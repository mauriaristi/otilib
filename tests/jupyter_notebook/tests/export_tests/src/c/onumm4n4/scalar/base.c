

// Not implemented correctly:
void onumm4n4_set_im_o(onumm4n4_t* num, imdir_t idx, ord_t order, onumm4n4_t* res){
    *res=onumm4n4_init();
}
void onumm4n4_extract_im_to(onumm4n4_t* num, imdir_t idx, ord_t order, onumm4n4_t* res){
    *res=onumm4n4_init();
}
onumm4n4_t onumm4n4_extract_im(imdir_t idx, ord_t order, onumm4n4_t* num){
    onumm4n4_t res = onumm4n4_init();
    return res;
}
onumm4n4_t onumm4n4_extract_deriv(imdir_t idx, ord_t order, onumm4n4_t* num){
    onumm4n4_t res = onumm4n4_init();
    return res;
}
void onumm4n4_extract_deriv_to(imdir_t idx, ord_t order, onumm4n4_t* num, onumm4n4_t* res){
	*res = onumm4n4_init();
}

inline ord_t onumm4n4_get_order(onumm4n4_t* lhs){

	return 4;

}

onumm4n4_t onumm4n4_get_deriv_o( imdir_t idx, ord_t order, onumm4n4_t* num){

    onumm4n4_t res = onumm4n4_init();

    onumm4n4_get_deriv_to( idx, order, num, &res);
    
    return res;

}

void onumm4n4_get_deriv_to( imdir_t idx, ord_t order, onumm4n4_t* num, onumm4n4_t* res){

    coeff_t deriv = onumm4n4_get_deriv(idx,order,num);

    onumm4n4_set_r( deriv, res);

}

void onumm4n4_set_im_r(coeff_t num, imdir_t idx, ord_t order, onumm4n4_t* res){

    onumm4n4_set_item(num, idx,order,res);

}

onumm4n4_t onumm4n4_init(){

  onumm4n4_t res;

  // Init function
  // Real;
  res.r = 0.0;
  // Order 1;
  res.e1 = 0.0;
  res.e2 = 0.0;
  res.e3 = 0.0;
  res.e4 = 0.0;
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

  return res;

}

ndir_t onumm4n4_get_ndir_order(ord_t order, onumm4n4_t* num){

  ndir_t res;

  switch(order){
    case 0:
      res = 1;
      break;
    case 1:
      res = 4;
      break;
    case 2:
      res = 10;
      break;
    case 3:
      res = 20;
      break;
    case 4:
      res = 35;
      break;
  }

  return res;

}

ndir_t onumm4n4_get_ndir_total(onumm4n4_t* num){

  ndir_t res;

  res = 35;

  return res;

}

onumm4n4_t onumm4n4_create_r(  coeff_t lhs){

  onumm4n4_t res;

  // Assign like function 'lhs'
  // Real;
  res.r = lhs;
  // Order 1;
  res.e1 = 0.0;
  res.e2 = 0.0;
  res.e3 = 0.0;
  res.e4 = 0.0;
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

  return res;

}

void onumm4n4_set_r(  coeff_t lhs, onumm4n4_t* res){

  // Assign like function 'lhs'
  // Real;
  res->r = lhs;
  // Order 1;
  res->e1 = 0.0;
  res->e2 = 0.0;
  res->e3 = 0.0;
  res->e4 = 0.0;
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

}

void onumm4n4_set_o(  onumm4n4_t* lhs, onumm4n4_t* res){

  // Assign like function 'lhs'
  // Real;
  res->r = lhs->r;
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

onumm4n4_t onumm4n4_get_order_im(ord_t order, onumm4n4_t* lhs){

  onumm4n4_t res;

  res = onumm4n4_init();
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
      break;
  }

  return res;

}

void onumm4n4_get_order_im_to(ord_t order, onumm4n4_t* lhs, onumm4n4_t* res){


  *res = onumm4n4_init();
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
      break;
  }

}

coeff_t onumm4n4_get_item(imdir_t idx, ord_t order, onumm4n4_t* lhs){

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
      }
      break;
  }
  return res;

}

coeff_t onumm4n4_get_deriv(imdir_t idx, ord_t order, onumm4n4_t* lhs){

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
      }
      break;
  }
  return res;

}

void onumm4n4_set_item(coeff_t val, imdir_t idx, ord_t order, onumm4n4_t* x){

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
      }
      break;
  }
}

