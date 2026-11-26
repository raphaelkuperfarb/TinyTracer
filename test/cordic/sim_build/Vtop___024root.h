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
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        VL_IN8(clk,0,0);
        VL_IN8(rst_n,0,0);
        VL_IN8(ui_in,7,0);
        VL_OUT8(uo_out,7,0);
        VL_IN8(uio_in,7,0);
        VL_OUT8(uio_out,7,0);
        VL_OUT8(uio_oe,7,0);
        VL_IN8(ena,0,0);
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
        CData/*4:0*/ tt_um_cordic__DOT__u_cordic__DOT__j;
        CData/*4:0*/ tt_um_cordic__DOT__u_cordic__DOT__iteration;
        CData/*0:0*/ tt_um_cordic__DOT__u_cordic__DOT__x_subtract;
        CData/*0:0*/ tt_um_cordic__DOT__u_cordic__DOT__y_subtract;
        CData/*0:0*/ tt_um_cordic__DOT__u_cordic__DOT__z_subtract;
        CData/*0:0*/ tt_um_cordic__DOT__u_cordic__DOT__repeated;
        CData/*0:0*/ tt_um_cordic__DOT__u_cordic__DOT__start;
        CData/*3:0*/ tt_um_cordic__DOT__u_cordic__DOT__k;
        CData/*3:0*/ tt_um_cordic__DOT__u_cordic__DOT__l;
        CData/*3:0*/ tt_um_cordic__DOT__u_cordic__DOT__shift_diff;
        CData/*3:0*/ tt_um_cordic__DOT__u_cordic__DOT__shift_next;
        CData/*3:0*/ tt_um_cordic__DOT__u_cordic__DOT__shift_q;
        CData/*3:0*/ tt_um_cordic__DOT__u_cordic__DOT__shift_base;
        CData/*0:0*/ tt_um_cordic__DOT__u_cordic__DOT__div_shift;
        CData/*0:0*/ tt_um_cordic__DOT__u_cordic__DOT__sqrt_shift;
        CData/*3:0*/ tt_um_cordic__DOT__u_cordic__DOT__sqrt_amt;
        CData/*0:0*/ tt_um_cordic__DOT__u_cordic__DOT__shift_right_next;
        CData/*0:0*/ tt_um_cordic__DOT__u_cordic__DOT__shift_right_q;
        CData/*0:0*/ tt_um_cordic__DOT__u_cordic__DOT__tooBig;
        CData/*4:0*/ tt_um_cordic__DOT__u_cordic__DOT__sh_amt;
        CData/*0:0*/ tt_um_cordic__DOT__u_cordic__DOT__sh_left;
        CData/*0:0*/ tt_um_cordic__DOT__u_cordic__DOT__angle_shift;
        CData/*0:0*/ tt_um_cordic__DOT__u_cordic__DOT__angle_shift_q;
        CData/*1:0*/ tt_um_cordic__DOT__u_cordic__DOT__opcode;
        CData/*0:0*/ tt_um_cordic__DOT__u_cordic__DOT__format;
        CData/*0:0*/ __Vtrigprevexpr___TOP__tt_um_cordic__DOT__clk__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__tt_um_cordic__DOT__u_cordic__DOT__clk__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__tt_um_cordic__DOT__u_cordic__DOT__rst_n__0;
        SData/*15:0*/ tt_um_cordic__DOT__op1_q;
        SData/*15:0*/ tt_um_cordic__DOT__op2_q;
        SData/*15:0*/ tt_um_cordic__DOT__result_q;
        SData/*15:0*/ tt_um_cordic__DOT__u_cordic__DOT__postscale_result;
        IData/*19:0*/ tt_um_cordic__DOT__u_cordic__DOT__x;
        IData/*19:0*/ tt_um_cordic__DOT__u_cordic__DOT__y;
        IData/*19:0*/ tt_um_cordic__DOT__u_cordic__DOT__x_next;
        IData/*19:0*/ tt_um_cordic__DOT__u_cordic__DOT__y_next;
        IData/*16:0*/ tt_um_cordic__DOT__u_cordic__DOT__z;
        IData/*16:0*/ tt_um_cordic__DOT__u_cordic__DOT__z_next;
        IData/*19:0*/ tt_um_cordic__DOT__u_cordic__DOT__negative_x;
        IData/*19:0*/ tt_um_cordic__DOT__u_cordic__DOT__negative_y;
        IData/*19:0*/ tt_um_cordic__DOT__u_cordic__DOT__x_shifted;
    };
    struct {
        IData/*19:0*/ tt_um_cordic__DOT__u_cordic__DOT__y_shifted;
        IData/*16:0*/ tt_um_cordic__DOT__u_cordic__DOT__one_shifted;
        IData/*16:0*/ tt_um_cordic__DOT__u_cordic__DOT__z_sum;
        IData/*19:0*/ tt_um_cordic__DOT__u_cordic__DOT__ym;
        IData/*19:0*/ tt_um_cordic__DOT__u_cordic__DOT__xp;
        IData/*19:0*/ tt_um_cordic__DOT__u_cordic__DOT__normalized;
        IData/*19:0*/ tt_um_cordic__DOT__u_cordic__DOT__sh_in;
        IData/*19:0*/ tt_um_cordic__DOT__u_cordic__DOT__sh_pre;
        IData/*19:0*/ tt_um_cordic__DOT__u_cordic__DOT__sh_out;
        IData/*20:0*/ tt_um_cordic__DOT__u_cordic__DOT__sh_r;
        IData/*20:0*/ tt_um_cordic__DOT__u_cordic__DOT__postscale_x;
        IData/*31:0*/ tt_um_cordic__DOT__u_cordic__DOT__unnamedblk1__DOT__i;
        IData/*31:0*/ tt_um_cordic__DOT__u_cordic__DOT__unnamedblk2__DOT__i;
        IData/*31:0*/ tt_um_cordic__DOT__u_cordic__DOT__unnamedblk3__DOT__i;
        QData/*34:0*/ tt_um_cordic__DOT__u_cordic__DOT__postscale_39x;
        QData/*34:0*/ tt_um_cordic__DOT__u_cordic__DOT__postscale_product;
        VlUnpacked<QData/*63:0*/, 1> __VstlTriggered;
        VlUnpacked<QData/*63:0*/, 1> __VicoTriggered;
        VlUnpacked<QData/*63:0*/, 1> __VactTriggered;
        VlUnpacked<QData/*63:0*/, 1> __VnbaTriggered;
    };

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
    static constexpr IData/*31:0*/ tt_um_cordic__DOT__u_cordic__DOT__G = 4U;
    static constexpr IData/*31:0*/ tt_um_cordic__DOT__u_cordic__DOT__W = 0x00000014U;
    static constexpr VlWide<9>/*271:0*/ tt_um_cordic__DOT__u_cordic__DOT__ATAN_LUT = VlWide<9>{{
            0x76b26488, 0x7f587d70, 0x80007fd0, 0x80008000,
            0x80008000, 0x80008000, 0x80008000, 0x80008000,
            0x00000000
    }};
    static constexpr IData/*19:0*/ tt_um_cordic__DOT__u_cordic__DOT__SQRT_C_DIR = 0x00010000U;
    static constexpr IData/*19:0*/ tt_um_cordic__DOT__u_cordic__DOT__SQRT_C_POS = 0x00000200U;

    // CONSTRUCTORS
    Vtop___024root(Vtop__Syms* symsp, const char* namep);
    ~Vtop___024root();
    VL_UNCOPYABLE(Vtop___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
