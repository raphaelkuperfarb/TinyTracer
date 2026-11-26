import math

import cocotb
from cocotb.clock import Clock
from cocotb.triggers import FallingEdge, ReadOnly, RisingEdge, Timer


def control(opcode, fmt=0):
    return (opcode << 6) | (fmt << 5)


def signed16(value):
    return value - 65536 if value & 32768 else value


async def write_byte(dut, opcode, fmt, selector, value):
    await FallingEdge(dut.clk)
    dut.ui_in.value = control(opcode, fmt) | 16 | (selector << 2)
    dut.uio_in.value = value
    await RisingEdge(dut.clk)
    await FallingEdge(dut.clk)
    dut.ui_in.value = control(opcode, fmt)


async def run_operation(
    dut, opcode, op1, op2, expected, tolerance, fractional_bits, fmt=0
):
    await write_byte(dut, opcode, fmt, 0, op1 & 255)
    await write_byte(dut, opcode, fmt, 1, (op1 >> 8) & 255)
    await write_byte(dut, opcode, fmt, 2, op2 & 255)
    await write_byte(dut, opcode, fmt, 3, (op2 >> 8) & 255)

    await FallingEdge(dut.clk)
    dut.ui_in.value = control(opcode, fmt) | 2
    await RisingEdge(dut.clk)
    await FallingEdge(dut.clk)
    dut.ui_in.value = control(opcode, fmt)

    for _ in range(64):
        await RisingEdge(dut.clk)
        await ReadOnly()
        if int(dut.uio_oe.value) == 0xFF:
            result = (int(dut.uio_out.value) << 8) | int(dut.uo_out.value)
            signed_result = signed16(result)
            scale = 1 << fractional_bits
            format_name = "POS Q9.7" if fmt == 0 else "DIR Q2.14"
            dut._log.info(
                f"opcode={opcode} format={format_name} "
                f"A={signed16(op1) / scale:.6f} "
                f"B={signed16(op2) / scale:.6f} "
                f"result={signed_result / scale:.6f} "
                f"expected={expected / scale:.6f}"
            )
            passed = abs(signed_result - expected) <= tolerance
            await FallingEdge(dut.clk)
            dut.ui_in.value = control(opcode, fmt) | 1
            await RisingEdge(dut.clk)
            await FallingEdge(dut.clk)
            dut.ui_in.value = control(opcode, fmt)
            assert passed, (
                f"opcode {opcode}: got {signed_result / scale:.6f}, "
                f"expected {expected / scale:.6f} +/- {tolerance} LSB"
            )
            return result

    raise AssertionError(f"opcode {opcode:02b} did not produce a result")


