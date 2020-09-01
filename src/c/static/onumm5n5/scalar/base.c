

// Not implemented correctly:
void onumm5n5_set_im_o(onumm5n5_t* num, imdir_t idx, ord_t order, onumm5n5_t* res){
    onumm5n5_set_item(num->r,idx,order,res);
}
void onumm5n5_set_deriv_r(coeff_t num, imdir_t idx, ord_t order, onumm5n5_t* res){
    *res=onumm5n5_init();
}
void onumm5n5_set_deriv_o(onumm5n5_t* num, imdir_t idx, ord_t order, onumm5n5_t* res){
    *res=onumm5n5_init();
}
void onumm5n5_extract_im_to( imdir_t idx, ord_t order, onumm5n5_t* num, onumm5n5_t* res){
    *res=onumm5n5_init();
}
onumm5n5_t onumm5n5_extract_im(imdir_t idx, ord_t order, onumm5n5_t* num){
    onumm5n5_t res = onumm5n5_init();
    return res;
}
onumm5n5_t onumm5n5_extract_deriv(imdir_t idx, ord_t order, onumm5n5_t* num){
    onumm5n5_t res = onumm5n5_init();
    return res;
}
void onumm5n5_extract_deriv_to(imdir_t idx, ord_t order, onumm5n5_t* num, onumm5n5_t* res){
	*res = onumm5n5_init();
}
void onumm5n5_get_im_to_o(imdir_t idx, ord_t order, onumm5n5_t* num, onumm5n5_t* res){
    coeff_t rres = onumm5n5_get_item(idx, order, num);
    onumm5n5_set_r(rres,res);
}
onumm5n5_t onumm5n5_get_im_o(imdir_t idx, ord_t order, onumm5n5_t* num){
    coeff_t rres = onumm5n5_get_item(idx, order, num);
    onumm5n5_t res;
    onumm5n5_set_r(rres,&res);
    return res;
}
void onumm5n5_get_im_to_r(imdir_t idx, ord_t order, onumm5n5_t* num, coeff_t* res){
    *res = onumm5n5_get_item(idx, order, num);
}

inline ord_t onumm5n5_get_order(onumm5n5_t* lhs){

	return 5;

}

onumm5n5_t onumm5n5_get_deriv_o( imdir_t idx, ord_t order, onumm5n5_t* num){

    onumm5n5_t res = onumm5n5_init();

    onumm5n5_get_deriv_to( idx, order, num, &res);
    
    return res;

}

void onumm5n5_get_deriv_to( imdir_t idx, ord_t order, onumm5n5_t* num, onumm5n5_t* res){

    coeff_t deriv = onumm5n5_get_deriv(idx,order,num);

    onumm5n5_set_r( deriv, res);

}

void onumm5n5_set_im_r(coeff_t num, imdir_t idx, ord_t order, onumm5n5_t* res){

    onumm5n5_set_item(num, idx,order,res);

}

onumm5n5_t onumm5n5_init(void){

  onumm5n5_t res;

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
  // Order 5;
  res.e11111 = 0.0;
  res.e11112 = 0.0;
  res.e11122 = 0.0;
  res.e11222 = 0.0;
  res.e12222 = 0.0;
  res.e22222 = 0.0;
  res.e11113 = 0.0;
  res.e11123 = 0.0;
  res.e11223 = 0.0;
  res.e12223 = 0.0;
  res.e22223 = 0.0;
  res.e11133 = 0.0;
  res.e11233 = 0.0;
  res.e12233 = 0.0;
  res.e22233 = 0.0;
  res.e11333 = 0.0;
  res.e12333 = 0.0;
  res.e22333 = 0.0;
  res.e13333 = 0.0;
  res.e23333 = 0.0;
  res.e33333 = 0.0;
  res.e11114 = 0.0;
  res.e11124 = 0.0;
  res.e11224 = 0.0;
  res.e12224 = 0.0;
  res.e22224 = 0.0;
  res.e11134 = 0.0;
  res.e11234 = 0.0;
  res.e12234 = 0.0;
  res.e22234 = 0.0;
  res.e11334 = 0.0;
  res.e12334 = 0.0;
  res.e22334 = 0.0;
  res.e13334 = 0.0;
  res.e23334 = 0.0;
  res.e33334 = 0.0;
  res.e11144 = 0.0;
  res.e11244 = 0.0;
  res.e12244 = 0.0;
  res.e22244 = 0.0;
  res.e11344 = 0.0;
  res.e12344 = 0.0;
  res.e22344 = 0.0;
  res.e13344 = 0.0;
  res.e23344 = 0.0;
  res.e33344 = 0.0;
  res.e11444 = 0.0;
  res.e12444 = 0.0;
  res.e22444 = 0.0;
  res.e13444 = 0.0;
  res.e23444 = 0.0;
  res.e33444 = 0.0;
  res.e14444 = 0.0;
  res.e24444 = 0.0;
  res.e34444 = 0.0;
  res.e44444 = 0.0;
  res.e11115 = 0.0;
  res.e11125 = 0.0;
  res.e11225 = 0.0;
  res.e12225 = 0.0;
  res.e22225 = 0.0;
  res.e11135 = 0.0;
  res.e11235 = 0.0;
  res.e12235 = 0.0;
  res.e22235 = 0.0;
  res.e11335 = 0.0;
  res.e12335 = 0.0;
  res.e22335 = 0.0;
  res.e13335 = 0.0;
  res.e23335 = 0.0;
  res.e33335 = 0.0;
  res.e11145 = 0.0;
  res.e11245 = 0.0;
  res.e12245 = 0.0;
  res.e22245 = 0.0;
  res.e11345 = 0.0;
  res.e12345 = 0.0;
  res.e22345 = 0.0;
  res.e13345 = 0.0;
  res.e23345 = 0.0;
  res.e33345 = 0.0;
  res.e11445 = 0.0;
  res.e12445 = 0.0;
  res.e22445 = 0.0;
  res.e13445 = 0.0;
  res.e23445 = 0.0;
  res.e33445 = 0.0;
  res.e14445 = 0.0;
  res.e24445 = 0.0;
  res.e34445 = 0.0;
  res.e44445 = 0.0;
  res.e11155 = 0.0;
  res.e11255 = 0.0;
  res.e12255 = 0.0;
  res.e22255 = 0.0;
  res.e11355 = 0.0;
  res.e12355 = 0.0;
  res.e22355 = 0.0;
  res.e13355 = 0.0;
  res.e23355 = 0.0;
  res.e33355 = 0.0;
  res.e11455 = 0.0;
  res.e12455 = 0.0;
  res.e22455 = 0.0;
  res.e13455 = 0.0;
  res.e23455 = 0.0;
  res.e33455 = 0.0;
  res.e14455 = 0.0;
  res.e24455 = 0.0;
  res.e34455 = 0.0;
  res.e44455 = 0.0;
  res.e11555 = 0.0;
  res.e12555 = 0.0;
  res.e22555 = 0.0;
  res.e13555 = 0.0;
  res.e23555 = 0.0;
  res.e33555 = 0.0;
  res.e14555 = 0.0;
  res.e24555 = 0.0;
  res.e34555 = 0.0;
  res.e44555 = 0.0;
  res.e15555 = 0.0;
  res.e25555 = 0.0;
  res.e35555 = 0.0;
  res.e45555 = 0.0;
  res.e55555 = 0.0;

  return res;

}

ndir_t onumm5n5_get_ndir_order(ord_t order, onumm5n5_t* num){

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
    case 5:
      res = 126;
      break;
  }

  return res;

}

ndir_t onumm5n5_get_ndir_total(onumm5n5_t* num){

  ndir_t res;

  res = 126;

  return res;

}

coeff_t* onumm5n5_get_order_address(ord_t order, onumm5n5_t* num){

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
    case 5:
      res = &num->e11111;
      break;
  }
  return res;

}

onumm5n5_t onumm5n5_create_r(  coeff_t lhs){

  onumm5n5_t res;

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
  // Order 5;
  res.e11111 = 0.0;
  res.e11112 = 0.0;
  res.e11122 = 0.0;
  res.e11222 = 0.0;
  res.e12222 = 0.0;
  res.e22222 = 0.0;
  res.e11113 = 0.0;
  res.e11123 = 0.0;
  res.e11223 = 0.0;
  res.e12223 = 0.0;
  res.e22223 = 0.0;
  res.e11133 = 0.0;
  res.e11233 = 0.0;
  res.e12233 = 0.0;
  res.e22233 = 0.0;
  res.e11333 = 0.0;
  res.e12333 = 0.0;
  res.e22333 = 0.0;
  res.e13333 = 0.0;
  res.e23333 = 0.0;
  res.e33333 = 0.0;
  res.e11114 = 0.0;
  res.e11124 = 0.0;
  res.e11224 = 0.0;
  res.e12224 = 0.0;
  res.e22224 = 0.0;
  res.e11134 = 0.0;
  res.e11234 = 0.0;
  res.e12234 = 0.0;
  res.e22234 = 0.0;
  res.e11334 = 0.0;
  res.e12334 = 0.0;
  res.e22334 = 0.0;
  res.e13334 = 0.0;
  res.e23334 = 0.0;
  res.e33334 = 0.0;
  res.e11144 = 0.0;
  res.e11244 = 0.0;
  res.e12244 = 0.0;
  res.e22244 = 0.0;
  res.e11344 = 0.0;
  res.e12344 = 0.0;
  res.e22344 = 0.0;
  res.e13344 = 0.0;
  res.e23344 = 0.0;
  res.e33344 = 0.0;
  res.e11444 = 0.0;
  res.e12444 = 0.0;
  res.e22444 = 0.0;
  res.e13444 = 0.0;
  res.e23444 = 0.0;
  res.e33444 = 0.0;
  res.e14444 = 0.0;
  res.e24444 = 0.0;
  res.e34444 = 0.0;
  res.e44444 = 0.0;
  res.e11115 = 0.0;
  res.e11125 = 0.0;
  res.e11225 = 0.0;
  res.e12225 = 0.0;
  res.e22225 = 0.0;
  res.e11135 = 0.0;
  res.e11235 = 0.0;
  res.e12235 = 0.0;
  res.e22235 = 0.0;
  res.e11335 = 0.0;
  res.e12335 = 0.0;
  res.e22335 = 0.0;
  res.e13335 = 0.0;
  res.e23335 = 0.0;
  res.e33335 = 0.0;
  res.e11145 = 0.0;
  res.e11245 = 0.0;
  res.e12245 = 0.0;
  res.e22245 = 0.0;
  res.e11345 = 0.0;
  res.e12345 = 0.0;
  res.e22345 = 0.0;
  res.e13345 = 0.0;
  res.e23345 = 0.0;
  res.e33345 = 0.0;
  res.e11445 = 0.0;
  res.e12445 = 0.0;
  res.e22445 = 0.0;
  res.e13445 = 0.0;
  res.e23445 = 0.0;
  res.e33445 = 0.0;
  res.e14445 = 0.0;
  res.e24445 = 0.0;
  res.e34445 = 0.0;
  res.e44445 = 0.0;
  res.e11155 = 0.0;
  res.e11255 = 0.0;
  res.e12255 = 0.0;
  res.e22255 = 0.0;
  res.e11355 = 0.0;
  res.e12355 = 0.0;
  res.e22355 = 0.0;
  res.e13355 = 0.0;
  res.e23355 = 0.0;
  res.e33355 = 0.0;
  res.e11455 = 0.0;
  res.e12455 = 0.0;
  res.e22455 = 0.0;
  res.e13455 = 0.0;
  res.e23455 = 0.0;
  res.e33455 = 0.0;
  res.e14455 = 0.0;
  res.e24455 = 0.0;
  res.e34455 = 0.0;
  res.e44455 = 0.0;
  res.e11555 = 0.0;
  res.e12555 = 0.0;
  res.e22555 = 0.0;
  res.e13555 = 0.0;
  res.e23555 = 0.0;
  res.e33555 = 0.0;
  res.e14555 = 0.0;
  res.e24555 = 0.0;
  res.e34555 = 0.0;
  res.e44555 = 0.0;
  res.e15555 = 0.0;
  res.e25555 = 0.0;
  res.e35555 = 0.0;
  res.e45555 = 0.0;
  res.e55555 = 0.0;

  return res;

}

void onumm5n5_set_r(  coeff_t lhs, onumm5n5_t* res){

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
  // Order 5;
  res->e11111 = 0.0;
  res->e11112 = 0.0;
  res->e11122 = 0.0;
  res->e11222 = 0.0;
  res->e12222 = 0.0;
  res->e22222 = 0.0;
  res->e11113 = 0.0;
  res->e11123 = 0.0;
  res->e11223 = 0.0;
  res->e12223 = 0.0;
  res->e22223 = 0.0;
  res->e11133 = 0.0;
  res->e11233 = 0.0;
  res->e12233 = 0.0;
  res->e22233 = 0.0;
  res->e11333 = 0.0;
  res->e12333 = 0.0;
  res->e22333 = 0.0;
  res->e13333 = 0.0;
  res->e23333 = 0.0;
  res->e33333 = 0.0;
  res->e11114 = 0.0;
  res->e11124 = 0.0;
  res->e11224 = 0.0;
  res->e12224 = 0.0;
  res->e22224 = 0.0;
  res->e11134 = 0.0;
  res->e11234 = 0.0;
  res->e12234 = 0.0;
  res->e22234 = 0.0;
  res->e11334 = 0.0;
  res->e12334 = 0.0;
  res->e22334 = 0.0;
  res->e13334 = 0.0;
  res->e23334 = 0.0;
  res->e33334 = 0.0;
  res->e11144 = 0.0;
  res->e11244 = 0.0;
  res->e12244 = 0.0;
  res->e22244 = 0.0;
  res->e11344 = 0.0;
  res->e12344 = 0.0;
  res->e22344 = 0.0;
  res->e13344 = 0.0;
  res->e23344 = 0.0;
  res->e33344 = 0.0;
  res->e11444 = 0.0;
  res->e12444 = 0.0;
  res->e22444 = 0.0;
  res->e13444 = 0.0;
  res->e23444 = 0.0;
  res->e33444 = 0.0;
  res->e14444 = 0.0;
  res->e24444 = 0.0;
  res->e34444 = 0.0;
  res->e44444 = 0.0;
  res->e11115 = 0.0;
  res->e11125 = 0.0;
  res->e11225 = 0.0;
  res->e12225 = 0.0;
  res->e22225 = 0.0;
  res->e11135 = 0.0;
  res->e11235 = 0.0;
  res->e12235 = 0.0;
  res->e22235 = 0.0;
  res->e11335 = 0.0;
  res->e12335 = 0.0;
  res->e22335 = 0.0;
  res->e13335 = 0.0;
  res->e23335 = 0.0;
  res->e33335 = 0.0;
  res->e11145 = 0.0;
  res->e11245 = 0.0;
  res->e12245 = 0.0;
  res->e22245 = 0.0;
  res->e11345 = 0.0;
  res->e12345 = 0.0;
  res->e22345 = 0.0;
  res->e13345 = 0.0;
  res->e23345 = 0.0;
  res->e33345 = 0.0;
  res->e11445 = 0.0;
  res->e12445 = 0.0;
  res->e22445 = 0.0;
  res->e13445 = 0.0;
  res->e23445 = 0.0;
  res->e33445 = 0.0;
  res->e14445 = 0.0;
  res->e24445 = 0.0;
  res->e34445 = 0.0;
  res->e44445 = 0.0;
  res->e11155 = 0.0;
  res->e11255 = 0.0;
  res->e12255 = 0.0;
  res->e22255 = 0.0;
  res->e11355 = 0.0;
  res->e12355 = 0.0;
  res->e22355 = 0.0;
  res->e13355 = 0.0;
  res->e23355 = 0.0;
  res->e33355 = 0.0;
  res->e11455 = 0.0;
  res->e12455 = 0.0;
  res->e22455 = 0.0;
  res->e13455 = 0.0;
  res->e23455 = 0.0;
  res->e33455 = 0.0;
  res->e14455 = 0.0;
  res->e24455 = 0.0;
  res->e34455 = 0.0;
  res->e44455 = 0.0;
  res->e11555 = 0.0;
  res->e12555 = 0.0;
  res->e22555 = 0.0;
  res->e13555 = 0.0;
  res->e23555 = 0.0;
  res->e33555 = 0.0;
  res->e14555 = 0.0;
  res->e24555 = 0.0;
  res->e34555 = 0.0;
  res->e44555 = 0.0;
  res->e15555 = 0.0;
  res->e25555 = 0.0;
  res->e35555 = 0.0;
  res->e45555 = 0.0;
  res->e55555 = 0.0;

}

void onumm5n5_set_o(  onumm5n5_t* lhs, onumm5n5_t* res){

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

onumm5n5_t onumm5n5_get_order_im(ord_t order, onumm5n5_t* lhs){

  onumm5n5_t res;

  res = onumm5n5_init();
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
    case 5:
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
      break;
  }

  return res;

}

void onumm5n5_get_order_im_to(ord_t order, onumm5n5_t* lhs, onumm5n5_t* res){


  *res = onumm5n5_init();
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
    case 5:
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
      break;
  }

}

coeff_t onumm5n5_get_item(imdir_t idx, ord_t order, onumm5n5_t* lhs){

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
    case 5:
      switch (idx){
        case 0:
          res = lhs->e11111;
          break;
        case 1:
          res = lhs->e11112;
          break;
        case 2:
          res = lhs->e11122;
          break;
        case 3:
          res = lhs->e11222;
          break;
        case 4:
          res = lhs->e12222;
          break;
        case 5:
          res = lhs->e22222;
          break;
        case 6:
          res = lhs->e11113;
          break;
        case 7:
          res = lhs->e11123;
          break;
        case 8:
          res = lhs->e11223;
          break;
        case 9:
          res = lhs->e12223;
          break;
        case 10:
          res = lhs->e22223;
          break;
        case 11:
          res = lhs->e11133;
          break;
        case 12:
          res = lhs->e11233;
          break;
        case 13:
          res = lhs->e12233;
          break;
        case 14:
          res = lhs->e22233;
          break;
        case 15:
          res = lhs->e11333;
          break;
        case 16:
          res = lhs->e12333;
          break;
        case 17:
          res = lhs->e22333;
          break;
        case 18:
          res = lhs->e13333;
          break;
        case 19:
          res = lhs->e23333;
          break;
        case 20:
          res = lhs->e33333;
          break;
        case 21:
          res = lhs->e11114;
          break;
        case 22:
          res = lhs->e11124;
          break;
        case 23:
          res = lhs->e11224;
          break;
        case 24:
          res = lhs->e12224;
          break;
        case 25:
          res = lhs->e22224;
          break;
        case 26:
          res = lhs->e11134;
          break;
        case 27:
          res = lhs->e11234;
          break;
        case 28:
          res = lhs->e12234;
          break;
        case 29:
          res = lhs->e22234;
          break;
        case 30:
          res = lhs->e11334;
          break;
        case 31:
          res = lhs->e12334;
          break;
        case 32:
          res = lhs->e22334;
          break;
        case 33:
          res = lhs->e13334;
          break;
        case 34:
          res = lhs->e23334;
          break;
        case 35:
          res = lhs->e33334;
          break;
        case 36:
          res = lhs->e11144;
          break;
        case 37:
          res = lhs->e11244;
          break;
        case 38:
          res = lhs->e12244;
          break;
        case 39:
          res = lhs->e22244;
          break;
        case 40:
          res = lhs->e11344;
          break;
        case 41:
          res = lhs->e12344;
          break;
        case 42:
          res = lhs->e22344;
          break;
        case 43:
          res = lhs->e13344;
          break;
        case 44:
          res = lhs->e23344;
          break;
        case 45:
          res = lhs->e33344;
          break;
        case 46:
          res = lhs->e11444;
          break;
        case 47:
          res = lhs->e12444;
          break;
        case 48:
          res = lhs->e22444;
          break;
        case 49:
          res = lhs->e13444;
          break;
        case 50:
          res = lhs->e23444;
          break;
        case 51:
          res = lhs->e33444;
          break;
        case 52:
          res = lhs->e14444;
          break;
        case 53:
          res = lhs->e24444;
          break;
        case 54:
          res = lhs->e34444;
          break;
        case 55:
          res = lhs->e44444;
          break;
        case 56:
          res = lhs->e11115;
          break;
        case 57:
          res = lhs->e11125;
          break;
        case 58:
          res = lhs->e11225;
          break;
        case 59:
          res = lhs->e12225;
          break;
        case 60:
          res = lhs->e22225;
          break;
        case 61:
          res = lhs->e11135;
          break;
        case 62:
          res = lhs->e11235;
          break;
        case 63:
          res = lhs->e12235;
          break;
        case 64:
          res = lhs->e22235;
          break;
        case 65:
          res = lhs->e11335;
          break;
        case 66:
          res = lhs->e12335;
          break;
        case 67:
          res = lhs->e22335;
          break;
        case 68:
          res = lhs->e13335;
          break;
        case 69:
          res = lhs->e23335;
          break;
        case 70:
          res = lhs->e33335;
          break;
        case 71:
          res = lhs->e11145;
          break;
        case 72:
          res = lhs->e11245;
          break;
        case 73:
          res = lhs->e12245;
          break;
        case 74:
          res = lhs->e22245;
          break;
        case 75:
          res = lhs->e11345;
          break;
        case 76:
          res = lhs->e12345;
          break;
        case 77:
          res = lhs->e22345;
          break;
        case 78:
          res = lhs->e13345;
          break;
        case 79:
          res = lhs->e23345;
          break;
        case 80:
          res = lhs->e33345;
          break;
        case 81:
          res = lhs->e11445;
          break;
        case 82:
          res = lhs->e12445;
          break;
        case 83:
          res = lhs->e22445;
          break;
        case 84:
          res = lhs->e13445;
          break;
        case 85:
          res = lhs->e23445;
          break;
        case 86:
          res = lhs->e33445;
          break;
        case 87:
          res = lhs->e14445;
          break;
        case 88:
          res = lhs->e24445;
          break;
        case 89:
          res = lhs->e34445;
          break;
        case 90:
          res = lhs->e44445;
          break;
        case 91:
          res = lhs->e11155;
          break;
        case 92:
          res = lhs->e11255;
          break;
        case 93:
          res = lhs->e12255;
          break;
        case 94:
          res = lhs->e22255;
          break;
        case 95:
          res = lhs->e11355;
          break;
        case 96:
          res = lhs->e12355;
          break;
        case 97:
          res = lhs->e22355;
          break;
        case 98:
          res = lhs->e13355;
          break;
        case 99:
          res = lhs->e23355;
          break;
        case 100:
          res = lhs->e33355;
          break;
        case 101:
          res = lhs->e11455;
          break;
        case 102:
          res = lhs->e12455;
          break;
        case 103:
          res = lhs->e22455;
          break;
        case 104:
          res = lhs->e13455;
          break;
        case 105:
          res = lhs->e23455;
          break;
        case 106:
          res = lhs->e33455;
          break;
        case 107:
          res = lhs->e14455;
          break;
        case 108:
          res = lhs->e24455;
          break;
        case 109:
          res = lhs->e34455;
          break;
        case 110:
          res = lhs->e44455;
          break;
        case 111:
          res = lhs->e11555;
          break;
        case 112:
          res = lhs->e12555;
          break;
        case 113:
          res = lhs->e22555;
          break;
        case 114:
          res = lhs->e13555;
          break;
        case 115:
          res = lhs->e23555;
          break;
        case 116:
          res = lhs->e33555;
          break;
        case 117:
          res = lhs->e14555;
          break;
        case 118:
          res = lhs->e24555;
          break;
        case 119:
          res = lhs->e34555;
          break;
        case 120:
          res = lhs->e44555;
          break;
        case 121:
          res = lhs->e15555;
          break;
        case 122:
          res = lhs->e25555;
          break;
        case 123:
          res = lhs->e35555;
          break;
        case 124:
          res = lhs->e45555;
          break;
        case 125:
          res = lhs->e55555;
          break;
      }
      break;
  }
  return res;

}

coeff_t onumm5n5_get_deriv(imdir_t idx, ord_t order, onumm5n5_t* lhs){

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
    case 5:
      switch (idx){
        case 0:
          factor = 1.2000000000000000e+02;
          res = lhs->e11111*factor;
          break;
        case 1:
          factor = 2.4000000000000000e+01;
          res = lhs->e11112*factor;
          break;
        case 2:
          factor = 1.2000000000000000e+01;
          res = lhs->e11122*factor;
          break;
        case 3:
          factor = 1.2000000000000000e+01;
          res = lhs->e11222*factor;
          break;
        case 4:
          factor = 2.4000000000000000e+01;
          res = lhs->e12222*factor;
          break;
        case 5:
          factor = 1.2000000000000000e+02;
          res = lhs->e22222*factor;
          break;
        case 6:
          factor = 2.4000000000000000e+01;
          res = lhs->e11113*factor;
          break;
        case 7:
          factor = 6.0000000000000000e+00;
          res = lhs->e11123*factor;
          break;
        case 8:
          factor = 4.0000000000000000e+00;
          res = lhs->e11223*factor;
          break;
        case 9:
          factor = 6.0000000000000000e+00;
          res = lhs->e12223*factor;
          break;
        case 10:
          factor = 2.4000000000000000e+01;
          res = lhs->e22223*factor;
          break;
        case 11:
          factor = 1.2000000000000000e+01;
          res = lhs->e11133*factor;
          break;
        case 12:
          factor = 4.0000000000000000e+00;
          res = lhs->e11233*factor;
          break;
        case 13:
          factor = 4.0000000000000000e+00;
          res = lhs->e12233*factor;
          break;
        case 14:
          factor = 1.2000000000000000e+01;
          res = lhs->e22233*factor;
          break;
        case 15:
          factor = 1.2000000000000000e+01;
          res = lhs->e11333*factor;
          break;
        case 16:
          factor = 6.0000000000000000e+00;
          res = lhs->e12333*factor;
          break;
        case 17:
          factor = 1.2000000000000000e+01;
          res = lhs->e22333*factor;
          break;
        case 18:
          factor = 2.4000000000000000e+01;
          res = lhs->e13333*factor;
          break;
        case 19:
          factor = 2.4000000000000000e+01;
          res = lhs->e23333*factor;
          break;
        case 20:
          factor = 1.2000000000000000e+02;
          res = lhs->e33333*factor;
          break;
        case 21:
          factor = 2.4000000000000000e+01;
          res = lhs->e11114*factor;
          break;
        case 22:
          factor = 6.0000000000000000e+00;
          res = lhs->e11124*factor;
          break;
        case 23:
          factor = 4.0000000000000000e+00;
          res = lhs->e11224*factor;
          break;
        case 24:
          factor = 6.0000000000000000e+00;
          res = lhs->e12224*factor;
          break;
        case 25:
          factor = 2.4000000000000000e+01;
          res = lhs->e22224*factor;
          break;
        case 26:
          factor = 6.0000000000000000e+00;
          res = lhs->e11134*factor;
          break;
        case 27:
          factor = 2.0000000000000000e+00;
          res = lhs->e11234*factor;
          break;
        case 28:
          factor = 2.0000000000000000e+00;
          res = lhs->e12234*factor;
          break;
        case 29:
          factor = 6.0000000000000000e+00;
          res = lhs->e22234*factor;
          break;
        case 30:
          factor = 4.0000000000000000e+00;
          res = lhs->e11334*factor;
          break;
        case 31:
          factor = 2.0000000000000000e+00;
          res = lhs->e12334*factor;
          break;
        case 32:
          factor = 4.0000000000000000e+00;
          res = lhs->e22334*factor;
          break;
        case 33:
          factor = 6.0000000000000000e+00;
          res = lhs->e13334*factor;
          break;
        case 34:
          factor = 6.0000000000000000e+00;
          res = lhs->e23334*factor;
          break;
        case 35:
          factor = 2.4000000000000000e+01;
          res = lhs->e33334*factor;
          break;
        case 36:
          factor = 1.2000000000000000e+01;
          res = lhs->e11144*factor;
          break;
        case 37:
          factor = 4.0000000000000000e+00;
          res = lhs->e11244*factor;
          break;
        case 38:
          factor = 4.0000000000000000e+00;
          res = lhs->e12244*factor;
          break;
        case 39:
          factor = 1.2000000000000000e+01;
          res = lhs->e22244*factor;
          break;
        case 40:
          factor = 4.0000000000000000e+00;
          res = lhs->e11344*factor;
          break;
        case 41:
          factor = 2.0000000000000000e+00;
          res = lhs->e12344*factor;
          break;
        case 42:
          factor = 4.0000000000000000e+00;
          res = lhs->e22344*factor;
          break;
        case 43:
          factor = 4.0000000000000000e+00;
          res = lhs->e13344*factor;
          break;
        case 44:
          factor = 4.0000000000000000e+00;
          res = lhs->e23344*factor;
          break;
        case 45:
          factor = 1.2000000000000000e+01;
          res = lhs->e33344*factor;
          break;
        case 46:
          factor = 1.2000000000000000e+01;
          res = lhs->e11444*factor;
          break;
        case 47:
          factor = 6.0000000000000000e+00;
          res = lhs->e12444*factor;
          break;
        case 48:
          factor = 1.2000000000000000e+01;
          res = lhs->e22444*factor;
          break;
        case 49:
          factor = 6.0000000000000000e+00;
          res = lhs->e13444*factor;
          break;
        case 50:
          factor = 6.0000000000000000e+00;
          res = lhs->e23444*factor;
          break;
        case 51:
          factor = 1.2000000000000000e+01;
          res = lhs->e33444*factor;
          break;
        case 52:
          factor = 2.4000000000000000e+01;
          res = lhs->e14444*factor;
          break;
        case 53:
          factor = 2.4000000000000000e+01;
          res = lhs->e24444*factor;
          break;
        case 54:
          factor = 2.4000000000000000e+01;
          res = lhs->e34444*factor;
          break;
        case 55:
          factor = 1.2000000000000000e+02;
          res = lhs->e44444*factor;
          break;
        case 56:
          factor = 2.4000000000000000e+01;
          res = lhs->e11115*factor;
          break;
        case 57:
          factor = 6.0000000000000000e+00;
          res = lhs->e11125*factor;
          break;
        case 58:
          factor = 4.0000000000000000e+00;
          res = lhs->e11225*factor;
          break;
        case 59:
          factor = 6.0000000000000000e+00;
          res = lhs->e12225*factor;
          break;
        case 60:
          factor = 2.4000000000000000e+01;
          res = lhs->e22225*factor;
          break;
        case 61:
          factor = 6.0000000000000000e+00;
          res = lhs->e11135*factor;
          break;
        case 62:
          factor = 2.0000000000000000e+00;
          res = lhs->e11235*factor;
          break;
        case 63:
          factor = 2.0000000000000000e+00;
          res = lhs->e12235*factor;
          break;
        case 64:
          factor = 6.0000000000000000e+00;
          res = lhs->e22235*factor;
          break;
        case 65:
          factor = 4.0000000000000000e+00;
          res = lhs->e11335*factor;
          break;
        case 66:
          factor = 2.0000000000000000e+00;
          res = lhs->e12335*factor;
          break;
        case 67:
          factor = 4.0000000000000000e+00;
          res = lhs->e22335*factor;
          break;
        case 68:
          factor = 6.0000000000000000e+00;
          res = lhs->e13335*factor;
          break;
        case 69:
          factor = 6.0000000000000000e+00;
          res = lhs->e23335*factor;
          break;
        case 70:
          factor = 2.4000000000000000e+01;
          res = lhs->e33335*factor;
          break;
        case 71:
          factor = 6.0000000000000000e+00;
          res = lhs->e11145*factor;
          break;
        case 72:
          factor = 2.0000000000000000e+00;
          res = lhs->e11245*factor;
          break;
        case 73:
          factor = 2.0000000000000000e+00;
          res = lhs->e12245*factor;
          break;
        case 74:
          factor = 6.0000000000000000e+00;
          res = lhs->e22245*factor;
          break;
        case 75:
          factor = 2.0000000000000000e+00;
          res = lhs->e11345*factor;
          break;
        case 76:
          factor = 1.0000000000000000e+00;
          res = lhs->e12345*factor;
          break;
        case 77:
          factor = 2.0000000000000000e+00;
          res = lhs->e22345*factor;
          break;
        case 78:
          factor = 2.0000000000000000e+00;
          res = lhs->e13345*factor;
          break;
        case 79:
          factor = 2.0000000000000000e+00;
          res = lhs->e23345*factor;
          break;
        case 80:
          factor = 6.0000000000000000e+00;
          res = lhs->e33345*factor;
          break;
        case 81:
          factor = 4.0000000000000000e+00;
          res = lhs->e11445*factor;
          break;
        case 82:
          factor = 2.0000000000000000e+00;
          res = lhs->e12445*factor;
          break;
        case 83:
          factor = 4.0000000000000000e+00;
          res = lhs->e22445*factor;
          break;
        case 84:
          factor = 2.0000000000000000e+00;
          res = lhs->e13445*factor;
          break;
        case 85:
          factor = 2.0000000000000000e+00;
          res = lhs->e23445*factor;
          break;
        case 86:
          factor = 4.0000000000000000e+00;
          res = lhs->e33445*factor;
          break;
        case 87:
          factor = 6.0000000000000000e+00;
          res = lhs->e14445*factor;
          break;
        case 88:
          factor = 6.0000000000000000e+00;
          res = lhs->e24445*factor;
          break;
        case 89:
          factor = 6.0000000000000000e+00;
          res = lhs->e34445*factor;
          break;
        case 90:
          factor = 2.4000000000000000e+01;
          res = lhs->e44445*factor;
          break;
        case 91:
          factor = 1.2000000000000000e+01;
          res = lhs->e11155*factor;
          break;
        case 92:
          factor = 4.0000000000000000e+00;
          res = lhs->e11255*factor;
          break;
        case 93:
          factor = 4.0000000000000000e+00;
          res = lhs->e12255*factor;
          break;
        case 94:
          factor = 1.2000000000000000e+01;
          res = lhs->e22255*factor;
          break;
        case 95:
          factor = 4.0000000000000000e+00;
          res = lhs->e11355*factor;
          break;
        case 96:
          factor = 2.0000000000000000e+00;
          res = lhs->e12355*factor;
          break;
        case 97:
          factor = 4.0000000000000000e+00;
          res = lhs->e22355*factor;
          break;
        case 98:
          factor = 4.0000000000000000e+00;
          res = lhs->e13355*factor;
          break;
        case 99:
          factor = 4.0000000000000000e+00;
          res = lhs->e23355*factor;
          break;
        case 100:
          factor = 1.2000000000000000e+01;
          res = lhs->e33355*factor;
          break;
        case 101:
          factor = 4.0000000000000000e+00;
          res = lhs->e11455*factor;
          break;
        case 102:
          factor = 2.0000000000000000e+00;
          res = lhs->e12455*factor;
          break;
        case 103:
          factor = 4.0000000000000000e+00;
          res = lhs->e22455*factor;
          break;
        case 104:
          factor = 2.0000000000000000e+00;
          res = lhs->e13455*factor;
          break;
        case 105:
          factor = 2.0000000000000000e+00;
          res = lhs->e23455*factor;
          break;
        case 106:
          factor = 4.0000000000000000e+00;
          res = lhs->e33455*factor;
          break;
        case 107:
          factor = 4.0000000000000000e+00;
          res = lhs->e14455*factor;
          break;
        case 108:
          factor = 4.0000000000000000e+00;
          res = lhs->e24455*factor;
          break;
        case 109:
          factor = 4.0000000000000000e+00;
          res = lhs->e34455*factor;
          break;
        case 110:
          factor = 1.2000000000000000e+01;
          res = lhs->e44455*factor;
          break;
        case 111:
          factor = 1.2000000000000000e+01;
          res = lhs->e11555*factor;
          break;
        case 112:
          factor = 6.0000000000000000e+00;
          res = lhs->e12555*factor;
          break;
        case 113:
          factor = 1.2000000000000000e+01;
          res = lhs->e22555*factor;
          break;
        case 114:
          factor = 6.0000000000000000e+00;
          res = lhs->e13555*factor;
          break;
        case 115:
          factor = 6.0000000000000000e+00;
          res = lhs->e23555*factor;
          break;
        case 116:
          factor = 1.2000000000000000e+01;
          res = lhs->e33555*factor;
          break;
        case 117:
          factor = 6.0000000000000000e+00;
          res = lhs->e14555*factor;
          break;
        case 118:
          factor = 6.0000000000000000e+00;
          res = lhs->e24555*factor;
          break;
        case 119:
          factor = 6.0000000000000000e+00;
          res = lhs->e34555*factor;
          break;
        case 120:
          factor = 1.2000000000000000e+01;
          res = lhs->e44555*factor;
          break;
        case 121:
          factor = 2.4000000000000000e+01;
          res = lhs->e15555*factor;
          break;
        case 122:
          factor = 2.4000000000000000e+01;
          res = lhs->e25555*factor;
          break;
        case 123:
          factor = 2.4000000000000000e+01;
          res = lhs->e35555*factor;
          break;
        case 124:
          factor = 2.4000000000000000e+01;
          res = lhs->e45555*factor;
          break;
        case 125:
          factor = 1.2000000000000000e+02;
          res = lhs->e55555*factor;
          break;
      }
      break;
  }
  return res;

}

