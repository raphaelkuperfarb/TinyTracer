// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"

VL_ATTR_COLD void Vtop___024root___eval_static(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_static\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__tt_um_cordic__DOT__clk__0 
        = vlSelfRef.tt_um_cordic__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__tt_um_cordic__DOT__u_cordic__DOT__clk__0 
        = vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__clk;
}

VL_ATTR_COLD void Vtop___024root___eval_initial(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_initial\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vtop___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in);
void Vtop_fu_if___ico_sequent__TOP__tt_um_cordic__DOT__fu__0(Vtop_fu_if* vlSelf);
void Vtop___024root___ico_sequent__TOP__1(Vtop___024root* vlSelf);

VL_ATTR_COLD bool Vtop___024root___eval_stl(Vtop___024root* vlSelf, CData/*0:0*/ firstIteration) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_stl\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VstlExecute;
    // Body
    vlSelfRef.__VstlTriggered[0U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VstlTriggered[0U]) 
                                     | (IData)((IData)(firstIteration)));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtop___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
    }
#endif
    __VstlExecute = Vtop___024root___trigger_anySet__stl(vlSelfRef.__VstlTriggered);
    if (__VstlExecute) {
        {
            // Inlined CFunc: _eval_body__stl
            if ((1ULL & vlSelfRef.__VstlTriggered[0U])) {
                {
                    // Inlined CFunc: _stl_sequent__TOP__0
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
                    vlSelfRef.tt_um_cordic__DOT__uio_oe 
                        = (0x000000ffU & (- (IData)((IData)(vlSelfRef.tt_um_cordic__DOT__result_valid))));
                    vlSelfRef.tt_um_cordic__DOT__uo_out 
                        = (0x000000ffU & (IData)(vlSelfRef.tt_um_cordic__DOT__result_q));
                    vlSelfRef.tt_um_cordic__DOT__uio_out 
                        = (0x000000ffU & ((IData)(vlSelfRef.tt_um_cordic__DOT__result_q) 
                                          >> 8U));
                    vlSelfRef.tt_um_cordic__DOT__ena 
                        = vlSelfRef.ena;
                    vlSelfRef.tt_um_cordic__DOT__clk 
                        = vlSelfRef.clk;
                    vlSelfRef.tt_um_cordic__DOT__rst_n 
                        = vlSelfRef.rst_n;
                    vlSelfRef.tt_um_cordic__DOT__ui_in 
                        = vlSelfRef.ui_in;
                    vlSelfRef.uio_oe = vlSelfRef.tt_um_cordic__DOT__uio_oe;
                    vlSelfRef.uo_out = vlSelfRef.tt_um_cordic__DOT__uo_out;
                    vlSelfRef.uio_out = vlSelfRef.tt_um_cordic__DOT__uio_out;
                    vlSelfRef.tt_um_cordic__DOT___unused 
                        = vlSelfRef.tt_um_cordic__DOT__ena;
                    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__clk 
                        = vlSelfRef.tt_um_cordic__DOT__clk;
                    vlSelfRef.tt_um_cordic__DOT__u_cordic__DOT__rst_n 
                        = vlSelfRef.tt_um_cordic__DOT__rst_n;
                }
                Vtop_fu_if___ico_sequent__TOP__tt_um_cordic__DOT__fu__0((&vlSymsp->TOP__tt_um_cordic__DOT__fu));
                Vtop___024root___ico_sequent__TOP__1(vlSelf);
            }
        }
    }
    return (__VstlExecute);
}

