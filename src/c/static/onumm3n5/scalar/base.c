

// Not implemented correctly:
void onumm3n5_set_im_o(onumm3n5_t* num, imdir_t idx, ord_t order, onumm3n5_t* res){
    onumm3n5_set_item(num->r,idx,order,res);
}
void onumm3n5_set_deriv_r(coeff_t num, imdir_t idx, ord_t order, onumm3n5_t* res){
    *res=onumm3n5_init();
}
void onumm3n5_set_deriv_o(onumm3n5_t* num, imdir_t idx, ord_t order, onumm3n5_t* res){
    *res=onumm3n5_init();
}
void onumm3n5_extract_im_to( imdir_t idx, ord_t order, onumm3n5_t* num, onumm3n5_t* res){
    *res=onumm3n5_init();
}
onumm3n5_t onumm3n5_extract_im(imdir_t idx, ord_t order, onumm3n5_t* num){
    onumm3n5_t res = onumm3n5_init();
    return res;
}
onumm3n5_t onumm3n5_extract_deriv(imdir_t idx, ord_t order, onumm3n5_t* num){
    onumm3n5_t res = onumm3n5_init();
    return res;
}
void onumm3n5_extract_deriv_to(imdir_t idx, ord_t order, onumm3n5_t* num, onumm3n5_t* res){
	*res = onumm3n5_init();
}
void onumm3n5_get_im_to_o(imdir_t idx, ord_t order, onumm3n5_t* num, onumm3n5_t* res){
    coeff_t rres = onumm3n5_get_item(idx, order, num);
    onumm3n5_set_r(rres,res);
}
onumm3n5_t onumm3n5_get_im_o(imdir_t idx, ord_t order, onumm3n5_t* num){
    coeff_t rres = onumm3n5_get_item(idx, order, num);
    onumm3n5_t res;
    onumm3n5_set_r(rres,&res);
    return res;
}
void onumm3n5_get_im_to_r(imdir_t idx, ord_t order, onumm3n5_t* num, coeff_t* res){
    *res = onumm3n5_get_item(idx, order, num);
}

inline ord_t onumm3n5_get_order(onumm3n5_t* lhs){

	return 5;

}

onumm3n5_t onumm3n5_get_deriv_o( imdir_t idx, ord_t order, onumm3n5_t* num){

    onumm3n5_t res = onumm3n5_init();

    onumm3n5_get_deriv_to( idx, order, num, &res);
    
    return res;

}

void onumm3n5_get_deriv_to( imdir_t idx, ord_t order, onumm3n5_t* num, onumm3n5_t* res){

    coeff_t deriv = onumm3n5_get_deriv(idx,order,num);

    onumm3n5_set_r( deriv, res);

}

void onumm3n5_set_im_r(coeff_t num, imdir_t idx, ord_t order, onumm3n5_t* res){

    onumm3n5_set_item(num, idx,order,res);

}

onumm3n5_t onumm3n5_init(void){

  onumm3n5_t res;

  // Init function
  // Real;
  res.r = 0.0;
  // Order 1;
  res.e1 = 0.0;
  res.e2 = 0.0;
  res.e3 = 0.0;
  // Order 2;
  res.e11 = 0.0;
  res.e12 = 0.0;
  res.e22 = 0.0;
  res.e13 = 0.0;
  res.e23 = 0.0;
  res.e33 = 0.0;
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

  return res;

}

ndir_t onumm3n5_get_ndir_order(ord_t order, onumm3n5_t* num){

  ndir_t res;

  switch(order){
    case 0:
      res = 1;
      break;
    case 1:
      res = 3;
      break;
    case 2:
      res = 6;
      break;
    case 3:
      res = 10;
      break;
    case 4:
      res = 15;
      break;
    case 5:
      res = 21;
      break;
  }

  return res;

}

ndir_t onumm3n5_get_ndir_total(onumm3n5_t* num){

  ndir_t res;

  res = 35;

  return res;

}

coeff_t* onumm3n5_get_order_address(ord_t order, onumm3n5_t* num){

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

onumm3n5_t onumm3n5_create_r(  coeff_t lhs){

  onumm3n5_t res;

  // Assign like function 'lhs'
  // Real;
  res.r = lhs;
  // Order 1;
  res.e1 = 0.0;
  res.e2 = 0.0;
  res.e3 = 0.0;
  // Order 2;
  res.e11 = 0.0;
  res.e12 = 0.0;
  res.e22 = 0.0;
  res.e13 = 0.0;
  res.e23 = 0.0;
  res.e33 = 0.0;
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

  return res;

}

void onumm3n5_set_r(  coeff_t lhs, onumm3n5_t* res){

  // Assign like function 'lhs'
  // Real;
  res->r = lhs;
  // Order 1;
  res->e1 = 0.0;
  res->e2 = 0.0;
  res->e3 = 0.0;
  // Order 2;
  res->e11 = 0.0;
  res->e12 = 0.0;
  res->e22 = 0.0;
  res->e13 = 0.0;
  res->e23 = 0.0;
  res->e33 = 0.0;
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

}

void onumm3n5_set_o(  onumm3n5_t* lhs, onumm3n5_t* res){

  // Assign like function 'lhs'
  // Real;
  res->r = lhs->r;
  // Order 1;
  res->e1 = lhs->e1;
  res->e2 = lhs->e2;
  res->e3 = lhs->e3;
  // Order 2;
  res->e11 = lhs->e11;
  res->e12 = lhs->e12;
  res->e22 = lhs->e22;
  res->e13 = lhs->e13;
  res->e23 = lhs->e23;
  res->e33 = lhs->e33;
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

}

onumm3n5_t onumm3n5_get_order_im(ord_t order, onumm3n5_t* lhs){

  onumm3n5_t res;

  res = onumm3n5_init();
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
      break;
    case 2:
      // Order 2;
      res.e11 = lhs->e11;
      res.e12 = lhs->e12;
      res.e22 = lhs->e22;
      res.e13 = lhs->e13;
      res.e23 = lhs->e23;
      res.e33 = lhs->e33;
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
      break;
  }

  return res;

}

