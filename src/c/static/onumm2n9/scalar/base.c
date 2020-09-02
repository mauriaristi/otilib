

// Not implemented correctly:
void onumm2n9_set_im_o(onumm2n9_t* num, imdir_t idx, ord_t order, onumm2n9_t* res){
    onumm2n9_set_item(num->r,idx,order,res);
}
void onumm2n9_set_deriv_r(coeff_t num, imdir_t idx, ord_t order, onumm2n9_t* res){
    *res=onumm2n9_init();
}
void onumm2n9_set_deriv_o(onumm2n9_t* num, imdir_t idx, ord_t order, onumm2n9_t* res){
    *res=onumm2n9_init();
}
void onumm2n9_extract_im_to( imdir_t idx, ord_t order, onumm2n9_t* num, onumm2n9_t* res){
    *res=onumm2n9_init();
}
onumm2n9_t onumm2n9_extract_im(imdir_t idx, ord_t order, onumm2n9_t* num){
    onumm2n9_t res = onumm2n9_init();
    return res;
}
onumm2n9_t onumm2n9_extract_deriv(imdir_t idx, ord_t order, onumm2n9_t* num){
    onumm2n9_t res = onumm2n9_init();
    return res;
}
void onumm2n9_extract_deriv_to(imdir_t idx, ord_t order, onumm2n9_t* num, onumm2n9_t* res){
	*res = onumm2n9_init();
}
void onumm2n9_get_im_to_o(imdir_t idx, ord_t order, onumm2n9_t* num, onumm2n9_t* res){
    coeff_t rres = onumm2n9_get_item(idx, order, num);
    onumm2n9_set_r(rres,res);
}
onumm2n9_t onumm2n9_get_im_o(imdir_t idx, ord_t order, onumm2n9_t* num){
    coeff_t rres = onumm2n9_get_item(idx, order, num);
    onumm2n9_t res;
    onumm2n9_set_r(rres,&res);
    return res;
}
void onumm2n9_get_im_to_r(imdir_t idx, ord_t order, onumm2n9_t* num, coeff_t* res){
    *res = onumm2n9_get_item(idx, order, num);
}

inline ord_t onumm2n9_get_order(onumm2n9_t* lhs){

	return 9;

}

onumm2n9_t onumm2n9_get_deriv_o( imdir_t idx, ord_t order, onumm2n9_t* num){

    onumm2n9_t res = onumm2n9_init();

    onumm2n9_get_deriv_to( idx, order, num, &res);
    
    return res;

}

void onumm2n9_get_deriv_to( imdir_t idx, ord_t order, onumm2n9_t* num, onumm2n9_t* res){

    coeff_t deriv = onumm2n9_get_deriv(idx,order,num);

    onumm2n9_set_r( deriv, res);

}

void onumm2n9_set_im_r(coeff_t num, imdir_t idx, ord_t order, onumm2n9_t* res){

    onumm2n9_set_item(num, idx,order,res);

}

onumm2n9_t onumm2n9_init(void){

  onumm2n9_t res;

  // Init function
  // Real;
  res.r = 0.0;
  // Order 1;
  res.e1 = 0.0;
  res.e2 = 0.0;
  // Order 2;
  res.e11 = 0.0;
  res.e12 = 0.0;
  res.e22 = 0.0;
  // Order 3;
  res.e111 = 0.0;
  res.e112 = 0.0;
  res.e122 = 0.0;
  res.e222 = 0.0;
  // Order 4;
  res.e1111 = 0.0;
  res.e1112 = 0.0;
  res.e1122 = 0.0;
  res.e1222 = 0.0;
  res.e2222 = 0.0;
  // Order 5;
  res.e11111 = 0.0;
  res.e11112 = 0.0;
  res.e11122 = 0.0;
  res.e11222 = 0.0;
  res.e12222 = 0.0;
  res.e22222 = 0.0;
  // Order 6;
  res.e111111 = 0.0;
  res.e111112 = 0.0;
  res.e111122 = 0.0;
  res.e111222 = 0.0;
  res.e112222 = 0.0;
  res.e122222 = 0.0;
  res.e222222 = 0.0;
  // Order 7;
  res.e1111111 = 0.0;
  res.e1111112 = 0.0;
  res.e1111122 = 0.0;
  res.e1111222 = 0.0;
  res.e1112222 = 0.0;
  res.e1122222 = 0.0;
  res.e1222222 = 0.0;
  res.e2222222 = 0.0;
  // Order 8;
  res.e11111111 = 0.0;
  res.e11111112 = 0.0;
  res.e11111122 = 0.0;
  res.e11111222 = 0.0;
  res.e11112222 = 0.0;
  res.e11122222 = 0.0;
  res.e11222222 = 0.0;
  res.e12222222 = 0.0;
  res.e22222222 = 0.0;
  // Order 9;
  res.e111111111 = 0.0;
  res.e111111112 = 0.0;
  res.e111111122 = 0.0;
  res.e111111222 = 0.0;
  res.e111112222 = 0.0;
  res.e111122222 = 0.0;
  res.e111222222 = 0.0;
  res.e112222222 = 0.0;
  res.e122222222 = 0.0;
  res.e222222222 = 0.0;

  return res;

}

ndir_t onumm2n9_get_ndir_order(ord_t order, onumm2n9_t* num){

  ndir_t res;

  switch(order){
    case 0:
      res = 1;
      break;
    case 1:
      res = 2;
      break;
    case 2:
      res = 3;
      break;
    case 3:
      res = 4;
      break;
    case 4:
      res = 5;
      break;
    case 5:
      res = 6;
      break;
    case 6:
      res = 7;
      break;
    case 7:
      res = 8;
      break;
    case 8:
      res = 9;
      break;
    case 9:
      res = 10;
      break;
  }

  return res;

}

ndir_t onumm2n9_get_ndir_total(onumm2n9_t* num){

  ndir_t res;

  res = 45;

  return res;

}

coeff_t* onumm2n9_get_order_address(ord_t order, onumm2n9_t* num){

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
    case 6:
      res = &num->e111111;
      break;
    case 7:
      res = &num->e1111111;
      break;
    case 8:
      res = &num->e11111111;
      break;
    case 9:
      res = &num->e111111111;
      break;
  }
  return res;

}

onumm2n9_t onumm2n9_create_r(  coeff_t lhs){

  onumm2n9_t res;

  // Assign like function 'lhs'
  // Real;
  res.r = lhs;
  // Order 1;
  res.e1 = 0.0;
  res.e2 = 0.0;
  // Order 2;
  res.e11 = 0.0;
  res.e12 = 0.0;
  res.e22 = 0.0;
  // Order 3;
  res.e111 = 0.0;
  res.e112 = 0.0;
  res.e122 = 0.0;
  res.e222 = 0.0;
  // Order 4;
  res.e1111 = 0.0;
  res.e1112 = 0.0;
  res.e1122 = 0.0;
  res.e1222 = 0.0;
  res.e2222 = 0.0;
  // Order 5;
  res.e11111 = 0.0;
  res.e11112 = 0.0;
  res.e11122 = 0.0;
  res.e11222 = 0.0;
  res.e12222 = 0.0;
  res.e22222 = 0.0;
  // Order 6;
  res.e111111 = 0.0;
  res.e111112 = 0.0;
  res.e111122 = 0.0;
  res.e111222 = 0.0;
  res.e112222 = 0.0;
  res.e122222 = 0.0;
  res.e222222 = 0.0;
  // Order 7;
  res.e1111111 = 0.0;
  res.e1111112 = 0.0;
  res.e1111122 = 0.0;
  res.e1111222 = 0.0;
  res.e1112222 = 0.0;
  res.e1122222 = 0.0;
  res.e1222222 = 0.0;
  res.e2222222 = 0.0;
  // Order 8;
  res.e11111111 = 0.0;
  res.e11111112 = 0.0;
  res.e11111122 = 0.0;
  res.e11111222 = 0.0;
  res.e11112222 = 0.0;
  res.e11122222 = 0.0;
  res.e11222222 = 0.0;
  res.e12222222 = 0.0;
  res.e22222222 = 0.0;
  // Order 9;
  res.e111111111 = 0.0;
  res.e111111112 = 0.0;
  res.e111111122 = 0.0;
  res.e111111222 = 0.0;
  res.e111112222 = 0.0;
  res.e111122222 = 0.0;
  res.e111222222 = 0.0;
  res.e112222222 = 0.0;
  res.e122222222 = 0.0;
  res.e222222222 = 0.0;

  return res;

}

void onumm2n9_set_r(  coeff_t lhs, onumm2n9_t* res){

  // Assign like function 'lhs'
  // Real;
  res->r = lhs;
  // Order 1;
  res->e1 = 0.0;
  res->e2 = 0.0;
  // Order 2;
  res->e11 = 0.0;
  res->e12 = 0.0;
  res->e22 = 0.0;
  // Order 3;
  res->e111 = 0.0;
  res->e112 = 0.0;
  res->e122 = 0.0;
  res->e222 = 0.0;
  // Order 4;
  res->e1111 = 0.0;
  res->e1112 = 0.0;
  res->e1122 = 0.0;
  res->e1222 = 0.0;
  res->e2222 = 0.0;
  // Order 5;
  res->e11111 = 0.0;
  res->e11112 = 0.0;
  res->e11122 = 0.0;
  res->e11222 = 0.0;
  res->e12222 = 0.0;
  res->e22222 = 0.0;
  // Order 6;
  res->e111111 = 0.0;
  res->e111112 = 0.0;
  res->e111122 = 0.0;
  res->e111222 = 0.0;
  res->e112222 = 0.0;
  res->e122222 = 0.0;
  res->e222222 = 0.0;
  // Order 7;
  res->e1111111 = 0.0;
  res->e1111112 = 0.0;
  res->e1111122 = 0.0;
  res->e1111222 = 0.0;
  res->e1112222 = 0.0;
  res->e1122222 = 0.0;
  res->e1222222 = 0.0;
  res->e2222222 = 0.0;
  // Order 8;
  res->e11111111 = 0.0;
  res->e11111112 = 0.0;
  res->e11111122 = 0.0;
  res->e11111222 = 0.0;
  res->e11112222 = 0.0;
  res->e11122222 = 0.0;
  res->e11222222 = 0.0;
  res->e12222222 = 0.0;
  res->e22222222 = 0.0;
  // Order 9;
  res->e111111111 = 0.0;
  res->e111111112 = 0.0;
  res->e111111122 = 0.0;
  res->e111111222 = 0.0;
  res->e111112222 = 0.0;
  res->e111122222 = 0.0;
  res->e111222222 = 0.0;
  res->e112222222 = 0.0;
  res->e122222222 = 0.0;
  res->e222222222 = 0.0;

}

void onumm2n9_set_o(  onumm2n9_t* lhs, onumm2n9_t* res){

  // Assign like function 'lhs'
  // Real;
  res->r = lhs->r;
  // Order 1;
  res->e1 = lhs->e1;
  res->e2 = lhs->e2;
  // Order 2;
  res->e11 = lhs->e11;
  res->e12 = lhs->e12;
  res->e22 = lhs->e22;
  // Order 3;
  res->e111 = lhs->e111;
  res->e112 = lhs->e112;
  res->e122 = lhs->e122;
  res->e222 = lhs->e222;
  // Order 4;
  res->e1111 = lhs->e1111;
  res->e1112 = lhs->e1112;
  res->e1122 = lhs->e1122;
  res->e1222 = lhs->e1222;
  res->e2222 = lhs->e2222;
  // Order 5;
  res->e11111 = lhs->e11111;
  res->e11112 = lhs->e11112;
  res->e11122 = lhs->e11122;
  res->e11222 = lhs->e11222;
  res->e12222 = lhs->e12222;
  res->e22222 = lhs->e22222;
  // Order 6;
  res->e111111 = lhs->e111111;
  res->e111112 = lhs->e111112;
  res->e111122 = lhs->e111122;
  res->e111222 = lhs->e111222;
  res->e112222 = lhs->e112222;
  res->e122222 = lhs->e122222;
  res->e222222 = lhs->e222222;
  // Order 7;
  res->e1111111 = lhs->e1111111;
  res->e1111112 = lhs->e1111112;
  res->e1111122 = lhs->e1111122;
  res->e1111222 = lhs->e1111222;
  res->e1112222 = lhs->e1112222;
  res->e1122222 = lhs->e1122222;
  res->e1222222 = lhs->e1222222;
  res->e2222222 = lhs->e2222222;
  // Order 8;
  res->e11111111 = lhs->e11111111;
  res->e11111112 = lhs->e11111112;
  res->e11111122 = lhs->e11111122;
  res->e11111222 = lhs->e11111222;
  res->e11112222 = lhs->e11112222;
  res->e11122222 = lhs->e11122222;
  res->e11222222 = lhs->e11222222;
  res->e12222222 = lhs->e12222222;
  res->e22222222 = lhs->e22222222;
  // Order 9;
  res->e111111111 = lhs->e111111111;
  res->e111111112 = lhs->e111111112;
  res->e111111122 = lhs->e111111122;
  res->e111111222 = lhs->e111111222;
  res->e111112222 = lhs->e111112222;
  res->e111122222 = lhs->e111122222;
  res->e111222222 = lhs->e111222222;
  res->e112222222 = lhs->e112222222;
  res->e122222222 = lhs->e122222222;
  res->e222222222 = lhs->e222222222;

}

