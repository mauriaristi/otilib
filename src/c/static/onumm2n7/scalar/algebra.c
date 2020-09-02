
// Division.

// ****************************************************************************************************
onumm2n7_t onumm2n7_div_ro(coeff_t num, onumm2n7_t* den){

    
    onumm2n7_t inv = onumm2n7_pow(den,-1);
    onumm2n7_t res = onumm2n7_mul_ro(num,&inv);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
onumm2n7_t onumm2n7_div_oo(onumm2n7_t* num, onumm2n7_t* den){

    
    onumm2n7_t inv = onumm2n7_init();
    onumm2n7_pow_to(den,-1,&inv);
    onumm2n7_t res = onumm2n7_mul_oo(num,&inv);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
onumm2n7_t onumm2n7_div_or(onumm2n7_t* num, coeff_t val){

    return onumm2n7_mul_ro(1.0/val,num);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
onumm2n7_t onumm2n7_abs(onumm2n7_t* num){

	onumm2n7_t res;
    onumm2n7_abs_to(num,&res);
    return res;

}
// ----------------------------------------------------------------------------------------------------

onumm2n7_t onumm2n7_neg(  onumm2n7_t* lhs){

  onumm2n7_t res;

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
  // Order 3;
  res.e111 = -lhs->e111;
  res.e112 = -lhs->e112;
  res.e122 = -lhs->e122;
  res.e222 = -lhs->e222;
  // Order 4;
  res.e1111 = -lhs->e1111;
  res.e1112 = -lhs->e1112;
  res.e1122 = -lhs->e1122;
  res.e1222 = -lhs->e1222;
  res.e2222 = -lhs->e2222;
  // Order 5;
  res.e11111 = -lhs->e11111;
  res.e11112 = -lhs->e11112;
  res.e11122 = -lhs->e11122;
  res.e11222 = -lhs->e11222;
  res.e12222 = -lhs->e12222;
  res.e22222 = -lhs->e22222;
  // Order 6;
  res.e111111 = -lhs->e111111;
  res.e111112 = -lhs->e111112;
  res.e111122 = -lhs->e111122;
  res.e111222 = -lhs->e111222;
  res.e112222 = -lhs->e112222;
  res.e122222 = -lhs->e122222;
  res.e222222 = -lhs->e222222;
  // Order 7;
  res.e1111111 = -lhs->e1111111;
  res.e1111112 = -lhs->e1111112;
  res.e1111122 = -lhs->e1111122;
  res.e1111222 = -lhs->e1111222;
  res.e1112222 = -lhs->e1112222;
  res.e1122222 = -lhs->e1122222;
  res.e1222222 = -lhs->e1222222;
  res.e2222222 = -lhs->e2222222;

  return res;

}

void onumm2n7_neg_to(  onumm2n7_t* lhs, onumm2n7_t* res){

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
  // Order 3;
  res->e111 = -lhs->e111;
  res->e112 = -lhs->e112;
  res->e122 = -lhs->e122;
  res->e222 = -lhs->e222;
  // Order 4;
  res->e1111 = -lhs->e1111;
  res->e1112 = -lhs->e1112;
  res->e1122 = -lhs->e1122;
  res->e1222 = -lhs->e1222;
  res->e2222 = -lhs->e2222;
  // Order 5;
  res->e11111 = -lhs->e11111;
  res->e11112 = -lhs->e11112;
  res->e11122 = -lhs->e11122;
  res->e11222 = -lhs->e11222;
  res->e12222 = -lhs->e12222;
  res->e22222 = -lhs->e22222;
  // Order 6;
  res->e111111 = -lhs->e111111;
  res->e111112 = -lhs->e111112;
  res->e111122 = -lhs->e111122;
  res->e111222 = -lhs->e111222;
  res->e112222 = -lhs->e112222;
  res->e122222 = -lhs->e122222;
  res->e222222 = -lhs->e222222;
  // Order 7;
  res->e1111111 = -lhs->e1111111;
  res->e1111112 = -lhs->e1111112;
  res->e1111122 = -lhs->e1111122;
  res->e1111222 = -lhs->e1111222;
  res->e1112222 = -lhs->e1112222;
  res->e1122222 = -lhs->e1122222;
  res->e1222222 = -lhs->e1222222;
  res->e2222222 = -lhs->e2222222;

}

onumm2n7_t onumm2n7_sum_oo(  onumm2n7_t* lhs,  onumm2n7_t* rhs){
  onumm2n7_t res;

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
  // Order 3
  res.e111 = lhs->e111 + rhs->e111;
  res.e112 = lhs->e112 + rhs->e112;
  res.e122 = lhs->e122 + rhs->e122;
  res.e222 = lhs->e222 + rhs->e222;
  // Order 4
  res.e1111 = lhs->e1111 + rhs->e1111;
  res.e1112 = lhs->e1112 + rhs->e1112;
  res.e1122 = lhs->e1122 + rhs->e1122;
  res.e1222 = lhs->e1222 + rhs->e1222;
  res.e2222 = lhs->e2222 + rhs->e2222;
  // Order 5
  res.e11111 = lhs->e11111 + rhs->e11111;
  res.e11112 = lhs->e11112 + rhs->e11112;
  res.e11122 = lhs->e11122 + rhs->e11122;
  res.e11222 = lhs->e11222 + rhs->e11222;
  res.e12222 = lhs->e12222 + rhs->e12222;
  res.e22222 = lhs->e22222 + rhs->e22222;
  // Order 6
  res.e111111 = lhs->e111111 + rhs->e111111;
  res.e111112 = lhs->e111112 + rhs->e111112;
  res.e111122 = lhs->e111122 + rhs->e111122;
  res.e111222 = lhs->e111222 + rhs->e111222;
  res.e112222 = lhs->e112222 + rhs->e112222;
  res.e122222 = lhs->e122222 + rhs->e122222;
  res.e222222 = lhs->e222222 + rhs->e222222;
  // Order 7
  res.e1111111 = lhs->e1111111 + rhs->e1111111;
  res.e1111112 = lhs->e1111112 + rhs->e1111112;
  res.e1111122 = lhs->e1111122 + rhs->e1111122;
  res.e1111222 = lhs->e1111222 + rhs->e1111222;
  res.e1112222 = lhs->e1112222 + rhs->e1112222;
  res.e1122222 = lhs->e1122222 + rhs->e1122222;
  res.e1222222 = lhs->e1222222 + rhs->e1222222;
  res.e2222222 = lhs->e2222222 + rhs->e2222222;

  return res;

}

void onumm2n7_sum_oo_to(  onumm2n7_t* lhs,  onumm2n7_t* rhs, onumm2n7_t* res){
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
  // Order 3
  res->e111 = lhs->e111 + rhs->e111;
  res->e112 = lhs->e112 + rhs->e112;
  res->e122 = lhs->e122 + rhs->e122;
  res->e222 = lhs->e222 + rhs->e222;
  // Order 4
  res->e1111 = lhs->e1111 + rhs->e1111;
  res->e1112 = lhs->e1112 + rhs->e1112;
  res->e1122 = lhs->e1122 + rhs->e1122;
  res->e1222 = lhs->e1222 + rhs->e1222;
  res->e2222 = lhs->e2222 + rhs->e2222;
  // Order 5
  res->e11111 = lhs->e11111 + rhs->e11111;
  res->e11112 = lhs->e11112 + rhs->e11112;
  res->e11122 = lhs->e11122 + rhs->e11122;
  res->e11222 = lhs->e11222 + rhs->e11222;
  res->e12222 = lhs->e12222 + rhs->e12222;
  res->e22222 = lhs->e22222 + rhs->e22222;
  // Order 6
  res->e111111 = lhs->e111111 + rhs->e111111;
  res->e111112 = lhs->e111112 + rhs->e111112;
  res->e111122 = lhs->e111122 + rhs->e111122;
  res->e111222 = lhs->e111222 + rhs->e111222;
  res->e112222 = lhs->e112222 + rhs->e112222;
  res->e122222 = lhs->e122222 + rhs->e122222;
  res->e222222 = lhs->e222222 + rhs->e222222;
  // Order 7
  res->e1111111 = lhs->e1111111 + rhs->e1111111;
  res->e1111112 = lhs->e1111112 + rhs->e1111112;
  res->e1111122 = lhs->e1111122 + rhs->e1111122;
  res->e1111222 = lhs->e1111222 + rhs->e1111222;
  res->e1112222 = lhs->e1112222 + rhs->e1112222;
  res->e1122222 = lhs->e1122222 + rhs->e1122222;
  res->e1222222 = lhs->e1222222 + rhs->e1222222;
  res->e2222222 = lhs->e2222222 + rhs->e2222222;

}

onumm2n7_t onumm2n7_sum_ro(  coeff_t lhs,  onumm2n7_t* rhs){
  onumm2n7_t res;

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
  // Order 3;
  res.e111 =  + rhs->e111;
  res.e112 =  + rhs->e112;
  res.e122 =  + rhs->e122;
  res.e222 =  + rhs->e222;
  // Order 4;
  res.e1111 =  + rhs->e1111;
  res.e1112 =  + rhs->e1112;
  res.e1122 =  + rhs->e1122;
  res.e1222 =  + rhs->e1222;
  res.e2222 =  + rhs->e2222;
  // Order 5;
  res.e11111 =  + rhs->e11111;
  res.e11112 =  + rhs->e11112;
  res.e11122 =  + rhs->e11122;
  res.e11222 =  + rhs->e11222;
  res.e12222 =  + rhs->e12222;
  res.e22222 =  + rhs->e22222;
  // Order 6;
  res.e111111 =  + rhs->e111111;
  res.e111112 =  + rhs->e111112;
  res.e111122 =  + rhs->e111122;
  res.e111222 =  + rhs->e111222;
  res.e112222 =  + rhs->e112222;
  res.e122222 =  + rhs->e122222;
  res.e222222 =  + rhs->e222222;
  // Order 7;
  res.e1111111 =  + rhs->e1111111;
  res.e1111112 =  + rhs->e1111112;
  res.e1111122 =  + rhs->e1111122;
  res.e1111222 =  + rhs->e1111222;
  res.e1112222 =  + rhs->e1112222;
  res.e1122222 =  + rhs->e1122222;
  res.e1222222 =  + rhs->e1222222;
  res.e2222222 =  + rhs->e2222222;

  return res;

}

void onumm2n7_sum_ro_to(  coeff_t lhs,  onumm2n7_t* rhs, onumm2n7_t* res){
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
  // Order 3;
  res->e111 =  + rhs->e111;
  res->e112 =  + rhs->e112;
  res->e122 =  + rhs->e122;
  res->e222 =  + rhs->e222;
  // Order 4;
  res->e1111 =  + rhs->e1111;
  res->e1112 =  + rhs->e1112;
  res->e1122 =  + rhs->e1122;
  res->e1222 =  + rhs->e1222;
  res->e2222 =  + rhs->e2222;
  // Order 5;
  res->e11111 =  + rhs->e11111;
  res->e11112 =  + rhs->e11112;
  res->e11122 =  + rhs->e11122;
  res->e11222 =  + rhs->e11222;
  res->e12222 =  + rhs->e12222;
  res->e22222 =  + rhs->e22222;
  // Order 6;
  res->e111111 =  + rhs->e111111;
  res->e111112 =  + rhs->e111112;
  res->e111122 =  + rhs->e111122;
  res->e111222 =  + rhs->e111222;
  res->e112222 =  + rhs->e112222;
  res->e122222 =  + rhs->e122222;
  res->e222222 =  + rhs->e222222;
  // Order 7;
  res->e1111111 =  + rhs->e1111111;
  res->e1111112 =  + rhs->e1111112;
  res->e1111122 =  + rhs->e1111122;
  res->e1111222 =  + rhs->e1111222;
  res->e1112222 =  + rhs->e1112222;
  res->e1122222 =  + rhs->e1122222;
  res->e1222222 =  + rhs->e1222222;
  res->e2222222 =  + rhs->e2222222;

}

onumm2n7_t onumm2n7_sub_oo(  onumm2n7_t* lhs,  onumm2n7_t* rhs){
  onumm2n7_t res;

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
  // Order 3
  res.e111 = lhs->e111 - rhs->e111;
  res.e112 = lhs->e112 - rhs->e112;
  res.e122 = lhs->e122 - rhs->e122;
  res.e222 = lhs->e222 - rhs->e222;
  // Order 4
  res.e1111 = lhs->e1111 - rhs->e1111;
  res.e1112 = lhs->e1112 - rhs->e1112;
  res.e1122 = lhs->e1122 - rhs->e1122;
  res.e1222 = lhs->e1222 - rhs->e1222;
  res.e2222 = lhs->e2222 - rhs->e2222;
  // Order 5
  res.e11111 = lhs->e11111 - rhs->e11111;
  res.e11112 = lhs->e11112 - rhs->e11112;
  res.e11122 = lhs->e11122 - rhs->e11122;
  res.e11222 = lhs->e11222 - rhs->e11222;
  res.e12222 = lhs->e12222 - rhs->e12222;
  res.e22222 = lhs->e22222 - rhs->e22222;
  // Order 6
  res.e111111 = lhs->e111111 - rhs->e111111;
  res.e111112 = lhs->e111112 - rhs->e111112;
  res.e111122 = lhs->e111122 - rhs->e111122;
  res.e111222 = lhs->e111222 - rhs->e111222;
  res.e112222 = lhs->e112222 - rhs->e112222;
  res.e122222 = lhs->e122222 - rhs->e122222;
  res.e222222 = lhs->e222222 - rhs->e222222;
  // Order 7
  res.e1111111 = lhs->e1111111 - rhs->e1111111;
  res.e1111112 = lhs->e1111112 - rhs->e1111112;
  res.e1111122 = lhs->e1111122 - rhs->e1111122;
  res.e1111222 = lhs->e1111222 - rhs->e1111222;
  res.e1112222 = lhs->e1112222 - rhs->e1112222;
  res.e1122222 = lhs->e1122222 - rhs->e1122222;
  res.e1222222 = lhs->e1222222 - rhs->e1222222;
  res.e2222222 = lhs->e2222222 - rhs->e2222222;

  return res;

}

void onumm2n7_sub_oo_to(  onumm2n7_t* lhs,  onumm2n7_t* rhs, onumm2n7_t* res){
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
  // Order 3
  res->e111 = lhs->e111 - rhs->e111;
  res->e112 = lhs->e112 - rhs->e112;
  res->e122 = lhs->e122 - rhs->e122;
  res->e222 = lhs->e222 - rhs->e222;
  // Order 4
  res->e1111 = lhs->e1111 - rhs->e1111;
  res->e1112 = lhs->e1112 - rhs->e1112;
  res->e1122 = lhs->e1122 - rhs->e1122;
  res->e1222 = lhs->e1222 - rhs->e1222;
  res->e2222 = lhs->e2222 - rhs->e2222;
  // Order 5
  res->e11111 = lhs->e11111 - rhs->e11111;
  res->e11112 = lhs->e11112 - rhs->e11112;
  res->e11122 = lhs->e11122 - rhs->e11122;
  res->e11222 = lhs->e11222 - rhs->e11222;
  res->e12222 = lhs->e12222 - rhs->e12222;
  res->e22222 = lhs->e22222 - rhs->e22222;
  // Order 6
  res->e111111 = lhs->e111111 - rhs->e111111;
  res->e111112 = lhs->e111112 - rhs->e111112;
  res->e111122 = lhs->e111122 - rhs->e111122;
  res->e111222 = lhs->e111222 - rhs->e111222;
  res->e112222 = lhs->e112222 - rhs->e112222;
  res->e122222 = lhs->e122222 - rhs->e122222;
  res->e222222 = lhs->e222222 - rhs->e222222;
  // Order 7
  res->e1111111 = lhs->e1111111 - rhs->e1111111;
  res->e1111112 = lhs->e1111112 - rhs->e1111112;
  res->e1111122 = lhs->e1111122 - rhs->e1111122;
  res->e1111222 = lhs->e1111222 - rhs->e1111222;
  res->e1112222 = lhs->e1112222 - rhs->e1112222;
  res->e1122222 = lhs->e1122222 - rhs->e1122222;
  res->e1222222 = lhs->e1222222 - rhs->e1222222;
  res->e2222222 = lhs->e2222222 - rhs->e2222222;

}

onumm2n7_t onumm2n7_sub_ro(  coeff_t lhs,  onumm2n7_t* rhs){
  onumm2n7_t res;

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
  // Order 3;
  res.e111 =  - rhs->e111;
  res.e112 =  - rhs->e112;
  res.e122 =  - rhs->e122;
  res.e222 =  - rhs->e222;
  // Order 4;
  res.e1111 =  - rhs->e1111;
  res.e1112 =  - rhs->e1112;
  res.e1122 =  - rhs->e1122;
  res.e1222 =  - rhs->e1222;
  res.e2222 =  - rhs->e2222;
  // Order 5;
  res.e11111 =  - rhs->e11111;
  res.e11112 =  - rhs->e11112;
  res.e11122 =  - rhs->e11122;
  res.e11222 =  - rhs->e11222;
  res.e12222 =  - rhs->e12222;
  res.e22222 =  - rhs->e22222;
  // Order 6;
  res.e111111 =  - rhs->e111111;
  res.e111112 =  - rhs->e111112;
  res.e111122 =  - rhs->e111122;
  res.e111222 =  - rhs->e111222;
  res.e112222 =  - rhs->e112222;
  res.e122222 =  - rhs->e122222;
  res.e222222 =  - rhs->e222222;
  // Order 7;
  res.e1111111 =  - rhs->e1111111;
  res.e1111112 =  - rhs->e1111112;
  res.e1111122 =  - rhs->e1111122;
  res.e1111222 =  - rhs->e1111222;
  res.e1112222 =  - rhs->e1112222;
  res.e1122222 =  - rhs->e1122222;
  res.e1222222 =  - rhs->e1222222;
  res.e2222222 =  - rhs->e2222222;

  return res;

}

void onumm2n7_sub_ro_to(  coeff_t lhs,  onumm2n7_t* rhs, onumm2n7_t* res){
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
  // Order 3;
  res->e111 =  - rhs->e111;
  res->e112 =  - rhs->e112;
  res->e122 =  - rhs->e122;
  res->e222 =  - rhs->e222;
  // Order 4;
  res->e1111 =  - rhs->e1111;
  res->e1112 =  - rhs->e1112;
  res->e1122 =  - rhs->e1122;
  res->e1222 =  - rhs->e1222;
  res->e2222 =  - rhs->e2222;
  // Order 5;
  res->e11111 =  - rhs->e11111;
  res->e11112 =  - rhs->e11112;
  res->e11122 =  - rhs->e11122;
  res->e11222 =  - rhs->e11222;
  res->e12222 =  - rhs->e12222;
  res->e22222 =  - rhs->e22222;
  // Order 6;
  res->e111111 =  - rhs->e111111;
  res->e111112 =  - rhs->e111112;
  res->e111122 =  - rhs->e111122;
  res->e111222 =  - rhs->e111222;
  res->e112222 =  - rhs->e112222;
  res->e122222 =  - rhs->e122222;
  res->e222222 =  - rhs->e222222;
  // Order 7;
  res->e1111111 =  - rhs->e1111111;
  res->e1111112 =  - rhs->e1111112;
  res->e1111122 =  - rhs->e1111122;
  res->e1111222 =  - rhs->e1111222;
  res->e1112222 =  - rhs->e1112222;
  res->e1122222 =  - rhs->e1122222;
  res->e1222222 =  - rhs->e1222222;
  res->e2222222 =  - rhs->e2222222;

}

onumm2n7_t onumm2n7_sub_or(  onumm2n7_t* lhs,  coeff_t rhs){
  onumm2n7_t res;

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
  // Order 3;
  res.e111 = lhs->e111;
  res.e112 = lhs->e112;
  res.e122 = lhs->e122;
  res.e222 = lhs->e222;
  // Order 4;
  res.e1111 = lhs->e1111;
  res.e1112 = lhs->e1112;
  res.e1122 = lhs->e1122;
  res.e1222 = lhs->e1222;
  res.e2222 = lhs->e2222;
  // Order 5;
  res.e11111 = lhs->e11111;
  res.e11112 = lhs->e11112;
  res.e11122 = lhs->e11122;
  res.e11222 = lhs->e11222;
  res.e12222 = lhs->e12222;
  res.e22222 = lhs->e22222;
  // Order 6;
  res.e111111 = lhs->e111111;
  res.e111112 = lhs->e111112;
  res.e111122 = lhs->e111122;
  res.e111222 = lhs->e111222;
  res.e112222 = lhs->e112222;
  res.e122222 = lhs->e122222;
  res.e222222 = lhs->e222222;
  // Order 7;
  res.e1111111 = lhs->e1111111;
  res.e1111112 = lhs->e1111112;
  res.e1111122 = lhs->e1111122;
  res.e1111222 = lhs->e1111222;
  res.e1112222 = lhs->e1112222;
  res.e1122222 = lhs->e1122222;
  res.e1222222 = lhs->e1222222;
  res.e2222222 = lhs->e2222222;

  return res;

}

void onumm2n7_sub_or_to(  onumm2n7_t* lhs,  coeff_t rhs, onumm2n7_t* res){
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
  // Order 3;
  res->e111 = lhs->e111;
  res->e112 = lhs->e112;
  res->e122 = lhs->e122;
  res->e222 = lhs->e222;
  // Order 4;
  res->e1111 = lhs->e1111;
  res->e1112 = lhs->e1112;
  res->e1122 = lhs->e1122;
  res->e1222 = lhs->e1222;
  res->e2222 = lhs->e2222;
  // Order 5;
  res->e11111 = lhs->e11111;
  res->e11112 = lhs->e11112;
  res->e11122 = lhs->e11122;
  res->e11222 = lhs->e11222;
  res->e12222 = lhs->e12222;
  res->e22222 = lhs->e22222;
  // Order 6;
  res->e111111 = lhs->e111111;
  res->e111112 = lhs->e111112;
  res->e111122 = lhs->e111122;
  res->e111222 = lhs->e111222;
  res->e112222 = lhs->e112222;
  res->e122222 = lhs->e122222;
  res->e222222 = lhs->e222222;
  // Order 7;
  res->e1111111 = lhs->e1111111;
  res->e1111112 = lhs->e1111112;
  res->e1111122 = lhs->e1111122;
  res->e1111222 = lhs->e1111222;
  res->e1112222 = lhs->e1112222;
  res->e1122222 = lhs->e1122222;
  res->e1222222 = lhs->e1222222;
  res->e2222222 = lhs->e2222222;

}

onumm2n7_t onumm2n7_mul_oo(  onumm2n7_t* lhs,  onumm2n7_t* rhs){
  onumm2n7_t res;

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
  // Order 3;
  res.e111 = lhs->r * rhs->e111 + lhs->e111 * rhs->r + lhs->e1 * rhs->e11 
           + lhs->e11 * rhs->e1;
  res.e112 = lhs->r * rhs->e112 + lhs->e112 * rhs->r + lhs->e1 * rhs->e12 
           + lhs->e12 * rhs->e1 + lhs->e2 * rhs->e11 + lhs->e11 * rhs->e2;
  res.e122 = lhs->r * rhs->e122 + lhs->e122 * rhs->r + lhs->e1 * rhs->e22 
           + lhs->e22 * rhs->e1 + lhs->e2 * rhs->e12 + lhs->e12 * rhs->e2;
  res.e222 = lhs->r * rhs->e222 + lhs->e222 * rhs->r + lhs->e2 * rhs->e22 
           + lhs->e22 * rhs->e2;
  // Order 4;
  res.e1111 = lhs->r * rhs->e1111 + lhs->e1111 * rhs->r + lhs->e1 * rhs->e111 
            + lhs->e111 * rhs->e1 + lhs->e11 * rhs->e11;
  res.e1112 = lhs->r * rhs->e1112 + lhs->e1112 * rhs->r + lhs->e1 * rhs->e112 
            + lhs->e112 * rhs->e1 + lhs->e2 * rhs->e111 + lhs->e111 * rhs->e2 
            + lhs->e11 * rhs->e12 + lhs->e12 * rhs->e11;
  res.e1122 = lhs->r * rhs->e1122 + lhs->e1122 * rhs->r + lhs->e1 * rhs->e122 
            + lhs->e122 * rhs->e1 + lhs->e2 * rhs->e112 + lhs->e112 * rhs->e2 
            + lhs->e11 * rhs->e22 + lhs->e12 * rhs->e12 + lhs->e22 * rhs->e11;
  res.e1222 = lhs->r * rhs->e1222 + lhs->e1222 * rhs->r + lhs->e1 * rhs->e222 
            + lhs->e222 * rhs->e1 + lhs->e2 * rhs->e122 + lhs->e122 * rhs->e2 
            + lhs->e12 * rhs->e22 + lhs->e22 * rhs->e12;
  res.e2222 = lhs->r * rhs->e2222 + lhs->e2222 * rhs->r + lhs->e2 * rhs->e222 
            + lhs->e222 * rhs->e2 + lhs->e22 * rhs->e22;
  // Order 5;
  res.e11111 = lhs->r * rhs->e11111 + lhs->e11111 * rhs->r + lhs->e1 * rhs->e1111 
             + lhs->e1111 * rhs->e1 + lhs->e11 * rhs->e111 + lhs->e111 * rhs->e11;
  res.e11112 = lhs->r * rhs->e11112 + lhs->e11112 * rhs->r + lhs->e1 * rhs->e1112 
             + lhs->e1112 * rhs->e1 + lhs->e2 * rhs->e1111 + lhs->e1111 * rhs->e2 
             + lhs->e11 * rhs->e112 + lhs->e112 * rhs->e11 + lhs->e12 * rhs->e111 
             + lhs->e111 * rhs->e12;
  res.e11122 = lhs->r * rhs->e11122 + lhs->e11122 * rhs->r + lhs->e1 * rhs->e1122 
             + lhs->e1122 * rhs->e1 + lhs->e2 * rhs->e1112 + lhs->e1112 * rhs->e2 
             + lhs->e11 * rhs->e122 + lhs->e122 * rhs->e11 + lhs->e12 * rhs->e112 
             + lhs->e112 * rhs->e12 + lhs->e22 * rhs->e111 + lhs->e111 * rhs->e22;
  res.e11222 = lhs->r * rhs->e11222 + lhs->e11222 * rhs->r + lhs->e1 * rhs->e1222 
             + lhs->e1222 * rhs->e1 + lhs->e2 * rhs->e1122 + lhs->e1122 * rhs->e2 
             + lhs->e11 * rhs->e222 + lhs->e222 * rhs->e11 + lhs->e12 * rhs->e122 
             + lhs->e122 * rhs->e12 + lhs->e22 * rhs->e112 + lhs->e112 * rhs->e22;
  res.e12222 = lhs->r * rhs->e12222 + lhs->e12222 * rhs->r + lhs->e1 * rhs->e2222 
             + lhs->e2222 * rhs->e1 + lhs->e2 * rhs->e1222 + lhs->e1222 * rhs->e2 
             + lhs->e12 * rhs->e222 + lhs->e222 * rhs->e12 + lhs->e22 * rhs->e122 
             + lhs->e122 * rhs->e22;
  res.e22222 = lhs->r * rhs->e22222 + lhs->e22222 * rhs->r + lhs->e2 * rhs->e2222 
             + lhs->e2222 * rhs->e2 + lhs->e22 * rhs->e222 + lhs->e222 * rhs->e22;
  // Order 6;
  res.e111111 = lhs->r * rhs->e111111 + lhs->e111111 * rhs->r + lhs->e1 * rhs->e11111 
              + lhs->e11111 * rhs->e1 + lhs->e11 * rhs->e1111 + lhs->e1111 * rhs->e11 
              + lhs->e111 * rhs->e111;
  res.e111112 = lhs->r * rhs->e111112 + lhs->e111112 * rhs->r + lhs->e1 * rhs->e11112 
              + lhs->e11112 * rhs->e1 + lhs->e2 * rhs->e11111 + lhs->e11111 * rhs->e2 
              + lhs->e11 * rhs->e1112 + lhs->e1112 * rhs->e11 + lhs->e12 * rhs->e1111 
              + lhs->e1111 * rhs->e12 + lhs->e111 * rhs->e112 + lhs->e112 * rhs->e111;
  res.e111122 = lhs->r * rhs->e111122 + lhs->e111122 * rhs->r + lhs->e1 * rhs->e11122 
              + lhs->e11122 * rhs->e1 + lhs->e2 * rhs->e11112 + lhs->e11112 * rhs->e2 
              + lhs->e11 * rhs->e1122 + lhs->e1122 * rhs->e11 + lhs->e12 * rhs->e1112 
              + lhs->e1112 * rhs->e12 + lhs->e22 * rhs->e1111 + lhs->e1111 * rhs->e22 
              + lhs->e111 * rhs->e122 + lhs->e112 * rhs->e112 + lhs->e122 * rhs->e111;
  res.e111222 = lhs->r * rhs->e111222 + lhs->e111222 * rhs->r + lhs->e1 * rhs->e11222 
              + lhs->e11222 * rhs->e1 + lhs->e2 * rhs->e11122 + lhs->e11122 * rhs->e2 
              + lhs->e11 * rhs->e1222 + lhs->e1222 * rhs->e11 + lhs->e12 * rhs->e1122 
              + lhs->e1122 * rhs->e12 + lhs->e22 * rhs->e1112 + lhs->e1112 * rhs->e22 
              + lhs->e111 * rhs->e222 + lhs->e112 * rhs->e122 + lhs->e122 * rhs->e112 
              + lhs->e222 * rhs->e111;
  res.e112222 = lhs->r * rhs->e112222 + lhs->e112222 * rhs->r + lhs->e1 * rhs->e12222 
              + lhs->e12222 * rhs->e1 + lhs->e2 * rhs->e11222 + lhs->e11222 * rhs->e2 
              + lhs->e11 * rhs->e2222 + lhs->e2222 * rhs->e11 + lhs->e12 * rhs->e1222 
              + lhs->e1222 * rhs->e12 + lhs->e22 * rhs->e1122 + lhs->e1122 * rhs->e22 
              + lhs->e112 * rhs->e222 + lhs->e122 * rhs->e122 + lhs->e222 * rhs->e112;
  res.e122222 = lhs->r * rhs->e122222 + lhs->e122222 * rhs->r + lhs->e1 * rhs->e22222 
              + lhs->e22222 * rhs->e1 + lhs->e2 * rhs->e12222 + lhs->e12222 * rhs->e2 
              + lhs->e12 * rhs->e2222 + lhs->e2222 * rhs->e12 + lhs->e22 * rhs->e1222 
              + lhs->e1222 * rhs->e22 + lhs->e122 * rhs->e222 + lhs->e222 * rhs->e122;
  res.e222222 = lhs->r * rhs->e222222 + lhs->e222222 * rhs->r + lhs->e2 * rhs->e22222 
              + lhs->e22222 * rhs->e2 + lhs->e22 * rhs->e2222 + lhs->e2222 * rhs->e22 
              + lhs->e222 * rhs->e222;
  // Order 7;
  res.e1111111 = lhs->r * rhs->e1111111 + lhs->e1111111 * rhs->r + lhs->e1 * rhs->e111111 
               + lhs->e111111 * rhs->e1 + lhs->e11 * rhs->e11111 + lhs->e11111 * rhs->e11 
               + lhs->e111 * rhs->e1111 + lhs->e1111 * rhs->e111;
  res.e1111112 = lhs->r * rhs->e1111112 + lhs->e1111112 * rhs->r + lhs->e1 * rhs->e111112 
               + lhs->e111112 * rhs->e1 + lhs->e2 * rhs->e111111 + lhs->e111111 * rhs->e2 
               + lhs->e11 * rhs->e11112 + lhs->e11112 * rhs->e11 + lhs->e12 * rhs->e11111 
               + lhs->e11111 * rhs->e12 + lhs->e111 * rhs->e1112 + lhs->e1112 * rhs->e111 
               + lhs->e112 * rhs->e1111 + lhs->e1111 * rhs->e112;
  res.e1111122 = lhs->r * rhs->e1111122 + lhs->e1111122 * rhs->r + lhs->e1 * rhs->e111122 
               + lhs->e111122 * rhs->e1 + lhs->e2 * rhs->e111112 + lhs->e111112 * rhs->e2 
               + lhs->e11 * rhs->e11122 + lhs->e11122 * rhs->e11 + lhs->e12 * rhs->e11112 
               + lhs->e11112 * rhs->e12 + lhs->e22 * rhs->e11111 + lhs->e11111 * rhs->e22 
               + lhs->e111 * rhs->e1122 + lhs->e1122 * rhs->e111 + lhs->e112 * rhs->e1112 
               + lhs->e1112 * rhs->e112 + lhs->e122 * rhs->e1111 + lhs->e1111 * rhs->e122;
  res.e1111222 = lhs->r * rhs->e1111222 + lhs->e1111222 * rhs->r + lhs->e1 * rhs->e111222 
               + lhs->e111222 * rhs->e1 + lhs->e2 * rhs->e111122 + lhs->e111122 * rhs->e2 
               + lhs->e11 * rhs->e11222 + lhs->e11222 * rhs->e11 + lhs->e12 * rhs->e11122 
               + lhs->e11122 * rhs->e12 + lhs->e22 * rhs->e11112 + lhs->e11112 * rhs->e22 
               + lhs->e111 * rhs->e1222 + lhs->e1222 * rhs->e111 + lhs->e112 * rhs->e1122 
               + lhs->e1122 * rhs->e112 + lhs->e122 * rhs->e1112 + lhs->e1112 * rhs->e122 
               + lhs->e222 * rhs->e1111 + lhs->e1111 * rhs->e222;
  res.e1112222 = lhs->r * rhs->e1112222 + lhs->e1112222 * rhs->r + lhs->e1 * rhs->e112222 
               + lhs->e112222 * rhs->e1 + lhs->e2 * rhs->e111222 + lhs->e111222 * rhs->e2 
               + lhs->e11 * rhs->e12222 + lhs->e12222 * rhs->e11 + lhs->e12 * rhs->e11222 
               + lhs->e11222 * rhs->e12 + lhs->e22 * rhs->e11122 + lhs->e11122 * rhs->e22 
               + lhs->e111 * rhs->e2222 + lhs->e2222 * rhs->e111 + lhs->e112 * rhs->e1222 
               + lhs->e1222 * rhs->e112 + lhs->e122 * rhs->e1122 + lhs->e1122 * rhs->e122 
               + lhs->e222 * rhs->e1112 + lhs->e1112 * rhs->e222;
  res.e1122222 = lhs->r * rhs->e1122222 + lhs->e1122222 * rhs->r + lhs->e1 * rhs->e122222 
               + lhs->e122222 * rhs->e1 + lhs->e2 * rhs->e112222 + lhs->e112222 * rhs->e2 
               + lhs->e11 * rhs->e22222 + lhs->e22222 * rhs->e11 + lhs->e12 * rhs->e12222 
               + lhs->e12222 * rhs->e12 + lhs->e22 * rhs->e11222 + lhs->e11222 * rhs->e22 
               + lhs->e112 * rhs->e2222 + lhs->e2222 * rhs->e112 + lhs->e122 * rhs->e1222 
               + lhs->e1222 * rhs->e122 + lhs->e222 * rhs->e1122 + lhs->e1122 * rhs->e222;
  res.e1222222 = lhs->r * rhs->e1222222 + lhs->e1222222 * rhs->r + lhs->e1 * rhs->e222222 
               + lhs->e222222 * rhs->e1 + lhs->e2 * rhs->e122222 + lhs->e122222 * rhs->e2 
               + lhs->e12 * rhs->e22222 + lhs->e22222 * rhs->e12 + lhs->e22 * rhs->e12222 
               + lhs->e12222 * rhs->e22 + lhs->e122 * rhs->e2222 + lhs->e2222 * rhs->e122 
               + lhs->e222 * rhs->e1222 + lhs->e1222 * rhs->e222;
  res.e2222222 = lhs->r * rhs->e2222222 + lhs->e2222222 * rhs->r + lhs->e2 * rhs->e222222 
               + lhs->e222222 * rhs->e2 + lhs->e22 * rhs->e22222 + lhs->e22222 * rhs->e22 
               + lhs->e222 * rhs->e2222 + lhs->e2222 * rhs->e222;

  return res;

}

void onumm2n7_mul_oo_to(  onumm2n7_t* lhs,  onumm2n7_t* rhs, onumm2n7_t* res){
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
  // Order 3;
  res->e111 = lhs->r * rhs->e111 + lhs->e111 * rhs->r + lhs->e1 * rhs->e11 
           + lhs->e11 * rhs->e1;
  res->e112 = lhs->r * rhs->e112 + lhs->e112 * rhs->r + lhs->e1 * rhs->e12 
           + lhs->e12 * rhs->e1 + lhs->e2 * rhs->e11 + lhs->e11 * rhs->e2;
  res->e122 = lhs->r * rhs->e122 + lhs->e122 * rhs->r + lhs->e1 * rhs->e22 
           + lhs->e22 * rhs->e1 + lhs->e2 * rhs->e12 + lhs->e12 * rhs->e2;
  res->e222 = lhs->r * rhs->e222 + lhs->e222 * rhs->r + lhs->e2 * rhs->e22 
           + lhs->e22 * rhs->e2;
  // Order 4;
  res->e1111 = lhs->r * rhs->e1111 + lhs->e1111 * rhs->r + lhs->e1 * rhs->e111 
            + lhs->e111 * rhs->e1 + lhs->e11 * rhs->e11;
  res->e1112 = lhs->r * rhs->e1112 + lhs->e1112 * rhs->r + lhs->e1 * rhs->e112 
            + lhs->e112 * rhs->e1 + lhs->e2 * rhs->e111 + lhs->e111 * rhs->e2 
            + lhs->e11 * rhs->e12 + lhs->e12 * rhs->e11;
  res->e1122 = lhs->r * rhs->e1122 + lhs->e1122 * rhs->r + lhs->e1 * rhs->e122 
            + lhs->e122 * rhs->e1 + lhs->e2 * rhs->e112 + lhs->e112 * rhs->e2 
            + lhs->e11 * rhs->e22 + lhs->e12 * rhs->e12 + lhs->e22 * rhs->e11;
  res->e1222 = lhs->r * rhs->e1222 + lhs->e1222 * rhs->r + lhs->e1 * rhs->e222 
            + lhs->e222 * rhs->e1 + lhs->e2 * rhs->e122 + lhs->e122 * rhs->e2 
            + lhs->e12 * rhs->e22 + lhs->e22 * rhs->e12;
  res->e2222 = lhs->r * rhs->e2222 + lhs->e2222 * rhs->r + lhs->e2 * rhs->e222 
            + lhs->e222 * rhs->e2 + lhs->e22 * rhs->e22;
  // Order 5;
  res->e11111 = lhs->r * rhs->e11111 + lhs->e11111 * rhs->r + lhs->e1 * rhs->e1111 
             + lhs->e1111 * rhs->e1 + lhs->e11 * rhs->e111 + lhs->e111 * rhs->e11;
  res->e11112 = lhs->r * rhs->e11112 + lhs->e11112 * rhs->r + lhs->e1 * rhs->e1112 
             + lhs->e1112 * rhs->e1 + lhs->e2 * rhs->e1111 + lhs->e1111 * rhs->e2 
             + lhs->e11 * rhs->e112 + lhs->e112 * rhs->e11 + lhs->e12 * rhs->e111 
             + lhs->e111 * rhs->e12;
  res->e11122 = lhs->r * rhs->e11122 + lhs->e11122 * rhs->r + lhs->e1 * rhs->e1122 
             + lhs->e1122 * rhs->e1 + lhs->e2 * rhs->e1112 + lhs->e1112 * rhs->e2 
             + lhs->e11 * rhs->e122 + lhs->e122 * rhs->e11 + lhs->e12 * rhs->e112 
             + lhs->e112 * rhs->e12 + lhs->e22 * rhs->e111 + lhs->e111 * rhs->e22;
  res->e11222 = lhs->r * rhs->e11222 + lhs->e11222 * rhs->r + lhs->e1 * rhs->e1222 
             + lhs->e1222 * rhs->e1 + lhs->e2 * rhs->e1122 + lhs->e1122 * rhs->e2 
             + lhs->e11 * rhs->e222 + lhs->e222 * rhs->e11 + lhs->e12 * rhs->e122 
             + lhs->e122 * rhs->e12 + lhs->e22 * rhs->e112 + lhs->e112 * rhs->e22;
  res->e12222 = lhs->r * rhs->e12222 + lhs->e12222 * rhs->r + lhs->e1 * rhs->e2222 
             + lhs->e2222 * rhs->e1 + lhs->e2 * rhs->e1222 + lhs->e1222 * rhs->e2 
             + lhs->e12 * rhs->e222 + lhs->e222 * rhs->e12 + lhs->e22 * rhs->e122 
             + lhs->e122 * rhs->e22;
  res->e22222 = lhs->r * rhs->e22222 + lhs->e22222 * rhs->r + lhs->e2 * rhs->e2222 
             + lhs->e2222 * rhs->e2 + lhs->e22 * rhs->e222 + lhs->e222 * rhs->e22;
  // Order 6;
  res->e111111 = lhs->r * rhs->e111111 + lhs->e111111 * rhs->r + lhs->e1 * rhs->e11111 
              + lhs->e11111 * rhs->e1 + lhs->e11 * rhs->e1111 + lhs->e1111 * rhs->e11 
              + lhs->e111 * rhs->e111;
  res->e111112 = lhs->r * rhs->e111112 + lhs->e111112 * rhs->r + lhs->e1 * rhs->e11112 
              + lhs->e11112 * rhs->e1 + lhs->e2 * rhs->e11111 + lhs->e11111 * rhs->e2 
              + lhs->e11 * rhs->e1112 + lhs->e1112 * rhs->e11 + lhs->e12 * rhs->e1111 
              + lhs->e1111 * rhs->e12 + lhs->e111 * rhs->e112 + lhs->e112 * rhs->e111;
  res->e111122 = lhs->r * rhs->e111122 + lhs->e111122 * rhs->r + lhs->e1 * rhs->e11122 
              + lhs->e11122 * rhs->e1 + lhs->e2 * rhs->e11112 + lhs->e11112 * rhs->e2 
              + lhs->e11 * rhs->e1122 + lhs->e1122 * rhs->e11 + lhs->e12 * rhs->e1112 
              + lhs->e1112 * rhs->e12 + lhs->e22 * rhs->e1111 + lhs->e1111 * rhs->e22 
              + lhs->e111 * rhs->e122 + lhs->e112 * rhs->e112 + lhs->e122 * rhs->e111;
  res->e111222 = lhs->r * rhs->e111222 + lhs->e111222 * rhs->r + lhs->e1 * rhs->e11222 
              + lhs->e11222 * rhs->e1 + lhs->e2 * rhs->e11122 + lhs->e11122 * rhs->e2 
              + lhs->e11 * rhs->e1222 + lhs->e1222 * rhs->e11 + lhs->e12 * rhs->e1122 
              + lhs->e1122 * rhs->e12 + lhs->e22 * rhs->e1112 + lhs->e1112 * rhs->e22 
              + lhs->e111 * rhs->e222 + lhs->e112 * rhs->e122 + lhs->e122 * rhs->e112 
              + lhs->e222 * rhs->e111;
  res->e112222 = lhs->r * rhs->e112222 + lhs->e112222 * rhs->r + lhs->e1 * rhs->e12222 
              + lhs->e12222 * rhs->e1 + lhs->e2 * rhs->e11222 + lhs->e11222 * rhs->e2 
              + lhs->e11 * rhs->e2222 + lhs->e2222 * rhs->e11 + lhs->e12 * rhs->e1222 
              + lhs->e1222 * rhs->e12 + lhs->e22 * rhs->e1122 + lhs->e1122 * rhs->e22 
              + lhs->e112 * rhs->e222 + lhs->e122 * rhs->e122 + lhs->e222 * rhs->e112;
  res->e122222 = lhs->r * rhs->e122222 + lhs->e122222 * rhs->r + lhs->e1 * rhs->e22222 
              + lhs->e22222 * rhs->e1 + lhs->e2 * rhs->e12222 + lhs->e12222 * rhs->e2 
              + lhs->e12 * rhs->e2222 + lhs->e2222 * rhs->e12 + lhs->e22 * rhs->e1222 
              + lhs->e1222 * rhs->e22 + lhs->e122 * rhs->e222 + lhs->e222 * rhs->e122;
  res->e222222 = lhs->r * rhs->e222222 + lhs->e222222 * rhs->r + lhs->e2 * rhs->e22222 
              + lhs->e22222 * rhs->e2 + lhs->e22 * rhs->e2222 + lhs->e2222 * rhs->e22 
              + lhs->e222 * rhs->e222;
  // Order 7;
  res->e1111111 = lhs->r * rhs->e1111111 + lhs->e1111111 * rhs->r + lhs->e1 * rhs->e111111 
               + lhs->e111111 * rhs->e1 + lhs->e11 * rhs->e11111 + lhs->e11111 * rhs->e11 
               + lhs->e111 * rhs->e1111 + lhs->e1111 * rhs->e111;
  res->e1111112 = lhs->r * rhs->e1111112 + lhs->e1111112 * rhs->r + lhs->e1 * rhs->e111112 
               + lhs->e111112 * rhs->e1 + lhs->e2 * rhs->e111111 + lhs->e111111 * rhs->e2 
               + lhs->e11 * rhs->e11112 + lhs->e11112 * rhs->e11 + lhs->e12 * rhs->e11111 
               + lhs->e11111 * rhs->e12 + lhs->e111 * rhs->e1112 + lhs->e1112 * rhs->e111 
               + lhs->e112 * rhs->e1111 + lhs->e1111 * rhs->e112;
  res->e1111122 = lhs->r * rhs->e1111122 + lhs->e1111122 * rhs->r + lhs->e1 * rhs->e111122 
               + lhs->e111122 * rhs->e1 + lhs->e2 * rhs->e111112 + lhs->e111112 * rhs->e2 
               + lhs->e11 * rhs->e11122 + lhs->e11122 * rhs->e11 + lhs->e12 * rhs->e11112 
               + lhs->e11112 * rhs->e12 + lhs->e22 * rhs->e11111 + lhs->e11111 * rhs->e22 
               + lhs->e111 * rhs->e1122 + lhs->e1122 * rhs->e111 + lhs->e112 * rhs->e1112 
               + lhs->e1112 * rhs->e112 + lhs->e122 * rhs->e1111 + lhs->e1111 * rhs->e122;
  res->e1111222 = lhs->r * rhs->e1111222 + lhs->e1111222 * rhs->r + lhs->e1 * rhs->e111222 
               + lhs->e111222 * rhs->e1 + lhs->e2 * rhs->e111122 + lhs->e111122 * rhs->e2 
               + lhs->e11 * rhs->e11222 + lhs->e11222 * rhs->e11 + lhs->e12 * rhs->e11122 
               + lhs->e11122 * rhs->e12 + lhs->e22 * rhs->e11112 + lhs->e11112 * rhs->e22 
               + lhs->e111 * rhs->e1222 + lhs->e1222 * rhs->e111 + lhs->e112 * rhs->e1122 
               + lhs->e1122 * rhs->e112 + lhs->e122 * rhs->e1112 + lhs->e1112 * rhs->e122 
               + lhs->e222 * rhs->e1111 + lhs->e1111 * rhs->e222;
  res->e1112222 = lhs->r * rhs->e1112222 + lhs->e1112222 * rhs->r + lhs->e1 * rhs->e112222 
               + lhs->e112222 * rhs->e1 + lhs->e2 * rhs->e111222 + lhs->e111222 * rhs->e2 
               + lhs->e11 * rhs->e12222 + lhs->e12222 * rhs->e11 + lhs->e12 * rhs->e11222 
               + lhs->e11222 * rhs->e12 + lhs->e22 * rhs->e11122 + lhs->e11122 * rhs->e22 
               + lhs->e111 * rhs->e2222 + lhs->e2222 * rhs->e111 + lhs->e112 * rhs->e1222 
               + lhs->e1222 * rhs->e112 + lhs->e122 * rhs->e1122 + lhs->e1122 * rhs->e122 
               + lhs->e222 * rhs->e1112 + lhs->e1112 * rhs->e222;
  res->e1122222 = lhs->r * rhs->e1122222 + lhs->e1122222 * rhs->r + lhs->e1 * rhs->e122222 
               + lhs->e122222 * rhs->e1 + lhs->e2 * rhs->e112222 + lhs->e112222 * rhs->e2 
               + lhs->e11 * rhs->e22222 + lhs->e22222 * rhs->e11 + lhs->e12 * rhs->e12222 
               + lhs->e12222 * rhs->e12 + lhs->e22 * rhs->e11222 + lhs->e11222 * rhs->e22 
               + lhs->e112 * rhs->e2222 + lhs->e2222 * rhs->e112 + lhs->e122 * rhs->e1222 
               + lhs->e1222 * rhs->e122 + lhs->e222 * rhs->e1122 + lhs->e1122 * rhs->e222;
  res->e1222222 = lhs->r * rhs->e1222222 + lhs->e1222222 * rhs->r + lhs->e1 * rhs->e222222 
               + lhs->e222222 * rhs->e1 + lhs->e2 * rhs->e122222 + lhs->e122222 * rhs->e2 
               + lhs->e12 * rhs->e22222 + lhs->e22222 * rhs->e12 + lhs->e22 * rhs->e12222 
               + lhs->e12222 * rhs->e22 + lhs->e122 * rhs->e2222 + lhs->e2222 * rhs->e122 
               + lhs->e222 * rhs->e1222 + lhs->e1222 * rhs->e222;
  res->e2222222 = lhs->r * rhs->e2222222 + lhs->e2222222 * rhs->r + lhs->e2 * rhs->e222222 
               + lhs->e222222 * rhs->e2 + lhs->e22 * rhs->e22222 + lhs->e22222 * rhs->e22 
               + lhs->e222 * rhs->e2222 + lhs->e2222 * rhs->e222;

}

onumm2n7_t onumm2n7_mul_ro(  coeff_t lhs,  onumm2n7_t* rhs){
  onumm2n7_t res;

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
  // Order 3;
  res.e111 = lhs * rhs->e111;
  res.e112 = lhs * rhs->e112;
  res.e122 = lhs * rhs->e122;
  res.e222 = lhs * rhs->e222;
  // Order 4;
  res.e1111 = lhs * rhs->e1111;
  res.e1112 = lhs * rhs->e1112;
  res.e1122 = lhs * rhs->e1122;
  res.e1222 = lhs * rhs->e1222;
  res.e2222 = lhs * rhs->e2222;
  // Order 5;
  res.e11111 = lhs * rhs->e11111;
  res.e11112 = lhs * rhs->e11112;
  res.e11122 = lhs * rhs->e11122;
  res.e11222 = lhs * rhs->e11222;
  res.e12222 = lhs * rhs->e12222;
  res.e22222 = lhs * rhs->e22222;
  // Order 6;
  res.e111111 = lhs * rhs->e111111;
  res.e111112 = lhs * rhs->e111112;
  res.e111122 = lhs * rhs->e111122;
  res.e111222 = lhs * rhs->e111222;
  res.e112222 = lhs * rhs->e112222;
  res.e122222 = lhs * rhs->e122222;
  res.e222222 = lhs * rhs->e222222;
  // Order 7;
  res.e1111111 = lhs * rhs->e1111111;
  res.e1111112 = lhs * rhs->e1111112;
  res.e1111122 = lhs * rhs->e1111122;
  res.e1111222 = lhs * rhs->e1111222;
  res.e1112222 = lhs * rhs->e1112222;
  res.e1122222 = lhs * rhs->e1122222;
  res.e1222222 = lhs * rhs->e1222222;
  res.e2222222 = lhs * rhs->e2222222;

  return res;

}

void onumm2n7_mul_ro_to(  coeff_t lhs,  onumm2n7_t* rhs, onumm2n7_t* res){
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
  // Order 3;
  res->e111 = lhs * rhs->e111;
  res->e112 = lhs * rhs->e112;
  res->e122 = lhs * rhs->e122;
  res->e222 = lhs * rhs->e222;
  // Order 4;
  res->e1111 = lhs * rhs->e1111;
  res->e1112 = lhs * rhs->e1112;
  res->e1122 = lhs * rhs->e1122;
  res->e1222 = lhs * rhs->e1222;
  res->e2222 = lhs * rhs->e2222;
  // Order 5;
  res->e11111 = lhs * rhs->e11111;
  res->e11112 = lhs * rhs->e11112;
  res->e11122 = lhs * rhs->e11122;
  res->e11222 = lhs * rhs->e11222;
  res->e12222 = lhs * rhs->e12222;
  res->e22222 = lhs * rhs->e22222;
  // Order 6;
  res->e111111 = lhs * rhs->e111111;
  res->e111112 = lhs * rhs->e111112;
  res->e111122 = lhs * rhs->e111122;
  res->e111222 = lhs * rhs->e111222;
  res->e112222 = lhs * rhs->e112222;
  res->e122222 = lhs * rhs->e122222;
  res->e222222 = lhs * rhs->e222222;
  // Order 7;
  res->e1111111 = lhs * rhs->e1111111;
  res->e1111112 = lhs * rhs->e1111112;
  res->e1111122 = lhs * rhs->e1111122;
  res->e1111222 = lhs * rhs->e1111222;
  res->e1112222 = lhs * rhs->e1112222;
  res->e1122222 = lhs * rhs->e1122222;
  res->e1222222 = lhs * rhs->e1222222;
  res->e2222222 = lhs * rhs->e2222222;

}

onumm2n7_t onumm2n7_trunc_mul_oo(  onumm2n7_t* lhs,  onumm2n7_t* rhs){
  onumm2n7_t res;

  res = onumm2n7_init();

  //  Truncated multiplication like function 'lhs * rhs'
  // Order 2;
  res.e11 =  + lhs->e1 * rhs->e1;
  res.e12 =  + lhs->e1 * rhs->e2 + lhs->e2 * rhs->e1;
  res.e22 =  + lhs->e2 * rhs->e2;
  // Order 3;
  res.e111 =  + lhs->e1 * rhs->e11 + lhs->e11 * rhs->e1;
  res.e112 =  + lhs->e1 * rhs->e12 + lhs->e12 * rhs->e1 + lhs->e2 * rhs->e11 
           + lhs->e11 * rhs->e2;
  res.e122 =  + lhs->e1 * rhs->e22 + lhs->e22 * rhs->e1 + lhs->e2 * rhs->e12 
           + lhs->e12 * rhs->e2;
  res.e222 =  + lhs->e2 * rhs->e22 + lhs->e22 * rhs->e2;
  // Order 4;
  res.e1111 =  + lhs->e1 * rhs->e111 + lhs->e111 * rhs->e1 + lhs->e11 * rhs->e11;
  res.e1112 =  + lhs->e1 * rhs->e112 + lhs->e112 * rhs->e1 + lhs->e2 * rhs->e111 
            + lhs->e111 * rhs->e2 + lhs->e11 * rhs->e12 + lhs->e12 * rhs->e11;
  res.e1122 =  + lhs->e1 * rhs->e122 + lhs->e122 * rhs->e1 + lhs->e2 * rhs->e112 
            + lhs->e112 * rhs->e2 + lhs->e11 * rhs->e22 + lhs->e12 * rhs->e12 
            + lhs->e22 * rhs->e11;
  res.e1222 =  + lhs->e1 * rhs->e222 + lhs->e222 * rhs->e1 + lhs->e2 * rhs->e122 
            + lhs->e122 * rhs->e2 + lhs->e12 * rhs->e22 + lhs->e22 * rhs->e12;
  res.e2222 =  + lhs->e2 * rhs->e222 + lhs->e222 * rhs->e2 + lhs->e22 * rhs->e22;
  // Order 5;
  res.e11111 =  + lhs->e1 * rhs->e1111 + lhs->e1111 * rhs->e1 + lhs->e11 * rhs->e111 
             + lhs->e111 * rhs->e11;
  res.e11112 =  + lhs->e1 * rhs->e1112 + lhs->e1112 * rhs->e1 + lhs->e2 * rhs->e1111 
             + lhs->e1111 * rhs->e2 + lhs->e11 * rhs->e112 + lhs->e112 * rhs->e11 
             + lhs->e12 * rhs->e111 + lhs->e111 * rhs->e12;
  res.e11122 =  + lhs->e1 * rhs->e1122 + lhs->e1122 * rhs->e1 + lhs->e2 * rhs->e1112 
             + lhs->e1112 * rhs->e2 + lhs->e11 * rhs->e122 + lhs->e122 * rhs->e11 
             + lhs->e12 * rhs->e112 + lhs->e112 * rhs->e12 + lhs->e22 * rhs->e111 
             + lhs->e111 * rhs->e22;
  res.e11222 =  + lhs->e1 * rhs->e1222 + lhs->e1222 * rhs->e1 + lhs->e2 * rhs->e1122 
             + lhs->e1122 * rhs->e2 + lhs->e11 * rhs->e222 + lhs->e222 * rhs->e11 
             + lhs->e12 * rhs->e122 + lhs->e122 * rhs->e12 + lhs->e22 * rhs->e112 
             + lhs->e112 * rhs->e22;
  res.e12222 =  + lhs->e1 * rhs->e2222 + lhs->e2222 * rhs->e1 + lhs->e2 * rhs->e1222 
             + lhs->e1222 * rhs->e2 + lhs->e12 * rhs->e222 + lhs->e222 * rhs->e12 
             + lhs->e22 * rhs->e122 + lhs->e122 * rhs->e22;
  res.e22222 =  + lhs->e2 * rhs->e2222 + lhs->e2222 * rhs->e2 + lhs->e22 * rhs->e222 
             + lhs->e222 * rhs->e22;
  // Order 6;
  res.e111111 =  + lhs->e1 * rhs->e11111 + lhs->e11111 * rhs->e1 + lhs->e11 * rhs->e1111 
              + lhs->e1111 * rhs->e11 + lhs->e111 * rhs->e111;
  res.e111112 =  + lhs->e1 * rhs->e11112 + lhs->e11112 * rhs->e1 + lhs->e2 * rhs->e11111 
              + lhs->e11111 * rhs->e2 + lhs->e11 * rhs->e1112 + lhs->e1112 * rhs->e11 
              + lhs->e12 * rhs->e1111 + lhs->e1111 * rhs->e12 + lhs->e111 * rhs->e112 
              + lhs->e112 * rhs->e111;
  res.e111122 =  + lhs->e1 * rhs->e11122 + lhs->e11122 * rhs->e1 + lhs->e2 * rhs->e11112 
              + lhs->e11112 * rhs->e2 + lhs->e11 * rhs->e1122 + lhs->e1122 * rhs->e11 
              + lhs->e12 * rhs->e1112 + lhs->e1112 * rhs->e12 + lhs->e22 * rhs->e1111 
              + lhs->e1111 * rhs->e22 + lhs->e111 * rhs->e122 + lhs->e112 * rhs->e112 
              + lhs->e122 * rhs->e111;
  res.e111222 =  + lhs->e1 * rhs->e11222 + lhs->e11222 * rhs->e1 + lhs->e2 * rhs->e11122 
              + lhs->e11122 * rhs->e2 + lhs->e11 * rhs->e1222 + lhs->e1222 * rhs->e11 
              + lhs->e12 * rhs->e1122 + lhs->e1122 * rhs->e12 + lhs->e22 * rhs->e1112 
              + lhs->e1112 * rhs->e22 + lhs->e111 * rhs->e222 + lhs->e112 * rhs->e122 
              + lhs->e122 * rhs->e112 + lhs->e222 * rhs->e111;
  res.e112222 =  + lhs->e1 * rhs->e12222 + lhs->e12222 * rhs->e1 + lhs->e2 * rhs->e11222 
              + lhs->e11222 * rhs->e2 + lhs->e11 * rhs->e2222 + lhs->e2222 * rhs->e11 
              + lhs->e12 * rhs->e1222 + lhs->e1222 * rhs->e12 + lhs->e22 * rhs->e1122 
              + lhs->e1122 * rhs->e22 + lhs->e112 * rhs->e222 + lhs->e122 * rhs->e122 
              + lhs->e222 * rhs->e112;
  res.e122222 =  + lhs->e1 * rhs->e22222 + lhs->e22222 * rhs->e1 + lhs->e2 * rhs->e12222 
              + lhs->e12222 * rhs->e2 + lhs->e12 * rhs->e2222 + lhs->e2222 * rhs->e12 
              + lhs->e22 * rhs->e1222 + lhs->e1222 * rhs->e22 + lhs->e122 * rhs->e222 
              + lhs->e222 * rhs->e122;
  res.e222222 =  + lhs->e2 * rhs->e22222 + lhs->e22222 * rhs->e2 + lhs->e22 * rhs->e2222 
              + lhs->e2222 * rhs->e22 + lhs->e222 * rhs->e222;
  // Order 7;
  res.e1111111 =  + lhs->e1 * rhs->e111111 + lhs->e111111 * rhs->e1 + lhs->e11 * rhs->e11111 
               + lhs->e11111 * rhs->e11 + lhs->e111 * rhs->e1111 + lhs->e1111 * rhs->e111;
  res.e1111112 =  + lhs->e1 * rhs->e111112 + lhs->e111112 * rhs->e1 + lhs->e2 * rhs->e111111 
               + lhs->e111111 * rhs->e2 + lhs->e11 * rhs->e11112 + lhs->e11112 * rhs->e11 
               + lhs->e12 * rhs->e11111 + lhs->e11111 * rhs->e12 + lhs->e111 * rhs->e1112 
               + lhs->e1112 * rhs->e111 + lhs->e112 * rhs->e1111 + lhs->e1111 * rhs->e112;
  res.e1111122 =  + lhs->e1 * rhs->e111122 + lhs->e111122 * rhs->e1 + lhs->e2 * rhs->e111112 
               + lhs->e111112 * rhs->e2 + lhs->e11 * rhs->e11122 + lhs->e11122 * rhs->e11 
               + lhs->e12 * rhs->e11112 + lhs->e11112 * rhs->e12 + lhs->e22 * rhs->e11111 
               + lhs->e11111 * rhs->e22 + lhs->e111 * rhs->e1122 + lhs->e1122 * rhs->e111 
               + lhs->e112 * rhs->e1112 + lhs->e1112 * rhs->e112 + lhs->e122 * rhs->e1111 
               + lhs->e1111 * rhs->e122;
  res.e1111222 =  + lhs->e1 * rhs->e111222 + lhs->e111222 * rhs->e1 + lhs->e2 * rhs->e111122 
               + lhs->e111122 * rhs->e2 + lhs->e11 * rhs->e11222 + lhs->e11222 * rhs->e11 
               + lhs->e12 * rhs->e11122 + lhs->e11122 * rhs->e12 + lhs->e22 * rhs->e11112 
               + lhs->e11112 * rhs->e22 + lhs->e111 * rhs->e1222 + lhs->e1222 * rhs->e111 
               + lhs->e112 * rhs->e1122 + lhs->e1122 * rhs->e112 + lhs->e122 * rhs->e1112 
               + lhs->e1112 * rhs->e122 + lhs->e222 * rhs->e1111 + lhs->e1111 * rhs->e222;
  res.e1112222 =  + lhs->e1 * rhs->e112222 + lhs->e112222 * rhs->e1 + lhs->e2 * rhs->e111222 
               + lhs->e111222 * rhs->e2 + lhs->e11 * rhs->e12222 + lhs->e12222 * rhs->e11 
               + lhs->e12 * rhs->e11222 + lhs->e11222 * rhs->e12 + lhs->e22 * rhs->e11122 
               + lhs->e11122 * rhs->e22 + lhs->e111 * rhs->e2222 + lhs->e2222 * rhs->e111 
               + lhs->e112 * rhs->e1222 + lhs->e1222 * rhs->e112 + lhs->e122 * rhs->e1122 
               + lhs->e1122 * rhs->e122 + lhs->e222 * rhs->e1112 + lhs->e1112 * rhs->e222;
  res.e1122222 =  + lhs->e1 * rhs->e122222 + lhs->e122222 * rhs->e1 + lhs->e2 * rhs->e112222 
               + lhs->e112222 * rhs->e2 + lhs->e11 * rhs->e22222 + lhs->e22222 * rhs->e11 
               + lhs->e12 * rhs->e12222 + lhs->e12222 * rhs->e12 + lhs->e22 * rhs->e11222 
               + lhs->e11222 * rhs->e22 + lhs->e112 * rhs->e2222 + lhs->e2222 * rhs->e112 
               + lhs->e122 * rhs->e1222 + lhs->e1222 * rhs->e122 + lhs->e222 * rhs->e1122 
               + lhs->e1122 * rhs->e222;
  res.e1222222 =  + lhs->e1 * rhs->e222222 + lhs->e222222 * rhs->e1 + lhs->e2 * rhs->e122222 
               + lhs->e122222 * rhs->e2 + lhs->e12 * rhs->e22222 + lhs->e22222 * rhs->e12 
               + lhs->e22 * rhs->e12222 + lhs->e12222 * rhs->e22 + lhs->e122 * rhs->e2222 
               + lhs->e2222 * rhs->e122 + lhs->e222 * rhs->e1222 + lhs->e1222 * rhs->e222;
  res.e2222222 =  + lhs->e2 * rhs->e222222 + lhs->e222222 * rhs->e2 + lhs->e22 * rhs->e22222 
               + lhs->e22222 * rhs->e22 + lhs->e222 * rhs->e2222 + lhs->e2222 * rhs->e222;

  return res;

}

void onumm2n7_trunc_mul_oo_to(  onumm2n7_t* lhs,  onumm2n7_t* rhs, onumm2n7_t* res){
   (*res) = onumm2n7_init();

  //  Truncated multiplication like function 'lhs * rhs'
  // Order 2;
  res->e11 =  + lhs->e1 * rhs->e1;
  res->e12 =  + lhs->e1 * rhs->e2 + lhs->e2 * rhs->e1;
  res->e22 =  + lhs->e2 * rhs->e2;
  // Order 3;
  res->e111 =  + lhs->e1 * rhs->e11 + lhs->e11 * rhs->e1;
  res->e112 =  + lhs->e1 * rhs->e12 + lhs->e12 * rhs->e1 + lhs->e2 * rhs->e11 
           + lhs->e11 * rhs->e2;
  res->e122 =  + lhs->e1 * rhs->e22 + lhs->e22 * rhs->e1 + lhs->e2 * rhs->e12 
           + lhs->e12 * rhs->e2;
  res->e222 =  + lhs->e2 * rhs->e22 + lhs->e22 * rhs->e2;
  // Order 4;
  res->e1111 =  + lhs->e1 * rhs->e111 + lhs->e111 * rhs->e1 + lhs->e11 * rhs->e11;
  res->e1112 =  + lhs->e1 * rhs->e112 + lhs->e112 * rhs->e1 + lhs->e2 * rhs->e111 
            + lhs->e111 * rhs->e2 + lhs->e11 * rhs->e12 + lhs->e12 * rhs->e11;
  res->e1122 =  + lhs->e1 * rhs->e122 + lhs->e122 * rhs->e1 + lhs->e2 * rhs->e112 
            + lhs->e112 * rhs->e2 + lhs->e11 * rhs->e22 + lhs->e12 * rhs->e12 
            + lhs->e22 * rhs->e11;
  res->e1222 =  + lhs->e1 * rhs->e222 + lhs->e222 * rhs->e1 + lhs->e2 * rhs->e122 
            + lhs->e122 * rhs->e2 + lhs->e12 * rhs->e22 + lhs->e22 * rhs->e12;
  res->e2222 =  + lhs->e2 * rhs->e222 + lhs->e222 * rhs->e2 + lhs->e22 * rhs->e22;
  // Order 5;
  res->e11111 =  + lhs->e1 * rhs->e1111 + lhs->e1111 * rhs->e1 + lhs->e11 * rhs->e111 
             + lhs->e111 * rhs->e11;
  res->e11112 =  + lhs->e1 * rhs->e1112 + lhs->e1112 * rhs->e1 + lhs->e2 * rhs->e1111 
             + lhs->e1111 * rhs->e2 + lhs->e11 * rhs->e112 + lhs->e112 * rhs->e11 
             + lhs->e12 * rhs->e111 + lhs->e111 * rhs->e12;
  res->e11122 =  + lhs->e1 * rhs->e1122 + lhs->e1122 * rhs->e1 + lhs->e2 * rhs->e1112 
             + lhs->e1112 * rhs->e2 + lhs->e11 * rhs->e122 + lhs->e122 * rhs->e11 
             + lhs->e12 * rhs->e112 + lhs->e112 * rhs->e12 + lhs->e22 * rhs->e111 
             + lhs->e111 * rhs->e22;
  res->e11222 =  + lhs->e1 * rhs->e1222 + lhs->e1222 * rhs->e1 + lhs->e2 * rhs->e1122 
             + lhs->e1122 * rhs->e2 + lhs->e11 * rhs->e222 + lhs->e222 * rhs->e11 
             + lhs->e12 * rhs->e122 + lhs->e122 * rhs->e12 + lhs->e22 * rhs->e112 
             + lhs->e112 * rhs->e22;
  res->e12222 =  + lhs->e1 * rhs->e2222 + lhs->e2222 * rhs->e1 + lhs->e2 * rhs->e1222 
             + lhs->e1222 * rhs->e2 + lhs->e12 * rhs->e222 + lhs->e222 * rhs->e12 
             + lhs->e22 * rhs->e122 + lhs->e122 * rhs->e22;
  res->e22222 =  + lhs->e2 * rhs->e2222 + lhs->e2222 * rhs->e2 + lhs->e22 * rhs->e222 
             + lhs->e222 * rhs->e22;
  // Order 6;
  res->e111111 =  + lhs->e1 * rhs->e11111 + lhs->e11111 * rhs->e1 + lhs->e11 * rhs->e1111 
              + lhs->e1111 * rhs->e11 + lhs->e111 * rhs->e111;
  res->e111112 =  + lhs->e1 * rhs->e11112 + lhs->e11112 * rhs->e1 + lhs->e2 * rhs->e11111 
              + lhs->e11111 * rhs->e2 + lhs->e11 * rhs->e1112 + lhs->e1112 * rhs->e11 
              + lhs->e12 * rhs->e1111 + lhs->e1111 * rhs->e12 + lhs->e111 * rhs->e112 
              + lhs->e112 * rhs->e111;
  res->e111122 =  + lhs->e1 * rhs->e11122 + lhs->e11122 * rhs->e1 + lhs->e2 * rhs->e11112 
              + lhs->e11112 * rhs->e2 + lhs->e11 * rhs->e1122 + lhs->e1122 * rhs->e11 
              + lhs->e12 * rhs->e1112 + lhs->e1112 * rhs->e12 + lhs->e22 * rhs->e1111 
              + lhs->e1111 * rhs->e22 + lhs->e111 * rhs->e122 + lhs->e112 * rhs->e112 
              + lhs->e122 * rhs->e111;
  res->e111222 =  + lhs->e1 * rhs->e11222 + lhs->e11222 * rhs->e1 + lhs->e2 * rhs->e11122 
              + lhs->e11122 * rhs->e2 + lhs->e11 * rhs->e1222 + lhs->e1222 * rhs->e11 
              + lhs->e12 * rhs->e1122 + lhs->e1122 * rhs->e12 + lhs->e22 * rhs->e1112 
              + lhs->e1112 * rhs->e22 + lhs->e111 * rhs->e222 + lhs->e112 * rhs->e122 
              + lhs->e122 * rhs->e112 + lhs->e222 * rhs->e111;
  res->e112222 =  + lhs->e1 * rhs->e12222 + lhs->e12222 * rhs->e1 + lhs->e2 * rhs->e11222 
              + lhs->e11222 * rhs->e2 + lhs->e11 * rhs->e2222 + lhs->e2222 * rhs->e11 
              + lhs->e12 * rhs->e1222 + lhs->e1222 * rhs->e12 + lhs->e22 * rhs->e1122 
              + lhs->e1122 * rhs->e22 + lhs->e112 * rhs->e222 + lhs->e122 * rhs->e122 
              + lhs->e222 * rhs->e112;
  res->e122222 =  + lhs->e1 * rhs->e22222 + lhs->e22222 * rhs->e1 + lhs->e2 * rhs->e12222 
              + lhs->e12222 * rhs->e2 + lhs->e12 * rhs->e2222 + lhs->e2222 * rhs->e12 
              + lhs->e22 * rhs->e1222 + lhs->e1222 * rhs->e22 + lhs->e122 * rhs->e222 
              + lhs->e222 * rhs->e122;
  res->e222222 =  + lhs->e2 * rhs->e22222 + lhs->e22222 * rhs->e2 + lhs->e22 * rhs->e2222 
              + lhs->e2222 * rhs->e22 + lhs->e222 * rhs->e222;
  // Order 7;
  res->e1111111 =  + lhs->e1 * rhs->e111111 + lhs->e111111 * rhs->e1 + lhs->e11 * rhs->e11111 
               + lhs->e11111 * rhs->e11 + lhs->e111 * rhs->e1111 + lhs->e1111 * rhs->e111;
  res->e1111112 =  + lhs->e1 * rhs->e111112 + lhs->e111112 * rhs->e1 + lhs->e2 * rhs->e111111 
               + lhs->e111111 * rhs->e2 + lhs->e11 * rhs->e11112 + lhs->e11112 * rhs->e11 
               + lhs->e12 * rhs->e11111 + lhs->e11111 * rhs->e12 + lhs->e111 * rhs->e1112 
               + lhs->e1112 * rhs->e111 + lhs->e112 * rhs->e1111 + lhs->e1111 * rhs->e112;
  res->e1111122 =  + lhs->e1 * rhs->e111122 + lhs->e111122 * rhs->e1 + lhs->e2 * rhs->e111112 
               + lhs->e111112 * rhs->e2 + lhs->e11 * rhs->e11122 + lhs->e11122 * rhs->e11 
               + lhs->e12 * rhs->e11112 + lhs->e11112 * rhs->e12 + lhs->e22 * rhs->e11111 
               + lhs->e11111 * rhs->e22 + lhs->e111 * rhs->e1122 + lhs->e1122 * rhs->e111 
               + lhs->e112 * rhs->e1112 + lhs->e1112 * rhs->e112 + lhs->e122 * rhs->e1111 
               + lhs->e1111 * rhs->e122;
  res->e1111222 =  + lhs->e1 * rhs->e111222 + lhs->e111222 * rhs->e1 + lhs->e2 * rhs->e111122 
               + lhs->e111122 * rhs->e2 + lhs->e11 * rhs->e11222 + lhs->e11222 * rhs->e11 
               + lhs->e12 * rhs->e11122 + lhs->e11122 * rhs->e12 + lhs->e22 * rhs->e11112 
               + lhs->e11112 * rhs->e22 + lhs->e111 * rhs->e1222 + lhs->e1222 * rhs->e111 
               + lhs->e112 * rhs->e1122 + lhs->e1122 * rhs->e112 + lhs->e122 * rhs->e1112 
               + lhs->e1112 * rhs->e122 + lhs->e222 * rhs->e1111 + lhs->e1111 * rhs->e222;
  res->e1112222 =  + lhs->e1 * rhs->e112222 + lhs->e112222 * rhs->e1 + lhs->e2 * rhs->e111222 
               + lhs->e111222 * rhs->e2 + lhs->e11 * rhs->e12222 + lhs->e12222 * rhs->e11 
               + lhs->e12 * rhs->e11222 + lhs->e11222 * rhs->e12 + lhs->e22 * rhs->e11122 
               + lhs->e11122 * rhs->e22 + lhs->e111 * rhs->e2222 + lhs->e2222 * rhs->e111 
               + lhs->e112 * rhs->e1222 + lhs->e1222 * rhs->e112 + lhs->e122 * rhs->e1122 
               + lhs->e1122 * rhs->e122 + lhs->e222 * rhs->e1112 + lhs->e1112 * rhs->e222;
  res->e1122222 =  + lhs->e1 * rhs->e122222 + lhs->e122222 * rhs->e1 + lhs->e2 * rhs->e112222 
               + lhs->e112222 * rhs->e2 + lhs->e11 * rhs->e22222 + lhs->e22222 * rhs->e11 
               + lhs->e12 * rhs->e12222 + lhs->e12222 * rhs->e12 + lhs->e22 * rhs->e11222 
               + lhs->e11222 * rhs->e22 + lhs->e112 * rhs->e2222 + lhs->e2222 * rhs->e112 
               + lhs->e122 * rhs->e1222 + lhs->e1222 * rhs->e122 + lhs->e222 * rhs->e1122 
               + lhs->e1122 * rhs->e222;
  res->e1222222 =  + lhs->e1 * rhs->e222222 + lhs->e222222 * rhs->e1 + lhs->e2 * rhs->e122222 
               + lhs->e122222 * rhs->e2 + lhs->e12 * rhs->e22222 + lhs->e22222 * rhs->e12 
               + lhs->e22 * rhs->e12222 + lhs->e12222 * rhs->e22 + lhs->e122 * rhs->e2222 
               + lhs->e2222 * rhs->e122 + lhs->e222 * rhs->e1222 + lhs->e1222 * rhs->e222;
  res->e2222222 =  + lhs->e2 * rhs->e222222 + lhs->e222222 * rhs->e2 + lhs->e22 * rhs->e22222 
               + lhs->e22222 * rhs->e22 + lhs->e222 * rhs->e2222 + lhs->e2222 * rhs->e222;

}

onumm2n7_t onumm2n7_gem_oo(  onumm2n7_t* a,  onumm2n7_t* b,  onumm2n7_t* c){
  onumm2n7_t res;

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
  // Order 3;
  res.e111 = c->e111 + a->r * b->e111 + a->e111 * b->r + a->e1 * b->e11 
           + a->e11 * b->e1;
  res.e112 = c->e112 + a->r * b->e112 + a->e112 * b->r + a->e1 * b->e12 
           + a->e12 * b->e1 + a->e2 * b->e11 + a->e11 * b->e2;
  res.e122 = c->e122 + a->r * b->e122 + a->e122 * b->r + a->e1 * b->e22 
           + a->e22 * b->e1 + a->e2 * b->e12 + a->e12 * b->e2;
  res.e222 = c->e222 + a->r * b->e222 + a->e222 * b->r + a->e2 * b->e22 
           + a->e22 * b->e2;
  // Order 4;
  res.e1111 = c->e1111 + a->r * b->e1111 + a->e1111 * b->r + a->e1 * b->e111 
            + a->e111 * b->e1 + a->e11 * b->e11;
  res.e1112 = c->e1112 + a->r * b->e1112 + a->e1112 * b->r + a->e1 * b->e112 
            + a->e112 * b->e1 + a->e2 * b->e111 + a->e111 * b->e2 
            + a->e11 * b->e12 + a->e12 * b->e11;
  res.e1122 = c->e1122 + a->r * b->e1122 + a->e1122 * b->r + a->e1 * b->e122 
            + a->e122 * b->e1 + a->e2 * b->e112 + a->e112 * b->e2 
            + a->e11 * b->e22 + a->e12 * b->e12 + a->e22 * b->e11;
  res.e1222 = c->e1222 + a->r * b->e1222 + a->e1222 * b->r + a->e1 * b->e222 
            + a->e222 * b->e1 + a->e2 * b->e122 + a->e122 * b->e2 
            + a->e12 * b->e22 + a->e22 * b->e12;
  res.e2222 = c->e2222 + a->r * b->e2222 + a->e2222 * b->r + a->e2 * b->e222 
            + a->e222 * b->e2 + a->e22 * b->e22;
  // Order 5;
  res.e11111 = c->e11111 + a->r * b->e11111 + a->e11111 * b->r + a->e1 * b->e1111 
             + a->e1111 * b->e1 + a->e11 * b->e111 + a->e111 * b->e11;
  res.e11112 = c->e11112 + a->r * b->e11112 + a->e11112 * b->r + a->e1 * b->e1112 
             + a->e1112 * b->e1 + a->e2 * b->e1111 + a->e1111 * b->e2 
             + a->e11 * b->e112 + a->e112 * b->e11 + a->e12 * b->e111 
             + a->e111 * b->e12;
  res.e11122 = c->e11122 + a->r * b->e11122 + a->e11122 * b->r + a->e1 * b->e1122 
             + a->e1122 * b->e1 + a->e2 * b->e1112 + a->e1112 * b->e2 
             + a->e11 * b->e122 + a->e122 * b->e11 + a->e12 * b->e112 
             + a->e112 * b->e12 + a->e22 * b->e111 + a->e111 * b->e22;
  res.e11222 = c->e11222 + a->r * b->e11222 + a->e11222 * b->r + a->e1 * b->e1222 
             + a->e1222 * b->e1 + a->e2 * b->e1122 + a->e1122 * b->e2 
             + a->e11 * b->e222 + a->e222 * b->e11 + a->e12 * b->e122 
             + a->e122 * b->e12 + a->e22 * b->e112 + a->e112 * b->e22;
  res.e12222 = c->e12222 + a->r * b->e12222 + a->e12222 * b->r + a->e1 * b->e2222 
             + a->e2222 * b->e1 + a->e2 * b->e1222 + a->e1222 * b->e2 
             + a->e12 * b->e222 + a->e222 * b->e12 + a->e22 * b->e122 
             + a->e122 * b->e22;
  res.e22222 = c->e22222 + a->r * b->e22222 + a->e22222 * b->r + a->e2 * b->e2222 
             + a->e2222 * b->e2 + a->e22 * b->e222 + a->e222 * b->e22;
  // Order 6;
  res.e111111 = c->e111111 + a->r * b->e111111 + a->e111111 * b->r + a->e1 * b->e11111 
              + a->e11111 * b->e1 + a->e11 * b->e1111 + a->e1111 * b->e11 
              + a->e111 * b->e111;
  res.e111112 = c->e111112 + a->r * b->e111112 + a->e111112 * b->r + a->e1 * b->e11112 
              + a->e11112 * b->e1 + a->e2 * b->e11111 + a->e11111 * b->e2 
              + a->e11 * b->e1112 + a->e1112 * b->e11 + a->e12 * b->e1111 
              + a->e1111 * b->e12 + a->e111 * b->e112 + a->e112 * b->e111;
  res.e111122 = c->e111122 + a->r * b->e111122 + a->e111122 * b->r + a->e1 * b->e11122 
              + a->e11122 * b->e1 + a->e2 * b->e11112 + a->e11112 * b->e2 
              + a->e11 * b->e1122 + a->e1122 * b->e11 + a->e12 * b->e1112 
              + a->e1112 * b->e12 + a->e22 * b->e1111 + a->e1111 * b->e22 
              + a->e111 * b->e122 + a->e112 * b->e112 + a->e122 * b->e111;
  res.e111222 = c->e111222 + a->r * b->e111222 + a->e111222 * b->r + a->e1 * b->e11222 
              + a->e11222 * b->e1 + a->e2 * b->e11122 + a->e11122 * b->e2 
              + a->e11 * b->e1222 + a->e1222 * b->e11 + a->e12 * b->e1122 
              + a->e1122 * b->e12 + a->e22 * b->e1112 + a->e1112 * b->e22 
              + a->e111 * b->e222 + a->e112 * b->e122 + a->e122 * b->e112 
              + a->e222 * b->e111;
  res.e112222 = c->e112222 + a->r * b->e112222 + a->e112222 * b->r + a->e1 * b->e12222 
              + a->e12222 * b->e1 + a->e2 * b->e11222 + a->e11222 * b->e2 
              + a->e11 * b->e2222 + a->e2222 * b->e11 + a->e12 * b->e1222 
              + a->e1222 * b->e12 + a->e22 * b->e1122 + a->e1122 * b->e22 
              + a->e112 * b->e222 + a->e122 * b->e122 + a->e222 * b->e112;
  res.e122222 = c->e122222 + a->r * b->e122222 + a->e122222 * b->r + a->e1 * b->e22222 
              + a->e22222 * b->e1 + a->e2 * b->e12222 + a->e12222 * b->e2 
              + a->e12 * b->e2222 + a->e2222 * b->e12 + a->e22 * b->e1222 
              + a->e1222 * b->e22 + a->e122 * b->e222 + a->e222 * b->e122;
  res.e222222 = c->e222222 + a->r * b->e222222 + a->e222222 * b->r + a->e2 * b->e22222 
              + a->e22222 * b->e2 + a->e22 * b->e2222 + a->e2222 * b->e22 
              + a->e222 * b->e222;
  // Order 7;
  res.e1111111 = c->e1111111 + a->r * b->e1111111 + a->e1111111 * b->r + a->e1 * b->e111111 
               + a->e111111 * b->e1 + a->e11 * b->e11111 + a->e11111 * b->e11 
               + a->e111 * b->e1111 + a->e1111 * b->e111;
  res.e1111112 = c->e1111112 + a->r * b->e1111112 + a->e1111112 * b->r + a->e1 * b->e111112 
               + a->e111112 * b->e1 + a->e2 * b->e111111 + a->e111111 * b->e2 
               + a->e11 * b->e11112 + a->e11112 * b->e11 + a->e12 * b->e11111 
               + a->e11111 * b->e12 + a->e111 * b->e1112 + a->e1112 * b->e111 
               + a->e112 * b->e1111 + a->e1111 * b->e112;
  res.e1111122 = c->e1111122 + a->r * b->e1111122 + a->e1111122 * b->r + a->e1 * b->e111122 
               + a->e111122 * b->e1 + a->e2 * b->e111112 + a->e111112 * b->e2 
               + a->e11 * b->e11122 + a->e11122 * b->e11 + a->e12 * b->e11112 
               + a->e11112 * b->e12 + a->e22 * b->e11111 + a->e11111 * b->e22 
               + a->e111 * b->e1122 + a->e1122 * b->e111 + a->e112 * b->e1112 
               + a->e1112 * b->e112 + a->e122 * b->e1111 + a->e1111 * b->e122;
  res.e1111222 = c->e1111222 + a->r * b->e1111222 + a->e1111222 * b->r + a->e1 * b->e111222 
               + a->e111222 * b->e1 + a->e2 * b->e111122 + a->e111122 * b->e2 
               + a->e11 * b->e11222 + a->e11222 * b->e11 + a->e12 * b->e11122 
               + a->e11122 * b->e12 + a->e22 * b->e11112 + a->e11112 * b->e22 
               + a->e111 * b->e1222 + a->e1222 * b->e111 + a->e112 * b->e1122 
               + a->e1122 * b->e112 + a->e122 * b->e1112 + a->e1112 * b->e122 
               + a->e222 * b->e1111 + a->e1111 * b->e222;
  res.e1112222 = c->e1112222 + a->r * b->e1112222 + a->e1112222 * b->r + a->e1 * b->e112222 
               + a->e112222 * b->e1 + a->e2 * b->e111222 + a->e111222 * b->e2 
               + a->e11 * b->e12222 + a->e12222 * b->e11 + a->e12 * b->e11222 
               + a->e11222 * b->e12 + a->e22 * b->e11122 + a->e11122 * b->e22 
               + a->e111 * b->e2222 + a->e2222 * b->e111 + a->e112 * b->e1222 
               + a->e1222 * b->e112 + a->e122 * b->e1122 + a->e1122 * b->e122 
               + a->e222 * b->e1112 + a->e1112 * b->e222;
  res.e1122222 = c->e1122222 + a->r * b->e1122222 + a->e1122222 * b->r + a->e1 * b->e122222 
               + a->e122222 * b->e1 + a->e2 * b->e112222 + a->e112222 * b->e2 
               + a->e11 * b->e22222 + a->e22222 * b->e11 + a->e12 * b->e12222 
               + a->e12222 * b->e12 + a->e22 * b->e11222 + a->e11222 * b->e22 
               + a->e112 * b->e2222 + a->e2222 * b->e112 + a->e122 * b->e1222 
               + a->e1222 * b->e122 + a->e222 * b->e1122 + a->e1122 * b->e222;
  res.e1222222 = c->e1222222 + a->r * b->e1222222 + a->e1222222 * b->r + a->e1 * b->e222222 
               + a->e222222 * b->e1 + a->e2 * b->e122222 + a->e122222 * b->e2 
               + a->e12 * b->e22222 + a->e22222 * b->e12 + a->e22 * b->e12222 
               + a->e12222 * b->e22 + a->e122 * b->e2222 + a->e2222 * b->e122 
               + a->e222 * b->e1222 + a->e1222 * b->e222;
  res.e2222222 = c->e2222222 + a->r * b->e2222222 + a->e2222222 * b->r + a->e2 * b->e222222 
               + a->e222222 * b->e2 + a->e22 * b->e22222 + a->e22222 * b->e22 
               + a->e222 * b->e2222 + a->e2222 * b->e222;

  return res;

}

void onumm2n7_gem_oo_to(  onumm2n7_t* a,  onumm2n7_t* b,  onumm2n7_t* c, onumm2n7_t* res){
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
  // Order 3;
  res->e111 = c->e111 + a->r * b->e111 + a->e111 * b->r + a->e1 * b->e11 
           + a->e11 * b->e1;
  res->e112 = c->e112 + a->r * b->e112 + a->e112 * b->r + a->e1 * b->e12 
           + a->e12 * b->e1 + a->e2 * b->e11 + a->e11 * b->e2;
  res->e122 = c->e122 + a->r * b->e122 + a->e122 * b->r + a->e1 * b->e22 
           + a->e22 * b->e1 + a->e2 * b->e12 + a->e12 * b->e2;
  res->e222 = c->e222 + a->r * b->e222 + a->e222 * b->r + a->e2 * b->e22 
           + a->e22 * b->e2;
  // Order 4;
  res->e1111 = c->e1111 + a->r * b->e1111 + a->e1111 * b->r + a->e1 * b->e111 
            + a->e111 * b->e1 + a->e11 * b->e11;
  res->e1112 = c->e1112 + a->r * b->e1112 + a->e1112 * b->r + a->e1 * b->e112 
            + a->e112 * b->e1 + a->e2 * b->e111 + a->e111 * b->e2 
            + a->e11 * b->e12 + a->e12 * b->e11;
  res->e1122 = c->e1122 + a->r * b->e1122 + a->e1122 * b->r + a->e1 * b->e122 
            + a->e122 * b->e1 + a->e2 * b->e112 + a->e112 * b->e2 
            + a->e11 * b->e22 + a->e12 * b->e12 + a->e22 * b->e11;
  res->e1222 = c->e1222 + a->r * b->e1222 + a->e1222 * b->r + a->e1 * b->e222 
            + a->e222 * b->e1 + a->e2 * b->e122 + a->e122 * b->e2 
            + a->e12 * b->e22 + a->e22 * b->e12;
  res->e2222 = c->e2222 + a->r * b->e2222 + a->e2222 * b->r + a->e2 * b->e222 
            + a->e222 * b->e2 + a->e22 * b->e22;
  // Order 5;
  res->e11111 = c->e11111 + a->r * b->e11111 + a->e11111 * b->r + a->e1 * b->e1111 
             + a->e1111 * b->e1 + a->e11 * b->e111 + a->e111 * b->e11;
  res->e11112 = c->e11112 + a->r * b->e11112 + a->e11112 * b->r + a->e1 * b->e1112 
             + a->e1112 * b->e1 + a->e2 * b->e1111 + a->e1111 * b->e2 
             + a->e11 * b->e112 + a->e112 * b->e11 + a->e12 * b->e111 
             + a->e111 * b->e12;
  res->e11122 = c->e11122 + a->r * b->e11122 + a->e11122 * b->r + a->e1 * b->e1122 
             + a->e1122 * b->e1 + a->e2 * b->e1112 + a->e1112 * b->e2 
             + a->e11 * b->e122 + a->e122 * b->e11 + a->e12 * b->e112 
             + a->e112 * b->e12 + a->e22 * b->e111 + a->e111 * b->e22;
  res->e11222 = c->e11222 + a->r * b->e11222 + a->e11222 * b->r + a->e1 * b->e1222 
             + a->e1222 * b->e1 + a->e2 * b->e1122 + a->e1122 * b->e2 
             + a->e11 * b->e222 + a->e222 * b->e11 + a->e12 * b->e122 
             + a->e122 * b->e12 + a->e22 * b->e112 + a->e112 * b->e22;
  res->e12222 = c->e12222 + a->r * b->e12222 + a->e12222 * b->r + a->e1 * b->e2222 
             + a->e2222 * b->e1 + a->e2 * b->e1222 + a->e1222 * b->e2 
             + a->e12 * b->e222 + a->e222 * b->e12 + a->e22 * b->e122 
             + a->e122 * b->e22;
  res->e22222 = c->e22222 + a->r * b->e22222 + a->e22222 * b->r + a->e2 * b->e2222 
             + a->e2222 * b->e2 + a->e22 * b->e222 + a->e222 * b->e22;
  // Order 6;
  res->e111111 = c->e111111 + a->r * b->e111111 + a->e111111 * b->r + a->e1 * b->e11111 
              + a->e11111 * b->e1 + a->e11 * b->e1111 + a->e1111 * b->e11 
              + a->e111 * b->e111;
  res->e111112 = c->e111112 + a->r * b->e111112 + a->e111112 * b->r + a->e1 * b->e11112 
              + a->e11112 * b->e1 + a->e2 * b->e11111 + a->e11111 * b->e2 
              + a->e11 * b->e1112 + a->e1112 * b->e11 + a->e12 * b->e1111 
              + a->e1111 * b->e12 + a->e111 * b->e112 + a->e112 * b->e111;
  res->e111122 = c->e111122 + a->r * b->e111122 + a->e111122 * b->r + a->e1 * b->e11122 
              + a->e11122 * b->e1 + a->e2 * b->e11112 + a->e11112 * b->e2 
              + a->e11 * b->e1122 + a->e1122 * b->e11 + a->e12 * b->e1112 
              + a->e1112 * b->e12 + a->e22 * b->e1111 + a->e1111 * b->e22 
              + a->e111 * b->e122 + a->e112 * b->e112 + a->e122 * b->e111;
  res->e111222 = c->e111222 + a->r * b->e111222 + a->e111222 * b->r + a->e1 * b->e11222 
              + a->e11222 * b->e1 + a->e2 * b->e11122 + a->e11122 * b->e2 
              + a->e11 * b->e1222 + a->e1222 * b->e11 + a->e12 * b->e1122 
              + a->e1122 * b->e12 + a->e22 * b->e1112 + a->e1112 * b->e22 
              + a->e111 * b->e222 + a->e112 * b->e122 + a->e122 * b->e112 
              + a->e222 * b->e111;
  res->e112222 = c->e112222 + a->r * b->e112222 + a->e112222 * b->r + a->e1 * b->e12222 
              + a->e12222 * b->e1 + a->e2 * b->e11222 + a->e11222 * b->e2 
              + a->e11 * b->e2222 + a->e2222 * b->e11 + a->e12 * b->e1222 
              + a->e1222 * b->e12 + a->e22 * b->e1122 + a->e1122 * b->e22 
              + a->e112 * b->e222 + a->e122 * b->e122 + a->e222 * b->e112;
  res->e122222 = c->e122222 + a->r * b->e122222 + a->e122222 * b->r + a->e1 * b->e22222 
              + a->e22222 * b->e1 + a->e2 * b->e12222 + a->e12222 * b->e2 
              + a->e12 * b->e2222 + a->e2222 * b->e12 + a->e22 * b->e1222 
              + a->e1222 * b->e22 + a->e122 * b->e222 + a->e222 * b->e122;
  res->e222222 = c->e222222 + a->r * b->e222222 + a->e222222 * b->r + a->e2 * b->e22222 
              + a->e22222 * b->e2 + a->e22 * b->e2222 + a->e2222 * b->e22 
              + a->e222 * b->e222;
  // Order 7;
  res->e1111111 = c->e1111111 + a->r * b->e1111111 + a->e1111111 * b->r + a->e1 * b->e111111 
               + a->e111111 * b->e1 + a->e11 * b->e11111 + a->e11111 * b->e11 
               + a->e111 * b->e1111 + a->e1111 * b->e111;
  res->e1111112 = c->e1111112 + a->r * b->e1111112 + a->e1111112 * b->r + a->e1 * b->e111112 
               + a->e111112 * b->e1 + a->e2 * b->e111111 + a->e111111 * b->e2 
               + a->e11 * b->e11112 + a->e11112 * b->e11 + a->e12 * b->e11111 
               + a->e11111 * b->e12 + a->e111 * b->e1112 + a->e1112 * b->e111 
               + a->e112 * b->e1111 + a->e1111 * b->e112;
  res->e1111122 = c->e1111122 + a->r * b->e1111122 + a->e1111122 * b->r + a->e1 * b->e111122 
               + a->e111122 * b->e1 + a->e2 * b->e111112 + a->e111112 * b->e2 
               + a->e11 * b->e11122 + a->e11122 * b->e11 + a->e12 * b->e11112 
               + a->e11112 * b->e12 + a->e22 * b->e11111 + a->e11111 * b->e22 
               + a->e111 * b->e1122 + a->e1122 * b->e111 + a->e112 * b->e1112 
               + a->e1112 * b->e112 + a->e122 * b->e1111 + a->e1111 * b->e122;
  res->e1111222 = c->e1111222 + a->r * b->e1111222 + a->e1111222 * b->r + a->e1 * b->e111222 
               + a->e111222 * b->e1 + a->e2 * b->e111122 + a->e111122 * b->e2 
               + a->e11 * b->e11222 + a->e11222 * b->e11 + a->e12 * b->e11122 
               + a->e11122 * b->e12 + a->e22 * b->e11112 + a->e11112 * b->e22 
               + a->e111 * b->e1222 + a->e1222 * b->e111 + a->e112 * b->e1122 
               + a->e1122 * b->e112 + a->e122 * b->e1112 + a->e1112 * b->e122 
               + a->e222 * b->e1111 + a->e1111 * b->e222;
  res->e1112222 = c->e1112222 + a->r * b->e1112222 + a->e1112222 * b->r + a->e1 * b->e112222 
               + a->e112222 * b->e1 + a->e2 * b->e111222 + a->e111222 * b->e2 
               + a->e11 * b->e12222 + a->e12222 * b->e11 + a->e12 * b->e11222 
               + a->e11222 * b->e12 + a->e22 * b->e11122 + a->e11122 * b->e22 
               + a->e111 * b->e2222 + a->e2222 * b->e111 + a->e112 * b->e1222 
               + a->e1222 * b->e112 + a->e122 * b->e1122 + a->e1122 * b->e122 
               + a->e222 * b->e1112 + a->e1112 * b->e222;
  res->e1122222 = c->e1122222 + a->r * b->e1122222 + a->e1122222 * b->r + a->e1 * b->e122222 
               + a->e122222 * b->e1 + a->e2 * b->e112222 + a->e112222 * b->e2 
               + a->e11 * b->e22222 + a->e22222 * b->e11 + a->e12 * b->e12222 
               + a->e12222 * b->e12 + a->e22 * b->e11222 + a->e11222 * b->e22 
               + a->e112 * b->e2222 + a->e2222 * b->e112 + a->e122 * b->e1222 
               + a->e1222 * b->e122 + a->e222 * b->e1122 + a->e1122 * b->e222;
  res->e1222222 = c->e1222222 + a->r * b->e1222222 + a->e1222222 * b->r + a->e1 * b->e222222 
               + a->e222222 * b->e1 + a->e2 * b->e122222 + a->e122222 * b->e2 
               + a->e12 * b->e22222 + a->e22222 * b->e12 + a->e22 * b->e12222 
               + a->e12222 * b->e22 + a->e122 * b->e2222 + a->e2222 * b->e122 
               + a->e222 * b->e1222 + a->e1222 * b->e222;
  res->e2222222 = c->e2222222 + a->r * b->e2222222 + a->e2222222 * b->r + a->e2 * b->e222222 
               + a->e222222 * b->e2 + a->e22 * b->e22222 + a->e22222 * b->e22 
               + a->e222 * b->e2222 + a->e2222 * b->e222;

}

onumm2n7_t onumm2n7_gem_ro(  coeff_t a,  onumm2n7_t* b,  onumm2n7_t* c){
  onumm2n7_t res;

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
  // Order 3;
  res.e111 = c->e111 + a * b->e111;
  res.e112 = c->e112 + a * b->e112;
  res.e122 = c->e122 + a * b->e122;
  res.e222 = c->e222 + a * b->e222;
  // Order 4;
  res.e1111 = c->e1111 + a * b->e1111;
  res.e1112 = c->e1112 + a * b->e1112;
  res.e1122 = c->e1122 + a * b->e1122;
  res.e1222 = c->e1222 + a * b->e1222;
  res.e2222 = c->e2222 + a * b->e2222;
  // Order 5;
  res.e11111 = c->e11111 + a * b->e11111;
  res.e11112 = c->e11112 + a * b->e11112;
  res.e11122 = c->e11122 + a * b->e11122;
  res.e11222 = c->e11222 + a * b->e11222;
  res.e12222 = c->e12222 + a * b->e12222;
  res.e22222 = c->e22222 + a * b->e22222;
  // Order 6;
  res.e111111 = c->e111111 + a * b->e111111;
  res.e111112 = c->e111112 + a * b->e111112;
  res.e111122 = c->e111122 + a * b->e111122;
  res.e111222 = c->e111222 + a * b->e111222;
  res.e112222 = c->e112222 + a * b->e112222;
  res.e122222 = c->e122222 + a * b->e122222;
  res.e222222 = c->e222222 + a * b->e222222;
  // Order 7;
  res.e1111111 = c->e1111111 + a * b->e1111111;
  res.e1111112 = c->e1111112 + a * b->e1111112;
  res.e1111122 = c->e1111122 + a * b->e1111122;
  res.e1111222 = c->e1111222 + a * b->e1111222;
  res.e1112222 = c->e1112222 + a * b->e1112222;
  res.e1122222 = c->e1122222 + a * b->e1122222;
  res.e1222222 = c->e1222222 + a * b->e1222222;
  res.e2222222 = c->e2222222 + a * b->e2222222;

  return res;

}

void onumm2n7_gem_ro_to(  coeff_t a,  onumm2n7_t* b,  onumm2n7_t* c, onumm2n7_t* res){
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
  // Order 3;
  res->e111 = c->e111 + a * b->e111;
  res->e112 = c->e112 + a * b->e112;
  res->e122 = c->e122 + a * b->e122;
  res->e222 = c->e222 + a * b->e222;
  // Order 4;
  res->e1111 = c->e1111 + a * b->e1111;
  res->e1112 = c->e1112 + a * b->e1112;
  res->e1122 = c->e1122 + a * b->e1122;
  res->e1222 = c->e1222 + a * b->e1222;
  res->e2222 = c->e2222 + a * b->e2222;
  // Order 5;
  res->e11111 = c->e11111 + a * b->e11111;
  res->e11112 = c->e11112 + a * b->e11112;
  res->e11122 = c->e11122 + a * b->e11122;
  res->e11222 = c->e11222 + a * b->e11222;
  res->e12222 = c->e12222 + a * b->e12222;
  res->e22222 = c->e22222 + a * b->e22222;
  // Order 6;
  res->e111111 = c->e111111 + a * b->e111111;
  res->e111112 = c->e111112 + a * b->e111112;
  res->e111122 = c->e111122 + a * b->e111122;
  res->e111222 = c->e111222 + a * b->e111222;
  res->e112222 = c->e112222 + a * b->e112222;
  res->e122222 = c->e122222 + a * b->e122222;
  res->e222222 = c->e222222 + a * b->e222222;
  // Order 7;
  res->e1111111 = c->e1111111 + a * b->e1111111;
  res->e1111112 = c->e1111112 + a * b->e1111112;
  res->e1111122 = c->e1111122 + a * b->e1111122;
  res->e1111222 = c->e1111222 + a * b->e1111222;
  res->e1112222 = c->e1112222 + a * b->e1112222;
  res->e1122222 = c->e1122222 + a * b->e1122222;
  res->e1222222 = c->e1222222 + a * b->e1222222;
  res->e2222222 = c->e2222222 + a * b->e2222222;

}

void onumm2n7_trunc_gem_oo_to( ord_t ord_lhs,  onumm2n7_t* a,  ord_t ord_rhs,  onumm2n7_t* b,  onumm2n7_t* c, onumm2n7_t* res){
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
          break;
        case 2:
          // res order: 2
          res->e11 = c->e11 + a->r * b->e11;
          res->e12 = c->e12 + a->r * b->e12;
          res->e22 = c->e22 + a->r * b->e22;
          break;
        case 3:
          // res order: 3
          res->e111 = c->e111 + a->r * b->e111;
          res->e112 = c->e112 + a->r * b->e112;
          res->e122 = c->e122 + a->r * b->e122;
          res->e222 = c->e222 + a->r * b->e222;
          break;
        case 4:
          // res order: 4
          res->e1111 = c->e1111 + a->r * b->e1111;
          res->e1112 = c->e1112 + a->r * b->e1112;
          res->e1122 = c->e1122 + a->r * b->e1122;
          res->e1222 = c->e1222 + a->r * b->e1222;
          res->e2222 = c->e2222 + a->r * b->e2222;
          break;
        case 5:
          // res order: 5
          res->e11111 = c->e11111 + a->r * b->e11111;
          res->e11112 = c->e11112 + a->r * b->e11112;
          res->e11122 = c->e11122 + a->r * b->e11122;
          res->e11222 = c->e11222 + a->r * b->e11222;
          res->e12222 = c->e12222 + a->r * b->e12222;
          res->e22222 = c->e22222 + a->r * b->e22222;
          break;
        case 6:
          // res order: 6
          res->e111111 = c->e111111 + a->r * b->e111111;
          res->e111112 = c->e111112 + a->r * b->e111112;
          res->e111122 = c->e111122 + a->r * b->e111122;
          res->e111222 = c->e111222 + a->r * b->e111222;
          res->e112222 = c->e112222 + a->r * b->e112222;
          res->e122222 = c->e122222 + a->r * b->e122222;
          res->e222222 = c->e222222 + a->r * b->e222222;
          break;
        case 7:
          // res order: 7
          res->e1111111 = c->e1111111 + a->r * b->e1111111;
          res->e1111112 = c->e1111112 + a->r * b->e1111112;
          res->e1111122 = c->e1111122 + a->r * b->e1111122;
          res->e1111222 = c->e1111222 + a->r * b->e1111222;
          res->e1112222 = c->e1112222 + a->r * b->e1112222;
          res->e1122222 = c->e1122222 + a->r * b->e1122222;
          res->e1222222 = c->e1222222 + a->r * b->e1222222;
          res->e2222222 = c->e2222222 + a->r * b->e2222222;
          break;
      }
      break;
    case 1:
      switch( ord_rhs ){
        case 0:
          // res order: 1
          res->e1 = c->e1 + a->e1 * b->r;
          res->e2 = c->e2 + a->e2 * b->r;
          break;
        case 1:
          // res order: 2
          res->e11 = c->e11 + a->e1 * b->e1;
          res->e12 = c->e12 + a->e1 * b->e2 + a->e2 * b->e1;
          res->e22 = c->e22 + a->e2 * b->e2;
          break;
        case 2:
          // res order: 3
          res->e111 = c->e111 + a->e1 * b->e11;
          res->e112 = c->e112 + a->e1 * b->e12 + a->e2 * b->e11;
          res->e122 = c->e122 + a->e1 * b->e22 + a->e2 * b->e12;
          res->e222 = c->e222 + a->e2 * b->e22;
          break;
        case 3:
          // res order: 4
          res->e1111 = c->e1111 + a->e1 * b->e111;
          res->e1112 = c->e1112 + a->e1 * b->e112 + a->e2 * b->e111;
          res->e1122 = c->e1122 + a->e1 * b->e122 + a->e2 * b->e112;
          res->e1222 = c->e1222 + a->e1 * b->e222 + a->e2 * b->e122;
          res->e2222 = c->e2222 + a->e2 * b->e222;
          break;
        case 4:
          // res order: 5
          res->e11111 = c->e11111 + a->e1 * b->e1111;
          res->e11112 = c->e11112 + a->e1 * b->e1112 + a->e2 * b->e1111;
          res->e11122 = c->e11122 + a->e1 * b->e1122 + a->e2 * b->e1112;
          res->e11222 = c->e11222 + a->e1 * b->e1222 + a->e2 * b->e1122;
          res->e12222 = c->e12222 + a->e1 * b->e2222 + a->e2 * b->e1222;
          res->e22222 = c->e22222 + a->e2 * b->e2222;
          break;
        case 5:
          // res order: 6
          res->e111111 = c->e111111 + a->e1 * b->e11111;
          res->e111112 = c->e111112 + a->e1 * b->e11112 + a->e2 * b->e11111;
          res->e111122 = c->e111122 + a->e1 * b->e11122 + a->e2 * b->e11112;
          res->e111222 = c->e111222 + a->e1 * b->e11222 + a->e2 * b->e11122;
          res->e112222 = c->e112222 + a->e1 * b->e12222 + a->e2 * b->e11222;
          res->e122222 = c->e122222 + a->e1 * b->e22222 + a->e2 * b->e12222;
          res->e222222 = c->e222222 + a->e2 * b->e22222;
          break;
        case 6:
          // res order: 7
          res->e1111111 = c->e1111111 + a->e1 * b->e111111;
          res->e1111112 = c->e1111112 + a->e1 * b->e111112 + a->e2 * b->e111111;
          res->e1111122 = c->e1111122 + a->e1 * b->e111122 + a->e2 * b->e111112;
          res->e1111222 = c->e1111222 + a->e1 * b->e111222 + a->e2 * b->e111122;
          res->e1112222 = c->e1112222 + a->e1 * b->e112222 + a->e2 * b->e111222;
          res->e1122222 = c->e1122222 + a->e1 * b->e122222 + a->e2 * b->e112222;
          res->e1222222 = c->e1222222 + a->e1 * b->e222222 + a->e2 * b->e122222;
          res->e2222222 = c->e2222222 + a->e2 * b->e222222;
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
          break;
        case 1:
          // res order: 3
          res->e111 = c->e111 + a->e11 * b->e1;
          res->e112 = c->e112 + a->e12 * b->e1 + a->e11 * b->e2;
          res->e122 = c->e122 + a->e22 * b->e1 + a->e12 * b->e2;
          res->e222 = c->e222 + a->e22 * b->e2;
          break;
        case 2:
          // res order: 4
          res->e1111 = c->e1111 + a->e11 * b->e11;
          res->e1112 = c->e1112 + a->e11 * b->e12 + a->e12 * b->e11;
          res->e1122 = c->e1122 + a->e11 * b->e22 + a->e12 * b->e12 
                     + a->e22 * b->e11;
          res->e1222 = c->e1222 + a->e12 * b->e22 + a->e22 * b->e12;
          res->e2222 = c->e2222 + a->e22 * b->e22;
          break;
        case 3:
          // res order: 5
          res->e11111 = c->e11111 + a->e11 * b->e111;
          res->e11112 = c->e11112 + a->e11 * b->e112 + a->e12 * b->e111;
          res->e11122 = c->e11122 + a->e11 * b->e122 + a->e12 * b->e112 
                      + a->e22 * b->e111;
          res->e11222 = c->e11222 + a->e11 * b->e222 + a->e12 * b->e122 
                      + a->e22 * b->e112;
          res->e12222 = c->e12222 + a->e12 * b->e222 + a->e22 * b->e122;
          res->e22222 = c->e22222 + a->e22 * b->e222;
          break;
        case 4:
          // res order: 6
          res->e111111 = c->e111111 + a->e11 * b->e1111;
          res->e111112 = c->e111112 + a->e11 * b->e1112 + a->e12 * b->e1111;
          res->e111122 = c->e111122 + a->e11 * b->e1122 + a->e12 * b->e1112 
                       + a->e22 * b->e1111;
          res->e111222 = c->e111222 + a->e11 * b->e1222 + a->e12 * b->e1122 
                       + a->e22 * b->e1112;
          res->e112222 = c->e112222 + a->e11 * b->e2222 + a->e12 * b->e1222 
                       + a->e22 * b->e1122;
          res->e122222 = c->e122222 + a->e12 * b->e2222 + a->e22 * b->e1222;
          res->e222222 = c->e222222 + a->e22 * b->e2222;
          break;
        case 5:
          // res order: 7
          res->e1111111 = c->e1111111 + a->e11 * b->e11111;
          res->e1111112 = c->e1111112 + a->e11 * b->e11112 + a->e12 * b->e11111;
          res->e1111122 = c->e1111122 + a->e11 * b->e11122 + a->e12 * b->e11112 
                        + a->e22 * b->e11111;
          res->e1111222 = c->e1111222 + a->e11 * b->e11222 + a->e12 * b->e11122 
                        + a->e22 * b->e11112;
          res->e1112222 = c->e1112222 + a->e11 * b->e12222 + a->e12 * b->e11222 
                        + a->e22 * b->e11122;
          res->e1122222 = c->e1122222 + a->e11 * b->e22222 + a->e12 * b->e12222 
                        + a->e22 * b->e11222;
          res->e1222222 = c->e1222222 + a->e12 * b->e22222 + a->e22 * b->e12222;
          res->e2222222 = c->e2222222 + a->e22 * b->e22222;
          break;
      }
      break;
    case 3:
      switch( ord_rhs ){
        case 0:
          // res order: 3
          res->e111 = c->e111 + a->e111 * b->r;
          res->e112 = c->e112 + a->e112 * b->r;
          res->e122 = c->e122 + a->e122 * b->r;
          res->e222 = c->e222 + a->e222 * b->r;
          break;
        case 1:
          // res order: 4
          res->e1111 = c->e1111 + a->e111 * b->e1;
          res->e1112 = c->e1112 + a->e112 * b->e1 + a->e111 * b->e2;
          res->e1122 = c->e1122 + a->e122 * b->e1 + a->e112 * b->e2;
          res->e1222 = c->e1222 + a->e222 * b->e1 + a->e122 * b->e2;
          res->e2222 = c->e2222 + a->e222 * b->e2;
          break;
        case 2:
          // res order: 5
          res->e11111 = c->e11111 + a->e111 * b->e11;
          res->e11112 = c->e11112 + a->e112 * b->e11 + a->e111 * b->e12;
          res->e11122 = c->e11122 + a->e122 * b->e11 + a->e112 * b->e12 
                      + a->e111 * b->e22;
          res->e11222 = c->e11222 + a->e222 * b->e11 + a->e122 * b->e12 
                      + a->e112 * b->e22;
          res->e12222 = c->e12222 + a->e222 * b->e12 + a->e122 * b->e22;
          res->e22222 = c->e22222 + a->e222 * b->e22;
          break;
        case 3:
          // res order: 6
          res->e111111 = c->e111111 + a->e111 * b->e111;
          res->e111112 = c->e111112 + a->e111 * b->e112 + a->e112 * b->e111;
          res->e111122 = c->e111122 + a->e111 * b->e122 + a->e112 * b->e112 
                       + a->e122 * b->e111;
          res->e111222 = c->e111222 + a->e111 * b->e222 + a->e112 * b->e122 
                       + a->e122 * b->e112 + a->e222 * b->e111;
          res->e112222 = c->e112222 + a->e112 * b->e222 + a->e122 * b->e122 
                       + a->e222 * b->e112;
          res->e122222 = c->e122222 + a->e122 * b->e222 + a->e222 * b->e122;
          res->e222222 = c->e222222 + a->e222 * b->e222;
          break;
        case 4:
          // res order: 7
          res->e1111111 = c->e1111111 + a->e111 * b->e1111;
          res->e1111112 = c->e1111112 + a->e111 * b->e1112 + a->e112 * b->e1111;
          res->e1111122 = c->e1111122 + a->e111 * b->e1122 + a->e112 * b->e1112 
                        + a->e122 * b->e1111;
          res->e1111222 = c->e1111222 + a->e111 * b->e1222 + a->e112 * b->e1122 
                        + a->e122 * b->e1112 + a->e222 * b->e1111;
          res->e1112222 = c->e1112222 + a->e111 * b->e2222 + a->e112 * b->e1222 
                        + a->e122 * b->e1122 + a->e222 * b->e1112;
          res->e1122222 = c->e1122222 + a->e112 * b->e2222 + a->e122 * b->e1222 
                        + a->e222 * b->e1122;
          res->e1222222 = c->e1222222 + a->e122 * b->e2222 + a->e222 * b->e1222;
          res->e2222222 = c->e2222222 + a->e222 * b->e2222;
          break;
      }
      break;
    case 4:
      switch( ord_rhs ){
        case 0:
          // res order: 4
          res->e1111 = c->e1111 + a->e1111 * b->r;
          res->e1112 = c->e1112 + a->e1112 * b->r;
          res->e1122 = c->e1122 + a->e1122 * b->r;
          res->e1222 = c->e1222 + a->e1222 * b->r;
          res->e2222 = c->e2222 + a->e2222 * b->r;
          break;
        case 1:
          // res order: 5
          res->e11111 = c->e11111 + a->e1111 * b->e1;
          res->e11112 = c->e11112 + a->e1112 * b->e1 + a->e1111 * b->e2;
          res->e11122 = c->e11122 + a->e1122 * b->e1 + a->e1112 * b->e2;
          res->e11222 = c->e11222 + a->e1222 * b->e1 + a->e1122 * b->e2;
          res->e12222 = c->e12222 + a->e2222 * b->e1 + a->e1222 * b->e2;
          res->e22222 = c->e22222 + a->e2222 * b->e2;
          break;
        case 2:
          // res order: 6
          res->e111111 = c->e111111 + a->e1111 * b->e11;
          res->e111112 = c->e111112 + a->e1112 * b->e11 + a->e1111 * b->e12;
          res->e111122 = c->e111122 + a->e1122 * b->e11 + a->e1112 * b->e12 
                       + a->e1111 * b->e22;
          res->e111222 = c->e111222 + a->e1222 * b->e11 + a->e1122 * b->e12 
                       + a->e1112 * b->e22;
          res->e112222 = c->e112222 + a->e2222 * b->e11 + a->e1222 * b->e12 
                       + a->e1122 * b->e22;
          res->e122222 = c->e122222 + a->e2222 * b->e12 + a->e1222 * b->e22;
          res->e222222 = c->e222222 + a->e2222 * b->e22;
          break;
        case 3:
          // res order: 7
          res->e1111111 = c->e1111111 + a->e1111 * b->e111;
          res->e1111112 = c->e1111112 + a->e1112 * b->e111 + a->e1111 * b->e112;
          res->e1111122 = c->e1111122 + a->e1122 * b->e111 + a->e1112 * b->e112 
                        + a->e1111 * b->e122;
          res->e1111222 = c->e1111222 + a->e1222 * b->e111 + a->e1122 * b->e112 
                        + a->e1112 * b->e122 + a->e1111 * b->e222;
          res->e1112222 = c->e1112222 + a->e2222 * b->e111 + a->e1222 * b->e112 
                        + a->e1122 * b->e122 + a->e1112 * b->e222;
          res->e1122222 = c->e1122222 + a->e2222 * b->e112 + a->e1222 * b->e122 
                        + a->e1122 * b->e222;
          res->e1222222 = c->e1222222 + a->e2222 * b->e122 + a->e1222 * b->e222;
          res->e2222222 = c->e2222222 + a->e2222 * b->e222;
          break;
      }
      break;
    case 5:
      switch( ord_rhs ){
        case 0:
          // res order: 5
          res->e11111 = c->e11111 + a->e11111 * b->r;
          res->e11112 = c->e11112 + a->e11112 * b->r;
          res->e11122 = c->e11122 + a->e11122 * b->r;
          res->e11222 = c->e11222 + a->e11222 * b->r;
          res->e12222 = c->e12222 + a->e12222 * b->r;
          res->e22222 = c->e22222 + a->e22222 * b->r;
          break;
        case 1:
          // res order: 6
          res->e111111 = c->e111111 + a->e11111 * b->e1;
          res->e111112 = c->e111112 + a->e11112 * b->e1 + a->e11111 * b->e2;
          res->e111122 = c->e111122 + a->e11122 * b->e1 + a->e11112 * b->e2;
          res->e111222 = c->e111222 + a->e11222 * b->e1 + a->e11122 * b->e2;
          res->e112222 = c->e112222 + a->e12222 * b->e1 + a->e11222 * b->e2;
          res->e122222 = c->e122222 + a->e22222 * b->e1 + a->e12222 * b->e2;
          res->e222222 = c->e222222 + a->e22222 * b->e2;
          break;
        case 2:
          // res order: 7
          res->e1111111 = c->e1111111 + a->e11111 * b->e11;
          res->e1111112 = c->e1111112 + a->e11112 * b->e11 + a->e11111 * b->e12;
          res->e1111122 = c->e1111122 + a->e11122 * b->e11 + a->e11112 * b->e12 
                        + a->e11111 * b->e22;
          res->e1111222 = c->e1111222 + a->e11222 * b->e11 + a->e11122 * b->e12 
                        + a->e11112 * b->e22;
          res->e1112222 = c->e1112222 + a->e12222 * b->e11 + a->e11222 * b->e12 
                        + a->e11122 * b->e22;
          res->e1122222 = c->e1122222 + a->e22222 * b->e11 + a->e12222 * b->e12 
                        + a->e11222 * b->e22;
          res->e1222222 = c->e1222222 + a->e22222 * b->e12 + a->e12222 * b->e22;
          res->e2222222 = c->e2222222 + a->e22222 * b->e22;
          break;
      }
      break;
    case 6:
      switch( ord_rhs ){
        case 0:
          // res order: 6
          res->e111111 = c->e111111 + a->e111111 * b->r;
          res->e111112 = c->e111112 + a->e111112 * b->r;
          res->e111122 = c->e111122 + a->e111122 * b->r;
          res->e111222 = c->e111222 + a->e111222 * b->r;
          res->e112222 = c->e112222 + a->e112222 * b->r;
          res->e122222 = c->e122222 + a->e122222 * b->r;
          res->e222222 = c->e222222 + a->e222222 * b->r;
          break;
        case 1:
          // res order: 7
          res->e1111111 = c->e1111111 + a->e111111 * b->e1;
          res->e1111112 = c->e1111112 + a->e111112 * b->e1 + a->e111111 * b->e2;
          res->e1111122 = c->e1111122 + a->e111122 * b->e1 + a->e111112 * b->e2;
          res->e1111222 = c->e1111222 + a->e111222 * b->e1 + a->e111122 * b->e2;
          res->e1112222 = c->e1112222 + a->e112222 * b->e1 + a->e111222 * b->e2;
          res->e1122222 = c->e1122222 + a->e122222 * b->e1 + a->e112222 * b->e2;
          res->e1222222 = c->e1222222 + a->e222222 * b->e1 + a->e122222 * b->e2;
          res->e2222222 = c->e2222222 + a->e222222 * b->e2;
          break;
      }
      break;
    case 7:
      switch( ord_rhs ){
        case 0:
          // res order: 7
          res->e1111111 = c->e1111111 + a->e1111111 * b->r;
          res->e1111112 = c->e1111112 + a->e1111112 * b->r;
          res->e1111122 = c->e1111122 + a->e1111122 * b->r;
          res->e1111222 = c->e1111222 + a->e1111222 * b->r;
          res->e1112222 = c->e1112222 + a->e1112222 * b->r;
          res->e1122222 = c->e1122222 + a->e1122222 * b->r;
          res->e1222222 = c->e1222222 + a->e1222222 * b->r;
          res->e2222222 = c->e2222222 + a->e2222222 * b->r;
          break;
      }
      break;
  }

}

onumm2n7_t onumm2n7_feval(coeff_t* feval_re, onumm2n7_t* x){

  onumm2n7_t res;

  // feval function
  //  Definitions
  coeff_t factor=1, coef = 0;
  onumm2n7_t deltax = (*x), deltax_power = (*x);
  deltax.r = 0.0;
  deltax_power.r = 0.0;
  onumm2n7_set_r(0.0, &res);
  //  Real
  res.r = feval_re[0];
  // Order 1
  factor *=1;
  coef    = feval_re[1]/ factor;;
  onumm2n7_gem_ro_to( coef, &deltax_power, &res, &res);
  deltax_power = onumm2n7_mul_oo(&deltax_power,&deltax);
  // Order 2
  factor *=2;
  coef    = feval_re[2]/ factor;;
  onumm2n7_gem_ro_to( coef, &deltax_power, &res, &res);
  deltax_power = onumm2n7_mul_oo(&deltax_power,&deltax);
  // Order 3
  factor *=3;
  coef    = feval_re[3]/ factor;;
  onumm2n7_gem_ro_to( coef, &deltax_power, &res, &res);
  deltax_power = onumm2n7_mul_oo(&deltax_power,&deltax);
  // Order 4
  factor *=4;
  coef    = feval_re[4]/ factor;;
  onumm2n7_gem_ro_to( coef, &deltax_power, &res, &res);
  deltax_power = onumm2n7_mul_oo(&deltax_power,&deltax);
  // Order 5
  factor *=5;
  coef    = feval_re[5]/ factor;;
  onumm2n7_gem_ro_to( coef, &deltax_power, &res, &res);
  deltax_power = onumm2n7_mul_oo(&deltax_power,&deltax);
  // Order 6
  factor *=6;
  coef    = feval_re[6]/ factor;;
  onumm2n7_gem_ro_to( coef, &deltax_power, &res, &res);
  deltax_power = onumm2n7_mul_oo(&deltax_power,&deltax);
  // Order 7
  factor *=7;
  coef    = feval_re[7]/ factor;;
  onumm2n7_gem_ro_to( coef, &deltax_power, &res, &res);

  return res;

}

void onumm2n7_feval_to(coeff_t* feval_re, onumm2n7_t* x, onumm2n7_t* res){

  // feval function
  //  Definitions
  coeff_t factor=1, coef = 0;
  onumm2n7_t deltax = (*x), deltax_power = (*x);
  deltax.r = 0.0;
  deltax_power.r = 0.0;
  onumm2n7_set_r(0.0, res);
  //  Real
  res->r = feval_re[0];
  // Order 1
  factor *=1;
  coef    = feval_re[1]/ factor;;
  onumm2n7_gem_ro_to( coef, &deltax_power, res, res);
  deltax_power = onumm2n7_mul_oo(&deltax_power,&deltax);
  // Order 2
  factor *=2;
  coef    = feval_re[2]/ factor;;
  onumm2n7_gem_ro_to( coef, &deltax_power, res, res);
  deltax_power = onumm2n7_mul_oo(&deltax_power,&deltax);
  // Order 3
  factor *=3;
  coef    = feval_re[3]/ factor;;
  onumm2n7_gem_ro_to( coef, &deltax_power, res, res);
  deltax_power = onumm2n7_mul_oo(&deltax_power,&deltax);
  // Order 4
  factor *=4;
  coef    = feval_re[4]/ factor;;
  onumm2n7_gem_ro_to( coef, &deltax_power, res, res);
  deltax_power = onumm2n7_mul_oo(&deltax_power,&deltax);
  // Order 5
  factor *=5;
  coef    = feval_re[5]/ factor;;
  onumm2n7_gem_ro_to( coef, &deltax_power, res, res);
  deltax_power = onumm2n7_mul_oo(&deltax_power,&deltax);
  // Order 6
  factor *=6;
  coef    = feval_re[6]/ factor;;
  onumm2n7_gem_ro_to( coef, &deltax_power, res, res);
  deltax_power = onumm2n7_mul_oo(&deltax_power,&deltax);
  // Order 7
  factor *=7;
  coef    = feval_re[7]/ factor;;
  onumm2n7_gem_ro_to( coef, &deltax_power, res, res);

}

