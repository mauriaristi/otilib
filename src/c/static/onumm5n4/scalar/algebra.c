
// Division.

// ****************************************************************************************************
onumm5n4_t onumm5n4_div_ro(coeff_t num, onumm5n4_t* den){

    
    onumm5n4_t inv = onumm5n4_pow(den,-1);
    onumm5n4_t res = onumm5n4_mul_ro(num,&inv);

    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
onumm5n4_t onumm5n4_div_oo(onumm5n4_t* num, onumm5n4_t* den){

    
    onumm5n4_t inv = onumm5n4_init();
    onumm5n4_pow_to(den,-1,&inv);
    onumm5n4_t res = onumm5n4_mul_oo(num,&inv);
    
    return res;

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
onumm5n4_t onumm5n4_div_or(onumm5n4_t* num, coeff_t val){

    return onumm5n4_mul_ro(1.0/val,num);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
onumm5n4_t onumm5n4_abs(onumm5n4_t* num){

	onumm5n4_t res;
    onumm5n4_abs_to(num,&res);
    return res;

}
// ----------------------------------------------------------------------------------------------------

onumm5n4_t onumm5n4_neg(  onumm5n4_t* lhs){

  onumm5n4_t res;

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

  return res;

}

void onumm5n4_neg_to(  onumm5n4_t* lhs, onumm5n4_t* res){

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

}

onumm5n4_t onumm5n4_sum_oo(  onumm5n4_t* lhs,  onumm5n4_t* rhs){
  onumm5n4_t res;

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

  return res;

}

void onumm5n4_sum_oo_to(  onumm5n4_t* lhs,  onumm5n4_t* rhs, onumm5n4_t* res){
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

}

onumm5n4_t onumm5n4_sum_ro(  coeff_t lhs,  onumm5n4_t* rhs){
  onumm5n4_t res;

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

  return res;

}

void onumm5n4_sum_ro_to(  coeff_t lhs,  onumm5n4_t* rhs, onumm5n4_t* res){
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

}

onumm5n4_t onumm5n4_sub_oo(  onumm5n4_t* lhs,  onumm5n4_t* rhs){
  onumm5n4_t res;

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

  return res;

}

void onumm5n4_sub_oo_to(  onumm5n4_t* lhs,  onumm5n4_t* rhs, onumm5n4_t* res){
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

}

onumm5n4_t onumm5n4_sub_ro(  coeff_t lhs,  onumm5n4_t* rhs){
  onumm5n4_t res;

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

  return res;

}

void onumm5n4_sub_ro_to(  coeff_t lhs,  onumm5n4_t* rhs, onumm5n4_t* res){
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

}

onumm5n4_t onumm5n4_sub_or(  onumm5n4_t* lhs,  coeff_t rhs){
  onumm5n4_t res;

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

  return res;

}

void onumm5n4_sub_or_to(  onumm5n4_t* lhs,  coeff_t rhs, onumm5n4_t* res){
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

}

onumm5n4_t onumm5n4_mul_oo(  onumm5n4_t* lhs,  onumm5n4_t* rhs){
  onumm5n4_t res;

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

  return res;

}

void onumm5n4_mul_oo_to(  onumm5n4_t* lhs,  onumm5n4_t* rhs, onumm5n4_t* res){
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

}

onumm5n4_t onumm5n4_mul_ro(  coeff_t lhs,  onumm5n4_t* rhs){
  onumm5n4_t res;

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

  return res;

}

void onumm5n4_mul_ro_to(  coeff_t lhs,  onumm5n4_t* rhs, onumm5n4_t* res){
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

}

onumm5n4_t onumm5n4_trunc_mul_oo(  onumm5n4_t* lhs,  onumm5n4_t* rhs){
  onumm5n4_t res;

  res = onumm5n4_init();

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

  return res;

}

void onumm5n4_trunc_mul_oo_to(  onumm5n4_t* lhs,  onumm5n4_t* rhs, onumm5n4_t* res){
   (*res) = onumm5n4_init();

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

}

onumm5n4_t onumm5n4_gem_oo(  onumm5n4_t* a,  onumm5n4_t* b,  onumm5n4_t* c){
  onumm5n4_t res;

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

  return res;

}

void onumm5n4_gem_oo_to(  onumm5n4_t* a,  onumm5n4_t* b,  onumm5n4_t* c, onumm5n4_t* res){
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

}

onumm5n4_t onumm5n4_gem_ro(  coeff_t a,  onumm5n4_t* b,  onumm5n4_t* c){
  onumm5n4_t res;

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

  return res;

}

void onumm5n4_gem_ro_to(  coeff_t a,  onumm5n4_t* b,  onumm5n4_t* c, onumm5n4_t* res){
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

}

void onumm5n4_trunc_gem_oo_to( ord_t ord_lhs,  onumm5n4_t* a,  ord_t ord_rhs,  onumm5n4_t* b,  onumm5n4_t* c, onumm5n4_t* res){
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
      }
      break;
  }

}

void onumm5n4_trunc_sum_oo_to(ord_t order, onumm5n4_t* lhs,onumm5n4_t* rhs, onumm5n4_t* res){
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
      break;
  }
}

