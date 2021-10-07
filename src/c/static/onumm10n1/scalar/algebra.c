
// Division.

// ****************************************************************************************************
onumm10n1_t onumm10n1_div_ro(coeff_t num, onumm10n1_t* den){

    
    onumm10n1_t inv = onumm10n1_pow(den,-1);
    onumm10n1_t res = onumm10n1_mul_ro(num,&inv);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
onumm10n1_t onumm10n1_div_oo(onumm10n1_t* num, onumm10n1_t* den){

    
    onumm10n1_t inv = onumm10n1_init();
    onumm10n1_pow_to(den,-1,&inv);
    onumm10n1_t res = onumm10n1_mul_oo(num,&inv);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
onumm10n1_t onumm10n1_div_or(onumm10n1_t* num, coeff_t val){

    return onumm10n1_mul_ro(1.0/val,num);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
onumm10n1_t onumm10n1_abs(onumm10n1_t* num){

	onumm10n1_t res;
    onumm10n1_abs_to(num,&res);
    return res;

}
// ----------------------------------------------------------------------------------------------------

onumm10n1_t onumm10n1_neg(  onumm10n1_t* lhs){

  onumm10n1_t res;

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

  return res;

}

void onumm10n1_neg_to(  onumm10n1_t* lhs, onumm10n1_t* res){

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

}

onumm10n1_t onumm10n1_sum_oo(  onumm10n1_t* lhs,  onumm10n1_t* rhs){
  onumm10n1_t res;

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

  return res;

}

void onumm10n1_sum_oo_to(  onumm10n1_t* lhs,  onumm10n1_t* rhs, onumm10n1_t* res){
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

}

onumm10n1_t onumm10n1_sum_ro(  coeff_t lhs,  onumm10n1_t* rhs){
  onumm10n1_t res;

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

  return res;

}

void onumm10n1_sum_ro_to(  coeff_t lhs,  onumm10n1_t* rhs, onumm10n1_t* res){
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

}

onumm10n1_t onumm10n1_sub_oo(  onumm10n1_t* lhs,  onumm10n1_t* rhs){
  onumm10n1_t res;

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

  return res;

}

void onumm10n1_sub_oo_to(  onumm10n1_t* lhs,  onumm10n1_t* rhs, onumm10n1_t* res){
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

}

onumm10n1_t onumm10n1_sub_ro(  coeff_t lhs,  onumm10n1_t* rhs){
  onumm10n1_t res;

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

  return res;

}

void onumm10n1_sub_ro_to(  coeff_t lhs,  onumm10n1_t* rhs, onumm10n1_t* res){
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

}

onumm10n1_t onumm10n1_sub_or(  onumm10n1_t* lhs,  coeff_t rhs){
  onumm10n1_t res;

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

  return res;

}

void onumm10n1_sub_or_to(  onumm10n1_t* lhs,  coeff_t rhs, onumm10n1_t* res){
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

}

onumm10n1_t onumm10n1_mul_oo(  onumm10n1_t* lhs,  onumm10n1_t* rhs){
  onumm10n1_t res;

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

  return res;

}

void onumm10n1_mul_oo_to(  onumm10n1_t* lhs,  onumm10n1_t* rhs, onumm10n1_t* res){
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

}

onumm10n1_t onumm10n1_mul_ro(  coeff_t lhs,  onumm10n1_t* rhs){
  onumm10n1_t res;

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

  return res;

}

void onumm10n1_mul_ro_to(  coeff_t lhs,  onumm10n1_t* rhs, onumm10n1_t* res){
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

}

onumm10n1_t onumm10n1_trunc_mul_oo(  onumm10n1_t* lhs,  onumm10n1_t* rhs){
  onumm10n1_t res;

  res = onumm10n1_init();

  //  Truncated multiplication like function 'lhs * rhs'

  return res;

}

void onumm10n1_trunc_mul_oo_to(  onumm10n1_t* lhs,  onumm10n1_t* rhs, onumm10n1_t* res){
   (*res) = onumm10n1_init();

  //  Truncated multiplication like function 'lhs * rhs'

}

onumm10n1_t onumm10n1_gem_oo(  onumm10n1_t* a,  onumm10n1_t* b,  onumm10n1_t* c){
  onumm10n1_t res;

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

  return res;

}

void onumm10n1_gem_oo_to(  onumm10n1_t* a,  onumm10n1_t* b,  onumm10n1_t* c, onumm10n1_t* res){
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

}

onumm10n1_t onumm10n1_gem_ro(  coeff_t a,  onumm10n1_t* b,  onumm10n1_t* c){
  onumm10n1_t res;

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

  return res;

}

void onumm10n1_gem_ro_to(  coeff_t a,  onumm10n1_t* b,  onumm10n1_t* c, onumm10n1_t* res){
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

}

void onumm10n1_trunc_gem_oo_to( ord_t ord_lhs,  onumm10n1_t* a,  ord_t ord_rhs,  onumm10n1_t* b,  onumm10n1_t* c, onumm10n1_t* res){
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
          res->e8 = c->e8 + a->r * b->e8;
          res->e9 = c->e9 + a->r * b->e9;
          res->eA = c->eA + a->r * b->eA;
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
          res->e8 = c->e8 + a->e8 * b->r;
          res->e9 = c->e9 + a->e9 * b->r;
          res->eA = c->eA + a->eA * b->r;
          break;
      }
      break;
  }

}

void onumm10n1_trunc_sum_oo_to(ord_t order, onumm10n1_t* lhs,onumm10n1_t* rhs, onumm10n1_t* res){
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
      res->e7 = lhs->e7 + rhs->e7;
      res->e8 = lhs->e8 + rhs->e8;
      res->e9 = lhs->e9 + rhs->e9;
      res->eA = lhs->eA + rhs->eA;
      break;
  }
}

void onumm10n1_trunc_sub_oo_to(ord_t order, onumm10n1_t* lhs,onumm10n1_t* rhs, onumm10n1_t* res){
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
      res->e7 = lhs->e7 - rhs->e7;
      res->e8 = lhs->e8 - rhs->e8;
      res->e9 = lhs->e9 - rhs->e9;
      res->eA = lhs->eA - rhs->eA;
      break;
  }
}

onumm10n1_t onumm10n1_feval(coeff_t* feval_re, onumm10n1_t* x){

  onumm10n1_t res;

  // feval function
  //  Definitions
  coeff_t factor=1, coef = 0;
  onumm10n1_t deltax = (*x), deltax_power = (*x);
  deltax.r = 0.0;
  deltax_power.r = 0.0;
  onumm10n1_set_r(0.0, &res);
  //  Real
  res.r = feval_re[0];
  // Order 1
  factor *=1;
  coef    = feval_re[1]/ factor;;
  onumm10n1_gem_ro_to( coef, &deltax_power, &res, &res);

  return res;

}

void onumm10n1_feval_to(coeff_t* feval_re, onumm10n1_t* x, onumm10n1_t* res){

  // feval function
  //  Definitions
  coeff_t factor=1, coef = 0;
  onumm10n1_t deltax = (*x), deltax_power = (*x);
  deltax.r = 0.0;
  deltax_power.r = 0.0;
  onumm10n1_set_r(0.0, res);
  //  Real
  res->r = feval_re[0];
  // Order 1
  factor *=1;
  coef    = feval_re[1]/ factor;;
  onumm10n1_gem_ro_to( coef, &deltax_power, res, res);

}

