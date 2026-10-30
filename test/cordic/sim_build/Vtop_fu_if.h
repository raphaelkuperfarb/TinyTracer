// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP_FU_IF_H_
#define VERILATED_VTOP_FU_IF_H_  // guard

#include "verilated.h"


class Vtop__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtop_fu_if final {
  public:

    // DESIGN SPECIFIC STATE
    CData/*0:0*/ req_valid;
    CData/*2:0*/ req_opcode;
    CData/*0:0*/ req_fmt;
    CData/*0:0*/ req_ready;
    CData/*0:0*/ resp_done;
    SData/*15:0*/ req_op1;
    SData/*15:0*/ req_op2;
    SData/*15:0*/ resp_result;

    // INTERNAL VARIABLES
    Vtop__Syms* vlSymsp;
    const char* vlNamep;

    // CONSTRUCTORS
    Vtop_fu_if();
    ~Vtop_fu_if();
    void ctor(Vtop__Syms* symsp, const char* namep);
    void dtor();
    VL_UNCOPYABLE(Vtop_fu_if);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
