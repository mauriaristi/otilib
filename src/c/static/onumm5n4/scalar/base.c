

// Not implemented correctly:
void onumm5n4_set_im_o(onumm5n4_t* num, imdir_t idx, ord_t order, onumm5n4_t* res){
    onumm5n4_set_item(num->r,idx,order,res);
}
void onumm5n4_set_deriv_r(coeff_t num, imdir_t idx, ord_t order, onumm5n4_t* res){
    *res=onumm5n4_init();
}
void onumm5n4_set_deriv_o(onumm5n4_t* num, imdir_t idx, ord_t order, onumm5n4_t* res){
    *res=onumm5n4_init();
}
void onumm5n4_extract_im_to( imdir_t idx, ord_t order, onumm5n4_t* num, onumm5n4_t* res){
    *res=onumm5n4_init();
}
onumm5n4_t onumm5n4_extract_im(imdir_t idx, ord_t order, onumm5n4_t* num){
    onumm5n4_t res = onumm5n4_init();
    return res;
}
onumm5n4_t onumm5n4_extract_deriv(imdir_t idx, ord_t order, onumm5n4_t* num){
    onumm5n4_t res = onumm5n4_init();
    return res;
}
void onumm5n4_extract_deriv_to(imdir_t idx, ord_t order, onumm5n4_t* num, onumm5n4_t* res){
	*res = onumm5n4_init();
}
void onumm5n4_get_im_to_o(imdir_t idx, ord_t order, onumm5n4_t* num, onumm5n4_t* res){
    coeff_t rres = onumm5n4_get_item(idx, order, num);
    onumm5n4_set_r(rres,res);
}
onumm5n4_t onumm5n4_get_im_o(imdir_t idx, ord_t order, onumm5n4_t* num){
    coeff_t rres = onumm5n4_get_item(idx, order, num);
    onumm5n4_t res;
    onumm5n4_set_r(rres,&res);
    return res;
}
void onumm5n4_get_im_to_r(imdir_t idx, ord_t order, onumm5n4_t* num, coeff_t* res){
    *res = onumm5n4_get_item(idx, order, num);
}

inline ord_t onumm5n4_get_order(onumm5n4_t* lhs){

	return 4;

}

onumm5n4_t onumm5n4_get_deriv_o( imdir_t idx, ord_t order, onumm5n4_t* num){

    onumm5n4_t res = onumm5n4_init();

    onumm5n4_get_deriv_to( idx, order, num, &res);
    
    return res;

}

void onumm5n4_get_deriv_to( imdir_t idx, ord_t order, onumm5n4_t* num, onumm5n4_t* res){

    coeff_t deriv = onumm5n4_get_deriv(idx,order,num);

    onumm5n4_set_r( deriv, res);

}

void onumm5n4_set_im_r(coeff_t num, imdir_t idx, ord_t order, onumm5n4_t* res){

    onumm5n4_set_item(num, idx,order,res);

}

onumm5n4_t onumm5n4_init(void){

  onumm5n4_t res;

  // Init function
  // Real;
  res.r = 0.0;
  // Order 1;
  res.e1 = 0.0;
  res.e2 = 0.0;
  res.e3 = 0.0;
  res.e4 = 0.0;
  res.e5 = 0.0;
  // Order 2;
  res.e11 = 0.0;
  res.e12 = 0.0;
  res.e22 = 0.0;
  res.e13 = 0.0;
  res.e23 = 0.0;
  res.e33 = 0.0;
  res.e14 = 0.0;
  res.e24 = 0.0;
  res.e34 = 0.0;
  res.e44 = 0.0;
  res.e15 = 0.0;
  res.e25 = 0.0;
  res.e35 = 0.0;
  res.e45 = 0.0;
  res.e55 = 0.0;
  // Order 3;
  res.e111 = 0.0;
  res.e112 = 0.0;
  res.e122 = 0.0;
  res.e222 = 0.0;
  res.e113 = 0.0;
  res.e123 = 0.0;
  res.e223 = 0.0;
  res.e133 = 0.0;
  res.e233 = 0.0;
  res.e333 = 0.0;
  res.e114 = 0.0;
  res.e124 = 0.0;
  res.e224 = 0.0;
  res.e134 = 0.0;
  res.e234 = 0.0;
  res.e334 = 0.0;
  res.e144 = 0.0;
  res.e244 = 0.0;
  res.e344 = 0.0;
  res.e444 = 0.0;
  res.e115 = 0.0;
  res.e125 = 0.0;
  res.e225 = 0.0;
  res.e135 = 0.0;
  res.e235 = 0.0;
  res.e335 = 0.0;
  res.e145 = 0.0;
  res.e245 = 0.0;
  res.e345 = 0.0;
  res.e445 = 0.0;
  res.e155 = 0.0;
  res.e255 = 0.0;
  res.e355 = 0.0;
  res.e455 = 0.0;
  res.e555 = 0.0;
  // Order 4;
  res.e1111 = 0.0;
  res.e1112 = 0.0;
  res.e1122 = 0.0;
  res.e1222 = 0.0;
  res.e2222 = 0.0;
  res.e1113 = 0.0;
  res.e1123 = 0.0;
  res.e1223 = 0.0;
  res.e2223 = 0.0;
  res.e1133 = 0.0;
  res.e1233 = 0.0;
  res.e2233 = 0.0;
  res.e1333 = 0.0;
  res.e2333 = 0.0;
  res.e3333 = 0.0;
  res.e1114 = 0.0;
  res.e1124 = 0.0;
  res.e1224 = 0.0;
  res.e2224 = 0.0;
  res.e1134 = 0.0;
  res.e1234 = 0.0;
  res.e2234 = 0.0;
  res.e1334 = 0.0;
  res.e2334 = 0.0;
  res.e3334 = 0.0;
  res.e1144 = 0.0;
  res.e1244 = 0.0;
  res.e2244 = 0.0;
  res.e1344 = 0.0;
  res.e2344 = 0.0;
  res.e3344 = 0.0;
  res.e1444 = 0.0;
  res.e2444 = 0.0;
  res.e3444 = 0.0;
  res.e4444 = 0.0;
  res.e1115 = 0.0;
  res.e1125 = 0.0;
  res.e1225 = 0.0;
  res.e2225 = 0.0;
  res.e1135 = 0.0;
  res.e1235 = 0.0;
  res.e2235 = 0.0;
  res.e1335 = 0.0;
  res.e2335 = 0.0;
  res.e3335 = 0.0;
  res.e1145 = 0.0;
  res.e1245 = 0.0;
  res.e2245 = 0.0;
  res.e1345 = 0.0;
  res.e2345 = 0.0;
  res.e3345 = 0.0;
  res.e1445 = 0.0;
  res.e2445 = 0.0;
  res.e3445 = 0.0;
  res.e4445 = 0.0;
  res.e1155 = 0.0;
  res.e1255 = 0.0;
  res.e2255 = 0.0;
  res.e1355 = 0.0;
  res.e2355 = 0.0;
  res.e3355 = 0.0;
  res.e1455 = 0.0;
  res.e2455 = 0.0;
  res.e3455 = 0.0;
  res.e4455 = 0.0;
  res.e1555 = 0.0;
  res.e2555 = 0.0;
  res.e3555 = 0.0;
  res.e4555 = 0.0;
  res.e5555 = 0.0;

  return res;

}

ndir_t onumm5n4_get_ndir_order(ord_t order, onumm5n4_t* num){

  ndir_t res;

  switch(order){
    case 0:
      res = 1;
      break;
    case 1:
      res = 5;
      break;
    case 2:
      res = 15;
      break;
    case 3:
      res = 35;
      break;
    case 4:
      res = 70;
      break;
  }

  return res;

}

ndir_t onumm5n4_get_ndir_total(onumm5n4_t* num){

  ndir_t res;

  res = 56;

  return res;

}

coeff_t* onumm5n4_get_order_address(ord_t order, onumm5n4_t* num){

  coeff_t* res;

  switch(order){
    case 0:
      res = &num->r;
      break;
    case 1:
      res = &num->e1;
      break;
    case 2:
      res = &num->e11;
      break;
    case 3:
      res = &num->e111;
      break;
    case 4:
      res = &num->e1111;
      break;
  }
  return res;

}

onumm5n4_t onumm5n4_create_r(  coeff_t lhs){

  onumm5n4_t res;

  // Assign like function 'lhs'
  // Real;
  res.r = lhs;
  // Order 1;
  res.e1 = 0.0;
  res.e2 = 0.0;
  res.e3 = 0.0;
  res.e4 = 0.0;
  res.e5 = 0.0;
  // Order 2;
  res.e11 = 0.0;
  res.e12 = 0.0;
  res.e22 = 0.0;
  res.e13 = 0.0;
  res.e23 = 0.0;
  res.e33 = 0.0;
  res.e14 = 0.0;
  res.e24 = 0.0;
  res.e34 = 0.0;
  res.e44 = 0.0;
  res.e15 = 0.0;
  res.e25 = 0.0;
  res.e35 = 0.0;
  res.e45 = 0.0;
  res.e55 = 0.0;
  // Order 3;
  res.e111 = 0.0;
  res.e112 = 0.0;
  res.e122 = 0.0;
  res.e222 = 0.0;
  res.e113 = 0.0;
  res.e123 = 0.0;
  res.e223 = 0.0;
  res.e133 = 0.0;
  res.e233 = 0.0;
  res.e333 = 0.0;
  res.e114 = 0.0;
  res.e124 = 0.0;
  res.e224 = 0.0;
  res.e134 = 0.0;
  res.e234 = 0.0;
  res.e334 = 0.0;
  res.e144 = 0.0;
  res.e244 = 0.0;
  res.e344 = 0.0;
  res.e444 = 0.0;
  res.e115 = 0.0;
  res.e125 = 0.0;
  res.e225 = 0.0;
  res.e135 = 0.0;
  res.e235 = 0.0;
  res.e335 = 0.0;
  res.e145 = 0.0;
  res.e245 = 0.0;
  res.e345 = 0.0;
  res.e445 = 0.0;
  res.e155 = 0.0;
  res.e255 = 0.0;
  res.e355 = 0.0;
  res.e455 = 0.0;
  res.e555 = 0.0;
  // Order 4;
  res.e1111 = 0.0;
  res.e1112 = 0.0;
  res.e1122 = 0.0;
  res.e1222 = 0.0;
  res.e2222 = 0.0;
  res.e1113 = 0.0;
  res.e1123 = 0.0;
  res.e1223 = 0.0;
  res.e2223 = 0.0;
  res.e1133 = 0.0;
  res.e1233 = 0.0;
  res.e2233 = 0.0;
  res.e1333 = 0.0;
  res.e2333 = 0.0;
  res.e3333 = 0.0;
  res.e1114 = 0.0;
  res.e1124 = 0.0;
  res.e1224 = 0.0;
  res.e2224 = 0.0;
  res.e1134 = 0.0;
  res.e1234 = 0.0;
  res.e2234 = 0.0;
  res.e1334 = 0.0;
  res.e2334 = 0.0;
  res.e3334 = 0.0;
  res.e1144 = 0.0;
  res.e1244 = 0.0;
  res.e2244 = 0.0;
  res.e1344 = 0.0;
  res.e2344 = 0.0;
  res.e3344 = 0.0;
  res.e1444 = 0.0;
  res.e2444 = 0.0;
  res.e3444 = 0.0;
  res.e4444 = 0.0;
  res.e1115 = 0.0;
  res.e1125 = 0.0;
  res.e1225 = 0.0;
  res.e2225 = 0.0;
  res.e1135 = 0.0;
  res.e1235 = 0.0;
  res.e2235 = 0.0;
  res.e1335 = 0.0;
  res.e2335 = 0.0;
  res.e3335 = 0.0;
  res.e1145 = 0.0;
  res.e1245 = 0.0;
  res.e2245 = 0.0;
  res.e1345 = 0.0;
  res.e2345 = 0.0;
  res.e3345 = 0.0;
  res.e1445 = 0.0;
  res.e2445 = 0.0;
  res.e3445 = 0.0;
  res.e4445 = 0.0;
  res.e1155 = 0.0;
  res.e1255 = 0.0;
  res.e2255 = 0.0;
  res.e1355 = 0.0;
  res.e2355 = 0.0;
  res.e3355 = 0.0;
  res.e1455 = 0.0;
  res.e2455 = 0.0;
  res.e3455 = 0.0;
  res.e4455 = 0.0;
  res.e1555 = 0.0;
  res.e2555 = 0.0;
  res.e3555 = 0.0;
  res.e4555 = 0.0;
  res.e5555 = 0.0;

  return res;

}

void onumm5n4_set_r(  coeff_t lhs, onumm5n4_t* res){

  // Assign like function 'lhs'
  // Real;
  res->r = lhs;
  // Order 1;
  res->e1 = 0.0;
  res->e2 = 0.0;
  res->e3 = 0.0;
  res->e4 = 0.0;
  res->e5 = 0.0;
  // Order 2;
  res->e11 = 0.0;
  res->e12 = 0.0;
  res->e22 = 0.0;
  res->e13 = 0.0;
  res->e23 = 0.0;
  res->e33 = 0.0;
  res->e14 = 0.0;
  res->e24 = 0.0;
  res->e34 = 0.0;
  res->e44 = 0.0;
  res->e15 = 0.0;
  res->e25 = 0.0;
  res->e35 = 0.0;
  res->e45 = 0.0;
  res->e55 = 0.0;
  // Order 3;
  res->e111 = 0.0;
  res->e112 = 0.0;
  res->e122 = 0.0;
  res->e222 = 0.0;
  res->e113 = 0.0;
  res->e123 = 0.0;
  res->e223 = 0.0;
  res->e133 = 0.0;
  res->e233 = 0.0;
  res->e333 = 0.0;
  res->e114 = 0.0;
  res->e124 = 0.0;
  res->e224 = 0.0;
  res->e134 = 0.0;
  res->e234 = 0.0;
  res->e334 = 0.0;
  res->e144 = 0.0;
  res->e244 = 0.0;
  res->e344 = 0.0;
  res->e444 = 0.0;
  res->e115 = 0.0;
  res->e125 = 0.0;
  res->e225 = 0.0;
  res->e135 = 0.0;
  res->e235 = 0.0;
  res->e335 = 0.0;
  res->e145 = 0.0;
  res->e245 = 0.0;
  res->e345 = 0.0;
  res->e445 = 0.0;
  res->e155 = 0.0;
  res->e255 = 0.0;
  res->e355 = 0.0;
  res->e455 = 0.0;
  res->e555 = 0.0;
  // Order 4;
  res->e1111 = 0.0;
  res->e1112 = 0.0;
  res->e1122 = 0.0;
  res->e1222 = 0.0;
  res->e2222 = 0.0;
  res->e1113 = 0.0;
  res->e1123 = 0.0;
  res->e1223 = 0.0;
  res->e2223 = 0.0;
  res->e1133 = 0.0;
  res->e1233 = 0.0;
  res->e2233 = 0.0;
  res->e1333 = 0.0;
  res->e2333 = 0.0;
  res->e3333 = 0.0;
  res->e1114 = 0.0;
  res->e1124 = 0.0;
  res->e1224 = 0.0;
  res->e2224 = 0.0;
  res->e1134 = 0.0;
  res->e1234 = 0.0;
  res->e2234 = 0.0;
  res->e1334 = 0.0;
  res->e2334 = 0.0;
  res->e3334 = 0.0;
  res->e1144 = 0.0;
  res->e1244 = 0.0;
  res->e2244 = 0.0;
  res->e1344 = 0.0;
  res->e2344 = 0.0;
  res->e3344 = 0.0;
  res->e1444 = 0.0;
  res->e2444 = 0.0;
  res->e3444 = 0.0;
  res->e4444 = 0.0;
  res->e1115 = 0.0;
  res->e1125 = 0.0;
  res->e1225 = 0.0;
  res->e2225 = 0.0;
  res->e1135 = 0.0;
  res->e1235 = 0.0;
  res->e2235 = 0.0;
  res->e1335 = 0.0;
  res->e2335 = 0.0;
  res->e3335 = 0.0;
  res->e1145 = 0.0;
  res->e1245 = 0.0;
  res->e2245 = 0.0;
  res->e1345 = 0.0;
  res->e2345 = 0.0;
  res->e3345 = 0.0;
  res->e1445 = 0.0;
  res->e2445 = 0.0;
  res->e3445 = 0.0;
  res->e4445 = 0.0;
  res->e1155 = 0.0;
  res->e1255 = 0.0;
  res->e2255 = 0.0;
  res->e1355 = 0.0;
  res->e2355 = 0.0;
  res->e3355 = 0.0;
  res->e1455 = 0.0;
  res->e2455 = 0.0;
  res->e3455 = 0.0;
  res->e4455 = 0.0;
  res->e1555 = 0.0;
  res->e2555 = 0.0;
  res->e3555 = 0.0;
  res->e4555 = 0.0;
  res->e5555 = 0.0;

}

