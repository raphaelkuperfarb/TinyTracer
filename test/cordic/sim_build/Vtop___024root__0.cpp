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
void Vtop_fu_if___ico_sequent__TOP__tt_um_cordic__DOT__fu__1(Vtop_fu_if* vlSelf);

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
                Vtop_fu_if___ico_sequent__TOP__tt_um_cordic__DOT__fu__1((&vlSymsp->TOP__tt_um_cordic__DOT__fu));
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

extern const VlUnpacked<CData/*2:0*/, 2048> Vtop__ConstPool__TABLE_h1973fb7a_0;
extern const VlWide<8>/*255:0*/ Vtop__ConstPool__CONST_h051babf7_0;

void Vtop___024root___ico_sequent__TOP__1(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ico_sequent__TOP__1\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    SData/*15:0*/ __VdfgRegularize_h6e95ff9d_0_0;
    __VdfgRegularize_h6e95ff9d_0_0 = 0;
    // Body
    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__sq_p 
        = (0x0000000fU & (((0x00004000U & (IData)(vlSymsp->TOP__tt_um_cordic__DOT__fu.req_op1))
                            ? 0x0eU : ((0x00002000U 
                                        & (IData)(vlSymsp->TOP__tt_um_cordic__DOT__fu.req_op1))
                                        ? 0x0dU : (
                                                   (0x00001000U 
                                                    & (IData)(vlSymsp->TOP__tt_um_cordic__DOT__fu.req_op1))
                                                    ? 0x0cU
                                                    : 
                                                   ((0x00000800U 
                                                     & (IData)(vlSymsp->TOP__tt_um_cordic__DOT__fu.req_op1))
                                                     ? 0x0bU
                                                     : 
                                                    ((0x00000400U 
                                                      & (IData)(vlSymsp->TOP__tt_um_cordic__DOT__fu.req_op1))
                                                      ? 0x0aU
                                                      : 
                                                     ((0x00000200U 
                                                       & (IData)(vlSymsp->TOP__tt_um_cordic__DOT__fu.req_op1))
                                                       ? 9U
                                                       : 
                                                      ((0x00000100U 
                                                        & (IData)(vlSymsp->TOP__tt_um_cordic__DOT__fu.req_op1))
                                                        ? 8U
                                                        : 
                                                       ((0x00000080U 
                                                         & (IData)(vlSymsp->TOP__tt_um_cordic__DOT__fu.req_op1))
                                                         ? 7U
                                                         : 
                                                        ((0x00000040U 
                                                          & (IData)(vlSymsp->TOP__tt_um_cordic__DOT__fu.req_op1))
                                                          ? 6U
                                                          : 
                                                         ((0x00000020U 
                                                           & (IData)(vlSymsp->TOP__tt_um_cordic__DOT__fu.req_op1))
                                                           ? 5U
                                                           : 
                                                          ((0x00000010U 
                                                            & (IData)(vlSymsp->TOP__tt_um_cordic__DOT__fu.req_op1))
                                                            ? 4U
                                                            : 
                                                           ((8U 
                                                             & (IData)(vlSymsp->TOP__tt_um_cordic__DOT__fu.req_op1))
                                                             ? 3U
                                                             : 
                                                            ((4U 
                                                              & (IData)(vlSymsp->TOP__tt_um_cordic__DOT__fu.req_op1))
                                                              ? 2U
                                                              : 
                                                             (1U 
                                                              & (- (IData)(
                                                                           (1U 
                                                                            & ((IData)(vlSymsp->TOP__tt_um_cordic__DOT__fu.req_op1) 
                                                                               >> 1U)))))))))))))))))) 
                          | (- (IData)((1U & ((IData)(vlSymsp->TOP__tt_um_cordic__DOT__fu.req_op1) 
                                              >> 0x0000000fU))))));
    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__cos_hi 
        = VL_LTS_III(16, 0x6488U, (IData)(vlSymsp->TOP__tt_um_cordic__DOT__fu.req_op2));
    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__cos_lo 
        = VL_GTS_III(16, 0x9b78U, (IData)(vlSymsp->TOP__tt_um_cordic__DOT__fu.req_op2));
    if ((0x00008000U & (IData)(vlSymsp->TOP__tt_um_cordic__DOT__fu.req_op2))) {
        vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__div_x 
            = (0x0000ffffU & (- (IData)(vlSymsp->TOP__tt_um_cordic__DOT__fu.req_op2)));
        vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__div_y 
            = (0x0000ffffU & (- (IData)(vlSymsp->TOP__tt_um_cordic__DOT__fu.req_op1)));
    } else {
        vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__div_x 
            = (0x0000ffffU & (IData)(vlSymsp->TOP__tt_um_cordic__DOT__fu.req_op2));
        vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__div_y 
            = (0x0000ffffU & (IData)(vlSymsp->TOP__tt_um_cordic__DOT__fu.req_op1));
    }
    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__start 
        = ((~ ((1U == (3U & (IData)(vlSymsp->TOP__tt_um_cordic__DOT__fu.req_opcode))) 
               & ((IData)(vlSymsp->TOP__tt_um_cordic__DOT__fu.req_op1) 
                  >> 0x0000000fU))) & (IData)(vlSymsp->TOP__tt_um_cordic__DOT__fu.req_valid));
    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__sq_f 
        = ((IData)(vlSymsp->TOP__tt_um_cordic__DOT__fu.req_fmt)
            ? 0x0eU : 7U);
    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__flip_next 
        = vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__flip;
    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__div_px 
        = (0x0000000fU & (((0x00004000U & (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__div_x))
                            ? 0x0eU : ((0x00002000U 
                                        & (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__div_x))
                                        ? 0x0dU : (
                                                   (0x00001000U 
                                                    & (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__div_x))
                                                    ? 0x0cU
                                                    : 
                                                   ((0x00000800U 
                                                     & (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__div_x))
                                                     ? 0x0bU
                                                     : 
                                                    ((0x00000400U 
                                                      & (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__div_x))
                                                      ? 0x0aU
                                                      : 
                                                     ((0x00000200U 
                                                       & (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__div_x))
                                                       ? 9U
                                                       : 
                                                      ((0x00000100U 
                                                        & (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__div_x))
                                                        ? 8U
                                                        : 
                                                       ((0x00000080U 
                                                         & (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__div_x))
                                                         ? 7U
                                                         : 
                                                        ((0x00000040U 
                                                          & (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__div_x))
                                                          ? 6U
                                                          : 
                                                         ((0x00000020U 
                                                           & (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__div_x))
                                                           ? 5U
                                                           : 
                                                          ((0x00000010U 
                                                            & (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__div_x))
                                                            ? 4U
                                                            : 
                                                           ((8U 
                                                             & (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__div_x))
                                                             ? 3U
                                                             : 
                                                            ((4U 
                                                              & (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__div_x))
                                                              ? 2U
                                                              : 
                                                             (1U 
                                                              & (- (IData)(
                                                                           (1U 
                                                                            & ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__div_x) 
                                                                               >> 1U)))))))))))))))))) 
                          | (- (IData)((1U & ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__div_x) 
                                              >> 0x0000000fU))))));
    __VdfgRegularize_h6e95ff9d_0_0 = (0x0000ffffU & 
                                      ((0x00008000U 
                                        & (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__div_y))
                                        ? (- (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__div_y))
                                        : (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__div_y)));
    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__next_state 
        = Vtop__ConstPool__TABLE_h1973fb7a_0[((((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__start) 
                                                << 0x0000000aU) 
                                               | ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__j) 
                                                  << 5U)) 
                                              | (((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__opcode) 
                                                  << 3U) 
                                                 | (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__current_state)))];
    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__sq_k 
        = (0x0000003fU & VL_SHIFTRS_III(6,6,32, (0x0000003fU 
                                                 & ((IData)(1U) 
                                                    + 
                                                    ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__sq_p) 
                                                     - (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__sq_f)))), 1U));
    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__div_py 
        = (0x0000000fU & (((0x00004000U & (IData)(__VdfgRegularize_h6e95ff9d_0_0))
                            ? 0x0eU : ((0x00002000U 
                                        & (IData)(__VdfgRegularize_h6e95ff9d_0_0))
                                        ? 0x0dU : (
                                                   (0x00001000U 
                                                    & (IData)(__VdfgRegularize_h6e95ff9d_0_0))
                                                    ? 0x0cU
                                                    : 
                                                   ((0x00000800U 
                                                     & (IData)(__VdfgRegularize_h6e95ff9d_0_0))
                                                     ? 0x0bU
                                                     : 
                                                    ((0x00000400U 
                                                      & (IData)(__VdfgRegularize_h6e95ff9d_0_0))
                                                      ? 0x0aU
                                                      : 
                                                     ((0x00000200U 
                                                       & (IData)(__VdfgRegularize_h6e95ff9d_0_0))
                                                       ? 9U
                                                       : 
                                                      ((0x00000100U 
                                                        & (IData)(__VdfgRegularize_h6e95ff9d_0_0))
                                                        ? 8U
                                                        : 
                                                       ((0x00000080U 
                                                         & (IData)(__VdfgRegularize_h6e95ff9d_0_0))
                                                         ? 7U
                                                         : 
                                                        ((0x00000040U 
                                                          & (IData)(__VdfgRegularize_h6e95ff9d_0_0))
                                                          ? 6U
                                                          : 
                                                         ((0x00000020U 
                                                           & (IData)(__VdfgRegularize_h6e95ff9d_0_0))
                                                           ? 5U
                                                           : 
                                                          ((0x00000010U 
                                                            & (IData)(__VdfgRegularize_h6e95ff9d_0_0))
                                                            ? 4U
                                                            : 
                                                           ((8U 
                                                             & (IData)(__VdfgRegularize_h6e95ff9d_0_0))
                                                             ? 3U
                                                             : 
                                                            ((4U 
                                                              & (IData)(__VdfgRegularize_h6e95ff9d_0_0))
                                                              ? 2U
                                                              : 
                                                             (1U 
                                                              & (- (IData)(
                                                                           (1U 
                                                                            & ((IData)(__VdfgRegularize_h6e95ff9d_0_0) 
                                                                               >> 1U)))))))))))))))))) 
                          | (- (IData)((1U & ((IData)(__VdfgRegularize_h6e95ff9d_0_0) 
                                              >> 0x0000000fU))))));
    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__sq_s 
        = (0x0000003fU & (((IData)(0x0eU) - (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__sq_f)) 
                          - ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__sq_k) 
                             << 1U)));
    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__div_k 
        = (0x0000001fU & (((IData)(1U) + ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__div_py) 
                                          - (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__div_px))) 
                          & (- (IData)(((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__div_py) 
                                        >= (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__div_px))))));
    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__sq_w 
        = (0x0000ffffU & (VL_LTES_III(32, 0U, VL_EXTENDS_II(32,6, (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__sq_s)))
                           ? VL_SHIFTL_III(16,16,6, (IData)(vlSymsp->TOP__tt_um_cordic__DOT__fu.req_op1), (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__sq_s))
                           : VL_SHIFTR_III(16,16,6, (IData)(vlSymsp->TOP__tt_um_cordic__DOT__fu.req_op1), 
                                           (0x0000003fU 
                                            & (- (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__sq_s))))));
    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__k_next 
        = vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__k;
    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x_next 
        = vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x;
    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__y_next 
        = vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__y;
    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__z_next 
        = vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__z;
    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__iteration = 0U;
    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__ym = 0U;
    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x_shifted = 0U;
    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__y_shifted = 0U;
    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x_subtract = 0U;
    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__y_subtract = 0U;
    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__z_subtract = 0U;
    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__one_shifted = 0U;
    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__z_sum = 0U;
    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__scale_input 
        = (((- (IData)((1U & ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x) 
                              >> 0x0fU)))) << 0x00000010U) 
           | (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x));
    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__scale_result 
        = vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__scale_input;
    if ((0U != (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__current_state))) {
        if ((1U != (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__current_state))) {
            if ((3U == (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__current_state))) {
                vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__flip_next = 0U;
                vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__k_next = 0U;
                if ((1U & (~ ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__opcode) 
                              >> 1U)))) {
                    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__k_next 
                        = ((1U & (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__opcode))
                            ? (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__sq_k)
                            : (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__div_k));
                }
                vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__z_next = 0U;
                if ((2U & (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__opcode))) {
                    if ((1U & (~ (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__opcode)))) {
                        vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__flip_next 
                            = ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__cos_hi) 
                               | (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__cos_lo));
                    }
                    if ((1U & (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__opcode))) {
                        vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x_next 
                            = (0x0000ffffU & ((0x00008000U 
                                               & (IData)(vlSymsp->TOP__tt_um_cordic__DOT__fu.req_op1))
                                               ? (- (IData)(vlSymsp->TOP__tt_um_cordic__DOT__fu.req_op1))
                                               : (IData)(vlSymsp->TOP__tt_um_cordic__DOT__fu.req_op1)));
                        vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__y_next 
                            = (0x0000ffffU & ((0x00008000U 
                                               & (IData)(vlSymsp->TOP__tt_um_cordic__DOT__fu.req_op2))
                                               ? (- (IData)(vlSymsp->TOP__tt_um_cordic__DOT__fu.req_op2))
                                               : (IData)(vlSymsp->TOP__tt_um_cordic__DOT__fu.req_op2)));
                    } else {
                        vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x_next 
                            = vlSymsp->TOP__tt_um_cordic__DOT__fu.req_op1;
                        vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__y_next = 0U;
                        vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__z_next 
                            = (0x0000ffffU & ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__cos_hi)
                                               ? ((IData)(vlSymsp->TOP__tt_um_cordic__DOT__fu.req_op2) 
                                                  - (IData)(0xc910U))
                                               : ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__cos_lo)
                                                   ? 
                                                  ((IData)(0xc910U) 
                                                   + (IData)(vlSymsp->TOP__tt_um_cordic__DOT__fu.req_op2))
                                                   : (IData)(vlSymsp->TOP__tt_um_cordic__DOT__fu.req_op2))));
                    }
                } else if ((1U & (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__opcode))) {
                    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x_next 
                        = (0x0000ffffU & ((IData)(0x1000U) 
                                          + (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__sq_w)));
                    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__y_next 
                        = (0x0000ffffU & ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__sq_w) 
                                          - (IData)(0x1000U)));
                } else {
                    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x_next 
                        = vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__div_x;
                    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__y_next 
                        = (0x0000ffffU & VL_SHIFTRS_III(16,16,5, (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__div_y), (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__div_k)));
                }
            } else if ((2U == (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__current_state))) {
                vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__iteration 
                    = (0x0000000fU & ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__j) 
                                      | (- (IData)(
                                                   (1U 
                                                    & ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__j) 
                                                       >> 4U))))));
                vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__ym 
                    = (0x0000ffffU & ((0x00008000U 
                                       & (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__y))
                                       ? (- (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__y))
                                       : (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__y)));
                vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x_shifted 
                    = (0x0000ffffU & VL_SHIFTRS_III(16,16,4, (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x), (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__iteration)));
                vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__y_shifted 
                    = (0x0000ffffU & VL_SHIFTRS_III(16,16,4, 
                                                    ((1U 
                                                      == (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__opcode))
                                                      ? (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__ym)
                                                      : (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__y)), (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__iteration)));
                if ((2U == (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__opcode))) {
                    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__y_subtract 
                        = (1U & ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__z) 
                                 >> 0x0fU));
                    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__z_subtract 
                        = (1U & (~ ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__z) 
                                    >> 0x0fU)));
                } else {
                    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__y_subtract 
                        = (1U & (~ ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__y) 
                                    >> 0x0fU)));
                    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__z_subtract 
                        = (1U & ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__y) 
                                 >> 0x0fU));
                }
                vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x_subtract 
                    = (1U & ((1U == (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__opcode)) 
                             | ((1U & (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__opcode))
                                 ? ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__y) 
                                    >> 0x0fU) : (~ 
                                                 ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__z) 
                                                  >> 0x0fU)))));
                vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x_next 
                    = (0x0000ffffU & ((0U == (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__opcode))
                                       ? (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x)
                                       : (((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x) 
                                           + ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__y_shifted) 
                                              ^ (- (IData)((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x_subtract))))) 
                                          + (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x_subtract))));
                vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__y_next 
                    = (0x0000ffffU & (((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__y) 
                                       + ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x_shifted) 
                                          ^ (- (IData)((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__y_subtract))))) 
                                      + (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__y_subtract)));
                vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__one_shifted 
                    = (0x4000U >> (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__iteration));
                vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__z_sum 
                    = (0x0000ffffU & (((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__z) 
                                       + (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__z_subtract)) 
                                      + (((2U & (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__opcode))
                                           ? (((0U 
                                                == 
                                                (0x0000001fU 
                                                 & ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__iteration) 
                                                    << 4U)))
                                                ? 0U
                                                : (Vtop__ConstPool__CONST_h051babf7_0
                                                   [
                                                   (((IData)(0x0000000fU) 
                                                     + 
                                                     ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__iteration) 
                                                      << 4U)) 
                                                    >> 5U)] 
                                                   << 
                                                   ((IData)(0x00000020U) 
                                                    - 
                                                    (0x0000001fU 
                                                     & ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__iteration) 
                                                        << 4U))))) 
                                              | (Vtop__ConstPool__CONST_h051babf7_0
                                                 [(0x07ffffffU 
                                                   & ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__iteration) 
                                                      >> 1U))] 
                                                 >> 
                                                 (0x0000001fU 
                                                  & ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__iteration) 
                                                     << 4U))))
                                           : (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__one_shifted)) 
                                         ^ (- (IData)((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__z_subtract))))));
                vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__z_next 
                    = vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__z_sum;
            } else if ((6U == (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__current_state))) {
                if ((0U != (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__k))) {
                    if ((0U == (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__opcode))) {
                        vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__z_next 
                            = (0x0000ffffU & VL_SHIFTL_III(16,16,6, (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__z), (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__k)));
                    } else if ((1U == (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__opcode))) {
                        vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x_next 
                            = (0x0000ffffU & (VL_LTS_III(32, 0U, 
                                                         VL_EXTENDS_II(32,6, (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__k)))
                                               ? VL_SHIFTL_III(16,16,6, (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x), (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__k))
                                               : VL_SHIFTRS_III(16,16,6, (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x), 
                                                                (0x0000003fU 
                                                                 & (- (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__k))))));
                    }
                }
            } else if ((4U == (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__current_state))) {
                if (((2U == (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__opcode)) 
                     | (3U == (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__opcode)))) {
                    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__scale_result 
                        = ((((VL_SHIFTRS_III(32,32,32, vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__scale_input, 1U) 
                              + VL_SHIFTRS_III(32,32,32, vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__scale_input, 3U)) 
                             - VL_SHIFTRS_III(32,32,32, vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__scale_input, 6U)) 
                            - VL_SHIFTRS_III(32,32,32, vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__scale_input, 9U)) 
                           - VL_SHIFTRS_III(32,32,32, vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__scale_input, 0x0000000dU));
                } else if ((1U == (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__opcode))) {
                    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__scale_result 
                        = (((((vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__scale_input 
                               + VL_SHIFTRS_III(32,32,32, vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__scale_input, 2U)) 
                              - VL_SHIFTRS_III(32,32,32, vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__scale_input, 5U)) 
                             - VL_SHIFTRS_III(32,32,32, vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__scale_input, 7U)) 
                            - VL_SHIFTRS_III(32,32,32, vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__scale_input, 8U)) 
                           + VL_SHIFTRS_III(32,32,32, vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__scale_input, 0x0000000bU));
                }
                vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x_next 
                    = (VL_LTS_III(32, 0x00007fffU, vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__scale_result)
                        ? 0x00007fffU : (VL_GTS_III(32, 0xffff8000U, vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__scale_result)
                                          ? 0x00008000U
                                          : (0x0000ffffU 
                                             & vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__scale_result)));
            }
        }
    }
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