void onumm5n5_set_item(coeff_t val, imdir_t idx, ord_t order, onumm5n5_t* x){

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
    case 5:
      switch (idx){
        case 0:
          x->e11111 = val;
          break;
        case 1:
          x->e11112 = val;
          break;
        case 2:
          x->e11122 = val;
          break;
        case 3:
          x->e11222 = val;
          break;
        case 4:
          x->e12222 = val;
          break;
        case 5:
          x->e22222 = val;
          break;
        case 6:
          x->e11113 = val;
          break;
        case 7:
          x->e11123 = val;
          break;
        case 8:
          x->e11223 = val;
          break;
        case 9:
          x->e12223 = val;
          break;
        case 10:
          x->e22223 = val;
          break;
        case 11:
          x->e11133 = val;
          break;
        case 12:
          x->e11233 = val;
          break;
        case 13:
          x->e12233 = val;
          break;
        case 14:
          x->e22233 = val;
          break;
        case 15:
          x->e11333 = val;
          break;
        case 16:
          x->e12333 = val;
          break;
        case 17:
          x->e22333 = val;
          break;
        case 18:
          x->e13333 = val;
          break;
        case 19:
          x->e23333 = val;
          break;
        case 20:
          x->e33333 = val;
          break;
        case 21:
          x->e11114 = val;
          break;
        case 22:
          x->e11124 = val;
          break;
        case 23:
          x->e11224 = val;
          break;
        case 24:
          x->e12224 = val;
          break;
        case 25:
          x->e22224 = val;
          break;
        case 26:
          x->e11134 = val;
          break;
        case 27:
          x->e11234 = val;
          break;
        case 28:
          x->e12234 = val;
          break;
        case 29:
          x->e22234 = val;
          break;
        case 30:
          x->e11334 = val;
          break;
        case 31:
          x->e12334 = val;
          break;
        case 32:
          x->e22334 = val;
          break;
        case 33:
          x->e13334 = val;
          break;
        case 34:
          x->e23334 = val;
          break;
        case 35:
          x->e33334 = val;
          break;
        case 36:
          x->e11144 = val;
          break;
        case 37:
          x->e11244 = val;
          break;
        case 38:
          x->e12244 = val;
          break;
        case 39:
          x->e22244 = val;
          break;
        case 40:
          x->e11344 = val;
          break;
        case 41:
          x->e12344 = val;
          break;
        case 42:
          x->e22344 = val;
          break;
        case 43:
          x->e13344 = val;
          break;
        case 44:
          x->e23344 = val;
          break;
        case 45:
          x->e33344 = val;
          break;
        case 46:
          x->e11444 = val;
          break;
        case 47:
          x->e12444 = val;
          break;
        case 48:
          x->e22444 = val;
          break;
        case 49:
          x->e13444 = val;
          break;
        case 50:
          x->e23444 = val;
          break;
        case 51:
          x->e33444 = val;
          break;
        case 52:
          x->e14444 = val;
          break;
        case 53:
          x->e24444 = val;
          break;
        case 54:
          x->e34444 = val;
          break;
        case 55:
          x->e44444 = val;
          break;
        case 56:
          x->e11115 = val;
          break;
        case 57:
          x->e11125 = val;
          break;
        case 58:
          x->e11225 = val;
          break;
        case 59:
          x->e12225 = val;
          break;
        case 60:
          x->e22225 = val;
          break;
        case 61:
          x->e11135 = val;
          break;
        case 62:
          x->e11235 = val;
          break;
        case 63:
          x->e12235 = val;
          break;
        case 64:
          x->e22235 = val;
          break;
        case 65:
          x->e11335 = val;
          break;
        case 66:
          x->e12335 = val;
          break;
        case 67:
          x->e22335 = val;
          break;
        case 68:
          x->e13335 = val;
          break;
        case 69:
          x->e23335 = val;
          break;
        case 70:
          x->e33335 = val;
          break;
        case 71:
          x->e11145 = val;
          break;
        case 72:
          x->e11245 = val;
          break;
        case 73:
          x->e12245 = val;
          break;
        case 74:
          x->e22245 = val;
          break;
        case 75:
          x->e11345 = val;
          break;
        case 76:
          x->e12345 = val;
          break;
        case 77:
          x->e22345 = val;
          break;
        case 78:
          x->e13345 = val;
          break;
        case 79:
          x->e23345 = val;
          break;
        case 80:
          x->e33345 = val;
          break;
        case 81:
          x->e11445 = val;
          break;
        case 82:
          x->e12445 = val;
          break;
        case 83:
          x->e22445 = val;
          break;
        case 84:
          x->e13445 = val;
          break;
        case 85:
          x->e23445 = val;
          break;
        case 86:
          x->e33445 = val;
          break;
        case 87:
          x->e14445 = val;
          break;
        case 88:
          x->e24445 = val;
          break;
        case 89:
          x->e34445 = val;
          break;
        case 90:
          x->e44445 = val;
          break;
        case 91:
          x->e11155 = val;
          break;
        case 92:
          x->e11255 = val;
          break;
        case 93:
          x->e12255 = val;
          break;
        case 94:
          x->e22255 = val;
          break;
        case 95:
          x->e11355 = val;
          break;
        case 96:
          x->e12355 = val;
          break;
        case 97:
          x->e22355 = val;
          break;
        case 98:
          x->e13355 = val;
          break;
        case 99:
          x->e23355 = val;
          break;
        case 100:
          x->e33355 = val;
          break;
        case 101:
          x->e11455 = val;
          break;
        case 102:
          x->e12455 = val;
          break;
        case 103:
          x->e22455 = val;
          break;
        case 104:
          x->e13455 = val;
          break;
        case 105:
          x->e23455 = val;
          break;
        case 106:
          x->e33455 = val;
          break;
        case 107:
          x->e14455 = val;
          break;
        case 108:
          x->e24455 = val;
          break;
        case 109:
          x->e34455 = val;
          break;
        case 110:
          x->e44455 = val;
          break;
        case 111:
          x->e11555 = val;
          break;
        case 112:
          x->e12555 = val;
          break;
        case 113:
          x->e22555 = val;
          break;
        case 114:
          x->e13555 = val;
          break;
        case 115:
          x->e23555 = val;
          break;
        case 116:
          x->e33555 = val;
          break;
        case 117:
          x->e14555 = val;
          break;
        case 118:
          x->e24555 = val;
          break;
        case 119:
          x->e34555 = val;
          break;
        case 120:
          x->e44555 = val;
          break;
        case 121:
          x->e15555 = val;
          break;
        case 122:
          x->e25555 = val;
          break;
        case 123:
          x->e35555 = val;
          break;
        case 124:
          x->e45555 = val;
          break;
        case 125:
          x->e55555 = val;
          break;
      }
      break;
  }
}

onumm5n5_t onumm5n5_copy(  onumm5n5_t* lhs){

  onumm5n5_t res;

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

void onumm5n5_copy_to(  onumm5n5_t* lhs, onumm5n5_t* res){

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

onumm5n5_t onumm5n5_taylor_integrate(coeff_t* deltas,onumm5n5_t* lhs){

  onumm5n5_t res;

  res = onumm5n5_init();
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
  // Order 5;
  factor = pow(deltas[0],5)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],0);
  res.r += factor*lhs->e11111;
  factor = pow(deltas[0],4)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],0);
  res.r += factor*lhs->e11112;
  factor = pow(deltas[0],3)*pow(deltas[1],2)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],0);
  res.r += factor*lhs->e11122;
  factor = pow(deltas[0],2)*pow(deltas[1],3)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],0);
  res.r += factor*lhs->e11222;
  factor = pow(deltas[0],1)*pow(deltas[1],4)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],0);
  res.r += factor*lhs->e12222;
  factor = pow(deltas[0],0)*pow(deltas[1],5)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],0);
  res.r += factor*lhs->e22222;
  factor = pow(deltas[0],4)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],0)*pow(deltas[4],0);
  res.r += factor*lhs->e11113;
  factor = pow(deltas[0],3)*pow(deltas[1],1)*pow(deltas[2],1)*pow(deltas[3],0)*pow(deltas[4],0);
  res.r += factor*lhs->e11123;
  factor = pow(deltas[0],2)*pow(deltas[1],2)*pow(deltas[2],1)*pow(deltas[3],0)*pow(deltas[4],0);
  res.r += factor*lhs->e11223;
  factor = pow(deltas[0],1)*pow(deltas[1],3)*pow(deltas[2],1)*pow(deltas[3],0)*pow(deltas[4],0);
  res.r += factor*lhs->e12223;
  factor = pow(deltas[0],0)*pow(deltas[1],4)*pow(deltas[2],1)*pow(deltas[3],0)*pow(deltas[4],0);
  res.r += factor*lhs->e22223;
  factor = pow(deltas[0],3)*pow(deltas[1],0)*pow(deltas[2],2)*pow(deltas[3],0)*pow(deltas[4],0);
  res.r += factor*lhs->e11133;
  factor = pow(deltas[0],2)*pow(deltas[1],1)*pow(deltas[2],2)*pow(deltas[3],0)*pow(deltas[4],0);
  res.r += factor*lhs->e11233;
  factor = pow(deltas[0],1)*pow(deltas[1],2)*pow(deltas[2],2)*pow(deltas[3],0)*pow(deltas[4],0);
  res.r += factor*lhs->e12233;
  factor = pow(deltas[0],0)*pow(deltas[1],3)*pow(deltas[2],2)*pow(deltas[3],0)*pow(deltas[4],0);
  res.r += factor*lhs->e22233;
  factor = pow(deltas[0],2)*pow(deltas[1],0)*pow(deltas[2],3)*pow(deltas[3],0)*pow(deltas[4],0);
  res.r += factor*lhs->e11333;
  factor = pow(deltas[0],1)*pow(deltas[1],1)*pow(deltas[2],3)*pow(deltas[3],0)*pow(deltas[4],0);
  res.r += factor*lhs->e12333;
  factor = pow(deltas[0],0)*pow(deltas[1],2)*pow(deltas[2],3)*pow(deltas[3],0)*pow(deltas[4],0);
  res.r += factor*lhs->e22333;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],4)*pow(deltas[3],0)*pow(deltas[4],0);
  res.r += factor*lhs->e13333;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],4)*pow(deltas[3],0)*pow(deltas[4],0);
  res.r += factor*lhs->e23333;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],5)*pow(deltas[3],0)*pow(deltas[4],0);
  res.r += factor*lhs->e33333;
  factor = pow(deltas[0],4)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],1)*pow(deltas[4],0);
  res.r += factor*lhs->e11114;
  factor = pow(deltas[0],3)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],1)*pow(deltas[4],0);
  res.r += factor*lhs->e11124;
  factor = pow(deltas[0],2)*pow(deltas[1],2)*pow(deltas[2],0)*pow(deltas[3],1)*pow(deltas[4],0);
  res.r += factor*lhs->e11224;
  factor = pow(deltas[0],1)*pow(deltas[1],3)*pow(deltas[2],0)*pow(deltas[3],1)*pow(deltas[4],0);
  res.r += factor*lhs->e12224;
  factor = pow(deltas[0],0)*pow(deltas[1],4)*pow(deltas[2],0)*pow(deltas[3],1)*pow(deltas[4],0);
  res.r += factor*lhs->e22224;
  factor = pow(deltas[0],3)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],1)*pow(deltas[4],0);
  res.r += factor*lhs->e11134;
  factor = pow(deltas[0],2)*pow(deltas[1],1)*pow(deltas[2],1)*pow(deltas[3],1)*pow(deltas[4],0);
  res.r += factor*lhs->e11234;
  factor = pow(deltas[0],1)*pow(deltas[1],2)*pow(deltas[2],1)*pow(deltas[3],1)*pow(deltas[4],0);
  res.r += factor*lhs->e12234;
  factor = pow(deltas[0],0)*pow(deltas[1],3)*pow(deltas[2],1)*pow(deltas[3],1)*pow(deltas[4],0);
  res.r += factor*lhs->e22234;
  factor = pow(deltas[0],2)*pow(deltas[1],0)*pow(deltas[2],2)*pow(deltas[3],1)*pow(deltas[4],0);
  res.r += factor*lhs->e11334;
  factor = pow(deltas[0],1)*pow(deltas[1],1)*pow(deltas[2],2)*pow(deltas[3],1)*pow(deltas[4],0);
  res.r += factor*lhs->e12334;
  factor = pow(deltas[0],0)*pow(deltas[1],2)*pow(deltas[2],2)*pow(deltas[3],1)*pow(deltas[4],0);
  res.r += factor*lhs->e22334;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],3)*pow(deltas[3],1)*pow(deltas[4],0);
  res.r += factor*lhs->e13334;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],3)*pow(deltas[3],1)*pow(deltas[4],0);
  res.r += factor*lhs->e23334;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],4)*pow(deltas[3],1)*pow(deltas[4],0);
  res.r += factor*lhs->e33334;
  factor = pow(deltas[0],3)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],2)*pow(deltas[4],0);
  res.r += factor*lhs->e11144;
  factor = pow(deltas[0],2)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],2)*pow(deltas[4],0);
  res.r += factor*lhs->e11244;
  factor = pow(deltas[0],1)*pow(deltas[1],2)*pow(deltas[2],0)*pow(deltas[3],2)*pow(deltas[4],0);
  res.r += factor*lhs->e12244;
  factor = pow(deltas[0],0)*pow(deltas[1],3)*pow(deltas[2],0)*pow(deltas[3],2)*pow(deltas[4],0);
  res.r += factor*lhs->e22244;
  factor = pow(deltas[0],2)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],2)*pow(deltas[4],0);
  res.r += factor*lhs->e11344;
  factor = pow(deltas[0],1)*pow(deltas[1],1)*pow(deltas[2],1)*pow(deltas[3],2)*pow(deltas[4],0);
  res.r += factor*lhs->e12344;
  factor = pow(deltas[0],0)*pow(deltas[1],2)*pow(deltas[2],1)*pow(deltas[3],2)*pow(deltas[4],0);
  res.r += factor*lhs->e22344;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],2)*pow(deltas[3],2)*pow(deltas[4],0);
  res.r += factor*lhs->e13344;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],2)*pow(deltas[3],2)*pow(deltas[4],0);
  res.r += factor*lhs->e23344;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],3)*pow(deltas[3],2)*pow(deltas[4],0);
  res.r += factor*lhs->e33344;
  factor = pow(deltas[0],2)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],3)*pow(deltas[4],0);
  res.r += factor*lhs->e11444;
  factor = pow(deltas[0],1)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],3)*pow(deltas[4],0);
  res.r += factor*lhs->e12444;
  factor = pow(deltas[0],0)*pow(deltas[1],2)*pow(deltas[2],0)*pow(deltas[3],3)*pow(deltas[4],0);
  res.r += factor*lhs->e22444;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],3)*pow(deltas[4],0);
  res.r += factor*lhs->e13444;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],1)*pow(deltas[3],3)*pow(deltas[4],0);
  res.r += factor*lhs->e23444;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],2)*pow(deltas[3],3)*pow(deltas[4],0);
  res.r += factor*lhs->e33444;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],4)*pow(deltas[4],0);
  res.r += factor*lhs->e14444;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],4)*pow(deltas[4],0);
  res.r += factor*lhs->e24444;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],4)*pow(deltas[4],0);
  res.r += factor*lhs->e34444;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],5)*pow(deltas[4],0);
  res.r += factor*lhs->e44444;
  factor = pow(deltas[0],4)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],1);
  res.r += factor*lhs->e11115;
  factor = pow(deltas[0],3)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],1);
  res.r += factor*lhs->e11125;
  factor = pow(deltas[0],2)*pow(deltas[1],2)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],1);
  res.r += factor*lhs->e11225;
  factor = pow(deltas[0],1)*pow(deltas[1],3)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],1);
  res.r += factor*lhs->e12225;
  factor = pow(deltas[0],0)*pow(deltas[1],4)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],1);
  res.r += factor*lhs->e22225;
  factor = pow(deltas[0],3)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],0)*pow(deltas[4],1);
  res.r += factor*lhs->e11135;
  factor = pow(deltas[0],2)*pow(deltas[1],1)*pow(deltas[2],1)*pow(deltas[3],0)*pow(deltas[4],1);
  res.r += factor*lhs->e11235;
  factor = pow(deltas[0],1)*pow(deltas[1],2)*pow(deltas[2],1)*pow(deltas[3],0)*pow(deltas[4],1);
  res.r += factor*lhs->e12235;
  factor = pow(deltas[0],0)*pow(deltas[1],3)*pow(deltas[2],1)*pow(deltas[3],0)*pow(deltas[4],1);
  res.r += factor*lhs->e22235;
  factor = pow(deltas[0],2)*pow(deltas[1],0)*pow(deltas[2],2)*pow(deltas[3],0)*pow(deltas[4],1);
  res.r += factor*lhs->e11335;
  factor = pow(deltas[0],1)*pow(deltas[1],1)*pow(deltas[2],2)*pow(deltas[3],0)*pow(deltas[4],1);
  res.r += factor*lhs->e12335;
  factor = pow(deltas[0],0)*pow(deltas[1],2)*pow(deltas[2],2)*pow(deltas[3],0)*pow(deltas[4],1);
  res.r += factor*lhs->e22335;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],3)*pow(deltas[3],0)*pow(deltas[4],1);
  res.r += factor*lhs->e13335;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],3)*pow(deltas[3],0)*pow(deltas[4],1);
  res.r += factor*lhs->e23335;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],4)*pow(deltas[3],0)*pow(deltas[4],1);
  res.r += factor*lhs->e33335;
  factor = pow(deltas[0],3)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],1)*pow(deltas[4],1);
  res.r += factor*lhs->e11145;
  factor = pow(deltas[0],2)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],1)*pow(deltas[4],1);
  res.r += factor*lhs->e11245;
  factor = pow(deltas[0],1)*pow(deltas[1],2)*pow(deltas[2],0)*pow(deltas[3],1)*pow(deltas[4],1);
  res.r += factor*lhs->e12245;
  factor = pow(deltas[0],0)*pow(deltas[1],3)*pow(deltas[2],0)*pow(deltas[3],1)*pow(deltas[4],1);
  res.r += factor*lhs->e22245;
  factor = pow(deltas[0],2)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],1)*pow(deltas[4],1);
  res.r += factor*lhs->e11345;
  factor = pow(deltas[0],1)*pow(deltas[1],1)*pow(deltas[2],1)*pow(deltas[3],1)*pow(deltas[4],1);
  res.r += factor*lhs->e12345;
  factor = pow(deltas[0],0)*pow(deltas[1],2)*pow(deltas[2],1)*pow(deltas[3],1)*pow(deltas[4],1);
  res.r += factor*lhs->e22345;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],2)*pow(deltas[3],1)*pow(deltas[4],1);
  res.r += factor*lhs->e13345;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],2)*pow(deltas[3],1)*pow(deltas[4],1);
  res.r += factor*lhs->e23345;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],3)*pow(deltas[3],1)*pow(deltas[4],1);
  res.r += factor*lhs->e33345;
  factor = pow(deltas[0],2)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],2)*pow(deltas[4],1);
  res.r += factor*lhs->e11445;
  factor = pow(deltas[0],1)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],2)*pow(deltas[4],1);
  res.r += factor*lhs->e12445;
  factor = pow(deltas[0],0)*pow(deltas[1],2)*pow(deltas[2],0)*pow(deltas[3],2)*pow(deltas[4],1);
  res.r += factor*lhs->e22445;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],2)*pow(deltas[4],1);
  res.r += factor*lhs->e13445;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],1)*pow(deltas[3],2)*pow(deltas[4],1);
  res.r += factor*lhs->e23445;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],2)*pow(deltas[3],2)*pow(deltas[4],1);
  res.r += factor*lhs->e33445;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],3)*pow(deltas[4],1);
  res.r += factor*lhs->e14445;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],3)*pow(deltas[4],1);
  res.r += factor*lhs->e24445;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],3)*pow(deltas[4],1);
  res.r += factor*lhs->e34445;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],4)*pow(deltas[4],1);
  res.r += factor*lhs->e44445;
  factor = pow(deltas[0],3)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],2);
  res.r += factor*lhs->e11155;
  factor = pow(deltas[0],2)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],2);
  res.r += factor*lhs->e11255;
  factor = pow(deltas[0],1)*pow(deltas[1],2)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],2);
  res.r += factor*lhs->e12255;
  factor = pow(deltas[0],0)*pow(deltas[1],3)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],2);
  res.r += factor*lhs->e22255;
  factor = pow(deltas[0],2)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],0)*pow(deltas[4],2);
  res.r += factor*lhs->e11355;
  factor = pow(deltas[0],1)*pow(deltas[1],1)*pow(deltas[2],1)*pow(deltas[3],0)*pow(deltas[4],2);
  res.r += factor*lhs->e12355;
  factor = pow(deltas[0],0)*pow(deltas[1],2)*pow(deltas[2],1)*pow(deltas[3],0)*pow(deltas[4],2);
  res.r += factor*lhs->e22355;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],2)*pow(deltas[3],0)*pow(deltas[4],2);
  res.r += factor*lhs->e13355;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],2)*pow(deltas[3],0)*pow(deltas[4],2);
  res.r += factor*lhs->e23355;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],3)*pow(deltas[3],0)*pow(deltas[4],2);
  res.r += factor*lhs->e33355;
  factor = pow(deltas[0],2)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],1)*pow(deltas[4],2);
  res.r += factor*lhs->e11455;
  factor = pow(deltas[0],1)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],1)*pow(deltas[4],2);
  res.r += factor*lhs->e12455;
  factor = pow(deltas[0],0)*pow(deltas[1],2)*pow(deltas[2],0)*pow(deltas[3],1)*pow(deltas[4],2);
  res.r += factor*lhs->e22455;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],1)*pow(deltas[4],2);
  res.r += factor*lhs->e13455;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],1)*pow(deltas[3],1)*pow(deltas[4],2);
  res.r += factor*lhs->e23455;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],2)*pow(deltas[3],1)*pow(deltas[4],2);
  res.r += factor*lhs->e33455;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],2)*pow(deltas[4],2);
  res.r += factor*lhs->e14455;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],2)*pow(deltas[4],2);
  res.r += factor*lhs->e24455;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],2)*pow(deltas[4],2);
  res.r += factor*lhs->e34455;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],3)*pow(deltas[4],2);
  res.r += factor*lhs->e44455;
  factor = pow(deltas[0],2)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],3);
  res.r += factor*lhs->e11555;
  factor = pow(deltas[0],1)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],3);
  res.r += factor*lhs->e12555;
  factor = pow(deltas[0],0)*pow(deltas[1],2)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],3);
  res.r += factor*lhs->e22555;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],0)*pow(deltas[4],3);
  res.r += factor*lhs->e13555;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],1)*pow(deltas[3],0)*pow(deltas[4],3);
  res.r += factor*lhs->e23555;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],2)*pow(deltas[3],0)*pow(deltas[4],3);
  res.r += factor*lhs->e33555;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],1)*pow(deltas[4],3);
  res.r += factor*lhs->e14555;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],1)*pow(deltas[4],3);
  res.r += factor*lhs->e24555;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],1)*pow(deltas[4],3);
  res.r += factor*lhs->e34555;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],2)*pow(deltas[4],3);
  res.r += factor*lhs->e44555;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],4);
  res.r += factor*lhs->e15555;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],4);
  res.r += factor*lhs->e25555;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],0)*pow(deltas[4],4);
  res.r += factor*lhs->e35555;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],1)*pow(deltas[4],4);
  res.r += factor*lhs->e45555;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],5);
  res.r += factor*lhs->e55555;

  return res;

}

