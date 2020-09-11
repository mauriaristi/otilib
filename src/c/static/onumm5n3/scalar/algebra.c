
// Division.

// ****************************************************************************************************
onumm5n3_t onumm5n3_div_ro(coeff_t num, onumm5n3_t* den){

    
    onumm5n3_t inv = onumm5n3_pow(den,-1);
    onumm5n3_t res = onumm5n3_mul_ro(num,&inv);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
onumm5n3_t onumm5n3_div_oo(onumm5n3_t* num, onumm5n3_t* den){

    
    onumm5n3_t inv = onumm5n3_init();
    onumm5n3_pow_to(den,-1,&inv);
    onumm5n3_t res = onumm5n3_mul_oo(num,&inv);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
onumm5n3_t onumm5n3_div_or(onumm5n3_t* num, coeff_t val){

    return onumm5n3_mul_ro(1.0/val,num);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
onumm5n3_t onumm5n3_abs(onumm5n3_t* num){

	onumm5n3_t res;
    onumm5n3_abs_to(num,&res);
    return res;

}
// ----------------------------------------------------------------------------------------------------

onumm5n3_t onumm5n3_neg(  onumm5n3_t* lhs){

  onumm5n3_t res;

  // Negation like function '-lhs'
  // Real;
  res.r = -lhs->r;
  // Order 1;
  res.e1 = -lhs->e1;
  res.e2 = -lhs->e2;
  res.e3 = -lhs->e3;
  res.e4 = -lhs->e4;
  res.e5 = -lhs->e5;
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
  res.e114 = -lhs->e114;
  res.e124 = -lhs->e124;
  res.e224 = -lhs->e224;
  res.e134 = -lhs->e134;
  res.e234 = -lhs->e234;
  res.e334 = -lhs->e334;
  res.e144 = -lhs->e144;
  res.e244 = -lhs->e244;
  res.e344 = -lhs->e344;
  res.e444 = -lhs->e444;
  res.e115 = -lhs->e115;
  res.e125 = -lhs->e125;
  res.e225 = -lhs->e225;
  res.e135 = -lhs->e135;
  res.e235 = -lhs->e235;
  res.e335 = -lhs->e335;
  res.e145 = -lhs->e145;
  res.e245 = -lhs->e245;
  res.e345 = -lhs->e345;
  res.e445 = -lhs->e445;
  res.e155 = -lhs->e155;
  res.e255 = -lhs->e255;
  res.e355 = -lhs->e355;
  res.e455 = -lhs->e455;
  res.e555 = -lhs->e555;

  return res;

}

void onumm5n3_neg_to(  onumm5n3_t* lhs, onumm5n3_t* res){

  // Negation like function '-lhs'
  // Real;
  res->r = -lhs->r;
  // Order 1;
  res->e1 = -lhs->e1;
  res->e2 = -lhs->e2;
  res->e3 = -lhs->e3;
  res->e4 = -lhs->e4;
  res->e5 = -lhs->e5;
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
  res->e114 = -lhs->e114;
  res->e124 = -lhs->e124;
  res->e224 = -lhs->e224;
  res->e134 = -lhs->e134;
  res->e234 = -lhs->e234;
  res->e334 = -lhs->e334;
  res->e144 = -lhs->e144;
  res->e244 = -lhs->e244;
  res->e344 = -lhs->e344;
  res->e444 = -lhs->e444;
  res->e115 = -lhs->e115;
  res->e125 = -lhs->e125;
  res->e225 = -lhs->e225;
  res->e135 = -lhs->e135;
  res->e235 = -lhs->e235;
  res->e335 = -lhs->e335;
  res->e145 = -lhs->e145;
  res->e245 = -lhs->e245;
  res->e345 = -lhs->e345;
  res->e445 = -lhs->e445;
  res->e155 = -lhs->e155;
  res->e255 = -lhs->e255;
  res->e355 = -lhs->e355;
  res->e455 = -lhs->e455;
  res->e555 = -lhs->e555;

}

onumm5n3_t onumm5n3_sum_oo(  onumm5n3_t* lhs,  onumm5n3_t* rhs){
  onumm5n3_t res;

  // Addition like function 'lhs + rhs'
  //  Real
  res.r = lhs->r + rhs->r;
  // Order 1
  res.e1 = lhs->e1 + rhs->e1;
  res.e2 = lhs->e2 + rhs->e2;
  res.e3 = lhs->e3 + rhs->e3;
  res.e4 = lhs->e4 + rhs->e4;
  res.e5 = lhs->e5 + rhs->e5;
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
  res.e114 = lhs->e114 + rhs->e114;
  res.e124 = lhs->e124 + rhs->e124;
  res.e224 = lhs->e224 + rhs->e224;
  res.e134 = lhs->e134 + rhs->e134;
  res.e234 = lhs->e234 + rhs->e234;
  res.e334 = lhs->e334 + rhs->e334;
  res.e144 = lhs->e144 + rhs->e144;
  res.e244 = lhs->e244 + rhs->e244;
  res.e344 = lhs->e344 + rhs->e344;
  res.e444 = lhs->e444 + rhs->e444;
  res.e115 = lhs->e115 + rhs->e115;
  res.e125 = lhs->e125 + rhs->e125;
  res.e225 = lhs->e225 + rhs->e225;
  res.e135 = lhs->e135 + rhs->e135;
  res.e235 = lhs->e235 + rhs->e235;
  res.e335 = lhs->e335 + rhs->e335;
  res.e145 = lhs->e145 + rhs->e145;
  res.e245 = lhs->e245 + rhs->e245;
  res.e345 = lhs->e345 + rhs->e345;
  res.e445 = lhs->e445 + rhs->e445;
  res.e155 = lhs->e155 + rhs->e155;
  res.e255 = lhs->e255 + rhs->e255;
  res.e355 = lhs->e355 + rhs->e355;
  res.e455 = lhs->e455 + rhs->e455;
  res.e555 = lhs->e555 + rhs->e555;

  return res;

}

void onumm5n3_sum_oo_to(  onumm5n3_t* lhs,  onumm5n3_t* rhs, onumm5n3_t* res){
  // Addition like function 'lhs + rhs'
  //  Real
  res->r = lhs->r + rhs->r;
  // Order 1
  res->e1 = lhs->e1 + rhs->e1;
  res->e2 = lhs->e2 + rhs->e2;
  res->e3 = lhs->e3 + rhs->e3;
  res->e4 = lhs->e4 + rhs->e4;
  res->e5 = lhs->e5 + rhs->e5;
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
  res->e114 = lhs->e114 + rhs->e114;
  res->e124 = lhs->e124 + rhs->e124;
  res->e224 = lhs->e224 + rhs->e224;
  res->e134 = lhs->e134 + rhs->e134;
  res->e234 = lhs->e234 + rhs->e234;
  res->e334 = lhs->e334 + rhs->e334;
  res->e144 = lhs->e144 + rhs->e144;
  res->e244 = lhs->e244 + rhs->e244;
  res->e344 = lhs->e344 + rhs->e344;
  res->e444 = lhs->e444 + rhs->e444;
  res->e115 = lhs->e115 + rhs->e115;
  res->e125 = lhs->e125 + rhs->e125;
  res->e225 = lhs->e225 + rhs->e225;
  res->e135 = lhs->e135 + rhs->e135;
  res->e235 = lhs->e235 + rhs->e235;
  res->e335 = lhs->e335 + rhs->e335;
  res->e145 = lhs->e145 + rhs->e145;
  res->e245 = lhs->e245 + rhs->e245;
  res->e345 = lhs->e345 + rhs->e345;
  res->e445 = lhs->e445 + rhs->e445;
  res->e155 = lhs->e155 + rhs->e155;
  res->e255 = lhs->e255 + rhs->e255;
  res->e355 = lhs->e355 + rhs->e355;
  res->e455 = lhs->e455 + rhs->e455;
  res->e555 = lhs->e555 + rhs->e555;

}

onumm5n3_t onumm5n3_sum_ro(  coeff_t lhs,  onumm5n3_t* rhs){
  onumm5n3_t res;

  // Addition like function 'lhs + rhs'
  // Real;
  res.r = lhs + rhs->r;
  // Order 1;
  res.e1 =  + rhs->e1;
  res.e2 =  + rhs->e2;
  res.e3 =  + rhs->e3;
  res.e4 =  + rhs->e4;
  res.e5 =  + rhs->e5;
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
  res.e114 =  + rhs->e114;
  res.e124 =  + rhs->e124;
  res.e224 =  + rhs->e224;
  res.e134 =  + rhs->e134;
  res.e234 =  + rhs->e234;
  res.e334 =  + rhs->e334;
  res.e144 =  + rhs->e144;
  res.e244 =  + rhs->e244;
  res.e344 =  + rhs->e344;
  res.e444 =  + rhs->e444;
  res.e115 =  + rhs->e115;
  res.e125 =  + rhs->e125;
  res.e225 =  + rhs->e225;
  res.e135 =  + rhs->e135;
  res.e235 =  + rhs->e235;
  res.e335 =  + rhs->e335;
  res.e145 =  + rhs->e145;
  res.e245 =  + rhs->e245;
  res.e345 =  + rhs->e345;
  res.e445 =  + rhs->e445;
  res.e155 =  + rhs->e155;
  res.e255 =  + rhs->e255;
  res.e355 =  + rhs->e355;
  res.e455 =  + rhs->e455;
  res.e555 =  + rhs->e555;

  return res;

}

void onumm5n3_sum_ro_to(  coeff_t lhs,  onumm5n3_t* rhs, onumm5n3_t* res){
  // Addition like function 'lhs + rhs'
  // Real;
  res->r = lhs + rhs->r;
  // Order 1;
  res->e1 =  + rhs->e1;
  res->e2 =  + rhs->e2;
  res->e3 =  + rhs->e3;
  res->e4 =  + rhs->e4;
  res->e5 =  + rhs->e5;
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
  res->e114 =  + rhs->e114;
  res->e124 =  + rhs->e124;
  res->e224 =  + rhs->e224;
  res->e134 =  + rhs->e134;
  res->e234 =  + rhs->e234;
  res->e334 =  + rhs->e334;
  res->e144 =  + rhs->e144;
  res->e244 =  + rhs->e244;
  res->e344 =  + rhs->e344;
  res->e444 =  + rhs->e444;
  res->e115 =  + rhs->e115;
  res->e125 =  + rhs->e125;
  res->e225 =  + rhs->e225;
  res->e135 =  + rhs->e135;
  res->e235 =  + rhs->e235;
  res->e335 =  + rhs->e335;
  res->e145 =  + rhs->e145;
  res->e245 =  + rhs->e245;
  res->e345 =  + rhs->e345;
  res->e445 =  + rhs->e445;
  res->e155 =  + rhs->e155;
  res->e255 =  + rhs->e255;
  res->e355 =  + rhs->e355;
  res->e455 =  + rhs->e455;
  res->e555 =  + rhs->e555;

}

onumm5n3_t onumm5n3_sub_oo(  onumm5n3_t* lhs,  onumm5n3_t* rhs){
  onumm5n3_t res;

  // Addition like function 'lhs - rhs'
  //  Real
  res.r = lhs->r - rhs->r;
  // Order 1
  res.e1 = lhs->e1 - rhs->e1;
  res.e2 = lhs->e2 - rhs->e2;
  res.e3 = lhs->e3 - rhs->e3;
  res.e4 = lhs->e4 - rhs->e4;
  res.e5 = lhs->e5 - rhs->e5;
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
  res.e114 = lhs->e114 - rhs->e114;
  res.e124 = lhs->e124 - rhs->e124;
  res.e224 = lhs->e224 - rhs->e224;
  res.e134 = lhs->e134 - rhs->e134;
  res.e234 = lhs->e234 - rhs->e234;
  res.e334 = lhs->e334 - rhs->e334;
  res.e144 = lhs->e144 - rhs->e144;
  res.e244 = lhs->e244 - rhs->e244;
  res.e344 = lhs->e344 - rhs->e344;
  res.e444 = lhs->e444 - rhs->e444;
  res.e115 = lhs->e115 - rhs->e115;
  res.e125 = lhs->e125 - rhs->e125;
  res.e225 = lhs->e225 - rhs->e225;
  res.e135 = lhs->e135 - rhs->e135;
  res.e235 = lhs->e235 - rhs->e235;
  res.e335 = lhs->e335 - rhs->e335;
  res.e145 = lhs->e145 - rhs->e145;
  res.e245 = lhs->e245 - rhs->e245;
  res.e345 = lhs->e345 - rhs->e345;
  res.e445 = lhs->e445 - rhs->e445;
  res.e155 = lhs->e155 - rhs->e155;
  res.e255 = lhs->e255 - rhs->e255;
  res.e355 = lhs->e355 - rhs->e355;
  res.e455 = lhs->e455 - rhs->e455;
  res.e555 = lhs->e555 - rhs->e555;

  return res;

}

void onumm5n3_sub_oo_to(  onumm5n3_t* lhs,  onumm5n3_t* rhs, onumm5n3_t* res){
  // Addition like function 'lhs - rhs'
  //  Real
  res->r = lhs->r - rhs->r;
  // Order 1
  res->e1 = lhs->e1 - rhs->e1;
  res->e2 = lhs->e2 - rhs->e2;
  res->e3 = lhs->e3 - rhs->e3;
  res->e4 = lhs->e4 - rhs->e4;
  res->e5 = lhs->e5 - rhs->e5;
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
  res->e114 = lhs->e114 - rhs->e114;
  res->e124 = lhs->e124 - rhs->e124;
  res->e224 = lhs->e224 - rhs->e224;
  res->e134 = lhs->e134 - rhs->e134;
  res->e234 = lhs->e234 - rhs->e234;
  res->e334 = lhs->e334 - rhs->e334;
  res->e144 = lhs->e144 - rhs->e144;
  res->e244 = lhs->e244 - rhs->e244;
  res->e344 = lhs->e344 - rhs->e344;
  res->e444 = lhs->e444 - rhs->e444;
  res->e115 = lhs->e115 - rhs->e115;
  res->e125 = lhs->e125 - rhs->e125;
  res->e225 = lhs->e225 - rhs->e225;
  res->e135 = lhs->e135 - rhs->e135;
  res->e235 = lhs->e235 - rhs->e235;
  res->e335 = lhs->e335 - rhs->e335;
  res->e145 = lhs->e145 - rhs->e145;
  res->e245 = lhs->e245 - rhs->e245;
  res->e345 = lhs->e345 - rhs->e345;
  res->e445 = lhs->e445 - rhs->e445;
  res->e155 = lhs->e155 - rhs->e155;
  res->e255 = lhs->e255 - rhs->e255;
  res->e355 = lhs->e355 - rhs->e355;
  res->e455 = lhs->e455 - rhs->e455;
  res->e555 = lhs->e555 - rhs->e555;

}

onumm5n3_t onumm5n3_sub_ro(  coeff_t lhs,  onumm5n3_t* rhs){
  onumm5n3_t res;

  // Addition like function 'lhs - rhs'
  // Real;
  res.r = lhs - rhs->r;
  // Order 1;
  res.e1 =  - rhs->e1;
  res.e2 =  - rhs->e2;
  res.e3 =  - rhs->e3;
  res.e4 =  - rhs->e4;
  res.e5 =  - rhs->e5;
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
  res.e114 =  - rhs->e114;
  res.e124 =  - rhs->e124;
  res.e224 =  - rhs->e224;
  res.e134 =  - rhs->e134;
  res.e234 =  - rhs->e234;
  res.e334 =  - rhs->e334;
  res.e144 =  - rhs->e144;
  res.e244 =  - rhs->e244;
  res.e344 =  - rhs->e344;
  res.e444 =  - rhs->e444;
  res.e115 =  - rhs->e115;
  res.e125 =  - rhs->e125;
  res.e225 =  - rhs->e225;
  res.e135 =  - rhs->e135;
  res.e235 =  - rhs->e235;
  res.e335 =  - rhs->e335;
  res.e145 =  - rhs->e145;
  res.e245 =  - rhs->e245;
  res.e345 =  - rhs->e345;
  res.e445 =  - rhs->e445;
  res.e155 =  - rhs->e155;
  res.e255 =  - rhs->e255;
  res.e355 =  - rhs->e355;
  res.e455 =  - rhs->e455;
  res.e555 =  - rhs->e555;

  return res;

}

void onumm5n3_sub_ro_to(  coeff_t lhs,  onumm5n3_t* rhs, onumm5n3_t* res){
  // Addition like function 'lhs - rhs'
  // Real;
  res->r = lhs - rhs->r;
  // Order 1;
  res->e1 =  - rhs->e1;
  res->e2 =  - rhs->e2;
  res->e3 =  - rhs->e3;
  res->e4 =  - rhs->e4;
  res->e5 =  - rhs->e5;
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
  res->e114 =  - rhs->e114;
  res->e124 =  - rhs->e124;
  res->e224 =  - rhs->e224;
  res->e134 =  - rhs->e134;
  res->e234 =  - rhs->e234;
  res->e334 =  - rhs->e334;
  res->e144 =  - rhs->e144;
  res->e244 =  - rhs->e244;
  res->e344 =  - rhs->e344;
  res->e444 =  - rhs->e444;
  res->e115 =  - rhs->e115;
  res->e125 =  - rhs->e125;
  res->e225 =  - rhs->e225;
  res->e135 =  - rhs->e135;
  res->e235 =  - rhs->e235;
  res->e335 =  - rhs->e335;
  res->e145 =  - rhs->e145;
  res->e245 =  - rhs->e245;
  res->e345 =  - rhs->e345;
  res->e445 =  - rhs->e445;
  res->e155 =  - rhs->e155;
  res->e255 =  - rhs->e255;
  res->e355 =  - rhs->e355;
  res->e455 =  - rhs->e455;
  res->e555 =  - rhs->e555;

}

onumm5n3_t onumm5n3_sub_or(  onumm5n3_t* lhs,  coeff_t rhs){
  onumm5n3_t res;

  // Addition like function 'lhs - rhs'
  // Real;
  res.r = lhs->r - rhs;
  // Order 1;
  res.e1 = lhs->e1;
  res.e2 = lhs->e2;
  res.e3 = lhs->e3;
  res.e4 = lhs->e4;
  res.e5 = lhs->e5;
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
  res.e114 = lhs->e114;
  res.e124 = lhs->e124;
  res.e224 = lhs->e224;
  res.e134 = lhs->e134;
  res.e234 = lhs->e234;
  res.e334 = lhs->e334;
  res.e144 = lhs->e144;
  res.e244 = lhs->e244;
  res.e344 = lhs->e344;
  res.e444 = lhs->e444;
  res.e115 = lhs->e115;
  res.e125 = lhs->e125;
  res.e225 = lhs->e225;
  res.e135 = lhs->e135;
  res.e235 = lhs->e235;
  res.e335 = lhs->e335;
  res.e145 = lhs->e145;
  res.e245 = lhs->e245;
  res.e345 = lhs->e345;
  res.e445 = lhs->e445;
  res.e155 = lhs->e155;
  res.e255 = lhs->e255;
  res.e355 = lhs->e355;
  res.e455 = lhs->e455;
  res.e555 = lhs->e555;

  return res;

}

void onumm5n3_sub_or_to(  onumm5n3_t* lhs,  coeff_t rhs, onumm5n3_t* res){
  // Addition like function 'lhs - rhs'
  // Real;
  res->r = lhs->r - rhs;
  // Order 1;
  res->e1 = lhs->e1;
  res->e2 = lhs->e2;
  res->e3 = lhs->e3;
  res->e4 = lhs->e4;
  res->e5 = lhs->e5;
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
  res->e114 = lhs->e114;
  res->e124 = lhs->e124;
  res->e224 = lhs->e224;
  res->e134 = lhs->e134;
  res->e234 = lhs->e234;
  res->e334 = lhs->e334;
  res->e144 = lhs->e144;
  res->e244 = lhs->e244;
  res->e344 = lhs->e344;
  res->e444 = lhs->e444;
  res->e115 = lhs->e115;
  res->e125 = lhs->e125;
  res->e225 = lhs->e225;
  res->e135 = lhs->e135;
  res->e235 = lhs->e235;
  res->e335 = lhs->e335;
  res->e145 = lhs->e145;
  res->e245 = lhs->e245;
  res->e345 = lhs->e345;
  res->e445 = lhs->e445;
  res->e155 = lhs->e155;
  res->e255 = lhs->e255;
  res->e355 = lhs->e355;
  res->e455 = lhs->e455;
  res->e555 = lhs->e555;

}

onumm5n3_t onumm5n3_mul_oo(  onumm5n3_t* lhs,  onumm5n3_t* rhs){
  onumm5n3_t res;

  //  Multiplication like function 'lhs * rhs'
  // Real;
  res.r = lhs->r * rhs->r;
  // Order 1;
  res.e1 = lhs->r * rhs->e1 + lhs->e1 * rhs->r;
  res.e2 = lhs->r * rhs->e2 + lhs->e2 * rhs->r;
  res.e3 = lhs->r * rhs->e3 + lhs->e3 * rhs->r;
  res.e4 = lhs->r * rhs->e4 + lhs->e4 * rhs->r;
  res.e5 = lhs->r * rhs->e5 + lhs->e5 * rhs->r;
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
  res.e114 = lhs->r * rhs->e114 + lhs->e114 * rhs->r + lhs->e1 * rhs->e14 
           + lhs->e14 * rhs->e1 + lhs->e4 * rhs->e11 + lhs->e11 * rhs->e4;
  res.e124 = lhs->r * rhs->e124 + lhs->e124 * rhs->r + lhs->e1 * rhs->e24 
           + lhs->e24 * rhs->e1 + lhs->e2 * rhs->e14 + lhs->e14 * rhs->e2 
           + lhs->e4 * rhs->e12 + lhs->e12 * rhs->e4;
  res.e224 = lhs->r * rhs->e224 + lhs->e224 * rhs->r + lhs->e2 * rhs->e24 
           + lhs->e24 * rhs->e2 + lhs->e4 * rhs->e22 + lhs->e22 * rhs->e4;
  res.e134 = lhs->r * rhs->e134 + lhs->e134 * rhs->r + lhs->e1 * rhs->e34 
           + lhs->e34 * rhs->e1 + lhs->e3 * rhs->e14 + lhs->e14 * rhs->e3 
           + lhs->e4 * rhs->e13 + lhs->e13 * rhs->e4;
  res.e234 = lhs->r * rhs->e234 + lhs->e234 * rhs->r + lhs->e2 * rhs->e34 
           + lhs->e34 * rhs->e2 + lhs->e3 * rhs->e24 + lhs->e24 * rhs->e3 
           + lhs->e4 * rhs->e23 + lhs->e23 * rhs->e4;
  res.e334 = lhs->r * rhs->e334 + lhs->e334 * rhs->r + lhs->e3 * rhs->e34 
           + lhs->e34 * rhs->e3 + lhs->e4 * rhs->e33 + lhs->e33 * rhs->e4;
  res.e144 = lhs->r * rhs->e144 + lhs->e144 * rhs->r + lhs->e1 * rhs->e44 
           + lhs->e44 * rhs->e1 + lhs->e4 * rhs->e14 + lhs->e14 * rhs->e4;
  res.e244 = lhs->r * rhs->e244 + lhs->e244 * rhs->r + lhs->e2 * rhs->e44 
           + lhs->e44 * rhs->e2 + lhs->e4 * rhs->e24 + lhs->e24 * rhs->e4;
  res.e344 = lhs->r * rhs->e344 + lhs->e344 * rhs->r + lhs->e3 * rhs->e44 
           + lhs->e44 * rhs->e3 + lhs->e4 * rhs->e34 + lhs->e34 * rhs->e4;
  res.e444 = lhs->r * rhs->e444 + lhs->e444 * rhs->r + lhs->e4 * rhs->e44 
           + lhs->e44 * rhs->e4;
  res.e115 = lhs->r * rhs->e115 + lhs->e115 * rhs->r + lhs->e1 * rhs->e15 
           + lhs->e15 * rhs->e1 + lhs->e5 * rhs->e11 + lhs->e11 * rhs->e5;
  res.e125 = lhs->r * rhs->e125 + lhs->e125 * rhs->r + lhs->e1 * rhs->e25 
           + lhs->e25 * rhs->e1 + lhs->e2 * rhs->e15 + lhs->e15 * rhs->e2 
           + lhs->e5 * rhs->e12 + lhs->e12 * rhs->e5;
  res.e225 = lhs->r * rhs->e225 + lhs->e225 * rhs->r + lhs->e2 * rhs->e25 
           + lhs->e25 * rhs->e2 + lhs->e5 * rhs->e22 + lhs->e22 * rhs->e5;
  res.e135 = lhs->r * rhs->e135 + lhs->e135 * rhs->r + lhs->e1 * rhs->e35 
           + lhs->e35 * rhs->e1 + lhs->e3 * rhs->e15 + lhs->e15 * rhs->e3 
           + lhs->e5 * rhs->e13 + lhs->e13 * rhs->e5;
  res.e235 = lhs->r * rhs->e235 + lhs->e235 * rhs->r + lhs->e2 * rhs->e35 
           + lhs->e35 * rhs->e2 + lhs->e3 * rhs->e25 + lhs->e25 * rhs->e3 
           + lhs->e5 * rhs->e23 + lhs->e23 * rhs->e5;
  res.e335 = lhs->r * rhs->e335 + lhs->e335 * rhs->r + lhs->e3 * rhs->e35 
           + lhs->e35 * rhs->e3 + lhs->e5 * rhs->e33 + lhs->e33 * rhs->e5;
  res.e145 = lhs->r * rhs->e145 + lhs->e145 * rhs->r + lhs->e1 * rhs->e45 
           + lhs->e45 * rhs->e1 + lhs->e4 * rhs->e15 + lhs->e15 * rhs->e4 
           + lhs->e5 * rhs->e14 + lhs->e14 * rhs->e5;
  res.e245 = lhs->r * rhs->e245 + lhs->e245 * rhs->r + lhs->e2 * rhs->e45 
           + lhs->e45 * rhs->e2 + lhs->e4 * rhs->e25 + lhs->e25 * rhs->e4 
           + lhs->e5 * rhs->e24 + lhs->e24 * rhs->e5;
  res.e345 = lhs->r * rhs->e345 + lhs->e345 * rhs->r + lhs->e3 * rhs->e45 
           + lhs->e45 * rhs->e3 + lhs->e4 * rhs->e35 + lhs->e35 * rhs->e4 
           + lhs->e5 * rhs->e34 + lhs->e34 * rhs->e5;
  res.e445 = lhs->r * rhs->e445 + lhs->e445 * rhs->r + lhs->e4 * rhs->e45 
           + lhs->e45 * rhs->e4 + lhs->e5 * rhs->e44 + lhs->e44 * rhs->e5;
  res.e155 = lhs->r * rhs->e155 + lhs->e155 * rhs->r + lhs->e1 * rhs->e55 
           + lhs->e55 * rhs->e1 + lhs->e5 * rhs->e15 + lhs->e15 * rhs->e5;
  res.e255 = lhs->r * rhs->e255 + lhs->e255 * rhs->r + lhs->e2 * rhs->e55 
           + lhs->e55 * rhs->e2 + lhs->e5 * rhs->e25 + lhs->e25 * rhs->e5;
  res.e355 = lhs->r * rhs->e355 + lhs->e355 * rhs->r + lhs->e3 * rhs->e55 
           + lhs->e55 * rhs->e3 + lhs->e5 * rhs->e35 + lhs->e35 * rhs->e5;
  res.e455 = lhs->r * rhs->e455 + lhs->e455 * rhs->r + lhs->e4 * rhs->e55 
           + lhs->e55 * rhs->e4 + lhs->e5 * rhs->e45 + lhs->e45 * rhs->e5;
  res.e555 = lhs->r * rhs->e555 + lhs->e555 * rhs->r + lhs->e5 * rhs->e55 
           + lhs->e55 * rhs->e5;

  return res;

}

void onumm5n3_mul_oo_to(  onumm5n3_t* lhs,  onumm5n3_t* rhs, onumm5n3_t* res){
  //  Multiplication like function 'lhs * rhs'
  // Real;
  res->r = lhs->r * rhs->r;
  // Order 1;
  res->e1 = lhs->r * rhs->e1 + lhs->e1 * rhs->r;
  res->e2 = lhs->r * rhs->e2 + lhs->e2 * rhs->r;
  res->e3 = lhs->r * rhs->e3 + lhs->e3 * rhs->r;
  res->e4 = lhs->r * rhs->e4 + lhs->e4 * rhs->r;
  res->e5 = lhs->r * rhs->e5 + lhs->e5 * rhs->r;
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
  res->e114 = lhs->r * rhs->e114 + lhs->e114 * rhs->r + lhs->e1 * rhs->e14 
           + lhs->e14 * rhs->e1 + lhs->e4 * rhs->e11 + lhs->e11 * rhs->e4;
  res->e124 = lhs->r * rhs->e124 + lhs->e124 * rhs->r + lhs->e1 * rhs->e24 
           + lhs->e24 * rhs->e1 + lhs->e2 * rhs->e14 + lhs->e14 * rhs->e2 
           + lhs->e4 * rhs->e12 + lhs->e12 * rhs->e4;
  res->e224 = lhs->r * rhs->e224 + lhs->e224 * rhs->r + lhs->e2 * rhs->e24 
           + lhs->e24 * rhs->e2 + lhs->e4 * rhs->e22 + lhs->e22 * rhs->e4;
  res->e134 = lhs->r * rhs->e134 + lhs->e134 * rhs->r + lhs->e1 * rhs->e34 
           + lhs->e34 * rhs->e1 + lhs->e3 * rhs->e14 + lhs->e14 * rhs->e3 
           + lhs->e4 * rhs->e13 + lhs->e13 * rhs->e4;
  res->e234 = lhs->r * rhs->e234 + lhs->e234 * rhs->r + lhs->e2 * rhs->e34 
           + lhs->e34 * rhs->e2 + lhs->e3 * rhs->e24 + lhs->e24 * rhs->e3 
           + lhs->e4 * rhs->e23 + lhs->e23 * rhs->e4;
  res->e334 = lhs->r * rhs->e334 + lhs->e334 * rhs->r + lhs->e3 * rhs->e34 
           + lhs->e34 * rhs->e3 + lhs->e4 * rhs->e33 + lhs->e33 * rhs->e4;
  res->e144 = lhs->r * rhs->e144 + lhs->e144 * rhs->r + lhs->e1 * rhs->e44 
           + lhs->e44 * rhs->e1 + lhs->e4 * rhs->e14 + lhs->e14 * rhs->e4;
  res->e244 = lhs->r * rhs->e244 + lhs->e244 * rhs->r + lhs->e2 * rhs->e44 
           + lhs->e44 * rhs->e2 + lhs->e4 * rhs->e24 + lhs->e24 * rhs->e4;
  res->e344 = lhs->r * rhs->e344 + lhs->e344 * rhs->r + lhs->e3 * rhs->e44 
           + lhs->e44 * rhs->e3 + lhs->e4 * rhs->e34 + lhs->e34 * rhs->e4;
  res->e444 = lhs->r * rhs->e444 + lhs->e444 * rhs->r + lhs->e4 * rhs->e44 
           + lhs->e44 * rhs->e4;
  res->e115 = lhs->r * rhs->e115 + lhs->e115 * rhs->r + lhs->e1 * rhs->e15 
           + lhs->e15 * rhs->e1 + lhs->e5 * rhs->e11 + lhs->e11 * rhs->e5;
  res->e125 = lhs->r * rhs->e125 + lhs->e125 * rhs->r + lhs->e1 * rhs->e25 
           + lhs->e25 * rhs->e1 + lhs->e2 * rhs->e15 + lhs->e15 * rhs->e2 
           + lhs->e5 * rhs->e12 + lhs->e12 * rhs->e5;
  res->e225 = lhs->r * rhs->e225 + lhs->e225 * rhs->r + lhs->e2 * rhs->e25 
           + lhs->e25 * rhs->e2 + lhs->e5 * rhs->e22 + lhs->e22 * rhs->e5;
  res->e135 = lhs->r * rhs->e135 + lhs->e135 * rhs->r + lhs->e1 * rhs->e35 
           + lhs->e35 * rhs->e1 + lhs->e3 * rhs->e15 + lhs->e15 * rhs->e3 
           + lhs->e5 * rhs->e13 + lhs->e13 * rhs->e5;
  res->e235 = lhs->r * rhs->e235 + lhs->e235 * rhs->r + lhs->e2 * rhs->e35 
           + lhs->e35 * rhs->e2 + lhs->e3 * rhs->e25 + lhs->e25 * rhs->e3 
           + lhs->e5 * rhs->e23 + lhs->e23 * rhs->e5;
  res->e335 = lhs->r * rhs->e335 + lhs->e335 * rhs->r + lhs->e3 * rhs->e35 
           + lhs->e35 * rhs->e3 + lhs->e5 * rhs->e33 + lhs->e33 * rhs->e5;
  res->e145 = lhs->r * rhs->e145 + lhs->e145 * rhs->r + lhs->e1 * rhs->e45 
           + lhs->e45 * rhs->e1 + lhs->e4 * rhs->e15 + lhs->e15 * rhs->e4 
           + lhs->e5 * rhs->e14 + lhs->e14 * rhs->e5;
  res->e245 = lhs->r * rhs->e245 + lhs->e245 * rhs->r + lhs->e2 * rhs->e45 
           + lhs->e45 * rhs->e2 + lhs->e4 * rhs->e25 + lhs->e25 * rhs->e4 
           + lhs->e5 * rhs->e24 + lhs->e24 * rhs->e5;
  res->e345 = lhs->r * rhs->e345 + lhs->e345 * rhs->r + lhs->e3 * rhs->e45 
           + lhs->e45 * rhs->e3 + lhs->e4 * rhs->e35 + lhs->e35 * rhs->e4 
           + lhs->e5 * rhs->e34 + lhs->e34 * rhs->e5;
  res->e445 = lhs->r * rhs->e445 + lhs->e445 * rhs->r + lhs->e4 * rhs->e45 
           + lhs->e45 * rhs->e4 + lhs->e5 * rhs->e44 + lhs->e44 * rhs->e5;
  res->e155 = lhs->r * rhs->e155 + lhs->e155 * rhs->r + lhs->e1 * rhs->e55 
           + lhs->e55 * rhs->e1 + lhs->e5 * rhs->e15 + lhs->e15 * rhs->e5;
  res->e255 = lhs->r * rhs->e255 + lhs->e255 * rhs->r + lhs->e2 * rhs->e55 
           + lhs->e55 * rhs->e2 + lhs->e5 * rhs->e25 + lhs->e25 * rhs->e5;
  res->e355 = lhs->r * rhs->e355 + lhs->e355 * rhs->r + lhs->e3 * rhs->e55 
           + lhs->e55 * rhs->e3 + lhs->e5 * rhs->e35 + lhs->e35 * rhs->e5;
  res->e455 = lhs->r * rhs->e455 + lhs->e455 * rhs->r + lhs->e4 * rhs->e55 
           + lhs->e55 * rhs->e4 + lhs->e5 * rhs->e45 + lhs->e45 * rhs->e5;
  res->e555 = lhs->r * rhs->e555 + lhs->e555 * rhs->r + lhs->e5 * rhs->e55 
           + lhs->e55 * rhs->e5;

}

onumm5n3_t onumm5n3_mul_ro(  coeff_t lhs,  onumm5n3_t* rhs){
  onumm5n3_t res;

  // Multiplication like function 'lhs * rhs'
  //  Real;
  res.r = lhs * rhs->r;
  // Order 1;
  res.e1 = lhs * rhs->e1;
  res.e2 = lhs * rhs->e2;
  res.e3 = lhs * rhs->e3;
  res.e4 = lhs * rhs->e4;
  res.e5 = lhs * rhs->e5;
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
  res.e114 = lhs * rhs->e114;
  res.e124 = lhs * rhs->e124;
  res.e224 = lhs * rhs->e224;
  res.e134 = lhs * rhs->e134;
  res.e234 = lhs * rhs->e234;
  res.e334 = lhs * rhs->e334;
  res.e144 = lhs * rhs->e144;
  res.e244 = lhs * rhs->e244;
  res.e344 = lhs * rhs->e344;
  res.e444 = lhs * rhs->e444;
  res.e115 = lhs * rhs->e115;
  res.e125 = lhs * rhs->e125;
  res.e225 = lhs * rhs->e225;
  res.e135 = lhs * rhs->e135;
  res.e235 = lhs * rhs->e235;
  res.e335 = lhs * rhs->e335;
  res.e145 = lhs * rhs->e145;
  res.e245 = lhs * rhs->e245;
  res.e345 = lhs * rhs->e345;
  res.e445 = lhs * rhs->e445;
  res.e155 = lhs * rhs->e155;
  res.e255 = lhs * rhs->e255;
  res.e355 = lhs * rhs->e355;
  res.e455 = lhs * rhs->e455;
  res.e555 = lhs * rhs->e555;

  return res;

}

void onumm5n3_mul_ro_to(  coeff_t lhs,  onumm5n3_t* rhs, onumm5n3_t* res){
  // Multiplication like function 'lhs * rhs'
  //  Real;
  res->r = lhs * rhs->r;
  // Order 1;
  res->e1 = lhs * rhs->e1;
  res->e2 = lhs * rhs->e2;
  res->e3 = lhs * rhs->e3;
  res->e4 = lhs * rhs->e4;
  res->e5 = lhs * rhs->e5;
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
  res->e114 = lhs * rhs->e114;
  res->e124 = lhs * rhs->e124;
  res->e224 = lhs * rhs->e224;
  res->e134 = lhs * rhs->e134;
  res->e234 = lhs * rhs->e234;
  res->e334 = lhs * rhs->e334;
  res->e144 = lhs * rhs->e144;
  res->e244 = lhs * rhs->e244;
  res->e344 = lhs * rhs->e344;
  res->e444 = lhs * rhs->e444;
  res->e115 = lhs * rhs->e115;
  res->e125 = lhs * rhs->e125;
  res->e225 = lhs * rhs->e225;
  res->e135 = lhs * rhs->e135;
  res->e235 = lhs * rhs->e235;
  res->e335 = lhs * rhs->e335;
  res->e145 = lhs * rhs->e145;
  res->e245 = lhs * rhs->e245;
  res->e345 = lhs * rhs->e345;
  res->e445 = lhs * rhs->e445;
  res->e155 = lhs * rhs->e155;
  res->e255 = lhs * rhs->e255;
  res->e355 = lhs * rhs->e355;
  res->e455 = lhs * rhs->e455;
  res->e555 = lhs * rhs->e555;

}

onumm5n3_t onumm5n3_trunc_mul_oo(  onumm5n3_t* lhs,  onumm5n3_t* rhs){
  onumm5n3_t res;

  res = onumm5n3_init();

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
  res.e114 =  + lhs->e1 * rhs->e14 + lhs->e14 * rhs->e1 + lhs->e4 * rhs->e11 
           + lhs->e11 * rhs->e4;
  res.e124 =  + lhs->e1 * rhs->e24 + lhs->e24 * rhs->e1 + lhs->e2 * rhs->e14 
           + lhs->e14 * rhs->e2 + lhs->e4 * rhs->e12 + lhs->e12 * rhs->e4;
  res.e224 =  + lhs->e2 * rhs->e24 + lhs->e24 * rhs->e2 + lhs->e4 * rhs->e22 
           + lhs->e22 * rhs->e4;
  res.e134 =  + lhs->e1 * rhs->e34 + lhs->e34 * rhs->e1 + lhs->e3 * rhs->e14 
           + lhs->e14 * rhs->e3 + lhs->e4 * rhs->e13 + lhs->e13 * rhs->e4;
  res.e234 =  + lhs->e2 * rhs->e34 + lhs->e34 * rhs->e2 + lhs->e3 * rhs->e24 
           + lhs->e24 * rhs->e3 + lhs->e4 * rhs->e23 + lhs->e23 * rhs->e4;
  res.e334 =  + lhs->e3 * rhs->e34 + lhs->e34 * rhs->e3 + lhs->e4 * rhs->e33 
           + lhs->e33 * rhs->e4;
  res.e144 =  + lhs->e1 * rhs->e44 + lhs->e44 * rhs->e1 + lhs->e4 * rhs->e14 
           + lhs->e14 * rhs->e4;
  res.e244 =  + lhs->e2 * rhs->e44 + lhs->e44 * rhs->e2 + lhs->e4 * rhs->e24 
           + lhs->e24 * rhs->e4;
  res.e344 =  + lhs->e3 * rhs->e44 + lhs->e44 * rhs->e3 + lhs->e4 * rhs->e34 
           + lhs->e34 * rhs->e4;
  res.e444 =  + lhs->e4 * rhs->e44 + lhs->e44 * rhs->e4;
  res.e115 =  + lhs->e1 * rhs->e15 + lhs->e15 * rhs->e1 + lhs->e5 * rhs->e11 
           + lhs->e11 * rhs->e5;
  res.e125 =  + lhs->e1 * rhs->e25 + lhs->e25 * rhs->e1 + lhs->e2 * rhs->e15 
           + lhs->e15 * rhs->e2 + lhs->e5 * rhs->e12 + lhs->e12 * rhs->e5;
  res.e225 =  + lhs->e2 * rhs->e25 + lhs->e25 * rhs->e2 + lhs->e5 * rhs->e22 
           + lhs->e22 * rhs->e5;
  res.e135 =  + lhs->e1 * rhs->e35 + lhs->e35 * rhs->e1 + lhs->e3 * rhs->e15 
           + lhs->e15 * rhs->e3 + lhs->e5 * rhs->e13 + lhs->e13 * rhs->e5;
  res.e235 =  + lhs->e2 * rhs->e35 + lhs->e35 * rhs->e2 + lhs->e3 * rhs->e25 
           + lhs->e25 * rhs->e3 + lhs->e5 * rhs->e23 + lhs->e23 * rhs->e5;
  res.e335 =  + lhs->e3 * rhs->e35 + lhs->e35 * rhs->e3 + lhs->e5 * rhs->e33 
           + lhs->e33 * rhs->e5;
  res.e145 =  + lhs->e1 * rhs->e45 + lhs->e45 * rhs->e1 + lhs->e4 * rhs->e15 
           + lhs->e15 * rhs->e4 + lhs->e5 * rhs->e14 + lhs->e14 * rhs->e5;
  res.e245 =  + lhs->e2 * rhs->e45 + lhs->e45 * rhs->e2 + lhs->e4 * rhs->e25 
           + lhs->e25 * rhs->e4 + lhs->e5 * rhs->e24 + lhs->e24 * rhs->e5;
  res.e345 =  + lhs->e3 * rhs->e45 + lhs->e45 * rhs->e3 + lhs->e4 * rhs->e35 
           + lhs->e35 * rhs->e4 + lhs->e5 * rhs->e34 + lhs->e34 * rhs->e5;
  res.e445 =  + lhs->e4 * rhs->e45 + lhs->e45 * rhs->e4 + lhs->e5 * rhs->e44 
           + lhs->e44 * rhs->e5;
  res.e155 =  + lhs->e1 * rhs->e55 + lhs->e55 * rhs->e1 + lhs->e5 * rhs->e15 
           + lhs->e15 * rhs->e5;
  res.e255 =  + lhs->e2 * rhs->e55 + lhs->e55 * rhs->e2 + lhs->e5 * rhs->e25 
           + lhs->e25 * rhs->e5;
  res.e355 =  + lhs->e3 * rhs->e55 + lhs->e55 * rhs->e3 + lhs->e5 * rhs->e35 
           + lhs->e35 * rhs->e5;
  res.e455 =  + lhs->e4 * rhs->e55 + lhs->e55 * rhs->e4 + lhs->e5 * rhs->e45 
           + lhs->e45 * rhs->e5;
  res.e555 =  + lhs->e5 * rhs->e55 + lhs->e55 * rhs->e5;

  return res;

}

void onumm5n3_trunc_mul_oo_to(  onumm5n3_t* lhs,  onumm5n3_t* rhs, onumm5n3_t* res){
   (*res) = onumm5n3_init();

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
  res->e114 =  + lhs->e1 * rhs->e14 + lhs->e14 * rhs->e1 + lhs->e4 * rhs->e11 
           + lhs->e11 * rhs->e4;
  res->e124 =  + lhs->e1 * rhs->e24 + lhs->e24 * rhs->e1 + lhs->e2 * rhs->e14 
           + lhs->e14 * rhs->e2 + lhs->e4 * rhs->e12 + lhs->e12 * rhs->e4;
  res->e224 =  + lhs->e2 * rhs->e24 + lhs->e24 * rhs->e2 + lhs->e4 * rhs->e22 
           + lhs->e22 * rhs->e4;
  res->e134 =  + lhs->e1 * rhs->e34 + lhs->e34 * rhs->e1 + lhs->e3 * rhs->e14 
           + lhs->e14 * rhs->e3 + lhs->e4 * rhs->e13 + lhs->e13 * rhs->e4;
  res->e234 =  + lhs->e2 * rhs->e34 + lhs->e34 * rhs->e2 + lhs->e3 * rhs->e24 
           + lhs->e24 * rhs->e3 + lhs->e4 * rhs->e23 + lhs->e23 * rhs->e4;
  res->e334 =  + lhs->e3 * rhs->e34 + lhs->e34 * rhs->e3 + lhs->e4 * rhs->e33 
           + lhs->e33 * rhs->e4;
  res->e144 =  + lhs->e1 * rhs->e44 + lhs->e44 * rhs->e1 + lhs->e4 * rhs->e14 
           + lhs->e14 * rhs->e4;
  res->e244 =  + lhs->e2 * rhs->e44 + lhs->e44 * rhs->e2 + lhs->e4 * rhs->e24 
           + lhs->e24 * rhs->e4;
  res->e344 =  + lhs->e3 * rhs->e44 + lhs->e44 * rhs->e3 + lhs->e4 * rhs->e34 
           + lhs->e34 * rhs->e4;
  res->e444 =  + lhs->e4 * rhs->e44 + lhs->e44 * rhs->e4;
  res->e115 =  + lhs->e1 * rhs->e15 + lhs->e15 * rhs->e1 + lhs->e5 * rhs->e11 
           + lhs->e11 * rhs->e5;
  res->e125 =  + lhs->e1 * rhs->e25 + lhs->e25 * rhs->e1 + lhs->e2 * rhs->e15 
           + lhs->e15 * rhs->e2 + lhs->e5 * rhs->e12 + lhs->e12 * rhs->e5;
  res->e225 =  + lhs->e2 * rhs->e25 + lhs->e25 * rhs->e2 + lhs->e5 * rhs->e22 
           + lhs->e22 * rhs->e5;
  res->e135 =  + lhs->e1 * rhs->e35 + lhs->e35 * rhs->e1 + lhs->e3 * rhs->e15 
           + lhs->e15 * rhs->e3 + lhs->e5 * rhs->e13 + lhs->e13 * rhs->e5;
  res->e235 =  + lhs->e2 * rhs->e35 + lhs->e35 * rhs->e2 + lhs->e3 * rhs->e25 
           + lhs->e25 * rhs->e3 + lhs->e5 * rhs->e23 + lhs->e23 * rhs->e5;
  res->e335 =  + lhs->e3 * rhs->e35 + lhs->e35 * rhs->e3 + lhs->e5 * rhs->e33 
           + lhs->e33 * rhs->e5;
  res->e145 =  + lhs->e1 * rhs->e45 + lhs->e45 * rhs->e1 + lhs->e4 * rhs->e15 
           + lhs->e15 * rhs->e4 + lhs->e5 * rhs->e14 + lhs->e14 * rhs->e5;
  res->e245 =  + lhs->e2 * rhs->e45 + lhs->e45 * rhs->e2 + lhs->e4 * rhs->e25 
           + lhs->e25 * rhs->e4 + lhs->e5 * rhs->e24 + lhs->e24 * rhs->e5;
  res->e345 =  + lhs->e3 * rhs->e45 + lhs->e45 * rhs->e3 + lhs->e4 * rhs->e35 
           + lhs->e35 * rhs->e4 + lhs->e5 * rhs->e34 + lhs->e34 * rhs->e5;
  res->e445 =  + lhs->e4 * rhs->e45 + lhs->e45 * rhs->e4 + lhs->e5 * rhs->e44 
           + lhs->e44 * rhs->e5;
  res->e155 =  + lhs->e1 * rhs->e55 + lhs->e55 * rhs->e1 + lhs->e5 * rhs->e15 
           + lhs->e15 * rhs->e5;
  res->e255 =  + lhs->e2 * rhs->e55 + lhs->e55 * rhs->e2 + lhs->e5 * rhs->e25 
           + lhs->e25 * rhs->e5;
  res->e355 =  + lhs->e3 * rhs->e55 + lhs->e55 * rhs->e3 + lhs->e5 * rhs->e35 
           + lhs->e35 * rhs->e5;
  res->e455 =  + lhs->e4 * rhs->e55 + lhs->e55 * rhs->e4 + lhs->e5 * rhs->e45 
           + lhs->e45 * rhs->e5;
  res->e555 =  + lhs->e5 * rhs->e55 + lhs->e55 * rhs->e5;

}

onumm5n3_t onumm5n3_gem_oo(  onumm5n3_t* a,  onumm5n3_t* b,  onumm5n3_t* c){
  onumm5n3_t res;

  //  General multiplication like function 'a * b + c'
  // Real;
  res.r = c->r + a->r * b->r;
  // Order 1;
  res.e1 = c->e1 + a->r * b->e1 + a->e1 * b->r;
  res.e2 = c->e2 + a->r * b->e2 + a->e2 * b->r;
  res.e3 = c->e3 + a->r * b->e3 + a->e3 * b->r;
  res.e4 = c->e4 + a->r * b->e4 + a->e4 * b->r;
  res.e5 = c->e5 + a->r * b->e5 + a->e5 * b->r;
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
  res.e114 = c->e114 + a->r * b->e114 + a->e114 * b->r + a->e1 * b->e14 
           + a->e14 * b->e1 + a->e4 * b->e11 + a->e11 * b->e4;
  res.e124 = c->e124 + a->r * b->e124 + a->e124 * b->r + a->e1 * b->e24 
           + a->e24 * b->e1 + a->e2 * b->e14 + a->e14 * b->e2 
           + a->e4 * b->e12 + a->e12 * b->e4;
  res.e224 = c->e224 + a->r * b->e224 + a->e224 * b->r + a->e2 * b->e24 
           + a->e24 * b->e2 + a->e4 * b->e22 + a->e22 * b->e4;
  res.e134 = c->e134 + a->r * b->e134 + a->e134 * b->r + a->e1 * b->e34 
           + a->e34 * b->e1 + a->e3 * b->e14 + a->e14 * b->e3 
           + a->e4 * b->e13 + a->e13 * b->e4;
  res.e234 = c->e234 + a->r * b->e234 + a->e234 * b->r + a->e2 * b->e34 
           + a->e34 * b->e2 + a->e3 * b->e24 + a->e24 * b->e3 
           + a->e4 * b->e23 + a->e23 * b->e4;
  res.e334 = c->e334 + a->r * b->e334 + a->e334 * b->r + a->e3 * b->e34 
           + a->e34 * b->e3 + a->e4 * b->e33 + a->e33 * b->e4;
  res.e144 = c->e144 + a->r * b->e144 + a->e144 * b->r + a->e1 * b->e44 
           + a->e44 * b->e1 + a->e4 * b->e14 + a->e14 * b->e4;
  res.e244 = c->e244 + a->r * b->e244 + a->e244 * b->r + a->e2 * b->e44 
           + a->e44 * b->e2 + a->e4 * b->e24 + a->e24 * b->e4;
  res.e344 = c->e344 + a->r * b->e344 + a->e344 * b->r + a->e3 * b->e44 
           + a->e44 * b->e3 + a->e4 * b->e34 + a->e34 * b->e4;
  res.e444 = c->e444 + a->r * b->e444 + a->e444 * b->r + a->e4 * b->e44 
           + a->e44 * b->e4;
  res.e115 = c->e115 + a->r * b->e115 + a->e115 * b->r + a->e1 * b->e15 
           + a->e15 * b->e1 + a->e5 * b->e11 + a->e11 * b->e5;
  res.e125 = c->e125 + a->r * b->e125 + a->e125 * b->r + a->e1 * b->e25 
           + a->e25 * b->e1 + a->e2 * b->e15 + a->e15 * b->e2 
           + a->e5 * b->e12 + a->e12 * b->e5;
  res.e225 = c->e225 + a->r * b->e225 + a->e225 * b->r + a->e2 * b->e25 
           + a->e25 * b->e2 + a->e5 * b->e22 + a->e22 * b->e5;
  res.e135 = c->e135 + a->r * b->e135 + a->e135 * b->r + a->e1 * b->e35 
           + a->e35 * b->e1 + a->e3 * b->e15 + a->e15 * b->e3 
           + a->e5 * b->e13 + a->e13 * b->e5;
  res.e235 = c->e235 + a->r * b->e235 + a->e235 * b->r + a->e2 * b->e35 
           + a->e35 * b->e2 + a->e3 * b->e25 + a->e25 * b->e3 
           + a->e5 * b->e23 + a->e23 * b->e5;
  res.e335 = c->e335 + a->r * b->e335 + a->e335 * b->r + a->e3 * b->e35 
           + a->e35 * b->e3 + a->e5 * b->e33 + a->e33 * b->e5;
  res.e145 = c->e145 + a->r * b->e145 + a->e145 * b->r + a->e1 * b->e45 
           + a->e45 * b->e1 + a->e4 * b->e15 + a->e15 * b->e4 
           + a->e5 * b->e14 + a->e14 * b->e5;
  res.e245 = c->e245 + a->r * b->e245 + a->e245 * b->r + a->e2 * b->e45 
           + a->e45 * b->e2 + a->e4 * b->e25 + a->e25 * b->e4 
           + a->e5 * b->e24 + a->e24 * b->e5;
  res.e345 = c->e345 + a->r * b->e345 + a->e345 * b->r + a->e3 * b->e45 
           + a->e45 * b->e3 + a->e4 * b->e35 + a->e35 * b->e4 
           + a->e5 * b->e34 + a->e34 * b->e5;
  res.e445 = c->e445 + a->r * b->e445 + a->e445 * b->r + a->e4 * b->e45 
           + a->e45 * b->e4 + a->e5 * b->e44 + a->e44 * b->e5;
  res.e155 = c->e155 + a->r * b->e155 + a->e155 * b->r + a->e1 * b->e55 
           + a->e55 * b->e1 + a->e5 * b->e15 + a->e15 * b->e5;
  res.e255 = c->e255 + a->r * b->e255 + a->e255 * b->r + a->e2 * b->e55 
           + a->e55 * b->e2 + a->e5 * b->e25 + a->e25 * b->e5;
  res.e355 = c->e355 + a->r * b->e355 + a->e355 * b->r + a->e3 * b->e55 
           + a->e55 * b->e3 + a->e5 * b->e35 + a->e35 * b->e5;
  res.e455 = c->e455 + a->r * b->e455 + a->e455 * b->r + a->e4 * b->e55 
           + a->e55 * b->e4 + a->e5 * b->e45 + a->e45 * b->e5;
  res.e555 = c->e555 + a->r * b->e555 + a->e555 * b->r + a->e5 * b->e55 
           + a->e55 * b->e5;

  return res;

}

void onumm5n3_gem_oo_to(  onumm5n3_t* a,  onumm5n3_t* b,  onumm5n3_t* c, onumm5n3_t* res){
  //  General multiplication like function 'a * b + c'
  // Real;
  res->r = c->r + a->r * b->r;
  // Order 1;
  res->e1 = c->e1 + a->r * b->e1 + a->e1 * b->r;
  res->e2 = c->e2 + a->r * b->e2 + a->e2 * b->r;
  res->e3 = c->e3 + a->r * b->e3 + a->e3 * b->r;
  res->e4 = c->e4 + a->r * b->e4 + a->e4 * b->r;
  res->e5 = c->e5 + a->r * b->e5 + a->e5 * b->r;
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
  res->e114 = c->e114 + a->r * b->e114 + a->e114 * b->r + a->e1 * b->e14 
           + a->e14 * b->e1 + a->e4 * b->e11 + a->e11 * b->e4;
  res->e124 = c->e124 + a->r * b->e124 + a->e124 * b->r + a->e1 * b->e24 
           + a->e24 * b->e1 + a->e2 * b->e14 + a->e14 * b->e2 
           + a->e4 * b->e12 + a->e12 * b->e4;
  res->e224 = c->e224 + a->r * b->e224 + a->e224 * b->r + a->e2 * b->e24 
           + a->e24 * b->e2 + a->e4 * b->e22 + a->e22 * b->e4;
  res->e134 = c->e134 + a->r * b->e134 + a->e134 * b->r + a->e1 * b->e34 
           + a->e34 * b->e1 + a->e3 * b->e14 + a->e14 * b->e3 
           + a->e4 * b->e13 + a->e13 * b->e4;
  res->e234 = c->e234 + a->r * b->e234 + a->e234 * b->r + a->e2 * b->e34 
           + a->e34 * b->e2 + a->e3 * b->e24 + a->e24 * b->e3 
           + a->e4 * b->e23 + a->e23 * b->e4;
  res->e334 = c->e334 + a->r * b->e334 + a->e334 * b->r + a->e3 * b->e34 
           + a->e34 * b->e3 + a->e4 * b->e33 + a->e33 * b->e4;
  res->e144 = c->e144 + a->r * b->e144 + a->e144 * b->r + a->e1 * b->e44 
           + a->e44 * b->e1 + a->e4 * b->e14 + a->e14 * b->e4;
  res->e244 = c->e244 + a->r * b->e244 + a->e244 * b->r + a->e2 * b->e44 
           + a->e44 * b->e2 + a->e4 * b->e24 + a->e24 * b->e4;
  res->e344 = c->e344 + a->r * b->e344 + a->e344 * b->r + a->e3 * b->e44 
           + a->e44 * b->e3 + a->e4 * b->e34 + a->e34 * b->e4;
  res->e444 = c->e444 + a->r * b->e444 + a->e444 * b->r + a->e4 * b->e44 
           + a->e44 * b->e4;
  res->e115 = c->e115 + a->r * b->e115 + a->e115 * b->r + a->e1 * b->e15 
           + a->e15 * b->e1 + a->e5 * b->e11 + a->e11 * b->e5;
  res->e125 = c->e125 + a->r * b->e125 + a->e125 * b->r + a->e1 * b->e25 
           + a->e25 * b->e1 + a->e2 * b->e15 + a->e15 * b->e2 
           + a->e5 * b->e12 + a->e12 * b->e5;
  res->e225 = c->e225 + a->r * b->e225 + a->e225 * b->r + a->e2 * b->e25 
           + a->e25 * b->e2 + a->e5 * b->e22 + a->e22 * b->e5;
  res->e135 = c->e135 + a->r * b->e135 + a->e135 * b->r + a->e1 * b->e35 
           + a->e35 * b->e1 + a->e3 * b->e15 + a->e15 * b->e3 
           + a->e5 * b->e13 + a->e13 * b->e5;
  res->e235 = c->e235 + a->r * b->e235 + a->e235 * b->r + a->e2 * b->e35 
           + a->e35 * b->e2 + a->e3 * b->e25 + a->e25 * b->e3 
           + a->e5 * b->e23 + a->e23 * b->e5;
  res->e335 = c->e335 + a->r * b->e335 + a->e335 * b->r + a->e3 * b->e35 
           + a->e35 * b->e3 + a->e5 * b->e33 + a->e33 * b->e5;
  res->e145 = c->e145 + a->r * b->e145 + a->e145 * b->r + a->e1 * b->e45 
           + a->e45 * b->e1 + a->e4 * b->e15 + a->e15 * b->e4 
           + a->e5 * b->e14 + a->e14 * b->e5;
  res->e245 = c->e245 + a->r * b->e245 + a->e245 * b->r + a->e2 * b->e45 
           + a->e45 * b->e2 + a->e4 * b->e25 + a->e25 * b->e4 
           + a->e5 * b->e24 + a->e24 * b->e5;
  res->e345 = c->e345 + a->r * b->e345 + a->e345 * b->r + a->e3 * b->e45 
           + a->e45 * b->e3 + a->e4 * b->e35 + a->e35 * b->e4 
           + a->e5 * b->e34 + a->e34 * b->e5;
  res->e445 = c->e445 + a->r * b->e445 + a->e445 * b->r + a->e4 * b->e45 
           + a->e45 * b->e4 + a->e5 * b->e44 + a->e44 * b->e5;
  res->e155 = c->e155 + a->r * b->e155 + a->e155 * b->r + a->e1 * b->e55 
           + a->e55 * b->e1 + a->e5 * b->e15 + a->e15 * b->e5;
  res->e255 = c->e255 + a->r * b->e255 + a->e255 * b->r + a->e2 * b->e55 
           + a->e55 * b->e2 + a->e5 * b->e25 + a->e25 * b->e5;
  res->e355 = c->e355 + a->r * b->e355 + a->e355 * b->r + a->e3 * b->e55 
           + a->e55 * b->e3 + a->e5 * b->e35 + a->e35 * b->e5;
  res->e455 = c->e455 + a->r * b->e455 + a->e455 * b->r + a->e4 * b->e55 
           + a->e55 * b->e4 + a->e5 * b->e45 + a->e45 * b->e5;
  res->e555 = c->e555 + a->r * b->e555 + a->e555 * b->r + a->e5 * b->e55 
           + a->e55 * b->e5;

}

onumm5n3_t onumm5n3_gem_ro(  coeff_t a,  onumm5n3_t* b,  onumm5n3_t* c){
  onumm5n3_t res;

  //  General multiplication like function 'a * b + c'
  // Real;
  res.r = c->r + a * b->r;
  // Order 1;
  res.e1 = c->e1 + a * b->e1;
  res.e2 = c->e2 + a * b->e2;
  res.e3 = c->e3 + a * b->e3;
  res.e4 = c->e4 + a * b->e4;
  res.e5 = c->e5 + a * b->e5;
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
  res.e114 = c->e114 + a * b->e114;
  res.e124 = c->e124 + a * b->e124;
  res.e224 = c->e224 + a * b->e224;
  res.e134 = c->e134 + a * b->e134;
  res.e234 = c->e234 + a * b->e234;
  res.e334 = c->e334 + a * b->e334;
  res.e144 = c->e144 + a * b->e144;
  res.e244 = c->e244 + a * b->e244;
  res.e344 = c->e344 + a * b->e344;
  res.e444 = c->e444 + a * b->e444;
  res.e115 = c->e115 + a * b->e115;
  res.e125 = c->e125 + a * b->e125;
  res.e225 = c->e225 + a * b->e225;
  res.e135 = c->e135 + a * b->e135;
  res.e235 = c->e235 + a * b->e235;
  res.e335 = c->e335 + a * b->e335;
  res.e145 = c->e145 + a * b->e145;
  res.e245 = c->e245 + a * b->e245;
  res.e345 = c->e345 + a * b->e345;
  res.e445 = c->e445 + a * b->e445;
  res.e155 = c->e155 + a * b->e155;
  res.e255 = c->e255 + a * b->e255;
  res.e355 = c->e355 + a * b->e355;
  res.e455 = c->e455 + a * b->e455;
  res.e555 = c->e555 + a * b->e555;

  return res;

}

void onumm5n3_gem_ro_to(  coeff_t a,  onumm5n3_t* b,  onumm5n3_t* c, onumm5n3_t* res){
  //  General multiplication like function 'a * b + c'
  // Real;
  res->r = c->r + a * b->r;
  // Order 1;
  res->e1 = c->e1 + a * b->e1;
  res->e2 = c->e2 + a * b->e2;
  res->e3 = c->e3 + a * b->e3;
  res->e4 = c->e4 + a * b->e4;
  res->e5 = c->e5 + a * b->e5;
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
  res->e114 = c->e114 + a * b->e114;
  res->e124 = c->e124 + a * b->e124;
  res->e224 = c->e224 + a * b->e224;
  res->e134 = c->e134 + a * b->e134;
  res->e234 = c->e234 + a * b->e234;
  res->e334 = c->e334 + a * b->e334;
  res->e144 = c->e144 + a * b->e144;
  res->e244 = c->e244 + a * b->e244;
  res->e344 = c->e344 + a * b->e344;
  res->e444 = c->e444 + a * b->e444;
  res->e115 = c->e115 + a * b->e115;
  res->e125 = c->e125 + a * b->e125;
  res->e225 = c->e225 + a * b->e225;
  res->e135 = c->e135 + a * b->e135;
  res->e235 = c->e235 + a * b->e235;
  res->e335 = c->e335 + a * b->e335;
  res->e145 = c->e145 + a * b->e145;
  res->e245 = c->e245 + a * b->e245;
  res->e345 = c->e345 + a * b->e345;
  res->e445 = c->e445 + a * b->e445;
  res->e155 = c->e155 + a * b->e155;
  res->e255 = c->e255 + a * b->e255;
  res->e355 = c->e355 + a * b->e355;
  res->e455 = c->e455 + a * b->e455;
  res->e555 = c->e555 + a * b->e555;

}

void onumm5n3_trunc_gem_oo_to( ord_t ord_lhs,  onumm5n3_t* a,  ord_t ord_rhs,  onumm5n3_t* b,  onumm5n3_t* c, onumm5n3_t* res){
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
          res->e114 = c->e114 + a->r * b->e114;
          res->e124 = c->e124 + a->r * b->e124;
          res->e224 = c->e224 + a->r * b->e224;
          res->e134 = c->e134 + a->r * b->e134;
          res->e234 = c->e234 + a->r * b->e234;
          res->e334 = c->e334 + a->r * b->e334;
          res->e144 = c->e144 + a->r * b->e144;
          res->e244 = c->e244 + a->r * b->e244;
          res->e344 = c->e344 + a->r * b->e344;
          res->e444 = c->e444 + a->r * b->e444;
          res->e115 = c->e115 + a->r * b->e115;
          res->e125 = c->e125 + a->r * b->e125;
          res->e225 = c->e225 + a->r * b->e225;
          res->e135 = c->e135 + a->r * b->e135;
          res->e235 = c->e235 + a->r * b->e235;
          res->e335 = c->e335 + a->r * b->e335;
          res->e145 = c->e145 + a->r * b->e145;
          res->e245 = c->e245 + a->r * b->e245;
          res->e345 = c->e345 + a->r * b->e345;
          res->e445 = c->e445 + a->r * b->e445;
          res->e155 = c->e155 + a->r * b->e155;
          res->e255 = c->e255 + a->r * b->e255;
          res->e355 = c->e355 + a->r * b->e355;
          res->e455 = c->e455 + a->r * b->e455;
          res->e555 = c->e555 + a->r * b->e555;
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
          res->e114 = c->e114 + a->e1 * b->e14 + a->e4 * b->e11;
          res->e124 = c->e124 + a->e1 * b->e24 + a->e2 * b->e14 
                    + a->e4 * b->e12;
          res->e224 = c->e224 + a->e2 * b->e24 + a->e4 * b->e22;
          res->e134 = c->e134 + a->e1 * b->e34 + a->e3 * b->e14 
                    + a->e4 * b->e13;
          res->e234 = c->e234 + a->e2 * b->e34 + a->e3 * b->e24 
                    + a->e4 * b->e23;
          res->e334 = c->e334 + a->e3 * b->e34 + a->e4 * b->e33;
          res->e144 = c->e144 + a->e1 * b->e44 + a->e4 * b->e14;
          res->e244 = c->e244 + a->e2 * b->e44 + a->e4 * b->e24;
          res->e344 = c->e344 + a->e3 * b->e44 + a->e4 * b->e34;
          res->e444 = c->e444 + a->e4 * b->e44;
          res->e115 = c->e115 + a->e1 * b->e15 + a->e5 * b->e11;
          res->e125 = c->e125 + a->e1 * b->e25 + a->e2 * b->e15 
                    + a->e5 * b->e12;
          res->e225 = c->e225 + a->e2 * b->e25 + a->e5 * b->e22;
          res->e135 = c->e135 + a->e1 * b->e35 + a->e3 * b->e15 
                    + a->e5 * b->e13;
          res->e235 = c->e235 + a->e2 * b->e35 + a->e3 * b->e25 
                    + a->e5 * b->e23;
          res->e335 = c->e335 + a->e3 * b->e35 + a->e5 * b->e33;
          res->e145 = c->e145 + a->e1 * b->e45 + a->e4 * b->e15 
                    + a->e5 * b->e14;
          res->e245 = c->e245 + a->e2 * b->e45 + a->e4 * b->e25 
                    + a->e5 * b->e24;
          res->e345 = c->e345 + a->e3 * b->e45 + a->e4 * b->e35 
                    + a->e5 * b->e34;
          res->e445 = c->e445 + a->e4 * b->e45 + a->e5 * b->e44;
          res->e155 = c->e155 + a->e1 * b->e55 + a->e5 * b->e15;
          res->e255 = c->e255 + a->e2 * b->e55 + a->e5 * b->e25;
          res->e355 = c->e355 + a->e3 * b->e55 + a->e5 * b->e35;
          res->e455 = c->e455 + a->e4 * b->e55 + a->e5 * b->e45;
          res->e555 = c->e555 + a->e5 * b->e55;
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
          res->e114 = c->e114 + a->e14 * b->e1 + a->e11 * b->e4;
          res->e124 = c->e124 + a->e24 * b->e1 + a->e14 * b->e2 
                    + a->e12 * b->e4;
          res->e224 = c->e224 + a->e24 * b->e2 + a->e22 * b->e4;
          res->e134 = c->e134 + a->e34 * b->e1 + a->e14 * b->e3 
                    + a->e13 * b->e4;
          res->e234 = c->e234 + a->e34 * b->e2 + a->e24 * b->e3 
                    + a->e23 * b->e4;
          res->e334 = c->e334 + a->e34 * b->e3 + a->e33 * b->e4;
          res->e144 = c->e144 + a->e44 * b->e1 + a->e14 * b->e4;
          res->e244 = c->e244 + a->e44 * b->e2 + a->e24 * b->e4;
          res->e344 = c->e344 + a->e44 * b->e3 + a->e34 * b->e4;
          res->e444 = c->e444 + a->e44 * b->e4;
          res->e115 = c->e115 + a->e15 * b->e1 + a->e11 * b->e5;
          res->e125 = c->e125 + a->e25 * b->e1 + a->e15 * b->e2 
                    + a->e12 * b->e5;
          res->e225 = c->e225 + a->e25 * b->e2 + a->e22 * b->e5;
          res->e135 = c->e135 + a->e35 * b->e1 + a->e15 * b->e3 
                    + a->e13 * b->e5;
          res->e235 = c->e235 + a->e35 * b->e2 + a->e25 * b->e3 
                    + a->e23 * b->e5;
          res->e335 = c->e335 + a->e35 * b->e3 + a->e33 * b->e5;
          res->e145 = c->e145 + a->e45 * b->e1 + a->e15 * b->e4 
                    + a->e14 * b->e5;
          res->e245 = c->e245 + a->e45 * b->e2 + a->e25 * b->e4 
                    + a->e24 * b->e5;
          res->e345 = c->e345 + a->e45 * b->e3 + a->e35 * b->e4 
                    + a->e34 * b->e5;
          res->e445 = c->e445 + a->e45 * b->e4 + a->e44 * b->e5;
          res->e155 = c->e155 + a->e55 * b->e1 + a->e15 * b->e5;
          res->e255 = c->e255 + a->e55 * b->e2 + a->e25 * b->e5;
          res->e355 = c->e355 + a->e55 * b->e3 + a->e35 * b->e5;
          res->e455 = c->e455 + a->e55 * b->e4 + a->e45 * b->e5;
          res->e555 = c->e555 + a->e55 * b->e5;
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
          res->e114 = c->e114 + a->e114 * b->r;
          res->e124 = c->e124 + a->e124 * b->r;
          res->e224 = c->e224 + a->e224 * b->r;
          res->e134 = c->e134 + a->e134 * b->r;
          res->e234 = c->e234 + a->e234 * b->r;
          res->e334 = c->e334 + a->e334 * b->r;
          res->e144 = c->e144 + a->e144 * b->r;
          res->e244 = c->e244 + a->e244 * b->r;
          res->e344 = c->e344 + a->e344 * b->r;
          res->e444 = c->e444 + a->e444 * b->r;
          res->e115 = c->e115 + a->e115 * b->r;
          res->e125 = c->e125 + a->e125 * b->r;
          res->e225 = c->e225 + a->e225 * b->r;
          res->e135 = c->e135 + a->e135 * b->r;
          res->e235 = c->e235 + a->e235 * b->r;
          res->e335 = c->e335 + a->e335 * b->r;
          res->e145 = c->e145 + a->e145 * b->r;
          res->e245 = c->e245 + a->e245 * b->r;
          res->e345 = c->e345 + a->e345 * b->r;
          res->e445 = c->e445 + a->e445 * b->r;
          res->e155 = c->e155 + a->e155 * b->r;
          res->e255 = c->e255 + a->e255 * b->r;
          res->e355 = c->e355 + a->e355 * b->r;
          res->e455 = c->e455 + a->e455 * b->r;
          res->e555 = c->e555 + a->e555 * b->r;
          break;
      }
      break;
  }

}

void onumm5n3_trunc_sum_oo_to(ord_t order, onumm5n3_t* lhs,onumm5n3_t* rhs, onumm5n3_t* res){
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
      res->e114 = lhs->e114 + rhs->e114;
      res->e124 = lhs->e124 + rhs->e124;
      res->e224 = lhs->e224 + rhs->e224;
      res->e134 = lhs->e134 + rhs->e134;
      res->e234 = lhs->e234 + rhs->e234;
      res->e334 = lhs->e334 + rhs->e334;
      res->e144 = lhs->e144 + rhs->e144;
      res->e244 = lhs->e244 + rhs->e244;
      res->e344 = lhs->e344 + rhs->e344;
      res->e444 = lhs->e444 + rhs->e444;
      res->e115 = lhs->e115 + rhs->e115;
      res->e125 = lhs->e125 + rhs->e125;
      res->e225 = lhs->e225 + rhs->e225;
      res->e135 = lhs->e135 + rhs->e135;
      res->e235 = lhs->e235 + rhs->e235;
      res->e335 = lhs->e335 + rhs->e335;
      res->e145 = lhs->e145 + rhs->e145;
      res->e245 = lhs->e245 + rhs->e245;
      res->e345 = lhs->e345 + rhs->e345;
      res->e445 = lhs->e445 + rhs->e445;
      res->e155 = lhs->e155 + rhs->e155;
      res->e255 = lhs->e255 + rhs->e255;
      res->e355 = lhs->e355 + rhs->e355;
      res->e455 = lhs->e455 + rhs->e455;
      res->e555 = lhs->e555 + rhs->e555;
      break;
  }
}

