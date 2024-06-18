#ifndef OTI_ONUMM3N4_SCALAR_STRUCTURES_H
#define OTI_ONUMM3N4_SCALAR_STRUCTURES_H

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
} onumm3n4_t;




// ----------------------------------------------------------------------------------------------------
// -------------------------------------    END STRUCTURES      ---------------------------------------
// ----------------------------------------------------------------------------------------------------

#endif