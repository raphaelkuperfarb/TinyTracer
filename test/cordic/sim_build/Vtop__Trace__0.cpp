// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals

#include "verilated_vcd_c.h"
#include "Vtop__Syms.h"


void Vtop___024root__trace_chg_0_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vtop___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_0\n"); );
    // Body
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    Vtop___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vtop___024root__trace_chg_dtype____0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<SData/*15:0*/, 16>& __VdtypeVar);
void Vtop___024root__trace_chg_dtype____1(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<SData/*15:0*/, 16>& __VdtypeVar);

void Vtop___024root__trace_chg_0_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_0_sub_0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 0);
    bufp->chgCData(oldp+0,(vlSelfRef.ui_in),8);
    bufp->chgCData(oldp+1,(vlSelfRef.uo_out),8);
    bufp->chgCData(oldp+2,(vlSelfRef.uio_in),8);
    bufp->chgCData(oldp+3,(vlSelfRef.uio_out),8);
    bufp->chgCData(oldp+4,(vlSelfRef.uio_oe),8);
    bufp->chgBit(oldp+5,(vlSelfRef.ena));
    bufp->chgBit(oldp+6,(vlSelfRef.clk));
    bufp->chgBit(oldp+7,(vlSelfRef.rst_n));
    bufp->chgCData(oldp+8,(vlSelfRef.tt_um_cordic__DOT__ui_in),8);
    bufp->chgCData(oldp+9,(vlSelfRef.tt_um_cordic__DOT__uo_out),8);
    bufp->chgCData(oldp+10,(vlSelfRef.tt_um_cordic__DOT__uio_in),8);
    bufp->chgCData(oldp+11,(vlSelfRef.tt_um_cordic__DOT__uio_out),8);
    bufp->chgCData(oldp+12,(vlSelfRef.tt_um_cordic__DOT__uio_oe),8);
    bufp->chgBit(oldp+13,(vlSelfRef.tt_um_cordic__DOT__ena));
    bufp->chgBit(oldp+14,(vlSelfRef.tt_um_cordic__DOT__clk));
    bufp->chgBit(oldp+15,(vlSelfRef.tt_um_cordic__DOT__rst_n));
    bufp->chgSData(oldp+16,(vlSelfRef.tt_um_cordic__DOT__op1_q),16);
    bufp->chgSData(oldp+17,(vlSelfRef.tt_um_cordic__DOT__op2_q),16);
    bufp->chgSData(oldp+18,(vlSelfRef.tt_um_cordic__DOT__result_q),16);
    bufp->chgBit(oldp+19,(vlSelfRef.tt_um_cordic__DOT__result_valid));
    bufp->chgBit(oldp+20,(vlSelfRef.tt_um_cordic__DOT__fmt_q));
    bufp->chgBit(oldp+21,(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__clk));
    bufp->chgBit(oldp+22,(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__rst_n));
    Vtop___024root__trace_chg_dtype____0(vlSelf, bufp, 23, vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__ATAN_LUT);
    Vtop___024root__trace_chg_dtype____1(vlSelf, bufp, 39, vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__ATANH_LUT);
    bufp->chgCData(oldp+55,(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__current_state),3);
    bufp->chgCData(oldp+56,(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__next_state),3);
    bufp->chgCData(oldp+57,(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__cycles_completed),4);
    bufp->chgCData(oldp+58,(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__j),4);
    bufp->chgSData(oldp+59,(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x),16);
    bufp->chgSData(oldp+60,(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__y),16);
    bufp->chgSData(oldp+61,(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__z),16);
    bufp->chgSData(oldp+62,(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x_next),16);
    bufp->chgSData(oldp+63,(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__y_next),16);
    bufp->chgSData(oldp+64,(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__z_next),16);
    bufp->chgBit(oldp+65,(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__repeated));
    bufp->chgBit(oldp+66,(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__start));
    bufp->chgCData(oldp+67,(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__k),4);
    bufp->chgCData(oldp+68,(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__l),4);
    bufp->chgCData(oldp+69,(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__shift_next),4);
    bufp->chgCData(oldp+70,(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__shift_q),4);
    bufp->chgBit(oldp+71,(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__shift_right_next));
    bufp->chgBit(oldp+72,(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__shift_right_q));
    bufp->chgBit(oldp+73,(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__tooBig));
    bufp->chgSData(oldp+74,(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__ym),16);
    bufp->chgSData(oldp+75,(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__xp),16);
    bufp->chgSData(oldp+76,(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__normalized),16);
    bufp->chgIData(oldp+77,(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__postscale_product),32);
    bufp->chgIData(oldp+78,(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__postscale_result),32);
    bufp->chgBit(oldp+79,(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__neg_q));
    bufp->chgBit(oldp+80,(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__neg_next));
    bufp->chgBit(oldp+81,(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__angleShift));
    bufp->chgCData(oldp+82,(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__opcode),2);
    bufp->chgBit(oldp+83,(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__format));
    bufp->chgBit(oldp+84,(vlSymsp->TOP__tt_um_cordic__DOT__fu.req_valid));
    bufp->chgSData(oldp+85,(vlSymsp->TOP__tt_um_cordic__DOT__fu.req_op1),16);
    bufp->chgSData(oldp+86,(vlSymsp->TOP__tt_um_cordic__DOT__fu.req_op2),16);
    bufp->chgCData(oldp+87,(vlSymsp->TOP__tt_um_cordic__DOT__fu.req_opcode),3);
    bufp->chgBit(oldp+88,(vlSymsp->TOP__tt_um_cordic__DOT__fu.req_fmt));
    bufp->chgBit(oldp+89,(vlSymsp->TOP__tt_um_cordic__DOT__fu.req_ready));
    bufp->chgBit(oldp+90,(vlSymsp->TOP__tt_um_cordic__DOT__fu.resp_done));
    bufp->chgSData(oldp+91,(vlSymsp->TOP__tt_um_cordic__DOT__fu.resp_result),16);
}