void onumm5n3_trunc_sub_oo_to(ord_t order, onumm5n3_t* lhs,onumm5n3_t* rhs, onumm5n3_t* res){
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
      res->e114 = lhs->e114 - rhs->e114;
      res->e124 = lhs->e124 - rhs->e124;
      res->e224 = lhs->e224 - rhs->e224;
      res->e134 = lhs->e134 - rhs->e134;
      res->e234 = lhs->e234 - rhs->e234;
      res->e334 = lhs->e334 - rhs->e334;
      res->e144 = lhs->e144 - rhs->e144;
      res->e244 = lhs->e244 - rhs->e244;
      res->e344 = lhs->e344 - rhs->e344;
      res->e444 = lhs->e444 - rhs->e444;
      res->e115 = lhs->e115 - rhs->e115;
      res->e125 = lhs->e125 - rhs->e125;
      res->e225 = lhs->e225 - rhs->e225;
      res->e135 = lhs->e135 - rhs->e135;
      res->e235 = lhs->e235 - rhs->e235;
      res->e335 = lhs->e335 - rhs->e335;
      res->e145 = lhs->e145 - rhs->e145;
      res->e245 = lhs->e245 - rhs->e245;
      res->e345 = lhs->e345 - rhs->e345;
      res->e445 = lhs->e445 - rhs->e445;
      res->e155 = lhs->e155 - rhs->e155;
      res->e255 = lhs->e255 - rhs->e255;
      res->e355 = lhs->e355 - rhs->e355;
      res->e455 = lhs->e455 - rhs->e455;
      res->e555 = lhs->e555 - rhs->e555;
      break;
  }
}

