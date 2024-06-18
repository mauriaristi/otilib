
// Division.

// ****************************************************************************************************
onumm3n2_t onumm3n2_div_ro(coeff_t num, onumm3n2_t* den){

    
    onumm3n2_t inv = onumm3n2_pow(den,-1);
    onumm3n2_t res = onumm3n2_mul_ro(num,&inv);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
onumm3n2_t onumm3n2_div_oo(onumm3n2_t* num, onumm3n2_t* den){

    
    onumm3n2_t inv = onumm3n2_init();
    onumm3n2_pow_to(den,-1,&inv);
    onumm3n2_t res = onumm3n2_mul_oo(num,&inv);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
onumm3n2_t onumm3n2_div_or(onumm3n2_t* num, coeff_t val){

    return onumm3n2_mul_ro(1.0/val,num);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
onumm3n2_t onumm3n2_abs(onumm3n2_t* num){

	onumm3n2_t res;
    onumm3n2_abs_to(num,&res);
    return res;

}
// ----------------------------------------------------------------------------------------------------

onumm3n2_t onumm3n2_neg(  onumm3n2_t* lhs){

  onumm3n2_t res;

  // Negation like function '-lhs'
  // Real;
  res.r = -lhs->r;
  // Order 1;
  res.e1 = -lhs->e1;
  res.e2 = -lhs->e2;
  res.e3 = -lhs->e3;
  // Order 2;
  res.e11 = -lhs->e11;
  res.e12 = -lhs->e12;
  res.e22 = -lhs->e22;
  res.e13 = -lhs->e13;
  res.e23 = -lhs->e23;
  res.e33 = -lhs->e33;

  return res;

}

void onumm3n2_neg_to(  onumm3n2_t* lhs, onumm3n2_t* res){

  // Negation like function '-lhs'
  // Real;
  res->r = -lhs->r;
  // Order 1;
  res->e1 = -lhs->e1;
  res->e2 = -lhs->e2;
  res->e3 = -lhs->e3;
  // Order 2;
  res->e11 = -lhs->e11;
  res->e12 = -lhs->e12;
  res->e22 = -lhs->e22;
  res->e13 = -lhs->e13;
  res->e23 = -lhs->e23;
  res->e33 = -lhs->e33;

}

onumm3n2_t onumm3n2_sum_oo(  onumm3n2_t* lhs,  onumm3n2_t* rhs){
  onumm3n2_t res;

  // Addition like function 'lhs + rhs'
  //  Real
  res.r = lhs->r + rhs->r;
  // Order 1
  res.e1 = lhs->e1 + rhs->e1;
  res.e2 = lhs->e2 + rhs->e2;
  res.e3 = lhs->e3 + rhs->e3;
  // Order 2
  res.e11 = lhs->e11 + rhs->e11;
  res.e12 = lhs->e12 + rhs->e12;
  res.e22 = lhs->e22 + rhs->e22;
  res.e13 = lhs->e13 + rhs->e13;
  res.e23 = lhs->e23 + rhs->e23;
  res.e33 = lhs->e33 + rhs->e33;

  return res;

}

void onumm3n2_sum_oo_to(  onumm3n2_t* lhs,  onumm3n2_t* rhs, onumm3n2_t* res){
  // Addition like function 'lhs + rhs'
  //  Real
  res->r = lhs->r + rhs->r;
  // Order 1
  res->e1 = lhs->e1 + rhs->e1;
  res->e2 = lhs->e2 + rhs->e2;
  res->e3 = lhs->e3 + rhs->e3;
  // Order 2
  res->e11 = lhs->e11 + rhs->e11;
  res->e12 = lhs->e12 + rhs->e12;
  res->e22 = lhs->e22 + rhs->e22;
  res->e13 = lhs->e13 + rhs->e13;
  res->e23 = lhs->e23 + rhs->e23;
  res->e33 = lhs->e33 + rhs->e33;

}

onumm3n2_t onumm3n2_sum_ro(  coeff_t lhs,  onumm3n2_t* rhs){
  onumm3n2_t res;

  // Addition like function 'lhs + rhs'
  // Real;
  res.r = lhs + rhs->r;
  // Order 1;
  res.e1 =  + rhs->e1;
  res.e2 =  + rhs->e2;
  res.e3 =  + rhs->e3;
  // Order 2;
  res.e11 =  + rhs->e11;
  res.e12 =  + rhs->e12;
  res.e22 =  + rhs->e22;
  res.e13 =  + rhs->e13;
  res.e23 =  + rhs->e23;
  res.e33 =  + rhs->e33;

  return res;

}

void onumm3n2_sum_ro_to(  coeff_t lhs,  onumm3n2_t* rhs, onumm3n2_t* res){
  // Addition like function 'lhs + rhs'
  // Real;
  res->r = lhs + rhs->r;
  // Order 1;
  res->e1 =  + rhs->e1;
  res->e2 =  + rhs->e2;
  res->e3 =  + rhs->e3;
  // Order 2;
  res->e11 =  + rhs->e11;
  res->e12 =  + rhs->e12;
  res->e22 =  + rhs->e22;
  res->e13 =  + rhs->e13;
  res->e23 =  + rhs->e23;
  res->e33 =  + rhs->e33;

}

onumm3n2_t onumm3n2_sub_oo(  onumm3n2_t* lhs,  onumm3n2_t* rhs){
  onumm3n2_t res;

  // Addition like function 'lhs - rhs'
  //  Real
  res.r = lhs->r - rhs->r;
  // Order 1
  res.e1 = lhs->e1 - rhs->e1;
  res.e2 = lhs->e2 - rhs->e2;
  res.e3 = lhs->e3 - rhs->e3;
  // Order 2
  res.e11 = lhs->e11 - rhs->e11;
  res.e12 = lhs->e12 - rhs->e12;
  res.e22 = lhs->e22 - rhs->e22;
  res.e13 = lhs->e13 - rhs->e13;
  res.e23 = lhs->e23 - rhs->e23;
  res.e33 = lhs->e33 - rhs->e33;

  return res;

}

void onumm3n2_sub_oo_to(  onumm3n2_t* lhs,  onumm3n2_t* rhs, onumm3n2_t* res){
  // Addition like function 'lhs - rhs'
  //  Real
  res->r = lhs->r - rhs->r;
  // Order 1
  res->e1 = lhs->e1 - rhs->e1;
  res->e2 = lhs->e2 - rhs->e2;
  res->e3 = lhs->e3 - rhs->e3;
  // Order 2
  res->e11 = lhs->e11 - rhs->e11;
  res->e12 = lhs->e12 - rhs->e12;
  res->e22 = lhs->e22 - rhs->e22;
  res->e13 = lhs->e13 - rhs->e13;
  res->e23 = lhs->e23 - rhs->e23;
  res->e33 = lhs->e33 - rhs->e33;

}

onumm3n2_t onumm3n2_sub_ro(  coeff_t lhs,  onumm3n2_t* rhs){
  onumm3n2_t res;

  // Addition like function 'lhs - rhs'
  // Real;
  res.r = lhs - rhs->r;
  // Order 1;
  res.e1 =  - rhs->e1;
  res.e2 =  - rhs->e2;
  res.e3 =  - rhs->e3;
  // Order 2;
  res.e11 =  - rhs->e11;
  res.e12 =  - rhs->e12;
  res.e22 =  - rhs->e22;
  res.e13 =  - rhs->e13;
  res.e23 =  - rhs->e23;
  res.e33 =  - rhs->e33;

  return res;

}

void onumm3n2_sub_ro_to(  coeff_t lhs,  onumm3n2_t* rhs, onumm3n2_t* res){
  // Addition like function 'lhs - rhs'
  // Real;
  res->r = lhs - rhs->r;
  // Order 1;
  res->e1 =  - rhs->e1;
  res->e2 =  - rhs->e2;
  res->e3 =  - rhs->e3;
  // Order 2;
  res->e11 =  - rhs->e11;
  res->e12 =  - rhs->e12;
  res->e22 =  - rhs->e22;
  res->e13 =  - rhs->e13;
  res->e23 =  - rhs->e23;
  res->e33 =  - rhs->e33;

}

onumm3n2_t onumm3n2_sub_or(  onumm3n2_t* lhs,  coeff_t rhs){
  onumm3n2_t res;

  // Addition like function 'lhs - rhs'
  // Real;
  res.r = lhs->r - rhs;
  // Order 1;
  res.e1 = lhs->e1;
  res.e2 = lhs->e2;
  res.e3 = lhs->e3;
  // Order 2;
  res.e11 = lhs->e11;
  res.e12 = lhs->e12;
  res.e22 = lhs->e22;
  res.e13 = lhs->e13;
  res.e23 = lhs->e23;
  res.e33 = lhs->e33;

  return res;

}

void onumm3n2_sub_or_to(  onumm3n2_t* lhs,  coeff_t rhs, onumm3n2_t* res){
  // Addition like function 'lhs - rhs'
  // Real;
  res->r = lhs->r - rhs;
  // Order 1;
  res->e1 = lhs->e1;
  res->e2 = lhs->e2;
  res->e3 = lhs->e3;
  // Order 2;
  res->e11 = lhs->e11;
  res->e12 = lhs->e12;
  res->e22 = lhs->e22;
  res->e13 = lhs->e13;
  res->e23 = lhs->e23;
  res->e33 = lhs->e33;

}

onumm3n2_t onumm3n2_mul_oo(  onumm3n2_t* lhs,  onumm3n2_t* rhs){
  onumm3n2_t res;

  //  Multiplication like function 'lhs * rhs'
  // Real;
  res.r = lhs->r * rhs->r;
  // Order 1;
  res.e1 = lhs->r * rhs->e1 + lhs->e1 * rhs->r;
  res.e2 = lhs->r * rhs->e2 + lhs->e2 * rhs->r;
  res.e3 = lhs->r * rhs->e3 + lhs->e3 * rhs->r;
  // Order 2;
  res.e11 = lhs->r * rhs->e11 + lhs->e11 * rhs->r + lhs->e1 * rhs->e1;
  res.e12 = lhs->r * rhs->e12 + lhs->e12 * rhs->r + lhs->e1 * rhs->e2 
          + lhs->e2 * rhs->e1;
  res.e22 = lhs->r * rhs->e22 + lhs->e22 * rhs->r + lhs->e2 * rhs->e2;
  res.e13 = lhs->r * rhs->e13 + lhs->e13 * rhs->r + lhs->e1 * rhs->e3 
          + lhs->e3 * rhs->e1;
  res.e23 = lhs->r * rhs->e23 + lhs->e23 * rhs->r + lhs->e2 * rhs->e3 
          + lhs->e3 * rhs->e2;
  res.e33 = lhs->r * rhs->e33 + lhs->e33 * rhs->r + lhs->e3 * rhs->e3;

  return res;

}

void onumm3n2_mul_oo_to(  onumm3n2_t* lhs,  onumm3n2_t* rhs, onumm3n2_t* res){
  //  Multiplication like function 'lhs * rhs'
  // Real;
  res->r = lhs->r * rhs->r;
  // Order 1;
  res->e1 = lhs->r * rhs->e1 + lhs->e1 * rhs->r;
  res->e2 = lhs->r * rhs->e2 + lhs->e2 * rhs->r;
  res->e3 = lhs->r * rhs->e3 + lhs->e3 * rhs->r;
  // Order 2;
  res->e11 = lhs->r * rhs->e11 + lhs->e11 * rhs->r + lhs->e1 * rhs->e1;
  res->e12 = lhs->r * rhs->e12 + lhs->e12 * rhs->r + lhs->e1 * rhs->e2 
          + lhs->e2 * rhs->e1;
  res->e22 = lhs->r * rhs->e22 + lhs->e22 * rhs->r + lhs->e2 * rhs->e2;
  res->e13 = lhs->r * rhs->e13 + lhs->e13 * rhs->r + lhs->e1 * rhs->e3 
          + lhs->e3 * rhs->e1;
  res->e23 = lhs->r * rhs->e23 + lhs->e23 * rhs->r + lhs->e2 * rhs->e3 
          + lhs->e3 * rhs->e2;
  res->e33 = lhs->r * rhs->e33 + lhs->e33 * rhs->r + lhs->e3 * rhs->e3;

}

onumm3n2_t onumm3n2_mul_ro(  coeff_t lhs,  onumm3n2_t* rhs){
  onumm3n2_t res;

  // Multiplication like function 'lhs * rhs'
  //  Real;
  res.r = lhs * rhs->r;
  // Order 1;
  res.e1 = lhs * rhs->e1;
  res.e2 = lhs * rhs->e2;
  res.e3 = lhs * rhs->e3;
  // Order 2;
  res.e11 = lhs * rhs->e11;
  res.e12 = lhs * rhs->e12;
  res.e22 = lhs * rhs->e22;
  res.e13 = lhs * rhs->e13;
  res.e23 = lhs * rhs->e23;
  res.e33 = lhs * rhs->e33;

  return res;

}

void onumm3n2_mul_ro_to(  coeff_t lhs,  onumm3n2_t* rhs, onumm3n2_t* res){
  // Multiplication like function 'lhs * rhs'
  //  Real;
  res->r = lhs * rhs->r;
  // Order 1;
  res->e1 = lhs * rhs->e1;
  res->e2 = lhs * rhs->e2;
  res->e3 = lhs * rhs->e3;
  // Order 2;
  res->e11 = lhs * rhs->e11;
  res->e12 = lhs * rhs->e12;
  res->e22 = lhs * rhs->e22;
  res->e13 = lhs * rhs->e13;
  res->e23 = lhs * rhs->e23;
  res->e33 = lhs * rhs->e33;

}

onumm3n2_t onumm3n2_trunc_mul_oo(  onumm3n2_t* lhs,  onumm3n2_t* rhs){
  onumm3n2_t res;

  res = onumm3n2_init();

  //  Truncated multiplication like function 'lhs * rhs'
  // Order 2;
  res.e11 =  + lhs->e1 * rhs->e1;
  res.e12 =  + lhs->e1 * rhs->e2 + lhs->e2 * rhs->e1;
  res.e22 =  + lhs->e2 * rhs->e2;
  res.e13 =  + lhs->e1 * rhs->e3 + lhs->e3 * rhs->e1;
  res.e23 =  + lhs->e2 * rhs->e3 + lhs->e3 * rhs->e2;
  res.e33 =  + lhs->e3 * rhs->e3;

  return res;

}

void onumm3n2_trunc_mul_oo_to(  onumm3n2_t* lhs,  onumm3n2_t* rhs, onumm3n2_t* res){
   (*res) = onumm3n2_init();

  //  Truncated multiplication like function 'lhs * rhs'
  // Order 2;
  res->e11 =  + lhs->e1 * rhs->e1;
  res->e12 =  + lhs->e1 * rhs->e2 + lhs->e2 * rhs->e1;
  res->e22 =  + lhs->e2 * rhs->e2;
  res->e13 =  + lhs->e1 * rhs->e3 + lhs->e3 * rhs->e1;
  res->e23 =  + lhs->e2 * rhs->e3 + lhs->e3 * rhs->e2;
  res->e33 =  + lhs->e3 * rhs->e3;

}

onumm3n2_t onumm3n2_gem_oo(  onumm3n2_t* a,  onumm3n2_t* b,  onumm3n2_t* c){
  onumm3n2_t res;

  //  General multiplication like function 'a * b + c'
  // Real;
  res.r = c->r + a->r * b->r;
  // Order 1;
  res.e1 = c->e1 + a->r * b->e1 + a->e1 * b->r;
  res.e2 = c->e2 + a->r * b->e2 + a->e2 * b->r;
  res.e3 = c->e3 + a->r * b->e3 + a->e3 * b->r;
  // Order 2;
  res.e11 = c->e11 + a->r * b->e11 + a->e11 * b->r + a->e1 * b->e1;
  res.e12 = c->e12 + a->r * b->e12 + a->e12 * b->r + a->e1 * b->e2 
          + a->e2 * b->e1;
  res.e22 = c->e22 + a->r * b->e22 + a->e22 * b->r + a->e2 * b->e2;
  res.e13 = c->e13 + a->r * b->e13 + a->e13 * b->r + a->e1 * b->e3 
          + a->e3 * b->e1;
  res.e23 = c->e23 + a->r * b->e23 + a->e23 * b->r + a->e2 * b->e3 
          + a->e3 * b->e2;
  res.e33 = c->e33 + a->r * b->e33 + a->e33 * b->r + a->e3 * b->e3;

  return res;

}

void onumm3n2_gem_oo_to(  onumm3n2_t* a,  onumm3n2_t* b,  onumm3n2_t* c, onumm3n2_t* res){
  //  General multiplication like function 'a * b + c'
  // Real;
  res->r = c->r + a->r * b->r;
  // Order 1;
  res->e1 = c->e1 + a->r * b->e1 + a->e1 * b->r;
  res->e2 = c->e2 + a->r * b->e2 + a->e2 * b->r;
  res->e3 = c->e3 + a->r * b->e3 + a->e3 * b->r;
  // Order 2;
  res->e11 = c->e11 + a->r * b->e11 + a->e11 * b->r + a->e1 * b->e1;
  res->e12 = c->e12 + a->r * b->e12 + a->e12 * b->r + a->e1 * b->e2 
          + a->e2 * b->e1;
  res->e22 = c->e22 + a->r * b->e22 + a->e22 * b->r + a->e2 * b->e2;
  res->e13 = c->e13 + a->r * b->e13 + a->e13 * b->r + a->e1 * b->e3 
          + a->e3 * b->e1;
  res->e23 = c->e23 + a->r * b->e23 + a->e23 * b->r + a->e2 * b->e3 
          + a->e3 * b->e2;
  res->e33 = c->e33 + a->r * b->e33 + a->e33 * b->r + a->e3 * b->e3;

}

onumm3n2_t onumm3n2_gem_ro(  coeff_t a,  onumm3n2_t* b,  onumm3n2_t* c){
  onumm3n2_t res;

  //  General multiplication like function 'a * b + c'
  // Real;
  res.r = c->r + a * b->r;
  // Order 1;
  res.e1 = c->e1 + a * b->e1;
  res.e2 = c->e2 + a * b->e2;
  res.e3 = c->e3 + a * b->e3;
  // Order 2;
  res.e11 = c->e11 + a * b->e11;
  res.e12 = c->e12 + a * b->e12;
  res.e22 = c->e22 + a * b->e22;
  res.e13 = c->e13 + a * b->e13;
  res.e23 = c->e23 + a * b->e23;
  res.e33 = c->e33 + a * b->e33;

  return res;

}

void onumm3n2_gem_ro_to(  coeff_t a,  onumm3n2_t* b,  onumm3n2_t* c, onumm3n2_t* res){
  //  General multiplication like function 'a * b + c'
  // Real;
  res->r = c->r + a * b->r;
  // Order 1;
  res->e1 = c->e1 + a * b->e1;
  res->e2 = c->e2 + a * b->e2;
  res->e3 = c->e3 + a * b->e3;
  // Order 2;
  res->e11 = c->e11 + a * b->e11;
  res->e12 = c->e12 + a * b->e12;
  res->e22 = c->e22 + a * b->e22;
  res->e13 = c->e13 + a * b->e13;
  res->e23 = c->e23 + a * b->e23;
  res->e33 = c->e33 + a * b->e33;

}

void onumm3n2_trunc_gem_oo_to( ord_t ord_lhs,  onumm3n2_t* a,  ord_t ord_rhs,  onumm3n2_t* b,  onumm3n2_t* c, onumm3n2_t* res){
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
          break;
        case 2:
          // res order: 2
          res->e11 = c->e11 + a->r * b->e11;
          res->e12 = c->e12 + a->r * b->e12;
          res->e22 = c->e22 + a->r * b->e22;
          res->e13 = c->e13 + a->r * b->e13;
          res->e23 = c->e23 + a->r * b->e23;
          res->e33 = c->e33 + a->r * b->e33;
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
          break;
        case 1:
          // res order: 2
          res->e11 = c->e11 + a->e1 * b->e1;
          res->e12 = c->e12 + a->e1 * b->e2 + a->e2 * b->e1;
          res->e22 = c->e22 + a->e2 * b->e2;
          res->e13 = c->e13 + a->e1 * b->e3 + a->e3 * b->e1;
          res->e23 = c->e23 + a->e2 * b->e3 + a->e3 * b->e2;
          res->e33 = c->e33 + a->e3 * b->e3;
          break;
      }
      break;
    case 2:
      switch( ord_rhs ){
        case 0:
          // res order: 2
          res->e11 = c->e11 + a->e11 * b->r;
          res->e12 = c->e12 + a->e12 * b->r;
          res->e22 = c->e22 + a->e22 * b->r;
          res->e13 = c->e13 + a->e13 * b->r;
          res->e23 = c->e23 + a->e23 * b->r;
          res->e33 = c->e33 + a->e33 * b->r;
          break;
      }
      break;
  }

}

void onumm3n2_trunc_sum_oo_to(ord_t order, onumm3n2_t* lhs,onumm3n2_t* rhs, onumm3n2_t* res){
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
      break;
    case(2):    // Order 2
      res->e11 = lhs->e11 + rhs->e11;
      res->e12 = lhs->e12 + rhs->e12;
      res->e22 = lhs->e22 + rhs->e22;
      res->e13 = lhs->e13 + rhs->e13;
      res->e23 = lhs->e23 + rhs->e23;
      res->e33 = lhs->e33 + rhs->e33;
      break;
  }
}

