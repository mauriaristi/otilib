
// Division.

// ****************************************************************************************************
onumm4n5_t onumm4n5_div_ro(coeff_t num, onumm4n5_t* den){

    
    onumm4n5_t inv = onumm4n5_pow(den,-1);
    onumm4n5_t res = onumm4n5_mul_ro(num,&inv);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
onumm4n5_t onumm4n5_div_oo(onumm4n5_t* num, onumm4n5_t* den){

    
    onumm4n5_t inv = onumm4n5_init();
    onumm4n5_pow_to(den,-1,&inv);
    onumm4n5_t res = onumm4n5_mul_oo(num,&inv);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
onumm4n5_t onumm4n5_div_or(onumm4n5_t* num, coeff_t val){

    return onumm4n5_mul_ro(1.0/val,num);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
onumm4n5_t onumm4n5_abs(onumm4n5_t* num){

	onumm4n5_t res;
    onumm4n5_abs_to(num,&res);
    return res;

}
// ----------------------------------------------------------------------------------------------------

onumm4n5_t onumm4n5_neg(  onumm4n5_t* lhs){

  onumm4n5_t res;

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
  res.e11114 = -lhs->e11114;
  res.e11124 = -lhs->e11124;
  res.e11224 = -lhs->e11224;
  res.e12224 = -lhs->e12224;
  res.e22224 = -lhs->e22224;
  res.e11134 = -lhs->e11134;
  res.e11234 = -lhs->e11234;
  res.e12234 = -lhs->e12234;
  res.e22234 = -lhs->e22234;
  res.e11334 = -lhs->e11334;
  res.e12334 = -lhs->e12334;
  res.e22334 = -lhs->e22334;
  res.e13334 = -lhs->e13334;
  res.e23334 = -lhs->e23334;
  res.e33334 = -lhs->e33334;
  res.e11144 = -lhs->e11144;
  res.e11244 = -lhs->e11244;
  res.e12244 = -lhs->e12244;
  res.e22244 = -lhs->e22244;
  res.e11344 = -lhs->e11344;
  res.e12344 = -lhs->e12344;
  res.e22344 = -lhs->e22344;
  res.e13344 = -lhs->e13344;
  res.e23344 = -lhs->e23344;
  res.e33344 = -lhs->e33344;
  res.e11444 = -lhs->e11444;
  res.e12444 = -lhs->e12444;
  res.e22444 = -lhs->e22444;
  res.e13444 = -lhs->e13444;
  res.e23444 = -lhs->e23444;
  res.e33444 = -lhs->e33444;
  res.e14444 = -lhs->e14444;
  res.e24444 = -lhs->e24444;
  res.e34444 = -lhs->e34444;
  res.e44444 = -lhs->e44444;

  return res;

}

void onumm4n5_neg_to(  onumm4n5_t* lhs, onumm4n5_t* res){

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
  res->e11114 = -lhs->e11114;
  res->e11124 = -lhs->e11124;
  res->e11224 = -lhs->e11224;
  res->e12224 = -lhs->e12224;
  res->e22224 = -lhs->e22224;
  res->e11134 = -lhs->e11134;
  res->e11234 = -lhs->e11234;
  res->e12234 = -lhs->e12234;
  res->e22234 = -lhs->e22234;
  res->e11334 = -lhs->e11334;
  res->e12334 = -lhs->e12334;
  res->e22334 = -lhs->e22334;
  res->e13334 = -lhs->e13334;
  res->e23334 = -lhs->e23334;
  res->e33334 = -lhs->e33334;
  res->e11144 = -lhs->e11144;
  res->e11244 = -lhs->e11244;
  res->e12244 = -lhs->e12244;
  res->e22244 = -lhs->e22244;
  res->e11344 = -lhs->e11344;
  res->e12344 = -lhs->e12344;
  res->e22344 = -lhs->e22344;
  res->e13344 = -lhs->e13344;
  res->e23344 = -lhs->e23344;
  res->e33344 = -lhs->e33344;
  res->e11444 = -lhs->e11444;
  res->e12444 = -lhs->e12444;
  res->e22444 = -lhs->e22444;
  res->e13444 = -lhs->e13444;
  res->e23444 = -lhs->e23444;
  res->e33444 = -lhs->e33444;
  res->e14444 = -lhs->e14444;
  res->e24444 = -lhs->e24444;
  res->e34444 = -lhs->e34444;
  res->e44444 = -lhs->e44444;

}

onumm4n5_t onumm4n5_sum_oo(  onumm4n5_t* lhs,  onumm4n5_t* rhs){
  onumm4n5_t res;

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
  res.e11114 = lhs->e11114 + rhs->e11114;
  res.e11124 = lhs->e11124 + rhs->e11124;
  res.e11224 = lhs->e11224 + rhs->e11224;
  res.e12224 = lhs->e12224 + rhs->e12224;
  res.e22224 = lhs->e22224 + rhs->e22224;
  res.e11134 = lhs->e11134 + rhs->e11134;
  res.e11234 = lhs->e11234 + rhs->e11234;
  res.e12234 = lhs->e12234 + rhs->e12234;
  res.e22234 = lhs->e22234 + rhs->e22234;
  res.e11334 = lhs->e11334 + rhs->e11334;
  res.e12334 = lhs->e12334 + rhs->e12334;
  res.e22334 = lhs->e22334 + rhs->e22334;
  res.e13334 = lhs->e13334 + rhs->e13334;
  res.e23334 = lhs->e23334 + rhs->e23334;
  res.e33334 = lhs->e33334 + rhs->e33334;
  res.e11144 = lhs->e11144 + rhs->e11144;
  res.e11244 = lhs->e11244 + rhs->e11244;
  res.e12244 = lhs->e12244 + rhs->e12244;
  res.e22244 = lhs->e22244 + rhs->e22244;
  res.e11344 = lhs->e11344 + rhs->e11344;
  res.e12344 = lhs->e12344 + rhs->e12344;
  res.e22344 = lhs->e22344 + rhs->e22344;
  res.e13344 = lhs->e13344 + rhs->e13344;
  res.e23344 = lhs->e23344 + rhs->e23344;
  res.e33344 = lhs->e33344 + rhs->e33344;
  res.e11444 = lhs->e11444 + rhs->e11444;
  res.e12444 = lhs->e12444 + rhs->e12444;
  res.e22444 = lhs->e22444 + rhs->e22444;
  res.e13444 = lhs->e13444 + rhs->e13444;
  res.e23444 = lhs->e23444 + rhs->e23444;
  res.e33444 = lhs->e33444 + rhs->e33444;
  res.e14444 = lhs->e14444 + rhs->e14444;
  res.e24444 = lhs->e24444 + rhs->e24444;
  res.e34444 = lhs->e34444 + rhs->e34444;
  res.e44444 = lhs->e44444 + rhs->e44444;

  return res;

}

void onumm4n5_sum_oo_to(  onumm4n5_t* lhs,  onumm4n5_t* rhs, onumm4n5_t* res){
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
  res->e11114 = lhs->e11114 + rhs->e11114;
  res->e11124 = lhs->e11124 + rhs->e11124;
  res->e11224 = lhs->e11224 + rhs->e11224;
  res->e12224 = lhs->e12224 + rhs->e12224;
  res->e22224 = lhs->e22224 + rhs->e22224;
  res->e11134 = lhs->e11134 + rhs->e11134;
  res->e11234 = lhs->e11234 + rhs->e11234;
  res->e12234 = lhs->e12234 + rhs->e12234;
  res->e22234 = lhs->e22234 + rhs->e22234;
  res->e11334 = lhs->e11334 + rhs->e11334;
  res->e12334 = lhs->e12334 + rhs->e12334;
  res->e22334 = lhs->e22334 + rhs->e22334;
  res->e13334 = lhs->e13334 + rhs->e13334;
  res->e23334 = lhs->e23334 + rhs->e23334;
  res->e33334 = lhs->e33334 + rhs->e33334;
  res->e11144 = lhs->e11144 + rhs->e11144;
  res->e11244 = lhs->e11244 + rhs->e11244;
  res->e12244 = lhs->e12244 + rhs->e12244;
  res->e22244 = lhs->e22244 + rhs->e22244;
  res->e11344 = lhs->e11344 + rhs->e11344;
  res->e12344 = lhs->e12344 + rhs->e12344;
  res->e22344 = lhs->e22344 + rhs->e22344;
  res->e13344 = lhs->e13344 + rhs->e13344;
  res->e23344 = lhs->e23344 + rhs->e23344;
  res->e33344 = lhs->e33344 + rhs->e33344;
  res->e11444 = lhs->e11444 + rhs->e11444;
  res->e12444 = lhs->e12444 + rhs->e12444;
  res->e22444 = lhs->e22444 + rhs->e22444;
  res->e13444 = lhs->e13444 + rhs->e13444;
  res->e23444 = lhs->e23444 + rhs->e23444;
  res->e33444 = lhs->e33444 + rhs->e33444;
  res->e14444 = lhs->e14444 + rhs->e14444;
  res->e24444 = lhs->e24444 + rhs->e24444;
  res->e34444 = lhs->e34444 + rhs->e34444;
  res->e44444 = lhs->e44444 + rhs->e44444;

}

onumm4n5_t onumm4n5_sum_ro(  coeff_t lhs,  onumm4n5_t* rhs){
  onumm4n5_t res;

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
  res.e11114 =  + rhs->e11114;
  res.e11124 =  + rhs->e11124;
  res.e11224 =  + rhs->e11224;
  res.e12224 =  + rhs->e12224;
  res.e22224 =  + rhs->e22224;
  res.e11134 =  + rhs->e11134;
  res.e11234 =  + rhs->e11234;
  res.e12234 =  + rhs->e12234;
  res.e22234 =  + rhs->e22234;
  res.e11334 =  + rhs->e11334;
  res.e12334 =  + rhs->e12334;
  res.e22334 =  + rhs->e22334;
  res.e13334 =  + rhs->e13334;
  res.e23334 =  + rhs->e23334;
  res.e33334 =  + rhs->e33334;
  res.e11144 =  + rhs->e11144;
  res.e11244 =  + rhs->e11244;
  res.e12244 =  + rhs->e12244;
  res.e22244 =  + rhs->e22244;
  res.e11344 =  + rhs->e11344;
  res.e12344 =  + rhs->e12344;
  res.e22344 =  + rhs->e22344;
  res.e13344 =  + rhs->e13344;
  res.e23344 =  + rhs->e23344;
  res.e33344 =  + rhs->e33344;
  res.e11444 =  + rhs->e11444;
  res.e12444 =  + rhs->e12444;
  res.e22444 =  + rhs->e22444;
  res.e13444 =  + rhs->e13444;
  res.e23444 =  + rhs->e23444;
  res.e33444 =  + rhs->e33444;
  res.e14444 =  + rhs->e14444;
  res.e24444 =  + rhs->e24444;
  res.e34444 =  + rhs->e34444;
  res.e44444 =  + rhs->e44444;

  return res;

}

void onumm4n5_sum_ro_to(  coeff_t lhs,  onumm4n5_t* rhs, onumm4n5_t* res){
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
  res->e11114 =  + rhs->e11114;
  res->e11124 =  + rhs->e11124;
  res->e11224 =  + rhs->e11224;
  res->e12224 =  + rhs->e12224;
  res->e22224 =  + rhs->e22224;
  res->e11134 =  + rhs->e11134;
  res->e11234 =  + rhs->e11234;
  res->e12234 =  + rhs->e12234;
  res->e22234 =  + rhs->e22234;
  res->e11334 =  + rhs->e11334;
  res->e12334 =  + rhs->e12334;
  res->e22334 =  + rhs->e22334;
  res->e13334 =  + rhs->e13334;
  res->e23334 =  + rhs->e23334;
  res->e33334 =  + rhs->e33334;
  res->e11144 =  + rhs->e11144;
  res->e11244 =  + rhs->e11244;
  res->e12244 =  + rhs->e12244;
  res->e22244 =  + rhs->e22244;
  res->e11344 =  + rhs->e11344;
  res->e12344 =  + rhs->e12344;
  res->e22344 =  + rhs->e22344;
  res->e13344 =  + rhs->e13344;
  res->e23344 =  + rhs->e23344;
  res->e33344 =  + rhs->e33344;
  res->e11444 =  + rhs->e11444;
  res->e12444 =  + rhs->e12444;
  res->e22444 =  + rhs->e22444;
  res->e13444 =  + rhs->e13444;
  res->e23444 =  + rhs->e23444;
  res->e33444 =  + rhs->e33444;
  res->e14444 =  + rhs->e14444;
  res->e24444 =  + rhs->e24444;
  res->e34444 =  + rhs->e34444;
  res->e44444 =  + rhs->e44444;

}

onumm4n5_t onumm4n5_sub_oo(  onumm4n5_t* lhs,  onumm4n5_t* rhs){
  onumm4n5_t res;

  // Addition like function 'lhs - rhs'
  //  Real
  res.r = lhs->r - rhs->r;
  // Order 1
  res.e1 = lhs->e1 - rhs->e1;
  res.e2 = lhs->e2 - rhs->e2;
  res.e3 = lhs->e3 - rhs->e3;
  res.e4 = lhs->e4 - rhs->e4;
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
  res.e1114 = lhs->e1114 - rhs->e1114;
  res.e1124 = lhs->e1124 - rhs->e1124;
  res.e1224 = lhs->e1224 - rhs->e1224;
  res.e2224 = lhs->e2224 - rhs->e2224;
  res.e1134 = lhs->e1134 - rhs->e1134;
  res.e1234 = lhs->e1234 - rhs->e1234;
  res.e2234 = lhs->e2234 - rhs->e2234;
  res.e1334 = lhs->e1334 - rhs->e1334;
  res.e2334 = lhs->e2334 - rhs->e2334;
  res.e3334 = lhs->e3334 - rhs->e3334;
  res.e1144 = lhs->e1144 - rhs->e1144;
  res.e1244 = lhs->e1244 - rhs->e1244;
  res.e2244 = lhs->e2244 - rhs->e2244;
  res.e1344 = lhs->e1344 - rhs->e1344;
  res.e2344 = lhs->e2344 - rhs->e2344;
  res.e3344 = lhs->e3344 - rhs->e3344;
  res.e1444 = lhs->e1444 - rhs->e1444;
  res.e2444 = lhs->e2444 - rhs->e2444;
  res.e3444 = lhs->e3444 - rhs->e3444;
  res.e4444 = lhs->e4444 - rhs->e4444;
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
  res.e11114 = lhs->e11114 - rhs->e11114;
  res.e11124 = lhs->e11124 - rhs->e11124;
  res.e11224 = lhs->e11224 - rhs->e11224;
  res.e12224 = lhs->e12224 - rhs->e12224;
  res.e22224 = lhs->e22224 - rhs->e22224;
  res.e11134 = lhs->e11134 - rhs->e11134;
  res.e11234 = lhs->e11234 - rhs->e11234;
  res.e12234 = lhs->e12234 - rhs->e12234;
  res.e22234 = lhs->e22234 - rhs->e22234;
  res.e11334 = lhs->e11334 - rhs->e11334;
  res.e12334 = lhs->e12334 - rhs->e12334;
  res.e22334 = lhs->e22334 - rhs->e22334;
  res.e13334 = lhs->e13334 - rhs->e13334;
  res.e23334 = lhs->e23334 - rhs->e23334;
  res.e33334 = lhs->e33334 - rhs->e33334;
  res.e11144 = lhs->e11144 - rhs->e11144;
  res.e11244 = lhs->e11244 - rhs->e11244;
  res.e12244 = lhs->e12244 - rhs->e12244;
  res.e22244 = lhs->e22244 - rhs->e22244;
  res.e11344 = lhs->e11344 - rhs->e11344;
  res.e12344 = lhs->e12344 - rhs->e12344;
  res.e22344 = lhs->e22344 - rhs->e22344;
  res.e13344 = lhs->e13344 - rhs->e13344;
  res.e23344 = lhs->e23344 - rhs->e23344;
  res.e33344 = lhs->e33344 - rhs->e33344;
  res.e11444 = lhs->e11444 - rhs->e11444;
  res.e12444 = lhs->e12444 - rhs->e12444;
  res.e22444 = lhs->e22444 - rhs->e22444;
  res.e13444 = lhs->e13444 - rhs->e13444;
  res.e23444 = lhs->e23444 - rhs->e23444;
  res.e33444 = lhs->e33444 - rhs->e33444;
  res.e14444 = lhs->e14444 - rhs->e14444;
  res.e24444 = lhs->e24444 - rhs->e24444;
  res.e34444 = lhs->e34444 - rhs->e34444;
  res.e44444 = lhs->e44444 - rhs->e44444;

  return res;

}

void onumm4n5_sub_oo_to(  onumm4n5_t* lhs,  onumm4n5_t* rhs, onumm4n5_t* res){
  // Addition like function 'lhs - rhs'
  //  Real
  res->r = lhs->r - rhs->r;
  // Order 1
  res->e1 = lhs->e1 - rhs->e1;
  res->e2 = lhs->e2 - rhs->e2;
  res->e3 = lhs->e3 - rhs->e3;
  res->e4 = lhs->e4 - rhs->e4;
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
  res->e1114 = lhs->e1114 - rhs->e1114;
  res->e1124 = lhs->e1124 - rhs->e1124;
  res->e1224 = lhs->e1224 - rhs->e1224;
  res->e2224 = lhs->e2224 - rhs->e2224;
  res->e1134 = lhs->e1134 - rhs->e1134;
  res->e1234 = lhs->e1234 - rhs->e1234;
  res->e2234 = lhs->e2234 - rhs->e2234;
  res->e1334 = lhs->e1334 - rhs->e1334;
  res->e2334 = lhs->e2334 - rhs->e2334;
  res->e3334 = lhs->e3334 - rhs->e3334;
  res->e1144 = lhs->e1144 - rhs->e1144;
  res->e1244 = lhs->e1244 - rhs->e1244;
  res->e2244 = lhs->e2244 - rhs->e2244;
  res->e1344 = lhs->e1344 - rhs->e1344;
  res->e2344 = lhs->e2344 - rhs->e2344;
  res->e3344 = lhs->e3344 - rhs->e3344;
  res->e1444 = lhs->e1444 - rhs->e1444;
  res->e2444 = lhs->e2444 - rhs->e2444;
  res->e3444 = lhs->e3444 - rhs->e3444;
  res->e4444 = lhs->e4444 - rhs->e4444;
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
  res->e11114 = lhs->e11114 - rhs->e11114;
  res->e11124 = lhs->e11124 - rhs->e11124;
  res->e11224 = lhs->e11224 - rhs->e11224;
  res->e12224 = lhs->e12224 - rhs->e12224;
  res->e22224 = lhs->e22224 - rhs->e22224;
  res->e11134 = lhs->e11134 - rhs->e11134;
  res->e11234 = lhs->e11234 - rhs->e11234;
  res->e12234 = lhs->e12234 - rhs->e12234;
  res->e22234 = lhs->e22234 - rhs->e22234;
  res->e11334 = lhs->e11334 - rhs->e11334;
  res->e12334 = lhs->e12334 - rhs->e12334;
  res->e22334 = lhs->e22334 - rhs->e22334;
  res->e13334 = lhs->e13334 - rhs->e13334;
  res->e23334 = lhs->e23334 - rhs->e23334;
  res->e33334 = lhs->e33334 - rhs->e33334;
  res->e11144 = lhs->e11144 - rhs->e11144;
  res->e11244 = lhs->e11244 - rhs->e11244;
  res->e12244 = lhs->e12244 - rhs->e12244;
  res->e22244 = lhs->e22244 - rhs->e22244;
  res->e11344 = lhs->e11344 - rhs->e11344;
  res->e12344 = lhs->e12344 - rhs->e12344;
  res->e22344 = lhs->e22344 - rhs->e22344;
  res->e13344 = lhs->e13344 - rhs->e13344;
  res->e23344 = lhs->e23344 - rhs->e23344;
  res->e33344 = lhs->e33344 - rhs->e33344;
  res->e11444 = lhs->e11444 - rhs->e11444;
  res->e12444 = lhs->e12444 - rhs->e12444;
  res->e22444 = lhs->e22444 - rhs->e22444;
  res->e13444 = lhs->e13444 - rhs->e13444;
  res->e23444 = lhs->e23444 - rhs->e23444;
  res->e33444 = lhs->e33444 - rhs->e33444;
  res->e14444 = lhs->e14444 - rhs->e14444;
  res->e24444 = lhs->e24444 - rhs->e24444;
  res->e34444 = lhs->e34444 - rhs->e34444;
  res->e44444 = lhs->e44444 - rhs->e44444;

}

onumm4n5_t onumm4n5_sub_ro(  coeff_t lhs,  onumm4n5_t* rhs){
  onumm4n5_t res;

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
  res.e11114 =  - rhs->e11114;
  res.e11124 =  - rhs->e11124;
  res.e11224 =  - rhs->e11224;
  res.e12224 =  - rhs->e12224;
  res.e22224 =  - rhs->e22224;
  res.e11134 =  - rhs->e11134;
  res.e11234 =  - rhs->e11234;
  res.e12234 =  - rhs->e12234;
  res.e22234 =  - rhs->e22234;
  res.e11334 =  - rhs->e11334;
  res.e12334 =  - rhs->e12334;
  res.e22334 =  - rhs->e22334;
  res.e13334 =  - rhs->e13334;
  res.e23334 =  - rhs->e23334;
  res.e33334 =  - rhs->e33334;
  res.e11144 =  - rhs->e11144;
  res.e11244 =  - rhs->e11244;
  res.e12244 =  - rhs->e12244;
  res.e22244 =  - rhs->e22244;
  res.e11344 =  - rhs->e11344;
  res.e12344 =  - rhs->e12344;
  res.e22344 =  - rhs->e22344;
  res.e13344 =  - rhs->e13344;
  res.e23344 =  - rhs->e23344;
  res.e33344 =  - rhs->e33344;
  res.e11444 =  - rhs->e11444;
  res.e12444 =  - rhs->e12444;
  res.e22444 =  - rhs->e22444;
  res.e13444 =  - rhs->e13444;
  res.e23444 =  - rhs->e23444;
  res.e33444 =  - rhs->e33444;
  res.e14444 =  - rhs->e14444;
  res.e24444 =  - rhs->e24444;
  res.e34444 =  - rhs->e34444;
  res.e44444 =  - rhs->e44444;

  return res;

}

void onumm4n5_sub_ro_to(  coeff_t lhs,  onumm4n5_t* rhs, onumm4n5_t* res){
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
  res->e11114 =  - rhs->e11114;
  res->e11124 =  - rhs->e11124;
  res->e11224 =  - rhs->e11224;
  res->e12224 =  - rhs->e12224;
  res->e22224 =  - rhs->e22224;
  res->e11134 =  - rhs->e11134;
  res->e11234 =  - rhs->e11234;
  res->e12234 =  - rhs->e12234;
  res->e22234 =  - rhs->e22234;
  res->e11334 =  - rhs->e11334;
  res->e12334 =  - rhs->e12334;
  res->e22334 =  - rhs->e22334;
  res->e13334 =  - rhs->e13334;
  res->e23334 =  - rhs->e23334;
  res->e33334 =  - rhs->e33334;
  res->e11144 =  - rhs->e11144;
  res->e11244 =  - rhs->e11244;
  res->e12244 =  - rhs->e12244;
  res->e22244 =  - rhs->e22244;
  res->e11344 =  - rhs->e11344;
  res->e12344 =  - rhs->e12344;
  res->e22344 =  - rhs->e22344;
  res->e13344 =  - rhs->e13344;
  res->e23344 =  - rhs->e23344;
  res->e33344 =  - rhs->e33344;
  res->e11444 =  - rhs->e11444;
  res->e12444 =  - rhs->e12444;
  res->e22444 =  - rhs->e22444;
  res->e13444 =  - rhs->e13444;
  res->e23444 =  - rhs->e23444;
  res->e33444 =  - rhs->e33444;
  res->e14444 =  - rhs->e14444;
  res->e24444 =  - rhs->e24444;
  res->e34444 =  - rhs->e34444;
  res->e44444 =  - rhs->e44444;

}

onumm4n5_t onumm4n5_sub_or(  onumm4n5_t* lhs,  coeff_t rhs){
  onumm4n5_t res;

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
  res.e11114 = lhs->e11114;
  res.e11124 = lhs->e11124;
  res.e11224 = lhs->e11224;
  res.e12224 = lhs->e12224;
  res.e22224 = lhs->e22224;
  res.e11134 = lhs->e11134;
  res.e11234 = lhs->e11234;
  res.e12234 = lhs->e12234;
  res.e22234 = lhs->e22234;
  res.e11334 = lhs->e11334;
  res.e12334 = lhs->e12334;
  res.e22334 = lhs->e22334;
  res.e13334 = lhs->e13334;
  res.e23334 = lhs->e23334;
  res.e33334 = lhs->e33334;
  res.e11144 = lhs->e11144;
  res.e11244 = lhs->e11244;
  res.e12244 = lhs->e12244;
  res.e22244 = lhs->e22244;
  res.e11344 = lhs->e11344;
  res.e12344 = lhs->e12344;
  res.e22344 = lhs->e22344;
  res.e13344 = lhs->e13344;
  res.e23344 = lhs->e23344;
  res.e33344 = lhs->e33344;
  res.e11444 = lhs->e11444;
  res.e12444 = lhs->e12444;
  res.e22444 = lhs->e22444;
  res.e13444 = lhs->e13444;
  res.e23444 = lhs->e23444;
  res.e33444 = lhs->e33444;
  res.e14444 = lhs->e14444;
  res.e24444 = lhs->e24444;
  res.e34444 = lhs->e34444;
  res.e44444 = lhs->e44444;

  return res;

}

void onumm4n5_sub_or_to(  onumm4n5_t* lhs,  coeff_t rhs, onumm4n5_t* res){
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
  res->e11114 = lhs->e11114;
  res->e11124 = lhs->e11124;
  res->e11224 = lhs->e11224;
  res->e12224 = lhs->e12224;
  res->e22224 = lhs->e22224;
  res->e11134 = lhs->e11134;
  res->e11234 = lhs->e11234;
  res->e12234 = lhs->e12234;
  res->e22234 = lhs->e22234;
  res->e11334 = lhs->e11334;
  res->e12334 = lhs->e12334;
  res->e22334 = lhs->e22334;
  res->e13334 = lhs->e13334;
  res->e23334 = lhs->e23334;
  res->e33334 = lhs->e33334;
  res->e11144 = lhs->e11144;
  res->e11244 = lhs->e11244;
  res->e12244 = lhs->e12244;
  res->e22244 = lhs->e22244;
  res->e11344 = lhs->e11344;
  res->e12344 = lhs->e12344;
  res->e22344 = lhs->e22344;
  res->e13344 = lhs->e13344;
  res->e23344 = lhs->e23344;
  res->e33344 = lhs->e33344;
  res->e11444 = lhs->e11444;
  res->e12444 = lhs->e12444;
  res->e22444 = lhs->e22444;
  res->e13444 = lhs->e13444;
  res->e23444 = lhs->e23444;
  res->e33444 = lhs->e33444;
  res->e14444 = lhs->e14444;
  res->e24444 = lhs->e24444;
  res->e34444 = lhs->e34444;
  res->e44444 = lhs->e44444;

}

onumm4n5_t onumm4n5_mul_oo(  onumm4n5_t* lhs,  onumm4n5_t* rhs){
  onumm4n5_t res;

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
  res.e11114 = lhs->r * rhs->e11114 + lhs->e11114 * rhs->r + lhs->e1 * rhs->e1114 
             + lhs->e1114 * rhs->e1 + lhs->e4 * rhs->e1111 + lhs->e1111 * rhs->e4 
             + lhs->e11 * rhs->e114 + lhs->e114 * rhs->e11 + lhs->e14 * rhs->e111 
             + lhs->e111 * rhs->e14;
  res.e11124 = lhs->r * rhs->e11124 + lhs->e11124 * rhs->r + lhs->e1 * rhs->e1124 
             + lhs->e1124 * rhs->e1 + lhs->e2 * rhs->e1114 + lhs->e1114 * rhs->e2 
             + lhs->e4 * rhs->e1112 + lhs->e1112 * rhs->e4 + lhs->e11 * rhs->e124 
             + lhs->e124 * rhs->e11 + lhs->e12 * rhs->e114 + lhs->e114 * rhs->e12 
             + lhs->e14 * rhs->e112 + lhs->e112 * rhs->e14 + lhs->e24 * rhs->e111 
             + lhs->e111 * rhs->e24;
  res.e11224 = lhs->r * rhs->e11224 + lhs->e11224 * rhs->r + lhs->e1 * rhs->e1224 
             + lhs->e1224 * rhs->e1 + lhs->e2 * rhs->e1124 + lhs->e1124 * rhs->e2 
             + lhs->e4 * rhs->e1122 + lhs->e1122 * rhs->e4 + lhs->e11 * rhs->e224 
             + lhs->e224 * rhs->e11 + lhs->e12 * rhs->e124 + lhs->e124 * rhs->e12 
             + lhs->e22 * rhs->e114 + lhs->e114 * rhs->e22 + lhs->e14 * rhs->e122 
             + lhs->e122 * rhs->e14 + lhs->e24 * rhs->e112 + lhs->e112 * rhs->e24;
  res.e12224 = lhs->r * rhs->e12224 + lhs->e12224 * rhs->r + lhs->e1 * rhs->e2224 
             + lhs->e2224 * rhs->e1 + lhs->e2 * rhs->e1224 + lhs->e1224 * rhs->e2 
             + lhs->e4 * rhs->e1222 + lhs->e1222 * rhs->e4 + lhs->e12 * rhs->e224 
             + lhs->e224 * rhs->e12 + lhs->e22 * rhs->e124 + lhs->e124 * rhs->e22 
             + lhs->e14 * rhs->e222 + lhs->e222 * rhs->e14 + lhs->e24 * rhs->e122 
             + lhs->e122 * rhs->e24;
  res.e22224 = lhs->r * rhs->e22224 + lhs->e22224 * rhs->r + lhs->e2 * rhs->e2224 
             + lhs->e2224 * rhs->e2 + lhs->e4 * rhs->e2222 + lhs->e2222 * rhs->e4 
             + lhs->e22 * rhs->e224 + lhs->e224 * rhs->e22 + lhs->e24 * rhs->e222 
             + lhs->e222 * rhs->e24;
  res.e11134 = lhs->r * rhs->e11134 + lhs->e11134 * rhs->r + lhs->e1 * rhs->e1134 
             + lhs->e1134 * rhs->e1 + lhs->e3 * rhs->e1114 + lhs->e1114 * rhs->e3 
             + lhs->e4 * rhs->e1113 + lhs->e1113 * rhs->e4 + lhs->e11 * rhs->e134 
             + lhs->e134 * rhs->e11 + lhs->e13 * rhs->e114 + lhs->e114 * rhs->e13 
             + lhs->e14 * rhs->e113 + lhs->e113 * rhs->e14 + lhs->e34 * rhs->e111 
             + lhs->e111 * rhs->e34;
  res.e11234 = lhs->r * rhs->e11234 + lhs->e11234 * rhs->r + lhs->e1 * rhs->e1234 
             + lhs->e1234 * rhs->e1 + lhs->e2 * rhs->e1134 + lhs->e1134 * rhs->e2 
             + lhs->e3 * rhs->e1124 + lhs->e1124 * rhs->e3 + lhs->e4 * rhs->e1123 
             + lhs->e1123 * rhs->e4 + lhs->e11 * rhs->e234 + lhs->e234 * rhs->e11 
             + lhs->e12 * rhs->e134 + lhs->e134 * rhs->e12 + lhs->e13 * rhs->e124 
             + lhs->e124 * rhs->e13 + lhs->e23 * rhs->e114 + lhs->e114 * rhs->e23 
             + lhs->e14 * rhs->e123 + lhs->e123 * rhs->e14 + lhs->e24 * rhs->e113 
             + lhs->e113 * rhs->e24 + lhs->e34 * rhs->e112 + lhs->e112 * rhs->e34;
  res.e12234 = lhs->r * rhs->e12234 + lhs->e12234 * rhs->r + lhs->e1 * rhs->e2234 
             + lhs->e2234 * rhs->e1 + lhs->e2 * rhs->e1234 + lhs->e1234 * rhs->e2 
             + lhs->e3 * rhs->e1224 + lhs->e1224 * rhs->e3 + lhs->e4 * rhs->e1223 
             + lhs->e1223 * rhs->e4 + lhs->e12 * rhs->e234 + lhs->e234 * rhs->e12 
             + lhs->e22 * rhs->e134 + lhs->e134 * rhs->e22 + lhs->e13 * rhs->e224 
             + lhs->e224 * rhs->e13 + lhs->e23 * rhs->e124 + lhs->e124 * rhs->e23 
             + lhs->e14 * rhs->e223 + lhs->e223 * rhs->e14 + lhs->e24 * rhs->e123 
             + lhs->e123 * rhs->e24 + lhs->e34 * rhs->e122 + lhs->e122 * rhs->e34;
  res.e22234 = lhs->r * rhs->e22234 + lhs->e22234 * rhs->r + lhs->e2 * rhs->e2234 
             + lhs->e2234 * rhs->e2 + lhs->e3 * rhs->e2224 + lhs->e2224 * rhs->e3 
             + lhs->e4 * rhs->e2223 + lhs->e2223 * rhs->e4 + lhs->e22 * rhs->e234 
             + lhs->e234 * rhs->e22 + lhs->e23 * rhs->e224 + lhs->e224 * rhs->e23 
             + lhs->e24 * rhs->e223 + lhs->e223 * rhs->e24 + lhs->e34 * rhs->e222 
             + lhs->e222 * rhs->e34;
  res.e11334 = lhs->r * rhs->e11334 + lhs->e11334 * rhs->r + lhs->e1 * rhs->e1334 
             + lhs->e1334 * rhs->e1 + lhs->e3 * rhs->e1134 + lhs->e1134 * rhs->e3 
             + lhs->e4 * rhs->e1133 + lhs->e1133 * rhs->e4 + lhs->e11 * rhs->e334 
             + lhs->e334 * rhs->e11 + lhs->e13 * rhs->e134 + lhs->e134 * rhs->e13 
             + lhs->e33 * rhs->e114 + lhs->e114 * rhs->e33 + lhs->e14 * rhs->e133 
             + lhs->e133 * rhs->e14 + lhs->e34 * rhs->e113 + lhs->e113 * rhs->e34;
  res.e12334 = lhs->r * rhs->e12334 + lhs->e12334 * rhs->r + lhs->e1 * rhs->e2334 
             + lhs->e2334 * rhs->e1 + lhs->e2 * rhs->e1334 + lhs->e1334 * rhs->e2 
             + lhs->e3 * rhs->e1234 + lhs->e1234 * rhs->e3 + lhs->e4 * rhs->e1233 
             + lhs->e1233 * rhs->e4 + lhs->e12 * rhs->e334 + lhs->e334 * rhs->e12 
             + lhs->e13 * rhs->e234 + lhs->e234 * rhs->e13 + lhs->e23 * rhs->e134 
             + lhs->e134 * rhs->e23 + lhs->e33 * rhs->e124 + lhs->e124 * rhs->e33 
             + lhs->e14 * rhs->e233 + lhs->e233 * rhs->e14 + lhs->e24 * rhs->e133 
             + lhs->e133 * rhs->e24 + lhs->e34 * rhs->e123 + lhs->e123 * rhs->e34;
  res.e22334 = lhs->r * rhs->e22334 + lhs->e22334 * rhs->r + lhs->e2 * rhs->e2334 
             + lhs->e2334 * rhs->e2 + lhs->e3 * rhs->e2234 + lhs->e2234 * rhs->e3 
             + lhs->e4 * rhs->e2233 + lhs->e2233 * rhs->e4 + lhs->e22 * rhs->e334 
             + lhs->e334 * rhs->e22 + lhs->e23 * rhs->e234 + lhs->e234 * rhs->e23 
             + lhs->e33 * rhs->e224 + lhs->e224 * rhs->e33 + lhs->e24 * rhs->e233 
             + lhs->e233 * rhs->e24 + lhs->e34 * rhs->e223 + lhs->e223 * rhs->e34;
  res.e13334 = lhs->r * rhs->e13334 + lhs->e13334 * rhs->r + lhs->e1 * rhs->e3334 
             + lhs->e3334 * rhs->e1 + lhs->e3 * rhs->e1334 + lhs->e1334 * rhs->e3 
             + lhs->e4 * rhs->e1333 + lhs->e1333 * rhs->e4 + lhs->e13 * rhs->e334 
             + lhs->e334 * rhs->e13 + lhs->e33 * rhs->e134 + lhs->e134 * rhs->e33 
             + lhs->e14 * rhs->e333 + lhs->e333 * rhs->e14 + lhs->e34 * rhs->e133 
             + lhs->e133 * rhs->e34;
  res.e23334 = lhs->r * rhs->e23334 + lhs->e23334 * rhs->r + lhs->e2 * rhs->e3334 
             + lhs->e3334 * rhs->e2 + lhs->e3 * rhs->e2334 + lhs->e2334 * rhs->e3 
             + lhs->e4 * rhs->e2333 + lhs->e2333 * rhs->e4 + lhs->e23 * rhs->e334 
             + lhs->e334 * rhs->e23 + lhs->e33 * rhs->e234 + lhs->e234 * rhs->e33 
             + lhs->e24 * rhs->e333 + lhs->e333 * rhs->e24 + lhs->e34 * rhs->e233 
             + lhs->e233 * rhs->e34;
  res.e33334 = lhs->r * rhs->e33334 + lhs->e33334 * rhs->r + lhs->e3 * rhs->e3334 
             + lhs->e3334 * rhs->e3 + lhs->e4 * rhs->e3333 + lhs->e3333 * rhs->e4 
             + lhs->e33 * rhs->e334 + lhs->e334 * rhs->e33 + lhs->e34 * rhs->e333 
             + lhs->e333 * rhs->e34;
  res.e11144 = lhs->r * rhs->e11144 + lhs->e11144 * rhs->r + lhs->e1 * rhs->e1144 
             + lhs->e1144 * rhs->e1 + lhs->e4 * rhs->e1114 + lhs->e1114 * rhs->e4 
             + lhs->e11 * rhs->e144 + lhs->e144 * rhs->e11 + lhs->e14 * rhs->e114 
             + lhs->e114 * rhs->e14 + lhs->e44 * rhs->e111 + lhs->e111 * rhs->e44;
  res.e11244 = lhs->r * rhs->e11244 + lhs->e11244 * rhs->r + lhs->e1 * rhs->e1244 
             + lhs->e1244 * rhs->e1 + lhs->e2 * rhs->e1144 + lhs->e1144 * rhs->e2 
             + lhs->e4 * rhs->e1124 + lhs->e1124 * rhs->e4 + lhs->e11 * rhs->e244 
             + lhs->e244 * rhs->e11 + lhs->e12 * rhs->e144 + lhs->e144 * rhs->e12 
             + lhs->e14 * rhs->e124 + lhs->e124 * rhs->e14 + lhs->e24 * rhs->e114 
             + lhs->e114 * rhs->e24 + lhs->e44 * rhs->e112 + lhs->e112 * rhs->e44;
  res.e12244 = lhs->r * rhs->e12244 + lhs->e12244 * rhs->r + lhs->e1 * rhs->e2244 
             + lhs->e2244 * rhs->e1 + lhs->e2 * rhs->e1244 + lhs->e1244 * rhs->e2 
             + lhs->e4 * rhs->e1224 + lhs->e1224 * rhs->e4 + lhs->e12 * rhs->e244 
             + lhs->e244 * rhs->e12 + lhs->e22 * rhs->e144 + lhs->e144 * rhs->e22 
             + lhs->e14 * rhs->e224 + lhs->e224 * rhs->e14 + lhs->e24 * rhs->e124 
             + lhs->e124 * rhs->e24 + lhs->e44 * rhs->e122 + lhs->e122 * rhs->e44;
  res.e22244 = lhs->r * rhs->e22244 + lhs->e22244 * rhs->r + lhs->e2 * rhs->e2244 
             + lhs->e2244 * rhs->e2 + lhs->e4 * rhs->e2224 + lhs->e2224 * rhs->e4 
             + lhs->e22 * rhs->e244 + lhs->e244 * rhs->e22 + lhs->e24 * rhs->e224 
             + lhs->e224 * rhs->e24 + lhs->e44 * rhs->e222 + lhs->e222 * rhs->e44;
  res.e11344 = lhs->r * rhs->e11344 + lhs->e11344 * rhs->r + lhs->e1 * rhs->e1344 
             + lhs->e1344 * rhs->e1 + lhs->e3 * rhs->e1144 + lhs->e1144 * rhs->e3 
             + lhs->e4 * rhs->e1134 + lhs->e1134 * rhs->e4 + lhs->e11 * rhs->e344 
             + lhs->e344 * rhs->e11 + lhs->e13 * rhs->e144 + lhs->e144 * rhs->e13 
             + lhs->e14 * rhs->e134 + lhs->e134 * rhs->e14 + lhs->e34 * rhs->e114 
             + lhs->e114 * rhs->e34 + lhs->e44 * rhs->e113 + lhs->e113 * rhs->e44;
  res.e12344 = lhs->r * rhs->e12344 + lhs->e12344 * rhs->r + lhs->e1 * rhs->e2344 
             + lhs->e2344 * rhs->e1 + lhs->e2 * rhs->e1344 + lhs->e1344 * rhs->e2 
             + lhs->e3 * rhs->e1244 + lhs->e1244 * rhs->e3 + lhs->e4 * rhs->e1234 
             + lhs->e1234 * rhs->e4 + lhs->e12 * rhs->e344 + lhs->e344 * rhs->e12 
             + lhs->e13 * rhs->e244 + lhs->e244 * rhs->e13 + lhs->e23 * rhs->e144 
             + lhs->e144 * rhs->e23 + lhs->e14 * rhs->e234 + lhs->e234 * rhs->e14 
             + lhs->e24 * rhs->e134 + lhs->e134 * rhs->e24 + lhs->e34 * rhs->e124 
             + lhs->e124 * rhs->e34 + lhs->e44 * rhs->e123 + lhs->e123 * rhs->e44;
  res.e22344 = lhs->r * rhs->e22344 + lhs->e22344 * rhs->r + lhs->e2 * rhs->e2344 
             + lhs->e2344 * rhs->e2 + lhs->e3 * rhs->e2244 + lhs->e2244 * rhs->e3 
             + lhs->e4 * rhs->e2234 + lhs->e2234 * rhs->e4 + lhs->e22 * rhs->e344 
             + lhs->e344 * rhs->e22 + lhs->e23 * rhs->e244 + lhs->e244 * rhs->e23 
             + lhs->e24 * rhs->e234 + lhs->e234 * rhs->e24 + lhs->e34 * rhs->e224 
             + lhs->e224 * rhs->e34 + lhs->e44 * rhs->e223 + lhs->e223 * rhs->e44;
  res.e13344 = lhs->r * rhs->e13344 + lhs->e13344 * rhs->r + lhs->e1 * rhs->e3344 
             + lhs->e3344 * rhs->e1 + lhs->e3 * rhs->e1344 + lhs->e1344 * rhs->e3 
             + lhs->e4 * rhs->e1334 + lhs->e1334 * rhs->e4 + lhs->e13 * rhs->e344 
             + lhs->e344 * rhs->e13 + lhs->e33 * rhs->e144 + lhs->e144 * rhs->e33 
             + lhs->e14 * rhs->e334 + lhs->e334 * rhs->e14 + lhs->e34 * rhs->e134 
             + lhs->e134 * rhs->e34 + lhs->e44 * rhs->e133 + lhs->e133 * rhs->e44;
  res.e23344 = lhs->r * rhs->e23344 + lhs->e23344 * rhs->r + lhs->e2 * rhs->e3344 
             + lhs->e3344 * rhs->e2 + lhs->e3 * rhs->e2344 + lhs->e2344 * rhs->e3 
             + lhs->e4 * rhs->e2334 + lhs->e2334 * rhs->e4 + lhs->e23 * rhs->e344 
             + lhs->e344 * rhs->e23 + lhs->e33 * rhs->e244 + lhs->e244 * rhs->e33 
             + lhs->e24 * rhs->e334 + lhs->e334 * rhs->e24 + lhs->e34 * rhs->e234 
             + lhs->e234 * rhs->e34 + lhs->e44 * rhs->e233 + lhs->e233 * rhs->e44;
  res.e33344 = lhs->r * rhs->e33344 + lhs->e33344 * rhs->r + lhs->e3 * rhs->e3344 
             + lhs->e3344 * rhs->e3 + lhs->e4 * rhs->e3334 + lhs->e3334 * rhs->e4 
             + lhs->e33 * rhs->e344 + lhs->e344 * rhs->e33 + lhs->e34 * rhs->e334 
             + lhs->e334 * rhs->e34 + lhs->e44 * rhs->e333 + lhs->e333 * rhs->e44;
  res.e11444 = lhs->r * rhs->e11444 + lhs->e11444 * rhs->r + lhs->e1 * rhs->e1444 
             + lhs->e1444 * rhs->e1 + lhs->e4 * rhs->e1144 + lhs->e1144 * rhs->e4 
             + lhs->e11 * rhs->e444 + lhs->e444 * rhs->e11 + lhs->e14 * rhs->e144 
             + lhs->e144 * rhs->e14 + lhs->e44 * rhs->e114 + lhs->e114 * rhs->e44;
  res.e12444 = lhs->r * rhs->e12444 + lhs->e12444 * rhs->r + lhs->e1 * rhs->e2444 
             + lhs->e2444 * rhs->e1 + lhs->e2 * rhs->e1444 + lhs->e1444 * rhs->e2 
             + lhs->e4 * rhs->e1244 + lhs->e1244 * rhs->e4 + lhs->e12 * rhs->e444 
             + lhs->e444 * rhs->e12 + lhs->e14 * rhs->e244 + lhs->e244 * rhs->e14 
             + lhs->e24 * rhs->e144 + lhs->e144 * rhs->e24 + lhs->e44 * rhs->e124 
             + lhs->e124 * rhs->e44;
  res.e22444 = lhs->r * rhs->e22444 + lhs->e22444 * rhs->r + lhs->e2 * rhs->e2444 
             + lhs->e2444 * rhs->e2 + lhs->e4 * rhs->e2244 + lhs->e2244 * rhs->e4 
             + lhs->e22 * rhs->e444 + lhs->e444 * rhs->e22 + lhs->e24 * rhs->e244 
             + lhs->e244 * rhs->e24 + lhs->e44 * rhs->e224 + lhs->e224 * rhs->e44;
  res.e13444 = lhs->r * rhs->e13444 + lhs->e13444 * rhs->r + lhs->e1 * rhs->e3444 
             + lhs->e3444 * rhs->e1 + lhs->e3 * rhs->e1444 + lhs->e1444 * rhs->e3 
             + lhs->e4 * rhs->e1344 + lhs->e1344 * rhs->e4 + lhs->e13 * rhs->e444 
             + lhs->e444 * rhs->e13 + lhs->e14 * rhs->e344 + lhs->e344 * rhs->e14 
             + lhs->e34 * rhs->e144 + lhs->e144 * rhs->e34 + lhs->e44 * rhs->e134 
             + lhs->e134 * rhs->e44;
  res.e23444 = lhs->r * rhs->e23444 + lhs->e23444 * rhs->r + lhs->e2 * rhs->e3444 
             + lhs->e3444 * rhs->e2 + lhs->e3 * rhs->e2444 + lhs->e2444 * rhs->e3 
             + lhs->e4 * rhs->e2344 + lhs->e2344 * rhs->e4 + lhs->e23 * rhs->e444 
             + lhs->e444 * rhs->e23 + lhs->e24 * rhs->e344 + lhs->e344 * rhs->e24 
             + lhs->e34 * rhs->e244 + lhs->e244 * rhs->e34 + lhs->e44 * rhs->e234 
             + lhs->e234 * rhs->e44;
  res.e33444 = lhs->r * rhs->e33444 + lhs->e33444 * rhs->r + lhs->e3 * rhs->e3444 
             + lhs->e3444 * rhs->e3 + lhs->e4 * rhs->e3344 + lhs->e3344 * rhs->e4 
             + lhs->e33 * rhs->e444 + lhs->e444 * rhs->e33 + lhs->e34 * rhs->e344 
             + lhs->e344 * rhs->e34 + lhs->e44 * rhs->e334 + lhs->e334 * rhs->e44;
  res.e14444 = lhs->r * rhs->e14444 + lhs->e14444 * rhs->r + lhs->e1 * rhs->e4444 
             + lhs->e4444 * rhs->e1 + lhs->e4 * rhs->e1444 + lhs->e1444 * rhs->e4 
             + lhs->e14 * rhs->e444 + lhs->e444 * rhs->e14 + lhs->e44 * rhs->e144 
             + lhs->e144 * rhs->e44;
  res.e24444 = lhs->r * rhs->e24444 + lhs->e24444 * rhs->r + lhs->e2 * rhs->e4444 
             + lhs->e4444 * rhs->e2 + lhs->e4 * rhs->e2444 + lhs->e2444 * rhs->e4 
             + lhs->e24 * rhs->e444 + lhs->e444 * rhs->e24 + lhs->e44 * rhs->e244 
             + lhs->e244 * rhs->e44;
  res.e34444 = lhs->r * rhs->e34444 + lhs->e34444 * rhs->r + lhs->e3 * rhs->e4444 
             + lhs->e4444 * rhs->e3 + lhs->e4 * rhs->e3444 + lhs->e3444 * rhs->e4 
             + lhs->e34 * rhs->e444 + lhs->e444 * rhs->e34 + lhs->e44 * rhs->e344 
             + lhs->e344 * rhs->e44;
  res.e44444 = lhs->r * rhs->e44444 + lhs->e44444 * rhs->r + lhs->e4 * rhs->e4444 
             + lhs->e4444 * rhs->e4 + lhs->e44 * rhs->e444 + lhs->e444 * rhs->e44;

  return res;

}

void onumm4n5_mul_oo_to(  onumm4n5_t* lhs,  onumm4n5_t* rhs, onumm4n5_t* res){
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
  res->e11114 = lhs->r * rhs->e11114 + lhs->e11114 * rhs->r + lhs->e1 * rhs->e1114 
             + lhs->e1114 * rhs->e1 + lhs->e4 * rhs->e1111 + lhs->e1111 * rhs->e4 
             + lhs->e11 * rhs->e114 + lhs->e114 * rhs->e11 + lhs->e14 * rhs->e111 
             + lhs->e111 * rhs->e14;
  res->e11124 = lhs->r * rhs->e11124 + lhs->e11124 * rhs->r + lhs->e1 * rhs->e1124 
             + lhs->e1124 * rhs->e1 + lhs->e2 * rhs->e1114 + lhs->e1114 * rhs->e2 
             + lhs->e4 * rhs->e1112 + lhs->e1112 * rhs->e4 + lhs->e11 * rhs->e124 
             + lhs->e124 * rhs->e11 + lhs->e12 * rhs->e114 + lhs->e114 * rhs->e12 
             + lhs->e14 * rhs->e112 + lhs->e112 * rhs->e14 + lhs->e24 * rhs->e111 
             + lhs->e111 * rhs->e24;
  res->e11224 = lhs->r * rhs->e11224 + lhs->e11224 * rhs->r + lhs->e1 * rhs->e1224 
             + lhs->e1224 * rhs->e1 + lhs->e2 * rhs->e1124 + lhs->e1124 * rhs->e2 
             + lhs->e4 * rhs->e1122 + lhs->e1122 * rhs->e4 + lhs->e11 * rhs->e224 
             + lhs->e224 * rhs->e11 + lhs->e12 * rhs->e124 + lhs->e124 * rhs->e12 
             + lhs->e22 * rhs->e114 + lhs->e114 * rhs->e22 + lhs->e14 * rhs->e122 
             + lhs->e122 * rhs->e14 + lhs->e24 * rhs->e112 + lhs->e112 * rhs->e24;
  res->e12224 = lhs->r * rhs->e12224 + lhs->e12224 * rhs->r + lhs->e1 * rhs->e2224 
             + lhs->e2224 * rhs->e1 + lhs->e2 * rhs->e1224 + lhs->e1224 * rhs->e2 
             + lhs->e4 * rhs->e1222 + lhs->e1222 * rhs->e4 + lhs->e12 * rhs->e224 
             + lhs->e224 * rhs->e12 + lhs->e22 * rhs->e124 + lhs->e124 * rhs->e22 
             + lhs->e14 * rhs->e222 + lhs->e222 * rhs->e14 + lhs->e24 * rhs->e122 
             + lhs->e122 * rhs->e24;
  res->e22224 = lhs->r * rhs->e22224 + lhs->e22224 * rhs->r + lhs->e2 * rhs->e2224 
             + lhs->e2224 * rhs->e2 + lhs->e4 * rhs->e2222 + lhs->e2222 * rhs->e4 
             + lhs->e22 * rhs->e224 + lhs->e224 * rhs->e22 + lhs->e24 * rhs->e222 
             + lhs->e222 * rhs->e24;
  res->e11134 = lhs->r * rhs->e11134 + lhs->e11134 * rhs->r + lhs->e1 * rhs->e1134 
             + lhs->e1134 * rhs->e1 + lhs->e3 * rhs->e1114 + lhs->e1114 * rhs->e3 
             + lhs->e4 * rhs->e1113 + lhs->e1113 * rhs->e4 + lhs->e11 * rhs->e134 
             + lhs->e134 * rhs->e11 + lhs->e13 * rhs->e114 + lhs->e114 * rhs->e13 
             + lhs->e14 * rhs->e113 + lhs->e113 * rhs->e14 + lhs->e34 * rhs->e111 
             + lhs->e111 * rhs->e34;
  res->e11234 = lhs->r * rhs->e11234 + lhs->e11234 * rhs->r + lhs->e1 * rhs->e1234 
             + lhs->e1234 * rhs->e1 + lhs->e2 * rhs->e1134 + lhs->e1134 * rhs->e2 
             + lhs->e3 * rhs->e1124 + lhs->e1124 * rhs->e3 + lhs->e4 * rhs->e1123 
             + lhs->e1123 * rhs->e4 + lhs->e11 * rhs->e234 + lhs->e234 * rhs->e11 
             + lhs->e12 * rhs->e134 + lhs->e134 * rhs->e12 + lhs->e13 * rhs->e124 
             + lhs->e124 * rhs->e13 + lhs->e23 * rhs->e114 + lhs->e114 * rhs->e23 
             + lhs->e14 * rhs->e123 + lhs->e123 * rhs->e14 + lhs->e24 * rhs->e113 
             + lhs->e113 * rhs->e24 + lhs->e34 * rhs->e112 + lhs->e112 * rhs->e34;
  res->e12234 = lhs->r * rhs->e12234 + lhs->e12234 * rhs->r + lhs->e1 * rhs->e2234 
             + lhs->e2234 * rhs->e1 + lhs->e2 * rhs->e1234 + lhs->e1234 * rhs->e2 
             + lhs->e3 * rhs->e1224 + lhs->e1224 * rhs->e3 + lhs->e4 * rhs->e1223 
             + lhs->e1223 * rhs->e4 + lhs->e12 * rhs->e234 + lhs->e234 * rhs->e12 
             + lhs->e22 * rhs->e134 + lhs->e134 * rhs->e22 + lhs->e13 * rhs->e224 
             + lhs->e224 * rhs->e13 + lhs->e23 * rhs->e124 + lhs->e124 * rhs->e23 
             + lhs->e14 * rhs->e223 + lhs->e223 * rhs->e14 + lhs->e24 * rhs->e123 
             + lhs->e123 * rhs->e24 + lhs->e34 * rhs->e122 + lhs->e122 * rhs->e34;
  res->e22234 = lhs->r * rhs->e22234 + lhs->e22234 * rhs->r + lhs->e2 * rhs->e2234 
             + lhs->e2234 * rhs->e2 + lhs->e3 * rhs->e2224 + lhs->e2224 * rhs->e3 
             + lhs->e4 * rhs->e2223 + lhs->e2223 * rhs->e4 + lhs->e22 * rhs->e234 
             + lhs->e234 * rhs->e22 + lhs->e23 * rhs->e224 + lhs->e224 * rhs->e23 
             + lhs->e24 * rhs->e223 + lhs->e223 * rhs->e24 + lhs->e34 * rhs->e222 
             + lhs->e222 * rhs->e34;
  res->e11334 = lhs->r * rhs->e11334 + lhs->e11334 * rhs->r + lhs->e1 * rhs->e1334 
             + lhs->e1334 * rhs->e1 + lhs->e3 * rhs->e1134 + lhs->e1134 * rhs->e3 
             + lhs->e4 * rhs->e1133 + lhs->e1133 * rhs->e4 + lhs->e11 * rhs->e334 
             + lhs->e334 * rhs->e11 + lhs->e13 * rhs->e134 + lhs->e134 * rhs->e13 
             + lhs->e33 * rhs->e114 + lhs->e114 * rhs->e33 + lhs->e14 * rhs->e133 
             + lhs->e133 * rhs->e14 + lhs->e34 * rhs->e113 + lhs->e113 * rhs->e34;
  res->e12334 = lhs->r * rhs->e12334 + lhs->e12334 * rhs->r + lhs->e1 * rhs->e2334 
             + lhs->e2334 * rhs->e1 + lhs->e2 * rhs->e1334 + lhs->e1334 * rhs->e2 
             + lhs->e3 * rhs->e1234 + lhs->e1234 * rhs->e3 + lhs->e4 * rhs->e1233 
             + lhs->e1233 * rhs->e4 + lhs->e12 * rhs->e334 + lhs->e334 * rhs->e12 
             + lhs->e13 * rhs->e234 + lhs->e234 * rhs->e13 + lhs->e23 * rhs->e134 
             + lhs->e134 * rhs->e23 + lhs->e33 * rhs->e124 + lhs->e124 * rhs->e33 
             + lhs->e14 * rhs->e233 + lhs->e233 * rhs->e14 + lhs->e24 * rhs->e133 
             + lhs->e133 * rhs->e24 + lhs->e34 * rhs->e123 + lhs->e123 * rhs->e34;
  res->e22334 = lhs->r * rhs->e22334 + lhs->e22334 * rhs->r + lhs->e2 * rhs->e2334 
             + lhs->e2334 * rhs->e2 + lhs->e3 * rhs->e2234 + lhs->e2234 * rhs->e3 
             + lhs->e4 * rhs->e2233 + lhs->e2233 * rhs->e4 + lhs->e22 * rhs->e334 
             + lhs->e334 * rhs->e22 + lhs->e23 * rhs->e234 + lhs->e234 * rhs->e23 
             + lhs->e33 * rhs->e224 + lhs->e224 * rhs->e33 + lhs->e24 * rhs->e233 
             + lhs->e233 * rhs->e24 + lhs->e34 * rhs->e223 + lhs->e223 * rhs->e34;
  res->e13334 = lhs->r * rhs->e13334 + lhs->e13334 * rhs->r + lhs->e1 * rhs->e3334 
             + lhs->e3334 * rhs->e1 + lhs->e3 * rhs->e1334 + lhs->e1334 * rhs->e3 
             + lhs->e4 * rhs->e1333 + lhs->e1333 * rhs->e4 + lhs->e13 * rhs->e334 
             + lhs->e334 * rhs->e13 + lhs->e33 * rhs->e134 + lhs->e134 * rhs->e33 
             + lhs->e14 * rhs->e333 + lhs->e333 * rhs->e14 + lhs->e34 * rhs->e133 
             + lhs->e133 * rhs->e34;
  res->e23334 = lhs->r * rhs->e23334 + lhs->e23334 * rhs->r + lhs->e2 * rhs->e3334 
             + lhs->e3334 * rhs->e2 + lhs->e3 * rhs->e2334 + lhs->e2334 * rhs->e3 
             + lhs->e4 * rhs->e2333 + lhs->e2333 * rhs->e4 + lhs->e23 * rhs->e334 
             + lhs->e334 * rhs->e23 + lhs->e33 * rhs->e234 + lhs->e234 * rhs->e33 
             + lhs->e24 * rhs->e333 + lhs->e333 * rhs->e24 + lhs->e34 * rhs->e233 
             + lhs->e233 * rhs->e34;
  res->e33334 = lhs->r * rhs->e33334 + lhs->e33334 * rhs->r + lhs->e3 * rhs->e3334 
             + lhs->e3334 * rhs->e3 + lhs->e4 * rhs->e3333 + lhs->e3333 * rhs->e4 
             + lhs->e33 * rhs->e334 + lhs->e334 * rhs->e33 + lhs->e34 * rhs->e333 
             + lhs->e333 * rhs->e34;
  res->e11144 = lhs->r * rhs->e11144 + lhs->e11144 * rhs->r + lhs->e1 * rhs->e1144 
             + lhs->e1144 * rhs->e1 + lhs->e4 * rhs->e1114 + lhs->e1114 * rhs->e4 
             + lhs->e11 * rhs->e144 + lhs->e144 * rhs->e11 + lhs->e14 * rhs->e114 
             + lhs->e114 * rhs->e14 + lhs->e44 * rhs->e111 + lhs->e111 * rhs->e44;
  res->e11244 = lhs->r * rhs->e11244 + lhs->e11244 * rhs->r + lhs->e1 * rhs->e1244 
             + lhs->e1244 * rhs->e1 + lhs->e2 * rhs->e1144 + lhs->e1144 * rhs->e2 
             + lhs->e4 * rhs->e1124 + lhs->e1124 * rhs->e4 + lhs->e11 * rhs->e244 
             + lhs->e244 * rhs->e11 + lhs->e12 * rhs->e144 + lhs->e144 * rhs->e12 
             + lhs->e14 * rhs->e124 + lhs->e124 * rhs->e14 + lhs->e24 * rhs->e114 
             + lhs->e114 * rhs->e24 + lhs->e44 * rhs->e112 + lhs->e112 * rhs->e44;
  res->e12244 = lhs->r * rhs->e12244 + lhs->e12244 * rhs->r + lhs->e1 * rhs->e2244 
             + lhs->e2244 * rhs->e1 + lhs->e2 * rhs->e1244 + lhs->e1244 * rhs->e2 
             + lhs->e4 * rhs->e1224 + lhs->e1224 * rhs->e4 + lhs->e12 * rhs->e244 
             + lhs->e244 * rhs->e12 + lhs->e22 * rhs->e144 + lhs->e144 * rhs->e22 
             + lhs->e14 * rhs->e224 + lhs->e224 * rhs->e14 + lhs->e24 * rhs->e124 
             + lhs->e124 * rhs->e24 + lhs->e44 * rhs->e122 + lhs->e122 * rhs->e44;
  res->e22244 = lhs->r * rhs->e22244 + lhs->e22244 * rhs->r + lhs->e2 * rhs->e2244 
             + lhs->e2244 * rhs->e2 + lhs->e4 * rhs->e2224 + lhs->e2224 * rhs->e4 
             + lhs->e22 * rhs->e244 + lhs->e244 * rhs->e22 + lhs->e24 * rhs->e224 
             + lhs->e224 * rhs->e24 + lhs->e44 * rhs->e222 + lhs->e222 * rhs->e44;
  res->e11344 = lhs->r * rhs->e11344 + lhs->e11344 * rhs->r + lhs->e1 * rhs->e1344 
             + lhs->e1344 * rhs->e1 + lhs->e3 * rhs->e1144 + lhs->e1144 * rhs->e3 
             + lhs->e4 * rhs->e1134 + lhs->e1134 * rhs->e4 + lhs->e11 * rhs->e344 
             + lhs->e344 * rhs->e11 + lhs->e13 * rhs->e144 + lhs->e144 * rhs->e13 
             + lhs->e14 * rhs->e134 + lhs->e134 * rhs->e14 + lhs->e34 * rhs->e114 
             + lhs->e114 * rhs->e34 + lhs->e44 * rhs->e113 + lhs->e113 * rhs->e44;
  res->e12344 = lhs->r * rhs->e12344 + lhs->e12344 * rhs->r + lhs->e1 * rhs->e2344 
             + lhs->e2344 * rhs->e1 + lhs->e2 * rhs->e1344 + lhs->e1344 * rhs->e2 
             + lhs->e3 * rhs->e1244 + lhs->e1244 * rhs->e3 + lhs->e4 * rhs->e1234 
             + lhs->e1234 * rhs->e4 + lhs->e12 * rhs->e344 + lhs->e344 * rhs->e12 
             + lhs->e13 * rhs->e244 + lhs->e244 * rhs->e13 + lhs->e23 * rhs->e144 
             + lhs->e144 * rhs->e23 + lhs->e14 * rhs->e234 + lhs->e234 * rhs->e14 
             + lhs->e24 * rhs->e134 + lhs->e134 * rhs->e24 + lhs->e34 * rhs->e124 
             + lhs->e124 * rhs->e34 + lhs->e44 * rhs->e123 + lhs->e123 * rhs->e44;
  res->e22344 = lhs->r * rhs->e22344 + lhs->e22344 * rhs->r + lhs->e2 * rhs->e2344 
             + lhs->e2344 * rhs->e2 + lhs->e3 * rhs->e2244 + lhs->e2244 * rhs->e3 
             + lhs->e4 * rhs->e2234 + lhs->e2234 * rhs->e4 + lhs->e22 * rhs->e344 
             + lhs->e344 * rhs->e22 + lhs->e23 * rhs->e244 + lhs->e244 * rhs->e23 
             + lhs->e24 * rhs->e234 + lhs->e234 * rhs->e24 + lhs->e34 * rhs->e224 
             + lhs->e224 * rhs->e34 + lhs->e44 * rhs->e223 + lhs->e223 * rhs->e44;
  res->e13344 = lhs->r * rhs->e13344 + lhs->e13344 * rhs->r + lhs->e1 * rhs->e3344 
             + lhs->e3344 * rhs->e1 + lhs->e3 * rhs->e1344 + lhs->e1344 * rhs->e3 
             + lhs->e4 * rhs->e1334 + lhs->e1334 * rhs->e4 + lhs->e13 * rhs->e344 
             + lhs->e344 * rhs->e13 + lhs->e33 * rhs->e144 + lhs->e144 * rhs->e33 
             + lhs->e14 * rhs->e334 + lhs->e334 * rhs->e14 + lhs->e34 * rhs->e134 
             + lhs->e134 * rhs->e34 + lhs->e44 * rhs->e133 + lhs->e133 * rhs->e44;
  res->e23344 = lhs->r * rhs->e23344 + lhs->e23344 * rhs->r + lhs->e2 * rhs->e3344 
             + lhs->e3344 * rhs->e2 + lhs->e3 * rhs->e2344 + lhs->e2344 * rhs->e3 
             + lhs->e4 * rhs->e2334 + lhs->e2334 * rhs->e4 + lhs->e23 * rhs->e344 
             + lhs->e344 * rhs->e23 + lhs->e33 * rhs->e244 + lhs->e244 * rhs->e33 
             + lhs->e24 * rhs->e334 + lhs->e334 * rhs->e24 + lhs->e34 * rhs->e234 
             + lhs->e234 * rhs->e34 + lhs->e44 * rhs->e233 + lhs->e233 * rhs->e44;
  res->e33344 = lhs->r * rhs->e33344 + lhs->e33344 * rhs->r + lhs->e3 * rhs->e3344 
             + lhs->e3344 * rhs->e3 + lhs->e4 * rhs->e3334 + lhs->e3334 * rhs->e4 
             + lhs->e33 * rhs->e344 + lhs->e344 * rhs->e33 + lhs->e34 * rhs->e334 
             + lhs->e334 * rhs->e34 + lhs->e44 * rhs->e333 + lhs->e333 * rhs->e44;
  res->e11444 = lhs->r * rhs->e11444 + lhs->e11444 * rhs->r + lhs->e1 * rhs->e1444 
             + lhs->e1444 * rhs->e1 + lhs->e4 * rhs->e1144 + lhs->e1144 * rhs->e4 
             + lhs->e11 * rhs->e444 + lhs->e444 * rhs->e11 + lhs->e14 * rhs->e144 
             + lhs->e144 * rhs->e14 + lhs->e44 * rhs->e114 + lhs->e114 * rhs->e44;
  res->e12444 = lhs->r * rhs->e12444 + lhs->e12444 * rhs->r + lhs->e1 * rhs->e2444 
             + lhs->e2444 * rhs->e1 + lhs->e2 * rhs->e1444 + lhs->e1444 * rhs->e2 
             + lhs->e4 * rhs->e1244 + lhs->e1244 * rhs->e4 + lhs->e12 * rhs->e444 
             + lhs->e444 * rhs->e12 + lhs->e14 * rhs->e244 + lhs->e244 * rhs->e14 
             + lhs->e24 * rhs->e144 + lhs->e144 * rhs->e24 + lhs->e44 * rhs->e124 
             + lhs->e124 * rhs->e44;
  res->e22444 = lhs->r * rhs->e22444 + lhs->e22444 * rhs->r + lhs->e2 * rhs->e2444 
             + lhs->e2444 * rhs->e2 + lhs->e4 * rhs->e2244 + lhs->e2244 * rhs->e4 
             + lhs->e22 * rhs->e444 + lhs->e444 * rhs->e22 + lhs->e24 * rhs->e244 
             + lhs->e244 * rhs->e24 + lhs->e44 * rhs->e224 + lhs->e224 * rhs->e44;
  res->e13444 = lhs->r * rhs->e13444 + lhs->e13444 * rhs->r + lhs->e1 * rhs->e3444 
             + lhs->e3444 * rhs->e1 + lhs->e3 * rhs->e1444 + lhs->e1444 * rhs->e3 
             + lhs->e4 * rhs->e1344 + lhs->e1344 * rhs->e4 + lhs->e13 * rhs->e444 
             + lhs->e444 * rhs->e13 + lhs->e14 * rhs->e344 + lhs->e344 * rhs->e14 
             + lhs->e34 * rhs->e144 + lhs->e144 * rhs->e34 + lhs->e44 * rhs->e134 
             + lhs->e134 * rhs->e44;
  res->e23444 = lhs->r * rhs->e23444 + lhs->e23444 * rhs->r + lhs->e2 * rhs->e3444 
             + lhs->e3444 * rhs->e2 + lhs->e3 * rhs->e2444 + lhs->e2444 * rhs->e3 
             + lhs->e4 * rhs->e2344 + lhs->e2344 * rhs->e4 + lhs->e23 * rhs->e444 
             + lhs->e444 * rhs->e23 + lhs->e24 * rhs->e344 + lhs->e344 * rhs->e24 
             + lhs->e34 * rhs->e244 + lhs->e244 * rhs->e34 + lhs->e44 * rhs->e234 
             + lhs->e234 * rhs->e44;
  res->e33444 = lhs->r * rhs->e33444 + lhs->e33444 * rhs->r + lhs->e3 * rhs->e3444 
             + lhs->e3444 * rhs->e3 + lhs->e4 * rhs->e3344 + lhs->e3344 * rhs->e4 
             + lhs->e33 * rhs->e444 + lhs->e444 * rhs->e33 + lhs->e34 * rhs->e344 
             + lhs->e344 * rhs->e34 + lhs->e44 * rhs->e334 + lhs->e334 * rhs->e44;
  res->e14444 = lhs->r * rhs->e14444 + lhs->e14444 * rhs->r + lhs->e1 * rhs->e4444 
             + lhs->e4444 * rhs->e1 + lhs->e4 * rhs->e1444 + lhs->e1444 * rhs->e4 
             + lhs->e14 * rhs->e444 + lhs->e444 * rhs->e14 + lhs->e44 * rhs->e144 
             + lhs->e144 * rhs->e44;
  res->e24444 = lhs->r * rhs->e24444 + lhs->e24444 * rhs->r + lhs->e2 * rhs->e4444 
             + lhs->e4444 * rhs->e2 + lhs->e4 * rhs->e2444 + lhs->e2444 * rhs->e4 
             + lhs->e24 * rhs->e444 + lhs->e444 * rhs->e24 + lhs->e44 * rhs->e244 
             + lhs->e244 * rhs->e44;
  res->e34444 = lhs->r * rhs->e34444 + lhs->e34444 * rhs->r + lhs->e3 * rhs->e4444 
             + lhs->e4444 * rhs->e3 + lhs->e4 * rhs->e3444 + lhs->e3444 * rhs->e4 
             + lhs->e34 * rhs->e444 + lhs->e444 * rhs->e34 + lhs->e44 * rhs->e344 
             + lhs->e344 * rhs->e44;
  res->e44444 = lhs->r * rhs->e44444 + lhs->e44444 * rhs->r + lhs->e4 * rhs->e4444 
             + lhs->e4444 * rhs->e4 + lhs->e44 * rhs->e444 + lhs->e444 * rhs->e44;

}

onumm4n5_t onumm4n5_mul_ro(  coeff_t lhs,  onumm4n5_t* rhs){
  onumm4n5_t res;

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
  res.e11114 = lhs * rhs->e11114;
  res.e11124 = lhs * rhs->e11124;
  res.e11224 = lhs * rhs->e11224;
  res.e12224 = lhs * rhs->e12224;
  res.e22224 = lhs * rhs->e22224;
  res.e11134 = lhs * rhs->e11134;
  res.e11234 = lhs * rhs->e11234;
  res.e12234 = lhs * rhs->e12234;
  res.e22234 = lhs * rhs->e22234;
  res.e11334 = lhs * rhs->e11334;
  res.e12334 = lhs * rhs->e12334;
  res.e22334 = lhs * rhs->e22334;
  res.e13334 = lhs * rhs->e13334;
  res.e23334 = lhs * rhs->e23334;
  res.e33334 = lhs * rhs->e33334;
  res.e11144 = lhs * rhs->e11144;
  res.e11244 = lhs * rhs->e11244;
  res.e12244 = lhs * rhs->e12244;
  res.e22244 = lhs * rhs->e22244;
  res.e11344 = lhs * rhs->e11344;
  res.e12344 = lhs * rhs->e12344;
  res.e22344 = lhs * rhs->e22344;
  res.e13344 = lhs * rhs->e13344;
  res.e23344 = lhs * rhs->e23344;
  res.e33344 = lhs * rhs->e33344;
  res.e11444 = lhs * rhs->e11444;
  res.e12444 = lhs * rhs->e12444;
  res.e22444 = lhs * rhs->e22444;
  res.e13444 = lhs * rhs->e13444;
  res.e23444 = lhs * rhs->e23444;
  res.e33444 = lhs * rhs->e33444;
  res.e14444 = lhs * rhs->e14444;
  res.e24444 = lhs * rhs->e24444;
  res.e34444 = lhs * rhs->e34444;
  res.e44444 = lhs * rhs->e44444;

  return res;

}

void onumm4n5_mul_ro_to(  coeff_t lhs,  onumm4n5_t* rhs, onumm4n5_t* res){
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
  res->e11114 = lhs * rhs->e11114;
  res->e11124 = lhs * rhs->e11124;
  res->e11224 = lhs * rhs->e11224;
  res->e12224 = lhs * rhs->e12224;
  res->e22224 = lhs * rhs->e22224;
  res->e11134 = lhs * rhs->e11134;
  res->e11234 = lhs * rhs->e11234;
  res->e12234 = lhs * rhs->e12234;
  res->e22234 = lhs * rhs->e22234;
  res->e11334 = lhs * rhs->e11334;
  res->e12334 = lhs * rhs->e12334;
  res->e22334 = lhs * rhs->e22334;
  res->e13334 = lhs * rhs->e13334;
  res->e23334 = lhs * rhs->e23334;
  res->e33334 = lhs * rhs->e33334;
  res->e11144 = lhs * rhs->e11144;
  res->e11244 = lhs * rhs->e11244;
  res->e12244 = lhs * rhs->e12244;
  res->e22244 = lhs * rhs->e22244;
  res->e11344 = lhs * rhs->e11344;
  res->e12344 = lhs * rhs->e12344;
  res->e22344 = lhs * rhs->e22344;
  res->e13344 = lhs * rhs->e13344;
  res->e23344 = lhs * rhs->e23344;
  res->e33344 = lhs * rhs->e33344;
  res->e11444 = lhs * rhs->e11444;
  res->e12444 = lhs * rhs->e12444;
  res->e22444 = lhs * rhs->e22444;
  res->e13444 = lhs * rhs->e13444;
  res->e23444 = lhs * rhs->e23444;
  res->e33444 = lhs * rhs->e33444;
  res->e14444 = lhs * rhs->e14444;
  res->e24444 = lhs * rhs->e24444;
  res->e34444 = lhs * rhs->e34444;
  res->e44444 = lhs * rhs->e44444;

}

onumm4n5_t onumm4n5_trunc_mul_oo(  onumm4n5_t* lhs,  onumm4n5_t* rhs){
  onumm4n5_t res;

  res = onumm4n5_init();

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
  res.e11114 =  + lhs->e1 * rhs->e1114 + lhs->e1114 * rhs->e1 + lhs->e4 * rhs->e1111 
             + lhs->e1111 * rhs->e4 + lhs->e11 * rhs->e114 + lhs->e114 * rhs->e11 
             + lhs->e14 * rhs->e111 + lhs->e111 * rhs->e14;
  res.e11124 =  + lhs->e1 * rhs->e1124 + lhs->e1124 * rhs->e1 + lhs->e2 * rhs->e1114 
             + lhs->e1114 * rhs->e2 + lhs->e4 * rhs->e1112 + lhs->e1112 * rhs->e4 
             + lhs->e11 * rhs->e124 + lhs->e124 * rhs->e11 + lhs->e12 * rhs->e114 
             + lhs->e114 * rhs->e12 + lhs->e14 * rhs->e112 + lhs->e112 * rhs->e14 
             + lhs->e24 * rhs->e111 + lhs->e111 * rhs->e24;
  res.e11224 =  + lhs->e1 * rhs->e1224 + lhs->e1224 * rhs->e1 + lhs->e2 * rhs->e1124 
             + lhs->e1124 * rhs->e2 + lhs->e4 * rhs->e1122 + lhs->e1122 * rhs->e4 
             + lhs->e11 * rhs->e224 + lhs->e224 * rhs->e11 + lhs->e12 * rhs->e124 
             + lhs->e124 * rhs->e12 + lhs->e22 * rhs->e114 + lhs->e114 * rhs->e22 
             + lhs->e14 * rhs->e122 + lhs->e122 * rhs->e14 + lhs->e24 * rhs->e112 
             + lhs->e112 * rhs->e24;
  res.e12224 =  + lhs->e1 * rhs->e2224 + lhs->e2224 * rhs->e1 + lhs->e2 * rhs->e1224 
             + lhs->e1224 * rhs->e2 + lhs->e4 * rhs->e1222 + lhs->e1222 * rhs->e4 
             + lhs->e12 * rhs->e224 + lhs->e224 * rhs->e12 + lhs->e22 * rhs->e124 
             + lhs->e124 * rhs->e22 + lhs->e14 * rhs->e222 + lhs->e222 * rhs->e14 
             + lhs->e24 * rhs->e122 + lhs->e122 * rhs->e24;
  res.e22224 =  + lhs->e2 * rhs->e2224 + lhs->e2224 * rhs->e2 + lhs->e4 * rhs->e2222 
             + lhs->e2222 * rhs->e4 + lhs->e22 * rhs->e224 + lhs->e224 * rhs->e22 
             + lhs->e24 * rhs->e222 + lhs->e222 * rhs->e24;
  res.e11134 =  + lhs->e1 * rhs->e1134 + lhs->e1134 * rhs->e1 + lhs->e3 * rhs->e1114 
             + lhs->e1114 * rhs->e3 + lhs->e4 * rhs->e1113 + lhs->e1113 * rhs->e4 
             + lhs->e11 * rhs->e134 + lhs->e134 * rhs->e11 + lhs->e13 * rhs->e114 
             + lhs->e114 * rhs->e13 + lhs->e14 * rhs->e113 + lhs->e113 * rhs->e14 
             + lhs->e34 * rhs->e111 + lhs->e111 * rhs->e34;
  res.e11234 =  + lhs->e1 * rhs->e1234 + lhs->e1234 * rhs->e1 + lhs->e2 * rhs->e1134 
             + lhs->e1134 * rhs->e2 + lhs->e3 * rhs->e1124 + lhs->e1124 * rhs->e3 
             + lhs->e4 * rhs->e1123 + lhs->e1123 * rhs->e4 + lhs->e11 * rhs->e234 
             + lhs->e234 * rhs->e11 + lhs->e12 * rhs->e134 + lhs->e134 * rhs->e12 
             + lhs->e13 * rhs->e124 + lhs->e124 * rhs->e13 + lhs->e23 * rhs->e114 
             + lhs->e114 * rhs->e23 + lhs->e14 * rhs->e123 + lhs->e123 * rhs->e14 
             + lhs->e24 * rhs->e113 + lhs->e113 * rhs->e24 + lhs->e34 * rhs->e112 
             + lhs->e112 * rhs->e34;
  res.e12234 =  + lhs->e1 * rhs->e2234 + lhs->e2234 * rhs->e1 + lhs->e2 * rhs->e1234 
             + lhs->e1234 * rhs->e2 + lhs->e3 * rhs->e1224 + lhs->e1224 * rhs->e3 
             + lhs->e4 * rhs->e1223 + lhs->e1223 * rhs->e4 + lhs->e12 * rhs->e234 
             + lhs->e234 * rhs->e12 + lhs->e22 * rhs->e134 + lhs->e134 * rhs->e22 
             + lhs->e13 * rhs->e224 + lhs->e224 * rhs->e13 + lhs->e23 * rhs->e124 
             + lhs->e124 * rhs->e23 + lhs->e14 * rhs->e223 + lhs->e223 * rhs->e14 
             + lhs->e24 * rhs->e123 + lhs->e123 * rhs->e24 + lhs->e34 * rhs->e122 
             + lhs->e122 * rhs->e34;
  res.e22234 =  + lhs->e2 * rhs->e2234 + lhs->e2234 * rhs->e2 + lhs->e3 * rhs->e2224 
             + lhs->e2224 * rhs->e3 + lhs->e4 * rhs->e2223 + lhs->e2223 * rhs->e4 
             + lhs->e22 * rhs->e234 + lhs->e234 * rhs->e22 + lhs->e23 * rhs->e224 
             + lhs->e224 * rhs->e23 + lhs->e24 * rhs->e223 + lhs->e223 * rhs->e24 
             + lhs->e34 * rhs->e222 + lhs->e222 * rhs->e34;
  res.e11334 =  + lhs->e1 * rhs->e1334 + lhs->e1334 * rhs->e1 + lhs->e3 * rhs->e1134 
             + lhs->e1134 * rhs->e3 + lhs->e4 * rhs->e1133 + lhs->e1133 * rhs->e4 
             + lhs->e11 * rhs->e334 + lhs->e334 * rhs->e11 + lhs->e13 * rhs->e134 
             + lhs->e134 * rhs->e13 + lhs->e33 * rhs->e114 + lhs->e114 * rhs->e33 
             + lhs->e14 * rhs->e133 + lhs->e133 * rhs->e14 + lhs->e34 * rhs->e113 
             + lhs->e113 * rhs->e34;
  res.e12334 =  + lhs->e1 * rhs->e2334 + lhs->e2334 * rhs->e1 + lhs->e2 * rhs->e1334 
             + lhs->e1334 * rhs->e2 + lhs->e3 * rhs->e1234 + lhs->e1234 * rhs->e3 
             + lhs->e4 * rhs->e1233 + lhs->e1233 * rhs->e4 + lhs->e12 * rhs->e334 
             + lhs->e334 * rhs->e12 + lhs->e13 * rhs->e234 + lhs->e234 * rhs->e13 
             + lhs->e23 * rhs->e134 + lhs->e134 * rhs->e23 + lhs->e33 * rhs->e124 
             + lhs->e124 * rhs->e33 + lhs->e14 * rhs->e233 + lhs->e233 * rhs->e14 
             + lhs->e24 * rhs->e133 + lhs->e133 * rhs->e24 + lhs->e34 * rhs->e123 
             + lhs->e123 * rhs->e34;
  res.e22334 =  + lhs->e2 * rhs->e2334 + lhs->e2334 * rhs->e2 + lhs->e3 * rhs->e2234 
             + lhs->e2234 * rhs->e3 + lhs->e4 * rhs->e2233 + lhs->e2233 * rhs->e4 
             + lhs->e22 * rhs->e334 + lhs->e334 * rhs->e22 + lhs->e23 * rhs->e234 
             + lhs->e234 * rhs->e23 + lhs->e33 * rhs->e224 + lhs->e224 * rhs->e33 
             + lhs->e24 * rhs->e233 + lhs->e233 * rhs->e24 + lhs->e34 * rhs->e223 
             + lhs->e223 * rhs->e34;
  res.e13334 =  + lhs->e1 * rhs->e3334 + lhs->e3334 * rhs->e1 + lhs->e3 * rhs->e1334 
             + lhs->e1334 * rhs->e3 + lhs->e4 * rhs->e1333 + lhs->e1333 * rhs->e4 
             + lhs->e13 * rhs->e334 + lhs->e334 * rhs->e13 + lhs->e33 * rhs->e134 
             + lhs->e134 * rhs->e33 + lhs->e14 * rhs->e333 + lhs->e333 * rhs->e14 
             + lhs->e34 * rhs->e133 + lhs->e133 * rhs->e34;
  res.e23334 =  + lhs->e2 * rhs->e3334 + lhs->e3334 * rhs->e2 + lhs->e3 * rhs->e2334 
             + lhs->e2334 * rhs->e3 + lhs->e4 * rhs->e2333 + lhs->e2333 * rhs->e4 
             + lhs->e23 * rhs->e334 + lhs->e334 * rhs->e23 + lhs->e33 * rhs->e234 
             + lhs->e234 * rhs->e33 + lhs->e24 * rhs->e333 + lhs->e333 * rhs->e24 
             + lhs->e34 * rhs->e233 + lhs->e233 * rhs->e34;
  res.e33334 =  + lhs->e3 * rhs->e3334 + lhs->e3334 * rhs->e3 + lhs->e4 * rhs->e3333 
             + lhs->e3333 * rhs->e4 + lhs->e33 * rhs->e334 + lhs->e334 * rhs->e33 
             + lhs->e34 * rhs->e333 + lhs->e333 * rhs->e34;
  res.e11144 =  + lhs->e1 * rhs->e1144 + lhs->e1144 * rhs->e1 + lhs->e4 * rhs->e1114 
             + lhs->e1114 * rhs->e4 + lhs->e11 * rhs->e144 + lhs->e144 * rhs->e11 
             + lhs->e14 * rhs->e114 + lhs->e114 * rhs->e14 + lhs->e44 * rhs->e111 
             + lhs->e111 * rhs->e44;
  res.e11244 =  + lhs->e1 * rhs->e1244 + lhs->e1244 * rhs->e1 + lhs->e2 * rhs->e1144 
             + lhs->e1144 * rhs->e2 + lhs->e4 * rhs->e1124 + lhs->e1124 * rhs->e4 
             + lhs->e11 * rhs->e244 + lhs->e244 * rhs->e11 + lhs->e12 * rhs->e144 
             + lhs->e144 * rhs->e12 + lhs->e14 * rhs->e124 + lhs->e124 * rhs->e14 
             + lhs->e24 * rhs->e114 + lhs->e114 * rhs->e24 + lhs->e44 * rhs->e112 
             + lhs->e112 * rhs->e44;
  res.e12244 =  + lhs->e1 * rhs->e2244 + lhs->e2244 * rhs->e1 + lhs->e2 * rhs->e1244 
             + lhs->e1244 * rhs->e2 + lhs->e4 * rhs->e1224 + lhs->e1224 * rhs->e4 
             + lhs->e12 * rhs->e244 + lhs->e244 * rhs->e12 + lhs->e22 * rhs->e144 
             + lhs->e144 * rhs->e22 + lhs->e14 * rhs->e224 + lhs->e224 * rhs->e14 
             + lhs->e24 * rhs->e124 + lhs->e124 * rhs->e24 + lhs->e44 * rhs->e122 
             + lhs->e122 * rhs->e44;
  res.e22244 =  + lhs->e2 * rhs->e2244 + lhs->e2244 * rhs->e2 + lhs->e4 * rhs->e2224 
             + lhs->e2224 * rhs->e4 + lhs->e22 * rhs->e244 + lhs->e244 * rhs->e22 
             + lhs->e24 * rhs->e224 + lhs->e224 * rhs->e24 + lhs->e44 * rhs->e222 
             + lhs->e222 * rhs->e44;
  res.e11344 =  + lhs->e1 * rhs->e1344 + lhs->e1344 * rhs->e1 + lhs->e3 * rhs->e1144 
             + lhs->e1144 * rhs->e3 + lhs->e4 * rhs->e1134 + lhs->e1134 * rhs->e4 
             + lhs->e11 * rhs->e344 + lhs->e344 * rhs->e11 + lhs->e13 * rhs->e144 
             + lhs->e144 * rhs->e13 + lhs->e14 * rhs->e134 + lhs->e134 * rhs->e14 
             + lhs->e34 * rhs->e114 + lhs->e114 * rhs->e34 + lhs->e44 * rhs->e113 
             + lhs->e113 * rhs->e44;
  res.e12344 =  + lhs->e1 * rhs->e2344 + lhs->e2344 * rhs->e1 + lhs->e2 * rhs->e1344 
             + lhs->e1344 * rhs->e2 + lhs->e3 * rhs->e1244 + lhs->e1244 * rhs->e3 
             + lhs->e4 * rhs->e1234 + lhs->e1234 * rhs->e4 + lhs->e12 * rhs->e344 
             + lhs->e344 * rhs->e12 + lhs->e13 * rhs->e244 + lhs->e244 * rhs->e13 
             + lhs->e23 * rhs->e144 + lhs->e144 * rhs->e23 + lhs->e14 * rhs->e234 
             + lhs->e234 * rhs->e14 + lhs->e24 * rhs->e134 + lhs->e134 * rhs->e24 
             + lhs->e34 * rhs->e124 + lhs->e124 * rhs->e34 + lhs->e44 * rhs->e123 
             + lhs->e123 * rhs->e44;
  res.e22344 =  + lhs->e2 * rhs->e2344 + lhs->e2344 * rhs->e2 + lhs->e3 * rhs->e2244 
             + lhs->e2244 * rhs->e3 + lhs->e4 * rhs->e2234 + lhs->e2234 * rhs->e4 
             + lhs->e22 * rhs->e344 + lhs->e344 * rhs->e22 + lhs->e23 * rhs->e244 
             + lhs->e244 * rhs->e23 + lhs->e24 * rhs->e234 + lhs->e234 * rhs->e24 
             + lhs->e34 * rhs->e224 + lhs->e224 * rhs->e34 + lhs->e44 * rhs->e223 
             + lhs->e223 * rhs->e44;
  res.e13344 =  + lhs->e1 * rhs->e3344 + lhs->e3344 * rhs->e1 + lhs->e3 * rhs->e1344 
             + lhs->e1344 * rhs->e3 + lhs->e4 * rhs->e1334 + lhs->e1334 * rhs->e4 
             + lhs->e13 * rhs->e344 + lhs->e344 * rhs->e13 + lhs->e33 * rhs->e144 
             + lhs->e144 * rhs->e33 + lhs->e14 * rhs->e334 + lhs->e334 * rhs->e14 
             + lhs->e34 * rhs->e134 + lhs->e134 * rhs->e34 + lhs->e44 * rhs->e133 
             + lhs->e133 * rhs->e44;
  res.e23344 =  + lhs->e2 * rhs->e3344 + lhs->e3344 * rhs->e2 + lhs->e3 * rhs->e2344 
             + lhs->e2344 * rhs->e3 + lhs->e4 * rhs->e2334 + lhs->e2334 * rhs->e4 
             + lhs->e23 * rhs->e344 + lhs->e344 * rhs->e23 + lhs->e33 * rhs->e244 
             + lhs->e244 * rhs->e33 + lhs->e24 * rhs->e334 + lhs->e334 * rhs->e24 
             + lhs->e34 * rhs->e234 + lhs->e234 * rhs->e34 + lhs->e44 * rhs->e233 
             + lhs->e233 * rhs->e44;
  res.e33344 =  + lhs->e3 * rhs->e3344 + lhs->e3344 * rhs->e3 + lhs->e4 * rhs->e3334 
             + lhs->e3334 * rhs->e4 + lhs->e33 * rhs->e344 + lhs->e344 * rhs->e33 
             + lhs->e34 * rhs->e334 + lhs->e334 * rhs->e34 + lhs->e44 * rhs->e333 
             + lhs->e333 * rhs->e44;
  res.e11444 =  + lhs->e1 * rhs->e1444 + lhs->e1444 * rhs->e1 + lhs->e4 * rhs->e1144 
             + lhs->e1144 * rhs->e4 + lhs->e11 * rhs->e444 + lhs->e444 * rhs->e11 
             + lhs->e14 * rhs->e144 + lhs->e144 * rhs->e14 + lhs->e44 * rhs->e114 
             + lhs->e114 * rhs->e44;
  res.e12444 =  + lhs->e1 * rhs->e2444 + lhs->e2444 * rhs->e1 + lhs->e2 * rhs->e1444 
             + lhs->e1444 * rhs->e2 + lhs->e4 * rhs->e1244 + lhs->e1244 * rhs->e4 
             + lhs->e12 * rhs->e444 + lhs->e444 * rhs->e12 + lhs->e14 * rhs->e244 
             + lhs->e244 * rhs->e14 + lhs->e24 * rhs->e144 + lhs->e144 * rhs->e24 
             + lhs->e44 * rhs->e124 + lhs->e124 * rhs->e44;
  res.e22444 =  + lhs->e2 * rhs->e2444 + lhs->e2444 * rhs->e2 + lhs->e4 * rhs->e2244 
             + lhs->e2244 * rhs->e4 + lhs->e22 * rhs->e444 + lhs->e444 * rhs->e22 
             + lhs->e24 * rhs->e244 + lhs->e244 * rhs->e24 + lhs->e44 * rhs->e224 
             + lhs->e224 * rhs->e44;
  res.e13444 =  + lhs->e1 * rhs->e3444 + lhs->e3444 * rhs->e1 + lhs->e3 * rhs->e1444 
             + lhs->e1444 * rhs->e3 + lhs->e4 * rhs->e1344 + lhs->e1344 * rhs->e4 
             + lhs->e13 * rhs->e444 + lhs->e444 * rhs->e13 + lhs->e14 * rhs->e344 
             + lhs->e344 * rhs->e14 + lhs->e34 * rhs->e144 + lhs->e144 * rhs->e34 
             + lhs->e44 * rhs->e134 + lhs->e134 * rhs->e44;
  res.e23444 =  + lhs->e2 * rhs->e3444 + lhs->e3444 * rhs->e2 + lhs->e3 * rhs->e2444 
             + lhs->e2444 * rhs->e3 + lhs->e4 * rhs->e2344 + lhs->e2344 * rhs->e4 
             + lhs->e23 * rhs->e444 + lhs->e444 * rhs->e23 + lhs->e24 * rhs->e344 
             + lhs->e344 * rhs->e24 + lhs->e34 * rhs->e244 + lhs->e244 * rhs->e34 
             + lhs->e44 * rhs->e234 + lhs->e234 * rhs->e44;
  res.e33444 =  + lhs->e3 * rhs->e3444 + lhs->e3444 * rhs->e3 + lhs->e4 * rhs->e3344 
             + lhs->e3344 * rhs->e4 + lhs->e33 * rhs->e444 + lhs->e444 * rhs->e33 
             + lhs->e34 * rhs->e344 + lhs->e344 * rhs->e34 + lhs->e44 * rhs->e334 
             + lhs->e334 * rhs->e44;
  res.e14444 =  + lhs->e1 * rhs->e4444 + lhs->e4444 * rhs->e1 + lhs->e4 * rhs->e1444 
             + lhs->e1444 * rhs->e4 + lhs->e14 * rhs->e444 + lhs->e444 * rhs->e14 
             + lhs->e44 * rhs->e144 + lhs->e144 * rhs->e44;
  res.e24444 =  + lhs->e2 * rhs->e4444 + lhs->e4444 * rhs->e2 + lhs->e4 * rhs->e2444 
             + lhs->e2444 * rhs->e4 + lhs->e24 * rhs->e444 + lhs->e444 * rhs->e24 
             + lhs->e44 * rhs->e244 + lhs->e244 * rhs->e44;
  res.e34444 =  + lhs->e3 * rhs->e4444 + lhs->e4444 * rhs->e3 + lhs->e4 * rhs->e3444 
             + lhs->e3444 * rhs->e4 + lhs->e34 * rhs->e444 + lhs->e444 * rhs->e34 
             + lhs->e44 * rhs->e344 + lhs->e344 * rhs->e44;
  res.e44444 =  + lhs->e4 * rhs->e4444 + lhs->e4444 * rhs->e4 + lhs->e44 * rhs->e444 
             + lhs->e444 * rhs->e44;

  return res;

}

void onumm4n5_trunc_mul_oo_to(  onumm4n5_t* lhs,  onumm4n5_t* rhs, onumm4n5_t* res){
   (*res) = onumm4n5_init();

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
  res->e11114 =  + lhs->e1 * rhs->e1114 + lhs->e1114 * rhs->e1 + lhs->e4 * rhs->e1111 
             + lhs->e1111 * rhs->e4 + lhs->e11 * rhs->e114 + lhs->e114 * rhs->e11 
             + lhs->e14 * rhs->e111 + lhs->e111 * rhs->e14;
  res->e11124 =  + lhs->e1 * rhs->e1124 + lhs->e1124 * rhs->e1 + lhs->e2 * rhs->e1114 
             + lhs->e1114 * rhs->e2 + lhs->e4 * rhs->e1112 + lhs->e1112 * rhs->e4 
             + lhs->e11 * rhs->e124 + lhs->e124 * rhs->e11 + lhs->e12 * rhs->e114 
             + lhs->e114 * rhs->e12 + lhs->e14 * rhs->e112 + lhs->e112 * rhs->e14 
             + lhs->e24 * rhs->e111 + lhs->e111 * rhs->e24;
  res->e11224 =  + lhs->e1 * rhs->e1224 + lhs->e1224 * rhs->e1 + lhs->e2 * rhs->e1124 
             + lhs->e1124 * rhs->e2 + lhs->e4 * rhs->e1122 + lhs->e1122 * rhs->e4 
             + lhs->e11 * rhs->e224 + lhs->e224 * rhs->e11 + lhs->e12 * rhs->e124 
             + lhs->e124 * rhs->e12 + lhs->e22 * rhs->e114 + lhs->e114 * rhs->e22 
             + lhs->e14 * rhs->e122 + lhs->e122 * rhs->e14 + lhs->e24 * rhs->e112 
             + lhs->e112 * rhs->e24;
  res->e12224 =  + lhs->e1 * rhs->e2224 + lhs->e2224 * rhs->e1 + lhs->e2 * rhs->e1224 
             + lhs->e1224 * rhs->e2 + lhs->e4 * rhs->e1222 + lhs->e1222 * rhs->e4 
             + lhs->e12 * rhs->e224 + lhs->e224 * rhs->e12 + lhs->e22 * rhs->e124 
             + lhs->e124 * rhs->e22 + lhs->e14 * rhs->e222 + lhs->e222 * rhs->e14 
             + lhs->e24 * rhs->e122 + lhs->e122 * rhs->e24;
  res->e22224 =  + lhs->e2 * rhs->e2224 + lhs->e2224 * rhs->e2 + lhs->e4 * rhs->e2222 
             + lhs->e2222 * rhs->e4 + lhs->e22 * rhs->e224 + lhs->e224 * rhs->e22 
             + lhs->e24 * rhs->e222 + lhs->e222 * rhs->e24;
  res->e11134 =  + lhs->e1 * rhs->e1134 + lhs->e1134 * rhs->e1 + lhs->e3 * rhs->e1114 
             + lhs->e1114 * rhs->e3 + lhs->e4 * rhs->e1113 + lhs->e1113 * rhs->e4 
             + lhs->e11 * rhs->e134 + lhs->e134 * rhs->e11 + lhs->e13 * rhs->e114 
             + lhs->e114 * rhs->e13 + lhs->e14 * rhs->e113 + lhs->e113 * rhs->e14 
             + lhs->e34 * rhs->e111 + lhs->e111 * rhs->e34;
  res->e11234 =  + lhs->e1 * rhs->e1234 + lhs->e1234 * rhs->e1 + lhs->e2 * rhs->e1134 
             + lhs->e1134 * rhs->e2 + lhs->e3 * rhs->e1124 + lhs->e1124 * rhs->e3 
             + lhs->e4 * rhs->e1123 + lhs->e1123 * rhs->e4 + lhs->e11 * rhs->e234 
             + lhs->e234 * rhs->e11 + lhs->e12 * rhs->e134 + lhs->e134 * rhs->e12 
             + lhs->e13 * rhs->e124 + lhs->e124 * rhs->e13 + lhs->e23 * rhs->e114 
             + lhs->e114 * rhs->e23 + lhs->e14 * rhs->e123 + lhs->e123 * rhs->e14 
             + lhs->e24 * rhs->e113 + lhs->e113 * rhs->e24 + lhs->e34 * rhs->e112 
             + lhs->e112 * rhs->e34;
  res->e12234 =  + lhs->e1 * rhs->e2234 + lhs->e2234 * rhs->e1 + lhs->e2 * rhs->e1234 
             + lhs->e1234 * rhs->e2 + lhs->e3 * rhs->e1224 + lhs->e1224 * rhs->e3 
             + lhs->e4 * rhs->e1223 + lhs->e1223 * rhs->e4 + lhs->e12 * rhs->e234 
             + lhs->e234 * rhs->e12 + lhs->e22 * rhs->e134 + lhs->e134 * rhs->e22 
             + lhs->e13 * rhs->e224 + lhs->e224 * rhs->e13 + lhs->e23 * rhs->e124 
             + lhs->e124 * rhs->e23 + lhs->e14 * rhs->e223 + lhs->e223 * rhs->e14 
             + lhs->e24 * rhs->e123 + lhs->e123 * rhs->e24 + lhs->e34 * rhs->e122 
             + lhs->e122 * rhs->e34;
  res->e22234 =  + lhs->e2 * rhs->e2234 + lhs->e2234 * rhs->e2 + lhs->e3 * rhs->e2224 
             + lhs->e2224 * rhs->e3 + lhs->e4 * rhs->e2223 + lhs->e2223 * rhs->e4 
             + lhs->e22 * rhs->e234 + lhs->e234 * rhs->e22 + lhs->e23 * rhs->e224 
             + lhs->e224 * rhs->e23 + lhs->e24 * rhs->e223 + lhs->e223 * rhs->e24 
             + lhs->e34 * rhs->e222 + lhs->e222 * rhs->e34;
  res->e11334 =  + lhs->e1 * rhs->e1334 + lhs->e1334 * rhs->e1 + lhs->e3 * rhs->e1134 
             + lhs->e1134 * rhs->e3 + lhs->e4 * rhs->e1133 + lhs->e1133 * rhs->e4 
             + lhs->e11 * rhs->e334 + lhs->e334 * rhs->e11 + lhs->e13 * rhs->e134 
             + lhs->e134 * rhs->e13 + lhs->e33 * rhs->e114 + lhs->e114 * rhs->e33 
             + lhs->e14 * rhs->e133 + lhs->e133 * rhs->e14 + lhs->e34 * rhs->e113 
             + lhs->e113 * rhs->e34;
  res->e12334 =  + lhs->e1 * rhs->e2334 + lhs->e2334 * rhs->e1 + lhs->e2 * rhs->e1334 
             + lhs->e1334 * rhs->e2 + lhs->e3 * rhs->e1234 + lhs->e1234 * rhs->e3 
             + lhs->e4 * rhs->e1233 + lhs->e1233 * rhs->e4 + lhs->e12 * rhs->e334 
             + lhs->e334 * rhs->e12 + lhs->e13 * rhs->e234 + lhs->e234 * rhs->e13 
             + lhs->e23 * rhs->e134 + lhs->e134 * rhs->e23 + lhs->e33 * rhs->e124 
             + lhs->e124 * rhs->e33 + lhs->e14 * rhs->e233 + lhs->e233 * rhs->e14 
             + lhs->e24 * rhs->e133 + lhs->e133 * rhs->e24 + lhs->e34 * rhs->e123 
             + lhs->e123 * rhs->e34;
  res->e22334 =  + lhs->e2 * rhs->e2334 + lhs->e2334 * rhs->e2 + lhs->e3 * rhs->e2234 
             + lhs->e2234 * rhs->e3 + lhs->e4 * rhs->e2233 + lhs->e2233 * rhs->e4 
             + lhs->e22 * rhs->e334 + lhs->e334 * rhs->e22 + lhs->e23 * rhs->e234 
             + lhs->e234 * rhs->e23 + lhs->e33 * rhs->e224 + lhs->e224 * rhs->e33 
             + lhs->e24 * rhs->e233 + lhs->e233 * rhs->e24 + lhs->e34 * rhs->e223 
             + lhs->e223 * rhs->e34;
  res->e13334 =  + lhs->e1 * rhs->e3334 + lhs->e3334 * rhs->e1 + lhs->e3 * rhs->e1334 
             + lhs->e1334 * rhs->e3 + lhs->e4 * rhs->e1333 + lhs->e1333 * rhs->e4 
             + lhs->e13 * rhs->e334 + lhs->e334 * rhs->e13 + lhs->e33 * rhs->e134 
             + lhs->e134 * rhs->e33 + lhs->e14 * rhs->e333 + lhs->e333 * rhs->e14 
             + lhs->e34 * rhs->e133 + lhs->e133 * rhs->e34;
  res->e23334 =  + lhs->e2 * rhs->e3334 + lhs->e3334 * rhs->e2 + lhs->e3 * rhs->e2334 
             + lhs->e2334 * rhs->e3 + lhs->e4 * rhs->e2333 + lhs->e2333 * rhs->e4 
             + lhs->e23 * rhs->e334 + lhs->e334 * rhs->e23 + lhs->e33 * rhs->e234 
             + lhs->e234 * rhs->e33 + lhs->e24 * rhs->e333 + lhs->e333 * rhs->e24 
             + lhs->e34 * rhs->e233 + lhs->e233 * rhs->e34;
  res->e33334 =  + lhs->e3 * rhs->e3334 + lhs->e3334 * rhs->e3 + lhs->e4 * rhs->e3333 
             + lhs->e3333 * rhs->e4 + lhs->e33 * rhs->e334 + lhs->e334 * rhs->e33 
             + lhs->e34 * rhs->e333 + lhs->e333 * rhs->e34;
  res->e11144 =  + lhs->e1 * rhs->e1144 + lhs->e1144 * rhs->e1 + lhs->e4 * rhs->e1114 
             + lhs->e1114 * rhs->e4 + lhs->e11 * rhs->e144 + lhs->e144 * rhs->e11 
             + lhs->e14 * rhs->e114 + lhs->e114 * rhs->e14 + lhs->e44 * rhs->e111 
             + lhs->e111 * rhs->e44;
  res->e11244 =  + lhs->e1 * rhs->e1244 + lhs->e1244 * rhs->e1 + lhs->e2 * rhs->e1144 
             + lhs->e1144 * rhs->e2 + lhs->e4 * rhs->e1124 + lhs->e1124 * rhs->e4 
             + lhs->e11 * rhs->e244 + lhs->e244 * rhs->e11 + lhs->e12 * rhs->e144 
             + lhs->e144 * rhs->e12 + lhs->e14 * rhs->e124 + lhs->e124 * rhs->e14 
             + lhs->e24 * rhs->e114 + lhs->e114 * rhs->e24 + lhs->e44 * rhs->e112 
             + lhs->e112 * rhs->e44;
  res->e12244 =  + lhs->e1 * rhs->e2244 + lhs->e2244 * rhs->e1 + lhs->e2 * rhs->e1244 
             + lhs->e1244 * rhs->e2 + lhs->e4 * rhs->e1224 + lhs->e1224 * rhs->e4 
             + lhs->e12 * rhs->e244 + lhs->e244 * rhs->e12 + lhs->e22 * rhs->e144 
             + lhs->e144 * rhs->e22 + lhs->e14 * rhs->e224 + lhs->e224 * rhs->e14 
             + lhs->e24 * rhs->e124 + lhs->e124 * rhs->e24 + lhs->e44 * rhs->e122 
             + lhs->e122 * rhs->e44;
  res->e22244 =  + lhs->e2 * rhs->e2244 + lhs->e2244 * rhs->e2 + lhs->e4 * rhs->e2224 
             + lhs->e2224 * rhs->e4 + lhs->e22 * rhs->e244 + lhs->e244 * rhs->e22 
             + lhs->e24 * rhs->e224 + lhs->e224 * rhs->e24 + lhs->e44 * rhs->e222 
             + lhs->e222 * rhs->e44;
  res->e11344 =  + lhs->e1 * rhs->e1344 + lhs->e1344 * rhs->e1 + lhs->e3 * rhs->e1144 
             + lhs->e1144 * rhs->e3 + lhs->e4 * rhs->e1134 + lhs->e1134 * rhs->e4 
             + lhs->e11 * rhs->e344 + lhs->e344 * rhs->e11 + lhs->e13 * rhs->e144 
             + lhs->e144 * rhs->e13 + lhs->e14 * rhs->e134 + lhs->e134 * rhs->e14 
             + lhs->e34 * rhs->e114 + lhs->e114 * rhs->e34 + lhs->e44 * rhs->e113 
             + lhs->e113 * rhs->e44;
  res->e12344 =  + lhs->e1 * rhs->e2344 + lhs->e2344 * rhs->e1 + lhs->e2 * rhs->e1344 
             + lhs->e1344 * rhs->e2 + lhs->e3 * rhs->e1244 + lhs->e1244 * rhs->e3 
             + lhs->e4 * rhs->e1234 + lhs->e1234 * rhs->e4 + lhs->e12 * rhs->e344 
             + lhs->e344 * rhs->e12 + lhs->e13 * rhs->e244 + lhs->e244 * rhs->e13 
             + lhs->e23 * rhs->e144 + lhs->e144 * rhs->e23 + lhs->e14 * rhs->e234 
             + lhs->e234 * rhs->e14 + lhs->e24 * rhs->e134 + lhs->e134 * rhs->e24 
             + lhs->e34 * rhs->e124 + lhs->e124 * rhs->e34 + lhs->e44 * rhs->e123 
             + lhs->e123 * rhs->e44;
  res->e22344 =  + lhs->e2 * rhs->e2344 + lhs->e2344 * rhs->e2 + lhs->e3 * rhs->e2244 
             + lhs->e2244 * rhs->e3 + lhs->e4 * rhs->e2234 + lhs->e2234 * rhs->e4 
             + lhs->e22 * rhs->e344 + lhs->e344 * rhs->e22 + lhs->e23 * rhs->e244 
             + lhs->e244 * rhs->e23 + lhs->e24 * rhs->e234 + lhs->e234 * rhs->e24 
             + lhs->e34 * rhs->e224 + lhs->e224 * rhs->e34 + lhs->e44 * rhs->e223 
             + lhs->e223 * rhs->e44;
  res->e13344 =  + lhs->e1 * rhs->e3344 + lhs->e3344 * rhs->e1 + lhs->e3 * rhs->e1344 
             + lhs->e1344 * rhs->e3 + lhs->e4 * rhs->e1334 + lhs->e1334 * rhs->e4 
             + lhs->e13 * rhs->e344 + lhs->e344 * rhs->e13 + lhs->e33 * rhs->e144 
             + lhs->e144 * rhs->e33 + lhs->e14 * rhs->e334 + lhs->e334 * rhs->e14 
             + lhs->e34 * rhs->e134 + lhs->e134 * rhs->e34 + lhs->e44 * rhs->e133 
             + lhs->e133 * rhs->e44;
  res->e23344 =  + lhs->e2 * rhs->e3344 + lhs->e3344 * rhs->e2 + lhs->e3 * rhs->e2344 
             + lhs->e2344 * rhs->e3 + lhs->e4 * rhs->e2334 + lhs->e2334 * rhs->e4 
             + lhs->e23 * rhs->e344 + lhs->e344 * rhs->e23 + lhs->e33 * rhs->e244 
             + lhs->e244 * rhs->e33 + lhs->e24 * rhs->e334 + lhs->e334 * rhs->e24 
             + lhs->e34 * rhs->e234 + lhs->e234 * rhs->e34 + lhs->e44 * rhs->e233 
             + lhs->e233 * rhs->e44;
  res->e33344 =  + lhs->e3 * rhs->e3344 + lhs->e3344 * rhs->e3 + lhs->e4 * rhs->e3334 
             + lhs->e3334 * rhs->e4 + lhs->e33 * rhs->e344 + lhs->e344 * rhs->e33 
             + lhs->e34 * rhs->e334 + lhs->e334 * rhs->e34 + lhs->e44 * rhs->e333 
             + lhs->e333 * rhs->e44;
  res->e11444 =  + lhs->e1 * rhs->e1444 + lhs->e1444 * rhs->e1 + lhs->e4 * rhs->e1144 
             + lhs->e1144 * rhs->e4 + lhs->e11 * rhs->e444 + lhs->e444 * rhs->e11 
             + lhs->e14 * rhs->e144 + lhs->e144 * rhs->e14 + lhs->e44 * rhs->e114 
             + lhs->e114 * rhs->e44;
  res->e12444 =  + lhs->e1 * rhs->e2444 + lhs->e2444 * rhs->e1 + lhs->e2 * rhs->e1444 
             + lhs->e1444 * rhs->e2 + lhs->e4 * rhs->e1244 + lhs->e1244 * rhs->e4 
             + lhs->e12 * rhs->e444 + lhs->e444 * rhs->e12 + lhs->e14 * rhs->e244 
             + lhs->e244 * rhs->e14 + lhs->e24 * rhs->e144 + lhs->e144 * rhs->e24 
             + lhs->e44 * rhs->e124 + lhs->e124 * rhs->e44;
  res->e22444 =  + lhs->e2 * rhs->e2444 + lhs->e2444 * rhs->e2 + lhs->e4 * rhs->e2244 
             + lhs->e2244 * rhs->e4 + lhs->e22 * rhs->e444 + lhs->e444 * rhs->e22 
             + lhs->e24 * rhs->e244 + lhs->e244 * rhs->e24 + lhs->e44 * rhs->e224 
             + lhs->e224 * rhs->e44;
  res->e13444 =  + lhs->e1 * rhs->e3444 + lhs->e3444 * rhs->e1 + lhs->e3 * rhs->e1444 
             + lhs->e1444 * rhs->e3 + lhs->e4 * rhs->e1344 + lhs->e1344 * rhs->e4 
             + lhs->e13 * rhs->e444 + lhs->e444 * rhs->e13 + lhs->e14 * rhs->e344 
             + lhs->e344 * rhs->e14 + lhs->e34 * rhs->e144 + lhs->e144 * rhs->e34 
             + lhs->e44 * rhs->e134 + lhs->e134 * rhs->e44;
  res->e23444 =  + lhs->e2 * rhs->e3444 + lhs->e3444 * rhs->e2 + lhs->e3 * rhs->e2444 
             + lhs->e2444 * rhs->e3 + lhs->e4 * rhs->e2344 + lhs->e2344 * rhs->e4 
             + lhs->e23 * rhs->e444 + lhs->e444 * rhs->e23 + lhs->e24 * rhs->e344 
             + lhs->e344 * rhs->e24 + lhs->e34 * rhs->e244 + lhs->e244 * rhs->e34 
             + lhs->e44 * rhs->e234 + lhs->e234 * rhs->e44;
  res->e33444 =  + lhs->e3 * rhs->e3444 + lhs->e3444 * rhs->e3 + lhs->e4 * rhs->e3344 
             + lhs->e3344 * rhs->e4 + lhs->e33 * rhs->e444 + lhs->e444 * rhs->e33 
             + lhs->e34 * rhs->e344 + lhs->e344 * rhs->e34 + lhs->e44 * rhs->e334 
             + lhs->e334 * rhs->e44;
  res->e14444 =  + lhs->e1 * rhs->e4444 + lhs->e4444 * rhs->e1 + lhs->e4 * rhs->e1444 
             + lhs->e1444 * rhs->e4 + lhs->e14 * rhs->e444 + lhs->e444 * rhs->e14 
             + lhs->e44 * rhs->e144 + lhs->e144 * rhs->e44;
  res->e24444 =  + lhs->e2 * rhs->e4444 + lhs->e4444 * rhs->e2 + lhs->e4 * rhs->e2444 
             + lhs->e2444 * rhs->e4 + lhs->e24 * rhs->e444 + lhs->e444 * rhs->e24 
             + lhs->e44 * rhs->e244 + lhs->e244 * rhs->e44;
  res->e34444 =  + lhs->e3 * rhs->e4444 + lhs->e4444 * rhs->e3 + lhs->e4 * rhs->e3444 
             + lhs->e3444 * rhs->e4 + lhs->e34 * rhs->e444 + lhs->e444 * rhs->e34 
             + lhs->e44 * rhs->e344 + lhs->e344 * rhs->e44;
  res->e44444 =  + lhs->e4 * rhs->e4444 + lhs->e4444 * rhs->e4 + lhs->e44 * rhs->e444 
             + lhs->e444 * rhs->e44;

}

onumm4n5_t onumm4n5_gem_oo(  onumm4n5_t* a,  onumm4n5_t* b,  onumm4n5_t* c){
  onumm4n5_t res;

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
  res.e11114 = c->e11114 + a->r * b->e11114 + a->e11114 * b->r + a->e1 * b->e1114 
             + a->e1114 * b->e1 + a->e4 * b->e1111 + a->e1111 * b->e4 
             + a->e11 * b->e114 + a->e114 * b->e11 + a->e14 * b->e111 
             + a->e111 * b->e14;
  res.e11124 = c->e11124 + a->r * b->e11124 + a->e11124 * b->r + a->e1 * b->e1124 
             + a->e1124 * b->e1 + a->e2 * b->e1114 + a->e1114 * b->e2 
             + a->e4 * b->e1112 + a->e1112 * b->e4 + a->e11 * b->e124 
             + a->e124 * b->e11 + a->e12 * b->e114 + a->e114 * b->e12 
             + a->e14 * b->e112 + a->e112 * b->e14 + a->e24 * b->e111 
             + a->e111 * b->e24;
  res.e11224 = c->e11224 + a->r * b->e11224 + a->e11224 * b->r + a->e1 * b->e1224 
             + a->e1224 * b->e1 + a->e2 * b->e1124 + a->e1124 * b->e2 
             + a->e4 * b->e1122 + a->e1122 * b->e4 + a->e11 * b->e224 
             + a->e224 * b->e11 + a->e12 * b->e124 + a->e124 * b->e12 
             + a->e22 * b->e114 + a->e114 * b->e22 + a->e14 * b->e122 
             + a->e122 * b->e14 + a->e24 * b->e112 + a->e112 * b->e24;
  res.e12224 = c->e12224 + a->r * b->e12224 + a->e12224 * b->r + a->e1 * b->e2224 
             + a->e2224 * b->e1 + a->e2 * b->e1224 + a->e1224 * b->e2 
             + a->e4 * b->e1222 + a->e1222 * b->e4 + a->e12 * b->e224 
             + a->e224 * b->e12 + a->e22 * b->e124 + a->e124 * b->e22 
             + a->e14 * b->e222 + a->e222 * b->e14 + a->e24 * b->e122 
             + a->e122 * b->e24;
  res.e22224 = c->e22224 + a->r * b->e22224 + a->e22224 * b->r + a->e2 * b->e2224 
             + a->e2224 * b->e2 + a->e4 * b->e2222 + a->e2222 * b->e4 
             + a->e22 * b->e224 + a->e224 * b->e22 + a->e24 * b->e222 
             + a->e222 * b->e24;
  res.e11134 = c->e11134 + a->r * b->e11134 + a->e11134 * b->r + a->e1 * b->e1134 
             + a->e1134 * b->e1 + a->e3 * b->e1114 + a->e1114 * b->e3 
             + a->e4 * b->e1113 + a->e1113 * b->e4 + a->e11 * b->e134 
             + a->e134 * b->e11 + a->e13 * b->e114 + a->e114 * b->e13 
             + a->e14 * b->e113 + a->e113 * b->e14 + a->e34 * b->e111 
             + a->e111 * b->e34;
  res.e11234 = c->e11234 + a->r * b->e11234 + a->e11234 * b->r + a->e1 * b->e1234 
             + a->e1234 * b->e1 + a->e2 * b->e1134 + a->e1134 * b->e2 
             + a->e3 * b->e1124 + a->e1124 * b->e3 + a->e4 * b->e1123 
             + a->e1123 * b->e4 + a->e11 * b->e234 + a->e234 * b->e11 
             + a->e12 * b->e134 + a->e134 * b->e12 + a->e13 * b->e124 
             + a->e124 * b->e13 + a->e23 * b->e114 + a->e114 * b->e23 
             + a->e14 * b->e123 + a->e123 * b->e14 + a->e24 * b->e113 
             + a->e113 * b->e24 + a->e34 * b->e112 + a->e112 * b->e34;
  res.e12234 = c->e12234 + a->r * b->e12234 + a->e12234 * b->r + a->e1 * b->e2234 
             + a->e2234 * b->e1 + a->e2 * b->e1234 + a->e1234 * b->e2 
             + a->e3 * b->e1224 + a->e1224 * b->e3 + a->e4 * b->e1223 
             + a->e1223 * b->e4 + a->e12 * b->e234 + a->e234 * b->e12 
             + a->e22 * b->e134 + a->e134 * b->e22 + a->e13 * b->e224 
             + a->e224 * b->e13 + a->e23 * b->e124 + a->e124 * b->e23 
             + a->e14 * b->e223 + a->e223 * b->e14 + a->e24 * b->e123 
             + a->e123 * b->e24 + a->e34 * b->e122 + a->e122 * b->e34;
  res.e22234 = c->e22234 + a->r * b->e22234 + a->e22234 * b->r + a->e2 * b->e2234 
             + a->e2234 * b->e2 + a->e3 * b->e2224 + a->e2224 * b->e3 
             + a->e4 * b->e2223 + a->e2223 * b->e4 + a->e22 * b->e234 
             + a->e234 * b->e22 + a->e23 * b->e224 + a->e224 * b->e23 
             + a->e24 * b->e223 + a->e223 * b->e24 + a->e34 * b->e222 
             + a->e222 * b->e34;
  res.e11334 = c->e11334 + a->r * b->e11334 + a->e11334 * b->r + a->e1 * b->e1334 
             + a->e1334 * b->e1 + a->e3 * b->e1134 + a->e1134 * b->e3 
             + a->e4 * b->e1133 + a->e1133 * b->e4 + a->e11 * b->e334 
             + a->e334 * b->e11 + a->e13 * b->e134 + a->e134 * b->e13 
             + a->e33 * b->e114 + a->e114 * b->e33 + a->e14 * b->e133 
             + a->e133 * b->e14 + a->e34 * b->e113 + a->e113 * b->e34;
  res.e12334 = c->e12334 + a->r * b->e12334 + a->e12334 * b->r + a->e1 * b->e2334 
             + a->e2334 * b->e1 + a->e2 * b->e1334 + a->e1334 * b->e2 
             + a->e3 * b->e1234 + a->e1234 * b->e3 + a->e4 * b->e1233 
             + a->e1233 * b->e4 + a->e12 * b->e334 + a->e334 * b->e12 
             + a->e13 * b->e234 + a->e234 * b->e13 + a->e23 * b->e134 
             + a->e134 * b->e23 + a->e33 * b->e124 + a->e124 * b->e33 
             + a->e14 * b->e233 + a->e233 * b->e14 + a->e24 * b->e133 
             + a->e133 * b->e24 + a->e34 * b->e123 + a->e123 * b->e34;
  res.e22334 = c->e22334 + a->r * b->e22334 + a->e22334 * b->r + a->e2 * b->e2334 
             + a->e2334 * b->e2 + a->e3 * b->e2234 + a->e2234 * b->e3 
             + a->e4 * b->e2233 + a->e2233 * b->e4 + a->e22 * b->e334 
             + a->e334 * b->e22 + a->e23 * b->e234 + a->e234 * b->e23 
             + a->e33 * b->e224 + a->e224 * b->e33 + a->e24 * b->e233 
             + a->e233 * b->e24 + a->e34 * b->e223 + a->e223 * b->e34;
  res.e13334 = c->e13334 + a->r * b->e13334 + a->e13334 * b->r + a->e1 * b->e3334 
             + a->e3334 * b->e1 + a->e3 * b->e1334 + a->e1334 * b->e3 
             + a->e4 * b->e1333 + a->e1333 * b->e4 + a->e13 * b->e334 
             + a->e334 * b->e13 + a->e33 * b->e134 + a->e134 * b->e33 
             + a->e14 * b->e333 + a->e333 * b->e14 + a->e34 * b->e133 
             + a->e133 * b->e34;
  res.e23334 = c->e23334 + a->r * b->e23334 + a->e23334 * b->r + a->e2 * b->e3334 
             + a->e3334 * b->e2 + a->e3 * b->e2334 + a->e2334 * b->e3 
             + a->e4 * b->e2333 + a->e2333 * b->e4 + a->e23 * b->e334 
             + a->e334 * b->e23 + a->e33 * b->e234 + a->e234 * b->e33 
             + a->e24 * b->e333 + a->e333 * b->e24 + a->e34 * b->e233 
             + a->e233 * b->e34;
  res.e33334 = c->e33334 + a->r * b->e33334 + a->e33334 * b->r + a->e3 * b->e3334 
             + a->e3334 * b->e3 + a->e4 * b->e3333 + a->e3333 * b->e4 
             + a->e33 * b->e334 + a->e334 * b->e33 + a->e34 * b->e333 
             + a->e333 * b->e34;
  res.e11144 = c->e11144 + a->r * b->e11144 + a->e11144 * b->r + a->e1 * b->e1144 
             + a->e1144 * b->e1 + a->e4 * b->e1114 + a->e1114 * b->e4 
             + a->e11 * b->e144 + a->e144 * b->e11 + a->e14 * b->e114 
             + a->e114 * b->e14 + a->e44 * b->e111 + a->e111 * b->e44;
  res.e11244 = c->e11244 + a->r * b->e11244 + a->e11244 * b->r + a->e1 * b->e1244 
             + a->e1244 * b->e1 + a->e2 * b->e1144 + a->e1144 * b->e2 
             + a->e4 * b->e1124 + a->e1124 * b->e4 + a->e11 * b->e244 
             + a->e244 * b->e11 + a->e12 * b->e144 + a->e144 * b->e12 
             + a->e14 * b->e124 + a->e124 * b->e14 + a->e24 * b->e114 
             + a->e114 * b->e24 + a->e44 * b->e112 + a->e112 * b->e44;
  res.e12244 = c->e12244 + a->r * b->e12244 + a->e12244 * b->r + a->e1 * b->e2244 
             + a->e2244 * b->e1 + a->e2 * b->e1244 + a->e1244 * b->e2 
             + a->e4 * b->e1224 + a->e1224 * b->e4 + a->e12 * b->e244 
             + a->e244 * b->e12 + a->e22 * b->e144 + a->e144 * b->e22 
             + a->e14 * b->e224 + a->e224 * b->e14 + a->e24 * b->e124 
             + a->e124 * b->e24 + a->e44 * b->e122 + a->e122 * b->e44;
  res.e22244 = c->e22244 + a->r * b->e22244 + a->e22244 * b->r + a->e2 * b->e2244 
             + a->e2244 * b->e2 + a->e4 * b->e2224 + a->e2224 * b->e4 
             + a->e22 * b->e244 + a->e244 * b->e22 + a->e24 * b->e224 
             + a->e224 * b->e24 + a->e44 * b->e222 + a->e222 * b->e44;
  res.e11344 = c->e11344 + a->r * b->e11344 + a->e11344 * b->r + a->e1 * b->e1344 
             + a->e1344 * b->e1 + a->e3 * b->e1144 + a->e1144 * b->e3 
             + a->e4 * b->e1134 + a->e1134 * b->e4 + a->e11 * b->e344 
             + a->e344 * b->e11 + a->e13 * b->e144 + a->e144 * b->e13 
             + a->e14 * b->e134 + a->e134 * b->e14 + a->e34 * b->e114 
             + a->e114 * b->e34 + a->e44 * b->e113 + a->e113 * b->e44;
  res.e12344 = c->e12344 + a->r * b->e12344 + a->e12344 * b->r + a->e1 * b->e2344 
             + a->e2344 * b->e1 + a->e2 * b->e1344 + a->e1344 * b->e2 
             + a->e3 * b->e1244 + a->e1244 * b->e3 + a->e4 * b->e1234 
             + a->e1234 * b->e4 + a->e12 * b->e344 + a->e344 * b->e12 
             + a->e13 * b->e244 + a->e244 * b->e13 + a->e23 * b->e144 
             + a->e144 * b->e23 + a->e14 * b->e234 + a->e234 * b->e14 
             + a->e24 * b->e134 + a->e134 * b->e24 + a->e34 * b->e124 
             + a->e124 * b->e34 + a->e44 * b->e123 + a->e123 * b->e44;
  res.e22344 = c->e22344 + a->r * b->e22344 + a->e22344 * b->r + a->e2 * b->e2344 
             + a->e2344 * b->e2 + a->e3 * b->e2244 + a->e2244 * b->e3 
             + a->e4 * b->e2234 + a->e2234 * b->e4 + a->e22 * b->e344 
             + a->e344 * b->e22 + a->e23 * b->e244 + a->e244 * b->e23 
             + a->e24 * b->e234 + a->e234 * b->e24 + a->e34 * b->e224 
             + a->e224 * b->e34 + a->e44 * b->e223 + a->e223 * b->e44;
  res.e13344 = c->e13344 + a->r * b->e13344 + a->e13344 * b->r + a->e1 * b->e3344 
             + a->e3344 * b->e1 + a->e3 * b->e1344 + a->e1344 * b->e3 
             + a->e4 * b->e1334 + a->e1334 * b->e4 + a->e13 * b->e344 
             + a->e344 * b->e13 + a->e33 * b->e144 + a->e144 * b->e33 
             + a->e14 * b->e334 + a->e334 * b->e14 + a->e34 * b->e134 
             + a->e134 * b->e34 + a->e44 * b->e133 + a->e133 * b->e44;
  res.e23344 = c->e23344 + a->r * b->e23344 + a->e23344 * b->r + a->e2 * b->e3344 
             + a->e3344 * b->e2 + a->e3 * b->e2344 + a->e2344 * b->e3 
             + a->e4 * b->e2334 + a->e2334 * b->e4 + a->e23 * b->e344 
             + a->e344 * b->e23 + a->e33 * b->e244 + a->e244 * b->e33 
             + a->e24 * b->e334 + a->e334 * b->e24 + a->e34 * b->e234 
             + a->e234 * b->e34 + a->e44 * b->e233 + a->e233 * b->e44;
  res.e33344 = c->e33344 + a->r * b->e33344 + a->e33344 * b->r + a->e3 * b->e3344 
             + a->e3344 * b->e3 + a->e4 * b->e3334 + a->e3334 * b->e4 
             + a->e33 * b->e344 + a->e344 * b->e33 + a->e34 * b->e334 
             + a->e334 * b->e34 + a->e44 * b->e333 + a->e333 * b->e44;
  res.e11444 = c->e11444 + a->r * b->e11444 + a->e11444 * b->r + a->e1 * b->e1444 
             + a->e1444 * b->e1 + a->e4 * b->e1144 + a->e1144 * b->e4 
             + a->e11 * b->e444 + a->e444 * b->e11 + a->e14 * b->e144 
             + a->e144 * b->e14 + a->e44 * b->e114 + a->e114 * b->e44;
  res.e12444 = c->e12444 + a->r * b->e12444 + a->e12444 * b->r + a->e1 * b->e2444 
             + a->e2444 * b->e1 + a->e2 * b->e1444 + a->e1444 * b->e2 
             + a->e4 * b->e1244 + a->e1244 * b->e4 + a->e12 * b->e444 
             + a->e444 * b->e12 + a->e14 * b->e244 + a->e244 * b->e14 
             + a->e24 * b->e144 + a->e144 * b->e24 + a->e44 * b->e124 
             + a->e124 * b->e44;
  res.e22444 = c->e22444 + a->r * b->e22444 + a->e22444 * b->r + a->e2 * b->e2444 
             + a->e2444 * b->e2 + a->e4 * b->e2244 + a->e2244 * b->e4 
             + a->e22 * b->e444 + a->e444 * b->e22 + a->e24 * b->e244 
             + a->e244 * b->e24 + a->e44 * b->e224 + a->e224 * b->e44;
  res.e13444 = c->e13444 + a->r * b->e13444 + a->e13444 * b->r + a->e1 * b->e3444 
             + a->e3444 * b->e1 + a->e3 * b->e1444 + a->e1444 * b->e3 
             + a->e4 * b->e1344 + a->e1344 * b->e4 + a->e13 * b->e444 
             + a->e444 * b->e13 + a->e14 * b->e344 + a->e344 * b->e14 
             + a->e34 * b->e144 + a->e144 * b->e34 + a->e44 * b->e134 
             + a->e134 * b->e44;
  res.e23444 = c->e23444 + a->r * b->e23444 + a->e23444 * b->r + a->e2 * b->e3444 
             + a->e3444 * b->e2 + a->e3 * b->e2444 + a->e2444 * b->e3 
             + a->e4 * b->e2344 + a->e2344 * b->e4 + a->e23 * b->e444 
             + a->e444 * b->e23 + a->e24 * b->e344 + a->e344 * b->e24 
             + a->e34 * b->e244 + a->e244 * b->e34 + a->e44 * b->e234 
             + a->e234 * b->e44;
  res.e33444 = c->e33444 + a->r * b->e33444 + a->e33444 * b->r + a->e3 * b->e3444 
             + a->e3444 * b->e3 + a->e4 * b->e3344 + a->e3344 * b->e4 
             + a->e33 * b->e444 + a->e444 * b->e33 + a->e34 * b->e344 
             + a->e344 * b->e34 + a->e44 * b->e334 + a->e334 * b->e44;
  res.e14444 = c->e14444 + a->r * b->e14444 + a->e14444 * b->r + a->e1 * b->e4444 
             + a->e4444 * b->e1 + a->e4 * b->e1444 + a->e1444 * b->e4 
             + a->e14 * b->e444 + a->e444 * b->e14 + a->e44 * b->e144 
             + a->e144 * b->e44;
  res.e24444 = c->e24444 + a->r * b->e24444 + a->e24444 * b->r + a->e2 * b->e4444 
             + a->e4444 * b->e2 + a->e4 * b->e2444 + a->e2444 * b->e4 
             + a->e24 * b->e444 + a->e444 * b->e24 + a->e44 * b->e244 
             + a->e244 * b->e44;
  res.e34444 = c->e34444 + a->r * b->e34444 + a->e34444 * b->r + a->e3 * b->e4444 
             + a->e4444 * b->e3 + a->e4 * b->e3444 + a->e3444 * b->e4 
             + a->e34 * b->e444 + a->e444 * b->e34 + a->e44 * b->e344 
             + a->e344 * b->e44;
  res.e44444 = c->e44444 + a->r * b->e44444 + a->e44444 * b->r + a->e4 * b->e4444 
             + a->e4444 * b->e4 + a->e44 * b->e444 + a->e444 * b->e44;

  return res;

}

void onumm4n5_gem_oo_to(  onumm4n5_t* a,  onumm4n5_t* b,  onumm4n5_t* c, onumm4n5_t* res){
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
  res->e11114 = c->e11114 + a->r * b->e11114 + a->e11114 * b->r + a->e1 * b->e1114 
             + a->e1114 * b->e1 + a->e4 * b->e1111 + a->e1111 * b->e4 
             + a->e11 * b->e114 + a->e114 * b->e11 + a->e14 * b->e111 
             + a->e111 * b->e14;
  res->e11124 = c->e11124 + a->r * b->e11124 + a->e11124 * b->r + a->e1 * b->e1124 
             + a->e1124 * b->e1 + a->e2 * b->e1114 + a->e1114 * b->e2 
             + a->e4 * b->e1112 + a->e1112 * b->e4 + a->e11 * b->e124 
             + a->e124 * b->e11 + a->e12 * b->e114 + a->e114 * b->e12 
             + a->e14 * b->e112 + a->e112 * b->e14 + a->e24 * b->e111 
             + a->e111 * b->e24;
  res->e11224 = c->e11224 + a->r * b->e11224 + a->e11224 * b->r + a->e1 * b->e1224 
             + a->e1224 * b->e1 + a->e2 * b->e1124 + a->e1124 * b->e2 
             + a->e4 * b->e1122 + a->e1122 * b->e4 + a->e11 * b->e224 
             + a->e224 * b->e11 + a->e12 * b->e124 + a->e124 * b->e12 
             + a->e22 * b->e114 + a->e114 * b->e22 + a->e14 * b->e122 
             + a->e122 * b->e14 + a->e24 * b->e112 + a->e112 * b->e24;
  res->e12224 = c->e12224 + a->r * b->e12224 + a->e12224 * b->r + a->e1 * b->e2224 
             + a->e2224 * b->e1 + a->e2 * b->e1224 + a->e1224 * b->e2 
             + a->e4 * b->e1222 + a->e1222 * b->e4 + a->e12 * b->e224 
             + a->e224 * b->e12 + a->e22 * b->e124 + a->e124 * b->e22 
             + a->e14 * b->e222 + a->e222 * b->e14 + a->e24 * b->e122 
             + a->e122 * b->e24;
  res->e22224 = c->e22224 + a->r * b->e22224 + a->e22224 * b->r + a->e2 * b->e2224 
             + a->e2224 * b->e2 + a->e4 * b->e2222 + a->e2222 * b->e4 
             + a->e22 * b->e224 + a->e224 * b->e22 + a->e24 * b->e222 
             + a->e222 * b->e24;
  res->e11134 = c->e11134 + a->r * b->e11134 + a->e11134 * b->r + a->e1 * b->e1134 
             + a->e1134 * b->e1 + a->e3 * b->e1114 + a->e1114 * b->e3 
             + a->e4 * b->e1113 + a->e1113 * b->e4 + a->e11 * b->e134 
             + a->e134 * b->e11 + a->e13 * b->e114 + a->e114 * b->e13 
             + a->e14 * b->e113 + a->e113 * b->e14 + a->e34 * b->e111 
             + a->e111 * b->e34;
  res->e11234 = c->e11234 + a->r * b->e11234 + a->e11234 * b->r + a->e1 * b->e1234 
             + a->e1234 * b->e1 + a->e2 * b->e1134 + a->e1134 * b->e2 
             + a->e3 * b->e1124 + a->e1124 * b->e3 + a->e4 * b->e1123 
             + a->e1123 * b->e4 + a->e11 * b->e234 + a->e234 * b->e11 
             + a->e12 * b->e134 + a->e134 * b->e12 + a->e13 * b->e124 
             + a->e124 * b->e13 + a->e23 * b->e114 + a->e114 * b->e23 
             + a->e14 * b->e123 + a->e123 * b->e14 + a->e24 * b->e113 
             + a->e113 * b->e24 + a->e34 * b->e112 + a->e112 * b->e34;
  res->e12234 = c->e12234 + a->r * b->e12234 + a->e12234 * b->r + a->e1 * b->e2234 
             + a->e2234 * b->e1 + a->e2 * b->e1234 + a->e1234 * b->e2 
             + a->e3 * b->e1224 + a->e1224 * b->e3 + a->e4 * b->e1223 
             + a->e1223 * b->e4 + a->e12 * b->e234 + a->e234 * b->e12 
             + a->e22 * b->e134 + a->e134 * b->e22 + a->e13 * b->e224 
             + a->e224 * b->e13 + a->e23 * b->e124 + a->e124 * b->e23 
             + a->e14 * b->e223 + a->e223 * b->e14 + a->e24 * b->e123 
             + a->e123 * b->e24 + a->e34 * b->e122 + a->e122 * b->e34;
  res->e22234 = c->e22234 + a->r * b->e22234 + a->e22234 * b->r + a->e2 * b->e2234 
             + a->e2234 * b->e2 + a->e3 * b->e2224 + a->e2224 * b->e3 
             + a->e4 * b->e2223 + a->e2223 * b->e4 + a->e22 * b->e234 
             + a->e234 * b->e22 + a->e23 * b->e224 + a->e224 * b->e23 
             + a->e24 * b->e223 + a->e223 * b->e24 + a->e34 * b->e222 
             + a->e222 * b->e34;
  res->e11334 = c->e11334 + a->r * b->e11334 + a->e11334 * b->r + a->e1 * b->e1334 
             + a->e1334 * b->e1 + a->e3 * b->e1134 + a->e1134 * b->e3 
             + a->e4 * b->e1133 + a->e1133 * b->e4 + a->e11 * b->e334 
             + a->e334 * b->e11 + a->e13 * b->e134 + a->e134 * b->e13 
             + a->e33 * b->e114 + a->e114 * b->e33 + a->e14 * b->e133 
             + a->e133 * b->e14 + a->e34 * b->e113 + a->e113 * b->e34;
  res->e12334 = c->e12334 + a->r * b->e12334 + a->e12334 * b->r + a->e1 * b->e2334 
             + a->e2334 * b->e1 + a->e2 * b->e1334 + a->e1334 * b->e2 
             + a->e3 * b->e1234 + a->e1234 * b->e3 + a->e4 * b->e1233 
             + a->e1233 * b->e4 + a->e12 * b->e334 + a->e334 * b->e12 
             + a->e13 * b->e234 + a->e234 * b->e13 + a->e23 * b->e134 
             + a->e134 * b->e23 + a->e33 * b->e124 + a->e124 * b->e33 
             + a->e14 * b->e233 + a->e233 * b->e14 + a->e24 * b->e133 
             + a->e133 * b->e24 + a->e34 * b->e123 + a->e123 * b->e34;
  res->e22334 = c->e22334 + a->r * b->e22334 + a->e22334 * b->r + a->e2 * b->e2334 
             + a->e2334 * b->e2 + a->e3 * b->e2234 + a->e2234 * b->e3 
             + a->e4 * b->e2233 + a->e2233 * b->e4 + a->e22 * b->e334 
             + a->e334 * b->e22 + a->e23 * b->e234 + a->e234 * b->e23 
             + a->e33 * b->e224 + a->e224 * b->e33 + a->e24 * b->e233 
             + a->e233 * b->e24 + a->e34 * b->e223 + a->e223 * b->e34;
  res->e13334 = c->e13334 + a->r * b->e13334 + a->e13334 * b->r + a->e1 * b->e3334 
             + a->e3334 * b->e1 + a->e3 * b->e1334 + a->e1334 * b->e3 
             + a->e4 * b->e1333 + a->e1333 * b->e4 + a->e13 * b->e334 
             + a->e334 * b->e13 + a->e33 * b->e134 + a->e134 * b->e33 
             + a->e14 * b->e333 + a->e333 * b->e14 + a->e34 * b->e133 
             + a->e133 * b->e34;
  res->e23334 = c->e23334 + a->r * b->e23334 + a->e23334 * b->r + a->e2 * b->e3334 
             + a->e3334 * b->e2 + a->e3 * b->e2334 + a->e2334 * b->e3 
             + a->e4 * b->e2333 + a->e2333 * b->e4 + a->e23 * b->e334 
             + a->e334 * b->e23 + a->e33 * b->e234 + a->e234 * b->e33 
             + a->e24 * b->e333 + a->e333 * b->e24 + a->e34 * b->e233 
             + a->e233 * b->e34;
  res->e33334 = c->e33334 + a->r * b->e33334 + a->e33334 * b->r + a->e3 * b->e3334 
             + a->e3334 * b->e3 + a->e4 * b->e3333 + a->e3333 * b->e4 
             + a->e33 * b->e334 + a->e334 * b->e33 + a->e34 * b->e333 
             + a->e333 * b->e34;
  res->e11144 = c->e11144 + a->r * b->e11144 + a->e11144 * b->r + a->e1 * b->e1144 
             + a->e1144 * b->e1 + a->e4 * b->e1114 + a->e1114 * b->e4 
             + a->e11 * b->e144 + a->e144 * b->e11 + a->e14 * b->e114 
             + a->e114 * b->e14 + a->e44 * b->e111 + a->e111 * b->e44;
  res->e11244 = c->e11244 + a->r * b->e11244 + a->e11244 * b->r + a->e1 * b->e1244 
             + a->e1244 * b->e1 + a->e2 * b->e1144 + a->e1144 * b->e2 
             + a->e4 * b->e1124 + a->e1124 * b->e4 + a->e11 * b->e244 
             + a->e244 * b->e11 + a->e12 * b->e144 + a->e144 * b->e12 
             + a->e14 * b->e124 + a->e124 * b->e14 + a->e24 * b->e114 
             + a->e114 * b->e24 + a->e44 * b->e112 + a->e112 * b->e44;
  res->e12244 = c->e12244 + a->r * b->e12244 + a->e12244 * b->r + a->e1 * b->e2244 
             + a->e2244 * b->e1 + a->e2 * b->e1244 + a->e1244 * b->e2 
             + a->e4 * b->e1224 + a->e1224 * b->e4 + a->e12 * b->e244 
             + a->e244 * b->e12 + a->e22 * b->e144 + a->e144 * b->e22 
             + a->e14 * b->e224 + a->e224 * b->e14 + a->e24 * b->e124 
             + a->e124 * b->e24 + a->e44 * b->e122 + a->e122 * b->e44;
  res->e22244 = c->e22244 + a->r * b->e22244 + a->e22244 * b->r + a->e2 * b->e2244 
             + a->e2244 * b->e2 + a->e4 * b->e2224 + a->e2224 * b->e4 
             + a->e22 * b->e244 + a->e244 * b->e22 + a->e24 * b->e224 
             + a->e224 * b->e24 + a->e44 * b->e222 + a->e222 * b->e44;
  res->e11344 = c->e11344 + a->r * b->e11344 + a->e11344 * b->r + a->e1 * b->e1344 
             + a->e1344 * b->e1 + a->e3 * b->e1144 + a->e1144 * b->e3 
             + a->e4 * b->e1134 + a->e1134 * b->e4 + a->e11 * b->e344 
             + a->e344 * b->e11 + a->e13 * b->e144 + a->e144 * b->e13 
             + a->e14 * b->e134 + a->e134 * b->e14 + a->e34 * b->e114 
             + a->e114 * b->e34 + a->e44 * b->e113 + a->e113 * b->e44;
  res->e12344 = c->e12344 + a->r * b->e12344 + a->e12344 * b->r + a->e1 * b->e2344 
             + a->e2344 * b->e1 + a->e2 * b->e1344 + a->e1344 * b->e2 
             + a->e3 * b->e1244 + a->e1244 * b->e3 + a->e4 * b->e1234 
             + a->e1234 * b->e4 + a->e12 * b->e344 + a->e344 * b->e12 
             + a->e13 * b->e244 + a->e244 * b->e13 + a->e23 * b->e144 
             + a->e144 * b->e23 + a->e14 * b->e234 + a->e234 * b->e14 
             + a->e24 * b->e134 + a->e134 * b->e24 + a->e34 * b->e124 
             + a->e124 * b->e34 + a->e44 * b->e123 + a->e123 * b->e44;
  res->e22344 = c->e22344 + a->r * b->e22344 + a->e22344 * b->r + a->e2 * b->e2344 
             + a->e2344 * b->e2 + a->e3 * b->e2244 + a->e2244 * b->e3 
             + a->e4 * b->e2234 + a->e2234 * b->e4 + a->e22 * b->e344 
             + a->e344 * b->e22 + a->e23 * b->e244 + a->e244 * b->e23 
             + a->e24 * b->e234 + a->e234 * b->e24 + a->e34 * b->e224 
             + a->e224 * b->e34 + a->e44 * b->e223 + a->e223 * b->e44;
  res->e13344 = c->e13344 + a->r * b->e13344 + a->e13344 * b->r + a->e1 * b->e3344 
             + a->e3344 * b->e1 + a->e3 * b->e1344 + a->e1344 * b->e3 
             + a->e4 * b->e1334 + a->e1334 * b->e4 + a->e13 * b->e344 
             + a->e344 * b->e13 + a->e33 * b->e144 + a->e144 * b->e33 
             + a->e14 * b->e334 + a->e334 * b->e14 + a->e34 * b->e134 
             + a->e134 * b->e34 + a->e44 * b->e133 + a->e133 * b->e44;
  res->e23344 = c->e23344 + a->r * b->e23344 + a->e23344 * b->r + a->e2 * b->e3344 
             + a->e3344 * b->e2 + a->e3 * b->e2344 + a->e2344 * b->e3 
             + a->e4 * b->e2334 + a->e2334 * b->e4 + a->e23 * b->e344 
             + a->e344 * b->e23 + a->e33 * b->e244 + a->e244 * b->e33 
             + a->e24 * b->e334 + a->e334 * b->e24 + a->e34 * b->e234 
             + a->e234 * b->e34 + a->e44 * b->e233 + a->e233 * b->e44;
  res->e33344 = c->e33344 + a->r * b->e33344 + a->e33344 * b->r + a->e3 * b->e3344 
             + a->e3344 * b->e3 + a->e4 * b->e3334 + a->e3334 * b->e4 
             + a->e33 * b->e344 + a->e344 * b->e33 + a->e34 * b->e334 
             + a->e334 * b->e34 + a->e44 * b->e333 + a->e333 * b->e44;
  res->e11444 = c->e11444 + a->r * b->e11444 + a->e11444 * b->r + a->e1 * b->e1444 
             + a->e1444 * b->e1 + a->e4 * b->e1144 + a->e1144 * b->e4 
             + a->e11 * b->e444 + a->e444 * b->e11 + a->e14 * b->e144 
             + a->e144 * b->e14 + a->e44 * b->e114 + a->e114 * b->e44;
  res->e12444 = c->e12444 + a->r * b->e12444 + a->e12444 * b->r + a->e1 * b->e2444 
             + a->e2444 * b->e1 + a->e2 * b->e1444 + a->e1444 * b->e2 
             + a->e4 * b->e1244 + a->e1244 * b->e4 + a->e12 * b->e444 
             + a->e444 * b->e12 + a->e14 * b->e244 + a->e244 * b->e14 
             + a->e24 * b->e144 + a->e144 * b->e24 + a->e44 * b->e124 
             + a->e124 * b->e44;
  res->e22444 = c->e22444 + a->r * b->e22444 + a->e22444 * b->r + a->e2 * b->e2444 
             + a->e2444 * b->e2 + a->e4 * b->e2244 + a->e2244 * b->e4 
             + a->e22 * b->e444 + a->e444 * b->e22 + a->e24 * b->e244 
             + a->e244 * b->e24 + a->e44 * b->e224 + a->e224 * b->e44;
  res->e13444 = c->e13444 + a->r * b->e13444 + a->e13444 * b->r + a->e1 * b->e3444 
             + a->e3444 * b->e1 + a->e3 * b->e1444 + a->e1444 * b->e3 
             + a->e4 * b->e1344 + a->e1344 * b->e4 + a->e13 * b->e444 
             + a->e444 * b->e13 + a->e14 * b->e344 + a->e344 * b->e14 
             + a->e34 * b->e144 + a->e144 * b->e34 + a->e44 * b->e134 
             + a->e134 * b->e44;
  res->e23444 = c->e23444 + a->r * b->e23444 + a->e23444 * b->r + a->e2 * b->e3444 
             + a->e3444 * b->e2 + a->e3 * b->e2444 + a->e2444 * b->e3 
             + a->e4 * b->e2344 + a->e2344 * b->e4 + a->e23 * b->e444 
             + a->e444 * b->e23 + a->e24 * b->e344 + a->e344 * b->e24 
             + a->e34 * b->e244 + a->e244 * b->e34 + a->e44 * b->e234 
             + a->e234 * b->e44;
  res->e33444 = c->e33444 + a->r * b->e33444 + a->e33444 * b->r + a->e3 * b->e3444 
             + a->e3444 * b->e3 + a->e4 * b->e3344 + a->e3344 * b->e4 
             + a->e33 * b->e444 + a->e444 * b->e33 + a->e34 * b->e344 
             + a->e344 * b->e34 + a->e44 * b->e334 + a->e334 * b->e44;
  res->e14444 = c->e14444 + a->r * b->e14444 + a->e14444 * b->r + a->e1 * b->e4444 
             + a->e4444 * b->e1 + a->e4 * b->e1444 + a->e1444 * b->e4 
             + a->e14 * b->e444 + a->e444 * b->e14 + a->e44 * b->e144 
             + a->e144 * b->e44;
  res->e24444 = c->e24444 + a->r * b->e24444 + a->e24444 * b->r + a->e2 * b->e4444 
             + a->e4444 * b->e2 + a->e4 * b->e2444 + a->e2444 * b->e4 
             + a->e24 * b->e444 + a->e444 * b->e24 + a->e44 * b->e244 
             + a->e244 * b->e44;
  res->e34444 = c->e34444 + a->r * b->e34444 + a->e34444 * b->r + a->e3 * b->e4444 
             + a->e4444 * b->e3 + a->e4 * b->e3444 + a->e3444 * b->e4 
             + a->e34 * b->e444 + a->e444 * b->e34 + a->e44 * b->e344 
             + a->e344 * b->e44;
  res->e44444 = c->e44444 + a->r * b->e44444 + a->e44444 * b->r + a->e4 * b->e4444 
             + a->e4444 * b->e4 + a->e44 * b->e444 + a->e444 * b->e44;

}

onumm4n5_t onumm4n5_gem_ro(  coeff_t a,  onumm4n5_t* b,  onumm4n5_t* c){
  onumm4n5_t res;

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
  res.e11114 = c->e11114 + a * b->e11114;
  res.e11124 = c->e11124 + a * b->e11124;
  res.e11224 = c->e11224 + a * b->e11224;
  res.e12224 = c->e12224 + a * b->e12224;
  res.e22224 = c->e22224 + a * b->e22224;
  res.e11134 = c->e11134 + a * b->e11134;
  res.e11234 = c->e11234 + a * b->e11234;
  res.e12234 = c->e12234 + a * b->e12234;
  res.e22234 = c->e22234 + a * b->e22234;
  res.e11334 = c->e11334 + a * b->e11334;
  res.e12334 = c->e12334 + a * b->e12334;
  res.e22334 = c->e22334 + a * b->e22334;
  res.e13334 = c->e13334 + a * b->e13334;
  res.e23334 = c->e23334 + a * b->e23334;
  res.e33334 = c->e33334 + a * b->e33334;
  res.e11144 = c->e11144 + a * b->e11144;
  res.e11244 = c->e11244 + a * b->e11244;
  res.e12244 = c->e12244 + a * b->e12244;
  res.e22244 = c->e22244 + a * b->e22244;
  res.e11344 = c->e11344 + a * b->e11344;
  res.e12344 = c->e12344 + a * b->e12344;
  res.e22344 = c->e22344 + a * b->e22344;
  res.e13344 = c->e13344 + a * b->e13344;
  res.e23344 = c->e23344 + a * b->e23344;
  res.e33344 = c->e33344 + a * b->e33344;
  res.e11444 = c->e11444 + a * b->e11444;
  res.e12444 = c->e12444 + a * b->e12444;
  res.e22444 = c->e22444 + a * b->e22444;
  res.e13444 = c->e13444 + a * b->e13444;
  res.e23444 = c->e23444 + a * b->e23444;
  res.e33444 = c->e33444 + a * b->e33444;
  res.e14444 = c->e14444 + a * b->e14444;
  res.e24444 = c->e24444 + a * b->e24444;
  res.e34444 = c->e34444 + a * b->e34444;
  res.e44444 = c->e44444 + a * b->e44444;

  return res;

}

void onumm4n5_gem_ro_to(  coeff_t a,  onumm4n5_t* b,  onumm4n5_t* c, onumm4n5_t* res){
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
  res->e11114 = c->e11114 + a * b->e11114;
  res->e11124 = c->e11124 + a * b->e11124;
  res->e11224 = c->e11224 + a * b->e11224;
  res->e12224 = c->e12224 + a * b->e12224;
  res->e22224 = c->e22224 + a * b->e22224;
  res->e11134 = c->e11134 + a * b->e11134;
  res->e11234 = c->e11234 + a * b->e11234;
  res->e12234 = c->e12234 + a * b->e12234;
  res->e22234 = c->e22234 + a * b->e22234;
  res->e11334 = c->e11334 + a * b->e11334;
  res->e12334 = c->e12334 + a * b->e12334;
  res->e22334 = c->e22334 + a * b->e22334;
  res->e13334 = c->e13334 + a * b->e13334;
  res->e23334 = c->e23334 + a * b->e23334;
  res->e33334 = c->e33334 + a * b->e33334;
  res->e11144 = c->e11144 + a * b->e11144;
  res->e11244 = c->e11244 + a * b->e11244;
  res->e12244 = c->e12244 + a * b->e12244;
  res->e22244 = c->e22244 + a * b->e22244;
  res->e11344 = c->e11344 + a * b->e11344;
  res->e12344 = c->e12344 + a * b->e12344;
  res->e22344 = c->e22344 + a * b->e22344;
  res->e13344 = c->e13344 + a * b->e13344;
  res->e23344 = c->e23344 + a * b->e23344;
  res->e33344 = c->e33344 + a * b->e33344;
  res->e11444 = c->e11444 + a * b->e11444;
  res->e12444 = c->e12444 + a * b->e12444;
  res->e22444 = c->e22444 + a * b->e22444;
  res->e13444 = c->e13444 + a * b->e13444;
  res->e23444 = c->e23444 + a * b->e23444;
  res->e33444 = c->e33444 + a * b->e33444;
  res->e14444 = c->e14444 + a * b->e14444;
  res->e24444 = c->e24444 + a * b->e24444;
  res->e34444 = c->e34444 + a * b->e34444;
  res->e44444 = c->e44444 + a * b->e44444;

}

void onumm4n5_trunc_gem_oo_to( ord_t ord_lhs,  onumm4n5_t* a,  ord_t ord_rhs,  onumm4n5_t* b,  onumm4n5_t* c, onumm4n5_t* res){
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
          res->e1114 = c->e1114 + a->r * b->e1114;
          res->e1124 = c->e1124 + a->r * b->e1124;
          res->e1224 = c->e1224 + a->r * b->e1224;
          res->e2224 = c->e2224 + a->r * b->e2224;
          res->e1134 = c->e1134 + a->r * b->e1134;
          res->e1234 = c->e1234 + a->r * b->e1234;
          res->e2234 = c->e2234 + a->r * b->e2234;
          res->e1334 = c->e1334 + a->r * b->e1334;
          res->e2334 = c->e2334 + a->r * b->e2334;
          res->e3334 = c->e3334 + a->r * b->e3334;
          res->e1144 = c->e1144 + a->r * b->e1144;
          res->e1244 = c->e1244 + a->r * b->e1244;
          res->e2244 = c->e2244 + a->r * b->e2244;
          res->e1344 = c->e1344 + a->r * b->e1344;
          res->e2344 = c->e2344 + a->r * b->e2344;
          res->e3344 = c->e3344 + a->r * b->e3344;
          res->e1444 = c->e1444 + a->r * b->e1444;
          res->e2444 = c->e2444 + a->r * b->e2444;
          res->e3444 = c->e3444 + a->r * b->e3444;
          res->e4444 = c->e4444 + a->r * b->e4444;
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
          res->e11114 = c->e11114 + a->r * b->e11114;
          res->e11124 = c->e11124 + a->r * b->e11124;
          res->e11224 = c->e11224 + a->r * b->e11224;
          res->e12224 = c->e12224 + a->r * b->e12224;
          res->e22224 = c->e22224 + a->r * b->e22224;
          res->e11134 = c->e11134 + a->r * b->e11134;
          res->e11234 = c->e11234 + a->r * b->e11234;
          res->e12234 = c->e12234 + a->r * b->e12234;
          res->e22234 = c->e22234 + a->r * b->e22234;
          res->e11334 = c->e11334 + a->r * b->e11334;
          res->e12334 = c->e12334 + a->r * b->e12334;
          res->e22334 = c->e22334 + a->r * b->e22334;
          res->e13334 = c->e13334 + a->r * b->e13334;
          res->e23334 = c->e23334 + a->r * b->e23334;
          res->e33334 = c->e33334 + a->r * b->e33334;
          res->e11144 = c->e11144 + a->r * b->e11144;
          res->e11244 = c->e11244 + a->r * b->e11244;
          res->e12244 = c->e12244 + a->r * b->e12244;
          res->e22244 = c->e22244 + a->r * b->e22244;
          res->e11344 = c->e11344 + a->r * b->e11344;
          res->e12344 = c->e12344 + a->r * b->e12344;
          res->e22344 = c->e22344 + a->r * b->e22344;
          res->e13344 = c->e13344 + a->r * b->e13344;
          res->e23344 = c->e23344 + a->r * b->e23344;
          res->e33344 = c->e33344 + a->r * b->e33344;
          res->e11444 = c->e11444 + a->r * b->e11444;
          res->e12444 = c->e12444 + a->r * b->e12444;
          res->e22444 = c->e22444 + a->r * b->e22444;
          res->e13444 = c->e13444 + a->r * b->e13444;
          res->e23444 = c->e23444 + a->r * b->e23444;
          res->e33444 = c->e33444 + a->r * b->e33444;
          res->e14444 = c->e14444 + a->r * b->e14444;
          res->e24444 = c->e24444 + a->r * b->e24444;
          res->e34444 = c->e34444 + a->r * b->e34444;
          res->e44444 = c->e44444 + a->r * b->e44444;
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
          res->e1114 = c->e1114 + a->e1 * b->e114 + a->e4 * b->e111;
          res->e1124 = c->e1124 + a->e1 * b->e124 + a->e2 * b->e114 
                     + a->e4 * b->e112;
          res->e1224 = c->e1224 + a->e1 * b->e224 + a->e2 * b->e124 
                     + a->e4 * b->e122;
          res->e2224 = c->e2224 + a->e2 * b->e224 + a->e4 * b->e222;
          res->e1134 = c->e1134 + a->e1 * b->e134 + a->e3 * b->e114 
                     + a->e4 * b->e113;
          res->e1234 = c->e1234 + a->e1 * b->e234 + a->e2 * b->e134 
                     + a->e3 * b->e124 + a->e4 * b->e123;
          res->e2234 = c->e2234 + a->e2 * b->e234 + a->e3 * b->e224 
                     + a->e4 * b->e223;
          res->e1334 = c->e1334 + a->e1 * b->e334 + a->e3 * b->e134 
                     + a->e4 * b->e133;
          res->e2334 = c->e2334 + a->e2 * b->e334 + a->e3 * b->e234 
                     + a->e4 * b->e233;
          res->e3334 = c->e3334 + a->e3 * b->e334 + a->e4 * b->e333;
          res->e1144 = c->e1144 + a->e1 * b->e144 + a->e4 * b->e114;
          res->e1244 = c->e1244 + a->e1 * b->e244 + a->e2 * b->e144 
                     + a->e4 * b->e124;
          res->e2244 = c->e2244 + a->e2 * b->e244 + a->e4 * b->e224;
          res->e1344 = c->e1344 + a->e1 * b->e344 + a->e3 * b->e144 
                     + a->e4 * b->e134;
          res->e2344 = c->e2344 + a->e2 * b->e344 + a->e3 * b->e244 
                     + a->e4 * b->e234;
          res->e3344 = c->e3344 + a->e3 * b->e344 + a->e4 * b->e334;
          res->e1444 = c->e1444 + a->e1 * b->e444 + a->e4 * b->e144;
          res->e2444 = c->e2444 + a->e2 * b->e444 + a->e4 * b->e244;
          res->e3444 = c->e3444 + a->e3 * b->e444 + a->e4 * b->e344;
          res->e4444 = c->e4444 + a->e4 * b->e444;
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
          res->e11114 = c->e11114 + a->e1 * b->e1114 + a->e4 * b->e1111;
          res->e11124 = c->e11124 + a->e1 * b->e1124 + a->e2 * b->e1114 
                      + a->e4 * b->e1112;
          res->e11224 = c->e11224 + a->e1 * b->e1224 + a->e2 * b->e1124 
                      + a->e4 * b->e1122;
          res->e12224 = c->e12224 + a->e1 * b->e2224 + a->e2 * b->e1224 
                      + a->e4 * b->e1222;
          res->e22224 = c->e22224 + a->e2 * b->e2224 + a->e4 * b->e2222;
          res->e11134 = c->e11134 + a->e1 * b->e1134 + a->e3 * b->e1114 
                      + a->e4 * b->e1113;
          res->e11234 = c->e11234 + a->e1 * b->e1234 + a->e2 * b->e1134 
                      + a->e3 * b->e1124 + a->e4 * b->e1123;
          res->e12234 = c->e12234 + a->e1 * b->e2234 + a->e2 * b->e1234 
                      + a->e3 * b->e1224 + a->e4 * b->e1223;
          res->e22234 = c->e22234 + a->e2 * b->e2234 + a->e3 * b->e2224 
                      + a->e4 * b->e2223;
          res->e11334 = c->e11334 + a->e1 * b->e1334 + a->e3 * b->e1134 
                      + a->e4 * b->e1133;
          res->e12334 = c->e12334 + a->e1 * b->e2334 + a->e2 * b->e1334 
                      + a->e3 * b->e1234 + a->e4 * b->e1233;
          res->e22334 = c->e22334 + a->e2 * b->e2334 + a->e3 * b->e2234 
                      + a->e4 * b->e2233;
          res->e13334 = c->e13334 + a->e1 * b->e3334 + a->e3 * b->e1334 
                      + a->e4 * b->e1333;
          res->e23334 = c->e23334 + a->e2 * b->e3334 + a->e3 * b->e2334 
                      + a->e4 * b->e2333;
          res->e33334 = c->e33334 + a->e3 * b->e3334 + a->e4 * b->e3333;
          res->e11144 = c->e11144 + a->e1 * b->e1144 + a->e4 * b->e1114;
          res->e11244 = c->e11244 + a->e1 * b->e1244 + a->e2 * b->e1144 
                      + a->e4 * b->e1124;
          res->e12244 = c->e12244 + a->e1 * b->e2244 + a->e2 * b->e1244 
                      + a->e4 * b->e1224;
          res->e22244 = c->e22244 + a->e2 * b->e2244 + a->e4 * b->e2224;
          res->e11344 = c->e11344 + a->e1 * b->e1344 + a->e3 * b->e1144 
                      + a->e4 * b->e1134;
          res->e12344 = c->e12344 + a->e1 * b->e2344 + a->e2 * b->e1344 
                      + a->e3 * b->e1244 + a->e4 * b->e1234;
          res->e22344 = c->e22344 + a->e2 * b->e2344 + a->e3 * b->e2244 
                      + a->e4 * b->e2234;
          res->e13344 = c->e13344 + a->e1 * b->e3344 + a->e3 * b->e1344 
                      + a->e4 * b->e1334;
          res->e23344 = c->e23344 + a->e2 * b->e3344 + a->e3 * b->e2344 
                      + a->e4 * b->e2334;
          res->e33344 = c->e33344 + a->e3 * b->e3344 + a->e4 * b->e3334;
          res->e11444 = c->e11444 + a->e1 * b->e1444 + a->e4 * b->e1144;
          res->e12444 = c->e12444 + a->e1 * b->e2444 + a->e2 * b->e1444 
                      + a->e4 * b->e1244;
          res->e22444 = c->e22444 + a->e2 * b->e2444 + a->e4 * b->e2244;
          res->e13444 = c->e13444 + a->e1 * b->e3444 + a->e3 * b->e1444 
                      + a->e4 * b->e1344;
          res->e23444 = c->e23444 + a->e2 * b->e3444 + a->e3 * b->e2444 
                      + a->e4 * b->e2344;
          res->e33444 = c->e33444 + a->e3 * b->e3444 + a->e4 * b->e3344;
          res->e14444 = c->e14444 + a->e1 * b->e4444 + a->e4 * b->e1444;
          res->e24444 = c->e24444 + a->e2 * b->e4444 + a->e4 * b->e2444;
          res->e34444 = c->e34444 + a->e3 * b->e4444 + a->e4 * b->e3444;
          res->e44444 = c->e44444 + a->e4 * b->e4444;
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
          res->e1114 = c->e1114 + a->e11 * b->e14 + a->e14 * b->e11;
          res->e1124 = c->e1124 + a->e11 * b->e24 + a->e12 * b->e14 
                     + a->e14 * b->e12 + a->e24 * b->e11;
          res->e1224 = c->e1224 + a->e12 * b->e24 + a->e22 * b->e14 
                     + a->e14 * b->e22 + a->e24 * b->e12;
          res->e2224 = c->e2224 + a->e22 * b->e24 + a->e24 * b->e22;
          res->e1134 = c->e1134 + a->e11 * b->e34 + a->e13 * b->e14 
                     + a->e14 * b->e13 + a->e34 * b->e11;
          res->e1234 = c->e1234 + a->e12 * b->e34 + a->e13 * b->e24 
                     + a->e23 * b->e14 + a->e14 * b->e23 + a->e24 * b->e13 
                     + a->e34 * b->e12;
          res->e2234 = c->e2234 + a->e22 * b->e34 + a->e23 * b->e24 
                     + a->e24 * b->e23 + a->e34 * b->e22;
          res->e1334 = c->e1334 + a->e13 * b->e34 + a->e33 * b->e14 
                     + a->e14 * b->e33 + a->e34 * b->e13;
          res->e2334 = c->e2334 + a->e23 * b->e34 + a->e33 * b->e24 
                     + a->e24 * b->e33 + a->e34 * b->e23;
          res->e3334 = c->e3334 + a->e33 * b->e34 + a->e34 * b->e33;
          res->e1144 = c->e1144 + a->e11 * b->e44 + a->e14 * b->e14 
                     + a->e44 * b->e11;
          res->e1244 = c->e1244 + a->e12 * b->e44 + a->e14 * b->e24 
                     + a->e24 * b->e14 + a->e44 * b->e12;
          res->e2244 = c->e2244 + a->e22 * b->e44 + a->e24 * b->e24 
                     + a->e44 * b->e22;
          res->e1344 = c->e1344 + a->e13 * b->e44 + a->e14 * b->e34 
                     + a->e34 * b->e14 + a->e44 * b->e13;
          res->e2344 = c->e2344 + a->e23 * b->e44 + a->e24 * b->e34 
                     + a->e34 * b->e24 + a->e44 * b->e23;
          res->e3344 = c->e3344 + a->e33 * b->e44 + a->e34 * b->e34 
                     + a->e44 * b->e33;
          res->e1444 = c->e1444 + a->e14 * b->e44 + a->e44 * b->e14;
          res->e2444 = c->e2444 + a->e24 * b->e44 + a->e44 * b->e24;
          res->e3444 = c->e3444 + a->e34 * b->e44 + a->e44 * b->e34;
          res->e4444 = c->e4444 + a->e44 * b->e44;
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
          res->e11114 = c->e11114 + a->e11 * b->e114 + a->e14 * b->e111;
          res->e11124 = c->e11124 + a->e11 * b->e124 + a->e12 * b->e114 
                      + a->e14 * b->e112 + a->e24 * b->e111;
          res->e11224 = c->e11224 + a->e11 * b->e224 + a->e12 * b->e124 
                      + a->e22 * b->e114 + a->e14 * b->e122 + a->e24 * b->e112;
          res->e12224 = c->e12224 + a->e12 * b->e224 + a->e22 * b->e124 
                      + a->e14 * b->e222 + a->e24 * b->e122;
          res->e22224 = c->e22224 + a->e22 * b->e224 + a->e24 * b->e222;
          res->e11134 = c->e11134 + a->e11 * b->e134 + a->e13 * b->e114 
                      + a->e14 * b->e113 + a->e34 * b->e111;
          res->e11234 = c->e11234 + a->e11 * b->e234 + a->e12 * b->e134 
                      + a->e13 * b->e124 + a->e23 * b->e114 + a->e14 * b->e123 
                      + a->e24 * b->e113 + a->e34 * b->e112;
          res->e12234 = c->e12234 + a->e12 * b->e234 + a->e22 * b->e134 
                      + a->e13 * b->e224 + a->e23 * b->e124 + a->e14 * b->e223 
                      + a->e24 * b->e123 + a->e34 * b->e122;
          res->e22234 = c->e22234 + a->e22 * b->e234 + a->e23 * b->e224 
                      + a->e24 * b->e223 + a->e34 * b->e222;
          res->e11334 = c->e11334 + a->e11 * b->e334 + a->e13 * b->e134 
                      + a->e33 * b->e114 + a->e14 * b->e133 + a->e34 * b->e113;
          res->e12334 = c->e12334 + a->e12 * b->e334 + a->e13 * b->e234 
                      + a->e23 * b->e134 + a->e33 * b->e124 + a->e14 * b->e233 
                      + a->e24 * b->e133 + a->e34 * b->e123;
          res->e22334 = c->e22334 + a->e22 * b->e334 + a->e23 * b->e234 
                      + a->e33 * b->e224 + a->e24 * b->e233 + a->e34 * b->e223;
          res->e13334 = c->e13334 + a->e13 * b->e334 + a->e33 * b->e134 
                      + a->e14 * b->e333 + a->e34 * b->e133;
          res->e23334 = c->e23334 + a->e23 * b->e334 + a->e33 * b->e234 
                      + a->e24 * b->e333 + a->e34 * b->e233;
          res->e33334 = c->e33334 + a->e33 * b->e334 + a->e34 * b->e333;
          res->e11144 = c->e11144 + a->e11 * b->e144 + a->e14 * b->e114 
                      + a->e44 * b->e111;
          res->e11244 = c->e11244 + a->e11 * b->e244 + a->e12 * b->e144 
                      + a->e14 * b->e124 + a->e24 * b->e114 + a->e44 * b->e112;
          res->e12244 = c->e12244 + a->e12 * b->e244 + a->e22 * b->e144 
                      + a->e14 * b->e224 + a->e24 * b->e124 + a->e44 * b->e122;
          res->e22244 = c->e22244 + a->e22 * b->e244 + a->e24 * b->e224 
                      + a->e44 * b->e222;
          res->e11344 = c->e11344 + a->e11 * b->e344 + a->e13 * b->e144 
                      + a->e14 * b->e134 + a->e34 * b->e114 + a->e44 * b->e113;
          res->e12344 = c->e12344 + a->e12 * b->e344 + a->e13 * b->e244 
                      + a->e23 * b->e144 + a->e14 * b->e234 + a->e24 * b->e134 
                      + a->e34 * b->e124 + a->e44 * b->e123;
          res->e22344 = c->e22344 + a->e22 * b->e344 + a->e23 * b->e244 
                      + a->e24 * b->e234 + a->e34 * b->e224 + a->e44 * b->e223;
          res->e13344 = c->e13344 + a->e13 * b->e344 + a->e33 * b->e144 
                      + a->e14 * b->e334 + a->e34 * b->e134 + a->e44 * b->e133;
          res->e23344 = c->e23344 + a->e23 * b->e344 + a->e33 * b->e244 
                      + a->e24 * b->e334 + a->e34 * b->e234 + a->e44 * b->e233;
          res->e33344 = c->e33344 + a->e33 * b->e344 + a->e34 * b->e334 
                      + a->e44 * b->e333;
          res->e11444 = c->e11444 + a->e11 * b->e444 + a->e14 * b->e144 
                      + a->e44 * b->e114;
          res->e12444 = c->e12444 + a->e12 * b->e444 + a->e14 * b->e244 
                      + a->e24 * b->e144 + a->e44 * b->e124;
          res->e22444 = c->e22444 + a->e22 * b->e444 + a->e24 * b->e244 
                      + a->e44 * b->e224;
          res->e13444 = c->e13444 + a->e13 * b->e444 + a->e14 * b->e344 
                      + a->e34 * b->e144 + a->e44 * b->e134;
          res->e23444 = c->e23444 + a->e23 * b->e444 + a->e24 * b->e344 
                      + a->e34 * b->e244 + a->e44 * b->e234;
          res->e33444 = c->e33444 + a->e33 * b->e444 + a->e34 * b->e344 
                      + a->e44 * b->e334;
          res->e14444 = c->e14444 + a->e14 * b->e444 + a->e44 * b->e144;
          res->e24444 = c->e24444 + a->e24 * b->e444 + a->e44 * b->e244;
          res->e34444 = c->e34444 + a->e34 * b->e444 + a->e44 * b->e344;
          res->e44444 = c->e44444 + a->e44 * b->e444;
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
          res->e1114 = c->e1114 + a->e114 * b->e1 + a->e111 * b->e4;
          res->e1124 = c->e1124 + a->e124 * b->e1 + a->e114 * b->e2 
                     + a->e112 * b->e4;
          res->e1224 = c->e1224 + a->e224 * b->e1 + a->e124 * b->e2 
                     + a->e122 * b->e4;
          res->e2224 = c->e2224 + a->e224 * b->e2 + a->e222 * b->e4;
          res->e1134 = c->e1134 + a->e134 * b->e1 + a->e114 * b->e3 
                     + a->e113 * b->e4;
          res->e1234 = c->e1234 + a->e234 * b->e1 + a->e134 * b->e2 
                     + a->e124 * b->e3 + a->e123 * b->e4;
          res->e2234 = c->e2234 + a->e234 * b->e2 + a->e224 * b->e3 
                     + a->e223 * b->e4;
          res->e1334 = c->e1334 + a->e334 * b->e1 + a->e134 * b->e3 
                     + a->e133 * b->e4;
          res->e2334 = c->e2334 + a->e334 * b->e2 + a->e234 * b->e3 
                     + a->e233 * b->e4;
          res->e3334 = c->e3334 + a->e334 * b->e3 + a->e333 * b->e4;
          res->e1144 = c->e1144 + a->e144 * b->e1 + a->e114 * b->e4;
          res->e1244 = c->e1244 + a->e244 * b->e1 + a->e144 * b->e2 
                     + a->e124 * b->e4;
          res->e2244 = c->e2244 + a->e244 * b->e2 + a->e224 * b->e4;
          res->e1344 = c->e1344 + a->e344 * b->e1 + a->e144 * b->e3 
                     + a->e134 * b->e4;
          res->e2344 = c->e2344 + a->e344 * b->e2 + a->e244 * b->e3 
                     + a->e234 * b->e4;
          res->e3344 = c->e3344 + a->e344 * b->e3 + a->e334 * b->e4;
          res->e1444 = c->e1444 + a->e444 * b->e1 + a->e144 * b->e4;
          res->e2444 = c->e2444 + a->e444 * b->e2 + a->e244 * b->e4;
          res->e3444 = c->e3444 + a->e444 * b->e3 + a->e344 * b->e4;
          res->e4444 = c->e4444 + a->e444 * b->e4;
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
          res->e11114 = c->e11114 + a->e114 * b->e11 + a->e111 * b->e14;
          res->e11124 = c->e11124 + a->e124 * b->e11 + a->e114 * b->e12 
                      + a->e112 * b->e14 + a->e111 * b->e24;
          res->e11224 = c->e11224 + a->e224 * b->e11 + a->e124 * b->e12 
                      + a->e114 * b->e22 + a->e122 * b->e14 + a->e112 * b->e24;
          res->e12224 = c->e12224 + a->e224 * b->e12 + a->e124 * b->e22 
                      + a->e222 * b->e14 + a->e122 * b->e24;
          res->e22224 = c->e22224 + a->e224 * b->e22 + a->e222 * b->e24;
          res->e11134 = c->e11134 + a->e134 * b->e11 + a->e114 * b->e13 
                      + a->e113 * b->e14 + a->e111 * b->e34;
          res->e11234 = c->e11234 + a->e234 * b->e11 + a->e134 * b->e12 
                      + a->e124 * b->e13 + a->e114 * b->e23 + a->e123 * b->e14 
                      + a->e113 * b->e24 + a->e112 * b->e34;
          res->e12234 = c->e12234 + a->e234 * b->e12 + a->e134 * b->e22 
                      + a->e224 * b->e13 + a->e124 * b->e23 + a->e223 * b->e14 
                      + a->e123 * b->e24 + a->e122 * b->e34;
          res->e22234 = c->e22234 + a->e234 * b->e22 + a->e224 * b->e23 
                      + a->e223 * b->e24 + a->e222 * b->e34;
          res->e11334 = c->e11334 + a->e334 * b->e11 + a->e134 * b->e13 
                      + a->e114 * b->e33 + a->e133 * b->e14 + a->e113 * b->e34;
          res->e12334 = c->e12334 + a->e334 * b->e12 + a->e234 * b->e13 
                      + a->e134 * b->e23 + a->e124 * b->e33 + a->e233 * b->e14 
                      + a->e133 * b->e24 + a->e123 * b->e34;
          res->e22334 = c->e22334 + a->e334 * b->e22 + a->e234 * b->e23 
                      + a->e224 * b->e33 + a->e233 * b->e24 + a->e223 * b->e34;
          res->e13334 = c->e13334 + a->e334 * b->e13 + a->e134 * b->e33 
                      + a->e333 * b->e14 + a->e133 * b->e34;
          res->e23334 = c->e23334 + a->e334 * b->e23 + a->e234 * b->e33 
                      + a->e333 * b->e24 + a->e233 * b->e34;
          res->e33334 = c->e33334 + a->e334 * b->e33 + a->e333 * b->e34;
          res->e11144 = c->e11144 + a->e144 * b->e11 + a->e114 * b->e14 
                      + a->e111 * b->e44;
          res->e11244 = c->e11244 + a->e244 * b->e11 + a->e144 * b->e12 
                      + a->e124 * b->e14 + a->e114 * b->e24 + a->e112 * b->e44;
          res->e12244 = c->e12244 + a->e244 * b->e12 + a->e144 * b->e22 
                      + a->e224 * b->e14 + a->e124 * b->e24 + a->e122 * b->e44;
          res->e22244 = c->e22244 + a->e244 * b->e22 + a->e224 * b->e24 
                      + a->e222 * b->e44;
          res->e11344 = c->e11344 + a->e344 * b->e11 + a->e144 * b->e13 
                      + a->e134 * b->e14 + a->e114 * b->e34 + a->e113 * b->e44;
          res->e12344 = c->e12344 + a->e344 * b->e12 + a->e244 * b->e13 
                      + a->e144 * b->e23 + a->e234 * b->e14 + a->e134 * b->e24 
                      + a->e124 * b->e34 + a->e123 * b->e44;
          res->e22344 = c->e22344 + a->e344 * b->e22 + a->e244 * b->e23 
                      + a->e234 * b->e24 + a->e224 * b->e34 + a->e223 * b->e44;
          res->e13344 = c->e13344 + a->e344 * b->e13 + a->e144 * b->e33 
                      + a->e334 * b->e14 + a->e134 * b->e34 + a->e133 * b->e44;
          res->e23344 = c->e23344 + a->e344 * b->e23 + a->e244 * b->e33 
                      + a->e334 * b->e24 + a->e234 * b->e34 + a->e233 * b->e44;
          res->e33344 = c->e33344 + a->e344 * b->e33 + a->e334 * b->e34 
                      + a->e333 * b->e44;
          res->e11444 = c->e11444 + a->e444 * b->e11 + a->e144 * b->e14 
                      + a->e114 * b->e44;
          res->e12444 = c->e12444 + a->e444 * b->e12 + a->e244 * b->e14 
                      + a->e144 * b->e24 + a->e124 * b->e44;
          res->e22444 = c->e22444 + a->e444 * b->e22 + a->e244 * b->e24 
                      + a->e224 * b->e44;
          res->e13444 = c->e13444 + a->e444 * b->e13 + a->e344 * b->e14 
                      + a->e144 * b->e34 + a->e134 * b->e44;
          res->e23444 = c->e23444 + a->e444 * b->e23 + a->e344 * b->e24 
                      + a->e244 * b->e34 + a->e234 * b->e44;
          res->e33444 = c->e33444 + a->e444 * b->e33 + a->e344 * b->e34 
                      + a->e334 * b->e44;
          res->e14444 = c->e14444 + a->e444 * b->e14 + a->e144 * b->e44;
          res->e24444 = c->e24444 + a->e444 * b->e24 + a->e244 * b->e44;
          res->e34444 = c->e34444 + a->e444 * b->e34 + a->e344 * b->e44;
          res->e44444 = c->e44444 + a->e444 * b->e44;
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
          res->e1114 = c->e1114 + a->e1114 * b->r;
          res->e1124 = c->e1124 + a->e1124 * b->r;
          res->e1224 = c->e1224 + a->e1224 * b->r;
          res->e2224 = c->e2224 + a->e2224 * b->r;
          res->e1134 = c->e1134 + a->e1134 * b->r;
          res->e1234 = c->e1234 + a->e1234 * b->r;
          res->e2234 = c->e2234 + a->e2234 * b->r;
          res->e1334 = c->e1334 + a->e1334 * b->r;
          res->e2334 = c->e2334 + a->e2334 * b->r;
          res->e3334 = c->e3334 + a->e3334 * b->r;
          res->e1144 = c->e1144 + a->e1144 * b->r;
          res->e1244 = c->e1244 + a->e1244 * b->r;
          res->e2244 = c->e2244 + a->e2244 * b->r;
          res->e1344 = c->e1344 + a->e1344 * b->r;
          res->e2344 = c->e2344 + a->e2344 * b->r;
          res->e3344 = c->e3344 + a->e3344 * b->r;
          res->e1444 = c->e1444 + a->e1444 * b->r;
          res->e2444 = c->e2444 + a->e2444 * b->r;
          res->e3444 = c->e3444 + a->e3444 * b->r;
          res->e4444 = c->e4444 + a->e4444 * b->r;
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
          res->e11114 = c->e11114 + a->e1114 * b->e1 + a->e1111 * b->e4;
          res->e11124 = c->e11124 + a->e1124 * b->e1 + a->e1114 * b->e2 
                      + a->e1112 * b->e4;
          res->e11224 = c->e11224 + a->e1224 * b->e1 + a->e1124 * b->e2 
                      + a->e1122 * b->e4;
          res->e12224 = c->e12224 + a->e2224 * b->e1 + a->e1224 * b->e2 
                      + a->e1222 * b->e4;
          res->e22224 = c->e22224 + a->e2224 * b->e2 + a->e2222 * b->e4;
          res->e11134 = c->e11134 + a->e1134 * b->e1 + a->e1114 * b->e3 
                      + a->e1113 * b->e4;
          res->e11234 = c->e11234 + a->e1234 * b->e1 + a->e1134 * b->e2 
                      + a->e1124 * b->e3 + a->e1123 * b->e4;
          res->e12234 = c->e12234 + a->e2234 * b->e1 + a->e1234 * b->e2 
                      + a->e1224 * b->e3 + a->e1223 * b->e4;
          res->e22234 = c->e22234 + a->e2234 * b->e2 + a->e2224 * b->e3 
                      + a->e2223 * b->e4;
          res->e11334 = c->e11334 + a->e1334 * b->e1 + a->e1134 * b->e3 
                      + a->e1133 * b->e4;
          res->e12334 = c->e12334 + a->e2334 * b->e1 + a->e1334 * b->e2 
                      + a->e1234 * b->e3 + a->e1233 * b->e4;
          res->e22334 = c->e22334 + a->e2334 * b->e2 + a->e2234 * b->e3 
                      + a->e2233 * b->e4;
          res->e13334 = c->e13334 + a->e3334 * b->e1 + a->e1334 * b->e3 
                      + a->e1333 * b->e4;
          res->e23334 = c->e23334 + a->e3334 * b->e2 + a->e2334 * b->e3 
                      + a->e2333 * b->e4;
          res->e33334 = c->e33334 + a->e3334 * b->e3 + a->e3333 * b->e4;
          res->e11144 = c->e11144 + a->e1144 * b->e1 + a->e1114 * b->e4;
          res->e11244 = c->e11244 + a->e1244 * b->e1 + a->e1144 * b->e2 
                      + a->e1124 * b->e4;
          res->e12244 = c->e12244 + a->e2244 * b->e1 + a->e1244 * b->e2 
                      + a->e1224 * b->e4;
          res->e22244 = c->e22244 + a->e2244 * b->e2 + a->e2224 * b->e4;
          res->e11344 = c->e11344 + a->e1344 * b->e1 + a->e1144 * b->e3 
                      + a->e1134 * b->e4;
          res->e12344 = c->e12344 + a->e2344 * b->e1 + a->e1344 * b->e2 
                      + a->e1244 * b->e3 + a->e1234 * b->e4;
          res->e22344 = c->e22344 + a->e2344 * b->e2 + a->e2244 * b->e3 
                      + a->e2234 * b->e4;
          res->e13344 = c->e13344 + a->e3344 * b->e1 + a->e1344 * b->e3 
                      + a->e1334 * b->e4;
          res->e23344 = c->e23344 + a->e3344 * b->e2 + a->e2344 * b->e3 
                      + a->e2334 * b->e4;
          res->e33344 = c->e33344 + a->e3344 * b->e3 + a->e3334 * b->e4;
          res->e11444 = c->e11444 + a->e1444 * b->e1 + a->e1144 * b->e4;
          res->e12444 = c->e12444 + a->e2444 * b->e1 + a->e1444 * b->e2 
                      + a->e1244 * b->e4;
          res->e22444 = c->e22444 + a->e2444 * b->e2 + a->e2244 * b->e4;
          res->e13444 = c->e13444 + a->e3444 * b->e1 + a->e1444 * b->e3 
                      + a->e1344 * b->e4;
          res->e23444 = c->e23444 + a->e3444 * b->e2 + a->e2444 * b->e3 
                      + a->e2344 * b->e4;
          res->e33444 = c->e33444 + a->e3444 * b->e3 + a->e3344 * b->e4;
          res->e14444 = c->e14444 + a->e4444 * b->e1 + a->e1444 * b->e4;
          res->e24444 = c->e24444 + a->e4444 * b->e2 + a->e2444 * b->e4;
          res->e34444 = c->e34444 + a->e4444 * b->e3 + a->e3444 * b->e4;
          res->e44444 = c->e44444 + a->e4444 * b->e4;
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
          res->e11114 = c->e11114 + a->e11114 * b->r;
          res->e11124 = c->e11124 + a->e11124 * b->r;
          res->e11224 = c->e11224 + a->e11224 * b->r;
          res->e12224 = c->e12224 + a->e12224 * b->r;
          res->e22224 = c->e22224 + a->e22224 * b->r;
          res->e11134 = c->e11134 + a->e11134 * b->r;
          res->e11234 = c->e11234 + a->e11234 * b->r;
          res->e12234 = c->e12234 + a->e12234 * b->r;
          res->e22234 = c->e22234 + a->e22234 * b->r;
          res->e11334 = c->e11334 + a->e11334 * b->r;
          res->e12334 = c->e12334 + a->e12334 * b->r;
          res->e22334 = c->e22334 + a->e22334 * b->r;
          res->e13334 = c->e13334 + a->e13334 * b->r;
          res->e23334 = c->e23334 + a->e23334 * b->r;
          res->e33334 = c->e33334 + a->e33334 * b->r;
          res->e11144 = c->e11144 + a->e11144 * b->r;
          res->e11244 = c->e11244 + a->e11244 * b->r;
          res->e12244 = c->e12244 + a->e12244 * b->r;
          res->e22244 = c->e22244 + a->e22244 * b->r;
          res->e11344 = c->e11344 + a->e11344 * b->r;
          res->e12344 = c->e12344 + a->e12344 * b->r;
          res->e22344 = c->e22344 + a->e22344 * b->r;
          res->e13344 = c->e13344 + a->e13344 * b->r;
          res->e23344 = c->e23344 + a->e23344 * b->r;
          res->e33344 = c->e33344 + a->e33344 * b->r;
          res->e11444 = c->e11444 + a->e11444 * b->r;
          res->e12444 = c->e12444 + a->e12444 * b->r;
          res->e22444 = c->e22444 + a->e22444 * b->r;
          res->e13444 = c->e13444 + a->e13444 * b->r;
          res->e23444 = c->e23444 + a->e23444 * b->r;
          res->e33444 = c->e33444 + a->e33444 * b->r;
          res->e14444 = c->e14444 + a->e14444 * b->r;
          res->e24444 = c->e24444 + a->e24444 * b->r;
          res->e34444 = c->e34444 + a->e34444 * b->r;
          res->e44444 = c->e44444 + a->e44444 * b->r;
          break;
      }
      break;
  }

}

onumm4n5_t onumm4n5_feval(coeff_t* feval_re, onumm4n5_t* x){

  onumm4n5_t res;

  // feval function
  //  Definitions
  coeff_t factor=1, coef = 0;
  onumm4n5_t deltax = (*x), deltax_power = (*x);
  deltax.r = 0.0;
  deltax_power.r = 0.0;
  onumm4n5_set_r(0.0, &res);
  //  Real
  res.r = feval_re[0];
  // Order 1
  factor *=1;
  coef    = feval_re[1]/ factor;;
  onumm4n5_gem_ro_to( coef, &deltax_power, &res, &res);
  deltax_power = onumm4n5_mul_oo(&deltax_power,&deltax);
  // Order 2
  factor *=2;
  coef    = feval_re[2]/ factor;;
  onumm4n5_gem_ro_to( coef, &deltax_power, &res, &res);
  deltax_power = onumm4n5_mul_oo(&deltax_power,&deltax);
  // Order 3
  factor *=3;
  coef    = feval_re[3]/ factor;;
  onumm4n5_gem_ro_to( coef, &deltax_power, &res, &res);
  deltax_power = onumm4n5_mul_oo(&deltax_power,&deltax);
  // Order 4
  factor *=4;
  coef    = feval_re[4]/ factor;;
  onumm4n5_gem_ro_to( coef, &deltax_power, &res, &res);
  deltax_power = onumm4n5_mul_oo(&deltax_power,&deltax);
  // Order 5
  factor *=5;
  coef    = feval_re[5]/ factor;;
  onumm4n5_gem_ro_to( coef, &deltax_power, &res, &res);

  return res;

}

void onumm4n5_feval_to(coeff_t* feval_re, onumm4n5_t* x, onumm4n5_t* res){

  // feval function
  //  Definitions
  coeff_t factor=1, coef = 0;
  onumm4n5_t deltax = (*x), deltax_power = (*x);
  deltax.r = 0.0;
  deltax_power.r = 0.0;
  onumm4n5_set_r(0.0, res);
  //  Real
  res->r = feval_re[0];
  // Order 1
  factor *=1;
  coef    = feval_re[1]/ factor;;
  onumm4n5_gem_ro_to( coef, &deltax_power, res, res);
  deltax_power = onumm4n5_mul_oo(&deltax_power,&deltax);
  // Order 2
  factor *=2;
  coef    = feval_re[2]/ factor;;
  onumm4n5_gem_ro_to( coef, &deltax_power, res, res);
  deltax_power = onumm4n5_mul_oo(&deltax_power,&deltax);
  // Order 3
  factor *=3;
  coef    = feval_re[3]/ factor;;
  onumm4n5_gem_ro_to( coef, &deltax_power, res, res);
  deltax_power = onumm4n5_mul_oo(&deltax_power,&deltax);
  // Order 4
  factor *=4;
  coef    = feval_re[4]/ factor;;
  onumm4n5_gem_ro_to( coef, &deltax_power, res, res);
  deltax_power = onumm4n5_mul_oo(&deltax_power,&deltax);
  // Order 5
  factor *=5;
  coef    = feval_re[5]/ factor;;
  onumm4n5_gem_ro_to( coef, &deltax_power, res, res);

}

