
// Division.

// ****************************************************************************************************
onumm9n2_t onumm9n2_div_ro(coeff_t num, onumm9n2_t* den){

    
    onumm9n2_t inv = onumm9n2_pow(den,-1);
    onumm9n2_t res = onumm9n2_mul_ro(num,&inv);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
onumm9n2_t onumm9n2_div_oo(onumm9n2_t* num, onumm9n2_t* den){

    
    onumm9n2_t inv = onumm9n2_init();
    onumm9n2_pow_to(den,-1,&inv);
    onumm9n2_t res = onumm9n2_mul_oo(num,&inv);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
onumm9n2_t onumm9n2_div_or(onumm9n2_t* num, coeff_t val){

    return onumm9n2_mul_ro(1.0/val,num);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
onumm9n2_t onumm9n2_abs(onumm9n2_t* num){

	onumm9n2_t res;
    onumm9n2_abs_to(num,&res);
    return res;

}
// ----------------------------------------------------------------------------------------------------

onumm9n2_t onumm9n2_neg(  onumm9n2_t* lhs){

  onumm9n2_t res;

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
  res.e7 = -lhs->e7;
  res.e8 = -lhs->e8;
  res.e9 = -lhs->e9;
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
  res.e17 = -lhs->e17;
  res.e27 = -lhs->e27;
  res.e37 = -lhs->e37;
  res.e47 = -lhs->e47;
  res.e57 = -lhs->e57;
  res.e67 = -lhs->e67;
  res.e77 = -lhs->e77;
  res.e18 = -lhs->e18;
  res.e28 = -lhs->e28;
  res.e38 = -lhs->e38;
  res.e48 = -lhs->e48;
  res.e58 = -lhs->e58;
  res.e68 = -lhs->e68;
  res.e78 = -lhs->e78;
  res.e88 = -lhs->e88;
  res.e19 = -lhs->e19;
  res.e29 = -lhs->e29;
  res.e39 = -lhs->e39;
  res.e49 = -lhs->e49;
  res.e59 = -lhs->e59;
  res.e69 = -lhs->e69;
  res.e79 = -lhs->e79;
  res.e89 = -lhs->e89;
  res.e99 = -lhs->e99;

  return res;

}

void onumm9n2_neg_to(  onumm9n2_t* lhs, onumm9n2_t* res){

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
  res->e7 = -lhs->e7;
  res->e8 = -lhs->e8;
  res->e9 = -lhs->e9;
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
  res->e17 = -lhs->e17;
  res->e27 = -lhs->e27;
  res->e37 = -lhs->e37;
  res->e47 = -lhs->e47;
  res->e57 = -lhs->e57;
  res->e67 = -lhs->e67;
  res->e77 = -lhs->e77;
  res->e18 = -lhs->e18;
  res->e28 = -lhs->e28;
  res->e38 = -lhs->e38;
  res->e48 = -lhs->e48;
  res->e58 = -lhs->e58;
  res->e68 = -lhs->e68;
  res->e78 = -lhs->e78;
  res->e88 = -lhs->e88;
  res->e19 = -lhs->e19;
  res->e29 = -lhs->e29;
  res->e39 = -lhs->e39;
  res->e49 = -lhs->e49;
  res->e59 = -lhs->e59;
  res->e69 = -lhs->e69;
  res->e79 = -lhs->e79;
  res->e89 = -lhs->e89;
  res->e99 = -lhs->e99;

}

onumm9n2_t onumm9n2_sum_oo(  onumm9n2_t* lhs,  onumm9n2_t* rhs){
  onumm9n2_t res;

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
  res.e7 = lhs->e7 + rhs->e7;
  res.e8 = lhs->e8 + rhs->e8;
  res.e9 = lhs->e9 + rhs->e9;
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
  res.e17 = lhs->e17 + rhs->e17;
  res.e27 = lhs->e27 + rhs->e27;
  res.e37 = lhs->e37 + rhs->e37;
  res.e47 = lhs->e47 + rhs->e47;
  res.e57 = lhs->e57 + rhs->e57;
  res.e67 = lhs->e67 + rhs->e67;
  res.e77 = lhs->e77 + rhs->e77;
  res.e18 = lhs->e18 + rhs->e18;
  res.e28 = lhs->e28 + rhs->e28;
  res.e38 = lhs->e38 + rhs->e38;
  res.e48 = lhs->e48 + rhs->e48;
  res.e58 = lhs->e58 + rhs->e58;
  res.e68 = lhs->e68 + rhs->e68;
  res.e78 = lhs->e78 + rhs->e78;
  res.e88 = lhs->e88 + rhs->e88;
  res.e19 = lhs->e19 + rhs->e19;
  res.e29 = lhs->e29 + rhs->e29;
  res.e39 = lhs->e39 + rhs->e39;
  res.e49 = lhs->e49 + rhs->e49;
  res.e59 = lhs->e59 + rhs->e59;
  res.e69 = lhs->e69 + rhs->e69;
  res.e79 = lhs->e79 + rhs->e79;
  res.e89 = lhs->e89 + rhs->e89;
  res.e99 = lhs->e99 + rhs->e99;

  return res;

}

void onumm9n2_sum_oo_to(  onumm9n2_t* lhs,  onumm9n2_t* rhs, onumm9n2_t* res){
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
  res->e7 = lhs->e7 + rhs->e7;
  res->e8 = lhs->e8 + rhs->e8;
  res->e9 = lhs->e9 + rhs->e9;
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
  res->e17 = lhs->e17 + rhs->e17;
  res->e27 = lhs->e27 + rhs->e27;
  res->e37 = lhs->e37 + rhs->e37;
  res->e47 = lhs->e47 + rhs->e47;
  res->e57 = lhs->e57 + rhs->e57;
  res->e67 = lhs->e67 + rhs->e67;
  res->e77 = lhs->e77 + rhs->e77;
  res->e18 = lhs->e18 + rhs->e18;
  res->e28 = lhs->e28 + rhs->e28;
  res->e38 = lhs->e38 + rhs->e38;
  res->e48 = lhs->e48 + rhs->e48;
  res->e58 = lhs->e58 + rhs->e58;
  res->e68 = lhs->e68 + rhs->e68;
  res->e78 = lhs->e78 + rhs->e78;
  res->e88 = lhs->e88 + rhs->e88;
  res->e19 = lhs->e19 + rhs->e19;
  res->e29 = lhs->e29 + rhs->e29;
  res->e39 = lhs->e39 + rhs->e39;
  res->e49 = lhs->e49 + rhs->e49;
  res->e59 = lhs->e59 + rhs->e59;
  res->e69 = lhs->e69 + rhs->e69;
  res->e79 = lhs->e79 + rhs->e79;
  res->e89 = lhs->e89 + rhs->e89;
  res->e99 = lhs->e99 + rhs->e99;

}

onumm9n2_t onumm9n2_sum_ro(  coeff_t lhs,  onumm9n2_t* rhs){
  onumm9n2_t res;

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
  res.e7 =  + rhs->e7;
  res.e8 =  + rhs->e8;
  res.e9 =  + rhs->e9;
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
  res.e17 =  + rhs->e17;
  res.e27 =  + rhs->e27;
  res.e37 =  + rhs->e37;
  res.e47 =  + rhs->e47;
  res.e57 =  + rhs->e57;
  res.e67 =  + rhs->e67;
  res.e77 =  + rhs->e77;
  res.e18 =  + rhs->e18;
  res.e28 =  + rhs->e28;
  res.e38 =  + rhs->e38;
  res.e48 =  + rhs->e48;
  res.e58 =  + rhs->e58;
  res.e68 =  + rhs->e68;
  res.e78 =  + rhs->e78;
  res.e88 =  + rhs->e88;
  res.e19 =  + rhs->e19;
  res.e29 =  + rhs->e29;
  res.e39 =  + rhs->e39;
  res.e49 =  + rhs->e49;
  res.e59 =  + rhs->e59;
  res.e69 =  + rhs->e69;
  res.e79 =  + rhs->e79;
  res.e89 =  + rhs->e89;
  res.e99 =  + rhs->e99;

  return res;

}

void onumm9n2_sum_ro_to(  coeff_t lhs,  onumm9n2_t* rhs, onumm9n2_t* res){
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
  res->e7 =  + rhs->e7;
  res->e8 =  + rhs->e8;
  res->e9 =  + rhs->e9;
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
  res->e17 =  + rhs->e17;
  res->e27 =  + rhs->e27;
  res->e37 =  + rhs->e37;
  res->e47 =  + rhs->e47;
  res->e57 =  + rhs->e57;
  res->e67 =  + rhs->e67;
  res->e77 =  + rhs->e77;
  res->e18 =  + rhs->e18;
  res->e28 =  + rhs->e28;
  res->e38 =  + rhs->e38;
  res->e48 =  + rhs->e48;
  res->e58 =  + rhs->e58;
  res->e68 =  + rhs->e68;
  res->e78 =  + rhs->e78;
  res->e88 =  + rhs->e88;
  res->e19 =  + rhs->e19;
  res->e29 =  + rhs->e29;
  res->e39 =  + rhs->e39;
  res->e49 =  + rhs->e49;
  res->e59 =  + rhs->e59;
  res->e69 =  + rhs->e69;
  res->e79 =  + rhs->e79;
  res->e89 =  + rhs->e89;
  res->e99 =  + rhs->e99;

}

onumm9n2_t onumm9n2_sub_oo(  onumm9n2_t* lhs,  onumm9n2_t* rhs){
  onumm9n2_t res;

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
  res.e7 = lhs->e7 - rhs->e7;
  res.e8 = lhs->e8 - rhs->e8;
  res.e9 = lhs->e9 - rhs->e9;
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
  res.e17 = lhs->e17 - rhs->e17;
  res.e27 = lhs->e27 - rhs->e27;
  res.e37 = lhs->e37 - rhs->e37;
  res.e47 = lhs->e47 - rhs->e47;
  res.e57 = lhs->e57 - rhs->e57;
  res.e67 = lhs->e67 - rhs->e67;
  res.e77 = lhs->e77 - rhs->e77;
  res.e18 = lhs->e18 - rhs->e18;
  res.e28 = lhs->e28 - rhs->e28;
  res.e38 = lhs->e38 - rhs->e38;
  res.e48 = lhs->e48 - rhs->e48;
  res.e58 = lhs->e58 - rhs->e58;
  res.e68 = lhs->e68 - rhs->e68;
  res.e78 = lhs->e78 - rhs->e78;
  res.e88 = lhs->e88 - rhs->e88;
  res.e19 = lhs->e19 - rhs->e19;
  res.e29 = lhs->e29 - rhs->e29;
  res.e39 = lhs->e39 - rhs->e39;
  res.e49 = lhs->e49 - rhs->e49;
  res.e59 = lhs->e59 - rhs->e59;
  res.e69 = lhs->e69 - rhs->e69;
  res.e79 = lhs->e79 - rhs->e79;
  res.e89 = lhs->e89 - rhs->e89;
  res.e99 = lhs->e99 - rhs->e99;

  return res;

}

void onumm9n2_sub_oo_to(  onumm9n2_t* lhs,  onumm9n2_t* rhs, onumm9n2_t* res){
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
  res->e7 = lhs->e7 - rhs->e7;
  res->e8 = lhs->e8 - rhs->e8;
  res->e9 = lhs->e9 - rhs->e9;
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
  res->e17 = lhs->e17 - rhs->e17;
  res->e27 = lhs->e27 - rhs->e27;
  res->e37 = lhs->e37 - rhs->e37;
  res->e47 = lhs->e47 - rhs->e47;
  res->e57 = lhs->e57 - rhs->e57;
  res->e67 = lhs->e67 - rhs->e67;
  res->e77 = lhs->e77 - rhs->e77;
  res->e18 = lhs->e18 - rhs->e18;
  res->e28 = lhs->e28 - rhs->e28;
  res->e38 = lhs->e38 - rhs->e38;
  res->e48 = lhs->e48 - rhs->e48;
  res->e58 = lhs->e58 - rhs->e58;
  res->e68 = lhs->e68 - rhs->e68;
  res->e78 = lhs->e78 - rhs->e78;
  res->e88 = lhs->e88 - rhs->e88;
  res->e19 = lhs->e19 - rhs->e19;
  res->e29 = lhs->e29 - rhs->e29;
  res->e39 = lhs->e39 - rhs->e39;
  res->e49 = lhs->e49 - rhs->e49;
  res->e59 = lhs->e59 - rhs->e59;
  res->e69 = lhs->e69 - rhs->e69;
  res->e79 = lhs->e79 - rhs->e79;
  res->e89 = lhs->e89 - rhs->e89;
  res->e99 = lhs->e99 - rhs->e99;

}

onumm9n2_t onumm9n2_sub_ro(  coeff_t lhs,  onumm9n2_t* rhs){
  onumm9n2_t res;

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
  res.e7 =  - rhs->e7;
  res.e8 =  - rhs->e8;
  res.e9 =  - rhs->e9;
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
  res.e17 =  - rhs->e17;
  res.e27 =  - rhs->e27;
  res.e37 =  - rhs->e37;
  res.e47 =  - rhs->e47;
  res.e57 =  - rhs->e57;
  res.e67 =  - rhs->e67;
  res.e77 =  - rhs->e77;
  res.e18 =  - rhs->e18;
  res.e28 =  - rhs->e28;
  res.e38 =  - rhs->e38;
  res.e48 =  - rhs->e48;
  res.e58 =  - rhs->e58;
  res.e68 =  - rhs->e68;
  res.e78 =  - rhs->e78;
  res.e88 =  - rhs->e88;
  res.e19 =  - rhs->e19;
  res.e29 =  - rhs->e29;
  res.e39 =  - rhs->e39;
  res.e49 =  - rhs->e49;
  res.e59 =  - rhs->e59;
  res.e69 =  - rhs->e69;
  res.e79 =  - rhs->e79;
  res.e89 =  - rhs->e89;
  res.e99 =  - rhs->e99;

  return res;

}

void onumm9n2_sub_ro_to(  coeff_t lhs,  onumm9n2_t* rhs, onumm9n2_t* res){
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
  res->e7 =  - rhs->e7;
  res->e8 =  - rhs->e8;
  res->e9 =  - rhs->e9;
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
  res->e17 =  - rhs->e17;
  res->e27 =  - rhs->e27;
  res->e37 =  - rhs->e37;
  res->e47 =  - rhs->e47;
  res->e57 =  - rhs->e57;
  res->e67 =  - rhs->e67;
  res->e77 =  - rhs->e77;
  res->e18 =  - rhs->e18;
  res->e28 =  - rhs->e28;
  res->e38 =  - rhs->e38;
  res->e48 =  - rhs->e48;
  res->e58 =  - rhs->e58;
  res->e68 =  - rhs->e68;
  res->e78 =  - rhs->e78;
  res->e88 =  - rhs->e88;
  res->e19 =  - rhs->e19;
  res->e29 =  - rhs->e29;
  res->e39 =  - rhs->e39;
  res->e49 =  - rhs->e49;
  res->e59 =  - rhs->e59;
  res->e69 =  - rhs->e69;
  res->e79 =  - rhs->e79;
  res->e89 =  - rhs->e89;
  res->e99 =  - rhs->e99;

}

onumm9n2_t onumm9n2_sub_or(  onumm9n2_t* lhs,  coeff_t rhs){
  onumm9n2_t res;

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
  res.e7 = lhs->e7;
  res.e8 = lhs->e8;
  res.e9 = lhs->e9;
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
  res.e17 = lhs->e17;
  res.e27 = lhs->e27;
  res.e37 = lhs->e37;
  res.e47 = lhs->e47;
  res.e57 = lhs->e57;
  res.e67 = lhs->e67;
  res.e77 = lhs->e77;
  res.e18 = lhs->e18;
  res.e28 = lhs->e28;
  res.e38 = lhs->e38;
  res.e48 = lhs->e48;
  res.e58 = lhs->e58;
  res.e68 = lhs->e68;
  res.e78 = lhs->e78;
  res.e88 = lhs->e88;
  res.e19 = lhs->e19;
  res.e29 = lhs->e29;
  res.e39 = lhs->e39;
  res.e49 = lhs->e49;
  res.e59 = lhs->e59;
  res.e69 = lhs->e69;
  res.e79 = lhs->e79;
  res.e89 = lhs->e89;
  res.e99 = lhs->e99;

  return res;

}

void onumm9n2_sub_or_to(  onumm9n2_t* lhs,  coeff_t rhs, onumm9n2_t* res){
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
  res->e7 = lhs->e7;
  res->e8 = lhs->e8;
  res->e9 = lhs->e9;
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
  res->e17 = lhs->e17;
  res->e27 = lhs->e27;
  res->e37 = lhs->e37;
  res->e47 = lhs->e47;
  res->e57 = lhs->e57;
  res->e67 = lhs->e67;
  res->e77 = lhs->e77;
  res->e18 = lhs->e18;
  res->e28 = lhs->e28;
  res->e38 = lhs->e38;
  res->e48 = lhs->e48;
  res->e58 = lhs->e58;
  res->e68 = lhs->e68;
  res->e78 = lhs->e78;
  res->e88 = lhs->e88;
  res->e19 = lhs->e19;
  res->e29 = lhs->e29;
  res->e39 = lhs->e39;
  res->e49 = lhs->e49;
  res->e59 = lhs->e59;
  res->e69 = lhs->e69;
  res->e79 = lhs->e79;
  res->e89 = lhs->e89;
  res->e99 = lhs->e99;

}

onumm9n2_t onumm9n2_mul_oo(  onumm9n2_t* lhs,  onumm9n2_t* rhs){
  onumm9n2_t res;

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
  res.e7 = lhs->r * rhs->e7 + lhs->e7 * rhs->r;
  res.e8 = lhs->r * rhs->e8 + lhs->e8 * rhs->r;
  res.e9 = lhs->r * rhs->e9 + lhs->e9 * rhs->r;
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
  res.e17 = lhs->r * rhs->e17 + lhs->e17 * rhs->r + lhs->e1 * rhs->e7 
          + lhs->e7 * rhs->e1;
  res.e27 = lhs->r * rhs->e27 + lhs->e27 * rhs->r + lhs->e2 * rhs->e7 
          + lhs->e7 * rhs->e2;
  res.e37 = lhs->r * rhs->e37 + lhs->e37 * rhs->r + lhs->e3 * rhs->e7 
          + lhs->e7 * rhs->e3;
  res.e47 = lhs->r * rhs->e47 + lhs->e47 * rhs->r + lhs->e4 * rhs->e7 
          + lhs->e7 * rhs->e4;
  res.e57 = lhs->r * rhs->e57 + lhs->e57 * rhs->r + lhs->e5 * rhs->e7 
          + lhs->e7 * rhs->e5;
  res.e67 = lhs->r * rhs->e67 + lhs->e67 * rhs->r + lhs->e6 * rhs->e7 
          + lhs->e7 * rhs->e6;
  res.e77 = lhs->r * rhs->e77 + lhs->e77 * rhs->r + lhs->e7 * rhs->e7;
  res.e18 = lhs->r * rhs->e18 + lhs->e18 * rhs->r + lhs->e1 * rhs->e8 
          + lhs->e8 * rhs->e1;
  res.e28 = lhs->r * rhs->e28 + lhs->e28 * rhs->r + lhs->e2 * rhs->e8 
          + lhs->e8 * rhs->e2;
  res.e38 = lhs->r * rhs->e38 + lhs->e38 * rhs->r + lhs->e3 * rhs->e8 
          + lhs->e8 * rhs->e3;
  res.e48 = lhs->r * rhs->e48 + lhs->e48 * rhs->r + lhs->e4 * rhs->e8 
          + lhs->e8 * rhs->e4;
  res.e58 = lhs->r * rhs->e58 + lhs->e58 * rhs->r + lhs->e5 * rhs->e8 
          + lhs->e8 * rhs->e5;
  res.e68 = lhs->r * rhs->e68 + lhs->e68 * rhs->r + lhs->e6 * rhs->e8 
          + lhs->e8 * rhs->e6;
  res.e78 = lhs->r * rhs->e78 + lhs->e78 * rhs->r + lhs->e7 * rhs->e8 
          + lhs->e8 * rhs->e7;
  res.e88 = lhs->r * rhs->e88 + lhs->e88 * rhs->r + lhs->e8 * rhs->e8;
  res.e19 = lhs->r * rhs->e19 + lhs->e19 * rhs->r + lhs->e1 * rhs->e9 
          + lhs->e9 * rhs->e1;
  res.e29 = lhs->r * rhs->e29 + lhs->e29 * rhs->r + lhs->e2 * rhs->e9 
          + lhs->e9 * rhs->e2;
  res.e39 = lhs->r * rhs->e39 + lhs->e39 * rhs->r + lhs->e3 * rhs->e9 
          + lhs->e9 * rhs->e3;
  res.e49 = lhs->r * rhs->e49 + lhs->e49 * rhs->r + lhs->e4 * rhs->e9 
          + lhs->e9 * rhs->e4;
  res.e59 = lhs->r * rhs->e59 + lhs->e59 * rhs->r + lhs->e5 * rhs->e9 
          + lhs->e9 * rhs->e5;
  res.e69 = lhs->r * rhs->e69 + lhs->e69 * rhs->r + lhs->e6 * rhs->e9 
          + lhs->e9 * rhs->e6;
  res.e79 = lhs->r * rhs->e79 + lhs->e79 * rhs->r + lhs->e7 * rhs->e9 
          + lhs->e9 * rhs->e7;
  res.e89 = lhs->r * rhs->e89 + lhs->e89 * rhs->r + lhs->e8 * rhs->e9 
          + lhs->e9 * rhs->e8;
  res.e99 = lhs->r * rhs->e99 + lhs->e99 * rhs->r + lhs->e9 * rhs->e9;

  return res;

}

void onumm9n2_mul_oo_to(  onumm9n2_t* lhs,  onumm9n2_t* rhs, onumm9n2_t* res){
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
  res->e7 = lhs->r * rhs->e7 + lhs->e7 * rhs->r;
  res->e8 = lhs->r * rhs->e8 + lhs->e8 * rhs->r;
  res->e9 = lhs->r * rhs->e9 + lhs->e9 * rhs->r;
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
  res->e17 = lhs->r * rhs->e17 + lhs->e17 * rhs->r + lhs->e1 * rhs->e7 
          + lhs->e7 * rhs->e1;
  res->e27 = lhs->r * rhs->e27 + lhs->e27 * rhs->r + lhs->e2 * rhs->e7 
          + lhs->e7 * rhs->e2;
  res->e37 = lhs->r * rhs->e37 + lhs->e37 * rhs->r + lhs->e3 * rhs->e7 
          + lhs->e7 * rhs->e3;
  res->e47 = lhs->r * rhs->e47 + lhs->e47 * rhs->r + lhs->e4 * rhs->e7 
          + lhs->e7 * rhs->e4;
  res->e57 = lhs->r * rhs->e57 + lhs->e57 * rhs->r + lhs->e5 * rhs->e7 
          + lhs->e7 * rhs->e5;
  res->e67 = lhs->r * rhs->e67 + lhs->e67 * rhs->r + lhs->e6 * rhs->e7 
          + lhs->e7 * rhs->e6;
  res->e77 = lhs->r * rhs->e77 + lhs->e77 * rhs->r + lhs->e7 * rhs->e7;
  res->e18 = lhs->r * rhs->e18 + lhs->e18 * rhs->r + lhs->e1 * rhs->e8 
          + lhs->e8 * rhs->e1;
  res->e28 = lhs->r * rhs->e28 + lhs->e28 * rhs->r + lhs->e2 * rhs->e8 
          + lhs->e8 * rhs->e2;
  res->e38 = lhs->r * rhs->e38 + lhs->e38 * rhs->r + lhs->e3 * rhs->e8 
          + lhs->e8 * rhs->e3;
  res->e48 = lhs->r * rhs->e48 + lhs->e48 * rhs->r + lhs->e4 * rhs->e8 
          + lhs->e8 * rhs->e4;
  res->e58 = lhs->r * rhs->e58 + lhs->e58 * rhs->r + lhs->e5 * rhs->e8 
          + lhs->e8 * rhs->e5;
  res->e68 = lhs->r * rhs->e68 + lhs->e68 * rhs->r + lhs->e6 * rhs->e8 
          + lhs->e8 * rhs->e6;
  res->e78 = lhs->r * rhs->e78 + lhs->e78 * rhs->r + lhs->e7 * rhs->e8 
          + lhs->e8 * rhs->e7;
  res->e88 = lhs->r * rhs->e88 + lhs->e88 * rhs->r + lhs->e8 * rhs->e8;
  res->e19 = lhs->r * rhs->e19 + lhs->e19 * rhs->r + lhs->e1 * rhs->e9 
          + lhs->e9 * rhs->e1;
  res->e29 = lhs->r * rhs->e29 + lhs->e29 * rhs->r + lhs->e2 * rhs->e9 
          + lhs->e9 * rhs->e2;
  res->e39 = lhs->r * rhs->e39 + lhs->e39 * rhs->r + lhs->e3 * rhs->e9 
          + lhs->e9 * rhs->e3;
  res->e49 = lhs->r * rhs->e49 + lhs->e49 * rhs->r + lhs->e4 * rhs->e9 
          + lhs->e9 * rhs->e4;
  res->e59 = lhs->r * rhs->e59 + lhs->e59 * rhs->r + lhs->e5 * rhs->e9 
          + lhs->e9 * rhs->e5;
  res->e69 = lhs->r * rhs->e69 + lhs->e69 * rhs->r + lhs->e6 * rhs->e9 
          + lhs->e9 * rhs->e6;
  res->e79 = lhs->r * rhs->e79 + lhs->e79 * rhs->r + lhs->e7 * rhs->e9 
          + lhs->e9 * rhs->e7;
  res->e89 = lhs->r * rhs->e89 + lhs->e89 * rhs->r + lhs->e8 * rhs->e9 
          + lhs->e9 * rhs->e8;
  res->e99 = lhs->r * rhs->e99 + lhs->e99 * rhs->r + lhs->e9 * rhs->e9;

}

onumm9n2_t onumm9n2_mul_ro(  coeff_t lhs,  onumm9n2_t* rhs){
  onumm9n2_t res;

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
  res.e7 = lhs * rhs->e7;
  res.e8 = lhs * rhs->e8;
  res.e9 = lhs * rhs->e9;
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
  res.e17 = lhs * rhs->e17;
  res.e27 = lhs * rhs->e27;
  res.e37 = lhs * rhs->e37;
  res.e47 = lhs * rhs->e47;
  res.e57 = lhs * rhs->e57;
  res.e67 = lhs * rhs->e67;
  res.e77 = lhs * rhs->e77;
  res.e18 = lhs * rhs->e18;
  res.e28 = lhs * rhs->e28;
  res.e38 = lhs * rhs->e38;
  res.e48 = lhs * rhs->e48;
  res.e58 = lhs * rhs->e58;
  res.e68 = lhs * rhs->e68;
  res.e78 = lhs * rhs->e78;
  res.e88 = lhs * rhs->e88;
  res.e19 = lhs * rhs->e19;
  res.e29 = lhs * rhs->e29;
  res.e39 = lhs * rhs->e39;
  res.e49 = lhs * rhs->e49;
  res.e59 = lhs * rhs->e59;
  res.e69 = lhs * rhs->e69;
  res.e79 = lhs * rhs->e79;
  res.e89 = lhs * rhs->e89;
  res.e99 = lhs * rhs->e99;

  return res;

}

void onumm9n2_mul_ro_to(  coeff_t lhs,  onumm9n2_t* rhs, onumm9n2_t* res){
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
  res->e7 = lhs * rhs->e7;
  res->e8 = lhs * rhs->e8;
  res->e9 = lhs * rhs->e9;
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
  res->e17 = lhs * rhs->e17;
  res->e27 = lhs * rhs->e27;
  res->e37 = lhs * rhs->e37;
  res->e47 = lhs * rhs->e47;
  res->e57 = lhs * rhs->e57;
  res->e67 = lhs * rhs->e67;
  res->e77 = lhs * rhs->e77;
  res->e18 = lhs * rhs->e18;
  res->e28 = lhs * rhs->e28;
  res->e38 = lhs * rhs->e38;
  res->e48 = lhs * rhs->e48;
  res->e58 = lhs * rhs->e58;
  res->e68 = lhs * rhs->e68;
  res->e78 = lhs * rhs->e78;
  res->e88 = lhs * rhs->e88;
  res->e19 = lhs * rhs->e19;
  res->e29 = lhs * rhs->e29;
  res->e39 = lhs * rhs->e39;
  res->e49 = lhs * rhs->e49;
  res->e59 = lhs * rhs->e59;
  res->e69 = lhs * rhs->e69;
  res->e79 = lhs * rhs->e79;
  res->e89 = lhs * rhs->e89;
  res->e99 = lhs * rhs->e99;

}

onumm9n2_t onumm9n2_trunc_mul_oo(  onumm9n2_t* lhs,  onumm9n2_t* rhs){
  onumm9n2_t res;

  res = onumm9n2_init();

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
  res.e17 =  + lhs->e1 * rhs->e7 + lhs->e7 * rhs->e1;
  res.e27 =  + lhs->e2 * rhs->e7 + lhs->e7 * rhs->e2;
  res.e37 =  + lhs->e3 * rhs->e7 + lhs->e7 * rhs->e3;
  res.e47 =  + lhs->e4 * rhs->e7 + lhs->e7 * rhs->e4;
  res.e57 =  + lhs->e5 * rhs->e7 + lhs->e7 * rhs->e5;
  res.e67 =  + lhs->e6 * rhs->e7 + lhs->e7 * rhs->e6;
  res.e77 =  + lhs->e7 * rhs->e7;
  res.e18 =  + lhs->e1 * rhs->e8 + lhs->e8 * rhs->e1;
  res.e28 =  + lhs->e2 * rhs->e8 + lhs->e8 * rhs->e2;
  res.e38 =  + lhs->e3 * rhs->e8 + lhs->e8 * rhs->e3;
  res.e48 =  + lhs->e4 * rhs->e8 + lhs->e8 * rhs->e4;
  res.e58 =  + lhs->e5 * rhs->e8 + lhs->e8 * rhs->e5;
  res.e68 =  + lhs->e6 * rhs->e8 + lhs->e8 * rhs->e6;
  res.e78 =  + lhs->e7 * rhs->e8 + lhs->e8 * rhs->e7;
  res.e88 =  + lhs->e8 * rhs->e8;
  res.e19 =  + lhs->e1 * rhs->e9 + lhs->e9 * rhs->e1;
  res.e29 =  + lhs->e2 * rhs->e9 + lhs->e9 * rhs->e2;
  res.e39 =  + lhs->e3 * rhs->e9 + lhs->e9 * rhs->e3;
  res.e49 =  + lhs->e4 * rhs->e9 + lhs->e9 * rhs->e4;
  res.e59 =  + lhs->e5 * rhs->e9 + lhs->e9 * rhs->e5;
  res.e69 =  + lhs->e6 * rhs->e9 + lhs->e9 * rhs->e6;
  res.e79 =  + lhs->e7 * rhs->e9 + lhs->e9 * rhs->e7;
  res.e89 =  + lhs->e8 * rhs->e9 + lhs->e9 * rhs->e8;
  res.e99 =  + lhs->e9 * rhs->e9;

  return res;

}

void onumm9n2_trunc_mul_oo_to(  onumm9n2_t* lhs,  onumm9n2_t* rhs, onumm9n2_t* res){
   (*res) = onumm9n2_init();

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
  res->e17 =  + lhs->e1 * rhs->e7 + lhs->e7 * rhs->e1;
  res->e27 =  + lhs->e2 * rhs->e7 + lhs->e7 * rhs->e2;
  res->e37 =  + lhs->e3 * rhs->e7 + lhs->e7 * rhs->e3;
  res->e47 =  + lhs->e4 * rhs->e7 + lhs->e7 * rhs->e4;
  res->e57 =  + lhs->e5 * rhs->e7 + lhs->e7 * rhs->e5;
  res->e67 =  + lhs->e6 * rhs->e7 + lhs->e7 * rhs->e6;
  res->e77 =  + lhs->e7 * rhs->e7;
  res->e18 =  + lhs->e1 * rhs->e8 + lhs->e8 * rhs->e1;
  res->e28 =  + lhs->e2 * rhs->e8 + lhs->e8 * rhs->e2;
  res->e38 =  + lhs->e3 * rhs->e8 + lhs->e8 * rhs->e3;
  res->e48 =  + lhs->e4 * rhs->e8 + lhs->e8 * rhs->e4;
  res->e58 =  + lhs->e5 * rhs->e8 + lhs->e8 * rhs->e5;
  res->e68 =  + lhs->e6 * rhs->e8 + lhs->e8 * rhs->e6;
  res->e78 =  + lhs->e7 * rhs->e8 + lhs->e8 * rhs->e7;
  res->e88 =  + lhs->e8 * rhs->e8;
  res->e19 =  + lhs->e1 * rhs->e9 + lhs->e9 * rhs->e1;
  res->e29 =  + lhs->e2 * rhs->e9 + lhs->e9 * rhs->e2;
  res->e39 =  + lhs->e3 * rhs->e9 + lhs->e9 * rhs->e3;
  res->e49 =  + lhs->e4 * rhs->e9 + lhs->e9 * rhs->e4;
  res->e59 =  + lhs->e5 * rhs->e9 + lhs->e9 * rhs->e5;
  res->e69 =  + lhs->e6 * rhs->e9 + lhs->e9 * rhs->e6;
  res->e79 =  + lhs->e7 * rhs->e9 + lhs->e9 * rhs->e7;
  res->e89 =  + lhs->e8 * rhs->e9 + lhs->e9 * rhs->e8;
  res->e99 =  + lhs->e9 * rhs->e9;

}

onumm9n2_t onumm9n2_gem_oo(  onumm9n2_t* a,  onumm9n2_t* b,  onumm9n2_t* c){
  onumm9n2_t res;

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
  res.e7 = c->e7 + a->r * b->e7 + a->e7 * b->r;
  res.e8 = c->e8 + a->r * b->e8 + a->e8 * b->r;
  res.e9 = c->e9 + a->r * b->e9 + a->e9 * b->r;
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
  res.e17 = c->e17 + a->r * b->e17 + a->e17 * b->r + a->e1 * b->e7 
          + a->e7 * b->e1;
  res.e27 = c->e27 + a->r * b->e27 + a->e27 * b->r + a->e2 * b->e7 
          + a->e7 * b->e2;
  res.e37 = c->e37 + a->r * b->e37 + a->e37 * b->r + a->e3 * b->e7 
          + a->e7 * b->e3;
  res.e47 = c->e47 + a->r * b->e47 + a->e47 * b->r + a->e4 * b->e7 
          + a->e7 * b->e4;
  res.e57 = c->e57 + a->r * b->e57 + a->e57 * b->r + a->e5 * b->e7 
          + a->e7 * b->e5;
  res.e67 = c->e67 + a->r * b->e67 + a->e67 * b->r + a->e6 * b->e7 
          + a->e7 * b->e6;
  res.e77 = c->e77 + a->r * b->e77 + a->e77 * b->r + a->e7 * b->e7;
  res.e18 = c->e18 + a->r * b->e18 + a->e18 * b->r + a->e1 * b->e8 
          + a->e8 * b->e1;
  res.e28 = c->e28 + a->r * b->e28 + a->e28 * b->r + a->e2 * b->e8 
          + a->e8 * b->e2;
  res.e38 = c->e38 + a->r * b->e38 + a->e38 * b->r + a->e3 * b->e8 
          + a->e8 * b->e3;
  res.e48 = c->e48 + a->r * b->e48 + a->e48 * b->r + a->e4 * b->e8 
          + a->e8 * b->e4;
  res.e58 = c->e58 + a->r * b->e58 + a->e58 * b->r + a->e5 * b->e8 
          + a->e8 * b->e5;
  res.e68 = c->e68 + a->r * b->e68 + a->e68 * b->r + a->e6 * b->e8 
          + a->e8 * b->e6;
  res.e78 = c->e78 + a->r * b->e78 + a->e78 * b->r + a->e7 * b->e8 
          + a->e8 * b->e7;
  res.e88 = c->e88 + a->r * b->e88 + a->e88 * b->r + a->e8 * b->e8;
  res.e19 = c->e19 + a->r * b->e19 + a->e19 * b->r + a->e1 * b->e9 
          + a->e9 * b->e1;
  res.e29 = c->e29 + a->r * b->e29 + a->e29 * b->r + a->e2 * b->e9 
          + a->e9 * b->e2;
  res.e39 = c->e39 + a->r * b->e39 + a->e39 * b->r + a->e3 * b->e9 
          + a->e9 * b->e3;
  res.e49 = c->e49 + a->r * b->e49 + a->e49 * b->r + a->e4 * b->e9 
          + a->e9 * b->e4;
  res.e59 = c->e59 + a->r * b->e59 + a->e59 * b->r + a->e5 * b->e9 
          + a->e9 * b->e5;
  res.e69 = c->e69 + a->r * b->e69 + a->e69 * b->r + a->e6 * b->e9 
          + a->e9 * b->e6;
  res.e79 = c->e79 + a->r * b->e79 + a->e79 * b->r + a->e7 * b->e9 
          + a->e9 * b->e7;
  res.e89 = c->e89 + a->r * b->e89 + a->e89 * b->r + a->e8 * b->e9 
          + a->e9 * b->e8;
  res.e99 = c->e99 + a->r * b->e99 + a->e99 * b->r + a->e9 * b->e9;

  return res;

}

void onumm9n2_gem_oo_to(  onumm9n2_t* a,  onumm9n2_t* b,  onumm9n2_t* c, onumm9n2_t* res){
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
  res->e7 = c->e7 + a->r * b->e7 + a->e7 * b->r;
  res->e8 = c->e8 + a->r * b->e8 + a->e8 * b->r;
  res->e9 = c->e9 + a->r * b->e9 + a->e9 * b->r;
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
  res->e17 = c->e17 + a->r * b->e17 + a->e17 * b->r + a->e1 * b->e7 
          + a->e7 * b->e1;
  res->e27 = c->e27 + a->r * b->e27 + a->e27 * b->r + a->e2 * b->e7 
          + a->e7 * b->e2;
  res->e37 = c->e37 + a->r * b->e37 + a->e37 * b->r + a->e3 * b->e7 
          + a->e7 * b->e3;
  res->e47 = c->e47 + a->r * b->e47 + a->e47 * b->r + a->e4 * b->e7 
          + a->e7 * b->e4;
  res->e57 = c->e57 + a->r * b->e57 + a->e57 * b->r + a->e5 * b->e7 
          + a->e7 * b->e5;
  res->e67 = c->e67 + a->r * b->e67 + a->e67 * b->r + a->e6 * b->e7 
          + a->e7 * b->e6;
  res->e77 = c->e77 + a->r * b->e77 + a->e77 * b->r + a->e7 * b->e7;
  res->e18 = c->e18 + a->r * b->e18 + a->e18 * b->r + a->e1 * b->e8 
          + a->e8 * b->e1;
  res->e28 = c->e28 + a->r * b->e28 + a->e28 * b->r + a->e2 * b->e8 
          + a->e8 * b->e2;
  res->e38 = c->e38 + a->r * b->e38 + a->e38 * b->r + a->e3 * b->e8 
          + a->e8 * b->e3;
  res->e48 = c->e48 + a->r * b->e48 + a->e48 * b->r + a->e4 * b->e8 
          + a->e8 * b->e4;
  res->e58 = c->e58 + a->r * b->e58 + a->e58 * b->r + a->e5 * b->e8 
          + a->e8 * b->e5;
  res->e68 = c->e68 + a->r * b->e68 + a->e68 * b->r + a->e6 * b->e8 
          + a->e8 * b->e6;
  res->e78 = c->e78 + a->r * b->e78 + a->e78 * b->r + a->e7 * b->e8 
          + a->e8 * b->e7;
  res->e88 = c->e88 + a->r * b->e88 + a->e88 * b->r + a->e8 * b->e8;
  res->e19 = c->e19 + a->r * b->e19 + a->e19 * b->r + a->e1 * b->e9 
          + a->e9 * b->e1;
  res->e29 = c->e29 + a->r * b->e29 + a->e29 * b->r + a->e2 * b->e9 
          + a->e9 * b->e2;
  res->e39 = c->e39 + a->r * b->e39 + a->e39 * b->r + a->e3 * b->e9 
          + a->e9 * b->e3;
  res->e49 = c->e49 + a->r * b->e49 + a->e49 * b->r + a->e4 * b->e9 
          + a->e9 * b->e4;
  res->e59 = c->e59 + a->r * b->e59 + a->e59 * b->r + a->e5 * b->e9 
          + a->e9 * b->e5;
  res->e69 = c->e69 + a->r * b->e69 + a->e69 * b->r + a->e6 * b->e9 
          + a->e9 * b->e6;
  res->e79 = c->e79 + a->r * b->e79 + a->e79 * b->r + a->e7 * b->e9 
          + a->e9 * b->e7;
  res->e89 = c->e89 + a->r * b->e89 + a->e89 * b->r + a->e8 * b->e9 
          + a->e9 * b->e8;
  res->e99 = c->e99 + a->r * b->e99 + a->e99 * b->r + a->e9 * b->e9;

}

onumm9n2_t onumm9n2_gem_ro(  coeff_t a,  onumm9n2_t* b,  onumm9n2_t* c){
  onumm9n2_t res;

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
  res.e7 = c->e7 + a * b->e7;
  res.e8 = c->e8 + a * b->e8;
  res.e9 = c->e9 + a * b->e9;
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
  res.e17 = c->e17 + a * b->e17;
  res.e27 = c->e27 + a * b->e27;
  res.e37 = c->e37 + a * b->e37;
  res.e47 = c->e47 + a * b->e47;
  res.e57 = c->e57 + a * b->e57;
  res.e67 = c->e67 + a * b->e67;
  res.e77 = c->e77 + a * b->e77;
  res.e18 = c->e18 + a * b->e18;
  res.e28 = c->e28 + a * b->e28;
  res.e38 = c->e38 + a * b->e38;
  res.e48 = c->e48 + a * b->e48;
  res.e58 = c->e58 + a * b->e58;
  res.e68 = c->e68 + a * b->e68;
  res.e78 = c->e78 + a * b->e78;
  res.e88 = c->e88 + a * b->e88;
  res.e19 = c->e19 + a * b->e19;
  res.e29 = c->e29 + a * b->e29;
  res.e39 = c->e39 + a * b->e39;
  res.e49 = c->e49 + a * b->e49;
  res.e59 = c->e59 + a * b->e59;
  res.e69 = c->e69 + a * b->e69;
  res.e79 = c->e79 + a * b->e79;
  res.e89 = c->e89 + a * b->e89;
  res.e99 = c->e99 + a * b->e99;

  return res;

}

void onumm9n2_gem_ro_to(  coeff_t a,  onumm9n2_t* b,  onumm9n2_t* c, onumm9n2_t* res){
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
  res->e7 = c->e7 + a * b->e7;
  res->e8 = c->e8 + a * b->e8;
  res->e9 = c->e9 + a * b->e9;
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
  res->e17 = c->e17 + a * b->e17;
  res->e27 = c->e27 + a * b->e27;
  res->e37 = c->e37 + a * b->e37;
  res->e47 = c->e47 + a * b->e47;
  res->e57 = c->e57 + a * b->e57;
  res->e67 = c->e67 + a * b->e67;
  res->e77 = c->e77 + a * b->e77;
  res->e18 = c->e18 + a * b->e18;
  res->e28 = c->e28 + a * b->e28;
  res->e38 = c->e38 + a * b->e38;
  res->e48 = c->e48 + a * b->e48;
  res->e58 = c->e58 + a * b->e58;
  res->e68 = c->e68 + a * b->e68;
  res->e78 = c->e78 + a * b->e78;
  res->e88 = c->e88 + a * b->e88;
  res->e19 = c->e19 + a * b->e19;
  res->e29 = c->e29 + a * b->e29;
  res->e39 = c->e39 + a * b->e39;
  res->e49 = c->e49 + a * b->e49;
  res->e59 = c->e59 + a * b->e59;
  res->e69 = c->e69 + a * b->e69;
  res->e79 = c->e79 + a * b->e79;
  res->e89 = c->e89 + a * b->e89;
  res->e99 = c->e99 + a * b->e99;

}

void onumm9n2_trunc_gem_oo_to( ord_t ord_lhs,  onumm9n2_t* a,  ord_t ord_rhs,  onumm9n2_t* b,  onumm9n2_t* c, onumm9n2_t* res){
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
          res->e7 = c->e7 + a->r * b->e7;
          res->e8 = c->e8 + a->r * b->e8;
          res->e9 = c->e9 + a->r * b->e9;
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
          res->e17 = c->e17 + a->r * b->e17;
          res->e27 = c->e27 + a->r * b->e27;
          res->e37 = c->e37 + a->r * b->e37;
          res->e47 = c->e47 + a->r * b->e47;
          res->e57 = c->e57 + a->r * b->e57;
          res->e67 = c->e67 + a->r * b->e67;
          res->e77 = c->e77 + a->r * b->e77;
          res->e18 = c->e18 + a->r * b->e18;
          res->e28 = c->e28 + a->r * b->e28;
          res->e38 = c->e38 + a->r * b->e38;
          res->e48 = c->e48 + a->r * b->e48;
          res->e58 = c->e58 + a->r * b->e58;
          res->e68 = c->e68 + a->r * b->e68;
          res->e78 = c->e78 + a->r * b->e78;
          res->e88 = c->e88 + a->r * b->e88;
          res->e19 = c->e19 + a->r * b->e19;
          res->e29 = c->e29 + a->r * b->e29;
          res->e39 = c->e39 + a->r * b->e39;
          res->e49 = c->e49 + a->r * b->e49;
          res->e59 = c->e59 + a->r * b->e59;
          res->e69 = c->e69 + a->r * b->e69;
          res->e79 = c->e79 + a->r * b->e79;
          res->e89 = c->e89 + a->r * b->e89;
          res->e99 = c->e99 + a->r * b->e99;
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
          res->e7 = c->e7 + a->e7 * b->r;
          res->e8 = c->e8 + a->e8 * b->r;
          res->e9 = c->e9 + a->e9 * b->r;
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
          res->e17 = c->e17 + a->e1 * b->e7 + a->e7 * b->e1;
          res->e27 = c->e27 + a->e2 * b->e7 + a->e7 * b->e2;
          res->e37 = c->e37 + a->e3 * b->e7 + a->e7 * b->e3;
          res->e47 = c->e47 + a->e4 * b->e7 + a->e7 * b->e4;
          res->e57 = c->e57 + a->e5 * b->e7 + a->e7 * b->e5;
          res->e67 = c->e67 + a->e6 * b->e7 + a->e7 * b->e6;
          res->e77 = c->e77 + a->e7 * b->e7;
          res->e18 = c->e18 + a->e1 * b->e8 + a->e8 * b->e1;
          res->e28 = c->e28 + a->e2 * b->e8 + a->e8 * b->e2;
          res->e38 = c->e38 + a->e3 * b->e8 + a->e8 * b->e3;
          res->e48 = c->e48 + a->e4 * b->e8 + a->e8 * b->e4;
          res->e58 = c->e58 + a->e5 * b->e8 + a->e8 * b->e5;
          res->e68 = c->e68 + a->e6 * b->e8 + a->e8 * b->e6;
          res->e78 = c->e78 + a->e7 * b->e8 + a->e8 * b->e7;
          res->e88 = c->e88 + a->e8 * b->e8;
          res->e19 = c->e19 + a->e1 * b->e9 + a->e9 * b->e1;
          res->e29 = c->e29 + a->e2 * b->e9 + a->e9 * b->e2;
          res->e39 = c->e39 + a->e3 * b->e9 + a->e9 * b->e3;
          res->e49 = c->e49 + a->e4 * b->e9 + a->e9 * b->e4;
          res->e59 = c->e59 + a->e5 * b->e9 + a->e9 * b->e5;
          res->e69 = c->e69 + a->e6 * b->e9 + a->e9 * b->e6;
          res->e79 = c->e79 + a->e7 * b->e9 + a->e9 * b->e7;
          res->e89 = c->e89 + a->e8 * b->e9 + a->e9 * b->e8;
          res->e99 = c->e99 + a->e9 * b->e9;
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
          res->e17 = c->e17 + a->e17 * b->r;
          res->e27 = c->e27 + a->e27 * b->r;
          res->e37 = c->e37 + a->e37 * b->r;
          res->e47 = c->e47 + a->e47 * b->r;
          res->e57 = c->e57 + a->e57 * b->r;
          res->e67 = c->e67 + a->e67 * b->r;
          res->e77 = c->e77 + a->e77 * b->r;
          res->e18 = c->e18 + a->e18 * b->r;
          res->e28 = c->e28 + a->e28 * b->r;
          res->e38 = c->e38 + a->e38 * b->r;
          res->e48 = c->e48 + a->e48 * b->r;
          res->e58 = c->e58 + a->e58 * b->r;
          res->e68 = c->e68 + a->e68 * b->r;
          res->e78 = c->e78 + a->e78 * b->r;
          res->e88 = c->e88 + a->e88 * b->r;
          res->e19 = c->e19 + a->e19 * b->r;
          res->e29 = c->e29 + a->e29 * b->r;
          res->e39 = c->e39 + a->e39 * b->r;
          res->e49 = c->e49 + a->e49 * b->r;
          res->e59 = c->e59 + a->e59 * b->r;
          res->e69 = c->e69 + a->e69 * b->r;
          res->e79 = c->e79 + a->e79 * b->r;
          res->e89 = c->e89 + a->e89 * b->r;
          res->e99 = c->e99 + a->e99 * b->r;
          break;
      }
      break;
  }

}

onumm9n2_t onumm9n2_feval(coeff_t* feval_re, onumm9n2_t* x){

  onumm9n2_t res;

  // feval function
  //  Definitions
  coeff_t factor=1, coef = 0;
  onumm9n2_t deltax = (*x), deltax_power = (*x);
  deltax.r = 0.0;
  deltax_power.r = 0.0;
  onumm9n2_set_r(0.0, &res);
  //  Real
  res.r = feval_re[0];
  // Order 1
  factor *=1;
  coef    = feval_re[1]/ factor;;
  onumm9n2_gem_ro_to( coef, &deltax_power, &res, &res);
  deltax_power = onumm9n2_mul_oo(&deltax_power,&deltax);
  // Order 2
  factor *=2;
  coef    = feval_re[2]/ factor;;
  onumm9n2_gem_ro_to( coef, &deltax_power, &res, &res);

  return res;

}

void onumm9n2_feval_to(coeff_t* feval_re, onumm9n2_t* x, onumm9n2_t* res){

  // feval function
  //  Definitions
  coeff_t factor=1, coef = 0;
  onumm9n2_t deltax = (*x), deltax_power = (*x);
  deltax.r = 0.0;
  deltax_power.r = 0.0;
  onumm9n2_set_r(0.0, res);
  //  Real
  res->r = feval_re[0];
  // Order 1
  factor *=1;
  coef    = feval_re[1]/ factor;;
  onumm9n2_gem_ro_to( coef, &deltax_power, res, res);
  deltax_power = onumm9n2_mul_oo(&deltax_power,&deltax);
  // Order 2
  factor *=2;
  coef    = feval_re[2]/ factor;;
  onumm9n2_gem_ro_to( coef, &deltax_power, res, res);

}

