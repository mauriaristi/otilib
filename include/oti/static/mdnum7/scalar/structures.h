#ifndef OTI_MDNUM7_SCALAR_STRUCTURES_H
#define OTI_MDNUM7_SCALAR_STRUCTURES_H

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
  coeff_t e17;
  coeff_t e27;
  coeff_t e37;
  coeff_t e47;
  coeff_t e57;
  coeff_t e67;
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
  coeff_t e127;
  coeff_t e137;
  coeff_t e237;
  coeff_t e147;
  coeff_t e247;
  coeff_t e347;
  coeff_t e157;
  coeff_t e257;
  coeff_t e357;
  coeff_t e457;
  coeff_t e167;
  coeff_t e267;
  coeff_t e367;
  coeff_t e467;
  coeff_t e567;
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
  coeff_t e1237;
  coeff_t e1247;
  coeff_t e1347;
  coeff_t e2347;
  coeff_t e1257;
  coeff_t e1357;
  coeff_t e2357;
  coeff_t e1457;
  coeff_t e2457;
  coeff_t e3457;
  coeff_t e1267;
  coeff_t e1367;
  coeff_t e2367;
  coeff_t e1467;
  coeff_t e2467;
  coeff_t e3467;
  coeff_t e1567;
  coeff_t e2567;
  coeff_t e3567;
  coeff_t e4567;
  // Order 5
  coeff_t e12345;
  coeff_t e12346;
  coeff_t e12356;
  coeff_t e12456;
  coeff_t e13456;
  coeff_t e23456;
  coeff_t e12347;
  coeff_t e12357;
  coeff_t e12457;
  coeff_t e13457;
  coeff_t e23457;
  coeff_t e12367;
  coeff_t e12467;
  coeff_t e13467;
  coeff_t e23467;
  coeff_t e12567;
  coeff_t e13567;
  coeff_t e23567;
  coeff_t e14567;
  coeff_t e24567;
  coeff_t e34567;
  // Order 6
  coeff_t e123456;
  coeff_t e123457;
  coeff_t e123467;
  coeff_t e123567;
  coeff_t e124567;
  coeff_t e134567;
  coeff_t e234567;
  // Order 7
  coeff_t e1234567;
} mdnum7_t;




// ----------------------------------------------------------------------------------------------------
// -------------------------------------    END STRUCTURES      ---------------------------------------
// ----------------------------------------------------------------------------------------------------

#endif