void onumm3n5_get_order_im_to(ord_t order, onumm3n5_t* lhs, onumm3n5_t* res){


  *res = onumm3n5_init();
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
      break;
    case 2:
      // Order 2;
      res->e11 = lhs->e11;
      res->e12 = lhs->e12;
      res->e22 = lhs->e22;
      res->e13 = lhs->e13;
      res->e23 = lhs->e23;
      res->e33 = lhs->e33;
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
      break;
  }

}

coeff_t onumm3n5_get_item(imdir_t idx, ord_t order, onumm3n5_t* lhs){

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
      }
      break;
  }
  return res;

}

coeff_t onumm3n5_get_deriv(imdir_t idx, ord_t order, onumm3n5_t* lhs){

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
      }
      break;
  }
  return res;

}

void onumm3n5_set_item(coeff_t val, imdir_t idx, ord_t order, onumm3n5_t* x){

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
      }
      break;
  }
}

onumm3n5_t onumm3n5_copy(  onumm3n5_t* lhs){

  onumm3n5_t res;

  // Assign like function 'lhs'
  // Real;
  res.r = lhs->r;
  // Order 1;
  res.e1 = lhs->e1;
  res.e2 = lhs->e2;
  res.e3 = lhs->e3;
  // Order 2;
  res.e11 = lhs->e11;
  res.e12 = lhs->e12;
  res.e22 = lhs->e22;
  res.e13 = lhs->e13;
  res.e23 = lhs->e23;
  res.e33 = lhs->e33;
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

  return res;

}

void onumm3n5_copy_to(  onumm3n5_t* lhs, onumm3n5_t* res){

  // Assign like function 'lhs'
  // Real;
  res->r = lhs->r;
  // Order 1;
  res->e1 = lhs->e1;
  res->e2 = lhs->e2;
  res->e3 = lhs->e3;
  // Order 2;
  res->e11 = lhs->e11;
  res->e12 = lhs->e12;
  res->e22 = lhs->e22;
  res->e13 = lhs->e13;
  res->e23 = lhs->e23;
  res->e33 = lhs->e33;
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

}

