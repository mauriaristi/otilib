#ifndef OTI_ONUMM10N2_SCALAR_STRUCTURES_H
#define OTI_ONUMM10N2_SCALAR_STRUCTURES_H

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
  // Order 2
  coeff_t e11;
  coeff_t e12;
  coeff_t e22;
  coeff_t e13;
  coeff_t e23;
  coeff_t e33;
  coeff_t e14;
  coeff_t e24;
  coeff_t e34;
  coeff_t e44;
  coeff_t e15;
  coeff_t e25;
  coeff_t e35;
  coeff_t e45;
  coeff_t e55;
  coeff_t e16;
  coeff_t e26;
  coeff_t e36;
  coeff_t e46;
  coeff_t e56;
  coeff_t e66;
  coeff_t e17;
  coeff_t e27;
  coeff_t e37;
  coeff_t e47;
  coeff_t e57;
  coeff_t e67;
  coeff_t e77;
  coeff_t e18;
  coeff_t e28;
  coeff_t e38;
  coeff_t e48;
  coeff_t e58;
  coeff_t e68;
  coeff_t e78;
  coeff_t e88;
  coeff_t e19;
  coeff_t e29;
  coeff_t e39;
  coeff_t e49;
  coeff_t e59;
  coeff_t e69;
  coeff_t e79;
  coeff_t e89;
  coeff_t e99;
  coeff_t e1A;
  coeff_t e2A;
  coeff_t e3A;
  coeff_t e4A;
  coeff_t e5A;
  coeff_t e6A;
  coeff_t e7A;
  coeff_t e8A;
  coeff_t e9A;
  coeff_t eAA;
} onumm10n2_t;


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
OTI_STATIC_LAYOUT_ASSERT(sizeof(onumm10n2_t) == 66 * sizeof(coeff_t), "onumm10n2_t has padding");
OTI_STATIC_LAYOUT_ASSERT(offsetof(onumm10n2_t, r) == 0 * sizeof(coeff_t), "onumm10n2_t.r: colex 0");
OTI_STATIC_LAYOUT_ASSERT(offsetof(onumm10n2_t, e1) == 1 * sizeof(coeff_t), "onumm10n2_t.e1: colex 1");
OTI_STATIC_LAYOUT_ASSERT(offsetof(onumm10n2_t, e2) == 2 * sizeof(coeff_t), "onumm10n2_t.e2: colex 2");
OTI_STATIC_LAYOUT_ASSERT(offsetof(onumm10n2_t, e3) == 3 * sizeof(coeff_t), "onumm10n2_t.e3: colex 3");
OTI_STATIC_LAYOUT_ASSERT(offsetof(onumm10n2_t, e4) == 4 * sizeof(coeff_t), "onumm10n2_t.e4: colex 4");
OTI_STATIC_LAYOUT_ASSERT(offsetof(onumm10n2_t, e5) == 5 * sizeof(coeff_t), "onumm10n2_t.e5: colex 5");
OTI_STATIC_LAYOUT_ASSERT(offsetof(onumm10n2_t, e6) == 6 * sizeof(coeff_t), "onumm10n2_t.e6: colex 6");
OTI_STATIC_LAYOUT_ASSERT(offsetof(onumm10n2_t, e7) == 7 * sizeof(coeff_t), "onumm10n2_t.e7: colex 7");
OTI_STATIC_LAYOUT_ASSERT(offsetof(onumm10n2_t, e8) == 8 * sizeof(coeff_t), "onumm10n2_t.e8: colex 8");
OTI_STATIC_LAYOUT_ASSERT(offsetof(onumm10n2_t, e9) == 9 * sizeof(coeff_t), "onumm10n2_t.e9: colex 9");
OTI_STATIC_LAYOUT_ASSERT(offsetof(onumm10n2_t, eA) == 10 * sizeof(coeff_t), "onumm10n2_t.eA: colex 10");
OTI_STATIC_LAYOUT_ASSERT(offsetof(onumm10n2_t, e11) == 11 * sizeof(coeff_t), "onumm10n2_t.e11: colex 11");
OTI_STATIC_LAYOUT_ASSERT(offsetof(onumm10n2_t, e12) == 12 * sizeof(coeff_t), "onumm10n2_t.e12: colex 12");
OTI_STATIC_LAYOUT_ASSERT(offsetof(onumm10n2_t, e22) == 13 * sizeof(coeff_t), "onumm10n2_t.e22: colex 13");
OTI_STATIC_LAYOUT_ASSERT(offsetof(onumm10n2_t, e13) == 14 * sizeof(coeff_t), "onumm10n2_t.e13: colex 14");
OTI_STATIC_LAYOUT_ASSERT(offsetof(onumm10n2_t, e23) == 15 * sizeof(coeff_t), "onumm10n2_t.e23: colex 15");
OTI_STATIC_LAYOUT_ASSERT(offsetof(onumm10n2_t, e33) == 16 * sizeof(coeff_t), "onumm10n2_t.e33: colex 16");
OTI_STATIC_LAYOUT_ASSERT(offsetof(onumm10n2_t, e14) == 17 * sizeof(coeff_t), "onumm10n2_t.e14: colex 17");
OTI_STATIC_LAYOUT_ASSERT(offsetof(onumm10n2_t, e24) == 18 * sizeof(coeff_t), "onumm10n2_t.e24: colex 18");
OTI_STATIC_LAYOUT_ASSERT(offsetof(onumm10n2_t, e34) == 19 * sizeof(coeff_t), "onumm10n2_t.e34: colex 19");
OTI_STATIC_LAYOUT_ASSERT(offsetof(onumm10n2_t, e44) == 20 * sizeof(coeff_t), "onumm10n2_t.e44: colex 20");
OTI_STATIC_LAYOUT_ASSERT(offsetof(onumm10n2_t, e15) == 21 * sizeof(coeff_t), "onumm10n2_t.e15: colex 21");
OTI_STATIC_LAYOUT_ASSERT(offsetof(onumm10n2_t, e25) == 22 * sizeof(coeff_t), "onumm10n2_t.e25: colex 22");
OTI_STATIC_LAYOUT_ASSERT(offsetof(onumm10n2_t, e35) == 23 * sizeof(coeff_t), "onumm10n2_t.e35: colex 23");
OTI_STATIC_LAYOUT_ASSERT(offsetof(onumm10n2_t, e45) == 24 * sizeof(coeff_t), "onumm10n2_t.e45: colex 24");
OTI_STATIC_LAYOUT_ASSERT(offsetof(onumm10n2_t, e55) == 25 * sizeof(coeff_t), "onumm10n2_t.e55: colex 25");
OTI_STATIC_LAYOUT_ASSERT(offsetof(onumm10n2_t, e16) == 26 * sizeof(coeff_t), "onumm10n2_t.e16: colex 26");
OTI_STATIC_LAYOUT_ASSERT(offsetof(onumm10n2_t, e26) == 27 * sizeof(coeff_t), "onumm10n2_t.e26: colex 27");
OTI_STATIC_LAYOUT_ASSERT(offsetof(onumm10n2_t, e36) == 28 * sizeof(coeff_t), "onumm10n2_t.e36: colex 28");
OTI_STATIC_LAYOUT_ASSERT(offsetof(onumm10n2_t, e46) == 29 * sizeof(coeff_t), "onumm10n2_t.e46: colex 29");
OTI_STATIC_LAYOUT_ASSERT(offsetof(onumm10n2_t, e56) == 30 * sizeof(coeff_t), "onumm10n2_t.e56: colex 30");
OTI_STATIC_LAYOUT_ASSERT(offsetof(onumm10n2_t, e66) == 31 * sizeof(coeff_t), "onumm10n2_t.e66: colex 31");
OTI_STATIC_LAYOUT_ASSERT(offsetof(onumm10n2_t, e17) == 32 * sizeof(coeff_t), "onumm10n2_t.e17: colex 32");
OTI_STATIC_LAYOUT_ASSERT(offsetof(onumm10n2_t, e27) == 33 * sizeof(coeff_t), "onumm10n2_t.e27: colex 33");
OTI_STATIC_LAYOUT_ASSERT(offsetof(onumm10n2_t, e37) == 34 * sizeof(coeff_t), "onumm10n2_t.e37: colex 34");
OTI_STATIC_LAYOUT_ASSERT(offsetof(onumm10n2_t, e47) == 35 * sizeof(coeff_t), "onumm10n2_t.e47: colex 35");
OTI_STATIC_LAYOUT_ASSERT(offsetof(onumm10n2_t, e57) == 36 * sizeof(coeff_t), "onumm10n2_t.e57: colex 36");
OTI_STATIC_LAYOUT_ASSERT(offsetof(onumm10n2_t, e67) == 37 * sizeof(coeff_t), "onumm10n2_t.e67: colex 37");
OTI_STATIC_LAYOUT_ASSERT(offsetof(onumm10n2_t, e77) == 38 * sizeof(coeff_t), "onumm10n2_t.e77: colex 38");
OTI_STATIC_LAYOUT_ASSERT(offsetof(onumm10n2_t, e18) == 39 * sizeof(coeff_t), "onumm10n2_t.e18: colex 39");
OTI_STATIC_LAYOUT_ASSERT(offsetof(onumm10n2_t, e28) == 40 * sizeof(coeff_t), "onumm10n2_t.e28: colex 40");
OTI_STATIC_LAYOUT_ASSERT(offsetof(onumm10n2_t, e38) == 41 * sizeof(coeff_t), "onumm10n2_t.e38: colex 41");
OTI_STATIC_LAYOUT_ASSERT(offsetof(onumm10n2_t, e48) == 42 * sizeof(coeff_t), "onumm10n2_t.e48: colex 42");
OTI_STATIC_LAYOUT_ASSERT(offsetof(onumm10n2_t, e58) == 43 * sizeof(coeff_t), "onumm10n2_t.e58: colex 43");
OTI_STATIC_LAYOUT_ASSERT(offsetof(onumm10n2_t, e68) == 44 * sizeof(coeff_t), "onumm10n2_t.e68: colex 44");
OTI_STATIC_LAYOUT_ASSERT(offsetof(onumm10n2_t, e78) == 45 * sizeof(coeff_t), "onumm10n2_t.e78: colex 45");
OTI_STATIC_LAYOUT_ASSERT(offsetof(onumm10n2_t, e88) == 46 * sizeof(coeff_t), "onumm10n2_t.e88: colex 46");
OTI_STATIC_LAYOUT_ASSERT(offsetof(onumm10n2_t, e19) == 47 * sizeof(coeff_t), "onumm10n2_t.e19: colex 47");
OTI_STATIC_LAYOUT_ASSERT(offsetof(onumm10n2_t, e29) == 48 * sizeof(coeff_t), "onumm10n2_t.e29: colex 48");
OTI_STATIC_LAYOUT_ASSERT(offsetof(onumm10n2_t, e39) == 49 * sizeof(coeff_t), "onumm10n2_t.e39: colex 49");
OTI_STATIC_LAYOUT_ASSERT(offsetof(onumm10n2_t, e49) == 50 * sizeof(coeff_t), "onumm10n2_t.e49: colex 50");
OTI_STATIC_LAYOUT_ASSERT(offsetof(onumm10n2_t, e59) == 51 * sizeof(coeff_t), "onumm10n2_t.e59: colex 51");
OTI_STATIC_LAYOUT_ASSERT(offsetof(onumm10n2_t, e69) == 52 * sizeof(coeff_t), "onumm10n2_t.e69: colex 52");
OTI_STATIC_LAYOUT_ASSERT(offsetof(onumm10n2_t, e79) == 53 * sizeof(coeff_t), "onumm10n2_t.e79: colex 53");
OTI_STATIC_LAYOUT_ASSERT(offsetof(onumm10n2_t, e89) == 54 * sizeof(coeff_t), "onumm10n2_t.e89: colex 54");
OTI_STATIC_LAYOUT_ASSERT(offsetof(onumm10n2_t, e99) == 55 * sizeof(coeff_t), "onumm10n2_t.e99: colex 55");
OTI_STATIC_LAYOUT_ASSERT(offsetof(onumm10n2_t, e1A) == 56 * sizeof(coeff_t), "onumm10n2_t.e1A: colex 56");
OTI_STATIC_LAYOUT_ASSERT(offsetof(onumm10n2_t, e2A) == 57 * sizeof(coeff_t), "onumm10n2_t.e2A: colex 57");
OTI_STATIC_LAYOUT_ASSERT(offsetof(onumm10n2_t, e3A) == 58 * sizeof(coeff_t), "onumm10n2_t.e3A: colex 58");
OTI_STATIC_LAYOUT_ASSERT(offsetof(onumm10n2_t, e4A) == 59 * sizeof(coeff_t), "onumm10n2_t.e4A: colex 59");
OTI_STATIC_LAYOUT_ASSERT(offsetof(onumm10n2_t, e5A) == 60 * sizeof(coeff_t), "onumm10n2_t.e5A: colex 60");
OTI_STATIC_LAYOUT_ASSERT(offsetof(onumm10n2_t, e6A) == 61 * sizeof(coeff_t), "onumm10n2_t.e6A: colex 61");
OTI_STATIC_LAYOUT_ASSERT(offsetof(onumm10n2_t, e7A) == 62 * sizeof(coeff_t), "onumm10n2_t.e7A: colex 62");
OTI_STATIC_LAYOUT_ASSERT(offsetof(onumm10n2_t, e8A) == 63 * sizeof(coeff_t), "onumm10n2_t.e8A: colex 63");
OTI_STATIC_LAYOUT_ASSERT(offsetof(onumm10n2_t, e9A) == 64 * sizeof(coeff_t), "onumm10n2_t.e9A: colex 64");
OTI_STATIC_LAYOUT_ASSERT(offsetof(onumm10n2_t, eAA) == 65 * sizeof(coeff_t), "onumm10n2_t.eAA: colex 65");
// END LAYOUT ASSERTS


// ----------------------------------------------------------------------------------------------------
// -------------------------------------    END STRUCTURES      ---------------------------------------
// ----------------------------------------------------------------------------------------------------

#endif