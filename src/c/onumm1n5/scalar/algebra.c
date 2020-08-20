
// Division.

// ****************************************************************************************************
onumm1n5_t onumm1n5_div_ro(coeff_t num, onumm1n5_t* den){

    
    onumm1n5_t inv = onumm1n5_pow(den,-1);
    onumm1n5_t res = onumm1n5_mul_ro(num,&inv);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
onumm1n5_t onumm1n5_div_oo(onumm1n5_t* num, onumm1n5_t* den){

    
    onumm1n5_t inv = onumm1n5_init();
    onumm1n5_pow_to(den,-1,&inv);
    onumm1n5_t res = onumm1n5_mul_oo(num,&inv);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
onumm1n5_t onumm1n5_div_or(onumm1n5_t* num, coeff_t val){

    return onumm1n5_mul_ro(1.0/val,num);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
onumm1n5_t onumm1n5_abs(onumm1n5_t* num){

	onumm1n5_t res;
    onumm1n5_abs_to(num,&res);
    return res;

}
// ----------------------------------------------------------------------------------------------------

onumm1n5_t onumm1n5_neg(  onumm1n5_t* lhs){

  onumm1n5_t res;

  // Negation like function '-lhs'
  // Real;
  res.r = -lhs->r;
  // Order 1;
  res.e1 = -lhs->e1;
  // Order 2;
  res.e11 = -lhs->e11;
  // Order 3;
  res.e111 = -lhs->e111;
  // Order 4;
  res.e1111 = -lhs->e1111;
  // Order 5;
  res.e11111 = -lhs->e11111;

  return res;

}

void onumm1n5_neg_to(  onumm1n5_t* lhs, onumm1n5_t* res){

  // Negation like function '-lhs'
  // Real;
  res->r = -lhs->r;
  // Order 1;
  res->e1 = -lhs->e1;
  // Order 2;
  res->e11 = -lhs->e11;
  // Order 3;
  res->e111 = -lhs->e111;
  // Order 4;
  res->e1111 = -lhs->e1111;
  // Order 5;
  res->e11111 = -lhs->e11111;

}

onumm1n5_t onumm1n5_sum_oo(  onumm1n5_t* lhs,  onumm1n5_t* rhs){
  onumm1n5_t res;

  // Addition like function 'lhs + rhs'
  //  Real
  res.r = lhs->r + rhs->r;
  // Order 1
  res.e1 = lhs->e1 + rhs->e1;
  // Order 2
  res.e11 = lhs->e11 + rhs->e11;
  // Order 3
  res.e111 = lhs->e111 + rhs->e111;
  // Order 4
  res.e1111 = lhs->e1111 + rhs->e1111;
  // Order 5
  res.e11111 = lhs->e11111 + rhs->e11111;

  return res;

}

void onumm1n5_sum_oo_to(  onumm1n5_t* lhs,  onumm1n5_t* rhs, onumm1n5_t* res){
  // Addition like function 'lhs + rhs'
  //  Real
  res->r = lhs->r + rhs->r;
  // Order 1
  res->e1 = lhs->e1 + rhs->e1;
  // Order 2
  res->e11 = lhs->e11 + rhs->e11;
  // Order 3
  res->e111 = lhs->e111 + rhs->e111;
  // Order 4
  res->e1111 = lhs->e1111 + rhs->e1111;
  // Order 5
  res->e11111 = lhs->e11111 + rhs->e11111;

}

onumm1n5_t onumm1n5_sum_ro(  coeff_t lhs,  onumm1n5_t* rhs){
  onumm1n5_t res;

  // Addition like function 'lhs + rhs'
  // Real;
  res.r = lhs + rhs->r;
  // Order 1;
  res.e1 =  + rhs->e1;
  // Order 2;
  res.e11 =  + rhs->e11;
  // Order 3;
  res.e111 =  + rhs->e111;
  // Order 4;
  res.e1111 =  + rhs->e1111;
  // Order 5;
  res.e11111 =  + rhs->e11111;

  return res;

}

void onumm1n5_sum_ro_to(  coeff_t lhs,  onumm1n5_t* rhs, onumm1n5_t* res){
  // Addition like function 'lhs + rhs'
  // Real;
  res->r = lhs + rhs->r;
  // Order 1;
  res->e1 =  + rhs->e1;
  // Order 2;
  res->e11 =  + rhs->e11;
  // Order 3;
  res->e111 =  + rhs->e111;
  // Order 4;
  res->e1111 =  + rhs->e1111;
  // Order 5;
  res->e11111 =  + rhs->e11111;

}

onumm1n5_t onumm1n5_sub_oo(  onumm1n5_t* lhs,  onumm1n5_t* rhs){
  onumm1n5_t res;

  // Addition like function 'lhs - rhs'
  //  Real
  res.r = lhs->r - rhs->r;
  // Order 1
  res.e1 = lhs->e1 - rhs->e1;
  // Order 2
  res.e11 = lhs->e11 - rhs->e11;
  // Order 3
  res.e111 = lhs->e111 - rhs->e111;
  // Order 4
  res.e1111 = lhs->e1111 - rhs->e1111;
  // Order 5
  res.e11111 = lhs->e11111 - rhs->e11111;

  return res;

}

void onumm1n5_sub_oo_to(  onumm1n5_t* lhs,  onumm1n5_t* rhs, onumm1n5_t* res){
  // Addition like function 'lhs - rhs'
  //  Real
  res->r = lhs->r - rhs->r;
  // Order 1
  res->e1 = lhs->e1 - rhs->e1;
  // Order 2
  res->e11 = lhs->e11 - rhs->e11;
  // Order 3
  res->e111 = lhs->e111 - rhs->e111;
  // Order 4
  res->e1111 = lhs->e1111 - rhs->e1111;
  // Order 5
  res->e11111 = lhs->e11111 - rhs->e11111;

}

onumm1n5_t onumm1n5_sub_ro(  coeff_t lhs,  onumm1n5_t* rhs){
  onumm1n5_t res;

  // Addition like function 'lhs - rhs'
  // Real;
  res.r = lhs - rhs->r;
  // Order 1;
  res.e1 =  - rhs->e1;
  // Order 2;
  res.e11 =  - rhs->e11;
  // Order 3;
  res.e111 =  - rhs->e111;
  // Order 4;
  res.e1111 =  - rhs->e1111;
  // Order 5;
  res.e11111 =  - rhs->e11111;

  return res;

}

void onumm1n5_sub_ro_to(  coeff_t lhs,  onumm1n5_t* rhs, onumm1n5_t* res){
  // Addition like function 'lhs - rhs'
  // Real;
  res->r = lhs - rhs->r;
  // Order 1;
  res->e1 =  - rhs->e1;
  // Order 2;
  res->e11 =  - rhs->e11;
  // Order 3;
  res->e111 =  - rhs->e111;
  // Order 4;
  res->e1111 =  - rhs->e1111;
  // Order 5;
  res->e11111 =  - rhs->e11111;

}

onumm1n5_t onumm1n5_sub_or(  onumm1n5_t* lhs,  coeff_t rhs){
  onumm1n5_t res;

  // Addition like function 'lhs - rhs'
  // Real;
  res.r = lhs->r - rhs;
  // Order 1;
  res.e1 = lhs->e1;
  // Order 2;
  res.e11 = lhs->e11;
  // Order 3;
  res.e111 = lhs->e111;
  // Order 4;
  res.e1111 = lhs->e1111;
  // Order 5;
  res.e11111 = lhs->e11111;

  return res;

}

void onumm1n5_sub_or_to(  onumm1n5_t* lhs,  coeff_t rhs, onumm1n5_t* res){
  // Addition like function 'lhs - rhs'
  // Real;
  res->r = lhs->r - rhs;
  // Order 1;
  res->e1 = lhs->e1;
  // Order 2;
  res->e11 = lhs->e11;
  // Order 3;
  res->e111 = lhs->e111;
  // Order 4;
  res->e1111 = lhs->e1111;
  // Order 5;
  res->e11111 = lhs->e11111;

}

onumm1n5_t onumm1n5_mul_oo(  onumm1n5_t* lhs,  onumm1n5_t* rhs){
  onumm1n5_t res;

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
  // Order 4;
  res.e1111 = lhs->r * rhs->e1111 + lhs->e1111 * rhs->r + lhs->e1 * rhs->e111 
            + lhs->e111 * rhs->e1 + lhs->e11 * rhs->e11;
  // Order 5;
  res.e11111 = lhs->r * rhs->e11111 + lhs->e11111 * rhs->r + lhs->e1 * rhs->e1111 
             + lhs->e1111 * rhs->e1 + lhs->e11 * rhs->e111 + lhs->e111 * rhs->e11;

  return res;

}

void onumm1n5_mul_oo_to(  onumm1n5_t* lhs,  onumm1n5_t* rhs, onumm1n5_t* res){
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
  // Order 4;
  res->e1111 = lhs->r * rhs->e1111 + lhs->e1111 * rhs->r + lhs->e1 * rhs->e111 
            + lhs->e111 * rhs->e1 + lhs->e11 * rhs->e11;
  // Order 5;
  res->e11111 = lhs->r * rhs->e11111 + lhs->e11111 * rhs->r + lhs->e1 * rhs->e1111 
             + lhs->e1111 * rhs->e1 + lhs->e11 * rhs->e111 + lhs->e111 * rhs->e11;

}

onumm1n5_t onumm1n5_mul_ro(  coeff_t lhs,  onumm1n5_t* rhs){
  onumm1n5_t res;

  // Multiplication like function 'lhs * rhs'
  //  Real;
  res.r = lhs * rhs->r;
  // Order 1;
  res.e1 = lhs * rhs->e1;
  // Order 2;
  res.e11 = lhs * rhs->e11;
  // Order 3;
  res.e111 = lhs * rhs->e111;
  // Order 4;
  res.e1111 = lhs * rhs->e1111;
  // Order 5;
  res.e11111 = lhs * rhs->e11111;

  return res;

}

void onumm1n5_mul_ro_to(  coeff_t lhs,  onumm1n5_t* rhs, onumm1n5_t* res){
  // Multiplication like function 'lhs * rhs'
  //  Real;
  res->r = lhs * rhs->r;
  // Order 1;
  res->e1 = lhs * rhs->e1;
  // Order 2;
  res->e11 = lhs * rhs->e11;
  // Order 3;
  res->e111 = lhs * rhs->e111;
  // Order 4;
  res->e1111 = lhs * rhs->e1111;
  // Order 5;
  res->e11111 = lhs * rhs->e11111;

}

onumm1n5_t onumm1n5_trunc_mul_oo(  onumm1n5_t* lhs,  onumm1n5_t* rhs){
  onumm1n5_t res;

  res = onumm1n5_init();

  //  Truncated multiplication like function 'lhs * rhs'
  // Order 2;
  res.e11 =  + lhs->e1 * rhs->e1;
  // Order 3;
  res.e111 =  + lhs->e1 * rhs->e11 + lhs->e11 * rhs->e1;
  // Order 4;
  res.e1111 =  + lhs->e1 * rhs->e111 + lhs->e111 * rhs->e1 + lhs->e11 * rhs->e11;
  // Order 5;
  res.e11111 =  + lhs->e1 * rhs->e1111 + lhs->e1111 * rhs->e1 + lhs->e11 * rhs->e111 
             + lhs->e111 * rhs->e11;

  return res;

}

void onumm1n5_trunc_mul_oo_to(  onumm1n5_t* lhs,  onumm1n5_t* rhs, onumm1n5_t* res){
   (*res) = onumm1n5_init();

  //  Truncated multiplication like function 'lhs * rhs'
  // Order 2;
  res->e11 =  + lhs->e1 * rhs->e1;
  // Order 3;
  res->e111 =  + lhs->e1 * rhs->e11 + lhs->e11 * rhs->e1;
  // Order 4;
  res->e1111 =  + lhs->e1 * rhs->e111 + lhs->e111 * rhs->e1 + lhs->e11 * rhs->e11;
  // Order 5;
  res->e11111 =  + lhs->e1 * rhs->e1111 + lhs->e1111 * rhs->e1 + lhs->e11 * rhs->e111 
             + lhs->e111 * rhs->e11;

}

onumm1n5_t onumm1n5_gem_oo(  onumm1n5_t* a,  onumm1n5_t* b,  onumm1n5_t* c){
  onumm1n5_t res;

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
  // Order 4;
  res.e1111 = c->e1111 + a->r * b->e1111 + a->e1111 * b->r + a->e1 * b->e111 
            + a->e111 * b->e1 + a->e11 * b->e11;
  // Order 5;
  res.e11111 = c->e11111 + a->r * b->e11111 + a->e11111 * b->r + a->e1 * b->e1111 
             + a->e1111 * b->e1 + a->e11 * b->e111 + a->e111 * b->e11;

  return res;

}

void onumm1n5_gem_oo_to(  onumm1n5_t* a,  onumm1n5_t* b,  onumm1n5_t* c, onumm1n5_t* res){
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
  // Order 4;
  res->e1111 = c->e1111 + a->r * b->e1111 + a->e1111 * b->r + a->e1 * b->e111 
            + a->e111 * b->e1 + a->e11 * b->e11;
  // Order 5;
  res->e11111 = c->e11111 + a->r * b->e11111 + a->e11111 * b->r + a->e1 * b->e1111 
             + a->e1111 * b->e1 + a->e11 * b->e111 + a->e111 * b->e11;

}

onumm1n5_t onumm1n5_gem_ro(  coeff_t a,  onumm1n5_t* b,  onumm1n5_t* c){
  onumm1n5_t res;

  //  General multiplication like function 'a * b + c'
  // Real;
  res.r = c->r + a * b->r;
  // Order 1;
  res.e1 = c->e1 + a * b->e1;
  // Order 2;
  res.e11 = c->e11 + a * b->e11;
  // Order 3;
  res.e111 = c->e111 + a * b->e111;
  // Order 4;
  res.e1111 = c->e1111 + a * b->e1111;
  // Order 5;
  res.e11111 = c->e11111 + a * b->e11111;

  return res;

}

void onumm1n5_gem_ro_to(  coeff_t a,  onumm1n5_t* b,  onumm1n5_t* c, onumm1n5_t* res){
  //  General multiplication like function 'a * b + c'
  // Real;
  res->r = c->r + a * b->r;
  // Order 1;
  res->e1 = c->e1 + a * b->e1;
  // Order 2;
  res->e11 = c->e11 + a * b->e11;
  // Order 3;
  res->e111 = c->e111 + a * b->e111;
  // Order 4;
  res->e1111 = c->e1111 + a * b->e1111;
  // Order 5;
  res->e11111 = c->e11111 + a * b->e11111;

}

onumm1n5_t onumm1n5_feval(coeff_t* feval_re, onumm1n5_t* x){

  onumm1n5_t res;

  // feval function
  //  Definitions
  coeff_t factor=1, coef = 0;
  onumm1n5_t deltax = (*x), deltax_power = (*x);
  deltax.r = 0.0;
  deltax_power.r = 0.0;
  onumm1n5_set_r(0.0, &res);
  //  Real
  res.r = feval_re[0];
  // Order 1
  factor *=1;
  coef    = feval_re[1]/ factor;;
  onumm1n5_gem_ro_to( coef, &deltax_power, &res, &res);
  deltax_power = onumm1n5_mul_oo(&deltax_power,&deltax);
  // Order 2
  factor *=2;
  coef    = feval_re[2]/ factor;;
  onumm1n5_gem_ro_to( coef, &deltax_power, &res, &res);
  deltax_power = onumm1n5_mul_oo(&deltax_power,&deltax);
  // Order 3
  factor *=3;
  coef    = feval_re[3]/ factor;;
  onumm1n5_gem_ro_to( coef, &deltax_power, &res, &res);
  deltax_power = onumm1n5_mul_oo(&deltax_power,&deltax);
  // Order 4
  factor *=4;
  coef    = feval_re[4]/ factor;;
  onumm1n5_gem_ro_to( coef, &deltax_power, &res, &res);
  deltax_power = onumm1n5_mul_oo(&deltax_power,&deltax);
  // Order 5
  factor *=5;
  coef    = feval_re[5]/ factor;;
  onumm1n5_gem_ro_to( coef, &deltax_power, &res, &res);

  return res;

}

void onumm1n5_feval_to(coeff_t* feval_re, onumm1n5_t* x, onumm1n5_t* res){

  // feval function
  //  Definitions
  coeff_t factor=1, coef = 0;
  onumm1n5_t deltax = (*x), deltax_power = (*x);
  deltax.r = 0.0;
  deltax_power.r = 0.0;
  onumm1n5_set_r(0.0, res);
  //  Real
  res->r = feval_re[0];
  // Order 1
  factor *=1;
  coef    = feval_re[1]/ factor;;
  onumm1n5_gem_ro_to( coef, &deltax_power, res, res);
  deltax_power = onumm1n5_mul_oo(&deltax_power,&deltax);
  // Order 2
  factor *=2;
  coef    = feval_re[2]/ factor;;
  onumm1n5_gem_ro_to( coef, &deltax_power, res, res);
  deltax_power = onumm1n5_mul_oo(&deltax_power,&deltax);
  // Order 3
  factor *=3;
  coef    = feval_re[3]/ factor;;
  onumm1n5_gem_ro_to( coef, &deltax_power, res, res);
  deltax_power = onumm1n5_mul_oo(&deltax_power,&deltax);
  // Order 4
  factor *=4;
  coef    = feval_re[4]/ factor;;
  onumm1n5_gem_ro_to( coef, &deltax_power, res, res);
  deltax_power = onumm1n5_mul_oo(&deltax_power,&deltax);
  // Order 5
  factor *=5;
  coef    = feval_re[5]/ factor;;
  onumm1n5_gem_ro_to( coef, &deltax_power, res, res);

}