void Vtop___024root___nba_sequent__TOP__2(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__2\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    SData/*15:0*/ __VdfgRegularize_h6e95ff9d_0_0;
    __VdfgRegularize_h6e95ff9d_0_0 = 0;
    // Body
    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__sq_f 
        = ((IData)(vlSymsp->TOP__tt_um_cordic__DOT__fu.req_fmt)
            ? 0x0eU : 7U);
    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__start 
        = ((~ ((1U == (3U & (IData)(vlSymsp->TOP__tt_um_cordic__DOT__fu.req_opcode))) 
               & ((IData)(vlSymsp->TOP__tt_um_cordic__DOT__fu.req_op1) 
                  >> 0x0000000fU))) & (IData)(vlSymsp->TOP__tt_um_cordic__DOT__fu.req_valid));
    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__sq_p 
        = (0x0000000fU & (((0x00004000U & (IData)(vlSymsp->TOP__tt_um_cordic__DOT__fu.req_op1))
                            ? 0x0eU : ((0x00002000U 
                                        & (IData)(vlSymsp->TOP__tt_um_cordic__DOT__fu.req_op1))
                                        ? 0x0dU : (
                                                   (0x00001000U 
                                                    & (IData)(vlSymsp->TOP__tt_um_cordic__DOT__fu.req_op1))
                                                    ? 0x0cU
                                                    : 
                                                   ((0x00000800U 
                                                     & (IData)(vlSymsp->TOP__tt_um_cordic__DOT__fu.req_op1))
                                                     ? 0x0bU
                                                     : 
                                                    ((0x00000400U 
                                                      & (IData)(vlSymsp->TOP__tt_um_cordic__DOT__fu.req_op1))
                                                      ? 0x0aU
                                                      : 
                                                     ((0x00000200U 
                                                       & (IData)(vlSymsp->TOP__tt_um_cordic__DOT__fu.req_op1))
                                                       ? 9U
                                                       : 
                                                      ((0x00000100U 
                                                        & (IData)(vlSymsp->TOP__tt_um_cordic__DOT__fu.req_op1))
                                                        ? 8U
                                                        : 
                                                       ((0x00000080U 
                                                         & (IData)(vlSymsp->TOP__tt_um_cordic__DOT__fu.req_op1))
                                                         ? 7U
                                                         : 
                                                        ((0x00000040U 
                                                          & (IData)(vlSymsp->TOP__tt_um_cordic__DOT__fu.req_op1))
                                                          ? 6U
                                                          : 
                                                         ((0x00000020U 
                                                           & (IData)(vlSymsp->TOP__tt_um_cordic__DOT__fu.req_op1))
                                                           ? 5U
                                                           : 
                                                          ((0x00000010U 
                                                            & (IData)(vlSymsp->TOP__tt_um_cordic__DOT__fu.req_op1))
                                                            ? 4U
                                                            : 
                                                           ((8U 
                                                             & (IData)(vlSymsp->TOP__tt_um_cordic__DOT__fu.req_op1))
                                                             ? 3U
                                                             : 
                                                            ((4U 
                                                              & (IData)(vlSymsp->TOP__tt_um_cordic__DOT__fu.req_op1))
                                                              ? 2U
                                                              : 
                                                             (1U 
                                                              & (- (IData)(
                                                                           (1U 
                                                                            & ((IData)(vlSymsp->TOP__tt_um_cordic__DOT__fu.req_op1) 
                                                                               >> 1U)))))))))))))))))) 
                          | (- (IData)((1U & ((IData)(vlSymsp->TOP__tt_um_cordic__DOT__fu.req_op1) 
                                              >> 0x0000000fU))))));
    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__cos_hi 
        = VL_LTS_III(16, 0x6488U, (IData)(vlSymsp->TOP__tt_um_cordic__DOT__fu.req_op2));
    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__cos_lo 
        = VL_GTS_III(16, 0x9b78U, (IData)(vlSymsp->TOP__tt_um_cordic__DOT__fu.req_op2));
    if ((0x00008000U & (IData)(vlSymsp->TOP__tt_um_cordic__DOT__fu.req_op2))) {
        vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__div_x 
            = (0x0000ffffU & (- (IData)(vlSymsp->TOP__tt_um_cordic__DOT__fu.req_op2)));
        vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__div_y 
            = (0x0000ffffU & (- (IData)(vlSymsp->TOP__tt_um_cordic__DOT__fu.req_op1)));
    } else {
        vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__div_x 
            = (0x0000ffffU & (IData)(vlSymsp->TOP__tt_um_cordic__DOT__fu.req_op2));
        vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__div_y 
            = (0x0000ffffU & (IData)(vlSymsp->TOP__tt_um_cordic__DOT__fu.req_op1));
    }
    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__sq_k 
        = (0x0000003fU & VL_SHIFTRS_III(6,6,32, (0x0000003fU 
                                                 & ((IData)(1U) 
                                                    + 
                                                    ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__sq_p) 
                                                     - (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__sq_f)))), 1U));
    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__div_px 
        = (0x0000000fU & (((0x00004000U & (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__div_x))
                            ? 0x0eU : ((0x00002000U 
                                        & (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__div_x))
                                        ? 0x0dU : (
                                                   (0x00001000U 
                                                    & (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__div_x))
                                                    ? 0x0cU
                                                    : 
                                                   ((0x00000800U 
                                                     & (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__div_x))
                                                     ? 0x0bU
                                                     : 
                                                    ((0x00000400U 
                                                      & (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__div_x))
                                                      ? 0x0aU
                                                      : 
                                                     ((0x00000200U 
                                                       & (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__div_x))
                                                       ? 9U
                                                       : 
                                                      ((0x00000100U 
                                                        & (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__div_x))
                                                        ? 8U
                                                        : 
                                                       ((0x00000080U 
                                                         & (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__div_x))
                                                         ? 7U
                                                         : 
                                                        ((0x00000040U 
                                                          & (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__div_x))
                                                          ? 6U
                                                          : 
                                                         ((0x00000020U 
                                                           & (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__div_x))
                                                           ? 5U
                                                           : 
                                                          ((0x00000010U 
                                                            & (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__div_x))
                                                            ? 4U
                                                            : 
                                                           ((8U 
                                                             & (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__div_x))
                                                             ? 3U
                                                             : 
                                                            ((4U 
                                                              & (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__div_x))
                                                              ? 2U
                                                              : 
                                                             (1U 
                                                              & (- (IData)(
                                                                           (1U 
                                                                            & ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__div_x) 
                                                                               >> 1U)))))))))))))))))) 
                          | (- (IData)((1U & ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__div_x) 
                                              >> 0x0000000fU))))));
    __VdfgRegularize_h6e95ff9d_0_0 = (0x0000ffffU & 
                                      ((0x00008000U 
                                        & (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__div_y))
                                        ? (- (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__div_y))
                                        : (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__div_y)));
    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__sq_s 
        = (0x0000003fU & (((IData)(0x0eU) - (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__sq_f)) 
                          - ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__sq_k) 
                             << 1U)));
    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__div_py 
        = (0x0000000fU & (((0x00004000U & (IData)(__VdfgRegularize_h6e95ff9d_0_0))
                            ? 0x0eU : ((0x00002000U 
                                        & (IData)(__VdfgRegularize_h6e95ff9d_0_0))
                                        ? 0x0dU : (
                                                   (0x00001000U 
                                                    & (IData)(__VdfgRegularize_h6e95ff9d_0_0))
                                                    ? 0x0cU
                                                    : 
                                                   ((0x00000800U 
                                                     & (IData)(__VdfgRegularize_h6e95ff9d_0_0))
                                                     ? 0x0bU
                                                     : 
                                                    ((0x00000400U 
                                                      & (IData)(__VdfgRegularize_h6e95ff9d_0_0))
                                                      ? 0x0aU
                                                      : 
                                                     ((0x00000200U 
                                                       & (IData)(__VdfgRegularize_h6e95ff9d_0_0))
                                                       ? 9U
                                                       : 
                                                      ((0x00000100U 
                                                        & (IData)(__VdfgRegularize_h6e95ff9d_0_0))
                                                        ? 8U
                                                        : 
                                                       ((0x00000080U 
                                                         & (IData)(__VdfgRegularize_h6e95ff9d_0_0))
                                                         ? 7U
                                                         : 
                                                        ((0x00000040U 
                                                          & (IData)(__VdfgRegularize_h6e95ff9d_0_0))
                                                          ? 6U
                                                          : 
                                                         ((0x00000020U 
                                                           & (IData)(__VdfgRegularize_h6e95ff9d_0_0))
                                                           ? 5U
                                                           : 
                                                          ((0x00000010U 
                                                            & (IData)(__VdfgRegularize_h6e95ff9d_0_0))
                                                            ? 4U
                                                            : 
                                                           ((8U 
                                                             & (IData)(__VdfgRegularize_h6e95ff9d_0_0))
                                                             ? 3U
                                                             : 
                                                            ((4U 
                                                              & (IData)(__VdfgRegularize_h6e95ff9d_0_0))
                                                              ? 2U
                                                              : 
                                                             (1U 
                                                              & (- (IData)(
                                                                           (1U 
                                                                            & ((IData)(__VdfgRegularize_h6e95ff9d_0_0) 
                                                                               >> 1U)))))))))))))))))) 
                          | (- (IData)((1U & ((IData)(__VdfgRegularize_h6e95ff9d_0_0) 
                                              >> 0x0000000fU))))));
    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__sq_w 
        = (0x0000ffffU & (VL_LTES_III(32, 0U, VL_EXTENDS_II(32,6, (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__sq_s)))
                           ? VL_SHIFTL_III(16,16,6, (IData)(vlSymsp->TOP__tt_um_cordic__DOT__fu.req_op1), (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__sq_s))
                           : VL_SHIFTR_III(16,16,6, (IData)(vlSymsp->TOP__tt_um_cordic__DOT__fu.req_op1), 
                                           (0x0000003fU 
                                            & (- (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__sq_s))))));
    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__div_k 
        = (0x0000001fU & (((IData)(1U) + ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__div_py) 
                                          - (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__div_px))) 
                          & (- (IData)(((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__div_py) 
                                        >= (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__div_px))))));
}

