// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP_TINYTRACER_PKG_H_
#define VERILATED_VTOP_TINYTRACER_PKG_H_  // guard

#include "verilated.h"


class Vtop__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtop_tinytracer_pkg final {
  public:

    // INTERNAL VARIABLES
    Vtop__Syms* vlSymsp;
    const char* vlNamep;

    // PARAMETERS
    static constexpr CData/*7:0*/ RENDER_START = 0U;
    static constexpr CData/*7:0*/ OBJ_START = 1U;
    static constexpr CData/*7:0*/ PIXEL_START = 0U;
    static constexpr CData/*7:0*/ DLE = 3U;
    static constexpr IData/*31:0*/ ADDR_WIDTH = 9U;
    static constexpr IData/*31:0*/ DATA_WIDTH = 0x00000010U;
    static constexpr IData/*31:0*/ DIM_WIDTH = 0x0000000cU;
    static constexpr IData/*31:0*/ PIX_W = 9U;
    static constexpr IData/*31:0*/ MAX_SPP = 0x00000020U;
    static constexpr IData/*31:0*/ SPP_LOG2_W = 3U;
    static constexpr IData/*31:0*/ COLOUR_DEPTH = 8U;
    static constexpr IData/*31:0*/ SAMPLE_DEPTH = 0x0000000cU;
    static constexpr IData/*31:0*/ MAX_BOUNCES = 8U;
    static constexpr IData/*31:0*/ WLEN = 0x00000010U;
    static constexpr IData/*31:0*/ POS_FRAC = 7U;
    static constexpr IData/*31:0*/ DIR_FRAC = 0x0000000eU;
    static constexpr IData/*31:0*/ MACRO_W = 0x00000066U;
    static constexpr IData/*31:0*/ MACROOP_W = 5U;
    static constexpr IData/*31:0*/ MICRO_W = 0x0000000dU;
    static constexpr IData/*31:0*/ MICROOP_W = 4U;
    static constexpr IData/*31:0*/ SCRATCH_WORDS = 7U;
    static constexpr IData/*31:0*/ HDR_WORDS = 0x00000011U;
    static constexpr IData/*31:0*/ MAX_BV = 0x00000010U;
    static constexpr IData/*31:0*/ BV_BASE = 0x00000011U;
    static constexpr IData/*31:0*/ BV_WORDS = 5U;
    static constexpr IData/*31:0*/ SPH_WORDS = 7U;
    static constexpr IData/*31:0*/ TRI_WORDS = 0x0000000cU;

    // CONSTRUCTORS
    Vtop_tinytracer_pkg();
    ~Vtop_tinytracer_pkg();
    void ctor(Vtop__Syms* symsp, const char* namep);
    void dtor();
    VL_UNCOPYABLE(Vtop_tinytracer_pkg);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
