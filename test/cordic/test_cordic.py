import math
import random

import cocotb
from cocotb.clock import Clock
from cocotb.triggers import FallingEdge, ReadOnly, RisingEdge, Timer

from reference_models.cordic_ref import (
    CORDIC_DIV,
    CORDIC_SQRT,
    CORDIC_COS,
    CORDIC_MAG,
    COS_MAX_ANGLE,
    to_signed,
    to_fixed,
    to_float,
    expected,
)


def control(opcode, fmt=0):
    return (opcode << 6) | (fmt << 5)


OP_NAMES = {0b00: "DIV", 0b01: "SQRT", 0b10: "COS", 0b11: "MAG"}


def op_label(opcode, fmt):
    """The tag that prefixes each message (e.g. SQRT/DIR)"""
    return f"{OP_NAMES.get(opcode, f'OP{opcode:02b}')}/{'DIR' if fmt else 'POS'}"


LSB_TOLERANCE = 1


def bits_of_precision(error_lsb, fractional_bits):
    if error_lsb <= 0:
        return fractional_bits
    lost = math.ceil(math.log2(error_lsb))
    return max(0, min(fractional_bits, fractional_bits - lost))


async def write_byte(dut, opcode, fmt, selector, value):
    await FallingEdge(dut.clk)
    dut.ui_in.value = control(opcode, fmt) | 16 | (selector << 2)
    dut.uio_in.value = value
    await RisingEdge(dut.clk)
    await FallingEdge(dut.clk)
    dut.ui_in.value = control(opcode, fmt)


async def run_operation(dut, opcode, op1, op2, expected, fractional_bits=14, fmt=0):
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
            signed_result = to_signed(result)
            scale = 1 << fractional_bits
            label = op_label(opcode, fmt)

            error_lsb = abs(signed_result - expected)
            good_bits = bits_of_precision(error_lsb, fractional_bits)
            passed = error_lsb <= LSB_TOLERANCE

            dut._log.info(
                f"[{label}] A={to_float(op1, fractional_bits):.6f}, "
                f"B={to_float(op2, fractional_bits):.6f}, "
                f"result={to_float(result, fractional_bits):.6f}, "
                f"expected={expected / scale:.6f}, "
                f"err={error_lsb} LSB, "
                f"precision={good_bits}/{fractional_bits} frac bits"
            )
            await FallingEdge(dut.clk)
            dut.ui_in.value = control(opcode, fmt) | 1
            await RisingEdge(dut.clk)
            await FallingEdge(dut.clk)
            dut.ui_in.value = control(opcode, fmt)
            assert passed, (
                f"[{label}] got {to_float(result, fractional_bits):.6f}, "
                f"expected {expected / scale:.6f}: err {error_lsb} LSB, "
                f"({good_bits}/{fractional_bits} frac bits)"
            )
            return result

    raise AssertionError(f"[{op_label(opcode, fmt)}] did not produce a result")



@cocotb.test()
async def cordic_operations(dut):
    cocotb.start_soon(Clock(dut.clk, 10, units="ns").start())

    dut.rst_n.value = 0
    dut.ena.value = 1
    dut.ui_in.value = 0
    dut.uio_in.value = 0
    await Timer(30, units="ns")
    dut.rst_n.value = 1

    cases = []

    for numerator, denominator in [
        (0x4000, 0x4000), (0x3000, 0x4000),
        (0x2000, 0x4000), (0x5000, 0x4000),
        (0x6000, 0x4000), (0x3000, 0x2000),
        (0x2000, 0x1800), (0x5000, 0x3000),
        (0x2800, 0x5000), (0x1000, 0x1000),
        (0x2000, 0x1000), (0x3000, 0x1000),
        (0x5000, 0x1000), (0x0800, 0x1000),
        (0x1800, 0x1000), (0x5000, 0xF000),
        (0xB000, 0x1000), (0xB000, 0xF000),
        (0xE000, 0x1000), (0xE000, 0x2000),
        (0x2000, 0xE000), (0xE000, 0xE000),
        (0xE000, 0x4000), (0x2000, 0xC000),
        (0xE000, 0xC000),
    ]:
        cases.append(
            (0b00, numerator, denominator,
             expected(CORDIC_DIV, numerator, denominator, 1), 14, 1)
        )

    for value in [
        0x0008, 0x001F, 0x0020, 0x0021,
        0x003F, 0x0040, 0x0041, 0x007F,
        0x0080, 0x0081, 0x0120, 0x00FF,
        0x0100, 0x0101, 0x01FF, 0x0200,
        0x0201, 0x03FF, 0x0400, 0x0401,
        0x0800, 0x0FFF, 0x1000, 0x1001,
        0x00AB, 0x0155, 0x02AB, 0x0555,
        0x1FFF, 0x2000, 0x2001, 0x2AAB,
        0x3FFF, 0x4000, 0x4001, 0x5555,
        0x7FFD, 0x7FFE, 0x7FFF,
    ]:
        cases.append((0b01, value, 0x0000, expected(CORDIC_SQRT, value, 0x0000, 0), 7, 0))

    for value in [0x0FFF, 0x1000, 0x1FFF, 0x2000, 0x4000, 0x5000, 0x6000]:
        cases.append((0b01, value, 0x0000, expected(CORDIC_SQRT, value, 0x0000, 1), 14, 1))

    for angle in [
        0x0000, 0x2000, 0xE000, 0x4000,
        0xC000, 0x6000, 0xA000, 0x7333,
        0x8CCD,
    ]:
        cases.append((0b10, 0x4000, angle, expected(CORDIC_COS, 0x4000, angle, 1), 14, 1))

    # POS magnitude vectors (Q9.7).
    for x_value, y_value in [
        (0x0080, 0x0000), (0x0040, 0x0040),
        (0x004D, 0x0066), (0x0180, 0x0200),
    ]:
        cases.append((0b11, x_value, y_value, expected(CORDIC_MAG, x_value, y_value, 0), 7, 0))

    # DIR magnitude vectors (Q2.14).
    for x_value, y_value in [
        (0x4000, 0x0000), (0x2000, 0x2000),
        (0x2666, 0x3333), (0x3000, 0x3000),
    ]:
        cases.append((0b11, x_value, y_value, expected(CORDIC_MAG, x_value, y_value, 1), 14, 1))

    failures = await _run_cases(dut, cases)
    assert not failures, "CORDIC result mismatches:\n" + "\n".join(failures)