void onumm3n2_trunc_sub_oo_to(ord_t order, onumm3n2_t* lhs,onumm3n2_t* rhs, onumm3n2_t* res){
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
      break;
    case(2):    // Order 2
      res->e11 = lhs->e11 - rhs->e11;
      res->e12 = lhs->e12 - rhs->e12;
      res->e22 = lhs->e22 - rhs->e22;
      res->e13 = lhs->e13 - rhs->e13;
      res->e23 = lhs->e23 - rhs->e23;
      res->e33 = lhs->e33 - rhs->e33;
      break;
  }
}

onumm3n2_t onumm3n2_feval(coeff_t* feval_re, onumm3n2_t* x){

  onumm3n2_t res;

  // feval function
  //  Definitions
  coeff_t factor=1, coef = 0;
  onumm3n2_t deltax = (*x), deltax_power = (*x);
  deltax.r = 0.0;
  deltax_power.r = 0.0;
  onumm3n2_set_r(0.0, &res);
  //  Real
  res.r = feval_re[0];
  // Order 1
  factor *=1;
  coef    = feval_re[1]/ factor;;
  onumm3n2_gem_ro_to( coef, &deltax_power, &res, &res);
  deltax_power = onumm3n2_mul_oo(&deltax_power,&deltax);
  // Order 2
  factor *=2;
  coef    = feval_re[2]/ factor;;
  onumm3n2_gem_ro_to( coef, &deltax_power, &res, &res);

  return res;

}

void onumm3n2_feval_to(coeff_t* feval_re, onumm3n2_t* x, onumm3n2_t* res){

  // feval function
  //  Definitions
  coeff_t factor=1, coef = 0;
  onumm3n2_t deltax = (*x), deltax_power = (*x);
  deltax.r = 0.0;
  deltax_power.r = 0.0;
  onumm3n2_set_r(0.0, res);
  //  Real
  res->r = feval_re[0];
  // Order 1
  factor *=1;
  coef    = feval_re[1]/ factor;;
  onumm3n2_gem_ro_to( coef, &deltax_power, res, res);
  deltax_power = onumm3n2_mul_oo(&deltax_power,&deltax);
  // Order 2
  factor *=2;
  coef    = feval_re[2]/ factor;;
  onumm3n2_gem_ro_to( coef, &deltax_power, res, res);

}

