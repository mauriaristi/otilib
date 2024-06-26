
// Division.

// ****************************************************************************************************
onumm1n10_t onumm1n10_div_ro(coeff_t num, onumm1n10_t* den){

    
    onumm1n10_t inv = onumm1n10_pow(den,-1);
    onumm1n10_t res = onumm1n10_mul_ro(num,&inv);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
onumm1n10_t onumm1n10_div_oo(onumm1n10_t* num, onumm1n10_t* den){

    
    onumm1n10_t inv = onumm1n10_init();
    onumm1n10_pow_to(den,-1,&inv);
    onumm1n10_t res = onumm1n10_mul_oo(num,&inv);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
onumm1n10_t onumm1n10_div_or(onumm1n10_t* num, coeff_t val){

    return onumm1n10_mul_ro(1.0/val,num);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
onumm1n10_t onumm1n10_abs(onumm1n10_t* num){

	onumm1n10_t res;
    onumm1n10_abs_to(num,&res);
    return res;

}
// ----------------------------------------------------------------------------------------------------

onumm1n10_t onumm1n10_neg(  onumm1n10_t* lhs){

  onumm1n10_t res;

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
  // Order 6;
  res.e111111 = -lhs->e111111;
  // Order 7;
  res.e1111111 = -lhs->e1111111;
  // Order 8;
  res.e11111111 = -lhs->e11111111;
  // Order 9;
  res.e111111111 = -lhs->e111111111;
  // Order 10;
  res.e1111111111 = -lhs->e1111111111;

  return res;

}

void onumm1n10_neg_to(  onumm1n10_t* lhs, onumm1n10_t* res){

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
  // Order 6;
  res->e111111 = -lhs->e111111;
  // Order 7;
  res->e1111111 = -lhs->e1111111;
  // Order 8;
  res->e11111111 = -lhs->e11111111;
  // Order 9;
  res->e111111111 = -lhs->e111111111;
  // Order 10;
  res->e1111111111 = -lhs->e1111111111;

}

onumm1n10_t onumm1n10_sum_oo(  onumm1n10_t* lhs,  onumm1n10_t* rhs){
  onumm1n10_t res;

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
  // Order 6
  res.e111111 = lhs->e111111 + rhs->e111111;
  // Order 7
  res.e1111111 = lhs->e1111111 + rhs->e1111111;
  // Order 8
  res.e11111111 = lhs->e11111111 + rhs->e11111111;
  // Order 9
  res.e111111111 = lhs->e111111111 + rhs->e111111111;
  // Order 10
  res.e1111111111 = lhs->e1111111111 + rhs->e1111111111;

  return res;

}

void onumm1n10_sum_oo_to(  onumm1n10_t* lhs,  onumm1n10_t* rhs, onumm1n10_t* res){
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
  // Order 6
  res->e111111 = lhs->e111111 + rhs->e111111;
  // Order 7
  res->e1111111 = lhs->e1111111 + rhs->e1111111;
  // Order 8
  res->e11111111 = lhs->e11111111 + rhs->e11111111;
  // Order 9
  res->e111111111 = lhs->e111111111 + rhs->e111111111;
  // Order 10
  res->e1111111111 = lhs->e1111111111 + rhs->e1111111111;

}

onumm1n10_t onumm1n10_sum_ro(  coeff_t lhs,  onumm1n10_t* rhs){
  onumm1n10_t res;

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
  // Order 6;
  res.e111111 =  + rhs->e111111;
  // Order 7;
  res.e1111111 =  + rhs->e1111111;
  // Order 8;
  res.e11111111 =  + rhs->e11111111;
  // Order 9;
  res.e111111111 =  + rhs->e111111111;
  // Order 10;
  res.e1111111111 =  + rhs->e1111111111;

  return res;

}

void onumm1n10_sum_ro_to(  coeff_t lhs,  onumm1n10_t* rhs, onumm1n10_t* res){
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
  // Order 6;
  res->e111111 =  + rhs->e111111;
  // Order 7;
  res->e1111111 =  + rhs->e1111111;
  // Order 8;
  res->e11111111 =  + rhs->e11111111;
  // Order 9;
  res->e111111111 =  + rhs->e111111111;
  // Order 10;
  res->e1111111111 =  + rhs->e1111111111;

}

onumm1n10_t onumm1n10_sub_oo(  onumm1n10_t* lhs,  onumm1n10_t* rhs){
  onumm1n10_t res;

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
  // Order 6
  res.e111111 = lhs->e111111 - rhs->e111111;
  // Order 7
  res.e1111111 = lhs->e1111111 - rhs->e1111111;
  // Order 8
  res.e11111111 = lhs->e11111111 - rhs->e11111111;
  // Order 9
  res.e111111111 = lhs->e111111111 - rhs->e111111111;
  // Order 10
  res.e1111111111 = lhs->e1111111111 - rhs->e1111111111;

  return res;

}

void onumm1n10_sub_oo_to(  onumm1n10_t* lhs,  onumm1n10_t* rhs, onumm1n10_t* res){
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
  // Order 6
  res->e111111 = lhs->e111111 - rhs->e111111;
  // Order 7
  res->e1111111 = lhs->e1111111 - rhs->e1111111;
  // Order 8
  res->e11111111 = lhs->e11111111 - rhs->e11111111;
  // Order 9
  res->e111111111 = lhs->e111111111 - rhs->e111111111;
  // Order 10
  res->e1111111111 = lhs->e1111111111 - rhs->e1111111111;

}

onumm1n10_t onumm1n10_sub_ro(  coeff_t lhs,  onumm1n10_t* rhs){
  onumm1n10_t res;

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
  // Order 6;
  res.e111111 =  - rhs->e111111;
  // Order 7;
  res.e1111111 =  - rhs->e1111111;
  // Order 8;
  res.e11111111 =  - rhs->e11111111;
  // Order 9;
  res.e111111111 =  - rhs->e111111111;
  // Order 10;
  res.e1111111111 =  - rhs->e1111111111;

  return res;

}

void onumm1n10_sub_ro_to(  coeff_t lhs,  onumm1n10_t* rhs, onumm1n10_t* res){
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
  // Order 6;
  res->e111111 =  - rhs->e111111;
  // Order 7;
  res->e1111111 =  - rhs->e1111111;
  // Order 8;
  res->e11111111 =  - rhs->e11111111;
  // Order 9;
  res->e111111111 =  - rhs->e111111111;
  // Order 10;
  res->e1111111111 =  - rhs->e1111111111;

}

onumm1n10_t onumm1n10_sub_or(  onumm1n10_t* lhs,  coeff_t rhs){
  onumm1n10_t res;

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
  // Order 6;
  res.e111111 = lhs->e111111;
  // Order 7;
  res.e1111111 = lhs->e1111111;
  // Order 8;
  res.e11111111 = lhs->e11111111;
  // Order 9;
  res.e111111111 = lhs->e111111111;
  // Order 10;
  res.e1111111111 = lhs->e1111111111;

  return res;

}

void onumm1n10_sub_or_to(  onumm1n10_t* lhs,  coeff_t rhs, onumm1n10_t* res){
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
  // Order 6;
  res->e111111 = lhs->e111111;
  // Order 7;
  res->e1111111 = lhs->e1111111;
  // Order 8;
  res->e11111111 = lhs->e11111111;
  // Order 9;
  res->e111111111 = lhs->e111111111;
  // Order 10;
  res->e1111111111 = lhs->e1111111111;

}

onumm1n10_t onumm1n10_mul_oo(  onumm1n10_t* lhs,  onumm1n10_t* rhs){
  onumm1n10_t res;

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
  // Order 6;
  res.e111111 = lhs->r * rhs->e111111 + lhs->e111111 * rhs->r + lhs->e1 * rhs->e11111 
              + lhs->e11111 * rhs->e1 + lhs->e11 * rhs->e1111 + lhs->e1111 * rhs->e11 
              + lhs->e111 * rhs->e111;
  // Order 7;
  res.e1111111 = lhs->r * rhs->e1111111 + lhs->e1111111 * rhs->r + lhs->e1 * rhs->e111111 
               + lhs->e111111 * rhs->e1 + lhs->e11 * rhs->e11111 + lhs->e11111 * rhs->e11 
               + lhs->e111 * rhs->e1111 + lhs->e1111 * rhs->e111;
  // Order 8;
  res.e11111111 = lhs->r * rhs->e11111111 + lhs->e11111111 * rhs->r + lhs->e1 * rhs->e1111111 
                + lhs->e1111111 * rhs->e1 + lhs->e11 * rhs->e111111 + lhs->e111111 * rhs->e11 
                + lhs->e111 * rhs->e11111 + lhs->e11111 * rhs->e111 + lhs->e1111 * rhs->e1111;
  // Order 9;
  res.e111111111 = lhs->r * rhs->e111111111 + lhs->e111111111 * rhs->r + lhs->e1 * rhs->e11111111 
                 + lhs->e11111111 * rhs->e1 + lhs->e11 * rhs->e1111111 + lhs->e1111111 * rhs->e11 
                 + lhs->e111 * rhs->e111111 + lhs->e111111 * rhs->e111 + lhs->e1111 * rhs->e11111 
                 + lhs->e11111 * rhs->e1111;
  // Order 10;
  res.e1111111111 = lhs->r * rhs->e1111111111 + lhs->e1111111111 * rhs->r + lhs->e1 * rhs->e111111111 
                  + lhs->e111111111 * rhs->e1 + lhs->e11 * rhs->e11111111 + lhs->e11111111 * rhs->e11 
                  + lhs->e111 * rhs->e1111111 + lhs->e1111111 * rhs->e111 + lhs->e1111 * rhs->e111111 
                  + lhs->e111111 * rhs->e1111 + lhs->e11111 * rhs->e11111;

  return res;

}

void onumm1n10_mul_oo_to(  onumm1n10_t* lhs,  onumm1n10_t* rhs, onumm1n10_t* res){
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
  // Order 6;
  res->e111111 = lhs->r * rhs->e111111 + lhs->e111111 * rhs->r + lhs->e1 * rhs->e11111 
              + lhs->e11111 * rhs->e1 + lhs->e11 * rhs->e1111 + lhs->e1111 * rhs->e11 
              + lhs->e111 * rhs->e111;
  // Order 7;
  res->e1111111 = lhs->r * rhs->e1111111 + lhs->e1111111 * rhs->r + lhs->e1 * rhs->e111111 
               + lhs->e111111 * rhs->e1 + lhs->e11 * rhs->e11111 + lhs->e11111 * rhs->e11 
               + lhs->e111 * rhs->e1111 + lhs->e1111 * rhs->e111;
  // Order 8;
  res->e11111111 = lhs->r * rhs->e11111111 + lhs->e11111111 * rhs->r + lhs->e1 * rhs->e1111111 
                + lhs->e1111111 * rhs->e1 + lhs->e11 * rhs->e111111 + lhs->e111111 * rhs->e11 
                + lhs->e111 * rhs->e11111 + lhs->e11111 * rhs->e111 + lhs->e1111 * rhs->e1111;
  // Order 9;
  res->e111111111 = lhs->r * rhs->e111111111 + lhs->e111111111 * rhs->r + lhs->e1 * rhs->e11111111 
                 + lhs->e11111111 * rhs->e1 + lhs->e11 * rhs->e1111111 + lhs->e1111111 * rhs->e11 
                 + lhs->e111 * rhs->e111111 + lhs->e111111 * rhs->e111 + lhs->e1111 * rhs->e11111 
                 + lhs->e11111 * rhs->e1111;
  // Order 10;
  res->e1111111111 = lhs->r * rhs->e1111111111 + lhs->e1111111111 * rhs->r + lhs->e1 * rhs->e111111111 
                  + lhs->e111111111 * rhs->e1 + lhs->e11 * rhs->e11111111 + lhs->e11111111 * rhs->e11 
                  + lhs->e111 * rhs->e1111111 + lhs->e1111111 * rhs->e111 + lhs->e1111 * rhs->e111111 
                  + lhs->e111111 * rhs->e1111 + lhs->e11111 * rhs->e11111;

}

onumm1n10_t onumm1n10_mul_ro(  coeff_t lhs,  onumm1n10_t* rhs){
  onumm1n10_t res;

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
  // Order 6;
  res.e111111 = lhs * rhs->e111111;
  // Order 7;
  res.e1111111 = lhs * rhs->e1111111;
  // Order 8;
  res.e11111111 = lhs * rhs->e11111111;
  // Order 9;
  res.e111111111 = lhs * rhs->e111111111;
  // Order 10;
  res.e1111111111 = lhs * rhs->e1111111111;

  return res;

}

void onumm1n10_mul_ro_to(  coeff_t lhs,  onumm1n10_t* rhs, onumm1n10_t* res){
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
  // Order 6;
  res->e111111 = lhs * rhs->e111111;
  // Order 7;
  res->e1111111 = lhs * rhs->e1111111;
  // Order 8;
  res->e11111111 = lhs * rhs->e11111111;
  // Order 9;
  res->e111111111 = lhs * rhs->e111111111;
  // Order 10;
  res->e1111111111 = lhs * rhs->e1111111111;

}

onumm1n10_t onumm1n10_trunc_mul_oo(  onumm1n10_t* lhs,  onumm1n10_t* rhs){
  onumm1n10_t res;

  res = onumm1n10_init();

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
  // Order 6;
  res.e111111 =  + lhs->e1 * rhs->e11111 + lhs->e11111 * rhs->e1 + lhs->e11 * rhs->e1111 
              + lhs->e1111 * rhs->e11 + lhs->e111 * rhs->e111;
  // Order 7;
  res.e1111111 =  + lhs->e1 * rhs->e111111 + lhs->e111111 * rhs->e1 + lhs->e11 * rhs->e11111 
               + lhs->e11111 * rhs->e11 + lhs->e111 * rhs->e1111 + lhs->e1111 * rhs->e111;
  // Order 8;
  res.e11111111 =  + lhs->e1 * rhs->e1111111 + lhs->e1111111 * rhs->e1 + lhs->e11 * rhs->e111111 
                + lhs->e111111 * rhs->e11 + lhs->e111 * rhs->e11111 + lhs->e11111 * rhs->e111 
                + lhs->e1111 * rhs->e1111;
  // Order 9;
  res.e111111111 =  + lhs->e1 * rhs->e11111111 + lhs->e11111111 * rhs->e1 + lhs->e11 * rhs->e1111111 
                 + lhs->e1111111 * rhs->e11 + lhs->e111 * rhs->e111111 + lhs->e111111 * rhs->e111 
                 + lhs->e1111 * rhs->e11111 + lhs->e11111 * rhs->e1111;
  // Order 10;
  res.e1111111111 =  + lhs->e1 * rhs->e111111111 + lhs->e111111111 * rhs->e1 + lhs->e11 * rhs->e11111111 
                  + lhs->e11111111 * rhs->e11 + lhs->e111 * rhs->e1111111 + lhs->e1111111 * rhs->e111 
                  + lhs->e1111 * rhs->e111111 + lhs->e111111 * rhs->e1111 + lhs->e11111 * rhs->e11111;

  return res;

}

void onumm1n10_trunc_mul_oo_to(  onumm1n10_t* lhs,  onumm1n10_t* rhs, onumm1n10_t* res){
   (*res) = onumm1n10_init();

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
  // Order 6;
  res->e111111 =  + lhs->e1 * rhs->e11111 + lhs->e11111 * rhs->e1 + lhs->e11 * rhs->e1111 
              + lhs->e1111 * rhs->e11 + lhs->e111 * rhs->e111;
  // Order 7;
  res->e1111111 =  + lhs->e1 * rhs->e111111 + lhs->e111111 * rhs->e1 + lhs->e11 * rhs->e11111 
               + lhs->e11111 * rhs->e11 + lhs->e111 * rhs->e1111 + lhs->e1111 * rhs->e111;
  // Order 8;
  res->e11111111 =  + lhs->e1 * rhs->e1111111 + lhs->e1111111 * rhs->e1 + lhs->e11 * rhs->e111111 
                + lhs->e111111 * rhs->e11 + lhs->e111 * rhs->e11111 + lhs->e11111 * rhs->e111 
                + lhs->e1111 * rhs->e1111;
  // Order 9;
  res->e111111111 =  + lhs->e1 * rhs->e11111111 + lhs->e11111111 * rhs->e1 + lhs->e11 * rhs->e1111111 
                 + lhs->e1111111 * rhs->e11 + lhs->e111 * rhs->e111111 + lhs->e111111 * rhs->e111 
                 + lhs->e1111 * rhs->e11111 + lhs->e11111 * rhs->e1111;
  // Order 10;
  res->e1111111111 =  + lhs->e1 * rhs->e111111111 + lhs->e111111111 * rhs->e1 + lhs->e11 * rhs->e11111111 
                  + lhs->e11111111 * rhs->e11 + lhs->e111 * rhs->e1111111 + lhs->e1111111 * rhs->e111 
                  + lhs->e1111 * rhs->e111111 + lhs->e111111 * rhs->e1111 + lhs->e11111 * rhs->e11111;

}

onumm1n10_t onumm1n10_gem_oo(  onumm1n10_t* a,  onumm1n10_t* b,  onumm1n10_t* c){
  onumm1n10_t res;

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
  // Order 6;
  res.e111111 = c->e111111 + a->r * b->e111111 + a->e111111 * b->r + a->e1 * b->e11111 
              + a->e11111 * b->e1 + a->e11 * b->e1111 + a->e1111 * b->e11 
              + a->e111 * b->e111;
  // Order 7;
  res.e1111111 = c->e1111111 + a->r * b->e1111111 + a->e1111111 * b->r + a->e1 * b->e111111 
               + a->e111111 * b->e1 + a->e11 * b->e11111 + a->e11111 * b->e11 
               + a->e111 * b->e1111 + a->e1111 * b->e111;
  // Order 8;
  res.e11111111 = c->e11111111 + a->r * b->e11111111 + a->e11111111 * b->r + a->e1 * b->e1111111 
                + a->e1111111 * b->e1 + a->e11 * b->e111111 + a->e111111 * b->e11 
                + a->e111 * b->e11111 + a->e11111 * b->e111 + a->e1111 * b->e1111;
  // Order 9;
  res.e111111111 = c->e111111111 + a->r * b->e111111111 + a->e111111111 * b->r + a->e1 * b->e11111111 
                 + a->e11111111 * b->e1 + a->e11 * b->e1111111 + a->e1111111 * b->e11 
                 + a->e111 * b->e111111 + a->e111111 * b->e111 + a->e1111 * b->e11111 
                 + a->e11111 * b->e1111;
  // Order 10;
  res.e1111111111 = c->e1111111111 + a->r * b->e1111111111 + a->e1111111111 * b->r + a->e1 * b->e111111111 
                  + a->e111111111 * b->e1 + a->e11 * b->e11111111 + a->e11111111 * b->e11 
                  + a->e111 * b->e1111111 + a->e1111111 * b->e111 + a->e1111 * b->e111111 
                  + a->e111111 * b->e1111 + a->e11111 * b->e11111;

  return res;

}

void onumm1n10_gem_oo_to(  onumm1n10_t* a,  onumm1n10_t* b,  onumm1n10_t* c, onumm1n10_t* res){
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
  // Order 6;
  res->e111111 = c->e111111 + a->r * b->e111111 + a->e111111 * b->r + a->e1 * b->e11111 
              + a->e11111 * b->e1 + a->e11 * b->e1111 + a->e1111 * b->e11 
              + a->e111 * b->e111;
  // Order 7;
  res->e1111111 = c->e1111111 + a->r * b->e1111111 + a->e1111111 * b->r + a->e1 * b->e111111 
               + a->e111111 * b->e1 + a->e11 * b->e11111 + a->e11111 * b->e11 
               + a->e111 * b->e1111 + a->e1111 * b->e111;
  // Order 8;
  res->e11111111 = c->e11111111 + a->r * b->e11111111 + a->e11111111 * b->r + a->e1 * b->e1111111 
                + a->e1111111 * b->e1 + a->e11 * b->e111111 + a->e111111 * b->e11 
                + a->e111 * b->e11111 + a->e11111 * b->e111 + a->e1111 * b->e1111;
  // Order 9;
  res->e111111111 = c->e111111111 + a->r * b->e111111111 + a->e111111111 * b->r + a->e1 * b->e11111111 
                 + a->e11111111 * b->e1 + a->e11 * b->e1111111 + a->e1111111 * b->e11 
                 + a->e111 * b->e111111 + a->e111111 * b->e111 + a->e1111 * b->e11111 
                 + a->e11111 * b->e1111;
  // Order 10;
  res->e1111111111 = c->e1111111111 + a->r * b->e1111111111 + a->e1111111111 * b->r + a->e1 * b->e111111111 
                  + a->e111111111 * b->e1 + a->e11 * b->e11111111 + a->e11111111 * b->e11 
                  + a->e111 * b->e1111111 + a->e1111111 * b->e111 + a->e1111 * b->e111111 
                  + a->e111111 * b->e1111 + a->e11111 * b->e11111;

}

onumm1n10_t onumm1n10_gem_ro(  coeff_t a,  onumm1n10_t* b,  onumm1n10_t* c){
  onumm1n10_t res;

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
  // Order 6;
  res.e111111 = c->e111111 + a * b->e111111;
  // Order 7;
  res.e1111111 = c->e1111111 + a * b->e1111111;
  // Order 8;
  res.e11111111 = c->e11111111 + a * b->e11111111;
  // Order 9;
  res.e111111111 = c->e111111111 + a * b->e111111111;
  // Order 10;
  res.e1111111111 = c->e1111111111 + a * b->e1111111111;

  return res;

}

void onumm1n10_gem_ro_to(  coeff_t a,  onumm1n10_t* b,  onumm1n10_t* c, onumm1n10_t* res){
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
  // Order 6;
  res->e111111 = c->e111111 + a * b->e111111;
  // Order 7;
  res->e1111111 = c->e1111111 + a * b->e1111111;
  // Order 8;
  res->e11111111 = c->e11111111 + a * b->e11111111;
  // Order 9;
  res->e111111111 = c->e111111111 + a * b->e111111111;
  // Order 10;
  res->e1111111111 = c->e1111111111 + a * b->e1111111111;

}

void onumm1n10_trunc_gem_oo_to( ord_t ord_lhs,  onumm1n10_t* a,  ord_t ord_rhs,  onumm1n10_t* b,  onumm1n10_t* c, onumm1n10_t* res){
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
        case 2:
          // res order: 2
          res->e11 = c->e11 + a->r * b->e11;
          break;
        case 3:
          // res order: 3
          res->e111 = c->e111 + a->r * b->e111;
          break;
        case 4:
          // res order: 4
          res->e1111 = c->e1111 + a->r * b->e1111;
          break;
        case 5:
          // res order: 5
          res->e11111 = c->e11111 + a->r * b->e11111;
          break;
        case 6:
          // res order: 6
          res->e111111 = c->e111111 + a->r * b->e111111;
          break;
        case 7:
          // res order: 7
          res->e1111111 = c->e1111111 + a->r * b->e1111111;
          break;
        case 8:
          // res order: 8
          res->e11111111 = c->e11111111 + a->r * b->e11111111;
          break;
        case 9:
          // res order: 9
          res->e111111111 = c->e111111111 + a->r * b->e111111111;
          break;
        case 10:
          // res order: 10
          res->e1111111111 = c->e1111111111 + a->r * b->e1111111111;
          break;
      }
      break;
    case 1:
      switch( ord_rhs ){
        case 0:
          // res order: 1
          res->e1 = c->e1 + a->e1 * b->r;
          break;
        case 1:
          // res order: 2
          res->e11 = c->e11 + a->e1 * b->e1;
          break;
        case 2:
          // res order: 3
          res->e111 = c->e111 + a->e1 * b->e11;
          break;
        case 3:
          // res order: 4
          res->e1111 = c->e1111 + a->e1 * b->e111;
          break;
        case 4:
          // res order: 5
          res->e11111 = c->e11111 + a->e1 * b->e1111;
          break;
        case 5:
          // res order: 6
          res->e111111 = c->e111111 + a->e1 * b->e11111;
          break;
        case 6:
          // res order: 7
          res->e1111111 = c->e1111111 + a->e1 * b->e111111;
          break;
        case 7:
          // res order: 8
          res->e11111111 = c->e11111111 + a->e1 * b->e1111111;
          break;
        case 8:
          // res order: 9
          res->e111111111 = c->e111111111 + a->e1 * b->e11111111;
          break;
        case 9:
          // res order: 10
          res->e1111111111 = c->e1111111111 + a->e1 * b->e111111111;
          break;
      }
      break;
    case 2:
      switch( ord_rhs ){
        case 0:
          // res order: 2
          res->e11 = c->e11 + a->e11 * b->r;
          break;
        case 1:
          // res order: 3
          res->e111 = c->e111 + a->e11 * b->e1;
          break;
        case 2:
          // res order: 4
          res->e1111 = c->e1111 + a->e11 * b->e11;
          break;
        case 3:
          // res order: 5
          res->e11111 = c->e11111 + a->e11 * b->e111;
          break;
        case 4:
          // res order: 6
          res->e111111 = c->e111111 + a->e11 * b->e1111;
          break;
        case 5:
          // res order: 7
          res->e1111111 = c->e1111111 + a->e11 * b->e11111;
          break;
        case 6:
          // res order: 8
          res->e11111111 = c->e11111111 + a->e11 * b->e111111;
          break;
        case 7:
          // res order: 9
          res->e111111111 = c->e111111111 + a->e11 * b->e1111111;
          break;
        case 8:
          // res order: 10
          res->e1111111111 = c->e1111111111 + a->e11 * b->e11111111;
          break;
      }
      break;
    case 3:
      switch( ord_rhs ){
        case 0:
          // res order: 3
          res->e111 = c->e111 + a->e111 * b->r;
          break;
        case 1:
          // res order: 4
          res->e1111 = c->e1111 + a->e111 * b->e1;
          break;
        case 2:
          // res order: 5
          res->e11111 = c->e11111 + a->e111 * b->e11;
          break;
        case 3:
          // res order: 6
          res->e111111 = c->e111111 + a->e111 * b->e111;
          break;
        case 4:
          // res order: 7
          res->e1111111 = c->e1111111 + a->e111 * b->e1111;
          break;
        case 5:
          // res order: 8
          res->e11111111 = c->e11111111 + a->e111 * b->e11111;
          break;
        case 6:
          // res order: 9
          res->e111111111 = c->e111111111 + a->e111 * b->e111111;
          break;
        case 7:
          // res order: 10
          res->e1111111111 = c->e1111111111 + a->e111 * b->e1111111;
          break;
      }
      break;
    case 4:
      switch( ord_rhs ){
        case 0:
          // res order: 4
          res->e1111 = c->e1111 + a->e1111 * b->r;
          break;
        case 1:
          // res order: 5
          res->e11111 = c->e11111 + a->e1111 * b->e1;
          break;
        case 2:
          // res order: 6
          res->e111111 = c->e111111 + a->e1111 * b->e11;
          break;
        case 3:
          // res order: 7
          res->e1111111 = c->e1111111 + a->e1111 * b->e111;
          break;
        case 4:
          // res order: 8
          res->e11111111 = c->e11111111 + a->e1111 * b->e1111;
          break;
        case 5:
          // res order: 9
          res->e111111111 = c->e111111111 + a->e1111 * b->e11111;
          break;
        case 6:
          // res order: 10
          res->e1111111111 = c->e1111111111 + a->e1111 * b->e111111;
          break;
      }
      break;
    case 5:
      switch( ord_rhs ){
        case 0:
          // res order: 5
          res->e11111 = c->e11111 + a->e11111 * b->r;
          break;
        case 1:
          // res order: 6
          res->e111111 = c->e111111 + a->e11111 * b->e1;
          break;
        case 2:
          // res order: 7
          res->e1111111 = c->e1111111 + a->e11111 * b->e11;
          break;
        case 3:
          // res order: 8
          res->e11111111 = c->e11111111 + a->e11111 * b->e111;
          break;
        case 4:
          // res order: 9
          res->e111111111 = c->e111111111 + a->e11111 * b->e1111;
          break;
        case 5:
          // res order: 10
          res->e1111111111 = c->e1111111111 + a->e11111 * b->e11111;
          break;
      }
      break;
    case 6:
      switch( ord_rhs ){
        case 0:
          // res order: 6
          res->e111111 = c->e111111 + a->e111111 * b->r;
          break;
        case 1:
          // res order: 7
          res->e1111111 = c->e1111111 + a->e111111 * b->e1;
          break;
        case 2:
          // res order: 8
          res->e11111111 = c->e11111111 + a->e111111 * b->e11;
          break;
        case 3:
          // res order: 9
          res->e111111111 = c->e111111111 + a->e111111 * b->e111;
          break;
        case 4:
          // res order: 10
          res->e1111111111 = c->e1111111111 + a->e111111 * b->e1111;
          break;
      }
      break;
    case 7:
      switch( ord_rhs ){
        case 0:
          // res order: 7
          res->e1111111 = c->e1111111 + a->e1111111 * b->r;
          break;
        case 1:
          // res order: 8
          res->e11111111 = c->e11111111 + a->e1111111 * b->e1;
          break;
        case 2:
          // res order: 9
          res->e111111111 = c->e111111111 + a->e1111111 * b->e11;
          break;
        case 3:
          // res order: 10
          res->e1111111111 = c->e1111111111 + a->e1111111 * b->e111;
          break;
      }
      break;
    case 8:
      switch( ord_rhs ){
        case 0:
          // res order: 8
          res->e11111111 = c->e11111111 + a->e11111111 * b->r;
          break;
        case 1:
          // res order: 9
          res->e111111111 = c->e111111111 + a->e11111111 * b->e1;
          break;
        case 2:
          // res order: 10
          res->e1111111111 = c->e1111111111 + a->e11111111 * b->e11;
          break;
      }
      break;
    case 9:
      switch( ord_rhs ){
        case 0:
          // res order: 9
          res->e111111111 = c->e111111111 + a->e111111111 * b->r;
          break;
        case 1:
          // res order: 10
          res->e1111111111 = c->e1111111111 + a->e111111111 * b->e1;
          break;
      }
      break;
    case 10:
      switch( ord_rhs ){
        case 0:
          // res order: 10
          res->e1111111111 = c->e1111111111 + a->e1111111111 * b->r;
          break;
      }
      break;
  }

}

void onumm1n10_trunc_sum_oo_to(ord_t order, onumm1n10_t* lhs,onumm1n10_t* rhs, onumm1n10_t* res){
  // Addition like function 'lhs + rhs'
  switch(order){
    case(0):
      //  Real
      res->r = lhs->r + rhs->r;
      break;
    case(1):    // Order 1
      res->e1 = lhs->e1 + rhs->e1;
      break;
    case(2):    // Order 2
      res->e11 = lhs->e11 + rhs->e11;
      break;
    case(3):    // Order 3
      res->e111 = lhs->e111 + rhs->e111;
      break;
    case(4):    // Order 4
      res->e1111 = lhs->e1111 + rhs->e1111;
      break;
    case(5):    // Order 5
      res->e11111 = lhs->e11111 + rhs->e11111;
      break;
    case(6):    // Order 6
      res->e111111 = lhs->e111111 + rhs->e111111;
      break;
    case(7):    // Order 7
      res->e1111111 = lhs->e1111111 + rhs->e1111111;
      break;
    case(8):    // Order 8
      res->e11111111 = lhs->e11111111 + rhs->e11111111;
      break;
    case(9):    // Order 9
      res->e111111111 = lhs->e111111111 + rhs->e111111111;
      break;
    case(10):    // Order 10
      res->e1111111111 = lhs->e1111111111 + rhs->e1111111111;
      break;
  }
}

void onumm1n10_trunc_sub_oo_to(ord_t order, onumm1n10_t* lhs,onumm1n10_t* rhs, onumm1n10_t* res){
  // Addition like function 'lhs - rhs'
  switch(order){
    case(0):
      //  Real
      res->r = lhs->r - rhs->r;
      break;
    case(1):    // Order 1
      res->e1 = lhs->e1 - rhs->e1;
      break;
    case(2):    // Order 2
      res->e11 = lhs->e11 - rhs->e11;
      break;
    case(3):    // Order 3
      res->e111 = lhs->e111 - rhs->e111;
      break;
    case(4):    // Order 4
      res->e1111 = lhs->e1111 - rhs->e1111;
      break;
    case(5):    // Order 5
      res->e11111 = lhs->e11111 - rhs->e11111;
      break;
    case(6):    // Order 6
      res->e111111 = lhs->e111111 - rhs->e111111;
      break;
    case(7):    // Order 7
      res->e1111111 = lhs->e1111111 - rhs->e1111111;
      break;
    case(8):    // Order 8
      res->e11111111 = lhs->e11111111 - rhs->e11111111;
      break;
    case(9):    // Order 9
      res->e111111111 = lhs->e111111111 - rhs->e111111111;
      break;
    case(10):    // Order 10
      res->e1111111111 = lhs->e1111111111 - rhs->e1111111111;
      break;
  }
}

onumm1n10_t onumm1n10_feval(coeff_t* feval_re, onumm1n10_t* x){

  onumm1n10_t res;

  // feval function
  //  Definitions
  coeff_t factor=1, coef = 0;
  onumm1n10_t deltax = (*x), deltax_power = (*x);
  deltax.r = 0.0;
  deltax_power.r = 0.0;
  onumm1n10_set_r(0.0, &res);
  //  Real
  res.r = feval_re[0];
  // Order 1
  factor *=1;
  coef    = feval_re[1]/ factor;;
  onumm1n10_gem_ro_to( coef, &deltax_power, &res, &res);
  deltax_power = onumm1n10_mul_oo(&deltax_power,&deltax);
  // Order 2
  factor *=2;
  coef    = feval_re[2]/ factor;;
  onumm1n10_gem_ro_to( coef, &deltax_power, &res, &res);
  deltax_power = onumm1n10_mul_oo(&deltax_power,&deltax);
  // Order 3
  factor *=3;
  coef    = feval_re[3]/ factor;;
  onumm1n10_gem_ro_to( coef, &deltax_power, &res, &res);
  deltax_power = onumm1n10_mul_oo(&deltax_power,&deltax);
  // Order 4
  factor *=4;
  coef    = feval_re[4]/ factor;;
  onumm1n10_gem_ro_to( coef, &deltax_power, &res, &res);
  deltax_power = onumm1n10_mul_oo(&deltax_power,&deltax);
  // Order 5
  factor *=5;
  coef    = feval_re[5]/ factor;;
  onumm1n10_gem_ro_to( coef, &deltax_power, &res, &res);
  deltax_power = onumm1n10_mul_oo(&deltax_power,&deltax);
  // Order 6
  factor *=6;
  coef    = feval_re[6]/ factor;;
  onumm1n10_gem_ro_to( coef, &deltax_power, &res, &res);
  deltax_power = onumm1n10_mul_oo(&deltax_power,&deltax);
  // Order 7
  factor *=7;
  coef    = feval_re[7]/ factor;;
  onumm1n10_gem_ro_to( coef, &deltax_power, &res, &res);
  deltax_power = onumm1n10_mul_oo(&deltax_power,&deltax);
  // Order 8
  factor *=8;
  coef    = feval_re[8]/ factor;;
  onumm1n10_gem_ro_to( coef, &deltax_power, &res, &res);
  deltax_power = onumm1n10_mul_oo(&deltax_power,&deltax);
  // Order 9
  factor *=9;
  coef    = feval_re[9]/ factor;;
  onumm1n10_gem_ro_to( coef, &deltax_power, &res, &res);
  deltax_power = onumm1n10_mul_oo(&deltax_power,&deltax);
  // Order 10
  factor *=10;
  coef    = feval_re[10]/ factor;;
  onumm1n10_gem_ro_to( coef, &deltax_power, &res, &res);

  return res;

}

void onumm1n10_feval_to(coeff_t* feval_re, onumm1n10_t* x, onumm1n10_t* res){

  // feval function
  //  Definitions
  coeff_t factor=1, coef = 0;
  onumm1n10_t deltax = (*x), deltax_power = (*x);
  deltax.r = 0.0;
  deltax_power.r = 0.0;
  onumm1n10_set_r(0.0, res);
  //  Real
  res->r = feval_re[0];
  // Order 1
  factor *=1;
  coef    = feval_re[1]/ factor;;
  onumm1n10_gem_ro_to( coef, &deltax_power, res, res);
  deltax_power = onumm1n10_mul_oo(&deltax_power,&deltax);
  // Order 2
  factor *=2;
  coef    = feval_re[2]/ factor;;
  onumm1n10_gem_ro_to( coef, &deltax_power, res, res);
  deltax_power = onumm1n10_mul_oo(&deltax_power,&deltax);
  // Order 3
  factor *=3;
  coef    = feval_re[3]/ factor;;
  onumm1n10_gem_ro_to( coef, &deltax_power, res, res);
  deltax_power = onumm1n10_mul_oo(&deltax_power,&deltax);
  // Order 4
  factor *=4;
  coef    = feval_re[4]/ factor;;
  onumm1n10_gem_ro_to( coef, &deltax_power, res, res);
  deltax_power = onumm1n10_mul_oo(&deltax_power,&deltax);
  // Order 5
  factor *=5;
  coef    = feval_re[5]/ factor;;
  onumm1n10_gem_ro_to( coef, &deltax_power, res, res);
  deltax_power = onumm1n10_mul_oo(&deltax_power,&deltax);
  // Order 6
  factor *=6;
  coef    = feval_re[6]/ factor;;
  onumm1n10_gem_ro_to( coef, &deltax_power, res, res);
  deltax_power = onumm1n10_mul_oo(&deltax_power,&deltax);
  // Order 7
  factor *=7;
  coef    = feval_re[7]/ factor;;
  onumm1n10_gem_ro_to( coef, &deltax_power, res, res);
  deltax_power = onumm1n10_mul_oo(&deltax_power,&deltax);
  // Order 8
  factor *=8;
  coef    = feval_re[8]/ factor;;
  onumm1n10_gem_ro_to( coef, &deltax_power, res, res);
  deltax_power = onumm1n10_mul_oo(&deltax_power,&deltax);
  // Order 9
  factor *=9;
  coef    = feval_re[9]/ factor;;
  onumm1n10_gem_ro_to( coef, &deltax_power, res, res);
  deltax_power = onumm1n10_mul_oo(&deltax_power,&deltax);
  // Order 10
  factor *=10;
  coef    = feval_re[10]/ factor;;
  onumm1n10_gem_ro_to( coef, &deltax_power, res, res);

}