def _normalized_cases():
    return [
        (0b00, 0x2000, 0x4000, expected(CORDIC_DIV, 0x2000, 0x4000, 1), 14, 1),  # 0.5/1
        (0b01, 0x0080, 0x0000, expected(CORDIC_SQRT, 0x0080, 0x0000, 0), 7, 0),  # sqrt(1.0) POS
        (0b01, 0x4000, 0x0000, expected(CORDIC_SQRT, 0x4000, 0x0000, 1), 14, 1),  # sqrt(1.0) DIR
        (0b10, 0x4000, 0x2000, expected(CORDIC_COS, 0x4000, 0x2000, 1), 14, 1),  # cos(0.5 rad)
        (0b11, 0x004D, 0x0066, expected(CORDIC_MAG, 0x004D, 0x0066, 0), 7, 0),  # ~(0.6,0.8)
    ]


def _unnormalized_cases():
    return [
        (0b00, 0x6000, 0x2000, expected(CORDIC_DIV, 0x6000, 0x2000, 1), 14, 1),  # 1.5/0.5
        (0b01, 0x0800, 0x0000, expected(CORDIC_SQRT, 0x0800, 0x0000, 0), 7, 0),  # sqrt(16.0) POS
        (0b01, 0x1000, 0x0000, expected(CORDIC_SQRT, 0x1000, 0x0000, 1), 14, 1),  # sqrt(0.25) DIR, <0.5
        (0b10, 0x6000, 0x6000, expected(CORDIC_COS, 0x6000, 0x6000, 1), 14, 1),  # cos(1.5 rad) > pi/2
        (0b11, 0xFF80, 0xFF80, expected(CORDIC_MAG, 0xFF80, 0xFF80, 0), 7, 0),  # (-1,-1)
    ]


async def _run_cases(dut, cases):
    failures = []
    for opcode, op1, op2, exp, frac_bits, fmt in cases:
        if exp is None:
            dut._log.info(
                f"[{op_label(opcode, fmt)}] skipped: out of model's legal range"
            )
            continue
        try:
            await run_operation(dut, opcode, op1, op2, exp, frac_bits, fmt)
        except AssertionError as error:
            failures.append(str(error))
            dut._log.error(str(error))
    return failures


@cocotb.test()
async def test_norm_inputs(dut):
    """Call each operation once with inputs that do not need normalization"""
    await _reset(dut)
    failures = await _run_cases(dut, _normalized_cases())
    assert not failures, "normalized-input mismatches:\n" + "\n".join(failures)


@cocotb.test()
async def test_unorm_inputs(dut):
    """Same as test_norm_inputs but with inputs that need normalization"""
    await _reset(dut)
    failures = await _run_cases(dut, _unnormalized_cases())
    assert not failures, "unnormalized-input mismatches:\n" + "\n".join(failures)


S_IDLE = 0b000
S_INIT = 0b001
S_NORMALIZE = 0b011
S_LOOP = 0b010
S_REVERT = 0b110
S_POSTSCALE = 0b100

STATE_NAMES = {
    S_IDLE: "IDLE", S_INIT: "INIT", S_NORMALIZE: "NORMALIZE",
    S_LOOP: "LOOP", S_REVERT: "REVERT", S_POSTSCALE: "POSTSCALE",
}

LEGAL_NEXT = {
    S_IDLE: {S_IDLE, S_INIT},
    S_INIT: {S_NORMALIZE},
    S_NORMALIZE: {S_LOOP},
    S_LOOP: {S_LOOP, S_REVERT},
    S_REVERT: {S_POSTSCALE},
    S_POSTSCALE: {S_IDLE},
}


