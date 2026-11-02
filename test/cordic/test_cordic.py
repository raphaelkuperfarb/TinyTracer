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
            passed = abs(result - expected) <= tolerance
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

    for numerator, denominator in [
        (0x4000, 0x4000),  # 1 / 1
        (0x3000, 0x4000),  # 0.75 / 1
        (0x2000, 0x4000),  # 0.5 / 1
        (0x5000, 0x4000),  # 1.25 / 1: numerator > denominator
        (0x6000, 0x4000),  # 1.5 / 1: numerator > denominator
        (0x2800, 0x5000),  # 0.625 / 1.25
    ]:
        quotient = signed16(numerator) / signed16(denominator)
        cases.append((0b00, numerator, denominator, round(quotient * q14), 2, 14, 1))

    # POS square roots (Q9.7, fmt=0). Adjacent raw inputs around powers of
    # two help expose late-iteration rounding when the residual gets tiny.
    for value in [
        0x0008,
        0x001F, 0x0020, 0x0021,  # around 0.25
        0x003F, 0x0040, 0x0041,  # around 0.5
        0x007F, 0x0080, 0x0081,  # around 1.0
        0x0120,
        0x00FF, 0x0100, 0x0101,  # around 2.0
        0x01FF, 0x0200, 0x0201,  # around 4.0
        0x03FF, 0x0400, 0x0401,  # around 8.0
        0x0800,
        0x0FFF, 0x1000, 0x1001,  # around 32.0; exercises right normalization
        0x00AB, 0x0155, 0x02AB, 0x0555,  # irregular binary patterns
        0x1FFF, 0x2000, 0x2001,  # around 64.0
        0x2AAB,  # irregular pattern above 64.0
        0x3FFF, 0x4000, 0x4001,  # around 128.0
        0x5555,  # irregular pattern above 128.0
        0x7FFD, 0x7FFE, 0x7FFF,  # largest positive POS inputs
    ]:
        root = math.sqrt(signed16(value) / q7)
        cases.append((0b01, value, 0x0000, round(root * q7), 8, 7, 0))

    # DIR square roots (Q2.14, fmt=1).
    for value in [0x1000, 0x2000, 0x4000, 0x5000, 0x6000]:
        root = math.sqrt(signed16(value) / q14)
        cases.append((0b01, value, 0x0000, round(root * q14), 12, 14, 1))

    for angle in [
        0x0000,  # 0 radians
        0x2000,  # +0.5 radians
        0xE000,  # -0.5 radians
        0x4000,  # +1.0 radians
        0xC000,  # -1.0 radians
        0x6000,  # +1.5 radians
        0xA000,  # -1.5 radians
    ]:
        angle_real = signed16(angle) / q14
        cosine = math.cos(angle_real)
        cases.append((0b10, 0x4000, angle, round(cosine * q14), 5, 14, 1))

    # POS magnitude vectors (Q9.7).
    for x_value, y_value in [
        (0x0080, 0x0000),  # (1, 0)
        (0x0040, 0x0040),  # (0.5, 0.5)
        (0x004D, 0x0066),  # approximately (0.6, 0.8)
        (0x0180, 0x0200),  # (3, 4)
    ]:
        magnitude = math.hypot(signed16(x_value) / q7, signed16(y_value) / q7)
        cases.append((0b11, x_value, y_value, round(magnitude * q7), 8, 7, 0))

    # DIR magnitude vectors (Q2.14).
    for x_value, y_value in [
        (0x4000, 0x0000),  # (1, 0)
        (0x2000, 0x2000),  # (0.5, 0.5)
        (0x2666, 0x3333),  # approximately (0.6, 0.8)
        (0x3000, 0x3000),  # (0.75, 0.75)
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
