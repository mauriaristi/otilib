
// Division.

// ****************************************************************************************************
onumm5n5_t onumm5n5_div_ro(coeff_t num, onumm5n5_t* den){

    
    onumm5n5_t inv = onumm5n5_pow(den,-1);
    onumm5n5_t res = onumm5n5_mul_ro(num,&inv);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
onumm5n5_t onumm5n5_div_oo(onumm5n5_t* num, onumm5n5_t* den){

    
    onumm5n5_t inv = onumm5n5_init();
    onumm5n5_pow_to(den,-1,&inv);
    onumm5n5_t res = onumm5n5_mul_oo(num,&inv);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
onumm5n5_t onumm5n5_div_or(onumm5n5_t* num, coeff_t val){

    return onumm5n5_mul_ro(1.0/val,num);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
onumm5n5_t onumm5n5_abs(onumm5n5_t* num){

	onumm5n5_t res;
    onumm5n5_abs_to(num,&res);
    return res;

}
// ----------------------------------------------------------------------------------------------------

onumm5n5_t onumm5n5_neg(  onumm5n5_t* lhs){

  onumm5n5_t res;

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
  res.e1115 = -lhs->e1115;
  res.e1125 = -lhs->e1125;
  res.e1225 = -lhs->e1225;
  res.e2225 = -lhs->e2225;
  res.e1135 = -lhs->e1135;
  res.e1235 = -lhs->e1235;
  res.e2235 = -lhs->e2235;
  res.e1335 = -lhs->e1335;
  res.e2335 = -lhs->e2335;
  res.e3335 = -lhs->e3335;
  res.e1145 = -lhs->e1145;
  res.e1245 = -lhs->e1245;
  res.e2245 = -lhs->e2245;
  res.e1345 = -lhs->e1345;
  res.e2345 = -lhs->e2345;
  res.e3345 = -lhs->e3345;
  res.e1445 = -lhs->e1445;
  res.e2445 = -lhs->e2445;
  res.e3445 = -lhs->e3445;
  res.e4445 = -lhs->e4445;
  res.e1155 = -lhs->e1155;
  res.e1255 = -lhs->e1255;
  res.e2255 = -lhs->e2255;
  res.e1355 = -lhs->e1355;
  res.e2355 = -lhs->e2355;
  res.e3355 = -lhs->e3355;
  res.e1455 = -lhs->e1455;
  res.e2455 = -lhs->e2455;
  res.e3455 = -lhs->e3455;
  res.e4455 = -lhs->e4455;
  res.e1555 = -lhs->e1555;
  res.e2555 = -lhs->e2555;
  res.e3555 = -lhs->e3555;
  res.e4555 = -lhs->e4555;
  res.e5555 = -lhs->e5555;
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
  res.e11115 = -lhs->e11115;
  res.e11125 = -lhs->e11125;
  res.e11225 = -lhs->e11225;
  res.e12225 = -lhs->e12225;
  res.e22225 = -lhs->e22225;
  res.e11135 = -lhs->e11135;
  res.e11235 = -lhs->e11235;
  res.e12235 = -lhs->e12235;
  res.e22235 = -lhs->e22235;
  res.e11335 = -lhs->e11335;
  res.e12335 = -lhs->e12335;
  res.e22335 = -lhs->e22335;
  res.e13335 = -lhs->e13335;
  res.e23335 = -lhs->e23335;
  res.e33335 = -lhs->e33335;
  res.e11145 = -lhs->e11145;
  res.e11245 = -lhs->e11245;
  res.e12245 = -lhs->e12245;
  res.e22245 = -lhs->e22245;
  res.e11345 = -lhs->e11345;
  res.e12345 = -lhs->e12345;
  res.e22345 = -lhs->e22345;
  res.e13345 = -lhs->e13345;
  res.e23345 = -lhs->e23345;
  res.e33345 = -lhs->e33345;
  res.e11445 = -lhs->e11445;
  res.e12445 = -lhs->e12445;
  res.e22445 = -lhs->e22445;
  res.e13445 = -lhs->e13445;
  res.e23445 = -lhs->e23445;
  res.e33445 = -lhs->e33445;
  res.e14445 = -lhs->e14445;
  res.e24445 = -lhs->e24445;
  res.e34445 = -lhs->e34445;
  res.e44445 = -lhs->e44445;
  res.e11155 = -lhs->e11155;
  res.e11255 = -lhs->e11255;
  res.e12255 = -lhs->e12255;
  res.e22255 = -lhs->e22255;
  res.e11355 = -lhs->e11355;
  res.e12355 = -lhs->e12355;
  res.e22355 = -lhs->e22355;
  res.e13355 = -lhs->e13355;
  res.e23355 = -lhs->e23355;
  res.e33355 = -lhs->e33355;
  res.e11455 = -lhs->e11455;
  res.e12455 = -lhs->e12455;
  res.e22455 = -lhs->e22455;
  res.e13455 = -lhs->e13455;
  res.e23455 = -lhs->e23455;
  res.e33455 = -lhs->e33455;
  res.e14455 = -lhs->e14455;
  res.e24455 = -lhs->e24455;
  res.e34455 = -lhs->e34455;
  res.e44455 = -lhs->e44455;
  res.e11555 = -lhs->e11555;
  res.e12555 = -lhs->e12555;
  res.e22555 = -lhs->e22555;
  res.e13555 = -lhs->e13555;
  res.e23555 = -lhs->e23555;
  res.e33555 = -lhs->e33555;
  res.e14555 = -lhs->e14555;
  res.e24555 = -lhs->e24555;
  res.e34555 = -lhs->e34555;
  res.e44555 = -lhs->e44555;
  res.e15555 = -lhs->e15555;
  res.e25555 = -lhs->e25555;
  res.e35555 = -lhs->e35555;
  res.e45555 = -lhs->e45555;
  res.e55555 = -lhs->e55555;

  return res;

}

void onumm5n5_neg_to(  onumm5n5_t* lhs, onumm5n5_t* res){

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
  res->e1115 = -lhs->e1115;
  res->e1125 = -lhs->e1125;
  res->e1225 = -lhs->e1225;
  res->e2225 = -lhs->e2225;
  res->e1135 = -lhs->e1135;
  res->e1235 = -lhs->e1235;
  res->e2235 = -lhs->e2235;
  res->e1335 = -lhs->e1335;
  res->e2335 = -lhs->e2335;
  res->e3335 = -lhs->e3335;
  res->e1145 = -lhs->e1145;
  res->e1245 = -lhs->e1245;
  res->e2245 = -lhs->e2245;
  res->e1345 = -lhs->e1345;
  res->e2345 = -lhs->e2345;
  res->e3345 = -lhs->e3345;
  res->e1445 = -lhs->e1445;
  res->e2445 = -lhs->e2445;
  res->e3445 = -lhs->e3445;
  res->e4445 = -lhs->e4445;
  res->e1155 = -lhs->e1155;
  res->e1255 = -lhs->e1255;
  res->e2255 = -lhs->e2255;
  res->e1355 = -lhs->e1355;
  res->e2355 = -lhs->e2355;
  res->e3355 = -lhs->e3355;
  res->e1455 = -lhs->e1455;
  res->e2455 = -lhs->e2455;
  res->e3455 = -lhs->e3455;
  res->e4455 = -lhs->e4455;
  res->e1555 = -lhs->e1555;
  res->e2555 = -lhs->e2555;
  res->e3555 = -lhs->e3555;
  res->e4555 = -lhs->e4555;
  res->e5555 = -lhs->e5555;
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
  res->e11115 = -lhs->e11115;
  res->e11125 = -lhs->e11125;
  res->e11225 = -lhs->e11225;
  res->e12225 = -lhs->e12225;
  res->e22225 = -lhs->e22225;
  res->e11135 = -lhs->e11135;
  res->e11235 = -lhs->e11235;
  res->e12235 = -lhs->e12235;
  res->e22235 = -lhs->e22235;
  res->e11335 = -lhs->e11335;
  res->e12335 = -lhs->e12335;
  res->e22335 = -lhs->e22335;
  res->e13335 = -lhs->e13335;
  res->e23335 = -lhs->e23335;
  res->e33335 = -lhs->e33335;
  res->e11145 = -lhs->e11145;
  res->e11245 = -lhs->e11245;
  res->e12245 = -lhs->e12245;
  res->e22245 = -lhs->e22245;
  res->e11345 = -lhs->e11345;
  res->e12345 = -lhs->e12345;
  res->e22345 = -lhs->e22345;
  res->e13345 = -lhs->e13345;
  res->e23345 = -lhs->e23345;
  res->e33345 = -lhs->e33345;
  res->e11445 = -lhs->e11445;
  res->e12445 = -lhs->e12445;
  res->e22445 = -lhs->e22445;
  res->e13445 = -lhs->e13445;
  res->e23445 = -lhs->e23445;
  res->e33445 = -lhs->e33445;
  res->e14445 = -lhs->e14445;
  res->e24445 = -lhs->e24445;
  res->e34445 = -lhs->e34445;
  res->e44445 = -lhs->e44445;
  res->e11155 = -lhs->e11155;
  res->e11255 = -lhs->e11255;
  res->e12255 = -lhs->e12255;
  res->e22255 = -lhs->e22255;
  res->e11355 = -lhs->e11355;
  res->e12355 = -lhs->e12355;
  res->e22355 = -lhs->e22355;
  res->e13355 = -lhs->e13355;
  res->e23355 = -lhs->e23355;
  res->e33355 = -lhs->e33355;
  res->e11455 = -lhs->e11455;
  res->e12455 = -lhs->e12455;
  res->e22455 = -lhs->e22455;
  res->e13455 = -lhs->e13455;
  res->e23455 = -lhs->e23455;
  res->e33455 = -lhs->e33455;
  res->e14455 = -lhs->e14455;
  res->e24455 = -lhs->e24455;
  res->e34455 = -lhs->e34455;
  res->e44455 = -lhs->e44455;
  res->e11555 = -lhs->e11555;
  res->e12555 = -lhs->e12555;
  res->e22555 = -lhs->e22555;
  res->e13555 = -lhs->e13555;
  res->e23555 = -lhs->e23555;
  res->e33555 = -lhs->e33555;
  res->e14555 = -lhs->e14555;
  res->e24555 = -lhs->e24555;
  res->e34555 = -lhs->e34555;
  res->e44555 = -lhs->e44555;
  res->e15555 = -lhs->e15555;
  res->e25555 = -lhs->e25555;
  res->e35555 = -lhs->e35555;
  res->e45555 = -lhs->e45555;
  res->e55555 = -lhs->e55555;

}

onumm5n5_t onumm5n5_sum_oo(  onumm5n5_t* lhs,  onumm5n5_t* rhs){
  onumm5n5_t res;

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
  res.e1115 = lhs->e1115 + rhs->e1115;
  res.e1125 = lhs->e1125 + rhs->e1125;
  res.e1225 = lhs->e1225 + rhs->e1225;
  res.e2225 = lhs->e2225 + rhs->e2225;
  res.e1135 = lhs->e1135 + rhs->e1135;
  res.e1235 = lhs->e1235 + rhs->e1235;
  res.e2235 = lhs->e2235 + rhs->e2235;
  res.e1335 = lhs->e1335 + rhs->e1335;
  res.e2335 = lhs->e2335 + rhs->e2335;
  res.e3335 = lhs->e3335 + rhs->e3335;
  res.e1145 = lhs->e1145 + rhs->e1145;
  res.e1245 = lhs->e1245 + rhs->e1245;
  res.e2245 = lhs->e2245 + rhs->e2245;
  res.e1345 = lhs->e1345 + rhs->e1345;
  res.e2345 = lhs->e2345 + rhs->e2345;
  res.e3345 = lhs->e3345 + rhs->e3345;
  res.e1445 = lhs->e1445 + rhs->e1445;
  res.e2445 = lhs->e2445 + rhs->e2445;
  res.e3445 = lhs->e3445 + rhs->e3445;
  res.e4445 = lhs->e4445 + rhs->e4445;
  res.e1155 = lhs->e1155 + rhs->e1155;
  res.e1255 = lhs->e1255 + rhs->e1255;
  res.e2255 = lhs->e2255 + rhs->e2255;
  res.e1355 = lhs->e1355 + rhs->e1355;
  res.e2355 = lhs->e2355 + rhs->e2355;
  res.e3355 = lhs->e3355 + rhs->e3355;
  res.e1455 = lhs->e1455 + rhs->e1455;
  res.e2455 = lhs->e2455 + rhs->e2455;
  res.e3455 = lhs->e3455 + rhs->e3455;
  res.e4455 = lhs->e4455 + rhs->e4455;
  res.e1555 = lhs->e1555 + rhs->e1555;
  res.e2555 = lhs->e2555 + rhs->e2555;
  res.e3555 = lhs->e3555 + rhs->e3555;
  res.e4555 = lhs->e4555 + rhs->e4555;
  res.e5555 = lhs->e5555 + rhs->e5555;
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
  res.e11115 = lhs->e11115 + rhs->e11115;
  res.e11125 = lhs->e11125 + rhs->e11125;
  res.e11225 = lhs->e11225 + rhs->e11225;
  res.e12225 = lhs->e12225 + rhs->e12225;
  res.e22225 = lhs->e22225 + rhs->e22225;
  res.e11135 = lhs->e11135 + rhs->e11135;
  res.e11235 = lhs->e11235 + rhs->e11235;
  res.e12235 = lhs->e12235 + rhs->e12235;
  res.e22235 = lhs->e22235 + rhs->e22235;
  res.e11335 = lhs->e11335 + rhs->e11335;
  res.e12335 = lhs->e12335 + rhs->e12335;
  res.e22335 = lhs->e22335 + rhs->e22335;
  res.e13335 = lhs->e13335 + rhs->e13335;
  res.e23335 = lhs->e23335 + rhs->e23335;
  res.e33335 = lhs->e33335 + rhs->e33335;
  res.e11145 = lhs->e11145 + rhs->e11145;
  res.e11245 = lhs->e11245 + rhs->e11245;
  res.e12245 = lhs->e12245 + rhs->e12245;
  res.e22245 = lhs->e22245 + rhs->e22245;
  res.e11345 = lhs->e11345 + rhs->e11345;
  res.e12345 = lhs->e12345 + rhs->e12345;
  res.e22345 = lhs->e22345 + rhs->e22345;
  res.e13345 = lhs->e13345 + rhs->e13345;
  res.e23345 = lhs->e23345 + rhs->e23345;
  res.e33345 = lhs->e33345 + rhs->e33345;
  res.e11445 = lhs->e11445 + rhs->e11445;
  res.e12445 = lhs->e12445 + rhs->e12445;
  res.e22445 = lhs->e22445 + rhs->e22445;
  res.e13445 = lhs->e13445 + rhs->e13445;
  res.e23445 = lhs->e23445 + rhs->e23445;
  res.e33445 = lhs->e33445 + rhs->e33445;
  res.e14445 = lhs->e14445 + rhs->e14445;
  res.e24445 = lhs->e24445 + rhs->e24445;
  res.e34445 = lhs->e34445 + rhs->e34445;
  res.e44445 = lhs->e44445 + rhs->e44445;
  res.e11155 = lhs->e11155 + rhs->e11155;
  res.e11255 = lhs->e11255 + rhs->e11255;
  res.e12255 = lhs->e12255 + rhs->e12255;
  res.e22255 = lhs->e22255 + rhs->e22255;
  res.e11355 = lhs->e11355 + rhs->e11355;
  res.e12355 = lhs->e12355 + rhs->e12355;
  res.e22355 = lhs->e22355 + rhs->e22355;
  res.e13355 = lhs->e13355 + rhs->e13355;
  res.e23355 = lhs->e23355 + rhs->e23355;
  res.e33355 = lhs->e33355 + rhs->e33355;
  res.e11455 = lhs->e11455 + rhs->e11455;
  res.e12455 = lhs->e12455 + rhs->e12455;
  res.e22455 = lhs->e22455 + rhs->e22455;
  res.e13455 = lhs->e13455 + rhs->e13455;
  res.e23455 = lhs->e23455 + rhs->e23455;
  res.e33455 = lhs->e33455 + rhs->e33455;
  res.e14455 = lhs->e14455 + rhs->e14455;
  res.e24455 = lhs->e24455 + rhs->e24455;
  res.e34455 = lhs->e34455 + rhs->e34455;
  res.e44455 = lhs->e44455 + rhs->e44455;
  res.e11555 = lhs->e11555 + rhs->e11555;
  res.e12555 = lhs->e12555 + rhs->e12555;
  res.e22555 = lhs->e22555 + rhs->e22555;
  res.e13555 = lhs->e13555 + rhs->e13555;
  res.e23555 = lhs->e23555 + rhs->e23555;
  res.e33555 = lhs->e33555 + rhs->e33555;
  res.e14555 = lhs->e14555 + rhs->e14555;
  res.e24555 = lhs->e24555 + rhs->e24555;
  res.e34555 = lhs->e34555 + rhs->e34555;
  res.e44555 = lhs->e44555 + rhs->e44555;
  res.e15555 = lhs->e15555 + rhs->e15555;
  res.e25555 = lhs->e25555 + rhs->e25555;
  res.e35555 = lhs->e35555 + rhs->e35555;
  res.e45555 = lhs->e45555 + rhs->e45555;
  res.e55555 = lhs->e55555 + rhs->e55555;

  return res;

}

void onumm5n5_sum_oo_to(  onumm5n5_t* lhs,  onumm5n5_t* rhs, onumm5n5_t* res){
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
  res->e1115 = lhs->e1115 + rhs->e1115;
  res->e1125 = lhs->e1125 + rhs->e1125;
  res->e1225 = lhs->e1225 + rhs->e1225;
  res->e2225 = lhs->e2225 + rhs->e2225;
  res->e1135 = lhs->e1135 + rhs->e1135;
  res->e1235 = lhs->e1235 + rhs->e1235;
  res->e2235 = lhs->e2235 + rhs->e2235;
  res->e1335 = lhs->e1335 + rhs->e1335;
  res->e2335 = lhs->e2335 + rhs->e2335;
  res->e3335 = lhs->e3335 + rhs->e3335;
  res->e1145 = lhs->e1145 + rhs->e1145;
  res->e1245 = lhs->e1245 + rhs->e1245;
  res->e2245 = lhs->e2245 + rhs->e2245;
  res->e1345 = lhs->e1345 + rhs->e1345;
  res->e2345 = lhs->e2345 + rhs->e2345;
  res->e3345 = lhs->e3345 + rhs->e3345;
  res->e1445 = lhs->e1445 + rhs->e1445;
  res->e2445 = lhs->e2445 + rhs->e2445;
  res->e3445 = lhs->e3445 + rhs->e3445;
  res->e4445 = lhs->e4445 + rhs->e4445;
  res->e1155 = lhs->e1155 + rhs->e1155;
  res->e1255 = lhs->e1255 + rhs->e1255;
  res->e2255 = lhs->e2255 + rhs->e2255;
  res->e1355 = lhs->e1355 + rhs->e1355;
  res->e2355 = lhs->e2355 + rhs->e2355;
  res->e3355 = lhs->e3355 + rhs->e3355;
  res->e1455 = lhs->e1455 + rhs->e1455;
  res->e2455 = lhs->e2455 + rhs->e2455;
  res->e3455 = lhs->e3455 + rhs->e3455;
  res->e4455 = lhs->e4455 + rhs->e4455;
  res->e1555 = lhs->e1555 + rhs->e1555;
  res->e2555 = lhs->e2555 + rhs->e2555;
  res->e3555 = lhs->e3555 + rhs->e3555;
  res->e4555 = lhs->e4555 + rhs->e4555;
  res->e5555 = lhs->e5555 + rhs->e5555;
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
  res->e11115 = lhs->e11115 + rhs->e11115;
  res->e11125 = lhs->e11125 + rhs->e11125;
  res->e11225 = lhs->e11225 + rhs->e11225;
  res->e12225 = lhs->e12225 + rhs->e12225;
  res->e22225 = lhs->e22225 + rhs->e22225;
  res->e11135 = lhs->e11135 + rhs->e11135;
  res->e11235 = lhs->e11235 + rhs->e11235;
  res->e12235 = lhs->e12235 + rhs->e12235;
  res->e22235 = lhs->e22235 + rhs->e22235;
  res->e11335 = lhs->e11335 + rhs->e11335;
  res->e12335 = lhs->e12335 + rhs->e12335;
  res->e22335 = lhs->e22335 + rhs->e22335;
  res->e13335 = lhs->e13335 + rhs->e13335;
  res->e23335 = lhs->e23335 + rhs->e23335;
  res->e33335 = lhs->e33335 + rhs->e33335;
  res->e11145 = lhs->e11145 + rhs->e11145;
  res->e11245 = lhs->e11245 + rhs->e11245;
  res->e12245 = lhs->e12245 + rhs->e12245;
  res->e22245 = lhs->e22245 + rhs->e22245;
  res->e11345 = lhs->e11345 + rhs->e11345;
  res->e12345 = lhs->e12345 + rhs->e12345;
  res->e22345 = lhs->e22345 + rhs->e22345;
  res->e13345 = lhs->e13345 + rhs->e13345;
  res->e23345 = lhs->e23345 + rhs->e23345;
  res->e33345 = lhs->e33345 + rhs->e33345;
  res->e11445 = lhs->e11445 + rhs->e11445;
  res->e12445 = lhs->e12445 + rhs->e12445;
  res->e22445 = lhs->e22445 + rhs->e22445;
  res->e13445 = lhs->e13445 + rhs->e13445;
  res->e23445 = lhs->e23445 + rhs->e23445;
  res->e33445 = lhs->e33445 + rhs->e33445;
  res->e14445 = lhs->e14445 + rhs->e14445;
  res->e24445 = lhs->e24445 + rhs->e24445;
  res->e34445 = lhs->e34445 + rhs->e34445;
  res->e44445 = lhs->e44445 + rhs->e44445;
  res->e11155 = lhs->e11155 + rhs->e11155;
  res->e11255 = lhs->e11255 + rhs->e11255;
  res->e12255 = lhs->e12255 + rhs->e12255;
  res->e22255 = lhs->e22255 + rhs->e22255;
  res->e11355 = lhs->e11355 + rhs->e11355;
  res->e12355 = lhs->e12355 + rhs->e12355;
  res->e22355 = lhs->e22355 + rhs->e22355;
  res->e13355 = lhs->e13355 + rhs->e13355;
  res->e23355 = lhs->e23355 + rhs->e23355;
  res->e33355 = lhs->e33355 + rhs->e33355;
  res->e11455 = lhs->e11455 + rhs->e11455;
  res->e12455 = lhs->e12455 + rhs->e12455;
  res->e22455 = lhs->e22455 + rhs->e22455;
  res->e13455 = lhs->e13455 + rhs->e13455;
  res->e23455 = lhs->e23455 + rhs->e23455;
  res->e33455 = lhs->e33455 + rhs->e33455;
  res->e14455 = lhs->e14455 + rhs->e14455;
  res->e24455 = lhs->e24455 + rhs->e24455;
  res->e34455 = lhs->e34455 + rhs->e34455;
  res->e44455 = lhs->e44455 + rhs->e44455;
  res->e11555 = lhs->e11555 + rhs->e11555;
  res->e12555 = lhs->e12555 + rhs->e12555;
  res->e22555 = lhs->e22555 + rhs->e22555;
  res->e13555 = lhs->e13555 + rhs->e13555;
  res->e23555 = lhs->e23555 + rhs->e23555;
  res->e33555 = lhs->e33555 + rhs->e33555;
  res->e14555 = lhs->e14555 + rhs->e14555;
  res->e24555 = lhs->e24555 + rhs->e24555;
  res->e34555 = lhs->e34555 + rhs->e34555;
  res->e44555 = lhs->e44555 + rhs->e44555;
  res->e15555 = lhs->e15555 + rhs->e15555;
  res->e25555 = lhs->e25555 + rhs->e25555;
  res->e35555 = lhs->e35555 + rhs->e35555;
  res->e45555 = lhs->e45555 + rhs->e45555;
  res->e55555 = lhs->e55555 + rhs->e55555;

}

onumm5n5_t onumm5n5_sum_ro(  coeff_t lhs,  onumm5n5_t* rhs){
  onumm5n5_t res;

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
  res.e1115 =  + rhs->e1115;
  res.e1125 =  + rhs->e1125;
  res.e1225 =  + rhs->e1225;
  res.e2225 =  + rhs->e2225;
  res.e1135 =  + rhs->e1135;
  res.e1235 =  + rhs->e1235;
  res.e2235 =  + rhs->e2235;
  res.e1335 =  + rhs->e1335;
  res.e2335 =  + rhs->e2335;
  res.e3335 =  + rhs->e3335;
  res.e1145 =  + rhs->e1145;
  res.e1245 =  + rhs->e1245;
  res.e2245 =  + rhs->e2245;
  res.e1345 =  + rhs->e1345;
  res.e2345 =  + rhs->e2345;
  res.e3345 =  + rhs->e3345;
  res.e1445 =  + rhs->e1445;
  res.e2445 =  + rhs->e2445;
  res.e3445 =  + rhs->e3445;
  res.e4445 =  + rhs->e4445;
  res.e1155 =  + rhs->e1155;
  res.e1255 =  + rhs->e1255;
  res.e2255 =  + rhs->e2255;
  res.e1355 =  + rhs->e1355;
  res.e2355 =  + rhs->e2355;
  res.e3355 =  + rhs->e3355;
  res.e1455 =  + rhs->e1455;
  res.e2455 =  + rhs->e2455;
  res.e3455 =  + rhs->e3455;
  res.e4455 =  + rhs->e4455;
  res.e1555 =  + rhs->e1555;
  res.e2555 =  + rhs->e2555;
  res.e3555 =  + rhs->e3555;
  res.e4555 =  + rhs->e4555;
  res.e5555 =  + rhs->e5555;
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
  res.e11115 =  + rhs->e11115;
  res.e11125 =  + rhs->e11125;
  res.e11225 =  + rhs->e11225;
  res.e12225 =  + rhs->e12225;
  res.e22225 =  + rhs->e22225;
  res.e11135 =  + rhs->e11135;
  res.e11235 =  + rhs->e11235;
  res.e12235 =  + rhs->e12235;
  res.e22235 =  + rhs->e22235;
  res.e11335 =  + rhs->e11335;
  res.e12335 =  + rhs->e12335;
  res.e22335 =  + rhs->e22335;
  res.e13335 =  + rhs->e13335;
  res.e23335 =  + rhs->e23335;
  res.e33335 =  + rhs->e33335;
  res.e11145 =  + rhs->e11145;
  res.e11245 =  + rhs->e11245;
  res.e12245 =  + rhs->e12245;
  res.e22245 =  + rhs->e22245;
  res.e11345 =  + rhs->e11345;
  res.e12345 =  + rhs->e12345;
  res.e22345 =  + rhs->e22345;
  res.e13345 =  + rhs->e13345;
  res.e23345 =  + rhs->e23345;
  res.e33345 =  + rhs->e33345;
  res.e11445 =  + rhs->e11445;
  res.e12445 =  + rhs->e12445;
  res.e22445 =  + rhs->e22445;
  res.e13445 =  + rhs->e13445;
  res.e23445 =  + rhs->e23445;
  res.e33445 =  + rhs->e33445;
  res.e14445 =  + rhs->e14445;
  res.e24445 =  + rhs->e24445;
  res.e34445 =  + rhs->e34445;
  res.e44445 =  + rhs->e44445;
  res.e11155 =  + rhs->e11155;
  res.e11255 =  + rhs->e11255;
  res.e12255 =  + rhs->e12255;
  res.e22255 =  + rhs->e22255;
  res.e11355 =  + rhs->e11355;
  res.e12355 =  + rhs->e12355;
  res.e22355 =  + rhs->e22355;
  res.e13355 =  + rhs->e13355;
  res.e23355 =  + rhs->e23355;
  res.e33355 =  + rhs->e33355;
  res.e11455 =  + rhs->e11455;
  res.e12455 =  + rhs->e12455;
  res.e22455 =  + rhs->e22455;
  res.e13455 =  + rhs->e13455;
  res.e23455 =  + rhs->e23455;
  res.e33455 =  + rhs->e33455;
  res.e14455 =  + rhs->e14455;
  res.e24455 =  + rhs->e24455;
  res.e34455 =  + rhs->e34455;
  res.e44455 =  + rhs->e44455;
  res.e11555 =  + rhs->e11555;
  res.e12555 =  + rhs->e12555;
  res.e22555 =  + rhs->e22555;
  res.e13555 =  + rhs->e13555;
  res.e23555 =  + rhs->e23555;
  res.e33555 =  + rhs->e33555;
  res.e14555 =  + rhs->e14555;
  res.e24555 =  + rhs->e24555;
  res.e34555 =  + rhs->e34555;
  res.e44555 =  + rhs->e44555;
  res.e15555 =  + rhs->e15555;
  res.e25555 =  + rhs->e25555;
  res.e35555 =  + rhs->e35555;
  res.e45555 =  + rhs->e45555;
  res.e55555 =  + rhs->e55555;

  return res;

}

void onumm5n5_sum_ro_to(  coeff_t lhs,  onumm5n5_t* rhs, onumm5n5_t* res){
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
  res->e1115 =  + rhs->e1115;
  res->e1125 =  + rhs->e1125;
  res->e1225 =  + rhs->e1225;
  res->e2225 =  + rhs->e2225;
  res->e1135 =  + rhs->e1135;
  res->e1235 =  + rhs->e1235;
  res->e2235 =  + rhs->e2235;
  res->e1335 =  + rhs->e1335;
  res->e2335 =  + rhs->e2335;
  res->e3335 =  + rhs->e3335;
  res->e1145 =  + rhs->e1145;
  res->e1245 =  + rhs->e1245;
  res->e2245 =  + rhs->e2245;
  res->e1345 =  + rhs->e1345;
  res->e2345 =  + rhs->e2345;
  res->e3345 =  + rhs->e3345;
  res->e1445 =  + rhs->e1445;
  res->e2445 =  + rhs->e2445;
  res->e3445 =  + rhs->e3445;
  res->e4445 =  + rhs->e4445;
  res->e1155 =  + rhs->e1155;
  res->e1255 =  + rhs->e1255;
  res->e2255 =  + rhs->e2255;
  res->e1355 =  + rhs->e1355;
  res->e2355 =  + rhs->e2355;
  res->e3355 =  + rhs->e3355;
  res->e1455 =  + rhs->e1455;
  res->e2455 =  + rhs->e2455;
  res->e3455 =  + rhs->e3455;
  res->e4455 =  + rhs->e4455;
  res->e1555 =  + rhs->e1555;
  res->e2555 =  + rhs->e2555;
  res->e3555 =  + rhs->e3555;
  res->e4555 =  + rhs->e4555;
  res->e5555 =  + rhs->e5555;
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
  res->e11115 =  + rhs->e11115;
  res->e11125 =  + rhs->e11125;
  res->e11225 =  + rhs->e11225;
  res->e12225 =  + rhs->e12225;
  res->e22225 =  + rhs->e22225;
  res->e11135 =  + rhs->e11135;
  res->e11235 =  + rhs->e11235;
  res->e12235 =  + rhs->e12235;
  res->e22235 =  + rhs->e22235;
  res->e11335 =  + rhs->e11335;
  res->e12335 =  + rhs->e12335;
  res->e22335 =  + rhs->e22335;
  res->e13335 =  + rhs->e13335;
  res->e23335 =  + rhs->e23335;
  res->e33335 =  + rhs->e33335;
  res->e11145 =  + rhs->e11145;
  res->e11245 =  + rhs->e11245;
  res->e12245 =  + rhs->e12245;
  res->e22245 =  + rhs->e22245;
  res->e11345 =  + rhs->e11345;
  res->e12345 =  + rhs->e12345;
  res->e22345 =  + rhs->e22345;
  res->e13345 =  + rhs->e13345;
  res->e23345 =  + rhs->e23345;
  res->e33345 =  + rhs->e33345;
  res->e11445 =  + rhs->e11445;
  res->e12445 =  + rhs->e12445;
  res->e22445 =  + rhs->e22445;
  res->e13445 =  + rhs->e13445;
  res->e23445 =  + rhs->e23445;
  res->e33445 =  + rhs->e33445;
  res->e14445 =  + rhs->e14445;
  res->e24445 =  + rhs->e24445;
  res->e34445 =  + rhs->e34445;
  res->e44445 =  + rhs->e44445;
  res->e11155 =  + rhs->e11155;
  res->e11255 =  + rhs->e11255;
  res->e12255 =  + rhs->e12255;
  res->e22255 =  + rhs->e22255;
  res->e11355 =  + rhs->e11355;
  res->e12355 =  + rhs->e12355;
  res->e22355 =  + rhs->e22355;
  res->e13355 =  + rhs->e13355;
  res->e23355 =  + rhs->e23355;
  res->e33355 =  + rhs->e33355;
  res->e11455 =  + rhs->e11455;
  res->e12455 =  + rhs->e12455;
  res->e22455 =  + rhs->e22455;
  res->e13455 =  + rhs->e13455;
  res->e23455 =  + rhs->e23455;
  res->e33455 =  + rhs->e33455;
  res->e14455 =  + rhs->e14455;
  res->e24455 =  + rhs->e24455;
  res->e34455 =  + rhs->e34455;
  res->e44455 =  + rhs->e44455;
  res->e11555 =  + rhs->e11555;
  res->e12555 =  + rhs->e12555;
  res->e22555 =  + rhs->e22555;
  res->e13555 =  + rhs->e13555;
  res->e23555 =  + rhs->e23555;
  res->e33555 =  + rhs->e33555;
  res->e14555 =  + rhs->e14555;
  res->e24555 =  + rhs->e24555;
  res->e34555 =  + rhs->e34555;
  res->e44555 =  + rhs->e44555;
  res->e15555 =  + rhs->e15555;
  res->e25555 =  + rhs->e25555;
  res->e35555 =  + rhs->e35555;
  res->e45555 =  + rhs->e45555;
  res->e55555 =  + rhs->e55555;

}

onumm5n5_t onumm5n5_sub_oo(  onumm5n5_t* lhs,  onumm5n5_t* rhs){
  onumm5n5_t res;

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
  res.e1115 = lhs->e1115 - rhs->e1115;
  res.e1125 = lhs->e1125 - rhs->e1125;
  res.e1225 = lhs->e1225 - rhs->e1225;
  res.e2225 = lhs->e2225 - rhs->e2225;
  res.e1135 = lhs->e1135 - rhs->e1135;
  res.e1235 = lhs->e1235 - rhs->e1235;
  res.e2235 = lhs->e2235 - rhs->e2235;
  res.e1335 = lhs->e1335 - rhs->e1335;
  res.e2335 = lhs->e2335 - rhs->e2335;
  res.e3335 = lhs->e3335 - rhs->e3335;
  res.e1145 = lhs->e1145 - rhs->e1145;
  res.e1245 = lhs->e1245 - rhs->e1245;
  res.e2245 = lhs->e2245 - rhs->e2245;
  res.e1345 = lhs->e1345 - rhs->e1345;
  res.e2345 = lhs->e2345 - rhs->e2345;
  res.e3345 = lhs->e3345 - rhs->e3345;
  res.e1445 = lhs->e1445 - rhs->e1445;
  res.e2445 = lhs->e2445 - rhs->e2445;
  res.e3445 = lhs->e3445 - rhs->e3445;
  res.e4445 = lhs->e4445 - rhs->e4445;
  res.e1155 = lhs->e1155 - rhs->e1155;
  res.e1255 = lhs->e1255 - rhs->e1255;
  res.e2255 = lhs->e2255 - rhs->e2255;
  res.e1355 = lhs->e1355 - rhs->e1355;
  res.e2355 = lhs->e2355 - rhs->e2355;
  res.e3355 = lhs->e3355 - rhs->e3355;
  res.e1455 = lhs->e1455 - rhs->e1455;
  res.e2455 = lhs->e2455 - rhs->e2455;
  res.e3455 = lhs->e3455 - rhs->e3455;
  res.e4455 = lhs->e4455 - rhs->e4455;
  res.e1555 = lhs->e1555 - rhs->e1555;
  res.e2555 = lhs->e2555 - rhs->e2555;
  res.e3555 = lhs->e3555 - rhs->e3555;
  res.e4555 = lhs->e4555 - rhs->e4555;
  res.e5555 = lhs->e5555 - rhs->e5555;
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
  res.e11115 = lhs->e11115 - rhs->e11115;
  res.e11125 = lhs->e11125 - rhs->e11125;
  res.e11225 = lhs->e11225 - rhs->e11225;
  res.e12225 = lhs->e12225 - rhs->e12225;
  res.e22225 = lhs->e22225 - rhs->e22225;
  res.e11135 = lhs->e11135 - rhs->e11135;
  res.e11235 = lhs->e11235 - rhs->e11235;
  res.e12235 = lhs->e12235 - rhs->e12235;
  res.e22235 = lhs->e22235 - rhs->e22235;
  res.e11335 = lhs->e11335 - rhs->e11335;
  res.e12335 = lhs->e12335 - rhs->e12335;
  res.e22335 = lhs->e22335 - rhs->e22335;
  res.e13335 = lhs->e13335 - rhs->e13335;
  res.e23335 = lhs->e23335 - rhs->e23335;
  res.e33335 = lhs->e33335 - rhs->e33335;
  res.e11145 = lhs->e11145 - rhs->e11145;
  res.e11245 = lhs->e11245 - rhs->e11245;
  res.e12245 = lhs->e12245 - rhs->e12245;
  res.e22245 = lhs->e22245 - rhs->e22245;
  res.e11345 = lhs->e11345 - rhs->e11345;
  res.e12345 = lhs->e12345 - rhs->e12345;
  res.e22345 = lhs->e22345 - rhs->e22345;
  res.e13345 = lhs->e13345 - rhs->e13345;
  res.e23345 = lhs->e23345 - rhs->e23345;
  res.e33345 = lhs->e33345 - rhs->e33345;
  res.e11445 = lhs->e11445 - rhs->e11445;
  res.e12445 = lhs->e12445 - rhs->e12445;
  res.e22445 = lhs->e22445 - rhs->e22445;
  res.e13445 = lhs->e13445 - rhs->e13445;
  res.e23445 = lhs->e23445 - rhs->e23445;
  res.e33445 = lhs->e33445 - rhs->e33445;
  res.e14445 = lhs->e14445 - rhs->e14445;
  res.e24445 = lhs->e24445 - rhs->e24445;
  res.e34445 = lhs->e34445 - rhs->e34445;
  res.e44445 = lhs->e44445 - rhs->e44445;
  res.e11155 = lhs->e11155 - rhs->e11155;
  res.e11255 = lhs->e11255 - rhs->e11255;
  res.e12255 = lhs->e12255 - rhs->e12255;
  res.e22255 = lhs->e22255 - rhs->e22255;
  res.e11355 = lhs->e11355 - rhs->e11355;
  res.e12355 = lhs->e12355 - rhs->e12355;
  res.e22355 = lhs->e22355 - rhs->e22355;
  res.e13355 = lhs->e13355 - rhs->e13355;
  res.e23355 = lhs->e23355 - rhs->e23355;
  res.e33355 = lhs->e33355 - rhs->e33355;
  res.e11455 = lhs->e11455 - rhs->e11455;
  res.e12455 = lhs->e12455 - rhs->e12455;
  res.e22455 = lhs->e22455 - rhs->e22455;
  res.e13455 = lhs->e13455 - rhs->e13455;
  res.e23455 = lhs->e23455 - rhs->e23455;
  res.e33455 = lhs->e33455 - rhs->e33455;
  res.e14455 = lhs->e14455 - rhs->e14455;
  res.e24455 = lhs->e24455 - rhs->e24455;
  res.e34455 = lhs->e34455 - rhs->e34455;
  res.e44455 = lhs->e44455 - rhs->e44455;
  res.e11555 = lhs->e11555 - rhs->e11555;
  res.e12555 = lhs->e12555 - rhs->e12555;
  res.e22555 = lhs->e22555 - rhs->e22555;
  res.e13555 = lhs->e13555 - rhs->e13555;
  res.e23555 = lhs->e23555 - rhs->e23555;
  res.e33555 = lhs->e33555 - rhs->e33555;
  res.e14555 = lhs->e14555 - rhs->e14555;
  res.e24555 = lhs->e24555 - rhs->e24555;
  res.e34555 = lhs->e34555 - rhs->e34555;
  res.e44555 = lhs->e44555 - rhs->e44555;
  res.e15555 = lhs->e15555 - rhs->e15555;
  res.e25555 = lhs->e25555 - rhs->e25555;
  res.e35555 = lhs->e35555 - rhs->e35555;
  res.e45555 = lhs->e45555 - rhs->e45555;
  res.e55555 = lhs->e55555 - rhs->e55555;

  return res;

}

void onumm5n5_sub_oo_to(  onumm5n5_t* lhs,  onumm5n5_t* rhs, onumm5n5_t* res){
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
  res->e1115 = lhs->e1115 - rhs->e1115;
  res->e1125 = lhs->e1125 - rhs->e1125;
  res->e1225 = lhs->e1225 - rhs->e1225;
  res->e2225 = lhs->e2225 - rhs->e2225;
  res->e1135 = lhs->e1135 - rhs->e1135;
  res->e1235 = lhs->e1235 - rhs->e1235;
  res->e2235 = lhs->e2235 - rhs->e2235;
  res->e1335 = lhs->e1335 - rhs->e1335;
  res->e2335 = lhs->e2335 - rhs->e2335;
  res->e3335 = lhs->e3335 - rhs->e3335;
  res->e1145 = lhs->e1145 - rhs->e1145;
  res->e1245 = lhs->e1245 - rhs->e1245;
  res->e2245 = lhs->e2245 - rhs->e2245;
  res->e1345 = lhs->e1345 - rhs->e1345;
  res->e2345 = lhs->e2345 - rhs->e2345;
  res->e3345 = lhs->e3345 - rhs->e3345;
  res->e1445 = lhs->e1445 - rhs->e1445;
  res->e2445 = lhs->e2445 - rhs->e2445;
  res->e3445 = lhs->e3445 - rhs->e3445;
  res->e4445 = lhs->e4445 - rhs->e4445;
  res->e1155 = lhs->e1155 - rhs->e1155;
  res->e1255 = lhs->e1255 - rhs->e1255;
  res->e2255 = lhs->e2255 - rhs->e2255;
  res->e1355 = lhs->e1355 - rhs->e1355;
  res->e2355 = lhs->e2355 - rhs->e2355;
  res->e3355 = lhs->e3355 - rhs->e3355;
  res->e1455 = lhs->e1455 - rhs->e1455;
  res->e2455 = lhs->e2455 - rhs->e2455;
  res->e3455 = lhs->e3455 - rhs->e3455;
  res->e4455 = lhs->e4455 - rhs->e4455;
  res->e1555 = lhs->e1555 - rhs->e1555;
  res->e2555 = lhs->e2555 - rhs->e2555;
  res->e3555 = lhs->e3555 - rhs->e3555;
  res->e4555 = lhs->e4555 - rhs->e4555;
  res->e5555 = lhs->e5555 - rhs->e5555;
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
  res->e11115 = lhs->e11115 - rhs->e11115;
  res->e11125 = lhs->e11125 - rhs->e11125;
  res->e11225 = lhs->e11225 - rhs->e11225;
  res->e12225 = lhs->e12225 - rhs->e12225;
  res->e22225 = lhs->e22225 - rhs->e22225;
  res->e11135 = lhs->e11135 - rhs->e11135;
  res->e11235 = lhs->e11235 - rhs->e11235;
  res->e12235 = lhs->e12235 - rhs->e12235;
  res->e22235 = lhs->e22235 - rhs->e22235;
  res->e11335 = lhs->e11335 - rhs->e11335;
  res->e12335 = lhs->e12335 - rhs->e12335;
  res->e22335 = lhs->e22335 - rhs->e22335;
  res->e13335 = lhs->e13335 - rhs->e13335;
  res->e23335 = lhs->e23335 - rhs->e23335;
  res->e33335 = lhs->e33335 - rhs->e33335;
  res->e11145 = lhs->e11145 - rhs->e11145;
  res->e11245 = lhs->e11245 - rhs->e11245;
  res->e12245 = lhs->e12245 - rhs->e12245;
  res->e22245 = lhs->e22245 - rhs->e22245;
  res->e11345 = lhs->e11345 - rhs->e11345;
  res->e12345 = lhs->e12345 - rhs->e12345;
  res->e22345 = lhs->e22345 - rhs->e22345;
  res->e13345 = lhs->e13345 - rhs->e13345;
  res->e23345 = lhs->e23345 - rhs->e23345;
  res->e33345 = lhs->e33345 - rhs->e33345;
  res->e11445 = lhs->e11445 - rhs->e11445;
  res->e12445 = lhs->e12445 - rhs->e12445;
  res->e22445 = lhs->e22445 - rhs->e22445;
  res->e13445 = lhs->e13445 - rhs->e13445;
  res->e23445 = lhs->e23445 - rhs->e23445;
  res->e33445 = lhs->e33445 - rhs->e33445;
  res->e14445 = lhs->e14445 - rhs->e14445;
  res->e24445 = lhs->e24445 - rhs->e24445;
  res->e34445 = lhs->e34445 - rhs->e34445;
  res->e44445 = lhs->e44445 - rhs->e44445;
  res->e11155 = lhs->e11155 - rhs->e11155;
  res->e11255 = lhs->e11255 - rhs->e11255;
  res->e12255 = lhs->e12255 - rhs->e12255;
  res->e22255 = lhs->e22255 - rhs->e22255;
  res->e11355 = lhs->e11355 - rhs->e11355;
  res->e12355 = lhs->e12355 - rhs->e12355;
  res->e22355 = lhs->e22355 - rhs->e22355;
  res->e13355 = lhs->e13355 - rhs->e13355;
  res->e23355 = lhs->e23355 - rhs->e23355;
  res->e33355 = lhs->e33355 - rhs->e33355;
  res->e11455 = lhs->e11455 - rhs->e11455;
  res->e12455 = lhs->e12455 - rhs->e12455;
  res->e22455 = lhs->e22455 - rhs->e22455;
  res->e13455 = lhs->e13455 - rhs->e13455;
  res->e23455 = lhs->e23455 - rhs->e23455;
  res->e33455 = lhs->e33455 - rhs->e33455;
  res->e14455 = lhs->e14455 - rhs->e14455;
  res->e24455 = lhs->e24455 - rhs->e24455;
  res->e34455 = lhs->e34455 - rhs->e34455;
  res->e44455 = lhs->e44455 - rhs->e44455;
  res->e11555 = lhs->e11555 - rhs->e11555;
  res->e12555 = lhs->e12555 - rhs->e12555;
  res->e22555 = lhs->e22555 - rhs->e22555;
  res->e13555 = lhs->e13555 - rhs->e13555;
  res->e23555 = lhs->e23555 - rhs->e23555;
  res->e33555 = lhs->e33555 - rhs->e33555;
  res->e14555 = lhs->e14555 - rhs->e14555;
  res->e24555 = lhs->e24555 - rhs->e24555;
  res->e34555 = lhs->e34555 - rhs->e34555;
  res->e44555 = lhs->e44555 - rhs->e44555;
  res->e15555 = lhs->e15555 - rhs->e15555;
  res->e25555 = lhs->e25555 - rhs->e25555;
  res->e35555 = lhs->e35555 - rhs->e35555;
  res->e45555 = lhs->e45555 - rhs->e45555;
  res->e55555 = lhs->e55555 - rhs->e55555;

}

onumm5n5_t onumm5n5_sub_ro(  coeff_t lhs,  onumm5n5_t* rhs){
  onumm5n5_t res;

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
  res.e1115 =  - rhs->e1115;
  res.e1125 =  - rhs->e1125;
  res.e1225 =  - rhs->e1225;
  res.e2225 =  - rhs->e2225;
  res.e1135 =  - rhs->e1135;
  res.e1235 =  - rhs->e1235;
  res.e2235 =  - rhs->e2235;
  res.e1335 =  - rhs->e1335;
  res.e2335 =  - rhs->e2335;
  res.e3335 =  - rhs->e3335;
  res.e1145 =  - rhs->e1145;
  res.e1245 =  - rhs->e1245;
  res.e2245 =  - rhs->e2245;
  res.e1345 =  - rhs->e1345;
  res.e2345 =  - rhs->e2345;
  res.e3345 =  - rhs->e3345;
  res.e1445 =  - rhs->e1445;
  res.e2445 =  - rhs->e2445;
  res.e3445 =  - rhs->e3445;
  res.e4445 =  - rhs->e4445;
  res.e1155 =  - rhs->e1155;
  res.e1255 =  - rhs->e1255;
  res.e2255 =  - rhs->e2255;
  res.e1355 =  - rhs->e1355;
  res.e2355 =  - rhs->e2355;
  res.e3355 =  - rhs->e3355;
  res.e1455 =  - rhs->e1455;
  res.e2455 =  - rhs->e2455;
  res.e3455 =  - rhs->e3455;
  res.e4455 =  - rhs->e4455;
  res.e1555 =  - rhs->e1555;
  res.e2555 =  - rhs->e2555;
  res.e3555 =  - rhs->e3555;
  res.e4555 =  - rhs->e4555;
  res.e5555 =  - rhs->e5555;
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
  res.e11115 =  - rhs->e11115;
  res.e11125 =  - rhs->e11125;
  res.e11225 =  - rhs->e11225;
  res.e12225 =  - rhs->e12225;
  res.e22225 =  - rhs->e22225;
  res.e11135 =  - rhs->e11135;
  res.e11235 =  - rhs->e11235;
  res.e12235 =  - rhs->e12235;
  res.e22235 =  - rhs->e22235;
  res.e11335 =  - rhs->e11335;
  res.e12335 =  - rhs->e12335;
  res.e22335 =  - rhs->e22335;
  res.e13335 =  - rhs->e13335;
  res.e23335 =  - rhs->e23335;
  res.e33335 =  - rhs->e33335;
  res.e11145 =  - rhs->e11145;
  res.e11245 =  - rhs->e11245;
  res.e12245 =  - rhs->e12245;
  res.e22245 =  - rhs->e22245;
  res.e11345 =  - rhs->e11345;
  res.e12345 =  - rhs->e12345;
  res.e22345 =  - rhs->e22345;
  res.e13345 =  - rhs->e13345;
  res.e23345 =  - rhs->e23345;
  res.e33345 =  - rhs->e33345;
  res.e11445 =  - rhs->e11445;
  res.e12445 =  - rhs->e12445;
  res.e22445 =  - rhs->e22445;
  res.e13445 =  - rhs->e13445;
  res.e23445 =  - rhs->e23445;
  res.e33445 =  - rhs->e33445;
  res.e14445 =  - rhs->e14445;
  res.e24445 =  - rhs->e24445;
  res.e34445 =  - rhs->e34445;
  res.e44445 =  - rhs->e44445;
  res.e11155 =  - rhs->e11155;
  res.e11255 =  - rhs->e11255;
  res.e12255 =  - rhs->e12255;
  res.e22255 =  - rhs->e22255;
  res.e11355 =  - rhs->e11355;
  res.e12355 =  - rhs->e12355;
  res.e22355 =  - rhs->e22355;
  res.e13355 =  - rhs->e13355;
  res.e23355 =  - rhs->e23355;
  res.e33355 =  - rhs->e33355;
  res.e11455 =  - rhs->e11455;
  res.e12455 =  - rhs->e12455;
  res.e22455 =  - rhs->e22455;
  res.e13455 =  - rhs->e13455;
  res.e23455 =  - rhs->e23455;
  res.e33455 =  - rhs->e33455;
  res.e14455 =  - rhs->e14455;
  res.e24455 =  - rhs->e24455;
  res.e34455 =  - rhs->e34455;
  res.e44455 =  - rhs->e44455;
  res.e11555 =  - rhs->e11555;
  res.e12555 =  - rhs->e12555;
  res.e22555 =  - rhs->e22555;
  res.e13555 =  - rhs->e13555;
  res.e23555 =  - rhs->e23555;
  res.e33555 =  - rhs->e33555;
  res.e14555 =  - rhs->e14555;
  res.e24555 =  - rhs->e24555;
  res.e34555 =  - rhs->e34555;
  res.e44555 =  - rhs->e44555;
  res.e15555 =  - rhs->e15555;
  res.e25555 =  - rhs->e25555;
  res.e35555 =  - rhs->e35555;
  res.e45555 =  - rhs->e45555;
  res.e55555 =  - rhs->e55555;

  return res;

}

void onumm5n5_sub_ro_to(  coeff_t lhs,  onumm5n5_t* rhs, onumm5n5_t* res){
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
  res->e1115 =  - rhs->e1115;
  res->e1125 =  - rhs->e1125;
  res->e1225 =  - rhs->e1225;
  res->e2225 =  - rhs->e2225;
  res->e1135 =  - rhs->e1135;
  res->e1235 =  - rhs->e1235;
  res->e2235 =  - rhs->e2235;
  res->e1335 =  - rhs->e1335;
  res->e2335 =  - rhs->e2335;
  res->e3335 =  - rhs->e3335;
  res->e1145 =  - rhs->e1145;
  res->e1245 =  - rhs->e1245;
  res->e2245 =  - rhs->e2245;
  res->e1345 =  - rhs->e1345;
  res->e2345 =  - rhs->e2345;
  res->e3345 =  - rhs->e3345;
  res->e1445 =  - rhs->e1445;
  res->e2445 =  - rhs->e2445;
  res->e3445 =  - rhs->e3445;
  res->e4445 =  - rhs->e4445;
  res->e1155 =  - rhs->e1155;
  res->e1255 =  - rhs->e1255;
  res->e2255 =  - rhs->e2255;
  res->e1355 =  - rhs->e1355;
  res->e2355 =  - rhs->e2355;
  res->e3355 =  - rhs->e3355;
  res->e1455 =  - rhs->e1455;
  res->e2455 =  - rhs->e2455;
  res->e3455 =  - rhs->e3455;
  res->e4455 =  - rhs->e4455;
  res->e1555 =  - rhs->e1555;
  res->e2555 =  - rhs->e2555;
  res->e3555 =  - rhs->e3555;
  res->e4555 =  - rhs->e4555;
  res->e5555 =  - rhs->e5555;
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
  res->e11115 =  - rhs->e11115;
  res->e11125 =  - rhs->e11125;
  res->e11225 =  - rhs->e11225;
  res->e12225 =  - rhs->e12225;
  res->e22225 =  - rhs->e22225;
  res->e11135 =  - rhs->e11135;
  res->e11235 =  - rhs->e11235;
  res->e12235 =  - rhs->e12235;
  res->e22235 =  - rhs->e22235;
  res->e11335 =  - rhs->e11335;
  res->e12335 =  - rhs->e12335;
  res->e22335 =  - rhs->e22335;
  res->e13335 =  - rhs->e13335;
  res->e23335 =  - rhs->e23335;
  res->e33335 =  - rhs->e33335;
  res->e11145 =  - rhs->e11145;
  res->e11245 =  - rhs->e11245;
  res->e12245 =  - rhs->e12245;
  res->e22245 =  - rhs->e22245;
  res->e11345 =  - rhs->e11345;
  res->e12345 =  - rhs->e12345;
  res->e22345 =  - rhs->e22345;
  res->e13345 =  - rhs->e13345;
  res->e23345 =  - rhs->e23345;
  res->e33345 =  - rhs->e33345;
  res->e11445 =  - rhs->e11445;
  res->e12445 =  - rhs->e12445;
  res->e22445 =  - rhs->e22445;
  res->e13445 =  - rhs->e13445;
  res->e23445 =  - rhs->e23445;
  res->e33445 =  - rhs->e33445;
  res->e14445 =  - rhs->e14445;
  res->e24445 =  - rhs->e24445;
  res->e34445 =  - rhs->e34445;
  res->e44445 =  - rhs->e44445;
  res->e11155 =  - rhs->e11155;
  res->e11255 =  - rhs->e11255;
  res->e12255 =  - rhs->e12255;
  res->e22255 =  - rhs->e22255;
  res->e11355 =  - rhs->e11355;
  res->e12355 =  - rhs->e12355;
  res->e22355 =  - rhs->e22355;
  res->e13355 =  - rhs->e13355;
  res->e23355 =  - rhs->e23355;
  res->e33355 =  - rhs->e33355;
  res->e11455 =  - rhs->e11455;
  res->e12455 =  - rhs->e12455;
  res->e22455 =  - rhs->e22455;
  res->e13455 =  - rhs->e13455;
  res->e23455 =  - rhs->e23455;
  res->e33455 =  - rhs->e33455;
  res->e14455 =  - rhs->e14455;
  res->e24455 =  - rhs->e24455;
  res->e34455 =  - rhs->e34455;
  res->e44455 =  - rhs->e44455;
  res->e11555 =  - rhs->e11555;
  res->e12555 =  - rhs->e12555;
  res->e22555 =  - rhs->e22555;
  res->e13555 =  - rhs->e13555;
  res->e23555 =  - rhs->e23555;
  res->e33555 =  - rhs->e33555;
  res->e14555 =  - rhs->e14555;
  res->e24555 =  - rhs->e24555;
  res->e34555 =  - rhs->e34555;
  res->e44555 =  - rhs->e44555;
  res->e15555 =  - rhs->e15555;
  res->e25555 =  - rhs->e25555;
  res->e35555 =  - rhs->e35555;
  res->e45555 =  - rhs->e45555;
  res->e55555 =  - rhs->e55555;

}

onumm5n5_t onumm5n5_sub_or(  onumm5n5_t* lhs,  coeff_t rhs){
  onumm5n5_t res;

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
  res.e1115 = lhs->e1115;
  res.e1125 = lhs->e1125;
  res.e1225 = lhs->e1225;
  res.e2225 = lhs->e2225;
  res.e1135 = lhs->e1135;
  res.e1235 = lhs->e1235;
  res.e2235 = lhs->e2235;
  res.e1335 = lhs->e1335;
  res.e2335 = lhs->e2335;
  res.e3335 = lhs->e3335;
  res.e1145 = lhs->e1145;
  res.e1245 = lhs->e1245;
  res.e2245 = lhs->e2245;
  res.e1345 = lhs->e1345;
  res.e2345 = lhs->e2345;
  res.e3345 = lhs->e3345;
  res.e1445 = lhs->e1445;
  res.e2445 = lhs->e2445;
  res.e3445 = lhs->e3445;
  res.e4445 = lhs->e4445;
  res.e1155 = lhs->e1155;
  res.e1255 = lhs->e1255;
  res.e2255 = lhs->e2255;
  res.e1355 = lhs->e1355;
  res.e2355 = lhs->e2355;
  res.e3355 = lhs->e3355;
  res.e1455 = lhs->e1455;
  res.e2455 = lhs->e2455;
  res.e3455 = lhs->e3455;
  res.e4455 = lhs->e4455;
  res.e1555 = lhs->e1555;
  res.e2555 = lhs->e2555;
  res.e3555 = lhs->e3555;
  res.e4555 = lhs->e4555;
  res.e5555 = lhs->e5555;
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
  res.e11115 = lhs->e11115;
  res.e11125 = lhs->e11125;
  res.e11225 = lhs->e11225;
  res.e12225 = lhs->e12225;
  res.e22225 = lhs->e22225;
  res.e11135 = lhs->e11135;
  res.e11235 = lhs->e11235;
  res.e12235 = lhs->e12235;
  res.e22235 = lhs->e22235;
  res.e11335 = lhs->e11335;
  res.e12335 = lhs->e12335;
  res.e22335 = lhs->e22335;
  res.e13335 = lhs->e13335;
  res.e23335 = lhs->e23335;
  res.e33335 = lhs->e33335;
  res.e11145 = lhs->e11145;
  res.e11245 = lhs->e11245;
  res.e12245 = lhs->e12245;
  res.e22245 = lhs->e22245;
  res.e11345 = lhs->e11345;
  res.e12345 = lhs->e12345;
  res.e22345 = lhs->e22345;
  res.e13345 = lhs->e13345;
  res.e23345 = lhs->e23345;
  res.e33345 = lhs->e33345;
  res.e11445 = lhs->e11445;
  res.e12445 = lhs->e12445;
  res.e22445 = lhs->e22445;
  res.e13445 = lhs->e13445;
  res.e23445 = lhs->e23445;
  res.e33445 = lhs->e33445;
  res.e14445 = lhs->e14445;
  res.e24445 = lhs->e24445;
  res.e34445 = lhs->e34445;
  res.e44445 = lhs->e44445;
  res.e11155 = lhs->e11155;
  res.e11255 = lhs->e11255;
  res.e12255 = lhs->e12255;
  res.e22255 = lhs->e22255;
  res.e11355 = lhs->e11355;
  res.e12355 = lhs->e12355;
  res.e22355 = lhs->e22355;
  res.e13355 = lhs->e13355;
  res.e23355 = lhs->e23355;
  res.e33355 = lhs->e33355;
  res.e11455 = lhs->e11455;
  res.e12455 = lhs->e12455;
  res.e22455 = lhs->e22455;
  res.e13455 = lhs->e13455;
  res.e23455 = lhs->e23455;
  res.e33455 = lhs->e33455;
  res.e14455 = lhs->e14455;
  res.e24455 = lhs->e24455;
  res.e34455 = lhs->e34455;
  res.e44455 = lhs->e44455;
  res.e11555 = lhs->e11555;
  res.e12555 = lhs->e12555;
  res.e22555 = lhs->e22555;
  res.e13555 = lhs->e13555;
  res.e23555 = lhs->e23555;
  res.e33555 = lhs->e33555;
  res.e14555 = lhs->e14555;
  res.e24555 = lhs->e24555;
  res.e34555 = lhs->e34555;
  res.e44555 = lhs->e44555;
  res.e15555 = lhs->e15555;
  res.e25555 = lhs->e25555;
  res.e35555 = lhs->e35555;
  res.e45555 = lhs->e45555;
  res.e55555 = lhs->e55555;

  return res;

}

void onumm5n5_sub_or_to(  onumm5n5_t* lhs,  coeff_t rhs, onumm5n5_t* res){
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
  res->e1115 = lhs->e1115;
  res->e1125 = lhs->e1125;
  res->e1225 = lhs->e1225;
  res->e2225 = lhs->e2225;
  res->e1135 = lhs->e1135;
  res->e1235 = lhs->e1235;
  res->e2235 = lhs->e2235;
  res->e1335 = lhs->e1335;
  res->e2335 = lhs->e2335;
  res->e3335 = lhs->e3335;
  res->e1145 = lhs->e1145;
  res->e1245 = lhs->e1245;
  res->e2245 = lhs->e2245;
  res->e1345 = lhs->e1345;
  res->e2345 = lhs->e2345;
  res->e3345 = lhs->e3345;
  res->e1445 = lhs->e1445;
  res->e2445 = lhs->e2445;
  res->e3445 = lhs->e3445;
  res->e4445 = lhs->e4445;
  res->e1155 = lhs->e1155;
  res->e1255 = lhs->e1255;
  res->e2255 = lhs->e2255;
  res->e1355 = lhs->e1355;
  res->e2355 = lhs->e2355;
  res->e3355 = lhs->e3355;
  res->e1455 = lhs->e1455;
  res->e2455 = lhs->e2455;
  res->e3455 = lhs->e3455;
  res->e4455 = lhs->e4455;
  res->e1555 = lhs->e1555;
  res->e2555 = lhs->e2555;
  res->e3555 = lhs->e3555;
  res->e4555 = lhs->e4555;
  res->e5555 = lhs->e5555;
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
  res->e11115 = lhs->e11115;
  res->e11125 = lhs->e11125;
  res->e11225 = lhs->e11225;
  res->e12225 = lhs->e12225;
  res->e22225 = lhs->e22225;
  res->e11135 = lhs->e11135;
  res->e11235 = lhs->e11235;
  res->e12235 = lhs->e12235;
  res->e22235 = lhs->e22235;
  res->e11335 = lhs->e11335;
  res->e12335 = lhs->e12335;
  res->e22335 = lhs->e22335;
  res->e13335 = lhs->e13335;
  res->e23335 = lhs->e23335;
  res->e33335 = lhs->e33335;
  res->e11145 = lhs->e11145;
  res->e11245 = lhs->e11245;
  res->e12245 = lhs->e12245;
  res->e22245 = lhs->e22245;
  res->e11345 = lhs->e11345;
  res->e12345 = lhs->e12345;
  res->e22345 = lhs->e22345;
  res->e13345 = lhs->e13345;
  res->e23345 = lhs->e23345;
  res->e33345 = lhs->e33345;
  res->e11445 = lhs->e11445;
  res->e12445 = lhs->e12445;
  res->e22445 = lhs->e22445;
  res->e13445 = lhs->e13445;
  res->e23445 = lhs->e23445;
  res->e33445 = lhs->e33445;
  res->e14445 = lhs->e14445;
  res->e24445 = lhs->e24445;
  res->e34445 = lhs->e34445;
  res->e44445 = lhs->e44445;
  res->e11155 = lhs->e11155;
  res->e11255 = lhs->e11255;
  res->e12255 = lhs->e12255;
  res->e22255 = lhs->e22255;
  res->e11355 = lhs->e11355;
  res->e12355 = lhs->e12355;
  res->e22355 = lhs->e22355;
  res->e13355 = lhs->e13355;
  res->e23355 = lhs->e23355;
  res->e33355 = lhs->e33355;
  res->e11455 = lhs->e11455;
  res->e12455 = lhs->e12455;
  res->e22455 = lhs->e22455;
  res->e13455 = lhs->e13455;
  res->e23455 = lhs->e23455;
  res->e33455 = lhs->e33455;
  res->e14455 = lhs->e14455;
  res->e24455 = lhs->e24455;
  res->e34455 = lhs->e34455;
  res->e44455 = lhs->e44455;
  res->e11555 = lhs->e11555;
  res->e12555 = lhs->e12555;
  res->e22555 = lhs->e22555;
  res->e13555 = lhs->e13555;
  res->e23555 = lhs->e23555;
  res->e33555 = lhs->e33555;
  res->e14555 = lhs->e14555;
  res->e24555 = lhs->e24555;
  res->e34555 = lhs->e34555;
  res->e44555 = lhs->e44555;
  res->e15555 = lhs->e15555;
  res->e25555 = lhs->e25555;
  res->e35555 = lhs->e35555;
  res->e45555 = lhs->e45555;
  res->e55555 = lhs->e55555;

}

onumm5n5_t onumm5n5_mul_oo(  onumm5n5_t* lhs,  onumm5n5_t* rhs){
  onumm5n5_t res;

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
  res.e1115 = lhs->r * rhs->e1115 + lhs->e1115 * rhs->r + lhs->e1 * rhs->e115 
            + lhs->e115 * rhs->e1 + lhs->e5 * rhs->e111 + lhs->e111 * rhs->e5 
            + lhs->e11 * rhs->e15 + lhs->e15 * rhs->e11;
  res.e1125 = lhs->r * rhs->e1125 + lhs->e1125 * rhs->r + lhs->e1 * rhs->e125 
            + lhs->e125 * rhs->e1 + lhs->e2 * rhs->e115 + lhs->e115 * rhs->e2 
            + lhs->e5 * rhs->e112 + lhs->e112 * rhs->e5 + lhs->e11 * rhs->e25 
            + lhs->e12 * rhs->e15 + lhs->e15 * rhs->e12 + lhs->e25 * rhs->e11;
  res.e1225 = lhs->r * rhs->e1225 + lhs->e1225 * rhs->r + lhs->e1 * rhs->e225 
            + lhs->e225 * rhs->e1 + lhs->e2 * rhs->e125 + lhs->e125 * rhs->e2 
            + lhs->e5 * rhs->e122 + lhs->e122 * rhs->e5 + lhs->e12 * rhs->e25 
            + lhs->e22 * rhs->e15 + lhs->e15 * rhs->e22 + lhs->e25 * rhs->e12;
  res.e2225 = lhs->r * rhs->e2225 + lhs->e2225 * rhs->r + lhs->e2 * rhs->e225 
            + lhs->e225 * rhs->e2 + lhs->e5 * rhs->e222 + lhs->e222 * rhs->e5 
            + lhs->e22 * rhs->e25 + lhs->e25 * rhs->e22;
  res.e1135 = lhs->r * rhs->e1135 + lhs->e1135 * rhs->r + lhs->e1 * rhs->e135 
            + lhs->e135 * rhs->e1 + lhs->e3 * rhs->e115 + lhs->e115 * rhs->e3 
            + lhs->e5 * rhs->e113 + lhs->e113 * rhs->e5 + lhs->e11 * rhs->e35 
            + lhs->e13 * rhs->e15 + lhs->e15 * rhs->e13 + lhs->e35 * rhs->e11;
  res.e1235 = lhs->r * rhs->e1235 + lhs->e1235 * rhs->r + lhs->e1 * rhs->e235 
            + lhs->e235 * rhs->e1 + lhs->e2 * rhs->e135 + lhs->e135 * rhs->e2 
            + lhs->e3 * rhs->e125 + lhs->e125 * rhs->e3 + lhs->e5 * rhs->e123 
            + lhs->e123 * rhs->e5 + lhs->e12 * rhs->e35 + lhs->e13 * rhs->e25 
            + lhs->e23 * rhs->e15 + lhs->e15 * rhs->e23 + lhs->e25 * rhs->e13 
            + lhs->e35 * rhs->e12;
  res.e2235 = lhs->r * rhs->e2235 + lhs->e2235 * rhs->r + lhs->e2 * rhs->e235 
            + lhs->e235 * rhs->e2 + lhs->e3 * rhs->e225 + lhs->e225 * rhs->e3 
            + lhs->e5 * rhs->e223 + lhs->e223 * rhs->e5 + lhs->e22 * rhs->e35 
            + lhs->e23 * rhs->e25 + lhs->e25 * rhs->e23 + lhs->e35 * rhs->e22;
  res.e1335 = lhs->r * rhs->e1335 + lhs->e1335 * rhs->r + lhs->e1 * rhs->e335 
            + lhs->e335 * rhs->e1 + lhs->e3 * rhs->e135 + lhs->e135 * rhs->e3 
            + lhs->e5 * rhs->e133 + lhs->e133 * rhs->e5 + lhs->e13 * rhs->e35 
            + lhs->e33 * rhs->e15 + lhs->e15 * rhs->e33 + lhs->e35 * rhs->e13;
  res.e2335 = lhs->r * rhs->e2335 + lhs->e2335 * rhs->r + lhs->e2 * rhs->e335 
            + lhs->e335 * rhs->e2 + lhs->e3 * rhs->e235 + lhs->e235 * rhs->e3 
            + lhs->e5 * rhs->e233 + lhs->e233 * rhs->e5 + lhs->e23 * rhs->e35 
            + lhs->e33 * rhs->e25 + lhs->e25 * rhs->e33 + lhs->e35 * rhs->e23;
  res.e3335 = lhs->r * rhs->e3335 + lhs->e3335 * rhs->r + lhs->e3 * rhs->e335 
            + lhs->e335 * rhs->e3 + lhs->e5 * rhs->e333 + lhs->e333 * rhs->e5 
            + lhs->e33 * rhs->e35 + lhs->e35 * rhs->e33;
  res.e1145 = lhs->r * rhs->e1145 + lhs->e1145 * rhs->r + lhs->e1 * rhs->e145 
            + lhs->e145 * rhs->e1 + lhs->e4 * rhs->e115 + lhs->e115 * rhs->e4 
            + lhs->e5 * rhs->e114 + lhs->e114 * rhs->e5 + lhs->e11 * rhs->e45 
            + lhs->e14 * rhs->e15 + lhs->e15 * rhs->e14 + lhs->e45 * rhs->e11;
  res.e1245 = lhs->r * rhs->e1245 + lhs->e1245 * rhs->r + lhs->e1 * rhs->e245 
            + lhs->e245 * rhs->e1 + lhs->e2 * rhs->e145 + lhs->e145 * rhs->e2 
            + lhs->e4 * rhs->e125 + lhs->e125 * rhs->e4 + lhs->e5 * rhs->e124 
            + lhs->e124 * rhs->e5 + lhs->e12 * rhs->e45 + lhs->e14 * rhs->e25 
            + lhs->e24 * rhs->e15 + lhs->e15 * rhs->e24 + lhs->e25 * rhs->e14 
            + lhs->e45 * rhs->e12;
  res.e2245 = lhs->r * rhs->e2245 + lhs->e2245 * rhs->r + lhs->e2 * rhs->e245 
            + lhs->e245 * rhs->e2 + lhs->e4 * rhs->e225 + lhs->e225 * rhs->e4 
            + lhs->e5 * rhs->e224 + lhs->e224 * rhs->e5 + lhs->e22 * rhs->e45 
            + lhs->e24 * rhs->e25 + lhs->e25 * rhs->e24 + lhs->e45 * rhs->e22;
  res.e1345 = lhs->r * rhs->e1345 + lhs->e1345 * rhs->r + lhs->e1 * rhs->e345 
            + lhs->e345 * rhs->e1 + lhs->e3 * rhs->e145 + lhs->e145 * rhs->e3 
            + lhs->e4 * rhs->e135 + lhs->e135 * rhs->e4 + lhs->e5 * rhs->e134 
            + lhs->e134 * rhs->e5 + lhs->e13 * rhs->e45 + lhs->e14 * rhs->e35 
            + lhs->e34 * rhs->e15 + lhs->e15 * rhs->e34 + lhs->e35 * rhs->e14 
            + lhs->e45 * rhs->e13;
  res.e2345 = lhs->r * rhs->e2345 + lhs->e2345 * rhs->r + lhs->e2 * rhs->e345 
            + lhs->e345 * rhs->e2 + lhs->e3 * rhs->e245 + lhs->e245 * rhs->e3 
            + lhs->e4 * rhs->e235 + lhs->e235 * rhs->e4 + lhs->e5 * rhs->e234 
            + lhs->e234 * rhs->e5 + lhs->e23 * rhs->e45 + lhs->e24 * rhs->e35 
            + lhs->e34 * rhs->e25 + lhs->e25 * rhs->e34 + lhs->e35 * rhs->e24 
            + lhs->e45 * rhs->e23;
  res.e3345 = lhs->r * rhs->e3345 + lhs->e3345 * rhs->r + lhs->e3 * rhs->e345 
            + lhs->e345 * rhs->e3 + lhs->e4 * rhs->e335 + lhs->e335 * rhs->e4 
            + lhs->e5 * rhs->e334 + lhs->e334 * rhs->e5 + lhs->e33 * rhs->e45 
            + lhs->e34 * rhs->e35 + lhs->e35 * rhs->e34 + lhs->e45 * rhs->e33;
  res.e1445 = lhs->r * rhs->e1445 + lhs->e1445 * rhs->r + lhs->e1 * rhs->e445 
            + lhs->e445 * rhs->e1 + lhs->e4 * rhs->e145 + lhs->e145 * rhs->e4 
            + lhs->e5 * rhs->e144 + lhs->e144 * rhs->e5 + lhs->e14 * rhs->e45 
            + lhs->e44 * rhs->e15 + lhs->e15 * rhs->e44 + lhs->e45 * rhs->e14;
  res.e2445 = lhs->r * rhs->e2445 + lhs->e2445 * rhs->r + lhs->e2 * rhs->e445 
            + lhs->e445 * rhs->e2 + lhs->e4 * rhs->e245 + lhs->e245 * rhs->e4 
            + lhs->e5 * rhs->e244 + lhs->e244 * rhs->e5 + lhs->e24 * rhs->e45 
            + lhs->e44 * rhs->e25 + lhs->e25 * rhs->e44 + lhs->e45 * rhs->e24;
  res.e3445 = lhs->r * rhs->e3445 + lhs->e3445 * rhs->r + lhs->e3 * rhs->e445 
            + lhs->e445 * rhs->e3 + lhs->e4 * rhs->e345 + lhs->e345 * rhs->e4 
            + lhs->e5 * rhs->e344 + lhs->e344 * rhs->e5 + lhs->e34 * rhs->e45 
            + lhs->e44 * rhs->e35 + lhs->e35 * rhs->e44 + lhs->e45 * rhs->e34;
  res.e4445 = lhs->r * rhs->e4445 + lhs->e4445 * rhs->r + lhs->e4 * rhs->e445 
            + lhs->e445 * rhs->e4 + lhs->e5 * rhs->e444 + lhs->e444 * rhs->e5 
            + lhs->e44 * rhs->e45 + lhs->e45 * rhs->e44;
  res.e1155 = lhs->r * rhs->e1155 + lhs->e1155 * rhs->r + lhs->e1 * rhs->e155 
            + lhs->e155 * rhs->e1 + lhs->e5 * rhs->e115 + lhs->e115 * rhs->e5 
            + lhs->e11 * rhs->e55 + lhs->e15 * rhs->e15 + lhs->e55 * rhs->e11;
  res.e1255 = lhs->r * rhs->e1255 + lhs->e1255 * rhs->r + lhs->e1 * rhs->e255 
            + lhs->e255 * rhs->e1 + lhs->e2 * rhs->e155 + lhs->e155 * rhs->e2 
            + lhs->e5 * rhs->e125 + lhs->e125 * rhs->e5 + lhs->e12 * rhs->e55 
            + lhs->e15 * rhs->e25 + lhs->e25 * rhs->e15 + lhs->e55 * rhs->e12;
  res.e2255 = lhs->r * rhs->e2255 + lhs->e2255 * rhs->r + lhs->e2 * rhs->e255 
            + lhs->e255 * rhs->e2 + lhs->e5 * rhs->e225 + lhs->e225 * rhs->e5 
            + lhs->e22 * rhs->e55 + lhs->e25 * rhs->e25 + lhs->e55 * rhs->e22;
  res.e1355 = lhs->r * rhs->e1355 + lhs->e1355 * rhs->r + lhs->e1 * rhs->e355 
            + lhs->e355 * rhs->e1 + lhs->e3 * rhs->e155 + lhs->e155 * rhs->e3 
            + lhs->e5 * rhs->e135 + lhs->e135 * rhs->e5 + lhs->e13 * rhs->e55 
            + lhs->e15 * rhs->e35 + lhs->e35 * rhs->e15 + lhs->e55 * rhs->e13;
  res.e2355 = lhs->r * rhs->e2355 + lhs->e2355 * rhs->r + lhs->e2 * rhs->e355 
            + lhs->e355 * rhs->e2 + lhs->e3 * rhs->e255 + lhs->e255 * rhs->e3 
            + lhs->e5 * rhs->e235 + lhs->e235 * rhs->e5 + lhs->e23 * rhs->e55 
            + lhs->e25 * rhs->e35 + lhs->e35 * rhs->e25 + lhs->e55 * rhs->e23;
  res.e3355 = lhs->r * rhs->e3355 + lhs->e3355 * rhs->r + lhs->e3 * rhs->e355 
            + lhs->e355 * rhs->e3 + lhs->e5 * rhs->e335 + lhs->e335 * rhs->e5 
            + lhs->e33 * rhs->e55 + lhs->e35 * rhs->e35 + lhs->e55 * rhs->e33;
  res.e1455 = lhs->r * rhs->e1455 + lhs->e1455 * rhs->r + lhs->e1 * rhs->e455 
            + lhs->e455 * rhs->e1 + lhs->e4 * rhs->e155 + lhs->e155 * rhs->e4 
            + lhs->e5 * rhs->e145 + lhs->e145 * rhs->e5 + lhs->e14 * rhs->e55 
            + lhs->e15 * rhs->e45 + lhs->e45 * rhs->e15 + lhs->e55 * rhs->e14;
  res.e2455 = lhs->r * rhs->e2455 + lhs->e2455 * rhs->r + lhs->e2 * rhs->e455 
            + lhs->e455 * rhs->e2 + lhs->e4 * rhs->e255 + lhs->e255 * rhs->e4 
            + lhs->e5 * rhs->e245 + lhs->e245 * rhs->e5 + lhs->e24 * rhs->e55 
            + lhs->e25 * rhs->e45 + lhs->e45 * rhs->e25 + lhs->e55 * rhs->e24;
  res.e3455 = lhs->r * rhs->e3455 + lhs->e3455 * rhs->r + lhs->e3 * rhs->e455 
            + lhs->e455 * rhs->e3 + lhs->e4 * rhs->e355 + lhs->e355 * rhs->e4 
            + lhs->e5 * rhs->e345 + lhs->e345 * rhs->e5 + lhs->e34 * rhs->e55 
            + lhs->e35 * rhs->e45 + lhs->e45 * rhs->e35 + lhs->e55 * rhs->e34;
  res.e4455 = lhs->r * rhs->e4455 + lhs->e4455 * rhs->r + lhs->e4 * rhs->e455 
            + lhs->e455 * rhs->e4 + lhs->e5 * rhs->e445 + lhs->e445 * rhs->e5 
            + lhs->e44 * rhs->e55 + lhs->e45 * rhs->e45 + lhs->e55 * rhs->e44;
  res.e1555 = lhs->r * rhs->e1555 + lhs->e1555 * rhs->r + lhs->e1 * rhs->e555 
            + lhs->e555 * rhs->e1 + lhs->e5 * rhs->e155 + lhs->e155 * rhs->e5 
            + lhs->e15 * rhs->e55 + lhs->e55 * rhs->e15;
  res.e2555 = lhs->r * rhs->e2555 + lhs->e2555 * rhs->r + lhs->e2 * rhs->e555 
            + lhs->e555 * rhs->e2 + lhs->e5 * rhs->e255 + lhs->e255 * rhs->e5 
            + lhs->e25 * rhs->e55 + lhs->e55 * rhs->e25;
  res.e3555 = lhs->r * rhs->e3555 + lhs->e3555 * rhs->r + lhs->e3 * rhs->e555 
            + lhs->e555 * rhs->e3 + lhs->e5 * rhs->e355 + lhs->e355 * rhs->e5 
            + lhs->e35 * rhs->e55 + lhs->e55 * rhs->e35;
  res.e4555 = lhs->r * rhs->e4555 + lhs->e4555 * rhs->r + lhs->e4 * rhs->e555 
            + lhs->e555 * rhs->e4 + lhs->e5 * rhs->e455 + lhs->e455 * rhs->e5 
            + lhs->e45 * rhs->e55 + lhs->e55 * rhs->e45;
  res.e5555 = lhs->r * rhs->e5555 + lhs->e5555 * rhs->r + lhs->e5 * rhs->e555 
            + lhs->e555 * rhs->e5 + lhs->e55 * rhs->e55;
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
  res.e11115 = lhs->r * rhs->e11115 + lhs->e11115 * rhs->r + lhs->e1 * rhs->e1115 
             + lhs->e1115 * rhs->e1 + lhs->e5 * rhs->e1111 + lhs->e1111 * rhs->e5 
             + lhs->e11 * rhs->e115 + lhs->e115 * rhs->e11 + lhs->e15 * rhs->e111 
             + lhs->e111 * rhs->e15;
  res.e11125 = lhs->r * rhs->e11125 + lhs->e11125 * rhs->r + lhs->e1 * rhs->e1125 
             + lhs->e1125 * rhs->e1 + lhs->e2 * rhs->e1115 + lhs->e1115 * rhs->e2 
             + lhs->e5 * rhs->e1112 + lhs->e1112 * rhs->e5 + lhs->e11 * rhs->e125 
             + lhs->e125 * rhs->e11 + lhs->e12 * rhs->e115 + lhs->e115 * rhs->e12 
             + lhs->e15 * rhs->e112 + lhs->e112 * rhs->e15 + lhs->e25 * rhs->e111 
             + lhs->e111 * rhs->e25;
  res.e11225 = lhs->r * rhs->e11225 + lhs->e11225 * rhs->r + lhs->e1 * rhs->e1225 
             + lhs->e1225 * rhs->e1 + lhs->e2 * rhs->e1125 + lhs->e1125 * rhs->e2 
             + lhs->e5 * rhs->e1122 + lhs->e1122 * rhs->e5 + lhs->e11 * rhs->e225 
             + lhs->e225 * rhs->e11 + lhs->e12 * rhs->e125 + lhs->e125 * rhs->e12 
             + lhs->e22 * rhs->e115 + lhs->e115 * rhs->e22 + lhs->e15 * rhs->e122 
             + lhs->e122 * rhs->e15 + lhs->e25 * rhs->e112 + lhs->e112 * rhs->e25;
  res.e12225 = lhs->r * rhs->e12225 + lhs->e12225 * rhs->r + lhs->e1 * rhs->e2225 
             + lhs->e2225 * rhs->e1 + lhs->e2 * rhs->e1225 + lhs->e1225 * rhs->e2 
             + lhs->e5 * rhs->e1222 + lhs->e1222 * rhs->e5 + lhs->e12 * rhs->e225 
             + lhs->e225 * rhs->e12 + lhs->e22 * rhs->e125 + lhs->e125 * rhs->e22 
             + lhs->e15 * rhs->e222 + lhs->e222 * rhs->e15 + lhs->e25 * rhs->e122 
             + lhs->e122 * rhs->e25;
  res.e22225 = lhs->r * rhs->e22225 + lhs->e22225 * rhs->r + lhs->e2 * rhs->e2225 
             + lhs->e2225 * rhs->e2 + lhs->e5 * rhs->e2222 + lhs->e2222 * rhs->e5 
             + lhs->e22 * rhs->e225 + lhs->e225 * rhs->e22 + lhs->e25 * rhs->e222 
             + lhs->e222 * rhs->e25;
  res.e11135 = lhs->r * rhs->e11135 + lhs->e11135 * rhs->r + lhs->e1 * rhs->e1135 
             + lhs->e1135 * rhs->e1 + lhs->e3 * rhs->e1115 + lhs->e1115 * rhs->e3 
             + lhs->e5 * rhs->e1113 + lhs->e1113 * rhs->e5 + lhs->e11 * rhs->e135 
             + lhs->e135 * rhs->e11 + lhs->e13 * rhs->e115 + lhs->e115 * rhs->e13 
             + lhs->e15 * rhs->e113 + lhs->e113 * rhs->e15 + lhs->e35 * rhs->e111 
             + lhs->e111 * rhs->e35;
  res.e11235 = lhs->r * rhs->e11235 + lhs->e11235 * rhs->r + lhs->e1 * rhs->e1235 
             + lhs->e1235 * rhs->e1 + lhs->e2 * rhs->e1135 + lhs->e1135 * rhs->e2 
             + lhs->e3 * rhs->e1125 + lhs->e1125 * rhs->e3 + lhs->e5 * rhs->e1123 
             + lhs->e1123 * rhs->e5 + lhs->e11 * rhs->e235 + lhs->e235 * rhs->e11 
             + lhs->e12 * rhs->e135 + lhs->e135 * rhs->e12 + lhs->e13 * rhs->e125 
             + lhs->e125 * rhs->e13 + lhs->e23 * rhs->e115 + lhs->e115 * rhs->e23 
             + lhs->e15 * rhs->e123 + lhs->e123 * rhs->e15 + lhs->e25 * rhs->e113 
             + lhs->e113 * rhs->e25 + lhs->e35 * rhs->e112 + lhs->e112 * rhs->e35;
  res.e12235 = lhs->r * rhs->e12235 + lhs->e12235 * rhs->r + lhs->e1 * rhs->e2235 
             + lhs->e2235 * rhs->e1 + lhs->e2 * rhs->e1235 + lhs->e1235 * rhs->e2 
             + lhs->e3 * rhs->e1225 + lhs->e1225 * rhs->e3 + lhs->e5 * rhs->e1223 
             + lhs->e1223 * rhs->e5 + lhs->e12 * rhs->e235 + lhs->e235 * rhs->e12 
             + lhs->e22 * rhs->e135 + lhs->e135 * rhs->e22 + lhs->e13 * rhs->e225 
             + lhs->e225 * rhs->e13 + lhs->e23 * rhs->e125 + lhs->e125 * rhs->e23 
             + lhs->e15 * rhs->e223 + lhs->e223 * rhs->e15 + lhs->e25 * rhs->e123 
             + lhs->e123 * rhs->e25 + lhs->e35 * rhs->e122 + lhs->e122 * rhs->e35;
  res.e22235 = lhs->r * rhs->e22235 + lhs->e22235 * rhs->r + lhs->e2 * rhs->e2235 
             + lhs->e2235 * rhs->e2 + lhs->e3 * rhs->e2225 + lhs->e2225 * rhs->e3 
             + lhs->e5 * rhs->e2223 + lhs->e2223 * rhs->e5 + lhs->e22 * rhs->e235 
             + lhs->e235 * rhs->e22 + lhs->e23 * rhs->e225 + lhs->e225 * rhs->e23 
             + lhs->e25 * rhs->e223 + lhs->e223 * rhs->e25 + lhs->e35 * rhs->e222 
             + lhs->e222 * rhs->e35;
  res.e11335 = lhs->r * rhs->e11335 + lhs->e11335 * rhs->r + lhs->e1 * rhs->e1335 
             + lhs->e1335 * rhs->e1 + lhs->e3 * rhs->e1135 + lhs->e1135 * rhs->e3 
             + lhs->e5 * rhs->e1133 + lhs->e1133 * rhs->e5 + lhs->e11 * rhs->e335 
             + lhs->e335 * rhs->e11 + lhs->e13 * rhs->e135 + lhs->e135 * rhs->e13 
             + lhs->e33 * rhs->e115 + lhs->e115 * rhs->e33 + lhs->e15 * rhs->e133 
             + lhs->e133 * rhs->e15 + lhs->e35 * rhs->e113 + lhs->e113 * rhs->e35;
  res.e12335 = lhs->r * rhs->e12335 + lhs->e12335 * rhs->r + lhs->e1 * rhs->e2335 
             + lhs->e2335 * rhs->e1 + lhs->e2 * rhs->e1335 + lhs->e1335 * rhs->e2 
             + lhs->e3 * rhs->e1235 + lhs->e1235 * rhs->e3 + lhs->e5 * rhs->e1233 
             + lhs->e1233 * rhs->e5 + lhs->e12 * rhs->e335 + lhs->e335 * rhs->e12 
             + lhs->e13 * rhs->e235 + lhs->e235 * rhs->e13 + lhs->e23 * rhs->e135 
             + lhs->e135 * rhs->e23 + lhs->e33 * rhs->e125 + lhs->e125 * rhs->e33 
             + lhs->e15 * rhs->e233 + lhs->e233 * rhs->e15 + lhs->e25 * rhs->e133 
             + lhs->e133 * rhs->e25 + lhs->e35 * rhs->e123 + lhs->e123 * rhs->e35;
  res.e22335 = lhs->r * rhs->e22335 + lhs->e22335 * rhs->r + lhs->e2 * rhs->e2335 
             + lhs->e2335 * rhs->e2 + lhs->e3 * rhs->e2235 + lhs->e2235 * rhs->e3 
             + lhs->e5 * rhs->e2233 + lhs->e2233 * rhs->e5 + lhs->e22 * rhs->e335 
             + lhs->e335 * rhs->e22 + lhs->e23 * rhs->e235 + lhs->e235 * rhs->e23 
             + lhs->e33 * rhs->e225 + lhs->e225 * rhs->e33 + lhs->e25 * rhs->e233 
             + lhs->e233 * rhs->e25 + lhs->e35 * rhs->e223 + lhs->e223 * rhs->e35;
  res.e13335 = lhs->r * rhs->e13335 + lhs->e13335 * rhs->r + lhs->e1 * rhs->e3335 
             + lhs->e3335 * rhs->e1 + lhs->e3 * rhs->e1335 + lhs->e1335 * rhs->e3 
             + lhs->e5 * rhs->e1333 + lhs->e1333 * rhs->e5 + lhs->e13 * rhs->e335 
             + lhs->e335 * rhs->e13 + lhs->e33 * rhs->e135 + lhs->e135 * rhs->e33 
             + lhs->e15 * rhs->e333 + lhs->e333 * rhs->e15 + lhs->e35 * rhs->e133 
             + lhs->e133 * rhs->e35;
  res.e23335 = lhs->r * rhs->e23335 + lhs->e23335 * rhs->r + lhs->e2 * rhs->e3335 
             + lhs->e3335 * rhs->e2 + lhs->e3 * rhs->e2335 + lhs->e2335 * rhs->e3 
             + lhs->e5 * rhs->e2333 + lhs->e2333 * rhs->e5 + lhs->e23 * rhs->e335 
             + lhs->e335 * rhs->e23 + lhs->e33 * rhs->e235 + lhs->e235 * rhs->e33 
             + lhs->e25 * rhs->e333 + lhs->e333 * rhs->e25 + lhs->e35 * rhs->e233 
             + lhs->e233 * rhs->e35;
  res.e33335 = lhs->r * rhs->e33335 + lhs->e33335 * rhs->r + lhs->e3 * rhs->e3335 
             + lhs->e3335 * rhs->e3 + lhs->e5 * rhs->e3333 + lhs->e3333 * rhs->e5 
             + lhs->e33 * rhs->e335 + lhs->e335 * rhs->e33 + lhs->e35 * rhs->e333 
             + lhs->e333 * rhs->e35;
  res.e11145 = lhs->r * rhs->e11145 + lhs->e11145 * rhs->r + lhs->e1 * rhs->e1145 
             + lhs->e1145 * rhs->e1 + lhs->e4 * rhs->e1115 + lhs->e1115 * rhs->e4 
             + lhs->e5 * rhs->e1114 + lhs->e1114 * rhs->e5 + lhs->e11 * rhs->e145 
             + lhs->e145 * rhs->e11 + lhs->e14 * rhs->e115 + lhs->e115 * rhs->e14 
             + lhs->e15 * rhs->e114 + lhs->e114 * rhs->e15 + lhs->e45 * rhs->e111 
             + lhs->e111 * rhs->e45;
  res.e11245 = lhs->r * rhs->e11245 + lhs->e11245 * rhs->r + lhs->e1 * rhs->e1245 
             + lhs->e1245 * rhs->e1 + lhs->e2 * rhs->e1145 + lhs->e1145 * rhs->e2 
             + lhs->e4 * rhs->e1125 + lhs->e1125 * rhs->e4 + lhs->e5 * rhs->e1124 
             + lhs->e1124 * rhs->e5 + lhs->e11 * rhs->e245 + lhs->e245 * rhs->e11 
             + lhs->e12 * rhs->e145 + lhs->e145 * rhs->e12 + lhs->e14 * rhs->e125 
             + lhs->e125 * rhs->e14 + lhs->e24 * rhs->e115 + lhs->e115 * rhs->e24 
             + lhs->e15 * rhs->e124 + lhs->e124 * rhs->e15 + lhs->e25 * rhs->e114 
             + lhs->e114 * rhs->e25 + lhs->e45 * rhs->e112 + lhs->e112 * rhs->e45;
  res.e12245 = lhs->r * rhs->e12245 + lhs->e12245 * rhs->r + lhs->e1 * rhs->e2245 
             + lhs->e2245 * rhs->e1 + lhs->e2 * rhs->e1245 + lhs->e1245 * rhs->e2 
             + lhs->e4 * rhs->e1225 + lhs->e1225 * rhs->e4 + lhs->e5 * rhs->e1224 
             + lhs->e1224 * rhs->e5 + lhs->e12 * rhs->e245 + lhs->e245 * rhs->e12 
             + lhs->e22 * rhs->e145 + lhs->e145 * rhs->e22 + lhs->e14 * rhs->e225 
             + lhs->e225 * rhs->e14 + lhs->e24 * rhs->e125 + lhs->e125 * rhs->e24 
             + lhs->e15 * rhs->e224 + lhs->e224 * rhs->e15 + lhs->e25 * rhs->e124 
             + lhs->e124 * rhs->e25 + lhs->e45 * rhs->e122 + lhs->e122 * rhs->e45;
  res.e22245 = lhs->r * rhs->e22245 + lhs->e22245 * rhs->r + lhs->e2 * rhs->e2245 
             + lhs->e2245 * rhs->e2 + lhs->e4 * rhs->e2225 + lhs->e2225 * rhs->e4 
             + lhs->e5 * rhs->e2224 + lhs->e2224 * rhs->e5 + lhs->e22 * rhs->e245 
             + lhs->e245 * rhs->e22 + lhs->e24 * rhs->e225 + lhs->e225 * rhs->e24 
             + lhs->e25 * rhs->e224 + lhs->e224 * rhs->e25 + lhs->e45 * rhs->e222 
             + lhs->e222 * rhs->e45;
  res.e11345 = lhs->r * rhs->e11345 + lhs->e11345 * rhs->r + lhs->e1 * rhs->e1345 
             + lhs->e1345 * rhs->e1 + lhs->e3 * rhs->e1145 + lhs->e1145 * rhs->e3 
             + lhs->e4 * rhs->e1135 + lhs->e1135 * rhs->e4 + lhs->e5 * rhs->e1134 
             + lhs->e1134 * rhs->e5 + lhs->e11 * rhs->e345 + lhs->e345 * rhs->e11 
             + lhs->e13 * rhs->e145 + lhs->e145 * rhs->e13 + lhs->e14 * rhs->e135 
             + lhs->e135 * rhs->e14 + lhs->e34 * rhs->e115 + lhs->e115 * rhs->e34 
             + lhs->e15 * rhs->e134 + lhs->e134 * rhs->e15 + lhs->e35 * rhs->e114 
             + lhs->e114 * rhs->e35 + lhs->e45 * rhs->e113 + lhs->e113 * rhs->e45;
  res.e12345 = lhs->r * rhs->e12345 + lhs->e12345 * rhs->r + lhs->e1 * rhs->e2345 
             + lhs->e2345 * rhs->e1 + lhs->e2 * rhs->e1345 + lhs->e1345 * rhs->e2 
             + lhs->e3 * rhs->e1245 + lhs->e1245 * rhs->e3 + lhs->e4 * rhs->e1235 
             + lhs->e1235 * rhs->e4 + lhs->e5 * rhs->e1234 + lhs->e1234 * rhs->e5 
             + lhs->e12 * rhs->e345 + lhs->e345 * rhs->e12 + lhs->e13 * rhs->e245 
             + lhs->e245 * rhs->e13 + lhs->e23 * rhs->e145 + lhs->e145 * rhs->e23 
             + lhs->e14 * rhs->e235 + lhs->e235 * rhs->e14 + lhs->e24 * rhs->e135 
             + lhs->e135 * rhs->e24 + lhs->e34 * rhs->e125 + lhs->e125 * rhs->e34 
             + lhs->e15 * rhs->e234 + lhs->e234 * rhs->e15 + lhs->e25 * rhs->e134 
             + lhs->e134 * rhs->e25 + lhs->e35 * rhs->e124 + lhs->e124 * rhs->e35 
             + lhs->e45 * rhs->e123 + lhs->e123 * rhs->e45;
  res.e22345 = lhs->r * rhs->e22345 + lhs->e22345 * rhs->r + lhs->e2 * rhs->e2345 
             + lhs->e2345 * rhs->e2 + lhs->e3 * rhs->e2245 + lhs->e2245 * rhs->e3 
             + lhs->e4 * rhs->e2235 + lhs->e2235 * rhs->e4 + lhs->e5 * rhs->e2234 
             + lhs->e2234 * rhs->e5 + lhs->e22 * rhs->e345 + lhs->e345 * rhs->e22 
             + lhs->e23 * rhs->e245 + lhs->e245 * rhs->e23 + lhs->e24 * rhs->e235 
             + lhs->e235 * rhs->e24 + lhs->e34 * rhs->e225 + lhs->e225 * rhs->e34 
             + lhs->e25 * rhs->e234 + lhs->e234 * rhs->e25 + lhs->e35 * rhs->e224 
             + lhs->e224 * rhs->e35 + lhs->e45 * rhs->e223 + lhs->e223 * rhs->e45;
  res.e13345 = lhs->r * rhs->e13345 + lhs->e13345 * rhs->r + lhs->e1 * rhs->e3345 
             + lhs->e3345 * rhs->e1 + lhs->e3 * rhs->e1345 + lhs->e1345 * rhs->e3 
             + lhs->e4 * rhs->e1335 + lhs->e1335 * rhs->e4 + lhs->e5 * rhs->e1334 
             + lhs->e1334 * rhs->e5 + lhs->e13 * rhs->e345 + lhs->e345 * rhs->e13 
             + lhs->e33 * rhs->e145 + lhs->e145 * rhs->e33 + lhs->e14 * rhs->e335 
             + lhs->e335 * rhs->e14 + lhs->e34 * rhs->e135 + lhs->e135 * rhs->e34 
             + lhs->e15 * rhs->e334 + lhs->e334 * rhs->e15 + lhs->e35 * rhs->e134 
             + lhs->e134 * rhs->e35 + lhs->e45 * rhs->e133 + lhs->e133 * rhs->e45;
  res.e23345 = lhs->r * rhs->e23345 + lhs->e23345 * rhs->r + lhs->e2 * rhs->e3345 
             + lhs->e3345 * rhs->e2 + lhs->e3 * rhs->e2345 + lhs->e2345 * rhs->e3 
             + lhs->e4 * rhs->e2335 + lhs->e2335 * rhs->e4 + lhs->e5 * rhs->e2334 
             + lhs->e2334 * rhs->e5 + lhs->e23 * rhs->e345 + lhs->e345 * rhs->e23 
             + lhs->e33 * rhs->e245 + lhs->e245 * rhs->e33 + lhs->e24 * rhs->e335 
             + lhs->e335 * rhs->e24 + lhs->e34 * rhs->e235 + lhs->e235 * rhs->e34 
             + lhs->e25 * rhs->e334 + lhs->e334 * rhs->e25 + lhs->e35 * rhs->e234 
             + lhs->e234 * rhs->e35 + lhs->e45 * rhs->e233 + lhs->e233 * rhs->e45;
  res.e33345 = lhs->r * rhs->e33345 + lhs->e33345 * rhs->r + lhs->e3 * rhs->e3345 
             + lhs->e3345 * rhs->e3 + lhs->e4 * rhs->e3335 + lhs->e3335 * rhs->e4 
             + lhs->e5 * rhs->e3334 + lhs->e3334 * rhs->e5 + lhs->e33 * rhs->e345 
             + lhs->e345 * rhs->e33 + lhs->e34 * rhs->e335 + lhs->e335 * rhs->e34 
             + lhs->e35 * rhs->e334 + lhs->e334 * rhs->e35 + lhs->e45 * rhs->e333 
             + lhs->e333 * rhs->e45;
  res.e11445 = lhs->r * rhs->e11445 + lhs->e11445 * rhs->r + lhs->e1 * rhs->e1445 
             + lhs->e1445 * rhs->e1 + lhs->e4 * rhs->e1145 + lhs->e1145 * rhs->e4 
             + lhs->e5 * rhs->e1144 + lhs->e1144 * rhs->e5 + lhs->e11 * rhs->e445 
             + lhs->e445 * rhs->e11 + lhs->e14 * rhs->e145 + lhs->e145 * rhs->e14 
             + lhs->e44 * rhs->e115 + lhs->e115 * rhs->e44 + lhs->e15 * rhs->e144 
             + lhs->e144 * rhs->e15 + lhs->e45 * rhs->e114 + lhs->e114 * rhs->e45;
  res.e12445 = lhs->r * rhs->e12445 + lhs->e12445 * rhs->r + lhs->e1 * rhs->e2445 
             + lhs->e2445 * rhs->e1 + lhs->e2 * rhs->e1445 + lhs->e1445 * rhs->e2 
             + lhs->e4 * rhs->e1245 + lhs->e1245 * rhs->e4 + lhs->e5 * rhs->e1244 
             + lhs->e1244 * rhs->e5 + lhs->e12 * rhs->e445 + lhs->e445 * rhs->e12 
             + lhs->e14 * rhs->e245 + lhs->e245 * rhs->e14 + lhs->e24 * rhs->e145 
             + lhs->e145 * rhs->e24 + lhs->e44 * rhs->e125 + lhs->e125 * rhs->e44 
             + lhs->e15 * rhs->e244 + lhs->e244 * rhs->e15 + lhs->e25 * rhs->e144 
             + lhs->e144 * rhs->e25 + lhs->e45 * rhs->e124 + lhs->e124 * rhs->e45;
  res.e22445 = lhs->r * rhs->e22445 + lhs->e22445 * rhs->r + lhs->e2 * rhs->e2445 
             + lhs->e2445 * rhs->e2 + lhs->e4 * rhs->e2245 + lhs->e2245 * rhs->e4 
             + lhs->e5 * rhs->e2244 + lhs->e2244 * rhs->e5 + lhs->e22 * rhs->e445 
             + lhs->e445 * rhs->e22 + lhs->e24 * rhs->e245 + lhs->e245 * rhs->e24 
             + lhs->e44 * rhs->e225 + lhs->e225 * rhs->e44 + lhs->e25 * rhs->e244 
             + lhs->e244 * rhs->e25 + lhs->e45 * rhs->e224 + lhs->e224 * rhs->e45;
  res.e13445 = lhs->r * rhs->e13445 + lhs->e13445 * rhs->r + lhs->e1 * rhs->e3445 
             + lhs->e3445 * rhs->e1 + lhs->e3 * rhs->e1445 + lhs->e1445 * rhs->e3 
             + lhs->e4 * rhs->e1345 + lhs->e1345 * rhs->e4 + lhs->e5 * rhs->e1344 
             + lhs->e1344 * rhs->e5 + lhs->e13 * rhs->e445 + lhs->e445 * rhs->e13 
             + lhs->e14 * rhs->e345 + lhs->e345 * rhs->e14 + lhs->e34 * rhs->e145 
             + lhs->e145 * rhs->e34 + lhs->e44 * rhs->e135 + lhs->e135 * rhs->e44 
             + lhs->e15 * rhs->e344 + lhs->e344 * rhs->e15 + lhs->e35 * rhs->e144 
             + lhs->e144 * rhs->e35 + lhs->e45 * rhs->e134 + lhs->e134 * rhs->e45;
  res.e23445 = lhs->r * rhs->e23445 + lhs->e23445 * rhs->r + lhs->e2 * rhs->e3445 
             + lhs->e3445 * rhs->e2 + lhs->e3 * rhs->e2445 + lhs->e2445 * rhs->e3 
             + lhs->e4 * rhs->e2345 + lhs->e2345 * rhs->e4 + lhs->e5 * rhs->e2344 
             + lhs->e2344 * rhs->e5 + lhs->e23 * rhs->e445 + lhs->e445 * rhs->e23 
             + lhs->e24 * rhs->e345 + lhs->e345 * rhs->e24 + lhs->e34 * rhs->e245 
             + lhs->e245 * rhs->e34 + lhs->e44 * rhs->e235 + lhs->e235 * rhs->e44 
             + lhs->e25 * rhs->e344 + lhs->e344 * rhs->e25 + lhs->e35 * rhs->e244 
             + lhs->e244 * rhs->e35 + lhs->e45 * rhs->e234 + lhs->e234 * rhs->e45;
  res.e33445 = lhs->r * rhs->e33445 + lhs->e33445 * rhs->r + lhs->e3 * rhs->e3445 
             + lhs->e3445 * rhs->e3 + lhs->e4 * rhs->e3345 + lhs->e3345 * rhs->e4 
             + lhs->e5 * rhs->e3344 + lhs->e3344 * rhs->e5 + lhs->e33 * rhs->e445 
             + lhs->e445 * rhs->e33 + lhs->e34 * rhs->e345 + lhs->e345 * rhs->e34 
             + lhs->e44 * rhs->e335 + lhs->e335 * rhs->e44 + lhs->e35 * rhs->e344 
             + lhs->e344 * rhs->e35 + lhs->e45 * rhs->e334 + lhs->e334 * rhs->e45;
  res.e14445 = lhs->r * rhs->e14445 + lhs->e14445 * rhs->r + lhs->e1 * rhs->e4445 
             + lhs->e4445 * rhs->e1 + lhs->e4 * rhs->e1445 + lhs->e1445 * rhs->e4 
             + lhs->e5 * rhs->e1444 + lhs->e1444 * rhs->e5 + lhs->e14 * rhs->e445 
             + lhs->e445 * rhs->e14 + lhs->e44 * rhs->e145 + lhs->e145 * rhs->e44 
             + lhs->e15 * rhs->e444 + lhs->e444 * rhs->e15 + lhs->e45 * rhs->e144 
             + lhs->e144 * rhs->e45;
  res.e24445 = lhs->r * rhs->e24445 + lhs->e24445 * rhs->r + lhs->e2 * rhs->e4445 
             + lhs->e4445 * rhs->e2 + lhs->e4 * rhs->e2445 + lhs->e2445 * rhs->e4 
             + lhs->e5 * rhs->e2444 + lhs->e2444 * rhs->e5 + lhs->e24 * rhs->e445 
             + lhs->e445 * rhs->e24 + lhs->e44 * rhs->e245 + lhs->e245 * rhs->e44 
             + lhs->e25 * rhs->e444 + lhs->e444 * rhs->e25 + lhs->e45 * rhs->e244 
             + lhs->e244 * rhs->e45;
  res.e34445 = lhs->r * rhs->e34445 + lhs->e34445 * rhs->r + lhs->e3 * rhs->e4445 
             + lhs->e4445 * rhs->e3 + lhs->e4 * rhs->e3445 + lhs->e3445 * rhs->e4 
             + lhs->e5 * rhs->e3444 + lhs->e3444 * rhs->e5 + lhs->e34 * rhs->e445 
             + lhs->e445 * rhs->e34 + lhs->e44 * rhs->e345 + lhs->e345 * rhs->e44 
             + lhs->e35 * rhs->e444 + lhs->e444 * rhs->e35 + lhs->e45 * rhs->e344 
             + lhs->e344 * rhs->e45;
  res.e44445 = lhs->r * rhs->e44445 + lhs->e44445 * rhs->r + lhs->e4 * rhs->e4445 
             + lhs->e4445 * rhs->e4 + lhs->e5 * rhs->e4444 + lhs->e4444 * rhs->e5 
             + lhs->e44 * rhs->e445 + lhs->e445 * rhs->e44 + lhs->e45 * rhs->e444 
             + lhs->e444 * rhs->e45;
  res.e11155 = lhs->r * rhs->e11155 + lhs->e11155 * rhs->r + lhs->e1 * rhs->e1155 
             + lhs->e1155 * rhs->e1 + lhs->e5 * rhs->e1115 + lhs->e1115 * rhs->e5 
             + lhs->e11 * rhs->e155 + lhs->e155 * rhs->e11 + lhs->e15 * rhs->e115 
             + lhs->e115 * rhs->e15 + lhs->e55 * rhs->e111 + lhs->e111 * rhs->e55;
  res.e11255 = lhs->r * rhs->e11255 + lhs->e11255 * rhs->r + lhs->e1 * rhs->e1255 
             + lhs->e1255 * rhs->e1 + lhs->e2 * rhs->e1155 + lhs->e1155 * rhs->e2 
             + lhs->e5 * rhs->e1125 + lhs->e1125 * rhs->e5 + lhs->e11 * rhs->e255 
             + lhs->e255 * rhs->e11 + lhs->e12 * rhs->e155 + lhs->e155 * rhs->e12 
             + lhs->e15 * rhs->e125 + lhs->e125 * rhs->e15 + lhs->e25 * rhs->e115 
             + lhs->e115 * rhs->e25 + lhs->e55 * rhs->e112 + lhs->e112 * rhs->e55;
  res.e12255 = lhs->r * rhs->e12255 + lhs->e12255 * rhs->r + lhs->e1 * rhs->e2255 
             + lhs->e2255 * rhs->e1 + lhs->e2 * rhs->e1255 + lhs->e1255 * rhs->e2 
             + lhs->e5 * rhs->e1225 + lhs->e1225 * rhs->e5 + lhs->e12 * rhs->e255 
             + lhs->e255 * rhs->e12 + lhs->e22 * rhs->e155 + lhs->e155 * rhs->e22 
             + lhs->e15 * rhs->e225 + lhs->e225 * rhs->e15 + lhs->e25 * rhs->e125 
             + lhs->e125 * rhs->e25 + lhs->e55 * rhs->e122 + lhs->e122 * rhs->e55;
  res.e22255 = lhs->r * rhs->e22255 + lhs->e22255 * rhs->r + lhs->e2 * rhs->e2255 
             + lhs->e2255 * rhs->e2 + lhs->e5 * rhs->e2225 + lhs->e2225 * rhs->e5 
             + lhs->e22 * rhs->e255 + lhs->e255 * rhs->e22 + lhs->e25 * rhs->e225 
             + lhs->e225 * rhs->e25 + lhs->e55 * rhs->e222 + lhs->e222 * rhs->e55;
  res.e11355 = lhs->r * rhs->e11355 + lhs->e11355 * rhs->r + lhs->e1 * rhs->e1355 
             + lhs->e1355 * rhs->e1 + lhs->e3 * rhs->e1155 + lhs->e1155 * rhs->e3 
             + lhs->e5 * rhs->e1135 + lhs->e1135 * rhs->e5 + lhs->e11 * rhs->e355 
             + lhs->e355 * rhs->e11 + lhs->e13 * rhs->e155 + lhs->e155 * rhs->e13 
             + lhs->e15 * rhs->e135 + lhs->e135 * rhs->e15 + lhs->e35 * rhs->e115 
             + lhs->e115 * rhs->e35 + lhs->e55 * rhs->e113 + lhs->e113 * rhs->e55;
  res.e12355 = lhs->r * rhs->e12355 + lhs->e12355 * rhs->r + lhs->e1 * rhs->e2355 
             + lhs->e2355 * rhs->e1 + lhs->e2 * rhs->e1355 + lhs->e1355 * rhs->e2 
             + lhs->e3 * rhs->e1255 + lhs->e1255 * rhs->e3 + lhs->e5 * rhs->e1235 
             + lhs->e1235 * rhs->e5 + lhs->e12 * rhs->e355 + lhs->e355 * rhs->e12 
             + lhs->e13 * rhs->e255 + lhs->e255 * rhs->e13 + lhs->e23 * rhs->e155 
             + lhs->e155 * rhs->e23 + lhs->e15 * rhs->e235 + lhs->e235 * rhs->e15 
             + lhs->e25 * rhs->e135 + lhs->e135 * rhs->e25 + lhs->e35 * rhs->e125 
             + lhs->e125 * rhs->e35 + lhs->e55 * rhs->e123 + lhs->e123 * rhs->e55;
  res.e22355 = lhs->r * rhs->e22355 + lhs->e22355 * rhs->r + lhs->e2 * rhs->e2355 
             + lhs->e2355 * rhs->e2 + lhs->e3 * rhs->e2255 + lhs->e2255 * rhs->e3 
             + lhs->e5 * rhs->e2235 + lhs->e2235 * rhs->e5 + lhs->e22 * rhs->e355 
             + lhs->e355 * rhs->e22 + lhs->e23 * rhs->e255 + lhs->e255 * rhs->e23 
             + lhs->e25 * rhs->e235 + lhs->e235 * rhs->e25 + lhs->e35 * rhs->e225 
             + lhs->e225 * rhs->e35 + lhs->e55 * rhs->e223 + lhs->e223 * rhs->e55;
  res.e13355 = lhs->r * rhs->e13355 + lhs->e13355 * rhs->r + lhs->e1 * rhs->e3355 
             + lhs->e3355 * rhs->e1 + lhs->e3 * rhs->e1355 + lhs->e1355 * rhs->e3 
             + lhs->e5 * rhs->e1335 + lhs->e1335 * rhs->e5 + lhs->e13 * rhs->e355 
             + lhs->e355 * rhs->e13 + lhs->e33 * rhs->e155 + lhs->e155 * rhs->e33 
             + lhs->e15 * rhs->e335 + lhs->e335 * rhs->e15 + lhs->e35 * rhs->e135 
             + lhs->e135 * rhs->e35 + lhs->e55 * rhs->e133 + lhs->e133 * rhs->e55;
  res.e23355 = lhs->r * rhs->e23355 + lhs->e23355 * rhs->r + lhs->e2 * rhs->e3355 
             + lhs->e3355 * rhs->e2 + lhs->e3 * rhs->e2355 + lhs->e2355 * rhs->e3 
             + lhs->e5 * rhs->e2335 + lhs->e2335 * rhs->e5 + lhs->e23 * rhs->e355 
             + lhs->e355 * rhs->e23 + lhs->e33 * rhs->e255 + lhs->e255 * rhs->e33 
             + lhs->e25 * rhs->e335 + lhs->e335 * rhs->e25 + lhs->e35 * rhs->e235 
             + lhs->e235 * rhs->e35 + lhs->e55 * rhs->e233 + lhs->e233 * rhs->e55;
  res.e33355 = lhs->r * rhs->e33355 + lhs->e33355 * rhs->r + lhs->e3 * rhs->e3355 
             + lhs->e3355 * rhs->e3 + lhs->e5 * rhs->e3335 + lhs->e3335 * rhs->e5 
             + lhs->e33 * rhs->e355 + lhs->e355 * rhs->e33 + lhs->e35 * rhs->e335 
             + lhs->e335 * rhs->e35 + lhs->e55 * rhs->e333 + lhs->e333 * rhs->e55;
  res.e11455 = lhs->r * rhs->e11455 + lhs->e11455 * rhs->r + lhs->e1 * rhs->e1455 
             + lhs->e1455 * rhs->e1 + lhs->e4 * rhs->e1155 + lhs->e1155 * rhs->e4 
             + lhs->e5 * rhs->e1145 + lhs->e1145 * rhs->e5 + lhs->e11 * rhs->e455 
             + lhs->e455 * rhs->e11 + lhs->e14 * rhs->e155 + lhs->e155 * rhs->e14 
             + lhs->e15 * rhs->e145 + lhs->e145 * rhs->e15 + lhs->e45 * rhs->e115 
             + lhs->e115 * rhs->e45 + lhs->e55 * rhs->e114 + lhs->e114 * rhs->e55;
  res.e12455 = lhs->r * rhs->e12455 + lhs->e12455 * rhs->r + lhs->e1 * rhs->e2455 
             + lhs->e2455 * rhs->e1 + lhs->e2 * rhs->e1455 + lhs->e1455 * rhs->e2 
             + lhs->e4 * rhs->e1255 + lhs->e1255 * rhs->e4 + lhs->e5 * rhs->e1245 
             + lhs->e1245 * rhs->e5 + lhs->e12 * rhs->e455 + lhs->e455 * rhs->e12 
             + lhs->e14 * rhs->e255 + lhs->e255 * rhs->e14 + lhs->e24 * rhs->e155 
             + lhs->e155 * rhs->e24 + lhs->e15 * rhs->e245 + lhs->e245 * rhs->e15 
             + lhs->e25 * rhs->e145 + lhs->e145 * rhs->e25 + lhs->e45 * rhs->e125 
             + lhs->e125 * rhs->e45 + lhs->e55 * rhs->e124 + lhs->e124 * rhs->e55;
  res.e22455 = lhs->r * rhs->e22455 + lhs->e22455 * rhs->r + lhs->e2 * rhs->e2455 
             + lhs->e2455 * rhs->e2 + lhs->e4 * rhs->e2255 + lhs->e2255 * rhs->e4 
             + lhs->e5 * rhs->e2245 + lhs->e2245 * rhs->e5 + lhs->e22 * rhs->e455 
             + lhs->e455 * rhs->e22 + lhs->e24 * rhs->e255 + lhs->e255 * rhs->e24 
             + lhs->e25 * rhs->e245 + lhs->e245 * rhs->e25 + lhs->e45 * rhs->e225 
             + lhs->e225 * rhs->e45 + lhs->e55 * rhs->e224 + lhs->e224 * rhs->e55;
  res.e13455 = lhs->r * rhs->e13455 + lhs->e13455 * rhs->r + lhs->e1 * rhs->e3455 
             + lhs->e3455 * rhs->e1 + lhs->e3 * rhs->e1455 + lhs->e1455 * rhs->e3 
             + lhs->e4 * rhs->e1355 + lhs->e1355 * rhs->e4 + lhs->e5 * rhs->e1345 
             + lhs->e1345 * rhs->e5 + lhs->e13 * rhs->e455 + lhs->e455 * rhs->e13 
             + lhs->e14 * rhs->e355 + lhs->e355 * rhs->e14 + lhs->e34 * rhs->e155 
             + lhs->e155 * rhs->e34 + lhs->e15 * rhs->e345 + lhs->e345 * rhs->e15 
             + lhs->e35 * rhs->e145 + lhs->e145 * rhs->e35 + lhs->e45 * rhs->e135 
             + lhs->e135 * rhs->e45 + lhs->e55 * rhs->e134 + lhs->e134 * rhs->e55;
  res.e23455 = lhs->r * rhs->e23455 + lhs->e23455 * rhs->r + lhs->e2 * rhs->e3455 
             + lhs->e3455 * rhs->e2 + lhs->e3 * rhs->e2455 + lhs->e2455 * rhs->e3 
             + lhs->e4 * rhs->e2355 + lhs->e2355 * rhs->e4 + lhs->e5 * rhs->e2345 
             + lhs->e2345 * rhs->e5 + lhs->e23 * rhs->e455 + lhs->e455 * rhs->e23 
             + lhs->e24 * rhs->e355 + lhs->e355 * rhs->e24 + lhs->e34 * rhs->e255 
             + lhs->e255 * rhs->e34 + lhs->e25 * rhs->e345 + lhs->e345 * rhs->e25 
             + lhs->e35 * rhs->e245 + lhs->e245 * rhs->e35 + lhs->e45 * rhs->e235 
             + lhs->e235 * rhs->e45 + lhs->e55 * rhs->e234 + lhs->e234 * rhs->e55;
  res.e33455 = lhs->r * rhs->e33455 + lhs->e33455 * rhs->r + lhs->e3 * rhs->e3455 
             + lhs->e3455 * rhs->e3 + lhs->e4 * rhs->e3355 + lhs->e3355 * rhs->e4 
             + lhs->e5 * rhs->e3345 + lhs->e3345 * rhs->e5 + lhs->e33 * rhs->e455 
             + lhs->e455 * rhs->e33 + lhs->e34 * rhs->e355 + lhs->e355 * rhs->e34 
             + lhs->e35 * rhs->e345 + lhs->e345 * rhs->e35 + lhs->e45 * rhs->e335 
             + lhs->e335 * rhs->e45 + lhs->e55 * rhs->e334 + lhs->e334 * rhs->e55;
  res.e14455 = lhs->r * rhs->e14455 + lhs->e14455 * rhs->r + lhs->e1 * rhs->e4455 
             + lhs->e4455 * rhs->e1 + lhs->e4 * rhs->e1455 + lhs->e1455 * rhs->e4 
             + lhs->e5 * rhs->e1445 + lhs->e1445 * rhs->e5 + lhs->e14 * rhs->e455 
             + lhs->e455 * rhs->e14 + lhs->e44 * rhs->e155 + lhs->e155 * rhs->e44 
             + lhs->e15 * rhs->e445 + lhs->e445 * rhs->e15 + lhs->e45 * rhs->e145 
             + lhs->e145 * rhs->e45 + lhs->e55 * rhs->e144 + lhs->e144 * rhs->e55;
  res.e24455 = lhs->r * rhs->e24455 + lhs->e24455 * rhs->r + lhs->e2 * rhs->e4455 
             + lhs->e4455 * rhs->e2 + lhs->e4 * rhs->e2455 + lhs->e2455 * rhs->e4 
             + lhs->e5 * rhs->e2445 + lhs->e2445 * rhs->e5 + lhs->e24 * rhs->e455 
             + lhs->e455 * rhs->e24 + lhs->e44 * rhs->e255 + lhs->e255 * rhs->e44 
             + lhs->e25 * rhs->e445 + lhs->e445 * rhs->e25 + lhs->e45 * rhs->e245 
             + lhs->e245 * rhs->e45 + lhs->e55 * rhs->e244 + lhs->e244 * rhs->e55;
  res.e34455 = lhs->r * rhs->e34455 + lhs->e34455 * rhs->r + lhs->e3 * rhs->e4455 
             + lhs->e4455 * rhs->e3 + lhs->e4 * rhs->e3455 + lhs->e3455 * rhs->e4 
             + lhs->e5 * rhs->e3445 + lhs->e3445 * rhs->e5 + lhs->e34 * rhs->e455 
             + lhs->e455 * rhs->e34 + lhs->e44 * rhs->e355 + lhs->e355 * rhs->e44 
             + lhs->e35 * rhs->e445 + lhs->e445 * rhs->e35 + lhs->e45 * rhs->e345 
             + lhs->e345 * rhs->e45 + lhs->e55 * rhs->e344 + lhs->e344 * rhs->e55;
  res.e44455 = lhs->r * rhs->e44455 + lhs->e44455 * rhs->r + lhs->e4 * rhs->e4455 
             + lhs->e4455 * rhs->e4 + lhs->e5 * rhs->e4445 + lhs->e4445 * rhs->e5 
             + lhs->e44 * rhs->e455 + lhs->e455 * rhs->e44 + lhs->e45 * rhs->e445 
             + lhs->e445 * rhs->e45 + lhs->e55 * rhs->e444 + lhs->e444 * rhs->e55;
  res.e11555 = lhs->r * rhs->e11555 + lhs->e11555 * rhs->r + lhs->e1 * rhs->e1555 
             + lhs->e1555 * rhs->e1 + lhs->e5 * rhs->e1155 + lhs->e1155 * rhs->e5 
             + lhs->e11 * rhs->e555 + lhs->e555 * rhs->e11 + lhs->e15 * rhs->e155 
             + lhs->e155 * rhs->e15 + lhs->e55 * rhs->e115 + lhs->e115 * rhs->e55;
  res.e12555 = lhs->r * rhs->e12555 + lhs->e12555 * rhs->r + lhs->e1 * rhs->e2555 
             + lhs->e2555 * rhs->e1 + lhs->e2 * rhs->e1555 + lhs->e1555 * rhs->e2 
             + lhs->e5 * rhs->e1255 + lhs->e1255 * rhs->e5 + lhs->e12 * rhs->e555 
             + lhs->e555 * rhs->e12 + lhs->e15 * rhs->e255 + lhs->e255 * rhs->e15 
             + lhs->e25 * rhs->e155 + lhs->e155 * rhs->e25 + lhs->e55 * rhs->e125 
             + lhs->e125 * rhs->e55;
  res.e22555 = lhs->r * rhs->e22555 + lhs->e22555 * rhs->r + lhs->e2 * rhs->e2555 
             + lhs->e2555 * rhs->e2 + lhs->e5 * rhs->e2255 + lhs->e2255 * rhs->e5 
             + lhs->e22 * rhs->e555 + lhs->e555 * rhs->e22 + lhs->e25 * rhs->e255 
             + lhs->e255 * rhs->e25 + lhs->e55 * rhs->e225 + lhs->e225 * rhs->e55;
  res.e13555 = lhs->r * rhs->e13555 + lhs->e13555 * rhs->r + lhs->e1 * rhs->e3555 
             + lhs->e3555 * rhs->e1 + lhs->e3 * rhs->e1555 + lhs->e1555 * rhs->e3 
             + lhs->e5 * rhs->e1355 + lhs->e1355 * rhs->e5 + lhs->e13 * rhs->e555 
             + lhs->e555 * rhs->e13 + lhs->e15 * rhs->e355 + lhs->e355 * rhs->e15 
             + lhs->e35 * rhs->e155 + lhs->e155 * rhs->e35 + lhs->e55 * rhs->e135 
             + lhs->e135 * rhs->e55;
  res.e23555 = lhs->r * rhs->e23555 + lhs->e23555 * rhs->r + lhs->e2 * rhs->e3555 
             + lhs->e3555 * rhs->e2 + lhs->e3 * rhs->e2555 + lhs->e2555 * rhs->e3 
             + lhs->e5 * rhs->e2355 + lhs->e2355 * rhs->e5 + lhs->e23 * rhs->e555 
             + lhs->e555 * rhs->e23 + lhs->e25 * rhs->e355 + lhs->e355 * rhs->e25 
             + lhs->e35 * rhs->e255 + lhs->e255 * rhs->e35 + lhs->e55 * rhs->e235 
             + lhs->e235 * rhs->e55;
  res.e33555 = lhs->r * rhs->e33555 + lhs->e33555 * rhs->r + lhs->e3 * rhs->e3555 
             + lhs->e3555 * rhs->e3 + lhs->e5 * rhs->e3355 + lhs->e3355 * rhs->e5 
             + lhs->e33 * rhs->e555 + lhs->e555 * rhs->e33 + lhs->e35 * rhs->e355 
             + lhs->e355 * rhs->e35 + lhs->e55 * rhs->e335 + lhs->e335 * rhs->e55;
  res.e14555 = lhs->r * rhs->e14555 + lhs->e14555 * rhs->r + lhs->e1 * rhs->e4555 
             + lhs->e4555 * rhs->e1 + lhs->e4 * rhs->e1555 + lhs->e1555 * rhs->e4 
             + lhs->e5 * rhs->e1455 + lhs->e1455 * rhs->e5 + lhs->e14 * rhs->e555 
             + lhs->e555 * rhs->e14 + lhs->e15 * rhs->e455 + lhs->e455 * rhs->e15 
             + lhs->e45 * rhs->e155 + lhs->e155 * rhs->e45 + lhs->e55 * rhs->e145 
             + lhs->e145 * rhs->e55;
  res.e24555 = lhs->r * rhs->e24555 + lhs->e24555 * rhs->r + lhs->e2 * rhs->e4555 
             + lhs->e4555 * rhs->e2 + lhs->e4 * rhs->e2555 + lhs->e2555 * rhs->e4 
             + lhs->e5 * rhs->e2455 + lhs->e2455 * rhs->e5 + lhs->e24 * rhs->e555 
             + lhs->e555 * rhs->e24 + lhs->e25 * rhs->e455 + lhs->e455 * rhs->e25 
             + lhs->e45 * rhs->e255 + lhs->e255 * rhs->e45 + lhs->e55 * rhs->e245 
             + lhs->e245 * rhs->e55;
  res.e34555 = lhs->r * rhs->e34555 + lhs->e34555 * rhs->r + lhs->e3 * rhs->e4555 
             + lhs->e4555 * rhs->e3 + lhs->e4 * rhs->e3555 + lhs->e3555 * rhs->e4 
             + lhs->e5 * rhs->e3455 + lhs->e3455 * rhs->e5 + lhs->e34 * rhs->e555 
             + lhs->e555 * rhs->e34 + lhs->e35 * rhs->e455 + lhs->e455 * rhs->e35 
             + lhs->e45 * rhs->e355 + lhs->e355 * rhs->e45 + lhs->e55 * rhs->e345 
             + lhs->e345 * rhs->e55;
  res.e44555 = lhs->r * rhs->e44555 + lhs->e44555 * rhs->r + lhs->e4 * rhs->e4555 
             + lhs->e4555 * rhs->e4 + lhs->e5 * rhs->e4455 + lhs->e4455 * rhs->e5 
             + lhs->e44 * rhs->e555 + lhs->e555 * rhs->e44 + lhs->e45 * rhs->e455 
             + lhs->e455 * rhs->e45 + lhs->e55 * rhs->e445 + lhs->e445 * rhs->e55;
  res.e15555 = lhs->r * rhs->e15555 + lhs->e15555 * rhs->r + lhs->e1 * rhs->e5555 
             + lhs->e5555 * rhs->e1 + lhs->e5 * rhs->e1555 + lhs->e1555 * rhs->e5 
             + lhs->e15 * rhs->e555 + lhs->e555 * rhs->e15 + lhs->e55 * rhs->e155 
             + lhs->e155 * rhs->e55;
  res.e25555 = lhs->r * rhs->e25555 + lhs->e25555 * rhs->r + lhs->e2 * rhs->e5555 
             + lhs->e5555 * rhs->e2 + lhs->e5 * rhs->e2555 + lhs->e2555 * rhs->e5 
             + lhs->e25 * rhs->e555 + lhs->e555 * rhs->e25 + lhs->e55 * rhs->e255 
             + lhs->e255 * rhs->e55;
  res.e35555 = lhs->r * rhs->e35555 + lhs->e35555 * rhs->r + lhs->e3 * rhs->e5555 
             + lhs->e5555 * rhs->e3 + lhs->e5 * rhs->e3555 + lhs->e3555 * rhs->e5 
             + lhs->e35 * rhs->e555 + lhs->e555 * rhs->e35 + lhs->e55 * rhs->e355 
             + lhs->e355 * rhs->e55;
  res.e45555 = lhs->r * rhs->e45555 + lhs->e45555 * rhs->r + lhs->e4 * rhs->e5555 
             + lhs->e5555 * rhs->e4 + lhs->e5 * rhs->e4555 + lhs->e4555 * rhs->e5 
             + lhs->e45 * rhs->e555 + lhs->e555 * rhs->e45 + lhs->e55 * rhs->e455 
             + lhs->e455 * rhs->e55;
  res.e55555 = lhs->r * rhs->e55555 + lhs->e55555 * rhs->r + lhs->e5 * rhs->e5555 
             + lhs->e5555 * rhs->e5 + lhs->e55 * rhs->e555 + lhs->e555 * rhs->e55;

  return res;

}

void onumm5n5_mul_oo_to(  onumm5n5_t* lhs,  onumm5n5_t* rhs, onumm5n5_t* res){
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
  res->e1115 = lhs->r * rhs->e1115 + lhs->e1115 * rhs->r + lhs->e1 * rhs->e115 
            + lhs->e115 * rhs->e1 + lhs->e5 * rhs->e111 + lhs->e111 * rhs->e5 
            + lhs->e11 * rhs->e15 + lhs->e15 * rhs->e11;
  res->e1125 = lhs->r * rhs->e1125 + lhs->e1125 * rhs->r + lhs->e1 * rhs->e125 
            + lhs->e125 * rhs->e1 + lhs->e2 * rhs->e115 + lhs->e115 * rhs->e2 
            + lhs->e5 * rhs->e112 + lhs->e112 * rhs->e5 + lhs->e11 * rhs->e25 
            + lhs->e12 * rhs->e15 + lhs->e15 * rhs->e12 + lhs->e25 * rhs->e11;
  res->e1225 = lhs->r * rhs->e1225 + lhs->e1225 * rhs->r + lhs->e1 * rhs->e225 
            + lhs->e225 * rhs->e1 + lhs->e2 * rhs->e125 + lhs->e125 * rhs->e2 
            + lhs->e5 * rhs->e122 + lhs->e122 * rhs->e5 + lhs->e12 * rhs->e25 
            + lhs->e22 * rhs->e15 + lhs->e15 * rhs->e22 + lhs->e25 * rhs->e12;
  res->e2225 = lhs->r * rhs->e2225 + lhs->e2225 * rhs->r + lhs->e2 * rhs->e225 
            + lhs->e225 * rhs->e2 + lhs->e5 * rhs->e222 + lhs->e222 * rhs->e5 
            + lhs->e22 * rhs->e25 + lhs->e25 * rhs->e22;
  res->e1135 = lhs->r * rhs->e1135 + lhs->e1135 * rhs->r + lhs->e1 * rhs->e135 
            + lhs->e135 * rhs->e1 + lhs->e3 * rhs->e115 + lhs->e115 * rhs->e3 
            + lhs->e5 * rhs->e113 + lhs->e113 * rhs->e5 + lhs->e11 * rhs->e35 
            + lhs->e13 * rhs->e15 + lhs->e15 * rhs->e13 + lhs->e35 * rhs->e11;
  res->e1235 = lhs->r * rhs->e1235 + lhs->e1235 * rhs->r + lhs->e1 * rhs->e235 
            + lhs->e235 * rhs->e1 + lhs->e2 * rhs->e135 + lhs->e135 * rhs->e2 
            + lhs->e3 * rhs->e125 + lhs->e125 * rhs->e3 + lhs->e5 * rhs->e123 
            + lhs->e123 * rhs->e5 + lhs->e12 * rhs->e35 + lhs->e13 * rhs->e25 
            + lhs->e23 * rhs->e15 + lhs->e15 * rhs->e23 + lhs->e25 * rhs->e13 
            + lhs->e35 * rhs->e12;
  res->e2235 = lhs->r * rhs->e2235 + lhs->e2235 * rhs->r + lhs->e2 * rhs->e235 
            + lhs->e235 * rhs->e2 + lhs->e3 * rhs->e225 + lhs->e225 * rhs->e3 
            + lhs->e5 * rhs->e223 + lhs->e223 * rhs->e5 + lhs->e22 * rhs->e35 
            + lhs->e23 * rhs->e25 + lhs->e25 * rhs->e23 + lhs->e35 * rhs->e22;
  res->e1335 = lhs->r * rhs->e1335 + lhs->e1335 * rhs->r + lhs->e1 * rhs->e335 
            + lhs->e335 * rhs->e1 + lhs->e3 * rhs->e135 + lhs->e135 * rhs->e3 
            + lhs->e5 * rhs->e133 + lhs->e133 * rhs->e5 + lhs->e13 * rhs->e35 
            + lhs->e33 * rhs->e15 + lhs->e15 * rhs->e33 + lhs->e35 * rhs->e13;
  res->e2335 = lhs->r * rhs->e2335 + lhs->e2335 * rhs->r + lhs->e2 * rhs->e335 
            + lhs->e335 * rhs->e2 + lhs->e3 * rhs->e235 + lhs->e235 * rhs->e3 
            + lhs->e5 * rhs->e233 + lhs->e233 * rhs->e5 + lhs->e23 * rhs->e35 
            + lhs->e33 * rhs->e25 + lhs->e25 * rhs->e33 + lhs->e35 * rhs->e23;
  res->e3335 = lhs->r * rhs->e3335 + lhs->e3335 * rhs->r + lhs->e3 * rhs->e335 
            + lhs->e335 * rhs->e3 + lhs->e5 * rhs->e333 + lhs->e333 * rhs->e5 
            + lhs->e33 * rhs->e35 + lhs->e35 * rhs->e33;
  res->e1145 = lhs->r * rhs->e1145 + lhs->e1145 * rhs->r + lhs->e1 * rhs->e145 
            + lhs->e145 * rhs->e1 + lhs->e4 * rhs->e115 + lhs->e115 * rhs->e4 
            + lhs->e5 * rhs->e114 + lhs->e114 * rhs->e5 + lhs->e11 * rhs->e45 
            + lhs->e14 * rhs->e15 + lhs->e15 * rhs->e14 + lhs->e45 * rhs->e11;
  res->e1245 = lhs->r * rhs->e1245 + lhs->e1245 * rhs->r + lhs->e1 * rhs->e245 
            + lhs->e245 * rhs->e1 + lhs->e2 * rhs->e145 + lhs->e145 * rhs->e2 
            + lhs->e4 * rhs->e125 + lhs->e125 * rhs->e4 + lhs->e5 * rhs->e124 
            + lhs->e124 * rhs->e5 + lhs->e12 * rhs->e45 + lhs->e14 * rhs->e25 
            + lhs->e24 * rhs->e15 + lhs->e15 * rhs->e24 + lhs->e25 * rhs->e14 
            + lhs->e45 * rhs->e12;
  res->e2245 = lhs->r * rhs->e2245 + lhs->e2245 * rhs->r + lhs->e2 * rhs->e245 
            + lhs->e245 * rhs->e2 + lhs->e4 * rhs->e225 + lhs->e225 * rhs->e4 
            + lhs->e5 * rhs->e224 + lhs->e224 * rhs->e5 + lhs->e22 * rhs->e45 
            + lhs->e24 * rhs->e25 + lhs->e25 * rhs->e24 + lhs->e45 * rhs->e22;
  res->e1345 = lhs->r * rhs->e1345 + lhs->e1345 * rhs->r + lhs->e1 * rhs->e345 
            + lhs->e345 * rhs->e1 + lhs->e3 * rhs->e145 + lhs->e145 * rhs->e3 
            + lhs->e4 * rhs->e135 + lhs->e135 * rhs->e4 + lhs->e5 * rhs->e134 
            + lhs->e134 * rhs->e5 + lhs->e13 * rhs->e45 + lhs->e14 * rhs->e35 
            + lhs->e34 * rhs->e15 + lhs->e15 * rhs->e34 + lhs->e35 * rhs->e14 
            + lhs->e45 * rhs->e13;
  res->e2345 = lhs->r * rhs->e2345 + lhs->e2345 * rhs->r + lhs->e2 * rhs->e345 
            + lhs->e345 * rhs->e2 + lhs->e3 * rhs->e245 + lhs->e245 * rhs->e3 
            + lhs->e4 * rhs->e235 + lhs->e235 * rhs->e4 + lhs->e5 * rhs->e234 
            + lhs->e234 * rhs->e5 + lhs->e23 * rhs->e45 + lhs->e24 * rhs->e35 
            + lhs->e34 * rhs->e25 + lhs->e25 * rhs->e34 + lhs->e35 * rhs->e24 
            + lhs->e45 * rhs->e23;
  res->e3345 = lhs->r * rhs->e3345 + lhs->e3345 * rhs->r + lhs->e3 * rhs->e345 
            + lhs->e345 * rhs->e3 + lhs->e4 * rhs->e335 + lhs->e335 * rhs->e4 
            + lhs->e5 * rhs->e334 + lhs->e334 * rhs->e5 + lhs->e33 * rhs->e45 
            + lhs->e34 * rhs->e35 + lhs->e35 * rhs->e34 + lhs->e45 * rhs->e33;
  res->e1445 = lhs->r * rhs->e1445 + lhs->e1445 * rhs->r + lhs->e1 * rhs->e445 
            + lhs->e445 * rhs->e1 + lhs->e4 * rhs->e145 + lhs->e145 * rhs->e4 
            + lhs->e5 * rhs->e144 + lhs->e144 * rhs->e5 + lhs->e14 * rhs->e45 
            + lhs->e44 * rhs->e15 + lhs->e15 * rhs->e44 + lhs->e45 * rhs->e14;
  res->e2445 = lhs->r * rhs->e2445 + lhs->e2445 * rhs->r + lhs->e2 * rhs->e445 
            + lhs->e445 * rhs->e2 + lhs->e4 * rhs->e245 + lhs->e245 * rhs->e4 
            + lhs->e5 * rhs->e244 + lhs->e244 * rhs->e5 + lhs->e24 * rhs->e45 
            + lhs->e44 * rhs->e25 + lhs->e25 * rhs->e44 + lhs->e45 * rhs->e24;
  res->e3445 = lhs->r * rhs->e3445 + lhs->e3445 * rhs->r + lhs->e3 * rhs->e445 
            + lhs->e445 * rhs->e3 + lhs->e4 * rhs->e345 + lhs->e345 * rhs->e4 
            + lhs->e5 * rhs->e344 + lhs->e344 * rhs->e5 + lhs->e34 * rhs->e45 
            + lhs->e44 * rhs->e35 + lhs->e35 * rhs->e44 + lhs->e45 * rhs->e34;
  res->e4445 = lhs->r * rhs->e4445 + lhs->e4445 * rhs->r + lhs->e4 * rhs->e445 
            + lhs->e445 * rhs->e4 + lhs->e5 * rhs->e444 + lhs->e444 * rhs->e5 
            + lhs->e44 * rhs->e45 + lhs->e45 * rhs->e44;
  res->e1155 = lhs->r * rhs->e1155 + lhs->e1155 * rhs->r + lhs->e1 * rhs->e155 
            + lhs->e155 * rhs->e1 + lhs->e5 * rhs->e115 + lhs->e115 * rhs->e5 
            + lhs->e11 * rhs->e55 + lhs->e15 * rhs->e15 + lhs->e55 * rhs->e11;
  res->e1255 = lhs->r * rhs->e1255 + lhs->e1255 * rhs->r + lhs->e1 * rhs->e255 
            + lhs->e255 * rhs->e1 + lhs->e2 * rhs->e155 + lhs->e155 * rhs->e2 
            + lhs->e5 * rhs->e125 + lhs->e125 * rhs->e5 + lhs->e12 * rhs->e55 
            + lhs->e15 * rhs->e25 + lhs->e25 * rhs->e15 + lhs->e55 * rhs->e12;
  res->e2255 = lhs->r * rhs->e2255 + lhs->e2255 * rhs->r + lhs->e2 * rhs->e255 
            + lhs->e255 * rhs->e2 + lhs->e5 * rhs->e225 + lhs->e225 * rhs->e5 
            + lhs->e22 * rhs->e55 + lhs->e25 * rhs->e25 + lhs->e55 * rhs->e22;
  res->e1355 = lhs->r * rhs->e1355 + lhs->e1355 * rhs->r + lhs->e1 * rhs->e355 
            + lhs->e355 * rhs->e1 + lhs->e3 * rhs->e155 + lhs->e155 * rhs->e3 
            + lhs->e5 * rhs->e135 + lhs->e135 * rhs->e5 + lhs->e13 * rhs->e55 
            + lhs->e15 * rhs->e35 + lhs->e35 * rhs->e15 + lhs->e55 * rhs->e13;
  res->e2355 = lhs->r * rhs->e2355 + lhs->e2355 * rhs->r + lhs->e2 * rhs->e355 
            + lhs->e355 * rhs->e2 + lhs->e3 * rhs->e255 + lhs->e255 * rhs->e3 
            + lhs->e5 * rhs->e235 + lhs->e235 * rhs->e5 + lhs->e23 * rhs->e55 
            + lhs->e25 * rhs->e35 + lhs->e35 * rhs->e25 + lhs->e55 * rhs->e23;
  res->e3355 = lhs->r * rhs->e3355 + lhs->e3355 * rhs->r + lhs->e3 * rhs->e355 
            + lhs->e355 * rhs->e3 + lhs->e5 * rhs->e335 + lhs->e335 * rhs->e5 
            + lhs->e33 * rhs->e55 + lhs->e35 * rhs->e35 + lhs->e55 * rhs->e33;
  res->e1455 = lhs->r * rhs->e1455 + lhs->e1455 * rhs->r + lhs->e1 * rhs->e455 
            + lhs->e455 * rhs->e1 + lhs->e4 * rhs->e155 + lhs->e155 * rhs->e4 
            + lhs->e5 * rhs->e145 + lhs->e145 * rhs->e5 + lhs->e14 * rhs->e55 
            + lhs->e15 * rhs->e45 + lhs->e45 * rhs->e15 + lhs->e55 * rhs->e14;
  res->e2455 = lhs->r * rhs->e2455 + lhs->e2455 * rhs->r + lhs->e2 * rhs->e455 
            + lhs->e455 * rhs->e2 + lhs->e4 * rhs->e255 + lhs->e255 * rhs->e4 
            + lhs->e5 * rhs->e245 + lhs->e245 * rhs->e5 + lhs->e24 * rhs->e55 
            + lhs->e25 * rhs->e45 + lhs->e45 * rhs->e25 + lhs->e55 * rhs->e24;
  res->e3455 = lhs->r * rhs->e3455 + lhs->e3455 * rhs->r + lhs->e3 * rhs->e455 
            + lhs->e455 * rhs->e3 + lhs->e4 * rhs->e355 + lhs->e355 * rhs->e4 
            + lhs->e5 * rhs->e345 + lhs->e345 * rhs->e5 + lhs->e34 * rhs->e55 
            + lhs->e35 * rhs->e45 + lhs->e45 * rhs->e35 + lhs->e55 * rhs->e34;
  res->e4455 = lhs->r * rhs->e4455 + lhs->e4455 * rhs->r + lhs->e4 * rhs->e455 
            + lhs->e455 * rhs->e4 + lhs->e5 * rhs->e445 + lhs->e445 * rhs->e5 
            + lhs->e44 * rhs->e55 + lhs->e45 * rhs->e45 + lhs->e55 * rhs->e44;
  res->e1555 = lhs->r * rhs->e1555 + lhs->e1555 * rhs->r + lhs->e1 * rhs->e555 
            + lhs->e555 * rhs->e1 + lhs->e5 * rhs->e155 + lhs->e155 * rhs->e5 
            + lhs->e15 * rhs->e55 + lhs->e55 * rhs->e15;
  res->e2555 = lhs->r * rhs->e2555 + lhs->e2555 * rhs->r + lhs->e2 * rhs->e555 
            + lhs->e555 * rhs->e2 + lhs->e5 * rhs->e255 + lhs->e255 * rhs->e5 
            + lhs->e25 * rhs->e55 + lhs->e55 * rhs->e25;
  res->e3555 = lhs->r * rhs->e3555 + lhs->e3555 * rhs->r + lhs->e3 * rhs->e555 
            + lhs->e555 * rhs->e3 + lhs->e5 * rhs->e355 + lhs->e355 * rhs->e5 
            + lhs->e35 * rhs->e55 + lhs->e55 * rhs->e35;
  res->e4555 = lhs->r * rhs->e4555 + lhs->e4555 * rhs->r + lhs->e4 * rhs->e555 
            + lhs->e555 * rhs->e4 + lhs->e5 * rhs->e455 + lhs->e455 * rhs->e5 
            + lhs->e45 * rhs->e55 + lhs->e55 * rhs->e45;
  res->e5555 = lhs->r * rhs->e5555 + lhs->e5555 * rhs->r + lhs->e5 * rhs->e555 
            + lhs->e555 * rhs->e5 + lhs->e55 * rhs->e55;
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
  res->e11115 = lhs->r * rhs->e11115 + lhs->e11115 * rhs->r + lhs->e1 * rhs->e1115 
             + lhs->e1115 * rhs->e1 + lhs->e5 * rhs->e1111 + lhs->e1111 * rhs->e5 
             + lhs->e11 * rhs->e115 + lhs->e115 * rhs->e11 + lhs->e15 * rhs->e111 
             + lhs->e111 * rhs->e15;
  res->e11125 = lhs->r * rhs->e11125 + lhs->e11125 * rhs->r + lhs->e1 * rhs->e1125 
             + lhs->e1125 * rhs->e1 + lhs->e2 * rhs->e1115 + lhs->e1115 * rhs->e2 
             + lhs->e5 * rhs->e1112 + lhs->e1112 * rhs->e5 + lhs->e11 * rhs->e125 
             + lhs->e125 * rhs->e11 + lhs->e12 * rhs->e115 + lhs->e115 * rhs->e12 
             + lhs->e15 * rhs->e112 + lhs->e112 * rhs->e15 + lhs->e25 * rhs->e111 
             + lhs->e111 * rhs->e25;
  res->e11225 = lhs->r * rhs->e11225 + lhs->e11225 * rhs->r + lhs->e1 * rhs->e1225 
             + lhs->e1225 * rhs->e1 + lhs->e2 * rhs->e1125 + lhs->e1125 * rhs->e2 
             + lhs->e5 * rhs->e1122 + lhs->e1122 * rhs->e5 + lhs->e11 * rhs->e225 
             + lhs->e225 * rhs->e11 + lhs->e12 * rhs->e125 + lhs->e125 * rhs->e12 
             + lhs->e22 * rhs->e115 + lhs->e115 * rhs->e22 + lhs->e15 * rhs->e122 
             + lhs->e122 * rhs->e15 + lhs->e25 * rhs->e112 + lhs->e112 * rhs->e25;
  res->e12225 = lhs->r * rhs->e12225 + lhs->e12225 * rhs->r + lhs->e1 * rhs->e2225 
             + lhs->e2225 * rhs->e1 + lhs->e2 * rhs->e1225 + lhs->e1225 * rhs->e2 
             + lhs->e5 * rhs->e1222 + lhs->e1222 * rhs->e5 + lhs->e12 * rhs->e225 
             + lhs->e225 * rhs->e12 + lhs->e22 * rhs->e125 + lhs->e125 * rhs->e22 
             + lhs->e15 * rhs->e222 + lhs->e222 * rhs->e15 + lhs->e25 * rhs->e122 
             + lhs->e122 * rhs->e25;
  res->e22225 = lhs->r * rhs->e22225 + lhs->e22225 * rhs->r + lhs->e2 * rhs->e2225 
             + lhs->e2225 * rhs->e2 + lhs->e5 * rhs->e2222 + lhs->e2222 * rhs->e5 
             + lhs->e22 * rhs->e225 + lhs->e225 * rhs->e22 + lhs->e25 * rhs->e222 
             + lhs->e222 * rhs->e25;
  res->e11135 = lhs->r * rhs->e11135 + lhs->e11135 * rhs->r + lhs->e1 * rhs->e1135 
             + lhs->e1135 * rhs->e1 + lhs->e3 * rhs->e1115 + lhs->e1115 * rhs->e3 
             + lhs->e5 * rhs->e1113 + lhs->e1113 * rhs->e5 + lhs->e11 * rhs->e135 
             + lhs->e135 * rhs->e11 + lhs->e13 * rhs->e115 + lhs->e115 * rhs->e13 
             + lhs->e15 * rhs->e113 + lhs->e113 * rhs->e15 + lhs->e35 * rhs->e111 
             + lhs->e111 * rhs->e35;
  res->e11235 = lhs->r * rhs->e11235 + lhs->e11235 * rhs->r + lhs->e1 * rhs->e1235 
             + lhs->e1235 * rhs->e1 + lhs->e2 * rhs->e1135 + lhs->e1135 * rhs->e2 
             + lhs->e3 * rhs->e1125 + lhs->e1125 * rhs->e3 + lhs->e5 * rhs->e1123 
             + lhs->e1123 * rhs->e5 + lhs->e11 * rhs->e235 + lhs->e235 * rhs->e11 
             + lhs->e12 * rhs->e135 + lhs->e135 * rhs->e12 + lhs->e13 * rhs->e125 
             + lhs->e125 * rhs->e13 + lhs->e23 * rhs->e115 + lhs->e115 * rhs->e23 
             + lhs->e15 * rhs->e123 + lhs->e123 * rhs->e15 + lhs->e25 * rhs->e113 
             + lhs->e113 * rhs->e25 + lhs->e35 * rhs->e112 + lhs->e112 * rhs->e35;
  res->e12235 = lhs->r * rhs->e12235 + lhs->e12235 * rhs->r + lhs->e1 * rhs->e2235 
             + lhs->e2235 * rhs->e1 + lhs->e2 * rhs->e1235 + lhs->e1235 * rhs->e2 
             + lhs->e3 * rhs->e1225 + lhs->e1225 * rhs->e3 + lhs->e5 * rhs->e1223 
             + lhs->e1223 * rhs->e5 + lhs->e12 * rhs->e235 + lhs->e235 * rhs->e12 
             + lhs->e22 * rhs->e135 + lhs->e135 * rhs->e22 + lhs->e13 * rhs->e225 
             + lhs->e225 * rhs->e13 + lhs->e23 * rhs->e125 + lhs->e125 * rhs->e23 
             + lhs->e15 * rhs->e223 + lhs->e223 * rhs->e15 + lhs->e25 * rhs->e123 
             + lhs->e123 * rhs->e25 + lhs->e35 * rhs->e122 + lhs->e122 * rhs->e35;
  res->e22235 = lhs->r * rhs->e22235 + lhs->e22235 * rhs->r + lhs->e2 * rhs->e2235 
             + lhs->e2235 * rhs->e2 + lhs->e3 * rhs->e2225 + lhs->e2225 * rhs->e3 
             + lhs->e5 * rhs->e2223 + lhs->e2223 * rhs->e5 + lhs->e22 * rhs->e235 
             + lhs->e235 * rhs->e22 + lhs->e23 * rhs->e225 + lhs->e225 * rhs->e23 
             + lhs->e25 * rhs->e223 + lhs->e223 * rhs->e25 + lhs->e35 * rhs->e222 
             + lhs->e222 * rhs->e35;
  res->e11335 = lhs->r * rhs->e11335 + lhs->e11335 * rhs->r + lhs->e1 * rhs->e1335 
             + lhs->e1335 * rhs->e1 + lhs->e3 * rhs->e1135 + lhs->e1135 * rhs->e3 
             + lhs->e5 * rhs->e1133 + lhs->e1133 * rhs->e5 + lhs->e11 * rhs->e335 
             + lhs->e335 * rhs->e11 + lhs->e13 * rhs->e135 + lhs->e135 * rhs->e13 
             + lhs->e33 * rhs->e115 + lhs->e115 * rhs->e33 + lhs->e15 * rhs->e133 
             + lhs->e133 * rhs->e15 + lhs->e35 * rhs->e113 + lhs->e113 * rhs->e35;
  res->e12335 = lhs->r * rhs->e12335 + lhs->e12335 * rhs->r + lhs->e1 * rhs->e2335 
             + lhs->e2335 * rhs->e1 + lhs->e2 * rhs->e1335 + lhs->e1335 * rhs->e2 
             + lhs->e3 * rhs->e1235 + lhs->e1235 * rhs->e3 + lhs->e5 * rhs->e1233 
             + lhs->e1233 * rhs->e5 + lhs->e12 * rhs->e335 + lhs->e335 * rhs->e12 
             + lhs->e13 * rhs->e235 + lhs->e235 * rhs->e13 + lhs->e23 * rhs->e135 
             + lhs->e135 * rhs->e23 + lhs->e33 * rhs->e125 + lhs->e125 * rhs->e33 
             + lhs->e15 * rhs->e233 + lhs->e233 * rhs->e15 + lhs->e25 * rhs->e133 
             + lhs->e133 * rhs->e25 + lhs->e35 * rhs->e123 + lhs->e123 * rhs->e35;
  res->e22335 = lhs->r * rhs->e22335 + lhs->e22335 * rhs->r + lhs->e2 * rhs->e2335 
             + lhs->e2335 * rhs->e2 + lhs->e3 * rhs->e2235 + lhs->e2235 * rhs->e3 
             + lhs->e5 * rhs->e2233 + lhs->e2233 * rhs->e5 + lhs->e22 * rhs->e335 
             + lhs->e335 * rhs->e22 + lhs->e23 * rhs->e235 + lhs->e235 * rhs->e23 
             + lhs->e33 * rhs->e225 + lhs->e225 * rhs->e33 + lhs->e25 * rhs->e233 
             + lhs->e233 * rhs->e25 + lhs->e35 * rhs->e223 + lhs->e223 * rhs->e35;
  res->e13335 = lhs->r * rhs->e13335 + lhs->e13335 * rhs->r + lhs->e1 * rhs->e3335 
             + lhs->e3335 * rhs->e1 + lhs->e3 * rhs->e1335 + lhs->e1335 * rhs->e3 
             + lhs->e5 * rhs->e1333 + lhs->e1333 * rhs->e5 + lhs->e13 * rhs->e335 
             + lhs->e335 * rhs->e13 + lhs->e33 * rhs->e135 + lhs->e135 * rhs->e33 
             + lhs->e15 * rhs->e333 + lhs->e333 * rhs->e15 + lhs->e35 * rhs->e133 
             + lhs->e133 * rhs->e35;
  res->e23335 = lhs->r * rhs->e23335 + lhs->e23335 * rhs->r + lhs->e2 * rhs->e3335 
             + lhs->e3335 * rhs->e2 + lhs->e3 * rhs->e2335 + lhs->e2335 * rhs->e3 
             + lhs->e5 * rhs->e2333 + lhs->e2333 * rhs->e5 + lhs->e23 * rhs->e335 
             + lhs->e335 * rhs->e23 + lhs->e33 * rhs->e235 + lhs->e235 * rhs->e33 
             + lhs->e25 * rhs->e333 + lhs->e333 * rhs->e25 + lhs->e35 * rhs->e233 
             + lhs->e233 * rhs->e35;
  res->e33335 = lhs->r * rhs->e33335 + lhs->e33335 * rhs->r + lhs->e3 * rhs->e3335 
             + lhs->e3335 * rhs->e3 + lhs->e5 * rhs->e3333 + lhs->e3333 * rhs->e5 
             + lhs->e33 * rhs->e335 + lhs->e335 * rhs->e33 + lhs->e35 * rhs->e333 
             + lhs->e333 * rhs->e35;
  res->e11145 = lhs->r * rhs->e11145 + lhs->e11145 * rhs->r + lhs->e1 * rhs->e1145 
             + lhs->e1145 * rhs->e1 + lhs->e4 * rhs->e1115 + lhs->e1115 * rhs->e4 
             + lhs->e5 * rhs->e1114 + lhs->e1114 * rhs->e5 + lhs->e11 * rhs->e145 
             + lhs->e145 * rhs->e11 + lhs->e14 * rhs->e115 + lhs->e115 * rhs->e14 
             + lhs->e15 * rhs->e114 + lhs->e114 * rhs->e15 + lhs->e45 * rhs->e111 
             + lhs->e111 * rhs->e45;
  res->e11245 = lhs->r * rhs->e11245 + lhs->e11245 * rhs->r + lhs->e1 * rhs->e1245 
             + lhs->e1245 * rhs->e1 + lhs->e2 * rhs->e1145 + lhs->e1145 * rhs->e2 
             + lhs->e4 * rhs->e1125 + lhs->e1125 * rhs->e4 + lhs->e5 * rhs->e1124 
             + lhs->e1124 * rhs->e5 + lhs->e11 * rhs->e245 + lhs->e245 * rhs->e11 
             + lhs->e12 * rhs->e145 + lhs->e145 * rhs->e12 + lhs->e14 * rhs->e125 
             + lhs->e125 * rhs->e14 + lhs->e24 * rhs->e115 + lhs->e115 * rhs->e24 
             + lhs->e15 * rhs->e124 + lhs->e124 * rhs->e15 + lhs->e25 * rhs->e114 
             + lhs->e114 * rhs->e25 + lhs->e45 * rhs->e112 + lhs->e112 * rhs->e45;
  res->e12245 = lhs->r * rhs->e12245 + lhs->e12245 * rhs->r + lhs->e1 * rhs->e2245 
             + lhs->e2245 * rhs->e1 + lhs->e2 * rhs->e1245 + lhs->e1245 * rhs->e2 
             + lhs->e4 * rhs->e1225 + lhs->e1225 * rhs->e4 + lhs->e5 * rhs->e1224 
             + lhs->e1224 * rhs->e5 + lhs->e12 * rhs->e245 + lhs->e245 * rhs->e12 
             + lhs->e22 * rhs->e145 + lhs->e145 * rhs->e22 + lhs->e14 * rhs->e225 
             + lhs->e225 * rhs->e14 + lhs->e24 * rhs->e125 + lhs->e125 * rhs->e24 
             + lhs->e15 * rhs->e224 + lhs->e224 * rhs->e15 + lhs->e25 * rhs->e124 
             + lhs->e124 * rhs->e25 + lhs->e45 * rhs->e122 + lhs->e122 * rhs->e45;
  res->e22245 = lhs->r * rhs->e22245 + lhs->e22245 * rhs->r + lhs->e2 * rhs->e2245 
             + lhs->e2245 * rhs->e2 + lhs->e4 * rhs->e2225 + lhs->e2225 * rhs->e4 
             + lhs->e5 * rhs->e2224 + lhs->e2224 * rhs->e5 + lhs->e22 * rhs->e245 
             + lhs->e245 * rhs->e22 + lhs->e24 * rhs->e225 + lhs->e225 * rhs->e24 
             + lhs->e25 * rhs->e224 + lhs->e224 * rhs->e25 + lhs->e45 * rhs->e222 
             + lhs->e222 * rhs->e45;
  res->e11345 = lhs->r * rhs->e11345 + lhs->e11345 * rhs->r + lhs->e1 * rhs->e1345 
             + lhs->e1345 * rhs->e1 + lhs->e3 * rhs->e1145 + lhs->e1145 * rhs->e3 
             + lhs->e4 * rhs->e1135 + lhs->e1135 * rhs->e4 + lhs->e5 * rhs->e1134 
             + lhs->e1134 * rhs->e5 + lhs->e11 * rhs->e345 + lhs->e345 * rhs->e11 
             + lhs->e13 * rhs->e145 + lhs->e145 * rhs->e13 + lhs->e14 * rhs->e135 
             + lhs->e135 * rhs->e14 + lhs->e34 * rhs->e115 + lhs->e115 * rhs->e34 
             + lhs->e15 * rhs->e134 + lhs->e134 * rhs->e15 + lhs->e35 * rhs->e114 
             + lhs->e114 * rhs->e35 + lhs->e45 * rhs->e113 + lhs->e113 * rhs->e45;
  res->e12345 = lhs->r * rhs->e12345 + lhs->e12345 * rhs->r + lhs->e1 * rhs->e2345 
             + lhs->e2345 * rhs->e1 + lhs->e2 * rhs->e1345 + lhs->e1345 * rhs->e2 
             + lhs->e3 * rhs->e1245 + lhs->e1245 * rhs->e3 + lhs->e4 * rhs->e1235 
             + lhs->e1235 * rhs->e4 + lhs->e5 * rhs->e1234 + lhs->e1234 * rhs->e5 
             + lhs->e12 * rhs->e345 + lhs->e345 * rhs->e12 + lhs->e13 * rhs->e245 
             + lhs->e245 * rhs->e13 + lhs->e23 * rhs->e145 + lhs->e145 * rhs->e23 
             + lhs->e14 * rhs->e235 + lhs->e235 * rhs->e14 + lhs->e24 * rhs->e135 
             + lhs->e135 * rhs->e24 + lhs->e34 * rhs->e125 + lhs->e125 * rhs->e34 
             + lhs->e15 * rhs->e234 + lhs->e234 * rhs->e15 + lhs->e25 * rhs->e134 
             + lhs->e134 * rhs->e25 + lhs->e35 * rhs->e124 + lhs->e124 * rhs->e35 
             + lhs->e45 * rhs->e123 + lhs->e123 * rhs->e45;
  res->e22345 = lhs->r * rhs->e22345 + lhs->e22345 * rhs->r + lhs->e2 * rhs->e2345 
             + lhs->e2345 * rhs->e2 + lhs->e3 * rhs->e2245 + lhs->e2245 * rhs->e3 
             + lhs->e4 * rhs->e2235 + lhs->e2235 * rhs->e4 + lhs->e5 * rhs->e2234 
             + lhs->e2234 * rhs->e5 + lhs->e22 * rhs->e345 + lhs->e345 * rhs->e22 
             + lhs->e23 * rhs->e245 + lhs->e245 * rhs->e23 + lhs->e24 * rhs->e235 
             + lhs->e235 * rhs->e24 + lhs->e34 * rhs->e225 + lhs->e225 * rhs->e34 
             + lhs->e25 * rhs->e234 + lhs->e234 * rhs->e25 + lhs->e35 * rhs->e224 
             + lhs->e224 * rhs->e35 + lhs->e45 * rhs->e223 + lhs->e223 * rhs->e45;
  res->e13345 = lhs->r * rhs->e13345 + lhs->e13345 * rhs->r + lhs->e1 * rhs->e3345 
             + lhs->e3345 * rhs->e1 + lhs->e3 * rhs->e1345 + lhs->e1345 * rhs->e3 
             + lhs->e4 * rhs->e1335 + lhs->e1335 * rhs->e4 + lhs->e5 * rhs->e1334 
             + lhs->e1334 * rhs->e5 + lhs->e13 * rhs->e345 + lhs->e345 * rhs->e13 
             + lhs->e33 * rhs->e145 + lhs->e145 * rhs->e33 + lhs->e14 * rhs->e335 
             + lhs->e335 * rhs->e14 + lhs->e34 * rhs->e135 + lhs->e135 * rhs->e34 
             + lhs->e15 * rhs->e334 + lhs->e334 * rhs->e15 + lhs->e35 * rhs->e134 
             + lhs->e134 * rhs->e35 + lhs->e45 * rhs->e133 + lhs->e133 * rhs->e45;
  res->e23345 = lhs->r * rhs->e23345 + lhs->e23345 * rhs->r + lhs->e2 * rhs->e3345 
             + lhs->e3345 * rhs->e2 + lhs->e3 * rhs->e2345 + lhs->e2345 * rhs->e3 
             + lhs->e4 * rhs->e2335 + lhs->e2335 * rhs->e4 + lhs->e5 * rhs->e2334 
             + lhs->e2334 * rhs->e5 + lhs->e23 * rhs->e345 + lhs->e345 * rhs->e23 
             + lhs->e33 * rhs->e245 + lhs->e245 * rhs->e33 + lhs->e24 * rhs->e335 
             + lhs->e335 * rhs->e24 + lhs->e34 * rhs->e235 + lhs->e235 * rhs->e34 
             + lhs->e25 * rhs->e334 + lhs->e334 * rhs->e25 + lhs->e35 * rhs->e234 
             + lhs->e234 * rhs->e35 + lhs->e45 * rhs->e233 + lhs->e233 * rhs->e45;
  res->e33345 = lhs->r * rhs->e33345 + lhs->e33345 * rhs->r + lhs->e3 * rhs->e3345 
             + lhs->e3345 * rhs->e3 + lhs->e4 * rhs->e3335 + lhs->e3335 * rhs->e4 
             + lhs->e5 * rhs->e3334 + lhs->e3334 * rhs->e5 + lhs->e33 * rhs->e345 
             + lhs->e345 * rhs->e33 + lhs->e34 * rhs->e335 + lhs->e335 * rhs->e34 
             + lhs->e35 * rhs->e334 + lhs->e334 * rhs->e35 + lhs->e45 * rhs->e333 
             + lhs->e333 * rhs->e45;
  res->e11445 = lhs->r * rhs->e11445 + lhs->e11445 * rhs->r + lhs->e1 * rhs->e1445 
             + lhs->e1445 * rhs->e1 + lhs->e4 * rhs->e1145 + lhs->e1145 * rhs->e4 
             + lhs->e5 * rhs->e1144 + lhs->e1144 * rhs->e5 + lhs->e11 * rhs->e445 
             + lhs->e445 * rhs->e11 + lhs->e14 * rhs->e145 + lhs->e145 * rhs->e14 
             + lhs->e44 * rhs->e115 + lhs->e115 * rhs->e44 + lhs->e15 * rhs->e144 
             + lhs->e144 * rhs->e15 + lhs->e45 * rhs->e114 + lhs->e114 * rhs->e45;
  res->e12445 = lhs->r * rhs->e12445 + lhs->e12445 * rhs->r + lhs->e1 * rhs->e2445 
             + lhs->e2445 * rhs->e1 + lhs->e2 * rhs->e1445 + lhs->e1445 * rhs->e2 
             + lhs->e4 * rhs->e1245 + lhs->e1245 * rhs->e4 + lhs->e5 * rhs->e1244 
             + lhs->e1244 * rhs->e5 + lhs->e12 * rhs->e445 + lhs->e445 * rhs->e12 
             + lhs->e14 * rhs->e245 + lhs->e245 * rhs->e14 + lhs->e24 * rhs->e145 
             + lhs->e145 * rhs->e24 + lhs->e44 * rhs->e125 + lhs->e125 * rhs->e44 
             + lhs->e15 * rhs->e244 + lhs->e244 * rhs->e15 + lhs->e25 * rhs->e144 
             + lhs->e144 * rhs->e25 + lhs->e45 * rhs->e124 + lhs->e124 * rhs->e45;
  res->e22445 = lhs->r * rhs->e22445 + lhs->e22445 * rhs->r + lhs->e2 * rhs->e2445 
             + lhs->e2445 * rhs->e2 + lhs->e4 * rhs->e2245 + lhs->e2245 * rhs->e4 
             + lhs->e5 * rhs->e2244 + lhs->e2244 * rhs->e5 + lhs->e22 * rhs->e445 
             + lhs->e445 * rhs->e22 + lhs->e24 * rhs->e245 + lhs->e245 * rhs->e24 
             + lhs->e44 * rhs->e225 + lhs->e225 * rhs->e44 + lhs->e25 * rhs->e244 
             + lhs->e244 * rhs->e25 + lhs->e45 * rhs->e224 + lhs->e224 * rhs->e45;
  res->e13445 = lhs->r * rhs->e13445 + lhs->e13445 * rhs->r + lhs->e1 * rhs->e3445 
             + lhs->e3445 * rhs->e1 + lhs->e3 * rhs->e1445 + lhs->e1445 * rhs->e3 
             + lhs->e4 * rhs->e1345 + lhs->e1345 * rhs->e4 + lhs->e5 * rhs->e1344 
             + lhs->e1344 * rhs->e5 + lhs->e13 * rhs->e445 + lhs->e445 * rhs->e13 
             + lhs->e14 * rhs->e345 + lhs->e345 * rhs->e14 + lhs->e34 * rhs->e145 
             + lhs->e145 * rhs->e34 + lhs->e44 * rhs->e135 + lhs->e135 * rhs->e44 
             + lhs->e15 * rhs->e344 + lhs->e344 * rhs->e15 + lhs->e35 * rhs->e144 
             + lhs->e144 * rhs->e35 + lhs->e45 * rhs->e134 + lhs->e134 * rhs->e45;
  res->e23445 = lhs->r * rhs->e23445 + lhs->e23445 * rhs->r + lhs->e2 * rhs->e3445 
             + lhs->e3445 * rhs->e2 + lhs->e3 * rhs->e2445 + lhs->e2445 * rhs->e3 
             + lhs->e4 * rhs->e2345 + lhs->e2345 * rhs->e4 + lhs->e5 * rhs->e2344 
             + lhs->e2344 * rhs->e5 + lhs->e23 * rhs->e445 + lhs->e445 * rhs->e23 
             + lhs->e24 * rhs->e345 + lhs->e345 * rhs->e24 + lhs->e34 * rhs->e245 
             + lhs->e245 * rhs->e34 + lhs->e44 * rhs->e235 + lhs->e235 * rhs->e44 
             + lhs->e25 * rhs->e344 + lhs->e344 * rhs->e25 + lhs->e35 * rhs->e244 
             + lhs->e244 * rhs->e35 + lhs->e45 * rhs->e234 + lhs->e234 * rhs->e45;
  res->e33445 = lhs->r * rhs->e33445 + lhs->e33445 * rhs->r + lhs->e3 * rhs->e3445 
             + lhs->e3445 * rhs->e3 + lhs->e4 * rhs->e3345 + lhs->e3345 * rhs->e4 
             + lhs->e5 * rhs->e3344 + lhs->e3344 * rhs->e5 + lhs->e33 * rhs->e445 
             + lhs->e445 * rhs->e33 + lhs->e34 * rhs->e345 + lhs->e345 * rhs->e34 
             + lhs->e44 * rhs->e335 + lhs->e335 * rhs->e44 + lhs->e35 * rhs->e344 
             + lhs->e344 * rhs->e35 + lhs->e45 * rhs->e334 + lhs->e334 * rhs->e45;
  res->e14445 = lhs->r * rhs->e14445 + lhs->e14445 * rhs->r + lhs->e1 * rhs->e4445 
             + lhs->e4445 * rhs->e1 + lhs->e4 * rhs->e1445 + lhs->e1445 * rhs->e4 
             + lhs->e5 * rhs->e1444 + lhs->e1444 * rhs->e5 + lhs->e14 * rhs->e445 
             + lhs->e445 * rhs->e14 + lhs->e44 * rhs->e145 + lhs->e145 * rhs->e44 
             + lhs->e15 * rhs->e444 + lhs->e444 * rhs->e15 + lhs->e45 * rhs->e144 
             + lhs->e144 * rhs->e45;
  res->e24445 = lhs->r * rhs->e24445 + lhs->e24445 * rhs->r + lhs->e2 * rhs->e4445 
             + lhs->e4445 * rhs->e2 + lhs->e4 * rhs->e2445 + lhs->e2445 * rhs->e4 
             + lhs->e5 * rhs->e2444 + lhs->e2444 * rhs->e5 + lhs->e24 * rhs->e445 
             + lhs->e445 * rhs->e24 + lhs->e44 * rhs->e245 + lhs->e245 * rhs->e44 
             + lhs->e25 * rhs->e444 + lhs->e444 * rhs->e25 + lhs->e45 * rhs->e244 
             + lhs->e244 * rhs->e45;
  res->e34445 = lhs->r * rhs->e34445 + lhs->e34445 * rhs->r + lhs->e3 * rhs->e4445 
             + lhs->e4445 * rhs->e3 + lhs->e4 * rhs->e3445 + lhs->e3445 * rhs->e4 
             + lhs->e5 * rhs->e3444 + lhs->e3444 * rhs->e5 + lhs->e34 * rhs->e445 
             + lhs->e445 * rhs->e34 + lhs->e44 * rhs->e345 + lhs->e345 * rhs->e44 
             + lhs->e35 * rhs->e444 + lhs->e444 * rhs->e35 + lhs->e45 * rhs->e344 
             + lhs->e344 * rhs->e45;
  res->e44445 = lhs->r * rhs->e44445 + lhs->e44445 * rhs->r + lhs->e4 * rhs->e4445 
             + lhs->e4445 * rhs->e4 + lhs->e5 * rhs->e4444 + lhs->e4444 * rhs->e5 
             + lhs->e44 * rhs->e445 + lhs->e445 * rhs->e44 + lhs->e45 * rhs->e444 
             + lhs->e444 * rhs->e45;
  res->e11155 = lhs->r * rhs->e11155 + lhs->e11155 * rhs->r + lhs->e1 * rhs->e1155 
             + lhs->e1155 * rhs->e1 + lhs->e5 * rhs->e1115 + lhs->e1115 * rhs->e5 
             + lhs->e11 * rhs->e155 + lhs->e155 * rhs->e11 + lhs->e15 * rhs->e115 
             + lhs->e115 * rhs->e15 + lhs->e55 * rhs->e111 + lhs->e111 * rhs->e55;
  res->e11255 = lhs->r * rhs->e11255 + lhs->e11255 * rhs->r + lhs->e1 * rhs->e1255 
             + lhs->e1255 * rhs->e1 + lhs->e2 * rhs->e1155 + lhs->e1155 * rhs->e2 
             + lhs->e5 * rhs->e1125 + lhs->e1125 * rhs->e5 + lhs->e11 * rhs->e255 
             + lhs->e255 * rhs->e11 + lhs->e12 * rhs->e155 + lhs->e155 * rhs->e12 
             + lhs->e15 * rhs->e125 + lhs->e125 * rhs->e15 + lhs->e25 * rhs->e115 
             + lhs->e115 * rhs->e25 + lhs->e55 * rhs->e112 + lhs->e112 * rhs->e55;
  res->e12255 = lhs->r * rhs->e12255 + lhs->e12255 * rhs->r + lhs->e1 * rhs->e2255 
             + lhs->e2255 * rhs->e1 + lhs->e2 * rhs->e1255 + lhs->e1255 * rhs->e2 
             + lhs->e5 * rhs->e1225 + lhs->e1225 * rhs->e5 + lhs->e12 * rhs->e255 
             + lhs->e255 * rhs->e12 + lhs->e22 * rhs->e155 + lhs->e155 * rhs->e22 
             + lhs->e15 * rhs->e225 + lhs->e225 * rhs->e15 + lhs->e25 * rhs->e125 
             + lhs->e125 * rhs->e25 + lhs->e55 * rhs->e122 + lhs->e122 * rhs->e55;
  res->e22255 = lhs->r * rhs->e22255 + lhs->e22255 * rhs->r + lhs->e2 * rhs->e2255 
             + lhs->e2255 * rhs->e2 + lhs->e5 * rhs->e2225 + lhs->e2225 * rhs->e5 
             + lhs->e22 * rhs->e255 + lhs->e255 * rhs->e22 + lhs->e25 * rhs->e225 
             + lhs->e225 * rhs->e25 + lhs->e55 * rhs->e222 + lhs->e222 * rhs->e55;
  res->e11355 = lhs->r * rhs->e11355 + lhs->e11355 * rhs->r + lhs->e1 * rhs->e1355 
             + lhs->e1355 * rhs->e1 + lhs->e3 * rhs->e1155 + lhs->e1155 * rhs->e3 
             + lhs->e5 * rhs->e1135 + lhs->e1135 * rhs->e5 + lhs->e11 * rhs->e355 
             + lhs->e355 * rhs->e11 + lhs->e13 * rhs->e155 + lhs->e155 * rhs->e13 
             + lhs->e15 * rhs->e135 + lhs->e135 * rhs->e15 + lhs->e35 * rhs->e115 
             + lhs->e115 * rhs->e35 + lhs->e55 * rhs->e113 + lhs->e113 * rhs->e55;
  res->e12355 = lhs->r * rhs->e12355 + lhs->e12355 * rhs->r + lhs->e1 * rhs->e2355 
             + lhs->e2355 * rhs->e1 + lhs->e2 * rhs->e1355 + lhs->e1355 * rhs->e2 
             + lhs->e3 * rhs->e1255 + lhs->e1255 * rhs->e3 + lhs->e5 * rhs->e1235 
             + lhs->e1235 * rhs->e5 + lhs->e12 * rhs->e355 + lhs->e355 * rhs->e12 
             + lhs->e13 * rhs->e255 + lhs->e255 * rhs->e13 + lhs->e23 * rhs->e155 
             + lhs->e155 * rhs->e23 + lhs->e15 * rhs->e235 + lhs->e235 * rhs->e15 
             + lhs->e25 * rhs->e135 + lhs->e135 * rhs->e25 + lhs->e35 * rhs->e125 
             + lhs->e125 * rhs->e35 + lhs->e55 * rhs->e123 + lhs->e123 * rhs->e55;
  res->e22355 = lhs->r * rhs->e22355 + lhs->e22355 * rhs->r + lhs->e2 * rhs->e2355 
             + lhs->e2355 * rhs->e2 + lhs->e3 * rhs->e2255 + lhs->e2255 * rhs->e3 
             + lhs->e5 * rhs->e2235 + lhs->e2235 * rhs->e5 + lhs->e22 * rhs->e355 
             + lhs->e355 * rhs->e22 + lhs->e23 * rhs->e255 + lhs->e255 * rhs->e23 
             + lhs->e25 * rhs->e235 + lhs->e235 * rhs->e25 + lhs->e35 * rhs->e225 
             + lhs->e225 * rhs->e35 + lhs->e55 * rhs->e223 + lhs->e223 * rhs->e55;
  res->e13355 = lhs->r * rhs->e13355 + lhs->e13355 * rhs->r + lhs->e1 * rhs->e3355 
             + lhs->e3355 * rhs->e1 + lhs->e3 * rhs->e1355 + lhs->e1355 * rhs->e3 
             + lhs->e5 * rhs->e1335 + lhs->e1335 * rhs->e5 + lhs->e13 * rhs->e355 
             + lhs->e355 * rhs->e13 + lhs->e33 * rhs->e155 + lhs->e155 * rhs->e33 
             + lhs->e15 * rhs->e335 + lhs->e335 * rhs->e15 + lhs->e35 * rhs->e135 
             + lhs->e135 * rhs->e35 + lhs->e55 * rhs->e133 + lhs->e133 * rhs->e55;
  res->e23355 = lhs->r * rhs->e23355 + lhs->e23355 * rhs->r + lhs->e2 * rhs->e3355 
             + lhs->e3355 * rhs->e2 + lhs->e3 * rhs->e2355 + lhs->e2355 * rhs->e3 
             + lhs->e5 * rhs->e2335 + lhs->e2335 * rhs->e5 + lhs->e23 * rhs->e355 
             + lhs->e355 * rhs->e23 + lhs->e33 * rhs->e255 + lhs->e255 * rhs->e33 
             + lhs->e25 * rhs->e335 + lhs->e335 * rhs->e25 + lhs->e35 * rhs->e235 
             + lhs->e235 * rhs->e35 + lhs->e55 * rhs->e233 + lhs->e233 * rhs->e55;
  res->e33355 = lhs->r * rhs->e33355 + lhs->e33355 * rhs->r + lhs->e3 * rhs->e3355 
             + lhs->e3355 * rhs->e3 + lhs->e5 * rhs->e3335 + lhs->e3335 * rhs->e5 
             + lhs->e33 * rhs->e355 + lhs->e355 * rhs->e33 + lhs->e35 * rhs->e335 
             + lhs->e335 * rhs->e35 + lhs->e55 * rhs->e333 + lhs->e333 * rhs->e55;
  res->e11455 = lhs->r * rhs->e11455 + lhs->e11455 * rhs->r + lhs->e1 * rhs->e1455 
             + lhs->e1455 * rhs->e1 + lhs->e4 * rhs->e1155 + lhs->e1155 * rhs->e4 
             + lhs->e5 * rhs->e1145 + lhs->e1145 * rhs->e5 + lhs->e11 * rhs->e455 
             + lhs->e455 * rhs->e11 + lhs->e14 * rhs->e155 + lhs->e155 * rhs->e14 
             + lhs->e15 * rhs->e145 + lhs->e145 * rhs->e15 + lhs->e45 * rhs->e115 
             + lhs->e115 * rhs->e45 + lhs->e55 * rhs->e114 + lhs->e114 * rhs->e55;
  res->e12455 = lhs->r * rhs->e12455 + lhs->e12455 * rhs->r + lhs->e1 * rhs->e2455 
             + lhs->e2455 * rhs->e1 + lhs->e2 * rhs->e1455 + lhs->e1455 * rhs->e2 
             + lhs->e4 * rhs->e1255 + lhs->e1255 * rhs->e4 + lhs->e5 * rhs->e1245 
             + lhs->e1245 * rhs->e5 + lhs->e12 * rhs->e455 + lhs->e455 * rhs->e12 
             + lhs->e14 * rhs->e255 + lhs->e255 * rhs->e14 + lhs->e24 * rhs->e155 
             + lhs->e155 * rhs->e24 + lhs->e15 * rhs->e245 + lhs->e245 * rhs->e15 
             + lhs->e25 * rhs->e145 + lhs->e145 * rhs->e25 + lhs->e45 * rhs->e125 
             + lhs->e125 * rhs->e45 + lhs->e55 * rhs->e124 + lhs->e124 * rhs->e55;
  res->e22455 = lhs->r * rhs->e22455 + lhs->e22455 * rhs->r + lhs->e2 * rhs->e2455 
             + lhs->e2455 * rhs->e2 + lhs->e4 * rhs->e2255 + lhs->e2255 * rhs->e4 
             + lhs->e5 * rhs->e2245 + lhs->e2245 * rhs->e5 + lhs->e22 * rhs->e455 
             + lhs->e455 * rhs->e22 + lhs->e24 * rhs->e255 + lhs->e255 * rhs->e24 
             + lhs->e25 * rhs->e245 + lhs->e245 * rhs->e25 + lhs->e45 * rhs->e225 
             + lhs->e225 * rhs->e45 + lhs->e55 * rhs->e224 + lhs->e224 * rhs->e55;
  res->e13455 = lhs->r * rhs->e13455 + lhs->e13455 * rhs->r + lhs->e1 * rhs->e3455 
             + lhs->e3455 * rhs->e1 + lhs->e3 * rhs->e1455 + lhs->e1455 * rhs->e3 
             + lhs->e4 * rhs->e1355 + lhs->e1355 * rhs->e4 + lhs->e5 * rhs->e1345 
             + lhs->e1345 * rhs->e5 + lhs->e13 * rhs->e455 + lhs->e455 * rhs->e13 
             + lhs->e14 * rhs->e355 + lhs->e355 * rhs->e14 + lhs->e34 * rhs->e155 
             + lhs->e155 * rhs->e34 + lhs->e15 * rhs->e345 + lhs->e345 * rhs->e15 
             + lhs->e35 * rhs->e145 + lhs->e145 * rhs->e35 + lhs->e45 * rhs->e135 
             + lhs->e135 * rhs->e45 + lhs->e55 * rhs->e134 + lhs->e134 * rhs->e55;
  res->e23455 = lhs->r * rhs->e23455 + lhs->e23455 * rhs->r + lhs->e2 * rhs->e3455 
             + lhs->e3455 * rhs->e2 + lhs->e3 * rhs->e2455 + lhs->e2455 * rhs->e3 
             + lhs->e4 * rhs->e2355 + lhs->e2355 * rhs->e4 + lhs->e5 * rhs->e2345 
             + lhs->e2345 * rhs->e5 + lhs->e23 * rhs->e455 + lhs->e455 * rhs->e23 
             + lhs->e24 * rhs->e355 + lhs->e355 * rhs->e24 + lhs->e34 * rhs->e255 
             + lhs->e255 * rhs->e34 + lhs->e25 * rhs->e345 + lhs->e345 * rhs->e25 
             + lhs->e35 * rhs->e245 + lhs->e245 * rhs->e35 + lhs->e45 * rhs->e235 
             + lhs->e235 * rhs->e45 + lhs->e55 * rhs->e234 + lhs->e234 * rhs->e55;
  res->e33455 = lhs->r * rhs->e33455 + lhs->e33455 * rhs->r + lhs->e3 * rhs->e3455 
             + lhs->e3455 * rhs->e3 + lhs->e4 * rhs->e3355 + lhs->e3355 * rhs->e4 
             + lhs->e5 * rhs->e3345 + lhs->e3345 * rhs->e5 + lhs->e33 * rhs->e455 
             + lhs->e455 * rhs->e33 + lhs->e34 * rhs->e355 + lhs->e355 * rhs->e34 
             + lhs->e35 * rhs->e345 + lhs->e345 * rhs->e35 + lhs->e45 * rhs->e335 
             + lhs->e335 * rhs->e45 + lhs->e55 * rhs->e334 + lhs->e334 * rhs->e55;
  res->e14455 = lhs->r * rhs->e14455 + lhs->e14455 * rhs->r + lhs->e1 * rhs->e4455 
             + lhs->e4455 * rhs->e1 + lhs->e4 * rhs->e1455 + lhs->e1455 * rhs->e4 
             + lhs->e5 * rhs->e1445 + lhs->e1445 * rhs->e5 + lhs->e14 * rhs->e455 
             + lhs->e455 * rhs->e14 + lhs->e44 * rhs->e155 + lhs->e155 * rhs->e44 
             + lhs->e15 * rhs->e445 + lhs->e445 * rhs->e15 + lhs->e45 * rhs->e145 
             + lhs->e145 * rhs->e45 + lhs->e55 * rhs->e144 + lhs->e144 * rhs->e55;
  res->e24455 = lhs->r * rhs->e24455 + lhs->e24455 * rhs->r + lhs->e2 * rhs->e4455 
             + lhs->e4455 * rhs->e2 + lhs->e4 * rhs->e2455 + lhs->e2455 * rhs->e4 
             + lhs->e5 * rhs->e2445 + lhs->e2445 * rhs->e5 + lhs->e24 * rhs->e455 
             + lhs->e455 * rhs->e24 + lhs->e44 * rhs->e255 + lhs->e255 * rhs->e44 
             + lhs->e25 * rhs->e445 + lhs->e445 * rhs->e25 + lhs->e45 * rhs->e245 
             + lhs->e245 * rhs->e45 + lhs->e55 * rhs->e244 + lhs->e244 * rhs->e55;
  res->e34455 = lhs->r * rhs->e34455 + lhs->e34455 * rhs->r + lhs->e3 * rhs->e4455 
             + lhs->e4455 * rhs->e3 + lhs->e4 * rhs->e3455 + lhs->e3455 * rhs->e4 
             + lhs->e5 * rhs->e3445 + lhs->e3445 * rhs->e5 + lhs->e34 * rhs->e455 
             + lhs->e455 * rhs->e34 + lhs->e44 * rhs->e355 + lhs->e355 * rhs->e44 
             + lhs->e35 * rhs->e445 + lhs->e445 * rhs->e35 + lhs->e45 * rhs->e345 
             + lhs->e345 * rhs->e45 + lhs->e55 * rhs->e344 + lhs->e344 * rhs->e55;
  res->e44455 = lhs->r * rhs->e44455 + lhs->e44455 * rhs->r + lhs->e4 * rhs->e4455 
             + lhs->e4455 * rhs->e4 + lhs->e5 * rhs->e4445 + lhs->e4445 * rhs->e5 
             + lhs->e44 * rhs->e455 + lhs->e455 * rhs->e44 + lhs->e45 * rhs->e445 
             + lhs->e445 * rhs->e45 + lhs->e55 * rhs->e444 + lhs->e444 * rhs->e55;
  res->e11555 = lhs->r * rhs->e11555 + lhs->e11555 * rhs->r + lhs->e1 * rhs->e1555 
             + lhs->e1555 * rhs->e1 + lhs->e5 * rhs->e1155 + lhs->e1155 * rhs->e5 
             + lhs->e11 * rhs->e555 + lhs->e555 * rhs->e11 + lhs->e15 * rhs->e155 
             + lhs->e155 * rhs->e15 + lhs->e55 * rhs->e115 + lhs->e115 * rhs->e55;
  res->e12555 = lhs->r * rhs->e12555 + lhs->e12555 * rhs->r + lhs->e1 * rhs->e2555 
             + lhs->e2555 * rhs->e1 + lhs->e2 * rhs->e1555 + lhs->e1555 * rhs->e2 
             + lhs->e5 * rhs->e1255 + lhs->e1255 * rhs->e5 + lhs->e12 * rhs->e555 
             + lhs->e555 * rhs->e12 + lhs->e15 * rhs->e255 + lhs->e255 * rhs->e15 
             + lhs->e25 * rhs->e155 + lhs->e155 * rhs->e25 + lhs->e55 * rhs->e125 
             + lhs->e125 * rhs->e55;
  res->e22555 = lhs->r * rhs->e22555 + lhs->e22555 * rhs->r + lhs->e2 * rhs->e2555 
             + lhs->e2555 * rhs->e2 + lhs->e5 * rhs->e2255 + lhs->e2255 * rhs->e5 
             + lhs->e22 * rhs->e555 + lhs->e555 * rhs->e22 + lhs->e25 * rhs->e255 
             + lhs->e255 * rhs->e25 + lhs->e55 * rhs->e225 + lhs->e225 * rhs->e55;
  res->e13555 = lhs->r * rhs->e13555 + lhs->e13555 * rhs->r + lhs->e1 * rhs->e3555 
             + lhs->e3555 * rhs->e1 + lhs->e3 * rhs->e1555 + lhs->e1555 * rhs->e3 
             + lhs->e5 * rhs->e1355 + lhs->e1355 * rhs->e5 + lhs->e13 * rhs->e555 
             + lhs->e555 * rhs->e13 + lhs->e15 * rhs->e355 + lhs->e355 * rhs->e15 
             + lhs->e35 * rhs->e155 + lhs->e155 * rhs->e35 + lhs->e55 * rhs->e135 
             + lhs->e135 * rhs->e55;
  res->e23555 = lhs->r * rhs->e23555 + lhs->e23555 * rhs->r + lhs->e2 * rhs->e3555 
             + lhs->e3555 * rhs->e2 + lhs->e3 * rhs->e2555 + lhs->e2555 * rhs->e3 
             + lhs->e5 * rhs->e2355 + lhs->e2355 * rhs->e5 + lhs->e23 * rhs->e555 
             + lhs->e555 * rhs->e23 + lhs->e25 * rhs->e355 + lhs->e355 * rhs->e25 
             + lhs->e35 * rhs->e255 + lhs->e255 * rhs->e35 + lhs->e55 * rhs->e235 
             + lhs->e235 * rhs->e55;
  res->e33555 = lhs->r * rhs->e33555 + lhs->e33555 * rhs->r + lhs->e3 * rhs->e3555 
             + lhs->e3555 * rhs->e3 + lhs->e5 * rhs->e3355 + lhs->e3355 * rhs->e5 
             + lhs->e33 * rhs->e555 + lhs->e555 * rhs->e33 + lhs->e35 * rhs->e355 
             + lhs->e355 * rhs->e35 + lhs->e55 * rhs->e335 + lhs->e335 * rhs->e55;
  res->e14555 = lhs->r * rhs->e14555 + lhs->e14555 * rhs->r + lhs->e1 * rhs->e4555 
             + lhs->e4555 * rhs->e1 + lhs->e4 * rhs->e1555 + lhs->e1555 * rhs->e4 
             + lhs->e5 * rhs->e1455 + lhs->e1455 * rhs->e5 + lhs->e14 * rhs->e555 
             + lhs->e555 * rhs->e14 + lhs->e15 * rhs->e455 + lhs->e455 * rhs->e15 
             + lhs->e45 * rhs->e155 + lhs->e155 * rhs->e45 + lhs->e55 * rhs->e145 
             + lhs->e145 * rhs->e55;
  res->e24555 = lhs->r * rhs->e24555 + lhs->e24555 * rhs->r + lhs->e2 * rhs->e4555 
             + lhs->e4555 * rhs->e2 + lhs->e4 * rhs->e2555 + lhs->e2555 * rhs->e4 
             + lhs->e5 * rhs->e2455 + lhs->e2455 * rhs->e5 + lhs->e24 * rhs->e555 
             + lhs->e555 * rhs->e24 + lhs->e25 * rhs->e455 + lhs->e455 * rhs->e25 
             + lhs->e45 * rhs->e255 + lhs->e255 * rhs->e45 + lhs->e55 * rhs->e245 
             + lhs->e245 * rhs->e55;
  res->e34555 = lhs->r * rhs->e34555 + lhs->e34555 * rhs->r + lhs->e3 * rhs->e4555 
             + lhs->e4555 * rhs->e3 + lhs->e4 * rhs->e3555 + lhs->e3555 * rhs->e4 
             + lhs->e5 * rhs->e3455 + lhs->e3455 * rhs->e5 + lhs->e34 * rhs->e555 
             + lhs->e555 * rhs->e34 + lhs->e35 * rhs->e455 + lhs->e455 * rhs->e35 
             + lhs->e45 * rhs->e355 + lhs->e355 * rhs->e45 + lhs->e55 * rhs->e345 
             + lhs->e345 * rhs->e55;
  res->e44555 = lhs->r * rhs->e44555 + lhs->e44555 * rhs->r + lhs->e4 * rhs->e4555 
             + lhs->e4555 * rhs->e4 + lhs->e5 * rhs->e4455 + lhs->e4455 * rhs->e5 
             + lhs->e44 * rhs->e555 + lhs->e555 * rhs->e44 + lhs->e45 * rhs->e455 
             + lhs->e455 * rhs->e45 + lhs->e55 * rhs->e445 + lhs->e445 * rhs->e55;
  res->e15555 = lhs->r * rhs->e15555 + lhs->e15555 * rhs->r + lhs->e1 * rhs->e5555 
             + lhs->e5555 * rhs->e1 + lhs->e5 * rhs->e1555 + lhs->e1555 * rhs->e5 
             + lhs->e15 * rhs->e555 + lhs->e555 * rhs->e15 + lhs->e55 * rhs->e155 
             + lhs->e155 * rhs->e55;
  res->e25555 = lhs->r * rhs->e25555 + lhs->e25555 * rhs->r + lhs->e2 * rhs->e5555 
             + lhs->e5555 * rhs->e2 + lhs->e5 * rhs->e2555 + lhs->e2555 * rhs->e5 
             + lhs->e25 * rhs->e555 + lhs->e555 * rhs->e25 + lhs->e55 * rhs->e255 
             + lhs->e255 * rhs->e55;
  res->e35555 = lhs->r * rhs->e35555 + lhs->e35555 * rhs->r + lhs->e3 * rhs->e5555 
             + lhs->e5555 * rhs->e3 + lhs->e5 * rhs->e3555 + lhs->e3555 * rhs->e5 
             + lhs->e35 * rhs->e555 + lhs->e555 * rhs->e35 + lhs->e55 * rhs->e355 
             + lhs->e355 * rhs->e55;
  res->e45555 = lhs->r * rhs->e45555 + lhs->e45555 * rhs->r + lhs->e4 * rhs->e5555 
             + lhs->e5555 * rhs->e4 + lhs->e5 * rhs->e4555 + lhs->e4555 * rhs->e5 
             + lhs->e45 * rhs->e555 + lhs->e555 * rhs->e45 + lhs->e55 * rhs->e455 
             + lhs->e455 * rhs->e55;
  res->e55555 = lhs->r * rhs->e55555 + lhs->e55555 * rhs->r + lhs->e5 * rhs->e5555 
             + lhs->e5555 * rhs->e5 + lhs->e55 * rhs->e555 + lhs->e555 * rhs->e55;

}

onumm5n5_t onumm5n5_mul_ro(  coeff_t lhs,  onumm5n5_t* rhs){
  onumm5n5_t res;

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
  res.e1115 = lhs * rhs->e1115;
  res.e1125 = lhs * rhs->e1125;
  res.e1225 = lhs * rhs->e1225;
  res.e2225 = lhs * rhs->e2225;
  res.e1135 = lhs * rhs->e1135;
  res.e1235 = lhs * rhs->e1235;
  res.e2235 = lhs * rhs->e2235;
  res.e1335 = lhs * rhs->e1335;
  res.e2335 = lhs * rhs->e2335;
  res.e3335 = lhs * rhs->e3335;
  res.e1145 = lhs * rhs->e1145;
  res.e1245 = lhs * rhs->e1245;
  res.e2245 = lhs * rhs->e2245;
  res.e1345 = lhs * rhs->e1345;
  res.e2345 = lhs * rhs->e2345;
  res.e3345 = lhs * rhs->e3345;
  res.e1445 = lhs * rhs->e1445;
  res.e2445 = lhs * rhs->e2445;
  res.e3445 = lhs * rhs->e3445;
  res.e4445 = lhs * rhs->e4445;
  res.e1155 = lhs * rhs->e1155;
  res.e1255 = lhs * rhs->e1255;
  res.e2255 = lhs * rhs->e2255;
  res.e1355 = lhs * rhs->e1355;
  res.e2355 = lhs * rhs->e2355;
  res.e3355 = lhs * rhs->e3355;
  res.e1455 = lhs * rhs->e1455;
  res.e2455 = lhs * rhs->e2455;
  res.e3455 = lhs * rhs->e3455;
  res.e4455 = lhs * rhs->e4455;
  res.e1555 = lhs * rhs->e1555;
  res.e2555 = lhs * rhs->e2555;
  res.e3555 = lhs * rhs->e3555;
  res.e4555 = lhs * rhs->e4555;
  res.e5555 = lhs * rhs->e5555;
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
  res.e11115 = lhs * rhs->e11115;
  res.e11125 = lhs * rhs->e11125;
  res.e11225 = lhs * rhs->e11225;
  res.e12225 = lhs * rhs->e12225;
  res.e22225 = lhs * rhs->e22225;
  res.e11135 = lhs * rhs->e11135;
  res.e11235 = lhs * rhs->e11235;
  res.e12235 = lhs * rhs->e12235;
  res.e22235 = lhs * rhs->e22235;
  res.e11335 = lhs * rhs->e11335;
  res.e12335 = lhs * rhs->e12335;
  res.e22335 = lhs * rhs->e22335;
  res.e13335 = lhs * rhs->e13335;
  res.e23335 = lhs * rhs->e23335;
  res.e33335 = lhs * rhs->e33335;
  res.e11145 = lhs * rhs->e11145;
  res.e11245 = lhs * rhs->e11245;
  res.e12245 = lhs * rhs->e12245;
  res.e22245 = lhs * rhs->e22245;
  res.e11345 = lhs * rhs->e11345;
  res.e12345 = lhs * rhs->e12345;
  res.e22345 = lhs * rhs->e22345;
  res.e13345 = lhs * rhs->e13345;
  res.e23345 = lhs * rhs->e23345;
  res.e33345 = lhs * rhs->e33345;
  res.e11445 = lhs * rhs->e11445;
  res.e12445 = lhs * rhs->e12445;
  res.e22445 = lhs * rhs->e22445;
  res.e13445 = lhs * rhs->e13445;
  res.e23445 = lhs * rhs->e23445;
  res.e33445 = lhs * rhs->e33445;
  res.e14445 = lhs * rhs->e14445;
  res.e24445 = lhs * rhs->e24445;
  res.e34445 = lhs * rhs->e34445;
  res.e44445 = lhs * rhs->e44445;
  res.e11155 = lhs * rhs->e11155;
  res.e11255 = lhs * rhs->e11255;
  res.e12255 = lhs * rhs->e12255;
  res.e22255 = lhs * rhs->e22255;
  res.e11355 = lhs * rhs->e11355;
  res.e12355 = lhs * rhs->e12355;
  res.e22355 = lhs * rhs->e22355;
  res.e13355 = lhs * rhs->e13355;
  res.e23355 = lhs * rhs->e23355;
  res.e33355 = lhs * rhs->e33355;
  res.e11455 = lhs * rhs->e11455;
  res.e12455 = lhs * rhs->e12455;
  res.e22455 = lhs * rhs->e22455;
  res.e13455 = lhs * rhs->e13455;
  res.e23455 = lhs * rhs->e23455;
  res.e33455 = lhs * rhs->e33455;
  res.e14455 = lhs * rhs->e14455;
  res.e24455 = lhs * rhs->e24455;
  res.e34455 = lhs * rhs->e34455;
  res.e44455 = lhs * rhs->e44455;
  res.e11555 = lhs * rhs->e11555;
  res.e12555 = lhs * rhs->e12555;
  res.e22555 = lhs * rhs->e22555;
  res.e13555 = lhs * rhs->e13555;
  res.e23555 = lhs * rhs->e23555;
  res.e33555 = lhs * rhs->e33555;
  res.e14555 = lhs * rhs->e14555;
  res.e24555 = lhs * rhs->e24555;
  res.e34555 = lhs * rhs->e34555;
  res.e44555 = lhs * rhs->e44555;
  res.e15555 = lhs * rhs->e15555;
  res.e25555 = lhs * rhs->e25555;
  res.e35555 = lhs * rhs->e35555;
  res.e45555 = lhs * rhs->e45555;
  res.e55555 = lhs * rhs->e55555;

  return res;

}

void onumm5n5_mul_ro_to(  coeff_t lhs,  onumm5n5_t* rhs, onumm5n5_t* res){
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
  res->e1115 = lhs * rhs->e1115;
  res->e1125 = lhs * rhs->e1125;
  res->e1225 = lhs * rhs->e1225;
  res->e2225 = lhs * rhs->e2225;
  res->e1135 = lhs * rhs->e1135;
  res->e1235 = lhs * rhs->e1235;
  res->e2235 = lhs * rhs->e2235;
  res->e1335 = lhs * rhs->e1335;
  res->e2335 = lhs * rhs->e2335;
  res->e3335 = lhs * rhs->e3335;
  res->e1145 = lhs * rhs->e1145;
  res->e1245 = lhs * rhs->e1245;
  res->e2245 = lhs * rhs->e2245;
  res->e1345 = lhs * rhs->e1345;
  res->e2345 = lhs * rhs->e2345;
  res->e3345 = lhs * rhs->e3345;
  res->e1445 = lhs * rhs->e1445;
  res->e2445 = lhs * rhs->e2445;
  res->e3445 = lhs * rhs->e3445;
  res->e4445 = lhs * rhs->e4445;
  res->e1155 = lhs * rhs->e1155;
  res->e1255 = lhs * rhs->e1255;
  res->e2255 = lhs * rhs->e2255;
  res->e1355 = lhs * rhs->e1355;
  res->e2355 = lhs * rhs->e2355;
  res->e3355 = lhs * rhs->e3355;
  res->e1455 = lhs * rhs->e1455;
  res->e2455 = lhs * rhs->e2455;
  res->e3455 = lhs * rhs->e3455;
  res->e4455 = lhs * rhs->e4455;
  res->e1555 = lhs * rhs->e1555;
  res->e2555 = lhs * rhs->e2555;
  res->e3555 = lhs * rhs->e3555;
  res->e4555 = lhs * rhs->e4555;
  res->e5555 = lhs * rhs->e5555;
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
  res->e11115 = lhs * rhs->e11115;
  res->e11125 = lhs * rhs->e11125;
  res->e11225 = lhs * rhs->e11225;
  res->e12225 = lhs * rhs->e12225;
  res->e22225 = lhs * rhs->e22225;
  res->e11135 = lhs * rhs->e11135;
  res->e11235 = lhs * rhs->e11235;
  res->e12235 = lhs * rhs->e12235;
  res->e22235 = lhs * rhs->e22235;
  res->e11335 = lhs * rhs->e11335;
  res->e12335 = lhs * rhs->e12335;
  res->e22335 = lhs * rhs->e22335;
  res->e13335 = lhs * rhs->e13335;
  res->e23335 = lhs * rhs->e23335;
  res->e33335 = lhs * rhs->e33335;
  res->e11145 = lhs * rhs->e11145;
  res->e11245 = lhs * rhs->e11245;
  res->e12245 = lhs * rhs->e12245;
  res->e22245 = lhs * rhs->e22245;
  res->e11345 = lhs * rhs->e11345;
  res->e12345 = lhs * rhs->e12345;
  res->e22345 = lhs * rhs->e22345;
  res->e13345 = lhs * rhs->e13345;
  res->e23345 = lhs * rhs->e23345;
  res->e33345 = lhs * rhs->e33345;
  res->e11445 = lhs * rhs->e11445;
  res->e12445 = lhs * rhs->e12445;
  res->e22445 = lhs * rhs->e22445;
  res->e13445 = lhs * rhs->e13445;
  res->e23445 = lhs * rhs->e23445;
  res->e33445 = lhs * rhs->e33445;
  res->e14445 = lhs * rhs->e14445;
  res->e24445 = lhs * rhs->e24445;
  res->e34445 = lhs * rhs->e34445;
  res->e44445 = lhs * rhs->e44445;
  res->e11155 = lhs * rhs->e11155;
  res->e11255 = lhs * rhs->e11255;
  res->e12255 = lhs * rhs->e12255;
  res->e22255 = lhs * rhs->e22255;
  res->e11355 = lhs * rhs->e11355;
  res->e12355 = lhs * rhs->e12355;
  res->e22355 = lhs * rhs->e22355;
  res->e13355 = lhs * rhs->e13355;
  res->e23355 = lhs * rhs->e23355;
  res->e33355 = lhs * rhs->e33355;
  res->e11455 = lhs * rhs->e11455;
  res->e12455 = lhs * rhs->e12455;
  res->e22455 = lhs * rhs->e22455;
  res->e13455 = lhs * rhs->e13455;
  res->e23455 = lhs * rhs->e23455;
  res->e33455 = lhs * rhs->e33455;
  res->e14455 = lhs * rhs->e14455;
  res->e24455 = lhs * rhs->e24455;
  res->e34455 = lhs * rhs->e34455;
  res->e44455 = lhs * rhs->e44455;
  res->e11555 = lhs * rhs->e11555;
  res->e12555 = lhs * rhs->e12555;
  res->e22555 = lhs * rhs->e22555;
  res->e13555 = lhs * rhs->e13555;
  res->e23555 = lhs * rhs->e23555;
  res->e33555 = lhs * rhs->e33555;
  res->e14555 = lhs * rhs->e14555;
  res->e24555 = lhs * rhs->e24555;
  res->e34555 = lhs * rhs->e34555;
  res->e44555 = lhs * rhs->e44555;
  res->e15555 = lhs * rhs->e15555;
  res->e25555 = lhs * rhs->e25555;
  res->e35555 = lhs * rhs->e35555;
  res->e45555 = lhs * rhs->e45555;
  res->e55555 = lhs * rhs->e55555;

}

onumm5n5_t onumm5n5_trunc_mul_oo(  onumm5n5_t* lhs,  onumm5n5_t* rhs){
  onumm5n5_t res;

  res = onumm5n5_init();

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
  res.e1115 =  + lhs->e1 * rhs->e115 + lhs->e115 * rhs->e1 + lhs->e5 * rhs->e111 
            + lhs->e111 * rhs->e5 + lhs->e11 * rhs->e15 + lhs->e15 * rhs->e11;
  res.e1125 =  + lhs->e1 * rhs->e125 + lhs->e125 * rhs->e1 + lhs->e2 * rhs->e115 
            + lhs->e115 * rhs->e2 + lhs->e5 * rhs->e112 + lhs->e112 * rhs->e5 
            + lhs->e11 * rhs->e25 + lhs->e12 * rhs->e15 + lhs->e15 * rhs->e12 
            + lhs->e25 * rhs->e11;
  res.e1225 =  + lhs->e1 * rhs->e225 + lhs->e225 * rhs->e1 + lhs->e2 * rhs->e125 
            + lhs->e125 * rhs->e2 + lhs->e5 * rhs->e122 + lhs->e122 * rhs->e5 
            + lhs->e12 * rhs->e25 + lhs->e22 * rhs->e15 + lhs->e15 * rhs->e22 
            + lhs->e25 * rhs->e12;
  res.e2225 =  + lhs->e2 * rhs->e225 + lhs->e225 * rhs->e2 + lhs->e5 * rhs->e222 
            + lhs->e222 * rhs->e5 + lhs->e22 * rhs->e25 + lhs->e25 * rhs->e22;
  res.e1135 =  + lhs->e1 * rhs->e135 + lhs->e135 * rhs->e1 + lhs->e3 * rhs->e115 
            + lhs->e115 * rhs->e3 + lhs->e5 * rhs->e113 + lhs->e113 * rhs->e5 
            + lhs->e11 * rhs->e35 + lhs->e13 * rhs->e15 + lhs->e15 * rhs->e13 
            + lhs->e35 * rhs->e11;
  res.e1235 =  + lhs->e1 * rhs->e235 + lhs->e235 * rhs->e1 + lhs->e2 * rhs->e135 
            + lhs->e135 * rhs->e2 + lhs->e3 * rhs->e125 + lhs->e125 * rhs->e3 
            + lhs->e5 * rhs->e123 + lhs->e123 * rhs->e5 + lhs->e12 * rhs->e35 
            + lhs->e13 * rhs->e25 + lhs->e23 * rhs->e15 + lhs->e15 * rhs->e23 
            + lhs->e25 * rhs->e13 + lhs->e35 * rhs->e12;
  res.e2235 =  + lhs->e2 * rhs->e235 + lhs->e235 * rhs->e2 + lhs->e3 * rhs->e225 
            + lhs->e225 * rhs->e3 + lhs->e5 * rhs->e223 + lhs->e223 * rhs->e5 
            + lhs->e22 * rhs->e35 + lhs->e23 * rhs->e25 + lhs->e25 * rhs->e23 
            + lhs->e35 * rhs->e22;
  res.e1335 =  + lhs->e1 * rhs->e335 + lhs->e335 * rhs->e1 + lhs->e3 * rhs->e135 
            + lhs->e135 * rhs->e3 + lhs->e5 * rhs->e133 + lhs->e133 * rhs->e5 
            + lhs->e13 * rhs->e35 + lhs->e33 * rhs->e15 + lhs->e15 * rhs->e33 
            + lhs->e35 * rhs->e13;
  res.e2335 =  + lhs->e2 * rhs->e335 + lhs->e335 * rhs->e2 + lhs->e3 * rhs->e235 
            + lhs->e235 * rhs->e3 + lhs->e5 * rhs->e233 + lhs->e233 * rhs->e5 
            + lhs->e23 * rhs->e35 + lhs->e33 * rhs->e25 + lhs->e25 * rhs->e33 
            + lhs->e35 * rhs->e23;
  res.e3335 =  + lhs->e3 * rhs->e335 + lhs->e335 * rhs->e3 + lhs->e5 * rhs->e333 
            + lhs->e333 * rhs->e5 + lhs->e33 * rhs->e35 + lhs->e35 * rhs->e33;
  res.e1145 =  + lhs->e1 * rhs->e145 + lhs->e145 * rhs->e1 + lhs->e4 * rhs->e115 
            + lhs->e115 * rhs->e4 + lhs->e5 * rhs->e114 + lhs->e114 * rhs->e5 
            + lhs->e11 * rhs->e45 + lhs->e14 * rhs->e15 + lhs->e15 * rhs->e14 
            + lhs->e45 * rhs->e11;
  res.e1245 =  + lhs->e1 * rhs->e245 + lhs->e245 * rhs->e1 + lhs->e2 * rhs->e145 
            + lhs->e145 * rhs->e2 + lhs->e4 * rhs->e125 + lhs->e125 * rhs->e4 
            + lhs->e5 * rhs->e124 + lhs->e124 * rhs->e5 + lhs->e12 * rhs->e45 
            + lhs->e14 * rhs->e25 + lhs->e24 * rhs->e15 + lhs->e15 * rhs->e24 
            + lhs->e25 * rhs->e14 + lhs->e45 * rhs->e12;
  res.e2245 =  + lhs->e2 * rhs->e245 + lhs->e245 * rhs->e2 + lhs->e4 * rhs->e225 
            + lhs->e225 * rhs->e4 + lhs->e5 * rhs->e224 + lhs->e224 * rhs->e5 
            + lhs->e22 * rhs->e45 + lhs->e24 * rhs->e25 + lhs->e25 * rhs->e24 
            + lhs->e45 * rhs->e22;
  res.e1345 =  + lhs->e1 * rhs->e345 + lhs->e345 * rhs->e1 + lhs->e3 * rhs->e145 
            + lhs->e145 * rhs->e3 + lhs->e4 * rhs->e135 + lhs->e135 * rhs->e4 
            + lhs->e5 * rhs->e134 + lhs->e134 * rhs->e5 + lhs->e13 * rhs->e45 
            + lhs->e14 * rhs->e35 + lhs->e34 * rhs->e15 + lhs->e15 * rhs->e34 
            + lhs->e35 * rhs->e14 + lhs->e45 * rhs->e13;
  res.e2345 =  + lhs->e2 * rhs->e345 + lhs->e345 * rhs->e2 + lhs->e3 * rhs->e245 
            + lhs->e245 * rhs->e3 + lhs->e4 * rhs->e235 + lhs->e235 * rhs->e4 
            + lhs->e5 * rhs->e234 + lhs->e234 * rhs->e5 + lhs->e23 * rhs->e45 
            + lhs->e24 * rhs->e35 + lhs->e34 * rhs->e25 + lhs->e25 * rhs->e34 
            + lhs->e35 * rhs->e24 + lhs->e45 * rhs->e23;
  res.e3345 =  + lhs->e3 * rhs->e345 + lhs->e345 * rhs->e3 + lhs->e4 * rhs->e335 
            + lhs->e335 * rhs->e4 + lhs->e5 * rhs->e334 + lhs->e334 * rhs->e5 
            + lhs->e33 * rhs->e45 + lhs->e34 * rhs->e35 + lhs->e35 * rhs->e34 
            + lhs->e45 * rhs->e33;
  res.e1445 =  + lhs->e1 * rhs->e445 + lhs->e445 * rhs->e1 + lhs->e4 * rhs->e145 
            + lhs->e145 * rhs->e4 + lhs->e5 * rhs->e144 + lhs->e144 * rhs->e5 
            + lhs->e14 * rhs->e45 + lhs->e44 * rhs->e15 + lhs->e15 * rhs->e44 
            + lhs->e45 * rhs->e14;
  res.e2445 =  + lhs->e2 * rhs->e445 + lhs->e445 * rhs->e2 + lhs->e4 * rhs->e245 
            + lhs->e245 * rhs->e4 + lhs->e5 * rhs->e244 + lhs->e244 * rhs->e5 
            + lhs->e24 * rhs->e45 + lhs->e44 * rhs->e25 + lhs->e25 * rhs->e44 
            + lhs->e45 * rhs->e24;
  res.e3445 =  + lhs->e3 * rhs->e445 + lhs->e445 * rhs->e3 + lhs->e4 * rhs->e345 
            + lhs->e345 * rhs->e4 + lhs->e5 * rhs->e344 + lhs->e344 * rhs->e5 
            + lhs->e34 * rhs->e45 + lhs->e44 * rhs->e35 + lhs->e35 * rhs->e44 
            + lhs->e45 * rhs->e34;
  res.e4445 =  + lhs->e4 * rhs->e445 + lhs->e445 * rhs->e4 + lhs->e5 * rhs->e444 
            + lhs->e444 * rhs->e5 + lhs->e44 * rhs->e45 + lhs->e45 * rhs->e44;
  res.e1155 =  + lhs->e1 * rhs->e155 + lhs->e155 * rhs->e1 + lhs->e5 * rhs->e115 
            + lhs->e115 * rhs->e5 + lhs->e11 * rhs->e55 + lhs->e15 * rhs->e15 
            + lhs->e55 * rhs->e11;
  res.e1255 =  + lhs->e1 * rhs->e255 + lhs->e255 * rhs->e1 + lhs->e2 * rhs->e155 
            + lhs->e155 * rhs->e2 + lhs->e5 * rhs->e125 + lhs->e125 * rhs->e5 
            + lhs->e12 * rhs->e55 + lhs->e15 * rhs->e25 + lhs->e25 * rhs->e15 
            + lhs->e55 * rhs->e12;
  res.e2255 =  + lhs->e2 * rhs->e255 + lhs->e255 * rhs->e2 + lhs->e5 * rhs->e225 
            + lhs->e225 * rhs->e5 + lhs->e22 * rhs->e55 + lhs->e25 * rhs->e25 
            + lhs->e55 * rhs->e22;
  res.e1355 =  + lhs->e1 * rhs->e355 + lhs->e355 * rhs->e1 + lhs->e3 * rhs->e155 
            + lhs->e155 * rhs->e3 + lhs->e5 * rhs->e135 + lhs->e135 * rhs->e5 
            + lhs->e13 * rhs->e55 + lhs->e15 * rhs->e35 + lhs->e35 * rhs->e15 
            + lhs->e55 * rhs->e13;
  res.e2355 =  + lhs->e2 * rhs->e355 + lhs->e355 * rhs->e2 + lhs->e3 * rhs->e255 
            + lhs->e255 * rhs->e3 + lhs->e5 * rhs->e235 + lhs->e235 * rhs->e5 
            + lhs->e23 * rhs->e55 + lhs->e25 * rhs->e35 + lhs->e35 * rhs->e25 
            + lhs->e55 * rhs->e23;
  res.e3355 =  + lhs->e3 * rhs->e355 + lhs->e355 * rhs->e3 + lhs->e5 * rhs->e335 
            + lhs->e335 * rhs->e5 + lhs->e33 * rhs->e55 + lhs->e35 * rhs->e35 
            + lhs->e55 * rhs->e33;
  res.e1455 =  + lhs->e1 * rhs->e455 + lhs->e455 * rhs->e1 + lhs->e4 * rhs->e155 
            + lhs->e155 * rhs->e4 + lhs->e5 * rhs->e145 + lhs->e145 * rhs->e5 
            + lhs->e14 * rhs->e55 + lhs->e15 * rhs->e45 + lhs->e45 * rhs->e15 
            + lhs->e55 * rhs->e14;
  res.e2455 =  + lhs->e2 * rhs->e455 + lhs->e455 * rhs->e2 + lhs->e4 * rhs->e255 
            + lhs->e255 * rhs->e4 + lhs->e5 * rhs->e245 + lhs->e245 * rhs->e5 
            + lhs->e24 * rhs->e55 + lhs->e25 * rhs->e45 + lhs->e45 * rhs->e25 
            + lhs->e55 * rhs->e24;
  res.e3455 =  + lhs->e3 * rhs->e455 + lhs->e455 * rhs->e3 + lhs->e4 * rhs->e355 
            + lhs->e355 * rhs->e4 + lhs->e5 * rhs->e345 + lhs->e345 * rhs->e5 
            + lhs->e34 * rhs->e55 + lhs->e35 * rhs->e45 + lhs->e45 * rhs->e35 
            + lhs->e55 * rhs->e34;
  res.e4455 =  + lhs->e4 * rhs->e455 + lhs->e455 * rhs->e4 + lhs->e5 * rhs->e445 
            + lhs->e445 * rhs->e5 + lhs->e44 * rhs->e55 + lhs->e45 * rhs->e45 
            + lhs->e55 * rhs->e44;
  res.e1555 =  + lhs->e1 * rhs->e555 + lhs->e555 * rhs->e1 + lhs->e5 * rhs->e155 
            + lhs->e155 * rhs->e5 + lhs->e15 * rhs->e55 + lhs->e55 * rhs->e15;
  res.e2555 =  + lhs->e2 * rhs->e555 + lhs->e555 * rhs->e2 + lhs->e5 * rhs->e255 
            + lhs->e255 * rhs->e5 + lhs->e25 * rhs->e55 + lhs->e55 * rhs->e25;
  res.e3555 =  + lhs->e3 * rhs->e555 + lhs->e555 * rhs->e3 + lhs->e5 * rhs->e355 
            + lhs->e355 * rhs->e5 + lhs->e35 * rhs->e55 + lhs->e55 * rhs->e35;
  res.e4555 =  + lhs->e4 * rhs->e555 + lhs->e555 * rhs->e4 + lhs->e5 * rhs->e455 
            + lhs->e455 * rhs->e5 + lhs->e45 * rhs->e55 + lhs->e55 * rhs->e45;
  res.e5555 =  + lhs->e5 * rhs->e555 + lhs->e555 * rhs->e5 + lhs->e55 * rhs->e55;
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
  res.e11115 =  + lhs->e1 * rhs->e1115 + lhs->e1115 * rhs->e1 + lhs->e5 * rhs->e1111 
             + lhs->e1111 * rhs->e5 + lhs->e11 * rhs->e115 + lhs->e115 * rhs->e11 
             + lhs->e15 * rhs->e111 + lhs->e111 * rhs->e15;
  res.e11125 =  + lhs->e1 * rhs->e1125 + lhs->e1125 * rhs->e1 + lhs->e2 * rhs->e1115 
             + lhs->e1115 * rhs->e2 + lhs->e5 * rhs->e1112 + lhs->e1112 * rhs->e5 
             + lhs->e11 * rhs->e125 + lhs->e125 * rhs->e11 + lhs->e12 * rhs->e115 
             + lhs->e115 * rhs->e12 + lhs->e15 * rhs->e112 + lhs->e112 * rhs->e15 
             + lhs->e25 * rhs->e111 + lhs->e111 * rhs->e25;
  res.e11225 =  + lhs->e1 * rhs->e1225 + lhs->e1225 * rhs->e1 + lhs->e2 * rhs->e1125 
             + lhs->e1125 * rhs->e2 + lhs->e5 * rhs->e1122 + lhs->e1122 * rhs->e5 
             + lhs->e11 * rhs->e225 + lhs->e225 * rhs->e11 + lhs->e12 * rhs->e125 
             + lhs->e125 * rhs->e12 + lhs->e22 * rhs->e115 + lhs->e115 * rhs->e22 
             + lhs->e15 * rhs->e122 + lhs->e122 * rhs->e15 + lhs->e25 * rhs->e112 
             + lhs->e112 * rhs->e25;
  res.e12225 =  + lhs->e1 * rhs->e2225 + lhs->e2225 * rhs->e1 + lhs->e2 * rhs->e1225 
             + lhs->e1225 * rhs->e2 + lhs->e5 * rhs->e1222 + lhs->e1222 * rhs->e5 
             + lhs->e12 * rhs->e225 + lhs->e225 * rhs->e12 + lhs->e22 * rhs->e125 
             + lhs->e125 * rhs->e22 + lhs->e15 * rhs->e222 + lhs->e222 * rhs->e15 
             + lhs->e25 * rhs->e122 + lhs->e122 * rhs->e25;
  res.e22225 =  + lhs->e2 * rhs->e2225 + lhs->e2225 * rhs->e2 + lhs->e5 * rhs->e2222 
             + lhs->e2222 * rhs->e5 + lhs->e22 * rhs->e225 + lhs->e225 * rhs->e22 
             + lhs->e25 * rhs->e222 + lhs->e222 * rhs->e25;
  res.e11135 =  + lhs->e1 * rhs->e1135 + lhs->e1135 * rhs->e1 + lhs->e3 * rhs->e1115 
             + lhs->e1115 * rhs->e3 + lhs->e5 * rhs->e1113 + lhs->e1113 * rhs->e5 
             + lhs->e11 * rhs->e135 + lhs->e135 * rhs->e11 + lhs->e13 * rhs->e115 
             + lhs->e115 * rhs->e13 + lhs->e15 * rhs->e113 + lhs->e113 * rhs->e15 
             + lhs->e35 * rhs->e111 + lhs->e111 * rhs->e35;
  res.e11235 =  + lhs->e1 * rhs->e1235 + lhs->e1235 * rhs->e1 + lhs->e2 * rhs->e1135 
             + lhs->e1135 * rhs->e2 + lhs->e3 * rhs->e1125 + lhs->e1125 * rhs->e3 
             + lhs->e5 * rhs->e1123 + lhs->e1123 * rhs->e5 + lhs->e11 * rhs->e235 
             + lhs->e235 * rhs->e11 + lhs->e12 * rhs->e135 + lhs->e135 * rhs->e12 
             + lhs->e13 * rhs->e125 + lhs->e125 * rhs->e13 + lhs->e23 * rhs->e115 
             + lhs->e115 * rhs->e23 + lhs->e15 * rhs->e123 + lhs->e123 * rhs->e15 
             + lhs->e25 * rhs->e113 + lhs->e113 * rhs->e25 + lhs->e35 * rhs->e112 
             + lhs->e112 * rhs->e35;
  res.e12235 =  + lhs->e1 * rhs->e2235 + lhs->e2235 * rhs->e1 + lhs->e2 * rhs->e1235 
             + lhs->e1235 * rhs->e2 + lhs->e3 * rhs->e1225 + lhs->e1225 * rhs->e3 
             + lhs->e5 * rhs->e1223 + lhs->e1223 * rhs->e5 + lhs->e12 * rhs->e235 
             + lhs->e235 * rhs->e12 + lhs->e22 * rhs->e135 + lhs->e135 * rhs->e22 
             + lhs->e13 * rhs->e225 + lhs->e225 * rhs->e13 + lhs->e23 * rhs->e125 
             + lhs->e125 * rhs->e23 + lhs->e15 * rhs->e223 + lhs->e223 * rhs->e15 
             + lhs->e25 * rhs->e123 + lhs->e123 * rhs->e25 + lhs->e35 * rhs->e122 
             + lhs->e122 * rhs->e35;
  res.e22235 =  + lhs->e2 * rhs->e2235 + lhs->e2235 * rhs->e2 + lhs->e3 * rhs->e2225 
             + lhs->e2225 * rhs->e3 + lhs->e5 * rhs->e2223 + lhs->e2223 * rhs->e5 
             + lhs->e22 * rhs->e235 + lhs->e235 * rhs->e22 + lhs->e23 * rhs->e225 
             + lhs->e225 * rhs->e23 + lhs->e25 * rhs->e223 + lhs->e223 * rhs->e25 
             + lhs->e35 * rhs->e222 + lhs->e222 * rhs->e35;
  res.e11335 =  + lhs->e1 * rhs->e1335 + lhs->e1335 * rhs->e1 + lhs->e3 * rhs->e1135 
             + lhs->e1135 * rhs->e3 + lhs->e5 * rhs->e1133 + lhs->e1133 * rhs->e5 
             + lhs->e11 * rhs->e335 + lhs->e335 * rhs->e11 + lhs->e13 * rhs->e135 
             + lhs->e135 * rhs->e13 + lhs->e33 * rhs->e115 + lhs->e115 * rhs->e33 
             + lhs->e15 * rhs->e133 + lhs->e133 * rhs->e15 + lhs->e35 * rhs->e113 
             + lhs->e113 * rhs->e35;
  res.e12335 =  + lhs->e1 * rhs->e2335 + lhs->e2335 * rhs->e1 + lhs->e2 * rhs->e1335 
             + lhs->e1335 * rhs->e2 + lhs->e3 * rhs->e1235 + lhs->e1235 * rhs->e3 
             + lhs->e5 * rhs->e1233 + lhs->e1233 * rhs->e5 + lhs->e12 * rhs->e335 
             + lhs->e335 * rhs->e12 + lhs->e13 * rhs->e235 + lhs->e235 * rhs->e13 
             + lhs->e23 * rhs->e135 + lhs->e135 * rhs->e23 + lhs->e33 * rhs->e125 
             + lhs->e125 * rhs->e33 + lhs->e15 * rhs->e233 + lhs->e233 * rhs->e15 
             + lhs->e25 * rhs->e133 + lhs->e133 * rhs->e25 + lhs->e35 * rhs->e123 
             + lhs->e123 * rhs->e35;
  res.e22335 =  + lhs->e2 * rhs->e2335 + lhs->e2335 * rhs->e2 + lhs->e3 * rhs->e2235 
             + lhs->e2235 * rhs->e3 + lhs->e5 * rhs->e2233 + lhs->e2233 * rhs->e5 
             + lhs->e22 * rhs->e335 + lhs->e335 * rhs->e22 + lhs->e23 * rhs->e235 
             + lhs->e235 * rhs->e23 + lhs->e33 * rhs->e225 + lhs->e225 * rhs->e33 
             + lhs->e25 * rhs->e233 + lhs->e233 * rhs->e25 + lhs->e35 * rhs->e223 
             + lhs->e223 * rhs->e35;
  res.e13335 =  + lhs->e1 * rhs->e3335 + lhs->e3335 * rhs->e1 + lhs->e3 * rhs->e1335 
             + lhs->e1335 * rhs->e3 + lhs->e5 * rhs->e1333 + lhs->e1333 * rhs->e5 
             + lhs->e13 * rhs->e335 + lhs->e335 * rhs->e13 + lhs->e33 * rhs->e135 
             + lhs->e135 * rhs->e33 + lhs->e15 * rhs->e333 + lhs->e333 * rhs->e15 
             + lhs->e35 * rhs->e133 + lhs->e133 * rhs->e35;
  res.e23335 =  + lhs->e2 * rhs->e3335 + lhs->e3335 * rhs->e2 + lhs->e3 * rhs->e2335 
             + lhs->e2335 * rhs->e3 + lhs->e5 * rhs->e2333 + lhs->e2333 * rhs->e5 
             + lhs->e23 * rhs->e335 + lhs->e335 * rhs->e23 + lhs->e33 * rhs->e235 
             + lhs->e235 * rhs->e33 + lhs->e25 * rhs->e333 + lhs->e333 * rhs->e25 
             + lhs->e35 * rhs->e233 + lhs->e233 * rhs->e35;
  res.e33335 =  + lhs->e3 * rhs->e3335 + lhs->e3335 * rhs->e3 + lhs->e5 * rhs->e3333 
             + lhs->e3333 * rhs->e5 + lhs->e33 * rhs->e335 + lhs->e335 * rhs->e33 
             + lhs->e35 * rhs->e333 + lhs->e333 * rhs->e35;
  res.e11145 =  + lhs->e1 * rhs->e1145 + lhs->e1145 * rhs->e1 + lhs->e4 * rhs->e1115 
             + lhs->e1115 * rhs->e4 + lhs->e5 * rhs->e1114 + lhs->e1114 * rhs->e5 
             + lhs->e11 * rhs->e145 + lhs->e145 * rhs->e11 + lhs->e14 * rhs->e115 
             + lhs->e115 * rhs->e14 + lhs->e15 * rhs->e114 + lhs->e114 * rhs->e15 
             + lhs->e45 * rhs->e111 + lhs->e111 * rhs->e45;
  res.e11245 =  + lhs->e1 * rhs->e1245 + lhs->e1245 * rhs->e1 + lhs->e2 * rhs->e1145 
             + lhs->e1145 * rhs->e2 + lhs->e4 * rhs->e1125 + lhs->e1125 * rhs->e4 
             + lhs->e5 * rhs->e1124 + lhs->e1124 * rhs->e5 + lhs->e11 * rhs->e245 
             + lhs->e245 * rhs->e11 + lhs->e12 * rhs->e145 + lhs->e145 * rhs->e12 
             + lhs->e14 * rhs->e125 + lhs->e125 * rhs->e14 + lhs->e24 * rhs->e115 
             + lhs->e115 * rhs->e24 + lhs->e15 * rhs->e124 + lhs->e124 * rhs->e15 
             + lhs->e25 * rhs->e114 + lhs->e114 * rhs->e25 + lhs->e45 * rhs->e112 
             + lhs->e112 * rhs->e45;
  res.e12245 =  + lhs->e1 * rhs->e2245 + lhs->e2245 * rhs->e1 + lhs->e2 * rhs->e1245 
             + lhs->e1245 * rhs->e2 + lhs->e4 * rhs->e1225 + lhs->e1225 * rhs->e4 
             + lhs->e5 * rhs->e1224 + lhs->e1224 * rhs->e5 + lhs->e12 * rhs->e245 
             + lhs->e245 * rhs->e12 + lhs->e22 * rhs->e145 + lhs->e145 * rhs->e22 
             + lhs->e14 * rhs->e225 + lhs->e225 * rhs->e14 + lhs->e24 * rhs->e125 
             + lhs->e125 * rhs->e24 + lhs->e15 * rhs->e224 + lhs->e224 * rhs->e15 
             + lhs->e25 * rhs->e124 + lhs->e124 * rhs->e25 + lhs->e45 * rhs->e122 
             + lhs->e122 * rhs->e45;
  res.e22245 =  + lhs->e2 * rhs->e2245 + lhs->e2245 * rhs->e2 + lhs->e4 * rhs->e2225 
             + lhs->e2225 * rhs->e4 + lhs->e5 * rhs->e2224 + lhs->e2224 * rhs->e5 
             + lhs->e22 * rhs->e245 + lhs->e245 * rhs->e22 + lhs->e24 * rhs->e225 
             + lhs->e225 * rhs->e24 + lhs->e25 * rhs->e224 + lhs->e224 * rhs->e25 
             + lhs->e45 * rhs->e222 + lhs->e222 * rhs->e45;
  res.e11345 =  + lhs->e1 * rhs->e1345 + lhs->e1345 * rhs->e1 + lhs->e3 * rhs->e1145 
             + lhs->e1145 * rhs->e3 + lhs->e4 * rhs->e1135 + lhs->e1135 * rhs->e4 
             + lhs->e5 * rhs->e1134 + lhs->e1134 * rhs->e5 + lhs->e11 * rhs->e345 
             + lhs->e345 * rhs->e11 + lhs->e13 * rhs->e145 + lhs->e145 * rhs->e13 
             + lhs->e14 * rhs->e135 + lhs->e135 * rhs->e14 + lhs->e34 * rhs->e115 
             + lhs->e115 * rhs->e34 + lhs->e15 * rhs->e134 + lhs->e134 * rhs->e15 
             + lhs->e35 * rhs->e114 + lhs->e114 * rhs->e35 + lhs->e45 * rhs->e113 
             + lhs->e113 * rhs->e45;
  res.e12345 =  + lhs->e1 * rhs->e2345 + lhs->e2345 * rhs->e1 + lhs->e2 * rhs->e1345 
             + lhs->e1345 * rhs->e2 + lhs->e3 * rhs->e1245 + lhs->e1245 * rhs->e3 
             + lhs->e4 * rhs->e1235 + lhs->e1235 * rhs->e4 + lhs->e5 * rhs->e1234 
             + lhs->e1234 * rhs->e5 + lhs->e12 * rhs->e345 + lhs->e345 * rhs->e12 
             + lhs->e13 * rhs->e245 + lhs->e245 * rhs->e13 + lhs->e23 * rhs->e145 
             + lhs->e145 * rhs->e23 + lhs->e14 * rhs->e235 + lhs->e235 * rhs->e14 
             + lhs->e24 * rhs->e135 + lhs->e135 * rhs->e24 + lhs->e34 * rhs->e125 
             + lhs->e125 * rhs->e34 + lhs->e15 * rhs->e234 + lhs->e234 * rhs->e15 
             + lhs->e25 * rhs->e134 + lhs->e134 * rhs->e25 + lhs->e35 * rhs->e124 
             + lhs->e124 * rhs->e35 + lhs->e45 * rhs->e123 + lhs->e123 * rhs->e45;
  res.e22345 =  + lhs->e2 * rhs->e2345 + lhs->e2345 * rhs->e2 + lhs->e3 * rhs->e2245 
             + lhs->e2245 * rhs->e3 + lhs->e4 * rhs->e2235 + lhs->e2235 * rhs->e4 
             + lhs->e5 * rhs->e2234 + lhs->e2234 * rhs->e5 + lhs->e22 * rhs->e345 
             + lhs->e345 * rhs->e22 + lhs->e23 * rhs->e245 + lhs->e245 * rhs->e23 
             + lhs->e24 * rhs->e235 + lhs->e235 * rhs->e24 + lhs->e34 * rhs->e225 
             + lhs->e225 * rhs->e34 + lhs->e25 * rhs->e234 + lhs->e234 * rhs->e25 
             + lhs->e35 * rhs->e224 + lhs->e224 * rhs->e35 + lhs->e45 * rhs->e223 
             + lhs->e223 * rhs->e45;
  res.e13345 =  + lhs->e1 * rhs->e3345 + lhs->e3345 * rhs->e1 + lhs->e3 * rhs->e1345 
             + lhs->e1345 * rhs->e3 + lhs->e4 * rhs->e1335 + lhs->e1335 * rhs->e4 
             + lhs->e5 * rhs->e1334 + lhs->e1334 * rhs->e5 + lhs->e13 * rhs->e345 
             + lhs->e345 * rhs->e13 + lhs->e33 * rhs->e145 + lhs->e145 * rhs->e33 
             + lhs->e14 * rhs->e335 + lhs->e335 * rhs->e14 + lhs->e34 * rhs->e135 
             + lhs->e135 * rhs->e34 + lhs->e15 * rhs->e334 + lhs->e334 * rhs->e15 
             + lhs->e35 * rhs->e134 + lhs->e134 * rhs->e35 + lhs->e45 * rhs->e133 
             + lhs->e133 * rhs->e45;
  res.e23345 =  + lhs->e2 * rhs->e3345 + lhs->e3345 * rhs->e2 + lhs->e3 * rhs->e2345 
             + lhs->e2345 * rhs->e3 + lhs->e4 * rhs->e2335 + lhs->e2335 * rhs->e4 
             + lhs->e5 * rhs->e2334 + lhs->e2334 * rhs->e5 + lhs->e23 * rhs->e345 
             + lhs->e345 * rhs->e23 + lhs->e33 * rhs->e245 + lhs->e245 * rhs->e33 
             + lhs->e24 * rhs->e335 + lhs->e335 * rhs->e24 + lhs->e34 * rhs->e235 
             + lhs->e235 * rhs->e34 + lhs->e25 * rhs->e334 + lhs->e334 * rhs->e25 
             + lhs->e35 * rhs->e234 + lhs->e234 * rhs->e35 + lhs->e45 * rhs->e233 
             + lhs->e233 * rhs->e45;
  res.e33345 =  + lhs->e3 * rhs->e3345 + lhs->e3345 * rhs->e3 + lhs->e4 * rhs->e3335 
             + lhs->e3335 * rhs->e4 + lhs->e5 * rhs->e3334 + lhs->e3334 * rhs->e5 
             + lhs->e33 * rhs->e345 + lhs->e345 * rhs->e33 + lhs->e34 * rhs->e335 
             + lhs->e335 * rhs->e34 + lhs->e35 * rhs->e334 + lhs->e334 * rhs->e35 
             + lhs->e45 * rhs->e333 + lhs->e333 * rhs->e45;
  res.e11445 =  + lhs->e1 * rhs->e1445 + lhs->e1445 * rhs->e1 + lhs->e4 * rhs->e1145 
             + lhs->e1145 * rhs->e4 + lhs->e5 * rhs->e1144 + lhs->e1144 * rhs->e5 
             + lhs->e11 * rhs->e445 + lhs->e445 * rhs->e11 + lhs->e14 * rhs->e145 
             + lhs->e145 * rhs->e14 + lhs->e44 * rhs->e115 + lhs->e115 * rhs->e44 
             + lhs->e15 * rhs->e144 + lhs->e144 * rhs->e15 + lhs->e45 * rhs->e114 
             + lhs->e114 * rhs->e45;
  res.e12445 =  + lhs->e1 * rhs->e2445 + lhs->e2445 * rhs->e1 + lhs->e2 * rhs->e1445 
             + lhs->e1445 * rhs->e2 + lhs->e4 * rhs->e1245 + lhs->e1245 * rhs->e4 
             + lhs->e5 * rhs->e1244 + lhs->e1244 * rhs->e5 + lhs->e12 * rhs->e445 
             + lhs->e445 * rhs->e12 + lhs->e14 * rhs->e245 + lhs->e245 * rhs->e14 
             + lhs->e24 * rhs->e145 + lhs->e145 * rhs->e24 + lhs->e44 * rhs->e125 
             + lhs->e125 * rhs->e44 + lhs->e15 * rhs->e244 + lhs->e244 * rhs->e15 
             + lhs->e25 * rhs->e144 + lhs->e144 * rhs->e25 + lhs->e45 * rhs->e124 
             + lhs->e124 * rhs->e45;
  res.e22445 =  + lhs->e2 * rhs->e2445 + lhs->e2445 * rhs->e2 + lhs->e4 * rhs->e2245 
             + lhs->e2245 * rhs->e4 + lhs->e5 * rhs->e2244 + lhs->e2244 * rhs->e5 
             + lhs->e22 * rhs->e445 + lhs->e445 * rhs->e22 + lhs->e24 * rhs->e245 
             + lhs->e245 * rhs->e24 + lhs->e44 * rhs->e225 + lhs->e225 * rhs->e44 
             + lhs->e25 * rhs->e244 + lhs->e244 * rhs->e25 + lhs->e45 * rhs->e224 
             + lhs->e224 * rhs->e45;
  res.e13445 =  + lhs->e1 * rhs->e3445 + lhs->e3445 * rhs->e1 + lhs->e3 * rhs->e1445 
             + lhs->e1445 * rhs->e3 + lhs->e4 * rhs->e1345 + lhs->e1345 * rhs->e4 
             + lhs->e5 * rhs->e1344 + lhs->e1344 * rhs->e5 + lhs->e13 * rhs->e445 
             + lhs->e445 * rhs->e13 + lhs->e14 * rhs->e345 + lhs->e345 * rhs->e14 
             + lhs->e34 * rhs->e145 + lhs->e145 * rhs->e34 + lhs->e44 * rhs->e135 
             + lhs->e135 * rhs->e44 + lhs->e15 * rhs->e344 + lhs->e344 * rhs->e15 
             + lhs->e35 * rhs->e144 + lhs->e144 * rhs->e35 + lhs->e45 * rhs->e134 
             + lhs->e134 * rhs->e45;
  res.e23445 =  + lhs->e2 * rhs->e3445 + lhs->e3445 * rhs->e2 + lhs->e3 * rhs->e2445 
             + lhs->e2445 * rhs->e3 + lhs->e4 * rhs->e2345 + lhs->e2345 * rhs->e4 
             + lhs->e5 * rhs->e2344 + lhs->e2344 * rhs->e5 + lhs->e23 * rhs->e445 
             + lhs->e445 * rhs->e23 + lhs->e24 * rhs->e345 + lhs->e345 * rhs->e24 
             + lhs->e34 * rhs->e245 + lhs->e245 * rhs->e34 + lhs->e44 * rhs->e235 
             + lhs->e235 * rhs->e44 + lhs->e25 * rhs->e344 + lhs->e344 * rhs->e25 
             + lhs->e35 * rhs->e244 + lhs->e244 * rhs->e35 + lhs->e45 * rhs->e234 
             + lhs->e234 * rhs->e45;
  res.e33445 =  + lhs->e3 * rhs->e3445 + lhs->e3445 * rhs->e3 + lhs->e4 * rhs->e3345 
             + lhs->e3345 * rhs->e4 + lhs->e5 * rhs->e3344 + lhs->e3344 * rhs->e5 
             + lhs->e33 * rhs->e445 + lhs->e445 * rhs->e33 + lhs->e34 * rhs->e345 
             + lhs->e345 * rhs->e34 + lhs->e44 * rhs->e335 + lhs->e335 * rhs->e44 
             + lhs->e35 * rhs->e344 + lhs->e344 * rhs->e35 + lhs->e45 * rhs->e334 
             + lhs->e334 * rhs->e45;
  res.e14445 =  + lhs->e1 * rhs->e4445 + lhs->e4445 * rhs->e1 + lhs->e4 * rhs->e1445 
             + lhs->e1445 * rhs->e4 + lhs->e5 * rhs->e1444 + lhs->e1444 * rhs->e5 
             + lhs->e14 * rhs->e445 + lhs->e445 * rhs->e14 + lhs->e44 * rhs->e145 
             + lhs->e145 * rhs->e44 + lhs->e15 * rhs->e444 + lhs->e444 * rhs->e15 
             + lhs->e45 * rhs->e144 + lhs->e144 * rhs->e45;
  res.e24445 =  + lhs->e2 * rhs->e4445 + lhs->e4445 * rhs->e2 + lhs->e4 * rhs->e2445 
             + lhs->e2445 * rhs->e4 + lhs->e5 * rhs->e2444 + lhs->e2444 * rhs->e5 
             + lhs->e24 * rhs->e445 + lhs->e445 * rhs->e24 + lhs->e44 * rhs->e245 
             + lhs->e245 * rhs->e44 + lhs->e25 * rhs->e444 + lhs->e444 * rhs->e25 
             + lhs->e45 * rhs->e244 + lhs->e244 * rhs->e45;
  res.e34445 =  + lhs->e3 * rhs->e4445 + lhs->e4445 * rhs->e3 + lhs->e4 * rhs->e3445 
             + lhs->e3445 * rhs->e4 + lhs->e5 * rhs->e3444 + lhs->e3444 * rhs->e5 
             + lhs->e34 * rhs->e445 + lhs->e445 * rhs->e34 + lhs->e44 * rhs->e345 
             + lhs->e345 * rhs->e44 + lhs->e35 * rhs->e444 + lhs->e444 * rhs->e35 
             + lhs->e45 * rhs->e344 + lhs->e344 * rhs->e45;
  res.e44445 =  + lhs->e4 * rhs->e4445 + lhs->e4445 * rhs->e4 + lhs->e5 * rhs->e4444 
             + lhs->e4444 * rhs->e5 + lhs->e44 * rhs->e445 + lhs->e445 * rhs->e44 
             + lhs->e45 * rhs->e444 + lhs->e444 * rhs->e45;
  res.e11155 =  + lhs->e1 * rhs->e1155 + lhs->e1155 * rhs->e1 + lhs->e5 * rhs->e1115 
             + lhs->e1115 * rhs->e5 + lhs->e11 * rhs->e155 + lhs->e155 * rhs->e11 
             + lhs->e15 * rhs->e115 + lhs->e115 * rhs->e15 + lhs->e55 * rhs->e111 
             + lhs->e111 * rhs->e55;
  res.e11255 =  + lhs->e1 * rhs->e1255 + lhs->e1255 * rhs->e1 + lhs->e2 * rhs->e1155 
             + lhs->e1155 * rhs->e2 + lhs->e5 * rhs->e1125 + lhs->e1125 * rhs->e5 
             + lhs->e11 * rhs->e255 + lhs->e255 * rhs->e11 + lhs->e12 * rhs->e155 
             + lhs->e155 * rhs->e12 + lhs->e15 * rhs->e125 + lhs->e125 * rhs->e15 
             + lhs->e25 * rhs->e115 + lhs->e115 * rhs->e25 + lhs->e55 * rhs->e112 
             + lhs->e112 * rhs->e55;
  res.e12255 =  + lhs->e1 * rhs->e2255 + lhs->e2255 * rhs->e1 + lhs->e2 * rhs->e1255 
             + lhs->e1255 * rhs->e2 + lhs->e5 * rhs->e1225 + lhs->e1225 * rhs->e5 
             + lhs->e12 * rhs->e255 + lhs->e255 * rhs->e12 + lhs->e22 * rhs->e155 
             + lhs->e155 * rhs->e22 + lhs->e15 * rhs->e225 + lhs->e225 * rhs->e15 
             + lhs->e25 * rhs->e125 + lhs->e125 * rhs->e25 + lhs->e55 * rhs->e122 
             + lhs->e122 * rhs->e55;
  res.e22255 =  + lhs->e2 * rhs->e2255 + lhs->e2255 * rhs->e2 + lhs->e5 * rhs->e2225 
             + lhs->e2225 * rhs->e5 + lhs->e22 * rhs->e255 + lhs->e255 * rhs->e22 
             + lhs->e25 * rhs->e225 + lhs->e225 * rhs->e25 + lhs->e55 * rhs->e222 
             + lhs->e222 * rhs->e55;
  res.e11355 =  + lhs->e1 * rhs->e1355 + lhs->e1355 * rhs->e1 + lhs->e3 * rhs->e1155 
             + lhs->e1155 * rhs->e3 + lhs->e5 * rhs->e1135 + lhs->e1135 * rhs->e5 
             + lhs->e11 * rhs->e355 + lhs->e355 * rhs->e11 + lhs->e13 * rhs->e155 
             + lhs->e155 * rhs->e13 + lhs->e15 * rhs->e135 + lhs->e135 * rhs->e15 
             + lhs->e35 * rhs->e115 + lhs->e115 * rhs->e35 + lhs->e55 * rhs->e113 
             + lhs->e113 * rhs->e55;
  res.e12355 =  + lhs->e1 * rhs->e2355 + lhs->e2355 * rhs->e1 + lhs->e2 * rhs->e1355 
             + lhs->e1355 * rhs->e2 + lhs->e3 * rhs->e1255 + lhs->e1255 * rhs->e3 
             + lhs->e5 * rhs->e1235 + lhs->e1235 * rhs->e5 + lhs->e12 * rhs->e355 
             + lhs->e355 * rhs->e12 + lhs->e13 * rhs->e255 + lhs->e255 * rhs->e13 
             + lhs->e23 * rhs->e155 + lhs->e155 * rhs->e23 + lhs->e15 * rhs->e235 
             + lhs->e235 * rhs->e15 + lhs->e25 * rhs->e135 + lhs->e135 * rhs->e25 
             + lhs->e35 * rhs->e125 + lhs->e125 * rhs->e35 + lhs->e55 * rhs->e123 
             + lhs->e123 * rhs->e55;
  res.e22355 =  + lhs->e2 * rhs->e2355 + lhs->e2355 * rhs->e2 + lhs->e3 * rhs->e2255 
             + lhs->e2255 * rhs->e3 + lhs->e5 * rhs->e2235 + lhs->e2235 * rhs->e5 
             + lhs->e22 * rhs->e355 + lhs->e355 * rhs->e22 + lhs->e23 * rhs->e255 
             + lhs->e255 * rhs->e23 + lhs->e25 * rhs->e235 + lhs->e235 * rhs->e25 
             + lhs->e35 * rhs->e225 + lhs->e225 * rhs->e35 + lhs->e55 * rhs->e223 
             + lhs->e223 * rhs->e55;
  res.e13355 =  + lhs->e1 * rhs->e3355 + lhs->e3355 * rhs->e1 + lhs->e3 * rhs->e1355 
             + lhs->e1355 * rhs->e3 + lhs->e5 * rhs->e1335 + lhs->e1335 * rhs->e5 
             + lhs->e13 * rhs->e355 + lhs->e355 * rhs->e13 + lhs->e33 * rhs->e155 
             + lhs->e155 * rhs->e33 + lhs->e15 * rhs->e335 + lhs->e335 * rhs->e15 
             + lhs->e35 * rhs->e135 + lhs->e135 * rhs->e35 + lhs->e55 * rhs->e133 
             + lhs->e133 * rhs->e55;
  res.e23355 =  + lhs->e2 * rhs->e3355 + lhs->e3355 * rhs->e2 + lhs->e3 * rhs->e2355 
             + lhs->e2355 * rhs->e3 + lhs->e5 * rhs->e2335 + lhs->e2335 * rhs->e5 
             + lhs->e23 * rhs->e355 + lhs->e355 * rhs->e23 + lhs->e33 * rhs->e255 
             + lhs->e255 * rhs->e33 + lhs->e25 * rhs->e335 + lhs->e335 * rhs->e25 
             + lhs->e35 * rhs->e235 + lhs->e235 * rhs->e35 + lhs->e55 * rhs->e233 
             + lhs->e233 * rhs->e55;
  res.e33355 =  + lhs->e3 * rhs->e3355 + lhs->e3355 * rhs->e3 + lhs->e5 * rhs->e3335 
             + lhs->e3335 * rhs->e5 + lhs->e33 * rhs->e355 + lhs->e355 * rhs->e33 
             + lhs->e35 * rhs->e335 + lhs->e335 * rhs->e35 + lhs->e55 * rhs->e333 
             + lhs->e333 * rhs->e55;
  res.e11455 =  + lhs->e1 * rhs->e1455 + lhs->e1455 * rhs->e1 + lhs->e4 * rhs->e1155 
             + lhs->e1155 * rhs->e4 + lhs->e5 * rhs->e1145 + lhs->e1145 * rhs->e5 
             + lhs->e11 * rhs->e455 + lhs->e455 * rhs->e11 + lhs->e14 * rhs->e155 
             + lhs->e155 * rhs->e14 + lhs->e15 * rhs->e145 + lhs->e145 * rhs->e15 
             + lhs->e45 * rhs->e115 + lhs->e115 * rhs->e45 + lhs->e55 * rhs->e114 
             + lhs->e114 * rhs->e55;
  res.e12455 =  + lhs->e1 * rhs->e2455 + lhs->e2455 * rhs->e1 + lhs->e2 * rhs->e1455 
             + lhs->e1455 * rhs->e2 + lhs->e4 * rhs->e1255 + lhs->e1255 * rhs->e4 
             + lhs->e5 * rhs->e1245 + lhs->e1245 * rhs->e5 + lhs->e12 * rhs->e455 
             + lhs->e455 * rhs->e12 + lhs->e14 * rhs->e255 + lhs->e255 * rhs->e14 
             + lhs->e24 * rhs->e155 + lhs->e155 * rhs->e24 + lhs->e15 * rhs->e245 
             + lhs->e245 * rhs->e15 + lhs->e25 * rhs->e145 + lhs->e145 * rhs->e25 
             + lhs->e45 * rhs->e125 + lhs->e125 * rhs->e45 + lhs->e55 * rhs->e124 
             + lhs->e124 * rhs->e55;
  res.e22455 =  + lhs->e2 * rhs->e2455 + lhs->e2455 * rhs->e2 + lhs->e4 * rhs->e2255 
             + lhs->e2255 * rhs->e4 + lhs->e5 * rhs->e2245 + lhs->e2245 * rhs->e5 
             + lhs->e22 * rhs->e455 + lhs->e455 * rhs->e22 + lhs->e24 * rhs->e255 
             + lhs->e255 * rhs->e24 + lhs->e25 * rhs->e245 + lhs->e245 * rhs->e25 
             + lhs->e45 * rhs->e225 + lhs->e225 * rhs->e45 + lhs->e55 * rhs->e224 
             + lhs->e224 * rhs->e55;
  res.e13455 =  + lhs->e1 * rhs->e3455 + lhs->e3455 * rhs->e1 + lhs->e3 * rhs->e1455 
             + lhs->e1455 * rhs->e3 + lhs->e4 * rhs->e1355 + lhs->e1355 * rhs->e4 
             + lhs->e5 * rhs->e1345 + lhs->e1345 * rhs->e5 + lhs->e13 * rhs->e455 
             + lhs->e455 * rhs->e13 + lhs->e14 * rhs->e355 + lhs->e355 * rhs->e14 
             + lhs->e34 * rhs->e155 + lhs->e155 * rhs->e34 + lhs->e15 * rhs->e345 
             + lhs->e345 * rhs->e15 + lhs->e35 * rhs->e145 + lhs->e145 * rhs->e35 
             + lhs->e45 * rhs->e135 + lhs->e135 * rhs->e45 + lhs->e55 * rhs->e134 
             + lhs->e134 * rhs->e55;
  res.e23455 =  + lhs->e2 * rhs->e3455 + lhs->e3455 * rhs->e2 + lhs->e3 * rhs->e2455 
             + lhs->e2455 * rhs->e3 + lhs->e4 * rhs->e2355 + lhs->e2355 * rhs->e4 
             + lhs->e5 * rhs->e2345 + lhs->e2345 * rhs->e5 + lhs->e23 * rhs->e455 
             + lhs->e455 * rhs->e23 + lhs->e24 * rhs->e355 + lhs->e355 * rhs->e24 
             + lhs->e34 * rhs->e255 + lhs->e255 * rhs->e34 + lhs->e25 * rhs->e345 
             + lhs->e345 * rhs->e25 + lhs->e35 * rhs->e245 + lhs->e245 * rhs->e35 
             + lhs->e45 * rhs->e235 + lhs->e235 * rhs->e45 + lhs->e55 * rhs->e234 
             + lhs->e234 * rhs->e55;
  res.e33455 =  + lhs->e3 * rhs->e3455 + lhs->e3455 * rhs->e3 + lhs->e4 * rhs->e3355 
             + lhs->e3355 * rhs->e4 + lhs->e5 * rhs->e3345 + lhs->e3345 * rhs->e5 
             + lhs->e33 * rhs->e455 + lhs->e455 * rhs->e33 + lhs->e34 * rhs->e355 
             + lhs->e355 * rhs->e34 + lhs->e35 * rhs->e345 + lhs->e345 * rhs->e35 
             + lhs->e45 * rhs->e335 + lhs->e335 * rhs->e45 + lhs->e55 * rhs->e334 
             + lhs->e334 * rhs->e55;
  res.e14455 =  + lhs->e1 * rhs->e4455 + lhs->e4455 * rhs->e1 + lhs->e4 * rhs->e1455 
             + lhs->e1455 * rhs->e4 + lhs->e5 * rhs->e1445 + lhs->e1445 * rhs->e5 
             + lhs->e14 * rhs->e455 + lhs->e455 * rhs->e14 + lhs->e44 * rhs->e155 
             + lhs->e155 * rhs->e44 + lhs->e15 * rhs->e445 + lhs->e445 * rhs->e15 
             + lhs->e45 * rhs->e145 + lhs->e145 * rhs->e45 + lhs->e55 * rhs->e144 
             + lhs->e144 * rhs->e55;
  res.e24455 =  + lhs->e2 * rhs->e4455 + lhs->e4455 * rhs->e2 + lhs->e4 * rhs->e2455 
             + lhs->e2455 * rhs->e4 + lhs->e5 * rhs->e2445 + lhs->e2445 * rhs->e5 
             + lhs->e24 * rhs->e455 + lhs->e455 * rhs->e24 + lhs->e44 * rhs->e255 
             + lhs->e255 * rhs->e44 + lhs->e25 * rhs->e445 + lhs->e445 * rhs->e25 
             + lhs->e45 * rhs->e245 + lhs->e245 * rhs->e45 + lhs->e55 * rhs->e244 
             + lhs->e244 * rhs->e55;
  res.e34455 =  + lhs->e3 * rhs->e4455 + lhs->e4455 * rhs->e3 + lhs->e4 * rhs->e3455 
             + lhs->e3455 * rhs->e4 + lhs->e5 * rhs->e3445 + lhs->e3445 * rhs->e5 
             + lhs->e34 * rhs->e455 + lhs->e455 * rhs->e34 + lhs->e44 * rhs->e355 
             + lhs->e355 * rhs->e44 + lhs->e35 * rhs->e445 + lhs->e445 * rhs->e35 
             + lhs->e45 * rhs->e345 + lhs->e345 * rhs->e45 + lhs->e55 * rhs->e344 
             + lhs->e344 * rhs->e55;
  res.e44455 =  + lhs->e4 * rhs->e4455 + lhs->e4455 * rhs->e4 + lhs->e5 * rhs->e4445 
             + lhs->e4445 * rhs->e5 + lhs->e44 * rhs->e455 + lhs->e455 * rhs->e44 
             + lhs->e45 * rhs->e445 + lhs->e445 * rhs->e45 + lhs->e55 * rhs->e444 
             + lhs->e444 * rhs->e55;
  res.e11555 =  + lhs->e1 * rhs->e1555 + lhs->e1555 * rhs->e1 + lhs->e5 * rhs->e1155 
             + lhs->e1155 * rhs->e5 + lhs->e11 * rhs->e555 + lhs->e555 * rhs->e11 
             + lhs->e15 * rhs->e155 + lhs->e155 * rhs->e15 + lhs->e55 * rhs->e115 
             + lhs->e115 * rhs->e55;
  res.e12555 =  + lhs->e1 * rhs->e2555 + lhs->e2555 * rhs->e1 + lhs->e2 * rhs->e1555 
             + lhs->e1555 * rhs->e2 + lhs->e5 * rhs->e1255 + lhs->e1255 * rhs->e5 
             + lhs->e12 * rhs->e555 + lhs->e555 * rhs->e12 + lhs->e15 * rhs->e255 
             + lhs->e255 * rhs->e15 + lhs->e25 * rhs->e155 + lhs->e155 * rhs->e25 
             + lhs->e55 * rhs->e125 + lhs->e125 * rhs->e55;
  res.e22555 =  + lhs->e2 * rhs->e2555 + lhs->e2555 * rhs->e2 + lhs->e5 * rhs->e2255 
             + lhs->e2255 * rhs->e5 + lhs->e22 * rhs->e555 + lhs->e555 * rhs->e22 
             + lhs->e25 * rhs->e255 + lhs->e255 * rhs->e25 + lhs->e55 * rhs->e225 
             + lhs->e225 * rhs->e55;
  res.e13555 =  + lhs->e1 * rhs->e3555 + lhs->e3555 * rhs->e1 + lhs->e3 * rhs->e1555 
             + lhs->e1555 * rhs->e3 + lhs->e5 * rhs->e1355 + lhs->e1355 * rhs->e5 
             + lhs->e13 * rhs->e555 + lhs->e555 * rhs->e13 + lhs->e15 * rhs->e355 
             + lhs->e355 * rhs->e15 + lhs->e35 * rhs->e155 + lhs->e155 * rhs->e35 
             + lhs->e55 * rhs->e135 + lhs->e135 * rhs->e55;
  res.e23555 =  + lhs->e2 * rhs->e3555 + lhs->e3555 * rhs->e2 + lhs->e3 * rhs->e2555 
             + lhs->e2555 * rhs->e3 + lhs->e5 * rhs->e2355 + lhs->e2355 * rhs->e5 
             + lhs->e23 * rhs->e555 + lhs->e555 * rhs->e23 + lhs->e25 * rhs->e355 
             + lhs->e355 * rhs->e25 + lhs->e35 * rhs->e255 + lhs->e255 * rhs->e35 
             + lhs->e55 * rhs->e235 + lhs->e235 * rhs->e55;
  res.e33555 =  + lhs->e3 * rhs->e3555 + lhs->e3555 * rhs->e3 + lhs->e5 * rhs->e3355 
             + lhs->e3355 * rhs->e5 + lhs->e33 * rhs->e555 + lhs->e555 * rhs->e33 
             + lhs->e35 * rhs->e355 + lhs->e355 * rhs->e35 + lhs->e55 * rhs->e335 
             + lhs->e335 * rhs->e55;
  res.e14555 =  + lhs->e1 * rhs->e4555 + lhs->e4555 * rhs->e1 + lhs->e4 * rhs->e1555 
             + lhs->e1555 * rhs->e4 + lhs->e5 * rhs->e1455 + lhs->e1455 * rhs->e5 
             + lhs->e14 * rhs->e555 + lhs->e555 * rhs->e14 + lhs->e15 * rhs->e455 
             + lhs->e455 * rhs->e15 + lhs->e45 * rhs->e155 + lhs->e155 * rhs->e45 
             + lhs->e55 * rhs->e145 + lhs->e145 * rhs->e55;
  res.e24555 =  + lhs->e2 * rhs->e4555 + lhs->e4555 * rhs->e2 + lhs->e4 * rhs->e2555 
             + lhs->e2555 * rhs->e4 + lhs->e5 * rhs->e2455 + lhs->e2455 * rhs->e5 
             + lhs->e24 * rhs->e555 + lhs->e555 * rhs->e24 + lhs->e25 * rhs->e455 
             + lhs->e455 * rhs->e25 + lhs->e45 * rhs->e255 + lhs->e255 * rhs->e45 
             + lhs->e55 * rhs->e245 + lhs->e245 * rhs->e55;
  res.e34555 =  + lhs->e3 * rhs->e4555 + lhs->e4555 * rhs->e3 + lhs->e4 * rhs->e3555 
             + lhs->e3555 * rhs->e4 + lhs->e5 * rhs->e3455 + lhs->e3455 * rhs->e5 
             + lhs->e34 * rhs->e555 + lhs->e555 * rhs->e34 + lhs->e35 * rhs->e455 
             + lhs->e455 * rhs->e35 + lhs->e45 * rhs->e355 + lhs->e355 * rhs->e45 
             + lhs->e55 * rhs->e345 + lhs->e345 * rhs->e55;
  res.e44555 =  + lhs->e4 * rhs->e4555 + lhs->e4555 * rhs->e4 + lhs->e5 * rhs->e4455 
             + lhs->e4455 * rhs->e5 + lhs->e44 * rhs->e555 + lhs->e555 * rhs->e44 
             + lhs->e45 * rhs->e455 + lhs->e455 * rhs->e45 + lhs->e55 * rhs->e445 
             + lhs->e445 * rhs->e55;
  res.e15555 =  + lhs->e1 * rhs->e5555 + lhs->e5555 * rhs->e1 + lhs->e5 * rhs->e1555 
             + lhs->e1555 * rhs->e5 + lhs->e15 * rhs->e555 + lhs->e555 * rhs->e15 
             + lhs->e55 * rhs->e155 + lhs->e155 * rhs->e55;
  res.e25555 =  + lhs->e2 * rhs->e5555 + lhs->e5555 * rhs->e2 + lhs->e5 * rhs->e2555 
             + lhs->e2555 * rhs->e5 + lhs->e25 * rhs->e555 + lhs->e555 * rhs->e25 
             + lhs->e55 * rhs->e255 + lhs->e255 * rhs->e55;
  res.e35555 =  + lhs->e3 * rhs->e5555 + lhs->e5555 * rhs->e3 + lhs->e5 * rhs->e3555 
             + lhs->e3555 * rhs->e5 + lhs->e35 * rhs->e555 + lhs->e555 * rhs->e35 
             + lhs->e55 * rhs->e355 + lhs->e355 * rhs->e55;
  res.e45555 =  + lhs->e4 * rhs->e5555 + lhs->e5555 * rhs->e4 + lhs->e5 * rhs->e4555 
             + lhs->e4555 * rhs->e5 + lhs->e45 * rhs->e555 + lhs->e555 * rhs->e45 
             + lhs->e55 * rhs->e455 + lhs->e455 * rhs->e55;
  res.e55555 =  + lhs->e5 * rhs->e5555 + lhs->e5555 * rhs->e5 + lhs->e55 * rhs->e555 
             + lhs->e555 * rhs->e55;

  return res;

}

void onumm5n5_trunc_mul_oo_to(  onumm5n5_t* lhs,  onumm5n5_t* rhs, onumm5n5_t* res){
   (*res) = onumm5n5_init();

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
  res->e1115 =  + lhs->e1 * rhs->e115 + lhs->e115 * rhs->e1 + lhs->e5 * rhs->e111 
            + lhs->e111 * rhs->e5 + lhs->e11 * rhs->e15 + lhs->e15 * rhs->e11;
  res->e1125 =  + lhs->e1 * rhs->e125 + lhs->e125 * rhs->e1 + lhs->e2 * rhs->e115 
            + lhs->e115 * rhs->e2 + lhs->e5 * rhs->e112 + lhs->e112 * rhs->e5 
            + lhs->e11 * rhs->e25 + lhs->e12 * rhs->e15 + lhs->e15 * rhs->e12 
            + lhs->e25 * rhs->e11;
  res->e1225 =  + lhs->e1 * rhs->e225 + lhs->e225 * rhs->e1 + lhs->e2 * rhs->e125 
            + lhs->e125 * rhs->e2 + lhs->e5 * rhs->e122 + lhs->e122 * rhs->e5 
            + lhs->e12 * rhs->e25 + lhs->e22 * rhs->e15 + lhs->e15 * rhs->e22 
            + lhs->e25 * rhs->e12;
  res->e2225 =  + lhs->e2 * rhs->e225 + lhs->e225 * rhs->e2 + lhs->e5 * rhs->e222 
            + lhs->e222 * rhs->e5 + lhs->e22 * rhs->e25 + lhs->e25 * rhs->e22;
  res->e1135 =  + lhs->e1 * rhs->e135 + lhs->e135 * rhs->e1 + lhs->e3 * rhs->e115 
            + lhs->e115 * rhs->e3 + lhs->e5 * rhs->e113 + lhs->e113 * rhs->e5 
            + lhs->e11 * rhs->e35 + lhs->e13 * rhs->e15 + lhs->e15 * rhs->e13 
            + lhs->e35 * rhs->e11;
  res->e1235 =  + lhs->e1 * rhs->e235 + lhs->e235 * rhs->e1 + lhs->e2 * rhs->e135 
            + lhs->e135 * rhs->e2 + lhs->e3 * rhs->e125 + lhs->e125 * rhs->e3 
            + lhs->e5 * rhs->e123 + lhs->e123 * rhs->e5 + lhs->e12 * rhs->e35 
            + lhs->e13 * rhs->e25 + lhs->e23 * rhs->e15 + lhs->e15 * rhs->e23 
            + lhs->e25 * rhs->e13 + lhs->e35 * rhs->e12;
  res->e2235 =  + lhs->e2 * rhs->e235 + lhs->e235 * rhs->e2 + lhs->e3 * rhs->e225 
            + lhs->e225 * rhs->e3 + lhs->e5 * rhs->e223 + lhs->e223 * rhs->e5 
            + lhs->e22 * rhs->e35 + lhs->e23 * rhs->e25 + lhs->e25 * rhs->e23 
            + lhs->e35 * rhs->e22;
  res->e1335 =  + lhs->e1 * rhs->e335 + lhs->e335 * rhs->e1 + lhs->e3 * rhs->e135 
            + lhs->e135 * rhs->e3 + lhs->e5 * rhs->e133 + lhs->e133 * rhs->e5 
            + lhs->e13 * rhs->e35 + lhs->e33 * rhs->e15 + lhs->e15 * rhs->e33 
            + lhs->e35 * rhs->e13;
  res->e2335 =  + lhs->e2 * rhs->e335 + lhs->e335 * rhs->e2 + lhs->e3 * rhs->e235 
            + lhs->e235 * rhs->e3 + lhs->e5 * rhs->e233 + lhs->e233 * rhs->e5 
            + lhs->e23 * rhs->e35 + lhs->e33 * rhs->e25 + lhs->e25 * rhs->e33 
            + lhs->e35 * rhs->e23;
  res->e3335 =  + lhs->e3 * rhs->e335 + lhs->e335 * rhs->e3 + lhs->e5 * rhs->e333 
            + lhs->e333 * rhs->e5 + lhs->e33 * rhs->e35 + lhs->e35 * rhs->e33;
  res->e1145 =  + lhs->e1 * rhs->e145 + lhs->e145 * rhs->e1 + lhs->e4 * rhs->e115 
            + lhs->e115 * rhs->e4 + lhs->e5 * rhs->e114 + lhs->e114 * rhs->e5 
            + lhs->e11 * rhs->e45 + lhs->e14 * rhs->e15 + lhs->e15 * rhs->e14 
            + lhs->e45 * rhs->e11;
  res->e1245 =  + lhs->e1 * rhs->e245 + lhs->e245 * rhs->e1 + lhs->e2 * rhs->e145 
            + lhs->e145 * rhs->e2 + lhs->e4 * rhs->e125 + lhs->e125 * rhs->e4 
            + lhs->e5 * rhs->e124 + lhs->e124 * rhs->e5 + lhs->e12 * rhs->e45 
            + lhs->e14 * rhs->e25 + lhs->e24 * rhs->e15 + lhs->e15 * rhs->e24 
            + lhs->e25 * rhs->e14 + lhs->e45 * rhs->e12;
  res->e2245 =  + lhs->e2 * rhs->e245 + lhs->e245 * rhs->e2 + lhs->e4 * rhs->e225 
            + lhs->e225 * rhs->e4 + lhs->e5 * rhs->e224 + lhs->e224 * rhs->e5 
            + lhs->e22 * rhs->e45 + lhs->e24 * rhs->e25 + lhs->e25 * rhs->e24 
            + lhs->e45 * rhs->e22;
  res->e1345 =  + lhs->e1 * rhs->e345 + lhs->e345 * rhs->e1 + lhs->e3 * rhs->e145 
            + lhs->e145 * rhs->e3 + lhs->e4 * rhs->e135 + lhs->e135 * rhs->e4 
            + lhs->e5 * rhs->e134 + lhs->e134 * rhs->e5 + lhs->e13 * rhs->e45 
            + lhs->e14 * rhs->e35 + lhs->e34 * rhs->e15 + lhs->e15 * rhs->e34 
            + lhs->e35 * rhs->e14 + lhs->e45 * rhs->e13;
  res->e2345 =  + lhs->e2 * rhs->e345 + lhs->e345 * rhs->e2 + lhs->e3 * rhs->e245 
            + lhs->e245 * rhs->e3 + lhs->e4 * rhs->e235 + lhs->e235 * rhs->e4 
            + lhs->e5 * rhs->e234 + lhs->e234 * rhs->e5 + lhs->e23 * rhs->e45 
            + lhs->e24 * rhs->e35 + lhs->e34 * rhs->e25 + lhs->e25 * rhs->e34 
            + lhs->e35 * rhs->e24 + lhs->e45 * rhs->e23;
  res->e3345 =  + lhs->e3 * rhs->e345 + lhs->e345 * rhs->e3 + lhs->e4 * rhs->e335 
            + lhs->e335 * rhs->e4 + lhs->e5 * rhs->e334 + lhs->e334 * rhs->e5 
            + lhs->e33 * rhs->e45 + lhs->e34 * rhs->e35 + lhs->e35 * rhs->e34 
            + lhs->e45 * rhs->e33;
  res->e1445 =  + lhs->e1 * rhs->e445 + lhs->e445 * rhs->e1 + lhs->e4 * rhs->e145 
            + lhs->e145 * rhs->e4 + lhs->e5 * rhs->e144 + lhs->e144 * rhs->e5 
            + lhs->e14 * rhs->e45 + lhs->e44 * rhs->e15 + lhs->e15 * rhs->e44 
            + lhs->e45 * rhs->e14;
  res->e2445 =  + lhs->e2 * rhs->e445 + lhs->e445 * rhs->e2 + lhs->e4 * rhs->e245 
            + lhs->e245 * rhs->e4 + lhs->e5 * rhs->e244 + lhs->e244 * rhs->e5 
            + lhs->e24 * rhs->e45 + lhs->e44 * rhs->e25 + lhs->e25 * rhs->e44 
            + lhs->e45 * rhs->e24;
  res->e3445 =  + lhs->e3 * rhs->e445 + lhs->e445 * rhs->e3 + lhs->e4 * rhs->e345 
            + lhs->e345 * rhs->e4 + lhs->e5 * rhs->e344 + lhs->e344 * rhs->e5 
            + lhs->e34 * rhs->e45 + lhs->e44 * rhs->e35 + lhs->e35 * rhs->e44 
            + lhs->e45 * rhs->e34;
  res->e4445 =  + lhs->e4 * rhs->e445 + lhs->e445 * rhs->e4 + lhs->e5 * rhs->e444 
            + lhs->e444 * rhs->e5 + lhs->e44 * rhs->e45 + lhs->e45 * rhs->e44;
  res->e1155 =  + lhs->e1 * rhs->e155 + lhs->e155 * rhs->e1 + lhs->e5 * rhs->e115 
            + lhs->e115 * rhs->e5 + lhs->e11 * rhs->e55 + lhs->e15 * rhs->e15 
            + lhs->e55 * rhs->e11;
  res->e1255 =  + lhs->e1 * rhs->e255 + lhs->e255 * rhs->e1 + lhs->e2 * rhs->e155 
            + lhs->e155 * rhs->e2 + lhs->e5 * rhs->e125 + lhs->e125 * rhs->e5 
            + lhs->e12 * rhs->e55 + lhs->e15 * rhs->e25 + lhs->e25 * rhs->e15 
            + lhs->e55 * rhs->e12;
  res->e2255 =  + lhs->e2 * rhs->e255 + lhs->e255 * rhs->e2 + lhs->e5 * rhs->e225 
            + lhs->e225 * rhs->e5 + lhs->e22 * rhs->e55 + lhs->e25 * rhs->e25 
            + lhs->e55 * rhs->e22;
  res->e1355 =  + lhs->e1 * rhs->e355 + lhs->e355 * rhs->e1 + lhs->e3 * rhs->e155 
            + lhs->e155 * rhs->e3 + lhs->e5 * rhs->e135 + lhs->e135 * rhs->e5 
            + lhs->e13 * rhs->e55 + lhs->e15 * rhs->e35 + lhs->e35 * rhs->e15 
            + lhs->e55 * rhs->e13;
  res->e2355 =  + lhs->e2 * rhs->e355 + lhs->e355 * rhs->e2 + lhs->e3 * rhs->e255 
            + lhs->e255 * rhs->e3 + lhs->e5 * rhs->e235 + lhs->e235 * rhs->e5 
            + lhs->e23 * rhs->e55 + lhs->e25 * rhs->e35 + lhs->e35 * rhs->e25 
            + lhs->e55 * rhs->e23;
  res->e3355 =  + lhs->e3 * rhs->e355 + lhs->e355 * rhs->e3 + lhs->e5 * rhs->e335 
            + lhs->e335 * rhs->e5 + lhs->e33 * rhs->e55 + lhs->e35 * rhs->e35 
            + lhs->e55 * rhs->e33;
  res->e1455 =  + lhs->e1 * rhs->e455 + lhs->e455 * rhs->e1 + lhs->e4 * rhs->e155 
            + lhs->e155 * rhs->e4 + lhs->e5 * rhs->e145 + lhs->e145 * rhs->e5 
            + lhs->e14 * rhs->e55 + lhs->e15 * rhs->e45 + lhs->e45 * rhs->e15 
            + lhs->e55 * rhs->e14;
  res->e2455 =  + lhs->e2 * rhs->e455 + lhs->e455 * rhs->e2 + lhs->e4 * rhs->e255 
            + lhs->e255 * rhs->e4 + lhs->e5 * rhs->e245 + lhs->e245 * rhs->e5 
            + lhs->e24 * rhs->e55 + lhs->e25 * rhs->e45 + lhs->e45 * rhs->e25 
            + lhs->e55 * rhs->e24;
  res->e3455 =  + lhs->e3 * rhs->e455 + lhs->e455 * rhs->e3 + lhs->e4 * rhs->e355 
            + lhs->e355 * rhs->e4 + lhs->e5 * rhs->e345 + lhs->e345 * rhs->e5 
            + lhs->e34 * rhs->e55 + lhs->e35 * rhs->e45 + lhs->e45 * rhs->e35 
            + lhs->e55 * rhs->e34;
  res->e4455 =  + lhs->e4 * rhs->e455 + lhs->e455 * rhs->e4 + lhs->e5 * rhs->e445 
            + lhs->e445 * rhs->e5 + lhs->e44 * rhs->e55 + lhs->e45 * rhs->e45 
            + lhs->e55 * rhs->e44;
  res->e1555 =  + lhs->e1 * rhs->e555 + lhs->e555 * rhs->e1 + lhs->e5 * rhs->e155 
            + lhs->e155 * rhs->e5 + lhs->e15 * rhs->e55 + lhs->e55 * rhs->e15;
  res->e2555 =  + lhs->e2 * rhs->e555 + lhs->e555 * rhs->e2 + lhs->e5 * rhs->e255 
            + lhs->e255 * rhs->e5 + lhs->e25 * rhs->e55 + lhs->e55 * rhs->e25;
  res->e3555 =  + lhs->e3 * rhs->e555 + lhs->e555 * rhs->e3 + lhs->e5 * rhs->e355 
            + lhs->e355 * rhs->e5 + lhs->e35 * rhs->e55 + lhs->e55 * rhs->e35;
  res->e4555 =  + lhs->e4 * rhs->e555 + lhs->e555 * rhs->e4 + lhs->e5 * rhs->e455 
            + lhs->e455 * rhs->e5 + lhs->e45 * rhs->e55 + lhs->e55 * rhs->e45;
  res->e5555 =  + lhs->e5 * rhs->e555 + lhs->e555 * rhs->e5 + lhs->e55 * rhs->e55;
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
  res->e11115 =  + lhs->e1 * rhs->e1115 + lhs->e1115 * rhs->e1 + lhs->e5 * rhs->e1111 
             + lhs->e1111 * rhs->e5 + lhs->e11 * rhs->e115 + lhs->e115 * rhs->e11 
             + lhs->e15 * rhs->e111 + lhs->e111 * rhs->e15;
  res->e11125 =  + lhs->e1 * rhs->e1125 + lhs->e1125 * rhs->e1 + lhs->e2 * rhs->e1115 
             + lhs->e1115 * rhs->e2 + lhs->e5 * rhs->e1112 + lhs->e1112 * rhs->e5 
             + lhs->e11 * rhs->e125 + lhs->e125 * rhs->e11 + lhs->e12 * rhs->e115 
             + lhs->e115 * rhs->e12 + lhs->e15 * rhs->e112 + lhs->e112 * rhs->e15 
             + lhs->e25 * rhs->e111 + lhs->e111 * rhs->e25;
  res->e11225 =  + lhs->e1 * rhs->e1225 + lhs->e1225 * rhs->e1 + lhs->e2 * rhs->e1125 
             + lhs->e1125 * rhs->e2 + lhs->e5 * rhs->e1122 + lhs->e1122 * rhs->e5 
             + lhs->e11 * rhs->e225 + lhs->e225 * rhs->e11 + lhs->e12 * rhs->e125 
             + lhs->e125 * rhs->e12 + lhs->e22 * rhs->e115 + lhs->e115 * rhs->e22 
             + lhs->e15 * rhs->e122 + lhs->e122 * rhs->e15 + lhs->e25 * rhs->e112 
             + lhs->e112 * rhs->e25;
  res->e12225 =  + lhs->e1 * rhs->e2225 + lhs->e2225 * rhs->e1 + lhs->e2 * rhs->e1225 
             + lhs->e1225 * rhs->e2 + lhs->e5 * rhs->e1222 + lhs->e1222 * rhs->e5 
             + lhs->e12 * rhs->e225 + lhs->e225 * rhs->e12 + lhs->e22 * rhs->e125 
             + lhs->e125 * rhs->e22 + lhs->e15 * rhs->e222 + lhs->e222 * rhs->e15 
             + lhs->e25 * rhs->e122 + lhs->e122 * rhs->e25;
  res->e22225 =  + lhs->e2 * rhs->e2225 + lhs->e2225 * rhs->e2 + lhs->e5 * rhs->e2222 
             + lhs->e2222 * rhs->e5 + lhs->e22 * rhs->e225 + lhs->e225 * rhs->e22 
             + lhs->e25 * rhs->e222 + lhs->e222 * rhs->e25;
  res->e11135 =  + lhs->e1 * rhs->e1135 + lhs->e1135 * rhs->e1 + lhs->e3 * rhs->e1115 
             + lhs->e1115 * rhs->e3 + lhs->e5 * rhs->e1113 + lhs->e1113 * rhs->e5 
             + lhs->e11 * rhs->e135 + lhs->e135 * rhs->e11 + lhs->e13 * rhs->e115 
             + lhs->e115 * rhs->e13 + lhs->e15 * rhs->e113 + lhs->e113 * rhs->e15 
             + lhs->e35 * rhs->e111 + lhs->e111 * rhs->e35;
  res->e11235 =  + lhs->e1 * rhs->e1235 + lhs->e1235 * rhs->e1 + lhs->e2 * rhs->e1135 
             + lhs->e1135 * rhs->e2 + lhs->e3 * rhs->e1125 + lhs->e1125 * rhs->e3 
             + lhs->e5 * rhs->e1123 + lhs->e1123 * rhs->e5 + lhs->e11 * rhs->e235 
             + lhs->e235 * rhs->e11 + lhs->e12 * rhs->e135 + lhs->e135 * rhs->e12 
             + lhs->e13 * rhs->e125 + lhs->e125 * rhs->e13 + lhs->e23 * rhs->e115 
             + lhs->e115 * rhs->e23 + lhs->e15 * rhs->e123 + lhs->e123 * rhs->e15 
             + lhs->e25 * rhs->e113 + lhs->e113 * rhs->e25 + lhs->e35 * rhs->e112 
             + lhs->e112 * rhs->e35;
  res->e12235 =  + lhs->e1 * rhs->e2235 + lhs->e2235 * rhs->e1 + lhs->e2 * rhs->e1235 
             + lhs->e1235 * rhs->e2 + lhs->e3 * rhs->e1225 + lhs->e1225 * rhs->e3 
             + lhs->e5 * rhs->e1223 + lhs->e1223 * rhs->e5 + lhs->e12 * rhs->e235 
             + lhs->e235 * rhs->e12 + lhs->e22 * rhs->e135 + lhs->e135 * rhs->e22 
             + lhs->e13 * rhs->e225 + lhs->e225 * rhs->e13 + lhs->e23 * rhs->e125 
             + lhs->e125 * rhs->e23 + lhs->e15 * rhs->e223 + lhs->e223 * rhs->e15 
             + lhs->e25 * rhs->e123 + lhs->e123 * rhs->e25 + lhs->e35 * rhs->e122 
             + lhs->e122 * rhs->e35;
  res->e22235 =  + lhs->e2 * rhs->e2235 + lhs->e2235 * rhs->e2 + lhs->e3 * rhs->e2225 
             + lhs->e2225 * rhs->e3 + lhs->e5 * rhs->e2223 + lhs->e2223 * rhs->e5 
             + lhs->e22 * rhs->e235 + lhs->e235 * rhs->e22 + lhs->e23 * rhs->e225 
             + lhs->e225 * rhs->e23 + lhs->e25 * rhs->e223 + lhs->e223 * rhs->e25 
             + lhs->e35 * rhs->e222 + lhs->e222 * rhs->e35;
  res->e11335 =  + lhs->e1 * rhs->e1335 + lhs->e1335 * rhs->e1 + lhs->e3 * rhs->e1135 
             + lhs->e1135 * rhs->e3 + lhs->e5 * rhs->e1133 + lhs->e1133 * rhs->e5 
             + lhs->e11 * rhs->e335 + lhs->e335 * rhs->e11 + lhs->e13 * rhs->e135 
             + lhs->e135 * rhs->e13 + lhs->e33 * rhs->e115 + lhs->e115 * rhs->e33 
             + lhs->e15 * rhs->e133 + lhs->e133 * rhs->e15 + lhs->e35 * rhs->e113 
             + lhs->e113 * rhs->e35;
  res->e12335 =  + lhs->e1 * rhs->e2335 + lhs->e2335 * rhs->e1 + lhs->e2 * rhs->e1335 
             + lhs->e1335 * rhs->e2 + lhs->e3 * rhs->e1235 + lhs->e1235 * rhs->e3 
             + lhs->e5 * rhs->e1233 + lhs->e1233 * rhs->e5 + lhs->e12 * rhs->e335 
             + lhs->e335 * rhs->e12 + lhs->e13 * rhs->e235 + lhs->e235 * rhs->e13 
             + lhs->e23 * rhs->e135 + lhs->e135 * rhs->e23 + lhs->e33 * rhs->e125 
             + lhs->e125 * rhs->e33 + lhs->e15 * rhs->e233 + lhs->e233 * rhs->e15 
             + lhs->e25 * rhs->e133 + lhs->e133 * rhs->e25 + lhs->e35 * rhs->e123 
             + lhs->e123 * rhs->e35;
  res->e22335 =  + lhs->e2 * rhs->e2335 + lhs->e2335 * rhs->e2 + lhs->e3 * rhs->e2235 
             + lhs->e2235 * rhs->e3 + lhs->e5 * rhs->e2233 + lhs->e2233 * rhs->e5 
             + lhs->e22 * rhs->e335 + lhs->e335 * rhs->e22 + lhs->e23 * rhs->e235 
             + lhs->e235 * rhs->e23 + lhs->e33 * rhs->e225 + lhs->e225 * rhs->e33 
             + lhs->e25 * rhs->e233 + lhs->e233 * rhs->e25 + lhs->e35 * rhs->e223 
             + lhs->e223 * rhs->e35;
  res->e13335 =  + lhs->e1 * rhs->e3335 + lhs->e3335 * rhs->e1 + lhs->e3 * rhs->e1335 
             + lhs->e1335 * rhs->e3 + lhs->e5 * rhs->e1333 + lhs->e1333 * rhs->e5 
             + lhs->e13 * rhs->e335 + lhs->e335 * rhs->e13 + lhs->e33 * rhs->e135 
             + lhs->e135 * rhs->e33 + lhs->e15 * rhs->e333 + lhs->e333 * rhs->e15 
             + lhs->e35 * rhs->e133 + lhs->e133 * rhs->e35;
  res->e23335 =  + lhs->e2 * rhs->e3335 + lhs->e3335 * rhs->e2 + lhs->e3 * rhs->e2335 
             + lhs->e2335 * rhs->e3 + lhs->e5 * rhs->e2333 + lhs->e2333 * rhs->e5 
             + lhs->e23 * rhs->e335 + lhs->e335 * rhs->e23 + lhs->e33 * rhs->e235 
             + lhs->e235 * rhs->e33 + lhs->e25 * rhs->e333 + lhs->e333 * rhs->e25 
             + lhs->e35 * rhs->e233 + lhs->e233 * rhs->e35;
  res->e33335 =  + lhs->e3 * rhs->e3335 + lhs->e3335 * rhs->e3 + lhs->e5 * rhs->e3333 
             + lhs->e3333 * rhs->e5 + lhs->e33 * rhs->e335 + lhs->e335 * rhs->e33 
             + lhs->e35 * rhs->e333 + lhs->e333 * rhs->e35;
  res->e11145 =  + lhs->e1 * rhs->e1145 + lhs->e1145 * rhs->e1 + lhs->e4 * rhs->e1115 
             + lhs->e1115 * rhs->e4 + lhs->e5 * rhs->e1114 + lhs->e1114 * rhs->e5 
             + lhs->e11 * rhs->e145 + lhs->e145 * rhs->e11 + lhs->e14 * rhs->e115 
             + lhs->e115 * rhs->e14 + lhs->e15 * rhs->e114 + lhs->e114 * rhs->e15 
             + lhs->e45 * rhs->e111 + lhs->e111 * rhs->e45;
  res->e11245 =  + lhs->e1 * rhs->e1245 + lhs->e1245 * rhs->e1 + lhs->e2 * rhs->e1145 
             + lhs->e1145 * rhs->e2 + lhs->e4 * rhs->e1125 + lhs->e1125 * rhs->e4 
             + lhs->e5 * rhs->e1124 + lhs->e1124 * rhs->e5 + lhs->e11 * rhs->e245 
             + lhs->e245 * rhs->e11 + lhs->e12 * rhs->e145 + lhs->e145 * rhs->e12 
             + lhs->e14 * rhs->e125 + lhs->e125 * rhs->e14 + lhs->e24 * rhs->e115 
             + lhs->e115 * rhs->e24 + lhs->e15 * rhs->e124 + lhs->e124 * rhs->e15 
             + lhs->e25 * rhs->e114 + lhs->e114 * rhs->e25 + lhs->e45 * rhs->e112 
             + lhs->e112 * rhs->e45;
  res->e12245 =  + lhs->e1 * rhs->e2245 + lhs->e2245 * rhs->e1 + lhs->e2 * rhs->e1245 
             + lhs->e1245 * rhs->e2 + lhs->e4 * rhs->e1225 + lhs->e1225 * rhs->e4 
             + lhs->e5 * rhs->e1224 + lhs->e1224 * rhs->e5 + lhs->e12 * rhs->e245 
             + lhs->e245 * rhs->e12 + lhs->e22 * rhs->e145 + lhs->e145 * rhs->e22 
             + lhs->e14 * rhs->e225 + lhs->e225 * rhs->e14 + lhs->e24 * rhs->e125 
             + lhs->e125 * rhs->e24 + lhs->e15 * rhs->e224 + lhs->e224 * rhs->e15 
             + lhs->e25 * rhs->e124 + lhs->e124 * rhs->e25 + lhs->e45 * rhs->e122 
             + lhs->e122 * rhs->e45;
  res->e22245 =  + lhs->e2 * rhs->e2245 + lhs->e2245 * rhs->e2 + lhs->e4 * rhs->e2225 
             + lhs->e2225 * rhs->e4 + lhs->e5 * rhs->e2224 + lhs->e2224 * rhs->e5 
             + lhs->e22 * rhs->e245 + lhs->e245 * rhs->e22 + lhs->e24 * rhs->e225 
             + lhs->e225 * rhs->e24 + lhs->e25 * rhs->e224 + lhs->e224 * rhs->e25 
             + lhs->e45 * rhs->e222 + lhs->e222 * rhs->e45;
  res->e11345 =  + lhs->e1 * rhs->e1345 + lhs->e1345 * rhs->e1 + lhs->e3 * rhs->e1145 
             + lhs->e1145 * rhs->e3 + lhs->e4 * rhs->e1135 + lhs->e1135 * rhs->e4 
             + lhs->e5 * rhs->e1134 + lhs->e1134 * rhs->e5 + lhs->e11 * rhs->e345 
             + lhs->e345 * rhs->e11 + lhs->e13 * rhs->e145 + lhs->e145 * rhs->e13 
             + lhs->e14 * rhs->e135 + lhs->e135 * rhs->e14 + lhs->e34 * rhs->e115 
             + lhs->e115 * rhs->e34 + lhs->e15 * rhs->e134 + lhs->e134 * rhs->e15 
             + lhs->e35 * rhs->e114 + lhs->e114 * rhs->e35 + lhs->e45 * rhs->e113 
             + lhs->e113 * rhs->e45;
  res->e12345 =  + lhs->e1 * rhs->e2345 + lhs->e2345 * rhs->e1 + lhs->e2 * rhs->e1345 
             + lhs->e1345 * rhs->e2 + lhs->e3 * rhs->e1245 + lhs->e1245 * rhs->e3 
             + lhs->e4 * rhs->e1235 + lhs->e1235 * rhs->e4 + lhs->e5 * rhs->e1234 
             + lhs->e1234 * rhs->e5 + lhs->e12 * rhs->e345 + lhs->e345 * rhs->e12 
             + lhs->e13 * rhs->e245 + lhs->e245 * rhs->e13 + lhs->e23 * rhs->e145 
             + lhs->e145 * rhs->e23 + lhs->e14 * rhs->e235 + lhs->e235 * rhs->e14 
             + lhs->e24 * rhs->e135 + lhs->e135 * rhs->e24 + lhs->e34 * rhs->e125 
             + lhs->e125 * rhs->e34 + lhs->e15 * rhs->e234 + lhs->e234 * rhs->e15 
             + lhs->e25 * rhs->e134 + lhs->e134 * rhs->e25 + lhs->e35 * rhs->e124 
             + lhs->e124 * rhs->e35 + lhs->e45 * rhs->e123 + lhs->e123 * rhs->e45;
  res->e22345 =  + lhs->e2 * rhs->e2345 + lhs->e2345 * rhs->e2 + lhs->e3 * rhs->e2245 
             + lhs->e2245 * rhs->e3 + lhs->e4 * rhs->e2235 + lhs->e2235 * rhs->e4 
             + lhs->e5 * rhs->e2234 + lhs->e2234 * rhs->e5 + lhs->e22 * rhs->e345 
             + lhs->e345 * rhs->e22 + lhs->e23 * rhs->e245 + lhs->e245 * rhs->e23 
             + lhs->e24 * rhs->e235 + lhs->e235 * rhs->e24 + lhs->e34 * rhs->e225 
             + lhs->e225 * rhs->e34 + lhs->e25 * rhs->e234 + lhs->e234 * rhs->e25 
             + lhs->e35 * rhs->e224 + lhs->e224 * rhs->e35 + lhs->e45 * rhs->e223 
             + lhs->e223 * rhs->e45;
  res->e13345 =  + lhs->e1 * rhs->e3345 + lhs->e3345 * rhs->e1 + lhs->e3 * rhs->e1345 
             + lhs->e1345 * rhs->e3 + lhs->e4 * rhs->e1335 + lhs->e1335 * rhs->e4 
             + lhs->e5 * rhs->e1334 + lhs->e1334 * rhs->e5 + lhs->e13 * rhs->e345 
             + lhs->e345 * rhs->e13 + lhs->e33 * rhs->e145 + lhs->e145 * rhs->e33 
             + lhs->e14 * rhs->e335 + lhs->e335 * rhs->e14 + lhs->e34 * rhs->e135 
             + lhs->e135 * rhs->e34 + lhs->e15 * rhs->e334 + lhs->e334 * rhs->e15 
             + lhs->e35 * rhs->e134 + lhs->e134 * rhs->e35 + lhs->e45 * rhs->e133 
             + lhs->e133 * rhs->e45;
  res->e23345 =  + lhs->e2 * rhs->e3345 + lhs->e3345 * rhs->e2 + lhs->e3 * rhs->e2345 
             + lhs->e2345 * rhs->e3 + lhs->e4 * rhs->e2335 + lhs->e2335 * rhs->e4 
             + lhs->e5 * rhs->e2334 + lhs->e2334 * rhs->e5 + lhs->e23 * rhs->e345 
             + lhs->e345 * rhs->e23 + lhs->e33 * rhs->e245 + lhs->e245 * rhs->e33 
             + lhs->e24 * rhs->e335 + lhs->e335 * rhs->e24 + lhs->e34 * rhs->e235 
             + lhs->e235 * rhs->e34 + lhs->e25 * rhs->e334 + lhs->e334 * rhs->e25 
             + lhs->e35 * rhs->e234 + lhs->e234 * rhs->e35 + lhs->e45 * rhs->e233 
             + lhs->e233 * rhs->e45;
  res->e33345 =  + lhs->e3 * rhs->e3345 + lhs->e3345 * rhs->e3 + lhs->e4 * rhs->e3335 
             + lhs->e3335 * rhs->e4 + lhs->e5 * rhs->e3334 + lhs->e3334 * rhs->e5 
             + lhs->e33 * rhs->e345 + lhs->e345 * rhs->e33 + lhs->e34 * rhs->e335 
             + lhs->e335 * rhs->e34 + lhs->e35 * rhs->e334 + lhs->e334 * rhs->e35 
             + lhs->e45 * rhs->e333 + lhs->e333 * rhs->e45;
  res->e11445 =  + lhs->e1 * rhs->e1445 + lhs->e1445 * rhs->e1 + lhs->e4 * rhs->e1145 
             + lhs->e1145 * rhs->e4 + lhs->e5 * rhs->e1144 + lhs->e1144 * rhs->e5 
             + lhs->e11 * rhs->e445 + lhs->e445 * rhs->e11 + lhs->e14 * rhs->e145 
             + lhs->e145 * rhs->e14 + lhs->e44 * rhs->e115 + lhs->e115 * rhs->e44 
             + lhs->e15 * rhs->e144 + lhs->e144 * rhs->e15 + lhs->e45 * rhs->e114 
             + lhs->e114 * rhs->e45;
  res->e12445 =  + lhs->e1 * rhs->e2445 + lhs->e2445 * rhs->e1 + lhs->e2 * rhs->e1445 
             + lhs->e1445 * rhs->e2 + lhs->e4 * rhs->e1245 + lhs->e1245 * rhs->e4 
             + lhs->e5 * rhs->e1244 + lhs->e1244 * rhs->e5 + lhs->e12 * rhs->e445 
             + lhs->e445 * rhs->e12 + lhs->e14 * rhs->e245 + lhs->e245 * rhs->e14 
             + lhs->e24 * rhs->e145 + lhs->e145 * rhs->e24 + lhs->e44 * rhs->e125 
             + lhs->e125 * rhs->e44 + lhs->e15 * rhs->e244 + lhs->e244 * rhs->e15 
             + lhs->e25 * rhs->e144 + lhs->e144 * rhs->e25 + lhs->e45 * rhs->e124 
             + lhs->e124 * rhs->e45;
  res->e22445 =  + lhs->e2 * rhs->e2445 + lhs->e2445 * rhs->e2 + lhs->e4 * rhs->e2245 
             + lhs->e2245 * rhs->e4 + lhs->e5 * rhs->e2244 + lhs->e2244 * rhs->e5 
             + lhs->e22 * rhs->e445 + lhs->e445 * rhs->e22 + lhs->e24 * rhs->e245 
             + lhs->e245 * rhs->e24 + lhs->e44 * rhs->e225 + lhs->e225 * rhs->e44 
             + lhs->e25 * rhs->e244 + lhs->e244 * rhs->e25 + lhs->e45 * rhs->e224 
             + lhs->e224 * rhs->e45;
  res->e13445 =  + lhs->e1 * rhs->e3445 + lhs->e3445 * rhs->e1 + lhs->e3 * rhs->e1445 
             + lhs->e1445 * rhs->e3 + lhs->e4 * rhs->e1345 + lhs->e1345 * rhs->e4 
             + lhs->e5 * rhs->e1344 + lhs->e1344 * rhs->e5 + lhs->e13 * rhs->e445 
             + lhs->e445 * rhs->e13 + lhs->e14 * rhs->e345 + lhs->e345 * rhs->e14 
             + lhs->e34 * rhs->e145 + lhs->e145 * rhs->e34 + lhs->e44 * rhs->e135 
             + lhs->e135 * rhs->e44 + lhs->e15 * rhs->e344 + lhs->e344 * rhs->e15 
             + lhs->e35 * rhs->e144 + lhs->e144 * rhs->e35 + lhs->e45 * rhs->e134 
             + lhs->e134 * rhs->e45;
  res->e23445 =  + lhs->e2 * rhs->e3445 + lhs->e3445 * rhs->e2 + lhs->e3 * rhs->e2445 
             + lhs->e2445 * rhs->e3 + lhs->e4 * rhs->e2345 + lhs->e2345 * rhs->e4 
             + lhs->e5 * rhs->e2344 + lhs->e2344 * rhs->e5 + lhs->e23 * rhs->e445 
             + lhs->e445 * rhs->e23 + lhs->e24 * rhs->e345 + lhs->e345 * rhs->e24 
             + lhs->e34 * rhs->e245 + lhs->e245 * rhs->e34 + lhs->e44 * rhs->e235 
             + lhs->e235 * rhs->e44 + lhs->e25 * rhs->e344 + lhs->e344 * rhs->e25 
             + lhs->e35 * rhs->e244 + lhs->e244 * rhs->e35 + lhs->e45 * rhs->e234 
             + lhs->e234 * rhs->e45;
  res->e33445 =  + lhs->e3 * rhs->e3445 + lhs->e3445 * rhs->e3 + lhs->e4 * rhs->e3345 
             + lhs->e3345 * rhs->e4 + lhs->e5 * rhs->e3344 + lhs->e3344 * rhs->e5 
             + lhs->e33 * rhs->e445 + lhs->e445 * rhs->e33 + lhs->e34 * rhs->e345 
             + lhs->e345 * rhs->e34 + lhs->e44 * rhs->e335 + lhs->e335 * rhs->e44 
             + lhs->e35 * rhs->e344 + lhs->e344 * rhs->e35 + lhs->e45 * rhs->e334 
             + lhs->e334 * rhs->e45;
  res->e14445 =  + lhs->e1 * rhs->e4445 + lhs->e4445 * rhs->e1 + lhs->e4 * rhs->e1445 
             + lhs->e1445 * rhs->e4 + lhs->e5 * rhs->e1444 + lhs->e1444 * rhs->e5 
             + lhs->e14 * rhs->e445 + lhs->e445 * rhs->e14 + lhs->e44 * rhs->e145 
             + lhs->e145 * rhs->e44 + lhs->e15 * rhs->e444 + lhs->e444 * rhs->e15 
             + lhs->e45 * rhs->e144 + lhs->e144 * rhs->e45;
  res->e24445 =  + lhs->e2 * rhs->e4445 + lhs->e4445 * rhs->e2 + lhs->e4 * rhs->e2445 
             + lhs->e2445 * rhs->e4 + lhs->e5 * rhs->e2444 + lhs->e2444 * rhs->e5 
             + lhs->e24 * rhs->e445 + lhs->e445 * rhs->e24 + lhs->e44 * rhs->e245 
             + lhs->e245 * rhs->e44 + lhs->e25 * rhs->e444 + lhs->e444 * rhs->e25 
             + lhs->e45 * rhs->e244 + lhs->e244 * rhs->e45;
  res->e34445 =  + lhs->e3 * rhs->e4445 + lhs->e4445 * rhs->e3 + lhs->e4 * rhs->e3445 
             + lhs->e3445 * rhs->e4 + lhs->e5 * rhs->e3444 + lhs->e3444 * rhs->e5 
             + lhs->e34 * rhs->e445 + lhs->e445 * rhs->e34 + lhs->e44 * rhs->e345 
             + lhs->e345 * rhs->e44 + lhs->e35 * rhs->e444 + lhs->e444 * rhs->e35 
             + lhs->e45 * rhs->e344 + lhs->e344 * rhs->e45;
  res->e44445 =  + lhs->e4 * rhs->e4445 + lhs->e4445 * rhs->e4 + lhs->e5 * rhs->e4444 
             + lhs->e4444 * rhs->e5 + lhs->e44 * rhs->e445 + lhs->e445 * rhs->e44 
             + lhs->e45 * rhs->e444 + lhs->e444 * rhs->e45;
  res->e11155 =  + lhs->e1 * rhs->e1155 + lhs->e1155 * rhs->e1 + lhs->e5 * rhs->e1115 
             + lhs->e1115 * rhs->e5 + lhs->e11 * rhs->e155 + lhs->e155 * rhs->e11 
             + lhs->e15 * rhs->e115 + lhs->e115 * rhs->e15 + lhs->e55 * rhs->e111 
             + lhs->e111 * rhs->e55;
  res->e11255 =  + lhs->e1 * rhs->e1255 + lhs->e1255 * rhs->e1 + lhs->e2 * rhs->e1155 
             + lhs->e1155 * rhs->e2 + lhs->e5 * rhs->e1125 + lhs->e1125 * rhs->e5 
             + lhs->e11 * rhs->e255 + lhs->e255 * rhs->e11 + lhs->e12 * rhs->e155 
             + lhs->e155 * rhs->e12 + lhs->e15 * rhs->e125 + lhs->e125 * rhs->e15 
             + lhs->e25 * rhs->e115 + lhs->e115 * rhs->e25 + lhs->e55 * rhs->e112 
             + lhs->e112 * rhs->e55;
  res->e12255 =  + lhs->e1 * rhs->e2255 + lhs->e2255 * rhs->e1 + lhs->e2 * rhs->e1255 
             + lhs->e1255 * rhs->e2 + lhs->e5 * rhs->e1225 + lhs->e1225 * rhs->e5 
             + lhs->e12 * rhs->e255 + lhs->e255 * rhs->e12 + lhs->e22 * rhs->e155 
             + lhs->e155 * rhs->e22 + lhs->e15 * rhs->e225 + lhs->e225 * rhs->e15 
             + lhs->e25 * rhs->e125 + lhs->e125 * rhs->e25 + lhs->e55 * rhs->e122 
             + lhs->e122 * rhs->e55;
  res->e22255 =  + lhs->e2 * rhs->e2255 + lhs->e2255 * rhs->e2 + lhs->e5 * rhs->e2225 
             + lhs->e2225 * rhs->e5 + lhs->e22 * rhs->e255 + lhs->e255 * rhs->e22 
             + lhs->e25 * rhs->e225 + lhs->e225 * rhs->e25 + lhs->e55 * rhs->e222 
             + lhs->e222 * rhs->e55;
  res->e11355 =  + lhs->e1 * rhs->e1355 + lhs->e1355 * rhs->e1 + lhs->e3 * rhs->e1155 
             + lhs->e1155 * rhs->e3 + lhs->e5 * rhs->e1135 + lhs->e1135 * rhs->e5 
             + lhs->e11 * rhs->e355 + lhs->e355 * rhs->e11 + lhs->e13 * rhs->e155 
             + lhs->e155 * rhs->e13 + lhs->e15 * rhs->e135 + lhs->e135 * rhs->e15 
             + lhs->e35 * rhs->e115 + lhs->e115 * rhs->e35 + lhs->e55 * rhs->e113 
             + lhs->e113 * rhs->e55;
  res->e12355 =  + lhs->e1 * rhs->e2355 + lhs->e2355 * rhs->e1 + lhs->e2 * rhs->e1355 
             + lhs->e1355 * rhs->e2 + lhs->e3 * rhs->e1255 + lhs->e1255 * rhs->e3 
             + lhs->e5 * rhs->e1235 + lhs->e1235 * rhs->e5 + lhs->e12 * rhs->e355 
             + lhs->e355 * rhs->e12 + lhs->e13 * rhs->e255 + lhs->e255 * rhs->e13 
             + lhs->e23 * rhs->e155 + lhs->e155 * rhs->e23 + lhs->e15 * rhs->e235 
             + lhs->e235 * rhs->e15 + lhs->e25 * rhs->e135 + lhs->e135 * rhs->e25 
             + lhs->e35 * rhs->e125 + lhs->e125 * rhs->e35 + lhs->e55 * rhs->e123 
             + lhs->e123 * rhs->e55;
  res->e22355 =  + lhs->e2 * rhs->e2355 + lhs->e2355 * rhs->e2 + lhs->e3 * rhs->e2255 
             + lhs->e2255 * rhs->e3 + lhs->e5 * rhs->e2235 + lhs->e2235 * rhs->e5 
             + lhs->e22 * rhs->e355 + lhs->e355 * rhs->e22 + lhs->e23 * rhs->e255 
             + lhs->e255 * rhs->e23 + lhs->e25 * rhs->e235 + lhs->e235 * rhs->e25 
             + lhs->e35 * rhs->e225 + lhs->e225 * rhs->e35 + lhs->e55 * rhs->e223 
             + lhs->e223 * rhs->e55;
  res->e13355 =  + lhs->e1 * rhs->e3355 + lhs->e3355 * rhs->e1 + lhs->e3 * rhs->e1355 
             + lhs->e1355 * rhs->e3 + lhs->e5 * rhs->e1335 + lhs->e1335 * rhs->e5 
             + lhs->e13 * rhs->e355 + lhs->e355 * rhs->e13 + lhs->e33 * rhs->e155 
             + lhs->e155 * rhs->e33 + lhs->e15 * rhs->e335 + lhs->e335 * rhs->e15 
             + lhs->e35 * rhs->e135 + lhs->e135 * rhs->e35 + lhs->e55 * rhs->e133 
             + lhs->e133 * rhs->e55;
  res->e23355 =  + lhs->e2 * rhs->e3355 + lhs->e3355 * rhs->e2 + lhs->e3 * rhs->e2355 
             + lhs->e2355 * rhs->e3 + lhs->e5 * rhs->e2335 + lhs->e2335 * rhs->e5 
             + lhs->e23 * rhs->e355 + lhs->e355 * rhs->e23 + lhs->e33 * rhs->e255 
             + lhs->e255 * rhs->e33 + lhs->e25 * rhs->e335 + lhs->e335 * rhs->e25 
             + lhs->e35 * rhs->e235 + lhs->e235 * rhs->e35 + lhs->e55 * rhs->e233 
             + lhs->e233 * rhs->e55;
  res->e33355 =  + lhs->e3 * rhs->e3355 + lhs->e3355 * rhs->e3 + lhs->e5 * rhs->e3335 
             + lhs->e3335 * rhs->e5 + lhs->e33 * rhs->e355 + lhs->e355 * rhs->e33 
             + lhs->e35 * rhs->e335 + lhs->e335 * rhs->e35 + lhs->e55 * rhs->e333 
             + lhs->e333 * rhs->e55;
  res->e11455 =  + lhs->e1 * rhs->e1455 + lhs->e1455 * rhs->e1 + lhs->e4 * rhs->e1155 
             + lhs->e1155 * rhs->e4 + lhs->e5 * rhs->e1145 + lhs->e1145 * rhs->e5 
             + lhs->e11 * rhs->e455 + lhs->e455 * rhs->e11 + lhs->e14 * rhs->e155 
             + lhs->e155 * rhs->e14 + lhs->e15 * rhs->e145 + lhs->e145 * rhs->e15 
             + lhs->e45 * rhs->e115 + lhs->e115 * rhs->e45 + lhs->e55 * rhs->e114 
             + lhs->e114 * rhs->e55;
  res->e12455 =  + lhs->e1 * rhs->e2455 + lhs->e2455 * rhs->e1 + lhs->e2 * rhs->e1455 
             + lhs->e1455 * rhs->e2 + lhs->e4 * rhs->e1255 + lhs->e1255 * rhs->e4 
             + lhs->e5 * rhs->e1245 + lhs->e1245 * rhs->e5 + lhs->e12 * rhs->e455 
             + lhs->e455 * rhs->e12 + lhs->e14 * rhs->e255 + lhs->e255 * rhs->e14 
             + lhs->e24 * rhs->e155 + lhs->e155 * rhs->e24 + lhs->e15 * rhs->e245 
             + lhs->e245 * rhs->e15 + lhs->e25 * rhs->e145 + lhs->e145 * rhs->e25 
             + lhs->e45 * rhs->e125 + lhs->e125 * rhs->e45 + lhs->e55 * rhs->e124 
             + lhs->e124 * rhs->e55;
  res->e22455 =  + lhs->e2 * rhs->e2455 + lhs->e2455 * rhs->e2 + lhs->e4 * rhs->e2255 
             + lhs->e2255 * rhs->e4 + lhs->e5 * rhs->e2245 + lhs->e2245 * rhs->e5 
             + lhs->e22 * rhs->e455 + lhs->e455 * rhs->e22 + lhs->e24 * rhs->e255 
             + lhs->e255 * rhs->e24 + lhs->e25 * rhs->e245 + lhs->e245 * rhs->e25 
             + lhs->e45 * rhs->e225 + lhs->e225 * rhs->e45 + lhs->e55 * rhs->e224 
             + lhs->e224 * rhs->e55;
  res->e13455 =  + lhs->e1 * rhs->e3455 + lhs->e3455 * rhs->e1 + lhs->e3 * rhs->e1455 
             + lhs->e1455 * rhs->e3 + lhs->e4 * rhs->e1355 + lhs->e1355 * rhs->e4 
             + lhs->e5 * rhs->e1345 + lhs->e1345 * rhs->e5 + lhs->e13 * rhs->e455 
             + lhs->e455 * rhs->e13 + lhs->e14 * rhs->e355 + lhs->e355 * rhs->e14 
             + lhs->e34 * rhs->e155 + lhs->e155 * rhs->e34 + lhs->e15 * rhs->e345 
             + lhs->e345 * rhs->e15 + lhs->e35 * rhs->e145 + lhs->e145 * rhs->e35 
             + lhs->e45 * rhs->e135 + lhs->e135 * rhs->e45 + lhs->e55 * rhs->e134 
             + lhs->e134 * rhs->e55;
  res->e23455 =  + lhs->e2 * rhs->e3455 + lhs->e3455 * rhs->e2 + lhs->e3 * rhs->e2455 
             + lhs->e2455 * rhs->e3 + lhs->e4 * rhs->e2355 + lhs->e2355 * rhs->e4 
             + lhs->e5 * rhs->e2345 + lhs->e2345 * rhs->e5 + lhs->e23 * rhs->e455 
             + lhs->e455 * rhs->e23 + lhs->e24 * rhs->e355 + lhs->e355 * rhs->e24 
             + lhs->e34 * rhs->e255 + lhs->e255 * rhs->e34 + lhs->e25 * rhs->e345 
             + lhs->e345 * rhs->e25 + lhs->e35 * rhs->e245 + lhs->e245 * rhs->e35 
             + lhs->e45 * rhs->e235 + lhs->e235 * rhs->e45 + lhs->e55 * rhs->e234 
             + lhs->e234 * rhs->e55;
  res->e33455 =  + lhs->e3 * rhs->e3455 + lhs->e3455 * rhs->e3 + lhs->e4 * rhs->e3355 
             + lhs->e3355 * rhs->e4 + lhs->e5 * rhs->e3345 + lhs->e3345 * rhs->e5 
             + lhs->e33 * rhs->e455 + lhs->e455 * rhs->e33 + lhs->e34 * rhs->e355 
             + lhs->e355 * rhs->e34 + lhs->e35 * rhs->e345 + lhs->e345 * rhs->e35 
             + lhs->e45 * rhs->e335 + lhs->e335 * rhs->e45 + lhs->e55 * rhs->e334 
             + lhs->e334 * rhs->e55;
  res->e14455 =  + lhs->e1 * rhs->e4455 + lhs->e4455 * rhs->e1 + lhs->e4 * rhs->e1455 
             + lhs->e1455 * rhs->e4 + lhs->e5 * rhs->e1445 + lhs->e1445 * rhs->e5 
             + lhs->e14 * rhs->e455 + lhs->e455 * rhs->e14 + lhs->e44 * rhs->e155 
             + lhs->e155 * rhs->e44 + lhs->e15 * rhs->e445 + lhs->e445 * rhs->e15 
             + lhs->e45 * rhs->e145 + lhs->e145 * rhs->e45 + lhs->e55 * rhs->e144 
             + lhs->e144 * rhs->e55;
  res->e24455 =  + lhs->e2 * rhs->e4455 + lhs->e4455 * rhs->e2 + lhs->e4 * rhs->e2455 
             + lhs->e2455 * rhs->e4 + lhs->e5 * rhs->e2445 + lhs->e2445 * rhs->e5 
             + lhs->e24 * rhs->e455 + lhs->e455 * rhs->e24 + lhs->e44 * rhs->e255 
             + lhs->e255 * rhs->e44 + lhs->e25 * rhs->e445 + lhs->e445 * rhs->e25 
             + lhs->e45 * rhs->e245 + lhs->e245 * rhs->e45 + lhs->e55 * rhs->e244 
             + lhs->e244 * rhs->e55;
  res->e34455 =  + lhs->e3 * rhs->e4455 + lhs->e4455 * rhs->e3 + lhs->e4 * rhs->e3455 
             + lhs->e3455 * rhs->e4 + lhs->e5 * rhs->e3445 + lhs->e3445 * rhs->e5 
             + lhs->e34 * rhs->e455 + lhs->e455 * rhs->e34 + lhs->e44 * rhs->e355 
             + lhs->e355 * rhs->e44 + lhs->e35 * rhs->e445 + lhs->e445 * rhs->e35 
             + lhs->e45 * rhs->e345 + lhs->e345 * rhs->e45 + lhs->e55 * rhs->e344 
             + lhs->e344 * rhs->e55;
  res->e44455 =  + lhs->e4 * rhs->e4455 + lhs->e4455 * rhs->e4 + lhs->e5 * rhs->e4445 
             + lhs->e4445 * rhs->e5 + lhs->e44 * rhs->e455 + lhs->e455 * rhs->e44 
             + lhs->e45 * rhs->e445 + lhs->e445 * rhs->e45 + lhs->e55 * rhs->e444 
             + lhs->e444 * rhs->e55;
  res->e11555 =  + lhs->e1 * rhs->e1555 + lhs->e1555 * rhs->e1 + lhs->e5 * rhs->e1155 
             + lhs->e1155 * rhs->e5 + lhs->e11 * rhs->e555 + lhs->e555 * rhs->e11 
             + lhs->e15 * rhs->e155 + lhs->e155 * rhs->e15 + lhs->e55 * rhs->e115 
             + lhs->e115 * rhs->e55;
  res->e12555 =  + lhs->e1 * rhs->e2555 + lhs->e2555 * rhs->e1 + lhs->e2 * rhs->e1555 
             + lhs->e1555 * rhs->e2 + lhs->e5 * rhs->e1255 + lhs->e1255 * rhs->e5 
             + lhs->e12 * rhs->e555 + lhs->e555 * rhs->e12 + lhs->e15 * rhs->e255 
             + lhs->e255 * rhs->e15 + lhs->e25 * rhs->e155 + lhs->e155 * rhs->e25 
             + lhs->e55 * rhs->e125 + lhs->e125 * rhs->e55;
  res->e22555 =  + lhs->e2 * rhs->e2555 + lhs->e2555 * rhs->e2 + lhs->e5 * rhs->e2255 
             + lhs->e2255 * rhs->e5 + lhs->e22 * rhs->e555 + lhs->e555 * rhs->e22 
             + lhs->e25 * rhs->e255 + lhs->e255 * rhs->e25 + lhs->e55 * rhs->e225 
             + lhs->e225 * rhs->e55;
  res->e13555 =  + lhs->e1 * rhs->e3555 + lhs->e3555 * rhs->e1 + lhs->e3 * rhs->e1555 
             + lhs->e1555 * rhs->e3 + lhs->e5 * rhs->e1355 + lhs->e1355 * rhs->e5 
             + lhs->e13 * rhs->e555 + lhs->e555 * rhs->e13 + lhs->e15 * rhs->e355 
             + lhs->e355 * rhs->e15 + lhs->e35 * rhs->e155 + lhs->e155 * rhs->e35 
             + lhs->e55 * rhs->e135 + lhs->e135 * rhs->e55;
  res->e23555 =  + lhs->e2 * rhs->e3555 + lhs->e3555 * rhs->e2 + lhs->e3 * rhs->e2555 
             + lhs->e2555 * rhs->e3 + lhs->e5 * rhs->e2355 + lhs->e2355 * rhs->e5 
             + lhs->e23 * rhs->e555 + lhs->e555 * rhs->e23 + lhs->e25 * rhs->e355 
             + lhs->e355 * rhs->e25 + lhs->e35 * rhs->e255 + lhs->e255 * rhs->e35 
             + lhs->e55 * rhs->e235 + lhs->e235 * rhs->e55;
  res->e33555 =  + lhs->e3 * rhs->e3555 + lhs->e3555 * rhs->e3 + lhs->e5 * rhs->e3355 
             + lhs->e3355 * rhs->e5 + lhs->e33 * rhs->e555 + lhs->e555 * rhs->e33 
             + lhs->e35 * rhs->e355 + lhs->e355 * rhs->e35 + lhs->e55 * rhs->e335 
             + lhs->e335 * rhs->e55;
  res->e14555 =  + lhs->e1 * rhs->e4555 + lhs->e4555 * rhs->e1 + lhs->e4 * rhs->e1555 
             + lhs->e1555 * rhs->e4 + lhs->e5 * rhs->e1455 + lhs->e1455 * rhs->e5 
             + lhs->e14 * rhs->e555 + lhs->e555 * rhs->e14 + lhs->e15 * rhs->e455 
             + lhs->e455 * rhs->e15 + lhs->e45 * rhs->e155 + lhs->e155 * rhs->e45 
             + lhs->e55 * rhs->e145 + lhs->e145 * rhs->e55;
  res->e24555 =  + lhs->e2 * rhs->e4555 + lhs->e4555 * rhs->e2 + lhs->e4 * rhs->e2555 
             + lhs->e2555 * rhs->e4 + lhs->e5 * rhs->e2455 + lhs->e2455 * rhs->e5 
             + lhs->e24 * rhs->e555 + lhs->e555 * rhs->e24 + lhs->e25 * rhs->e455 
             + lhs->e455 * rhs->e25 + lhs->e45 * rhs->e255 + lhs->e255 * rhs->e45 
             + lhs->e55 * rhs->e245 + lhs->e245 * rhs->e55;
  res->e34555 =  + lhs->e3 * rhs->e4555 + lhs->e4555 * rhs->e3 + lhs->e4 * rhs->e3555 
             + lhs->e3555 * rhs->e4 + lhs->e5 * rhs->e3455 + lhs->e3455 * rhs->e5 
             + lhs->e34 * rhs->e555 + lhs->e555 * rhs->e34 + lhs->e35 * rhs->e455 
             + lhs->e455 * rhs->e35 + lhs->e45 * rhs->e355 + lhs->e355 * rhs->e45 
             + lhs->e55 * rhs->e345 + lhs->e345 * rhs->e55;
  res->e44555 =  + lhs->e4 * rhs->e4555 + lhs->e4555 * rhs->e4 + lhs->e5 * rhs->e4455 
             + lhs->e4455 * rhs->e5 + lhs->e44 * rhs->e555 + lhs->e555 * rhs->e44 
             + lhs->e45 * rhs->e455 + lhs->e455 * rhs->e45 + lhs->e55 * rhs->e445 
             + lhs->e445 * rhs->e55;
  res->e15555 =  + lhs->e1 * rhs->e5555 + lhs->e5555 * rhs->e1 + lhs->e5 * rhs->e1555 
             + lhs->e1555 * rhs->e5 + lhs->e15 * rhs->e555 + lhs->e555 * rhs->e15 
             + lhs->e55 * rhs->e155 + lhs->e155 * rhs->e55;
  res->e25555 =  + lhs->e2 * rhs->e5555 + lhs->e5555 * rhs->e2 + lhs->e5 * rhs->e2555 
             + lhs->e2555 * rhs->e5 + lhs->e25 * rhs->e555 + lhs->e555 * rhs->e25 
             + lhs->e55 * rhs->e255 + lhs->e255 * rhs->e55;
  res->e35555 =  + lhs->e3 * rhs->e5555 + lhs->e5555 * rhs->e3 + lhs->e5 * rhs->e3555 
             + lhs->e3555 * rhs->e5 + lhs->e35 * rhs->e555 + lhs->e555 * rhs->e35 
             + lhs->e55 * rhs->e355 + lhs->e355 * rhs->e55;
  res->e45555 =  + lhs->e4 * rhs->e5555 + lhs->e5555 * rhs->e4 + lhs->e5 * rhs->e4555 
             + lhs->e4555 * rhs->e5 + lhs->e45 * rhs->e555 + lhs->e555 * rhs->e45 
             + lhs->e55 * rhs->e455 + lhs->e455 * rhs->e55;
  res->e55555 =  + lhs->e5 * rhs->e5555 + lhs->e5555 * rhs->e5 + lhs->e55 * rhs->e555 
             + lhs->e555 * rhs->e55;

}

onumm5n5_t onumm5n5_gem_oo(  onumm5n5_t* a,  onumm5n5_t* b,  onumm5n5_t* c){
  onumm5n5_t res;

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
  res.e1115 = c->e1115 + a->r * b->e1115 + a->e1115 * b->r + a->e1 * b->e115 
            + a->e115 * b->e1 + a->e5 * b->e111 + a->e111 * b->e5 
            + a->e11 * b->e15 + a->e15 * b->e11;
  res.e1125 = c->e1125 + a->r * b->e1125 + a->e1125 * b->r + a->e1 * b->e125 
            + a->e125 * b->e1 + a->e2 * b->e115 + a->e115 * b->e2 
            + a->e5 * b->e112 + a->e112 * b->e5 + a->e11 * b->e25 
            + a->e12 * b->e15 + a->e15 * b->e12 + a->e25 * b->e11;
  res.e1225 = c->e1225 + a->r * b->e1225 + a->e1225 * b->r + a->e1 * b->e225 
            + a->e225 * b->e1 + a->e2 * b->e125 + a->e125 * b->e2 
            + a->e5 * b->e122 + a->e122 * b->e5 + a->e12 * b->e25 
            + a->e22 * b->e15 + a->e15 * b->e22 + a->e25 * b->e12;
  res.e2225 = c->e2225 + a->r * b->e2225 + a->e2225 * b->r + a->e2 * b->e225 
            + a->e225 * b->e2 + a->e5 * b->e222 + a->e222 * b->e5 
            + a->e22 * b->e25 + a->e25 * b->e22;
  res.e1135 = c->e1135 + a->r * b->e1135 + a->e1135 * b->r + a->e1 * b->e135 
            + a->e135 * b->e1 + a->e3 * b->e115 + a->e115 * b->e3 
            + a->e5 * b->e113 + a->e113 * b->e5 + a->e11 * b->e35 
            + a->e13 * b->e15 + a->e15 * b->e13 + a->e35 * b->e11;
  res.e1235 = c->e1235 + a->r * b->e1235 + a->e1235 * b->r + a->e1 * b->e235 
            + a->e235 * b->e1 + a->e2 * b->e135 + a->e135 * b->e2 
            + a->e3 * b->e125 + a->e125 * b->e3 + a->e5 * b->e123 
            + a->e123 * b->e5 + a->e12 * b->e35 + a->e13 * b->e25 
            + a->e23 * b->e15 + a->e15 * b->e23 + a->e25 * b->e13 
            + a->e35 * b->e12;
  res.e2235 = c->e2235 + a->r * b->e2235 + a->e2235 * b->r + a->e2 * b->e235 
            + a->e235 * b->e2 + a->e3 * b->e225 + a->e225 * b->e3 
            + a->e5 * b->e223 + a->e223 * b->e5 + a->e22 * b->e35 
            + a->e23 * b->e25 + a->e25 * b->e23 + a->e35 * b->e22;
  res.e1335 = c->e1335 + a->r * b->e1335 + a->e1335 * b->r + a->e1 * b->e335 
            + a->e335 * b->e1 + a->e3 * b->e135 + a->e135 * b->e3 
            + a->e5 * b->e133 + a->e133 * b->e5 + a->e13 * b->e35 
            + a->e33 * b->e15 + a->e15 * b->e33 + a->e35 * b->e13;
  res.e2335 = c->e2335 + a->r * b->e2335 + a->e2335 * b->r + a->e2 * b->e335 
            + a->e335 * b->e2 + a->e3 * b->e235 + a->e235 * b->e3 
            + a->e5 * b->e233 + a->e233 * b->e5 + a->e23 * b->e35 
            + a->e33 * b->e25 + a->e25 * b->e33 + a->e35 * b->e23;
  res.e3335 = c->e3335 + a->r * b->e3335 + a->e3335 * b->r + a->e3 * b->e335 
            + a->e335 * b->e3 + a->e5 * b->e333 + a->e333 * b->e5 
            + a->e33 * b->e35 + a->e35 * b->e33;
  res.e1145 = c->e1145 + a->r * b->e1145 + a->e1145 * b->r + a->e1 * b->e145 
            + a->e145 * b->e1 + a->e4 * b->e115 + a->e115 * b->e4 
            + a->e5 * b->e114 + a->e114 * b->e5 + a->e11 * b->e45 
            + a->e14 * b->e15 + a->e15 * b->e14 + a->e45 * b->e11;
  res.e1245 = c->e1245 + a->r * b->e1245 + a->e1245 * b->r + a->e1 * b->e245 
            + a->e245 * b->e1 + a->e2 * b->e145 + a->e145 * b->e2 
            + a->e4 * b->e125 + a->e125 * b->e4 + a->e5 * b->e124 
            + a->e124 * b->e5 + a->e12 * b->e45 + a->e14 * b->e25 
            + a->e24 * b->e15 + a->e15 * b->e24 + a->e25 * b->e14 
            + a->e45 * b->e12;
  res.e2245 = c->e2245 + a->r * b->e2245 + a->e2245 * b->r + a->e2 * b->e245 
            + a->e245 * b->e2 + a->e4 * b->e225 + a->e225 * b->e4 
            + a->e5 * b->e224 + a->e224 * b->e5 + a->e22 * b->e45 
            + a->e24 * b->e25 + a->e25 * b->e24 + a->e45 * b->e22;
  res.e1345 = c->e1345 + a->r * b->e1345 + a->e1345 * b->r + a->e1 * b->e345 
            + a->e345 * b->e1 + a->e3 * b->e145 + a->e145 * b->e3 
            + a->e4 * b->e135 + a->e135 * b->e4 + a->e5 * b->e134 
            + a->e134 * b->e5 + a->e13 * b->e45 + a->e14 * b->e35 
            + a->e34 * b->e15 + a->e15 * b->e34 + a->e35 * b->e14 
            + a->e45 * b->e13;
  res.e2345 = c->e2345 + a->r * b->e2345 + a->e2345 * b->r + a->e2 * b->e345 
            + a->e345 * b->e2 + a->e3 * b->e245 + a->e245 * b->e3 
            + a->e4 * b->e235 + a->e235 * b->e4 + a->e5 * b->e234 
            + a->e234 * b->e5 + a->e23 * b->e45 + a->e24 * b->e35 
            + a->e34 * b->e25 + a->e25 * b->e34 + a->e35 * b->e24 
            + a->e45 * b->e23;
  res.e3345 = c->e3345 + a->r * b->e3345 + a->e3345 * b->r + a->e3 * b->e345 
            + a->e345 * b->e3 + a->e4 * b->e335 + a->e335 * b->e4 
            + a->e5 * b->e334 + a->e334 * b->e5 + a->e33 * b->e45 
            + a->e34 * b->e35 + a->e35 * b->e34 + a->e45 * b->e33;
  res.e1445 = c->e1445 + a->r * b->e1445 + a->e1445 * b->r + a->e1 * b->e445 
            + a->e445 * b->e1 + a->e4 * b->e145 + a->e145 * b->e4 
            + a->e5 * b->e144 + a->e144 * b->e5 + a->e14 * b->e45 
            + a->e44 * b->e15 + a->e15 * b->e44 + a->e45 * b->e14;
  res.e2445 = c->e2445 + a->r * b->e2445 + a->e2445 * b->r + a->e2 * b->e445 
            + a->e445 * b->e2 + a->e4 * b->e245 + a->e245 * b->e4 
            + a->e5 * b->e244 + a->e244 * b->e5 + a->e24 * b->e45 
            + a->e44 * b->e25 + a->e25 * b->e44 + a->e45 * b->e24;
  res.e3445 = c->e3445 + a->r * b->e3445 + a->e3445 * b->r + a->e3 * b->e445 
            + a->e445 * b->e3 + a->e4 * b->e345 + a->e345 * b->e4 
            + a->e5 * b->e344 + a->e344 * b->e5 + a->e34 * b->e45 
            + a->e44 * b->e35 + a->e35 * b->e44 + a->e45 * b->e34;
  res.e4445 = c->e4445 + a->r * b->e4445 + a->e4445 * b->r + a->e4 * b->e445 
            + a->e445 * b->e4 + a->e5 * b->e444 + a->e444 * b->e5 
            + a->e44 * b->e45 + a->e45 * b->e44;
  res.e1155 = c->e1155 + a->r * b->e1155 + a->e1155 * b->r + a->e1 * b->e155 
            + a->e155 * b->e1 + a->e5 * b->e115 + a->e115 * b->e5 
            + a->e11 * b->e55 + a->e15 * b->e15 + a->e55 * b->e11;
  res.e1255 = c->e1255 + a->r * b->e1255 + a->e1255 * b->r + a->e1 * b->e255 
            + a->e255 * b->e1 + a->e2 * b->e155 + a->e155 * b->e2 
            + a->e5 * b->e125 + a->e125 * b->e5 + a->e12 * b->e55 
            + a->e15 * b->e25 + a->e25 * b->e15 + a->e55 * b->e12;
  res.e2255 = c->e2255 + a->r * b->e2255 + a->e2255 * b->r + a->e2 * b->e255 
            + a->e255 * b->e2 + a->e5 * b->e225 + a->e225 * b->e5 
            + a->e22 * b->e55 + a->e25 * b->e25 + a->e55 * b->e22;
  res.e1355 = c->e1355 + a->r * b->e1355 + a->e1355 * b->r + a->e1 * b->e355 
            + a->e355 * b->e1 + a->e3 * b->e155 + a->e155 * b->e3 
            + a->e5 * b->e135 + a->e135 * b->e5 + a->e13 * b->e55 
            + a->e15 * b->e35 + a->e35 * b->e15 + a->e55 * b->e13;
  res.e2355 = c->e2355 + a->r * b->e2355 + a->e2355 * b->r + a->e2 * b->e355 
            + a->e355 * b->e2 + a->e3 * b->e255 + a->e255 * b->e3 
            + a->e5 * b->e235 + a->e235 * b->e5 + a->e23 * b->e55 
            + a->e25 * b->e35 + a->e35 * b->e25 + a->e55 * b->e23;
  res.e3355 = c->e3355 + a->r * b->e3355 + a->e3355 * b->r + a->e3 * b->e355 
            + a->e355 * b->e3 + a->e5 * b->e335 + a->e335 * b->e5 
            + a->e33 * b->e55 + a->e35 * b->e35 + a->e55 * b->e33;
  res.e1455 = c->e1455 + a->r * b->e1455 + a->e1455 * b->r + a->e1 * b->e455 
            + a->e455 * b->e1 + a->e4 * b->e155 + a->e155 * b->e4 
            + a->e5 * b->e145 + a->e145 * b->e5 + a->e14 * b->e55 
            + a->e15 * b->e45 + a->e45 * b->e15 + a->e55 * b->e14;
  res.e2455 = c->e2455 + a->r * b->e2455 + a->e2455 * b->r + a->e2 * b->e455 
            + a->e455 * b->e2 + a->e4 * b->e255 + a->e255 * b->e4 
            + a->e5 * b->e245 + a->e245 * b->e5 + a->e24 * b->e55 
            + a->e25 * b->e45 + a->e45 * b->e25 + a->e55 * b->e24;
  res.e3455 = c->e3455 + a->r * b->e3455 + a->e3455 * b->r + a->e3 * b->e455 
            + a->e455 * b->e3 + a->e4 * b->e355 + a->e355 * b->e4 
            + a->e5 * b->e345 + a->e345 * b->e5 + a->e34 * b->e55 
            + a->e35 * b->e45 + a->e45 * b->e35 + a->e55 * b->e34;
  res.e4455 = c->e4455 + a->r * b->e4455 + a->e4455 * b->r + a->e4 * b->e455 
            + a->e455 * b->e4 + a->e5 * b->e445 + a->e445 * b->e5 
            + a->e44 * b->e55 + a->e45 * b->e45 + a->e55 * b->e44;
  res.e1555 = c->e1555 + a->r * b->e1555 + a->e1555 * b->r + a->e1 * b->e555 
            + a->e555 * b->e1 + a->e5 * b->e155 + a->e155 * b->e5 
            + a->e15 * b->e55 + a->e55 * b->e15;
  res.e2555 = c->e2555 + a->r * b->e2555 + a->e2555 * b->r + a->e2 * b->e555 
            + a->e555 * b->e2 + a->e5 * b->e255 + a->e255 * b->e5 
            + a->e25 * b->e55 + a->e55 * b->e25;
  res.e3555 = c->e3555 + a->r * b->e3555 + a->e3555 * b->r + a->e3 * b->e555 
            + a->e555 * b->e3 + a->e5 * b->e355 + a->e355 * b->e5 
            + a->e35 * b->e55 + a->e55 * b->e35;
  res.e4555 = c->e4555 + a->r * b->e4555 + a->e4555 * b->r + a->e4 * b->e555 
            + a->e555 * b->e4 + a->e5 * b->e455 + a->e455 * b->e5 
            + a->e45 * b->e55 + a->e55 * b->e45;
  res.e5555 = c->e5555 + a->r * b->e5555 + a->e5555 * b->r + a->e5 * b->e555 
            + a->e555 * b->e5 + a->e55 * b->e55;
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
  res.e11115 = c->e11115 + a->r * b->e11115 + a->e11115 * b->r + a->e1 * b->e1115 
             + a->e1115 * b->e1 + a->e5 * b->e1111 + a->e1111 * b->e5 
             + a->e11 * b->e115 + a->e115 * b->e11 + a->e15 * b->e111 
             + a->e111 * b->e15;
  res.e11125 = c->e11125 + a->r * b->e11125 + a->e11125 * b->r + a->e1 * b->e1125 
             + a->e1125 * b->e1 + a->e2 * b->e1115 + a->e1115 * b->e2 
             + a->e5 * b->e1112 + a->e1112 * b->e5 + a->e11 * b->e125 
             + a->e125 * b->e11 + a->e12 * b->e115 + a->e115 * b->e12 
             + a->e15 * b->e112 + a->e112 * b->e15 + a->e25 * b->e111 
             + a->e111 * b->e25;
  res.e11225 = c->e11225 + a->r * b->e11225 + a->e11225 * b->r + a->e1 * b->e1225 
             + a->e1225 * b->e1 + a->e2 * b->e1125 + a->e1125 * b->e2 
             + a->e5 * b->e1122 + a->e1122 * b->e5 + a->e11 * b->e225 
             + a->e225 * b->e11 + a->e12 * b->e125 + a->e125 * b->e12 
             + a->e22 * b->e115 + a->e115 * b->e22 + a->e15 * b->e122 
             + a->e122 * b->e15 + a->e25 * b->e112 + a->e112 * b->e25;
  res.e12225 = c->e12225 + a->r * b->e12225 + a->e12225 * b->r + a->e1 * b->e2225 
             + a->e2225 * b->e1 + a->e2 * b->e1225 + a->e1225 * b->e2 
             + a->e5 * b->e1222 + a->e1222 * b->e5 + a->e12 * b->e225 
             + a->e225 * b->e12 + a->e22 * b->e125 + a->e125 * b->e22 
             + a->e15 * b->e222 + a->e222 * b->e15 + a->e25 * b->e122 
             + a->e122 * b->e25;
  res.e22225 = c->e22225 + a->r * b->e22225 + a->e22225 * b->r + a->e2 * b->e2225 
             + a->e2225 * b->e2 + a->e5 * b->e2222 + a->e2222 * b->e5 
             + a->e22 * b->e225 + a->e225 * b->e22 + a->e25 * b->e222 
             + a->e222 * b->e25;
  res.e11135 = c->e11135 + a->r * b->e11135 + a->e11135 * b->r + a->e1 * b->e1135 
             + a->e1135 * b->e1 + a->e3 * b->e1115 + a->e1115 * b->e3 
             + a->e5 * b->e1113 + a->e1113 * b->e5 + a->e11 * b->e135 
             + a->e135 * b->e11 + a->e13 * b->e115 + a->e115 * b->e13 
             + a->e15 * b->e113 + a->e113 * b->e15 + a->e35 * b->e111 
             + a->e111 * b->e35;
  res.e11235 = c->e11235 + a->r * b->e11235 + a->e11235 * b->r + a->e1 * b->e1235 
             + a->e1235 * b->e1 + a->e2 * b->e1135 + a->e1135 * b->e2 
             + a->e3 * b->e1125 + a->e1125 * b->e3 + a->e5 * b->e1123 
             + a->e1123 * b->e5 + a->e11 * b->e235 + a->e235 * b->e11 
             + a->e12 * b->e135 + a->e135 * b->e12 + a->e13 * b->e125 
             + a->e125 * b->e13 + a->e23 * b->e115 + a->e115 * b->e23 
             + a->e15 * b->e123 + a->e123 * b->e15 + a->e25 * b->e113 
             + a->e113 * b->e25 + a->e35 * b->e112 + a->e112 * b->e35;
  res.e12235 = c->e12235 + a->r * b->e12235 + a->e12235 * b->r + a->e1 * b->e2235 
             + a->e2235 * b->e1 + a->e2 * b->e1235 + a->e1235 * b->e2 
             + a->e3 * b->e1225 + a->e1225 * b->e3 + a->e5 * b->e1223 
             + a->e1223 * b->e5 + a->e12 * b->e235 + a->e235 * b->e12 
             + a->e22 * b->e135 + a->e135 * b->e22 + a->e13 * b->e225 
             + a->e225 * b->e13 + a->e23 * b->e125 + a->e125 * b->e23 
             + a->e15 * b->e223 + a->e223 * b->e15 + a->e25 * b->e123 
             + a->e123 * b->e25 + a->e35 * b->e122 + a->e122 * b->e35;
  res.e22235 = c->e22235 + a->r * b->e22235 + a->e22235 * b->r + a->e2 * b->e2235 
             + a->e2235 * b->e2 + a->e3 * b->e2225 + a->e2225 * b->e3 
             + a->e5 * b->e2223 + a->e2223 * b->e5 + a->e22 * b->e235 
             + a->e235 * b->e22 + a->e23 * b->e225 + a->e225 * b->e23 
             + a->e25 * b->e223 + a->e223 * b->e25 + a->e35 * b->e222 
             + a->e222 * b->e35;
  res.e11335 = c->e11335 + a->r * b->e11335 + a->e11335 * b->r + a->e1 * b->e1335 
             + a->e1335 * b->e1 + a->e3 * b->e1135 + a->e1135 * b->e3 
             + a->e5 * b->e1133 + a->e1133 * b->e5 + a->e11 * b->e335 
             + a->e335 * b->e11 + a->e13 * b->e135 + a->e135 * b->e13 
             + a->e33 * b->e115 + a->e115 * b->e33 + a->e15 * b->e133 
             + a->e133 * b->e15 + a->e35 * b->e113 + a->e113 * b->e35;
  res.e12335 = c->e12335 + a->r * b->e12335 + a->e12335 * b->r + a->e1 * b->e2335 
             + a->e2335 * b->e1 + a->e2 * b->e1335 + a->e1335 * b->e2 
             + a->e3 * b->e1235 + a->e1235 * b->e3 + a->e5 * b->e1233 
             + a->e1233 * b->e5 + a->e12 * b->e335 + a->e335 * b->e12 
             + a->e13 * b->e235 + a->e235 * b->e13 + a->e23 * b->e135 
             + a->e135 * b->e23 + a->e33 * b->e125 + a->e125 * b->e33 
             + a->e15 * b->e233 + a->e233 * b->e15 + a->e25 * b->e133 
             + a->e133 * b->e25 + a->e35 * b->e123 + a->e123 * b->e35;
  res.e22335 = c->e22335 + a->r * b->e22335 + a->e22335 * b->r + a->e2 * b->e2335 
             + a->e2335 * b->e2 + a->e3 * b->e2235 + a->e2235 * b->e3 
             + a->e5 * b->e2233 + a->e2233 * b->e5 + a->e22 * b->e335 
             + a->e335 * b->e22 + a->e23 * b->e235 + a->e235 * b->e23 
             + a->e33 * b->e225 + a->e225 * b->e33 + a->e25 * b->e233 
             + a->e233 * b->e25 + a->e35 * b->e223 + a->e223 * b->e35;
  res.e13335 = c->e13335 + a->r * b->e13335 + a->e13335 * b->r + a->e1 * b->e3335 
             + a->e3335 * b->e1 + a->e3 * b->e1335 + a->e1335 * b->e3 
             + a->e5 * b->e1333 + a->e1333 * b->e5 + a->e13 * b->e335 
             + a->e335 * b->e13 + a->e33 * b->e135 + a->e135 * b->e33 
             + a->e15 * b->e333 + a->e333 * b->e15 + a->e35 * b->e133 
             + a->e133 * b->e35;
  res.e23335 = c->e23335 + a->r * b->e23335 + a->e23335 * b->r + a->e2 * b->e3335 
             + a->e3335 * b->e2 + a->e3 * b->e2335 + a->e2335 * b->e3 
             + a->e5 * b->e2333 + a->e2333 * b->e5 + a->e23 * b->e335 
             + a->e335 * b->e23 + a->e33 * b->e235 + a->e235 * b->e33 
             + a->e25 * b->e333 + a->e333 * b->e25 + a->e35 * b->e233 
             + a->e233 * b->e35;
  res.e33335 = c->e33335 + a->r * b->e33335 + a->e33335 * b->r + a->e3 * b->e3335 
             + a->e3335 * b->e3 + a->e5 * b->e3333 + a->e3333 * b->e5 
             + a->e33 * b->e335 + a->e335 * b->e33 + a->e35 * b->e333 
             + a->e333 * b->e35;
  res.e11145 = c->e11145 + a->r * b->e11145 + a->e11145 * b->r + a->e1 * b->e1145 
             + a->e1145 * b->e1 + a->e4 * b->e1115 + a->e1115 * b->e4 
             + a->e5 * b->e1114 + a->e1114 * b->e5 + a->e11 * b->e145 
             + a->e145 * b->e11 + a->e14 * b->e115 + a->e115 * b->e14 
             + a->e15 * b->e114 + a->e114 * b->e15 + a->e45 * b->e111 
             + a->e111 * b->e45;
  res.e11245 = c->e11245 + a->r * b->e11245 + a->e11245 * b->r + a->e1 * b->e1245 
             + a->e1245 * b->e1 + a->e2 * b->e1145 + a->e1145 * b->e2 
             + a->e4 * b->e1125 + a->e1125 * b->e4 + a->e5 * b->e1124 
             + a->e1124 * b->e5 + a->e11 * b->e245 + a->e245 * b->e11 
             + a->e12 * b->e145 + a->e145 * b->e12 + a->e14 * b->e125 
             + a->e125 * b->e14 + a->e24 * b->e115 + a->e115 * b->e24 
             + a->e15 * b->e124 + a->e124 * b->e15 + a->e25 * b->e114 
             + a->e114 * b->e25 + a->e45 * b->e112 + a->e112 * b->e45;
  res.e12245 = c->e12245 + a->r * b->e12245 + a->e12245 * b->r + a->e1 * b->e2245 
             + a->e2245 * b->e1 + a->e2 * b->e1245 + a->e1245 * b->e2 
             + a->e4 * b->e1225 + a->e1225 * b->e4 + a->e5 * b->e1224 
             + a->e1224 * b->e5 + a->e12 * b->e245 + a->e245 * b->e12 
             + a->e22 * b->e145 + a->e145 * b->e22 + a->e14 * b->e225 
             + a->e225 * b->e14 + a->e24 * b->e125 + a->e125 * b->e24 
             + a->e15 * b->e224 + a->e224 * b->e15 + a->e25 * b->e124 
             + a->e124 * b->e25 + a->e45 * b->e122 + a->e122 * b->e45;
  res.e22245 = c->e22245 + a->r * b->e22245 + a->e22245 * b->r + a->e2 * b->e2245 
             + a->e2245 * b->e2 + a->e4 * b->e2225 + a->e2225 * b->e4 
             + a->e5 * b->e2224 + a->e2224 * b->e5 + a->e22 * b->e245 
             + a->e245 * b->e22 + a->e24 * b->e225 + a->e225 * b->e24 
             + a->e25 * b->e224 + a->e224 * b->e25 + a->e45 * b->e222 
             + a->e222 * b->e45;
  res.e11345 = c->e11345 + a->r * b->e11345 + a->e11345 * b->r + a->e1 * b->e1345 
             + a->e1345 * b->e1 + a->e3 * b->e1145 + a->e1145 * b->e3 
             + a->e4 * b->e1135 + a->e1135 * b->e4 + a->e5 * b->e1134 
             + a->e1134 * b->e5 + a->e11 * b->e345 + a->e345 * b->e11 
             + a->e13 * b->e145 + a->e145 * b->e13 + a->e14 * b->e135 
             + a->e135 * b->e14 + a->e34 * b->e115 + a->e115 * b->e34 
             + a->e15 * b->e134 + a->e134 * b->e15 + a->e35 * b->e114 
             + a->e114 * b->e35 + a->e45 * b->e113 + a->e113 * b->e45;
  res.e12345 = c->e12345 + a->r * b->e12345 + a->e12345 * b->r + a->e1 * b->e2345 
             + a->e2345 * b->e1 + a->e2 * b->e1345 + a->e1345 * b->e2 
             + a->e3 * b->e1245 + a->e1245 * b->e3 + a->e4 * b->e1235 
             + a->e1235 * b->e4 + a->e5 * b->e1234 + a->e1234 * b->e5 
             + a->e12 * b->e345 + a->e345 * b->e12 + a->e13 * b->e245 
             + a->e245 * b->e13 + a->e23 * b->e145 + a->e145 * b->e23 
             + a->e14 * b->e235 + a->e235 * b->e14 + a->e24 * b->e135 
             + a->e135 * b->e24 + a->e34 * b->e125 + a->e125 * b->e34 
             + a->e15 * b->e234 + a->e234 * b->e15 + a->e25 * b->e134 
             + a->e134 * b->e25 + a->e35 * b->e124 + a->e124 * b->e35 
             + a->e45 * b->e123 + a->e123 * b->e45;
  res.e22345 = c->e22345 + a->r * b->e22345 + a->e22345 * b->r + a->e2 * b->e2345 
             + a->e2345 * b->e2 + a->e3 * b->e2245 + a->e2245 * b->e3 
             + a->e4 * b->e2235 + a->e2235 * b->e4 + a->e5 * b->e2234 
             + a->e2234 * b->e5 + a->e22 * b->e345 + a->e345 * b->e22 
             + a->e23 * b->e245 + a->e245 * b->e23 + a->e24 * b->e235 
             + a->e235 * b->e24 + a->e34 * b->e225 + a->e225 * b->e34 
             + a->e25 * b->e234 + a->e234 * b->e25 + a->e35 * b->e224 
             + a->e224 * b->e35 + a->e45 * b->e223 + a->e223 * b->e45;
  res.e13345 = c->e13345 + a->r * b->e13345 + a->e13345 * b->r + a->e1 * b->e3345 
             + a->e3345 * b->e1 + a->e3 * b->e1345 + a->e1345 * b->e3 
             + a->e4 * b->e1335 + a->e1335 * b->e4 + a->e5 * b->e1334 
             + a->e1334 * b->e5 + a->e13 * b->e345 + a->e345 * b->e13 
             + a->e33 * b->e145 + a->e145 * b->e33 + a->e14 * b->e335 
             + a->e335 * b->e14 + a->e34 * b->e135 + a->e135 * b->e34 
             + a->e15 * b->e334 + a->e334 * b->e15 + a->e35 * b->e134 
             + a->e134 * b->e35 + a->e45 * b->e133 + a->e133 * b->e45;
  res.e23345 = c->e23345 + a->r * b->e23345 + a->e23345 * b->r + a->e2 * b->e3345 
             + a->e3345 * b->e2 + a->e3 * b->e2345 + a->e2345 * b->e3 
             + a->e4 * b->e2335 + a->e2335 * b->e4 + a->e5 * b->e2334 
             + a->e2334 * b->e5 + a->e23 * b->e345 + a->e345 * b->e23 
             + a->e33 * b->e245 + a->e245 * b->e33 + a->e24 * b->e335 
             + a->e335 * b->e24 + a->e34 * b->e235 + a->e235 * b->e34 
             + a->e25 * b->e334 + a->e334 * b->e25 + a->e35 * b->e234 
             + a->e234 * b->e35 + a->e45 * b->e233 + a->e233 * b->e45;
  res.e33345 = c->e33345 + a->r * b->e33345 + a->e33345 * b->r + a->e3 * b->e3345 
             + a->e3345 * b->e3 + a->e4 * b->e3335 + a->e3335 * b->e4 
             + a->e5 * b->e3334 + a->e3334 * b->e5 + a->e33 * b->e345 
             + a->e345 * b->e33 + a->e34 * b->e335 + a->e335 * b->e34 
             + a->e35 * b->e334 + a->e334 * b->e35 + a->e45 * b->e333 
             + a->e333 * b->e45;
  res.e11445 = c->e11445 + a->r * b->e11445 + a->e11445 * b->r + a->e1 * b->e1445 
             + a->e1445 * b->e1 + a->e4 * b->e1145 + a->e1145 * b->e4 
             + a->e5 * b->e1144 + a->e1144 * b->e5 + a->e11 * b->e445 
             + a->e445 * b->e11 + a->e14 * b->e145 + a->e145 * b->e14 
             + a->e44 * b->e115 + a->e115 * b->e44 + a->e15 * b->e144 
             + a->e144 * b->e15 + a->e45 * b->e114 + a->e114 * b->e45;
  res.e12445 = c->e12445 + a->r * b->e12445 + a->e12445 * b->r + a->e1 * b->e2445 
             + a->e2445 * b->e1 + a->e2 * b->e1445 + a->e1445 * b->e2 
             + a->e4 * b->e1245 + a->e1245 * b->e4 + a->e5 * b->e1244 
             + a->e1244 * b->e5 + a->e12 * b->e445 + a->e445 * b->e12 
             + a->e14 * b->e245 + a->e245 * b->e14 + a->e24 * b->e145 
             + a->e145 * b->e24 + a->e44 * b->e125 + a->e125 * b->e44 
             + a->e15 * b->e244 + a->e244 * b->e15 + a->e25 * b->e144 
             + a->e144 * b->e25 + a->e45 * b->e124 + a->e124 * b->e45;
  res.e22445 = c->e22445 + a->r * b->e22445 + a->e22445 * b->r + a->e2 * b->e2445 
             + a->e2445 * b->e2 + a->e4 * b->e2245 + a->e2245 * b->e4 
             + a->e5 * b->e2244 + a->e2244 * b->e5 + a->e22 * b->e445 
             + a->e445 * b->e22 + a->e24 * b->e245 + a->e245 * b->e24 
             + a->e44 * b->e225 + a->e225 * b->e44 + a->e25 * b->e244 
             + a->e244 * b->e25 + a->e45 * b->e224 + a->e224 * b->e45;
  res.e13445 = c->e13445 + a->r * b->e13445 + a->e13445 * b->r + a->e1 * b->e3445 
             + a->e3445 * b->e1 + a->e3 * b->e1445 + a->e1445 * b->e3 
             + a->e4 * b->e1345 + a->e1345 * b->e4 + a->e5 * b->e1344 
             + a->e1344 * b->e5 + a->e13 * b->e445 + a->e445 * b->e13 
             + a->e14 * b->e345 + a->e345 * b->e14 + a->e34 * b->e145 
             + a->e145 * b->e34 + a->e44 * b->e135 + a->e135 * b->e44 
             + a->e15 * b->e344 + a->e344 * b->e15 + a->e35 * b->e144 
             + a->e144 * b->e35 + a->e45 * b->e134 + a->e134 * b->e45;
  res.e23445 = c->e23445 + a->r * b->e23445 + a->e23445 * b->r + a->e2 * b->e3445 
             + a->e3445 * b->e2 + a->e3 * b->e2445 + a->e2445 * b->e3 
             + a->e4 * b->e2345 + a->e2345 * b->e4 + a->e5 * b->e2344 
             + a->e2344 * b->e5 + a->e23 * b->e445 + a->e445 * b->e23 
             + a->e24 * b->e345 + a->e345 * b->e24 + a->e34 * b->e245 
             + a->e245 * b->e34 + a->e44 * b->e235 + a->e235 * b->e44 
             + a->e25 * b->e344 + a->e344 * b->e25 + a->e35 * b->e244 
             + a->e244 * b->e35 + a->e45 * b->e234 + a->e234 * b->e45;
  res.e33445 = c->e33445 + a->r * b->e33445 + a->e33445 * b->r + a->e3 * b->e3445 
             + a->e3445 * b->e3 + a->e4 * b->e3345 + a->e3345 * b->e4 
             + a->e5 * b->e3344 + a->e3344 * b->e5 + a->e33 * b->e445 
             + a->e445 * b->e33 + a->e34 * b->e345 + a->e345 * b->e34 
             + a->e44 * b->e335 + a->e335 * b->e44 + a->e35 * b->e344 
             + a->e344 * b->e35 + a->e45 * b->e334 + a->e334 * b->e45;
  res.e14445 = c->e14445 + a->r * b->e14445 + a->e14445 * b->r + a->e1 * b->e4445 
             + a->e4445 * b->e1 + a->e4 * b->e1445 + a->e1445 * b->e4 
             + a->e5 * b->e1444 + a->e1444 * b->e5 + a->e14 * b->e445 
             + a->e445 * b->e14 + a->e44 * b->e145 + a->e145 * b->e44 
             + a->e15 * b->e444 + a->e444 * b->e15 + a->e45 * b->e144 
             + a->e144 * b->e45;
  res.e24445 = c->e24445 + a->r * b->e24445 + a->e24445 * b->r + a->e2 * b->e4445 
             + a->e4445 * b->e2 + a->e4 * b->e2445 + a->e2445 * b->e4 
             + a->e5 * b->e2444 + a->e2444 * b->e5 + a->e24 * b->e445 
             + a->e445 * b->e24 + a->e44 * b->e245 + a->e245 * b->e44 
             + a->e25 * b->e444 + a->e444 * b->e25 + a->e45 * b->e244 
             + a->e244 * b->e45;
  res.e34445 = c->e34445 + a->r * b->e34445 + a->e34445 * b->r + a->e3 * b->e4445 
             + a->e4445 * b->e3 + a->e4 * b->e3445 + a->e3445 * b->e4 
             + a->e5 * b->e3444 + a->e3444 * b->e5 + a->e34 * b->e445 
             + a->e445 * b->e34 + a->e44 * b->e345 + a->e345 * b->e44 
             + a->e35 * b->e444 + a->e444 * b->e35 + a->e45 * b->e344 
             + a->e344 * b->e45;
  res.e44445 = c->e44445 + a->r * b->e44445 + a->e44445 * b->r + a->e4 * b->e4445 
             + a->e4445 * b->e4 + a->e5 * b->e4444 + a->e4444 * b->e5 
             + a->e44 * b->e445 + a->e445 * b->e44 + a->e45 * b->e444 
             + a->e444 * b->e45;
  res.e11155 = c->e11155 + a->r * b->e11155 + a->e11155 * b->r + a->e1 * b->e1155 
             + a->e1155 * b->e1 + a->e5 * b->e1115 + a->e1115 * b->e5 
             + a->e11 * b->e155 + a->e155 * b->e11 + a->e15 * b->e115 
             + a->e115 * b->e15 + a->e55 * b->e111 + a->e111 * b->e55;
  res.e11255 = c->e11255 + a->r * b->e11255 + a->e11255 * b->r + a->e1 * b->e1255 
             + a->e1255 * b->e1 + a->e2 * b->e1155 + a->e1155 * b->e2 
             + a->e5 * b->e1125 + a->e1125 * b->e5 + a->e11 * b->e255 
             + a->e255 * b->e11 + a->e12 * b->e155 + a->e155 * b->e12 
             + a->e15 * b->e125 + a->e125 * b->e15 + a->e25 * b->e115 
             + a->e115 * b->e25 + a->e55 * b->e112 + a->e112 * b->e55;
  res.e12255 = c->e12255 + a->r * b->e12255 + a->e12255 * b->r + a->e1 * b->e2255 
             + a->e2255 * b->e1 + a->e2 * b->e1255 + a->e1255 * b->e2 
             + a->e5 * b->e1225 + a->e1225 * b->e5 + a->e12 * b->e255 
             + a->e255 * b->e12 + a->e22 * b->e155 + a->e155 * b->e22 
             + a->e15 * b->e225 + a->e225 * b->e15 + a->e25 * b->e125 
             + a->e125 * b->e25 + a->e55 * b->e122 + a->e122 * b->e55;
  res.e22255 = c->e22255 + a->r * b->e22255 + a->e22255 * b->r + a->e2 * b->e2255 
             + a->e2255 * b->e2 + a->e5 * b->e2225 + a->e2225 * b->e5 
             + a->e22 * b->e255 + a->e255 * b->e22 + a->e25 * b->e225 
             + a->e225 * b->e25 + a->e55 * b->e222 + a->e222 * b->e55;
  res.e11355 = c->e11355 + a->r * b->e11355 + a->e11355 * b->r + a->e1 * b->e1355 
             + a->e1355 * b->e1 + a->e3 * b->e1155 + a->e1155 * b->e3 
             + a->e5 * b->e1135 + a->e1135 * b->e5 + a->e11 * b->e355 
             + a->e355 * b->e11 + a->e13 * b->e155 + a->e155 * b->e13 
             + a->e15 * b->e135 + a->e135 * b->e15 + a->e35 * b->e115 
             + a->e115 * b->e35 + a->e55 * b->e113 + a->e113 * b->e55;
  res.e12355 = c->e12355 + a->r * b->e12355 + a->e12355 * b->r + a->e1 * b->e2355 
             + a->e2355 * b->e1 + a->e2 * b->e1355 + a->e1355 * b->e2 
             + a->e3 * b->e1255 + a->e1255 * b->e3 + a->e5 * b->e1235 
             + a->e1235 * b->e5 + a->e12 * b->e355 + a->e355 * b->e12 
             + a->e13 * b->e255 + a->e255 * b->e13 + a->e23 * b->e155 
             + a->e155 * b->e23 + a->e15 * b->e235 + a->e235 * b->e15 
             + a->e25 * b->e135 + a->e135 * b->e25 + a->e35 * b->e125 
             + a->e125 * b->e35 + a->e55 * b->e123 + a->e123 * b->e55;
  res.e22355 = c->e22355 + a->r * b->e22355 + a->e22355 * b->r + a->e2 * b->e2355 
             + a->e2355 * b->e2 + a->e3 * b->e2255 + a->e2255 * b->e3 
             + a->e5 * b->e2235 + a->e2235 * b->e5 + a->e22 * b->e355 
             + a->e355 * b->e22 + a->e23 * b->e255 + a->e255 * b->e23 
             + a->e25 * b->e235 + a->e235 * b->e25 + a->e35 * b->e225 
             + a->e225 * b->e35 + a->e55 * b->e223 + a->e223 * b->e55;
  res.e13355 = c->e13355 + a->r * b->e13355 + a->e13355 * b->r + a->e1 * b->e3355 
             + a->e3355 * b->e1 + a->e3 * b->e1355 + a->e1355 * b->e3 
             + a->e5 * b->e1335 + a->e1335 * b->e5 + a->e13 * b->e355 
             + a->e355 * b->e13 + a->e33 * b->e155 + a->e155 * b->e33 
             + a->e15 * b->e335 + a->e335 * b->e15 + a->e35 * b->e135 
             + a->e135 * b->e35 + a->e55 * b->e133 + a->e133 * b->e55;
  res.e23355 = c->e23355 + a->r * b->e23355 + a->e23355 * b->r + a->e2 * b->e3355 
             + a->e3355 * b->e2 + a->e3 * b->e2355 + a->e2355 * b->e3 
             + a->e5 * b->e2335 + a->e2335 * b->e5 + a->e23 * b->e355 
             + a->e355 * b->e23 + a->e33 * b->e255 + a->e255 * b->e33 
             + a->e25 * b->e335 + a->e335 * b->e25 + a->e35 * b->e235 
             + a->e235 * b->e35 + a->e55 * b->e233 + a->e233 * b->e55;
  res.e33355 = c->e33355 + a->r * b->e33355 + a->e33355 * b->r + a->e3 * b->e3355 
             + a->e3355 * b->e3 + a->e5 * b->e3335 + a->e3335 * b->e5 
             + a->e33 * b->e355 + a->e355 * b->e33 + a->e35 * b->e335 
             + a->e335 * b->e35 + a->e55 * b->e333 + a->e333 * b->e55;
  res.e11455 = c->e11455 + a->r * b->e11455 + a->e11455 * b->r + a->e1 * b->e1455 
             + a->e1455 * b->e1 + a->e4 * b->e1155 + a->e1155 * b->e4 
             + a->e5 * b->e1145 + a->e1145 * b->e5 + a->e11 * b->e455 
             + a->e455 * b->e11 + a->e14 * b->e155 + a->e155 * b->e14 
             + a->e15 * b->e145 + a->e145 * b->e15 + a->e45 * b->e115 
             + a->e115 * b->e45 + a->e55 * b->e114 + a->e114 * b->e55;
  res.e12455 = c->e12455 + a->r * b->e12455 + a->e12455 * b->r + a->e1 * b->e2455 
             + a->e2455 * b->e1 + a->e2 * b->e1455 + a->e1455 * b->e2 
             + a->e4 * b->e1255 + a->e1255 * b->e4 + a->e5 * b->e1245 
             + a->e1245 * b->e5 + a->e12 * b->e455 + a->e455 * b->e12 
             + a->e14 * b->e255 + a->e255 * b->e14 + a->e24 * b->e155 
             + a->e155 * b->e24 + a->e15 * b->e245 + a->e245 * b->e15 
             + a->e25 * b->e145 + a->e145 * b->e25 + a->e45 * b->e125 
             + a->e125 * b->e45 + a->e55 * b->e124 + a->e124 * b->e55;
  res.e22455 = c->e22455 + a->r * b->e22455 + a->e22455 * b->r + a->e2 * b->e2455 
             + a->e2455 * b->e2 + a->e4 * b->e2255 + a->e2255 * b->e4 
             + a->e5 * b->e2245 + a->e2245 * b->e5 + a->e22 * b->e455 
             + a->e455 * b->e22 + a->e24 * b->e255 + a->e255 * b->e24 
             + a->e25 * b->e245 + a->e245 * b->e25 + a->e45 * b->e225 
             + a->e225 * b->e45 + a->e55 * b->e224 + a->e224 * b->e55;
  res.e13455 = c->e13455 + a->r * b->e13455 + a->e13455 * b->r + a->e1 * b->e3455 
             + a->e3455 * b->e1 + a->e3 * b->e1455 + a->e1455 * b->e3 
             + a->e4 * b->e1355 + a->e1355 * b->e4 + a->e5 * b->e1345 
             + a->e1345 * b->e5 + a->e13 * b->e455 + a->e455 * b->e13 
             + a->e14 * b->e355 + a->e355 * b->e14 + a->e34 * b->e155 
             + a->e155 * b->e34 + a->e15 * b->e345 + a->e345 * b->e15 
             + a->e35 * b->e145 + a->e145 * b->e35 + a->e45 * b->e135 
             + a->e135 * b->e45 + a->e55 * b->e134 + a->e134 * b->e55;
  res.e23455 = c->e23455 + a->r * b->e23455 + a->e23455 * b->r + a->e2 * b->e3455 
             + a->e3455 * b->e2 + a->e3 * b->e2455 + a->e2455 * b->e3 
             + a->e4 * b->e2355 + a->e2355 * b->e4 + a->e5 * b->e2345 
             + a->e2345 * b->e5 + a->e23 * b->e455 + a->e455 * b->e23 
             + a->e24 * b->e355 + a->e355 * b->e24 + a->e34 * b->e255 
             + a->e255 * b->e34 + a->e25 * b->e345 + a->e345 * b->e25 
             + a->e35 * b->e245 + a->e245 * b->e35 + a->e45 * b->e235 
             + a->e235 * b->e45 + a->e55 * b->e234 + a->e234 * b->e55;
  res.e33455 = c->e33455 + a->r * b->e33455 + a->e33455 * b->r + a->e3 * b->e3455 
             + a->e3455 * b->e3 + a->e4 * b->e3355 + a->e3355 * b->e4 
             + a->e5 * b->e3345 + a->e3345 * b->e5 + a->e33 * b->e455 
             + a->e455 * b->e33 + a->e34 * b->e355 + a->e355 * b->e34 
             + a->e35 * b->e345 + a->e345 * b->e35 + a->e45 * b->e335 
             + a->e335 * b->e45 + a->e55 * b->e334 + a->e334 * b->e55;
  res.e14455 = c->e14455 + a->r * b->e14455 + a->e14455 * b->r + a->e1 * b->e4455 
             + a->e4455 * b->e1 + a->e4 * b->e1455 + a->e1455 * b->e4 
             + a->e5 * b->e1445 + a->e1445 * b->e5 + a->e14 * b->e455 
             + a->e455 * b->e14 + a->e44 * b->e155 + a->e155 * b->e44 
             + a->e15 * b->e445 + a->e445 * b->e15 + a->e45 * b->e145 
             + a->e145 * b->e45 + a->e55 * b->e144 + a->e144 * b->e55;
  res.e24455 = c->e24455 + a->r * b->e24455 + a->e24455 * b->r + a->e2 * b->e4455 
             + a->e4455 * b->e2 + a->e4 * b->e2455 + a->e2455 * b->e4 
             + a->e5 * b->e2445 + a->e2445 * b->e5 + a->e24 * b->e455 
             + a->e455 * b->e24 + a->e44 * b->e255 + a->e255 * b->e44 
             + a->e25 * b->e445 + a->e445 * b->e25 + a->e45 * b->e245 
             + a->e245 * b->e45 + a->e55 * b->e244 + a->e244 * b->e55;
  res.e34455 = c->e34455 + a->r * b->e34455 + a->e34455 * b->r + a->e3 * b->e4455 
             + a->e4455 * b->e3 + a->e4 * b->e3455 + a->e3455 * b->e4 
             + a->e5 * b->e3445 + a->e3445 * b->e5 + a->e34 * b->e455 
             + a->e455 * b->e34 + a->e44 * b->e355 + a->e355 * b->e44 
             + a->e35 * b->e445 + a->e445 * b->e35 + a->e45 * b->e345 
             + a->e345 * b->e45 + a->e55 * b->e344 + a->e344 * b->e55;
  res.e44455 = c->e44455 + a->r * b->e44455 + a->e44455 * b->r + a->e4 * b->e4455 
             + a->e4455 * b->e4 + a->e5 * b->e4445 + a->e4445 * b->e5 
             + a->e44 * b->e455 + a->e455 * b->e44 + a->e45 * b->e445 
             + a->e445 * b->e45 + a->e55 * b->e444 + a->e444 * b->e55;
  res.e11555 = c->e11555 + a->r * b->e11555 + a->e11555 * b->r + a->e1 * b->e1555 
             + a->e1555 * b->e1 + a->e5 * b->e1155 + a->e1155 * b->e5 
             + a->e11 * b->e555 + a->e555 * b->e11 + a->e15 * b->e155 
             + a->e155 * b->e15 + a->e55 * b->e115 + a->e115 * b->e55;
  res.e12555 = c->e12555 + a->r * b->e12555 + a->e12555 * b->r + a->e1 * b->e2555 
             + a->e2555 * b->e1 + a->e2 * b->e1555 + a->e1555 * b->e2 
             + a->e5 * b->e1255 + a->e1255 * b->e5 + a->e12 * b->e555 
             + a->e555 * b->e12 + a->e15 * b->e255 + a->e255 * b->e15 
             + a->e25 * b->e155 + a->e155 * b->e25 + a->e55 * b->e125 
             + a->e125 * b->e55;
  res.e22555 = c->e22555 + a->r * b->e22555 + a->e22555 * b->r + a->e2 * b->e2555 
             + a->e2555 * b->e2 + a->e5 * b->e2255 + a->e2255 * b->e5 
             + a->e22 * b->e555 + a->e555 * b->e22 + a->e25 * b->e255 
             + a->e255 * b->e25 + a->e55 * b->e225 + a->e225 * b->e55;
  res.e13555 = c->e13555 + a->r * b->e13555 + a->e13555 * b->r + a->e1 * b->e3555 
             + a->e3555 * b->e1 + a->e3 * b->e1555 + a->e1555 * b->e3 
             + a->e5 * b->e1355 + a->e1355 * b->e5 + a->e13 * b->e555 
             + a->e555 * b->e13 + a->e15 * b->e355 + a->e355 * b->e15 
             + a->e35 * b->e155 + a->e155 * b->e35 + a->e55 * b->e135 
             + a->e135 * b->e55;
  res.e23555 = c->e23555 + a->r * b->e23555 + a->e23555 * b->r + a->e2 * b->e3555 
             + a->e3555 * b->e2 + a->e3 * b->e2555 + a->e2555 * b->e3 
             + a->e5 * b->e2355 + a->e2355 * b->e5 + a->e23 * b->e555 
             + a->e555 * b->e23 + a->e25 * b->e355 + a->e355 * b->e25 
             + a->e35 * b->e255 + a->e255 * b->e35 + a->e55 * b->e235 
             + a->e235 * b->e55;
  res.e33555 = c->e33555 + a->r * b->e33555 + a->e33555 * b->r + a->e3 * b->e3555 
             + a->e3555 * b->e3 + a->e5 * b->e3355 + a->e3355 * b->e5 
             + a->e33 * b->e555 + a->e555 * b->e33 + a->e35 * b->e355 
             + a->e355 * b->e35 + a->e55 * b->e335 + a->e335 * b->e55;
  res.e14555 = c->e14555 + a->r * b->e14555 + a->e14555 * b->r + a->e1 * b->e4555 
             + a->e4555 * b->e1 + a->e4 * b->e1555 + a->e1555 * b->e4 
             + a->e5 * b->e1455 + a->e1455 * b->e5 + a->e14 * b->e555 
             + a->e555 * b->e14 + a->e15 * b->e455 + a->e455 * b->e15 
             + a->e45 * b->e155 + a->e155 * b->e45 + a->e55 * b->e145 
             + a->e145 * b->e55;
  res.e24555 = c->e24555 + a->r * b->e24555 + a->e24555 * b->r + a->e2 * b->e4555 
             + a->e4555 * b->e2 + a->e4 * b->e2555 + a->e2555 * b->e4 
             + a->e5 * b->e2455 + a->e2455 * b->e5 + a->e24 * b->e555 
             + a->e555 * b->e24 + a->e25 * b->e455 + a->e455 * b->e25 
             + a->e45 * b->e255 + a->e255 * b->e45 + a->e55 * b->e245 
             + a->e245 * b->e55;
  res.e34555 = c->e34555 + a->r * b->e34555 + a->e34555 * b->r + a->e3 * b->e4555 
             + a->e4555 * b->e3 + a->e4 * b->e3555 + a->e3555 * b->e4 
             + a->e5 * b->e3455 + a->e3455 * b->e5 + a->e34 * b->e555 
             + a->e555 * b->e34 + a->e35 * b->e455 + a->e455 * b->e35 
             + a->e45 * b->e355 + a->e355 * b->e45 + a->e55 * b->e345 
             + a->e345 * b->e55;
  res.e44555 = c->e44555 + a->r * b->e44555 + a->e44555 * b->r + a->e4 * b->e4555 
             + a->e4555 * b->e4 + a->e5 * b->e4455 + a->e4455 * b->e5 
             + a->e44 * b->e555 + a->e555 * b->e44 + a->e45 * b->e455 
             + a->e455 * b->e45 + a->e55 * b->e445 + a->e445 * b->e55;
  res.e15555 = c->e15555 + a->r * b->e15555 + a->e15555 * b->r + a->e1 * b->e5555 
             + a->e5555 * b->e1 + a->e5 * b->e1555 + a->e1555 * b->e5 
             + a->e15 * b->e555 + a->e555 * b->e15 + a->e55 * b->e155 
             + a->e155 * b->e55;
  res.e25555 = c->e25555 + a->r * b->e25555 + a->e25555 * b->r + a->e2 * b->e5555 
             + a->e5555 * b->e2 + a->e5 * b->e2555 + a->e2555 * b->e5 
             + a->e25 * b->e555 + a->e555 * b->e25 + a->e55 * b->e255 
             + a->e255 * b->e55;
  res.e35555 = c->e35555 + a->r * b->e35555 + a->e35555 * b->r + a->e3 * b->e5555 
             + a->e5555 * b->e3 + a->e5 * b->e3555 + a->e3555 * b->e5 
             + a->e35 * b->e555 + a->e555 * b->e35 + a->e55 * b->e355 
             + a->e355 * b->e55;
  res.e45555 = c->e45555 + a->r * b->e45555 + a->e45555 * b->r + a->e4 * b->e5555 
             + a->e5555 * b->e4 + a->e5 * b->e4555 + a->e4555 * b->e5 
             + a->e45 * b->e555 + a->e555 * b->e45 + a->e55 * b->e455 
             + a->e455 * b->e55;
  res.e55555 = c->e55555 + a->r * b->e55555 + a->e55555 * b->r + a->e5 * b->e5555 
             + a->e5555 * b->e5 + a->e55 * b->e555 + a->e555 * b->e55;

  return res;

}

void onumm5n5_gem_oo_to(  onumm5n5_t* a,  onumm5n5_t* b,  onumm5n5_t* c, onumm5n5_t* res){
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
  res->e1115 = c->e1115 + a->r * b->e1115 + a->e1115 * b->r + a->e1 * b->e115 
            + a->e115 * b->e1 + a->e5 * b->e111 + a->e111 * b->e5 
            + a->e11 * b->e15 + a->e15 * b->e11;
  res->e1125 = c->e1125 + a->r * b->e1125 + a->e1125 * b->r + a->e1 * b->e125 
            + a->e125 * b->e1 + a->e2 * b->e115 + a->e115 * b->e2 
            + a->e5 * b->e112 + a->e112 * b->e5 + a->e11 * b->e25 
            + a->e12 * b->e15 + a->e15 * b->e12 + a->e25 * b->e11;
  res->e1225 = c->e1225 + a->r * b->e1225 + a->e1225 * b->r + a->e1 * b->e225 
            + a->e225 * b->e1 + a->e2 * b->e125 + a->e125 * b->e2 
            + a->e5 * b->e122 + a->e122 * b->e5 + a->e12 * b->e25 
            + a->e22 * b->e15 + a->e15 * b->e22 + a->e25 * b->e12;
  res->e2225 = c->e2225 + a->r * b->e2225 + a->e2225 * b->r + a->e2 * b->e225 
            + a->e225 * b->e2 + a->e5 * b->e222 + a->e222 * b->e5 
            + a->e22 * b->e25 + a->e25 * b->e22;
  res->e1135 = c->e1135 + a->r * b->e1135 + a->e1135 * b->r + a->e1 * b->e135 
            + a->e135 * b->e1 + a->e3 * b->e115 + a->e115 * b->e3 
            + a->e5 * b->e113 + a->e113 * b->e5 + a->e11 * b->e35 
            + a->e13 * b->e15 + a->e15 * b->e13 + a->e35 * b->e11;
  res->e1235 = c->e1235 + a->r * b->e1235 + a->e1235 * b->r + a->e1 * b->e235 
            + a->e235 * b->e1 + a->e2 * b->e135 + a->e135 * b->e2 
            + a->e3 * b->e125 + a->e125 * b->e3 + a->e5 * b->e123 
            + a->e123 * b->e5 + a->e12 * b->e35 + a->e13 * b->e25 
            + a->e23 * b->e15 + a->e15 * b->e23 + a->e25 * b->e13 
            + a->e35 * b->e12;
  res->e2235 = c->e2235 + a->r * b->e2235 + a->e2235 * b->r + a->e2 * b->e235 
            + a->e235 * b->e2 + a->e3 * b->e225 + a->e225 * b->e3 
            + a->e5 * b->e223 + a->e223 * b->e5 + a->e22 * b->e35 
            + a->e23 * b->e25 + a->e25 * b->e23 + a->e35 * b->e22;
  res->e1335 = c->e1335 + a->r * b->e1335 + a->e1335 * b->r + a->e1 * b->e335 
            + a->e335 * b->e1 + a->e3 * b->e135 + a->e135 * b->e3 
            + a->e5 * b->e133 + a->e133 * b->e5 + a->e13 * b->e35 
            + a->e33 * b->e15 + a->e15 * b->e33 + a->e35 * b->e13;
  res->e2335 = c->e2335 + a->r * b->e2335 + a->e2335 * b->r + a->e2 * b->e335 
            + a->e335 * b->e2 + a->e3 * b->e235 + a->e235 * b->e3 
            + a->e5 * b->e233 + a->e233 * b->e5 + a->e23 * b->e35 
            + a->e33 * b->e25 + a->e25 * b->e33 + a->e35 * b->e23;
  res->e3335 = c->e3335 + a->r * b->e3335 + a->e3335 * b->r + a->e3 * b->e335 
            + a->e335 * b->e3 + a->e5 * b->e333 + a->e333 * b->e5 
            + a->e33 * b->e35 + a->e35 * b->e33;
  res->e1145 = c->e1145 + a->r * b->e1145 + a->e1145 * b->r + a->e1 * b->e145 
            + a->e145 * b->e1 + a->e4 * b->e115 + a->e115 * b->e4 
            + a->e5 * b->e114 + a->e114 * b->e5 + a->e11 * b->e45 
            + a->e14 * b->e15 + a->e15 * b->e14 + a->e45 * b->e11;
  res->e1245 = c->e1245 + a->r * b->e1245 + a->e1245 * b->r + a->e1 * b->e245 
            + a->e245 * b->e1 + a->e2 * b->e145 + a->e145 * b->e2 
            + a->e4 * b->e125 + a->e125 * b->e4 + a->e5 * b->e124 
            + a->e124 * b->e5 + a->e12 * b->e45 + a->e14 * b->e25 
            + a->e24 * b->e15 + a->e15 * b->e24 + a->e25 * b->e14 
            + a->e45 * b->e12;
  res->e2245 = c->e2245 + a->r * b->e2245 + a->e2245 * b->r + a->e2 * b->e245 
            + a->e245 * b->e2 + a->e4 * b->e225 + a->e225 * b->e4 
            + a->e5 * b->e224 + a->e224 * b->e5 + a->e22 * b->e45 
            + a->e24 * b->e25 + a->e25 * b->e24 + a->e45 * b->e22;
  res->e1345 = c->e1345 + a->r * b->e1345 + a->e1345 * b->r + a->e1 * b->e345 
            + a->e345 * b->e1 + a->e3 * b->e145 + a->e145 * b->e3 
            + a->e4 * b->e135 + a->e135 * b->e4 + a->e5 * b->e134 
            + a->e134 * b->e5 + a->e13 * b->e45 + a->e14 * b->e35 
            + a->e34 * b->e15 + a->e15 * b->e34 + a->e35 * b->e14 
            + a->e45 * b->e13;
  res->e2345 = c->e2345 + a->r * b->e2345 + a->e2345 * b->r + a->e2 * b->e345 
            + a->e345 * b->e2 + a->e3 * b->e245 + a->e245 * b->e3 
            + a->e4 * b->e235 + a->e235 * b->e4 + a->e5 * b->e234 
            + a->e234 * b->e5 + a->e23 * b->e45 + a->e24 * b->e35 
            + a->e34 * b->e25 + a->e25 * b->e34 + a->e35 * b->e24 
            + a->e45 * b->e23;
  res->e3345 = c->e3345 + a->r * b->e3345 + a->e3345 * b->r + a->e3 * b->e345 
            + a->e345 * b->e3 + a->e4 * b->e335 + a->e335 * b->e4 
            + a->e5 * b->e334 + a->e334 * b->e5 + a->e33 * b->e45 
            + a->e34 * b->e35 + a->e35 * b->e34 + a->e45 * b->e33;
  res->e1445 = c->e1445 + a->r * b->e1445 + a->e1445 * b->r + a->e1 * b->e445 
            + a->e445 * b->e1 + a->e4 * b->e145 + a->e145 * b->e4 
            + a->e5 * b->e144 + a->e144 * b->e5 + a->e14 * b->e45 
            + a->e44 * b->e15 + a->e15 * b->e44 + a->e45 * b->e14;
  res->e2445 = c->e2445 + a->r * b->e2445 + a->e2445 * b->r + a->e2 * b->e445 
            + a->e445 * b->e2 + a->e4 * b->e245 + a->e245 * b->e4 
            + a->e5 * b->e244 + a->e244 * b->e5 + a->e24 * b->e45 
            + a->e44 * b->e25 + a->e25 * b->e44 + a->e45 * b->e24;
  res->e3445 = c->e3445 + a->r * b->e3445 + a->e3445 * b->r + a->e3 * b->e445 
            + a->e445 * b->e3 + a->e4 * b->e345 + a->e345 * b->e4 
            + a->e5 * b->e344 + a->e344 * b->e5 + a->e34 * b->e45 
            + a->e44 * b->e35 + a->e35 * b->e44 + a->e45 * b->e34;
  res->e4445 = c->e4445 + a->r * b->e4445 + a->e4445 * b->r + a->e4 * b->e445 
            + a->e445 * b->e4 + a->e5 * b->e444 + a->e444 * b->e5 
            + a->e44 * b->e45 + a->e45 * b->e44;
  res->e1155 = c->e1155 + a->r * b->e1155 + a->e1155 * b->r + a->e1 * b->e155 
            + a->e155 * b->e1 + a->e5 * b->e115 + a->e115 * b->e5 
            + a->e11 * b->e55 + a->e15 * b->e15 + a->e55 * b->e11;
  res->e1255 = c->e1255 + a->r * b->e1255 + a->e1255 * b->r + a->e1 * b->e255 
            + a->e255 * b->e1 + a->e2 * b->e155 + a->e155 * b->e2 
            + a->e5 * b->e125 + a->e125 * b->e5 + a->e12 * b->e55 
            + a->e15 * b->e25 + a->e25 * b->e15 + a->e55 * b->e12;
  res->e2255 = c->e2255 + a->r * b->e2255 + a->e2255 * b->r + a->e2 * b->e255 
            + a->e255 * b->e2 + a->e5 * b->e225 + a->e225 * b->e5 
            + a->e22 * b->e55 + a->e25 * b->e25 + a->e55 * b->e22;
  res->e1355 = c->e1355 + a->r * b->e1355 + a->e1355 * b->r + a->e1 * b->e355 
            + a->e355 * b->e1 + a->e3 * b->e155 + a->e155 * b->e3 
            + a->e5 * b->e135 + a->e135 * b->e5 + a->e13 * b->e55 
            + a->e15 * b->e35 + a->e35 * b->e15 + a->e55 * b->e13;
  res->e2355 = c->e2355 + a->r * b->e2355 + a->e2355 * b->r + a->e2 * b->e355 
            + a->e355 * b->e2 + a->e3 * b->e255 + a->e255 * b->e3 
            + a->e5 * b->e235 + a->e235 * b->e5 + a->e23 * b->e55 
            + a->e25 * b->e35 + a->e35 * b->e25 + a->e55 * b->e23;
  res->e3355 = c->e3355 + a->r * b->e3355 + a->e3355 * b->r + a->e3 * b->e355 
            + a->e355 * b->e3 + a->e5 * b->e335 + a->e335 * b->e5 
            + a->e33 * b->e55 + a->e35 * b->e35 + a->e55 * b->e33;
  res->e1455 = c->e1455 + a->r * b->e1455 + a->e1455 * b->r + a->e1 * b->e455 
            + a->e455 * b->e1 + a->e4 * b->e155 + a->e155 * b->e4 
            + a->e5 * b->e145 + a->e145 * b->e5 + a->e14 * b->e55 
            + a->e15 * b->e45 + a->e45 * b->e15 + a->e55 * b->e14;
  res->e2455 = c->e2455 + a->r * b->e2455 + a->e2455 * b->r + a->e2 * b->e455 
            + a->e455 * b->e2 + a->e4 * b->e255 + a->e255 * b->e4 
            + a->e5 * b->e245 + a->e245 * b->e5 + a->e24 * b->e55 
            + a->e25 * b->e45 + a->e45 * b->e25 + a->e55 * b->e24;
  res->e3455 = c->e3455 + a->r * b->e3455 + a->e3455 * b->r + a->e3 * b->e455 
            + a->e455 * b->e3 + a->e4 * b->e355 + a->e355 * b->e4 
            + a->e5 * b->e345 + a->e345 * b->e5 + a->e34 * b->e55 
            + a->e35 * b->e45 + a->e45 * b->e35 + a->e55 * b->e34;
  res->e4455 = c->e4455 + a->r * b->e4455 + a->e4455 * b->r + a->e4 * b->e455 
            + a->e455 * b->e4 + a->e5 * b->e445 + a->e445 * b->e5 
            + a->e44 * b->e55 + a->e45 * b->e45 + a->e55 * b->e44;
  res->e1555 = c->e1555 + a->r * b->e1555 + a->e1555 * b->r + a->e1 * b->e555 
            + a->e555 * b->e1 + a->e5 * b->e155 + a->e155 * b->e5 
            + a->e15 * b->e55 + a->e55 * b->e15;
  res->e2555 = c->e2555 + a->r * b->e2555 + a->e2555 * b->r + a->e2 * b->e555 
            + a->e555 * b->e2 + a->e5 * b->e255 + a->e255 * b->e5 
            + a->e25 * b->e55 + a->e55 * b->e25;
  res->e3555 = c->e3555 + a->r * b->e3555 + a->e3555 * b->r + a->e3 * b->e555 
            + a->e555 * b->e3 + a->e5 * b->e355 + a->e355 * b->e5 
            + a->e35 * b->e55 + a->e55 * b->e35;
  res->e4555 = c->e4555 + a->r * b->e4555 + a->e4555 * b->r + a->e4 * b->e555 
            + a->e555 * b->e4 + a->e5 * b->e455 + a->e455 * b->e5 
            + a->e45 * b->e55 + a->e55 * b->e45;
  res->e5555 = c->e5555 + a->r * b->e5555 + a->e5555 * b->r + a->e5 * b->e555 
            + a->e555 * b->e5 + a->e55 * b->e55;
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
  res->e11115 = c->e11115 + a->r * b->e11115 + a->e11115 * b->r + a->e1 * b->e1115 
             + a->e1115 * b->e1 + a->e5 * b->e1111 + a->e1111 * b->e5 
             + a->e11 * b->e115 + a->e115 * b->e11 + a->e15 * b->e111 
             + a->e111 * b->e15;
  res->e11125 = c->e11125 + a->r * b->e11125 + a->e11125 * b->r + a->e1 * b->e1125 
             + a->e1125 * b->e1 + a->e2 * b->e1115 + a->e1115 * b->e2 
             + a->e5 * b->e1112 + a->e1112 * b->e5 + a->e11 * b->e125 
             + a->e125 * b->e11 + a->e12 * b->e115 + a->e115 * b->e12 
             + a->e15 * b->e112 + a->e112 * b->e15 + a->e25 * b->e111 
             + a->e111 * b->e25;
  res->e11225 = c->e11225 + a->r * b->e11225 + a->e11225 * b->r + a->e1 * b->e1225 
             + a->e1225 * b->e1 + a->e2 * b->e1125 + a->e1125 * b->e2 
             + a->e5 * b->e1122 + a->e1122 * b->e5 + a->e11 * b->e225 
             + a->e225 * b->e11 + a->e12 * b->e125 + a->e125 * b->e12 
             + a->e22 * b->e115 + a->e115 * b->e22 + a->e15 * b->e122 
             + a->e122 * b->e15 + a->e25 * b->e112 + a->e112 * b->e25;
  res->e12225 = c->e12225 + a->r * b->e12225 + a->e12225 * b->r + a->e1 * b->e2225 
             + a->e2225 * b->e1 + a->e2 * b->e1225 + a->e1225 * b->e2 
             + a->e5 * b->e1222 + a->e1222 * b->e5 + a->e12 * b->e225 
             + a->e225 * b->e12 + a->e22 * b->e125 + a->e125 * b->e22 
             + a->e15 * b->e222 + a->e222 * b->e15 + a->e25 * b->e122 
             + a->e122 * b->e25;
  res->e22225 = c->e22225 + a->r * b->e22225 + a->e22225 * b->r + a->e2 * b->e2225 
             + a->e2225 * b->e2 + a->e5 * b->e2222 + a->e2222 * b->e5 
             + a->e22 * b->e225 + a->e225 * b->e22 + a->e25 * b->e222 
             + a->e222 * b->e25;
  res->e11135 = c->e11135 + a->r * b->e11135 + a->e11135 * b->r + a->e1 * b->e1135 
             + a->e1135 * b->e1 + a->e3 * b->e1115 + a->e1115 * b->e3 
             + a->e5 * b->e1113 + a->e1113 * b->e5 + a->e11 * b->e135 
             + a->e135 * b->e11 + a->e13 * b->e115 + a->e115 * b->e13 
             + a->e15 * b->e113 + a->e113 * b->e15 + a->e35 * b->e111 
             + a->e111 * b->e35;
  res->e11235 = c->e11235 + a->r * b->e11235 + a->e11235 * b->r + a->e1 * b->e1235 
             + a->e1235 * b->e1 + a->e2 * b->e1135 + a->e1135 * b->e2 
             + a->e3 * b->e1125 + a->e1125 * b->e3 + a->e5 * b->e1123 
             + a->e1123 * b->e5 + a->e11 * b->e235 + a->e235 * b->e11 
             + a->e12 * b->e135 + a->e135 * b->e12 + a->e13 * b->e125 
             + a->e125 * b->e13 + a->e23 * b->e115 + a->e115 * b->e23 
             + a->e15 * b->e123 + a->e123 * b->e15 + a->e25 * b->e113 
             + a->e113 * b->e25 + a->e35 * b->e112 + a->e112 * b->e35;
  res->e12235 = c->e12235 + a->r * b->e12235 + a->e12235 * b->r + a->e1 * b->e2235 
             + a->e2235 * b->e1 + a->e2 * b->e1235 + a->e1235 * b->e2 
             + a->e3 * b->e1225 + a->e1225 * b->e3 + a->e5 * b->e1223 
             + a->e1223 * b->e5 + a->e12 * b->e235 + a->e235 * b->e12 
             + a->e22 * b->e135 + a->e135 * b->e22 + a->e13 * b->e225 
             + a->e225 * b->e13 + a->e23 * b->e125 + a->e125 * b->e23 
             + a->e15 * b->e223 + a->e223 * b->e15 + a->e25 * b->e123 
             + a->e123 * b->e25 + a->e35 * b->e122 + a->e122 * b->e35;
  res->e22235 = c->e22235 + a->r * b->e22235 + a->e22235 * b->r + a->e2 * b->e2235 
             + a->e2235 * b->e2 + a->e3 * b->e2225 + a->e2225 * b->e3 
             + a->e5 * b->e2223 + a->e2223 * b->e5 + a->e22 * b->e235 
             + a->e235 * b->e22 + a->e23 * b->e225 + a->e225 * b->e23 
             + a->e25 * b->e223 + a->e223 * b->e25 + a->e35 * b->e222 
             + a->e222 * b->e35;
  res->e11335 = c->e11335 + a->r * b->e11335 + a->e11335 * b->r + a->e1 * b->e1335 
             + a->e1335 * b->e1 + a->e3 * b->e1135 + a->e1135 * b->e3 
             + a->e5 * b->e1133 + a->e1133 * b->e5 + a->e11 * b->e335 
             + a->e335 * b->e11 + a->e13 * b->e135 + a->e135 * b->e13 
             + a->e33 * b->e115 + a->e115 * b->e33 + a->e15 * b->e133 
             + a->e133 * b->e15 + a->e35 * b->e113 + a->e113 * b->e35;
  res->e12335 = c->e12335 + a->r * b->e12335 + a->e12335 * b->r + a->e1 * b->e2335 
             + a->e2335 * b->e1 + a->e2 * b->e1335 + a->e1335 * b->e2 
             + a->e3 * b->e1235 + a->e1235 * b->e3 + a->e5 * b->e1233 
             + a->e1233 * b->e5 + a->e12 * b->e335 + a->e335 * b->e12 
             + a->e13 * b->e235 + a->e235 * b->e13 + a->e23 * b->e135 
             + a->e135 * b->e23 + a->e33 * b->e125 + a->e125 * b->e33 
             + a->e15 * b->e233 + a->e233 * b->e15 + a->e25 * b->e133 
             + a->e133 * b->e25 + a->e35 * b->e123 + a->e123 * b->e35;
  res->e22335 = c->e22335 + a->r * b->e22335 + a->e22335 * b->r + a->e2 * b->e2335 
             + a->e2335 * b->e2 + a->e3 * b->e2235 + a->e2235 * b->e3 
             + a->e5 * b->e2233 + a->e2233 * b->e5 + a->e22 * b->e335 
             + a->e335 * b->e22 + a->e23 * b->e235 + a->e235 * b->e23 
             + a->e33 * b->e225 + a->e225 * b->e33 + a->e25 * b->e233 
             + a->e233 * b->e25 + a->e35 * b->e223 + a->e223 * b->e35;
  res->e13335 = c->e13335 + a->r * b->e13335 + a->e13335 * b->r + a->e1 * b->e3335 
             + a->e3335 * b->e1 + a->e3 * b->e1335 + a->e1335 * b->e3 
             + a->e5 * b->e1333 + a->e1333 * b->e5 + a->e13 * b->e335 
             + a->e335 * b->e13 + a->e33 * b->e135 + a->e135 * b->e33 
             + a->e15 * b->e333 + a->e333 * b->e15 + a->e35 * b->e133 
             + a->e133 * b->e35;
  res->e23335 = c->e23335 + a->r * b->e23335 + a->e23335 * b->r + a->e2 * b->e3335 
             + a->e3335 * b->e2 + a->e3 * b->e2335 + a->e2335 * b->e3 
             + a->e5 * b->e2333 + a->e2333 * b->e5 + a->e23 * b->e335 
             + a->e335 * b->e23 + a->e33 * b->e235 + a->e235 * b->e33 
             + a->e25 * b->e333 + a->e333 * b->e25 + a->e35 * b->e233 
             + a->e233 * b->e35;
  res->e33335 = c->e33335 + a->r * b->e33335 + a->e33335 * b->r + a->e3 * b->e3335 
             + a->e3335 * b->e3 + a->e5 * b->e3333 + a->e3333 * b->e5 
             + a->e33 * b->e335 + a->e335 * b->e33 + a->e35 * b->e333 
             + a->e333 * b->e35;
  res->e11145 = c->e11145 + a->r * b->e11145 + a->e11145 * b->r + a->e1 * b->e1145 
             + a->e1145 * b->e1 + a->e4 * b->e1115 + a->e1115 * b->e4 
             + a->e5 * b->e1114 + a->e1114 * b->e5 + a->e11 * b->e145 
             + a->e145 * b->e11 + a->e14 * b->e115 + a->e115 * b->e14 
             + a->e15 * b->e114 + a->e114 * b->e15 + a->e45 * b->e111 
             + a->e111 * b->e45;
  res->e11245 = c->e11245 + a->r * b->e11245 + a->e11245 * b->r + a->e1 * b->e1245 
             + a->e1245 * b->e1 + a->e2 * b->e1145 + a->e1145 * b->e2 
             + a->e4 * b->e1125 + a->e1125 * b->e4 + a->e5 * b->e1124 
             + a->e1124 * b->e5 + a->e11 * b->e245 + a->e245 * b->e11 
             + a->e12 * b->e145 + a->e145 * b->e12 + a->e14 * b->e125 
             + a->e125 * b->e14 + a->e24 * b->e115 + a->e115 * b->e24 
             + a->e15 * b->e124 + a->e124 * b->e15 + a->e25 * b->e114 
             + a->e114 * b->e25 + a->e45 * b->e112 + a->e112 * b->e45;
  res->e12245 = c->e12245 + a->r * b->e12245 + a->e12245 * b->r + a->e1 * b->e2245 
             + a->e2245 * b->e1 + a->e2 * b->e1245 + a->e1245 * b->e2 
             + a->e4 * b->e1225 + a->e1225 * b->e4 + a->e5 * b->e1224 
             + a->e1224 * b->e5 + a->e12 * b->e245 + a->e245 * b->e12 
             + a->e22 * b->e145 + a->e145 * b->e22 + a->e14 * b->e225 
             + a->e225 * b->e14 + a->e24 * b->e125 + a->e125 * b->e24 
             + a->e15 * b->e224 + a->e224 * b->e15 + a->e25 * b->e124 
             + a->e124 * b->e25 + a->e45 * b->e122 + a->e122 * b->e45;
  res->e22245 = c->e22245 + a->r * b->e22245 + a->e22245 * b->r + a->e2 * b->e2245 
             + a->e2245 * b->e2 + a->e4 * b->e2225 + a->e2225 * b->e4 
             + a->e5 * b->e2224 + a->e2224 * b->e5 + a->e22 * b->e245 
             + a->e245 * b->e22 + a->e24 * b->e225 + a->e225 * b->e24 
             + a->e25 * b->e224 + a->e224 * b->e25 + a->e45 * b->e222 
             + a->e222 * b->e45;
  res->e11345 = c->e11345 + a->r * b->e11345 + a->e11345 * b->r + a->e1 * b->e1345 
             + a->e1345 * b->e1 + a->e3 * b->e1145 + a->e1145 * b->e3 
             + a->e4 * b->e1135 + a->e1135 * b->e4 + a->e5 * b->e1134 
             + a->e1134 * b->e5 + a->e11 * b->e345 + a->e345 * b->e11 
             + a->e13 * b->e145 + a->e145 * b->e13 + a->e14 * b->e135 
             + a->e135 * b->e14 + a->e34 * b->e115 + a->e115 * b->e34 
             + a->e15 * b->e134 + a->e134 * b->e15 + a->e35 * b->e114 
             + a->e114 * b->e35 + a->e45 * b->e113 + a->e113 * b->e45;
  res->e12345 = c->e12345 + a->r * b->e12345 + a->e12345 * b->r + a->e1 * b->e2345 
             + a->e2345 * b->e1 + a->e2 * b->e1345 + a->e1345 * b->e2 
             + a->e3 * b->e1245 + a->e1245 * b->e3 + a->e4 * b->e1235 
             + a->e1235 * b->e4 + a->e5 * b->e1234 + a->e1234 * b->e5 
             + a->e12 * b->e345 + a->e345 * b->e12 + a->e13 * b->e245 
             + a->e245 * b->e13 + a->e23 * b->e145 + a->e145 * b->e23 
             + a->e14 * b->e235 + a->e235 * b->e14 + a->e24 * b->e135 
             + a->e135 * b->e24 + a->e34 * b->e125 + a->e125 * b->e34 
             + a->e15 * b->e234 + a->e234 * b->e15 + a->e25 * b->e134 
             + a->e134 * b->e25 + a->e35 * b->e124 + a->e124 * b->e35 
             + a->e45 * b->e123 + a->e123 * b->e45;
  res->e22345 = c->e22345 + a->r * b->e22345 + a->e22345 * b->r + a->e2 * b->e2345 
             + a->e2345 * b->e2 + a->e3 * b->e2245 + a->e2245 * b->e3 
             + a->e4 * b->e2235 + a->e2235 * b->e4 + a->e5 * b->e2234 
             + a->e2234 * b->e5 + a->e22 * b->e345 + a->e345 * b->e22 
             + a->e23 * b->e245 + a->e245 * b->e23 + a->e24 * b->e235 
             + a->e235 * b->e24 + a->e34 * b->e225 + a->e225 * b->e34 
             + a->e25 * b->e234 + a->e234 * b->e25 + a->e35 * b->e224 
             + a->e224 * b->e35 + a->e45 * b->e223 + a->e223 * b->e45;
  res->e13345 = c->e13345 + a->r * b->e13345 + a->e13345 * b->r + a->e1 * b->e3345 
             + a->e3345 * b->e1 + a->e3 * b->e1345 + a->e1345 * b->e3 
             + a->e4 * b->e1335 + a->e1335 * b->e4 + a->e5 * b->e1334 
             + a->e1334 * b->e5 + a->e13 * b->e345 + a->e345 * b->e13 
             + a->e33 * b->e145 + a->e145 * b->e33 + a->e14 * b->e335 
             + a->e335 * b->e14 + a->e34 * b->e135 + a->e135 * b->e34 
             + a->e15 * b->e334 + a->e334 * b->e15 + a->e35 * b->e134 
             + a->e134 * b->e35 + a->e45 * b->e133 + a->e133 * b->e45;
  res->e23345 = c->e23345 + a->r * b->e23345 + a->e23345 * b->r + a->e2 * b->e3345 
             + a->e3345 * b->e2 + a->e3 * b->e2345 + a->e2345 * b->e3 
             + a->e4 * b->e2335 + a->e2335 * b->e4 + a->e5 * b->e2334 
             + a->e2334 * b->e5 + a->e23 * b->e345 + a->e345 * b->e23 
             + a->e33 * b->e245 + a->e245 * b->e33 + a->e24 * b->e335 
             + a->e335 * b->e24 + a->e34 * b->e235 + a->e235 * b->e34 
             + a->e25 * b->e334 + a->e334 * b->e25 + a->e35 * b->e234 
             + a->e234 * b->e35 + a->e45 * b->e233 + a->e233 * b->e45;
  res->e33345 = c->e33345 + a->r * b->e33345 + a->e33345 * b->r + a->e3 * b->e3345 
             + a->e3345 * b->e3 + a->e4 * b->e3335 + a->e3335 * b->e4 
             + a->e5 * b->e3334 + a->e3334 * b->e5 + a->e33 * b->e345 
             + a->e345 * b->e33 + a->e34 * b->e335 + a->e335 * b->e34 
             + a->e35 * b->e334 + a->e334 * b->e35 + a->e45 * b->e333 
             + a->e333 * b->e45;
  res->e11445 = c->e11445 + a->r * b->e11445 + a->e11445 * b->r + a->e1 * b->e1445 
             + a->e1445 * b->e1 + a->e4 * b->e1145 + a->e1145 * b->e4 
             + a->e5 * b->e1144 + a->e1144 * b->e5 + a->e11 * b->e445 
             + a->e445 * b->e11 + a->e14 * b->e145 + a->e145 * b->e14 
             + a->e44 * b->e115 + a->e115 * b->e44 + a->e15 * b->e144 
             + a->e144 * b->e15 + a->e45 * b->e114 + a->e114 * b->e45;
  res->e12445 = c->e12445 + a->r * b->e12445 + a->e12445 * b->r + a->e1 * b->e2445 
             + a->e2445 * b->e1 + a->e2 * b->e1445 + a->e1445 * b->e2 
             + a->e4 * b->e1245 + a->e1245 * b->e4 + a->e5 * b->e1244 
             + a->e1244 * b->e5 + a->e12 * b->e445 + a->e445 * b->e12 
             + a->e14 * b->e245 + a->e245 * b->e14 + a->e24 * b->e145 
             + a->e145 * b->e24 + a->e44 * b->e125 + a->e125 * b->e44 
             + a->e15 * b->e244 + a->e244 * b->e15 + a->e25 * b->e144 
             + a->e144 * b->e25 + a->e45 * b->e124 + a->e124 * b->e45;
  res->e22445 = c->e22445 + a->r * b->e22445 + a->e22445 * b->r + a->e2 * b->e2445 
             + a->e2445 * b->e2 + a->e4 * b->e2245 + a->e2245 * b->e4 
             + a->e5 * b->e2244 + a->e2244 * b->e5 + a->e22 * b->e445 
             + a->e445 * b->e22 + a->e24 * b->e245 + a->e245 * b->e24 
             + a->e44 * b->e225 + a->e225 * b->e44 + a->e25 * b->e244 
             + a->e244 * b->e25 + a->e45 * b->e224 + a->e224 * b->e45;
  res->e13445 = c->e13445 + a->r * b->e13445 + a->e13445 * b->r + a->e1 * b->e3445 
             + a->e3445 * b->e1 + a->e3 * b->e1445 + a->e1445 * b->e3 
             + a->e4 * b->e1345 + a->e1345 * b->e4 + a->e5 * b->e1344 
             + a->e1344 * b->e5 + a->e13 * b->e445 + a->e445 * b->e13 
             + a->e14 * b->e345 + a->e345 * b->e14 + a->e34 * b->e145 
             + a->e145 * b->e34 + a->e44 * b->e135 + a->e135 * b->e44 
             + a->e15 * b->e344 + a->e344 * b->e15 + a->e35 * b->e144 
             + a->e144 * b->e35 + a->e45 * b->e134 + a->e134 * b->e45;
  res->e23445 = c->e23445 + a->r * b->e23445 + a->e23445 * b->r + a->e2 * b->e3445 
             + a->e3445 * b->e2 + a->e3 * b->e2445 + a->e2445 * b->e3 
             + a->e4 * b->e2345 + a->e2345 * b->e4 + a->e5 * b->e2344 
             + a->e2344 * b->e5 + a->e23 * b->e445 + a->e445 * b->e23 
             + a->e24 * b->e345 + a->e345 * b->e24 + a->e34 * b->e245 
             + a->e245 * b->e34 + a->e44 * b->e235 + a->e235 * b->e44 
             + a->e25 * b->e344 + a->e344 * b->e25 + a->e35 * b->e244 
             + a->e244 * b->e35 + a->e45 * b->e234 + a->e234 * b->e45;
  res->e33445 = c->e33445 + a->r * b->e33445 + a->e33445 * b->r + a->e3 * b->e3445 
             + a->e3445 * b->e3 + a->e4 * b->e3345 + a->e3345 * b->e4 
             + a->e5 * b->e3344 + a->e3344 * b->e5 + a->e33 * b->e445 
             + a->e445 * b->e33 + a->e34 * b->e345 + a->e345 * b->e34 
             + a->e44 * b->e335 + a->e335 * b->e44 + a->e35 * b->e344 
             + a->e344 * b->e35 + a->e45 * b->e334 + a->e334 * b->e45;
  res->e14445 = c->e14445 + a->r * b->e14445 + a->e14445 * b->r + a->e1 * b->e4445 
             + a->e4445 * b->e1 + a->e4 * b->e1445 + a->e1445 * b->e4 
             + a->e5 * b->e1444 + a->e1444 * b->e5 + a->e14 * b->e445 
             + a->e445 * b->e14 + a->e44 * b->e145 + a->e145 * b->e44 
             + a->e15 * b->e444 + a->e444 * b->e15 + a->e45 * b->e144 
             + a->e144 * b->e45;
  res->e24445 = c->e24445 + a->r * b->e24445 + a->e24445 * b->r + a->e2 * b->e4445 
             + a->e4445 * b->e2 + a->e4 * b->e2445 + a->e2445 * b->e4 
             + a->e5 * b->e2444 + a->e2444 * b->e5 + a->e24 * b->e445 
             + a->e445 * b->e24 + a->e44 * b->e245 + a->e245 * b->e44 
             + a->e25 * b->e444 + a->e444 * b->e25 + a->e45 * b->e244 
             + a->e244 * b->e45;
  res->e34445 = c->e34445 + a->r * b->e34445 + a->e34445 * b->r + a->e3 * b->e4445 
             + a->e4445 * b->e3 + a->e4 * b->e3445 + a->e3445 * b->e4 
             + a->e5 * b->e3444 + a->e3444 * b->e5 + a->e34 * b->e445 
             + a->e445 * b->e34 + a->e44 * b->e345 + a->e345 * b->e44 
             + a->e35 * b->e444 + a->e444 * b->e35 + a->e45 * b->e344 
             + a->e344 * b->e45;
  res->e44445 = c->e44445 + a->r * b->e44445 + a->e44445 * b->r + a->e4 * b->e4445 
             + a->e4445 * b->e4 + a->e5 * b->e4444 + a->e4444 * b->e5 
             + a->e44 * b->e445 + a->e445 * b->e44 + a->e45 * b->e444 
             + a->e444 * b->e45;
  res->e11155 = c->e11155 + a->r * b->e11155 + a->e11155 * b->r + a->e1 * b->e1155 
             + a->e1155 * b->e1 + a->e5 * b->e1115 + a->e1115 * b->e5 
             + a->e11 * b->e155 + a->e155 * b->e11 + a->e15 * b->e115 
             + a->e115 * b->e15 + a->e55 * b->e111 + a->e111 * b->e55;
  res->e11255 = c->e11255 + a->r * b->e11255 + a->e11255 * b->r + a->e1 * b->e1255 
             + a->e1255 * b->e1 + a->e2 * b->e1155 + a->e1155 * b->e2 
             + a->e5 * b->e1125 + a->e1125 * b->e5 + a->e11 * b->e255 
             + a->e255 * b->e11 + a->e12 * b->e155 + a->e155 * b->e12 
             + a->e15 * b->e125 + a->e125 * b->e15 + a->e25 * b->e115 
             + a->e115 * b->e25 + a->e55 * b->e112 + a->e112 * b->e55;
  res->e12255 = c->e12255 + a->r * b->e12255 + a->e12255 * b->r + a->e1 * b->e2255 
             + a->e2255 * b->e1 + a->e2 * b->e1255 + a->e1255 * b->e2 
             + a->e5 * b->e1225 + a->e1225 * b->e5 + a->e12 * b->e255 
             + a->e255 * b->e12 + a->e22 * b->e155 + a->e155 * b->e22 
             + a->e15 * b->e225 + a->e225 * b->e15 + a->e25 * b->e125 
             + a->e125 * b->e25 + a->e55 * b->e122 + a->e122 * b->e55;
  res->e22255 = c->e22255 + a->r * b->e22255 + a->e22255 * b->r + a->e2 * b->e2255 
             + a->e2255 * b->e2 + a->e5 * b->e2225 + a->e2225 * b->e5 
             + a->e22 * b->e255 + a->e255 * b->e22 + a->e25 * b->e225 
             + a->e225 * b->e25 + a->e55 * b->e222 + a->e222 * b->e55;
  res->e11355 = c->e11355 + a->r * b->e11355 + a->e11355 * b->r + a->e1 * b->e1355 
             + a->e1355 * b->e1 + a->e3 * b->e1155 + a->e1155 * b->e3 
             + a->e5 * b->e1135 + a->e1135 * b->e5 + a->e11 * b->e355 
             + a->e355 * b->e11 + a->e13 * b->e155 + a->e155 * b->e13 
             + a->e15 * b->e135 + a->e135 * b->e15 + a->e35 * b->e115 
             + a->e115 * b->e35 + a->e55 * b->e113 + a->e113 * b->e55;
  res->e12355 = c->e12355 + a->r * b->e12355 + a->e12355 * b->r + a->e1 * b->e2355 
             + a->e2355 * b->e1 + a->e2 * b->e1355 + a->e1355 * b->e2 
             + a->e3 * b->e1255 + a->e1255 * b->e3 + a->e5 * b->e1235 
             + a->e1235 * b->e5 + a->e12 * b->e355 + a->e355 * b->e12 
             + a->e13 * b->e255 + a->e255 * b->e13 + a->e23 * b->e155 
             + a->e155 * b->e23 + a->e15 * b->e235 + a->e235 * b->e15 
             + a->e25 * b->e135 + a->e135 * b->e25 + a->e35 * b->e125 
             + a->e125 * b->e35 + a->e55 * b->e123 + a->e123 * b->e55;
  res->e22355 = c->e22355 + a->r * b->e22355 + a->e22355 * b->r + a->e2 * b->e2355 
             + a->e2355 * b->e2 + a->e3 * b->e2255 + a->e2255 * b->e3 
             + a->e5 * b->e2235 + a->e2235 * b->e5 + a->e22 * b->e355 
             + a->e355 * b->e22 + a->e23 * b->e255 + a->e255 * b->e23 
             + a->e25 * b->e235 + a->e235 * b->e25 + a->e35 * b->e225 
             + a->e225 * b->e35 + a->e55 * b->e223 + a->e223 * b->e55;
  res->e13355 = c->e13355 + a->r * b->e13355 + a->e13355 * b->r + a->e1 * b->e3355 
             + a->e3355 * b->e1 + a->e3 * b->e1355 + a->e1355 * b->e3 
             + a->e5 * b->e1335 + a->e1335 * b->e5 + a->e13 * b->e355 
             + a->e355 * b->e13 + a->e33 * b->e155 + a->e155 * b->e33 
             + a->e15 * b->e335 + a->e335 * b->e15 + a->e35 * b->e135 
             + a->e135 * b->e35 + a->e55 * b->e133 + a->e133 * b->e55;
  res->e23355 = c->e23355 + a->r * b->e23355 + a->e23355 * b->r + a->e2 * b->e3355 
             + a->e3355 * b->e2 + a->e3 * b->e2355 + a->e2355 * b->e3 
             + a->e5 * b->e2335 + a->e2335 * b->e5 + a->e23 * b->e355 
             + a->e355 * b->e23 + a->e33 * b->e255 + a->e255 * b->e33 
             + a->e25 * b->e335 + a->e335 * b->e25 + a->e35 * b->e235 
             + a->e235 * b->e35 + a->e55 * b->e233 + a->e233 * b->e55;
  res->e33355 = c->e33355 + a->r * b->e33355 + a->e33355 * b->r + a->e3 * b->e3355 
             + a->e3355 * b->e3 + a->e5 * b->e3335 + a->e3335 * b->e5 
             + a->e33 * b->e355 + a->e355 * b->e33 + a->e35 * b->e335 
             + a->e335 * b->e35 + a->e55 * b->e333 + a->e333 * b->e55;
  res->e11455 = c->e11455 + a->r * b->e11455 + a->e11455 * b->r + a->e1 * b->e1455 
             + a->e1455 * b->e1 + a->e4 * b->e1155 + a->e1155 * b->e4 
             + a->e5 * b->e1145 + a->e1145 * b->e5 + a->e11 * b->e455 
             + a->e455 * b->e11 + a->e14 * b->e155 + a->e155 * b->e14 
             + a->e15 * b->e145 + a->e145 * b->e15 + a->e45 * b->e115 
             + a->e115 * b->e45 + a->e55 * b->e114 + a->e114 * b->e55;
  res->e12455 = c->e12455 + a->r * b->e12455 + a->e12455 * b->r + a->e1 * b->e2455 
             + a->e2455 * b->e1 + a->e2 * b->e1455 + a->e1455 * b->e2 
             + a->e4 * b->e1255 + a->e1255 * b->e4 + a->e5 * b->e1245 
             + a->e1245 * b->e5 + a->e12 * b->e455 + a->e455 * b->e12 
             + a->e14 * b->e255 + a->e255 * b->e14 + a->e24 * b->e155 
             + a->e155 * b->e24 + a->e15 * b->e245 + a->e245 * b->e15 
             + a->e25 * b->e145 + a->e145 * b->e25 + a->e45 * b->e125 
             + a->e125 * b->e45 + a->e55 * b->e124 + a->e124 * b->e55;
  res->e22455 = c->e22455 + a->r * b->e22455 + a->e22455 * b->r + a->e2 * b->e2455 
             + a->e2455 * b->e2 + a->e4 * b->e2255 + a->e2255 * b->e4 
             + a->e5 * b->e2245 + a->e2245 * b->e5 + a->e22 * b->e455 
             + a->e455 * b->e22 + a->e24 * b->e255 + a->e255 * b->e24 
             + a->e25 * b->e245 + a->e245 * b->e25 + a->e45 * b->e225 
             + a->e225 * b->e45 + a->e55 * b->e224 + a->e224 * b->e55;
  res->e13455 = c->e13455 + a->r * b->e13455 + a->e13455 * b->r + a->e1 * b->e3455 
             + a->e3455 * b->e1 + a->e3 * b->e1455 + a->e1455 * b->e3 
             + a->e4 * b->e1355 + a->e1355 * b->e4 + a->e5 * b->e1345 
             + a->e1345 * b->e5 + a->e13 * b->e455 + a->e455 * b->e13 
             + a->e14 * b->e355 + a->e355 * b->e14 + a->e34 * b->e155 
             + a->e155 * b->e34 + a->e15 * b->e345 + a->e345 * b->e15 
             + a->e35 * b->e145 + a->e145 * b->e35 + a->e45 * b->e135 
             + a->e135 * b->e45 + a->e55 * b->e134 + a->e134 * b->e55;
  res->e23455 = c->e23455 + a->r * b->e23455 + a->e23455 * b->r + a->e2 * b->e3455 
             + a->e3455 * b->e2 + a->e3 * b->e2455 + a->e2455 * b->e3 
             + a->e4 * b->e2355 + a->e2355 * b->e4 + a->e5 * b->e2345 
             + a->e2345 * b->e5 + a->e23 * b->e455 + a->e455 * b->e23 
             + a->e24 * b->e355 + a->e355 * b->e24 + a->e34 * b->e255 
             + a->e255 * b->e34 + a->e25 * b->e345 + a->e345 * b->e25 
             + a->e35 * b->e245 + a->e245 * b->e35 + a->e45 * b->e235 
             + a->e235 * b->e45 + a->e55 * b->e234 + a->e234 * b->e55;
  res->e33455 = c->e33455 + a->r * b->e33455 + a->e33455 * b->r + a->e3 * b->e3455 
             + a->e3455 * b->e3 + a->e4 * b->e3355 + a->e3355 * b->e4 
             + a->e5 * b->e3345 + a->e3345 * b->e5 + a->e33 * b->e455 
             + a->e455 * b->e33 + a->e34 * b->e355 + a->e355 * b->e34 
             + a->e35 * b->e345 + a->e345 * b->e35 + a->e45 * b->e335 
             + a->e335 * b->e45 + a->e55 * b->e334 + a->e334 * b->e55;
  res->e14455 = c->e14455 + a->r * b->e14455 + a->e14455 * b->r + a->e1 * b->e4455 
             + a->e4455 * b->e1 + a->e4 * b->e1455 + a->e1455 * b->e4 
             + a->e5 * b->e1445 + a->e1445 * b->e5 + a->e14 * b->e455 
             + a->e455 * b->e14 + a->e44 * b->e155 + a->e155 * b->e44 
             + a->e15 * b->e445 + a->e445 * b->e15 + a->e45 * b->e145 
             + a->e145 * b->e45 + a->e55 * b->e144 + a->e144 * b->e55;
  res->e24455 = c->e24455 + a->r * b->e24455 + a->e24455 * b->r + a->e2 * b->e4455 
             + a->e4455 * b->e2 + a->e4 * b->e2455 + a->e2455 * b->e4 
             + a->e5 * b->e2445 + a->e2445 * b->e5 + a->e24 * b->e455 
             + a->e455 * b->e24 + a->e44 * b->e255 + a->e255 * b->e44 
             + a->e25 * b->e445 + a->e445 * b->e25 + a->e45 * b->e245 
             + a->e245 * b->e45 + a->e55 * b->e244 + a->e244 * b->e55;
  res->e34455 = c->e34455 + a->r * b->e34455 + a->e34455 * b->r + a->e3 * b->e4455 
             + a->e4455 * b->e3 + a->e4 * b->e3455 + a->e3455 * b->e4 
             + a->e5 * b->e3445 + a->e3445 * b->e5 + a->e34 * b->e455 
             + a->e455 * b->e34 + a->e44 * b->e355 + a->e355 * b->e44 
             + a->e35 * b->e445 + a->e445 * b->e35 + a->e45 * b->e345 
             + a->e345 * b->e45 + a->e55 * b->e344 + a->e344 * b->e55;
  res->e44455 = c->e44455 + a->r * b->e44455 + a->e44455 * b->r + a->e4 * b->e4455 
             + a->e4455 * b->e4 + a->e5 * b->e4445 + a->e4445 * b->e5 
             + a->e44 * b->e455 + a->e455 * b->e44 + a->e45 * b->e445 
             + a->e445 * b->e45 + a->e55 * b->e444 + a->e444 * b->e55;
  res->e11555 = c->e11555 + a->r * b->e11555 + a->e11555 * b->r + a->e1 * b->e1555 
             + a->e1555 * b->e1 + a->e5 * b->e1155 + a->e1155 * b->e5 
             + a->e11 * b->e555 + a->e555 * b->e11 + a->e15 * b->e155 
             + a->e155 * b->e15 + a->e55 * b->e115 + a->e115 * b->e55;
  res->e12555 = c->e12555 + a->r * b->e12555 + a->e12555 * b->r + a->e1 * b->e2555 
             + a->e2555 * b->e1 + a->e2 * b->e1555 + a->e1555 * b->e2 
             + a->e5 * b->e1255 + a->e1255 * b->e5 + a->e12 * b->e555 
             + a->e555 * b->e12 + a->e15 * b->e255 + a->e255 * b->e15 
             + a->e25 * b->e155 + a->e155 * b->e25 + a->e55 * b->e125 
             + a->e125 * b->e55;
  res->e22555 = c->e22555 + a->r * b->e22555 + a->e22555 * b->r + a->e2 * b->e2555 
             + a->e2555 * b->e2 + a->e5 * b->e2255 + a->e2255 * b->e5 
             + a->e22 * b->e555 + a->e555 * b->e22 + a->e25 * b->e255 
             + a->e255 * b->e25 + a->e55 * b->e225 + a->e225 * b->e55;
  res->e13555 = c->e13555 + a->r * b->e13555 + a->e13555 * b->r + a->e1 * b->e3555 
             + a->e3555 * b->e1 + a->e3 * b->e1555 + a->e1555 * b->e3 
             + a->e5 * b->e1355 + a->e1355 * b->e5 + a->e13 * b->e555 
             + a->e555 * b->e13 + a->e15 * b->e355 + a->e355 * b->e15 
             + a->e35 * b->e155 + a->e155 * b->e35 + a->e55 * b->e135 
             + a->e135 * b->e55;
  res->e23555 = c->e23555 + a->r * b->e23555 + a->e23555 * b->r + a->e2 * b->e3555 
             + a->e3555 * b->e2 + a->e3 * b->e2555 + a->e2555 * b->e3 
             + a->e5 * b->e2355 + a->e2355 * b->e5 + a->e23 * b->e555 
             + a->e555 * b->e23 + a->e25 * b->e355 + a->e355 * b->e25 
             + a->e35 * b->e255 + a->e255 * b->e35 + a->e55 * b->e235 
             + a->e235 * b->e55;
  res->e33555 = c->e33555 + a->r * b->e33555 + a->e33555 * b->r + a->e3 * b->e3555 
             + a->e3555 * b->e3 + a->e5 * b->e3355 + a->e3355 * b->e5 
             + a->e33 * b->e555 + a->e555 * b->e33 + a->e35 * b->e355 
             + a->e355 * b->e35 + a->e55 * b->e335 + a->e335 * b->e55;
  res->e14555 = c->e14555 + a->r * b->e14555 + a->e14555 * b->r + a->e1 * b->e4555 
             + a->e4555 * b->e1 + a->e4 * b->e1555 + a->e1555 * b->e4 
             + a->e5 * b->e1455 + a->e1455 * b->e5 + a->e14 * b->e555 
             + a->e555 * b->e14 + a->e15 * b->e455 + a->e455 * b->e15 
             + a->e45 * b->e155 + a->e155 * b->e45 + a->e55 * b->e145 
             + a->e145 * b->e55;
  res->e24555 = c->e24555 + a->r * b->e24555 + a->e24555 * b->r + a->e2 * b->e4555 
             + a->e4555 * b->e2 + a->e4 * b->e2555 + a->e2555 * b->e4 
             + a->e5 * b->e2455 + a->e2455 * b->e5 + a->e24 * b->e555 
             + a->e555 * b->e24 + a->e25 * b->e455 + a->e455 * b->e25 
             + a->e45 * b->e255 + a->e255 * b->e45 + a->e55 * b->e245 
             + a->e245 * b->e55;
  res->e34555 = c->e34555 + a->r * b->e34555 + a->e34555 * b->r + a->e3 * b->e4555 
             + a->e4555 * b->e3 + a->e4 * b->e3555 + a->e3555 * b->e4 
             + a->e5 * b->e3455 + a->e3455 * b->e5 + a->e34 * b->e555 
             + a->e555 * b->e34 + a->e35 * b->e455 + a->e455 * b->e35 
             + a->e45 * b->e355 + a->e355 * b->e45 + a->e55 * b->e345 
             + a->e345 * b->e55;
  res->e44555 = c->e44555 + a->r * b->e44555 + a->e44555 * b->r + a->e4 * b->e4555 
             + a->e4555 * b->e4 + a->e5 * b->e4455 + a->e4455 * b->e5 
             + a->e44 * b->e555 + a->e555 * b->e44 + a->e45 * b->e455 
             + a->e455 * b->e45 + a->e55 * b->e445 + a->e445 * b->e55;
  res->e15555 = c->e15555 + a->r * b->e15555 + a->e15555 * b->r + a->e1 * b->e5555 
             + a->e5555 * b->e1 + a->e5 * b->e1555 + a->e1555 * b->e5 
             + a->e15 * b->e555 + a->e555 * b->e15 + a->e55 * b->e155 
             + a->e155 * b->e55;
  res->e25555 = c->e25555 + a->r * b->e25555 + a->e25555 * b->r + a->e2 * b->e5555 
             + a->e5555 * b->e2 + a->e5 * b->e2555 + a->e2555 * b->e5 
             + a->e25 * b->e555 + a->e555 * b->e25 + a->e55 * b->e255 
             + a->e255 * b->e55;
  res->e35555 = c->e35555 + a->r * b->e35555 + a->e35555 * b->r + a->e3 * b->e5555 
             + a->e5555 * b->e3 + a->e5 * b->e3555 + a->e3555 * b->e5 
             + a->e35 * b->e555 + a->e555 * b->e35 + a->e55 * b->e355 
             + a->e355 * b->e55;
  res->e45555 = c->e45555 + a->r * b->e45555 + a->e45555 * b->r + a->e4 * b->e5555 
             + a->e5555 * b->e4 + a->e5 * b->e4555 + a->e4555 * b->e5 
             + a->e45 * b->e555 + a->e555 * b->e45 + a->e55 * b->e455 
             + a->e455 * b->e55;
  res->e55555 = c->e55555 + a->r * b->e55555 + a->e55555 * b->r + a->e5 * b->e5555 
             + a->e5555 * b->e5 + a->e55 * b->e555 + a->e555 * b->e55;

}

onumm5n5_t onumm5n5_gem_ro(  coeff_t a,  onumm5n5_t* b,  onumm5n5_t* c){
  onumm5n5_t res;

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
  res.e1115 = c->e1115 + a * b->e1115;
  res.e1125 = c->e1125 + a * b->e1125;
  res.e1225 = c->e1225 + a * b->e1225;
  res.e2225 = c->e2225 + a * b->e2225;
  res.e1135 = c->e1135 + a * b->e1135;
  res.e1235 = c->e1235 + a * b->e1235;
  res.e2235 = c->e2235 + a * b->e2235;
  res.e1335 = c->e1335 + a * b->e1335;
  res.e2335 = c->e2335 + a * b->e2335;
  res.e3335 = c->e3335 + a * b->e3335;
  res.e1145 = c->e1145 + a * b->e1145;
  res.e1245 = c->e1245 + a * b->e1245;
  res.e2245 = c->e2245 + a * b->e2245;
  res.e1345 = c->e1345 + a * b->e1345;
  res.e2345 = c->e2345 + a * b->e2345;
  res.e3345 = c->e3345 + a * b->e3345;
  res.e1445 = c->e1445 + a * b->e1445;
  res.e2445 = c->e2445 + a * b->e2445;
  res.e3445 = c->e3445 + a * b->e3445;
  res.e4445 = c->e4445 + a * b->e4445;
  res.e1155 = c->e1155 + a * b->e1155;
  res.e1255 = c->e1255 + a * b->e1255;
  res.e2255 = c->e2255 + a * b->e2255;
  res.e1355 = c->e1355 + a * b->e1355;
  res.e2355 = c->e2355 + a * b->e2355;
  res.e3355 = c->e3355 + a * b->e3355;
  res.e1455 = c->e1455 + a * b->e1455;
  res.e2455 = c->e2455 + a * b->e2455;
  res.e3455 = c->e3455 + a * b->e3455;
  res.e4455 = c->e4455 + a * b->e4455;
  res.e1555 = c->e1555 + a * b->e1555;
  res.e2555 = c->e2555 + a * b->e2555;
  res.e3555 = c->e3555 + a * b->e3555;
  res.e4555 = c->e4555 + a * b->e4555;
  res.e5555 = c->e5555 + a * b->e5555;
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
  res.e11115 = c->e11115 + a * b->e11115;
  res.e11125 = c->e11125 + a * b->e11125;
  res.e11225 = c->e11225 + a * b->e11225;
  res.e12225 = c->e12225 + a * b->e12225;
  res.e22225 = c->e22225 + a * b->e22225;
  res.e11135 = c->e11135 + a * b->e11135;
  res.e11235 = c->e11235 + a * b->e11235;
  res.e12235 = c->e12235 + a * b->e12235;
  res.e22235 = c->e22235 + a * b->e22235;
  res.e11335 = c->e11335 + a * b->e11335;
  res.e12335 = c->e12335 + a * b->e12335;
  res.e22335 = c->e22335 + a * b->e22335;
  res.e13335 = c->e13335 + a * b->e13335;
  res.e23335 = c->e23335 + a * b->e23335;
  res.e33335 = c->e33335 + a * b->e33335;
  res.e11145 = c->e11145 + a * b->e11145;
  res.e11245 = c->e11245 + a * b->e11245;
  res.e12245 = c->e12245 + a * b->e12245;
  res.e22245 = c->e22245 + a * b->e22245;
  res.e11345 = c->e11345 + a * b->e11345;
  res.e12345 = c->e12345 + a * b->e12345;
  res.e22345 = c->e22345 + a * b->e22345;
  res.e13345 = c->e13345 + a * b->e13345;
  res.e23345 = c->e23345 + a * b->e23345;
  res.e33345 = c->e33345 + a * b->e33345;
  res.e11445 = c->e11445 + a * b->e11445;
  res.e12445 = c->e12445 + a * b->e12445;
  res.e22445 = c->e22445 + a * b->e22445;
  res.e13445 = c->e13445 + a * b->e13445;
  res.e23445 = c->e23445 + a * b->e23445;
  res.e33445 = c->e33445 + a * b->e33445;
  res.e14445 = c->e14445 + a * b->e14445;
  res.e24445 = c->e24445 + a * b->e24445;
  res.e34445 = c->e34445 + a * b->e34445;
  res.e44445 = c->e44445 + a * b->e44445;
  res.e11155 = c->e11155 + a * b->e11155;
  res.e11255 = c->e11255 + a * b->e11255;
  res.e12255 = c->e12255 + a * b->e12255;
  res.e22255 = c->e22255 + a * b->e22255;
  res.e11355 = c->e11355 + a * b->e11355;
  res.e12355 = c->e12355 + a * b->e12355;
  res.e22355 = c->e22355 + a * b->e22355;
  res.e13355 = c->e13355 + a * b->e13355;
  res.e23355 = c->e23355 + a * b->e23355;
  res.e33355 = c->e33355 + a * b->e33355;
  res.e11455 = c->e11455 + a * b->e11455;
  res.e12455 = c->e12455 + a * b->e12455;
  res.e22455 = c->e22455 + a * b->e22455;
  res.e13455 = c->e13455 + a * b->e13455;
  res.e23455 = c->e23455 + a * b->e23455;
  res.e33455 = c->e33455 + a * b->e33455;
  res.e14455 = c->e14455 + a * b->e14455;
  res.e24455 = c->e24455 + a * b->e24455;
  res.e34455 = c->e34455 + a * b->e34455;
  res.e44455 = c->e44455 + a * b->e44455;
  res.e11555 = c->e11555 + a * b->e11555;
  res.e12555 = c->e12555 + a * b->e12555;
  res.e22555 = c->e22555 + a * b->e22555;
  res.e13555 = c->e13555 + a * b->e13555;
  res.e23555 = c->e23555 + a * b->e23555;
  res.e33555 = c->e33555 + a * b->e33555;
  res.e14555 = c->e14555 + a * b->e14555;
  res.e24555 = c->e24555 + a * b->e24555;
  res.e34555 = c->e34555 + a * b->e34555;
  res.e44555 = c->e44555 + a * b->e44555;
  res.e15555 = c->e15555 + a * b->e15555;
  res.e25555 = c->e25555 + a * b->e25555;
  res.e35555 = c->e35555 + a * b->e35555;
  res.e45555 = c->e45555 + a * b->e45555;
  res.e55555 = c->e55555 + a * b->e55555;

  return res;

}

void onumm5n5_gem_ro_to(  coeff_t a,  onumm5n5_t* b,  onumm5n5_t* c, onumm5n5_t* res){
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
  res->e1115 = c->e1115 + a * b->e1115;
  res->e1125 = c->e1125 + a * b->e1125;
  res->e1225 = c->e1225 + a * b->e1225;
  res->e2225 = c->e2225 + a * b->e2225;
  res->e1135 = c->e1135 + a * b->e1135;
  res->e1235 = c->e1235 + a * b->e1235;
  res->e2235 = c->e2235 + a * b->e2235;
  res->e1335 = c->e1335 + a * b->e1335;
  res->e2335 = c->e2335 + a * b->e2335;
  res->e3335 = c->e3335 + a * b->e3335;
  res->e1145 = c->e1145 + a * b->e1145;
  res->e1245 = c->e1245 + a * b->e1245;
  res->e2245 = c->e2245 + a * b->e2245;
  res->e1345 = c->e1345 + a * b->e1345;
  res->e2345 = c->e2345 + a * b->e2345;
  res->e3345 = c->e3345 + a * b->e3345;
  res->e1445 = c->e1445 + a * b->e1445;
  res->e2445 = c->e2445 + a * b->e2445;
  res->e3445 = c->e3445 + a * b->e3445;
  res->e4445 = c->e4445 + a * b->e4445;
  res->e1155 = c->e1155 + a * b->e1155;
  res->e1255 = c->e1255 + a * b->e1255;
  res->e2255 = c->e2255 + a * b->e2255;
  res->e1355 = c->e1355 + a * b->e1355;
  res->e2355 = c->e2355 + a * b->e2355;
  res->e3355 = c->e3355 + a * b->e3355;
  res->e1455 = c->e1455 + a * b->e1455;
  res->e2455 = c->e2455 + a * b->e2455;
  res->e3455 = c->e3455 + a * b->e3455;
  res->e4455 = c->e4455 + a * b->e4455;
  res->e1555 = c->e1555 + a * b->e1555;
  res->e2555 = c->e2555 + a * b->e2555;
  res->e3555 = c->e3555 + a * b->e3555;
  res->e4555 = c->e4555 + a * b->e4555;
  res->e5555 = c->e5555 + a * b->e5555;
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
  res->e11115 = c->e11115 + a * b->e11115;
  res->e11125 = c->e11125 + a * b->e11125;
  res->e11225 = c->e11225 + a * b->e11225;
  res->e12225 = c->e12225 + a * b->e12225;
  res->e22225 = c->e22225 + a * b->e22225;
  res->e11135 = c->e11135 + a * b->e11135;
  res->e11235 = c->e11235 + a * b->e11235;
  res->e12235 = c->e12235 + a * b->e12235;
  res->e22235 = c->e22235 + a * b->e22235;
  res->e11335 = c->e11335 + a * b->e11335;
  res->e12335 = c->e12335 + a * b->e12335;
  res->e22335 = c->e22335 + a * b->e22335;
  res->e13335 = c->e13335 + a * b->e13335;
  res->e23335 = c->e23335 + a * b->e23335;
  res->e33335 = c->e33335 + a * b->e33335;
  res->e11145 = c->e11145 + a * b->e11145;
  res->e11245 = c->e11245 + a * b->e11245;
  res->e12245 = c->e12245 + a * b->e12245;
  res->e22245 = c->e22245 + a * b->e22245;
  res->e11345 = c->e11345 + a * b->e11345;
  res->e12345 = c->e12345 + a * b->e12345;
  res->e22345 = c->e22345 + a * b->e22345;
  res->e13345 = c->e13345 + a * b->e13345;
  res->e23345 = c->e23345 + a * b->e23345;
  res->e33345 = c->e33345 + a * b->e33345;
  res->e11445 = c->e11445 + a * b->e11445;
  res->e12445 = c->e12445 + a * b->e12445;
  res->e22445 = c->e22445 + a * b->e22445;
  res->e13445 = c->e13445 + a * b->e13445;
  res->e23445 = c->e23445 + a * b->e23445;
  res->e33445 = c->e33445 + a * b->e33445;
  res->e14445 = c->e14445 + a * b->e14445;
  res->e24445 = c->e24445 + a * b->e24445;
  res->e34445 = c->e34445 + a * b->e34445;
  res->e44445 = c->e44445 + a * b->e44445;
  res->e11155 = c->e11155 + a * b->e11155;
  res->e11255 = c->e11255 + a * b->e11255;
  res->e12255 = c->e12255 + a * b->e12255;
  res->e22255 = c->e22255 + a * b->e22255;
  res->e11355 = c->e11355 + a * b->e11355;
  res->e12355 = c->e12355 + a * b->e12355;
  res->e22355 = c->e22355 + a * b->e22355;
  res->e13355 = c->e13355 + a * b->e13355;
  res->e23355 = c->e23355 + a * b->e23355;
  res->e33355 = c->e33355 + a * b->e33355;
  res->e11455 = c->e11455 + a * b->e11455;
  res->e12455 = c->e12455 + a * b->e12455;
  res->e22455 = c->e22455 + a * b->e22455;
  res->e13455 = c->e13455 + a * b->e13455;
  res->e23455 = c->e23455 + a * b->e23455;
  res->e33455 = c->e33455 + a * b->e33455;
  res->e14455 = c->e14455 + a * b->e14455;
  res->e24455 = c->e24455 + a * b->e24455;
  res->e34455 = c->e34455 + a * b->e34455;
  res->e44455 = c->e44455 + a * b->e44455;
  res->e11555 = c->e11555 + a * b->e11555;
  res->e12555 = c->e12555 + a * b->e12555;
  res->e22555 = c->e22555 + a * b->e22555;
  res->e13555 = c->e13555 + a * b->e13555;
  res->e23555 = c->e23555 + a * b->e23555;
  res->e33555 = c->e33555 + a * b->e33555;
  res->e14555 = c->e14555 + a * b->e14555;
  res->e24555 = c->e24555 + a * b->e24555;
  res->e34555 = c->e34555 + a * b->e34555;
  res->e44555 = c->e44555 + a * b->e44555;
  res->e15555 = c->e15555 + a * b->e15555;
  res->e25555 = c->e25555 + a * b->e25555;
  res->e35555 = c->e35555 + a * b->e35555;
  res->e45555 = c->e45555 + a * b->e45555;
  res->e55555 = c->e55555 + a * b->e55555;

}

void onumm5n5_trunc_gem_oo_to( ord_t ord_lhs,  onumm5n5_t* a,  ord_t ord_rhs,  onumm5n5_t* b,  onumm5n5_t* c, onumm5n5_t* res){
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
          res->e1115 = c->e1115 + a->r * b->e1115;
          res->e1125 = c->e1125 + a->r * b->e1125;
          res->e1225 = c->e1225 + a->r * b->e1225;
          res->e2225 = c->e2225 + a->r * b->e2225;
          res->e1135 = c->e1135 + a->r * b->e1135;
          res->e1235 = c->e1235 + a->r * b->e1235;
          res->e2235 = c->e2235 + a->r * b->e2235;
          res->e1335 = c->e1335 + a->r * b->e1335;
          res->e2335 = c->e2335 + a->r * b->e2335;
          res->e3335 = c->e3335 + a->r * b->e3335;
          res->e1145 = c->e1145 + a->r * b->e1145;
          res->e1245 = c->e1245 + a->r * b->e1245;
          res->e2245 = c->e2245 + a->r * b->e2245;
          res->e1345 = c->e1345 + a->r * b->e1345;
          res->e2345 = c->e2345 + a->r * b->e2345;
          res->e3345 = c->e3345 + a->r * b->e3345;
          res->e1445 = c->e1445 + a->r * b->e1445;
          res->e2445 = c->e2445 + a->r * b->e2445;
          res->e3445 = c->e3445 + a->r * b->e3445;
          res->e4445 = c->e4445 + a->r * b->e4445;
          res->e1155 = c->e1155 + a->r * b->e1155;
          res->e1255 = c->e1255 + a->r * b->e1255;
          res->e2255 = c->e2255 + a->r * b->e2255;
          res->e1355 = c->e1355 + a->r * b->e1355;
          res->e2355 = c->e2355 + a->r * b->e2355;
          res->e3355 = c->e3355 + a->r * b->e3355;
          res->e1455 = c->e1455 + a->r * b->e1455;
          res->e2455 = c->e2455 + a->r * b->e2455;
          res->e3455 = c->e3455 + a->r * b->e3455;
          res->e4455 = c->e4455 + a->r * b->e4455;
          res->e1555 = c->e1555 + a->r * b->e1555;
          res->e2555 = c->e2555 + a->r * b->e2555;
          res->e3555 = c->e3555 + a->r * b->e3555;
          res->e4555 = c->e4555 + a->r * b->e4555;
          res->e5555 = c->e5555 + a->r * b->e5555;
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
          res->e11115 = c->e11115 + a->r * b->e11115;
          res->e11125 = c->e11125 + a->r * b->e11125;
          res->e11225 = c->e11225 + a->r * b->e11225;
          res->e12225 = c->e12225 + a->r * b->e12225;
          res->e22225 = c->e22225 + a->r * b->e22225;
          res->e11135 = c->e11135 + a->r * b->e11135;
          res->e11235 = c->e11235 + a->r * b->e11235;
          res->e12235 = c->e12235 + a->r * b->e12235;
          res->e22235 = c->e22235 + a->r * b->e22235;
          res->e11335 = c->e11335 + a->r * b->e11335;
          res->e12335 = c->e12335 + a->r * b->e12335;
          res->e22335 = c->e22335 + a->r * b->e22335;
          res->e13335 = c->e13335 + a->r * b->e13335;
          res->e23335 = c->e23335 + a->r * b->e23335;
          res->e33335 = c->e33335 + a->r * b->e33335;
          res->e11145 = c->e11145 + a->r * b->e11145;
          res->e11245 = c->e11245 + a->r * b->e11245;
          res->e12245 = c->e12245 + a->r * b->e12245;
          res->e22245 = c->e22245 + a->r * b->e22245;
          res->e11345 = c->e11345 + a->r * b->e11345;
          res->e12345 = c->e12345 + a->r * b->e12345;
          res->e22345 = c->e22345 + a->r * b->e22345;
          res->e13345 = c->e13345 + a->r * b->e13345;
          res->e23345 = c->e23345 + a->r * b->e23345;
          res->e33345 = c->e33345 + a->r * b->e33345;
          res->e11445 = c->e11445 + a->r * b->e11445;
          res->e12445 = c->e12445 + a->r * b->e12445;
          res->e22445 = c->e22445 + a->r * b->e22445;
          res->e13445 = c->e13445 + a->r * b->e13445;
          res->e23445 = c->e23445 + a->r * b->e23445;
          res->e33445 = c->e33445 + a->r * b->e33445;
          res->e14445 = c->e14445 + a->r * b->e14445;
          res->e24445 = c->e24445 + a->r * b->e24445;
          res->e34445 = c->e34445 + a->r * b->e34445;
          res->e44445 = c->e44445 + a->r * b->e44445;
          res->e11155 = c->e11155 + a->r * b->e11155;
          res->e11255 = c->e11255 + a->r * b->e11255;
          res->e12255 = c->e12255 + a->r * b->e12255;
          res->e22255 = c->e22255 + a->r * b->e22255;
          res->e11355 = c->e11355 + a->r * b->e11355;
          res->e12355 = c->e12355 + a->r * b->e12355;
          res->e22355 = c->e22355 + a->r * b->e22355;
          res->e13355 = c->e13355 + a->r * b->e13355;
          res->e23355 = c->e23355 + a->r * b->e23355;
          res->e33355 = c->e33355 + a->r * b->e33355;
          res->e11455 = c->e11455 + a->r * b->e11455;
          res->e12455 = c->e12455 + a->r * b->e12455;
          res->e22455 = c->e22455 + a->r * b->e22455;
          res->e13455 = c->e13455 + a->r * b->e13455;
          res->e23455 = c->e23455 + a->r * b->e23455;
          res->e33455 = c->e33455 + a->r * b->e33455;
          res->e14455 = c->e14455 + a->r * b->e14455;
          res->e24455 = c->e24455 + a->r * b->e24455;
          res->e34455 = c->e34455 + a->r * b->e34455;
          res->e44455 = c->e44455 + a->r * b->e44455;
          res->e11555 = c->e11555 + a->r * b->e11555;
          res->e12555 = c->e12555 + a->r * b->e12555;
          res->e22555 = c->e22555 + a->r * b->e22555;
          res->e13555 = c->e13555 + a->r * b->e13555;
          res->e23555 = c->e23555 + a->r * b->e23555;
          res->e33555 = c->e33555 + a->r * b->e33555;
          res->e14555 = c->e14555 + a->r * b->e14555;
          res->e24555 = c->e24555 + a->r * b->e24555;
          res->e34555 = c->e34555 + a->r * b->e34555;
          res->e44555 = c->e44555 + a->r * b->e44555;
          res->e15555 = c->e15555 + a->r * b->e15555;
          res->e25555 = c->e25555 + a->r * b->e25555;
          res->e35555 = c->e35555 + a->r * b->e35555;
          res->e45555 = c->e45555 + a->r * b->e45555;
          res->e55555 = c->e55555 + a->r * b->e55555;
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
          res->e1115 = c->e1115 + a->e1 * b->e115 + a->e5 * b->e111;
          res->e1125 = c->e1125 + a->e1 * b->e125 + a->e2 * b->e115 
                     + a->e5 * b->e112;
          res->e1225 = c->e1225 + a->e1 * b->e225 + a->e2 * b->e125 
                     + a->e5 * b->e122;
          res->e2225 = c->e2225 + a->e2 * b->e225 + a->e5 * b->e222;
          res->e1135 = c->e1135 + a->e1 * b->e135 + a->e3 * b->e115 
                     + a->e5 * b->e113;
          res->e1235 = c->e1235 + a->e1 * b->e235 + a->e2 * b->e135 
                     + a->e3 * b->e125 + a->e5 * b->e123;
          res->e2235 = c->e2235 + a->e2 * b->e235 + a->e3 * b->e225 
                     + a->e5 * b->e223;
          res->e1335 = c->e1335 + a->e1 * b->e335 + a->e3 * b->e135 
                     + a->e5 * b->e133;
          res->e2335 = c->e2335 + a->e2 * b->e335 + a->e3 * b->e235 
                     + a->e5 * b->e233;
          res->e3335 = c->e3335 + a->e3 * b->e335 + a->e5 * b->e333;
          res->e1145 = c->e1145 + a->e1 * b->e145 + a->e4 * b->e115 
                     + a->e5 * b->e114;
          res->e1245 = c->e1245 + a->e1 * b->e245 + a->e2 * b->e145 
                     + a->e4 * b->e125 + a->e5 * b->e124;
          res->e2245 = c->e2245 + a->e2 * b->e245 + a->e4 * b->e225 
                     + a->e5 * b->e224;
          res->e1345 = c->e1345 + a->e1 * b->e345 + a->e3 * b->e145 
                     + a->e4 * b->e135 + a->e5 * b->e134;
          res->e2345 = c->e2345 + a->e2 * b->e345 + a->e3 * b->e245 
                     + a->e4 * b->e235 + a->e5 * b->e234;
          res->e3345 = c->e3345 + a->e3 * b->e345 + a->e4 * b->e335 
                     + a->e5 * b->e334;
          res->e1445 = c->e1445 + a->e1 * b->e445 + a->e4 * b->e145 
                     + a->e5 * b->e144;
          res->e2445 = c->e2445 + a->e2 * b->e445 + a->e4 * b->e245 
                     + a->e5 * b->e244;
          res->e3445 = c->e3445 + a->e3 * b->e445 + a->e4 * b->e345 
                     + a->e5 * b->e344;
          res->e4445 = c->e4445 + a->e4 * b->e445 + a->e5 * b->e444;
          res->e1155 = c->e1155 + a->e1 * b->e155 + a->e5 * b->e115;
          res->e1255 = c->e1255 + a->e1 * b->e255 + a->e2 * b->e155 
                     + a->e5 * b->e125;
          res->e2255 = c->e2255 + a->e2 * b->e255 + a->e5 * b->e225;
          res->e1355 = c->e1355 + a->e1 * b->e355 + a->e3 * b->e155 
                     + a->e5 * b->e135;
          res->e2355 = c->e2355 + a->e2 * b->e355 + a->e3 * b->e255 
                     + a->e5 * b->e235;
          res->e3355 = c->e3355 + a->e3 * b->e355 + a->e5 * b->e335;
          res->e1455 = c->e1455 + a->e1 * b->e455 + a->e4 * b->e155 
                     + a->e5 * b->e145;
          res->e2455 = c->e2455 + a->e2 * b->e455 + a->e4 * b->e255 
                     + a->e5 * b->e245;
          res->e3455 = c->e3455 + a->e3 * b->e455 + a->e4 * b->e355 
                     + a->e5 * b->e345;
          res->e4455 = c->e4455 + a->e4 * b->e455 + a->e5 * b->e445;
          res->e1555 = c->e1555 + a->e1 * b->e555 + a->e5 * b->e155;
          res->e2555 = c->e2555 + a->e2 * b->e555 + a->e5 * b->e255;
          res->e3555 = c->e3555 + a->e3 * b->e555 + a->e5 * b->e355;
          res->e4555 = c->e4555 + a->e4 * b->e555 + a->e5 * b->e455;
          res->e5555 = c->e5555 + a->e5 * b->e555;
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
          res->e11115 = c->e11115 + a->e1 * b->e1115 + a->e5 * b->e1111;
          res->e11125 = c->e11125 + a->e1 * b->e1125 + a->e2 * b->e1115 
                      + a->e5 * b->e1112;
          res->e11225 = c->e11225 + a->e1 * b->e1225 + a->e2 * b->e1125 
                      + a->e5 * b->e1122;
          res->e12225 = c->e12225 + a->e1 * b->e2225 + a->e2 * b->e1225 
                      + a->e5 * b->e1222;
          res->e22225 = c->e22225 + a->e2 * b->e2225 + a->e5 * b->e2222;
          res->e11135 = c->e11135 + a->e1 * b->e1135 + a->e3 * b->e1115 
                      + a->e5 * b->e1113;
          res->e11235 = c->e11235 + a->e1 * b->e1235 + a->e2 * b->e1135 
                      + a->e3 * b->e1125 + a->e5 * b->e1123;
          res->e12235 = c->e12235 + a->e1 * b->e2235 + a->e2 * b->e1235 
                      + a->e3 * b->e1225 + a->e5 * b->e1223;
          res->e22235 = c->e22235 + a->e2 * b->e2235 + a->e3 * b->e2225 
                      + a->e5 * b->e2223;
          res->e11335 = c->e11335 + a->e1 * b->e1335 + a->e3 * b->e1135 
                      + a->e5 * b->e1133;
          res->e12335 = c->e12335 + a->e1 * b->e2335 + a->e2 * b->e1335 
                      + a->e3 * b->e1235 + a->e5 * b->e1233;
          res->e22335 = c->e22335 + a->e2 * b->e2335 + a->e3 * b->e2235 
                      + a->e5 * b->e2233;
          res->e13335 = c->e13335 + a->e1 * b->e3335 + a->e3 * b->e1335 
                      + a->e5 * b->e1333;
          res->e23335 = c->e23335 + a->e2 * b->e3335 + a->e3 * b->e2335 
                      + a->e5 * b->e2333;
          res->e33335 = c->e33335 + a->e3 * b->e3335 + a->e5 * b->e3333;
          res->e11145 = c->e11145 + a->e1 * b->e1145 + a->e4 * b->e1115 
                      + a->e5 * b->e1114;
          res->e11245 = c->e11245 + a->e1 * b->e1245 + a->e2 * b->e1145 
                      + a->e4 * b->e1125 + a->e5 * b->e1124;
          res->e12245 = c->e12245 + a->e1 * b->e2245 + a->e2 * b->e1245 
                      + a->e4 * b->e1225 + a->e5 * b->e1224;
          res->e22245 = c->e22245 + a->e2 * b->e2245 + a->e4 * b->e2225 
                      + a->e5 * b->e2224;
          res->e11345 = c->e11345 + a->e1 * b->e1345 + a->e3 * b->e1145 
                      + a->e4 * b->e1135 + a->e5 * b->e1134;
          res->e12345 = c->e12345 + a->e1 * b->e2345 + a->e2 * b->e1345 
                      + a->e3 * b->e1245 + a->e4 * b->e1235 + a->e5 * b->e1234;
          res->e22345 = c->e22345 + a->e2 * b->e2345 + a->e3 * b->e2245 
                      + a->e4 * b->e2235 + a->e5 * b->e2234;
          res->e13345 = c->e13345 + a->e1 * b->e3345 + a->e3 * b->e1345 
                      + a->e4 * b->e1335 + a->e5 * b->e1334;
          res->e23345 = c->e23345 + a->e2 * b->e3345 + a->e3 * b->e2345 
                      + a->e4 * b->e2335 + a->e5 * b->e2334;
          res->e33345 = c->e33345 + a->e3 * b->e3345 + a->e4 * b->e3335 
                      + a->e5 * b->e3334;
          res->e11445 = c->e11445 + a->e1 * b->e1445 + a->e4 * b->e1145 
                      + a->e5 * b->e1144;
          res->e12445 = c->e12445 + a->e1 * b->e2445 + a->e2 * b->e1445 
                      + a->e4 * b->e1245 + a->e5 * b->e1244;
          res->e22445 = c->e22445 + a->e2 * b->e2445 + a->e4 * b->e2245 
                      + a->e5 * b->e2244;
          res->e13445 = c->e13445 + a->e1 * b->e3445 + a->e3 * b->e1445 
                      + a->e4 * b->e1345 + a->e5 * b->e1344;
          res->e23445 = c->e23445 + a->e2 * b->e3445 + a->e3 * b->e2445 
                      + a->e4 * b->e2345 + a->e5 * b->e2344;
          res->e33445 = c->e33445 + a->e3 * b->e3445 + a->e4 * b->e3345 
                      + a->e5 * b->e3344;
          res->e14445 = c->e14445 + a->e1 * b->e4445 + a->e4 * b->e1445 
                      + a->e5 * b->e1444;
          res->e24445 = c->e24445 + a->e2 * b->e4445 + a->e4 * b->e2445 
                      + a->e5 * b->e2444;
          res->e34445 = c->e34445 + a->e3 * b->e4445 + a->e4 * b->e3445 
                      + a->e5 * b->e3444;
          res->e44445 = c->e44445 + a->e4 * b->e4445 + a->e5 * b->e4444;
          res->e11155 = c->e11155 + a->e1 * b->e1155 + a->e5 * b->e1115;
          res->e11255 = c->e11255 + a->e1 * b->e1255 + a->e2 * b->e1155 
                      + a->e5 * b->e1125;
          res->e12255 = c->e12255 + a->e1 * b->e2255 + a->e2 * b->e1255 
                      + a->e5 * b->e1225;
          res->e22255 = c->e22255 + a->e2 * b->e2255 + a->e5 * b->e2225;
          res->e11355 = c->e11355 + a->e1 * b->e1355 + a->e3 * b->e1155 
                      + a->e5 * b->e1135;
          res->e12355 = c->e12355 + a->e1 * b->e2355 + a->e2 * b->e1355 
                      + a->e3 * b->e1255 + a->e5 * b->e1235;
          res->e22355 = c->e22355 + a->e2 * b->e2355 + a->e3 * b->e2255 
                      + a->e5 * b->e2235;
          res->e13355 = c->e13355 + a->e1 * b->e3355 + a->e3 * b->e1355 
                      + a->e5 * b->e1335;
          res->e23355 = c->e23355 + a->e2 * b->e3355 + a->e3 * b->e2355 
                      + a->e5 * b->e2335;
          res->e33355 = c->e33355 + a->e3 * b->e3355 + a->e5 * b->e3335;
          res->e11455 = c->e11455 + a->e1 * b->e1455 + a->e4 * b->e1155 
                      + a->e5 * b->e1145;
          res->e12455 = c->e12455 + a->e1 * b->e2455 + a->e2 * b->e1455 
                      + a->e4 * b->e1255 + a->e5 * b->e1245;
          res->e22455 = c->e22455 + a->e2 * b->e2455 + a->e4 * b->e2255 
                      + a->e5 * b->e2245;
          res->e13455 = c->e13455 + a->e1 * b->e3455 + a->e3 * b->e1455 
                      + a->e4 * b->e1355 + a->e5 * b->e1345;
          res->e23455 = c->e23455 + a->e2 * b->e3455 + a->e3 * b->e2455 
                      + a->e4 * b->e2355 + a->e5 * b->e2345;
          res->e33455 = c->e33455 + a->e3 * b->e3455 + a->e4 * b->e3355 
                      + a->e5 * b->e3345;
          res->e14455 = c->e14455 + a->e1 * b->e4455 + a->e4 * b->e1455 
                      + a->e5 * b->e1445;
          res->e24455 = c->e24455 + a->e2 * b->e4455 + a->e4 * b->e2455 
                      + a->e5 * b->e2445;
          res->e34455 = c->e34455 + a->e3 * b->e4455 + a->e4 * b->e3455 
                      + a->e5 * b->e3445;
          res->e44455 = c->e44455 + a->e4 * b->e4455 + a->e5 * b->e4445;
          res->e11555 = c->e11555 + a->e1 * b->e1555 + a->e5 * b->e1155;
          res->e12555 = c->e12555 + a->e1 * b->e2555 + a->e2 * b->e1555 
                      + a->e5 * b->e1255;
          res->e22555 = c->e22555 + a->e2 * b->e2555 + a->e5 * b->e2255;
          res->e13555 = c->e13555 + a->e1 * b->e3555 + a->e3 * b->e1555 
                      + a->e5 * b->e1355;
          res->e23555 = c->e23555 + a->e2 * b->e3555 + a->e3 * b->e2555 
                      + a->e5 * b->e2355;
          res->e33555 = c->e33555 + a->e3 * b->e3555 + a->e5 * b->e3355;
          res->e14555 = c->e14555 + a->e1 * b->e4555 + a->e4 * b->e1555 
                      + a->e5 * b->e1455;
          res->e24555 = c->e24555 + a->e2 * b->e4555 + a->e4 * b->e2555 
                      + a->e5 * b->e2455;
          res->e34555 = c->e34555 + a->e3 * b->e4555 + a->e4 * b->e3555 
                      + a->e5 * b->e3455;
          res->e44555 = c->e44555 + a->e4 * b->e4555 + a->e5 * b->e4455;
          res->e15555 = c->e15555 + a->e1 * b->e5555 + a->e5 * b->e1555;
          res->e25555 = c->e25555 + a->e2 * b->e5555 + a->e5 * b->e2555;
          res->e35555 = c->e35555 + a->e3 * b->e5555 + a->e5 * b->e3555;
          res->e45555 = c->e45555 + a->e4 * b->e5555 + a->e5 * b->e4555;
          res->e55555 = c->e55555 + a->e5 * b->e5555;
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
          res->e1115 = c->e1115 + a->e11 * b->e15 + a->e15 * b->e11;
          res->e1125 = c->e1125 + a->e11 * b->e25 + a->e12 * b->e15 
                     + a->e15 * b->e12 + a->e25 * b->e11;
          res->e1225 = c->e1225 + a->e12 * b->e25 + a->e22 * b->e15 
                     + a->e15 * b->e22 + a->e25 * b->e12;
          res->e2225 = c->e2225 + a->e22 * b->e25 + a->e25 * b->e22;
          res->e1135 = c->e1135 + a->e11 * b->e35 + a->e13 * b->e15 
                     + a->e15 * b->e13 + a->e35 * b->e11;
          res->e1235 = c->e1235 + a->e12 * b->e35 + a->e13 * b->e25 
                     + a->e23 * b->e15 + a->e15 * b->e23 + a->e25 * b->e13 
                     + a->e35 * b->e12;
          res->e2235 = c->e2235 + a->e22 * b->e35 + a->e23 * b->e25 
                     + a->e25 * b->e23 + a->e35 * b->e22;
          res->e1335 = c->e1335 + a->e13 * b->e35 + a->e33 * b->e15 
                     + a->e15 * b->e33 + a->e35 * b->e13;
          res->e2335 = c->e2335 + a->e23 * b->e35 + a->e33 * b->e25 
                     + a->e25 * b->e33 + a->e35 * b->e23;
          res->e3335 = c->e3335 + a->e33 * b->e35 + a->e35 * b->e33;
          res->e1145 = c->e1145 + a->e11 * b->e45 + a->e14 * b->e15 
                     + a->e15 * b->e14 + a->e45 * b->e11;
          res->e1245 = c->e1245 + a->e12 * b->e45 + a->e14 * b->e25 
                     + a->e24 * b->e15 + a->e15 * b->e24 + a->e25 * b->e14 
                     + a->e45 * b->e12;
          res->e2245 = c->e2245 + a->e22 * b->e45 + a->e24 * b->e25 
                     + a->e25 * b->e24 + a->e45 * b->e22;
          res->e1345 = c->e1345 + a->e13 * b->e45 + a->e14 * b->e35 
                     + a->e34 * b->e15 + a->e15 * b->e34 + a->e35 * b->e14 
                     + a->e45 * b->e13;
          res->e2345 = c->e2345 + a->e23 * b->e45 + a->e24 * b->e35 
                     + a->e34 * b->e25 + a->e25 * b->e34 + a->e35 * b->e24 
                     + a->e45 * b->e23;
          res->e3345 = c->e3345 + a->e33 * b->e45 + a->e34 * b->e35 
                     + a->e35 * b->e34 + a->e45 * b->e33;
          res->e1445 = c->e1445 + a->e14 * b->e45 + a->e44 * b->e15 
                     + a->e15 * b->e44 + a->e45 * b->e14;
          res->e2445 = c->e2445 + a->e24 * b->e45 + a->e44 * b->e25 
                     + a->e25 * b->e44 + a->e45 * b->e24;
          res->e3445 = c->e3445 + a->e34 * b->e45 + a->e44 * b->e35 
                     + a->e35 * b->e44 + a->e45 * b->e34;
          res->e4445 = c->e4445 + a->e44 * b->e45 + a->e45 * b->e44;
          res->e1155 = c->e1155 + a->e11 * b->e55 + a->e15 * b->e15 
                     + a->e55 * b->e11;
          res->e1255 = c->e1255 + a->e12 * b->e55 + a->e15 * b->e25 
                     + a->e25 * b->e15 + a->e55 * b->e12;
          res->e2255 = c->e2255 + a->e22 * b->e55 + a->e25 * b->e25 
                     + a->e55 * b->e22;
          res->e1355 = c->e1355 + a->e13 * b->e55 + a->e15 * b->e35 
                     + a->e35 * b->e15 + a->e55 * b->e13;
          res->e2355 = c->e2355 + a->e23 * b->e55 + a->e25 * b->e35 
                     + a->e35 * b->e25 + a->e55 * b->e23;
          res->e3355 = c->e3355 + a->e33 * b->e55 + a->e35 * b->e35 
                     + a->e55 * b->e33;
          res->e1455 = c->e1455 + a->e14 * b->e55 + a->e15 * b->e45 
                     + a->e45 * b->e15 + a->e55 * b->e14;
          res->e2455 = c->e2455 + a->e24 * b->e55 + a->e25 * b->e45 
                     + a->e45 * b->e25 + a->e55 * b->e24;
          res->e3455 = c->e3455 + a->e34 * b->e55 + a->e35 * b->e45 
                     + a->e45 * b->e35 + a->e55 * b->e34;
          res->e4455 = c->e4455 + a->e44 * b->e55 + a->e45 * b->e45 
                     + a->e55 * b->e44;
          res->e1555 = c->e1555 + a->e15 * b->e55 + a->e55 * b->e15;
          res->e2555 = c->e2555 + a->e25 * b->e55 + a->e55 * b->e25;
          res->e3555 = c->e3555 + a->e35 * b->e55 + a->e55 * b->e35;
          res->e4555 = c->e4555 + a->e45 * b->e55 + a->e55 * b->e45;
          res->e5555 = c->e5555 + a->e55 * b->e55;
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
          res->e11115 = c->e11115 + a->e11 * b->e115 + a->e15 * b->e111;
          res->e11125 = c->e11125 + a->e11 * b->e125 + a->e12 * b->e115 
                      + a->e15 * b->e112 + a->e25 * b->e111;
          res->e11225 = c->e11225 + a->e11 * b->e225 + a->e12 * b->e125 
                      + a->e22 * b->e115 + a->e15 * b->e122 + a->e25 * b->e112;
          res->e12225 = c->e12225 + a->e12 * b->e225 + a->e22 * b->e125 
                      + a->e15 * b->e222 + a->e25 * b->e122;
          res->e22225 = c->e22225 + a->e22 * b->e225 + a->e25 * b->e222;
          res->e11135 = c->e11135 + a->e11 * b->e135 + a->e13 * b->e115 
                      + a->e15 * b->e113 + a->e35 * b->e111;
          res->e11235 = c->e11235 + a->e11 * b->e235 + a->e12 * b->e135 
                      + a->e13 * b->e125 + a->e23 * b->e115 + a->e15 * b->e123 
                      + a->e25 * b->e113 + a->e35 * b->e112;
          res->e12235 = c->e12235 + a->e12 * b->e235 + a->e22 * b->e135 
                      + a->e13 * b->e225 + a->e23 * b->e125 + a->e15 * b->e223 
                      + a->e25 * b->e123 + a->e35 * b->e122;
          res->e22235 = c->e22235 + a->e22 * b->e235 + a->e23 * b->e225 
                      + a->e25 * b->e223 + a->e35 * b->e222;
          res->e11335 = c->e11335 + a->e11 * b->e335 + a->e13 * b->e135 
                      + a->e33 * b->e115 + a->e15 * b->e133 + a->e35 * b->e113;
          res->e12335 = c->e12335 + a->e12 * b->e335 + a->e13 * b->e235 
                      + a->e23 * b->e135 + a->e33 * b->e125 + a->e15 * b->e233 
                      + a->e25 * b->e133 + a->e35 * b->e123;
          res->e22335 = c->e22335 + a->e22 * b->e335 + a->e23 * b->e235 
                      + a->e33 * b->e225 + a->e25 * b->e233 + a->e35 * b->e223;
          res->e13335 = c->e13335 + a->e13 * b->e335 + a->e33 * b->e135 
                      + a->e15 * b->e333 + a->e35 * b->e133;
          res->e23335 = c->e23335 + a->e23 * b->e335 + a->e33 * b->e235 
                      + a->e25 * b->e333 + a->e35 * b->e233;
          res->e33335 = c->e33335 + a->e33 * b->e335 + a->e35 * b->e333;
          res->e11145 = c->e11145 + a->e11 * b->e145 + a->e14 * b->e115 
                      + a->e15 * b->e114 + a->e45 * b->e111;
          res->e11245 = c->e11245 + a->e11 * b->e245 + a->e12 * b->e145 
                      + a->e14 * b->e125 + a->e24 * b->e115 + a->e15 * b->e124 
                      + a->e25 * b->e114 + a->e45 * b->e112;
          res->e12245 = c->e12245 + a->e12 * b->e245 + a->e22 * b->e145 
                      + a->e14 * b->e225 + a->e24 * b->e125 + a->e15 * b->e224 
                      + a->e25 * b->e124 + a->e45 * b->e122;
          res->e22245 = c->e22245 + a->e22 * b->e245 + a->e24 * b->e225 
                      + a->e25 * b->e224 + a->e45 * b->e222;
          res->e11345 = c->e11345 + a->e11 * b->e345 + a->e13 * b->e145 
                      + a->e14 * b->e135 + a->e34 * b->e115 + a->e15 * b->e134 
                      + a->e35 * b->e114 + a->e45 * b->e113;
          res->e12345 = c->e12345 + a->e12 * b->e345 + a->e13 * b->e245 
                      + a->e23 * b->e145 + a->e14 * b->e235 + a->e24 * b->e135 
                      + a->e34 * b->e125 + a->e15 * b->e234 + a->e25 * b->e134 
                      + a->e35 * b->e124 + a->e45 * b->e123;
          res->e22345 = c->e22345 + a->e22 * b->e345 + a->e23 * b->e245 
                      + a->e24 * b->e235 + a->e34 * b->e225 + a->e25 * b->e234 
                      + a->e35 * b->e224 + a->e45 * b->e223;
          res->e13345 = c->e13345 + a->e13 * b->e345 + a->e33 * b->e145 
                      + a->e14 * b->e335 + a->e34 * b->e135 + a->e15 * b->e334 
                      + a->e35 * b->e134 + a->e45 * b->e133;
          res->e23345 = c->e23345 + a->e23 * b->e345 + a->e33 * b->e245 
                      + a->e24 * b->e335 + a->e34 * b->e235 + a->e25 * b->e334 
                      + a->e35 * b->e234 + a->e45 * b->e233;
          res->e33345 = c->e33345 + a->e33 * b->e345 + a->e34 * b->e335 
                      + a->e35 * b->e334 + a->e45 * b->e333;
          res->e11445 = c->e11445 + a->e11 * b->e445 + a->e14 * b->e145 
                      + a->e44 * b->e115 + a->e15 * b->e144 + a->e45 * b->e114;
          res->e12445 = c->e12445 + a->e12 * b->e445 + a->e14 * b->e245 
                      + a->e24 * b->e145 + a->e44 * b->e125 + a->e15 * b->e244 
                      + a->e25 * b->e144 + a->e45 * b->e124;
          res->e22445 = c->e22445 + a->e22 * b->e445 + a->e24 * b->e245 
                      + a->e44 * b->e225 + a->e25 * b->e244 + a->e45 * b->e224;
          res->e13445 = c->e13445 + a->e13 * b->e445 + a->e14 * b->e345 
                      + a->e34 * b->e145 + a->e44 * b->e135 + a->e15 * b->e344 
                      + a->e35 * b->e144 + a->e45 * b->e134;
          res->e23445 = c->e23445 + a->e23 * b->e445 + a->e24 * b->e345 
                      + a->e34 * b->e245 + a->e44 * b->e235 + a->e25 * b->e344 
                      + a->e35 * b->e244 + a->e45 * b->e234;
          res->e33445 = c->e33445 + a->e33 * b->e445 + a->e34 * b->e345 
                      + a->e44 * b->e335 + a->e35 * b->e344 + a->e45 * b->e334;
          res->e14445 = c->e14445 + a->e14 * b->e445 + a->e44 * b->e145 
                      + a->e15 * b->e444 + a->e45 * b->e144;
          res->e24445 = c->e24445 + a->e24 * b->e445 + a->e44 * b->e245 
                      + a->e25 * b->e444 + a->e45 * b->e244;
          res->e34445 = c->e34445 + a->e34 * b->e445 + a->e44 * b->e345 
                      + a->e35 * b->e444 + a->e45 * b->e344;
          res->e44445 = c->e44445 + a->e44 * b->e445 + a->e45 * b->e444;
          res->e11155 = c->e11155 + a->e11 * b->e155 + a->e15 * b->e115 
                      + a->e55 * b->e111;
          res->e11255 = c->e11255 + a->e11 * b->e255 + a->e12 * b->e155 
                      + a->e15 * b->e125 + a->e25 * b->e115 + a->e55 * b->e112;
          res->e12255 = c->e12255 + a->e12 * b->e255 + a->e22 * b->e155 
                      + a->e15 * b->e225 + a->e25 * b->e125 + a->e55 * b->e122;
          res->e22255 = c->e22255 + a->e22 * b->e255 + a->e25 * b->e225 
                      + a->e55 * b->e222;
          res->e11355 = c->e11355 + a->e11 * b->e355 + a->e13 * b->e155 
                      + a->e15 * b->e135 + a->e35 * b->e115 + a->e55 * b->e113;
          res->e12355 = c->e12355 + a->e12 * b->e355 + a->e13 * b->e255 
                      + a->e23 * b->e155 + a->e15 * b->e235 + a->e25 * b->e135 
                      + a->e35 * b->e125 + a->e55 * b->e123;
          res->e22355 = c->e22355 + a->e22 * b->e355 + a->e23 * b->e255 
                      + a->e25 * b->e235 + a->e35 * b->e225 + a->e55 * b->e223;
          res->e13355 = c->e13355 + a->e13 * b->e355 + a->e33 * b->e155 
                      + a->e15 * b->e335 + a->e35 * b->e135 + a->e55 * b->e133;
          res->e23355 = c->e23355 + a->e23 * b->e355 + a->e33 * b->e255 
                      + a->e25 * b->e335 + a->e35 * b->e235 + a->e55 * b->e233;
          res->e33355 = c->e33355 + a->e33 * b->e355 + a->e35 * b->e335 
                      + a->e55 * b->e333;
          res->e11455 = c->e11455 + a->e11 * b->e455 + a->e14 * b->e155 
                      + a->e15 * b->e145 + a->e45 * b->e115 + a->e55 * b->e114;
          res->e12455 = c->e12455 + a->e12 * b->e455 + a->e14 * b->e255 
                      + a->e24 * b->e155 + a->e15 * b->e245 + a->e25 * b->e145 
                      + a->e45 * b->e125 + a->e55 * b->e124;
          res->e22455 = c->e22455 + a->e22 * b->e455 + a->e24 * b->e255 
                      + a->e25 * b->e245 + a->e45 * b->e225 + a->e55 * b->e224;
          res->e13455 = c->e13455 + a->e13 * b->e455 + a->e14 * b->e355 
                      + a->e34 * b->e155 + a->e15 * b->e345 + a->e35 * b->e145 
                      + a->e45 * b->e135 + a->e55 * b->e134;
          res->e23455 = c->e23455 + a->e23 * b->e455 + a->e24 * b->e355 
                      + a->e34 * b->e255 + a->e25 * b->e345 + a->e35 * b->e245 
                      + a->e45 * b->e235 + a->e55 * b->e234;
          res->e33455 = c->e33455 + a->e33 * b->e455 + a->e34 * b->e355 
                      + a->e35 * b->e345 + a->e45 * b->e335 + a->e55 * b->e334;
          res->e14455 = c->e14455 + a->e14 * b->e455 + a->e44 * b->e155 
                      + a->e15 * b->e445 + a->e45 * b->e145 + a->e55 * b->e144;
          res->e24455 = c->e24455 + a->e24 * b->e455 + a->e44 * b->e255 
                      + a->e25 * b->e445 + a->e45 * b->e245 + a->e55 * b->e244;
          res->e34455 = c->e34455 + a->e34 * b->e455 + a->e44 * b->e355 
                      + a->e35 * b->e445 + a->e45 * b->e345 + a->e55 * b->e344;
          res->e44455 = c->e44455 + a->e44 * b->e455 + a->e45 * b->e445 
                      + a->e55 * b->e444;
          res->e11555 = c->e11555 + a->e11 * b->e555 + a->e15 * b->e155 
                      + a->e55 * b->e115;
          res->e12555 = c->e12555 + a->e12 * b->e555 + a->e15 * b->e255 
                      + a->e25 * b->e155 + a->e55 * b->e125;
          res->e22555 = c->e22555 + a->e22 * b->e555 + a->e25 * b->e255 
                      + a->e55 * b->e225;
          res->e13555 = c->e13555 + a->e13 * b->e555 + a->e15 * b->e355 
                      + a->e35 * b->e155 + a->e55 * b->e135;
          res->e23555 = c->e23555 + a->e23 * b->e555 + a->e25 * b->e355 
                      + a->e35 * b->e255 + a->e55 * b->e235;
          res->e33555 = c->e33555 + a->e33 * b->e555 + a->e35 * b->e355 
                      + a->e55 * b->e335;
          res->e14555 = c->e14555 + a->e14 * b->e555 + a->e15 * b->e455 
                      + a->e45 * b->e155 + a->e55 * b->e145;
          res->e24555 = c->e24555 + a->e24 * b->e555 + a->e25 * b->e455 
                      + a->e45 * b->e255 + a->e55 * b->e245;
          res->e34555 = c->e34555 + a->e34 * b->e555 + a->e35 * b->e455 
                      + a->e45 * b->e355 + a->e55 * b->e345;
          res->e44555 = c->e44555 + a->e44 * b->e555 + a->e45 * b->e455 
                      + a->e55 * b->e445;
          res->e15555 = c->e15555 + a->e15 * b->e555 + a->e55 * b->e155;
          res->e25555 = c->e25555 + a->e25 * b->e555 + a->e55 * b->e255;
          res->e35555 = c->e35555 + a->e35 * b->e555 + a->e55 * b->e355;
          res->e45555 = c->e45555 + a->e45 * b->e555 + a->e55 * b->e455;
          res->e55555 = c->e55555 + a->e55 * b->e555;
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
          res->e1115 = c->e1115 + a->e115 * b->e1 + a->e111 * b->e5;
          res->e1125 = c->e1125 + a->e125 * b->e1 + a->e115 * b->e2 
                     + a->e112 * b->e5;
          res->e1225 = c->e1225 + a->e225 * b->e1 + a->e125 * b->e2 
                     + a->e122 * b->e5;
          res->e2225 = c->e2225 + a->e225 * b->e2 + a->e222 * b->e5;
          res->e1135 = c->e1135 + a->e135 * b->e1 + a->e115 * b->e3 
                     + a->e113 * b->e5;
          res->e1235 = c->e1235 + a->e235 * b->e1 + a->e135 * b->e2 
                     + a->e125 * b->e3 + a->e123 * b->e5;
          res->e2235 = c->e2235 + a->e235 * b->e2 + a->e225 * b->e3 
                     + a->e223 * b->e5;
          res->e1335 = c->e1335 + a->e335 * b->e1 + a->e135 * b->e3 
                     + a->e133 * b->e5;
          res->e2335 = c->e2335 + a->e335 * b->e2 + a->e235 * b->e3 
                     + a->e233 * b->e5;
          res->e3335 = c->e3335 + a->e335 * b->e3 + a->e333 * b->e5;
          res->e1145 = c->e1145 + a->e145 * b->e1 + a->e115 * b->e4 
                     + a->e114 * b->e5;
          res->e1245 = c->e1245 + a->e245 * b->e1 + a->e145 * b->e2 
                     + a->e125 * b->e4 + a->e124 * b->e5;
          res->e2245 = c->e2245 + a->e245 * b->e2 + a->e225 * b->e4 
                     + a->e224 * b->e5;
          res->e1345 = c->e1345 + a->e345 * b->e1 + a->e145 * b->e3 
                     + a->e135 * b->e4 + a->e134 * b->e5;
          res->e2345 = c->e2345 + a->e345 * b->e2 + a->e245 * b->e3 
                     + a->e235 * b->e4 + a->e234 * b->e5;
          res->e3345 = c->e3345 + a->e345 * b->e3 + a->e335 * b->e4 
                     + a->e334 * b->e5;
          res->e1445 = c->e1445 + a->e445 * b->e1 + a->e145 * b->e4 
                     + a->e144 * b->e5;
          res->e2445 = c->e2445 + a->e445 * b->e2 + a->e245 * b->e4 
                     + a->e244 * b->e5;
          res->e3445 = c->e3445 + a->e445 * b->e3 + a->e345 * b->e4 
                     + a->e344 * b->e5;
          res->e4445 = c->e4445 + a->e445 * b->e4 + a->e444 * b->e5;
          res->e1155 = c->e1155 + a->e155 * b->e1 + a->e115 * b->e5;
          res->e1255 = c->e1255 + a->e255 * b->e1 + a->e155 * b->e2 
                     + a->e125 * b->e5;
          res->e2255 = c->e2255 + a->e255 * b->e2 + a->e225 * b->e5;
          res->e1355 = c->e1355 + a->e355 * b->e1 + a->e155 * b->e3 
                     + a->e135 * b->e5;
          res->e2355 = c->e2355 + a->e355 * b->e2 + a->e255 * b->e3 
                     + a->e235 * b->e5;
          res->e3355 = c->e3355 + a->e355 * b->e3 + a->e335 * b->e5;
          res->e1455 = c->e1455 + a->e455 * b->e1 + a->e155 * b->e4 
                     + a->e145 * b->e5;
          res->e2455 = c->e2455 + a->e455 * b->e2 + a->e255 * b->e4 
                     + a->e245 * b->e5;
          res->e3455 = c->e3455 + a->e455 * b->e3 + a->e355 * b->e4 
                     + a->e345 * b->e5;
          res->e4455 = c->e4455 + a->e455 * b->e4 + a->e445 * b->e5;
          res->e1555 = c->e1555 + a->e555 * b->e1 + a->e155 * b->e5;
          res->e2555 = c->e2555 + a->e555 * b->e2 + a->e255 * b->e5;
          res->e3555 = c->e3555 + a->e555 * b->e3 + a->e355 * b->e5;
          res->e4555 = c->e4555 + a->e555 * b->e4 + a->e455 * b->e5;
          res->e5555 = c->e5555 + a->e555 * b->e5;
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
          res->e11115 = c->e11115 + a->e115 * b->e11 + a->e111 * b->e15;
          res->e11125 = c->e11125 + a->e125 * b->e11 + a->e115 * b->e12 
                      + a->e112 * b->e15 + a->e111 * b->e25;
          res->e11225 = c->e11225 + a->e225 * b->e11 + a->e125 * b->e12 
                      + a->e115 * b->e22 + a->e122 * b->e15 + a->e112 * b->e25;
          res->e12225 = c->e12225 + a->e225 * b->e12 + a->e125 * b->e22 
                      + a->e222 * b->e15 + a->e122 * b->e25;
          res->e22225 = c->e22225 + a->e225 * b->e22 + a->e222 * b->e25;
          res->e11135 = c->e11135 + a->e135 * b->e11 + a->e115 * b->e13 
                      + a->e113 * b->e15 + a->e111 * b->e35;
          res->e11235 = c->e11235 + a->e235 * b->e11 + a->e135 * b->e12 
                      + a->e125 * b->e13 + a->e115 * b->e23 + a->e123 * b->e15 
                      + a->e113 * b->e25 + a->e112 * b->e35;
          res->e12235 = c->e12235 + a->e235 * b->e12 + a->e135 * b->e22 
                      + a->e225 * b->e13 + a->e125 * b->e23 + a->e223 * b->e15 
                      + a->e123 * b->e25 + a->e122 * b->e35;
          res->e22235 = c->e22235 + a->e235 * b->e22 + a->e225 * b->e23 
                      + a->e223 * b->e25 + a->e222 * b->e35;
          res->e11335 = c->e11335 + a->e335 * b->e11 + a->e135 * b->e13 
                      + a->e115 * b->e33 + a->e133 * b->e15 + a->e113 * b->e35;
          res->e12335 = c->e12335 + a->e335 * b->e12 + a->e235 * b->e13 
                      + a->e135 * b->e23 + a->e125 * b->e33 + a->e233 * b->e15 
                      + a->e133 * b->e25 + a->e123 * b->e35;
          res->e22335 = c->e22335 + a->e335 * b->e22 + a->e235 * b->e23 
                      + a->e225 * b->e33 + a->e233 * b->e25 + a->e223 * b->e35;
          res->e13335 = c->e13335 + a->e335 * b->e13 + a->e135 * b->e33 
                      + a->e333 * b->e15 + a->e133 * b->e35;
          res->e23335 = c->e23335 + a->e335 * b->e23 + a->e235 * b->e33 
                      + a->e333 * b->e25 + a->e233 * b->e35;
          res->e33335 = c->e33335 + a->e335 * b->e33 + a->e333 * b->e35;
          res->e11145 = c->e11145 + a->e145 * b->e11 + a->e115 * b->e14 
                      + a->e114 * b->e15 + a->e111 * b->e45;
          res->e11245 = c->e11245 + a->e245 * b->e11 + a->e145 * b->e12 
                      + a->e125 * b->e14 + a->e115 * b->e24 + a->e124 * b->e15 
                      + a->e114 * b->e25 + a->e112 * b->e45;
          res->e12245 = c->e12245 + a->e245 * b->e12 + a->e145 * b->e22 
                      + a->e225 * b->e14 + a->e125 * b->e24 + a->e224 * b->e15 
                      + a->e124 * b->e25 + a->e122 * b->e45;
          res->e22245 = c->e22245 + a->e245 * b->e22 + a->e225 * b->e24 
                      + a->e224 * b->e25 + a->e222 * b->e45;
          res->e11345 = c->e11345 + a->e345 * b->e11 + a->e145 * b->e13 
                      + a->e135 * b->e14 + a->e115 * b->e34 + a->e134 * b->e15 
                      + a->e114 * b->e35 + a->e113 * b->e45;
          res->e12345 = c->e12345 + a->e345 * b->e12 + a->e245 * b->e13 
                      + a->e145 * b->e23 + a->e235 * b->e14 + a->e135 * b->e24 
                      + a->e125 * b->e34 + a->e234 * b->e15 + a->e134 * b->e25 
                      + a->e124 * b->e35 + a->e123 * b->e45;
          res->e22345 = c->e22345 + a->e345 * b->e22 + a->e245 * b->e23 
                      + a->e235 * b->e24 + a->e225 * b->e34 + a->e234 * b->e25 
                      + a->e224 * b->e35 + a->e223 * b->e45;
          res->e13345 = c->e13345 + a->e345 * b->e13 + a->e145 * b->e33 
                      + a->e335 * b->e14 + a->e135 * b->e34 + a->e334 * b->e15 
                      + a->e134 * b->e35 + a->e133 * b->e45;
          res->e23345 = c->e23345 + a->e345 * b->e23 + a->e245 * b->e33 
                      + a->e335 * b->e24 + a->e235 * b->e34 + a->e334 * b->e25 
                      + a->e234 * b->e35 + a->e233 * b->e45;
          res->e33345 = c->e33345 + a->e345 * b->e33 + a->e335 * b->e34 
                      + a->e334 * b->e35 + a->e333 * b->e45;
          res->e11445 = c->e11445 + a->e445 * b->e11 + a->e145 * b->e14 
                      + a->e115 * b->e44 + a->e144 * b->e15 + a->e114 * b->e45;
          res->e12445 = c->e12445 + a->e445 * b->e12 + a->e245 * b->e14 
                      + a->e145 * b->e24 + a->e125 * b->e44 + a->e244 * b->e15 
                      + a->e144 * b->e25 + a->e124 * b->e45;
          res->e22445 = c->e22445 + a->e445 * b->e22 + a->e245 * b->e24 
                      + a->e225 * b->e44 + a->e244 * b->e25 + a->e224 * b->e45;
          res->e13445 = c->e13445 + a->e445 * b->e13 + a->e345 * b->e14 
                      + a->e145 * b->e34 + a->e135 * b->e44 + a->e344 * b->e15 
                      + a->e144 * b->e35 + a->e134 * b->e45;
          res->e23445 = c->e23445 + a->e445 * b->e23 + a->e345 * b->e24 
                      + a->e245 * b->e34 + a->e235 * b->e44 + a->e344 * b->e25 
                      + a->e244 * b->e35 + a->e234 * b->e45;
          res->e33445 = c->e33445 + a->e445 * b->e33 + a->e345 * b->e34 
                      + a->e335 * b->e44 + a->e344 * b->e35 + a->e334 * b->e45;
          res->e14445 = c->e14445 + a->e445 * b->e14 + a->e145 * b->e44 
                      + a->e444 * b->e15 + a->e144 * b->e45;
          res->e24445 = c->e24445 + a->e445 * b->e24 + a->e245 * b->e44 
                      + a->e444 * b->e25 + a->e244 * b->e45;
          res->e34445 = c->e34445 + a->e445 * b->e34 + a->e345 * b->e44 
                      + a->e444 * b->e35 + a->e344 * b->e45;
          res->e44445 = c->e44445 + a->e445 * b->e44 + a->e444 * b->e45;
          res->e11155 = c->e11155 + a->e155 * b->e11 + a->e115 * b->e15 
                      + a->e111 * b->e55;
          res->e11255 = c->e11255 + a->e255 * b->e11 + a->e155 * b->e12 
                      + a->e125 * b->e15 + a->e115 * b->e25 + a->e112 * b->e55;
          res->e12255 = c->e12255 + a->e255 * b->e12 + a->e155 * b->e22 
                      + a->e225 * b->e15 + a->e125 * b->e25 + a->e122 * b->e55;
          res->e22255 = c->e22255 + a->e255 * b->e22 + a->e225 * b->e25 
                      + a->e222 * b->e55;
          res->e11355 = c->e11355 + a->e355 * b->e11 + a->e155 * b->e13 
                      + a->e135 * b->e15 + a->e115 * b->e35 + a->e113 * b->e55;
          res->e12355 = c->e12355 + a->e355 * b->e12 + a->e255 * b->e13 
                      + a->e155 * b->e23 + a->e235 * b->e15 + a->e135 * b->e25 
                      + a->e125 * b->e35 + a->e123 * b->e55;
          res->e22355 = c->e22355 + a->e355 * b->e22 + a->e255 * b->e23 
                      + a->e235 * b->e25 + a->e225 * b->e35 + a->e223 * b->e55;
          res->e13355 = c->e13355 + a->e355 * b->e13 + a->e155 * b->e33 
                      + a->e335 * b->e15 + a->e135 * b->e35 + a->e133 * b->e55;
          res->e23355 = c->e23355 + a->e355 * b->e23 + a->e255 * b->e33 
                      + a->e335 * b->e25 + a->e235 * b->e35 + a->e233 * b->e55;
          res->e33355 = c->e33355 + a->e355 * b->e33 + a->e335 * b->e35 
                      + a->e333 * b->e55;
          res->e11455 = c->e11455 + a->e455 * b->e11 + a->e155 * b->e14 
                      + a->e145 * b->e15 + a->e115 * b->e45 + a->e114 * b->e55;
          res->e12455 = c->e12455 + a->e455 * b->e12 + a->e255 * b->e14 
                      + a->e155 * b->e24 + a->e245 * b->e15 + a->e145 * b->e25 
                      + a->e125 * b->e45 + a->e124 * b->e55;
          res->e22455 = c->e22455 + a->e455 * b->e22 + a->e255 * b->e24 
                      + a->e245 * b->e25 + a->e225 * b->e45 + a->e224 * b->e55;
          res->e13455 = c->e13455 + a->e455 * b->e13 + a->e355 * b->e14 
                      + a->e155 * b->e34 + a->e345 * b->e15 + a->e145 * b->e35 
                      + a->e135 * b->e45 + a->e134 * b->e55;
          res->e23455 = c->e23455 + a->e455 * b->e23 + a->e355 * b->e24 
                      + a->e255 * b->e34 + a->e345 * b->e25 + a->e245 * b->e35 
                      + a->e235 * b->e45 + a->e234 * b->e55;
          res->e33455 = c->e33455 + a->e455 * b->e33 + a->e355 * b->e34 
                      + a->e345 * b->e35 + a->e335 * b->e45 + a->e334 * b->e55;
          res->e14455 = c->e14455 + a->e455 * b->e14 + a->e155 * b->e44 
                      + a->e445 * b->e15 + a->e145 * b->e45 + a->e144 * b->e55;
          res->e24455 = c->e24455 + a->e455 * b->e24 + a->e255 * b->e44 
                      + a->e445 * b->e25 + a->e245 * b->e45 + a->e244 * b->e55;
          res->e34455 = c->e34455 + a->e455 * b->e34 + a->e355 * b->e44 
                      + a->e445 * b->e35 + a->e345 * b->e45 + a->e344 * b->e55;
          res->e44455 = c->e44455 + a->e455 * b->e44 + a->e445 * b->e45 
                      + a->e444 * b->e55;
          res->e11555 = c->e11555 + a->e555 * b->e11 + a->e155 * b->e15 
                      + a->e115 * b->e55;
          res->e12555 = c->e12555 + a->e555 * b->e12 + a->e255 * b->e15 
                      + a->e155 * b->e25 + a->e125 * b->e55;
          res->e22555 = c->e22555 + a->e555 * b->e22 + a->e255 * b->e25 
                      + a->e225 * b->e55;
          res->e13555 = c->e13555 + a->e555 * b->e13 + a->e355 * b->e15 
                      + a->e155 * b->e35 + a->e135 * b->e55;
          res->e23555 = c->e23555 + a->e555 * b->e23 + a->e355 * b->e25 
                      + a->e255 * b->e35 + a->e235 * b->e55;
          res->e33555 = c->e33555 + a->e555 * b->e33 + a->e355 * b->e35 
                      + a->e335 * b->e55;
          res->e14555 = c->e14555 + a->e555 * b->e14 + a->e455 * b->e15 
                      + a->e155 * b->e45 + a->e145 * b->e55;
          res->e24555 = c->e24555 + a->e555 * b->e24 + a->e455 * b->e25 
                      + a->e255 * b->e45 + a->e245 * b->e55;
          res->e34555 = c->e34555 + a->e555 * b->e34 + a->e455 * b->e35 
                      + a->e355 * b->e45 + a->e345 * b->e55;
          res->e44555 = c->e44555 + a->e555 * b->e44 + a->e455 * b->e45 
                      + a->e445 * b->e55;
          res->e15555 = c->e15555 + a->e555 * b->e15 + a->e155 * b->e55;
          res->e25555 = c->e25555 + a->e555 * b->e25 + a->e255 * b->e55;
          res->e35555 = c->e35555 + a->e555 * b->e35 + a->e355 * b->e55;
          res->e45555 = c->e45555 + a->e555 * b->e45 + a->e455 * b->e55;
          res->e55555 = c->e55555 + a->e555 * b->e55;
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
          res->e1115 = c->e1115 + a->e1115 * b->r;
          res->e1125 = c->e1125 + a->e1125 * b->r;
          res->e1225 = c->e1225 + a->e1225 * b->r;
          res->e2225 = c->e2225 + a->e2225 * b->r;
          res->e1135 = c->e1135 + a->e1135 * b->r;
          res->e1235 = c->e1235 + a->e1235 * b->r;
          res->e2235 = c->e2235 + a->e2235 * b->r;
          res->e1335 = c->e1335 + a->e1335 * b->r;
          res->e2335 = c->e2335 + a->e2335 * b->r;
          res->e3335 = c->e3335 + a->e3335 * b->r;
          res->e1145 = c->e1145 + a->e1145 * b->r;
          res->e1245 = c->e1245 + a->e1245 * b->r;
          res->e2245 = c->e2245 + a->e2245 * b->r;
          res->e1345 = c->e1345 + a->e1345 * b->r;
          res->e2345 = c->e2345 + a->e2345 * b->r;
          res->e3345 = c->e3345 + a->e3345 * b->r;
          res->e1445 = c->e1445 + a->e1445 * b->r;
          res->e2445 = c->e2445 + a->e2445 * b->r;
          res->e3445 = c->e3445 + a->e3445 * b->r;
          res->e4445 = c->e4445 + a->e4445 * b->r;
          res->e1155 = c->e1155 + a->e1155 * b->r;
          res->e1255 = c->e1255 + a->e1255 * b->r;
          res->e2255 = c->e2255 + a->e2255 * b->r;
          res->e1355 = c->e1355 + a->e1355 * b->r;
          res->e2355 = c->e2355 + a->e2355 * b->r;
          res->e3355 = c->e3355 + a->e3355 * b->r;
          res->e1455 = c->e1455 + a->e1455 * b->r;
          res->e2455 = c->e2455 + a->e2455 * b->r;
          res->e3455 = c->e3455 + a->e3455 * b->r;
          res->e4455 = c->e4455 + a->e4455 * b->r;
          res->e1555 = c->e1555 + a->e1555 * b->r;
          res->e2555 = c->e2555 + a->e2555 * b->r;
          res->e3555 = c->e3555 + a->e3555 * b->r;
          res->e4555 = c->e4555 + a->e4555 * b->r;
          res->e5555 = c->e5555 + a->e5555 * b->r;
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
          res->e11115 = c->e11115 + a->e1115 * b->e1 + a->e1111 * b->e5;
          res->e11125 = c->e11125 + a->e1125 * b->e1 + a->e1115 * b->e2 
                      + a->e1112 * b->e5;
          res->e11225 = c->e11225 + a->e1225 * b->e1 + a->e1125 * b->e2 
                      + a->e1122 * b->e5;
          res->e12225 = c->e12225 + a->e2225 * b->e1 + a->e1225 * b->e2 
                      + a->e1222 * b->e5;
          res->e22225 = c->e22225 + a->e2225 * b->e2 + a->e2222 * b->e5;
          res->e11135 = c->e11135 + a->e1135 * b->e1 + a->e1115 * b->e3 
                      + a->e1113 * b->e5;
          res->e11235 = c->e11235 + a->e1235 * b->e1 + a->e1135 * b->e2 
                      + a->e1125 * b->e3 + a->e1123 * b->e5;
          res->e12235 = c->e12235 + a->e2235 * b->e1 + a->e1235 * b->e2 
                      + a->e1225 * b->e3 + a->e1223 * b->e5;
          res->e22235 = c->e22235 + a->e2235 * b->e2 + a->e2225 * b->e3 
                      + a->e2223 * b->e5;
          res->e11335 = c->e11335 + a->e1335 * b->e1 + a->e1135 * b->e3 
                      + a->e1133 * b->e5;
          res->e12335 = c->e12335 + a->e2335 * b->e1 + a->e1335 * b->e2 
                      + a->e1235 * b->e3 + a->e1233 * b->e5;
          res->e22335 = c->e22335 + a->e2335 * b->e2 + a->e2235 * b->e3 
                      + a->e2233 * b->e5;
          res->e13335 = c->e13335 + a->e3335 * b->e1 + a->e1335 * b->e3 
                      + a->e1333 * b->e5;
          res->e23335 = c->e23335 + a->e3335 * b->e2 + a->e2335 * b->e3 
                      + a->e2333 * b->e5;
          res->e33335 = c->e33335 + a->e3335 * b->e3 + a->e3333 * b->e5;
          res->e11145 = c->e11145 + a->e1145 * b->e1 + a->e1115 * b->e4 
                      + a->e1114 * b->e5;
          res->e11245 = c->e11245 + a->e1245 * b->e1 + a->e1145 * b->e2 
                      + a->e1125 * b->e4 + a->e1124 * b->e5;
          res->e12245 = c->e12245 + a->e2245 * b->e1 + a->e1245 * b->e2 
                      + a->e1225 * b->e4 + a->e1224 * b->e5;
          res->e22245 = c->e22245 + a->e2245 * b->e2 + a->e2225 * b->e4 
                      + a->e2224 * b->e5;
          res->e11345 = c->e11345 + a->e1345 * b->e1 + a->e1145 * b->e3 
                      + a->e1135 * b->e4 + a->e1134 * b->e5;
          res->e12345 = c->e12345 + a->e2345 * b->e1 + a->e1345 * b->e2 
                      + a->e1245 * b->e3 + a->e1235 * b->e4 + a->e1234 * b->e5;
          res->e22345 = c->e22345 + a->e2345 * b->e2 + a->e2245 * b->e3 
                      + a->e2235 * b->e4 + a->e2234 * b->e5;
          res->e13345 = c->e13345 + a->e3345 * b->e1 + a->e1345 * b->e3 
                      + a->e1335 * b->e4 + a->e1334 * b->e5;
          res->e23345 = c->e23345 + a->e3345 * b->e2 + a->e2345 * b->e3 
                      + a->e2335 * b->e4 + a->e2334 * b->e5;
          res->e33345 = c->e33345 + a->e3345 * b->e3 + a->e3335 * b->e4 
                      + a->e3334 * b->e5;
          res->e11445 = c->e11445 + a->e1445 * b->e1 + a->e1145 * b->e4 
                      + a->e1144 * b->e5;
          res->e12445 = c->e12445 + a->e2445 * b->e1 + a->e1445 * b->e2 
                      + a->e1245 * b->e4 + a->e1244 * b->e5;
          res->e22445 = c->e22445 + a->e2445 * b->e2 + a->e2245 * b->e4 
                      + a->e2244 * b->e5;
          res->e13445 = c->e13445 + a->e3445 * b->e1 + a->e1445 * b->e3 
                      + a->e1345 * b->e4 + a->e1344 * b->e5;
          res->e23445 = c->e23445 + a->e3445 * b->e2 + a->e2445 * b->e3 
                      + a->e2345 * b->e4 + a->e2344 * b->e5;
          res->e33445 = c->e33445 + a->e3445 * b->e3 + a->e3345 * b->e4 
                      + a->e3344 * b->e5;
          res->e14445 = c->e14445 + a->e4445 * b->e1 + a->e1445 * b->e4 
                      + a->e1444 * b->e5;
          res->e24445 = c->e24445 + a->e4445 * b->e2 + a->e2445 * b->e4 
                      + a->e2444 * b->e5;
          res->e34445 = c->e34445 + a->e4445 * b->e3 + a->e3445 * b->e4 
                      + a->e3444 * b->e5;
          res->e44445 = c->e44445 + a->e4445 * b->e4 + a->e4444 * b->e5;
          res->e11155 = c->e11155 + a->e1155 * b->e1 + a->e1115 * b->e5;
          res->e11255 = c->e11255 + a->e1255 * b->e1 + a->e1155 * b->e2 
                      + a->e1125 * b->e5;
          res->e12255 = c->e12255 + a->e2255 * b->e1 + a->e1255 * b->e2 
                      + a->e1225 * b->e5;
          res->e22255 = c->e22255 + a->e2255 * b->e2 + a->e2225 * b->e5;
          res->e11355 = c->e11355 + a->e1355 * b->e1 + a->e1155 * b->e3 
                      + a->e1135 * b->e5;
          res->e12355 = c->e12355 + a->e2355 * b->e1 + a->e1355 * b->e2 
                      + a->e1255 * b->e3 + a->e1235 * b->e5;
          res->e22355 = c->e22355 + a->e2355 * b->e2 + a->e2255 * b->e3 
                      + a->e2235 * b->e5;
          res->e13355 = c->e13355 + a->e3355 * b->e1 + a->e1355 * b->e3 
                      + a->e1335 * b->e5;
          res->e23355 = c->e23355 + a->e3355 * b->e2 + a->e2355 * b->e3 
                      + a->e2335 * b->e5;
          res->e33355 = c->e33355 + a->e3355 * b->e3 + a->e3335 * b->e5;
          res->e11455 = c->e11455 + a->e1455 * b->e1 + a->e1155 * b->e4 
                      + a->e1145 * b->e5;
          res->e12455 = c->e12455 + a->e2455 * b->e1 + a->e1455 * b->e2 
                      + a->e1255 * b->e4 + a->e1245 * b->e5;
          res->e22455 = c->e22455 + a->e2455 * b->e2 + a->e2255 * b->e4 
                      + a->e2245 * b->e5;
          res->e13455 = c->e13455 + a->e3455 * b->e1 + a->e1455 * b->e3 
                      + a->e1355 * b->e4 + a->e1345 * b->e5;
          res->e23455 = c->e23455 + a->e3455 * b->e2 + a->e2455 * b->e3 
                      + a->e2355 * b->e4 + a->e2345 * b->e5;
          res->e33455 = c->e33455 + a->e3455 * b->e3 + a->e3355 * b->e4 
                      + a->e3345 * b->e5;
          res->e14455 = c->e14455 + a->e4455 * b->e1 + a->e1455 * b->e4 
                      + a->e1445 * b->e5;
          res->e24455 = c->e24455 + a->e4455 * b->e2 + a->e2455 * b->e4 
                      + a->e2445 * b->e5;
          res->e34455 = c->e34455 + a->e4455 * b->e3 + a->e3455 * b->e4 
                      + a->e3445 * b->e5;
          res->e44455 = c->e44455 + a->e4455 * b->e4 + a->e4445 * b->e5;
          res->e11555 = c->e11555 + a->e1555 * b->e1 + a->e1155 * b->e5;
          res->e12555 = c->e12555 + a->e2555 * b->e1 + a->e1555 * b->e2 
                      + a->e1255 * b->e5;
          res->e22555 = c->e22555 + a->e2555 * b->e2 + a->e2255 * b->e5;
          res->e13555 = c->e13555 + a->e3555 * b->e1 + a->e1555 * b->e3 
                      + a->e1355 * b->e5;
          res->e23555 = c->e23555 + a->e3555 * b->e2 + a->e2555 * b->e3 
                      + a->e2355 * b->e5;
          res->e33555 = c->e33555 + a->e3555 * b->e3 + a->e3355 * b->e5;
          res->e14555 = c->e14555 + a->e4555 * b->e1 + a->e1555 * b->e4 
                      + a->e1455 * b->e5;
          res->e24555 = c->e24555 + a->e4555 * b->e2 + a->e2555 * b->e4 
                      + a->e2455 * b->e5;
          res->e34555 = c->e34555 + a->e4555 * b->e3 + a->e3555 * b->e4 
                      + a->e3455 * b->e5;
          res->e44555 = c->e44555 + a->e4555 * b->e4 + a->e4455 * b->e5;
          res->e15555 = c->e15555 + a->e5555 * b->e1 + a->e1555 * b->e5;
          res->e25555 = c->e25555 + a->e5555 * b->e2 + a->e2555 * b->e5;
          res->e35555 = c->e35555 + a->e5555 * b->e3 + a->e3555 * b->e5;
          res->e45555 = c->e45555 + a->e5555 * b->e4 + a->e4555 * b->e5;
          res->e55555 = c->e55555 + a->e5555 * b->e5;
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
          res->e11115 = c->e11115 + a->e11115 * b->r;
          res->e11125 = c->e11125 + a->e11125 * b->r;
          res->e11225 = c->e11225 + a->e11225 * b->r;
          res->e12225 = c->e12225 + a->e12225 * b->r;
          res->e22225 = c->e22225 + a->e22225 * b->r;
          res->e11135 = c->e11135 + a->e11135 * b->r;
          res->e11235 = c->e11235 + a->e11235 * b->r;
          res->e12235 = c->e12235 + a->e12235 * b->r;
          res->e22235 = c->e22235 + a->e22235 * b->r;
          res->e11335 = c->e11335 + a->e11335 * b->r;
          res->e12335 = c->e12335 + a->e12335 * b->r;
          res->e22335 = c->e22335 + a->e22335 * b->r;
          res->e13335 = c->e13335 + a->e13335 * b->r;
          res->e23335 = c->e23335 + a->e23335 * b->r;
          res->e33335 = c->e33335 + a->e33335 * b->r;
          res->e11145 = c->e11145 + a->e11145 * b->r;
          res->e11245 = c->e11245 + a->e11245 * b->r;
          res->e12245 = c->e12245 + a->e12245 * b->r;
          res->e22245 = c->e22245 + a->e22245 * b->r;
          res->e11345 = c->e11345 + a->e11345 * b->r;
          res->e12345 = c->e12345 + a->e12345 * b->r;
          res->e22345 = c->e22345 + a->e22345 * b->r;
          res->e13345 = c->e13345 + a->e13345 * b->r;
          res->e23345 = c->e23345 + a->e23345 * b->r;
          res->e33345 = c->e33345 + a->e33345 * b->r;
          res->e11445 = c->e11445 + a->e11445 * b->r;
          res->e12445 = c->e12445 + a->e12445 * b->r;
          res->e22445 = c->e22445 + a->e22445 * b->r;
          res->e13445 = c->e13445 + a->e13445 * b->r;
          res->e23445 = c->e23445 + a->e23445 * b->r;
          res->e33445 = c->e33445 + a->e33445 * b->r;
          res->e14445 = c->e14445 + a->e14445 * b->r;
          res->e24445 = c->e24445 + a->e24445 * b->r;
          res->e34445 = c->e34445 + a->e34445 * b->r;
          res->e44445 = c->e44445 + a->e44445 * b->r;
          res->e11155 = c->e11155 + a->e11155 * b->r;
          res->e11255 = c->e11255 + a->e11255 * b->r;
          res->e12255 = c->e12255 + a->e12255 * b->r;
          res->e22255 = c->e22255 + a->e22255 * b->r;
          res->e11355 = c->e11355 + a->e11355 * b->r;
          res->e12355 = c->e12355 + a->e12355 * b->r;
          res->e22355 = c->e22355 + a->e22355 * b->r;
          res->e13355 = c->e13355 + a->e13355 * b->r;
          res->e23355 = c->e23355 + a->e23355 * b->r;
          res->e33355 = c->e33355 + a->e33355 * b->r;
          res->e11455 = c->e11455 + a->e11455 * b->r;
          res->e12455 = c->e12455 + a->e12455 * b->r;
          res->e22455 = c->e22455 + a->e22455 * b->r;
          res->e13455 = c->e13455 + a->e13455 * b->r;
          res->e23455 = c->e23455 + a->e23455 * b->r;
          res->e33455 = c->e33455 + a->e33455 * b->r;
          res->e14455 = c->e14455 + a->e14455 * b->r;
          res->e24455 = c->e24455 + a->e24455 * b->r;
          res->e34455 = c->e34455 + a->e34455 * b->r;
          res->e44455 = c->e44455 + a->e44455 * b->r;
          res->e11555 = c->e11555 + a->e11555 * b->r;
          res->e12555 = c->e12555 + a->e12555 * b->r;
          res->e22555 = c->e22555 + a->e22555 * b->r;
          res->e13555 = c->e13555 + a->e13555 * b->r;
          res->e23555 = c->e23555 + a->e23555 * b->r;
          res->e33555 = c->e33555 + a->e33555 * b->r;
          res->e14555 = c->e14555 + a->e14555 * b->r;
          res->e24555 = c->e24555 + a->e24555 * b->r;
          res->e34555 = c->e34555 + a->e34555 * b->r;
          res->e44555 = c->e44555 + a->e44555 * b->r;
          res->e15555 = c->e15555 + a->e15555 * b->r;
          res->e25555 = c->e25555 + a->e25555 * b->r;
          res->e35555 = c->e35555 + a->e35555 * b->r;
          res->e45555 = c->e45555 + a->e45555 * b->r;
          res->e55555 = c->e55555 + a->e55555 * b->r;
          break;
      }
      break;
  }

}

onumm5n5_t onumm5n5_feval(coeff_t* feval_re, onumm5n5_t* x){

  onumm5n5_t res;

  // feval function
  //  Definitions
  coeff_t factor=1, coef = 0;
  onumm5n5_t deltax = (*x), deltax_power = (*x);
  deltax.r = 0.0;
  deltax_power.r = 0.0;
  onumm5n5_set_r(0.0, &res);
  //  Real
  res.r = feval_re[0];
  // Order 1
  factor *=1;
  coef    = feval_re[1]/ factor;;
  onumm5n5_gem_ro_to( coef, &deltax_power, &res, &res);
  deltax_power = onumm5n5_mul_oo(&deltax_power,&deltax);
  // Order 2
  factor *=2;
  coef    = feval_re[2]/ factor;;
  onumm5n5_gem_ro_to( coef, &deltax_power, &res, &res);
  deltax_power = onumm5n5_mul_oo(&deltax_power,&deltax);
  // Order 3
  factor *=3;
  coef    = feval_re[3]/ factor;;
  onumm5n5_gem_ro_to( coef, &deltax_power, &res, &res);
  deltax_power = onumm5n5_mul_oo(&deltax_power,&deltax);
  // Order 4
  factor *=4;
  coef    = feval_re[4]/ factor;;
  onumm5n5_gem_ro_to( coef, &deltax_power, &res, &res);
  deltax_power = onumm5n5_mul_oo(&deltax_power,&deltax);
  // Order 5
  factor *=5;
  coef    = feval_re[5]/ factor;;
  onumm5n5_gem_ro_to( coef, &deltax_power, &res, &res);

  return res;

}

void onumm5n5_feval_to(coeff_t* feval_re, onumm5n5_t* x, onumm5n5_t* res){

  // feval function
  //  Definitions
  coeff_t factor=1, coef = 0;
  onumm5n5_t deltax = (*x), deltax_power = (*x);
  deltax.r = 0.0;
  deltax_power.r = 0.0;
  onumm5n5_set_r(0.0, res);
  //  Real
  res->r = feval_re[0];
  // Order 1
  factor *=1;
  coef    = feval_re[1]/ factor;;
  onumm5n5_gem_ro_to( coef, &deltax_power, res, res);
  deltax_power = onumm5n5_mul_oo(&deltax_power,&deltax);
  // Order 2
  factor *=2;
  coef    = feval_re[2]/ factor;;
  onumm5n5_gem_ro_to( coef, &deltax_power, res, res);
  deltax_power = onumm5n5_mul_oo(&deltax_power,&deltax);
  // Order 3
  factor *=3;
  coef    = feval_re[3]/ factor;;
  onumm5n5_gem_ro_to( coef, &deltax_power, res, res);
  deltax_power = onumm5n5_mul_oo(&deltax_power,&deltax);
  // Order 4
  factor *=4;
  coef    = feval_re[4]/ factor;;
  onumm5n5_gem_ro_to( coef, &deltax_power, res, res);
  deltax_power = onumm5n5_mul_oo(&deltax_power,&deltax);
  // Order 5
  factor *=5;
  coef    = feval_re[5]/ factor;;
  onumm5n5_gem_ro_to( coef, &deltax_power, res, res);

}