onumm3n5_t onumm3n5_taylor_integrate(coeff_t* deltas,onumm3n5_t* lhs){

  onumm3n5_t res;

  res = onumm3n5_init();
  coeff_t factor;
  // Taylor integration
  // Real;
  res.r = lhs->r;
  // Order 1;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],0);
  res.r += factor*lhs->e1;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],0);
  res.r += factor*lhs->e2;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],1);
  res.r += factor*lhs->e3;
  // Order 2;
  factor = pow(deltas[0],2)*pow(deltas[1],0)*pow(deltas[2],0);
  res.r += factor*lhs->e11;
  factor = pow(deltas[0],1)*pow(deltas[1],1)*pow(deltas[2],0);
  res.r += factor*lhs->e12;
  factor = pow(deltas[0],0)*pow(deltas[1],2)*pow(deltas[2],0);
  res.r += factor*lhs->e22;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],1);
  res.r += factor*lhs->e13;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],1);
  res.r += factor*lhs->e23;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],2);
  res.r += factor*lhs->e33;
  // Order 3;
  factor = pow(deltas[0],3)*pow(deltas[1],0)*pow(deltas[2],0);
  res.r += factor*lhs->e111;
  factor = pow(deltas[0],2)*pow(deltas[1],1)*pow(deltas[2],0);
  res.r += factor*lhs->e112;
  factor = pow(deltas[0],1)*pow(deltas[1],2)*pow(deltas[2],0);
  res.r += factor*lhs->e122;
  factor = pow(deltas[0],0)*pow(deltas[1],3)*pow(deltas[2],0);
  res.r += factor*lhs->e222;
  factor = pow(deltas[0],2)*pow(deltas[1],0)*pow(deltas[2],1);
  res.r += factor*lhs->e113;
  factor = pow(deltas[0],1)*pow(deltas[1],1)*pow(deltas[2],1);
  res.r += factor*lhs->e123;
  factor = pow(deltas[0],0)*pow(deltas[1],2)*pow(deltas[2],1);
  res.r += factor*lhs->e223;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],2);
  res.r += factor*lhs->e133;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],2);
  res.r += factor*lhs->e233;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],3);
  res.r += factor*lhs->e333;
  // Order 4;
  factor = pow(deltas[0],4)*pow(deltas[1],0)*pow(deltas[2],0);
  res.r += factor*lhs->e1111;
  factor = pow(deltas[0],3)*pow(deltas[1],1)*pow(deltas[2],0);
  res.r += factor*lhs->e1112;
  factor = pow(deltas[0],2)*pow(deltas[1],2)*pow(deltas[2],0);
  res.r += factor*lhs->e1122;
  factor = pow(deltas[0],1)*pow(deltas[1],3)*pow(deltas[2],0);
  res.r += factor*lhs->e1222;
  factor = pow(deltas[0],0)*pow(deltas[1],4)*pow(deltas[2],0);
  res.r += factor*lhs->e2222;
  factor = pow(deltas[0],3)*pow(deltas[1],0)*pow(deltas[2],1);
  res.r += factor*lhs->e1113;
  factor = pow(deltas[0],2)*pow(deltas[1],1)*pow(deltas[2],1);
  res.r += factor*lhs->e1123;
  factor = pow(deltas[0],1)*pow(deltas[1],2)*pow(deltas[2],1);
  res.r += factor*lhs->e1223;
  factor = pow(deltas[0],0)*pow(deltas[1],3)*pow(deltas[2],1);
  res.r += factor*lhs->e2223;
  factor = pow(deltas[0],2)*pow(deltas[1],0)*pow(deltas[2],2);
  res.r += factor*lhs->e1133;
  factor = pow(deltas[0],1)*pow(deltas[1],1)*pow(deltas[2],2);
  res.r += factor*lhs->e1233;
  factor = pow(deltas[0],0)*pow(deltas[1],2)*pow(deltas[2],2);
  res.r += factor*lhs->e2233;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],3);
  res.r += factor*lhs->e1333;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],3);
  res.r += factor*lhs->e2333;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],4);
  res.r += factor*lhs->e3333;
  // Order 5;
  factor = pow(deltas[0],5)*pow(deltas[1],0)*pow(deltas[2],0);
  res.r += factor*lhs->e11111;
  factor = pow(deltas[0],4)*pow(deltas[1],1)*pow(deltas[2],0);
  res.r += factor*lhs->e11112;
  factor = pow(deltas[0],3)*pow(deltas[1],2)*pow(deltas[2],0);
  res.r += factor*lhs->e11122;
  factor = pow(deltas[0],2)*pow(deltas[1],3)*pow(deltas[2],0);
  res.r += factor*lhs->e11222;
  factor = pow(deltas[0],1)*pow(deltas[1],4)*pow(deltas[2],0);
  res.r += factor*lhs->e12222;
  factor = pow(deltas[0],0)*pow(deltas[1],5)*pow(deltas[2],0);
  res.r += factor*lhs->e22222;
  factor = pow(deltas[0],4)*pow(deltas[1],0)*pow(deltas[2],1);
  res.r += factor*lhs->e11113;
  factor = pow(deltas[0],3)*pow(deltas[1],1)*pow(deltas[2],1);
  res.r += factor*lhs->e11123;
  factor = pow(deltas[0],2)*pow(deltas[1],2)*pow(deltas[2],1);
  res.r += factor*lhs->e11223;
  factor = pow(deltas[0],1)*pow(deltas[1],3)*pow(deltas[2],1);
  res.r += factor*lhs->e12223;
  factor = pow(deltas[0],0)*pow(deltas[1],4)*pow(deltas[2],1);
  res.r += factor*lhs->e22223;
  factor = pow(deltas[0],3)*pow(deltas[1],0)*pow(deltas[2],2);
  res.r += factor*lhs->e11133;
  factor = pow(deltas[0],2)*pow(deltas[1],1)*pow(deltas[2],2);
  res.r += factor*lhs->e11233;
  factor = pow(deltas[0],1)*pow(deltas[1],2)*pow(deltas[2],2);
  res.r += factor*lhs->e12233;
  factor = pow(deltas[0],0)*pow(deltas[1],3)*pow(deltas[2],2);
  res.r += factor*lhs->e22233;
  factor = pow(deltas[0],2)*pow(deltas[1],0)*pow(deltas[2],3);
  res.r += factor*lhs->e11333;
  factor = pow(deltas[0],1)*pow(deltas[1],1)*pow(deltas[2],3);
  res.r += factor*lhs->e12333;
  factor = pow(deltas[0],0)*pow(deltas[1],2)*pow(deltas[2],3);
  res.r += factor*lhs->e22333;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],4);
  res.r += factor*lhs->e13333;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],4);
  res.r += factor*lhs->e23333;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],5);
  res.r += factor*lhs->e33333;

  return res;

}