void onumm5n5_taylor_integrate_to(coeff_t* deltas,onumm5n5_t* lhs, onumm5n5_t* res){

  *res = onumm5n5_init();
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
  // Order 5;
  factor = pow(deltas[0],5)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],0);
  res->r += factor*lhs->e11111;
  factor = pow(deltas[0],4)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],0);
  res->r += factor*lhs->e11112;
  factor = pow(deltas[0],3)*pow(deltas[1],2)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],0);
  res->r += factor*lhs->e11122;
  factor = pow(deltas[0],2)*pow(deltas[1],3)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],0);
  res->r += factor*lhs->e11222;
  factor = pow(deltas[0],1)*pow(deltas[1],4)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],0);
  res->r += factor*lhs->e12222;
  factor = pow(deltas[0],0)*pow(deltas[1],5)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],0);
  res->r += factor*lhs->e22222;
  factor = pow(deltas[0],4)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],0)*pow(deltas[4],0);
  res->r += factor*lhs->e11113;
  factor = pow(deltas[0],3)*pow(deltas[1],1)*pow(deltas[2],1)*pow(deltas[3],0)*pow(deltas[4],0);
  res->r += factor*lhs->e11123;
  factor = pow(deltas[0],2)*pow(deltas[1],2)*pow(deltas[2],1)*pow(deltas[3],0)*pow(deltas[4],0);
  res->r += factor*lhs->e11223;
  factor = pow(deltas[0],1)*pow(deltas[1],3)*pow(deltas[2],1)*pow(deltas[3],0)*pow(deltas[4],0);
  res->r += factor*lhs->e12223;
  factor = pow(deltas[0],0)*pow(deltas[1],4)*pow(deltas[2],1)*pow(deltas[3],0)*pow(deltas[4],0);
  res->r += factor*lhs->e22223;
  factor = pow(deltas[0],3)*pow(deltas[1],0)*pow(deltas[2],2)*pow(deltas[3],0)*pow(deltas[4],0);
  res->r += factor*lhs->e11133;
  factor = pow(deltas[0],2)*pow(deltas[1],1)*pow(deltas[2],2)*pow(deltas[3],0)*pow(deltas[4],0);
  res->r += factor*lhs->e11233;
  factor = pow(deltas[0],1)*pow(deltas[1],2)*pow(deltas[2],2)*pow(deltas[3],0)*pow(deltas[4],0);
  res->r += factor*lhs->e12233;
  factor = pow(deltas[0],0)*pow(deltas[1],3)*pow(deltas[2],2)*pow(deltas[3],0)*pow(deltas[4],0);
  res->r += factor*lhs->e22233;
  factor = pow(deltas[0],2)*pow(deltas[1],0)*pow(deltas[2],3)*pow(deltas[3],0)*pow(deltas[4],0);
  res->r += factor*lhs->e11333;
  factor = pow(deltas[0],1)*pow(deltas[1],1)*pow(deltas[2],3)*pow(deltas[3],0)*pow(deltas[4],0);
  res->r += factor*lhs->e12333;
  factor = pow(deltas[0],0)*pow(deltas[1],2)*pow(deltas[2],3)*pow(deltas[3],0)*pow(deltas[4],0);
  res->r += factor*lhs->e22333;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],4)*pow(deltas[3],0)*pow(deltas[4],0);
  res->r += factor*lhs->e13333;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],4)*pow(deltas[3],0)*pow(deltas[4],0);
  res->r += factor*lhs->e23333;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],5)*pow(deltas[3],0)*pow(deltas[4],0);
  res->r += factor*lhs->e33333;
  factor = pow(deltas[0],4)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],1)*pow(deltas[4],0);
  res->r += factor*lhs->e11114;
  factor = pow(deltas[0],3)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],1)*pow(deltas[4],0);
  res->r += factor*lhs->e11124;
  factor = pow(deltas[0],2)*pow(deltas[1],2)*pow(deltas[2],0)*pow(deltas[3],1)*pow(deltas[4],0);
  res->r += factor*lhs->e11224;
  factor = pow(deltas[0],1)*pow(deltas[1],3)*pow(deltas[2],0)*pow(deltas[3],1)*pow(deltas[4],0);
  res->r += factor*lhs->e12224;
  factor = pow(deltas[0],0)*pow(deltas[1],4)*pow(deltas[2],0)*pow(deltas[3],1)*pow(deltas[4],0);
  res->r += factor*lhs->e22224;
  factor = pow(deltas[0],3)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],1)*pow(deltas[4],0);
  res->r += factor*lhs->e11134;
  factor = pow(deltas[0],2)*pow(deltas[1],1)*pow(deltas[2],1)*pow(deltas[3],1)*pow(deltas[4],0);
  res->r += factor*lhs->e11234;
  factor = pow(deltas[0],1)*pow(deltas[1],2)*pow(deltas[2],1)*pow(deltas[3],1)*pow(deltas[4],0);
  res->r += factor*lhs->e12234;
  factor = pow(deltas[0],0)*pow(deltas[1],3)*pow(deltas[2],1)*pow(deltas[3],1)*pow(deltas[4],0);
  res->r += factor*lhs->e22234;
  factor = pow(deltas[0],2)*pow(deltas[1],0)*pow(deltas[2],2)*pow(deltas[3],1)*pow(deltas[4],0);
  res->r += factor*lhs->e11334;
  factor = pow(deltas[0],1)*pow(deltas[1],1)*pow(deltas[2],2)*pow(deltas[3],1)*pow(deltas[4],0);
  res->r += factor*lhs->e12334;
  factor = pow(deltas[0],0)*pow(deltas[1],2)*pow(deltas[2],2)*pow(deltas[3],1)*pow(deltas[4],0);
  res->r += factor*lhs->e22334;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],3)*pow(deltas[3],1)*pow(deltas[4],0);
  res->r += factor*lhs->e13334;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],3)*pow(deltas[3],1)*pow(deltas[4],0);
  res->r += factor*lhs->e23334;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],4)*pow(deltas[3],1)*pow(deltas[4],0);
  res->r += factor*lhs->e33334;
  factor = pow(deltas[0],3)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],2)*pow(deltas[4],0);
  res->r += factor*lhs->e11144;
  factor = pow(deltas[0],2)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],2)*pow(deltas[4],0);
  res->r += factor*lhs->e11244;
  factor = pow(deltas[0],1)*pow(deltas[1],2)*pow(deltas[2],0)*pow(deltas[3],2)*pow(deltas[4],0);
  res->r += factor*lhs->e12244;
  factor = pow(deltas[0],0)*pow(deltas[1],3)*pow(deltas[2],0)*pow(deltas[3],2)*pow(deltas[4],0);
  res->r += factor*lhs->e22244;
  factor = pow(deltas[0],2)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],2)*pow(deltas[4],0);
  res->r += factor*lhs->e11344;
  factor = pow(deltas[0],1)*pow(deltas[1],1)*pow(deltas[2],1)*pow(deltas[3],2)*pow(deltas[4],0);
  res->r += factor*lhs->e12344;
  factor = pow(deltas[0],0)*pow(deltas[1],2)*pow(deltas[2],1)*pow(deltas[3],2)*pow(deltas[4],0);
  res->r += factor*lhs->e22344;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],2)*pow(deltas[3],2)*pow(deltas[4],0);
  res->r += factor*lhs->e13344;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],2)*pow(deltas[3],2)*pow(deltas[4],0);
  res->r += factor*lhs->e23344;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],3)*pow(deltas[3],2)*pow(deltas[4],0);
  res->r += factor*lhs->e33344;
  factor = pow(deltas[0],2)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],3)*pow(deltas[4],0);
  res->r += factor*lhs->e11444;
  factor = pow(deltas[0],1)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],3)*pow(deltas[4],0);
  res->r += factor*lhs->e12444;
  factor = pow(deltas[0],0)*pow(deltas[1],2)*pow(deltas[2],0)*pow(deltas[3],3)*pow(deltas[4],0);
  res->r += factor*lhs->e22444;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],3)*pow(deltas[4],0);
  res->r += factor*lhs->e13444;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],1)*pow(deltas[3],3)*pow(deltas[4],0);
  res->r += factor*lhs->e23444;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],2)*pow(deltas[3],3)*pow(deltas[4],0);
  res->r += factor*lhs->e33444;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],4)*pow(deltas[4],0);
  res->r += factor*lhs->e14444;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],4)*pow(deltas[4],0);
  res->r += factor*lhs->e24444;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],4)*pow(deltas[4],0);
  res->r += factor*lhs->e34444;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],5)*pow(deltas[4],0);
  res->r += factor*lhs->e44444;
  factor = pow(deltas[0],4)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],1);
  res->r += factor*lhs->e11115;
  factor = pow(deltas[0],3)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],1);
  res->r += factor*lhs->e11125;
  factor = pow(deltas[0],2)*pow(deltas[1],2)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],1);
  res->r += factor*lhs->e11225;
  factor = pow(deltas[0],1)*pow(deltas[1],3)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],1);
  res->r += factor*lhs->e12225;
  factor = pow(deltas[0],0)*pow(deltas[1],4)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],1);
  res->r += factor*lhs->e22225;
  factor = pow(deltas[0],3)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],0)*pow(deltas[4],1);
  res->r += factor*lhs->e11135;
  factor = pow(deltas[0],2)*pow(deltas[1],1)*pow(deltas[2],1)*pow(deltas[3],0)*pow(deltas[4],1);
  res->r += factor*lhs->e11235;
  factor = pow(deltas[0],1)*pow(deltas[1],2)*pow(deltas[2],1)*pow(deltas[3],0)*pow(deltas[4],1);
  res->r += factor*lhs->e12235;
  factor = pow(deltas[0],0)*pow(deltas[1],3)*pow(deltas[2],1)*pow(deltas[3],0)*pow(deltas[4],1);
  res->r += factor*lhs->e22235;
  factor = pow(deltas[0],2)*pow(deltas[1],0)*pow(deltas[2],2)*pow(deltas[3],0)*pow(deltas[4],1);
  res->r += factor*lhs->e11335;
  factor = pow(deltas[0],1)*pow(deltas[1],1)*pow(deltas[2],2)*pow(deltas[3],0)*pow(deltas[4],1);
  res->r += factor*lhs->e12335;
  factor = pow(deltas[0],0)*pow(deltas[1],2)*pow(deltas[2],2)*pow(deltas[3],0)*pow(deltas[4],1);
  res->r += factor*lhs->e22335;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],3)*pow(deltas[3],0)*pow(deltas[4],1);
  res->r += factor*lhs->e13335;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],3)*pow(deltas[3],0)*pow(deltas[4],1);
  res->r += factor*lhs->e23335;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],4)*pow(deltas[3],0)*pow(deltas[4],1);
  res->r += factor*lhs->e33335;
  factor = pow(deltas[0],3)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],1)*pow(deltas[4],1);
  res->r += factor*lhs->e11145;
  factor = pow(deltas[0],2)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],1)*pow(deltas[4],1);
  res->r += factor*lhs->e11245;
  factor = pow(deltas[0],1)*pow(deltas[1],2)*pow(deltas[2],0)*pow(deltas[3],1)*pow(deltas[4],1);
  res->r += factor*lhs->e12245;
  factor = pow(deltas[0],0)*pow(deltas[1],3)*pow(deltas[2],0)*pow(deltas[3],1)*pow(deltas[4],1);
  res->r += factor*lhs->e22245;
  factor = pow(deltas[0],2)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],1)*pow(deltas[4],1);
  res->r += factor*lhs->e11345;
  factor = pow(deltas[0],1)*pow(deltas[1],1)*pow(deltas[2],1)*pow(deltas[3],1)*pow(deltas[4],1);
  res->r += factor*lhs->e12345;
  factor = pow(deltas[0],0)*pow(deltas[1],2)*pow(deltas[2],1)*pow(deltas[3],1)*pow(deltas[4],1);
  res->r += factor*lhs->e22345;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],2)*pow(deltas[3],1)*pow(deltas[4],1);
  res->r += factor*lhs->e13345;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],2)*pow(deltas[3],1)*pow(deltas[4],1);
  res->r += factor*lhs->e23345;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],3)*pow(deltas[3],1)*pow(deltas[4],1);
  res->r += factor*lhs->e33345;
  factor = pow(deltas[0],2)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],2)*pow(deltas[4],1);
  res->r += factor*lhs->e11445;
  factor = pow(deltas[0],1)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],2)*pow(deltas[4],1);
  res->r += factor*lhs->e12445;
  factor = pow(deltas[0],0)*pow(deltas[1],2)*pow(deltas[2],0)*pow(deltas[3],2)*pow(deltas[4],1);
  res->r += factor*lhs->e22445;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],2)*pow(deltas[4],1);
  res->r += factor*lhs->e13445;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],1)*pow(deltas[3],2)*pow(deltas[4],1);
  res->r += factor*lhs->e23445;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],2)*pow(deltas[3],2)*pow(deltas[4],1);
  res->r += factor*lhs->e33445;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],3)*pow(deltas[4],1);
  res->r += factor*lhs->e14445;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],3)*pow(deltas[4],1);
  res->r += factor*lhs->e24445;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],3)*pow(deltas[4],1);
  res->r += factor*lhs->e34445;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],4)*pow(deltas[4],1);
  res->r += factor*lhs->e44445;
  factor = pow(deltas[0],3)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],2);
  res->r += factor*lhs->e11155;
  factor = pow(deltas[0],2)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],2);
  res->r += factor*lhs->e11255;
  factor = pow(deltas[0],1)*pow(deltas[1],2)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],2);
  res->r += factor*lhs->e12255;
  factor = pow(deltas[0],0)*pow(deltas[1],3)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],2);
  res->r += factor*lhs->e22255;
  factor = pow(deltas[0],2)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],0)*pow(deltas[4],2);
  res->r += factor*lhs->e11355;
  factor = pow(deltas[0],1)*pow(deltas[1],1)*pow(deltas[2],1)*pow(deltas[3],0)*pow(deltas[4],2);
  res->r += factor*lhs->e12355;
  factor = pow(deltas[0],0)*pow(deltas[1],2)*pow(deltas[2],1)*pow(deltas[3],0)*pow(deltas[4],2);
  res->r += factor*lhs->e22355;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],2)*pow(deltas[3],0)*pow(deltas[4],2);
  res->r += factor*lhs->e13355;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],2)*pow(deltas[3],0)*pow(deltas[4],2);
  res->r += factor*lhs->e23355;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],3)*pow(deltas[3],0)*pow(deltas[4],2);
  res->r += factor*lhs->e33355;
  factor = pow(deltas[0],2)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],1)*pow(deltas[4],2);
  res->r += factor*lhs->e11455;
  factor = pow(deltas[0],1)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],1)*pow(deltas[4],2);
  res->r += factor*lhs->e12455;
  factor = pow(deltas[0],0)*pow(deltas[1],2)*pow(deltas[2],0)*pow(deltas[3],1)*pow(deltas[4],2);
  res->r += factor*lhs->e22455;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],1)*pow(deltas[4],2);
  res->r += factor*lhs->e13455;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],1)*pow(deltas[3],1)*pow(deltas[4],2);
  res->r += factor*lhs->e23455;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],2)*pow(deltas[3],1)*pow(deltas[4],2);
  res->r += factor*lhs->e33455;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],2)*pow(deltas[4],2);
  res->r += factor*lhs->e14455;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],2)*pow(deltas[4],2);
  res->r += factor*lhs->e24455;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],2)*pow(deltas[4],2);
  res->r += factor*lhs->e34455;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],3)*pow(deltas[4],2);
  res->r += factor*lhs->e44455;
  factor = pow(deltas[0],2)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],3);
  res->r += factor*lhs->e11555;
  factor = pow(deltas[0],1)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],3);
  res->r += factor*lhs->e12555;
  factor = pow(deltas[0],0)*pow(deltas[1],2)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],3);
  res->r += factor*lhs->e22555;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],0)*pow(deltas[4],3);
  res->r += factor*lhs->e13555;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],1)*pow(deltas[3],0)*pow(deltas[4],3);
  res->r += factor*lhs->e23555;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],2)*pow(deltas[3],0)*pow(deltas[4],3);
  res->r += factor*lhs->e33555;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],1)*pow(deltas[4],3);
  res->r += factor*lhs->e14555;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],1)*pow(deltas[4],3);
  res->r += factor*lhs->e24555;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],1)*pow(deltas[4],3);
  res->r += factor*lhs->e34555;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],2)*pow(deltas[4],3);
  res->r += factor*lhs->e44555;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],4);
  res->r += factor*lhs->e15555;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],4);
  res->r += factor*lhs->e25555;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],0)*pow(deltas[4],4);
  res->r += factor*lhs->e35555;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],1)*pow(deltas[4],4);
  res->r += factor*lhs->e45555;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],5);
  res->r += factor*lhs->e55555;

}