@cocotb.test()
async def test_state_transitions(dut):
    """Verify the FSM only makes legal state transitions"""
    await _reset(dut)
    core = dut.u_cordic

    await write_byte(dut, 0b00, 1, 0, 0x6000 & 0xFF)
    await write_byte(dut, 0b00, 1, 1, (0x6000 >> 8) & 0xFF)
    await write_byte(dut, 0b00, 1, 2, 0x2000 & 0xFF)
    await write_byte(dut, 0b00, 1, 3, (0x2000 >> 8) & 0xFF)

    await FallingEdge(dut.clk)
    dut.ui_in.value = control(0b00, 1) | 2
    await RisingEdge(dut.clk)
    await FallingEdge(dut.clk)
    dut.ui_in.value = control(0b00, 1)

    prev = int(core.current_state.value)
    sequence = [prev]
    left_idle = False
    for _ in range(64):
        await RisingEdge(dut.clk)
        await ReadOnly()
        cur = int(core.current_state.value)
        if cur != prev:
            assert cur in LEGAL_NEXT.get(prev, set()), (
                f"illegal transition "
                f"{STATE_NAMES.get(prev, prev)} -> {STATE_NAMES.get(cur, cur)}"
            )
            sequence.append(cur)
            if prev != S_IDLE and cur == S_IDLE:
                left_idle = True
                prev = cur
                break
            prev = cur

    dut._log.info(
        "state sequence: " + " -> ".join(STATE_NAMES.get(s, str(s)) for s in sequence)
    )
    assert left_idle, "FSM never completed an operation back to IDLE"


SWEEP_N = 40


def _rand_q(rng, frac_bits, lo, hi):
    """Random raw fixed-point value (model's encoder) whose real value is in [lo, hi)."""
    return to_fixed(rng.uniform(lo, hi), frac_bits)


async def _reset(dut):
    cocotb.start_soon(Clock(dut.clk, 10, units="ns").start())
    dut.rst_n.value = 0
    dut.ena.value = 1
    dut.ui_in.value = 0
    dut.uio_in.value = 0
    await Timer(30, units="ns")
    dut.rst_n.value = 1


async def _sweep_op(dut, make_case, rng, failures):
    """Run SWEEP_N random cases for one opcode, collecting mismatches"""
    for _ in range(SWEEP_N):
        opcode, op1, op2, exp, frac_bits, fmt = make_case(rng)
        if exp is None:
            continue
        try:
            await run_operation(dut, opcode, op1, op2, exp, frac_bits, fmt)
        except AssertionError as error:
            failures.append(str(error))
            dut._log.error(str(error))


@cocotb.test()
async def cordic_sweep(dut):
    """Constrained-random sweep across all four opcodes and both formats"""
    seed = 0xC0D1C
    rng = random.Random(seed)
    dut._log.info(f"cordic_sweep seed=0x{seed:X} ({SWEEP_N} cases/op)")

    await _reset(dut)
    failures = []

    # DIV (Q9.7 operands -> Q2.14 result).
    def div_case(r):
        num = _rand_q(r, 7, -4.0, 4.0)
        den = 0
        while to_signed(den) == 0:
            den = _rand_q(r, 7, -4.0, 4.0)
        return (0b00, num, den, expected(CORDIC_DIV, num, den, 1), 14, 1)

    # SQRT POS (Q9.7) and DIR (Q2.14), a >= 0.
    def sqrt_pos_case(r):
        val = _rand_q(r, 7, 0.0, 255.0)
        return (0b01, val, 0x0000, expected(CORDIC_SQRT, val, 0x0000, 0), 7, 0)

    def sqrt_dir_case(r):
        val = _rand_q(r, 14, 0.0, 1.999)
        return (0b01, val, 0x0000, expected(CORDIC_SQRT, val, 0x0000, 1), 14, 1)

    # COS (DIR), a = 1.0, legal angle within +/-1.743 rad.
    def cos_case(r):
        angle = to_fixed(r.uniform(-COS_MAX_ANGLE, COS_MAX_ANGLE), 14)
        return (0b10, 0x4000, angle, expected(CORDIC_COS, 0x4000, angle, 1), 14, 1)

    # MAG POS (Q9.7) and DIR (Q2.14).
    def mag_pos_case(r):
        x = _rand_q(r, 7, -8.0, 8.0)
        y = _rand_q(r, 7, -8.0, 8.0)
        return (0b11, x, y, expected(CORDIC_MAG, x, y, 0), 7, 0)

    def mag_dir_case(r):
        x = _rand_q(r, 14, -1.0, 1.0)
        y = _rand_q(r, 14, -1.0, 1.0)
        return (0b11, x, y, expected(CORDIC_MAG, x, y, 1), 14, 1)

    await _sweep_op(dut, div_case, rng, failures)
    await _sweep_op(dut, sqrt_pos_case, rng, failures)
    await _sweep_op(dut, sqrt_dir_case, rng, failures)
    await _sweep_op(dut, cos_case, rng, failures)
    await _sweep_op(dut, mag_pos_case, rng, failures)
    await _sweep_op(dut, mag_dir_case, rng, failures)

    assert not failures, (
        f"CORDIC sweep mismatches (seed=0x{seed:X}): {len(failures)}\n"
        + "\n".join(failures)
    )
