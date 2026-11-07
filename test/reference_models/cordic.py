import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge, Timer

CLK_PERIOD_NS = 10
BIT_WIDTH = 16
FRAC_BITS = 14


def to_fixed(value):
    """Convert a float to signed Q2.14 (16-bit)."""
    scaled = round(value * (1 << FRAC_BITS))
    return scaled & ((1 << BIT_WIDTH) - 1)


async def reset_dut(dut):
    """Reset the DUT to a known state."""
    dut.rst_n.value = 0
    dut.start.value = 0
    dut.A_in.value = 0
    dut.B_in.value = 0
    dut.opcode.value = 0

    for _ in range(3):
        await RisingEdge(dut.clk)

    await Timer(1, unit="ns")
    dut.rst_n.value = 1
    await RisingEdge(dut.clk)


async def init_dut(dut):
    """Start the clock and initialize the DUT."""
    cocotb.start_soon(
        Clock(dut.clk, CLK_PERIOD_NS, unit="ns").start()
    )
    await reset_dut(dut)


async def send_inputs(dut, a, b, opcode):
    """Apply Q2.14 operands and pulse start for one cycle."""
    dut.A_in.value = to_fixed(a)
    dut.B_in.value = to_fixed(b)
    dut.opcode.value = opcode
    dut.start.value = 1

    await RisingEdge(dut.clk)
    await Timer(1, unit="ns")
    dut.start.value = 0


@cocotb.test()
async def test_initialization(dut):
    await init_dut(dut)

    assert int(dut.busy.value) == 0, \
        "DUT should not be busy after reset"

@cocotb.test()
async def test_norm_inputs(dut):
    """
    For this test we're going to call each operation once
    For each call, we generate inputs that do not need normalization.
    We precompute the answer in python, and compare that to the output of the cordic module.
    Allow for once LSB of tolerance.
    """

@cocotb.test()
async def test_unorm_inputs(dut):
    """
    This test is the same as the above one except we use inputs that need normalization.
    """

@cocotb.test()
async def test_random_inputs(dut):
    """
    For this test we're going to call each operation 5 times.
    Each time, we're gonna generate random inputs and compute the result of that operation.
    Then, we send those inputs to the cordic module which will compute the result.
    Once its done, we compare the results. Allow for one LSB of tolerance.
    """

@cocotb.test()
async def test_state_transitions(dut):
    """
    For this test we want to verify proper state transitioning.
    Pick an operation (like division), and input values that need normalization.
    As the module runs, catch state transitions and log them
    If a single out of order transition occurs, then the test fails.
    We don't care about the answer here, so don't put any assertions on it
    """