onumm4n4_t onumm4n4_copy(  onumm4n4_t* lhs){

  onumm4n4_t res;

  // Assign like function 'lhs'
  // Real;
  res.r = lhs->r;
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

void onumm4n4_copy_to(  onumm4n4_t* lhs, onumm4n4_t* res){

  // Assign like function 'lhs'
  // Real;
  res->r = lhs->r;
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

onumm4n4_t onumm4n4_taylor_integrate(coeff_t* deltas,onumm4n4_t* lhs){

  onumm4n4_t res;

  coeff_t factor;
  // Taylor integration
  // Real;
  res.r = lhs->r;
  // Order 1;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0);
  res.e1 = factor*lhs->e1;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],0);
  res.e2 = factor*lhs->e2;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],0);
  res.e3 = factor*lhs->e3;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],1);
  res.e4 = factor*lhs->e4;
  // Order 2;
  factor = pow(deltas[0],2)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0);
  res.e11 = factor*lhs->e11;
  factor = pow(deltas[0],1)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],0);
  res.e12 = factor*lhs->e12;
  factor = pow(deltas[0],0)*pow(deltas[1],2)*pow(deltas[2],0)*pow(deltas[3],0);
  res.e22 = factor*lhs->e22;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],0);
  res.e13 = factor*lhs->e13;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],1)*pow(deltas[3],0);
  res.e23 = factor*lhs->e23;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],2)*pow(deltas[3],0);
  res.e33 = factor*lhs->e33;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],1);
  res.e14 = factor*lhs->e14;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],1);
  res.e24 = factor*lhs->e24;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],1);
  res.e34 = factor*lhs->e34;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],2);
  res.e44 = factor*lhs->e44;
  // Order 3;
  factor = pow(deltas[0],3)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0);
  res.e111 = factor*lhs->e111;
  factor = pow(deltas[0],2)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],0);
  res.e112 = factor*lhs->e112;
  factor = pow(deltas[0],1)*pow(deltas[1],2)*pow(deltas[2],0)*pow(deltas[3],0);
  res.e122 = factor*lhs->e122;
  factor = pow(deltas[0],0)*pow(deltas[1],3)*pow(deltas[2],0)*pow(deltas[3],0);
  res.e222 = factor*lhs->e222;
  factor = pow(deltas[0],2)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],0);
  res.e113 = factor*lhs->e113;
  factor = pow(deltas[0],1)*pow(deltas[1],1)*pow(deltas[2],1)*pow(deltas[3],0);
  res.e123 = factor*lhs->e123;
  factor = pow(deltas[0],0)*pow(deltas[1],2)*pow(deltas[2],1)*pow(deltas[3],0);
  res.e223 = factor*lhs->e223;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],2)*pow(deltas[3],0);
  res.e133 = factor*lhs->e133;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],2)*pow(deltas[3],0);
  res.e233 = factor*lhs->e233;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],3)*pow(deltas[3],0);
  res.e333 = factor*lhs->e333;
  factor = pow(deltas[0],2)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],1);
  res.e114 = factor*lhs->e114;
  factor = pow(deltas[0],1)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],1);
  res.e124 = factor*lhs->e124;
  factor = pow(deltas[0],0)*pow(deltas[1],2)*pow(deltas[2],0)*pow(deltas[3],1);
  res.e224 = factor*lhs->e224;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],1);
  res.e134 = factor*lhs->e134;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],1)*pow(deltas[3],1);
  res.e234 = factor*lhs->e234;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],2)*pow(deltas[3],1);
  res.e334 = factor*lhs->e334;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],2);
  res.e144 = factor*lhs->e144;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],2);
  res.e244 = factor*lhs->e244;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],2);
  res.e344 = factor*lhs->e344;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],3);
  res.e444 = factor*lhs->e444;
  // Order 4;
  factor = pow(deltas[0],4)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0);
  res.e1111 = factor*lhs->e1111;
  factor = pow(deltas[0],3)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],0);
  res.e1112 = factor*lhs->e1112;
  factor = pow(deltas[0],2)*pow(deltas[1],2)*pow(deltas[2],0)*pow(deltas[3],0);
  res.e1122 = factor*lhs->e1122;
  factor = pow(deltas[0],1)*pow(deltas[1],3)*pow(deltas[2],0)*pow(deltas[3],0);
  res.e1222 = factor*lhs->e1222;
  factor = pow(deltas[0],0)*pow(deltas[1],4)*pow(deltas[2],0)*pow(deltas[3],0);
  res.e2222 = factor*lhs->e2222;
  factor = pow(deltas[0],3)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],0);
  res.e1113 = factor*lhs->e1113;
  factor = pow(deltas[0],2)*pow(deltas[1],1)*pow(deltas[2],1)*pow(deltas[3],0);
  res.e1123 = factor*lhs->e1123;
  factor = pow(deltas[0],1)*pow(deltas[1],2)*pow(deltas[2],1)*pow(deltas[3],0);
  res.e1223 = factor*lhs->e1223;
  factor = pow(deltas[0],0)*pow(deltas[1],3)*pow(deltas[2],1)*pow(deltas[3],0);
  res.e2223 = factor*lhs->e2223;
  factor = pow(deltas[0],2)*pow(deltas[1],0)*pow(deltas[2],2)*pow(deltas[3],0);
  res.e1133 = factor*lhs->e1133;
  factor = pow(deltas[0],1)*pow(deltas[1],1)*pow(deltas[2],2)*pow(deltas[3],0);
  res.e1233 = factor*lhs->e1233;
  factor = pow(deltas[0],0)*pow(deltas[1],2)*pow(deltas[2],2)*pow(deltas[3],0);
  res.e2233 = factor*lhs->e2233;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],3)*pow(deltas[3],0);
  res.e1333 = factor*lhs->e1333;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],3)*pow(deltas[3],0);
  res.e2333 = factor*lhs->e2333;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],4)*pow(deltas[3],0);
  res.e3333 = factor*lhs->e3333;
  factor = pow(deltas[0],3)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],1);
  res.e1114 = factor*lhs->e1114;
  factor = pow(deltas[0],2)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],1);
  res.e1124 = factor*lhs->e1124;
  factor = pow(deltas[0],1)*pow(deltas[1],2)*pow(deltas[2],0)*pow(deltas[3],1);
  res.e1224 = factor*lhs->e1224;
  factor = pow(deltas[0],0)*pow(deltas[1],3)*pow(deltas[2],0)*pow(deltas[3],1);
  res.e2224 = factor*lhs->e2224;
  factor = pow(deltas[0],2)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],1);
  res.e1134 = factor*lhs->e1134;
  factor = pow(deltas[0],1)*pow(deltas[1],1)*pow(deltas[2],1)*pow(deltas[3],1);
  res.e1234 = factor*lhs->e1234;
  factor = pow(deltas[0],0)*pow(deltas[1],2)*pow(deltas[2],1)*pow(deltas[3],1);
  res.e2234 = factor*lhs->e2234;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],2)*pow(deltas[3],1);
  res.e1334 = factor*lhs->e1334;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],2)*pow(deltas[3],1);
  res.e2334 = factor*lhs->e2334;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],3)*pow(deltas[3],1);
  res.e3334 = factor*lhs->e3334;
  factor = pow(deltas[0],2)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],2);
  res.e1144 = factor*lhs->e1144;
  factor = pow(deltas[0],1)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],2);
  res.e1244 = factor*lhs->e1244;
  factor = pow(deltas[0],0)*pow(deltas[1],2)*pow(deltas[2],0)*pow(deltas[3],2);
  res.e2244 = factor*lhs->e2244;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],2);
  res.e1344 = factor*lhs->e1344;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],1)*pow(deltas[3],2);
  res.e2344 = factor*lhs->e2344;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],2)*pow(deltas[3],2);
  res.e3344 = factor*lhs->e3344;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],3);
  res.e1444 = factor*lhs->e1444;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],3);
  res.e2444 = factor*lhs->e2444;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],3);
  res.e3444 = factor*lhs->e3444;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],4);
  res.e4444 = factor*lhs->e4444;

  return res;

}

