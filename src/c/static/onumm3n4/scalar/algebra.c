
// Division.

// ****************************************************************************************************
onumm3n4_t onumm3n4_div_ro(coeff_t num, onumm3n4_t* den){

    
    onumm3n4_t inv = onumm3n4_pow(den,-1);
    onumm3n4_t res = onumm3n4_mul_ro(num,&inv);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
onumm3n4_t onumm3n4_div_oo(onumm3n4_t* num, onumm3n4_t* den){

    
    onumm3n4_t inv = onumm3n4_init();
    onumm3n4_pow_to(den,-1,&inv);
    onumm3n4_t res = onumm3n4_mul_oo(num,&inv);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
onumm3n4_t onumm3n4_div_or(onumm3n4_t* num, coeff_t val){

    return onumm3n4_mul_ro(1.0/val,num);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
onumm3n4_t onumm3n4_abs(onumm3n4_t* num){

	onumm3n4_t res;
    onumm3n4_abs_to(num,&res);
    return res;

}
// ----------------------------------------------------------------------------------------------------

onumm3n4_t onumm3n4_neg(  onumm3n4_t* lhs){

  onumm3n4_t res;

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
  // Order 3;
  res.e111 = -lhs->e111;
  res.e112 = -lhs->e112;
  res.e122 = -lhs->e122;
  res.e222 = -lhs->e222;
  res.e113 = -lhs->e113;
  res.e123 = -lhs->e123;
  res.e223 = -lhs->e223;
  res.e133 = -lhs->e133;
  res.e233 = -lhs->e233;
  res.e333 = -lhs->e333;
  // Order 4;
  res.e1111 = -lhs->e1111;
  res.e1112 = -lhs->e1112;
  res.e1122 = -lhs->e1122;
  res.e1222 = -lhs->e1222;
  res.e2222 = -lhs->e2222;
  res.e1113 = -lhs->e1113;
  res.e1123 = -lhs->e1123;
  res.e1223 = -lhs->e1223;
  res.e2223 = -lhs->e2223;
  res.e1133 = -lhs->e1133;
  res.e1233 = -lhs->e1233;
  res.e2233 = -lhs->e2233;
  res.e1333 = -lhs->e1333;
  res.e2333 = -lhs->e2333;
  res.e3333 = -lhs->e3333;

  return res;

}

void onumm3n4_neg_to(  onumm3n4_t* lhs, onumm3n4_t* res){

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
  // Order 3;
  res->e111 = -lhs->e111;
  res->e112 = -lhs->e112;
  res->e122 = -lhs->e122;
  res->e222 = -lhs->e222;
  res->e113 = -lhs->e113;
  res->e123 = -lhs->e123;
  res->e223 = -lhs->e223;
  res->e133 = -lhs->e133;
  res->e233 = -lhs->e233;
  res->e333 = -lhs->e333;
  // Order 4;
  res->e1111 = -lhs->e1111;
  res->e1112 = -lhs->e1112;
  res->e1122 = -lhs->e1122;
  res->e1222 = -lhs->e1222;
  res->e2222 = -lhs->e2222;
  res->e1113 = -lhs->e1113;
  res->e1123 = -lhs->e1123;
  res->e1223 = -lhs->e1223;
  res->e2223 = -lhs->e2223;
  res->e1133 = -lhs->e1133;
  res->e1233 = -lhs->e1233;
  res->e2233 = -lhs->e2233;
  res->e1333 = -lhs->e1333;
  res->e2333 = -lhs->e2333;
  res->e3333 = -lhs->e3333;

}

onumm3n4_t onumm3n4_sum_oo(  onumm3n4_t* lhs,  onumm3n4_t* rhs){
  onumm3n4_t res;

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
  // Order 3
  res.e111 = lhs->e111 + rhs->e111;
  res.e112 = lhs->e112 + rhs->e112;
  res.e122 = lhs->e122 + rhs->e122;
  res.e222 = lhs->e222 + rhs->e222;
  res.e113 = lhs->e113 + rhs->e113;
  res.e123 = lhs->e123 + rhs->e123;
  res.e223 = lhs->e223 + rhs->e223;
  res.e133 = lhs->e133 + rhs->e133;
  res.e233 = lhs->e233 + rhs->e233;
  res.e333 = lhs->e333 + rhs->e333;
  // Order 4
  res.e1111 = lhs->e1111 + rhs->e1111;
  res.e1112 = lhs->e1112 + rhs->e1112;
  res.e1122 = lhs->e1122 + rhs->e1122;
  res.e1222 = lhs->e1222 + rhs->e1222;
  res.e2222 = lhs->e2222 + rhs->e2222;
  res.e1113 = lhs->e1113 + rhs->e1113;
  res.e1123 = lhs->e1123 + rhs->e1123;
  res.e1223 = lhs->e1223 + rhs->e1223;
  res.e2223 = lhs->e2223 + rhs->e2223;
  res.e1133 = lhs->e1133 + rhs->e1133;
  res.e1233 = lhs->e1233 + rhs->e1233;
  res.e2233 = lhs->e2233 + rhs->e2233;
  res.e1333 = lhs->e1333 + rhs->e1333;
  res.e2333 = lhs->e2333 + rhs->e2333;
  res.e3333 = lhs->e3333 + rhs->e3333;

  return res;

}

void onumm3n4_sum_oo_to(  onumm3n4_t* lhs,  onumm3n4_t* rhs, onumm3n4_t* res){
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
  // Order 3
  res->e111 = lhs->e111 + rhs->e111;
  res->e112 = lhs->e112 + rhs->e112;
  res->e122 = lhs->e122 + rhs->e122;
  res->e222 = lhs->e222 + rhs->e222;
  res->e113 = lhs->e113 + rhs->e113;
  res->e123 = lhs->e123 + rhs->e123;
  res->e223 = lhs->e223 + rhs->e223;
  res->e133 = lhs->e133 + rhs->e133;
  res->e233 = lhs->e233 + rhs->e233;
  res->e333 = lhs->e333 + rhs->e333;
  // Order 4
  res->e1111 = lhs->e1111 + rhs->e1111;
  res->e1112 = lhs->e1112 + rhs->e1112;
  res->e1122 = lhs->e1122 + rhs->e1122;
  res->e1222 = lhs->e1222 + rhs->e1222;
  res->e2222 = lhs->e2222 + rhs->e2222;
  res->e1113 = lhs->e1113 + rhs->e1113;
  res->e1123 = lhs->e1123 + rhs->e1123;
  res->e1223 = lhs->e1223 + rhs->e1223;
  res->e2223 = lhs->e2223 + rhs->e2223;
  res->e1133 = lhs->e1133 + rhs->e1133;
  res->e1233 = lhs->e1233 + rhs->e1233;
  res->e2233 = lhs->e2233 + rhs->e2233;
  res->e1333 = lhs->e1333 + rhs->e1333;
  res->e2333 = lhs->e2333 + rhs->e2333;
  res->e3333 = lhs->e3333 + rhs->e3333;

}

onumm3n4_t onumm3n4_sum_ro(  coeff_t lhs,  onumm3n4_t* rhs){
  onumm3n4_t res;

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
  // Order 3;
  res.e111 =  + rhs->e111;
  res.e112 =  + rhs->e112;
  res.e122 =  + rhs->e122;
  res.e222 =  + rhs->e222;
  res.e113 =  + rhs->e113;
  res.e123 =  + rhs->e123;
  res.e223 =  + rhs->e223;
  res.e133 =  + rhs->e133;
  res.e233 =  + rhs->e233;
  res.e333 =  + rhs->e333;
  // Order 4;
  res.e1111 =  + rhs->e1111;
  res.e1112 =  + rhs->e1112;
  res.e1122 =  + rhs->e1122;
  res.e1222 =  + rhs->e1222;
  res.e2222 =  + rhs->e2222;
  res.e1113 =  + rhs->e1113;
  res.e1123 =  + rhs->e1123;
  res.e1223 =  + rhs->e1223;
  res.e2223 =  + rhs->e2223;
  res.e1133 =  + rhs->e1133;
  res.e1233 =  + rhs->e1233;
  res.e2233 =  + rhs->e2233;
  res.e1333 =  + rhs->e1333;
  res.e2333 =  + rhs->e2333;
  res.e3333 =  + rhs->e3333;

  return res;

}

void onumm3n4_sum_ro_to(  coeff_t lhs,  onumm3n4_t* rhs, onumm3n4_t* res){
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
  // Order 3;
  res->e111 =  + rhs->e111;
  res->e112 =  + rhs->e112;
  res->e122 =  + rhs->e122;
  res->e222 =  + rhs->e222;
  res->e113 =  + rhs->e113;
  res->e123 =  + rhs->e123;
  res->e223 =  + rhs->e223;
  res->e133 =  + rhs->e133;
  res->e233 =  + rhs->e233;
  res->e333 =  + rhs->e333;
  // Order 4;
  res->e1111 =  + rhs->e1111;
  res->e1112 =  + rhs->e1112;
  res->e1122 =  + rhs->e1122;
  res->e1222 =  + rhs->e1222;
  res->e2222 =  + rhs->e2222;
  res->e1113 =  + rhs->e1113;
  res->e1123 =  + rhs->e1123;
  res->e1223 =  + rhs->e1223;
  res->e2223 =  + rhs->e2223;
  res->e1133 =  + rhs->e1133;
  res->e1233 =  + rhs->e1233;
  res->e2233 =  + rhs->e2233;
  res->e1333 =  + rhs->e1333;
  res->e2333 =  + rhs->e2333;
  res->e3333 =  + rhs->e3333;

}

onumm3n4_t onumm3n4_sub_oo(  onumm3n4_t* lhs,  onumm3n4_t* rhs){
  onumm3n4_t res;

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
  // Order 3
  res.e111 = lhs->e111 - rhs->e111;
  res.e112 = lhs->e112 - rhs->e112;
  res.e122 = lhs->e122 - rhs->e122;
  res.e222 = lhs->e222 - rhs->e222;
  res.e113 = lhs->e113 - rhs->e113;
  res.e123 = lhs->e123 - rhs->e123;
  res.e223 = lhs->e223 - rhs->e223;
  res.e133 = lhs->e133 - rhs->e133;
  res.e233 = lhs->e233 - rhs->e233;
  res.e333 = lhs->e333 - rhs->e333;
  // Order 4
  res.e1111 = lhs->e1111 - rhs->e1111;
  res.e1112 = lhs->e1112 - rhs->e1112;
  res.e1122 = lhs->e1122 - rhs->e1122;
  res.e1222 = lhs->e1222 - rhs->e1222;
  res.e2222 = lhs->e2222 - rhs->e2222;
  res.e1113 = lhs->e1113 - rhs->e1113;
  res.e1123 = lhs->e1123 - rhs->e1123;
  res.e1223 = lhs->e1223 - rhs->e1223;
  res.e2223 = lhs->e2223 - rhs->e2223;
  res.e1133 = lhs->e1133 - rhs->e1133;
  res.e1233 = lhs->e1233 - rhs->e1233;
  res.e2233 = lhs->e2233 - rhs->e2233;
  res.e1333 = lhs->e1333 - rhs->e1333;
  res.e2333 = lhs->e2333 - rhs->e2333;
  res.e3333 = lhs->e3333 - rhs->e3333;

  return res;

}

void onumm3n4_sub_oo_to(  onumm3n4_t* lhs,  onumm3n4_t* rhs, onumm3n4_t* res){
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
  // Order 3
  res->e111 = lhs->e111 - rhs->e111;
  res->e112 = lhs->e112 - rhs->e112;
  res->e122 = lhs->e122 - rhs->e122;
  res->e222 = lhs->e222 - rhs->e222;
  res->e113 = lhs->e113 - rhs->e113;
  res->e123 = lhs->e123 - rhs->e123;
  res->e223 = lhs->e223 - rhs->e223;
  res->e133 = lhs->e133 - rhs->e133;
  res->e233 = lhs->e233 - rhs->e233;
  res->e333 = lhs->e333 - rhs->e333;
  // Order 4
  res->e1111 = lhs->e1111 - rhs->e1111;
  res->e1112 = lhs->e1112 - rhs->e1112;
  res->e1122 = lhs->e1122 - rhs->e1122;
  res->e1222 = lhs->e1222 - rhs->e1222;
  res->e2222 = lhs->e2222 - rhs->e2222;
  res->e1113 = lhs->e1113 - rhs->e1113;
  res->e1123 = lhs->e1123 - rhs->e1123;
  res->e1223 = lhs->e1223 - rhs->e1223;
  res->e2223 = lhs->e2223 - rhs->e2223;
  res->e1133 = lhs->e1133 - rhs->e1133;
  res->e1233 = lhs->e1233 - rhs->e1233;
  res->e2233 = lhs->e2233 - rhs->e2233;
  res->e1333 = lhs->e1333 - rhs->e1333;
  res->e2333 = lhs->e2333 - rhs->e2333;
  res->e3333 = lhs->e3333 - rhs->e3333;

}

onumm3n4_t onumm3n4_sub_ro(  coeff_t lhs,  onumm3n4_t* rhs){
  onumm3n4_t res;

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
  // Order 3;
  res.e111 =  - rhs->e111;
  res.e112 =  - rhs->e112;
  res.e122 =  - rhs->e122;
  res.e222 =  - rhs->e222;
  res.e113 =  - rhs->e113;
  res.e123 =  - rhs->e123;
  res.e223 =  - rhs->e223;
  res.e133 =  - rhs->e133;
  res.e233 =  - rhs->e233;
  res.e333 =  - rhs->e333;
  // Order 4;
  res.e1111 =  - rhs->e1111;
  res.e1112 =  - rhs->e1112;
  res.e1122 =  - rhs->e1122;
  res.e1222 =  - rhs->e1222;
  res.e2222 =  - rhs->e2222;
  res.e1113 =  - rhs->e1113;
  res.e1123 =  - rhs->e1123;
  res.e1223 =  - rhs->e1223;
  res.e2223 =  - rhs->e2223;
  res.e1133 =  - rhs->e1133;
  res.e1233 =  - rhs->e1233;
  res.e2233 =  - rhs->e2233;
  res.e1333 =  - rhs->e1333;
  res.e2333 =  - rhs->e2333;
  res.e3333 =  - rhs->e3333;

  return res;

}

void onumm3n4_sub_ro_to(  coeff_t lhs,  onumm3n4_t* rhs, onumm3n4_t* res){
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
  // Order 3;
  res->e111 =  - rhs->e111;
  res->e112 =  - rhs->e112;
  res->e122 =  - rhs->e122;
  res->e222 =  - rhs->e222;
  res->e113 =  - rhs->e113;
  res->e123 =  - rhs->e123;
  res->e223 =  - rhs->e223;
  res->e133 =  - rhs->e133;
  res->e233 =  - rhs->e233;
  res->e333 =  - rhs->e333;
  // Order 4;
  res->e1111 =  - rhs->e1111;
  res->e1112 =  - rhs->e1112;
  res->e1122 =  - rhs->e1122;
  res->e1222 =  - rhs->e1222;
  res->e2222 =  - rhs->e2222;
  res->e1113 =  - rhs->e1113;
  res->e1123 =  - rhs->e1123;
  res->e1223 =  - rhs->e1223;
  res->e2223 =  - rhs->e2223;
  res->e1133 =  - rhs->e1133;
  res->e1233 =  - rhs->e1233;
  res->e2233 =  - rhs->e2233;
  res->e1333 =  - rhs->e1333;
  res->e2333 =  - rhs->e2333;
  res->e3333 =  - rhs->e3333;

}

onumm3n4_t onumm3n4_sub_or(  onumm3n4_t* lhs,  coeff_t rhs){
  onumm3n4_t res;

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
  // Order 3;
  res.e111 = lhs->e111;
  res.e112 = lhs->e112;
  res.e122 = lhs->e122;
  res.e222 = lhs->e222;
  res.e113 = lhs->e113;
  res.e123 = lhs->e123;
  res.e223 = lhs->e223;
  res.e133 = lhs->e133;
  res.e233 = lhs->e233;
  res.e333 = lhs->e333;
  // Order 4;
  res.e1111 = lhs->e1111;
  res.e1112 = lhs->e1112;
  res.e1122 = lhs->e1122;
  res.e1222 = lhs->e1222;
  res.e2222 = lhs->e2222;
  res.e1113 = lhs->e1113;
  res.e1123 = lhs->e1123;
  res.e1223 = lhs->e1223;
  res.e2223 = lhs->e2223;
  res.e1133 = lhs->e1133;
  res.e1233 = lhs->e1233;
  res.e2233 = lhs->e2233;
  res.e1333 = lhs->e1333;
  res.e2333 = lhs->e2333;
  res.e3333 = lhs->e3333;

  return res;

}

void onumm3n4_sub_or_to(  onumm3n4_t* lhs,  coeff_t rhs, onumm3n4_t* res){
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
  // Order 3;
  res->e111 = lhs->e111;
  res->e112 = lhs->e112;
  res->e122 = lhs->e122;
  res->e222 = lhs->e222;
  res->e113 = lhs->e113;
  res->e123 = lhs->e123;
  res->e223 = lhs->e223;
  res->e133 = lhs->e133;
  res->e233 = lhs->e233;
  res->e333 = lhs->e333;
  // Order 4;
  res->e1111 = lhs->e1111;
  res->e1112 = lhs->e1112;
  res->e1122 = lhs->e1122;
  res->e1222 = lhs->e1222;
  res->e2222 = lhs->e2222;
  res->e1113 = lhs->e1113;
  res->e1123 = lhs->e1123;
  res->e1223 = lhs->e1223;
  res->e2223 = lhs->e2223;
  res->e1133 = lhs->e1133;
  res->e1233 = lhs->e1233;
  res->e2233 = lhs->e2233;
  res->e1333 = lhs->e1333;
  res->e2333 = lhs->e2333;
  res->e3333 = lhs->e3333;

}

onumm3n4_t onumm3n4_mul_oo(  onumm3n4_t* lhs,  onumm3n4_t* rhs){
  onumm3n4_t res;

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
  // Order 3;
  res.e111 = lhs->r * rhs->e111 + lhs->e111 * rhs->r + lhs->e1 * rhs->e11 
           + lhs->e11 * rhs->e1;
  res.e112 = lhs->r * rhs->e112 + lhs->e112 * rhs->r + lhs->e1 * rhs->e12 
           + lhs->e12 * rhs->e1 + lhs->e2 * rhs->e11 + lhs->e11 * rhs->e2;
  res.e122 = lhs->r * rhs->e122 + lhs->e122 * rhs->r + lhs->e1 * rhs->e22 
           + lhs->e22 * rhs->e1 + lhs->e2 * rhs->e12 + lhs->e12 * rhs->e2;
  res.e222 = lhs->r * rhs->e222 + lhs->e222 * rhs->r + lhs->e2 * rhs->e22 
           + lhs->e22 * rhs->e2;
  res.e113 = lhs->r * rhs->e113 + lhs->e113 * rhs->r + lhs->e1 * rhs->e13 
           + lhs->e13 * rhs->e1 + lhs->e3 * rhs->e11 + lhs->e11 * rhs->e3;
  res.e123 = lhs->r * rhs->e123 + lhs->e123 * rhs->r + lhs->e1 * rhs->e23 
           + lhs->e23 * rhs->e1 + lhs->e2 * rhs->e13 + lhs->e13 * rhs->e2 
           + lhs->e3 * rhs->e12 + lhs->e12 * rhs->e3;
  res.e223 = lhs->r * rhs->e223 + lhs->e223 * rhs->r + lhs->e2 * rhs->e23 
           + lhs->e23 * rhs->e2 + lhs->e3 * rhs->e22 + lhs->e22 * rhs->e3;
  res.e133 = lhs->r * rhs->e133 + lhs->e133 * rhs->r + lhs->e1 * rhs->e33 
           + lhs->e33 * rhs->e1 + lhs->e3 * rhs->e13 + lhs->e13 * rhs->e3;
  res.e233 = lhs->r * rhs->e233 + lhs->e233 * rhs->r + lhs->e2 * rhs->e33 
           + lhs->e33 * rhs->e2 + lhs->e3 * rhs->e23 + lhs->e23 * rhs->e3;
  res.e333 = lhs->r * rhs->e333 + lhs->e333 * rhs->r + lhs->e3 * rhs->e33 
           + lhs->e33 * rhs->e3;
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
  res.e1113 = lhs->r * rhs->e1113 + lhs->e1113 * rhs->r + lhs->e1 * rhs->e113 
            + lhs->e113 * rhs->e1 + lhs->e3 * rhs->e111 + lhs->e111 * rhs->e3 
            + lhs->e11 * rhs->e13 + lhs->e13 * rhs->e11;
  res.e1123 = lhs->r * rhs->e1123 + lhs->e1123 * rhs->r + lhs->e1 * rhs->e123 
            + lhs->e123 * rhs->e1 + lhs->e2 * rhs->e113 + lhs->e113 * rhs->e2 
            + lhs->e3 * rhs->e112 + lhs->e112 * rhs->e3 + lhs->e11 * rhs->e23 
            + lhs->e12 * rhs->e13 + lhs->e13 * rhs->e12 + lhs->e23 * rhs->e11;
  res.e1223 = lhs->r * rhs->e1223 + lhs->e1223 * rhs->r + lhs->e1 * rhs->e223 
            + lhs->e223 * rhs->e1 + lhs->e2 * rhs->e123 + lhs->e123 * rhs->e2 
            + lhs->e3 * rhs->e122 + lhs->e122 * rhs->e3 + lhs->e12 * rhs->e23 
            + lhs->e22 * rhs->e13 + lhs->e13 * rhs->e22 + lhs->e23 * rhs->e12;
  res.e2223 = lhs->r * rhs->e2223 + lhs->e2223 * rhs->r + lhs->e2 * rhs->e223 
            + lhs->e223 * rhs->e2 + lhs->e3 * rhs->e222 + lhs->e222 * rhs->e3 
            + lhs->e22 * rhs->e23 + lhs->e23 * rhs->e22;
  res.e1133 = lhs->r * rhs->e1133 + lhs->e1133 * rhs->r + lhs->e1 * rhs->e133 
            + lhs->e133 * rhs->e1 + lhs->e3 * rhs->e113 + lhs->e113 * rhs->e3 
            + lhs->e11 * rhs->e33 + lhs->e13 * rhs->e13 + lhs->e33 * rhs->e11;
  res.e1233 = lhs->r * rhs->e1233 + lhs->e1233 * rhs->r + lhs->e1 * rhs->e233 
            + lhs->e233 * rhs->e1 + lhs->e2 * rhs->e133 + lhs->e133 * rhs->e2 
            + lhs->e3 * rhs->e123 + lhs->e123 * rhs->e3 + lhs->e12 * rhs->e33 
            + lhs->e13 * rhs->e23 + lhs->e23 * rhs->e13 + lhs->e33 * rhs->e12;
  res.e2233 = lhs->r * rhs->e2233 + lhs->e2233 * rhs->r + lhs->e2 * rhs->e233 
            + lhs->e233 * rhs->e2 + lhs->e3 * rhs->e223 + lhs->e223 * rhs->e3 
            + lhs->e22 * rhs->e33 + lhs->e23 * rhs->e23 + lhs->e33 * rhs->e22;
  res.e1333 = lhs->r * rhs->e1333 + lhs->e1333 * rhs->r + lhs->e1 * rhs->e333 
            + lhs->e333 * rhs->e1 + lhs->e3 * rhs->e133 + lhs->e133 * rhs->e3 
            + lhs->e13 * rhs->e33 + lhs->e33 * rhs->e13;
  res.e2333 = lhs->r * rhs->e2333 + lhs->e2333 * rhs->r + lhs->e2 * rhs->e333 
            + lhs->e333 * rhs->e2 + lhs->e3 * rhs->e233 + lhs->e233 * rhs->e3 
            + lhs->e23 * rhs->e33 + lhs->e33 * rhs->e23;
  res.e3333 = lhs->r * rhs->e3333 + lhs->e3333 * rhs->r + lhs->e3 * rhs->e333 
            + lhs->e333 * rhs->e3 + lhs->e33 * rhs->e33;

  return res;

}

void onumm3n4_mul_oo_to(  onumm3n4_t* lhs,  onumm3n4_t* rhs, onumm3n4_t* res){
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
  // Order 3;
  res->e111 = lhs->r * rhs->e111 + lhs->e111 * rhs->r + lhs->e1 * rhs->e11 
           + lhs->e11 * rhs->e1;
  res->e112 = lhs->r * rhs->e112 + lhs->e112 * rhs->r + lhs->e1 * rhs->e12 
           + lhs->e12 * rhs->e1 + lhs->e2 * rhs->e11 + lhs->e11 * rhs->e2;
  res->e122 = lhs->r * rhs->e122 + lhs->e122 * rhs->r + lhs->e1 * rhs->e22 
           + lhs->e22 * rhs->e1 + lhs->e2 * rhs->e12 + lhs->e12 * rhs->e2;
  res->e222 = lhs->r * rhs->e222 + lhs->e222 * rhs->r + lhs->e2 * rhs->e22 
           + lhs->e22 * rhs->e2;
  res->e113 = lhs->r * rhs->e113 + lhs->e113 * rhs->r + lhs->e1 * rhs->e13 
           + lhs->e13 * rhs->e1 + lhs->e3 * rhs->e11 + lhs->e11 * rhs->e3;
  res->e123 = lhs->r * rhs->e123 + lhs->e123 * rhs->r + lhs->e1 * rhs->e23 
           + lhs->e23 * rhs->e1 + lhs->e2 * rhs->e13 + lhs->e13 * rhs->e2 
           + lhs->e3 * rhs->e12 + lhs->e12 * rhs->e3;
  res->e223 = lhs->r * rhs->e223 + lhs->e223 * rhs->r + lhs->e2 * rhs->e23 
           + lhs->e23 * rhs->e2 + lhs->e3 * rhs->e22 + lhs->e22 * rhs->e3;
  res->e133 = lhs->r * rhs->e133 + lhs->e133 * rhs->r + lhs->e1 * rhs->e33 
           + lhs->e33 * rhs->e1 + lhs->e3 * rhs->e13 + lhs->e13 * rhs->e3;
  res->e233 = lhs->r * rhs->e233 + lhs->e233 * rhs->r + lhs->e2 * rhs->e33 
           + lhs->e33 * rhs->e2 + lhs->e3 * rhs->e23 + lhs->e23 * rhs->e3;
  res->e333 = lhs->r * rhs->e333 + lhs->e333 * rhs->r + lhs->e3 * rhs->e33 
           + lhs->e33 * rhs->e3;
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
  res->e1113 = lhs->r * rhs->e1113 + lhs->e1113 * rhs->r + lhs->e1 * rhs->e113 
            + lhs->e113 * rhs->e1 + lhs->e3 * rhs->e111 + lhs->e111 * rhs->e3 
            + lhs->e11 * rhs->e13 + lhs->e13 * rhs->e11;
  res->e1123 = lhs->r * rhs->e1123 + lhs->e1123 * rhs->r + lhs->e1 * rhs->e123 
            + lhs->e123 * rhs->e1 + lhs->e2 * rhs->e113 + lhs->e113 * rhs->e2 
            + lhs->e3 * rhs->e112 + lhs->e112 * rhs->e3 + lhs->e11 * rhs->e23 
            + lhs->e12 * rhs->e13 + lhs->e13 * rhs->e12 + lhs->e23 * rhs->e11;
  res->e1223 = lhs->r * rhs->e1223 + lhs->e1223 * rhs->r + lhs->e1 * rhs->e223 
            + lhs->e223 * rhs->e1 + lhs->e2 * rhs->e123 + lhs->e123 * rhs->e2 
            + lhs->e3 * rhs->e122 + lhs->e122 * rhs->e3 + lhs->e12 * rhs->e23 
            + lhs->e22 * rhs->e13 + lhs->e13 * rhs->e22 + lhs->e23 * rhs->e12;
  res->e2223 = lhs->r * rhs->e2223 + lhs->e2223 * rhs->r + lhs->e2 * rhs->e223 
            + lhs->e223 * rhs->e2 + lhs->e3 * rhs->e222 + lhs->e222 * rhs->e3 
            + lhs->e22 * rhs->e23 + lhs->e23 * rhs->e22;
  res->e1133 = lhs->r * rhs->e1133 + lhs->e1133 * rhs->r + lhs->e1 * rhs->e133 
            + lhs->e133 * rhs->e1 + lhs->e3 * rhs->e113 + lhs->e113 * rhs->e3 
            + lhs->e11 * rhs->e33 + lhs->e13 * rhs->e13 + lhs->e33 * rhs->e11;
  res->e1233 = lhs->r * rhs->e1233 + lhs->e1233 * rhs->r + lhs->e1 * rhs->e233 
            + lhs->e233 * rhs->e1 + lhs->e2 * rhs->e133 + lhs->e133 * rhs->e2 
            + lhs->e3 * rhs->e123 + lhs->e123 * rhs->e3 + lhs->e12 * rhs->e33 
            + lhs->e13 * rhs->e23 + lhs->e23 * rhs->e13 + lhs->e33 * rhs->e12;
  res->e2233 = lhs->r * rhs->e2233 + lhs->e2233 * rhs->r + lhs->e2 * rhs->e233 
            + lhs->e233 * rhs->e2 + lhs->e3 * rhs->e223 + lhs->e223 * rhs->e3 
            + lhs->e22 * rhs->e33 + lhs->e23 * rhs->e23 + lhs->e33 * rhs->e22;
  res->e1333 = lhs->r * rhs->e1333 + lhs->e1333 * rhs->r + lhs->e1 * rhs->e333 
            + lhs->e333 * rhs->e1 + lhs->e3 * rhs->e133 + lhs->e133 * rhs->e3 
            + lhs->e13 * rhs->e33 + lhs->e33 * rhs->e13;
  res->e2333 = lhs->r * rhs->e2333 + lhs->e2333 * rhs->r + lhs->e2 * rhs->e333 
            + lhs->e333 * rhs->e2 + lhs->e3 * rhs->e233 + lhs->e233 * rhs->e3 
            + lhs->e23 * rhs->e33 + lhs->e33 * rhs->e23;
  res->e3333 = lhs->r * rhs->e3333 + lhs->e3333 * rhs->r + lhs->e3 * rhs->e333 
            + lhs->e333 * rhs->e3 + lhs->e33 * rhs->e33;

}

onumm3n4_t onumm3n4_mul_ro(  coeff_t lhs,  onumm3n4_t* rhs){
  onumm3n4_t res;

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
  // Order 3;
  res.e111 = lhs * rhs->e111;
  res.e112 = lhs * rhs->e112;
  res.e122 = lhs * rhs->e122;
  res.e222 = lhs * rhs->e222;
  res.e113 = lhs * rhs->e113;
  res.e123 = lhs * rhs->e123;
  res.e223 = lhs * rhs->e223;
  res.e133 = lhs * rhs->e133;
  res.e233 = lhs * rhs->e233;
  res.e333 = lhs * rhs->e333;
  // Order 4;
  res.e1111 = lhs * rhs->e1111;
  res.e1112 = lhs * rhs->e1112;
  res.e1122 = lhs * rhs->e1122;
  res.e1222 = lhs * rhs->e1222;
  res.e2222 = lhs * rhs->e2222;
  res.e1113 = lhs * rhs->e1113;
  res.e1123 = lhs * rhs->e1123;
  res.e1223 = lhs * rhs->e1223;
  res.e2223 = lhs * rhs->e2223;
  res.e1133 = lhs * rhs->e1133;
  res.e1233 = lhs * rhs->e1233;
  res.e2233 = lhs * rhs->e2233;
  res.e1333 = lhs * rhs->e1333;
  res.e2333 = lhs * rhs->e2333;
  res.e3333 = lhs * rhs->e3333;

  return res;

}

void onumm3n4_mul_ro_to(  coeff_t lhs,  onumm3n4_t* rhs, onumm3n4_t* res){
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
  // Order 3;
  res->e111 = lhs * rhs->e111;
  res->e112 = lhs * rhs->e112;
  res->e122 = lhs * rhs->e122;
  res->e222 = lhs * rhs->e222;
  res->e113 = lhs * rhs->e113;
  res->e123 = lhs * rhs->e123;
  res->e223 = lhs * rhs->e223;
  res->e133 = lhs * rhs->e133;
  res->e233 = lhs * rhs->e233;
  res->e333 = lhs * rhs->e333;
  // Order 4;
  res->e1111 = lhs * rhs->e1111;
  res->e1112 = lhs * rhs->e1112;
  res->e1122 = lhs * rhs->e1122;
  res->e1222 = lhs * rhs->e1222;
  res->e2222 = lhs * rhs->e2222;
  res->e1113 = lhs * rhs->e1113;
  res->e1123 = lhs * rhs->e1123;
  res->e1223 = lhs * rhs->e1223;
  res->e2223 = lhs * rhs->e2223;
  res->e1133 = lhs * rhs->e1133;
  res->e1233 = lhs * rhs->e1233;
  res->e2233 = lhs * rhs->e2233;
  res->e1333 = lhs * rhs->e1333;
  res->e2333 = lhs * rhs->e2333;
  res->e3333 = lhs * rhs->e3333;

}

onumm3n4_t onumm3n4_trunc_mul_oo(  onumm3n4_t* lhs,  onumm3n4_t* rhs){
  onumm3n4_t res;

  res = onumm3n4_init();

  //  Truncated multiplication like function 'lhs * rhs'
  // Order 2;
  res.e11 =  + lhs->e1 * rhs->e1;
  res.e12 =  + lhs->e1 * rhs->e2 + lhs->e2 * rhs->e1;
  res.e22 =  + lhs->e2 * rhs->e2;
  res.e13 =  + lhs->e1 * rhs->e3 + lhs->e3 * rhs->e1;
  res.e23 =  + lhs->e2 * rhs->e3 + lhs->e3 * rhs->e2;
  res.e33 =  + lhs->e3 * rhs->e3;
  // Order 3;
  res.e111 =  + lhs->e1 * rhs->e11 + lhs->e11 * rhs->e1;
  res.e112 =  + lhs->e1 * rhs->e12 + lhs->e12 * rhs->e1 + lhs->e2 * rhs->e11 
           + lhs->e11 * rhs->e2;
  res.e122 =  + lhs->e1 * rhs->e22 + lhs->e22 * rhs->e1 + lhs->e2 * rhs->e12 
           + lhs->e12 * rhs->e2;
  res.e222 =  + lhs->e2 * rhs->e22 + lhs->e22 * rhs->e2;
  res.e113 =  + lhs->e1 * rhs->e13 + lhs->e13 * rhs->e1 + lhs->e3 * rhs->e11 
           + lhs->e11 * rhs->e3;
  res.e123 =  + lhs->e1 * rhs->e23 + lhs->e23 * rhs->e1 + lhs->e2 * rhs->e13 
           + lhs->e13 * rhs->e2 + lhs->e3 * rhs->e12 + lhs->e12 * rhs->e3;
  res.e223 =  + lhs->e2 * rhs->e23 + lhs->e23 * rhs->e2 + lhs->e3 * rhs->e22 
           + lhs->e22 * rhs->e3;
  res.e133 =  + lhs->e1 * rhs->e33 + lhs->e33 * rhs->e1 + lhs->e3 * rhs->e13 
           + lhs->e13 * rhs->e3;
  res.e233 =  + lhs->e2 * rhs->e33 + lhs->e33 * rhs->e2 + lhs->e3 * rhs->e23 
           + lhs->e23 * rhs->e3;
  res.e333 =  + lhs->e3 * rhs->e33 + lhs->e33 * rhs->e3;
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
  res.e1113 =  + lhs->e1 * rhs->e113 + lhs->e113 * rhs->e1 + lhs->e3 * rhs->e111 
            + lhs->e111 * rhs->e3 + lhs->e11 * rhs->e13 + lhs->e13 * rhs->e11;
  res.e1123 =  + lhs->e1 * rhs->e123 + lhs->e123 * rhs->e1 + lhs->e2 * rhs->e113 
            + lhs->e113 * rhs->e2 + lhs->e3 * rhs->e112 + lhs->e112 * rhs->e3 
            + lhs->e11 * rhs->e23 + lhs->e12 * rhs->e13 + lhs->e13 * rhs->e12 
            + lhs->e23 * rhs->e11;
  res.e1223 =  + lhs->e1 * rhs->e223 + lhs->e223 * rhs->e1 + lhs->e2 * rhs->e123 
            + lhs->e123 * rhs->e2 + lhs->e3 * rhs->e122 + lhs->e122 * rhs->e3 
            + lhs->e12 * rhs->e23 + lhs->e22 * rhs->e13 + lhs->e13 * rhs->e22 
            + lhs->e23 * rhs->e12;
  res.e2223 =  + lhs->e2 * rhs->e223 + lhs->e223 * rhs->e2 + lhs->e3 * rhs->e222 
            + lhs->e222 * rhs->e3 + lhs->e22 * rhs->e23 + lhs->e23 * rhs->e22;
  res.e1133 =  + lhs->e1 * rhs->e133 + lhs->e133 * rhs->e1 + lhs->e3 * rhs->e113 
            + lhs->e113 * rhs->e3 + lhs->e11 * rhs->e33 + lhs->e13 * rhs->e13 
            + lhs->e33 * rhs->e11;
  res.e1233 =  + lhs->e1 * rhs->e233 + lhs->e233 * rhs->e1 + lhs->e2 * rhs->e133 
            + lhs->e133 * rhs->e2 + lhs->e3 * rhs->e123 + lhs->e123 * rhs->e3 
            + lhs->e12 * rhs->e33 + lhs->e13 * rhs->e23 + lhs->e23 * rhs->e13 
            + lhs->e33 * rhs->e12;
  res.e2233 =  + lhs->e2 * rhs->e233 + lhs->e233 * rhs->e2 + lhs->e3 * rhs->e223 
            + lhs->e223 * rhs->e3 + lhs->e22 * rhs->e33 + lhs->e23 * rhs->e23 
            + lhs->e33 * rhs->e22;
  res.e1333 =  + lhs->e1 * rhs->e333 + lhs->e333 * rhs->e1 + lhs->e3 * rhs->e133 
            + lhs->e133 * rhs->e3 + lhs->e13 * rhs->e33 + lhs->e33 * rhs->e13;
  res.e2333 =  + lhs->e2 * rhs->e333 + lhs->e333 * rhs->e2 + lhs->e3 * rhs->e233 
            + lhs->e233 * rhs->e3 + lhs->e23 * rhs->e33 + lhs->e33 * rhs->e23;
  res.e3333 =  + lhs->e3 * rhs->e333 + lhs->e333 * rhs->e3 + lhs->e33 * rhs->e33;

  return res;

}

void onumm3n4_trunc_mul_oo_to(  onumm3n4_t* lhs,  onumm3n4_t* rhs, onumm3n4_t* res){
   (*res) = onumm3n4_init();

  //  Truncated multiplication like function 'lhs * rhs'
  // Order 2;
  res->e11 =  + lhs->e1 * rhs->e1;
  res->e12 =  + lhs->e1 * rhs->e2 + lhs->e2 * rhs->e1;
  res->e22 =  + lhs->e2 * rhs->e2;
  res->e13 =  + lhs->e1 * rhs->e3 + lhs->e3 * rhs->e1;
  res->e23 =  + lhs->e2 * rhs->e3 + lhs->e3 * rhs->e2;
  res->e33 =  + lhs->e3 * rhs->e3;
  // Order 3;
  res->e111 =  + lhs->e1 * rhs->e11 + lhs->e11 * rhs->e1;
  res->e112 =  + lhs->e1 * rhs->e12 + lhs->e12 * rhs->e1 + lhs->e2 * rhs->e11 
           + lhs->e11 * rhs->e2;
  res->e122 =  + lhs->e1 * rhs->e22 + lhs->e22 * rhs->e1 + lhs->e2 * rhs->e12 
           + lhs->e12 * rhs->e2;
  res->e222 =  + lhs->e2 * rhs->e22 + lhs->e22 * rhs->e2;
  res->e113 =  + lhs->e1 * rhs->e13 + lhs->e13 * rhs->e1 + lhs->e3 * rhs->e11 
           + lhs->e11 * rhs->e3;
  res->e123 =  + lhs->e1 * rhs->e23 + lhs->e23 * rhs->e1 + lhs->e2 * rhs->e13 
           + lhs->e13 * rhs->e2 + lhs->e3 * rhs->e12 + lhs->e12 * rhs->e3;
  res->e223 =  + lhs->e2 * rhs->e23 + lhs->e23 * rhs->e2 + lhs->e3 * rhs->e22 
           + lhs->e22 * rhs->e3;
  res->e133 =  + lhs->e1 * rhs->e33 + lhs->e33 * rhs->e1 + lhs->e3 * rhs->e13 
           + lhs->e13 * rhs->e3;
  res->e233 =  + lhs->e2 * rhs->e33 + lhs->e33 * rhs->e2 + lhs->e3 * rhs->e23 
           + lhs->e23 * rhs->e3;
  res->e333 =  + lhs->e3 * rhs->e33 + lhs->e33 * rhs->e3;
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
  res->e1113 =  + lhs->e1 * rhs->e113 + lhs->e113 * rhs->e1 + lhs->e3 * rhs->e111 
            + lhs->e111 * rhs->e3 + lhs->e11 * rhs->e13 + lhs->e13 * rhs->e11;
  res->e1123 =  + lhs->e1 * rhs->e123 + lhs->e123 * rhs->e1 + lhs->e2 * rhs->e113 
            + lhs->e113 * rhs->e2 + lhs->e3 * rhs->e112 + lhs->e112 * rhs->e3 
            + lhs->e11 * rhs->e23 + lhs->e12 * rhs->e13 + lhs->e13 * rhs->e12 
            + lhs->e23 * rhs->e11;
  res->e1223 =  + lhs->e1 * rhs->e223 + lhs->e223 * rhs->e1 + lhs->e2 * rhs->e123 
            + lhs->e123 * rhs->e2 + lhs->e3 * rhs->e122 + lhs->e122 * rhs->e3 
            + lhs->e12 * rhs->e23 + lhs->e22 * rhs->e13 + lhs->e13 * rhs->e22 
            + lhs->e23 * rhs->e12;
  res->e2223 =  + lhs->e2 * rhs->e223 + lhs->e223 * rhs->e2 + lhs->e3 * rhs->e222 
            + lhs->e222 * rhs->e3 + lhs->e22 * rhs->e23 + lhs->e23 * rhs->e22;
  res->e1133 =  + lhs->e1 * rhs->e133 + lhs->e133 * rhs->e1 + lhs->e3 * rhs->e113 
            + lhs->e113 * rhs->e3 + lhs->e11 * rhs->e33 + lhs->e13 * rhs->e13 
            + lhs->e33 * rhs->e11;
  res->e1233 =  + lhs->e1 * rhs->e233 + lhs->e233 * rhs->e1 + lhs->e2 * rhs->e133 
            + lhs->e133 * rhs->e2 + lhs->e3 * rhs->e123 + lhs->e123 * rhs->e3 
            + lhs->e12 * rhs->e33 + lhs->e13 * rhs->e23 + lhs->e23 * rhs->e13 
            + lhs->e33 * rhs->e12;
  res->e2233 =  + lhs->e2 * rhs->e233 + lhs->e233 * rhs->e2 + lhs->e3 * rhs->e223 
            + lhs->e223 * rhs->e3 + lhs->e22 * rhs->e33 + lhs->e23 * rhs->e23 
            + lhs->e33 * rhs->e22;
  res->e1333 =  + lhs->e1 * rhs->e333 + lhs->e333 * rhs->e1 + lhs->e3 * rhs->e133 
            + lhs->e133 * rhs->e3 + lhs->e13 * rhs->e33 + lhs->e33 * rhs->e13;
  res->e2333 =  + lhs->e2 * rhs->e333 + lhs->e333 * rhs->e2 + lhs->e3 * rhs->e233 
            + lhs->e233 * rhs->e3 + lhs->e23 * rhs->e33 + lhs->e33 * rhs->e23;
  res->e3333 =  + lhs->e3 * rhs->e333 + lhs->e333 * rhs->e3 + lhs->e33 * rhs->e33;

}

onumm3n4_t onumm3n4_gem_oo(  onumm3n4_t* a,  onumm3n4_t* b,  onumm3n4_t* c){
  onumm3n4_t res;

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
  // Order 3;
  res.e111 = c->e111 + a->r * b->e111 + a->e111 * b->r + a->e1 * b->e11 
           + a->e11 * b->e1;
  res.e112 = c->e112 + a->r * b->e112 + a->e112 * b->r + a->e1 * b->e12 
           + a->e12 * b->e1 + a->e2 * b->e11 + a->e11 * b->e2;
  res.e122 = c->e122 + a->r * b->e122 + a->e122 * b->r + a->e1 * b->e22 
           + a->e22 * b->e1 + a->e2 * b->e12 + a->e12 * b->e2;
  res.e222 = c->e222 + a->r * b->e222 + a->e222 * b->r + a->e2 * b->e22 
           + a->e22 * b->e2;
  res.e113 = c->e113 + a->r * b->e113 + a->e113 * b->r + a->e1 * b->e13 
           + a->e13 * b->e1 + a->e3 * b->e11 + a->e11 * b->e3;
  res.e123 = c->e123 + a->r * b->e123 + a->e123 * b->r + a->e1 * b->e23 
           + a->e23 * b->e1 + a->e2 * b->e13 + a->e13 * b->e2 
           + a->e3 * b->e12 + a->e12 * b->e3;
  res.e223 = c->e223 + a->r * b->e223 + a->e223 * b->r + a->e2 * b->e23 
           + a->e23 * b->e2 + a->e3 * b->e22 + a->e22 * b->e3;
  res.e133 = c->e133 + a->r * b->e133 + a->e133 * b->r + a->e1 * b->e33 
           + a->e33 * b->e1 + a->e3 * b->e13 + a->e13 * b->e3;
  res.e233 = c->e233 + a->r * b->e233 + a->e233 * b->r + a->e2 * b->e33 
           + a->e33 * b->e2 + a->e3 * b->e23 + a->e23 * b->e3;
  res.e333 = c->e333 + a->r * b->e333 + a->e333 * b->r + a->e3 * b->e33 
           + a->e33 * b->e3;
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
  res.e1113 = c->e1113 + a->r * b->e1113 + a->e1113 * b->r + a->e1 * b->e113 
            + a->e113 * b->e1 + a->e3 * b->e111 + a->e111 * b->e3 
            + a->e11 * b->e13 + a->e13 * b->e11;
  res.e1123 = c->e1123 + a->r * b->e1123 + a->e1123 * b->r + a->e1 * b->e123 
            + a->e123 * b->e1 + a->e2 * b->e113 + a->e113 * b->e2 
            + a->e3 * b->e112 + a->e112 * b->e3 + a->e11 * b->e23 
            + a->e12 * b->e13 + a->e13 * b->e12 + a->e23 * b->e11;
  res.e1223 = c->e1223 + a->r * b->e1223 + a->e1223 * b->r + a->e1 * b->e223 
            + a->e223 * b->e1 + a->e2 * b->e123 + a->e123 * b->e2 
            + a->e3 * b->e122 + a->e122 * b->e3 + a->e12 * b->e23 
            + a->e22 * b->e13 + a->e13 * b->e22 + a->e23 * b->e12;
  res.e2223 = c->e2223 + a->r * b->e2223 + a->e2223 * b->r + a->e2 * b->e223 
            + a->e223 * b->e2 + a->e3 * b->e222 + a->e222 * b->e3 
            + a->e22 * b->e23 + a->e23 * b->e22;
  res.e1133 = c->e1133 + a->r * b->e1133 + a->e1133 * b->r + a->e1 * b->e133 
            + a->e133 * b->e1 + a->e3 * b->e113 + a->e113 * b->e3 
            + a->e11 * b->e33 + a->e13 * b->e13 + a->e33 * b->e11;
  res.e1233 = c->e1233 + a->r * b->e1233 + a->e1233 * b->r + a->e1 * b->e233 
            + a->e233 * b->e1 + a->e2 * b->e133 + a->e133 * b->e2 
            + a->e3 * b->e123 + a->e123 * b->e3 + a->e12 * b->e33 
            + a->e13 * b->e23 + a->e23 * b->e13 + a->e33 * b->e12;
  res.e2233 = c->e2233 + a->r * b->e2233 + a->e2233 * b->r + a->e2 * b->e233 
            + a->e233 * b->e2 + a->e3 * b->e223 + a->e223 * b->e3 
            + a->e22 * b->e33 + a->e23 * b->e23 + a->e33 * b->e22;
  res.e1333 = c->e1333 + a->r * b->e1333 + a->e1333 * b->r + a->e1 * b->e333 
            + a->e333 * b->e1 + a->e3 * b->e133 + a->e133 * b->e3 
            + a->e13 * b->e33 + a->e33 * b->e13;
  res.e2333 = c->e2333 + a->r * b->e2333 + a->e2333 * b->r + a->e2 * b->e333 
            + a->e333 * b->e2 + a->e3 * b->e233 + a->e233 * b->e3 
            + a->e23 * b->e33 + a->e33 * b->e23;
  res.e3333 = c->e3333 + a->r * b->e3333 + a->e3333 * b->r + a->e3 * b->e333 
            + a->e333 * b->e3 + a->e33 * b->e33;

  return res;

}

void onumm3n4_gem_oo_to(  onumm3n4_t* a,  onumm3n4_t* b,  onumm3n4_t* c, onumm3n4_t* res){
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
  // Order 3;
  res->e111 = c->e111 + a->r * b->e111 + a->e111 * b->r + a->e1 * b->e11 
           + a->e11 * b->e1;
  res->e112 = c->e112 + a->r * b->e112 + a->e112 * b->r + a->e1 * b->e12 
           + a->e12 * b->e1 + a->e2 * b->e11 + a->e11 * b->e2;
  res->e122 = c->e122 + a->r * b->e122 + a->e122 * b->r + a->e1 * b->e22 
           + a->e22 * b->e1 + a->e2 * b->e12 + a->e12 * b->e2;
  res->e222 = c->e222 + a->r * b->e222 + a->e222 * b->r + a->e2 * b->e22 
           + a->e22 * b->e2;
  res->e113 = c->e113 + a->r * b->e113 + a->e113 * b->r + a->e1 * b->e13 
           + a->e13 * b->e1 + a->e3 * b->e11 + a->e11 * b->e3;
  res->e123 = c->e123 + a->r * b->e123 + a->e123 * b->r + a->e1 * b->e23 
           + a->e23 * b->e1 + a->e2 * b->e13 + a->e13 * b->e2 
           + a->e3 * b->e12 + a->e12 * b->e3;
  res->e223 = c->e223 + a->r * b->e223 + a->e223 * b->r + a->e2 * b->e23 
           + a->e23 * b->e2 + a->e3 * b->e22 + a->e22 * b->e3;
  res->e133 = c->e133 + a->r * b->e133 + a->e133 * b->r + a->e1 * b->e33 
           + a->e33 * b->e1 + a->e3 * b->e13 + a->e13 * b->e3;
  res->e233 = c->e233 + a->r * b->e233 + a->e233 * b->r + a->e2 * b->e33 
           + a->e33 * b->e2 + a->e3 * b->e23 + a->e23 * b->e3;
  res->e333 = c->e333 + a->r * b->e333 + a->e333 * b->r + a->e3 * b->e33 
           + a->e33 * b->e3;
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
  res->e1113 = c->e1113 + a->r * b->e1113 + a->e1113 * b->r + a->e1 * b->e113 
            + a->e113 * b->e1 + a->e3 * b->e111 + a->e111 * b->e3 
            + a->e11 * b->e13 + a->e13 * b->e11;
  res->e1123 = c->e1123 + a->r * b->e1123 + a->e1123 * b->r + a->e1 * b->e123 
            + a->e123 * b->e1 + a->e2 * b->e113 + a->e113 * b->e2 
            + a->e3 * b->e112 + a->e112 * b->e3 + a->e11 * b->e23 
            + a->e12 * b->e13 + a->e13 * b->e12 + a->e23 * b->e11;
  res->e1223 = c->e1223 + a->r * b->e1223 + a->e1223 * b->r + a->e1 * b->e223 
            + a->e223 * b->e1 + a->e2 * b->e123 + a->e123 * b->e2 
            + a->e3 * b->e122 + a->e122 * b->e3 + a->e12 * b->e23 
            + a->e22 * b->e13 + a->e13 * b->e22 + a->e23 * b->e12;
  res->e2223 = c->e2223 + a->r * b->e2223 + a->e2223 * b->r + a->e2 * b->e223 
            + a->e223 * b->e2 + a->e3 * b->e222 + a->e222 * b->e3 
            + a->e22 * b->e23 + a->e23 * b->e22;
  res->e1133 = c->e1133 + a->r * b->e1133 + a->e1133 * b->r + a->e1 * b->e133 
            + a->e133 * b->e1 + a->e3 * b->e113 + a->e113 * b->e3 
            + a->e11 * b->e33 + a->e13 * b->e13 + a->e33 * b->e11;
  res->e1233 = c->e1233 + a->r * b->e1233 + a->e1233 * b->r + a->e1 * b->e233 
            + a->e233 * b->e1 + a->e2 * b->e133 + a->e133 * b->e2 
            + a->e3 * b->e123 + a->e123 * b->e3 + a->e12 * b->e33 
            + a->e13 * b->e23 + a->e23 * b->e13 + a->e33 * b->e12;
  res->e2233 = c->e2233 + a->r * b->e2233 + a->e2233 * b->r + a->e2 * b->e233 
            + a->e233 * b->e2 + a->e3 * b->e223 + a->e223 * b->e3 
            + a->e22 * b->e33 + a->e23 * b->e23 + a->e33 * b->e22;
  res->e1333 = c->e1333 + a->r * b->e1333 + a->e1333 * b->r + a->e1 * b->e333 
            + a->e333 * b->e1 + a->e3 * b->e133 + a->e133 * b->e3 
            + a->e13 * b->e33 + a->e33 * b->e13;
  res->e2333 = c->e2333 + a->r * b->e2333 + a->e2333 * b->r + a->e2 * b->e333 
            + a->e333 * b->e2 + a->e3 * b->e233 + a->e233 * b->e3 
            + a->e23 * b->e33 + a->e33 * b->e23;
  res->e3333 = c->e3333 + a->r * b->e3333 + a->e3333 * b->r + a->e3 * b->e333 
            + a->e333 * b->e3 + a->e33 * b->e33;

}

onumm3n4_t onumm3n4_gem_ro(  coeff_t a,  onumm3n4_t* b,  onumm3n4_t* c){
  onumm3n4_t res;

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
  // Order 3;
  res.e111 = c->e111 + a * b->e111;
  res.e112 = c->e112 + a * b->e112;
  res.e122 = c->e122 + a * b->e122;
  res.e222 = c->e222 + a * b->e222;
  res.e113 = c->e113 + a * b->e113;
  res.e123 = c->e123 + a * b->e123;
  res.e223 = c->e223 + a * b->e223;
  res.e133 = c->e133 + a * b->e133;
  res.e233 = c->e233 + a * b->e233;
  res.e333 = c->e333 + a * b->e333;
  // Order 4;
  res.e1111 = c->e1111 + a * b->e1111;
  res.e1112 = c->e1112 + a * b->e1112;
  res.e1122 = c->e1122 + a * b->e1122;
  res.e1222 = c->e1222 + a * b->e1222;
  res.e2222 = c->e2222 + a * b->e2222;
  res.e1113 = c->e1113 + a * b->e1113;
  res.e1123 = c->e1123 + a * b->e1123;
  res.e1223 = c->e1223 + a * b->e1223;
  res.e2223 = c->e2223 + a * b->e2223;
  res.e1133 = c->e1133 + a * b->e1133;
  res.e1233 = c->e1233 + a * b->e1233;
  res.e2233 = c->e2233 + a * b->e2233;
  res.e1333 = c->e1333 + a * b->e1333;
  res.e2333 = c->e2333 + a * b->e2333;
  res.e3333 = c->e3333 + a * b->e3333;

  return res;

}

void onumm3n4_gem_ro_to(  coeff_t a,  onumm3n4_t* b,  onumm3n4_t* c, onumm3n4_t* res){
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
  // Order 3;
  res->e111 = c->e111 + a * b->e111;
  res->e112 = c->e112 + a * b->e112;
  res->e122 = c->e122 + a * b->e122;
  res->e222 = c->e222 + a * b->e222;
  res->e113 = c->e113 + a * b->e113;
  res->e123 = c->e123 + a * b->e123;
  res->e223 = c->e223 + a * b->e223;
  res->e133 = c->e133 + a * b->e133;
  res->e233 = c->e233 + a * b->e233;
  res->e333 = c->e333 + a * b->e333;
  // Order 4;
  res->e1111 = c->e1111 + a * b->e1111;
  res->e1112 = c->e1112 + a * b->e1112;
  res->e1122 = c->e1122 + a * b->e1122;
  res->e1222 = c->e1222 + a * b->e1222;
  res->e2222 = c->e2222 + a * b->e2222;
  res->e1113 = c->e1113 + a * b->e1113;
  res->e1123 = c->e1123 + a * b->e1123;
  res->e1223 = c->e1223 + a * b->e1223;
  res->e2223 = c->e2223 + a * b->e2223;
  res->e1133 = c->e1133 + a * b->e1133;
  res->e1233 = c->e1233 + a * b->e1233;
  res->e2233 = c->e2233 + a * b->e2233;
  res->e1333 = c->e1333 + a * b->e1333;
  res->e2333 = c->e2333 + a * b->e2333;
  res->e3333 = c->e3333 + a * b->e3333;

}

void onumm3n4_trunc_gem_oo_to( ord_t ord_lhs,  onumm3n4_t* a,  ord_t ord_rhs,  onumm3n4_t* b,  onumm3n4_t* c, onumm3n4_t* res){
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
        case 3:
          // res order: 3
          res->e111 = c->e111 + a->r * b->e111;
          res->e112 = c->e112 + a->r * b->e112;
          res->e122 = c->e122 + a->r * b->e122;
          res->e222 = c->e222 + a->r * b->e222;
          res->e113 = c->e113 + a->r * b->e113;
          res->e123 = c->e123 + a->r * b->e123;
          res->e223 = c->e223 + a->r * b->e223;
          res->e133 = c->e133 + a->r * b->e133;
          res->e233 = c->e233 + a->r * b->e233;
          res->e333 = c->e333 + a->r * b->e333;
          break;
        case 4:
          // res order: 4
          res->e1111 = c->e1111 + a->r * b->e1111;
          res->e1112 = c->e1112 + a->r * b->e1112;
          res->e1122 = c->e1122 + a->r * b->e1122;
          res->e1222 = c->e1222 + a->r * b->e1222;
          res->e2222 = c->e2222 + a->r * b->e2222;
          res->e1113 = c->e1113 + a->r * b->e1113;
          res->e1123 = c->e1123 + a->r * b->e1123;
          res->e1223 = c->e1223 + a->r * b->e1223;
          res->e2223 = c->e2223 + a->r * b->e2223;
          res->e1133 = c->e1133 + a->r * b->e1133;
          res->e1233 = c->e1233 + a->r * b->e1233;
          res->e2233 = c->e2233 + a->r * b->e2233;
          res->e1333 = c->e1333 + a->r * b->e1333;
          res->e2333 = c->e2333 + a->r * b->e2333;
          res->e3333 = c->e3333 + a->r * b->e3333;
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
        case 2:
          // res order: 3
          res->e111 = c->e111 + a->e1 * b->e11;
          res->e112 = c->e112 + a->e1 * b->e12 + a->e2 * b->e11;
          res->e122 = c->e122 + a->e1 * b->e22 + a->e2 * b->e12;
          res->e222 = c->e222 + a->e2 * b->e22;
          res->e113 = c->e113 + a->e1 * b->e13 + a->e3 * b->e11;
          res->e123 = c->e123 + a->e1 * b->e23 + a->e2 * b->e13 
                    + a->e3 * b->e12;
          res->e223 = c->e223 + a->e2 * b->e23 + a->e3 * b->e22;
          res->e133 = c->e133 + a->e1 * b->e33 + a->e3 * b->e13;
          res->e233 = c->e233 + a->e2 * b->e33 + a->e3 * b->e23;
          res->e333 = c->e333 + a->e3 * b->e33;
          break;
        case 3:
          // res order: 4
          res->e1111 = c->e1111 + a->e1 * b->e111;
          res->e1112 = c->e1112 + a->e1 * b->e112 + a->e2 * b->e111;
          res->e1122 = c->e1122 + a->e1 * b->e122 + a->e2 * b->e112;
          res->e1222 = c->e1222 + a->e1 * b->e222 + a->e2 * b->e122;
          res->e2222 = c->e2222 + a->e2 * b->e222;
          res->e1113 = c->e1113 + a->e1 * b->e113 + a->e3 * b->e111;
          res->e1123 = c->e1123 + a->e1 * b->e123 + a->e2 * b->e113 
                     + a->e3 * b->e112;
          res->e1223 = c->e1223 + a->e1 * b->e223 + a->e2 * b->e123 
                     + a->e3 * b->e122;
          res->e2223 = c->e2223 + a->e2 * b->e223 + a->e3 * b->e222;
          res->e1133 = c->e1133 + a->e1 * b->e133 + a->e3 * b->e113;
          res->e1233 = c->e1233 + a->e1 * b->e233 + a->e2 * b->e133 
                     + a->e3 * b->e123;
          res->e2233 = c->e2233 + a->e2 * b->e233 + a->e3 * b->e223;
          res->e1333 = c->e1333 + a->e1 * b->e333 + a->e3 * b->e133;
          res->e2333 = c->e2333 + a->e2 * b->e333 + a->e3 * b->e233;
          res->e3333 = c->e3333 + a->e3 * b->e333;
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
        case 1:
          // res order: 3
          res->e111 = c->e111 + a->e11 * b->e1;
          res->e112 = c->e112 + a->e12 * b->e1 + a->e11 * b->e2;
          res->e122 = c->e122 + a->e22 * b->e1 + a->e12 * b->e2;
          res->e222 = c->e222 + a->e22 * b->e2;
          res->e113 = c->e113 + a->e13 * b->e1 + a->e11 * b->e3;
          res->e123 = c->e123 + a->e23 * b->e1 + a->e13 * b->e2 
                    + a->e12 * b->e3;
          res->e223 = c->e223 + a->e23 * b->e2 + a->e22 * b->e3;
          res->e133 = c->e133 + a->e33 * b->e1 + a->e13 * b->e3;
          res->e233 = c->e233 + a->e33 * b->e2 + a->e23 * b->e3;
          res->e333 = c->e333 + a->e33 * b->e3;
          break;
        case 2:
          // res order: 4
          res->e1111 = c->e1111 + a->e11 * b->e11;
          res->e1112 = c->e1112 + a->e11 * b->e12 + a->e12 * b->e11;
          res->e1122 = c->e1122 + a->e11 * b->e22 + a->e12 * b->e12 
                     + a->e22 * b->e11;
          res->e1222 = c->e1222 + a->e12 * b->e22 + a->e22 * b->e12;
          res->e2222 = c->e2222 + a->e22 * b->e22;
          res->e1113 = c->e1113 + a->e11 * b->e13 + a->e13 * b->e11;
          res->e1123 = c->e1123 + a->e11 * b->e23 + a->e12 * b->e13 
                     + a->e13 * b->e12 + a->e23 * b->e11;
          res->e1223 = c->e1223 + a->e12 * b->e23 + a->e22 * b->e13 
                     + a->e13 * b->e22 + a->e23 * b->e12;
          res->e2223 = c->e2223 + a->e22 * b->e23 + a->e23 * b->e22;
          res->e1133 = c->e1133 + a->e11 * b->e33 + a->e13 * b->e13 
                     + a->e33 * b->e11;
          res->e1233 = c->e1233 + a->e12 * b->e33 + a->e13 * b->e23 
                     + a->e23 * b->e13 + a->e33 * b->e12;
          res->e2233 = c->e2233 + a->e22 * b->e33 + a->e23 * b->e23 
                     + a->e33 * b->e22;
          res->e1333 = c->e1333 + a->e13 * b->e33 + a->e33 * b->e13;
          res->e2333 = c->e2333 + a->e23 * b->e33 + a->e33 * b->e23;
          res->e3333 = c->e3333 + a->e33 * b->e33;
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
          res->e113 = c->e113 + a->e113 * b->r;
          res->e123 = c->e123 + a->e123 * b->r;
          res->e223 = c->e223 + a->e223 * b->r;
          res->e133 = c->e133 + a->e133 * b->r;
          res->e233 = c->e233 + a->e233 * b->r;
          res->e333 = c->e333 + a->e333 * b->r;
          break;
        case 1:
          // res order: 4
          res->e1111 = c->e1111 + a->e111 * b->e1;
          res->e1112 = c->e1112 + a->e112 * b->e1 + a->e111 * b->e2;
          res->e1122 = c->e1122 + a->e122 * b->e1 + a->e112 * b->e2;
          res->e1222 = c->e1222 + a->e222 * b->e1 + a->e122 * b->e2;
          res->e2222 = c->e2222 + a->e222 * b->e2;
          res->e1113 = c->e1113 + a->e113 * b->e1 + a->e111 * b->e3;
          res->e1123 = c->e1123 + a->e123 * b->e1 + a->e113 * b->e2 
                     + a->e112 * b->e3;
          res->e1223 = c->e1223 + a->e223 * b->e1 + a->e123 * b->e2 
                     + a->e122 * b->e3;
          res->e2223 = c->e2223 + a->e223 * b->e2 + a->e222 * b->e3;
          res->e1133 = c->e1133 + a->e133 * b->e1 + a->e113 * b->e3;
          res->e1233 = c->e1233 + a->e233 * b->e1 + a->e133 * b->e2 
                     + a->e123 * b->e3;
          res->e2233 = c->e2233 + a->e233 * b->e2 + a->e223 * b->e3;
          res->e1333 = c->e1333 + a->e333 * b->e1 + a->e133 * b->e3;
          res->e2333 = c->e2333 + a->e333 * b->e2 + a->e233 * b->e3;
          res->e3333 = c->e3333 + a->e333 * b->e3;
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
          res->e1113 = c->e1113 + a->e1113 * b->r;
          res->e1123 = c->e1123 + a->e1123 * b->r;
          res->e1223 = c->e1223 + a->e1223 * b->r;
          res->e2223 = c->e2223 + a->e2223 * b->r;
          res->e1133 = c->e1133 + a->e1133 * b->r;
          res->e1233 = c->e1233 + a->e1233 * b->r;
          res->e2233 = c->e2233 + a->e2233 * b->r;
          res->e1333 = c->e1333 + a->e1333 * b->r;
          res->e2333 = c->e2333 + a->e2333 * b->r;
          res->e3333 = c->e3333 + a->e3333 * b->r;
          break;
      }
      break;
  }

}

void onumm3n4_trunc_sum_oo_to(ord_t order, onumm3n4_t* lhs,onumm3n4_t* rhs, onumm3n4_t* res){
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
    case(3):    // Order 3
      res->e111 = lhs->e111 + rhs->e111;
      res->e112 = lhs->e112 + rhs->e112;
      res->e122 = lhs->e122 + rhs->e122;
      res->e222 = lhs->e222 + rhs->e222;
      res->e113 = lhs->e113 + rhs->e113;
      res->e123 = lhs->e123 + rhs->e123;
      res->e223 = lhs->e223 + rhs->e223;
      res->e133 = lhs->e133 + rhs->e133;
      res->e233 = lhs->e233 + rhs->e233;
      res->e333 = lhs->e333 + rhs->e333;
      break;
    case(4):    // Order 4
      res->e1111 = lhs->e1111 + rhs->e1111;
      res->e1112 = lhs->e1112 + rhs->e1112;
      res->e1122 = lhs->e1122 + rhs->e1122;
      res->e1222 = lhs->e1222 + rhs->e1222;
      res->e2222 = lhs->e2222 + rhs->e2222;
      res->e1113 = lhs->e1113 + rhs->e1113;
      res->e1123 = lhs->e1123 + rhs->e1123;
      res->e1223 = lhs->e1223 + rhs->e1223;
      res->e2223 = lhs->e2223 + rhs->e2223;
      res->e1133 = lhs->e1133 + rhs->e1133;
      res->e1233 = lhs->e1233 + rhs->e1233;
      res->e2233 = lhs->e2233 + rhs->e2233;
      res->e1333 = lhs->e1333 + rhs->e1333;
      res->e2333 = lhs->e2333 + rhs->e2333;
      res->e3333 = lhs->e3333 + rhs->e3333;
      break;
  }
}

