// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"

void Vtop___024root___eval_sample(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_sample\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__ico(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG
bool Vtop___024root___trigger_anySet__ico(const VlUnpacked<QData/*63:0*/, 1> &in);
void Vtop_fu_if___ico_sequent__TOP__tt_um_cordic__DOT__fu__0(Vtop_fu_if* vlSelf);
void Vtop___024root___ico_sequent__TOP__1(Vtop___024root* vlSelf);

bool Vtop___024root___eval_ico(Vtop___024root* vlSelf, CData/*0:0*/ firstIteration) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_ico\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VicoExecute;
    // Body
    vlSelfRef.__VicoTriggered[0U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VicoTriggered[0U]) 
                                     | (IData)((IData)(firstIteration)));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtop___024root___dump_triggers__ico(vlSelfRef.__VicoTriggered, "ico"s);
    }
#endif
    __VicoExecute = Vtop___024root___trigger_anySet__ico(vlSelfRef.__VicoTriggered);
    if (__VicoExecute) {
        {
            // Inlined CFunc: _eval_body__ico
            if ((1ULL & vlSelfRef.__VicoTriggered[0U])) {
                {
                    // Inlined CFunc: _ico_sequent__TOP__0
                    vlSymsp->TOP__tt_um_cordic__DOT__fu.req_ready = 0U;
                    if ((0U == (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__current_state))) {
                        vlSymsp->TOP__tt_um_cordic__DOT__fu.req_ready = 1U;
                    }
                    vlSymsp->TOP__tt_um_cordic__DOT__fu.resp_done = 0U;
                    if ((0U != (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__current_state))) {
                        if ((1U != (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__current_state))) {
                            if ((3U != (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__current_state))) {
                                if ((2U != (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__current_state))) {
                                    if ((6U != (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__current_state))) {
                                        if ((4U == (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__current_state))) {
                                            vlSymsp->TOP__tt_um_cordic__DOT__fu.resp_done = 1U;
                                        }
                                    }
                                }
                            }
                        }
                    }
                    vlSelfRef.tt_um_cordic__DOT__uio_in 
                        = vlSelfRef.uio_in;
                    vlSelfRef.tt_um_cordic__DOT__clk 
                        = vlSelfRef.clk;
                    vlSelfRef.tt_um_cordic__DOT__uio_oe 
                        = (0x000000ffU & (- (IData)((IData)(vlSelfRef.tt_um_cordic__DOT__result_valid))));
                    vlSelfRef.tt_um_cordic__DOT__uo_out 
                        = (0x000000ffU & (IData)(vlSelfRef.tt_um_cordic__DOT__result_q));
                    vlSelfRef.tt_um_cordic__DOT__uio_out 
                        = (0x000000ffU & ((IData)(vlSelfRef.tt_um_cordic__DOT__result_q) 
                                          >> 8U));
                    vlSelfRef.tt_um_cordic__DOT__ena 
                        = vlSelfRef.ena;
                    vlSelfRef.tt_um_cordic__DOT__rst_n 
                        = vlSelfRef.rst_n;
                    vlSelfRef.tt_um_cordic__DOT__ui_in 
                        = vlSelfRef.ui_in;
                    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__clk 
                        = vlSelfRef.tt_um_cordic__DOT__clk;
                    vlSelfRef.uio_oe = vlSelfRef.tt_um_cordic__DOT__uio_oe;
                    vlSelfRef.uo_out = vlSelfRef.tt_um_cordic__DOT__uo_out;
                    vlSelfRef.uio_out = vlSelfRef.tt_um_cordic__DOT__uio_out;
                    vlSelfRef.tt_um_cordic__DOT___unused 
                        = vlSelfRef.tt_um_cordic__DOT__ena;
                    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__rst_n 
                        = vlSelfRef.tt_um_cordic__DOT__rst_n;
                }
                Vtop_fu_if___ico_sequent__TOP__tt_um_cordic__DOT__fu__0((&vlSymsp->TOP__tt_um_cordic__DOT__fu));
                Vtop___024root___ico_sequent__TOP__1(vlSelf);
            }
        }
    }
    return (__VicoExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG
void Vtop___024root___trigger_orInto__act_vec_vec(VlUnpacked<QData/*63:0*/, 1> &out, const VlUnpacked<QData/*63:0*/, 1> &in);

bool Vtop___024root___eval_act(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_act\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    {
        // Inlined CFunc: _eval_triggers_vec__act
        vlSelfRef.__VactTriggered[0U] = (QData)((IData)(
                                                        ((((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__clk) 
                                                           & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tt_um_cordic__DOT__u_cordic__DOT__clk__0))) 
                                                          << 1U) 
                                                         | ((IData)(vlSelfRef.tt_um_cordic__DOT__clk) 
                                                            & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tt_um_cordic__DOT__clk__0))))));
        vlSelfRef.__Vtrigprevexpr___TOP__tt_um_cordic__DOT__clk__0 
            = vlSelfRef.tt_um_cordic__DOT__clk;
        vlSelfRef.__Vtrigprevexpr___TOP__tt_um_cordic__DOT__u_cordic__DOT__clk__0 
            = vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__clk;
    }
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtop___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
    }
#endif
    Vtop___024root___trigger_orInto__act_vec_vec(vlSelfRef.__VnbaTriggered, vlSelfRef.__VactTriggered);
    return (0U);
}

bool Vtop___024root___eval_inact(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_inact\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    return (0U);
}

bool Vtop___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in);
void Vtop___024root___eval_body__nba(Vtop___024root* vlSelf);
void Vtop___024root___trigger_clear__act(VlUnpacked<QData/*63:0*/, 1> &out);

bool Vtop___024root___eval_nba(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_nba\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = Vtop___024root___trigger_anySet__act(vlSelfRef.__VnbaTriggered);
    if (__VnbaExecute) {
        Vtop___024root___eval_body__nba(vlSelf);
        Vtop___024root___trigger_clear__act(vlSelfRef.__VnbaTriggered);
    }
    return (__VnbaExecute);
}

bool Vtop___024root___eval_obs(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_obs\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    return (0U);
}

bool Vtop___024root___eval_react(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_react\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    return (0U);
}

void Vtop___024root___eval_postponed(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_postponed\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

bool Vtop___024root___trigger_anySet__ico(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___trigger_anySet__ico\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        if (in[n]) {
            return (1U);
        }
        n = ((IData)(1U) + n);
    } while ((1U > n));
    return (0U);
}

extern const VlWide<8>/*255:0*/ Vtop__ConstPool__CONST_h051babf7_0;
extern const VlWide<8>/*255:0*/ Vtop__ConstPool__CONST_h74ec95ef_0;
extern const VlUnpacked<CData/*2:0*/, 256> Vtop__ConstPool__TABLE_h15b7204f_0;