void onumm5n4_set_o(  onumm5n4_t* lhs, onumm5n4_t* res){

  // Assign like function 'lhs'
  // Real;
  res->r = lhs->r;
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

onumm5n4_t onumm5n4_get_order_im(ord_t order, onumm5n4_t* lhs){

  onumm5n4_t res;

  res = onumm5n4_init();
  switch( order ){
    case 0:
      // Assign like function 'lhs'
      // Real;
      res.r = lhs->r;
      break;
    case 1:
      // Order 1;
      res.e1 = lhs->e1;
      res.e2 = lhs->e2;
      res.e3 = lhs->e3;
      res.e4 = lhs->e4;
      res.e5 = lhs->e5;
      break;
    case 2:
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
      break;
    case 3:
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
      break;
    case 4:
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
      break;
  }

  return res;

}

void onumm5n4_get_order_im_to(ord_t order, onumm5n4_t* lhs, onumm5n4_t* res){


  *res = onumm5n4_init();
  switch( order ){
    case 0:
      // Assign like function 'lhs'
      // Real;
      res->r = lhs->r;
      break;
    case 1:
      // Order 1;
      res->e1 = lhs->e1;
      res->e2 = lhs->e2;
      res->e3 = lhs->e3;
      res->e4 = lhs->e4;
      res->e5 = lhs->e5;
      break;
    case 2:
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
      break;
    case 3:
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
      break;
    case 4:
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
      break;
  }

}

coeff_t onumm5n4_get_item(imdir_t idx, ord_t order, onumm5n4_t* lhs){

  coeff_t res;

  // Get Imaginary coefficient.
  res = 0.0;
  // Real;
  switch (order){
    case 0:
      res = lhs->r;
      break;
    case 1:
      switch (idx){
        case 0:
          res = lhs->e1;
          break;
        case 1:
          res = lhs->e2;
          break;
        case 2:
          res = lhs->e3;
          break;
        case 3:
          res = lhs->e4;
          break;
        case 4:
          res = lhs->e5;
          break;
      }
      break;
    case 2:
      switch (idx){
        case 0:
          res = lhs->e11;
          break;
        case 1:
          res = lhs->e12;
          break;
        case 2:
          res = lhs->e22;
          break;
        case 3:
          res = lhs->e13;
          break;
        case 4:
          res = lhs->e23;
          break;
        case 5:
          res = lhs->e33;
          break;
        case 6:
          res = lhs->e14;
          break;
        case 7:
          res = lhs->e24;
          break;
        case 8:
          res = lhs->e34;
          break;
        case 9:
          res = lhs->e44;
          break;
        case 10:
          res = lhs->e15;
          break;
        case 11:
          res = lhs->e25;
          break;
        case 12:
          res = lhs->e35;
          break;
        case 13:
          res = lhs->e45;
          break;
        case 14:
          res = lhs->e55;
          break;
      }
      break;
    case 3:
      switch (idx){
        case 0:
          res = lhs->e111;
          break;
        case 1:
          res = lhs->e112;
          break;
        case 2:
          res = lhs->e122;
          break;
        case 3:
          res = lhs->e222;
          break;
        case 4:
          res = lhs->e113;
          break;
        case 5:
          res = lhs->e123;
          break;
        case 6:
          res = lhs->e223;
          break;
        case 7:
          res = lhs->e133;
          break;
        case 8:
          res = lhs->e233;
          break;
        case 9:
          res = lhs->e333;
          break;
        case 10:
          res = lhs->e114;
          break;
        case 11:
          res = lhs->e124;
          break;
        case 12:
          res = lhs->e224;
          break;
        case 13:
          res = lhs->e134;
          break;
        case 14:
          res = lhs->e234;
          break;
        case 15:
          res = lhs->e334;
          break;
        case 16:
          res = lhs->e144;
          break;
        case 17:
          res = lhs->e244;
          break;
        case 18:
          res = lhs->e344;
          break;
        case 19:
          res = lhs->e444;
          break;
        case 20:
          res = lhs->e115;
          break;
        case 21:
          res = lhs->e125;
          break;
        case 22:
          res = lhs->e225;
          break;
        case 23:
          res = lhs->e135;
          break;
        case 24:
          res = lhs->e235;
          break;
        case 25:
          res = lhs->e335;
          break;
        case 26:
          res = lhs->e145;
          break;
        case 27:
          res = lhs->e245;
          break;
        case 28:
          res = lhs->e345;
          break;
        case 29:
          res = lhs->e445;
          break;
        case 30:
          res = lhs->e155;
          break;
        case 31:
          res = lhs->e255;
          break;
        case 32:
          res = lhs->e355;
          break;
        case 33:
          res = lhs->e455;
          break;
        case 34:
          res = lhs->e555;
          break;
      }
      break;
    case 4:
      switch (idx){
        case 0:
          res = lhs->e1111;
          break;
        case 1:
          res = lhs->e1112;
          break;
        case 2:
          res = lhs->e1122;
          break;
        case 3:
          res = lhs->e1222;
          break;
        case 4:
          res = lhs->e2222;
          break;
        case 5:
          res = lhs->e1113;
          break;
        case 6:
          res = lhs->e1123;
          break;
        case 7:
          res = lhs->e1223;
          break;
        case 8:
          res = lhs->e2223;
          break;
        case 9:
          res = lhs->e1133;
          break;
        case 10:
          res = lhs->e1233;
          break;
        case 11:
          res = lhs->e2233;
          break;
        case 12:
          res = lhs->e1333;
          break;
        case 13:
          res = lhs->e2333;
          break;
        case 14:
          res = lhs->e3333;
          break;
        case 15:
          res = lhs->e1114;
          break;
        case 16:
          res = lhs->e1124;
          break;
        case 17:
          res = lhs->e1224;
          break;
        case 18:
          res = lhs->e2224;
          break;
        case 19:
          res = lhs->e1134;
          break;
        case 20:
          res = lhs->e1234;
          break;
        case 21:
          res = lhs->e2234;
          break;
        case 22:
          res = lhs->e1334;
          break;
        case 23:
          res = lhs->e2334;
          break;
        case 24:
          res = lhs->e3334;
          break;
        case 25:
          res = lhs->e1144;
          break;
        case 26:
          res = lhs->e1244;
          break;
        case 27:
          res = lhs->e2244;
          break;
        case 28:
          res = lhs->e1344;
          break;
        case 29:
          res = lhs->e2344;
          break;
        case 30:
          res = lhs->e3344;
          break;
        case 31:
          res = lhs->e1444;
          break;
        case 32:
          res = lhs->e2444;
          break;
        case 33:
          res = lhs->e3444;
          break;
        case 34:
          res = lhs->e4444;
          break;
        case 35:
          res = lhs->e1115;
          break;
        case 36:
          res = lhs->e1125;
          break;
        case 37:
          res = lhs->e1225;
          break;
        case 38:
          res = lhs->e2225;
          break;
        case 39:
          res = lhs->e1135;
          break;
        case 40:
          res = lhs->e1235;
          break;
        case 41:
          res = lhs->e2235;
          break;
        case 42:
          res = lhs->e1335;
          break;
        case 43:
          res = lhs->e2335;
          break;
        case 44:
          res = lhs->e3335;
          break;
        case 45:
          res = lhs->e1145;
          break;
        case 46:
          res = lhs->e1245;
          break;
        case 47:
          res = lhs->e2245;
          break;
        case 48:
          res = lhs->e1345;
          break;
        case 49:
          res = lhs->e2345;
          break;
        case 50:
          res = lhs->e3345;
          break;
        case 51:
          res = lhs->e1445;
          break;
        case 52:
          res = lhs->e2445;
          break;
        case 53:
          res = lhs->e3445;
          break;
        case 54:
          res = lhs->e4445;
          break;
        case 55:
          res = lhs->e1155;
          break;
        case 56:
          res = lhs->e1255;
          break;
        case 57:
          res = lhs->e2255;
          break;
        case 58:
          res = lhs->e1355;
          break;
        case 59:
          res = lhs->e2355;
          break;
        case 60:
          res = lhs->e3355;
          break;
        case 61:
          res = lhs->e1455;
          break;
        case 62:
          res = lhs->e2455;
          break;
        case 63:
          res = lhs->e3455;
          break;
        case 64:
          res = lhs->e4455;
          break;
        case 65:
          res = lhs->e1555;
          break;
        case 66:
          res = lhs->e2555;
          break;
        case 67:
          res = lhs->e3555;
          break;
        case 68:
          res = lhs->e4555;
          break;
        case 69:
          res = lhs->e5555;
          break;
      }
      break;
  }
  return res;

}

coeff_t onumm5n4_get_deriv(imdir_t idx, ord_t order, onumm5n4_t* lhs){

  coeff_t res;

  coeff_t factor;
  // Get Imaginary coefficient.
  res = 0.0;
  // Real;
  switch (order){
    case 0:
      res = lhs->r;
      break;
    case 1:
      switch (idx){
        case 0:
          factor = 1.0000000000000000e+00;
          res = lhs->e1*factor;
          break;
        case 1:
          factor = 1.0000000000000000e+00;
          res = lhs->e2*factor;
          break;
        case 2:
          factor = 1.0000000000000000e+00;
          res = lhs->e3*factor;
          break;
        case 3:
          factor = 1.0000000000000000e+00;
          res = lhs->e4*factor;
          break;
        case 4:
          factor = 1.0000000000000000e+00;
          res = lhs->e5*factor;
          break;
      }
      break;
    case 2:
      switch (idx){
        case 0:
          factor = 2.0000000000000000e+00;
          res = lhs->e11*factor;
          break;
        case 1:
          factor = 1.0000000000000000e+00;
          res = lhs->e12*factor;
          break;
        case 2:
          factor = 2.0000000000000000e+00;
          res = lhs->e22*factor;
          break;
        case 3:
          factor = 1.0000000000000000e+00;
          res = lhs->e13*factor;
          break;
        case 4:
          factor = 1.0000000000000000e+00;
          res = lhs->e23*factor;
          break;
        case 5:
          factor = 2.0000000000000000e+00;
          res = lhs->e33*factor;
          break;
        case 6:
          factor = 1.0000000000000000e+00;
          res = lhs->e14*factor;
          break;
        case 7:
          factor = 1.0000000000000000e+00;
          res = lhs->e24*factor;
          break;
        case 8:
          factor = 1.0000000000000000e+00;
          res = lhs->e34*factor;
          break;
        case 9:
          factor = 2.0000000000000000e+00;
          res = lhs->e44*factor;
          break;
        case 10:
          factor = 1.0000000000000000e+00;
          res = lhs->e15*factor;
          break;
        case 11:
          factor = 1.0000000000000000e+00;
          res = lhs->e25*factor;
          break;
        case 12:
          factor = 1.0000000000000000e+00;
          res = lhs->e35*factor;
          break;
        case 13:
          factor = 1.0000000000000000e+00;
          res = lhs->e45*factor;
          break;
        case 14:
          factor = 2.0000000000000000e+00;
          res = lhs->e55*factor;
          break;
      }
      break;
    case 3:
      switch (idx){
        case 0:
          factor = 6.0000000000000000e+00;
          res = lhs->e111*factor;
          break;
        case 1:
          factor = 2.0000000000000000e+00;
          res = lhs->e112*factor;
          break;
        case 2:
          factor = 2.0000000000000000e+00;
          res = lhs->e122*factor;
          break;
        case 3:
          factor = 6.0000000000000000e+00;
          res = lhs->e222*factor;
          break;
        case 4:
          factor = 2.0000000000000000e+00;
          res = lhs->e113*factor;
          break;
        case 5:
          factor = 1.0000000000000000e+00;
          res = lhs->e123*factor;
          break;
        case 6:
          factor = 2.0000000000000000e+00;
          res = lhs->e223*factor;
          break;
        case 7:
          factor = 2.0000000000000000e+00;
          res = lhs->e133*factor;
          break;
        case 8:
          factor = 2.0000000000000000e+00;
          res = lhs->e233*factor;
          break;
        case 9:
          factor = 6.0000000000000000e+00;
          res = lhs->e333*factor;
          break;
        case 10:
          factor = 2.0000000000000000e+00;
          res = lhs->e114*factor;
          break;
        case 11:
          factor = 1.0000000000000000e+00;
          res = lhs->e124*factor;
          break;
        case 12:
          factor = 2.0000000000000000e+00;
          res = lhs->e224*factor;
          break;
        case 13:
          factor = 1.0000000000000000e+00;
          res = lhs->e134*factor;
          break;
        case 14:
          factor = 1.0000000000000000e+00;
          res = lhs->e234*factor;
          break;
        case 15:
          factor = 2.0000000000000000e+00;
          res = lhs->e334*factor;
          break;
        case 16:
          factor = 2.0000000000000000e+00;
          res = lhs->e144*factor;
          break;
        case 17:
          factor = 2.0000000000000000e+00;
          res = lhs->e244*factor;
          break;
        case 18:
          factor = 2.0000000000000000e+00;
          res = lhs->e344*factor;
          break;
        case 19:
          factor = 6.0000000000000000e+00;
          res = lhs->e444*factor;
          break;
        case 20:
          factor = 2.0000000000000000e+00;
          res = lhs->e115*factor;
          break;
        case 21:
          factor = 1.0000000000000000e+00;
          res = lhs->e125*factor;
          break;
        case 22:
          factor = 2.0000000000000000e+00;
          res = lhs->e225*factor;
          break;
        case 23:
          factor = 1.0000000000000000e+00;
          res = lhs->e135*factor;
          break;
        case 24:
          factor = 1.0000000000000000e+00;
          res = lhs->e235*factor;
          break;
        case 25:
          factor = 2.0000000000000000e+00;
          res = lhs->e335*factor;
          break;
        case 26:
          factor = 1.0000000000000000e+00;
          res = lhs->e145*factor;
          break;
        case 27:
          factor = 1.0000000000000000e+00;
          res = lhs->e245*factor;
          break;
        case 28:
          factor = 1.0000000000000000e+00;
          res = lhs->e345*factor;
          break;
        case 29:
          factor = 2.0000000000000000e+00;
          res = lhs->e445*factor;
          break;
        case 30:
          factor = 2.0000000000000000e+00;
          res = lhs->e155*factor;
          break;
        case 31:
          factor = 2.0000000000000000e+00;
          res = lhs->e255*factor;
          break;
        case 32:
          factor = 2.0000000000000000e+00;
          res = lhs->e355*factor;
          break;
        case 33:
          factor = 2.0000000000000000e+00;
          res = lhs->e455*factor;
          break;
        case 34:
          factor = 6.0000000000000000e+00;
          res = lhs->e555*factor;
          break;
      }
      break;
    case 4:
      switch (idx){
        case 0:
          factor = 2.4000000000000000e+01;
          res = lhs->e1111*factor;
          break;
        case 1:
          factor = 6.0000000000000000e+00;
          res = lhs->e1112*factor;
          break;
        case 2:
          factor = 4.0000000000000000e+00;
          res = lhs->e1122*factor;
          break;
        case 3:
          factor = 6.0000000000000000e+00;
          res = lhs->e1222*factor;
          break;
        case 4:
          factor = 2.4000000000000000e+01;
          res = lhs->e2222*factor;
          break;
        case 5:
          factor = 6.0000000000000000e+00;
          res = lhs->e1113*factor;
          break;
        case 6:
          factor = 2.0000000000000000e+00;
          res = lhs->e1123*factor;
          break;
        case 7:
          factor = 2.0000000000000000e+00;
          res = lhs->e1223*factor;
          break;
        case 8:
          factor = 6.0000000000000000e+00;
          res = lhs->e2223*factor;
          break;
        case 9:
          factor = 4.0000000000000000e+00;
          res = lhs->e1133*factor;
          break;
        case 10:
          factor = 2.0000000000000000e+00;
          res = lhs->e1233*factor;
          break;
        case 11:
          factor = 4.0000000000000000e+00;
          res = lhs->e2233*factor;
          break;
        case 12:
          factor = 6.0000000000000000e+00;
          res = lhs->e1333*factor;
          break;
        case 13:
          factor = 6.0000000000000000e+00;
          res = lhs->e2333*factor;
          break;
        case 14:
          factor = 2.4000000000000000e+01;
          res = lhs->e3333*factor;
          break;
        case 15:
          factor = 6.0000000000000000e+00;
          res = lhs->e1114*factor;
          break;
        case 16:
          factor = 2.0000000000000000e+00;
          res = lhs->e1124*factor;
          break;
        case 17:
          factor = 2.0000000000000000e+00;
          res = lhs->e1224*factor;
          break;
        case 18:
          factor = 6.0000000000000000e+00;
          res = lhs->e2224*factor;
          break;
        case 19:
          factor = 2.0000000000000000e+00;
          res = lhs->e1134*factor;
          break;
        case 20:
          factor = 1.0000000000000000e+00;
          res = lhs->e1234*factor;
          break;
        case 21:
          factor = 2.0000000000000000e+00;
          res = lhs->e2234*factor;
          break;
        case 22:
          factor = 2.0000000000000000e+00;
          res = lhs->e1334*factor;
          break;
        case 23:
          factor = 2.0000000000000000e+00;
          res = lhs->e2334*factor;
          break;
        case 24:
          factor = 6.0000000000000000e+00;
          res = lhs->e3334*factor;
          break;
        case 25:
          factor = 4.0000000000000000e+00;
          res = lhs->e1144*factor;
          break;
        case 26:
          factor = 2.0000000000000000e+00;
          res = lhs->e1244*factor;
          break;
        case 27:
          factor = 4.0000000000000000e+00;
          res = lhs->e2244*factor;
          break;
        case 28:
          factor = 2.0000000000000000e+00;
          res = lhs->e1344*factor;
          break;
        case 29:
          factor = 2.0000000000000000e+00;
          res = lhs->e2344*factor;
          break;
        case 30:
          factor = 4.0000000000000000e+00;
          res = lhs->e3344*factor;
          break;
        case 31:
          factor = 6.0000000000000000e+00;
          res = lhs->e1444*factor;
          break;
        case 32:
          factor = 6.0000000000000000e+00;
          res = lhs->e2444*factor;
          break;
        case 33:
          factor = 6.0000000000000000e+00;
          res = lhs->e3444*factor;
          break;
        case 34:
          factor = 2.4000000000000000e+01;
          res = lhs->e4444*factor;
          break;
        case 35:
          factor = 6.0000000000000000e+00;
          res = lhs->e1115*factor;
          break;
        case 36:
          factor = 2.0000000000000000e+00;
          res = lhs->e1125*factor;
          break;
        case 37:
          factor = 2.0000000000000000e+00;
          res = lhs->e1225*factor;
          break;
        case 38:
          factor = 6.0000000000000000e+00;
          res = lhs->e2225*factor;
          break;
        case 39:
          factor = 2.0000000000000000e+00;
          res = lhs->e1135*factor;
          break;
        case 40:
          factor = 1.0000000000000000e+00;
          res = lhs->e1235*factor;
          break;
        case 41:
          factor = 2.0000000000000000e+00;
          res = lhs->e2235*factor;
          break;
        case 42:
          factor = 2.0000000000000000e+00;
          res = lhs->e1335*factor;
          break;
        case 43:
          factor = 2.0000000000000000e+00;
          res = lhs->e2335*factor;
          break;
        case 44:
          factor = 6.0000000000000000e+00;
          res = lhs->e3335*factor;
          break;
        case 45:
          factor = 2.0000000000000000e+00;
          res = lhs->e1145*factor;
          break;
        case 46:
          factor = 1.0000000000000000e+00;
          res = lhs->e1245*factor;
          break;
        case 47:
          factor = 2.0000000000000000e+00;
          res = lhs->e2245*factor;
          break;
        case 48:
          factor = 1.0000000000000000e+00;
          res = lhs->e1345*factor;
          break;
        case 49:
          factor = 1.0000000000000000e+00;
          res = lhs->e2345*factor;
          break;
        case 50:
          factor = 2.0000000000000000e+00;
          res = lhs->e3345*factor;
          break;
        case 51:
          factor = 2.0000000000000000e+00;
          res = lhs->e1445*factor;
          break;
        case 52:
          factor = 2.0000000000000000e+00;
          res = lhs->e2445*factor;
          break;
        case 53:
          factor = 2.0000000000000000e+00;
          res = lhs->e3445*factor;
          break;
        case 54:
          factor = 6.0000000000000000e+00;
          res = lhs->e4445*factor;
          break;
        case 55:
          factor = 4.0000000000000000e+00;
          res = lhs->e1155*factor;
          break;
        case 56:
          factor = 2.0000000000000000e+00;
          res = lhs->e1255*factor;
          break;
        case 57:
          factor = 4.0000000000000000e+00;
          res = lhs->e2255*factor;
          break;
        case 58:
          factor = 2.0000000000000000e+00;
          res = lhs->e1355*factor;
          break;
        case 59:
          factor = 2.0000000000000000e+00;
          res = lhs->e2355*factor;
          break;
        case 60:
          factor = 4.0000000000000000e+00;
          res = lhs->e3355*factor;
          break;
        case 61:
          factor = 2.0000000000000000e+00;
          res = lhs->e1455*factor;
          break;
        case 62:
          factor = 2.0000000000000000e+00;
          res = lhs->e2455*factor;
          break;
        case 63:
          factor = 2.0000000000000000e+00;
          res = lhs->e3455*factor;
          break;
        case 64:
          factor = 4.0000000000000000e+00;
          res = lhs->e4455*factor;
          break;
        case 65:
          factor = 6.0000000000000000e+00;
          res = lhs->e1555*factor;
          break;
        case 66:
          factor = 6.0000000000000000e+00;
          res = lhs->e2555*factor;
          break;
        case 67:
          factor = 6.0000000000000000e+00;
          res = lhs->e3555*factor;
          break;
        case 68:
          factor = 6.0000000000000000e+00;
          res = lhs->e4555*factor;
          break;
        case 69:
          factor = 2.4000000000000000e+01;
          res = lhs->e5555*factor;
          break;
      }
      break;
  }
  return res;

}

void onumm5n4_set_item(coeff_t val, imdir_t idx, ord_t order, onumm5n4_t* x){

  // Set Imaginary coefficient.
  // Real;
  switch (order){
    case 0:
      x->r = val;
      break;
    case 1:
      switch (idx){
        case 0:
          x->e1 = val;
          break;
        case 1:
          x->e2 = val;
          break;
        case 2:
          x->e3 = val;
          break;
        case 3:
          x->e4 = val;
          break;
        case 4:
          x->e5 = val;
          break;
      }
      break;
    case 2:
      switch (idx){
        case 0:
          x->e11 = val;
          break;
        case 1:
          x->e12 = val;
          break;
        case 2:
          x->e22 = val;
          break;
        case 3:
          x->e13 = val;
          break;
        case 4:
          x->e23 = val;
          break;
        case 5:
          x->e33 = val;
          break;
        case 6:
          x->e14 = val;
          break;
        case 7:
          x->e24 = val;
          break;
        case 8:
          x->e34 = val;
          break;
        case 9:
          x->e44 = val;
          break;
        case 10:
          x->e15 = val;
          break;
        case 11:
          x->e25 = val;
          break;
        case 12:
          x->e35 = val;
          break;
        case 13:
          x->e45 = val;
          break;
        case 14:
          x->e55 = val;
          break;
      }
      break;
    case 3:
      switch (idx){
        case 0:
          x->e111 = val;
          break;
        case 1:
          x->e112 = val;
          break;
        case 2:
          x->e122 = val;
          break;
        case 3:
          x->e222 = val;
          break;
        case 4:
          x->e113 = val;
          break;
        case 5:
          x->e123 = val;
          break;
        case 6:
          x->e223 = val;
          break;
        case 7:
          x->e133 = val;
          break;
        case 8:
          x->e233 = val;
          break;
        case 9:
          x->e333 = val;
          break;
        case 10:
          x->e114 = val;
          break;
        case 11:
          x->e124 = val;
          break;
        case 12:
          x->e224 = val;
          break;
        case 13:
          x->e134 = val;
          break;
        case 14:
          x->e234 = val;
          break;
        case 15:
          x->e334 = val;
          break;
        case 16:
          x->e144 = val;
          break;
        case 17:
          x->e244 = val;
          break;
        case 18:
          x->e344 = val;
          break;
        case 19:
          x->e444 = val;
          break;
        case 20:
          x->e115 = val;
          break;
        case 21:
          x->e125 = val;
          break;
        case 22:
          x->e225 = val;
          break;
        case 23:
          x->e135 = val;
          break;
        case 24:
          x->e235 = val;
          break;
        case 25:
          x->e335 = val;
          break;
        case 26:
          x->e145 = val;
          break;
        case 27:
          x->e245 = val;
          break;
        case 28:
          x->e345 = val;
          break;
        case 29:
          x->e445 = val;
          break;
        case 30:
          x->e155 = val;
          break;
        case 31:
          x->e255 = val;
          break;
        case 32:
          x->e355 = val;
          break;
        case 33:
          x->e455 = val;
          break;
        case 34:
          x->e555 = val;
          break;
      }
      break;
    case 4:
      switch (idx){
        case 0:
          x->e1111 = val;
          break;
        case 1:
          x->e1112 = val;
          break;
        case 2:
          x->e1122 = val;
          break;
        case 3:
          x->e1222 = val;
          break;
        case 4:
          x->e2222 = val;
          break;
        case 5:
          x->e1113 = val;
          break;
        case 6:
          x->e1123 = val;
          break;
        case 7:
          x->e1223 = val;
          break;
        case 8:
          x->e2223 = val;
          break;
        case 9:
          x->e1133 = val;
          break;
        case 10:
          x->e1233 = val;
          break;
        case 11:
          x->e2233 = val;
          break;
        case 12:
          x->e1333 = val;
          break;
        case 13:
          x->e2333 = val;
          break;
        case 14:
          x->e3333 = val;
          break;
        case 15:
          x->e1114 = val;
          break;
        case 16:
          x->e1124 = val;
          break;
        case 17:
          x->e1224 = val;
          break;
        case 18:
          x->e2224 = val;
          break;
        case 19:
          x->e1134 = val;
          break;
        case 20:
          x->e1234 = val;
          break;
        case 21:
          x->e2234 = val;
          break;
        case 22:
          x->e1334 = val;
          break;
        case 23:
          x->e2334 = val;
          break;
        case 24:
          x->e3334 = val;
          break;
        case 25:
          x->e1144 = val;
          break;
        case 26:
          x->e1244 = val;
          break;
        case 27:
          x->e2244 = val;
          break;
        case 28:
          x->e1344 = val;
          break;
        case 29:
          x->e2344 = val;
          break;
        case 30:
          x->e3344 = val;
          break;
        case 31:
          x->e1444 = val;
          break;
        case 32:
          x->e2444 = val;
          break;
        case 33:
          x->e3444 = val;
          break;
        case 34:
          x->e4444 = val;
          break;
        case 35:
          x->e1115 = val;
          break;
        case 36:
          x->e1125 = val;
          break;
        case 37:
          x->e1225 = val;
          break;
        case 38:
          x->e2225 = val;
          break;
        case 39:
          x->e1135 = val;
          break;
        case 40:
          x->e1235 = val;
          break;
        case 41:
          x->e2235 = val;
          break;
        case 42:
          x->e1335 = val;
          break;
        case 43:
          x->e2335 = val;
          break;
        case 44:
          x->e3335 = val;
          break;
        case 45:
          x->e1145 = val;
          break;
        case 46:
          x->e1245 = val;
          break;
        case 47:
          x->e2245 = val;
          break;
        case 48:
          x->e1345 = val;
          break;
        case 49:
          x->e2345 = val;
          break;
        case 50:
          x->e3345 = val;
          break;
        case 51:
          x->e1445 = val;
          break;
        case 52:
          x->e2445 = val;
          break;
        case 53:
          x->e3445 = val;
          break;
        case 54:
          x->e4445 = val;
          break;
        case 55:
          x->e1155 = val;
          break;
        case 56:
          x->e1255 = val;
          break;
        case 57:
          x->e2255 = val;
          break;
        case 58:
          x->e1355 = val;
          break;
        case 59:
          x->e2355 = val;
          break;
        case 60:
          x->e3355 = val;
          break;
        case 61:
          x->e1455 = val;
          break;
        case 62:
          x->e2455 = val;
          break;
        case 63:
          x->e3455 = val;
          break;
        case 64:
          x->e4455 = val;
          break;
        case 65:
          x->e1555 = val;
          break;
        case 66:
          x->e2555 = val;
          break;
        case 67:
          x->e3555 = val;
          break;
        case 68:
          x->e4555 = val;
          break;
        case 69:
          x->e5555 = val;
          break;
      }
      break;
  }
}

onumm5n4_t onumm5n4_copy(  onumm5n4_t* lhs){

  onumm5n4_t res;

  // Assign like function 'lhs'
  // Real;
  res.r = lhs->r;
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

void onumm5n4_copy_to(  onumm5n4_t* lhs, onumm5n4_t* res){

  // Assign like function 'lhs'
  // Real;
  res->r = lhs->r;
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

onumm5n4_t onumm5n4_taylor_integrate(coeff_t* deltas,onumm5n4_t* lhs){

  onumm5n4_t res;

  res = onumm5n4_init();
  coeff_t factor;
  // Taylor integration
  // Real;
  res.r = lhs->r;
  // Order 1;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],0);
  res.r += factor*lhs->e1;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],0);
  res.r += factor*lhs->e2;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],0)*pow(deltas[4],0);
  res.r += factor*lhs->e3;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],1)*pow(deltas[4],0);
  res.r += factor*lhs->e4;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],1);
  res.r += factor*lhs->e5;
  // Order 2;
  factor = pow(deltas[0],2)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],0);
  res.r += factor*lhs->e11;
  factor = pow(deltas[0],1)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],0);
  res.r += factor*lhs->e12;
  factor = pow(deltas[0],0)*pow(deltas[1],2)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],0);
  res.r += factor*lhs->e22;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],0)*pow(deltas[4],0);
  res.r += factor*lhs->e13;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],1)*pow(deltas[3],0)*pow(deltas[4],0);
  res.r += factor*lhs->e23;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],2)*pow(deltas[3],0)*pow(deltas[4],0);
  res.r += factor*lhs->e33;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],1)*pow(deltas[4],0);
  res.r += factor*lhs->e14;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],1)*pow(deltas[4],0);
  res.r += factor*lhs->e24;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],1)*pow(deltas[4],0);
  res.r += factor*lhs->e34;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],2)*pow(deltas[4],0);
  res.r += factor*lhs->e44;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],1);
  res.r += factor*lhs->e15;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],1);
  res.r += factor*lhs->e25;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],0)*pow(deltas[4],1);
  res.r += factor*lhs->e35;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],1)*pow(deltas[4],1);
  res.r += factor*lhs->e45;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],2);
  res.r += factor*lhs->e55;
  // Order 3;
  factor = pow(deltas[0],3)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],0);
  res.r += factor*lhs->e111;
  factor = pow(deltas[0],2)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],0);
  res.r += factor*lhs->e112;
  factor = pow(deltas[0],1)*pow(deltas[1],2)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],0);
  res.r += factor*lhs->e122;
  factor = pow(deltas[0],0)*pow(deltas[1],3)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],0);
  res.r += factor*lhs->e222;
  factor = pow(deltas[0],2)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],0)*pow(deltas[4],0);
  res.r += factor*lhs->e113;
  factor = pow(deltas[0],1)*pow(deltas[1],1)*pow(deltas[2],1)*pow(deltas[3],0)*pow(deltas[4],0);
  res.r += factor*lhs->e123;
  factor = pow(deltas[0],0)*pow(deltas[1],2)*pow(deltas[2],1)*pow(deltas[3],0)*pow(deltas[4],0);
  res.r += factor*lhs->e223;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],2)*pow(deltas[3],0)*pow(deltas[4],0);
  res.r += factor*lhs->e133;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],2)*pow(deltas[3],0)*pow(deltas[4],0);
  res.r += factor*lhs->e233;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],3)*pow(deltas[3],0)*pow(deltas[4],0);
  res.r += factor*lhs->e333;
  factor = pow(deltas[0],2)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],1)*pow(deltas[4],0);
  res.r += factor*lhs->e114;
  factor = pow(deltas[0],1)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],1)*pow(deltas[4],0);
  res.r += factor*lhs->e124;
  factor = pow(deltas[0],0)*pow(deltas[1],2)*pow(deltas[2],0)*pow(deltas[3],1)*pow(deltas[4],0);
  res.r += factor*lhs->e224;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],1)*pow(deltas[4],0);
  res.r += factor*lhs->e134;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],1)*pow(deltas[3],1)*pow(deltas[4],0);
  res.r += factor*lhs->e234;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],2)*pow(deltas[3],1)*pow(deltas[4],0);
  res.r += factor*lhs->e334;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],2)*pow(deltas[4],0);
  res.r += factor*lhs->e144;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],2)*pow(deltas[4],0);
  res.r += factor*lhs->e244;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],2)*pow(deltas[4],0);
  res.r += factor*lhs->e344;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],3)*pow(deltas[4],0);
  res.r += factor*lhs->e444;
  factor = pow(deltas[0],2)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],1);
  res.r += factor*lhs->e115;
  factor = pow(deltas[0],1)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],1);
  res.r += factor*lhs->e125;
  factor = pow(deltas[0],0)*pow(deltas[1],2)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],1);
  res.r += factor*lhs->e225;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],0)*pow(deltas[4],1);
  res.r += factor*lhs->e135;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],1)*pow(deltas[3],0)*pow(deltas[4],1);
  res.r += factor*lhs->e235;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],2)*pow(deltas[3],0)*pow(deltas[4],1);
  res.r += factor*lhs->e335;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],1)*pow(deltas[4],1);
  res.r += factor*lhs->e145;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],1)*pow(deltas[4],1);
  res.r += factor*lhs->e245;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],1)*pow(deltas[4],1);
  res.r += factor*lhs->e345;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],2)*pow(deltas[4],1);
  res.r += factor*lhs->e445;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],2);
  res.r += factor*lhs->e155;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],2);
  res.r += factor*lhs->e255;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],0)*pow(deltas[4],2);
  res.r += factor*lhs->e355;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],1)*pow(deltas[4],2);
  res.r += factor*lhs->e455;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],3);
  res.r += factor*lhs->e555;
  // Order 4;
  factor = pow(deltas[0],4)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],0);
  res.r += factor*lhs->e1111;
  factor = pow(deltas[0],3)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],0);
  res.r += factor*lhs->e1112;
  factor = pow(deltas[0],2)*pow(deltas[1],2)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],0);
  res.r += factor*lhs->e1122;
  factor = pow(deltas[0],1)*pow(deltas[1],3)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],0);
  res.r += factor*lhs->e1222;
  factor = pow(deltas[0],0)*pow(deltas[1],4)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],0);
  res.r += factor*lhs->e2222;
  factor = pow(deltas[0],3)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],0)*pow(deltas[4],0);
  res.r += factor*lhs->e1113;
  factor = pow(deltas[0],2)*pow(deltas[1],1)*pow(deltas[2],1)*pow(deltas[3],0)*pow(deltas[4],0);
  res.r += factor*lhs->e1123;
  factor = pow(deltas[0],1)*pow(deltas[1],2)*pow(deltas[2],1)*pow(deltas[3],0)*pow(deltas[4],0);
  res.r += factor*lhs->e1223;
  factor = pow(deltas[0],0)*pow(deltas[1],3)*pow(deltas[2],1)*pow(deltas[3],0)*pow(deltas[4],0);
  res.r += factor*lhs->e2223;
  factor = pow(deltas[0],2)*pow(deltas[1],0)*pow(deltas[2],2)*pow(deltas[3],0)*pow(deltas[4],0);
  res.r += factor*lhs->e1133;
  factor = pow(deltas[0],1)*pow(deltas[1],1)*pow(deltas[2],2)*pow(deltas[3],0)*pow(deltas[4],0);
  res.r += factor*lhs->e1233;
  factor = pow(deltas[0],0)*pow(deltas[1],2)*pow(deltas[2],2)*pow(deltas[3],0)*pow(deltas[4],0);
  res.r += factor*lhs->e2233;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],3)*pow(deltas[3],0)*pow(deltas[4],0);
  res.r += factor*lhs->e1333;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],3)*pow(deltas[3],0)*pow(deltas[4],0);
  res.r += factor*lhs->e2333;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],4)*pow(deltas[3],0)*pow(deltas[4],0);
  res.r += factor*lhs->e3333;
  factor = pow(deltas[0],3)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],1)*pow(deltas[4],0);
  res.r += factor*lhs->e1114;
  factor = pow(deltas[0],2)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],1)*pow(deltas[4],0);
  res.r += factor*lhs->e1124;
  factor = pow(deltas[0],1)*pow(deltas[1],2)*pow(deltas[2],0)*pow(deltas[3],1)*pow(deltas[4],0);
  res.r += factor*lhs->e1224;
  factor = pow(deltas[0],0)*pow(deltas[1],3)*pow(deltas[2],0)*pow(deltas[3],1)*pow(deltas[4],0);
  res.r += factor*lhs->e2224;
  factor = pow(deltas[0],2)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],1)*pow(deltas[4],0);
  res.r += factor*lhs->e1134;
  factor = pow(deltas[0],1)*pow(deltas[1],1)*pow(deltas[2],1)*pow(deltas[3],1)*pow(deltas[4],0);
  res.r += factor*lhs->e1234;
  factor = pow(deltas[0],0)*pow(deltas[1],2)*pow(deltas[2],1)*pow(deltas[3],1)*pow(deltas[4],0);
  res.r += factor*lhs->e2234;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],2)*pow(deltas[3],1)*pow(deltas[4],0);
  res.r += factor*lhs->e1334;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],2)*pow(deltas[3],1)*pow(deltas[4],0);
  res.r += factor*lhs->e2334;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],3)*pow(deltas[3],1)*pow(deltas[4],0);
  res.r += factor*lhs->e3334;
  factor = pow(deltas[0],2)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],2)*pow(deltas[4],0);
  res.r += factor*lhs->e1144;
  factor = pow(deltas[0],1)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],2)*pow(deltas[4],0);
  res.r += factor*lhs->e1244;
  factor = pow(deltas[0],0)*pow(deltas[1],2)*pow(deltas[2],0)*pow(deltas[3],2)*pow(deltas[4],0);
  res.r += factor*lhs->e2244;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],2)*pow(deltas[4],0);
  res.r += factor*lhs->e1344;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],1)*pow(deltas[3],2)*pow(deltas[4],0);
  res.r += factor*lhs->e2344;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],2)*pow(deltas[3],2)*pow(deltas[4],0);
  res.r += factor*lhs->e3344;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],3)*pow(deltas[4],0);
  res.r += factor*lhs->e1444;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],3)*pow(deltas[4],0);
  res.r += factor*lhs->e2444;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],3)*pow(deltas[4],0);
  res.r += factor*lhs->e3444;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],4)*pow(deltas[4],0);
  res.r += factor*lhs->e4444;
  factor = pow(deltas[0],3)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],1);
  res.r += factor*lhs->e1115;
  factor = pow(deltas[0],2)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],1);
  res.r += factor*lhs->e1125;
  factor = pow(deltas[0],1)*pow(deltas[1],2)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],1);
  res.r += factor*lhs->e1225;
  factor = pow(deltas[0],0)*pow(deltas[1],3)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],1);
  res.r += factor*lhs->e2225;
  factor = pow(deltas[0],2)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],0)*pow(deltas[4],1);
  res.r += factor*lhs->e1135;
  factor = pow(deltas[0],1)*pow(deltas[1],1)*pow(deltas[2],1)*pow(deltas[3],0)*pow(deltas[4],1);
  res.r += factor*lhs->e1235;
  factor = pow(deltas[0],0)*pow(deltas[1],2)*pow(deltas[2],1)*pow(deltas[3],0)*pow(deltas[4],1);
  res.r += factor*lhs->e2235;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],2)*pow(deltas[3],0)*pow(deltas[4],1);
  res.r += factor*lhs->e1335;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],2)*pow(deltas[3],0)*pow(deltas[4],1);
  res.r += factor*lhs->e2335;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],3)*pow(deltas[3],0)*pow(deltas[4],1);
  res.r += factor*lhs->e3335;
  factor = pow(deltas[0],2)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],1)*pow(deltas[4],1);
  res.r += factor*lhs->e1145;
  factor = pow(deltas[0],1)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],1)*pow(deltas[4],1);
  res.r += factor*lhs->e1245;
  factor = pow(deltas[0],0)*pow(deltas[1],2)*pow(deltas[2],0)*pow(deltas[3],1)*pow(deltas[4],1);
  res.r += factor*lhs->e2245;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],1)*pow(deltas[4],1);
  res.r += factor*lhs->e1345;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],1)*pow(deltas[3],1)*pow(deltas[4],1);
  res.r += factor*lhs->e2345;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],2)*pow(deltas[3],1)*pow(deltas[4],1);
  res.r += factor*lhs->e3345;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],2)*pow(deltas[4],1);
  res.r += factor*lhs->e1445;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],2)*pow(deltas[4],1);
  res.r += factor*lhs->e2445;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],2)*pow(deltas[4],1);
  res.r += factor*lhs->e3445;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],3)*pow(deltas[4],1);
  res.r += factor*lhs->e4445;
  factor = pow(deltas[0],2)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],2);
  res.r += factor*lhs->e1155;
  factor = pow(deltas[0],1)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],2);
  res.r += factor*lhs->e1255;
  factor = pow(deltas[0],0)*pow(deltas[1],2)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],2);
  res.r += factor*lhs->e2255;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],0)*pow(deltas[4],2);
  res.r += factor*lhs->e1355;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],1)*pow(deltas[3],0)*pow(deltas[4],2);
  res.r += factor*lhs->e2355;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],2)*pow(deltas[3],0)*pow(deltas[4],2);
  res.r += factor*lhs->e3355;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],1)*pow(deltas[4],2);
  res.r += factor*lhs->e1455;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],1)*pow(deltas[4],2);
  res.r += factor*lhs->e2455;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],1)*pow(deltas[4],2);
  res.r += factor*lhs->e3455;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],2)*pow(deltas[4],2);
  res.r += factor*lhs->e4455;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],3);
  res.r += factor*lhs->e1555;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],3);
  res.r += factor*lhs->e2555;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],0)*pow(deltas[4],3);
  res.r += factor*lhs->e3555;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],1)*pow(deltas[4],3);
  res.r += factor*lhs->e4555;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],4);
  res.r += factor*lhs->e5555;

  return res;

}

