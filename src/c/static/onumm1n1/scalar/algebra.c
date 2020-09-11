
// Division.

// ****************************************************************************************************
onumm1n1_t onumm1n1_div_ro(coeff_t num, onumm1n1_t* den){

    
    onumm1n1_t inv = onumm1n1_pow(den,-1);
    onumm1n1_t res = onumm1n1_mul_ro(num,&inv);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
onumm1n1_t onumm1n1_div_oo(onumm1n1_t* num, onumm1n1_t* den){

    
    onumm1n1_t inv = onumm1n1_init();
    onumm1n1_pow_to(den,-1,&inv);
    onumm1n1_t res = onumm1n1_mul_oo(num,&inv);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
onumm1n1_t onumm1n1_div_or(onumm1n1_t* num, coeff_t val){

    return onumm1n1_mul_ro(1.0/val,num);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
onumm1n1_t onumm1n1_abs(onumm1n1_t* num){

	onumm1n1_t res;
    onumm1n1_abs_to(num,&res);
    return res;

}
// ----------------------------------------------------------------------------------------------------

onumm1n1_t onumm1n1_neg(  onumm1n1_t* lhs){

  onumm1n1_t res;

  // Negation like function '-lhs'
  // Real;
  res.r = -lhs->r;
  // Order 1;
  res.e1 = -lhs->e1;

  return res;

}

void onumm1n1_neg_to(  onumm1n1_t* lhs, onumm1n1_t* res){

  // Negation like function '-lhs'
  // Real;
  res->r = -lhs->r;
  // Order 1;
  res->e1 = -lhs->e1;

}

onumm1n1_t onumm1n1_sum_oo(  onumm1n1_t* lhs,  onumm1n1_t* rhs){
  onumm1n1_t res;

  // Addition like function 'lhs + rhs'
  //  Real
  res.r = lhs->r + rhs->r;
  // Order 1
  res.e1 = lhs->e1 + rhs->e1;

  return res;

}

void onumm1n1_sum_oo_to(  onumm1n1_t* lhs,  onumm1n1_t* rhs, onumm1n1_t* res){
  // Addition like function 'lhs + rhs'
  //  Real
  res->r = lhs->r + rhs->r;
  // Order 1
  res->e1 = lhs->e1 + rhs->e1;

}

onumm1n1_t onumm1n1_sum_ro(  coeff_t lhs,  onumm1n1_t* rhs){
  onumm1n1_t res;

  // Addition like function 'lhs + rhs'
  // Real;
  res.r = lhs + rhs->r;
  // Order 1;
  res.e1 =  + rhs->e1;

  return res;

}

void onumm1n1_sum_ro_to(  coeff_t lhs,  onumm1n1_t* rhs, onumm1n1_t* res){
  // Addition like function 'lhs + rhs'
  // Real;
  res->r = lhs + rhs->r;
  // Order 1;
  res->e1 =  + rhs->e1;

}

onumm1n1_t onumm1n1_sub_oo(  onumm1n1_t* lhs,  onumm1n1_t* rhs){
  onumm1n1_t res;

  // Addition like function 'lhs - rhs'
  //  Real
  res.r = lhs->r - rhs->r;
  // Order 1
  res.e1 = lhs->e1 - rhs->e1;

  return res;

}

void onumm1n1_sub_oo_to(  onumm1n1_t* lhs,  onumm1n1_t* rhs, onumm1n1_t* res){
  // Addition like function 'lhs - rhs'
  //  Real
  res->r = lhs->r - rhs->r;
  // Order 1
  res->e1 = lhs->e1 - rhs->e1;

}

onumm1n1_t onumm1n1_sub_ro(  coeff_t lhs,  onumm1n1_t* rhs){
  onumm1n1_t res;

  // Addition like function 'lhs - rhs'
  // Real;
  res.r = lhs - rhs->r;
  // Order 1;
  res.e1 =  - rhs->e1;

  return res;

}

void onumm1n1_sub_ro_to(  coeff_t lhs,  onumm1n1_t* rhs, onumm1n1_t* res){
  // Addition like function 'lhs - rhs'
  // Real;
  res->r = lhs - rhs->r;
  // Order 1;
  res->e1 =  - rhs->e1;

}

onumm1n1_t onumm1n1_sub_or(  onumm1n1_t* lhs,  coeff_t rhs){
  onumm1n1_t res;

  // Addition like function 'lhs - rhs'
  // Real;
  res.r = lhs->r - rhs;
  // Order 1;
  res.e1 = lhs->e1;

  return res;

}

void onumm1n1_sub_or_to(  onumm1n1_t* lhs,  coeff_t rhs, onumm1n1_t* res){
  // Addition like function 'lhs - rhs'
  // Real;
  res->r = lhs->r - rhs;
  // Order 1;
  res->e1 = lhs->e1;

}

onumm1n1_t onumm1n1_mul_oo(  onumm1n1_t* lhs,  onumm1n1_t* rhs){
  onumm1n1_t res;

  //  Multiplication like function 'lhs * rhs'
  // Real;
  res.r = lhs->r * rhs->r;
  // Order 1;
  res.e1 = lhs->r * rhs->e1 + lhs->e1 * rhs->r;

  return res;

}

void onumm1n1_mul_oo_to(  onumm1n1_t* lhs,  onumm1n1_t* rhs, onumm1n1_t* res){
  //  Multiplication like function 'lhs * rhs'
  // Real;
  res->r = lhs->r * rhs->r;
  // Order 1;
  res->e1 = lhs->r * rhs->e1 + lhs->e1 * rhs->r;

}

onumm1n1_t onumm1n1_mul_ro(  coeff_t lhs,  onumm1n1_t* rhs){
  onumm1n1_t res;

  // Multiplication like function 'lhs * rhs'
  //  Real;
  res.r = lhs * rhs->r;
  // Order 1;
  res.e1 = lhs * rhs->e1;

  return res;

}

void onumm1n1_mul_ro_to(  coeff_t lhs,  onumm1n1_t* rhs, onumm1n1_t* res){
  // Multiplication like function 'lhs * rhs'
  //  Real;
  res->r = lhs * rhs->r;
  // Order 1;
  res->e1 = lhs * rhs->e1;

}

onumm1n1_t onumm1n1_trunc_mul_oo(  onumm1n1_t* lhs,  onumm1n1_t* rhs){
  onumm1n1_t res;

  res = onumm1n1_init();

  //  Truncated multiplication like function 'lhs * rhs'

  return res;

}

void onumm1n1_trunc_mul_oo_to(  onumm1n1_t* lhs,  onumm1n1_t* rhs, onumm1n1_t* res){
   (*res) = onumm1n1_init();

  //  Truncated multiplication like function 'lhs * rhs'

}

onumm1n1_t onumm1n1_gem_oo(  onumm1n1_t* a,  onumm1n1_t* b,  onumm1n1_t* c){
  onumm1n1_t res;

  //  General multiplication like function 'a * b + c'
  // Real;
  res.r = c->r + a->r * b->r;
  // Order 1;
  res.e1 = c->e1 + a->r * b->e1 + a->e1 * b->r;

  return res;

}

void onumm1n1_gem_oo_to(  onumm1n1_t* a,  onumm1n1_t* b,  onumm1n1_t* c, onumm1n1_t* res){
  //  General multiplication like function 'a * b + c'
  // Real;
  res->r = c->r + a->r * b->r;
  // Order 1;
  res->e1 = c->e1 + a->r * b->e1 + a->e1 * b->r;

}

onumm1n1_t onumm1n1_gem_ro(  coeff_t a,  onumm1n1_t* b,  onumm1n1_t* c){
  onumm1n1_t res;

  //  General multiplication like function 'a * b + c'
  // Real;
  res.r = c->r + a * b->r;
  // Order 1;
  res.e1 = c->e1 + a * b->e1;

  return res;

}

void onumm1n1_gem_ro_to(  coeff_t a,  onumm1n1_t* b,  onumm1n1_t* c, onumm1n1_t* res){
  //  General multiplication like function 'a * b + c'
  // Real;
  res->r = c->r + a * b->r;
  // Order 1;
  res->e1 = c->e1 + a * b->e1;

}

void onumm1n1_trunc_gem_oo_to( ord_t ord_lhs,  onumm1n1_t* a,  ord_t ord_rhs,  onumm1n1_t* b,  onumm1n1_t* c, onumm1n1_t* res){
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
          break;
      }
      break;
    case 1:
      switch( ord_rhs ){
        case 0:
          // res order: 1
          res->e1 = c->e1 + a->e1 * b->r;
          break;
      }
      break;
  }

}

void onumm1n1_trunc_sum_oo_to(ord_t order, onumm1n1_t* lhs,onumm1n1_t* rhs, onumm1n1_t* res){
  // Addition like function 'lhs + rhs'
  switch(order){
    case(0):
      //  Real
      res->r = lhs->r + rhs->r;
      break;
    case(1):    // Order 1
      res->e1 = lhs->e1 + rhs->e1;
      break;
  }
}

void onumm1n1_trunc_sub_oo_to(ord_t order, onumm1n1_t* lhs,onumm1n1_t* rhs, onumm1n1_t* res){
  // Addition like function 'lhs - rhs'
  switch(order){
    case(0):
      //  Real
      res->r = lhs->r - rhs->r;
      break;
    case(1):    // Order 1
      res->e1 = lhs->e1 - rhs->e1;
      break;
  }
}

onumm1n1_t onumm1n1_feval(coeff_t* feval_re, onumm1n1_t* x){

  onumm1n1_t res;

  // feval function
  //  Definitions
  coeff_t factor=1, coef = 0;
  onumm1n1_t deltax = (*x), deltax_power = (*x);
  deltax.r = 0.0;
  deltax_power.r = 0.0;
  onumm1n1_set_r(0.0, &res);
  //  Real
  res.r = feval_re[0];
  // Order 1
  factor *=1;
  coef    = feval_re[1]/ factor;;
  onumm1n1_gem_ro_to( coef, &deltax_power, &res, &res);

  return res;

}

void onumm1n1_feval_to(coeff_t* feval_re, onumm1n1_t* x, onumm1n1_t* res){

  // feval function
  //  Definitions
  coeff_t factor=1, coef = 0;
  onumm1n1_t deltax = (*x), deltax_power = (*x);
  deltax.r = 0.0;
  deltax_power.r = 0.0;
  onumm1n1_set_r(0.0, res);
  //  Real
  res->r = feval_re[0];
  // Order 1
  factor *=1;
  coef    = feval_re[1]/ factor;;
  onumm1n1_gem_ro_to( coef, &deltax_power, res, res);

}

