// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vtop__pch.h"

extern const VlVarTableEntry Vtop___024root__VpiVarTable0[];
extern const VlVarTableEntry Vtop___024root__VpiVarTable1[];
extern const VlVarTableEntry Vtop_fu_if__VpiVarTable2[];
extern const VlVarTableEntry Vtop___024root__VpiVarTable3[];
extern const VlVarTableEntry Vtop___024root__VpiVarTable4[];
extern const VlVarTableEntry Vtop___024root__VpiVarTable5[];
extern const VlVarTableEntry Vtop___024root__VpiVarTable6[];
extern const VlScopeTableEntry Vtop__Syms__VpiScopeTable[];


// VPI VARIABLE/SCOPE TABLES
#if defined(__GNUC__)
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Winvalid-offsetof"
#endif
extern const VlVarTableEntry Vtop___024root__VpiVarTable0[] = {
    {"clk", offsetof(Vtop___024root, clk), VLVT_UINT8, (VLVD_IN|VLVF_PUB_RW|VLVF_NET), 0, 0, {0, 0, 0, 0, 0, 0}},
    {"ena", offsetof(Vtop___024root, ena), VLVT_UINT8, (VLVD_IN|VLVF_PUB_RW|VLVF_NET), 0, 0, {0, 0, 0, 0, 0, 0}},
    {"rst_n", offsetof(Vtop___024root, rst_n), VLVT_UINT8, (VLVD_IN|VLVF_PUB_RW|VLVF_NET), 0, 0, {0, 0, 0, 0, 0, 0}},
    {"ui_in", offsetof(Vtop___024root, ui_in), VLVT_UINT8, (VLVD_IN|VLVF_PUB_RW|VLVF_NET), 0, 1, {7, 0, 0, 0, 0, 0}},
    {"uio_in", offsetof(Vtop___024root, uio_in), VLVT_UINT8, (VLVD_IN|VLVF_PUB_RW|VLVF_NET), 0, 1, {7, 0, 0, 0, 0, 0}},
    {"uio_oe", offsetof(Vtop___024root, uio_oe), VLVT_UINT8, (VLVD_OUT|VLVF_PUB_RW|VLVF_CONTINUOUSLY|VLVF_NET), 0, 1, {7, 0, 0, 0, 0, 0}},
    {"uio_out", offsetof(Vtop___024root, uio_out), VLVT_UINT8, (VLVD_OUT|VLVF_PUB_RW|VLVF_CONTINUOUSLY|VLVF_NET), 0, 1, {7, 0, 0, 0, 0, 0}},
    {"uo_out", offsetof(Vtop___024root, uo_out), VLVT_UINT8, (VLVD_OUT|VLVF_PUB_RW|VLVF_CONTINUOUSLY|VLVF_NET), 0, 1, {7, 0, 0, 0, 0, 0}},
};
extern const VlVarTableEntry Vtop___024root__VpiVarTable1[] = {
    {"_unused", offsetof(Vtop___024root, tt_um_cordic__DOT___unused), VLVT_UINT8, (VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY|VLVF_NET), 0, 0, {0, 0, 0, 0, 0, 0}},
    {"clk", offsetof(Vtop___024root, tt_um_cordic__DOT__clk), VLVT_UINT8, (VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY|VLVF_NET), 0, 0, {0, 0, 0, 0, 0, 0}},
    {"ena", offsetof(Vtop___024root, tt_um_cordic__DOT__ena), VLVT_UINT8, (VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY|VLVF_NET), 0, 0, {0, 0, 0, 0, 0, 0}},
    {"fmt_q", offsetof(Vtop___024root, tt_um_cordic__DOT__fmt_q), VLVT_UINT8, (VLVD_NODIR|VLVF_PUB_RW), 0, 0, {0, 0, 0, 0, 0, 0}},
    {"op1_q", offsetof(Vtop___024root, tt_um_cordic__DOT__op1_q), VLVT_UINT16, (VLVD_NODIR|VLVF_PUB_RW), 0, 1, {15, 0, 0, 0, 0, 0}},
    {"op2_q", offsetof(Vtop___024root, tt_um_cordic__DOT__op2_q), VLVT_UINT16, (VLVD_NODIR|VLVF_PUB_RW), 0, 1, {15, 0, 0, 0, 0, 0}},
    {"result_q", offsetof(Vtop___024root, tt_um_cordic__DOT__result_q), VLVT_UINT16, (VLVD_NODIR|VLVF_PUB_RW), 0, 1, {15, 0, 0, 0, 0, 0}},
    {"result_valid", offsetof(Vtop___024root, tt_um_cordic__DOT__result_valid), VLVT_UINT8, (VLVD_NODIR|VLVF_PUB_RW), 0, 0, {0, 0, 0, 0, 0, 0}},
    {"rst_n", offsetof(Vtop___024root, tt_um_cordic__DOT__rst_n), VLVT_UINT8, (VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY|VLVF_NET), 0, 0, {0, 0, 0, 0, 0, 0}},
    {"ui_in", offsetof(Vtop___024root, tt_um_cordic__DOT__ui_in), VLVT_UINT8, (VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY|VLVF_NET), 0, 1, {7, 0, 0, 0, 0, 0}},
    {"uio_in", offsetof(Vtop___024root, tt_um_cordic__DOT__uio_in), VLVT_UINT8, (VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY|VLVF_NET), 0, 1, {7, 0, 0, 0, 0, 0}},
    {"uio_oe", offsetof(Vtop___024root, tt_um_cordic__DOT__uio_oe), VLVT_UINT8, (VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY|VLVF_NET), 0, 1, {7, 0, 0, 0, 0, 0}},
    {"uio_out", offsetof(Vtop___024root, tt_um_cordic__DOT__uio_out), VLVT_UINT8, (VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY|VLVF_NET), 0, 1, {7, 0, 0, 0, 0, 0}},
    {"uo_out", offsetof(Vtop___024root, tt_um_cordic__DOT__uo_out), VLVT_UINT8, (VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY|VLVF_NET), 0, 1, {7, 0, 0, 0, 0, 0}},
};
extern const VlVarTableEntry Vtop_fu_if__VpiVarTable2[] = {
    {"req_fmt", offsetof(Vtop_fu_if, req_fmt), VLVT_UINT8, (VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY), 0, 0, {0, 0, 0, 0, 0, 0}},
    {"req_op1", offsetof(Vtop_fu_if, req_op1), VLVT_UINT16, (VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY), 0, 1, {15, 0, 0, 0, 0, 0}},
    {"req_op2", offsetof(Vtop_fu_if, req_op2), VLVT_UINT16, (VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY), 0, 1, {15, 0, 0, 0, 0, 0}},
    {"req_opcode", offsetof(Vtop_fu_if, req_opcode), VLVT_UINT8, (VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY), 0, 1, {2, 0, 0, 0, 0, 0}},
    {"req_ready", offsetof(Vtop_fu_if, req_ready), VLVT_UINT8, (VLVD_NODIR|VLVF_PUB_RW), 0, 0, {0, 0, 0, 0, 0, 0}},
    {"req_valid", offsetof(Vtop_fu_if, req_valid), VLVT_UINT8, (VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY), 0, 0, {0, 0, 0, 0, 0, 0}},
    {"resp_done", offsetof(Vtop_fu_if, resp_done), VLVT_UINT8, (VLVD_NODIR|VLVF_PUB_RW), 0, 0, {0, 0, 0, 0, 0, 0}},
    {"resp_result", offsetof(Vtop_fu_if, resp_result), VLVT_UINT16, (VLVD_NODIR|VLVF_PUB_RW), 0, 1, {15, 0, 0, 0, 0, 0}},
};
extern const VlVarTableEntry Vtop___024root__VpiVarTable3[] = {
    {"angleShift", offsetof(Vtop___024root, tt_um_cordic__DOT__u_cordic__DOT__angleShift), VLVT_UINT8, (VLVD_NODIR|VLVF_PUB_RW), 0, 0, {0, 0, 0, 0, 0, 0}},
    {"clk", offsetof(Vtop___024root, tt_um_cordic__DOT__u_cordic__DOT__clk), VLVT_UINT8, (VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY), 0, 0, {0, 0, 0, 0, 0, 0}},
    {"current_state", offsetof(Vtop___024root, tt_um_cordic__DOT__u_cordic__DOT__current_state), VLVT_UINT8, (VLVD_NODIR|VLVF_PUB_RW), 0, 1, {2, 0, 0, 0, 0, 0}},
    {"cycles_completed", offsetof(Vtop___024root, tt_um_cordic__DOT__u_cordic__DOT__cycles_completed), VLVT_UINT8, (VLVD_NODIR|VLVF_PUB_RW), 0, 1, {3, 0, 0, 0, 0, 0}},
    {"format", offsetof(Vtop___024root, tt_um_cordic__DOT__u_cordic__DOT__format), VLVT_UINT8, (VLVD_NODIR|VLVF_PUB_RW), 0, 0, {0, 0, 0, 0, 0, 0}},
    {"j", offsetof(Vtop___024root, tt_um_cordic__DOT__u_cordic__DOT__j), VLVT_UINT8, (VLVD_NODIR|VLVF_PUB_RW), 0, 1, {3, 0, 0, 0, 0, 0}},
    {"k", offsetof(Vtop___024root, tt_um_cordic__DOT__u_cordic__DOT__k), VLVT_UINT8, (VLVD_NODIR|VLVF_PUB_RW), 0, 1, {3, 0, 0, 0, 0, 0}},
    {"l", offsetof(Vtop___024root, tt_um_cordic__DOT__u_cordic__DOT__l), VLVT_UINT8, (VLVD_NODIR|VLVF_PUB_RW), 0, 1, {3, 0, 0, 0, 0, 0}},
    {"neg_next", offsetof(Vtop___024root, tt_um_cordic__DOT__u_cordic__DOT__neg_next), VLVT_UINT8, (VLVD_NODIR|VLVF_PUB_RW), 0, 0, {0, 0, 0, 0, 0, 0}},
    {"neg_q", offsetof(Vtop___024root, tt_um_cordic__DOT__u_cordic__DOT__neg_q), VLVT_UINT8, (VLVD_NODIR|VLVF_PUB_RW), 0, 0, {0, 0, 0, 0, 0, 0}},
    {"next_state", offsetof(Vtop___024root, tt_um_cordic__DOT__u_cordic__DOT__next_state), VLVT_UINT8, (VLVD_NODIR|VLVF_PUB_RW), 0, 1, {2, 0, 0, 0, 0, 0}},
    {"normalized", offsetof(Vtop___024root, tt_um_cordic__DOT__u_cordic__DOT__normalized), VLVT_UINT16, (VLVD_NODIR|VLVF_PUB_RW|VLVF_SIGNED), 0, 1, {15, 0, 0, 0, 0, 0}},
    {"opcode", offsetof(Vtop___024root, tt_um_cordic__DOT__u_cordic__DOT__opcode), VLVT_UINT8, (VLVD_NODIR|VLVF_PUB_RW), 0, 1, {1, 0, 0, 0, 0, 0}},
    {"postscale_product", offsetof(Vtop___024root, tt_um_cordic__DOT__u_cordic__DOT__postscale_product), VLVT_UINT32, (VLVD_NODIR|VLVF_PUB_RW|VLVF_SIGNED), 0, 1, {31, 0, 0, 0, 0, 0}},
    {"postscale_result", offsetof(Vtop___024root, tt_um_cordic__DOT__u_cordic__DOT__postscale_result), VLVT_UINT32, (VLVD_NODIR|VLVF_PUB_RW|VLVF_SIGNED), 0, 1, {31, 0, 0, 0, 0, 0}},
    {"repeated", offsetof(Vtop___024root, tt_um_cordic__DOT__u_cordic__DOT__repeated), VLVT_UINT8, (VLVD_NODIR|VLVF_PUB_RW), 0, 0, {0, 0, 0, 0, 0, 0}},
    {"rst_n", offsetof(Vtop___024root, tt_um_cordic__DOT__u_cordic__DOT__rst_n), VLVT_UINT8, (VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY), 0, 0, {0, 0, 0, 0, 0, 0}},
    {"shift_next", offsetof(Vtop___024root, tt_um_cordic__DOT__u_cordic__DOT__shift_next), VLVT_UINT8, (VLVD_NODIR|VLVF_PUB_RW), 0, 1, {3, 0, 0, 0, 0, 0}},
    {"shift_q", offsetof(Vtop___024root, tt_um_cordic__DOT__u_cordic__DOT__shift_q), VLVT_UINT8, (VLVD_NODIR|VLVF_PUB_RW), 0, 1, {3, 0, 0, 0, 0, 0}},
    {"shift_right_next", offsetof(Vtop___024root, tt_um_cordic__DOT__u_cordic__DOT__shift_right_next), VLVT_UINT8, (VLVD_NODIR|VLVF_PUB_RW), 0, 0, {0, 0, 0, 0, 0, 0}},
    {"shift_right_q", offsetof(Vtop___024root, tt_um_cordic__DOT__u_cordic__DOT__shift_right_q), VLVT_UINT8, (VLVD_NODIR|VLVF_PUB_RW), 0, 0, {0, 0, 0, 0, 0, 0}},
    {"start", offsetof(Vtop___024root, tt_um_cordic__DOT__u_cordic__DOT__start), VLVT_UINT8, (VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY|VLVF_NET), 0, 0, {0, 0, 0, 0, 0, 0}},
    {"tooBig", offsetof(Vtop___024root, tt_um_cordic__DOT__u_cordic__DOT__tooBig), VLVT_UINT8, (VLVD_NODIR|VLVF_PUB_RW), 0, 0, {0, 0, 0, 0, 0, 0}},
    {"x", offsetof(Vtop___024root, tt_um_cordic__DOT__u_cordic__DOT__x), VLVT_UINT16, (VLVD_NODIR|VLVF_PUB_RW|VLVF_SIGNED), 0, 1, {15, 0, 0, 0, 0, 0}},
    {"x_next", offsetof(Vtop___024root, tt_um_cordic__DOT__u_cordic__DOT__x_next), VLVT_UINT16, (VLVD_NODIR|VLVF_PUB_RW|VLVF_SIGNED), 0, 1, {15, 0, 0, 0, 0, 0}},
    {"xp", offsetof(Vtop___024root, tt_um_cordic__DOT__u_cordic__DOT__xp), VLVT_UINT16, (VLVD_NODIR|VLVF_PUB_RW|VLVF_SIGNED), 0, 1, {15, 0, 0, 0, 0, 0}},
    {"y", offsetof(Vtop___024root, tt_um_cordic__DOT__u_cordic__DOT__y), VLVT_UINT16, (VLVD_NODIR|VLVF_PUB_RW|VLVF_SIGNED), 0, 1, {15, 0, 0, 0, 0, 0}},
    {"y_next", offsetof(Vtop___024root, tt_um_cordic__DOT__u_cordic__DOT__y_next), VLVT_UINT16, (VLVD_NODIR|VLVF_PUB_RW|VLVF_SIGNED), 0, 1, {15, 0, 0, 0, 0, 0}},
    {"ym", offsetof(Vtop___024root, tt_um_cordic__DOT__u_cordic__DOT__ym), VLVT_UINT16, (VLVD_NODIR|VLVF_PUB_RW|VLVF_SIGNED), 0, 1, {15, 0, 0, 0, 0, 0}},
    {"z", offsetof(Vtop___024root, tt_um_cordic__DOT__u_cordic__DOT__z), VLVT_UINT16, (VLVD_NODIR|VLVF_PUB_RW|VLVF_SIGNED), 0, 1, {15, 0, 0, 0, 0, 0}},
    {"z_next", offsetof(Vtop___024root, tt_um_cordic__DOT__u_cordic__DOT__z_next), VLVT_UINT16, (VLVD_NODIR|VLVF_PUB_RW|VLVF_SIGNED), 0, 1, {15, 0, 0, 0, 0, 0}},
};
extern const VlVarTableEntry Vtop___024root__VpiVarTable4[] = {
    {"i", offsetof(Vtop___024root, tt_um_cordic__DOT__u_cordic__DOT__unnamedblk1__DOT__i), VLVT_UINT32, (VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY|VLVF_SIGNED), 0, 1, {31, 0, 0, 0, 0, 0}},
};
extern const VlVarTableEntry Vtop___024root__VpiVarTable5[] = {
    {"h", offsetof(Vtop___024root, tt_um_cordic__DOT__u_cordic__DOT__unnamedblk2__DOT__h), VLVT_UINT32, (VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY|VLVF_SIGNED), 0, 1, {31, 0, 0, 0, 0, 0}},
};
extern const VlVarTableEntry Vtop___024root__VpiVarTable6[] = {
    {"i", offsetof(Vtop___024root, tt_um_cordic__DOT__u_cordic__DOT__unnamedblk3__DOT__i), VLVT_UINT32, (VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY|VLVF_SIGNED), 0, 1, {31, 0, 0, 0, 0, 0}},
};
extern const VlScopeTableEntry Vtop__Syms__VpiScopeTable[] = {
    {offsetof(Vtop__Syms, __Vscopep_TOP), "TOP", "TOP", "<null>", 0, VerilatedScope::SCOPE_OTHER},
    {offsetof(Vtop__Syms, __Vscopep_tinytracer_pkg), "tinytracer_pkg", "tinytracer_pkg", "tinytracer_pkg", -9, VerilatedScope::SCOPE_PACKAGE},
    {offsetof(Vtop__Syms, __Vscopep_tt_um_cordic), "tt_um_cordic", "tt_um_cordic", "tt_um_cordic", -9, VerilatedScope::SCOPE_MODULE},
    {offsetof(Vtop__Syms, __Vscopep_tt_um_cordic__fu), "tt_um_cordic.fu", "fu", "fu_if", -9, VerilatedScope::SCOPE_MODULE},
    {offsetof(Vtop__Syms, __Vscopep_tt_um_cordic__u_cordic), "tt_um_cordic.u_cordic", "u_cordic", "cordic", -9, VerilatedScope::SCOPE_MODULE},
    {offsetof(Vtop__Syms, __Vscopep_tt_um_cordic__u_cordic__unnamedblk1), "tt_um_cordic.u_cordic.unnamedblk1", "unnamedblk1", "<null>", -9, VerilatedScope::SCOPE_OTHER},
    {offsetof(Vtop__Syms, __Vscopep_tt_um_cordic__u_cordic__unnamedblk2), "tt_um_cordic.u_cordic.unnamedblk2", "unnamedblk2", "<null>", -9, VerilatedScope::SCOPE_OTHER},
    {offsetof(Vtop__Syms, __Vscopep_tt_um_cordic__u_cordic__unnamedblk3), "tt_um_cordic.u_cordic.unnamedblk3", "unnamedblk3", "<null>", -9, VerilatedScope::SCOPE_OTHER},
};
#if defined(__GNUC__)
# pragma GCC diagnostic pop
#endif
Vtop__Syms::Vtop__Syms(VerilatedContext* contextp, const char* namep, Vtop* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    , __Vm_didInit{modelp->m_didInit}
    // Setup top module instance
    , TOP{this, namep}
{
    // Check resources
    Verilated::stackCheck(189);
    // Setup sub module instances
    TOP__tinytracer_pkg.ctor(this, "tinytracer_pkg");
    TOP__tt_um_cordic__DOT__fu.ctor(this, "tt_um_cordic.fu");
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-9);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    TOP.__PVT__tinytracer_pkg = &TOP__tinytracer_pkg;
    TOP.__PVT__tt_um_cordic__DOT__fu = &TOP__tt_um_cordic__DOT__fu;
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
    TOP__tinytracer_pkg.__Vconfigure(true);
    TOP__tt_um_cordic__DOT__fu.__Vconfigure(true);
    // Setup scopes
    VerilatedScope::scopesConstructFromTable(Vtop__Syms__VpiScopeTable, 8, this);
    // Set up scope hierarchy
    __Vhier.add(0, __Vscopep_tinytracer_pkg);
    __Vhier.add(0, __Vscopep_tt_um_cordic);
    __Vhier.add(__Vscopep_tt_um_cordic, __Vscopep_tt_um_cordic__fu);
    __Vhier.add(__Vscopep_tt_um_cordic, __Vscopep_tt_um_cordic__u_cordic);
    __Vhier.add(__Vscopep_tt_um_cordic__u_cordic, __Vscopep_tt_um_cordic__u_cordic__unnamedblk1);
    __Vhier.add(__Vscopep_tt_um_cordic__u_cordic, __Vscopep_tt_um_cordic__u_cordic__unnamedblk2);
    __Vhier.add(__Vscopep_tt_um_cordic__u_cordic, __Vscopep_tt_um_cordic__u_cordic__unnamedblk3);
    // Setup export functions - final: 0
    // Setup export functions - final: 1
    // Setup public variables
    __Vscopep_TOP->varsInsertFromTable(Vtop___024root__VpiVarTable0, 8, &(TOP));
    __Vscopep_tinytracer_pkg->varInsert("ADDR_WIDTH", const_cast<void*>(static_cast<const void*>(&(TOP__tinytracer_pkg.ADDR_WIDTH))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY|VLVF_SIGNED, 0, 1 ,31,0);
    __Vscopep_tinytracer_pkg->varInsert("BV_BASE", const_cast<void*>(static_cast<const void*>(&(TOP__tinytracer_pkg.BV_BASE))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY|VLVF_SIGNED, 0, 1 ,31,0);
    __Vscopep_tinytracer_pkg->varInsert("BV_WORDS", const_cast<void*>(static_cast<const void*>(&(TOP__tinytracer_pkg.BV_WORDS))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY|VLVF_SIGNED, 0, 1 ,31,0);
    __Vscopep_tinytracer_pkg->varInsert("COLOUR_DEPTH", const_cast<void*>(static_cast<const void*>(&(TOP__tinytracer_pkg.COLOUR_DEPTH))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY|VLVF_SIGNED, 0, 1 ,31,0);
    __Vscopep_tinytracer_pkg->varInsert("DATA_WIDTH", const_cast<void*>(static_cast<const void*>(&(TOP__tinytracer_pkg.DATA_WIDTH))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY|VLVF_SIGNED, 0, 1 ,31,0);
    __Vscopep_tinytracer_pkg->varInsert("DIM_WIDTH", const_cast<void*>(static_cast<const void*>(&(TOP__tinytracer_pkg.DIM_WIDTH))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY|VLVF_SIGNED, 0, 1 ,31,0);
    __Vscopep_tinytracer_pkg->varInsert("DIR_FRAC", const_cast<void*>(static_cast<const void*>(&(TOP__tinytracer_pkg.DIR_FRAC))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY|VLVF_SIGNED, 0, 1 ,31,0);
    __Vscopep_tinytracer_pkg->varInsert("DLE", const_cast<void*>(static_cast<const void*>(&(TOP__tinytracer_pkg.DLE))), true, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,7,0);
    __Vscopep_tinytracer_pkg->varInsert("HDR_WORDS", const_cast<void*>(static_cast<const void*>(&(TOP__tinytracer_pkg.HDR_WORDS))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY|VLVF_SIGNED, 0, 1 ,31,0);
    __Vscopep_tinytracer_pkg->varInsert("MACROOP_W", const_cast<void*>(static_cast<const void*>(&(TOP__tinytracer_pkg.MACROOP_W))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY|VLVF_SIGNED, 0, 1 ,31,0);
    __Vscopep_tinytracer_pkg->varInsert("MACRO_W", const_cast<void*>(static_cast<const void*>(&(TOP__tinytracer_pkg.MACRO_W))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY|VLVF_SIGNED, 0, 1 ,31,0);
    __Vscopep_tinytracer_pkg->varInsert("MAX_BOUNCES", const_cast<void*>(static_cast<const void*>(&(TOP__tinytracer_pkg.MAX_BOUNCES))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY|VLVF_SIGNED, 0, 1 ,31,0);
    __Vscopep_tinytracer_pkg->varInsert("MAX_BV", const_cast<void*>(static_cast<const void*>(&(TOP__tinytracer_pkg.MAX_BV))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY|VLVF_SIGNED, 0, 1 ,31,0);
    __Vscopep_tinytracer_pkg->varInsert("MAX_SPP", const_cast<void*>(static_cast<const void*>(&(TOP__tinytracer_pkg.MAX_SPP))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY|VLVF_SIGNED, 0, 1 ,31,0);
    __Vscopep_tinytracer_pkg->varInsert("MICROOP_W", const_cast<void*>(static_cast<const void*>(&(TOP__tinytracer_pkg.MICROOP_W))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY|VLVF_SIGNED, 0, 1 ,31,0);
    __Vscopep_tinytracer_pkg->varInsert("MICRO_W", const_cast<void*>(static_cast<const void*>(&(TOP__tinytracer_pkg.MICRO_W))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY|VLVF_SIGNED, 0, 1 ,31,0);
    __Vscopep_tinytracer_pkg->varInsert("OBJ_START", const_cast<void*>(static_cast<const void*>(&(TOP__tinytracer_pkg.OBJ_START))), true, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,7,0);
    __Vscopep_tinytracer_pkg->varInsert("PIXEL_START", const_cast<void*>(static_cast<const void*>(&(TOP__tinytracer_pkg.PIXEL_START))), true, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,7,0);
    __Vscopep_tinytracer_pkg->varInsert("PIX_W", const_cast<void*>(static_cast<const void*>(&(TOP__tinytracer_pkg.PIX_W))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY|VLVF_SIGNED, 0, 1 ,31,0);
    __Vscopep_tinytracer_pkg->varInsert("POS_FRAC", const_cast<void*>(static_cast<const void*>(&(TOP__tinytracer_pkg.POS_FRAC))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY|VLVF_SIGNED, 0, 1 ,31,0);
    __Vscopep_tinytracer_pkg->varInsert("RENDER_START", const_cast<void*>(static_cast<const void*>(&(TOP__tinytracer_pkg.RENDER_START))), true, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,7,0);
    __Vscopep_tinytracer_pkg->varInsert("SAMPLE_DEPTH", const_cast<void*>(static_cast<const void*>(&(TOP__tinytracer_pkg.SAMPLE_DEPTH))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY|VLVF_SIGNED, 0, 1 ,31,0);
    __Vscopep_tinytracer_pkg->varInsert("SCRATCH_WORDS", const_cast<void*>(static_cast<const void*>(&(TOP__tinytracer_pkg.SCRATCH_WORDS))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY|VLVF_SIGNED, 0, 1 ,31,0);
    __Vscopep_tinytracer_pkg->varInsert("SPH_WORDS", const_cast<void*>(static_cast<const void*>(&(TOP__tinytracer_pkg.SPH_WORDS))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY|VLVF_SIGNED, 0, 1 ,31,0);
    __Vscopep_tinytracer_pkg->varInsert("SPP_LOG2_W", const_cast<void*>(static_cast<const void*>(&(TOP__tinytracer_pkg.SPP_LOG2_W))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY|VLVF_SIGNED, 0, 1 ,31,0);
    __Vscopep_tinytracer_pkg->varInsert("TRI_WORDS", const_cast<void*>(static_cast<const void*>(&(TOP__tinytracer_pkg.TRI_WORDS))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY|VLVF_SIGNED, 0, 1 ,31,0);
    __Vscopep_tinytracer_pkg->varInsert("WLEN", const_cast<void*>(static_cast<const void*>(&(TOP__tinytracer_pkg.WLEN))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY|VLVF_SIGNED, 0, 1 ,31,0);
    __Vscopep_tt_um_cordic->varsInsertFromTable(Vtop___024root__VpiVarTable1, 14, &(TOP));
    __Vscopep_tt_um_cordic__fu->varsInsertFromTable(Vtop_fu_if__VpiVarTable2, 8, &(TOP__tt_um_cordic__DOT__fu));
    __Vscopep_tt_um_cordic__u_cordic->varsInsertFromTable(Vtop___024root__VpiVarTable3, 31, &(TOP));
    __Vscopep_tt_um_cordic__u_cordic->varInsert("ATANH_LUT", const_cast<void*>(static_cast<const void*>(&(TOP.tt_um_cordic__DOT__u_cordic__DOT__ATANH_LUT))), true, VLVT_UINT16, VLVD_NODIR|VLVF_PUB_RW, 1, 1 ,0,15 ,15,0);
    __Vscopep_tt_um_cordic__u_cordic->varInsert("ATAN_LUT", const_cast<void*>(static_cast<const void*>(&(TOP.tt_um_cordic__DOT__u_cordic__DOT__ATAN_LUT))), true, VLVT_UINT16, VLVD_NODIR|VLVF_PUB_RW, 1, 1 ,0,15 ,15,0);
    __Vscopep_tt_um_cordic__u_cordic->varInsert("IDLE", const_cast<void*>(static_cast<const void*>(&(TOP.tt_um_cordic__DOT__u_cordic__DOT__IDLE))), true, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,2,0);
    __Vscopep_tt_um_cordic__u_cordic->varInsert("INIT", const_cast<void*>(static_cast<const void*>(&(TOP.tt_um_cordic__DOT__u_cordic__DOT__INIT))), true, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,2,0);
    __Vscopep_tt_um_cordic__u_cordic->varInsert("ITER", const_cast<void*>(static_cast<const void*>(&(TOP.tt_um_cordic__DOT__u_cordic__DOT__ITER))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY|VLVF_SIGNED, 0, 1 ,31,0);
    __Vscopep_tt_um_cordic__u_cordic->varInsert("LOOP", const_cast<void*>(static_cast<const void*>(&(TOP.tt_um_cordic__DOT__u_cordic__DOT__LOOP))), true, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,2,0);
    __Vscopep_tt_um_cordic__u_cordic->varInsert("NORMALIZE", const_cast<void*>(static_cast<const void*>(&(TOP.tt_um_cordic__DOT__u_cordic__DOT__NORMALIZE))), true, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,2,0);
    __Vscopep_tt_um_cordic__u_cordic->varInsert("POSTSCALE", const_cast<void*>(static_cast<const void*>(&(TOP.tt_um_cordic__DOT__u_cordic__DOT__POSTSCALE))), true, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,2,0);
    __Vscopep_tt_um_cordic__u_cordic->varInsert("REVERT", const_cast<void*>(static_cast<const void*>(&(TOP.tt_um_cordic__DOT__u_cordic__DOT__REVERT))), true, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,2,0);
    __Vscopep_tt_um_cordic__u_cordic__unnamedblk1->varsInsertFromTable(Vtop___024root__VpiVarTable4, 1, &(TOP));
    __Vscopep_tt_um_cordic__u_cordic__unnamedblk2->varsInsertFromTable(Vtop___024root__VpiVarTable5, 1, &(TOP));
    __Vscopep_tt_um_cordic__u_cordic__unnamedblk3->varsInsertFromTable(Vtop___024root__VpiVarTable6, 1, &(TOP));
}

Vtop__Syms::~Vtop__Syms() {
    // Tear down scope hierarchy
    __Vhier.remove(0, __Vscopep_tinytracer_pkg);
    __Vhier.remove(0, __Vscopep_tt_um_cordic);
    __Vhier.remove(__Vscopep_tt_um_cordic, __Vscopep_tt_um_cordic__fu);
    __Vhier.remove(__Vscopep_tt_um_cordic, __Vscopep_tt_um_cordic__u_cordic);
    __Vhier.remove(__Vscopep_tt_um_cordic__u_cordic, __Vscopep_tt_um_cordic__u_cordic__unnamedblk1);
    __Vhier.remove(__Vscopep_tt_um_cordic__u_cordic, __Vscopep_tt_um_cordic__u_cordic__unnamedblk2);
    __Vhier.remove(__Vscopep_tt_um_cordic__u_cordic, __Vscopep_tt_um_cordic__u_cordic__unnamedblk3);
    // Clear keys from hierarchy map after values have been removed
    __Vhier.clear();
    // Tear down scopes
    VL_DO_CLEAR(delete __Vscopep_TOP, __Vscopep_TOP = nullptr);
    VL_DO_CLEAR(delete __Vscopep_tinytracer_pkg, __Vscopep_tinytracer_pkg = nullptr);
    VL_DO_CLEAR(delete __Vscopep_tt_um_cordic, __Vscopep_tt_um_cordic = nullptr);
    VL_DO_CLEAR(delete __Vscopep_tt_um_cordic__fu, __Vscopep_tt_um_cordic__fu = nullptr);
    VL_DO_CLEAR(delete __Vscopep_tt_um_cordic__u_cordic, __Vscopep_tt_um_cordic__u_cordic = nullptr);
    VL_DO_CLEAR(delete __Vscopep_tt_um_cordic__u_cordic__unnamedblk1, __Vscopep_tt_um_cordic__u_cordic__unnamedblk1 = nullptr);
    VL_DO_CLEAR(delete __Vscopep_tt_um_cordic__u_cordic__unnamedblk2, __Vscopep_tt_um_cordic__u_cordic__unnamedblk2 = nullptr);
    VL_DO_CLEAR(delete __Vscopep_tt_um_cordic__u_cordic__unnamedblk3, __Vscopep_tt_um_cordic__u_cordic__unnamedblk3 = nullptr);
    // Tear down sub module instances
    TOP__tt_um_cordic__DOT__fu.dtor();
    TOP__tinytracer_pkg.dtor();
}
