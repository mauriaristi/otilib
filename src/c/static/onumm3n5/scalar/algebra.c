
// Division.

// ****************************************************************************************************
onumm3n5_t onumm3n5_div_ro(coeff_t num, onumm3n5_t* den){

    
    onumm3n5_t inv = onumm3n5_pow(den,-1);
    onumm3n5_t res = onumm3n5_mul_ro(num,&inv);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
onumm3n5_t onumm3n5_div_oo(onumm3n5_t* num, onumm3n5_t* den){

    
    onumm3n5_t inv = onumm3n5_init();
    onumm3n5_pow_to(den,-1,&inv);
    onumm3n5_t res = onumm3n5_mul_oo(num,&inv);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
onumm3n5_t onumm3n5_div_or(onumm3n5_t* num, coeff_t val){

    return onumm3n5_mul_ro(1.0/val,num);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
onumm3n5_t onumm3n5_abs(onumm3n5_t* num){

	onumm3n5_t res;
    onumm3n5_abs_to(num,&res);
    return res;

}
// ----------------------------------------------------------------------------------------------------

onumm3n5_t onumm3n5_neg(  onumm3n5_t* lhs){

  onumm3n5_t res;

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
  // Order 5;
  res.e11111 = -lhs->e11111;
  res.e11112 = -lhs->e11112;
  res.e11122 = -lhs->e11122;
  res.e11222 = -lhs->e11222;
  res.e12222 = -lhs->e12222;
  res.e22222 = -lhs->e22222;
  res.e11113 = -lhs->e11113;
  res.e11123 = -lhs->e11123;
  res.e11223 = -lhs->e11223;
  res.e12223 = -lhs->e12223;
  res.e22223 = -lhs->e22223;
  res.e11133 = -lhs->e11133;
  res.e11233 = -lhs->e11233;
  res.e12233 = -lhs->e12233;
  res.e22233 = -lhs->e22233;
  res.e11333 = -lhs->e11333;
  res.e12333 = -lhs->e12333;
  res.e22333 = -lhs->e22333;
  res.e13333 = -lhs->e13333;
  res.e23333 = -lhs->e23333;
  res.e33333 = -lhs->e33333;

  return res;

}

void onumm3n5_neg_to(  onumm3n5_t* lhs, onumm3n5_t* res){

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
  // Order 5;
  res->e11111 = -lhs->e11111;
  res->e11112 = -lhs->e11112;
  res->e11122 = -lhs->e11122;
  res->e11222 = -lhs->e11222;
  res->e12222 = -lhs->e12222;
  res->e22222 = -lhs->e22222;
  res->e11113 = -lhs->e11113;
  res->e11123 = -lhs->e11123;
  res->e11223 = -lhs->e11223;
  res->e12223 = -lhs->e12223;
  res->e22223 = -lhs->e22223;
  res->e11133 = -lhs->e11133;
  res->e11233 = -lhs->e11233;
  res->e12233 = -lhs->e12233;
  res->e22233 = -lhs->e22233;
  res->e11333 = -lhs->e11333;
  res->e12333 = -lhs->e12333;
  res->e22333 = -lhs->e22333;
  res->e13333 = -lhs->e13333;
  res->e23333 = -lhs->e23333;
  res->e33333 = -lhs->e33333;

}

onumm3n5_t onumm3n5_sum_oo(  onumm3n5_t* lhs,  onumm3n5_t* rhs){
  onumm3n5_t res;

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
  // Order 5
  res.e11111 = lhs->e11111 + rhs->e11111;
  res.e11112 = lhs->e11112 + rhs->e11112;
  res.e11122 = lhs->e11122 + rhs->e11122;
  res.e11222 = lhs->e11222 + rhs->e11222;
  res.e12222 = lhs->e12222 + rhs->e12222;
  res.e22222 = lhs->e22222 + rhs->e22222;
  res.e11113 = lhs->e11113 + rhs->e11113;
  res.e11123 = lhs->e11123 + rhs->e11123;
  res.e11223 = lhs->e11223 + rhs->e11223;
  res.e12223 = lhs->e12223 + rhs->e12223;
  res.e22223 = lhs->e22223 + rhs->e22223;
  res.e11133 = lhs->e11133 + rhs->e11133;
  res.e11233 = lhs->e11233 + rhs->e11233;
  res.e12233 = lhs->e12233 + rhs->e12233;
  res.e22233 = lhs->e22233 + rhs->e22233;
  res.e11333 = lhs->e11333 + rhs->e11333;
  res.e12333 = lhs->e12333 + rhs->e12333;
  res.e22333 = lhs->e22333 + rhs->e22333;
  res.e13333 = lhs->e13333 + rhs->e13333;
  res.e23333 = lhs->e23333 + rhs->e23333;
  res.e33333 = lhs->e33333 + rhs->e33333;

  return res;

}

void onumm3n5_sum_oo_to(  onumm3n5_t* lhs,  onumm3n5_t* rhs, onumm3n5_t* res){
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
  // Order 5
  res->e11111 = lhs->e11111 + rhs->e11111;
  res->e11112 = lhs->e11112 + rhs->e11112;
  res->e11122 = lhs->e11122 + rhs->e11122;
  res->e11222 = lhs->e11222 + rhs->e11222;
  res->e12222 = lhs->e12222 + rhs->e12222;
  res->e22222 = lhs->e22222 + rhs->e22222;
  res->e11113 = lhs->e11113 + rhs->e11113;
  res->e11123 = lhs->e11123 + rhs->e11123;
  res->e11223 = lhs->e11223 + rhs->e11223;
  res->e12223 = lhs->e12223 + rhs->e12223;
  res->e22223 = lhs->e22223 + rhs->e22223;
  res->e11133 = lhs->e11133 + rhs->e11133;
  res->e11233 = lhs->e11233 + rhs->e11233;
  res->e12233 = lhs->e12233 + rhs->e12233;
  res->e22233 = lhs->e22233 + rhs->e22233;
  res->e11333 = lhs->e11333 + rhs->e11333;
  res->e12333 = lhs->e12333 + rhs->e12333;
  res->e22333 = lhs->e22333 + rhs->e22333;
  res->e13333 = lhs->e13333 + rhs->e13333;
  res->e23333 = lhs->e23333 + rhs->e23333;
  res->e33333 = lhs->e33333 + rhs->e33333;

}

onumm3n5_t onumm3n5_sum_ro(  coeff_t lhs,  onumm3n5_t* rhs){
  onumm3n5_t res;

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
  // Order 5;
  res.e11111 =  + rhs->e11111;
  res.e11112 =  + rhs->e11112;
  res.e11122 =  + rhs->e11122;
  res.e11222 =  + rhs->e11222;
  res.e12222 =  + rhs->e12222;
  res.e22222 =  + rhs->e22222;
  res.e11113 =  + rhs->e11113;
  res.e11123 =  + rhs->e11123;
  res.e11223 =  + rhs->e11223;
  res.e12223 =  + rhs->e12223;
  res.e22223 =  + rhs->e22223;
  res.e11133 =  + rhs->e11133;
  res.e11233 =  + rhs->e11233;
  res.e12233 =  + rhs->e12233;
  res.e22233 =  + rhs->e22233;
  res.e11333 =  + rhs->e11333;
  res.e12333 =  + rhs->e12333;
  res.e22333 =  + rhs->e22333;
  res.e13333 =  + rhs->e13333;
  res.e23333 =  + rhs->e23333;
  res.e33333 =  + rhs->e33333;

  return res;

}

void onumm3n5_sum_ro_to(  coeff_t lhs,  onumm3n5_t* rhs, onumm3n5_t* res){
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
  // Order 5;
  res->e11111 =  + rhs->e11111;
  res->e11112 =  + rhs->e11112;
  res->e11122 =  + rhs->e11122;
  res->e11222 =  + rhs->e11222;
  res->e12222 =  + rhs->e12222;
  res->e22222 =  + rhs->e22222;
  res->e11113 =  + rhs->e11113;
  res->e11123 =  + rhs->e11123;
  res->e11223 =  + rhs->e11223;
  res->e12223 =  + rhs->e12223;
  res->e22223 =  + rhs->e22223;
  res->e11133 =  + rhs->e11133;
  res->e11233 =  + rhs->e11233;
  res->e12233 =  + rhs->e12233;
  res->e22233 =  + rhs->e22233;
  res->e11333 =  + rhs->e11333;
  res->e12333 =  + rhs->e12333;
  res->e22333 =  + rhs->e22333;
  res->e13333 =  + rhs->e13333;
  res->e23333 =  + rhs->e23333;
  res->e33333 =  + rhs->e33333;

}

onumm3n5_t onumm3n5_sub_oo(  onumm3n5_t* lhs,  onumm3n5_t* rhs){
  onumm3n5_t res;

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
  // Order 5
  res.e11111 = lhs->e11111 - rhs->e11111;
  res.e11112 = lhs->e11112 - rhs->e11112;
  res.e11122 = lhs->e11122 - rhs->e11122;
  res.e11222 = lhs->e11222 - rhs->e11222;
  res.e12222 = lhs->e12222 - rhs->e12222;
  res.e22222 = lhs->e22222 - rhs->e22222;
  res.e11113 = lhs->e11113 - rhs->e11113;
  res.e11123 = lhs->e11123 - rhs->e11123;
  res.e11223 = lhs->e11223 - rhs->e11223;
  res.e12223 = lhs->e12223 - rhs->e12223;
  res.e22223 = lhs->e22223 - rhs->e22223;
  res.e11133 = lhs->e11133 - rhs->e11133;
  res.e11233 = lhs->e11233 - rhs->e11233;
  res.e12233 = lhs->e12233 - rhs->e12233;
  res.e22233 = lhs->e22233 - rhs->e22233;
  res.e11333 = lhs->e11333 - rhs->e11333;
  res.e12333 = lhs->e12333 - rhs->e12333;
  res.e22333 = lhs->e22333 - rhs->e22333;
  res.e13333 = lhs->e13333 - rhs->e13333;
  res.e23333 = lhs->e23333 - rhs->e23333;
  res.e33333 = lhs->e33333 - rhs->e33333;

  return res;

}

void onumm3n5_sub_oo_to(  onumm3n5_t* lhs,  onumm3n5_t* rhs, onumm3n5_t* res){
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
  // Order 5
  res->e11111 = lhs->e11111 - rhs->e11111;
  res->e11112 = lhs->e11112 - rhs->e11112;
  res->e11122 = lhs->e11122 - rhs->e11122;
  res->e11222 = lhs->e11222 - rhs->e11222;
  res->e12222 = lhs->e12222 - rhs->e12222;
  res->e22222 = lhs->e22222 - rhs->e22222;
  res->e11113 = lhs->e11113 - rhs->e11113;
  res->e11123 = lhs->e11123 - rhs->e11123;
  res->e11223 = lhs->e11223 - rhs->e11223;
  res->e12223 = lhs->e12223 - rhs->e12223;
  res->e22223 = lhs->e22223 - rhs->e22223;
  res->e11133 = lhs->e11133 - rhs->e11133;
  res->e11233 = lhs->e11233 - rhs->e11233;
  res->e12233 = lhs->e12233 - rhs->e12233;
  res->e22233 = lhs->e22233 - rhs->e22233;
  res->e11333 = lhs->e11333 - rhs->e11333;
  res->e12333 = lhs->e12333 - rhs->e12333;
  res->e22333 = lhs->e22333 - rhs->e22333;
  res->e13333 = lhs->e13333 - rhs->e13333;
  res->e23333 = lhs->e23333 - rhs->e23333;
  res->e33333 = lhs->e33333 - rhs->e33333;

}

onumm3n5_t onumm3n5_sub_ro(  coeff_t lhs,  onumm3n5_t* rhs){
  onumm3n5_t res;

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
  // Order 5;
  res.e11111 =  - rhs->e11111;
  res.e11112 =  - rhs->e11112;
  res.e11122 =  - rhs->e11122;
  res.e11222 =  - rhs->e11222;
  res.e12222 =  - rhs->e12222;
  res.e22222 =  - rhs->e22222;
  res.e11113 =  - rhs->e11113;
  res.e11123 =  - rhs->e11123;
  res.e11223 =  - rhs->e11223;
  res.e12223 =  - rhs->e12223;
  res.e22223 =  - rhs->e22223;
  res.e11133 =  - rhs->e11133;
  res.e11233 =  - rhs->e11233;
  res.e12233 =  - rhs->e12233;
  res.e22233 =  - rhs->e22233;
  res.e11333 =  - rhs->e11333;
  res.e12333 =  - rhs->e12333;
  res.e22333 =  - rhs->e22333;
  res.e13333 =  - rhs->e13333;
  res.e23333 =  - rhs->e23333;
  res.e33333 =  - rhs->e33333;

  return res;

}

void onumm3n5_sub_ro_to(  coeff_t lhs,  onumm3n5_t* rhs, onumm3n5_t* res){
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
  // Order 5;
  res->e11111 =  - rhs->e11111;
  res->e11112 =  - rhs->e11112;
  res->e11122 =  - rhs->e11122;
  res->e11222 =  - rhs->e11222;
  res->e12222 =  - rhs->e12222;
  res->e22222 =  - rhs->e22222;
  res->e11113 =  - rhs->e11113;
  res->e11123 =  - rhs->e11123;
  res->e11223 =  - rhs->e11223;
  res->e12223 =  - rhs->e12223;
  res->e22223 =  - rhs->e22223;
  res->e11133 =  - rhs->e11133;
  res->e11233 =  - rhs->e11233;
  res->e12233 =  - rhs->e12233;
  res->e22233 =  - rhs->e22233;
  res->e11333 =  - rhs->e11333;
  res->e12333 =  - rhs->e12333;
  res->e22333 =  - rhs->e22333;
  res->e13333 =  - rhs->e13333;
  res->e23333 =  - rhs->e23333;
  res->e33333 =  - rhs->e33333;

}

onumm3n5_t onumm3n5_sub_or(  onumm3n5_t* lhs,  coeff_t rhs){
  onumm3n5_t res;

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
  // Order 5;
  res.e11111 = lhs->e11111;
  res.e11112 = lhs->e11112;
  res.e11122 = lhs->e11122;
  res.e11222 = lhs->e11222;
  res.e12222 = lhs->e12222;
  res.e22222 = lhs->e22222;
  res.e11113 = lhs->e11113;
  res.e11123 = lhs->e11123;
  res.e11223 = lhs->e11223;
  res.e12223 = lhs->e12223;
  res.e22223 = lhs->e22223;
  res.e11133 = lhs->e11133;
  res.e11233 = lhs->e11233;
  res.e12233 = lhs->e12233;
  res.e22233 = lhs->e22233;
  res.e11333 = lhs->e11333;
  res.e12333 = lhs->e12333;
  res.e22333 = lhs->e22333;
  res.e13333 = lhs->e13333;
  res.e23333 = lhs->e23333;
  res.e33333 = lhs->e33333;

  return res;

}

void onumm3n5_sub_or_to(  onumm3n5_t* lhs,  coeff_t rhs, onumm3n5_t* res){
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
  // Order 5;
  res->e11111 = lhs->e11111;
  res->e11112 = lhs->e11112;
  res->e11122 = lhs->e11122;
  res->e11222 = lhs->e11222;
  res->e12222 = lhs->e12222;
  res->e22222 = lhs->e22222;
  res->e11113 = lhs->e11113;
  res->e11123 = lhs->e11123;
  res->e11223 = lhs->e11223;
  res->e12223 = lhs->e12223;
  res->e22223 = lhs->e22223;
  res->e11133 = lhs->e11133;
  res->e11233 = lhs->e11233;
  res->e12233 = lhs->e12233;
  res->e22233 = lhs->e22233;
  res->e11333 = lhs->e11333;
  res->e12333 = lhs->e12333;
  res->e22333 = lhs->e22333;
  res->e13333 = lhs->e13333;
  res->e23333 = lhs->e23333;
  res->e33333 = lhs->e33333;

}

onumm3n5_t onumm3n5_mul_oo(  onumm3n5_t* lhs,  onumm3n5_t* rhs){
  onumm3n5_t res;

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
  res.e11113 = lhs->r * rhs->e11113 + lhs->e11113 * rhs->r + lhs->e1 * rhs->e1113 
             + lhs->e1113 * rhs->e1 + lhs->e3 * rhs->e1111 + lhs->e1111 * rhs->e3 
             + lhs->e11 * rhs->e113 + lhs->e113 * rhs->e11 + lhs->e13 * rhs->e111 
             + lhs->e111 * rhs->e13;
  res.e11123 = lhs->r * rhs->e11123 + lhs->e11123 * rhs->r + lhs->e1 * rhs->e1123 
             + lhs->e1123 * rhs->e1 + lhs->e2 * rhs->e1113 + lhs->e1113 * rhs->e2 
             + lhs->e3 * rhs->e1112 + lhs->e1112 * rhs->e3 + lhs->e11 * rhs->e123 
             + lhs->e123 * rhs->e11 + lhs->e12 * rhs->e113 + lhs->e113 * rhs->e12 
             + lhs->e13 * rhs->e112 + lhs->e112 * rhs->e13 + lhs->e23 * rhs->e111 
             + lhs->e111 * rhs->e23;
  res.e11223 = lhs->r * rhs->e11223 + lhs->e11223 * rhs->r + lhs->e1 * rhs->e1223 
             + lhs->e1223 * rhs->e1 + lhs->e2 * rhs->e1123 + lhs->e1123 * rhs->e2 
             + lhs->e3 * rhs->e1122 + lhs->e1122 * rhs->e3 + lhs->e11 * rhs->e223 
             + lhs->e223 * rhs->e11 + lhs->e12 * rhs->e123 + lhs->e123 * rhs->e12 
             + lhs->e22 * rhs->e113 + lhs->e113 * rhs->e22 + lhs->e13 * rhs->e122 
             + lhs->e122 * rhs->e13 + lhs->e23 * rhs->e112 + lhs->e112 * rhs->e23;
  res.e12223 = lhs->r * rhs->e12223 + lhs->e12223 * rhs->r + lhs->e1 * rhs->e2223 
             + lhs->e2223 * rhs->e1 + lhs->e2 * rhs->e1223 + lhs->e1223 * rhs->e2 
             + lhs->e3 * rhs->e1222 + lhs->e1222 * rhs->e3 + lhs->e12 * rhs->e223 
             + lhs->e223 * rhs->e12 + lhs->e22 * rhs->e123 + lhs->e123 * rhs->e22 
             + lhs->e13 * rhs->e222 + lhs->e222 * rhs->e13 + lhs->e23 * rhs->e122 
             + lhs->e122 * rhs->e23;
  res.e22223 = lhs->r * rhs->e22223 + lhs->e22223 * rhs->r + lhs->e2 * rhs->e2223 
             + lhs->e2223 * rhs->e2 + lhs->e3 * rhs->e2222 + lhs->e2222 * rhs->e3 
             + lhs->e22 * rhs->e223 + lhs->e223 * rhs->e22 + lhs->e23 * rhs->e222 
             + lhs->e222 * rhs->e23;
  res.e11133 = lhs->r * rhs->e11133 + lhs->e11133 * rhs->r + lhs->e1 * rhs->e1133 
             + lhs->e1133 * rhs->e1 + lhs->e3 * rhs->e1113 + lhs->e1113 * rhs->e3 
             + lhs->e11 * rhs->e133 + lhs->e133 * rhs->e11 + lhs->e13 * rhs->e113 
             + lhs->e113 * rhs->e13 + lhs->e33 * rhs->e111 + lhs->e111 * rhs->e33;
  res.e11233 = lhs->r * rhs->e11233 + lhs->e11233 * rhs->r + lhs->e1 * rhs->e1233 
             + lhs->e1233 * rhs->e1 + lhs->e2 * rhs->e1133 + lhs->e1133 * rhs->e2 
             + lhs->e3 * rhs->e1123 + lhs->e1123 * rhs->e3 + lhs->e11 * rhs->e233 
             + lhs->e233 * rhs->e11 + lhs->e12 * rhs->e133 + lhs->e133 * rhs->e12 
             + lhs->e13 * rhs->e123 + lhs->e123 * rhs->e13 + lhs->e23 * rhs->e113 
             + lhs->e113 * rhs->e23 + lhs->e33 * rhs->e112 + lhs->e112 * rhs->e33;
  res.e12233 = lhs->r * rhs->e12233 + lhs->e12233 * rhs->r + lhs->e1 * rhs->e2233 
             + lhs->e2233 * rhs->e1 + lhs->e2 * rhs->e1233 + lhs->e1233 * rhs->e2 
             + lhs->e3 * rhs->e1223 + lhs->e1223 * rhs->e3 + lhs->e12 * rhs->e233 
             + lhs->e233 * rhs->e12 + lhs->e22 * rhs->e133 + lhs->e133 * rhs->e22 
             + lhs->e13 * rhs->e223 + lhs->e223 * rhs->e13 + lhs->e23 * rhs->e123 
             + lhs->e123 * rhs->e23 + lhs->e33 * rhs->e122 + lhs->e122 * rhs->e33;
  res.e22233 = lhs->r * rhs->e22233 + lhs->e22233 * rhs->r + lhs->e2 * rhs->e2233 
             + lhs->e2233 * rhs->e2 + lhs->e3 * rhs->e2223 + lhs->e2223 * rhs->e3 
             + lhs->e22 * rhs->e233 + lhs->e233 * rhs->e22 + lhs->e23 * rhs->e223 
             + lhs->e223 * rhs->e23 + lhs->e33 * rhs->e222 + lhs->e222 * rhs->e33;
  res.e11333 = lhs->r * rhs->e11333 + lhs->e11333 * rhs->r + lhs->e1 * rhs->e1333 
             + lhs->e1333 * rhs->e1 + lhs->e3 * rhs->e1133 + lhs->e1133 * rhs->e3 
             + lhs->e11 * rhs->e333 + lhs->e333 * rhs->e11 + lhs->e13 * rhs->e133 
             + lhs->e133 * rhs->e13 + lhs->e33 * rhs->e113 + lhs->e113 * rhs->e33;
  res.e12333 = lhs->r * rhs->e12333 + lhs->e12333 * rhs->r + lhs->e1 * rhs->e2333 
             + lhs->e2333 * rhs->e1 + lhs->e2 * rhs->e1333 + lhs->e1333 * rhs->e2 
             + lhs->e3 * rhs->e1233 + lhs->e1233 * rhs->e3 + lhs->e12 * rhs->e333 
             + lhs->e333 * rhs->e12 + lhs->e13 * rhs->e233 + lhs->e233 * rhs->e13 
             + lhs->e23 * rhs->e133 + lhs->e133 * rhs->e23 + lhs->e33 * rhs->e123 
             + lhs->e123 * rhs->e33;
  res.e22333 = lhs->r * rhs->e22333 + lhs->e22333 * rhs->r + lhs->e2 * rhs->e2333 
             + lhs->e2333 * rhs->e2 + lhs->e3 * rhs->e2233 + lhs->e2233 * rhs->e3 
             + lhs->e22 * rhs->e333 + lhs->e333 * rhs->e22 + lhs->e23 * rhs->e233 
             + lhs->e233 * rhs->e23 + lhs->e33 * rhs->e223 + lhs->e223 * rhs->e33;
  res.e13333 = lhs->r * rhs->e13333 + lhs->e13333 * rhs->r + lhs->e1 * rhs->e3333 
             + lhs->e3333 * rhs->e1 + lhs->e3 * rhs->e1333 + lhs->e1333 * rhs->e3 
             + lhs->e13 * rhs->e333 + lhs->e333 * rhs->e13 + lhs->e33 * rhs->e133 
             + lhs->e133 * rhs->e33;
  res.e23333 = lhs->r * rhs->e23333 + lhs->e23333 * rhs->r + lhs->e2 * rhs->e3333 
             + lhs->e3333 * rhs->e2 + lhs->e3 * rhs->e2333 + lhs->e2333 * rhs->e3 
             + lhs->e23 * rhs->e333 + lhs->e333 * rhs->e23 + lhs->e33 * rhs->e233 
             + lhs->e233 * rhs->e33;
  res.e33333 = lhs->r * rhs->e33333 + lhs->e33333 * rhs->r + lhs->e3 * rhs->e3333 
             + lhs->e3333 * rhs->e3 + lhs->e33 * rhs->e333 + lhs->e333 * rhs->e33;

  return res;

}

void onumm3n5_mul_oo_to(  onumm3n5_t* lhs,  onumm3n5_t* rhs, onumm3n5_t* res){
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
  res->e11113 = lhs->r * rhs->e11113 + lhs->e11113 * rhs->r + lhs->e1 * rhs->e1113 
             + lhs->e1113 * rhs->e1 + lhs->e3 * rhs->e1111 + lhs->e1111 * rhs->e3 
             + lhs->e11 * rhs->e113 + lhs->e113 * rhs->e11 + lhs->e13 * rhs->e111 
             + lhs->e111 * rhs->e13;
  res->e11123 = lhs->r * rhs->e11123 + lhs->e11123 * rhs->r + lhs->e1 * rhs->e1123 
             + lhs->e1123 * rhs->e1 + lhs->e2 * rhs->e1113 + lhs->e1113 * rhs->e2 
             + lhs->e3 * rhs->e1112 + lhs->e1112 * rhs->e3 + lhs->e11 * rhs->e123 
             + lhs->e123 * rhs->e11 + lhs->e12 * rhs->e113 + lhs->e113 * rhs->e12 
             + lhs->e13 * rhs->e112 + lhs->e112 * rhs->e13 + lhs->e23 * rhs->e111 
             + lhs->e111 * rhs->e23;
  res->e11223 = lhs->r * rhs->e11223 + lhs->e11223 * rhs->r + lhs->e1 * rhs->e1223 
             + lhs->e1223 * rhs->e1 + lhs->e2 * rhs->e1123 + lhs->e1123 * rhs->e2 
             + lhs->e3 * rhs->e1122 + lhs->e1122 * rhs->e3 + lhs->e11 * rhs->e223 
             + lhs->e223 * rhs->e11 + lhs->e12 * rhs->e123 + lhs->e123 * rhs->e12 
             + lhs->e22 * rhs->e113 + lhs->e113 * rhs->e22 + lhs->e13 * rhs->e122 
             + lhs->e122 * rhs->e13 + lhs->e23 * rhs->e112 + lhs->e112 * rhs->e23;
  res->e12223 = lhs->r * rhs->e12223 + lhs->e12223 * rhs->r + lhs->e1 * rhs->e2223 
             + lhs->e2223 * rhs->e1 + lhs->e2 * rhs->e1223 + lhs->e1223 * rhs->e2 
             + lhs->e3 * rhs->e1222 + lhs->e1222 * rhs->e3 + lhs->e12 * rhs->e223 
             + lhs->e223 * rhs->e12 + lhs->e22 * rhs->e123 + lhs->e123 * rhs->e22 
             + lhs->e13 * rhs->e222 + lhs->e222 * rhs->e13 + lhs->e23 * rhs->e122 
             + lhs->e122 * rhs->e23;
  res->e22223 = lhs->r * rhs->e22223 + lhs->e22223 * rhs->r + lhs->e2 * rhs->e2223 
             + lhs->e2223 * rhs->e2 + lhs->e3 * rhs->e2222 + lhs->e2222 * rhs->e3 
             + lhs->e22 * rhs->e223 + lhs->e223 * rhs->e22 + lhs->e23 * rhs->e222 
             + lhs->e222 * rhs->e23;
  res->e11133 = lhs->r * rhs->e11133 + lhs->e11133 * rhs->r + lhs->e1 * rhs->e1133 
             + lhs->e1133 * rhs->e1 + lhs->e3 * rhs->e1113 + lhs->e1113 * rhs->e3 
             + lhs->e11 * rhs->e133 + lhs->e133 * rhs->e11 + lhs->e13 * rhs->e113 
             + lhs->e113 * rhs->e13 + lhs->e33 * rhs->e111 + lhs->e111 * rhs->e33;
  res->e11233 = lhs->r * rhs->e11233 + lhs->e11233 * rhs->r + lhs->e1 * rhs->e1233 
             + lhs->e1233 * rhs->e1 + lhs->e2 * rhs->e1133 + lhs->e1133 * rhs->e2 
             + lhs->e3 * rhs->e1123 + lhs->e1123 * rhs->e3 + lhs->e11 * rhs->e233 
             + lhs->e233 * rhs->e11 + lhs->e12 * rhs->e133 + lhs->e133 * rhs->e12 
             + lhs->e13 * rhs->e123 + lhs->e123 * rhs->e13 + lhs->e23 * rhs->e113 
             + lhs->e113 * rhs->e23 + lhs->e33 * rhs->e112 + lhs->e112 * rhs->e33;
  res->e12233 = lhs->r * rhs->e12233 + lhs->e12233 * rhs->r + lhs->e1 * rhs->e2233 
             + lhs->e2233 * rhs->e1 + lhs->e2 * rhs->e1233 + lhs->e1233 * rhs->e2 
             + lhs->e3 * rhs->e1223 + lhs->e1223 * rhs->e3 + lhs->e12 * rhs->e233 
             + lhs->e233 * rhs->e12 + lhs->e22 * rhs->e133 + lhs->e133 * rhs->e22 
             + lhs->e13 * rhs->e223 + lhs->e223 * rhs->e13 + lhs->e23 * rhs->e123 
             + lhs->e123 * rhs->e23 + lhs->e33 * rhs->e122 + lhs->e122 * rhs->e33;
  res->e22233 = lhs->r * rhs->e22233 + lhs->e22233 * rhs->r + lhs->e2 * rhs->e2233 
             + lhs->e2233 * rhs->e2 + lhs->e3 * rhs->e2223 + lhs->e2223 * rhs->e3 
             + lhs->e22 * rhs->e233 + lhs->e233 * rhs->e22 + lhs->e23 * rhs->e223 
             + lhs->e223 * rhs->e23 + lhs->e33 * rhs->e222 + lhs->e222 * rhs->e33;
  res->e11333 = lhs->r * rhs->e11333 + lhs->e11333 * rhs->r + lhs->e1 * rhs->e1333 
             + lhs->e1333 * rhs->e1 + lhs->e3 * rhs->e1133 + lhs->e1133 * rhs->e3 
             + lhs->e11 * rhs->e333 + lhs->e333 * rhs->e11 + lhs->e13 * rhs->e133 
             + lhs->e133 * rhs->e13 + lhs->e33 * rhs->e113 + lhs->e113 * rhs->e33;
  res->e12333 = lhs->r * rhs->e12333 + lhs->e12333 * rhs->r + lhs->e1 * rhs->e2333 
             + lhs->e2333 * rhs->e1 + lhs->e2 * rhs->e1333 + lhs->e1333 * rhs->e2 
             + lhs->e3 * rhs->e1233 + lhs->e1233 * rhs->e3 + lhs->e12 * rhs->e333 
             + lhs->e333 * rhs->e12 + lhs->e13 * rhs->e233 + lhs->e233 * rhs->e13 
             + lhs->e23 * rhs->e133 + lhs->e133 * rhs->e23 + lhs->e33 * rhs->e123 
             + lhs->e123 * rhs->e33;
  res->e22333 = lhs->r * rhs->e22333 + lhs->e22333 * rhs->r + lhs->e2 * rhs->e2333 
             + lhs->e2333 * rhs->e2 + lhs->e3 * rhs->e2233 + lhs->e2233 * rhs->e3 
             + lhs->e22 * rhs->e333 + lhs->e333 * rhs->e22 + lhs->e23 * rhs->e233 
             + lhs->e233 * rhs->e23 + lhs->e33 * rhs->e223 + lhs->e223 * rhs->e33;
  res->e13333 = lhs->r * rhs->e13333 + lhs->e13333 * rhs->r + lhs->e1 * rhs->e3333 
             + lhs->e3333 * rhs->e1 + lhs->e3 * rhs->e1333 + lhs->e1333 * rhs->e3 
             + lhs->e13 * rhs->e333 + lhs->e333 * rhs->e13 + lhs->e33 * rhs->e133 
             + lhs->e133 * rhs->e33;
  res->e23333 = lhs->r * rhs->e23333 + lhs->e23333 * rhs->r + lhs->e2 * rhs->e3333 
             + lhs->e3333 * rhs->e2 + lhs->e3 * rhs->e2333 + lhs->e2333 * rhs->e3 
             + lhs->e23 * rhs->e333 + lhs->e333 * rhs->e23 + lhs->e33 * rhs->e233 
             + lhs->e233 * rhs->e33;
  res->e33333 = lhs->r * rhs->e33333 + lhs->e33333 * rhs->r + lhs->e3 * rhs->e3333 
             + lhs->e3333 * rhs->e3 + lhs->e33 * rhs->e333 + lhs->e333 * rhs->e33;

}

onumm3n5_t onumm3n5_mul_ro(  coeff_t lhs,  onumm3n5_t* rhs){
  onumm3n5_t res;

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
  // Order 5;
  res.e11111 = lhs * rhs->e11111;
  res.e11112 = lhs * rhs->e11112;
  res.e11122 = lhs * rhs->e11122;
  res.e11222 = lhs * rhs->e11222;
  res.e12222 = lhs * rhs->e12222;
  res.e22222 = lhs * rhs->e22222;
  res.e11113 = lhs * rhs->e11113;
  res.e11123 = lhs * rhs->e11123;
  res.e11223 = lhs * rhs->e11223;
  res.e12223 = lhs * rhs->e12223;
  res.e22223 = lhs * rhs->e22223;
  res.e11133 = lhs * rhs->e11133;
  res.e11233 = lhs * rhs->e11233;
  res.e12233 = lhs * rhs->e12233;
  res.e22233 = lhs * rhs->e22233;
  res.e11333 = lhs * rhs->e11333;
  res.e12333 = lhs * rhs->e12333;
  res.e22333 = lhs * rhs->e22333;
  res.e13333 = lhs * rhs->e13333;
  res.e23333 = lhs * rhs->e23333;
  res.e33333 = lhs * rhs->e33333;

  return res;

}

void onumm3n5_mul_ro_to(  coeff_t lhs,  onumm3n5_t* rhs, onumm3n5_t* res){
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
  // Order 5;
  res->e11111 = lhs * rhs->e11111;
  res->e11112 = lhs * rhs->e11112;
  res->e11122 = lhs * rhs->e11122;
  res->e11222 = lhs * rhs->e11222;
  res->e12222 = lhs * rhs->e12222;
  res->e22222 = lhs * rhs->e22222;
  res->e11113 = lhs * rhs->e11113;
  res->e11123 = lhs * rhs->e11123;
  res->e11223 = lhs * rhs->e11223;
  res->e12223 = lhs * rhs->e12223;
  res->e22223 = lhs * rhs->e22223;
  res->e11133 = lhs * rhs->e11133;
  res->e11233 = lhs * rhs->e11233;
  res->e12233 = lhs * rhs->e12233;
  res->e22233 = lhs * rhs->e22233;
  res->e11333 = lhs * rhs->e11333;
  res->e12333 = lhs * rhs->e12333;
  res->e22333 = lhs * rhs->e22333;
  res->e13333 = lhs * rhs->e13333;
  res->e23333 = lhs * rhs->e23333;
  res->e33333 = lhs * rhs->e33333;

}

onumm3n5_t onumm3n5_trunc_mul_oo(  onumm3n5_t* lhs,  onumm3n5_t* rhs){
  onumm3n5_t res;

  res = onumm3n5_init();

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
  res.e11113 =  + lhs->e1 * rhs->e1113 + lhs->e1113 * rhs->e1 + lhs->e3 * rhs->e1111 
             + lhs->e1111 * rhs->e3 + lhs->e11 * rhs->e113 + lhs->e113 * rhs->e11 
             + lhs->e13 * rhs->e111 + lhs->e111 * rhs->e13;
  res.e11123 =  + lhs->e1 * rhs->e1123 + lhs->e1123 * rhs->e1 + lhs->e2 * rhs->e1113 
             + lhs->e1113 * rhs->e2 + lhs->e3 * rhs->e1112 + lhs->e1112 * rhs->e3 
             + lhs->e11 * rhs->e123 + lhs->e123 * rhs->e11 + lhs->e12 * rhs->e113 
             + lhs->e113 * rhs->e12 + lhs->e13 * rhs->e112 + lhs->e112 * rhs->e13 
             + lhs->e23 * rhs->e111 + lhs->e111 * rhs->e23;
  res.e11223 =  + lhs->e1 * rhs->e1223 + lhs->e1223 * rhs->e1 + lhs->e2 * rhs->e1123 
             + lhs->e1123 * rhs->e2 + lhs->e3 * rhs->e1122 + lhs->e1122 * rhs->e3 
             + lhs->e11 * rhs->e223 + lhs->e223 * rhs->e11 + lhs->e12 * rhs->e123 
             + lhs->e123 * rhs->e12 + lhs->e22 * rhs->e113 + lhs->e113 * rhs->e22 
             + lhs->e13 * rhs->e122 + lhs->e122 * rhs->e13 + lhs->e23 * rhs->e112 
             + lhs->e112 * rhs->e23;
  res.e12223 =  + lhs->e1 * rhs->e2223 + lhs->e2223 * rhs->e1 + lhs->e2 * rhs->e1223 
             + lhs->e1223 * rhs->e2 + lhs->e3 * rhs->e1222 + lhs->e1222 * rhs->e3 
             + lhs->e12 * rhs->e223 + lhs->e223 * rhs->e12 + lhs->e22 * rhs->e123 
             + lhs->e123 * rhs->e22 + lhs->e13 * rhs->e222 + lhs->e222 * rhs->e13 
             + lhs->e23 * rhs->e122 + lhs->e122 * rhs->e23;
  res.e22223 =  + lhs->e2 * rhs->e2223 + lhs->e2223 * rhs->e2 + lhs->e3 * rhs->e2222 
             + lhs->e2222 * rhs->e3 + lhs->e22 * rhs->e223 + lhs->e223 * rhs->e22 
             + lhs->e23 * rhs->e222 + lhs->e222 * rhs->e23;
  res.e11133 =  + lhs->e1 * rhs->e1133 + lhs->e1133 * rhs->e1 + lhs->e3 * rhs->e1113 
             + lhs->e1113 * rhs->e3 + lhs->e11 * rhs->e133 + lhs->e133 * rhs->e11 
             + lhs->e13 * rhs->e113 + lhs->e113 * rhs->e13 + lhs->e33 * rhs->e111 
             + lhs->e111 * rhs->e33;
  res.e11233 =  + lhs->e1 * rhs->e1233 + lhs->e1233 * rhs->e1 + lhs->e2 * rhs->e1133 
             + lhs->e1133 * rhs->e2 + lhs->e3 * rhs->e1123 + lhs->e1123 * rhs->e3 
             + lhs->e11 * rhs->e233 + lhs->e233 * rhs->e11 + lhs->e12 * rhs->e133 
             + lhs->e133 * rhs->e12 + lhs->e13 * rhs->e123 + lhs->e123 * rhs->e13 
             + lhs->e23 * rhs->e113 + lhs->e113 * rhs->e23 + lhs->e33 * rhs->e112 
             + lhs->e112 * rhs->e33;
  res.e12233 =  + lhs->e1 * rhs->e2233 + lhs->e2233 * rhs->e1 + lhs->e2 * rhs->e1233 
             + lhs->e1233 * rhs->e2 + lhs->e3 * rhs->e1223 + lhs->e1223 * rhs->e3 
             + lhs->e12 * rhs->e233 + lhs->e233 * rhs->e12 + lhs->e22 * rhs->e133 
             + lhs->e133 * rhs->e22 + lhs->e13 * rhs->e223 + lhs->e223 * rhs->e13 
             + lhs->e23 * rhs->e123 + lhs->e123 * rhs->e23 + lhs->e33 * rhs->e122 
             + lhs->e122 * rhs->e33;
  res.e22233 =  + lhs->e2 * rhs->e2233 + lhs->e2233 * rhs->e2 + lhs->e3 * rhs->e2223 
             + lhs->e2223 * rhs->e3 + lhs->e22 * rhs->e233 + lhs->e233 * rhs->e22 
             + lhs->e23 * rhs->e223 + lhs->e223 * rhs->e23 + lhs->e33 * rhs->e222 
             + lhs->e222 * rhs->e33;
  res.e11333 =  + lhs->e1 * rhs->e1333 + lhs->e1333 * rhs->e1 + lhs->e3 * rhs->e1133 
             + lhs->e1133 * rhs->e3 + lhs->e11 * rhs->e333 + lhs->e333 * rhs->e11 
             + lhs->e13 * rhs->e133 + lhs->e133 * rhs->e13 + lhs->e33 * rhs->e113 
             + lhs->e113 * rhs->e33;
  res.e12333 =  + lhs->e1 * rhs->e2333 + lhs->e2333 * rhs->e1 + lhs->e2 * rhs->e1333 
             + lhs->e1333 * rhs->e2 + lhs->e3 * rhs->e1233 + lhs->e1233 * rhs->e3 
             + lhs->e12 * rhs->e333 + lhs->e333 * rhs->e12 + lhs->e13 * rhs->e233 
             + lhs->e233 * rhs->e13 + lhs->e23 * rhs->e133 + lhs->e133 * rhs->e23 
             + lhs->e33 * rhs->e123 + lhs->e123 * rhs->e33;
  res.e22333 =  + lhs->e2 * rhs->e2333 + lhs->e2333 * rhs->e2 + lhs->e3 * rhs->e2233 
             + lhs->e2233 * rhs->e3 + lhs->e22 * rhs->e333 + lhs->e333 * rhs->e22 
             + lhs->e23 * rhs->e233 + lhs->e233 * rhs->e23 + lhs->e33 * rhs->e223 
             + lhs->e223 * rhs->e33;
  res.e13333 =  + lhs->e1 * rhs->e3333 + lhs->e3333 * rhs->e1 + lhs->e3 * rhs->e1333 
             + lhs->e1333 * rhs->e3 + lhs->e13 * rhs->e333 + lhs->e333 * rhs->e13 
             + lhs->e33 * rhs->e133 + lhs->e133 * rhs->e33;
  res.e23333 =  + lhs->e2 * rhs->e3333 + lhs->e3333 * rhs->e2 + lhs->e3 * rhs->e2333 
             + lhs->e2333 * rhs->e3 + lhs->e23 * rhs->e333 + lhs->e333 * rhs->e23 
             + lhs->e33 * rhs->e233 + lhs->e233 * rhs->e33;
  res.e33333 =  + lhs->e3 * rhs->e3333 + lhs->e3333 * rhs->e3 + lhs->e33 * rhs->e333 
             + lhs->e333 * rhs->e33;

  return res;

}

void onumm3n5_trunc_mul_oo_to(  onumm3n5_t* lhs,  onumm3n5_t* rhs, onumm3n5_t* res){
   (*res) = onumm3n5_init();

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
  res->e11113 =  + lhs->e1 * rhs->e1113 + lhs->e1113 * rhs->e1 + lhs->e3 * rhs->e1111 
             + lhs->e1111 * rhs->e3 + lhs->e11 * rhs->e113 + lhs->e113 * rhs->e11 
             + lhs->e13 * rhs->e111 + lhs->e111 * rhs->e13;
  res->e11123 =  + lhs->e1 * rhs->e1123 + lhs->e1123 * rhs->e1 + lhs->e2 * rhs->e1113 
             + lhs->e1113 * rhs->e2 + lhs->e3 * rhs->e1112 + lhs->e1112 * rhs->e3 
             + lhs->e11 * rhs->e123 + lhs->e123 * rhs->e11 + lhs->e12 * rhs->e113 
             + lhs->e113 * rhs->e12 + lhs->e13 * rhs->e112 + lhs->e112 * rhs->e13 
             + lhs->e23 * rhs->e111 + lhs->e111 * rhs->e23;
  res->e11223 =  + lhs->e1 * rhs->e1223 + lhs->e1223 * rhs->e1 + lhs->e2 * rhs->e1123 
             + lhs->e1123 * rhs->e2 + lhs->e3 * rhs->e1122 + lhs->e1122 * rhs->e3 
             + lhs->e11 * rhs->e223 + lhs->e223 * rhs->e11 + lhs->e12 * rhs->e123 
             + lhs->e123 * rhs->e12 + lhs->e22 * rhs->e113 + lhs->e113 * rhs->e22 
             + lhs->e13 * rhs->e122 + lhs->e122 * rhs->e13 + lhs->e23 * rhs->e112 
             + lhs->e112 * rhs->e23;
  res->e12223 =  + lhs->e1 * rhs->e2223 + lhs->e2223 * rhs->e1 + lhs->e2 * rhs->e1223 
             + lhs->e1223 * rhs->e2 + lhs->e3 * rhs->e1222 + lhs->e1222 * rhs->e3 
             + lhs->e12 * rhs->e223 + lhs->e223 * rhs->e12 + lhs->e22 * rhs->e123 
             + lhs->e123 * rhs->e22 + lhs->e13 * rhs->e222 + lhs->e222 * rhs->e13 
             + lhs->e23 * rhs->e122 + lhs->e122 * rhs->e23;
  res->e22223 =  + lhs->e2 * rhs->e2223 + lhs->e2223 * rhs->e2 + lhs->e3 * rhs->e2222 
             + lhs->e2222 * rhs->e3 + lhs->e22 * rhs->e223 + lhs->e223 * rhs->e22 
             + lhs->e23 * rhs->e222 + lhs->e222 * rhs->e23;
  res->e11133 =  + lhs->e1 * rhs->e1133 + lhs->e1133 * rhs->e1 + lhs->e3 * rhs->e1113 
             + lhs->e1113 * rhs->e3 + lhs->e11 * rhs->e133 + lhs->e133 * rhs->e11 
             + lhs->e13 * rhs->e113 + lhs->e113 * rhs->e13 + lhs->e33 * rhs->e111 
             + lhs->e111 * rhs->e33;
  res->e11233 =  + lhs->e1 * rhs->e1233 + lhs->e1233 * rhs->e1 + lhs->e2 * rhs->e1133 
             + lhs->e1133 * rhs->e2 + lhs->e3 * rhs->e1123 + lhs->e1123 * rhs->e3 
             + lhs->e11 * rhs->e233 + lhs->e233 * rhs->e11 + lhs->e12 * rhs->e133 
             + lhs->e133 * rhs->e12 + lhs->e13 * rhs->e123 + lhs->e123 * rhs->e13 
             + lhs->e23 * rhs->e113 + lhs->e113 * rhs->e23 + lhs->e33 * rhs->e112 
             + lhs->e112 * rhs->e33;
  res->e12233 =  + lhs->e1 * rhs->e2233 + lhs->e2233 * rhs->e1 + lhs->e2 * rhs->e1233 
             + lhs->e1233 * rhs->e2 + lhs->e3 * rhs->e1223 + lhs->e1223 * rhs->e3 
             + lhs->e12 * rhs->e233 + lhs->e233 * rhs->e12 + lhs->e22 * rhs->e133 
             + lhs->e133 * rhs->e22 + lhs->e13 * rhs->e223 + lhs->e223 * rhs->e13 
             + lhs->e23 * rhs->e123 + lhs->e123 * rhs->e23 + lhs->e33 * rhs->e122 
             + lhs->e122 * rhs->e33;
  res->e22233 =  + lhs->e2 * rhs->e2233 + lhs->e2233 * rhs->e2 + lhs->e3 * rhs->e2223 
             + lhs->e2223 * rhs->e3 + lhs->e22 * rhs->e233 + lhs->e233 * rhs->e22 
             + lhs->e23 * rhs->e223 + lhs->e223 * rhs->e23 + lhs->e33 * rhs->e222 
             + lhs->e222 * rhs->e33;
  res->e11333 =  + lhs->e1 * rhs->e1333 + lhs->e1333 * rhs->e1 + lhs->e3 * rhs->e1133 
             + lhs->e1133 * rhs->e3 + lhs->e11 * rhs->e333 + lhs->e333 * rhs->e11 
             + lhs->e13 * rhs->e133 + lhs->e133 * rhs->e13 + lhs->e33 * rhs->e113 
             + lhs->e113 * rhs->e33;
  res->e12333 =  + lhs->e1 * rhs->e2333 + lhs->e2333 * rhs->e1 + lhs->e2 * rhs->e1333 
             + lhs->e1333 * rhs->e2 + lhs->e3 * rhs->e1233 + lhs->e1233 * rhs->e3 
             + lhs->e12 * rhs->e333 + lhs->e333 * rhs->e12 + lhs->e13 * rhs->e233 
             + lhs->e233 * rhs->e13 + lhs->e23 * rhs->e133 + lhs->e133 * rhs->e23 
             + lhs->e33 * rhs->e123 + lhs->e123 * rhs->e33;
  res->e22333 =  + lhs->e2 * rhs->e2333 + lhs->e2333 * rhs->e2 + lhs->e3 * rhs->e2233 
             + lhs->e2233 * rhs->e3 + lhs->e22 * rhs->e333 + lhs->e333 * rhs->e22 
             + lhs->e23 * rhs->e233 + lhs->e233 * rhs->e23 + lhs->e33 * rhs->e223 
             + lhs->e223 * rhs->e33;
  res->e13333 =  + lhs->e1 * rhs->e3333 + lhs->e3333 * rhs->e1 + lhs->e3 * rhs->e1333 
             + lhs->e1333 * rhs->e3 + lhs->e13 * rhs->e333 + lhs->e333 * rhs->e13 
             + lhs->e33 * rhs->e133 + lhs->e133 * rhs->e33;
  res->e23333 =  + lhs->e2 * rhs->e3333 + lhs->e3333 * rhs->e2 + lhs->e3 * rhs->e2333 
             + lhs->e2333 * rhs->e3 + lhs->e23 * rhs->e333 + lhs->e333 * rhs->e23 
             + lhs->e33 * rhs->e233 + lhs->e233 * rhs->e33;
  res->e33333 =  + lhs->e3 * rhs->e3333 + lhs->e3333 * rhs->e3 + lhs->e33 * rhs->e333 
             + lhs->e333 * rhs->e33;

}

onumm3n5_t onumm3n5_gem_oo(  onumm3n5_t* a,  onumm3n5_t* b,  onumm3n5_t* c){
  onumm3n5_t res;

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
  res.e11113 = c->e11113 + a->r * b->e11113 + a->e11113 * b->r + a->e1 * b->e1113 
             + a->e1113 * b->e1 + a->e3 * b->e1111 + a->e1111 * b->e3 
             + a->e11 * b->e113 + a->e113 * b->e11 + a->e13 * b->e111 
             + a->e111 * b->e13;
  res.e11123 = c->e11123 + a->r * b->e11123 + a->e11123 * b->r + a->e1 * b->e1123 
             + a->e1123 * b->e1 + a->e2 * b->e1113 + a->e1113 * b->e2 
             + a->e3 * b->e1112 + a->e1112 * b->e3 + a->e11 * b->e123 
             + a->e123 * b->e11 + a->e12 * b->e113 + a->e113 * b->e12 
             + a->e13 * b->e112 + a->e112 * b->e13 + a->e23 * b->e111 
             + a->e111 * b->e23;
  res.e11223 = c->e11223 + a->r * b->e11223 + a->e11223 * b->r + a->e1 * b->e1223 
             + a->e1223 * b->e1 + a->e2 * b->e1123 + a->e1123 * b->e2 
             + a->e3 * b->e1122 + a->e1122 * b->e3 + a->e11 * b->e223 
             + a->e223 * b->e11 + a->e12 * b->e123 + a->e123 * b->e12 
             + a->e22 * b->e113 + a->e113 * b->e22 + a->e13 * b->e122 
             + a->e122 * b->e13 + a->e23 * b->e112 + a->e112 * b->e23;
  res.e12223 = c->e12223 + a->r * b->e12223 + a->e12223 * b->r + a->e1 * b->e2223 
             + a->e2223 * b->e1 + a->e2 * b->e1223 + a->e1223 * b->e2 
             + a->e3 * b->e1222 + a->e1222 * b->e3 + a->e12 * b->e223 
             + a->e223 * b->e12 + a->e22 * b->e123 + a->e123 * b->e22 
             + a->e13 * b->e222 + a->e222 * b->e13 + a->e23 * b->e122 
             + a->e122 * b->e23;
  res.e22223 = c->e22223 + a->r * b->e22223 + a->e22223 * b->r + a->e2 * b->e2223 
             + a->e2223 * b->e2 + a->e3 * b->e2222 + a->e2222 * b->e3 
             + a->e22 * b->e223 + a->e223 * b->e22 + a->e23 * b->e222 
             + a->e222 * b->e23;
  res.e11133 = c->e11133 + a->r * b->e11133 + a->e11133 * b->r + a->e1 * b->e1133 
             + a->e1133 * b->e1 + a->e3 * b->e1113 + a->e1113 * b->e3 
             + a->e11 * b->e133 + a->e133 * b->e11 + a->e13 * b->e113 
             + a->e113 * b->e13 + a->e33 * b->e111 + a->e111 * b->e33;
  res.e11233 = c->e11233 + a->r * b->e11233 + a->e11233 * b->r + a->e1 * b->e1233 
             + a->e1233 * b->e1 + a->e2 * b->e1133 + a->e1133 * b->e2 
             + a->e3 * b->e1123 + a->e1123 * b->e3 + a->e11 * b->e233 
             + a->e233 * b->e11 + a->e12 * b->e133 + a->e133 * b->e12 
             + a->e13 * b->e123 + a->e123 * b->e13 + a->e23 * b->e113 
             + a->e113 * b->e23 + a->e33 * b->e112 + a->e112 * b->e33;
  res.e12233 = c->e12233 + a->r * b->e12233 + a->e12233 * b->r + a->e1 * b->e2233 
             + a->e2233 * b->e1 + a->e2 * b->e1233 + a->e1233 * b->e2 
             + a->e3 * b->e1223 + a->e1223 * b->e3 + a->e12 * b->e233 
             + a->e233 * b->e12 + a->e22 * b->e133 + a->e133 * b->e22 
             + a->e13 * b->e223 + a->e223 * b->e13 + a->e23 * b->e123 
             + a->e123 * b->e23 + a->e33 * b->e122 + a->e122 * b->e33;
  res.e22233 = c->e22233 + a->r * b->e22233 + a->e22233 * b->r + a->e2 * b->e2233 
             + a->e2233 * b->e2 + a->e3 * b->e2223 + a->e2223 * b->e3 
             + a->e22 * b->e233 + a->e233 * b->e22 + a->e23 * b->e223 
             + a->e223 * b->e23 + a->e33 * b->e222 + a->e222 * b->e33;
  res.e11333 = c->e11333 + a->r * b->e11333 + a->e11333 * b->r + a->e1 * b->e1333 
             + a->e1333 * b->e1 + a->e3 * b->e1133 + a->e1133 * b->e3 
             + a->e11 * b->e333 + a->e333 * b->e11 + a->e13 * b->e133 
             + a->e133 * b->e13 + a->e33 * b->e113 + a->e113 * b->e33;
  res.e12333 = c->e12333 + a->r * b->e12333 + a->e12333 * b->r + a->e1 * b->e2333 
             + a->e2333 * b->e1 + a->e2 * b->e1333 + a->e1333 * b->e2 
             + a->e3 * b->e1233 + a->e1233 * b->e3 + a->e12 * b->e333 
             + a->e333 * b->e12 + a->e13 * b->e233 + a->e233 * b->e13 
             + a->e23 * b->e133 + a->e133 * b->e23 + a->e33 * b->e123 
             + a->e123 * b->e33;
  res.e22333 = c->e22333 + a->r * b->e22333 + a->e22333 * b->r + a->e2 * b->e2333 
             + a->e2333 * b->e2 + a->e3 * b->e2233 + a->e2233 * b->e3 
             + a->e22 * b->e333 + a->e333 * b->e22 + a->e23 * b->e233 
             + a->e233 * b->e23 + a->e33 * b->e223 + a->e223 * b->e33;
  res.e13333 = c->e13333 + a->r * b->e13333 + a->e13333 * b->r + a->e1 * b->e3333 
             + a->e3333 * b->e1 + a->e3 * b->e1333 + a->e1333 * b->e3 
             + a->e13 * b->e333 + a->e333 * b->e13 + a->e33 * b->e133 
             + a->e133 * b->e33;
  res.e23333 = c->e23333 + a->r * b->e23333 + a->e23333 * b->r + a->e2 * b->e3333 
             + a->e3333 * b->e2 + a->e3 * b->e2333 + a->e2333 * b->e3 
             + a->e23 * b->e333 + a->e333 * b->e23 + a->e33 * b->e233 
             + a->e233 * b->e33;
  res.e33333 = c->e33333 + a->r * b->e33333 + a->e33333 * b->r + a->e3 * b->e3333 
             + a->e3333 * b->e3 + a->e33 * b->e333 + a->e333 * b->e33;

  return res;

}

void onumm3n5_gem_oo_to(  onumm3n5_t* a,  onumm3n5_t* b,  onumm3n5_t* c, onumm3n5_t* res){
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
  res->e11113 = c->e11113 + a->r * b->e11113 + a->e11113 * b->r + a->e1 * b->e1113 
             + a->e1113 * b->e1 + a->e3 * b->e1111 + a->e1111 * b->e3 
             + a->e11 * b->e113 + a->e113 * b->e11 + a->e13 * b->e111 
             + a->e111 * b->e13;
  res->e11123 = c->e11123 + a->r * b->e11123 + a->e11123 * b->r + a->e1 * b->e1123 
             + a->e1123 * b->e1 + a->e2 * b->e1113 + a->e1113 * b->e2 
             + a->e3 * b->e1112 + a->e1112 * b->e3 + a->e11 * b->e123 
             + a->e123 * b->e11 + a->e12 * b->e113 + a->e113 * b->e12 
             + a->e13 * b->e112 + a->e112 * b->e13 + a->e23 * b->e111 
             + a->e111 * b->e23;
  res->e11223 = c->e11223 + a->r * b->e11223 + a->e11223 * b->r + a->e1 * b->e1223 
             + a->e1223 * b->e1 + a->e2 * b->e1123 + a->e1123 * b->e2 
             + a->e3 * b->e1122 + a->e1122 * b->e3 + a->e11 * b->e223 
             + a->e223 * b->e11 + a->e12 * b->e123 + a->e123 * b->e12 
             + a->e22 * b->e113 + a->e113 * b->e22 + a->e13 * b->e122 
             + a->e122 * b->e13 + a->e23 * b->e112 + a->e112 * b->e23;
  res->e12223 = c->e12223 + a->r * b->e12223 + a->e12223 * b->r + a->e1 * b->e2223 
             + a->e2223 * b->e1 + a->e2 * b->e1223 + a->e1223 * b->e2 
             + a->e3 * b->e1222 + a->e1222 * b->e3 + a->e12 * b->e223 
             + a->e223 * b->e12 + a->e22 * b->e123 + a->e123 * b->e22 
             + a->e13 * b->e222 + a->e222 * b->e13 + a->e23 * b->e122 
             + a->e122 * b->e23;
  res->e22223 = c->e22223 + a->r * b->e22223 + a->e22223 * b->r + a->e2 * b->e2223 
             + a->e2223 * b->e2 + a->e3 * b->e2222 + a->e2222 * b->e3 
             + a->e22 * b->e223 + a->e223 * b->e22 + a->e23 * b->e222 
             + a->e222 * b->e23;
  res->e11133 = c->e11133 + a->r * b->e11133 + a->e11133 * b->r + a->e1 * b->e1133 
             + a->e1133 * b->e1 + a->e3 * b->e1113 + a->e1113 * b->e3 
             + a->e11 * b->e133 + a->e133 * b->e11 + a->e13 * b->e113 
             + a->e113 * b->e13 + a->e33 * b->e111 + a->e111 * b->e33;
  res->e11233 = c->e11233 + a->r * b->e11233 + a->e11233 * b->r + a->e1 * b->e1233 
             + a->e1233 * b->e1 + a->e2 * b->e1133 + a->e1133 * b->e2 
             + a->e3 * b->e1123 + a->e1123 * b->e3 + a->e11 * b->e233 
             + a->e233 * b->e11 + a->e12 * b->e133 + a->e133 * b->e12 
             + a->e13 * b->e123 + a->e123 * b->e13 + a->e23 * b->e113 
             + a->e113 * b->e23 + a->e33 * b->e112 + a->e112 * b->e33;
  res->e12233 = c->e12233 + a->r * b->e12233 + a->e12233 * b->r + a->e1 * b->e2233 
             + a->e2233 * b->e1 + a->e2 * b->e1233 + a->e1233 * b->e2 
             + a->e3 * b->e1223 + a->e1223 * b->e3 + a->e12 * b->e233 
             + a->e233 * b->e12 + a->e22 * b->e133 + a->e133 * b->e22 
             + a->e13 * b->e223 + a->e223 * b->e13 + a->e23 * b->e123 
             + a->e123 * b->e23 + a->e33 * b->e122 + a->e122 * b->e33;
  res->e22233 = c->e22233 + a->r * b->e22233 + a->e22233 * b->r + a->e2 * b->e2233 
             + a->e2233 * b->e2 + a->e3 * b->e2223 + a->e2223 * b->e3 
             + a->e22 * b->e233 + a->e233 * b->e22 + a->e23 * b->e223 
             + a->e223 * b->e23 + a->e33 * b->e222 + a->e222 * b->e33;
  res->e11333 = c->e11333 + a->r * b->e11333 + a->e11333 * b->r + a->e1 * b->e1333 
             + a->e1333 * b->e1 + a->e3 * b->e1133 + a->e1133 * b->e3 
             + a->e11 * b->e333 + a->e333 * b->e11 + a->e13 * b->e133 
             + a->e133 * b->e13 + a->e33 * b->e113 + a->e113 * b->e33;
  res->e12333 = c->e12333 + a->r * b->e12333 + a->e12333 * b->r + a->e1 * b->e2333 
             + a->e2333 * b->e1 + a->e2 * b->e1333 + a->e1333 * b->e2 
             + a->e3 * b->e1233 + a->e1233 * b->e3 + a->e12 * b->e333 
             + a->e333 * b->e12 + a->e13 * b->e233 + a->e233 * b->e13 
             + a->e23 * b->e133 + a->e133 * b->e23 + a->e33 * b->e123 
             + a->e123 * b->e33;
  res->e22333 = c->e22333 + a->r * b->e22333 + a->e22333 * b->r + a->e2 * b->e2333 
             + a->e2333 * b->e2 + a->e3 * b->e2233 + a->e2233 * b->e3 
             + a->e22 * b->e333 + a->e333 * b->e22 + a->e23 * b->e233 
             + a->e233 * b->e23 + a->e33 * b->e223 + a->e223 * b->e33;
  res->e13333 = c->e13333 + a->r * b->e13333 + a->e13333 * b->r + a->e1 * b->e3333 
             + a->e3333 * b->e1 + a->e3 * b->e1333 + a->e1333 * b->e3 
             + a->e13 * b->e333 + a->e333 * b->e13 + a->e33 * b->e133 
             + a->e133 * b->e33;
  res->e23333 = c->e23333 + a->r * b->e23333 + a->e23333 * b->r + a->e2 * b->e3333 
             + a->e3333 * b->e2 + a->e3 * b->e2333 + a->e2333 * b->e3 
             + a->e23 * b->e333 + a->e333 * b->e23 + a->e33 * b->e233 
             + a->e233 * b->e33;
  res->e33333 = c->e33333 + a->r * b->e33333 + a->e33333 * b->r + a->e3 * b->e3333 
             + a->e3333 * b->e3 + a->e33 * b->e333 + a->e333 * b->e33;

}

onumm3n5_t onumm3n5_gem_ro(  coeff_t a,  onumm3n5_t* b,  onumm3n5_t* c){
  onumm3n5_t res;

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
  // Order 5;
  res.e11111 = c->e11111 + a * b->e11111;
  res.e11112 = c->e11112 + a * b->e11112;
  res.e11122 = c->e11122 + a * b->e11122;
  res.e11222 = c->e11222 + a * b->e11222;
  res.e12222 = c->e12222 + a * b->e12222;
  res.e22222 = c->e22222 + a * b->e22222;
  res.e11113 = c->e11113 + a * b->e11113;
  res.e11123 = c->e11123 + a * b->e11123;
  res.e11223 = c->e11223 + a * b->e11223;
  res.e12223 = c->e12223 + a * b->e12223;
  res.e22223 = c->e22223 + a * b->e22223;
  res.e11133 = c->e11133 + a * b->e11133;
  res.e11233 = c->e11233 + a * b->e11233;
  res.e12233 = c->e12233 + a * b->e12233;
  res.e22233 = c->e22233 + a * b->e22233;
  res.e11333 = c->e11333 + a * b->e11333;
  res.e12333 = c->e12333 + a * b->e12333;
  res.e22333 = c->e22333 + a * b->e22333;
  res.e13333 = c->e13333 + a * b->e13333;
  res.e23333 = c->e23333 + a * b->e23333;
  res.e33333 = c->e33333 + a * b->e33333;

  return res;

}

void onumm3n5_gem_ro_to(  coeff_t a,  onumm3n5_t* b,  onumm3n5_t* c, onumm3n5_t* res){
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
  // Order 5;
  res->e11111 = c->e11111 + a * b->e11111;
  res->e11112 = c->e11112 + a * b->e11112;
  res->e11122 = c->e11122 + a * b->e11122;
  res->e11222 = c->e11222 + a * b->e11222;
  res->e12222 = c->e12222 + a * b->e12222;
  res->e22222 = c->e22222 + a * b->e22222;
  res->e11113 = c->e11113 + a * b->e11113;
  res->e11123 = c->e11123 + a * b->e11123;
  res->e11223 = c->e11223 + a * b->e11223;
  res->e12223 = c->e12223 + a * b->e12223;
  res->e22223 = c->e22223 + a * b->e22223;
  res->e11133 = c->e11133 + a * b->e11133;
  res->e11233 = c->e11233 + a * b->e11233;
  res->e12233 = c->e12233 + a * b->e12233;
  res->e22233 = c->e22233 + a * b->e22233;
  res->e11333 = c->e11333 + a * b->e11333;
  res->e12333 = c->e12333 + a * b->e12333;
  res->e22333 = c->e22333 + a * b->e22333;
  res->e13333 = c->e13333 + a * b->e13333;
  res->e23333 = c->e23333 + a * b->e23333;
  res->e33333 = c->e33333 + a * b->e33333;

}

void onumm3n5_trunc_gem_oo_to( ord_t ord_lhs,  onumm3n5_t* a,  ord_t ord_rhs,  onumm3n5_t* b,  onumm3n5_t* c, onumm3n5_t* res){
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
        case 5:
          // res order: 5
          res->e11111 = c->e11111 + a->r * b->e11111;
          res->e11112 = c->e11112 + a->r * b->e11112;
          res->e11122 = c->e11122 + a->r * b->e11122;
          res->e11222 = c->e11222 + a->r * b->e11222;
          res->e12222 = c->e12222 + a->r * b->e12222;
          res->e22222 = c->e22222 + a->r * b->e22222;
          res->e11113 = c->e11113 + a->r * b->e11113;
          res->e11123 = c->e11123 + a->r * b->e11123;
          res->e11223 = c->e11223 + a->r * b->e11223;
          res->e12223 = c->e12223 + a->r * b->e12223;
          res->e22223 = c->e22223 + a->r * b->e22223;
          res->e11133 = c->e11133 + a->r * b->e11133;
          res->e11233 = c->e11233 + a->r * b->e11233;
          res->e12233 = c->e12233 + a->r * b->e12233;
          res->e22233 = c->e22233 + a->r * b->e22233;
          res->e11333 = c->e11333 + a->r * b->e11333;
          res->e12333 = c->e12333 + a->r * b->e12333;
          res->e22333 = c->e22333 + a->r * b->e22333;
          res->e13333 = c->e13333 + a->r * b->e13333;
          res->e23333 = c->e23333 + a->r * b->e23333;
          res->e33333 = c->e33333 + a->r * b->e33333;
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
        case 4:
          // res order: 5
          res->e11111 = c->e11111 + a->e1 * b->e1111;
          res->e11112 = c->e11112 + a->e1 * b->e1112 + a->e2 * b->e1111;
          res->e11122 = c->e11122 + a->e1 * b->e1122 + a->e2 * b->e1112;
          res->e11222 = c->e11222 + a->e1 * b->e1222 + a->e2 * b->e1122;
          res->e12222 = c->e12222 + a->e1 * b->e2222 + a->e2 * b->e1222;
          res->e22222 = c->e22222 + a->e2 * b->e2222;
          res->e11113 = c->e11113 + a->e1 * b->e1113 + a->e3 * b->e1111;
          res->e11123 = c->e11123 + a->e1 * b->e1123 + a->e2 * b->e1113 
                      + a->e3 * b->e1112;
          res->e11223 = c->e11223 + a->e1 * b->e1223 + a->e2 * b->e1123 
                      + a->e3 * b->e1122;
          res->e12223 = c->e12223 + a->e1 * b->e2223 + a->e2 * b->e1223 
                      + a->e3 * b->e1222;
          res->e22223 = c->e22223 + a->e2 * b->e2223 + a->e3 * b->e2222;
          res->e11133 = c->e11133 + a->e1 * b->e1133 + a->e3 * b->e1113;
          res->e11233 = c->e11233 + a->e1 * b->e1233 + a->e2 * b->e1133 
                      + a->e3 * b->e1123;
          res->e12233 = c->e12233 + a->e1 * b->e2233 + a->e2 * b->e1233 
                      + a->e3 * b->e1223;
          res->e22233 = c->e22233 + a->e2 * b->e2233 + a->e3 * b->e2223;
          res->e11333 = c->e11333 + a->e1 * b->e1333 + a->e3 * b->e1133;
          res->e12333 = c->e12333 + a->e1 * b->e2333 + a->e2 * b->e1333 
                      + a->e3 * b->e1233;
          res->e22333 = c->e22333 + a->e2 * b->e2333 + a->e3 * b->e2233;
          res->e13333 = c->e13333 + a->e1 * b->e3333 + a->e3 * b->e1333;
          res->e23333 = c->e23333 + a->e2 * b->e3333 + a->e3 * b->e2333;
          res->e33333 = c->e33333 + a->e3 * b->e3333;
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
          res->e11113 = c->e11113 + a->e11 * b->e113 + a->e13 * b->e111;
          res->e11123 = c->e11123 + a->e11 * b->e123 + a->e12 * b->e113 
                      + a->e13 * b->e112 + a->e23 * b->e111;
          res->e11223 = c->e11223 + a->e11 * b->e223 + a->e12 * b->e123 
                      + a->e22 * b->e113 + a->e13 * b->e122 + a->e23 * b->e112;
          res->e12223 = c->e12223 + a->e12 * b->e223 + a->e22 * b->e123 
                      + a->e13 * b->e222 + a->e23 * b->e122;
          res->e22223 = c->e22223 + a->e22 * b->e223 + a->e23 * b->e222;
          res->e11133 = c->e11133 + a->e11 * b->e133 + a->e13 * b->e113 
                      + a->e33 * b->e111;
          res->e11233 = c->e11233 + a->e11 * b->e233 + a->e12 * b->e133 
                      + a->e13 * b->e123 + a->e23 * b->e113 + a->e33 * b->e112;
          res->e12233 = c->e12233 + a->e12 * b->e233 + a->e22 * b->e133 
                      + a->e13 * b->e223 + a->e23 * b->e123 + a->e33 * b->e122;
          res->e22233 = c->e22233 + a->e22 * b->e233 + a->e23 * b->e223 
                      + a->e33 * b->e222;
          res->e11333 = c->e11333 + a->e11 * b->e333 + a->e13 * b->e133 
                      + a->e33 * b->e113;
          res->e12333 = c->e12333 + a->e12 * b->e333 + a->e13 * b->e233 
                      + a->e23 * b->e133 + a->e33 * b->e123;
          res->e22333 = c->e22333 + a->e22 * b->e333 + a->e23 * b->e233 
                      + a->e33 * b->e223;
          res->e13333 = c->e13333 + a->e13 * b->e333 + a->e33 * b->e133;
          res->e23333 = c->e23333 + a->e23 * b->e333 + a->e33 * b->e233;
          res->e33333 = c->e33333 + a->e33 * b->e333;
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
          res->e11113 = c->e11113 + a->e113 * b->e11 + a->e111 * b->e13;
          res->e11123 = c->e11123 + a->e123 * b->e11 + a->e113 * b->e12 
                      + a->e112 * b->e13 + a->e111 * b->e23;
          res->e11223 = c->e11223 + a->e223 * b->e11 + a->e123 * b->e12 
                      + a->e113 * b->e22 + a->e122 * b->e13 + a->e112 * b->e23;
          res->e12223 = c->e12223 + a->e223 * b->e12 + a->e123 * b->e22 
                      + a->e222 * b->e13 + a->e122 * b->e23;
          res->e22223 = c->e22223 + a->e223 * b->e22 + a->e222 * b->e23;
          res->e11133 = c->e11133 + a->e133 * b->e11 + a->e113 * b->e13 
                      + a->e111 * b->e33;
          res->e11233 = c->e11233 + a->e233 * b->e11 + a->e133 * b->e12 
                      + a->e123 * b->e13 + a->e113 * b->e23 + a->e112 * b->e33;
          res->e12233 = c->e12233 + a->e233 * b->e12 + a->e133 * b->e22 
                      + a->e223 * b->e13 + a->e123 * b->e23 + a->e122 * b->e33;
          res->e22233 = c->e22233 + a->e233 * b->e22 + a->e223 * b->e23 
                      + a->e222 * b->e33;
          res->e11333 = c->e11333 + a->e333 * b->e11 + a->e133 * b->e13 
                      + a->e113 * b->e33;
          res->e12333 = c->e12333 + a->e333 * b->e12 + a->e233 * b->e13 
                      + a->e133 * b->e23 + a->e123 * b->e33;
          res->e22333 = c->e22333 + a->e333 * b->e22 + a->e233 * b->e23 
                      + a->e223 * b->e33;
          res->e13333 = c->e13333 + a->e333 * b->e13 + a->e133 * b->e33;
          res->e23333 = c->e23333 + a->e333 * b->e23 + a->e233 * b->e33;
          res->e33333 = c->e33333 + a->e333 * b->e33;
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
        case 1:
          // res order: 5
          res->e11111 = c->e11111 + a->e1111 * b->e1;
          res->e11112 = c->e11112 + a->e1112 * b->e1 + a->e1111 * b->e2;
          res->e11122 = c->e11122 + a->e1122 * b->e1 + a->e1112 * b->e2;
          res->e11222 = c->e11222 + a->e1222 * b->e1 + a->e1122 * b->e2;
          res->e12222 = c->e12222 + a->e2222 * b->e1 + a->e1222 * b->e2;
          res->e22222 = c->e22222 + a->e2222 * b->e2;
          res->e11113 = c->e11113 + a->e1113 * b->e1 + a->e1111 * b->e3;
          res->e11123 = c->e11123 + a->e1123 * b->e1 + a->e1113 * b->e2 
                      + a->e1112 * b->e3;
          res->e11223 = c->e11223 + a->e1223 * b->e1 + a->e1123 * b->e2 
                      + a->e1122 * b->e3;
          res->e12223 = c->e12223 + a->e2223 * b->e1 + a->e1223 * b->e2 
                      + a->e1222 * b->e3;
          res->e22223 = c->e22223 + a->e2223 * b->e2 + a->e2222 * b->e3;
          res->e11133 = c->e11133 + a->e1133 * b->e1 + a->e1113 * b->e3;
          res->e11233 = c->e11233 + a->e1233 * b->e1 + a->e1133 * b->e2 
                      + a->e1123 * b->e3;
          res->e12233 = c->e12233 + a->e2233 * b->e1 + a->e1233 * b->e2 
                      + a->e1223 * b->e3;
          res->e22233 = c->e22233 + a->e2233 * b->e2 + a->e2223 * b->e3;
          res->e11333 = c->e11333 + a->e1333 * b->e1 + a->e1133 * b->e3;
          res->e12333 = c->e12333 + a->e2333 * b->e1 + a->e1333 * b->e2 
                      + a->e1233 * b->e3;
          res->e22333 = c->e22333 + a->e2333 * b->e2 + a->e2233 * b->e3;
          res->e13333 = c->e13333 + a->e3333 * b->e1 + a->e1333 * b->e3;
          res->e23333 = c->e23333 + a->e3333 * b->e2 + a->e2333 * b->e3;
          res->e33333 = c->e33333 + a->e3333 * b->e3;
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
          res->e11113 = c->e11113 + a->e11113 * b->r;
          res->e11123 = c->e11123 + a->e11123 * b->r;
          res->e11223 = c->e11223 + a->e11223 * b->r;
          res->e12223 = c->e12223 + a->e12223 * b->r;
          res->e22223 = c->e22223 + a->e22223 * b->r;
          res->e11133 = c->e11133 + a->e11133 * b->r;
          res->e11233 = c->e11233 + a->e11233 * b->r;
          res->e12233 = c->e12233 + a->e12233 * b->r;
          res->e22233 = c->e22233 + a->e22233 * b->r;
          res->e11333 = c->e11333 + a->e11333 * b->r;
          res->e12333 = c->e12333 + a->e12333 * b->r;
          res->e22333 = c->e22333 + a->e22333 * b->r;
          res->e13333 = c->e13333 + a->e13333 * b->r;
          res->e23333 = c->e23333 + a->e23333 * b->r;
          res->e33333 = c->e33333 + a->e33333 * b->r;
          break;
      }
      break;
  }

}

onumm3n5_t onumm3n5_feval(coeff_t* feval_re, onumm3n5_t* x){

  onumm3n5_t res;

  // feval function
  //  Definitions
  coeff_t factor=1, coef = 0;
  onumm3n5_t deltax = (*x), deltax_power = (*x);
  deltax.r = 0.0;
  deltax_power.r = 0.0;
  onumm3n5_set_r(0.0, &res);
  //  Real
  res.r = feval_re[0];
  // Order 1
  factor *=1;
  coef    = feval_re[1]/ factor;;
  onumm3n5_gem_ro_to( coef, &deltax_power, &res, &res);
  deltax_power = onumm3n5_mul_oo(&deltax_power,&deltax);
  // Order 2
  factor *=2;
  coef    = feval_re[2]/ factor;;
  onumm3n5_gem_ro_to( coef, &deltax_power, &res, &res);
  deltax_power = onumm3n5_mul_oo(&deltax_power,&deltax);
  // Order 3
  factor *=3;
  coef    = feval_re[3]/ factor;;
  onumm3n5_gem_ro_to( coef, &deltax_power, &res, &res);
  deltax_power = onumm3n5_mul_oo(&deltax_power,&deltax);
  // Order 4
  factor *=4;
  coef    = feval_re[4]/ factor;;
  onumm3n5_gem_ro_to( coef, &deltax_power, &res, &res);
  deltax_power = onumm3n5_mul_oo(&deltax_power,&deltax);
  // Order 5
  factor *=5;
  coef    = feval_re[5]/ factor;;
  onumm3n5_gem_ro_to( coef, &deltax_power, &res, &res);

  return res;

}

void onumm3n5_feval_to(coeff_t* feval_re, onumm3n5_t* x, onumm3n5_t* res){

  // feval function
  //  Definitions
  coeff_t factor=1, coef = 0;
  onumm3n5_t deltax = (*x), deltax_power = (*x);
  deltax.r = 0.0;
  deltax_power.r = 0.0;
  onumm3n5_set_r(0.0, res);
  //  Real
  res->r = feval_re[0];
  // Order 1
  factor *=1;
  coef    = feval_re[1]/ factor;;
  onumm3n5_gem_ro_to( coef, &deltax_power, res, res);
  deltax_power = onumm3n5_mul_oo(&deltax_power,&deltax);
  // Order 2
  factor *=2;
  coef    = feval_re[2]/ factor;;
  onumm3n5_gem_ro_to( coef, &deltax_power, res, res);
  deltax_power = onumm3n5_mul_oo(&deltax_power,&deltax);
  // Order 3
  factor *=3;
  coef    = feval_re[3]/ factor;;
  onumm3n5_gem_ro_to( coef, &deltax_power, res, res);
  deltax_power = onumm3n5_mul_oo(&deltax_power,&deltax);
  // Order 4
  factor *=4;
  coef    = feval_re[4]/ factor;;
  onumm3n5_gem_ro_to( coef, &deltax_power, res, res);
  deltax_power = onumm3n5_mul_oo(&deltax_power,&deltax);
  // Order 5
  factor *=5;
  coef    = feval_re[5]/ factor;;
  onumm3n5_gem_ro_to( coef, &deltax_power, res, res);

}