void Vtop___024root___ico_sequent__TOP__1(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ico_sequent__TOP__1\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSymsp->TOP__tt_um_cordic__DOT__fu.resp_result = 0U;
    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x_next 
        = vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x;
    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__y_next 
        = vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__y;
    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__z_next 
        = vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__z;
    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__shift_next 
        = vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__shift_q;
    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__shift_right_next 
        = vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__shift_right_q;
    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__neg_next 
        = vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__neg_q;
    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__k = 0U;
    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__l = 0U;
    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__tooBig = 0U;
    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__ym = 0U;
    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__xp = 0U;
    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__angleShift = 0U;
    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__normalized 
        = vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x;
    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__postscale_product = 0U;
    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__postscale_result = 0U;
    if ((0U != (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__current_state))) {
        if ((1U == (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__current_state))) {
            if ((0U == (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__opcode))) {
                vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x_next 
                    = vlSymsp->TOP__tt_um_cordic__DOT__fu.req_op2;
                vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__y_next 
                    = vlSymsp->TOP__tt_um_cordic__DOT__fu.req_op1;
                vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__z_next = 0U;
            } else if ((2U == (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__opcode))) {
                vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x_next = 0x26ddU;
                vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__y_next = 0U;
                vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__z_next 
                    = vlSymsp->TOP__tt_um_cordic__DOT__fu.req_op2;
            } else {
                if ((3U == (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__opcode))) {
                    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x_next 
                        = vlSymsp->TOP__tt_um_cordic__DOT__fu.req_op1;
                    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__y_next 
                        = vlSymsp->TOP__tt_um_cordic__DOT__fu.req_op2;
                } else {
                    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x_next 
                        = vlSymsp->TOP__tt_um_cordic__DOT__fu.req_op1;
                    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__y_next 
                        = vlSymsp->TOP__tt_um_cordic__DOT__fu.req_op1;
                }
                vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__z_next = 0U;
            }
        } else if ((3U == (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__current_state))) {
            if ((0U == (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__opcode))) {
                vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__neg_next 
                    = (1U & ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x) 
                             >> 0x0fU));
                vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__ym 
                    = (0x0000ffffU & ((0x00008000U 
                                       & (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__y))
                                       ? (~ (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__y))
                                       : (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__y)));
                vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__xp 
                    = (0x0000ffffU & ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__neg_next)
                                       ? (- (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x))
                                       : (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x)));
                vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__k = 0U;
                vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__l = 0U;
                vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__unnamedblk1__DOT__i = 0U;
                while (VL_GTS_III(32, 0x0000000fU, vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__unnamedblk1__DOT__i)) {
                    if ((1U & ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__xp) 
                               >> (0x0000000fU & vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__unnamedblk1__DOT__i)))) {
                        vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__k 
                            = (0x0000000fU & vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__unnamedblk1__DOT__i);
                    }
                    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__unnamedblk1__DOT__i 
                        = ((IData)(1U) + vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__unnamedblk1__DOT__i);
                }
                vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__unnamedblk2__DOT__h = 0U;
                while (VL_GTS_III(32, 0x0000000fU, vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__unnamedblk2__DOT__h)) {
                    if ((1U & ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__y) 
                               >> (0x0000000fU & vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__unnamedblk2__DOT__h)))) {
                        vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__l 
                            = (0x0000000fU & vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__unnamedblk2__DOT__h);
                    }
                    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__unnamedblk2__DOT__h 
                        = ((IData)(1U) + vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__unnamedblk2__DOT__h);
                }
                if (VL_GTS_III(16, (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__ym), (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x))) {
                    if ((0x00004000U & (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__ym))) {
                        vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__y_next 
                            = (0x0000ffffU & VL_SHIFTRS_III(16,16,32, (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__y), 1U));
                        vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x_next 
                            = (0x0000ffffU & VL_SHIFTL_III(16,16,32, (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__xp), 
                                                           ((IData)(0x0000000eU) 
                                                            - (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__k))));
                        vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__shift_next 
                            = (0x0000000fU & ((IData)(0x0fU) 
                                              - (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__k)));
                    } else {
                        vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x_next 
                            = (0x0000ffffU & VL_SHIFTL_III(16,16,32, (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__xp), 
                                                           ((IData)(1U) 
                                                            + 
                                                            ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__l) 
                                                             - (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__k)))));
                        vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__shift_next 
                            = (0x0000000fU & ((IData)(1U) 
                                              + ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__l) 
                                                 - (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__k))));
                    }
                }
            } else if ((2U == (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__opcode))) {
                vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__angleShift 
                    = (VL_LTS_III(16, 0x6f92U, (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__z)) 
                       | VL_GTS_III(16, 0x906eU, (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__z)));
                if (vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__angleShift) {
                    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__z_next 
                        = (0x0000ffffU & ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__z) 
                                          + ((0x00008000U 
                                              & (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__z))
                                              ? 0x0000c910U
                                              : 0x000136f0U)));
                }
            } else if ((3U == (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__opcode))) {
                vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x_next 
                    = (0x0000ffffU & ((0x00008000U 
                                       & (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x))
                                       ? (- (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x))
                                       : (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x)));
                vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__y_next 
                    = (0x0000ffffU & ((0x00008000U 
                                       & (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__y))
                                       ? (- (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__y))
                                       : (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__y)));
            } else if ((1U == (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__opcode))) {
                vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__tooBig 
                    = (0U != (0x0000007fU & ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x) 
                                             >> 8U)));
                vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__normalized 
                    = vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x;
                if ((1U & ((((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__tooBig) 
                             | (IData)((0U == (0x00c0U 
                                               & (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x))))) 
                            & (~ (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__format))) 
                           | (IData)(((0U == (0x6000U 
                                              & (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x))) 
                                      & (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__format)))))) {
                    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__unnamedblk3__DOT__i = 0U;
                    while (VL_GTS_III(32, 0x0000000fU, vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__unnamedblk3__DOT__i)) {
                        if ((1U & ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x) 
                                   >> (0x0000000fU 
                                       & vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__unnamedblk3__DOT__i)))) {
                            vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__k 
                                = (0x0000000fU & vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__unnamedblk3__DOT__i);
                        }
                        vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__unnamedblk3__DOT__i 
                            = ((IData)(1U) + vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__unnamedblk3__DOT__i);
                    }
                    if (vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__format) {
                        vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__shift_next 
                            = (0x0000000fU & ((1U & (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__k))
                                               ? ((IData)(0x0000000dU) 
                                                  - (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__k))
                                               : ((IData)(0x0000000eU) 
                                                  - (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__k))));
                        vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__shift_right_next = 0U;
                        vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__normalized 
                            = (0x0000ffffU & ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x) 
                                              << (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__shift_next)));
                    } else if (vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__tooBig) {
                        vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__shift_next 
                            = (0x0000000fU & ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__k) 
                                              - ((1U 
                                                  & (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__k))
                                                  ? 7U
                                                  : 6U)));
                        vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__shift_right_next = 1U;
                        vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__normalized 
                            = (0x0000ffffU & VL_SHIFTRS_III(16,16,4, (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x), (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__shift_next)));
                    } else {
                        vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__shift_next 
                            = (0x0000000fU & (((1U 
                                                & (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__k))
                                                ? 7U
                                                : 6U) 
                                              - (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__k)));
                        vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__shift_right_next = 0U;
                        vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__normalized 
                            = (0x0000ffffU & ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x) 
                                              << (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__shift_next)));
                    }
                }
                if (vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__format) {
                    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x_next 
                        = (0x0000ffffU & ((IData)(0x1000U) 
                                          + (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__normalized)));
                    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__y_next 
                        = (0x0000ffffU & ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__normalized) 
                                          - (IData)(0x1000U)));
                } else {
                    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x_next 
                        = (0x0000ffffU & ((IData)(0x0020U) 
                                          + (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__normalized)));
                    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__y_next 
                        = (0x0000ffffU & ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__normalized) 
                                          - (IData)(0x0020U)));
                }
            }
        } else if ((2U == (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__current_state))) {
            if ((0U == (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__opcode))) {
                if ((0x00008000U & (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__y))) {
                    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__y_next 
                        = (0x0000ffffU & ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__y) 
                                          + VL_SHIFTRS_III(16,16,4, (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x), (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__cycles_completed))));
                    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__z_next 
                        = (0x0000ffffU & ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__z) 
                                          - (0x4000U 
                                             >> (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__cycles_completed))));
                } else {
                    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__y_next 
                        = (0x0000ffffU & ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__y) 
                                          - VL_SHIFTRS_III(16,16,4, (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x), (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__cycles_completed))));
                    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__z_next 
                        = (0x0000ffffU & ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__z) 
                                          + (0x4000U 
                                             >> (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__cycles_completed))));
                }
            } else if ((2U == (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__opcode))) {
                if ((0x00008000U & (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__z))) {
                    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x_next 
                        = (0x0000ffffU & ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x) 
                                          + VL_SHIFTRS_III(16,16,4, (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__y), (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__cycles_completed))));
                    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__y_next 
                        = (0x0000ffffU & ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__y) 
                                          - VL_SHIFTRS_III(16,16,4, (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x), (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__cycles_completed))));
                    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__z_next 
                        = (0x0000ffffU & ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__z) 
                                          + (((0U == 
                                               (0x0000001fU 
                                                & ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__cycles_completed) 
                                                   << 4U)))
                                               ? 0U
                                               : (Vtop__ConstPool__CONST_h051babf7_0
                                                  [
                                                  (((IData)(0x0000000fU) 
                                                    + 
                                                    ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__cycles_completed) 
                                                     << 4U)) 
                                                   >> 5U)] 
                                                  << 
                                                  ((IData)(0x00000020U) 
                                                   - 
                                                   (0x0000001fU 
                                                    & ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__cycles_completed) 
                                                       << 4U))))) 
                                             | (Vtop__ConstPool__CONST_h051babf7_0
                                                [(0x07ffffffU 
                                                  & ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__cycles_completed) 
                                                     >> 1U))] 
                                                >> 
                                                (0x0000001fU 
                                                 & ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__cycles_completed) 
                                                    << 4U))))));
                } else {
                    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x_next 
                        = (0x0000ffffU & ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x) 
                                          - VL_SHIFTRS_III(16,16,4, (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__y), (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__cycles_completed))));
                    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__y_next 
                        = (0x0000ffffU & ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__y) 
                                          + VL_SHIFTRS_III(16,16,4, (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x), (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__cycles_completed))));
                    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__z_next 
                        = (0x0000ffffU & ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__z) 
                                          - (((0U == 
                                               (0x0000001fU 
                                                & ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__cycles_completed) 
                                                   << 4U)))
                                               ? 0U
                                               : (Vtop__ConstPool__CONST_h051babf7_0
                                                  [
                                                  (((IData)(0x0000000fU) 
                                                    + 
                                                    ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__cycles_completed) 
                                                     << 4U)) 
                                                   >> 5U)] 
                                                  << 
                                                  ((IData)(0x00000020U) 
                                                   - 
                                                   (0x0000001fU 
                                                    & ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__cycles_completed) 
                                                       << 4U))))) 
                                             | (Vtop__ConstPool__CONST_h051babf7_0
                                                [(0x07ffffffU 
                                                  & ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__cycles_completed) 
                                                     >> 1U))] 
                                                >> 
                                                (0x0000001fU 
                                                 & ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__cycles_completed) 
                                                    << 4U))))));
                }
            } else if ((3U == (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__opcode))) {
                if ((0x00008000U & (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__y))) {
                    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x_next 
                        = (0x0000ffffU & ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x) 
                                          - VL_SHIFTRS_III(16,16,4, (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__y), (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__cycles_completed))));
                    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__y_next 
                        = (0x0000ffffU & ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__y) 
                                          + VL_SHIFTRS_III(16,16,4, (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x), (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__cycles_completed))));
                    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__z_next 
                        = (0x0000ffffU & ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__z) 
                                          - (((0U == 
                                               (0x0000001fU 
                                                & ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__cycles_completed) 
                                                   << 4U)))
                                               ? 0U
                                               : (Vtop__ConstPool__CONST_h051babf7_0
                                                  [
                                                  (((IData)(0x0000000fU) 
                                                    + 
                                                    ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__cycles_completed) 
                                                     << 4U)) 
                                                   >> 5U)] 
                                                  << 
                                                  ((IData)(0x00000020U) 
                                                   - 
                                                   (0x0000001fU 
                                                    & ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__cycles_completed) 
                                                       << 4U))))) 
                                             | (Vtop__ConstPool__CONST_h051babf7_0
                                                [(0x07ffffffU 
                                                  & ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__cycles_completed) 
                                                     >> 1U))] 
                                                >> 
                                                (0x0000001fU 
                                                 & ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__cycles_completed) 
                                                    << 4U))))));
                } else {
                    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x_next 
                        = (0x0000ffffU & ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x) 
                                          + VL_SHIFTRS_III(16,16,4, (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__y), (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__cycles_completed))));
                    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__y_next 
                        = (0x0000ffffU & ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__y) 
                                          - VL_SHIFTRS_III(16,16,4, (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x), (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__cycles_completed))));
                    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__z_next 
                        = (0x0000ffffU & ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__z) 
                                          + (((0U == 
                                               (0x0000001fU 
                                                & ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__cycles_completed) 
                                                   << 4U)))
                                               ? 0U
                                               : (Vtop__ConstPool__CONST_h051babf7_0
                                                  [
                                                  (((IData)(0x0000000fU) 
                                                    + 
                                                    ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__cycles_completed) 
                                                     << 4U)) 
                                                   >> 5U)] 
                                                  << 
                                                  ((IData)(0x00000020U) 
                                                   - 
                                                   (0x0000001fU 
                                                    & ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__cycles_completed) 
                                                       << 4U))))) 
                                             | (Vtop__ConstPool__CONST_h051babf7_0
                                                [(0x07ffffffU 
                                                  & ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__cycles_completed) 
                                                     >> 1U))] 
                                                >> 
                                                (0x0000001fU 
                                                 & ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__cycles_completed) 
                                                    << 4U))))));
                }
            } else if ((0x00008000U & (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__y))) {
                vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x_next 
                    = (0x0000ffffU & ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x) 
                                      + VL_SHIFTRS_III(16,16,4, (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__y), (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__j))));
                vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__y_next 
                    = (0x0000ffffU & ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__y) 
                                      + VL_SHIFTRS_III(16,16,4, (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x), (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__j))));
                vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__z_next 
                    = (0x0000ffffU & ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__z) 
                                      - (((0U == (0x00000010U 
                                                  & (((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__j) 
                                                      - (IData)(1U)) 
                                                     << 4U)))
                                           ? 0U : (Vtop__ConstPool__CONST_h74ec95ef_0
                                                   [
                                                   (((IData)(0x0000000fU) 
                                                     + 
                                                     (0x000000f0U 
                                                      & (((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__j) 
                                                          - (IData)(1U)) 
                                                         << 4U))) 
                                                    >> 5U)] 
                                                   << 
                                                   ((IData)(0x00000020U) 
                                                    - 
                                                    (0x00000010U 
                                                     & (((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__j) 
                                                         - (IData)(1U)) 
                                                        << 4U))))) 
                                         | (Vtop__ConstPool__CONST_h74ec95ef_0
                                            [(7U & 
                                              (((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__j) 
                                                - (IData)(1U)) 
                                               >> 1U))] 
                                            >> (0x00000010U 
                                                & (((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__j) 
                                                    - (IData)(1U)) 
                                                   << 4U))))));
            } else {
                vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x_next 
                    = (0x0000ffffU & ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x) 
                                      - VL_SHIFTRS_III(16,16,4, (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__y), (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__j))));
                vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__y_next 
                    = (0x0000ffffU & ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__y) 
                                      - VL_SHIFTRS_III(16,16,4, (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x), (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__j))));
                vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__z_next 
                    = (0x0000ffffU & ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__z) 
                                      + (((0U == (0x00000010U 
                                                  & (((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__j) 
                                                      - (IData)(1U)) 
                                                     << 4U)))
                                           ? 0U : (Vtop__ConstPool__CONST_h74ec95ef_0
                                                   [
                                                   (((IData)(0x0000000fU) 
                                                     + 
                                                     (0x000000f0U 
                                                      & (((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__j) 
                                                          - (IData)(1U)) 
                                                         << 4U))) 
                                                    >> 5U)] 
                                                   << 
                                                   ((IData)(0x00000020U) 
                                                    - 
                                                    (0x00000010U 
                                                     & (((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__j) 
                                                         - (IData)(1U)) 
                                                        << 4U))))) 
                                         | (Vtop__ConstPool__CONST_h74ec95ef_0
                                            [(7U & 
                                              (((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__j) 
                                                - (IData)(1U)) 
                                               >> 1U))] 
                                            >> (0x00000010U 
                                                & (((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__j) 
                                                    - (IData)(1U)) 
                                                   << 4U))))));
            }
        } else if ((6U == (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__current_state))) {
            if ((0U == (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__opcode))) {
                vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__z_next 
                    = (0x0000ffffU & ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__z) 
                                      << (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__shift_q)));
            } else if ((2U == (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__opcode))) {
                if (vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__angleShift) {
                    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x_next 
                        = (0x0000ffffU & (- (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x)));
                    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__y_next 
                        = (0x0000ffffU & (- (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__y)));
                } else {
                    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x_next 
                        = (0x0000ffffU & (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x));
                    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__y_next 
                        = (0x0000ffffU & (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__y));
                }
            } else if ((1U == (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__opcode))) {
                vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x_next 
                    = (0x0000ffffU & ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__shift_right_q)
                                       ? ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x) 
                                          << ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__shift_q) 
                                              >> 1U))
                                       : VL_SHIFTRS_III(16,16,4, (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x), 
                                                        ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__shift_q) 
                                                         >> 1U))));
            }
        } else if ((4U == (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__current_state))) {
            if ((3U == (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__opcode))) {
                vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__postscale_product 
                    = (((((((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x) 
                            << 0x0000000dU) + ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x) 
                                               << 0x0000000bU)) 
                          - ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x) 
                             << 8U)) - ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x) 
                                        << 5U)) - ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x) 
                                                   << 3U)) 
                       + (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x));
                vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__postscale_result 
                    = VL_SHIFTRS_III(32,32,32, vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__postscale_product, 0x0000000eU);
                vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x_next 
                    = (VL_LTS_III(32, 0x00007fffU, vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__postscale_result)
                        ? 0x00007fffU : (VL_GTS_III(32, 0xffff8000U, vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__postscale_result)
                                          ? 0x00008000U
                                          : (0x0000ffffU 
                                             & vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__postscale_result)));
            } else if ((1U == (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__opcode))) {
                vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__postscale_product 
                    = (((((((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x) 
                            << 0x0000000eU) + ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x) 
                                               << 0x0000000cU)) 
                          - ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x) 
                             << 9U)) - ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x) 
                                        << 7U)) - ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x) 
                                                   << 6U)) 
                       + ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x) 
                          << 3U));
                vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__postscale_result 
                    = VL_SHIFTRS_III(32,32,32, vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__postscale_product, 0x0000000eU);
                vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x_next 
                    = (VL_LTS_III(32, 0x00007fffU, vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__postscale_result)
                        ? 0x00007fffU : (VL_GTS_III(32, 0xffff8000U, vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__postscale_result)
                                          ? 0x00008000U
                                          : (0x0000ffffU 
                                             & vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__postscale_result)));
            }
            vlSymsp->TOP__tt_um_cordic__DOT__fu.resp_result 
                = ((2U & (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__opcode))
                    ? ((1U & (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__opcode))
                        ? (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x_next)
                        : (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x))
                    : ((1U & (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__opcode))
                        ? (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x_next)
                        : (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__z)));
        }
    }
    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__start 
        = ((~ ((1U == (IData)(vlSymsp->TOP__tt_um_cordic__DOT__fu.req_opcode)) 
               & ((IData)(vlSymsp->TOP__tt_um_cordic__DOT__fu.req_op1) 
                  >> 0x0000000fU))) & (IData)(vlSymsp->TOP__tt_um_cordic__DOT__fu.req_valid));
    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__next_state 
        = Vtop__ConstPool__TABLE_h15b7204f_0[(((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__cycles_completed) 
                                               << 4U) 
                                              | (((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__start) 
                                                  << 3U) 
                                                 | (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__current_state)))];
}