onumm5n3_t onumm5n3_feval(coeff_t* feval_re, onumm5n3_t* x){

  onumm5n3_t res;

  // feval function
  //  Definitions
  coeff_t factor=1, coef = 0;
  onumm5n3_t deltax = (*x), deltax_power = (*x);
  deltax.r = 0.0;
  deltax_power.r = 0.0;
  onumm5n3_set_r(0.0, &res);
  //  Real
  res.r = feval_re[0];
  // Order 1
  factor *=1;
  coef    = feval_re[1]/ factor;;
  onumm5n3_gem_ro_to( coef, &deltax_power, &res, &res);
  deltax_power = onumm5n3_mul_oo(&deltax_power,&deltax);
  // Order 2
  factor *=2;
  coef    = feval_re[2]/ factor;;
  onumm5n3_gem_ro_to( coef, &deltax_power, &res, &res);
  deltax_power = onumm5n3_mul_oo(&deltax_power,&deltax);
  // Order 3
  factor *=3;
  coef    = feval_re[3]/ factor;;
  onumm5n3_gem_ro_to( coef, &deltax_power, &res, &res);

  return res;

}

void onumm5n3_feval_to(coeff_t* feval_re, onumm5n3_t* x, onumm5n3_t* res){

  // feval function
  //  Definitions
  coeff_t factor=1, coef = 0;
  onumm5n3_t deltax = (*x), deltax_power = (*x);
  deltax.r = 0.0;
  deltax_power.r = 0.0;
  onumm5n3_set_r(0.0, res);
  //  Real
  res->r = feval_re[0];
  // Order 1
  factor *=1;
  coef    = feval_re[1]/ factor;;
  onumm5n3_gem_ro_to( coef, &deltax_power, res, res);
  deltax_power = onumm5n3_mul_oo(&deltax_power,&deltax);
  // Order 2
  factor *=2;
  coef    = feval_re[2]/ factor;;
  onumm5n3_gem_ro_to( coef, &deltax_power, res, res);
  deltax_power = onumm5n3_mul_oo(&deltax_power,&deltax);
  // Order 3
  factor *=3;
  coef    = feval_re[3]/ factor;;
  onumm5n3_gem_ro_to( coef, &deltax_power, res, res);

}