void Vtop___024root___nba_comb__TOP__0(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_comb__TOP__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__next_state 
        = Vtop__ConstPool__TABLE_h1973fb7a_0[((((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__start) 
                                                << 0x0000000aU) 
                                               | ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__j) 
                                                  << 5U)) 
                                              | (((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__opcode) 
                                                  << 3U) 
                                                 | (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__current_state)))];
    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__flip_next 
        = vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__flip;
    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__k_next 
        = vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__k;
    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x_next 
        = vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x;
    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__y_next 
        = vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__y;
    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__z_next 
        = vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__z;
    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__iteration = 0U;
    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__ym = 0U;
    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x_shifted = 0U;
    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__y_shifted = 0U;
    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x_subtract = 0U;
    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__y_subtract = 0U;
    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__z_subtract = 0U;
    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__one_shifted = 0U;
    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__z_sum = 0U;
    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__scale_input 
        = (((- (IData)((1U & ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x) 
                              >> 0x0fU)))) << 0x00000010U) 
           | (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x));
    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__scale_result 
        = vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__scale_input;
    if ((0U != (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__current_state))) {
        if ((1U != (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__current_state))) {
            if ((3U == (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__current_state))) {
                vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__flip_next = 0U;
                vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__k_next = 0U;
                if ((1U & (~ ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__opcode) 
                              >> 1U)))) {
                    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__k_next 
                        = ((1U & (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__opcode))
                            ? (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__sq_k)
                            : (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__div_k));
                }
                vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__z_next = 0U;
                if ((2U & (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__opcode))) {
                    if ((1U & (~ (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__opcode)))) {
                        vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__flip_next 
                            = ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__cos_hi) 
                               | (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__cos_lo));
                    }
                    if ((1U & (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__opcode))) {
                        vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x_next 
                            = (0x0000ffffU & ((0x00008000U 
                                               & (IData)(vlSymsp->TOP__tt_um_cordic__DOT__fu.req_op1))
                                               ? (- (IData)(vlSymsp->TOP__tt_um_cordic__DOT__fu.req_op1))
                                               : (IData)(vlSymsp->TOP__tt_um_cordic__DOT__fu.req_op1)));
                        vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__y_next 
                            = (0x0000ffffU & ((0x00008000U 
                                               & (IData)(vlSymsp->TOP__tt_um_cordic__DOT__fu.req_op2))
                                               ? (- (IData)(vlSymsp->TOP__tt_um_cordic__DOT__fu.req_op2))
                                               : (IData)(vlSymsp->TOP__tt_um_cordic__DOT__fu.req_op2)));
                    } else {
                        vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x_next 
                            = vlSymsp->TOP__tt_um_cordic__DOT__fu.req_op1;
                        vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__y_next = 0U;
                        vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__z_next 
                            = (0x0000ffffU & ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__cos_hi)
                                               ? ((IData)(vlSymsp->TOP__tt_um_cordic__DOT__fu.req_op2) 
                                                  - (IData)(0xc910U))
                                               : ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__cos_lo)
                                                   ? 
                                                  ((IData)(0xc910U) 
                                                   + (IData)(vlSymsp->TOP__tt_um_cordic__DOT__fu.req_op2))
                                                   : (IData)(vlSymsp->TOP__tt_um_cordic__DOT__fu.req_op2))));
                    }
                } else if ((1U & (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__opcode))) {
                    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x_next 
                        = (0x0000ffffU & ((IData)(0x1000U) 
                                          + (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__sq_w)));
                    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__y_next 
                        = (0x0000ffffU & ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__sq_w) 
                                          - (IData)(0x1000U)));
                } else {
                    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x_next 
                        = vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__div_x;
                    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__y_next 
                        = (0x0000ffffU & VL_SHIFTRS_III(16,16,5, (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__div_y), (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__div_k)));
                }
            } else if ((2U == (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__current_state))) {
                vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__iteration 
                    = (0x0000000fU & ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__j) 
                                      | (- (IData)(
                                                   (1U 
                                                    & ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__j) 
                                                       >> 4U))))));
                vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__ym 
                    = (0x0000ffffU & ((0x00008000U 
                                       & (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__y))
                                       ? (- (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__y))
                                       : (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__y)));
                vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x_shifted 
                    = (0x0000ffffU & VL_SHIFTRS_III(16,16,4, (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x), (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__iteration)));
                vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__y_shifted 
                    = (0x0000ffffU & VL_SHIFTRS_III(16,16,4, 
                                                    ((1U 
                                                      == (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__opcode))
                                                      ? (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__ym)
                                                      : (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__y)), (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__iteration)));
                if ((2U == (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__opcode))) {
                    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__y_subtract 
                        = (1U & ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__z) 
                                 >> 0x0fU));
                    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__z_subtract 
                        = (1U & (~ ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__z) 
                                    >> 0x0fU)));
                } else {
                    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__y_subtract 
                        = (1U & (~ ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__y) 
                                    >> 0x0fU)));
                    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__z_subtract 
                        = (1U & ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__y) 
                                 >> 0x0fU));
                }
                vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x_subtract 
                    = (1U & ((1U == (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__opcode)) 
                             | ((1U & (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__opcode))
                                 ? ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__y) 
                                    >> 0x0fU) : (~ 
                                                 ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__z) 
                                                  >> 0x0fU)))));
                vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x_next 
                    = (0x0000ffffU & ((0U == (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__opcode))
                                       ? (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x)
                                       : (((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x) 
                                           + ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__y_shifted) 
                                              ^ (- (IData)((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x_subtract))))) 
                                          + (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x_subtract))));
                vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__y_next 
                    = (0x0000ffffU & (((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__y) 
                                       + ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x_shifted) 
                                          ^ (- (IData)((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__y_subtract))))) 
                                      + (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__y_subtract)));
                vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__one_shifted 
                    = (0x4000U >> (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__iteration));
                vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__z_sum 
                    = (0x0000ffffU & (((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__z) 
                                       + (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__z_subtract)) 
                                      + (((2U & (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__opcode))
                                           ? (((0U 
                                                == 
                                                (0x0000001fU 
                                                 & ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__iteration) 
                                                    << 4U)))
                                                ? 0U
                                                : (Vtop__ConstPool__CONST_h051babf7_0
                                                   [
                                                   (((IData)(0x0000000fU) 
                                                     + 
                                                     ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__iteration) 
                                                      << 4U)) 
                                                    >> 5U)] 
                                                   << 
                                                   ((IData)(0x00000020U) 
                                                    - 
                                                    (0x0000001fU 
                                                     & ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__iteration) 
                                                        << 4U))))) 
                                              | (Vtop__ConstPool__CONST_h051babf7_0
                                                 [(0x07ffffffU 
                                                   & ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__iteration) 
                                                      >> 1U))] 
                                                 >> 
                                                 (0x0000001fU 
                                                  & ((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__iteration) 
                                                     << 4U))))
                                           : (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__one_shifted)) 
                                         ^ (- (IData)((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__z_subtract))))));
                vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__z_next 
                    = vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__z_sum;
            } else if ((6U == (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__current_state))) {
                if ((0U != (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__k))) {
                    if ((0U == (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__opcode))) {
                        vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__z_next 
                            = (0x0000ffffU & VL_SHIFTL_III(16,16,6, (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__z), (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__k)));
                    } else if ((1U == (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__opcode))) {
                        vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x_next 
                            = (0x0000ffffU & (VL_LTS_III(32, 0U, 
                                                         VL_EXTENDS_II(32,6, (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__k)))
                                               ? VL_SHIFTL_III(16,16,6, (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x), (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__k))
                                               : VL_SHIFTRS_III(16,16,6, (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x), 
                                                                (0x0000003fU 
                                                                 & (- (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__k))))));
                    }
                }
            } else if ((4U == (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__current_state))) {
                if (((2U == (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__opcode)) 
                     | (3U == (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__opcode)))) {
                    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__scale_result 
                        = ((((VL_SHIFTRS_III(32,32,32, vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__scale_input, 1U) 
                              + VL_SHIFTRS_III(32,32,32, vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__scale_input, 3U)) 
                             - VL_SHIFTRS_III(32,32,32, vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__scale_input, 6U)) 
                            - VL_SHIFTRS_III(32,32,32, vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__scale_input, 9U)) 
                           - VL_SHIFTRS_III(32,32,32, vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__scale_input, 0x0000000dU));
                } else if ((1U == (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__opcode))) {
                    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__scale_result 
                        = (((((vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__scale_input 
                               + VL_SHIFTRS_III(32,32,32, vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__scale_input, 2U)) 
                              - VL_SHIFTRS_III(32,32,32, vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__scale_input, 5U)) 
                             - VL_SHIFTRS_III(32,32,32, vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__scale_input, 7U)) 
                            - VL_SHIFTRS_III(32,32,32, vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__scale_input, 8U)) 
                           + VL_SHIFTRS_III(32,32,32, vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__scale_input, 0x0000000bU));
                }
                vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x_next 
                    = (VL_LTS_III(32, 0x00007fffU, vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__scale_result)
                        ? 0x00007fffU : (VL_GTS_III(32, 0xffff8000U, vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__scale_result)
                                          ? 0x00008000U
                                          : (0x0000ffffU 
                                             & vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__scale_result)));
            }
        }
    }
}

