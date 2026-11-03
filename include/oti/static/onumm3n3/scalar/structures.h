#ifndef OTI_ONUMM3N3_SCALAR_STRUCTURES_H
#define OTI_ONUMM3N3_SCALAR_STRUCTURES_H

// ----------------------------------------------------------------------------------------------------
// --------------------------------------      STRUCTURES        --------------------------------------
// ----------------------------------------------------------------------------------------------------

// Scalar
typedef struct {
  // Real
  coeff_t r;
  // Order 1
  coeff_t e1;
  coeff_t e2;
  coeff_t e3;
  // Order 2
  coeff_t e11;
  coeff_t e12;
  coeff_t e22;
  coeff_t e13;
  coeff_t e23;
  coeff_t e33;
  // Order 3
  coeff_t e111;
  coeff_t e112;
  coeff_t e122;
  coeff_t e222;
  coeff_t e113;
  coeff_t e123;
  coeff_t e223;
  coeff_t e133;
  coeff_t e233;
  coeff_t e333;
} onumm3n3_t;


// Layout checks (generated): no padding, coefficients in colex order (real part first).
// BEGIN LAYOUT ASSERTS
#include <stddef.h>
#ifndef OTI_STATIC_LAYOUT_ASSERT
#if defined(__cplusplus)
#define OTI_STATIC_LAYOUT_ASSERT(c, m) static_assert(c, m)
#else
#define OTI_STATIC_LAYOUT_ASSERT(c, m) _Static_assert(c, m)
#endif
#endif
OTI_STATIC_LAYOUT_ASSERT(sizeof(onumm3n3_t) == 20 * sizeof(coeff_t), "onumm3n3_t has padding");
OTI_STATIC_LAYOUT_ASSERT(offsetof(onumm3n3_t, r) == 0 * sizeof(coeff_t), "onumm3n3_t.r: colex 0");
OTI_STATIC_LAYOUT_ASSERT(offsetof(onumm3n3_t, e1) == 1 * sizeof(coeff_t), "onumm3n3_t.e1: colex 1");
OTI_STATIC_LAYOUT_ASSERT(offsetof(onumm3n3_t, e2) == 2 * sizeof(coeff_t), "onumm3n3_t.e2: colex 2");
OTI_STATIC_LAYOUT_ASSERT(offsetof(onumm3n3_t, e3) == 3 * sizeof(coeff_t), "onumm3n3_t.e3: colex 3");
OTI_STATIC_LAYOUT_ASSERT(offsetof(onumm3n3_t, e11) == 4 * sizeof(coeff_t), "onumm3n3_t.e11: colex 4");
OTI_STATIC_LAYOUT_ASSERT(offsetof(onumm3n3_t, e12) == 5 * sizeof(coeff_t), "onumm3n3_t.e12: colex 5");
OTI_STATIC_LAYOUT_ASSERT(offsetof(onumm3n3_t, e22) == 6 * sizeof(coeff_t), "onumm3n3_t.e22: colex 6");
OTI_STATIC_LAYOUT_ASSERT(offsetof(onumm3n3_t, e13) == 7 * sizeof(coeff_t), "onumm3n3_t.e13: colex 7");
OTI_STATIC_LAYOUT_ASSERT(offsetof(onumm3n3_t, e23) == 8 * sizeof(coeff_t), "onumm3n3_t.e23: colex 8");
OTI_STATIC_LAYOUT_ASSERT(offsetof(onumm3n3_t, e33) == 9 * sizeof(coeff_t), "onumm3n3_t.e33: colex 9");
OTI_STATIC_LAYOUT_ASSERT(offsetof(onumm3n3_t, e111) == 10 * sizeof(coeff_t), "onumm3n3_t.e111: colex 10");
OTI_STATIC_LAYOUT_ASSERT(offsetof(onumm3n3_t, e112) == 11 * sizeof(coeff_t), "onumm3n3_t.e112: colex 11");
OTI_STATIC_LAYOUT_ASSERT(offsetof(onumm3n3_t, e122) == 12 * sizeof(coeff_t), "onumm3n3_t.e122: colex 12");
OTI_STATIC_LAYOUT_ASSERT(offsetof(onumm3n3_t, e222) == 13 * sizeof(coeff_t), "onumm3n3_t.e222: colex 13");
OTI_STATIC_LAYOUT_ASSERT(offsetof(onumm3n3_t, e113) == 14 * sizeof(coeff_t), "onumm3n3_t.e113: colex 14");
OTI_STATIC_LAYOUT_ASSERT(offsetof(onumm3n3_t, e123) == 15 * sizeof(coeff_t), "onumm3n3_t.e123: colex 15");
OTI_STATIC_LAYOUT_ASSERT(offsetof(onumm3n3_t, e223) == 16 * sizeof(coeff_t), "onumm3n3_t.e223: colex 16");
OTI_STATIC_LAYOUT_ASSERT(offsetof(onumm3n3_t, e133) == 17 * sizeof(coeff_t), "onumm3n3_t.e133: colex 17");
OTI_STATIC_LAYOUT_ASSERT(offsetof(onumm3n3_t, e233) == 18 * sizeof(coeff_t), "onumm3n3_t.e233: colex 18");
OTI_STATIC_LAYOUT_ASSERT(offsetof(onumm3n3_t, e333) == 19 * sizeof(coeff_t), "onumm3n3_t.e333: colex 19");
// END LAYOUT ASSERTS


// ----------------------------------------------------------------------------------------------------
// -------------------------------------    END STRUCTURES      ---------------------------------------
// ----------------------------------------------------------------------------------------------------

#endif