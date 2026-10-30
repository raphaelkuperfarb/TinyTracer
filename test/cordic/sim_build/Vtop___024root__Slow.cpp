// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"

// Parameter definitions for Vtop___024root
constexpr CData/*2:0*/ Vtop___024root::tt_um_cordic__DOT__u_cordic__DOT__IDLE;
constexpr CData/*2:0*/ Vtop___024root::tt_um_cordic__DOT__u_cordic__DOT__INIT;
constexpr CData/*2:0*/ Vtop___024root::tt_um_cordic__DOT__u_cordic__DOT__NORMALIZE;
constexpr CData/*2:0*/ Vtop___024root::tt_um_cordic__DOT__u_cordic__DOT__LOOP;
constexpr CData/*2:0*/ Vtop___024root::tt_um_cordic__DOT__u_cordic__DOT__REVERT;
constexpr CData/*2:0*/ Vtop___024root::tt_um_cordic__DOT__u_cordic__DOT__POSTSCALE;
constexpr IData/*31:0*/ Vtop___024root::tt_um_cordic__DOT__u_cordic__DOT__ITER;
constexpr VlWide<8>/*255:0*/ Vtop___024root::tt_um_cordic__DOT__u_cordic__DOT__ATAN_LUT;
constexpr VlWide<8>/*255:0*/ Vtop___024root::tt_um_cordic__DOT__u_cordic__DOT__ATANH_LUT;


void Vtop___024root___ctor_var_reset(Vtop___024root* vlSelf);

Vtop___024root::Vtop___024root(Vtop__Syms* symsp, const char* namep)
 {
    vlSymsp = symsp;
    vlNamep = strdup(namep);
    // Reset structure values
    Vtop___024root___ctor_var_reset(this);
}

void Vtop___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vtop___024root::~Vtop___024root() {
    VL_DO_DANGLING(std::free(const_cast<char*>(vlNamep)), vlNamep);
}
