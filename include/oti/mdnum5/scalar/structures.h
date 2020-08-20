#ifndef OTI_MDNUM5_SCALAR_STRUCTURES_H
#define OTI_MDNUM5_SCALAR_STRUCTURES_H

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
  // Order 2
  coeff_t e12;
  coeff_t e13;
  coeff_t e23;
  coeff_t e14;
  coeff_t e24;
  coeff_t e34;
  coeff_t e15;
  coeff_t e25;
  coeff_t e35;
  coeff_t e45;
  // Order 3
  coeff_t e123;
  coeff_t e124;
  coeff_t e134;
  coeff_t e234;
  coeff_t e125;
  coeff_t e135;
  coeff_t e235;
  coeff_t e145;
  coeff_t e245;
  coeff_t e345;
  // Order 4
  coeff_t e1234;
  coeff_t e1235;
  coeff_t e1245;
  coeff_t e1345;
  coeff_t e2345;
  // Order 5
  coeff_t e12345;
} mdnum5_t;




// ----------------------------------------------------------------------------------------------------
// -------------------------------------    END STRUCTURES      ---------------------------------------
// ----------------------------------------------------------------------------------------------------

#endif