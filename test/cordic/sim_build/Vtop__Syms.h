// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VTOP__SYMS_H_
#define VERILATED_VTOP__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vtop.h"

// INCLUDE MODULE CLASSES
#include "Vtop___024root.h"
#include "Vtop_tinytracer_pkg.h"
#include "Vtop_fu_if.h"

// DPI TYPES for DPI Export callbacks (Internal use)

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES) Vtop__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vtop* const __Vm_modelp;
    bool __Vm_activity = false;  ///< Used by trace routines to determine change occurred
    uint32_t __Vm_baseCode = 0;  ///< Used by trace routines when tracing multiple models
    VlDeleter __Vm_deleter;
    bool& __Vm_didInit;

    // MODULE INSTANCE STATE
    Vtop___024root                 TOP;
    Vtop_tinytracer_pkg            TOP__tinytracer_pkg;
    Vtop_fu_if                     TOP__tt_um_cordic__DOT__fu;

    // SCOPE NAMES
    VerilatedScope* __Vscopep_TOP;
    VerilatedScope* __Vscopep_tinytracer_pkg;
    VerilatedScope* __Vscopep_tt_um_cordic;
    VerilatedScope* __Vscopep_tt_um_cordic__fu;
    VerilatedScope* __Vscopep_tt_um_cordic__u_cordic;
    VerilatedScope* __Vscopep_tt_um_cordic__u_cordic__unnamedblk1;
    VerilatedScope* __Vscopep_tt_um_cordic__u_cordic__unnamedblk2;
    VerilatedScope* __Vscopep_tt_um_cordic__u_cordic__unnamedblk3;

    // SCOPE HIERARCHY
    VerilatedHierarchy __Vhier;

    // CONSTRUCTORS
    Vtop__Syms(VerilatedContext* contextp, const char* namep, Vtop* modelp);
    ~Vtop__Syms();

    // METHODS
    const char* name() const { return TOP.vlNamep; }
};

#endif  // guard