void Vtop_fu_if___nba_sequent__TOP__tt_um_cordic__DOT__fu__0(Vtop_fu_if* vlSelf);
void Vtop_fu_if___nba_sequent__TOP__tt_um_cordic__DOT__fu__1(Vtop_fu_if* vlSelf);

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
            CData/*0:0*/ __Vinline_0__nba_sequent__TOP__0___Vdly__tt_um_cordic__DOT__u_cordic__DOT__repeated;
            __Vinline_0__nba_sequent__TOP__0___Vdly__tt_um_cordic__DOT__u_cordic__DOT__repeated = 0;
            CData/*4:0*/ __Vinline_0__nba_sequent__TOP__0___Vdly__tt_um_cordic__DOT__u_cordic__DOT__j;
            __Vinline_0__nba_sequent__TOP__0___Vdly__tt_um_cordic__DOT__u_cordic__DOT__j = 0;
            __Vinline_0__nba_sequent__TOP__0___Vdly__tt_um_cordic__DOT__u_cordic__DOT__repeated 
                = vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__repeated;
            __Vinline_0__nba_sequent__TOP__0___Vdly__tt_um_cordic__DOT__u_cordic__DOT__j 
                = vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__j;
            __Vinline_0__nba_sequent__TOP__0___Vdly__tt_um_cordic__DOT__u_cordic__DOT__opcode 
                = vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__opcode;
            if (vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__rst_n) {
                if (((0U == (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__current_state)) 
                     & (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__start))) {
                    __Vinline_0__nba_sequent__TOP__0___Vdly__tt_um_cordic__DOT__u_cordic__DOT__opcode 
                        = (3U & (IData)(vlSymsp->TOP__tt_um_cordic__DOT__fu.req_opcode));
                    __Vinline_0__nba_sequent__TOP__0___Vdly__tt_um_cordic__DOT__u_cordic__DOT__repeated = 0U;
                    __Vinline_0__nba_sequent__TOP__0___Vdly__tt_um_cordic__DOT__u_cordic__DOT__j 
                        = (1U == (3U & (IData)(vlSymsp->TOP__tt_um_cordic__DOT__fu.req_opcode)));
                } else if ((2U == (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__current_state))) {
                    if ((IData)(((((4U == (6U & (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__j))) 
                                   & (1U == (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__opcode))) 
                                  & (~ (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__repeated))) 
                                 & (~ (((IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__j) 
                                        >> 3U) ^ (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__j)))))) {
                        __Vinline_0__nba_sequent__TOP__0___Vdly__tt_um_cordic__DOT__u_cordic__DOT__j 
                            = vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__j;
                        __Vinline_0__nba_sequent__TOP__0___Vdly__tt_um_cordic__DOT__u_cordic__DOT__repeated = 1U;
                    } else {
                        __Vinline_0__nba_sequent__TOP__0___Vdly__tt_um_cordic__DOT__u_cordic__DOT__j 
                            = (0x0000001fU & ((IData)(1U) 
                                              + (IData)(vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__j)));
                        __Vinline_0__nba_sequent__TOP__0___Vdly__tt_um_cordic__DOT__u_cordic__DOT__repeated = 0U;
                    }
                }
                vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__flip 
                    = vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__flip_next;
                vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__k 
                    = vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__k_next;
                vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x 
                    = vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__x_next;
                vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__y 
                    = vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__y_next;
                vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__z 
                    = vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__z_next;
                vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__current_state 
                    = vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__next_state;
            } else {
                __Vinline_0__nba_sequent__TOP__0___Vdly__tt_um_cordic__DOT__u_cordic__DOT__opcode = 0U;
                __Vinline_0__nba_sequent__TOP__0___Vdly__tt_um_cordic__DOT__u_cordic__DOT__repeated = 0U;
                __Vinline_0__nba_sequent__TOP__0___Vdly__tt_um_cordic__DOT__u_cordic__DOT__j = 0U;
                vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__current_state = 0U;
            }
            vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__repeated 
                = __Vinline_0__nba_sequent__TOP__0___Vdly__tt_um_cordic__DOT__u_cordic__DOT__repeated;
            vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__j 
                = __Vinline_0__nba_sequent__TOP__0___Vdly__tt_um_cordic__DOT__u_cordic__DOT__j;
            vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__opcode 
                = __Vinline_0__nba_sequent__TOP__0___Vdly__tt_um_cordic__DOT__u_cordic__DOT__opcode;
        }
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_sequent__TOP__1
            if (vlSelfRef.tt_um_cordic__DOT__rst_n) {
                if ((1U & (~ (IData)(vlSelfRef.tt_um_cordic__DOT__ui_in)))) {
                    if (vlSymsp->TOP__tt_um_cordic__DOT__fu.resp_done) {
                        vlSelfRef.tt_um_cordic__DOT__result_q 
                            = vlSymsp->TOP__tt_um_cordic__DOT__fu.resp_result;
                    }
                }
                if ((1U & (IData)(vlSelfRef.tt_um_cordic__DOT__ui_in))) {
                    vlSelfRef.tt_um_cordic__DOT__result_valid = 0U;
                } else if (vlSymsp->TOP__tt_um_cordic__DOT__fu.resp_done) {
                    vlSelfRef.tt_um_cordic__DOT__result_valid = 1U;
                }
                if ((((IData)(vlSelfRef.tt_um_cordic__DOT__ui_in) 
                      >> 1U) & (IData)(vlSymsp->TOP__tt_um_cordic__DOT__fu.req_ready))) {
                    vlSelfRef.tt_um_cordic__DOT__fmt_q 
                        = (1U & ((IData)(vlSelfRef.tt_um_cordic__DOT__ui_in) 
                                 >> 5U));
                }
                if ((0x00000010U & (IData)(vlSelfRef.tt_um_cordic__DOT__ui_in))) {
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
                    if ((8U & (IData)(vlSelfRef.tt_um_cordic__DOT__ui_in))) {
                        vlSelfRef.tt_um_cordic__DOT__op2_q 
                            = ((4U & (IData)(vlSelfRef.tt_um_cordic__DOT__ui_in))
                                ? ((0x00ffU & (IData)(vlSelfRef.tt_um_cordic__DOT__op2_q)) 
                                   | ((IData)(vlSelfRef.tt_um_cordic__DOT__uio_in) 
                                      << 8U)) : ((0xff00U 
                                                  & (IData)(vlSelfRef.tt_um_cordic__DOT__op2_q)) 
                                                 | (IData)(vlSelfRef.tt_um_cordic__DOT__uio_in)));
                    }
                }
            } else {
                vlSelfRef.tt_um_cordic__DOT__result_q = 0U;
                vlSelfRef.tt_um_cordic__DOT__result_valid = 0U;
                vlSelfRef.tt_um_cordic__DOT__fmt_q = 0U;
                vlSelfRef.tt_um_cordic__DOT__op1_q = 0U;
                vlSelfRef.tt_um_cordic__DOT__op2_q = 0U;
            }
            vlSelfRef.tt_um_cordic__DOT__uo_out = (0x000000ffU 
                                                   & (IData)(vlSelfRef.tt_um_cordic__DOT__result_q));
            vlSelfRef.tt_um_cordic__DOT__uio_out = 
                (0x000000ffU & ((IData)(vlSelfRef.tt_um_cordic__DOT__result_q) 
                                >> 8U));
            vlSelfRef.tt_um_cordic__DOT__uio_oe = (0x000000ffU 
                                                   & (- (IData)((IData)(vlSelfRef.tt_um_cordic__DOT__result_valid))));
            vlSelfRef.uo_out = vlSelfRef.tt_um_cordic__DOT__uo_out;
            vlSelfRef.uio_out = vlSelfRef.tt_um_cordic__DOT__uio_out;
            vlSelfRef.uio_oe = vlSelfRef.tt_um_cordic__DOT__uio_oe;
        }
        Vtop_fu_if___nba_sequent__TOP__tt_um_cordic__DOT__fu__0((&vlSymsp->TOP__tt_um_cordic__DOT__fu));
        Vtop___024root___nba_sequent__TOP__2(vlSelf);
    }
    if ((2ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtop_fu_if___nba_sequent__TOP__tt_um_cordic__DOT__fu__1((&vlSymsp->TOP__tt_um_cordic__DOT__fu));
    }
    if ((3ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtop___024root___nba_comb__TOP__0(vlSelf);
        Vtop_fu_if___ico_sequent__TOP__tt_um_cordic__DOT__fu__1((&vlSymsp->TOP__tt_um_cordic__DOT__fu));
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