@cocotb.test()
async def cordic_operations(dut):
    cocotb.start_soon(Clock(dut.clk, 10, units="ns").start())

    dut.rst_n.value = 0
    dut.ena.value = 1
    dut.ui_in.value = 0
    dut.uio_in.value = 0
    await Timer(30, units="ns")
    dut.rst_n.value = 1

    # Opcode map: 00 DIV, 01 SQRT, 10 COS, 11 MAG. Inputs are raw fixed-point values.
    q14 = 1 << 14
    q7 = 1 << 7
    cases = []

    # DIV (Q2.14): result = op1 / op2, saturating to the 16-bit range.
    for numerator, denominator in [
        (0x0000, 0x4000),  # 0 / 1: zero numerator
        (0x4000, 0x4000),  # 1 / 1
        (0x1000, 0x3000),  # 0.25 / 0.75 = 1/3: repeating quotient, every bit used
        (0x6000, 0x4000),  # 1.5 / 1: numerator > denominator
        (0x7000, 0x4000),  # 1.75 / 1: numerator's top bit at 14 (l == 14 path)
        (0x7FFF, 0x4000),  # 1.99994 / 1: largest quotient below 2
        (0x3FFF, 0x2000),  # 1.99988: just under the positive limit
        (0x2000, 0x1000),  # 0.5 / 0.25 = 2.0: saturates to 0x7FFF
        (0x7FFF, 0x0001),  # largest / smallest: maximum normalization, saturates
        (0x0003, 0x0004),  # tiny operands: normalization shifts both far
        (0x0001, 0x7FFF),  # tiny quotient: rounds to 0
        (0xE000, 0x1000),  # -0.5 / 0.25 = -2.0: exactly the negative limit
        (0x8000, 0x0001),  # most negative / smallest: negative saturation
        (0x8000, 0xC000),  # -2 / -1 = 2.0: most negative numerator, saturates
        (0x8000, 0x7FFF),  # -2 / 1.99994: most negative numerator, in range
        (0xC000, 0x6000),  # -1 / 1.5: negative numerator
        (0x3000, 0xA000),  # 0.75 / -1.5: negative denominator
        (0x9000, 0xB000),  # -1.75 / -1.25: both negative
        (0x6000, 0x8000),  # 1.5 / -2: denominator -2.0 can't be negated (known weak spot)
    ]:
        quotient = signed16(numerator) / signed16(denominator)
        # Division results clamp to the signed 16-bit range.
        expected = min(0x7FFF, max(-0x8000, round(quotient * q14)))
        cases.append((0b00, numerator, denominator, expected, 2, 14, 1))

    # SQRT POS (Q9.7, fmt=0). Normalization moves the leading one to bit 6 or 7
    # (w in [0.5, 2)): inputs below shift left, inputs of 2.0 and up shift right.
    for value in [
        0x0000,  # 0: can't be normalized
        0x0001,  # smallest input: largest left shift (odd bit)
        0x0002,  # smallest even-bit input
        0x003F,  # just below 0.5: left shift
        0x0040,  # 0.5: bottom of the window, no shift
        0x0080,  # 1.0: odd/even boundary inside the window
        0x00FF,  # just below 2.0: top of the window, no shift
        0x0100,  # 2.0: first input that shifts right
        0x0155,  # irregular pattern, right shift by 2
        0x1000,  # 32.0: right shift
        0x4000,  # 128.0: top bit, largest right shift
        0x7FFF,  # largest input
    ]:
        root = math.sqrt(signed16(value) / q7)
        cases.append((0b01, value, 0x0000, round(root * q7), 8, 7, 0))

    # SQRT DIR (Q2.14, fmt=1). Normalization moves the leading one to bit 12 or 13
    # (w in [0.25, 1)): inputs below shift left, inputs of 1.0 and up shift right.
    for value in [
        0x0000,  # 0: can't be normalized
        0x0001,  # smallest input: largest left shift (odd bit)
        0x0002,  # smallest even-bit input
        0x0FFF,  # just below 0.25: left shift by 2
        0x1000,  # 0.25: bottom of the window, no shift
        0x1C00,  # 0.4375: overflowed under the old [0.5, 2) window
        0x2000,  # 0.5: odd/even boundary inside the window
        0x3FFF,  # just below 1.0: top of the window, no shift
        0x4000,  # 1.0: first input that shifts right (loses its low bits)
        0x7000,  # 1.75: overflowed under the old [0.5, 2) window
        0x7FFF,  # largest input
    ]:
        root = math.sqrt(signed16(value) / q14)
        cases.append((0b01, value, 0x0000, round(root * q14), 12, 14, 1))

    # COS (Q2.14, angle in radians). Angles beyond +-1.7433 (0x6F92 / 0x906E)
    # are folded by +-pi and the result negated.
    for angle in [
        0x0000,  # 0: cos = 1, largest output
        0x0001,  # smallest positive angle
        0x2000,  # +0.5
        0xE000,  # -0.5: negative angle
        0x6488,  # +pi/2: cos = 0
        0x9B78,  # -pi/2: cos = 0
        0x6F92,  # +1.7433: largest angle not folded
        0x6F93,  # just above: first folded angle
        0x906E,  # -1.7433: most negative angle not folded
        0x906D,  # just below: first folded negative angle
        0x7FFF,  # +1.99994: largest angle
        0x8000,  # -2.0: most negative angle
    ]:
        angle_real = signed16(angle) / q14
        cosine = math.cos(angle_real)
        cases.append((0b10, 0x4000, angle, round(cosine * q14), 5, 14, 1))

    # MAG POS (Q9.7). The CORDIC gain (1.647) overflows x when the magnitude
    # is above about 0x4DB4 raw (155.4 in POS).
    for x_value, y_value in [
        (0x0000, 0x0000),  # zero vector
        (0x0080, 0x0000),  # (1, 0): on the x axis
        (0x0000, 0x0080),  # (0, 1): on the y axis
        (0x0180, 0x0200),  # (3, 4) = 5
        (0xFE80, 0xFE00),  # (-3, -4): both components negative
        (0x3000, 0x3000),  # (96, 96) = 135.8: large, still in range
        (0x4E00, 0x0000),  # 156: just above the overflow limit (known weak spot)
    ]:
        magnitude = math.hypot(signed16(x_value) / q7, signed16(y_value) / q7)
        cases.append((0b11, x_value, y_value, round(magnitude * q7), 8, 7, 0))

    # MAG DIR (Q2.14). Same raw limit: about 1.214.
    for x_value, y_value in [
        (0x0001, 0x0001),  # smallest nonzero vector
        (0x4000, 0x0000),  # (1, 0)
        (0x2666, 0x3333),  # about (0.6, 0.8) = 1
        (0xC000, 0x2000),  # (-1, 0.5): negative x
        (0x4D00, 0x0000),  # 1.203: just below the overflow limit
        (0x4E00, 0x0000),  # 1.219: just above the overflow limit (known weak spot)
    ]:
        magnitude = math.hypot(signed16(x_value) / q14, signed16(y_value) / q14)
        cases.append((0b11, x_value, y_value, round(magnitude * q14), 8, 14, 1))
    failures = []
    for opcode, op1, op2, expected, tolerance, fractional_bits, fmt in cases:
        try:
            await run_operation(
                dut, opcode, op1, op2, expected, tolerance, fractional_bits, fmt
            )
        except AssertionError as error:
            failures.append(str(error))
            dut._log.error(str(error))

    assert not failures, "CORDIC result mismatches:\n" + "\n".join(failures)
