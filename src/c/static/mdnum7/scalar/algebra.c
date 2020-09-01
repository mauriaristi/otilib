
// Division.

// ****************************************************************************************************
mdnum7_t mdnum7_div_ro(coeff_t num, mdnum7_t* den){

    
    mdnum7_t inv = mdnum7_pow(den,-1);
    mdnum7_t res = mdnum7_mul_ro(num,&inv);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdnum7_t mdnum7_div_oo(mdnum7_t* num, mdnum7_t* den){

    
    mdnum7_t inv = mdnum7_init();
    mdnum7_pow_to(den,-1,&inv);
    mdnum7_t res = mdnum7_mul_oo(num,&inv);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdnum7_t mdnum7_div_or(mdnum7_t* num, coeff_t val){

    return mdnum7_mul_ro(1.0/val,num);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdnum7_t mdnum7_abs(mdnum7_t* num){

	mdnum7_t res;
    mdnum7_abs_to(num,&res);
    return res;

}
// ----------------------------------------------------------------------------------------------------

mdnum7_t mdnum7_neg(  mdnum7_t* lhs){

  mdnum7_t res;

  // Negation like function '-lhs'
  // Real;
  res.r = -lhs->r;
  // Order 1;
  res.e1 = -lhs->e1;
  res.e2 = -lhs->e2;
  res.e3 = -lhs->e3;
  res.e4 = -lhs->e4;
  res.e5 = -lhs->e5;
  res.e6 = -lhs->e6;
  res.e7 = -lhs->e7;
  // Order 2;
  res.e12 = -lhs->e12;
  res.e13 = -lhs->e13;
  res.e23 = -lhs->e23;
  res.e14 = -lhs->e14;
  res.e24 = -lhs->e24;
  res.e34 = -lhs->e34;
  res.e15 = -lhs->e15;
  res.e25 = -lhs->e25;
  res.e35 = -lhs->e35;
  res.e45 = -lhs->e45;
  res.e16 = -lhs->e16;
  res.e26 = -lhs->e26;
  res.e36 = -lhs->e36;
  res.e46 = -lhs->e46;
  res.e56 = -lhs->e56;
  res.e17 = -lhs->e17;
  res.e27 = -lhs->e27;
  res.e37 = -lhs->e37;
  res.e47 = -lhs->e47;
  res.e57 = -lhs->e57;
  res.e67 = -lhs->e67;
  // Order 3;
  res.e123 = -lhs->e123;
  res.e124 = -lhs->e124;
  res.e134 = -lhs->e134;
  res.e234 = -lhs->e234;
  res.e125 = -lhs->e125;
  res.e135 = -lhs->e135;
  res.e235 = -lhs->e235;
  res.e145 = -lhs->e145;
  res.e245 = -lhs->e245;
  res.e345 = -lhs->e345;
  res.e126 = -lhs->e126;
  res.e136 = -lhs->e136;
  res.e236 = -lhs->e236;
  res.e146 = -lhs->e146;
  res.e246 = -lhs->e246;
  res.e346 = -lhs->e346;
  res.e156 = -lhs->e156;
  res.e256 = -lhs->e256;
  res.e356 = -lhs->e356;
  res.e456 = -lhs->e456;
  res.e127 = -lhs->e127;
  res.e137 = -lhs->e137;
  res.e237 = -lhs->e237;
  res.e147 = -lhs->e147;
  res.e247 = -lhs->e247;
  res.e347 = -lhs->e347;
  res.e157 = -lhs->e157;
  res.e257 = -lhs->e257;
  res.e357 = -lhs->e357;
  res.e457 = -lhs->e457;
  res.e167 = -lhs->e167;
  res.e267 = -lhs->e267;
  res.e367 = -lhs->e367;
  res.e467 = -lhs->e467;
  res.e567 = -lhs->e567;
  // Order 4;
  res.e1234 = -lhs->e1234;
  res.e1235 = -lhs->e1235;
  res.e1245 = -lhs->e1245;
  res.e1345 = -lhs->e1345;
  res.e2345 = -lhs->e2345;
  res.e1236 = -lhs->e1236;
  res.e1246 = -lhs->e1246;
  res.e1346 = -lhs->e1346;
  res.e2346 = -lhs->e2346;
  res.e1256 = -lhs->e1256;
  res.e1356 = -lhs->e1356;
  res.e2356 = -lhs->e2356;
  res.e1456 = -lhs->e1456;
  res.e2456 = -lhs->e2456;
  res.e3456 = -lhs->e3456;
  res.e1237 = -lhs->e1237;
  res.e1247 = -lhs->e1247;
  res.e1347 = -lhs->e1347;
  res.e2347 = -lhs->e2347;
  res.e1257 = -lhs->e1257;
  res.e1357 = -lhs->e1357;
  res.e2357 = -lhs->e2357;
  res.e1457 = -lhs->e1457;
  res.e2457 = -lhs->e2457;
  res.e3457 = -lhs->e3457;
  res.e1267 = -lhs->e1267;
  res.e1367 = -lhs->e1367;
  res.e2367 = -lhs->e2367;
  res.e1467 = -lhs->e1467;
  res.e2467 = -lhs->e2467;
  res.e3467 = -lhs->e3467;
  res.e1567 = -lhs->e1567;
  res.e2567 = -lhs->e2567;
  res.e3567 = -lhs->e3567;
  res.e4567 = -lhs->e4567;
  // Order 5;
  res.e12345 = -lhs->e12345;
  res.e12346 = -lhs->e12346;
  res.e12356 = -lhs->e12356;
  res.e12456 = -lhs->e12456;
  res.e13456 = -lhs->e13456;
  res.e23456 = -lhs->e23456;
  res.e12347 = -lhs->e12347;
  res.e12357 = -lhs->e12357;
  res.e12457 = -lhs->e12457;
  res.e13457 = -lhs->e13457;
  res.e23457 = -lhs->e23457;
  res.e12367 = -lhs->e12367;
  res.e12467 = -lhs->e12467;
  res.e13467 = -lhs->e13467;
  res.e23467 = -lhs->e23467;
  res.e12567 = -lhs->e12567;
  res.e13567 = -lhs->e13567;
  res.e23567 = -lhs->e23567;
  res.e14567 = -lhs->e14567;
  res.e24567 = -lhs->e24567;
  res.e34567 = -lhs->e34567;
  // Order 6;
  res.e123456 = -lhs->e123456;
  res.e123457 = -lhs->e123457;
  res.e123467 = -lhs->e123467;
  res.e123567 = -lhs->e123567;
  res.e124567 = -lhs->e124567;
  res.e134567 = -lhs->e134567;
  res.e234567 = -lhs->e234567;
  // Order 7;
  res.e1234567 = -lhs->e1234567;

  return res;

}

void mdnum7_neg_to(  mdnum7_t* lhs, mdnum7_t* res){

  // Negation like function '-lhs'
  // Real;
  res->r = -lhs->r;
  // Order 1;
  res->e1 = -lhs->e1;
  res->e2 = -lhs->e2;
  res->e3 = -lhs->e3;
  res->e4 = -lhs->e4;
  res->e5 = -lhs->e5;
  res->e6 = -lhs->e6;
  res->e7 = -lhs->e7;
  // Order 2;
  res->e12 = -lhs->e12;
  res->e13 = -lhs->e13;
  res->e23 = -lhs->e23;
  res->e14 = -lhs->e14;
  res->e24 = -lhs->e24;
  res->e34 = -lhs->e34;
  res->e15 = -lhs->e15;
  res->e25 = -lhs->e25;
  res->e35 = -lhs->e35;
  res->e45 = -lhs->e45;
  res->e16 = -lhs->e16;
  res->e26 = -lhs->e26;
  res->e36 = -lhs->e36;
  res->e46 = -lhs->e46;
  res->e56 = -lhs->e56;
  res->e17 = -lhs->e17;
  res->e27 = -lhs->e27;
  res->e37 = -lhs->e37;
  res->e47 = -lhs->e47;
  res->e57 = -lhs->e57;
  res->e67 = -lhs->e67;
  // Order 3;
  res->e123 = -lhs->e123;
  res->e124 = -lhs->e124;
  res->e134 = -lhs->e134;
  res->e234 = -lhs->e234;
  res->e125 = -lhs->e125;
  res->e135 = -lhs->e135;
  res->e235 = -lhs->e235;
  res->e145 = -lhs->e145;
  res->e245 = -lhs->e245;
  res->e345 = -lhs->e345;
  res->e126 = -lhs->e126;
  res->e136 = -lhs->e136;
  res->e236 = -lhs->e236;
  res->e146 = -lhs->e146;
  res->e246 = -lhs->e246;
  res->e346 = -lhs->e346;
  res->e156 = -lhs->e156;
  res->e256 = -lhs->e256;
  res->e356 = -lhs->e356;
  res->e456 = -lhs->e456;
  res->e127 = -lhs->e127;
  res->e137 = -lhs->e137;
  res->e237 = -lhs->e237;
  res->e147 = -lhs->e147;
  res->e247 = -lhs->e247;
  res->e347 = -lhs->e347;
  res->e157 = -lhs->e157;
  res->e257 = -lhs->e257;
  res->e357 = -lhs->e357;
  res->e457 = -lhs->e457;
  res->e167 = -lhs->e167;
  res->e267 = -lhs->e267;
  res->e367 = -lhs->e367;
  res->e467 = -lhs->e467;
  res->e567 = -lhs->e567;
  // Order 4;
  res->e1234 = -lhs->e1234;
  res->e1235 = -lhs->e1235;
  res->e1245 = -lhs->e1245;
  res->e1345 = -lhs->e1345;
  res->e2345 = -lhs->e2345;
  res->e1236 = -lhs->e1236;
  res->e1246 = -lhs->e1246;
  res->e1346 = -lhs->e1346;
  res->e2346 = -lhs->e2346;
  res->e1256 = -lhs->e1256;
  res->e1356 = -lhs->e1356;
  res->e2356 = -lhs->e2356;
  res->e1456 = -lhs->e1456;
  res->e2456 = -lhs->e2456;
  res->e3456 = -lhs->e3456;
  res->e1237 = -lhs->e1237;
  res->e1247 = -lhs->e1247;
  res->e1347 = -lhs->e1347;
  res->e2347 = -lhs->e2347;
  res->e1257 = -lhs->e1257;
  res->e1357 = -lhs->e1357;
  res->e2357 = -lhs->e2357;
  res->e1457 = -lhs->e1457;
  res->e2457 = -lhs->e2457;
  res->e3457 = -lhs->e3457;
  res->e1267 = -lhs->e1267;
  res->e1367 = -lhs->e1367;
  res->e2367 = -lhs->e2367;
  res->e1467 = -lhs->e1467;
  res->e2467 = -lhs->e2467;
  res->e3467 = -lhs->e3467;
  res->e1567 = -lhs->e1567;
  res->e2567 = -lhs->e2567;
  res->e3567 = -lhs->e3567;
  res->e4567 = -lhs->e4567;
  // Order 5;
  res->e12345 = -lhs->e12345;
  res->e12346 = -lhs->e12346;
  res->e12356 = -lhs->e12356;
  res->e12456 = -lhs->e12456;
  res->e13456 = -lhs->e13456;
  res->e23456 = -lhs->e23456;
  res->e12347 = -lhs->e12347;
  res->e12357 = -lhs->e12357;
  res->e12457 = -lhs->e12457;
  res->e13457 = -lhs->e13457;
  res->e23457 = -lhs->e23457;
  res->e12367 = -lhs->e12367;
  res->e12467 = -lhs->e12467;
  res->e13467 = -lhs->e13467;
  res->e23467 = -lhs->e23467;
  res->e12567 = -lhs->e12567;
  res->e13567 = -lhs->e13567;
  res->e23567 = -lhs->e23567;
  res->e14567 = -lhs->e14567;
  res->e24567 = -lhs->e24567;
  res->e34567 = -lhs->e34567;
  // Order 6;
  res->e123456 = -lhs->e123456;
  res->e123457 = -lhs->e123457;
  res->e123467 = -lhs->e123467;
  res->e123567 = -lhs->e123567;
  res->e124567 = -lhs->e124567;
  res->e134567 = -lhs->e134567;
  res->e234567 = -lhs->e234567;
  // Order 7;
  res->e1234567 = -lhs->e1234567;

}

mdnum7_t mdnum7_sum_oo(  mdnum7_t* lhs,  mdnum7_t* rhs){
  mdnum7_t res;

  // Addition like function 'lhs + rhs'
  //  Real
  res.r = lhs->r + rhs->r;
  // Order 1
  res.e1 = lhs->e1 + rhs->e1;
  res.e2 = lhs->e2 + rhs->e2;
  res.e3 = lhs->e3 + rhs->e3;
  res.e4 = lhs->e4 + rhs->e4;
  res.e5 = lhs->e5 + rhs->e5;
  res.e6 = lhs->e6 + rhs->e6;
  res.e7 = lhs->e7 + rhs->e7;
  // Order 2
  res.e12 = lhs->e12 + rhs->e12;
  res.e13 = lhs->e13 + rhs->e13;
  res.e23 = lhs->e23 + rhs->e23;
  res.e14 = lhs->e14 + rhs->e14;
  res.e24 = lhs->e24 + rhs->e24;
  res.e34 = lhs->e34 + rhs->e34;
  res.e15 = lhs->e15 + rhs->e15;
  res.e25 = lhs->e25 + rhs->e25;
  res.e35 = lhs->e35 + rhs->e35;
  res.e45 = lhs->e45 + rhs->e45;
  res.e16 = lhs->e16 + rhs->e16;
  res.e26 = lhs->e26 + rhs->e26;
  res.e36 = lhs->e36 + rhs->e36;
  res.e46 = lhs->e46 + rhs->e46;
  res.e56 = lhs->e56 + rhs->e56;
  res.e17 = lhs->e17 + rhs->e17;
  res.e27 = lhs->e27 + rhs->e27;
  res.e37 = lhs->e37 + rhs->e37;
  res.e47 = lhs->e47 + rhs->e47;
  res.e57 = lhs->e57 + rhs->e57;
  res.e67 = lhs->e67 + rhs->e67;
  // Order 3
  res.e123 = lhs->e123 + rhs->e123;
  res.e124 = lhs->e124 + rhs->e124;
  res.e134 = lhs->e134 + rhs->e134;
  res.e234 = lhs->e234 + rhs->e234;
  res.e125 = lhs->e125 + rhs->e125;
  res.e135 = lhs->e135 + rhs->e135;
  res.e235 = lhs->e235 + rhs->e235;
  res.e145 = lhs->e145 + rhs->e145;
  res.e245 = lhs->e245 + rhs->e245;
  res.e345 = lhs->e345 + rhs->e345;
  res.e126 = lhs->e126 + rhs->e126;
  res.e136 = lhs->e136 + rhs->e136;
  res.e236 = lhs->e236 + rhs->e236;
  res.e146 = lhs->e146 + rhs->e146;
  res.e246 = lhs->e246 + rhs->e246;
  res.e346 = lhs->e346 + rhs->e346;
  res.e156 = lhs->e156 + rhs->e156;
  res.e256 = lhs->e256 + rhs->e256;
  res.e356 = lhs->e356 + rhs->e356;
  res.e456 = lhs->e456 + rhs->e456;
  res.e127 = lhs->e127 + rhs->e127;
  res.e137 = lhs->e137 + rhs->e137;
  res.e237 = lhs->e237 + rhs->e237;
  res.e147 = lhs->e147 + rhs->e147;
  res.e247 = lhs->e247 + rhs->e247;
  res.e347 = lhs->e347 + rhs->e347;
  res.e157 = lhs->e157 + rhs->e157;
  res.e257 = lhs->e257 + rhs->e257;
  res.e357 = lhs->e357 + rhs->e357;
  res.e457 = lhs->e457 + rhs->e457;
  res.e167 = lhs->e167 + rhs->e167;
  res.e267 = lhs->e267 + rhs->e267;
  res.e367 = lhs->e367 + rhs->e367;
  res.e467 = lhs->e467 + rhs->e467;
  res.e567 = lhs->e567 + rhs->e567;
  // Order 4
  res.e1234 = lhs->e1234 + rhs->e1234;
  res.e1235 = lhs->e1235 + rhs->e1235;
  res.e1245 = lhs->e1245 + rhs->e1245;
  res.e1345 = lhs->e1345 + rhs->e1345;
  res.e2345 = lhs->e2345 + rhs->e2345;
  res.e1236 = lhs->e1236 + rhs->e1236;
  res.e1246 = lhs->e1246 + rhs->e1246;
  res.e1346 = lhs->e1346 + rhs->e1346;
  res.e2346 = lhs->e2346 + rhs->e2346;
  res.e1256 = lhs->e1256 + rhs->e1256;
  res.e1356 = lhs->e1356 + rhs->e1356;
  res.e2356 = lhs->e2356 + rhs->e2356;
  res.e1456 = lhs->e1456 + rhs->e1456;
  res.e2456 = lhs->e2456 + rhs->e2456;
  res.e3456 = lhs->e3456 + rhs->e3456;
  res.e1237 = lhs->e1237 + rhs->e1237;
  res.e1247 = lhs->e1247 + rhs->e1247;
  res.e1347 = lhs->e1347 + rhs->e1347;
  res.e2347 = lhs->e2347 + rhs->e2347;
  res.e1257 = lhs->e1257 + rhs->e1257;
  res.e1357 = lhs->e1357 + rhs->e1357;
  res.e2357 = lhs->e2357 + rhs->e2357;
  res.e1457 = lhs->e1457 + rhs->e1457;
  res.e2457 = lhs->e2457 + rhs->e2457;
  res.e3457 = lhs->e3457 + rhs->e3457;
  res.e1267 = lhs->e1267 + rhs->e1267;
  res.e1367 = lhs->e1367 + rhs->e1367;
  res.e2367 = lhs->e2367 + rhs->e2367;
  res.e1467 = lhs->e1467 + rhs->e1467;
  res.e2467 = lhs->e2467 + rhs->e2467;
  res.e3467 = lhs->e3467 + rhs->e3467;
  res.e1567 = lhs->e1567 + rhs->e1567;
  res.e2567 = lhs->e2567 + rhs->e2567;
  res.e3567 = lhs->e3567 + rhs->e3567;
  res.e4567 = lhs->e4567 + rhs->e4567;
  // Order 5
  res.e12345 = lhs->e12345 + rhs->e12345;
  res.e12346 = lhs->e12346 + rhs->e12346;
  res.e12356 = lhs->e12356 + rhs->e12356;
  res.e12456 = lhs->e12456 + rhs->e12456;
  res.e13456 = lhs->e13456 + rhs->e13456;
  res.e23456 = lhs->e23456 + rhs->e23456;
  res.e12347 = lhs->e12347 + rhs->e12347;
  res.e12357 = lhs->e12357 + rhs->e12357;
  res.e12457 = lhs->e12457 + rhs->e12457;
  res.e13457 = lhs->e13457 + rhs->e13457;
  res.e23457 = lhs->e23457 + rhs->e23457;
  res.e12367 = lhs->e12367 + rhs->e12367;
  res.e12467 = lhs->e12467 + rhs->e12467;
  res.e13467 = lhs->e13467 + rhs->e13467;
  res.e23467 = lhs->e23467 + rhs->e23467;
  res.e12567 = lhs->e12567 + rhs->e12567;
  res.e13567 = lhs->e13567 + rhs->e13567;
  res.e23567 = lhs->e23567 + rhs->e23567;
  res.e14567 = lhs->e14567 + rhs->e14567;
  res.e24567 = lhs->e24567 + rhs->e24567;
  res.e34567 = lhs->e34567 + rhs->e34567;
  // Order 6
  res.e123456 = lhs->e123456 + rhs->e123456;
  res.e123457 = lhs->e123457 + rhs->e123457;
  res.e123467 = lhs->e123467 + rhs->e123467;
  res.e123567 = lhs->e123567 + rhs->e123567;
  res.e124567 = lhs->e124567 + rhs->e124567;
  res.e134567 = lhs->e134567 + rhs->e134567;
  res.e234567 = lhs->e234567 + rhs->e234567;
  // Order 7
  res.e1234567 = lhs->e1234567 + rhs->e1234567;

  return res;

}

void mdnum7_sum_oo_to(  mdnum7_t* lhs,  mdnum7_t* rhs, mdnum7_t* res){
  // Addition like function 'lhs + rhs'
  //  Real
  res->r = lhs->r + rhs->r;
  // Order 1
  res->e1 = lhs->e1 + rhs->e1;
  res->e2 = lhs->e2 + rhs->e2;
  res->e3 = lhs->e3 + rhs->e3;
  res->e4 = lhs->e4 + rhs->e4;
  res->e5 = lhs->e5 + rhs->e5;
  res->e6 = lhs->e6 + rhs->e6;
  res->e7 = lhs->e7 + rhs->e7;
  // Order 2
  res->e12 = lhs->e12 + rhs->e12;
  res->e13 = lhs->e13 + rhs->e13;
  res->e23 = lhs->e23 + rhs->e23;
  res->e14 = lhs->e14 + rhs->e14;
  res->e24 = lhs->e24 + rhs->e24;
  res->e34 = lhs->e34 + rhs->e34;
  res->e15 = lhs->e15 + rhs->e15;
  res->e25 = lhs->e25 + rhs->e25;
  res->e35 = lhs->e35 + rhs->e35;
  res->e45 = lhs->e45 + rhs->e45;
  res->e16 = lhs->e16 + rhs->e16;
  res->e26 = lhs->e26 + rhs->e26;
  res->e36 = lhs->e36 + rhs->e36;
  res->e46 = lhs->e46 + rhs->e46;
  res->e56 = lhs->e56 + rhs->e56;
  res->e17 = lhs->e17 + rhs->e17;
  res->e27 = lhs->e27 + rhs->e27;
  res->e37 = lhs->e37 + rhs->e37;
  res->e47 = lhs->e47 + rhs->e47;
  res->e57 = lhs->e57 + rhs->e57;
  res->e67 = lhs->e67 + rhs->e67;
  // Order 3
  res->e123 = lhs->e123 + rhs->e123;
  res->e124 = lhs->e124 + rhs->e124;
  res->e134 = lhs->e134 + rhs->e134;
  res->e234 = lhs->e234 + rhs->e234;
  res->e125 = lhs->e125 + rhs->e125;
  res->e135 = lhs->e135 + rhs->e135;
  res->e235 = lhs->e235 + rhs->e235;
  res->e145 = lhs->e145 + rhs->e145;
  res->e245 = lhs->e245 + rhs->e245;
  res->e345 = lhs->e345 + rhs->e345;
  res->e126 = lhs->e126 + rhs->e126;
  res->e136 = lhs->e136 + rhs->e136;
  res->e236 = lhs->e236 + rhs->e236;
  res->e146 = lhs->e146 + rhs->e146;
  res->e246 = lhs->e246 + rhs->e246;
  res->e346 = lhs->e346 + rhs->e346;
  res->e156 = lhs->e156 + rhs->e156;
  res->e256 = lhs->e256 + rhs->e256;
  res->e356 = lhs->e356 + rhs->e356;
  res->e456 = lhs->e456 + rhs->e456;
  res->e127 = lhs->e127 + rhs->e127;
  res->e137 = lhs->e137 + rhs->e137;
  res->e237 = lhs->e237 + rhs->e237;
  res->e147 = lhs->e147 + rhs->e147;
  res->e247 = lhs->e247 + rhs->e247;
  res->e347 = lhs->e347 + rhs->e347;
  res->e157 = lhs->e157 + rhs->e157;
  res->e257 = lhs->e257 + rhs->e257;
  res->e357 = lhs->e357 + rhs->e357;
  res->e457 = lhs->e457 + rhs->e457;
  res->e167 = lhs->e167 + rhs->e167;
  res->e267 = lhs->e267 + rhs->e267;
  res->e367 = lhs->e367 + rhs->e367;
  res->e467 = lhs->e467 + rhs->e467;
  res->e567 = lhs->e567 + rhs->e567;
  // Order 4
  res->e1234 = lhs->e1234 + rhs->e1234;
  res->e1235 = lhs->e1235 + rhs->e1235;
  res->e1245 = lhs->e1245 + rhs->e1245;
  res->e1345 = lhs->e1345 + rhs->e1345;
  res->e2345 = lhs->e2345 + rhs->e2345;
  res->e1236 = lhs->e1236 + rhs->e1236;
  res->e1246 = lhs->e1246 + rhs->e1246;
  res->e1346 = lhs->e1346 + rhs->e1346;
  res->e2346 = lhs->e2346 + rhs->e2346;
  res->e1256 = lhs->e1256 + rhs->e1256;
  res->e1356 = lhs->e1356 + rhs->e1356;
  res->e2356 = lhs->e2356 + rhs->e2356;
  res->e1456 = lhs->e1456 + rhs->e1456;
  res->e2456 = lhs->e2456 + rhs->e2456;
  res->e3456 = lhs->e3456 + rhs->e3456;
  res->e1237 = lhs->e1237 + rhs->e1237;
  res->e1247 = lhs->e1247 + rhs->e1247;
  res->e1347 = lhs->e1347 + rhs->e1347;
  res->e2347 = lhs->e2347 + rhs->e2347;
  res->e1257 = lhs->e1257 + rhs->e1257;
  res->e1357 = lhs->e1357 + rhs->e1357;
  res->e2357 = lhs->e2357 + rhs->e2357;
  res->e1457 = lhs->e1457 + rhs->e1457;
  res->e2457 = lhs->e2457 + rhs->e2457;
  res->e3457 = lhs->e3457 + rhs->e3457;
  res->e1267 = lhs->e1267 + rhs->e1267;
  res->e1367 = lhs->e1367 + rhs->e1367;
  res->e2367 = lhs->e2367 + rhs->e2367;
  res->e1467 = lhs->e1467 + rhs->e1467;
  res->e2467 = lhs->e2467 + rhs->e2467;
  res->e3467 = lhs->e3467 + rhs->e3467;
  res->e1567 = lhs->e1567 + rhs->e1567;
  res->e2567 = lhs->e2567 + rhs->e2567;
  res->e3567 = lhs->e3567 + rhs->e3567;
  res->e4567 = lhs->e4567 + rhs->e4567;
  // Order 5
  res->e12345 = lhs->e12345 + rhs->e12345;
  res->e12346 = lhs->e12346 + rhs->e12346;
  res->e12356 = lhs->e12356 + rhs->e12356;
  res->e12456 = lhs->e12456 + rhs->e12456;
  res->e13456 = lhs->e13456 + rhs->e13456;
  res->e23456 = lhs->e23456 + rhs->e23456;
  res->e12347 = lhs->e12347 + rhs->e12347;
  res->e12357 = lhs->e12357 + rhs->e12357;
  res->e12457 = lhs->e12457 + rhs->e12457;
  res->e13457 = lhs->e13457 + rhs->e13457;
  res->e23457 = lhs->e23457 + rhs->e23457;
  res->e12367 = lhs->e12367 + rhs->e12367;
  res->e12467 = lhs->e12467 + rhs->e12467;
  res->e13467 = lhs->e13467 + rhs->e13467;
  res->e23467 = lhs->e23467 + rhs->e23467;
  res->e12567 = lhs->e12567 + rhs->e12567;
  res->e13567 = lhs->e13567 + rhs->e13567;
  res->e23567 = lhs->e23567 + rhs->e23567;
  res->e14567 = lhs->e14567 + rhs->e14567;
  res->e24567 = lhs->e24567 + rhs->e24567;
  res->e34567 = lhs->e34567 + rhs->e34567;
  // Order 6
  res->e123456 = lhs->e123456 + rhs->e123456;
  res->e123457 = lhs->e123457 + rhs->e123457;
  res->e123467 = lhs->e123467 + rhs->e123467;
  res->e123567 = lhs->e123567 + rhs->e123567;
  res->e124567 = lhs->e124567 + rhs->e124567;
  res->e134567 = lhs->e134567 + rhs->e134567;
  res->e234567 = lhs->e234567 + rhs->e234567;
  // Order 7
  res->e1234567 = lhs->e1234567 + rhs->e1234567;

}

mdnum7_t mdnum7_sum_ro(  coeff_t lhs,  mdnum7_t* rhs){
  mdnum7_t res;

  // Addition like function 'lhs + rhs'
  // Real;
  res.r = lhs + rhs->r;
  // Order 1;
  res.e1 =  + rhs->e1;
  res.e2 =  + rhs->e2;
  res.e3 =  + rhs->e3;
  res.e4 =  + rhs->e4;
  res.e5 =  + rhs->e5;
  res.e6 =  + rhs->e6;
  res.e7 =  + rhs->e7;
  // Order 2;
  res.e12 =  + rhs->e12;
  res.e13 =  + rhs->e13;
  res.e23 =  + rhs->e23;
  res.e14 =  + rhs->e14;
  res.e24 =  + rhs->e24;
  res.e34 =  + rhs->e34;
  res.e15 =  + rhs->e15;
  res.e25 =  + rhs->e25;
  res.e35 =  + rhs->e35;
  res.e45 =  + rhs->e45;
  res.e16 =  + rhs->e16;
  res.e26 =  + rhs->e26;
  res.e36 =  + rhs->e36;
  res.e46 =  + rhs->e46;
  res.e56 =  + rhs->e56;
  res.e17 =  + rhs->e17;
  res.e27 =  + rhs->e27;
  res.e37 =  + rhs->e37;
  res.e47 =  + rhs->e47;
  res.e57 =  + rhs->e57;
  res.e67 =  + rhs->e67;
  // Order 3;
  res.e123 =  + rhs->e123;
  res.e124 =  + rhs->e124;
  res.e134 =  + rhs->e134;
  res.e234 =  + rhs->e234;
  res.e125 =  + rhs->e125;
  res.e135 =  + rhs->e135;
  res.e235 =  + rhs->e235;
  res.e145 =  + rhs->e145;
  res.e245 =  + rhs->e245;
  res.e345 =  + rhs->e345;
  res.e126 =  + rhs->e126;
  res.e136 =  + rhs->e136;
  res.e236 =  + rhs->e236;
  res.e146 =  + rhs->e146;
  res.e246 =  + rhs->e246;
  res.e346 =  + rhs->e346;
  res.e156 =  + rhs->e156;
  res.e256 =  + rhs->e256;
  res.e356 =  + rhs->e356;
  res.e456 =  + rhs->e456;
  res.e127 =  + rhs->e127;
  res.e137 =  + rhs->e137;
  res.e237 =  + rhs->e237;
  res.e147 =  + rhs->e147;
  res.e247 =  + rhs->e247;
  res.e347 =  + rhs->e347;
  res.e157 =  + rhs->e157;
  res.e257 =  + rhs->e257;
  res.e357 =  + rhs->e357;
  res.e457 =  + rhs->e457;
  res.e167 =  + rhs->e167;
  res.e267 =  + rhs->e267;
  res.e367 =  + rhs->e367;
  res.e467 =  + rhs->e467;
  res.e567 =  + rhs->e567;
  // Order 4;
  res.e1234 =  + rhs->e1234;
  res.e1235 =  + rhs->e1235;
  res.e1245 =  + rhs->e1245;
  res.e1345 =  + rhs->e1345;
  res.e2345 =  + rhs->e2345;
  res.e1236 =  + rhs->e1236;
  res.e1246 =  + rhs->e1246;
  res.e1346 =  + rhs->e1346;
  res.e2346 =  + rhs->e2346;
  res.e1256 =  + rhs->e1256;
  res.e1356 =  + rhs->e1356;
  res.e2356 =  + rhs->e2356;
  res.e1456 =  + rhs->e1456;
  res.e2456 =  + rhs->e2456;
  res.e3456 =  + rhs->e3456;
  res.e1237 =  + rhs->e1237;
  res.e1247 =  + rhs->e1247;
  res.e1347 =  + rhs->e1347;
  res.e2347 =  + rhs->e2347;
  res.e1257 =  + rhs->e1257;
  res.e1357 =  + rhs->e1357;
  res.e2357 =  + rhs->e2357;
  res.e1457 =  + rhs->e1457;
  res.e2457 =  + rhs->e2457;
  res.e3457 =  + rhs->e3457;
  res.e1267 =  + rhs->e1267;
  res.e1367 =  + rhs->e1367;
  res.e2367 =  + rhs->e2367;
  res.e1467 =  + rhs->e1467;
  res.e2467 =  + rhs->e2467;
  res.e3467 =  + rhs->e3467;
  res.e1567 =  + rhs->e1567;
  res.e2567 =  + rhs->e2567;
  res.e3567 =  + rhs->e3567;
  res.e4567 =  + rhs->e4567;
  // Order 5;
  res.e12345 =  + rhs->e12345;
  res.e12346 =  + rhs->e12346;
  res.e12356 =  + rhs->e12356;
  res.e12456 =  + rhs->e12456;
  res.e13456 =  + rhs->e13456;
  res.e23456 =  + rhs->e23456;
  res.e12347 =  + rhs->e12347;
  res.e12357 =  + rhs->e12357;
  res.e12457 =  + rhs->e12457;
  res.e13457 =  + rhs->e13457;
  res.e23457 =  + rhs->e23457;
  res.e12367 =  + rhs->e12367;
  res.e12467 =  + rhs->e12467;
  res.e13467 =  + rhs->e13467;
  res.e23467 =  + rhs->e23467;
  res.e12567 =  + rhs->e12567;
  res.e13567 =  + rhs->e13567;
  res.e23567 =  + rhs->e23567;
  res.e14567 =  + rhs->e14567;
  res.e24567 =  + rhs->e24567;
  res.e34567 =  + rhs->e34567;
  // Order 6;
  res.e123456 =  + rhs->e123456;
  res.e123457 =  + rhs->e123457;
  res.e123467 =  + rhs->e123467;
  res.e123567 =  + rhs->e123567;
  res.e124567 =  + rhs->e124567;
  res.e134567 =  + rhs->e134567;
  res.e234567 =  + rhs->e234567;
  // Order 7;
  res.e1234567 =  + rhs->e1234567;

  return res;

}

void mdnum7_sum_ro_to(  coeff_t lhs,  mdnum7_t* rhs, mdnum7_t* res){
  // Addition like function 'lhs + rhs'
  // Real;
  res->r = lhs + rhs->r;
  // Order 1;
  res->e1 =  + rhs->e1;
  res->e2 =  + rhs->e2;
  res->e3 =  + rhs->e3;
  res->e4 =  + rhs->e4;
  res->e5 =  + rhs->e5;
  res->e6 =  + rhs->e6;
  res->e7 =  + rhs->e7;
  // Order 2;
  res->e12 =  + rhs->e12;
  res->e13 =  + rhs->e13;
  res->e23 =  + rhs->e23;
  res->e14 =  + rhs->e14;
  res->e24 =  + rhs->e24;
  res->e34 =  + rhs->e34;
  res->e15 =  + rhs->e15;
  res->e25 =  + rhs->e25;
  res->e35 =  + rhs->e35;
  res->e45 =  + rhs->e45;
  res->e16 =  + rhs->e16;
  res->e26 =  + rhs->e26;
  res->e36 =  + rhs->e36;
  res->e46 =  + rhs->e46;
  res->e56 =  + rhs->e56;
  res->e17 =  + rhs->e17;
  res->e27 =  + rhs->e27;
  res->e37 =  + rhs->e37;
  res->e47 =  + rhs->e47;
  res->e57 =  + rhs->e57;
  res->e67 =  + rhs->e67;
  // Order 3;
  res->e123 =  + rhs->e123;
  res->e124 =  + rhs->e124;
  res->e134 =  + rhs->e134;
  res->e234 =  + rhs->e234;
  res->e125 =  + rhs->e125;
  res->e135 =  + rhs->e135;
  res->e235 =  + rhs->e235;
  res->e145 =  + rhs->e145;
  res->e245 =  + rhs->e245;
  res->e345 =  + rhs->e345;
  res->e126 =  + rhs->e126;
  res->e136 =  + rhs->e136;
  res->e236 =  + rhs->e236;
  res->e146 =  + rhs->e146;
  res->e246 =  + rhs->e246;
  res->e346 =  + rhs->e346;
  res->e156 =  + rhs->e156;
  res->e256 =  + rhs->e256;
  res->e356 =  + rhs->e356;
  res->e456 =  + rhs->e456;
  res->e127 =  + rhs->e127;
  res->e137 =  + rhs->e137;
  res->e237 =  + rhs->e237;
  res->e147 =  + rhs->e147;
  res->e247 =  + rhs->e247;
  res->e347 =  + rhs->e347;
  res->e157 =  + rhs->e157;
  res->e257 =  + rhs->e257;
  res->e357 =  + rhs->e357;
  res->e457 =  + rhs->e457;
  res->e167 =  + rhs->e167;
  res->e267 =  + rhs->e267;
  res->e367 =  + rhs->e367;
  res->e467 =  + rhs->e467;
  res->e567 =  + rhs->e567;
  // Order 4;
  res->e1234 =  + rhs->e1234;
  res->e1235 =  + rhs->e1235;
  res->e1245 =  + rhs->e1245;
  res->e1345 =  + rhs->e1345;
  res->e2345 =  + rhs->e2345;
  res->e1236 =  + rhs->e1236;
  res->e1246 =  + rhs->e1246;
  res->e1346 =  + rhs->e1346;
  res->e2346 =  + rhs->e2346;
  res->e1256 =  + rhs->e1256;
  res->e1356 =  + rhs->e1356;
  res->e2356 =  + rhs->e2356;
  res->e1456 =  + rhs->e1456;
  res->e2456 =  + rhs->e2456;
  res->e3456 =  + rhs->e3456;
  res->e1237 =  + rhs->e1237;
  res->e1247 =  + rhs->e1247;
  res->e1347 =  + rhs->e1347;
  res->e2347 =  + rhs->e2347;
  res->e1257 =  + rhs->e1257;
  res->e1357 =  + rhs->e1357;
  res->e2357 =  + rhs->e2357;
  res->e1457 =  + rhs->e1457;
  res->e2457 =  + rhs->e2457;
  res->e3457 =  + rhs->e3457;
  res->e1267 =  + rhs->e1267;
  res->e1367 =  + rhs->e1367;
  res->e2367 =  + rhs->e2367;
  res->e1467 =  + rhs->e1467;
  res->e2467 =  + rhs->e2467;
  res->e3467 =  + rhs->e3467;
  res->e1567 =  + rhs->e1567;
  res->e2567 =  + rhs->e2567;
  res->e3567 =  + rhs->e3567;
  res->e4567 =  + rhs->e4567;
  // Order 5;
  res->e12345 =  + rhs->e12345;
  res->e12346 =  + rhs->e12346;
  res->e12356 =  + rhs->e12356;
  res->e12456 =  + rhs->e12456;
  res->e13456 =  + rhs->e13456;
  res->e23456 =  + rhs->e23456;
  res->e12347 =  + rhs->e12347;
  res->e12357 =  + rhs->e12357;
  res->e12457 =  + rhs->e12457;
  res->e13457 =  + rhs->e13457;
  res->e23457 =  + rhs->e23457;
  res->e12367 =  + rhs->e12367;
  res->e12467 =  + rhs->e12467;
  res->e13467 =  + rhs->e13467;
  res->e23467 =  + rhs->e23467;
  res->e12567 =  + rhs->e12567;
  res->e13567 =  + rhs->e13567;
  res->e23567 =  + rhs->e23567;
  res->e14567 =  + rhs->e14567;
  res->e24567 =  + rhs->e24567;
  res->e34567 =  + rhs->e34567;
  // Order 6;
  res->e123456 =  + rhs->e123456;
  res->e123457 =  + rhs->e123457;
  res->e123467 =  + rhs->e123467;
  res->e123567 =  + rhs->e123567;
  res->e124567 =  + rhs->e124567;
  res->e134567 =  + rhs->e134567;
  res->e234567 =  + rhs->e234567;
  // Order 7;
  res->e1234567 =  + rhs->e1234567;

}

mdnum7_t mdnum7_sub_oo(  mdnum7_t* lhs,  mdnum7_t* rhs){
  mdnum7_t res;

  // Addition like function 'lhs - rhs'
  //  Real
  res.r = lhs->r - rhs->r;
  // Order 1
  res.e1 = lhs->e1 - rhs->e1;
  res.e2 = lhs->e2 - rhs->e2;
  res.e3 = lhs->e3 - rhs->e3;
  res.e4 = lhs->e4 - rhs->e4;
  res.e5 = lhs->e5 - rhs->e5;
  res.e6 = lhs->e6 - rhs->e6;
  res.e7 = lhs->e7 - rhs->e7;
  // Order 2
  res.e12 = lhs->e12 - rhs->e12;
  res.e13 = lhs->e13 - rhs->e13;
  res.e23 = lhs->e23 - rhs->e23;
  res.e14 = lhs->e14 - rhs->e14;
  res.e24 = lhs->e24 - rhs->e24;
  res.e34 = lhs->e34 - rhs->e34;
  res.e15 = lhs->e15 - rhs->e15;
  res.e25 = lhs->e25 - rhs->e25;
  res.e35 = lhs->e35 - rhs->e35;
  res.e45 = lhs->e45 - rhs->e45;
  res.e16 = lhs->e16 - rhs->e16;
  res.e26 = lhs->e26 - rhs->e26;
  res.e36 = lhs->e36 - rhs->e36;
  res.e46 = lhs->e46 - rhs->e46;
  res.e56 = lhs->e56 - rhs->e56;
  res.e17 = lhs->e17 - rhs->e17;
  res.e27 = lhs->e27 - rhs->e27;
  res.e37 = lhs->e37 - rhs->e37;
  res.e47 = lhs->e47 - rhs->e47;
  res.e57 = lhs->e57 - rhs->e57;
  res.e67 = lhs->e67 - rhs->e67;
  // Order 3
  res.e123 = lhs->e123 - rhs->e123;
  res.e124 = lhs->e124 - rhs->e124;
  res.e134 = lhs->e134 - rhs->e134;
  res.e234 = lhs->e234 - rhs->e234;
  res.e125 = lhs->e125 - rhs->e125;
  res.e135 = lhs->e135 - rhs->e135;
  res.e235 = lhs->e235 - rhs->e235;
  res.e145 = lhs->e145 - rhs->e145;
  res.e245 = lhs->e245 - rhs->e245;
  res.e345 = lhs->e345 - rhs->e345;
  res.e126 = lhs->e126 - rhs->e126;
  res.e136 = lhs->e136 - rhs->e136;
  res.e236 = lhs->e236 - rhs->e236;
  res.e146 = lhs->e146 - rhs->e146;
  res.e246 = lhs->e246 - rhs->e246;
  res.e346 = lhs->e346 - rhs->e346;
  res.e156 = lhs->e156 - rhs->e156;
  res.e256 = lhs->e256 - rhs->e256;
  res.e356 = lhs->e356 - rhs->e356;
  res.e456 = lhs->e456 - rhs->e456;
  res.e127 = lhs->e127 - rhs->e127;
  res.e137 = lhs->e137 - rhs->e137;
  res.e237 = lhs->e237 - rhs->e237;
  res.e147 = lhs->e147 - rhs->e147;
  res.e247 = lhs->e247 - rhs->e247;
  res.e347 = lhs->e347 - rhs->e347;
  res.e157 = lhs->e157 - rhs->e157;
  res.e257 = lhs->e257 - rhs->e257;
  res.e357 = lhs->e357 - rhs->e357;
  res.e457 = lhs->e457 - rhs->e457;
  res.e167 = lhs->e167 - rhs->e167;
  res.e267 = lhs->e267 - rhs->e267;
  res.e367 = lhs->e367 - rhs->e367;
  res.e467 = lhs->e467 - rhs->e467;
  res.e567 = lhs->e567 - rhs->e567;
  // Order 4
  res.e1234 = lhs->e1234 - rhs->e1234;
  res.e1235 = lhs->e1235 - rhs->e1235;
  res.e1245 = lhs->e1245 - rhs->e1245;
  res.e1345 = lhs->e1345 - rhs->e1345;
  res.e2345 = lhs->e2345 - rhs->e2345;
  res.e1236 = lhs->e1236 - rhs->e1236;
  res.e1246 = lhs->e1246 - rhs->e1246;
  res.e1346 = lhs->e1346 - rhs->e1346;
  res.e2346 = lhs->e2346 - rhs->e2346;
  res.e1256 = lhs->e1256 - rhs->e1256;
  res.e1356 = lhs->e1356 - rhs->e1356;
  res.e2356 = lhs->e2356 - rhs->e2356;
  res.e1456 = lhs->e1456 - rhs->e1456;
  res.e2456 = lhs->e2456 - rhs->e2456;
  res.e3456 = lhs->e3456 - rhs->e3456;
  res.e1237 = lhs->e1237 - rhs->e1237;
  res.e1247 = lhs->e1247 - rhs->e1247;
  res.e1347 = lhs->e1347 - rhs->e1347;
  res.e2347 = lhs->e2347 - rhs->e2347;
  res.e1257 = lhs->e1257 - rhs->e1257;
  res.e1357 = lhs->e1357 - rhs->e1357;
  res.e2357 = lhs->e2357 - rhs->e2357;
  res.e1457 = lhs->e1457 - rhs->e1457;
  res.e2457 = lhs->e2457 - rhs->e2457;
  res.e3457 = lhs->e3457 - rhs->e3457;
  res.e1267 = lhs->e1267 - rhs->e1267;
  res.e1367 = lhs->e1367 - rhs->e1367;
  res.e2367 = lhs->e2367 - rhs->e2367;
  res.e1467 = lhs->e1467 - rhs->e1467;
  res.e2467 = lhs->e2467 - rhs->e2467;
  res.e3467 = lhs->e3467 - rhs->e3467;
  res.e1567 = lhs->e1567 - rhs->e1567;
  res.e2567 = lhs->e2567 - rhs->e2567;
  res.e3567 = lhs->e3567 - rhs->e3567;
  res.e4567 = lhs->e4567 - rhs->e4567;
  // Order 5
  res.e12345 = lhs->e12345 - rhs->e12345;
  res.e12346 = lhs->e12346 - rhs->e12346;
  res.e12356 = lhs->e12356 - rhs->e12356;
  res.e12456 = lhs->e12456 - rhs->e12456;
  res.e13456 = lhs->e13456 - rhs->e13456;
  res.e23456 = lhs->e23456 - rhs->e23456;
  res.e12347 = lhs->e12347 - rhs->e12347;
  res.e12357 = lhs->e12357 - rhs->e12357;
  res.e12457 = lhs->e12457 - rhs->e12457;
  res.e13457 = lhs->e13457 - rhs->e13457;
  res.e23457 = lhs->e23457 - rhs->e23457;
  res.e12367 = lhs->e12367 - rhs->e12367;
  res.e12467 = lhs->e12467 - rhs->e12467;
  res.e13467 = lhs->e13467 - rhs->e13467;
  res.e23467 = lhs->e23467 - rhs->e23467;
  res.e12567 = lhs->e12567 - rhs->e12567;
  res.e13567 = lhs->e13567 - rhs->e13567;
  res.e23567 = lhs->e23567 - rhs->e23567;
  res.e14567 = lhs->e14567 - rhs->e14567;
  res.e24567 = lhs->e24567 - rhs->e24567;
  res.e34567 = lhs->e34567 - rhs->e34567;
  // Order 6
  res.e123456 = lhs->e123456 - rhs->e123456;
  res.e123457 = lhs->e123457 - rhs->e123457;
  res.e123467 = lhs->e123467 - rhs->e123467;
  res.e123567 = lhs->e123567 - rhs->e123567;
  res.e124567 = lhs->e124567 - rhs->e124567;
  res.e134567 = lhs->e134567 - rhs->e134567;
  res.e234567 = lhs->e234567 - rhs->e234567;
  // Order 7
  res.e1234567 = lhs->e1234567 - rhs->e1234567;

  return res;

}

void mdnum7_sub_oo_to(  mdnum7_t* lhs,  mdnum7_t* rhs, mdnum7_t* res){
  // Addition like function 'lhs - rhs'
  //  Real
  res->r = lhs->r - rhs->r;
  // Order 1
  res->e1 = lhs->e1 - rhs->e1;
  res->e2 = lhs->e2 - rhs->e2;
  res->e3 = lhs->e3 - rhs->e3;
  res->e4 = lhs->e4 - rhs->e4;
  res->e5 = lhs->e5 - rhs->e5;
  res->e6 = lhs->e6 - rhs->e6;
  res->e7 = lhs->e7 - rhs->e7;
  // Order 2
  res->e12 = lhs->e12 - rhs->e12;
  res->e13 = lhs->e13 - rhs->e13;
  res->e23 = lhs->e23 - rhs->e23;
  res->e14 = lhs->e14 - rhs->e14;
  res->e24 = lhs->e24 - rhs->e24;
  res->e34 = lhs->e34 - rhs->e34;
  res->e15 = lhs->e15 - rhs->e15;
  res->e25 = lhs->e25 - rhs->e25;
  res->e35 = lhs->e35 - rhs->e35;
  res->e45 = lhs->e45 - rhs->e45;
  res->e16 = lhs->e16 - rhs->e16;
  res->e26 = lhs->e26 - rhs->e26;
  res->e36 = lhs->e36 - rhs->e36;
  res->e46 = lhs->e46 - rhs->e46;
  res->e56 = lhs->e56 - rhs->e56;
  res->e17 = lhs->e17 - rhs->e17;
  res->e27 = lhs->e27 - rhs->e27;
  res->e37 = lhs->e37 - rhs->e37;
  res->e47 = lhs->e47 - rhs->e47;
  res->e57 = lhs->e57 - rhs->e57;
  res->e67 = lhs->e67 - rhs->e67;
  // Order 3
  res->e123 = lhs->e123 - rhs->e123;
  res->e124 = lhs->e124 - rhs->e124;
  res->e134 = lhs->e134 - rhs->e134;
  res->e234 = lhs->e234 - rhs->e234;
  res->e125 = lhs->e125 - rhs->e125;
  res->e135 = lhs->e135 - rhs->e135;
  res->e235 = lhs->e235 - rhs->e235;
  res->e145 = lhs->e145 - rhs->e145;
  res->e245 = lhs->e245 - rhs->e245;
  res->e345 = lhs->e345 - rhs->e345;
  res->e126 = lhs->e126 - rhs->e126;
  res->e136 = lhs->e136 - rhs->e136;
  res->e236 = lhs->e236 - rhs->e236;
  res->e146 = lhs->e146 - rhs->e146;
  res->e246 = lhs->e246 - rhs->e246;
  res->e346 = lhs->e346 - rhs->e346;
  res->e156 = lhs->e156 - rhs->e156;
  res->e256 = lhs->e256 - rhs->e256;
  res->e356 = lhs->e356 - rhs->e356;
  res->e456 = lhs->e456 - rhs->e456;
  res->e127 = lhs->e127 - rhs->e127;
  res->e137 = lhs->e137 - rhs->e137;
  res->e237 = lhs->e237 - rhs->e237;
  res->e147 = lhs->e147 - rhs->e147;
  res->e247 = lhs->e247 - rhs->e247;
  res->e347 = lhs->e347 - rhs->e347;
  res->e157 = lhs->e157 - rhs->e157;
  res->e257 = lhs->e257 - rhs->e257;
  res->e357 = lhs->e357 - rhs->e357;
  res->e457 = lhs->e457 - rhs->e457;
  res->e167 = lhs->e167 - rhs->e167;
  res->e267 = lhs->e267 - rhs->e267;
  res->e367 = lhs->e367 - rhs->e367;
  res->e467 = lhs->e467 - rhs->e467;
  res->e567 = lhs->e567 - rhs->e567;
  // Order 4
  res->e1234 = lhs->e1234 - rhs->e1234;
  res->e1235 = lhs->e1235 - rhs->e1235;
  res->e1245 = lhs->e1245 - rhs->e1245;
  res->e1345 = lhs->e1345 - rhs->e1345;
  res->e2345 = lhs->e2345 - rhs->e2345;
  res->e1236 = lhs->e1236 - rhs->e1236;
  res->e1246 = lhs->e1246 - rhs->e1246;
  res->e1346 = lhs->e1346 - rhs->e1346;
  res->e2346 = lhs->e2346 - rhs->e2346;
  res->e1256 = lhs->e1256 - rhs->e1256;
  res->e1356 = lhs->e1356 - rhs->e1356;
  res->e2356 = lhs->e2356 - rhs->e2356;
  res->e1456 = lhs->e1456 - rhs->e1456;
  res->e2456 = lhs->e2456 - rhs->e2456;
  res->e3456 = lhs->e3456 - rhs->e3456;
  res->e1237 = lhs->e1237 - rhs->e1237;
  res->e1247 = lhs->e1247 - rhs->e1247;
  res->e1347 = lhs->e1347 - rhs->e1347;
  res->e2347 = lhs->e2347 - rhs->e2347;
  res->e1257 = lhs->e1257 - rhs->e1257;
  res->e1357 = lhs->e1357 - rhs->e1357;
  res->e2357 = lhs->e2357 - rhs->e2357;
  res->e1457 = lhs->e1457 - rhs->e1457;
  res->e2457 = lhs->e2457 - rhs->e2457;
  res->e3457 = lhs->e3457 - rhs->e3457;
  res->e1267 = lhs->e1267 - rhs->e1267;
  res->e1367 = lhs->e1367 - rhs->e1367;
  res->e2367 = lhs->e2367 - rhs->e2367;
  res->e1467 = lhs->e1467 - rhs->e1467;
  res->e2467 = lhs->e2467 - rhs->e2467;
  res->e3467 = lhs->e3467 - rhs->e3467;
  res->e1567 = lhs->e1567 - rhs->e1567;
  res->e2567 = lhs->e2567 - rhs->e2567;
  res->e3567 = lhs->e3567 - rhs->e3567;
  res->e4567 = lhs->e4567 - rhs->e4567;
  // Order 5
  res->e12345 = lhs->e12345 - rhs->e12345;
  res->e12346 = lhs->e12346 - rhs->e12346;
  res->e12356 = lhs->e12356 - rhs->e12356;
  res->e12456 = lhs->e12456 - rhs->e12456;
  res->e13456 = lhs->e13456 - rhs->e13456;
  res->e23456 = lhs->e23456 - rhs->e23456;
  res->e12347 = lhs->e12347 - rhs->e12347;
  res->e12357 = lhs->e12357 - rhs->e12357;
  res->e12457 = lhs->e12457 - rhs->e12457;
  res->e13457 = lhs->e13457 - rhs->e13457;
  res->e23457 = lhs->e23457 - rhs->e23457;
  res->e12367 = lhs->e12367 - rhs->e12367;
  res->e12467 = lhs->e12467 - rhs->e12467;
  res->e13467 = lhs->e13467 - rhs->e13467;
  res->e23467 = lhs->e23467 - rhs->e23467;
  res->e12567 = lhs->e12567 - rhs->e12567;
  res->e13567 = lhs->e13567 - rhs->e13567;
  res->e23567 = lhs->e23567 - rhs->e23567;
  res->e14567 = lhs->e14567 - rhs->e14567;
  res->e24567 = lhs->e24567 - rhs->e24567;
  res->e34567 = lhs->e34567 - rhs->e34567;
  // Order 6
  res->e123456 = lhs->e123456 - rhs->e123456;
  res->e123457 = lhs->e123457 - rhs->e123457;
  res->e123467 = lhs->e123467 - rhs->e123467;
  res->e123567 = lhs->e123567 - rhs->e123567;
  res->e124567 = lhs->e124567 - rhs->e124567;
  res->e134567 = lhs->e134567 - rhs->e134567;
  res->e234567 = lhs->e234567 - rhs->e234567;
  // Order 7
  res->e1234567 = lhs->e1234567 - rhs->e1234567;

}

mdnum7_t mdnum7_sub_ro(  coeff_t lhs,  mdnum7_t* rhs){
  mdnum7_t res;

  // Addition like function 'lhs - rhs'
  // Real;
  res.r = lhs - rhs->r;
  // Order 1;
  res.e1 =  - rhs->e1;
  res.e2 =  - rhs->e2;
  res.e3 =  - rhs->e3;
  res.e4 =  - rhs->e4;
  res.e5 =  - rhs->e5;
  res.e6 =  - rhs->e6;
  res.e7 =  - rhs->e7;
  // Order 2;
  res.e12 =  - rhs->e12;
  res.e13 =  - rhs->e13;
  res.e23 =  - rhs->e23;
  res.e14 =  - rhs->e14;
  res.e24 =  - rhs->e24;
  res.e34 =  - rhs->e34;
  res.e15 =  - rhs->e15;
  res.e25 =  - rhs->e25;
  res.e35 =  - rhs->e35;
  res.e45 =  - rhs->e45;
  res.e16 =  - rhs->e16;
  res.e26 =  - rhs->e26;
  res.e36 =  - rhs->e36;
  res.e46 =  - rhs->e46;
  res.e56 =  - rhs->e56;
  res.e17 =  - rhs->e17;
  res.e27 =  - rhs->e27;
  res.e37 =  - rhs->e37;
  res.e47 =  - rhs->e47;
  res.e57 =  - rhs->e57;
  res.e67 =  - rhs->e67;
  // Order 3;
  res.e123 =  - rhs->e123;
  res.e124 =  - rhs->e124;
  res.e134 =  - rhs->e134;
  res.e234 =  - rhs->e234;
  res.e125 =  - rhs->e125;
  res.e135 =  - rhs->e135;
  res.e235 =  - rhs->e235;
  res.e145 =  - rhs->e145;
  res.e245 =  - rhs->e245;
  res.e345 =  - rhs->e345;
  res.e126 =  - rhs->e126;
  res.e136 =  - rhs->e136;
  res.e236 =  - rhs->e236;
  res.e146 =  - rhs->e146;
  res.e246 =  - rhs->e246;
  res.e346 =  - rhs->e346;
  res.e156 =  - rhs->e156;
  res.e256 =  - rhs->e256;
  res.e356 =  - rhs->e356;
  res.e456 =  - rhs->e456;
  res.e127 =  - rhs->e127;
  res.e137 =  - rhs->e137;
  res.e237 =  - rhs->e237;
  res.e147 =  - rhs->e147;
  res.e247 =  - rhs->e247;
  res.e347 =  - rhs->e347;
  res.e157 =  - rhs->e157;
  res.e257 =  - rhs->e257;
  res.e357 =  - rhs->e357;
  res.e457 =  - rhs->e457;
  res.e167 =  - rhs->e167;
  res.e267 =  - rhs->e267;
  res.e367 =  - rhs->e367;
  res.e467 =  - rhs->e467;
  res.e567 =  - rhs->e567;
  // Order 4;
  res.e1234 =  - rhs->e1234;
  res.e1235 =  - rhs->e1235;
  res.e1245 =  - rhs->e1245;
  res.e1345 =  - rhs->e1345;
  res.e2345 =  - rhs->e2345;
  res.e1236 =  - rhs->e1236;
  res.e1246 =  - rhs->e1246;
  res.e1346 =  - rhs->e1346;
  res.e2346 =  - rhs->e2346;
  res.e1256 =  - rhs->e1256;
  res.e1356 =  - rhs->e1356;
  res.e2356 =  - rhs->e2356;
  res.e1456 =  - rhs->e1456;
  res.e2456 =  - rhs->e2456;
  res.e3456 =  - rhs->e3456;
  res.e1237 =  - rhs->e1237;
  res.e1247 =  - rhs->e1247;
  res.e1347 =  - rhs->e1347;
  res.e2347 =  - rhs->e2347;
  res.e1257 =  - rhs->e1257;
  res.e1357 =  - rhs->e1357;
  res.e2357 =  - rhs->e2357;
  res.e1457 =  - rhs->e1457;
  res.e2457 =  - rhs->e2457;
  res.e3457 =  - rhs->e3457;
  res.e1267 =  - rhs->e1267;
  res.e1367 =  - rhs->e1367;
  res.e2367 =  - rhs->e2367;
  res.e1467 =  - rhs->e1467;
  res.e2467 =  - rhs->e2467;
  res.e3467 =  - rhs->e3467;
  res.e1567 =  - rhs->e1567;
  res.e2567 =  - rhs->e2567;
  res.e3567 =  - rhs->e3567;
  res.e4567 =  - rhs->e4567;
  // Order 5;
  res.e12345 =  - rhs->e12345;
  res.e12346 =  - rhs->e12346;
  res.e12356 =  - rhs->e12356;
  res.e12456 =  - rhs->e12456;
  res.e13456 =  - rhs->e13456;
  res.e23456 =  - rhs->e23456;
  res.e12347 =  - rhs->e12347;
  res.e12357 =  - rhs->e12357;
  res.e12457 =  - rhs->e12457;
  res.e13457 =  - rhs->e13457;
  res.e23457 =  - rhs->e23457;
  res.e12367 =  - rhs->e12367;
  res.e12467 =  - rhs->e12467;
  res.e13467 =  - rhs->e13467;
  res.e23467 =  - rhs->e23467;
  res.e12567 =  - rhs->e12567;
  res.e13567 =  - rhs->e13567;
  res.e23567 =  - rhs->e23567;
  res.e14567 =  - rhs->e14567;
  res.e24567 =  - rhs->e24567;
  res.e34567 =  - rhs->e34567;
  // Order 6;
  res.e123456 =  - rhs->e123456;
  res.e123457 =  - rhs->e123457;
  res.e123467 =  - rhs->e123467;
  res.e123567 =  - rhs->e123567;
  res.e124567 =  - rhs->e124567;
  res.e134567 =  - rhs->e134567;
  res.e234567 =  - rhs->e234567;
  // Order 7;
  res.e1234567 =  - rhs->e1234567;

  return res;

}

void mdnum7_sub_ro_to(  coeff_t lhs,  mdnum7_t* rhs, mdnum7_t* res){
  // Addition like function 'lhs - rhs'
  // Real;
  res->r = lhs - rhs->r;
  // Order 1;
  res->e1 =  - rhs->e1;
  res->e2 =  - rhs->e2;
  res->e3 =  - rhs->e3;
  res->e4 =  - rhs->e4;
  res->e5 =  - rhs->e5;
  res->e6 =  - rhs->e6;
  res->e7 =  - rhs->e7;
  // Order 2;
  res->e12 =  - rhs->e12;
  res->e13 =  - rhs->e13;
  res->e23 =  - rhs->e23;
  res->e14 =  - rhs->e14;
  res->e24 =  - rhs->e24;
  res->e34 =  - rhs->e34;
  res->e15 =  - rhs->e15;
  res->e25 =  - rhs->e25;
  res->e35 =  - rhs->e35;
  res->e45 =  - rhs->e45;
  res->e16 =  - rhs->e16;
  res->e26 =  - rhs->e26;
  res->e36 =  - rhs->e36;
  res->e46 =  - rhs->e46;
  res->e56 =  - rhs->e56;
  res->e17 =  - rhs->e17;
  res->e27 =  - rhs->e27;
  res->e37 =  - rhs->e37;
  res->e47 =  - rhs->e47;
  res->e57 =  - rhs->e57;
  res->e67 =  - rhs->e67;
  // Order 3;
  res->e123 =  - rhs->e123;
  res->e124 =  - rhs->e124;
  res->e134 =  - rhs->e134;
  res->e234 =  - rhs->e234;
  res->e125 =  - rhs->e125;
  res->e135 =  - rhs->e135;
  res->e235 =  - rhs->e235;
  res->e145 =  - rhs->e145;
  res->e245 =  - rhs->e245;
  res->e345 =  - rhs->e345;
  res->e126 =  - rhs->e126;
  res->e136 =  - rhs->e136;
  res->e236 =  - rhs->e236;
  res->e146 =  - rhs->e146;
  res->e246 =  - rhs->e246;
  res->e346 =  - rhs->e346;
  res->e156 =  - rhs->e156;
  res->e256 =  - rhs->e256;
  res->e356 =  - rhs->e356;
  res->e456 =  - rhs->e456;
  res->e127 =  - rhs->e127;
  res->e137 =  - rhs->e137;
  res->e237 =  - rhs->e237;
  res->e147 =  - rhs->e147;
  res->e247 =  - rhs->e247;
  res->e347 =  - rhs->e347;
  res->e157 =  - rhs->e157;
  res->e257 =  - rhs->e257;
  res->e357 =  - rhs->e357;
  res->e457 =  - rhs->e457;
  res->e167 =  - rhs->e167;
  res->e267 =  - rhs->e267;
  res->e367 =  - rhs->e367;
  res->e467 =  - rhs->e467;
  res->e567 =  - rhs->e567;
  // Order 4;
  res->e1234 =  - rhs->e1234;
  res->e1235 =  - rhs->e1235;
  res->e1245 =  - rhs->e1245;
  res->e1345 =  - rhs->e1345;
  res->e2345 =  - rhs->e2345;
  res->e1236 =  - rhs->e1236;
  res->e1246 =  - rhs->e1246;
  res->e1346 =  - rhs->e1346;
  res->e2346 =  - rhs->e2346;
  res->e1256 =  - rhs->e1256;
  res->e1356 =  - rhs->e1356;
  res->e2356 =  - rhs->e2356;
  res->e1456 =  - rhs->e1456;
  res->e2456 =  - rhs->e2456;
  res->e3456 =  - rhs->e3456;
  res->e1237 =  - rhs->e1237;
  res->e1247 =  - rhs->e1247;
  res->e1347 =  - rhs->e1347;
  res->e2347 =  - rhs->e2347;
  res->e1257 =  - rhs->e1257;
  res->e1357 =  - rhs->e1357;
  res->e2357 =  - rhs->e2357;
  res->e1457 =  - rhs->e1457;
  res->e2457 =  - rhs->e2457;
  res->e3457 =  - rhs->e3457;
  res->e1267 =  - rhs->e1267;
  res->e1367 =  - rhs->e1367;
  res->e2367 =  - rhs->e2367;
  res->e1467 =  - rhs->e1467;
  res->e2467 =  - rhs->e2467;
  res->e3467 =  - rhs->e3467;
  res->e1567 =  - rhs->e1567;
  res->e2567 =  - rhs->e2567;
  res->e3567 =  - rhs->e3567;
  res->e4567 =  - rhs->e4567;
  // Order 5;
  res->e12345 =  - rhs->e12345;
  res->e12346 =  - rhs->e12346;
  res->e12356 =  - rhs->e12356;
  res->e12456 =  - rhs->e12456;
  res->e13456 =  - rhs->e13456;
  res->e23456 =  - rhs->e23456;
  res->e12347 =  - rhs->e12347;
  res->e12357 =  - rhs->e12357;
  res->e12457 =  - rhs->e12457;
  res->e13457 =  - rhs->e13457;
  res->e23457 =  - rhs->e23457;
  res->e12367 =  - rhs->e12367;
  res->e12467 =  - rhs->e12467;
  res->e13467 =  - rhs->e13467;
  res->e23467 =  - rhs->e23467;
  res->e12567 =  - rhs->e12567;
  res->e13567 =  - rhs->e13567;
  res->e23567 =  - rhs->e23567;
  res->e14567 =  - rhs->e14567;
  res->e24567 =  - rhs->e24567;
  res->e34567 =  - rhs->e34567;
  // Order 6;
  res->e123456 =  - rhs->e123456;
  res->e123457 =  - rhs->e123457;
  res->e123467 =  - rhs->e123467;
  res->e123567 =  - rhs->e123567;
  res->e124567 =  - rhs->e124567;
  res->e134567 =  - rhs->e134567;
  res->e234567 =  - rhs->e234567;
  // Order 7;
  res->e1234567 =  - rhs->e1234567;

}

mdnum7_t mdnum7_sub_or(  mdnum7_t* lhs,  coeff_t rhs){
  mdnum7_t res;

  // Addition like function 'lhs - rhs'
  // Real;
  res.r = lhs->r - rhs;
  // Order 1;
  res.e1 = lhs->e1;
  res.e2 = lhs->e2;
  res.e3 = lhs->e3;
  res.e4 = lhs->e4;
  res.e5 = lhs->e5;
  res.e6 = lhs->e6;
  res.e7 = lhs->e7;
  // Order 2;
  res.e12 = lhs->e12;
  res.e13 = lhs->e13;
  res.e23 = lhs->e23;
  res.e14 = lhs->e14;
  res.e24 = lhs->e24;
  res.e34 = lhs->e34;
  res.e15 = lhs->e15;
  res.e25 = lhs->e25;
  res.e35 = lhs->e35;
  res.e45 = lhs->e45;
  res.e16 = lhs->e16;
  res.e26 = lhs->e26;
  res.e36 = lhs->e36;
  res.e46 = lhs->e46;
  res.e56 = lhs->e56;
  res.e17 = lhs->e17;
  res.e27 = lhs->e27;
  res.e37 = lhs->e37;
  res.e47 = lhs->e47;
  res.e57 = lhs->e57;
  res.e67 = lhs->e67;
  // Order 3;
  res.e123 = lhs->e123;
  res.e124 = lhs->e124;
  res.e134 = lhs->e134;
  res.e234 = lhs->e234;
  res.e125 = lhs->e125;
  res.e135 = lhs->e135;
  res.e235 = lhs->e235;
  res.e145 = lhs->e145;
  res.e245 = lhs->e245;
  res.e345 = lhs->e345;
  res.e126 = lhs->e126;
  res.e136 = lhs->e136;
  res.e236 = lhs->e236;
  res.e146 = lhs->e146;
  res.e246 = lhs->e246;
  res.e346 = lhs->e346;
  res.e156 = lhs->e156;
  res.e256 = lhs->e256;
  res.e356 = lhs->e356;
  res.e456 = lhs->e456;
  res.e127 = lhs->e127;
  res.e137 = lhs->e137;
  res.e237 = lhs->e237;
  res.e147 = lhs->e147;
  res.e247 = lhs->e247;
  res.e347 = lhs->e347;
  res.e157 = lhs->e157;
  res.e257 = lhs->e257;
  res.e357 = lhs->e357;
  res.e457 = lhs->e457;
  res.e167 = lhs->e167;
  res.e267 = lhs->e267;
  res.e367 = lhs->e367;
  res.e467 = lhs->e467;
  res.e567 = lhs->e567;
  // Order 4;
  res.e1234 = lhs->e1234;
  res.e1235 = lhs->e1235;
  res.e1245 = lhs->e1245;
  res.e1345 = lhs->e1345;
  res.e2345 = lhs->e2345;
  res.e1236 = lhs->e1236;
  res.e1246 = lhs->e1246;
  res.e1346 = lhs->e1346;
  res.e2346 = lhs->e2346;
  res.e1256 = lhs->e1256;
  res.e1356 = lhs->e1356;
  res.e2356 = lhs->e2356;
  res.e1456 = lhs->e1456;
  res.e2456 = lhs->e2456;
  res.e3456 = lhs->e3456;
  res.e1237 = lhs->e1237;
  res.e1247 = lhs->e1247;
  res.e1347 = lhs->e1347;
  res.e2347 = lhs->e2347;
  res.e1257 = lhs->e1257;
  res.e1357 = lhs->e1357;
  res.e2357 = lhs->e2357;
  res.e1457 = lhs->e1457;
  res.e2457 = lhs->e2457;
  res.e3457 = lhs->e3457;
  res.e1267 = lhs->e1267;
  res.e1367 = lhs->e1367;
  res.e2367 = lhs->e2367;
  res.e1467 = lhs->e1467;
  res.e2467 = lhs->e2467;
  res.e3467 = lhs->e3467;
  res.e1567 = lhs->e1567;
  res.e2567 = lhs->e2567;
  res.e3567 = lhs->e3567;
  res.e4567 = lhs->e4567;
  // Order 5;
  res.e12345 = lhs->e12345;
  res.e12346 = lhs->e12346;
  res.e12356 = lhs->e12356;
  res.e12456 = lhs->e12456;
  res.e13456 = lhs->e13456;
  res.e23456 = lhs->e23456;
  res.e12347 = lhs->e12347;
  res.e12357 = lhs->e12357;
  res.e12457 = lhs->e12457;
  res.e13457 = lhs->e13457;
  res.e23457 = lhs->e23457;
  res.e12367 = lhs->e12367;
  res.e12467 = lhs->e12467;
  res.e13467 = lhs->e13467;
  res.e23467 = lhs->e23467;
  res.e12567 = lhs->e12567;
  res.e13567 = lhs->e13567;
  res.e23567 = lhs->e23567;
  res.e14567 = lhs->e14567;
  res.e24567 = lhs->e24567;
  res.e34567 = lhs->e34567;
  // Order 6;
  res.e123456 = lhs->e123456;
  res.e123457 = lhs->e123457;
  res.e123467 = lhs->e123467;
  res.e123567 = lhs->e123567;
  res.e124567 = lhs->e124567;
  res.e134567 = lhs->e134567;
  res.e234567 = lhs->e234567;
  // Order 7;
  res.e1234567 = lhs->e1234567;

  return res;

}

void mdnum7_sub_or_to(  mdnum7_t* lhs,  coeff_t rhs, mdnum7_t* res){
  // Addition like function 'lhs - rhs'
  // Real;
  res->r = lhs->r - rhs;
  // Order 1;
  res->e1 = lhs->e1;
  res->e2 = lhs->e2;
  res->e3 = lhs->e3;
  res->e4 = lhs->e4;
  res->e5 = lhs->e5;
  res->e6 = lhs->e6;
  res->e7 = lhs->e7;
  // Order 2;
  res->e12 = lhs->e12;
  res->e13 = lhs->e13;
  res->e23 = lhs->e23;
  res->e14 = lhs->e14;
  res->e24 = lhs->e24;
  res->e34 = lhs->e34;
  res->e15 = lhs->e15;
  res->e25 = lhs->e25;
  res->e35 = lhs->e35;
  res->e45 = lhs->e45;
  res->e16 = lhs->e16;
  res->e26 = lhs->e26;
  res->e36 = lhs->e36;
  res->e46 = lhs->e46;
  res->e56 = lhs->e56;
  res->e17 = lhs->e17;
  res->e27 = lhs->e27;
  res->e37 = lhs->e37;
  res->e47 = lhs->e47;
  res->e57 = lhs->e57;
  res->e67 = lhs->e67;
  // Order 3;
  res->e123 = lhs->e123;
  res->e124 = lhs->e124;
  res->e134 = lhs->e134;
  res->e234 = lhs->e234;
  res->e125 = lhs->e125;
  res->e135 = lhs->e135;
  res->e235 = lhs->e235;
  res->e145 = lhs->e145;
  res->e245 = lhs->e245;
  res->e345 = lhs->e345;
  res->e126 = lhs->e126;
  res->e136 = lhs->e136;
  res->e236 = lhs->e236;
  res->e146 = lhs->e146;
  res->e246 = lhs->e246;
  res->e346 = lhs->e346;
  res->e156 = lhs->e156;
  res->e256 = lhs->e256;
  res->e356 = lhs->e356;
  res->e456 = lhs->e456;
  res->e127 = lhs->e127;
  res->e137 = lhs->e137;
  res->e237 = lhs->e237;
  res->e147 = lhs->e147;
  res->e247 = lhs->e247;
  res->e347 = lhs->e347;
  res->e157 = lhs->e157;
  res->e257 = lhs->e257;
  res->e357 = lhs->e357;
  res->e457 = lhs->e457;
  res->e167 = lhs->e167;
  res->e267 = lhs->e267;
  res->e367 = lhs->e367;
  res->e467 = lhs->e467;
  res->e567 = lhs->e567;
  // Order 4;
  res->e1234 = lhs->e1234;
  res->e1235 = lhs->e1235;
  res->e1245 = lhs->e1245;
  res->e1345 = lhs->e1345;
  res->e2345 = lhs->e2345;
  res->e1236 = lhs->e1236;
  res->e1246 = lhs->e1246;
  res->e1346 = lhs->e1346;
  res->e2346 = lhs->e2346;
  res->e1256 = lhs->e1256;
  res->e1356 = lhs->e1356;
  res->e2356 = lhs->e2356;
  res->e1456 = lhs->e1456;
  res->e2456 = lhs->e2456;
  res->e3456 = lhs->e3456;
  res->e1237 = lhs->e1237;
  res->e1247 = lhs->e1247;
  res->e1347 = lhs->e1347;
  res->e2347 = lhs->e2347;
  res->e1257 = lhs->e1257;
  res->e1357 = lhs->e1357;
  res->e2357 = lhs->e2357;
  res->e1457 = lhs->e1457;
  res->e2457 = lhs->e2457;
  res->e3457 = lhs->e3457;
  res->e1267 = lhs->e1267;
  res->e1367 = lhs->e1367;
  res->e2367 = lhs->e2367;
  res->e1467 = lhs->e1467;
  res->e2467 = lhs->e2467;
  res->e3467 = lhs->e3467;
  res->e1567 = lhs->e1567;
  res->e2567 = lhs->e2567;
  res->e3567 = lhs->e3567;
  res->e4567 = lhs->e4567;
  // Order 5;
  res->e12345 = lhs->e12345;
  res->e12346 = lhs->e12346;
  res->e12356 = lhs->e12356;
  res->e12456 = lhs->e12456;
  res->e13456 = lhs->e13456;
  res->e23456 = lhs->e23456;
  res->e12347 = lhs->e12347;
  res->e12357 = lhs->e12357;
  res->e12457 = lhs->e12457;
  res->e13457 = lhs->e13457;
  res->e23457 = lhs->e23457;
  res->e12367 = lhs->e12367;
  res->e12467 = lhs->e12467;
  res->e13467 = lhs->e13467;
  res->e23467 = lhs->e23467;
  res->e12567 = lhs->e12567;
  res->e13567 = lhs->e13567;
  res->e23567 = lhs->e23567;
  res->e14567 = lhs->e14567;
  res->e24567 = lhs->e24567;
  res->e34567 = lhs->e34567;
  // Order 6;
  res->e123456 = lhs->e123456;
  res->e123457 = lhs->e123457;
  res->e123467 = lhs->e123467;
  res->e123567 = lhs->e123567;
  res->e124567 = lhs->e124567;
  res->e134567 = lhs->e134567;
  res->e234567 = lhs->e234567;
  // Order 7;
  res->e1234567 = lhs->e1234567;

}

mdnum7_t mdnum7_mul_oo(  mdnum7_t* lhs,  mdnum7_t* rhs){
  mdnum7_t res;

  //  Multiplication like function 'lhs * rhs'
  // Real;
  res.r = lhs->r * rhs->r;
  // Order 1;
  res.e1 = lhs->r * rhs->e1 + lhs->e1 * rhs->r;
  res.e2 = lhs->r * rhs->e2 + lhs->e2 * rhs->r;
  res.e3 = lhs->r * rhs->e3 + lhs->e3 * rhs->r;
  res.e4 = lhs->r * rhs->e4 + lhs->e4 * rhs->r;
  res.e5 = lhs->r * rhs->e5 + lhs->e5 * rhs->r;
  res.e6 = lhs->r * rhs->e6 + lhs->e6 * rhs->r;
  res.e7 = lhs->r * rhs->e7 + lhs->e7 * rhs->r;
  // Order 2;
  res.e12 = lhs->r * rhs->e12 + lhs->e12 * rhs->r + lhs->e1 * rhs->e2 
          + lhs->e2 * rhs->e1;
  res.e13 = lhs->r * rhs->e13 + lhs->e13 * rhs->r + lhs->e1 * rhs->e3 
          + lhs->e3 * rhs->e1;
  res.e23 = lhs->r * rhs->e23 + lhs->e23 * rhs->r + lhs->e2 * rhs->e3 
          + lhs->e3 * rhs->e2;
  res.e14 = lhs->r * rhs->e14 + lhs->e14 * rhs->r + lhs->e1 * rhs->e4 
          + lhs->e4 * rhs->e1;
  res.e24 = lhs->r * rhs->e24 + lhs->e24 * rhs->r + lhs->e2 * rhs->e4 
          + lhs->e4 * rhs->e2;
  res.e34 = lhs->r * rhs->e34 + lhs->e34 * rhs->r + lhs->e3 * rhs->e4 
          + lhs->e4 * rhs->e3;
  res.e15 = lhs->r * rhs->e15 + lhs->e15 * rhs->r + lhs->e1 * rhs->e5 
          + lhs->e5 * rhs->e1;
  res.e25 = lhs->r * rhs->e25 + lhs->e25 * rhs->r + lhs->e2 * rhs->e5 
          + lhs->e5 * rhs->e2;
  res.e35 = lhs->r * rhs->e35 + lhs->e35 * rhs->r + lhs->e3 * rhs->e5 
          + lhs->e5 * rhs->e3;
  res.e45 = lhs->r * rhs->e45 + lhs->e45 * rhs->r + lhs->e4 * rhs->e5 
          + lhs->e5 * rhs->e4;
  res.e16 = lhs->r * rhs->e16 + lhs->e16 * rhs->r + lhs->e1 * rhs->e6 
          + lhs->e6 * rhs->e1;
  res.e26 = lhs->r * rhs->e26 + lhs->e26 * rhs->r + lhs->e2 * rhs->e6 
          + lhs->e6 * rhs->e2;
  res.e36 = lhs->r * rhs->e36 + lhs->e36 * rhs->r + lhs->e3 * rhs->e6 
          + lhs->e6 * rhs->e3;
  res.e46 = lhs->r * rhs->e46 + lhs->e46 * rhs->r + lhs->e4 * rhs->e6 
          + lhs->e6 * rhs->e4;
  res.e56 = lhs->r * rhs->e56 + lhs->e56 * rhs->r + lhs->e5 * rhs->e6 
          + lhs->e6 * rhs->e5;
  res.e17 = lhs->r * rhs->e17 + lhs->e17 * rhs->r + lhs->e1 * rhs->e7 
          + lhs->e7 * rhs->e1;
  res.e27 = lhs->r * rhs->e27 + lhs->e27 * rhs->r + lhs->e2 * rhs->e7 
          + lhs->e7 * rhs->e2;
  res.e37 = lhs->r * rhs->e37 + lhs->e37 * rhs->r + lhs->e3 * rhs->e7 
          + lhs->e7 * rhs->e3;
  res.e47 = lhs->r * rhs->e47 + lhs->e47 * rhs->r + lhs->e4 * rhs->e7 
          + lhs->e7 * rhs->e4;
  res.e57 = lhs->r * rhs->e57 + lhs->e57 * rhs->r + lhs->e5 * rhs->e7 
          + lhs->e7 * rhs->e5;
  res.e67 = lhs->r * rhs->e67 + lhs->e67 * rhs->r + lhs->e6 * rhs->e7 
          + lhs->e7 * rhs->e6;
  // Order 3;
  res.e123 = lhs->r * rhs->e123 + lhs->e123 * rhs->r + lhs->e1 * rhs->e23 
           + lhs->e23 * rhs->e1 + lhs->e2 * rhs->e13 + lhs->e13 * rhs->e2 
           + lhs->e3 * rhs->e12 + lhs->e12 * rhs->e3;
  res.e124 = lhs->r * rhs->e124 + lhs->e124 * rhs->r + lhs->e1 * rhs->e24 
           + lhs->e24 * rhs->e1 + lhs->e2 * rhs->e14 + lhs->e14 * rhs->e2 
           + lhs->e4 * rhs->e12 + lhs->e12 * rhs->e4;
  res.e134 = lhs->r * rhs->e134 + lhs->e134 * rhs->r + lhs->e1 * rhs->e34 
           + lhs->e34 * rhs->e1 + lhs->e3 * rhs->e14 + lhs->e14 * rhs->e3 
           + lhs->e4 * rhs->e13 + lhs->e13 * rhs->e4;
  res.e234 = lhs->r * rhs->e234 + lhs->e234 * rhs->r + lhs->e2 * rhs->e34 
           + lhs->e34 * rhs->e2 + lhs->e3 * rhs->e24 + lhs->e24 * rhs->e3 
           + lhs->e4 * rhs->e23 + lhs->e23 * rhs->e4;
  res.e125 = lhs->r * rhs->e125 + lhs->e125 * rhs->r + lhs->e1 * rhs->e25 
           + lhs->e25 * rhs->e1 + lhs->e2 * rhs->e15 + lhs->e15 * rhs->e2 
           + lhs->e5 * rhs->e12 + lhs->e12 * rhs->e5;
  res.e135 = lhs->r * rhs->e135 + lhs->e135 * rhs->r + lhs->e1 * rhs->e35 
           + lhs->e35 * rhs->e1 + lhs->e3 * rhs->e15 + lhs->e15 * rhs->e3 
           + lhs->e5 * rhs->e13 + lhs->e13 * rhs->e5;
  res.e235 = lhs->r * rhs->e235 + lhs->e235 * rhs->r + lhs->e2 * rhs->e35 
           + lhs->e35 * rhs->e2 + lhs->e3 * rhs->e25 + lhs->e25 * rhs->e3 
           + lhs->e5 * rhs->e23 + lhs->e23 * rhs->e5;
  res.e145 = lhs->r * rhs->e145 + lhs->e145 * rhs->r + lhs->e1 * rhs->e45 
           + lhs->e45 * rhs->e1 + lhs->e4 * rhs->e15 + lhs->e15 * rhs->e4 
           + lhs->e5 * rhs->e14 + lhs->e14 * rhs->e5;
  res.e245 = lhs->r * rhs->e245 + lhs->e245 * rhs->r + lhs->e2 * rhs->e45 
           + lhs->e45 * rhs->e2 + lhs->e4 * rhs->e25 + lhs->e25 * rhs->e4 
           + lhs->e5 * rhs->e24 + lhs->e24 * rhs->e5;
  res.e345 = lhs->r * rhs->e345 + lhs->e345 * rhs->r + lhs->e3 * rhs->e45 
           + lhs->e45 * rhs->e3 + lhs->e4 * rhs->e35 + lhs->e35 * rhs->e4 
           + lhs->e5 * rhs->e34 + lhs->e34 * rhs->e5;
  res.e126 = lhs->r * rhs->e126 + lhs->e126 * rhs->r + lhs->e1 * rhs->e26 
           + lhs->e26 * rhs->e1 + lhs->e2 * rhs->e16 + lhs->e16 * rhs->e2 
           + lhs->e6 * rhs->e12 + lhs->e12 * rhs->e6;
  res.e136 = lhs->r * rhs->e136 + lhs->e136 * rhs->r + lhs->e1 * rhs->e36 
           + lhs->e36 * rhs->e1 + lhs->e3 * rhs->e16 + lhs->e16 * rhs->e3 
           + lhs->e6 * rhs->e13 + lhs->e13 * rhs->e6;
  res.e236 = lhs->r * rhs->e236 + lhs->e236 * rhs->r + lhs->e2 * rhs->e36 
           + lhs->e36 * rhs->e2 + lhs->e3 * rhs->e26 + lhs->e26 * rhs->e3 
           + lhs->e6 * rhs->e23 + lhs->e23 * rhs->e6;
  res.e146 = lhs->r * rhs->e146 + lhs->e146 * rhs->r + lhs->e1 * rhs->e46 
           + lhs->e46 * rhs->e1 + lhs->e4 * rhs->e16 + lhs->e16 * rhs->e4 
           + lhs->e6 * rhs->e14 + lhs->e14 * rhs->e6;
  res.e246 = lhs->r * rhs->e246 + lhs->e246 * rhs->r + lhs->e2 * rhs->e46 
           + lhs->e46 * rhs->e2 + lhs->e4 * rhs->e26 + lhs->e26 * rhs->e4 
           + lhs->e6 * rhs->e24 + lhs->e24 * rhs->e6;
  res.e346 = lhs->r * rhs->e346 + lhs->e346 * rhs->r + lhs->e3 * rhs->e46 
           + lhs->e46 * rhs->e3 + lhs->e4 * rhs->e36 + lhs->e36 * rhs->e4 
           + lhs->e6 * rhs->e34 + lhs->e34 * rhs->e6;
  res.e156 = lhs->r * rhs->e156 + lhs->e156 * rhs->r + lhs->e1 * rhs->e56 
           + lhs->e56 * rhs->e1 + lhs->e5 * rhs->e16 + lhs->e16 * rhs->e5 
           + lhs->e6 * rhs->e15 + lhs->e15 * rhs->e6;
  res.e256 = lhs->r * rhs->e256 + lhs->e256 * rhs->r + lhs->e2 * rhs->e56 
           + lhs->e56 * rhs->e2 + lhs->e5 * rhs->e26 + lhs->e26 * rhs->e5 
           + lhs->e6 * rhs->e25 + lhs->e25 * rhs->e6;
  res.e356 = lhs->r * rhs->e356 + lhs->e356 * rhs->r + lhs->e3 * rhs->e56 
           + lhs->e56 * rhs->e3 + lhs->e5 * rhs->e36 + lhs->e36 * rhs->e5 
           + lhs->e6 * rhs->e35 + lhs->e35 * rhs->e6;
  res.e456 = lhs->r * rhs->e456 + lhs->e456 * rhs->r + lhs->e4 * rhs->e56 
           + lhs->e56 * rhs->e4 + lhs->e5 * rhs->e46 + lhs->e46 * rhs->e5 
           + lhs->e6 * rhs->e45 + lhs->e45 * rhs->e6;
  res.e127 = lhs->r * rhs->e127 + lhs->e127 * rhs->r + lhs->e1 * rhs->e27 
           + lhs->e27 * rhs->e1 + lhs->e2 * rhs->e17 + lhs->e17 * rhs->e2 
           + lhs->e7 * rhs->e12 + lhs->e12 * rhs->e7;
  res.e137 = lhs->r * rhs->e137 + lhs->e137 * rhs->r + lhs->e1 * rhs->e37 
           + lhs->e37 * rhs->e1 + lhs->e3 * rhs->e17 + lhs->e17 * rhs->e3 
           + lhs->e7 * rhs->e13 + lhs->e13 * rhs->e7;
  res.e237 = lhs->r * rhs->e237 + lhs->e237 * rhs->r + lhs->e2 * rhs->e37 
           + lhs->e37 * rhs->e2 + lhs->e3 * rhs->e27 + lhs->e27 * rhs->e3 
           + lhs->e7 * rhs->e23 + lhs->e23 * rhs->e7;
  res.e147 = lhs->r * rhs->e147 + lhs->e147 * rhs->r + lhs->e1 * rhs->e47 
           + lhs->e47 * rhs->e1 + lhs->e4 * rhs->e17 + lhs->e17 * rhs->e4 
           + lhs->e7 * rhs->e14 + lhs->e14 * rhs->e7;
  res.e247 = lhs->r * rhs->e247 + lhs->e247 * rhs->r + lhs->e2 * rhs->e47 
           + lhs->e47 * rhs->e2 + lhs->e4 * rhs->e27 + lhs->e27 * rhs->e4 
           + lhs->e7 * rhs->e24 + lhs->e24 * rhs->e7;
  res.e347 = lhs->r * rhs->e347 + lhs->e347 * rhs->r + lhs->e3 * rhs->e47 
           + lhs->e47 * rhs->e3 + lhs->e4 * rhs->e37 + lhs->e37 * rhs->e4 
           + lhs->e7 * rhs->e34 + lhs->e34 * rhs->e7;
  res.e157 = lhs->r * rhs->e157 + lhs->e157 * rhs->r + lhs->e1 * rhs->e57 
           + lhs->e57 * rhs->e1 + lhs->e5 * rhs->e17 + lhs->e17 * rhs->e5 
           + lhs->e7 * rhs->e15 + lhs->e15 * rhs->e7;
  res.e257 = lhs->r * rhs->e257 + lhs->e257 * rhs->r + lhs->e2 * rhs->e57 
           + lhs->e57 * rhs->e2 + lhs->e5 * rhs->e27 + lhs->e27 * rhs->e5 
           + lhs->e7 * rhs->e25 + lhs->e25 * rhs->e7;
  res.e357 = lhs->r * rhs->e357 + lhs->e357 * rhs->r + lhs->e3 * rhs->e57 
           + lhs->e57 * rhs->e3 + lhs->e5 * rhs->e37 + lhs->e37 * rhs->e5 
           + lhs->e7 * rhs->e35 + lhs->e35 * rhs->e7;
  res.e457 = lhs->r * rhs->e457 + lhs->e457 * rhs->r + lhs->e4 * rhs->e57 
           + lhs->e57 * rhs->e4 + lhs->e5 * rhs->e47 + lhs->e47 * rhs->e5 
           + lhs->e7 * rhs->e45 + lhs->e45 * rhs->e7;
  res.e167 = lhs->r * rhs->e167 + lhs->e167 * rhs->r + lhs->e1 * rhs->e67 
           + lhs->e67 * rhs->e1 + lhs->e6 * rhs->e17 + lhs->e17 * rhs->e6 
           + lhs->e7 * rhs->e16 + lhs->e16 * rhs->e7;
  res.e267 = lhs->r * rhs->e267 + lhs->e267 * rhs->r + lhs->e2 * rhs->e67 
           + lhs->e67 * rhs->e2 + lhs->e6 * rhs->e27 + lhs->e27 * rhs->e6 
           + lhs->e7 * rhs->e26 + lhs->e26 * rhs->e7;
  res.e367 = lhs->r * rhs->e367 + lhs->e367 * rhs->r + lhs->e3 * rhs->e67 
           + lhs->e67 * rhs->e3 + lhs->e6 * rhs->e37 + lhs->e37 * rhs->e6 
           + lhs->e7 * rhs->e36 + lhs->e36 * rhs->e7;
  res.e467 = lhs->r * rhs->e467 + lhs->e467 * rhs->r + lhs->e4 * rhs->e67 
           + lhs->e67 * rhs->e4 + lhs->e6 * rhs->e47 + lhs->e47 * rhs->e6 
           + lhs->e7 * rhs->e46 + lhs->e46 * rhs->e7;
  res.e567 = lhs->r * rhs->e567 + lhs->e567 * rhs->r + lhs->e5 * rhs->e67 
           + lhs->e67 * rhs->e5 + lhs->e6 * rhs->e57 + lhs->e57 * rhs->e6 
           + lhs->e7 * rhs->e56 + lhs->e56 * rhs->e7;
  // Order 4;
  res.e1234 = lhs->r * rhs->e1234 + lhs->e1234 * rhs->r + lhs->e1 * rhs->e234 
            + lhs->e234 * rhs->e1 + lhs->e2 * rhs->e134 + lhs->e134 * rhs->e2 
            + lhs->e3 * rhs->e124 + lhs->e124 * rhs->e3 + lhs->e4 * rhs->e123 
            + lhs->e123 * rhs->e4 + lhs->e12 * rhs->e34 + lhs->e13 * rhs->e24 
            + lhs->e23 * rhs->e14 + lhs->e14 * rhs->e23 + lhs->e24 * rhs->e13 
            + lhs->e34 * rhs->e12;
  res.e1235 = lhs->r * rhs->e1235 + lhs->e1235 * rhs->r + lhs->e1 * rhs->e235 
            + lhs->e235 * rhs->e1 + lhs->e2 * rhs->e135 + lhs->e135 * rhs->e2 
            + lhs->e3 * rhs->e125 + lhs->e125 * rhs->e3 + lhs->e5 * rhs->e123 
            + lhs->e123 * rhs->e5 + lhs->e12 * rhs->e35 + lhs->e13 * rhs->e25 
            + lhs->e23 * rhs->e15 + lhs->e15 * rhs->e23 + lhs->e25 * rhs->e13 
            + lhs->e35 * rhs->e12;
  res.e1245 = lhs->r * rhs->e1245 + lhs->e1245 * rhs->r + lhs->e1 * rhs->e245 
            + lhs->e245 * rhs->e1 + lhs->e2 * rhs->e145 + lhs->e145 * rhs->e2 
            + lhs->e4 * rhs->e125 + lhs->e125 * rhs->e4 + lhs->e5 * rhs->e124 
            + lhs->e124 * rhs->e5 + lhs->e12 * rhs->e45 + lhs->e14 * rhs->e25 
            + lhs->e24 * rhs->e15 + lhs->e15 * rhs->e24 + lhs->e25 * rhs->e14 
            + lhs->e45 * rhs->e12;
  res.e1345 = lhs->r * rhs->e1345 + lhs->e1345 * rhs->r + lhs->e1 * rhs->e345 
            + lhs->e345 * rhs->e1 + lhs->e3 * rhs->e145 + lhs->e145 * rhs->e3 
            + lhs->e4 * rhs->e135 + lhs->e135 * rhs->e4 + lhs->e5 * rhs->e134 
            + lhs->e134 * rhs->e5 + lhs->e13 * rhs->e45 + lhs->e14 * rhs->e35 
            + lhs->e34 * rhs->e15 + lhs->e15 * rhs->e34 + lhs->e35 * rhs->e14 
            + lhs->e45 * rhs->e13;
  res.e2345 = lhs->r * rhs->e2345 + lhs->e2345 * rhs->r + lhs->e2 * rhs->e345 
            + lhs->e345 * rhs->e2 + lhs->e3 * rhs->e245 + lhs->e245 * rhs->e3 
            + lhs->e4 * rhs->e235 + lhs->e235 * rhs->e4 + lhs->e5 * rhs->e234 
            + lhs->e234 * rhs->e5 + lhs->e23 * rhs->e45 + lhs->e24 * rhs->e35 
            + lhs->e34 * rhs->e25 + lhs->e25 * rhs->e34 + lhs->e35 * rhs->e24 
            + lhs->e45 * rhs->e23;
  res.e1236 = lhs->r * rhs->e1236 + lhs->e1236 * rhs->r + lhs->e1 * rhs->e236 
            + lhs->e236 * rhs->e1 + lhs->e2 * rhs->e136 + lhs->e136 * rhs->e2 
            + lhs->e3 * rhs->e126 + lhs->e126 * rhs->e3 + lhs->e6 * rhs->e123 
            + lhs->e123 * rhs->e6 + lhs->e12 * rhs->e36 + lhs->e13 * rhs->e26 
            + lhs->e23 * rhs->e16 + lhs->e16 * rhs->e23 + lhs->e26 * rhs->e13 
            + lhs->e36 * rhs->e12;
  res.e1246 = lhs->r * rhs->e1246 + lhs->e1246 * rhs->r + lhs->e1 * rhs->e246 
            + lhs->e246 * rhs->e1 + lhs->e2 * rhs->e146 + lhs->e146 * rhs->e2 
            + lhs->e4 * rhs->e126 + lhs->e126 * rhs->e4 + lhs->e6 * rhs->e124 
            + lhs->e124 * rhs->e6 + lhs->e12 * rhs->e46 + lhs->e14 * rhs->e26 
            + lhs->e24 * rhs->e16 + lhs->e16 * rhs->e24 + lhs->e26 * rhs->e14 
            + lhs->e46 * rhs->e12;
  res.e1346 = lhs->r * rhs->e1346 + lhs->e1346 * rhs->r + lhs->e1 * rhs->e346 
            + lhs->e346 * rhs->e1 + lhs->e3 * rhs->e146 + lhs->e146 * rhs->e3 
            + lhs->e4 * rhs->e136 + lhs->e136 * rhs->e4 + lhs->e6 * rhs->e134 
            + lhs->e134 * rhs->e6 + lhs->e13 * rhs->e46 + lhs->e14 * rhs->e36 
            + lhs->e34 * rhs->e16 + lhs->e16 * rhs->e34 + lhs->e36 * rhs->e14 
            + lhs->e46 * rhs->e13;
  res.e2346 = lhs->r * rhs->e2346 + lhs->e2346 * rhs->r + lhs->e2 * rhs->e346 
            + lhs->e346 * rhs->e2 + lhs->e3 * rhs->e246 + lhs->e246 * rhs->e3 
            + lhs->e4 * rhs->e236 + lhs->e236 * rhs->e4 + lhs->e6 * rhs->e234 
            + lhs->e234 * rhs->e6 + lhs->e23 * rhs->e46 + lhs->e24 * rhs->e36 
            + lhs->e34 * rhs->e26 + lhs->e26 * rhs->e34 + lhs->e36 * rhs->e24 
            + lhs->e46 * rhs->e23;
  res.e1256 = lhs->r * rhs->e1256 + lhs->e1256 * rhs->r + lhs->e1 * rhs->e256 
            + lhs->e256 * rhs->e1 + lhs->e2 * rhs->e156 + lhs->e156 * rhs->e2 
            + lhs->e5 * rhs->e126 + lhs->e126 * rhs->e5 + lhs->e6 * rhs->e125 
            + lhs->e125 * rhs->e6 + lhs->e12 * rhs->e56 + lhs->e15 * rhs->e26 
            + lhs->e25 * rhs->e16 + lhs->e16 * rhs->e25 + lhs->e26 * rhs->e15 
            + lhs->e56 * rhs->e12;
  res.e1356 = lhs->r * rhs->e1356 + lhs->e1356 * rhs->r + lhs->e1 * rhs->e356 
            + lhs->e356 * rhs->e1 + lhs->e3 * rhs->e156 + lhs->e156 * rhs->e3 
            + lhs->e5 * rhs->e136 + lhs->e136 * rhs->e5 + lhs->e6 * rhs->e135 
            + lhs->e135 * rhs->e6 + lhs->e13 * rhs->e56 + lhs->e15 * rhs->e36 
            + lhs->e35 * rhs->e16 + lhs->e16 * rhs->e35 + lhs->e36 * rhs->e15 
            + lhs->e56 * rhs->e13;
  res.e2356 = lhs->r * rhs->e2356 + lhs->e2356 * rhs->r + lhs->e2 * rhs->e356 
            + lhs->e356 * rhs->e2 + lhs->e3 * rhs->e256 + lhs->e256 * rhs->e3 
            + lhs->e5 * rhs->e236 + lhs->e236 * rhs->e5 + lhs->e6 * rhs->e235 
            + lhs->e235 * rhs->e6 + lhs->e23 * rhs->e56 + lhs->e25 * rhs->e36 
            + lhs->e35 * rhs->e26 + lhs->e26 * rhs->e35 + lhs->e36 * rhs->e25 
            + lhs->e56 * rhs->e23;
  res.e1456 = lhs->r * rhs->e1456 + lhs->e1456 * rhs->r + lhs->e1 * rhs->e456 
            + lhs->e456 * rhs->e1 + lhs->e4 * rhs->e156 + lhs->e156 * rhs->e4 
            + lhs->e5 * rhs->e146 + lhs->e146 * rhs->e5 + lhs->e6 * rhs->e145 
            + lhs->e145 * rhs->e6 + lhs->e14 * rhs->e56 + lhs->e15 * rhs->e46 
            + lhs->e45 * rhs->e16 + lhs->e16 * rhs->e45 + lhs->e46 * rhs->e15 
            + lhs->e56 * rhs->e14;
  res.e2456 = lhs->r * rhs->e2456 + lhs->e2456 * rhs->r + lhs->e2 * rhs->e456 
            + lhs->e456 * rhs->e2 + lhs->e4 * rhs->e256 + lhs->e256 * rhs->e4 
            + lhs->e5 * rhs->e246 + lhs->e246 * rhs->e5 + lhs->e6 * rhs->e245 
            + lhs->e245 * rhs->e6 + lhs->e24 * rhs->e56 + lhs->e25 * rhs->e46 
            + lhs->e45 * rhs->e26 + lhs->e26 * rhs->e45 + lhs->e46 * rhs->e25 
            + lhs->e56 * rhs->e24;
  res.e3456 = lhs->r * rhs->e3456 + lhs->e3456 * rhs->r + lhs->e3 * rhs->e456 
            + lhs->e456 * rhs->e3 + lhs->e4 * rhs->e356 + lhs->e356 * rhs->e4 
            + lhs->e5 * rhs->e346 + lhs->e346 * rhs->e5 + lhs->e6 * rhs->e345 
            + lhs->e345 * rhs->e6 + lhs->e34 * rhs->e56 + lhs->e35 * rhs->e46 
            + lhs->e45 * rhs->e36 + lhs->e36 * rhs->e45 + lhs->e46 * rhs->e35 
            + lhs->e56 * rhs->e34;
  res.e1237 = lhs->r * rhs->e1237 + lhs->e1237 * rhs->r + lhs->e1 * rhs->e237 
            + lhs->e237 * rhs->e1 + lhs->e2 * rhs->e137 + lhs->e137 * rhs->e2 
            + lhs->e3 * rhs->e127 + lhs->e127 * rhs->e3 + lhs->e7 * rhs->e123 
            + lhs->e123 * rhs->e7 + lhs->e12 * rhs->e37 + lhs->e13 * rhs->e27 
            + lhs->e23 * rhs->e17 + lhs->e17 * rhs->e23 + lhs->e27 * rhs->e13 
            + lhs->e37 * rhs->e12;
  res.e1247 = lhs->r * rhs->e1247 + lhs->e1247 * rhs->r + lhs->e1 * rhs->e247 
            + lhs->e247 * rhs->e1 + lhs->e2 * rhs->e147 + lhs->e147 * rhs->e2 
            + lhs->e4 * rhs->e127 + lhs->e127 * rhs->e4 + lhs->e7 * rhs->e124 
            + lhs->e124 * rhs->e7 + lhs->e12 * rhs->e47 + lhs->e14 * rhs->e27 
            + lhs->e24 * rhs->e17 + lhs->e17 * rhs->e24 + lhs->e27 * rhs->e14 
            + lhs->e47 * rhs->e12;
  res.e1347 = lhs->r * rhs->e1347 + lhs->e1347 * rhs->r + lhs->e1 * rhs->e347 
            + lhs->e347 * rhs->e1 + lhs->e3 * rhs->e147 + lhs->e147 * rhs->e3 
            + lhs->e4 * rhs->e137 + lhs->e137 * rhs->e4 + lhs->e7 * rhs->e134 
            + lhs->e134 * rhs->e7 + lhs->e13 * rhs->e47 + lhs->e14 * rhs->e37 
            + lhs->e34 * rhs->e17 + lhs->e17 * rhs->e34 + lhs->e37 * rhs->e14 
            + lhs->e47 * rhs->e13;
  res.e2347 = lhs->r * rhs->e2347 + lhs->e2347 * rhs->r + lhs->e2 * rhs->e347 
            + lhs->e347 * rhs->e2 + lhs->e3 * rhs->e247 + lhs->e247 * rhs->e3 
            + lhs->e4 * rhs->e237 + lhs->e237 * rhs->e4 + lhs->e7 * rhs->e234 
            + lhs->e234 * rhs->e7 + lhs->e23 * rhs->e47 + lhs->e24 * rhs->e37 
            + lhs->e34 * rhs->e27 + lhs->e27 * rhs->e34 + lhs->e37 * rhs->e24 
            + lhs->e47 * rhs->e23;
  res.e1257 = lhs->r * rhs->e1257 + lhs->e1257 * rhs->r + lhs->e1 * rhs->e257 
            + lhs->e257 * rhs->e1 + lhs->e2 * rhs->e157 + lhs->e157 * rhs->e2 
            + lhs->e5 * rhs->e127 + lhs->e127 * rhs->e5 + lhs->e7 * rhs->e125 
            + lhs->e125 * rhs->e7 + lhs->e12 * rhs->e57 + lhs->e15 * rhs->e27 
            + lhs->e25 * rhs->e17 + lhs->e17 * rhs->e25 + lhs->e27 * rhs->e15 
            + lhs->e57 * rhs->e12;
  res.e1357 = lhs->r * rhs->e1357 + lhs->e1357 * rhs->r + lhs->e1 * rhs->e357 
            + lhs->e357 * rhs->e1 + lhs->e3 * rhs->e157 + lhs->e157 * rhs->e3 
            + lhs->e5 * rhs->e137 + lhs->e137 * rhs->e5 + lhs->e7 * rhs->e135 
            + lhs->e135 * rhs->e7 + lhs->e13 * rhs->e57 + lhs->e15 * rhs->e37 
            + lhs->e35 * rhs->e17 + lhs->e17 * rhs->e35 + lhs->e37 * rhs->e15 
            + lhs->e57 * rhs->e13;
  res.e2357 = lhs->r * rhs->e2357 + lhs->e2357 * rhs->r + lhs->e2 * rhs->e357 
            + lhs->e357 * rhs->e2 + lhs->e3 * rhs->e257 + lhs->e257 * rhs->e3 
            + lhs->e5 * rhs->e237 + lhs->e237 * rhs->e5 + lhs->e7 * rhs->e235 
            + lhs->e235 * rhs->e7 + lhs->e23 * rhs->e57 + lhs->e25 * rhs->e37 
            + lhs->e35 * rhs->e27 + lhs->e27 * rhs->e35 + lhs->e37 * rhs->e25 
            + lhs->e57 * rhs->e23;
  res.e1457 = lhs->r * rhs->e1457 + lhs->e1457 * rhs->r + lhs->e1 * rhs->e457 
            + lhs->e457 * rhs->e1 + lhs->e4 * rhs->e157 + lhs->e157 * rhs->e4 
            + lhs->e5 * rhs->e147 + lhs->e147 * rhs->e5 + lhs->e7 * rhs->e145 
            + lhs->e145 * rhs->e7 + lhs->e14 * rhs->e57 + lhs->e15 * rhs->e47 
            + lhs->e45 * rhs->e17 + lhs->e17 * rhs->e45 + lhs->e47 * rhs->e15 
            + lhs->e57 * rhs->e14;
  res.e2457 = lhs->r * rhs->e2457 + lhs->e2457 * rhs->r + lhs->e2 * rhs->e457 
            + lhs->e457 * rhs->e2 + lhs->e4 * rhs->e257 + lhs->e257 * rhs->e4 
            + lhs->e5 * rhs->e247 + lhs->e247 * rhs->e5 + lhs->e7 * rhs->e245 
            + lhs->e245 * rhs->e7 + lhs->e24 * rhs->e57 + lhs->e25 * rhs->e47 
            + lhs->e45 * rhs->e27 + lhs->e27 * rhs->e45 + lhs->e47 * rhs->e25 
            + lhs->e57 * rhs->e24;
  res.e3457 = lhs->r * rhs->e3457 + lhs->e3457 * rhs->r + lhs->e3 * rhs->e457 
            + lhs->e457 * rhs->e3 + lhs->e4 * rhs->e357 + lhs->e357 * rhs->e4 
            + lhs->e5 * rhs->e347 + lhs->e347 * rhs->e5 + lhs->e7 * rhs->e345 
            + lhs->e345 * rhs->e7 + lhs->e34 * rhs->e57 + lhs->e35 * rhs->e47 
            + lhs->e45 * rhs->e37 + lhs->e37 * rhs->e45 + lhs->e47 * rhs->e35 
            + lhs->e57 * rhs->e34;
  res.e1267 = lhs->r * rhs->e1267 + lhs->e1267 * rhs->r + lhs->e1 * rhs->e267 
            + lhs->e267 * rhs->e1 + lhs->e2 * rhs->e167 + lhs->e167 * rhs->e2 
            + lhs->e6 * rhs->e127 + lhs->e127 * rhs->e6 + lhs->e7 * rhs->e126 
            + lhs->e126 * rhs->e7 + lhs->e12 * rhs->e67 + lhs->e16 * rhs->e27 
            + lhs->e26 * rhs->e17 + lhs->e17 * rhs->e26 + lhs->e27 * rhs->e16 
            + lhs->e67 * rhs->e12;
  res.e1367 = lhs->r * rhs->e1367 + lhs->e1367 * rhs->r + lhs->e1 * rhs->e367 
            + lhs->e367 * rhs->e1 + lhs->e3 * rhs->e167 + lhs->e167 * rhs->e3 
            + lhs->e6 * rhs->e137 + lhs->e137 * rhs->e6 + lhs->e7 * rhs->e136 
            + lhs->e136 * rhs->e7 + lhs->e13 * rhs->e67 + lhs->e16 * rhs->e37 
            + lhs->e36 * rhs->e17 + lhs->e17 * rhs->e36 + lhs->e37 * rhs->e16 
            + lhs->e67 * rhs->e13;
  res.e2367 = lhs->r * rhs->e2367 + lhs->e2367 * rhs->r + lhs->e2 * rhs->e367 
            + lhs->e367 * rhs->e2 + lhs->e3 * rhs->e267 + lhs->e267 * rhs->e3 
            + lhs->e6 * rhs->e237 + lhs->e237 * rhs->e6 + lhs->e7 * rhs->e236 
            + lhs->e236 * rhs->e7 + lhs->e23 * rhs->e67 + lhs->e26 * rhs->e37 
            + lhs->e36 * rhs->e27 + lhs->e27 * rhs->e36 + lhs->e37 * rhs->e26 
            + lhs->e67 * rhs->e23;
  res.e1467 = lhs->r * rhs->e1467 + lhs->e1467 * rhs->r + lhs->e1 * rhs->e467 
            + lhs->e467 * rhs->e1 + lhs->e4 * rhs->e167 + lhs->e167 * rhs->e4 
            + lhs->e6 * rhs->e147 + lhs->e147 * rhs->e6 + lhs->e7 * rhs->e146 
            + lhs->e146 * rhs->e7 + lhs->e14 * rhs->e67 + lhs->e16 * rhs->e47 
            + lhs->e46 * rhs->e17 + lhs->e17 * rhs->e46 + lhs->e47 * rhs->e16 
            + lhs->e67 * rhs->e14;
  res.e2467 = lhs->r * rhs->e2467 + lhs->e2467 * rhs->r + lhs->e2 * rhs->e467 
            + lhs->e467 * rhs->e2 + lhs->e4 * rhs->e267 + lhs->e267 * rhs->e4 
            + lhs->e6 * rhs->e247 + lhs->e247 * rhs->e6 + lhs->e7 * rhs->e246 
            + lhs->e246 * rhs->e7 + lhs->e24 * rhs->e67 + lhs->e26 * rhs->e47 
            + lhs->e46 * rhs->e27 + lhs->e27 * rhs->e46 + lhs->e47 * rhs->e26 
            + lhs->e67 * rhs->e24;
  res.e3467 = lhs->r * rhs->e3467 + lhs->e3467 * rhs->r + lhs->e3 * rhs->e467 
            + lhs->e467 * rhs->e3 + lhs->e4 * rhs->e367 + lhs->e367 * rhs->e4 
            + lhs->e6 * rhs->e347 + lhs->e347 * rhs->e6 + lhs->e7 * rhs->e346 
            + lhs->e346 * rhs->e7 + lhs->e34 * rhs->e67 + lhs->e36 * rhs->e47 
            + lhs->e46 * rhs->e37 + lhs->e37 * rhs->e46 + lhs->e47 * rhs->e36 
            + lhs->e67 * rhs->e34;
  res.e1567 = lhs->r * rhs->e1567 + lhs->e1567 * rhs->r + lhs->e1 * rhs->e567 
            + lhs->e567 * rhs->e1 + lhs->e5 * rhs->e167 + lhs->e167 * rhs->e5 
            + lhs->e6 * rhs->e157 + lhs->e157 * rhs->e6 + lhs->e7 * rhs->e156 
            + lhs->e156 * rhs->e7 + lhs->e15 * rhs->e67 + lhs->e16 * rhs->e57 
            + lhs->e56 * rhs->e17 + lhs->e17 * rhs->e56 + lhs->e57 * rhs->e16 
            + lhs->e67 * rhs->e15;
  res.e2567 = lhs->r * rhs->e2567 + lhs->e2567 * rhs->r + lhs->e2 * rhs->e567 
            + lhs->e567 * rhs->e2 + lhs->e5 * rhs->e267 + lhs->e267 * rhs->e5 
            + lhs->e6 * rhs->e257 + lhs->e257 * rhs->e6 + lhs->e7 * rhs->e256 
            + lhs->e256 * rhs->e7 + lhs->e25 * rhs->e67 + lhs->e26 * rhs->e57 
            + lhs->e56 * rhs->e27 + lhs->e27 * rhs->e56 + lhs->e57 * rhs->e26 
            + lhs->e67 * rhs->e25;
  res.e3567 = lhs->r * rhs->e3567 + lhs->e3567 * rhs->r + lhs->e3 * rhs->e567 
            + lhs->e567 * rhs->e3 + lhs->e5 * rhs->e367 + lhs->e367 * rhs->e5 
            + lhs->e6 * rhs->e357 + lhs->e357 * rhs->e6 + lhs->e7 * rhs->e356 
            + lhs->e356 * rhs->e7 + lhs->e35 * rhs->e67 + lhs->e36 * rhs->e57 
            + lhs->e56 * rhs->e37 + lhs->e37 * rhs->e56 + lhs->e57 * rhs->e36 
            + lhs->e67 * rhs->e35;
  res.e4567 = lhs->r * rhs->e4567 + lhs->e4567 * rhs->r + lhs->e4 * rhs->e567 
            + lhs->e567 * rhs->e4 + lhs->e5 * rhs->e467 + lhs->e467 * rhs->e5 
            + lhs->e6 * rhs->e457 + lhs->e457 * rhs->e6 + lhs->e7 * rhs->e456 
            + lhs->e456 * rhs->e7 + lhs->e45 * rhs->e67 + lhs->e46 * rhs->e57 
            + lhs->e56 * rhs->e47 + lhs->e47 * rhs->e56 + lhs->e57 * rhs->e46 
            + lhs->e67 * rhs->e45;
  // Order 5;
  res.e12345 = lhs->r * rhs->e12345 + lhs->e12345 * rhs->r + lhs->e1 * rhs->e2345 
             + lhs->e2345 * rhs->e1 + lhs->e2 * rhs->e1345 + lhs->e1345 * rhs->e2 
             + lhs->e3 * rhs->e1245 + lhs->e1245 * rhs->e3 + lhs->e4 * rhs->e1235 
             + lhs->e1235 * rhs->e4 + lhs->e5 * rhs->e1234 + lhs->e1234 * rhs->e5 
             + lhs->e12 * rhs->e345 + lhs->e345 * rhs->e12 + lhs->e13 * rhs->e245 
             + lhs->e245 * rhs->e13 + lhs->e23 * rhs->e145 + lhs->e145 * rhs->e23 
             + lhs->e14 * rhs->e235 + lhs->e235 * rhs->e14 + lhs->e24 * rhs->e135 
             + lhs->e135 * rhs->e24 + lhs->e34 * rhs->e125 + lhs->e125 * rhs->e34 
             + lhs->e15 * rhs->e234 + lhs->e234 * rhs->e15 + lhs->e25 * rhs->e134 
             + lhs->e134 * rhs->e25 + lhs->e35 * rhs->e124 + lhs->e124 * rhs->e35 
             + lhs->e45 * rhs->e123 + lhs->e123 * rhs->e45;
  res.e12346 = lhs->r * rhs->e12346 + lhs->e12346 * rhs->r + lhs->e1 * rhs->e2346 
             + lhs->e2346 * rhs->e1 + lhs->e2 * rhs->e1346 + lhs->e1346 * rhs->e2 
             + lhs->e3 * rhs->e1246 + lhs->e1246 * rhs->e3 + lhs->e4 * rhs->e1236 
             + lhs->e1236 * rhs->e4 + lhs->e6 * rhs->e1234 + lhs->e1234 * rhs->e6 
             + lhs->e12 * rhs->e346 + lhs->e346 * rhs->e12 + lhs->e13 * rhs->e246 
             + lhs->e246 * rhs->e13 + lhs->e23 * rhs->e146 + lhs->e146 * rhs->e23 
             + lhs->e14 * rhs->e236 + lhs->e236 * rhs->e14 + lhs->e24 * rhs->e136 
             + lhs->e136 * rhs->e24 + lhs->e34 * rhs->e126 + lhs->e126 * rhs->e34 
             + lhs->e16 * rhs->e234 + lhs->e234 * rhs->e16 + lhs->e26 * rhs->e134 
             + lhs->e134 * rhs->e26 + lhs->e36 * rhs->e124 + lhs->e124 * rhs->e36 
             + lhs->e46 * rhs->e123 + lhs->e123 * rhs->e46;
  res.e12356 = lhs->r * rhs->e12356 + lhs->e12356 * rhs->r + lhs->e1 * rhs->e2356 
             + lhs->e2356 * rhs->e1 + lhs->e2 * rhs->e1356 + lhs->e1356 * rhs->e2 
             + lhs->e3 * rhs->e1256 + lhs->e1256 * rhs->e3 + lhs->e5 * rhs->e1236 
             + lhs->e1236 * rhs->e5 + lhs->e6 * rhs->e1235 + lhs->e1235 * rhs->e6 
             + lhs->e12 * rhs->e356 + lhs->e356 * rhs->e12 + lhs->e13 * rhs->e256 
             + lhs->e256 * rhs->e13 + lhs->e23 * rhs->e156 + lhs->e156 * rhs->e23 
             + lhs->e15 * rhs->e236 + lhs->e236 * rhs->e15 + lhs->e25 * rhs->e136 
             + lhs->e136 * rhs->e25 + lhs->e35 * rhs->e126 + lhs->e126 * rhs->e35 
             + lhs->e16 * rhs->e235 + lhs->e235 * rhs->e16 + lhs->e26 * rhs->e135 
             + lhs->e135 * rhs->e26 + lhs->e36 * rhs->e125 + lhs->e125 * rhs->e36 
             + lhs->e56 * rhs->e123 + lhs->e123 * rhs->e56;
  res.e12456 = lhs->r * rhs->e12456 + lhs->e12456 * rhs->r + lhs->e1 * rhs->e2456 
             + lhs->e2456 * rhs->e1 + lhs->e2 * rhs->e1456 + lhs->e1456 * rhs->e2 
             + lhs->e4 * rhs->e1256 + lhs->e1256 * rhs->e4 + lhs->e5 * rhs->e1246 
             + lhs->e1246 * rhs->e5 + lhs->e6 * rhs->e1245 + lhs->e1245 * rhs->e6 
             + lhs->e12 * rhs->e456 + lhs->e456 * rhs->e12 + lhs->e14 * rhs->e256 
             + lhs->e256 * rhs->e14 + lhs->e24 * rhs->e156 + lhs->e156 * rhs->e24 
             + lhs->e15 * rhs->e246 + lhs->e246 * rhs->e15 + lhs->e25 * rhs->e146 
             + lhs->e146 * rhs->e25 + lhs->e45 * rhs->e126 + lhs->e126 * rhs->e45 
             + lhs->e16 * rhs->e245 + lhs->e245 * rhs->e16 + lhs->e26 * rhs->e145 
             + lhs->e145 * rhs->e26 + lhs->e46 * rhs->e125 + lhs->e125 * rhs->e46 
             + lhs->e56 * rhs->e124 + lhs->e124 * rhs->e56;
  res.e13456 = lhs->r * rhs->e13456 + lhs->e13456 * rhs->r + lhs->e1 * rhs->e3456 
             + lhs->e3456 * rhs->e1 + lhs->e3 * rhs->e1456 + lhs->e1456 * rhs->e3 
             + lhs->e4 * rhs->e1356 + lhs->e1356 * rhs->e4 + lhs->e5 * rhs->e1346 
             + lhs->e1346 * rhs->e5 + lhs->e6 * rhs->e1345 + lhs->e1345 * rhs->e6 
             + lhs->e13 * rhs->e456 + lhs->e456 * rhs->e13 + lhs->e14 * rhs->e356 
             + lhs->e356 * rhs->e14 + lhs->e34 * rhs->e156 + lhs->e156 * rhs->e34 
             + lhs->e15 * rhs->e346 + lhs->e346 * rhs->e15 + lhs->e35 * rhs->e146 
             + lhs->e146 * rhs->e35 + lhs->e45 * rhs->e136 + lhs->e136 * rhs->e45 
             + lhs->e16 * rhs->e345 + lhs->e345 * rhs->e16 + lhs->e36 * rhs->e145 
             + lhs->e145 * rhs->e36 + lhs->e46 * rhs->e135 + lhs->e135 * rhs->e46 
             + lhs->e56 * rhs->e134 + lhs->e134 * rhs->e56;
  res.e23456 = lhs->r * rhs->e23456 + lhs->e23456 * rhs->r + lhs->e2 * rhs->e3456 
             + lhs->e3456 * rhs->e2 + lhs->e3 * rhs->e2456 + lhs->e2456 * rhs->e3 
             + lhs->e4 * rhs->e2356 + lhs->e2356 * rhs->e4 + lhs->e5 * rhs->e2346 
             + lhs->e2346 * rhs->e5 + lhs->e6 * rhs->e2345 + lhs->e2345 * rhs->e6 
             + lhs->e23 * rhs->e456 + lhs->e456 * rhs->e23 + lhs->e24 * rhs->e356 
             + lhs->e356 * rhs->e24 + lhs->e34 * rhs->e256 + lhs->e256 * rhs->e34 
             + lhs->e25 * rhs->e346 + lhs->e346 * rhs->e25 + lhs->e35 * rhs->e246 
             + lhs->e246 * rhs->e35 + lhs->e45 * rhs->e236 + lhs->e236 * rhs->e45 
             + lhs->e26 * rhs->e345 + lhs->e345 * rhs->e26 + lhs->e36 * rhs->e245 
             + lhs->e245 * rhs->e36 + lhs->e46 * rhs->e235 + lhs->e235 * rhs->e46 
             + lhs->e56 * rhs->e234 + lhs->e234 * rhs->e56;
  res.e12347 = lhs->r * rhs->e12347 + lhs->e12347 * rhs->r + lhs->e1 * rhs->e2347 
             + lhs->e2347 * rhs->e1 + lhs->e2 * rhs->e1347 + lhs->e1347 * rhs->e2 
             + lhs->e3 * rhs->e1247 + lhs->e1247 * rhs->e3 + lhs->e4 * rhs->e1237 
             + lhs->e1237 * rhs->e4 + lhs->e7 * rhs->e1234 + lhs->e1234 * rhs->e7 
             + lhs->e12 * rhs->e347 + lhs->e347 * rhs->e12 + lhs->e13 * rhs->e247 
             + lhs->e247 * rhs->e13 + lhs->e23 * rhs->e147 + lhs->e147 * rhs->e23 
             + lhs->e14 * rhs->e237 + lhs->e237 * rhs->e14 + lhs->e24 * rhs->e137 
             + lhs->e137 * rhs->e24 + lhs->e34 * rhs->e127 + lhs->e127 * rhs->e34 
             + lhs->e17 * rhs->e234 + lhs->e234 * rhs->e17 + lhs->e27 * rhs->e134 
             + lhs->e134 * rhs->e27 + lhs->e37 * rhs->e124 + lhs->e124 * rhs->e37 
             + lhs->e47 * rhs->e123 + lhs->e123 * rhs->e47;
  res.e12357 = lhs->r * rhs->e12357 + lhs->e12357 * rhs->r + lhs->e1 * rhs->e2357 
             + lhs->e2357 * rhs->e1 + lhs->e2 * rhs->e1357 + lhs->e1357 * rhs->e2 
             + lhs->e3 * rhs->e1257 + lhs->e1257 * rhs->e3 + lhs->e5 * rhs->e1237 
             + lhs->e1237 * rhs->e5 + lhs->e7 * rhs->e1235 + lhs->e1235 * rhs->e7 
             + lhs->e12 * rhs->e357 + lhs->e357 * rhs->e12 + lhs->e13 * rhs->e257 
             + lhs->e257 * rhs->e13 + lhs->e23 * rhs->e157 + lhs->e157 * rhs->e23 
             + lhs->e15 * rhs->e237 + lhs->e237 * rhs->e15 + lhs->e25 * rhs->e137 
             + lhs->e137 * rhs->e25 + lhs->e35 * rhs->e127 + lhs->e127 * rhs->e35 
             + lhs->e17 * rhs->e235 + lhs->e235 * rhs->e17 + lhs->e27 * rhs->e135 
             + lhs->e135 * rhs->e27 + lhs->e37 * rhs->e125 + lhs->e125 * rhs->e37 
             + lhs->e57 * rhs->e123 + lhs->e123 * rhs->e57;
  res.e12457 = lhs->r * rhs->e12457 + lhs->e12457 * rhs->r + lhs->e1 * rhs->e2457 
             + lhs->e2457 * rhs->e1 + lhs->e2 * rhs->e1457 + lhs->e1457 * rhs->e2 
             + lhs->e4 * rhs->e1257 + lhs->e1257 * rhs->e4 + lhs->e5 * rhs->e1247 
             + lhs->e1247 * rhs->e5 + lhs->e7 * rhs->e1245 + lhs->e1245 * rhs->e7 
             + lhs->e12 * rhs->e457 + lhs->e457 * rhs->e12 + lhs->e14 * rhs->e257 
             + lhs->e257 * rhs->e14 + lhs->e24 * rhs->e157 + lhs->e157 * rhs->e24 
             + lhs->e15 * rhs->e247 + lhs->e247 * rhs->e15 + lhs->e25 * rhs->e147 
             + lhs->e147 * rhs->e25 + lhs->e45 * rhs->e127 + lhs->e127 * rhs->e45 
             + lhs->e17 * rhs->e245 + lhs->e245 * rhs->e17 + lhs->e27 * rhs->e145 
             + lhs->e145 * rhs->e27 + lhs->e47 * rhs->e125 + lhs->e125 * rhs->e47 
             + lhs->e57 * rhs->e124 + lhs->e124 * rhs->e57;
  res.e13457 = lhs->r * rhs->e13457 + lhs->e13457 * rhs->r + lhs->e1 * rhs->e3457 
             + lhs->e3457 * rhs->e1 + lhs->e3 * rhs->e1457 + lhs->e1457 * rhs->e3 
             + lhs->e4 * rhs->e1357 + lhs->e1357 * rhs->e4 + lhs->e5 * rhs->e1347 
             + lhs->e1347 * rhs->e5 + lhs->e7 * rhs->e1345 + lhs->e1345 * rhs->e7 
             + lhs->e13 * rhs->e457 + lhs->e457 * rhs->e13 + lhs->e14 * rhs->e357 
             + lhs->e357 * rhs->e14 + lhs->e34 * rhs->e157 + lhs->e157 * rhs->e34 
             + lhs->e15 * rhs->e347 + lhs->e347 * rhs->e15 + lhs->e35 * rhs->e147 
             + lhs->e147 * rhs->e35 + lhs->e45 * rhs->e137 + lhs->e137 * rhs->e45 
             + lhs->e17 * rhs->e345 + lhs->e345 * rhs->e17 + lhs->e37 * rhs->e145 
             + lhs->e145 * rhs->e37 + lhs->e47 * rhs->e135 + lhs->e135 * rhs->e47 
             + lhs->e57 * rhs->e134 + lhs->e134 * rhs->e57;
  res.e23457 = lhs->r * rhs->e23457 + lhs->e23457 * rhs->r + lhs->e2 * rhs->e3457 
             + lhs->e3457 * rhs->e2 + lhs->e3 * rhs->e2457 + lhs->e2457 * rhs->e3 
             + lhs->e4 * rhs->e2357 + lhs->e2357 * rhs->e4 + lhs->e5 * rhs->e2347 
             + lhs->e2347 * rhs->e5 + lhs->e7 * rhs->e2345 + lhs->e2345 * rhs->e7 
             + lhs->e23 * rhs->e457 + lhs->e457 * rhs->e23 + lhs->e24 * rhs->e357 
             + lhs->e357 * rhs->e24 + lhs->e34 * rhs->e257 + lhs->e257 * rhs->e34 
             + lhs->e25 * rhs->e347 + lhs->e347 * rhs->e25 + lhs->e35 * rhs->e247 
             + lhs->e247 * rhs->e35 + lhs->e45 * rhs->e237 + lhs->e237 * rhs->e45 
             + lhs->e27 * rhs->e345 + lhs->e345 * rhs->e27 + lhs->e37 * rhs->e245 
             + lhs->e245 * rhs->e37 + lhs->e47 * rhs->e235 + lhs->e235 * rhs->e47 
             + lhs->e57 * rhs->e234 + lhs->e234 * rhs->e57;
  res.e12367 = lhs->r * rhs->e12367 + lhs->e12367 * rhs->r + lhs->e1 * rhs->e2367 
             + lhs->e2367 * rhs->e1 + lhs->e2 * rhs->e1367 + lhs->e1367 * rhs->e2 
             + lhs->e3 * rhs->e1267 + lhs->e1267 * rhs->e3 + lhs->e6 * rhs->e1237 
             + lhs->e1237 * rhs->e6 + lhs->e7 * rhs->e1236 + lhs->e1236 * rhs->e7 
             + lhs->e12 * rhs->e367 + lhs->e367 * rhs->e12 + lhs->e13 * rhs->e267 
             + lhs->e267 * rhs->e13 + lhs->e23 * rhs->e167 + lhs->e167 * rhs->e23 
             + lhs->e16 * rhs->e237 + lhs->e237 * rhs->e16 + lhs->e26 * rhs->e137 
             + lhs->e137 * rhs->e26 + lhs->e36 * rhs->e127 + lhs->e127 * rhs->e36 
             + lhs->e17 * rhs->e236 + lhs->e236 * rhs->e17 + lhs->e27 * rhs->e136 
             + lhs->e136 * rhs->e27 + lhs->e37 * rhs->e126 + lhs->e126 * rhs->e37 
             + lhs->e67 * rhs->e123 + lhs->e123 * rhs->e67;
  res.e12467 = lhs->r * rhs->e12467 + lhs->e12467 * rhs->r + lhs->e1 * rhs->e2467 
             + lhs->e2467 * rhs->e1 + lhs->e2 * rhs->e1467 + lhs->e1467 * rhs->e2 
             + lhs->e4 * rhs->e1267 + lhs->e1267 * rhs->e4 + lhs->e6 * rhs->e1247 
             + lhs->e1247 * rhs->e6 + lhs->e7 * rhs->e1246 + lhs->e1246 * rhs->e7 
             + lhs->e12 * rhs->e467 + lhs->e467 * rhs->e12 + lhs->e14 * rhs->e267 
             + lhs->e267 * rhs->e14 + lhs->e24 * rhs->e167 + lhs->e167 * rhs->e24 
             + lhs->e16 * rhs->e247 + lhs->e247 * rhs->e16 + lhs->e26 * rhs->e147 
             + lhs->e147 * rhs->e26 + lhs->e46 * rhs->e127 + lhs->e127 * rhs->e46 
             + lhs->e17 * rhs->e246 + lhs->e246 * rhs->e17 + lhs->e27 * rhs->e146 
             + lhs->e146 * rhs->e27 + lhs->e47 * rhs->e126 + lhs->e126 * rhs->e47 
             + lhs->e67 * rhs->e124 + lhs->e124 * rhs->e67;
  res.e13467 = lhs->r * rhs->e13467 + lhs->e13467 * rhs->r + lhs->e1 * rhs->e3467 
             + lhs->e3467 * rhs->e1 + lhs->e3 * rhs->e1467 + lhs->e1467 * rhs->e3 
             + lhs->e4 * rhs->e1367 + lhs->e1367 * rhs->e4 + lhs->e6 * rhs->e1347 
             + lhs->e1347 * rhs->e6 + lhs->e7 * rhs->e1346 + lhs->e1346 * rhs->e7 
             + lhs->e13 * rhs->e467 + lhs->e467 * rhs->e13 + lhs->e14 * rhs->e367 
             + lhs->e367 * rhs->e14 + lhs->e34 * rhs->e167 + lhs->e167 * rhs->e34 
             + lhs->e16 * rhs->e347 + lhs->e347 * rhs->e16 + lhs->e36 * rhs->e147 
             + lhs->e147 * rhs->e36 + lhs->e46 * rhs->e137 + lhs->e137 * rhs->e46 
             + lhs->e17 * rhs->e346 + lhs->e346 * rhs->e17 + lhs->e37 * rhs->e146 
             + lhs->e146 * rhs->e37 + lhs->e47 * rhs->e136 + lhs->e136 * rhs->e47 
             + lhs->e67 * rhs->e134 + lhs->e134 * rhs->e67;
  res.e23467 = lhs->r * rhs->e23467 + lhs->e23467 * rhs->r + lhs->e2 * rhs->e3467 
             + lhs->e3467 * rhs->e2 + lhs->e3 * rhs->e2467 + lhs->e2467 * rhs->e3 
             + lhs->e4 * rhs->e2367 + lhs->e2367 * rhs->e4 + lhs->e6 * rhs->e2347 
             + lhs->e2347 * rhs->e6 + lhs->e7 * rhs->e2346 + lhs->e2346 * rhs->e7 
             + lhs->e23 * rhs->e467 + lhs->e467 * rhs->e23 + lhs->e24 * rhs->e367 
             + lhs->e367 * rhs->e24 + lhs->e34 * rhs->e267 + lhs->e267 * rhs->e34 
             + lhs->e26 * rhs->e347 + lhs->e347 * rhs->e26 + lhs->e36 * rhs->e247 
             + lhs->e247 * rhs->e36 + lhs->e46 * rhs->e237 + lhs->e237 * rhs->e46 
             + lhs->e27 * rhs->e346 + lhs->e346 * rhs->e27 + lhs->e37 * rhs->e246 
             + lhs->e246 * rhs->e37 + lhs->e47 * rhs->e236 + lhs->e236 * rhs->e47 
             + lhs->e67 * rhs->e234 + lhs->e234 * rhs->e67;
  res.e12567 = lhs->r * rhs->e12567 + lhs->e12567 * rhs->r + lhs->e1 * rhs->e2567 
             + lhs->e2567 * rhs->e1 + lhs->e2 * rhs->e1567 + lhs->e1567 * rhs->e2 
             + lhs->e5 * rhs->e1267 + lhs->e1267 * rhs->e5 + lhs->e6 * rhs->e1257 
             + lhs->e1257 * rhs->e6 + lhs->e7 * rhs->e1256 + lhs->e1256 * rhs->e7 
             + lhs->e12 * rhs->e567 + lhs->e567 * rhs->e12 + lhs->e15 * rhs->e267 
             + lhs->e267 * rhs->e15 + lhs->e25 * rhs->e167 + lhs->e167 * rhs->e25 
             + lhs->e16 * rhs->e257 + lhs->e257 * rhs->e16 + lhs->e26 * rhs->e157 
             + lhs->e157 * rhs->e26 + lhs->e56 * rhs->e127 + lhs->e127 * rhs->e56 
             + lhs->e17 * rhs->e256 + lhs->e256 * rhs->e17 + lhs->e27 * rhs->e156 
             + lhs->e156 * rhs->e27 + lhs->e57 * rhs->e126 + lhs->e126 * rhs->e57 
             + lhs->e67 * rhs->e125 + lhs->e125 * rhs->e67;
  res.e13567 = lhs->r * rhs->e13567 + lhs->e13567 * rhs->r + lhs->e1 * rhs->e3567 
             + lhs->e3567 * rhs->e1 + lhs->e3 * rhs->e1567 + lhs->e1567 * rhs->e3 
             + lhs->e5 * rhs->e1367 + lhs->e1367 * rhs->e5 + lhs->e6 * rhs->e1357 
             + lhs->e1357 * rhs->e6 + lhs->e7 * rhs->e1356 + lhs->e1356 * rhs->e7 
             + lhs->e13 * rhs->e567 + lhs->e567 * rhs->e13 + lhs->e15 * rhs->e367 
             + lhs->e367 * rhs->e15 + lhs->e35 * rhs->e167 + lhs->e167 * rhs->e35 
             + lhs->e16 * rhs->e357 + lhs->e357 * rhs->e16 + lhs->e36 * rhs->e157 
             + lhs->e157 * rhs->e36 + lhs->e56 * rhs->e137 + lhs->e137 * rhs->e56 
             + lhs->e17 * rhs->e356 + lhs->e356 * rhs->e17 + lhs->e37 * rhs->e156 
             + lhs->e156 * rhs->e37 + lhs->e57 * rhs->e136 + lhs->e136 * rhs->e57 
             + lhs->e67 * rhs->e135 + lhs->e135 * rhs->e67;
  res.e23567 = lhs->r * rhs->e23567 + lhs->e23567 * rhs->r + lhs->e2 * rhs->e3567 
             + lhs->e3567 * rhs->e2 + lhs->e3 * rhs->e2567 + lhs->e2567 * rhs->e3 
             + lhs->e5 * rhs->e2367 + lhs->e2367 * rhs->e5 + lhs->e6 * rhs->e2357 
             + lhs->e2357 * rhs->e6 + lhs->e7 * rhs->e2356 + lhs->e2356 * rhs->e7 
             + lhs->e23 * rhs->e567 + lhs->e567 * rhs->e23 + lhs->e25 * rhs->e367 
             + lhs->e367 * rhs->e25 + lhs->e35 * rhs->e267 + lhs->e267 * rhs->e35 
             + lhs->e26 * rhs->e357 + lhs->e357 * rhs->e26 + lhs->e36 * rhs->e257 
             + lhs->e257 * rhs->e36 + lhs->e56 * rhs->e237 + lhs->e237 * rhs->e56 
             + lhs->e27 * rhs->e356 + lhs->e356 * rhs->e27 + lhs->e37 * rhs->e256 
             + lhs->e256 * rhs->e37 + lhs->e57 * rhs->e236 + lhs->e236 * rhs->e57 
             + lhs->e67 * rhs->e235 + lhs->e235 * rhs->e67;
  res.e14567 = lhs->r * rhs->e14567 + lhs->e14567 * rhs->r + lhs->e1 * rhs->e4567 
             + lhs->e4567 * rhs->e1 + lhs->e4 * rhs->e1567 + lhs->e1567 * rhs->e4 
             + lhs->e5 * rhs->e1467 + lhs->e1467 * rhs->e5 + lhs->e6 * rhs->e1457 
             + lhs->e1457 * rhs->e6 + lhs->e7 * rhs->e1456 + lhs->e1456 * rhs->e7 
             + lhs->e14 * rhs->e567 + lhs->e567 * rhs->e14 + lhs->e15 * rhs->e467 
             + lhs->e467 * rhs->e15 + lhs->e45 * rhs->e167 + lhs->e167 * rhs->e45 
             + lhs->e16 * rhs->e457 + lhs->e457 * rhs->e16 + lhs->e46 * rhs->e157 
             + lhs->e157 * rhs->e46 + lhs->e56 * rhs->e147 + lhs->e147 * rhs->e56 
             + lhs->e17 * rhs->e456 + lhs->e456 * rhs->e17 + lhs->e47 * rhs->e156 
             + lhs->e156 * rhs->e47 + lhs->e57 * rhs->e146 + lhs->e146 * rhs->e57 
             + lhs->e67 * rhs->e145 + lhs->e145 * rhs->e67;
  res.e24567 = lhs->r * rhs->e24567 + lhs->e24567 * rhs->r + lhs->e2 * rhs->e4567 
             + lhs->e4567 * rhs->e2 + lhs->e4 * rhs->e2567 + lhs->e2567 * rhs->e4 
             + lhs->e5 * rhs->e2467 + lhs->e2467 * rhs->e5 + lhs->e6 * rhs->e2457 
             + lhs->e2457 * rhs->e6 + lhs->e7 * rhs->e2456 + lhs->e2456 * rhs->e7 
             + lhs->e24 * rhs->e567 + lhs->e567 * rhs->e24 + lhs->e25 * rhs->e467 
             + lhs->e467 * rhs->e25 + lhs->e45 * rhs->e267 + lhs->e267 * rhs->e45 
             + lhs->e26 * rhs->e457 + lhs->e457 * rhs->e26 + lhs->e46 * rhs->e257 
             + lhs->e257 * rhs->e46 + lhs->e56 * rhs->e247 + lhs->e247 * rhs->e56 
             + lhs->e27 * rhs->e456 + lhs->e456 * rhs->e27 + lhs->e47 * rhs->e256 
             + lhs->e256 * rhs->e47 + lhs->e57 * rhs->e246 + lhs->e246 * rhs->e57 
             + lhs->e67 * rhs->e245 + lhs->e245 * rhs->e67;
  res.e34567 = lhs->r * rhs->e34567 + lhs->e34567 * rhs->r + lhs->e3 * rhs->e4567 
             + lhs->e4567 * rhs->e3 + lhs->e4 * rhs->e3567 + lhs->e3567 * rhs->e4 
             + lhs->e5 * rhs->e3467 + lhs->e3467 * rhs->e5 + lhs->e6 * rhs->e3457 
             + lhs->e3457 * rhs->e6 + lhs->e7 * rhs->e3456 + lhs->e3456 * rhs->e7 
             + lhs->e34 * rhs->e567 + lhs->e567 * rhs->e34 + lhs->e35 * rhs->e467 
             + lhs->e467 * rhs->e35 + lhs->e45 * rhs->e367 + lhs->e367 * rhs->e45 
             + lhs->e36 * rhs->e457 + lhs->e457 * rhs->e36 + lhs->e46 * rhs->e357 
             + lhs->e357 * rhs->e46 + lhs->e56 * rhs->e347 + lhs->e347 * rhs->e56 
             + lhs->e37 * rhs->e456 + lhs->e456 * rhs->e37 + lhs->e47 * rhs->e356 
             + lhs->e356 * rhs->e47 + lhs->e57 * rhs->e346 + lhs->e346 * rhs->e57 
             + lhs->e67 * rhs->e345 + lhs->e345 * rhs->e67;
  // Order 6;
  res.e123456 = lhs->r * rhs->e123456 + lhs->e123456 * rhs->r + lhs->e1 * rhs->e23456 
              + lhs->e23456 * rhs->e1 + lhs->e2 * rhs->e13456 + lhs->e13456 * rhs->e2 
              + lhs->e3 * rhs->e12456 + lhs->e12456 * rhs->e3 + lhs->e4 * rhs->e12356 
              + lhs->e12356 * rhs->e4 + lhs->e5 * rhs->e12346 + lhs->e12346 * rhs->e5 
              + lhs->e6 * rhs->e12345 + lhs->e12345 * rhs->e6 + lhs->e12 * rhs->e3456 
              + lhs->e3456 * rhs->e12 + lhs->e13 * rhs->e2456 + lhs->e2456 * rhs->e13 
              + lhs->e23 * rhs->e1456 + lhs->e1456 * rhs->e23 + lhs->e14 * rhs->e2356 
              + lhs->e2356 * rhs->e14 + lhs->e24 * rhs->e1356 + lhs->e1356 * rhs->e24 
              + lhs->e34 * rhs->e1256 + lhs->e1256 * rhs->e34 + lhs->e15 * rhs->e2346 
              + lhs->e2346 * rhs->e15 + lhs->e25 * rhs->e1346 + lhs->e1346 * rhs->e25 
              + lhs->e35 * rhs->e1246 + lhs->e1246 * rhs->e35 + lhs->e45 * rhs->e1236 
              + lhs->e1236 * rhs->e45 + lhs->e16 * rhs->e2345 + lhs->e2345 * rhs->e16 
              + lhs->e26 * rhs->e1345 + lhs->e1345 * rhs->e26 + lhs->e36 * rhs->e1245 
              + lhs->e1245 * rhs->e36 + lhs->e46 * rhs->e1235 + lhs->e1235 * rhs->e46 
              + lhs->e56 * rhs->e1234 + lhs->e1234 * rhs->e56 + lhs->e123 * rhs->e456 
              + lhs->e124 * rhs->e356 + lhs->e134 * rhs->e256 + lhs->e234 * rhs->e156 
              + lhs->e125 * rhs->e346 + lhs->e135 * rhs->e246 + lhs->e235 * rhs->e146 
              + lhs->e145 * rhs->e236 + lhs->e245 * rhs->e136 + lhs->e345 * rhs->e126 
              + lhs->e126 * rhs->e345 + lhs->e136 * rhs->e245 + lhs->e236 * rhs->e145 
              + lhs->e146 * rhs->e235 + lhs->e246 * rhs->e135 + lhs->e346 * rhs->e125 
              + lhs->e156 * rhs->e234 + lhs->e256 * rhs->e134 + lhs->e356 * rhs->e124 
              + lhs->e456 * rhs->e123;
  res.e123457 = lhs->r * rhs->e123457 + lhs->e123457 * rhs->r + lhs->e1 * rhs->e23457 
              + lhs->e23457 * rhs->e1 + lhs->e2 * rhs->e13457 + lhs->e13457 * rhs->e2 
              + lhs->e3 * rhs->e12457 + lhs->e12457 * rhs->e3 + lhs->e4 * rhs->e12357 
              + lhs->e12357 * rhs->e4 + lhs->e5 * rhs->e12347 + lhs->e12347 * rhs->e5 
              + lhs->e7 * rhs->e12345 + lhs->e12345 * rhs->e7 + lhs->e12 * rhs->e3457 
              + lhs->e3457 * rhs->e12 + lhs->e13 * rhs->e2457 + lhs->e2457 * rhs->e13 
              + lhs->e23 * rhs->e1457 + lhs->e1457 * rhs->e23 + lhs->e14 * rhs->e2357 
              + lhs->e2357 * rhs->e14 + lhs->e24 * rhs->e1357 + lhs->e1357 * rhs->e24 
              + lhs->e34 * rhs->e1257 + lhs->e1257 * rhs->e34 + lhs->e15 * rhs->e2347 
              + lhs->e2347 * rhs->e15 + lhs->e25 * rhs->e1347 + lhs->e1347 * rhs->e25 
              + lhs->e35 * rhs->e1247 + lhs->e1247 * rhs->e35 + lhs->e45 * rhs->e1237 
              + lhs->e1237 * rhs->e45 + lhs->e17 * rhs->e2345 + lhs->e2345 * rhs->e17 
              + lhs->e27 * rhs->e1345 + lhs->e1345 * rhs->e27 + lhs->e37 * rhs->e1245 
              + lhs->e1245 * rhs->e37 + lhs->e47 * rhs->e1235 + lhs->e1235 * rhs->e47 
              + lhs->e57 * rhs->e1234 + lhs->e1234 * rhs->e57 + lhs->e123 * rhs->e457 
              + lhs->e124 * rhs->e357 + lhs->e134 * rhs->e257 + lhs->e234 * rhs->e157 
              + lhs->e125 * rhs->e347 + lhs->e135 * rhs->e247 + lhs->e235 * rhs->e147 
              + lhs->e145 * rhs->e237 + lhs->e245 * rhs->e137 + lhs->e345 * rhs->e127 
              + lhs->e127 * rhs->e345 + lhs->e137 * rhs->e245 + lhs->e237 * rhs->e145 
              + lhs->e147 * rhs->e235 + lhs->e247 * rhs->e135 + lhs->e347 * rhs->e125 
              + lhs->e157 * rhs->e234 + lhs->e257 * rhs->e134 + lhs->e357 * rhs->e124 
              + lhs->e457 * rhs->e123;
  res.e123467 = lhs->r * rhs->e123467 + lhs->e123467 * rhs->r + lhs->e1 * rhs->e23467 
              + lhs->e23467 * rhs->e1 + lhs->e2 * rhs->e13467 + lhs->e13467 * rhs->e2 
              + lhs->e3 * rhs->e12467 + lhs->e12467 * rhs->e3 + lhs->e4 * rhs->e12367 
              + lhs->e12367 * rhs->e4 + lhs->e6 * rhs->e12347 + lhs->e12347 * rhs->e6 
              + lhs->e7 * rhs->e12346 + lhs->e12346 * rhs->e7 + lhs->e12 * rhs->e3467 
              + lhs->e3467 * rhs->e12 + lhs->e13 * rhs->e2467 + lhs->e2467 * rhs->e13 
              + lhs->e23 * rhs->e1467 + lhs->e1467 * rhs->e23 + lhs->e14 * rhs->e2367 
              + lhs->e2367 * rhs->e14 + lhs->e24 * rhs->e1367 + lhs->e1367 * rhs->e24 
              + lhs->e34 * rhs->e1267 + lhs->e1267 * rhs->e34 + lhs->e16 * rhs->e2347 
              + lhs->e2347 * rhs->e16 + lhs->e26 * rhs->e1347 + lhs->e1347 * rhs->e26 
              + lhs->e36 * rhs->e1247 + lhs->e1247 * rhs->e36 + lhs->e46 * rhs->e1237 
              + lhs->e1237 * rhs->e46 + lhs->e17 * rhs->e2346 + lhs->e2346 * rhs->e17 
              + lhs->e27 * rhs->e1346 + lhs->e1346 * rhs->e27 + lhs->e37 * rhs->e1246 
              + lhs->e1246 * rhs->e37 + lhs->e47 * rhs->e1236 + lhs->e1236 * rhs->e47 
              + lhs->e67 * rhs->e1234 + lhs->e1234 * rhs->e67 + lhs->e123 * rhs->e467 
              + lhs->e124 * rhs->e367 + lhs->e134 * rhs->e267 + lhs->e234 * rhs->e167 
              + lhs->e126 * rhs->e347 + lhs->e136 * rhs->e247 + lhs->e236 * rhs->e147 
              + lhs->e146 * rhs->e237 + lhs->e246 * rhs->e137 + lhs->e346 * rhs->e127 
              + lhs->e127 * rhs->e346 + lhs->e137 * rhs->e246 + lhs->e237 * rhs->e146 
              + lhs->e147 * rhs->e236 + lhs->e247 * rhs->e136 + lhs->e347 * rhs->e126 
              + lhs->e167 * rhs->e234 + lhs->e267 * rhs->e134 + lhs->e367 * rhs->e124 
              + lhs->e467 * rhs->e123;
  res.e123567 = lhs->r * rhs->e123567 + lhs->e123567 * rhs->r + lhs->e1 * rhs->e23567 
              + lhs->e23567 * rhs->e1 + lhs->e2 * rhs->e13567 + lhs->e13567 * rhs->e2 
              + lhs->e3 * rhs->e12567 + lhs->e12567 * rhs->e3 + lhs->e5 * rhs->e12367 
              + lhs->e12367 * rhs->e5 + lhs->e6 * rhs->e12357 + lhs->e12357 * rhs->e6 
              + lhs->e7 * rhs->e12356 + lhs->e12356 * rhs->e7 + lhs->e12 * rhs->e3567 
              + lhs->e3567 * rhs->e12 + lhs->e13 * rhs->e2567 + lhs->e2567 * rhs->e13 
              + lhs->e23 * rhs->e1567 + lhs->e1567 * rhs->e23 + lhs->e15 * rhs->e2367 
              + lhs->e2367 * rhs->e15 + lhs->e25 * rhs->e1367 + lhs->e1367 * rhs->e25 
              + lhs->e35 * rhs->e1267 + lhs->e1267 * rhs->e35 + lhs->e16 * rhs->e2357 
              + lhs->e2357 * rhs->e16 + lhs->e26 * rhs->e1357 + lhs->e1357 * rhs->e26 
              + lhs->e36 * rhs->e1257 + lhs->e1257 * rhs->e36 + lhs->e56 * rhs->e1237 
              + lhs->e1237 * rhs->e56 + lhs->e17 * rhs->e2356 + lhs->e2356 * rhs->e17 
              + lhs->e27 * rhs->e1356 + lhs->e1356 * rhs->e27 + lhs->e37 * rhs->e1256 
              + lhs->e1256 * rhs->e37 + lhs->e57 * rhs->e1236 + lhs->e1236 * rhs->e57 
              + lhs->e67 * rhs->e1235 + lhs->e1235 * rhs->e67 + lhs->e123 * rhs->e567 
              + lhs->e125 * rhs->e367 + lhs->e135 * rhs->e267 + lhs->e235 * rhs->e167 
              + lhs->e126 * rhs->e357 + lhs->e136 * rhs->e257 + lhs->e236 * rhs->e157 
              + lhs->e156 * rhs->e237 + lhs->e256 * rhs->e137 + lhs->e356 * rhs->e127 
              + lhs->e127 * rhs->e356 + lhs->e137 * rhs->e256 + lhs->e237 * rhs->e156 
              + lhs->e157 * rhs->e236 + lhs->e257 * rhs->e136 + lhs->e357 * rhs->e126 
              + lhs->e167 * rhs->e235 + lhs->e267 * rhs->e135 + lhs->e367 * rhs->e125 
              + lhs->e567 * rhs->e123;
  res.e124567 = lhs->r * rhs->e124567 + lhs->e124567 * rhs->r + lhs->e1 * rhs->e24567 
              + lhs->e24567 * rhs->e1 + lhs->e2 * rhs->e14567 + lhs->e14567 * rhs->e2 
              + lhs->e4 * rhs->e12567 + lhs->e12567 * rhs->e4 + lhs->e5 * rhs->e12467 
              + lhs->e12467 * rhs->e5 + lhs->e6 * rhs->e12457 + lhs->e12457 * rhs->e6 
              + lhs->e7 * rhs->e12456 + lhs->e12456 * rhs->e7 + lhs->e12 * rhs->e4567 
              + lhs->e4567 * rhs->e12 + lhs->e14 * rhs->e2567 + lhs->e2567 * rhs->e14 
              + lhs->e24 * rhs->e1567 + lhs->e1567 * rhs->e24 + lhs->e15 * rhs->e2467 
              + lhs->e2467 * rhs->e15 + lhs->e25 * rhs->e1467 + lhs->e1467 * rhs->e25 
              + lhs->e45 * rhs->e1267 + lhs->e1267 * rhs->e45 + lhs->e16 * rhs->e2457 
              + lhs->e2457 * rhs->e16 + lhs->e26 * rhs->e1457 + lhs->e1457 * rhs->e26 
              + lhs->e46 * rhs->e1257 + lhs->e1257 * rhs->e46 + lhs->e56 * rhs->e1247 
              + lhs->e1247 * rhs->e56 + lhs->e17 * rhs->e2456 + lhs->e2456 * rhs->e17 
              + lhs->e27 * rhs->e1456 + lhs->e1456 * rhs->e27 + lhs->e47 * rhs->e1256 
              + lhs->e1256 * rhs->e47 + lhs->e57 * rhs->e1246 + lhs->e1246 * rhs->e57 
              + lhs->e67 * rhs->e1245 + lhs->e1245 * rhs->e67 + lhs->e124 * rhs->e567 
              + lhs->e125 * rhs->e467 + lhs->e145 * rhs->e267 + lhs->e245 * rhs->e167 
              + lhs->e126 * rhs->e457 + lhs->e146 * rhs->e257 + lhs->e246 * rhs->e157 
              + lhs->e156 * rhs->e247 + lhs->e256 * rhs->e147 + lhs->e456 * rhs->e127 
              + lhs->e127 * rhs->e456 + lhs->e147 * rhs->e256 + lhs->e247 * rhs->e156 
              + lhs->e157 * rhs->e246 + lhs->e257 * rhs->e146 + lhs->e457 * rhs->e126 
              + lhs->e167 * rhs->e245 + lhs->e267 * rhs->e145 + lhs->e467 * rhs->e125 
              + lhs->e567 * rhs->e124;
  res.e134567 = lhs->r * rhs->e134567 + lhs->e134567 * rhs->r + lhs->e1 * rhs->e34567 
              + lhs->e34567 * rhs->e1 + lhs->e3 * rhs->e14567 + lhs->e14567 * rhs->e3 
              + lhs->e4 * rhs->e13567 + lhs->e13567 * rhs->e4 + lhs->e5 * rhs->e13467 
              + lhs->e13467 * rhs->e5 + lhs->e6 * rhs->e13457 + lhs->e13457 * rhs->e6 
              + lhs->e7 * rhs->e13456 + lhs->e13456 * rhs->e7 + lhs->e13 * rhs->e4567 
              + lhs->e4567 * rhs->e13 + lhs->e14 * rhs->e3567 + lhs->e3567 * rhs->e14 
              + lhs->e34 * rhs->e1567 + lhs->e1567 * rhs->e34 + lhs->e15 * rhs->e3467 
              + lhs->e3467 * rhs->e15 + lhs->e35 * rhs->e1467 + lhs->e1467 * rhs->e35 
              + lhs->e45 * rhs->e1367 + lhs->e1367 * rhs->e45 + lhs->e16 * rhs->e3457 
              + lhs->e3457 * rhs->e16 + lhs->e36 * rhs->e1457 + lhs->e1457 * rhs->e36 
              + lhs->e46 * rhs->e1357 + lhs->e1357 * rhs->e46 + lhs->e56 * rhs->e1347 
              + lhs->e1347 * rhs->e56 + lhs->e17 * rhs->e3456 + lhs->e3456 * rhs->e17 
              + lhs->e37 * rhs->e1456 + lhs->e1456 * rhs->e37 + lhs->e47 * rhs->e1356 
              + lhs->e1356 * rhs->e47 + lhs->e57 * rhs->e1346 + lhs->e1346 * rhs->e57 
              + lhs->e67 * rhs->e1345 + lhs->e1345 * rhs->e67 + lhs->e134 * rhs->e567 
              + lhs->e135 * rhs->e467 + lhs->e145 * rhs->e367 + lhs->e345 * rhs->e167 
              + lhs->e136 * rhs->e457 + lhs->e146 * rhs->e357 + lhs->e346 * rhs->e157 
              + lhs->e156 * rhs->e347 + lhs->e356 * rhs->e147 + lhs->e456 * rhs->e137 
              + lhs->e137 * rhs->e456 + lhs->e147 * rhs->e356 + lhs->e347 * rhs->e156 
              + lhs->e157 * rhs->e346 + lhs->e357 * rhs->e146 + lhs->e457 * rhs->e136 
              + lhs->e167 * rhs->e345 + lhs->e367 * rhs->e145 + lhs->e467 * rhs->e135 
              + lhs->e567 * rhs->e134;
  res.e234567 = lhs->r * rhs->e234567 + lhs->e234567 * rhs->r + lhs->e2 * rhs->e34567 
              + lhs->e34567 * rhs->e2 + lhs->e3 * rhs->e24567 + lhs->e24567 * rhs->e3 
              + lhs->e4 * rhs->e23567 + lhs->e23567 * rhs->e4 + lhs->e5 * rhs->e23467 
              + lhs->e23467 * rhs->e5 + lhs->e6 * rhs->e23457 + lhs->e23457 * rhs->e6 
              + lhs->e7 * rhs->e23456 + lhs->e23456 * rhs->e7 + lhs->e23 * rhs->e4567 
              + lhs->e4567 * rhs->e23 + lhs->e24 * rhs->e3567 + lhs->e3567 * rhs->e24 
              + lhs->e34 * rhs->e2567 + lhs->e2567 * rhs->e34 + lhs->e25 * rhs->e3467 
              + lhs->e3467 * rhs->e25 + lhs->e35 * rhs->e2467 + lhs->e2467 * rhs->e35 
              + lhs->e45 * rhs->e2367 + lhs->e2367 * rhs->e45 + lhs->e26 * rhs->e3457 
              + lhs->e3457 * rhs->e26 + lhs->e36 * rhs->e2457 + lhs->e2457 * rhs->e36 
              + lhs->e46 * rhs->e2357 + lhs->e2357 * rhs->e46 + lhs->e56 * rhs->e2347 
              + lhs->e2347 * rhs->e56 + lhs->e27 * rhs->e3456 + lhs->e3456 * rhs->e27 
              + lhs->e37 * rhs->e2456 + lhs->e2456 * rhs->e37 + lhs->e47 * rhs->e2356 
              + lhs->e2356 * rhs->e47 + lhs->e57 * rhs->e2346 + lhs->e2346 * rhs->e57 
              + lhs->e67 * rhs->e2345 + lhs->e2345 * rhs->e67 + lhs->e234 * rhs->e567 
              + lhs->e235 * rhs->e467 + lhs->e245 * rhs->e367 + lhs->e345 * rhs->e267 
              + lhs->e236 * rhs->e457 + lhs->e246 * rhs->e357 + lhs->e346 * rhs->e257 
              + lhs->e256 * rhs->e347 + lhs->e356 * rhs->e247 + lhs->e456 * rhs->e237 
              + lhs->e237 * rhs->e456 + lhs->e247 * rhs->e356 + lhs->e347 * rhs->e256 
              + lhs->e257 * rhs->e346 + lhs->e357 * rhs->e246 + lhs->e457 * rhs->e236 
              + lhs->e267 * rhs->e345 + lhs->e367 * rhs->e245 + lhs->e467 * rhs->e235 
              + lhs->e567 * rhs->e234;
  // Order 7;
  res.e1234567 = lhs->r * rhs->e1234567 + lhs->e1234567 * rhs->r + lhs->e1 * rhs->e234567 
               + lhs->e234567 * rhs->e1 + lhs->e2 * rhs->e134567 + lhs->e134567 * rhs->e2 
               + lhs->e3 * rhs->e124567 + lhs->e124567 * rhs->e3 + lhs->e4 * rhs->e123567 
               + lhs->e123567 * rhs->e4 + lhs->e5 * rhs->e123467 + lhs->e123467 * rhs->e5 
               + lhs->e6 * rhs->e123457 + lhs->e123457 * rhs->e6 + lhs->e7 * rhs->e123456 
               + lhs->e123456 * rhs->e7 + lhs->e12 * rhs->e34567 + lhs->e34567 * rhs->e12 
               + lhs->e13 * rhs->e24567 + lhs->e24567 * rhs->e13 + lhs->e23 * rhs->e14567 
               + lhs->e14567 * rhs->e23 + lhs->e14 * rhs->e23567 + lhs->e23567 * rhs->e14 
               + lhs->e24 * rhs->e13567 + lhs->e13567 * rhs->e24 + lhs->e34 * rhs->e12567 
               + lhs->e12567 * rhs->e34 + lhs->e15 * rhs->e23467 + lhs->e23467 * rhs->e15 
               + lhs->e25 * rhs->e13467 + lhs->e13467 * rhs->e25 + lhs->e35 * rhs->e12467 
               + lhs->e12467 * rhs->e35 + lhs->e45 * rhs->e12367 + lhs->e12367 * rhs->e45 
               + lhs->e16 * rhs->e23457 + lhs->e23457 * rhs->e16 + lhs->e26 * rhs->e13457 
               + lhs->e13457 * rhs->e26 + lhs->e36 * rhs->e12457 + lhs->e12457 * rhs->e36 
               + lhs->e46 * rhs->e12357 + lhs->e12357 * rhs->e46 + lhs->e56 * rhs->e12347 
               + lhs->e12347 * rhs->e56 + lhs->e17 * rhs->e23456 + lhs->e23456 * rhs->e17 
               + lhs->e27 * rhs->e13456 + lhs->e13456 * rhs->e27 + lhs->e37 * rhs->e12456 
               + lhs->e12456 * rhs->e37 + lhs->e47 * rhs->e12356 + lhs->e12356 * rhs->e47 
               + lhs->e57 * rhs->e12346 + lhs->e12346 * rhs->e57 + lhs->e67 * rhs->e12345 
               + lhs->e12345 * rhs->e67 + lhs->e123 * rhs->e4567 + lhs->e4567 * rhs->e123 
               + lhs->e124 * rhs->e3567 + lhs->e3567 * rhs->e124 + lhs->e134 * rhs->e2567 
               + lhs->e2567 * rhs->e134 + lhs->e234 * rhs->e1567 + lhs->e1567 * rhs->e234 
               + lhs->e125 * rhs->e3467 + lhs->e3467 * rhs->e125 + lhs->e135 * rhs->e2467 
               + lhs->e2467 * rhs->e135 + lhs->e235 * rhs->e1467 + lhs->e1467 * rhs->e235 
               + lhs->e145 * rhs->e2367 + lhs->e2367 * rhs->e145 + lhs->e245 * rhs->e1367 
               + lhs->e1367 * rhs->e245 + lhs->e345 * rhs->e1267 + lhs->e1267 * rhs->e345 
               + lhs->e126 * rhs->e3457 + lhs->e3457 * rhs->e126 + lhs->e136 * rhs->e2457 
               + lhs->e2457 * rhs->e136 + lhs->e236 * rhs->e1457 + lhs->e1457 * rhs->e236 
               + lhs->e146 * rhs->e2357 + lhs->e2357 * rhs->e146 + lhs->e246 * rhs->e1357 
               + lhs->e1357 * rhs->e246 + lhs->e346 * rhs->e1257 + lhs->e1257 * rhs->e346 
               + lhs->e156 * rhs->e2347 + lhs->e2347 * rhs->e156 + lhs->e256 * rhs->e1347 
               + lhs->e1347 * rhs->e256 + lhs->e356 * rhs->e1247 + lhs->e1247 * rhs->e356 
               + lhs->e456 * rhs->e1237 + lhs->e1237 * rhs->e456 + lhs->e127 * rhs->e3456 
               + lhs->e3456 * rhs->e127 + lhs->e137 * rhs->e2456 + lhs->e2456 * rhs->e137 
               + lhs->e237 * rhs->e1456 + lhs->e1456 * rhs->e237 + lhs->e147 * rhs->e2356 
               + lhs->e2356 * rhs->e147 + lhs->e247 * rhs->e1356 + lhs->e1356 * rhs->e247 
               + lhs->e347 * rhs->e1256 + lhs->e1256 * rhs->e347 + lhs->e157 * rhs->e2346 
               + lhs->e2346 * rhs->e157 + lhs->e257 * rhs->e1346 + lhs->e1346 * rhs->e257 
               + lhs->e357 * rhs->e1246 + lhs->e1246 * rhs->e357 + lhs->e457 * rhs->e1236 
               + lhs->e1236 * rhs->e457 + lhs->e167 * rhs->e2345 + lhs->e2345 * rhs->e167 
               + lhs->e267 * rhs->e1345 + lhs->e1345 * rhs->e267 + lhs->e367 * rhs->e1245 
               + lhs->e1245 * rhs->e367 + lhs->e467 * rhs->e1235 + lhs->e1235 * rhs->e467 
               + lhs->e567 * rhs->e1234 + lhs->e1234 * rhs->e567;

  return res;

}

void mdnum7_mul_oo_to(  mdnum7_t* lhs,  mdnum7_t* rhs, mdnum7_t* res){
  //  Multiplication like function 'lhs * rhs'
  // Real;
  res->r = lhs->r * rhs->r;
  // Order 1;
  res->e1 = lhs->r * rhs->e1 + lhs->e1 * rhs->r;
  res->e2 = lhs->r * rhs->e2 + lhs->e2 * rhs->r;
  res->e3 = lhs->r * rhs->e3 + lhs->e3 * rhs->r;
  res->e4 = lhs->r * rhs->e4 + lhs->e4 * rhs->r;
  res->e5 = lhs->r * rhs->e5 + lhs->e5 * rhs->r;
  res->e6 = lhs->r * rhs->e6 + lhs->e6 * rhs->r;
  res->e7 = lhs->r * rhs->e7 + lhs->e7 * rhs->r;
  // Order 2;
  res->e12 = lhs->r * rhs->e12 + lhs->e12 * rhs->r + lhs->e1 * rhs->e2 
          + lhs->e2 * rhs->e1;
  res->e13 = lhs->r * rhs->e13 + lhs->e13 * rhs->r + lhs->e1 * rhs->e3 
          + lhs->e3 * rhs->e1;
  res->e23 = lhs->r * rhs->e23 + lhs->e23 * rhs->r + lhs->e2 * rhs->e3 
          + lhs->e3 * rhs->e2;
  res->e14 = lhs->r * rhs->e14 + lhs->e14 * rhs->r + lhs->e1 * rhs->e4 
          + lhs->e4 * rhs->e1;
  res->e24 = lhs->r * rhs->e24 + lhs->e24 * rhs->r + lhs->e2 * rhs->e4 
          + lhs->e4 * rhs->e2;
  res->e34 = lhs->r * rhs->e34 + lhs->e34 * rhs->r + lhs->e3 * rhs->e4 
          + lhs->e4 * rhs->e3;
  res->e15 = lhs->r * rhs->e15 + lhs->e15 * rhs->r + lhs->e1 * rhs->e5 
          + lhs->e5 * rhs->e1;
  res->e25 = lhs->r * rhs->e25 + lhs->e25 * rhs->r + lhs->e2 * rhs->e5 
          + lhs->e5 * rhs->e2;
  res->e35 = lhs->r * rhs->e35 + lhs->e35 * rhs->r + lhs->e3 * rhs->e5 
          + lhs->e5 * rhs->e3;
  res->e45 = lhs->r * rhs->e45 + lhs->e45 * rhs->r + lhs->e4 * rhs->e5 
          + lhs->e5 * rhs->e4;
  res->e16 = lhs->r * rhs->e16 + lhs->e16 * rhs->r + lhs->e1 * rhs->e6 
          + lhs->e6 * rhs->e1;
  res->e26 = lhs->r * rhs->e26 + lhs->e26 * rhs->r + lhs->e2 * rhs->e6 
          + lhs->e6 * rhs->e2;
  res->e36 = lhs->r * rhs->e36 + lhs->e36 * rhs->r + lhs->e3 * rhs->e6 
          + lhs->e6 * rhs->e3;
  res->e46 = lhs->r * rhs->e46 + lhs->e46 * rhs->r + lhs->e4 * rhs->e6 
          + lhs->e6 * rhs->e4;
  res->e56 = lhs->r * rhs->e56 + lhs->e56 * rhs->r + lhs->e5 * rhs->e6 
          + lhs->e6 * rhs->e5;
  res->e17 = lhs->r * rhs->e17 + lhs->e17 * rhs->r + lhs->e1 * rhs->e7 
          + lhs->e7 * rhs->e1;
  res->e27 = lhs->r * rhs->e27 + lhs->e27 * rhs->r + lhs->e2 * rhs->e7 
          + lhs->e7 * rhs->e2;
  res->e37 = lhs->r * rhs->e37 + lhs->e37 * rhs->r + lhs->e3 * rhs->e7 
          + lhs->e7 * rhs->e3;
  res->e47 = lhs->r * rhs->e47 + lhs->e47 * rhs->r + lhs->e4 * rhs->e7 
          + lhs->e7 * rhs->e4;
  res->e57 = lhs->r * rhs->e57 + lhs->e57 * rhs->r + lhs->e5 * rhs->e7 
          + lhs->e7 * rhs->e5;
  res->e67 = lhs->r * rhs->e67 + lhs->e67 * rhs->r + lhs->e6 * rhs->e7 
          + lhs->e7 * rhs->e6;
  // Order 3;
  res->e123 = lhs->r * rhs->e123 + lhs->e123 * rhs->r + lhs->e1 * rhs->e23 
           + lhs->e23 * rhs->e1 + lhs->e2 * rhs->e13 + lhs->e13 * rhs->e2 
           + lhs->e3 * rhs->e12 + lhs->e12 * rhs->e3;
  res->e124 = lhs->r * rhs->e124 + lhs->e124 * rhs->r + lhs->e1 * rhs->e24 
           + lhs->e24 * rhs->e1 + lhs->e2 * rhs->e14 + lhs->e14 * rhs->e2 
           + lhs->e4 * rhs->e12 + lhs->e12 * rhs->e4;
  res->e134 = lhs->r * rhs->e134 + lhs->e134 * rhs->r + lhs->e1 * rhs->e34 
           + lhs->e34 * rhs->e1 + lhs->e3 * rhs->e14 + lhs->e14 * rhs->e3 
           + lhs->e4 * rhs->e13 + lhs->e13 * rhs->e4;
  res->e234 = lhs->r * rhs->e234 + lhs->e234 * rhs->r + lhs->e2 * rhs->e34 
           + lhs->e34 * rhs->e2 + lhs->e3 * rhs->e24 + lhs->e24 * rhs->e3 
           + lhs->e4 * rhs->e23 + lhs->e23 * rhs->e4;
  res->e125 = lhs->r * rhs->e125 + lhs->e125 * rhs->r + lhs->e1 * rhs->e25 
           + lhs->e25 * rhs->e1 + lhs->e2 * rhs->e15 + lhs->e15 * rhs->e2 
           + lhs->e5 * rhs->e12 + lhs->e12 * rhs->e5;
  res->e135 = lhs->r * rhs->e135 + lhs->e135 * rhs->r + lhs->e1 * rhs->e35 
           + lhs->e35 * rhs->e1 + lhs->e3 * rhs->e15 + lhs->e15 * rhs->e3 
           + lhs->e5 * rhs->e13 + lhs->e13 * rhs->e5;
  res->e235 = lhs->r * rhs->e235 + lhs->e235 * rhs->r + lhs->e2 * rhs->e35 
           + lhs->e35 * rhs->e2 + lhs->e3 * rhs->e25 + lhs->e25 * rhs->e3 
           + lhs->e5 * rhs->e23 + lhs->e23 * rhs->e5;
  res->e145 = lhs->r * rhs->e145 + lhs->e145 * rhs->r + lhs->e1 * rhs->e45 
           + lhs->e45 * rhs->e1 + lhs->e4 * rhs->e15 + lhs->e15 * rhs->e4 
           + lhs->e5 * rhs->e14 + lhs->e14 * rhs->e5;
  res->e245 = lhs->r * rhs->e245 + lhs->e245 * rhs->r + lhs->e2 * rhs->e45 
           + lhs->e45 * rhs->e2 + lhs->e4 * rhs->e25 + lhs->e25 * rhs->e4 
           + lhs->e5 * rhs->e24 + lhs->e24 * rhs->e5;
  res->e345 = lhs->r * rhs->e345 + lhs->e345 * rhs->r + lhs->e3 * rhs->e45 
           + lhs->e45 * rhs->e3 + lhs->e4 * rhs->e35 + lhs->e35 * rhs->e4 
           + lhs->e5 * rhs->e34 + lhs->e34 * rhs->e5;
  res->e126 = lhs->r * rhs->e126 + lhs->e126 * rhs->r + lhs->e1 * rhs->e26 
           + lhs->e26 * rhs->e1 + lhs->e2 * rhs->e16 + lhs->e16 * rhs->e2 
           + lhs->e6 * rhs->e12 + lhs->e12 * rhs->e6;
  res->e136 = lhs->r * rhs->e136 + lhs->e136 * rhs->r + lhs->e1 * rhs->e36 
           + lhs->e36 * rhs->e1 + lhs->e3 * rhs->e16 + lhs->e16 * rhs->e3 
           + lhs->e6 * rhs->e13 + lhs->e13 * rhs->e6;
  res->e236 = lhs->r * rhs->e236 + lhs->e236 * rhs->r + lhs->e2 * rhs->e36 
           + lhs->e36 * rhs->e2 + lhs->e3 * rhs->e26 + lhs->e26 * rhs->e3 
           + lhs->e6 * rhs->e23 + lhs->e23 * rhs->e6;
  res->e146 = lhs->r * rhs->e146 + lhs->e146 * rhs->r + lhs->e1 * rhs->e46 
           + lhs->e46 * rhs->e1 + lhs->e4 * rhs->e16 + lhs->e16 * rhs->e4 
           + lhs->e6 * rhs->e14 + lhs->e14 * rhs->e6;
  res->e246 = lhs->r * rhs->e246 + lhs->e246 * rhs->r + lhs->e2 * rhs->e46 
           + lhs->e46 * rhs->e2 + lhs->e4 * rhs->e26 + lhs->e26 * rhs->e4 
           + lhs->e6 * rhs->e24 + lhs->e24 * rhs->e6;
  res->e346 = lhs->r * rhs->e346 + lhs->e346 * rhs->r + lhs->e3 * rhs->e46 
           + lhs->e46 * rhs->e3 + lhs->e4 * rhs->e36 + lhs->e36 * rhs->e4 
           + lhs->e6 * rhs->e34 + lhs->e34 * rhs->e6;
  res->e156 = lhs->r * rhs->e156 + lhs->e156 * rhs->r + lhs->e1 * rhs->e56 
           + lhs->e56 * rhs->e1 + lhs->e5 * rhs->e16 + lhs->e16 * rhs->e5 
           + lhs->e6 * rhs->e15 + lhs->e15 * rhs->e6;
  res->e256 = lhs->r * rhs->e256 + lhs->e256 * rhs->r + lhs->e2 * rhs->e56 
           + lhs->e56 * rhs->e2 + lhs->e5 * rhs->e26 + lhs->e26 * rhs->e5 
           + lhs->e6 * rhs->e25 + lhs->e25 * rhs->e6;
  res->e356 = lhs->r * rhs->e356 + lhs->e356 * rhs->r + lhs->e3 * rhs->e56 
           + lhs->e56 * rhs->e3 + lhs->e5 * rhs->e36 + lhs->e36 * rhs->e5 
           + lhs->e6 * rhs->e35 + lhs->e35 * rhs->e6;
  res->e456 = lhs->r * rhs->e456 + lhs->e456 * rhs->r + lhs->e4 * rhs->e56 
           + lhs->e56 * rhs->e4 + lhs->e5 * rhs->e46 + lhs->e46 * rhs->e5 
           + lhs->e6 * rhs->e45 + lhs->e45 * rhs->e6;
  res->e127 = lhs->r * rhs->e127 + lhs->e127 * rhs->r + lhs->e1 * rhs->e27 
           + lhs->e27 * rhs->e1 + lhs->e2 * rhs->e17 + lhs->e17 * rhs->e2 
           + lhs->e7 * rhs->e12 + lhs->e12 * rhs->e7;
  res->e137 = lhs->r * rhs->e137 + lhs->e137 * rhs->r + lhs->e1 * rhs->e37 
           + lhs->e37 * rhs->e1 + lhs->e3 * rhs->e17 + lhs->e17 * rhs->e3 
           + lhs->e7 * rhs->e13 + lhs->e13 * rhs->e7;
  res->e237 = lhs->r * rhs->e237 + lhs->e237 * rhs->r + lhs->e2 * rhs->e37 
           + lhs->e37 * rhs->e2 + lhs->e3 * rhs->e27 + lhs->e27 * rhs->e3 
           + lhs->e7 * rhs->e23 + lhs->e23 * rhs->e7;
  res->e147 = lhs->r * rhs->e147 + lhs->e147 * rhs->r + lhs->e1 * rhs->e47 
           + lhs->e47 * rhs->e1 + lhs->e4 * rhs->e17 + lhs->e17 * rhs->e4 
           + lhs->e7 * rhs->e14 + lhs->e14 * rhs->e7;
  res->e247 = lhs->r * rhs->e247 + lhs->e247 * rhs->r + lhs->e2 * rhs->e47 
           + lhs->e47 * rhs->e2 + lhs->e4 * rhs->e27 + lhs->e27 * rhs->e4 
           + lhs->e7 * rhs->e24 + lhs->e24 * rhs->e7;
  res->e347 = lhs->r * rhs->e347 + lhs->e347 * rhs->r + lhs->e3 * rhs->e47 
           + lhs->e47 * rhs->e3 + lhs->e4 * rhs->e37 + lhs->e37 * rhs->e4 
           + lhs->e7 * rhs->e34 + lhs->e34 * rhs->e7;
  res->e157 = lhs->r * rhs->e157 + lhs->e157 * rhs->r + lhs->e1 * rhs->e57 
           + lhs->e57 * rhs->e1 + lhs->e5 * rhs->e17 + lhs->e17 * rhs->e5 
           + lhs->e7 * rhs->e15 + lhs->e15 * rhs->e7;
  res->e257 = lhs->r * rhs->e257 + lhs->e257 * rhs->r + lhs->e2 * rhs->e57 
           + lhs->e57 * rhs->e2 + lhs->e5 * rhs->e27 + lhs->e27 * rhs->e5 
           + lhs->e7 * rhs->e25 + lhs->e25 * rhs->e7;
  res->e357 = lhs->r * rhs->e357 + lhs->e357 * rhs->r + lhs->e3 * rhs->e57 
           + lhs->e57 * rhs->e3 + lhs->e5 * rhs->e37 + lhs->e37 * rhs->e5 
           + lhs->e7 * rhs->e35 + lhs->e35 * rhs->e7;
  res->e457 = lhs->r * rhs->e457 + lhs->e457 * rhs->r + lhs->e4 * rhs->e57 
           + lhs->e57 * rhs->e4 + lhs->e5 * rhs->e47 + lhs->e47 * rhs->e5 
           + lhs->e7 * rhs->e45 + lhs->e45 * rhs->e7;
  res->e167 = lhs->r * rhs->e167 + lhs->e167 * rhs->r + lhs->e1 * rhs->e67 
           + lhs->e67 * rhs->e1 + lhs->e6 * rhs->e17 + lhs->e17 * rhs->e6 
           + lhs->e7 * rhs->e16 + lhs->e16 * rhs->e7;
  res->e267 = lhs->r * rhs->e267 + lhs->e267 * rhs->r + lhs->e2 * rhs->e67 
           + lhs->e67 * rhs->e2 + lhs->e6 * rhs->e27 + lhs->e27 * rhs->e6 
           + lhs->e7 * rhs->e26 + lhs->e26 * rhs->e7;
  res->e367 = lhs->r * rhs->e367 + lhs->e367 * rhs->r + lhs->e3 * rhs->e67 
           + lhs->e67 * rhs->e3 + lhs->e6 * rhs->e37 + lhs->e37 * rhs->e6 
           + lhs->e7 * rhs->e36 + lhs->e36 * rhs->e7;
  res->e467 = lhs->r * rhs->e467 + lhs->e467 * rhs->r + lhs->e4 * rhs->e67 
           + lhs->e67 * rhs->e4 + lhs->e6 * rhs->e47 + lhs->e47 * rhs->e6 
           + lhs->e7 * rhs->e46 + lhs->e46 * rhs->e7;
  res->e567 = lhs->r * rhs->e567 + lhs->e567 * rhs->r + lhs->e5 * rhs->e67 
           + lhs->e67 * rhs->e5 + lhs->e6 * rhs->e57 + lhs->e57 * rhs->e6 
           + lhs->e7 * rhs->e56 + lhs->e56 * rhs->e7;
  // Order 4;
  res->e1234 = lhs->r * rhs->e1234 + lhs->e1234 * rhs->r + lhs->e1 * rhs->e234 
            + lhs->e234 * rhs->e1 + lhs->e2 * rhs->e134 + lhs->e134 * rhs->e2 
            + lhs->e3 * rhs->e124 + lhs->e124 * rhs->e3 + lhs->e4 * rhs->e123 
            + lhs->e123 * rhs->e4 + lhs->e12 * rhs->e34 + lhs->e13 * rhs->e24 
            + lhs->e23 * rhs->e14 + lhs->e14 * rhs->e23 + lhs->e24 * rhs->e13 
            + lhs->e34 * rhs->e12;
  res->e1235 = lhs->r * rhs->e1235 + lhs->e1235 * rhs->r + lhs->e1 * rhs->e235 
            + lhs->e235 * rhs->e1 + lhs->e2 * rhs->e135 + lhs->e135 * rhs->e2 
            + lhs->e3 * rhs->e125 + lhs->e125 * rhs->e3 + lhs->e5 * rhs->e123 
            + lhs->e123 * rhs->e5 + lhs->e12 * rhs->e35 + lhs->e13 * rhs->e25 
            + lhs->e23 * rhs->e15 + lhs->e15 * rhs->e23 + lhs->e25 * rhs->e13 
            + lhs->e35 * rhs->e12;
  res->e1245 = lhs->r * rhs->e1245 + lhs->e1245 * rhs->r + lhs->e1 * rhs->e245 
            + lhs->e245 * rhs->e1 + lhs->e2 * rhs->e145 + lhs->e145 * rhs->e2 
            + lhs->e4 * rhs->e125 + lhs->e125 * rhs->e4 + lhs->e5 * rhs->e124 
            + lhs->e124 * rhs->e5 + lhs->e12 * rhs->e45 + lhs->e14 * rhs->e25 
            + lhs->e24 * rhs->e15 + lhs->e15 * rhs->e24 + lhs->e25 * rhs->e14 
            + lhs->e45 * rhs->e12;
  res->e1345 = lhs->r * rhs->e1345 + lhs->e1345 * rhs->r + lhs->e1 * rhs->e345 
            + lhs->e345 * rhs->e1 + lhs->e3 * rhs->e145 + lhs->e145 * rhs->e3 
            + lhs->e4 * rhs->e135 + lhs->e135 * rhs->e4 + lhs->e5 * rhs->e134 
            + lhs->e134 * rhs->e5 + lhs->e13 * rhs->e45 + lhs->e14 * rhs->e35 
            + lhs->e34 * rhs->e15 + lhs->e15 * rhs->e34 + lhs->e35 * rhs->e14 
            + lhs->e45 * rhs->e13;
  res->e2345 = lhs->r * rhs->e2345 + lhs->e2345 * rhs->r + lhs->e2 * rhs->e345 
            + lhs->e345 * rhs->e2 + lhs->e3 * rhs->e245 + lhs->e245 * rhs->e3 
            + lhs->e4 * rhs->e235 + lhs->e235 * rhs->e4 + lhs->e5 * rhs->e234 
            + lhs->e234 * rhs->e5 + lhs->e23 * rhs->e45 + lhs->e24 * rhs->e35 
            + lhs->e34 * rhs->e25 + lhs->e25 * rhs->e34 + lhs->e35 * rhs->e24 
            + lhs->e45 * rhs->e23;
  res->e1236 = lhs->r * rhs->e1236 + lhs->e1236 * rhs->r + lhs->e1 * rhs->e236 
            + lhs->e236 * rhs->e1 + lhs->e2 * rhs->e136 + lhs->e136 * rhs->e2 
            + lhs->e3 * rhs->e126 + lhs->e126 * rhs->e3 + lhs->e6 * rhs->e123 
            + lhs->e123 * rhs->e6 + lhs->e12 * rhs->e36 + lhs->e13 * rhs->e26 
            + lhs->e23 * rhs->e16 + lhs->e16 * rhs->e23 + lhs->e26 * rhs->e13 
            + lhs->e36 * rhs->e12;
  res->e1246 = lhs->r * rhs->e1246 + lhs->e1246 * rhs->r + lhs->e1 * rhs->e246 
            + lhs->e246 * rhs->e1 + lhs->e2 * rhs->e146 + lhs->e146 * rhs->e2 
            + lhs->e4 * rhs->e126 + lhs->e126 * rhs->e4 + lhs->e6 * rhs->e124 
            + lhs->e124 * rhs->e6 + lhs->e12 * rhs->e46 + lhs->e14 * rhs->e26 
            + lhs->e24 * rhs->e16 + lhs->e16 * rhs->e24 + lhs->e26 * rhs->e14 
            + lhs->e46 * rhs->e12;
  res->e1346 = lhs->r * rhs->e1346 + lhs->e1346 * rhs->r + lhs->e1 * rhs->e346 
            + lhs->e346 * rhs->e1 + lhs->e3 * rhs->e146 + lhs->e146 * rhs->e3 
            + lhs->e4 * rhs->e136 + lhs->e136 * rhs->e4 + lhs->e6 * rhs->e134 
            + lhs->e134 * rhs->e6 + lhs->e13 * rhs->e46 + lhs->e14 * rhs->e36 
            + lhs->e34 * rhs->e16 + lhs->e16 * rhs->e34 + lhs->e36 * rhs->e14 
            + lhs->e46 * rhs->e13;
  res->e2346 = lhs->r * rhs->e2346 + lhs->e2346 * rhs->r + lhs->e2 * rhs->e346 
            + lhs->e346 * rhs->e2 + lhs->e3 * rhs->e246 + lhs->e246 * rhs->e3 
            + lhs->e4 * rhs->e236 + lhs->e236 * rhs->e4 + lhs->e6 * rhs->e234 
            + lhs->e234 * rhs->e6 + lhs->e23 * rhs->e46 + lhs->e24 * rhs->e36 
            + lhs->e34 * rhs->e26 + lhs->e26 * rhs->e34 + lhs->e36 * rhs->e24 
            + lhs->e46 * rhs->e23;
  res->e1256 = lhs->r * rhs->e1256 + lhs->e1256 * rhs->r + lhs->e1 * rhs->e256 
            + lhs->e256 * rhs->e1 + lhs->e2 * rhs->e156 + lhs->e156 * rhs->e2 
            + lhs->e5 * rhs->e126 + lhs->e126 * rhs->e5 + lhs->e6 * rhs->e125 
            + lhs->e125 * rhs->e6 + lhs->e12 * rhs->e56 + lhs->e15 * rhs->e26 
            + lhs->e25 * rhs->e16 + lhs->e16 * rhs->e25 + lhs->e26 * rhs->e15 
            + lhs->e56 * rhs->e12;
  res->e1356 = lhs->r * rhs->e1356 + lhs->e1356 * rhs->r + lhs->e1 * rhs->e356 
            + lhs->e356 * rhs->e1 + lhs->e3 * rhs->e156 + lhs->e156 * rhs->e3 
            + lhs->e5 * rhs->e136 + lhs->e136 * rhs->e5 + lhs->e6 * rhs->e135 
            + lhs->e135 * rhs->e6 + lhs->e13 * rhs->e56 + lhs->e15 * rhs->e36 
            + lhs->e35 * rhs->e16 + lhs->e16 * rhs->e35 + lhs->e36 * rhs->e15 
            + lhs->e56 * rhs->e13;
  res->e2356 = lhs->r * rhs->e2356 + lhs->e2356 * rhs->r + lhs->e2 * rhs->e356 
            + lhs->e356 * rhs->e2 + lhs->e3 * rhs->e256 + lhs->e256 * rhs->e3 
            + lhs->e5 * rhs->e236 + lhs->e236 * rhs->e5 + lhs->e6 * rhs->e235 
            + lhs->e235 * rhs->e6 + lhs->e23 * rhs->e56 + lhs->e25 * rhs->e36 
            + lhs->e35 * rhs->e26 + lhs->e26 * rhs->e35 + lhs->e36 * rhs->e25 
            + lhs->e56 * rhs->e23;
  res->e1456 = lhs->r * rhs->e1456 + lhs->e1456 * rhs->r + lhs->e1 * rhs->e456 
            + lhs->e456 * rhs->e1 + lhs->e4 * rhs->e156 + lhs->e156 * rhs->e4 
            + lhs->e5 * rhs->e146 + lhs->e146 * rhs->e5 + lhs->e6 * rhs->e145 
            + lhs->e145 * rhs->e6 + lhs->e14 * rhs->e56 + lhs->e15 * rhs->e46 
            + lhs->e45 * rhs->e16 + lhs->e16 * rhs->e45 + lhs->e46 * rhs->e15 
            + lhs->e56 * rhs->e14;
  res->e2456 = lhs->r * rhs->e2456 + lhs->e2456 * rhs->r + lhs->e2 * rhs->e456 
            + lhs->e456 * rhs->e2 + lhs->e4 * rhs->e256 + lhs->e256 * rhs->e4 
            + lhs->e5 * rhs->e246 + lhs->e246 * rhs->e5 + lhs->e6 * rhs->e245 
            + lhs->e245 * rhs->e6 + lhs->e24 * rhs->e56 + lhs->e25 * rhs->e46 
            + lhs->e45 * rhs->e26 + lhs->e26 * rhs->e45 + lhs->e46 * rhs->e25 
            + lhs->e56 * rhs->e24;
  res->e3456 = lhs->r * rhs->e3456 + lhs->e3456 * rhs->r + lhs->e3 * rhs->e456 
            + lhs->e456 * rhs->e3 + lhs->e4 * rhs->e356 + lhs->e356 * rhs->e4 
            + lhs->e5 * rhs->e346 + lhs->e346 * rhs->e5 + lhs->e6 * rhs->e345 
            + lhs->e345 * rhs->e6 + lhs->e34 * rhs->e56 + lhs->e35 * rhs->e46 
            + lhs->e45 * rhs->e36 + lhs->e36 * rhs->e45 + lhs->e46 * rhs->e35 
            + lhs->e56 * rhs->e34;
  res->e1237 = lhs->r * rhs->e1237 + lhs->e1237 * rhs->r + lhs->e1 * rhs->e237 
            + lhs->e237 * rhs->e1 + lhs->e2 * rhs->e137 + lhs->e137 * rhs->e2 
            + lhs->e3 * rhs->e127 + lhs->e127 * rhs->e3 + lhs->e7 * rhs->e123 
            + lhs->e123 * rhs->e7 + lhs->e12 * rhs->e37 + lhs->e13 * rhs->e27 
            + lhs->e23 * rhs->e17 + lhs->e17 * rhs->e23 + lhs->e27 * rhs->e13 
            + lhs->e37 * rhs->e12;
  res->e1247 = lhs->r * rhs->e1247 + lhs->e1247 * rhs->r + lhs->e1 * rhs->e247 
            + lhs->e247 * rhs->e1 + lhs->e2 * rhs->e147 + lhs->e147 * rhs->e2 
            + lhs->e4 * rhs->e127 + lhs->e127 * rhs->e4 + lhs->e7 * rhs->e124 
            + lhs->e124 * rhs->e7 + lhs->e12 * rhs->e47 + lhs->e14 * rhs->e27 
            + lhs->e24 * rhs->e17 + lhs->e17 * rhs->e24 + lhs->e27 * rhs->e14 
            + lhs->e47 * rhs->e12;
  res->e1347 = lhs->r * rhs->e1347 + lhs->e1347 * rhs->r + lhs->e1 * rhs->e347 
            + lhs->e347 * rhs->e1 + lhs->e3 * rhs->e147 + lhs->e147 * rhs->e3 
            + lhs->e4 * rhs->e137 + lhs->e137 * rhs->e4 + lhs->e7 * rhs->e134 
            + lhs->e134 * rhs->e7 + lhs->e13 * rhs->e47 + lhs->e14 * rhs->e37 
            + lhs->e34 * rhs->e17 + lhs->e17 * rhs->e34 + lhs->e37 * rhs->e14 
            + lhs->e47 * rhs->e13;
  res->e2347 = lhs->r * rhs->e2347 + lhs->e2347 * rhs->r + lhs->e2 * rhs->e347 
            + lhs->e347 * rhs->e2 + lhs->e3 * rhs->e247 + lhs->e247 * rhs->e3 
            + lhs->e4 * rhs->e237 + lhs->e237 * rhs->e4 + lhs->e7 * rhs->e234 
            + lhs->e234 * rhs->e7 + lhs->e23 * rhs->e47 + lhs->e24 * rhs->e37 
            + lhs->e34 * rhs->e27 + lhs->e27 * rhs->e34 + lhs->e37 * rhs->e24 
            + lhs->e47 * rhs->e23;
  res->e1257 = lhs->r * rhs->e1257 + lhs->e1257 * rhs->r + lhs->e1 * rhs->e257 
            + lhs->e257 * rhs->e1 + lhs->e2 * rhs->e157 + lhs->e157 * rhs->e2 
            + lhs->e5 * rhs->e127 + lhs->e127 * rhs->e5 + lhs->e7 * rhs->e125 
            + lhs->e125 * rhs->e7 + lhs->e12 * rhs->e57 + lhs->e15 * rhs->e27 
            + lhs->e25 * rhs->e17 + lhs->e17 * rhs->e25 + lhs->e27 * rhs->e15 
            + lhs->e57 * rhs->e12;
  res->e1357 = lhs->r * rhs->e1357 + lhs->e1357 * rhs->r + lhs->e1 * rhs->e357 
            + lhs->e357 * rhs->e1 + lhs->e3 * rhs->e157 + lhs->e157 * rhs->e3 
            + lhs->e5 * rhs->e137 + lhs->e137 * rhs->e5 + lhs->e7 * rhs->e135 
            + lhs->e135 * rhs->e7 + lhs->e13 * rhs->e57 + lhs->e15 * rhs->e37 
            + lhs->e35 * rhs->e17 + lhs->e17 * rhs->e35 + lhs->e37 * rhs->e15 
            + lhs->e57 * rhs->e13;
  res->e2357 = lhs->r * rhs->e2357 + lhs->e2357 * rhs->r + lhs->e2 * rhs->e357 
            + lhs->e357 * rhs->e2 + lhs->e3 * rhs->e257 + lhs->e257 * rhs->e3 
            + lhs->e5 * rhs->e237 + lhs->e237 * rhs->e5 + lhs->e7 * rhs->e235 
            + lhs->e235 * rhs->e7 + lhs->e23 * rhs->e57 + lhs->e25 * rhs->e37 
            + lhs->e35 * rhs->e27 + lhs->e27 * rhs->e35 + lhs->e37 * rhs->e25 
            + lhs->e57 * rhs->e23;
  res->e1457 = lhs->r * rhs->e1457 + lhs->e1457 * rhs->r + lhs->e1 * rhs->e457 
            + lhs->e457 * rhs->e1 + lhs->e4 * rhs->e157 + lhs->e157 * rhs->e4 
            + lhs->e5 * rhs->e147 + lhs->e147 * rhs->e5 + lhs->e7 * rhs->e145 
            + lhs->e145 * rhs->e7 + lhs->e14 * rhs->e57 + lhs->e15 * rhs->e47 
            + lhs->e45 * rhs->e17 + lhs->e17 * rhs->e45 + lhs->e47 * rhs->e15 
            + lhs->e57 * rhs->e14;
  res->e2457 = lhs->r * rhs->e2457 + lhs->e2457 * rhs->r + lhs->e2 * rhs->e457 
            + lhs->e457 * rhs->e2 + lhs->e4 * rhs->e257 + lhs->e257 * rhs->e4 
            + lhs->e5 * rhs->e247 + lhs->e247 * rhs->e5 + lhs->e7 * rhs->e245 
            + lhs->e245 * rhs->e7 + lhs->e24 * rhs->e57 + lhs->e25 * rhs->e47 
            + lhs->e45 * rhs->e27 + lhs->e27 * rhs->e45 + lhs->e47 * rhs->e25 
            + lhs->e57 * rhs->e24;
  res->e3457 = lhs->r * rhs->e3457 + lhs->e3457 * rhs->r + lhs->e3 * rhs->e457 
            + lhs->e457 * rhs->e3 + lhs->e4 * rhs->e357 + lhs->e357 * rhs->e4 
            + lhs->e5 * rhs->e347 + lhs->e347 * rhs->e5 + lhs->e7 * rhs->e345 
            + lhs->e345 * rhs->e7 + lhs->e34 * rhs->e57 + lhs->e35 * rhs->e47 
            + lhs->e45 * rhs->e37 + lhs->e37 * rhs->e45 + lhs->e47 * rhs->e35 
            + lhs->e57 * rhs->e34;
  res->e1267 = lhs->r * rhs->e1267 + lhs->e1267 * rhs->r + lhs->e1 * rhs->e267 
            + lhs->e267 * rhs->e1 + lhs->e2 * rhs->e167 + lhs->e167 * rhs->e2 
            + lhs->e6 * rhs->e127 + lhs->e127 * rhs->e6 + lhs->e7 * rhs->e126 
            + lhs->e126 * rhs->e7 + lhs->e12 * rhs->e67 + lhs->e16 * rhs->e27 
            + lhs->e26 * rhs->e17 + lhs->e17 * rhs->e26 + lhs->e27 * rhs->e16 
            + lhs->e67 * rhs->e12;
  res->e1367 = lhs->r * rhs->e1367 + lhs->e1367 * rhs->r + lhs->e1 * rhs->e367 
            + lhs->e367 * rhs->e1 + lhs->e3 * rhs->e167 + lhs->e167 * rhs->e3 
            + lhs->e6 * rhs->e137 + lhs->e137 * rhs->e6 + lhs->e7 * rhs->e136 
            + lhs->e136 * rhs->e7 + lhs->e13 * rhs->e67 + lhs->e16 * rhs->e37 
            + lhs->e36 * rhs->e17 + lhs->e17 * rhs->e36 + lhs->e37 * rhs->e16 
            + lhs->e67 * rhs->e13;
  res->e2367 = lhs->r * rhs->e2367 + lhs->e2367 * rhs->r + lhs->e2 * rhs->e367 
            + lhs->e367 * rhs->e2 + lhs->e3 * rhs->e267 + lhs->e267 * rhs->e3 
            + lhs->e6 * rhs->e237 + lhs->e237 * rhs->e6 + lhs->e7 * rhs->e236 
            + lhs->e236 * rhs->e7 + lhs->e23 * rhs->e67 + lhs->e26 * rhs->e37 
            + lhs->e36 * rhs->e27 + lhs->e27 * rhs->e36 + lhs->e37 * rhs->e26 
            + lhs->e67 * rhs->e23;
  res->e1467 = lhs->r * rhs->e1467 + lhs->e1467 * rhs->r + lhs->e1 * rhs->e467 
            + lhs->e467 * rhs->e1 + lhs->e4 * rhs->e167 + lhs->e167 * rhs->e4 
            + lhs->e6 * rhs->e147 + lhs->e147 * rhs->e6 + lhs->e7 * rhs->e146 
            + lhs->e146 * rhs->e7 + lhs->e14 * rhs->e67 + lhs->e16 * rhs->e47 
            + lhs->e46 * rhs->e17 + lhs->e17 * rhs->e46 + lhs->e47 * rhs->e16 
            + lhs->e67 * rhs->e14;
  res->e2467 = lhs->r * rhs->e2467 + lhs->e2467 * rhs->r + lhs->e2 * rhs->e467 
            + lhs->e467 * rhs->e2 + lhs->e4 * rhs->e267 + lhs->e267 * rhs->e4 
            + lhs->e6 * rhs->e247 + lhs->e247 * rhs->e6 + lhs->e7 * rhs->e246 
            + lhs->e246 * rhs->e7 + lhs->e24 * rhs->e67 + lhs->e26 * rhs->e47 
            + lhs->e46 * rhs->e27 + lhs->e27 * rhs->e46 + lhs->e47 * rhs->e26 
            + lhs->e67 * rhs->e24;
  res->e3467 = lhs->r * rhs->e3467 + lhs->e3467 * rhs->r + lhs->e3 * rhs->e467 
            + lhs->e467 * rhs->e3 + lhs->e4 * rhs->e367 + lhs->e367 * rhs->e4 
            + lhs->e6 * rhs->e347 + lhs->e347 * rhs->e6 + lhs->e7 * rhs->e346 
            + lhs->e346 * rhs->e7 + lhs->e34 * rhs->e67 + lhs->e36 * rhs->e47 
            + lhs->e46 * rhs->e37 + lhs->e37 * rhs->e46 + lhs->e47 * rhs->e36 
            + lhs->e67 * rhs->e34;
  res->e1567 = lhs->r * rhs->e1567 + lhs->e1567 * rhs->r + lhs->e1 * rhs->e567 
            + lhs->e567 * rhs->e1 + lhs->e5 * rhs->e167 + lhs->e167 * rhs->e5 
            + lhs->e6 * rhs->e157 + lhs->e157 * rhs->e6 + lhs->e7 * rhs->e156 
            + lhs->e156 * rhs->e7 + lhs->e15 * rhs->e67 + lhs->e16 * rhs->e57 
            + lhs->e56 * rhs->e17 + lhs->e17 * rhs->e56 + lhs->e57 * rhs->e16 
            + lhs->e67 * rhs->e15;
  res->e2567 = lhs->r * rhs->e2567 + lhs->e2567 * rhs->r + lhs->e2 * rhs->e567 
            + lhs->e567 * rhs->e2 + lhs->e5 * rhs->e267 + lhs->e267 * rhs->e5 
            + lhs->e6 * rhs->e257 + lhs->e257 * rhs->e6 + lhs->e7 * rhs->e256 
            + lhs->e256 * rhs->e7 + lhs->e25 * rhs->e67 + lhs->e26 * rhs->e57 
            + lhs->e56 * rhs->e27 + lhs->e27 * rhs->e56 + lhs->e57 * rhs->e26 
            + lhs->e67 * rhs->e25;
  res->e3567 = lhs->r * rhs->e3567 + lhs->e3567 * rhs->r + lhs->e3 * rhs->e567 
            + lhs->e567 * rhs->e3 + lhs->e5 * rhs->e367 + lhs->e367 * rhs->e5 
            + lhs->e6 * rhs->e357 + lhs->e357 * rhs->e6 + lhs->e7 * rhs->e356 
            + lhs->e356 * rhs->e7 + lhs->e35 * rhs->e67 + lhs->e36 * rhs->e57 
            + lhs->e56 * rhs->e37 + lhs->e37 * rhs->e56 + lhs->e57 * rhs->e36 
            + lhs->e67 * rhs->e35;
  res->e4567 = lhs->r * rhs->e4567 + lhs->e4567 * rhs->r + lhs->e4 * rhs->e567 
            + lhs->e567 * rhs->e4 + lhs->e5 * rhs->e467 + lhs->e467 * rhs->e5 
            + lhs->e6 * rhs->e457 + lhs->e457 * rhs->e6 + lhs->e7 * rhs->e456 
            + lhs->e456 * rhs->e7 + lhs->e45 * rhs->e67 + lhs->e46 * rhs->e57 
            + lhs->e56 * rhs->e47 + lhs->e47 * rhs->e56 + lhs->e57 * rhs->e46 
            + lhs->e67 * rhs->e45;
  // Order 5;
  res->e12345 = lhs->r * rhs->e12345 + lhs->e12345 * rhs->r + lhs->e1 * rhs->e2345 
             + lhs->e2345 * rhs->e1 + lhs->e2 * rhs->e1345 + lhs->e1345 * rhs->e2 
             + lhs->e3 * rhs->e1245 + lhs->e1245 * rhs->e3 + lhs->e4 * rhs->e1235 
             + lhs->e1235 * rhs->e4 + lhs->e5 * rhs->e1234 + lhs->e1234 * rhs->e5 
             + lhs->e12 * rhs->e345 + lhs->e345 * rhs->e12 + lhs->e13 * rhs->e245 
             + lhs->e245 * rhs->e13 + lhs->e23 * rhs->e145 + lhs->e145 * rhs->e23 
             + lhs->e14 * rhs->e235 + lhs->e235 * rhs->e14 + lhs->e24 * rhs->e135 
             + lhs->e135 * rhs->e24 + lhs->e34 * rhs->e125 + lhs->e125 * rhs->e34 
             + lhs->e15 * rhs->e234 + lhs->e234 * rhs->e15 + lhs->e25 * rhs->e134 
             + lhs->e134 * rhs->e25 + lhs->e35 * rhs->e124 + lhs->e124 * rhs->e35 
             + lhs->e45 * rhs->e123 + lhs->e123 * rhs->e45;
  res->e12346 = lhs->r * rhs->e12346 + lhs->e12346 * rhs->r + lhs->e1 * rhs->e2346 
             + lhs->e2346 * rhs->e1 + lhs->e2 * rhs->e1346 + lhs->e1346 * rhs->e2 
             + lhs->e3 * rhs->e1246 + lhs->e1246 * rhs->e3 + lhs->e4 * rhs->e1236 
             + lhs->e1236 * rhs->e4 + lhs->e6 * rhs->e1234 + lhs->e1234 * rhs->e6 
             + lhs->e12 * rhs->e346 + lhs->e346 * rhs->e12 + lhs->e13 * rhs->e246 
             + lhs->e246 * rhs->e13 + lhs->e23 * rhs->e146 + lhs->e146 * rhs->e23 
             + lhs->e14 * rhs->e236 + lhs->e236 * rhs->e14 + lhs->e24 * rhs->e136 
             + lhs->e136 * rhs->e24 + lhs->e34 * rhs->e126 + lhs->e126 * rhs->e34 
             + lhs->e16 * rhs->e234 + lhs->e234 * rhs->e16 + lhs->e26 * rhs->e134 
             + lhs->e134 * rhs->e26 + lhs->e36 * rhs->e124 + lhs->e124 * rhs->e36 
             + lhs->e46 * rhs->e123 + lhs->e123 * rhs->e46;
  res->e12356 = lhs->r * rhs->e12356 + lhs->e12356 * rhs->r + lhs->e1 * rhs->e2356 
             + lhs->e2356 * rhs->e1 + lhs->e2 * rhs->e1356 + lhs->e1356 * rhs->e2 
             + lhs->e3 * rhs->e1256 + lhs->e1256 * rhs->e3 + lhs->e5 * rhs->e1236 
             + lhs->e1236 * rhs->e5 + lhs->e6 * rhs->e1235 + lhs->e1235 * rhs->e6 
             + lhs->e12 * rhs->e356 + lhs->e356 * rhs->e12 + lhs->e13 * rhs->e256 
             + lhs->e256 * rhs->e13 + lhs->e23 * rhs->e156 + lhs->e156 * rhs->e23 
             + lhs->e15 * rhs->e236 + lhs->e236 * rhs->e15 + lhs->e25 * rhs->e136 
             + lhs->e136 * rhs->e25 + lhs->e35 * rhs->e126 + lhs->e126 * rhs->e35 
             + lhs->e16 * rhs->e235 + lhs->e235 * rhs->e16 + lhs->e26 * rhs->e135 
             + lhs->e135 * rhs->e26 + lhs->e36 * rhs->e125 + lhs->e125 * rhs->e36 
             + lhs->e56 * rhs->e123 + lhs->e123 * rhs->e56;
  res->e12456 = lhs->r * rhs->e12456 + lhs->e12456 * rhs->r + lhs->e1 * rhs->e2456 
             + lhs->e2456 * rhs->e1 + lhs->e2 * rhs->e1456 + lhs->e1456 * rhs->e2 
             + lhs->e4 * rhs->e1256 + lhs->e1256 * rhs->e4 + lhs->e5 * rhs->e1246 
             + lhs->e1246 * rhs->e5 + lhs->e6 * rhs->e1245 + lhs->e1245 * rhs->e6 
             + lhs->e12 * rhs->e456 + lhs->e456 * rhs->e12 + lhs->e14 * rhs->e256 
             + lhs->e256 * rhs->e14 + lhs->e24 * rhs->e156 + lhs->e156 * rhs->e24 
             + lhs->e15 * rhs->e246 + lhs->e246 * rhs->e15 + lhs->e25 * rhs->e146 
             + lhs->e146 * rhs->e25 + lhs->e45 * rhs->e126 + lhs->e126 * rhs->e45 
             + lhs->e16 * rhs->e245 + lhs->e245 * rhs->e16 + lhs->e26 * rhs->e145 
             + lhs->e145 * rhs->e26 + lhs->e46 * rhs->e125 + lhs->e125 * rhs->e46 
             + lhs->e56 * rhs->e124 + lhs->e124 * rhs->e56;
  res->e13456 = lhs->r * rhs->e13456 + lhs->e13456 * rhs->r + lhs->e1 * rhs->e3456 
             + lhs->e3456 * rhs->e1 + lhs->e3 * rhs->e1456 + lhs->e1456 * rhs->e3 
             + lhs->e4 * rhs->e1356 + lhs->e1356 * rhs->e4 + lhs->e5 * rhs->e1346 
             + lhs->e1346 * rhs->e5 + lhs->e6 * rhs->e1345 + lhs->e1345 * rhs->e6 
             + lhs->e13 * rhs->e456 + lhs->e456 * rhs->e13 + lhs->e14 * rhs->e356 
             + lhs->e356 * rhs->e14 + lhs->e34 * rhs->e156 + lhs->e156 * rhs->e34 
             + lhs->e15 * rhs->e346 + lhs->e346 * rhs->e15 + lhs->e35 * rhs->e146 
             + lhs->e146 * rhs->e35 + lhs->e45 * rhs->e136 + lhs->e136 * rhs->e45 
             + lhs->e16 * rhs->e345 + lhs->e345 * rhs->e16 + lhs->e36 * rhs->e145 
             + lhs->e145 * rhs->e36 + lhs->e46 * rhs->e135 + lhs->e135 * rhs->e46 
             + lhs->e56 * rhs->e134 + lhs->e134 * rhs->e56;
  res->e23456 = lhs->r * rhs->e23456 + lhs->e23456 * rhs->r + lhs->e2 * rhs->e3456 
             + lhs->e3456 * rhs->e2 + lhs->e3 * rhs->e2456 + lhs->e2456 * rhs->e3 
             + lhs->e4 * rhs->e2356 + lhs->e2356 * rhs->e4 + lhs->e5 * rhs->e2346 
             + lhs->e2346 * rhs->e5 + lhs->e6 * rhs->e2345 + lhs->e2345 * rhs->e6 
             + lhs->e23 * rhs->e456 + lhs->e456 * rhs->e23 + lhs->e24 * rhs->e356 
             + lhs->e356 * rhs->e24 + lhs->e34 * rhs->e256 + lhs->e256 * rhs->e34 
             + lhs->e25 * rhs->e346 + lhs->e346 * rhs->e25 + lhs->e35 * rhs->e246 
             + lhs->e246 * rhs->e35 + lhs->e45 * rhs->e236 + lhs->e236 * rhs->e45 
             + lhs->e26 * rhs->e345 + lhs->e345 * rhs->e26 + lhs->e36 * rhs->e245 
             + lhs->e245 * rhs->e36 + lhs->e46 * rhs->e235 + lhs->e235 * rhs->e46 
             + lhs->e56 * rhs->e234 + lhs->e234 * rhs->e56;
  res->e12347 = lhs->r * rhs->e12347 + lhs->e12347 * rhs->r + lhs->e1 * rhs->e2347 
             + lhs->e2347 * rhs->e1 + lhs->e2 * rhs->e1347 + lhs->e1347 * rhs->e2 
             + lhs->e3 * rhs->e1247 + lhs->e1247 * rhs->e3 + lhs->e4 * rhs->e1237 
             + lhs->e1237 * rhs->e4 + lhs->e7 * rhs->e1234 + lhs->e1234 * rhs->e7 
             + lhs->e12 * rhs->e347 + lhs->e347 * rhs->e12 + lhs->e13 * rhs->e247 
             + lhs->e247 * rhs->e13 + lhs->e23 * rhs->e147 + lhs->e147 * rhs->e23 
             + lhs->e14 * rhs->e237 + lhs->e237 * rhs->e14 + lhs->e24 * rhs->e137 
             + lhs->e137 * rhs->e24 + lhs->e34 * rhs->e127 + lhs->e127 * rhs->e34 
             + lhs->e17 * rhs->e234 + lhs->e234 * rhs->e17 + lhs->e27 * rhs->e134 
             + lhs->e134 * rhs->e27 + lhs->e37 * rhs->e124 + lhs->e124 * rhs->e37 
             + lhs->e47 * rhs->e123 + lhs->e123 * rhs->e47;
  res->e12357 = lhs->r * rhs->e12357 + lhs->e12357 * rhs->r + lhs->e1 * rhs->e2357 
             + lhs->e2357 * rhs->e1 + lhs->e2 * rhs->e1357 + lhs->e1357 * rhs->e2 
             + lhs->e3 * rhs->e1257 + lhs->e1257 * rhs->e3 + lhs->e5 * rhs->e1237 
             + lhs->e1237 * rhs->e5 + lhs->e7 * rhs->e1235 + lhs->e1235 * rhs->e7 
             + lhs->e12 * rhs->e357 + lhs->e357 * rhs->e12 + lhs->e13 * rhs->e257 
             + lhs->e257 * rhs->e13 + lhs->e23 * rhs->e157 + lhs->e157 * rhs->e23 
             + lhs->e15 * rhs->e237 + lhs->e237 * rhs->e15 + lhs->e25 * rhs->e137 
             + lhs->e137 * rhs->e25 + lhs->e35 * rhs->e127 + lhs->e127 * rhs->e35 
             + lhs->e17 * rhs->e235 + lhs->e235 * rhs->e17 + lhs->e27 * rhs->e135 
             + lhs->e135 * rhs->e27 + lhs->e37 * rhs->e125 + lhs->e125 * rhs->e37 
             + lhs->e57 * rhs->e123 + lhs->e123 * rhs->e57;
  res->e12457 = lhs->r * rhs->e12457 + lhs->e12457 * rhs->r + lhs->e1 * rhs->e2457 
             + lhs->e2457 * rhs->e1 + lhs->e2 * rhs->e1457 + lhs->e1457 * rhs->e2 
             + lhs->e4 * rhs->e1257 + lhs->e1257 * rhs->e4 + lhs->e5 * rhs->e1247 
             + lhs->e1247 * rhs->e5 + lhs->e7 * rhs->e1245 + lhs->e1245 * rhs->e7 
             + lhs->e12 * rhs->e457 + lhs->e457 * rhs->e12 + lhs->e14 * rhs->e257 
             + lhs->e257 * rhs->e14 + lhs->e24 * rhs->e157 + lhs->e157 * rhs->e24 
             + lhs->e15 * rhs->e247 + lhs->e247 * rhs->e15 + lhs->e25 * rhs->e147 
             + lhs->e147 * rhs->e25 + lhs->e45 * rhs->e127 + lhs->e127 * rhs->e45 
             + lhs->e17 * rhs->e245 + lhs->e245 * rhs->e17 + lhs->e27 * rhs->e145 
             + lhs->e145 * rhs->e27 + lhs->e47 * rhs->e125 + lhs->e125 * rhs->e47 
             + lhs->e57 * rhs->e124 + lhs->e124 * rhs->e57;
  res->e13457 = lhs->r * rhs->e13457 + lhs->e13457 * rhs->r + lhs->e1 * rhs->e3457 
             + lhs->e3457 * rhs->e1 + lhs->e3 * rhs->e1457 + lhs->e1457 * rhs->e3 
             + lhs->e4 * rhs->e1357 + lhs->e1357 * rhs->e4 + lhs->e5 * rhs->e1347 
             + lhs->e1347 * rhs->e5 + lhs->e7 * rhs->e1345 + lhs->e1345 * rhs->e7 
             + lhs->e13 * rhs->e457 + lhs->e457 * rhs->e13 + lhs->e14 * rhs->e357 
             + lhs->e357 * rhs->e14 + lhs->e34 * rhs->e157 + lhs->e157 * rhs->e34 
             + lhs->e15 * rhs->e347 + lhs->e347 * rhs->e15 + lhs->e35 * rhs->e147 
             + lhs->e147 * rhs->e35 + lhs->e45 * rhs->e137 + lhs->e137 * rhs->e45 
             + lhs->e17 * rhs->e345 + lhs->e345 * rhs->e17 + lhs->e37 * rhs->e145 
             + lhs->e145 * rhs->e37 + lhs->e47 * rhs->e135 + lhs->e135 * rhs->e47 
             + lhs->e57 * rhs->e134 + lhs->e134 * rhs->e57;
  res->e23457 = lhs->r * rhs->e23457 + lhs->e23457 * rhs->r + lhs->e2 * rhs->e3457 
             + lhs->e3457 * rhs->e2 + lhs->e3 * rhs->e2457 + lhs->e2457 * rhs->e3 
             + lhs->e4 * rhs->e2357 + lhs->e2357 * rhs->e4 + lhs->e5 * rhs->e2347 
             + lhs->e2347 * rhs->e5 + lhs->e7 * rhs->e2345 + lhs->e2345 * rhs->e7 
             + lhs->e23 * rhs->e457 + lhs->e457 * rhs->e23 + lhs->e24 * rhs->e357 
             + lhs->e357 * rhs->e24 + lhs->e34 * rhs->e257 + lhs->e257 * rhs->e34 
             + lhs->e25 * rhs->e347 + lhs->e347 * rhs->e25 + lhs->e35 * rhs->e247 
             + lhs->e247 * rhs->e35 + lhs->e45 * rhs->e237 + lhs->e237 * rhs->e45 
             + lhs->e27 * rhs->e345 + lhs->e345 * rhs->e27 + lhs->e37 * rhs->e245 
             + lhs->e245 * rhs->e37 + lhs->e47 * rhs->e235 + lhs->e235 * rhs->e47 
             + lhs->e57 * rhs->e234 + lhs->e234 * rhs->e57;
  res->e12367 = lhs->r * rhs->e12367 + lhs->e12367 * rhs->r + lhs->e1 * rhs->e2367 
             + lhs->e2367 * rhs->e1 + lhs->e2 * rhs->e1367 + lhs->e1367 * rhs->e2 
             + lhs->e3 * rhs->e1267 + lhs->e1267 * rhs->e3 + lhs->e6 * rhs->e1237 
             + lhs->e1237 * rhs->e6 + lhs->e7 * rhs->e1236 + lhs->e1236 * rhs->e7 
             + lhs->e12 * rhs->e367 + lhs->e367 * rhs->e12 + lhs->e13 * rhs->e267 
             + lhs->e267 * rhs->e13 + lhs->e23 * rhs->e167 + lhs->e167 * rhs->e23 
             + lhs->e16 * rhs->e237 + lhs->e237 * rhs->e16 + lhs->e26 * rhs->e137 
             + lhs->e137 * rhs->e26 + lhs->e36 * rhs->e127 + lhs->e127 * rhs->e36 
             + lhs->e17 * rhs->e236 + lhs->e236 * rhs->e17 + lhs->e27 * rhs->e136 
             + lhs->e136 * rhs->e27 + lhs->e37 * rhs->e126 + lhs->e126 * rhs->e37 
             + lhs->e67 * rhs->e123 + lhs->e123 * rhs->e67;
  res->e12467 = lhs->r * rhs->e12467 + lhs->e12467 * rhs->r + lhs->e1 * rhs->e2467 
             + lhs->e2467 * rhs->e1 + lhs->e2 * rhs->e1467 + lhs->e1467 * rhs->e2 
             + lhs->e4 * rhs->e1267 + lhs->e1267 * rhs->e4 + lhs->e6 * rhs->e1247 
             + lhs->e1247 * rhs->e6 + lhs->e7 * rhs->e1246 + lhs->e1246 * rhs->e7 
             + lhs->e12 * rhs->e467 + lhs->e467 * rhs->e12 + lhs->e14 * rhs->e267 
             + lhs->e267 * rhs->e14 + lhs->e24 * rhs->e167 + lhs->e167 * rhs->e24 
             + lhs->e16 * rhs->e247 + lhs->e247 * rhs->e16 + lhs->e26 * rhs->e147 
             + lhs->e147 * rhs->e26 + lhs->e46 * rhs->e127 + lhs->e127 * rhs->e46 
             + lhs->e17 * rhs->e246 + lhs->e246 * rhs->e17 + lhs->e27 * rhs->e146 
             + lhs->e146 * rhs->e27 + lhs->e47 * rhs->e126 + lhs->e126 * rhs->e47 
             + lhs->e67 * rhs->e124 + lhs->e124 * rhs->e67;
  res->e13467 = lhs->r * rhs->e13467 + lhs->e13467 * rhs->r + lhs->e1 * rhs->e3467 
             + lhs->e3467 * rhs->e1 + lhs->e3 * rhs->e1467 + lhs->e1467 * rhs->e3 
             + lhs->e4 * rhs->e1367 + lhs->e1367 * rhs->e4 + lhs->e6 * rhs->e1347 
             + lhs->e1347 * rhs->e6 + lhs->e7 * rhs->e1346 + lhs->e1346 * rhs->e7 
             + lhs->e13 * rhs->e467 + lhs->e467 * rhs->e13 + lhs->e14 * rhs->e367 
             + lhs->e367 * rhs->e14 + lhs->e34 * rhs->e167 + lhs->e167 * rhs->e34 
             + lhs->e16 * rhs->e347 + lhs->e347 * rhs->e16 + lhs->e36 * rhs->e147 
             + lhs->e147 * rhs->e36 + lhs->e46 * rhs->e137 + lhs->e137 * rhs->e46 
             + lhs->e17 * rhs->e346 + lhs->e346 * rhs->e17 + lhs->e37 * rhs->e146 
             + lhs->e146 * rhs->e37 + lhs->e47 * rhs->e136 + lhs->e136 * rhs->e47 
             + lhs->e67 * rhs->e134 + lhs->e134 * rhs->e67;
  res->e23467 = lhs->r * rhs->e23467 + lhs->e23467 * rhs->r + lhs->e2 * rhs->e3467 
             + lhs->e3467 * rhs->e2 + lhs->e3 * rhs->e2467 + lhs->e2467 * rhs->e3 
             + lhs->e4 * rhs->e2367 + lhs->e2367 * rhs->e4 + lhs->e6 * rhs->e2347 
             + lhs->e2347 * rhs->e6 + lhs->e7 * rhs->e2346 + lhs->e2346 * rhs->e7 
             + lhs->e23 * rhs->e467 + lhs->e467 * rhs->e23 + lhs->e24 * rhs->e367 
             + lhs->e367 * rhs->e24 + lhs->e34 * rhs->e267 + lhs->e267 * rhs->e34 
             + lhs->e26 * rhs->e347 + lhs->e347 * rhs->e26 + lhs->e36 * rhs->e247 
             + lhs->e247 * rhs->e36 + lhs->e46 * rhs->e237 + lhs->e237 * rhs->e46 
             + lhs->e27 * rhs->e346 + lhs->e346 * rhs->e27 + lhs->e37 * rhs->e246 
             + lhs->e246 * rhs->e37 + lhs->e47 * rhs->e236 + lhs->e236 * rhs->e47 
             + lhs->e67 * rhs->e234 + lhs->e234 * rhs->e67;
  res->e12567 = lhs->r * rhs->e12567 + lhs->e12567 * rhs->r + lhs->e1 * rhs->e2567 
             + lhs->e2567 * rhs->e1 + lhs->e2 * rhs->e1567 + lhs->e1567 * rhs->e2 
             + lhs->e5 * rhs->e1267 + lhs->e1267 * rhs->e5 + lhs->e6 * rhs->e1257 
             + lhs->e1257 * rhs->e6 + lhs->e7 * rhs->e1256 + lhs->e1256 * rhs->e7 
             + lhs->e12 * rhs->e567 + lhs->e567 * rhs->e12 + lhs->e15 * rhs->e267 
             + lhs->e267 * rhs->e15 + lhs->e25 * rhs->e167 + lhs->e167 * rhs->e25 
             + lhs->e16 * rhs->e257 + lhs->e257 * rhs->e16 + lhs->e26 * rhs->e157 
             + lhs->e157 * rhs->e26 + lhs->e56 * rhs->e127 + lhs->e127 * rhs->e56 
             + lhs->e17 * rhs->e256 + lhs->e256 * rhs->e17 + lhs->e27 * rhs->e156 
             + lhs->e156 * rhs->e27 + lhs->e57 * rhs->e126 + lhs->e126 * rhs->e57 
             + lhs->e67 * rhs->e125 + lhs->e125 * rhs->e67;
  res->e13567 = lhs->r * rhs->e13567 + lhs->e13567 * rhs->r + lhs->e1 * rhs->e3567 
             + lhs->e3567 * rhs->e1 + lhs->e3 * rhs->e1567 + lhs->e1567 * rhs->e3 
             + lhs->e5 * rhs->e1367 + lhs->e1367 * rhs->e5 + lhs->e6 * rhs->e1357 
             + lhs->e1357 * rhs->e6 + lhs->e7 * rhs->e1356 + lhs->e1356 * rhs->e7 
             + lhs->e13 * rhs->e567 + lhs->e567 * rhs->e13 + lhs->e15 * rhs->e367 
             + lhs->e367 * rhs->e15 + lhs->e35 * rhs->e167 + lhs->e167 * rhs->e35 
             + lhs->e16 * rhs->e357 + lhs->e357 * rhs->e16 + lhs->e36 * rhs->e157 
             + lhs->e157 * rhs->e36 + lhs->e56 * rhs->e137 + lhs->e137 * rhs->e56 
             + lhs->e17 * rhs->e356 + lhs->e356 * rhs->e17 + lhs->e37 * rhs->e156 
             + lhs->e156 * rhs->e37 + lhs->e57 * rhs->e136 + lhs->e136 * rhs->e57 
             + lhs->e67 * rhs->e135 + lhs->e135 * rhs->e67;
  res->e23567 = lhs->r * rhs->e23567 + lhs->e23567 * rhs->r + lhs->e2 * rhs->e3567 
             + lhs->e3567 * rhs->e2 + lhs->e3 * rhs->e2567 + lhs->e2567 * rhs->e3 
             + lhs->e5 * rhs->e2367 + lhs->e2367 * rhs->e5 + lhs->e6 * rhs->e2357 
             + lhs->e2357 * rhs->e6 + lhs->e7 * rhs->e2356 + lhs->e2356 * rhs->e7 
             + lhs->e23 * rhs->e567 + lhs->e567 * rhs->e23 + lhs->e25 * rhs->e367 
             + lhs->e367 * rhs->e25 + lhs->e35 * rhs->e267 + lhs->e267 * rhs->e35 
             + lhs->e26 * rhs->e357 + lhs->e357 * rhs->e26 + lhs->e36 * rhs->e257 
             + lhs->e257 * rhs->e36 + lhs->e56 * rhs->e237 + lhs->e237 * rhs->e56 
             + lhs->e27 * rhs->e356 + lhs->e356 * rhs->e27 + lhs->e37 * rhs->e256 
             + lhs->e256 * rhs->e37 + lhs->e57 * rhs->e236 + lhs->e236 * rhs->e57 
             + lhs->e67 * rhs->e235 + lhs->e235 * rhs->e67;
  res->e14567 = lhs->r * rhs->e14567 + lhs->e14567 * rhs->r + lhs->e1 * rhs->e4567 
             + lhs->e4567 * rhs->e1 + lhs->e4 * rhs->e1567 + lhs->e1567 * rhs->e4 
             + lhs->e5 * rhs->e1467 + lhs->e1467 * rhs->e5 + lhs->e6 * rhs->e1457 
             + lhs->e1457 * rhs->e6 + lhs->e7 * rhs->e1456 + lhs->e1456 * rhs->e7 
             + lhs->e14 * rhs->e567 + lhs->e567 * rhs->e14 + lhs->e15 * rhs->e467 
             + lhs->e467 * rhs->e15 + lhs->e45 * rhs->e167 + lhs->e167 * rhs->e45 
             + lhs->e16 * rhs->e457 + lhs->e457 * rhs->e16 + lhs->e46 * rhs->e157 
             + lhs->e157 * rhs->e46 + lhs->e56 * rhs->e147 + lhs->e147 * rhs->e56 
             + lhs->e17 * rhs->e456 + lhs->e456 * rhs->e17 + lhs->e47 * rhs->e156 
             + lhs->e156 * rhs->e47 + lhs->e57 * rhs->e146 + lhs->e146 * rhs->e57 
             + lhs->e67 * rhs->e145 + lhs->e145 * rhs->e67;
  res->e24567 = lhs->r * rhs->e24567 + lhs->e24567 * rhs->r + lhs->e2 * rhs->e4567 
             + lhs->e4567 * rhs->e2 + lhs->e4 * rhs->e2567 + lhs->e2567 * rhs->e4 
             + lhs->e5 * rhs->e2467 + lhs->e2467 * rhs->e5 + lhs->e6 * rhs->e2457 
             + lhs->e2457 * rhs->e6 + lhs->e7 * rhs->e2456 + lhs->e2456 * rhs->e7 
             + lhs->e24 * rhs->e567 + lhs->e567 * rhs->e24 + lhs->e25 * rhs->e467 
             + lhs->e467 * rhs->e25 + lhs->e45 * rhs->e267 + lhs->e267 * rhs->e45 
             + lhs->e26 * rhs->e457 + lhs->e457 * rhs->e26 + lhs->e46 * rhs->e257 
             + lhs->e257 * rhs->e46 + lhs->e56 * rhs->e247 + lhs->e247 * rhs->e56 
             + lhs->e27 * rhs->e456 + lhs->e456 * rhs->e27 + lhs->e47 * rhs->e256 
             + lhs->e256 * rhs->e47 + lhs->e57 * rhs->e246 + lhs->e246 * rhs->e57 
             + lhs->e67 * rhs->e245 + lhs->e245 * rhs->e67;
  res->e34567 = lhs->r * rhs->e34567 + lhs->e34567 * rhs->r + lhs->e3 * rhs->e4567 
             + lhs->e4567 * rhs->e3 + lhs->e4 * rhs->e3567 + lhs->e3567 * rhs->e4 
             + lhs->e5 * rhs->e3467 + lhs->e3467 * rhs->e5 + lhs->e6 * rhs->e3457 
             + lhs->e3457 * rhs->e6 + lhs->e7 * rhs->e3456 + lhs->e3456 * rhs->e7 
             + lhs->e34 * rhs->e567 + lhs->e567 * rhs->e34 + lhs->e35 * rhs->e467 
             + lhs->e467 * rhs->e35 + lhs->e45 * rhs->e367 + lhs->e367 * rhs->e45 
             + lhs->e36 * rhs->e457 + lhs->e457 * rhs->e36 + lhs->e46 * rhs->e357 
             + lhs->e357 * rhs->e46 + lhs->e56 * rhs->e347 + lhs->e347 * rhs->e56 
             + lhs->e37 * rhs->e456 + lhs->e456 * rhs->e37 + lhs->e47 * rhs->e356 
             + lhs->e356 * rhs->e47 + lhs->e57 * rhs->e346 + lhs->e346 * rhs->e57 
             + lhs->e67 * rhs->e345 + lhs->e345 * rhs->e67;
  // Order 6;
  res->e123456 = lhs->r * rhs->e123456 + lhs->e123456 * rhs->r + lhs->e1 * rhs->e23456 
              + lhs->e23456 * rhs->e1 + lhs->e2 * rhs->e13456 + lhs->e13456 * rhs->e2 
              + lhs->e3 * rhs->e12456 + lhs->e12456 * rhs->e3 + lhs->e4 * rhs->e12356 
              + lhs->e12356 * rhs->e4 + lhs->e5 * rhs->e12346 + lhs->e12346 * rhs->e5 
              + lhs->e6 * rhs->e12345 + lhs->e12345 * rhs->e6 + lhs->e12 * rhs->e3456 
              + lhs->e3456 * rhs->e12 + lhs->e13 * rhs->e2456 + lhs->e2456 * rhs->e13 
              + lhs->e23 * rhs->e1456 + lhs->e1456 * rhs->e23 + lhs->e14 * rhs->e2356 
              + lhs->e2356 * rhs->e14 + lhs->e24 * rhs->e1356 + lhs->e1356 * rhs->e24 
              + lhs->e34 * rhs->e1256 + lhs->e1256 * rhs->e34 + lhs->e15 * rhs->e2346 
              + lhs->e2346 * rhs->e15 + lhs->e25 * rhs->e1346 + lhs->e1346 * rhs->e25 
              + lhs->e35 * rhs->e1246 + lhs->e1246 * rhs->e35 + lhs->e45 * rhs->e1236 
              + lhs->e1236 * rhs->e45 + lhs->e16 * rhs->e2345 + lhs->e2345 * rhs->e16 
              + lhs->e26 * rhs->e1345 + lhs->e1345 * rhs->e26 + lhs->e36 * rhs->e1245 
              + lhs->e1245 * rhs->e36 + lhs->e46 * rhs->e1235 + lhs->e1235 * rhs->e46 
              + lhs->e56 * rhs->e1234 + lhs->e1234 * rhs->e56 + lhs->e123 * rhs->e456 
              + lhs->e124 * rhs->e356 + lhs->e134 * rhs->e256 + lhs->e234 * rhs->e156 
              + lhs->e125 * rhs->e346 + lhs->e135 * rhs->e246 + lhs->e235 * rhs->e146 
              + lhs->e145 * rhs->e236 + lhs->e245 * rhs->e136 + lhs->e345 * rhs->e126 
              + lhs->e126 * rhs->e345 + lhs->e136 * rhs->e245 + lhs->e236 * rhs->e145 
              + lhs->e146 * rhs->e235 + lhs->e246 * rhs->e135 + lhs->e346 * rhs->e125 
              + lhs->e156 * rhs->e234 + lhs->e256 * rhs->e134 + lhs->e356 * rhs->e124 
              + lhs->e456 * rhs->e123;
  res->e123457 = lhs->r * rhs->e123457 + lhs->e123457 * rhs->r + lhs->e1 * rhs->e23457 
              + lhs->e23457 * rhs->e1 + lhs->e2 * rhs->e13457 + lhs->e13457 * rhs->e2 
              + lhs->e3 * rhs->e12457 + lhs->e12457 * rhs->e3 + lhs->e4 * rhs->e12357 
              + lhs->e12357 * rhs->e4 + lhs->e5 * rhs->e12347 + lhs->e12347 * rhs->e5 
              + lhs->e7 * rhs->e12345 + lhs->e12345 * rhs->e7 + lhs->e12 * rhs->e3457 
              + lhs->e3457 * rhs->e12 + lhs->e13 * rhs->e2457 + lhs->e2457 * rhs->e13 
              + lhs->e23 * rhs->e1457 + lhs->e1457 * rhs->e23 + lhs->e14 * rhs->e2357 
              + lhs->e2357 * rhs->e14 + lhs->e24 * rhs->e1357 + lhs->e1357 * rhs->e24 
              + lhs->e34 * rhs->e1257 + lhs->e1257 * rhs->e34 + lhs->e15 * rhs->e2347 
              + lhs->e2347 * rhs->e15 + lhs->e25 * rhs->e1347 + lhs->e1347 * rhs->e25 
              + lhs->e35 * rhs->e1247 + lhs->e1247 * rhs->e35 + lhs->e45 * rhs->e1237 
              + lhs->e1237 * rhs->e45 + lhs->e17 * rhs->e2345 + lhs->e2345 * rhs->e17 
              + lhs->e27 * rhs->e1345 + lhs->e1345 * rhs->e27 + lhs->e37 * rhs->e1245 
              + lhs->e1245 * rhs->e37 + lhs->e47 * rhs->e1235 + lhs->e1235 * rhs->e47 
              + lhs->e57 * rhs->e1234 + lhs->e1234 * rhs->e57 + lhs->e123 * rhs->e457 
              + lhs->e124 * rhs->e357 + lhs->e134 * rhs->e257 + lhs->e234 * rhs->e157 
              + lhs->e125 * rhs->e347 + lhs->e135 * rhs->e247 + lhs->e235 * rhs->e147 
              + lhs->e145 * rhs->e237 + lhs->e245 * rhs->e137 + lhs->e345 * rhs->e127 
              + lhs->e127 * rhs->e345 + lhs->e137 * rhs->e245 + lhs->e237 * rhs->e145 
              + lhs->e147 * rhs->e235 + lhs->e247 * rhs->e135 + lhs->e347 * rhs->e125 
              + lhs->e157 * rhs->e234 + lhs->e257 * rhs->e134 + lhs->e357 * rhs->e124 
              + lhs->e457 * rhs->e123;
  res->e123467 = lhs->r * rhs->e123467 + lhs->e123467 * rhs->r + lhs->e1 * rhs->e23467 
              + lhs->e23467 * rhs->e1 + lhs->e2 * rhs->e13467 + lhs->e13467 * rhs->e2 
              + lhs->e3 * rhs->e12467 + lhs->e12467 * rhs->e3 + lhs->e4 * rhs->e12367 
              + lhs->e12367 * rhs->e4 + lhs->e6 * rhs->e12347 + lhs->e12347 * rhs->e6 
              + lhs->e7 * rhs->e12346 + lhs->e12346 * rhs->e7 + lhs->e12 * rhs->e3467 
              + lhs->e3467 * rhs->e12 + lhs->e13 * rhs->e2467 + lhs->e2467 * rhs->e13 
              + lhs->e23 * rhs->e1467 + lhs->e1467 * rhs->e23 + lhs->e14 * rhs->e2367 
              + lhs->e2367 * rhs->e14 + lhs->e24 * rhs->e1367 + lhs->e1367 * rhs->e24 
              + lhs->e34 * rhs->e1267 + lhs->e1267 * rhs->e34 + lhs->e16 * rhs->e2347 
              + lhs->e2347 * rhs->e16 + lhs->e26 * rhs->e1347 + lhs->e1347 * rhs->e26 
              + lhs->e36 * rhs->e1247 + lhs->e1247 * rhs->e36 + lhs->e46 * rhs->e1237 
              + lhs->e1237 * rhs->e46 + lhs->e17 * rhs->e2346 + lhs->e2346 * rhs->e17 
              + lhs->e27 * rhs->e1346 + lhs->e1346 * rhs->e27 + lhs->e37 * rhs->e1246 
              + lhs->e1246 * rhs->e37 + lhs->e47 * rhs->e1236 + lhs->e1236 * rhs->e47 
              + lhs->e67 * rhs->e1234 + lhs->e1234 * rhs->e67 + lhs->e123 * rhs->e467 
              + lhs->e124 * rhs->e367 + lhs->e134 * rhs->e267 + lhs->e234 * rhs->e167 
              + lhs->e126 * rhs->e347 + lhs->e136 * rhs->e247 + lhs->e236 * rhs->e147 
              + lhs->e146 * rhs->e237 + lhs->e246 * rhs->e137 + lhs->e346 * rhs->e127 
              + lhs->e127 * rhs->e346 + lhs->e137 * rhs->e246 + lhs->e237 * rhs->e146 
              + lhs->e147 * rhs->e236 + lhs->e247 * rhs->e136 + lhs->e347 * rhs->e126 
              + lhs->e167 * rhs->e234 + lhs->e267 * rhs->e134 + lhs->e367 * rhs->e124 
              + lhs->e467 * rhs->e123;
  res->e123567 = lhs->r * rhs->e123567 + lhs->e123567 * rhs->r + lhs->e1 * rhs->e23567 
              + lhs->e23567 * rhs->e1 + lhs->e2 * rhs->e13567 + lhs->e13567 * rhs->e2 
              + lhs->e3 * rhs->e12567 + lhs->e12567 * rhs->e3 + lhs->e5 * rhs->e12367 
              + lhs->e12367 * rhs->e5 + lhs->e6 * rhs->e12357 + lhs->e12357 * rhs->e6 
              + lhs->e7 * rhs->e12356 + lhs->e12356 * rhs->e7 + lhs->e12 * rhs->e3567 
              + lhs->e3567 * rhs->e12 + lhs->e13 * rhs->e2567 + lhs->e2567 * rhs->e13 
              + lhs->e23 * rhs->e1567 + lhs->e1567 * rhs->e23 + lhs->e15 * rhs->e2367 
              + lhs->e2367 * rhs->e15 + lhs->e25 * rhs->e1367 + lhs->e1367 * rhs->e25 
              + lhs->e35 * rhs->e1267 + lhs->e1267 * rhs->e35 + lhs->e16 * rhs->e2357 
              + lhs->e2357 * rhs->e16 + lhs->e26 * rhs->e1357 + lhs->e1357 * rhs->e26 
              + lhs->e36 * rhs->e1257 + lhs->e1257 * rhs->e36 + lhs->e56 * rhs->e1237 
              + lhs->e1237 * rhs->e56 + lhs->e17 * rhs->e2356 + lhs->e2356 * rhs->e17 
              + lhs->e27 * rhs->e1356 + lhs->e1356 * rhs->e27 + lhs->e37 * rhs->e1256 
              + lhs->e1256 * rhs->e37 + lhs->e57 * rhs->e1236 + lhs->e1236 * rhs->e57 
              + lhs->e67 * rhs->e1235 + lhs->e1235 * rhs->e67 + lhs->e123 * rhs->e567 
              + lhs->e125 * rhs->e367 + lhs->e135 * rhs->e267 + lhs->e235 * rhs->e167 
              + lhs->e126 * rhs->e357 + lhs->e136 * rhs->e257 + lhs->e236 * rhs->e157 
              + lhs->e156 * rhs->e237 + lhs->e256 * rhs->e137 + lhs->e356 * rhs->e127 
              + lhs->e127 * rhs->e356 + lhs->e137 * rhs->e256 + lhs->e237 * rhs->e156 
              + lhs->e157 * rhs->e236 + lhs->e257 * rhs->e136 + lhs->e357 * rhs->e126 
              + lhs->e167 * rhs->e235 + lhs->e267 * rhs->e135 + lhs->e367 * rhs->e125 
              + lhs->e567 * rhs->e123;
  res->e124567 = lhs->r * rhs->e124567 + lhs->e124567 * rhs->r + lhs->e1 * rhs->e24567 
              + lhs->e24567 * rhs->e1 + lhs->e2 * rhs->e14567 + lhs->e14567 * rhs->e2 
              + lhs->e4 * rhs->e12567 + lhs->e12567 * rhs->e4 + lhs->e5 * rhs->e12467 
              + lhs->e12467 * rhs->e5 + lhs->e6 * rhs->e12457 + lhs->e12457 * rhs->e6 
              + lhs->e7 * rhs->e12456 + lhs->e12456 * rhs->e7 + lhs->e12 * rhs->e4567 
              + lhs->e4567 * rhs->e12 + lhs->e14 * rhs->e2567 + lhs->e2567 * rhs->e14 
              + lhs->e24 * rhs->e1567 + lhs->e1567 * rhs->e24 + lhs->e15 * rhs->e2467 
              + lhs->e2467 * rhs->e15 + lhs->e25 * rhs->e1467 + lhs->e1467 * rhs->e25 
              + lhs->e45 * rhs->e1267 + lhs->e1267 * rhs->e45 + lhs->e16 * rhs->e2457 
              + lhs->e2457 * rhs->e16 + lhs->e26 * rhs->e1457 + lhs->e1457 * rhs->e26 
              + lhs->e46 * rhs->e1257 + lhs->e1257 * rhs->e46 + lhs->e56 * rhs->e1247 
              + lhs->e1247 * rhs->e56 + lhs->e17 * rhs->e2456 + lhs->e2456 * rhs->e17 
              + lhs->e27 * rhs->e1456 + lhs->e1456 * rhs->e27 + lhs->e47 * rhs->e1256 
              + lhs->e1256 * rhs->e47 + lhs->e57 * rhs->e1246 + lhs->e1246 * rhs->e57 
              + lhs->e67 * rhs->e1245 + lhs->e1245 * rhs->e67 + lhs->e124 * rhs->e567 
              + lhs->e125 * rhs->e467 + lhs->e145 * rhs->e267 + lhs->e245 * rhs->e167 
              + lhs->e126 * rhs->e457 + lhs->e146 * rhs->e257 + lhs->e246 * rhs->e157 
              + lhs->e156 * rhs->e247 + lhs->e256 * rhs->e147 + lhs->e456 * rhs->e127 
              + lhs->e127 * rhs->e456 + lhs->e147 * rhs->e256 + lhs->e247 * rhs->e156 
              + lhs->e157 * rhs->e246 + lhs->e257 * rhs->e146 + lhs->e457 * rhs->e126 
              + lhs->e167 * rhs->e245 + lhs->e267 * rhs->e145 + lhs->e467 * rhs->e125 
              + lhs->e567 * rhs->e124;
  res->e134567 = lhs->r * rhs->e134567 + lhs->e134567 * rhs->r + lhs->e1 * rhs->e34567 
              + lhs->e34567 * rhs->e1 + lhs->e3 * rhs->e14567 + lhs->e14567 * rhs->e3 
              + lhs->e4 * rhs->e13567 + lhs->e13567 * rhs->e4 + lhs->e5 * rhs->e13467 
              + lhs->e13467 * rhs->e5 + lhs->e6 * rhs->e13457 + lhs->e13457 * rhs->e6 
              + lhs->e7 * rhs->e13456 + lhs->e13456 * rhs->e7 + lhs->e13 * rhs->e4567 
              + lhs->e4567 * rhs->e13 + lhs->e14 * rhs->e3567 + lhs->e3567 * rhs->e14 
              + lhs->e34 * rhs->e1567 + lhs->e1567 * rhs->e34 + lhs->e15 * rhs->e3467 
              + lhs->e3467 * rhs->e15 + lhs->e35 * rhs->e1467 + lhs->e1467 * rhs->e35 
              + lhs->e45 * rhs->e1367 + lhs->e1367 * rhs->e45 + lhs->e16 * rhs->e3457 
              + lhs->e3457 * rhs->e16 + lhs->e36 * rhs->e1457 + lhs->e1457 * rhs->e36 
              + lhs->e46 * rhs->e1357 + lhs->e1357 * rhs->e46 + lhs->e56 * rhs->e1347 
              + lhs->e1347 * rhs->e56 + lhs->e17 * rhs->e3456 + lhs->e3456 * rhs->e17 
              + lhs->e37 * rhs->e1456 + lhs->e1456 * rhs->e37 + lhs->e47 * rhs->e1356 
              + lhs->e1356 * rhs->e47 + lhs->e57 * rhs->e1346 + lhs->e1346 * rhs->e57 
              + lhs->e67 * rhs->e1345 + lhs->e1345 * rhs->e67 + lhs->e134 * rhs->e567 
              + lhs->e135 * rhs->e467 + lhs->e145 * rhs->e367 + lhs->e345 * rhs->e167 
              + lhs->e136 * rhs->e457 + lhs->e146 * rhs->e357 + lhs->e346 * rhs->e157 
              + lhs->e156 * rhs->e347 + lhs->e356 * rhs->e147 + lhs->e456 * rhs->e137 
              + lhs->e137 * rhs->e456 + lhs->e147 * rhs->e356 + lhs->e347 * rhs->e156 
              + lhs->e157 * rhs->e346 + lhs->e357 * rhs->e146 + lhs->e457 * rhs->e136 
              + lhs->e167 * rhs->e345 + lhs->e367 * rhs->e145 + lhs->e467 * rhs->e135 
              + lhs->e567 * rhs->e134;
  res->e234567 = lhs->r * rhs->e234567 + lhs->e234567 * rhs->r + lhs->e2 * rhs->e34567 
              + lhs->e34567 * rhs->e2 + lhs->e3 * rhs->e24567 + lhs->e24567 * rhs->e3 
              + lhs->e4 * rhs->e23567 + lhs->e23567 * rhs->e4 + lhs->e5 * rhs->e23467 
              + lhs->e23467 * rhs->e5 + lhs->e6 * rhs->e23457 + lhs->e23457 * rhs->e6 
              + lhs->e7 * rhs->e23456 + lhs->e23456 * rhs->e7 + lhs->e23 * rhs->e4567 
              + lhs->e4567 * rhs->e23 + lhs->e24 * rhs->e3567 + lhs->e3567 * rhs->e24 
              + lhs->e34 * rhs->e2567 + lhs->e2567 * rhs->e34 + lhs->e25 * rhs->e3467 
              + lhs->e3467 * rhs->e25 + lhs->e35 * rhs->e2467 + lhs->e2467 * rhs->e35 
              + lhs->e45 * rhs->e2367 + lhs->e2367 * rhs->e45 + lhs->e26 * rhs->e3457 
              + lhs->e3457 * rhs->e26 + lhs->e36 * rhs->e2457 + lhs->e2457 * rhs->e36 
              + lhs->e46 * rhs->e2357 + lhs->e2357 * rhs->e46 + lhs->e56 * rhs->e2347 
              + lhs->e2347 * rhs->e56 + lhs->e27 * rhs->e3456 + lhs->e3456 * rhs->e27 
              + lhs->e37 * rhs->e2456 + lhs->e2456 * rhs->e37 + lhs->e47 * rhs->e2356 
              + lhs->e2356 * rhs->e47 + lhs->e57 * rhs->e2346 + lhs->e2346 * rhs->e57 
              + lhs->e67 * rhs->e2345 + lhs->e2345 * rhs->e67 + lhs->e234 * rhs->e567 
              + lhs->e235 * rhs->e467 + lhs->e245 * rhs->e367 + lhs->e345 * rhs->e267 
              + lhs->e236 * rhs->e457 + lhs->e246 * rhs->e357 + lhs->e346 * rhs->e257 
              + lhs->e256 * rhs->e347 + lhs->e356 * rhs->e247 + lhs->e456 * rhs->e237 
              + lhs->e237 * rhs->e456 + lhs->e247 * rhs->e356 + lhs->e347 * rhs->e256 
              + lhs->e257 * rhs->e346 + lhs->e357 * rhs->e246 + lhs->e457 * rhs->e236 
              + lhs->e267 * rhs->e345 + lhs->e367 * rhs->e245 + lhs->e467 * rhs->e235 
              + lhs->e567 * rhs->e234;
  // Order 7;
  res->e1234567 = lhs->r * rhs->e1234567 + lhs->e1234567 * rhs->r + lhs->e1 * rhs->e234567 
               + lhs->e234567 * rhs->e1 + lhs->e2 * rhs->e134567 + lhs->e134567 * rhs->e2 
               + lhs->e3 * rhs->e124567 + lhs->e124567 * rhs->e3 + lhs->e4 * rhs->e123567 
               + lhs->e123567 * rhs->e4 + lhs->e5 * rhs->e123467 + lhs->e123467 * rhs->e5 
               + lhs->e6 * rhs->e123457 + lhs->e123457 * rhs->e6 + lhs->e7 * rhs->e123456 
               + lhs->e123456 * rhs->e7 + lhs->e12 * rhs->e34567 + lhs->e34567 * rhs->e12 
               + lhs->e13 * rhs->e24567 + lhs->e24567 * rhs->e13 + lhs->e23 * rhs->e14567 
               + lhs->e14567 * rhs->e23 + lhs->e14 * rhs->e23567 + lhs->e23567 * rhs->e14 
               + lhs->e24 * rhs->e13567 + lhs->e13567 * rhs->e24 + lhs->e34 * rhs->e12567 
               + lhs->e12567 * rhs->e34 + lhs->e15 * rhs->e23467 + lhs->e23467 * rhs->e15 
               + lhs->e25 * rhs->e13467 + lhs->e13467 * rhs->e25 + lhs->e35 * rhs->e12467 
               + lhs->e12467 * rhs->e35 + lhs->e45 * rhs->e12367 + lhs->e12367 * rhs->e45 
               + lhs->e16 * rhs->e23457 + lhs->e23457 * rhs->e16 + lhs->e26 * rhs->e13457 
               + lhs->e13457 * rhs->e26 + lhs->e36 * rhs->e12457 + lhs->e12457 * rhs->e36 
               + lhs->e46 * rhs->e12357 + lhs->e12357 * rhs->e46 + lhs->e56 * rhs->e12347 
               + lhs->e12347 * rhs->e56 + lhs->e17 * rhs->e23456 + lhs->e23456 * rhs->e17 
               + lhs->e27 * rhs->e13456 + lhs->e13456 * rhs->e27 + lhs->e37 * rhs->e12456 
               + lhs->e12456 * rhs->e37 + lhs->e47 * rhs->e12356 + lhs->e12356 * rhs->e47 
               + lhs->e57 * rhs->e12346 + lhs->e12346 * rhs->e57 + lhs->e67 * rhs->e12345 
               + lhs->e12345 * rhs->e67 + lhs->e123 * rhs->e4567 + lhs->e4567 * rhs->e123 
               + lhs->e124 * rhs->e3567 + lhs->e3567 * rhs->e124 + lhs->e134 * rhs->e2567 
               + lhs->e2567 * rhs->e134 + lhs->e234 * rhs->e1567 + lhs->e1567 * rhs->e234 
               + lhs->e125 * rhs->e3467 + lhs->e3467 * rhs->e125 + lhs->e135 * rhs->e2467 
               + lhs->e2467 * rhs->e135 + lhs->e235 * rhs->e1467 + lhs->e1467 * rhs->e235 
               + lhs->e145 * rhs->e2367 + lhs->e2367 * rhs->e145 + lhs->e245 * rhs->e1367 
               + lhs->e1367 * rhs->e245 + lhs->e345 * rhs->e1267 + lhs->e1267 * rhs->e345 
               + lhs->e126 * rhs->e3457 + lhs->e3457 * rhs->e126 + lhs->e136 * rhs->e2457 
               + lhs->e2457 * rhs->e136 + lhs->e236 * rhs->e1457 + lhs->e1457 * rhs->e236 
               + lhs->e146 * rhs->e2357 + lhs->e2357 * rhs->e146 + lhs->e246 * rhs->e1357 
               + lhs->e1357 * rhs->e246 + lhs->e346 * rhs->e1257 + lhs->e1257 * rhs->e346 
               + lhs->e156 * rhs->e2347 + lhs->e2347 * rhs->e156 + lhs->e256 * rhs->e1347 
               + lhs->e1347 * rhs->e256 + lhs->e356 * rhs->e1247 + lhs->e1247 * rhs->e356 
               + lhs->e456 * rhs->e1237 + lhs->e1237 * rhs->e456 + lhs->e127 * rhs->e3456 
               + lhs->e3456 * rhs->e127 + lhs->e137 * rhs->e2456 + lhs->e2456 * rhs->e137 
               + lhs->e237 * rhs->e1456 + lhs->e1456 * rhs->e237 + lhs->e147 * rhs->e2356 
               + lhs->e2356 * rhs->e147 + lhs->e247 * rhs->e1356 + lhs->e1356 * rhs->e247 
               + lhs->e347 * rhs->e1256 + lhs->e1256 * rhs->e347 + lhs->e157 * rhs->e2346 
               + lhs->e2346 * rhs->e157 + lhs->e257 * rhs->e1346 + lhs->e1346 * rhs->e257 
               + lhs->e357 * rhs->e1246 + lhs->e1246 * rhs->e357 + lhs->e457 * rhs->e1236 
               + lhs->e1236 * rhs->e457 + lhs->e167 * rhs->e2345 + lhs->e2345 * rhs->e167 
               + lhs->e267 * rhs->e1345 + lhs->e1345 * rhs->e267 + lhs->e367 * rhs->e1245 
               + lhs->e1245 * rhs->e367 + lhs->e467 * rhs->e1235 + lhs->e1235 * rhs->e467 
               + lhs->e567 * rhs->e1234 + lhs->e1234 * rhs->e567;

}

mdnum7_t mdnum7_mul_ro(  coeff_t lhs,  mdnum7_t* rhs){
  mdnum7_t res;

  // Multiplication like function 'lhs * rhs'
  //  Real;
  res.r = lhs * rhs->r;
  // Order 1;
  res.e1 = lhs * rhs->e1;
  res.e2 = lhs * rhs->e2;
  res.e3 = lhs * rhs->e3;
  res.e4 = lhs * rhs->e4;
  res.e5 = lhs * rhs->e5;
  res.e6 = lhs * rhs->e6;
  res.e7 = lhs * rhs->e7;
  // Order 2;
  res.e12 = lhs * rhs->e12;
  res.e13 = lhs * rhs->e13;
  res.e23 = lhs * rhs->e23;
  res.e14 = lhs * rhs->e14;
  res.e24 = lhs * rhs->e24;
  res.e34 = lhs * rhs->e34;
  res.e15 = lhs * rhs->e15;
  res.e25 = lhs * rhs->e25;
  res.e35 = lhs * rhs->e35;
  res.e45 = lhs * rhs->e45;
  res.e16 = lhs * rhs->e16;
  res.e26 = lhs * rhs->e26;
  res.e36 = lhs * rhs->e36;
  res.e46 = lhs * rhs->e46;
  res.e56 = lhs * rhs->e56;
  res.e17 = lhs * rhs->e17;
  res.e27 = lhs * rhs->e27;
  res.e37 = lhs * rhs->e37;
  res.e47 = lhs * rhs->e47;
  res.e57 = lhs * rhs->e57;
  res.e67 = lhs * rhs->e67;
  // Order 3;
  res.e123 = lhs * rhs->e123;
  res.e124 = lhs * rhs->e124;
  res.e134 = lhs * rhs->e134;
  res.e234 = lhs * rhs->e234;
  res.e125 = lhs * rhs->e125;
  res.e135 = lhs * rhs->e135;
  res.e235 = lhs * rhs->e235;
  res.e145 = lhs * rhs->e145;
  res.e245 = lhs * rhs->e245;
  res.e345 = lhs * rhs->e345;
  res.e126 = lhs * rhs->e126;
  res.e136 = lhs * rhs->e136;
  res.e236 = lhs * rhs->e236;
  res.e146 = lhs * rhs->e146;
  res.e246 = lhs * rhs->e246;
  res.e346 = lhs * rhs->e346;
  res.e156 = lhs * rhs->e156;
  res.e256 = lhs * rhs->e256;
  res.e356 = lhs * rhs->e356;
  res.e456 = lhs * rhs->e456;
  res.e127 = lhs * rhs->e127;
  res.e137 = lhs * rhs->e137;
  res.e237 = lhs * rhs->e237;
  res.e147 = lhs * rhs->e147;
  res.e247 = lhs * rhs->e247;
  res.e347 = lhs * rhs->e347;
  res.e157 = lhs * rhs->e157;
  res.e257 = lhs * rhs->e257;
  res.e357 = lhs * rhs->e357;
  res.e457 = lhs * rhs->e457;
  res.e167 = lhs * rhs->e167;
  res.e267 = lhs * rhs->e267;
  res.e367 = lhs * rhs->e367;
  res.e467 = lhs * rhs->e467;
  res.e567 = lhs * rhs->e567;
  // Order 4;
  res.e1234 = lhs * rhs->e1234;
  res.e1235 = lhs * rhs->e1235;
  res.e1245 = lhs * rhs->e1245;
  res.e1345 = lhs * rhs->e1345;
  res.e2345 = lhs * rhs->e2345;
  res.e1236 = lhs * rhs->e1236;
  res.e1246 = lhs * rhs->e1246;
  res.e1346 = lhs * rhs->e1346;
  res.e2346 = lhs * rhs->e2346;
  res.e1256 = lhs * rhs->e1256;
  res.e1356 = lhs * rhs->e1356;
  res.e2356 = lhs * rhs->e2356;
  res.e1456 = lhs * rhs->e1456;
  res.e2456 = lhs * rhs->e2456;
  res.e3456 = lhs * rhs->e3456;
  res.e1237 = lhs * rhs->e1237;
  res.e1247 = lhs * rhs->e1247;
  res.e1347 = lhs * rhs->e1347;
  res.e2347 = lhs * rhs->e2347;
  res.e1257 = lhs * rhs->e1257;
  res.e1357 = lhs * rhs->e1357;
  res.e2357 = lhs * rhs->e2357;
  res.e1457 = lhs * rhs->e1457;
  res.e2457 = lhs * rhs->e2457;
  res.e3457 = lhs * rhs->e3457;
  res.e1267 = lhs * rhs->e1267;
  res.e1367 = lhs * rhs->e1367;
  res.e2367 = lhs * rhs->e2367;
  res.e1467 = lhs * rhs->e1467;
  res.e2467 = lhs * rhs->e2467;
  res.e3467 = lhs * rhs->e3467;
  res.e1567 = lhs * rhs->e1567;
  res.e2567 = lhs * rhs->e2567;
  res.e3567 = lhs * rhs->e3567;
  res.e4567 = lhs * rhs->e4567;
  // Order 5;
  res.e12345 = lhs * rhs->e12345;
  res.e12346 = lhs * rhs->e12346;
  res.e12356 = lhs * rhs->e12356;
  res.e12456 = lhs * rhs->e12456;
  res.e13456 = lhs * rhs->e13456;
  res.e23456 = lhs * rhs->e23456;
  res.e12347 = lhs * rhs->e12347;
  res.e12357 = lhs * rhs->e12357;
  res.e12457 = lhs * rhs->e12457;
  res.e13457 = lhs * rhs->e13457;
  res.e23457 = lhs * rhs->e23457;
  res.e12367 = lhs * rhs->e12367;
  res.e12467 = lhs * rhs->e12467;
  res.e13467 = lhs * rhs->e13467;
  res.e23467 = lhs * rhs->e23467;
  res.e12567 = lhs * rhs->e12567;
  res.e13567 = lhs * rhs->e13567;
  res.e23567 = lhs * rhs->e23567;
  res.e14567 = lhs * rhs->e14567;
  res.e24567 = lhs * rhs->e24567;
  res.e34567 = lhs * rhs->e34567;
  // Order 6;
  res.e123456 = lhs * rhs->e123456;
  res.e123457 = lhs * rhs->e123457;
  res.e123467 = lhs * rhs->e123467;
  res.e123567 = lhs * rhs->e123567;
  res.e124567 = lhs * rhs->e124567;
  res.e134567 = lhs * rhs->e134567;
  res.e234567 = lhs * rhs->e234567;
  // Order 7;
  res.e1234567 = lhs * rhs->e1234567;

  return res;

}

void mdnum7_mul_ro_to(  coeff_t lhs,  mdnum7_t* rhs, mdnum7_t* res){
  // Multiplication like function 'lhs * rhs'
  //  Real;
  res->r = lhs * rhs->r;
  // Order 1;
  res->e1 = lhs * rhs->e1;
  res->e2 = lhs * rhs->e2;
  res->e3 = lhs * rhs->e3;
  res->e4 = lhs * rhs->e4;
  res->e5 = lhs * rhs->e5;
  res->e6 = lhs * rhs->e6;
  res->e7 = lhs * rhs->e7;
  // Order 2;
  res->e12 = lhs * rhs->e12;
  res->e13 = lhs * rhs->e13;
  res->e23 = lhs * rhs->e23;
  res->e14 = lhs * rhs->e14;
  res->e24 = lhs * rhs->e24;
  res->e34 = lhs * rhs->e34;
  res->e15 = lhs * rhs->e15;
  res->e25 = lhs * rhs->e25;
  res->e35 = lhs * rhs->e35;
  res->e45 = lhs * rhs->e45;
  res->e16 = lhs * rhs->e16;
  res->e26 = lhs * rhs->e26;
  res->e36 = lhs * rhs->e36;
  res->e46 = lhs * rhs->e46;
  res->e56 = lhs * rhs->e56;
  res->e17 = lhs * rhs->e17;
  res->e27 = lhs * rhs->e27;
  res->e37 = lhs * rhs->e37;
  res->e47 = lhs * rhs->e47;
  res->e57 = lhs * rhs->e57;
  res->e67 = lhs * rhs->e67;
  // Order 3;
  res->e123 = lhs * rhs->e123;
  res->e124 = lhs * rhs->e124;
  res->e134 = lhs * rhs->e134;
  res->e234 = lhs * rhs->e234;
  res->e125 = lhs * rhs->e125;
  res->e135 = lhs * rhs->e135;
  res->e235 = lhs * rhs->e235;
  res->e145 = lhs * rhs->e145;
  res->e245 = lhs * rhs->e245;
  res->e345 = lhs * rhs->e345;
  res->e126 = lhs * rhs->e126;
  res->e136 = lhs * rhs->e136;
  res->e236 = lhs * rhs->e236;
  res->e146 = lhs * rhs->e146;
  res->e246 = lhs * rhs->e246;
  res->e346 = lhs * rhs->e346;
  res->e156 = lhs * rhs->e156;
  res->e256 = lhs * rhs->e256;
  res->e356 = lhs * rhs->e356;
  res->e456 = lhs * rhs->e456;
  res->e127 = lhs * rhs->e127;
  res->e137 = lhs * rhs->e137;
  res->e237 = lhs * rhs->e237;
  res->e147 = lhs * rhs->e147;
  res->e247 = lhs * rhs->e247;
  res->e347 = lhs * rhs->e347;
  res->e157 = lhs * rhs->e157;
  res->e257 = lhs * rhs->e257;
  res->e357 = lhs * rhs->e357;
  res->e457 = lhs * rhs->e457;
  res->e167 = lhs * rhs->e167;
  res->e267 = lhs * rhs->e267;
  res->e367 = lhs * rhs->e367;
  res->e467 = lhs * rhs->e467;
  res->e567 = lhs * rhs->e567;
  // Order 4;
  res->e1234 = lhs * rhs->e1234;
  res->e1235 = lhs * rhs->e1235;
  res->e1245 = lhs * rhs->e1245;
  res->e1345 = lhs * rhs->e1345;
  res->e2345 = lhs * rhs->e2345;
  res->e1236 = lhs * rhs->e1236;
  res->e1246 = lhs * rhs->e1246;
  res->e1346 = lhs * rhs->e1346;
  res->e2346 = lhs * rhs->e2346;
  res->e1256 = lhs * rhs->e1256;
  res->e1356 = lhs * rhs->e1356;
  res->e2356 = lhs * rhs->e2356;
  res->e1456 = lhs * rhs->e1456;
  res->e2456 = lhs * rhs->e2456;
  res->e3456 = lhs * rhs->e3456;
  res->e1237 = lhs * rhs->e1237;
  res->e1247 = lhs * rhs->e1247;
  res->e1347 = lhs * rhs->e1347;
  res->e2347 = lhs * rhs->e2347;
  res->e1257 = lhs * rhs->e1257;
  res->e1357 = lhs * rhs->e1357;
  res->e2357 = lhs * rhs->e2357;
  res->e1457 = lhs * rhs->e1457;
  res->e2457 = lhs * rhs->e2457;
  res->e3457 = lhs * rhs->e3457;
  res->e1267 = lhs * rhs->e1267;
  res->e1367 = lhs * rhs->e1367;
  res->e2367 = lhs * rhs->e2367;
  res->e1467 = lhs * rhs->e1467;
  res->e2467 = lhs * rhs->e2467;
  res->e3467 = lhs * rhs->e3467;
  res->e1567 = lhs * rhs->e1567;
  res->e2567 = lhs * rhs->e2567;
  res->e3567 = lhs * rhs->e3567;
  res->e4567 = lhs * rhs->e4567;
  // Order 5;
  res->e12345 = lhs * rhs->e12345;
  res->e12346 = lhs * rhs->e12346;
  res->e12356 = lhs * rhs->e12356;
  res->e12456 = lhs * rhs->e12456;
  res->e13456 = lhs * rhs->e13456;
  res->e23456 = lhs * rhs->e23456;
  res->e12347 = lhs * rhs->e12347;
  res->e12357 = lhs * rhs->e12357;
  res->e12457 = lhs * rhs->e12457;
  res->e13457 = lhs * rhs->e13457;
  res->e23457 = lhs * rhs->e23457;
  res->e12367 = lhs * rhs->e12367;
  res->e12467 = lhs * rhs->e12467;
  res->e13467 = lhs * rhs->e13467;
  res->e23467 = lhs * rhs->e23467;
  res->e12567 = lhs * rhs->e12567;
  res->e13567 = lhs * rhs->e13567;
  res->e23567 = lhs * rhs->e23567;
  res->e14567 = lhs * rhs->e14567;
  res->e24567 = lhs * rhs->e24567;
  res->e34567 = lhs * rhs->e34567;
  // Order 6;
  res->e123456 = lhs * rhs->e123456;
  res->e123457 = lhs * rhs->e123457;
  res->e123467 = lhs * rhs->e123467;
  res->e123567 = lhs * rhs->e123567;
  res->e124567 = lhs * rhs->e124567;
  res->e134567 = lhs * rhs->e134567;
  res->e234567 = lhs * rhs->e234567;
  // Order 7;
  res->e1234567 = lhs * rhs->e1234567;

}

mdnum7_t mdnum7_trunc_mul_oo(  mdnum7_t* lhs,  mdnum7_t* rhs){
  mdnum7_t res;

  res = mdnum7_init();

  //  Truncated multiplication like function 'lhs * rhs'
  // Order 2;
  res.e12 =  + lhs->e1 * rhs->e2 + lhs->e2 * rhs->e1;
  res.e13 =  + lhs->e1 * rhs->e3 + lhs->e3 * rhs->e1;
  res.e23 =  + lhs->e2 * rhs->e3 + lhs->e3 * rhs->e2;
  res.e14 =  + lhs->e1 * rhs->e4 + lhs->e4 * rhs->e1;
  res.e24 =  + lhs->e2 * rhs->e4 + lhs->e4 * rhs->e2;
  res.e34 =  + lhs->e3 * rhs->e4 + lhs->e4 * rhs->e3;
  res.e15 =  + lhs->e1 * rhs->e5 + lhs->e5 * rhs->e1;
  res.e25 =  + lhs->e2 * rhs->e5 + lhs->e5 * rhs->e2;
  res.e35 =  + lhs->e3 * rhs->e5 + lhs->e5 * rhs->e3;
  res.e45 =  + lhs->e4 * rhs->e5 + lhs->e5 * rhs->e4;
  res.e16 =  + lhs->e1 * rhs->e6 + lhs->e6 * rhs->e1;
  res.e26 =  + lhs->e2 * rhs->e6 + lhs->e6 * rhs->e2;
  res.e36 =  + lhs->e3 * rhs->e6 + lhs->e6 * rhs->e3;
  res.e46 =  + lhs->e4 * rhs->e6 + lhs->e6 * rhs->e4;
  res.e56 =  + lhs->e5 * rhs->e6 + lhs->e6 * rhs->e5;
  res.e17 =  + lhs->e1 * rhs->e7 + lhs->e7 * rhs->e1;
  res.e27 =  + lhs->e2 * rhs->e7 + lhs->e7 * rhs->e2;
  res.e37 =  + lhs->e3 * rhs->e7 + lhs->e7 * rhs->e3;
  res.e47 =  + lhs->e4 * rhs->e7 + lhs->e7 * rhs->e4;
  res.e57 =  + lhs->e5 * rhs->e7 + lhs->e7 * rhs->e5;
  res.e67 =  + lhs->e6 * rhs->e7 + lhs->e7 * rhs->e6;
  // Order 3;
  res.e123 =  + lhs->e1 * rhs->e23 + lhs->e23 * rhs->e1 + lhs->e2 * rhs->e13 
           + lhs->e13 * rhs->e2 + lhs->e3 * rhs->e12 + lhs->e12 * rhs->e3;
  res.e124 =  + lhs->e1 * rhs->e24 + lhs->e24 * rhs->e1 + lhs->e2 * rhs->e14 
           + lhs->e14 * rhs->e2 + lhs->e4 * rhs->e12 + lhs->e12 * rhs->e4;
  res.e134 =  + lhs->e1 * rhs->e34 + lhs->e34 * rhs->e1 + lhs->e3 * rhs->e14 
           + lhs->e14 * rhs->e3 + lhs->e4 * rhs->e13 + lhs->e13 * rhs->e4;
  res.e234 =  + lhs->e2 * rhs->e34 + lhs->e34 * rhs->e2 + lhs->e3 * rhs->e24 
           + lhs->e24 * rhs->e3 + lhs->e4 * rhs->e23 + lhs->e23 * rhs->e4;
  res.e125 =  + lhs->e1 * rhs->e25 + lhs->e25 * rhs->e1 + lhs->e2 * rhs->e15 
           + lhs->e15 * rhs->e2 + lhs->e5 * rhs->e12 + lhs->e12 * rhs->e5;
  res.e135 =  + lhs->e1 * rhs->e35 + lhs->e35 * rhs->e1 + lhs->e3 * rhs->e15 
           + lhs->e15 * rhs->e3 + lhs->e5 * rhs->e13 + lhs->e13 * rhs->e5;
  res.e235 =  + lhs->e2 * rhs->e35 + lhs->e35 * rhs->e2 + lhs->e3 * rhs->e25 
           + lhs->e25 * rhs->e3 + lhs->e5 * rhs->e23 + lhs->e23 * rhs->e5;
  res.e145 =  + lhs->e1 * rhs->e45 + lhs->e45 * rhs->e1 + lhs->e4 * rhs->e15 
           + lhs->e15 * rhs->e4 + lhs->e5 * rhs->e14 + lhs->e14 * rhs->e5;
  res.e245 =  + lhs->e2 * rhs->e45 + lhs->e45 * rhs->e2 + lhs->e4 * rhs->e25 
           + lhs->e25 * rhs->e4 + lhs->e5 * rhs->e24 + lhs->e24 * rhs->e5;
  res.e345 =  + lhs->e3 * rhs->e45 + lhs->e45 * rhs->e3 + lhs->e4 * rhs->e35 
           + lhs->e35 * rhs->e4 + lhs->e5 * rhs->e34 + lhs->e34 * rhs->e5;
  res.e126 =  + lhs->e1 * rhs->e26 + lhs->e26 * rhs->e1 + lhs->e2 * rhs->e16 
           + lhs->e16 * rhs->e2 + lhs->e6 * rhs->e12 + lhs->e12 * rhs->e6;
  res.e136 =  + lhs->e1 * rhs->e36 + lhs->e36 * rhs->e1 + lhs->e3 * rhs->e16 
           + lhs->e16 * rhs->e3 + lhs->e6 * rhs->e13 + lhs->e13 * rhs->e6;
  res.e236 =  + lhs->e2 * rhs->e36 + lhs->e36 * rhs->e2 + lhs->e3 * rhs->e26 
           + lhs->e26 * rhs->e3 + lhs->e6 * rhs->e23 + lhs->e23 * rhs->e6;
  res.e146 =  + lhs->e1 * rhs->e46 + lhs->e46 * rhs->e1 + lhs->e4 * rhs->e16 
           + lhs->e16 * rhs->e4 + lhs->e6 * rhs->e14 + lhs->e14 * rhs->e6;
  res.e246 =  + lhs->e2 * rhs->e46 + lhs->e46 * rhs->e2 + lhs->e4 * rhs->e26 
           + lhs->e26 * rhs->e4 + lhs->e6 * rhs->e24 + lhs->e24 * rhs->e6;
  res.e346 =  + lhs->e3 * rhs->e46 + lhs->e46 * rhs->e3 + lhs->e4 * rhs->e36 
           + lhs->e36 * rhs->e4 + lhs->e6 * rhs->e34 + lhs->e34 * rhs->e6;
  res.e156 =  + lhs->e1 * rhs->e56 + lhs->e56 * rhs->e1 + lhs->e5 * rhs->e16 
           + lhs->e16 * rhs->e5 + lhs->e6 * rhs->e15 + lhs->e15 * rhs->e6;
  res.e256 =  + lhs->e2 * rhs->e56 + lhs->e56 * rhs->e2 + lhs->e5 * rhs->e26 
           + lhs->e26 * rhs->e5 + lhs->e6 * rhs->e25 + lhs->e25 * rhs->e6;
  res.e356 =  + lhs->e3 * rhs->e56 + lhs->e56 * rhs->e3 + lhs->e5 * rhs->e36 
           + lhs->e36 * rhs->e5 + lhs->e6 * rhs->e35 + lhs->e35 * rhs->e6;
  res.e456 =  + lhs->e4 * rhs->e56 + lhs->e56 * rhs->e4 + lhs->e5 * rhs->e46 
           + lhs->e46 * rhs->e5 + lhs->e6 * rhs->e45 + lhs->e45 * rhs->e6;
  res.e127 =  + lhs->e1 * rhs->e27 + lhs->e27 * rhs->e1 + lhs->e2 * rhs->e17 
           + lhs->e17 * rhs->e2 + lhs->e7 * rhs->e12 + lhs->e12 * rhs->e7;
  res.e137 =  + lhs->e1 * rhs->e37 + lhs->e37 * rhs->e1 + lhs->e3 * rhs->e17 
           + lhs->e17 * rhs->e3 + lhs->e7 * rhs->e13 + lhs->e13 * rhs->e7;
  res.e237 =  + lhs->e2 * rhs->e37 + lhs->e37 * rhs->e2 + lhs->e3 * rhs->e27 
           + lhs->e27 * rhs->e3 + lhs->e7 * rhs->e23 + lhs->e23 * rhs->e7;
  res.e147 =  + lhs->e1 * rhs->e47 + lhs->e47 * rhs->e1 + lhs->e4 * rhs->e17 
           + lhs->e17 * rhs->e4 + lhs->e7 * rhs->e14 + lhs->e14 * rhs->e7;
  res.e247 =  + lhs->e2 * rhs->e47 + lhs->e47 * rhs->e2 + lhs->e4 * rhs->e27 
           + lhs->e27 * rhs->e4 + lhs->e7 * rhs->e24 + lhs->e24 * rhs->e7;
  res.e347 =  + lhs->e3 * rhs->e47 + lhs->e47 * rhs->e3 + lhs->e4 * rhs->e37 
           + lhs->e37 * rhs->e4 + lhs->e7 * rhs->e34 + lhs->e34 * rhs->e7;
  res.e157 =  + lhs->e1 * rhs->e57 + lhs->e57 * rhs->e1 + lhs->e5 * rhs->e17 
           + lhs->e17 * rhs->e5 + lhs->e7 * rhs->e15 + lhs->e15 * rhs->e7;
  res.e257 =  + lhs->e2 * rhs->e57 + lhs->e57 * rhs->e2 + lhs->e5 * rhs->e27 
           + lhs->e27 * rhs->e5 + lhs->e7 * rhs->e25 + lhs->e25 * rhs->e7;
  res.e357 =  + lhs->e3 * rhs->e57 + lhs->e57 * rhs->e3 + lhs->e5 * rhs->e37 
           + lhs->e37 * rhs->e5 + lhs->e7 * rhs->e35 + lhs->e35 * rhs->e7;
  res.e457 =  + lhs->e4 * rhs->e57 + lhs->e57 * rhs->e4 + lhs->e5 * rhs->e47 
           + lhs->e47 * rhs->e5 + lhs->e7 * rhs->e45 + lhs->e45 * rhs->e7;
  res.e167 =  + lhs->e1 * rhs->e67 + lhs->e67 * rhs->e1 + lhs->e6 * rhs->e17 
           + lhs->e17 * rhs->e6 + lhs->e7 * rhs->e16 + lhs->e16 * rhs->e7;
  res.e267 =  + lhs->e2 * rhs->e67 + lhs->e67 * rhs->e2 + lhs->e6 * rhs->e27 
           + lhs->e27 * rhs->e6 + lhs->e7 * rhs->e26 + lhs->e26 * rhs->e7;
  res.e367 =  + lhs->e3 * rhs->e67 + lhs->e67 * rhs->e3 + lhs->e6 * rhs->e37 
           + lhs->e37 * rhs->e6 + lhs->e7 * rhs->e36 + lhs->e36 * rhs->e7;
  res.e467 =  + lhs->e4 * rhs->e67 + lhs->e67 * rhs->e4 + lhs->e6 * rhs->e47 
           + lhs->e47 * rhs->e6 + lhs->e7 * rhs->e46 + lhs->e46 * rhs->e7;
  res.e567 =  + lhs->e5 * rhs->e67 + lhs->e67 * rhs->e5 + lhs->e6 * rhs->e57 
           + lhs->e57 * rhs->e6 + lhs->e7 * rhs->e56 + lhs->e56 * rhs->e7;
  // Order 4;
  res.e1234 =  + lhs->e1 * rhs->e234 + lhs->e234 * rhs->e1 + lhs->e2 * rhs->e134 
            + lhs->e134 * rhs->e2 + lhs->e3 * rhs->e124 + lhs->e124 * rhs->e3 
            + lhs->e4 * rhs->e123 + lhs->e123 * rhs->e4 + lhs->e12 * rhs->e34 
            + lhs->e13 * rhs->e24 + lhs->e23 * rhs->e14 + lhs->e14 * rhs->e23 
            + lhs->e24 * rhs->e13 + lhs->e34 * rhs->e12;
  res.e1235 =  + lhs->e1 * rhs->e235 + lhs->e235 * rhs->e1 + lhs->e2 * rhs->e135 
            + lhs->e135 * rhs->e2 + lhs->e3 * rhs->e125 + lhs->e125 * rhs->e3 
            + lhs->e5 * rhs->e123 + lhs->e123 * rhs->e5 + lhs->e12 * rhs->e35 
            + lhs->e13 * rhs->e25 + lhs->e23 * rhs->e15 + lhs->e15 * rhs->e23 
            + lhs->e25 * rhs->e13 + lhs->e35 * rhs->e12;
  res.e1245 =  + lhs->e1 * rhs->e245 + lhs->e245 * rhs->e1 + lhs->e2 * rhs->e145 
            + lhs->e145 * rhs->e2 + lhs->e4 * rhs->e125 + lhs->e125 * rhs->e4 
            + lhs->e5 * rhs->e124 + lhs->e124 * rhs->e5 + lhs->e12 * rhs->e45 
            + lhs->e14 * rhs->e25 + lhs->e24 * rhs->e15 + lhs->e15 * rhs->e24 
            + lhs->e25 * rhs->e14 + lhs->e45 * rhs->e12;
  res.e1345 =  + lhs->e1 * rhs->e345 + lhs->e345 * rhs->e1 + lhs->e3 * rhs->e145 
            + lhs->e145 * rhs->e3 + lhs->e4 * rhs->e135 + lhs->e135 * rhs->e4 
            + lhs->e5 * rhs->e134 + lhs->e134 * rhs->e5 + lhs->e13 * rhs->e45 
            + lhs->e14 * rhs->e35 + lhs->e34 * rhs->e15 + lhs->e15 * rhs->e34 
            + lhs->e35 * rhs->e14 + lhs->e45 * rhs->e13;
  res.e2345 =  + lhs->e2 * rhs->e345 + lhs->e345 * rhs->e2 + lhs->e3 * rhs->e245 
            + lhs->e245 * rhs->e3 + lhs->e4 * rhs->e235 + lhs->e235 * rhs->e4 
            + lhs->e5 * rhs->e234 + lhs->e234 * rhs->e5 + lhs->e23 * rhs->e45 
            + lhs->e24 * rhs->e35 + lhs->e34 * rhs->e25 + lhs->e25 * rhs->e34 
            + lhs->e35 * rhs->e24 + lhs->e45 * rhs->e23;
  res.e1236 =  + lhs->e1 * rhs->e236 + lhs->e236 * rhs->e1 + lhs->e2 * rhs->e136 
            + lhs->e136 * rhs->e2 + lhs->e3 * rhs->e126 + lhs->e126 * rhs->e3 
            + lhs->e6 * rhs->e123 + lhs->e123 * rhs->e6 + lhs->e12 * rhs->e36 
            + lhs->e13 * rhs->e26 + lhs->e23 * rhs->e16 + lhs->e16 * rhs->e23 
            + lhs->e26 * rhs->e13 + lhs->e36 * rhs->e12;
  res.e1246 =  + lhs->e1 * rhs->e246 + lhs->e246 * rhs->e1 + lhs->e2 * rhs->e146 
            + lhs->e146 * rhs->e2 + lhs->e4 * rhs->e126 + lhs->e126 * rhs->e4 
            + lhs->e6 * rhs->e124 + lhs->e124 * rhs->e6 + lhs->e12 * rhs->e46 
            + lhs->e14 * rhs->e26 + lhs->e24 * rhs->e16 + lhs->e16 * rhs->e24 
            + lhs->e26 * rhs->e14 + lhs->e46 * rhs->e12;
  res.e1346 =  + lhs->e1 * rhs->e346 + lhs->e346 * rhs->e1 + lhs->e3 * rhs->e146 
            + lhs->e146 * rhs->e3 + lhs->e4 * rhs->e136 + lhs->e136 * rhs->e4 
            + lhs->e6 * rhs->e134 + lhs->e134 * rhs->e6 + lhs->e13 * rhs->e46 
            + lhs->e14 * rhs->e36 + lhs->e34 * rhs->e16 + lhs->e16 * rhs->e34 
            + lhs->e36 * rhs->e14 + lhs->e46 * rhs->e13;
  res.e2346 =  + lhs->e2 * rhs->e346 + lhs->e346 * rhs->e2 + lhs->e3 * rhs->e246 
            + lhs->e246 * rhs->e3 + lhs->e4 * rhs->e236 + lhs->e236 * rhs->e4 
            + lhs->e6 * rhs->e234 + lhs->e234 * rhs->e6 + lhs->e23 * rhs->e46 
            + lhs->e24 * rhs->e36 + lhs->e34 * rhs->e26 + lhs->e26 * rhs->e34 
            + lhs->e36 * rhs->e24 + lhs->e46 * rhs->e23;
  res.e1256 =  + lhs->e1 * rhs->e256 + lhs->e256 * rhs->e1 + lhs->e2 * rhs->e156 
            + lhs->e156 * rhs->e2 + lhs->e5 * rhs->e126 + lhs->e126 * rhs->e5 
            + lhs->e6 * rhs->e125 + lhs->e125 * rhs->e6 + lhs->e12 * rhs->e56 
            + lhs->e15 * rhs->e26 + lhs->e25 * rhs->e16 + lhs->e16 * rhs->e25 
            + lhs->e26 * rhs->e15 + lhs->e56 * rhs->e12;
  res.e1356 =  + lhs->e1 * rhs->e356 + lhs->e356 * rhs->e1 + lhs->e3 * rhs->e156 
            + lhs->e156 * rhs->e3 + lhs->e5 * rhs->e136 + lhs->e136 * rhs->e5 
            + lhs->e6 * rhs->e135 + lhs->e135 * rhs->e6 + lhs->e13 * rhs->e56 
            + lhs->e15 * rhs->e36 + lhs->e35 * rhs->e16 + lhs->e16 * rhs->e35 
            + lhs->e36 * rhs->e15 + lhs->e56 * rhs->e13;
  res.e2356 =  + lhs->e2 * rhs->e356 + lhs->e356 * rhs->e2 + lhs->e3 * rhs->e256 
            + lhs->e256 * rhs->e3 + lhs->e5 * rhs->e236 + lhs->e236 * rhs->e5 
            + lhs->e6 * rhs->e235 + lhs->e235 * rhs->e6 + lhs->e23 * rhs->e56 
            + lhs->e25 * rhs->e36 + lhs->e35 * rhs->e26 + lhs->e26 * rhs->e35 
            + lhs->e36 * rhs->e25 + lhs->e56 * rhs->e23;
  res.e1456 =  + lhs->e1 * rhs->e456 + lhs->e456 * rhs->e1 + lhs->e4 * rhs->e156 
            + lhs->e156 * rhs->e4 + lhs->e5 * rhs->e146 + lhs->e146 * rhs->e5 
            + lhs->e6 * rhs->e145 + lhs->e145 * rhs->e6 + lhs->e14 * rhs->e56 
            + lhs->e15 * rhs->e46 + lhs->e45 * rhs->e16 + lhs->e16 * rhs->e45 
            + lhs->e46 * rhs->e15 + lhs->e56 * rhs->e14;
  res.e2456 =  + lhs->e2 * rhs->e456 + lhs->e456 * rhs->e2 + lhs->e4 * rhs->e256 
            + lhs->e256 * rhs->e4 + lhs->e5 * rhs->e246 + lhs->e246 * rhs->e5 
            + lhs->e6 * rhs->e245 + lhs->e245 * rhs->e6 + lhs->e24 * rhs->e56 
            + lhs->e25 * rhs->e46 + lhs->e45 * rhs->e26 + lhs->e26 * rhs->e45 
            + lhs->e46 * rhs->e25 + lhs->e56 * rhs->e24;
  res.e3456 =  + lhs->e3 * rhs->e456 + lhs->e456 * rhs->e3 + lhs->e4 * rhs->e356 
            + lhs->e356 * rhs->e4 + lhs->e5 * rhs->e346 + lhs->e346 * rhs->e5 
            + lhs->e6 * rhs->e345 + lhs->e345 * rhs->e6 + lhs->e34 * rhs->e56 
            + lhs->e35 * rhs->e46 + lhs->e45 * rhs->e36 + lhs->e36 * rhs->e45 
            + lhs->e46 * rhs->e35 + lhs->e56 * rhs->e34;
  res.e1237 =  + lhs->e1 * rhs->e237 + lhs->e237 * rhs->e1 + lhs->e2 * rhs->e137 
            + lhs->e137 * rhs->e2 + lhs->e3 * rhs->e127 + lhs->e127 * rhs->e3 
            + lhs->e7 * rhs->e123 + lhs->e123 * rhs->e7 + lhs->e12 * rhs->e37 
            + lhs->e13 * rhs->e27 + lhs->e23 * rhs->e17 + lhs->e17 * rhs->e23 
            + lhs->e27 * rhs->e13 + lhs->e37 * rhs->e12;
  res.e1247 =  + lhs->e1 * rhs->e247 + lhs->e247 * rhs->e1 + lhs->e2 * rhs->e147 
            + lhs->e147 * rhs->e2 + lhs->e4 * rhs->e127 + lhs->e127 * rhs->e4 
            + lhs->e7 * rhs->e124 + lhs->e124 * rhs->e7 + lhs->e12 * rhs->e47 
            + lhs->e14 * rhs->e27 + lhs->e24 * rhs->e17 + lhs->e17 * rhs->e24 
            + lhs->e27 * rhs->e14 + lhs->e47 * rhs->e12;
  res.e1347 =  + lhs->e1 * rhs->e347 + lhs->e347 * rhs->e1 + lhs->e3 * rhs->e147 
            + lhs->e147 * rhs->e3 + lhs->e4 * rhs->e137 + lhs->e137 * rhs->e4 
            + lhs->e7 * rhs->e134 + lhs->e134 * rhs->e7 + lhs->e13 * rhs->e47 
            + lhs->e14 * rhs->e37 + lhs->e34 * rhs->e17 + lhs->e17 * rhs->e34 
            + lhs->e37 * rhs->e14 + lhs->e47 * rhs->e13;
  res.e2347 =  + lhs->e2 * rhs->e347 + lhs->e347 * rhs->e2 + lhs->e3 * rhs->e247 
            + lhs->e247 * rhs->e3 + lhs->e4 * rhs->e237 + lhs->e237 * rhs->e4 
            + lhs->e7 * rhs->e234 + lhs->e234 * rhs->e7 + lhs->e23 * rhs->e47 
            + lhs->e24 * rhs->e37 + lhs->e34 * rhs->e27 + lhs->e27 * rhs->e34 
            + lhs->e37 * rhs->e24 + lhs->e47 * rhs->e23;
  res.e1257 =  + lhs->e1 * rhs->e257 + lhs->e257 * rhs->e1 + lhs->e2 * rhs->e157 
            + lhs->e157 * rhs->e2 + lhs->e5 * rhs->e127 + lhs->e127 * rhs->e5 
            + lhs->e7 * rhs->e125 + lhs->e125 * rhs->e7 + lhs->e12 * rhs->e57 
            + lhs->e15 * rhs->e27 + lhs->e25 * rhs->e17 + lhs->e17 * rhs->e25 
            + lhs->e27 * rhs->e15 + lhs->e57 * rhs->e12;
  res.e1357 =  + lhs->e1 * rhs->e357 + lhs->e357 * rhs->e1 + lhs->e3 * rhs->e157 
            + lhs->e157 * rhs->e3 + lhs->e5 * rhs->e137 + lhs->e137 * rhs->e5 
            + lhs->e7 * rhs->e135 + lhs->e135 * rhs->e7 + lhs->e13 * rhs->e57 
            + lhs->e15 * rhs->e37 + lhs->e35 * rhs->e17 + lhs->e17 * rhs->e35 
            + lhs->e37 * rhs->e15 + lhs->e57 * rhs->e13;
  res.e2357 =  + lhs->e2 * rhs->e357 + lhs->e357 * rhs->e2 + lhs->e3 * rhs->e257 
            + lhs->e257 * rhs->e3 + lhs->e5 * rhs->e237 + lhs->e237 * rhs->e5 
            + lhs->e7 * rhs->e235 + lhs->e235 * rhs->e7 + lhs->e23 * rhs->e57 
            + lhs->e25 * rhs->e37 + lhs->e35 * rhs->e27 + lhs->e27 * rhs->e35 
            + lhs->e37 * rhs->e25 + lhs->e57 * rhs->e23;
  res.e1457 =  + lhs->e1 * rhs->e457 + lhs->e457 * rhs->e1 + lhs->e4 * rhs->e157 
            + lhs->e157 * rhs->e4 + lhs->e5 * rhs->e147 + lhs->e147 * rhs->e5 
            + lhs->e7 * rhs->e145 + lhs->e145 * rhs->e7 + lhs->e14 * rhs->e57 
            + lhs->e15 * rhs->e47 + lhs->e45 * rhs->e17 + lhs->e17 * rhs->e45 
            + lhs->e47 * rhs->e15 + lhs->e57 * rhs->e14;
  res.e2457 =  + lhs->e2 * rhs->e457 + lhs->e457 * rhs->e2 + lhs->e4 * rhs->e257 
            + lhs->e257 * rhs->e4 + lhs->e5 * rhs->e247 + lhs->e247 * rhs->e5 
            + lhs->e7 * rhs->e245 + lhs->e245 * rhs->e7 + lhs->e24 * rhs->e57 
            + lhs->e25 * rhs->e47 + lhs->e45 * rhs->e27 + lhs->e27 * rhs->e45 
            + lhs->e47 * rhs->e25 + lhs->e57 * rhs->e24;
  res.e3457 =  + lhs->e3 * rhs->e457 + lhs->e457 * rhs->e3 + lhs->e4 * rhs->e357 
            + lhs->e357 * rhs->e4 + lhs->e5 * rhs->e347 + lhs->e347 * rhs->e5 
            + lhs->e7 * rhs->e345 + lhs->e345 * rhs->e7 + lhs->e34 * rhs->e57 
            + lhs->e35 * rhs->e47 + lhs->e45 * rhs->e37 + lhs->e37 * rhs->e45 
            + lhs->e47 * rhs->e35 + lhs->e57 * rhs->e34;
  res.e1267 =  + lhs->e1 * rhs->e267 + lhs->e267 * rhs->e1 + lhs->e2 * rhs->e167 
            + lhs->e167 * rhs->e2 + lhs->e6 * rhs->e127 + lhs->e127 * rhs->e6 
            + lhs->e7 * rhs->e126 + lhs->e126 * rhs->e7 + lhs->e12 * rhs->e67 
            + lhs->e16 * rhs->e27 + lhs->e26 * rhs->e17 + lhs->e17 * rhs->e26 
            + lhs->e27 * rhs->e16 + lhs->e67 * rhs->e12;
  res.e1367 =  + lhs->e1 * rhs->e367 + lhs->e367 * rhs->e1 + lhs->e3 * rhs->e167 
            + lhs->e167 * rhs->e3 + lhs->e6 * rhs->e137 + lhs->e137 * rhs->e6 
            + lhs->e7 * rhs->e136 + lhs->e136 * rhs->e7 + lhs->e13 * rhs->e67 
            + lhs->e16 * rhs->e37 + lhs->e36 * rhs->e17 + lhs->e17 * rhs->e36 
            + lhs->e37 * rhs->e16 + lhs->e67 * rhs->e13;
  res.e2367 =  + lhs->e2 * rhs->e367 + lhs->e367 * rhs->e2 + lhs->e3 * rhs->e267 
            + lhs->e267 * rhs->e3 + lhs->e6 * rhs->e237 + lhs->e237 * rhs->e6 
            + lhs->e7 * rhs->e236 + lhs->e236 * rhs->e7 + lhs->e23 * rhs->e67 
            + lhs->e26 * rhs->e37 + lhs->e36 * rhs->e27 + lhs->e27 * rhs->e36 
            + lhs->e37 * rhs->e26 + lhs->e67 * rhs->e23;
  res.e1467 =  + lhs->e1 * rhs->e467 + lhs->e467 * rhs->e1 + lhs->e4 * rhs->e167 
            + lhs->e167 * rhs->e4 + lhs->e6 * rhs->e147 + lhs->e147 * rhs->e6 
            + lhs->e7 * rhs->e146 + lhs->e146 * rhs->e7 + lhs->e14 * rhs->e67 
            + lhs->e16 * rhs->e47 + lhs->e46 * rhs->e17 + lhs->e17 * rhs->e46 
            + lhs->e47 * rhs->e16 + lhs->e67 * rhs->e14;
  res.e2467 =  + lhs->e2 * rhs->e467 + lhs->e467 * rhs->e2 + lhs->e4 * rhs->e267 
            + lhs->e267 * rhs->e4 + lhs->e6 * rhs->e247 + lhs->e247 * rhs->e6 
            + lhs->e7 * rhs->e246 + lhs->e246 * rhs->e7 + lhs->e24 * rhs->e67 
            + lhs->e26 * rhs->e47 + lhs->e46 * rhs->e27 + lhs->e27 * rhs->e46 
            + lhs->e47 * rhs->e26 + lhs->e67 * rhs->e24;
  res.e3467 =  + lhs->e3 * rhs->e467 + lhs->e467 * rhs->e3 + lhs->e4 * rhs->e367 
            + lhs->e367 * rhs->e4 + lhs->e6 * rhs->e347 + lhs->e347 * rhs->e6 
            + lhs->e7 * rhs->e346 + lhs->e346 * rhs->e7 + lhs->e34 * rhs->e67 
            + lhs->e36 * rhs->e47 + lhs->e46 * rhs->e37 + lhs->e37 * rhs->e46 
            + lhs->e47 * rhs->e36 + lhs->e67 * rhs->e34;
  res.e1567 =  + lhs->e1 * rhs->e567 + lhs->e567 * rhs->e1 + lhs->e5 * rhs->e167 
            + lhs->e167 * rhs->e5 + lhs->e6 * rhs->e157 + lhs->e157 * rhs->e6 
            + lhs->e7 * rhs->e156 + lhs->e156 * rhs->e7 + lhs->e15 * rhs->e67 
            + lhs->e16 * rhs->e57 + lhs->e56 * rhs->e17 + lhs->e17 * rhs->e56 
            + lhs->e57 * rhs->e16 + lhs->e67 * rhs->e15;
  res.e2567 =  + lhs->e2 * rhs->e567 + lhs->e567 * rhs->e2 + lhs->e5 * rhs->e267 
            + lhs->e267 * rhs->e5 + lhs->e6 * rhs->e257 + lhs->e257 * rhs->e6 
            + lhs->e7 * rhs->e256 + lhs->e256 * rhs->e7 + lhs->e25 * rhs->e67 
            + lhs->e26 * rhs->e57 + lhs->e56 * rhs->e27 + lhs->e27 * rhs->e56 
            + lhs->e57 * rhs->e26 + lhs->e67 * rhs->e25;
  res.e3567 =  + lhs->e3 * rhs->e567 + lhs->e567 * rhs->e3 + lhs->e5 * rhs->e367 
            + lhs->e367 * rhs->e5 + lhs->e6 * rhs->e357 + lhs->e357 * rhs->e6 
            + lhs->e7 * rhs->e356 + lhs->e356 * rhs->e7 + lhs->e35 * rhs->e67 
            + lhs->e36 * rhs->e57 + lhs->e56 * rhs->e37 + lhs->e37 * rhs->e56 
            + lhs->e57 * rhs->e36 + lhs->e67 * rhs->e35;
  res.e4567 =  + lhs->e4 * rhs->e567 + lhs->e567 * rhs->e4 + lhs->e5 * rhs->e467 
            + lhs->e467 * rhs->e5 + lhs->e6 * rhs->e457 + lhs->e457 * rhs->e6 
            + lhs->e7 * rhs->e456 + lhs->e456 * rhs->e7 + lhs->e45 * rhs->e67 
            + lhs->e46 * rhs->e57 + lhs->e56 * rhs->e47 + lhs->e47 * rhs->e56 
            + lhs->e57 * rhs->e46 + lhs->e67 * rhs->e45;
  // Order 5;
  res.e12345 =  + lhs->e1 * rhs->e2345 + lhs->e2345 * rhs->e1 + lhs->e2 * rhs->e1345 
             + lhs->e1345 * rhs->e2 + lhs->e3 * rhs->e1245 + lhs->e1245 * rhs->e3 
             + lhs->e4 * rhs->e1235 + lhs->e1235 * rhs->e4 + lhs->e5 * rhs->e1234 
             + lhs->e1234 * rhs->e5 + lhs->e12 * rhs->e345 + lhs->e345 * rhs->e12 
             + lhs->e13 * rhs->e245 + lhs->e245 * rhs->e13 + lhs->e23 * rhs->e145 
             + lhs->e145 * rhs->e23 + lhs->e14 * rhs->e235 + lhs->e235 * rhs->e14 
             + lhs->e24 * rhs->e135 + lhs->e135 * rhs->e24 + lhs->e34 * rhs->e125 
             + lhs->e125 * rhs->e34 + lhs->e15 * rhs->e234 + lhs->e234 * rhs->e15 
             + lhs->e25 * rhs->e134 + lhs->e134 * rhs->e25 + lhs->e35 * rhs->e124 
             + lhs->e124 * rhs->e35 + lhs->e45 * rhs->e123 + lhs->e123 * rhs->e45;
  res.e12346 =  + lhs->e1 * rhs->e2346 + lhs->e2346 * rhs->e1 + lhs->e2 * rhs->e1346 
             + lhs->e1346 * rhs->e2 + lhs->e3 * rhs->e1246 + lhs->e1246 * rhs->e3 
             + lhs->e4 * rhs->e1236 + lhs->e1236 * rhs->e4 + lhs->e6 * rhs->e1234 
             + lhs->e1234 * rhs->e6 + lhs->e12 * rhs->e346 + lhs->e346 * rhs->e12 
             + lhs->e13 * rhs->e246 + lhs->e246 * rhs->e13 + lhs->e23 * rhs->e146 
             + lhs->e146 * rhs->e23 + lhs->e14 * rhs->e236 + lhs->e236 * rhs->e14 
             + lhs->e24 * rhs->e136 + lhs->e136 * rhs->e24 + lhs->e34 * rhs->e126 
             + lhs->e126 * rhs->e34 + lhs->e16 * rhs->e234 + lhs->e234 * rhs->e16 
             + lhs->e26 * rhs->e134 + lhs->e134 * rhs->e26 + lhs->e36 * rhs->e124 
             + lhs->e124 * rhs->e36 + lhs->e46 * rhs->e123 + lhs->e123 * rhs->e46;
  res.e12356 =  + lhs->e1 * rhs->e2356 + lhs->e2356 * rhs->e1 + lhs->e2 * rhs->e1356 
             + lhs->e1356 * rhs->e2 + lhs->e3 * rhs->e1256 + lhs->e1256 * rhs->e3 
             + lhs->e5 * rhs->e1236 + lhs->e1236 * rhs->e5 + lhs->e6 * rhs->e1235 
             + lhs->e1235 * rhs->e6 + lhs->e12 * rhs->e356 + lhs->e356 * rhs->e12 
             + lhs->e13 * rhs->e256 + lhs->e256 * rhs->e13 + lhs->e23 * rhs->e156 
             + lhs->e156 * rhs->e23 + lhs->e15 * rhs->e236 + lhs->e236 * rhs->e15 
             + lhs->e25 * rhs->e136 + lhs->e136 * rhs->e25 + lhs->e35 * rhs->e126 
             + lhs->e126 * rhs->e35 + lhs->e16 * rhs->e235 + lhs->e235 * rhs->e16 
             + lhs->e26 * rhs->e135 + lhs->e135 * rhs->e26 + lhs->e36 * rhs->e125 
             + lhs->e125 * rhs->e36 + lhs->e56 * rhs->e123 + lhs->e123 * rhs->e56;
  res.e12456 =  + lhs->e1 * rhs->e2456 + lhs->e2456 * rhs->e1 + lhs->e2 * rhs->e1456 
             + lhs->e1456 * rhs->e2 + lhs->e4 * rhs->e1256 + lhs->e1256 * rhs->e4 
             + lhs->e5 * rhs->e1246 + lhs->e1246 * rhs->e5 + lhs->e6 * rhs->e1245 
             + lhs->e1245 * rhs->e6 + lhs->e12 * rhs->e456 + lhs->e456 * rhs->e12 
             + lhs->e14 * rhs->e256 + lhs->e256 * rhs->e14 + lhs->e24 * rhs->e156 
             + lhs->e156 * rhs->e24 + lhs->e15 * rhs->e246 + lhs->e246 * rhs->e15 
             + lhs->e25 * rhs->e146 + lhs->e146 * rhs->e25 + lhs->e45 * rhs->e126 
             + lhs->e126 * rhs->e45 + lhs->e16 * rhs->e245 + lhs->e245 * rhs->e16 
             + lhs->e26 * rhs->e145 + lhs->e145 * rhs->e26 + lhs->e46 * rhs->e125 
             + lhs->e125 * rhs->e46 + lhs->e56 * rhs->e124 + lhs->e124 * rhs->e56;
  res.e13456 =  + lhs->e1 * rhs->e3456 + lhs->e3456 * rhs->e1 + lhs->e3 * rhs->e1456 
             + lhs->e1456 * rhs->e3 + lhs->e4 * rhs->e1356 + lhs->e1356 * rhs->e4 
             + lhs->e5 * rhs->e1346 + lhs->e1346 * rhs->e5 + lhs->e6 * rhs->e1345 
             + lhs->e1345 * rhs->e6 + lhs->e13 * rhs->e456 + lhs->e456 * rhs->e13 
             + lhs->e14 * rhs->e356 + lhs->e356 * rhs->e14 + lhs->e34 * rhs->e156 
             + lhs->e156 * rhs->e34 + lhs->e15 * rhs->e346 + lhs->e346 * rhs->e15 
             + lhs->e35 * rhs->e146 + lhs->e146 * rhs->e35 + lhs->e45 * rhs->e136 
             + lhs->e136 * rhs->e45 + lhs->e16 * rhs->e345 + lhs->e345 * rhs->e16 
             + lhs->e36 * rhs->e145 + lhs->e145 * rhs->e36 + lhs->e46 * rhs->e135 
             + lhs->e135 * rhs->e46 + lhs->e56 * rhs->e134 + lhs->e134 * rhs->e56;
  res.e23456 =  + lhs->e2 * rhs->e3456 + lhs->e3456 * rhs->e2 + lhs->e3 * rhs->e2456 
             + lhs->e2456 * rhs->e3 + lhs->e4 * rhs->e2356 + lhs->e2356 * rhs->e4 
             + lhs->e5 * rhs->e2346 + lhs->e2346 * rhs->e5 + lhs->e6 * rhs->e2345 
             + lhs->e2345 * rhs->e6 + lhs->e23 * rhs->e456 + lhs->e456 * rhs->e23 
             + lhs->e24 * rhs->e356 + lhs->e356 * rhs->e24 + lhs->e34 * rhs->e256 
             + lhs->e256 * rhs->e34 + lhs->e25 * rhs->e346 + lhs->e346 * rhs->e25 
             + lhs->e35 * rhs->e246 + lhs->e246 * rhs->e35 + lhs->e45 * rhs->e236 
             + lhs->e236 * rhs->e45 + lhs->e26 * rhs->e345 + lhs->e345 * rhs->e26 
             + lhs->e36 * rhs->e245 + lhs->e245 * rhs->e36 + lhs->e46 * rhs->e235 
             + lhs->e235 * rhs->e46 + lhs->e56 * rhs->e234 + lhs->e234 * rhs->e56;
  res.e12347 =  + lhs->e1 * rhs->e2347 + lhs->e2347 * rhs->e1 + lhs->e2 * rhs->e1347 
             + lhs->e1347 * rhs->e2 + lhs->e3 * rhs->e1247 + lhs->e1247 * rhs->e3 
             + lhs->e4 * rhs->e1237 + lhs->e1237 * rhs->e4 + lhs->e7 * rhs->e1234 
             + lhs->e1234 * rhs->e7 + lhs->e12 * rhs->e347 + lhs->e347 * rhs->e12 
             + lhs->e13 * rhs->e247 + lhs->e247 * rhs->e13 + lhs->e23 * rhs->e147 
             + lhs->e147 * rhs->e23 + lhs->e14 * rhs->e237 + lhs->e237 * rhs->e14 
             + lhs->e24 * rhs->e137 + lhs->e137 * rhs->e24 + lhs->e34 * rhs->e127 
             + lhs->e127 * rhs->e34 + lhs->e17 * rhs->e234 + lhs->e234 * rhs->e17 
             + lhs->e27 * rhs->e134 + lhs->e134 * rhs->e27 + lhs->e37 * rhs->e124 
             + lhs->e124 * rhs->e37 + lhs->e47 * rhs->e123 + lhs->e123 * rhs->e47;
  res.e12357 =  + lhs->e1 * rhs->e2357 + lhs->e2357 * rhs->e1 + lhs->e2 * rhs->e1357 
             + lhs->e1357 * rhs->e2 + lhs->e3 * rhs->e1257 + lhs->e1257 * rhs->e3 
             + lhs->e5 * rhs->e1237 + lhs->e1237 * rhs->e5 + lhs->e7 * rhs->e1235 
             + lhs->e1235 * rhs->e7 + lhs->e12 * rhs->e357 + lhs->e357 * rhs->e12 
             + lhs->e13 * rhs->e257 + lhs->e257 * rhs->e13 + lhs->e23 * rhs->e157 
             + lhs->e157 * rhs->e23 + lhs->e15 * rhs->e237 + lhs->e237 * rhs->e15 
             + lhs->e25 * rhs->e137 + lhs->e137 * rhs->e25 + lhs->e35 * rhs->e127 
             + lhs->e127 * rhs->e35 + lhs->e17 * rhs->e235 + lhs->e235 * rhs->e17 
             + lhs->e27 * rhs->e135 + lhs->e135 * rhs->e27 + lhs->e37 * rhs->e125 
             + lhs->e125 * rhs->e37 + lhs->e57 * rhs->e123 + lhs->e123 * rhs->e57;
  res.e12457 =  + lhs->e1 * rhs->e2457 + lhs->e2457 * rhs->e1 + lhs->e2 * rhs->e1457 
             + lhs->e1457 * rhs->e2 + lhs->e4 * rhs->e1257 + lhs->e1257 * rhs->e4 
             + lhs->e5 * rhs->e1247 + lhs->e1247 * rhs->e5 + lhs->e7 * rhs->e1245 
             + lhs->e1245 * rhs->e7 + lhs->e12 * rhs->e457 + lhs->e457 * rhs->e12 
             + lhs->e14 * rhs->e257 + lhs->e257 * rhs->e14 + lhs->e24 * rhs->e157 
             + lhs->e157 * rhs->e24 + lhs->e15 * rhs->e247 + lhs->e247 * rhs->e15 
             + lhs->e25 * rhs->e147 + lhs->e147 * rhs->e25 + lhs->e45 * rhs->e127 
             + lhs->e127 * rhs->e45 + lhs->e17 * rhs->e245 + lhs->e245 * rhs->e17 
             + lhs->e27 * rhs->e145 + lhs->e145 * rhs->e27 + lhs->e47 * rhs->e125 
             + lhs->e125 * rhs->e47 + lhs->e57 * rhs->e124 + lhs->e124 * rhs->e57;
  res.e13457 =  + lhs->e1 * rhs->e3457 + lhs->e3457 * rhs->e1 + lhs->e3 * rhs->e1457 
             + lhs->e1457 * rhs->e3 + lhs->e4 * rhs->e1357 + lhs->e1357 * rhs->e4 
             + lhs->e5 * rhs->e1347 + lhs->e1347 * rhs->e5 + lhs->e7 * rhs->e1345 
             + lhs->e1345 * rhs->e7 + lhs->e13 * rhs->e457 + lhs->e457 * rhs->e13 
             + lhs->e14 * rhs->e357 + lhs->e357 * rhs->e14 + lhs->e34 * rhs->e157 
             + lhs->e157 * rhs->e34 + lhs->e15 * rhs->e347 + lhs->e347 * rhs->e15 
             + lhs->e35 * rhs->e147 + lhs->e147 * rhs->e35 + lhs->e45 * rhs->e137 
             + lhs->e137 * rhs->e45 + lhs->e17 * rhs->e345 + lhs->e345 * rhs->e17 
             + lhs->e37 * rhs->e145 + lhs->e145 * rhs->e37 + lhs->e47 * rhs->e135 
             + lhs->e135 * rhs->e47 + lhs->e57 * rhs->e134 + lhs->e134 * rhs->e57;
  res.e23457 =  + lhs->e2 * rhs->e3457 + lhs->e3457 * rhs->e2 + lhs->e3 * rhs->e2457 
             + lhs->e2457 * rhs->e3 + lhs->e4 * rhs->e2357 + lhs->e2357 * rhs->e4 
             + lhs->e5 * rhs->e2347 + lhs->e2347 * rhs->e5 + lhs->e7 * rhs->e2345 
             + lhs->e2345 * rhs->e7 + lhs->e23 * rhs->e457 + lhs->e457 * rhs->e23 
             + lhs->e24 * rhs->e357 + lhs->e357 * rhs->e24 + lhs->e34 * rhs->e257 
             + lhs->e257 * rhs->e34 + lhs->e25 * rhs->e347 + lhs->e347 * rhs->e25 
             + lhs->e35 * rhs->e247 + lhs->e247 * rhs->e35 + lhs->e45 * rhs->e237 
             + lhs->e237 * rhs->e45 + lhs->e27 * rhs->e345 + lhs->e345 * rhs->e27 
             + lhs->e37 * rhs->e245 + lhs->e245 * rhs->e37 + lhs->e47 * rhs->e235 
             + lhs->e235 * rhs->e47 + lhs->e57 * rhs->e234 + lhs->e234 * rhs->e57;
  res.e12367 =  + lhs->e1 * rhs->e2367 + lhs->e2367 * rhs->e1 + lhs->e2 * rhs->e1367 
             + lhs->e1367 * rhs->e2 + lhs->e3 * rhs->e1267 + lhs->e1267 * rhs->e3 
             + lhs->e6 * rhs->e1237 + lhs->e1237 * rhs->e6 + lhs->e7 * rhs->e1236 
             + lhs->e1236 * rhs->e7 + lhs->e12 * rhs->e367 + lhs->e367 * rhs->e12 
             + lhs->e13 * rhs->e267 + lhs->e267 * rhs->e13 + lhs->e23 * rhs->e167 
             + lhs->e167 * rhs->e23 + lhs->e16 * rhs->e237 + lhs->e237 * rhs->e16 
             + lhs->e26 * rhs->e137 + lhs->e137 * rhs->e26 + lhs->e36 * rhs->e127 
             + lhs->e127 * rhs->e36 + lhs->e17 * rhs->e236 + lhs->e236 * rhs->e17 
             + lhs->e27 * rhs->e136 + lhs->e136 * rhs->e27 + lhs->e37 * rhs->e126 
             + lhs->e126 * rhs->e37 + lhs->e67 * rhs->e123 + lhs->e123 * rhs->e67;
  res.e12467 =  + lhs->e1 * rhs->e2467 + lhs->e2467 * rhs->e1 + lhs->e2 * rhs->e1467 
             + lhs->e1467 * rhs->e2 + lhs->e4 * rhs->e1267 + lhs->e1267 * rhs->e4 
             + lhs->e6 * rhs->e1247 + lhs->e1247 * rhs->e6 + lhs->e7 * rhs->e1246 
             + lhs->e1246 * rhs->e7 + lhs->e12 * rhs->e467 + lhs->e467 * rhs->e12 
             + lhs->e14 * rhs->e267 + lhs->e267 * rhs->e14 + lhs->e24 * rhs->e167 
             + lhs->e167 * rhs->e24 + lhs->e16 * rhs->e247 + lhs->e247 * rhs->e16 
             + lhs->e26 * rhs->e147 + lhs->e147 * rhs->e26 + lhs->e46 * rhs->e127 
             + lhs->e127 * rhs->e46 + lhs->e17 * rhs->e246 + lhs->e246 * rhs->e17 
             + lhs->e27 * rhs->e146 + lhs->e146 * rhs->e27 + lhs->e47 * rhs->e126 
             + lhs->e126 * rhs->e47 + lhs->e67 * rhs->e124 + lhs->e124 * rhs->e67;
  res.e13467 =  + lhs->e1 * rhs->e3467 + lhs->e3467 * rhs->e1 + lhs->e3 * rhs->e1467 
             + lhs->e1467 * rhs->e3 + lhs->e4 * rhs->e1367 + lhs->e1367 * rhs->e4 
             + lhs->e6 * rhs->e1347 + lhs->e1347 * rhs->e6 + lhs->e7 * rhs->e1346 
             + lhs->e1346 * rhs->e7 + lhs->e13 * rhs->e467 + lhs->e467 * rhs->e13 
             + lhs->e14 * rhs->e367 + lhs->e367 * rhs->e14 + lhs->e34 * rhs->e167 
             + lhs->e167 * rhs->e34 + lhs->e16 * rhs->e347 + lhs->e347 * rhs->e16 
             + lhs->e36 * rhs->e147 + lhs->e147 * rhs->e36 + lhs->e46 * rhs->e137 
             + lhs->e137 * rhs->e46 + lhs->e17 * rhs->e346 + lhs->e346 * rhs->e17 
             + lhs->e37 * rhs->e146 + lhs->e146 * rhs->e37 + lhs->e47 * rhs->e136 
             + lhs->e136 * rhs->e47 + lhs->e67 * rhs->e134 + lhs->e134 * rhs->e67;
  res.e23467 =  + lhs->e2 * rhs->e3467 + lhs->e3467 * rhs->e2 + lhs->e3 * rhs->e2467 
             + lhs->e2467 * rhs->e3 + lhs->e4 * rhs->e2367 + lhs->e2367 * rhs->e4 
             + lhs->e6 * rhs->e2347 + lhs->e2347 * rhs->e6 + lhs->e7 * rhs->e2346 
             + lhs->e2346 * rhs->e7 + lhs->e23 * rhs->e467 + lhs->e467 * rhs->e23 
             + lhs->e24 * rhs->e367 + lhs->e367 * rhs->e24 + lhs->e34 * rhs->e267 
             + lhs->e267 * rhs->e34 + lhs->e26 * rhs->e347 + lhs->e347 * rhs->e26 
             + lhs->e36 * rhs->e247 + lhs->e247 * rhs->e36 + lhs->e46 * rhs->e237 
             + lhs->e237 * rhs->e46 + lhs->e27 * rhs->e346 + lhs->e346 * rhs->e27 
             + lhs->e37 * rhs->e246 + lhs->e246 * rhs->e37 + lhs->e47 * rhs->e236 
             + lhs->e236 * rhs->e47 + lhs->e67 * rhs->e234 + lhs->e234 * rhs->e67;
  res.e12567 =  + lhs->e1 * rhs->e2567 + lhs->e2567 * rhs->e1 + lhs->e2 * rhs->e1567 
             + lhs->e1567 * rhs->e2 + lhs->e5 * rhs->e1267 + lhs->e1267 * rhs->e5 
             + lhs->e6 * rhs->e1257 + lhs->e1257 * rhs->e6 + lhs->e7 * rhs->e1256 
             + lhs->e1256 * rhs->e7 + lhs->e12 * rhs->e567 + lhs->e567 * rhs->e12 
             + lhs->e15 * rhs->e267 + lhs->e267 * rhs->e15 + lhs->e25 * rhs->e167 
             + lhs->e167 * rhs->e25 + lhs->e16 * rhs->e257 + lhs->e257 * rhs->e16 
             + lhs->e26 * rhs->e157 + lhs->e157 * rhs->e26 + lhs->e56 * rhs->e127 
             + lhs->e127 * rhs->e56 + lhs->e17 * rhs->e256 + lhs->e256 * rhs->e17 
             + lhs->e27 * rhs->e156 + lhs->e156 * rhs->e27 + lhs->e57 * rhs->e126 
             + lhs->e126 * rhs->e57 + lhs->e67 * rhs->e125 + lhs->e125 * rhs->e67;
  res.e13567 =  + lhs->e1 * rhs->e3567 + lhs->e3567 * rhs->e1 + lhs->e3 * rhs->e1567 
             + lhs->e1567 * rhs->e3 + lhs->e5 * rhs->e1367 + lhs->e1367 * rhs->e5 
             + lhs->e6 * rhs->e1357 + lhs->e1357 * rhs->e6 + lhs->e7 * rhs->e1356 
             + lhs->e1356 * rhs->e7 + lhs->e13 * rhs->e567 + lhs->e567 * rhs->e13 
             + lhs->e15 * rhs->e367 + lhs->e367 * rhs->e15 + lhs->e35 * rhs->e167 
             + lhs->e167 * rhs->e35 + lhs->e16 * rhs->e357 + lhs->e357 * rhs->e16 
             + lhs->e36 * rhs->e157 + lhs->e157 * rhs->e36 + lhs->e56 * rhs->e137 
             + lhs->e137 * rhs->e56 + lhs->e17 * rhs->e356 + lhs->e356 * rhs->e17 
             + lhs->e37 * rhs->e156 + lhs->e156 * rhs->e37 + lhs->e57 * rhs->e136 
             + lhs->e136 * rhs->e57 + lhs->e67 * rhs->e135 + lhs->e135 * rhs->e67;
  res.e23567 =  + lhs->e2 * rhs->e3567 + lhs->e3567 * rhs->e2 + lhs->e3 * rhs->e2567 
             + lhs->e2567 * rhs->e3 + lhs->e5 * rhs->e2367 + lhs->e2367 * rhs->e5 
             + lhs->e6 * rhs->e2357 + lhs->e2357 * rhs->e6 + lhs->e7 * rhs->e2356 
             + lhs->e2356 * rhs->e7 + lhs->e23 * rhs->e567 + lhs->e567 * rhs->e23 
             + lhs->e25 * rhs->e367 + lhs->e367 * rhs->e25 + lhs->e35 * rhs->e267 
             + lhs->e267 * rhs->e35 + lhs->e26 * rhs->e357 + lhs->e357 * rhs->e26 
             + lhs->e36 * rhs->e257 + lhs->e257 * rhs->e36 + lhs->e56 * rhs->e237 
             + lhs->e237 * rhs->e56 + lhs->e27 * rhs->e356 + lhs->e356 * rhs->e27 
             + lhs->e37 * rhs->e256 + lhs->e256 * rhs->e37 + lhs->e57 * rhs->e236 
             + lhs->e236 * rhs->e57 + lhs->e67 * rhs->e235 + lhs->e235 * rhs->e67;
  res.e14567 =  + lhs->e1 * rhs->e4567 + lhs->e4567 * rhs->e1 + lhs->e4 * rhs->e1567 
             + lhs->e1567 * rhs->e4 + lhs->e5 * rhs->e1467 + lhs->e1467 * rhs->e5 
             + lhs->e6 * rhs->e1457 + lhs->e1457 * rhs->e6 + lhs->e7 * rhs->e1456 
             + lhs->e1456 * rhs->e7 + lhs->e14 * rhs->e567 + lhs->e567 * rhs->e14 
             + lhs->e15 * rhs->e467 + lhs->e467 * rhs->e15 + lhs->e45 * rhs->e167 
             + lhs->e167 * rhs->e45 + lhs->e16 * rhs->e457 + lhs->e457 * rhs->e16 
             + lhs->e46 * rhs->e157 + lhs->e157 * rhs->e46 + lhs->e56 * rhs->e147 
             + lhs->e147 * rhs->e56 + lhs->e17 * rhs->e456 + lhs->e456 * rhs->e17 
             + lhs->e47 * rhs->e156 + lhs->e156 * rhs->e47 + lhs->e57 * rhs->e146 
             + lhs->e146 * rhs->e57 + lhs->e67 * rhs->e145 + lhs->e145 * rhs->e67;
  res.e24567 =  + lhs->e2 * rhs->e4567 + lhs->e4567 * rhs->e2 + lhs->e4 * rhs->e2567 
             + lhs->e2567 * rhs->e4 + lhs->e5 * rhs->e2467 + lhs->e2467 * rhs->e5 
             + lhs->e6 * rhs->e2457 + lhs->e2457 * rhs->e6 + lhs->e7 * rhs->e2456 
             + lhs->e2456 * rhs->e7 + lhs->e24 * rhs->e567 + lhs->e567 * rhs->e24 
             + lhs->e25 * rhs->e467 + lhs->e467 * rhs->e25 + lhs->e45 * rhs->e267 
             + lhs->e267 * rhs->e45 + lhs->e26 * rhs->e457 + lhs->e457 * rhs->e26 
             + lhs->e46 * rhs->e257 + lhs->e257 * rhs->e46 + lhs->e56 * rhs->e247 
             + lhs->e247 * rhs->e56 + lhs->e27 * rhs->e456 + lhs->e456 * rhs->e27 
             + lhs->e47 * rhs->e256 + lhs->e256 * rhs->e47 + lhs->e57 * rhs->e246 
             + lhs->e246 * rhs->e57 + lhs->e67 * rhs->e245 + lhs->e245 * rhs->e67;
  res.e34567 =  + lhs->e3 * rhs->e4567 + lhs->e4567 * rhs->e3 + lhs->e4 * rhs->e3567 
             + lhs->e3567 * rhs->e4 + lhs->e5 * rhs->e3467 + lhs->e3467 * rhs->e5 
             + lhs->e6 * rhs->e3457 + lhs->e3457 * rhs->e6 + lhs->e7 * rhs->e3456 
             + lhs->e3456 * rhs->e7 + lhs->e34 * rhs->e567 + lhs->e567 * rhs->e34 
             + lhs->e35 * rhs->e467 + lhs->e467 * rhs->e35 + lhs->e45 * rhs->e367 
             + lhs->e367 * rhs->e45 + lhs->e36 * rhs->e457 + lhs->e457 * rhs->e36 
             + lhs->e46 * rhs->e357 + lhs->e357 * rhs->e46 + lhs->e56 * rhs->e347 
             + lhs->e347 * rhs->e56 + lhs->e37 * rhs->e456 + lhs->e456 * rhs->e37 
             + lhs->e47 * rhs->e356 + lhs->e356 * rhs->e47 + lhs->e57 * rhs->e346 
             + lhs->e346 * rhs->e57 + lhs->e67 * rhs->e345 + lhs->e345 * rhs->e67;
  // Order 6;
  res.e123456 =  + lhs->e1 * rhs->e23456 + lhs->e23456 * rhs->e1 + lhs->e2 * rhs->e13456 
              + lhs->e13456 * rhs->e2 + lhs->e3 * rhs->e12456 + lhs->e12456 * rhs->e3 
              + lhs->e4 * rhs->e12356 + lhs->e12356 * rhs->e4 + lhs->e5 * rhs->e12346 
              + lhs->e12346 * rhs->e5 + lhs->e6 * rhs->e12345 + lhs->e12345 * rhs->e6 
              + lhs->e12 * rhs->e3456 + lhs->e3456 * rhs->e12 + lhs->e13 * rhs->e2456 
              + lhs->e2456 * rhs->e13 + lhs->e23 * rhs->e1456 + lhs->e1456 * rhs->e23 
              + lhs->e14 * rhs->e2356 + lhs->e2356 * rhs->e14 + lhs->e24 * rhs->e1356 
              + lhs->e1356 * rhs->e24 + lhs->e34 * rhs->e1256 + lhs->e1256 * rhs->e34 
              + lhs->e15 * rhs->e2346 + lhs->e2346 * rhs->e15 + lhs->e25 * rhs->e1346 
              + lhs->e1346 * rhs->e25 + lhs->e35 * rhs->e1246 + lhs->e1246 * rhs->e35 
              + lhs->e45 * rhs->e1236 + lhs->e1236 * rhs->e45 + lhs->e16 * rhs->e2345 
              + lhs->e2345 * rhs->e16 + lhs->e26 * rhs->e1345 + lhs->e1345 * rhs->e26 
              + lhs->e36 * rhs->e1245 + lhs->e1245 * rhs->e36 + lhs->e46 * rhs->e1235 
              + lhs->e1235 * rhs->e46 + lhs->e56 * rhs->e1234 + lhs->e1234 * rhs->e56 
              + lhs->e123 * rhs->e456 + lhs->e124 * rhs->e356 + lhs->e134 * rhs->e256 
              + lhs->e234 * rhs->e156 + lhs->e125 * rhs->e346 + lhs->e135 * rhs->e246 
              + lhs->e235 * rhs->e146 + lhs->e145 * rhs->e236 + lhs->e245 * rhs->e136 
              + lhs->e345 * rhs->e126 + lhs->e126 * rhs->e345 + lhs->e136 * rhs->e245 
              + lhs->e236 * rhs->e145 + lhs->e146 * rhs->e235 + lhs->e246 * rhs->e135 
              + lhs->e346 * rhs->e125 + lhs->e156 * rhs->e234 + lhs->e256 * rhs->e134 
              + lhs->e356 * rhs->e124 + lhs->e456 * rhs->e123;
  res.e123457 =  + lhs->e1 * rhs->e23457 + lhs->e23457 * rhs->e1 + lhs->e2 * rhs->e13457 
              + lhs->e13457 * rhs->e2 + lhs->e3 * rhs->e12457 + lhs->e12457 * rhs->e3 
              + lhs->e4 * rhs->e12357 + lhs->e12357 * rhs->e4 + lhs->e5 * rhs->e12347 
              + lhs->e12347 * rhs->e5 + lhs->e7 * rhs->e12345 + lhs->e12345 * rhs->e7 
              + lhs->e12 * rhs->e3457 + lhs->e3457 * rhs->e12 + lhs->e13 * rhs->e2457 
              + lhs->e2457 * rhs->e13 + lhs->e23 * rhs->e1457 + lhs->e1457 * rhs->e23 
              + lhs->e14 * rhs->e2357 + lhs->e2357 * rhs->e14 + lhs->e24 * rhs->e1357 
              + lhs->e1357 * rhs->e24 + lhs->e34 * rhs->e1257 + lhs->e1257 * rhs->e34 
              + lhs->e15 * rhs->e2347 + lhs->e2347 * rhs->e15 + lhs->e25 * rhs->e1347 
              + lhs->e1347 * rhs->e25 + lhs->e35 * rhs->e1247 + lhs->e1247 * rhs->e35 
              + lhs->e45 * rhs->e1237 + lhs->e1237 * rhs->e45 + lhs->e17 * rhs->e2345 
              + lhs->e2345 * rhs->e17 + lhs->e27 * rhs->e1345 + lhs->e1345 * rhs->e27 
              + lhs->e37 * rhs->e1245 + lhs->e1245 * rhs->e37 + lhs->e47 * rhs->e1235 
              + lhs->e1235 * rhs->e47 + lhs->e57 * rhs->e1234 + lhs->e1234 * rhs->e57 
              + lhs->e123 * rhs->e457 + lhs->e124 * rhs->e357 + lhs->e134 * rhs->e257 
              + lhs->e234 * rhs->e157 + lhs->e125 * rhs->e347 + lhs->e135 * rhs->e247 
              + lhs->e235 * rhs->e147 + lhs->e145 * rhs->e237 + lhs->e245 * rhs->e137 
              + lhs->e345 * rhs->e127 + lhs->e127 * rhs->e345 + lhs->e137 * rhs->e245 
              + lhs->e237 * rhs->e145 + lhs->e147 * rhs->e235 + lhs->e247 * rhs->e135 
              + lhs->e347 * rhs->e125 + lhs->e157 * rhs->e234 + lhs->e257 * rhs->e134 
              + lhs->e357 * rhs->e124 + lhs->e457 * rhs->e123;
  res.e123467 =  + lhs->e1 * rhs->e23467 + lhs->e23467 * rhs->e1 + lhs->e2 * rhs->e13467 
              + lhs->e13467 * rhs->e2 + lhs->e3 * rhs->e12467 + lhs->e12467 * rhs->e3 
              + lhs->e4 * rhs->e12367 + lhs->e12367 * rhs->e4 + lhs->e6 * rhs->e12347 
              + lhs->e12347 * rhs->e6 + lhs->e7 * rhs->e12346 + lhs->e12346 * rhs->e7 
              + lhs->e12 * rhs->e3467 + lhs->e3467 * rhs->e12 + lhs->e13 * rhs->e2467 
              + lhs->e2467 * rhs->e13 + lhs->e23 * rhs->e1467 + lhs->e1467 * rhs->e23 
              + lhs->e14 * rhs->e2367 + lhs->e2367 * rhs->e14 + lhs->e24 * rhs->e1367 
              + lhs->e1367 * rhs->e24 + lhs->e34 * rhs->e1267 + lhs->e1267 * rhs->e34 
              + lhs->e16 * rhs->e2347 + lhs->e2347 * rhs->e16 + lhs->e26 * rhs->e1347 
              + lhs->e1347 * rhs->e26 + lhs->e36 * rhs->e1247 + lhs->e1247 * rhs->e36 
              + lhs->e46 * rhs->e1237 + lhs->e1237 * rhs->e46 + lhs->e17 * rhs->e2346 
              + lhs->e2346 * rhs->e17 + lhs->e27 * rhs->e1346 + lhs->e1346 * rhs->e27 
              + lhs->e37 * rhs->e1246 + lhs->e1246 * rhs->e37 + lhs->e47 * rhs->e1236 
              + lhs->e1236 * rhs->e47 + lhs->e67 * rhs->e1234 + lhs->e1234 * rhs->e67 
              + lhs->e123 * rhs->e467 + lhs->e124 * rhs->e367 + lhs->e134 * rhs->e267 
              + lhs->e234 * rhs->e167 + lhs->e126 * rhs->e347 + lhs->e136 * rhs->e247 
              + lhs->e236 * rhs->e147 + lhs->e146 * rhs->e237 + lhs->e246 * rhs->e137 
              + lhs->e346 * rhs->e127 + lhs->e127 * rhs->e346 + lhs->e137 * rhs->e246 
              + lhs->e237 * rhs->e146 + lhs->e147 * rhs->e236 + lhs->e247 * rhs->e136 
              + lhs->e347 * rhs->e126 + lhs->e167 * rhs->e234 + lhs->e267 * rhs->e134 
              + lhs->e367 * rhs->e124 + lhs->e467 * rhs->e123;
  res.e123567 =  + lhs->e1 * rhs->e23567 + lhs->e23567 * rhs->e1 + lhs->e2 * rhs->e13567 
              + lhs->e13567 * rhs->e2 + lhs->e3 * rhs->e12567 + lhs->e12567 * rhs->e3 
              + lhs->e5 * rhs->e12367 + lhs->e12367 * rhs->e5 + lhs->e6 * rhs->e12357 
              + lhs->e12357 * rhs->e6 + lhs->e7 * rhs->e12356 + lhs->e12356 * rhs->e7 
              + lhs->e12 * rhs->e3567 + lhs->e3567 * rhs->e12 + lhs->e13 * rhs->e2567 
              + lhs->e2567 * rhs->e13 + lhs->e23 * rhs->e1567 + lhs->e1567 * rhs->e23 
              + lhs->e15 * rhs->e2367 + lhs->e2367 * rhs->e15 + lhs->e25 * rhs->e1367 
              + lhs->e1367 * rhs->e25 + lhs->e35 * rhs->e1267 + lhs->e1267 * rhs->e35 
              + lhs->e16 * rhs->e2357 + lhs->e2357 * rhs->e16 + lhs->e26 * rhs->e1357 
              + lhs->e1357 * rhs->e26 + lhs->e36 * rhs->e1257 + lhs->e1257 * rhs->e36 
              + lhs->e56 * rhs->e1237 + lhs->e1237 * rhs->e56 + lhs->e17 * rhs->e2356 
              + lhs->e2356 * rhs->e17 + lhs->e27 * rhs->e1356 + lhs->e1356 * rhs->e27 
              + lhs->e37 * rhs->e1256 + lhs->e1256 * rhs->e37 + lhs->e57 * rhs->e1236 
              + lhs->e1236 * rhs->e57 + lhs->e67 * rhs->e1235 + lhs->e1235 * rhs->e67 
              + lhs->e123 * rhs->e567 + lhs->e125 * rhs->e367 + lhs->e135 * rhs->e267 
              + lhs->e235 * rhs->e167 + lhs->e126 * rhs->e357 + lhs->e136 * rhs->e257 
              + lhs->e236 * rhs->e157 + lhs->e156 * rhs->e237 + lhs->e256 * rhs->e137 
              + lhs->e356 * rhs->e127 + lhs->e127 * rhs->e356 + lhs->e137 * rhs->e256 
              + lhs->e237 * rhs->e156 + lhs->e157 * rhs->e236 + lhs->e257 * rhs->e136 
              + lhs->e357 * rhs->e126 + lhs->e167 * rhs->e235 + lhs->e267 * rhs->e135 
              + lhs->e367 * rhs->e125 + lhs->e567 * rhs->e123;
  res.e124567 =  + lhs->e1 * rhs->e24567 + lhs->e24567 * rhs->e1 + lhs->e2 * rhs->e14567 
              + lhs->e14567 * rhs->e2 + lhs->e4 * rhs->e12567 + lhs->e12567 * rhs->e4 
              + lhs->e5 * rhs->e12467 + lhs->e12467 * rhs->e5 + lhs->e6 * rhs->e12457 
              + lhs->e12457 * rhs->e6 + lhs->e7 * rhs->e12456 + lhs->e12456 * rhs->e7 
              + lhs->e12 * rhs->e4567 + lhs->e4567 * rhs->e12 + lhs->e14 * rhs->e2567 
              + lhs->e2567 * rhs->e14 + lhs->e24 * rhs->e1567 + lhs->e1567 * rhs->e24 
              + lhs->e15 * rhs->e2467 + lhs->e2467 * rhs->e15 + lhs->e25 * rhs->e1467 
              + lhs->e1467 * rhs->e25 + lhs->e45 * rhs->e1267 + lhs->e1267 * rhs->e45 
              + lhs->e16 * rhs->e2457 + lhs->e2457 * rhs->e16 + lhs->e26 * rhs->e1457 
              + lhs->e1457 * rhs->e26 + lhs->e46 * rhs->e1257 + lhs->e1257 * rhs->e46 
              + lhs->e56 * rhs->e1247 + lhs->e1247 * rhs->e56 + lhs->e17 * rhs->e2456 
              + lhs->e2456 * rhs->e17 + lhs->e27 * rhs->e1456 + lhs->e1456 * rhs->e27 
              + lhs->e47 * rhs->e1256 + lhs->e1256 * rhs->e47 + lhs->e57 * rhs->e1246 
              + lhs->e1246 * rhs->e57 + lhs->e67 * rhs->e1245 + lhs->e1245 * rhs->e67 
              + lhs->e124 * rhs->e567 + lhs->e125 * rhs->e467 + lhs->e145 * rhs->e267 
              + lhs->e245 * rhs->e167 + lhs->e126 * rhs->e457 + lhs->e146 * rhs->e257 
              + lhs->e246 * rhs->e157 + lhs->e156 * rhs->e247 + lhs->e256 * rhs->e147 
              + lhs->e456 * rhs->e127 + lhs->e127 * rhs->e456 + lhs->e147 * rhs->e256 
              + lhs->e247 * rhs->e156 + lhs->e157 * rhs->e246 + lhs->e257 * rhs->e146 
              + lhs->e457 * rhs->e126 + lhs->e167 * rhs->e245 + lhs->e267 * rhs->e145 
              + lhs->e467 * rhs->e125 + lhs->e567 * rhs->e124;
  res.e134567 =  + lhs->e1 * rhs->e34567 + lhs->e34567 * rhs->e1 + lhs->e3 * rhs->e14567 
              + lhs->e14567 * rhs->e3 + lhs->e4 * rhs->e13567 + lhs->e13567 * rhs->e4 
              + lhs->e5 * rhs->e13467 + lhs->e13467 * rhs->e5 + lhs->e6 * rhs->e13457 
              + lhs->e13457 * rhs->e6 + lhs->e7 * rhs->e13456 + lhs->e13456 * rhs->e7 
              + lhs->e13 * rhs->e4567 + lhs->e4567 * rhs->e13 + lhs->e14 * rhs->e3567 
              + lhs->e3567 * rhs->e14 + lhs->e34 * rhs->e1567 + lhs->e1567 * rhs->e34 
              + lhs->e15 * rhs->e3467 + lhs->e3467 * rhs->e15 + lhs->e35 * rhs->e1467 
              + lhs->e1467 * rhs->e35 + lhs->e45 * rhs->e1367 + lhs->e1367 * rhs->e45 
              + lhs->e16 * rhs->e3457 + lhs->e3457 * rhs->e16 + lhs->e36 * rhs->e1457 
              + lhs->e1457 * rhs->e36 + lhs->e46 * rhs->e1357 + lhs->e1357 * rhs->e46 
              + lhs->e56 * rhs->e1347 + lhs->e1347 * rhs->e56 + lhs->e17 * rhs->e3456 
              + lhs->e3456 * rhs->e17 + lhs->e37 * rhs->e1456 + lhs->e1456 * rhs->e37 
              + lhs->e47 * rhs->e1356 + lhs->e1356 * rhs->e47 + lhs->e57 * rhs->e1346 
              + lhs->e1346 * rhs->e57 + lhs->e67 * rhs->e1345 + lhs->e1345 * rhs->e67 
              + lhs->e134 * rhs->e567 + lhs->e135 * rhs->e467 + lhs->e145 * rhs->e367 
              + lhs->e345 * rhs->e167 + lhs->e136 * rhs->e457 + lhs->e146 * rhs->e357 
              + lhs->e346 * rhs->e157 + lhs->e156 * rhs->e347 + lhs->e356 * rhs->e147 
              + lhs->e456 * rhs->e137 + lhs->e137 * rhs->e456 + lhs->e147 * rhs->e356 
              + lhs->e347 * rhs->e156 + lhs->e157 * rhs->e346 + lhs->e357 * rhs->e146 
              + lhs->e457 * rhs->e136 + lhs->e167 * rhs->e345 + lhs->e367 * rhs->e145 
              + lhs->e467 * rhs->e135 + lhs->e567 * rhs->e134;
  res.e234567 =  + lhs->e2 * rhs->e34567 + lhs->e34567 * rhs->e2 + lhs->e3 * rhs->e24567 
              + lhs->e24567 * rhs->e3 + lhs->e4 * rhs->e23567 + lhs->e23567 * rhs->e4 
              + lhs->e5 * rhs->e23467 + lhs->e23467 * rhs->e5 + lhs->e6 * rhs->e23457 
              + lhs->e23457 * rhs->e6 + lhs->e7 * rhs->e23456 + lhs->e23456 * rhs->e7 
              + lhs->e23 * rhs->e4567 + lhs->e4567 * rhs->e23 + lhs->e24 * rhs->e3567 
              + lhs->e3567 * rhs->e24 + lhs->e34 * rhs->e2567 + lhs->e2567 * rhs->e34 
              + lhs->e25 * rhs->e3467 + lhs->e3467 * rhs->e25 + lhs->e35 * rhs->e2467 
              + lhs->e2467 * rhs->e35 + lhs->e45 * rhs->e2367 + lhs->e2367 * rhs->e45 
              + lhs->e26 * rhs->e3457 + lhs->e3457 * rhs->e26 + lhs->e36 * rhs->e2457 
              + lhs->e2457 * rhs->e36 + lhs->e46 * rhs->e2357 + lhs->e2357 * rhs->e46 
              + lhs->e56 * rhs->e2347 + lhs->e2347 * rhs->e56 + lhs->e27 * rhs->e3456 
              + lhs->e3456 * rhs->e27 + lhs->e37 * rhs->e2456 + lhs->e2456 * rhs->e37 
              + lhs->e47 * rhs->e2356 + lhs->e2356 * rhs->e47 + lhs->e57 * rhs->e2346 
              + lhs->e2346 * rhs->e57 + lhs->e67 * rhs->e2345 + lhs->e2345 * rhs->e67 
              + lhs->e234 * rhs->e567 + lhs->e235 * rhs->e467 + lhs->e245 * rhs->e367 
              + lhs->e345 * rhs->e267 + lhs->e236 * rhs->e457 + lhs->e246 * rhs->e357 
              + lhs->e346 * rhs->e257 + lhs->e256 * rhs->e347 + lhs->e356 * rhs->e247 
              + lhs->e456 * rhs->e237 + lhs->e237 * rhs->e456 + lhs->e247 * rhs->e356 
              + lhs->e347 * rhs->e256 + lhs->e257 * rhs->e346 + lhs->e357 * rhs->e246 
              + lhs->e457 * rhs->e236 + lhs->e267 * rhs->e345 + lhs->e367 * rhs->e245 
              + lhs->e467 * rhs->e235 + lhs->e567 * rhs->e234;
  // Order 7;
  res.e1234567 =  + lhs->e1 * rhs->e234567 + lhs->e234567 * rhs->e1 + lhs->e2 * rhs->e134567 
               + lhs->e134567 * rhs->e2 + lhs->e3 * rhs->e124567 + lhs->e124567 * rhs->e3 
               + lhs->e4 * rhs->e123567 + lhs->e123567 * rhs->e4 + lhs->e5 * rhs->e123467 
               + lhs->e123467 * rhs->e5 + lhs->e6 * rhs->e123457 + lhs->e123457 * rhs->e6 
               + lhs->e7 * rhs->e123456 + lhs->e123456 * rhs->e7 + lhs->e12 * rhs->e34567 
               + lhs->e34567 * rhs->e12 + lhs->e13 * rhs->e24567 + lhs->e24567 * rhs->e13 
               + lhs->e23 * rhs->e14567 + lhs->e14567 * rhs->e23 + lhs->e14 * rhs->e23567 
               + lhs->e23567 * rhs->e14 + lhs->e24 * rhs->e13567 + lhs->e13567 * rhs->e24 
               + lhs->e34 * rhs->e12567 + lhs->e12567 * rhs->e34 + lhs->e15 * rhs->e23467 
               + lhs->e23467 * rhs->e15 + lhs->e25 * rhs->e13467 + lhs->e13467 * rhs->e25 
               + lhs->e35 * rhs->e12467 + lhs->e12467 * rhs->e35 + lhs->e45 * rhs->e12367 
               + lhs->e12367 * rhs->e45 + lhs->e16 * rhs->e23457 + lhs->e23457 * rhs->e16 
               + lhs->e26 * rhs->e13457 + lhs->e13457 * rhs->e26 + lhs->e36 * rhs->e12457 
               + lhs->e12457 * rhs->e36 + lhs->e46 * rhs->e12357 + lhs->e12357 * rhs->e46 
               + lhs->e56 * rhs->e12347 + lhs->e12347 * rhs->e56 + lhs->e17 * rhs->e23456 
               + lhs->e23456 * rhs->e17 + lhs->e27 * rhs->e13456 + lhs->e13456 * rhs->e27 
               + lhs->e37 * rhs->e12456 + lhs->e12456 * rhs->e37 + lhs->e47 * rhs->e12356 
               + lhs->e12356 * rhs->e47 + lhs->e57 * rhs->e12346 + lhs->e12346 * rhs->e57 
               + lhs->e67 * rhs->e12345 + lhs->e12345 * rhs->e67 + lhs->e123 * rhs->e4567 
               + lhs->e4567 * rhs->e123 + lhs->e124 * rhs->e3567 + lhs->e3567 * rhs->e124 
               + lhs->e134 * rhs->e2567 + lhs->e2567 * rhs->e134 + lhs->e234 * rhs->e1567 
               + lhs->e1567 * rhs->e234 + lhs->e125 * rhs->e3467 + lhs->e3467 * rhs->e125 
               + lhs->e135 * rhs->e2467 + lhs->e2467 * rhs->e135 + lhs->e235 * rhs->e1467 
               + lhs->e1467 * rhs->e235 + lhs->e145 * rhs->e2367 + lhs->e2367 * rhs->e145 
               + lhs->e245 * rhs->e1367 + lhs->e1367 * rhs->e245 + lhs->e345 * rhs->e1267 
               + lhs->e1267 * rhs->e345 + lhs->e126 * rhs->e3457 + lhs->e3457 * rhs->e126 
               + lhs->e136 * rhs->e2457 + lhs->e2457 * rhs->e136 + lhs->e236 * rhs->e1457 
               + lhs->e1457 * rhs->e236 + lhs->e146 * rhs->e2357 + lhs->e2357 * rhs->e146 
               + lhs->e246 * rhs->e1357 + lhs->e1357 * rhs->e246 + lhs->e346 * rhs->e1257 
               + lhs->e1257 * rhs->e346 + lhs->e156 * rhs->e2347 + lhs->e2347 * rhs->e156 
               + lhs->e256 * rhs->e1347 + lhs->e1347 * rhs->e256 + lhs->e356 * rhs->e1247 
               + lhs->e1247 * rhs->e356 + lhs->e456 * rhs->e1237 + lhs->e1237 * rhs->e456 
               + lhs->e127 * rhs->e3456 + lhs->e3456 * rhs->e127 + lhs->e137 * rhs->e2456 
               + lhs->e2456 * rhs->e137 + lhs->e237 * rhs->e1456 + lhs->e1456 * rhs->e237 
               + lhs->e147 * rhs->e2356 + lhs->e2356 * rhs->e147 + lhs->e247 * rhs->e1356 
               + lhs->e1356 * rhs->e247 + lhs->e347 * rhs->e1256 + lhs->e1256 * rhs->e347 
               + lhs->e157 * rhs->e2346 + lhs->e2346 * rhs->e157 + lhs->e257 * rhs->e1346 
               + lhs->e1346 * rhs->e257 + lhs->e357 * rhs->e1246 + lhs->e1246 * rhs->e357 
               + lhs->e457 * rhs->e1236 + lhs->e1236 * rhs->e457 + lhs->e167 * rhs->e2345 
               + lhs->e2345 * rhs->e167 + lhs->e267 * rhs->e1345 + lhs->e1345 * rhs->e267 
               + lhs->e367 * rhs->e1245 + lhs->e1245 * rhs->e367 + lhs->e467 * rhs->e1235 
               + lhs->e1235 * rhs->e467 + lhs->e567 * rhs->e1234 + lhs->e1234 * rhs->e567;

  return res;

}

void mdnum7_trunc_mul_oo_to(  mdnum7_t* lhs,  mdnum7_t* rhs, mdnum7_t* res){
   (*res) = mdnum7_init();

  //  Truncated multiplication like function 'lhs * rhs'
  // Order 2;
  res->e12 =  + lhs->e1 * rhs->e2 + lhs->e2 * rhs->e1;
  res->e13 =  + lhs->e1 * rhs->e3 + lhs->e3 * rhs->e1;
  res->e23 =  + lhs->e2 * rhs->e3 + lhs->e3 * rhs->e2;
  res->e14 =  + lhs->e1 * rhs->e4 + lhs->e4 * rhs->e1;
  res->e24 =  + lhs->e2 * rhs->e4 + lhs->e4 * rhs->e2;
  res->e34 =  + lhs->e3 * rhs->e4 + lhs->e4 * rhs->e3;
  res->e15 =  + lhs->e1 * rhs->e5 + lhs->e5 * rhs->e1;
  res->e25 =  + lhs->e2 * rhs->e5 + lhs->e5 * rhs->e2;
  res->e35 =  + lhs->e3 * rhs->e5 + lhs->e5 * rhs->e3;
  res->e45 =  + lhs->e4 * rhs->e5 + lhs->e5 * rhs->e4;
  res->e16 =  + lhs->e1 * rhs->e6 + lhs->e6 * rhs->e1;
  res->e26 =  + lhs->e2 * rhs->e6 + lhs->e6 * rhs->e2;
  res->e36 =  + lhs->e3 * rhs->e6 + lhs->e6 * rhs->e3;
  res->e46 =  + lhs->e4 * rhs->e6 + lhs->e6 * rhs->e4;
  res->e56 =  + lhs->e5 * rhs->e6 + lhs->e6 * rhs->e5;
  res->e17 =  + lhs->e1 * rhs->e7 + lhs->e7 * rhs->e1;
  res->e27 =  + lhs->e2 * rhs->e7 + lhs->e7 * rhs->e2;
  res->e37 =  + lhs->e3 * rhs->e7 + lhs->e7 * rhs->e3;
  res->e47 =  + lhs->e4 * rhs->e7 + lhs->e7 * rhs->e4;
  res->e57 =  + lhs->e5 * rhs->e7 + lhs->e7 * rhs->e5;
  res->e67 =  + lhs->e6 * rhs->e7 + lhs->e7 * rhs->e6;
  // Order 3;
  res->e123 =  + lhs->e1 * rhs->e23 + lhs->e23 * rhs->e1 + lhs->e2 * rhs->e13 
           + lhs->e13 * rhs->e2 + lhs->e3 * rhs->e12 + lhs->e12 * rhs->e3;
  res->e124 =  + lhs->e1 * rhs->e24 + lhs->e24 * rhs->e1 + lhs->e2 * rhs->e14 
           + lhs->e14 * rhs->e2 + lhs->e4 * rhs->e12 + lhs->e12 * rhs->e4;
  res->e134 =  + lhs->e1 * rhs->e34 + lhs->e34 * rhs->e1 + lhs->e3 * rhs->e14 
           + lhs->e14 * rhs->e3 + lhs->e4 * rhs->e13 + lhs->e13 * rhs->e4;
  res->e234 =  + lhs->e2 * rhs->e34 + lhs->e34 * rhs->e2 + lhs->e3 * rhs->e24 
           + lhs->e24 * rhs->e3 + lhs->e4 * rhs->e23 + lhs->e23 * rhs->e4;
  res->e125 =  + lhs->e1 * rhs->e25 + lhs->e25 * rhs->e1 + lhs->e2 * rhs->e15 
           + lhs->e15 * rhs->e2 + lhs->e5 * rhs->e12 + lhs->e12 * rhs->e5;
  res->e135 =  + lhs->e1 * rhs->e35 + lhs->e35 * rhs->e1 + lhs->e3 * rhs->e15 
           + lhs->e15 * rhs->e3 + lhs->e5 * rhs->e13 + lhs->e13 * rhs->e5;
  res->e235 =  + lhs->e2 * rhs->e35 + lhs->e35 * rhs->e2 + lhs->e3 * rhs->e25 
           + lhs->e25 * rhs->e3 + lhs->e5 * rhs->e23 + lhs->e23 * rhs->e5;
  res->e145 =  + lhs->e1 * rhs->e45 + lhs->e45 * rhs->e1 + lhs->e4 * rhs->e15 
           + lhs->e15 * rhs->e4 + lhs->e5 * rhs->e14 + lhs->e14 * rhs->e5;
  res->e245 =  + lhs->e2 * rhs->e45 + lhs->e45 * rhs->e2 + lhs->e4 * rhs->e25 
           + lhs->e25 * rhs->e4 + lhs->e5 * rhs->e24 + lhs->e24 * rhs->e5;
  res->e345 =  + lhs->e3 * rhs->e45 + lhs->e45 * rhs->e3 + lhs->e4 * rhs->e35 
           + lhs->e35 * rhs->e4 + lhs->e5 * rhs->e34 + lhs->e34 * rhs->e5;
  res->e126 =  + lhs->e1 * rhs->e26 + lhs->e26 * rhs->e1 + lhs->e2 * rhs->e16 
           + lhs->e16 * rhs->e2 + lhs->e6 * rhs->e12 + lhs->e12 * rhs->e6;
  res->e136 =  + lhs->e1 * rhs->e36 + lhs->e36 * rhs->e1 + lhs->e3 * rhs->e16 
           + lhs->e16 * rhs->e3 + lhs->e6 * rhs->e13 + lhs->e13 * rhs->e6;
  res->e236 =  + lhs->e2 * rhs->e36 + lhs->e36 * rhs->e2 + lhs->e3 * rhs->e26 
           + lhs->e26 * rhs->e3 + lhs->e6 * rhs->e23 + lhs->e23 * rhs->e6;
  res->e146 =  + lhs->e1 * rhs->e46 + lhs->e46 * rhs->e1 + lhs->e4 * rhs->e16 
           + lhs->e16 * rhs->e4 + lhs->e6 * rhs->e14 + lhs->e14 * rhs->e6;
  res->e246 =  + lhs->e2 * rhs->e46 + lhs->e46 * rhs->e2 + lhs->e4 * rhs->e26 
           + lhs->e26 * rhs->e4 + lhs->e6 * rhs->e24 + lhs->e24 * rhs->e6;
  res->e346 =  + lhs->e3 * rhs->e46 + lhs->e46 * rhs->e3 + lhs->e4 * rhs->e36 
           + lhs->e36 * rhs->e4 + lhs->e6 * rhs->e34 + lhs->e34 * rhs->e6;
  res->e156 =  + lhs->e1 * rhs->e56 + lhs->e56 * rhs->e1 + lhs->e5 * rhs->e16 
           + lhs->e16 * rhs->e5 + lhs->e6 * rhs->e15 + lhs->e15 * rhs->e6;
  res->e256 =  + lhs->e2 * rhs->e56 + lhs->e56 * rhs->e2 + lhs->e5 * rhs->e26 
           + lhs->e26 * rhs->e5 + lhs->e6 * rhs->e25 + lhs->e25 * rhs->e6;
  res->e356 =  + lhs->e3 * rhs->e56 + lhs->e56 * rhs->e3 + lhs->e5 * rhs->e36 
           + lhs->e36 * rhs->e5 + lhs->e6 * rhs->e35 + lhs->e35 * rhs->e6;
  res->e456 =  + lhs->e4 * rhs->e56 + lhs->e56 * rhs->e4 + lhs->e5 * rhs->e46 
           + lhs->e46 * rhs->e5 + lhs->e6 * rhs->e45 + lhs->e45 * rhs->e6;
  res->e127 =  + lhs->e1 * rhs->e27 + lhs->e27 * rhs->e1 + lhs->e2 * rhs->e17 
           + lhs->e17 * rhs->e2 + lhs->e7 * rhs->e12 + lhs->e12 * rhs->e7;
  res->e137 =  + lhs->e1 * rhs->e37 + lhs->e37 * rhs->e1 + lhs->e3 * rhs->e17 
           + lhs->e17 * rhs->e3 + lhs->e7 * rhs->e13 + lhs->e13 * rhs->e7;
  res->e237 =  + lhs->e2 * rhs->e37 + lhs->e37 * rhs->e2 + lhs->e3 * rhs->e27 
           + lhs->e27 * rhs->e3 + lhs->e7 * rhs->e23 + lhs->e23 * rhs->e7;
  res->e147 =  + lhs->e1 * rhs->e47 + lhs->e47 * rhs->e1 + lhs->e4 * rhs->e17 
           + lhs->e17 * rhs->e4 + lhs->e7 * rhs->e14 + lhs->e14 * rhs->e7;
  res->e247 =  + lhs->e2 * rhs->e47 + lhs->e47 * rhs->e2 + lhs->e4 * rhs->e27 
           + lhs->e27 * rhs->e4 + lhs->e7 * rhs->e24 + lhs->e24 * rhs->e7;
  res->e347 =  + lhs->e3 * rhs->e47 + lhs->e47 * rhs->e3 + lhs->e4 * rhs->e37 
           + lhs->e37 * rhs->e4 + lhs->e7 * rhs->e34 + lhs->e34 * rhs->e7;
  res->e157 =  + lhs->e1 * rhs->e57 + lhs->e57 * rhs->e1 + lhs->e5 * rhs->e17 
           + lhs->e17 * rhs->e5 + lhs->e7 * rhs->e15 + lhs->e15 * rhs->e7;
  res->e257 =  + lhs->e2 * rhs->e57 + lhs->e57 * rhs->e2 + lhs->e5 * rhs->e27 
           + lhs->e27 * rhs->e5 + lhs->e7 * rhs->e25 + lhs->e25 * rhs->e7;
  res->e357 =  + lhs->e3 * rhs->e57 + lhs->e57 * rhs->e3 + lhs->e5 * rhs->e37 
           + lhs->e37 * rhs->e5 + lhs->e7 * rhs->e35 + lhs->e35 * rhs->e7;
  res->e457 =  + lhs->e4 * rhs->e57 + lhs->e57 * rhs->e4 + lhs->e5 * rhs->e47 
           + lhs->e47 * rhs->e5 + lhs->e7 * rhs->e45 + lhs->e45 * rhs->e7;
  res->e167 =  + lhs->e1 * rhs->e67 + lhs->e67 * rhs->e1 + lhs->e6 * rhs->e17 
           + lhs->e17 * rhs->e6 + lhs->e7 * rhs->e16 + lhs->e16 * rhs->e7;
  res->e267 =  + lhs->e2 * rhs->e67 + lhs->e67 * rhs->e2 + lhs->e6 * rhs->e27 
           + lhs->e27 * rhs->e6 + lhs->e7 * rhs->e26 + lhs->e26 * rhs->e7;
  res->e367 =  + lhs->e3 * rhs->e67 + lhs->e67 * rhs->e3 + lhs->e6 * rhs->e37 
           + lhs->e37 * rhs->e6 + lhs->e7 * rhs->e36 + lhs->e36 * rhs->e7;
  res->e467 =  + lhs->e4 * rhs->e67 + lhs->e67 * rhs->e4 + lhs->e6 * rhs->e47 
           + lhs->e47 * rhs->e6 + lhs->e7 * rhs->e46 + lhs->e46 * rhs->e7;
  res->e567 =  + lhs->e5 * rhs->e67 + lhs->e67 * rhs->e5 + lhs->e6 * rhs->e57 
           + lhs->e57 * rhs->e6 + lhs->e7 * rhs->e56 + lhs->e56 * rhs->e7;
  // Order 4;
  res->e1234 =  + lhs->e1 * rhs->e234 + lhs->e234 * rhs->e1 + lhs->e2 * rhs->e134 
            + lhs->e134 * rhs->e2 + lhs->e3 * rhs->e124 + lhs->e124 * rhs->e3 
            + lhs->e4 * rhs->e123 + lhs->e123 * rhs->e4 + lhs->e12 * rhs->e34 
            + lhs->e13 * rhs->e24 + lhs->e23 * rhs->e14 + lhs->e14 * rhs->e23 
            + lhs->e24 * rhs->e13 + lhs->e34 * rhs->e12;
  res->e1235 =  + lhs->e1 * rhs->e235 + lhs->e235 * rhs->e1 + lhs->e2 * rhs->e135 
            + lhs->e135 * rhs->e2 + lhs->e3 * rhs->e125 + lhs->e125 * rhs->e3 
            + lhs->e5 * rhs->e123 + lhs->e123 * rhs->e5 + lhs->e12 * rhs->e35 
            + lhs->e13 * rhs->e25 + lhs->e23 * rhs->e15 + lhs->e15 * rhs->e23 
            + lhs->e25 * rhs->e13 + lhs->e35 * rhs->e12;
  res->e1245 =  + lhs->e1 * rhs->e245 + lhs->e245 * rhs->e1 + lhs->e2 * rhs->e145 
            + lhs->e145 * rhs->e2 + lhs->e4 * rhs->e125 + lhs->e125 * rhs->e4 
            + lhs->e5 * rhs->e124 + lhs->e124 * rhs->e5 + lhs->e12 * rhs->e45 
            + lhs->e14 * rhs->e25 + lhs->e24 * rhs->e15 + lhs->e15 * rhs->e24 
            + lhs->e25 * rhs->e14 + lhs->e45 * rhs->e12;
  res->e1345 =  + lhs->e1 * rhs->e345 + lhs->e345 * rhs->e1 + lhs->e3 * rhs->e145 
            + lhs->e145 * rhs->e3 + lhs->e4 * rhs->e135 + lhs->e135 * rhs->e4 
            + lhs->e5 * rhs->e134 + lhs->e134 * rhs->e5 + lhs->e13 * rhs->e45 
            + lhs->e14 * rhs->e35 + lhs->e34 * rhs->e15 + lhs->e15 * rhs->e34 
            + lhs->e35 * rhs->e14 + lhs->e45 * rhs->e13;
  res->e2345 =  + lhs->e2 * rhs->e345 + lhs->e345 * rhs->e2 + lhs->e3 * rhs->e245 
            + lhs->e245 * rhs->e3 + lhs->e4 * rhs->e235 + lhs->e235 * rhs->e4 
            + lhs->e5 * rhs->e234 + lhs->e234 * rhs->e5 + lhs->e23 * rhs->e45 
            + lhs->e24 * rhs->e35 + lhs->e34 * rhs->e25 + lhs->e25 * rhs->e34 
            + lhs->e35 * rhs->e24 + lhs->e45 * rhs->e23;
  res->e1236 =  + lhs->e1 * rhs->e236 + lhs->e236 * rhs->e1 + lhs->e2 * rhs->e136 
            + lhs->e136 * rhs->e2 + lhs->e3 * rhs->e126 + lhs->e126 * rhs->e3 
            + lhs->e6 * rhs->e123 + lhs->e123 * rhs->e6 + lhs->e12 * rhs->e36 
            + lhs->e13 * rhs->e26 + lhs->e23 * rhs->e16 + lhs->e16 * rhs->e23 
            + lhs->e26 * rhs->e13 + lhs->e36 * rhs->e12;
  res->e1246 =  + lhs->e1 * rhs->e246 + lhs->e246 * rhs->e1 + lhs->e2 * rhs->e146 
            + lhs->e146 * rhs->e2 + lhs->e4 * rhs->e126 + lhs->e126 * rhs->e4 
            + lhs->e6 * rhs->e124 + lhs->e124 * rhs->e6 + lhs->e12 * rhs->e46 
            + lhs->e14 * rhs->e26 + lhs->e24 * rhs->e16 + lhs->e16 * rhs->e24 
            + lhs->e26 * rhs->e14 + lhs->e46 * rhs->e12;
  res->e1346 =  + lhs->e1 * rhs->e346 + lhs->e346 * rhs->e1 + lhs->e3 * rhs->e146 
            + lhs->e146 * rhs->e3 + lhs->e4 * rhs->e136 + lhs->e136 * rhs->e4 
            + lhs->e6 * rhs->e134 + lhs->e134 * rhs->e6 + lhs->e13 * rhs->e46 
            + lhs->e14 * rhs->e36 + lhs->e34 * rhs->e16 + lhs->e16 * rhs->e34 
            + lhs->e36 * rhs->e14 + lhs->e46 * rhs->e13;
  res->e2346 =  + lhs->e2 * rhs->e346 + lhs->e346 * rhs->e2 + lhs->e3 * rhs->e246 
            + lhs->e246 * rhs->e3 + lhs->e4 * rhs->e236 + lhs->e236 * rhs->e4 
            + lhs->e6 * rhs->e234 + lhs->e234 * rhs->e6 + lhs->e23 * rhs->e46 
            + lhs->e24 * rhs->e36 + lhs->e34 * rhs->e26 + lhs->e26 * rhs->e34 
            + lhs->e36 * rhs->e24 + lhs->e46 * rhs->e23;
  res->e1256 =  + lhs->e1 * rhs->e256 + lhs->e256 * rhs->e1 + lhs->e2 * rhs->e156 
            + lhs->e156 * rhs->e2 + lhs->e5 * rhs->e126 + lhs->e126 * rhs->e5 
            + lhs->e6 * rhs->e125 + lhs->e125 * rhs->e6 + lhs->e12 * rhs->e56 
            + lhs->e15 * rhs->e26 + lhs->e25 * rhs->e16 + lhs->e16 * rhs->e25 
            + lhs->e26 * rhs->e15 + lhs->e56 * rhs->e12;
  res->e1356 =  + lhs->e1 * rhs->e356 + lhs->e356 * rhs->e1 + lhs->e3 * rhs->e156 
            + lhs->e156 * rhs->e3 + lhs->e5 * rhs->e136 + lhs->e136 * rhs->e5 
            + lhs->e6 * rhs->e135 + lhs->e135 * rhs->e6 + lhs->e13 * rhs->e56 
            + lhs->e15 * rhs->e36 + lhs->e35 * rhs->e16 + lhs->e16 * rhs->e35 
            + lhs->e36 * rhs->e15 + lhs->e56 * rhs->e13;
  res->e2356 =  + lhs->e2 * rhs->e356 + lhs->e356 * rhs->e2 + lhs->e3 * rhs->e256 
            + lhs->e256 * rhs->e3 + lhs->e5 * rhs->e236 + lhs->e236 * rhs->e5 
            + lhs->e6 * rhs->e235 + lhs->e235 * rhs->e6 + lhs->e23 * rhs->e56 
            + lhs->e25 * rhs->e36 + lhs->e35 * rhs->e26 + lhs->e26 * rhs->e35 
            + lhs->e36 * rhs->e25 + lhs->e56 * rhs->e23;
  res->e1456 =  + lhs->e1 * rhs->e456 + lhs->e456 * rhs->e1 + lhs->e4 * rhs->e156 
            + lhs->e156 * rhs->e4 + lhs->e5 * rhs->e146 + lhs->e146 * rhs->e5 
            + lhs->e6 * rhs->e145 + lhs->e145 * rhs->e6 + lhs->e14 * rhs->e56 
            + lhs->e15 * rhs->e46 + lhs->e45 * rhs->e16 + lhs->e16 * rhs->e45 
            + lhs->e46 * rhs->e15 + lhs->e56 * rhs->e14;
  res->e2456 =  + lhs->e2 * rhs->e456 + lhs->e456 * rhs->e2 + lhs->e4 * rhs->e256 
            + lhs->e256 * rhs->e4 + lhs->e5 * rhs->e246 + lhs->e246 * rhs->e5 
            + lhs->e6 * rhs->e245 + lhs->e245 * rhs->e6 + lhs->e24 * rhs->e56 
            + lhs->e25 * rhs->e46 + lhs->e45 * rhs->e26 + lhs->e26 * rhs->e45 
            + lhs->e46 * rhs->e25 + lhs->e56 * rhs->e24;
  res->e3456 =  + lhs->e3 * rhs->e456 + lhs->e456 * rhs->e3 + lhs->e4 * rhs->e356 
            + lhs->e356 * rhs->e4 + lhs->e5 * rhs->e346 + lhs->e346 * rhs->e5 
            + lhs->e6 * rhs->e345 + lhs->e345 * rhs->e6 + lhs->e34 * rhs->e56 
            + lhs->e35 * rhs->e46 + lhs->e45 * rhs->e36 + lhs->e36 * rhs->e45 
            + lhs->e46 * rhs->e35 + lhs->e56 * rhs->e34;
  res->e1237 =  + lhs->e1 * rhs->e237 + lhs->e237 * rhs->e1 + lhs->e2 * rhs->e137 
            + lhs->e137 * rhs->e2 + lhs->e3 * rhs->e127 + lhs->e127 * rhs->e3 
            + lhs->e7 * rhs->e123 + lhs->e123 * rhs->e7 + lhs->e12 * rhs->e37 
            + lhs->e13 * rhs->e27 + lhs->e23 * rhs->e17 + lhs->e17 * rhs->e23 
            + lhs->e27 * rhs->e13 + lhs->e37 * rhs->e12;
  res->e1247 =  + lhs->e1 * rhs->e247 + lhs->e247 * rhs->e1 + lhs->e2 * rhs->e147 
            + lhs->e147 * rhs->e2 + lhs->e4 * rhs->e127 + lhs->e127 * rhs->e4 
            + lhs->e7 * rhs->e124 + lhs->e124 * rhs->e7 + lhs->e12 * rhs->e47 
            + lhs->e14 * rhs->e27 + lhs->e24 * rhs->e17 + lhs->e17 * rhs->e24 
            + lhs->e27 * rhs->e14 + lhs->e47 * rhs->e12;
  res->e1347 =  + lhs->e1 * rhs->e347 + lhs->e347 * rhs->e1 + lhs->e3 * rhs->e147 
            + lhs->e147 * rhs->e3 + lhs->e4 * rhs->e137 + lhs->e137 * rhs->e4 
            + lhs->e7 * rhs->e134 + lhs->e134 * rhs->e7 + lhs->e13 * rhs->e47 
            + lhs->e14 * rhs->e37 + lhs->e34 * rhs->e17 + lhs->e17 * rhs->e34 
            + lhs->e37 * rhs->e14 + lhs->e47 * rhs->e13;
  res->e2347 =  + lhs->e2 * rhs->e347 + lhs->e347 * rhs->e2 + lhs->e3 * rhs->e247 
            + lhs->e247 * rhs->e3 + lhs->e4 * rhs->e237 + lhs->e237 * rhs->e4 
            + lhs->e7 * rhs->e234 + lhs->e234 * rhs->e7 + lhs->e23 * rhs->e47 
            + lhs->e24 * rhs->e37 + lhs->e34 * rhs->e27 + lhs->e27 * rhs->e34 
            + lhs->e37 * rhs->e24 + lhs->e47 * rhs->e23;
  res->e1257 =  + lhs->e1 * rhs->e257 + lhs->e257 * rhs->e1 + lhs->e2 * rhs->e157 
            + lhs->e157 * rhs->e2 + lhs->e5 * rhs->e127 + lhs->e127 * rhs->e5 
            + lhs->e7 * rhs->e125 + lhs->e125 * rhs->e7 + lhs->e12 * rhs->e57 
            + lhs->e15 * rhs->e27 + lhs->e25 * rhs->e17 + lhs->e17 * rhs->e25 
            + lhs->e27 * rhs->e15 + lhs->e57 * rhs->e12;
  res->e1357 =  + lhs->e1 * rhs->e357 + lhs->e357 * rhs->e1 + lhs->e3 * rhs->e157 
            + lhs->e157 * rhs->e3 + lhs->e5 * rhs->e137 + lhs->e137 * rhs->e5 
            + lhs->e7 * rhs->e135 + lhs->e135 * rhs->e7 + lhs->e13 * rhs->e57 
            + lhs->e15 * rhs->e37 + lhs->e35 * rhs->e17 + lhs->e17 * rhs->e35 
            + lhs->e37 * rhs->e15 + lhs->e57 * rhs->e13;
  res->e2357 =  + lhs->e2 * rhs->e357 + lhs->e357 * rhs->e2 + lhs->e3 * rhs->e257 
            + lhs->e257 * rhs->e3 + lhs->e5 * rhs->e237 + lhs->e237 * rhs->e5 
            + lhs->e7 * rhs->e235 + lhs->e235 * rhs->e7 + lhs->e23 * rhs->e57 
            + lhs->e25 * rhs->e37 + lhs->e35 * rhs->e27 + lhs->e27 * rhs->e35 
            + lhs->e37 * rhs->e25 + lhs->e57 * rhs->e23;
  res->e1457 =  + lhs->e1 * rhs->e457 + lhs->e457 * rhs->e1 + lhs->e4 * rhs->e157 
            + lhs->e157 * rhs->e4 + lhs->e5 * rhs->e147 + lhs->e147 * rhs->e5 
            + lhs->e7 * rhs->e145 + lhs->e145 * rhs->e7 + lhs->e14 * rhs->e57 
            + lhs->e15 * rhs->e47 + lhs->e45 * rhs->e17 + lhs->e17 * rhs->e45 
            + lhs->e47 * rhs->e15 + lhs->e57 * rhs->e14;
  res->e2457 =  + lhs->e2 * rhs->e457 + lhs->e457 * rhs->e2 + lhs->e4 * rhs->e257 
            + lhs->e257 * rhs->e4 + lhs->e5 * rhs->e247 + lhs->e247 * rhs->e5 
            + lhs->e7 * rhs->e245 + lhs->e245 * rhs->e7 + lhs->e24 * rhs->e57 
            + lhs->e25 * rhs->e47 + lhs->e45 * rhs->e27 + lhs->e27 * rhs->e45 
            + lhs->e47 * rhs->e25 + lhs->e57 * rhs->e24;
  res->e3457 =  + lhs->e3 * rhs->e457 + lhs->e457 * rhs->e3 + lhs->e4 * rhs->e357 
            + lhs->e357 * rhs->e4 + lhs->e5 * rhs->e347 + lhs->e347 * rhs->e5 
            + lhs->e7 * rhs->e345 + lhs->e345 * rhs->e7 + lhs->e34 * rhs->e57 
            + lhs->e35 * rhs->e47 + lhs->e45 * rhs->e37 + lhs->e37 * rhs->e45 
            + lhs->e47 * rhs->e35 + lhs->e57 * rhs->e34;
  res->e1267 =  + lhs->e1 * rhs->e267 + lhs->e267 * rhs->e1 + lhs->e2 * rhs->e167 
            + lhs->e167 * rhs->e2 + lhs->e6 * rhs->e127 + lhs->e127 * rhs->e6 
            + lhs->e7 * rhs->e126 + lhs->e126 * rhs->e7 + lhs->e12 * rhs->e67 
            + lhs->e16 * rhs->e27 + lhs->e26 * rhs->e17 + lhs->e17 * rhs->e26 
            + lhs->e27 * rhs->e16 + lhs->e67 * rhs->e12;
  res->e1367 =  + lhs->e1 * rhs->e367 + lhs->e367 * rhs->e1 + lhs->e3 * rhs->e167 
            + lhs->e167 * rhs->e3 + lhs->e6 * rhs->e137 + lhs->e137 * rhs->e6 
            + lhs->e7 * rhs->e136 + lhs->e136 * rhs->e7 + lhs->e13 * rhs->e67 
            + lhs->e16 * rhs->e37 + lhs->e36 * rhs->e17 + lhs->e17 * rhs->e36 
            + lhs->e37 * rhs->e16 + lhs->e67 * rhs->e13;
  res->e2367 =  + lhs->e2 * rhs->e367 + lhs->e367 * rhs->e2 + lhs->e3 * rhs->e267 
            + lhs->e267 * rhs->e3 + lhs->e6 * rhs->e237 + lhs->e237 * rhs->e6 
            + lhs->e7 * rhs->e236 + lhs->e236 * rhs->e7 + lhs->e23 * rhs->e67 
            + lhs->e26 * rhs->e37 + lhs->e36 * rhs->e27 + lhs->e27 * rhs->e36 
            + lhs->e37 * rhs->e26 + lhs->e67 * rhs->e23;
  res->e1467 =  + lhs->e1 * rhs->e467 + lhs->e467 * rhs->e1 + lhs->e4 * rhs->e167 
            + lhs->e167 * rhs->e4 + lhs->e6 * rhs->e147 + lhs->e147 * rhs->e6 
            + lhs->e7 * rhs->e146 + lhs->e146 * rhs->e7 + lhs->e14 * rhs->e67 
            + lhs->e16 * rhs->e47 + lhs->e46 * rhs->e17 + lhs->e17 * rhs->e46 
            + lhs->e47 * rhs->e16 + lhs->e67 * rhs->e14;
  res->e2467 =  + lhs->e2 * rhs->e467 + lhs->e467 * rhs->e2 + lhs->e4 * rhs->e267 
            + lhs->e267 * rhs->e4 + lhs->e6 * rhs->e247 + lhs->e247 * rhs->e6 
            + lhs->e7 * rhs->e246 + lhs->e246 * rhs->e7 + lhs->e24 * rhs->e67 
            + lhs->e26 * rhs->e47 + lhs->e46 * rhs->e27 + lhs->e27 * rhs->e46 
            + lhs->e47 * rhs->e26 + lhs->e67 * rhs->e24;
  res->e3467 =  + lhs->e3 * rhs->e467 + lhs->e467 * rhs->e3 + lhs->e4 * rhs->e367 
            + lhs->e367 * rhs->e4 + lhs->e6 * rhs->e347 + lhs->e347 * rhs->e6 
            + lhs->e7 * rhs->e346 + lhs->e346 * rhs->e7 + lhs->e34 * rhs->e67 
            + lhs->e36 * rhs->e47 + lhs->e46 * rhs->e37 + lhs->e37 * rhs->e46 
            + lhs->e47 * rhs->e36 + lhs->e67 * rhs->e34;
  res->e1567 =  + lhs->e1 * rhs->e567 + lhs->e567 * rhs->e1 + lhs->e5 * rhs->e167 
            + lhs->e167 * rhs->e5 + lhs->e6 * rhs->e157 + lhs->e157 * rhs->e6 
            + lhs->e7 * rhs->e156 + lhs->e156 * rhs->e7 + lhs->e15 * rhs->e67 
            + lhs->e16 * rhs->e57 + lhs->e56 * rhs->e17 + lhs->e17 * rhs->e56 
            + lhs->e57 * rhs->e16 + lhs->e67 * rhs->e15;
  res->e2567 =  + lhs->e2 * rhs->e567 + lhs->e567 * rhs->e2 + lhs->e5 * rhs->e267 
            + lhs->e267 * rhs->e5 + lhs->e6 * rhs->e257 + lhs->e257 * rhs->e6 
            + lhs->e7 * rhs->e256 + lhs->e256 * rhs->e7 + lhs->e25 * rhs->e67 
            + lhs->e26 * rhs->e57 + lhs->e56 * rhs->e27 + lhs->e27 * rhs->e56 
            + lhs->e57 * rhs->e26 + lhs->e67 * rhs->e25;
  res->e3567 =  + lhs->e3 * rhs->e567 + lhs->e567 * rhs->e3 + lhs->e5 * rhs->e367 
            + lhs->e367 * rhs->e5 + lhs->e6 * rhs->e357 + lhs->e357 * rhs->e6 
            + lhs->e7 * rhs->e356 + lhs->e356 * rhs->e7 + lhs->e35 * rhs->e67 
            + lhs->e36 * rhs->e57 + lhs->e56 * rhs->e37 + lhs->e37 * rhs->e56 
            + lhs->e57 * rhs->e36 + lhs->e67 * rhs->e35;
  res->e4567 =  + lhs->e4 * rhs->e567 + lhs->e567 * rhs->e4 + lhs->e5 * rhs->e467 
            + lhs->e467 * rhs->e5 + lhs->e6 * rhs->e457 + lhs->e457 * rhs->e6 
            + lhs->e7 * rhs->e456 + lhs->e456 * rhs->e7 + lhs->e45 * rhs->e67 
            + lhs->e46 * rhs->e57 + lhs->e56 * rhs->e47 + lhs->e47 * rhs->e56 
            + lhs->e57 * rhs->e46 + lhs->e67 * rhs->e45;
  // Order 5;
  res->e12345 =  + lhs->e1 * rhs->e2345 + lhs->e2345 * rhs->e1 + lhs->e2 * rhs->e1345 
             + lhs->e1345 * rhs->e2 + lhs->e3 * rhs->e1245 + lhs->e1245 * rhs->e3 
             + lhs->e4 * rhs->e1235 + lhs->e1235 * rhs->e4 + lhs->e5 * rhs->e1234 
             + lhs->e1234 * rhs->e5 + lhs->e12 * rhs->e345 + lhs->e345 * rhs->e12 
             + lhs->e13 * rhs->e245 + lhs->e245 * rhs->e13 + lhs->e23 * rhs->e145 
             + lhs->e145 * rhs->e23 + lhs->e14 * rhs->e235 + lhs->e235 * rhs->e14 
             + lhs->e24 * rhs->e135 + lhs->e135 * rhs->e24 + lhs->e34 * rhs->e125 
             + lhs->e125 * rhs->e34 + lhs->e15 * rhs->e234 + lhs->e234 * rhs->e15 
             + lhs->e25 * rhs->e134 + lhs->e134 * rhs->e25 + lhs->e35 * rhs->e124 
             + lhs->e124 * rhs->e35 + lhs->e45 * rhs->e123 + lhs->e123 * rhs->e45;
  res->e12346 =  + lhs->e1 * rhs->e2346 + lhs->e2346 * rhs->e1 + lhs->e2 * rhs->e1346 
             + lhs->e1346 * rhs->e2 + lhs->e3 * rhs->e1246 + lhs->e1246 * rhs->e3 
             + lhs->e4 * rhs->e1236 + lhs->e1236 * rhs->e4 + lhs->e6 * rhs->e1234 
             + lhs->e1234 * rhs->e6 + lhs->e12 * rhs->e346 + lhs->e346 * rhs->e12 
             + lhs->e13 * rhs->e246 + lhs->e246 * rhs->e13 + lhs->e23 * rhs->e146 
             + lhs->e146 * rhs->e23 + lhs->e14 * rhs->e236 + lhs->e236 * rhs->e14 
             + lhs->e24 * rhs->e136 + lhs->e136 * rhs->e24 + lhs->e34 * rhs->e126 
             + lhs->e126 * rhs->e34 + lhs->e16 * rhs->e234 + lhs->e234 * rhs->e16 
             + lhs->e26 * rhs->e134 + lhs->e134 * rhs->e26 + lhs->e36 * rhs->e124 
             + lhs->e124 * rhs->e36 + lhs->e46 * rhs->e123 + lhs->e123 * rhs->e46;
  res->e12356 =  + lhs->e1 * rhs->e2356 + lhs->e2356 * rhs->e1 + lhs->e2 * rhs->e1356 
             + lhs->e1356 * rhs->e2 + lhs->e3 * rhs->e1256 + lhs->e1256 * rhs->e3 
             + lhs->e5 * rhs->e1236 + lhs->e1236 * rhs->e5 + lhs->e6 * rhs->e1235 
             + lhs->e1235 * rhs->e6 + lhs->e12 * rhs->e356 + lhs->e356 * rhs->e12 
             + lhs->e13 * rhs->e256 + lhs->e256 * rhs->e13 + lhs->e23 * rhs->e156 
             + lhs->e156 * rhs->e23 + lhs->e15 * rhs->e236 + lhs->e236 * rhs->e15 
             + lhs->e25 * rhs->e136 + lhs->e136 * rhs->e25 + lhs->e35 * rhs->e126 
             + lhs->e126 * rhs->e35 + lhs->e16 * rhs->e235 + lhs->e235 * rhs->e16 
             + lhs->e26 * rhs->e135 + lhs->e135 * rhs->e26 + lhs->e36 * rhs->e125 
             + lhs->e125 * rhs->e36 + lhs->e56 * rhs->e123 + lhs->e123 * rhs->e56;
  res->e12456 =  + lhs->e1 * rhs->e2456 + lhs->e2456 * rhs->e1 + lhs->e2 * rhs->e1456 
             + lhs->e1456 * rhs->e2 + lhs->e4 * rhs->e1256 + lhs->e1256 * rhs->e4 
             + lhs->e5 * rhs->e1246 + lhs->e1246 * rhs->e5 + lhs->e6 * rhs->e1245 
             + lhs->e1245 * rhs->e6 + lhs->e12 * rhs->e456 + lhs->e456 * rhs->e12 
             + lhs->e14 * rhs->e256 + lhs->e256 * rhs->e14 + lhs->e24 * rhs->e156 
             + lhs->e156 * rhs->e24 + lhs->e15 * rhs->e246 + lhs->e246 * rhs->e15 
             + lhs->e25 * rhs->e146 + lhs->e146 * rhs->e25 + lhs->e45 * rhs->e126 
             + lhs->e126 * rhs->e45 + lhs->e16 * rhs->e245 + lhs->e245 * rhs->e16 
             + lhs->e26 * rhs->e145 + lhs->e145 * rhs->e26 + lhs->e46 * rhs->e125 
             + lhs->e125 * rhs->e46 + lhs->e56 * rhs->e124 + lhs->e124 * rhs->e56;
  res->e13456 =  + lhs->e1 * rhs->e3456 + lhs->e3456 * rhs->e1 + lhs->e3 * rhs->e1456 
             + lhs->e1456 * rhs->e3 + lhs->e4 * rhs->e1356 + lhs->e1356 * rhs->e4 
             + lhs->e5 * rhs->e1346 + lhs->e1346 * rhs->e5 + lhs->e6 * rhs->e1345 
             + lhs->e1345 * rhs->e6 + lhs->e13 * rhs->e456 + lhs->e456 * rhs->e13 
             + lhs->e14 * rhs->e356 + lhs->e356 * rhs->e14 + lhs->e34 * rhs->e156 
             + lhs->e156 * rhs->e34 + lhs->e15 * rhs->e346 + lhs->e346 * rhs->e15 
             + lhs->e35 * rhs->e146 + lhs->e146 * rhs->e35 + lhs->e45 * rhs->e136 
             + lhs->e136 * rhs->e45 + lhs->e16 * rhs->e345 + lhs->e345 * rhs->e16 
             + lhs->e36 * rhs->e145 + lhs->e145 * rhs->e36 + lhs->e46 * rhs->e135 
             + lhs->e135 * rhs->e46 + lhs->e56 * rhs->e134 + lhs->e134 * rhs->e56;
  res->e23456 =  + lhs->e2 * rhs->e3456 + lhs->e3456 * rhs->e2 + lhs->e3 * rhs->e2456 
             + lhs->e2456 * rhs->e3 + lhs->e4 * rhs->e2356 + lhs->e2356 * rhs->e4 
             + lhs->e5 * rhs->e2346 + lhs->e2346 * rhs->e5 + lhs->e6 * rhs->e2345 
             + lhs->e2345 * rhs->e6 + lhs->e23 * rhs->e456 + lhs->e456 * rhs->e23 
             + lhs->e24 * rhs->e356 + lhs->e356 * rhs->e24 + lhs->e34 * rhs->e256 
             + lhs->e256 * rhs->e34 + lhs->e25 * rhs->e346 + lhs->e346 * rhs->e25 
             + lhs->e35 * rhs->e246 + lhs->e246 * rhs->e35 + lhs->e45 * rhs->e236 
             + lhs->e236 * rhs->e45 + lhs->e26 * rhs->e345 + lhs->e345 * rhs->e26 
             + lhs->e36 * rhs->e245 + lhs->e245 * rhs->e36 + lhs->e46 * rhs->e235 
             + lhs->e235 * rhs->e46 + lhs->e56 * rhs->e234 + lhs->e234 * rhs->e56;
  res->e12347 =  + lhs->e1 * rhs->e2347 + lhs->e2347 * rhs->e1 + lhs->e2 * rhs->e1347 
             + lhs->e1347 * rhs->e2 + lhs->e3 * rhs->e1247 + lhs->e1247 * rhs->e3 
             + lhs->e4 * rhs->e1237 + lhs->e1237 * rhs->e4 + lhs->e7 * rhs->e1234 
             + lhs->e1234 * rhs->e7 + lhs->e12 * rhs->e347 + lhs->e347 * rhs->e12 
             + lhs->e13 * rhs->e247 + lhs->e247 * rhs->e13 + lhs->e23 * rhs->e147 
             + lhs->e147 * rhs->e23 + lhs->e14 * rhs->e237 + lhs->e237 * rhs->e14 
             + lhs->e24 * rhs->e137 + lhs->e137 * rhs->e24 + lhs->e34 * rhs->e127 
             + lhs->e127 * rhs->e34 + lhs->e17 * rhs->e234 + lhs->e234 * rhs->e17 
             + lhs->e27 * rhs->e134 + lhs->e134 * rhs->e27 + lhs->e37 * rhs->e124 
             + lhs->e124 * rhs->e37 + lhs->e47 * rhs->e123 + lhs->e123 * rhs->e47;
  res->e12357 =  + lhs->e1 * rhs->e2357 + lhs->e2357 * rhs->e1 + lhs->e2 * rhs->e1357 
             + lhs->e1357 * rhs->e2 + lhs->e3 * rhs->e1257 + lhs->e1257 * rhs->e3 
             + lhs->e5 * rhs->e1237 + lhs->e1237 * rhs->e5 + lhs->e7 * rhs->e1235 
             + lhs->e1235 * rhs->e7 + lhs->e12 * rhs->e357 + lhs->e357 * rhs->e12 
             + lhs->e13 * rhs->e257 + lhs->e257 * rhs->e13 + lhs->e23 * rhs->e157 
             + lhs->e157 * rhs->e23 + lhs->e15 * rhs->e237 + lhs->e237 * rhs->e15 
             + lhs->e25 * rhs->e137 + lhs->e137 * rhs->e25 + lhs->e35 * rhs->e127 
             + lhs->e127 * rhs->e35 + lhs->e17 * rhs->e235 + lhs->e235 * rhs->e17 
             + lhs->e27 * rhs->e135 + lhs->e135 * rhs->e27 + lhs->e37 * rhs->e125 
             + lhs->e125 * rhs->e37 + lhs->e57 * rhs->e123 + lhs->e123 * rhs->e57;
  res->e12457 =  + lhs->e1 * rhs->e2457 + lhs->e2457 * rhs->e1 + lhs->e2 * rhs->e1457 
             + lhs->e1457 * rhs->e2 + lhs->e4 * rhs->e1257 + lhs->e1257 * rhs->e4 
             + lhs->e5 * rhs->e1247 + lhs->e1247 * rhs->e5 + lhs->e7 * rhs->e1245 
             + lhs->e1245 * rhs->e7 + lhs->e12 * rhs->e457 + lhs->e457 * rhs->e12 
             + lhs->e14 * rhs->e257 + lhs->e257 * rhs->e14 + lhs->e24 * rhs->e157 
             + lhs->e157 * rhs->e24 + lhs->e15 * rhs->e247 + lhs->e247 * rhs->e15 
             + lhs->e25 * rhs->e147 + lhs->e147 * rhs->e25 + lhs->e45 * rhs->e127 
             + lhs->e127 * rhs->e45 + lhs->e17 * rhs->e245 + lhs->e245 * rhs->e17 
             + lhs->e27 * rhs->e145 + lhs->e145 * rhs->e27 + lhs->e47 * rhs->e125 
             + lhs->e125 * rhs->e47 + lhs->e57 * rhs->e124 + lhs->e124 * rhs->e57;
  res->e13457 =  + lhs->e1 * rhs->e3457 + lhs->e3457 * rhs->e1 + lhs->e3 * rhs->e1457 
             + lhs->e1457 * rhs->e3 + lhs->e4 * rhs->e1357 + lhs->e1357 * rhs->e4 
             + lhs->e5 * rhs->e1347 + lhs->e1347 * rhs->e5 + lhs->e7 * rhs->e1345 
             + lhs->e1345 * rhs->e7 + lhs->e13 * rhs->e457 + lhs->e457 * rhs->e13 
             + lhs->e14 * rhs->e357 + lhs->e357 * rhs->e14 + lhs->e34 * rhs->e157 
             + lhs->e157 * rhs->e34 + lhs->e15 * rhs->e347 + lhs->e347 * rhs->e15 
             + lhs->e35 * rhs->e147 + lhs->e147 * rhs->e35 + lhs->e45 * rhs->e137 
             + lhs->e137 * rhs->e45 + lhs->e17 * rhs->e345 + lhs->e345 * rhs->e17 
             + lhs->e37 * rhs->e145 + lhs->e145 * rhs->e37 + lhs->e47 * rhs->e135 
             + lhs->e135 * rhs->e47 + lhs->e57 * rhs->e134 + lhs->e134 * rhs->e57;
  res->e23457 =  + lhs->e2 * rhs->e3457 + lhs->e3457 * rhs->e2 + lhs->e3 * rhs->e2457 
             + lhs->e2457 * rhs->e3 + lhs->e4 * rhs->e2357 + lhs->e2357 * rhs->e4 
             + lhs->e5 * rhs->e2347 + lhs->e2347 * rhs->e5 + lhs->e7 * rhs->e2345 
             + lhs->e2345 * rhs->e7 + lhs->e23 * rhs->e457 + lhs->e457 * rhs->e23 
             + lhs->e24 * rhs->e357 + lhs->e357 * rhs->e24 + lhs->e34 * rhs->e257 
             + lhs->e257 * rhs->e34 + lhs->e25 * rhs->e347 + lhs->e347 * rhs->e25 
             + lhs->e35 * rhs->e247 + lhs->e247 * rhs->e35 + lhs->e45 * rhs->e237 
             + lhs->e237 * rhs->e45 + lhs->e27 * rhs->e345 + lhs->e345 * rhs->e27 
             + lhs->e37 * rhs->e245 + lhs->e245 * rhs->e37 + lhs->e47 * rhs->e235 
             + lhs->e235 * rhs->e47 + lhs->e57 * rhs->e234 + lhs->e234 * rhs->e57;
  res->e12367 =  + lhs->e1 * rhs->e2367 + lhs->e2367 * rhs->e1 + lhs->e2 * rhs->e1367 
             + lhs->e1367 * rhs->e2 + lhs->e3 * rhs->e1267 + lhs->e1267 * rhs->e3 
             + lhs->e6 * rhs->e1237 + lhs->e1237 * rhs->e6 + lhs->e7 * rhs->e1236 
             + lhs->e1236 * rhs->e7 + lhs->e12 * rhs->e367 + lhs->e367 * rhs->e12 
             + lhs->e13 * rhs->e267 + lhs->e267 * rhs->e13 + lhs->e23 * rhs->e167 
             + lhs->e167 * rhs->e23 + lhs->e16 * rhs->e237 + lhs->e237 * rhs->e16 
             + lhs->e26 * rhs->e137 + lhs->e137 * rhs->e26 + lhs->e36 * rhs->e127 
             + lhs->e127 * rhs->e36 + lhs->e17 * rhs->e236 + lhs->e236 * rhs->e17 
             + lhs->e27 * rhs->e136 + lhs->e136 * rhs->e27 + lhs->e37 * rhs->e126 
             + lhs->e126 * rhs->e37 + lhs->e67 * rhs->e123 + lhs->e123 * rhs->e67;
  res->e12467 =  + lhs->e1 * rhs->e2467 + lhs->e2467 * rhs->e1 + lhs->e2 * rhs->e1467 
             + lhs->e1467 * rhs->e2 + lhs->e4 * rhs->e1267 + lhs->e1267 * rhs->e4 
             + lhs->e6 * rhs->e1247 + lhs->e1247 * rhs->e6 + lhs->e7 * rhs->e1246 
             + lhs->e1246 * rhs->e7 + lhs->e12 * rhs->e467 + lhs->e467 * rhs->e12 
             + lhs->e14 * rhs->e267 + lhs->e267 * rhs->e14 + lhs->e24 * rhs->e167 
             + lhs->e167 * rhs->e24 + lhs->e16 * rhs->e247 + lhs->e247 * rhs->e16 
             + lhs->e26 * rhs->e147 + lhs->e147 * rhs->e26 + lhs->e46 * rhs->e127 
             + lhs->e127 * rhs->e46 + lhs->e17 * rhs->e246 + lhs->e246 * rhs->e17 
             + lhs->e27 * rhs->e146 + lhs->e146 * rhs->e27 + lhs->e47 * rhs->e126 
             + lhs->e126 * rhs->e47 + lhs->e67 * rhs->e124 + lhs->e124 * rhs->e67;
  res->e13467 =  + lhs->e1 * rhs->e3467 + lhs->e3467 * rhs->e1 + lhs->e3 * rhs->e1467 
             + lhs->e1467 * rhs->e3 + lhs->e4 * rhs->e1367 + lhs->e1367 * rhs->e4 
             + lhs->e6 * rhs->e1347 + lhs->e1347 * rhs->e6 + lhs->e7 * rhs->e1346 
             + lhs->e1346 * rhs->e7 + lhs->e13 * rhs->e467 + lhs->e467 * rhs->e13 
             + lhs->e14 * rhs->e367 + lhs->e367 * rhs->e14 + lhs->e34 * rhs->e167 
             + lhs->e167 * rhs->e34 + lhs->e16 * rhs->e347 + lhs->e347 * rhs->e16 
             + lhs->e36 * rhs->e147 + lhs->e147 * rhs->e36 + lhs->e46 * rhs->e137 
             + lhs->e137 * rhs->e46 + lhs->e17 * rhs->e346 + lhs->e346 * rhs->e17 
             + lhs->e37 * rhs->e146 + lhs->e146 * rhs->e37 + lhs->e47 * rhs->e136 
             + lhs->e136 * rhs->e47 + lhs->e67 * rhs->e134 + lhs->e134 * rhs->e67;
  res->e23467 =  + lhs->e2 * rhs->e3467 + lhs->e3467 * rhs->e2 + lhs->e3 * rhs->e2467 
             + lhs->e2467 * rhs->e3 + lhs->e4 * rhs->e2367 + lhs->e2367 * rhs->e4 
             + lhs->e6 * rhs->e2347 + lhs->e2347 * rhs->e6 + lhs->e7 * rhs->e2346 
             + lhs->e2346 * rhs->e7 + lhs->e23 * rhs->e467 + lhs->e467 * rhs->e23 
             + lhs->e24 * rhs->e367 + lhs->e367 * rhs->e24 + lhs->e34 * rhs->e267 
             + lhs->e267 * rhs->e34 + lhs->e26 * rhs->e347 + lhs->e347 * rhs->e26 
             + lhs->e36 * rhs->e247 + lhs->e247 * rhs->e36 + lhs->e46 * rhs->e237 
             + lhs->e237 * rhs->e46 + lhs->e27 * rhs->e346 + lhs->e346 * rhs->e27 
             + lhs->e37 * rhs->e246 + lhs->e246 * rhs->e37 + lhs->e47 * rhs->e236 
             + lhs->e236 * rhs->e47 + lhs->e67 * rhs->e234 + lhs->e234 * rhs->e67;
  res->e12567 =  + lhs->e1 * rhs->e2567 + lhs->e2567 * rhs->e1 + lhs->e2 * rhs->e1567 
             + lhs->e1567 * rhs->e2 + lhs->e5 * rhs->e1267 + lhs->e1267 * rhs->e5 
             + lhs->e6 * rhs->e1257 + lhs->e1257 * rhs->e6 + lhs->e7 * rhs->e1256 
             + lhs->e1256 * rhs->e7 + lhs->e12 * rhs->e567 + lhs->e567 * rhs->e12 
             + lhs->e15 * rhs->e267 + lhs->e267 * rhs->e15 + lhs->e25 * rhs->e167 
             + lhs->e167 * rhs->e25 + lhs->e16 * rhs->e257 + lhs->e257 * rhs->e16 
             + lhs->e26 * rhs->e157 + lhs->e157 * rhs->e26 + lhs->e56 * rhs->e127 
             + lhs->e127 * rhs->e56 + lhs->e17 * rhs->e256 + lhs->e256 * rhs->e17 
             + lhs->e27 * rhs->e156 + lhs->e156 * rhs->e27 + lhs->e57 * rhs->e126 
             + lhs->e126 * rhs->e57 + lhs->e67 * rhs->e125 + lhs->e125 * rhs->e67;
  res->e13567 =  + lhs->e1 * rhs->e3567 + lhs->e3567 * rhs->e1 + lhs->e3 * rhs->e1567 
             + lhs->e1567 * rhs->e3 + lhs->e5 * rhs->e1367 + lhs->e1367 * rhs->e5 
             + lhs->e6 * rhs->e1357 + lhs->e1357 * rhs->e6 + lhs->e7 * rhs->e1356 
             + lhs->e1356 * rhs->e7 + lhs->e13 * rhs->e567 + lhs->e567 * rhs->e13 
             + lhs->e15 * rhs->e367 + lhs->e367 * rhs->e15 + lhs->e35 * rhs->e167 
             + lhs->e167 * rhs->e35 + lhs->e16 * rhs->e357 + lhs->e357 * rhs->e16 
             + lhs->e36 * rhs->e157 + lhs->e157 * rhs->e36 + lhs->e56 * rhs->e137 
             + lhs->e137 * rhs->e56 + lhs->e17 * rhs->e356 + lhs->e356 * rhs->e17 
             + lhs->e37 * rhs->e156 + lhs->e156 * rhs->e37 + lhs->e57 * rhs->e136 
             + lhs->e136 * rhs->e57 + lhs->e67 * rhs->e135 + lhs->e135 * rhs->e67;
  res->e23567 =  + lhs->e2 * rhs->e3567 + lhs->e3567 * rhs->e2 + lhs->e3 * rhs->e2567 
             + lhs->e2567 * rhs->e3 + lhs->e5 * rhs->e2367 + lhs->e2367 * rhs->e5 
             + lhs->e6 * rhs->e2357 + lhs->e2357 * rhs->e6 + lhs->e7 * rhs->e2356 
             + lhs->e2356 * rhs->e7 + lhs->e23 * rhs->e567 + lhs->e567 * rhs->e23 
             + lhs->e25 * rhs->e367 + lhs->e367 * rhs->e25 + lhs->e35 * rhs->e267 
             + lhs->e267 * rhs->e35 + lhs->e26 * rhs->e357 + lhs->e357 * rhs->e26 
             + lhs->e36 * rhs->e257 + lhs->e257 * rhs->e36 + lhs->e56 * rhs->e237 
             + lhs->e237 * rhs->e56 + lhs->e27 * rhs->e356 + lhs->e356 * rhs->e27 
             + lhs->e37 * rhs->e256 + lhs->e256 * rhs->e37 + lhs->e57 * rhs->e236 
             + lhs->e236 * rhs->e57 + lhs->e67 * rhs->e235 + lhs->e235 * rhs->e67;
  res->e14567 =  + lhs->e1 * rhs->e4567 + lhs->e4567 * rhs->e1 + lhs->e4 * rhs->e1567 
             + lhs->e1567 * rhs->e4 + lhs->e5 * rhs->e1467 + lhs->e1467 * rhs->e5 
             + lhs->e6 * rhs->e1457 + lhs->e1457 * rhs->e6 + lhs->e7 * rhs->e1456 
             + lhs->e1456 * rhs->e7 + lhs->e14 * rhs->e567 + lhs->e567 * rhs->e14 
             + lhs->e15 * rhs->e467 + lhs->e467 * rhs->e15 + lhs->e45 * rhs->e167 
             + lhs->e167 * rhs->e45 + lhs->e16 * rhs->e457 + lhs->e457 * rhs->e16 
             + lhs->e46 * rhs->e157 + lhs->e157 * rhs->e46 + lhs->e56 * rhs->e147 
             + lhs->e147 * rhs->e56 + lhs->e17 * rhs->e456 + lhs->e456 * rhs->e17 
             + lhs->e47 * rhs->e156 + lhs->e156 * rhs->e47 + lhs->e57 * rhs->e146 
             + lhs->e146 * rhs->e57 + lhs->e67 * rhs->e145 + lhs->e145 * rhs->e67;
  res->e24567 =  + lhs->e2 * rhs->e4567 + lhs->e4567 * rhs->e2 + lhs->e4 * rhs->e2567 
             + lhs->e2567 * rhs->e4 + lhs->e5 * rhs->e2467 + lhs->e2467 * rhs->e5 
             + lhs->e6 * rhs->e2457 + lhs->e2457 * rhs->e6 + lhs->e7 * rhs->e2456 
             + lhs->e2456 * rhs->e7 + lhs->e24 * rhs->e567 + lhs->e567 * rhs->e24 
             + lhs->e25 * rhs->e467 + lhs->e467 * rhs->e25 + lhs->e45 * rhs->e267 
             + lhs->e267 * rhs->e45 + lhs->e26 * rhs->e457 + lhs->e457 * rhs->e26 
             + lhs->e46 * rhs->e257 + lhs->e257 * rhs->e46 + lhs->e56 * rhs->e247 
             + lhs->e247 * rhs->e56 + lhs->e27 * rhs->e456 + lhs->e456 * rhs->e27 
             + lhs->e47 * rhs->e256 + lhs->e256 * rhs->e47 + lhs->e57 * rhs->e246 
             + lhs->e246 * rhs->e57 + lhs->e67 * rhs->e245 + lhs->e245 * rhs->e67;
  res->e34567 =  + lhs->e3 * rhs->e4567 + lhs->e4567 * rhs->e3 + lhs->e4 * rhs->e3567 
             + lhs->e3567 * rhs->e4 + lhs->e5 * rhs->e3467 + lhs->e3467 * rhs->e5 
             + lhs->e6 * rhs->e3457 + lhs->e3457 * rhs->e6 + lhs->e7 * rhs->e3456 
             + lhs->e3456 * rhs->e7 + lhs->e34 * rhs->e567 + lhs->e567 * rhs->e34 
             + lhs->e35 * rhs->e467 + lhs->e467 * rhs->e35 + lhs->e45 * rhs->e367 
             + lhs->e367 * rhs->e45 + lhs->e36 * rhs->e457 + lhs->e457 * rhs->e36 
             + lhs->e46 * rhs->e357 + lhs->e357 * rhs->e46 + lhs->e56 * rhs->e347 
             + lhs->e347 * rhs->e56 + lhs->e37 * rhs->e456 + lhs->e456 * rhs->e37 
             + lhs->e47 * rhs->e356 + lhs->e356 * rhs->e47 + lhs->e57 * rhs->e346 
             + lhs->e346 * rhs->e57 + lhs->e67 * rhs->e345 + lhs->e345 * rhs->e67;
  // Order 6;
  res->e123456 =  + lhs->e1 * rhs->e23456 + lhs->e23456 * rhs->e1 + lhs->e2 * rhs->e13456 
              + lhs->e13456 * rhs->e2 + lhs->e3 * rhs->e12456 + lhs->e12456 * rhs->e3 
              + lhs->e4 * rhs->e12356 + lhs->e12356 * rhs->e4 + lhs->e5 * rhs->e12346 
              + lhs->e12346 * rhs->e5 + lhs->e6 * rhs->e12345 + lhs->e12345 * rhs->e6 
              + lhs->e12 * rhs->e3456 + lhs->e3456 * rhs->e12 + lhs->e13 * rhs->e2456 
              + lhs->e2456 * rhs->e13 + lhs->e23 * rhs->e1456 + lhs->e1456 * rhs->e23 
              + lhs->e14 * rhs->e2356 + lhs->e2356 * rhs->e14 + lhs->e24 * rhs->e1356 
              + lhs->e1356 * rhs->e24 + lhs->e34 * rhs->e1256 + lhs->e1256 * rhs->e34 
              + lhs->e15 * rhs->e2346 + lhs->e2346 * rhs->e15 + lhs->e25 * rhs->e1346 
              + lhs->e1346 * rhs->e25 + lhs->e35 * rhs->e1246 + lhs->e1246 * rhs->e35 
              + lhs->e45 * rhs->e1236 + lhs->e1236 * rhs->e45 + lhs->e16 * rhs->e2345 
              + lhs->e2345 * rhs->e16 + lhs->e26 * rhs->e1345 + lhs->e1345 * rhs->e26 
              + lhs->e36 * rhs->e1245 + lhs->e1245 * rhs->e36 + lhs->e46 * rhs->e1235 
              + lhs->e1235 * rhs->e46 + lhs->e56 * rhs->e1234 + lhs->e1234 * rhs->e56 
              + lhs->e123 * rhs->e456 + lhs->e124 * rhs->e356 + lhs->e134 * rhs->e256 
              + lhs->e234 * rhs->e156 + lhs->e125 * rhs->e346 + lhs->e135 * rhs->e246 
              + lhs->e235 * rhs->e146 + lhs->e145 * rhs->e236 + lhs->e245 * rhs->e136 
              + lhs->e345 * rhs->e126 + lhs->e126 * rhs->e345 + lhs->e136 * rhs->e245 
              + lhs->e236 * rhs->e145 + lhs->e146 * rhs->e235 + lhs->e246 * rhs->e135 
              + lhs->e346 * rhs->e125 + lhs->e156 * rhs->e234 + lhs->e256 * rhs->e134 
              + lhs->e356 * rhs->e124 + lhs->e456 * rhs->e123;
  res->e123457 =  + lhs->e1 * rhs->e23457 + lhs->e23457 * rhs->e1 + lhs->e2 * rhs->e13457 
              + lhs->e13457 * rhs->e2 + lhs->e3 * rhs->e12457 + lhs->e12457 * rhs->e3 
              + lhs->e4 * rhs->e12357 + lhs->e12357 * rhs->e4 + lhs->e5 * rhs->e12347 
              + lhs->e12347 * rhs->e5 + lhs->e7 * rhs->e12345 + lhs->e12345 * rhs->e7 
              + lhs->e12 * rhs->e3457 + lhs->e3457 * rhs->e12 + lhs->e13 * rhs->e2457 
              + lhs->e2457 * rhs->e13 + lhs->e23 * rhs->e1457 + lhs->e1457 * rhs->e23 
              + lhs->e14 * rhs->e2357 + lhs->e2357 * rhs->e14 + lhs->e24 * rhs->e1357 
              + lhs->e1357 * rhs->e24 + lhs->e34 * rhs->e1257 + lhs->e1257 * rhs->e34 
              + lhs->e15 * rhs->e2347 + lhs->e2347 * rhs->e15 + lhs->e25 * rhs->e1347 
              + lhs->e1347 * rhs->e25 + lhs->e35 * rhs->e1247 + lhs->e1247 * rhs->e35 
              + lhs->e45 * rhs->e1237 + lhs->e1237 * rhs->e45 + lhs->e17 * rhs->e2345 
              + lhs->e2345 * rhs->e17 + lhs->e27 * rhs->e1345 + lhs->e1345 * rhs->e27 
              + lhs->e37 * rhs->e1245 + lhs->e1245 * rhs->e37 + lhs->e47 * rhs->e1235 
              + lhs->e1235 * rhs->e47 + lhs->e57 * rhs->e1234 + lhs->e1234 * rhs->e57 
              + lhs->e123 * rhs->e457 + lhs->e124 * rhs->e357 + lhs->e134 * rhs->e257 
              + lhs->e234 * rhs->e157 + lhs->e125 * rhs->e347 + lhs->e135 * rhs->e247 
              + lhs->e235 * rhs->e147 + lhs->e145 * rhs->e237 + lhs->e245 * rhs->e137 
              + lhs->e345 * rhs->e127 + lhs->e127 * rhs->e345 + lhs->e137 * rhs->e245 
              + lhs->e237 * rhs->e145 + lhs->e147 * rhs->e235 + lhs->e247 * rhs->e135 
              + lhs->e347 * rhs->e125 + lhs->e157 * rhs->e234 + lhs->e257 * rhs->e134 
              + lhs->e357 * rhs->e124 + lhs->e457 * rhs->e123;
  res->e123467 =  + lhs->e1 * rhs->e23467 + lhs->e23467 * rhs->e1 + lhs->e2 * rhs->e13467 
              + lhs->e13467 * rhs->e2 + lhs->e3 * rhs->e12467 + lhs->e12467 * rhs->e3 
              + lhs->e4 * rhs->e12367 + lhs->e12367 * rhs->e4 + lhs->e6 * rhs->e12347 
              + lhs->e12347 * rhs->e6 + lhs->e7 * rhs->e12346 + lhs->e12346 * rhs->e7 
              + lhs->e12 * rhs->e3467 + lhs->e3467 * rhs->e12 + lhs->e13 * rhs->e2467 
              + lhs->e2467 * rhs->e13 + lhs->e23 * rhs->e1467 + lhs->e1467 * rhs->e23 
              + lhs->e14 * rhs->e2367 + lhs->e2367 * rhs->e14 + lhs->e24 * rhs->e1367 
              + lhs->e1367 * rhs->e24 + lhs->e34 * rhs->e1267 + lhs->e1267 * rhs->e34 
              + lhs->e16 * rhs->e2347 + lhs->e2347 * rhs->e16 + lhs->e26 * rhs->e1347 
              + lhs->e1347 * rhs->e26 + lhs->e36 * rhs->e1247 + lhs->e1247 * rhs->e36 
              + lhs->e46 * rhs->e1237 + lhs->e1237 * rhs->e46 + lhs->e17 * rhs->e2346 
              + lhs->e2346 * rhs->e17 + lhs->e27 * rhs->e1346 + lhs->e1346 * rhs->e27 
              + lhs->e37 * rhs->e1246 + lhs->e1246 * rhs->e37 + lhs->e47 * rhs->e1236 
              + lhs->e1236 * rhs->e47 + lhs->e67 * rhs->e1234 + lhs->e1234 * rhs->e67 
              + lhs->e123 * rhs->e467 + lhs->e124 * rhs->e367 + lhs->e134 * rhs->e267 
              + lhs->e234 * rhs->e167 + lhs->e126 * rhs->e347 + lhs->e136 * rhs->e247 
              + lhs->e236 * rhs->e147 + lhs->e146 * rhs->e237 + lhs->e246 * rhs->e137 
              + lhs->e346 * rhs->e127 + lhs->e127 * rhs->e346 + lhs->e137 * rhs->e246 
              + lhs->e237 * rhs->e146 + lhs->e147 * rhs->e236 + lhs->e247 * rhs->e136 
              + lhs->e347 * rhs->e126 + lhs->e167 * rhs->e234 + lhs->e267 * rhs->e134 
              + lhs->e367 * rhs->e124 + lhs->e467 * rhs->e123;
  res->e123567 =  + lhs->e1 * rhs->e23567 + lhs->e23567 * rhs->e1 + lhs->e2 * rhs->e13567 
              + lhs->e13567 * rhs->e2 + lhs->e3 * rhs->e12567 + lhs->e12567 * rhs->e3 
              + lhs->e5 * rhs->e12367 + lhs->e12367 * rhs->e5 + lhs->e6 * rhs->e12357 
              + lhs->e12357 * rhs->e6 + lhs->e7 * rhs->e12356 + lhs->e12356 * rhs->e7 
              + lhs->e12 * rhs->e3567 + lhs->e3567 * rhs->e12 + lhs->e13 * rhs->e2567 
              + lhs->e2567 * rhs->e13 + lhs->e23 * rhs->e1567 + lhs->e1567 * rhs->e23 
              + lhs->e15 * rhs->e2367 + lhs->e2367 * rhs->e15 + lhs->e25 * rhs->e1367 
              + lhs->e1367 * rhs->e25 + lhs->e35 * rhs->e1267 + lhs->e1267 * rhs->e35 
              + lhs->e16 * rhs->e2357 + lhs->e2357 * rhs->e16 + lhs->e26 * rhs->e1357 
              + lhs->e1357 * rhs->e26 + lhs->e36 * rhs->e1257 + lhs->e1257 * rhs->e36 
              + lhs->e56 * rhs->e1237 + lhs->e1237 * rhs->e56 + lhs->e17 * rhs->e2356 
              + lhs->e2356 * rhs->e17 + lhs->e27 * rhs->e1356 + lhs->e1356 * rhs->e27 
              + lhs->e37 * rhs->e1256 + lhs->e1256 * rhs->e37 + lhs->e57 * rhs->e1236 
              + lhs->e1236 * rhs->e57 + lhs->e67 * rhs->e1235 + lhs->e1235 * rhs->e67 
              + lhs->e123 * rhs->e567 + lhs->e125 * rhs->e367 + lhs->e135 * rhs->e267 
              + lhs->e235 * rhs->e167 + lhs->e126 * rhs->e357 + lhs->e136 * rhs->e257 
              + lhs->e236 * rhs->e157 + lhs->e156 * rhs->e237 + lhs->e256 * rhs->e137 
              + lhs->e356 * rhs->e127 + lhs->e127 * rhs->e356 + lhs->e137 * rhs->e256 
              + lhs->e237 * rhs->e156 + lhs->e157 * rhs->e236 + lhs->e257 * rhs->e136 
              + lhs->e357 * rhs->e126 + lhs->e167 * rhs->e235 + lhs->e267 * rhs->e135 
              + lhs->e367 * rhs->e125 + lhs->e567 * rhs->e123;
  res->e124567 =  + lhs->e1 * rhs->e24567 + lhs->e24567 * rhs->e1 + lhs->e2 * rhs->e14567 
              + lhs->e14567 * rhs->e2 + lhs->e4 * rhs->e12567 + lhs->e12567 * rhs->e4 
              + lhs->e5 * rhs->e12467 + lhs->e12467 * rhs->e5 + lhs->e6 * rhs->e12457 
              + lhs->e12457 * rhs->e6 + lhs->e7 * rhs->e12456 + lhs->e12456 * rhs->e7 
              + lhs->e12 * rhs->e4567 + lhs->e4567 * rhs->e12 + lhs->e14 * rhs->e2567 
              + lhs->e2567 * rhs->e14 + lhs->e24 * rhs->e1567 + lhs->e1567 * rhs->e24 
              + lhs->e15 * rhs->e2467 + lhs->e2467 * rhs->e15 + lhs->e25 * rhs->e1467 
              + lhs->e1467 * rhs->e25 + lhs->e45 * rhs->e1267 + lhs->e1267 * rhs->e45 
              + lhs->e16 * rhs->e2457 + lhs->e2457 * rhs->e16 + lhs->e26 * rhs->e1457 
              + lhs->e1457 * rhs->e26 + lhs->e46 * rhs->e1257 + lhs->e1257 * rhs->e46 
              + lhs->e56 * rhs->e1247 + lhs->e1247 * rhs->e56 + lhs->e17 * rhs->e2456 
              + lhs->e2456 * rhs->e17 + lhs->e27 * rhs->e1456 + lhs->e1456 * rhs->e27 
              + lhs->e47 * rhs->e1256 + lhs->e1256 * rhs->e47 + lhs->e57 * rhs->e1246 
              + lhs->e1246 * rhs->e57 + lhs->e67 * rhs->e1245 + lhs->e1245 * rhs->e67 
              + lhs->e124 * rhs->e567 + lhs->e125 * rhs->e467 + lhs->e145 * rhs->e267 
              + lhs->e245 * rhs->e167 + lhs->e126 * rhs->e457 + lhs->e146 * rhs->e257 
              + lhs->e246 * rhs->e157 + lhs->e156 * rhs->e247 + lhs->e256 * rhs->e147 
              + lhs->e456 * rhs->e127 + lhs->e127 * rhs->e456 + lhs->e147 * rhs->e256 
              + lhs->e247 * rhs->e156 + lhs->e157 * rhs->e246 + lhs->e257 * rhs->e146 
              + lhs->e457 * rhs->e126 + lhs->e167 * rhs->e245 + lhs->e267 * rhs->e145 
              + lhs->e467 * rhs->e125 + lhs->e567 * rhs->e124;
  res->e134567 =  + lhs->e1 * rhs->e34567 + lhs->e34567 * rhs->e1 + lhs->e3 * rhs->e14567 
              + lhs->e14567 * rhs->e3 + lhs->e4 * rhs->e13567 + lhs->e13567 * rhs->e4 
              + lhs->e5 * rhs->e13467 + lhs->e13467 * rhs->e5 + lhs->e6 * rhs->e13457 
              + lhs->e13457 * rhs->e6 + lhs->e7 * rhs->e13456 + lhs->e13456 * rhs->e7 
              + lhs->e13 * rhs->e4567 + lhs->e4567 * rhs->e13 + lhs->e14 * rhs->e3567 
              + lhs->e3567 * rhs->e14 + lhs->e34 * rhs->e1567 + lhs->e1567 * rhs->e34 
              + lhs->e15 * rhs->e3467 + lhs->e3467 * rhs->e15 + lhs->e35 * rhs->e1467 
              + lhs->e1467 * rhs->e35 + lhs->e45 * rhs->e1367 + lhs->e1367 * rhs->e45 
              + lhs->e16 * rhs->e3457 + lhs->e3457 * rhs->e16 + lhs->e36 * rhs->e1457 
              + lhs->e1457 * rhs->e36 + lhs->e46 * rhs->e1357 + lhs->e1357 * rhs->e46 
              + lhs->e56 * rhs->e1347 + lhs->e1347 * rhs->e56 + lhs->e17 * rhs->e3456 
              + lhs->e3456 * rhs->e17 + lhs->e37 * rhs->e1456 + lhs->e1456 * rhs->e37 
              + lhs->e47 * rhs->e1356 + lhs->e1356 * rhs->e47 + lhs->e57 * rhs->e1346 
              + lhs->e1346 * rhs->e57 + lhs->e67 * rhs->e1345 + lhs->e1345 * rhs->e67 
              + lhs->e134 * rhs->e567 + lhs->e135 * rhs->e467 + lhs->e145 * rhs->e367 
              + lhs->e345 * rhs->e167 + lhs->e136 * rhs->e457 + lhs->e146 * rhs->e357 
              + lhs->e346 * rhs->e157 + lhs->e156 * rhs->e347 + lhs->e356 * rhs->e147 
              + lhs->e456 * rhs->e137 + lhs->e137 * rhs->e456 + lhs->e147 * rhs->e356 
              + lhs->e347 * rhs->e156 + lhs->e157 * rhs->e346 + lhs->e357 * rhs->e146 
              + lhs->e457 * rhs->e136 + lhs->e167 * rhs->e345 + lhs->e367 * rhs->e145 
              + lhs->e467 * rhs->e135 + lhs->e567 * rhs->e134;
  res->e234567 =  + lhs->e2 * rhs->e34567 + lhs->e34567 * rhs->e2 + lhs->e3 * rhs->e24567 
              + lhs->e24567 * rhs->e3 + lhs->e4 * rhs->e23567 + lhs->e23567 * rhs->e4 
              + lhs->e5 * rhs->e23467 + lhs->e23467 * rhs->e5 + lhs->e6 * rhs->e23457 
              + lhs->e23457 * rhs->e6 + lhs->e7 * rhs->e23456 + lhs->e23456 * rhs->e7 
              + lhs->e23 * rhs->e4567 + lhs->e4567 * rhs->e23 + lhs->e24 * rhs->e3567 
              + lhs->e3567 * rhs->e24 + lhs->e34 * rhs->e2567 + lhs->e2567 * rhs->e34 
              + lhs->e25 * rhs->e3467 + lhs->e3467 * rhs->e25 + lhs->e35 * rhs->e2467 
              + lhs->e2467 * rhs->e35 + lhs->e45 * rhs->e2367 + lhs->e2367 * rhs->e45 
              + lhs->e26 * rhs->e3457 + lhs->e3457 * rhs->e26 + lhs->e36 * rhs->e2457 
              + lhs->e2457 * rhs->e36 + lhs->e46 * rhs->e2357 + lhs->e2357 * rhs->e46 
              + lhs->e56 * rhs->e2347 + lhs->e2347 * rhs->e56 + lhs->e27 * rhs->e3456 
              + lhs->e3456 * rhs->e27 + lhs->e37 * rhs->e2456 + lhs->e2456 * rhs->e37 
              + lhs->e47 * rhs->e2356 + lhs->e2356 * rhs->e47 + lhs->e57 * rhs->e2346 
              + lhs->e2346 * rhs->e57 + lhs->e67 * rhs->e2345 + lhs->e2345 * rhs->e67 
              + lhs->e234 * rhs->e567 + lhs->e235 * rhs->e467 + lhs->e245 * rhs->e367 
              + lhs->e345 * rhs->e267 + lhs->e236 * rhs->e457 + lhs->e246 * rhs->e357 
              + lhs->e346 * rhs->e257 + lhs->e256 * rhs->e347 + lhs->e356 * rhs->e247 
              + lhs->e456 * rhs->e237 + lhs->e237 * rhs->e456 + lhs->e247 * rhs->e356 
              + lhs->e347 * rhs->e256 + lhs->e257 * rhs->e346 + lhs->e357 * rhs->e246 
              + lhs->e457 * rhs->e236 + lhs->e267 * rhs->e345 + lhs->e367 * rhs->e245 
              + lhs->e467 * rhs->e235 + lhs->e567 * rhs->e234;
  // Order 7;
  res->e1234567 =  + lhs->e1 * rhs->e234567 + lhs->e234567 * rhs->e1 + lhs->e2 * rhs->e134567 
               + lhs->e134567 * rhs->e2 + lhs->e3 * rhs->e124567 + lhs->e124567 * rhs->e3 
               + lhs->e4 * rhs->e123567 + lhs->e123567 * rhs->e4 + lhs->e5 * rhs->e123467 
               + lhs->e123467 * rhs->e5 + lhs->e6 * rhs->e123457 + lhs->e123457 * rhs->e6 
               + lhs->e7 * rhs->e123456 + lhs->e123456 * rhs->e7 + lhs->e12 * rhs->e34567 
               + lhs->e34567 * rhs->e12 + lhs->e13 * rhs->e24567 + lhs->e24567 * rhs->e13 
               + lhs->e23 * rhs->e14567 + lhs->e14567 * rhs->e23 + lhs->e14 * rhs->e23567 
               + lhs->e23567 * rhs->e14 + lhs->e24 * rhs->e13567 + lhs->e13567 * rhs->e24 
               + lhs->e34 * rhs->e12567 + lhs->e12567 * rhs->e34 + lhs->e15 * rhs->e23467 
               + lhs->e23467 * rhs->e15 + lhs->e25 * rhs->e13467 + lhs->e13467 * rhs->e25 
               + lhs->e35 * rhs->e12467 + lhs->e12467 * rhs->e35 + lhs->e45 * rhs->e12367 
               + lhs->e12367 * rhs->e45 + lhs->e16 * rhs->e23457 + lhs->e23457 * rhs->e16 
               + lhs->e26 * rhs->e13457 + lhs->e13457 * rhs->e26 + lhs->e36 * rhs->e12457 
               + lhs->e12457 * rhs->e36 + lhs->e46 * rhs->e12357 + lhs->e12357 * rhs->e46 
               + lhs->e56 * rhs->e12347 + lhs->e12347 * rhs->e56 + lhs->e17 * rhs->e23456 
               + lhs->e23456 * rhs->e17 + lhs->e27 * rhs->e13456 + lhs->e13456 * rhs->e27 
               + lhs->e37 * rhs->e12456 + lhs->e12456 * rhs->e37 + lhs->e47 * rhs->e12356 
               + lhs->e12356 * rhs->e47 + lhs->e57 * rhs->e12346 + lhs->e12346 * rhs->e57 
               + lhs->e67 * rhs->e12345 + lhs->e12345 * rhs->e67 + lhs->e123 * rhs->e4567 
               + lhs->e4567 * rhs->e123 + lhs->e124 * rhs->e3567 + lhs->e3567 * rhs->e124 
               + lhs->e134 * rhs->e2567 + lhs->e2567 * rhs->e134 + lhs->e234 * rhs->e1567 
               + lhs->e1567 * rhs->e234 + lhs->e125 * rhs->e3467 + lhs->e3467 * rhs->e125 
               + lhs->e135 * rhs->e2467 + lhs->e2467 * rhs->e135 + lhs->e235 * rhs->e1467 
               + lhs->e1467 * rhs->e235 + lhs->e145 * rhs->e2367 + lhs->e2367 * rhs->e145 
               + lhs->e245 * rhs->e1367 + lhs->e1367 * rhs->e245 + lhs->e345 * rhs->e1267 
               + lhs->e1267 * rhs->e345 + lhs->e126 * rhs->e3457 + lhs->e3457 * rhs->e126 
               + lhs->e136 * rhs->e2457 + lhs->e2457 * rhs->e136 + lhs->e236 * rhs->e1457 
               + lhs->e1457 * rhs->e236 + lhs->e146 * rhs->e2357 + lhs->e2357 * rhs->e146 
               + lhs->e246 * rhs->e1357 + lhs->e1357 * rhs->e246 + lhs->e346 * rhs->e1257 
               + lhs->e1257 * rhs->e346 + lhs->e156 * rhs->e2347 + lhs->e2347 * rhs->e156 
               + lhs->e256 * rhs->e1347 + lhs->e1347 * rhs->e256 + lhs->e356 * rhs->e1247 
               + lhs->e1247 * rhs->e356 + lhs->e456 * rhs->e1237 + lhs->e1237 * rhs->e456 
               + lhs->e127 * rhs->e3456 + lhs->e3456 * rhs->e127 + lhs->e137 * rhs->e2456 
               + lhs->e2456 * rhs->e137 + lhs->e237 * rhs->e1456 + lhs->e1456 * rhs->e237 
               + lhs->e147 * rhs->e2356 + lhs->e2356 * rhs->e147 + lhs->e247 * rhs->e1356 
               + lhs->e1356 * rhs->e247 + lhs->e347 * rhs->e1256 + lhs->e1256 * rhs->e347 
               + lhs->e157 * rhs->e2346 + lhs->e2346 * rhs->e157 + lhs->e257 * rhs->e1346 
               + lhs->e1346 * rhs->e257 + lhs->e357 * rhs->e1246 + lhs->e1246 * rhs->e357 
               + lhs->e457 * rhs->e1236 + lhs->e1236 * rhs->e457 + lhs->e167 * rhs->e2345 
               + lhs->e2345 * rhs->e167 + lhs->e267 * rhs->e1345 + lhs->e1345 * rhs->e267 
               + lhs->e367 * rhs->e1245 + lhs->e1245 * rhs->e367 + lhs->e467 * rhs->e1235 
               + lhs->e1235 * rhs->e467 + lhs->e567 * rhs->e1234 + lhs->e1234 * rhs->e567;

}

mdnum7_t mdnum7_gem_oo(  mdnum7_t* a,  mdnum7_t* b,  mdnum7_t* c){
  mdnum7_t res;

  //  General multiplication like function 'a * b + c'
  // Real;
  res.r = c->r + a->r * b->r;
  // Order 1;
  res.e1 = c->e1 + a->r * b->e1 + a->e1 * b->r;
  res.e2 = c->e2 + a->r * b->e2 + a->e2 * b->r;
  res.e3 = c->e3 + a->r * b->e3 + a->e3 * b->r;
  res.e4 = c->e4 + a->r * b->e4 + a->e4 * b->r;
  res.e5 = c->e5 + a->r * b->e5 + a->e5 * b->r;
  res.e6 = c->e6 + a->r * b->e6 + a->e6 * b->r;
  res.e7 = c->e7 + a->r * b->e7 + a->e7 * b->r;
  // Order 2;
  res.e12 = c->e12 + a->r * b->e12 + a->e12 * b->r + a->e1 * b->e2 
          + a->e2 * b->e1;
  res.e13 = c->e13 + a->r * b->e13 + a->e13 * b->r + a->e1 * b->e3 
          + a->e3 * b->e1;
  res.e23 = c->e23 + a->r * b->e23 + a->e23 * b->r + a->e2 * b->e3 
          + a->e3 * b->e2;
  res.e14 = c->e14 + a->r * b->e14 + a->e14 * b->r + a->e1 * b->e4 
          + a->e4 * b->e1;
  res.e24 = c->e24 + a->r * b->e24 + a->e24 * b->r + a->e2 * b->e4 
          + a->e4 * b->e2;
  res.e34 = c->e34 + a->r * b->e34 + a->e34 * b->r + a->e3 * b->e4 
          + a->e4 * b->e3;
  res.e15 = c->e15 + a->r * b->e15 + a->e15 * b->r + a->e1 * b->e5 
          + a->e5 * b->e1;
  res.e25 = c->e25 + a->r * b->e25 + a->e25 * b->r + a->e2 * b->e5 
          + a->e5 * b->e2;
  res.e35 = c->e35 + a->r * b->e35 + a->e35 * b->r + a->e3 * b->e5 
          + a->e5 * b->e3;
  res.e45 = c->e45 + a->r * b->e45 + a->e45 * b->r + a->e4 * b->e5 
          + a->e5 * b->e4;
  res.e16 = c->e16 + a->r * b->e16 + a->e16 * b->r + a->e1 * b->e6 
          + a->e6 * b->e1;
  res.e26 = c->e26 + a->r * b->e26 + a->e26 * b->r + a->e2 * b->e6 
          + a->e6 * b->e2;
  res.e36 = c->e36 + a->r * b->e36 + a->e36 * b->r + a->e3 * b->e6 
          + a->e6 * b->e3;
  res.e46 = c->e46 + a->r * b->e46 + a->e46 * b->r + a->e4 * b->e6 
          + a->e6 * b->e4;
  res.e56 = c->e56 + a->r * b->e56 + a->e56 * b->r + a->e5 * b->e6 
          + a->e6 * b->e5;
  res.e17 = c->e17 + a->r * b->e17 + a->e17 * b->r + a->e1 * b->e7 
          + a->e7 * b->e1;
  res.e27 = c->e27 + a->r * b->e27 + a->e27 * b->r + a->e2 * b->e7 
          + a->e7 * b->e2;
  res.e37 = c->e37 + a->r * b->e37 + a->e37 * b->r + a->e3 * b->e7 
          + a->e7 * b->e3;
  res.e47 = c->e47 + a->r * b->e47 + a->e47 * b->r + a->e4 * b->e7 
          + a->e7 * b->e4;
  res.e57 = c->e57 + a->r * b->e57 + a->e57 * b->r + a->e5 * b->e7 
          + a->e7 * b->e5;
  res.e67 = c->e67 + a->r * b->e67 + a->e67 * b->r + a->e6 * b->e7 
          + a->e7 * b->e6;
  // Order 3;
  res.e123 = c->e123 + a->r * b->e123 + a->e123 * b->r + a->e1 * b->e23 
           + a->e23 * b->e1 + a->e2 * b->e13 + a->e13 * b->e2 
           + a->e3 * b->e12 + a->e12 * b->e3;
  res.e124 = c->e124 + a->r * b->e124 + a->e124 * b->r + a->e1 * b->e24 
           + a->e24 * b->e1 + a->e2 * b->e14 + a->e14 * b->e2 
           + a->e4 * b->e12 + a->e12 * b->e4;
  res.e134 = c->e134 + a->r * b->e134 + a->e134 * b->r + a->e1 * b->e34 
           + a->e34 * b->e1 + a->e3 * b->e14 + a->e14 * b->e3 
           + a->e4 * b->e13 + a->e13 * b->e4;
  res.e234 = c->e234 + a->r * b->e234 + a->e234 * b->r + a->e2 * b->e34 
           + a->e34 * b->e2 + a->e3 * b->e24 + a->e24 * b->e3 
           + a->e4 * b->e23 + a->e23 * b->e4;
  res.e125 = c->e125 + a->r * b->e125 + a->e125 * b->r + a->e1 * b->e25 
           + a->e25 * b->e1 + a->e2 * b->e15 + a->e15 * b->e2 
           + a->e5 * b->e12 + a->e12 * b->e5;
  res.e135 = c->e135 + a->r * b->e135 + a->e135 * b->r + a->e1 * b->e35 
           + a->e35 * b->e1 + a->e3 * b->e15 + a->e15 * b->e3 
           + a->e5 * b->e13 + a->e13 * b->e5;
  res.e235 = c->e235 + a->r * b->e235 + a->e235 * b->r + a->e2 * b->e35 
           + a->e35 * b->e2 + a->e3 * b->e25 + a->e25 * b->e3 
           + a->e5 * b->e23 + a->e23 * b->e5;
  res.e145 = c->e145 + a->r * b->e145 + a->e145 * b->r + a->e1 * b->e45 
           + a->e45 * b->e1 + a->e4 * b->e15 + a->e15 * b->e4 
           + a->e5 * b->e14 + a->e14 * b->e5;
  res.e245 = c->e245 + a->r * b->e245 + a->e245 * b->r + a->e2 * b->e45 
           + a->e45 * b->e2 + a->e4 * b->e25 + a->e25 * b->e4 
           + a->e5 * b->e24 + a->e24 * b->e5;
  res.e345 = c->e345 + a->r * b->e345 + a->e345 * b->r + a->e3 * b->e45 
           + a->e45 * b->e3 + a->e4 * b->e35 + a->e35 * b->e4 
           + a->e5 * b->e34 + a->e34 * b->e5;
  res.e126 = c->e126 + a->r * b->e126 + a->e126 * b->r + a->e1 * b->e26 
           + a->e26 * b->e1 + a->e2 * b->e16 + a->e16 * b->e2 
           + a->e6 * b->e12 + a->e12 * b->e6;
  res.e136 = c->e136 + a->r * b->e136 + a->e136 * b->r + a->e1 * b->e36 
           + a->e36 * b->e1 + a->e3 * b->e16 + a->e16 * b->e3 
           + a->e6 * b->e13 + a->e13 * b->e6;
  res.e236 = c->e236 + a->r * b->e236 + a->e236 * b->r + a->e2 * b->e36 
           + a->e36 * b->e2 + a->e3 * b->e26 + a->e26 * b->e3 
           + a->e6 * b->e23 + a->e23 * b->e6;
  res.e146 = c->e146 + a->r * b->e146 + a->e146 * b->r + a->e1 * b->e46 
           + a->e46 * b->e1 + a->e4 * b->e16 + a->e16 * b->e4 
           + a->e6 * b->e14 + a->e14 * b->e6;
  res.e246 = c->e246 + a->r * b->e246 + a->e246 * b->r + a->e2 * b->e46 
           + a->e46 * b->e2 + a->e4 * b->e26 + a->e26 * b->e4 
           + a->e6 * b->e24 + a->e24 * b->e6;
  res.e346 = c->e346 + a->r * b->e346 + a->e346 * b->r + a->e3 * b->e46 
           + a->e46 * b->e3 + a->e4 * b->e36 + a->e36 * b->e4 
           + a->e6 * b->e34 + a->e34 * b->e6;
  res.e156 = c->e156 + a->r * b->e156 + a->e156 * b->r + a->e1 * b->e56 
           + a->e56 * b->e1 + a->e5 * b->e16 + a->e16 * b->e5 
           + a->e6 * b->e15 + a->e15 * b->e6;
  res.e256 = c->e256 + a->r * b->e256 + a->e256 * b->r + a->e2 * b->e56 
           + a->e56 * b->e2 + a->e5 * b->e26 + a->e26 * b->e5 
           + a->e6 * b->e25 + a->e25 * b->e6;
  res.e356 = c->e356 + a->r * b->e356 + a->e356 * b->r + a->e3 * b->e56 
           + a->e56 * b->e3 + a->e5 * b->e36 + a->e36 * b->e5 
           + a->e6 * b->e35 + a->e35 * b->e6;
  res.e456 = c->e456 + a->r * b->e456 + a->e456 * b->r + a->e4 * b->e56 
           + a->e56 * b->e4 + a->e5 * b->e46 + a->e46 * b->e5 
           + a->e6 * b->e45 + a->e45 * b->e6;
  res.e127 = c->e127 + a->r * b->e127 + a->e127 * b->r + a->e1 * b->e27 
           + a->e27 * b->e1 + a->e2 * b->e17 + a->e17 * b->e2 
           + a->e7 * b->e12 + a->e12 * b->e7;
  res.e137 = c->e137 + a->r * b->e137 + a->e137 * b->r + a->e1 * b->e37 
           + a->e37 * b->e1 + a->e3 * b->e17 + a->e17 * b->e3 
           + a->e7 * b->e13 + a->e13 * b->e7;
  res.e237 = c->e237 + a->r * b->e237 + a->e237 * b->r + a->e2 * b->e37 
           + a->e37 * b->e2 + a->e3 * b->e27 + a->e27 * b->e3 
           + a->e7 * b->e23 + a->e23 * b->e7;
  res.e147 = c->e147 + a->r * b->e147 + a->e147 * b->r + a->e1 * b->e47 
           + a->e47 * b->e1 + a->e4 * b->e17 + a->e17 * b->e4 
           + a->e7 * b->e14 + a->e14 * b->e7;
  res.e247 = c->e247 + a->r * b->e247 + a->e247 * b->r + a->e2 * b->e47 
           + a->e47 * b->e2 + a->e4 * b->e27 + a->e27 * b->e4 
           + a->e7 * b->e24 + a->e24 * b->e7;
  res.e347 = c->e347 + a->r * b->e347 + a->e347 * b->r + a->e3 * b->e47 
           + a->e47 * b->e3 + a->e4 * b->e37 + a->e37 * b->e4 
           + a->e7 * b->e34 + a->e34 * b->e7;
  res.e157 = c->e157 + a->r * b->e157 + a->e157 * b->r + a->e1 * b->e57 
           + a->e57 * b->e1 + a->e5 * b->e17 + a->e17 * b->e5 
           + a->e7 * b->e15 + a->e15 * b->e7;
  res.e257 = c->e257 + a->r * b->e257 + a->e257 * b->r + a->e2 * b->e57 
           + a->e57 * b->e2 + a->e5 * b->e27 + a->e27 * b->e5 
           + a->e7 * b->e25 + a->e25 * b->e7;
  res.e357 = c->e357 + a->r * b->e357 + a->e357 * b->r + a->e3 * b->e57 
           + a->e57 * b->e3 + a->e5 * b->e37 + a->e37 * b->e5 
           + a->e7 * b->e35 + a->e35 * b->e7;
  res.e457 = c->e457 + a->r * b->e457 + a->e457 * b->r + a->e4 * b->e57 
           + a->e57 * b->e4 + a->e5 * b->e47 + a->e47 * b->e5 
           + a->e7 * b->e45 + a->e45 * b->e7;
  res.e167 = c->e167 + a->r * b->e167 + a->e167 * b->r + a->e1 * b->e67 
           + a->e67 * b->e1 + a->e6 * b->e17 + a->e17 * b->e6 
           + a->e7 * b->e16 + a->e16 * b->e7;
  res.e267 = c->e267 + a->r * b->e267 + a->e267 * b->r + a->e2 * b->e67 
           + a->e67 * b->e2 + a->e6 * b->e27 + a->e27 * b->e6 
           + a->e7 * b->e26 + a->e26 * b->e7;
  res.e367 = c->e367 + a->r * b->e367 + a->e367 * b->r + a->e3 * b->e67 
           + a->e67 * b->e3 + a->e6 * b->e37 + a->e37 * b->e6 
           + a->e7 * b->e36 + a->e36 * b->e7;
  res.e467 = c->e467 + a->r * b->e467 + a->e467 * b->r + a->e4 * b->e67 
           + a->e67 * b->e4 + a->e6 * b->e47 + a->e47 * b->e6 
           + a->e7 * b->e46 + a->e46 * b->e7;
  res.e567 = c->e567 + a->r * b->e567 + a->e567 * b->r + a->e5 * b->e67 
           + a->e67 * b->e5 + a->e6 * b->e57 + a->e57 * b->e6 
           + a->e7 * b->e56 + a->e56 * b->e7;
  // Order 4;
  res.e1234 = c->e1234 + a->r * b->e1234 + a->e1234 * b->r + a->e1 * b->e234 
            + a->e234 * b->e1 + a->e2 * b->e134 + a->e134 * b->e2 
            + a->e3 * b->e124 + a->e124 * b->e3 + a->e4 * b->e123 
            + a->e123 * b->e4 + a->e12 * b->e34 + a->e13 * b->e24 
            + a->e23 * b->e14 + a->e14 * b->e23 + a->e24 * b->e13 
            + a->e34 * b->e12;
  res.e1235 = c->e1235 + a->r * b->e1235 + a->e1235 * b->r + a->e1 * b->e235 
            + a->e235 * b->e1 + a->e2 * b->e135 + a->e135 * b->e2 
            + a->e3 * b->e125 + a->e125 * b->e3 + a->e5 * b->e123 
            + a->e123 * b->e5 + a->e12 * b->e35 + a->e13 * b->e25 
            + a->e23 * b->e15 + a->e15 * b->e23 + a->e25 * b->e13 
            + a->e35 * b->e12;
  res.e1245 = c->e1245 + a->r * b->e1245 + a->e1245 * b->r + a->e1 * b->e245 
            + a->e245 * b->e1 + a->e2 * b->e145 + a->e145 * b->e2 
            + a->e4 * b->e125 + a->e125 * b->e4 + a->e5 * b->e124 
            + a->e124 * b->e5 + a->e12 * b->e45 + a->e14 * b->e25 
            + a->e24 * b->e15 + a->e15 * b->e24 + a->e25 * b->e14 
            + a->e45 * b->e12;
  res.e1345 = c->e1345 + a->r * b->e1345 + a->e1345 * b->r + a->e1 * b->e345 
            + a->e345 * b->e1 + a->e3 * b->e145 + a->e145 * b->e3 
            + a->e4 * b->e135 + a->e135 * b->e4 + a->e5 * b->e134 
            + a->e134 * b->e5 + a->e13 * b->e45 + a->e14 * b->e35 
            + a->e34 * b->e15 + a->e15 * b->e34 + a->e35 * b->e14 
            + a->e45 * b->e13;
  res.e2345 = c->e2345 + a->r * b->e2345 + a->e2345 * b->r + a->e2 * b->e345 
            + a->e345 * b->e2 + a->e3 * b->e245 + a->e245 * b->e3 
            + a->e4 * b->e235 + a->e235 * b->e4 + a->e5 * b->e234 
            + a->e234 * b->e5 + a->e23 * b->e45 + a->e24 * b->e35 
            + a->e34 * b->e25 + a->e25 * b->e34 + a->e35 * b->e24 
            + a->e45 * b->e23;
  res.e1236 = c->e1236 + a->r * b->e1236 + a->e1236 * b->r + a->e1 * b->e236 
            + a->e236 * b->e1 + a->e2 * b->e136 + a->e136 * b->e2 
            + a->e3 * b->e126 + a->e126 * b->e3 + a->e6 * b->e123 
            + a->e123 * b->e6 + a->e12 * b->e36 + a->e13 * b->e26 
            + a->e23 * b->e16 + a->e16 * b->e23 + a->e26 * b->e13 
            + a->e36 * b->e12;
  res.e1246 = c->e1246 + a->r * b->e1246 + a->e1246 * b->r + a->e1 * b->e246 
            + a->e246 * b->e1 + a->e2 * b->e146 + a->e146 * b->e2 
            + a->e4 * b->e126 + a->e126 * b->e4 + a->e6 * b->e124 
            + a->e124 * b->e6 + a->e12 * b->e46 + a->e14 * b->e26 
            + a->e24 * b->e16 + a->e16 * b->e24 + a->e26 * b->e14 
            + a->e46 * b->e12;
  res.e1346 = c->e1346 + a->r * b->e1346 + a->e1346 * b->r + a->e1 * b->e346 
            + a->e346 * b->e1 + a->e3 * b->e146 + a->e146 * b->e3 
            + a->e4 * b->e136 + a->e136 * b->e4 + a->e6 * b->e134 
            + a->e134 * b->e6 + a->e13 * b->e46 + a->e14 * b->e36 
            + a->e34 * b->e16 + a->e16 * b->e34 + a->e36 * b->e14 
            + a->e46 * b->e13;
  res.e2346 = c->e2346 + a->r * b->e2346 + a->e2346 * b->r + a->e2 * b->e346 
            + a->e346 * b->e2 + a->e3 * b->e246 + a->e246 * b->e3 
            + a->e4 * b->e236 + a->e236 * b->e4 + a->e6 * b->e234 
            + a->e234 * b->e6 + a->e23 * b->e46 + a->e24 * b->e36 
            + a->e34 * b->e26 + a->e26 * b->e34 + a->e36 * b->e24 
            + a->e46 * b->e23;
  res.e1256 = c->e1256 + a->r * b->e1256 + a->e1256 * b->r + a->e1 * b->e256 
            + a->e256 * b->e1 + a->e2 * b->e156 + a->e156 * b->e2 
            + a->e5 * b->e126 + a->e126 * b->e5 + a->e6 * b->e125 
            + a->e125 * b->e6 + a->e12 * b->e56 + a->e15 * b->e26 
            + a->e25 * b->e16 + a->e16 * b->e25 + a->e26 * b->e15 
            + a->e56 * b->e12;
  res.e1356 = c->e1356 + a->r * b->e1356 + a->e1356 * b->r + a->e1 * b->e356 
            + a->e356 * b->e1 + a->e3 * b->e156 + a->e156 * b->e3 
            + a->e5 * b->e136 + a->e136 * b->e5 + a->e6 * b->e135 
            + a->e135 * b->e6 + a->e13 * b->e56 + a->e15 * b->e36 
            + a->e35 * b->e16 + a->e16 * b->e35 + a->e36 * b->e15 
            + a->e56 * b->e13;
  res.e2356 = c->e2356 + a->r * b->e2356 + a->e2356 * b->r + a->e2 * b->e356 
            + a->e356 * b->e2 + a->e3 * b->e256 + a->e256 * b->e3 
            + a->e5 * b->e236 + a->e236 * b->e5 + a->e6 * b->e235 
            + a->e235 * b->e6 + a->e23 * b->e56 + a->e25 * b->e36 
            + a->e35 * b->e26 + a->e26 * b->e35 + a->e36 * b->e25 
            + a->e56 * b->e23;
  res.e1456 = c->e1456 + a->r * b->e1456 + a->e1456 * b->r + a->e1 * b->e456 
            + a->e456 * b->e1 + a->e4 * b->e156 + a->e156 * b->e4 
            + a->e5 * b->e146 + a->e146 * b->e5 + a->e6 * b->e145 
            + a->e145 * b->e6 + a->e14 * b->e56 + a->e15 * b->e46 
            + a->e45 * b->e16 + a->e16 * b->e45 + a->e46 * b->e15 
            + a->e56 * b->e14;
  res.e2456 = c->e2456 + a->r * b->e2456 + a->e2456 * b->r + a->e2 * b->e456 
            + a->e456 * b->e2 + a->e4 * b->e256 + a->e256 * b->e4 
            + a->e5 * b->e246 + a->e246 * b->e5 + a->e6 * b->e245 
            + a->e245 * b->e6 + a->e24 * b->e56 + a->e25 * b->e46 
            + a->e45 * b->e26 + a->e26 * b->e45 + a->e46 * b->e25 
            + a->e56 * b->e24;
  res.e3456 = c->e3456 + a->r * b->e3456 + a->e3456 * b->r + a->e3 * b->e456 
            + a->e456 * b->e3 + a->e4 * b->e356 + a->e356 * b->e4 
            + a->e5 * b->e346 + a->e346 * b->e5 + a->e6 * b->e345 
            + a->e345 * b->e6 + a->e34 * b->e56 + a->e35 * b->e46 
            + a->e45 * b->e36 + a->e36 * b->e45 + a->e46 * b->e35 
            + a->e56 * b->e34;
  res.e1237 = c->e1237 + a->r * b->e1237 + a->e1237 * b->r + a->e1 * b->e237 
            + a->e237 * b->e1 + a->e2 * b->e137 + a->e137 * b->e2 
            + a->e3 * b->e127 + a->e127 * b->e3 + a->e7 * b->e123 
            + a->e123 * b->e7 + a->e12 * b->e37 + a->e13 * b->e27 
            + a->e23 * b->e17 + a->e17 * b->e23 + a->e27 * b->e13 
            + a->e37 * b->e12;
  res.e1247 = c->e1247 + a->r * b->e1247 + a->e1247 * b->r + a->e1 * b->e247 
            + a->e247 * b->e1 + a->e2 * b->e147 + a->e147 * b->e2 
            + a->e4 * b->e127 + a->e127 * b->e4 + a->e7 * b->e124 
            + a->e124 * b->e7 + a->e12 * b->e47 + a->e14 * b->e27 
            + a->e24 * b->e17 + a->e17 * b->e24 + a->e27 * b->e14 
            + a->e47 * b->e12;
  res.e1347 = c->e1347 + a->r * b->e1347 + a->e1347 * b->r + a->e1 * b->e347 
            + a->e347 * b->e1 + a->e3 * b->e147 + a->e147 * b->e3 
            + a->e4 * b->e137 + a->e137 * b->e4 + a->e7 * b->e134 
            + a->e134 * b->e7 + a->e13 * b->e47 + a->e14 * b->e37 
            + a->e34 * b->e17 + a->e17 * b->e34 + a->e37 * b->e14 
            + a->e47 * b->e13;
  res.e2347 = c->e2347 + a->r * b->e2347 + a->e2347 * b->r + a->e2 * b->e347 
            + a->e347 * b->e2 + a->e3 * b->e247 + a->e247 * b->e3 
            + a->e4 * b->e237 + a->e237 * b->e4 + a->e7 * b->e234 
            + a->e234 * b->e7 + a->e23 * b->e47 + a->e24 * b->e37 
            + a->e34 * b->e27 + a->e27 * b->e34 + a->e37 * b->e24 
            + a->e47 * b->e23;
  res.e1257 = c->e1257 + a->r * b->e1257 + a->e1257 * b->r + a->e1 * b->e257 
            + a->e257 * b->e1 + a->e2 * b->e157 + a->e157 * b->e2 
            + a->e5 * b->e127 + a->e127 * b->e5 + a->e7 * b->e125 
            + a->e125 * b->e7 + a->e12 * b->e57 + a->e15 * b->e27 
            + a->e25 * b->e17 + a->e17 * b->e25 + a->e27 * b->e15 
            + a->e57 * b->e12;
  res.e1357 = c->e1357 + a->r * b->e1357 + a->e1357 * b->r + a->e1 * b->e357 
            + a->e357 * b->e1 + a->e3 * b->e157 + a->e157 * b->e3 
            + a->e5 * b->e137 + a->e137 * b->e5 + a->e7 * b->e135 
            + a->e135 * b->e7 + a->e13 * b->e57 + a->e15 * b->e37 
            + a->e35 * b->e17 + a->e17 * b->e35 + a->e37 * b->e15 
            + a->e57 * b->e13;
  res.e2357 = c->e2357 + a->r * b->e2357 + a->e2357 * b->r + a->e2 * b->e357 
            + a->e357 * b->e2 + a->e3 * b->e257 + a->e257 * b->e3 
            + a->e5 * b->e237 + a->e237 * b->e5 + a->e7 * b->e235 
            + a->e235 * b->e7 + a->e23 * b->e57 + a->e25 * b->e37 
            + a->e35 * b->e27 + a->e27 * b->e35 + a->e37 * b->e25 
            + a->e57 * b->e23;
  res.e1457 = c->e1457 + a->r * b->e1457 + a->e1457 * b->r + a->e1 * b->e457 
            + a->e457 * b->e1 + a->e4 * b->e157 + a->e157 * b->e4 
            + a->e5 * b->e147 + a->e147 * b->e5 + a->e7 * b->e145 
            + a->e145 * b->e7 + a->e14 * b->e57 + a->e15 * b->e47 
            + a->e45 * b->e17 + a->e17 * b->e45 + a->e47 * b->e15 
            + a->e57 * b->e14;
  res.e2457 = c->e2457 + a->r * b->e2457 + a->e2457 * b->r + a->e2 * b->e457 
            + a->e457 * b->e2 + a->e4 * b->e257 + a->e257 * b->e4 
            + a->e5 * b->e247 + a->e247 * b->e5 + a->e7 * b->e245 
            + a->e245 * b->e7 + a->e24 * b->e57 + a->e25 * b->e47 
            + a->e45 * b->e27 + a->e27 * b->e45 + a->e47 * b->e25 
            + a->e57 * b->e24;
  res.e3457 = c->e3457 + a->r * b->e3457 + a->e3457 * b->r + a->e3 * b->e457 
            + a->e457 * b->e3 + a->e4 * b->e357 + a->e357 * b->e4 
            + a->e5 * b->e347 + a->e347 * b->e5 + a->e7 * b->e345 
            + a->e345 * b->e7 + a->e34 * b->e57 + a->e35 * b->e47 
            + a->e45 * b->e37 + a->e37 * b->e45 + a->e47 * b->e35 
            + a->e57 * b->e34;
  res.e1267 = c->e1267 + a->r * b->e1267 + a->e1267 * b->r + a->e1 * b->e267 
            + a->e267 * b->e1 + a->e2 * b->e167 + a->e167 * b->e2 
            + a->e6 * b->e127 + a->e127 * b->e6 + a->e7 * b->e126 
            + a->e126 * b->e7 + a->e12 * b->e67 + a->e16 * b->e27 
            + a->e26 * b->e17 + a->e17 * b->e26 + a->e27 * b->e16 
            + a->e67 * b->e12;
  res.e1367 = c->e1367 + a->r * b->e1367 + a->e1367 * b->r + a->e1 * b->e367 
            + a->e367 * b->e1 + a->e3 * b->e167 + a->e167 * b->e3 
            + a->e6 * b->e137 + a->e137 * b->e6 + a->e7 * b->e136 
            + a->e136 * b->e7 + a->e13 * b->e67 + a->e16 * b->e37 
            + a->e36 * b->e17 + a->e17 * b->e36 + a->e37 * b->e16 
            + a->e67 * b->e13;
  res.e2367 = c->e2367 + a->r * b->e2367 + a->e2367 * b->r + a->e2 * b->e367 
            + a->e367 * b->e2 + a->e3 * b->e267 + a->e267 * b->e3 
            + a->e6 * b->e237 + a->e237 * b->e6 + a->e7 * b->e236 
            + a->e236 * b->e7 + a->e23 * b->e67 + a->e26 * b->e37 
            + a->e36 * b->e27 + a->e27 * b->e36 + a->e37 * b->e26 
            + a->e67 * b->e23;
  res.e1467 = c->e1467 + a->r * b->e1467 + a->e1467 * b->r + a->e1 * b->e467 
            + a->e467 * b->e1 + a->e4 * b->e167 + a->e167 * b->e4 
            + a->e6 * b->e147 + a->e147 * b->e6 + a->e7 * b->e146 
            + a->e146 * b->e7 + a->e14 * b->e67 + a->e16 * b->e47 
            + a->e46 * b->e17 + a->e17 * b->e46 + a->e47 * b->e16 
            + a->e67 * b->e14;
  res.e2467 = c->e2467 + a->r * b->e2467 + a->e2467 * b->r + a->e2 * b->e467 
            + a->e467 * b->e2 + a->e4 * b->e267 + a->e267 * b->e4 
            + a->e6 * b->e247 + a->e247 * b->e6 + a->e7 * b->e246 
            + a->e246 * b->e7 + a->e24 * b->e67 + a->e26 * b->e47 
            + a->e46 * b->e27 + a->e27 * b->e46 + a->e47 * b->e26 
            + a->e67 * b->e24;
  res.e3467 = c->e3467 + a->r * b->e3467 + a->e3467 * b->r + a->e3 * b->e467 
            + a->e467 * b->e3 + a->e4 * b->e367 + a->e367 * b->e4 
            + a->e6 * b->e347 + a->e347 * b->e6 + a->e7 * b->e346 
            + a->e346 * b->e7 + a->e34 * b->e67 + a->e36 * b->e47 
            + a->e46 * b->e37 + a->e37 * b->e46 + a->e47 * b->e36 
            + a->e67 * b->e34;
  res.e1567 = c->e1567 + a->r * b->e1567 + a->e1567 * b->r + a->e1 * b->e567 
            + a->e567 * b->e1 + a->e5 * b->e167 + a->e167 * b->e5 
            + a->e6 * b->e157 + a->e157 * b->e6 + a->e7 * b->e156 
            + a->e156 * b->e7 + a->e15 * b->e67 + a->e16 * b->e57 
            + a->e56 * b->e17 + a->e17 * b->e56 + a->e57 * b->e16 
            + a->e67 * b->e15;
  res.e2567 = c->e2567 + a->r * b->e2567 + a->e2567 * b->r + a->e2 * b->e567 
            + a->e567 * b->e2 + a->e5 * b->e267 + a->e267 * b->e5 
            + a->e6 * b->e257 + a->e257 * b->e6 + a->e7 * b->e256 
            + a->e256 * b->e7 + a->e25 * b->e67 + a->e26 * b->e57 
            + a->e56 * b->e27 + a->e27 * b->e56 + a->e57 * b->e26 
            + a->e67 * b->e25;
  res.e3567 = c->e3567 + a->r * b->e3567 + a->e3567 * b->r + a->e3 * b->e567 
            + a->e567 * b->e3 + a->e5 * b->e367 + a->e367 * b->e5 
            + a->e6 * b->e357 + a->e357 * b->e6 + a->e7 * b->e356 
            + a->e356 * b->e7 + a->e35 * b->e67 + a->e36 * b->e57 
            + a->e56 * b->e37 + a->e37 * b->e56 + a->e57 * b->e36 
            + a->e67 * b->e35;
  res.e4567 = c->e4567 + a->r * b->e4567 + a->e4567 * b->r + a->e4 * b->e567 
            + a->e567 * b->e4 + a->e5 * b->e467 + a->e467 * b->e5 
            + a->e6 * b->e457 + a->e457 * b->e6 + a->e7 * b->e456 
            + a->e456 * b->e7 + a->e45 * b->e67 + a->e46 * b->e57 
            + a->e56 * b->e47 + a->e47 * b->e56 + a->e57 * b->e46 
            + a->e67 * b->e45;
  // Order 5;
  res.e12345 = c->e12345 + a->r * b->e12345 + a->e12345 * b->r + a->e1 * b->e2345 
             + a->e2345 * b->e1 + a->e2 * b->e1345 + a->e1345 * b->e2 
             + a->e3 * b->e1245 + a->e1245 * b->e3 + a->e4 * b->e1235 
             + a->e1235 * b->e4 + a->e5 * b->e1234 + a->e1234 * b->e5 
             + a->e12 * b->e345 + a->e345 * b->e12 + a->e13 * b->e245 
             + a->e245 * b->e13 + a->e23 * b->e145 + a->e145 * b->e23 
             + a->e14 * b->e235 + a->e235 * b->e14 + a->e24 * b->e135 
             + a->e135 * b->e24 + a->e34 * b->e125 + a->e125 * b->e34 
             + a->e15 * b->e234 + a->e234 * b->e15 + a->e25 * b->e134 
             + a->e134 * b->e25 + a->e35 * b->e124 + a->e124 * b->e35 
             + a->e45 * b->e123 + a->e123 * b->e45;
  res.e12346 = c->e12346 + a->r * b->e12346 + a->e12346 * b->r + a->e1 * b->e2346 
             + a->e2346 * b->e1 + a->e2 * b->e1346 + a->e1346 * b->e2 
             + a->e3 * b->e1246 + a->e1246 * b->e3 + a->e4 * b->e1236 
             + a->e1236 * b->e4 + a->e6 * b->e1234 + a->e1234 * b->e6 
             + a->e12 * b->e346 + a->e346 * b->e12 + a->e13 * b->e246 
             + a->e246 * b->e13 + a->e23 * b->e146 + a->e146 * b->e23 
             + a->e14 * b->e236 + a->e236 * b->e14 + a->e24 * b->e136 
             + a->e136 * b->e24 + a->e34 * b->e126 + a->e126 * b->e34 
             + a->e16 * b->e234 + a->e234 * b->e16 + a->e26 * b->e134 
             + a->e134 * b->e26 + a->e36 * b->e124 + a->e124 * b->e36 
             + a->e46 * b->e123 + a->e123 * b->e46;
  res.e12356 = c->e12356 + a->r * b->e12356 + a->e12356 * b->r + a->e1 * b->e2356 
             + a->e2356 * b->e1 + a->e2 * b->e1356 + a->e1356 * b->e2 
             + a->e3 * b->e1256 + a->e1256 * b->e3 + a->e5 * b->e1236 
             + a->e1236 * b->e5 + a->e6 * b->e1235 + a->e1235 * b->e6 
             + a->e12 * b->e356 + a->e356 * b->e12 + a->e13 * b->e256 
             + a->e256 * b->e13 + a->e23 * b->e156 + a->e156 * b->e23 
             + a->e15 * b->e236 + a->e236 * b->e15 + a->e25 * b->e136 
             + a->e136 * b->e25 + a->e35 * b->e126 + a->e126 * b->e35 
             + a->e16 * b->e235 + a->e235 * b->e16 + a->e26 * b->e135 
             + a->e135 * b->e26 + a->e36 * b->e125 + a->e125 * b->e36 
             + a->e56 * b->e123 + a->e123 * b->e56;
  res.e12456 = c->e12456 + a->r * b->e12456 + a->e12456 * b->r + a->e1 * b->e2456 
             + a->e2456 * b->e1 + a->e2 * b->e1456 + a->e1456 * b->e2 
             + a->e4 * b->e1256 + a->e1256 * b->e4 + a->e5 * b->e1246 
             + a->e1246 * b->e5 + a->e6 * b->e1245 + a->e1245 * b->e6 
             + a->e12 * b->e456 + a->e456 * b->e12 + a->e14 * b->e256 
             + a->e256 * b->e14 + a->e24 * b->e156 + a->e156 * b->e24 
             + a->e15 * b->e246 + a->e246 * b->e15 + a->e25 * b->e146 
             + a->e146 * b->e25 + a->e45 * b->e126 + a->e126 * b->e45 
             + a->e16 * b->e245 + a->e245 * b->e16 + a->e26 * b->e145 
             + a->e145 * b->e26 + a->e46 * b->e125 + a->e125 * b->e46 
             + a->e56 * b->e124 + a->e124 * b->e56;
  res.e13456 = c->e13456 + a->r * b->e13456 + a->e13456 * b->r + a->e1 * b->e3456 
             + a->e3456 * b->e1 + a->e3 * b->e1456 + a->e1456 * b->e3 
             + a->e4 * b->e1356 + a->e1356 * b->e4 + a->e5 * b->e1346 
             + a->e1346 * b->e5 + a->e6 * b->e1345 + a->e1345 * b->e6 
             + a->e13 * b->e456 + a->e456 * b->e13 + a->e14 * b->e356 
             + a->e356 * b->e14 + a->e34 * b->e156 + a->e156 * b->e34 
             + a->e15 * b->e346 + a->e346 * b->e15 + a->e35 * b->e146 
             + a->e146 * b->e35 + a->e45 * b->e136 + a->e136 * b->e45 
             + a->e16 * b->e345 + a->e345 * b->e16 + a->e36 * b->e145 
             + a->e145 * b->e36 + a->e46 * b->e135 + a->e135 * b->e46 
             + a->e56 * b->e134 + a->e134 * b->e56;
  res.e23456 = c->e23456 + a->r * b->e23456 + a->e23456 * b->r + a->e2 * b->e3456 
             + a->e3456 * b->e2 + a->e3 * b->e2456 + a->e2456 * b->e3 
             + a->e4 * b->e2356 + a->e2356 * b->e4 + a->e5 * b->e2346 
             + a->e2346 * b->e5 + a->e6 * b->e2345 + a->e2345 * b->e6 
             + a->e23 * b->e456 + a->e456 * b->e23 + a->e24 * b->e356 
             + a->e356 * b->e24 + a->e34 * b->e256 + a->e256 * b->e34 
             + a->e25 * b->e346 + a->e346 * b->e25 + a->e35 * b->e246 
             + a->e246 * b->e35 + a->e45 * b->e236 + a->e236 * b->e45 
             + a->e26 * b->e345 + a->e345 * b->e26 + a->e36 * b->e245 
             + a->e245 * b->e36 + a->e46 * b->e235 + a->e235 * b->e46 
             + a->e56 * b->e234 + a->e234 * b->e56;
  res.e12347 = c->e12347 + a->r * b->e12347 + a->e12347 * b->r + a->e1 * b->e2347 
             + a->e2347 * b->e1 + a->e2 * b->e1347 + a->e1347 * b->e2 
             + a->e3 * b->e1247 + a->e1247 * b->e3 + a->e4 * b->e1237 
             + a->e1237 * b->e4 + a->e7 * b->e1234 + a->e1234 * b->e7 
             + a->e12 * b->e347 + a->e347 * b->e12 + a->e13 * b->e247 
             + a->e247 * b->e13 + a->e23 * b->e147 + a->e147 * b->e23 
             + a->e14 * b->e237 + a->e237 * b->e14 + a->e24 * b->e137 
             + a->e137 * b->e24 + a->e34 * b->e127 + a->e127 * b->e34 
             + a->e17 * b->e234 + a->e234 * b->e17 + a->e27 * b->e134 
             + a->e134 * b->e27 + a->e37 * b->e124 + a->e124 * b->e37 
             + a->e47 * b->e123 + a->e123 * b->e47;
  res.e12357 = c->e12357 + a->r * b->e12357 + a->e12357 * b->r + a->e1 * b->e2357 
             + a->e2357 * b->e1 + a->e2 * b->e1357 + a->e1357 * b->e2 
             + a->e3 * b->e1257 + a->e1257 * b->e3 + a->e5 * b->e1237 
             + a->e1237 * b->e5 + a->e7 * b->e1235 + a->e1235 * b->e7 
             + a->e12 * b->e357 + a->e357 * b->e12 + a->e13 * b->e257 
             + a->e257 * b->e13 + a->e23 * b->e157 + a->e157 * b->e23 
             + a->e15 * b->e237 + a->e237 * b->e15 + a->e25 * b->e137 
             + a->e137 * b->e25 + a->e35 * b->e127 + a->e127 * b->e35 
             + a->e17 * b->e235 + a->e235 * b->e17 + a->e27 * b->e135 
             + a->e135 * b->e27 + a->e37 * b->e125 + a->e125 * b->e37 
             + a->e57 * b->e123 + a->e123 * b->e57;
  res.e12457 = c->e12457 + a->r * b->e12457 + a->e12457 * b->r + a->e1 * b->e2457 
             + a->e2457 * b->e1 + a->e2 * b->e1457 + a->e1457 * b->e2 
             + a->e4 * b->e1257 + a->e1257 * b->e4 + a->e5 * b->e1247 
             + a->e1247 * b->e5 + a->e7 * b->e1245 + a->e1245 * b->e7 
             + a->e12 * b->e457 + a->e457 * b->e12 + a->e14 * b->e257 
             + a->e257 * b->e14 + a->e24 * b->e157 + a->e157 * b->e24 
             + a->e15 * b->e247 + a->e247 * b->e15 + a->e25 * b->e147 
             + a->e147 * b->e25 + a->e45 * b->e127 + a->e127 * b->e45 
             + a->e17 * b->e245 + a->e245 * b->e17 + a->e27 * b->e145 
             + a->e145 * b->e27 + a->e47 * b->e125 + a->e125 * b->e47 
             + a->e57 * b->e124 + a->e124 * b->e57;
  res.e13457 = c->e13457 + a->r * b->e13457 + a->e13457 * b->r + a->e1 * b->e3457 
             + a->e3457 * b->e1 + a->e3 * b->e1457 + a->e1457 * b->e3 
             + a->e4 * b->e1357 + a->e1357 * b->e4 + a->e5 * b->e1347 
             + a->e1347 * b->e5 + a->e7 * b->e1345 + a->e1345 * b->e7 
             + a->e13 * b->e457 + a->e457 * b->e13 + a->e14 * b->e357 
             + a->e357 * b->e14 + a->e34 * b->e157 + a->e157 * b->e34 
             + a->e15 * b->e347 + a->e347 * b->e15 + a->e35 * b->e147 
             + a->e147 * b->e35 + a->e45 * b->e137 + a->e137 * b->e45 
             + a->e17 * b->e345 + a->e345 * b->e17 + a->e37 * b->e145 
             + a->e145 * b->e37 + a->e47 * b->e135 + a->e135 * b->e47 
             + a->e57 * b->e134 + a->e134 * b->e57;
  res.e23457 = c->e23457 + a->r * b->e23457 + a->e23457 * b->r + a->e2 * b->e3457 
             + a->e3457 * b->e2 + a->e3 * b->e2457 + a->e2457 * b->e3 
             + a->e4 * b->e2357 + a->e2357 * b->e4 + a->e5 * b->e2347 
             + a->e2347 * b->e5 + a->e7 * b->e2345 + a->e2345 * b->e7 
             + a->e23 * b->e457 + a->e457 * b->e23 + a->e24 * b->e357 
             + a->e357 * b->e24 + a->e34 * b->e257 + a->e257 * b->e34 
             + a->e25 * b->e347 + a->e347 * b->e25 + a->e35 * b->e247 
             + a->e247 * b->e35 + a->e45 * b->e237 + a->e237 * b->e45 
             + a->e27 * b->e345 + a->e345 * b->e27 + a->e37 * b->e245 
             + a->e245 * b->e37 + a->e47 * b->e235 + a->e235 * b->e47 
             + a->e57 * b->e234 + a->e234 * b->e57;
  res.e12367 = c->e12367 + a->r * b->e12367 + a->e12367 * b->r + a->e1 * b->e2367 
             + a->e2367 * b->e1 + a->e2 * b->e1367 + a->e1367 * b->e2 
             + a->e3 * b->e1267 + a->e1267 * b->e3 + a->e6 * b->e1237 
             + a->e1237 * b->e6 + a->e7 * b->e1236 + a->e1236 * b->e7 
             + a->e12 * b->e367 + a->e367 * b->e12 + a->e13 * b->e267 
             + a->e267 * b->e13 + a->e23 * b->e167 + a->e167 * b->e23 
             + a->e16 * b->e237 + a->e237 * b->e16 + a->e26 * b->e137 
             + a->e137 * b->e26 + a->e36 * b->e127 + a->e127 * b->e36 
             + a->e17 * b->e236 + a->e236 * b->e17 + a->e27 * b->e136 
             + a->e136 * b->e27 + a->e37 * b->e126 + a->e126 * b->e37 
             + a->e67 * b->e123 + a->e123 * b->e67;
  res.e12467 = c->e12467 + a->r * b->e12467 + a->e12467 * b->r + a->e1 * b->e2467 
             + a->e2467 * b->e1 + a->e2 * b->e1467 + a->e1467 * b->e2 
             + a->e4 * b->e1267 + a->e1267 * b->e4 + a->e6 * b->e1247 
             + a->e1247 * b->e6 + a->e7 * b->e1246 + a->e1246 * b->e7 
             + a->e12 * b->e467 + a->e467 * b->e12 + a->e14 * b->e267 
             + a->e267 * b->e14 + a->e24 * b->e167 + a->e167 * b->e24 
             + a->e16 * b->e247 + a->e247 * b->e16 + a->e26 * b->e147 
             + a->e147 * b->e26 + a->e46 * b->e127 + a->e127 * b->e46 
             + a->e17 * b->e246 + a->e246 * b->e17 + a->e27 * b->e146 
             + a->e146 * b->e27 + a->e47 * b->e126 + a->e126 * b->e47 
             + a->e67 * b->e124 + a->e124 * b->e67;
  res.e13467 = c->e13467 + a->r * b->e13467 + a->e13467 * b->r + a->e1 * b->e3467 
             + a->e3467 * b->e1 + a->e3 * b->e1467 + a->e1467 * b->e3 
             + a->e4 * b->e1367 + a->e1367 * b->e4 + a->e6 * b->e1347 
             + a->e1347 * b->e6 + a->e7 * b->e1346 + a->e1346 * b->e7 
             + a->e13 * b->e467 + a->e467 * b->e13 + a->e14 * b->e367 
             + a->e367 * b->e14 + a->e34 * b->e167 + a->e167 * b->e34 
             + a->e16 * b->e347 + a->e347 * b->e16 + a->e36 * b->e147 
             + a->e147 * b->e36 + a->e46 * b->e137 + a->e137 * b->e46 
             + a->e17 * b->e346 + a->e346 * b->e17 + a->e37 * b->e146 
             + a->e146 * b->e37 + a->e47 * b->e136 + a->e136 * b->e47 
             + a->e67 * b->e134 + a->e134 * b->e67;
  res.e23467 = c->e23467 + a->r * b->e23467 + a->e23467 * b->r + a->e2 * b->e3467 
             + a->e3467 * b->e2 + a->e3 * b->e2467 + a->e2467 * b->e3 
             + a->e4 * b->e2367 + a->e2367 * b->e4 + a->e6 * b->e2347 
             + a->e2347 * b->e6 + a->e7 * b->e2346 + a->e2346 * b->e7 
             + a->e23 * b->e467 + a->e467 * b->e23 + a->e24 * b->e367 
             + a->e367 * b->e24 + a->e34 * b->e267 + a->e267 * b->e34 
             + a->e26 * b->e347 + a->e347 * b->e26 + a->e36 * b->e247 
             + a->e247 * b->e36 + a->e46 * b->e237 + a->e237 * b->e46 
             + a->e27 * b->e346 + a->e346 * b->e27 + a->e37 * b->e246 
             + a->e246 * b->e37 + a->e47 * b->e236 + a->e236 * b->e47 
             + a->e67 * b->e234 + a->e234 * b->e67;
  res.e12567 = c->e12567 + a->r * b->e12567 + a->e12567 * b->r + a->e1 * b->e2567 
             + a->e2567 * b->e1 + a->e2 * b->e1567 + a->e1567 * b->e2 
             + a->e5 * b->e1267 + a->e1267 * b->e5 + a->e6 * b->e1257 
             + a->e1257 * b->e6 + a->e7 * b->e1256 + a->e1256 * b->e7 
             + a->e12 * b->e567 + a->e567 * b->e12 + a->e15 * b->e267 
             + a->e267 * b->e15 + a->e25 * b->e167 + a->e167 * b->e25 
             + a->e16 * b->e257 + a->e257 * b->e16 + a->e26 * b->e157 
             + a->e157 * b->e26 + a->e56 * b->e127 + a->e127 * b->e56 
             + a->e17 * b->e256 + a->e256 * b->e17 + a->e27 * b->e156 
             + a->e156 * b->e27 + a->e57 * b->e126 + a->e126 * b->e57 
             + a->e67 * b->e125 + a->e125 * b->e67;
  res.e13567 = c->e13567 + a->r * b->e13567 + a->e13567 * b->r + a->e1 * b->e3567 
             + a->e3567 * b->e1 + a->e3 * b->e1567 + a->e1567 * b->e3 
             + a->e5 * b->e1367 + a->e1367 * b->e5 + a->e6 * b->e1357 
             + a->e1357 * b->e6 + a->e7 * b->e1356 + a->e1356 * b->e7 
             + a->e13 * b->e567 + a->e567 * b->e13 + a->e15 * b->e367 
             + a->e367 * b->e15 + a->e35 * b->e167 + a->e167 * b->e35 
             + a->e16 * b->e357 + a->e357 * b->e16 + a->e36 * b->e157 
             + a->e157 * b->e36 + a->e56 * b->e137 + a->e137 * b->e56 
             + a->e17 * b->e356 + a->e356 * b->e17 + a->e37 * b->e156 
             + a->e156 * b->e37 + a->e57 * b->e136 + a->e136 * b->e57 
             + a->e67 * b->e135 + a->e135 * b->e67;
  res.e23567 = c->e23567 + a->r * b->e23567 + a->e23567 * b->r + a->e2 * b->e3567 
             + a->e3567 * b->e2 + a->e3 * b->e2567 + a->e2567 * b->e3 
             + a->e5 * b->e2367 + a->e2367 * b->e5 + a->e6 * b->e2357 
             + a->e2357 * b->e6 + a->e7 * b->e2356 + a->e2356 * b->e7 
             + a->e23 * b->e567 + a->e567 * b->e23 + a->e25 * b->e367 
             + a->e367 * b->e25 + a->e35 * b->e267 + a->e267 * b->e35 
             + a->e26 * b->e357 + a->e357 * b->e26 + a->e36 * b->e257 
             + a->e257 * b->e36 + a->e56 * b->e237 + a->e237 * b->e56 
             + a->e27 * b->e356 + a->e356 * b->e27 + a->e37 * b->e256 
             + a->e256 * b->e37 + a->e57 * b->e236 + a->e236 * b->e57 
             + a->e67 * b->e235 + a->e235 * b->e67;
  res.e14567 = c->e14567 + a->r * b->e14567 + a->e14567 * b->r + a->e1 * b->e4567 
             + a->e4567 * b->e1 + a->e4 * b->e1567 + a->e1567 * b->e4 
             + a->e5 * b->e1467 + a->e1467 * b->e5 + a->e6 * b->e1457 
             + a->e1457 * b->e6 + a->e7 * b->e1456 + a->e1456 * b->e7 
             + a->e14 * b->e567 + a->e567 * b->e14 + a->e15 * b->e467 
             + a->e467 * b->e15 + a->e45 * b->e167 + a->e167 * b->e45 
             + a->e16 * b->e457 + a->e457 * b->e16 + a->e46 * b->e157 
             + a->e157 * b->e46 + a->e56 * b->e147 + a->e147 * b->e56 
             + a->e17 * b->e456 + a->e456 * b->e17 + a->e47 * b->e156 
             + a->e156 * b->e47 + a->e57 * b->e146 + a->e146 * b->e57 
             + a->e67 * b->e145 + a->e145 * b->e67;
  res.e24567 = c->e24567 + a->r * b->e24567 + a->e24567 * b->r + a->e2 * b->e4567 
             + a->e4567 * b->e2 + a->e4 * b->e2567 + a->e2567 * b->e4 
             + a->e5 * b->e2467 + a->e2467 * b->e5 + a->e6 * b->e2457 
             + a->e2457 * b->e6 + a->e7 * b->e2456 + a->e2456 * b->e7 
             + a->e24 * b->e567 + a->e567 * b->e24 + a->e25 * b->e467 
             + a->e467 * b->e25 + a->e45 * b->e267 + a->e267 * b->e45 
             + a->e26 * b->e457 + a->e457 * b->e26 + a->e46 * b->e257 
             + a->e257 * b->e46 + a->e56 * b->e247 + a->e247 * b->e56 
             + a->e27 * b->e456 + a->e456 * b->e27 + a->e47 * b->e256 
             + a->e256 * b->e47 + a->e57 * b->e246 + a->e246 * b->e57 
             + a->e67 * b->e245 + a->e245 * b->e67;
  res.e34567 = c->e34567 + a->r * b->e34567 + a->e34567 * b->r + a->e3 * b->e4567 
             + a->e4567 * b->e3 + a->e4 * b->e3567 + a->e3567 * b->e4 
             + a->e5 * b->e3467 + a->e3467 * b->e5 + a->e6 * b->e3457 
             + a->e3457 * b->e6 + a->e7 * b->e3456 + a->e3456 * b->e7 
             + a->e34 * b->e567 + a->e567 * b->e34 + a->e35 * b->e467 
             + a->e467 * b->e35 + a->e45 * b->e367 + a->e367 * b->e45 
             + a->e36 * b->e457 + a->e457 * b->e36 + a->e46 * b->e357 
             + a->e357 * b->e46 + a->e56 * b->e347 + a->e347 * b->e56 
             + a->e37 * b->e456 + a->e456 * b->e37 + a->e47 * b->e356 
             + a->e356 * b->e47 + a->e57 * b->e346 + a->e346 * b->e57 
             + a->e67 * b->e345 + a->e345 * b->e67;
  // Order 6;
  res.e123456 = c->e123456 + a->r * b->e123456 + a->e123456 * b->r + a->e1 * b->e23456 
              + a->e23456 * b->e1 + a->e2 * b->e13456 + a->e13456 * b->e2 
              + a->e3 * b->e12456 + a->e12456 * b->e3 + a->e4 * b->e12356 
              + a->e12356 * b->e4 + a->e5 * b->e12346 + a->e12346 * b->e5 
              + a->e6 * b->e12345 + a->e12345 * b->e6 + a->e12 * b->e3456 
              + a->e3456 * b->e12 + a->e13 * b->e2456 + a->e2456 * b->e13 
              + a->e23 * b->e1456 + a->e1456 * b->e23 + a->e14 * b->e2356 
              + a->e2356 * b->e14 + a->e24 * b->e1356 + a->e1356 * b->e24 
              + a->e34 * b->e1256 + a->e1256 * b->e34 + a->e15 * b->e2346 
              + a->e2346 * b->e15 + a->e25 * b->e1346 + a->e1346 * b->e25 
              + a->e35 * b->e1246 + a->e1246 * b->e35 + a->e45 * b->e1236 
              + a->e1236 * b->e45 + a->e16 * b->e2345 + a->e2345 * b->e16 
              + a->e26 * b->e1345 + a->e1345 * b->e26 + a->e36 * b->e1245 
              + a->e1245 * b->e36 + a->e46 * b->e1235 + a->e1235 * b->e46 
              + a->e56 * b->e1234 + a->e1234 * b->e56 + a->e123 * b->e456 
              + a->e124 * b->e356 + a->e134 * b->e256 + a->e234 * b->e156 
              + a->e125 * b->e346 + a->e135 * b->e246 + a->e235 * b->e146 
              + a->e145 * b->e236 + a->e245 * b->e136 + a->e345 * b->e126 
              + a->e126 * b->e345 + a->e136 * b->e245 + a->e236 * b->e145 
              + a->e146 * b->e235 + a->e246 * b->e135 + a->e346 * b->e125 
              + a->e156 * b->e234 + a->e256 * b->e134 + a->e356 * b->e124 
              + a->e456 * b->e123;
  res.e123457 = c->e123457 + a->r * b->e123457 + a->e123457 * b->r + a->e1 * b->e23457 
              + a->e23457 * b->e1 + a->e2 * b->e13457 + a->e13457 * b->e2 
              + a->e3 * b->e12457 + a->e12457 * b->e3 + a->e4 * b->e12357 
              + a->e12357 * b->e4 + a->e5 * b->e12347 + a->e12347 * b->e5 
              + a->e7 * b->e12345 + a->e12345 * b->e7 + a->e12 * b->e3457 
              + a->e3457 * b->e12 + a->e13 * b->e2457 + a->e2457 * b->e13 
              + a->e23 * b->e1457 + a->e1457 * b->e23 + a->e14 * b->e2357 
              + a->e2357 * b->e14 + a->e24 * b->e1357 + a->e1357 * b->e24 
              + a->e34 * b->e1257 + a->e1257 * b->e34 + a->e15 * b->e2347 
              + a->e2347 * b->e15 + a->e25 * b->e1347 + a->e1347 * b->e25 
              + a->e35 * b->e1247 + a->e1247 * b->e35 + a->e45 * b->e1237 
              + a->e1237 * b->e45 + a->e17 * b->e2345 + a->e2345 * b->e17 
              + a->e27 * b->e1345 + a->e1345 * b->e27 + a->e37 * b->e1245 
              + a->e1245 * b->e37 + a->e47 * b->e1235 + a->e1235 * b->e47 
              + a->e57 * b->e1234 + a->e1234 * b->e57 + a->e123 * b->e457 
              + a->e124 * b->e357 + a->e134 * b->e257 + a->e234 * b->e157 
              + a->e125 * b->e347 + a->e135 * b->e247 + a->e235 * b->e147 
              + a->e145 * b->e237 + a->e245 * b->e137 + a->e345 * b->e127 
              + a->e127 * b->e345 + a->e137 * b->e245 + a->e237 * b->e145 
              + a->e147 * b->e235 + a->e247 * b->e135 + a->e347 * b->e125 
              + a->e157 * b->e234 + a->e257 * b->e134 + a->e357 * b->e124 
              + a->e457 * b->e123;
  res.e123467 = c->e123467 + a->r * b->e123467 + a->e123467 * b->r + a->e1 * b->e23467 
              + a->e23467 * b->e1 + a->e2 * b->e13467 + a->e13467 * b->e2 
              + a->e3 * b->e12467 + a->e12467 * b->e3 + a->e4 * b->e12367 
              + a->e12367 * b->e4 + a->e6 * b->e12347 + a->e12347 * b->e6 
              + a->e7 * b->e12346 + a->e12346 * b->e7 + a->e12 * b->e3467 
              + a->e3467 * b->e12 + a->e13 * b->e2467 + a->e2467 * b->e13 
              + a->e23 * b->e1467 + a->e1467 * b->e23 + a->e14 * b->e2367 
              + a->e2367 * b->e14 + a->e24 * b->e1367 + a->e1367 * b->e24 
              + a->e34 * b->e1267 + a->e1267 * b->e34 + a->e16 * b->e2347 
              + a->e2347 * b->e16 + a->e26 * b->e1347 + a->e1347 * b->e26 
              + a->e36 * b->e1247 + a->e1247 * b->e36 + a->e46 * b->e1237 
              + a->e1237 * b->e46 + a->e17 * b->e2346 + a->e2346 * b->e17 
              + a->e27 * b->e1346 + a->e1346 * b->e27 + a->e37 * b->e1246 
              + a->e1246 * b->e37 + a->e47 * b->e1236 + a->e1236 * b->e47 
              + a->e67 * b->e1234 + a->e1234 * b->e67 + a->e123 * b->e467 
              + a->e124 * b->e367 + a->e134 * b->e267 + a->e234 * b->e167 
              + a->e126 * b->e347 + a->e136 * b->e247 + a->e236 * b->e147 
              + a->e146 * b->e237 + a->e246 * b->e137 + a->e346 * b->e127 
              + a->e127 * b->e346 + a->e137 * b->e246 + a->e237 * b->e146 
              + a->e147 * b->e236 + a->e247 * b->e136 + a->e347 * b->e126 
              + a->e167 * b->e234 + a->e267 * b->e134 + a->e367 * b->e124 
              + a->e467 * b->e123;
  res.e123567 = c->e123567 + a->r * b->e123567 + a->e123567 * b->r + a->e1 * b->e23567 
              + a->e23567 * b->e1 + a->e2 * b->e13567 + a->e13567 * b->e2 
              + a->e3 * b->e12567 + a->e12567 * b->e3 + a->e5 * b->e12367 
              + a->e12367 * b->e5 + a->e6 * b->e12357 + a->e12357 * b->e6 
              + a->e7 * b->e12356 + a->e12356 * b->e7 + a->e12 * b->e3567 
              + a->e3567 * b->e12 + a->e13 * b->e2567 + a->e2567 * b->e13 
              + a->e23 * b->e1567 + a->e1567 * b->e23 + a->e15 * b->e2367 
              + a->e2367 * b->e15 + a->e25 * b->e1367 + a->e1367 * b->e25 
              + a->e35 * b->e1267 + a->e1267 * b->e35 + a->e16 * b->e2357 
              + a->e2357 * b->e16 + a->e26 * b->e1357 + a->e1357 * b->e26 
              + a->e36 * b->e1257 + a->e1257 * b->e36 + a->e56 * b->e1237 
              + a->e1237 * b->e56 + a->e17 * b->e2356 + a->e2356 * b->e17 
              + a->e27 * b->e1356 + a->e1356 * b->e27 + a->e37 * b->e1256 
              + a->e1256 * b->e37 + a->e57 * b->e1236 + a->e1236 * b->e57 
              + a->e67 * b->e1235 + a->e1235 * b->e67 + a->e123 * b->e567 
              + a->e125 * b->e367 + a->e135 * b->e267 + a->e235 * b->e167 
              + a->e126 * b->e357 + a->e136 * b->e257 + a->e236 * b->e157 
              + a->e156 * b->e237 + a->e256 * b->e137 + a->e356 * b->e127 
              + a->e127 * b->e356 + a->e137 * b->e256 + a->e237 * b->e156 
              + a->e157 * b->e236 + a->e257 * b->e136 + a->e357 * b->e126 
              + a->e167 * b->e235 + a->e267 * b->e135 + a->e367 * b->e125 
              + a->e567 * b->e123;
  res.e124567 = c->e124567 + a->r * b->e124567 + a->e124567 * b->r + a->e1 * b->e24567 
              + a->e24567 * b->e1 + a->e2 * b->e14567 + a->e14567 * b->e2 
              + a->e4 * b->e12567 + a->e12567 * b->e4 + a->e5 * b->e12467 
              + a->e12467 * b->e5 + a->e6 * b->e12457 + a->e12457 * b->e6 
              + a->e7 * b->e12456 + a->e12456 * b->e7 + a->e12 * b->e4567 
              + a->e4567 * b->e12 + a->e14 * b->e2567 + a->e2567 * b->e14 
              + a->e24 * b->e1567 + a->e1567 * b->e24 + a->e15 * b->e2467 
              + a->e2467 * b->e15 + a->e25 * b->e1467 + a->e1467 * b->e25 
              + a->e45 * b->e1267 + a->e1267 * b->e45 + a->e16 * b->e2457 
              + a->e2457 * b->e16 + a->e26 * b->e1457 + a->e1457 * b->e26 
              + a->e46 * b->e1257 + a->e1257 * b->e46 + a->e56 * b->e1247 
              + a->e1247 * b->e56 + a->e17 * b->e2456 + a->e2456 * b->e17 
              + a->e27 * b->e1456 + a->e1456 * b->e27 + a->e47 * b->e1256 
              + a->e1256 * b->e47 + a->e57 * b->e1246 + a->e1246 * b->e57 
              + a->e67 * b->e1245 + a->e1245 * b->e67 + a->e124 * b->e567 
              + a->e125 * b->e467 + a->e145 * b->e267 + a->e245 * b->e167 
              + a->e126 * b->e457 + a->e146 * b->e257 + a->e246 * b->e157 
              + a->e156 * b->e247 + a->e256 * b->e147 + a->e456 * b->e127 
              + a->e127 * b->e456 + a->e147 * b->e256 + a->e247 * b->e156 
              + a->e157 * b->e246 + a->e257 * b->e146 + a->e457 * b->e126 
              + a->e167 * b->e245 + a->e267 * b->e145 + a->e467 * b->e125 
              + a->e567 * b->e124;
  res.e134567 = c->e134567 + a->r * b->e134567 + a->e134567 * b->r + a->e1 * b->e34567 
              + a->e34567 * b->e1 + a->e3 * b->e14567 + a->e14567 * b->e3 
              + a->e4 * b->e13567 + a->e13567 * b->e4 + a->e5 * b->e13467 
              + a->e13467 * b->e5 + a->e6 * b->e13457 + a->e13457 * b->e6 
              + a->e7 * b->e13456 + a->e13456 * b->e7 + a->e13 * b->e4567 
              + a->e4567 * b->e13 + a->e14 * b->e3567 + a->e3567 * b->e14 
              + a->e34 * b->e1567 + a->e1567 * b->e34 + a->e15 * b->e3467 
              + a->e3467 * b->e15 + a->e35 * b->e1467 + a->e1467 * b->e35 
              + a->e45 * b->e1367 + a->e1367 * b->e45 + a->e16 * b->e3457 
              + a->e3457 * b->e16 + a->e36 * b->e1457 + a->e1457 * b->e36 
              + a->e46 * b->e1357 + a->e1357 * b->e46 + a->e56 * b->e1347 
              + a->e1347 * b->e56 + a->e17 * b->e3456 + a->e3456 * b->e17 
              + a->e37 * b->e1456 + a->e1456 * b->e37 + a->e47 * b->e1356 
              + a->e1356 * b->e47 + a->e57 * b->e1346 + a->e1346 * b->e57 
              + a->e67 * b->e1345 + a->e1345 * b->e67 + a->e134 * b->e567 
              + a->e135 * b->e467 + a->e145 * b->e367 + a->e345 * b->e167 
              + a->e136 * b->e457 + a->e146 * b->e357 + a->e346 * b->e157 
              + a->e156 * b->e347 + a->e356 * b->e147 + a->e456 * b->e137 
              + a->e137 * b->e456 + a->e147 * b->e356 + a->e347 * b->e156 
              + a->e157 * b->e346 + a->e357 * b->e146 + a->e457 * b->e136 
              + a->e167 * b->e345 + a->e367 * b->e145 + a->e467 * b->e135 
              + a->e567 * b->e134;
  res.e234567 = c->e234567 + a->r * b->e234567 + a->e234567 * b->r + a->e2 * b->e34567 
              + a->e34567 * b->e2 + a->e3 * b->e24567 + a->e24567 * b->e3 
              + a->e4 * b->e23567 + a->e23567 * b->e4 + a->e5 * b->e23467 
              + a->e23467 * b->e5 + a->e6 * b->e23457 + a->e23457 * b->e6 
              + a->e7 * b->e23456 + a->e23456 * b->e7 + a->e23 * b->e4567 
              + a->e4567 * b->e23 + a->e24 * b->e3567 + a->e3567 * b->e24 
              + a->e34 * b->e2567 + a->e2567 * b->e34 + a->e25 * b->e3467 
              + a->e3467 * b->e25 + a->e35 * b->e2467 + a->e2467 * b->e35 
              + a->e45 * b->e2367 + a->e2367 * b->e45 + a->e26 * b->e3457 
              + a->e3457 * b->e26 + a->e36 * b->e2457 + a->e2457 * b->e36 
              + a->e46 * b->e2357 + a->e2357 * b->e46 + a->e56 * b->e2347 
              + a->e2347 * b->e56 + a->e27 * b->e3456 + a->e3456 * b->e27 
              + a->e37 * b->e2456 + a->e2456 * b->e37 + a->e47 * b->e2356 
              + a->e2356 * b->e47 + a->e57 * b->e2346 + a->e2346 * b->e57 
              + a->e67 * b->e2345 + a->e2345 * b->e67 + a->e234 * b->e567 
              + a->e235 * b->e467 + a->e245 * b->e367 + a->e345 * b->e267 
              + a->e236 * b->e457 + a->e246 * b->e357 + a->e346 * b->e257 
              + a->e256 * b->e347 + a->e356 * b->e247 + a->e456 * b->e237 
              + a->e237 * b->e456 + a->e247 * b->e356 + a->e347 * b->e256 
              + a->e257 * b->e346 + a->e357 * b->e246 + a->e457 * b->e236 
              + a->e267 * b->e345 + a->e367 * b->e245 + a->e467 * b->e235 
              + a->e567 * b->e234;
  // Order 7;
  res.e1234567 = c->e1234567 + a->r * b->e1234567 + a->e1234567 * b->r + a->e1 * b->e234567 
               + a->e234567 * b->e1 + a->e2 * b->e134567 + a->e134567 * b->e2 
               + a->e3 * b->e124567 + a->e124567 * b->e3 + a->e4 * b->e123567 
               + a->e123567 * b->e4 + a->e5 * b->e123467 + a->e123467 * b->e5 
               + a->e6 * b->e123457 + a->e123457 * b->e6 + a->e7 * b->e123456 
               + a->e123456 * b->e7 + a->e12 * b->e34567 + a->e34567 * b->e12 
               + a->e13 * b->e24567 + a->e24567 * b->e13 + a->e23 * b->e14567 
               + a->e14567 * b->e23 + a->e14 * b->e23567 + a->e23567 * b->e14 
               + a->e24 * b->e13567 + a->e13567 * b->e24 + a->e34 * b->e12567 
               + a->e12567 * b->e34 + a->e15 * b->e23467 + a->e23467 * b->e15 
               + a->e25 * b->e13467 + a->e13467 * b->e25 + a->e35 * b->e12467 
               + a->e12467 * b->e35 + a->e45 * b->e12367 + a->e12367 * b->e45 
               + a->e16 * b->e23457 + a->e23457 * b->e16 + a->e26 * b->e13457 
               + a->e13457 * b->e26 + a->e36 * b->e12457 + a->e12457 * b->e36 
               + a->e46 * b->e12357 + a->e12357 * b->e46 + a->e56 * b->e12347 
               + a->e12347 * b->e56 + a->e17 * b->e23456 + a->e23456 * b->e17 
               + a->e27 * b->e13456 + a->e13456 * b->e27 + a->e37 * b->e12456 
               + a->e12456 * b->e37 + a->e47 * b->e12356 + a->e12356 * b->e47 
               + a->e57 * b->e12346 + a->e12346 * b->e57 + a->e67 * b->e12345 
               + a->e12345 * b->e67 + a->e123 * b->e4567 + a->e4567 * b->e123 
               + a->e124 * b->e3567 + a->e3567 * b->e124 + a->e134 * b->e2567 
               + a->e2567 * b->e134 + a->e234 * b->e1567 + a->e1567 * b->e234 
               + a->e125 * b->e3467 + a->e3467 * b->e125 + a->e135 * b->e2467 
               + a->e2467 * b->e135 + a->e235 * b->e1467 + a->e1467 * b->e235 
               + a->e145 * b->e2367 + a->e2367 * b->e145 + a->e245 * b->e1367 
               + a->e1367 * b->e245 + a->e345 * b->e1267 + a->e1267 * b->e345 
               + a->e126 * b->e3457 + a->e3457 * b->e126 + a->e136 * b->e2457 
               + a->e2457 * b->e136 + a->e236 * b->e1457 + a->e1457 * b->e236 
               + a->e146 * b->e2357 + a->e2357 * b->e146 + a->e246 * b->e1357 
               + a->e1357 * b->e246 + a->e346 * b->e1257 + a->e1257 * b->e346 
               + a->e156 * b->e2347 + a->e2347 * b->e156 + a->e256 * b->e1347 
               + a->e1347 * b->e256 + a->e356 * b->e1247 + a->e1247 * b->e356 
               + a->e456 * b->e1237 + a->e1237 * b->e456 + a->e127 * b->e3456 
               + a->e3456 * b->e127 + a->e137 * b->e2456 + a->e2456 * b->e137 
               + a->e237 * b->e1456 + a->e1456 * b->e237 + a->e147 * b->e2356 
               + a->e2356 * b->e147 + a->e247 * b->e1356 + a->e1356 * b->e247 
               + a->e347 * b->e1256 + a->e1256 * b->e347 + a->e157 * b->e2346 
               + a->e2346 * b->e157 + a->e257 * b->e1346 + a->e1346 * b->e257 
               + a->e357 * b->e1246 + a->e1246 * b->e357 + a->e457 * b->e1236 
               + a->e1236 * b->e457 + a->e167 * b->e2345 + a->e2345 * b->e167 
               + a->e267 * b->e1345 + a->e1345 * b->e267 + a->e367 * b->e1245 
               + a->e1245 * b->e367 + a->e467 * b->e1235 + a->e1235 * b->e467 
               + a->e567 * b->e1234 + a->e1234 * b->e567;

  return res;

}

void mdnum7_gem_oo_to(  mdnum7_t* a,  mdnum7_t* b,  mdnum7_t* c, mdnum7_t* res){
  //  General multiplication like function 'a * b + c'
  // Real;
  res->r = c->r + a->r * b->r;
  // Order 1;
  res->e1 = c->e1 + a->r * b->e1 + a->e1 * b->r;
  res->e2 = c->e2 + a->r * b->e2 + a->e2 * b->r;
  res->e3 = c->e3 + a->r * b->e3 + a->e3 * b->r;
  res->e4 = c->e4 + a->r * b->e4 + a->e4 * b->r;
  res->e5 = c->e5 + a->r * b->e5 + a->e5 * b->r;
  res->e6 = c->e6 + a->r * b->e6 + a->e6 * b->r;
  res->e7 = c->e7 + a->r * b->e7 + a->e7 * b->r;
  // Order 2;
  res->e12 = c->e12 + a->r * b->e12 + a->e12 * b->r + a->e1 * b->e2 
          + a->e2 * b->e1;
  res->e13 = c->e13 + a->r * b->e13 + a->e13 * b->r + a->e1 * b->e3 
          + a->e3 * b->e1;
  res->e23 = c->e23 + a->r * b->e23 + a->e23 * b->r + a->e2 * b->e3 
          + a->e3 * b->e2;
  res->e14 = c->e14 + a->r * b->e14 + a->e14 * b->r + a->e1 * b->e4 
          + a->e4 * b->e1;
  res->e24 = c->e24 + a->r * b->e24 + a->e24 * b->r + a->e2 * b->e4 
          + a->e4 * b->e2;
  res->e34 = c->e34 + a->r * b->e34 + a->e34 * b->r + a->e3 * b->e4 
          + a->e4 * b->e3;
  res->e15 = c->e15 + a->r * b->e15 + a->e15 * b->r + a->e1 * b->e5 
          + a->e5 * b->e1;
  res->e25 = c->e25 + a->r * b->e25 + a->e25 * b->r + a->e2 * b->e5 
          + a->e5 * b->e2;
  res->e35 = c->e35 + a->r * b->e35 + a->e35 * b->r + a->e3 * b->e5 
          + a->e5 * b->e3;
  res->e45 = c->e45 + a->r * b->e45 + a->e45 * b->r + a->e4 * b->e5 
          + a->e5 * b->e4;
  res->e16 = c->e16 + a->r * b->e16 + a->e16 * b->r + a->e1 * b->e6 
          + a->e6 * b->e1;
  res->e26 = c->e26 + a->r * b->e26 + a->e26 * b->r + a->e2 * b->e6 
          + a->e6 * b->e2;
  res->e36 = c->e36 + a->r * b->e36 + a->e36 * b->r + a->e3 * b->e6 
          + a->e6 * b->e3;
  res->e46 = c->e46 + a->r * b->e46 + a->e46 * b->r + a->e4 * b->e6 
          + a->e6 * b->e4;
  res->e56 = c->e56 + a->r * b->e56 + a->e56 * b->r + a->e5 * b->e6 
          + a->e6 * b->e5;
  res->e17 = c->e17 + a->r * b->e17 + a->e17 * b->r + a->e1 * b->e7 
          + a->e7 * b->e1;
  res->e27 = c->e27 + a->r * b->e27 + a->e27 * b->r + a->e2 * b->e7 
          + a->e7 * b->e2;
  res->e37 = c->e37 + a->r * b->e37 + a->e37 * b->r + a->e3 * b->e7 
          + a->e7 * b->e3;
  res->e47 = c->e47 + a->r * b->e47 + a->e47 * b->r + a->e4 * b->e7 
          + a->e7 * b->e4;
  res->e57 = c->e57 + a->r * b->e57 + a->e57 * b->r + a->e5 * b->e7 
          + a->e7 * b->e5;
  res->e67 = c->e67 + a->r * b->e67 + a->e67 * b->r + a->e6 * b->e7 
          + a->e7 * b->e6;
  // Order 3;
  res->e123 = c->e123 + a->r * b->e123 + a->e123 * b->r + a->e1 * b->e23 
           + a->e23 * b->e1 + a->e2 * b->e13 + a->e13 * b->e2 
           + a->e3 * b->e12 + a->e12 * b->e3;
  res->e124 = c->e124 + a->r * b->e124 + a->e124 * b->r + a->e1 * b->e24 
           + a->e24 * b->e1 + a->e2 * b->e14 + a->e14 * b->e2 
           + a->e4 * b->e12 + a->e12 * b->e4;
  res->e134 = c->e134 + a->r * b->e134 + a->e134 * b->r + a->e1 * b->e34 
           + a->e34 * b->e1 + a->e3 * b->e14 + a->e14 * b->e3 
           + a->e4 * b->e13 + a->e13 * b->e4;
  res->e234 = c->e234 + a->r * b->e234 + a->e234 * b->r + a->e2 * b->e34 
           + a->e34 * b->e2 + a->e3 * b->e24 + a->e24 * b->e3 
           + a->e4 * b->e23 + a->e23 * b->e4;
  res->e125 = c->e125 + a->r * b->e125 + a->e125 * b->r + a->e1 * b->e25 
           + a->e25 * b->e1 + a->e2 * b->e15 + a->e15 * b->e2 
           + a->e5 * b->e12 + a->e12 * b->e5;
  res->e135 = c->e135 + a->r * b->e135 + a->e135 * b->r + a->e1 * b->e35 
           + a->e35 * b->e1 + a->e3 * b->e15 + a->e15 * b->e3 
           + a->e5 * b->e13 + a->e13 * b->e5;
  res->e235 = c->e235 + a->r * b->e235 + a->e235 * b->r + a->e2 * b->e35 
           + a->e35 * b->e2 + a->e3 * b->e25 + a->e25 * b->e3 
           + a->e5 * b->e23 + a->e23 * b->e5;
  res->e145 = c->e145 + a->r * b->e145 + a->e145 * b->r + a->e1 * b->e45 
           + a->e45 * b->e1 + a->e4 * b->e15 + a->e15 * b->e4 
           + a->e5 * b->e14 + a->e14 * b->e5;
  res->e245 = c->e245 + a->r * b->e245 + a->e245 * b->r + a->e2 * b->e45 
           + a->e45 * b->e2 + a->e4 * b->e25 + a->e25 * b->e4 
           + a->e5 * b->e24 + a->e24 * b->e5;
  res->e345 = c->e345 + a->r * b->e345 + a->e345 * b->r + a->e3 * b->e45 
           + a->e45 * b->e3 + a->e4 * b->e35 + a->e35 * b->e4 
           + a->e5 * b->e34 + a->e34 * b->e5;
  res->e126 = c->e126 + a->r * b->e126 + a->e126 * b->r + a->e1 * b->e26 
           + a->e26 * b->e1 + a->e2 * b->e16 + a->e16 * b->e2 
           + a->e6 * b->e12 + a->e12 * b->e6;
  res->e136 = c->e136 + a->r * b->e136 + a->e136 * b->r + a->e1 * b->e36 
           + a->e36 * b->e1 + a->e3 * b->e16 + a->e16 * b->e3 
           + a->e6 * b->e13 + a->e13 * b->e6;
  res->e236 = c->e236 + a->r * b->e236 + a->e236 * b->r + a->e2 * b->e36 
           + a->e36 * b->e2 + a->e3 * b->e26 + a->e26 * b->e3 
           + a->e6 * b->e23 + a->e23 * b->e6;
  res->e146 = c->e146 + a->r * b->e146 + a->e146 * b->r + a->e1 * b->e46 
           + a->e46 * b->e1 + a->e4 * b->e16 + a->e16 * b->e4 
           + a->e6 * b->e14 + a->e14 * b->e6;
  res->e246 = c->e246 + a->r * b->e246 + a->e246 * b->r + a->e2 * b->e46 
           + a->e46 * b->e2 + a->e4 * b->e26 + a->e26 * b->e4 
           + a->e6 * b->e24 + a->e24 * b->e6;
  res->e346 = c->e346 + a->r * b->e346 + a->e346 * b->r + a->e3 * b->e46 
           + a->e46 * b->e3 + a->e4 * b->e36 + a->e36 * b->e4 
           + a->e6 * b->e34 + a->e34 * b->e6;
  res->e156 = c->e156 + a->r * b->e156 + a->e156 * b->r + a->e1 * b->e56 
           + a->e56 * b->e1 + a->e5 * b->e16 + a->e16 * b->e5 
           + a->e6 * b->e15 + a->e15 * b->e6;
  res->e256 = c->e256 + a->r * b->e256 + a->e256 * b->r + a->e2 * b->e56 
           + a->e56 * b->e2 + a->e5 * b->e26 + a->e26 * b->e5 
           + a->e6 * b->e25 + a->e25 * b->e6;
  res->e356 = c->e356 + a->r * b->e356 + a->e356 * b->r + a->e3 * b->e56 
           + a->e56 * b->e3 + a->e5 * b->e36 + a->e36 * b->e5 
           + a->e6 * b->e35 + a->e35 * b->e6;
  res->e456 = c->e456 + a->r * b->e456 + a->e456 * b->r + a->e4 * b->e56 
           + a->e56 * b->e4 + a->e5 * b->e46 + a->e46 * b->e5 
           + a->e6 * b->e45 + a->e45 * b->e6;
  res->e127 = c->e127 + a->r * b->e127 + a->e127 * b->r + a->e1 * b->e27 
           + a->e27 * b->e1 + a->e2 * b->e17 + a->e17 * b->e2 
           + a->e7 * b->e12 + a->e12 * b->e7;
  res->e137 = c->e137 + a->r * b->e137 + a->e137 * b->r + a->e1 * b->e37 
           + a->e37 * b->e1 + a->e3 * b->e17 + a->e17 * b->e3 
           + a->e7 * b->e13 + a->e13 * b->e7;
  res->e237 = c->e237 + a->r * b->e237 + a->e237 * b->r + a->e2 * b->e37 
           + a->e37 * b->e2 + a->e3 * b->e27 + a->e27 * b->e3 
           + a->e7 * b->e23 + a->e23 * b->e7;
  res->e147 = c->e147 + a->r * b->e147 + a->e147 * b->r + a->e1 * b->e47 
           + a->e47 * b->e1 + a->e4 * b->e17 + a->e17 * b->e4 
           + a->e7 * b->e14 + a->e14 * b->e7;
  res->e247 = c->e247 + a->r * b->e247 + a->e247 * b->r + a->e2 * b->e47 
           + a->e47 * b->e2 + a->e4 * b->e27 + a->e27 * b->e4 
           + a->e7 * b->e24 + a->e24 * b->e7;
  res->e347 = c->e347 + a->r * b->e347 + a->e347 * b->r + a->e3 * b->e47 
           + a->e47 * b->e3 + a->e4 * b->e37 + a->e37 * b->e4 
           + a->e7 * b->e34 + a->e34 * b->e7;
  res->e157 = c->e157 + a->r * b->e157 + a->e157 * b->r + a->e1 * b->e57 
           + a->e57 * b->e1 + a->e5 * b->e17 + a->e17 * b->e5 
           + a->e7 * b->e15 + a->e15 * b->e7;
  res->e257 = c->e257 + a->r * b->e257 + a->e257 * b->r + a->e2 * b->e57 
           + a->e57 * b->e2 + a->e5 * b->e27 + a->e27 * b->e5 
           + a->e7 * b->e25 + a->e25 * b->e7;
  res->e357 = c->e357 + a->r * b->e357 + a->e357 * b->r + a->e3 * b->e57 
           + a->e57 * b->e3 + a->e5 * b->e37 + a->e37 * b->e5 
           + a->e7 * b->e35 + a->e35 * b->e7;
  res->e457 = c->e457 + a->r * b->e457 + a->e457 * b->r + a->e4 * b->e57 
           + a->e57 * b->e4 + a->e5 * b->e47 + a->e47 * b->e5 
           + a->e7 * b->e45 + a->e45 * b->e7;
  res->e167 = c->e167 + a->r * b->e167 + a->e167 * b->r + a->e1 * b->e67 
           + a->e67 * b->e1 + a->e6 * b->e17 + a->e17 * b->e6 
           + a->e7 * b->e16 + a->e16 * b->e7;
  res->e267 = c->e267 + a->r * b->e267 + a->e267 * b->r + a->e2 * b->e67 
           + a->e67 * b->e2 + a->e6 * b->e27 + a->e27 * b->e6 
           + a->e7 * b->e26 + a->e26 * b->e7;
  res->e367 = c->e367 + a->r * b->e367 + a->e367 * b->r + a->e3 * b->e67 
           + a->e67 * b->e3 + a->e6 * b->e37 + a->e37 * b->e6 
           + a->e7 * b->e36 + a->e36 * b->e7;
  res->e467 = c->e467 + a->r * b->e467 + a->e467 * b->r + a->e4 * b->e67 
           + a->e67 * b->e4 + a->e6 * b->e47 + a->e47 * b->e6 
           + a->e7 * b->e46 + a->e46 * b->e7;
  res->e567 = c->e567 + a->r * b->e567 + a->e567 * b->r + a->e5 * b->e67 
           + a->e67 * b->e5 + a->e6 * b->e57 + a->e57 * b->e6 
           + a->e7 * b->e56 + a->e56 * b->e7;
  // Order 4;
  res->e1234 = c->e1234 + a->r * b->e1234 + a->e1234 * b->r + a->e1 * b->e234 
            + a->e234 * b->e1 + a->e2 * b->e134 + a->e134 * b->e2 
            + a->e3 * b->e124 + a->e124 * b->e3 + a->e4 * b->e123 
            + a->e123 * b->e4 + a->e12 * b->e34 + a->e13 * b->e24 
            + a->e23 * b->e14 + a->e14 * b->e23 + a->e24 * b->e13 
            + a->e34 * b->e12;
  res->e1235 = c->e1235 + a->r * b->e1235 + a->e1235 * b->r + a->e1 * b->e235 
            + a->e235 * b->e1 + a->e2 * b->e135 + a->e135 * b->e2 
            + a->e3 * b->e125 + a->e125 * b->e3 + a->e5 * b->e123 
            + a->e123 * b->e5 + a->e12 * b->e35 + a->e13 * b->e25 
            + a->e23 * b->e15 + a->e15 * b->e23 + a->e25 * b->e13 
            + a->e35 * b->e12;
  res->e1245 = c->e1245 + a->r * b->e1245 + a->e1245 * b->r + a->e1 * b->e245 
            + a->e245 * b->e1 + a->e2 * b->e145 + a->e145 * b->e2 
            + a->e4 * b->e125 + a->e125 * b->e4 + a->e5 * b->e124 
            + a->e124 * b->e5 + a->e12 * b->e45 + a->e14 * b->e25 
            + a->e24 * b->e15 + a->e15 * b->e24 + a->e25 * b->e14 
            + a->e45 * b->e12;
  res->e1345 = c->e1345 + a->r * b->e1345 + a->e1345 * b->r + a->e1 * b->e345 
            + a->e345 * b->e1 + a->e3 * b->e145 + a->e145 * b->e3 
            + a->e4 * b->e135 + a->e135 * b->e4 + a->e5 * b->e134 
            + a->e134 * b->e5 + a->e13 * b->e45 + a->e14 * b->e35 
            + a->e34 * b->e15 + a->e15 * b->e34 + a->e35 * b->e14 
            + a->e45 * b->e13;
  res->e2345 = c->e2345 + a->r * b->e2345 + a->e2345 * b->r + a->e2 * b->e345 
            + a->e345 * b->e2 + a->e3 * b->e245 + a->e245 * b->e3 
            + a->e4 * b->e235 + a->e235 * b->e4 + a->e5 * b->e234 
            + a->e234 * b->e5 + a->e23 * b->e45 + a->e24 * b->e35 
            + a->e34 * b->e25 + a->e25 * b->e34 + a->e35 * b->e24 
            + a->e45 * b->e23;
  res->e1236 = c->e1236 + a->r * b->e1236 + a->e1236 * b->r + a->e1 * b->e236 
            + a->e236 * b->e1 + a->e2 * b->e136 + a->e136 * b->e2 
            + a->e3 * b->e126 + a->e126 * b->e3 + a->e6 * b->e123 
            + a->e123 * b->e6 + a->e12 * b->e36 + a->e13 * b->e26 
            + a->e23 * b->e16 + a->e16 * b->e23 + a->e26 * b->e13 
            + a->e36 * b->e12;
  res->e1246 = c->e1246 + a->r * b->e1246 + a->e1246 * b->r + a->e1 * b->e246 
            + a->e246 * b->e1 + a->e2 * b->e146 + a->e146 * b->e2 
            + a->e4 * b->e126 + a->e126 * b->e4 + a->e6 * b->e124 
            + a->e124 * b->e6 + a->e12 * b->e46 + a->e14 * b->e26 
            + a->e24 * b->e16 + a->e16 * b->e24 + a->e26 * b->e14 
            + a->e46 * b->e12;
  res->e1346 = c->e1346 + a->r * b->e1346 + a->e1346 * b->r + a->e1 * b->e346 
            + a->e346 * b->e1 + a->e3 * b->e146 + a->e146 * b->e3 
            + a->e4 * b->e136 + a->e136 * b->e4 + a->e6 * b->e134 
            + a->e134 * b->e6 + a->e13 * b->e46 + a->e14 * b->e36 
            + a->e34 * b->e16 + a->e16 * b->e34 + a->e36 * b->e14 
            + a->e46 * b->e13;
  res->e2346 = c->e2346 + a->r * b->e2346 + a->e2346 * b->r + a->e2 * b->e346 
            + a->e346 * b->e2 + a->e3 * b->e246 + a->e246 * b->e3 
            + a->e4 * b->e236 + a->e236 * b->e4 + a->e6 * b->e234 
            + a->e234 * b->e6 + a->e23 * b->e46 + a->e24 * b->e36 
            + a->e34 * b->e26 + a->e26 * b->e34 + a->e36 * b->e24 
            + a->e46 * b->e23;
  res->e1256 = c->e1256 + a->r * b->e1256 + a->e1256 * b->r + a->e1 * b->e256 
            + a->e256 * b->e1 + a->e2 * b->e156 + a->e156 * b->e2 
            + a->e5 * b->e126 + a->e126 * b->e5 + a->e6 * b->e125 
            + a->e125 * b->e6 + a->e12 * b->e56 + a->e15 * b->e26 
            + a->e25 * b->e16 + a->e16 * b->e25 + a->e26 * b->e15 
            + a->e56 * b->e12;
  res->e1356 = c->e1356 + a->r * b->e1356 + a->e1356 * b->r + a->e1 * b->e356 
            + a->e356 * b->e1 + a->e3 * b->e156 + a->e156 * b->e3 
            + a->e5 * b->e136 + a->e136 * b->e5 + a->e6 * b->e135 
            + a->e135 * b->e6 + a->e13 * b->e56 + a->e15 * b->e36 
            + a->e35 * b->e16 + a->e16 * b->e35 + a->e36 * b->e15 
            + a->e56 * b->e13;
  res->e2356 = c->e2356 + a->r * b->e2356 + a->e2356 * b->r + a->e2 * b->e356 
            + a->e356 * b->e2 + a->e3 * b->e256 + a->e256 * b->e3 
            + a->e5 * b->e236 + a->e236 * b->e5 + a->e6 * b->e235 
            + a->e235 * b->e6 + a->e23 * b->e56 + a->e25 * b->e36 
            + a->e35 * b->e26 + a->e26 * b->e35 + a->e36 * b->e25 
            + a->e56 * b->e23;
  res->e1456 = c->e1456 + a->r * b->e1456 + a->e1456 * b->r + a->e1 * b->e456 
            + a->e456 * b->e1 + a->e4 * b->e156 + a->e156 * b->e4 
            + a->e5 * b->e146 + a->e146 * b->e5 + a->e6 * b->e145 
            + a->e145 * b->e6 + a->e14 * b->e56 + a->e15 * b->e46 
            + a->e45 * b->e16 + a->e16 * b->e45 + a->e46 * b->e15 
            + a->e56 * b->e14;
  res->e2456 = c->e2456 + a->r * b->e2456 + a->e2456 * b->r + a->e2 * b->e456 
            + a->e456 * b->e2 + a->e4 * b->e256 + a->e256 * b->e4 
            + a->e5 * b->e246 + a->e246 * b->e5 + a->e6 * b->e245 
            + a->e245 * b->e6 + a->e24 * b->e56 + a->e25 * b->e46 
            + a->e45 * b->e26 + a->e26 * b->e45 + a->e46 * b->e25 
            + a->e56 * b->e24;
  res->e3456 = c->e3456 + a->r * b->e3456 + a->e3456 * b->r + a->e3 * b->e456 
            + a->e456 * b->e3 + a->e4 * b->e356 + a->e356 * b->e4 
            + a->e5 * b->e346 + a->e346 * b->e5 + a->e6 * b->e345 
            + a->e345 * b->e6 + a->e34 * b->e56 + a->e35 * b->e46 
            + a->e45 * b->e36 + a->e36 * b->e45 + a->e46 * b->e35 
            + a->e56 * b->e34;
  res->e1237 = c->e1237 + a->r * b->e1237 + a->e1237 * b->r + a->e1 * b->e237 
            + a->e237 * b->e1 + a->e2 * b->e137 + a->e137 * b->e2 
            + a->e3 * b->e127 + a->e127 * b->e3 + a->e7 * b->e123 
            + a->e123 * b->e7 + a->e12 * b->e37 + a->e13 * b->e27 
            + a->e23 * b->e17 + a->e17 * b->e23 + a->e27 * b->e13 
            + a->e37 * b->e12;
  res->e1247 = c->e1247 + a->r * b->e1247 + a->e1247 * b->r + a->e1 * b->e247 
            + a->e247 * b->e1 + a->e2 * b->e147 + a->e147 * b->e2 
            + a->e4 * b->e127 + a->e127 * b->e4 + a->e7 * b->e124 
            + a->e124 * b->e7 + a->e12 * b->e47 + a->e14 * b->e27 
            + a->e24 * b->e17 + a->e17 * b->e24 + a->e27 * b->e14 
            + a->e47 * b->e12;
  res->e1347 = c->e1347 + a->r * b->e1347 + a->e1347 * b->r + a->e1 * b->e347 
            + a->e347 * b->e1 + a->e3 * b->e147 + a->e147 * b->e3 
            + a->e4 * b->e137 + a->e137 * b->e4 + a->e7 * b->e134 
            + a->e134 * b->e7 + a->e13 * b->e47 + a->e14 * b->e37 
            + a->e34 * b->e17 + a->e17 * b->e34 + a->e37 * b->e14 
            + a->e47 * b->e13;
  res->e2347 = c->e2347 + a->r * b->e2347 + a->e2347 * b->r + a->e2 * b->e347 
            + a->e347 * b->e2 + a->e3 * b->e247 + a->e247 * b->e3 
            + a->e4 * b->e237 + a->e237 * b->e4 + a->e7 * b->e234 
            + a->e234 * b->e7 + a->e23 * b->e47 + a->e24 * b->e37 
            + a->e34 * b->e27 + a->e27 * b->e34 + a->e37 * b->e24 
            + a->e47 * b->e23;
  res->e1257 = c->e1257 + a->r * b->e1257 + a->e1257 * b->r + a->e1 * b->e257 
            + a->e257 * b->e1 + a->e2 * b->e157 + a->e157 * b->e2 
            + a->e5 * b->e127 + a->e127 * b->e5 + a->e7 * b->e125 
            + a->e125 * b->e7 + a->e12 * b->e57 + a->e15 * b->e27 
            + a->e25 * b->e17 + a->e17 * b->e25 + a->e27 * b->e15 
            + a->e57 * b->e12;
  res->e1357 = c->e1357 + a->r * b->e1357 + a->e1357 * b->r + a->e1 * b->e357 
            + a->e357 * b->e1 + a->e3 * b->e157 + a->e157 * b->e3 
            + a->e5 * b->e137 + a->e137 * b->e5 + a->e7 * b->e135 
            + a->e135 * b->e7 + a->e13 * b->e57 + a->e15 * b->e37 
            + a->e35 * b->e17 + a->e17 * b->e35 + a->e37 * b->e15 
            + a->e57 * b->e13;
  res->e2357 = c->e2357 + a->r * b->e2357 + a->e2357 * b->r + a->e2 * b->e357 
            + a->e357 * b->e2 + a->e3 * b->e257 + a->e257 * b->e3 
            + a->e5 * b->e237 + a->e237 * b->e5 + a->e7 * b->e235 
            + a->e235 * b->e7 + a->e23 * b->e57 + a->e25 * b->e37 
            + a->e35 * b->e27 + a->e27 * b->e35 + a->e37 * b->e25 
            + a->e57 * b->e23;
  res->e1457 = c->e1457 + a->r * b->e1457 + a->e1457 * b->r + a->e1 * b->e457 
            + a->e457 * b->e1 + a->e4 * b->e157 + a->e157 * b->e4 
            + a->e5 * b->e147 + a->e147 * b->e5 + a->e7 * b->e145 
            + a->e145 * b->e7 + a->e14 * b->e57 + a->e15 * b->e47 
            + a->e45 * b->e17 + a->e17 * b->e45 + a->e47 * b->e15 
            + a->e57 * b->e14;
  res->e2457 = c->e2457 + a->r * b->e2457 + a->e2457 * b->r + a->e2 * b->e457 
            + a->e457 * b->e2 + a->e4 * b->e257 + a->e257 * b->e4 
            + a->e5 * b->e247 + a->e247 * b->e5 + a->e7 * b->e245 
            + a->e245 * b->e7 + a->e24 * b->e57 + a->e25 * b->e47 
            + a->e45 * b->e27 + a->e27 * b->e45 + a->e47 * b->e25 
            + a->e57 * b->e24;
  res->e3457 = c->e3457 + a->r * b->e3457 + a->e3457 * b->r + a->e3 * b->e457 
            + a->e457 * b->e3 + a->e4 * b->e357 + a->e357 * b->e4 
            + a->e5 * b->e347 + a->e347 * b->e5 + a->e7 * b->e345 
            + a->e345 * b->e7 + a->e34 * b->e57 + a->e35 * b->e47 
            + a->e45 * b->e37 + a->e37 * b->e45 + a->e47 * b->e35 
            + a->e57 * b->e34;
  res->e1267 = c->e1267 + a->r * b->e1267 + a->e1267 * b->r + a->e1 * b->e267 
            + a->e267 * b->e1 + a->e2 * b->e167 + a->e167 * b->e2 
            + a->e6 * b->e127 + a->e127 * b->e6 + a->e7 * b->e126 
            + a->e126 * b->e7 + a->e12 * b->e67 + a->e16 * b->e27 
            + a->e26 * b->e17 + a->e17 * b->e26 + a->e27 * b->e16 
            + a->e67 * b->e12;
  res->e1367 = c->e1367 + a->r * b->e1367 + a->e1367 * b->r + a->e1 * b->e367 
            + a->e367 * b->e1 + a->e3 * b->e167 + a->e167 * b->e3 
            + a->e6 * b->e137 + a->e137 * b->e6 + a->e7 * b->e136 
            + a->e136 * b->e7 + a->e13 * b->e67 + a->e16 * b->e37 
            + a->e36 * b->e17 + a->e17 * b->e36 + a->e37 * b->e16 
            + a->e67 * b->e13;
  res->e2367 = c->e2367 + a->r * b->e2367 + a->e2367 * b->r + a->e2 * b->e367 
            + a->e367 * b->e2 + a->e3 * b->e267 + a->e267 * b->e3 
            + a->e6 * b->e237 + a->e237 * b->e6 + a->e7 * b->e236 
            + a->e236 * b->e7 + a->e23 * b->e67 + a->e26 * b->e37 
            + a->e36 * b->e27 + a->e27 * b->e36 + a->e37 * b->e26 
            + a->e67 * b->e23;
  res->e1467 = c->e1467 + a->r * b->e1467 + a->e1467 * b->r + a->e1 * b->e467 
            + a->e467 * b->e1 + a->e4 * b->e167 + a->e167 * b->e4 
            + a->e6 * b->e147 + a->e147 * b->e6 + a->e7 * b->e146 
            + a->e146 * b->e7 + a->e14 * b->e67 + a->e16 * b->e47 
            + a->e46 * b->e17 + a->e17 * b->e46 + a->e47 * b->e16 
            + a->e67 * b->e14;
  res->e2467 = c->e2467 + a->r * b->e2467 + a->e2467 * b->r + a->e2 * b->e467 
            + a->e467 * b->e2 + a->e4 * b->e267 + a->e267 * b->e4 
            + a->e6 * b->e247 + a->e247 * b->e6 + a->e7 * b->e246 
            + a->e246 * b->e7 + a->e24 * b->e67 + a->e26 * b->e47 
            + a->e46 * b->e27 + a->e27 * b->e46 + a->e47 * b->e26 
            + a->e67 * b->e24;
  res->e3467 = c->e3467 + a->r * b->e3467 + a->e3467 * b->r + a->e3 * b->e467 
            + a->e467 * b->e3 + a->e4 * b->e367 + a->e367 * b->e4 
            + a->e6 * b->e347 + a->e347 * b->e6 + a->e7 * b->e346 
            + a->e346 * b->e7 + a->e34 * b->e67 + a->e36 * b->e47 
            + a->e46 * b->e37 + a->e37 * b->e46 + a->e47 * b->e36 
            + a->e67 * b->e34;
  res->e1567 = c->e1567 + a->r * b->e1567 + a->e1567 * b->r + a->e1 * b->e567 
            + a->e567 * b->e1 + a->e5 * b->e167 + a->e167 * b->e5 
            + a->e6 * b->e157 + a->e157 * b->e6 + a->e7 * b->e156 
            + a->e156 * b->e7 + a->e15 * b->e67 + a->e16 * b->e57 
            + a->e56 * b->e17 + a->e17 * b->e56 + a->e57 * b->e16 
            + a->e67 * b->e15;
  res->e2567 = c->e2567 + a->r * b->e2567 + a->e2567 * b->r + a->e2 * b->e567 
            + a->e567 * b->e2 + a->e5 * b->e267 + a->e267 * b->e5 
            + a->e6 * b->e257 + a->e257 * b->e6 + a->e7 * b->e256 
            + a->e256 * b->e7 + a->e25 * b->e67 + a->e26 * b->e57 
            + a->e56 * b->e27 + a->e27 * b->e56 + a->e57 * b->e26 
            + a->e67 * b->e25;
  res->e3567 = c->e3567 + a->r * b->e3567 + a->e3567 * b->r + a->e3 * b->e567 
            + a->e567 * b->e3 + a->e5 * b->e367 + a->e367 * b->e5 
            + a->e6 * b->e357 + a->e357 * b->e6 + a->e7 * b->e356 
            + a->e356 * b->e7 + a->e35 * b->e67 + a->e36 * b->e57 
            + a->e56 * b->e37 + a->e37 * b->e56 + a->e57 * b->e36 
            + a->e67 * b->e35;
  res->e4567 = c->e4567 + a->r * b->e4567 + a->e4567 * b->r + a->e4 * b->e567 
            + a->e567 * b->e4 + a->e5 * b->e467 + a->e467 * b->e5 
            + a->e6 * b->e457 + a->e457 * b->e6 + a->e7 * b->e456 
            + a->e456 * b->e7 + a->e45 * b->e67 + a->e46 * b->e57 
            + a->e56 * b->e47 + a->e47 * b->e56 + a->e57 * b->e46 
            + a->e67 * b->e45;
  // Order 5;
  res->e12345 = c->e12345 + a->r * b->e12345 + a->e12345 * b->r + a->e1 * b->e2345 
             + a->e2345 * b->e1 + a->e2 * b->e1345 + a->e1345 * b->e2 
             + a->e3 * b->e1245 + a->e1245 * b->e3 + a->e4 * b->e1235 
             + a->e1235 * b->e4 + a->e5 * b->e1234 + a->e1234 * b->e5 
             + a->e12 * b->e345 + a->e345 * b->e12 + a->e13 * b->e245 
             + a->e245 * b->e13 + a->e23 * b->e145 + a->e145 * b->e23 
             + a->e14 * b->e235 + a->e235 * b->e14 + a->e24 * b->e135 
             + a->e135 * b->e24 + a->e34 * b->e125 + a->e125 * b->e34 
             + a->e15 * b->e234 + a->e234 * b->e15 + a->e25 * b->e134 
             + a->e134 * b->e25 + a->e35 * b->e124 + a->e124 * b->e35 
             + a->e45 * b->e123 + a->e123 * b->e45;
  res->e12346 = c->e12346 + a->r * b->e12346 + a->e12346 * b->r + a->e1 * b->e2346 
             + a->e2346 * b->e1 + a->e2 * b->e1346 + a->e1346 * b->e2 
             + a->e3 * b->e1246 + a->e1246 * b->e3 + a->e4 * b->e1236 
             + a->e1236 * b->e4 + a->e6 * b->e1234 + a->e1234 * b->e6 
             + a->e12 * b->e346 + a->e346 * b->e12 + a->e13 * b->e246 
             + a->e246 * b->e13 + a->e23 * b->e146 + a->e146 * b->e23 
             + a->e14 * b->e236 + a->e236 * b->e14 + a->e24 * b->e136 
             + a->e136 * b->e24 + a->e34 * b->e126 + a->e126 * b->e34 
             + a->e16 * b->e234 + a->e234 * b->e16 + a->e26 * b->e134 
             + a->e134 * b->e26 + a->e36 * b->e124 + a->e124 * b->e36 
             + a->e46 * b->e123 + a->e123 * b->e46;
  res->e12356 = c->e12356 + a->r * b->e12356 + a->e12356 * b->r + a->e1 * b->e2356 
             + a->e2356 * b->e1 + a->e2 * b->e1356 + a->e1356 * b->e2 
             + a->e3 * b->e1256 + a->e1256 * b->e3 + a->e5 * b->e1236 
             + a->e1236 * b->e5 + a->e6 * b->e1235 + a->e1235 * b->e6 
             + a->e12 * b->e356 + a->e356 * b->e12 + a->e13 * b->e256 
             + a->e256 * b->e13 + a->e23 * b->e156 + a->e156 * b->e23 
             + a->e15 * b->e236 + a->e236 * b->e15 + a->e25 * b->e136 
             + a->e136 * b->e25 + a->e35 * b->e126 + a->e126 * b->e35 
             + a->e16 * b->e235 + a->e235 * b->e16 + a->e26 * b->e135 
             + a->e135 * b->e26 + a->e36 * b->e125 + a->e125 * b->e36 
             + a->e56 * b->e123 + a->e123 * b->e56;
  res->e12456 = c->e12456 + a->r * b->e12456 + a->e12456 * b->r + a->e1 * b->e2456 
             + a->e2456 * b->e1 + a->e2 * b->e1456 + a->e1456 * b->e2 
             + a->e4 * b->e1256 + a->e1256 * b->e4 + a->e5 * b->e1246 
             + a->e1246 * b->e5 + a->e6 * b->e1245 + a->e1245 * b->e6 
             + a->e12 * b->e456 + a->e456 * b->e12 + a->e14 * b->e256 
             + a->e256 * b->e14 + a->e24 * b->e156 + a->e156 * b->e24 
             + a->e15 * b->e246 + a->e246 * b->e15 + a->e25 * b->e146 
             + a->e146 * b->e25 + a->e45 * b->e126 + a->e126 * b->e45 
             + a->e16 * b->e245 + a->e245 * b->e16 + a->e26 * b->e145 
             + a->e145 * b->e26 + a->e46 * b->e125 + a->e125 * b->e46 
             + a->e56 * b->e124 + a->e124 * b->e56;
  res->e13456 = c->e13456 + a->r * b->e13456 + a->e13456 * b->r + a->e1 * b->e3456 
             + a->e3456 * b->e1 + a->e3 * b->e1456 + a->e1456 * b->e3 
             + a->e4 * b->e1356 + a->e1356 * b->e4 + a->e5 * b->e1346 
             + a->e1346 * b->e5 + a->e6 * b->e1345 + a->e1345 * b->e6 
             + a->e13 * b->e456 + a->e456 * b->e13 + a->e14 * b->e356 
             + a->e356 * b->e14 + a->e34 * b->e156 + a->e156 * b->e34 
             + a->e15 * b->e346 + a->e346 * b->e15 + a->e35 * b->e146 
             + a->e146 * b->e35 + a->e45 * b->e136 + a->e136 * b->e45 
             + a->e16 * b->e345 + a->e345 * b->e16 + a->e36 * b->e145 
             + a->e145 * b->e36 + a->e46 * b->e135 + a->e135 * b->e46 
             + a->e56 * b->e134 + a->e134 * b->e56;
  res->e23456 = c->e23456 + a->r * b->e23456 + a->e23456 * b->r + a->e2 * b->e3456 
             + a->e3456 * b->e2 + a->e3 * b->e2456 + a->e2456 * b->e3 
             + a->e4 * b->e2356 + a->e2356 * b->e4 + a->e5 * b->e2346 
             + a->e2346 * b->e5 + a->e6 * b->e2345 + a->e2345 * b->e6 
             + a->e23 * b->e456 + a->e456 * b->e23 + a->e24 * b->e356 
             + a->e356 * b->e24 + a->e34 * b->e256 + a->e256 * b->e34 
             + a->e25 * b->e346 + a->e346 * b->e25 + a->e35 * b->e246 
             + a->e246 * b->e35 + a->e45 * b->e236 + a->e236 * b->e45 
             + a->e26 * b->e345 + a->e345 * b->e26 + a->e36 * b->e245 
             + a->e245 * b->e36 + a->e46 * b->e235 + a->e235 * b->e46 
             + a->e56 * b->e234 + a->e234 * b->e56;
  res->e12347 = c->e12347 + a->r * b->e12347 + a->e12347 * b->r + a->e1 * b->e2347 
             + a->e2347 * b->e1 + a->e2 * b->e1347 + a->e1347 * b->e2 
             + a->e3 * b->e1247 + a->e1247 * b->e3 + a->e4 * b->e1237 
             + a->e1237 * b->e4 + a->e7 * b->e1234 + a->e1234 * b->e7 
             + a->e12 * b->e347 + a->e347 * b->e12 + a->e13 * b->e247 
             + a->e247 * b->e13 + a->e23 * b->e147 + a->e147 * b->e23 
             + a->e14 * b->e237 + a->e237 * b->e14 + a->e24 * b->e137 
             + a->e137 * b->e24 + a->e34 * b->e127 + a->e127 * b->e34 
             + a->e17 * b->e234 + a->e234 * b->e17 + a->e27 * b->e134 
             + a->e134 * b->e27 + a->e37 * b->e124 + a->e124 * b->e37 
             + a->e47 * b->e123 + a->e123 * b->e47;
  res->e12357 = c->e12357 + a->r * b->e12357 + a->e12357 * b->r + a->e1 * b->e2357 
             + a->e2357 * b->e1 + a->e2 * b->e1357 + a->e1357 * b->e2 
             + a->e3 * b->e1257 + a->e1257 * b->e3 + a->e5 * b->e1237 
             + a->e1237 * b->e5 + a->e7 * b->e1235 + a->e1235 * b->e7 
             + a->e12 * b->e357 + a->e357 * b->e12 + a->e13 * b->e257 
             + a->e257 * b->e13 + a->e23 * b->e157 + a->e157 * b->e23 
             + a->e15 * b->e237 + a->e237 * b->e15 + a->e25 * b->e137 
             + a->e137 * b->e25 + a->e35 * b->e127 + a->e127 * b->e35 
             + a->e17 * b->e235 + a->e235 * b->e17 + a->e27 * b->e135 
             + a->e135 * b->e27 + a->e37 * b->e125 + a->e125 * b->e37 
             + a->e57 * b->e123 + a->e123 * b->e57;
  res->e12457 = c->e12457 + a->r * b->e12457 + a->e12457 * b->r + a->e1 * b->e2457 
             + a->e2457 * b->e1 + a->e2 * b->e1457 + a->e1457 * b->e2 
             + a->e4 * b->e1257 + a->e1257 * b->e4 + a->e5 * b->e1247 
             + a->e1247 * b->e5 + a->e7 * b->e1245 + a->e1245 * b->e7 
             + a->e12 * b->e457 + a->e457 * b->e12 + a->e14 * b->e257 
             + a->e257 * b->e14 + a->e24 * b->e157 + a->e157 * b->e24 
             + a->e15 * b->e247 + a->e247 * b->e15 + a->e25 * b->e147 
             + a->e147 * b->e25 + a->e45 * b->e127 + a->e127 * b->e45 
             + a->e17 * b->e245 + a->e245 * b->e17 + a->e27 * b->e145 
             + a->e145 * b->e27 + a->e47 * b->e125 + a->e125 * b->e47 
             + a->e57 * b->e124 + a->e124 * b->e57;
  res->e13457 = c->e13457 + a->r * b->e13457 + a->e13457 * b->r + a->e1 * b->e3457 
             + a->e3457 * b->e1 + a->e3 * b->e1457 + a->e1457 * b->e3 
             + a->e4 * b->e1357 + a->e1357 * b->e4 + a->e5 * b->e1347 
             + a->e1347 * b->e5 + a->e7 * b->e1345 + a->e1345 * b->e7 
             + a->e13 * b->e457 + a->e457 * b->e13 + a->e14 * b->e357 
             + a->e357 * b->e14 + a->e34 * b->e157 + a->e157 * b->e34 
             + a->e15 * b->e347 + a->e347 * b->e15 + a->e35 * b->e147 
             + a->e147 * b->e35 + a->e45 * b->e137 + a->e137 * b->e45 
             + a->e17 * b->e345 + a->e345 * b->e17 + a->e37 * b->e145 
             + a->e145 * b->e37 + a->e47 * b->e135 + a->e135 * b->e47 
             + a->e57 * b->e134 + a->e134 * b->e57;
  res->e23457 = c->e23457 + a->r * b->e23457 + a->e23457 * b->r + a->e2 * b->e3457 
             + a->e3457 * b->e2 + a->e3 * b->e2457 + a->e2457 * b->e3 
             + a->e4 * b->e2357 + a->e2357 * b->e4 + a->e5 * b->e2347 
             + a->e2347 * b->e5 + a->e7 * b->e2345 + a->e2345 * b->e7 
             + a->e23 * b->e457 + a->e457 * b->e23 + a->e24 * b->e357 
             + a->e357 * b->e24 + a->e34 * b->e257 + a->e257 * b->e34 
             + a->e25 * b->e347 + a->e347 * b->e25 + a->e35 * b->e247 
             + a->e247 * b->e35 + a->e45 * b->e237 + a->e237 * b->e45 
             + a->e27 * b->e345 + a->e345 * b->e27 + a->e37 * b->e245 
             + a->e245 * b->e37 + a->e47 * b->e235 + a->e235 * b->e47 
             + a->e57 * b->e234 + a->e234 * b->e57;
  res->e12367 = c->e12367 + a->r * b->e12367 + a->e12367 * b->r + a->e1 * b->e2367 
             + a->e2367 * b->e1 + a->e2 * b->e1367 + a->e1367 * b->e2 
             + a->e3 * b->e1267 + a->e1267 * b->e3 + a->e6 * b->e1237 
             + a->e1237 * b->e6 + a->e7 * b->e1236 + a->e1236 * b->e7 
             + a->e12 * b->e367 + a->e367 * b->e12 + a->e13 * b->e267 
             + a->e267 * b->e13 + a->e23 * b->e167 + a->e167 * b->e23 
             + a->e16 * b->e237 + a->e237 * b->e16 + a->e26 * b->e137 
             + a->e137 * b->e26 + a->e36 * b->e127 + a->e127 * b->e36 
             + a->e17 * b->e236 + a->e236 * b->e17 + a->e27 * b->e136 
             + a->e136 * b->e27 + a->e37 * b->e126 + a->e126 * b->e37 
             + a->e67 * b->e123 + a->e123 * b->e67;
  res->e12467 = c->e12467 + a->r * b->e12467 + a->e12467 * b->r + a->e1 * b->e2467 
             + a->e2467 * b->e1 + a->e2 * b->e1467 + a->e1467 * b->e2 
             + a->e4 * b->e1267 + a->e1267 * b->e4 + a->e6 * b->e1247 
             + a->e1247 * b->e6 + a->e7 * b->e1246 + a->e1246 * b->e7 
             + a->e12 * b->e467 + a->e467 * b->e12 + a->e14 * b->e267 
             + a->e267 * b->e14 + a->e24 * b->e167 + a->e167 * b->e24 
             + a->e16 * b->e247 + a->e247 * b->e16 + a->e26 * b->e147 
             + a->e147 * b->e26 + a->e46 * b->e127 + a->e127 * b->e46 
             + a->e17 * b->e246 + a->e246 * b->e17 + a->e27 * b->e146 
             + a->e146 * b->e27 + a->e47 * b->e126 + a->e126 * b->e47 
             + a->e67 * b->e124 + a->e124 * b->e67;
  res->e13467 = c->e13467 + a->r * b->e13467 + a->e13467 * b->r + a->e1 * b->e3467 
             + a->e3467 * b->e1 + a->e3 * b->e1467 + a->e1467 * b->e3 
             + a->e4 * b->e1367 + a->e1367 * b->e4 + a->e6 * b->e1347 
             + a->e1347 * b->e6 + a->e7 * b->e1346 + a->e1346 * b->e7 
             + a->e13 * b->e467 + a->e467 * b->e13 + a->e14 * b->e367 
             + a->e367 * b->e14 + a->e34 * b->e167 + a->e167 * b->e34 
             + a->e16 * b->e347 + a->e347 * b->e16 + a->e36 * b->e147 
             + a->e147 * b->e36 + a->e46 * b->e137 + a->e137 * b->e46 
             + a->e17 * b->e346 + a->e346 * b->e17 + a->e37 * b->e146 
             + a->e146 * b->e37 + a->e47 * b->e136 + a->e136 * b->e47 
             + a->e67 * b->e134 + a->e134 * b->e67;
  res->e23467 = c->e23467 + a->r * b->e23467 + a->e23467 * b->r + a->e2 * b->e3467 
             + a->e3467 * b->e2 + a->e3 * b->e2467 + a->e2467 * b->e3 
             + a->e4 * b->e2367 + a->e2367 * b->e4 + a->e6 * b->e2347 
             + a->e2347 * b->e6 + a->e7 * b->e2346 + a->e2346 * b->e7 
             + a->e23 * b->e467 + a->e467 * b->e23 + a->e24 * b->e367 
             + a->e367 * b->e24 + a->e34 * b->e267 + a->e267 * b->e34 
             + a->e26 * b->e347 + a->e347 * b->e26 + a->e36 * b->e247 
             + a->e247 * b->e36 + a->e46 * b->e237 + a->e237 * b->e46 
             + a->e27 * b->e346 + a->e346 * b->e27 + a->e37 * b->e246 
             + a->e246 * b->e37 + a->e47 * b->e236 + a->e236 * b->e47 
             + a->e67 * b->e234 + a->e234 * b->e67;
  res->e12567 = c->e12567 + a->r * b->e12567 + a->e12567 * b->r + a->e1 * b->e2567 
             + a->e2567 * b->e1 + a->e2 * b->e1567 + a->e1567 * b->e2 
             + a->e5 * b->e1267 + a->e1267 * b->e5 + a->e6 * b->e1257 
             + a->e1257 * b->e6 + a->e7 * b->e1256 + a->e1256 * b->e7 
             + a->e12 * b->e567 + a->e567 * b->e12 + a->e15 * b->e267 
             + a->e267 * b->e15 + a->e25 * b->e167 + a->e167 * b->e25 
             + a->e16 * b->e257 + a->e257 * b->e16 + a->e26 * b->e157 
             + a->e157 * b->e26 + a->e56 * b->e127 + a->e127 * b->e56 
             + a->e17 * b->e256 + a->e256 * b->e17 + a->e27 * b->e156 
             + a->e156 * b->e27 + a->e57 * b->e126 + a->e126 * b->e57 
             + a->e67 * b->e125 + a->e125 * b->e67;
  res->e13567 = c->e13567 + a->r * b->e13567 + a->e13567 * b->r + a->e1 * b->e3567 
             + a->e3567 * b->e1 + a->e3 * b->e1567 + a->e1567 * b->e3 
             + a->e5 * b->e1367 + a->e1367 * b->e5 + a->e6 * b->e1357 
             + a->e1357 * b->e6 + a->e7 * b->e1356 + a->e1356 * b->e7 
             + a->e13 * b->e567 + a->e567 * b->e13 + a->e15 * b->e367 
             + a->e367 * b->e15 + a->e35 * b->e167 + a->e167 * b->e35 
             + a->e16 * b->e357 + a->e357 * b->e16 + a->e36 * b->e157 
             + a->e157 * b->e36 + a->e56 * b->e137 + a->e137 * b->e56 
             + a->e17 * b->e356 + a->e356 * b->e17 + a->e37 * b->e156 
             + a->e156 * b->e37 + a->e57 * b->e136 + a->e136 * b->e57 
             + a->e67 * b->e135 + a->e135 * b->e67;
  res->e23567 = c->e23567 + a->r * b->e23567 + a->e23567 * b->r + a->e2 * b->e3567 
             + a->e3567 * b->e2 + a->e3 * b->e2567 + a->e2567 * b->e3 
             + a->e5 * b->e2367 + a->e2367 * b->e5 + a->e6 * b->e2357 
             + a->e2357 * b->e6 + a->e7 * b->e2356 + a->e2356 * b->e7 
             + a->e23 * b->e567 + a->e567 * b->e23 + a->e25 * b->e367 
             + a->e367 * b->e25 + a->e35 * b->e267 + a->e267 * b->e35 
             + a->e26 * b->e357 + a->e357 * b->e26 + a->e36 * b->e257 
             + a->e257 * b->e36 + a->e56 * b->e237 + a->e237 * b->e56 
             + a->e27 * b->e356 + a->e356 * b->e27 + a->e37 * b->e256 
             + a->e256 * b->e37 + a->e57 * b->e236 + a->e236 * b->e57 
             + a->e67 * b->e235 + a->e235 * b->e67;
  res->e14567 = c->e14567 + a->r * b->e14567 + a->e14567 * b->r + a->e1 * b->e4567 
             + a->e4567 * b->e1 + a->e4 * b->e1567 + a->e1567 * b->e4 
             + a->e5 * b->e1467 + a->e1467 * b->e5 + a->e6 * b->e1457 
             + a->e1457 * b->e6 + a->e7 * b->e1456 + a->e1456 * b->e7 
             + a->e14 * b->e567 + a->e567 * b->e14 + a->e15 * b->e467 
             + a->e467 * b->e15 + a->e45 * b->e167 + a->e167 * b->e45 
             + a->e16 * b->e457 + a->e457 * b->e16 + a->e46 * b->e157 
             + a->e157 * b->e46 + a->e56 * b->e147 + a->e147 * b->e56 
             + a->e17 * b->e456 + a->e456 * b->e17 + a->e47 * b->e156 
             + a->e156 * b->e47 + a->e57 * b->e146 + a->e146 * b->e57 
             + a->e67 * b->e145 + a->e145 * b->e67;
  res->e24567 = c->e24567 + a->r * b->e24567 + a->e24567 * b->r + a->e2 * b->e4567 
             + a->e4567 * b->e2 + a->e4 * b->e2567 + a->e2567 * b->e4 
             + a->e5 * b->e2467 + a->e2467 * b->e5 + a->e6 * b->e2457 
             + a->e2457 * b->e6 + a->e7 * b->e2456 + a->e2456 * b->e7 
             + a->e24 * b->e567 + a->e567 * b->e24 + a->e25 * b->e467 
             + a->e467 * b->e25 + a->e45 * b->e267 + a->e267 * b->e45 
             + a->e26 * b->e457 + a->e457 * b->e26 + a->e46 * b->e257 
             + a->e257 * b->e46 + a->e56 * b->e247 + a->e247 * b->e56 
             + a->e27 * b->e456 + a->e456 * b->e27 + a->e47 * b->e256 
             + a->e256 * b->e47 + a->e57 * b->e246 + a->e246 * b->e57 
             + a->e67 * b->e245 + a->e245 * b->e67;
  res->e34567 = c->e34567 + a->r * b->e34567 + a->e34567 * b->r + a->e3 * b->e4567 
             + a->e4567 * b->e3 + a->e4 * b->e3567 + a->e3567 * b->e4 
             + a->e5 * b->e3467 + a->e3467 * b->e5 + a->e6 * b->e3457 
             + a->e3457 * b->e6 + a->e7 * b->e3456 + a->e3456 * b->e7 
             + a->e34 * b->e567 + a->e567 * b->e34 + a->e35 * b->e467 
             + a->e467 * b->e35 + a->e45 * b->e367 + a->e367 * b->e45 
             + a->e36 * b->e457 + a->e457 * b->e36 + a->e46 * b->e357 
             + a->e357 * b->e46 + a->e56 * b->e347 + a->e347 * b->e56 
             + a->e37 * b->e456 + a->e456 * b->e37 + a->e47 * b->e356 
             + a->e356 * b->e47 + a->e57 * b->e346 + a->e346 * b->e57 
             + a->e67 * b->e345 + a->e345 * b->e67;
  // Order 6;
  res->e123456 = c->e123456 + a->r * b->e123456 + a->e123456 * b->r + a->e1 * b->e23456 
              + a->e23456 * b->e1 + a->e2 * b->e13456 + a->e13456 * b->e2 
              + a->e3 * b->e12456 + a->e12456 * b->e3 + a->e4 * b->e12356 
              + a->e12356 * b->e4 + a->e5 * b->e12346 + a->e12346 * b->e5 
              + a->e6 * b->e12345 + a->e12345 * b->e6 + a->e12 * b->e3456 
              + a->e3456 * b->e12 + a->e13 * b->e2456 + a->e2456 * b->e13 
              + a->e23 * b->e1456 + a->e1456 * b->e23 + a->e14 * b->e2356 
              + a->e2356 * b->e14 + a->e24 * b->e1356 + a->e1356 * b->e24 
              + a->e34 * b->e1256 + a->e1256 * b->e34 + a->e15 * b->e2346 
              + a->e2346 * b->e15 + a->e25 * b->e1346 + a->e1346 * b->e25 
              + a->e35 * b->e1246 + a->e1246 * b->e35 + a->e45 * b->e1236 
              + a->e1236 * b->e45 + a->e16 * b->e2345 + a->e2345 * b->e16 
              + a->e26 * b->e1345 + a->e1345 * b->e26 + a->e36 * b->e1245 
              + a->e1245 * b->e36 + a->e46 * b->e1235 + a->e1235 * b->e46 
              + a->e56 * b->e1234 + a->e1234 * b->e56 + a->e123 * b->e456 
              + a->e124 * b->e356 + a->e134 * b->e256 + a->e234 * b->e156 
              + a->e125 * b->e346 + a->e135 * b->e246 + a->e235 * b->e146 
              + a->e145 * b->e236 + a->e245 * b->e136 + a->e345 * b->e126 
              + a->e126 * b->e345 + a->e136 * b->e245 + a->e236 * b->e145 
              + a->e146 * b->e235 + a->e246 * b->e135 + a->e346 * b->e125 
              + a->e156 * b->e234 + a->e256 * b->e134 + a->e356 * b->e124 
              + a->e456 * b->e123;
  res->e123457 = c->e123457 + a->r * b->e123457 + a->e123457 * b->r + a->e1 * b->e23457 
              + a->e23457 * b->e1 + a->e2 * b->e13457 + a->e13457 * b->e2 
              + a->e3 * b->e12457 + a->e12457 * b->e3 + a->e4 * b->e12357 
              + a->e12357 * b->e4 + a->e5 * b->e12347 + a->e12347 * b->e5 
              + a->e7 * b->e12345 + a->e12345 * b->e7 + a->e12 * b->e3457 
              + a->e3457 * b->e12 + a->e13 * b->e2457 + a->e2457 * b->e13 
              + a->e23 * b->e1457 + a->e1457 * b->e23 + a->e14 * b->e2357 
              + a->e2357 * b->e14 + a->e24 * b->e1357 + a->e1357 * b->e24 
              + a->e34 * b->e1257 + a->e1257 * b->e34 + a->e15 * b->e2347 
              + a->e2347 * b->e15 + a->e25 * b->e1347 + a->e1347 * b->e25 
              + a->e35 * b->e1247 + a->e1247 * b->e35 + a->e45 * b->e1237 
              + a->e1237 * b->e45 + a->e17 * b->e2345 + a->e2345 * b->e17 
              + a->e27 * b->e1345 + a->e1345 * b->e27 + a->e37 * b->e1245 
              + a->e1245 * b->e37 + a->e47 * b->e1235 + a->e1235 * b->e47 
              + a->e57 * b->e1234 + a->e1234 * b->e57 + a->e123 * b->e457 
              + a->e124 * b->e357 + a->e134 * b->e257 + a->e234 * b->e157 
              + a->e125 * b->e347 + a->e135 * b->e247 + a->e235 * b->e147 
              + a->e145 * b->e237 + a->e245 * b->e137 + a->e345 * b->e127 
              + a->e127 * b->e345 + a->e137 * b->e245 + a->e237 * b->e145 
              + a->e147 * b->e235 + a->e247 * b->e135 + a->e347 * b->e125 
              + a->e157 * b->e234 + a->e257 * b->e134 + a->e357 * b->e124 
              + a->e457 * b->e123;
  res->e123467 = c->e123467 + a->r * b->e123467 + a->e123467 * b->r + a->e1 * b->e23467 
              + a->e23467 * b->e1 + a->e2 * b->e13467 + a->e13467 * b->e2 
              + a->e3 * b->e12467 + a->e12467 * b->e3 + a->e4 * b->e12367 
              + a->e12367 * b->e4 + a->e6 * b->e12347 + a->e12347 * b->e6 
              + a->e7 * b->e12346 + a->e12346 * b->e7 + a->e12 * b->e3467 
              + a->e3467 * b->e12 + a->e13 * b->e2467 + a->e2467 * b->e13 
              + a->e23 * b->e1467 + a->e1467 * b->e23 + a->e14 * b->e2367 
              + a->e2367 * b->e14 + a->e24 * b->e1367 + a->e1367 * b->e24 
              + a->e34 * b->e1267 + a->e1267 * b->e34 + a->e16 * b->e2347 
              + a->e2347 * b->e16 + a->e26 * b->e1347 + a->e1347 * b->e26 
              + a->e36 * b->e1247 + a->e1247 * b->e36 + a->e46 * b->e1237 
              + a->e1237 * b->e46 + a->e17 * b->e2346 + a->e2346 * b->e17 
              + a->e27 * b->e1346 + a->e1346 * b->e27 + a->e37 * b->e1246 
              + a->e1246 * b->e37 + a->e47 * b->e1236 + a->e1236 * b->e47 
              + a->e67 * b->e1234 + a->e1234 * b->e67 + a->e123 * b->e467 
              + a->e124 * b->e367 + a->e134 * b->e267 + a->e234 * b->e167 
              + a->e126 * b->e347 + a->e136 * b->e247 + a->e236 * b->e147 
              + a->e146 * b->e237 + a->e246 * b->e137 + a->e346 * b->e127 
              + a->e127 * b->e346 + a->e137 * b->e246 + a->e237 * b->e146 
              + a->e147 * b->e236 + a->e247 * b->e136 + a->e347 * b->e126 
              + a->e167 * b->e234 + a->e267 * b->e134 + a->e367 * b->e124 
              + a->e467 * b->e123;
  res->e123567 = c->e123567 + a->r * b->e123567 + a->e123567 * b->r + a->e1 * b->e23567 
              + a->e23567 * b->e1 + a->e2 * b->e13567 + a->e13567 * b->e2 
              + a->e3 * b->e12567 + a->e12567 * b->e3 + a->e5 * b->e12367 
              + a->e12367 * b->e5 + a->e6 * b->e12357 + a->e12357 * b->e6 
              + a->e7 * b->e12356 + a->e12356 * b->e7 + a->e12 * b->e3567 
              + a->e3567 * b->e12 + a->e13 * b->e2567 + a->e2567 * b->e13 
              + a->e23 * b->e1567 + a->e1567 * b->e23 + a->e15 * b->e2367 
              + a->e2367 * b->e15 + a->e25 * b->e1367 + a->e1367 * b->e25 
              + a->e35 * b->e1267 + a->e1267 * b->e35 + a->e16 * b->e2357 
              + a->e2357 * b->e16 + a->e26 * b->e1357 + a->e1357 * b->e26 
              + a->e36 * b->e1257 + a->e1257 * b->e36 + a->e56 * b->e1237 
              + a->e1237 * b->e56 + a->e17 * b->e2356 + a->e2356 * b->e17 
              + a->e27 * b->e1356 + a->e1356 * b->e27 + a->e37 * b->e1256 
              + a->e1256 * b->e37 + a->e57 * b->e1236 + a->e1236 * b->e57 
              + a->e67 * b->e1235 + a->e1235 * b->e67 + a->e123 * b->e567 
              + a->e125 * b->e367 + a->e135 * b->e267 + a->e235 * b->e167 
              + a->e126 * b->e357 + a->e136 * b->e257 + a->e236 * b->e157 
              + a->e156 * b->e237 + a->e256 * b->e137 + a->e356 * b->e127 
              + a->e127 * b->e356 + a->e137 * b->e256 + a->e237 * b->e156 
              + a->e157 * b->e236 + a->e257 * b->e136 + a->e357 * b->e126 
              + a->e167 * b->e235 + a->e267 * b->e135 + a->e367 * b->e125 
              + a->e567 * b->e123;
  res->e124567 = c->e124567 + a->r * b->e124567 + a->e124567 * b->r + a->e1 * b->e24567 
              + a->e24567 * b->e1 + a->e2 * b->e14567 + a->e14567 * b->e2 
              + a->e4 * b->e12567 + a->e12567 * b->e4 + a->e5 * b->e12467 
              + a->e12467 * b->e5 + a->e6 * b->e12457 + a->e12457 * b->e6 
              + a->e7 * b->e12456 + a->e12456 * b->e7 + a->e12 * b->e4567 
              + a->e4567 * b->e12 + a->e14 * b->e2567 + a->e2567 * b->e14 
              + a->e24 * b->e1567 + a->e1567 * b->e24 + a->e15 * b->e2467 
              + a->e2467 * b->e15 + a->e25 * b->e1467 + a->e1467 * b->e25 
              + a->e45 * b->e1267 + a->e1267 * b->e45 + a->e16 * b->e2457 
              + a->e2457 * b->e16 + a->e26 * b->e1457 + a->e1457 * b->e26 
              + a->e46 * b->e1257 + a->e1257 * b->e46 + a->e56 * b->e1247 
              + a->e1247 * b->e56 + a->e17 * b->e2456 + a->e2456 * b->e17 
              + a->e27 * b->e1456 + a->e1456 * b->e27 + a->e47 * b->e1256 
              + a->e1256 * b->e47 + a->e57 * b->e1246 + a->e1246 * b->e57 
              + a->e67 * b->e1245 + a->e1245 * b->e67 + a->e124 * b->e567 
              + a->e125 * b->e467 + a->e145 * b->e267 + a->e245 * b->e167 
              + a->e126 * b->e457 + a->e146 * b->e257 + a->e246 * b->e157 
              + a->e156 * b->e247 + a->e256 * b->e147 + a->e456 * b->e127 
              + a->e127 * b->e456 + a->e147 * b->e256 + a->e247 * b->e156 
              + a->e157 * b->e246 + a->e257 * b->e146 + a->e457 * b->e126 
              + a->e167 * b->e245 + a->e267 * b->e145 + a->e467 * b->e125 
              + a->e567 * b->e124;
  res->e134567 = c->e134567 + a->r * b->e134567 + a->e134567 * b->r + a->e1 * b->e34567 
              + a->e34567 * b->e1 + a->e3 * b->e14567 + a->e14567 * b->e3 
              + a->e4 * b->e13567 + a->e13567 * b->e4 + a->e5 * b->e13467 
              + a->e13467 * b->e5 + a->e6 * b->e13457 + a->e13457 * b->e6 
              + a->e7 * b->e13456 + a->e13456 * b->e7 + a->e13 * b->e4567 
              + a->e4567 * b->e13 + a->e14 * b->e3567 + a->e3567 * b->e14 
              + a->e34 * b->e1567 + a->e1567 * b->e34 + a->e15 * b->e3467 
              + a->e3467 * b->e15 + a->e35 * b->e1467 + a->e1467 * b->e35 
              + a->e45 * b->e1367 + a->e1367 * b->e45 + a->e16 * b->e3457 
              + a->e3457 * b->e16 + a->e36 * b->e1457 + a->e1457 * b->e36 
              + a->e46 * b->e1357 + a->e1357 * b->e46 + a->e56 * b->e1347 
              + a->e1347 * b->e56 + a->e17 * b->e3456 + a->e3456 * b->e17 
              + a->e37 * b->e1456 + a->e1456 * b->e37 + a->e47 * b->e1356 
              + a->e1356 * b->e47 + a->e57 * b->e1346 + a->e1346 * b->e57 
              + a->e67 * b->e1345 + a->e1345 * b->e67 + a->e134 * b->e567 
              + a->e135 * b->e467 + a->e145 * b->e367 + a->e345 * b->e167 
              + a->e136 * b->e457 + a->e146 * b->e357 + a->e346 * b->e157 
              + a->e156 * b->e347 + a->e356 * b->e147 + a->e456 * b->e137 
              + a->e137 * b->e456 + a->e147 * b->e356 + a->e347 * b->e156 
              + a->e157 * b->e346 + a->e357 * b->e146 + a->e457 * b->e136 
              + a->e167 * b->e345 + a->e367 * b->e145 + a->e467 * b->e135 
              + a->e567 * b->e134;
  res->e234567 = c->e234567 + a->r * b->e234567 + a->e234567 * b->r + a->e2 * b->e34567 
              + a->e34567 * b->e2 + a->e3 * b->e24567 + a->e24567 * b->e3 
              + a->e4 * b->e23567 + a->e23567 * b->e4 + a->e5 * b->e23467 
              + a->e23467 * b->e5 + a->e6 * b->e23457 + a->e23457 * b->e6 
              + a->e7 * b->e23456 + a->e23456 * b->e7 + a->e23 * b->e4567 
              + a->e4567 * b->e23 + a->e24 * b->e3567 + a->e3567 * b->e24 
              + a->e34 * b->e2567 + a->e2567 * b->e34 + a->e25 * b->e3467 
              + a->e3467 * b->e25 + a->e35 * b->e2467 + a->e2467 * b->e35 
              + a->e45 * b->e2367 + a->e2367 * b->e45 + a->e26 * b->e3457 
              + a->e3457 * b->e26 + a->e36 * b->e2457 + a->e2457 * b->e36 
              + a->e46 * b->e2357 + a->e2357 * b->e46 + a->e56 * b->e2347 
              + a->e2347 * b->e56 + a->e27 * b->e3456 + a->e3456 * b->e27 
              + a->e37 * b->e2456 + a->e2456 * b->e37 + a->e47 * b->e2356 
              + a->e2356 * b->e47 + a->e57 * b->e2346 + a->e2346 * b->e57 
              + a->e67 * b->e2345 + a->e2345 * b->e67 + a->e234 * b->e567 
              + a->e235 * b->e467 + a->e245 * b->e367 + a->e345 * b->e267 
              + a->e236 * b->e457 + a->e246 * b->e357 + a->e346 * b->e257 
              + a->e256 * b->e347 + a->e356 * b->e247 + a->e456 * b->e237 
              + a->e237 * b->e456 + a->e247 * b->e356 + a->e347 * b->e256 
              + a->e257 * b->e346 + a->e357 * b->e246 + a->e457 * b->e236 
              + a->e267 * b->e345 + a->e367 * b->e245 + a->e467 * b->e235 
              + a->e567 * b->e234;
  // Order 7;
  res->e1234567 = c->e1234567 + a->r * b->e1234567 + a->e1234567 * b->r + a->e1 * b->e234567 
               + a->e234567 * b->e1 + a->e2 * b->e134567 + a->e134567 * b->e2 
               + a->e3 * b->e124567 + a->e124567 * b->e3 + a->e4 * b->e123567 
               + a->e123567 * b->e4 + a->e5 * b->e123467 + a->e123467 * b->e5 
               + a->e6 * b->e123457 + a->e123457 * b->e6 + a->e7 * b->e123456 
               + a->e123456 * b->e7 + a->e12 * b->e34567 + a->e34567 * b->e12 
               + a->e13 * b->e24567 + a->e24567 * b->e13 + a->e23 * b->e14567 
               + a->e14567 * b->e23 + a->e14 * b->e23567 + a->e23567 * b->e14 
               + a->e24 * b->e13567 + a->e13567 * b->e24 + a->e34 * b->e12567 
               + a->e12567 * b->e34 + a->e15 * b->e23467 + a->e23467 * b->e15 
               + a->e25 * b->e13467 + a->e13467 * b->e25 + a->e35 * b->e12467 
               + a->e12467 * b->e35 + a->e45 * b->e12367 + a->e12367 * b->e45 
               + a->e16 * b->e23457 + a->e23457 * b->e16 + a->e26 * b->e13457 
               + a->e13457 * b->e26 + a->e36 * b->e12457 + a->e12457 * b->e36 
               + a->e46 * b->e12357 + a->e12357 * b->e46 + a->e56 * b->e12347 
               + a->e12347 * b->e56 + a->e17 * b->e23456 + a->e23456 * b->e17 
               + a->e27 * b->e13456 + a->e13456 * b->e27 + a->e37 * b->e12456 
               + a->e12456 * b->e37 + a->e47 * b->e12356 + a->e12356 * b->e47 
               + a->e57 * b->e12346 + a->e12346 * b->e57 + a->e67 * b->e12345 
               + a->e12345 * b->e67 + a->e123 * b->e4567 + a->e4567 * b->e123 
               + a->e124 * b->e3567 + a->e3567 * b->e124 + a->e134 * b->e2567 
               + a->e2567 * b->e134 + a->e234 * b->e1567 + a->e1567 * b->e234 
               + a->e125 * b->e3467 + a->e3467 * b->e125 + a->e135 * b->e2467 
               + a->e2467 * b->e135 + a->e235 * b->e1467 + a->e1467 * b->e235 
               + a->e145 * b->e2367 + a->e2367 * b->e145 + a->e245 * b->e1367 
               + a->e1367 * b->e245 + a->e345 * b->e1267 + a->e1267 * b->e345 
               + a->e126 * b->e3457 + a->e3457 * b->e126 + a->e136 * b->e2457 
               + a->e2457 * b->e136 + a->e236 * b->e1457 + a->e1457 * b->e236 
               + a->e146 * b->e2357 + a->e2357 * b->e146 + a->e246 * b->e1357 
               + a->e1357 * b->e246 + a->e346 * b->e1257 + a->e1257 * b->e346 
               + a->e156 * b->e2347 + a->e2347 * b->e156 + a->e256 * b->e1347 
               + a->e1347 * b->e256 + a->e356 * b->e1247 + a->e1247 * b->e356 
               + a->e456 * b->e1237 + a->e1237 * b->e456 + a->e127 * b->e3456 
               + a->e3456 * b->e127 + a->e137 * b->e2456 + a->e2456 * b->e137 
               + a->e237 * b->e1456 + a->e1456 * b->e237 + a->e147 * b->e2356 
               + a->e2356 * b->e147 + a->e247 * b->e1356 + a->e1356 * b->e247 
               + a->e347 * b->e1256 + a->e1256 * b->e347 + a->e157 * b->e2346 
               + a->e2346 * b->e157 + a->e257 * b->e1346 + a->e1346 * b->e257 
               + a->e357 * b->e1246 + a->e1246 * b->e357 + a->e457 * b->e1236 
               + a->e1236 * b->e457 + a->e167 * b->e2345 + a->e2345 * b->e167 
               + a->e267 * b->e1345 + a->e1345 * b->e267 + a->e367 * b->e1245 
               + a->e1245 * b->e367 + a->e467 * b->e1235 + a->e1235 * b->e467 
               + a->e567 * b->e1234 + a->e1234 * b->e567;

}

mdnum7_t mdnum7_gem_ro(  coeff_t a,  mdnum7_t* b,  mdnum7_t* c){
  mdnum7_t res;

  //  General multiplication like function 'a * b + c'
  // Real;
  res.r = c->r + a * b->r;
  // Order 1;
  res.e1 = c->e1 + a * b->e1;
  res.e2 = c->e2 + a * b->e2;
  res.e3 = c->e3 + a * b->e3;
  res.e4 = c->e4 + a * b->e4;
  res.e5 = c->e5 + a * b->e5;
  res.e6 = c->e6 + a * b->e6;
  res.e7 = c->e7 + a * b->e7;
  // Order 2;
  res.e12 = c->e12 + a * b->e12;
  res.e13 = c->e13 + a * b->e13;
  res.e23 = c->e23 + a * b->e23;
  res.e14 = c->e14 + a * b->e14;
  res.e24 = c->e24 + a * b->e24;
  res.e34 = c->e34 + a * b->e34;
  res.e15 = c->e15 + a * b->e15;
  res.e25 = c->e25 + a * b->e25;
  res.e35 = c->e35 + a * b->e35;
  res.e45 = c->e45 + a * b->e45;
  res.e16 = c->e16 + a * b->e16;
  res.e26 = c->e26 + a * b->e26;
  res.e36 = c->e36 + a * b->e36;
  res.e46 = c->e46 + a * b->e46;
  res.e56 = c->e56 + a * b->e56;
  res.e17 = c->e17 + a * b->e17;
  res.e27 = c->e27 + a * b->e27;
  res.e37 = c->e37 + a * b->e37;
  res.e47 = c->e47 + a * b->e47;
  res.e57 = c->e57 + a * b->e57;
  res.e67 = c->e67 + a * b->e67;
  // Order 3;
  res.e123 = c->e123 + a * b->e123;
  res.e124 = c->e124 + a * b->e124;
  res.e134 = c->e134 + a * b->e134;
  res.e234 = c->e234 + a * b->e234;
  res.e125 = c->e125 + a * b->e125;
  res.e135 = c->e135 + a * b->e135;
  res.e235 = c->e235 + a * b->e235;
  res.e145 = c->e145 + a * b->e145;
  res.e245 = c->e245 + a * b->e245;
  res.e345 = c->e345 + a * b->e345;
  res.e126 = c->e126 + a * b->e126;
  res.e136 = c->e136 + a * b->e136;
  res.e236 = c->e236 + a * b->e236;
  res.e146 = c->e146 + a * b->e146;
  res.e246 = c->e246 + a * b->e246;
  res.e346 = c->e346 + a * b->e346;
  res.e156 = c->e156 + a * b->e156;
  res.e256 = c->e256 + a * b->e256;
  res.e356 = c->e356 + a * b->e356;
  res.e456 = c->e456 + a * b->e456;
  res.e127 = c->e127 + a * b->e127;
  res.e137 = c->e137 + a * b->e137;
  res.e237 = c->e237 + a * b->e237;
  res.e147 = c->e147 + a * b->e147;
  res.e247 = c->e247 + a * b->e247;
  res.e347 = c->e347 + a * b->e347;
  res.e157 = c->e157 + a * b->e157;
  res.e257 = c->e257 + a * b->e257;
  res.e357 = c->e357 + a * b->e357;
  res.e457 = c->e457 + a * b->e457;
  res.e167 = c->e167 + a * b->e167;
  res.e267 = c->e267 + a * b->e267;
  res.e367 = c->e367 + a * b->e367;
  res.e467 = c->e467 + a * b->e467;
  res.e567 = c->e567 + a * b->e567;
  // Order 4;
  res.e1234 = c->e1234 + a * b->e1234;
  res.e1235 = c->e1235 + a * b->e1235;
  res.e1245 = c->e1245 + a * b->e1245;
  res.e1345 = c->e1345 + a * b->e1345;
  res.e2345 = c->e2345 + a * b->e2345;
  res.e1236 = c->e1236 + a * b->e1236;
  res.e1246 = c->e1246 + a * b->e1246;
  res.e1346 = c->e1346 + a * b->e1346;
  res.e2346 = c->e2346 + a * b->e2346;
  res.e1256 = c->e1256 + a * b->e1256;
  res.e1356 = c->e1356 + a * b->e1356;
  res.e2356 = c->e2356 + a * b->e2356;
  res.e1456 = c->e1456 + a * b->e1456;
  res.e2456 = c->e2456 + a * b->e2456;
  res.e3456 = c->e3456 + a * b->e3456;
  res.e1237 = c->e1237 + a * b->e1237;
  res.e1247 = c->e1247 + a * b->e1247;
  res.e1347 = c->e1347 + a * b->e1347;
  res.e2347 = c->e2347 + a * b->e2347;
  res.e1257 = c->e1257 + a * b->e1257;
  res.e1357 = c->e1357 + a * b->e1357;
  res.e2357 = c->e2357 + a * b->e2357;
  res.e1457 = c->e1457 + a * b->e1457;
  res.e2457 = c->e2457 + a * b->e2457;
  res.e3457 = c->e3457 + a * b->e3457;
  res.e1267 = c->e1267 + a * b->e1267;
  res.e1367 = c->e1367 + a * b->e1367;
  res.e2367 = c->e2367 + a * b->e2367;
  res.e1467 = c->e1467 + a * b->e1467;
  res.e2467 = c->e2467 + a * b->e2467;
  res.e3467 = c->e3467 + a * b->e3467;
  res.e1567 = c->e1567 + a * b->e1567;
  res.e2567 = c->e2567 + a * b->e2567;
  res.e3567 = c->e3567 + a * b->e3567;
  res.e4567 = c->e4567 + a * b->e4567;
  // Order 5;
  res.e12345 = c->e12345 + a * b->e12345;
  res.e12346 = c->e12346 + a * b->e12346;
  res.e12356 = c->e12356 + a * b->e12356;
  res.e12456 = c->e12456 + a * b->e12456;
  res.e13456 = c->e13456 + a * b->e13456;
  res.e23456 = c->e23456 + a * b->e23456;
  res.e12347 = c->e12347 + a * b->e12347;
  res.e12357 = c->e12357 + a * b->e12357;
  res.e12457 = c->e12457 + a * b->e12457;
  res.e13457 = c->e13457 + a * b->e13457;
  res.e23457 = c->e23457 + a * b->e23457;
  res.e12367 = c->e12367 + a * b->e12367;
  res.e12467 = c->e12467 + a * b->e12467;
  res.e13467 = c->e13467 + a * b->e13467;
  res.e23467 = c->e23467 + a * b->e23467;
  res.e12567 = c->e12567 + a * b->e12567;
  res.e13567 = c->e13567 + a * b->e13567;
  res.e23567 = c->e23567 + a * b->e23567;
  res.e14567 = c->e14567 + a * b->e14567;
  res.e24567 = c->e24567 + a * b->e24567;
  res.e34567 = c->e34567 + a * b->e34567;
  // Order 6;
  res.e123456 = c->e123456 + a * b->e123456;
  res.e123457 = c->e123457 + a * b->e123457;
  res.e123467 = c->e123467 + a * b->e123467;
  res.e123567 = c->e123567 + a * b->e123567;
  res.e124567 = c->e124567 + a * b->e124567;
  res.e134567 = c->e134567 + a * b->e134567;
  res.e234567 = c->e234567 + a * b->e234567;
  // Order 7;
  res.e1234567 = c->e1234567 + a * b->e1234567;

  return res;

}

void mdnum7_gem_ro_to(  coeff_t a,  mdnum7_t* b,  mdnum7_t* c, mdnum7_t* res){
  //  General multiplication like function 'a * b + c'
  // Real;
  res->r = c->r + a * b->r;
  // Order 1;
  res->e1 = c->e1 + a * b->e1;
  res->e2 = c->e2 + a * b->e2;
  res->e3 = c->e3 + a * b->e3;
  res->e4 = c->e4 + a * b->e4;
  res->e5 = c->e5 + a * b->e5;
  res->e6 = c->e6 + a * b->e6;
  res->e7 = c->e7 + a * b->e7;
  // Order 2;
  res->e12 = c->e12 + a * b->e12;
  res->e13 = c->e13 + a * b->e13;
  res->e23 = c->e23 + a * b->e23;
  res->e14 = c->e14 + a * b->e14;
  res->e24 = c->e24 + a * b->e24;
  res->e34 = c->e34 + a * b->e34;
  res->e15 = c->e15 + a * b->e15;
  res->e25 = c->e25 + a * b->e25;
  res->e35 = c->e35 + a * b->e35;
  res->e45 = c->e45 + a * b->e45;
  res->e16 = c->e16 + a * b->e16;
  res->e26 = c->e26 + a * b->e26;
  res->e36 = c->e36 + a * b->e36;
  res->e46 = c->e46 + a * b->e46;
  res->e56 = c->e56 + a * b->e56;
  res->e17 = c->e17 + a * b->e17;
  res->e27 = c->e27 + a * b->e27;
  res->e37 = c->e37 + a * b->e37;
  res->e47 = c->e47 + a * b->e47;
  res->e57 = c->e57 + a * b->e57;
  res->e67 = c->e67 + a * b->e67;
  // Order 3;
  res->e123 = c->e123 + a * b->e123;
  res->e124 = c->e124 + a * b->e124;
  res->e134 = c->e134 + a * b->e134;
  res->e234 = c->e234 + a * b->e234;
  res->e125 = c->e125 + a * b->e125;
  res->e135 = c->e135 + a * b->e135;
  res->e235 = c->e235 + a * b->e235;
  res->e145 = c->e145 + a * b->e145;
  res->e245 = c->e245 + a * b->e245;
  res->e345 = c->e345 + a * b->e345;
  res->e126 = c->e126 + a * b->e126;
  res->e136 = c->e136 + a * b->e136;
  res->e236 = c->e236 + a * b->e236;
  res->e146 = c->e146 + a * b->e146;
  res->e246 = c->e246 + a * b->e246;
  res->e346 = c->e346 + a * b->e346;
  res->e156 = c->e156 + a * b->e156;
  res->e256 = c->e256 + a * b->e256;
  res->e356 = c->e356 + a * b->e356;
  res->e456 = c->e456 + a * b->e456;
  res->e127 = c->e127 + a * b->e127;
  res->e137 = c->e137 + a * b->e137;
  res->e237 = c->e237 + a * b->e237;
  res->e147 = c->e147 + a * b->e147;
  res->e247 = c->e247 + a * b->e247;
  res->e347 = c->e347 + a * b->e347;
  res->e157 = c->e157 + a * b->e157;
  res->e257 = c->e257 + a * b->e257;
  res->e357 = c->e357 + a * b->e357;
  res->e457 = c->e457 + a * b->e457;
  res->e167 = c->e167 + a * b->e167;
  res->e267 = c->e267 + a * b->e267;
  res->e367 = c->e367 + a * b->e367;
  res->e467 = c->e467 + a * b->e467;
  res->e567 = c->e567 + a * b->e567;
  // Order 4;
  res->e1234 = c->e1234 + a * b->e1234;
  res->e1235 = c->e1235 + a * b->e1235;
  res->e1245 = c->e1245 + a * b->e1245;
  res->e1345 = c->e1345 + a * b->e1345;
  res->e2345 = c->e2345 + a * b->e2345;
  res->e1236 = c->e1236 + a * b->e1236;
  res->e1246 = c->e1246 + a * b->e1246;
  res->e1346 = c->e1346 + a * b->e1346;
  res->e2346 = c->e2346 + a * b->e2346;
  res->e1256 = c->e1256 + a * b->e1256;
  res->e1356 = c->e1356 + a * b->e1356;
  res->e2356 = c->e2356 + a * b->e2356;
  res->e1456 = c->e1456 + a * b->e1456;
  res->e2456 = c->e2456 + a * b->e2456;
  res->e3456 = c->e3456 + a * b->e3456;
  res->e1237 = c->e1237 + a * b->e1237;
  res->e1247 = c->e1247 + a * b->e1247;
  res->e1347 = c->e1347 + a * b->e1347;
  res->e2347 = c->e2347 + a * b->e2347;
  res->e1257 = c->e1257 + a * b->e1257;
  res->e1357 = c->e1357 + a * b->e1357;
  res->e2357 = c->e2357 + a * b->e2357;
  res->e1457 = c->e1457 + a * b->e1457;
  res->e2457 = c->e2457 + a * b->e2457;
  res->e3457 = c->e3457 + a * b->e3457;
  res->e1267 = c->e1267 + a * b->e1267;
  res->e1367 = c->e1367 + a * b->e1367;
  res->e2367 = c->e2367 + a * b->e2367;
  res->e1467 = c->e1467 + a * b->e1467;
  res->e2467 = c->e2467 + a * b->e2467;
  res->e3467 = c->e3467 + a * b->e3467;
  res->e1567 = c->e1567 + a * b->e1567;
  res->e2567 = c->e2567 + a * b->e2567;
  res->e3567 = c->e3567 + a * b->e3567;
  res->e4567 = c->e4567 + a * b->e4567;
  // Order 5;
  res->e12345 = c->e12345 + a * b->e12345;
  res->e12346 = c->e12346 + a * b->e12346;
  res->e12356 = c->e12356 + a * b->e12356;
  res->e12456 = c->e12456 + a * b->e12456;
  res->e13456 = c->e13456 + a * b->e13456;
  res->e23456 = c->e23456 + a * b->e23456;
  res->e12347 = c->e12347 + a * b->e12347;
  res->e12357 = c->e12357 + a * b->e12357;
  res->e12457 = c->e12457 + a * b->e12457;
  res->e13457 = c->e13457 + a * b->e13457;
  res->e23457 = c->e23457 + a * b->e23457;
  res->e12367 = c->e12367 + a * b->e12367;
  res->e12467 = c->e12467 + a * b->e12467;
  res->e13467 = c->e13467 + a * b->e13467;
  res->e23467 = c->e23467 + a * b->e23467;
  res->e12567 = c->e12567 + a * b->e12567;
  res->e13567 = c->e13567 + a * b->e13567;
  res->e23567 = c->e23567 + a * b->e23567;
  res->e14567 = c->e14567 + a * b->e14567;
  res->e24567 = c->e24567 + a * b->e24567;
  res->e34567 = c->e34567 + a * b->e34567;
  // Order 6;
  res->e123456 = c->e123456 + a * b->e123456;
  res->e123457 = c->e123457 + a * b->e123457;
  res->e123467 = c->e123467 + a * b->e123467;
  res->e123567 = c->e123567 + a * b->e123567;
  res->e124567 = c->e124567 + a * b->e124567;
  res->e134567 = c->e134567 + a * b->e134567;
  res->e234567 = c->e234567 + a * b->e234567;
  // Order 7;
  res->e1234567 = c->e1234567 + a * b->e1234567;

}

void mdnum7_trunc_gem_oo_to( ord_t ord_lhs,  mdnum7_t* a,  ord_t ord_rhs,  mdnum7_t* b,  mdnum7_t* c, mdnum7_t* res){
  //  General multiplication like function 'a * b + c'
  switch( ord_lhs ){
    case 0:
      switch( ord_rhs ){
        case 0:
          // res order: 0
          res->r = c->r + a->r * b->r;
          break;
        case 1:
          // res order: 1
          res->e1 = c->e1 + a->r * b->e1;
          res->e2 = c->e2 + a->r * b->e2;
          res->e3 = c->e3 + a->r * b->e3;
          res->e4 = c->e4 + a->r * b->e4;
          res->e5 = c->e5 + a->r * b->e5;
          res->e6 = c->e6 + a->r * b->e6;
          res->e7 = c->e7 + a->r * b->e7;
          break;
        case 2:
          // res order: 2
          res->e12 = c->e12 + a->r * b->e12;
          res->e13 = c->e13 + a->r * b->e13;
          res->e23 = c->e23 + a->r * b->e23;
          res->e14 = c->e14 + a->r * b->e14;
          res->e24 = c->e24 + a->r * b->e24;
          res->e34 = c->e34 + a->r * b->e34;
          res->e15 = c->e15 + a->r * b->e15;
          res->e25 = c->e25 + a->r * b->e25;
          res->e35 = c->e35 + a->r * b->e35;
          res->e45 = c->e45 + a->r * b->e45;
          res->e16 = c->e16 + a->r * b->e16;
          res->e26 = c->e26 + a->r * b->e26;
          res->e36 = c->e36 + a->r * b->e36;
          res->e46 = c->e46 + a->r * b->e46;
          res->e56 = c->e56 + a->r * b->e56;
          res->e17 = c->e17 + a->r * b->e17;
          res->e27 = c->e27 + a->r * b->e27;
          res->e37 = c->e37 + a->r * b->e37;
          res->e47 = c->e47 + a->r * b->e47;
          res->e57 = c->e57 + a->r * b->e57;
          res->e67 = c->e67 + a->r * b->e67;
          break;
        case 3:
          // res order: 3
          res->e123 = c->e123 + a->r * b->e123;
          res->e124 = c->e124 + a->r * b->e124;
          res->e134 = c->e134 + a->r * b->e134;
          res->e234 = c->e234 + a->r * b->e234;
          res->e125 = c->e125 + a->r * b->e125;
          res->e135 = c->e135 + a->r * b->e135;
          res->e235 = c->e235 + a->r * b->e235;
          res->e145 = c->e145 + a->r * b->e145;
          res->e245 = c->e245 + a->r * b->e245;
          res->e345 = c->e345 + a->r * b->e345;
          res->e126 = c->e126 + a->r * b->e126;
          res->e136 = c->e136 + a->r * b->e136;
          res->e236 = c->e236 + a->r * b->e236;
          res->e146 = c->e146 + a->r * b->e146;
          res->e246 = c->e246 + a->r * b->e246;
          res->e346 = c->e346 + a->r * b->e346;
          res->e156 = c->e156 + a->r * b->e156;
          res->e256 = c->e256 + a->r * b->e256;
          res->e356 = c->e356 + a->r * b->e356;
          res->e456 = c->e456 + a->r * b->e456;
          res->e127 = c->e127 + a->r * b->e127;
          res->e137 = c->e137 + a->r * b->e137;
          res->e237 = c->e237 + a->r * b->e237;
          res->e147 = c->e147 + a->r * b->e147;
          res->e247 = c->e247 + a->r * b->e247;
          res->e347 = c->e347 + a->r * b->e347;
          res->e157 = c->e157 + a->r * b->e157;
          res->e257 = c->e257 + a->r * b->e257;
          res->e357 = c->e357 + a->r * b->e357;
          res->e457 = c->e457 + a->r * b->e457;
          res->e167 = c->e167 + a->r * b->e167;
          res->e267 = c->e267 + a->r * b->e267;
          res->e367 = c->e367 + a->r * b->e367;
          res->e467 = c->e467 + a->r * b->e467;
          res->e567 = c->e567 + a->r * b->e567;
          break;
        case 4:
          // res order: 4
          res->e1234 = c->e1234 + a->r * b->e1234;
          res->e1235 = c->e1235 + a->r * b->e1235;
          res->e1245 = c->e1245 + a->r * b->e1245;
          res->e1345 = c->e1345 + a->r * b->e1345;
          res->e2345 = c->e2345 + a->r * b->e2345;
          res->e1236 = c->e1236 + a->r * b->e1236;
          res->e1246 = c->e1246 + a->r * b->e1246;
          res->e1346 = c->e1346 + a->r * b->e1346;
          res->e2346 = c->e2346 + a->r * b->e2346;
          res->e1256 = c->e1256 + a->r * b->e1256;
          res->e1356 = c->e1356 + a->r * b->e1356;
          res->e2356 = c->e2356 + a->r * b->e2356;
          res->e1456 = c->e1456 + a->r * b->e1456;
          res->e2456 = c->e2456 + a->r * b->e2456;
          res->e3456 = c->e3456 + a->r * b->e3456;
          res->e1237 = c->e1237 + a->r * b->e1237;
          res->e1247 = c->e1247 + a->r * b->e1247;
          res->e1347 = c->e1347 + a->r * b->e1347;
          res->e2347 = c->e2347 + a->r * b->e2347;
          res->e1257 = c->e1257 + a->r * b->e1257;
          res->e1357 = c->e1357 + a->r * b->e1357;
          res->e2357 = c->e2357 + a->r * b->e2357;
          res->e1457 = c->e1457 + a->r * b->e1457;
          res->e2457 = c->e2457 + a->r * b->e2457;
          res->e3457 = c->e3457 + a->r * b->e3457;
          res->e1267 = c->e1267 + a->r * b->e1267;
          res->e1367 = c->e1367 + a->r * b->e1367;
          res->e2367 = c->e2367 + a->r * b->e2367;
          res->e1467 = c->e1467 + a->r * b->e1467;
          res->e2467 = c->e2467 + a->r * b->e2467;
          res->e3467 = c->e3467 + a->r * b->e3467;
          res->e1567 = c->e1567 + a->r * b->e1567;
          res->e2567 = c->e2567 + a->r * b->e2567;
          res->e3567 = c->e3567 + a->r * b->e3567;
          res->e4567 = c->e4567 + a->r * b->e4567;
          break;
        case 5:
          // res order: 5
          res->e12345 = c->e12345 + a->r * b->e12345;
          res->e12346 = c->e12346 + a->r * b->e12346;
          res->e12356 = c->e12356 + a->r * b->e12356;
          res->e12456 = c->e12456 + a->r * b->e12456;
          res->e13456 = c->e13456 + a->r * b->e13456;
          res->e23456 = c->e23456 + a->r * b->e23456;
          res->e12347 = c->e12347 + a->r * b->e12347;
          res->e12357 = c->e12357 + a->r * b->e12357;
          res->e12457 = c->e12457 + a->r * b->e12457;
          res->e13457 = c->e13457 + a->r * b->e13457;
          res->e23457 = c->e23457 + a->r * b->e23457;
          res->e12367 = c->e12367 + a->r * b->e12367;
          res->e12467 = c->e12467 + a->r * b->e12467;
          res->e13467 = c->e13467 + a->r * b->e13467;
          res->e23467 = c->e23467 + a->r * b->e23467;
          res->e12567 = c->e12567 + a->r * b->e12567;
          res->e13567 = c->e13567 + a->r * b->e13567;
          res->e23567 = c->e23567 + a->r * b->e23567;
          res->e14567 = c->e14567 + a->r * b->e14567;
          res->e24567 = c->e24567 + a->r * b->e24567;
          res->e34567 = c->e34567 + a->r * b->e34567;
          break;
        case 6:
          // res order: 6
          res->e123456 = c->e123456 + a->r * b->e123456;
          res->e123457 = c->e123457 + a->r * b->e123457;
          res->e123467 = c->e123467 + a->r * b->e123467;
          res->e123567 = c->e123567 + a->r * b->e123567;
          res->e124567 = c->e124567 + a->r * b->e124567;
          res->e134567 = c->e134567 + a->r * b->e134567;
          res->e234567 = c->e234567 + a->r * b->e234567;
          break;
        case 7:
          // res order: 7
          res->e1234567 = c->e1234567 + a->r * b->e1234567;
          break;
      }
      break;
    case 1:
      switch( ord_rhs ){
        case 0:
          // res order: 1
          res->e1 = c->e1 + a->e1 * b->r;
          res->e2 = c->e2 + a->e2 * b->r;
          res->e3 = c->e3 + a->e3 * b->r;
          res->e4 = c->e4 + a->e4 * b->r;
          res->e5 = c->e5 + a->e5 * b->r;
          res->e6 = c->e6 + a->e6 * b->r;
          res->e7 = c->e7 + a->e7 * b->r;
          break;
        case 1:
          // res order: 2
          res->e12 = c->e12 + a->e1 * b->e2 + a->e2 * b->e1;
          res->e13 = c->e13 + a->e1 * b->e3 + a->e3 * b->e1;
          res->e23 = c->e23 + a->e2 * b->e3 + a->e3 * b->e2;
          res->e14 = c->e14 + a->e1 * b->e4 + a->e4 * b->e1;
          res->e24 = c->e24 + a->e2 * b->e4 + a->e4 * b->e2;
          res->e34 = c->e34 + a->e3 * b->e4 + a->e4 * b->e3;
          res->e15 = c->e15 + a->e1 * b->e5 + a->e5 * b->e1;
          res->e25 = c->e25 + a->e2 * b->e5 + a->e5 * b->e2;
          res->e35 = c->e35 + a->e3 * b->e5 + a->e5 * b->e3;
          res->e45 = c->e45 + a->e4 * b->e5 + a->e5 * b->e4;
          res->e16 = c->e16 + a->e1 * b->e6 + a->e6 * b->e1;
          res->e26 = c->e26 + a->e2 * b->e6 + a->e6 * b->e2;
          res->e36 = c->e36 + a->e3 * b->e6 + a->e6 * b->e3;
          res->e46 = c->e46 + a->e4 * b->e6 + a->e6 * b->e4;
          res->e56 = c->e56 + a->e5 * b->e6 + a->e6 * b->e5;
          res->e17 = c->e17 + a->e1 * b->e7 + a->e7 * b->e1;
          res->e27 = c->e27 + a->e2 * b->e7 + a->e7 * b->e2;
          res->e37 = c->e37 + a->e3 * b->e7 + a->e7 * b->e3;
          res->e47 = c->e47 + a->e4 * b->e7 + a->e7 * b->e4;
          res->e57 = c->e57 + a->e5 * b->e7 + a->e7 * b->e5;
          res->e67 = c->e67 + a->e6 * b->e7 + a->e7 * b->e6;
          break;
        case 2:
          // res order: 3
          res->e123 = c->e123 + a->e1 * b->e23 + a->e2 * b->e13 
                    + a->e3 * b->e12;
          res->e124 = c->e124 + a->e1 * b->e24 + a->e2 * b->e14 
                    + a->e4 * b->e12;
          res->e134 = c->e134 + a->e1 * b->e34 + a->e3 * b->e14 
                    + a->e4 * b->e13;
          res->e234 = c->e234 + a->e2 * b->e34 + a->e3 * b->e24 
                    + a->e4 * b->e23;
          res->e125 = c->e125 + a->e1 * b->e25 + a->e2 * b->e15 
                    + a->e5 * b->e12;
          res->e135 = c->e135 + a->e1 * b->e35 + a->e3 * b->e15 
                    + a->e5 * b->e13;
          res->e235 = c->e235 + a->e2 * b->e35 + a->e3 * b->e25 
                    + a->e5 * b->e23;
          res->e145 = c->e145 + a->e1 * b->e45 + a->e4 * b->e15 
                    + a->e5 * b->e14;
          res->e245 = c->e245 + a->e2 * b->e45 + a->e4 * b->e25 
                    + a->e5 * b->e24;
          res->e345 = c->e345 + a->e3 * b->e45 + a->e4 * b->e35 
                    + a->e5 * b->e34;
          res->e126 = c->e126 + a->e1 * b->e26 + a->e2 * b->e16 
                    + a->e6 * b->e12;
          res->e136 = c->e136 + a->e1 * b->e36 + a->e3 * b->e16 
                    + a->e6 * b->e13;
          res->e236 = c->e236 + a->e2 * b->e36 + a->e3 * b->e26 
                    + a->e6 * b->e23;
          res->e146 = c->e146 + a->e1 * b->e46 + a->e4 * b->e16 
                    + a->e6 * b->e14;
          res->e246 = c->e246 + a->e2 * b->e46 + a->e4 * b->e26 
                    + a->e6 * b->e24;
          res->e346 = c->e346 + a->e3 * b->e46 + a->e4 * b->e36 
                    + a->e6 * b->e34;
          res->e156 = c->e156 + a->e1 * b->e56 + a->e5 * b->e16 
                    + a->e6 * b->e15;
          res->e256 = c->e256 + a->e2 * b->e56 + a->e5 * b->e26 
                    + a->e6 * b->e25;
          res->e356 = c->e356 + a->e3 * b->e56 + a->e5 * b->e36 
                    + a->e6 * b->e35;
          res->e456 = c->e456 + a->e4 * b->e56 + a->e5 * b->e46 
                    + a->e6 * b->e45;
          res->e127 = c->e127 + a->e1 * b->e27 + a->e2 * b->e17 
                    + a->e7 * b->e12;
          res->e137 = c->e137 + a->e1 * b->e37 + a->e3 * b->e17 
                    + a->e7 * b->e13;
          res->e237 = c->e237 + a->e2 * b->e37 + a->e3 * b->e27 
                    + a->e7 * b->e23;
          res->e147 = c->e147 + a->e1 * b->e47 + a->e4 * b->e17 
                    + a->e7 * b->e14;
          res->e247 = c->e247 + a->e2 * b->e47 + a->e4 * b->e27 
                    + a->e7 * b->e24;
          res->e347 = c->e347 + a->e3 * b->e47 + a->e4 * b->e37 
                    + a->e7 * b->e34;
          res->e157 = c->e157 + a->e1 * b->e57 + a->e5 * b->e17 
                    + a->e7 * b->e15;
          res->e257 = c->e257 + a->e2 * b->e57 + a->e5 * b->e27 
                    + a->e7 * b->e25;
          res->e357 = c->e357 + a->e3 * b->e57 + a->e5 * b->e37 
                    + a->e7 * b->e35;
          res->e457 = c->e457 + a->e4 * b->e57 + a->e5 * b->e47 
                    + a->e7 * b->e45;
          res->e167 = c->e167 + a->e1 * b->e67 + a->e6 * b->e17 
                    + a->e7 * b->e16;
          res->e267 = c->e267 + a->e2 * b->e67 + a->e6 * b->e27 
                    + a->e7 * b->e26;
          res->e367 = c->e367 + a->e3 * b->e67 + a->e6 * b->e37 
                    + a->e7 * b->e36;
          res->e467 = c->e467 + a->e4 * b->e67 + a->e6 * b->e47 
                    + a->e7 * b->e46;
          res->e567 = c->e567 + a->e5 * b->e67 + a->e6 * b->e57 
                    + a->e7 * b->e56;
          break;
        case 3:
          // res order: 4
          res->e1234 = c->e1234 + a->e1 * b->e234 + a->e2 * b->e134 
                     + a->e3 * b->e124 + a->e4 * b->e123;
          res->e1235 = c->e1235 + a->e1 * b->e235 + a->e2 * b->e135 
                     + a->e3 * b->e125 + a->e5 * b->e123;
          res->e1245 = c->e1245 + a->e1 * b->e245 + a->e2 * b->e145 
                     + a->e4 * b->e125 + a->e5 * b->e124;
          res->e1345 = c->e1345 + a->e1 * b->e345 + a->e3 * b->e145 
                     + a->e4 * b->e135 + a->e5 * b->e134;
          res->e2345 = c->e2345 + a->e2 * b->e345 + a->e3 * b->e245 
                     + a->e4 * b->e235 + a->e5 * b->e234;
          res->e1236 = c->e1236 + a->e1 * b->e236 + a->e2 * b->e136 
                     + a->e3 * b->e126 + a->e6 * b->e123;
          res->e1246 = c->e1246 + a->e1 * b->e246 + a->e2 * b->e146 
                     + a->e4 * b->e126 + a->e6 * b->e124;
          res->e1346 = c->e1346 + a->e1 * b->e346 + a->e3 * b->e146 
                     + a->e4 * b->e136 + a->e6 * b->e134;
          res->e2346 = c->e2346 + a->e2 * b->e346 + a->e3 * b->e246 
                     + a->e4 * b->e236 + a->e6 * b->e234;
          res->e1256 = c->e1256 + a->e1 * b->e256 + a->e2 * b->e156 
                     + a->e5 * b->e126 + a->e6 * b->e125;
          res->e1356 = c->e1356 + a->e1 * b->e356 + a->e3 * b->e156 
                     + a->e5 * b->e136 + a->e6 * b->e135;
          res->e2356 = c->e2356 + a->e2 * b->e356 + a->e3 * b->e256 
                     + a->e5 * b->e236 + a->e6 * b->e235;
          res->e1456 = c->e1456 + a->e1 * b->e456 + a->e4 * b->e156 
                     + a->e5 * b->e146 + a->e6 * b->e145;
          res->e2456 = c->e2456 + a->e2 * b->e456 + a->e4 * b->e256 
                     + a->e5 * b->e246 + a->e6 * b->e245;
          res->e3456 = c->e3456 + a->e3 * b->e456 + a->e4 * b->e356 
                     + a->e5 * b->e346 + a->e6 * b->e345;
          res->e1237 = c->e1237 + a->e1 * b->e237 + a->e2 * b->e137 
                     + a->e3 * b->e127 + a->e7 * b->e123;
          res->e1247 = c->e1247 + a->e1 * b->e247 + a->e2 * b->e147 
                     + a->e4 * b->e127 + a->e7 * b->e124;
          res->e1347 = c->e1347 + a->e1 * b->e347 + a->e3 * b->e147 
                     + a->e4 * b->e137 + a->e7 * b->e134;
          res->e2347 = c->e2347 + a->e2 * b->e347 + a->e3 * b->e247 
                     + a->e4 * b->e237 + a->e7 * b->e234;
          res->e1257 = c->e1257 + a->e1 * b->e257 + a->e2 * b->e157 
                     + a->e5 * b->e127 + a->e7 * b->e125;
          res->e1357 = c->e1357 + a->e1 * b->e357 + a->e3 * b->e157 
                     + a->e5 * b->e137 + a->e7 * b->e135;
          res->e2357 = c->e2357 + a->e2 * b->e357 + a->e3 * b->e257 
                     + a->e5 * b->e237 + a->e7 * b->e235;
          res->e1457 = c->e1457 + a->e1 * b->e457 + a->e4 * b->e157 
                     + a->e5 * b->e147 + a->e7 * b->e145;
          res->e2457 = c->e2457 + a->e2 * b->e457 + a->e4 * b->e257 
                     + a->e5 * b->e247 + a->e7 * b->e245;
          res->e3457 = c->e3457 + a->e3 * b->e457 + a->e4 * b->e357 
                     + a->e5 * b->e347 + a->e7 * b->e345;
          res->e1267 = c->e1267 + a->e1 * b->e267 + a->e2 * b->e167 
                     + a->e6 * b->e127 + a->e7 * b->e126;
          res->e1367 = c->e1367 + a->e1 * b->e367 + a->e3 * b->e167 
                     + a->e6 * b->e137 + a->e7 * b->e136;
          res->e2367 = c->e2367 + a->e2 * b->e367 + a->e3 * b->e267 
                     + a->e6 * b->e237 + a->e7 * b->e236;
          res->e1467 = c->e1467 + a->e1 * b->e467 + a->e4 * b->e167 
                     + a->e6 * b->e147 + a->e7 * b->e146;
          res->e2467 = c->e2467 + a->e2 * b->e467 + a->e4 * b->e267 
                     + a->e6 * b->e247 + a->e7 * b->e246;
          res->e3467 = c->e3467 + a->e3 * b->e467 + a->e4 * b->e367 
                     + a->e6 * b->e347 + a->e7 * b->e346;
          res->e1567 = c->e1567 + a->e1 * b->e567 + a->e5 * b->e167 
                     + a->e6 * b->e157 + a->e7 * b->e156;
          res->e2567 = c->e2567 + a->e2 * b->e567 + a->e5 * b->e267 
                     + a->e6 * b->e257 + a->e7 * b->e256;
          res->e3567 = c->e3567 + a->e3 * b->e567 + a->e5 * b->e367 
                     + a->e6 * b->e357 + a->e7 * b->e356;
          res->e4567 = c->e4567 + a->e4 * b->e567 + a->e5 * b->e467 
                     + a->e6 * b->e457 + a->e7 * b->e456;
          break;
        case 4:
          // res order: 5
          res->e12345 = c->e12345 + a->e1 * b->e2345 + a->e2 * b->e1345 
                      + a->e3 * b->e1245 + a->e4 * b->e1235 + a->e5 * b->e1234;
          res->e12346 = c->e12346 + a->e1 * b->e2346 + a->e2 * b->e1346 
                      + a->e3 * b->e1246 + a->e4 * b->e1236 + a->e6 * b->e1234;
          res->e12356 = c->e12356 + a->e1 * b->e2356 + a->e2 * b->e1356 
                      + a->e3 * b->e1256 + a->e5 * b->e1236 + a->e6 * b->e1235;
          res->e12456 = c->e12456 + a->e1 * b->e2456 + a->e2 * b->e1456 
                      + a->e4 * b->e1256 + a->e5 * b->e1246 + a->e6 * b->e1245;
          res->e13456 = c->e13456 + a->e1 * b->e3456 + a->e3 * b->e1456 
                      + a->e4 * b->e1356 + a->e5 * b->e1346 + a->e6 * b->e1345;
          res->e23456 = c->e23456 + a->e2 * b->e3456 + a->e3 * b->e2456 
                      + a->e4 * b->e2356 + a->e5 * b->e2346 + a->e6 * b->e2345;
          res->e12347 = c->e12347 + a->e1 * b->e2347 + a->e2 * b->e1347 
                      + a->e3 * b->e1247 + a->e4 * b->e1237 + a->e7 * b->e1234;
          res->e12357 = c->e12357 + a->e1 * b->e2357 + a->e2 * b->e1357 
                      + a->e3 * b->e1257 + a->e5 * b->e1237 + a->e7 * b->e1235;
          res->e12457 = c->e12457 + a->e1 * b->e2457 + a->e2 * b->e1457 
                      + a->e4 * b->e1257 + a->e5 * b->e1247 + a->e7 * b->e1245;
          res->e13457 = c->e13457 + a->e1 * b->e3457 + a->e3 * b->e1457 
                      + a->e4 * b->e1357 + a->e5 * b->e1347 + a->e7 * b->e1345;
          res->e23457 = c->e23457 + a->e2 * b->e3457 + a->e3 * b->e2457 
                      + a->e4 * b->e2357 + a->e5 * b->e2347 + a->e7 * b->e2345;
          res->e12367 = c->e12367 + a->e1 * b->e2367 + a->e2 * b->e1367 
                      + a->e3 * b->e1267 + a->e6 * b->e1237 + a->e7 * b->e1236;
          res->e12467 = c->e12467 + a->e1 * b->e2467 + a->e2 * b->e1467 
                      + a->e4 * b->e1267 + a->e6 * b->e1247 + a->e7 * b->e1246;
          res->e13467 = c->e13467 + a->e1 * b->e3467 + a->e3 * b->e1467 
                      + a->e4 * b->e1367 + a->e6 * b->e1347 + a->e7 * b->e1346;
          res->e23467 = c->e23467 + a->e2 * b->e3467 + a->e3 * b->e2467 
                      + a->e4 * b->e2367 + a->e6 * b->e2347 + a->e7 * b->e2346;
          res->e12567 = c->e12567 + a->e1 * b->e2567 + a->e2 * b->e1567 
                      + a->e5 * b->e1267 + a->e6 * b->e1257 + a->e7 * b->e1256;
          res->e13567 = c->e13567 + a->e1 * b->e3567 + a->e3 * b->e1567 
                      + a->e5 * b->e1367 + a->e6 * b->e1357 + a->e7 * b->e1356;
          res->e23567 = c->e23567 + a->e2 * b->e3567 + a->e3 * b->e2567 
                      + a->e5 * b->e2367 + a->e6 * b->e2357 + a->e7 * b->e2356;
          res->e14567 = c->e14567 + a->e1 * b->e4567 + a->e4 * b->e1567 
                      + a->e5 * b->e1467 + a->e6 * b->e1457 + a->e7 * b->e1456;
          res->e24567 = c->e24567 + a->e2 * b->e4567 + a->e4 * b->e2567 
                      + a->e5 * b->e2467 + a->e6 * b->e2457 + a->e7 * b->e2456;
          res->e34567 = c->e34567 + a->e3 * b->e4567 + a->e4 * b->e3567 
                      + a->e5 * b->e3467 + a->e6 * b->e3457 + a->e7 * b->e3456;
          break;
        case 5:
          // res order: 6
          res->e123456 = c->e123456 + a->e1 * b->e23456 + a->e2 * b->e13456 
                       + a->e3 * b->e12456 + a->e4 * b->e12356 + a->e5 * b->e12346 
                       + a->e6 * b->e12345;
          res->e123457 = c->e123457 + a->e1 * b->e23457 + a->e2 * b->e13457 
                       + a->e3 * b->e12457 + a->e4 * b->e12357 + a->e5 * b->e12347 
                       + a->e7 * b->e12345;
          res->e123467 = c->e123467 + a->e1 * b->e23467 + a->e2 * b->e13467 
                       + a->e3 * b->e12467 + a->e4 * b->e12367 + a->e6 * b->e12347 
                       + a->e7 * b->e12346;
          res->e123567 = c->e123567 + a->e1 * b->e23567 + a->e2 * b->e13567 
                       + a->e3 * b->e12567 + a->e5 * b->e12367 + a->e6 * b->e12357 
                       + a->e7 * b->e12356;
          res->e124567 = c->e124567 + a->e1 * b->e24567 + a->e2 * b->e14567 
                       + a->e4 * b->e12567 + a->e5 * b->e12467 + a->e6 * b->e12457 
                       + a->e7 * b->e12456;
          res->e134567 = c->e134567 + a->e1 * b->e34567 + a->e3 * b->e14567 
                       + a->e4 * b->e13567 + a->e5 * b->e13467 + a->e6 * b->e13457 
                       + a->e7 * b->e13456;
          res->e234567 = c->e234567 + a->e2 * b->e34567 + a->e3 * b->e24567 
                       + a->e4 * b->e23567 + a->e5 * b->e23467 + a->e6 * b->e23457 
                       + a->e7 * b->e23456;
          break;
        case 6:
          // res order: 7
          res->e1234567 = c->e1234567 + a->e1 * b->e234567 + a->e2 * b->e134567 
                        + a->e3 * b->e124567 + a->e4 * b->e123567 + a->e5 * b->e123467 
                        + a->e6 * b->e123457 + a->e7 * b->e123456;
          break;
      }
      break;
    case 2:
      switch( ord_rhs ){
        case 0:
          // res order: 2
          res->e12 = c->e12 + a->e12 * b->r;
          res->e13 = c->e13 + a->e13 * b->r;
          res->e23 = c->e23 + a->e23 * b->r;
          res->e14 = c->e14 + a->e14 * b->r;
          res->e24 = c->e24 + a->e24 * b->r;
          res->e34 = c->e34 + a->e34 * b->r;
          res->e15 = c->e15 + a->e15 * b->r;
          res->e25 = c->e25 + a->e25 * b->r;
          res->e35 = c->e35 + a->e35 * b->r;
          res->e45 = c->e45 + a->e45 * b->r;
          res->e16 = c->e16 + a->e16 * b->r;
          res->e26 = c->e26 + a->e26 * b->r;
          res->e36 = c->e36 + a->e36 * b->r;
          res->e46 = c->e46 + a->e46 * b->r;
          res->e56 = c->e56 + a->e56 * b->r;
          res->e17 = c->e17 + a->e17 * b->r;
          res->e27 = c->e27 + a->e27 * b->r;
          res->e37 = c->e37 + a->e37 * b->r;
          res->e47 = c->e47 + a->e47 * b->r;
          res->e57 = c->e57 + a->e57 * b->r;
          res->e67 = c->e67 + a->e67 * b->r;
          break;
        case 1:
          // res order: 3
          res->e123 = c->e123 + a->e23 * b->e1 + a->e13 * b->e2 
                    + a->e12 * b->e3;
          res->e124 = c->e124 + a->e24 * b->e1 + a->e14 * b->e2 
                    + a->e12 * b->e4;
          res->e134 = c->e134 + a->e34 * b->e1 + a->e14 * b->e3 
                    + a->e13 * b->e4;
          res->e234 = c->e234 + a->e34 * b->e2 + a->e24 * b->e3 
                    + a->e23 * b->e4;
          res->e125 = c->e125 + a->e25 * b->e1 + a->e15 * b->e2 
                    + a->e12 * b->e5;
          res->e135 = c->e135 + a->e35 * b->e1 + a->e15 * b->e3 
                    + a->e13 * b->e5;
          res->e235 = c->e235 + a->e35 * b->e2 + a->e25 * b->e3 
                    + a->e23 * b->e5;
          res->e145 = c->e145 + a->e45 * b->e1 + a->e15 * b->e4 
                    + a->e14 * b->e5;
          res->e245 = c->e245 + a->e45 * b->e2 + a->e25 * b->e4 
                    + a->e24 * b->e5;
          res->e345 = c->e345 + a->e45 * b->e3 + a->e35 * b->e4 
                    + a->e34 * b->e5;
          res->e126 = c->e126 + a->e26 * b->e1 + a->e16 * b->e2 
                    + a->e12 * b->e6;
          res->e136 = c->e136 + a->e36 * b->e1 + a->e16 * b->e3 
                    + a->e13 * b->e6;
          res->e236 = c->e236 + a->e36 * b->e2 + a->e26 * b->e3 
                    + a->e23 * b->e6;
          res->e146 = c->e146 + a->e46 * b->e1 + a->e16 * b->e4 
                    + a->e14 * b->e6;
          res->e246 = c->e246 + a->e46 * b->e2 + a->e26 * b->e4 
                    + a->e24 * b->e6;
          res->e346 = c->e346 + a->e46 * b->e3 + a->e36 * b->e4 
                    + a->e34 * b->e6;
          res->e156 = c->e156 + a->e56 * b->e1 + a->e16 * b->e5 
                    + a->e15 * b->e6;
          res->e256 = c->e256 + a->e56 * b->e2 + a->e26 * b->e5 
                    + a->e25 * b->e6;
          res->e356 = c->e356 + a->e56 * b->e3 + a->e36 * b->e5 
                    + a->e35 * b->e6;
          res->e456 = c->e456 + a->e56 * b->e4 + a->e46 * b->e5 
                    + a->e45 * b->e6;
          res->e127 = c->e127 + a->e27 * b->e1 + a->e17 * b->e2 
                    + a->e12 * b->e7;
          res->e137 = c->e137 + a->e37 * b->e1 + a->e17 * b->e3 
                    + a->e13 * b->e7;
          res->e237 = c->e237 + a->e37 * b->e2 + a->e27 * b->e3 
                    + a->e23 * b->e7;
          res->e147 = c->e147 + a->e47 * b->e1 + a->e17 * b->e4 
                    + a->e14 * b->e7;
          res->e247 = c->e247 + a->e47 * b->e2 + a->e27 * b->e4 
                    + a->e24 * b->e7;
          res->e347 = c->e347 + a->e47 * b->e3 + a->e37 * b->e4 
                    + a->e34 * b->e7;
          res->e157 = c->e157 + a->e57 * b->e1 + a->e17 * b->e5 
                    + a->e15 * b->e7;
          res->e257 = c->e257 + a->e57 * b->e2 + a->e27 * b->e5 
                    + a->e25 * b->e7;
          res->e357 = c->e357 + a->e57 * b->e3 + a->e37 * b->e5 
                    + a->e35 * b->e7;
          res->e457 = c->e457 + a->e57 * b->e4 + a->e47 * b->e5 
                    + a->e45 * b->e7;
          res->e167 = c->e167 + a->e67 * b->e1 + a->e17 * b->e6 
                    + a->e16 * b->e7;
          res->e267 = c->e267 + a->e67 * b->e2 + a->e27 * b->e6 
                    + a->e26 * b->e7;
          res->e367 = c->e367 + a->e67 * b->e3 + a->e37 * b->e6 
                    + a->e36 * b->e7;
          res->e467 = c->e467 + a->e67 * b->e4 + a->e47 * b->e6 
                    + a->e46 * b->e7;
          res->e567 = c->e567 + a->e67 * b->e5 + a->e57 * b->e6 
                    + a->e56 * b->e7;
          break;
        case 2:
          // res order: 4
          res->e1234 = c->e1234 + a->e12 * b->e34 + a->e13 * b->e24 
                     + a->e23 * b->e14 + a->e14 * b->e23 + a->e24 * b->e13 
                     + a->e34 * b->e12;
          res->e1235 = c->e1235 + a->e12 * b->e35 + a->e13 * b->e25 
                     + a->e23 * b->e15 + a->e15 * b->e23 + a->e25 * b->e13 
                     + a->e35 * b->e12;
          res->e1245 = c->e1245 + a->e12 * b->e45 + a->e14 * b->e25 
                     + a->e24 * b->e15 + a->e15 * b->e24 + a->e25 * b->e14 
                     + a->e45 * b->e12;
          res->e1345 = c->e1345 + a->e13 * b->e45 + a->e14 * b->e35 
                     + a->e34 * b->e15 + a->e15 * b->e34 + a->e35 * b->e14 
                     + a->e45 * b->e13;
          res->e2345 = c->e2345 + a->e23 * b->e45 + a->e24 * b->e35 
                     + a->e34 * b->e25 + a->e25 * b->e34 + a->e35 * b->e24 
                     + a->e45 * b->e23;
          res->e1236 = c->e1236 + a->e12 * b->e36 + a->e13 * b->e26 
                     + a->e23 * b->e16 + a->e16 * b->e23 + a->e26 * b->e13 
                     + a->e36 * b->e12;
          res->e1246 = c->e1246 + a->e12 * b->e46 + a->e14 * b->e26 
                     + a->e24 * b->e16 + a->e16 * b->e24 + a->e26 * b->e14 
                     + a->e46 * b->e12;
          res->e1346 = c->e1346 + a->e13 * b->e46 + a->e14 * b->e36 
                     + a->e34 * b->e16 + a->e16 * b->e34 + a->e36 * b->e14 
                     + a->e46 * b->e13;
          res->e2346 = c->e2346 + a->e23 * b->e46 + a->e24 * b->e36 
                     + a->e34 * b->e26 + a->e26 * b->e34 + a->e36 * b->e24 
                     + a->e46 * b->e23;
          res->e1256 = c->e1256 + a->e12 * b->e56 + a->e15 * b->e26 
                     + a->e25 * b->e16 + a->e16 * b->e25 + a->e26 * b->e15 
                     + a->e56 * b->e12;
          res->e1356 = c->e1356 + a->e13 * b->e56 + a->e15 * b->e36 
                     + a->e35 * b->e16 + a->e16 * b->e35 + a->e36 * b->e15 
                     + a->e56 * b->e13;
          res->e2356 = c->e2356 + a->e23 * b->e56 + a->e25 * b->e36 
                     + a->e35 * b->e26 + a->e26 * b->e35 + a->e36 * b->e25 
                     + a->e56 * b->e23;
          res->e1456 = c->e1456 + a->e14 * b->e56 + a->e15 * b->e46 
                     + a->e45 * b->e16 + a->e16 * b->e45 + a->e46 * b->e15 
                     + a->e56 * b->e14;
          res->e2456 = c->e2456 + a->e24 * b->e56 + a->e25 * b->e46 
                     + a->e45 * b->e26 + a->e26 * b->e45 + a->e46 * b->e25 
                     + a->e56 * b->e24;
          res->e3456 = c->e3456 + a->e34 * b->e56 + a->e35 * b->e46 
                     + a->e45 * b->e36 + a->e36 * b->e45 + a->e46 * b->e35 
                     + a->e56 * b->e34;
          res->e1237 = c->e1237 + a->e12 * b->e37 + a->e13 * b->e27 
                     + a->e23 * b->e17 + a->e17 * b->e23 + a->e27 * b->e13 
                     + a->e37 * b->e12;
          res->e1247 = c->e1247 + a->e12 * b->e47 + a->e14 * b->e27 
                     + a->e24 * b->e17 + a->e17 * b->e24 + a->e27 * b->e14 
                     + a->e47 * b->e12;
          res->e1347 = c->e1347 + a->e13 * b->e47 + a->e14 * b->e37 
                     + a->e34 * b->e17 + a->e17 * b->e34 + a->e37 * b->e14 
                     + a->e47 * b->e13;
          res->e2347 = c->e2347 + a->e23 * b->e47 + a->e24 * b->e37 
                     + a->e34 * b->e27 + a->e27 * b->e34 + a->e37 * b->e24 
                     + a->e47 * b->e23;
          res->e1257 = c->e1257 + a->e12 * b->e57 + a->e15 * b->e27 
                     + a->e25 * b->e17 + a->e17 * b->e25 + a->e27 * b->e15 
                     + a->e57 * b->e12;
          res->e1357 = c->e1357 + a->e13 * b->e57 + a->e15 * b->e37 
                     + a->e35 * b->e17 + a->e17 * b->e35 + a->e37 * b->e15 
                     + a->e57 * b->e13;
          res->e2357 = c->e2357 + a->e23 * b->e57 + a->e25 * b->e37 
                     + a->e35 * b->e27 + a->e27 * b->e35 + a->e37 * b->e25 
                     + a->e57 * b->e23;
          res->e1457 = c->e1457 + a->e14 * b->e57 + a->e15 * b->e47 
                     + a->e45 * b->e17 + a->e17 * b->e45 + a->e47 * b->e15 
                     + a->e57 * b->e14;
          res->e2457 = c->e2457 + a->e24 * b->e57 + a->e25 * b->e47 
                     + a->e45 * b->e27 + a->e27 * b->e45 + a->e47 * b->e25 
                     + a->e57 * b->e24;
          res->e3457 = c->e3457 + a->e34 * b->e57 + a->e35 * b->e47 
                     + a->e45 * b->e37 + a->e37 * b->e45 + a->e47 * b->e35 
                     + a->e57 * b->e34;
          res->e1267 = c->e1267 + a->e12 * b->e67 + a->e16 * b->e27 
                     + a->e26 * b->e17 + a->e17 * b->e26 + a->e27 * b->e16 
                     + a->e67 * b->e12;
          res->e1367 = c->e1367 + a->e13 * b->e67 + a->e16 * b->e37 
                     + a->e36 * b->e17 + a->e17 * b->e36 + a->e37 * b->e16 
                     + a->e67 * b->e13;
          res->e2367 = c->e2367 + a->e23 * b->e67 + a->e26 * b->e37 
                     + a->e36 * b->e27 + a->e27 * b->e36 + a->e37 * b->e26 
                     + a->e67 * b->e23;
          res->e1467 = c->e1467 + a->e14 * b->e67 + a->e16 * b->e47 
                     + a->e46 * b->e17 + a->e17 * b->e46 + a->e47 * b->e16 
                     + a->e67 * b->e14;
          res->e2467 = c->e2467 + a->e24 * b->e67 + a->e26 * b->e47 
                     + a->e46 * b->e27 + a->e27 * b->e46 + a->e47 * b->e26 
                     + a->e67 * b->e24;
          res->e3467 = c->e3467 + a->e34 * b->e67 + a->e36 * b->e47 
                     + a->e46 * b->e37 + a->e37 * b->e46 + a->e47 * b->e36 
                     + a->e67 * b->e34;
          res->e1567 = c->e1567 + a->e15 * b->e67 + a->e16 * b->e57 
                     + a->e56 * b->e17 + a->e17 * b->e56 + a->e57 * b->e16 
                     + a->e67 * b->e15;
          res->e2567 = c->e2567 + a->e25 * b->e67 + a->e26 * b->e57 
                     + a->e56 * b->e27 + a->e27 * b->e56 + a->e57 * b->e26 
                     + a->e67 * b->e25;
          res->e3567 = c->e3567 + a->e35 * b->e67 + a->e36 * b->e57 
                     + a->e56 * b->e37 + a->e37 * b->e56 + a->e57 * b->e36 
                     + a->e67 * b->e35;
          res->e4567 = c->e4567 + a->e45 * b->e67 + a->e46 * b->e57 
                     + a->e56 * b->e47 + a->e47 * b->e56 + a->e57 * b->e46 
                     + a->e67 * b->e45;
          break;
        case 3:
          // res order: 5
          res->e12345 = c->e12345 + a->e12 * b->e345 + a->e13 * b->e245 
                      + a->e23 * b->e145 + a->e14 * b->e235 + a->e24 * b->e135 
                      + a->e34 * b->e125 + a->e15 * b->e234 + a->e25 * b->e134 
                      + a->e35 * b->e124 + a->e45 * b->e123;
          res->e12346 = c->e12346 + a->e12 * b->e346 + a->e13 * b->e246 
                      + a->e23 * b->e146 + a->e14 * b->e236 + a->e24 * b->e136 
                      + a->e34 * b->e126 + a->e16 * b->e234 + a->e26 * b->e134 
                      + a->e36 * b->e124 + a->e46 * b->e123;
          res->e12356 = c->e12356 + a->e12 * b->e356 + a->e13 * b->e256 
                      + a->e23 * b->e156 + a->e15 * b->e236 + a->e25 * b->e136 
                      + a->e35 * b->e126 + a->e16 * b->e235 + a->e26 * b->e135 
                      + a->e36 * b->e125 + a->e56 * b->e123;
          res->e12456 = c->e12456 + a->e12 * b->e456 + a->e14 * b->e256 
                      + a->e24 * b->e156 + a->e15 * b->e246 + a->e25 * b->e146 
                      + a->e45 * b->e126 + a->e16 * b->e245 + a->e26 * b->e145 
                      + a->e46 * b->e125 + a->e56 * b->e124;
          res->e13456 = c->e13456 + a->e13 * b->e456 + a->e14 * b->e356 
                      + a->e34 * b->e156 + a->e15 * b->e346 + a->e35 * b->e146 
                      + a->e45 * b->e136 + a->e16 * b->e345 + a->e36 * b->e145 
                      + a->e46 * b->e135 + a->e56 * b->e134;
          res->e23456 = c->e23456 + a->e23 * b->e456 + a->e24 * b->e356 
                      + a->e34 * b->e256 + a->e25 * b->e346 + a->e35 * b->e246 
                      + a->e45 * b->e236 + a->e26 * b->e345 + a->e36 * b->e245 
                      + a->e46 * b->e235 + a->e56 * b->e234;
          res->e12347 = c->e12347 + a->e12 * b->e347 + a->e13 * b->e247 
                      + a->e23 * b->e147 + a->e14 * b->e237 + a->e24 * b->e137 
                      + a->e34 * b->e127 + a->e17 * b->e234 + a->e27 * b->e134 
                      + a->e37 * b->e124 + a->e47 * b->e123;
          res->e12357 = c->e12357 + a->e12 * b->e357 + a->e13 * b->e257 
                      + a->e23 * b->e157 + a->e15 * b->e237 + a->e25 * b->e137 
                      + a->e35 * b->e127 + a->e17 * b->e235 + a->e27 * b->e135 
                      + a->e37 * b->e125 + a->e57 * b->e123;
          res->e12457 = c->e12457 + a->e12 * b->e457 + a->e14 * b->e257 
                      + a->e24 * b->e157 + a->e15 * b->e247 + a->e25 * b->e147 
                      + a->e45 * b->e127 + a->e17 * b->e245 + a->e27 * b->e145 
                      + a->e47 * b->e125 + a->e57 * b->e124;
          res->e13457 = c->e13457 + a->e13 * b->e457 + a->e14 * b->e357 
                      + a->e34 * b->e157 + a->e15 * b->e347 + a->e35 * b->e147 
                      + a->e45 * b->e137 + a->e17 * b->e345 + a->e37 * b->e145 
                      + a->e47 * b->e135 + a->e57 * b->e134;
          res->e23457 = c->e23457 + a->e23 * b->e457 + a->e24 * b->e357 
                      + a->e34 * b->e257 + a->e25 * b->e347 + a->e35 * b->e247 
                      + a->e45 * b->e237 + a->e27 * b->e345 + a->e37 * b->e245 
                      + a->e47 * b->e235 + a->e57 * b->e234;
          res->e12367 = c->e12367 + a->e12 * b->e367 + a->e13 * b->e267 
                      + a->e23 * b->e167 + a->e16 * b->e237 + a->e26 * b->e137 
                      + a->e36 * b->e127 + a->e17 * b->e236 + a->e27 * b->e136 
                      + a->e37 * b->e126 + a->e67 * b->e123;
          res->e12467 = c->e12467 + a->e12 * b->e467 + a->e14 * b->e267 
                      + a->e24 * b->e167 + a->e16 * b->e247 + a->e26 * b->e147 
                      + a->e46 * b->e127 + a->e17 * b->e246 + a->e27 * b->e146 
                      + a->e47 * b->e126 + a->e67 * b->e124;
          res->e13467 = c->e13467 + a->e13 * b->e467 + a->e14 * b->e367 
                      + a->e34 * b->e167 + a->e16 * b->e347 + a->e36 * b->e147 
                      + a->e46 * b->e137 + a->e17 * b->e346 + a->e37 * b->e146 
                      + a->e47 * b->e136 + a->e67 * b->e134;
          res->e23467 = c->e23467 + a->e23 * b->e467 + a->e24 * b->e367 
                      + a->e34 * b->e267 + a->e26 * b->e347 + a->e36 * b->e247 
                      + a->e46 * b->e237 + a->e27 * b->e346 + a->e37 * b->e246 
                      + a->e47 * b->e236 + a->e67 * b->e234;
          res->e12567 = c->e12567 + a->e12 * b->e567 + a->e15 * b->e267 
                      + a->e25 * b->e167 + a->e16 * b->e257 + a->e26 * b->e157 
                      + a->e56 * b->e127 + a->e17 * b->e256 + a->e27 * b->e156 
                      + a->e57 * b->e126 + a->e67 * b->e125;
          res->e13567 = c->e13567 + a->e13 * b->e567 + a->e15 * b->e367 
                      + a->e35 * b->e167 + a->e16 * b->e357 + a->e36 * b->e157 
                      + a->e56 * b->e137 + a->e17 * b->e356 + a->e37 * b->e156 
                      + a->e57 * b->e136 + a->e67 * b->e135;
          res->e23567 = c->e23567 + a->e23 * b->e567 + a->e25 * b->e367 
                      + a->e35 * b->e267 + a->e26 * b->e357 + a->e36 * b->e257 
                      + a->e56 * b->e237 + a->e27 * b->e356 + a->e37 * b->e256 
                      + a->e57 * b->e236 + a->e67 * b->e235;
          res->e14567 = c->e14567 + a->e14 * b->e567 + a->e15 * b->e467 
                      + a->e45 * b->e167 + a->e16 * b->e457 + a->e46 * b->e157 
                      + a->e56 * b->e147 + a->e17 * b->e456 + a->e47 * b->e156 
                      + a->e57 * b->e146 + a->e67 * b->e145;
          res->e24567 = c->e24567 + a->e24 * b->e567 + a->e25 * b->e467 
                      + a->e45 * b->e267 + a->e26 * b->e457 + a->e46 * b->e257 
                      + a->e56 * b->e247 + a->e27 * b->e456 + a->e47 * b->e256 
                      + a->e57 * b->e246 + a->e67 * b->e245;
          res->e34567 = c->e34567 + a->e34 * b->e567 + a->e35 * b->e467 
                      + a->e45 * b->e367 + a->e36 * b->e457 + a->e46 * b->e357 
                      + a->e56 * b->e347 + a->e37 * b->e456 + a->e47 * b->e356 
                      + a->e57 * b->e346 + a->e67 * b->e345;
          break;
        case 4:
          // res order: 6
          res->e123456 = c->e123456 + a->e12 * b->e3456 + a->e13 * b->e2456 
                       + a->e23 * b->e1456 + a->e14 * b->e2356 + a->e24 * b->e1356 
                       + a->e34 * b->e1256 + a->e15 * b->e2346 + a->e25 * b->e1346 
                       + a->e35 * b->e1246 + a->e45 * b->e1236 + a->e16 * b->e2345 
                       + a->e26 * b->e1345 + a->e36 * b->e1245 + a->e46 * b->e1235 
                       + a->e56 * b->e1234;
          res->e123457 = c->e123457 + a->e12 * b->e3457 + a->e13 * b->e2457 
                       + a->e23 * b->e1457 + a->e14 * b->e2357 + a->e24 * b->e1357 
                       + a->e34 * b->e1257 + a->e15 * b->e2347 + a->e25 * b->e1347 
                       + a->e35 * b->e1247 + a->e45 * b->e1237 + a->e17 * b->e2345 
                       + a->e27 * b->e1345 + a->e37 * b->e1245 + a->e47 * b->e1235 
                       + a->e57 * b->e1234;
          res->e123467 = c->e123467 + a->e12 * b->e3467 + a->e13 * b->e2467 
                       + a->e23 * b->e1467 + a->e14 * b->e2367 + a->e24 * b->e1367 
                       + a->e34 * b->e1267 + a->e16 * b->e2347 + a->e26 * b->e1347 
                       + a->e36 * b->e1247 + a->e46 * b->e1237 + a->e17 * b->e2346 
                       + a->e27 * b->e1346 + a->e37 * b->e1246 + a->e47 * b->e1236 
                       + a->e67 * b->e1234;
          res->e123567 = c->e123567 + a->e12 * b->e3567 + a->e13 * b->e2567 
                       + a->e23 * b->e1567 + a->e15 * b->e2367 + a->e25 * b->e1367 
                       + a->e35 * b->e1267 + a->e16 * b->e2357 + a->e26 * b->e1357 
                       + a->e36 * b->e1257 + a->e56 * b->e1237 + a->e17 * b->e2356 
                       + a->e27 * b->e1356 + a->e37 * b->e1256 + a->e57 * b->e1236 
                       + a->e67 * b->e1235;
          res->e124567 = c->e124567 + a->e12 * b->e4567 + a->e14 * b->e2567 
                       + a->e24 * b->e1567 + a->e15 * b->e2467 + a->e25 * b->e1467 
                       + a->e45 * b->e1267 + a->e16 * b->e2457 + a->e26 * b->e1457 
                       + a->e46 * b->e1257 + a->e56 * b->e1247 + a->e17 * b->e2456 
                       + a->e27 * b->e1456 + a->e47 * b->e1256 + a->e57 * b->e1246 
                       + a->e67 * b->e1245;
          res->e134567 = c->e134567 + a->e13 * b->e4567 + a->e14 * b->e3567 
                       + a->e34 * b->e1567 + a->e15 * b->e3467 + a->e35 * b->e1467 
                       + a->e45 * b->e1367 + a->e16 * b->e3457 + a->e36 * b->e1457 
                       + a->e46 * b->e1357 + a->e56 * b->e1347 + a->e17 * b->e3456 
                       + a->e37 * b->e1456 + a->e47 * b->e1356 + a->e57 * b->e1346 
                       + a->e67 * b->e1345;
          res->e234567 = c->e234567 + a->e23 * b->e4567 + a->e24 * b->e3567 
                       + a->e34 * b->e2567 + a->e25 * b->e3467 + a->e35 * b->e2467 
                       + a->e45 * b->e2367 + a->e26 * b->e3457 + a->e36 * b->e2457 
                       + a->e46 * b->e2357 + a->e56 * b->e2347 + a->e27 * b->e3456 
                       + a->e37 * b->e2456 + a->e47 * b->e2356 + a->e57 * b->e2346 
                       + a->e67 * b->e2345;
          break;
        case 5:
          // res order: 7
          res->e1234567 = c->e1234567 + a->e12 * b->e34567 + a->e13 * b->e24567 
                        + a->e23 * b->e14567 + a->e14 * b->e23567 + a->e24 * b->e13567 
                        + a->e34 * b->e12567 + a->e15 * b->e23467 + a->e25 * b->e13467 
                        + a->e35 * b->e12467 + a->e45 * b->e12367 + a->e16 * b->e23457 
                        + a->e26 * b->e13457 + a->e36 * b->e12457 + a->e46 * b->e12357 
                        + a->e56 * b->e12347 + a->e17 * b->e23456 + a->e27 * b->e13456 
                        + a->e37 * b->e12456 + a->e47 * b->e12356 + a->e57 * b->e12346 
                        + a->e67 * b->e12345;
          break;
      }
      break;
    case 3:
      switch( ord_rhs ){
        case 0:
          // res order: 3
          res->e123 = c->e123 + a->e123 * b->r;
          res->e124 = c->e124 + a->e124 * b->r;
          res->e134 = c->e134 + a->e134 * b->r;
          res->e234 = c->e234 + a->e234 * b->r;
          res->e125 = c->e125 + a->e125 * b->r;
          res->e135 = c->e135 + a->e135 * b->r;
          res->e235 = c->e235 + a->e235 * b->r;
          res->e145 = c->e145 + a->e145 * b->r;
          res->e245 = c->e245 + a->e245 * b->r;
          res->e345 = c->e345 + a->e345 * b->r;
          res->e126 = c->e126 + a->e126 * b->r;
          res->e136 = c->e136 + a->e136 * b->r;
          res->e236 = c->e236 + a->e236 * b->r;
          res->e146 = c->e146 + a->e146 * b->r;
          res->e246 = c->e246 + a->e246 * b->r;
          res->e346 = c->e346 + a->e346 * b->r;
          res->e156 = c->e156 + a->e156 * b->r;
          res->e256 = c->e256 + a->e256 * b->r;
          res->e356 = c->e356 + a->e356 * b->r;
          res->e456 = c->e456 + a->e456 * b->r;
          res->e127 = c->e127 + a->e127 * b->r;
          res->e137 = c->e137 + a->e137 * b->r;
          res->e237 = c->e237 + a->e237 * b->r;
          res->e147 = c->e147 + a->e147 * b->r;
          res->e247 = c->e247 + a->e247 * b->r;
          res->e347 = c->e347 + a->e347 * b->r;
          res->e157 = c->e157 + a->e157 * b->r;
          res->e257 = c->e257 + a->e257 * b->r;
          res->e357 = c->e357 + a->e357 * b->r;
          res->e457 = c->e457 + a->e457 * b->r;
          res->e167 = c->e167 + a->e167 * b->r;
          res->e267 = c->e267 + a->e267 * b->r;
          res->e367 = c->e367 + a->e367 * b->r;
          res->e467 = c->e467 + a->e467 * b->r;
          res->e567 = c->e567 + a->e567 * b->r;
          break;
        case 1:
          // res order: 4
          res->e1234 = c->e1234 + a->e234 * b->e1 + a->e134 * b->e2 
                     + a->e124 * b->e3 + a->e123 * b->e4;
          res->e1235 = c->e1235 + a->e235 * b->e1 + a->e135 * b->e2 
                     + a->e125 * b->e3 + a->e123 * b->e5;
          res->e1245 = c->e1245 + a->e245 * b->e1 + a->e145 * b->e2 
                     + a->e125 * b->e4 + a->e124 * b->e5;
          res->e1345 = c->e1345 + a->e345 * b->e1 + a->e145 * b->e3 
                     + a->e135 * b->e4 + a->e134 * b->e5;
          res->e2345 = c->e2345 + a->e345 * b->e2 + a->e245 * b->e3 
                     + a->e235 * b->e4 + a->e234 * b->e5;
          res->e1236 = c->e1236 + a->e236 * b->e1 + a->e136 * b->e2 
                     + a->e126 * b->e3 + a->e123 * b->e6;
          res->e1246 = c->e1246 + a->e246 * b->e1 + a->e146 * b->e2 
                     + a->e126 * b->e4 + a->e124 * b->e6;
          res->e1346 = c->e1346 + a->e346 * b->e1 + a->e146 * b->e3 
                     + a->e136 * b->e4 + a->e134 * b->e6;
          res->e2346 = c->e2346 + a->e346 * b->e2 + a->e246 * b->e3 
                     + a->e236 * b->e4 + a->e234 * b->e6;
          res->e1256 = c->e1256 + a->e256 * b->e1 + a->e156 * b->e2 
                     + a->e126 * b->e5 + a->e125 * b->e6;
          res->e1356 = c->e1356 + a->e356 * b->e1 + a->e156 * b->e3 
                     + a->e136 * b->e5 + a->e135 * b->e6;
          res->e2356 = c->e2356 + a->e356 * b->e2 + a->e256 * b->e3 
                     + a->e236 * b->e5 + a->e235 * b->e6;
          res->e1456 = c->e1456 + a->e456 * b->e1 + a->e156 * b->e4 
                     + a->e146 * b->e5 + a->e145 * b->e6;
          res->e2456 = c->e2456 + a->e456 * b->e2 + a->e256 * b->e4 
                     + a->e246 * b->e5 + a->e245 * b->e6;
          res->e3456 = c->e3456 + a->e456 * b->e3 + a->e356 * b->e4 
                     + a->e346 * b->e5 + a->e345 * b->e6;
          res->e1237 = c->e1237 + a->e237 * b->e1 + a->e137 * b->e2 
                     + a->e127 * b->e3 + a->e123 * b->e7;
          res->e1247 = c->e1247 + a->e247 * b->e1 + a->e147 * b->e2 
                     + a->e127 * b->e4 + a->e124 * b->e7;
          res->e1347 = c->e1347 + a->e347 * b->e1 + a->e147 * b->e3 
                     + a->e137 * b->e4 + a->e134 * b->e7;
          res->e2347 = c->e2347 + a->e347 * b->e2 + a->e247 * b->e3 
                     + a->e237 * b->e4 + a->e234 * b->e7;
          res->e1257 = c->e1257 + a->e257 * b->e1 + a->e157 * b->e2 
                     + a->e127 * b->e5 + a->e125 * b->e7;
          res->e1357 = c->e1357 + a->e357 * b->e1 + a->e157 * b->e3 
                     + a->e137 * b->e5 + a->e135 * b->e7;
          res->e2357 = c->e2357 + a->e357 * b->e2 + a->e257 * b->e3 
                     + a->e237 * b->e5 + a->e235 * b->e7;
          res->e1457 = c->e1457 + a->e457 * b->e1 + a->e157 * b->e4 
                     + a->e147 * b->e5 + a->e145 * b->e7;
          res->e2457 = c->e2457 + a->e457 * b->e2 + a->e257 * b->e4 
                     + a->e247 * b->e5 + a->e245 * b->e7;
          res->e3457 = c->e3457 + a->e457 * b->e3 + a->e357 * b->e4 
                     + a->e347 * b->e5 + a->e345 * b->e7;
          res->e1267 = c->e1267 + a->e267 * b->e1 + a->e167 * b->e2 
                     + a->e127 * b->e6 + a->e126 * b->e7;
          res->e1367 = c->e1367 + a->e367 * b->e1 + a->e167 * b->e3 
                     + a->e137 * b->e6 + a->e136 * b->e7;
          res->e2367 = c->e2367 + a->e367 * b->e2 + a->e267 * b->e3 
                     + a->e237 * b->e6 + a->e236 * b->e7;
          res->e1467 = c->e1467 + a->e467 * b->e1 + a->e167 * b->e4 
                     + a->e147 * b->e6 + a->e146 * b->e7;
          res->e2467 = c->e2467 + a->e467 * b->e2 + a->e267 * b->e4 
                     + a->e247 * b->e6 + a->e246 * b->e7;
          res->e3467 = c->e3467 + a->e467 * b->e3 + a->e367 * b->e4 
                     + a->e347 * b->e6 + a->e346 * b->e7;
          res->e1567 = c->e1567 + a->e567 * b->e1 + a->e167 * b->e5 
                     + a->e157 * b->e6 + a->e156 * b->e7;
          res->e2567 = c->e2567 + a->e567 * b->e2 + a->e267 * b->e5 
                     + a->e257 * b->e6 + a->e256 * b->e7;
          res->e3567 = c->e3567 + a->e567 * b->e3 + a->e367 * b->e5 
                     + a->e357 * b->e6 + a->e356 * b->e7;
          res->e4567 = c->e4567 + a->e567 * b->e4 + a->e467 * b->e5 
                     + a->e457 * b->e6 + a->e456 * b->e7;
          break;
        case 2:
          // res order: 5
          res->e12345 = c->e12345 + a->e345 * b->e12 + a->e245 * b->e13 
                      + a->e145 * b->e23 + a->e235 * b->e14 + a->e135 * b->e24 
                      + a->e125 * b->e34 + a->e234 * b->e15 + a->e134 * b->e25 
                      + a->e124 * b->e35 + a->e123 * b->e45;
          res->e12346 = c->e12346 + a->e346 * b->e12 + a->e246 * b->e13 
                      + a->e146 * b->e23 + a->e236 * b->e14 + a->e136 * b->e24 
                      + a->e126 * b->e34 + a->e234 * b->e16 + a->e134 * b->e26 
                      + a->e124 * b->e36 + a->e123 * b->e46;
          res->e12356 = c->e12356 + a->e356 * b->e12 + a->e256 * b->e13 
                      + a->e156 * b->e23 + a->e236 * b->e15 + a->e136 * b->e25 
                      + a->e126 * b->e35 + a->e235 * b->e16 + a->e135 * b->e26 
                      + a->e125 * b->e36 + a->e123 * b->e56;
          res->e12456 = c->e12456 + a->e456 * b->e12 + a->e256 * b->e14 
                      + a->e156 * b->e24 + a->e246 * b->e15 + a->e146 * b->e25 
                      + a->e126 * b->e45 + a->e245 * b->e16 + a->e145 * b->e26 
                      + a->e125 * b->e46 + a->e124 * b->e56;
          res->e13456 = c->e13456 + a->e456 * b->e13 + a->e356 * b->e14 
                      + a->e156 * b->e34 + a->e346 * b->e15 + a->e146 * b->e35 
                      + a->e136 * b->e45 + a->e345 * b->e16 + a->e145 * b->e36 
                      + a->e135 * b->e46 + a->e134 * b->e56;
          res->e23456 = c->e23456 + a->e456 * b->e23 + a->e356 * b->e24 
                      + a->e256 * b->e34 + a->e346 * b->e25 + a->e246 * b->e35 
                      + a->e236 * b->e45 + a->e345 * b->e26 + a->e245 * b->e36 
                      + a->e235 * b->e46 + a->e234 * b->e56;
          res->e12347 = c->e12347 + a->e347 * b->e12 + a->e247 * b->e13 
                      + a->e147 * b->e23 + a->e237 * b->e14 + a->e137 * b->e24 
                      + a->e127 * b->e34 + a->e234 * b->e17 + a->e134 * b->e27 
                      + a->e124 * b->e37 + a->e123 * b->e47;
          res->e12357 = c->e12357 + a->e357 * b->e12 + a->e257 * b->e13 
                      + a->e157 * b->e23 + a->e237 * b->e15 + a->e137 * b->e25 
                      + a->e127 * b->e35 + a->e235 * b->e17 + a->e135 * b->e27 
                      + a->e125 * b->e37 + a->e123 * b->e57;
          res->e12457 = c->e12457 + a->e457 * b->e12 + a->e257 * b->e14 
                      + a->e157 * b->e24 + a->e247 * b->e15 + a->e147 * b->e25 
                      + a->e127 * b->e45 + a->e245 * b->e17 + a->e145 * b->e27 
                      + a->e125 * b->e47 + a->e124 * b->e57;
          res->e13457 = c->e13457 + a->e457 * b->e13 + a->e357 * b->e14 
                      + a->e157 * b->e34 + a->e347 * b->e15 + a->e147 * b->e35 
                      + a->e137 * b->e45 + a->e345 * b->e17 + a->e145 * b->e37 
                      + a->e135 * b->e47 + a->e134 * b->e57;
          res->e23457 = c->e23457 + a->e457 * b->e23 + a->e357 * b->e24 
                      + a->e257 * b->e34 + a->e347 * b->e25 + a->e247 * b->e35 
                      + a->e237 * b->e45 + a->e345 * b->e27 + a->e245 * b->e37 
                      + a->e235 * b->e47 + a->e234 * b->e57;
          res->e12367 = c->e12367 + a->e367 * b->e12 + a->e267 * b->e13 
                      + a->e167 * b->e23 + a->e237 * b->e16 + a->e137 * b->e26 
                      + a->e127 * b->e36 + a->e236 * b->e17 + a->e136 * b->e27 
                      + a->e126 * b->e37 + a->e123 * b->e67;
          res->e12467 = c->e12467 + a->e467 * b->e12 + a->e267 * b->e14 
                      + a->e167 * b->e24 + a->e247 * b->e16 + a->e147 * b->e26 
                      + a->e127 * b->e46 + a->e246 * b->e17 + a->e146 * b->e27 
                      + a->e126 * b->e47 + a->e124 * b->e67;
          res->e13467 = c->e13467 + a->e467 * b->e13 + a->e367 * b->e14 
                      + a->e167 * b->e34 + a->e347 * b->e16 + a->e147 * b->e36 
                      + a->e137 * b->e46 + a->e346 * b->e17 + a->e146 * b->e37 
                      + a->e136 * b->e47 + a->e134 * b->e67;
          res->e23467 = c->e23467 + a->e467 * b->e23 + a->e367 * b->e24 
                      + a->e267 * b->e34 + a->e347 * b->e26 + a->e247 * b->e36 
                      + a->e237 * b->e46 + a->e346 * b->e27 + a->e246 * b->e37 
                      + a->e236 * b->e47 + a->e234 * b->e67;
          res->e12567 = c->e12567 + a->e567 * b->e12 + a->e267 * b->e15 
                      + a->e167 * b->e25 + a->e257 * b->e16 + a->e157 * b->e26 
                      + a->e127 * b->e56 + a->e256 * b->e17 + a->e156 * b->e27 
                      + a->e126 * b->e57 + a->e125 * b->e67;
          res->e13567 = c->e13567 + a->e567 * b->e13 + a->e367 * b->e15 
                      + a->e167 * b->e35 + a->e357 * b->e16 + a->e157 * b->e36 
                      + a->e137 * b->e56 + a->e356 * b->e17 + a->e156 * b->e37 
                      + a->e136 * b->e57 + a->e135 * b->e67;
          res->e23567 = c->e23567 + a->e567 * b->e23 + a->e367 * b->e25 
                      + a->e267 * b->e35 + a->e357 * b->e26 + a->e257 * b->e36 
                      + a->e237 * b->e56 + a->e356 * b->e27 + a->e256 * b->e37 
                      + a->e236 * b->e57 + a->e235 * b->e67;
          res->e14567 = c->e14567 + a->e567 * b->e14 + a->e467 * b->e15 
                      + a->e167 * b->e45 + a->e457 * b->e16 + a->e157 * b->e46 
                      + a->e147 * b->e56 + a->e456 * b->e17 + a->e156 * b->e47 
                      + a->e146 * b->e57 + a->e145 * b->e67;
          res->e24567 = c->e24567 + a->e567 * b->e24 + a->e467 * b->e25 
                      + a->e267 * b->e45 + a->e457 * b->e26 + a->e257 * b->e46 
                      + a->e247 * b->e56 + a->e456 * b->e27 + a->e256 * b->e47 
                      + a->e246 * b->e57 + a->e245 * b->e67;
          res->e34567 = c->e34567 + a->e567 * b->e34 + a->e467 * b->e35 
                      + a->e367 * b->e45 + a->e457 * b->e36 + a->e357 * b->e46 
                      + a->e347 * b->e56 + a->e456 * b->e37 + a->e356 * b->e47 
                      + a->e346 * b->e57 + a->e345 * b->e67;
          break;
        case 3:
          // res order: 6
          res->e123456 = c->e123456 + a->e123 * b->e456 + a->e124 * b->e356 
                       + a->e134 * b->e256 + a->e234 * b->e156 + a->e125 * b->e346 
                       + a->e135 * b->e246 + a->e235 * b->e146 + a->e145 * b->e236 
                       + a->e245 * b->e136 + a->e345 * b->e126 + a->e126 * b->e345 
                       + a->e136 * b->e245 + a->e236 * b->e145 + a->e146 * b->e235 
                       + a->e246 * b->e135 + a->e346 * b->e125 + a->e156 * b->e234 
                       + a->e256 * b->e134 + a->e356 * b->e124 + a->e456 * b->e123;
          res->e123457 = c->e123457 + a->e123 * b->e457 + a->e124 * b->e357 
                       + a->e134 * b->e257 + a->e234 * b->e157 + a->e125 * b->e347 
                       + a->e135 * b->e247 + a->e235 * b->e147 + a->e145 * b->e237 
                       + a->e245 * b->e137 + a->e345 * b->e127 + a->e127 * b->e345 
                       + a->e137 * b->e245 + a->e237 * b->e145 + a->e147 * b->e235 
                       + a->e247 * b->e135 + a->e347 * b->e125 + a->e157 * b->e234 
                       + a->e257 * b->e134 + a->e357 * b->e124 + a->e457 * b->e123;
          res->e123467 = c->e123467 + a->e123 * b->e467 + a->e124 * b->e367 
                       + a->e134 * b->e267 + a->e234 * b->e167 + a->e126 * b->e347 
                       + a->e136 * b->e247 + a->e236 * b->e147 + a->e146 * b->e237 
                       + a->e246 * b->e137 + a->e346 * b->e127 + a->e127 * b->e346 
                       + a->e137 * b->e246 + a->e237 * b->e146 + a->e147 * b->e236 
                       + a->e247 * b->e136 + a->e347 * b->e126 + a->e167 * b->e234 
                       + a->e267 * b->e134 + a->e367 * b->e124 + a->e467 * b->e123;
          res->e123567 = c->e123567 + a->e123 * b->e567 + a->e125 * b->e367 
                       + a->e135 * b->e267 + a->e235 * b->e167 + a->e126 * b->e357 
                       + a->e136 * b->e257 + a->e236 * b->e157 + a->e156 * b->e237 
                       + a->e256 * b->e137 + a->e356 * b->e127 + a->e127 * b->e356 
                       + a->e137 * b->e256 + a->e237 * b->e156 + a->e157 * b->e236 
                       + a->e257 * b->e136 + a->e357 * b->e126 + a->e167 * b->e235 
                       + a->e267 * b->e135 + a->e367 * b->e125 + a->e567 * b->e123;
          res->e124567 = c->e124567 + a->e124 * b->e567 + a->e125 * b->e467 
                       + a->e145 * b->e267 + a->e245 * b->e167 + a->e126 * b->e457 
                       + a->e146 * b->e257 + a->e246 * b->e157 + a->e156 * b->e247 
                       + a->e256 * b->e147 + a->e456 * b->e127 + a->e127 * b->e456 
                       + a->e147 * b->e256 + a->e247 * b->e156 + a->e157 * b->e246 
                       + a->e257 * b->e146 + a->e457 * b->e126 + a->e167 * b->e245 
                       + a->e267 * b->e145 + a->e467 * b->e125 + a->e567 * b->e124;
          res->e134567 = c->e134567 + a->e134 * b->e567 + a->e135 * b->e467 
                       + a->e145 * b->e367 + a->e345 * b->e167 + a->e136 * b->e457 
                       + a->e146 * b->e357 + a->e346 * b->e157 + a->e156 * b->e347 
                       + a->e356 * b->e147 + a->e456 * b->e137 + a->e137 * b->e456 
                       + a->e147 * b->e356 + a->e347 * b->e156 + a->e157 * b->e346 
                       + a->e357 * b->e146 + a->e457 * b->e136 + a->e167 * b->e345 
                       + a->e367 * b->e145 + a->e467 * b->e135 + a->e567 * b->e134;
          res->e234567 = c->e234567 + a->e234 * b->e567 + a->e235 * b->e467 
                       + a->e245 * b->e367 + a->e345 * b->e267 + a->e236 * b->e457 
                       + a->e246 * b->e357 + a->e346 * b->e257 + a->e256 * b->e347 
                       + a->e356 * b->e247 + a->e456 * b->e237 + a->e237 * b->e456 
                       + a->e247 * b->e356 + a->e347 * b->e256 + a->e257 * b->e346 
                       + a->e357 * b->e246 + a->e457 * b->e236 + a->e267 * b->e345 
                       + a->e367 * b->e245 + a->e467 * b->e235 + a->e567 * b->e234;
          break;
        case 4:
          // res order: 7
          res->e1234567 = c->e1234567 + a->e123 * b->e4567 + a->e124 * b->e3567 
                        + a->e134 * b->e2567 + a->e234 * b->e1567 + a->e125 * b->e3467 
                        + a->e135 * b->e2467 + a->e235 * b->e1467 + a->e145 * b->e2367 
                        + a->e245 * b->e1367 + a->e345 * b->e1267 + a->e126 * b->e3457 
                        + a->e136 * b->e2457 + a->e236 * b->e1457 + a->e146 * b->e2357 
                        + a->e246 * b->e1357 + a->e346 * b->e1257 + a->e156 * b->e2347 
                        + a->e256 * b->e1347 + a->e356 * b->e1247 + a->e456 * b->e1237 
                        + a->e127 * b->e3456 + a->e137 * b->e2456 + a->e237 * b->e1456 
                        + a->e147 * b->e2356 + a->e247 * b->e1356 + a->e347 * b->e1256 
                        + a->e157 * b->e2346 + a->e257 * b->e1346 + a->e357 * b->e1246 
                        + a->e457 * b->e1236 + a->e167 * b->e2345 + a->e267 * b->e1345 
                        + a->e367 * b->e1245 + a->e467 * b->e1235 + a->e567 * b->e1234;
          break;
      }
      break;
    case 4:
      switch( ord_rhs ){
        case 0:
          // res order: 4
          res->e1234 = c->e1234 + a->e1234 * b->r;
          res->e1235 = c->e1235 + a->e1235 * b->r;
          res->e1245 = c->e1245 + a->e1245 * b->r;
          res->e1345 = c->e1345 + a->e1345 * b->r;
          res->e2345 = c->e2345 + a->e2345 * b->r;
          res->e1236 = c->e1236 + a->e1236 * b->r;
          res->e1246 = c->e1246 + a->e1246 * b->r;
          res->e1346 = c->e1346 + a->e1346 * b->r;
          res->e2346 = c->e2346 + a->e2346 * b->r;
          res->e1256 = c->e1256 + a->e1256 * b->r;
          res->e1356 = c->e1356 + a->e1356 * b->r;
          res->e2356 = c->e2356 + a->e2356 * b->r;
          res->e1456 = c->e1456 + a->e1456 * b->r;
          res->e2456 = c->e2456 + a->e2456 * b->r;
          res->e3456 = c->e3456 + a->e3456 * b->r;
          res->e1237 = c->e1237 + a->e1237 * b->r;
          res->e1247 = c->e1247 + a->e1247 * b->r;
          res->e1347 = c->e1347 + a->e1347 * b->r;
          res->e2347 = c->e2347 + a->e2347 * b->r;
          res->e1257 = c->e1257 + a->e1257 * b->r;
          res->e1357 = c->e1357 + a->e1357 * b->r;
          res->e2357 = c->e2357 + a->e2357 * b->r;
          res->e1457 = c->e1457 + a->e1457 * b->r;
          res->e2457 = c->e2457 + a->e2457 * b->r;
          res->e3457 = c->e3457 + a->e3457 * b->r;
          res->e1267 = c->e1267 + a->e1267 * b->r;
          res->e1367 = c->e1367 + a->e1367 * b->r;
          res->e2367 = c->e2367 + a->e2367 * b->r;
          res->e1467 = c->e1467 + a->e1467 * b->r;
          res->e2467 = c->e2467 + a->e2467 * b->r;
          res->e3467 = c->e3467 + a->e3467 * b->r;
          res->e1567 = c->e1567 + a->e1567 * b->r;
          res->e2567 = c->e2567 + a->e2567 * b->r;
          res->e3567 = c->e3567 + a->e3567 * b->r;
          res->e4567 = c->e4567 + a->e4567 * b->r;
          break;
        case 1:
          // res order: 5
          res->e12345 = c->e12345 + a->e2345 * b->e1 + a->e1345 * b->e2 
                      + a->e1245 * b->e3 + a->e1235 * b->e4 + a->e1234 * b->e5;
          res->e12346 = c->e12346 + a->e2346 * b->e1 + a->e1346 * b->e2 
                      + a->e1246 * b->e3 + a->e1236 * b->e4 + a->e1234 * b->e6;
          res->e12356 = c->e12356 + a->e2356 * b->e1 + a->e1356 * b->e2 
                      + a->e1256 * b->e3 + a->e1236 * b->e5 + a->e1235 * b->e6;
          res->e12456 = c->e12456 + a->e2456 * b->e1 + a->e1456 * b->e2 
                      + a->e1256 * b->e4 + a->e1246 * b->e5 + a->e1245 * b->e6;
          res->e13456 = c->e13456 + a->e3456 * b->e1 + a->e1456 * b->e3 
                      + a->e1356 * b->e4 + a->e1346 * b->e5 + a->e1345 * b->e6;
          res->e23456 = c->e23456 + a->e3456 * b->e2 + a->e2456 * b->e3 
                      + a->e2356 * b->e4 + a->e2346 * b->e5 + a->e2345 * b->e6;
          res->e12347 = c->e12347 + a->e2347 * b->e1 + a->e1347 * b->e2 
                      + a->e1247 * b->e3 + a->e1237 * b->e4 + a->e1234 * b->e7;
          res->e12357 = c->e12357 + a->e2357 * b->e1 + a->e1357 * b->e2 
                      + a->e1257 * b->e3 + a->e1237 * b->e5 + a->e1235 * b->e7;
          res->e12457 = c->e12457 + a->e2457 * b->e1 + a->e1457 * b->e2 
                      + a->e1257 * b->e4 + a->e1247 * b->e5 + a->e1245 * b->e7;
          res->e13457 = c->e13457 + a->e3457 * b->e1 + a->e1457 * b->e3 
                      + a->e1357 * b->e4 + a->e1347 * b->e5 + a->e1345 * b->e7;
          res->e23457 = c->e23457 + a->e3457 * b->e2 + a->e2457 * b->e3 
                      + a->e2357 * b->e4 + a->e2347 * b->e5 + a->e2345 * b->e7;
          res->e12367 = c->e12367 + a->e2367 * b->e1 + a->e1367 * b->e2 
                      + a->e1267 * b->e3 + a->e1237 * b->e6 + a->e1236 * b->e7;
          res->e12467 = c->e12467 + a->e2467 * b->e1 + a->e1467 * b->e2 
                      + a->e1267 * b->e4 + a->e1247 * b->e6 + a->e1246 * b->e7;
          res->e13467 = c->e13467 + a->e3467 * b->e1 + a->e1467 * b->e3 
                      + a->e1367 * b->e4 + a->e1347 * b->e6 + a->e1346 * b->e7;
          res->e23467 = c->e23467 + a->e3467 * b->e2 + a->e2467 * b->e3 
                      + a->e2367 * b->e4 + a->e2347 * b->e6 + a->e2346 * b->e7;
          res->e12567 = c->e12567 + a->e2567 * b->e1 + a->e1567 * b->e2 
                      + a->e1267 * b->e5 + a->e1257 * b->e6 + a->e1256 * b->e7;
          res->e13567 = c->e13567 + a->e3567 * b->e1 + a->e1567 * b->e3 
                      + a->e1367 * b->e5 + a->e1357 * b->e6 + a->e1356 * b->e7;
          res->e23567 = c->e23567 + a->e3567 * b->e2 + a->e2567 * b->e3 
                      + a->e2367 * b->e5 + a->e2357 * b->e6 + a->e2356 * b->e7;
          res->e14567 = c->e14567 + a->e4567 * b->e1 + a->e1567 * b->e4 
                      + a->e1467 * b->e5 + a->e1457 * b->e6 + a->e1456 * b->e7;
          res->e24567 = c->e24567 + a->e4567 * b->e2 + a->e2567 * b->e4 
                      + a->e2467 * b->e5 + a->e2457 * b->e6 + a->e2456 * b->e7;
          res->e34567 = c->e34567 + a->e4567 * b->e3 + a->e3567 * b->e4 
                      + a->e3467 * b->e5 + a->e3457 * b->e6 + a->e3456 * b->e7;
          break;
        case 2:
          // res order: 6
          res->e123456 = c->e123456 + a->e3456 * b->e12 + a->e2456 * b->e13 
                       + a->e1456 * b->e23 + a->e2356 * b->e14 + a->e1356 * b->e24 
                       + a->e1256 * b->e34 + a->e2346 * b->e15 + a->e1346 * b->e25 
                       + a->e1246 * b->e35 + a->e1236 * b->e45 + a->e2345 * b->e16 
                       + a->e1345 * b->e26 + a->e1245 * b->e36 + a->e1235 * b->e46 
                       + a->e1234 * b->e56;
          res->e123457 = c->e123457 + a->e3457 * b->e12 + a->e2457 * b->e13 
                       + a->e1457 * b->e23 + a->e2357 * b->e14 + a->e1357 * b->e24 
                       + a->e1257 * b->e34 + a->e2347 * b->e15 + a->e1347 * b->e25 
                       + a->e1247 * b->e35 + a->e1237 * b->e45 + a->e2345 * b->e17 
                       + a->e1345 * b->e27 + a->e1245 * b->e37 + a->e1235 * b->e47 
                       + a->e1234 * b->e57;
          res->e123467 = c->e123467 + a->e3467 * b->e12 + a->e2467 * b->e13 
                       + a->e1467 * b->e23 + a->e2367 * b->e14 + a->e1367 * b->e24 
                       + a->e1267 * b->e34 + a->e2347 * b->e16 + a->e1347 * b->e26 
                       + a->e1247 * b->e36 + a->e1237 * b->e46 + a->e2346 * b->e17 
                       + a->e1346 * b->e27 + a->e1246 * b->e37 + a->e1236 * b->e47 
                       + a->e1234 * b->e67;
          res->e123567 = c->e123567 + a->e3567 * b->e12 + a->e2567 * b->e13 
                       + a->e1567 * b->e23 + a->e2367 * b->e15 + a->e1367 * b->e25 
                       + a->e1267 * b->e35 + a->e2357 * b->e16 + a->e1357 * b->e26 
                       + a->e1257 * b->e36 + a->e1237 * b->e56 + a->e2356 * b->e17 
                       + a->e1356 * b->e27 + a->e1256 * b->e37 + a->e1236 * b->e57 
                       + a->e1235 * b->e67;
          res->e124567 = c->e124567 + a->e4567 * b->e12 + a->e2567 * b->e14 
                       + a->e1567 * b->e24 + a->e2467 * b->e15 + a->e1467 * b->e25 
                       + a->e1267 * b->e45 + a->e2457 * b->e16 + a->e1457 * b->e26 
                       + a->e1257 * b->e46 + a->e1247 * b->e56 + a->e2456 * b->e17 
                       + a->e1456 * b->e27 + a->e1256 * b->e47 + a->e1246 * b->e57 
                       + a->e1245 * b->e67;
          res->e134567 = c->e134567 + a->e4567 * b->e13 + a->e3567 * b->e14 
                       + a->e1567 * b->e34 + a->e3467 * b->e15 + a->e1467 * b->e35 
                       + a->e1367 * b->e45 + a->e3457 * b->e16 + a->e1457 * b->e36 
                       + a->e1357 * b->e46 + a->e1347 * b->e56 + a->e3456 * b->e17 
                       + a->e1456 * b->e37 + a->e1356 * b->e47 + a->e1346 * b->e57 
                       + a->e1345 * b->e67;
          res->e234567 = c->e234567 + a->e4567 * b->e23 + a->e3567 * b->e24 
                       + a->e2567 * b->e34 + a->e3467 * b->e25 + a->e2467 * b->e35 
                       + a->e2367 * b->e45 + a->e3457 * b->e26 + a->e2457 * b->e36 
                       + a->e2357 * b->e46 + a->e2347 * b->e56 + a->e3456 * b->e27 
                       + a->e2456 * b->e37 + a->e2356 * b->e47 + a->e2346 * b->e57 
                       + a->e2345 * b->e67;
          break;
        case 3:
          // res order: 7
          res->e1234567 = c->e1234567 + a->e4567 * b->e123 + a->e3567 * b->e124 
                        + a->e2567 * b->e134 + a->e1567 * b->e234 + a->e3467 * b->e125 
                        + a->e2467 * b->e135 + a->e1467 * b->e235 + a->e2367 * b->e145 
                        + a->e1367 * b->e245 + a->e1267 * b->e345 + a->e3457 * b->e126 
                        + a->e2457 * b->e136 + a->e1457 * b->e236 + a->e2357 * b->e146 
                        + a->e1357 * b->e246 + a->e1257 * b->e346 + a->e2347 * b->e156 
                        + a->e1347 * b->e256 + a->e1247 * b->e356 + a->e1237 * b->e456 
                        + a->e3456 * b->e127 + a->e2456 * b->e137 + a->e1456 * b->e237 
                        + a->e2356 * b->e147 + a->e1356 * b->e247 + a->e1256 * b->e347 
                        + a->e2346 * b->e157 + a->e1346 * b->e257 + a->e1246 * b->e357 
                        + a->e1236 * b->e457 + a->e2345 * b->e167 + a->e1345 * b->e267 
                        + a->e1245 * b->e367 + a->e1235 * b->e467 + a->e1234 * b->e567;
          break;
      }
      break;
    case 5:
      switch( ord_rhs ){
        case 0:
          // res order: 5
          res->e12345 = c->e12345 + a->e12345 * b->r;
          res->e12346 = c->e12346 + a->e12346 * b->r;
          res->e12356 = c->e12356 + a->e12356 * b->r;
          res->e12456 = c->e12456 + a->e12456 * b->r;
          res->e13456 = c->e13456 + a->e13456 * b->r;
          res->e23456 = c->e23456 + a->e23456 * b->r;
          res->e12347 = c->e12347 + a->e12347 * b->r;
          res->e12357 = c->e12357 + a->e12357 * b->r;
          res->e12457 = c->e12457 + a->e12457 * b->r;
          res->e13457 = c->e13457 + a->e13457 * b->r;
          res->e23457 = c->e23457 + a->e23457 * b->r;
          res->e12367 = c->e12367 + a->e12367 * b->r;
          res->e12467 = c->e12467 + a->e12467 * b->r;
          res->e13467 = c->e13467 + a->e13467 * b->r;
          res->e23467 = c->e23467 + a->e23467 * b->r;
          res->e12567 = c->e12567 + a->e12567 * b->r;
          res->e13567 = c->e13567 + a->e13567 * b->r;
          res->e23567 = c->e23567 + a->e23567 * b->r;
          res->e14567 = c->e14567 + a->e14567 * b->r;
          res->e24567 = c->e24567 + a->e24567 * b->r;
          res->e34567 = c->e34567 + a->e34567 * b->r;
          break;
        case 1:
          // res order: 6
          res->e123456 = c->e123456 + a->e23456 * b->e1 + a->e13456 * b->e2 
                       + a->e12456 * b->e3 + a->e12356 * b->e4 + a->e12346 * b->e5 
                       + a->e12345 * b->e6;
          res->e123457 = c->e123457 + a->e23457 * b->e1 + a->e13457 * b->e2 
                       + a->e12457 * b->e3 + a->e12357 * b->e4 + a->e12347 * b->e5 
                       + a->e12345 * b->e7;
          res->e123467 = c->e123467 + a->e23467 * b->e1 + a->e13467 * b->e2 
                       + a->e12467 * b->e3 + a->e12367 * b->e4 + a->e12347 * b->e6 
                       + a->e12346 * b->e7;
          res->e123567 = c->e123567 + a->e23567 * b->e1 + a->e13567 * b->e2 
                       + a->e12567 * b->e3 + a->e12367 * b->e5 + a->e12357 * b->e6 
                       + a->e12356 * b->e7;
          res->e124567 = c->e124567 + a->e24567 * b->e1 + a->e14567 * b->e2 
                       + a->e12567 * b->e4 + a->e12467 * b->e5 + a->e12457 * b->e6 
                       + a->e12456 * b->e7;
          res->e134567 = c->e134567 + a->e34567 * b->e1 + a->e14567 * b->e3 
                       + a->e13567 * b->e4 + a->e13467 * b->e5 + a->e13457 * b->e6 
                       + a->e13456 * b->e7;
          res->e234567 = c->e234567 + a->e34567 * b->e2 + a->e24567 * b->e3 
                       + a->e23567 * b->e4 + a->e23467 * b->e5 + a->e23457 * b->e6 
                       + a->e23456 * b->e7;
          break;
        case 2:
          // res order: 7
          res->e1234567 = c->e1234567 + a->e34567 * b->e12 + a->e24567 * b->e13 
                        + a->e14567 * b->e23 + a->e23567 * b->e14 + a->e13567 * b->e24 
                        + a->e12567 * b->e34 + a->e23467 * b->e15 + a->e13467 * b->e25 
                        + a->e12467 * b->e35 + a->e12367 * b->e45 + a->e23457 * b->e16 
                        + a->e13457 * b->e26 + a->e12457 * b->e36 + a->e12357 * b->e46 
                        + a->e12347 * b->e56 + a->e23456 * b->e17 + a->e13456 * b->e27 
                        + a->e12456 * b->e37 + a->e12356 * b->e47 + a->e12346 * b->e57 
                        + a->e12345 * b->e67;
          break;
      }
      break;
    case 6:
      switch( ord_rhs ){
        case 0:
          // res order: 6
          res->e123456 = c->e123456 + a->e123456 * b->r;
          res->e123457 = c->e123457 + a->e123457 * b->r;
          res->e123467 = c->e123467 + a->e123467 * b->r;
          res->e123567 = c->e123567 + a->e123567 * b->r;
          res->e124567 = c->e124567 + a->e124567 * b->r;
          res->e134567 = c->e134567 + a->e134567 * b->r;
          res->e234567 = c->e234567 + a->e234567 * b->r;
          break;
        case 1:
          // res order: 7
          res->e1234567 = c->e1234567 + a->e234567 * b->e1 + a->e134567 * b->e2 
                        + a->e124567 * b->e3 + a->e123567 * b->e4 + a->e123467 * b->e5 
                        + a->e123457 * b->e6 + a->e123456 * b->e7;
          break;
      }
      break;
    case 7:
      switch( ord_rhs ){
        case 0:
          // res order: 7
          res->e1234567 = c->e1234567 + a->e1234567 * b->r;
          break;
      }
      break;
  }

}

mdnum7_t mdnum7_feval(coeff_t* feval_re, mdnum7_t* x){

  mdnum7_t res;

  // feval function
  //  Definitions
  coeff_t factor=1, coef = 0;
  mdnum7_t deltax = (*x), deltax_power = (*x);
  deltax.r = 0.0;
  deltax_power.r = 0.0;
  mdnum7_set_r(0.0, &res);
  //  Real
  res.r = feval_re[0];
  // Order 1
  factor *=1;
  coef    = feval_re[1]/ factor;;
  mdnum7_gem_ro_to( coef, &deltax_power, &res, &res);
  deltax_power = mdnum7_mul_oo(&deltax_power,&deltax);
  // Order 2
  factor *=2;
  coef    = feval_re[2]/ factor;;
  mdnum7_gem_ro_to( coef, &deltax_power, &res, &res);
  deltax_power = mdnum7_mul_oo(&deltax_power,&deltax);
  // Order 3
  factor *=3;
  coef    = feval_re[3]/ factor;;
  mdnum7_gem_ro_to( coef, &deltax_power, &res, &res);
  deltax_power = mdnum7_mul_oo(&deltax_power,&deltax);
  // Order 4
  factor *=4;
  coef    = feval_re[4]/ factor;;
  mdnum7_gem_ro_to( coef, &deltax_power, &res, &res);
  deltax_power = mdnum7_mul_oo(&deltax_power,&deltax);
  // Order 5
  factor *=5;
  coef    = feval_re[5]/ factor;;
  mdnum7_gem_ro_to( coef, &deltax_power, &res, &res);
  deltax_power = mdnum7_mul_oo(&deltax_power,&deltax);
  // Order 6
  factor *=6;
  coef    = feval_re[6]/ factor;;
  mdnum7_gem_ro_to( coef, &deltax_power, &res, &res);
  deltax_power = mdnum7_mul_oo(&deltax_power,&deltax);
  // Order 7
  factor *=7;
  coef    = feval_re[7]/ factor;;
  mdnum7_gem_ro_to( coef, &deltax_power, &res, &res);

  return res;

}

void mdnum7_feval_to(coeff_t* feval_re, mdnum7_t* x, mdnum7_t* res){

  // feval function
  //  Definitions
  coeff_t factor=1, coef = 0;
  mdnum7_t deltax = (*x), deltax_power = (*x);
  deltax.r = 0.0;
  deltax_power.r = 0.0;
  mdnum7_set_r(0.0, res);
  //  Real
  res->r = feval_re[0];
  // Order 1
  factor *=1;
  coef    = feval_re[1]/ factor;;
  mdnum7_gem_ro_to( coef, &deltax_power, res, res);
  deltax_power = mdnum7_mul_oo(&deltax_power,&deltax);
  // Order 2
  factor *=2;
  coef    = feval_re[2]/ factor;;
  mdnum7_gem_ro_to( coef, &deltax_power, res, res);
  deltax_power = mdnum7_mul_oo(&deltax_power,&deltax);
  // Order 3
  factor *=3;
  coef    = feval_re[3]/ factor;;
  mdnum7_gem_ro_to( coef, &deltax_power, res, res);
  deltax_power = mdnum7_mul_oo(&deltax_power,&deltax);
  // Order 4
  factor *=4;
  coef    = feval_re[4]/ factor;;
  mdnum7_gem_ro_to( coef, &deltax_power, res, res);
  deltax_power = mdnum7_mul_oo(&deltax_power,&deltax);
  // Order 5
  factor *=5;
  coef    = feval_re[5]/ factor;;
  mdnum7_gem_ro_to( coef, &deltax_power, res, res);
  deltax_power = mdnum7_mul_oo(&deltax_power,&deltax);
  // Order 6
  factor *=6;
  coef    = feval_re[6]/ factor;;
  mdnum7_gem_ro_to( coef, &deltax_power, res, res);
  deltax_power = mdnum7_mul_oo(&deltax_power,&deltax);
  // Order 7
  factor *=7;
  coef    = feval_re[7]/ factor;;
  mdnum7_gem_ro_to( coef, &deltax_power, res, res);

}

