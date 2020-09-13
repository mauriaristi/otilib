#ifndef OTI_MDNUM6_SCALAR_STRUCTURES_H
#define OTI_MDNUM6_SCALAR_STRUCTURES_H

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
  coeff_t e16;
  coeff_t e26;
  coeff_t e36;
  coeff_t e46;
  coeff_t e56;
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
  coeff_t e126;
  coeff_t e136;
  coeff_t e236;
  coeff_t e146;
  coeff_t e246;
  coeff_t e346;
  coeff_t e156;
  coeff_t e256;
  coeff_t e356;
  coeff_t e456;
  // Order 4
  coeff_t e1234;
  coeff_t e1235;
  coeff_t e1245;
  coeff_t e1345;
  coeff_t e2345;
  coeff_t e1236;
  coeff_t e1246;
  coeff_t e1346;
  coeff_t e2346;
  coeff_t e1256;
  coeff_t e1356;
  coeff_t e2356;
  coeff_t e1456;
  coeff_t e2456;
  coeff_t e3456;
  // Order 5
  coeff_t e12345;
  coeff_t e12346;
  coeff_t e12356;
  coeff_t e12456;
  coeff_t e13456;
  coeff_t e23456;
  // Order 6
  coeff_t e123456;
} mdnum6_t;




// ----------------------------------------------------------------------------------------------------
// -------------------------------------    END STRUCTURES      ---------------------------------------
// ----------------------------------------------------------------------------------------------------

#endif