void onumm3n4_trunc_sub_oo_to(ord_t order, onumm3n4_t* lhs,onumm3n4_t* rhs, onumm3n4_t* res){
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
    case(3):    // Order 3
      res->e111 = lhs->e111 - rhs->e111;
      res->e112 = lhs->e112 - rhs->e112;
      res->e122 = lhs->e122 - rhs->e122;
      res->e222 = lhs->e222 - rhs->e222;
      res->e113 = lhs->e113 - rhs->e113;
      res->e123 = lhs->e123 - rhs->e123;
      res->e223 = lhs->e223 - rhs->e223;
      res->e133 = lhs->e133 - rhs->e133;
      res->e233 = lhs->e233 - rhs->e233;
      res->e333 = lhs->e333 - rhs->e333;
      break;
    case(4):    // Order 4
      res->e1111 = lhs->e1111 - rhs->e1111;
      res->e1112 = lhs->e1112 - rhs->e1112;
      res->e1122 = lhs->e1122 - rhs->e1122;
      res->e1222 = lhs->e1222 - rhs->e1222;
      res->e2222 = lhs->e2222 - rhs->e2222;
      res->e1113 = lhs->e1113 - rhs->e1113;
      res->e1123 = lhs->e1123 - rhs->e1123;
      res->e1223 = lhs->e1223 - rhs->e1223;
      res->e2223 = lhs->e2223 - rhs->e2223;
      res->e1133 = lhs->e1133 - rhs->e1133;
      res->e1233 = lhs->e1233 - rhs->e1233;
      res->e2233 = lhs->e2233 - rhs->e2233;
      res->e1333 = lhs->e1333 - rhs->e1333;
      res->e2333 = lhs->e2333 - rhs->e2333;
      res->e3333 = lhs->e3333 - rhs->e3333;
      break;
  }
}