onumm5n5_t onumm5n5_truncate_im(imdir_t idx, ord_t order, onumm5n5_t* lhs){

  onumm5n5_t res;

  // Copy number.
  res = (*lhs);
  // Truncate all other values when necessary.
  // Real;
  switch (order){
    case 0:
      res = onumm5n5_init();
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
          res.e11111 = 0.0;
          res.e11112 = 0.0;
          res.e11122 = 0.0;
          res.e11222 = 0.0;
          res.e12222 = 0.0;
          res.e11113 = 0.0;
          res.e11123 = 0.0;
          res.e11223 = 0.0;
          res.e12223 = 0.0;
          res.e11133 = 0.0;
          res.e11233 = 0.0;
          res.e12233 = 0.0;
          res.e11333 = 0.0;
          res.e12333 = 0.0;
          res.e13333 = 0.0;
          res.e11114 = 0.0;
          res.e11124 = 0.0;
          res.e11224 = 0.0;
          res.e12224 = 0.0;
          res.e11134 = 0.0;
          res.e11234 = 0.0;
          res.e12234 = 0.0;
          res.e11334 = 0.0;
          res.e12334 = 0.0;
          res.e13334 = 0.0;
          res.e11144 = 0.0;
          res.e11244 = 0.0;
          res.e12244 = 0.0;
          res.e11344 = 0.0;
          res.e12344 = 0.0;
          res.e13344 = 0.0;
          res.e11444 = 0.0;
          res.e12444 = 0.0;
          res.e13444 = 0.0;
          res.e14444 = 0.0;
          res.e11115 = 0.0;
          res.e11125 = 0.0;
          res.e11225 = 0.0;
          res.e12225 = 0.0;
          res.e11135 = 0.0;
          res.e11235 = 0.0;
          res.e12235 = 0.0;
          res.e11335 = 0.0;
          res.e12335 = 0.0;
          res.e13335 = 0.0;
          res.e11145 = 0.0;
          res.e11245 = 0.0;
          res.e12245 = 0.0;
          res.e11345 = 0.0;
          res.e12345 = 0.0;
          res.e13345 = 0.0;
          res.e11445 = 0.0;
          res.e12445 = 0.0;
          res.e13445 = 0.0;
          res.e14445 = 0.0;
          res.e11155 = 0.0;
          res.e11255 = 0.0;
          res.e12255 = 0.0;
          res.e11355 = 0.0;
          res.e12355 = 0.0;
          res.e13355 = 0.0;
          res.e11455 = 0.0;
          res.e12455 = 0.0;
          res.e13455 = 0.0;
          res.e14455 = 0.0;
          res.e11555 = 0.0;
          res.e12555 = 0.0;
          res.e13555 = 0.0;
          res.e14555 = 0.0;
          res.e15555 = 0.0;
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
          res.e11112 = 0.0;
          res.e11122 = 0.0;
          res.e11222 = 0.0;
          res.e12222 = 0.0;
          res.e22222 = 0.0;
          res.e11123 = 0.0;
          res.e11223 = 0.0;
          res.e12223 = 0.0;
          res.e22223 = 0.0;
          res.e11233 = 0.0;
          res.e12233 = 0.0;
          res.e22233 = 0.0;
          res.e12333 = 0.0;
          res.e22333 = 0.0;
          res.e23333 = 0.0;
          res.e11124 = 0.0;
          res.e11224 = 0.0;
          res.e12224 = 0.0;
          res.e22224 = 0.0;
          res.e11234 = 0.0;
          res.e12234 = 0.0;
          res.e22234 = 0.0;
          res.e12334 = 0.0;
          res.e22334 = 0.0;
          res.e23334 = 0.0;
          res.e11244 = 0.0;
          res.e12244 = 0.0;
          res.e22244 = 0.0;
          res.e12344 = 0.0;
          res.e22344 = 0.0;
          res.e23344 = 0.0;
          res.e12444 = 0.0;
          res.e22444 = 0.0;
          res.e23444 = 0.0;
          res.e24444 = 0.0;
          res.e11125 = 0.0;
          res.e11225 = 0.0;
          res.e12225 = 0.0;
          res.e22225 = 0.0;
          res.e11235 = 0.0;
          res.e12235 = 0.0;
          res.e22235 = 0.0;
          res.e12335 = 0.0;
          res.e22335 = 0.0;
          res.e23335 = 0.0;
          res.e11245 = 0.0;
          res.e12245 = 0.0;
          res.e22245 = 0.0;
          res.e12345 = 0.0;
          res.e22345 = 0.0;
          res.e23345 = 0.0;
          res.e12445 = 0.0;
          res.e22445 = 0.0;
          res.e23445 = 0.0;
          res.e24445 = 0.0;
          res.e11255 = 0.0;
          res.e12255 = 0.0;
          res.e22255 = 0.0;
          res.e12355 = 0.0;
          res.e22355 = 0.0;
          res.e23355 = 0.0;
          res.e12455 = 0.0;
          res.e22455 = 0.0;
          res.e23455 = 0.0;
          res.e24455 = 0.0;
          res.e12555 = 0.0;
          res.e22555 = 0.0;
          res.e23555 = 0.0;
          res.e24555 = 0.0;
          res.e25555 = 0.0;
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
          res.e11113 = 0.0;
          res.e11123 = 0.0;
          res.e11223 = 0.0;
          res.e12223 = 0.0;
          res.e22223 = 0.0;
          res.e11133 = 0.0;
          res.e11233 = 0.0;
          res.e12233 = 0.0;
          res.e22233 = 0.0;
          res.e11333 = 0.0;
          res.e12333 = 0.0;
          res.e22333 = 0.0;
          res.e13333 = 0.0;
          res.e23333 = 0.0;
          res.e33333 = 0.0;
          res.e11134 = 0.0;
          res.e11234 = 0.0;
          res.e12234 = 0.0;
          res.e22234 = 0.0;
          res.e11334 = 0.0;
          res.e12334 = 0.0;
          res.e22334 = 0.0;
          res.e13334 = 0.0;
          res.e23334 = 0.0;
          res.e33334 = 0.0;
          res.e11344 = 0.0;
          res.e12344 = 0.0;
          res.e22344 = 0.0;
          res.e13344 = 0.0;
          res.e23344 = 0.0;
          res.e33344 = 0.0;
          res.e13444 = 0.0;
          res.e23444 = 0.0;
          res.e33444 = 0.0;
          res.e34444 = 0.0;
          res.e11135 = 0.0;
          res.e11235 = 0.0;
          res.e12235 = 0.0;
          res.e22235 = 0.0;
          res.e11335 = 0.0;
          res.e12335 = 0.0;
          res.e22335 = 0.0;
          res.e13335 = 0.0;
          res.e23335 = 0.0;
          res.e33335 = 0.0;
          res.e11345 = 0.0;
          res.e12345 = 0.0;
          res.e22345 = 0.0;
          res.e13345 = 0.0;
          res.e23345 = 0.0;
          res.e33345 = 0.0;
          res.e13445 = 0.0;
          res.e23445 = 0.0;
          res.e33445 = 0.0;
          res.e34445 = 0.0;
          res.e11355 = 0.0;
          res.e12355 = 0.0;
          res.e22355 = 0.0;
          res.e13355 = 0.0;
          res.e23355 = 0.0;
          res.e33355 = 0.0;
          res.e13455 = 0.0;
          res.e23455 = 0.0;
          res.e33455 = 0.0;
          res.e34455 = 0.0;
          res.e13555 = 0.0;
          res.e23555 = 0.0;
          res.e33555 = 0.0;
          res.e34555 = 0.0;
          res.e35555 = 0.0;
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
          res.e11114 = 0.0;
          res.e11124 = 0.0;
          res.e11224 = 0.0;
          res.e12224 = 0.0;
          res.e22224 = 0.0;
          res.e11134 = 0.0;
          res.e11234 = 0.0;
          res.e12234 = 0.0;
          res.e22234 = 0.0;
          res.e11334 = 0.0;
          res.e12334 = 0.0;
          res.e22334 = 0.0;
          res.e13334 = 0.0;
          res.e23334 = 0.0;
          res.e33334 = 0.0;
          res.e11144 = 0.0;
          res.e11244 = 0.0;
          res.e12244 = 0.0;
          res.e22244 = 0.0;
          res.e11344 = 0.0;
          res.e12344 = 0.0;
          res.e22344 = 0.0;
          res.e13344 = 0.0;
          res.e23344 = 0.0;
          res.e33344 = 0.0;
          res.e11444 = 0.0;
          res.e12444 = 0.0;
          res.e22444 = 0.0;
          res.e13444 = 0.0;
          res.e23444 = 0.0;
          res.e33444 = 0.0;
          res.e14444 = 0.0;
          res.e24444 = 0.0;
          res.e34444 = 0.0;
          res.e44444 = 0.0;
          res.e11145 = 0.0;
          res.e11245 = 0.0;
          res.e12245 = 0.0;
          res.e22245 = 0.0;
          res.e11345 = 0.0;
          res.e12345 = 0.0;
          res.e22345 = 0.0;
          res.e13345 = 0.0;
          res.e23345 = 0.0;
          res.e33345 = 0.0;
          res.e11445 = 0.0;
          res.e12445 = 0.0;
          res.e22445 = 0.0;
          res.e13445 = 0.0;
          res.e23445 = 0.0;
          res.e33445 = 0.0;
          res.e14445 = 0.0;
          res.e24445 = 0.0;
          res.e34445 = 0.0;
          res.e44445 = 0.0;
          res.e11455 = 0.0;
          res.e12455 = 0.0;
          res.e22455 = 0.0;
          res.e13455 = 0.0;
          res.e23455 = 0.0;
          res.e33455 = 0.0;
          res.e14455 = 0.0;
          res.e24455 = 0.0;
          res.e34455 = 0.0;
          res.e44455 = 0.0;
          res.e14555 = 0.0;
          res.e24555 = 0.0;
          res.e34555 = 0.0;
          res.e44555 = 0.0;
          res.e45555 = 0.0;
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
          res.e11115 = 0.0;
          res.e11125 = 0.0;
          res.e11225 = 0.0;
          res.e12225 = 0.0;
          res.e22225 = 0.0;
          res.e11135 = 0.0;
          res.e11235 = 0.0;
          res.e12235 = 0.0;
          res.e22235 = 0.0;
          res.e11335 = 0.0;
          res.e12335 = 0.0;
          res.e22335 = 0.0;
          res.e13335 = 0.0;
          res.e23335 = 0.0;
          res.e33335 = 0.0;
          res.e11145 = 0.0;
          res.e11245 = 0.0;
          res.e12245 = 0.0;
          res.e22245 = 0.0;
          res.e11345 = 0.0;
          res.e12345 = 0.0;
          res.e22345 = 0.0;
          res.e13345 = 0.0;
          res.e23345 = 0.0;
          res.e33345 = 0.0;
          res.e11445 = 0.0;
          res.e12445 = 0.0;
          res.e22445 = 0.0;
          res.e13445 = 0.0;
          res.e23445 = 0.0;
          res.e33445 = 0.0;
          res.e14445 = 0.0;
          res.e24445 = 0.0;
          res.e34445 = 0.0;
          res.e44445 = 0.0;
          res.e11155 = 0.0;
          res.e11255 = 0.0;
          res.e12255 = 0.0;
          res.e22255 = 0.0;
          res.e11355 = 0.0;
          res.e12355 = 0.0;
          res.e22355 = 0.0;
          res.e13355 = 0.0;
          res.e23355 = 0.0;
          res.e33355 = 0.0;
          res.e11455 = 0.0;
          res.e12455 = 0.0;
          res.e22455 = 0.0;
          res.e13455 = 0.0;
          res.e23455 = 0.0;
          res.e33455 = 0.0;
          res.e14455 = 0.0;
          res.e24455 = 0.0;
          res.e34455 = 0.0;
          res.e44455 = 0.0;
          res.e11555 = 0.0;
          res.e12555 = 0.0;
          res.e22555 = 0.0;
          res.e13555 = 0.0;
          res.e23555 = 0.0;
          res.e33555 = 0.0;
          res.e14555 = 0.0;
          res.e24555 = 0.0;
          res.e34555 = 0.0;
          res.e44555 = 0.0;
          res.e15555 = 0.0;
          res.e25555 = 0.0;
          res.e35555 = 0.0;
          res.e45555 = 0.0;
          res.e55555 = 0.0;
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
          res.e11111 = 0.0;
          res.e11112 = 0.0;
          res.e11122 = 0.0;
          res.e11222 = 0.0;
          res.e11113 = 0.0;
          res.e11123 = 0.0;
          res.e11223 = 0.0;
          res.e11133 = 0.0;
          res.e11233 = 0.0;
          res.e11333 = 0.0;
          res.e11114 = 0.0;
          res.e11124 = 0.0;
          res.e11224 = 0.0;
          res.e11134 = 0.0;
          res.e11234 = 0.0;
          res.e11334 = 0.0;
          res.e11144 = 0.0;
          res.e11244 = 0.0;
          res.e11344 = 0.0;
          res.e11444 = 0.0;
          res.e11115 = 0.0;
          res.e11125 = 0.0;
          res.e11225 = 0.0;
          res.e11135 = 0.0;
          res.e11235 = 0.0;
          res.e11335 = 0.0;
          res.e11145 = 0.0;
          res.e11245 = 0.0;
          res.e11345 = 0.0;
          res.e11445 = 0.0;
          res.e11155 = 0.0;
          res.e11255 = 0.0;
          res.e11355 = 0.0;
          res.e11455 = 0.0;
          res.e11555 = 0.0;
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
          res.e11112 = 0.0;
          res.e11122 = 0.0;
          res.e11222 = 0.0;
          res.e12222 = 0.0;
          res.e11123 = 0.0;
          res.e11223 = 0.0;
          res.e12223 = 0.0;
          res.e11233 = 0.0;
          res.e12233 = 0.0;
          res.e12333 = 0.0;
          res.e11124 = 0.0;
          res.e11224 = 0.0;
          res.e12224 = 0.0;
          res.e11234 = 0.0;
          res.e12234 = 0.0;
          res.e12334 = 0.0;
          res.e11244 = 0.0;
          res.e12244 = 0.0;
          res.e12344 = 0.0;
          res.e12444 = 0.0;
          res.e11125 = 0.0;
          res.e11225 = 0.0;
          res.e12225 = 0.0;
          res.e11235 = 0.0;
          res.e12235 = 0.0;
          res.e12335 = 0.0;
          res.e11245 = 0.0;
          res.e12245 = 0.0;
          res.e12345 = 0.0;
          res.e12445 = 0.0;
          res.e11255 = 0.0;
          res.e12255 = 0.0;
          res.e12355 = 0.0;
          res.e12455 = 0.0;
          res.e12555 = 0.0;
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
          res.e11122 = 0.0;
          res.e11222 = 0.0;
          res.e12222 = 0.0;
          res.e22222 = 0.0;
          res.e11223 = 0.0;
          res.e12223 = 0.0;
          res.e22223 = 0.0;
          res.e12233 = 0.0;
          res.e22233 = 0.0;
          res.e22333 = 0.0;
          res.e11224 = 0.0;
          res.e12224 = 0.0;
          res.e22224 = 0.0;
          res.e12234 = 0.0;
          res.e22234 = 0.0;
          res.e22334 = 0.0;
          res.e12244 = 0.0;
          res.e22244 = 0.0;
          res.e22344 = 0.0;
          res.e22444 = 0.0;
          res.e11225 = 0.0;
          res.e12225 = 0.0;
          res.e22225 = 0.0;
          res.e12235 = 0.0;
          res.e22235 = 0.0;
          res.e22335 = 0.0;
          res.e12245 = 0.0;
          res.e22245 = 0.0;
          res.e22345 = 0.0;
          res.e22445 = 0.0;
          res.e12255 = 0.0;
          res.e22255 = 0.0;
          res.e22355 = 0.0;
          res.e22455 = 0.0;
          res.e22555 = 0.0;
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
          res.e11113 = 0.0;
          res.e11123 = 0.0;
          res.e11223 = 0.0;
          res.e12223 = 0.0;
          res.e11133 = 0.0;
          res.e11233 = 0.0;
          res.e12233 = 0.0;
          res.e11333 = 0.0;
          res.e12333 = 0.0;
          res.e13333 = 0.0;
          res.e11134 = 0.0;
          res.e11234 = 0.0;
          res.e12234 = 0.0;
          res.e11334 = 0.0;
          res.e12334 = 0.0;
          res.e13334 = 0.0;
          res.e11344 = 0.0;
          res.e12344 = 0.0;
          res.e13344 = 0.0;
          res.e13444 = 0.0;
          res.e11135 = 0.0;
          res.e11235 = 0.0;
          res.e12235 = 0.0;
          res.e11335 = 0.0;
          res.e12335 = 0.0;
          res.e13335 = 0.0;
          res.e11345 = 0.0;
          res.e12345 = 0.0;
          res.e13345 = 0.0;
          res.e13445 = 0.0;
          res.e11355 = 0.0;
          res.e12355 = 0.0;
          res.e13355 = 0.0;
          res.e13455 = 0.0;
          res.e13555 = 0.0;
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
          res.e11123 = 0.0;
          res.e11223 = 0.0;
          res.e12223 = 0.0;
          res.e22223 = 0.0;
          res.e11233 = 0.0;
          res.e12233 = 0.0;
          res.e22233 = 0.0;
          res.e12333 = 0.0;
          res.e22333 = 0.0;
          res.e23333 = 0.0;
          res.e11234 = 0.0;
          res.e12234 = 0.0;
          res.e22234 = 0.0;
          res.e12334 = 0.0;
          res.e22334 = 0.0;
          res.e23334 = 0.0;
          res.e12344 = 0.0;
          res.e22344 = 0.0;
          res.e23344 = 0.0;
          res.e23444 = 0.0;
          res.e11235 = 0.0;
          res.e12235 = 0.0;
          res.e22235 = 0.0;
          res.e12335 = 0.0;
          res.e22335 = 0.0;
          res.e23335 = 0.0;
          res.e12345 = 0.0;
          res.e22345 = 0.0;
          res.e23345 = 0.0;
          res.e23445 = 0.0;
          res.e12355 = 0.0;
          res.e22355 = 0.0;
          res.e23355 = 0.0;
          res.e23455 = 0.0;
          res.e23555 = 0.0;
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
          res.e11133 = 0.0;
          res.e11233 = 0.0;
          res.e12233 = 0.0;
          res.e22233 = 0.0;
          res.e11333 = 0.0;
          res.e12333 = 0.0;
          res.e22333 = 0.0;
          res.e13333 = 0.0;
          res.e23333 = 0.0;
          res.e33333 = 0.0;
          res.e11334 = 0.0;
          res.e12334 = 0.0;
          res.e22334 = 0.0;
          res.e13334 = 0.0;
          res.e23334 = 0.0;
          res.e33334 = 0.0;
          res.e13344 = 0.0;
          res.e23344 = 0.0;
          res.e33344 = 0.0;
          res.e33444 = 0.0;
          res.e11335 = 0.0;
          res.e12335 = 0.0;
          res.e22335 = 0.0;
          res.e13335 = 0.0;
          res.e23335 = 0.0;
          res.e33335 = 0.0;
          res.e13345 = 0.0;
          res.e23345 = 0.0;
          res.e33345 = 0.0;
          res.e33445 = 0.0;
          res.e13355 = 0.0;
          res.e23355 = 0.0;
          res.e33355 = 0.0;
          res.e33455 = 0.0;
          res.e33555 = 0.0;
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
          res.e11114 = 0.0;
          res.e11124 = 0.0;
          res.e11224 = 0.0;
          res.e12224 = 0.0;
          res.e11134 = 0.0;
          res.e11234 = 0.0;
          res.e12234 = 0.0;
          res.e11334 = 0.0;
          res.e12334 = 0.0;
          res.e13334 = 0.0;
          res.e11144 = 0.0;
          res.e11244 = 0.0;
          res.e12244 = 0.0;
          res.e11344 = 0.0;
          res.e12344 = 0.0;
          res.e13344 = 0.0;
          res.e11444 = 0.0;
          res.e12444 = 0.0;
          res.e13444 = 0.0;
          res.e14444 = 0.0;
          res.e11145 = 0.0;
          res.e11245 = 0.0;
          res.e12245 = 0.0;
          res.e11345 = 0.0;
          res.e12345 = 0.0;
          res.e13345 = 0.0;
          res.e11445 = 0.0;
          res.e12445 = 0.0;
          res.e13445 = 0.0;
          res.e14445 = 0.0;
          res.e11455 = 0.0;
          res.e12455 = 0.0;
          res.e13455 = 0.0;
          res.e14455 = 0.0;
          res.e14555 = 0.0;
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
          res.e11124 = 0.0;
          res.e11224 = 0.0;
          res.e12224 = 0.0;
          res.e22224 = 0.0;
          res.e11234 = 0.0;
          res.e12234 = 0.0;
          res.e22234 = 0.0;
          res.e12334 = 0.0;
          res.e22334 = 0.0;
          res.e23334 = 0.0;
          res.e11244 = 0.0;
          res.e12244 = 0.0;
          res.e22244 = 0.0;
          res.e12344 = 0.0;
          res.e22344 = 0.0;
          res.e23344 = 0.0;
          res.e12444 = 0.0;
          res.e22444 = 0.0;
          res.e23444 = 0.0;
          res.e24444 = 0.0;
          res.e11245 = 0.0;
          res.e12245 = 0.0;
          res.e22245 = 0.0;
          res.e12345 = 0.0;
          res.e22345 = 0.0;
          res.e23345 = 0.0;
          res.e12445 = 0.0;
          res.e22445 = 0.0;
          res.e23445 = 0.0;
          res.e24445 = 0.0;
          res.e12455 = 0.0;
          res.e22455 = 0.0;
          res.e23455 = 0.0;
          res.e24455 = 0.0;
          res.e24555 = 0.0;
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
          res.e11134 = 0.0;
          res.e11234 = 0.0;
          res.e12234 = 0.0;
          res.e22234 = 0.0;
          res.e11334 = 0.0;
          res.e12334 = 0.0;
          res.e22334 = 0.0;
          res.e13334 = 0.0;
          res.e23334 = 0.0;
          res.e33334 = 0.0;
          res.e11344 = 0.0;
          res.e12344 = 0.0;
          res.e22344 = 0.0;
          res.e13344 = 0.0;
          res.e23344 = 0.0;
          res.e33344 = 0.0;
          res.e13444 = 0.0;
          res.e23444 = 0.0;
          res.e33444 = 0.0;
          res.e34444 = 0.0;
          res.e11345 = 0.0;
          res.e12345 = 0.0;
          res.e22345 = 0.0;
          res.e13345 = 0.0;
          res.e23345 = 0.0;
          res.e33345 = 0.0;
          res.e13445 = 0.0;
          res.e23445 = 0.0;
          res.e33445 = 0.0;
          res.e34445 = 0.0;
          res.e13455 = 0.0;
          res.e23455 = 0.0;
          res.e33455 = 0.0;
          res.e34455 = 0.0;
          res.e34555 = 0.0;
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
          res.e11144 = 0.0;
          res.e11244 = 0.0;
          res.e12244 = 0.0;
          res.e22244 = 0.0;
          res.e11344 = 0.0;
          res.e12344 = 0.0;
          res.e22344 = 0.0;
          res.e13344 = 0.0;
          res.e23344 = 0.0;
          res.e33344 = 0.0;
          res.e11444 = 0.0;
          res.e12444 = 0.0;
          res.e22444 = 0.0;
          res.e13444 = 0.0;
          res.e23444 = 0.0;
          res.e33444 = 0.0;
          res.e14444 = 0.0;
          res.e24444 = 0.0;
          res.e34444 = 0.0;
          res.e44444 = 0.0;
          res.e11445 = 0.0;
          res.e12445 = 0.0;
          res.e22445 = 0.0;
          res.e13445 = 0.0;
          res.e23445 = 0.0;
          res.e33445 = 0.0;
          res.e14445 = 0.0;
          res.e24445 = 0.0;
          res.e34445 = 0.0;
          res.e44445 = 0.0;
          res.e14455 = 0.0;
          res.e24455 = 0.0;
          res.e34455 = 0.0;
          res.e44455 = 0.0;
          res.e44555 = 0.0;
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
          res.e11115 = 0.0;
          res.e11125 = 0.0;
          res.e11225 = 0.0;
          res.e12225 = 0.0;
          res.e11135 = 0.0;
          res.e11235 = 0.0;
          res.e12235 = 0.0;
          res.e11335 = 0.0;
          res.e12335 = 0.0;
          res.e13335 = 0.0;
          res.e11145 = 0.0;
          res.e11245 = 0.0;
          res.e12245 = 0.0;
          res.e11345 = 0.0;
          res.e12345 = 0.0;
          res.e13345 = 0.0;
          res.e11445 = 0.0;
          res.e12445 = 0.0;
          res.e13445 = 0.0;
          res.e14445 = 0.0;
          res.e11155 = 0.0;
          res.e11255 = 0.0;
          res.e12255 = 0.0;
          res.e11355 = 0.0;
          res.e12355 = 0.0;
          res.e13355 = 0.0;
          res.e11455 = 0.0;
          res.e12455 = 0.0;
          res.e13455 = 0.0;
          res.e14455 = 0.0;
          res.e11555 = 0.0;
          res.e12555 = 0.0;
          res.e13555 = 0.0;
          res.e14555 = 0.0;
          res.e15555 = 0.0;
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
          res.e11125 = 0.0;
          res.e11225 = 0.0;
          res.e12225 = 0.0;
          res.e22225 = 0.0;
          res.e11235 = 0.0;
          res.e12235 = 0.0;
          res.e22235 = 0.0;
          res.e12335 = 0.0;
          res.e22335 = 0.0;
          res.e23335 = 0.0;
          res.e11245 = 0.0;
          res.e12245 = 0.0;
          res.e22245 = 0.0;
          res.e12345 = 0.0;
          res.e22345 = 0.0;
          res.e23345 = 0.0;
          res.e12445 = 0.0;
          res.e22445 = 0.0;
          res.e23445 = 0.0;
          res.e24445 = 0.0;
          res.e11255 = 0.0;
          res.e12255 = 0.0;
          res.e22255 = 0.0;
          res.e12355 = 0.0;
          res.e22355 = 0.0;
          res.e23355 = 0.0;
          res.e12455 = 0.0;
          res.e22455 = 0.0;
          res.e23455 = 0.0;
          res.e24455 = 0.0;
          res.e12555 = 0.0;
          res.e22555 = 0.0;
          res.e23555 = 0.0;
          res.e24555 = 0.0;
          res.e25555 = 0.0;
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
          res.e11135 = 0.0;
          res.e11235 = 0.0;
          res.e12235 = 0.0;
          res.e22235 = 0.0;
          res.e11335 = 0.0;
          res.e12335 = 0.0;
          res.e22335 = 0.0;
          res.e13335 = 0.0;
          res.e23335 = 0.0;
          res.e33335 = 0.0;
          res.e11345 = 0.0;
          res.e12345 = 0.0;
          res.e22345 = 0.0;
          res.e13345 = 0.0;
          res.e23345 = 0.0;
          res.e33345 = 0.0;
          res.e13445 = 0.0;
          res.e23445 = 0.0;
          res.e33445 = 0.0;
          res.e34445 = 0.0;
          res.e11355 = 0.0;
          res.e12355 = 0.0;
          res.e22355 = 0.0;
          res.e13355 = 0.0;
          res.e23355 = 0.0;
          res.e33355 = 0.0;
          res.e13455 = 0.0;
          res.e23455 = 0.0;
          res.e33455 = 0.0;
          res.e34455 = 0.0;
          res.e13555 = 0.0;
          res.e23555 = 0.0;
          res.e33555 = 0.0;
          res.e34555 = 0.0;
          res.e35555 = 0.0;
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
          res.e11145 = 0.0;
          res.e11245 = 0.0;
          res.e12245 = 0.0;
          res.e22245 = 0.0;
          res.e11345 = 0.0;
          res.e12345 = 0.0;
          res.e22345 = 0.0;
          res.e13345 = 0.0;
          res.e23345 = 0.0;
          res.e33345 = 0.0;
          res.e11445 = 0.0;
          res.e12445 = 0.0;
          res.e22445 = 0.0;
          res.e13445 = 0.0;
          res.e23445 = 0.0;
          res.e33445 = 0.0;
          res.e14445 = 0.0;
          res.e24445 = 0.0;
          res.e34445 = 0.0;
          res.e44445 = 0.0;
          res.e11455 = 0.0;
          res.e12455 = 0.0;
          res.e22455 = 0.0;
          res.e13455 = 0.0;
          res.e23455 = 0.0;
          res.e33455 = 0.0;
          res.e14455 = 0.0;
          res.e24455 = 0.0;
          res.e34455 = 0.0;
          res.e44455 = 0.0;
          res.e14555 = 0.0;
          res.e24555 = 0.0;
          res.e34555 = 0.0;
          res.e44555 = 0.0;
          res.e45555 = 0.0;
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
          res.e11155 = 0.0;
          res.e11255 = 0.0;
          res.e12255 = 0.0;
          res.e22255 = 0.0;
          res.e11355 = 0.0;
          res.e12355 = 0.0;
          res.e22355 = 0.0;
          res.e13355 = 0.0;
          res.e23355 = 0.0;
          res.e33355 = 0.0;
          res.e11455 = 0.0;
          res.e12455 = 0.0;
          res.e22455 = 0.0;
          res.e13455 = 0.0;
          res.e23455 = 0.0;
          res.e33455 = 0.0;
          res.e14455 = 0.0;
          res.e24455 = 0.0;
          res.e34455 = 0.0;
          res.e44455 = 0.0;
          res.e11555 = 0.0;
          res.e12555 = 0.0;
          res.e22555 = 0.0;
          res.e13555 = 0.0;
          res.e23555 = 0.0;
          res.e33555 = 0.0;
          res.e14555 = 0.0;
          res.e24555 = 0.0;
          res.e34555 = 0.0;
          res.e44555 = 0.0;
          res.e15555 = 0.0;
          res.e25555 = 0.0;
          res.e35555 = 0.0;
          res.e45555 = 0.0;
          res.e55555 = 0.0;
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
          res.e11111 = 0.0;
          res.e11112 = 0.0;
          res.e11122 = 0.0;
          res.e11113 = 0.0;
          res.e11123 = 0.0;
          res.e11133 = 0.0;
          res.e11114 = 0.0;
          res.e11124 = 0.0;
          res.e11134 = 0.0;
          res.e11144 = 0.0;
          res.e11115 = 0.0;
          res.e11125 = 0.0;
          res.e11135 = 0.0;
          res.e11145 = 0.0;
          res.e11155 = 0.0;
          break;
        case 1: //  e112
          res.e112 = 0.0;
          res.e1112 = 0.0;
          res.e1122 = 0.0;
          res.e1123 = 0.0;
          res.e1124 = 0.0;
          res.e1125 = 0.0;
          res.e11112 = 0.0;
          res.e11122 = 0.0;
          res.e11222 = 0.0;
          res.e11123 = 0.0;
          res.e11223 = 0.0;
          res.e11233 = 0.0;
          res.e11124 = 0.0;
          res.e11224 = 0.0;
          res.e11234 = 0.0;
          res.e11244 = 0.0;
          res.e11125 = 0.0;
          res.e11225 = 0.0;
          res.e11235 = 0.0;
          res.e11245 = 0.0;
          res.e11255 = 0.0;
          break;
        case 2: //  e122
          res.e122 = 0.0;
          res.e1122 = 0.0;
          res.e1222 = 0.0;
          res.e1223 = 0.0;
          res.e1224 = 0.0;
          res.e1225 = 0.0;
          res.e11122 = 0.0;
          res.e11222 = 0.0;
          res.e12222 = 0.0;
          res.e11223 = 0.0;
          res.e12223 = 0.0;
          res.e12233 = 0.0;
          res.e11224 = 0.0;
          res.e12224 = 0.0;
          res.e12234 = 0.0;
          res.e12244 = 0.0;
          res.e11225 = 0.0;
          res.e12225 = 0.0;
          res.e12235 = 0.0;
          res.e12245 = 0.0;
          res.e12255 = 0.0;
          break;
        case 3: //  e222
          res.e222 = 0.0;
          res.e1222 = 0.0;
          res.e2222 = 0.0;
          res.e2223 = 0.0;
          res.e2224 = 0.0;
          res.e2225 = 0.0;
          res.e11222 = 0.0;
          res.e12222 = 0.0;
          res.e22222 = 0.0;
          res.e12223 = 0.0;
          res.e22223 = 0.0;
          res.e22233 = 0.0;
          res.e12224 = 0.0;
          res.e22224 = 0.0;
          res.e22234 = 0.0;
          res.e22244 = 0.0;
          res.e12225 = 0.0;
          res.e22225 = 0.0;
          res.e22235 = 0.0;
          res.e22245 = 0.0;
          res.e22255 = 0.0;
          break;
        case 4: //  e113
          res.e113 = 0.0;
          res.e1113 = 0.0;
          res.e1123 = 0.0;
          res.e1133 = 0.0;
          res.e1134 = 0.0;
          res.e1135 = 0.0;
          res.e11113 = 0.0;
          res.e11123 = 0.0;
          res.e11223 = 0.0;
          res.e11133 = 0.0;
          res.e11233 = 0.0;
          res.e11333 = 0.0;
          res.e11134 = 0.0;
          res.e11234 = 0.0;
          res.e11334 = 0.0;
          res.e11344 = 0.0;
          res.e11135 = 0.0;
          res.e11235 = 0.0;
          res.e11335 = 0.0;
          res.e11345 = 0.0;
          res.e11355 = 0.0;
          break;
        case 5: //  e123
          res.e123 = 0.0;
          res.e1123 = 0.0;
          res.e1223 = 0.0;
          res.e1233 = 0.0;
          res.e1234 = 0.0;
          res.e1235 = 0.0;
          res.e11123 = 0.0;
          res.e11223 = 0.0;
          res.e12223 = 0.0;
          res.e11233 = 0.0;
          res.e12233 = 0.0;
          res.e12333 = 0.0;
          res.e11234 = 0.0;
          res.e12234 = 0.0;
          res.e12334 = 0.0;
          res.e12344 = 0.0;
          res.e11235 = 0.0;
          res.e12235 = 0.0;
          res.e12335 = 0.0;
          res.e12345 = 0.0;
          res.e12355 = 0.0;
          break;
        case 6: //  e223
          res.e223 = 0.0;
          res.e1223 = 0.0;
          res.e2223 = 0.0;
          res.e2233 = 0.0;
          res.e2234 = 0.0;
          res.e2235 = 0.0;
          res.e11223 = 0.0;
          res.e12223 = 0.0;
          res.e22223 = 0.0;
          res.e12233 = 0.0;
          res.e22233 = 0.0;
          res.e22333 = 0.0;
          res.e12234 = 0.0;
          res.e22234 = 0.0;
          res.e22334 = 0.0;
          res.e22344 = 0.0;
          res.e12235 = 0.0;
          res.e22235 = 0.0;
          res.e22335 = 0.0;
          res.e22345 = 0.0;
          res.e22355 = 0.0;
          break;
        case 7: //  e133
          res.e133 = 0.0;
          res.e1133 = 0.0;
          res.e1233 = 0.0;
          res.e1333 = 0.0;
          res.e1334 = 0.0;
          res.e1335 = 0.0;
          res.e11133 = 0.0;
          res.e11233 = 0.0;
          res.e12233 = 0.0;
          res.e11333 = 0.0;
          res.e12333 = 0.0;
          res.e13333 = 0.0;
          res.e11334 = 0.0;
          res.e12334 = 0.0;
          res.e13334 = 0.0;
          res.e13344 = 0.0;
          res.e11335 = 0.0;
          res.e12335 = 0.0;
          res.e13335 = 0.0;
          res.e13345 = 0.0;
          res.e13355 = 0.0;
          break;
        case 8: //  e233
          res.e233 = 0.0;
          res.e1233 = 0.0;
          res.e2233 = 0.0;
          res.e2333 = 0.0;
          res.e2334 = 0.0;
          res.e2335 = 0.0;
          res.e11233 = 0.0;
          res.e12233 = 0.0;
          res.e22233 = 0.0;
          res.e12333 = 0.0;
          res.e22333 = 0.0;
          res.e23333 = 0.0;
          res.e12334 = 0.0;
          res.e22334 = 0.0;
          res.e23334 = 0.0;
          res.e23344 = 0.0;
          res.e12335 = 0.0;
          res.e22335 = 0.0;
          res.e23335 = 0.0;
          res.e23345 = 0.0;
          res.e23355 = 0.0;
          break;
        case 9: //  e333
          res.e333 = 0.0;
          res.e1333 = 0.0;
          res.e2333 = 0.0;
          res.e3333 = 0.0;
          res.e3334 = 0.0;
          res.e3335 = 0.0;
          res.e11333 = 0.0;
          res.e12333 = 0.0;
          res.e22333 = 0.0;
          res.e13333 = 0.0;
          res.e23333 = 0.0;
          res.e33333 = 0.0;
          res.e13334 = 0.0;
          res.e23334 = 0.0;
          res.e33334 = 0.0;
          res.e33344 = 0.0;
          res.e13335 = 0.0;
          res.e23335 = 0.0;
          res.e33335 = 0.0;
          res.e33345 = 0.0;
          res.e33355 = 0.0;
          break;
        case 10: //  e114
          res.e114 = 0.0;
          res.e1114 = 0.0;
          res.e1124 = 0.0;
          res.e1134 = 0.0;
          res.e1144 = 0.0;
          res.e1145 = 0.0;
          res.e11114 = 0.0;
          res.e11124 = 0.0;
          res.e11224 = 0.0;
          res.e11134 = 0.0;
          res.e11234 = 0.0;
          res.e11334 = 0.0;
          res.e11144 = 0.0;
          res.e11244 = 0.0;
          res.e11344 = 0.0;
          res.e11444 = 0.0;
          res.e11145 = 0.0;
          res.e11245 = 0.0;
          res.e11345 = 0.0;
          res.e11445 = 0.0;
          res.e11455 = 0.0;
          break;
        case 11: //  e124
          res.e124 = 0.0;
          res.e1124 = 0.0;
          res.e1224 = 0.0;
          res.e1234 = 0.0;
          res.e1244 = 0.0;
          res.e1245 = 0.0;
          res.e11124 = 0.0;
          res.e11224 = 0.0;
          res.e12224 = 0.0;
          res.e11234 = 0.0;
          res.e12234 = 0.0;
          res.e12334 = 0.0;
          res.e11244 = 0.0;
          res.e12244 = 0.0;
          res.e12344 = 0.0;
          res.e12444 = 0.0;
          res.e11245 = 0.0;
          res.e12245 = 0.0;
          res.e12345 = 0.0;
          res.e12445 = 0.0;
          res.e12455 = 0.0;
          break;
        case 12: //  e224
          res.e224 = 0.0;
          res.e1224 = 0.0;
          res.e2224 = 0.0;
          res.e2234 = 0.0;
          res.e2244 = 0.0;
          res.e2245 = 0.0;
          res.e11224 = 0.0;
          res.e12224 = 0.0;
          res.e22224 = 0.0;
          res.e12234 = 0.0;
          res.e22234 = 0.0;
          res.e22334 = 0.0;
          res.e12244 = 0.0;
          res.e22244 = 0.0;
          res.e22344 = 0.0;
          res.e22444 = 0.0;
          res.e12245 = 0.0;
          res.e22245 = 0.0;
          res.e22345 = 0.0;
          res.e22445 = 0.0;
          res.e22455 = 0.0;
          break;
        case 13: //  e134
          res.e134 = 0.0;
          res.e1134 = 0.0;
          res.e1234 = 0.0;
          res.e1334 = 0.0;
          res.e1344 = 0.0;
          res.e1345 = 0.0;
          res.e11134 = 0.0;
          res.e11234 = 0.0;
          res.e12234 = 0.0;
          res.e11334 = 0.0;
          res.e12334 = 0.0;
          res.e13334 = 0.0;
          res.e11344 = 0.0;
          res.e12344 = 0.0;
          res.e13344 = 0.0;
          res.e13444 = 0.0;
          res.e11345 = 0.0;
          res.e12345 = 0.0;
          res.e13345 = 0.0;
          res.e13445 = 0.0;
          res.e13455 = 0.0;
          break;
        case 14: //  e234
          res.e234 = 0.0;
          res.e1234 = 0.0;
          res.e2234 = 0.0;
          res.e2334 = 0.0;
          res.e2344 = 0.0;
          res.e2345 = 0.0;
          res.e11234 = 0.0;
          res.e12234 = 0.0;
          res.e22234 = 0.0;
          res.e12334 = 0.0;
          res.e22334 = 0.0;
          res.e23334 = 0.0;
          res.e12344 = 0.0;
          res.e22344 = 0.0;
          res.e23344 = 0.0;
          res.e23444 = 0.0;
          res.e12345 = 0.0;
          res.e22345 = 0.0;
          res.e23345 = 0.0;
          res.e23445 = 0.0;
          res.e23455 = 0.0;
          break;
        case 15: //  e334
          res.e334 = 0.0;
          res.e1334 = 0.0;
          res.e2334 = 0.0;
          res.e3334 = 0.0;
          res.e3344 = 0.0;
          res.e3345 = 0.0;
          res.e11334 = 0.0;
          res.e12334 = 0.0;
          res.e22334 = 0.0;
          res.e13334 = 0.0;
          res.e23334 = 0.0;
          res.e33334 = 0.0;
          res.e13344 = 0.0;
          res.e23344 = 0.0;
          res.e33344 = 0.0;
          res.e33444 = 0.0;
          res.e13345 = 0.0;
          res.e23345 = 0.0;
          res.e33345 = 0.0;
          res.e33445 = 0.0;
          res.e33455 = 0.0;
          break;
        case 16: //  e144
          res.e144 = 0.0;
          res.e1144 = 0.0;
          res.e1244 = 0.0;
          res.e1344 = 0.0;
          res.e1444 = 0.0;
          res.e1445 = 0.0;
          res.e11144 = 0.0;
          res.e11244 = 0.0;
          res.e12244 = 0.0;
          res.e11344 = 0.0;
          res.e12344 = 0.0;
          res.e13344 = 0.0;
          res.e11444 = 0.0;
          res.e12444 = 0.0;
          res.e13444 = 0.0;
          res.e14444 = 0.0;
          res.e11445 = 0.0;
          res.e12445 = 0.0;
          res.e13445 = 0.0;
          res.e14445 = 0.0;
          res.e14455 = 0.0;
          break;
        case 17: //  e244
          res.e244 = 0.0;
          res.e1244 = 0.0;
          res.e2244 = 0.0;
          res.e2344 = 0.0;
          res.e2444 = 0.0;
          res.e2445 = 0.0;
          res.e11244 = 0.0;
          res.e12244 = 0.0;
          res.e22244 = 0.0;
          res.e12344 = 0.0;
          res.e22344 = 0.0;
          res.e23344 = 0.0;
          res.e12444 = 0.0;
          res.e22444 = 0.0;
          res.e23444 = 0.0;
          res.e24444 = 0.0;
          res.e12445 = 0.0;
          res.e22445 = 0.0;
          res.e23445 = 0.0;
          res.e24445 = 0.0;
          res.e24455 = 0.0;
          break;
        case 18: //  e344
          res.e344 = 0.0;
          res.e1344 = 0.0;
          res.e2344 = 0.0;
          res.e3344 = 0.0;
          res.e3444 = 0.0;
          res.e3445 = 0.0;
          res.e11344 = 0.0;
          res.e12344 = 0.0;
          res.e22344 = 0.0;
          res.e13344 = 0.0;
          res.e23344 = 0.0;
          res.e33344 = 0.0;
          res.e13444 = 0.0;
          res.e23444 = 0.0;
          res.e33444 = 0.0;
          res.e34444 = 0.0;
          res.e13445 = 0.0;
          res.e23445 = 0.0;
          res.e33445 = 0.0;
          res.e34445 = 0.0;
          res.e34455 = 0.0;
          break;
        case 19: //  e444
          res.e444 = 0.0;
          res.e1444 = 0.0;
          res.e2444 = 0.0;
          res.e3444 = 0.0;
          res.e4444 = 0.0;
          res.e4445 = 0.0;
          res.e11444 = 0.0;
          res.e12444 = 0.0;
          res.e22444 = 0.0;
          res.e13444 = 0.0;
          res.e23444 = 0.0;
          res.e33444 = 0.0;
          res.e14444 = 0.0;
          res.e24444 = 0.0;
          res.e34444 = 0.0;
          res.e44444 = 0.0;
          res.e14445 = 0.0;
          res.e24445 = 0.0;
          res.e34445 = 0.0;
          res.e44445 = 0.0;
          res.e44455 = 0.0;
          break;
        case 20: //  e115
          res.e115 = 0.0;
          res.e1115 = 0.0;
          res.e1125 = 0.0;
          res.e1135 = 0.0;
          res.e1145 = 0.0;
          res.e1155 = 0.0;
          res.e11115 = 0.0;
          res.e11125 = 0.0;
          res.e11225 = 0.0;
          res.e11135 = 0.0;
          res.e11235 = 0.0;
          res.e11335 = 0.0;
          res.e11145 = 0.0;
          res.e11245 = 0.0;
          res.e11345 = 0.0;
          res.e11445 = 0.0;
          res.e11155 = 0.0;
          res.e11255 = 0.0;
          res.e11355 = 0.0;
          res.e11455 = 0.0;
          res.e11555 = 0.0;
          break;
        case 21: //  e125
          res.e125 = 0.0;
          res.e1125 = 0.0;
          res.e1225 = 0.0;
          res.e1235 = 0.0;
          res.e1245 = 0.0;
          res.e1255 = 0.0;
          res.e11125 = 0.0;
          res.e11225 = 0.0;
          res.e12225 = 0.0;
          res.e11235 = 0.0;
          res.e12235 = 0.0;
          res.e12335 = 0.0;
          res.e11245 = 0.0;
          res.e12245 = 0.0;
          res.e12345 = 0.0;
          res.e12445 = 0.0;
          res.e11255 = 0.0;
          res.e12255 = 0.0;
          res.e12355 = 0.0;
          res.e12455 = 0.0;
          res.e12555 = 0.0;
          break;
        case 22: //  e225
          res.e225 = 0.0;
          res.e1225 = 0.0;
          res.e2225 = 0.0;
          res.e2235 = 0.0;
          res.e2245 = 0.0;
          res.e2255 = 0.0;
          res.e11225 = 0.0;
          res.e12225 = 0.0;
          res.e22225 = 0.0;
          res.e12235 = 0.0;
          res.e22235 = 0.0;
          res.e22335 = 0.0;
          res.e12245 = 0.0;
          res.e22245 = 0.0;
          res.e22345 = 0.0;
          res.e22445 = 0.0;
          res.e12255 = 0.0;
          res.e22255 = 0.0;
          res.e22355 = 0.0;
          res.e22455 = 0.0;
          res.e22555 = 0.0;
          break;
        case 23: //  e135
          res.e135 = 0.0;
          res.e1135 = 0.0;
          res.e1235 = 0.0;
          res.e1335 = 0.0;
          res.e1345 = 0.0;
          res.e1355 = 0.0;
          res.e11135 = 0.0;
          res.e11235 = 0.0;
          res.e12235 = 0.0;
          res.e11335 = 0.0;
          res.e12335 = 0.0;
          res.e13335 = 0.0;
          res.e11345 = 0.0;
          res.e12345 = 0.0;
          res.e13345 = 0.0;
          res.e13445 = 0.0;
          res.e11355 = 0.0;
          res.e12355 = 0.0;
          res.e13355 = 0.0;
          res.e13455 = 0.0;
          res.e13555 = 0.0;
          break;
        case 24: //  e235
          res.e235 = 0.0;
          res.e1235 = 0.0;
          res.e2235 = 0.0;
          res.e2335 = 0.0;
          res.e2345 = 0.0;
          res.e2355 = 0.0;
          res.e11235 = 0.0;
          res.e12235 = 0.0;
          res.e22235 = 0.0;
          res.e12335 = 0.0;
          res.e22335 = 0.0;
          res.e23335 = 0.0;
          res.e12345 = 0.0;
          res.e22345 = 0.0;
          res.e23345 = 0.0;
          res.e23445 = 0.0;
          res.e12355 = 0.0;
          res.e22355 = 0.0;
          res.e23355 = 0.0;
          res.e23455 = 0.0;
          res.e23555 = 0.0;
          break;
        case 25: //  e335
          res.e335 = 0.0;
          res.e1335 = 0.0;
          res.e2335 = 0.0;
          res.e3335 = 0.0;
          res.e3345 = 0.0;
          res.e3355 = 0.0;
          res.e11335 = 0.0;
          res.e12335 = 0.0;
          res.e22335 = 0.0;
          res.e13335 = 0.0;
          res.e23335 = 0.0;
          res.e33335 = 0.0;
          res.e13345 = 0.0;
          res.e23345 = 0.0;
          res.e33345 = 0.0;
          res.e33445 = 0.0;
          res.e13355 = 0.0;
          res.e23355 = 0.0;
          res.e33355 = 0.0;
          res.e33455 = 0.0;
          res.e33555 = 0.0;
          break;
        case 26: //  e145
          res.e145 = 0.0;
          res.e1145 = 0.0;
          res.e1245 = 0.0;
          res.e1345 = 0.0;
          res.e1445 = 0.0;
          res.e1455 = 0.0;
          res.e11145 = 0.0;
          res.e11245 = 0.0;
          res.e12245 = 0.0;
          res.e11345 = 0.0;
          res.e12345 = 0.0;
          res.e13345 = 0.0;
          res.e11445 = 0.0;
          res.e12445 = 0.0;
          res.e13445 = 0.0;
          res.e14445 = 0.0;
          res.e11455 = 0.0;
          res.e12455 = 0.0;
          res.e13455 = 0.0;
          res.e14455 = 0.0;
          res.e14555 = 0.0;
          break;
        case 27: //  e245
          res.e245 = 0.0;
          res.e1245 = 0.0;
          res.e2245 = 0.0;
          res.e2345 = 0.0;
          res.e2445 = 0.0;
          res.e2455 = 0.0;
          res.e11245 = 0.0;
          res.e12245 = 0.0;
          res.e22245 = 0.0;
          res.e12345 = 0.0;
          res.e22345 = 0.0;
          res.e23345 = 0.0;
          res.e12445 = 0.0;
          res.e22445 = 0.0;
          res.e23445 = 0.0;
          res.e24445 = 0.0;
          res.e12455 = 0.0;
          res.e22455 = 0.0;
          res.e23455 = 0.0;
          res.e24455 = 0.0;
          res.e24555 = 0.0;
          break;
        case 28: //  e345
          res.e345 = 0.0;
          res.e1345 = 0.0;
          res.e2345 = 0.0;
          res.e3345 = 0.0;
          res.e3445 = 0.0;
          res.e3455 = 0.0;
          res.e11345 = 0.0;
          res.e12345 = 0.0;
          res.e22345 = 0.0;
          res.e13345 = 0.0;
          res.e23345 = 0.0;
          res.e33345 = 0.0;
          res.e13445 = 0.0;
          res.e23445 = 0.0;
          res.e33445 = 0.0;
          res.e34445 = 0.0;
          res.e13455 = 0.0;
          res.e23455 = 0.0;
          res.e33455 = 0.0;
          res.e34455 = 0.0;
          res.e34555 = 0.0;
          break;
        case 29: //  e445
          res.e445 = 0.0;
          res.e1445 = 0.0;
          res.e2445 = 0.0;
          res.e3445 = 0.0;
          res.e4445 = 0.0;
          res.e4455 = 0.0;
          res.e11445 = 0.0;
          res.e12445 = 0.0;
          res.e22445 = 0.0;
          res.e13445 = 0.0;
          res.e23445 = 0.0;
          res.e33445 = 0.0;
          res.e14445 = 0.0;
          res.e24445 = 0.0;
          res.e34445 = 0.0;
          res.e44445 = 0.0;
          res.e14455 = 0.0;
          res.e24455 = 0.0;
          res.e34455 = 0.0;
          res.e44455 = 0.0;
          res.e44555 = 0.0;
          break;
        case 30: //  e155
          res.e155 = 0.0;
          res.e1155 = 0.0;
          res.e1255 = 0.0;
          res.e1355 = 0.0;
          res.e1455 = 0.0;
          res.e1555 = 0.0;
          res.e11155 = 0.0;
          res.e11255 = 0.0;
          res.e12255 = 0.0;
          res.e11355 = 0.0;
          res.e12355 = 0.0;
          res.e13355 = 0.0;
          res.e11455 = 0.0;
          res.e12455 = 0.0;
          res.e13455 = 0.0;
          res.e14455 = 0.0;
          res.e11555 = 0.0;
          res.e12555 = 0.0;
          res.e13555 = 0.0;
          res.e14555 = 0.0;
          res.e15555 = 0.0;
          break;
        case 31: //  e255
          res.e255 = 0.0;
          res.e1255 = 0.0;
          res.e2255 = 0.0;
          res.e2355 = 0.0;
          res.e2455 = 0.0;
          res.e2555 = 0.0;
          res.e11255 = 0.0;
          res.e12255 = 0.0;
          res.e22255 = 0.0;
          res.e12355 = 0.0;
          res.e22355 = 0.0;
          res.e23355 = 0.0;
          res.e12455 = 0.0;
          res.e22455 = 0.0;
          res.e23455 = 0.0;
          res.e24455 = 0.0;
          res.e12555 = 0.0;
          res.e22555 = 0.0;
          res.e23555 = 0.0;
          res.e24555 = 0.0;
          res.e25555 = 0.0;
          break;
        case 32: //  e355
          res.e355 = 0.0;
          res.e1355 = 0.0;
          res.e2355 = 0.0;
          res.e3355 = 0.0;
          res.e3455 = 0.0;
          res.e3555 = 0.0;
          res.e11355 = 0.0;
          res.e12355 = 0.0;
          res.e22355 = 0.0;
          res.e13355 = 0.0;
          res.e23355 = 0.0;
          res.e33355 = 0.0;
          res.e13455 = 0.0;
          res.e23455 = 0.0;
          res.e33455 = 0.0;
          res.e34455 = 0.0;
          res.e13555 = 0.0;
          res.e23555 = 0.0;
          res.e33555 = 0.0;
          res.e34555 = 0.0;
          res.e35555 = 0.0;
          break;
        case 33: //  e455
          res.e455 = 0.0;
          res.e1455 = 0.0;
          res.e2455 = 0.0;
          res.e3455 = 0.0;
          res.e4455 = 0.0;
          res.e4555 = 0.0;
          res.e11455 = 0.0;
          res.e12455 = 0.0;
          res.e22455 = 0.0;
          res.e13455 = 0.0;
          res.e23455 = 0.0;
          res.e33455 = 0.0;
          res.e14455 = 0.0;
          res.e24455 = 0.0;
          res.e34455 = 0.0;
          res.e44455 = 0.0;
          res.e14555 = 0.0;
          res.e24555 = 0.0;
          res.e34555 = 0.0;
          res.e44555 = 0.0;
          res.e45555 = 0.0;
          break;
        case 34: //  e555
          res.e555 = 0.0;
          res.e1555 = 0.0;
          res.e2555 = 0.0;
          res.e3555 = 0.0;
          res.e4555 = 0.0;
          res.e5555 = 0.0;
          res.e11555 = 0.0;
          res.e12555 = 0.0;
          res.e22555 = 0.0;
          res.e13555 = 0.0;
          res.e23555 = 0.0;
          res.e33555 = 0.0;
          res.e14555 = 0.0;
          res.e24555 = 0.0;
          res.e34555 = 0.0;
          res.e44555 = 0.0;
          res.e15555 = 0.0;
          res.e25555 = 0.0;
          res.e35555 = 0.0;
          res.e45555 = 0.0;
          res.e55555 = 0.0;
          break;
      }
      break;
    case 4:
      switch (idx){
        case 0: //  e1111
          res.e1111 = 0.0;
          res.e11111 = 0.0;
          res.e11112 = 0.0;
          res.e11113 = 0.0;
          res.e11114 = 0.0;
          res.e11115 = 0.0;
          break;
        case 1: //  e1112
          res.e1112 = 0.0;
          res.e11112 = 0.0;
          res.e11122 = 0.0;
          res.e11123 = 0.0;
          res.e11124 = 0.0;
          res.e11125 = 0.0;
          break;
        case 2: //  e1122
          res.e1122 = 0.0;
          res.e11122 = 0.0;
          res.e11222 = 0.0;
          res.e11223 = 0.0;
          res.e11224 = 0.0;
          res.e11225 = 0.0;
          break;
        case 3: //  e1222
          res.e1222 = 0.0;
          res.e11222 = 0.0;
          res.e12222 = 0.0;
          res.e12223 = 0.0;
          res.e12224 = 0.0;
          res.e12225 = 0.0;
          break;
        case 4: //  e2222
          res.e2222 = 0.0;
          res.e12222 = 0.0;
          res.e22222 = 0.0;
          res.e22223 = 0.0;
          res.e22224 = 0.0;
          res.e22225 = 0.0;
          break;
        case 5: //  e1113
          res.e1113 = 0.0;
          res.e11113 = 0.0;
          res.e11123 = 0.0;
          res.e11133 = 0.0;
          res.e11134 = 0.0;
          res.e11135 = 0.0;
          break;
        case 6: //  e1123
          res.e1123 = 0.0;
          res.e11123 = 0.0;
          res.e11223 = 0.0;
          res.e11233 = 0.0;
          res.e11234 = 0.0;
          res.e11235 = 0.0;
          break;
        case 7: //  e1223
          res.e1223 = 0.0;
          res.e11223 = 0.0;
          res.e12223 = 0.0;
          res.e12233 = 0.0;
          res.e12234 = 0.0;
          res.e12235 = 0.0;
          break;
        case 8: //  e2223
          res.e2223 = 0.0;
          res.e12223 = 0.0;
          res.e22223 = 0.0;
          res.e22233 = 0.0;
          res.e22234 = 0.0;
          res.e22235 = 0.0;
          break;
        case 9: //  e1133
          res.e1133 = 0.0;
          res.e11133 = 0.0;
          res.e11233 = 0.0;
          res.e11333 = 0.0;
          res.e11334 = 0.0;
          res.e11335 = 0.0;
          break;
        case 10: //  e1233
          res.e1233 = 0.0;
          res.e11233 = 0.0;
          res.e12233 = 0.0;
          res.e12333 = 0.0;
          res.e12334 = 0.0;
          res.e12335 = 0.0;
          break;
        case 11: //  e2233
          res.e2233 = 0.0;
          res.e12233 = 0.0;
          res.e22233 = 0.0;
          res.e22333 = 0.0;
          res.e22334 = 0.0;
          res.e22335 = 0.0;
          break;
        case 12: //  e1333
          res.e1333 = 0.0;
          res.e11333 = 0.0;
          res.e12333 = 0.0;
          res.e13333 = 0.0;
          res.e13334 = 0.0;
          res.e13335 = 0.0;
          break;
        case 13: //  e2333
          res.e2333 = 0.0;
          res.e12333 = 0.0;
          res.e22333 = 0.0;
          res.e23333 = 0.0;
          res.e23334 = 0.0;
          res.e23335 = 0.0;
          break;
        case 14: //  e3333
          res.e3333 = 0.0;
          res.e13333 = 0.0;
          res.e23333 = 0.0;
          res.e33333 = 0.0;
          res.e33334 = 0.0;
          res.e33335 = 0.0;
          break;
        case 15: //  e1114
          res.e1114 = 0.0;
          res.e11114 = 0.0;
          res.e11124 = 0.0;
          res.e11134 = 0.0;
          res.e11144 = 0.0;
          res.e11145 = 0.0;
          break;
        case 16: //  e1124
          res.e1124 = 0.0;
          res.e11124 = 0.0;
          res.e11224 = 0.0;
          res.e11234 = 0.0;
          res.e11244 = 0.0;
          res.e11245 = 0.0;
          break;
        case 17: //  e1224
          res.e1224 = 0.0;
          res.e11224 = 0.0;
          res.e12224 = 0.0;
          res.e12234 = 0.0;
          res.e12244 = 0.0;
          res.e12245 = 0.0;
          break;
        case 18: //  e2224
          res.e2224 = 0.0;
          res.e12224 = 0.0;
          res.e22224 = 0.0;
          res.e22234 = 0.0;
          res.e22244 = 0.0;
          res.e22245 = 0.0;
          break;
        case 19: //  e1134
          res.e1134 = 0.0;
          res.e11134 = 0.0;
          res.e11234 = 0.0;
          res.e11334 = 0.0;
          res.e11344 = 0.0;
          res.e11345 = 0.0;
          break;
        case 20: //  e1234
          res.e1234 = 0.0;
          res.e11234 = 0.0;
          res.e12234 = 0.0;
          res.e12334 = 0.0;
          res.e12344 = 0.0;
          res.e12345 = 0.0;
          break;
        case 21: //  e2234
          res.e2234 = 0.0;
          res.e12234 = 0.0;
          res.e22234 = 0.0;
          res.e22334 = 0.0;
          res.e22344 = 0.0;
          res.e22345 = 0.0;
          break;
        case 22: //  e1334
          res.e1334 = 0.0;
          res.e11334 = 0.0;
          res.e12334 = 0.0;
          res.e13334 = 0.0;
          res.e13344 = 0.0;
          res.e13345 = 0.0;
          break;
        case 23: //  e2334
          res.e2334 = 0.0;
          res.e12334 = 0.0;
          res.e22334 = 0.0;
          res.e23334 = 0.0;
          res.e23344 = 0.0;
          res.e23345 = 0.0;
          break;
        case 24: //  e3334
          res.e3334 = 0.0;
          res.e13334 = 0.0;
          res.e23334 = 0.0;
          res.e33334 = 0.0;
          res.e33344 = 0.0;
          res.e33345 = 0.0;
          break;
        case 25: //  e1144
          res.e1144 = 0.0;
          res.e11144 = 0.0;
          res.e11244 = 0.0;
          res.e11344 = 0.0;
          res.e11444 = 0.0;
          res.e11445 = 0.0;
          break;
        case 26: //  e1244
          res.e1244 = 0.0;
          res.e11244 = 0.0;
          res.e12244 = 0.0;
          res.e12344 = 0.0;
          res.e12444 = 0.0;
          res.e12445 = 0.0;
          break;
        case 27: //  e2244
          res.e2244 = 0.0;
          res.e12244 = 0.0;
          res.e22244 = 0.0;
          res.e22344 = 0.0;
          res.e22444 = 0.0;
          res.e22445 = 0.0;
          break;
        case 28: //  e1344
          res.e1344 = 0.0;
          res.e11344 = 0.0;
          res.e12344 = 0.0;
          res.e13344 = 0.0;
          res.e13444 = 0.0;
          res.e13445 = 0.0;
          break;
        case 29: //  e2344
          res.e2344 = 0.0;
          res.e12344 = 0.0;
          res.e22344 = 0.0;
          res.e23344 = 0.0;
          res.e23444 = 0.0;
          res.e23445 = 0.0;
          break;
        case 30: //  e3344
          res.e3344 = 0.0;
          res.e13344 = 0.0;
          res.e23344 = 0.0;
          res.e33344 = 0.0;
          res.e33444 = 0.0;
          res.e33445 = 0.0;
          break;
        case 31: //  e1444
          res.e1444 = 0.0;
          res.e11444 = 0.0;
          res.e12444 = 0.0;
          res.e13444 = 0.0;
          res.e14444 = 0.0;
          res.e14445 = 0.0;
          break;
        case 32: //  e2444
          res.e2444 = 0.0;
          res.e12444 = 0.0;
          res.e22444 = 0.0;
          res.e23444 = 0.0;
          res.e24444 = 0.0;
          res.e24445 = 0.0;
          break;
        case 33: //  e3444
          res.e3444 = 0.0;
          res.e13444 = 0.0;
          res.e23444 = 0.0;
          res.e33444 = 0.0;
          res.e34444 = 0.0;
          res.e34445 = 0.0;
          break;
        case 34: //  e4444
          res.e4444 = 0.0;
          res.e14444 = 0.0;
          res.e24444 = 0.0;
          res.e34444 = 0.0;
          res.e44444 = 0.0;
          res.e44445 = 0.0;
          break;
        case 35: //  e1115
          res.e1115 = 0.0;
          res.e11115 = 0.0;
          res.e11125 = 0.0;
          res.e11135 = 0.0;
          res.e11145 = 0.0;
          res.e11155 = 0.0;
          break;
        case 36: //  e1125
          res.e1125 = 0.0;
          res.e11125 = 0.0;
          res.e11225 = 0.0;
          res.e11235 = 0.0;
          res.e11245 = 0.0;
          res.e11255 = 0.0;
          break;
        case 37: //  e1225
          res.e1225 = 0.0;
          res.e11225 = 0.0;
          res.e12225 = 0.0;
          res.e12235 = 0.0;
          res.e12245 = 0.0;
          res.e12255 = 0.0;
          break;
        case 38: //  e2225
          res.e2225 = 0.0;
          res.e12225 = 0.0;
          res.e22225 = 0.0;
          res.e22235 = 0.0;
          res.e22245 = 0.0;
          res.e22255 = 0.0;
          break;
        case 39: //  e1135
          res.e1135 = 0.0;
          res.e11135 = 0.0;
          res.e11235 = 0.0;
          res.e11335 = 0.0;
          res.e11345 = 0.0;
          res.e11355 = 0.0;
          break;
        case 40: //  e1235
          res.e1235 = 0.0;
          res.e11235 = 0.0;
          res.e12235 = 0.0;
          res.e12335 = 0.0;
          res.e12345 = 0.0;
          res.e12355 = 0.0;
          break;
        case 41: //  e2235
          res.e2235 = 0.0;
          res.e12235 = 0.0;
          res.e22235 = 0.0;
          res.e22335 = 0.0;
          res.e22345 = 0.0;
          res.e22355 = 0.0;
          break;
        case 42: //  e1335
          res.e1335 = 0.0;
          res.e11335 = 0.0;
          res.e12335 = 0.0;
          res.e13335 = 0.0;
          res.e13345 = 0.0;
          res.e13355 = 0.0;
          break;
        case 43: //  e2335
          res.e2335 = 0.0;
          res.e12335 = 0.0;
          res.e22335 = 0.0;
          res.e23335 = 0.0;
          res.e23345 = 0.0;
          res.e23355 = 0.0;
          break;
        case 44: //  e3335
          res.e3335 = 0.0;
          res.e13335 = 0.0;
          res.e23335 = 0.0;
          res.e33335 = 0.0;
          res.e33345 = 0.0;
          res.e33355 = 0.0;
          break;
        case 45: //  e1145
          res.e1145 = 0.0;
          res.e11145 = 0.0;
          res.e11245 = 0.0;
          res.e11345 = 0.0;
          res.e11445 = 0.0;
          res.e11455 = 0.0;
          break;
        case 46: //  e1245
          res.e1245 = 0.0;
          res.e11245 = 0.0;
          res.e12245 = 0.0;
          res.e12345 = 0.0;
          res.e12445 = 0.0;
          res.e12455 = 0.0;
          break;
        case 47: //  e2245
          res.e2245 = 0.0;
          res.e12245 = 0.0;
          res.e22245 = 0.0;
          res.e22345 = 0.0;
          res.e22445 = 0.0;
          res.e22455 = 0.0;
          break;
        case 48: //  e1345
          res.e1345 = 0.0;
          res.e11345 = 0.0;
          res.e12345 = 0.0;
          res.e13345 = 0.0;
          res.e13445 = 0.0;
          res.e13455 = 0.0;
          break;
        case 49: //  e2345
          res.e2345 = 0.0;
          res.e12345 = 0.0;
          res.e22345 = 0.0;
          res.e23345 = 0.0;
          res.e23445 = 0.0;
          res.e23455 = 0.0;
          break;
        case 50: //  e3345
          res.e3345 = 0.0;
          res.e13345 = 0.0;
          res.e23345 = 0.0;
          res.e33345 = 0.0;
          res.e33445 = 0.0;
          res.e33455 = 0.0;
          break;
        case 51: //  e1445
          res.e1445 = 0.0;
          res.e11445 = 0.0;
          res.e12445 = 0.0;
          res.e13445 = 0.0;
          res.e14445 = 0.0;
          res.e14455 = 0.0;
          break;
        case 52: //  e2445
          res.e2445 = 0.0;
          res.e12445 = 0.0;
          res.e22445 = 0.0;
          res.e23445 = 0.0;
          res.e24445 = 0.0;
          res.e24455 = 0.0;
          break;
        case 53: //  e3445
          res.e3445 = 0.0;
          res.e13445 = 0.0;
          res.e23445 = 0.0;
          res.e33445 = 0.0;
          res.e34445 = 0.0;
          res.e34455 = 0.0;
          break;
        case 54: //  e4445
          res.e4445 = 0.0;
          res.e14445 = 0.0;
          res.e24445 = 0.0;
          res.e34445 = 0.0;
          res.e44445 = 0.0;
          res.e44455 = 0.0;
          break;
        case 55: //  e1155
          res.e1155 = 0.0;
          res.e11155 = 0.0;
          res.e11255 = 0.0;
          res.e11355 = 0.0;
          res.e11455 = 0.0;
          res.e11555 = 0.0;
          break;
        case 56: //  e1255
          res.e1255 = 0.0;
          res.e11255 = 0.0;
          res.e12255 = 0.0;
          res.e12355 = 0.0;
          res.e12455 = 0.0;
          res.e12555 = 0.0;
          break;
        case 57: //  e2255
          res.e2255 = 0.0;
          res.e12255 = 0.0;
          res.e22255 = 0.0;
          res.e22355 = 0.0;
          res.e22455 = 0.0;
          res.e22555 = 0.0;
          break;
        case 58: //  e1355
          res.e1355 = 0.0;
          res.e11355 = 0.0;
          res.e12355 = 0.0;
          res.e13355 = 0.0;
          res.e13455 = 0.0;
          res.e13555 = 0.0;
          break;
        case 59: //  e2355
          res.e2355 = 0.0;
          res.e12355 = 0.0;
          res.e22355 = 0.0;
          res.e23355 = 0.0;
          res.e23455 = 0.0;
          res.e23555 = 0.0;
          break;
        case 60: //  e3355
          res.e3355 = 0.0;
          res.e13355 = 0.0;
          res.e23355 = 0.0;
          res.e33355 = 0.0;
          res.e33455 = 0.0;
          res.e33555 = 0.0;
          break;
        case 61: //  e1455
          res.e1455 = 0.0;
          res.e11455 = 0.0;
          res.e12455 = 0.0;
          res.e13455 = 0.0;
          res.e14455 = 0.0;
          res.e14555 = 0.0;
          break;
        case 62: //  e2455
          res.e2455 = 0.0;
          res.e12455 = 0.0;
          res.e22455 = 0.0;
          res.e23455 = 0.0;
          res.e24455 = 0.0;
          res.e24555 = 0.0;
          break;
        case 63: //  e3455
          res.e3455 = 0.0;
          res.e13455 = 0.0;
          res.e23455 = 0.0;
          res.e33455 = 0.0;
          res.e34455 = 0.0;
          res.e34555 = 0.0;
          break;
        case 64: //  e4455
          res.e4455 = 0.0;
          res.e14455 = 0.0;
          res.e24455 = 0.0;
          res.e34455 = 0.0;
          res.e44455 = 0.0;
          res.e44555 = 0.0;
          break;
        case 65: //  e1555
          res.e1555 = 0.0;
          res.e11555 = 0.0;
          res.e12555 = 0.0;
          res.e13555 = 0.0;
          res.e14555 = 0.0;
          res.e15555 = 0.0;
          break;
        case 66: //  e2555
          res.e2555 = 0.0;
          res.e12555 = 0.0;
          res.e22555 = 0.0;
          res.e23555 = 0.0;
          res.e24555 = 0.0;
          res.e25555 = 0.0;
          break;
        case 67: //  e3555
          res.e3555 = 0.0;
          res.e13555 = 0.0;
          res.e23555 = 0.0;
          res.e33555 = 0.0;
          res.e34555 = 0.0;
          res.e35555 = 0.0;
          break;
        case 68: //  e4555
          res.e4555 = 0.0;
          res.e14555 = 0.0;
          res.e24555 = 0.0;
          res.e34555 = 0.0;
          res.e44555 = 0.0;
          res.e45555 = 0.0;
          break;
        case 69: //  e5555
          res.e5555 = 0.0;
          res.e15555 = 0.0;
          res.e25555 = 0.0;
          res.e35555 = 0.0;
          res.e45555 = 0.0;
          res.e55555 = 0.0;
          break;
      }
      break;
    case 5:
      switch (idx){
        case 0: //  e11111
          res.e11111 = 0.0;
          break;
        case 1: //  e11112
          res.e11112 = 0.0;
          break;
        case 2: //  e11122
          res.e11122 = 0.0;
          break;
        case 3: //  e11222
          res.e11222 = 0.0;
          break;
        case 4: //  e12222
          res.e12222 = 0.0;
          break;
        case 5: //  e22222
          res.e22222 = 0.0;
          break;
        case 6: //  e11113
          res.e11113 = 0.0;
          break;
        case 7: //  e11123
          res.e11123 = 0.0;
          break;
        case 8: //  e11223
          res.e11223 = 0.0;
          break;
        case 9: //  e12223
          res.e12223 = 0.0;
          break;
        case 10: //  e22223
          res.e22223 = 0.0;
          break;
        case 11: //  e11133
          res.e11133 = 0.0;
          break;
        case 12: //  e11233
          res.e11233 = 0.0;
          break;
        case 13: //  e12233
          res.e12233 = 0.0;
          break;
        case 14: //  e22233
          res.e22233 = 0.0;
          break;
        case 15: //  e11333
          res.e11333 = 0.0;
          break;
        case 16: //  e12333
          res.e12333 = 0.0;
          break;
        case 17: //  e22333
          res.e22333 = 0.0;
          break;
        case 18: //  e13333
          res.e13333 = 0.0;
          break;
        case 19: //  e23333
          res.e23333 = 0.0;
          break;
        case 20: //  e33333
          res.e33333 = 0.0;
          break;
        case 21: //  e11114
          res.e11114 = 0.0;
          break;
        case 22: //  e11124
          res.e11124 = 0.0;
          break;
        case 23: //  e11224
          res.e11224 = 0.0;
          break;
        case 24: //  e12224
          res.e12224 = 0.0;
          break;
        case 25: //  e22224
          res.e22224 = 0.0;
          break;
        case 26: //  e11134
          res.e11134 = 0.0;
          break;
        case 27: //  e11234
          res.e11234 = 0.0;
          break;
        case 28: //  e12234
          res.e12234 = 0.0;
          break;
        case 29: //  e22234
          res.e22234 = 0.0;
          break;
        case 30: //  e11334
          res.e11334 = 0.0;
          break;
        case 31: //  e12334
          res.e12334 = 0.0;
          break;
        case 32: //  e22334
          res.e22334 = 0.0;
          break;
        case 33: //  e13334
          res.e13334 = 0.0;
          break;
        case 34: //  e23334
          res.e23334 = 0.0;
          break;
        case 35: //  e33334
          res.e33334 = 0.0;
          break;
        case 36: //  e11144
          res.e11144 = 0.0;
          break;
        case 37: //  e11244
          res.e11244 = 0.0;
          break;
        case 38: //  e12244
          res.e12244 = 0.0;
          break;
        case 39: //  e22244
          res.e22244 = 0.0;
          break;
        case 40: //  e11344
          res.e11344 = 0.0;
          break;
        case 41: //  e12344
          res.e12344 = 0.0;
          break;
        case 42: //  e22344
          res.e22344 = 0.0;
          break;
        case 43: //  e13344
          res.e13344 = 0.0;
          break;
        case 44: //  e23344
          res.e23344 = 0.0;
          break;
        case 45: //  e33344
          res.e33344 = 0.0;
          break;
        case 46: //  e11444
          res.e11444 = 0.0;
          break;
        case 47: //  e12444
          res.e12444 = 0.0;
          break;
        case 48: //  e22444
          res.e22444 = 0.0;
          break;
        case 49: //  e13444
          res.e13444 = 0.0;
          break;
        case 50: //  e23444
          res.e23444 = 0.0;
          break;
        case 51: //  e33444
          res.e33444 = 0.0;
          break;
        case 52: //  e14444
          res.e14444 = 0.0;
          break;
        case 53: //  e24444
          res.e24444 = 0.0;
          break;
        case 54: //  e34444
          res.e34444 = 0.0;
          break;
        case 55: //  e44444
          res.e44444 = 0.0;
          break;
        case 56: //  e11115
          res.e11115 = 0.0;
          break;
        case 57: //  e11125
          res.e11125 = 0.0;
          break;
        case 58: //  e11225
          res.e11225 = 0.0;
          break;
        case 59: //  e12225
          res.e12225 = 0.0;
          break;
        case 60: //  e22225
          res.e22225 = 0.0;
          break;
        case 61: //  e11135
          res.e11135 = 0.0;
          break;
        case 62: //  e11235
          res.e11235 = 0.0;
          break;
        case 63: //  e12235
          res.e12235 = 0.0;
          break;
        case 64: //  e22235
          res.e22235 = 0.0;
          break;
        case 65: //  e11335
          res.e11335 = 0.0;
          break;
        case 66: //  e12335
          res.e12335 = 0.0;
          break;
        case 67: //  e22335
          res.e22335 = 0.0;
          break;
        case 68: //  e13335
          res.e13335 = 0.0;
          break;
        case 69: //  e23335
          res.e23335 = 0.0;
          break;
        case 70: //  e33335
          res.e33335 = 0.0;
          break;
        case 71: //  e11145
          res.e11145 = 0.0;
          break;
        case 72: //  e11245
          res.e11245 = 0.0;
          break;
        case 73: //  e12245
          res.e12245 = 0.0;
          break;
        case 74: //  e22245
          res.e22245 = 0.0;
          break;
        case 75: //  e11345
          res.e11345 = 0.0;
          break;
        case 76: //  e12345
          res.e12345 = 0.0;
          break;
        case 77: //  e22345
          res.e22345 = 0.0;
          break;
        case 78: //  e13345
          res.e13345 = 0.0;
          break;
        case 79: //  e23345
          res.e23345 = 0.0;
          break;
        case 80: //  e33345
          res.e33345 = 0.0;
          break;
        case 81: //  e11445
          res.e11445 = 0.0;
          break;
        case 82: //  e12445
          res.e12445 = 0.0;
          break;
        case 83: //  e22445
          res.e22445 = 0.0;
          break;
        case 84: //  e13445
          res.e13445 = 0.0;
          break;
        case 85: //  e23445
          res.e23445 = 0.0;
          break;
        case 86: //  e33445
          res.e33445 = 0.0;
          break;
        case 87: //  e14445
          res.e14445 = 0.0;
          break;
        case 88: //  e24445
          res.e24445 = 0.0;
          break;
        case 89: //  e34445
          res.e34445 = 0.0;
          break;
        case 90: //  e44445
          res.e44445 = 0.0;
          break;
        case 91: //  e11155
          res.e11155 = 0.0;
          break;
        case 92: //  e11255
          res.e11255 = 0.0;
          break;
        case 93: //  e12255
          res.e12255 = 0.0;
          break;
        case 94: //  e22255
          res.e22255 = 0.0;
          break;
        case 95: //  e11355
          res.e11355 = 0.0;
          break;
        case 96: //  e12355
          res.e12355 = 0.0;
          break;
        case 97: //  e22355
          res.e22355 = 0.0;
          break;
        case 98: //  e13355
          res.e13355 = 0.0;
          break;
        case 99: //  e23355
          res.e23355 = 0.0;
          break;
        case 100: //  e33355
          res.e33355 = 0.0;
          break;
        case 101: //  e11455
          res.e11455 = 0.0;
          break;
        case 102: //  e12455
          res.e12455 = 0.0;
          break;
        case 103: //  e22455
          res.e22455 = 0.0;
          break;
        case 104: //  e13455
          res.e13455 = 0.0;
          break;
        case 105: //  e23455
          res.e23455 = 0.0;
          break;
        case 106: //  e33455
          res.e33455 = 0.0;
          break;
        case 107: //  e14455
          res.e14455 = 0.0;
          break;
        case 108: //  e24455
          res.e24455 = 0.0;
          break;
        case 109: //  e34455
          res.e34455 = 0.0;
          break;
        case 110: //  e44455
          res.e44455 = 0.0;
          break;
        case 111: //  e11555
          res.e11555 = 0.0;
          break;
        case 112: //  e12555
          res.e12555 = 0.0;
          break;
        case 113: //  e22555
          res.e22555 = 0.0;
          break;
        case 114: //  e13555
          res.e13555 = 0.0;
          break;
        case 115: //  e23555
          res.e23555 = 0.0;
          break;
        case 116: //  e33555
          res.e33555 = 0.0;
          break;
        case 117: //  e14555
          res.e14555 = 0.0;
          break;
        case 118: //  e24555
          res.e24555 = 0.0;
          break;
        case 119: //  e34555
          res.e34555 = 0.0;
          break;
        case 120: //  e44555
          res.e44555 = 0.0;
          break;
        case 121: //  e15555
          res.e15555 = 0.0;
          break;
        case 122: //  e25555
          res.e25555 = 0.0;
          break;
        case 123: //  e35555
          res.e35555 = 0.0;
          break;
        case 124: //  e45555
          res.e45555 = 0.0;
          break;
        case 125: //  e55555
          res.e55555 = 0.0;
          break;
      }
      break;
  }
  return res;

}