bool Vtop___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___trigger_anySet__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        if (in[n]) {
            return (1U);
        }
        n = ((IData)(1U) + n);
    } while ((1U > n));
    return (0U);
}

void Vtop___024root___nba_comb__TOP__0(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_comb__TOP__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSymsp->TOP__tt_um_cordic__DOT__fu.resp_result = 0U;
    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x_next 
        = vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x;
    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__y_next 
        = vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__y;
    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__z_next 
        = vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__z;
    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__shift_next 
        = vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__shift_q;
    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__shift_right_next 
        = vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__shift_right_q;
    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__neg_next 
        = vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__neg_q;
    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__k = 0U;
    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__l = 0U;
    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__tooBig = 0U;
    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__ym = 0U;
    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__xp = 0U;
    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__angleShift = 0U;
    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__normalized 
        = vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x;
    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__postscale_product = 0U;
    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__postscale_result = 0U;
    if ((0U != (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__current_state))) {
        if ((1U == (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__current_state))) {
            if ((0U == (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__opcode))) {
                vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x_next 
                    = vlSymsp->TOP__tt_um_cordic__DOT__fu.req_op2;
                vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__y_next 
                    = vlSymsp->TOP__tt_um_cordic__DOT__fu.req_op1;
                vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__z_next = 0U;
            } else if ((2U == (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__opcode))) {
                vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x_next = 0x26ddU;
                vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__y_next = 0U;
                vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__z_next 
                    = vlSymsp->TOP__tt_um_cordic__DOT__fu.req_op2;
            } else {
                if ((3U == (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__opcode))) {
                    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x_next 
                        = vlSymsp->TOP__tt_um_cordic__DOT__fu.req_op1;
                    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__y_next 
                        = vlSymsp->TOP__tt_um_cordic__DOT__fu.req_op2;
                } else {
                    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x_next 
                        = vlSymsp->TOP__tt_um_cordic__DOT__fu.req_op1;
                    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__y_next 
                        = vlSymsp->TOP__tt_um_cordic__DOT__fu.req_op1;
                }
                vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__z_next = 0U;
            }
        } else if ((3U == (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__current_state))) {
            if ((0U == (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__opcode))) {
                vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__neg_next 
                    = (1U & ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x) 
                             >> 0x0fU));
                vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__ym 
                    = (0x0000ffffU & ((0x00008000U 
                                       & (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__y))
                                       ? (~ (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__y))
                                       : (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__y)));
                vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__xp 
                    = (0x0000ffffU & ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__neg_next)
                                       ? (- (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x))
                                       : (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x)));
                vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__k = 0U;
                vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__l = 0U;
                vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__unnamedblk1__DOT__i = 0U;
                while (VL_GTS_III(32, 0x0000000fU, vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__unnamedblk1__DOT__i)) {
                    if ((1U & ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__xp) 
                               >> (0x0000000fU & vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__unnamedblk1__DOT__i)))) {
                        vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__k 
                            = (0x0000000fU & vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__unnamedblk1__DOT__i);
                    }
                    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__unnamedblk1__DOT__i 
                        = ((IData)(1U) + vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__unnamedblk1__DOT__i);
                }
                vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__unnamedblk2__DOT__h = 0U;
                while (VL_GTS_III(32, 0x0000000fU, vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__unnamedblk2__DOT__h)) {
                    if ((1U & ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__y) 
                               >> (0x0000000fU & vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__unnamedblk2__DOT__h)))) {
                        vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__l 
                            = (0x0000000fU & vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__unnamedblk2__DOT__h);
                    }
                    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__unnamedblk2__DOT__h 
                        = ((IData)(1U) + vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__unnamedblk2__DOT__h);
                }
                if (VL_GTS_III(16, (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__ym), (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x))) {
                    if ((0x00004000U & (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__ym))) {
                        vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__y_next 
                            = (0x0000ffffU & VL_SHIFTRS_III(16,16,32, (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__y), 1U));
                        vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x_next 
                            = (0x0000ffffU & VL_SHIFTL_III(16,16,32, (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__xp), 
                                                           ((IData)(0x0000000eU) 
                                                            - (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__k))));
                        vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__shift_next 
                            = (0x0000000fU & ((IData)(0x0fU) 
                                              - (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__k)));
                    } else {
                        vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x_next 
                            = (0x0000ffffU & VL_SHIFTL_III(16,16,32, (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__xp), 
                                                           ((IData)(1U) 
                                                            + 
                                                            ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__l) 
                                                             - (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__k)))));
                        vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__shift_next 
                            = (0x0000000fU & ((IData)(1U) 
                                              + ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__l) 
                                                 - (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__k))));
                    }
                }
            } else if ((2U == (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__opcode))) {
                vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__angleShift 
                    = (VL_LTS_III(16, 0x6f92U, (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__z)) 
                       | VL_GTS_III(16, 0x906eU, (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__z)));
                if (vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__angleShift) {
                    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__z_next 
                        = (0x0000ffffU & ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__z) 
                                          + ((0x00008000U 
                                              & (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__z))
                                              ? 0x0000c910U
                                              : 0x000136f0U)));
                }
            } else if ((3U == (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__opcode))) {
                vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x_next 
                    = (0x0000ffffU & ((0x00008000U 
                                       & (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x))
                                       ? (- (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x))
                                       : (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x)));
                vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__y_next 
                    = (0x0000ffffU & ((0x00008000U 
                                       & (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__y))
                                       ? (- (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__y))
                                       : (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__y)));
            } else if ((1U == (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__opcode))) {
                vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__tooBig 
                    = (0U != (0x0000007fU & ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x) 
                                             >> 8U)));
                vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__normalized 
                    = vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x;
                if ((1U & ((((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__tooBig) 
                             | (IData)((0U == (0x00c0U 
                                               & (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x))))) 
                            & (~ (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__format))) 
                           | (IData)(((0U == (0x6000U 
                                              & (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x))) 
                                      & (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__format)))))) {
                    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__unnamedblk3__DOT__i = 0U;
                    while (VL_GTS_III(32, 0x0000000fU, vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__unnamedblk3__DOT__i)) {
                        if ((1U & ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x) 
                                   >> (0x0000000fU 
                                       & vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__unnamedblk3__DOT__i)))) {
                            vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__k 
                                = (0x0000000fU & vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__unnamedblk3__DOT__i);
                        }
                        vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__unnamedblk3__DOT__i 
                            = ((IData)(1U) + vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__unnamedblk3__DOT__i);
                    }
                    if (vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__format) {
                        vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__shift_next 
                            = (0x0000000fU & ((1U & (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__k))
                                               ? ((IData)(0x0000000dU) 
                                                  - (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__k))
                                               : ((IData)(0x0000000eU) 
                                                  - (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__k))));
                        vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__shift_right_next = 0U;
                        vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__normalized 
                            = (0x0000ffffU & ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x) 
                                              << (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__shift_next)));
                    } else if (vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__tooBig) {
                        vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__shift_next 
                            = (0x0000000fU & ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__k) 
                                              - ((1U 
                                                  & (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__k))
                                                  ? 7U
                                                  : 6U)));
                        vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__shift_right_next = 1U;
                        vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__normalized 
                            = (0x0000ffffU & VL_SHIFTRS_III(16,16,4, (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x), (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__shift_next)));
                    } else {
                        vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__shift_next 
                            = (0x0000000fU & (((1U 
                                                & (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__k))
                                                ? 7U
                                                : 6U) 
                                              - (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__k)));
                        vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__shift_right_next = 0U;
                        vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__normalized 
                            = (0x0000ffffU & ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x) 
                                              << (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__shift_next)));
                    }
                }
                if (vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__format) {
                    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x_next 
                        = (0x0000ffffU & ((IData)(0x1000U) 
                                          + (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__normalized)));
                    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__y_next 
                        = (0x0000ffffU & ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__normalized) 
                                          - (IData)(0x1000U)));
                } else {
                    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x_next 
                        = (0x0000ffffU & ((IData)(0x0020U) 
                                          + (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__normalized)));
                    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__y_next 
                        = (0x0000ffffU & ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__normalized) 
                                          - (IData)(0x0020U)));
                }
            }
        } else if ((2U == (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__current_state))) {
            if ((0U == (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__opcode))) {
                if ((0x00008000U & (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__y))) {
                    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__y_next 
                        = (0x0000ffffU & ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__y) 
                                          + VL_SHIFTRS_III(16,16,4, (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x), (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__cycles_completed))));
                    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__z_next 
                        = (0x0000ffffU & ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__z) 
                                          - (0x4000U 
                                             >> (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__cycles_completed))));
                } else {
                    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__y_next 
                        = (0x0000ffffU & ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__y) 
                                          - VL_SHIFTRS_III(16,16,4, (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x), (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__cycles_completed))));
                    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__z_next 
                        = (0x0000ffffU & ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__z) 
                                          + (0x4000U 
                                             >> (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__cycles_completed))));
                }
            } else if ((2U == (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__opcode))) {
                if ((0x00008000U & (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__z))) {
                    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x_next 
                        = (0x0000ffffU & ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x) 
                                          + VL_SHIFTRS_III(16,16,4, (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__y), (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__cycles_completed))));
                    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__y_next 
                        = (0x0000ffffU & ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__y) 
                                          - VL_SHIFTRS_III(16,16,4, (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x), (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__cycles_completed))));
                    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__z_next 
                        = (0x0000ffffU & ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__z) 
                                          + (((0U == 
                                               (0x0000001fU 
                                                & ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__cycles_completed) 
                                                   << 4U)))
                                               ? 0U
                                               : (Vtop__ConstPool__CONST_h051babf7_0
                                                  [
                                                  (((IData)(0x0000000fU) 
                                                    + 
                                                    ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__cycles_completed) 
                                                     << 4U)) 
                                                   >> 5U)] 
                                                  << 
                                                  ((IData)(0x00000020U) 
                                                   - 
                                                   (0x0000001fU 
                                                    & ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__cycles_completed) 
                                                       << 4U))))) 
                                             | (Vtop__ConstPool__CONST_h051babf7_0
                                                [(0x07ffffffU 
                                                  & ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__cycles_completed) 
                                                     >> 1U))] 
                                                >> 
                                                (0x0000001fU 
                                                 & ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__cycles_completed) 
                                                    << 4U))))));
                } else {
                    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x_next 
                        = (0x0000ffffU & ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x) 
                                          - VL_SHIFTRS_III(16,16,4, (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__y), (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__cycles_completed))));
                    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__y_next 
                        = (0x0000ffffU & ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__y) 
                                          + VL_SHIFTRS_III(16,16,4, (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x), (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__cycles_completed))));
                    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__z_next 
                        = (0x0000ffffU & ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__z) 
                                          - (((0U == 
                                               (0x0000001fU 
                                                & ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__cycles_completed) 
                                                   << 4U)))
                                               ? 0U
                                               : (Vtop__ConstPool__CONST_h051babf7_0
                                                  [
                                                  (((IData)(0x0000000fU) 
                                                    + 
                                                    ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__cycles_completed) 
                                                     << 4U)) 
                                                   >> 5U)] 
                                                  << 
                                                  ((IData)(0x00000020U) 
                                                   - 
                                                   (0x0000001fU 
                                                    & ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__cycles_completed) 
                                                       << 4U))))) 
                                             | (Vtop__ConstPool__CONST_h051babf7_0
                                                [(0x07ffffffU 
                                                  & ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__cycles_completed) 
                                                     >> 1U))] 
                                                >> 
                                                (0x0000001fU 
                                                 & ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__cycles_completed) 
                                                    << 4U))))));
                }
            } else if ((3U == (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__opcode))) {
                if ((0x00008000U & (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__y))) {
                    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x_next 
                        = (0x0000ffffU & ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x) 
                                          - VL_SHIFTRS_III(16,16,4, (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__y), (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__cycles_completed))));
                    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__y_next 
                        = (0x0000ffffU & ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__y) 
                                          + VL_SHIFTRS_III(16,16,4, (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x), (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__cycles_completed))));
                    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__z_next 
                        = (0x0000ffffU & ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__z) 
                                          - (((0U == 
                                               (0x0000001fU 
                                                & ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__cycles_completed) 
                                                   << 4U)))
                                               ? 0U
                                               : (Vtop__ConstPool__CONST_h051babf7_0
                                                  [
                                                  (((IData)(0x0000000fU) 
                                                    + 
                                                    ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__cycles_completed) 
                                                     << 4U)) 
                                                   >> 5U)] 
                                                  << 
                                                  ((IData)(0x00000020U) 
                                                   - 
                                                   (0x0000001fU 
                                                    & ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__cycles_completed) 
                                                       << 4U))))) 
                                             | (Vtop__ConstPool__CONST_h051babf7_0
                                                [(0x07ffffffU 
                                                  & ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__cycles_completed) 
                                                     >> 1U))] 
                                                >> 
                                                (0x0000001fU 
                                                 & ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__cycles_completed) 
                                                    << 4U))))));
                } else {
                    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x_next 
                        = (0x0000ffffU & ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x) 
                                          + VL_SHIFTRS_III(16,16,4, (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__y), (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__cycles_completed))));
                    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__y_next 
                        = (0x0000ffffU & ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__y) 
                                          - VL_SHIFTRS_III(16,16,4, (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x), (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__cycles_completed))));
                    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__z_next 
                        = (0x0000ffffU & ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__z) 
                                          + (((0U == 
                                               (0x0000001fU 
                                                & ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__cycles_completed) 
                                                   << 4U)))
                                               ? 0U
                                               : (Vtop__ConstPool__CONST_h051babf7_0
                                                  [
                                                  (((IData)(0x0000000fU) 
                                                    + 
                                                    ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__cycles_completed) 
                                                     << 4U)) 
                                                   >> 5U)] 
                                                  << 
                                                  ((IData)(0x00000020U) 
                                                   - 
                                                   (0x0000001fU 
                                                    & ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__cycles_completed) 
                                                       << 4U))))) 
                                             | (Vtop__ConstPool__CONST_h051babf7_0
                                                [(0x07ffffffU 
                                                  & ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__cycles_completed) 
                                                     >> 1U))] 
                                                >> 
                                                (0x0000001fU 
                                                 & ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__cycles_completed) 
                                                    << 4U))))));
                }
            } else if ((0x00008000U & (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__y))) {
                vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x_next 
                    = (0x0000ffffU & ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x) 
                                      + VL_SHIFTRS_III(16,16,4, (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__y), (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__j))));
                vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__y_next 
                    = (0x0000ffffU & ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__y) 
                                      + VL_SHIFTRS_III(16,16,4, (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x), (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__j))));
                vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__z_next 
                    = (0x0000ffffU & ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__z) 
                                      - (((0U == (0x00000010U 
                                                  & (((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__j) 
                                                      - (IData)(1U)) 
                                                     << 4U)))
                                           ? 0U : (Vtop__ConstPool__CONST_h74ec95ef_0
                                                   [
                                                   (((IData)(0x0000000fU) 
                                                     + 
                                                     (0x000000f0U 
                                                      & (((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__j) 
                                                          - (IData)(1U)) 
                                                         << 4U))) 
                                                    >> 5U)] 
                                                   << 
                                                   ((IData)(0x00000020U) 
                                                    - 
                                                    (0x00000010U 
                                                     & (((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__j) 
                                                         - (IData)(1U)) 
                                                        << 4U))))) 
                                         | (Vtop__ConstPool__CONST_h74ec95ef_0
                                            [(7U & 
                                              (((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__j) 
                                                - (IData)(1U)) 
                                               >> 1U))] 
                                            >> (0x00000010U 
                                                & (((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__j) 
                                                    - (IData)(1U)) 
                                                   << 4U))))));
            } else {
                vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x_next 
                    = (0x0000ffffU & ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x) 
                                      - VL_SHIFTRS_III(16,16,4, (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__y), (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__j))));
                vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__y_next 
                    = (0x0000ffffU & ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__y) 
                                      - VL_SHIFTRS_III(16,16,4, (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x), (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__j))));
                vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__z_next 
                    = (0x0000ffffU & ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__z) 
                                      + (((0U == (0x00000010U 
                                                  & (((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__j) 
                                                      - (IData)(1U)) 
                                                     << 4U)))
                                           ? 0U : (Vtop__ConstPool__CONST_h74ec95ef_0
                                                   [
                                                   (((IData)(0x0000000fU) 
                                                     + 
                                                     (0x000000f0U 
                                                      & (((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__j) 
                                                          - (IData)(1U)) 
                                                         << 4U))) 
                                                    >> 5U)] 
                                                   << 
                                                   ((IData)(0x00000020U) 
                                                    - 
                                                    (0x00000010U 
                                                     & (((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__j) 
                                                         - (IData)(1U)) 
                                                        << 4U))))) 
                                         | (Vtop__ConstPool__CONST_h74ec95ef_0
                                            [(7U & 
                                              (((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__j) 
                                                - (IData)(1U)) 
                                               >> 1U))] 
                                            >> (0x00000010U 
                                                & (((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__j) 
                                                    - (IData)(1U)) 
                                                   << 4U))))));
            }
        } else if ((6U == (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__current_state))) {
            if ((0U == (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__opcode))) {
                vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__z_next 
                    = (0x0000ffffU & ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__z) 
                                      << (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__shift_q)));
            } else if ((2U == (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__opcode))) {
                if (vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__angleShift) {
                    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x_next 
                        = (0x0000ffffU & (- (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x)));
                    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__y_next 
                        = (0x0000ffffU & (- (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__y)));
                } else {
                    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x_next 
                        = (0x0000ffffU & (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x));
                    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__y_next 
                        = (0x0000ffffU & (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__y));
                }
            } else if ((1U == (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__opcode))) {
                vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x_next 
                    = (0x0000ffffU & ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__shift_right_q)
                                       ? ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x) 
                                          << ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__shift_q) 
                                              >> 1U))
                                       : VL_SHIFTRS_III(16,16,4, (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x), 
                                                        ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__shift_q) 
                                                         >> 1U))));
            }
        } else if ((4U == (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__current_state))) {
            if ((3U == (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__opcode))) {
                vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__postscale_product 
                    = (((((((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x) 
                            << 0x0000000dU) + ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x) 
                                               << 0x0000000bU)) 
                          - ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x) 
                             << 8U)) - ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x) 
                                        << 5U)) - ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x) 
                                                   << 3U)) 
                       + (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x));
                vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__postscale_result 
                    = VL_SHIFTRS_III(32,32,32, vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__postscale_product, 0x0000000eU);
                vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x_next 
                    = (VL_LTS_III(32, 0x00007fffU, vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__postscale_result)
                        ? 0x00007fffU : (VL_GTS_III(32, 0xffff8000U, vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__postscale_result)
                                          ? 0x00008000U
                                          : (0x0000ffffU 
                                             & vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__postscale_result)));
            } else if ((1U == (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__opcode))) {
                vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__postscale_product 
                    = (((((((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x) 
                            << 0x0000000eU) + ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x) 
                                               << 0x0000000cU)) 
                          - ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x) 
                             << 9U)) - ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x) 
                                        << 7U)) - ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x) 
                                                   << 6U)) 
                       + ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x) 
                          << 3U));
                vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__postscale_result 
                    = VL_SHIFTRS_III(32,32,32, vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__postscale_product, 0x0000000eU);
                vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x_next 
                    = (VL_LTS_III(32, 0x00007fffU, vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__postscale_result)
                        ? 0x00007fffU : (VL_GTS_III(32, 0xffff8000U, vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__postscale_result)
                                          ? 0x00008000U
                                          : (0x0000ffffU 
                                             & vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__postscale_result)));
            }
            vlSymsp->TOP__tt_um_cordic__DOT__fu.resp_result 
                = ((2U & (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__opcode))
                    ? ((1U & (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__opcode))
                        ? (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x_next)
                        : (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x))
                    : ((1U & (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__opcode))
                        ? (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x_next)
                        : (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__z)));
        }
    }
    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__next_state 
        = Vtop__ConstPool__TABLE_h15b7204f_0[(((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__cycles_completed) 
                                               << 4U) 
                                              | (((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__start) 
                                                  << 3U) 
                                                 | (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__current_state)))];
}

