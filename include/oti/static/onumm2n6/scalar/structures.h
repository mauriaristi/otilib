#ifndef OTI_ONUMM2N6_SCALAR_STRUCTURES_H
#define OTI_ONUMM2N6_SCALAR_STRUCTURES_H

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
  // Order 5
  coeff_t e11111;
  coeff_t e11112;
  coeff_t e11122;
  coeff_t e11222;
  coeff_t e12222;
  coeff_t e22222;
  // Order 6
  coeff_t e111111;
  coeff_t e111112;
  coeff_t e111122;
  coeff_t e111222;
  coeff_t e112222;
  coeff_t e122222;
  coeff_t e222222;
} onumm2n6_t;




// ----------------------------------------------------------------------------------------------------
// -------------------------------------    END STRUCTURES      ---------------------------------------
// ----------------------------------------------------------------------------------------------------

#endif