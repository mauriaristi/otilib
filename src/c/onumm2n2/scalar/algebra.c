
// Division.

// ****************************************************************************************************
onumm2n2_t onumm2n2_div_ro(coeff_t num, onumm2n2_t* den){

    
    onumm2n2_t inv = onumm2n2_pow(den,-1);
    onumm2n2_t res = onumm2n2_mul_ro(num,&inv);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
onumm2n2_t onumm2n2_div_oo(onumm2n2_t* num, onumm2n2_t* den){

    
    onumm2n2_t inv = onumm2n2_init();
    onumm2n2_pow_to(den,-1,&inv);
    onumm2n2_t res = onumm2n2_mul_oo(num,&inv);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
onumm2n2_t onumm2n2_div_or(onumm2n2_t* num, coeff_t val){

    return onumm2n2_mul_ro(1.0/val,num);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
onumm2n2_t onumm2n2_abs(onumm2n2_t* num){

	onumm2n2_t res;
    onumm2n2_abs_to(num,&res);
    return res;

}
// ----------------------------------------------------------------------------------------------------

onumm2n2_t onumm2n2_neg(  onumm2n2_t* lhs){

  onumm2n2_t res;

  // Negation like function '-lhs'
  // Real;
  res.r = -lhs->r;
  // Order 1;
  res.e1 = -lhs->e1;
  res.e2 = -lhs->e2;
  // Order 2;
  res.e11 = -lhs->e11;
  res.e12 = -lhs->e12;
  res.e22 = -lhs->e22;

  return res;

}

void onumm2n2_neg_to(  onumm2n2_t* lhs, onumm2n2_t* res){

  // Negation like function '-lhs'
  // Real;
  res->r = -lhs->r;
  // Order 1;
  res->e1 = -lhs->e1;
  res->e2 = -lhs->e2;
  // Order 2;
  res->e11 = -lhs->e11;
  res->e12 = -lhs->e12;
  res->e22 = -lhs->e22;

}

onumm2n2_t onumm2n2_sum_oo(  onumm2n2_t* lhs,  onumm2n2_t* rhs){
  onumm2n2_t res;

  // Addition like function 'lhs + rhs'
  //  Real
  res.r = lhs->r + rhs->r;
  // Order 1
  res.e1 = lhs->e1 + rhs->e1;
  res.e2 = lhs->e2 + rhs->e2;
  // Order 2
  res.e11 = lhs->e11 + rhs->e11;
  res.e12 = lhs->e12 + rhs->e12;
  res.e22 = lhs->e22 + rhs->e22;

  return res;

}

void onumm2n2_sum_oo_to(  onumm2n2_t* lhs,  onumm2n2_t* rhs, onumm2n2_t* res){
  // Addition like function 'lhs + rhs'
  //  Real
  res->r = lhs->r + rhs->r;
  // Order 1
  res->e1 = lhs->e1 + rhs->e1;
  res->e2 = lhs->e2 + rhs->e2;
  // Order 2
  res->e11 = lhs->e11 + rhs->e11;
  res->e12 = lhs->e12 + rhs->e12;
  res->e22 = lhs->e22 + rhs->e22;

}

onumm2n2_t onumm2n2_sum_ro(  coeff_t lhs,  onumm2n2_t* rhs){
  onumm2n2_t res;

  // Addition like function 'lhs + rhs'
  // Real;
  res.r = lhs + rhs->r;
  // Order 1;
  res.e1 =  + rhs->e1;
  res.e2 =  + rhs->e2;
  // Order 2;
  res.e11 =  + rhs->e11;
  res.e12 =  + rhs->e12;
  res.e22 =  + rhs->e22;

  return res;

}

void onumm2n2_sum_ro_to(  coeff_t lhs,  onumm2n2_t* rhs, onumm2n2_t* res){
  // Addition like function 'lhs + rhs'
  // Real;
  res->r = lhs + rhs->r;
  // Order 1;
  res->e1 =  + rhs->e1;
  res->e2 =  + rhs->e2;
  // Order 2;
  res->e11 =  + rhs->e11;
  res->e12 =  + rhs->e12;
  res->e22 =  + rhs->e22;

}

onumm2n2_t onumm2n2_sub_oo(  onumm2n2_t* lhs,  onumm2n2_t* rhs){
  onumm2n2_t res;

  // Addition like function 'lhs - rhs'
  //  Real
  res.r = lhs->r - rhs->r;
  // Order 1
  res.e1 = lhs->e1 - rhs->e1;
  res.e2 = lhs->e2 - rhs->e2;
  // Order 2
  res.e11 = lhs->e11 - rhs->e11;
  res.e12 = lhs->e12 - rhs->e12;
  res.e22 = lhs->e22 - rhs->e22;

  return res;

}

void onumm2n2_sub_oo_to(  onumm2n2_t* lhs,  onumm2n2_t* rhs, onumm2n2_t* res){
  // Addition like function 'lhs - rhs'
  //  Real
  res->r = lhs->r - rhs->r;
  // Order 1
  res->e1 = lhs->e1 - rhs->e1;
  res->e2 = lhs->e2 - rhs->e2;
  // Order 2
  res->e11 = lhs->e11 - rhs->e11;
  res->e12 = lhs->e12 - rhs->e12;
  res->e22 = lhs->e22 - rhs->e22;

}

onumm2n2_t onumm2n2_sub_ro(  coeff_t lhs,  onumm2n2_t* rhs){
  onumm2n2_t res;

  // Addition like function 'lhs - rhs'
  // Real;
  res.r = lhs - rhs->r;
  // Order 1;
  res.e1 =  - rhs->e1;
  res.e2 =  - rhs->e2;
  // Order 2;
  res.e11 =  - rhs->e11;
  res.e12 =  - rhs->e12;
  res.e22 =  - rhs->e22;

  return res;

}

void onumm2n2_sub_ro_to(  coeff_t lhs,  onumm2n2_t* rhs, onumm2n2_t* res){
  // Addition like function 'lhs - rhs'
  // Real;
  res->r = lhs - rhs->r;
  // Order 1;
  res->e1 =  - rhs->e1;
  res->e2 =  - rhs->e2;
  // Order 2;
  res->e11 =  - rhs->e11;
  res->e12 =  - rhs->e12;
  res->e22 =  - rhs->e22;

}

onumm2n2_t onumm2n2_sub_or(  onumm2n2_t* lhs,  coeff_t rhs){
  onumm2n2_t res;

  // Addition like function 'lhs - rhs'
  // Real;
  res.r = lhs->r - rhs;
  // Order 1;
  res.e1 = lhs->e1;
  res.e2 = lhs->e2;
  // Order 2;
  res.e11 = lhs->e11;
  res.e12 = lhs->e12;
  res.e22 = lhs->e22;

  return res;

}

void onumm2n2_sub_or_to(  onumm2n2_t* lhs,  coeff_t rhs, onumm2n2_t* res){
  // Addition like function 'lhs - rhs'
  // Real;
  res->r = lhs->r - rhs;
  // Order 1;
  res->e1 = lhs->e1;
  res->e2 = lhs->e2;
  // Order 2;
  res->e11 = lhs->e11;
  res->e12 = lhs->e12;
  res->e22 = lhs->e22;

}

onumm2n2_t onumm2n2_mul_oo(  onumm2n2_t* lhs,  onumm2n2_t* rhs){
  onumm2n2_t res;

  //  Multiplication like function 'lhs * rhs'
  // Real;
  res.r = lhs->r * rhs->r;
  // Order 1;
  res.e1 = lhs->r * rhs->e1 + lhs->e1 * rhs->r;
  res.e2 = lhs->r * rhs->e2 + lhs->e2 * rhs->r;
  // Order 2;
  res.e11 = lhs->r * rhs->e11 + lhs->e11 * rhs->r + lhs->e1 * rhs->e1;
  res.e12 = lhs->r * rhs->e12 + lhs->e12 * rhs->r + lhs->e1 * rhs->e2 
          + lhs->e2 * rhs->e1;
  res.e22 = lhs->r * rhs->e22 + lhs->e22 * rhs->r + lhs->e2 * rhs->e2;

  return res;

}

void onumm2n2_mul_oo_to(  onumm2n2_t* lhs,  onumm2n2_t* rhs, onumm2n2_t* res){
  //  Multiplication like function 'lhs * rhs'
  // Real;
  res->r = lhs->r * rhs->r;
  // Order 1;
  res->e1 = lhs->r * rhs->e1 + lhs->e1 * rhs->r;
  res->e2 = lhs->r * rhs->e2 + lhs->e2 * rhs->r;
  // Order 2;
  res->e11 = lhs->r * rhs->e11 + lhs->e11 * rhs->r + lhs->e1 * rhs->e1;
  res->e12 = lhs->r * rhs->e12 + lhs->e12 * rhs->r + lhs->e1 * rhs->e2 
          + lhs->e2 * rhs->e1;
  res->e22 = lhs->r * rhs->e22 + lhs->e22 * rhs->r + lhs->e2 * rhs->e2;

}

onumm2n2_t onumm2n2_mul_ro(  coeff_t lhs,  onumm2n2_t* rhs){
  onumm2n2_t res;

  // Multiplication like function 'lhs * rhs'
  //  Real;
  res.r = lhs * rhs->r;
  // Order 1;
  res.e1 = lhs * rhs->e1;
  res.e2 = lhs * rhs->e2;
  // Order 2;
  res.e11 = lhs * rhs->e11;
  res.e12 = lhs * rhs->e12;
  res.e22 = lhs * rhs->e22;

  return res;

}

void onumm2n2_mul_ro_to(  coeff_t lhs,  onumm2n2_t* rhs, onumm2n2_t* res){
  // Multiplication like function 'lhs * rhs'
  //  Real;
  res->r = lhs * rhs->r;
  // Order 1;
  res->e1 = lhs * rhs->e1;
  res->e2 = lhs * rhs->e2;
  // Order 2;
  res->e11 = lhs * rhs->e11;
  res->e12 = lhs * rhs->e12;
  res->e22 = lhs * rhs->e22;

}

onumm2n2_t onumm2n2_trunc_mul_oo(  onumm2n2_t* lhs,  onumm2n2_t* rhs){
  onumm2n2_t res;

  res = onumm2n2_init();

  //  Truncated multiplication like function 'lhs * rhs'
  // Order 2;
  res.e11 =  + lhs->e1 * rhs->e1;
  res.e12 =  + lhs->e1 * rhs->e2 + lhs->e2 * rhs->e1;
  res.e22 =  + lhs->e2 * rhs->e2;

  return res;

}

void onumm2n2_trunc_mul_oo_to(  onumm2n2_t* lhs,  onumm2n2_t* rhs, onumm2n2_t* res){
   (*res) = onumm2n2_init();

  //  Truncated multiplication like function 'lhs * rhs'
  // Order 2;
  res->e11 =  + lhs->e1 * rhs->e1;
  res->e12 =  + lhs->e1 * rhs->e2 + lhs->e2 * rhs->e1;
  res->e22 =  + lhs->e2 * rhs->e2;

}

onumm2n2_t onumm2n2_gem_oo(  onumm2n2_t* a,  onumm2n2_t* b,  onumm2n2_t* c){
  onumm2n2_t res;

  //  General multiplication like function 'a * b + c'
  // Real;
  res.r = c->r + a->r * b->r;
  // Order 1;
  res.e1 = c->e1 + a->r * b->e1 + a->e1 * b->r;
  res.e2 = c->e2 + a->r * b->e2 + a->e2 * b->r;
  // Order 2;
  res.e11 = c->e11 + a->r * b->e11 + a->e11 * b->r + a->e1 * b->e1;
  res.e12 = c->e12 + a->r * b->e12 + a->e12 * b->r + a->e1 * b->e2 
          + a->e2 * b->e1;
  res.e22 = c->e22 + a->r * b->e22 + a->e22 * b->r + a->e2 * b->e2;

  return res;

}

void onumm2n2_gem_oo_to(  onumm2n2_t* a,  onumm2n2_t* b,  onumm2n2_t* c, onumm2n2_t* res){
  //  General multiplication like function 'a * b + c'
  // Real;
  res->r = c->r + a->r * b->r;
  // Order 1;
  res->e1 = c->e1 + a->r * b->e1 + a->e1 * b->r;
  res->e2 = c->e2 + a->r * b->e2 + a->e2 * b->r;
  // Order 2;
  res->e11 = c->e11 + a->r * b->e11 + a->e11 * b->r + a->e1 * b->e1;
  res->e12 = c->e12 + a->r * b->e12 + a->e12 * b->r + a->e1 * b->e2 
          + a->e2 * b->e1;
  res->e22 = c->e22 + a->r * b->e22 + a->e22 * b->r + a->e2 * b->e2;

}

onumm2n2_t onumm2n2_gem_ro(  coeff_t a,  onumm2n2_t* b,  onumm2n2_t* c){
  onumm2n2_t res;

  //  General multiplication like function 'a * b + c'
  // Real;
  res.r = c->r + a * b->r;
  // Order 1;
  res.e1 = c->e1 + a * b->e1;
  res.e2 = c->e2 + a * b->e2;
  // Order 2;
  res.e11 = c->e11 + a * b->e11;
  res.e12 = c->e12 + a * b->e12;
  res.e22 = c->e22 + a * b->e22;

  return res;

}

void onumm2n2_gem_ro_to(  coeff_t a,  onumm2n2_t* b,  onumm2n2_t* c, onumm2n2_t* res){
  //  General multiplication like function 'a * b + c'
  // Real;
  res->r = c->r + a * b->r;
  // Order 1;
  res->e1 = c->e1 + a * b->e1;
  res->e2 = c->e2 + a * b->e2;
  // Order 2;
  res->e11 = c->e11 + a * b->e11;
  res->e12 = c->e12 + a * b->e12;
  res->e22 = c->e22 + a * b->e22;

}

onumm2n2_t onumm2n2_feval(coeff_t* feval_re, onumm2n2_t* x){

  onumm2n2_t res;

  // feval function
  //  Definitions
  coeff_t factor=1, coef = 0;
  onumm2n2_t deltax = (*x), deltax_power = (*x);
  deltax.r = 0.0;
  deltax_power.r = 0.0;
  onumm2n2_set_r(0.0, &res);
  //  Real
  res.r = feval_re[0];
  // Order 1
  factor *=1;
  coef    = feval_re[1]/ factor;;
  onumm2n2_gem_ro_to( coef, &deltax_power, &res, &res);
  deltax_power = onumm2n2_mul_oo(&deltax_power,&deltax);
  // Order 2
  factor *=2;
  coef    = feval_re[2]/ factor;;
  onumm2n2_gem_ro_to( coef, &deltax_power, &res, &res);

  return res;

}

void onumm2n2_feval_to(coeff_t* feval_re, onumm2n2_t* x, onumm2n2_t* res){

  // feval function
  //  Definitions
  coeff_t factor=1, coef = 0;
  onumm2n2_t deltax = (*x), deltax_power = (*x);
  deltax.r = 0.0;
  deltax_power.r = 0.0;
  onumm2n2_set_r(0.0, res);
  //  Real
  res->r = feval_re[0];
  // Order 1
  factor *=1;
  coef    = feval_re[1]/ factor;;
  onumm2n2_gem_ro_to( coef, &deltax_power, res, res);
  deltax_power = onumm2n2_mul_oo(&deltax_power,&deltax);
  // Order 2
  factor *=2;
  coef    = feval_re[2]/ factor;;
  onumm2n2_gem_ro_to( coef, &deltax_power, res, res);

}