void onumm5n5_truncate_im_to(imdir_t idx, ord_t order, onumm5n5_t* lhs, onumm5n5_t* res){

  // Copy number.
  *res = (*lhs);
  // Truncate all other values when necessary.
  // Real;
  switch (order){
    case 0:
      *res = onumm5n5_init();
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
          res->e11111 = 0.0;
          res->e11112 = 0.0;
          res->e11122 = 0.0;
          res->e11222 = 0.0;
          res->e12222 = 0.0;
          res->e11113 = 0.0;
          res->e11123 = 0.0;
          res->e11223 = 0.0;
          res->e12223 = 0.0;
          res->e11133 = 0.0;
          res->e11233 = 0.0;
          res->e12233 = 0.0;
          res->e11333 = 0.0;
          res->e12333 = 0.0;
          res->e13333 = 0.0;
          res->e11114 = 0.0;
          res->e11124 = 0.0;
          res->e11224 = 0.0;
          res->e12224 = 0.0;
          res->e11134 = 0.0;
          res->e11234 = 0.0;
          res->e12234 = 0.0;
          res->e11334 = 0.0;
          res->e12334 = 0.0;
          res->e13334 = 0.0;
          res->e11144 = 0.0;
          res->e11244 = 0.0;
          res->e12244 = 0.0;
          res->e11344 = 0.0;
          res->e12344 = 0.0;
          res->e13344 = 0.0;
          res->e11444 = 0.0;
          res->e12444 = 0.0;
          res->e13444 = 0.0;
          res->e14444 = 0.0;
          res->e11115 = 0.0;
          res->e11125 = 0.0;
          res->e11225 = 0.0;
          res->e12225 = 0.0;
          res->e11135 = 0.0;
          res->e11235 = 0.0;
          res->e12235 = 0.0;
          res->e11335 = 0.0;
          res->e12335 = 0.0;
          res->e13335 = 0.0;
          res->e11145 = 0.0;
          res->e11245 = 0.0;
          res->e12245 = 0.0;
          res->e11345 = 0.0;
          res->e12345 = 0.0;
          res->e13345 = 0.0;
          res->e11445 = 0.0;
          res->e12445 = 0.0;
          res->e13445 = 0.0;
          res->e14445 = 0.0;
          res->e11155 = 0.0;
          res->e11255 = 0.0;
          res->e12255 = 0.0;
          res->e11355 = 0.0;
          res->e12355 = 0.0;
          res->e13355 = 0.0;
          res->e11455 = 0.0;
          res->e12455 = 0.0;
          res->e13455 = 0.0;
          res->e14455 = 0.0;
          res->e11555 = 0.0;
          res->e12555 = 0.0;
          res->e13555 = 0.0;
          res->e14555 = 0.0;
          res->e15555 = 0.0;
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
          res->e11112 = 0.0;
          res->e11122 = 0.0;
          res->e11222 = 0.0;
          res->e12222 = 0.0;
          res->e22222 = 0.0;
          res->e11123 = 0.0;
          res->e11223 = 0.0;
          res->e12223 = 0.0;
          res->e22223 = 0.0;
          res->e11233 = 0.0;
          res->e12233 = 0.0;
          res->e22233 = 0.0;
          res->e12333 = 0.0;
          res->e22333 = 0.0;
          res->e23333 = 0.0;
          res->e11124 = 0.0;
          res->e11224 = 0.0;
          res->e12224 = 0.0;
          res->e22224 = 0.0;
          res->e11234 = 0.0;
          res->e12234 = 0.0;
          res->e22234 = 0.0;
          res->e12334 = 0.0;
          res->e22334 = 0.0;
          res->e23334 = 0.0;
          res->e11244 = 0.0;
          res->e12244 = 0.0;
          res->e22244 = 0.0;
          res->e12344 = 0.0;
          res->e22344 = 0.0;
          res->e23344 = 0.0;
          res->e12444 = 0.0;
          res->e22444 = 0.0;
          res->e23444 = 0.0;
          res->e24444 = 0.0;
          res->e11125 = 0.0;
          res->e11225 = 0.0;
          res->e12225 = 0.0;
          res->e22225 = 0.0;
          res->e11235 = 0.0;
          res->e12235 = 0.0;
          res->e22235 = 0.0;
          res->e12335 = 0.0;
          res->e22335 = 0.0;
          res->e23335 = 0.0;
          res->e11245 = 0.0;
          res->e12245 = 0.0;
          res->e22245 = 0.0;
          res->e12345 = 0.0;
          res->e22345 = 0.0;
          res->e23345 = 0.0;
          res->e12445 = 0.0;
          res->e22445 = 0.0;
          res->e23445 = 0.0;
          res->e24445 = 0.0;
          res->e11255 = 0.0;
          res->e12255 = 0.0;
          res->e22255 = 0.0;
          res->e12355 = 0.0;
          res->e22355 = 0.0;
          res->e23355 = 0.0;
          res->e12455 = 0.0;
          res->e22455 = 0.0;
          res->e23455 = 0.0;
          res->e24455 = 0.0;
          res->e12555 = 0.0;
          res->e22555 = 0.0;
          res->e23555 = 0.0;
          res->e24555 = 0.0;
          res->e25555 = 0.0;
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
          res->e11113 = 0.0;
          res->e11123 = 0.0;
          res->e11223 = 0.0;
          res->e12223 = 0.0;
          res->e22223 = 0.0;
          res->e11133 = 0.0;
          res->e11233 = 0.0;
          res->e12233 = 0.0;
          res->e22233 = 0.0;
          res->e11333 = 0.0;
          res->e12333 = 0.0;
          res->e22333 = 0.0;
          res->e13333 = 0.0;
          res->e23333 = 0.0;
          res->e33333 = 0.0;
          res->e11134 = 0.0;
          res->e11234 = 0.0;
          res->e12234 = 0.0;
          res->e22234 = 0.0;
          res->e11334 = 0.0;
          res->e12334 = 0.0;
          res->e22334 = 0.0;
          res->e13334 = 0.0;
          res->e23334 = 0.0;
          res->e33334 = 0.0;
          res->e11344 = 0.0;
          res->e12344 = 0.0;
          res->e22344 = 0.0;
          res->e13344 = 0.0;
          res->e23344 = 0.0;
          res->e33344 = 0.0;
          res->e13444 = 0.0;
          res->e23444 = 0.0;
          res->e33444 = 0.0;
          res->e34444 = 0.0;
          res->e11135 = 0.0;
          res->e11235 = 0.0;
          res->e12235 = 0.0;
          res->e22235 = 0.0;
          res->e11335 = 0.0;
          res->e12335 = 0.0;
          res->e22335 = 0.0;
          res->e13335 = 0.0;
          res->e23335 = 0.0;
          res->e33335 = 0.0;
          res->e11345 = 0.0;
          res->e12345 = 0.0;
          res->e22345 = 0.0;
          res->e13345 = 0.0;
          res->e23345 = 0.0;
          res->e33345 = 0.0;
          res->e13445 = 0.0;
          res->e23445 = 0.0;
          res->e33445 = 0.0;
          res->e34445 = 0.0;
          res->e11355 = 0.0;
          res->e12355 = 0.0;
          res->e22355 = 0.0;
          res->e13355 = 0.0;
          res->e23355 = 0.0;
          res->e33355 = 0.0;
          res->e13455 = 0.0;
          res->e23455 = 0.0;
          res->e33455 = 0.0;
          res->e34455 = 0.0;
          res->e13555 = 0.0;
          res->e23555 = 0.0;
          res->e33555 = 0.0;
          res->e34555 = 0.0;
          res->e35555 = 0.0;
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
          res->e11114 = 0.0;
          res->e11124 = 0.0;
          res->e11224 = 0.0;
          res->e12224 = 0.0;
          res->e22224 = 0.0;
          res->e11134 = 0.0;
          res->e11234 = 0.0;
          res->e12234 = 0.0;
          res->e22234 = 0.0;
          res->e11334 = 0.0;
          res->e12334 = 0.0;
          res->e22334 = 0.0;
          res->e13334 = 0.0;
          res->e23334 = 0.0;
          res->e33334 = 0.0;
          res->e11144 = 0.0;
          res->e11244 = 0.0;
          res->e12244 = 0.0;
          res->e22244 = 0.0;
          res->e11344 = 0.0;
          res->e12344 = 0.0;
          res->e22344 = 0.0;
          res->e13344 = 0.0;
          res->e23344 = 0.0;
          res->e33344 = 0.0;
          res->e11444 = 0.0;
          res->e12444 = 0.0;
          res->e22444 = 0.0;
          res->e13444 = 0.0;
          res->e23444 = 0.0;
          res->e33444 = 0.0;
          res->e14444 = 0.0;
          res->e24444 = 0.0;
          res->e34444 = 0.0;
          res->e44444 = 0.0;
          res->e11145 = 0.0;
          res->e11245 = 0.0;
          res->e12245 = 0.0;
          res->e22245 = 0.0;
          res->e11345 = 0.0;
          res->e12345 = 0.0;
          res->e22345 = 0.0;
          res->e13345 = 0.0;
          res->e23345 = 0.0;
          res->e33345 = 0.0;
          res->e11445 = 0.0;
          res->e12445 = 0.0;
          res->e22445 = 0.0;
          res->e13445 = 0.0;
          res->e23445 = 0.0;
          res->e33445 = 0.0;
          res->e14445 = 0.0;
          res->e24445 = 0.0;
          res->e34445 = 0.0;
          res->e44445 = 0.0;
          res->e11455 = 0.0;
          res->e12455 = 0.0;
          res->e22455 = 0.0;
          res->e13455 = 0.0;
          res->e23455 = 0.0;
          res->e33455 = 0.0;
          res->e14455 = 0.0;
          res->e24455 = 0.0;
          res->e34455 = 0.0;
          res->e44455 = 0.0;
          res->e14555 = 0.0;
          res->e24555 = 0.0;
          res->e34555 = 0.0;
          res->e44555 = 0.0;
          res->e45555 = 0.0;
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
          res->e11115 = 0.0;
          res->e11125 = 0.0;
          res->e11225 = 0.0;
          res->e12225 = 0.0;
          res->e22225 = 0.0;
          res->e11135 = 0.0;
          res->e11235 = 0.0;
          res->e12235 = 0.0;
          res->e22235 = 0.0;
          res->e11335 = 0.0;
          res->e12335 = 0.0;
          res->e22335 = 0.0;
          res->e13335 = 0.0;
          res->e23335 = 0.0;
          res->e33335 = 0.0;
          res->e11145 = 0.0;
          res->e11245 = 0.0;
          res->e12245 = 0.0;
          res->e22245 = 0.0;
          res->e11345 = 0.0;
          res->e12345 = 0.0;
          res->e22345 = 0.0;
          res->e13345 = 0.0;
          res->e23345 = 0.0;
          res->e33345 = 0.0;
          res->e11445 = 0.0;
          res->e12445 = 0.0;
          res->e22445 = 0.0;
          res->e13445 = 0.0;
          res->e23445 = 0.0;
          res->e33445 = 0.0;
          res->e14445 = 0.0;
          res->e24445 = 0.0;
          res->e34445 = 0.0;
          res->e44445 = 0.0;
          res->e11155 = 0.0;
          res->e11255 = 0.0;
          res->e12255 = 0.0;
          res->e22255 = 0.0;
          res->e11355 = 0.0;
          res->e12355 = 0.0;
          res->e22355 = 0.0;
          res->e13355 = 0.0;
          res->e23355 = 0.0;
          res->e33355 = 0.0;
          res->e11455 = 0.0;
          res->e12455 = 0.0;
          res->e22455 = 0.0;
          res->e13455 = 0.0;
          res->e23455 = 0.0;
          res->e33455 = 0.0;
          res->e14455 = 0.0;
          res->e24455 = 0.0;
          res->e34455 = 0.0;
          res->e44455 = 0.0;
          res->e11555 = 0.0;
          res->e12555 = 0.0;
          res->e22555 = 0.0;
          res->e13555 = 0.0;
          res->e23555 = 0.0;
          res->e33555 = 0.0;
          res->e14555 = 0.0;
          res->e24555 = 0.0;
          res->e34555 = 0.0;
          res->e44555 = 0.0;
          res->e15555 = 0.0;
          res->e25555 = 0.0;
          res->e35555 = 0.0;
          res->e45555 = 0.0;
          res->e55555 = 0.0;
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
          res->e11111 = 0.0;
          res->e11112 = 0.0;
          res->e11122 = 0.0;
          res->e11222 = 0.0;
          res->e11113 = 0.0;
          res->e11123 = 0.0;
          res->e11223 = 0.0;
          res->e11133 = 0.0;
          res->e11233 = 0.0;
          res->e11333 = 0.0;
          res->e11114 = 0.0;
          res->e11124 = 0.0;
          res->e11224 = 0.0;
          res->e11134 = 0.0;
          res->e11234 = 0.0;
          res->e11334 = 0.0;
          res->e11144 = 0.0;
          res->e11244 = 0.0;
          res->e11344 = 0.0;
          res->e11444 = 0.0;
          res->e11115 = 0.0;
          res->e11125 = 0.0;
          res->e11225 = 0.0;
          res->e11135 = 0.0;
          res->e11235 = 0.0;
          res->e11335 = 0.0;
          res->e11145 = 0.0;
          res->e11245 = 0.0;
          res->e11345 = 0.0;
          res->e11445 = 0.0;
          res->e11155 = 0.0;
          res->e11255 = 0.0;
          res->e11355 = 0.0;
          res->e11455 = 0.0;
          res->e11555 = 0.0;
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
          res->e11112 = 0.0;
          res->e11122 = 0.0;
          res->e11222 = 0.0;
          res->e12222 = 0.0;
          res->e11123 = 0.0;
          res->e11223 = 0.0;
          res->e12223 = 0.0;
          res->e11233 = 0.0;
          res->e12233 = 0.0;
          res->e12333 = 0.0;
          res->e11124 = 0.0;
          res->e11224 = 0.0;
          res->e12224 = 0.0;
          res->e11234 = 0.0;
          res->e12234 = 0.0;
          res->e12334 = 0.0;
          res->e11244 = 0.0;
          res->e12244 = 0.0;
          res->e12344 = 0.0;
          res->e12444 = 0.0;
          res->e11125 = 0.0;
          res->e11225 = 0.0;
          res->e12225 = 0.0;
          res->e11235 = 0.0;
          res->e12235 = 0.0;
          res->e12335 = 0.0;
          res->e11245 = 0.0;
          res->e12245 = 0.0;
          res->e12345 = 0.0;
          res->e12445 = 0.0;
          res->e11255 = 0.0;
          res->e12255 = 0.0;
          res->e12355 = 0.0;
          res->e12455 = 0.0;
          res->e12555 = 0.0;
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
          res->e11122 = 0.0;
          res->e11222 = 0.0;
          res->e12222 = 0.0;
          res->e22222 = 0.0;
          res->e11223 = 0.0;
          res->e12223 = 0.0;
          res->e22223 = 0.0;
          res->e12233 = 0.0;
          res->e22233 = 0.0;
          res->e22333 = 0.0;
          res->e11224 = 0.0;
          res->e12224 = 0.0;
          res->e22224 = 0.0;
          res->e12234 = 0.0;
          res->e22234 = 0.0;
          res->e22334 = 0.0;
          res->e12244 = 0.0;
          res->e22244 = 0.0;
          res->e22344 = 0.0;
          res->e22444 = 0.0;
          res->e11225 = 0.0;
          res->e12225 = 0.0;
          res->e22225 = 0.0;
          res->e12235 = 0.0;
          res->e22235 = 0.0;
          res->e22335 = 0.0;
          res->e12245 = 0.0;
          res->e22245 = 0.0;
          res->e22345 = 0.0;
          res->e22445 = 0.0;
          res->e12255 = 0.0;
          res->e22255 = 0.0;
          res->e22355 = 0.0;
          res->e22455 = 0.0;
          res->e22555 = 0.0;
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
          res->e11113 = 0.0;
          res->e11123 = 0.0;
          res->e11223 = 0.0;
          res->e12223 = 0.0;
          res->e11133 = 0.0;
          res->e11233 = 0.0;
          res->e12233 = 0.0;
          res->e11333 = 0.0;
          res->e12333 = 0.0;
          res->e13333 = 0.0;
          res->e11134 = 0.0;
          res->e11234 = 0.0;
          res->e12234 = 0.0;
          res->e11334 = 0.0;
          res->e12334 = 0.0;
          res->e13334 = 0.0;
          res->e11344 = 0.0;
          res->e12344 = 0.0;
          res->e13344 = 0.0;
          res->e13444 = 0.0;
          res->e11135 = 0.0;
          res->e11235 = 0.0;
          res->e12235 = 0.0;
          res->e11335 = 0.0;
          res->e12335 = 0.0;
          res->e13335 = 0.0;
          res->e11345 = 0.0;
          res->e12345 = 0.0;
          res->e13345 = 0.0;
          res->e13445 = 0.0;
          res->e11355 = 0.0;
          res->e12355 = 0.0;
          res->e13355 = 0.0;
          res->e13455 = 0.0;
          res->e13555 = 0.0;
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
          res->e11123 = 0.0;
          res->e11223 = 0.0;
          res->e12223 = 0.0;
          res->e22223 = 0.0;
          res->e11233 = 0.0;
          res->e12233 = 0.0;
          res->e22233 = 0.0;
          res->e12333 = 0.0;
          res->e22333 = 0.0;
          res->e23333 = 0.0;
          res->e11234 = 0.0;
          res->e12234 = 0.0;
          res->e22234 = 0.0;
          res->e12334 = 0.0;
          res->e22334 = 0.0;
          res->e23334 = 0.0;
          res->e12344 = 0.0;
          res->e22344 = 0.0;
          res->e23344 = 0.0;
          res->e23444 = 0.0;
          res->e11235 = 0.0;
          res->e12235 = 0.0;
          res->e22235 = 0.0;
          res->e12335 = 0.0;
          res->e22335 = 0.0;
          res->e23335 = 0.0;
          res->e12345 = 0.0;
          res->e22345 = 0.0;
          res->e23345 = 0.0;
          res->e23445 = 0.0;
          res->e12355 = 0.0;
          res->e22355 = 0.0;
          res->e23355 = 0.0;
          res->e23455 = 0.0;
          res->e23555 = 0.0;
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
          res->e11133 = 0.0;
          res->e11233 = 0.0;
          res->e12233 = 0.0;
          res->e22233 = 0.0;
          res->e11333 = 0.0;
          res->e12333 = 0.0;
          res->e22333 = 0.0;
          res->e13333 = 0.0;
          res->e23333 = 0.0;
          res->e33333 = 0.0;
          res->e11334 = 0.0;
          res->e12334 = 0.0;
          res->e22334 = 0.0;
          res->e13334 = 0.0;
          res->e23334 = 0.0;
          res->e33334 = 0.0;
          res->e13344 = 0.0;
          res->e23344 = 0.0;
          res->e33344 = 0.0;
          res->e33444 = 0.0;
          res->e11335 = 0.0;
          res->e12335 = 0.0;
          res->e22335 = 0.0;
          res->e13335 = 0.0;
          res->e23335 = 0.0;
          res->e33335 = 0.0;
          res->e13345 = 0.0;
          res->e23345 = 0.0;
          res->e33345 = 0.0;
          res->e33445 = 0.0;
          res->e13355 = 0.0;
          res->e23355 = 0.0;
          res->e33355 = 0.0;
          res->e33455 = 0.0;
          res->e33555 = 0.0;
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
          res->e11114 = 0.0;
          res->e11124 = 0.0;
          res->e11224 = 0.0;
          res->e12224 = 0.0;
          res->e11134 = 0.0;
          res->e11234 = 0.0;
          res->e12234 = 0.0;
          res->e11334 = 0.0;
          res->e12334 = 0.0;
          res->e13334 = 0.0;
          res->e11144 = 0.0;
          res->e11244 = 0.0;
          res->e12244 = 0.0;
          res->e11344 = 0.0;
          res->e12344 = 0.0;
          res->e13344 = 0.0;
          res->e11444 = 0.0;
          res->e12444 = 0.0;
          res->e13444 = 0.0;
          res->e14444 = 0.0;
          res->e11145 = 0.0;
          res->e11245 = 0.0;
          res->e12245 = 0.0;
          res->e11345 = 0.0;
          res->e12345 = 0.0;
          res->e13345 = 0.0;
          res->e11445 = 0.0;
          res->e12445 = 0.0;
          res->e13445 = 0.0;
          res->e14445 = 0.0;
          res->e11455 = 0.0;
          res->e12455 = 0.0;
          res->e13455 = 0.0;
          res->e14455 = 0.0;
          res->e14555 = 0.0;
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
          res->e11124 = 0.0;
          res->e11224 = 0.0;
          res->e12224 = 0.0;
          res->e22224 = 0.0;
          res->e11234 = 0.0;
          res->e12234 = 0.0;
          res->e22234 = 0.0;
          res->e12334 = 0.0;
          res->e22334 = 0.0;
          res->e23334 = 0.0;
          res->e11244 = 0.0;
          res->e12244 = 0.0;
          res->e22244 = 0.0;
          res->e12344 = 0.0;
          res->e22344 = 0.0;
          res->e23344 = 0.0;
          res->e12444 = 0.0;
          res->e22444 = 0.0;
          res->e23444 = 0.0;
          res->e24444 = 0.0;
          res->e11245 = 0.0;
          res->e12245 = 0.0;
          res->e22245 = 0.0;
          res->e12345 = 0.0;
          res->e22345 = 0.0;
          res->e23345 = 0.0;
          res->e12445 = 0.0;
          res->e22445 = 0.0;
          res->e23445 = 0.0;
          res->e24445 = 0.0;
          res->e12455 = 0.0;
          res->e22455 = 0.0;
          res->e23455 = 0.0;
          res->e24455 = 0.0;
          res->e24555 = 0.0;
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
          res->e11134 = 0.0;
          res->e11234 = 0.0;
          res->e12234 = 0.0;
          res->e22234 = 0.0;
          res->e11334 = 0.0;
          res->e12334 = 0.0;
          res->e22334 = 0.0;
          res->e13334 = 0.0;
          res->e23334 = 0.0;
          res->e33334 = 0.0;
          res->e11344 = 0.0;
          res->e12344 = 0.0;
          res->e22344 = 0.0;
          res->e13344 = 0.0;
          res->e23344 = 0.0;
          res->e33344 = 0.0;
          res->e13444 = 0.0;
          res->e23444 = 0.0;
          res->e33444 = 0.0;
          res->e34444 = 0.0;
          res->e11345 = 0.0;
          res->e12345 = 0.0;
          res->e22345 = 0.0;
          res->e13345 = 0.0;
          res->e23345 = 0.0;
          res->e33345 = 0.0;
          res->e13445 = 0.0;
          res->e23445 = 0.0;
          res->e33445 = 0.0;
          res->e34445 = 0.0;
          res->e13455 = 0.0;
          res->e23455 = 0.0;
          res->e33455 = 0.0;
          res->e34455 = 0.0;
          res->e34555 = 0.0;
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
          res->e11144 = 0.0;
          res->e11244 = 0.0;
          res->e12244 = 0.0;
          res->e22244 = 0.0;
          res->e11344 = 0.0;
          res->e12344 = 0.0;
          res->e22344 = 0.0;
          res->e13344 = 0.0;
          res->e23344 = 0.0;
          res->e33344 = 0.0;
          res->e11444 = 0.0;
          res->e12444 = 0.0;
          res->e22444 = 0.0;
          res->e13444 = 0.0;
          res->e23444 = 0.0;
          res->e33444 = 0.0;
          res->e14444 = 0.0;
          res->e24444 = 0.0;
          res->e34444 = 0.0;
          res->e44444 = 0.0;
          res->e11445 = 0.0;
          res->e12445 = 0.0;
          res->e22445 = 0.0;
          res->e13445 = 0.0;
          res->e23445 = 0.0;
          res->e33445 = 0.0;
          res->e14445 = 0.0;
          res->e24445 = 0.0;
          res->e34445 = 0.0;
          res->e44445 = 0.0;
          res->e14455 = 0.0;
          res->e24455 = 0.0;
          res->e34455 = 0.0;
          res->e44455 = 0.0;
          res->e44555 = 0.0;
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
          res->e11115 = 0.0;
          res->e11125 = 0.0;
          res->e11225 = 0.0;
          res->e12225 = 0.0;
          res->e11135 = 0.0;
          res->e11235 = 0.0;
          res->e12235 = 0.0;
          res->e11335 = 0.0;
          res->e12335 = 0.0;
          res->e13335 = 0.0;
          res->e11145 = 0.0;
          res->e11245 = 0.0;
          res->e12245 = 0.0;
          res->e11345 = 0.0;
          res->e12345 = 0.0;
          res->e13345 = 0.0;
          res->e11445 = 0.0;
          res->e12445 = 0.0;
          res->e13445 = 0.0;
          res->e14445 = 0.0;
          res->e11155 = 0.0;
          res->e11255 = 0.0;
          res->e12255 = 0.0;
          res->e11355 = 0.0;
          res->e12355 = 0.0;
          res->e13355 = 0.0;
          res->e11455 = 0.0;
          res->e12455 = 0.0;
          res->e13455 = 0.0;
          res->e14455 = 0.0;
          res->e11555 = 0.0;
          res->e12555 = 0.0;
          res->e13555 = 0.0;
          res->e14555 = 0.0;
          res->e15555 = 0.0;
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
          res->e11125 = 0.0;
          res->e11225 = 0.0;
          res->e12225 = 0.0;
          res->e22225 = 0.0;
          res->e11235 = 0.0;
          res->e12235 = 0.0;
          res->e22235 = 0.0;
          res->e12335 = 0.0;
          res->e22335 = 0.0;
          res->e23335 = 0.0;
          res->e11245 = 0.0;
          res->e12245 = 0.0;
          res->e22245 = 0.0;
          res->e12345 = 0.0;
          res->e22345 = 0.0;
          res->e23345 = 0.0;
          res->e12445 = 0.0;
          res->e22445 = 0.0;
          res->e23445 = 0.0;
          res->e24445 = 0.0;
          res->e11255 = 0.0;
          res->e12255 = 0.0;
          res->e22255 = 0.0;
          res->e12355 = 0.0;
          res->e22355 = 0.0;
          res->e23355 = 0.0;
          res->e12455 = 0.0;
          res->e22455 = 0.0;
          res->e23455 = 0.0;
          res->e24455 = 0.0;
          res->e12555 = 0.0;
          res->e22555 = 0.0;
          res->e23555 = 0.0;
          res->e24555 = 0.0;
          res->e25555 = 0.0;
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
          res->e11135 = 0.0;
          res->e11235 = 0.0;
          res->e12235 = 0.0;
          res->e22235 = 0.0;
          res->e11335 = 0.0;
          res->e12335 = 0.0;
          res->e22335 = 0.0;
          res->e13335 = 0.0;
          res->e23335 = 0.0;
          res->e33335 = 0.0;
          res->e11345 = 0.0;
          res->e12345 = 0.0;
          res->e22345 = 0.0;
          res->e13345 = 0.0;
          res->e23345 = 0.0;
          res->e33345 = 0.0;
          res->e13445 = 0.0;
          res->e23445 = 0.0;
          res->e33445 = 0.0;
          res->e34445 = 0.0;
          res->e11355 = 0.0;
          res->e12355 = 0.0;
          res->e22355 = 0.0;
          res->e13355 = 0.0;
          res->e23355 = 0.0;
          res->e33355 = 0.0;
          res->e13455 = 0.0;
          res->e23455 = 0.0;
          res->e33455 = 0.0;
          res->e34455 = 0.0;
          res->e13555 = 0.0;
          res->e23555 = 0.0;
          res->e33555 = 0.0;
          res->e34555 = 0.0;
          res->e35555 = 0.0;
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
          res->e11145 = 0.0;
          res->e11245 = 0.0;
          res->e12245 = 0.0;
          res->e22245 = 0.0;
          res->e11345 = 0.0;
          res->e12345 = 0.0;
          res->e22345 = 0.0;
          res->e13345 = 0.0;
          res->e23345 = 0.0;
          res->e33345 = 0.0;
          res->e11445 = 0.0;
          res->e12445 = 0.0;
          res->e22445 = 0.0;
          res->e13445 = 0.0;
          res->e23445 = 0.0;
          res->e33445 = 0.0;
          res->e14445 = 0.0;
          res->e24445 = 0.0;
          res->e34445 = 0.0;
          res->e44445 = 0.0;
          res->e11455 = 0.0;
          res->e12455 = 0.0;
          res->e22455 = 0.0;
          res->e13455 = 0.0;
          res->e23455 = 0.0;
          res->e33455 = 0.0;
          res->e14455 = 0.0;
          res->e24455 = 0.0;
          res->e34455 = 0.0;
          res->e44455 = 0.0;
          res->e14555 = 0.0;
          res->e24555 = 0.0;
          res->e34555 = 0.0;
          res->e44555 = 0.0;
          res->e45555 = 0.0;
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
          res->e11155 = 0.0;
          res->e11255 = 0.0;
          res->e12255 = 0.0;
          res->e22255 = 0.0;
          res->e11355 = 0.0;
          res->e12355 = 0.0;
          res->e22355 = 0.0;
          res->e13355 = 0.0;
          res->e23355 = 0.0;
          res->e33355 = 0.0;
          res->e11455 = 0.0;
          res->e12455 = 0.0;
          res->e22455 = 0.0;
          res->e13455 = 0.0;
          res->e23455 = 0.0;
          res->e33455 = 0.0;
          res->e14455 = 0.0;
          res->e24455 = 0.0;
          res->e34455 = 0.0;
          res->e44455 = 0.0;
          res->e11555 = 0.0;
          res->e12555 = 0.0;
          res->e22555 = 0.0;
          res->e13555 = 0.0;
          res->e23555 = 0.0;
          res->e33555 = 0.0;
          res->e14555 = 0.0;
          res->e24555 = 0.0;
          res->e34555 = 0.0;
          res->e44555 = 0.0;
          res->e15555 = 0.0;
          res->e25555 = 0.0;
          res->e35555 = 0.0;
          res->e45555 = 0.0;
          res->e55555 = 0.0;
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
          res->e11111 = 0.0;
          res->e11112 = 0.0;
          res->e11122 = 0.0;
          res->e11113 = 0.0;
          res->e11123 = 0.0;
          res->e11133 = 0.0;
          res->e11114 = 0.0;
          res->e11124 = 0.0;
          res->e11134 = 0.0;
          res->e11144 = 0.0;
          res->e11115 = 0.0;
          res->e11125 = 0.0;
          res->e11135 = 0.0;
          res->e11145 = 0.0;
          res->e11155 = 0.0;
          break;
        case 1: //  e112
          res->e112 = 0.0;
          res->e1112 = 0.0;
          res->e1122 = 0.0;
          res->e1123 = 0.0;
          res->e1124 = 0.0;
          res->e1125 = 0.0;
          res->e11112 = 0.0;
          res->e11122 = 0.0;
          res->e11222 = 0.0;
          res->e11123 = 0.0;
          res->e11223 = 0.0;
          res->e11233 = 0.0;
          res->e11124 = 0.0;
          res->e11224 = 0.0;
          res->e11234 = 0.0;
          res->e11244 = 0.0;
          res->e11125 = 0.0;
          res->e11225 = 0.0;
          res->e11235 = 0.0;
          res->e11245 = 0.0;
          res->e11255 = 0.0;
          break;
        case 2: //  e122
          res->e122 = 0.0;
          res->e1122 = 0.0;
          res->e1222 = 0.0;
          res->e1223 = 0.0;
          res->e1224 = 0.0;
          res->e1225 = 0.0;
          res->e11122 = 0.0;
          res->e11222 = 0.0;
          res->e12222 = 0.0;
          res->e11223 = 0.0;
          res->e12223 = 0.0;
          res->e12233 = 0.0;
          res->e11224 = 0.0;
          res->e12224 = 0.0;
          res->e12234 = 0.0;
          res->e12244 = 0.0;
          res->e11225 = 0.0;
          res->e12225 = 0.0;
          res->e12235 = 0.0;
          res->e12245 = 0.0;
          res->e12255 = 0.0;
          break;
        case 3: //  e222
          res->e222 = 0.0;
          res->e1222 = 0.0;
          res->e2222 = 0.0;
          res->e2223 = 0.0;
          res->e2224 = 0.0;
          res->e2225 = 0.0;
          res->e11222 = 0.0;
          res->e12222 = 0.0;
          res->e22222 = 0.0;
          res->e12223 = 0.0;
          res->e22223 = 0.0;
          res->e22233 = 0.0;
          res->e12224 = 0.0;
          res->e22224 = 0.0;
          res->e22234 = 0.0;
          res->e22244 = 0.0;
          res->e12225 = 0.0;
          res->e22225 = 0.0;
          res->e22235 = 0.0;
          res->e22245 = 0.0;
          res->e22255 = 0.0;
          break;
        case 4: //  e113
          res->e113 = 0.0;
          res->e1113 = 0.0;
          res->e1123 = 0.0;
          res->e1133 = 0.0;
          res->e1134 = 0.0;
          res->e1135 = 0.0;
          res->e11113 = 0.0;
          res->e11123 = 0.0;
          res->e11223 = 0.0;
          res->e11133 = 0.0;
          res->e11233 = 0.0;
          res->e11333 = 0.0;
          res->e11134 = 0.0;
          res->e11234 = 0.0;
          res->e11334 = 0.0;
          res->e11344 = 0.0;
          res->e11135 = 0.0;
          res->e11235 = 0.0;
          res->e11335 = 0.0;
          res->e11345 = 0.0;
          res->e11355 = 0.0;
          break;
        case 5: //  e123
          res->e123 = 0.0;
          res->e1123 = 0.0;
          res->e1223 = 0.0;
          res->e1233 = 0.0;
          res->e1234 = 0.0;
          res->e1235 = 0.0;
          res->e11123 = 0.0;
          res->e11223 = 0.0;
          res->e12223 = 0.0;
          res->e11233 = 0.0;
          res->e12233 = 0.0;
          res->e12333 = 0.0;
          res->e11234 = 0.0;
          res->e12234 = 0.0;
          res->e12334 = 0.0;
          res->e12344 = 0.0;
          res->e11235 = 0.0;
          res->e12235 = 0.0;
          res->e12335 = 0.0;
          res->e12345 = 0.0;
          res->e12355 = 0.0;
          break;
        case 6: //  e223
          res->e223 = 0.0;
          res->e1223 = 0.0;
          res->e2223 = 0.0;
          res->e2233 = 0.0;
          res->e2234 = 0.0;
          res->e2235 = 0.0;
          res->e11223 = 0.0;
          res->e12223 = 0.0;
          res->e22223 = 0.0;
          res->e12233 = 0.0;
          res->e22233 = 0.0;
          res->e22333 = 0.0;
          res->e12234 = 0.0;
          res->e22234 = 0.0;
          res->e22334 = 0.0;
          res->e22344 = 0.0;
          res->e12235 = 0.0;
          res->e22235 = 0.0;
          res->e22335 = 0.0;
          res->e22345 = 0.0;
          res->e22355 = 0.0;
          break;
        case 7: //  e133
          res->e133 = 0.0;
          res->e1133 = 0.0;
          res->e1233 = 0.0;
          res->e1333 = 0.0;
          res->e1334 = 0.0;
          res->e1335 = 0.0;
          res->e11133 = 0.0;
          res->e11233 = 0.0;
          res->e12233 = 0.0;
          res->e11333 = 0.0;
          res->e12333 = 0.0;
          res->e13333 = 0.0;
          res->e11334 = 0.0;
          res->e12334 = 0.0;
          res->e13334 = 0.0;
          res->e13344 = 0.0;
          res->e11335 = 0.0;
          res->e12335 = 0.0;
          res->e13335 = 0.0;
          res->e13345 = 0.0;
          res->e13355 = 0.0;
          break;
        case 8: //  e233
          res->e233 = 0.0;
          res->e1233 = 0.0;
          res->e2233 = 0.0;
          res->e2333 = 0.0;
          res->e2334 = 0.0;
          res->e2335 = 0.0;
          res->e11233 = 0.0;
          res->e12233 = 0.0;
          res->e22233 = 0.0;
          res->e12333 = 0.0;
          res->e22333 = 0.0;
          res->e23333 = 0.0;
          res->e12334 = 0.0;
          res->e22334 = 0.0;
          res->e23334 = 0.0;
          res->e23344 = 0.0;
          res->e12335 = 0.0;
          res->e22335 = 0.0;
          res->e23335 = 0.0;
          res->e23345 = 0.0;
          res->e23355 = 0.0;
          break;
        case 9: //  e333
          res->e333 = 0.0;
          res->e1333 = 0.0;
          res->e2333 = 0.0;
          res->e3333 = 0.0;
          res->e3334 = 0.0;
          res->e3335 = 0.0;
          res->e11333 = 0.0;
          res->e12333 = 0.0;
          res->e22333 = 0.0;
          res->e13333 = 0.0;
          res->e23333 = 0.0;
          res->e33333 = 0.0;
          res->e13334 = 0.0;
          res->e23334 = 0.0;
          res->e33334 = 0.0;
          res->e33344 = 0.0;
          res->e13335 = 0.0;
          res->e23335 = 0.0;
          res->e33335 = 0.0;
          res->e33345 = 0.0;
          res->e33355 = 0.0;
          break;
        case 10: //  e114
          res->e114 = 0.0;
          res->e1114 = 0.0;
          res->e1124 = 0.0;
          res->e1134 = 0.0;
          res->e1144 = 0.0;
          res->e1145 = 0.0;
          res->e11114 = 0.0;
          res->e11124 = 0.0;
          res->e11224 = 0.0;
          res->e11134 = 0.0;
          res->e11234 = 0.0;
          res->e11334 = 0.0;
          res->e11144 = 0.0;
          res->e11244 = 0.0;
          res->e11344 = 0.0;
          res->e11444 = 0.0;
          res->e11145 = 0.0;
          res->e11245 = 0.0;
          res->e11345 = 0.0;
          res->e11445 = 0.0;
          res->e11455 = 0.0;
          break;
        case 11: //  e124
          res->e124 = 0.0;
          res->e1124 = 0.0;
          res->e1224 = 0.0;
          res->e1234 = 0.0;
          res->e1244 = 0.0;
          res->e1245 = 0.0;
          res->e11124 = 0.0;
          res->e11224 = 0.0;
          res->e12224 = 0.0;
          res->e11234 = 0.0;
          res->e12234 = 0.0;
          res->e12334 = 0.0;
          res->e11244 = 0.0;
          res->e12244 = 0.0;
          res->e12344 = 0.0;
          res->e12444 = 0.0;
          res->e11245 = 0.0;
          res->e12245 = 0.0;
          res->e12345 = 0.0;
          res->e12445 = 0.0;
          res->e12455 = 0.0;
          break;
        case 12: //  e224
          res->e224 = 0.0;
          res->e1224 = 0.0;
          res->e2224 = 0.0;
          res->e2234 = 0.0;
          res->e2244 = 0.0;
          res->e2245 = 0.0;
          res->e11224 = 0.0;
          res->e12224 = 0.0;
          res->e22224 = 0.0;
          res->e12234 = 0.0;
          res->e22234 = 0.0;
          res->e22334 = 0.0;
          res->e12244 = 0.0;
          res->e22244 = 0.0;
          res->e22344 = 0.0;
          res->e22444 = 0.0;
          res->e12245 = 0.0;
          res->e22245 = 0.0;
          res->e22345 = 0.0;
          res->e22445 = 0.0;
          res->e22455 = 0.0;
          break;
        case 13: //  e134
          res->e134 = 0.0;
          res->e1134 = 0.0;
          res->e1234 = 0.0;
          res->e1334 = 0.0;
          res->e1344 = 0.0;
          res->e1345 = 0.0;
          res->e11134 = 0.0;
          res->e11234 = 0.0;
          res->e12234 = 0.0;
          res->e11334 = 0.0;
          res->e12334 = 0.0;
          res->e13334 = 0.0;
          res->e11344 = 0.0;
          res->e12344 = 0.0;
          res->e13344 = 0.0;
          res->e13444 = 0.0;
          res->e11345 = 0.0;
          res->e12345 = 0.0;
          res->e13345 = 0.0;
          res->e13445 = 0.0;
          res->e13455 = 0.0;
          break;
        case 14: //  e234
          res->e234 = 0.0;
          res->e1234 = 0.0;
          res->e2234 = 0.0;
          res->e2334 = 0.0;
          res->e2344 = 0.0;
          res->e2345 = 0.0;
          res->e11234 = 0.0;
          res->e12234 = 0.0;
          res->e22234 = 0.0;
          res->e12334 = 0.0;
          res->e22334 = 0.0;
          res->e23334 = 0.0;
          res->e12344 = 0.0;
          res->e22344 = 0.0;
          res->e23344 = 0.0;
          res->e23444 = 0.0;
          res->e12345 = 0.0;
          res->e22345 = 0.0;
          res->e23345 = 0.0;
          res->e23445 = 0.0;
          res->e23455 = 0.0;
          break;
        case 15: //  e334
          res->e334 = 0.0;
          res->e1334 = 0.0;
          res->e2334 = 0.0;
          res->e3334 = 0.0;
          res->e3344 = 0.0;
          res->e3345 = 0.0;
          res->e11334 = 0.0;
          res->e12334 = 0.0;
          res->e22334 = 0.0;
          res->e13334 = 0.0;
          res->e23334 = 0.0;
          res->e33334 = 0.0;
          res->e13344 = 0.0;
          res->e23344 = 0.0;
          res->e33344 = 0.0;
          res->e33444 = 0.0;
          res->e13345 = 0.0;
          res->e23345 = 0.0;
          res->e33345 = 0.0;
          res->e33445 = 0.0;
          res->e33455 = 0.0;
          break;
        case 16: //  e144
          res->e144 = 0.0;
          res->e1144 = 0.0;
          res->e1244 = 0.0;
          res->e1344 = 0.0;
          res->e1444 = 0.0;
          res->e1445 = 0.0;
          res->e11144 = 0.0;
          res->e11244 = 0.0;
          res->e12244 = 0.0;
          res->e11344 = 0.0;
          res->e12344 = 0.0;
          res->e13344 = 0.0;
          res->e11444 = 0.0;
          res->e12444 = 0.0;
          res->e13444 = 0.0;
          res->e14444 = 0.0;
          res->e11445 = 0.0;
          res->e12445 = 0.0;
          res->e13445 = 0.0;
          res->e14445 = 0.0;
          res->e14455 = 0.0;
          break;
        case 17: //  e244
          res->e244 = 0.0;
          res->e1244 = 0.0;
          res->e2244 = 0.0;
          res->e2344 = 0.0;
          res->e2444 = 0.0;
          res->e2445 = 0.0;
          res->e11244 = 0.0;
          res->e12244 = 0.0;
          res->e22244 = 0.0;
          res->e12344 = 0.0;
          res->e22344 = 0.0;
          res->e23344 = 0.0;
          res->e12444 = 0.0;
          res->e22444 = 0.0;
          res->e23444 = 0.0;
          res->e24444 = 0.0;
          res->e12445 = 0.0;
          res->e22445 = 0.0;
          res->e23445 = 0.0;
          res->e24445 = 0.0;
          res->e24455 = 0.0;
          break;
        case 18: //  e344
          res->e344 = 0.0;
          res->e1344 = 0.0;
          res->e2344 = 0.0;
          res->e3344 = 0.0;
          res->e3444 = 0.0;
          res->e3445 = 0.0;
          res->e11344 = 0.0;
          res->e12344 = 0.0;
          res->e22344 = 0.0;
          res->e13344 = 0.0;
          res->e23344 = 0.0;
          res->e33344 = 0.0;
          res->e13444 = 0.0;
          res->e23444 = 0.0;
          res->e33444 = 0.0;
          res->e34444 = 0.0;
          res->e13445 = 0.0;
          res->e23445 = 0.0;
          res->e33445 = 0.0;
          res->e34445 = 0.0;
          res->e34455 = 0.0;
          break;
        case 19: //  e444
          res->e444 = 0.0;
          res->e1444 = 0.0;
          res->e2444 = 0.0;
          res->e3444 = 0.0;
          res->e4444 = 0.0;
          res->e4445 = 0.0;
          res->e11444 = 0.0;
          res->e12444 = 0.0;
          res->e22444 = 0.0;
          res->e13444 = 0.0;
          res->e23444 = 0.0;
          res->e33444 = 0.0;
          res->e14444 = 0.0;
          res->e24444 = 0.0;
          res->e34444 = 0.0;
          res->e44444 = 0.0;
          res->e14445 = 0.0;
          res->e24445 = 0.0;
          res->e34445 = 0.0;
          res->e44445 = 0.0;
          res->e44455 = 0.0;
          break;
        case 20: //  e115
          res->e115 = 0.0;
          res->e1115 = 0.0;
          res->e1125 = 0.0;
          res->e1135 = 0.0;
          res->e1145 = 0.0;
          res->e1155 = 0.0;
          res->e11115 = 0.0;
          res->e11125 = 0.0;
          res->e11225 = 0.0;
          res->e11135 = 0.0;
          res->e11235 = 0.0;
          res->e11335 = 0.0;
          res->e11145 = 0.0;
          res->e11245 = 0.0;
          res->e11345 = 0.0;
          res->e11445 = 0.0;
          res->e11155 = 0.0;
          res->e11255 = 0.0;
          res->e11355 = 0.0;
          res->e11455 = 0.0;
          res->e11555 = 0.0;
          break;
        case 21: //  e125
          res->e125 = 0.0;
          res->e1125 = 0.0;
          res->e1225 = 0.0;
          res->e1235 = 0.0;
          res->e1245 = 0.0;
          res->e1255 = 0.0;
          res->e11125 = 0.0;
          res->e11225 = 0.0;
          res->e12225 = 0.0;
          res->e11235 = 0.0;
          res->e12235 = 0.0;
          res->e12335 = 0.0;
          res->e11245 = 0.0;
          res->e12245 = 0.0;
          res->e12345 = 0.0;
          res->e12445 = 0.0;
          res->e11255 = 0.0;
          res->e12255 = 0.0;
          res->e12355 = 0.0;
          res->e12455 = 0.0;
          res->e12555 = 0.0;
          break;
        case 22: //  e225
          res->e225 = 0.0;
          res->e1225 = 0.0;
          res->e2225 = 0.0;
          res->e2235 = 0.0;
          res->e2245 = 0.0;
          res->e2255 = 0.0;
          res->e11225 = 0.0;
          res->e12225 = 0.0;
          res->e22225 = 0.0;
          res->e12235 = 0.0;
          res->e22235 = 0.0;
          res->e22335 = 0.0;
          res->e12245 = 0.0;
          res->e22245 = 0.0;
          res->e22345 = 0.0;
          res->e22445 = 0.0;
          res->e12255 = 0.0;
          res->e22255 = 0.0;
          res->e22355 = 0.0;
          res->e22455 = 0.0;
          res->e22555 = 0.0;
          break;
        case 23: //  e135
          res->e135 = 0.0;
          res->e1135 = 0.0;
          res->e1235 = 0.0;
          res->e1335 = 0.0;
          res->e1345 = 0.0;
          res->e1355 = 0.0;
          res->e11135 = 0.0;
          res->e11235 = 0.0;
          res->e12235 = 0.0;
          res->e11335 = 0.0;
          res->e12335 = 0.0;
          res->e13335 = 0.0;
          res->e11345 = 0.0;
          res->e12345 = 0.0;
          res->e13345 = 0.0;
          res->e13445 = 0.0;
          res->e11355 = 0.0;
          res->e12355 = 0.0;
          res->e13355 = 0.0;
          res->e13455 = 0.0;
          res->e13555 = 0.0;
          break;
        case 24: //  e235
          res->e235 = 0.0;
          res->e1235 = 0.0;
          res->e2235 = 0.0;
          res->e2335 = 0.0;
          res->e2345 = 0.0;
          res->e2355 = 0.0;
          res->e11235 = 0.0;
          res->e12235 = 0.0;
          res->e22235 = 0.0;
          res->e12335 = 0.0;
          res->e22335 = 0.0;
          res->e23335 = 0.0;
          res->e12345 = 0.0;
          res->e22345 = 0.0;
          res->e23345 = 0.0;
          res->e23445 = 0.0;
          res->e12355 = 0.0;
          res->e22355 = 0.0;
          res->e23355 = 0.0;
          res->e23455 = 0.0;
          res->e23555 = 0.0;
          break;
        case 25: //  e335
          res->e335 = 0.0;
          res->e1335 = 0.0;
          res->e2335 = 0.0;
          res->e3335 = 0.0;
          res->e3345 = 0.0;
          res->e3355 = 0.0;
          res->e11335 = 0.0;
          res->e12335 = 0.0;
          res->e22335 = 0.0;
          res->e13335 = 0.0;
          res->e23335 = 0.0;
          res->e33335 = 0.0;
          res->e13345 = 0.0;
          res->e23345 = 0.0;
          res->e33345 = 0.0;
          res->e33445 = 0.0;
          res->e13355 = 0.0;
          res->e23355 = 0.0;
          res->e33355 = 0.0;
          res->e33455 = 0.0;
          res->e33555 = 0.0;
          break;
        case 26: //  e145
          res->e145 = 0.0;
          res->e1145 = 0.0;
          res->e1245 = 0.0;
          res->e1345 = 0.0;
          res->e1445 = 0.0;
          res->e1455 = 0.0;
          res->e11145 = 0.0;
          res->e11245 = 0.0;
          res->e12245 = 0.0;
          res->e11345 = 0.0;
          res->e12345 = 0.0;
          res->e13345 = 0.0;
          res->e11445 = 0.0;
          res->e12445 = 0.0;
          res->e13445 = 0.0;
          res->e14445 = 0.0;
          res->e11455 = 0.0;
          res->e12455 = 0.0;
          res->e13455 = 0.0;
          res->e14455 = 0.0;
          res->e14555 = 0.0;
          break;
        case 27: //  e245
          res->e245 = 0.0;
          res->e1245 = 0.0;
          res->e2245 = 0.0;
          res->e2345 = 0.0;
          res->e2445 = 0.0;
          res->e2455 = 0.0;
          res->e11245 = 0.0;
          res->e12245 = 0.0;
          res->e22245 = 0.0;
          res->e12345 = 0.0;
          res->e22345 = 0.0;
          res->e23345 = 0.0;
          res->e12445 = 0.0;
          res->e22445 = 0.0;
          res->e23445 = 0.0;
          res->e24445 = 0.0;
          res->e12455 = 0.0;
          res->e22455 = 0.0;
          res->e23455 = 0.0;
          res->e24455 = 0.0;
          res->e24555 = 0.0;
          break;
        case 28: //  e345
          res->e345 = 0.0;
          res->e1345 = 0.0;
          res->e2345 = 0.0;
          res->e3345 = 0.0;
          res->e3445 = 0.0;
          res->e3455 = 0.0;
          res->e11345 = 0.0;
          res->e12345 = 0.0;
          res->e22345 = 0.0;
          res->e13345 = 0.0;
          res->e23345 = 0.0;
          res->e33345 = 0.0;
          res->e13445 = 0.0;
          res->e23445 = 0.0;
          res->e33445 = 0.0;
          res->e34445 = 0.0;
          res->e13455 = 0.0;
          res->e23455 = 0.0;
          res->e33455 = 0.0;
          res->e34455 = 0.0;
          res->e34555 = 0.0;
          break;
        case 29: //  e445
          res->e445 = 0.0;
          res->e1445 = 0.0;
          res->e2445 = 0.0;
          res->e3445 = 0.0;
          res->e4445 = 0.0;
          res->e4455 = 0.0;
          res->e11445 = 0.0;
          res->e12445 = 0.0;
          res->e22445 = 0.0;
          res->e13445 = 0.0;
          res->e23445 = 0.0;
          res->e33445 = 0.0;
          res->e14445 = 0.0;
          res->e24445 = 0.0;
          res->e34445 = 0.0;
          res->e44445 = 0.0;
          res->e14455 = 0.0;
          res->e24455 = 0.0;
          res->e34455 = 0.0;
          res->e44455 = 0.0;
          res->e44555 = 0.0;
          break;
        case 30: //  e155
          res->e155 = 0.0;
          res->e1155 = 0.0;
          res->e1255 = 0.0;
          res->e1355 = 0.0;
          res->e1455 = 0.0;
          res->e1555 = 0.0;
          res->e11155 = 0.0;
          res->e11255 = 0.0;
          res->e12255 = 0.0;
          res->e11355 = 0.0;
          res->e12355 = 0.0;
          res->e13355 = 0.0;
          res->e11455 = 0.0;
          res->e12455 = 0.0;
          res->e13455 = 0.0;
          res->e14455 = 0.0;
          res->e11555 = 0.0;
          res->e12555 = 0.0;
          res->e13555 = 0.0;
          res->e14555 = 0.0;
          res->e15555 = 0.0;
          break;
        case 31: //  e255
          res->e255 = 0.0;
          res->e1255 = 0.0;
          res->e2255 = 0.0;
          res->e2355 = 0.0;
          res->e2455 = 0.0;
          res->e2555 = 0.0;
          res->e11255 = 0.0;
          res->e12255 = 0.0;
          res->e22255 = 0.0;
          res->e12355 = 0.0;
          res->e22355 = 0.0;
          res->e23355 = 0.0;
          res->e12455 = 0.0;
          res->e22455 = 0.0;
          res->e23455 = 0.0;
          res->e24455 = 0.0;
          res->e12555 = 0.0;
          res->e22555 = 0.0;
          res->e23555 = 0.0;
          res->e24555 = 0.0;
          res->e25555 = 0.0;
          break;
        case 32: //  e355
          res->e355 = 0.0;
          res->e1355 = 0.0;
          res->e2355 = 0.0;
          res->e3355 = 0.0;
          res->e3455 = 0.0;
          res->e3555 = 0.0;
          res->e11355 = 0.0;
          res->e12355 = 0.0;
          res->e22355 = 0.0;
          res->e13355 = 0.0;
          res->e23355 = 0.0;
          res->e33355 = 0.0;
          res->e13455 = 0.0;
          res->e23455 = 0.0;
          res->e33455 = 0.0;
          res->e34455 = 0.0;
          res->e13555 = 0.0;
          res->e23555 = 0.0;
          res->e33555 = 0.0;
          res->e34555 = 0.0;
          res->e35555 = 0.0;
          break;
        case 33: //  e455
          res->e455 = 0.0;
          res->e1455 = 0.0;
          res->e2455 = 0.0;
          res->e3455 = 0.0;
          res->e4455 = 0.0;
          res->e4555 = 0.0;
          res->e11455 = 0.0;
          res->e12455 = 0.0;
          res->e22455 = 0.0;
          res->e13455 = 0.0;
          res->e23455 = 0.0;
          res->e33455 = 0.0;
          res->e14455 = 0.0;
          res->e24455 = 0.0;
          res->e34455 = 0.0;
          res->e44455 = 0.0;
          res->e14555 = 0.0;
          res->e24555 = 0.0;
          res->e34555 = 0.0;
          res->e44555 = 0.0;
          res->e45555 = 0.0;
          break;
        case 34: //  e555
          res->e555 = 0.0;
          res->e1555 = 0.0;
          res->e2555 = 0.0;
          res->e3555 = 0.0;
          res->e4555 = 0.0;
          res->e5555 = 0.0;
          res->e11555 = 0.0;
          res->e12555 = 0.0;
          res->e22555 = 0.0;
          res->e13555 = 0.0;
          res->e23555 = 0.0;
          res->e33555 = 0.0;
          res->e14555 = 0.0;
          res->e24555 = 0.0;
          res->e34555 = 0.0;
          res->e44555 = 0.0;
          res->e15555 = 0.0;
          res->e25555 = 0.0;
          res->e35555 = 0.0;
          res->e45555 = 0.0;
          res->e55555 = 0.0;
          break;
      }
      break;
    case 4:
      switch (idx){
        case 0: //  e1111
          res->e1111 = 0.0;
          res->e11111 = 0.0;
          res->e11112 = 0.0;
          res->e11113 = 0.0;
          res->e11114 = 0.0;
          res->e11115 = 0.0;
          break;
        case 1: //  e1112
          res->e1112 = 0.0;
          res->e11112 = 0.0;
          res->e11122 = 0.0;
          res->e11123 = 0.0;
          res->e11124 = 0.0;
          res->e11125 = 0.0;
          break;
        case 2: //  e1122
          res->e1122 = 0.0;
          res->e11122 = 0.0;
          res->e11222 = 0.0;
          res->e11223 = 0.0;
          res->e11224 = 0.0;
          res->e11225 = 0.0;
          break;
        case 3: //  e1222
          res->e1222 = 0.0;
          res->e11222 = 0.0;
          res->e12222 = 0.0;
          res->e12223 = 0.0;
          res->e12224 = 0.0;
          res->e12225 = 0.0;
          break;
        case 4: //  e2222
          res->e2222 = 0.0;
          res->e12222 = 0.0;
          res->e22222 = 0.0;
          res->e22223 = 0.0;
          res->e22224 = 0.0;
          res->e22225 = 0.0;
          break;
        case 5: //  e1113
          res->e1113 = 0.0;
          res->e11113 = 0.0;
          res->e11123 = 0.0;
          res->e11133 = 0.0;
          res->e11134 = 0.0;
          res->e11135 = 0.0;
          break;
        case 6: //  e1123
          res->e1123 = 0.0;
          res->e11123 = 0.0;
          res->e11223 = 0.0;
          res->e11233 = 0.0;
          res->e11234 = 0.0;
          res->e11235 = 0.0;
          break;
        case 7: //  e1223
          res->e1223 = 0.0;
          res->e11223 = 0.0;
          res->e12223 = 0.0;
          res->e12233 = 0.0;
          res->e12234 = 0.0;
          res->e12235 = 0.0;
          break;
        case 8: //  e2223
          res->e2223 = 0.0;
          res->e12223 = 0.0;
          res->e22223 = 0.0;
          res->e22233 = 0.0;
          res->e22234 = 0.0;
          res->e22235 = 0.0;
          break;
        case 9: //  e1133
          res->e1133 = 0.0;
          res->e11133 = 0.0;
          res->e11233 = 0.0;
          res->e11333 = 0.0;
          res->e11334 = 0.0;
          res->e11335 = 0.0;
          break;
        case 10: //  e1233
          res->e1233 = 0.0;
          res->e11233 = 0.0;
          res->e12233 = 0.0;
          res->e12333 = 0.0;
          res->e12334 = 0.0;
          res->e12335 = 0.0;
          break;
        case 11: //  e2233
          res->e2233 = 0.0;
          res->e12233 = 0.0;
          res->e22233 = 0.0;
          res->e22333 = 0.0;
          res->e22334 = 0.0;
          res->e22335 = 0.0;
          break;
        case 12: //  e1333
          res->e1333 = 0.0;
          res->e11333 = 0.0;
          res->e12333 = 0.0;
          res->e13333 = 0.0;
          res->e13334 = 0.0;
          res->e13335 = 0.0;
          break;
        case 13: //  e2333
          res->e2333 = 0.0;
          res->e12333 = 0.0;
          res->e22333 = 0.0;
          res->e23333 = 0.0;
          res->e23334 = 0.0;
          res->e23335 = 0.0;
          break;
        case 14: //  e3333
          res->e3333 = 0.0;
          res->e13333 = 0.0;
          res->e23333 = 0.0;
          res->e33333 = 0.0;
          res->e33334 = 0.0;
          res->e33335 = 0.0;
          break;
        case 15: //  e1114
          res->e1114 = 0.0;
          res->e11114 = 0.0;
          res->e11124 = 0.0;
          res->e11134 = 0.0;
          res->e11144 = 0.0;
          res->e11145 = 0.0;
          break;
        case 16: //  e1124
          res->e1124 = 0.0;
          res->e11124 = 0.0;
          res->e11224 = 0.0;
          res->e11234 = 0.0;
          res->e11244 = 0.0;
          res->e11245 = 0.0;
          break;
        case 17: //  e1224
          res->e1224 = 0.0;
          res->e11224 = 0.0;
          res->e12224 = 0.0;
          res->e12234 = 0.0;
          res->e12244 = 0.0;
          res->e12245 = 0.0;
          break;
        case 18: //  e2224
          res->e2224 = 0.0;
          res->e12224 = 0.0;
          res->e22224 = 0.0;
          res->e22234 = 0.0;
          res->e22244 = 0.0;
          res->e22245 = 0.0;
          break;
        case 19: //  e1134
          res->e1134 = 0.0;
          res->e11134 = 0.0;
          res->e11234 = 0.0;
          res->e11334 = 0.0;
          res->e11344 = 0.0;
          res->e11345 = 0.0;
          break;
        case 20: //  e1234
          res->e1234 = 0.0;
          res->e11234 = 0.0;
          res->e12234 = 0.0;
          res->e12334 = 0.0;
          res->e12344 = 0.0;
          res->e12345 = 0.0;
          break;
        case 21: //  e2234
          res->e2234 = 0.0;
          res->e12234 = 0.0;
          res->e22234 = 0.0;
          res->e22334 = 0.0;
          res->e22344 = 0.0;
          res->e22345 = 0.0;
          break;
        case 22: //  e1334
          res->e1334 = 0.0;
          res->e11334 = 0.0;
          res->e12334 = 0.0;
          res->e13334 = 0.0;
          res->e13344 = 0.0;
          res->e13345 = 0.0;
          break;
        case 23: //  e2334
          res->e2334 = 0.0;
          res->e12334 = 0.0;
          res->e22334 = 0.0;
          res->e23334 = 0.0;
          res->e23344 = 0.0;
          res->e23345 = 0.0;
          break;
        case 24: //  e3334
          res->e3334 = 0.0;
          res->e13334 = 0.0;
          res->e23334 = 0.0;
          res->e33334 = 0.0;
          res->e33344 = 0.0;
          res->e33345 = 0.0;
          break;
        case 25: //  e1144
          res->e1144 = 0.0;
          res->e11144 = 0.0;
          res->e11244 = 0.0;
          res->e11344 = 0.0;
          res->e11444 = 0.0;
          res->e11445 = 0.0;
          break;
        case 26: //  e1244
          res->e1244 = 0.0;
          res->e11244 = 0.0;
          res->e12244 = 0.0;
          res->e12344 = 0.0;
          res->e12444 = 0.0;
          res->e12445 = 0.0;
          break;
        case 27: //  e2244
          res->e2244 = 0.0;
          res->e12244 = 0.0;
          res->e22244 = 0.0;
          res->e22344 = 0.0;
          res->e22444 = 0.0;
          res->e22445 = 0.0;
          break;
        case 28: //  e1344
          res->e1344 = 0.0;
          res->e11344 = 0.0;
          res->e12344 = 0.0;
          res->e13344 = 0.0;
          res->e13444 = 0.0;
          res->e13445 = 0.0;
          break;
        case 29: //  e2344
          res->e2344 = 0.0;
          res->e12344 = 0.0;
          res->e22344 = 0.0;
          res->e23344 = 0.0;
          res->e23444 = 0.0;
          res->e23445 = 0.0;
          break;
        case 30: //  e3344
          res->e3344 = 0.0;
          res->e13344 = 0.0;
          res->e23344 = 0.0;
          res->e33344 = 0.0;
          res->e33444 = 0.0;
          res->e33445 = 0.0;
          break;
        case 31: //  e1444
          res->e1444 = 0.0;
          res->e11444 = 0.0;
          res->e12444 = 0.0;
          res->e13444 = 0.0;
          res->e14444 = 0.0;
          res->e14445 = 0.0;
          break;
        case 32: //  e2444
          res->e2444 = 0.0;
          res->e12444 = 0.0;
          res->e22444 = 0.0;
          res->e23444 = 0.0;
          res->e24444 = 0.0;
          res->e24445 = 0.0;
          break;
        case 33: //  e3444
          res->e3444 = 0.0;
          res->e13444 = 0.0;
          res->e23444 = 0.0;
          res->e33444 = 0.0;
          res->e34444 = 0.0;
          res->e34445 = 0.0;
          break;
        case 34: //  e4444
          res->e4444 = 0.0;
          res->e14444 = 0.0;
          res->e24444 = 0.0;
          res->e34444 = 0.0;
          res->e44444 = 0.0;
          res->e44445 = 0.0;
          break;
        case 35: //  e1115
          res->e1115 = 0.0;
          res->e11115 = 0.0;
          res->e11125 = 0.0;
          res->e11135 = 0.0;
          res->e11145 = 0.0;
          res->e11155 = 0.0;
          break;
        case 36: //  e1125
          res->e1125 = 0.0;
          res->e11125 = 0.0;
          res->e11225 = 0.0;
          res->e11235 = 0.0;
          res->e11245 = 0.0;
          res->e11255 = 0.0;
          break;
        case 37: //  e1225
          res->e1225 = 0.0;
          res->e11225 = 0.0;
          res->e12225 = 0.0;
          res->e12235 = 0.0;
          res->e12245 = 0.0;
          res->e12255 = 0.0;
          break;
        case 38: //  e2225
          res->e2225 = 0.0;
          res->e12225 = 0.0;
          res->e22225 = 0.0;
          res->e22235 = 0.0;
          res->e22245 = 0.0;
          res->e22255 = 0.0;
          break;
        case 39: //  e1135
          res->e1135 = 0.0;
          res->e11135 = 0.0;
          res->e11235 = 0.0;
          res->e11335 = 0.0;
          res->e11345 = 0.0;
          res->e11355 = 0.0;
          break;
        case 40: //  e1235
          res->e1235 = 0.0;
          res->e11235 = 0.0;
          res->e12235 = 0.0;
          res->e12335 = 0.0;
          res->e12345 = 0.0;
          res->e12355 = 0.0;
          break;
        case 41: //  e2235
          res->e2235 = 0.0;
          res->e12235 = 0.0;
          res->e22235 = 0.0;
          res->e22335 = 0.0;
          res->e22345 = 0.0;
          res->e22355 = 0.0;
          break;
        case 42: //  e1335
          res->e1335 = 0.0;
          res->e11335 = 0.0;
          res->e12335 = 0.0;
          res->e13335 = 0.0;
          res->e13345 = 0.0;
          res->e13355 = 0.0;
          break;
        case 43: //  e2335
          res->e2335 = 0.0;
          res->e12335 = 0.0;
          res->e22335 = 0.0;
          res->e23335 = 0.0;
          res->e23345 = 0.0;
          res->e23355 = 0.0;
          break;
        case 44: //  e3335
          res->e3335 = 0.0;
          res->e13335 = 0.0;
          res->e23335 = 0.0;
          res->e33335 = 0.0;
          res->e33345 = 0.0;
          res->e33355 = 0.0;
          break;
        case 45: //  e1145
          res->e1145 = 0.0;
          res->e11145 = 0.0;
          res->e11245 = 0.0;
          res->e11345 = 0.0;
          res->e11445 = 0.0;
          res->e11455 = 0.0;
          break;
        case 46: //  e1245
          res->e1245 = 0.0;
          res->e11245 = 0.0;
          res->e12245 = 0.0;
          res->e12345 = 0.0;
          res->e12445 = 0.0;
          res->e12455 = 0.0;
          break;
        case 47: //  e2245
          res->e2245 = 0.0;
          res->e12245 = 0.0;
          res->e22245 = 0.0;
          res->e22345 = 0.0;
          res->e22445 = 0.0;
          res->e22455 = 0.0;
          break;
        case 48: //  e1345
          res->e1345 = 0.0;
          res->e11345 = 0.0;
          res->e12345 = 0.0;
          res->e13345 = 0.0;
          res->e13445 = 0.0;
          res->e13455 = 0.0;
          break;
        case 49: //  e2345
          res->e2345 = 0.0;
          res->e12345 = 0.0;
          res->e22345 = 0.0;
          res->e23345 = 0.0;
          res->e23445 = 0.0;
          res->e23455 = 0.0;
          break;
        case 50: //  e3345
          res->e3345 = 0.0;
          res->e13345 = 0.0;
          res->e23345 = 0.0;
          res->e33345 = 0.0;
          res->e33445 = 0.0;
          res->e33455 = 0.0;
          break;
        case 51: //  e1445
          res->e1445 = 0.0;
          res->e11445 = 0.0;
          res->e12445 = 0.0;
          res->e13445 = 0.0;
          res->e14445 = 0.0;
          res->e14455 = 0.0;
          break;
        case 52: //  e2445
          res->e2445 = 0.0;
          res->e12445 = 0.0;
          res->e22445 = 0.0;
          res->e23445 = 0.0;
          res->e24445 = 0.0;
          res->e24455 = 0.0;
          break;
        case 53: //  e3445
          res->e3445 = 0.0;
          res->e13445 = 0.0;
          res->e23445 = 0.0;
          res->e33445 = 0.0;
          res->e34445 = 0.0;
          res->e34455 = 0.0;
          break;
        case 54: //  e4445
          res->e4445 = 0.0;
          res->e14445 = 0.0;
          res->e24445 = 0.0;
          res->e34445 = 0.0;
          res->e44445 = 0.0;
          res->e44455 = 0.0;
          break;
        case 55: //  e1155
          res->e1155 = 0.0;
          res->e11155 = 0.0;
          res->e11255 = 0.0;
          res->e11355 = 0.0;
          res->e11455 = 0.0;
          res->e11555 = 0.0;
          break;
        case 56: //  e1255
          res->e1255 = 0.0;
          res->e11255 = 0.0;
          res->e12255 = 0.0;
          res->e12355 = 0.0;
          res->e12455 = 0.0;
          res->e12555 = 0.0;
          break;
        case 57: //  e2255
          res->e2255 = 0.0;
          res->e12255 = 0.0;
          res->e22255 = 0.0;
          res->e22355 = 0.0;
          res->e22455 = 0.0;
          res->e22555 = 0.0;
          break;
        case 58: //  e1355
          res->e1355 = 0.0;
          res->e11355 = 0.0;
          res->e12355 = 0.0;
          res->e13355 = 0.0;
          res->e13455 = 0.0;
          res->e13555 = 0.0;
          break;
        case 59: //  e2355
          res->e2355 = 0.0;
          res->e12355 = 0.0;
          res->e22355 = 0.0;
          res->e23355 = 0.0;
          res->e23455 = 0.0;
          res->e23555 = 0.0;
          break;
        case 60: //  e3355
          res->e3355 = 0.0;
          res->e13355 = 0.0;
          res->e23355 = 0.0;
          res->e33355 = 0.0;
          res->e33455 = 0.0;
          res->e33555 = 0.0;
          break;
        case 61: //  e1455
          res->e1455 = 0.0;
          res->e11455 = 0.0;
          res->e12455 = 0.0;
          res->e13455 = 0.0;
          res->e14455 = 0.0;
          res->e14555 = 0.0;
          break;
        case 62: //  e2455
          res->e2455 = 0.0;
          res->e12455 = 0.0;
          res->e22455 = 0.0;
          res->e23455 = 0.0;
          res->e24455 = 0.0;
          res->e24555 = 0.0;
          break;
        case 63: //  e3455
          res->e3455 = 0.0;
          res->e13455 = 0.0;
          res->e23455 = 0.0;
          res->e33455 = 0.0;
          res->e34455 = 0.0;
          res->e34555 = 0.0;
          break;
        case 64: //  e4455
          res->e4455 = 0.0;
          res->e14455 = 0.0;
          res->e24455 = 0.0;
          res->e34455 = 0.0;
          res->e44455 = 0.0;
          res->e44555 = 0.0;
          break;
        case 65: //  e1555
          res->e1555 = 0.0;
          res->e11555 = 0.0;
          res->e12555 = 0.0;
          res->e13555 = 0.0;
          res->e14555 = 0.0;
          res->e15555 = 0.0;
          break;
        case 66: //  e2555
          res->e2555 = 0.0;
          res->e12555 = 0.0;
          res->e22555 = 0.0;
          res->e23555 = 0.0;
          res->e24555 = 0.0;
          res->e25555 = 0.0;
          break;
        case 67: //  e3555
          res->e3555 = 0.0;
          res->e13555 = 0.0;
          res->e23555 = 0.0;
          res->e33555 = 0.0;
          res->e34555 = 0.0;
          res->e35555 = 0.0;
          break;
        case 68: //  e4555
          res->e4555 = 0.0;
          res->e14555 = 0.0;
          res->e24555 = 0.0;
          res->e34555 = 0.0;
          res->e44555 = 0.0;
          res->e45555 = 0.0;
          break;
        case 69: //  e5555
          res->e5555 = 0.0;
          res->e15555 = 0.0;
          res->e25555 = 0.0;
          res->e35555 = 0.0;
          res->e45555 = 0.0;
          res->e55555 = 0.0;
          break;
      }
      break;
    case 5:
      switch (idx){
        case 0: //  e11111
          res->e11111 = 0.0;
          break;
        case 1: //  e11112
          res->e11112 = 0.0;
          break;
        case 2: //  e11122
          res->e11122 = 0.0;
          break;
        case 3: //  e11222
          res->e11222 = 0.0;
          break;
        case 4: //  e12222
          res->e12222 = 0.0;
          break;
        case 5: //  e22222
          res->e22222 = 0.0;
          break;
        case 6: //  e11113
          res->e11113 = 0.0;
          break;
        case 7: //  e11123
          res->e11123 = 0.0;
          break;
        case 8: //  e11223
          res->e11223 = 0.0;
          break;
        case 9: //  e12223
          res->e12223 = 0.0;
          break;
        case 10: //  e22223
          res->e22223 = 0.0;
          break;
        case 11: //  e11133
          res->e11133 = 0.0;
          break;
        case 12: //  e11233
          res->e11233 = 0.0;
          break;
        case 13: //  e12233
          res->e12233 = 0.0;
          break;
        case 14: //  e22233
          res->e22233 = 0.0;
          break;
        case 15: //  e11333
          res->e11333 = 0.0;
          break;
        case 16: //  e12333
          res->e12333 = 0.0;
          break;
        case 17: //  e22333
          res->e22333 = 0.0;
          break;
        case 18: //  e13333
          res->e13333 = 0.0;
          break;
        case 19: //  e23333
          res->e23333 = 0.0;
          break;
        case 20: //  e33333
          res->e33333 = 0.0;
          break;
        case 21: //  e11114
          res->e11114 = 0.0;
          break;
        case 22: //  e11124
          res->e11124 = 0.0;
          break;
        case 23: //  e11224
          res->e11224 = 0.0;
          break;
        case 24: //  e12224
          res->e12224 = 0.0;
          break;
        case 25: //  e22224
          res->e22224 = 0.0;
          break;
        case 26: //  e11134
          res->e11134 = 0.0;
          break;
        case 27: //  e11234
          res->e11234 = 0.0;
          break;
        case 28: //  e12234
          res->e12234 = 0.0;
          break;
        case 29: //  e22234
          res->e22234 = 0.0;
          break;
        case 30: //  e11334
          res->e11334 = 0.0;
          break;
        case 31: //  e12334
          res->e12334 = 0.0;
          break;
        case 32: //  e22334
          res->e22334 = 0.0;
          break;
        case 33: //  e13334
          res->e13334 = 0.0;
          break;
        case 34: //  e23334
          res->e23334 = 0.0;
          break;
        case 35: //  e33334
          res->e33334 = 0.0;
          break;
        case 36: //  e11144
          res->e11144 = 0.0;
          break;
        case 37: //  e11244
          res->e11244 = 0.0;
          break;
        case 38: //  e12244
          res->e12244 = 0.0;
          break;
        case 39: //  e22244
          res->e22244 = 0.0;
          break;
        case 40: //  e11344
          res->e11344 = 0.0;
          break;
        case 41: //  e12344
          res->e12344 = 0.0;
          break;
        case 42: //  e22344
          res->e22344 = 0.0;
          break;
        case 43: //  e13344
          res->e13344 = 0.0;
          break;
        case 44: //  e23344
          res->e23344 = 0.0;
          break;
        case 45: //  e33344
          res->e33344 = 0.0;
          break;
        case 46: //  e11444
          res->e11444 = 0.0;
          break;
        case 47: //  e12444
          res->e12444 = 0.0;
          break;
        case 48: //  e22444
          res->e22444 = 0.0;
          break;
        case 49: //  e13444
          res->e13444 = 0.0;
          break;
        case 50: //  e23444
          res->e23444 = 0.0;
          break;
        case 51: //  e33444
          res->e33444 = 0.0;
          break;
        case 52: //  e14444
          res->e14444 = 0.0;
          break;
        case 53: //  e24444
          res->e24444 = 0.0;
          break;
        case 54: //  e34444
          res->e34444 = 0.0;
          break;
        case 55: //  e44444
          res->e44444 = 0.0;
          break;
        case 56: //  e11115
          res->e11115 = 0.0;
          break;
        case 57: //  e11125
          res->e11125 = 0.0;
          break;
        case 58: //  e11225
          res->e11225 = 0.0;
          break;
        case 59: //  e12225
          res->e12225 = 0.0;
          break;
        case 60: //  e22225
          res->e22225 = 0.0;
          break;
        case 61: //  e11135
          res->e11135 = 0.0;
          break;
        case 62: //  e11235
          res->e11235 = 0.0;
          break;
        case 63: //  e12235
          res->e12235 = 0.0;
          break;
        case 64: //  e22235
          res->e22235 = 0.0;
          break;
        case 65: //  e11335
          res->e11335 = 0.0;
          break;
        case 66: //  e12335
          res->e12335 = 0.0;
          break;
        case 67: //  e22335
          res->e22335 = 0.0;
          break;
        case 68: //  e13335
          res->e13335 = 0.0;
          break;
        case 69: //  e23335
          res->e23335 = 0.0;
          break;
        case 70: //  e33335
          res->e33335 = 0.0;
          break;
        case 71: //  e11145
          res->e11145 = 0.0;
          break;
        case 72: //  e11245
          res->e11245 = 0.0;
          break;
        case 73: //  e12245
          res->e12245 = 0.0;
          break;
        case 74: //  e22245
          res->e22245 = 0.0;
          break;
        case 75: //  e11345
          res->e11345 = 0.0;
          break;
        case 76: //  e12345
          res->e12345 = 0.0;
          break;
        case 77: //  e22345
          res->e22345 = 0.0;
          break;
        case 78: //  e13345
          res->e13345 = 0.0;
          break;
        case 79: //  e23345
          res->e23345 = 0.0;
          break;
        case 80: //  e33345
          res->e33345 = 0.0;
          break;
        case 81: //  e11445
          res->e11445 = 0.0;
          break;
        case 82: //  e12445
          res->e12445 = 0.0;
          break;
        case 83: //  e22445
          res->e22445 = 0.0;
          break;
        case 84: //  e13445
          res->e13445 = 0.0;
          break;
        case 85: //  e23445
          res->e23445 = 0.0;
          break;
        case 86: //  e33445
          res->e33445 = 0.0;
          break;
        case 87: //  e14445
          res->e14445 = 0.0;
          break;
        case 88: //  e24445
          res->e24445 = 0.0;
          break;
        case 89: //  e34445
          res->e34445 = 0.0;
          break;
        case 90: //  e44445
          res->e44445 = 0.0;
          break;
        case 91: //  e11155
          res->e11155 = 0.0;
          break;
        case 92: //  e11255
          res->e11255 = 0.0;
          break;
        case 93: //  e12255
          res->e12255 = 0.0;
          break;
        case 94: //  e22255
          res->e22255 = 0.0;
          break;
        case 95: //  e11355
          res->e11355 = 0.0;
          break;
        case 96: //  e12355
          res->e12355 = 0.0;
          break;
        case 97: //  e22355
          res->e22355 = 0.0;
          break;
        case 98: //  e13355
          res->e13355 = 0.0;
          break;
        case 99: //  e23355
          res->e23355 = 0.0;
          break;
        case 100: //  e33355
          res->e33355 = 0.0;
          break;
        case 101: //  e11455
          res->e11455 = 0.0;
          break;
        case 102: //  e12455
          res->e12455 = 0.0;
          break;
        case 103: //  e22455
          res->e22455 = 0.0;
          break;
        case 104: //  e13455
          res->e13455 = 0.0;
          break;
        case 105: //  e23455
          res->e23455 = 0.0;
          break;
        case 106: //  e33455
          res->e33455 = 0.0;
          break;
        case 107: //  e14455
          res->e14455 = 0.0;
          break;
        case 108: //  e24455
          res->e24455 = 0.0;
          break;
        case 109: //  e34455
          res->e34455 = 0.0;
          break;
        case 110: //  e44455
          res->e44455 = 0.0;
          break;
        case 111: //  e11555
          res->e11555 = 0.0;
          break;
        case 112: //  e12555
          res->e12555 = 0.0;
          break;
        case 113: //  e22555
          res->e22555 = 0.0;
          break;
        case 114: //  e13555
          res->e13555 = 0.0;
          break;
        case 115: //  e23555
          res->e23555 = 0.0;
          break;
        case 116: //  e33555
          res->e33555 = 0.0;
          break;
        case 117: //  e14555
          res->e14555 = 0.0;
          break;
        case 118: //  e24555
          res->e24555 = 0.0;
          break;
        case 119: //  e34555
          res->e34555 = 0.0;
          break;
        case 120: //  e44555
          res->e44555 = 0.0;
          break;
        case 121: //  e15555
          res->e15555 = 0.0;
          break;
        case 122: //  e25555
          res->e25555 = 0.0;
          break;
        case 123: //  e35555
          res->e35555 = 0.0;
          break;
        case 124: //  e45555
          res->e45555 = 0.0;
          break;
        case 125: //  e55555
          res->e55555 = 0.0;
          break;
      }
      break;
  }
}

