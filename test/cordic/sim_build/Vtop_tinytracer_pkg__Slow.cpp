// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"

// Parameter definitions for Vtop_tinytracer_pkg
constexpr CData/*7:0*/ Vtop_tinytracer_pkg::RENDER_START;
constexpr CData/*7:0*/ Vtop_tinytracer_pkg::OBJ_START;
constexpr CData/*7:0*/ Vtop_tinytracer_pkg::PIXEL_START;
constexpr CData/*7:0*/ Vtop_tinytracer_pkg::DLE;
constexpr IData/*31:0*/ Vtop_tinytracer_pkg::ADDR_WIDTH;
constexpr IData/*31:0*/ Vtop_tinytracer_pkg::DATA_WIDTH;
constexpr IData/*31:0*/ Vtop_tinytracer_pkg::DIM_WIDTH;
constexpr IData/*31:0*/ Vtop_tinytracer_pkg::PIX_W;
constexpr IData/*31:0*/ Vtop_tinytracer_pkg::MAX_SPP;
constexpr IData/*31:0*/ Vtop_tinytracer_pkg::SPP_LOG2_W;
constexpr IData/*31:0*/ Vtop_tinytracer_pkg::COLOUR_DEPTH;
constexpr IData/*31:0*/ Vtop_tinytracer_pkg::SAMPLE_DEPTH;
constexpr IData/*31:0*/ Vtop_tinytracer_pkg::MAX_BOUNCES;
constexpr IData/*31:0*/ Vtop_tinytracer_pkg::WLEN;
constexpr IData/*31:0*/ Vtop_tinytracer_pkg::POS_FRAC;
constexpr IData/*31:0*/ Vtop_tinytracer_pkg::DIR_FRAC;
constexpr IData/*31:0*/ Vtop_tinytracer_pkg::MACRO_W;
constexpr IData/*31:0*/ Vtop_tinytracer_pkg::MACROOP_W;
constexpr IData/*31:0*/ Vtop_tinytracer_pkg::MICRO_W;
constexpr IData/*31:0*/ Vtop_tinytracer_pkg::MICROOP_W;
constexpr IData/*31:0*/ Vtop_tinytracer_pkg::SCRATCH_WORDS;
constexpr IData/*31:0*/ Vtop_tinytracer_pkg::HDR_WORDS;
constexpr IData/*31:0*/ Vtop_tinytracer_pkg::MAX_BV;
constexpr IData/*31:0*/ Vtop_tinytracer_pkg::BV_BASE;
constexpr IData/*31:0*/ Vtop_tinytracer_pkg::BV_WORDS;
constexpr IData/*31:0*/ Vtop_tinytracer_pkg::SPH_WORDS;
constexpr IData/*31:0*/ Vtop_tinytracer_pkg::TRI_WORDS;



Vtop_tinytracer_pkg::Vtop_tinytracer_pkg() = default;
Vtop_tinytracer_pkg::~Vtop_tinytracer_pkg() = default;

void Vtop_tinytracer_pkg::ctor(Vtop__Syms* symsp, const char* namep) {
    vlSymsp = symsp;
    vlNamep = strdup(Verilated::catName(vlSymsp->name(), namep));
    // Reset structure values
}

void Vtop_tinytracer_pkg::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

void Vtop_tinytracer_pkg::dtor() {
    VL_DO_DANGLING(std::free(const_cast<char*>(vlNamep)), vlNamep);
}