onumm2n9_t onumm2n9_get_order_im(ord_t order, onumm2n9_t* lhs){

  onumm2n9_t res;

  res = onumm2n9_init();
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
      break;
    case 2:
      // Order 2;
      res.e11 = lhs->e11;
      res.e12 = lhs->e12;
      res.e22 = lhs->e22;
      break;
    case 3:
      // Order 3;
      res.e111 = lhs->e111;
      res.e112 = lhs->e112;
      res.e122 = lhs->e122;
      res.e222 = lhs->e222;
      break;
    case 4:
      // Order 4;
      res.e1111 = lhs->e1111;
      res.e1112 = lhs->e1112;
      res.e1122 = lhs->e1122;
      res.e1222 = lhs->e1222;
      res.e2222 = lhs->e2222;
      break;
    case 5:
      // Order 5;
      res.e11111 = lhs->e11111;
      res.e11112 = lhs->e11112;
      res.e11122 = lhs->e11122;
      res.e11222 = lhs->e11222;
      res.e12222 = lhs->e12222;
      res.e22222 = lhs->e22222;
      break;
    case 6:
      // Order 6;
      res.e111111 = lhs->e111111;
      res.e111112 = lhs->e111112;
      res.e111122 = lhs->e111122;
      res.e111222 = lhs->e111222;
      res.e112222 = lhs->e112222;
      res.e122222 = lhs->e122222;
      res.e222222 = lhs->e222222;
      break;
    case 7:
      // Order 7;
      res.e1111111 = lhs->e1111111;
      res.e1111112 = lhs->e1111112;
      res.e1111122 = lhs->e1111122;
      res.e1111222 = lhs->e1111222;
      res.e1112222 = lhs->e1112222;
      res.e1122222 = lhs->e1122222;
      res.e1222222 = lhs->e1222222;
      res.e2222222 = lhs->e2222222;
      break;
    case 8:
      // Order 8;
      res.e11111111 = lhs->e11111111;
      res.e11111112 = lhs->e11111112;
      res.e11111122 = lhs->e11111122;
      res.e11111222 = lhs->e11111222;
      res.e11112222 = lhs->e11112222;
      res.e11122222 = lhs->e11122222;
      res.e11222222 = lhs->e11222222;
      res.e12222222 = lhs->e12222222;
      res.e22222222 = lhs->e22222222;
      break;
    case 9:
      // Order 9;
      res.e111111111 = lhs->e111111111;
      res.e111111112 = lhs->e111111112;
      res.e111111122 = lhs->e111111122;
      res.e111111222 = lhs->e111111222;
      res.e111112222 = lhs->e111112222;
      res.e111122222 = lhs->e111122222;
      res.e111222222 = lhs->e111222222;
      res.e112222222 = lhs->e112222222;
      res.e122222222 = lhs->e122222222;
      res.e222222222 = lhs->e222222222;
      break;
  }

  return res;

}

void onumm2n9_get_order_im_to(ord_t order, onumm2n9_t* lhs, onumm2n9_t* res){


  *res = onumm2n9_init();
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
      break;
    case 2:
      // Order 2;
      res->e11 = lhs->e11;
      res->e12 = lhs->e12;
      res->e22 = lhs->e22;
      break;
    case 3:
      // Order 3;
      res->e111 = lhs->e111;
      res->e112 = lhs->e112;
      res->e122 = lhs->e122;
      res->e222 = lhs->e222;
      break;
    case 4:
      // Order 4;
      res->e1111 = lhs->e1111;
      res->e1112 = lhs->e1112;
      res->e1122 = lhs->e1122;
      res->e1222 = lhs->e1222;
      res->e2222 = lhs->e2222;
      break;
    case 5:
      // Order 5;
      res->e11111 = lhs->e11111;
      res->e11112 = lhs->e11112;
      res->e11122 = lhs->e11122;
      res->e11222 = lhs->e11222;
      res->e12222 = lhs->e12222;
      res->e22222 = lhs->e22222;
      break;
    case 6:
      // Order 6;
      res->e111111 = lhs->e111111;
      res->e111112 = lhs->e111112;
      res->e111122 = lhs->e111122;
      res->e111222 = lhs->e111222;
      res->e112222 = lhs->e112222;
      res->e122222 = lhs->e122222;
      res->e222222 = lhs->e222222;
      break;
    case 7:
      // Order 7;
      res->e1111111 = lhs->e1111111;
      res->e1111112 = lhs->e1111112;
      res->e1111122 = lhs->e1111122;
      res->e1111222 = lhs->e1111222;
      res->e1112222 = lhs->e1112222;
      res->e1122222 = lhs->e1122222;
      res->e1222222 = lhs->e1222222;
      res->e2222222 = lhs->e2222222;
      break;
    case 8:
      // Order 8;
      res->e11111111 = lhs->e11111111;
      res->e11111112 = lhs->e11111112;
      res->e11111122 = lhs->e11111122;
      res->e11111222 = lhs->e11111222;
      res->e11112222 = lhs->e11112222;
      res->e11122222 = lhs->e11122222;
      res->e11222222 = lhs->e11222222;
      res->e12222222 = lhs->e12222222;
      res->e22222222 = lhs->e22222222;
      break;
    case 9:
      // Order 9;
      res->e111111111 = lhs->e111111111;
      res->e111111112 = lhs->e111111112;
      res->e111111122 = lhs->e111111122;
      res->e111111222 = lhs->e111111222;
      res->e111112222 = lhs->e111112222;
      res->e111122222 = lhs->e111122222;
      res->e111222222 = lhs->e111222222;
      res->e112222222 = lhs->e112222222;
      res->e122222222 = lhs->e122222222;
      res->e222222222 = lhs->e222222222;
      break;
  }

}

coeff_t onumm2n9_get_item(imdir_t idx, ord_t order, onumm2n9_t* lhs){

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
      }
      break;
    case 6:
      switch (idx){
        case 0:
          res = lhs->e111111;
          break;
        case 1:
          res = lhs->e111112;
          break;
        case 2:
          res = lhs->e111122;
          break;
        case 3:
          res = lhs->e111222;
          break;
        case 4:
          res = lhs->e112222;
          break;
        case 5:
          res = lhs->e122222;
          break;
        case 6:
          res = lhs->e222222;
          break;
      }
      break;
    case 7:
      switch (idx){
        case 0:
          res = lhs->e1111111;
          break;
        case 1:
          res = lhs->e1111112;
          break;
        case 2:
          res = lhs->e1111122;
          break;
        case 3:
          res = lhs->e1111222;
          break;
        case 4:
          res = lhs->e1112222;
          break;
        case 5:
          res = lhs->e1122222;
          break;
        case 6:
          res = lhs->e1222222;
          break;
        case 7:
          res = lhs->e2222222;
          break;
      }
      break;
    case 8:
      switch (idx){
        case 0:
          res = lhs->e11111111;
          break;
        case 1:
          res = lhs->e11111112;
          break;
        case 2:
          res = lhs->e11111122;
          break;
        case 3:
          res = lhs->e11111222;
          break;
        case 4:
          res = lhs->e11112222;
          break;
        case 5:
          res = lhs->e11122222;
          break;
        case 6:
          res = lhs->e11222222;
          break;
        case 7:
          res = lhs->e12222222;
          break;
        case 8:
          res = lhs->e22222222;
          break;
      }
      break;
    case 9:
      switch (idx){
        case 0:
          res = lhs->e111111111;
          break;
        case 1:
          res = lhs->e111111112;
          break;
        case 2:
          res = lhs->e111111122;
          break;
        case 3:
          res = lhs->e111111222;
          break;
        case 4:
          res = lhs->e111112222;
          break;
        case 5:
          res = lhs->e111122222;
          break;
        case 6:
          res = lhs->e111222222;
          break;
        case 7:
          res = lhs->e112222222;
          break;
        case 8:
          res = lhs->e122222222;
          break;
        case 9:
          res = lhs->e222222222;
          break;
      }
      break;
  }
  return res;

}

coeff_t onumm2n9_get_deriv(imdir_t idx, ord_t order, onumm2n9_t* lhs){

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
      }
      break;
    case 6:
      switch (idx){
        case 0:
          factor = 7.2000000000000000e+02;
          res = lhs->e111111*factor;
          break;
        case 1:
          factor = 1.2000000000000000e+02;
          res = lhs->e111112*factor;
          break;
        case 2:
          factor = 4.8000000000000000e+01;
          res = lhs->e111122*factor;
          break;
        case 3:
          factor = 3.6000000000000000e+01;
          res = lhs->e111222*factor;
          break;
        case 4:
          factor = 4.8000000000000000e+01;
          res = lhs->e112222*factor;
          break;
        case 5:
          factor = 1.2000000000000000e+02;
          res = lhs->e122222*factor;
          break;
        case 6:
          factor = 7.2000000000000000e+02;
          res = lhs->e222222*factor;
          break;
      }
      break;
    case 7:
      switch (idx){
        case 0:
          factor = 5.0400000000000000e+03;
          res = lhs->e1111111*factor;
          break;
        case 1:
          factor = 7.2000000000000000e+02;
          res = lhs->e1111112*factor;
          break;
        case 2:
          factor = 2.4000000000000000e+02;
          res = lhs->e1111122*factor;
          break;
        case 3:
          factor = 1.4400000000000000e+02;
          res = lhs->e1111222*factor;
          break;
        case 4:
          factor = 1.4400000000000000e+02;
          res = lhs->e1112222*factor;
          break;
        case 5:
          factor = 2.4000000000000000e+02;
          res = lhs->e1122222*factor;
          break;
        case 6:
          factor = 7.2000000000000000e+02;
          res = lhs->e1222222*factor;
          break;
        case 7:
          factor = 5.0400000000000000e+03;
          res = lhs->e2222222*factor;
          break;
      }
      break;
    case 8:
      switch (idx){
        case 0:
          factor = 4.0320000000000000e+04;
          res = lhs->e11111111*factor;
          break;
        case 1:
          factor = 5.0400000000000000e+03;
          res = lhs->e11111112*factor;
          break;
        case 2:
          factor = 1.4400000000000000e+03;
          res = lhs->e11111122*factor;
          break;
        case 3:
          factor = 7.2000000000000000e+02;
          res = lhs->e11111222*factor;
          break;
        case 4:
          factor = 5.7600000000000000e+02;
          res = lhs->e11112222*factor;
          break;
        case 5:
          factor = 7.2000000000000000e+02;
          res = lhs->e11122222*factor;
          break;
        case 6:
          factor = 1.4400000000000000e+03;
          res = lhs->e11222222*factor;
          break;
        case 7:
          factor = 5.0400000000000000e+03;
          res = lhs->e12222222*factor;
          break;
        case 8:
          factor = 4.0320000000000000e+04;
          res = lhs->e22222222*factor;
          break;
      }
      break;
    case 9:
      switch (idx){
        case 0:
          factor = 3.6288000000000000e+05;
          res = lhs->e111111111*factor;
          break;
        case 1:
          factor = 4.0320000000000000e+04;
          res = lhs->e111111112*factor;
          break;
        case 2:
          factor = 1.0080000000000000e+04;
          res = lhs->e111111122*factor;
          break;
        case 3:
          factor = 4.3200000000000000e+03;
          res = lhs->e111111222*factor;
          break;
        case 4:
          factor = 2.8800000000000000e+03;
          res = lhs->e111112222*factor;
          break;
        case 5:
          factor = 2.8800000000000000e+03;
          res = lhs->e111122222*factor;
          break;
        case 6:
          factor = 4.3200000000000000e+03;
          res = lhs->e111222222*factor;
          break;
        case 7:
          factor = 1.0080000000000000e+04;
          res = lhs->e112222222*factor;
          break;
        case 8:
          factor = 4.0320000000000000e+04;
          res = lhs->e122222222*factor;
          break;
        case 9:
          factor = 3.6288000000000000e+05;
          res = lhs->e222222222*factor;
          break;
      }
      break;
  }
  return res;

}