onumm3n4_t onumm3n4_feval(coeff_t* feval_re, onumm3n4_t* x){

  onumm3n4_t res;

  // feval function
  //  Definitions
  coeff_t factor=1, coef = 0;
  onumm3n4_t deltax = (*x), deltax_power = (*x);
  deltax.r = 0.0;
  deltax_power.r = 0.0;
  onumm3n4_set_r(0.0, &res);
  //  Real
  res.r = feval_re[0];
  // Order 1
  factor *=1;
  coef    = feval_re[1]/ factor;;
  onumm3n4_gem_ro_to( coef, &deltax_power, &res, &res);
  deltax_power = onumm3n4_mul_oo(&deltax_power,&deltax);
  // Order 2
  factor *=2;
  coef    = feval_re[2]/ factor;;
  onumm3n4_gem_ro_to( coef, &deltax_power, &res, &res);
  deltax_power = onumm3n4_mul_oo(&deltax_power,&deltax);
  // Order 3
  factor *=3;
  coef    = feval_re[3]/ factor;;
  onumm3n4_gem_ro_to( coef, &deltax_power, &res, &res);
  deltax_power = onumm3n4_mul_oo(&deltax_power,&deltax);
  // Order 4
  factor *=4;
  coef    = feval_re[4]/ factor;;
  onumm3n4_gem_ro_to( coef, &deltax_power, &res, &res);

  return res;

}

