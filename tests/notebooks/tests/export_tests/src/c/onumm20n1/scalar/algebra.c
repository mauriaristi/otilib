
// Division.

// ****************************************************************************************************
onumm20n1_t onumm20n1_div_ro(coeff_t num, onumm20n1_t* den){

    
    onumm20n1_t inv = onumm20n1_pow(den,-1);
    onumm20n1_t res = onumm20n1_mul_ro(num,&inv);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
onumm20n1_t onumm20n1_div_oo(onumm20n1_t* num, onumm20n1_t* den){

    
    onumm20n1_t inv = onumm20n1_init();
    onumm20n1_pow_to(den,-1,&inv);
    onumm20n1_t res = onumm20n1_mul_oo(num,&inv);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
onumm20n1_t onumm20n1_div_or(onumm20n1_t* num, coeff_t val){

    return onumm20n1_mul_ro(1.0/val,num);

}
// ----------------------------------------------------------------------------------------------------

onumm20n1_t onumm20n1_neg(  onumm20n1_t* lhs){

  onumm20n1_t res;

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
  res.e8 = -lhs->e8;
  res.e9 = -lhs->e9;
  res.eA = -lhs->eA;
  res.eB = -lhs->eB;
  res.eC = -lhs->eC;
  res.eD = -lhs->eD;
  res.eE = -lhs->eE;
  res.eF = -lhs->eF;
  res.eG = -lhs->eG;
  res.eH = -lhs->eH;
  res.eI = -lhs->eI;
  res.eJ = -lhs->eJ;
  res.eK = -lhs->eK;

  return res;

}

void onumm20n1_neg_to(  onumm20n1_t* lhs, onumm20n1_t* res){

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
  res->e8 = -lhs->e8;
  res->e9 = -lhs->e9;
  res->eA = -lhs->eA;
  res->eB = -lhs->eB;
  res->eC = -lhs->eC;
  res->eD = -lhs->eD;
  res->eE = -lhs->eE;
  res->eF = -lhs->eF;
  res->eG = -lhs->eG;
  res->eH = -lhs->eH;
  res->eI = -lhs->eI;
  res->eJ = -lhs->eJ;
  res->eK = -lhs->eK;

}

onumm20n1_t onumm20n1_add_oo(  onumm20n1_t* lhs,  onumm20n1_t* rhs){
  onumm20n1_t res;

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
  res.e8 = lhs->e8 + rhs->e8;
  res.e9 = lhs->e9 + rhs->e9;
  res.eA = lhs->eA + rhs->eA;
  res.eB = lhs->eB + rhs->eB;
  res.eC = lhs->eC + rhs->eC;
  res.eD = lhs->eD + rhs->eD;
  res.eE = lhs->eE + rhs->eE;
  res.eF = lhs->eF + rhs->eF;
  res.eG = lhs->eG + rhs->eG;
  res.eH = lhs->eH + rhs->eH;
  res.eI = lhs->eI + rhs->eI;
  res.eJ = lhs->eJ + rhs->eJ;
  res.eK = lhs->eK + rhs->eK;

  return res;

}

void onumm20n1_add_oo_to(  onumm20n1_t* lhs,  onumm20n1_t* rhs, onumm20n1_t* res){
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
  res->e8 = lhs->e8 + rhs->e8;
  res->e9 = lhs->e9 + rhs->e9;
  res->eA = lhs->eA + rhs->eA;
  res->eB = lhs->eB + rhs->eB;
  res->eC = lhs->eC + rhs->eC;
  res->eD = lhs->eD + rhs->eD;
  res->eE = lhs->eE + rhs->eE;
  res->eF = lhs->eF + rhs->eF;
  res->eG = lhs->eG + rhs->eG;
  res->eH = lhs->eH + rhs->eH;
  res->eI = lhs->eI + rhs->eI;
  res->eJ = lhs->eJ + rhs->eJ;
  res->eK = lhs->eK + rhs->eK;

}

onumm20n1_t onumm20n1_add_ro(  coeff_t lhs,  onumm20n1_t* rhs){
  onumm20n1_t res;

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
  res.e8 =  + rhs->e8;
  res.e9 =  + rhs->e9;
  res.eA =  + rhs->eA;
  res.eB =  + rhs->eB;
  res.eC =  + rhs->eC;
  res.eD =  + rhs->eD;
  res.eE =  + rhs->eE;
  res.eF =  + rhs->eF;
  res.eG =  + rhs->eG;
  res.eH =  + rhs->eH;
  res.eI =  + rhs->eI;
  res.eJ =  + rhs->eJ;
  res.eK =  + rhs->eK;

  return res;

}

void onumm20n1_add_ro_to(  coeff_t lhs,  onumm20n1_t* rhs, onumm20n1_t* res){
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
  res->e8 =  + rhs->e8;
  res->e9 =  + rhs->e9;
  res->eA =  + rhs->eA;
  res->eB =  + rhs->eB;
  res->eC =  + rhs->eC;
  res->eD =  + rhs->eD;
  res->eE =  + rhs->eE;
  res->eF =  + rhs->eF;
  res->eG =  + rhs->eG;
  res->eH =  + rhs->eH;
  res->eI =  + rhs->eI;
  res->eJ =  + rhs->eJ;
  res->eK =  + rhs->eK;

}

onumm20n1_t onumm20n1_sub_oo(  onumm20n1_t* lhs,  onumm20n1_t* rhs){
  onumm20n1_t res;

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
  res.e8 = lhs->e8 - rhs->e8;
  res.e9 = lhs->e9 - rhs->e9;
  res.eA = lhs->eA - rhs->eA;
  res.eB = lhs->eB - rhs->eB;
  res.eC = lhs->eC - rhs->eC;
  res.eD = lhs->eD - rhs->eD;
  res.eE = lhs->eE - rhs->eE;
  res.eF = lhs->eF - rhs->eF;
  res.eG = lhs->eG - rhs->eG;
  res.eH = lhs->eH - rhs->eH;
  res.eI = lhs->eI - rhs->eI;
  res.eJ = lhs->eJ - rhs->eJ;
  res.eK = lhs->eK - rhs->eK;

  return res;

}

void onumm20n1_sub_oo_to(  onumm20n1_t* lhs,  onumm20n1_t* rhs, onumm20n1_t* res){
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
  res->e8 = lhs->e8 - rhs->e8;
  res->e9 = lhs->e9 - rhs->e9;
  res->eA = lhs->eA - rhs->eA;
  res->eB = lhs->eB - rhs->eB;
  res->eC = lhs->eC - rhs->eC;
  res->eD = lhs->eD - rhs->eD;
  res->eE = lhs->eE - rhs->eE;
  res->eF = lhs->eF - rhs->eF;
  res->eG = lhs->eG - rhs->eG;
  res->eH = lhs->eH - rhs->eH;
  res->eI = lhs->eI - rhs->eI;
  res->eJ = lhs->eJ - rhs->eJ;
  res->eK = lhs->eK - rhs->eK;

}

onumm20n1_t onumm20n1_sub_ro(  coeff_t lhs,  onumm20n1_t* rhs){
  onumm20n1_t res;

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
  res.e8 =  - rhs->e8;
  res.e9 =  - rhs->e9;
  res.eA =  - rhs->eA;
  res.eB =  - rhs->eB;
  res.eC =  - rhs->eC;
  res.eD =  - rhs->eD;
  res.eE =  - rhs->eE;
  res.eF =  - rhs->eF;
  res.eG =  - rhs->eG;
  res.eH =  - rhs->eH;
  res.eI =  - rhs->eI;
  res.eJ =  - rhs->eJ;
  res.eK =  - rhs->eK;

  return res;

}

void onumm20n1_sub_ro_to(  coeff_t lhs,  onumm20n1_t* rhs, onumm20n1_t* res){
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
  res->e8 =  - rhs->e8;
  res->e9 =  - rhs->e9;
  res->eA =  - rhs->eA;
  res->eB =  - rhs->eB;
  res->eC =  - rhs->eC;
  res->eD =  - rhs->eD;
  res->eE =  - rhs->eE;
  res->eF =  - rhs->eF;
  res->eG =  - rhs->eG;
  res->eH =  - rhs->eH;
  res->eI =  - rhs->eI;
  res->eJ =  - rhs->eJ;
  res->eK =  - rhs->eK;

}

onumm20n1_t onumm20n1_sub_or(  onumm20n1_t* lhs,  coeff_t rhs){
  onumm20n1_t res;

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
  res.e8 = lhs->e8;
  res.e9 = lhs->e9;
  res.eA = lhs->eA;
  res.eB = lhs->eB;
  res.eC = lhs->eC;
  res.eD = lhs->eD;
  res.eE = lhs->eE;
  res.eF = lhs->eF;
  res.eG = lhs->eG;
  res.eH = lhs->eH;
  res.eI = lhs->eI;
  res.eJ = lhs->eJ;
  res.eK = lhs->eK;

  return res;

}

void onumm20n1_sub_or_to(  onumm20n1_t* lhs,  coeff_t rhs, onumm20n1_t* res){
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
  res->e8 = lhs->e8;
  res->e9 = lhs->e9;
  res->eA = lhs->eA;
  res->eB = lhs->eB;
  res->eC = lhs->eC;
  res->eD = lhs->eD;
  res->eE = lhs->eE;
  res->eF = lhs->eF;
  res->eG = lhs->eG;
  res->eH = lhs->eH;
  res->eI = lhs->eI;
  res->eJ = lhs->eJ;
  res->eK = lhs->eK;

}

onumm20n1_t onumm20n1_mul_oo(  onumm20n1_t* lhs,  onumm20n1_t* rhs){
  onumm20n1_t res;

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
  res.e8 = lhs->r * rhs->e8 + lhs->e8 * rhs->r;
  res.e9 = lhs->r * rhs->e9 + lhs->e9 * rhs->r;
  res.eA = lhs->r * rhs->eA + lhs->eA * rhs->r;
  res.eB = lhs->r * rhs->eB + lhs->eB * rhs->r;
  res.eC = lhs->r * rhs->eC + lhs->eC * rhs->r;
  res.eD = lhs->r * rhs->eD + lhs->eD * rhs->r;
  res.eE = lhs->r * rhs->eE + lhs->eE * rhs->r;
  res.eF = lhs->r * rhs->eF + lhs->eF * rhs->r;
  res.eG = lhs->r * rhs->eG + lhs->eG * rhs->r;
  res.eH = lhs->r * rhs->eH + lhs->eH * rhs->r;
  res.eI = lhs->r * rhs->eI + lhs->eI * rhs->r;
  res.eJ = lhs->r * rhs->eJ + lhs->eJ * rhs->r;
  res.eK = lhs->r * rhs->eK + lhs->eK * rhs->r;

  return res;

}

void onumm20n1_mul_oo_to(  onumm20n1_t* lhs,  onumm20n1_t* rhs, onumm20n1_t* res){
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
  res->e8 = lhs->r * rhs->e8 + lhs->e8 * rhs->r;
  res->e9 = lhs->r * rhs->e9 + lhs->e9 * rhs->r;
  res->eA = lhs->r * rhs->eA + lhs->eA * rhs->r;
  res->eB = lhs->r * rhs->eB + lhs->eB * rhs->r;
  res->eC = lhs->r * rhs->eC + lhs->eC * rhs->r;
  res->eD = lhs->r * rhs->eD + lhs->eD * rhs->r;
  res->eE = lhs->r * rhs->eE + lhs->eE * rhs->r;
  res->eF = lhs->r * rhs->eF + lhs->eF * rhs->r;
  res->eG = lhs->r * rhs->eG + lhs->eG * rhs->r;
  res->eH = lhs->r * rhs->eH + lhs->eH * rhs->r;
  res->eI = lhs->r * rhs->eI + lhs->eI * rhs->r;
  res->eJ = lhs->r * rhs->eJ + lhs->eJ * rhs->r;
  res->eK = lhs->r * rhs->eK + lhs->eK * rhs->r;

}

onumm20n1_t onumm20n1_mul_ro(  coeff_t lhs,  onumm20n1_t* rhs){
  onumm20n1_t res;

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
  res.e8 = lhs * rhs->e8;
  res.e9 = lhs * rhs->e9;
  res.eA = lhs * rhs->eA;
  res.eB = lhs * rhs->eB;
  res.eC = lhs * rhs->eC;
  res.eD = lhs * rhs->eD;
  res.eE = lhs * rhs->eE;
  res.eF = lhs * rhs->eF;
  res.eG = lhs * rhs->eG;
  res.eH = lhs * rhs->eH;
  res.eI = lhs * rhs->eI;
  res.eJ = lhs * rhs->eJ;
  res.eK = lhs * rhs->eK;

  return res;

}

void onumm20n1_mul_ro_to(  coeff_t lhs,  onumm20n1_t* rhs, onumm20n1_t* res){
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
  res->e8 = lhs * rhs->e8;
  res->e9 = lhs * rhs->e9;
  res->eA = lhs * rhs->eA;
  res->eB = lhs * rhs->eB;
  res->eC = lhs * rhs->eC;
  res->eD = lhs * rhs->eD;
  res->eE = lhs * rhs->eE;
  res->eF = lhs * rhs->eF;
  res->eG = lhs * rhs->eG;
  res->eH = lhs * rhs->eH;
  res->eI = lhs * rhs->eI;
  res->eJ = lhs * rhs->eJ;
  res->eK = lhs * rhs->eK;

}

onumm20n1_t onumm20n1_trunc_mul_oo(  onumm20n1_t* lhs,  onumm20n1_t* rhs){
  onumm20n1_t res;

  res = onumm20n1_init();

  //  Truncated multiplication like function 'lhs * rhs'

  return res;

}

void onumm20n1_trunc_mul_oo_to(  onumm20n1_t* lhs,  onumm20n1_t* rhs, onumm20n1_t* res){
   (*res) = onumm20n1_init();

  //  Truncated multiplication like function 'lhs * rhs'

}

onumm20n1_t onumm20n1_gem_oo(  onumm20n1_t* a,  onumm20n1_t* b,  onumm20n1_t* c){
  onumm20n1_t res;

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
  res.e8 = c->e8 + a->r * b->e8 + a->e8 * b->r;
  res.e9 = c->e9 + a->r * b->e9 + a->e9 * b->r;
  res.eA = c->eA + a->r * b->eA + a->eA * b->r;
  res.eB = c->eB + a->r * b->eB + a->eB * b->r;
  res.eC = c->eC + a->r * b->eC + a->eC * b->r;
  res.eD = c->eD + a->r * b->eD + a->eD * b->r;
  res.eE = c->eE + a->r * b->eE + a->eE * b->r;
  res.eF = c->eF + a->r * b->eF + a->eF * b->r;
  res.eG = c->eG + a->r * b->eG + a->eG * b->r;
  res.eH = c->eH + a->r * b->eH + a->eH * b->r;
  res.eI = c->eI + a->r * b->eI + a->eI * b->r;
  res.eJ = c->eJ + a->r * b->eJ + a->eJ * b->r;
  res.eK = c->eK + a->r * b->eK + a->eK * b->r;

  return res;

}

void onumm20n1_gem_oo_to(  onumm20n1_t* a,  onumm20n1_t* b,  onumm20n1_t* c, onumm20n1_t* res){
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
  res->e8 = c->e8 + a->r * b->e8 + a->e8 * b->r;
  res->e9 = c->e9 + a->r * b->e9 + a->e9 * b->r;
  res->eA = c->eA + a->r * b->eA + a->eA * b->r;
  res->eB = c->eB + a->r * b->eB + a->eB * b->r;
  res->eC = c->eC + a->r * b->eC + a->eC * b->r;
  res->eD = c->eD + a->r * b->eD + a->eD * b->r;
  res->eE = c->eE + a->r * b->eE + a->eE * b->r;
  res->eF = c->eF + a->r * b->eF + a->eF * b->r;
  res->eG = c->eG + a->r * b->eG + a->eG * b->r;
  res->eH = c->eH + a->r * b->eH + a->eH * b->r;
  res->eI = c->eI + a->r * b->eI + a->eI * b->r;
  res->eJ = c->eJ + a->r * b->eJ + a->eJ * b->r;
  res->eK = c->eK + a->r * b->eK + a->eK * b->r;

}

onumm20n1_t onumm20n1_gem_ro(  coeff_t a,  onumm20n1_t* b,  onumm20n1_t* c){
  onumm20n1_t res;

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
  res.e8 = c->e8 + a * b->e8;
  res.e9 = c->e9 + a * b->e9;
  res.eA = c->eA + a * b->eA;
  res.eB = c->eB + a * b->eB;
  res.eC = c->eC + a * b->eC;
  res.eD = c->eD + a * b->eD;
  res.eE = c->eE + a * b->eE;
  res.eF = c->eF + a * b->eF;
  res.eG = c->eG + a * b->eG;
  res.eH = c->eH + a * b->eH;
  res.eI = c->eI + a * b->eI;
  res.eJ = c->eJ + a * b->eJ;
  res.eK = c->eK + a * b->eK;

  return res;

}

void onumm20n1_gem_ro_to(  coeff_t a,  onumm20n1_t* b,  onumm20n1_t* c, onumm20n1_t* res){
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
  res->e8 = c->e8 + a * b->e8;
  res->e9 = c->e9 + a * b->e9;
  res->eA = c->eA + a * b->eA;
  res->eB = c->eB + a * b->eB;
  res->eC = c->eC + a * b->eC;
  res->eD = c->eD + a * b->eD;
  res->eE = c->eE + a * b->eE;
  res->eF = c->eF + a * b->eF;
  res->eG = c->eG + a * b->eG;
  res->eH = c->eH + a * b->eH;
  res->eI = c->eI + a * b->eI;
  res->eJ = c->eJ + a * b->eJ;
  res->eK = c->eK + a * b->eK;

}

onumm20n1_t onumm20n1_feval(coeff_t* feval_re, onumm20n1_t* x){

  onumm20n1_t res;

  // feval function
  //  Definitions
  coeff_t factor=1, coef = 0;
  onumm20n1_t tmp1, tmp2, deltax = (*x), deltax_power = (*x);
  deltax.r = 0.0;
  deltax_power.r = 0.0;
  onumm20n1_set_r(0.0, &res);
  //  Real
  res.r = feval_re[0];
  // Order 1
  factor *=1;
  coef    = feval_re[1]/ factor;;
  onumm20n1_gem_ro_to( coef, &deltax_power, &res, &res);

  return res;

}

void onumm20n1_feval_to(coeff_t* feval_re, onumm20n1_t* x, onumm20n1_t* res){

  // feval function
  //  Definitions
  coeff_t factor=1, coef = 0;
  onumm20n1_t tmp1, tmp2, deltax = (*x), deltax_power = (*x);
  deltax.r = 0.0;
  deltax_power.r = 0.0;
  onumm20n1_set_r(0.0, res);
  //  Real
  res->r = feval_re[0];
  // Order 1
  factor *=1;
  coef    = feval_re[1]/ factor;;
  onumm20n1_gem_ro_to( coef, &deltax_power, res, res);

}