VL_ATTR_COLD void Vtop___024root___eval_dump_triggers__stl(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_dump_triggers__stl\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
#ifdef VL_DEBUG
    Vtop___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
#endif
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__ico(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtop___024root___eval_dump_triggers__ico(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_dump_triggers__ico\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
#ifdef VL_DEBUG
    Vtop___024root___dump_triggers__ico(vlSelfRef.__VicoTriggered, "ico"s);
#endif
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtop___024root___eval_dump_triggers__act(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_dump_triggers__act\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
#ifdef VL_DEBUG
    Vtop___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
#endif
}

VL_ATTR_COLD void Vtop___024root___eval_dump_triggers__nba(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_dump_triggers__nba\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
#ifdef VL_DEBUG
    Vtop___024root___dump_triggers__act(vlSelfRef.__VnbaTriggered, "nba"s);
#endif
}

VL_ATTR_COLD void Vtop___024root___eval_dump_triggers__obs(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_dump_triggers__obs\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vtop___024root___eval_dump_triggers__react(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_dump_triggers__react\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vtop___024root___eval_final(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_final\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(Vtop___024root___trigger_anySet__stl(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD bool Vtop___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___trigger_anySet__stl\n"); );
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

bool Vtop___024root___trigger_anySet__ico(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__ico(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__ico\n"); );
    // Body
    if ((1U & (~ (IData)(Vtop___024root___trigger_anySet__ico(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

bool Vtop___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(Vtop___024root___trigger_anySet__act(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: @(posedge tt_um_cordic.clk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 1U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 1 is active: @(posedge tt_um_cordic.u_cordic.clk)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtop___024root___ctor_var_reset(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ctor_var_reset\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->vlNamep);
    vlSelf->ui_in = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 9967284984545053805ull);
    vlSelf->uo_out = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 4898547878985855477ull);
    vlSelf->uio_in = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 1424820951596298123ull);
    vlSelf->uio_out = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 16185529977779244833ull);
    vlSelf->uio_oe = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 3840965624738958755ull);
    vlSelf->ena = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4194194277674688301ull);
    vlSelf->clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16707436170211756652ull);
    vlSelf->rst_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1638864771569018232ull);
    vlSelf->tt_um_cordic__DOT__ui_in = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 7624900440399350560ull);
    vlSelf->tt_um_cordic__DOT__uo_out = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 2922987232033774335ull);
    vlSelf->tt_um_cordic__DOT__uio_in = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 3372074154827181557ull);
    vlSelf->tt_um_cordic__DOT__uio_out = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 18416355711291719670ull);
    vlSelf->tt_um_cordic__DOT__uio_oe = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 10279767369316163430ull);
    vlSelf->tt_um_cordic__DOT__ena = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6082031215022435480ull);
    vlSelf->tt_um_cordic__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4612374036344993491ull);
    vlSelf->tt_um_cordic__DOT__rst_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11820789110696554575ull);
    vlSelf->tt_um_cordic__DOT__op1_q = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 1107906212567251048ull);
    vlSelf->tt_um_cordic__DOT__op2_q = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 3115941913976437297ull);
    vlSelf->tt_um_cordic__DOT__result_q = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 11565124242005606257ull);
    vlSelf->tt_um_cordic__DOT__result_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9876371830022568263ull);
    vlSelf->tt_um_cordic__DOT__fmt_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9478934119092107416ull);
    vlSelf->tt_um_cordic__DOT___unused = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7965797871036143391ull);
    vlSelf->tt_um_cordic__DOT__u_cordic__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1874475173253791219ull);
    vlSelf->tt_um_cordic__DOT__u_cordic__DOT__rst_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1258009166149636775ull);
    vlSelf->tt_um_cordic__DOT__u_cordic__DOT__current_state = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 17708041275941484148ull);
    vlSelf->tt_um_cordic__DOT__u_cordic__DOT__next_state = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 10543459298800691203ull);
    vlSelf->tt_um_cordic__DOT__u_cordic__DOT__cycles_completed = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 14481487996179536884ull);
    vlSelf->tt_um_cordic__DOT__u_cordic__DOT__j = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 1151553726931524657ull);
    vlSelf->tt_um_cordic__DOT__u_cordic__DOT__x = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 7933591865833817168ull);
    vlSelf->tt_um_cordic__DOT__u_cordic__DOT__y = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 3601552095599930755ull);
    vlSelf->tt_um_cordic__DOT__u_cordic__DOT__z = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 2954860601910890148ull);
    vlSelf->tt_um_cordic__DOT__u_cordic__DOT__x_next = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 1950631406285961407ull);
    vlSelf->tt_um_cordic__DOT__u_cordic__DOT__y_next = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 5027848173128669451ull);
    vlSelf->tt_um_cordic__DOT__u_cordic__DOT__z_next = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 9989597036133135168ull);
    vlSelf->tt_um_cordic__DOT__u_cordic__DOT__repeated = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6886207335721660554ull);
    vlSelf->tt_um_cordic__DOT__u_cordic__DOT__start = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16246185796468183869ull);
    vlSelf->tt_um_cordic__DOT__u_cordic__DOT__k = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 16482008820845747630ull);
    vlSelf->tt_um_cordic__DOT__u_cordic__DOT__l = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 12479474956403288427ull);
    vlSelf->tt_um_cordic__DOT__u_cordic__DOT__shift_next = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 10233822421526907053ull);
    vlSelf->tt_um_cordic__DOT__u_cordic__DOT__shift_q = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 59510315533695709ull);
    vlSelf->tt_um_cordic__DOT__u_cordic__DOT__shift_right_next = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6017681376053944049ull);
    vlSelf->tt_um_cordic__DOT__u_cordic__DOT__shift_right_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17737484830892243271ull);
    vlSelf->tt_um_cordic__DOT__u_cordic__DOT__tooBig = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6509448985774599561ull);
    vlSelf->tt_um_cordic__DOT__u_cordic__DOT__ym = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 16122052536951590330ull);
    vlSelf->tt_um_cordic__DOT__u_cordic__DOT__xp = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 11050522268129064551ull);
    vlSelf->tt_um_cordic__DOT__u_cordic__DOT__normalized = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 6514038028619737159ull);
    vlSelf->tt_um_cordic__DOT__u_cordic__DOT__postscale_product = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11194689768884128369ull);
    vlSelf->tt_um_cordic__DOT__u_cordic__DOT__postscale_result = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16291967078371936877ull);
    vlSelf->tt_um_cordic__DOT__u_cordic__DOT__neg_q = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12296453982232481284ull);
    vlSelf->tt_um_cordic__DOT__u_cordic__DOT__neg_next = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18024015959719737360ull);
    vlSelf->tt_um_cordic__DOT__u_cordic__DOT__angleShift = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12657475298094687866ull);
    vlSelf->tt_um_cordic__DOT__u_cordic__DOT__opcode = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 8125033404194173609ull);
    vlSelf->tt_um_cordic__DOT__u_cordic__DOT__format = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 655247897360982197ull);
    vlSelf->tt_um_cordic__DOT__u_cordic__DOT__unnamedblk1__DOT__i = 0;
    vlSelf->tt_um_cordic__DOT__u_cordic__DOT__unnamedblk2__DOT__h = 0;
    vlSelf->tt_um_cordic__DOT__u_cordic__DOT__unnamedblk3__DOT__i = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VstlTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VicoTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VactTriggered[__Vi0] = 0;
    }
    vlSelf->__Vtrigprevexpr___TOP__tt_um_cordic__DOT__clk__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__tt_um_cordic__DOT__u_cordic__DOT__clk__0 = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VnbaTriggered[__Vi0] = 0;
    }
}
