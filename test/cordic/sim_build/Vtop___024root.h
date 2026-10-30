// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP___024ROOT_H_
#define VERILATED_VTOP___024ROOT_H_  // guard

#include "verilated.h"
class Vtop_fu_if;
class Vtop_tinytracer_pkg;


class Vtop__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtop___024root final {
  public:
    // CELLS
    Vtop_tinytracer_pkg* __PVT__tinytracer_pkg;
    Vtop_fu_if* __PVT__tt_um_cordic__DOT__fu;

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(ui_in,7,0);
    VL_OUT8(uo_out,7,0);
    VL_IN8(uio_in,7,0);
    VL_OUT8(uio_out,7,0);
    VL_OUT8(uio_oe,7,0);
    VL_IN8(ena,0,0);
    VL_IN8(rst_n,0,0);
    CData/*7:0*/ tt_um_cordic__DOT__ui_in;
    CData/*7:0*/ tt_um_cordic__DOT__uo_out;
    CData/*7:0*/ tt_um_cordic__DOT__uio_in;
    CData/*7:0*/ tt_um_cordic__DOT__uio_out;
    CData/*7:0*/ tt_um_cordic__DOT__uio_oe;
    CData/*0:0*/ tt_um_cordic__DOT__ena;
    CData/*0:0*/ tt_um_cordic__DOT__clk;
    CData/*0:0*/ tt_um_cordic__DOT__rst_n;
    CData/*0:0*/ tt_um_cordic__DOT__result_valid;
    CData/*0:0*/ tt_um_cordic__DOT__fmt_q;
    CData/*0:0*/ tt_um_cordic__DOT___unused;
    CData/*0:0*/ tt_um_cordic__DOT__u_cordic__DOT__clk;
    CData/*0:0*/ tt_um_cordic__DOT__u_cordic__DOT__rst_n;
    CData/*2:0*/ tt_um_cordic__DOT__u_cordic__DOT__current_state;
    CData/*2:0*/ tt_um_cordic__DOT__u_cordic__DOT__next_state;
    CData/*3:0*/ tt_um_cordic__DOT__u_cordic__DOT__cycles_completed;
    CData/*3:0*/ tt_um_cordic__DOT__u_cordic__DOT__j;
    CData/*0:0*/ tt_um_cordic__DOT__u_cordic__DOT__repeated;
    CData/*0:0*/ tt_um_cordic__DOT__u_cordic__DOT__start;
    CData/*3:0*/ tt_um_cordic__DOT__u_cordic__DOT__k;
    CData/*3:0*/ tt_um_cordic__DOT__u_cordic__DOT__l;
    CData/*3:0*/ tt_um_cordic__DOT__u_cordic__DOT__shift_next;
    CData/*3:0*/ tt_um_cordic__DOT__u_cordic__DOT__shift_q;
    CData/*0:0*/ tt_um_cordic__DOT__u_cordic__DOT__shift_right_next;
    CData/*0:0*/ tt_um_cordic__DOT__u_cordic__DOT__shift_right_q;
    CData/*0:0*/ tt_um_cordic__DOT__u_cordic__DOT__tooBig;
    CData/*0:0*/ tt_um_cordic__DOT__u_cordic__DOT__neg_q;
    CData/*0:0*/ tt_um_cordic__DOT__u_cordic__DOT__neg_next;
    CData/*0:0*/ tt_um_cordic__DOT__u_cordic__DOT__angleShift;
    CData/*1:0*/ tt_um_cordic__DOT__u_cordic__DOT__opcode;
    CData/*0:0*/ tt_um_cordic__DOT__u_cordic__DOT__format;
    CData/*0:0*/ __Vtrigprevexpr___TOP__tt_um_cordic__DOT__clk__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__tt_um_cordic__DOT__u_cordic__DOT__clk__0;
    SData/*15:0*/ tt_um_cordic__DOT__op1_q;
    SData/*15:0*/ tt_um_cordic__DOT__op2_q;
    SData/*15:0*/ tt_um_cordic__DOT__result_q;
    SData/*15:0*/ tt_um_cordic__DOT__u_cordic__DOT__x;
    SData/*15:0*/ tt_um_cordic__DOT__u_cordic__DOT__y;
    SData/*15:0*/ tt_um_cordic__DOT__u_cordic__DOT__z;
    SData/*15:0*/ tt_um_cordic__DOT__u_cordic__DOT__x_next;
    SData/*15:0*/ tt_um_cordic__DOT__u_cordic__DOT__y_next;
    SData/*15:0*/ tt_um_cordic__DOT__u_cordic__DOT__z_next;
    SData/*15:0*/ tt_um_cordic__DOT__u_cordic__DOT__ym;
    SData/*15:0*/ tt_um_cordic__DOT__u_cordic__DOT__xp;
    SData/*15:0*/ tt_um_cordic__DOT__u_cordic__DOT__normalized;
    IData/*31:0*/ tt_um_cordic__DOT__u_cordic__DOT__postscale_product;
    IData/*31:0*/ tt_um_cordic__DOT__u_cordic__DOT__postscale_result;
    IData/*31:0*/ tt_um_cordic__DOT__u_cordic__DOT__unnamedblk1__DOT__i;
    IData/*31:0*/ tt_um_cordic__DOT__u_cordic__DOT__unnamedblk2__DOT__h;
    IData/*31:0*/ tt_um_cordic__DOT__u_cordic__DOT__unnamedblk3__DOT__i;
    VlUnpacked<QData/*63:0*/, 1> __VstlTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VicoTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VactTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vtop__Syms* vlSymsp;
    const char* vlNamep;

    // PARAMETERS
    static constexpr CData/*2:0*/ tt_um_cordic__DOT__u_cordic__DOT__IDLE = 0U;
    static constexpr CData/*2:0*/ tt_um_cordic__DOT__u_cordic__DOT__INIT = 1U;
    static constexpr CData/*2:0*/ tt_um_cordic__DOT__u_cordic__DOT__NORMALIZE = 3U;
    static constexpr CData/*2:0*/ tt_um_cordic__DOT__u_cordic__DOT__LOOP = 2U;
    static constexpr CData/*2:0*/ tt_um_cordic__DOT__u_cordic__DOT__REVERT = 6U;
    static constexpr CData/*2:0*/ tt_um_cordic__DOT__u_cordic__DOT__POSTSCALE = 4U;
    static constexpr IData/*31:0*/ tt_um_cordic__DOT__u_cordic__DOT__ITER = 0x00000010U;
    static constexpr VlWide<8>/*255:0*/ tt_um_cordic__DOT__u_cordic__DOT__ATAN_LUT = VlWide<8>{{
            0x1dac3244, 0x07f50fae, 0x020003ff, 0x00800100,
            0x00200040, 0x00080010, 0x00020004, 0x00010001
    }};
    static constexpr VlWide<8>/*255:0*/ tt_um_cordic__DOT__u_cordic__DOT__ATANH_LUT = VlWide<8>{{
            0x10592328, 0x0401080b, 0x01000200, 0x00400080,
            0x00100020, 0x00040008, 0x00010002, 0x00010001
    }};

    // CONSTRUCTORS
    Vtop___024root(Vtop__Syms* symsp, const char* namep);
    ~Vtop___024root();
    VL_UNCOPYABLE(Vtop___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