void onumm5n4_trunc_sub_oo_to(ord_t order, onumm5n4_t* lhs,onumm5n4_t* rhs, onumm5n4_t* res){
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
      break;
  }
}

onumm5n4_t onumm5n4_feval(coeff_t* feval_re, onumm5n4_t* x){

  onumm5n4_t res;

  // feval function
  //  Definitions
  coeff_t factor=1, coef = 0;
  onumm5n4_t deltax = (*x), deltax_power = (*x);
  deltax.r = 0.0;
  deltax_power.r = 0.0;
  onumm5n4_set_r(0.0, &res);
  //  Real
  res.r = feval_re[0];
  // Order 1
  factor *=1;
  coef    = feval_re[1]/ factor;;
  onumm5n4_gem_ro_to( coef, &deltax_power, &res, &res);
  deltax_power = onumm5n4_mul_oo(&deltax_power,&deltax);
  // Order 2
  factor *=2;
  coef    = feval_re[2]/ factor;;
  onumm5n4_gem_ro_to( coef, &deltax_power, &res, &res);
  deltax_power = onumm5n4_mul_oo(&deltax_power,&deltax);
  // Order 3
  factor *=3;
  coef    = feval_re[3]/ factor;;
  onumm5n4_gem_ro_to( coef, &deltax_power, &res, &res);
  deltax_power = onumm5n4_mul_oo(&deltax_power,&deltax);
  // Order 4
  factor *=4;
  coef    = feval_re[4]/ factor;;
  onumm5n4_gem_ro_to( coef, &deltax_power, &res, &res);

  return res;

}

void onumm5n4_feval_to(coeff_t* feval_re, onumm5n4_t* x, onumm5n4_t* res){

  // feval function
  //  Definitions
  coeff_t factor=1, coef = 0;
  onumm5n4_t deltax = (*x), deltax_power = (*x);
  deltax.r = 0.0;
  deltax_power.r = 0.0;
  onumm5n4_set_r(0.0, res);
  //  Real
  res->r = feval_re[0];
  // Order 1
  factor *=1;
  coef    = feval_re[1]/ factor;;
  onumm5n4_gem_ro_to( coef, &deltax_power, res, res);
  deltax_power = onumm5n4_mul_oo(&deltax_power,&deltax);
  // Order 2
  factor *=2;
  coef    = feval_re[2]/ factor;;
  onumm5n4_gem_ro_to( coef, &deltax_power, res, res);
  deltax_power = onumm5n4_mul_oo(&deltax_power,&deltax);
  // Order 3
  factor *=3;
  coef    = feval_re[3]/ factor;;
  onumm5n4_gem_ro_to( coef, &deltax_power, res, res);
  deltax_power = onumm5n4_mul_oo(&deltax_power,&deltax);
  // Order 4
  factor *=4;
  coef    = feval_re[4]/ factor;;
  onumm5n4_gem_ro_to( coef, &deltax_power, res, res);

}