void onumm5n4_taylor_integrate_to(coeff_t* deltas,onumm5n4_t* lhs, onumm5n4_t* res){

  *res = onumm5n4_init();
  coeff_t factor;
  // Taylor integration
  // Real;
  res->r = lhs->r;
  // Order 1;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],0);
  res->r += factor*lhs->e1;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],0);
  res->r += factor*lhs->e2;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],0)*pow(deltas[4],0);
  res->r += factor*lhs->e3;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],1)*pow(deltas[4],0);
  res->r += factor*lhs->e4;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],1);
  res->r += factor*lhs->e5;
  // Order 2;
  factor = pow(deltas[0],2)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],0);
  res->r += factor*lhs->e11;
  factor = pow(deltas[0],1)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],0);
  res->r += factor*lhs->e12;
  factor = pow(deltas[0],0)*pow(deltas[1],2)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],0);
  res->r += factor*lhs->e22;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],0)*pow(deltas[4],0);
  res->r += factor*lhs->e13;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],1)*pow(deltas[3],0)*pow(deltas[4],0);
  res->r += factor*lhs->e23;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],2)*pow(deltas[3],0)*pow(deltas[4],0);
  res->r += factor*lhs->e33;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],1)*pow(deltas[4],0);
  res->r += factor*lhs->e14;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],1)*pow(deltas[4],0);
  res->r += factor*lhs->e24;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],1)*pow(deltas[4],0);
  res->r += factor*lhs->e34;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],2)*pow(deltas[4],0);
  res->r += factor*lhs->e44;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],1);
  res->r += factor*lhs->e15;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],1);
  res->r += factor*lhs->e25;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],0)*pow(deltas[4],1);
  res->r += factor*lhs->e35;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],1)*pow(deltas[4],1);
  res->r += factor*lhs->e45;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],2);
  res->r += factor*lhs->e55;
  // Order 3;
  factor = pow(deltas[0],3)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],0);
  res->r += factor*lhs->e111;
  factor = pow(deltas[0],2)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],0);
  res->r += factor*lhs->e112;
  factor = pow(deltas[0],1)*pow(deltas[1],2)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],0);
  res->r += factor*lhs->e122;
  factor = pow(deltas[0],0)*pow(deltas[1],3)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],0);
  res->r += factor*lhs->e222;
  factor = pow(deltas[0],2)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],0)*pow(deltas[4],0);
  res->r += factor*lhs->e113;
  factor = pow(deltas[0],1)*pow(deltas[1],1)*pow(deltas[2],1)*pow(deltas[3],0)*pow(deltas[4],0);
  res->r += factor*lhs->e123;
  factor = pow(deltas[0],0)*pow(deltas[1],2)*pow(deltas[2],1)*pow(deltas[3],0)*pow(deltas[4],0);
  res->r += factor*lhs->e223;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],2)*pow(deltas[3],0)*pow(deltas[4],0);
  res->r += factor*lhs->e133;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],2)*pow(deltas[3],0)*pow(deltas[4],0);
  res->r += factor*lhs->e233;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],3)*pow(deltas[3],0)*pow(deltas[4],0);
  res->r += factor*lhs->e333;
  factor = pow(deltas[0],2)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],1)*pow(deltas[4],0);
  res->r += factor*lhs->e114;
  factor = pow(deltas[0],1)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],1)*pow(deltas[4],0);
  res->r += factor*lhs->e124;
  factor = pow(deltas[0],0)*pow(deltas[1],2)*pow(deltas[2],0)*pow(deltas[3],1)*pow(deltas[4],0);
  res->r += factor*lhs->e224;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],1)*pow(deltas[4],0);
  res->r += factor*lhs->e134;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],1)*pow(deltas[3],1)*pow(deltas[4],0);
  res->r += factor*lhs->e234;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],2)*pow(deltas[3],1)*pow(deltas[4],0);
  res->r += factor*lhs->e334;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],2)*pow(deltas[4],0);
  res->r += factor*lhs->e144;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],2)*pow(deltas[4],0);
  res->r += factor*lhs->e244;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],2)*pow(deltas[4],0);
  res->r += factor*lhs->e344;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],3)*pow(deltas[4],0);
  res->r += factor*lhs->e444;
  factor = pow(deltas[0],2)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],1);
  res->r += factor*lhs->e115;
  factor = pow(deltas[0],1)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],1);
  res->r += factor*lhs->e125;
  factor = pow(deltas[0],0)*pow(deltas[1],2)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],1);
  res->r += factor*lhs->e225;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],0)*pow(deltas[4],1);
  res->r += factor*lhs->e135;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],1)*pow(deltas[3],0)*pow(deltas[4],1);
  res->r += factor*lhs->e235;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],2)*pow(deltas[3],0)*pow(deltas[4],1);
  res->r += factor*lhs->e335;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],1)*pow(deltas[4],1);
  res->r += factor*lhs->e145;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],1)*pow(deltas[4],1);
  res->r += factor*lhs->e245;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],1)*pow(deltas[4],1);
  res->r += factor*lhs->e345;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],2)*pow(deltas[4],1);
  res->r += factor*lhs->e445;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],2);
  res->r += factor*lhs->e155;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],2);
  res->r += factor*lhs->e255;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],0)*pow(deltas[4],2);
  res->r += factor*lhs->e355;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],1)*pow(deltas[4],2);
  res->r += factor*lhs->e455;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],3);
  res->r += factor*lhs->e555;
  // Order 4;
  factor = pow(deltas[0],4)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],0);
  res->r += factor*lhs->e1111;
  factor = pow(deltas[0],3)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],0);
  res->r += factor*lhs->e1112;
  factor = pow(deltas[0],2)*pow(deltas[1],2)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],0);
  res->r += factor*lhs->e1122;
  factor = pow(deltas[0],1)*pow(deltas[1],3)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],0);
  res->r += factor*lhs->e1222;
  factor = pow(deltas[0],0)*pow(deltas[1],4)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],0);
  res->r += factor*lhs->e2222;
  factor = pow(deltas[0],3)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],0)*pow(deltas[4],0);
  res->r += factor*lhs->e1113;
  factor = pow(deltas[0],2)*pow(deltas[1],1)*pow(deltas[2],1)*pow(deltas[3],0)*pow(deltas[4],0);
  res->r += factor*lhs->e1123;
  factor = pow(deltas[0],1)*pow(deltas[1],2)*pow(deltas[2],1)*pow(deltas[3],0)*pow(deltas[4],0);
  res->r += factor*lhs->e1223;
  factor = pow(deltas[0],0)*pow(deltas[1],3)*pow(deltas[2],1)*pow(deltas[3],0)*pow(deltas[4],0);
  res->r += factor*lhs->e2223;
  factor = pow(deltas[0],2)*pow(deltas[1],0)*pow(deltas[2],2)*pow(deltas[3],0)*pow(deltas[4],0);
  res->r += factor*lhs->e1133;
  factor = pow(deltas[0],1)*pow(deltas[1],1)*pow(deltas[2],2)*pow(deltas[3],0)*pow(deltas[4],0);
  res->r += factor*lhs->e1233;
  factor = pow(deltas[0],0)*pow(deltas[1],2)*pow(deltas[2],2)*pow(deltas[3],0)*pow(deltas[4],0);
  res->r += factor*lhs->e2233;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],3)*pow(deltas[3],0)*pow(deltas[4],0);
  res->r += factor*lhs->e1333;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],3)*pow(deltas[3],0)*pow(deltas[4],0);
  res->r += factor*lhs->e2333;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],4)*pow(deltas[3],0)*pow(deltas[4],0);
  res->r += factor*lhs->e3333;
  factor = pow(deltas[0],3)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],1)*pow(deltas[4],0);
  res->r += factor*lhs->e1114;
  factor = pow(deltas[0],2)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],1)*pow(deltas[4],0);
  res->r += factor*lhs->e1124;
  factor = pow(deltas[0],1)*pow(deltas[1],2)*pow(deltas[2],0)*pow(deltas[3],1)*pow(deltas[4],0);
  res->r += factor*lhs->e1224;
  factor = pow(deltas[0],0)*pow(deltas[1],3)*pow(deltas[2],0)*pow(deltas[3],1)*pow(deltas[4],0);
  res->r += factor*lhs->e2224;
  factor = pow(deltas[0],2)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],1)*pow(deltas[4],0);
  res->r += factor*lhs->e1134;
  factor = pow(deltas[0],1)*pow(deltas[1],1)*pow(deltas[2],1)*pow(deltas[3],1)*pow(deltas[4],0);
  res->r += factor*lhs->e1234;
  factor = pow(deltas[0],0)*pow(deltas[1],2)*pow(deltas[2],1)*pow(deltas[3],1)*pow(deltas[4],0);
  res->r += factor*lhs->e2234;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],2)*pow(deltas[3],1)*pow(deltas[4],0);
  res->r += factor*lhs->e1334;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],2)*pow(deltas[3],1)*pow(deltas[4],0);
  res->r += factor*lhs->e2334;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],3)*pow(deltas[3],1)*pow(deltas[4],0);
  res->r += factor*lhs->e3334;
  factor = pow(deltas[0],2)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],2)*pow(deltas[4],0);
  res->r += factor*lhs->e1144;
  factor = pow(deltas[0],1)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],2)*pow(deltas[4],0);
  res->r += factor*lhs->e1244;
  factor = pow(deltas[0],0)*pow(deltas[1],2)*pow(deltas[2],0)*pow(deltas[3],2)*pow(deltas[4],0);
  res->r += factor*lhs->e2244;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],2)*pow(deltas[4],0);
  res->r += factor*lhs->e1344;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],1)*pow(deltas[3],2)*pow(deltas[4],0);
  res->r += factor*lhs->e2344;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],2)*pow(deltas[3],2)*pow(deltas[4],0);
  res->r += factor*lhs->e3344;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],3)*pow(deltas[4],0);
  res->r += factor*lhs->e1444;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],3)*pow(deltas[4],0);
  res->r += factor*lhs->e2444;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],3)*pow(deltas[4],0);
  res->r += factor*lhs->e3444;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],4)*pow(deltas[4],0);
  res->r += factor*lhs->e4444;
  factor = pow(deltas[0],3)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],1);
  res->r += factor*lhs->e1115;
  factor = pow(deltas[0],2)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],1);
  res->r += factor*lhs->e1125;
  factor = pow(deltas[0],1)*pow(deltas[1],2)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],1);
  res->r += factor*lhs->e1225;
  factor = pow(deltas[0],0)*pow(deltas[1],3)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],1);
  res->r += factor*lhs->e2225;
  factor = pow(deltas[0],2)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],0)*pow(deltas[4],1);
  res->r += factor*lhs->e1135;
  factor = pow(deltas[0],1)*pow(deltas[1],1)*pow(deltas[2],1)*pow(deltas[3],0)*pow(deltas[4],1);
  res->r += factor*lhs->e1235;
  factor = pow(deltas[0],0)*pow(deltas[1],2)*pow(deltas[2],1)*pow(deltas[3],0)*pow(deltas[4],1);
  res->r += factor*lhs->e2235;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],2)*pow(deltas[3],0)*pow(deltas[4],1);
  res->r += factor*lhs->e1335;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],2)*pow(deltas[3],0)*pow(deltas[4],1);
  res->r += factor*lhs->e2335;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],3)*pow(deltas[3],0)*pow(deltas[4],1);
  res->r += factor*lhs->e3335;
  factor = pow(deltas[0],2)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],1)*pow(deltas[4],1);
  res->r += factor*lhs->e1145;
  factor = pow(deltas[0],1)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],1)*pow(deltas[4],1);
  res->r += factor*lhs->e1245;
  factor = pow(deltas[0],0)*pow(deltas[1],2)*pow(deltas[2],0)*pow(deltas[3],1)*pow(deltas[4],1);
  res->r += factor*lhs->e2245;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],1)*pow(deltas[4],1);
  res->r += factor*lhs->e1345;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],1)*pow(deltas[3],1)*pow(deltas[4],1);
  res->r += factor*lhs->e2345;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],2)*pow(deltas[3],1)*pow(deltas[4],1);
  res->r += factor*lhs->e3345;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],2)*pow(deltas[4],1);
  res->r += factor*lhs->e1445;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],2)*pow(deltas[4],1);
  res->r += factor*lhs->e2445;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],2)*pow(deltas[4],1);
  res->r += factor*lhs->e3445;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],3)*pow(deltas[4],1);
  res->r += factor*lhs->e4445;
  factor = pow(deltas[0],2)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],2);
  res->r += factor*lhs->e1155;
  factor = pow(deltas[0],1)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],2);
  res->r += factor*lhs->e1255;
  factor = pow(deltas[0],0)*pow(deltas[1],2)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],2);
  res->r += factor*lhs->e2255;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],0)*pow(deltas[4],2);
  res->r += factor*lhs->e1355;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],1)*pow(deltas[3],0)*pow(deltas[4],2);
  res->r += factor*lhs->e2355;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],2)*pow(deltas[3],0)*pow(deltas[4],2);
  res->r += factor*lhs->e3355;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],1)*pow(deltas[4],2);
  res->r += factor*lhs->e1455;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],1)*pow(deltas[4],2);
  res->r += factor*lhs->e2455;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],1)*pow(deltas[4],2);
  res->r += factor*lhs->e3455;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],2)*pow(deltas[4],2);
  res->r += factor*lhs->e4455;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],3);
  res->r += factor*lhs->e1555;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],3);
  res->r += factor*lhs->e2555;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],0)*pow(deltas[4],3);
  res->r += factor*lhs->e3555;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],1)*pow(deltas[4],3);
  res->r += factor*lhs->e4555;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],4);
  res->r += factor*lhs->e5555;

}

