#ifndef OTI_ONUMM2N10_SCALAR_STRUCTURES_H
#define OTI_ONUMM2N10_SCALAR_STRUCTURES_H

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
  // Order 7
  coeff_t e1111111;
  coeff_t e1111112;
  coeff_t e1111122;
  coeff_t e1111222;
  coeff_t e1112222;
  coeff_t e1122222;
  coeff_t e1222222;
  coeff_t e2222222;
  // Order 8
  coeff_t e11111111;
  coeff_t e11111112;
  coeff_t e11111122;
  coeff_t e11111222;
  coeff_t e11112222;
  coeff_t e11122222;
  coeff_t e11222222;
  coeff_t e12222222;
  coeff_t e22222222;
  // Order 9
  coeff_t e111111111;
  coeff_t e111111112;
  coeff_t e111111122;
  coeff_t e111111222;
  coeff_t e111112222;
  coeff_t e111122222;
  coeff_t e111222222;
  coeff_t e112222222;
  coeff_t e122222222;
  coeff_t e222222222;
  // Order 10
  coeff_t e1111111111;
  coeff_t e1111111112;
  coeff_t e1111111122;
  coeff_t e1111111222;
  coeff_t e1111112222;
  coeff_t e1111122222;
  coeff_t e1111222222;
  coeff_t e1112222222;
  coeff_t e1122222222;
  coeff_t e1222222222;
  coeff_t e2222222222;
} onumm2n10_t;




// ----------------------------------------------------------------------------------------------------
// -------------------------------------    END STRUCTURES      ---------------------------------------
// ----------------------------------------------------------------------------------------------------

#endif