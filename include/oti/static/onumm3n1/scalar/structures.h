#ifndef OTI_ONUMM3N1_SCALAR_STRUCTURES_H
#define OTI_ONUMM3N1_SCALAR_STRUCTURES_H

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
} onumm3n1_t;


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
OTI_STATIC_LAYOUT_ASSERT(sizeof(onumm3n1_t) == 4 * sizeof(coeff_t), "onumm3n1_t has padding");
OTI_STATIC_LAYOUT_ASSERT(offsetof(onumm3n1_t, r) == 0 * sizeof(coeff_t), "onumm3n1_t.r: colex 0");
OTI_STATIC_LAYOUT_ASSERT(offsetof(onumm3n1_t, e1) == 1 * sizeof(coeff_t), "onumm3n1_t.e1: colex 1");
OTI_STATIC_LAYOUT_ASSERT(offsetof(onumm3n1_t, e2) == 2 * sizeof(coeff_t), "onumm3n1_t.e2: colex 2");
OTI_STATIC_LAYOUT_ASSERT(offsetof(onumm3n1_t, e3) == 3 * sizeof(coeff_t), "onumm3n1_t.e3: colex 3");
// END LAYOUT ASSERTS


// ----------------------------------------------------------------------------------------------------
// -------------------------------------    END STRUCTURES      ---------------------------------------
// ----------------------------------------------------------------------------------------------------

#endif