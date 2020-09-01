#ifndef OTI_ONUMM5N3_SCALAR_STRUCTURES_H
#define OTI_ONUMM5N3_SCALAR_STRUCTURES_H

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
  coeff_t e115;
  coeff_t e125;
  coeff_t e225;
  coeff_t e135;
  coeff_t e235;
  coeff_t e335;
  coeff_t e145;
  coeff_t e245;
  coeff_t e345;
  coeff_t e445;
  coeff_t e155;
  coeff_t e255;
  coeff_t e355;
  coeff_t e455;
  coeff_t e555;
} onumm5n3_t;




// ----------------------------------------------------------------------------------------------------
// -------------------------------------    END STRUCTURES      ---------------------------------------
// ----------------------------------------------------------------------------------------------------

#endif