void onumm4n4_taylor_integrate_to(coeff_t* deltas,onumm4n4_t* lhs, onumm4n4_t* res){

  coeff_t factor;
  // Taylor integration
  // Real;
  res->r = lhs->r;
  // Order 1;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0);
  res->e1 = factor*lhs->e1;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],0);
  res->e2 = factor*lhs->e2;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],0);
  res->e3 = factor*lhs->e3;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],1);
  res->e4 = factor*lhs->e4;
  // Order 2;
  factor = pow(deltas[0],2)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0);
  res->e11 = factor*lhs->e11;
  factor = pow(deltas[0],1)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],0);
  res->e12 = factor*lhs->e12;
  factor = pow(deltas[0],0)*pow(deltas[1],2)*pow(deltas[2],0)*pow(deltas[3],0);
  res->e22 = factor*lhs->e22;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],0);
  res->e13 = factor*lhs->e13;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],1)*pow(deltas[3],0);
  res->e23 = factor*lhs->e23;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],2)*pow(deltas[3],0);
  res->e33 = factor*lhs->e33;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],1);
  res->e14 = factor*lhs->e14;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],1);
  res->e24 = factor*lhs->e24;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],1);
  res->e34 = factor*lhs->e34;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],2);
  res->e44 = factor*lhs->e44;
  // Order 3;
  factor = pow(deltas[0],3)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0);
  res->e111 = factor*lhs->e111;
  factor = pow(deltas[0],2)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],0);
  res->e112 = factor*lhs->e112;
  factor = pow(deltas[0],1)*pow(deltas[1],2)*pow(deltas[2],0)*pow(deltas[3],0);
  res->e122 = factor*lhs->e122;
  factor = pow(deltas[0],0)*pow(deltas[1],3)*pow(deltas[2],0)*pow(deltas[3],0);
  res->e222 = factor*lhs->e222;
  factor = pow(deltas[0],2)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],0);
  res->e113 = factor*lhs->e113;
  factor = pow(deltas[0],1)*pow(deltas[1],1)*pow(deltas[2],1)*pow(deltas[3],0);
  res->e123 = factor*lhs->e123;
  factor = pow(deltas[0],0)*pow(deltas[1],2)*pow(deltas[2],1)*pow(deltas[3],0);
  res->e223 = factor*lhs->e223;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],2)*pow(deltas[3],0);
  res->e133 = factor*lhs->e133;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],2)*pow(deltas[3],0);
  res->e233 = factor*lhs->e233;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],3)*pow(deltas[3],0);
  res->e333 = factor*lhs->e333;
  factor = pow(deltas[0],2)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],1);
  res->e114 = factor*lhs->e114;
  factor = pow(deltas[0],1)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],1);
  res->e124 = factor*lhs->e124;
  factor = pow(deltas[0],0)*pow(deltas[1],2)*pow(deltas[2],0)*pow(deltas[3],1);
  res->e224 = factor*lhs->e224;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],1);
  res->e134 = factor*lhs->e134;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],1)*pow(deltas[3],1);
  res->e234 = factor*lhs->e234;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],2)*pow(deltas[3],1);
  res->e334 = factor*lhs->e334;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],2);
  res->e144 = factor*lhs->e144;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],2);
  res->e244 = factor*lhs->e244;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],2);
  res->e344 = factor*lhs->e344;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],3);
  res->e444 = factor*lhs->e444;
  // Order 4;
  factor = pow(deltas[0],4)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0);
  res->e1111 = factor*lhs->e1111;
  factor = pow(deltas[0],3)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],0);
  res->e1112 = factor*lhs->e1112;
  factor = pow(deltas[0],2)*pow(deltas[1],2)*pow(deltas[2],0)*pow(deltas[3],0);
  res->e1122 = factor*lhs->e1122;
  factor = pow(deltas[0],1)*pow(deltas[1],3)*pow(deltas[2],0)*pow(deltas[3],0);
  res->e1222 = factor*lhs->e1222;
  factor = pow(deltas[0],0)*pow(deltas[1],4)*pow(deltas[2],0)*pow(deltas[3],0);
  res->e2222 = factor*lhs->e2222;
  factor = pow(deltas[0],3)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],0);
  res->e1113 = factor*lhs->e1113;
  factor = pow(deltas[0],2)*pow(deltas[1],1)*pow(deltas[2],1)*pow(deltas[3],0);
  res->e1123 = factor*lhs->e1123;
  factor = pow(deltas[0],1)*pow(deltas[1],2)*pow(deltas[2],1)*pow(deltas[3],0);
  res->e1223 = factor*lhs->e1223;
  factor = pow(deltas[0],0)*pow(deltas[1],3)*pow(deltas[2],1)*pow(deltas[3],0);
  res->e2223 = factor*lhs->e2223;
  factor = pow(deltas[0],2)*pow(deltas[1],0)*pow(deltas[2],2)*pow(deltas[3],0);
  res->e1133 = factor*lhs->e1133;
  factor = pow(deltas[0],1)*pow(deltas[1],1)*pow(deltas[2],2)*pow(deltas[3],0);
  res->e1233 = factor*lhs->e1233;
  factor = pow(deltas[0],0)*pow(deltas[1],2)*pow(deltas[2],2)*pow(deltas[3],0);
  res->e2233 = factor*lhs->e2233;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],3)*pow(deltas[3],0);
  res->e1333 = factor*lhs->e1333;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],3)*pow(deltas[3],0);
  res->e2333 = factor*lhs->e2333;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],4)*pow(deltas[3],0);
  res->e3333 = factor*lhs->e3333;
  factor = pow(deltas[0],3)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],1);
  res->e1114 = factor*lhs->e1114;
  factor = pow(deltas[0],2)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],1);
  res->e1124 = factor*lhs->e1124;
  factor = pow(deltas[0],1)*pow(deltas[1],2)*pow(deltas[2],0)*pow(deltas[3],1);
  res->e1224 = factor*lhs->e1224;
  factor = pow(deltas[0],0)*pow(deltas[1],3)*pow(deltas[2],0)*pow(deltas[3],1);
  res->e2224 = factor*lhs->e2224;
  factor = pow(deltas[0],2)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],1);
  res->e1134 = factor*lhs->e1134;
  factor = pow(deltas[0],1)*pow(deltas[1],1)*pow(deltas[2],1)*pow(deltas[3],1);
  res->e1234 = factor*lhs->e1234;
  factor = pow(deltas[0],0)*pow(deltas[1],2)*pow(deltas[2],1)*pow(deltas[3],1);
  res->e2234 = factor*lhs->e2234;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],2)*pow(deltas[3],1);
  res->e1334 = factor*lhs->e1334;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],2)*pow(deltas[3],1);
  res->e2334 = factor*lhs->e2334;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],3)*pow(deltas[3],1);
  res->e3334 = factor*lhs->e3334;
  factor = pow(deltas[0],2)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],2);
  res->e1144 = factor*lhs->e1144;
  factor = pow(deltas[0],1)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],2);
  res->e1244 = factor*lhs->e1244;
  factor = pow(deltas[0],0)*pow(deltas[1],2)*pow(deltas[2],0)*pow(deltas[3],2);
  res->e2244 = factor*lhs->e2244;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],2);
  res->e1344 = factor*lhs->e1344;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],1)*pow(deltas[3],2);
  res->e2344 = factor*lhs->e2344;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],2)*pow(deltas[3],2);
  res->e3344 = factor*lhs->e3344;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],3);
  res->e1444 = factor*lhs->e1444;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],3);
  res->e2444 = factor*lhs->e2444;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],3);
  res->e3444 = factor*lhs->e3444;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],4);
  res->e4444 = factor*lhs->e4444;

}

