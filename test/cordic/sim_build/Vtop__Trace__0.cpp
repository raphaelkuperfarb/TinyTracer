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
    bufp->chgCData(oldp+23,(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__current_state),3);
    bufp->chgCData(oldp+24,(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__next_state),3);
    bufp->chgCData(oldp+25,(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__cycles_completed),4);
    bufp->chgCData(oldp+26,(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__j),5);
    bufp->chgCData(oldp+27,(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__iteration),5);
    bufp->chgSData(oldp+28,(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x),16);
    bufp->chgSData(oldp+29,(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__y),16);
    bufp->chgSData(oldp+30,(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__z),16);
    bufp->chgSData(oldp+31,(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x_next),16);
    bufp->chgSData(oldp+32,(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__y_next),16);
    bufp->chgSData(oldp+33,(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__z_next),16);
    bufp->chgSData(oldp+34,(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__negative_x),16);
    bufp->chgSData(oldp+35,(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__negative_y),16);
    bufp->chgSData(oldp+36,(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x_shifted),16);
    bufp->chgSData(oldp+37,(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__y_shifted),16);
    bufp->chgCData(oldp+38,(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__shift_by),4);
    bufp->chgBit(oldp+39,(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x_subtract));
    bufp->chgBit(oldp+40,(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__y_subtract));
    bufp->chgBit(oldp+41,(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__z_subtract));
    bufp->chgSData(oldp+42,(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__one_shifted),16);
    bufp->chgSData(oldp+43,(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x_minus_yshifted),16);
    bufp->chgSData(oldp+44,(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x_plus_yshifted),16);
    bufp->chgSData(oldp+45,(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__y_minus_xshifted),16);
    bufp->chgSData(oldp+46,(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__y_plus_xshifted),16);
    bufp->chgBit(oldp+47,(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__repeated));
    bufp->chgBit(oldp+48,(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__start));
    bufp->chgCData(oldp+49,(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__k),4);
    bufp->chgCData(oldp+50,(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__l),4);
    bufp->chgCData(oldp+51,(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__shift_diff),4);
    bufp->chgCData(oldp+52,(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__shift_next),4);
    bufp->chgCData(oldp+53,(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__shift_q),4);
    bufp->chgCData(oldp+54,(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__shift_base),4);
    bufp->chgBit(oldp+55,(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__shift_right_next));
    bufp->chgBit(oldp+56,(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__shift_right_q));
    bufp->chgBit(oldp+57,(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__tooBig));
    bufp->chgSData(oldp+58,(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__ym),16);
    bufp->chgSData(oldp+59,(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__xp),16);
    bufp->chgSData(oldp+60,(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__normalized),16);
    bufp->chgIData(oldp+61,(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__ps1),19);
    bufp->chgIData(oldp+62,(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__ps2),22);
    bufp->chgIData(oldp+63,(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__ps3),25);
    bufp->chgIData(oldp+64,(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__ps4),27);
    bufp->chgIData(oldp+65,(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__ps5),30);
    bufp->chgIData(oldp+66,(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__postscale_product),31);
    bufp->chgIData(oldp+67,(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__postscale_result),17);
    bufp->chgBit(oldp+68,(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__angle_shift));
    bufp->chgBit(oldp+69,(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__angle_shift_q));
    bufp->chgCData(oldp+70,(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__opcode),2);
    bufp->chgBit(oldp+71,(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__format));
    bufp->chgBit(oldp+72,(vlSymsp->TOP__tt_um_cordic__DOT__fu.req_valid));
    bufp->chgSData(oldp+73,(vlSymsp->TOP__tt_um_cordic__DOT__fu.req_op1),16);
    bufp->chgSData(oldp+74,(vlSymsp->TOP__tt_um_cordic__DOT__fu.req_op2),16);
    bufp->chgCData(oldp+75,(vlSymsp->TOP__tt_um_cordic__DOT__fu.req_opcode),3);
    bufp->chgBit(oldp+76,(vlSymsp->TOP__tt_um_cordic__DOT__fu.req_fmt));
    bufp->chgBit(oldp+77,(vlSymsp->TOP__tt_um_cordic__DOT__fu.req_ready));
    bufp->chgBit(oldp+78,(vlSymsp->TOP__tt_um_cordic__DOT__fu.resp_done));
    bufp->chgSData(oldp+79,(vlSymsp->TOP__tt_um_cordic__DOT__fu.resp_result),16);
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