void onumm3n4_feval_to(coeff_t* feval_re, onumm3n4_t* x, onumm3n4_t* res){

  // feval function
  //  Definitions
  coeff_t factor=1, coef = 0;
  onumm3n4_t deltax = (*x), deltax_power = (*x);
  deltax.r = 0.0;
  deltax_power.r = 0.0;
  onumm3n4_set_r(0.0, res);
  //  Real
  res->r = feval_re[0];
  // Order 1
  factor *=1;
  coef    = feval_re[1]/ factor;;
  onumm3n4_gem_ro_to( coef, &deltax_power, res, res);
  deltax_power = onumm3n4_mul_oo(&deltax_power,&deltax);
  // Order 2
  factor *=2;
  coef    = feval_re[2]/ factor;;
  onumm3n4_gem_ro_to( coef, &deltax_power, res, res);
  deltax_power = onumm3n4_mul_oo(&deltax_power,&deltax);
  // Order 3
  factor *=3;
  coef    = feval_re[3]/ factor;;
  onumm3n4_gem_ro_to( coef, &deltax_power, res, res);
  deltax_power = onumm3n4_mul_oo(&deltax_power,&deltax);
  // Order 4
  factor *=4;
  coef    = feval_re[4]/ factor;;
  onumm3n4_gem_ro_to( coef, &deltax_power, res, res);

}

