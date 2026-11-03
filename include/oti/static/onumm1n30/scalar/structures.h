#ifndef OTI_ONUMM1N30_SCALAR_STRUCTURES_H
#define OTI_ONUMM1N30_SCALAR_STRUCTURES_H

// ----------------------------------------------------------------------------------------------------
// --------------------------------------      STRUCTURES        --------------------------------------
// ----------------------------------------------------------------------------------------------------

// Scalar
typedef struct {
  // Real
  coeff_t r;
  // Order 1
  coeff_t e1;
  // Order 2
  coeff_t e11;
  // Order 3
  coeff_t e111;
  // Order 4
  coeff_t e1111;
  // Order 5
  coeff_t e11111;
  // Order 6
  coeff_t e111111;
  // Order 7
  coeff_t e1111111;
  // Order 8
  coeff_t e11111111;
  // Order 9
  coeff_t e111111111;
  // Order 10
  coeff_t e1111111111;
  // Order 11
  coeff_t e11111111111;
  // Order 12
  coeff_t e111111111111;
  // Order 13
  coeff_t e1111111111111;
  // Order 14
  coeff_t e11111111111111;
  // Order 15
  coeff_t e111111111111111;
  // Order 16
  coeff_t e1111111111111111;
  // Order 17
  coeff_t e11111111111111111;
  // Order 18
  coeff_t e111111111111111111;
  // Order 19
  coeff_t e1111111111111111111;
  // Order 20
  coeff_t e11111111111111111111;
  // Order 21
  coeff_t e111111111111111111111;
  // Order 22
  coeff_t e1111111111111111111111;
  // Order 23
  coeff_t e11111111111111111111111;
  // Order 24
  coeff_t e111111111111111111111111;
  // Order 25
  coeff_t e1111111111111111111111111;
  // Order 26
  coeff_t e11111111111111111111111111;
  // Order 27
  coeff_t e111111111111111111111111111;
  // Order 28
  coeff_t e1111111111111111111111111111;
  // Order 29
  coeff_t e11111111111111111111111111111;
  // Order 30
  coeff_t e111111111111111111111111111111;
} onumm1n30_t;


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
OTI_STATIC_LAYOUT_ASSERT(sizeof(onumm1n30_t) == 31 * sizeof(coeff_t), "onumm1n30_t has padding");
OTI_STATIC_LAYOUT_ASSERT(offsetof(onumm1n30_t, r) == 0 * sizeof(coeff_t), "onumm1n30_t.r: colex 0");
OTI_STATIC_LAYOUT_ASSERT(offsetof(onumm1n30_t, e1) == 1 * sizeof(coeff_t), "onumm1n30_t.e1: colex 1");
OTI_STATIC_LAYOUT_ASSERT(offsetof(onumm1n30_t, e11) == 2 * sizeof(coeff_t), "onumm1n30_t.e11: colex 2");
OTI_STATIC_LAYOUT_ASSERT(offsetof(onumm1n30_t, e111) == 3 * sizeof(coeff_t), "onumm1n30_t.e111: colex 3");
OTI_STATIC_LAYOUT_ASSERT(offsetof(onumm1n30_t, e1111) == 4 * sizeof(coeff_t),
                         "onumm1n30_t.e1111: colex 4");
OTI_STATIC_LAYOUT_ASSERT(offsetof(onumm1n30_t, e11111) == 5 * sizeof(coeff_t),
                         "onumm1n30_t.e11111: colex 5");
OTI_STATIC_LAYOUT_ASSERT(offsetof(onumm1n30_t, e111111) == 6 * sizeof(coeff_t),
                         "onumm1n30_t.e111111: colex 6");
OTI_STATIC_LAYOUT_ASSERT(offsetof(onumm1n30_t, e1111111) == 7 * sizeof(coeff_t),
                         "onumm1n30_t.e1111111: colex 7");
OTI_STATIC_LAYOUT_ASSERT(offsetof(onumm1n30_t, e11111111) == 8 * sizeof(coeff_t),
                         "onumm1n30_t.e11111111: colex 8");
OTI_STATIC_LAYOUT_ASSERT(offsetof(onumm1n30_t, e111111111) == 9 * sizeof(coeff_t),
                         "onumm1n30_t.e111111111: colex 9");
OTI_STATIC_LAYOUT_ASSERT(offsetof(onumm1n30_t, e1111111111) == 10 * sizeof(coeff_t),
                         "onumm1n30_t.e1111111111: colex 10");
OTI_STATIC_LAYOUT_ASSERT(offsetof(onumm1n30_t, e11111111111) == 11 * sizeof(coeff_t),
                         "onumm1n30_t.e11111111111: colex 11");