void onumm3n5_taylor_integrate_to(coeff_t* deltas,onumm3n5_t* lhs, onumm3n5_t* res){

  *res = onumm3n5_init();
  coeff_t factor;
  // Taylor integration
  // Real;
  res->r = lhs->r;
  // Order 1;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],0);
  res->r += factor*lhs->e1;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],0);
  res->r += factor*lhs->e2;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],1);
  res->r += factor*lhs->e3;
  // Order 2;
  factor = pow(deltas[0],2)*pow(deltas[1],0)*pow(deltas[2],0);
  res->r += factor*lhs->e11;
  factor = pow(deltas[0],1)*pow(deltas[1],1)*pow(deltas[2],0);
  res->r += factor*lhs->e12;
  factor = pow(deltas[0],0)*pow(deltas[1],2)*pow(deltas[2],0);
  res->r += factor*lhs->e22;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],1);
  res->r += factor*lhs->e13;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],1);
  res->r += factor*lhs->e23;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],2);
  res->r += factor*lhs->e33;
  // Order 3;
  factor = pow(deltas[0],3)*pow(deltas[1],0)*pow(deltas[2],0);
  res->r += factor*lhs->e111;
  factor = pow(deltas[0],2)*pow(deltas[1],1)*pow(deltas[2],0);
  res->r += factor*lhs->e112;
  factor = pow(deltas[0],1)*pow(deltas[1],2)*pow(deltas[2],0);
  res->r += factor*lhs->e122;
  factor = pow(deltas[0],0)*pow(deltas[1],3)*pow(deltas[2],0);
  res->r += factor*lhs->e222;
  factor = pow(deltas[0],2)*pow(deltas[1],0)*pow(deltas[2],1);
  res->r += factor*lhs->e113;
  factor = pow(deltas[0],1)*pow(deltas[1],1)*pow(deltas[2],1);
  res->r += factor*lhs->e123;
  factor = pow(deltas[0],0)*pow(deltas[1],2)*pow(deltas[2],1);
  res->r += factor*lhs->e223;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],2);
  res->r += factor*lhs->e133;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],2);
  res->r += factor*lhs->e233;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],3);
  res->r += factor*lhs->e333;
  // Order 4;
  factor = pow(deltas[0],4)*pow(deltas[1],0)*pow(deltas[2],0);
  res->r += factor*lhs->e1111;
  factor = pow(deltas[0],3)*pow(deltas[1],1)*pow(deltas[2],0);
  res->r += factor*lhs->e1112;
  factor = pow(deltas[0],2)*pow(deltas[1],2)*pow(deltas[2],0);
  res->r += factor*lhs->e1122;
  factor = pow(deltas[0],1)*pow(deltas[1],3)*pow(deltas[2],0);
  res->r += factor*lhs->e1222;
  factor = pow(deltas[0],0)*pow(deltas[1],4)*pow(deltas[2],0);
  res->r += factor*lhs->e2222;
  factor = pow(deltas[0],3)*pow(deltas[1],0)*pow(deltas[2],1);
  res->r += factor*lhs->e1113;
  factor = pow(deltas[0],2)*pow(deltas[1],1)*pow(deltas[2],1);
  res->r += factor*lhs->e1123;
  factor = pow(deltas[0],1)*pow(deltas[1],2)*pow(deltas[2],1);
  res->r += factor*lhs->e1223;
  factor = pow(deltas[0],0)*pow(deltas[1],3)*pow(deltas[2],1);
  res->r += factor*lhs->e2223;
  factor = pow(deltas[0],2)*pow(deltas[1],0)*pow(deltas[2],2);
  res->r += factor*lhs->e1133;
  factor = pow(deltas[0],1)*pow(deltas[1],1)*pow(deltas[2],2);
  res->r += factor*lhs->e1233;
  factor = pow(deltas[0],0)*pow(deltas[1],2)*pow(deltas[2],2);
  res->r += factor*lhs->e2233;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],3);
  res->r += factor*lhs->e1333;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],3);
  res->r += factor*lhs->e2333;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],4);
  res->r += factor*lhs->e3333;
  // Order 5;
  factor = pow(deltas[0],5)*pow(deltas[1],0)*pow(deltas[2],0);
  res->r += factor*lhs->e11111;
  factor = pow(deltas[0],4)*pow(deltas[1],1)*pow(deltas[2],0);
  res->r += factor*lhs->e11112;
  factor = pow(deltas[0],3)*pow(deltas[1],2)*pow(deltas[2],0);
  res->r += factor*lhs->e11122;
  factor = pow(deltas[0],2)*pow(deltas[1],3)*pow(deltas[2],0);
  res->r += factor*lhs->e11222;
  factor = pow(deltas[0],1)*pow(deltas[1],4)*pow(deltas[2],0);
  res->r += factor*lhs->e12222;
  factor = pow(deltas[0],0)*pow(deltas[1],5)*pow(deltas[2],0);
  res->r += factor*lhs->e22222;
  factor = pow(deltas[0],4)*pow(deltas[1],0)*pow(deltas[2],1);
  res->r += factor*lhs->e11113;
  factor = pow(deltas[0],3)*pow(deltas[1],1)*pow(deltas[2],1);
  res->r += factor*lhs->e11123;
  factor = pow(deltas[0],2)*pow(deltas[1],2)*pow(deltas[2],1);
  res->r += factor*lhs->e11223;
  factor = pow(deltas[0],1)*pow(deltas[1],3)*pow(deltas[2],1);
  res->r += factor*lhs->e12223;
  factor = pow(deltas[0],0)*pow(deltas[1],4)*pow(deltas[2],1);
  res->r += factor*lhs->e22223;
  factor = pow(deltas[0],3)*pow(deltas[1],0)*pow(deltas[2],2);
  res->r += factor*lhs->e11133;
  factor = pow(deltas[0],2)*pow(deltas[1],1)*pow(deltas[2],2);
  res->r += factor*lhs->e11233;
  factor = pow(deltas[0],1)*pow(deltas[1],2)*pow(deltas[2],2);
  res->r += factor*lhs->e12233;
  factor = pow(deltas[0],0)*pow(deltas[1],3)*pow(deltas[2],2);
  res->r += factor*lhs->e22233;
  factor = pow(deltas[0],2)*pow(deltas[1],0)*pow(deltas[2],3);
  res->r += factor*lhs->e11333;
  factor = pow(deltas[0],1)*pow(deltas[1],1)*pow(deltas[2],3);
  res->r += factor*lhs->e12333;
  factor = pow(deltas[0],0)*pow(deltas[1],2)*pow(deltas[2],3);
  res->r += factor*lhs->e22333;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],4);
  res->r += factor*lhs->e13333;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],4);
  res->r += factor*lhs->e23333;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],5);
  res->r += factor*lhs->e33333;

}

