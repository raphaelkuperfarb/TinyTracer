SIM ?= verilator
TOPLEVEL_LANG = verilog

SRC_DIR = $(abspath ../../src)
VERILOG_SOURCES = \
	$(SRC_DIR)/tinytracer_pkg.sv \
	$(SRC_DIR)/tinytracer_if.sv \
	$(SRC_DIR)/exu/functional_units/cordic.sv \
	$(SRC_DIR)/tt_um_cordic.sv

TOPLEVEL = tt_um_cordic
MODULE = test_cordic
COMPILE_ARGS += -I$(SRC_DIR)
EXTRA_ARGS += --timing --trace -Wno-fatal

include $(shell cocotb-config --makefiles)/Makefile.sim