onumm5n4_t onumm5n4_truncate_im(imdir_t idx, ord_t order, onumm5n4_t* lhs){

  onumm5n4_t res;

  // Copy number.
  res = (*lhs);
  // Truncate all other values when necessary.
  // Real;
  switch (order){
    case 0:
      res = onumm5n4_init();
      break;
    case 1:
      switch (idx){
        case 0: //  e1
          res.e1 = 0.0;
          res.e11 = 0.0;
          res.e12 = 0.0;
          res.e13 = 0.0;
          res.e14 = 0.0;
          res.e15 = 0.0;
          res.e111 = 0.0;
          res.e112 = 0.0;
          res.e122 = 0.0;
          res.e113 = 0.0;
          res.e123 = 0.0;
          res.e133 = 0.0;
          res.e114 = 0.0;
          res.e124 = 0.0;
          res.e134 = 0.0;
          res.e144 = 0.0;
          res.e115 = 0.0;
          res.e125 = 0.0;
          res.e135 = 0.0;
          res.e145 = 0.0;
          res.e155 = 0.0;
          res.e1111 = 0.0;
          res.e1112 = 0.0;
          res.e1122 = 0.0;
          res.e1222 = 0.0;
          res.e1113 = 0.0;
          res.e1123 = 0.0;
          res.e1223 = 0.0;
          res.e1133 = 0.0;
          res.e1233 = 0.0;
          res.e1333 = 0.0;
          res.e1114 = 0.0;
          res.e1124 = 0.0;
          res.e1224 = 0.0;
          res.e1134 = 0.0;
          res.e1234 = 0.0;
          res.e1334 = 0.0;
          res.e1144 = 0.0;
          res.e1244 = 0.0;
          res.e1344 = 0.0;
          res.e1444 = 0.0;
          res.e1115 = 0.0;
          res.e1125 = 0.0;
          res.e1225 = 0.0;
          res.e1135 = 0.0;
          res.e1235 = 0.0;
          res.e1335 = 0.0;
          res.e1145 = 0.0;
          res.e1245 = 0.0;
          res.e1345 = 0.0;
          res.e1445 = 0.0;
          res.e1155 = 0.0;
          res.e1255 = 0.0;
          res.e1355 = 0.0;
          res.e1455 = 0.0;
          res.e1555 = 0.0;
          break;
        case 1: //  e2
          res.e2 = 0.0;
          res.e12 = 0.0;
          res.e22 = 0.0;
          res.e23 = 0.0;
          res.e24 = 0.0;
          res.e25 = 0.0;
          res.e112 = 0.0;
          res.e122 = 0.0;
          res.e222 = 0.0;
          res.e123 = 0.0;
          res.e223 = 0.0;
          res.e233 = 0.0;
          res.e124 = 0.0;
          res.e224 = 0.0;
          res.e234 = 0.0;
          res.e244 = 0.0;
          res.e125 = 0.0;
          res.e225 = 0.0;
          res.e235 = 0.0;
          res.e245 = 0.0;
          res.e255 = 0.0;
          res.e1112 = 0.0;
          res.e1122 = 0.0;
          res.e1222 = 0.0;
          res.e2222 = 0.0;
          res.e1123 = 0.0;
          res.e1223 = 0.0;
          res.e2223 = 0.0;
          res.e1233 = 0.0;
          res.e2233 = 0.0;
          res.e2333 = 0.0;
          res.e1124 = 0.0;
          res.e1224 = 0.0;
          res.e2224 = 0.0;
          res.e1234 = 0.0;
          res.e2234 = 0.0;
          res.e2334 = 0.0;
          res.e1244 = 0.0;
          res.e2244 = 0.0;
          res.e2344 = 0.0;
          res.e2444 = 0.0;
          res.e1125 = 0.0;
          res.e1225 = 0.0;
          res.e2225 = 0.0;
          res.e1235 = 0.0;
          res.e2235 = 0.0;
          res.e2335 = 0.0;
          res.e1245 = 0.0;
          res.e2245 = 0.0;
          res.e2345 = 0.0;
          res.e2445 = 0.0;
          res.e1255 = 0.0;
          res.e2255 = 0.0;
          res.e2355 = 0.0;
          res.e2455 = 0.0;
          res.e2555 = 0.0;
          break;
        case 2: //  e3
          res.e3 = 0.0;
          res.e13 = 0.0;
          res.e23 = 0.0;
          res.e33 = 0.0;
          res.e34 = 0.0;
          res.e35 = 0.0;
          res.e113 = 0.0;
          res.e123 = 0.0;
          res.e223 = 0.0;
          res.e133 = 0.0;
          res.e233 = 0.0;
          res.e333 = 0.0;
          res.e134 = 0.0;
          res.e234 = 0.0;
          res.e334 = 0.0;
          res.e344 = 0.0;
          res.e135 = 0.0;
          res.e235 = 0.0;
          res.e335 = 0.0;
          res.e345 = 0.0;
          res.e355 = 0.0;
          res.e1113 = 0.0;
          res.e1123 = 0.0;
          res.e1223 = 0.0;
          res.e2223 = 0.0;
          res.e1133 = 0.0;
          res.e1233 = 0.0;
          res.e2233 = 0.0;
          res.e1333 = 0.0;
          res.e2333 = 0.0;
          res.e3333 = 0.0;
          res.e1134 = 0.0;
          res.e1234 = 0.0;
          res.e2234 = 0.0;
          res.e1334 = 0.0;
          res.e2334 = 0.0;
          res.e3334 = 0.0;
          res.e1344 = 0.0;
          res.e2344 = 0.0;
          res.e3344 = 0.0;
          res.e3444 = 0.0;
          res.e1135 = 0.0;
          res.e1235 = 0.0;
          res.e2235 = 0.0;
          res.e1335 = 0.0;
          res.e2335 = 0.0;
          res.e3335 = 0.0;
          res.e1345 = 0.0;
          res.e2345 = 0.0;
          res.e3345 = 0.0;
          res.e3445 = 0.0;
          res.e1355 = 0.0;
          res.e2355 = 0.0;
          res.e3355 = 0.0;
          res.e3455 = 0.0;
          res.e3555 = 0.0;
          break;
        case 3: //  e4
          res.e4 = 0.0;
          res.e14 = 0.0;
          res.e24 = 0.0;
          res.e34 = 0.0;
          res.e44 = 0.0;
          res.e45 = 0.0;
          res.e114 = 0.0;
          res.e124 = 0.0;
          res.e224 = 0.0;
          res.e134 = 0.0;
          res.e234 = 0.0;
          res.e334 = 0.0;
          res.e144 = 0.0;
          res.e244 = 0.0;
          res.e344 = 0.0;
          res.e444 = 0.0;
          res.e145 = 0.0;
          res.e245 = 0.0;
          res.e345 = 0.0;
          res.e445 = 0.0;
          res.e455 = 0.0;
          res.e1114 = 0.0;
          res.e1124 = 0.0;
          res.e1224 = 0.0;
          res.e2224 = 0.0;
          res.e1134 = 0.0;
          res.e1234 = 0.0;
          res.e2234 = 0.0;
          res.e1334 = 0.0;
          res.e2334 = 0.0;
          res.e3334 = 0.0;
          res.e1144 = 0.0;
          res.e1244 = 0.0;
          res.e2244 = 0.0;
          res.e1344 = 0.0;
          res.e2344 = 0.0;
          res.e3344 = 0.0;
          res.e1444 = 0.0;
          res.e2444 = 0.0;
          res.e3444 = 0.0;
          res.e4444 = 0.0;
          res.e1145 = 0.0;
          res.e1245 = 0.0;
          res.e2245 = 0.0;
          res.e1345 = 0.0;
          res.e2345 = 0.0;
          res.e3345 = 0.0;
          res.e1445 = 0.0;
          res.e2445 = 0.0;
          res.e3445 = 0.0;
          res.e4445 = 0.0;
          res.e1455 = 0.0;
          res.e2455 = 0.0;
          res.e3455 = 0.0;
          res.e4455 = 0.0;
          res.e4555 = 0.0;
          break;
        case 4: //  e5
          res.e5 = 0.0;
          res.e15 = 0.0;
          res.e25 = 0.0;
          res.e35 = 0.0;
          res.e45 = 0.0;
          res.e55 = 0.0;
          res.e115 = 0.0;
          res.e125 = 0.0;
          res.e225 = 0.0;
          res.e135 = 0.0;
          res.e235 = 0.0;
          res.e335 = 0.0;
          res.e145 = 0.0;
          res.e245 = 0.0;
          res.e345 = 0.0;
          res.e445 = 0.0;
          res.e155 = 0.0;
          res.e255 = 0.0;
          res.e355 = 0.0;
          res.e455 = 0.0;
          res.e555 = 0.0;
          res.e1115 = 0.0;
          res.e1125 = 0.0;
          res.e1225 = 0.0;
          res.e2225 = 0.0;
          res.e1135 = 0.0;
          res.e1235 = 0.0;
          res.e2235 = 0.0;
          res.e1335 = 0.0;
          res.e2335 = 0.0;
          res.e3335 = 0.0;
          res.e1145 = 0.0;
          res.e1245 = 0.0;
          res.e2245 = 0.0;
          res.e1345 = 0.0;
          res.e2345 = 0.0;
          res.e3345 = 0.0;
          res.e1445 = 0.0;
          res.e2445 = 0.0;
          res.e3445 = 0.0;
          res.e4445 = 0.0;
          res.e1155 = 0.0;
          res.e1255 = 0.0;
          res.e2255 = 0.0;
          res.e1355 = 0.0;
          res.e2355 = 0.0;
          res.e3355 = 0.0;
          res.e1455 = 0.0;
          res.e2455 = 0.0;
          res.e3455 = 0.0;
          res.e4455 = 0.0;
          res.e1555 = 0.0;
          res.e2555 = 0.0;
          res.e3555 = 0.0;
          res.e4555 = 0.0;
          res.e5555 = 0.0;
          break;
      }
      break;
    case 2:
      switch (idx){
        case 0: //  e11
          res.e11 = 0.0;
          res.e111 = 0.0;
          res.e112 = 0.0;
          res.e113 = 0.0;
          res.e114 = 0.0;
          res.e115 = 0.0;
          res.e1111 = 0.0;
          res.e1112 = 0.0;
          res.e1122 = 0.0;
          res.e1113 = 0.0;
          res.e1123 = 0.0;
          res.e1133 = 0.0;
          res.e1114 = 0.0;
          res.e1124 = 0.0;
          res.e1134 = 0.0;
          res.e1144 = 0.0;
          res.e1115 = 0.0;
          res.e1125 = 0.0;
          res.e1135 = 0.0;
          res.e1145 = 0.0;
          res.e1155 = 0.0;
          break;
        case 1: //  e12
          res.e12 = 0.0;
          res.e112 = 0.0;
          res.e122 = 0.0;
          res.e123 = 0.0;
          res.e124 = 0.0;
          res.e125 = 0.0;
          res.e1112 = 0.0;
          res.e1122 = 0.0;
          res.e1222 = 0.0;
          res.e1123 = 0.0;
          res.e1223 = 0.0;
          res.e1233 = 0.0;
          res.e1124 = 0.0;
          res.e1224 = 0.0;
          res.e1234 = 0.0;
          res.e1244 = 0.0;
          res.e1125 = 0.0;
          res.e1225 = 0.0;
          res.e1235 = 0.0;
          res.e1245 = 0.0;
          res.e1255 = 0.0;
          break;
        case 2: //  e22
          res.e22 = 0.0;
          res.e122 = 0.0;
          res.e222 = 0.0;
          res.e223 = 0.0;
          res.e224 = 0.0;
          res.e225 = 0.0;
          res.e1122 = 0.0;
          res.e1222 = 0.0;
          res.e2222 = 0.0;
          res.e1223 = 0.0;
          res.e2223 = 0.0;
          res.e2233 = 0.0;
          res.e1224 = 0.0;
          res.e2224 = 0.0;
          res.e2234 = 0.0;
          res.e2244 = 0.0;
          res.e1225 = 0.0;
          res.e2225 = 0.0;
          res.e2235 = 0.0;
          res.e2245 = 0.0;
          res.e2255 = 0.0;
          break;
        case 3: //  e13
          res.e13 = 0.0;
          res.e113 = 0.0;
          res.e123 = 0.0;
          res.e133 = 0.0;
          res.e134 = 0.0;
          res.e135 = 0.0;
          res.e1113 = 0.0;
          res.e1123 = 0.0;
          res.e1223 = 0.0;
          res.e1133 = 0.0;
          res.e1233 = 0.0;
          res.e1333 = 0.0;
          res.e1134 = 0.0;
          res.e1234 = 0.0;
          res.e1334 = 0.0;
          res.e1344 = 0.0;
          res.e1135 = 0.0;
          res.e1235 = 0.0;
          res.e1335 = 0.0;
          res.e1345 = 0.0;
          res.e1355 = 0.0;
          break;
        case 4: //  e23
          res.e23 = 0.0;
          res.e123 = 0.0;
          res.e223 = 0.0;
          res.e233 = 0.0;
          res.e234 = 0.0;
          res.e235 = 0.0;
          res.e1123 = 0.0;
          res.e1223 = 0.0;
          res.e2223 = 0.0;
          res.e1233 = 0.0;
          res.e2233 = 0.0;
          res.e2333 = 0.0;
          res.e1234 = 0.0;
          res.e2234 = 0.0;
          res.e2334 = 0.0;
          res.e2344 = 0.0;
          res.e1235 = 0.0;
          res.e2235 = 0.0;
          res.e2335 = 0.0;
          res.e2345 = 0.0;
          res.e2355 = 0.0;
          break;
        case 5: //  e33
          res.e33 = 0.0;
          res.e133 = 0.0;
          res.e233 = 0.0;
          res.e333 = 0.0;
          res.e334 = 0.0;
          res.e335 = 0.0;
          res.e1133 = 0.0;
          res.e1233 = 0.0;
          res.e2233 = 0.0;
          res.e1333 = 0.0;
          res.e2333 = 0.0;
          res.e3333 = 0.0;
          res.e1334 = 0.0;
          res.e2334 = 0.0;
          res.e3334 = 0.0;
          res.e3344 = 0.0;
          res.e1335 = 0.0;
          res.e2335 = 0.0;
          res.e3335 = 0.0;
          res.e3345 = 0.0;
          res.e3355 = 0.0;
          break;
        case 6: //  e14
          res.e14 = 0.0;
          res.e114 = 0.0;
          res.e124 = 0.0;
          res.e134 = 0.0;
          res.e144 = 0.0;
          res.e145 = 0.0;
          res.e1114 = 0.0;
          res.e1124 = 0.0;
          res.e1224 = 0.0;
          res.e1134 = 0.0;
          res.e1234 = 0.0;
          res.e1334 = 0.0;
          res.e1144 = 0.0;
          res.e1244 = 0.0;
          res.e1344 = 0.0;
          res.e1444 = 0.0;
          res.e1145 = 0.0;
          res.e1245 = 0.0;
          res.e1345 = 0.0;
          res.e1445 = 0.0;
          res.e1455 = 0.0;
          break;
        case 7: //  e24
          res.e24 = 0.0;
          res.e124 = 0.0;
          res.e224 = 0.0;
          res.e234 = 0.0;
          res.e244 = 0.0;
          res.e245 = 0.0;
          res.e1124 = 0.0;
          res.e1224 = 0.0;
          res.e2224 = 0.0;
          res.e1234 = 0.0;
          res.e2234 = 0.0;
          res.e2334 = 0.0;
          res.e1244 = 0.0;
          res.e2244 = 0.0;
          res.e2344 = 0.0;
          res.e2444 = 0.0;
          res.e1245 = 0.0;
          res.e2245 = 0.0;
          res.e2345 = 0.0;
          res.e2445 = 0.0;
          res.e2455 = 0.0;
          break;
        case 8: //  e34
          res.e34 = 0.0;
          res.e134 = 0.0;
          res.e234 = 0.0;
          res.e334 = 0.0;
          res.e344 = 0.0;
          res.e345 = 0.0;
          res.e1134 = 0.0;
          res.e1234 = 0.0;
          res.e2234 = 0.0;
          res.e1334 = 0.0;
          res.e2334 = 0.0;
          res.e3334 = 0.0;
          res.e1344 = 0.0;
          res.e2344 = 0.0;
          res.e3344 = 0.0;
          res.e3444 = 0.0;
          res.e1345 = 0.0;
          res.e2345 = 0.0;
          res.e3345 = 0.0;
          res.e3445 = 0.0;
          res.e3455 = 0.0;
          break;
        case 9: //  e44
          res.e44 = 0.0;
          res.e144 = 0.0;
          res.e244 = 0.0;
          res.e344 = 0.0;
          res.e444 = 0.0;
          res.e445 = 0.0;
          res.e1144 = 0.0;
          res.e1244 = 0.0;
          res.e2244 = 0.0;
          res.e1344 = 0.0;
          res.e2344 = 0.0;
          res.e3344 = 0.0;
          res.e1444 = 0.0;
          res.e2444 = 0.0;
          res.e3444 = 0.0;
          res.e4444 = 0.0;
          res.e1445 = 0.0;
          res.e2445 = 0.0;
          res.e3445 = 0.0;
          res.e4445 = 0.0;
          res.e4455 = 0.0;
          break;
        case 10: //  e15
          res.e15 = 0.0;
          res.e115 = 0.0;
          res.e125 = 0.0;
          res.e135 = 0.0;
          res.e145 = 0.0;
          res.e155 = 0.0;
          res.e1115 = 0.0;
          res.e1125 = 0.0;
          res.e1225 = 0.0;
          res.e1135 = 0.0;
          res.e1235 = 0.0;
          res.e1335 = 0.0;
          res.e1145 = 0.0;
          res.e1245 = 0.0;
          res.e1345 = 0.0;
          res.e1445 = 0.0;
          res.e1155 = 0.0;
          res.e1255 = 0.0;
          res.e1355 = 0.0;
          res.e1455 = 0.0;
          res.e1555 = 0.0;
          break;
        case 11: //  e25
          res.e25 = 0.0;
          res.e125 = 0.0;
          res.e225 = 0.0;
          res.e235 = 0.0;
          res.e245 = 0.0;
          res.e255 = 0.0;
          res.e1125 = 0.0;
          res.e1225 = 0.0;
          res.e2225 = 0.0;
          res.e1235 = 0.0;
          res.e2235 = 0.0;
          res.e2335 = 0.0;
          res.e1245 = 0.0;
          res.e2245 = 0.0;
          res.e2345 = 0.0;
          res.e2445 = 0.0;
          res.e1255 = 0.0;
          res.e2255 = 0.0;
          res.e2355 = 0.0;
          res.e2455 = 0.0;
          res.e2555 = 0.0;
          break;
        case 12: //  e35
          res.e35 = 0.0;
          res.e135 = 0.0;
          res.e235 = 0.0;
          res.e335 = 0.0;
          res.e345 = 0.0;
          res.e355 = 0.0;
          res.e1135 = 0.0;
          res.e1235 = 0.0;
          res.e2235 = 0.0;
          res.e1335 = 0.0;
          res.e2335 = 0.0;
          res.e3335 = 0.0;
          res.e1345 = 0.0;
          res.e2345 = 0.0;
          res.e3345 = 0.0;
          res.e3445 = 0.0;
          res.e1355 = 0.0;
          res.e2355 = 0.0;
          res.e3355 = 0.0;
          res.e3455 = 0.0;
          res.e3555 = 0.0;
          break;
        case 13: //  e45
          res.e45 = 0.0;
          res.e145 = 0.0;
          res.e245 = 0.0;
          res.e345 = 0.0;
          res.e445 = 0.0;
          res.e455 = 0.0;
          res.e1145 = 0.0;
          res.e1245 = 0.0;
          res.e2245 = 0.0;
          res.e1345 = 0.0;
          res.e2345 = 0.0;
          res.e3345 = 0.0;
          res.e1445 = 0.0;
          res.e2445 = 0.0;
          res.e3445 = 0.0;
          res.e4445 = 0.0;
          res.e1455 = 0.0;
          res.e2455 = 0.0;
          res.e3455 = 0.0;
          res.e4455 = 0.0;
          res.e4555 = 0.0;
          break;
        case 14: //  e55
          res.e55 = 0.0;
          res.e155 = 0.0;
          res.e255 = 0.0;
          res.e355 = 0.0;
          res.e455 = 0.0;
          res.e555 = 0.0;
          res.e1155 = 0.0;
          res.e1255 = 0.0;
          res.e2255 = 0.0;
          res.e1355 = 0.0;
          res.e2355 = 0.0;
          res.e3355 = 0.0;
          res.e1455 = 0.0;
          res.e2455 = 0.0;
          res.e3455 = 0.0;
          res.e4455 = 0.0;
          res.e1555 = 0.0;
          res.e2555 = 0.0;
          res.e3555 = 0.0;
          res.e4555 = 0.0;
          res.e5555 = 0.0;
          break;
      }
      break;
    case 3:
      switch (idx){
        case 0: //  e111
          res.e111 = 0.0;
          res.e1111 = 0.0;
          res.e1112 = 0.0;
          res.e1113 = 0.0;
          res.e1114 = 0.0;
          res.e1115 = 0.0;
          break;
        case 1: //  e112
          res.e112 = 0.0;
          res.e1112 = 0.0;
          res.e1122 = 0.0;
          res.e1123 = 0.0;
          res.e1124 = 0.0;
          res.e1125 = 0.0;
          break;
        case 2: //  e122
          res.e122 = 0.0;
          res.e1122 = 0.0;
          res.e1222 = 0.0;
          res.e1223 = 0.0;
          res.e1224 = 0.0;
          res.e1225 = 0.0;
          break;
        case 3: //  e222
          res.e222 = 0.0;
          res.e1222 = 0.0;
          res.e2222 = 0.0;
          res.e2223 = 0.0;
          res.e2224 = 0.0;
          res.e2225 = 0.0;
          break;
        case 4: //  e113
          res.e113 = 0.0;
          res.e1113 = 0.0;
          res.e1123 = 0.0;
          res.e1133 = 0.0;
          res.e1134 = 0.0;
          res.e1135 = 0.0;
          break;
        case 5: //  e123
          res.e123 = 0.0;
          res.e1123 = 0.0;
          res.e1223 = 0.0;
          res.e1233 = 0.0;
          res.e1234 = 0.0;
          res.e1235 = 0.0;
          break;
        case 6: //  e223
          res.e223 = 0.0;
          res.e1223 = 0.0;
          res.e2223 = 0.0;
          res.e2233 = 0.0;
          res.e2234 = 0.0;
          res.e2235 = 0.0;
          break;
        case 7: //  e133
          res.e133 = 0.0;
          res.e1133 = 0.0;
          res.e1233 = 0.0;
          res.e1333 = 0.0;
          res.e1334 = 0.0;
          res.e1335 = 0.0;
          break;
        case 8: //  e233
          res.e233 = 0.0;
          res.e1233 = 0.0;
          res.e2233 = 0.0;
          res.e2333 = 0.0;
          res.e2334 = 0.0;
          res.e2335 = 0.0;
          break;
        case 9: //  e333
          res.e333 = 0.0;
          res.e1333 = 0.0;
          res.e2333 = 0.0;
          res.e3333 = 0.0;
          res.e3334 = 0.0;
          res.e3335 = 0.0;
          break;
        case 10: //  e114
          res.e114 = 0.0;
          res.e1114 = 0.0;
          res.e1124 = 0.0;
          res.e1134 = 0.0;
          res.e1144 = 0.0;
          res.e1145 = 0.0;
          break;
        case 11: //  e124
          res.e124 = 0.0;
          res.e1124 = 0.0;
          res.e1224 = 0.0;
          res.e1234 = 0.0;
          res.e1244 = 0.0;
          res.e1245 = 0.0;
          break;
        case 12: //  e224
          res.e224 = 0.0;
          res.e1224 = 0.0;
          res.e2224 = 0.0;
          res.e2234 = 0.0;
          res.e2244 = 0.0;
          res.e2245 = 0.0;
          break;
        case 13: //  e134
          res.e134 = 0.0;
          res.e1134 = 0.0;
          res.e1234 = 0.0;
          res.e1334 = 0.0;
          res.e1344 = 0.0;
          res.e1345 = 0.0;
          break;
        case 14: //  e234
          res.e234 = 0.0;
          res.e1234 = 0.0;
          res.e2234 = 0.0;
          res.e2334 = 0.0;
          res.e2344 = 0.0;
          res.e2345 = 0.0;
          break;
        case 15: //  e334
          res.e334 = 0.0;
          res.e1334 = 0.0;
          res.e2334 = 0.0;
          res.e3334 = 0.0;
          res.e3344 = 0.0;
          res.e3345 = 0.0;
          break;
        case 16: //  e144
          res.e144 = 0.0;
          res.e1144 = 0.0;
          res.e1244 = 0.0;
          res.e1344 = 0.0;
          res.e1444 = 0.0;
          res.e1445 = 0.0;
          break;
        case 17: //  e244
          res.e244 = 0.0;
          res.e1244 = 0.0;
          res.e2244 = 0.0;
          res.e2344 = 0.0;
          res.e2444 = 0.0;
          res.e2445 = 0.0;
          break;
        case 18: //  e344
          res.e344 = 0.0;
          res.e1344 = 0.0;
          res.e2344 = 0.0;
          res.e3344 = 0.0;
          res.e3444 = 0.0;
          res.e3445 = 0.0;
          break;
        case 19: //  e444
          res.e444 = 0.0;
          res.e1444 = 0.0;
          res.e2444 = 0.0;
          res.e3444 = 0.0;
          res.e4444 = 0.0;
          res.e4445 = 0.0;
          break;
        case 20: //  e115
          res.e115 = 0.0;
          res.e1115 = 0.0;
          res.e1125 = 0.0;
          res.e1135 = 0.0;
          res.e1145 = 0.0;
          res.e1155 = 0.0;
          break;
        case 21: //  e125
          res.e125 = 0.0;
          res.e1125 = 0.0;
          res.e1225 = 0.0;
          res.e1235 = 0.0;
          res.e1245 = 0.0;
          res.e1255 = 0.0;
          break;
        case 22: //  e225
          res.e225 = 0.0;
          res.e1225 = 0.0;
          res.e2225 = 0.0;
          res.e2235 = 0.0;
          res.e2245 = 0.0;
          res.e2255 = 0.0;
          break;
        case 23: //  e135
          res.e135 = 0.0;
          res.e1135 = 0.0;
          res.e1235 = 0.0;
          res.e1335 = 0.0;
          res.e1345 = 0.0;
          res.e1355 = 0.0;
          break;
        case 24: //  e235
          res.e235 = 0.0;
          res.e1235 = 0.0;
          res.e2235 = 0.0;
          res.e2335 = 0.0;
          res.e2345 = 0.0;
          res.e2355 = 0.0;
          break;
        case 25: //  e335
          res.e335 = 0.0;
          res.e1335 = 0.0;
          res.e2335 = 0.0;
          res.e3335 = 0.0;
          res.e3345 = 0.0;
          res.e3355 = 0.0;
          break;
        case 26: //  e145
          res.e145 = 0.0;
          res.e1145 = 0.0;
          res.e1245 = 0.0;
          res.e1345 = 0.0;
          res.e1445 = 0.0;
          res.e1455 = 0.0;
          break;
        case 27: //  e245
          res.e245 = 0.0;
          res.e1245 = 0.0;
          res.e2245 = 0.0;
          res.e2345 = 0.0;
          res.e2445 = 0.0;
          res.e2455 = 0.0;
          break;
        case 28: //  e345
          res.e345 = 0.0;
          res.e1345 = 0.0;
          res.e2345 = 0.0;
          res.e3345 = 0.0;
          res.e3445 = 0.0;
          res.e3455 = 0.0;
          break;
        case 29: //  e445
          res.e445 = 0.0;
          res.e1445 = 0.0;
          res.e2445 = 0.0;
          res.e3445 = 0.0;
          res.e4445 = 0.0;
          res.e4455 = 0.0;
          break;
        case 30: //  e155
          res.e155 = 0.0;
          res.e1155 = 0.0;
          res.e1255 = 0.0;
          res.e1355 = 0.0;
          res.e1455 = 0.0;
          res.e1555 = 0.0;
          break;
        case 31: //  e255
          res.e255 = 0.0;
          res.e1255 = 0.0;
          res.e2255 = 0.0;
          res.e2355 = 0.0;
          res.e2455 = 0.0;
          res.e2555 = 0.0;
          break;
        case 32: //  e355
          res.e355 = 0.0;
          res.e1355 = 0.0;
          res.e2355 = 0.0;
          res.e3355 = 0.0;
          res.e3455 = 0.0;
          res.e3555 = 0.0;
          break;
        case 33: //  e455
          res.e455 = 0.0;
          res.e1455 = 0.0;
          res.e2455 = 0.0;
          res.e3455 = 0.0;
          res.e4455 = 0.0;
          res.e4555 = 0.0;
          break;
        case 34: //  e555
          res.e555 = 0.0;
          res.e1555 = 0.0;
          res.e2555 = 0.0;
          res.e3555 = 0.0;
          res.e4555 = 0.0;
          res.e5555 = 0.0;
          break;
      }
      break;
    case 4:
      switch (idx){
        case 0: //  e1111
          res.e1111 = 0.0;
          break;
        case 1: //  e1112
          res.e1112 = 0.0;
          break;
        case 2: //  e1122
          res.e1122 = 0.0;
          break;
        case 3: //  e1222
          res.e1222 = 0.0;
          break;
        case 4: //  e2222
          res.e2222 = 0.0;
          break;
        case 5: //  e1113
          res.e1113 = 0.0;
          break;
        case 6: //  e1123
          res.e1123 = 0.0;
          break;
        case 7: //  e1223
          res.e1223 = 0.0;
          break;
        case 8: //  e2223
          res.e2223 = 0.0;
          break;
        case 9: //  e1133
          res.e1133 = 0.0;
          break;
        case 10: //  e1233
          res.e1233 = 0.0;
          break;
        case 11: //  e2233
          res.e2233 = 0.0;
          break;
        case 12: //  e1333
          res.e1333 = 0.0;
          break;
        case 13: //  e2333
          res.e2333 = 0.0;
          break;
        case 14: //  e3333
          res.e3333 = 0.0;
          break;
        case 15: //  e1114
          res.e1114 = 0.0;
          break;
        case 16: //  e1124
          res.e1124 = 0.0;
          break;
        case 17: //  e1224
          res.e1224 = 0.0;
          break;
        case 18: //  e2224
          res.e2224 = 0.0;
          break;
        case 19: //  e1134
          res.e1134 = 0.0;
          break;
        case 20: //  e1234
          res.e1234 = 0.0;
          break;
        case 21: //  e2234
          res.e2234 = 0.0;
          break;
        case 22: //  e1334
          res.e1334 = 0.0;
          break;
        case 23: //  e2334
          res.e2334 = 0.0;
          break;
        case 24: //  e3334
          res.e3334 = 0.0;
          break;
        case 25: //  e1144
          res.e1144 = 0.0;
          break;
        case 26: //  e1244
          res.e1244 = 0.0;
          break;
        case 27: //  e2244
          res.e2244 = 0.0;
          break;
        case 28: //  e1344
          res.e1344 = 0.0;
          break;
        case 29: //  e2344
          res.e2344 = 0.0;
          break;
        case 30: //  e3344
          res.e3344 = 0.0;
          break;
        case 31: //  e1444
          res.e1444 = 0.0;
          break;
        case 32: //  e2444
          res.e2444 = 0.0;
          break;
        case 33: //  e3444
          res.e3444 = 0.0;
          break;
        case 34: //  e4444
          res.e4444 = 0.0;
          break;
        case 35: //  e1115
          res.e1115 = 0.0;
          break;
        case 36: //  e1125
          res.e1125 = 0.0;
          break;
        case 37: //  e1225
          res.e1225 = 0.0;
          break;
        case 38: //  e2225
          res.e2225 = 0.0;
          break;
        case 39: //  e1135
          res.e1135 = 0.0;
          break;
        case 40: //  e1235
          res.e1235 = 0.0;
          break;
        case 41: //  e2235
          res.e2235 = 0.0;
          break;
        case 42: //  e1335
          res.e1335 = 0.0;
          break;
        case 43: //  e2335
          res.e2335 = 0.0;
          break;
        case 44: //  e3335
          res.e3335 = 0.0;
          break;
        case 45: //  e1145
          res.e1145 = 0.0;
          break;
        case 46: //  e1245
          res.e1245 = 0.0;
          break;
        case 47: //  e2245
          res.e2245 = 0.0;
          break;
        case 48: //  e1345
          res.e1345 = 0.0;
          break;
        case 49: //  e2345
          res.e2345 = 0.0;
          break;
        case 50: //  e3345
          res.e3345 = 0.0;
          break;
        case 51: //  e1445
          res.e1445 = 0.0;
          break;
        case 52: //  e2445
          res.e2445 = 0.0;
          break;
        case 53: //  e3445
          res.e3445 = 0.0;
          break;
        case 54: //  e4445
          res.e4445 = 0.0;
          break;
        case 55: //  e1155
          res.e1155 = 0.0;
          break;
        case 56: //  e1255
          res.e1255 = 0.0;
          break;
        case 57: //  e2255
          res.e2255 = 0.0;
          break;
        case 58: //  e1355
          res.e1355 = 0.0;
          break;
        case 59: //  e2355
          res.e2355 = 0.0;
          break;
        case 60: //  e3355
          res.e3355 = 0.0;
          break;
        case 61: //  e1455
          res.e1455 = 0.0;
          break;
        case 62: //  e2455
          res.e2455 = 0.0;
          break;
        case 63: //  e3455
          res.e3455 = 0.0;
          break;
        case 64: //  e4455
          res.e4455 = 0.0;
          break;
        case 65: //  e1555
          res.e1555 = 0.0;
          break;
        case 66: //  e2555
          res.e2555 = 0.0;
          break;
        case 67: //  e3555
          res.e3555 = 0.0;
          break;
        case 68: //  e4555
          res.e4555 = 0.0;
          break;
        case 69: //  e5555
          res.e5555 = 0.0;
          break;
      }
      break;
  }
  return res;

}