void onumm2n9_set_item(coeff_t val, imdir_t idx, ord_t order, onumm2n9_t* x){

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
      }
      break;
    case 6:
      switch (idx){
        case 0:
          x->e111111 = val;
          break;
        case 1:
          x->e111112 = val;
          break;
        case 2:
          x->e111122 = val;
          break;
        case 3:
          x->e111222 = val;
          break;
        case 4:
          x->e112222 = val;
          break;
        case 5:
          x->e122222 = val;
          break;
        case 6:
          x->e222222 = val;
          break;
      }
      break;
    case 7:
      switch (idx){
        case 0:
          x->e1111111 = val;
          break;
        case 1:
          x->e1111112 = val;
          break;
        case 2:
          x->e1111122 = val;
          break;
        case 3:
          x->e1111222 = val;
          break;
        case 4:
          x->e1112222 = val;
          break;
        case 5:
          x->e1122222 = val;
          break;
        case 6:
          x->e1222222 = val;
          break;
        case 7:
          x->e2222222 = val;
          break;
      }
      break;
    case 8:
      switch (idx){
        case 0:
          x->e11111111 = val;
          break;
        case 1:
          x->e11111112 = val;
          break;
        case 2:
          x->e11111122 = val;
          break;
        case 3:
          x->e11111222 = val;
          break;
        case 4:
          x->e11112222 = val;
          break;
        case 5:
          x->e11122222 = val;
          break;
        case 6:
          x->e11222222 = val;
          break;
        case 7:
          x->e12222222 = val;
          break;
        case 8:
          x->e22222222 = val;
          break;
      }
      break;
    case 9:
      switch (idx){
        case 0:
          x->e111111111 = val;
          break;
        case 1:
          x->e111111112 = val;
          break;
        case 2:
          x->e111111122 = val;
          break;
        case 3:
          x->e111111222 = val;
          break;
        case 4:
          x->e111112222 = val;
          break;
        case 5:
          x->e111122222 = val;
          break;
        case 6:
          x->e111222222 = val;
          break;
        case 7:
          x->e112222222 = val;
          break;
        case 8:
          x->e122222222 = val;
          break;
        case 9:
          x->e222222222 = val;
          break;
      }
      break;
  }
}

onumm2n9_t onumm2n9_copy(  onumm2n9_t* lhs){

  onumm2n9_t res;

  // Assign like function 'lhs'
  // Real;
  res.r = lhs->r;
  // Order 1;
  res.e1 = lhs->e1;
  res.e2 = lhs->e2;
  // Order 2;
  res.e11 = lhs->e11;
  res.e12 = lhs->e12;
  res.e22 = lhs->e22;
  // Order 3;
  res.e111 = lhs->e111;
  res.e112 = lhs->e112;
  res.e122 = lhs->e122;
  res.e222 = lhs->e222;
  // Order 4;
  res.e1111 = lhs->e1111;
  res.e1112 = lhs->e1112;
  res.e1122 = lhs->e1122;
  res.e1222 = lhs->e1222;
  res.e2222 = lhs->e2222;
  // Order 5;
  res.e11111 = lhs->e11111;
  res.e11112 = lhs->e11112;
  res.e11122 = lhs->e11122;
  res.e11222 = lhs->e11222;
  res.e12222 = lhs->e12222;
  res.e22222 = lhs->e22222;
  // Order 6;
  res.e111111 = lhs->e111111;
  res.e111112 = lhs->e111112;
  res.e111122 = lhs->e111122;
  res.e111222 = lhs->e111222;
  res.e112222 = lhs->e112222;
  res.e122222 = lhs->e122222;
  res.e222222 = lhs->e222222;
  // Order 7;
  res.e1111111 = lhs->e1111111;
  res.e1111112 = lhs->e1111112;
  res.e1111122 = lhs->e1111122;
  res.e1111222 = lhs->e1111222;
  res.e1112222 = lhs->e1112222;
  res.e1122222 = lhs->e1122222;
  res.e1222222 = lhs->e1222222;
  res.e2222222 = lhs->e2222222;
  // Order 8;
  res.e11111111 = lhs->e11111111;
  res.e11111112 = lhs->e11111112;
  res.e11111122 = lhs->e11111122;
  res.e11111222 = lhs->e11111222;
  res.e11112222 = lhs->e11112222;
  res.e11122222 = lhs->e11122222;
  res.e11222222 = lhs->e11222222;
  res.e12222222 = lhs->e12222222;
  res.e22222222 = lhs->e22222222;
  // Order 9;
  res.e111111111 = lhs->e111111111;
  res.e111111112 = lhs->e111111112;
  res.e111111122 = lhs->e111111122;
  res.e111111222 = lhs->e111111222;
  res.e111112222 = lhs->e111112222;
  res.e111122222 = lhs->e111122222;
  res.e111222222 = lhs->e111222222;
  res.e112222222 = lhs->e112222222;
  res.e122222222 = lhs->e122222222;
  res.e222222222 = lhs->e222222222;

  return res;

}

void onumm2n9_copy_to(  onumm2n9_t* lhs, onumm2n9_t* res){

  // Assign like function 'lhs'
  // Real;
  res->r = lhs->r;
  // Order 1;
  res->e1 = lhs->e1;
  res->e2 = lhs->e2;
  // Order 2;
  res->e11 = lhs->e11;
  res->e12 = lhs->e12;
  res->e22 = lhs->e22;
  // Order 3;
  res->e111 = lhs->e111;
  res->e112 = lhs->e112;
  res->e122 = lhs->e122;
  res->e222 = lhs->e222;
  // Order 4;
  res->e1111 = lhs->e1111;
  res->e1112 = lhs->e1112;
  res->e1122 = lhs->e1122;
  res->e1222 = lhs->e1222;
  res->e2222 = lhs->e2222;
  // Order 5;
  res->e11111 = lhs->e11111;
  res->e11112 = lhs->e11112;
  res->e11122 = lhs->e11122;
  res->e11222 = lhs->e11222;
  res->e12222 = lhs->e12222;
  res->e22222 = lhs->e22222;
  // Order 6;
  res->e111111 = lhs->e111111;
  res->e111112 = lhs->e111112;
  res->e111122 = lhs->e111122;
  res->e111222 = lhs->e111222;
  res->e112222 = lhs->e112222;
  res->e122222 = lhs->e122222;
  res->e222222 = lhs->e222222;
  // Order 7;
  res->e1111111 = lhs->e1111111;
  res->e1111112 = lhs->e1111112;
  res->e1111122 = lhs->e1111122;
  res->e1111222 = lhs->e1111222;
  res->e1112222 = lhs->e1112222;
  res->e1122222 = lhs->e1122222;
  res->e1222222 = lhs->e1222222;
  res->e2222222 = lhs->e2222222;
  // Order 8;
  res->e11111111 = lhs->e11111111;
  res->e11111112 = lhs->e11111112;
  res->e11111122 = lhs->e11111122;
  res->e11111222 = lhs->e11111222;
  res->e11112222 = lhs->e11112222;
  res->e11122222 = lhs->e11122222;
  res->e11222222 = lhs->e11222222;
  res->e12222222 = lhs->e12222222;
  res->e22222222 = lhs->e22222222;
  // Order 9;
  res->e111111111 = lhs->e111111111;
  res->e111111112 = lhs->e111111112;
  res->e111111122 = lhs->e111111122;
  res->e111111222 = lhs->e111111222;
  res->e111112222 = lhs->e111112222;
  res->e111122222 = lhs->e111122222;
  res->e111222222 = lhs->e111222222;
  res->e112222222 = lhs->e112222222;
  res->e122222222 = lhs->e122222222;
  res->e222222222 = lhs->e222222222;

}

onumm2n9_t onumm2n9_taylor_integrate(coeff_t* deltas,onumm2n9_t* lhs){

  onumm2n9_t res;

  res = onumm2n9_init();
  coeff_t factor;
  // Taylor integration
  // Real;
  res.r = lhs->r;
  // Order 1;
  factor = pow(deltas[0],1)*pow(deltas[1],0);
  res.r += factor*lhs->e1;
  factor = pow(deltas[0],0)*pow(deltas[1],1);
  res.r += factor*lhs->e2;
  // Order 2;
  factor = pow(deltas[0],2)*pow(deltas[1],0);
  res.r += factor*lhs->e11;
  factor = pow(deltas[0],1)*pow(deltas[1],1);
  res.r += factor*lhs->e12;
  factor = pow(deltas[0],0)*pow(deltas[1],2);
  res.r += factor*lhs->e22;
  // Order 3;
  factor = pow(deltas[0],3)*pow(deltas[1],0);
  res.r += factor*lhs->e111;
  factor = pow(deltas[0],2)*pow(deltas[1],1);
  res.r += factor*lhs->e112;
  factor = pow(deltas[0],1)*pow(deltas[1],2);
  res.r += factor*lhs->e122;
  factor = pow(deltas[0],0)*pow(deltas[1],3);
  res.r += factor*lhs->e222;
  // Order 4;
  factor = pow(deltas[0],4)*pow(deltas[1],0);
  res.r += factor*lhs->e1111;
  factor = pow(deltas[0],3)*pow(deltas[1],1);
  res.r += factor*lhs->e1112;
  factor = pow(deltas[0],2)*pow(deltas[1],2);
  res.r += factor*lhs->e1122;
  factor = pow(deltas[0],1)*pow(deltas[1],3);
  res.r += factor*lhs->e1222;
  factor = pow(deltas[0],0)*pow(deltas[1],4);
  res.r += factor*lhs->e2222;
  // Order 5;
  factor = pow(deltas[0],5)*pow(deltas[1],0);
  res.r += factor*lhs->e11111;
  factor = pow(deltas[0],4)*pow(deltas[1],1);
  res.r += factor*lhs->e11112;
  factor = pow(deltas[0],3)*pow(deltas[1],2);
  res.r += factor*lhs->e11122;
  factor = pow(deltas[0],2)*pow(deltas[1],3);
  res.r += factor*lhs->e11222;
  factor = pow(deltas[0],1)*pow(deltas[1],4);
  res.r += factor*lhs->e12222;
  factor = pow(deltas[0],0)*pow(deltas[1],5);
  res.r += factor*lhs->e22222;
  // Order 6;
  factor = pow(deltas[0],6)*pow(deltas[1],0);
  res.r += factor*lhs->e111111;
  factor = pow(deltas[0],5)*pow(deltas[1],1);
  res.r += factor*lhs->e111112;
  factor = pow(deltas[0],4)*pow(deltas[1],2);
  res.r += factor*lhs->e111122;
  factor = pow(deltas[0],3)*pow(deltas[1],3);
  res.r += factor*lhs->e111222;
  factor = pow(deltas[0],2)*pow(deltas[1],4);
  res.r += factor*lhs->e112222;
  factor = pow(deltas[0],1)*pow(deltas[1],5);
  res.r += factor*lhs->e122222;
  factor = pow(deltas[0],0)*pow(deltas[1],6);
  res.r += factor*lhs->e222222;
  // Order 7;
  factor = pow(deltas[0],7)*pow(deltas[1],0);
  res.r += factor*lhs->e1111111;
  factor = pow(deltas[0],6)*pow(deltas[1],1);
  res.r += factor*lhs->e1111112;
  factor = pow(deltas[0],5)*pow(deltas[1],2);
  res.r += factor*lhs->e1111122;
  factor = pow(deltas[0],4)*pow(deltas[1],3);
  res.r += factor*lhs->e1111222;
  factor = pow(deltas[0],3)*pow(deltas[1],4);
  res.r += factor*lhs->e1112222;
  factor = pow(deltas[0],2)*pow(deltas[1],5);
  res.r += factor*lhs->e1122222;
  factor = pow(deltas[0],1)*pow(deltas[1],6);
  res.r += factor*lhs->e1222222;
  factor = pow(deltas[0],0)*pow(deltas[1],7);
  res.r += factor*lhs->e2222222;
  // Order 8;
  factor = pow(deltas[0],8)*pow(deltas[1],0);
  res.r += factor*lhs->e11111111;
  factor = pow(deltas[0],7)*pow(deltas[1],1);
  res.r += factor*lhs->e11111112;
  factor = pow(deltas[0],6)*pow(deltas[1],2);
  res.r += factor*lhs->e11111122;
  factor = pow(deltas[0],5)*pow(deltas[1],3);
  res.r += factor*lhs->e11111222;
  factor = pow(deltas[0],4)*pow(deltas[1],4);
  res.r += factor*lhs->e11112222;
  factor = pow(deltas[0],3)*pow(deltas[1],5);
  res.r += factor*lhs->e11122222;
  factor = pow(deltas[0],2)*pow(deltas[1],6);
  res.r += factor*lhs->e11222222;
  factor = pow(deltas[0],1)*pow(deltas[1],7);
  res.r += factor*lhs->e12222222;
  factor = pow(deltas[0],0)*pow(deltas[1],8);
  res.r += factor*lhs->e22222222;
  // Order 9;
  factor = pow(deltas[0],9)*pow(deltas[1],0);
  res.r += factor*lhs->e111111111;
  factor = pow(deltas[0],8)*pow(deltas[1],1);
  res.r += factor*lhs->e111111112;
  factor = pow(deltas[0],7)*pow(deltas[1],2);
  res.r += factor*lhs->e111111122;
  factor = pow(deltas[0],6)*pow(deltas[1],3);
  res.r += factor*lhs->e111111222;
  factor = pow(deltas[0],5)*pow(deltas[1],4);
  res.r += factor*lhs->e111112222;
  factor = pow(deltas[0],4)*pow(deltas[1],5);
  res.r += factor*lhs->e111122222;
  factor = pow(deltas[0],3)*pow(deltas[1],6);
  res.r += factor*lhs->e111222222;
  factor = pow(deltas[0],2)*pow(deltas[1],7);
  res.r += factor*lhs->e112222222;
  factor = pow(deltas[0],1)*pow(deltas[1],8);
  res.r += factor*lhs->e122222222;
  factor = pow(deltas[0],0)*pow(deltas[1],9);
  res.r += factor*lhs->e222222222;

  return res;

}

