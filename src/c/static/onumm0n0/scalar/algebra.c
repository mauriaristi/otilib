
// Division.

// ****************************************************************************************************
onumm0n0_t onumm0n0_div_ro(coeff_t num, onumm0n0_t* den){

    
    onumm0n0_t inv = onumm0n0_pow(den,-1);
    onumm0n0_t res = onumm0n0_mul_ro(num,&inv);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
onumm0n0_t onumm0n0_div_oo(onumm0n0_t* num, onumm0n0_t* den){

    
    onumm0n0_t inv = onumm0n0_init();
    onumm0n0_pow_to(den,-1,&inv);
    onumm0n0_t res = onumm0n0_mul_oo(num,&inv);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
onumm0n0_t onumm0n0_div_or(onumm0n0_t* num, coeff_t val){

    return onumm0n0_mul_ro(1.0/val,num);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
onumm0n0_t onumm0n0_abs(onumm0n0_t* num){

	onumm0n0_t res;
    onumm0n0_abs_to(num,&res);
    return res;

}
// ----------------------------------------------------------------------------------------------------

onumm0n0_t onumm0n0_neg(  onumm0n0_t* lhs){

  onumm0n0_t res;

  // Negation like function '-lhs'
  // Real;
  res.r = -lhs->r;

  return res;

}

void onumm0n0_neg_to(  onumm0n0_t* lhs, onumm0n0_t* res){

  // Negation like function '-lhs'
  // Real;
  res->r = -lhs->r;

}

onumm0n0_t onumm0n0_sum_oo(  onumm0n0_t* lhs,  onumm0n0_t* rhs){
  onumm0n0_t res;

  // Addition like function 'lhs + rhs'
  //  Real
  res.r = lhs->r + rhs->r;

  return res;

}

void onumm0n0_sum_oo_to(  onumm0n0_t* lhs,  onumm0n0_t* rhs, onumm0n0_t* res){
  // Addition like function 'lhs + rhs'
  //  Real
  res->r = lhs->r + rhs->r;

}

onumm0n0_t onumm0n0_sum_ro(  coeff_t lhs,  onumm0n0_t* rhs){
  onumm0n0_t res;

  // Addition like function 'lhs + rhs'
  // Real;
  res.r = lhs + rhs->r;

  return res;

}

void onumm0n0_sum_ro_to(  coeff_t lhs,  onumm0n0_t* rhs, onumm0n0_t* res){
  // Addition like function 'lhs + rhs'
  // Real;
  res->r = lhs + rhs->r;

}

onumm0n0_t onumm0n0_sub_oo(  onumm0n0_t* lhs,  onumm0n0_t* rhs){
  onumm0n0_t res;

  // Addition like function 'lhs - rhs'
  //  Real
  res.r = lhs->r - rhs->r;

  return res;

}

void onumm0n0_sub_oo_to(  onumm0n0_t* lhs,  onumm0n0_t* rhs, onumm0n0_t* res){
  // Addition like function 'lhs - rhs'
  //  Real
  res->r = lhs->r - rhs->r;

}

onumm0n0_t onumm0n0_sub_ro(  coeff_t lhs,  onumm0n0_t* rhs){
  onumm0n0_t res;

  // Addition like function 'lhs - rhs'
  // Real;
  res.r = lhs - rhs->r;

  return res;

}

void onumm0n0_sub_ro_to(  coeff_t lhs,  onumm0n0_t* rhs, onumm0n0_t* res){
  // Addition like function 'lhs - rhs'
  // Real;
  res->r = lhs - rhs->r;

}

onumm0n0_t onumm0n0_sub_or(  onumm0n0_t* lhs,  coeff_t rhs){
  onumm0n0_t res;

  // Addition like function 'lhs - rhs'
  // Real;
  res.r = lhs->r - rhs;

  return res;

}

void onumm0n0_sub_or_to(  onumm0n0_t* lhs,  coeff_t rhs, onumm0n0_t* res){
  // Addition like function 'lhs - rhs'
  // Real;
  res->r = lhs->r - rhs;

}

onumm0n0_t onumm0n0_mul_oo(  onumm0n0_t* lhs,  onumm0n0_t* rhs){
  onumm0n0_t res;

  //  Multiplication like function 'lhs * rhs'
  // Real;
  res.r = lhs->r * rhs->r;

  return res;

}

void onumm0n0_mul_oo_to(  onumm0n0_t* lhs,  onumm0n0_t* rhs, onumm0n0_t* res){
  //  Multiplication like function 'lhs * rhs'
  // Real;
  res->r = lhs->r * rhs->r;

}

onumm0n0_t onumm0n0_mul_ro(  coeff_t lhs,  onumm0n0_t* rhs){
  onumm0n0_t res;

  // Multiplication like function 'lhs * rhs'
  //  Real;
  res.r = lhs * rhs->r;

  return res;

}

void onumm0n0_mul_ro_to(  coeff_t lhs,  onumm0n0_t* rhs, onumm0n0_t* res){
  // Multiplication like function 'lhs * rhs'
  //  Real;
  res->r = lhs * rhs->r;

}

onumm0n0_t onumm0n0_trunc_mul_oo(  onumm0n0_t* lhs,  onumm0n0_t* rhs){
  onumm0n0_t res;

  res = onumm0n0_init();

  //  Truncated multiplication like function 'lhs * rhs'

  return res;

}

void onumm0n0_trunc_mul_oo_to(  onumm0n0_t* lhs,  onumm0n0_t* rhs, onumm0n0_t* res){
   (*res) = onumm0n0_init();

  //  Truncated multiplication like function 'lhs * rhs'

}

onumm0n0_t onumm0n0_gem_oo(  onumm0n0_t* a,  onumm0n0_t* b,  onumm0n0_t* c){
  onumm0n0_t res;

  //  General multiplication like function 'a * b + c'
  // Real;
  res.r = c->r + a->r * b->r;

  return res;

}

void onumm0n0_gem_oo_to(  onumm0n0_t* a,  onumm0n0_t* b,  onumm0n0_t* c, onumm0n0_t* res){
  //  General multiplication like function 'a * b + c'
  // Real;
  res->r = c->r + a->r * b->r;

}

onumm0n0_t onumm0n0_gem_ro(  coeff_t a,  onumm0n0_t* b,  onumm0n0_t* c){
  onumm0n0_t res;

  //  General multiplication like function 'a * b + c'
  // Real;
  res.r = c->r + a * b->r;

  return res;

}

void onumm0n0_gem_ro_to(  coeff_t a,  onumm0n0_t* b,  onumm0n0_t* c, onumm0n0_t* res){
  //  General multiplication like function 'a * b + c'
  // Real;
  res->r = c->r + a * b->r;

}

void onumm0n0_trunc_gem_oo_to( ord_t ord_lhs,  onumm0n0_t* a,  ord_t ord_rhs,  onumm0n0_t* b,  onumm0n0_t* c, onumm0n0_t* res){
  //  General multiplication like function 'a * b + c'
  switch( ord_lhs ){
    case 0:
      switch( ord_rhs ){
        case 0:
          // res order: 0
          res->r = c->r + a->r * b->r;
          break;
      }
      break;
  }

}

onumm0n0_t onumm0n0_feval(coeff_t* feval_re, onumm0n0_t* x){

  onumm0n0_t res;

  // feval function
  //  Definitions
  coeff_t factor=1, coef = 0;
  onumm0n0_t deltax = (*x), deltax_power = (*x);
  deltax.r = 0.0;
  deltax_power.r = 0.0;
  onumm0n0_set_r(0.0, &res);
  //  Real
  res.r = feval_re[0];

  return res;

}

void onumm0n0_feval_to(coeff_t* feval_re, onumm0n0_t* x, onumm0n0_t* res){

  // feval function
  //  Definitions
  coeff_t factor=1, coef = 0;
  onumm0n0_t deltax = (*x), deltax_power = (*x);
  deltax.r = 0.0;
  deltax_power.r = 0.0;
  onumm0n0_set_r(0.0, res);
  //  Real
  res->r = feval_re[0];

}

