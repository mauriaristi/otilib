
// Division.

// ****************************************************************************************************
mdnum1_t mdnum1_div_ro(coeff_t num, mdnum1_t* den){

    
    mdnum1_t inv = mdnum1_pow(den,-1);
    mdnum1_t res = mdnum1_mul_ro(num,&inv);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdnum1_t mdnum1_div_oo(mdnum1_t* num, mdnum1_t* den){

    
    mdnum1_t inv = mdnum1_init();
    mdnum1_pow_to(den,-1,&inv);
    mdnum1_t res = mdnum1_mul_oo(num,&inv);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdnum1_t mdnum1_div_or(mdnum1_t* num, coeff_t val){

    return mdnum1_mul_ro(1.0/val,num);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
mdnum1_t mdnum1_abs(mdnum1_t* num){

	mdnum1_t res;
    mdnum1_abs_to(num,&res);
    return res;

}
// ----------------------------------------------------------------------------------------------------

mdnum1_t mdnum1_neg(  mdnum1_t* lhs){

  mdnum1_t res;

  // Negation like function '-lhs'
  // Real;
  res.r = -lhs->r;
  // Order 1;
  res.e1 = -lhs->e1;

  return res;

}

void mdnum1_neg_to(  mdnum1_t* lhs, mdnum1_t* res){

  // Negation like function '-lhs'
  // Real;
  res->r = -lhs->r;
  // Order 1;
  res->e1 = -lhs->e1;

}

mdnum1_t mdnum1_sum_oo(  mdnum1_t* lhs,  mdnum1_t* rhs){
  mdnum1_t res;

  // Addition like function 'lhs + rhs'
  //  Real
  res.r = lhs->r + rhs->r;
  // Order 1
  res.e1 = lhs->e1 + rhs->e1;

  return res;

}

void mdnum1_sum_oo_to(  mdnum1_t* lhs,  mdnum1_t* rhs, mdnum1_t* res){
  // Addition like function 'lhs + rhs'
  //  Real
  res->r = lhs->r + rhs->r;
  // Order 1
  res->e1 = lhs->e1 + rhs->e1;

}

mdnum1_t mdnum1_sum_ro(  coeff_t lhs,  mdnum1_t* rhs){
  mdnum1_t res;

  // Addition like function 'lhs + rhs'
  // Real;
  res.r = lhs + rhs->r;
  // Order 1;
  res.e1 =  + rhs->e1;

  return res;

}

void mdnum1_sum_ro_to(  coeff_t lhs,  mdnum1_t* rhs, mdnum1_t* res){
  // Addition like function 'lhs + rhs'
  // Real;
  res->r = lhs + rhs->r;
  // Order 1;
  res->e1 =  + rhs->e1;

}

mdnum1_t mdnum1_sub_oo(  mdnum1_t* lhs,  mdnum1_t* rhs){
  mdnum1_t res;

  // Addition like function 'lhs - rhs'
  //  Real
  res.r = lhs->r - rhs->r;
  // Order 1
  res.e1 = lhs->e1 - rhs->e1;

  return res;

}

void mdnum1_sub_oo_to(  mdnum1_t* lhs,  mdnum1_t* rhs, mdnum1_t* res){
  // Addition like function 'lhs - rhs'
  //  Real
  res->r = lhs->r - rhs->r;
  // Order 1
  res->e1 = lhs->e1 - rhs->e1;

}

mdnum1_t mdnum1_sub_ro(  coeff_t lhs,  mdnum1_t* rhs){
  mdnum1_t res;

  // Addition like function 'lhs - rhs'
  // Real;
  res.r = lhs - rhs->r;
  // Order 1;
  res.e1 =  - rhs->e1;

  return res;

}

void mdnum1_sub_ro_to(  coeff_t lhs,  mdnum1_t* rhs, mdnum1_t* res){
  // Addition like function 'lhs - rhs'
  // Real;
  res->r = lhs - rhs->r;
  // Order 1;
  res->e1 =  - rhs->e1;

}

mdnum1_t mdnum1_sub_or(  mdnum1_t* lhs,  coeff_t rhs){
  mdnum1_t res;

  // Addition like function 'lhs - rhs'
  // Real;
  res.r = lhs->r - rhs;
  // Order 1;
  res.e1 = lhs->e1;

  return res;

}

void mdnum1_sub_or_to(  mdnum1_t* lhs,  coeff_t rhs, mdnum1_t* res){
  // Addition like function 'lhs - rhs'
  // Real;
  res->r = lhs->r - rhs;
  // Order 1;
  res->e1 = lhs->e1;

}

mdnum1_t mdnum1_mul_oo(  mdnum1_t* lhs,  mdnum1_t* rhs){
  mdnum1_t res;

  //  Multiplication like function 'lhs * rhs'
  // Real;
  res.r = lhs->r * rhs->r;
  // Order 1;
  res.e1 = lhs->r * rhs->e1 + lhs->e1 * rhs->r;

  return res;

}

void mdnum1_mul_oo_to(  mdnum1_t* lhs,  mdnum1_t* rhs, mdnum1_t* res){
  //  Multiplication like function 'lhs * rhs'
  // Real;
  res->r = lhs->r * rhs->r;
  // Order 1;
  res->e1 = lhs->r * rhs->e1 + lhs->e1 * rhs->r;

}

mdnum1_t mdnum1_mul_ro(  coeff_t lhs,  mdnum1_t* rhs){
  mdnum1_t res;

  // Multiplication like function 'lhs * rhs'
  //  Real;
  res.r = lhs * rhs->r;
  // Order 1;
  res.e1 = lhs * rhs->e1;

  return res;

}

void mdnum1_mul_ro_to(  coeff_t lhs,  mdnum1_t* rhs, mdnum1_t* res){
  // Multiplication like function 'lhs * rhs'
  //  Real;
  res->r = lhs * rhs->r;
  // Order 1;
  res->e1 = lhs * rhs->e1;

}

mdnum1_t mdnum1_trunc_mul_oo(  mdnum1_t* lhs,  mdnum1_t* rhs){
  mdnum1_t res;

  res = mdnum1_init();

  //  Truncated multiplication like function 'lhs * rhs'

  return res;

}

void mdnum1_trunc_mul_oo_to(  mdnum1_t* lhs,  mdnum1_t* rhs, mdnum1_t* res){
   (*res) = mdnum1_init();

  //  Truncated multiplication like function 'lhs * rhs'

}

mdnum1_t mdnum1_gem_oo(  mdnum1_t* a,  mdnum1_t* b,  mdnum1_t* c){
  mdnum1_t res;

  //  General multiplication like function 'a * b + c'
  // Real;
  res.r = c->r + a->r * b->r;
  // Order 1;
  res.e1 = c->e1 + a->r * b->e1 + a->e1 * b->r;

  return res;

}

void mdnum1_gem_oo_to(  mdnum1_t* a,  mdnum1_t* b,  mdnum1_t* c, mdnum1_t* res){
  //  General multiplication like function 'a * b + c'
  // Real;
  res->r = c->r + a->r * b->r;
  // Order 1;
  res->e1 = c->e1 + a->r * b->e1 + a->e1 * b->r;

}

mdnum1_t mdnum1_gem_ro(  coeff_t a,  mdnum1_t* b,  mdnum1_t* c){
  mdnum1_t res;

  //  General multiplication like function 'a * b + c'
  // Real;
  res.r = c->r + a * b->r;
  // Order 1;
  res.e1 = c->e1 + a * b->e1;

  return res;

}

void mdnum1_gem_ro_to(  coeff_t a,  mdnum1_t* b,  mdnum1_t* c, mdnum1_t* res){
  //  General multiplication like function 'a * b + c'
  // Real;
  res->r = c->r + a * b->r;
  // Order 1;
  res->e1 = c->e1 + a * b->e1;

}

void mdnum1_trunc_gem_oo_to( ord_t ord_lhs,  mdnum1_t* a,  ord_t ord_rhs,  mdnum1_t* b,  mdnum1_t* c, mdnum1_t* res){
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

void mdnum1_trunc_sum_oo_to(ord_t order, mdnum1_t* lhs,mdnum1_t* rhs, mdnum1_t* res){
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

void mdnum1_trunc_sub_oo_to(ord_t order, mdnum1_t* lhs,mdnum1_t* rhs, mdnum1_t* res){
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

mdnum1_t mdnum1_feval(coeff_t* feval_re, mdnum1_t* x){

  mdnum1_t res;

  // feval function
  //  Definitions
  coeff_t factor=1, coef = 0;
  mdnum1_t deltax = (*x), deltax_power = (*x);
  deltax.r = 0.0;
  deltax_power.r = 0.0;
  mdnum1_set_r(0.0, &res);
  //  Real
  res.r = feval_re[0];
  // Order 1
  factor *=1;
  coef    = feval_re[1]/ factor;;
  mdnum1_gem_ro_to( coef, &deltax_power, &res, &res);

  return res;

}

void mdnum1_feval_to(coeff_t* feval_re, mdnum1_t* x, mdnum1_t* res){

  // feval function
  //  Definitions
  coeff_t factor=1, coef = 0;
  mdnum1_t deltax = (*x), deltax_power = (*x);
  deltax.r = 0.0;
  deltax_power.r = 0.0;
  mdnum1_set_r(0.0, res);
  //  Real
  res->r = feval_re[0];
  // Order 1
  factor *=1;
  coef    = feval_re[1]/ factor;;
  mdnum1_gem_ro_to( coef, &deltax_power, res, res);

}