void onumm2n9_taylor_integrate_to(coeff_t* deltas,onumm2n9_t* lhs, onumm2n9_t* res){

  *res = onumm2n9_init();
  coeff_t factor;
  // Taylor integration
  // Real;
  res->r = lhs->r;
  // Order 1;
  factor = pow(deltas[0],1)*pow(deltas[1],0);
  res->r += factor*lhs->e1;
  factor = pow(deltas[0],0)*pow(deltas[1],1);
  res->r += factor*lhs->e2;
  // Order 2;
  factor = pow(deltas[0],2)*pow(deltas[1],0);
  res->r += factor*lhs->e11;
  factor = pow(deltas[0],1)*pow(deltas[1],1);
  res->r += factor*lhs->e12;
  factor = pow(deltas[0],0)*pow(deltas[1],2);
  res->r += factor*lhs->e22;
  // Order 3;
  factor = pow(deltas[0],3)*pow(deltas[1],0);
  res->r += factor*lhs->e111;
  factor = pow(deltas[0],2)*pow(deltas[1],1);
  res->r += factor*lhs->e112;
  factor = pow(deltas[0],1)*pow(deltas[1],2);
  res->r += factor*lhs->e122;
  factor = pow(deltas[0],0)*pow(deltas[1],3);
  res->r += factor*lhs->e222;
  // Order 4;
  factor = pow(deltas[0],4)*pow(deltas[1],0);
  res->r += factor*lhs->e1111;
  factor = pow(deltas[0],3)*pow(deltas[1],1);
  res->r += factor*lhs->e1112;
  factor = pow(deltas[0],2)*pow(deltas[1],2);
  res->r += factor*lhs->e1122;
  factor = pow(deltas[0],1)*pow(deltas[1],3);
  res->r += factor*lhs->e1222;
  factor = pow(deltas[0],0)*pow(deltas[1],4);
  res->r += factor*lhs->e2222;
  // Order 5;
  factor = pow(deltas[0],5)*pow(deltas[1],0);
  res->r += factor*lhs->e11111;
  factor = pow(deltas[0],4)*pow(deltas[1],1);
  res->r += factor*lhs->e11112;
  factor = pow(deltas[0],3)*pow(deltas[1],2);
  res->r += factor*lhs->e11122;
  factor = pow(deltas[0],2)*pow(deltas[1],3);
  res->r += factor*lhs->e11222;
  factor = pow(deltas[0],1)*pow(deltas[1],4);
  res->r += factor*lhs->e12222;
  factor = pow(deltas[0],0)*pow(deltas[1],5);
  res->r += factor*lhs->e22222;
  // Order 6;
  factor = pow(deltas[0],6)*pow(deltas[1],0);
  res->r += factor*lhs->e111111;
  factor = pow(deltas[0],5)*pow(deltas[1],1);
  res->r += factor*lhs->e111112;
  factor = pow(deltas[0],4)*pow(deltas[1],2);
  res->r += factor*lhs->e111122;
  factor = pow(deltas[0],3)*pow(deltas[1],3);
  res->r += factor*lhs->e111222;
  factor = pow(deltas[0],2)*pow(deltas[1],4);
  res->r += factor*lhs->e112222;
  factor = pow(deltas[0],1)*pow(deltas[1],5);
  res->r += factor*lhs->e122222;
  factor = pow(deltas[0],0)*pow(deltas[1],6);
  res->r += factor*lhs->e222222;
  // Order 7;
  factor = pow(deltas[0],7)*pow(deltas[1],0);
  res->r += factor*lhs->e1111111;
  factor = pow(deltas[0],6)*pow(deltas[1],1);
  res->r += factor*lhs->e1111112;
  factor = pow(deltas[0],5)*pow(deltas[1],2);
  res->r += factor*lhs->e1111122;
  factor = pow(deltas[0],4)*pow(deltas[1],3);
  res->r += factor*lhs->e1111222;
  factor = pow(deltas[0],3)*pow(deltas[1],4);
  res->r += factor*lhs->e1112222;
  factor = pow(deltas[0],2)*pow(deltas[1],5);
  res->r += factor*lhs->e1122222;
  factor = pow(deltas[0],1)*pow(deltas[1],6);
  res->r += factor*lhs->e1222222;
  factor = pow(deltas[0],0)*pow(deltas[1],7);
  res->r += factor*lhs->e2222222;
  // Order 8;
  factor = pow(deltas[0],8)*pow(deltas[1],0);
  res->r += factor*lhs->e11111111;
  factor = pow(deltas[0],7)*pow(deltas[1],1);
  res->r += factor*lhs->e11111112;
  factor = pow(deltas[0],6)*pow(deltas[1],2);
  res->r += factor*lhs->e11111122;
  factor = pow(deltas[0],5)*pow(deltas[1],3);
  res->r += factor*lhs->e11111222;
  factor = pow(deltas[0],4)*pow(deltas[1],4);
  res->r += factor*lhs->e11112222;
  factor = pow(deltas[0],3)*pow(deltas[1],5);
  res->r += factor*lhs->e11122222;
  factor = pow(deltas[0],2)*pow(deltas[1],6);
  res->r += factor*lhs->e11222222;
  factor = pow(deltas[0],1)*pow(deltas[1],7);
  res->r += factor*lhs->e12222222;
  factor = pow(deltas[0],0)*pow(deltas[1],8);
  res->r += factor*lhs->e22222222;
  // Order 9;
  factor = pow(deltas[0],9)*pow(deltas[1],0);
  res->r += factor*lhs->e111111111;
  factor = pow(deltas[0],8)*pow(deltas[1],1);
  res->r += factor*lhs->e111111112;
  factor = pow(deltas[0],7)*pow(deltas[1],2);
  res->r += factor*lhs->e111111122;
  factor = pow(deltas[0],6)*pow(deltas[1],3);
  res->r += factor*lhs->e111111222;
  factor = pow(deltas[0],5)*pow(deltas[1],4);
  res->r += factor*lhs->e111112222;
  factor = pow(deltas[0],4)*pow(deltas[1],5);
  res->r += factor*lhs->e111122222;
  factor = pow(deltas[0],3)*pow(deltas[1],6);
  res->r += factor*lhs->e111222222;
  factor = pow(deltas[0],2)*pow(deltas[1],7);
  res->r += factor*lhs->e112222222;
  factor = pow(deltas[0],1)*pow(deltas[1],8);
  res->r += factor*lhs->e122222222;
  factor = pow(deltas[0],0)*pow(deltas[1],9);
  res->r += factor*lhs->e222222222;

}

