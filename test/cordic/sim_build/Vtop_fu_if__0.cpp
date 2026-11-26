// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"

void Vtop_fu_if___ico_sequent__TOP__tt_um_cordic__DOT__fu__0(Vtop_fu_if* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtop_fu_if___ico_sequent__TOP__tt_um_cordic__DOT__fu__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.req_ready = (0U == (IData)(vlSymsp->TOP.tt_um_cordic__DOT__u_cordic__DOT__current_state));
    vlSelfRef.resp_done = (4U == (IData)(vlSymsp->TOP.tt_um_cordic__DOT__u_cordic__DOT__current_state));
    vlSelfRef.req_op1 = vlSymsp->TOP.tt_um_cordic__DOT__op1_q;
    vlSelfRef.req_op2 = vlSymsp->TOP.tt_um_cordic__DOT__op2_q;
    vlSelfRef.req_opcode = (3U & ((IData)(vlSymsp->TOP.tt_um_cordic__DOT__ui_in) 
                                  >> 6U));
    vlSelfRef.req_valid = (1U & ((~ (IData)(vlSymsp->TOP.tt_um_cordic__DOT__result_valid)) 
                                 & ((IData)(vlSymsp->TOP.tt_um_cordic__DOT__ui_in) 
                                    >> 1U)));
    vlSelfRef.req_fmt = (1U & ((2U & (IData)(vlSymsp->TOP.tt_um_cordic__DOT__ui_in))
                                ? ((IData)(vlSymsp->TOP.tt_um_cordic__DOT__ui_in) 
                                   >> 5U) : (IData)(vlSymsp->TOP.tt_um_cordic__DOT__fmt_q)));
}

void Vtop_fu_if___ico_sequent__TOP__tt_um_cordic__DOT__fu__1(Vtop_fu_if* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtop_fu_if___ico_sequent__TOP__tt_um_cordic__DOT__fu__1\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.resp_result = ((0U == (IData)(vlSymsp->TOP.tt_um_cordic__DOT__u_cordic__DOT__opcode))
                              ? (IData)(vlSymsp->TOP.tt_um_cordic__DOT__u_cordic__DOT__z)
                              : (IData)(vlSymsp->TOP.tt_um_cordic__DOT__u_cordic__DOT__x_next));
}

void Vtop_fu_if___nba_sequent__TOP__tt_um_cordic__DOT__fu__0(Vtop_fu_if* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtop_fu_if___nba_sequent__TOP__tt_um_cordic__DOT__fu__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.req_valid = (1U & ((~ (IData)(vlSymsp->TOP.tt_um_cordic__DOT__result_valid)) 
                                 & ((IData)(vlSymsp->TOP.tt_um_cordic__DOT__ui_in) 
                                    >> 1U)));
    vlSelfRef.req_fmt = (1U & ((2U & (IData)(vlSymsp->TOP.tt_um_cordic__DOT__ui_in))
                                ? ((IData)(vlSymsp->TOP.tt_um_cordic__DOT__ui_in) 
                                   >> 5U) : (IData)(vlSymsp->TOP.tt_um_cordic__DOT__fmt_q)));
    vlSelfRef.req_op1 = vlSymsp->TOP.tt_um_cordic__DOT__op1_q;
    vlSelfRef.req_op2 = vlSymsp->TOP.tt_um_cordic__DOT__op2_q;
}

void Vtop_fu_if___nba_sequent__TOP__tt_um_cordic__DOT__fu__1(Vtop_fu_if* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtop_fu_if___nba_sequent__TOP__tt_um_cordic__DOT__fu__1\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.resp_done = (4U == (IData)(vlSymsp->TOP.tt_um_cordic__DOT__u_cordic__DOT__current_state));
    vlSelfRef.req_ready = (0U == (IData)(vlSymsp->TOP.tt_um_cordic__DOT__u_cordic__DOT__current_state));
}