onumm3n5_t onumm3n5_truncate_im(imdir_t idx, ord_t order, onumm3n5_t* lhs){

  onumm3n5_t res;

  // Copy number.
  res = (*lhs);
  // Truncate all other values when necessary.
  // Real;
  switch (order){
    case 0:
      res = onumm3n5_init();
      break;
    case 1:
      switch (idx){
        case 0: //  e1
          res.e1 = 0.0;
          res.e11 = 0.0;
          res.e12 = 0.0;
          res.e13 = 0.0;
          res.e111 = 0.0;
          res.e112 = 0.0;
          res.e122 = 0.0;
          res.e113 = 0.0;
          res.e123 = 0.0;
          res.e133 = 0.0;
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
          break;
        case 1: //  e2
          res.e2 = 0.0;
          res.e12 = 0.0;
          res.e22 = 0.0;
          res.e23 = 0.0;
          res.e112 = 0.0;
          res.e122 = 0.0;
          res.e222 = 0.0;
          res.e123 = 0.0;
          res.e223 = 0.0;
          res.e233 = 0.0;
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
          break;
        case 2: //  e3
          res.e3 = 0.0;
          res.e13 = 0.0;
          res.e23 = 0.0;
          res.e33 = 0.0;
          res.e113 = 0.0;
          res.e123 = 0.0;
          res.e223 = 0.0;
          res.e133 = 0.0;
          res.e233 = 0.0;
          res.e333 = 0.0;
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
          res.e1111 = 0.0;
          res.e1112 = 0.0;
          res.e1122 = 0.0;
          res.e1113 = 0.0;
          res.e1123 = 0.0;
          res.e1133 = 0.0;
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
          break;
        case 1: //  e12
          res.e12 = 0.0;
          res.e112 = 0.0;
          res.e122 = 0.0;
          res.e123 = 0.0;
          res.e1112 = 0.0;
          res.e1122 = 0.0;
          res.e1222 = 0.0;
          res.e1123 = 0.0;
          res.e1223 = 0.0;
          res.e1233 = 0.0;
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
          break;
        case 2: //  e22
          res.e22 = 0.0;
          res.e122 = 0.0;
          res.e222 = 0.0;
          res.e223 = 0.0;
          res.e1122 = 0.0;
          res.e1222 = 0.0;
          res.e2222 = 0.0;
          res.e1223 = 0.0;
          res.e2223 = 0.0;
          res.e2233 = 0.0;
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
          break;
        case 3: //  e13
          res.e13 = 0.0;
          res.e113 = 0.0;
          res.e123 = 0.0;
          res.e133 = 0.0;
          res.e1113 = 0.0;
          res.e1123 = 0.0;
          res.e1223 = 0.0;
          res.e1133 = 0.0;
          res.e1233 = 0.0;
          res.e1333 = 0.0;
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
          break;
        case 4: //  e23
          res.e23 = 0.0;
          res.e123 = 0.0;
          res.e223 = 0.0;
          res.e233 = 0.0;
          res.e1123 = 0.0;
          res.e1223 = 0.0;
          res.e2223 = 0.0;
          res.e1233 = 0.0;
          res.e2233 = 0.0;
          res.e2333 = 0.0;
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
          break;
        case 5: //  e33
          res.e33 = 0.0;
          res.e133 = 0.0;
          res.e233 = 0.0;
          res.e333 = 0.0;
          res.e1133 = 0.0;
          res.e1233 = 0.0;
          res.e2233 = 0.0;
          res.e1333 = 0.0;
          res.e2333 = 0.0;
          res.e3333 = 0.0;
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
          res.e11111 = 0.0;
          res.e11112 = 0.0;
          res.e11122 = 0.0;
          res.e11113 = 0.0;
          res.e11123 = 0.0;
          res.e11133 = 0.0;
          break;
        case 1: //  e112
          res.e112 = 0.0;
          res.e1112 = 0.0;
          res.e1122 = 0.0;
          res.e1123 = 0.0;
          res.e11112 = 0.0;
          res.e11122 = 0.0;
          res.e11222 = 0.0;
          res.e11123 = 0.0;
          res.e11223 = 0.0;
          res.e11233 = 0.0;
          break;
        case 2: //  e122
          res.e122 = 0.0;
          res.e1122 = 0.0;
          res.e1222 = 0.0;
          res.e1223 = 0.0;
          res.e11122 = 0.0;
          res.e11222 = 0.0;
          res.e12222 = 0.0;
          res.e11223 = 0.0;
          res.e12223 = 0.0;
          res.e12233 = 0.0;
          break;
        case 3: //  e222
          res.e222 = 0.0;
          res.e1222 = 0.0;
          res.e2222 = 0.0;
          res.e2223 = 0.0;
          res.e11222 = 0.0;
          res.e12222 = 0.0;
          res.e22222 = 0.0;
          res.e12223 = 0.0;
          res.e22223 = 0.0;
          res.e22233 = 0.0;
          break;
        case 4: //  e113
          res.e113 = 0.0;
          res.e1113 = 0.0;
          res.e1123 = 0.0;
          res.e1133 = 0.0;
          res.e11113 = 0.0;
          res.e11123 = 0.0;
          res.e11223 = 0.0;
          res.e11133 = 0.0;
          res.e11233 = 0.0;
          res.e11333 = 0.0;
          break;
        case 5: //  e123
          res.e123 = 0.0;
          res.e1123 = 0.0;
          res.e1223 = 0.0;
          res.e1233 = 0.0;
          res.e11123 = 0.0;
          res.e11223 = 0.0;
          res.e12223 = 0.0;
          res.e11233 = 0.0;
          res.e12233 = 0.0;
          res.e12333 = 0.0;
          break;
        case 6: //  e223
          res.e223 = 0.0;
          res.e1223 = 0.0;
          res.e2223 = 0.0;
          res.e2233 = 0.0;
          res.e11223 = 0.0;
          res.e12223 = 0.0;
          res.e22223 = 0.0;
          res.e12233 = 0.0;
          res.e22233 = 0.0;
          res.e22333 = 0.0;
          break;
        case 7: //  e133
          res.e133 = 0.0;
          res.e1133 = 0.0;
          res.e1233 = 0.0;
          res.e1333 = 0.0;
          res.e11133 = 0.0;
          res.e11233 = 0.0;
          res.e12233 = 0.0;
          res.e11333 = 0.0;
          res.e12333 = 0.0;
          res.e13333 = 0.0;
          break;
        case 8: //  e233
          res.e233 = 0.0;
          res.e1233 = 0.0;
          res.e2233 = 0.0;
          res.e2333 = 0.0;
          res.e11233 = 0.0;
          res.e12233 = 0.0;
          res.e22233 = 0.0;
          res.e12333 = 0.0;
          res.e22333 = 0.0;
          res.e23333 = 0.0;
          break;
        case 9: //  e333
          res.e333 = 0.0;
          res.e1333 = 0.0;
          res.e2333 = 0.0;
          res.e3333 = 0.0;
          res.e11333 = 0.0;
          res.e12333 = 0.0;
          res.e22333 = 0.0;
          res.e13333 = 0.0;
          res.e23333 = 0.0;
          res.e33333 = 0.0;
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
          break;
        case 1: //  e1112
          res.e1112 = 0.0;
          res.e11112 = 0.0;
          res.e11122 = 0.0;
          res.e11123 = 0.0;
          break;
        case 2: //  e1122
          res.e1122 = 0.0;
          res.e11122 = 0.0;
          res.e11222 = 0.0;
          res.e11223 = 0.0;
          break;
        case 3: //  e1222
          res.e1222 = 0.0;
          res.e11222 = 0.0;
          res.e12222 = 0.0;
          res.e12223 = 0.0;
          break;
        case 4: //  e2222
          res.e2222 = 0.0;
          res.e12222 = 0.0;
          res.e22222 = 0.0;
          res.e22223 = 0.0;
          break;
        case 5: //  e1113
          res.e1113 = 0.0;
          res.e11113 = 0.0;
          res.e11123 = 0.0;
          res.e11133 = 0.0;
          break;
        case 6: //  e1123
          res.e1123 = 0.0;
          res.e11123 = 0.0;
          res.e11223 = 0.0;
          res.e11233 = 0.0;
          break;
        case 7: //  e1223
          res.e1223 = 0.0;
          res.e11223 = 0.0;
          res.e12223 = 0.0;
          res.e12233 = 0.0;
          break;
        case 8: //  e2223
          res.e2223 = 0.0;
          res.e12223 = 0.0;
          res.e22223 = 0.0;
          res.e22233 = 0.0;
          break;
        case 9: //  e1133
          res.e1133 = 0.0;
          res.e11133 = 0.0;
          res.e11233 = 0.0;
          res.e11333 = 0.0;
          break;
        case 10: //  e1233
          res.e1233 = 0.0;
          res.e11233 = 0.0;
          res.e12233 = 0.0;
          res.e12333 = 0.0;
          break;
        case 11: //  e2233
          res.e2233 = 0.0;
          res.e12233 = 0.0;
          res.e22233 = 0.0;
          res.e22333 = 0.0;
          break;
        case 12: //  e1333
          res.e1333 = 0.0;
          res.e11333 = 0.0;
          res.e12333 = 0.0;
          res.e13333 = 0.0;
          break;
        case 13: //  e2333
          res.e2333 = 0.0;
          res.e12333 = 0.0;
          res.e22333 = 0.0;
          res.e23333 = 0.0;
          break;
        case 14: //  e3333
          res.e3333 = 0.0;
          res.e13333 = 0.0;
          res.e23333 = 0.0;
          res.e33333 = 0.0;
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
      }
      break;
  }
  return res;

}