onumm2n9_t onumm2n9_truncate_im(imdir_t idx, ord_t order, onumm2n9_t* lhs){

  onumm2n9_t res;

  // Copy number.
  res = (*lhs);
  // Truncate all other values when necessary.
  // Real;
  switch (order){
    case 0:
      res = onumm2n9_init();
      break;
    case 1:
      switch (idx){
        case 0: //  e1
          res.e1 = 0.0;
          res.e11 = 0.0;
          res.e12 = 0.0;
          res.e111 = 0.0;
          res.e112 = 0.0;
          res.e122 = 0.0;
          res.e1111 = 0.0;
          res.e1112 = 0.0;
          res.e1122 = 0.0;
          res.e1222 = 0.0;
          res.e11111 = 0.0;
          res.e11112 = 0.0;
          res.e11122 = 0.0;
          res.e11222 = 0.0;
          res.e12222 = 0.0;
          res.e111111 = 0.0;
          res.e111112 = 0.0;
          res.e111122 = 0.0;
          res.e111222 = 0.0;
          res.e112222 = 0.0;
          res.e122222 = 0.0;
          res.e1111111 = 0.0;
          res.e1111112 = 0.0;
          res.e1111122 = 0.0;
          res.e1111222 = 0.0;
          res.e1112222 = 0.0;
          res.e1122222 = 0.0;
          res.e1222222 = 0.0;
          res.e11111111 = 0.0;
          res.e11111112 = 0.0;
          res.e11111122 = 0.0;
          res.e11111222 = 0.0;
          res.e11112222 = 0.0;
          res.e11122222 = 0.0;
          res.e11222222 = 0.0;
          res.e12222222 = 0.0;
          res.e111111111 = 0.0;
          res.e111111112 = 0.0;
          res.e111111122 = 0.0;
          res.e111111222 = 0.0;
          res.e111112222 = 0.0;
          res.e111122222 = 0.0;
          res.e111222222 = 0.0;
          res.e112222222 = 0.0;
          res.e122222222 = 0.0;
          break;
        case 1: //  e2
          res.e2 = 0.0;
          res.e12 = 0.0;
          res.e22 = 0.0;
          res.e112 = 0.0;
          res.e122 = 0.0;
          res.e222 = 0.0;
          res.e1112 = 0.0;
          res.e1122 = 0.0;
          res.e1222 = 0.0;
          res.e2222 = 0.0;
          res.e11112 = 0.0;
          res.e11122 = 0.0;
          res.e11222 = 0.0;
          res.e12222 = 0.0;
          res.e22222 = 0.0;
          res.e111112 = 0.0;
          res.e111122 = 0.0;
          res.e111222 = 0.0;
          res.e112222 = 0.0;
          res.e122222 = 0.0;
          res.e222222 = 0.0;
          res.e1111112 = 0.0;
          res.e1111122 = 0.0;
          res.e1111222 = 0.0;
          res.e1112222 = 0.0;
          res.e1122222 = 0.0;
          res.e1222222 = 0.0;
          res.e2222222 = 0.0;
          res.e11111112 = 0.0;
          res.e11111122 = 0.0;
          res.e11111222 = 0.0;
          res.e11112222 = 0.0;
          res.e11122222 = 0.0;
          res.e11222222 = 0.0;
          res.e12222222 = 0.0;
          res.e22222222 = 0.0;
          res.e111111112 = 0.0;
          res.e111111122 = 0.0;
          res.e111111222 = 0.0;
          res.e111112222 = 0.0;
          res.e111122222 = 0.0;
          res.e111222222 = 0.0;
          res.e112222222 = 0.0;
          res.e122222222 = 0.0;
          res.e222222222 = 0.0;
          break;
      }
      break;
    case 2:
      switch (idx){
        case 0: //  e11
          res.e11 = 0.0;
          res.e111 = 0.0;
          res.e112 = 0.0;
          res.e1111 = 0.0;
          res.e1112 = 0.0;
          res.e1122 = 0.0;
          res.e11111 = 0.0;
          res.e11112 = 0.0;
          res.e11122 = 0.0;
          res.e11222 = 0.0;
          res.e111111 = 0.0;
          res.e111112 = 0.0;
          res.e111122 = 0.0;
          res.e111222 = 0.0;
          res.e112222 = 0.0;
          res.e1111111 = 0.0;
          res.e1111112 = 0.0;
          res.e1111122 = 0.0;
          res.e1111222 = 0.0;
          res.e1112222 = 0.0;
          res.e1122222 = 0.0;
          res.e11111111 = 0.0;
          res.e11111112 = 0.0;
          res.e11111122 = 0.0;
          res.e11111222 = 0.0;
          res.e11112222 = 0.0;
          res.e11122222 = 0.0;
          res.e11222222 = 0.0;
          res.e111111111 = 0.0;
          res.e111111112 = 0.0;
          res.e111111122 = 0.0;
          res.e111111222 = 0.0;
          res.e111112222 = 0.0;
          res.e111122222 = 0.0;
          res.e111222222 = 0.0;
          res.e112222222 = 0.0;
          break;
        case 1: //  e12
          res.e12 = 0.0;
          res.e112 = 0.0;
          res.e122 = 0.0;
          res.e1112 = 0.0;
          res.e1122 = 0.0;
          res.e1222 = 0.0;
          res.e11112 = 0.0;
          res.e11122 = 0.0;
          res.e11222 = 0.0;
          res.e12222 = 0.0;
          res.e111112 = 0.0;
          res.e111122 = 0.0;
          res.e111222 = 0.0;
          res.e112222 = 0.0;
          res.e122222 = 0.0;
          res.e1111112 = 0.0;
          res.e1111122 = 0.0;
          res.e1111222 = 0.0;
          res.e1112222 = 0.0;
          res.e1122222 = 0.0;
          res.e1222222 = 0.0;
          res.e11111112 = 0.0;
          res.e11111122 = 0.0;
          res.e11111222 = 0.0;
          res.e11112222 = 0.0;
          res.e11122222 = 0.0;
          res.e11222222 = 0.0;
          res.e12222222 = 0.0;
          res.e111111112 = 0.0;
          res.e111111122 = 0.0;
          res.e111111222 = 0.0;
          res.e111112222 = 0.0;
          res.e111122222 = 0.0;
          res.e111222222 = 0.0;
          res.e112222222 = 0.0;
          res.e122222222 = 0.0;
          break;
        case 2: //  e22
          res.e22 = 0.0;
          res.e122 = 0.0;
          res.e222 = 0.0;
          res.e1122 = 0.0;
          res.e1222 = 0.0;
          res.e2222 = 0.0;
          res.e11122 = 0.0;
          res.e11222 = 0.0;
          res.e12222 = 0.0;
          res.e22222 = 0.0;
          res.e111122 = 0.0;
          res.e111222 = 0.0;
          res.e112222 = 0.0;
          res.e122222 = 0.0;
          res.e222222 = 0.0;
          res.e1111122 = 0.0;
          res.e1111222 = 0.0;
          res.e1112222 = 0.0;
          res.e1122222 = 0.0;
          res.e1222222 = 0.0;
          res.e2222222 = 0.0;
          res.e11111122 = 0.0;
          res.e11111222 = 0.0;
          res.e11112222 = 0.0;
          res.e11122222 = 0.0;
          res.e11222222 = 0.0;
          res.e12222222 = 0.0;
          res.e22222222 = 0.0;
          res.e111111122 = 0.0;
          res.e111111222 = 0.0;
          res.e111112222 = 0.0;
          res.e111122222 = 0.0;
          res.e111222222 = 0.0;
          res.e112222222 = 0.0;
          res.e122222222 = 0.0;
          res.e222222222 = 0.0;
          break;
      }
      break;
    case 3:
      switch (idx){
        case 0: //  e111
          res.e111 = 0.0;
          res.e1111 = 0.0;
          res.e1112 = 0.0;
          res.e11111 = 0.0;
          res.e11112 = 0.0;
          res.e11122 = 0.0;
          res.e111111 = 0.0;
          res.e111112 = 0.0;
          res.e111122 = 0.0;
          res.e111222 = 0.0;
          res.e1111111 = 0.0;
          res.e1111112 = 0.0;
          res.e1111122 = 0.0;
          res.e1111222 = 0.0;
          res.e1112222 = 0.0;
          res.e11111111 = 0.0;
          res.e11111112 = 0.0;
          res.e11111122 = 0.0;
          res.e11111222 = 0.0;
          res.e11112222 = 0.0;
          res.e11122222 = 0.0;
          res.e111111111 = 0.0;
          res.e111111112 = 0.0;
          res.e111111122 = 0.0;
          res.e111111222 = 0.0;
          res.e111112222 = 0.0;
          res.e111122222 = 0.0;
          res.e111222222 = 0.0;
          break;
        case 1: //  e112
          res.e112 = 0.0;
          res.e1112 = 0.0;
          res.e1122 = 0.0;
          res.e11112 = 0.0;
          res.e11122 = 0.0;
          res.e11222 = 0.0;
          res.e111112 = 0.0;
          res.e111122 = 0.0;
          res.e111222 = 0.0;
          res.e112222 = 0.0;
          res.e1111112 = 0.0;
          res.e1111122 = 0.0;
          res.e1111222 = 0.0;
          res.e1112222 = 0.0;
          res.e1122222 = 0.0;
          res.e11111112 = 0.0;
          res.e11111122 = 0.0;
          res.e11111222 = 0.0;
          res.e11112222 = 0.0;
          res.e11122222 = 0.0;
          res.e11222222 = 0.0;
          res.e111111112 = 0.0;
          res.e111111122 = 0.0;
          res.e111111222 = 0.0;
          res.e111112222 = 0.0;
          res.e111122222 = 0.0;
          res.e111222222 = 0.0;
          res.e112222222 = 0.0;
          break;
        case 2: //  e122
          res.e122 = 0.0;
          res.e1122 = 0.0;
          res.e1222 = 0.0;
          res.e11122 = 0.0;
          res.e11222 = 0.0;
          res.e12222 = 0.0;
          res.e111122 = 0.0;
          res.e111222 = 0.0;
          res.e112222 = 0.0;
          res.e122222 = 0.0;
          res.e1111122 = 0.0;
          res.e1111222 = 0.0;
          res.e1112222 = 0.0;
          res.e1122222 = 0.0;
          res.e1222222 = 0.0;
          res.e11111122 = 0.0;
          res.e11111222 = 0.0;
          res.e11112222 = 0.0;
          res.e11122222 = 0.0;
          res.e11222222 = 0.0;
          res.e12222222 = 0.0;
          res.e111111122 = 0.0;
          res.e111111222 = 0.0;
          res.e111112222 = 0.0;
          res.e111122222 = 0.0;
          res.e111222222 = 0.0;
          res.e112222222 = 0.0;
          res.e122222222 = 0.0;
          break;
        case 3: //  e222
          res.e222 = 0.0;
          res.e1222 = 0.0;
          res.e2222 = 0.0;
          res.e11222 = 0.0;
          res.e12222 = 0.0;
          res.e22222 = 0.0;
          res.e111222 = 0.0;
          res.e112222 = 0.0;
          res.e122222 = 0.0;
          res.e222222 = 0.0;
          res.e1111222 = 0.0;
          res.e1112222 = 0.0;
          res.e1122222 = 0.0;
          res.e1222222 = 0.0;
          res.e2222222 = 0.0;
          res.e11111222 = 0.0;
          res.e11112222 = 0.0;
          res.e11122222 = 0.0;
          res.e11222222 = 0.0;
          res.e12222222 = 0.0;
          res.e22222222 = 0.0;
          res.e111111222 = 0.0;
          res.e111112222 = 0.0;
          res.e111122222 = 0.0;
          res.e111222222 = 0.0;
          res.e112222222 = 0.0;
          res.e122222222 = 0.0;
          res.e222222222 = 0.0;
          break;
      }
      break;
    case 4:
      switch (idx){
        case 0: //  e1111
          res.e1111 = 0.0;
          res.e11111 = 0.0;
          res.e11112 = 0.0;
          res.e111111 = 0.0;
          res.e111112 = 0.0;
          res.e111122 = 0.0;
          res.e1111111 = 0.0;
          res.e1111112 = 0.0;
          res.e1111122 = 0.0;
          res.e1111222 = 0.0;
          res.e11111111 = 0.0;
          res.e11111112 = 0.0;
          res.e11111122 = 0.0;
          res.e11111222 = 0.0;
          res.e11112222 = 0.0;
          res.e111111111 = 0.0;
          res.e111111112 = 0.0;
          res.e111111122 = 0.0;
          res.e111111222 = 0.0;
          res.e111112222 = 0.0;
          res.e111122222 = 0.0;
          break;
        case 1: //  e1112
          res.e1112 = 0.0;
          res.e11112 = 0.0;
          res.e11122 = 0.0;
          res.e111112 = 0.0;
          res.e111122 = 0.0;
          res.e111222 = 0.0;
          res.e1111112 = 0.0;
          res.e1111122 = 0.0;
          res.e1111222 = 0.0;
          res.e1112222 = 0.0;
          res.e11111112 = 0.0;
          res.e11111122 = 0.0;
          res.e11111222 = 0.0;
          res.e11112222 = 0.0;
          res.e11122222 = 0.0;
          res.e111111112 = 0.0;
          res.e111111122 = 0.0;
          res.e111111222 = 0.0;
          res.e111112222 = 0.0;
          res.e111122222 = 0.0;
          res.e111222222 = 0.0;
          break;
        case 2: //  e1122
          res.e1122 = 0.0;
          res.e11122 = 0.0;
          res.e11222 = 0.0;
          res.e111122 = 0.0;
          res.e111222 = 0.0;
          res.e112222 = 0.0;
          res.e1111122 = 0.0;
          res.e1111222 = 0.0;
          res.e1112222 = 0.0;
          res.e1122222 = 0.0;
          res.e11111122 = 0.0;
          res.e11111222 = 0.0;
          res.e11112222 = 0.0;
          res.e11122222 = 0.0;
          res.e11222222 = 0.0;
          res.e111111122 = 0.0;
          res.e111111222 = 0.0;
          res.e111112222 = 0.0;
          res.e111122222 = 0.0;
          res.e111222222 = 0.0;
          res.e112222222 = 0.0;
          break;
        case 3: //  e1222
          res.e1222 = 0.0;
          res.e11222 = 0.0;
          res.e12222 = 0.0;
          res.e111222 = 0.0;
          res.e112222 = 0.0;
          res.e122222 = 0.0;
          res.e1111222 = 0.0;
          res.e1112222 = 0.0;
          res.e1122222 = 0.0;
          res.e1222222 = 0.0;
          res.e11111222 = 0.0;
          res.e11112222 = 0.0;
          res.e11122222 = 0.0;
          res.e11222222 = 0.0;
          res.e12222222 = 0.0;
          res.e111111222 = 0.0;
          res.e111112222 = 0.0;
          res.e111122222 = 0.0;
          res.e111222222 = 0.0;
          res.e112222222 = 0.0;
          res.e122222222 = 0.0;
          break;
        case 4: //  e2222
          res.e2222 = 0.0;
          res.e12222 = 0.0;
          res.e22222 = 0.0;
          res.e112222 = 0.0;
          res.e122222 = 0.0;
          res.e222222 = 0.0;
          res.e1112222 = 0.0;
          res.e1122222 = 0.0;
          res.e1222222 = 0.0;
          res.e2222222 = 0.0;
          res.e11112222 = 0.0;
          res.e11122222 = 0.0;
          res.e11222222 = 0.0;
          res.e12222222 = 0.0;
          res.e22222222 = 0.0;
          res.e111112222 = 0.0;
          res.e111122222 = 0.0;
          res.e111222222 = 0.0;
          res.e112222222 = 0.0;
          res.e122222222 = 0.0;
          res.e222222222 = 0.0;
          break;
      }
      break;
    case 5:
      switch (idx){
        case 0: //  e11111
          res.e11111 = 0.0;
          res.e111111 = 0.0;
          res.e111112 = 0.0;
          res.e1111111 = 0.0;
          res.e1111112 = 0.0;
          res.e1111122 = 0.0;
          res.e11111111 = 0.0;
          res.e11111112 = 0.0;
          res.e11111122 = 0.0;
          res.e11111222 = 0.0;
          res.e111111111 = 0.0;
          res.e111111112 = 0.0;
          res.e111111122 = 0.0;
          res.e111111222 = 0.0;
          res.e111112222 = 0.0;
          break;
        case 1: //  e11112
          res.e11112 = 0.0;
          res.e111112 = 0.0;
          res.e111122 = 0.0;
          res.e1111112 = 0.0;
          res.e1111122 = 0.0;
          res.e1111222 = 0.0;
          res.e11111112 = 0.0;
          res.e11111122 = 0.0;
          res.e11111222 = 0.0;
          res.e11112222 = 0.0;
          res.e111111112 = 0.0;
          res.e111111122 = 0.0;
          res.e111111222 = 0.0;
          res.e111112222 = 0.0;
          res.e111122222 = 0.0;
          break;
        case 2: //  e11122
          res.e11122 = 0.0;
          res.e111122 = 0.0;
          res.e111222 = 0.0;
          res.e1111122 = 0.0;
          res.e1111222 = 0.0;
          res.e1112222 = 0.0;
          res.e11111122 = 0.0;
          res.e11111222 = 0.0;
          res.e11112222 = 0.0;
          res.e11122222 = 0.0;
          res.e111111122 = 0.0;
          res.e111111222 = 0.0;
          res.e111112222 = 0.0;
          res.e111122222 = 0.0;
          res.e111222222 = 0.0;
          break;
        case 3: //  e11222
          res.e11222 = 0.0;
          res.e111222 = 0.0;
          res.e112222 = 0.0;
          res.e1111222 = 0.0;
          res.e1112222 = 0.0;
          res.e1122222 = 0.0;
          res.e11111222 = 0.0;
          res.e11112222 = 0.0;
          res.e11122222 = 0.0;
          res.e11222222 = 0.0;
          res.e111111222 = 0.0;
          res.e111112222 = 0.0;
          res.e111122222 = 0.0;
          res.e111222222 = 0.0;
          res.e112222222 = 0.0;
          break;
        case 4: //  e12222
          res.e12222 = 0.0;
          res.e112222 = 0.0;
          res.e122222 = 0.0;
          res.e1112222 = 0.0;
          res.e1122222 = 0.0;
          res.e1222222 = 0.0;
          res.e11112222 = 0.0;
          res.e11122222 = 0.0;
          res.e11222222 = 0.0;
          res.e12222222 = 0.0;
          res.e111112222 = 0.0;
          res.e111122222 = 0.0;
          res.e111222222 = 0.0;
          res.e112222222 = 0.0;
          res.e122222222 = 0.0;
          break;
        case 5: //  e22222
          res.e22222 = 0.0;
          res.e122222 = 0.0;
          res.e222222 = 0.0;
          res.e1122222 = 0.0;
          res.e1222222 = 0.0;
          res.e2222222 = 0.0;
          res.e11122222 = 0.0;
          res.e11222222 = 0.0;
          res.e12222222 = 0.0;
          res.e22222222 = 0.0;
          res.e111122222 = 0.0;
          res.e111222222 = 0.0;
          res.e112222222 = 0.0;
          res.e122222222 = 0.0;
          res.e222222222 = 0.0;
          break;
      }
      break;
    case 6:
      switch (idx){
        case 0: //  e111111
          res.e111111 = 0.0;
          res.e1111111 = 0.0;
          res.e1111112 = 0.0;
          res.e11111111 = 0.0;
          res.e11111112 = 0.0;
          res.e11111122 = 0.0;
          res.e111111111 = 0.0;
          res.e111111112 = 0.0;
          res.e111111122 = 0.0;
          res.e111111222 = 0.0;
          break;
        case 1: //  e111112
          res.e111112 = 0.0;
          res.e1111112 = 0.0;
          res.e1111122 = 0.0;
          res.e11111112 = 0.0;
          res.e11111122 = 0.0;
          res.e11111222 = 0.0;
          res.e111111112 = 0.0;
          res.e111111122 = 0.0;
          res.e111111222 = 0.0;
          res.e111112222 = 0.0;
          break;
        case 2: //  e111122
          res.e111122 = 0.0;
          res.e1111122 = 0.0;
          res.e1111222 = 0.0;
          res.e11111122 = 0.0;
          res.e11111222 = 0.0;
          res.e11112222 = 0.0;
          res.e111111122 = 0.0;
          res.e111111222 = 0.0;
          res.e111112222 = 0.0;
          res.e111122222 = 0.0;
          break;
        case 3: //  e111222
          res.e111222 = 0.0;
          res.e1111222 = 0.0;
          res.e1112222 = 0.0;
          res.e11111222 = 0.0;
          res.e11112222 = 0.0;
          res.e11122222 = 0.0;
          res.e111111222 = 0.0;
          res.e111112222 = 0.0;
          res.e111122222 = 0.0;
          res.e111222222 = 0.0;
          break;
        case 4: //  e112222
          res.e112222 = 0.0;
          res.e1112222 = 0.0;
          res.e1122222 = 0.0;
          res.e11112222 = 0.0;
          res.e11122222 = 0.0;
          res.e11222222 = 0.0;
          res.e111112222 = 0.0;
          res.e111122222 = 0.0;
          res.e111222222 = 0.0;
          res.e112222222 = 0.0;
          break;
        case 5: //  e122222
          res.e122222 = 0.0;
          res.e1122222 = 0.0;
          res.e1222222 = 0.0;
          res.e11122222 = 0.0;
          res.e11222222 = 0.0;
          res.e12222222 = 0.0;
          res.e111122222 = 0.0;
          res.e111222222 = 0.0;
          res.e112222222 = 0.0;
          res.e122222222 = 0.0;
          break;
        case 6: //  e222222
          res.e222222 = 0.0;
          res.e1222222 = 0.0;
          res.e2222222 = 0.0;
          res.e11222222 = 0.0;
          res.e12222222 = 0.0;
          res.e22222222 = 0.0;
          res.e111222222 = 0.0;
          res.e112222222 = 0.0;
          res.e122222222 = 0.0;
          res.e222222222 = 0.0;
          break;
      }
      break;
    case 7:
      switch (idx){
        case 0: //  e1111111
          res.e1111111 = 0.0;
          res.e11111111 = 0.0;
          res.e11111112 = 0.0;
          res.e111111111 = 0.0;
          res.e111111112 = 0.0;
          res.e111111122 = 0.0;
          break;
        case 1: //  e1111112
          res.e1111112 = 0.0;
          res.e11111112 = 0.0;
          res.e11111122 = 0.0;
          res.e111111112 = 0.0;
          res.e111111122 = 0.0;
          res.e111111222 = 0.0;
          break;
        case 2: //  e1111122
          res.e1111122 = 0.0;
          res.e11111122 = 0.0;
          res.e11111222 = 0.0;
          res.e111111122 = 0.0;
          res.e111111222 = 0.0;
          res.e111112222 = 0.0;
          break;
        case 3: //  e1111222
          res.e1111222 = 0.0;
          res.e11111222 = 0.0;
          res.e11112222 = 0.0;
          res.e111111222 = 0.0;
          res.e111112222 = 0.0;
          res.e111122222 = 0.0;
          break;
        case 4: //  e1112222
          res.e1112222 = 0.0;
          res.e11112222 = 0.0;
          res.e11122222 = 0.0;
          res.e111112222 = 0.0;
          res.e111122222 = 0.0;
          res.e111222222 = 0.0;
          break;
        case 5: //  e1122222
          res.e1122222 = 0.0;
          res.e11122222 = 0.0;
          res.e11222222 = 0.0;
          res.e111122222 = 0.0;
          res.e111222222 = 0.0;
          res.e112222222 = 0.0;
          break;
        case 6: //  e1222222
          res.e1222222 = 0.0;
          res.e11222222 = 0.0;
          res.e12222222 = 0.0;
          res.e111222222 = 0.0;
          res.e112222222 = 0.0;
          res.e122222222 = 0.0;
          break;
        case 7: //  e2222222
          res.e2222222 = 0.0;
          res.e12222222 = 0.0;
          res.e22222222 = 0.0;
          res.e112222222 = 0.0;
          res.e122222222 = 0.0;
          res.e222222222 = 0.0;
          break;
      }
      break;
    case 8:
      switch (idx){
        case 0: //  e11111111
          res.e11111111 = 0.0;
          res.e111111111 = 0.0;
          res.e111111112 = 0.0;
          break;
        case 1: //  e11111112
          res.e11111112 = 0.0;
          res.e111111112 = 0.0;
          res.e111111122 = 0.0;
          break;
        case 2: //  e11111122
          res.e11111122 = 0.0;
          res.e111111122 = 0.0;
          res.e111111222 = 0.0;
          break;
        case 3: //  e11111222
          res.e11111222 = 0.0;
          res.e111111222 = 0.0;
          res.e111112222 = 0.0;
          break;
        case 4: //  e11112222
          res.e11112222 = 0.0;
          res.e111112222 = 0.0;
          res.e111122222 = 0.0;
          break;
        case 5: //  e11122222
          res.e11122222 = 0.0;
          res.e111122222 = 0.0;
          res.e111222222 = 0.0;
          break;
        case 6: //  e11222222
          res.e11222222 = 0.0;
          res.e111222222 = 0.0;
          res.e112222222 = 0.0;
          break;
        case 7: //  e12222222
          res.e12222222 = 0.0;
          res.e112222222 = 0.0;
          res.e122222222 = 0.0;
          break;
        case 8: //  e22222222
          res.e22222222 = 0.0;
          res.e122222222 = 0.0;
          res.e222222222 = 0.0;
          break;
      }
      break;
    case 9:
      switch (idx){
        case 0: //  e111111111
          res.e111111111 = 0.0;
          break;
        case 1: //  e111111112
          res.e111111112 = 0.0;
          break;
        case 2: //  e111111122
          res.e111111122 = 0.0;
          break;
        case 3: //  e111111222
          res.e111111222 = 0.0;
          break;
        case 4: //  e111112222
          res.e111112222 = 0.0;
          break;
        case 5: //  e111122222
          res.e111122222 = 0.0;
          break;
        case 6: //  e111222222
          res.e111222222 = 0.0;
          break;
        case 7: //  e112222222
          res.e112222222 = 0.0;
          break;
        case 8: //  e122222222
          res.e122222222 = 0.0;
          break;
        case 9: //  e222222222
          res.e222222222 = 0.0;
          break;
      }
      break;
  }
  return res;

}

