
// Division.

// ****************************************************************************************************
mdnum5_t mdnum5_div_ro(coeff_t num, mdnum5_t* den){

    
    mdnum5_t inv = mdnum5_pow(den,-1);
    mdnum5_t res = mdnum5_mul_ro(num,&inv);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdnum5_t mdnum5_div_oo(mdnum5_t* num, mdnum5_t* den){

    
    mdnum5_t inv = mdnum5_init();
    mdnum5_pow_to(den,-1,&inv);
    mdnum5_t res = mdnum5_mul_oo(num,&inv);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdnum5_t mdnum5_div_or(mdnum5_t* num, coeff_t val){

    return mdnum5_mul_ro(1.0/val,num);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdnum5_t mdnum5_abs(mdnum5_t* num){

	mdnum5_t res;
    mdnum5_abs_to(num,&res);
    return res;

}
// ----------------------------------------------------------------------------------------------------

mdnum5_t mdnum5_neg(  mdnum5_t* lhs){

  mdnum5_t res;

  // Negation like function '-lhs'
  // Real;
  res.r = -lhs->r;
  // Order 1;
  res.e1 = -lhs->e1;
  res.e2 = -lhs->e2;
  res.e3 = -lhs->e3;
  res.e4 = -lhs->e4;
  res.e5 = -lhs->e5;
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
  // Order 4;
  res.e1234 = -lhs->e1234;
  res.e1235 = -lhs->e1235;
  res.e1245 = -lhs->e1245;
  res.e1345 = -lhs->e1345;
  res.e2345 = -lhs->e2345;
  // Order 5;
  res.e12345 = -lhs->e12345;

  return res;

}

void mdnum5_neg_to(  mdnum5_t* lhs, mdnum5_t* res){

  // Negation like function '-lhs'
  // Real;
  res->r = -lhs->r;
  // Order 1;
  res->e1 = -lhs->e1;
  res->e2 = -lhs->e2;
  res->e3 = -lhs->e3;
  res->e4 = -lhs->e4;
  res->e5 = -lhs->e5;
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
  // Order 4;
  res->e1234 = -lhs->e1234;
  res->e1235 = -lhs->e1235;
  res->e1245 = -lhs->e1245;
  res->e1345 = -lhs->e1345;
  res->e2345 = -lhs->e2345;
  // Order 5;
  res->e12345 = -lhs->e12345;

}

mdnum5_t mdnum5_sum_oo(  mdnum5_t* lhs,  mdnum5_t* rhs){
  mdnum5_t res;

  // Addition like function 'lhs + rhs'
  //  Real
  res.r = lhs->r + rhs->r;
  // Order 1
  res.e1 = lhs->e1 + rhs->e1;
  res.e2 = lhs->e2 + rhs->e2;
  res.e3 = lhs->e3 + rhs->e3;
  res.e4 = lhs->e4 + rhs->e4;
  res.e5 = lhs->e5 + rhs->e5;
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
  // Order 4
  res.e1234 = lhs->e1234 + rhs->e1234;
  res.e1235 = lhs->e1235 + rhs->e1235;
  res.e1245 = lhs->e1245 + rhs->e1245;
  res.e1345 = lhs->e1345 + rhs->e1345;
  res.e2345 = lhs->e2345 + rhs->e2345;
  // Order 5
  res.e12345 = lhs->e12345 + rhs->e12345;

  return res;

}

void mdnum5_sum_oo_to(  mdnum5_t* lhs,  mdnum5_t* rhs, mdnum5_t* res){
  // Addition like function 'lhs + rhs'
  //  Real
  res->r = lhs->r + rhs->r;
  // Order 1
  res->e1 = lhs->e1 + rhs->e1;
  res->e2 = lhs->e2 + rhs->e2;
  res->e3 = lhs->e3 + rhs->e3;
  res->e4 = lhs->e4 + rhs->e4;
  res->e5 = lhs->e5 + rhs->e5;
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
  // Order 4
  res->e1234 = lhs->e1234 + rhs->e1234;
  res->e1235 = lhs->e1235 + rhs->e1235;
  res->e1245 = lhs->e1245 + rhs->e1245;
  res->e1345 = lhs->e1345 + rhs->e1345;
  res->e2345 = lhs->e2345 + rhs->e2345;
  // Order 5
  res->e12345 = lhs->e12345 + rhs->e12345;

}

mdnum5_t mdnum5_sum_ro(  coeff_t lhs,  mdnum5_t* rhs){
  mdnum5_t res;

  // Addition like function 'lhs + rhs'
  // Real;
  res.r = lhs + rhs->r;
  // Order 1;
  res.e1 =  + rhs->e1;
  res.e2 =  + rhs->e2;
  res.e3 =  + rhs->e3;
  res.e4 =  + rhs->e4;
  res.e5 =  + rhs->e5;
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
  // Order 4;
  res.e1234 =  + rhs->e1234;
  res.e1235 =  + rhs->e1235;
  res.e1245 =  + rhs->e1245;
  res.e1345 =  + rhs->e1345;
  res.e2345 =  + rhs->e2345;
  // Order 5;
  res.e12345 =  + rhs->e12345;

  return res;

}

void mdnum5_sum_ro_to(  coeff_t lhs,  mdnum5_t* rhs, mdnum5_t* res){
  // Addition like function 'lhs + rhs'
  // Real;
  res->r = lhs + rhs->r;
  // Order 1;
  res->e1 =  + rhs->e1;
  res->e2 =  + rhs->e2;
  res->e3 =  + rhs->e3;
  res->e4 =  + rhs->e4;
  res->e5 =  + rhs->e5;
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
  // Order 4;
  res->e1234 =  + rhs->e1234;
  res->e1235 =  + rhs->e1235;
  res->e1245 =  + rhs->e1245;
  res->e1345 =  + rhs->e1345;
  res->e2345 =  + rhs->e2345;
  // Order 5;
  res->e12345 =  + rhs->e12345;

}

mdnum5_t mdnum5_sub_oo(  mdnum5_t* lhs,  mdnum5_t* rhs){
  mdnum5_t res;

  // Addition like function 'lhs - rhs'
  //  Real
  res.r = lhs->r - rhs->r;
  // Order 1
  res.e1 = lhs->e1 - rhs->e1;
  res.e2 = lhs->e2 - rhs->e2;
  res.e3 = lhs->e3 - rhs->e3;
  res.e4 = lhs->e4 - rhs->e4;
  res.e5 = lhs->e5 - rhs->e5;
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
  // Order 4
  res.e1234 = lhs->e1234 - rhs->e1234;
  res.e1235 = lhs->e1235 - rhs->e1235;
  res.e1245 = lhs->e1245 - rhs->e1245;
  res.e1345 = lhs->e1345 - rhs->e1345;
  res.e2345 = lhs->e2345 - rhs->e2345;
  // Order 5
  res.e12345 = lhs->e12345 - rhs->e12345;

  return res;

}

void mdnum5_sub_oo_to(  mdnum5_t* lhs,  mdnum5_t* rhs, mdnum5_t* res){
  // Addition like function 'lhs - rhs'
  //  Real
  res->r = lhs->r - rhs->r;
  // Order 1
  res->e1 = lhs->e1 - rhs->e1;
  res->e2 = lhs->e2 - rhs->e2;
  res->e3 = lhs->e3 - rhs->e3;
  res->e4 = lhs->e4 - rhs->e4;
  res->e5 = lhs->e5 - rhs->e5;
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
  // Order 4
  res->e1234 = lhs->e1234 - rhs->e1234;
  res->e1235 = lhs->e1235 - rhs->e1235;
  res->e1245 = lhs->e1245 - rhs->e1245;
  res->e1345 = lhs->e1345 - rhs->e1345;
  res->e2345 = lhs->e2345 - rhs->e2345;
  // Order 5
  res->e12345 = lhs->e12345 - rhs->e12345;

}

mdnum5_t mdnum5_sub_ro(  coeff_t lhs,  mdnum5_t* rhs){
  mdnum5_t res;

  // Addition like function 'lhs - rhs'
  // Real;
  res.r = lhs - rhs->r;
  // Order 1;
  res.e1 =  - rhs->e1;
  res.e2 =  - rhs->e2;
  res.e3 =  - rhs->e3;
  res.e4 =  - rhs->e4;
  res.e5 =  - rhs->e5;
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
  // Order 4;
  res.e1234 =  - rhs->e1234;
  res.e1235 =  - rhs->e1235;
  res.e1245 =  - rhs->e1245;
  res.e1345 =  - rhs->e1345;
  res.e2345 =  - rhs->e2345;
  // Order 5;
  res.e12345 =  - rhs->e12345;

  return res;

}

void mdnum5_sub_ro_to(  coeff_t lhs,  mdnum5_t* rhs, mdnum5_t* res){
  // Addition like function 'lhs - rhs'
  // Real;
  res->r = lhs - rhs->r;
  // Order 1;
  res->e1 =  - rhs->e1;
  res->e2 =  - rhs->e2;
  res->e3 =  - rhs->e3;
  res->e4 =  - rhs->e4;
  res->e5 =  - rhs->e5;
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
  // Order 4;
  res->e1234 =  - rhs->e1234;
  res->e1235 =  - rhs->e1235;
  res->e1245 =  - rhs->e1245;
  res->e1345 =  - rhs->e1345;
  res->e2345 =  - rhs->e2345;
  // Order 5;
  res->e12345 =  - rhs->e12345;

}

mdnum5_t mdnum5_sub_or(  mdnum5_t* lhs,  coeff_t rhs){
  mdnum5_t res;

  // Addition like function 'lhs - rhs'
  // Real;
  res.r = lhs->r - rhs;
  // Order 1;
  res.e1 = lhs->e1;
  res.e2 = lhs->e2;
  res.e3 = lhs->e3;
  res.e4 = lhs->e4;
  res.e5 = lhs->e5;
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
  // Order 4;
  res.e1234 = lhs->e1234;
  res.e1235 = lhs->e1235;
  res.e1245 = lhs->e1245;
  res.e1345 = lhs->e1345;
  res.e2345 = lhs->e2345;
  // Order 5;
  res.e12345 = lhs->e12345;

  return res;

}

void mdnum5_sub_or_to(  mdnum5_t* lhs,  coeff_t rhs, mdnum5_t* res){
  // Addition like function 'lhs - rhs'
  // Real;
  res->r = lhs->r - rhs;
  // Order 1;
  res->e1 = lhs->e1;
  res->e2 = lhs->e2;
  res->e3 = lhs->e3;
  res->e4 = lhs->e4;
  res->e5 = lhs->e5;
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
  // Order 4;
  res->e1234 = lhs->e1234;
  res->e1235 = lhs->e1235;
  res->e1245 = lhs->e1245;
  res->e1345 = lhs->e1345;
  res->e2345 = lhs->e2345;
  // Order 5;
  res->e12345 = lhs->e12345;

}

mdnum5_t mdnum5_mul_oo(  mdnum5_t* lhs,  mdnum5_t* rhs){
  mdnum5_t res;

  //  Multiplication like function 'lhs * rhs'
  // Real;
  res.r = lhs->r * rhs->r;
  // Order 1;
  res.e1 = lhs->r * rhs->e1 + lhs->e1 * rhs->r;
  res.e2 = lhs->r * rhs->e2 + lhs->e2 * rhs->r;
  res.e3 = lhs->r * rhs->e3 + lhs->e3 * rhs->r;
  res.e4 = lhs->r * rhs->e4 + lhs->e4 * rhs->r;
  res.e5 = lhs->r * rhs->e5 + lhs->e5 * rhs->r;
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

  return res;

}

void mdnum5_mul_oo_to(  mdnum5_t* lhs,  mdnum5_t* rhs, mdnum5_t* res){
  //  Multiplication like function 'lhs * rhs'
  // Real;
  res->r = lhs->r * rhs->r;
  // Order 1;
  res->e1 = lhs->r * rhs->e1 + lhs->e1 * rhs->r;
  res->e2 = lhs->r * rhs->e2 + lhs->e2 * rhs->r;
  res->e3 = lhs->r * rhs->e3 + lhs->e3 * rhs->r;
  res->e4 = lhs->r * rhs->e4 + lhs->e4 * rhs->r;
  res->e5 = lhs->r * rhs->e5 + lhs->e5 * rhs->r;
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

}

mdnum5_t mdnum5_mul_ro(  coeff_t lhs,  mdnum5_t* rhs){
  mdnum5_t res;

  // Multiplication like function 'lhs * rhs'
  //  Real;
  res.r = lhs * rhs->r;
  // Order 1;
  res.e1 = lhs * rhs->e1;
  res.e2 = lhs * rhs->e2;
  res.e3 = lhs * rhs->e3;
  res.e4 = lhs * rhs->e4;
  res.e5 = lhs * rhs->e5;
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
  // Order 4;
  res.e1234 = lhs * rhs->e1234;
  res.e1235 = lhs * rhs->e1235;
  res.e1245 = lhs * rhs->e1245;
  res.e1345 = lhs * rhs->e1345;
  res.e2345 = lhs * rhs->e2345;
  // Order 5;
  res.e12345 = lhs * rhs->e12345;

  return res;

}

void mdnum5_mul_ro_to(  coeff_t lhs,  mdnum5_t* rhs, mdnum5_t* res){
  // Multiplication like function 'lhs * rhs'
  //  Real;
  res->r = lhs * rhs->r;
  // Order 1;
  res->e1 = lhs * rhs->e1;
  res->e2 = lhs * rhs->e2;
  res->e3 = lhs * rhs->e3;
  res->e4 = lhs * rhs->e4;
  res->e5 = lhs * rhs->e5;
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
  // Order 4;
  res->e1234 = lhs * rhs->e1234;
  res->e1235 = lhs * rhs->e1235;
  res->e1245 = lhs * rhs->e1245;
  res->e1345 = lhs * rhs->e1345;
  res->e2345 = lhs * rhs->e2345;
  // Order 5;
  res->e12345 = lhs * rhs->e12345;

}

mdnum5_t mdnum5_trunc_mul_oo(  mdnum5_t* lhs,  mdnum5_t* rhs){
  mdnum5_t res;

  res = mdnum5_init();

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

  return res;

}

void mdnum5_trunc_mul_oo_to(  mdnum5_t* lhs,  mdnum5_t* rhs, mdnum5_t* res){
   (*res) = mdnum5_init();

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

}

mdnum5_t mdnum5_gem_oo(  mdnum5_t* a,  mdnum5_t* b,  mdnum5_t* c){
  mdnum5_t res;

  //  General multiplication like function 'a * b + c'
  // Real;
  res.r = c->r + a->r * b->r;
  // Order 1;
  res.e1 = c->e1 + a->r * b->e1 + a->e1 * b->r;
  res.e2 = c->e2 + a->r * b->e2 + a->e2 * b->r;
  res.e3 = c->e3 + a->r * b->e3 + a->e3 * b->r;
  res.e4 = c->e4 + a->r * b->e4 + a->e4 * b->r;
  res.e5 = c->e5 + a->r * b->e5 + a->e5 * b->r;
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

  return res;

}

void mdnum5_gem_oo_to(  mdnum5_t* a,  mdnum5_t* b,  mdnum5_t* c, mdnum5_t* res){
  //  General multiplication like function 'a * b + c'
  // Real;
  res->r = c->r + a->r * b->r;
  // Order 1;
  res->e1 = c->e1 + a->r * b->e1 + a->e1 * b->r;
  res->e2 = c->e2 + a->r * b->e2 + a->e2 * b->r;
  res->e3 = c->e3 + a->r * b->e3 + a->e3 * b->r;
  res->e4 = c->e4 + a->r * b->e4 + a->e4 * b->r;
  res->e5 = c->e5 + a->r * b->e5 + a->e5 * b->r;
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

}

mdnum5_t mdnum5_gem_ro(  coeff_t a,  mdnum5_t* b,  mdnum5_t* c){
  mdnum5_t res;

  //  General multiplication like function 'a * b + c'
  // Real;
  res.r = c->r + a * b->r;
  // Order 1;
  res.e1 = c->e1 + a * b->e1;
  res.e2 = c->e2 + a * b->e2;
  res.e3 = c->e3 + a * b->e3;
  res.e4 = c->e4 + a * b->e4;
  res.e5 = c->e5 + a * b->e5;
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
  // Order 4;
  res.e1234 = c->e1234 + a * b->e1234;
  res.e1235 = c->e1235 + a * b->e1235;
  res.e1245 = c->e1245 + a * b->e1245;
  res.e1345 = c->e1345 + a * b->e1345;
  res.e2345 = c->e2345 + a * b->e2345;
  // Order 5;
  res.e12345 = c->e12345 + a * b->e12345;

  return res;

}

void mdnum5_gem_ro_to(  coeff_t a,  mdnum5_t* b,  mdnum5_t* c, mdnum5_t* res){
  //  General multiplication like function 'a * b + c'
  // Real;
  res->r = c->r + a * b->r;
  // Order 1;
  res->e1 = c->e1 + a * b->e1;
  res->e2 = c->e2 + a * b->e2;
  res->e3 = c->e3 + a * b->e3;
  res->e4 = c->e4 + a * b->e4;
  res->e5 = c->e5 + a * b->e5;
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
  // Order 4;
  res->e1234 = c->e1234 + a * b->e1234;
  res->e1235 = c->e1235 + a * b->e1235;
  res->e1245 = c->e1245 + a * b->e1245;
  res->e1345 = c->e1345 + a * b->e1345;
  res->e2345 = c->e2345 + a * b->e2345;
  // Order 5;
  res->e12345 = c->e12345 + a * b->e12345;

}

void mdnum5_trunc_gem_oo_to( ord_t ord_lhs,  mdnum5_t* a,  ord_t ord_rhs,  mdnum5_t* b,  mdnum5_t* c, mdnum5_t* res){
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
          break;
        case 4:
          // res order: 4
          res->e1234 = c->e1234 + a->r * b->e1234;
          res->e1235 = c->e1235 + a->r * b->e1235;
          res->e1245 = c->e1245 + a->r * b->e1245;
          res->e1345 = c->e1345 + a->r * b->e1345;
          res->e2345 = c->e2345 + a->r * b->e2345;
          break;
        case 5:
          // res order: 5
          res->e12345 = c->e12345 + a->r * b->e12345;
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
          break;
        case 4:
          // res order: 5
          res->e12345 = c->e12345 + a->e1 * b->e2345 + a->e2 * b->e1345 
                      + a->e3 * b->e1245 + a->e4 * b->e1235 + a->e5 * b->e1234;
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
          break;
        case 3:
          // res order: 5
          res->e12345 = c->e12345 + a->e12 * b->e345 + a->e13 * b->e245 
                      + a->e23 * b->e145 + a->e14 * b->e235 + a->e24 * b->e135 
                      + a->e34 * b->e125 + a->e15 * b->e234 + a->e25 * b->e134 
                      + a->e35 * b->e124 + a->e45 * b->e123;
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
          break;
        case 2:
          // res order: 5
          res->e12345 = c->e12345 + a->e345 * b->e12 + a->e245 * b->e13 
                      + a->e145 * b->e23 + a->e235 * b->e14 + a->e135 * b->e24 
                      + a->e125 * b->e34 + a->e234 * b->e15 + a->e134 * b->e25 
                      + a->e124 * b->e35 + a->e123 * b->e45;
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
          break;
        case 1:
          // res order: 5
          res->e12345 = c->e12345 + a->e2345 * b->e1 + a->e1345 * b->e2 
                      + a->e1245 * b->e3 + a->e1235 * b->e4 + a->e1234 * b->e5;
          break;
      }
      break;
    case 5:
      switch( ord_rhs ){
        case 0:
          // res order: 5
          res->e12345 = c->e12345 + a->e12345 * b->r;
          break;
      }
      break;
  }

}

mdnum5_t mdnum5_feval(coeff_t* feval_re, mdnum5_t* x){

  mdnum5_t res;

  // feval function
  //  Definitions
  coeff_t factor=1, coef = 0;
  mdnum5_t deltax = (*x), deltax_power = (*x);
  deltax.r = 0.0;
  deltax_power.r = 0.0;
  mdnum5_set_r(0.0, &res);
  //  Real
  res.r = feval_re[0];
  // Order 1
  factor *=1;
  coef    = feval_re[1]/ factor;;
  mdnum5_gem_ro_to( coef, &deltax_power, &res, &res);
  deltax_power = mdnum5_mul_oo(&deltax_power,&deltax);
  // Order 2
  factor *=2;
  coef    = feval_re[2]/ factor;;
  mdnum5_gem_ro_to( coef, &deltax_power, &res, &res);
  deltax_power = mdnum5_mul_oo(&deltax_power,&deltax);
  // Order 3
  factor *=3;
  coef    = feval_re[3]/ factor;;
  mdnum5_gem_ro_to( coef, &deltax_power, &res, &res);
  deltax_power = mdnum5_mul_oo(&deltax_power,&deltax);
  // Order 4
  factor *=4;
  coef    = feval_re[4]/ factor;;
  mdnum5_gem_ro_to( coef, &deltax_power, &res, &res);
  deltax_power = mdnum5_mul_oo(&deltax_power,&deltax);
  // Order 5
  factor *=5;
  coef    = feval_re[5]/ factor;;
  mdnum5_gem_ro_to( coef, &deltax_power, &res, &res);

  return res;

}

void mdnum5_feval_to(coeff_t* feval_re, mdnum5_t* x, mdnum5_t* res){

  // feval function
  //  Definitions
  coeff_t factor=1, coef = 0;
  mdnum5_t deltax = (*x), deltax_power = (*x);
  deltax.r = 0.0;
  deltax_power.r = 0.0;
  mdnum5_set_r(0.0, res);
  //  Real
  res->r = feval_re[0];
  // Order 1
  factor *=1;
  coef    = feval_re[1]/ factor;;
  mdnum5_gem_ro_to( coef, &deltax_power, res, res);
  deltax_power = mdnum5_mul_oo(&deltax_power,&deltax);
  // Order 2
  factor *=2;
  coef    = feval_re[2]/ factor;;
  mdnum5_gem_ro_to( coef, &deltax_power, res, res);
  deltax_power = mdnum5_mul_oo(&deltax_power,&deltax);
  // Order 3
  factor *=3;
  coef    = feval_re[3]/ factor;;
  mdnum5_gem_ro_to( coef, &deltax_power, res, res);
  deltax_power = mdnum5_mul_oo(&deltax_power,&deltax);
  // Order 4
  factor *=4;
  coef    = feval_re[4]/ factor;;
  mdnum5_gem_ro_to( coef, &deltax_power, res, res);
  deltax_power = mdnum5_mul_oo(&deltax_power,&deltax);
  // Order 5
  factor *=5;
  coef    = feval_re[5]/ factor;;
  mdnum5_gem_ro_to( coef, &deltax_power, res, res);

}

