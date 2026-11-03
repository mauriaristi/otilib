#ifndef OTI_ONUMM2N4_SCALAR_STRUCTURES_H
#define OTI_ONUMM2N4_SCALAR_STRUCTURES_H

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
  // Order 2
  coeff_t e11;
  coeff_t e12;
  coeff_t e22;
  // Order 3
  coeff_t e111;
  coeff_t e112;
  coeff_t e122;
  coeff_t e222;
  // Order 4
  coeff_t e1111;
  coeff_t e1112;
  coeff_t e1122;
  coeff_t e1222;
  coeff_t e2222;
} onumm2n4_t;


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
OTI_STATIC_LAYOUT_ASSERT(sizeof(onumm2n4_t) == 15 * sizeof(coeff_t), "onumm2n4_t has padding");
OTI_STATIC_LAYOUT_ASSERT(offsetof(onumm2n4_t, r) == 0 * sizeof(coeff_t), "onumm2n4_t.r: colex 0");
OTI_STATIC_LAYOUT_ASSERT(offsetof(onumm2n4_t, e1) == 1 * sizeof(coeff_t), "onumm2n4_t.e1: colex 1");
OTI_STATIC_LAYOUT_ASSERT(offsetof(onumm2n4_t, e2) == 2 * sizeof(coeff_t), "onumm2n4_t.e2: colex 2");
OTI_STATIC_LAYOUT_ASSERT(offsetof(onumm2n4_t, e11) == 3 * sizeof(coeff_t), "onumm2n4_t.e11: colex 3");
OTI_STATIC_LAYOUT_ASSERT(offsetof(onumm2n4_t, e12) == 4 * sizeof(coeff_t), "onumm2n4_t.e12: colex 4");
OTI_STATIC_LAYOUT_ASSERT(offsetof(onumm2n4_t, e22) == 5 * sizeof(coeff_t), "onumm2n4_t.e22: colex 5");
OTI_STATIC_LAYOUT_ASSERT(offsetof(onumm2n4_t, e111) == 6 * sizeof(coeff_t), "onumm2n4_t.e111: colex 6");
OTI_STATIC_LAYOUT_ASSERT(offsetof(onumm2n4_t, e112) == 7 * sizeof(coeff_t), "onumm2n4_t.e112: colex 7");
OTI_STATIC_LAYOUT_ASSERT(offsetof(onumm2n4_t, e122) == 8 * sizeof(coeff_t), "onumm2n4_t.e122: colex 8");
OTI_STATIC_LAYOUT_ASSERT(offsetof(onumm2n4_t, e222) == 9 * sizeof(coeff_t), "onumm2n4_t.e222: colex 9");
OTI_STATIC_LAYOUT_ASSERT(offsetof(onumm2n4_t, e1111) == 10 * sizeof(coeff_t),
                         "onumm2n4_t.e1111: colex 10");
OTI_STATIC_LAYOUT_ASSERT(offsetof(onumm2n4_t, e1112) == 11 * sizeof(coeff_t),
                         "onumm2n4_t.e1112: colex 11");
OTI_STATIC_LAYOUT_ASSERT(offsetof(onumm2n4_t, e1122) == 12 * sizeof(coeff_t),
                         "onumm2n4_t.e1122: colex 12");
OTI_STATIC_LAYOUT_ASSERT(offsetof(onumm2n4_t, e1222) == 13 * sizeof(coeff_t),
                         "onumm2n4_t.e1222: colex 13");
OTI_STATIC_LAYOUT_ASSERT(offsetof(onumm2n4_t, e2222) == 14 * sizeof(coeff_t),
                         "onumm2n4_t.e2222: colex 14");
// END LAYOUT ASSERTS


// ----------------------------------------------------------------------------------------------------
// -------------------------------------    END STRUCTURES      ---------------------------------------
// ----------------------------------------------------------------------------------------------------

#endif