void onumm2n9_truncate_im_to(imdir_t idx, ord_t order, onumm2n9_t* lhs, onumm2n9_t* res){

  // Copy number.
  *res = (*lhs);
  // Truncate all other values when necessary.
  // Real;
  switch (order){
    case 0:
      *res = onumm2n9_init();
      break;
    case 1:
      switch (idx){
        case 0: //  e1
          res->e1 = 0.0;
          res->e11 = 0.0;
          res->e12 = 0.0;
          res->e111 = 0.0;
          res->e112 = 0.0;
          res->e122 = 0.0;
          res->e1111 = 0.0;
          res->e1112 = 0.0;
          res->e1122 = 0.0;
          res->e1222 = 0.0;
          res->e11111 = 0.0;
          res->e11112 = 0.0;
          res->e11122 = 0.0;
          res->e11222 = 0.0;
          res->e12222 = 0.0;
          res->e111111 = 0.0;
          res->e111112 = 0.0;
          res->e111122 = 0.0;
          res->e111222 = 0.0;
          res->e112222 = 0.0;
          res->e122222 = 0.0;
          res->e1111111 = 0.0;
          res->e1111112 = 0.0;
          res->e1111122 = 0.0;
          res->e1111222 = 0.0;
          res->e1112222 = 0.0;
          res->e1122222 = 0.0;
          res->e1222222 = 0.0;
          res->e11111111 = 0.0;
          res->e11111112 = 0.0;
          res->e11111122 = 0.0;
          res->e11111222 = 0.0;
          res->e11112222 = 0.0;
          res->e11122222 = 0.0;
          res->e11222222 = 0.0;
          res->e12222222 = 0.0;
          res->e111111111 = 0.0;
          res->e111111112 = 0.0;
          res->e111111122 = 0.0;
          res->e111111222 = 0.0;
          res->e111112222 = 0.0;
          res->e111122222 = 0.0;
          res->e111222222 = 0.0;
          res->e112222222 = 0.0;
          res->e122222222 = 0.0;
          break;
        case 1: //  e2
          res->e2 = 0.0;
          res->e12 = 0.0;
          res->e22 = 0.0;
          res->e112 = 0.0;
          res->e122 = 0.0;
          res->e222 = 0.0;
          res->e1112 = 0.0;
          res->e1122 = 0.0;
          res->e1222 = 0.0;
          res->e2222 = 0.0;
          res->e11112 = 0.0;
          res->e11122 = 0.0;
          res->e11222 = 0.0;
          res->e12222 = 0.0;
          res->e22222 = 0.0;
          res->e111112 = 0.0;
          res->e111122 = 0.0;
          res->e111222 = 0.0;
          res->e112222 = 0.0;
          res->e122222 = 0.0;
          res->e222222 = 0.0;
          res->e1111112 = 0.0;
          res->e1111122 = 0.0;
          res->e1111222 = 0.0;
          res->e1112222 = 0.0;
          res->e1122222 = 0.0;
          res->e1222222 = 0.0;
          res->e2222222 = 0.0;
          res->e11111112 = 0.0;
          res->e11111122 = 0.0;
          res->e11111222 = 0.0;
          res->e11112222 = 0.0;
          res->e11122222 = 0.0;
          res->e11222222 = 0.0;
          res->e12222222 = 0.0;
          res->e22222222 = 0.0;
          res->e111111112 = 0.0;
          res->e111111122 = 0.0;
          res->e111111222 = 0.0;
          res->e111112222 = 0.0;
          res->e111122222 = 0.0;
          res->e111222222 = 0.0;
          res->e112222222 = 0.0;
          res->e122222222 = 0.0;
          res->e222222222 = 0.0;
          break;
      }
      break;
    case 2:
      switch (idx){
        case 0: //  e11
          res->e11 = 0.0;
          res->e111 = 0.0;
          res->e112 = 0.0;
          res->e1111 = 0.0;
          res->e1112 = 0.0;
          res->e1122 = 0.0;
          res->e11111 = 0.0;
          res->e11112 = 0.0;
          res->e11122 = 0.0;
          res->e11222 = 0.0;
          res->e111111 = 0.0;
          res->e111112 = 0.0;
          res->e111122 = 0.0;
          res->e111222 = 0.0;
          res->e112222 = 0.0;
          res->e1111111 = 0.0;
          res->e1111112 = 0.0;
          res->e1111122 = 0.0;
          res->e1111222 = 0.0;
          res->e1112222 = 0.0;
          res->e1122222 = 0.0;
          res->e11111111 = 0.0;
          res->e11111112 = 0.0;
          res->e11111122 = 0.0;
          res->e11111222 = 0.0;
          res->e11112222 = 0.0;
          res->e11122222 = 0.0;
          res->e11222222 = 0.0;
          res->e111111111 = 0.0;
          res->e111111112 = 0.0;
          res->e111111122 = 0.0;
          res->e111111222 = 0.0;
          res->e111112222 = 0.0;
          res->e111122222 = 0.0;
          res->e111222222 = 0.0;
          res->e112222222 = 0.0;
          break;
        case 1: //  e12
          res->e12 = 0.0;
          res->e112 = 0.0;
          res->e122 = 0.0;
          res->e1112 = 0.0;
          res->e1122 = 0.0;
          res->e1222 = 0.0;
          res->e11112 = 0.0;
          res->e11122 = 0.0;
          res->e11222 = 0.0;
          res->e12222 = 0.0;
          res->e111112 = 0.0;
          res->e111122 = 0.0;
          res->e111222 = 0.0;
          res->e112222 = 0.0;
          res->e122222 = 0.0;
          res->e1111112 = 0.0;
          res->e1111122 = 0.0;
          res->e1111222 = 0.0;
          res->e1112222 = 0.0;
          res->e1122222 = 0.0;
          res->e1222222 = 0.0;
          res->e11111112 = 0.0;
          res->e11111122 = 0.0;
          res->e11111222 = 0.0;
          res->e11112222 = 0.0;
          res->e11122222 = 0.0;
          res->e11222222 = 0.0;
          res->e12222222 = 0.0;
          res->e111111112 = 0.0;
          res->e111111122 = 0.0;
          res->e111111222 = 0.0;
          res->e111112222 = 0.0;
          res->e111122222 = 0.0;
          res->e111222222 = 0.0;
          res->e112222222 = 0.0;
          res->e122222222 = 0.0;
          break;
        case 2: //  e22
          res->e22 = 0.0;
          res->e122 = 0.0;
          res->e222 = 0.0;
          res->e1122 = 0.0;
          res->e1222 = 0.0;
          res->e2222 = 0.0;
          res->e11122 = 0.0;
          res->e11222 = 0.0;
          res->e12222 = 0.0;
          res->e22222 = 0.0;
          res->e111122 = 0.0;
          res->e111222 = 0.0;
          res->e112222 = 0.0;
          res->e122222 = 0.0;
          res->e222222 = 0.0;
          res->e1111122 = 0.0;
          res->e1111222 = 0.0;
          res->e1112222 = 0.0;
          res->e1122222 = 0.0;
          res->e1222222 = 0.0;
          res->e2222222 = 0.0;
          res->e11111122 = 0.0;
          res->e11111222 = 0.0;
          res->e11112222 = 0.0;
          res->e11122222 = 0.0;
          res->e11222222 = 0.0;
          res->e12222222 = 0.0;
          res->e22222222 = 0.0;
          res->e111111122 = 0.0;
          res->e111111222 = 0.0;
          res->e111112222 = 0.0;
          res->e111122222 = 0.0;
          res->e111222222 = 0.0;
          res->e112222222 = 0.0;
          res->e122222222 = 0.0;
          res->e222222222 = 0.0;
          break;
      }
      break;
    case 3:
      switch (idx){
        case 0: //  e111
          res->e111 = 0.0;
          res->e1111 = 0.0;
          res->e1112 = 0.0;
          res->e11111 = 0.0;
          res->e11112 = 0.0;
          res->e11122 = 0.0;
          res->e111111 = 0.0;
          res->e111112 = 0.0;
          res->e111122 = 0.0;
          res->e111222 = 0.0;
          res->e1111111 = 0.0;
          res->e1111112 = 0.0;
          res->e1111122 = 0.0;
          res->e1111222 = 0.0;
          res->e1112222 = 0.0;
          res->e11111111 = 0.0;
          res->e11111112 = 0.0;
          res->e11111122 = 0.0;
          res->e11111222 = 0.0;
          res->e11112222 = 0.0;
          res->e11122222 = 0.0;
          res->e111111111 = 0.0;
          res->e111111112 = 0.0;
          res->e111111122 = 0.0;
          res->e111111222 = 0.0;
          res->e111112222 = 0.0;
          res->e111122222 = 0.0;
          res->e111222222 = 0.0;
          break;
        case 1: //  e112
          res->e112 = 0.0;
          res->e1112 = 0.0;
          res->e1122 = 0.0;
          res->e11112 = 0.0;
          res->e11122 = 0.0;
          res->e11222 = 0.0;
          res->e111112 = 0.0;
          res->e111122 = 0.0;
          res->e111222 = 0.0;
          res->e112222 = 0.0;
          res->e1111112 = 0.0;
          res->e1111122 = 0.0;
          res->e1111222 = 0.0;
          res->e1112222 = 0.0;
          res->e1122222 = 0.0;
          res->e11111112 = 0.0;
          res->e11111122 = 0.0;
          res->e11111222 = 0.0;
          res->e11112222 = 0.0;
          res->e11122222 = 0.0;
          res->e11222222 = 0.0;
          res->e111111112 = 0.0;
          res->e111111122 = 0.0;
          res->e111111222 = 0.0;
          res->e111112222 = 0.0;
          res->e111122222 = 0.0;
          res->e111222222 = 0.0;
          res->e112222222 = 0.0;
          break;
        case 2: //  e122
          res->e122 = 0.0;
          res->e1122 = 0.0;
          res->e1222 = 0.0;
          res->e11122 = 0.0;
          res->e11222 = 0.0;
          res->e12222 = 0.0;
          res->e111122 = 0.0;
          res->e111222 = 0.0;
          res->e112222 = 0.0;
          res->e122222 = 0.0;
          res->e1111122 = 0.0;
          res->e1111222 = 0.0;
          res->e1112222 = 0.0;
          res->e1122222 = 0.0;
          res->e1222222 = 0.0;
          res->e11111122 = 0.0;
          res->e11111222 = 0.0;
          res->e11112222 = 0.0;
          res->e11122222 = 0.0;
          res->e11222222 = 0.0;
          res->e12222222 = 0.0;
          res->e111111122 = 0.0;
          res->e111111222 = 0.0;
          res->e111112222 = 0.0;
          res->e111122222 = 0.0;
          res->e111222222 = 0.0;
          res->e112222222 = 0.0;
          res->e122222222 = 0.0;
          break;
        case 3: //  e222
          res->e222 = 0.0;
          res->e1222 = 0.0;
          res->e2222 = 0.0;
          res->e11222 = 0.0;
          res->e12222 = 0.0;
          res->e22222 = 0.0;
          res->e111222 = 0.0;
          res->e112222 = 0.0;
          res->e122222 = 0.0;
          res->e222222 = 0.0;
          res->e1111222 = 0.0;
          res->e1112222 = 0.0;
          res->e1122222 = 0.0;
          res->e1222222 = 0.0;
          res->e2222222 = 0.0;
          res->e11111222 = 0.0;
          res->e11112222 = 0.0;
          res->e11122222 = 0.0;
          res->e11222222 = 0.0;
          res->e12222222 = 0.0;
          res->e22222222 = 0.0;
          res->e111111222 = 0.0;
          res->e111112222 = 0.0;
          res->e111122222 = 0.0;
          res->e111222222 = 0.0;
          res->e112222222 = 0.0;
          res->e122222222 = 0.0;
          res->e222222222 = 0.0;
          break;
      }
      break;
    case 4:
      switch (idx){
        case 0: //  e1111
          res->e1111 = 0.0;
          res->e11111 = 0.0;
          res->e11112 = 0.0;
          res->e111111 = 0.0;
          res->e111112 = 0.0;
          res->e111122 = 0.0;
          res->e1111111 = 0.0;
          res->e1111112 = 0.0;
          res->e1111122 = 0.0;
          res->e1111222 = 0.0;
          res->e11111111 = 0.0;
          res->e11111112 = 0.0;
          res->e11111122 = 0.0;
          res->e11111222 = 0.0;
          res->e11112222 = 0.0;
          res->e111111111 = 0.0;
          res->e111111112 = 0.0;
          res->e111111122 = 0.0;
          res->e111111222 = 0.0;
          res->e111112222 = 0.0;
          res->e111122222 = 0.0;
          break;
        case 1: //  e1112
          res->e1112 = 0.0;
          res->e11112 = 0.0;
          res->e11122 = 0.0;
          res->e111112 = 0.0;
          res->e111122 = 0.0;
          res->e111222 = 0.0;
          res->e1111112 = 0.0;
          res->e1111122 = 0.0;
          res->e1111222 = 0.0;
          res->e1112222 = 0.0;
          res->e11111112 = 0.0;
          res->e11111122 = 0.0;
          res->e11111222 = 0.0;
          res->e11112222 = 0.0;
          res->e11122222 = 0.0;
          res->e111111112 = 0.0;
          res->e111111122 = 0.0;
          res->e111111222 = 0.0;
          res->e111112222 = 0.0;
          res->e111122222 = 0.0;
          res->e111222222 = 0.0;
          break;
        case 2: //  e1122
          res->e1122 = 0.0;
          res->e11122 = 0.0;
          res->e11222 = 0.0;
          res->e111122 = 0.0;
          res->e111222 = 0.0;
          res->e112222 = 0.0;
          res->e1111122 = 0.0;
          res->e1111222 = 0.0;
          res->e1112222 = 0.0;
          res->e1122222 = 0.0;
          res->e11111122 = 0.0;
          res->e11111222 = 0.0;
          res->e11112222 = 0.0;
          res->e11122222 = 0.0;
          res->e11222222 = 0.0;
          res->e111111122 = 0.0;
          res->e111111222 = 0.0;
          res->e111112222 = 0.0;
          res->e111122222 = 0.0;
          res->e111222222 = 0.0;
          res->e112222222 = 0.0;
          break;
        case 3: //  e1222
          res->e1222 = 0.0;
          res->e11222 = 0.0;
          res->e12222 = 0.0;
          res->e111222 = 0.0;
          res->e112222 = 0.0;
          res->e122222 = 0.0;
          res->e1111222 = 0.0;
          res->e1112222 = 0.0;
          res->e1122222 = 0.0;
          res->e1222222 = 0.0;
          res->e11111222 = 0.0;
          res->e11112222 = 0.0;
          res->e11122222 = 0.0;
          res->e11222222 = 0.0;
          res->e12222222 = 0.0;
          res->e111111222 = 0.0;
          res->e111112222 = 0.0;
          res->e111122222 = 0.0;
          res->e111222222 = 0.0;
          res->e112222222 = 0.0;
          res->e122222222 = 0.0;
          break;
        case 4: //  e2222
          res->e2222 = 0.0;
          res->e12222 = 0.0;
          res->e22222 = 0.0;
          res->e112222 = 0.0;
          res->e122222 = 0.0;
          res->e222222 = 0.0;
          res->e1112222 = 0.0;
          res->e1122222 = 0.0;
          res->e1222222 = 0.0;
          res->e2222222 = 0.0;
          res->e11112222 = 0.0;
          res->e11122222 = 0.0;
          res->e11222222 = 0.0;
          res->e12222222 = 0.0;
          res->e22222222 = 0.0;
          res->e111112222 = 0.0;
          res->e111122222 = 0.0;
          res->e111222222 = 0.0;
          res->e112222222 = 0.0;
          res->e122222222 = 0.0;
          res->e222222222 = 0.0;
          break;
      }
      break;
    case 5:
      switch (idx){
        case 0: //  e11111
          res->e11111 = 0.0;
          res->e111111 = 0.0;
          res->e111112 = 0.0;
          res->e1111111 = 0.0;
          res->e1111112 = 0.0;
          res->e1111122 = 0.0;
          res->e11111111 = 0.0;
          res->e11111112 = 0.0;
          res->e11111122 = 0.0;
          res->e11111222 = 0.0;
          res->e111111111 = 0.0;
          res->e111111112 = 0.0;
          res->e111111122 = 0.0;
          res->e111111222 = 0.0;
          res->e111112222 = 0.0;
          break;
        case 1: //  e11112
          res->e11112 = 0.0;
          res->e111112 = 0.0;
          res->e111122 = 0.0;
          res->e1111112 = 0.0;
          res->e1111122 = 0.0;
          res->e1111222 = 0.0;
          res->e11111112 = 0.0;
          res->e11111122 = 0.0;
          res->e11111222 = 0.0;
          res->e11112222 = 0.0;
          res->e111111112 = 0.0;
          res->e111111122 = 0.0;
          res->e111111222 = 0.0;
          res->e111112222 = 0.0;
          res->e111122222 = 0.0;
          break;
        case 2: //  e11122
          res->e11122 = 0.0;
          res->e111122 = 0.0;
          res->e111222 = 0.0;
          res->e1111122 = 0.0;
          res->e1111222 = 0.0;
          res->e1112222 = 0.0;
          res->e11111122 = 0.0;
          res->e11111222 = 0.0;
          res->e11112222 = 0.0;
          res->e11122222 = 0.0;
          res->e111111122 = 0.0;
          res->e111111222 = 0.0;
          res->e111112222 = 0.0;
          res->e111122222 = 0.0;
          res->e111222222 = 0.0;
          break;
        case 3: //  e11222
          res->e11222 = 0.0;
          res->e111222 = 0.0;
          res->e112222 = 0.0;
          res->e1111222 = 0.0;
          res->e1112222 = 0.0;
          res->e1122222 = 0.0;
          res->e11111222 = 0.0;
          res->e11112222 = 0.0;
          res->e11122222 = 0.0;
          res->e11222222 = 0.0;
          res->e111111222 = 0.0;
          res->e111112222 = 0.0;
          res->e111122222 = 0.0;
          res->e111222222 = 0.0;
          res->e112222222 = 0.0;
          break;
        case 4: //  e12222
          res->e12222 = 0.0;
          res->e112222 = 0.0;
          res->e122222 = 0.0;
          res->e1112222 = 0.0;
          res->e1122222 = 0.0;
          res->e1222222 = 0.0;
          res->e11112222 = 0.0;
          res->e11122222 = 0.0;
          res->e11222222 = 0.0;
          res->e12222222 = 0.0;
          res->e111112222 = 0.0;
          res->e111122222 = 0.0;
          res->e111222222 = 0.0;
          res->e112222222 = 0.0;
          res->e122222222 = 0.0;
          break;
        case 5: //  e22222
          res->e22222 = 0.0;
          res->e122222 = 0.0;
          res->e222222 = 0.0;
          res->e1122222 = 0.0;
          res->e1222222 = 0.0;
          res->e2222222 = 0.0;
          res->e11122222 = 0.0;
          res->e11222222 = 0.0;
          res->e12222222 = 0.0;
          res->e22222222 = 0.0;
          res->e111122222 = 0.0;
          res->e111222222 = 0.0;
          res->e112222222 = 0.0;
          res->e122222222 = 0.0;
          res->e222222222 = 0.0;
          break;
      }
      break;
    case 6:
      switch (idx){
        case 0: //  e111111
          res->e111111 = 0.0;
          res->e1111111 = 0.0;
          res->e1111112 = 0.0;
          res->e11111111 = 0.0;
          res->e11111112 = 0.0;
          res->e11111122 = 0.0;
          res->e111111111 = 0.0;
          res->e111111112 = 0.0;
          res->e111111122 = 0.0;
          res->e111111222 = 0.0;
          break;
        case 1: //  e111112
          res->e111112 = 0.0;
          res->e1111112 = 0.0;
          res->e1111122 = 0.0;
          res->e11111112 = 0.0;
          res->e11111122 = 0.0;
          res->e11111222 = 0.0;
          res->e111111112 = 0.0;
          res->e111111122 = 0.0;
          res->e111111222 = 0.0;
          res->e111112222 = 0.0;
          break;
        case 2: //  e111122
          res->e111122 = 0.0;
          res->e1111122 = 0.0;
          res->e1111222 = 0.0;
          res->e11111122 = 0.0;
          res->e11111222 = 0.0;
          res->e11112222 = 0.0;
          res->e111111122 = 0.0;
          res->e111111222 = 0.0;
          res->e111112222 = 0.0;
          res->e111122222 = 0.0;
          break;
        case 3: //  e111222
          res->e111222 = 0.0;
          res->e1111222 = 0.0;
          res->e1112222 = 0.0;
          res->e11111222 = 0.0;
          res->e11112222 = 0.0;
          res->e11122222 = 0.0;
          res->e111111222 = 0.0;
          res->e111112222 = 0.0;
          res->e111122222 = 0.0;
          res->e111222222 = 0.0;
          break;
        case 4: //  e112222
          res->e112222 = 0.0;
          res->e1112222 = 0.0;
          res->e1122222 = 0.0;
          res->e11112222 = 0.0;
          res->e11122222 = 0.0;
          res->e11222222 = 0.0;
          res->e111112222 = 0.0;
          res->e111122222 = 0.0;
          res->e111222222 = 0.0;
          res->e112222222 = 0.0;
          break;
        case 5: //  e122222
          res->e122222 = 0.0;
          res->e1122222 = 0.0;
          res->e1222222 = 0.0;
          res->e11122222 = 0.0;
          res->e11222222 = 0.0;
          res->e12222222 = 0.0;
          res->e111122222 = 0.0;
          res->e111222222 = 0.0;
          res->e112222222 = 0.0;
          res->e122222222 = 0.0;
          break;
        case 6: //  e222222
          res->e222222 = 0.0;
          res->e1222222 = 0.0;
          res->e2222222 = 0.0;
          res->e11222222 = 0.0;
          res->e12222222 = 0.0;
          res->e22222222 = 0.0;
          res->e111222222 = 0.0;
          res->e112222222 = 0.0;
          res->e122222222 = 0.0;
          res->e222222222 = 0.0;
          break;
      }
      break;
    case 7:
      switch (idx){
        case 0: //  e1111111
          res->e1111111 = 0.0;
          res->e11111111 = 0.0;
          res->e11111112 = 0.0;
          res->e111111111 = 0.0;
          res->e111111112 = 0.0;
          res->e111111122 = 0.0;
          break;
        case 1: //  e1111112
          res->e1111112 = 0.0;
          res->e11111112 = 0.0;
          res->e11111122 = 0.0;
          res->e111111112 = 0.0;
          res->e111111122 = 0.0;
          res->e111111222 = 0.0;
          break;
        case 2: //  e1111122
          res->e1111122 = 0.0;
          res->e11111122 = 0.0;
          res->e11111222 = 0.0;
          res->e111111122 = 0.0;
          res->e111111222 = 0.0;
          res->e111112222 = 0.0;
          break;
        case 3: //  e1111222
          res->e1111222 = 0.0;
          res->e11111222 = 0.0;
          res->e11112222 = 0.0;
          res->e111111222 = 0.0;
          res->e111112222 = 0.0;
          res->e111122222 = 0.0;
          break;
        case 4: //  e1112222
          res->e1112222 = 0.0;
          res->e11112222 = 0.0;
          res->e11122222 = 0.0;
          res->e111112222 = 0.0;
          res->e111122222 = 0.0;
          res->e111222222 = 0.0;
          break;
        case 5: //  e1122222
          res->e1122222 = 0.0;
          res->e11122222 = 0.0;
          res->e11222222 = 0.0;
          res->e111122222 = 0.0;
          res->e111222222 = 0.0;
          res->e112222222 = 0.0;
          break;
        case 6: //  e1222222
          res->e1222222 = 0.0;
          res->e11222222 = 0.0;
          res->e12222222 = 0.0;
          res->e111222222 = 0.0;
          res->e112222222 = 0.0;
          res->e122222222 = 0.0;
          break;
        case 7: //  e2222222
          res->e2222222 = 0.0;
          res->e12222222 = 0.0;
          res->e22222222 = 0.0;
          res->e112222222 = 0.0;
          res->e122222222 = 0.0;
          res->e222222222 = 0.0;
          break;
      }
      break;
    case 8:
      switch (idx){
        case 0: //  e11111111
          res->e11111111 = 0.0;
          res->e111111111 = 0.0;
          res->e111111112 = 0.0;
          break;
        case 1: //  e11111112
          res->e11111112 = 0.0;
          res->e111111112 = 0.0;
          res->e111111122 = 0.0;
          break;
        case 2: //  e11111122
          res->e11111122 = 0.0;
          res->e111111122 = 0.0;
          res->e111111222 = 0.0;
          break;
        case 3: //  e11111222
          res->e11111222 = 0.0;
          res->e111111222 = 0.0;
          res->e111112222 = 0.0;
          break;
        case 4: //  e11112222
          res->e11112222 = 0.0;
          res->e111112222 = 0.0;
          res->e111122222 = 0.0;
          break;
        case 5: //  e11122222
          res->e11122222 = 0.0;
          res->e111122222 = 0.0;
          res->e111222222 = 0.0;
          break;
        case 6: //  e11222222
          res->e11222222 = 0.0;
          res->e111222222 = 0.0;
          res->e112222222 = 0.0;
          break;
        case 7: //  e12222222
          res->e12222222 = 0.0;
          res->e112222222 = 0.0;
          res->e122222222 = 0.0;
          break;
        case 8: //  e22222222
          res->e22222222 = 0.0;
          res->e122222222 = 0.0;
          res->e222222222 = 0.0;
          break;
      }
      break;
    case 9:
      switch (idx){
        case 0: //  e111111111
          res->e111111111 = 0.0;
          break;
        case 1: //  e111111112
          res->e111111112 = 0.0;
          break;
        case 2: //  e111111122
          res->e111111122 = 0.0;
          break;
        case 3: //  e111111222
          res->e111111222 = 0.0;
          break;
        case 4: //  e111112222
          res->e111112222 = 0.0;
          break;
        case 5: //  e111122222
          res->e111122222 = 0.0;
          break;
        case 6: //  e111222222
          res->e111222222 = 0.0;
          break;
        case 7: //  e112222222
          res->e112222222 = 0.0;
          break;
        case 8: //  e122222222
          res->e122222222 = 0.0;
          break;
        case 9: //  e222222222
          res->e222222222 = 0.0;
          break;
      }
      break;
  }
}