void onumm5n5_print(  onumm5n5_t* lhs){

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
  //  Order 5;
  printf(" %+.8g*e11111",lhs->e11111);
  printf(" %+.8g*e11112",lhs->e11112);
  printf(" %+.8g*e11122",lhs->e11122);
  printf(" %+.8g*e11222",lhs->e11222);
  printf(" %+.8g*e12222",lhs->e12222);
  printf(" %+.8g*e22222",lhs->e22222);
  printf(" %+.8g*e11113",lhs->e11113);
  printf(" %+.8g*e11123",lhs->e11123);
  printf(" %+.8g*e11223",lhs->e11223);
  printf(" %+.8g*e12223",lhs->e12223);
  printf(" %+.8g*e22223",lhs->e22223);
  printf(" %+.8g*e11133",lhs->e11133);
  printf(" %+.8g*e11233",lhs->e11233);
  printf(" %+.8g*e12233",lhs->e12233);
  printf(" %+.8g*e22233",lhs->e22233);
  printf(" %+.8g*e11333",lhs->e11333);
  printf(" %+.8g*e12333",lhs->e12333);
  printf(" %+.8g*e22333",lhs->e22333);
  printf(" %+.8g*e13333",lhs->e13333);
  printf(" %+.8g*e23333",lhs->e23333);
  printf(" %+.8g*e33333",lhs->e33333);
  printf(" %+.8g*e11114",lhs->e11114);
  printf(" %+.8g*e11124",lhs->e11124);
  printf(" %+.8g*e11224",lhs->e11224);
  printf(" %+.8g*e12224",lhs->e12224);
  printf(" %+.8g*e22224",lhs->e22224);
  printf(" %+.8g*e11134",lhs->e11134);
  printf(" %+.8g*e11234",lhs->e11234);
  printf(" %+.8g*e12234",lhs->e12234);
  printf(" %+.8g*e22234",lhs->e22234);
  printf(" %+.8g*e11334",lhs->e11334);
  printf(" %+.8g*e12334",lhs->e12334);
  printf(" %+.8g*e22334",lhs->e22334);
  printf(" %+.8g*e13334",lhs->e13334);
  printf(" %+.8g*e23334",lhs->e23334);
  printf(" %+.8g*e33334",lhs->e33334);
  printf(" %+.8g*e11144",lhs->e11144);
  printf(" %+.8g*e11244",lhs->e11244);
  printf(" %+.8g*e12244",lhs->e12244);
  printf(" %+.8g*e22244",lhs->e22244);
  printf(" %+.8g*e11344",lhs->e11344);
  printf(" %+.8g*e12344",lhs->e12344);
  printf(" %+.8g*e22344",lhs->e22344);
  printf(" %+.8g*e13344",lhs->e13344);
  printf(" %+.8g*e23344",lhs->e23344);
  printf(" %+.8g*e33344",lhs->e33344);
  printf(" %+.8g*e11444",lhs->e11444);
  printf(" %+.8g*e12444",lhs->e12444);
  printf(" %+.8g*e22444",lhs->e22444);
  printf(" %+.8g*e13444",lhs->e13444);
  printf(" %+.8g*e23444",lhs->e23444);
  printf(" %+.8g*e33444",lhs->e33444);
  printf(" %+.8g*e14444",lhs->e14444);
  printf(" %+.8g*e24444",lhs->e24444);
  printf(" %+.8g*e34444",lhs->e34444);
  printf(" %+.8g*e44444",lhs->e44444);
  printf(" %+.8g*e11115",lhs->e11115);
  printf(" %+.8g*e11125",lhs->e11125);
  printf(" %+.8g*e11225",lhs->e11225);
  printf(" %+.8g*e12225",lhs->e12225);
  printf(" %+.8g*e22225",lhs->e22225);
  printf(" %+.8g*e11135",lhs->e11135);
  printf(" %+.8g*e11235",lhs->e11235);
  printf(" %+.8g*e12235",lhs->e12235);
  printf(" %+.8g*e22235",lhs->e22235);
  printf(" %+.8g*e11335",lhs->e11335);
  printf(" %+.8g*e12335",lhs->e12335);
  printf(" %+.8g*e22335",lhs->e22335);
  printf(" %+.8g*e13335",lhs->e13335);
  printf(" %+.8g*e23335",lhs->e23335);
  printf(" %+.8g*e33335",lhs->e33335);
  printf(" %+.8g*e11145",lhs->e11145);
  printf(" %+.8g*e11245",lhs->e11245);
  printf(" %+.8g*e12245",lhs->e12245);
  printf(" %+.8g*e22245",lhs->e22245);
  printf(" %+.8g*e11345",lhs->e11345);
  printf(" %+.8g*e12345",lhs->e12345);
  printf(" %+.8g*e22345",lhs->e22345);
  printf(" %+.8g*e13345",lhs->e13345);
  printf(" %+.8g*e23345",lhs->e23345);
  printf(" %+.8g*e33345",lhs->e33345);
  printf(" %+.8g*e11445",lhs->e11445);
  printf(" %+.8g*e12445",lhs->e12445);
  printf(" %+.8g*e22445",lhs->e22445);
  printf(" %+.8g*e13445",lhs->e13445);
  printf(" %+.8g*e23445",lhs->e23445);
  printf(" %+.8g*e33445",lhs->e33445);
  printf(" %+.8g*e14445",lhs->e14445);
  printf(" %+.8g*e24445",lhs->e24445);
  printf(" %+.8g*e34445",lhs->e34445);
  printf(" %+.8g*e44445",lhs->e44445);
  printf(" %+.8g*e11155",lhs->e11155);
  printf(" %+.8g*e11255",lhs->e11255);
  printf(" %+.8g*e12255",lhs->e12255);
  printf(" %+.8g*e22255",lhs->e22255);
  printf(" %+.8g*e11355",lhs->e11355);
  printf(" %+.8g*e12355",lhs->e12355);
  printf(" %+.8g*e22355",lhs->e22355);
  printf(" %+.8g*e13355",lhs->e13355);
  printf(" %+.8g*e23355",lhs->e23355);
  printf(" %+.8g*e33355",lhs->e33355);
  printf(" %+.8g*e11455",lhs->e11455);
  printf(" %+.8g*e12455",lhs->e12455);
  printf(" %+.8g*e22455",lhs->e22455);
  printf(" %+.8g*e13455",lhs->e13455);
  printf(" %+.8g*e23455",lhs->e23455);
  printf(" %+.8g*e33455",lhs->e33455);
  printf(" %+.8g*e14455",lhs->e14455);
  printf(" %+.8g*e24455",lhs->e24455);
  printf(" %+.8g*e34455",lhs->e34455);
  printf(" %+.8g*e44455",lhs->e44455);
  printf(" %+.8g*e11555",lhs->e11555);
  printf(" %+.8g*e12555",lhs->e12555);
  printf(" %+.8g*e22555",lhs->e22555);
  printf(" %+.8g*e13555",lhs->e13555);
  printf(" %+.8g*e23555",lhs->e23555);
  printf(" %+.8g*e33555",lhs->e33555);
  printf(" %+.8g*e14555",lhs->e14555);
  printf(" %+.8g*e24555",lhs->e24555);
  printf(" %+.8g*e34555",lhs->e34555);
  printf(" %+.8g*e44555",lhs->e44555);
  printf(" %+.8g*e15555",lhs->e15555);
  printf(" %+.8g*e25555",lhs->e25555);
  printf(" %+.8g*e35555",lhs->e35555);
  printf(" %+.8g*e45555",lhs->e45555);
  printf(" %+.8g*e55555",lhs->e55555);
  printf("\n");

}

