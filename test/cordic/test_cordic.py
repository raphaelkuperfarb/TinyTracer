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
            dut._log.info(
                f"opcode={opcode} A={signed16(op1) / scale:.6f} "
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
    ]:
        quotient = signed16(numerator) / signed16(denominator)
        cases.append((0b00, numerator, denominator, round(quotient * q14), 2, 14, 1))

    for value in [0x0200, 0x0080, 0x0020]:  # sqrt(4), sqrt(1), sqrt(0.25), POS
        root = math.sqrt(signed16(value) / q7)
        cases.append((0b01, value, 0x0000, round(root * q7), 8, 7, 0))

    for angle in [0x0000, 0x2000, 0xE000]:  # 0, +0.5, -0.5 radians; amplitude 1
        angle_real = signed16(angle) / q14
        cosine = math.cos(angle_real)
        cases.append((0b10, 0x4000, angle, round(cosine * q14), 5, 14, 1))

    for x_value, y_value in [
        (0x4000, 0x0000),  # (1, 0)
        (0x2000, 0x2000),  # (0.5, 0.5)
        (0x2666, 0x3333),  # approximately (0.6, 0.8)
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
