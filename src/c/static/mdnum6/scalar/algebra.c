
// Division.

// ****************************************************************************************************
mdnum6_t mdnum6_div_ro(coeff_t num, mdnum6_t* den){

    
    mdnum6_t inv = mdnum6_pow(den,-1);
    mdnum6_t res = mdnum6_mul_ro(num,&inv);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdnum6_t mdnum6_div_oo(mdnum6_t* num, mdnum6_t* den){

    
    mdnum6_t inv = mdnum6_init();
    mdnum6_pow_to(den,-1,&inv);
    mdnum6_t res = mdnum6_mul_oo(num,&inv);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdnum6_t mdnum6_div_or(mdnum6_t* num, coeff_t val){

    return mdnum6_mul_ro(1.0/val,num);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdnum6_t mdnum6_abs(mdnum6_t* num){

	mdnum6_t res;
    mdnum6_abs_to(num,&res);
    return res;

}
// ----------------------------------------------------------------------------------------------------

mdnum6_t mdnum6_neg(  mdnum6_t* lhs){

  mdnum6_t res;

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
  // Order 5;
  res.e12345 = -lhs->e12345;
  res.e12346 = -lhs->e12346;
  res.e12356 = -lhs->e12356;
  res.e12456 = -lhs->e12456;
  res.e13456 = -lhs->e13456;
  res.e23456 = -lhs->e23456;
  // Order 6;
  res.e123456 = -lhs->e123456;

  return res;

}

void mdnum6_neg_to(  mdnum6_t* lhs, mdnum6_t* res){

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
  // Order 5;
  res->e12345 = -lhs->e12345;
  res->e12346 = -lhs->e12346;
  res->e12356 = -lhs->e12356;
  res->e12456 = -lhs->e12456;
  res->e13456 = -lhs->e13456;
  res->e23456 = -lhs->e23456;
  // Order 6;
  res->e123456 = -lhs->e123456;

}

mdnum6_t mdnum6_sum_oo(  mdnum6_t* lhs,  mdnum6_t* rhs){
  mdnum6_t res;

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
  // Order 5
  res.e12345 = lhs->e12345 + rhs->e12345;
  res.e12346 = lhs->e12346 + rhs->e12346;
  res.e12356 = lhs->e12356 + rhs->e12356;
  res.e12456 = lhs->e12456 + rhs->e12456;
  res.e13456 = lhs->e13456 + rhs->e13456;
  res.e23456 = lhs->e23456 + rhs->e23456;
  // Order 6
  res.e123456 = lhs->e123456 + rhs->e123456;

  return res;

}

void mdnum6_sum_oo_to(  mdnum6_t* lhs,  mdnum6_t* rhs, mdnum6_t* res){
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
  // Order 5
  res->e12345 = lhs->e12345 + rhs->e12345;
  res->e12346 = lhs->e12346 + rhs->e12346;
  res->e12356 = lhs->e12356 + rhs->e12356;
  res->e12456 = lhs->e12456 + rhs->e12456;
  res->e13456 = lhs->e13456 + rhs->e13456;
  res->e23456 = lhs->e23456 + rhs->e23456;
  // Order 6
  res->e123456 = lhs->e123456 + rhs->e123456;

}

mdnum6_t mdnum6_sum_ro(  coeff_t lhs,  mdnum6_t* rhs){
  mdnum6_t res;

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
  // Order 5;
  res.e12345 =  + rhs->e12345;
  res.e12346 =  + rhs->e12346;
  res.e12356 =  + rhs->e12356;
  res.e12456 =  + rhs->e12456;
  res.e13456 =  + rhs->e13456;
  res.e23456 =  + rhs->e23456;
  // Order 6;
  res.e123456 =  + rhs->e123456;

  return res;

}

void mdnum6_sum_ro_to(  coeff_t lhs,  mdnum6_t* rhs, mdnum6_t* res){
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
  // Order 5;
  res->e12345 =  + rhs->e12345;
  res->e12346 =  + rhs->e12346;
  res->e12356 =  + rhs->e12356;
  res->e12456 =  + rhs->e12456;
  res->e13456 =  + rhs->e13456;
  res->e23456 =  + rhs->e23456;
  // Order 6;
  res->e123456 =  + rhs->e123456;

}

mdnum6_t mdnum6_sub_oo(  mdnum6_t* lhs,  mdnum6_t* rhs){
  mdnum6_t res;

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
  // Order 5
  res.e12345 = lhs->e12345 - rhs->e12345;
  res.e12346 = lhs->e12346 - rhs->e12346;
  res.e12356 = lhs->e12356 - rhs->e12356;
  res.e12456 = lhs->e12456 - rhs->e12456;
  res.e13456 = lhs->e13456 - rhs->e13456;
  res.e23456 = lhs->e23456 - rhs->e23456;
  // Order 6
  res.e123456 = lhs->e123456 - rhs->e123456;

  return res;

}

void mdnum6_sub_oo_to(  mdnum6_t* lhs,  mdnum6_t* rhs, mdnum6_t* res){
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
  // Order 5
  res->e12345 = lhs->e12345 - rhs->e12345;
  res->e12346 = lhs->e12346 - rhs->e12346;
  res->e12356 = lhs->e12356 - rhs->e12356;
  res->e12456 = lhs->e12456 - rhs->e12456;
  res->e13456 = lhs->e13456 - rhs->e13456;
  res->e23456 = lhs->e23456 - rhs->e23456;
  // Order 6
  res->e123456 = lhs->e123456 - rhs->e123456;

}

mdnum6_t mdnum6_sub_ro(  coeff_t lhs,  mdnum6_t* rhs){
  mdnum6_t res;

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
  // Order 5;
  res.e12345 =  - rhs->e12345;
  res.e12346 =  - rhs->e12346;
  res.e12356 =  - rhs->e12356;
  res.e12456 =  - rhs->e12456;
  res.e13456 =  - rhs->e13456;
  res.e23456 =  - rhs->e23456;
  // Order 6;
  res.e123456 =  - rhs->e123456;

  return res;

}

void mdnum6_sub_ro_to(  coeff_t lhs,  mdnum6_t* rhs, mdnum6_t* res){
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
  // Order 5;
  res->e12345 =  - rhs->e12345;
  res->e12346 =  - rhs->e12346;
  res->e12356 =  - rhs->e12356;
  res->e12456 =  - rhs->e12456;
  res->e13456 =  - rhs->e13456;
  res->e23456 =  - rhs->e23456;
  // Order 6;
  res->e123456 =  - rhs->e123456;

}

mdnum6_t mdnum6_sub_or(  mdnum6_t* lhs,  coeff_t rhs){
  mdnum6_t res;

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
  // Order 5;
  res.e12345 = lhs->e12345;
  res.e12346 = lhs->e12346;
  res.e12356 = lhs->e12356;
  res.e12456 = lhs->e12456;
  res.e13456 = lhs->e13456;
  res.e23456 = lhs->e23456;
  // Order 6;
  res.e123456 = lhs->e123456;

  return res;

}

void mdnum6_sub_or_to(  mdnum6_t* lhs,  coeff_t rhs, mdnum6_t* res){
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
  // Order 5;
  res->e12345 = lhs->e12345;
  res->e12346 = lhs->e12346;
  res->e12356 = lhs->e12356;
  res->e12456 = lhs->e12456;
  res->e13456 = lhs->e13456;
  res->e23456 = lhs->e23456;
  // Order 6;
  res->e123456 = lhs->e123456;

}

mdnum6_t mdnum6_mul_oo(  mdnum6_t* lhs,  mdnum6_t* rhs){
  mdnum6_t res;

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

  return res;

}

void mdnum6_mul_oo_to(  mdnum6_t* lhs,  mdnum6_t* rhs, mdnum6_t* res){
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

}

mdnum6_t mdnum6_mul_ro(  coeff_t lhs,  mdnum6_t* rhs){
  mdnum6_t res;

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
  // Order 5;
  res.e12345 = lhs * rhs->e12345;
  res.e12346 = lhs * rhs->e12346;
  res.e12356 = lhs * rhs->e12356;
  res.e12456 = lhs * rhs->e12456;
  res.e13456 = lhs * rhs->e13456;
  res.e23456 = lhs * rhs->e23456;
  // Order 6;
  res.e123456 = lhs * rhs->e123456;

  return res;

}

void mdnum6_mul_ro_to(  coeff_t lhs,  mdnum6_t* rhs, mdnum6_t* res){
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
  // Order 5;
  res->e12345 = lhs * rhs->e12345;
  res->e12346 = lhs * rhs->e12346;
  res->e12356 = lhs * rhs->e12356;
  res->e12456 = lhs * rhs->e12456;
  res->e13456 = lhs * rhs->e13456;
  res->e23456 = lhs * rhs->e23456;
  // Order 6;
  res->e123456 = lhs * rhs->e123456;

}

mdnum6_t mdnum6_trunc_mul_oo(  mdnum6_t* lhs,  mdnum6_t* rhs){
  mdnum6_t res;

  res = mdnum6_init();

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

  return res;

}

void mdnum6_trunc_mul_oo_to(  mdnum6_t* lhs,  mdnum6_t* rhs, mdnum6_t* res){
   (*res) = mdnum6_init();

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

}

mdnum6_t mdnum6_gem_oo(  mdnum6_t* a,  mdnum6_t* b,  mdnum6_t* c){
  mdnum6_t res;

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

  return res;

}

void mdnum6_gem_oo_to(  mdnum6_t* a,  mdnum6_t* b,  mdnum6_t* c, mdnum6_t* res){
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

}

mdnum6_t mdnum6_gem_ro(  coeff_t a,  mdnum6_t* b,  mdnum6_t* c){
  mdnum6_t res;

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
  // Order 5;
  res.e12345 = c->e12345 + a * b->e12345;
  res.e12346 = c->e12346 + a * b->e12346;
  res.e12356 = c->e12356 + a * b->e12356;
  res.e12456 = c->e12456 + a * b->e12456;
  res.e13456 = c->e13456 + a * b->e13456;
  res.e23456 = c->e23456 + a * b->e23456;
  // Order 6;
  res.e123456 = c->e123456 + a * b->e123456;

  return res;

}

void mdnum6_gem_ro_to(  coeff_t a,  mdnum6_t* b,  mdnum6_t* c, mdnum6_t* res){
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
  // Order 5;
  res->e12345 = c->e12345 + a * b->e12345;
  res->e12346 = c->e12346 + a * b->e12346;
  res->e12356 = c->e12356 + a * b->e12356;
  res->e12456 = c->e12456 + a * b->e12456;
  res->e13456 = c->e13456 + a * b->e13456;
  res->e23456 = c->e23456 + a * b->e23456;
  // Order 6;
  res->e123456 = c->e123456 + a * b->e123456;

}

void mdnum6_trunc_gem_oo_to( ord_t ord_lhs,  mdnum6_t* a,  ord_t ord_rhs,  mdnum6_t* b,  mdnum6_t* c, mdnum6_t* res){
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
          break;
        case 5:
          // res order: 5
          res->e12345 = c->e12345 + a->r * b->e12345;
          res->e12346 = c->e12346 + a->r * b->e12346;
          res->e12356 = c->e12356 + a->r * b->e12356;
          res->e12456 = c->e12456 + a->r * b->e12456;
          res->e13456 = c->e13456 + a->r * b->e13456;
          res->e23456 = c->e23456 + a->r * b->e23456;
          break;
        case 6:
          // res order: 6
          res->e123456 = c->e123456 + a->r * b->e123456;
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
          break;
        case 5:
          // res order: 6
          res->e123456 = c->e123456 + a->e1 * b->e23456 + a->e2 * b->e13456 
                       + a->e3 * b->e12456 + a->e4 * b->e12356 + a->e5 * b->e12346 
                       + a->e6 * b->e12345;
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
          break;
        case 4:
          // res order: 6
          res->e123456 = c->e123456 + a->e12 * b->e3456 + a->e13 * b->e2456 
                       + a->e23 * b->e1456 + a->e14 * b->e2356 + a->e24 * b->e1356 
                       + a->e34 * b->e1256 + a->e15 * b->e2346 + a->e25 * b->e1346 
                       + a->e35 * b->e1246 + a->e45 * b->e1236 + a->e16 * b->e2345 
                       + a->e26 * b->e1345 + a->e36 * b->e1245 + a->e46 * b->e1235 
                       + a->e56 * b->e1234;
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
          break;
        case 2:
          // res order: 6
          res->e123456 = c->e123456 + a->e3456 * b->e12 + a->e2456 * b->e13 
                       + a->e1456 * b->e23 + a->e2356 * b->e14 + a->e1356 * b->e24 
                       + a->e1256 * b->e34 + a->e2346 * b->e15 + a->e1346 * b->e25 
                       + a->e1246 * b->e35 + a->e1236 * b->e45 + a->e2345 * b->e16 
                       + a->e1345 * b->e26 + a->e1245 * b->e36 + a->e1235 * b->e46 
                       + a->e1234 * b->e56;
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
          break;
        case 1:
          // res order: 6
          res->e123456 = c->e123456 + a->e23456 * b->e1 + a->e13456 * b->e2 
                       + a->e12456 * b->e3 + a->e12356 * b->e4 + a->e12346 * b->e5 
                       + a->e12345 * b->e6;
          break;
      }
      break;
    case 6:
      switch( ord_rhs ){
        case 0:
          // res order: 6
          res->e123456 = c->e123456 + a->e123456 * b->r;
          break;
      }
      break;
  }

}

void mdnum6_trunc_sum_oo_to(ord_t order, mdnum6_t* lhs,mdnum6_t* rhs, mdnum6_t* res){
  // Addition like function 'lhs + rhs'
  switch(order){
    case(0):
      //  Real
      res->r = lhs->r + rhs->r;
      break;
    case(1):    // Order 1
      res->e1 = lhs->e1 + rhs->e1;
      res->e2 = lhs->e2 + rhs->e2;
      res->e3 = lhs->e3 + rhs->e3;
      res->e4 = lhs->e4 + rhs->e4;
      res->e5 = lhs->e5 + rhs->e5;
      res->e6 = lhs->e6 + rhs->e6;
      break;
    case(2):    // Order 2
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
      break;
    case(3):    // Order 3
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
      break;
    case(4):    // Order 4
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
      break;
    case(5):    // Order 5
      res->e12345 = lhs->e12345 + rhs->e12345;
      res->e12346 = lhs->e12346 + rhs->e12346;
      res->e12356 = lhs->e12356 + rhs->e12356;
      res->e12456 = lhs->e12456 + rhs->e12456;
      res->e13456 = lhs->e13456 + rhs->e13456;
      res->e23456 = lhs->e23456 + rhs->e23456;
      break;
    case(6):    // Order 6
      res->e123456 = lhs->e123456 + rhs->e123456;
      break;
  }
}

void mdnum6_trunc_sub_oo_to(ord_t order, mdnum6_t* lhs,mdnum6_t* rhs, mdnum6_t* res){
  // Addition like function 'lhs - rhs'
  switch(order){
    case(0):
      //  Real
      res->r = lhs->r - rhs->r;
      break;
    case(1):    // Order 1
      res->e1 = lhs->e1 - rhs->e1;
      res->e2 = lhs->e2 - rhs->e2;
      res->e3 = lhs->e3 - rhs->e3;
      res->e4 = lhs->e4 - rhs->e4;
      res->e5 = lhs->e5 - rhs->e5;
      res->e6 = lhs->e6 - rhs->e6;
      break;
    case(2):    // Order 2
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
      break;
    case(3):    // Order 3
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
      break;
    case(4):    // Order 4
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
      break;
    case(5):    // Order 5
      res->e12345 = lhs->e12345 - rhs->e12345;
      res->e12346 = lhs->e12346 - rhs->e12346;
      res->e12356 = lhs->e12356 - rhs->e12356;
      res->e12456 = lhs->e12456 - rhs->e12456;
      res->e13456 = lhs->e13456 - rhs->e13456;
      res->e23456 = lhs->e23456 - rhs->e23456;
      break;
    case(6):    // Order 6
      res->e123456 = lhs->e123456 - rhs->e123456;
      break;
  }
}

mdnum6_t mdnum6_feval(coeff_t* feval_re, mdnum6_t* x){

  mdnum6_t res;

  // feval function
  //  Definitions
  coeff_t factor=1, coef = 0;
  mdnum6_t deltax = (*x), deltax_power = (*x);
  deltax.r = 0.0;
  deltax_power.r = 0.0;
  mdnum6_set_r(0.0, &res);
  //  Real
  res.r = feval_re[0];
  // Order 1
  factor *=1;
  coef    = feval_re[1]/ factor;;
  mdnum6_gem_ro_to( coef, &deltax_power, &res, &res);
  deltax_power = mdnum6_mul_oo(&deltax_power,&deltax);
  // Order 2
  factor *=2;
  coef    = feval_re[2]/ factor;;
  mdnum6_gem_ro_to( coef, &deltax_power, &res, &res);
  deltax_power = mdnum6_mul_oo(&deltax_power,&deltax);
  // Order 3
  factor *=3;
  coef    = feval_re[3]/ factor;;
  mdnum6_gem_ro_to( coef, &deltax_power, &res, &res);
  deltax_power = mdnum6_mul_oo(&deltax_power,&deltax);
  // Order 4
  factor *=4;
  coef    = feval_re[4]/ factor;;
  mdnum6_gem_ro_to( coef, &deltax_power, &res, &res);
  deltax_power = mdnum6_mul_oo(&deltax_power,&deltax);
  // Order 5
  factor *=5;
  coef    = feval_re[5]/ factor;;
  mdnum6_gem_ro_to( coef, &deltax_power, &res, &res);
  deltax_power = mdnum6_mul_oo(&deltax_power,&deltax);
  // Order 6
  factor *=6;
  coef    = feval_re[6]/ factor;;
  mdnum6_gem_ro_to( coef, &deltax_power, &res, &res);

  return res;

}

void mdnum6_feval_to(coeff_t* feval_re, mdnum6_t* x, mdnum6_t* res){

  // feval function
  //  Definitions
  coeff_t factor=1, coef = 0;
  mdnum6_t deltax = (*x), deltax_power = (*x);
  deltax.r = 0.0;
  deltax_power.r = 0.0;
  mdnum6_set_r(0.0, res);
  //  Real
  res->r = feval_re[0];
  // Order 1
  factor *=1;
  coef    = feval_re[1]/ factor;;
  mdnum6_gem_ro_to( coef, &deltax_power, res, res);
  deltax_power = mdnum6_mul_oo(&deltax_power,&deltax);
  // Order 2
  factor *=2;
  coef    = feval_re[2]/ factor;;
  mdnum6_gem_ro_to( coef, &deltax_power, res, res);
  deltax_power = mdnum6_mul_oo(&deltax_power,&deltax);
  // Order 3
  factor *=3;
  coef    = feval_re[3]/ factor;;
  mdnum6_gem_ro_to( coef, &deltax_power, res, res);
  deltax_power = mdnum6_mul_oo(&deltax_power,&deltax);
  // Order 4
  factor *=4;
  coef    = feval_re[4]/ factor;;
  mdnum6_gem_ro_to( coef, &deltax_power, res, res);
  deltax_power = mdnum6_mul_oo(&deltax_power,&deltax);
  // Order 5
  factor *=5;
  coef    = feval_re[5]/ factor;;
  mdnum6_gem_ro_to( coef, &deltax_power, res, res);
  deltax_power = mdnum6_mul_oo(&deltax_power,&deltax);
  // Order 6
  factor *=6;
  coef    = feval_re[6]/ factor;;
  mdnum6_gem_ro_to( coef, &deltax_power, res, res);

}