onumm4n4_t onumm4n4_truncate_im(imdir_t idx, ord_t order, onumm4n4_t* lhs){

  onumm4n4_t res;

  // Copy number.
  res = (*lhs);
  // Truncate all other values when necessary.
  // Real;
  switch (order){
    case 0:
      res = onumm4n4_init();
      break;
    case 1:
      switch (idx){
        case 0: //  e1
          res.e1 = 0.0;
          res.e11 = 0.0;
          res.e12 = 0.0;
          res.e13 = 0.0;
          res.e14 = 0.0;
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
          break;
        case 1: //  e2
          res.e2 = 0.0;
          res.e12 = 0.0;
          res.e22 = 0.0;
          res.e23 = 0.0;
          res.e24 = 0.0;
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
          break;
        case 2: //  e3
          res.e3 = 0.0;
          res.e13 = 0.0;
          res.e23 = 0.0;
          res.e33 = 0.0;
          res.e34 = 0.0;
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
          break;
        case 3: //  e4
          res.e4 = 0.0;
          res.e14 = 0.0;
          res.e24 = 0.0;
          res.e34 = 0.0;
          res.e44 = 0.0;
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
          break;
        case 1: //  e12
          res.e12 = 0.0;
          res.e112 = 0.0;
          res.e122 = 0.0;
          res.e123 = 0.0;
          res.e124 = 0.0;
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
          break;
        case 2: //  e22
          res.e22 = 0.0;
          res.e122 = 0.0;
          res.e222 = 0.0;
          res.e223 = 0.0;
          res.e224 = 0.0;
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
          break;
        case 3: //  e13
          res.e13 = 0.0;
          res.e113 = 0.0;
          res.e123 = 0.0;
          res.e133 = 0.0;
          res.e134 = 0.0;
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
          break;
        case 4: //  e23
          res.e23 = 0.0;
          res.e123 = 0.0;
          res.e223 = 0.0;
          res.e233 = 0.0;
          res.e234 = 0.0;
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
          break;
        case 5: //  e33
          res.e33 = 0.0;
          res.e133 = 0.0;
          res.e233 = 0.0;
          res.e333 = 0.0;
          res.e334 = 0.0;
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
          break;
        case 6: //  e14
          res.e14 = 0.0;
          res.e114 = 0.0;
          res.e124 = 0.0;
          res.e134 = 0.0;
          res.e144 = 0.0;
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
          break;
        case 7: //  e24
          res.e24 = 0.0;
          res.e124 = 0.0;
          res.e224 = 0.0;
          res.e234 = 0.0;
          res.e244 = 0.0;
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
          break;
        case 8: //  e34
          res.e34 = 0.0;
          res.e134 = 0.0;
          res.e234 = 0.0;
          res.e334 = 0.0;
          res.e344 = 0.0;
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
          break;
        case 9: //  e44
          res.e44 = 0.0;
          res.e144 = 0.0;
          res.e244 = 0.0;
          res.e344 = 0.0;
          res.e444 = 0.0;
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
          break;
        case 1: //  e112
          res.e112 = 0.0;
          res.e1112 = 0.0;
          res.e1122 = 0.0;
          res.e1123 = 0.0;
          res.e1124 = 0.0;
          break;
        case 2: //  e122
          res.e122 = 0.0;
          res.e1122 = 0.0;
          res.e1222 = 0.0;
          res.e1223 = 0.0;
          res.e1224 = 0.0;
          break;
        case 3: //  e222
          res.e222 = 0.0;
          res.e1222 = 0.0;
          res.e2222 = 0.0;
          res.e2223 = 0.0;
          res.e2224 = 0.0;
          break;
        case 4: //  e113
          res.e113 = 0.0;
          res.e1113 = 0.0;
          res.e1123 = 0.0;
          res.e1133 = 0.0;
          res.e1134 = 0.0;
          break;
        case 5: //  e123
          res.e123 = 0.0;
          res.e1123 = 0.0;
          res.e1223 = 0.0;
          res.e1233 = 0.0;
          res.e1234 = 0.0;
          break;
        case 6: //  e223
          res.e223 = 0.0;
          res.e1223 = 0.0;
          res.e2223 = 0.0;
          res.e2233 = 0.0;
          res.e2234 = 0.0;
          break;
        case 7: //  e133
          res.e133 = 0.0;
          res.e1133 = 0.0;
          res.e1233 = 0.0;
          res.e1333 = 0.0;
          res.e1334 = 0.0;
          break;
        case 8: //  e233
          res.e233 = 0.0;
          res.e1233 = 0.0;
          res.e2233 = 0.0;
          res.e2333 = 0.0;
          res.e2334 = 0.0;
          break;
        case 9: //  e333
          res.e333 = 0.0;
          res.e1333 = 0.0;
          res.e2333 = 0.0;
          res.e3333 = 0.0;
          res.e3334 = 0.0;
          break;
        case 10: //  e114
          res.e114 = 0.0;
          res.e1114 = 0.0;
          res.e1124 = 0.0;
          res.e1134 = 0.0;
          res.e1144 = 0.0;
          break;
        case 11: //  e124
          res.e124 = 0.0;
          res.e1124 = 0.0;
          res.e1224 = 0.0;
          res.e1234 = 0.0;
          res.e1244 = 0.0;
          break;
        case 12: //  e224
          res.e224 = 0.0;
          res.e1224 = 0.0;
          res.e2224 = 0.0;
          res.e2234 = 0.0;
          res.e2244 = 0.0;
          break;
        case 13: //  e134
          res.e134 = 0.0;
          res.e1134 = 0.0;
          res.e1234 = 0.0;
          res.e1334 = 0.0;
          res.e1344 = 0.0;
          break;
        case 14: //  e234
          res.e234 = 0.0;
          res.e1234 = 0.0;
          res.e2234 = 0.0;
          res.e2334 = 0.0;
          res.e2344 = 0.0;
          break;
        case 15: //  e334
          res.e334 = 0.0;
          res.e1334 = 0.0;
          res.e2334 = 0.0;
          res.e3334 = 0.0;
          res.e3344 = 0.0;
          break;
        case 16: //  e144
          res.e144 = 0.0;
          res.e1144 = 0.0;
          res.e1244 = 0.0;
          res.e1344 = 0.0;
          res.e1444 = 0.0;
          break;
        case 17: //  e244
          res.e244 = 0.0;
          res.e1244 = 0.0;
          res.e2244 = 0.0;
          res.e2344 = 0.0;
          res.e2444 = 0.0;
          break;
        case 18: //  e344
          res.e344 = 0.0;
          res.e1344 = 0.0;
          res.e2344 = 0.0;
          res.e3344 = 0.0;
          res.e3444 = 0.0;
          break;
        case 19: //  e444
          res.e444 = 0.0;
          res.e1444 = 0.0;
          res.e2444 = 0.0;
          res.e3444 = 0.0;
          res.e4444 = 0.0;
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
      }
      break;
  }
  return res;

}