void Vtop___024root__trace_chg_dtype____0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<SData/*15:0*/, 16>& __VdtypeVar) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_dtype____0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode +  offset);
    bufp->chgSData(oldp+0,(__VdtypeVar[0]),16);
    bufp->chgSData(oldp+1,(__VdtypeVar[1]),16);
    bufp->chgSData(oldp+2,(__VdtypeVar[2]),16);
    bufp->chgSData(oldp+3,(__VdtypeVar[3]),16);
    bufp->chgSData(oldp+4,(__VdtypeVar[4]),16);
    bufp->chgSData(oldp+5,(__VdtypeVar[5]),16);
    bufp->chgSData(oldp+6,(__VdtypeVar[6]),16);
    bufp->chgSData(oldp+7,(__VdtypeVar[7]),16);
    bufp->chgSData(oldp+8,(__VdtypeVar[8]),16);
    bufp->chgSData(oldp+9,(__VdtypeVar[9]),16);
    bufp->chgSData(oldp+10,(__VdtypeVar[10]),16);
    bufp->chgSData(oldp+11,(__VdtypeVar[11]),16);
    bufp->chgSData(oldp+12,(__VdtypeVar[12]),16);
    bufp->chgSData(oldp+13,(__VdtypeVar[13]),16);
    bufp->chgSData(oldp+14,(__VdtypeVar[14]),16);
    bufp->chgSData(oldp+15,(__VdtypeVar[15]),16);
}

void Vtop___024root__trace_chg_dtype____1(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<SData/*15:0*/, 16>& __VdtypeVar) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_dtype____1\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode +  offset);
    bufp->chgSData(oldp+0,(__VdtypeVar[0]),16);
    bufp->chgSData(oldp+1,(__VdtypeVar[1]),16);
    bufp->chgSData(oldp+2,(__VdtypeVar[2]),16);
    bufp->chgSData(oldp+3,(__VdtypeVar[3]),16);
    bufp->chgSData(oldp+4,(__VdtypeVar[4]),16);
    bufp->chgSData(oldp+5,(__VdtypeVar[5]),16);
    bufp->chgSData(oldp+6,(__VdtypeVar[6]),16);
    bufp->chgSData(oldp+7,(__VdtypeVar[7]),16);
    bufp->chgSData(oldp+8,(__VdtypeVar[8]),16);
    bufp->chgSData(oldp+9,(__VdtypeVar[9]),16);
    bufp->chgSData(oldp+10,(__VdtypeVar[10]),16);
    bufp->chgSData(oldp+11,(__VdtypeVar[11]),16);
    bufp->chgSData(oldp+12,(__VdtypeVar[12]),16);
    bufp->chgSData(oldp+13,(__VdtypeVar[13]),16);
    bufp->chgSData(oldp+14,(__VdtypeVar[14]),16);
    bufp->chgSData(oldp+15,(__VdtypeVar[15]),16);
}

void Vtop___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_cleanup\n"); );
    // Locals
    VlUnpacked<CData/*0:0*/, 1> __Vm_traceActivity;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        __Vm_traceActivity[__Vi0] = 0;
    }
    // Body
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vlSymsp->__Vm_activity = false;
    __Vm_traceActivity[0U] = 0U;
}