void onumm2n9_print(  onumm2n9_t* lhs){

  // Print function.
  //  Real;
  printf("%.8g",lhs->r);
  //  Order 1;
  printf(" %+.8g*e1",lhs->e1);
  printf(" %+.8g*e2",lhs->e2);
  //  Order 2;
  printf(" %+.8g*e11",lhs->e11);
  printf(" %+.8g*e12",lhs->e12);
  printf(" %+.8g*e22",lhs->e22);
  //  Order 3;
  printf(" %+.8g*e111",lhs->e111);
  printf(" %+.8g*e112",lhs->e112);
  printf(" %+.8g*e122",lhs->e122);
  printf(" %+.8g*e222",lhs->e222);
  //  Order 4;
  printf(" %+.8g*e1111",lhs->e1111);
  printf(" %+.8g*e1112",lhs->e1112);
  printf(" %+.8g*e1122",lhs->e1122);
  printf(" %+.8g*e1222",lhs->e1222);
  printf(" %+.8g*e2222",lhs->e2222);
  //  Order 5;
  printf(" %+.8g*e11111",lhs->e11111);
  printf(" %+.8g*e11112",lhs->e11112);
  printf(" %+.8g*e11122",lhs->e11122);
  printf(" %+.8g*e11222",lhs->e11222);
  printf(" %+.8g*e12222",lhs->e12222);
  printf(" %+.8g*e22222",lhs->e22222);
  //  Order 6;
  printf(" %+.8g*e111111",lhs->e111111);
  printf(" %+.8g*e111112",lhs->e111112);
  printf(" %+.8g*e111122",lhs->e111122);
  printf(" %+.8g*e111222",lhs->e111222);
  printf(" %+.8g*e112222",lhs->e112222);
  printf(" %+.8g*e122222",lhs->e122222);
  printf(" %+.8g*e222222",lhs->e222222);
  //  Order 7;
  printf(" %+.8g*e1111111",lhs->e1111111);
  printf(" %+.8g*e1111112",lhs->e1111112);
  printf(" %+.8g*e1111122",lhs->e1111122);
  printf(" %+.8g*e1111222",lhs->e1111222);
  printf(" %+.8g*e1112222",lhs->e1112222);
  printf(" %+.8g*e1122222",lhs->e1122222);
  printf(" %+.8g*e1222222",lhs->e1222222);
  printf(" %+.8g*e2222222",lhs->e2222222);
  //  Order 8;
  printf(" %+.8g*e11111111",lhs->e11111111);
  printf(" %+.8g*e11111112",lhs->e11111112);
  printf(" %+.8g*e11111122",lhs->e11111122);
  printf(" %+.8g*e11111222",lhs->e11111222);
  printf(" %+.8g*e11112222",lhs->e11112222);
  printf(" %+.8g*e11122222",lhs->e11122222);
  printf(" %+.8g*e11222222",lhs->e11222222);
  printf(" %+.8g*e12222222",lhs->e12222222);
  printf(" %+.8g*e22222222",lhs->e22222222);
  //  Order 9;
  printf(" %+.8g*e111111111",lhs->e111111111);
  printf(" %+.8g*e111111112",lhs->e111111112);
  printf(" %+.8g*e111111122",lhs->e111111122);
  printf(" %+.8g*e111111222",lhs->e111111222);
  printf(" %+.8g*e111112222",lhs->e111112222);
  printf(" %+.8g*e111122222",lhs->e111122222);
  printf(" %+.8g*e111222222",lhs->e111222222);
  printf(" %+.8g*e112222222",lhs->e112222222);
  printf(" %+.8g*e122222222",lhs->e122222222);
  printf(" %+.8g*e222222222",lhs->e222222222);
  printf("\n");

}

imdir_t onumm2n9_get_indx(imdir_t idx, ord_t order){

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
      }
      break;
    case 6:
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
      }
      break;
    case 7:
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
      }
      break;
    case 8:
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
      }
      break;
    case 9:
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
      default:
          return 0;
  }
  return 0;
}