void onumm4n4_truncate_im_to(imdir_t idx, ord_t order, onumm4n4_t* lhs, onumm4n4_t* res){

  // Copy number.
  *res = (*lhs);
  // Truncate all other values when necessary.
  // Real;
  switch (order){
    case 0:
      *res = onumm4n4_init();
      break;
    case 1:
      switch (idx){
        case 0: //  e1
          res->e1 = 0.0;
          res->e11 = 0.0;
          res->e12 = 0.0;
          res->e13 = 0.0;
          res->e14 = 0.0;
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
          break;
        case 1: //  e2
          res->e2 = 0.0;
          res->e12 = 0.0;
          res->e22 = 0.0;
          res->e23 = 0.0;
          res->e24 = 0.0;
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
          break;
        case 2: //  e3
          res->e3 = 0.0;
          res->e13 = 0.0;
          res->e23 = 0.0;
          res->e33 = 0.0;
          res->e34 = 0.0;
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
          break;
        case 3: //  e4
          res->e4 = 0.0;
          res->e14 = 0.0;
          res->e24 = 0.0;
          res->e34 = 0.0;
          res->e44 = 0.0;
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
          break;
        case 1: //  e12
          res->e12 = 0.0;
          res->e112 = 0.0;
          res->e122 = 0.0;
          res->e123 = 0.0;
          res->e124 = 0.0;
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
          break;
        case 2: //  e22
          res->e22 = 0.0;
          res->e122 = 0.0;
          res->e222 = 0.0;
          res->e223 = 0.0;
          res->e224 = 0.0;
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
          break;
        case 3: //  e13
          res->e13 = 0.0;
          res->e113 = 0.0;
          res->e123 = 0.0;
          res->e133 = 0.0;
          res->e134 = 0.0;
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
          break;
        case 4: //  e23
          res->e23 = 0.0;
          res->e123 = 0.0;
          res->e223 = 0.0;
          res->e233 = 0.0;
          res->e234 = 0.0;
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
          break;
        case 5: //  e33
          res->e33 = 0.0;
          res->e133 = 0.0;
          res->e233 = 0.0;
          res->e333 = 0.0;
          res->e334 = 0.0;
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
          break;
        case 6: //  e14
          res->e14 = 0.0;
          res->e114 = 0.0;
          res->e124 = 0.0;
          res->e134 = 0.0;
          res->e144 = 0.0;
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
          break;
        case 7: //  e24
          res->e24 = 0.0;
          res->e124 = 0.0;
          res->e224 = 0.0;
          res->e234 = 0.0;
          res->e244 = 0.0;
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
          break;
        case 8: //  e34
          res->e34 = 0.0;
          res->e134 = 0.0;
          res->e234 = 0.0;
          res->e334 = 0.0;
          res->e344 = 0.0;
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
          break;
        case 9: //  e44
          res->e44 = 0.0;
          res->e144 = 0.0;
          res->e244 = 0.0;
          res->e344 = 0.0;
          res->e444 = 0.0;
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
          break;
        case 1: //  e112
          res->e112 = 0.0;
          res->e1112 = 0.0;
          res->e1122 = 0.0;
          res->e1123 = 0.0;
          res->e1124 = 0.0;
          break;
        case 2: //  e122
          res->e122 = 0.0;
          res->e1122 = 0.0;
          res->e1222 = 0.0;
          res->e1223 = 0.0;
          res->e1224 = 0.0;
          break;
        case 3: //  e222
          res->e222 = 0.0;
          res->e1222 = 0.0;
          res->e2222 = 0.0;
          res->e2223 = 0.0;
          res->e2224 = 0.0;
          break;
        case 4: //  e113
          res->e113 = 0.0;
          res->e1113 = 0.0;
          res->e1123 = 0.0;
          res->e1133 = 0.0;
          res->e1134 = 0.0;
          break;
        case 5: //  e123
          res->e123 = 0.0;
          res->e1123 = 0.0;
          res->e1223 = 0.0;
          res->e1233 = 0.0;
          res->e1234 = 0.0;
          break;
        case 6: //  e223
          res->e223 = 0.0;
          res->e1223 = 0.0;
          res->e2223 = 0.0;
          res->e2233 = 0.0;
          res->e2234 = 0.0;
          break;
        case 7: //  e133
          res->e133 = 0.0;
          res->e1133 = 0.0;
          res->e1233 = 0.0;
          res->e1333 = 0.0;
          res->e1334 = 0.0;
          break;
        case 8: //  e233
          res->e233 = 0.0;
          res->e1233 = 0.0;
          res->e2233 = 0.0;
          res->e2333 = 0.0;
          res->e2334 = 0.0;
          break;
        case 9: //  e333
          res->e333 = 0.0;
          res->e1333 = 0.0;
          res->e2333 = 0.0;
          res->e3333 = 0.0;
          res->e3334 = 0.0;
          break;
        case 10: //  e114
          res->e114 = 0.0;
          res->e1114 = 0.0;
          res->e1124 = 0.0;
          res->e1134 = 0.0;
          res->e1144 = 0.0;
          break;
        case 11: //  e124
          res->e124 = 0.0;
          res->e1124 = 0.0;
          res->e1224 = 0.0;
          res->e1234 = 0.0;
          res->e1244 = 0.0;
          break;
        case 12: //  e224
          res->e224 = 0.0;
          res->e1224 = 0.0;
          res->e2224 = 0.0;
          res->e2234 = 0.0;
          res->e2244 = 0.0;
          break;
        case 13: //  e134
          res->e134 = 0.0;
          res->e1134 = 0.0;
          res->e1234 = 0.0;
          res->e1334 = 0.0;
          res->e1344 = 0.0;
          break;
        case 14: //  e234
          res->e234 = 0.0;
          res->e1234 = 0.0;
          res->e2234 = 0.0;
          res->e2334 = 0.0;
          res->e2344 = 0.0;
          break;
        case 15: //  e334
          res->e334 = 0.0;
          res->e1334 = 0.0;
          res->e2334 = 0.0;
          res->e3334 = 0.0;
          res->e3344 = 0.0;
          break;
        case 16: //  e144
          res->e144 = 0.0;
          res->e1144 = 0.0;
          res->e1244 = 0.0;
          res->e1344 = 0.0;
          res->e1444 = 0.0;
          break;
        case 17: //  e244
          res->e244 = 0.0;
          res->e1244 = 0.0;
          res->e2244 = 0.0;
          res->e2344 = 0.0;
          res->e2444 = 0.0;
          break;
        case 18: //  e344
          res->e344 = 0.0;
          res->e1344 = 0.0;
          res->e2344 = 0.0;
          res->e3344 = 0.0;
          res->e3444 = 0.0;
          break;
        case 19: //  e444
          res->e444 = 0.0;
          res->e1444 = 0.0;
          res->e2444 = 0.0;
          res->e3444 = 0.0;
          res->e4444 = 0.0;
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
      }
      break;
  }
}

void onumm4n4_print(  onumm4n4_t* lhs){

  // Print function.
  //  Real;
  printf("%.8g",lhs->r);
  //  Order 1;
  printf(" %+.8g*e1",lhs->e1);
  printf(" %+.8g*e2",lhs->e2);
  printf(" %+.8g*e3",lhs->e3);
  printf(" %+.8g*e4",lhs->e4);
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
  printf("\n");

}