void onumm5n4_truncate_im_to(imdir_t idx, ord_t order, onumm5n4_t* lhs, onumm5n4_t* res){

  // Copy number.
  *res = (*lhs);
  // Truncate all other values when necessary.
  // Real;
  switch (order){
    case 0:
      *res = onumm5n4_init();
      break;
    case 1:
      switch (idx){
        case 0: //  e1
          res->e1 = 0.0;
          res->e11 = 0.0;
          res->e12 = 0.0;
          res->e13 = 0.0;
          res->e14 = 0.0;
          res->e15 = 0.0;
          res->e111 = 0.0;
          res->e112 = 0.0;
          res->e122 = 0.0;
          res->e113 = 0.0;
          res->e123 = 0.0;
          res->e133 = 0.0;
          res->e114 = 0.0;
          res->e124 = 0.0;
          res->e134 = 0.0;
          res->e144 = 0.0;
          res->e115 = 0.0;
          res->e125 = 0.0;
          res->e135 = 0.0;
          res->e145 = 0.0;
          res->e155 = 0.0;
          res->e1111 = 0.0;
          res->e1112 = 0.0;
          res->e1122 = 0.0;
          res->e1222 = 0.0;
          res->e1113 = 0.0;
          res->e1123 = 0.0;
          res->e1223 = 0.0;
          res->e1133 = 0.0;
          res->e1233 = 0.0;
          res->e1333 = 0.0;
          res->e1114 = 0.0;
          res->e1124 = 0.0;
          res->e1224 = 0.0;
          res->e1134 = 0.0;
          res->e1234 = 0.0;
          res->e1334 = 0.0;
          res->e1144 = 0.0;
          res->e1244 = 0.0;
          res->e1344 = 0.0;
          res->e1444 = 0.0;
          res->e1115 = 0.0;
          res->e1125 = 0.0;
          res->e1225 = 0.0;
          res->e1135 = 0.0;
          res->e1235 = 0.0;
          res->e1335 = 0.0;
          res->e1145 = 0.0;
          res->e1245 = 0.0;
          res->e1345 = 0.0;
          res->e1445 = 0.0;
          res->e1155 = 0.0;
          res->e1255 = 0.0;
          res->e1355 = 0.0;
          res->e1455 = 0.0;
          res->e1555 = 0.0;
          break;
        case 1: //  e2
          res->e2 = 0.0;
          res->e12 = 0.0;
          res->e22 = 0.0;
          res->e23 = 0.0;
          res->e24 = 0.0;
          res->e25 = 0.0;
          res->e112 = 0.0;
          res->e122 = 0.0;
          res->e222 = 0.0;
          res->e123 = 0.0;
          res->e223 = 0.0;
          res->e233 = 0.0;
          res->e124 = 0.0;
          res->e224 = 0.0;
          res->e234 = 0.0;
          res->e244 = 0.0;
          res->e125 = 0.0;
          res->e225 = 0.0;
          res->e235 = 0.0;
          res->e245 = 0.0;
          res->e255 = 0.0;
          res->e1112 = 0.0;
          res->e1122 = 0.0;
          res->e1222 = 0.0;
          res->e2222 = 0.0;
          res->e1123 = 0.0;
          res->e1223 = 0.0;
          res->e2223 = 0.0;
          res->e1233 = 0.0;
          res->e2233 = 0.0;
          res->e2333 = 0.0;
          res->e1124 = 0.0;
          res->e1224 = 0.0;
          res->e2224 = 0.0;
          res->e1234 = 0.0;
          res->e2234 = 0.0;
          res->e2334 = 0.0;
          res->e1244 = 0.0;
          res->e2244 = 0.0;
          res->e2344 = 0.0;
          res->e2444 = 0.0;
          res->e1125 = 0.0;
          res->e1225 = 0.0;
          res->e2225 = 0.0;
          res->e1235 = 0.0;
          res->e2235 = 0.0;
          res->e2335 = 0.0;
          res->e1245 = 0.0;
          res->e2245 = 0.0;
          res->e2345 = 0.0;
          res->e2445 = 0.0;
          res->e1255 = 0.0;
          res->e2255 = 0.0;
          res->e2355 = 0.0;
          res->e2455 = 0.0;
          res->e2555 = 0.0;
          break;
        case 2: //  e3
          res->e3 = 0.0;
          res->e13 = 0.0;
          res->e23 = 0.0;
          res->e33 = 0.0;
          res->e34 = 0.0;
          res->e35 = 0.0;
          res->e113 = 0.0;
          res->e123 = 0.0;
          res->e223 = 0.0;
          res->e133 = 0.0;
          res->e233 = 0.0;
          res->e333 = 0.0;
          res->e134 = 0.0;
          res->e234 = 0.0;
          res->e334 = 0.0;
          res->e344 = 0.0;
          res->e135 = 0.0;
          res->e235 = 0.0;
          res->e335 = 0.0;
          res->e345 = 0.0;
          res->e355 = 0.0;
          res->e1113 = 0.0;
          res->e1123 = 0.0;
          res->e1223 = 0.0;
          res->e2223 = 0.0;
          res->e1133 = 0.0;
          res->e1233 = 0.0;
          res->e2233 = 0.0;
          res->e1333 = 0.0;
          res->e2333 = 0.0;
          res->e3333 = 0.0;
          res->e1134 = 0.0;
          res->e1234 = 0.0;
          res->e2234 = 0.0;
          res->e1334 = 0.0;
          res->e2334 = 0.0;
          res->e3334 = 0.0;
          res->e1344 = 0.0;
          res->e2344 = 0.0;
          res->e3344 = 0.0;
          res->e3444 = 0.0;
          res->e1135 = 0.0;
          res->e1235 = 0.0;
          res->e2235 = 0.0;
          res->e1335 = 0.0;
          res->e2335 = 0.0;
          res->e3335 = 0.0;
          res->e1345 = 0.0;
          res->e2345 = 0.0;
          res->e3345 = 0.0;
          res->e3445 = 0.0;
          res->e1355 = 0.0;
          res->e2355 = 0.0;
          res->e3355 = 0.0;
          res->e3455 = 0.0;
          res->e3555 = 0.0;
          break;
        case 3: //  e4
          res->e4 = 0.0;
          res->e14 = 0.0;
          res->e24 = 0.0;
          res->e34 = 0.0;
          res->e44 = 0.0;
          res->e45 = 0.0;
          res->e114 = 0.0;
          res->e124 = 0.0;
          res->e224 = 0.0;
          res->e134 = 0.0;
          res->e234 = 0.0;
          res->e334 = 0.0;
          res->e144 = 0.0;
          res->e244 = 0.0;
          res->e344 = 0.0;
          res->e444 = 0.0;
          res->e145 = 0.0;
          res->e245 = 0.0;
          res->e345 = 0.0;
          res->e445 = 0.0;
          res->e455 = 0.0;
          res->e1114 = 0.0;
          res->e1124 = 0.0;
          res->e1224 = 0.0;
          res->e2224 = 0.0;
          res->e1134 = 0.0;
          res->e1234 = 0.0;
          res->e2234 = 0.0;
          res->e1334 = 0.0;
          res->e2334 = 0.0;
          res->e3334 = 0.0;
          res->e1144 = 0.0;
          res->e1244 = 0.0;
          res->e2244 = 0.0;
          res->e1344 = 0.0;
          res->e2344 = 0.0;
          res->e3344 = 0.0;
          res->e1444 = 0.0;
          res->e2444 = 0.0;
          res->e3444 = 0.0;
          res->e4444 = 0.0;
          res->e1145 = 0.0;
          res->e1245 = 0.0;
          res->e2245 = 0.0;
          res->e1345 = 0.0;
          res->e2345 = 0.0;
          res->e3345 = 0.0;
          res->e1445 = 0.0;
          res->e2445 = 0.0;
          res->e3445 = 0.0;
          res->e4445 = 0.0;
          res->e1455 = 0.0;
          res->e2455 = 0.0;
          res->e3455 = 0.0;
          res->e4455 = 0.0;
          res->e4555 = 0.0;
          break;
        case 4: //  e5
          res->e5 = 0.0;
          res->e15 = 0.0;
          res->e25 = 0.0;
          res->e35 = 0.0;
          res->e45 = 0.0;
          res->e55 = 0.0;
          res->e115 = 0.0;
          res->e125 = 0.0;
          res->e225 = 0.0;
          res->e135 = 0.0;
          res->e235 = 0.0;
          res->e335 = 0.0;
          res->e145 = 0.0;
          res->e245 = 0.0;
          res->e345 = 0.0;
          res->e445 = 0.0;
          res->e155 = 0.0;
          res->e255 = 0.0;
          res->e355 = 0.0;
          res->e455 = 0.0;
          res->e555 = 0.0;
          res->e1115 = 0.0;
          res->e1125 = 0.0;
          res->e1225 = 0.0;
          res->e2225 = 0.0;
          res->e1135 = 0.0;
          res->e1235 = 0.0;
          res->e2235 = 0.0;
          res->e1335 = 0.0;
          res->e2335 = 0.0;
          res->e3335 = 0.0;
          res->e1145 = 0.0;
          res->e1245 = 0.0;
          res->e2245 = 0.0;
          res->e1345 = 0.0;
          res->e2345 = 0.0;
          res->e3345 = 0.0;
          res->e1445 = 0.0;
          res->e2445 = 0.0;
          res->e3445 = 0.0;
          res->e4445 = 0.0;
          res->e1155 = 0.0;
          res->e1255 = 0.0;
          res->e2255 = 0.0;
          res->e1355 = 0.0;
          res->e2355 = 0.0;
          res->e3355 = 0.0;
          res->e1455 = 0.0;
          res->e2455 = 0.0;
          res->e3455 = 0.0;
          res->e4455 = 0.0;
          res->e1555 = 0.0;
          res->e2555 = 0.0;
          res->e3555 = 0.0;
          res->e4555 = 0.0;
          res->e5555 = 0.0;
          break;
      }
      break;
    case 2:
      switch (idx){
        case 0: //  e11
          res->e11 = 0.0;
          res->e111 = 0.0;
          res->e112 = 0.0;
          res->e113 = 0.0;
          res->e114 = 0.0;
          res->e115 = 0.0;
          res->e1111 = 0.0;
          res->e1112 = 0.0;
          res->e1122 = 0.0;
          res->e1113 = 0.0;
          res->e1123 = 0.0;
          res->e1133 = 0.0;
          res->e1114 = 0.0;
          res->e1124 = 0.0;
          res->e1134 = 0.0;
          res->e1144 = 0.0;
          res->e1115 = 0.0;
          res->e1125 = 0.0;
          res->e1135 = 0.0;
          res->e1145 = 0.0;
          res->e1155 = 0.0;
          break;
        case 1: //  e12
          res->e12 = 0.0;
          res->e112 = 0.0;
          res->e122 = 0.0;
          res->e123 = 0.0;
          res->e124 = 0.0;
          res->e125 = 0.0;
          res->e1112 = 0.0;
          res->e1122 = 0.0;
          res->e1222 = 0.0;
          res->e1123 = 0.0;
          res->e1223 = 0.0;
          res->e1233 = 0.0;
          res->e1124 = 0.0;
          res->e1224 = 0.0;
          res->e1234 = 0.0;
          res->e1244 = 0.0;
          res->e1125 = 0.0;
          res->e1225 = 0.0;
          res->e1235 = 0.0;
          res->e1245 = 0.0;
          res->e1255 = 0.0;
          break;
        case 2: //  e22
          res->e22 = 0.0;
          res->e122 = 0.0;
          res->e222 = 0.0;
          res->e223 = 0.0;
          res->e224 = 0.0;
          res->e225 = 0.0;
          res->e1122 = 0.0;
          res->e1222 = 0.0;
          res->e2222 = 0.0;
          res->e1223 = 0.0;
          res->e2223 = 0.0;
          res->e2233 = 0.0;
          res->e1224 = 0.0;
          res->e2224 = 0.0;
          res->e2234 = 0.0;
          res->e2244 = 0.0;
          res->e1225 = 0.0;
          res->e2225 = 0.0;
          res->e2235 = 0.0;
          res->e2245 = 0.0;
          res->e2255 = 0.0;
          break;
        case 3: //  e13
          res->e13 = 0.0;
          res->e113 = 0.0;
          res->e123 = 0.0;
          res->e133 = 0.0;
          res->e134 = 0.0;
          res->e135 = 0.0;
          res->e1113 = 0.0;
          res->e1123 = 0.0;
          res->e1223 = 0.0;
          res->e1133 = 0.0;
          res->e1233 = 0.0;
          res->e1333 = 0.0;
          res->e1134 = 0.0;
          res->e1234 = 0.0;
          res->e1334 = 0.0;
          res->e1344 = 0.0;
          res->e1135 = 0.0;
          res->e1235 = 0.0;
          res->e1335 = 0.0;
          res->e1345 = 0.0;
          res->e1355 = 0.0;
          break;
        case 4: //  e23
          res->e23 = 0.0;
          res->e123 = 0.0;
          res->e223 = 0.0;
          res->e233 = 0.0;
          res->e234 = 0.0;
          res->e235 = 0.0;
          res->e1123 = 0.0;
          res->e1223 = 0.0;
          res->e2223 = 0.0;
          res->e1233 = 0.0;
          res->e2233 = 0.0;
          res->e2333 = 0.0;
          res->e1234 = 0.0;
          res->e2234 = 0.0;
          res->e2334 = 0.0;
          res->e2344 = 0.0;
          res->e1235 = 0.0;
          res->e2235 = 0.0;
          res->e2335 = 0.0;
          res->e2345 = 0.0;
          res->e2355 = 0.0;
          break;
        case 5: //  e33
          res->e33 = 0.0;
          res->e133 = 0.0;
          res->e233 = 0.0;
          res->e333 = 0.0;
          res->e334 = 0.0;
          res->e335 = 0.0;
          res->e1133 = 0.0;
          res->e1233 = 0.0;
          res->e2233 = 0.0;
          res->e1333 = 0.0;
          res->e2333 = 0.0;
          res->e3333 = 0.0;
          res->e1334 = 0.0;
          res->e2334 = 0.0;
          res->e3334 = 0.0;
          res->e3344 = 0.0;
          res->e1335 = 0.0;
          res->e2335 = 0.0;
          res->e3335 = 0.0;
          res->e3345 = 0.0;
          res->e3355 = 0.0;
          break;
        case 6: //  e14
          res->e14 = 0.0;
          res->e114 = 0.0;
          res->e124 = 0.0;
          res->e134 = 0.0;
          res->e144 = 0.0;
          res->e145 = 0.0;
          res->e1114 = 0.0;
          res->e1124 = 0.0;
          res->e1224 = 0.0;
          res->e1134 = 0.0;
          res->e1234 = 0.0;
          res->e1334 = 0.0;
          res->e1144 = 0.0;
          res->e1244 = 0.0;
          res->e1344 = 0.0;
          res->e1444 = 0.0;
          res->e1145 = 0.0;
          res->e1245 = 0.0;
          res->e1345 = 0.0;
          res->e1445 = 0.0;
          res->e1455 = 0.0;
          break;
        case 7: //  e24
          res->e24 = 0.0;
          res->e124 = 0.0;
          res->e224 = 0.0;
          res->e234 = 0.0;
          res->e244 = 0.0;
          res->e245 = 0.0;
          res->e1124 = 0.0;
          res->e1224 = 0.0;
          res->e2224 = 0.0;
          res->e1234 = 0.0;
          res->e2234 = 0.0;
          res->e2334 = 0.0;
          res->e1244 = 0.0;
          res->e2244 = 0.0;
          res->e2344 = 0.0;
          res->e2444 = 0.0;
          res->e1245 = 0.0;
          res->e2245 = 0.0;
          res->e2345 = 0.0;
          res->e2445 = 0.0;
          res->e2455 = 0.0;
          break;
        case 8: //  e34
          res->e34 = 0.0;
          res->e134 = 0.0;
          res->e234 = 0.0;
          res->e334 = 0.0;
          res->e344 = 0.0;
          res->e345 = 0.0;
          res->e1134 = 0.0;
          res->e1234 = 0.0;
          res->e2234 = 0.0;
          res->e1334 = 0.0;
          res->e2334 = 0.0;
          res->e3334 = 0.0;
          res->e1344 = 0.0;
          res->e2344 = 0.0;
          res->e3344 = 0.0;
          res->e3444 = 0.0;
          res->e1345 = 0.0;
          res->e2345 = 0.0;
          res->e3345 = 0.0;
          res->e3445 = 0.0;
          res->e3455 = 0.0;
          break;
        case 9: //  e44
          res->e44 = 0.0;
          res->e144 = 0.0;
          res->e244 = 0.0;
          res->e344 = 0.0;
          res->e444 = 0.0;
          res->e445 = 0.0;
          res->e1144 = 0.0;
          res->e1244 = 0.0;
          res->e2244 = 0.0;
          res->e1344 = 0.0;
          res->e2344 = 0.0;
          res->e3344 = 0.0;
          res->e1444 = 0.0;
          res->e2444 = 0.0;
          res->e3444 = 0.0;
          res->e4444 = 0.0;
          res->e1445 = 0.0;
          res->e2445 = 0.0;
          res->e3445 = 0.0;
          res->e4445 = 0.0;
          res->e4455 = 0.0;
          break;
        case 10: //  e15
          res->e15 = 0.0;
          res->e115 = 0.0;
          res->e125 = 0.0;
          res->e135 = 0.0;
          res->e145 = 0.0;
          res->e155 = 0.0;
          res->e1115 = 0.0;
          res->e1125 = 0.0;
          res->e1225 = 0.0;
          res->e1135 = 0.0;
          res->e1235 = 0.0;
          res->e1335 = 0.0;
          res->e1145 = 0.0;
          res->e1245 = 0.0;
          res->e1345 = 0.0;
          res->e1445 = 0.0;
          res->e1155 = 0.0;
          res->e1255 = 0.0;
          res->e1355 = 0.0;
          res->e1455 = 0.0;
          res->e1555 = 0.0;
          break;
        case 11: //  e25
          res->e25 = 0.0;
          res->e125 = 0.0;
          res->e225 = 0.0;
          res->e235 = 0.0;
          res->e245 = 0.0;
          res->e255 = 0.0;
          res->e1125 = 0.0;
          res->e1225 = 0.0;
          res->e2225 = 0.0;
          res->e1235 = 0.0;
          res->e2235 = 0.0;
          res->e2335 = 0.0;
          res->e1245 = 0.0;
          res->e2245 = 0.0;
          res->e2345 = 0.0;
          res->e2445 = 0.0;
          res->e1255 = 0.0;
          res->e2255 = 0.0;
          res->e2355 = 0.0;
          res->e2455 = 0.0;
          res->e2555 = 0.0;
          break;
        case 12: //  e35
          res->e35 = 0.0;
          res->e135 = 0.0;
          res->e235 = 0.0;
          res->e335 = 0.0;
          res->e345 = 0.0;
          res->e355 = 0.0;
          res->e1135 = 0.0;
          res->e1235 = 0.0;
          res->e2235 = 0.0;
          res->e1335 = 0.0;
          res->e2335 = 0.0;
          res->e3335 = 0.0;
          res->e1345 = 0.0;
          res->e2345 = 0.0;
          res->e3345 = 0.0;
          res->e3445 = 0.0;
          res->e1355 = 0.0;
          res->e2355 = 0.0;
          res->e3355 = 0.0;
          res->e3455 = 0.0;
          res->e3555 = 0.0;
          break;
        case 13: //  e45
          res->e45 = 0.0;
          res->e145 = 0.0;
          res->e245 = 0.0;
          res->e345 = 0.0;
          res->e445 = 0.0;
          res->e455 = 0.0;
          res->e1145 = 0.0;
          res->e1245 = 0.0;
          res->e2245 = 0.0;
          res->e1345 = 0.0;
          res->e2345 = 0.0;
          res->e3345 = 0.0;
          res->e1445 = 0.0;
          res->e2445 = 0.0;
          res->e3445 = 0.0;
          res->e4445 = 0.0;
          res->e1455 = 0.0;
          res->e2455 = 0.0;
          res->e3455 = 0.0;
          res->e4455 = 0.0;
          res->e4555 = 0.0;
          break;
        case 14: //  e55
          res->e55 = 0.0;
          res->e155 = 0.0;
          res->e255 = 0.0;
          res->e355 = 0.0;
          res->e455 = 0.0;
          res->e555 = 0.0;
          res->e1155 = 0.0;
          res->e1255 = 0.0;
          res->e2255 = 0.0;
          res->e1355 = 0.0;
          res->e2355 = 0.0;
          res->e3355 = 0.0;
          res->e1455 = 0.0;
          res->e2455 = 0.0;
          res->e3455 = 0.0;
          res->e4455 = 0.0;
          res->e1555 = 0.0;
          res->e2555 = 0.0;
          res->e3555 = 0.0;
          res->e4555 = 0.0;
          res->e5555 = 0.0;
          break;
      }
      break;
    case 3:
      switch (idx){
        case 0: //  e111
          res->e111 = 0.0;
          res->e1111 = 0.0;
          res->e1112 = 0.0;
          res->e1113 = 0.0;
          res->e1114 = 0.0;
          res->e1115 = 0.0;
          break;
        case 1: //  e112
          res->e112 = 0.0;
          res->e1112 = 0.0;
          res->e1122 = 0.0;
          res->e1123 = 0.0;
          res->e1124 = 0.0;
          res->e1125 = 0.0;
          break;
        case 2: //  e122
          res->e122 = 0.0;
          res->e1122 = 0.0;
          res->e1222 = 0.0;
          res->e1223 = 0.0;
          res->e1224 = 0.0;
          res->e1225 = 0.0;
          break;
        case 3: //  e222
          res->e222 = 0.0;
          res->e1222 = 0.0;
          res->e2222 = 0.0;
          res->e2223 = 0.0;
          res->e2224 = 0.0;
          res->e2225 = 0.0;
          break;
        case 4: //  e113
          res->e113 = 0.0;
          res->e1113 = 0.0;
          res->e1123 = 0.0;
          res->e1133 = 0.0;
          res->e1134 = 0.0;
          res->e1135 = 0.0;
          break;
        case 5: //  e123
          res->e123 = 0.0;
          res->e1123 = 0.0;
          res->e1223 = 0.0;
          res->e1233 = 0.0;
          res->e1234 = 0.0;
          res->e1235 = 0.0;
          break;
        case 6: //  e223
          res->e223 = 0.0;
          res->e1223 = 0.0;
          res->e2223 = 0.0;
          res->e2233 = 0.0;
          res->e2234 = 0.0;
          res->e2235 = 0.0;
          break;
        case 7: //  e133
          res->e133 = 0.0;
          res->e1133 = 0.0;
          res->e1233 = 0.0;
          res->e1333 = 0.0;
          res->e1334 = 0.0;
          res->e1335 = 0.0;
          break;
        case 8: //  e233
          res->e233 = 0.0;
          res->e1233 = 0.0;
          res->e2233 = 0.0;
          res->e2333 = 0.0;
          res->e2334 = 0.0;
          res->e2335 = 0.0;
          break;
        case 9: //  e333
          res->e333 = 0.0;
          res->e1333 = 0.0;
          res->e2333 = 0.0;
          res->e3333 = 0.0;
          res->e3334 = 0.0;
          res->e3335 = 0.0;
          break;
        case 10: //  e114
          res->e114 = 0.0;
          res->e1114 = 0.0;
          res->e1124 = 0.0;
          res->e1134 = 0.0;
          res->e1144 = 0.0;
          res->e1145 = 0.0;
          break;
        case 11: //  e124
          res->e124 = 0.0;
          res->e1124 = 0.0;
          res->e1224 = 0.0;
          res->e1234 = 0.0;
          res->e1244 = 0.0;
          res->e1245 = 0.0;
          break;
        case 12: //  e224
          res->e224 = 0.0;
          res->e1224 = 0.0;
          res->e2224 = 0.0;
          res->e2234 = 0.0;
          res->e2244 = 0.0;
          res->e2245 = 0.0;
          break;
        case 13: //  e134
          res->e134 = 0.0;
          res->e1134 = 0.0;
          res->e1234 = 0.0;
          res->e1334 = 0.0;
          res->e1344 = 0.0;
          res->e1345 = 0.0;
          break;
        case 14: //  e234
          res->e234 = 0.0;
          res->e1234 = 0.0;
          res->e2234 = 0.0;
          res->e2334 = 0.0;
          res->e2344 = 0.0;
          res->e2345 = 0.0;
          break;
        case 15: //  e334
          res->e334 = 0.0;
          res->e1334 = 0.0;
          res->e2334 = 0.0;
          res->e3334 = 0.0;
          res->e3344 = 0.0;
          res->e3345 = 0.0;
          break;
        case 16: //  e144
          res->e144 = 0.0;
          res->e1144 = 0.0;
          res->e1244 = 0.0;
          res->e1344 = 0.0;
          res->e1444 = 0.0;
          res->e1445 = 0.0;
          break;
        case 17: //  e244
          res->e244 = 0.0;
          res->e1244 = 0.0;
          res->e2244 = 0.0;
          res->e2344 = 0.0;
          res->e2444 = 0.0;
          res->e2445 = 0.0;
          break;
        case 18: //  e344
          res->e344 = 0.0;
          res->e1344 = 0.0;
          res->e2344 = 0.0;
          res->e3344 = 0.0;
          res->e3444 = 0.0;
          res->e3445 = 0.0;
          break;
        case 19: //  e444
          res->e444 = 0.0;
          res->e1444 = 0.0;
          res->e2444 = 0.0;
          res->e3444 = 0.0;
          res->e4444 = 0.0;
          res->e4445 = 0.0;
          break;
        case 20: //  e115
          res->e115 = 0.0;
          res->e1115 = 0.0;
          res->e1125 = 0.0;
          res->e1135 = 0.0;
          res->e1145 = 0.0;
          res->e1155 = 0.0;
          break;
        case 21: //  e125
          res->e125 = 0.0;
          res->e1125 = 0.0;
          res->e1225 = 0.0;
          res->e1235 = 0.0;
          res->e1245 = 0.0;
          res->e1255 = 0.0;
          break;
        case 22: //  e225
          res->e225 = 0.0;
          res->e1225 = 0.0;
          res->e2225 = 0.0;
          res->e2235 = 0.0;
          res->e2245 = 0.0;
          res->e2255 = 0.0;
          break;
        case 23: //  e135
          res->e135 = 0.0;
          res->e1135 = 0.0;
          res->e1235 = 0.0;
          res->e1335 = 0.0;
          res->e1345 = 0.0;
          res->e1355 = 0.0;
          break;
        case 24: //  e235
          res->e235 = 0.0;
          res->e1235 = 0.0;
          res->e2235 = 0.0;
          res->e2335 = 0.0;
          res->e2345 = 0.0;
          res->e2355 = 0.0;
          break;
        case 25: //  e335
          res->e335 = 0.0;
          res->e1335 = 0.0;
          res->e2335 = 0.0;
          res->e3335 = 0.0;
          res->e3345 = 0.0;
          res->e3355 = 0.0;
          break;
        case 26: //  e145
          res->e145 = 0.0;
          res->e1145 = 0.0;
          res->e1245 = 0.0;
          res->e1345 = 0.0;
          res->e1445 = 0.0;
          res->e1455 = 0.0;
          break;
        case 27: //  e245
          res->e245 = 0.0;
          res->e1245 = 0.0;
          res->e2245 = 0.0;
          res->e2345 = 0.0;
          res->e2445 = 0.0;
          res->e2455 = 0.0;
          break;
        case 28: //  e345
          res->e345 = 0.0;
          res->e1345 = 0.0;
          res->e2345 = 0.0;
          res->e3345 = 0.0;
          res->e3445 = 0.0;
          res->e3455 = 0.0;
          break;
        case 29: //  e445
          res->e445 = 0.0;
          res->e1445 = 0.0;
          res->e2445 = 0.0;
          res->e3445 = 0.0;
          res->e4445 = 0.0;
          res->e4455 = 0.0;
          break;
        case 30: //  e155
          res->e155 = 0.0;
          res->e1155 = 0.0;
          res->e1255 = 0.0;
          res->e1355 = 0.0;
          res->e1455 = 0.0;
          res->e1555 = 0.0;
          break;
        case 31: //  e255
          res->e255 = 0.0;
          res->e1255 = 0.0;
          res->e2255 = 0.0;
          res->e2355 = 0.0;
          res->e2455 = 0.0;
          res->e2555 = 0.0;
          break;
        case 32: //  e355
          res->e355 = 0.0;
          res->e1355 = 0.0;
          res->e2355 = 0.0;
          res->e3355 = 0.0;
          res->e3455 = 0.0;
          res->e3555 = 0.0;
          break;
        case 33: //  e455
          res->e455 = 0.0;
          res->e1455 = 0.0;
          res->e2455 = 0.0;
          res->e3455 = 0.0;
          res->e4455 = 0.0;
          res->e4555 = 0.0;
          break;
        case 34: //  e555
          res->e555 = 0.0;
          res->e1555 = 0.0;
          res->e2555 = 0.0;
          res->e3555 = 0.0;
          res->e4555 = 0.0;
          res->e5555 = 0.0;
          break;
      }
      break;
    case 4:
      switch (idx){
        case 0: //  e1111
          res->e1111 = 0.0;
          break;
        case 1: //  e1112
          res->e1112 = 0.0;
          break;
        case 2: //  e1122
          res->e1122 = 0.0;
          break;
        case 3: //  e1222
          res->e1222 = 0.0;
          break;
        case 4: //  e2222
          res->e2222 = 0.0;
          break;
        case 5: //  e1113
          res->e1113 = 0.0;
          break;
        case 6: //  e1123
          res->e1123 = 0.0;
          break;
        case 7: //  e1223
          res->e1223 = 0.0;
          break;
        case 8: //  e2223
          res->e2223 = 0.0;
          break;
        case 9: //  e1133
          res->e1133 = 0.0;
          break;
        case 10: //  e1233
          res->e1233 = 0.0;
          break;
        case 11: //  e2233
          res->e2233 = 0.0;
          break;
        case 12: //  e1333
          res->e1333 = 0.0;
          break;
        case 13: //  e2333
          res->e2333 = 0.0;
          break;
        case 14: //  e3333
          res->e3333 = 0.0;
          break;
        case 15: //  e1114
          res->e1114 = 0.0;
          break;
        case 16: //  e1124
          res->e1124 = 0.0;
          break;
        case 17: //  e1224
          res->e1224 = 0.0;
          break;
        case 18: //  e2224
          res->e2224 = 0.0;
          break;
        case 19: //  e1134
          res->e1134 = 0.0;
          break;
        case 20: //  e1234
          res->e1234 = 0.0;
          break;
        case 21: //  e2234
          res->e2234 = 0.0;
          break;
        case 22: //  e1334
          res->e1334 = 0.0;
          break;
        case 23: //  e2334
          res->e2334 = 0.0;
          break;
        case 24: //  e3334
          res->e3334 = 0.0;
          break;
        case 25: //  e1144
          res->e1144 = 0.0;
          break;
        case 26: //  e1244
          res->e1244 = 0.0;
          break;
        case 27: //  e2244
          res->e2244 = 0.0;
          break;
        case 28: //  e1344
          res->e1344 = 0.0;
          break;
        case 29: //  e2344
          res->e2344 = 0.0;
          break;
        case 30: //  e3344
          res->e3344 = 0.0;
          break;
        case 31: //  e1444
          res->e1444 = 0.0;
          break;
        case 32: //  e2444
          res->e2444 = 0.0;
          break;
        case 33: //  e3444
          res->e3444 = 0.0;
          break;
        case 34: //  e4444
          res->e4444 = 0.0;
          break;
        case 35: //  e1115
          res->e1115 = 0.0;
          break;
        case 36: //  e1125
          res->e1125 = 0.0;
          break;
        case 37: //  e1225
          res->e1225 = 0.0;
          break;
        case 38: //  e2225
          res->e2225 = 0.0;
          break;
        case 39: //  e1135
          res->e1135 = 0.0;
          break;
        case 40: //  e1235
          res->e1235 = 0.0;
          break;
        case 41: //  e2235
          res->e2235 = 0.0;
          break;
        case 42: //  e1335
          res->e1335 = 0.0;
          break;
        case 43: //  e2335
          res->e2335 = 0.0;
          break;
        case 44: //  e3335
          res->e3335 = 0.0;
          break;
        case 45: //  e1145
          res->e1145 = 0.0;
          break;
        case 46: //  e1245
          res->e1245 = 0.0;
          break;
        case 47: //  e2245
          res->e2245 = 0.0;
          break;
        case 48: //  e1345
          res->e1345 = 0.0;
          break;
        case 49: //  e2345
          res->e2345 = 0.0;
          break;
        case 50: //  e3345
          res->e3345 = 0.0;
          break;
        case 51: //  e1445
          res->e1445 = 0.0;
          break;
        case 52: //  e2445
          res->e2445 = 0.0;
          break;
        case 53: //  e3445
          res->e3445 = 0.0;
          break;
        case 54: //  e4445
          res->e4445 = 0.0;
          break;
        case 55: //  e1155
          res->e1155 = 0.0;
          break;
        case 56: //  e1255
          res->e1255 = 0.0;
          break;
        case 57: //  e2255
          res->e2255 = 0.0;
          break;
        case 58: //  e1355
          res->e1355 = 0.0;
          break;
        case 59: //  e2355
          res->e2355 = 0.0;
          break;
        case 60: //  e3355
          res->e3355 = 0.0;
          break;
        case 61: //  e1455
          res->e1455 = 0.0;
          break;
        case 62: //  e2455
          res->e2455 = 0.0;
          break;
        case 63: //  e3455
          res->e3455 = 0.0;
          break;
        case 64: //  e4455
          res->e4455 = 0.0;
          break;
        case 65: //  e1555
          res->e1555 = 0.0;
          break;
        case 66: //  e2555
          res->e2555 = 0.0;
          break;
        case 67: //  e3555
          res->e3555 = 0.0;
          break;
        case 68: //  e4555
          res->e4555 = 0.0;
          break;
        case 69: //  e5555
          res->e5555 = 0.0;
          break;
      }
      break;
  }
}

