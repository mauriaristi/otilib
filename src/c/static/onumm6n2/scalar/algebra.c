
// Division.

// ****************************************************************************************************
onumm6n2_t onumm6n2_div_ro(coeff_t num, onumm6n2_t* den){

    
    onumm6n2_t inv = onumm6n2_pow(den,-1);
    onumm6n2_t res = onumm6n2_mul_ro(num,&inv);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
onumm6n2_t onumm6n2_div_oo(onumm6n2_t* num, onumm6n2_t* den){

    
    onumm6n2_t inv = onumm6n2_init();
    onumm6n2_pow_to(den,-1,&inv);
    onumm6n2_t res = onumm6n2_mul_oo(num,&inv);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
onumm6n2_t onumm6n2_div_or(onumm6n2_t* num, coeff_t val){

    return onumm6n2_mul_ro(1.0/val,num);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
onumm6n2_t onumm6n2_abs(onumm6n2_t* num){

	onumm6n2_t res;
    onumm6n2_abs_to(num,&res);
    return res;

}
// ----------------------------------------------------------------------------------------------------

onumm6n2_t onumm6n2_neg(  onumm6n2_t* lhs){

  onumm6n2_t res;

  // Negation like function '-lhs'
  // Real;
  res.r = -lhs->r;
  // Order 1;
  res.e1 = -lhs->e1;
  res.e2 = -lhs->e2;
  res.e3 = -lhs->e3;
  res.e4 = -lhs->e4;
  res.e5 = -lhs->e5;
  res.e6 = -lhs->e6;
  // Order 2;
  res.e11 = -lhs->e11;
  res.e12 = -lhs->e12;
  res.e22 = -lhs->e22;
  res.e13 = -lhs->e13;
  res.e23 = -lhs->e23;
  res.e33 = -lhs->e33;
  res.e14 = -lhs->e14;
  res.e24 = -lhs->e24;
  res.e34 = -lhs->e34;
  res.e44 = -lhs->e44;
  res.e15 = -lhs->e15;
  res.e25 = -lhs->e25;
  res.e35 = -lhs->e35;
  res.e45 = -lhs->e45;
  res.e55 = -lhs->e55;
  res.e16 = -lhs->e16;
  res.e26 = -lhs->e26;
  res.e36 = -lhs->e36;
  res.e46 = -lhs->e46;
  res.e56 = -lhs->e56;
  res.e66 = -lhs->e66;

  return res;

}

void onumm6n2_neg_to(  onumm6n2_t* lhs, onumm6n2_t* res){

  // Negation like function '-lhs'
  // Real;
  res->r = -lhs->r;
  // Order 1;
  res->e1 = -lhs->e1;
  res->e2 = -lhs->e2;
  res->e3 = -lhs->e3;
  res->e4 = -lhs->e4;
  res->e5 = -lhs->e5;
  res->e6 = -lhs->e6;
  // Order 2;
  res->e11 = -lhs->e11;
  res->e12 = -lhs->e12;
  res->e22 = -lhs->e22;
  res->e13 = -lhs->e13;
  res->e23 = -lhs->e23;
  res->e33 = -lhs->e33;
  res->e14 = -lhs->e14;
  res->e24 = -lhs->e24;
  res->e34 = -lhs->e34;
  res->e44 = -lhs->e44;
  res->e15 = -lhs->e15;
  res->e25 = -lhs->e25;
  res->e35 = -lhs->e35;
  res->e45 = -lhs->e45;
  res->e55 = -lhs->e55;
  res->e16 = -lhs->e16;
  res->e26 = -lhs->e26;
  res->e36 = -lhs->e36;
  res->e46 = -lhs->e46;
  res->e56 = -lhs->e56;
  res->e66 = -lhs->e66;

}

onumm6n2_t onumm6n2_sum_oo(  onumm6n2_t* lhs,  onumm6n2_t* rhs){
  onumm6n2_t res;

  // Addition like function 'lhs + rhs'
  //  Real
  res.r = lhs->r + rhs->r;
  // Order 1
  res.e1 = lhs->e1 + rhs->e1;
  res.e2 = lhs->e2 + rhs->e2;
  res.e3 = lhs->e3 + rhs->e3;
  res.e4 = lhs->e4 + rhs->e4;
  res.e5 = lhs->e5 + rhs->e5;
  res.e6 = lhs->e6 + rhs->e6;
  // Order 2
  res.e11 = lhs->e11 + rhs->e11;
  res.e12 = lhs->e12 + rhs->e12;
  res.e22 = lhs->e22 + rhs->e22;
  res.e13 = lhs->e13 + rhs->e13;
  res.e23 = lhs->e23 + rhs->e23;
  res.e33 = lhs->e33 + rhs->e33;
  res.e14 = lhs->e14 + rhs->e14;
  res.e24 = lhs->e24 + rhs->e24;
  res.e34 = lhs->e34 + rhs->e34;
  res.e44 = lhs->e44 + rhs->e44;
  res.e15 = lhs->e15 + rhs->e15;
  res.e25 = lhs->e25 + rhs->e25;
  res.e35 = lhs->e35 + rhs->e35;
  res.e45 = lhs->e45 + rhs->e45;
  res.e55 = lhs->e55 + rhs->e55;
  res.e16 = lhs->e16 + rhs->e16;
  res.e26 = lhs->e26 + rhs->e26;
  res.e36 = lhs->e36 + rhs->e36;
  res.e46 = lhs->e46 + rhs->e46;
  res.e56 = lhs->e56 + rhs->e56;
  res.e66 = lhs->e66 + rhs->e66;

  return res;

}

void onumm6n2_sum_oo_to(  onumm6n2_t* lhs,  onumm6n2_t* rhs, onumm6n2_t* res){
  // Addition like function 'lhs + rhs'
  //  Real
  res->r = lhs->r + rhs->r;
  // Order 1
  res->e1 = lhs->e1 + rhs->e1;
  res->e2 = lhs->e2 + rhs->e2;
  res->e3 = lhs->e3 + rhs->e3;
  res->e4 = lhs->e4 + rhs->e4;
  res->e5 = lhs->e5 + rhs->e5;
  res->e6 = lhs->e6 + rhs->e6;
  // Order 2
  res->e11 = lhs->e11 + rhs->e11;
  res->e12 = lhs->e12 + rhs->e12;
  res->e22 = lhs->e22 + rhs->e22;
  res->e13 = lhs->e13 + rhs->e13;
  res->e23 = lhs->e23 + rhs->e23;
  res->e33 = lhs->e33 + rhs->e33;
  res->e14 = lhs->e14 + rhs->e14;
  res->e24 = lhs->e24 + rhs->e24;
  res->e34 = lhs->e34 + rhs->e34;
  res->e44 = lhs->e44 + rhs->e44;
  res->e15 = lhs->e15 + rhs->e15;
  res->e25 = lhs->e25 + rhs->e25;
  res->e35 = lhs->e35 + rhs->e35;
  res->e45 = lhs->e45 + rhs->e45;
  res->e55 = lhs->e55 + rhs->e55;
  res->e16 = lhs->e16 + rhs->e16;
  res->e26 = lhs->e26 + rhs->e26;
  res->e36 = lhs->e36 + rhs->e36;
  res->e46 = lhs->e46 + rhs->e46;
  res->e56 = lhs->e56 + rhs->e56;
  res->e66 = lhs->e66 + rhs->e66;

}

onumm6n2_t onumm6n2_sum_ro(  coeff_t lhs,  onumm6n2_t* rhs){
  onumm6n2_t res;

  // Addition like function 'lhs + rhs'
  // Real;
  res.r = lhs + rhs->r;
  // Order 1;
  res.e1 =  + rhs->e1;
  res.e2 =  + rhs->e2;
  res.e3 =  + rhs->e3;
  res.e4 =  + rhs->e4;
  res.e5 =  + rhs->e5;
  res.e6 =  + rhs->e6;
  // Order 2;
  res.e11 =  + rhs->e11;
  res.e12 =  + rhs->e12;
  res.e22 =  + rhs->e22;
  res.e13 =  + rhs->e13;
  res.e23 =  + rhs->e23;
  res.e33 =  + rhs->e33;
  res.e14 =  + rhs->e14;
  res.e24 =  + rhs->e24;
  res.e34 =  + rhs->e34;
  res.e44 =  + rhs->e44;
  res.e15 =  + rhs->e15;
  res.e25 =  + rhs->e25;
  res.e35 =  + rhs->e35;
  res.e45 =  + rhs->e45;
  res.e55 =  + rhs->e55;
  res.e16 =  + rhs->e16;
  res.e26 =  + rhs->e26;
  res.e36 =  + rhs->e36;
  res.e46 =  + rhs->e46;
  res.e56 =  + rhs->e56;
  res.e66 =  + rhs->e66;

  return res;

}

void onumm6n2_sum_ro_to(  coeff_t lhs,  onumm6n2_t* rhs, onumm6n2_t* res){
  // Addition like function 'lhs + rhs'
  // Real;
  res->r = lhs + rhs->r;
  // Order 1;
  res->e1 =  + rhs->e1;
  res->e2 =  + rhs->e2;
  res->e3 =  + rhs->e3;
  res->e4 =  + rhs->e4;
  res->e5 =  + rhs->e5;
  res->e6 =  + rhs->e6;
  // Order 2;
  res->e11 =  + rhs->e11;
  res->e12 =  + rhs->e12;
  res->e22 =  + rhs->e22;
  res->e13 =  + rhs->e13;
  res->e23 =  + rhs->e23;
  res->e33 =  + rhs->e33;
  res->e14 =  + rhs->e14;
  res->e24 =  + rhs->e24;
  res->e34 =  + rhs->e34;
  res->e44 =  + rhs->e44;
  res->e15 =  + rhs->e15;
  res->e25 =  + rhs->e25;
  res->e35 =  + rhs->e35;
  res->e45 =  + rhs->e45;
  res->e55 =  + rhs->e55;
  res->e16 =  + rhs->e16;
  res->e26 =  + rhs->e26;
  res->e36 =  + rhs->e36;
  res->e46 =  + rhs->e46;
  res->e56 =  + rhs->e56;
  res->e66 =  + rhs->e66;

}

onumm6n2_t onumm6n2_sub_oo(  onumm6n2_t* lhs,  onumm6n2_t* rhs){
  onumm6n2_t res;

  // Addition like function 'lhs - rhs'
  //  Real
  res.r = lhs->r - rhs->r;
  // Order 1
  res.e1 = lhs->e1 - rhs->e1;
  res.e2 = lhs->e2 - rhs->e2;
  res.e3 = lhs->e3 - rhs->e3;
  res.e4 = lhs->e4 - rhs->e4;
  res.e5 = lhs->e5 - rhs->e5;
  res.e6 = lhs->e6 - rhs->e6;
  // Order 2
  res.e11 = lhs->e11 - rhs->e11;
  res.e12 = lhs->e12 - rhs->e12;
  res.e22 = lhs->e22 - rhs->e22;
  res.e13 = lhs->e13 - rhs->e13;
  res.e23 = lhs->e23 - rhs->e23;
  res.e33 = lhs->e33 - rhs->e33;
  res.e14 = lhs->e14 - rhs->e14;
  res.e24 = lhs->e24 - rhs->e24;
  res.e34 = lhs->e34 - rhs->e34;
  res.e44 = lhs->e44 - rhs->e44;
  res.e15 = lhs->e15 - rhs->e15;
  res.e25 = lhs->e25 - rhs->e25;
  res.e35 = lhs->e35 - rhs->e35;
  res.e45 = lhs->e45 - rhs->e45;
  res.e55 = lhs->e55 - rhs->e55;
  res.e16 = lhs->e16 - rhs->e16;
  res.e26 = lhs->e26 - rhs->e26;
  res.e36 = lhs->e36 - rhs->e36;
  res.e46 = lhs->e46 - rhs->e46;
  res.e56 = lhs->e56 - rhs->e56;
  res.e66 = lhs->e66 - rhs->e66;

  return res;

}

void onumm6n2_sub_oo_to(  onumm6n2_t* lhs,  onumm6n2_t* rhs, onumm6n2_t* res){
  // Addition like function 'lhs - rhs'
  //  Real
  res->r = lhs->r - rhs->r;
  // Order 1
  res->e1 = lhs->e1 - rhs->e1;
  res->e2 = lhs->e2 - rhs->e2;
  res->e3 = lhs->e3 - rhs->e3;
  res->e4 = lhs->e4 - rhs->e4;
  res->e5 = lhs->e5 - rhs->e5;
  res->e6 = lhs->e6 - rhs->e6;
  // Order 2
  res->e11 = lhs->e11 - rhs->e11;
  res->e12 = lhs->e12 - rhs->e12;
  res->e22 = lhs->e22 - rhs->e22;
  res->e13 = lhs->e13 - rhs->e13;
  res->e23 = lhs->e23 - rhs->e23;
  res->e33 = lhs->e33 - rhs->e33;
  res->e14 = lhs->e14 - rhs->e14;
  res->e24 = lhs->e24 - rhs->e24;
  res->e34 = lhs->e34 - rhs->e34;
  res->e44 = lhs->e44 - rhs->e44;
  res->e15 = lhs->e15 - rhs->e15;
  res->e25 = lhs->e25 - rhs->e25;
  res->e35 = lhs->e35 - rhs->e35;
  res->e45 = lhs->e45 - rhs->e45;
  res->e55 = lhs->e55 - rhs->e55;
  res->e16 = lhs->e16 - rhs->e16;
  res->e26 = lhs->e26 - rhs->e26;
  res->e36 = lhs->e36 - rhs->e36;
  res->e46 = lhs->e46 - rhs->e46;
  res->e56 = lhs->e56 - rhs->e56;
  res->e66 = lhs->e66 - rhs->e66;

}

onumm6n2_t onumm6n2_sub_ro(  coeff_t lhs,  onumm6n2_t* rhs){
  onumm6n2_t res;

  // Addition like function 'lhs - rhs'
  // Real;
  res.r = lhs - rhs->r;
  // Order 1;
  res.e1 =  - rhs->e1;
  res.e2 =  - rhs->e2;
  res.e3 =  - rhs->e3;
  res.e4 =  - rhs->e4;
  res.e5 =  - rhs->e5;
  res.e6 =  - rhs->e6;
  // Order 2;
  res.e11 =  - rhs->e11;
  res.e12 =  - rhs->e12;
  res.e22 =  - rhs->e22;
  res.e13 =  - rhs->e13;
  res.e23 =  - rhs->e23;
  res.e33 =  - rhs->e33;
  res.e14 =  - rhs->e14;
  res.e24 =  - rhs->e24;
  res.e34 =  - rhs->e34;
  res.e44 =  - rhs->e44;
  res.e15 =  - rhs->e15;
  res.e25 =  - rhs->e25;
  res.e35 =  - rhs->e35;
  res.e45 =  - rhs->e45;
  res.e55 =  - rhs->e55;
  res.e16 =  - rhs->e16;
  res.e26 =  - rhs->e26;
  res.e36 =  - rhs->e36;
  res.e46 =  - rhs->e46;
  res.e56 =  - rhs->e56;
  res.e66 =  - rhs->e66;

  return res;

}

void onumm6n2_sub_ro_to(  coeff_t lhs,  onumm6n2_t* rhs, onumm6n2_t* res){
  // Addition like function 'lhs - rhs'
  // Real;
  res->r = lhs - rhs->r;
  // Order 1;
  res->e1 =  - rhs->e1;
  res->e2 =  - rhs->e2;
  res->e3 =  - rhs->e3;
  res->e4 =  - rhs->e4;
  res->e5 =  - rhs->e5;
  res->e6 =  - rhs->e6;
  // Order 2;
  res->e11 =  - rhs->e11;
  res->e12 =  - rhs->e12;
  res->e22 =  - rhs->e22;
  res->e13 =  - rhs->e13;
  res->e23 =  - rhs->e23;
  res->e33 =  - rhs->e33;
  res->e14 =  - rhs->e14;
  res->e24 =  - rhs->e24;
  res->e34 =  - rhs->e34;
  res->e44 =  - rhs->e44;
  res->e15 =  - rhs->e15;
  res->e25 =  - rhs->e25;
  res->e35 =  - rhs->e35;
  res->e45 =  - rhs->e45;
  res->e55 =  - rhs->e55;
  res->e16 =  - rhs->e16;
  res->e26 =  - rhs->e26;
  res->e36 =  - rhs->e36;
  res->e46 =  - rhs->e46;
  res->e56 =  - rhs->e56;
  res->e66 =  - rhs->e66;

}

onumm6n2_t onumm6n2_sub_or(  onumm6n2_t* lhs,  coeff_t rhs){
  onumm6n2_t res;

  // Addition like function 'lhs - rhs'
  // Real;
  res.r = lhs->r - rhs;
  // Order 1;
  res.e1 = lhs->e1;
  res.e2 = lhs->e2;
  res.e3 = lhs->e3;
  res.e4 = lhs->e4;
  res.e5 = lhs->e5;
  res.e6 = lhs->e6;
  // Order 2;
  res.e11 = lhs->e11;
  res.e12 = lhs->e12;
  res.e22 = lhs->e22;
  res.e13 = lhs->e13;
  res.e23 = lhs->e23;
  res.e33 = lhs->e33;
  res.e14 = lhs->e14;
  res.e24 = lhs->e24;
  res.e34 = lhs->e34;
  res.e44 = lhs->e44;
  res.e15 = lhs->e15;
  res.e25 = lhs->e25;
  res.e35 = lhs->e35;
  res.e45 = lhs->e45;
  res.e55 = lhs->e55;
  res.e16 = lhs->e16;
  res.e26 = lhs->e26;
  res.e36 = lhs->e36;
  res.e46 = lhs->e46;
  res.e56 = lhs->e56;
  res.e66 = lhs->e66;

  return res;

}

void onumm6n2_sub_or_to(  onumm6n2_t* lhs,  coeff_t rhs, onumm6n2_t* res){
  // Addition like function 'lhs - rhs'
  // Real;
  res->r = lhs->r - rhs;
  // Order 1;
  res->e1 = lhs->e1;
  res->e2 = lhs->e2;
  res->e3 = lhs->e3;
  res->e4 = lhs->e4;
  res->e5 = lhs->e5;
  res->e6 = lhs->e6;
  // Order 2;
  res->e11 = lhs->e11;
  res->e12 = lhs->e12;
  res->e22 = lhs->e22;
  res->e13 = lhs->e13;
  res->e23 = lhs->e23;
  res->e33 = lhs->e33;
  res->e14 = lhs->e14;
  res->e24 = lhs->e24;
  res->e34 = lhs->e34;
  res->e44 = lhs->e44;
  res->e15 = lhs->e15;
  res->e25 = lhs->e25;
  res->e35 = lhs->e35;
  res->e45 = lhs->e45;
  res->e55 = lhs->e55;
  res->e16 = lhs->e16;
  res->e26 = lhs->e26;
  res->e36 = lhs->e36;
  res->e46 = lhs->e46;
  res->e56 = lhs->e56;
  res->e66 = lhs->e66;

}

onumm6n2_t onumm6n2_mul_oo(  onumm6n2_t* lhs,  onumm6n2_t* rhs){
  onumm6n2_t res;

  //  Multiplication like function 'lhs * rhs'
  // Real;
  res.r = lhs->r * rhs->r;
  // Order 1;
  res.e1 = lhs->r * rhs->e1 + lhs->e1 * rhs->r;
  res.e2 = lhs->r * rhs->e2 + lhs->e2 * rhs->r;
  res.e3 = lhs->r * rhs->e3 + lhs->e3 * rhs->r;
  res.e4 = lhs->r * rhs->e4 + lhs->e4 * rhs->r;
  res.e5 = lhs->r * rhs->e5 + lhs->e5 * rhs->r;
  res.e6 = lhs->r * rhs->e6 + lhs->e6 * rhs->r;
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
  res.e14 = lhs->r * rhs->e14 + lhs->e14 * rhs->r + lhs->e1 * rhs->e4 
          + lhs->e4 * rhs->e1;
  res.e24 = lhs->r * rhs->e24 + lhs->e24 * rhs->r + lhs->e2 * rhs->e4 
          + lhs->e4 * rhs->e2;
  res.e34 = lhs->r * rhs->e34 + lhs->e34 * rhs->r + lhs->e3 * rhs->e4 
          + lhs->e4 * rhs->e3;
  res.e44 = lhs->r * rhs->e44 + lhs->e44 * rhs->r + lhs->e4 * rhs->e4;
  res.e15 = lhs->r * rhs->e15 + lhs->e15 * rhs->r + lhs->e1 * rhs->e5 
          + lhs->e5 * rhs->e1;
  res.e25 = lhs->r * rhs->e25 + lhs->e25 * rhs->r + lhs->e2 * rhs->e5 
          + lhs->e5 * rhs->e2;
  res.e35 = lhs->r * rhs->e35 + lhs->e35 * rhs->r + lhs->e3 * rhs->e5 
          + lhs->e5 * rhs->e3;
  res.e45 = lhs->r * rhs->e45 + lhs->e45 * rhs->r + lhs->e4 * rhs->e5 
          + lhs->e5 * rhs->e4;
  res.e55 = lhs->r * rhs->e55 + lhs->e55 * rhs->r + lhs->e5 * rhs->e5;
  res.e16 = lhs->r * rhs->e16 + lhs->e16 * rhs->r + lhs->e1 * rhs->e6 
          + lhs->e6 * rhs->e1;
  res.e26 = lhs->r * rhs->e26 + lhs->e26 * rhs->r + lhs->e2 * rhs->e6 
          + lhs->e6 * rhs->e2;
  res.e36 = lhs->r * rhs->e36 + lhs->e36 * rhs->r + lhs->e3 * rhs->e6 
          + lhs->e6 * rhs->e3;
  res.e46 = lhs->r * rhs->e46 + lhs->e46 * rhs->r + lhs->e4 * rhs->e6 
          + lhs->e6 * rhs->e4;
  res.e56 = lhs->r * rhs->e56 + lhs->e56 * rhs->r + lhs->e5 * rhs->e6 
          + lhs->e6 * rhs->e5;
  res.e66 = lhs->r * rhs->e66 + lhs->e66 * rhs->r + lhs->e6 * rhs->e6;

  return res;

}

void onumm6n2_mul_oo_to(  onumm6n2_t* lhs,  onumm6n2_t* rhs, onumm6n2_t* res){
  //  Multiplication like function 'lhs * rhs'
  // Real;
  res->r = lhs->r * rhs->r;
  // Order 1;
  res->e1 = lhs->r * rhs->e1 + lhs->e1 * rhs->r;
  res->e2 = lhs->r * rhs->e2 + lhs->e2 * rhs->r;
  res->e3 = lhs->r * rhs->e3 + lhs->e3 * rhs->r;
  res->e4 = lhs->r * rhs->e4 + lhs->e4 * rhs->r;
  res->e5 = lhs->r * rhs->e5 + lhs->e5 * rhs->r;
  res->e6 = lhs->r * rhs->e6 + lhs->e6 * rhs->r;
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
  res->e14 = lhs->r * rhs->e14 + lhs->e14 * rhs->r + lhs->e1 * rhs->e4 
          + lhs->e4 * rhs->e1;
  res->e24 = lhs->r * rhs->e24 + lhs->e24 * rhs->r + lhs->e2 * rhs->e4 
          + lhs->e4 * rhs->e2;
  res->e34 = lhs->r * rhs->e34 + lhs->e34 * rhs->r + lhs->e3 * rhs->e4 
          + lhs->e4 * rhs->e3;
  res->e44 = lhs->r * rhs->e44 + lhs->e44 * rhs->r + lhs->e4 * rhs->e4;
  res->e15 = lhs->r * rhs->e15 + lhs->e15 * rhs->r + lhs->e1 * rhs->e5 
          + lhs->e5 * rhs->e1;
  res->e25 = lhs->r * rhs->e25 + lhs->e25 * rhs->r + lhs->e2 * rhs->e5 
          + lhs->e5 * rhs->e2;
  res->e35 = lhs->r * rhs->e35 + lhs->e35 * rhs->r + lhs->e3 * rhs->e5 
          + lhs->e5 * rhs->e3;
  res->e45 = lhs->r * rhs->e45 + lhs->e45 * rhs->r + lhs->e4 * rhs->e5 
          + lhs->e5 * rhs->e4;
  res->e55 = lhs->r * rhs->e55 + lhs->e55 * rhs->r + lhs->e5 * rhs->e5;
  res->e16 = lhs->r * rhs->e16 + lhs->e16 * rhs->r + lhs->e1 * rhs->e6 
          + lhs->e6 * rhs->e1;
  res->e26 = lhs->r * rhs->e26 + lhs->e26 * rhs->r + lhs->e2 * rhs->e6 
          + lhs->e6 * rhs->e2;
  res->e36 = lhs->r * rhs->e36 + lhs->e36 * rhs->r + lhs->e3 * rhs->e6 
          + lhs->e6 * rhs->e3;
  res->e46 = lhs->r * rhs->e46 + lhs->e46 * rhs->r + lhs->e4 * rhs->e6 
          + lhs->e6 * rhs->e4;
  res->e56 = lhs->r * rhs->e56 + lhs->e56 * rhs->r + lhs->e5 * rhs->e6 
          + lhs->e6 * rhs->e5;
  res->e66 = lhs->r * rhs->e66 + lhs->e66 * rhs->r + lhs->e6 * rhs->e6;

}

onumm6n2_t onumm6n2_mul_ro(  coeff_t lhs,  onumm6n2_t* rhs){
  onumm6n2_t res;

  // Multiplication like function 'lhs * rhs'
  //  Real;
  res.r = lhs * rhs->r;
  // Order 1;
  res.e1 = lhs * rhs->e1;
  res.e2 = lhs * rhs->e2;
  res.e3 = lhs * rhs->e3;
  res.e4 = lhs * rhs->e4;
  res.e5 = lhs * rhs->e5;
  res.e6 = lhs * rhs->e6;
  // Order 2;
  res.e11 = lhs * rhs->e11;
  res.e12 = lhs * rhs->e12;
  res.e22 = lhs * rhs->e22;
  res.e13 = lhs * rhs->e13;
  res.e23 = lhs * rhs->e23;
  res.e33 = lhs * rhs->e33;
  res.e14 = lhs * rhs->e14;
  res.e24 = lhs * rhs->e24;
  res.e34 = lhs * rhs->e34;
  res.e44 = lhs * rhs->e44;
  res.e15 = lhs * rhs->e15;
  res.e25 = lhs * rhs->e25;
  res.e35 = lhs * rhs->e35;
  res.e45 = lhs * rhs->e45;
  res.e55 = lhs * rhs->e55;
  res.e16 = lhs * rhs->e16;
  res.e26 = lhs * rhs->e26;
  res.e36 = lhs * rhs->e36;
  res.e46 = lhs * rhs->e46;
  res.e56 = lhs * rhs->e56;
  res.e66 = lhs * rhs->e66;

  return res;

}

void onumm6n2_mul_ro_to(  coeff_t lhs,  onumm6n2_t* rhs, onumm6n2_t* res){
  // Multiplication like function 'lhs * rhs'
  //  Real;
  res->r = lhs * rhs->r;
  // Order 1;
  res->e1 = lhs * rhs->e1;
  res->e2 = lhs * rhs->e2;
  res->e3 = lhs * rhs->e3;
  res->e4 = lhs * rhs->e4;
  res->e5 = lhs * rhs->e5;
  res->e6 = lhs * rhs->e6;
  // Order 2;
  res->e11 = lhs * rhs->e11;
  res->e12 = lhs * rhs->e12;
  res->e22 = lhs * rhs->e22;
  res->e13 = lhs * rhs->e13;
  res->e23 = lhs * rhs->e23;
  res->e33 = lhs * rhs->e33;
  res->e14 = lhs * rhs->e14;
  res->e24 = lhs * rhs->e24;
  res->e34 = lhs * rhs->e34;
  res->e44 = lhs * rhs->e44;
  res->e15 = lhs * rhs->e15;
  res->e25 = lhs * rhs->e25;
  res->e35 = lhs * rhs->e35;
  res->e45 = lhs * rhs->e45;
  res->e55 = lhs * rhs->e55;
  res->e16 = lhs * rhs->e16;
  res->e26 = lhs * rhs->e26;
  res->e36 = lhs * rhs->e36;
  res->e46 = lhs * rhs->e46;
  res->e56 = lhs * rhs->e56;
  res->e66 = lhs * rhs->e66;

}

onumm6n2_t onumm6n2_trunc_mul_oo(  onumm6n2_t* lhs,  onumm6n2_t* rhs){
  onumm6n2_t res;

  res = onumm6n2_init();

  //  Truncated multiplication like function 'lhs * rhs'
  // Order 2;
  res.e11 =  + lhs->e1 * rhs->e1;
  res.e12 =  + lhs->e1 * rhs->e2 + lhs->e2 * rhs->e1;
  res.e22 =  + lhs->e2 * rhs->e2;
  res.e13 =  + lhs->e1 * rhs->e3 + lhs->e3 * rhs->e1;
  res.e23 =  + lhs->e2 * rhs->e3 + lhs->e3 * rhs->e2;
  res.e33 =  + lhs->e3 * rhs->e3;
  res.e14 =  + lhs->e1 * rhs->e4 + lhs->e4 * rhs->e1;
  res.e24 =  + lhs->e2 * rhs->e4 + lhs->e4 * rhs->e2;
  res.e34 =  + lhs->e3 * rhs->e4 + lhs->e4 * rhs->e3;
  res.e44 =  + lhs->e4 * rhs->e4;
  res.e15 =  + lhs->e1 * rhs->e5 + lhs->e5 * rhs->e1;
  res.e25 =  + lhs->e2 * rhs->e5 + lhs->e5 * rhs->e2;
  res.e35 =  + lhs->e3 * rhs->e5 + lhs->e5 * rhs->e3;
  res.e45 =  + lhs->e4 * rhs->e5 + lhs->e5 * rhs->e4;
  res.e55 =  + lhs->e5 * rhs->e5;
  res.e16 =  + lhs->e1 * rhs->e6 + lhs->e6 * rhs->e1;
  res.e26 =  + lhs->e2 * rhs->e6 + lhs->e6 * rhs->e2;
  res.e36 =  + lhs->e3 * rhs->e6 + lhs->e6 * rhs->e3;
  res.e46 =  + lhs->e4 * rhs->e6 + lhs->e6 * rhs->e4;
  res.e56 =  + lhs->e5 * rhs->e6 + lhs->e6 * rhs->e5;
  res.e66 =  + lhs->e6 * rhs->e6;

  return res;

}

void onumm6n2_trunc_mul_oo_to(  onumm6n2_t* lhs,  onumm6n2_t* rhs, onumm6n2_t* res){
   (*res) = onumm6n2_init();

  //  Truncated multiplication like function 'lhs * rhs'
  // Order 2;
  res->e11 =  + lhs->e1 * rhs->e1;
  res->e12 =  + lhs->e1 * rhs->e2 + lhs->e2 * rhs->e1;
  res->e22 =  + lhs->e2 * rhs->e2;
  res->e13 =  + lhs->e1 * rhs->e3 + lhs->e3 * rhs->e1;
  res->e23 =  + lhs->e2 * rhs->e3 + lhs->e3 * rhs->e2;
  res->e33 =  + lhs->e3 * rhs->e3;
  res->e14 =  + lhs->e1 * rhs->e4 + lhs->e4 * rhs->e1;
  res->e24 =  + lhs->e2 * rhs->e4 + lhs->e4 * rhs->e2;
  res->e34 =  + lhs->e3 * rhs->e4 + lhs->e4 * rhs->e3;
  res->e44 =  + lhs->e4 * rhs->e4;
  res->e15 =  + lhs->e1 * rhs->e5 + lhs->e5 * rhs->e1;
  res->e25 =  + lhs->e2 * rhs->e5 + lhs->e5 * rhs->e2;
  res->e35 =  + lhs->e3 * rhs->e5 + lhs->e5 * rhs->e3;
  res->e45 =  + lhs->e4 * rhs->e5 + lhs->e5 * rhs->e4;
  res->e55 =  + lhs->e5 * rhs->e5;
  res->e16 =  + lhs->e1 * rhs->e6 + lhs->e6 * rhs->e1;
  res->e26 =  + lhs->e2 * rhs->e6 + lhs->e6 * rhs->e2;
  res->e36 =  + lhs->e3 * rhs->e6 + lhs->e6 * rhs->e3;
  res->e46 =  + lhs->e4 * rhs->e6 + lhs->e6 * rhs->e4;
  res->e56 =  + lhs->e5 * rhs->e6 + lhs->e6 * rhs->e5;
  res->e66 =  + lhs->e6 * rhs->e6;

}

onumm6n2_t onumm6n2_gem_oo(  onumm6n2_t* a,  onumm6n2_t* b,  onumm6n2_t* c){
  onumm6n2_t res;

  //  General multiplication like function 'a * b + c'
  // Real;
  res.r = c->r + a->r * b->r;
  // Order 1;
  res.e1 = c->e1 + a->r * b->e1 + a->e1 * b->r;
  res.e2 = c->e2 + a->r * b->e2 + a->e2 * b->r;
  res.e3 = c->e3 + a->r * b->e3 + a->e3 * b->r;
  res.e4 = c->e4 + a->r * b->e4 + a->e4 * b->r;
  res.e5 = c->e5 + a->r * b->e5 + a->e5 * b->r;
  res.e6 = c->e6 + a->r * b->e6 + a->e6 * b->r;
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
  res.e14 = c->e14 + a->r * b->e14 + a->e14 * b->r + a->e1 * b->e4 
          + a->e4 * b->e1;
  res.e24 = c->e24 + a->r * b->e24 + a->e24 * b->r + a->e2 * b->e4 
          + a->e4 * b->e2;
  res.e34 = c->e34 + a->r * b->e34 + a->e34 * b->r + a->e3 * b->e4 
          + a->e4 * b->e3;
  res.e44 = c->e44 + a->r * b->e44 + a->e44 * b->r + a->e4 * b->e4;
  res.e15 = c->e15 + a->r * b->e15 + a->e15 * b->r + a->e1 * b->e5 
          + a->e5 * b->e1;
  res.e25 = c->e25 + a->r * b->e25 + a->e25 * b->r + a->e2 * b->e5 
          + a->e5 * b->e2;
  res.e35 = c->e35 + a->r * b->e35 + a->e35 * b->r + a->e3 * b->e5 
          + a->e5 * b->e3;
  res.e45 = c->e45 + a->r * b->e45 + a->e45 * b->r + a->e4 * b->e5 
          + a->e5 * b->e4;
  res.e55 = c->e55 + a->r * b->e55 + a->e55 * b->r + a->e5 * b->e5;
  res.e16 = c->e16 + a->r * b->e16 + a->e16 * b->r + a->e1 * b->e6 
          + a->e6 * b->e1;
  res.e26 = c->e26 + a->r * b->e26 + a->e26 * b->r + a->e2 * b->e6 
          + a->e6 * b->e2;
  res.e36 = c->e36 + a->r * b->e36 + a->e36 * b->r + a->e3 * b->e6 
          + a->e6 * b->e3;
  res.e46 = c->e46 + a->r * b->e46 + a->e46 * b->r + a->e4 * b->e6 
          + a->e6 * b->e4;
  res.e56 = c->e56 + a->r * b->e56 + a->e56 * b->r + a->e5 * b->e6 
          + a->e6 * b->e5;
  res.e66 = c->e66 + a->r * b->e66 + a->e66 * b->r + a->e6 * b->e6;

  return res;

}

void onumm6n2_gem_oo_to(  onumm6n2_t* a,  onumm6n2_t* b,  onumm6n2_t* c, onumm6n2_t* res){
  //  General multiplication like function 'a * b + c'
  // Real;
  res->r = c->r + a->r * b->r;
  // Order 1;
  res->e1 = c->e1 + a->r * b->e1 + a->e1 * b->r;
  res->e2 = c->e2 + a->r * b->e2 + a->e2 * b->r;
  res->e3 = c->e3 + a->r * b->e3 + a->e3 * b->r;
  res->e4 = c->e4 + a->r * b->e4 + a->e4 * b->r;
  res->e5 = c->e5 + a->r * b->e5 + a->e5 * b->r;
  res->e6 = c->e6 + a->r * b->e6 + a->e6 * b->r;
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
  res->e14 = c->e14 + a->r * b->e14 + a->e14 * b->r + a->e1 * b->e4 
          + a->e4 * b->e1;
  res->e24 = c->e24 + a->r * b->e24 + a->e24 * b->r + a->e2 * b->e4 
          + a->e4 * b->e2;
  res->e34 = c->e34 + a->r * b->e34 + a->e34 * b->r + a->e3 * b->e4 
          + a->e4 * b->e3;
  res->e44 = c->e44 + a->r * b->e44 + a->e44 * b->r + a->e4 * b->e4;
  res->e15 = c->e15 + a->r * b->e15 + a->e15 * b->r + a->e1 * b->e5 
          + a->e5 * b->e1;
  res->e25 = c->e25 + a->r * b->e25 + a->e25 * b->r + a->e2 * b->e5 
          + a->e5 * b->e2;
  res->e35 = c->e35 + a->r * b->e35 + a->e35 * b->r + a->e3 * b->e5 
          + a->e5 * b->e3;
  res->e45 = c->e45 + a->r * b->e45 + a->e45 * b->r + a->e4 * b->e5 
          + a->e5 * b->e4;
  res->e55 = c->e55 + a->r * b->e55 + a->e55 * b->r + a->e5 * b->e5;
  res->e16 = c->e16 + a->r * b->e16 + a->e16 * b->r + a->e1 * b->e6 
          + a->e6 * b->e1;
  res->e26 = c->e26 + a->r * b->e26 + a->e26 * b->r + a->e2 * b->e6 
          + a->e6 * b->e2;
  res->e36 = c->e36 + a->r * b->e36 + a->e36 * b->r + a->e3 * b->e6 
          + a->e6 * b->e3;
  res->e46 = c->e46 + a->r * b->e46 + a->e46 * b->r + a->e4 * b->e6 
          + a->e6 * b->e4;
  res->e56 = c->e56 + a->r * b->e56 + a->e56 * b->r + a->e5 * b->e6 
          + a->e6 * b->e5;
  res->e66 = c->e66 + a->r * b->e66 + a->e66 * b->r + a->e6 * b->e6;

}

onumm6n2_t onumm6n2_gem_ro(  coeff_t a,  onumm6n2_t* b,  onumm6n2_t* c){
  onumm6n2_t res;

  //  General multiplication like function 'a * b + c'
  // Real;
  res.r = c->r + a * b->r;
  // Order 1;
  res.e1 = c->e1 + a * b->e1;
  res.e2 = c->e2 + a * b->e2;
  res.e3 = c->e3 + a * b->e3;
  res.e4 = c->e4 + a * b->e4;
  res.e5 = c->e5 + a * b->e5;
  res.e6 = c->e6 + a * b->e6;
  // Order 2;
  res.e11 = c->e11 + a * b->e11;
  res.e12 = c->e12 + a * b->e12;
  res.e22 = c->e22 + a * b->e22;
  res.e13 = c->e13 + a * b->e13;
  res.e23 = c->e23 + a * b->e23;
  res.e33 = c->e33 + a * b->e33;
  res.e14 = c->e14 + a * b->e14;
  res.e24 = c->e24 + a * b->e24;
  res.e34 = c->e34 + a * b->e34;
  res.e44 = c->e44 + a * b->e44;
  res.e15 = c->e15 + a * b->e15;
  res.e25 = c->e25 + a * b->e25;
  res.e35 = c->e35 + a * b->e35;
  res.e45 = c->e45 + a * b->e45;
  res.e55 = c->e55 + a * b->e55;
  res.e16 = c->e16 + a * b->e16;
  res.e26 = c->e26 + a * b->e26;
  res.e36 = c->e36 + a * b->e36;
  res.e46 = c->e46 + a * b->e46;
  res.e56 = c->e56 + a * b->e56;
  res.e66 = c->e66 + a * b->e66;

  return res;

}

void onumm6n2_gem_ro_to(  coeff_t a,  onumm6n2_t* b,  onumm6n2_t* c, onumm6n2_t* res){
  //  General multiplication like function 'a * b + c'
  // Real;
  res->r = c->r + a * b->r;
  // Order 1;
  res->e1 = c->e1 + a * b->e1;
  res->e2 = c->e2 + a * b->e2;
  res->e3 = c->e3 + a * b->e3;
  res->e4 = c->e4 + a * b->e4;
  res->e5 = c->e5 + a * b->e5;
  res->e6 = c->e6 + a * b->e6;
  // Order 2;
  res->e11 = c->e11 + a * b->e11;
  res->e12 = c->e12 + a * b->e12;
  res->e22 = c->e22 + a * b->e22;
  res->e13 = c->e13 + a * b->e13;
  res->e23 = c->e23 + a * b->e23;
  res->e33 = c->e33 + a * b->e33;
  res->e14 = c->e14 + a * b->e14;
  res->e24 = c->e24 + a * b->e24;
  res->e34 = c->e34 + a * b->e34;
  res->e44 = c->e44 + a * b->e44;
  res->e15 = c->e15 + a * b->e15;
  res->e25 = c->e25 + a * b->e25;
  res->e35 = c->e35 + a * b->e35;
  res->e45 = c->e45 + a * b->e45;
  res->e55 = c->e55 + a * b->e55;
  res->e16 = c->e16 + a * b->e16;
  res->e26 = c->e26 + a * b->e26;
  res->e36 = c->e36 + a * b->e36;
  res->e46 = c->e46 + a * b->e46;
  res->e56 = c->e56 + a * b->e56;
  res->e66 = c->e66 + a * b->e66;

}

void onumm6n2_trunc_gem_oo_to( ord_t ord_lhs,  onumm6n2_t* a,  ord_t ord_rhs,  onumm6n2_t* b,  onumm6n2_t* c, onumm6n2_t* res){
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
          res->e4 = c->e4 + a->r * b->e4;
          res->e5 = c->e5 + a->r * b->e5;
          res->e6 = c->e6 + a->r * b->e6;
          break;
        case 2:
          // res order: 2
          res->e11 = c->e11 + a->r * b->e11;
          res->e12 = c->e12 + a->r * b->e12;
          res->e22 = c->e22 + a->r * b->e22;
          res->e13 = c->e13 + a->r * b->e13;
          res->e23 = c->e23 + a->r * b->e23;
          res->e33 = c->e33 + a->r * b->e33;
          res->e14 = c->e14 + a->r * b->e14;
          res->e24 = c->e24 + a->r * b->e24;
          res->e34 = c->e34 + a->r * b->e34;
          res->e44 = c->e44 + a->r * b->e44;
          res->e15 = c->e15 + a->r * b->e15;
          res->e25 = c->e25 + a->r * b->e25;
          res->e35 = c->e35 + a->r * b->e35;
          res->e45 = c->e45 + a->r * b->e45;
          res->e55 = c->e55 + a->r * b->e55;
          res->e16 = c->e16 + a->r * b->e16;
          res->e26 = c->e26 + a->r * b->e26;
          res->e36 = c->e36 + a->r * b->e36;
          res->e46 = c->e46 + a->r * b->e46;
          res->e56 = c->e56 + a->r * b->e56;
          res->e66 = c->e66 + a->r * b->e66;
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
          res->e4 = c->e4 + a->e4 * b->r;
          res->e5 = c->e5 + a->e5 * b->r;
          res->e6 = c->e6 + a->e6 * b->r;
          break;
        case 1:
          // res order: 2
          res->e11 = c->e11 + a->e1 * b->e1;
          res->e12 = c->e12 + a->e1 * b->e2 + a->e2 * b->e1;
          res->e22 = c->e22 + a->e2 * b->e2;
          res->e13 = c->e13 + a->e1 * b->e3 + a->e3 * b->e1;
          res->e23 = c->e23 + a->e2 * b->e3 + a->e3 * b->e2;
          res->e33 = c->e33 + a->e3 * b->e3;
          res->e14 = c->e14 + a->e1 * b->e4 + a->e4 * b->e1;
          res->e24 = c->e24 + a->e2 * b->e4 + a->e4 * b->e2;
          res->e34 = c->e34 + a->e3 * b->e4 + a->e4 * b->e3;
          res->e44 = c->e44 + a->e4 * b->e4;
          res->e15 = c->e15 + a->e1 * b->e5 + a->e5 * b->e1;
          res->e25 = c->e25 + a->e2 * b->e5 + a->e5 * b->e2;
          res->e35 = c->e35 + a->e3 * b->e5 + a->e5 * b->e3;
          res->e45 = c->e45 + a->e4 * b->e5 + a->e5 * b->e4;
          res->e55 = c->e55 + a->e5 * b->e5;
          res->e16 = c->e16 + a->e1 * b->e6 + a->e6 * b->e1;
          res->e26 = c->e26 + a->e2 * b->e6 + a->e6 * b->e2;
          res->e36 = c->e36 + a->e3 * b->e6 + a->e6 * b->e3;
          res->e46 = c->e46 + a->e4 * b->e6 + a->e6 * b->e4;
          res->e56 = c->e56 + a->e5 * b->e6 + a->e6 * b->e5;
          res->e66 = c->e66 + a->e6 * b->e6;
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
          res->e14 = c->e14 + a->e14 * b->r;
          res->e24 = c->e24 + a->e24 * b->r;
          res->e34 = c->e34 + a->e34 * b->r;
          res->e44 = c->e44 + a->e44 * b->r;
          res->e15 = c->e15 + a->e15 * b->r;
          res->e25 = c->e25 + a->e25 * b->r;
          res->e35 = c->e35 + a->e35 * b->r;
          res->e45 = c->e45 + a->e45 * b->r;
          res->e55 = c->e55 + a->e55 * b->r;
          res->e16 = c->e16 + a->e16 * b->r;
          res->e26 = c->e26 + a->e26 * b->r;
          res->e36 = c->e36 + a->e36 * b->r;
          res->e46 = c->e46 + a->e46 * b->r;
          res->e56 = c->e56 + a->e56 * b->r;
          res->e66 = c->e66 + a->e66 * b->r;
          break;
      }
      break;
  }

}

void onumm6n2_trunc_sum_oo_to(ord_t order, onumm6n2_t* lhs,onumm6n2_t* rhs, onumm6n2_t* res){
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
      res->e4 = lhs->e4 + rhs->e4;
      res->e5 = lhs->e5 + rhs->e5;
      res->e6 = lhs->e6 + rhs->e6;
      break;
    case(2):    // Order 2
      res->e11 = lhs->e11 + rhs->e11;
      res->e12 = lhs->e12 + rhs->e12;
      res->e22 = lhs->e22 + rhs->e22;
      res->e13 = lhs->e13 + rhs->e13;
      res->e23 = lhs->e23 + rhs->e23;
      res->e33 = lhs->e33 + rhs->e33;
      res->e14 = lhs->e14 + rhs->e14;
      res->e24 = lhs->e24 + rhs->e24;
      res->e34 = lhs->e34 + rhs->e34;
      res->e44 = lhs->e44 + rhs->e44;
      res->e15 = lhs->e15 + rhs->e15;
      res->e25 = lhs->e25 + rhs->e25;
      res->e35 = lhs->e35 + rhs->e35;
      res->e45 = lhs->e45 + rhs->e45;
      res->e55 = lhs->e55 + rhs->e55;
      res->e16 = lhs->e16 + rhs->e16;
      res->e26 = lhs->e26 + rhs->e26;
      res->e36 = lhs->e36 + rhs->e36;
      res->e46 = lhs->e46 + rhs->e46;
      res->e56 = lhs->e56 + rhs->e56;
      res->e66 = lhs->e66 + rhs->e66;
      break;
  }
}

