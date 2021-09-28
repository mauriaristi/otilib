
// Division.

// ****************************************************************************************************
onumm4n4_t onumm4n4_div_ro(coeff_t num, onumm4n4_t* den){

    
    onumm4n4_t inv = onumm4n4_pow(den,-1);
    onumm4n4_t res = onumm4n4_mul_ro(num,&inv);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
onumm4n4_t onumm4n4_div_oo(onumm4n4_t* num, onumm4n4_t* den){

    
    onumm4n4_t inv = onumm4n4_init();
    onumm4n4_pow_to(den,-1,&inv);
    onumm4n4_t res = onumm4n4_mul_oo(num,&inv);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
onumm4n4_t onumm4n4_div_or(onumm4n4_t* num, coeff_t val){

    return onumm4n4_mul_ro(1.0/val,num);

}
// ----------------------------------------------------------------------------------------------------

onumm4n4_t onumm4n4_neg(  onumm4n4_t* lhs){

  onumm4n4_t res;

  // Negation like function '-lhs'
  // Real;
  res.r = -lhs->r;
  // Order 1;
  res.e1 = -lhs->e1;
  res.e2 = -lhs->e2;
  res.e3 = -lhs->e3;
  res.e4 = -lhs->e4;
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
  res.e1114 = -lhs->e1114;
  res.e1124 = -lhs->e1124;
  res.e1224 = -lhs->e1224;
  res.e2224 = -lhs->e2224;
  res.e1134 = -lhs->e1134;
  res.e1234 = -lhs->e1234;
  res.e2234 = -lhs->e2234;
  res.e1334 = -lhs->e1334;
  res.e2334 = -lhs->e2334;
  res.e3334 = -lhs->e3334;
  res.e1144 = -lhs->e1144;
  res.e1244 = -lhs->e1244;
  res.e2244 = -lhs->e2244;
  res.e1344 = -lhs->e1344;
  res.e2344 = -lhs->e2344;
  res.e3344 = -lhs->e3344;
  res.e1444 = -lhs->e1444;
  res.e2444 = -lhs->e2444;
  res.e3444 = -lhs->e3444;
  res.e4444 = -lhs->e4444;

  return res;

}

void onumm4n4_neg_to(  onumm4n4_t* lhs, onumm4n4_t* res){

  // Negation like function '-lhs'
  // Real;
  res->r = -lhs->r;
  // Order 1;
  res->e1 = -lhs->e1;
  res->e2 = -lhs->e2;
  res->e3 = -lhs->e3;
  res->e4 = -lhs->e4;
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
  res->e1114 = -lhs->e1114;
  res->e1124 = -lhs->e1124;
  res->e1224 = -lhs->e1224;
  res->e2224 = -lhs->e2224;
  res->e1134 = -lhs->e1134;
  res->e1234 = -lhs->e1234;
  res->e2234 = -lhs->e2234;
  res->e1334 = -lhs->e1334;
  res->e2334 = -lhs->e2334;
  res->e3334 = -lhs->e3334;
  res->e1144 = -lhs->e1144;
  res->e1244 = -lhs->e1244;
  res->e2244 = -lhs->e2244;
  res->e1344 = -lhs->e1344;
  res->e2344 = -lhs->e2344;
  res->e3344 = -lhs->e3344;
  res->e1444 = -lhs->e1444;
  res->e2444 = -lhs->e2444;
  res->e3444 = -lhs->e3444;
  res->e4444 = -lhs->e4444;

}

onumm4n4_t onumm4n4_add_oo(  onumm4n4_t* lhs,  onumm4n4_t* rhs){
  onumm4n4_t res;

  // Addition like function 'lhs + rhs'
  //  Real
  res.r = lhs->r + rhs->r;
  // Order 1
  res.e1 = lhs->e1 + rhs->e1;
  res.e2 = lhs->e2 + rhs->e2;
  res.e3 = lhs->e3 + rhs->e3;
  res.e4 = lhs->e4 + rhs->e4;
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
  res.e1114 = lhs->e1114 + rhs->e1114;
  res.e1124 = lhs->e1124 + rhs->e1124;
  res.e1224 = lhs->e1224 + rhs->e1224;
  res.e2224 = lhs->e2224 + rhs->e2224;
  res.e1134 = lhs->e1134 + rhs->e1134;
  res.e1234 = lhs->e1234 + rhs->e1234;
  res.e2234 = lhs->e2234 + rhs->e2234;
  res.e1334 = lhs->e1334 + rhs->e1334;
  res.e2334 = lhs->e2334 + rhs->e2334;
  res.e3334 = lhs->e3334 + rhs->e3334;
  res.e1144 = lhs->e1144 + rhs->e1144;
  res.e1244 = lhs->e1244 + rhs->e1244;
  res.e2244 = lhs->e2244 + rhs->e2244;
  res.e1344 = lhs->e1344 + rhs->e1344;
  res.e2344 = lhs->e2344 + rhs->e2344;
  res.e3344 = lhs->e3344 + rhs->e3344;
  res.e1444 = lhs->e1444 + rhs->e1444;
  res.e2444 = lhs->e2444 + rhs->e2444;
  res.e3444 = lhs->e3444 + rhs->e3444;
  res.e4444 = lhs->e4444 + rhs->e4444;

  return res;

}

void onumm4n4_add_oo_to(  onumm4n4_t* lhs,  onumm4n4_t* rhs, onumm4n4_t* res){
  // Addition like function 'lhs + rhs'
  //  Real
  res->r = lhs->r + rhs->r;
  // Order 1
  res->e1 = lhs->e1 + rhs->e1;
  res->e2 = lhs->e2 + rhs->e2;
  res->e3 = lhs->e3 + rhs->e3;
  res->e4 = lhs->e4 + rhs->e4;
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
  res->e1114 = lhs->e1114 + rhs->e1114;
  res->e1124 = lhs->e1124 + rhs->e1124;
  res->e1224 = lhs->e1224 + rhs->e1224;
  res->e2224 = lhs->e2224 + rhs->e2224;
  res->e1134 = lhs->e1134 + rhs->e1134;
  res->e1234 = lhs->e1234 + rhs->e1234;
  res->e2234 = lhs->e2234 + rhs->e2234;
  res->e1334 = lhs->e1334 + rhs->e1334;
  res->e2334 = lhs->e2334 + rhs->e2334;
  res->e3334 = lhs->e3334 + rhs->e3334;
  res->e1144 = lhs->e1144 + rhs->e1144;
  res->e1244 = lhs->e1244 + rhs->e1244;
  res->e2244 = lhs->e2244 + rhs->e2244;
  res->e1344 = lhs->e1344 + rhs->e1344;
  res->e2344 = lhs->e2344 + rhs->e2344;
  res->e3344 = lhs->e3344 + rhs->e3344;
  res->e1444 = lhs->e1444 + rhs->e1444;
  res->e2444 = lhs->e2444 + rhs->e2444;
  res->e3444 = lhs->e3444 + rhs->e3444;
  res->e4444 = lhs->e4444 + rhs->e4444;

}

onumm4n4_t onumm4n4_add_ro(  coeff_t lhs,  onumm4n4_t* rhs){
  onumm4n4_t res;

  // Addition like function 'lhs + rhs'
  // Real;
  res.r = lhs + rhs->r;
  // Order 1;
  res.e1 =  + rhs->e1;
  res.e2 =  + rhs->e2;
  res.e3 =  + rhs->e3;
  res.e4 =  + rhs->e4;
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
  res.e1114 =  + rhs->e1114;
  res.e1124 =  + rhs->e1124;
  res.e1224 =  + rhs->e1224;
  res.e2224 =  + rhs->e2224;
  res.e1134 =  + rhs->e1134;
  res.e1234 =  + rhs->e1234;
  res.e2234 =  + rhs->e2234;
  res.e1334 =  + rhs->e1334;
  res.e2334 =  + rhs->e2334;
  res.e3334 =  + rhs->e3334;
  res.e1144 =  + rhs->e1144;
  res.e1244 =  + rhs->e1244;
  res.e2244 =  + rhs->e2244;
  res.e1344 =  + rhs->e1344;
  res.e2344 =  + rhs->e2344;
  res.e3344 =  + rhs->e3344;
  res.e1444 =  + rhs->e1444;
  res.e2444 =  + rhs->e2444;
  res.e3444 =  + rhs->e3444;
  res.e4444 =  + rhs->e4444;

  return res;

}

void onumm4n4_add_ro_to(  coeff_t lhs,  onumm4n4_t* rhs, onumm4n4_t* res){
  // Addition like function 'lhs + rhs'
  // Real;
  res->r = lhs + rhs->r;
  // Order 1;
  res->e1 =  + rhs->e1;
  res->e2 =  + rhs->e2;
  res->e3 =  + rhs->e3;
  res->e4 =  + rhs->e4;
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
  res->e1114 =  + rhs->e1114;
  res->e1124 =  + rhs->e1124;
  res->e1224 =  + rhs->e1224;
  res->e2224 =  + rhs->e2224;
  res->e1134 =  + rhs->e1134;
  res->e1234 =  + rhs->e1234;
  res->e2234 =  + rhs->e2234;
  res->e1334 =  + rhs->e1334;
  res->e2334 =  + rhs->e2334;
  res->e3334 =  + rhs->e3334;
  res->e1144 =  + rhs->e1144;
  res->e1244 =  + rhs->e1244;
  res->e2244 =  + rhs->e2244;
  res->e1344 =  + rhs->e1344;
  res->e2344 =  + rhs->e2344;
  res->e3344 =  + rhs->e3344;
  res->e1444 =  + rhs->e1444;
  res->e2444 =  + rhs->e2444;
  res->e3444 =  + rhs->e3444;
  res->e4444 =  + rhs->e4444;

}

onumm4n4_t onumm4n4_sub_oo(  onumm4n4_t lhs,  onumm4n4_t* rhs){
  onumm4n4_t res;

  // Addition like function 'lhs - rhs'
  //  Real
  res.r = lhs.r - rhs->r;
  // Order 1
  res.e1 = lhs.e1 - rhs->e1;
  res.e2 = lhs.e2 - rhs->e2;
  res.e3 = lhs.e3 - rhs->e3;
  res.e4 = lhs.e4 - rhs->e4;
  // Order 2
  res.e11 = lhs.e11 - rhs->e11;
  res.e12 = lhs.e12 - rhs->e12;
  res.e22 = lhs.e22 - rhs->e22;
  res.e13 = lhs.e13 - rhs->e13;
  res.e23 = lhs.e23 - rhs->e23;
  res.e33 = lhs.e33 - rhs->e33;
  res.e14 = lhs.e14 - rhs->e14;
  res.e24 = lhs.e24 - rhs->e24;
  res.e34 = lhs.e34 - rhs->e34;
  res.e44 = lhs.e44 - rhs->e44;
  // Order 3
  res.e111 = lhs.e111 - rhs->e111;
  res.e112 = lhs.e112 - rhs->e112;
  res.e122 = lhs.e122 - rhs->e122;
  res.e222 = lhs.e222 - rhs->e222;
  res.e113 = lhs.e113 - rhs->e113;
  res.e123 = lhs.e123 - rhs->e123;
  res.e223 = lhs.e223 - rhs->e223;
  res.e133 = lhs.e133 - rhs->e133;
  res.e233 = lhs.e233 - rhs->e233;
  res.e333 = lhs.e333 - rhs->e333;
  res.e114 = lhs.e114 - rhs->e114;
  res.e124 = lhs.e124 - rhs->e124;
  res.e224 = lhs.e224 - rhs->e224;
  res.e134 = lhs.e134 - rhs->e134;
  res.e234 = lhs.e234 - rhs->e234;
  res.e334 = lhs.e334 - rhs->e334;
  res.e144 = lhs.e144 - rhs->e144;
  res.e244 = lhs.e244 - rhs->e244;
  res.e344 = lhs.e344 - rhs->e344;
  res.e444 = lhs.e444 - rhs->e444;
  // Order 4
  res.e1111 = lhs.e1111 - rhs->e1111;
  res.e1112 = lhs.e1112 - rhs->e1112;
  res.e1122 = lhs.e1122 - rhs->e1122;
  res.e1222 = lhs.e1222 - rhs->e1222;
  res.e2222 = lhs.e2222 - rhs->e2222;
  res.e1113 = lhs.e1113 - rhs->e1113;
  res.e1123 = lhs.e1123 - rhs->e1123;
  res.e1223 = lhs.e1223 - rhs->e1223;
  res.e2223 = lhs.e2223 - rhs->e2223;
  res.e1133 = lhs.e1133 - rhs->e1133;
  res.e1233 = lhs.e1233 - rhs->e1233;
  res.e2233 = lhs.e2233 - rhs->e2233;
  res.e1333 = lhs.e1333 - rhs->e1333;
  res.e2333 = lhs.e2333 - rhs->e2333;
  res.e3333 = lhs.e3333 - rhs->e3333;
  res.e1114 = lhs.e1114 - rhs->e1114;
  res.e1124 = lhs.e1124 - rhs->e1124;
  res.e1224 = lhs.e1224 - rhs->e1224;
  res.e2224 = lhs.e2224 - rhs->e2224;
  res.e1134 = lhs.e1134 - rhs->e1134;
  res.e1234 = lhs.e1234 - rhs->e1234;
  res.e2234 = lhs.e2234 - rhs->e2234;
  res.e1334 = lhs.e1334 - rhs->e1334;
  res.e2334 = lhs.e2334 - rhs->e2334;
  res.e3334 = lhs.e3334 - rhs->e3334;
  res.e1144 = lhs.e1144 - rhs->e1144;
  res.e1244 = lhs.e1244 - rhs->e1244;
  res.e2244 = lhs.e2244 - rhs->e2244;
  res.e1344 = lhs.e1344 - rhs->e1344;
  res.e2344 = lhs.e2344 - rhs->e2344;
  res.e3344 = lhs.e3344 - rhs->e3344;
  res.e1444 = lhs.e1444 - rhs->e1444;
  res.e2444 = lhs.e2444 - rhs->e2444;
  res.e3444 = lhs.e3444 - rhs->e3444;
  res.e4444 = lhs.e4444 - rhs->e4444;

  return res;

}

void onumm4n4_sub_oo_to(  onumm4n4_t lhs,  onumm4n4_t* rhs, onumm4n4_t* res){
  // Addition like function 'lhs - rhs'
  //  Real
  res->r = lhs.r - rhs->r;
  // Order 1
  res->e1 = lhs.e1 - rhs->e1;
  res->e2 = lhs.e2 - rhs->e2;
  res->e3 = lhs.e3 - rhs->e3;
  res->e4 = lhs.e4 - rhs->e4;
  // Order 2
  res->e11 = lhs.e11 - rhs->e11;
  res->e12 = lhs.e12 - rhs->e12;
  res->e22 = lhs.e22 - rhs->e22;
  res->e13 = lhs.e13 - rhs->e13;
  res->e23 = lhs.e23 - rhs->e23;
  res->e33 = lhs.e33 - rhs->e33;
  res->e14 = lhs.e14 - rhs->e14;
  res->e24 = lhs.e24 - rhs->e24;
  res->e34 = lhs.e34 - rhs->e34;
  res->e44 = lhs.e44 - rhs->e44;
  // Order 3
  res->e111 = lhs.e111 - rhs->e111;
  res->e112 = lhs.e112 - rhs->e112;
  res->e122 = lhs.e122 - rhs->e122;
  res->e222 = lhs.e222 - rhs->e222;
  res->e113 = lhs.e113 - rhs->e113;
  res->e123 = lhs.e123 - rhs->e123;
  res->e223 = lhs.e223 - rhs->e223;
  res->e133 = lhs.e133 - rhs->e133;
  res->e233 = lhs.e233 - rhs->e233;
  res->e333 = lhs.e333 - rhs->e333;
  res->e114 = lhs.e114 - rhs->e114;
  res->e124 = lhs.e124 - rhs->e124;
  res->e224 = lhs.e224 - rhs->e224;
  res->e134 = lhs.e134 - rhs->e134;
  res->e234 = lhs.e234 - rhs->e234;
  res->e334 = lhs.e334 - rhs->e334;
  res->e144 = lhs.e144 - rhs->e144;
  res->e244 = lhs.e244 - rhs->e244;
  res->e344 = lhs.e344 - rhs->e344;
  res->e444 = lhs.e444 - rhs->e444;
  // Order 4
  res->e1111 = lhs.e1111 - rhs->e1111;
  res->e1112 = lhs.e1112 - rhs->e1112;
  res->e1122 = lhs.e1122 - rhs->e1122;
  res->e1222 = lhs.e1222 - rhs->e1222;
  res->e2222 = lhs.e2222 - rhs->e2222;
  res->e1113 = lhs.e1113 - rhs->e1113;
  res->e1123 = lhs.e1123 - rhs->e1123;
  res->e1223 = lhs.e1223 - rhs->e1223;
  res->e2223 = lhs.e2223 - rhs->e2223;
  res->e1133 = lhs.e1133 - rhs->e1133;
  res->e1233 = lhs.e1233 - rhs->e1233;
  res->e2233 = lhs.e2233 - rhs->e2233;
  res->e1333 = lhs.e1333 - rhs->e1333;
  res->e2333 = lhs.e2333 - rhs->e2333;
  res->e3333 = lhs.e3333 - rhs->e3333;
  res->e1114 = lhs.e1114 - rhs->e1114;
  res->e1124 = lhs.e1124 - rhs->e1124;
  res->e1224 = lhs.e1224 - rhs->e1224;
  res->e2224 = lhs.e2224 - rhs->e2224;
  res->e1134 = lhs.e1134 - rhs->e1134;
  res->e1234 = lhs.e1234 - rhs->e1234;
  res->e2234 = lhs.e2234 - rhs->e2234;
  res->e1334 = lhs.e1334 - rhs->e1334;
  res->e2334 = lhs.e2334 - rhs->e2334;
  res->e3334 = lhs.e3334 - rhs->e3334;
  res->e1144 = lhs.e1144 - rhs->e1144;
  res->e1244 = lhs.e1244 - rhs->e1244;
  res->e2244 = lhs.e2244 - rhs->e2244;
  res->e1344 = lhs.e1344 - rhs->e1344;
  res->e2344 = lhs.e2344 - rhs->e2344;
  res->e3344 = lhs.e3344 - rhs->e3344;
  res->e1444 = lhs.e1444 - rhs->e1444;
  res->e2444 = lhs.e2444 - rhs->e2444;
  res->e3444 = lhs.e3444 - rhs->e3444;
  res->e4444 = lhs.e4444 - rhs->e4444;

}

onumm4n4_t onumm4n4_sub_ro(  coeff_t lhs,  onumm4n4_t* rhs){
  onumm4n4_t res;

  // Addition like function 'lhs - rhs'
  // Real;
  res.r = lhs - rhs->r;
  // Order 1;
  res.e1 =  - rhs->e1;
  res.e2 =  - rhs->e2;
  res.e3 =  - rhs->e3;
  res.e4 =  - rhs->e4;
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
  res.e1114 =  - rhs->e1114;
  res.e1124 =  - rhs->e1124;
  res.e1224 =  - rhs->e1224;
  res.e2224 =  - rhs->e2224;
  res.e1134 =  - rhs->e1134;
  res.e1234 =  - rhs->e1234;
  res.e2234 =  - rhs->e2234;
  res.e1334 =  - rhs->e1334;
  res.e2334 =  - rhs->e2334;
  res.e3334 =  - rhs->e3334;
  res.e1144 =  - rhs->e1144;
  res.e1244 =  - rhs->e1244;
  res.e2244 =  - rhs->e2244;
  res.e1344 =  - rhs->e1344;
  res.e2344 =  - rhs->e2344;
  res.e3344 =  - rhs->e3344;
  res.e1444 =  - rhs->e1444;
  res.e2444 =  - rhs->e2444;
  res.e3444 =  - rhs->e3444;
  res.e4444 =  - rhs->e4444;

  return res;

}

void onumm4n4_sub_ro_to(  coeff_t lhs,  onumm4n4_t* rhs, onumm4n4_t* res){
  // Addition like function 'lhs - rhs'
  // Real;
  res->r = lhs - rhs->r;
  // Order 1;
  res->e1 =  - rhs->e1;
  res->e2 =  - rhs->e2;
  res->e3 =  - rhs->e3;
  res->e4 =  - rhs->e4;
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
  res->e1114 =  - rhs->e1114;
  res->e1124 =  - rhs->e1124;
  res->e1224 =  - rhs->e1224;
  res->e2224 =  - rhs->e2224;
  res->e1134 =  - rhs->e1134;
  res->e1234 =  - rhs->e1234;
  res->e2234 =  - rhs->e2234;
  res->e1334 =  - rhs->e1334;
  res->e2334 =  - rhs->e2334;
  res->e3334 =  - rhs->e3334;
  res->e1144 =  - rhs->e1144;
  res->e1244 =  - rhs->e1244;
  res->e2244 =  - rhs->e2244;
  res->e1344 =  - rhs->e1344;
  res->e2344 =  - rhs->e2344;
  res->e3344 =  - rhs->e3344;
  res->e1444 =  - rhs->e1444;
  res->e2444 =  - rhs->e2444;
  res->e3444 =  - rhs->e3444;
  res->e4444 =  - rhs->e4444;

}

onumm4n4_t onumm4n4_sub_or(  onumm4n4_t* lhs,  coeff_t rhs){
  onumm4n4_t res;

  // Addition like function 'lhs - rhs'
  // Real;
  res.r = lhs->r - rhs;
  // Order 1;
  res.e1 = lhs->e1;
  res.e2 = lhs->e2;
  res.e3 = lhs->e3;
  res.e4 = lhs->e4;
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
  res.e1114 = lhs->e1114;
  res.e1124 = lhs->e1124;
  res.e1224 = lhs->e1224;
  res.e2224 = lhs->e2224;
  res.e1134 = lhs->e1134;
  res.e1234 = lhs->e1234;
  res.e2234 = lhs->e2234;
  res.e1334 = lhs->e1334;
  res.e2334 = lhs->e2334;
  res.e3334 = lhs->e3334;
  res.e1144 = lhs->e1144;
  res.e1244 = lhs->e1244;
  res.e2244 = lhs->e2244;
  res.e1344 = lhs->e1344;
  res.e2344 = lhs->e2344;
  res.e3344 = lhs->e3344;
  res.e1444 = lhs->e1444;
  res.e2444 = lhs->e2444;
  res.e3444 = lhs->e3444;
  res.e4444 = lhs->e4444;

  return res;

}

void onumm4n4_sub_or_to(  onumm4n4_t* lhs,  coeff_t rhs, onumm4n4_t* res){
  // Addition like function 'lhs - rhs'
  // Real;
  res->r = lhs->r - rhs;
  // Order 1;
  res->e1 = lhs->e1;
  res->e2 = lhs->e2;
  res->e3 = lhs->e3;
  res->e4 = lhs->e4;
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
  res->e1114 = lhs->e1114;
  res->e1124 = lhs->e1124;
  res->e1224 = lhs->e1224;
  res->e2224 = lhs->e2224;
  res->e1134 = lhs->e1134;
  res->e1234 = lhs->e1234;
  res->e2234 = lhs->e2234;
  res->e1334 = lhs->e1334;
  res->e2334 = lhs->e2334;
  res->e3334 = lhs->e3334;
  res->e1144 = lhs->e1144;
  res->e1244 = lhs->e1244;
  res->e2244 = lhs->e2244;
  res->e1344 = lhs->e1344;
  res->e2344 = lhs->e2344;
  res->e3344 = lhs->e3344;
  res->e1444 = lhs->e1444;
  res->e2444 = lhs->e2444;
  res->e3444 = lhs->e3444;
  res->e4444 = lhs->e4444;

}

onumm4n4_t onumm4n4_mul_oo(  onumm4n4_t* lhs,  onumm4n4_t* rhs){
  onumm4n4_t res;

  //  Multiplication like function 'lhs * rhs'
  // Real;
  res.r = lhs->r * rhs->r;
  // Order 1;
  res.e1 = lhs->r * rhs->e1 + lhs->e1 * rhs->r;
  res.e2 = lhs->r * rhs->e2 + lhs->e2 * rhs->r;
  res.e3 = lhs->r * rhs->e3 + lhs->e3 * rhs->r;
  res.e4 = lhs->r * rhs->e4 + lhs->e4 * rhs->r;
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
  res.e1114 = lhs->r * rhs->e1114 + lhs->e1114 * rhs->r + lhs->e1 * rhs->e114 
            + lhs->e114 * rhs->e1 + lhs->e4 * rhs->e111 + lhs->e111 * rhs->e4 
            + lhs->e11 * rhs->e14 + lhs->e14 * rhs->e11;
  res.e1124 = lhs->r * rhs->e1124 + lhs->e1124 * rhs->r + lhs->e1 * rhs->e124 
            + lhs->e124 * rhs->e1 + lhs->e2 * rhs->e114 + lhs->e114 * rhs->e2 
            + lhs->e4 * rhs->e112 + lhs->e112 * rhs->e4 + lhs->e11 * rhs->e24 
            + lhs->e12 * rhs->e14 + lhs->e14 * rhs->e12 + lhs->e24 * rhs->e11;
  res.e1224 = lhs->r * rhs->e1224 + lhs->e1224 * rhs->r + lhs->e1 * rhs->e224 
            + lhs->e224 * rhs->e1 + lhs->e2 * rhs->e124 + lhs->e124 * rhs->e2 
            + lhs->e4 * rhs->e122 + lhs->e122 * rhs->e4 + lhs->e12 * rhs->e24 
            + lhs->e22 * rhs->e14 + lhs->e14 * rhs->e22 + lhs->e24 * rhs->e12;
  res.e2224 = lhs->r * rhs->e2224 + lhs->e2224 * rhs->r + lhs->e2 * rhs->e224 
            + lhs->e224 * rhs->e2 + lhs->e4 * rhs->e222 + lhs->e222 * rhs->e4 
            + lhs->e22 * rhs->e24 + lhs->e24 * rhs->e22;
  res.e1134 = lhs->r * rhs->e1134 + lhs->e1134 * rhs->r + lhs->e1 * rhs->e134 
            + lhs->e134 * rhs->e1 + lhs->e3 * rhs->e114 + lhs->e114 * rhs->e3 
            + lhs->e4 * rhs->e113 + lhs->e113 * rhs->e4 + lhs->e11 * rhs->e34 
            + lhs->e13 * rhs->e14 + lhs->e14 * rhs->e13 + lhs->e34 * rhs->e11;
  res.e1234 = lhs->r * rhs->e1234 + lhs->e1234 * rhs->r + lhs->e1 * rhs->e234 
            + lhs->e234 * rhs->e1 + lhs->e2 * rhs->e134 + lhs->e134 * rhs->e2 
            + lhs->e3 * rhs->e124 + lhs->e124 * rhs->e3 + lhs->e4 * rhs->e123 
            + lhs->e123 * rhs->e4 + lhs->e12 * rhs->e34 + lhs->e13 * rhs->e24 
            + lhs->e23 * rhs->e14 + lhs->e14 * rhs->e23 + lhs->e24 * rhs->e13 
            + lhs->e34 * rhs->e12;
  res.e2234 = lhs->r * rhs->e2234 + lhs->e2234 * rhs->r + lhs->e2 * rhs->e234 
            + lhs->e234 * rhs->e2 + lhs->e3 * rhs->e224 + lhs->e224 * rhs->e3 
            + lhs->e4 * rhs->e223 + lhs->e223 * rhs->e4 + lhs->e22 * rhs->e34 
            + lhs->e23 * rhs->e24 + lhs->e24 * rhs->e23 + lhs->e34 * rhs->e22;
  res.e1334 = lhs->r * rhs->e1334 + lhs->e1334 * rhs->r + lhs->e1 * rhs->e334 
            + lhs->e334 * rhs->e1 + lhs->e3 * rhs->e134 + lhs->e134 * rhs->e3 
            + lhs->e4 * rhs->e133 + lhs->e133 * rhs->e4 + lhs->e13 * rhs->e34 
            + lhs->e33 * rhs->e14 + lhs->e14 * rhs->e33 + lhs->e34 * rhs->e13;
  res.e2334 = lhs->r * rhs->e2334 + lhs->e2334 * rhs->r + lhs->e2 * rhs->e334 
            + lhs->e334 * rhs->e2 + lhs->e3 * rhs->e234 + lhs->e234 * rhs->e3 
            + lhs->e4 * rhs->e233 + lhs->e233 * rhs->e4 + lhs->e23 * rhs->e34 
            + lhs->e33 * rhs->e24 + lhs->e24 * rhs->e33 + lhs->e34 * rhs->e23;
  res.e3334 = lhs->r * rhs->e3334 + lhs->e3334 * rhs->r + lhs->e3 * rhs->e334 
            + lhs->e334 * rhs->e3 + lhs->e4 * rhs->e333 + lhs->e333 * rhs->e4 
            + lhs->e33 * rhs->e34 + lhs->e34 * rhs->e33;
  res.e1144 = lhs->r * rhs->e1144 + lhs->e1144 * rhs->r + lhs->e1 * rhs->e144 
            + lhs->e144 * rhs->e1 + lhs->e4 * rhs->e114 + lhs->e114 * rhs->e4 
            + lhs->e11 * rhs->e44 + lhs->e14 * rhs->e14 + lhs->e44 * rhs->e11;
  res.e1244 = lhs->r * rhs->e1244 + lhs->e1244 * rhs->r + lhs->e1 * rhs->e244 
            + lhs->e244 * rhs->e1 + lhs->e2 * rhs->e144 + lhs->e144 * rhs->e2 
            + lhs->e4 * rhs->e124 + lhs->e124 * rhs->e4 + lhs->e12 * rhs->e44 
            + lhs->e14 * rhs->e24 + lhs->e24 * rhs->e14 + lhs->e44 * rhs->e12;
  res.e2244 = lhs->r * rhs->e2244 + lhs->e2244 * rhs->r + lhs->e2 * rhs->e244 
            + lhs->e244 * rhs->e2 + lhs->e4 * rhs->e224 + lhs->e224 * rhs->e4 
            + lhs->e22 * rhs->e44 + lhs->e24 * rhs->e24 + lhs->e44 * rhs->e22;
  res.e1344 = lhs->r * rhs->e1344 + lhs->e1344 * rhs->r + lhs->e1 * rhs->e344 
            + lhs->e344 * rhs->e1 + lhs->e3 * rhs->e144 + lhs->e144 * rhs->e3 
            + lhs->e4 * rhs->e134 + lhs->e134 * rhs->e4 + lhs->e13 * rhs->e44 
            + lhs->e14 * rhs->e34 + lhs->e34 * rhs->e14 + lhs->e44 * rhs->e13;
  res.e2344 = lhs->r * rhs->e2344 + lhs->e2344 * rhs->r + lhs->e2 * rhs->e344 
            + lhs->e344 * rhs->e2 + lhs->e3 * rhs->e244 + lhs->e244 * rhs->e3 
            + lhs->e4 * rhs->e234 + lhs->e234 * rhs->e4 + lhs->e23 * rhs->e44 
            + lhs->e24 * rhs->e34 + lhs->e34 * rhs->e24 + lhs->e44 * rhs->e23;
  res.e3344 = lhs->r * rhs->e3344 + lhs->e3344 * rhs->r + lhs->e3 * rhs->e344 
            + lhs->e344 * rhs->e3 + lhs->e4 * rhs->e334 + lhs->e334 * rhs->e4 
            + lhs->e33 * rhs->e44 + lhs->e34 * rhs->e34 + lhs->e44 * rhs->e33;
  res.e1444 = lhs->r * rhs->e1444 + lhs->e1444 * rhs->r + lhs->e1 * rhs->e444 
            + lhs->e444 * rhs->e1 + lhs->e4 * rhs->e144 + lhs->e144 * rhs->e4 
            + lhs->e14 * rhs->e44 + lhs->e44 * rhs->e14;
  res.e2444 = lhs->r * rhs->e2444 + lhs->e2444 * rhs->r + lhs->e2 * rhs->e444 
            + lhs->e444 * rhs->e2 + lhs->e4 * rhs->e244 + lhs->e244 * rhs->e4 
            + lhs->e24 * rhs->e44 + lhs->e44 * rhs->e24;
  res.e3444 = lhs->r * rhs->e3444 + lhs->e3444 * rhs->r + lhs->e3 * rhs->e444 
            + lhs->e444 * rhs->e3 + lhs->e4 * rhs->e344 + lhs->e344 * rhs->e4 
            + lhs->e34 * rhs->e44 + lhs->e44 * rhs->e34;
  res.e4444 = lhs->r * rhs->e4444 + lhs->e4444 * rhs->r + lhs->e4 * rhs->e444 
            + lhs->e444 * rhs->e4 + lhs->e44 * rhs->e44;

  return res;

}

void onumm4n4_mul_oo_to(  onumm4n4_t* lhs,  onumm4n4_t* rhs, onumm4n4_t* res){
  //  Multiplication like function 'lhs * rhs'
  // Real;
  res->r = lhs->r * rhs->r;
  // Order 1;
  res->e1 = lhs->r * rhs->e1 + lhs->e1 * rhs->r;
  res->e2 = lhs->r * rhs->e2 + lhs->e2 * rhs->r;
  res->e3 = lhs->r * rhs->e3 + lhs->e3 * rhs->r;
  res->e4 = lhs->r * rhs->e4 + lhs->e4 * rhs->r;
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
  res->e1114 = lhs->r * rhs->e1114 + lhs->e1114 * rhs->r + lhs->e1 * rhs->e114 
            + lhs->e114 * rhs->e1 + lhs->e4 * rhs->e111 + lhs->e111 * rhs->e4 
            + lhs->e11 * rhs->e14 + lhs->e14 * rhs->e11;
  res->e1124 = lhs->r * rhs->e1124 + lhs->e1124 * rhs->r + lhs->e1 * rhs->e124 
            + lhs->e124 * rhs->e1 + lhs->e2 * rhs->e114 + lhs->e114 * rhs->e2 
            + lhs->e4 * rhs->e112 + lhs->e112 * rhs->e4 + lhs->e11 * rhs->e24 
            + lhs->e12 * rhs->e14 + lhs->e14 * rhs->e12 + lhs->e24 * rhs->e11;
  res->e1224 = lhs->r * rhs->e1224 + lhs->e1224 * rhs->r + lhs->e1 * rhs->e224 
            + lhs->e224 * rhs->e1 + lhs->e2 * rhs->e124 + lhs->e124 * rhs->e2 
            + lhs->e4 * rhs->e122 + lhs->e122 * rhs->e4 + lhs->e12 * rhs->e24 
            + lhs->e22 * rhs->e14 + lhs->e14 * rhs->e22 + lhs->e24 * rhs->e12;
  res->e2224 = lhs->r * rhs->e2224 + lhs->e2224 * rhs->r + lhs->e2 * rhs->e224 
            + lhs->e224 * rhs->e2 + lhs->e4 * rhs->e222 + lhs->e222 * rhs->e4 
            + lhs->e22 * rhs->e24 + lhs->e24 * rhs->e22;
  res->e1134 = lhs->r * rhs->e1134 + lhs->e1134 * rhs->r + lhs->e1 * rhs->e134 
            + lhs->e134 * rhs->e1 + lhs->e3 * rhs->e114 + lhs->e114 * rhs->e3 
            + lhs->e4 * rhs->e113 + lhs->e113 * rhs->e4 + lhs->e11 * rhs->e34 
            + lhs->e13 * rhs->e14 + lhs->e14 * rhs->e13 + lhs->e34 * rhs->e11;
  res->e1234 = lhs->r * rhs->e1234 + lhs->e1234 * rhs->r + lhs->e1 * rhs->e234 
            + lhs->e234 * rhs->e1 + lhs->e2 * rhs->e134 + lhs->e134 * rhs->e2 
            + lhs->e3 * rhs->e124 + lhs->e124 * rhs->e3 + lhs->e4 * rhs->e123 
            + lhs->e123 * rhs->e4 + lhs->e12 * rhs->e34 + lhs->e13 * rhs->e24 
            + lhs->e23 * rhs->e14 + lhs->e14 * rhs->e23 + lhs->e24 * rhs->e13 
            + lhs->e34 * rhs->e12;
  res->e2234 = lhs->r * rhs->e2234 + lhs->e2234 * rhs->r + lhs->e2 * rhs->e234 
            + lhs->e234 * rhs->e2 + lhs->e3 * rhs->e224 + lhs->e224 * rhs->e3 
            + lhs->e4 * rhs->e223 + lhs->e223 * rhs->e4 + lhs->e22 * rhs->e34 
            + lhs->e23 * rhs->e24 + lhs->e24 * rhs->e23 + lhs->e34 * rhs->e22;
  res->e1334 = lhs->r * rhs->e1334 + lhs->e1334 * rhs->r + lhs->e1 * rhs->e334 
            + lhs->e334 * rhs->e1 + lhs->e3 * rhs->e134 + lhs->e134 * rhs->e3 
            + lhs->e4 * rhs->e133 + lhs->e133 * rhs->e4 + lhs->e13 * rhs->e34 
            + lhs->e33 * rhs->e14 + lhs->e14 * rhs->e33 + lhs->e34 * rhs->e13;
  res->e2334 = lhs->r * rhs->e2334 + lhs->e2334 * rhs->r + lhs->e2 * rhs->e334 
            + lhs->e334 * rhs->e2 + lhs->e3 * rhs->e234 + lhs->e234 * rhs->e3 
            + lhs->e4 * rhs->e233 + lhs->e233 * rhs->e4 + lhs->e23 * rhs->e34 
            + lhs->e33 * rhs->e24 + lhs->e24 * rhs->e33 + lhs->e34 * rhs->e23;
  res->e3334 = lhs->r * rhs->e3334 + lhs->e3334 * rhs->r + lhs->e3 * rhs->e334 
            + lhs->e334 * rhs->e3 + lhs->e4 * rhs->e333 + lhs->e333 * rhs->e4 
            + lhs->e33 * rhs->e34 + lhs->e34 * rhs->e33;
  res->e1144 = lhs->r * rhs->e1144 + lhs->e1144 * rhs->r + lhs->e1 * rhs->e144 
            + lhs->e144 * rhs->e1 + lhs->e4 * rhs->e114 + lhs->e114 * rhs->e4 
            + lhs->e11 * rhs->e44 + lhs->e14 * rhs->e14 + lhs->e44 * rhs->e11;
  res->e1244 = lhs->r * rhs->e1244 + lhs->e1244 * rhs->r + lhs->e1 * rhs->e244 
            + lhs->e244 * rhs->e1 + lhs->e2 * rhs->e144 + lhs->e144 * rhs->e2 
            + lhs->e4 * rhs->e124 + lhs->e124 * rhs->e4 + lhs->e12 * rhs->e44 
            + lhs->e14 * rhs->e24 + lhs->e24 * rhs->e14 + lhs->e44 * rhs->e12;
  res->e2244 = lhs->r * rhs->e2244 + lhs->e2244 * rhs->r + lhs->e2 * rhs->e244 
            + lhs->e244 * rhs->e2 + lhs->e4 * rhs->e224 + lhs->e224 * rhs->e4 
            + lhs->e22 * rhs->e44 + lhs->e24 * rhs->e24 + lhs->e44 * rhs->e22;
  res->e1344 = lhs->r * rhs->e1344 + lhs->e1344 * rhs->r + lhs->e1 * rhs->e344 
            + lhs->e344 * rhs->e1 + lhs->e3 * rhs->e144 + lhs->e144 * rhs->e3 
            + lhs->e4 * rhs->e134 + lhs->e134 * rhs->e4 + lhs->e13 * rhs->e44 
            + lhs->e14 * rhs->e34 + lhs->e34 * rhs->e14 + lhs->e44 * rhs->e13;
  res->e2344 = lhs->r * rhs->e2344 + lhs->e2344 * rhs->r + lhs->e2 * rhs->e344 
            + lhs->e344 * rhs->e2 + lhs->e3 * rhs->e244 + lhs->e244 * rhs->e3 
            + lhs->e4 * rhs->e234 + lhs->e234 * rhs->e4 + lhs->e23 * rhs->e44 
            + lhs->e24 * rhs->e34 + lhs->e34 * rhs->e24 + lhs->e44 * rhs->e23;
  res->e3344 = lhs->r * rhs->e3344 + lhs->e3344 * rhs->r + lhs->e3 * rhs->e344 
            + lhs->e344 * rhs->e3 + lhs->e4 * rhs->e334 + lhs->e334 * rhs->e4 
            + lhs->e33 * rhs->e44 + lhs->e34 * rhs->e34 + lhs->e44 * rhs->e33;
  res->e1444 = lhs->r * rhs->e1444 + lhs->e1444 * rhs->r + lhs->e1 * rhs->e444 
            + lhs->e444 * rhs->e1 + lhs->e4 * rhs->e144 + lhs->e144 * rhs->e4 
            + lhs->e14 * rhs->e44 + lhs->e44 * rhs->e14;
  res->e2444 = lhs->r * rhs->e2444 + lhs->e2444 * rhs->r + lhs->e2 * rhs->e444 
            + lhs->e444 * rhs->e2 + lhs->e4 * rhs->e244 + lhs->e244 * rhs->e4 
            + lhs->e24 * rhs->e44 + lhs->e44 * rhs->e24;
  res->e3444 = lhs->r * rhs->e3444 + lhs->e3444 * rhs->r + lhs->e3 * rhs->e444 
            + lhs->e444 * rhs->e3 + lhs->e4 * rhs->e344 + lhs->e344 * rhs->e4 
            + lhs->e34 * rhs->e44 + lhs->e44 * rhs->e34;
  res->e4444 = lhs->r * rhs->e4444 + lhs->e4444 * rhs->r + lhs->e4 * rhs->e444 
            + lhs->e444 * rhs->e4 + lhs->e44 * rhs->e44;

}

onumm4n4_t onumm4n4_mul_ro(  coeff_t lhs,  onumm4n4_t* rhs){
  onumm4n4_t res;

  // Multiplication like function 'lhs * rhs'
  //  Real;
  res.r = lhs * rhs->r;
  // Order 1;
  res.e1 = lhs * rhs->e1;
  res.e2 = lhs * rhs->e2;
  res.e3 = lhs * rhs->e3;
  res.e4 = lhs * rhs->e4;
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
  res.e1114 = lhs * rhs->e1114;
  res.e1124 = lhs * rhs->e1124;
  res.e1224 = lhs * rhs->e1224;
  res.e2224 = lhs * rhs->e2224;
  res.e1134 = lhs * rhs->e1134;
  res.e1234 = lhs * rhs->e1234;
  res.e2234 = lhs * rhs->e2234;
  res.e1334 = lhs * rhs->e1334;
  res.e2334 = lhs * rhs->e2334;
  res.e3334 = lhs * rhs->e3334;
  res.e1144 = lhs * rhs->e1144;
  res.e1244 = lhs * rhs->e1244;
  res.e2244 = lhs * rhs->e2244;
  res.e1344 = lhs * rhs->e1344;
  res.e2344 = lhs * rhs->e2344;
  res.e3344 = lhs * rhs->e3344;
  res.e1444 = lhs * rhs->e1444;
  res.e2444 = lhs * rhs->e2444;
  res.e3444 = lhs * rhs->e3444;
  res.e4444 = lhs * rhs->e4444;

  return res;

}

void onumm4n4_mul_ro_to(  coeff_t lhs,  onumm4n4_t* rhs, onumm4n4_t* res){
  // Multiplication like function 'lhs * rhs'
  //  Real;
  res->r = lhs * rhs->r;
  // Order 1;
  res->e1 = lhs * rhs->e1;
  res->e2 = lhs * rhs->e2;
  res->e3 = lhs * rhs->e3;
  res->e4 = lhs * rhs->e4;
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
  res->e1114 = lhs * rhs->e1114;
  res->e1124 = lhs * rhs->e1124;
  res->e1224 = lhs * rhs->e1224;
  res->e2224 = lhs * rhs->e2224;
  res->e1134 = lhs * rhs->e1134;
  res->e1234 = lhs * rhs->e1234;
  res->e2234 = lhs * rhs->e2234;
  res->e1334 = lhs * rhs->e1334;
  res->e2334 = lhs * rhs->e2334;
  res->e3334 = lhs * rhs->e3334;
  res->e1144 = lhs * rhs->e1144;
  res->e1244 = lhs * rhs->e1244;
  res->e2244 = lhs * rhs->e2244;
  res->e1344 = lhs * rhs->e1344;
  res->e2344 = lhs * rhs->e2344;
  res->e3344 = lhs * rhs->e3344;
  res->e1444 = lhs * rhs->e1444;
  res->e2444 = lhs * rhs->e2444;
  res->e3444 = lhs * rhs->e3444;
  res->e4444 = lhs * rhs->e4444;

}

onumm4n4_t onumm4n4_trunc_mul_oo(  onumm4n4_t* lhs,  onumm4n4_t* rhs){
  onumm4n4_t res;

  res = onumm4n4_init();

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
  res.e1114 =  + lhs->e1 * rhs->e114 + lhs->e114 * rhs->e1 + lhs->e4 * rhs->e111 
            + lhs->e111 * rhs->e4 + lhs->e11 * rhs->e14 + lhs->e14 * rhs->e11;
  res.e1124 =  + lhs->e1 * rhs->e124 + lhs->e124 * rhs->e1 + lhs->e2 * rhs->e114 
            + lhs->e114 * rhs->e2 + lhs->e4 * rhs->e112 + lhs->e112 * rhs->e4 
            + lhs->e11 * rhs->e24 + lhs->e12 * rhs->e14 + lhs->e14 * rhs->e12 
            + lhs->e24 * rhs->e11;
  res.e1224 =  + lhs->e1 * rhs->e224 + lhs->e224 * rhs->e1 + lhs->e2 * rhs->e124 
            + lhs->e124 * rhs->e2 + lhs->e4 * rhs->e122 + lhs->e122 * rhs->e4 
            + lhs->e12 * rhs->e24 + lhs->e22 * rhs->e14 + lhs->e14 * rhs->e22 
            + lhs->e24 * rhs->e12;
  res.e2224 =  + lhs->e2 * rhs->e224 + lhs->e224 * rhs->e2 + lhs->e4 * rhs->e222 
            + lhs->e222 * rhs->e4 + lhs->e22 * rhs->e24 + lhs->e24 * rhs->e22;
  res.e1134 =  + lhs->e1 * rhs->e134 + lhs->e134 * rhs->e1 + lhs->e3 * rhs->e114 
            + lhs->e114 * rhs->e3 + lhs->e4 * rhs->e113 + lhs->e113 * rhs->e4 
            + lhs->e11 * rhs->e34 + lhs->e13 * rhs->e14 + lhs->e14 * rhs->e13 
            + lhs->e34 * rhs->e11;
  res.e1234 =  + lhs->e1 * rhs->e234 + lhs->e234 * rhs->e1 + lhs->e2 * rhs->e134 
            + lhs->e134 * rhs->e2 + lhs->e3 * rhs->e124 + lhs->e124 * rhs->e3 
            + lhs->e4 * rhs->e123 + lhs->e123 * rhs->e4 + lhs->e12 * rhs->e34 
            + lhs->e13 * rhs->e24 + lhs->e23 * rhs->e14 + lhs->e14 * rhs->e23 
            + lhs->e24 * rhs->e13 + lhs->e34 * rhs->e12;
  res.e2234 =  + lhs->e2 * rhs->e234 + lhs->e234 * rhs->e2 + lhs->e3 * rhs->e224 
            + lhs->e224 * rhs->e3 + lhs->e4 * rhs->e223 + lhs->e223 * rhs->e4 
            + lhs->e22 * rhs->e34 + lhs->e23 * rhs->e24 + lhs->e24 * rhs->e23 
            + lhs->e34 * rhs->e22;
  res.e1334 =  + lhs->e1 * rhs->e334 + lhs->e334 * rhs->e1 + lhs->e3 * rhs->e134 
            + lhs->e134 * rhs->e3 + lhs->e4 * rhs->e133 + lhs->e133 * rhs->e4 
            + lhs->e13 * rhs->e34 + lhs->e33 * rhs->e14 + lhs->e14 * rhs->e33 
            + lhs->e34 * rhs->e13;
  res.e2334 =  + lhs->e2 * rhs->e334 + lhs->e334 * rhs->e2 + lhs->e3 * rhs->e234 
            + lhs->e234 * rhs->e3 + lhs->e4 * rhs->e233 + lhs->e233 * rhs->e4 
            + lhs->e23 * rhs->e34 + lhs->e33 * rhs->e24 + lhs->e24 * rhs->e33 
            + lhs->e34 * rhs->e23;
  res.e3334 =  + lhs->e3 * rhs->e334 + lhs->e334 * rhs->e3 + lhs->e4 * rhs->e333 
            + lhs->e333 * rhs->e4 + lhs->e33 * rhs->e34 + lhs->e34 * rhs->e33;
  res.e1144 =  + lhs->e1 * rhs->e144 + lhs->e144 * rhs->e1 + lhs->e4 * rhs->e114 
            + lhs->e114 * rhs->e4 + lhs->e11 * rhs->e44 + lhs->e14 * rhs->e14 
            + lhs->e44 * rhs->e11;
  res.e1244 =  + lhs->e1 * rhs->e244 + lhs->e244 * rhs->e1 + lhs->e2 * rhs->e144 
            + lhs->e144 * rhs->e2 + lhs->e4 * rhs->e124 + lhs->e124 * rhs->e4 
            + lhs->e12 * rhs->e44 + lhs->e14 * rhs->e24 + lhs->e24 * rhs->e14 
            + lhs->e44 * rhs->e12;
  res.e2244 =  + lhs->e2 * rhs->e244 + lhs->e244 * rhs->e2 + lhs->e4 * rhs->e224 
            + lhs->e224 * rhs->e4 + lhs->e22 * rhs->e44 + lhs->e24 * rhs->e24 
            + lhs->e44 * rhs->e22;
  res.e1344 =  + lhs->e1 * rhs->e344 + lhs->e344 * rhs->e1 + lhs->e3 * rhs->e144 
            + lhs->e144 * rhs->e3 + lhs->e4 * rhs->e134 + lhs->e134 * rhs->e4 
            + lhs->e13 * rhs->e44 + lhs->e14 * rhs->e34 + lhs->e34 * rhs->e14 
            + lhs->e44 * rhs->e13;
  res.e2344 =  + lhs->e2 * rhs->e344 + lhs->e344 * rhs->e2 + lhs->e3 * rhs->e244 
            + lhs->e244 * rhs->e3 + lhs->e4 * rhs->e234 + lhs->e234 * rhs->e4 
            + lhs->e23 * rhs->e44 + lhs->e24 * rhs->e34 + lhs->e34 * rhs->e24 
            + lhs->e44 * rhs->e23;
  res.e3344 =  + lhs->e3 * rhs->e344 + lhs->e344 * rhs->e3 + lhs->e4 * rhs->e334 
            + lhs->e334 * rhs->e4 + lhs->e33 * rhs->e44 + lhs->e34 * rhs->e34 
            + lhs->e44 * rhs->e33;
  res.e1444 =  + lhs->e1 * rhs->e444 + lhs->e444 * rhs->e1 + lhs->e4 * rhs->e144 
            + lhs->e144 * rhs->e4 + lhs->e14 * rhs->e44 + lhs->e44 * rhs->e14;
  res.e2444 =  + lhs->e2 * rhs->e444 + lhs->e444 * rhs->e2 + lhs->e4 * rhs->e244 
            + lhs->e244 * rhs->e4 + lhs->e24 * rhs->e44 + lhs->e44 * rhs->e24;
  res.e3444 =  + lhs->e3 * rhs->e444 + lhs->e444 * rhs->e3 + lhs->e4 * rhs->e344 
            + lhs->e344 * rhs->e4 + lhs->e34 * rhs->e44 + lhs->e44 * rhs->e34;
  res.e4444 =  + lhs->e4 * rhs->e444 + lhs->e444 * rhs->e4 + lhs->e44 * rhs->e44;

  return res;

}

void onumm4n4_trunc_mul_oo_to(  onumm4n4_t* lhs,  onumm4n4_t* rhs, onumm4n4_t* res){
   (*res) = onumm4n4_init();

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
  res->e1114 =  + lhs->e1 * rhs->e114 + lhs->e114 * rhs->e1 + lhs->e4 * rhs->e111 
            + lhs->e111 * rhs->e4 + lhs->e11 * rhs->e14 + lhs->e14 * rhs->e11;
  res->e1124 =  + lhs->e1 * rhs->e124 + lhs->e124 * rhs->e1 + lhs->e2 * rhs->e114 
            + lhs->e114 * rhs->e2 + lhs->e4 * rhs->e112 + lhs->e112 * rhs->e4 
            + lhs->e11 * rhs->e24 + lhs->e12 * rhs->e14 + lhs->e14 * rhs->e12 
            + lhs->e24 * rhs->e11;
  res->e1224 =  + lhs->e1 * rhs->e224 + lhs->e224 * rhs->e1 + lhs->e2 * rhs->e124 
            + lhs->e124 * rhs->e2 + lhs->e4 * rhs->e122 + lhs->e122 * rhs->e4 
            + lhs->e12 * rhs->e24 + lhs->e22 * rhs->e14 + lhs->e14 * rhs->e22 
            + lhs->e24 * rhs->e12;
  res->e2224 =  + lhs->e2 * rhs->e224 + lhs->e224 * rhs->e2 + lhs->e4 * rhs->e222 
            + lhs->e222 * rhs->e4 + lhs->e22 * rhs->e24 + lhs->e24 * rhs->e22;
  res->e1134 =  + lhs->e1 * rhs->e134 + lhs->e134 * rhs->e1 + lhs->e3 * rhs->e114 
            + lhs->e114 * rhs->e3 + lhs->e4 * rhs->e113 + lhs->e113 * rhs->e4 
            + lhs->e11 * rhs->e34 + lhs->e13 * rhs->e14 + lhs->e14 * rhs->e13 
            + lhs->e34 * rhs->e11;
  res->e1234 =  + lhs->e1 * rhs->e234 + lhs->e234 * rhs->e1 + lhs->e2 * rhs->e134 
            + lhs->e134 * rhs->e2 + lhs->e3 * rhs->e124 + lhs->e124 * rhs->e3 
            + lhs->e4 * rhs->e123 + lhs->e123 * rhs->e4 + lhs->e12 * rhs->e34 
            + lhs->e13 * rhs->e24 + lhs->e23 * rhs->e14 + lhs->e14 * rhs->e23 
            + lhs->e24 * rhs->e13 + lhs->e34 * rhs->e12;
  res->e2234 =  + lhs->e2 * rhs->e234 + lhs->e234 * rhs->e2 + lhs->e3 * rhs->e224 
            + lhs->e224 * rhs->e3 + lhs->e4 * rhs->e223 + lhs->e223 * rhs->e4 
            + lhs->e22 * rhs->e34 + lhs->e23 * rhs->e24 + lhs->e24 * rhs->e23 
            + lhs->e34 * rhs->e22;
  res->e1334 =  + lhs->e1 * rhs->e334 + lhs->e334 * rhs->e1 + lhs->e3 * rhs->e134 
            + lhs->e134 * rhs->e3 + lhs->e4 * rhs->e133 + lhs->e133 * rhs->e4 
            + lhs->e13 * rhs->e34 + lhs->e33 * rhs->e14 + lhs->e14 * rhs->e33 
            + lhs->e34 * rhs->e13;
  res->e2334 =  + lhs->e2 * rhs->e334 + lhs->e334 * rhs->e2 + lhs->e3 * rhs->e234 
            + lhs->e234 * rhs->e3 + lhs->e4 * rhs->e233 + lhs->e233 * rhs->e4 
            + lhs->e23 * rhs->e34 + lhs->e33 * rhs->e24 + lhs->e24 * rhs->e33 
            + lhs->e34 * rhs->e23;
  res->e3334 =  + lhs->e3 * rhs->e334 + lhs->e334 * rhs->e3 + lhs->e4 * rhs->e333 
            + lhs->e333 * rhs->e4 + lhs->e33 * rhs->e34 + lhs->e34 * rhs->e33;
  res->e1144 =  + lhs->e1 * rhs->e144 + lhs->e144 * rhs->e1 + lhs->e4 * rhs->e114 
            + lhs->e114 * rhs->e4 + lhs->e11 * rhs->e44 + lhs->e14 * rhs->e14 
            + lhs->e44 * rhs->e11;
  res->e1244 =  + lhs->e1 * rhs->e244 + lhs->e244 * rhs->e1 + lhs->e2 * rhs->e144 
            + lhs->e144 * rhs->e2 + lhs->e4 * rhs->e124 + lhs->e124 * rhs->e4 
            + lhs->e12 * rhs->e44 + lhs->e14 * rhs->e24 + lhs->e24 * rhs->e14 
            + lhs->e44 * rhs->e12;
  res->e2244 =  + lhs->e2 * rhs->e244 + lhs->e244 * rhs->e2 + lhs->e4 * rhs->e224 
            + lhs->e224 * rhs->e4 + lhs->e22 * rhs->e44 + lhs->e24 * rhs->e24 
            + lhs->e44 * rhs->e22;
  res->e1344 =  + lhs->e1 * rhs->e344 + lhs->e344 * rhs->e1 + lhs->e3 * rhs->e144 
            + lhs->e144 * rhs->e3 + lhs->e4 * rhs->e134 + lhs->e134 * rhs->e4 
            + lhs->e13 * rhs->e44 + lhs->e14 * rhs->e34 + lhs->e34 * rhs->e14 
            + lhs->e44 * rhs->e13;
  res->e2344 =  + lhs->e2 * rhs->e344 + lhs->e344 * rhs->e2 + lhs->e3 * rhs->e244 
            + lhs->e244 * rhs->e3 + lhs->e4 * rhs->e234 + lhs->e234 * rhs->e4 
            + lhs->e23 * rhs->e44 + lhs->e24 * rhs->e34 + lhs->e34 * rhs->e24 
            + lhs->e44 * rhs->e23;
  res->e3344 =  + lhs->e3 * rhs->e344 + lhs->e344 * rhs->e3 + lhs->e4 * rhs->e334 
            + lhs->e334 * rhs->e4 + lhs->e33 * rhs->e44 + lhs->e34 * rhs->e34 
            + lhs->e44 * rhs->e33;
  res->e1444 =  + lhs->e1 * rhs->e444 + lhs->e444 * rhs->e1 + lhs->e4 * rhs->e144 
            + lhs->e144 * rhs->e4 + lhs->e14 * rhs->e44 + lhs->e44 * rhs->e14;
  res->e2444 =  + lhs->e2 * rhs->e444 + lhs->e444 * rhs->e2 + lhs->e4 * rhs->e244 
            + lhs->e244 * rhs->e4 + lhs->e24 * rhs->e44 + lhs->e44 * rhs->e24;
  res->e3444 =  + lhs->e3 * rhs->e444 + lhs->e444 * rhs->e3 + lhs->e4 * rhs->e344 
            + lhs->e344 * rhs->e4 + lhs->e34 * rhs->e44 + lhs->e44 * rhs->e34;
  res->e4444 =  + lhs->e4 * rhs->e444 + lhs->e444 * rhs->e4 + lhs->e44 * rhs->e44;

}

onumm4n4_t onumm4n4_gem_oo(  onumm4n4_t* a,  onumm4n4_t* b,  onumm4n4_t* c){
  onumm4n4_t res;

  //  General multiplication like function 'a * b + c'
  // Real;
  res.r = c->r + a->r * b->r;
  // Order 1;
  res.e1 = c->e1 + a->r * b->e1 + a->e1 * b->r;
  res.e2 = c->e2 + a->r * b->e2 + a->e2 * b->r;
  res.e3 = c->e3 + a->r * b->e3 + a->e3 * b->r;
  res.e4 = c->e4 + a->r * b->e4 + a->e4 * b->r;
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
  res.e1114 = c->e1114 + a->r * b->e1114 + a->e1114 * b->r + a->e1 * b->e114 
            + a->e114 * b->e1 + a->e4 * b->e111 + a->e111 * b->e4 
            + a->e11 * b->e14 + a->e14 * b->e11;
  res.e1124 = c->e1124 + a->r * b->e1124 + a->e1124 * b->r + a->e1 * b->e124 
            + a->e124 * b->e1 + a->e2 * b->e114 + a->e114 * b->e2 
            + a->e4 * b->e112 + a->e112 * b->e4 + a->e11 * b->e24 
            + a->e12 * b->e14 + a->e14 * b->e12 + a->e24 * b->e11;
  res.e1224 = c->e1224 + a->r * b->e1224 + a->e1224 * b->r + a->e1 * b->e224 
            + a->e224 * b->e1 + a->e2 * b->e124 + a->e124 * b->e2 
            + a->e4 * b->e122 + a->e122 * b->e4 + a->e12 * b->e24 
            + a->e22 * b->e14 + a->e14 * b->e22 + a->e24 * b->e12;
  res.e2224 = c->e2224 + a->r * b->e2224 + a->e2224 * b->r + a->e2 * b->e224 
            + a->e224 * b->e2 + a->e4 * b->e222 + a->e222 * b->e4 
            + a->e22 * b->e24 + a->e24 * b->e22;
  res.e1134 = c->e1134 + a->r * b->e1134 + a->e1134 * b->r + a->e1 * b->e134 
            + a->e134 * b->e1 + a->e3 * b->e114 + a->e114 * b->e3 
            + a->e4 * b->e113 + a->e113 * b->e4 + a->e11 * b->e34 
            + a->e13 * b->e14 + a->e14 * b->e13 + a->e34 * b->e11;
  res.e1234 = c->e1234 + a->r * b->e1234 + a->e1234 * b->r + a->e1 * b->e234 
            + a->e234 * b->e1 + a->e2 * b->e134 + a->e134 * b->e2 
            + a->e3 * b->e124 + a->e124 * b->e3 + a->e4 * b->e123 
            + a->e123 * b->e4 + a->e12 * b->e34 + a->e13 * b->e24 
            + a->e23 * b->e14 + a->e14 * b->e23 + a->e24 * b->e13 
            + a->e34 * b->e12;
  res.e2234 = c->e2234 + a->r * b->e2234 + a->e2234 * b->r + a->e2 * b->e234 
            + a->e234 * b->e2 + a->e3 * b->e224 + a->e224 * b->e3 
            + a->e4 * b->e223 + a->e223 * b->e4 + a->e22 * b->e34 
            + a->e23 * b->e24 + a->e24 * b->e23 + a->e34 * b->e22;
  res.e1334 = c->e1334 + a->r * b->e1334 + a->e1334 * b->r + a->e1 * b->e334 
            + a->e334 * b->e1 + a->e3 * b->e134 + a->e134 * b->e3 
            + a->e4 * b->e133 + a->e133 * b->e4 + a->e13 * b->e34 
            + a->e33 * b->e14 + a->e14 * b->e33 + a->e34 * b->e13;
  res.e2334 = c->e2334 + a->r * b->e2334 + a->e2334 * b->r + a->e2 * b->e334 
            + a->e334 * b->e2 + a->e3 * b->e234 + a->e234 * b->e3 
            + a->e4 * b->e233 + a->e233 * b->e4 + a->e23 * b->e34 
            + a->e33 * b->e24 + a->e24 * b->e33 + a->e34 * b->e23;
  res.e3334 = c->e3334 + a->r * b->e3334 + a->e3334 * b->r + a->e3 * b->e334 
            + a->e334 * b->e3 + a->e4 * b->e333 + a->e333 * b->e4 
            + a->e33 * b->e34 + a->e34 * b->e33;
  res.e1144 = c->e1144 + a->r * b->e1144 + a->e1144 * b->r + a->e1 * b->e144 
            + a->e144 * b->e1 + a->e4 * b->e114 + a->e114 * b->e4 
            + a->e11 * b->e44 + a->e14 * b->e14 + a->e44 * b->e11;
  res.e1244 = c->e1244 + a->r * b->e1244 + a->e1244 * b->r + a->e1 * b->e244 
            + a->e244 * b->e1 + a->e2 * b->e144 + a->e144 * b->e2 
            + a->e4 * b->e124 + a->e124 * b->e4 + a->e12 * b->e44 
            + a->e14 * b->e24 + a->e24 * b->e14 + a->e44 * b->e12;
  res.e2244 = c->e2244 + a->r * b->e2244 + a->e2244 * b->r + a->e2 * b->e244 
            + a->e244 * b->e2 + a->e4 * b->e224 + a->e224 * b->e4 
            + a->e22 * b->e44 + a->e24 * b->e24 + a->e44 * b->e22;
  res.e1344 = c->e1344 + a->r * b->e1344 + a->e1344 * b->r + a->e1 * b->e344 
            + a->e344 * b->e1 + a->e3 * b->e144 + a->e144 * b->e3 
            + a->e4 * b->e134 + a->e134 * b->e4 + a->e13 * b->e44 
            + a->e14 * b->e34 + a->e34 * b->e14 + a->e44 * b->e13;
  res.e2344 = c->e2344 + a->r * b->e2344 + a->e2344 * b->r + a->e2 * b->e344 
            + a->e344 * b->e2 + a->e3 * b->e244 + a->e244 * b->e3 
            + a->e4 * b->e234 + a->e234 * b->e4 + a->e23 * b->e44 
            + a->e24 * b->e34 + a->e34 * b->e24 + a->e44 * b->e23;
  res.e3344 = c->e3344 + a->r * b->e3344 + a->e3344 * b->r + a->e3 * b->e344 
            + a->e344 * b->e3 + a->e4 * b->e334 + a->e334 * b->e4 
            + a->e33 * b->e44 + a->e34 * b->e34 + a->e44 * b->e33;
  res.e1444 = c->e1444 + a->r * b->e1444 + a->e1444 * b->r + a->e1 * b->e444 
            + a->e444 * b->e1 + a->e4 * b->e144 + a->e144 * b->e4 
            + a->e14 * b->e44 + a->e44 * b->e14;
  res.e2444 = c->e2444 + a->r * b->e2444 + a->e2444 * b->r + a->e2 * b->e444 
            + a->e444 * b->e2 + a->e4 * b->e244 + a->e244 * b->e4 
            + a->e24 * b->e44 + a->e44 * b->e24;
  res.e3444 = c->e3444 + a->r * b->e3444 + a->e3444 * b->r + a->e3 * b->e444 
            + a->e444 * b->e3 + a->e4 * b->e344 + a->e344 * b->e4 
            + a->e34 * b->e44 + a->e44 * b->e34;
  res.e4444 = c->e4444 + a->r * b->e4444 + a->e4444 * b->r + a->e4 * b->e444 
            + a->e444 * b->e4 + a->e44 * b->e44;

  return res;

}

void onumm4n4_gem_oo_to(  onumm4n4_t* a,  onumm4n4_t* b,  onumm4n4_t* c, onumm4n4_t* res){
  //  General multiplication like function 'a * b + c'
  // Real;
  res->r = c->r + a->r * b->r;
  // Order 1;
  res->e1 = c->e1 + a->r * b->e1 + a->e1 * b->r;
  res->e2 = c->e2 + a->r * b->e2 + a->e2 * b->r;
  res->e3 = c->e3 + a->r * b->e3 + a->e3 * b->r;
  res->e4 = c->e4 + a->r * b->e4 + a->e4 * b->r;
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
  res->e1114 = c->e1114 + a->r * b->e1114 + a->e1114 * b->r + a->e1 * b->e114 
            + a->e114 * b->e1 + a->e4 * b->e111 + a->e111 * b->e4 
            + a->e11 * b->e14 + a->e14 * b->e11;
  res->e1124 = c->e1124 + a->r * b->e1124 + a->e1124 * b->r + a->e1 * b->e124 
            + a->e124 * b->e1 + a->e2 * b->e114 + a->e114 * b->e2 
            + a->e4 * b->e112 + a->e112 * b->e4 + a->e11 * b->e24 
            + a->e12 * b->e14 + a->e14 * b->e12 + a->e24 * b->e11;
  res->e1224 = c->e1224 + a->r * b->e1224 + a->e1224 * b->r + a->e1 * b->e224 
            + a->e224 * b->e1 + a->e2 * b->e124 + a->e124 * b->e2 
            + a->e4 * b->e122 + a->e122 * b->e4 + a->e12 * b->e24 
            + a->e22 * b->e14 + a->e14 * b->e22 + a->e24 * b->e12;
  res->e2224 = c->e2224 + a->r * b->e2224 + a->e2224 * b->r + a->e2 * b->e224 
            + a->e224 * b->e2 + a->e4 * b->e222 + a->e222 * b->e4 
            + a->e22 * b->e24 + a->e24 * b->e22;
  res->e1134 = c->e1134 + a->r * b->e1134 + a->e1134 * b->r + a->e1 * b->e134 
            + a->e134 * b->e1 + a->e3 * b->e114 + a->e114 * b->e3 
            + a->e4 * b->e113 + a->e113 * b->e4 + a->e11 * b->e34 
            + a->e13 * b->e14 + a->e14 * b->e13 + a->e34 * b->e11;
  res->e1234 = c->e1234 + a->r * b->e1234 + a->e1234 * b->r + a->e1 * b->e234 
            + a->e234 * b->e1 + a->e2 * b->e134 + a->e134 * b->e2 
            + a->e3 * b->e124 + a->e124 * b->e3 + a->e4 * b->e123 
            + a->e123 * b->e4 + a->e12 * b->e34 + a->e13 * b->e24 
            + a->e23 * b->e14 + a->e14 * b->e23 + a->e24 * b->e13 
            + a->e34 * b->e12;
  res->e2234 = c->e2234 + a->r * b->e2234 + a->e2234 * b->r + a->e2 * b->e234 
            + a->e234 * b->e2 + a->e3 * b->e224 + a->e224 * b->e3 
            + a->e4 * b->e223 + a->e223 * b->e4 + a->e22 * b->e34 
            + a->e23 * b->e24 + a->e24 * b->e23 + a->e34 * b->e22;
  res->e1334 = c->e1334 + a->r * b->e1334 + a->e1334 * b->r + a->e1 * b->e334 
            + a->e334 * b->e1 + a->e3 * b->e134 + a->e134 * b->e3 
            + a->e4 * b->e133 + a->e133 * b->e4 + a->e13 * b->e34 
            + a->e33 * b->e14 + a->e14 * b->e33 + a->e34 * b->e13;
  res->e2334 = c->e2334 + a->r * b->e2334 + a->e2334 * b->r + a->e2 * b->e334 
            + a->e334 * b->e2 + a->e3 * b->e234 + a->e234 * b->e3 
            + a->e4 * b->e233 + a->e233 * b->e4 + a->e23 * b->e34 
            + a->e33 * b->e24 + a->e24 * b->e33 + a->e34 * b->e23;
  res->e3334 = c->e3334 + a->r * b->e3334 + a->e3334 * b->r + a->e3 * b->e334 
            + a->e334 * b->e3 + a->e4 * b->e333 + a->e333 * b->e4 
            + a->e33 * b->e34 + a->e34 * b->e33;
  res->e1144 = c->e1144 + a->r * b->e1144 + a->e1144 * b->r + a->e1 * b->e144 
            + a->e144 * b->e1 + a->e4 * b->e114 + a->e114 * b->e4 
            + a->e11 * b->e44 + a->e14 * b->e14 + a->e44 * b->e11;
  res->e1244 = c->e1244 + a->r * b->e1244 + a->e1244 * b->r + a->e1 * b->e244 
            + a->e244 * b->e1 + a->e2 * b->e144 + a->e144 * b->e2 
            + a->e4 * b->e124 + a->e124 * b->e4 + a->e12 * b->e44 
            + a->e14 * b->e24 + a->e24 * b->e14 + a->e44 * b->e12;
  res->e2244 = c->e2244 + a->r * b->e2244 + a->e2244 * b->r + a->e2 * b->e244 
            + a->e244 * b->e2 + a->e4 * b->e224 + a->e224 * b->e4 
            + a->e22 * b->e44 + a->e24 * b->e24 + a->e44 * b->e22;
  res->e1344 = c->e1344 + a->r * b->e1344 + a->e1344 * b->r + a->e1 * b->e344 
            + a->e344 * b->e1 + a->e3 * b->e144 + a->e144 * b->e3 
            + a->e4 * b->e134 + a->e134 * b->e4 + a->e13 * b->e44 
            + a->e14 * b->e34 + a->e34 * b->e14 + a->e44 * b->e13;
  res->e2344 = c->e2344 + a->r * b->e2344 + a->e2344 * b->r + a->e2 * b->e344 
            + a->e344 * b->e2 + a->e3 * b->e244 + a->e244 * b->e3 
            + a->e4 * b->e234 + a->e234 * b->e4 + a->e23 * b->e44 
            + a->e24 * b->e34 + a->e34 * b->e24 + a->e44 * b->e23;
  res->e3344 = c->e3344 + a->r * b->e3344 + a->e3344 * b->r + a->e3 * b->e344 
            + a->e344 * b->e3 + a->e4 * b->e334 + a->e334 * b->e4 
            + a->e33 * b->e44 + a->e34 * b->e34 + a->e44 * b->e33;
  res->e1444 = c->e1444 + a->r * b->e1444 + a->e1444 * b->r + a->e1 * b->e444 
            + a->e444 * b->e1 + a->e4 * b->e144 + a->e144 * b->e4 
            + a->e14 * b->e44 + a->e44 * b->e14;
  res->e2444 = c->e2444 + a->r * b->e2444 + a->e2444 * b->r + a->e2 * b->e444 
            + a->e444 * b->e2 + a->e4 * b->e244 + a->e244 * b->e4 
            + a->e24 * b->e44 + a->e44 * b->e24;
  res->e3444 = c->e3444 + a->r * b->e3444 + a->e3444 * b->r + a->e3 * b->e444 
            + a->e444 * b->e3 + a->e4 * b->e344 + a->e344 * b->e4 
            + a->e34 * b->e44 + a->e44 * b->e34;
  res->e4444 = c->e4444 + a->r * b->e4444 + a->e4444 * b->r + a->e4 * b->e444 
            + a->e444 * b->e4 + a->e44 * b->e44;

}

onumm4n4_t onumm4n4_gem_ro(  coeff_t a,  onumm4n4_t* b,  onumm4n4_t* c){
  onumm4n4_t res;

  //  General multiplication like function 'a * b + c'
  // Real;
  res.r = c->r + a * b->r;
  // Order 1;
  res.e1 = c->e1 + a * b->e1;
  res.e2 = c->e2 + a * b->e2;
  res.e3 = c->e3 + a * b->e3;
  res.e4 = c->e4 + a * b->e4;
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
  res.e1114 = c->e1114 + a * b->e1114;
  res.e1124 = c->e1124 + a * b->e1124;
  res.e1224 = c->e1224 + a * b->e1224;
  res.e2224 = c->e2224 + a * b->e2224;
  res.e1134 = c->e1134 + a * b->e1134;
  res.e1234 = c->e1234 + a * b->e1234;
  res.e2234 = c->e2234 + a * b->e2234;
  res.e1334 = c->e1334 + a * b->e1334;
  res.e2334 = c->e2334 + a * b->e2334;
  res.e3334 = c->e3334 + a * b->e3334;
  res.e1144 = c->e1144 + a * b->e1144;
  res.e1244 = c->e1244 + a * b->e1244;
  res.e2244 = c->e2244 + a * b->e2244;
  res.e1344 = c->e1344 + a * b->e1344;
  res.e2344 = c->e2344 + a * b->e2344;
  res.e3344 = c->e3344 + a * b->e3344;
  res.e1444 = c->e1444 + a * b->e1444;
  res.e2444 = c->e2444 + a * b->e2444;
  res.e3444 = c->e3444 + a * b->e3444;
  res.e4444 = c->e4444 + a * b->e4444;

  return res;

}

void onumm4n4_gem_ro_to(  coeff_t a,  onumm4n4_t* b,  onumm4n4_t* c, onumm4n4_t* res){
  //  General multiplication like function 'a * b + c'
  // Real;
  res->r = c->r + a * b->r;
  // Order 1;
  res->e1 = c->e1 + a * b->e1;
  res->e2 = c->e2 + a * b->e2;
  res->e3 = c->e3 + a * b->e3;
  res->e4 = c->e4 + a * b->e4;
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
  res->e1114 = c->e1114 + a * b->e1114;
  res->e1124 = c->e1124 + a * b->e1124;
  res->e1224 = c->e1224 + a * b->e1224;
  res->e2224 = c->e2224 + a * b->e2224;
  res->e1134 = c->e1134 + a * b->e1134;
  res->e1234 = c->e1234 + a * b->e1234;
  res->e2234 = c->e2234 + a * b->e2234;
  res->e1334 = c->e1334 + a * b->e1334;
  res->e2334 = c->e2334 + a * b->e2334;
  res->e3334 = c->e3334 + a * b->e3334;
  res->e1144 = c->e1144 + a * b->e1144;
  res->e1244 = c->e1244 + a * b->e1244;
  res->e2244 = c->e2244 + a * b->e2244;
  res->e1344 = c->e1344 + a * b->e1344;
  res->e2344 = c->e2344 + a * b->e2344;
  res->e3344 = c->e3344 + a * b->e3344;
  res->e1444 = c->e1444 + a * b->e1444;
  res->e2444 = c->e2444 + a * b->e2444;
  res->e3444 = c->e3444 + a * b->e3444;
  res->e4444 = c->e4444 + a * b->e4444;

}

onumm4n4_t onumm4n4_feval(coeff_t* feval_re, onumm4n4_t* x){

  onumm4n4_t res;

  // feval function
  //  Definitions
  coeff_t factor=1, coef = 0;
  onumm4n4_t tmp1, tmp2, deltax = (*x), deltax_power = (*x);
  deltax.r = 0.0;
  deltax_power.r = 0.0;
  onumm4n4_set_r(0.0, &res);
  //  Real
  res.r = feval_re[0];
  // Order 1
  factor *=1;
  coef    = feval_re[1]/ factor;;
  onumm4n4_gem_ro_to( coef, &deltax_power, &res, &res);
  deltax_power = onumm4n4_mul_oo(&deltax_power,&deltax);
  // Order 2
  factor *=2;
  coef    = feval_re[2]/ factor;;
  onumm4n4_gem_ro_to( coef, &deltax_power, &res, &res);
  deltax_power = onumm4n4_mul_oo(&deltax_power,&deltax);
  // Order 3
  factor *=3;
  coef    = feval_re[3]/ factor;;
  onumm4n4_gem_ro_to( coef, &deltax_power, &res, &res);
  deltax_power = onumm4n4_mul_oo(&deltax_power,&deltax);
  // Order 4
  factor *=4;
  coef    = feval_re[4]/ factor;;
  onumm4n4_gem_ro_to( coef, &deltax_power, &res, &res);

  return res;

}

void onumm4n4_feval_to(coeff_t* feval_re, onumm4n4_t* x, onumm4n4_t* res){

  // feval function
  //  Definitions
  coeff_t factor=1, coef = 0;
  onumm4n4_t tmp1, tmp2, deltax = (*x), deltax_power = (*x);
  deltax.r = 0.0;
  deltax_power.r = 0.0;
  onumm4n4_set_r(0.0, res);
  //  Real
  res->r = feval_re[0];
  // Order 1
  factor *=1;
  coef    = feval_re[1]/ factor;;
  onumm4n4_gem_ro_to( coef, &deltax_power, res, res);
  deltax_power = onumm4n4_mul_oo(&deltax_power,&deltax);
  // Order 2
  factor *=2;
  coef    = feval_re[2]/ factor;;
  onumm4n4_gem_ro_to( coef, &deltax_power, res, res);
  deltax_power = onumm4n4_mul_oo(&deltax_power,&deltax);
  // Order 3
  factor *=3;
  coef    = feval_re[3]/ factor;;
  onumm4n4_gem_ro_to( coef, &deltax_power, res, res);
  deltax_power = onumm4n4_mul_oo(&deltax_power,&deltax);
  // Order 4
  factor *=4;
  coef    = feval_re[4]/ factor;;
  onumm4n4_gem_ro_to( coef, &deltax_power, res, res);

}

