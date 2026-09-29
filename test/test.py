# SPDX-FileCopyrightText: © 2024 Tiny Tapeout
# SPDX-License-Identifier: Apache-2.0

import cocotb
from cocotb.clock import Clock
from cocotb.triggers import ClockCycles
from cocotb.triggers import RisingEdge
from cocotb.triggers import ReadOnly

@cocotb.test()
async def test_clkdiv_frequency(dut):
    dut._log.info("Start")

    cocotb.start_soon(Clock(dut.clk, 10, unit="ns").start())
    

    dut.ena.value = 1

    cases = [(4, 1), (4, 3), (5, 5), (7, 5), (10, 1), (126,1), (64, 63), (67, 16)]

    for b, c in cases:
        dut.ui_in.value = b
        dut.uio_in.value = c

        # Reset
        dut.rst_n.value = 0
        for _ in range(5):
            await RisingEdge(dut.clk)

        dut.rst_n.value = 1

        cycles = 1800
        rising_edges = 0
        previous_q = 0

        for _ in range(cycles):
            await RisingEdge(dut.clk)

            q = int(dut.uo_out.value)

            if previous_q == 0 and q == 1:
                rising_edges += 1

            previous_q = q

        expected = cycles * c / (2 * (b + c))

        dut._log.info(
            f"b={b}, c={c}: observed {rising_edges} rising edges; expected about {expected:.1f}"
        )

        assert abs(rising_edges - expected) <= 2

@cocotb.test()
async def test_clkdiv_reset(dut):
    dut._log.info("Start")

    cocotb.start_soon(Clock(dut.clk, 10, unit="ns").start())

    b = 4
    c = 1

    dut.ena.value = 1
    dut.ui_in.value = b
    dut.uio_in.value = c

    
    dut.rst_n.value = 0    
    await RisingEdge(dut.clk)     
    for _ in range(5):
        await RisingEdge(dut.clk)
        assert int(dut.uo_out.value) == 0, "q not 0 during initial reset"

    dut.rst_n.value = 1

    
    await ClockCycles(dut.clk, 50)

    
    dut.rst_n.value = 0 
    await RisingEdge(dut.clk)      
    for _ in range(5):
        await RisingEdge(dut.clk)
        assert int(dut.uo_out.value) == 0, "q not 0 during reset"

    dut.rst_n.value = 1
    


    