void onumm6n2_trunc_sub_oo_to(ord_t order, onumm6n2_t* lhs,onumm6n2_t* rhs, onumm6n2_t* res){
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
      res->e4 = lhs->e4 - rhs->e4;
      res->e5 = lhs->e5 - rhs->e5;
      res->e6 = lhs->e6 - rhs->e6;
      break;
    case(2):    // Order 2
      res->e11 = lhs->e11 - rhs->e11;
      res->e12 = lhs->e12 - rhs->e12;
      res->e22 = lhs->e22 - rhs->e22;
      res->e13 = lhs->e13 - rhs->e13;
      res->e23 = lhs->e23 - rhs->e23;
      res->e33 = lhs->e33 - rhs->e33;
      res->e14 = lhs->e14 - rhs->e14;
      res->e24 = lhs->e24 - rhs->e24;
      res->e34 = lhs->e34 - rhs->e34;
      res->e44 = lhs->e44 - rhs->e44;
      res->e15 = lhs->e15 - rhs->e15;
      res->e25 = lhs->e25 - rhs->e25;
      res->e35 = lhs->e35 - rhs->e35;
      res->e45 = lhs->e45 - rhs->e45;
      res->e55 = lhs->e55 - rhs->e55;
      res->e16 = lhs->e16 - rhs->e16;
      res->e26 = lhs->e26 - rhs->e26;
      res->e36 = lhs->e36 - rhs->e36;
      res->e46 = lhs->e46 - rhs->e46;
      res->e56 = lhs->e56 - rhs->e56;
      res->e66 = lhs->e66 - rhs->e66;
      break;
  }
}

