
// Division.

// ****************************************************************************************************
onumm1n3_t onumm1n3_div_ro(coeff_t num, onumm1n3_t* den){

    
    onumm1n3_t inv = onumm1n3_pow(den,-1);
    onumm1n3_t res = onumm1n3_mul_ro(num,&inv);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
onumm1n3_t onumm1n3_div_oo(onumm1n3_t* num, onumm1n3_t* den){

    
    onumm1n3_t inv = onumm1n3_init();
    onumm1n3_pow_to(den,-1,&inv);
    onumm1n3_t res = onumm1n3_mul_oo(num,&inv);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
onumm1n3_t onumm1n3_div_or(onumm1n3_t* num, coeff_t val){

    return onumm1n3_mul_ro(1.0/val,num);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
onumm1n3_t onumm1n3_abs(onumm1n3_t* num){

	onumm1n3_t res;
    onumm1n3_abs_to(num,&res);
    return res;

}
// ----------------------------------------------------------------------------------------------------

onumm1n3_t onumm1n3_neg(  onumm1n3_t* lhs){

  onumm1n3_t res;

  // Negation like function '-lhs'
  // Real;
  res.r = -lhs->r;
  // Order 1;
  res.e1 = -lhs->e1;
  // Order 2;
  res.e11 = -lhs->e11;
  // Order 3;
  res.e111 = -lhs->e111;

  return res;

}

void onumm1n3_neg_to(  onumm1n3_t* lhs, onumm1n3_t* res){

  // Negation like function '-lhs'
  // Real;
  res->r = -lhs->r;
  // Order 1;
  res->e1 = -lhs->e1;
  // Order 2;
  res->e11 = -lhs->e11;
  // Order 3;
  res->e111 = -lhs->e111;

}

onumm1n3_t onumm1n3_sum_oo(  onumm1n3_t* lhs,  onumm1n3_t* rhs){
  onumm1n3_t res;

  // Addition like function 'lhs + rhs'
  //  Real
  res.r = lhs->r + rhs->r;
  // Order 1
  res.e1 = lhs->e1 + rhs->e1;
  // Order 2
  res.e11 = lhs->e11 + rhs->e11;
  // Order 3
  res.e111 = lhs->e111 + rhs->e111;

  return res;

}

void onumm1n3_sum_oo_to(  onumm1n3_t* lhs,  onumm1n3_t* rhs, onumm1n3_t* res){
  // Addition like function 'lhs + rhs'
  //  Real
  res->r = lhs->r + rhs->r;
  // Order 1
  res->e1 = lhs->e1 + rhs->e1;
  // Order 2
  res->e11 = lhs->e11 + rhs->e11;
  // Order 3
  res->e111 = lhs->e111 + rhs->e111;

}

onumm1n3_t onumm1n3_sum_ro(  coeff_t lhs,  onumm1n3_t* rhs){
  onumm1n3_t res;

  // Addition like function 'lhs + rhs'
  // Real;
  res.r = lhs + rhs->r;
  // Order 1;
  res.e1 =  + rhs->e1;
  // Order 2;
  res.e11 =  + rhs->e11;
  // Order 3;
  res.e111 =  + rhs->e111;

  return res;

}

void onumm1n3_sum_ro_to(  coeff_t lhs,  onumm1n3_t* rhs, onumm1n3_t* res){
  // Addition like function 'lhs + rhs'
  // Real;
  res->r = lhs + rhs->r;
  // Order 1;
  res->e1 =  + rhs->e1;
  // Order 2;
  res->e11 =  + rhs->e11;
  // Order 3;
  res->e111 =  + rhs->e111;

}

onumm1n3_t onumm1n3_sub_oo(  onumm1n3_t* lhs,  onumm1n3_t* rhs){
  onumm1n3_t res;

  // Addition like function 'lhs - rhs'
  //  Real
  res.r = lhs->r - rhs->r;
  // Order 1
  res.e1 = lhs->e1 - rhs->e1;
  // Order 2
  res.e11 = lhs->e11 - rhs->e11;
  // Order 3
  res.e111 = lhs->e111 - rhs->e111;

  return res;

}

void onumm1n3_sub_oo_to(  onumm1n3_t* lhs,  onumm1n3_t* rhs, onumm1n3_t* res){
  // Addition like function 'lhs - rhs'
  //  Real
  res->r = lhs->r - rhs->r;
  // Order 1
  res->e1 = lhs->e1 - rhs->e1;
  // Order 2
  res->e11 = lhs->e11 - rhs->e11;
  // Order 3
  res->e111 = lhs->e111 - rhs->e111;

}

onumm1n3_t onumm1n3_sub_ro(  coeff_t lhs,  onumm1n3_t* rhs){
  onumm1n3_t res;

  // Addition like function 'lhs - rhs'
  // Real;
  res.r = lhs - rhs->r;
  // Order 1;
  res.e1 =  - rhs->e1;
  // Order 2;
  res.e11 =  - rhs->e11;
  // Order 3;
  res.e111 =  - rhs->e111;

  return res;

}

void onumm1n3_sub_ro_to(  coeff_t lhs,  onumm1n3_t* rhs, onumm1n3_t* res){
  // Addition like function 'lhs - rhs'
  // Real;
  res->r = lhs - rhs->r;
  // Order 1;
  res->e1 =  - rhs->e1;
  // Order 2;
  res->e11 =  - rhs->e11;
  // Order 3;
  res->e111 =  - rhs->e111;

}

onumm1n3_t onumm1n3_sub_or(  onumm1n3_t* lhs,  coeff_t rhs){
  onumm1n3_t res;

  // Addition like function 'lhs - rhs'
  // Real;
  res.r = lhs->r - rhs;
  // Order 1;
  res.e1 = lhs->e1;
  // Order 2;
  res.e11 = lhs->e11;
  // Order 3;
  res.e111 = lhs->e111;

  return res;

}

void onumm1n3_sub_or_to(  onumm1n3_t* lhs,  coeff_t rhs, onumm1n3_t* res){
  // Addition like function 'lhs - rhs'
  // Real;
  res->r = lhs->r - rhs;
  // Order 1;
  res->e1 = lhs->e1;
  // Order 2;
  res->e11 = lhs->e11;
  // Order 3;
  res->e111 = lhs->e111;

}

onumm1n3_t onumm1n3_mul_oo(  onumm1n3_t* lhs,  onumm1n3_t* rhs){
  onumm1n3_t res;

  //  Multiplication like function 'lhs * rhs'
  // Real;
  res.r = lhs->r * rhs->r;
  // Order 1;
  res.e1 = lhs->r * rhs->e1 + lhs->e1 * rhs->r;
  // Order 2;
  res.e11 = lhs->r * rhs->e11 + lhs->e11 * rhs->r + lhs->e1 * rhs->e1;
  // Order 3;
  res.e111 = lhs->r * rhs->e111 + lhs->e111 * rhs->r + lhs->e1 * rhs->e11 
           + lhs->e11 * rhs->e1;

  return res;

}

void onumm1n3_mul_oo_to(  onumm1n3_t* lhs,  onumm1n3_t* rhs, onumm1n3_t* res){
  //  Multiplication like function 'lhs * rhs'
  // Real;
  res->r = lhs->r * rhs->r;
  // Order 1;
  res->e1 = lhs->r * rhs->e1 + lhs->e1 * rhs->r;
  // Order 2;
  res->e11 = lhs->r * rhs->e11 + lhs->e11 * rhs->r + lhs->e1 * rhs->e1;
  // Order 3;
  res->e111 = lhs->r * rhs->e111 + lhs->e111 * rhs->r + lhs->e1 * rhs->e11 
           + lhs->e11 * rhs->e1;

}

onumm1n3_t onumm1n3_mul_ro(  coeff_t lhs,  onumm1n3_t* rhs){
  onumm1n3_t res;

  // Multiplication like function 'lhs * rhs'
  //  Real;
  res.r = lhs * rhs->r;
  // Order 1;
  res.e1 = lhs * rhs->e1;
  // Order 2;
  res.e11 = lhs * rhs->e11;
  // Order 3;
  res.e111 = lhs * rhs->e111;

  return res;

}

void onumm1n3_mul_ro_to(  coeff_t lhs,  onumm1n3_t* rhs, onumm1n3_t* res){
  // Multiplication like function 'lhs * rhs'
  //  Real;
  res->r = lhs * rhs->r;
  // Order 1;
  res->e1 = lhs * rhs->e1;
  // Order 2;
  res->e11 = lhs * rhs->e11;
  // Order 3;
  res->e111 = lhs * rhs->e111;

}

onumm1n3_t onumm1n3_trunc_mul_oo(  onumm1n3_t* lhs,  onumm1n3_t* rhs){
  onumm1n3_t res;

  res = onumm1n3_init();

  //  Truncated multiplication like function 'lhs * rhs'
  // Order 2;
  res.e11 =  + lhs->e1 * rhs->e1;
  // Order 3;
  res.e111 =  + lhs->e1 * rhs->e11 + lhs->e11 * rhs->e1;

  return res;

}

void onumm1n3_trunc_mul_oo_to(  onumm1n3_t* lhs,  onumm1n3_t* rhs, onumm1n3_t* res){
   (*res) = onumm1n3_init();

  //  Truncated multiplication like function 'lhs * rhs'
  // Order 2;
  res->e11 =  + lhs->e1 * rhs->e1;
  // Order 3;
  res->e111 =  + lhs->e1 * rhs->e11 + lhs->e11 * rhs->e1;

}

onumm1n3_t onumm1n3_gem_oo(  onumm1n3_t* a,  onumm1n3_t* b,  onumm1n3_t* c){
  onumm1n3_t res;

  //  General multiplication like function 'a * b + c'
  // Real;
  res.r = c->r + a->r * b->r;
  // Order 1;
  res.e1 = c->e1 + a->r * b->e1 + a->e1 * b->r;
  // Order 2;
  res.e11 = c->e11 + a->r * b->e11 + a->e11 * b->r + a->e1 * b->e1;
  // Order 3;
  res.e111 = c->e111 + a->r * b->e111 + a->e111 * b->r + a->e1 * b->e11 
           + a->e11 * b->e1;

  return res;

}

void onumm1n3_gem_oo_to(  onumm1n3_t* a,  onumm1n3_t* b,  onumm1n3_t* c, onumm1n3_t* res){
  //  General multiplication like function 'a * b + c'
  // Real;
  res->r = c->r + a->r * b->r;
  // Order 1;
  res->e1 = c->e1 + a->r * b->e1 + a->e1 * b->r;
  // Order 2;
  res->e11 = c->e11 + a->r * b->e11 + a->e11 * b->r + a->e1 * b->e1;
  // Order 3;
  res->e111 = c->e111 + a->r * b->e111 + a->e111 * b->r + a->e1 * b->e11 
           + a->e11 * b->e1;

}

onumm1n3_t onumm1n3_gem_ro(  coeff_t a,  onumm1n3_t* b,  onumm1n3_t* c){
  onumm1n3_t res;

  //  General multiplication like function 'a * b + c'
  // Real;
  res.r = c->r + a * b->r;
  // Order 1;
  res.e1 = c->e1 + a * b->e1;
  // Order 2;
  res.e11 = c->e11 + a * b->e11;
  // Order 3;
  res.e111 = c->e111 + a * b->e111;

  return res;

}

void onumm1n3_gem_ro_to(  coeff_t a,  onumm1n3_t* b,  onumm1n3_t* c, onumm1n3_t* res){
  //  General multiplication like function 'a * b + c'
  // Real;
  res->r = c->r + a * b->r;
  // Order 1;
  res->e1 = c->e1 + a * b->e1;
  // Order 2;
  res->e11 = c->e11 + a * b->e11;
  // Order 3;
  res->e111 = c->e111 + a * b->e111;

}

onumm1n3_t onumm1n3_feval(coeff_t* feval_re, onumm1n3_t* x){

  onumm1n3_t res;

  // feval function
  //  Definitions
  coeff_t factor=1, coef = 0;
  onumm1n3_t deltax = (*x), deltax_power = (*x);
  deltax.r = 0.0;
  deltax_power.r = 0.0;
  onumm1n3_set_r(0.0, &res);
  //  Real
  res.r = feval_re[0];
  // Order 1
  factor *=1;
  coef    = feval_re[1]/ factor;;
  onumm1n3_gem_ro_to( coef, &deltax_power, &res, &res);
  deltax_power = onumm1n3_mul_oo(&deltax_power,&deltax);
  // Order 2
  factor *=2;
  coef    = feval_re[2]/ factor;;
  onumm1n3_gem_ro_to( coef, &deltax_power, &res, &res);
  deltax_power = onumm1n3_mul_oo(&deltax_power,&deltax);
  // Order 3
  factor *=3;
  coef    = feval_re[3]/ factor;;
  onumm1n3_gem_ro_to( coef, &deltax_power, &res, &res);

  return res;

}

void onumm1n3_feval_to(coeff_t* feval_re, onumm1n3_t* x, onumm1n3_t* res){

  // feval function
  //  Definitions
  coeff_t factor=1, coef = 0;
  onumm1n3_t deltax = (*x), deltax_power = (*x);
  deltax.r = 0.0;
  deltax_power.r = 0.0;
  onumm1n3_set_r(0.0, res);
  //  Real
  res->r = feval_re[0];
  // Order 1
  factor *=1;
  coef    = feval_re[1]/ factor;;
  onumm1n3_gem_ro_to( coef, &deltax_power, res, res);
  deltax_power = onumm1n3_mul_oo(&deltax_power,&deltax);
  // Order 2
  factor *=2;
  coef    = feval_re[2]/ factor;;
  onumm1n3_gem_ro_to( coef, &deltax_power, res, res);
  deltax_power = onumm1n3_mul_oo(&deltax_power,&deltax);
  // Order 3
  factor *=3;
  coef    = feval_re[3]/ factor;;
  onumm1n3_gem_ro_to( coef, &deltax_power, res, res);

}