void onumm3n5_truncate_im_to(imdir_t idx, ord_t order, onumm3n5_t* lhs, onumm3n5_t* res){

  // Copy number.
  *res = (*lhs);
  // Truncate all other values when necessary.
  // Real;
  switch (order){
    case 0:
      *res = onumm3n5_init();
      break;
    case 1:
      switch (idx){
        case 0: //  e1
          res->e1 = 0.0;
          res->e11 = 0.0;
          res->e12 = 0.0;
          res->e13 = 0.0;
          res->e111 = 0.0;
          res->e112 = 0.0;
          res->e122 = 0.0;
          res->e113 = 0.0;
          res->e123 = 0.0;
          res->e133 = 0.0;
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
          break;
        case 1: //  e2
          res->e2 = 0.0;
          res->e12 = 0.0;
          res->e22 = 0.0;
          res->e23 = 0.0;
          res->e112 = 0.0;
          res->e122 = 0.0;
          res->e222 = 0.0;
          res->e123 = 0.0;
          res->e223 = 0.0;
          res->e233 = 0.0;
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
          break;
        case 2: //  e3
          res->e3 = 0.0;
          res->e13 = 0.0;
          res->e23 = 0.0;
          res->e33 = 0.0;
          res->e113 = 0.0;
          res->e123 = 0.0;
          res->e223 = 0.0;
          res->e133 = 0.0;
          res->e233 = 0.0;
          res->e333 = 0.0;
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
          res->e1111 = 0.0;
          res->e1112 = 0.0;
          res->e1122 = 0.0;
          res->e1113 = 0.0;
          res->e1123 = 0.0;
          res->e1133 = 0.0;
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
          break;
        case 1: //  e12
          res->e12 = 0.0;
          res->e112 = 0.0;
          res->e122 = 0.0;
          res->e123 = 0.0;
          res->e1112 = 0.0;
          res->e1122 = 0.0;
          res->e1222 = 0.0;
          res->e1123 = 0.0;
          res->e1223 = 0.0;
          res->e1233 = 0.0;
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
          break;
        case 2: //  e22
          res->e22 = 0.0;
          res->e122 = 0.0;
          res->e222 = 0.0;
          res->e223 = 0.0;
          res->e1122 = 0.0;
          res->e1222 = 0.0;
          res->e2222 = 0.0;
          res->e1223 = 0.0;
          res->e2223 = 0.0;
          res->e2233 = 0.0;
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
          break;
        case 3: //  e13
          res->e13 = 0.0;
          res->e113 = 0.0;
          res->e123 = 0.0;
          res->e133 = 0.0;
          res->e1113 = 0.0;
          res->e1123 = 0.0;
          res->e1223 = 0.0;
          res->e1133 = 0.0;
          res->e1233 = 0.0;
          res->e1333 = 0.0;
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
          break;
        case 4: //  e23
          res->e23 = 0.0;
          res->e123 = 0.0;
          res->e223 = 0.0;
          res->e233 = 0.0;
          res->e1123 = 0.0;
          res->e1223 = 0.0;
          res->e2223 = 0.0;
          res->e1233 = 0.0;
          res->e2233 = 0.0;
          res->e2333 = 0.0;
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
          break;
        case 5: //  e33
          res->e33 = 0.0;
          res->e133 = 0.0;
          res->e233 = 0.0;
          res->e333 = 0.0;
          res->e1133 = 0.0;
          res->e1233 = 0.0;
          res->e2233 = 0.0;
          res->e1333 = 0.0;
          res->e2333 = 0.0;
          res->e3333 = 0.0;
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
          res->e11111 = 0.0;
          res->e11112 = 0.0;
          res->e11122 = 0.0;
          res->e11113 = 0.0;
          res->e11123 = 0.0;
          res->e11133 = 0.0;
          break;
        case 1: //  e112
          res->e112 = 0.0;
          res->e1112 = 0.0;
          res->e1122 = 0.0;
          res->e1123 = 0.0;
          res->e11112 = 0.0;
          res->e11122 = 0.0;
          res->e11222 = 0.0;
          res->e11123 = 0.0;
          res->e11223 = 0.0;
          res->e11233 = 0.0;
          break;
        case 2: //  e122
          res->e122 = 0.0;
          res->e1122 = 0.0;
          res->e1222 = 0.0;
          res->e1223 = 0.0;
          res->e11122 = 0.0;
          res->e11222 = 0.0;
          res->e12222 = 0.0;
          res->e11223 = 0.0;
          res->e12223 = 0.0;
          res->e12233 = 0.0;
          break;
        case 3: //  e222
          res->e222 = 0.0;
          res->e1222 = 0.0;
          res->e2222 = 0.0;
          res->e2223 = 0.0;
          res->e11222 = 0.0;
          res->e12222 = 0.0;
          res->e22222 = 0.0;
          res->e12223 = 0.0;
          res->e22223 = 0.0;
          res->e22233 = 0.0;
          break;
        case 4: //  e113
          res->e113 = 0.0;
          res->e1113 = 0.0;
          res->e1123 = 0.0;
          res->e1133 = 0.0;
          res->e11113 = 0.0;
          res->e11123 = 0.0;
          res->e11223 = 0.0;
          res->e11133 = 0.0;
          res->e11233 = 0.0;
          res->e11333 = 0.0;
          break;
        case 5: //  e123
          res->e123 = 0.0;
          res->e1123 = 0.0;
          res->e1223 = 0.0;
          res->e1233 = 0.0;
          res->e11123 = 0.0;
          res->e11223 = 0.0;
          res->e12223 = 0.0;
          res->e11233 = 0.0;
          res->e12233 = 0.0;
          res->e12333 = 0.0;
          break;
        case 6: //  e223
          res->e223 = 0.0;
          res->e1223 = 0.0;
          res->e2223 = 0.0;
          res->e2233 = 0.0;
          res->e11223 = 0.0;
          res->e12223 = 0.0;
          res->e22223 = 0.0;
          res->e12233 = 0.0;
          res->e22233 = 0.0;
          res->e22333 = 0.0;
          break;
        case 7: //  e133
          res->e133 = 0.0;
          res->e1133 = 0.0;
          res->e1233 = 0.0;
          res->e1333 = 0.0;
          res->e11133 = 0.0;
          res->e11233 = 0.0;
          res->e12233 = 0.0;
          res->e11333 = 0.0;
          res->e12333 = 0.0;
          res->e13333 = 0.0;
          break;
        case 8: //  e233
          res->e233 = 0.0;
          res->e1233 = 0.0;
          res->e2233 = 0.0;
          res->e2333 = 0.0;
          res->e11233 = 0.0;
          res->e12233 = 0.0;
          res->e22233 = 0.0;
          res->e12333 = 0.0;
          res->e22333 = 0.0;
          res->e23333 = 0.0;
          break;
        case 9: //  e333
          res->e333 = 0.0;
          res->e1333 = 0.0;
          res->e2333 = 0.0;
          res->e3333 = 0.0;
          res->e11333 = 0.0;
          res->e12333 = 0.0;
          res->e22333 = 0.0;
          res->e13333 = 0.0;
          res->e23333 = 0.0;
          res->e33333 = 0.0;
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
          break;
        case 1: //  e1112
          res->e1112 = 0.0;
          res->e11112 = 0.0;
          res->e11122 = 0.0;
          res->e11123 = 0.0;
          break;
        case 2: //  e1122
          res->e1122 = 0.0;
          res->e11122 = 0.0;
          res->e11222 = 0.0;
          res->e11223 = 0.0;
          break;
        case 3: //  e1222
          res->e1222 = 0.0;
          res->e11222 = 0.0;
          res->e12222 = 0.0;
          res->e12223 = 0.0;
          break;
        case 4: //  e2222
          res->e2222 = 0.0;
          res->e12222 = 0.0;
          res->e22222 = 0.0;
          res->e22223 = 0.0;
          break;
        case 5: //  e1113
          res->e1113 = 0.0;
          res->e11113 = 0.0;
          res->e11123 = 0.0;
          res->e11133 = 0.0;
          break;
        case 6: //  e1123
          res->e1123 = 0.0;
          res->e11123 = 0.0;
          res->e11223 = 0.0;
          res->e11233 = 0.0;
          break;
        case 7: //  e1223
          res->e1223 = 0.0;
          res->e11223 = 0.0;
          res->e12223 = 0.0;
          res->e12233 = 0.0;
          break;
        case 8: //  e2223
          res->e2223 = 0.0;
          res->e12223 = 0.0;
          res->e22223 = 0.0;
          res->e22233 = 0.0;
          break;
        case 9: //  e1133
          res->e1133 = 0.0;
          res->e11133 = 0.0;
          res->e11233 = 0.0;
          res->e11333 = 0.0;
          break;
        case 10: //  e1233
          res->e1233 = 0.0;
          res->e11233 = 0.0;
          res->e12233 = 0.0;
          res->e12333 = 0.0;
          break;
        case 11: //  e2233
          res->e2233 = 0.0;
          res->e12233 = 0.0;
          res->e22233 = 0.0;
          res->e22333 = 0.0;
          break;
        case 12: //  e1333
          res->e1333 = 0.0;
          res->e11333 = 0.0;
          res->e12333 = 0.0;
          res->e13333 = 0.0;
          break;
        case 13: //  e2333
          res->e2333 = 0.0;
          res->e12333 = 0.0;
          res->e22333 = 0.0;
          res->e23333 = 0.0;
          break;
        case 14: //  e3333
          res->e3333 = 0.0;
          res->e13333 = 0.0;
          res->e23333 = 0.0;
          res->e33333 = 0.0;
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
      }
      break;
  }
}

void onumm3n5_print(  onumm3n5_t* lhs){

  // Print function.
  //  Real;
  printf("%.8g",lhs->r);
  //  Order 1;
  printf(" %+.8g*e1",lhs->e1);
  printf(" %+.8g*e2",lhs->e2);
  printf(" %+.8g*e3",lhs->e3);
  //  Order 2;
  printf(" %+.8g*e11",lhs->e11);
  printf(" %+.8g*e12",lhs->e12);
  printf(" %+.8g*e22",lhs->e22);
  printf(" %+.8g*e13",lhs->e13);
  printf(" %+.8g*e23",lhs->e23);
  printf(" %+.8g*e33",lhs->e33);
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
  printf("\n");

}

imdir_t onumm3n5_get_indx(imdir_t idx, ord_t order){

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
      }
      break;
      default:
          return 0;
  }
  return 0;
}