void onumm5n4_print(  onumm5n4_t* lhs){

  // Print function.
  //  Real;
  printf("%.8g",lhs->r);
  //  Order 1;
  printf(" %+.8g*e1",lhs->e1);
  printf(" %+.8g*e2",lhs->e2);
  printf(" %+.8g*e3",lhs->e3);
  printf(" %+.8g*e4",lhs->e4);
  printf(" %+.8g*e5",lhs->e5);
  //  Order 2;
  printf(" %+.8g*e11",lhs->e11);
  printf(" %+.8g*e12",lhs->e12);
  printf(" %+.8g*e22",lhs->e22);
  printf(" %+.8g*e13",lhs->e13);
  printf(" %+.8g*e23",lhs->e23);
  printf(" %+.8g*e33",lhs->e33);
  printf(" %+.8g*e14",lhs->e14);
  printf(" %+.8g*e24",lhs->e24);
  printf(" %+.8g*e34",lhs->e34);
  printf(" %+.8g*e44",lhs->e44);
  printf(" %+.8g*e15",lhs->e15);
  printf(" %+.8g*e25",lhs->e25);
  printf(" %+.8g*e35",lhs->e35);
  printf(" %+.8g*e45",lhs->e45);
  printf(" %+.8g*e55",lhs->e55);
  //  Order 3;
  printf(" %+.8g*e111",lhs->e111);
  printf(" %+.8g*e112",lhs->e112);
  printf(" %+.8g*e122",lhs->e122);
  printf(" %+.8g*e222",lhs->e222);
  printf(" %+.8g*e113",lhs->e113);
  printf(" %+.8g*e123",lhs->e123);
  printf(" %+.8g*e223",lhs->e223);
  printf(" %+.8g*e133",lhs->e133);
  printf(" %+.8g*e233",lhs->e233);
  printf(" %+.8g*e333",lhs->e333);
  printf(" %+.8g*e114",lhs->e114);
  printf(" %+.8g*e124",lhs->e124);
  printf(" %+.8g*e224",lhs->e224);
  printf(" %+.8g*e134",lhs->e134);
  printf(" %+.8g*e234",lhs->e234);
  printf(" %+.8g*e334",lhs->e334);
  printf(" %+.8g*e144",lhs->e144);
  printf(" %+.8g*e244",lhs->e244);
  printf(" %+.8g*e344",lhs->e344);
  printf(" %+.8g*e444",lhs->e444);
  printf(" %+.8g*e115",lhs->e115);
  printf(" %+.8g*e125",lhs->e125);
  printf(" %+.8g*e225",lhs->e225);
  printf(" %+.8g*e135",lhs->e135);
  printf(" %+.8g*e235",lhs->e235);
  printf(" %+.8g*e335",lhs->e335);
  printf(" %+.8g*e145",lhs->e145);
  printf(" %+.8g*e245",lhs->e245);
  printf(" %+.8g*e345",lhs->e345);
  printf(" %+.8g*e445",lhs->e445);
  printf(" %+.8g*e155",lhs->e155);
  printf(" %+.8g*e255",lhs->e255);
  printf(" %+.8g*e355",lhs->e355);
  printf(" %+.8g*e455",lhs->e455);
  printf(" %+.8g*e555",lhs->e555);
  //  Order 4;
  printf(" %+.8g*e1111",lhs->e1111);
  printf(" %+.8g*e1112",lhs->e1112);
  printf(" %+.8g*e1122",lhs->e1122);
  printf(" %+.8g*e1222",lhs->e1222);
  printf(" %+.8g*e2222",lhs->e2222);
  printf(" %+.8g*e1113",lhs->e1113);
  printf(" %+.8g*e1123",lhs->e1123);
  printf(" %+.8g*e1223",lhs->e1223);
  printf(" %+.8g*e2223",lhs->e2223);
  printf(" %+.8g*e1133",lhs->e1133);
  printf(" %+.8g*e1233",lhs->e1233);
  printf(" %+.8g*e2233",lhs->e2233);
  printf(" %+.8g*e1333",lhs->e1333);
  printf(" %+.8g*e2333",lhs->e2333);
  printf(" %+.8g*e3333",lhs->e3333);
  printf(" %+.8g*e1114",lhs->e1114);
  printf(" %+.8g*e1124",lhs->e1124);
  printf(" %+.8g*e1224",lhs->e1224);
  printf(" %+.8g*e2224",lhs->e2224);
  printf(" %+.8g*e1134",lhs->e1134);
  printf(" %+.8g*e1234",lhs->e1234);
  printf(" %+.8g*e2234",lhs->e2234);
  printf(" %+.8g*e1334",lhs->e1334);
  printf(" %+.8g*e2334",lhs->e2334);
  printf(" %+.8g*e3334",lhs->e3334);
  printf(" %+.8g*e1144",lhs->e1144);
  printf(" %+.8g*e1244",lhs->e1244);
  printf(" %+.8g*e2244",lhs->e2244);
  printf(" %+.8g*e1344",lhs->e1344);
  printf(" %+.8g*e2344",lhs->e2344);
  printf(" %+.8g*e3344",lhs->e3344);
  printf(" %+.8g*e1444",lhs->e1444);
  printf(" %+.8g*e2444",lhs->e2444);
  printf(" %+.8g*e3444",lhs->e3444);
  printf(" %+.8g*e4444",lhs->e4444);
  printf(" %+.8g*e1115",lhs->e1115);
  printf(" %+.8g*e1125",lhs->e1125);
  printf(" %+.8g*e1225",lhs->e1225);
  printf(" %+.8g*e2225",lhs->e2225);
  printf(" %+.8g*e1135",lhs->e1135);
  printf(" %+.8g*e1235",lhs->e1235);
  printf(" %+.8g*e2235",lhs->e2235);
  printf(" %+.8g*e1335",lhs->e1335);
  printf(" %+.8g*e2335",lhs->e2335);
  printf(" %+.8g*e3335",lhs->e3335);
  printf(" %+.8g*e1145",lhs->e1145);
  printf(" %+.8g*e1245",lhs->e1245);
  printf(" %+.8g*e2245",lhs->e2245);
  printf(" %+.8g*e1345",lhs->e1345);
  printf(" %+.8g*e2345",lhs->e2345);
  printf(" %+.8g*e3345",lhs->e3345);
  printf(" %+.8g*e1445",lhs->e1445);
  printf(" %+.8g*e2445",lhs->e2445);
  printf(" %+.8g*e3445",lhs->e3445);
  printf(" %+.8g*e4445",lhs->e4445);
  printf(" %+.8g*e1155",lhs->e1155);
  printf(" %+.8g*e1255",lhs->e1255);
  printf(" %+.8g*e2255",lhs->e2255);
  printf(" %+.8g*e1355",lhs->e1355);
  printf(" %+.8g*e2355",lhs->e2355);
  printf(" %+.8g*e3355",lhs->e3355);
  printf(" %+.8g*e1455",lhs->e1455);
  printf(" %+.8g*e2455",lhs->e2455);
  printf(" %+.8g*e3455",lhs->e3455);
  printf(" %+.8g*e4455",lhs->e4455);
  printf(" %+.8g*e1555",lhs->e1555);
  printf(" %+.8g*e2555",lhs->e2555);
  printf(" %+.8g*e3555",lhs->e3555);
  printf(" %+.8g*e4555",lhs->e4555);
  printf(" %+.8g*e5555",lhs->e5555);
  printf("\n");

}