onumm6n2_t onumm6n2_feval(coeff_t* feval_re, onumm6n2_t* x){

  onumm6n2_t res;

  // feval function
  //  Definitions
  coeff_t factor=1, coef = 0;
  onumm6n2_t deltax = (*x), deltax_power = (*x);
  deltax.r = 0.0;
  deltax_power.r = 0.0;
  onumm6n2_set_r(0.0, &res);
  //  Real
  res.r = feval_re[0];
  // Order 1
  factor *=1;
  coef    = feval_re[1]/ factor;;
  onumm6n2_gem_ro_to( coef, &deltax_power, &res, &res);
  deltax_power = onumm6n2_mul_oo(&deltax_power,&deltax);
  // Order 2
  factor *=2;
  coef    = feval_re[2]/ factor;;
  onumm6n2_gem_ro_to( coef, &deltax_power, &res, &res);

  return res;

}

void onumm6n2_feval_to(coeff_t* feval_re, onumm6n2_t* x, onumm6n2_t* res){

  // feval function
  //  Definitions
  coeff_t factor=1, coef = 0;
  onumm6n2_t deltax = (*x), deltax_power = (*x);
  deltax.r = 0.0;
  deltax_power.r = 0.0;
  onumm6n2_set_r(0.0, res);
  //  Real
  res->r = feval_re[0];
  // Order 1
  factor *=1;
  coef    = feval_re[1]/ factor;;
  onumm6n2_gem_ro_to( coef, &deltax_power, res, res);
  deltax_power = onumm6n2_mul_oo(&deltax_power,&deltax);
  // Order 2
  factor *=2;
  coef    = feval_re[2]/ factor;;
  onumm6n2_gem_ro_to( coef, &deltax_power, res, res);

}

