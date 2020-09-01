#ifndef OTI_ONUMM4N4_SCALAR_STRUCTURES_H
#define OTI_ONUMM4N4_SCALAR_STRUCTURES_H

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
  coeff_t e114;
  coeff_t e124;
  coeff_t e224;
  coeff_t e134;
  coeff_t e234;
  coeff_t e334;
  coeff_t e144;
  coeff_t e244;
  coeff_t e344;
  coeff_t e444;
  // Order 4
  coeff_t e1111;
  coeff_t e1112;
  coeff_t e1122;
  coeff_t e1222;
  coeff_t e2222;
  coeff_t e1113;
  coeff_t e1123;
  coeff_t e1223;
  coeff_t e2223;
  coeff_t e1133;
  coeff_t e1233;
  coeff_t e2233;
  coeff_t e1333;
  coeff_t e2333;
  coeff_t e3333;
  coeff_t e1114;
  coeff_t e1124;
  coeff_t e1224;
  coeff_t e2224;
  coeff_t e1134;
  coeff_t e1234;
  coeff_t e2234;
  coeff_t e1334;
  coeff_t e2334;
  coeff_t e3334;
  coeff_t e1144;
  coeff_t e1244;
  coeff_t e2244;
  coeff_t e1344;
  coeff_t e2344;
  coeff_t e3344;
  coeff_t e1444;
  coeff_t e2444;
  coeff_t e3444;
  coeff_t e4444;
} onumm4n4_t;




// ----------------------------------------------------------------------------------------------------
// -------------------------------------    END STRUCTURES      ---------------------------------------
// ----------------------------------------------------------------------------------------------------

#endif