OTI_STATIC_LAYOUT_ASSERT(offsetof(onumm1n30_t, e111111111111) == 12 * sizeof(coeff_t),
                         "onumm1n30_t.e111111111111: colex 12");
OTI_STATIC_LAYOUT_ASSERT(offsetof(onumm1n30_t, e1111111111111) == 13 * sizeof(coeff_t),
                         "onumm1n30_t.e1111111111111: colex 13");
OTI_STATIC_LAYOUT_ASSERT(offsetof(onumm1n30_t, e11111111111111) == 14 * sizeof(coeff_t),
                         "onumm1n30_t.e11111111111111: colex 14");
OTI_STATIC_LAYOUT_ASSERT(offsetof(onumm1n30_t, e111111111111111) == 15 * sizeof(coeff_t),
                         "onumm1n30_t.e111111111111111: colex 15");
OTI_STATIC_LAYOUT_ASSERT(offsetof(onumm1n30_t, e1111111111111111) == 16 * sizeof(coeff_t),
                         "onumm1n30_t.e1111111111111111: colex 16");
OTI_STATIC_LAYOUT_ASSERT(offsetof(onumm1n30_t, e11111111111111111) == 17 * sizeof(coeff_t),
                         "onumm1n30_t.e11111111111111111: colex 17");
OTI_STATIC_LAYOUT_ASSERT(offsetof(onumm1n30_t, e111111111111111111) == 18 * sizeof(coeff_t),
                         "onumm1n30_t.e111111111111111111: colex 18");
OTI_STATIC_LAYOUT_ASSERT(offsetof(onumm1n30_t, e1111111111111111111) == 19 * sizeof(coeff_t),
                         "onumm1n30_t.e1111111111111111111: colex 19");
OTI_STATIC_LAYOUT_ASSERT(offsetof(onumm1n30_t, e11111111111111111111) == 20 * sizeof(coeff_t),
                         "onumm1n30_t.e11111111111111111111: colex 20");
OTI_STATIC_LAYOUT_ASSERT(offsetof(onumm1n30_t, e111111111111111111111) == 21 * sizeof(coeff_t),
                         "onumm1n30_t.e111111111111111111111: colex 21");
OTI_STATIC_LAYOUT_ASSERT(offsetof(onumm1n30_t, e1111111111111111111111) == 22 * sizeof(coeff_t),
                         "onumm1n30_t.e1111111111111111111111: colex 22");
OTI_STATIC_LAYOUT_ASSERT(offsetof(onumm1n30_t, e11111111111111111111111) == 23 * sizeof(coeff_t),
                         "onumm1n30_t.e11111111111111111111111: colex 23");
OTI_STATIC_LAYOUT_ASSERT(offsetof(onumm1n30_t, e111111111111111111111111) == 24 * sizeof(coeff_t),
                         "onumm1n30_t.e111111111111111111111111: colex 24");
OTI_STATIC_LAYOUT_ASSERT(offsetof(onumm1n30_t, e1111111111111111111111111) == 25 * sizeof(coeff_t),
                         "onumm1n30_t.e1111111111111111111111111: colex 25");
OTI_STATIC_LAYOUT_ASSERT(offsetof(onumm1n30_t, e11111111111111111111111111) == 26 * sizeof(coeff_t),
                         "onumm1n30_t.e11111111111111111111111111: colex 26");
OTI_STATIC_LAYOUT_ASSERT(offsetof(onumm1n30_t, e111111111111111111111111111) == 27 * sizeof(coeff_t),
                         "onumm1n30_t.e111111111111111111111111111: colex 27");
OTI_STATIC_LAYOUT_ASSERT(offsetof(onumm1n30_t, e1111111111111111111111111111) == 28 * sizeof(coeff_t),
                         "onumm1n30_t.e1111111111111111111111111111: colex 28");
OTI_STATIC_LAYOUT_ASSERT(offsetof(onumm1n30_t, e11111111111111111111111111111) == 29 * sizeof(coeff_t),
                         "onumm1n30_t.e11111111111111111111111111111: colex 29");
OTI_STATIC_LAYOUT_ASSERT(offsetof(onumm1n30_t, e111111111111111111111111111111) == 30 * sizeof(coeff_t),
                         "onumm1n30_t.e111111111111111111111111111111: colex 30");
// END LAYOUT ASSERTS


// ----------------------------------------------------------------------------------------------------
// -------------------------------------    END STRUCTURES      ---------------------------------------
// ----------------------------------------------------------------------------------------------------

#endif