void Vtop_fu_if___nba_sequent__TOP__tt_um_cordic__DOT__fu__0(Vtop_fu_if* vlSelf);

void Vtop___024root___eval_body__nba(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_body__nba\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((2ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_sequent__TOP__0
            CData/*1:0*/ __Vinline_0__nba_sequent__TOP__0___Vdly__tt_um_cordic__DOT__u_cordic__DOT__opcode;
            __Vinline_0__nba_sequent__TOP__0___Vdly__tt_um_cordic__DOT__u_cordic__DOT__opcode = 0;
            CData/*3:0*/ __Vinline_0__nba_sequent__TOP__0___Vdly__tt_um_cordic__DOT__u_cordic__DOT__cycles_completed;
            __Vinline_0__nba_sequent__TOP__0___Vdly__tt_um_cordic__DOT__u_cordic__DOT__cycles_completed = 0;
            CData/*0:0*/ __Vinline_0__nba_sequent__TOP__0___Vdly__tt_um_cordic__DOT__u_cordic__DOT__repeated;
            __Vinline_0__nba_sequent__TOP__0___Vdly__tt_um_cordic__DOT__u_cordic__DOT__repeated = 0;
            CData/*3:0*/ __Vinline_0__nba_sequent__TOP__0___Vdly__tt_um_cordic__DOT__u_cordic__DOT__j;
            __Vinline_0__nba_sequent__TOP__0___Vdly__tt_um_cordic__DOT__u_cordic__DOT__j = 0;
            __Vinline_0__nba_sequent__TOP__0___Vdly__tt_um_cordic__DOT__u_cordic__DOT__repeated 
                = vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__repeated;
            __Vinline_0__nba_sequent__TOP__0___Vdly__tt_um_cordic__DOT__u_cordic__DOT__opcode 
                = vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__opcode;
            __Vinline_0__nba_sequent__TOP__0___Vdly__tt_um_cordic__DOT__u_cordic__DOT__j 
                = vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__j;
            __Vinline_0__nba_sequent__TOP__0___Vdly__tt_um_cordic__DOT__u_cordic__DOT__cycles_completed 
                = vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__cycles_completed;
            if (vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__rst_n) {
                vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x 
                    = vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x_next;
                vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__y 
                    = vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__y_next;
                vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__z 
                    = vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__z_next;
                vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__shift_q 
                    = vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__shift_next;
                vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__shift_right_q 
                    = vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__shift_right_next;
                vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__neg_q 
                    = vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__neg_next;
                if (((0U == (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__current_state)) 
                     & (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__start))) {
                    __Vinline_0__nba_sequent__TOP__0___Vdly__tt_um_cordic__DOT__u_cordic__DOT__opcode 
                        = (3U & (IData)(vlSymsp->TOP__tt_um_cordic__DOT__fu.req_opcode));
                    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__format 
                        = vlSymsp->TOP__tt_um_cordic__DOT__fu.req_fmt;
                    __Vinline_0__nba_sequent__TOP__0___Vdly__tt_um_cordic__DOT__u_cordic__DOT__cycles_completed = 0U;
                    __Vinline_0__nba_sequent__TOP__0___Vdly__tt_um_cordic__DOT__u_cordic__DOT__repeated = 0U;
                    __Vinline_0__nba_sequent__TOP__0___Vdly__tt_um_cordic__DOT__u_cordic__DOT__j = 1U;
                    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__shift_q = 0U;
                    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__shift_right_q = 0U;
                    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__neg_q = 0U;
                } else if ((2U == (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__current_state))) {
                    __Vinline_0__nba_sequent__TOP__0___Vdly__tt_um_cordic__DOT__u_cordic__DOT__cycles_completed 
                        = (0x0000000fU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__cycles_completed)));
                    if ((IData)(((((4U == (6U & (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__cycles_completed))) 
                                   & (1U == (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__opcode))) 
                                  & (~ (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__repeated))) 
                                 & (~ (((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__cycles_completed) 
                                        >> 3U) ^ (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__cycles_completed)))))) {
                        __Vinline_0__nba_sequent__TOP__0___Vdly__tt_um_cordic__DOT__u_cordic__DOT__j 
                            = vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__j;
                        __Vinline_0__nba_sequent__TOP__0___Vdly__tt_um_cordic__DOT__u_cordic__DOT__repeated = 1U;
                    } else {
                        __Vinline_0__nba_sequent__TOP__0___Vdly__tt_um_cordic__DOT__u_cordic__DOT__j 
                            = (0x0000000fU & ((IData)(1U) 
                                              + (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__j)));
                        __Vinline_0__nba_sequent__TOP__0___Vdly__tt_um_cordic__DOT__u_cordic__DOT__repeated = 0U;
                    }
                }
                vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__current_state 
                    = vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__next_state;
            } else {
                vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x = 0U;
                vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__y = 0U;
                vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__z = 0U;
                __Vinline_0__nba_sequent__TOP__0___Vdly__tt_um_cordic__DOT__u_cordic__DOT__cycles_completed = 0U;
                __Vinline_0__nba_sequent__TOP__0___Vdly__tt_um_cordic__DOT__u_cordic__DOT__repeated = 0U;
                __Vinline_0__nba_sequent__TOP__0___Vdly__tt_um_cordic__DOT__u_cordic__DOT__j = 1U;
                vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__shift_q = 0U;
                vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__shift_right_q = 0U;
                __Vinline_0__nba_sequent__TOP__0___Vdly__tt_um_cordic__DOT__u_cordic__DOT__opcode = 0U;
                vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__neg_q = 0U;
                vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__current_state = 0U;
            }
            vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__repeated 
                = __Vinline_0__nba_sequent__TOP__0___Vdly__tt_um_cordic__DOT__u_cordic__DOT__repeated;
            vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__opcode 
                = __Vinline_0__nba_sequent__TOP__0___Vdly__tt_um_cordic__DOT__u_cordic__DOT__opcode;
            vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__j 
                = __Vinline_0__nba_sequent__TOP__0___Vdly__tt_um_cordic__DOT__u_cordic__DOT__j;
            vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__cycles_completed 
                = __Vinline_0__nba_sequent__TOP__0___Vdly__tt_um_cordic__DOT__u_cordic__DOT__cycles_completed;
        }
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_sequent__TOP__1
            if (vlSelfRef.tt_um_cordic__DOT__rst_n) {
                if ((((IData)(vlSelfRef.tt_um_cordic__DOT__ui_in) 
                      >> 1U) & (IData)(vlSymsp->TOP__tt_um_cordic__DOT__fu.req_ready))) {
                    vlSelfRef.tt_um_cordic__DOT__fmt_q 
                        = (1U & ((IData)(vlSelfRef.tt_um_cordic__DOT__ui_in) 
                                 >> 5U));
                }
                if ((1U & (IData)(vlSelfRef.tt_um_cordic__DOT__ui_in))) {
                    vlSelfRef.tt_um_cordic__DOT__result_valid = 0U;
                } else if (vlSymsp->TOP__tt_um_cordic__DOT__fu.resp_done) {
                    vlSelfRef.tt_um_cordic__DOT__result_valid = 1U;
                }
                if ((1U & (~ (IData)(vlSelfRef.tt_um_cordic__DOT__ui_in)))) {
                    if (vlSymsp->TOP__tt_um_cordic__DOT__fu.resp_done) {
                        vlSelfRef.tt_um_cordic__DOT__result_q 
                            = vlSymsp->TOP__tt_um_cordic__DOT__fu.resp_result;
                    }
                }
                if ((0x00000010U & (IData)(vlSelfRef.tt_um_cordic__DOT__ui_in))) {
                    if ((8U & (IData)(vlSelfRef.tt_um_cordic__DOT__ui_in))) {
                        vlSelfRef.tt_um_cordic__DOT__op2_q 
                            = ((4U & (IData)(vlSelfRef.tt_um_cordic__DOT__ui_in))
                                ? ((0x00ffU & (IData)(vlSelfRef.tt_um_cordic__DOT__op2_q)) 
                                   | ((IData)(vlSelfRef.tt_um_cordic__DOT__uio_in) 
                                      << 8U)) : ((0xff00U 
                                                  & (IData)(vlSelfRef.tt_um_cordic__DOT__op2_q)) 
                                                 | (IData)(vlSelfRef.tt_um_cordic__DOT__uio_in)));
                    }
                    if ((1U & (~ ((IData)(vlSelfRef.tt_um_cordic__DOT__ui_in) 
                                  >> 3U)))) {
                        vlSelfRef.tt_um_cordic__DOT__op1_q 
                            = ((4U & (IData)(vlSelfRef.tt_um_cordic__DOT__ui_in))
                                ? ((0x00ffU & (IData)(vlSelfRef.tt_um_cordic__DOT__op1_q)) 
                                   | ((IData)(vlSelfRef.tt_um_cordic__DOT__uio_in) 
                                      << 8U)) : ((0xff00U 
                                                  & (IData)(vlSelfRef.tt_um_cordic__DOT__op1_q)) 
                                                 | (IData)(vlSelfRef.tt_um_cordic__DOT__uio_in)));
                    }
                }
            } else {
                vlSelfRef.tt_um_cordic__DOT__fmt_q = 0U;
                vlSelfRef.tt_um_cordic__DOT__result_valid = 0U;
                vlSelfRef.tt_um_cordic__DOT__result_q = 0U;
                vlSelfRef.tt_um_cordic__DOT__op2_q = 0U;
                vlSelfRef.tt_um_cordic__DOT__op1_q = 0U;
            }
            vlSelfRef.tt_um_cordic__DOT__uio_oe = (0x000000ffU 
                                                   & (- (IData)((IData)(vlSelfRef.tt_um_cordic__DOT__result_valid))));
            vlSelfRef.tt_um_cordic__DOT__uo_out = (0x000000ffU 
                                                   & (IData)(vlSelfRef.tt_um_cordic__DOT__result_q));
            vlSelfRef.tt_um_cordic__DOT__uio_out = 
                (0x000000ffU & ((IData)(vlSelfRef.tt_um_cordic__DOT__result_q) 
                                >> 8U));
            vlSelfRef.uio_oe = vlSelfRef.tt_um_cordic__DOT__uio_oe;
            vlSelfRef.uo_out = vlSelfRef.tt_um_cordic__DOT__uo_out;
            vlSelfRef.uio_out = vlSelfRef.tt_um_cordic__DOT__uio_out;
        }
        Vtop_fu_if___nba_sequent__TOP__tt_um_cordic__DOT__fu__0((&vlSymsp->TOP__tt_um_cordic__DOT__fu));
        {
            // Inlined CFunc: _nba_sequent__TOP__2
            vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__start 
                = ((~ ((1U == (IData)(vlSymsp->TOP__tt_um_cordic__DOT__fu.req_opcode)) 
                       & ((IData)(vlSymsp->TOP__tt_um_cordic__DOT__fu.req_op1) 
                          >> 0x0000000fU))) & (IData)(vlSymsp->TOP__tt_um_cordic__DOT__fu.req_valid));
        }
    }
    if ((2ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_sequent__TOP__3
            vlSymsp->TOP__tt_um_cordic__DOT__fu.req_ready = 0U;
            if ((0U == (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__current_state))) {
                vlSymsp->TOP__tt_um_cordic__DOT__fu.req_ready = 1U;
            }
            vlSymsp->TOP__tt_um_cordic__DOT__fu.resp_done = 0U;
            if ((0U != (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__current_state))) {
                if ((1U != (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__current_state))) {
                    if ((3U != (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__current_state))) {
                        if ((2U != (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__current_state))) {
                            if ((6U != (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__current_state))) {
                                if ((4U == (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__current_state))) {
                                    vlSymsp->TOP__tt_um_cordic__DOT__fu.resp_done = 1U;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((3ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtop___024root___nba_comb__TOP__0(vlSelf);
    }
}

void Vtop___024root___trigger_orInto__act_vec_vec(VlUnpacked<QData/*63:0*/, 1> &out, const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___trigger_orInto__act_vec_vec\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = (out[n] | in[n]);
        n = ((IData)(1U) + n);
    } while ((0U >= n));
}

void Vtop___024root___trigger_clear__act(VlUnpacked<QData/*63:0*/, 1> &out) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___trigger_clear__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = 0ULL;
        n = ((IData)(1U) + n);
    } while ((1U > n));
}

#ifdef VL_DEBUG
void Vtop___024root___eval_debug_assertions(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_debug_assertions\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY(((vlSelfRef.ena & 0xfeU)))) {
        Verilated::overWidthError("ena");
    }
    if (VL_UNLIKELY(((vlSelfRef.clk & 0xfeU)))) {
        Verilated::overWidthError("clk");
    }
    if (VL_UNLIKELY(((vlSelfRef.rst_n & 0xfeU)))) {
        Verilated::overWidthError("rst_n");
    }
}
#endif  // VL_DEBUG