imdir_t onumm5n5_get_indx(imdir_t idx, ord_t order){

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
    case 5:
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
        case 70:
          return 70;
          break;
        case 71:
          return 71;
          break;
        case 72:
          return 72;
          break;
        case 73:
          return 73;
          break;
        case 74:
          return 74;
          break;
        case 75:
          return 75;
          break;
        case 76:
          return 76;
          break;
        case 77:
          return 77;
          break;
        case 78:
          return 78;
          break;
        case 79:
          return 79;
          break;
        case 80:
          return 80;
          break;
        case 81:
          return 81;
          break;
        case 82:
          return 82;
          break;
        case 83:
          return 83;
          break;
        case 84:
          return 84;
          break;
        case 85:
          return 85;
          break;
        case 86:
          return 86;
          break;
        case 87:
          return 87;
          break;
        case 88:
          return 88;
          break;
        case 89:
          return 89;
          break;
        case 90:
          return 90;
          break;
        case 91:
          return 91;
          break;
        case 92:
          return 92;
          break;
        case 93:
          return 93;
          break;
        case 94:
          return 94;
          break;
        case 95:
          return 95;
          break;
        case 96:
          return 96;
          break;
        case 97:
          return 97;
          break;
        case 98:
          return 98;
          break;
        case 99:
          return 99;
          break;
        case 100:
          return 100;
          break;
        case 101:
          return 101;
          break;
        case 102:
          return 102;
          break;
        case 103:
          return 103;
          break;
        case 104:
          return 104;
          break;
        case 105:
          return 105;
          break;
        case 106:
          return 106;
          break;
        case 107:
          return 107;
          break;
        case 108:
          return 108;
          break;
        case 109:
          return 109;
          break;
        case 110:
          return 110;
          break;
        case 111:
          return 111;
          break;
        case 112:
          return 112;
          break;
        case 113:
          return 113;
          break;
        case 114:
          return 114;
          break;
        case 115:
          return 115;
          break;
        case 116:
          return 116;
          break;
        case 117:
          return 117;
          break;
        case 118:
          return 118;
          break;
        case 119:
          return 119;
          break;
        case 120:
          return 120;
          break;
        case 121:
          return 121;
          break;
        case 122:
          return 122;
          break;
        case 123:
          return 123;
          break;
        case 124:
          return 124;
          break;
        case 125:
          return 125;
          break;
      }
      break;
      default:
          return 0;
  }
  return 0;
}

