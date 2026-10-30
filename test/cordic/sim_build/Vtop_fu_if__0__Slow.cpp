// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"

VL_ATTR_COLD void Vtop_fu_if___ctor_var_reset(Vtop_fu_if* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtop_fu_if___ctor_var_reset\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->vlNamep);
    vlSelf->req_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12465084953323796564ull);
    vlSelf->req_op1 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 5614419182323345616ull);
    vlSelf->req_op2 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 13686981300916529877ull);
    vlSelf->req_opcode = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 159303299929919300ull);
    vlSelf->req_fmt = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10639996104448113400ull);
    vlSelf->req_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16539944981316001420ull);
    vlSelf->resp_done = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4695775032939892225ull);
    vlSelf->resp_result = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 12492749065350933615ull);
}