imdir_t onumm5n4_get_indx(imdir_t idx, ord_t order){

  // Real;
  switch (order){
    case 0:
      return 0;
      break;
    case 1:
      switch (idx){
        case 0:
          return 0;
          break;
        case 1:
          return 1;
          break;
        case 2:
          return 2;
          break;
        case 3:
          return 3;
          break;
        case 4:
          return 4;
          break;
      }
      break;
    case 2:
      switch (idx){
        case 0:
          return 0;
          break;
        case 1:
          return 1;
          break;
        case 2:
          return 2;
          break;
        case 3:
          return 3;
          break;
        case 4:
          return 4;
          break;
        case 5:
          return 5;
          break;
        case 6:
          return 6;
          break;
        case 7:
          return 7;
          break;
        case 8:
          return 8;
          break;
        case 9:
          return 9;
          break;
        case 10:
          return 10;
          break;
        case 11:
          return 11;
          break;
        case 12:
          return 12;
          break;
        case 13:
          return 13;
          break;
        case 14:
          return 14;
          break;
      }
      break;
    case 3:
      switch (idx){
        case 0:
          return 0;
          break;
        case 1:
          return 1;
          break;
        case 2:
          return 2;
          break;
        case 3:
          return 3;
          break;
        case 4:
          return 4;
          break;
        case 5:
          return 5;
          break;
        case 6:
          return 6;
          break;
        case 7:
          return 7;
          break;
        case 8:
          return 8;
          break;
        case 9:
          return 9;
          break;
        case 10:
          return 10;
          break;
        case 11:
          return 11;
          break;
        case 12:
          return 12;
          break;
        case 13:
          return 13;
          break;
        case 14:
          return 14;
          break;
        case 15:
          return 15;
          break;
        case 16:
          return 16;
          break;
        case 17:
          return 17;
          break;
        case 18:
          return 18;
          break;
        case 19:
          return 19;
          break;
        case 20:
          return 20;
          break;
        case 21:
          return 21;
          break;
        case 22:
          return 22;
          break;
        case 23:
          return 23;
          break;
        case 24:
          return 24;
          break;
        case 25:
          return 25;
          break;
        case 26:
          return 26;
          break;
        case 27:
          return 27;
          break;
        case 28:
          return 28;
          break;
        case 29:
          return 29;
          break;
        case 30:
          return 30;
          break;
        case 31:
          return 31;
          break;
        case 32:
          return 32;
          break;
        case 33:
          return 33;
          break;
        case 34:
          return 34;
          break;
      }
      break;
    case 4:
      switch (idx){
        case 0:
          return 0;
          break;
        case 1:
          return 1;
          break;
        case 2:
          return 2;
          break;
        case 3:
          return 3;
          break;
        case 4:
          return 4;
          break;
        case 5:
          return 5;
          break;
        case 6:
          return 6;
          break;
        case 7:
          return 7;
          break;
        case 8:
          return 8;
          break;
        case 9:
          return 9;
          break;
        case 10:
          return 10;
          break;
        case 11:
          return 11;
          break;
        case 12:
          return 12;
          break;
        case 13:
          return 13;
          break;
        case 14:
          return 14;
          break;
        case 15:
          return 15;
          break;
        case 16:
          return 16;
          break;
        case 17:
          return 17;
          break;
        case 18:
          return 18;
          break;
        case 19:
          return 19;
          break;
        case 20:
          return 20;
          break;
        case 21:
          return 21;
          break;
        case 22:
          return 22;
          break;
        case 23:
          return 23;
          break;
        case 24:
          return 24;
          break;
        case 25:
          return 25;
          break;
        case 26:
          return 26;
          break;
        case 27:
          return 27;
          break;
        case 28:
          return 28;
          break;
        case 29:
          return 29;
          break;
        case 30:
          return 30;
          break;
        case 31:
          return 31;
          break;
        case 32:
          return 32;
          break;
        case 33:
          return 33;
          break;
        case 34:
          return 34;
          break;
        case 35:
          return 35;
          break;
        case 36:
          return 36;
          break;
        case 37:
          return 37;
          break;
        case 38:
          return 38;
          break;
        case 39:
          return 39;
          break;
        case 40:
          return 40;
          break;
        case 41:
          return 41;
          break;
        case 42:
          return 42;
          break;
        case 43:
          return 43;
          break;
        case 44:
          return 44;
          break;
        case 45:
          return 45;
          break;
        case 46:
          return 46;
          break;
        case 47:
          return 47;
          break;
        case 48:
          return 48;
          break;
        case 49:
          return 49;
          break;
        case 50:
          return 50;
          break;
        case 51:
          return 51;
          break;
        case 52:
          return 52;
          break;
        case 53:
          return 53;
          break;
        case 54:
          return 54;
          break;
        case 55:
          return 55;
          break;
        case 56:
          return 56;
          break;
        case 57:
          return 57;
          break;
        case 58:
          return 58;
          break;
        case 59:
          return 59;
          break;
        case 60:
          return 60;
          break;
        case 61:
          return 61;
          break;
        case 62:
          return 62;
          break;
        case 63:
          return 63;
          break;
        case 64:
          return 64;
          break;
        case 65:
          return 65;
          break;
        case 66:
          return 66;
          break;
        case 67:
          return 67;
          break;
        case 68:
          return 68;
          break;
        case 69:
          return 69;
          break;
      }
      break;
      default:
          return 0;
  }
  return 0;
}

