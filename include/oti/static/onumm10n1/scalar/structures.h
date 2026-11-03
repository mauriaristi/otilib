#ifndef OTI_ONUMM10N1_SCALAR_STRUCTURES_H
#define OTI_ONUMM10N1_SCALAR_STRUCTURES_H

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
  coeff_t e4;
  coeff_t e5;
  coeff_t e6;
  coeff_t e7;
  coeff_t e8;
  coeff_t e9;
  coeff_t eA;
} onumm10n1_t;


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
OTI_STATIC_LAYOUT_ASSERT(sizeof(onumm10n1_t) == 11 * sizeof(coeff_t), "onumm10n1_t has padding");
OTI_STATIC_LAYOUT_ASSERT(offsetof(onumm10n1_t, r) == 0 * sizeof(coeff_t), "onumm10n1_t.r: colex 0");
OTI_STATIC_LAYOUT_ASSERT(offsetof(onumm10n1_t, e1) == 1 * sizeof(coeff_t), "onumm10n1_t.e1: colex 1");
OTI_STATIC_LAYOUT_ASSERT(offsetof(onumm10n1_t, e2) == 2 * sizeof(coeff_t), "onumm10n1_t.e2: colex 2");
OTI_STATIC_LAYOUT_ASSERT(offsetof(onumm10n1_t, e3) == 3 * sizeof(coeff_t), "onumm10n1_t.e3: colex 3");
OTI_STATIC_LAYOUT_ASSERT(offsetof(onumm10n1_t, e4) == 4 * sizeof(coeff_t), "onumm10n1_t.e4: colex 4");
OTI_STATIC_LAYOUT_ASSERT(offsetof(onumm10n1_t, e5) == 5 * sizeof(coeff_t), "onumm10n1_t.e5: colex 5");
OTI_STATIC_LAYOUT_ASSERT(offsetof(onumm10n1_t, e6) == 6 * sizeof(coeff_t), "onumm10n1_t.e6: colex 6");
OTI_STATIC_LAYOUT_ASSERT(offsetof(onumm10n1_t, e7) == 7 * sizeof(coeff_t), "onumm10n1_t.e7: colex 7");
OTI_STATIC_LAYOUT_ASSERT(offsetof(onumm10n1_t, e8) == 8 * sizeof(coeff_t), "onumm10n1_t.e8: colex 8");
OTI_STATIC_LAYOUT_ASSERT(offsetof(onumm10n1_t, e9) == 9 * sizeof(coeff_t), "onumm10n1_t.e9: colex 9");
OTI_STATIC_LAYOUT_ASSERT(offsetof(onumm10n1_t, eA) == 10 * sizeof(coeff_t), "onumm10n1_t.eA: colex 10");
// END LAYOUT ASSERTS


// ----------------------------------------------------------------------------------------------------
// -------------------------------------    END STRUCTURES      ---------------------------------------
// ----------------------------------------------------------------------------------------------------

#endif