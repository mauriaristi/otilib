

// Not implemented correctly:
void onumm1n30_set_im_o(onumm1n30_t* num, imdir_t idx, ord_t order, onumm1n30_t* res){
    onumm1n30_set_item(num->r,idx,order,res);
}
void onumm1n30_set_deriv_r(coeff_t num, imdir_t idx, ord_t order, onumm1n30_t* res){
    *res=onumm1n30_init();
}
void onumm1n30_set_deriv_o(onumm1n30_t* num, imdir_t idx, ord_t order, onumm1n30_t* res){
    *res=onumm1n30_init();
}
void onumm1n30_extract_im_to( imdir_t idx, ord_t order, onumm1n30_t* num, onumm1n30_t* res){
    *res=onumm1n30_init();
}
onumm1n30_t onumm1n30_extract_im(imdir_t idx, ord_t order, onumm1n30_t* num){
    onumm1n30_t res = onumm1n30_init();
    return res;
}
onumm1n30_t onumm1n30_extract_deriv(imdir_t idx, ord_t order, onumm1n30_t* num){
    onumm1n30_t res = onumm1n30_init();
    return res;
}
void onumm1n30_extract_deriv_to(imdir_t idx, ord_t order, onumm1n30_t* num, onumm1n30_t* res){
	*res = onumm1n30_init();
}
void onumm1n30_get_im_to_o(imdir_t idx, ord_t order, onumm1n30_t* num, onumm1n30_t* res){
    coeff_t rres = onumm1n30_get_item(idx, order, num);
    onumm1n30_set_r(rres,res);
}
onumm1n30_t onumm1n30_get_im_o(imdir_t idx, ord_t order, onumm1n30_t* num){
    coeff_t rres = onumm1n30_get_item(idx, order, num);
    onumm1n30_t res;
    onumm1n30_set_r(rres,&res);
    return res;
}
void onumm1n30_get_im_to_r(imdir_t idx, ord_t order, onumm1n30_t* num, coeff_t* res){
    *res = onumm1n30_get_item(idx, order, num);
}

inline ord_t onumm1n30_get_order(onumm1n30_t* lhs){

	return 30;

}

onumm1n30_t onumm1n30_get_deriv_o( imdir_t idx, ord_t order, onumm1n30_t* num){

    onumm1n30_t res = onumm1n30_init();

    onumm1n30_get_deriv_to( idx, order, num, &res);
    
    return res;

}

void onumm1n30_get_deriv_to( imdir_t idx, ord_t order, onumm1n30_t* num, onumm1n30_t* res){

    coeff_t deriv = onumm1n30_get_deriv(idx,order,num);

    onumm1n30_set_r( deriv, res);

}

void onumm1n30_set_im_r(coeff_t num, imdir_t idx, ord_t order, onumm1n30_t* res){

    onumm1n30_set_item(num, idx,order,res);

}

onumm1n30_t onumm1n30_init(void){

  onumm1n30_t res;

  // Init function
  // Real;
  res.r = 0.0;
  // Order 1;
  res.e1 = 0.0;
  // Order 2;
  res.e11 = 0.0;
  // Order 3;
  res.e111 = 0.0;
  // Order 4;
  res.e1111 = 0.0;
  // Order 5;
  res.e11111 = 0.0;
  // Order 6;
  res.e111111 = 0.0;
  // Order 7;
  res.e1111111 = 0.0;
  // Order 8;
  res.e11111111 = 0.0;
  // Order 9;
  res.e111111111 = 0.0;
  // Order 10;
  res.e1111111111 = 0.0;
  // Order 11;
  res.e11111111111 = 0.0;
  // Order 12;
  res.e111111111111 = 0.0;
  // Order 13;
  res.e1111111111111 = 0.0;
  // Order 14;
  res.e11111111111111 = 0.0;
  // Order 15;
  res.e111111111111111 = 0.0;
  // Order 16;
  res.e1111111111111111 = 0.0;
  // Order 17;
  res.e11111111111111111 = 0.0;
  // Order 18;
  res.e111111111111111111 = 0.0;
  // Order 19;
  res.e1111111111111111111 = 0.0;
  // Order 20;
  res.e11111111111111111111 = 0.0;
  // Order 21;
  res.e111111111111111111111 = 0.0;
  // Order 22;
  res.e1111111111111111111111 = 0.0;
  // Order 23;
  res.e11111111111111111111111 = 0.0;
  // Order 24;
  res.e111111111111111111111111 = 0.0;
  // Order 25;
  res.e1111111111111111111111111 = 0.0;
  // Order 26;
  res.e11111111111111111111111111 = 0.0;
  // Order 27;
  res.e111111111111111111111111111 = 0.0;
  // Order 28;
  res.e1111111111111111111111111111 = 0.0;
  // Order 29;
  res.e11111111111111111111111111111 = 0.0;
  // Order 30;
  res.e111111111111111111111111111111 = 0.0;

  return res;

}

ndir_t onumm1n30_get_ndir_order(ord_t order, onumm1n30_t* num){

  ndir_t res;

  switch(order){
    case 0:
      res = 1;
      break;
    case 1:
      res = 1;
      break;
    case 2:
      res = 1;
      break;
    case 3:
      res = 1;
      break;
    case 4:
      res = 1;
      break;
    case 5:
      res = 1;
      break;
    case 6:
      res = 1;
      break;
    case 7:
      res = 1;
      break;
    case 8:
      res = 1;
      break;
    case 9:
      res = 1;
      break;
    case 10:
      res = 1;
      break;
    case 11:
      res = 1;
      break;
    case 12:
      res = 1;
      break;
    case 13:
      res = 1;
      break;
    case 14:
      res = 1;
      break;
    case 15:
      res = 1;
      break;
    case 16:
      res = 1;
      break;
    case 17:
      res = 1;
      break;
    case 18:
      res = 1;
      break;
    case 19:
      res = 1;
      break;
    case 20:
      res = 1;
      break;
    case 21:
      res = 1;
      break;
    case 22:
      res = 1;
      break;
    case 23:
      res = 1;
      break;
    case 24:
      res = 1;
      break;
    case 25:
      res = 1;
      break;
    case 26:
      res = 1;
      break;
    case 27:
      res = 1;
      break;
    case 28:
      res = 1;
      break;
    case 29:
      res = 1;
      break;
    case 30:
      res = 1;
      break;
  }

  return res;

}

ndir_t onumm1n30_get_ndir_total(onumm1n30_t* num){

  ndir_t res;

  res = 30;

  return res;

}

coeff_t* onumm1n30_get_order_address(ord_t order, onumm1n30_t* num){

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
    case 10:
      res = &num->e1111111111;
      break;
    case 11:
      res = &num->e11111111111;
      break;
    case 12:
      res = &num->e111111111111;
      break;
    case 13:
      res = &num->e1111111111111;
      break;
    case 14:
      res = &num->e11111111111111;
      break;
    case 15:
      res = &num->e111111111111111;
      break;
    case 16:
      res = &num->e1111111111111111;
      break;
    case 17:
      res = &num->e11111111111111111;
      break;
    case 18:
      res = &num->e111111111111111111;
      break;
    case 19:
      res = &num->e1111111111111111111;
      break;
    case 20:
      res = &num->e11111111111111111111;
      break;
    case 21:
      res = &num->e111111111111111111111;
      break;
    case 22:
      res = &num->e1111111111111111111111;
      break;
    case 23:
      res = &num->e11111111111111111111111;
      break;
    case 24:
      res = &num->e111111111111111111111111;
      break;
    case 25:
      res = &num->e1111111111111111111111111;
      break;
    case 26:
      res = &num->e11111111111111111111111111;
      break;
    case 27:
      res = &num->e111111111111111111111111111;
      break;
    case 28:
      res = &num->e1111111111111111111111111111;
      break;
    case 29:
      res = &num->e11111111111111111111111111111;
      break;
    case 30:
      res = &num->e111111111111111111111111111111;
      break;
  }
  return res;

}

onumm1n30_t onumm1n30_create_r(  coeff_t lhs){

  onumm1n30_t res;

  // Assign like function 'lhs'
  // Real;
  res.r = lhs;
  // Order 1;
  res.e1 = 0.0;
  // Order 2;
  res.e11 = 0.0;
  // Order 3;
  res.e111 = 0.0;
  // Order 4;
  res.e1111 = 0.0;
  // Order 5;
  res.e11111 = 0.0;
  // Order 6;
  res.e111111 = 0.0;
  // Order 7;
  res.e1111111 = 0.0;
  // Order 8;
  res.e11111111 = 0.0;
  // Order 9;
  res.e111111111 = 0.0;
  // Order 10;
  res.e1111111111 = 0.0;
  // Order 11;
  res.e11111111111 = 0.0;
  // Order 12;
  res.e111111111111 = 0.0;
  // Order 13;
  res.e1111111111111 = 0.0;
  // Order 14;
  res.e11111111111111 = 0.0;
  // Order 15;
  res.e111111111111111 = 0.0;
  // Order 16;
  res.e1111111111111111 = 0.0;
  // Order 17;
  res.e11111111111111111 = 0.0;
  // Order 18;
  res.e111111111111111111 = 0.0;
  // Order 19;
  res.e1111111111111111111 = 0.0;
  // Order 20;
  res.e11111111111111111111 = 0.0;
  // Order 21;
  res.e111111111111111111111 = 0.0;
  // Order 22;
  res.e1111111111111111111111 = 0.0;
  // Order 23;
  res.e11111111111111111111111 = 0.0;
  // Order 24;
  res.e111111111111111111111111 = 0.0;
  // Order 25;
  res.e1111111111111111111111111 = 0.0;
  // Order 26;
  res.e11111111111111111111111111 = 0.0;
  // Order 27;
  res.e111111111111111111111111111 = 0.0;
  // Order 28;
  res.e1111111111111111111111111111 = 0.0;
  // Order 29;
  res.e11111111111111111111111111111 = 0.0;
  // Order 30;
  res.e111111111111111111111111111111 = 0.0;

  return res;

}

void onumm1n30_set_r(  coeff_t lhs, onumm1n30_t* res){

  // Assign like function 'lhs'
  // Real;
  res->r = lhs;
  // Order 1;
  res->e1 = 0.0;
  // Order 2;
  res->e11 = 0.0;
  // Order 3;
  res->e111 = 0.0;
  // Order 4;
  res->e1111 = 0.0;
  // Order 5;
  res->e11111 = 0.0;
  // Order 6;
  res->e111111 = 0.0;
  // Order 7;
  res->e1111111 = 0.0;
  // Order 8;
  res->e11111111 = 0.0;
  // Order 9;
  res->e111111111 = 0.0;
  // Order 10;
  res->e1111111111 = 0.0;
  // Order 11;
  res->e11111111111 = 0.0;
  // Order 12;
  res->e111111111111 = 0.0;
  // Order 13;
  res->e1111111111111 = 0.0;
  // Order 14;
  res->e11111111111111 = 0.0;
  // Order 15;
  res->e111111111111111 = 0.0;
  // Order 16;
  res->e1111111111111111 = 0.0;
  // Order 17;
  res->e11111111111111111 = 0.0;
  // Order 18;
  res->e111111111111111111 = 0.0;
  // Order 19;
  res->e1111111111111111111 = 0.0;
  // Order 20;
  res->e11111111111111111111 = 0.0;
  // Order 21;
  res->e111111111111111111111 = 0.0;
  // Order 22;
  res->e1111111111111111111111 = 0.0;
  // Order 23;
  res->e11111111111111111111111 = 0.0;
  // Order 24;
  res->e111111111111111111111111 = 0.0;
  // Order 25;
  res->e1111111111111111111111111 = 0.0;
  // Order 26;
  res->e11111111111111111111111111 = 0.0;
  // Order 27;
  res->e111111111111111111111111111 = 0.0;
  // Order 28;
  res->e1111111111111111111111111111 = 0.0;
  // Order 29;
  res->e11111111111111111111111111111 = 0.0;
  // Order 30;
  res->e111111111111111111111111111111 = 0.0;

}

void onumm1n30_set_o(  onumm1n30_t* lhs, onumm1n30_t* res){

  // Assign like function 'lhs'
  // Real;
  res->r = lhs->r;
  // Order 1;
  res->e1 = lhs->e1;
  // Order 2;
  res->e11 = lhs->e11;
  // Order 3;
  res->e111 = lhs->e111;
  // Order 4;
  res->e1111 = lhs->e1111;
  // Order 5;
  res->e11111 = lhs->e11111;
  // Order 6;
  res->e111111 = lhs->e111111;
  // Order 7;
  res->e1111111 = lhs->e1111111;
  // Order 8;
  res->e11111111 = lhs->e11111111;
  // Order 9;
  res->e111111111 = lhs->e111111111;
  // Order 10;
  res->e1111111111 = lhs->e1111111111;
  // Order 11;
  res->e11111111111 = lhs->e11111111111;
  // Order 12;
  res->e111111111111 = lhs->e111111111111;
  // Order 13;
  res->e1111111111111 = lhs->e1111111111111;
  // Order 14;
  res->e11111111111111 = lhs->e11111111111111;
  // Order 15;
  res->e111111111111111 = lhs->e111111111111111;
  // Order 16;
  res->e1111111111111111 = lhs->e1111111111111111;
  // Order 17;
  res->e11111111111111111 = lhs->e11111111111111111;
  // Order 18;
  res->e111111111111111111 = lhs->e111111111111111111;
  // Order 19;
  res->e1111111111111111111 = lhs->e1111111111111111111;
  // Order 20;
  res->e11111111111111111111 = lhs->e11111111111111111111;
  // Order 21;
  res->e111111111111111111111 = lhs->e111111111111111111111;
  // Order 22;
  res->e1111111111111111111111 = lhs->e1111111111111111111111;
  // Order 23;
  res->e11111111111111111111111 = lhs->e11111111111111111111111;
  // Order 24;
  res->e111111111111111111111111 = lhs->e111111111111111111111111;
  // Order 25;
  res->e1111111111111111111111111 = lhs->e1111111111111111111111111;
  // Order 26;
  res->e11111111111111111111111111 = lhs->e11111111111111111111111111;
  // Order 27;
  res->e111111111111111111111111111 = lhs->e111111111111111111111111111;
  // Order 28;
  res->e1111111111111111111111111111 = lhs->e1111111111111111111111111111;
  // Order 29;
  res->e11111111111111111111111111111 = lhs->e11111111111111111111111111111;
  // Order 30;
  res->e111111111111111111111111111111 = lhs->e111111111111111111111111111111;

}

onumm1n30_t onumm1n30_get_order_im(ord_t order, onumm1n30_t* lhs){

  onumm1n30_t res;

  res = onumm1n30_init();
  switch( order ){
    case 0:
      // Assign like function 'lhs'
      // Real;
      res.r = lhs->r;
      break;
    case 1:
      // Order 1;
      res.e1 = lhs->e1;
      break;
    case 2:
      // Order 2;
      res.e11 = lhs->e11;
      break;
    case 3:
      // Order 3;
      res.e111 = lhs->e111;
      break;
    case 4:
      // Order 4;
      res.e1111 = lhs->e1111;
      break;
    case 5:
      // Order 5;
      res.e11111 = lhs->e11111;
      break;
    case 6:
      // Order 6;
      res.e111111 = lhs->e111111;
      break;
    case 7:
      // Order 7;
      res.e1111111 = lhs->e1111111;
      break;
    case 8:
      // Order 8;
      res.e11111111 = lhs->e11111111;
      break;
    case 9:
      // Order 9;
      res.e111111111 = lhs->e111111111;
      break;
    case 10:
      // Order 10;
      res.e1111111111 = lhs->e1111111111;
      break;
    case 11:
      // Order 11;
      res.e11111111111 = lhs->e11111111111;
      break;
    case 12:
      // Order 12;
      res.e111111111111 = lhs->e111111111111;
      break;
    case 13:
      // Order 13;
      res.e1111111111111 = lhs->e1111111111111;
      break;
    case 14:
      // Order 14;
      res.e11111111111111 = lhs->e11111111111111;
      break;
    case 15:
      // Order 15;
      res.e111111111111111 = lhs->e111111111111111;
      break;
    case 16:
      // Order 16;
      res.e1111111111111111 = lhs->e1111111111111111;
      break;
    case 17:
      // Order 17;
      res.e11111111111111111 = lhs->e11111111111111111;
      break;
    case 18:
      // Order 18;
      res.e111111111111111111 = lhs->e111111111111111111;
      break;
    case 19:
      // Order 19;
      res.e1111111111111111111 = lhs->e1111111111111111111;
      break;
    case 20:
      // Order 20;
      res.e11111111111111111111 = lhs->e11111111111111111111;
      break;
    case 21:
      // Order 21;
      res.e111111111111111111111 = lhs->e111111111111111111111;
      break;
    case 22:
      // Order 22;
      res.e1111111111111111111111 = lhs->e1111111111111111111111;
      break;
    case 23:
      // Order 23;
      res.e11111111111111111111111 = lhs->e11111111111111111111111;
      break;
    case 24:
      // Order 24;
      res.e111111111111111111111111 = lhs->e111111111111111111111111;
      break;
    case 25:
      // Order 25;
      res.e1111111111111111111111111 = lhs->e1111111111111111111111111;
      break;
    case 26:
      // Order 26;
      res.e11111111111111111111111111 = lhs->e11111111111111111111111111;
      break;
    case 27:
      // Order 27;
      res.e111111111111111111111111111 = lhs->e111111111111111111111111111;
      break;
    case 28:
      // Order 28;
      res.e1111111111111111111111111111 = lhs->e1111111111111111111111111111;
      break;
    case 29:
      // Order 29;
      res.e11111111111111111111111111111 = lhs->e11111111111111111111111111111;
      break;
    case 30:
      // Order 30;
      res.e111111111111111111111111111111 = lhs->e111111111111111111111111111111;
      break;
  }

  return res;

}

void onumm1n30_get_order_im_to(ord_t order, onumm1n30_t* lhs, onumm1n30_t* res){


  *res = onumm1n30_init();
  switch( order ){
    case 0:
      // Assign like function 'lhs'
      // Real;
      res->r = lhs->r;
      break;
    case 1:
      // Order 1;
      res->e1 = lhs->e1;
      break;
    case 2:
      // Order 2;
      res->e11 = lhs->e11;
      break;
    case 3:
      // Order 3;
      res->e111 = lhs->e111;
      break;
    case 4:
      // Order 4;
      res->e1111 = lhs->e1111;
      break;
    case 5:
      // Order 5;
      res->e11111 = lhs->e11111;
      break;
    case 6:
      // Order 6;
      res->e111111 = lhs->e111111;
      break;
    case 7:
      // Order 7;
      res->e1111111 = lhs->e1111111;
      break;
    case 8:
      // Order 8;
      res->e11111111 = lhs->e11111111;
      break;
    case 9:
      // Order 9;
      res->e111111111 = lhs->e111111111;
      break;
    case 10:
      // Order 10;
      res->e1111111111 = lhs->e1111111111;
      break;
    case 11:
      // Order 11;
      res->e11111111111 = lhs->e11111111111;
      break;
    case 12:
      // Order 12;
      res->e111111111111 = lhs->e111111111111;
      break;
    case 13:
      // Order 13;
      res->e1111111111111 = lhs->e1111111111111;
      break;
    case 14:
      // Order 14;
      res->e11111111111111 = lhs->e11111111111111;
      break;
    case 15:
      // Order 15;
      res->e111111111111111 = lhs->e111111111111111;
      break;
    case 16:
      // Order 16;
      res->e1111111111111111 = lhs->e1111111111111111;
      break;
    case 17:
      // Order 17;
      res->e11111111111111111 = lhs->e11111111111111111;
      break;
    case 18:
      // Order 18;
      res->e111111111111111111 = lhs->e111111111111111111;
      break;
    case 19:
      // Order 19;
      res->e1111111111111111111 = lhs->e1111111111111111111;
      break;
    case 20:
      // Order 20;
      res->e11111111111111111111 = lhs->e11111111111111111111;
      break;
    case 21:
      // Order 21;
      res->e111111111111111111111 = lhs->e111111111111111111111;
      break;
    case 22:
      // Order 22;
      res->e1111111111111111111111 = lhs->e1111111111111111111111;
      break;
    case 23:
      // Order 23;
      res->e11111111111111111111111 = lhs->e11111111111111111111111;
      break;
    case 24:
      // Order 24;
      res->e111111111111111111111111 = lhs->e111111111111111111111111;
      break;
    case 25:
      // Order 25;
      res->e1111111111111111111111111 = lhs->e1111111111111111111111111;
      break;
    case 26:
      // Order 26;
      res->e11111111111111111111111111 = lhs->e11111111111111111111111111;
      break;
    case 27:
      // Order 27;
      res->e111111111111111111111111111 = lhs->e111111111111111111111111111;
      break;
    case 28:
      // Order 28;
      res->e1111111111111111111111111111 = lhs->e1111111111111111111111111111;
      break;
    case 29:
      // Order 29;
      res->e11111111111111111111111111111 = lhs->e11111111111111111111111111111;
      break;
    case 30:
      // Order 30;
      res->e111111111111111111111111111111 = lhs->e111111111111111111111111111111;
      break;
  }

}

coeff_t onumm1n30_get_item(imdir_t idx, ord_t order, onumm1n30_t* lhs){

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
      }
      break;
    case 2:
      switch (idx){
        case 0:
          res = lhs->e11;
          break;
      }
      break;
    case 3:
      switch (idx){
        case 0:
          res = lhs->e111;
          break;
      }
      break;
    case 4:
      switch (idx){
        case 0:
          res = lhs->e1111;
          break;
      }
      break;
    case 5:
      switch (idx){
        case 0:
          res = lhs->e11111;
          break;
      }
      break;
    case 6:
      switch (idx){
        case 0:
          res = lhs->e111111;
          break;
      }
      break;
    case 7:
      switch (idx){
        case 0:
          res = lhs->e1111111;
          break;
      }
      break;
    case 8:
      switch (idx){
        case 0:
          res = lhs->e11111111;
          break;
      }
      break;
    case 9:
      switch (idx){
        case 0:
          res = lhs->e111111111;
          break;
      }
      break;
    case 10:
      switch (idx){
        case 0:
          res = lhs->e1111111111;
          break;
      }
      break;
    case 11:
      switch (idx){
        case 0:
          res = lhs->e11111111111;
          break;
      }
      break;
    case 12:
      switch (idx){
        case 0:
          res = lhs->e111111111111;
          break;
      }
      break;
    case 13:
      switch (idx){
        case 0:
          res = lhs->e1111111111111;
          break;
      }
      break;
    case 14:
      switch (idx){
        case 0:
          res = lhs->e11111111111111;
          break;
      }
      break;
    case 15:
      switch (idx){
        case 0:
          res = lhs->e111111111111111;
          break;
      }
      break;
    case 16:
      switch (idx){
        case 0:
          res = lhs->e1111111111111111;
          break;
      }
      break;
    case 17:
      switch (idx){
        case 0:
          res = lhs->e11111111111111111;
          break;
      }
      break;
    case 18:
      switch (idx){
        case 0:
          res = lhs->e111111111111111111;
          break;
      }
      break;
    case 19:
      switch (idx){
        case 0:
          res = lhs->e1111111111111111111;
          break;
      }
      break;
    case 20:
      switch (idx){
        case 0:
          res = lhs->e11111111111111111111;
          break;
      }
      break;
    case 21:
      switch (idx){
        case 0:
          res = lhs->e111111111111111111111;
          break;
      }
      break;
    case 22:
      switch (idx){
        case 0:
          res = lhs->e1111111111111111111111;
          break;
      }
      break;
    case 23:
      switch (idx){
        case 0:
          res = lhs->e11111111111111111111111;
          break;
      }
      break;
    case 24:
      switch (idx){
        case 0:
          res = lhs->e111111111111111111111111;
          break;
      }
      break;
    case 25:
      switch (idx){
        case 0:
          res = lhs->e1111111111111111111111111;
          break;
      }
      break;
    case 26:
      switch (idx){
        case 0:
          res = lhs->e11111111111111111111111111;
          break;
      }
      break;
    case 27:
      switch (idx){
        case 0:
          res = lhs->e111111111111111111111111111;
          break;
      }
      break;
    case 28:
      switch (idx){
        case 0:
          res = lhs->e1111111111111111111111111111;
          break;
      }
      break;
    case 29:
      switch (idx){
        case 0:
          res = lhs->e11111111111111111111111111111;
          break;
      }
      break;
    case 30:
      switch (idx){
        case 0:
          res = lhs->e111111111111111111111111111111;
          break;
      }
      break;
  }
  return res;

}

coeff_t onumm1n30_get_deriv(imdir_t idx, ord_t order, onumm1n30_t* lhs){

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
      }
      break;
    case 2:
      switch (idx){
        case 0:
          factor = 2.0000000000000000e+00;
          res = lhs->e11*factor;
          break;
      }
      break;
    case 3:
      switch (idx){
        case 0:
          factor = 6.0000000000000000e+00;
          res = lhs->e111*factor;
          break;
      }
      break;
    case 4:
      switch (idx){
        case 0:
          factor = 2.4000000000000000e+01;
          res = lhs->e1111*factor;
          break;
      }
      break;
    case 5:
      switch (idx){
        case 0:
          factor = 1.2000000000000000e+02;
          res = lhs->e11111*factor;
          break;
      }
      break;
    case 6:
      switch (idx){
        case 0:
          factor = 7.2000000000000000e+02;
          res = lhs->e111111*factor;
          break;
      }
      break;
    case 7:
      switch (idx){
        case 0:
          factor = 5.0400000000000000e+03;
          res = lhs->e1111111*factor;
          break;
      }
      break;
    case 8:
      switch (idx){
        case 0:
          factor = 4.0320000000000000e+04;
          res = lhs->e11111111*factor;
          break;
      }
      break;
    case 9:
      switch (idx){
        case 0:
          factor = 3.6288000000000000e+05;
          res = lhs->e111111111*factor;
          break;
      }
      break;
    case 10:
      switch (idx){
        case 0:
          factor = 3.6288000000000000e+06;
          res = lhs->e1111111111*factor;
          break;
      }
      break;
    case 11:
      switch (idx){
        case 0:
          factor = 3.9916800000000000e+07;
          res = lhs->e11111111111*factor;
          break;
      }
      break;
    case 12:
      switch (idx){
        case 0:
          factor = 4.7900160000000000e+08;
          res = lhs->e111111111111*factor;
          break;
      }
      break;
    case 13:
      switch (idx){
        case 0:
          factor = 6.2270208000000000e+09;
          res = lhs->e1111111111111*factor;
          break;
      }
      break;
    case 14:
      switch (idx){
        case 0:
          factor = 8.7178291200000000e+10;
          res = lhs->e11111111111111*factor;
          break;
      }
      break;
    case 15:
      switch (idx){
        case 0:
          factor = 1.3076743680000000e+12;
          res = lhs->e111111111111111*factor;
          break;
      }
      break;
    case 16:
      switch (idx){
        case 0:
          factor = 2.0922789888000000e+13;
          res = lhs->e1111111111111111*factor;
          break;
      }
      break;
    case 17:
      switch (idx){
        case 0:
          factor = 3.5568742809600000e+14;
          res = lhs->e11111111111111111*factor;
          break;
      }
      break;
    case 18:
      switch (idx){
        case 0:
          factor = 6.4023737057280000e+15;
          res = lhs->e111111111111111111*factor;
          break;
      }
      break;
    case 19:
      switch (idx){
        case 0:
          factor = 1.2164510040883200e+17;
          res = lhs->e1111111111111111111*factor;
          break;
      }
      break;
    case 20:
      switch (idx){
        case 0:
          factor = 2.4329020081766400e+18;
          res = lhs->e11111111111111111111*factor;
          break;
      }
      break;
    case 21:
      switch (idx){
        case 0:
          factor = 5.1090942171709440e+19;
          res = lhs->e111111111111111111111*factor;
          break;
      }
      break;
    case 22:
      switch (idx){
        case 0:
          factor = 1.1240007277776077e+21;
          res = lhs->e1111111111111111111111*factor;
          break;
      }
      break;
    case 23:
      switch (idx){
        case 0:
          factor = 2.5852016738884978e+22;
          res = lhs->e11111111111111111111111*factor;
          break;
      }
      break;
    case 24:
      switch (idx){
        case 0:
          factor = 6.2044840173323941e+23;
          res = lhs->e111111111111111111111111*factor;
          break;
      }
      break;
    case 25:
      switch (idx){
        case 0:
          factor = 1.5511210043330986e+25;
          res = lhs->e1111111111111111111111111*factor;
          break;
      }
      break;
    case 26:
      switch (idx){
        case 0:
          factor = 4.0329146112660565e+26;
          res = lhs->e11111111111111111111111111*factor;
          break;
      }
      break;
    case 27:
      switch (idx){
        case 0:
          factor = 1.0888869450418352e+28;
          res = lhs->e111111111111111111111111111*factor;
          break;
      }
      break;
    case 28:
      switch (idx){
        case 0:
          factor = 3.0488834461171384e+29;
          res = lhs->e1111111111111111111111111111*factor;
          break;
      }
      break;
    case 29:
      switch (idx){
        case 0:
          factor = 8.8417619937397008e+30;
          res = lhs->e11111111111111111111111111111*factor;
          break;
      }
      break;
    case 30:
      switch (idx){
        case 0:
          factor = 2.6525285981219103e+32;
          res = lhs->e111111111111111111111111111111*factor;
          break;
      }
      break;
  }
  return res;

}

void onumm1n30_set_item(coeff_t val, imdir_t idx, ord_t order, onumm1n30_t* x){

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
      }
      break;
    case 2:
      switch (idx){
        case 0:
          x->e11 = val;
          break;
      }
      break;
    case 3:
      switch (idx){
        case 0:
          x->e111 = val;
          break;
      }
      break;
    case 4:
      switch (idx){
        case 0:
          x->e1111 = val;
          break;
      }
      break;
    case 5:
      switch (idx){
        case 0:
          x->e11111 = val;
          break;
      }
      break;
    case 6:
      switch (idx){
        case 0:
          x->e111111 = val;
          break;
      }
      break;
    case 7:
      switch (idx){
        case 0:
          x->e1111111 = val;
          break;
      }
      break;
    case 8:
      switch (idx){
        case 0:
          x->e11111111 = val;
          break;
      }
      break;
    case 9:
      switch (idx){
        case 0:
          x->e111111111 = val;
          break;
      }
      break;
    case 10:
      switch (idx){
        case 0:
          x->e1111111111 = val;
          break;
      }
      break;
    case 11:
      switch (idx){
        case 0:
          x->e11111111111 = val;
          break;
      }
      break;
    case 12:
      switch (idx){
        case 0:
          x->e111111111111 = val;
          break;
      }
      break;
    case 13:
      switch (idx){
        case 0:
          x->e1111111111111 = val;
          break;
      }
      break;
    case 14:
      switch (idx){
        case 0:
          x->e11111111111111 = val;
          break;
      }
      break;
    case 15:
      switch (idx){
        case 0:
          x->e111111111111111 = val;
          break;
      }
      break;
    case 16:
      switch (idx){
        case 0:
          x->e1111111111111111 = val;
          break;
      }
      break;
    case 17:
      switch (idx){
        case 0:
          x->e11111111111111111 = val;
          break;
      }
      break;
    case 18:
      switch (idx){
        case 0:
          x->e111111111111111111 = val;
          break;
      }
      break;
    case 19:
      switch (idx){
        case 0:
          x->e1111111111111111111 = val;
          break;
      }
      break;
    case 20:
      switch (idx){
        case 0:
          x->e11111111111111111111 = val;
          break;
      }
      break;
    case 21:
      switch (idx){
        case 0:
          x->e111111111111111111111 = val;
          break;
      }
      break;
    case 22:
      switch (idx){
        case 0:
          x->e1111111111111111111111 = val;
          break;
      }
      break;
    case 23:
      switch (idx){
        case 0:
          x->e11111111111111111111111 = val;
          break;
      }
      break;
    case 24:
      switch (idx){
        case 0:
          x->e111111111111111111111111 = val;
          break;
      }
      break;
    case 25:
      switch (idx){
        case 0:
          x->e1111111111111111111111111 = val;
          break;
      }
      break;
    case 26:
      switch (idx){
        case 0:
          x->e11111111111111111111111111 = val;
          break;
      }
      break;
    case 27:
      switch (idx){
        case 0:
          x->e111111111111111111111111111 = val;
          break;
      }
      break;
    case 28:
      switch (idx){
        case 0:
          x->e1111111111111111111111111111 = val;
          break;
      }
      break;
    case 29:
      switch (idx){
        case 0:
          x->e11111111111111111111111111111 = val;
          break;
      }
      break;
    case 30:
      switch (idx){
        case 0:
          x->e111111111111111111111111111111 = val;
          break;
      }
      break;
  }
}

onumm1n30_t onumm1n30_copy(  onumm1n30_t* lhs){

  onumm1n30_t res;

  // Assign like function 'lhs'
  // Real;
  res.r = lhs->r;
  // Order 1;
  res.e1 = lhs->e1;
  // Order 2;
  res.e11 = lhs->e11;
  // Order 3;
  res.e111 = lhs->e111;
  // Order 4;
  res.e1111 = lhs->e1111;
  // Order 5;
  res.e11111 = lhs->e11111;
  // Order 6;
  res.e111111 = lhs->e111111;
  // Order 7;
  res.e1111111 = lhs->e1111111;
  // Order 8;
  res.e11111111 = lhs->e11111111;
  // Order 9;
  res.e111111111 = lhs->e111111111;
  // Order 10;
  res.e1111111111 = lhs->e1111111111;
  // Order 11;
  res.e11111111111 = lhs->e11111111111;
  // Order 12;
  res.e111111111111 = lhs->e111111111111;
  // Order 13;
  res.e1111111111111 = lhs->e1111111111111;
  // Order 14;
  res.e11111111111111 = lhs->e11111111111111;
  // Order 15;
  res.e111111111111111 = lhs->e111111111111111;
  // Order 16;
  res.e1111111111111111 = lhs->e1111111111111111;
  // Order 17;
  res.e11111111111111111 = lhs->e11111111111111111;
  // Order 18;
  res.e111111111111111111 = lhs->e111111111111111111;
  // Order 19;
  res.e1111111111111111111 = lhs->e1111111111111111111;
  // Order 20;
  res.e11111111111111111111 = lhs->e11111111111111111111;
  // Order 21;
  res.e111111111111111111111 = lhs->e111111111111111111111;
  // Order 22;
  res.e1111111111111111111111 = lhs->e1111111111111111111111;
  // Order 23;
  res.e11111111111111111111111 = lhs->e11111111111111111111111;
  // Order 24;
  res.e111111111111111111111111 = lhs->e111111111111111111111111;
  // Order 25;
  res.e1111111111111111111111111 = lhs->e1111111111111111111111111;
  // Order 26;
  res.e11111111111111111111111111 = lhs->e11111111111111111111111111;
  // Order 27;
  res.e111111111111111111111111111 = lhs->e111111111111111111111111111;
  // Order 28;
  res.e1111111111111111111111111111 = lhs->e1111111111111111111111111111;
  // Order 29;
  res.e11111111111111111111111111111 = lhs->e11111111111111111111111111111;
  // Order 30;
  res.e111111111111111111111111111111 = lhs->e111111111111111111111111111111;

  return res;

}

void onumm1n30_copy_to(  onumm1n30_t* lhs, onumm1n30_t* res){

  // Assign like function 'lhs'
  // Real;
  res->r = lhs->r;
  // Order 1;
  res->e1 = lhs->e1;
  // Order 2;
  res->e11 = lhs->e11;
  // Order 3;
  res->e111 = lhs->e111;
  // Order 4;
  res->e1111 = lhs->e1111;
  // Order 5;
  res->e11111 = lhs->e11111;
  // Order 6;
  res->e111111 = lhs->e111111;
  // Order 7;
  res->e1111111 = lhs->e1111111;
  // Order 8;
  res->e11111111 = lhs->e11111111;
  // Order 9;
  res->e111111111 = lhs->e111111111;
  // Order 10;
  res->e1111111111 = lhs->e1111111111;
  // Order 11;
  res->e11111111111 = lhs->e11111111111;
  // Order 12;
  res->e111111111111 = lhs->e111111111111;
  // Order 13;
  res->e1111111111111 = lhs->e1111111111111;
  // Order 14;
  res->e11111111111111 = lhs->e11111111111111;
  // Order 15;
  res->e111111111111111 = lhs->e111111111111111;
  // Order 16;
  res->e1111111111111111 = lhs->e1111111111111111;
  // Order 17;
  res->e11111111111111111 = lhs->e11111111111111111;
  // Order 18;
  res->e111111111111111111 = lhs->e111111111111111111;
  // Order 19;
  res->e1111111111111111111 = lhs->e1111111111111111111;
  // Order 20;
  res->e11111111111111111111 = lhs->e11111111111111111111;
  // Order 21;
  res->e111111111111111111111 = lhs->e111111111111111111111;
  // Order 22;
  res->e1111111111111111111111 = lhs->e1111111111111111111111;
  // Order 23;
  res->e11111111111111111111111 = lhs->e11111111111111111111111;
  // Order 24;
  res->e111111111111111111111111 = lhs->e111111111111111111111111;
  // Order 25;
  res->e1111111111111111111111111 = lhs->e1111111111111111111111111;
  // Order 26;
  res->e11111111111111111111111111 = lhs->e11111111111111111111111111;
  // Order 27;
  res->e111111111111111111111111111 = lhs->e111111111111111111111111111;
  // Order 28;
  res->e1111111111111111111111111111 = lhs->e1111111111111111111111111111;
  // Order 29;
  res->e11111111111111111111111111111 = lhs->e11111111111111111111111111111;
  // Order 30;
  res->e111111111111111111111111111111 = lhs->e111111111111111111111111111111;

}

onumm1n30_t onumm1n30_taylor_integrate(coeff_t* deltas,onumm1n30_t* lhs){

  onumm1n30_t res;

  res = onumm1n30_init();
  coeff_t factor;
  // Taylor integration
  // Real;
  res.r = lhs->r;
  // Order 1;
  factor = pow(deltas[0],1);
  res.r += factor*lhs->e1;
  // Order 2;
  factor = pow(deltas[0],2);
  res.r += factor*lhs->e11;
  // Order 3;
  factor = pow(deltas[0],3);
  res.r += factor*lhs->e111;
  // Order 4;
  factor = pow(deltas[0],4);
  res.r += factor*lhs->e1111;
  // Order 5;
  factor = pow(deltas[0],5);
  res.r += factor*lhs->e11111;
  // Order 6;
  factor = pow(deltas[0],6);
  res.r += factor*lhs->e111111;
  // Order 7;
  factor = pow(deltas[0],7);
  res.r += factor*lhs->e1111111;
  // Order 8;
  factor = pow(deltas[0],8);
  res.r += factor*lhs->e11111111;
  // Order 9;
  factor = pow(deltas[0],9);
  res.r += factor*lhs->e111111111;
  // Order 10;
  factor = pow(deltas[0],10);
  res.r += factor*lhs->e1111111111;
  // Order 11;
  factor = pow(deltas[0],11);
  res.r += factor*lhs->e11111111111;
  // Order 12;
  factor = pow(deltas[0],12);
  res.r += factor*lhs->e111111111111;
  // Order 13;
  factor = pow(deltas[0],13);
  res.r += factor*lhs->e1111111111111;
  // Order 14;
  factor = pow(deltas[0],14);
  res.r += factor*lhs->e11111111111111;
  // Order 15;
  factor = pow(deltas[0],15);
  res.r += factor*lhs->e111111111111111;
  // Order 16;
  factor = pow(deltas[0],16);
  res.r += factor*lhs->e1111111111111111;
  // Order 17;
  factor = pow(deltas[0],17);
  res.r += factor*lhs->e11111111111111111;
  // Order 18;
  factor = pow(deltas[0],18);
  res.r += factor*lhs->e111111111111111111;
  // Order 19;
  factor = pow(deltas[0],19);
  res.r += factor*lhs->e1111111111111111111;
  // Order 20;
  factor = pow(deltas[0],20);
  res.r += factor*lhs->e11111111111111111111;
  // Order 21;
  factor = pow(deltas[0],21);
  res.r += factor*lhs->e111111111111111111111;
  // Order 22;
  factor = pow(deltas[0],22);
  res.r += factor*lhs->e1111111111111111111111;
  // Order 23;
  factor = pow(deltas[0],23);
  res.r += factor*lhs->e11111111111111111111111;
  // Order 24;
  factor = pow(deltas[0],24);
  res.r += factor*lhs->e111111111111111111111111;
  // Order 25;
  factor = pow(deltas[0],25);
  res.r += factor*lhs->e1111111111111111111111111;
  // Order 26;
  factor = pow(deltas[0],26);
  res.r += factor*lhs->e11111111111111111111111111;
  // Order 27;
  factor = pow(deltas[0],27);
  res.r += factor*lhs->e111111111111111111111111111;
  // Order 28;
  factor = pow(deltas[0],28);
  res.r += factor*lhs->e1111111111111111111111111111;
  // Order 29;
  factor = pow(deltas[0],29);
  res.r += factor*lhs->e11111111111111111111111111111;
  // Order 30;
  factor = pow(deltas[0],30);
  res.r += factor*lhs->e111111111111111111111111111111;

  return res;

}

void onumm1n30_taylor_integrate_to(coeff_t* deltas,onumm1n30_t* lhs, onumm1n30_t* res){

  *res = onumm1n30_init();
  coeff_t factor;
  // Taylor integration
  // Real;
  res->r = lhs->r;
  // Order 1;
  factor = pow(deltas[0],1);
  res->r += factor*lhs->e1;
  // Order 2;
  factor = pow(deltas[0],2);
  res->r += factor*lhs->e11;
  // Order 3;
  factor = pow(deltas[0],3);
  res->r += factor*lhs->e111;
  // Order 4;
  factor = pow(deltas[0],4);
  res->r += factor*lhs->e1111;
  // Order 5;
  factor = pow(deltas[0],5);
  res->r += factor*lhs->e11111;
  // Order 6;
  factor = pow(deltas[0],6);
  res->r += factor*lhs->e111111;
  // Order 7;
  factor = pow(deltas[0],7);
  res->r += factor*lhs->e1111111;
  // Order 8;
  factor = pow(deltas[0],8);
  res->r += factor*lhs->e11111111;
  // Order 9;
  factor = pow(deltas[0],9);
  res->r += factor*lhs->e111111111;
  // Order 10;
  factor = pow(deltas[0],10);
  res->r += factor*lhs->e1111111111;
  // Order 11;
  factor = pow(deltas[0],11);
  res->r += factor*lhs->e11111111111;
  // Order 12;
  factor = pow(deltas[0],12);
  res->r += factor*lhs->e111111111111;
  // Order 13;
  factor = pow(deltas[0],13);
  res->r += factor*lhs->e1111111111111;
  // Order 14;
  factor = pow(deltas[0],14);
  res->r += factor*lhs->e11111111111111;
  // Order 15;
  factor = pow(deltas[0],15);
  res->r += factor*lhs->e111111111111111;
  // Order 16;
  factor = pow(deltas[0],16);
  res->r += factor*lhs->e1111111111111111;
  // Order 17;
  factor = pow(deltas[0],17);
  res->r += factor*lhs->e11111111111111111;
  // Order 18;
  factor = pow(deltas[0],18);
  res->r += factor*lhs->e111111111111111111;
  // Order 19;
  factor = pow(deltas[0],19);
  res->r += factor*lhs->e1111111111111111111;
  // Order 20;
  factor = pow(deltas[0],20);
  res->r += factor*lhs->e11111111111111111111;
  // Order 21;
  factor = pow(deltas[0],21);
  res->r += factor*lhs->e111111111111111111111;
  // Order 22;
  factor = pow(deltas[0],22);
  res->r += factor*lhs->e1111111111111111111111;
  // Order 23;
  factor = pow(deltas[0],23);
  res->r += factor*lhs->e11111111111111111111111;
  // Order 24;
  factor = pow(deltas[0],24);
  res->r += factor*lhs->e111111111111111111111111;
  // Order 25;
  factor = pow(deltas[0],25);
  res->r += factor*lhs->e1111111111111111111111111;
  // Order 26;
  factor = pow(deltas[0],26);
  res->r += factor*lhs->e11111111111111111111111111;
  // Order 27;
  factor = pow(deltas[0],27);
  res->r += factor*lhs->e111111111111111111111111111;
  // Order 28;
  factor = pow(deltas[0],28);
  res->r += factor*lhs->e1111111111111111111111111111;
  // Order 29;
  factor = pow(deltas[0],29);
  res->r += factor*lhs->e11111111111111111111111111111;
  // Order 30;
  factor = pow(deltas[0],30);
  res->r += factor*lhs->e111111111111111111111111111111;

}

onumm1n30_t onumm1n30_truncate_im(imdir_t idx, ord_t order, onumm1n30_t* lhs){

  onumm1n30_t res;

  // Copy number.
  res = (*lhs);
  // Truncate all other values when necessary.
  // Real;
  switch (order){
    case 0:
      res = onumm1n30_init();
      break;
    case 1:
      switch (idx){
        case 0: //  e1
          res.e1 = 0.0;
          res.e11 = 0.0;
          res.e111 = 0.0;
          res.e1111 = 0.0;
          res.e11111 = 0.0;
          res.e111111 = 0.0;
          res.e1111111 = 0.0;
          res.e11111111 = 0.0;
          res.e111111111 = 0.0;
          res.e1111111111 = 0.0;
          res.e11111111111 = 0.0;
          res.e111111111111 = 0.0;
          res.e1111111111111 = 0.0;
          res.e11111111111111 = 0.0;
          res.e111111111111111 = 0.0;
          res.e1111111111111111 = 0.0;
          res.e11111111111111111 = 0.0;
          res.e111111111111111111 = 0.0;
          res.e1111111111111111111 = 0.0;
          res.e11111111111111111111 = 0.0;
          res.e111111111111111111111 = 0.0;
          res.e1111111111111111111111 = 0.0;
          res.e11111111111111111111111 = 0.0;
          res.e111111111111111111111111 = 0.0;
          res.e1111111111111111111111111 = 0.0;
          res.e11111111111111111111111111 = 0.0;
          res.e111111111111111111111111111 = 0.0;
          res.e1111111111111111111111111111 = 0.0;
          res.e11111111111111111111111111111 = 0.0;
          res.e111111111111111111111111111111 = 0.0;
          break;
      }
      break;
    case 2:
      switch (idx){
        case 0: //  e11
          res.e11 = 0.0;
          res.e111 = 0.0;
          res.e1111 = 0.0;
          res.e11111 = 0.0;
          res.e111111 = 0.0;
          res.e1111111 = 0.0;
          res.e11111111 = 0.0;
          res.e111111111 = 0.0;
          res.e1111111111 = 0.0;
          res.e11111111111 = 0.0;
          res.e111111111111 = 0.0;
          res.e1111111111111 = 0.0;
          res.e11111111111111 = 0.0;
          res.e111111111111111 = 0.0;
          res.e1111111111111111 = 0.0;
          res.e11111111111111111 = 0.0;
          res.e111111111111111111 = 0.0;
          res.e1111111111111111111 = 0.0;
          res.e11111111111111111111 = 0.0;
          res.e111111111111111111111 = 0.0;
          res.e1111111111111111111111 = 0.0;
          res.e11111111111111111111111 = 0.0;
          res.e111111111111111111111111 = 0.0;
          res.e1111111111111111111111111 = 0.0;
          res.e11111111111111111111111111 = 0.0;
          res.e111111111111111111111111111 = 0.0;
          res.e1111111111111111111111111111 = 0.0;
          res.e11111111111111111111111111111 = 0.0;
          res.e111111111111111111111111111111 = 0.0;
          break;
      }
      break;
    case 3:
      switch (idx){
        case 0: //  e111
          res.e111 = 0.0;
          res.e1111 = 0.0;
          res.e11111 = 0.0;
          res.e111111 = 0.0;
          res.e1111111 = 0.0;
          res.e11111111 = 0.0;
          res.e111111111 = 0.0;
          res.e1111111111 = 0.0;
          res.e11111111111 = 0.0;
          res.e111111111111 = 0.0;
          res.e1111111111111 = 0.0;
          res.e11111111111111 = 0.0;
          res.e111111111111111 = 0.0;
          res.e1111111111111111 = 0.0;
          res.e11111111111111111 = 0.0;
          res.e111111111111111111 = 0.0;
          res.e1111111111111111111 = 0.0;
          res.e11111111111111111111 = 0.0;
          res.e111111111111111111111 = 0.0;
          res.e1111111111111111111111 = 0.0;
          res.e11111111111111111111111 = 0.0;
          res.e111111111111111111111111 = 0.0;
          res.e1111111111111111111111111 = 0.0;
          res.e11111111111111111111111111 = 0.0;
          res.e111111111111111111111111111 = 0.0;
          res.e1111111111111111111111111111 = 0.0;
          res.e11111111111111111111111111111 = 0.0;
          res.e111111111111111111111111111111 = 0.0;
          break;
      }
      break;
    case 4:
      switch (idx){
        case 0: //  e1111
          res.e1111 = 0.0;
          res.e11111 = 0.0;
          res.e111111 = 0.0;
          res.e1111111 = 0.0;
          res.e11111111 = 0.0;
          res.e111111111 = 0.0;
          res.e1111111111 = 0.0;
          res.e11111111111 = 0.0;
          res.e111111111111 = 0.0;
          res.e1111111111111 = 0.0;
          res.e11111111111111 = 0.0;
          res.e111111111111111 = 0.0;
          res.e1111111111111111 = 0.0;
          res.e11111111111111111 = 0.0;
          res.e111111111111111111 = 0.0;
          res.e1111111111111111111 = 0.0;
          res.e11111111111111111111 = 0.0;
          res.e111111111111111111111 = 0.0;
          res.e1111111111111111111111 = 0.0;
          res.e11111111111111111111111 = 0.0;
          res.e111111111111111111111111 = 0.0;
          res.e1111111111111111111111111 = 0.0;
          res.e11111111111111111111111111 = 0.0;
          res.e111111111111111111111111111 = 0.0;
          res.e1111111111111111111111111111 = 0.0;
          res.e11111111111111111111111111111 = 0.0;
          res.e111111111111111111111111111111 = 0.0;
          break;
      }
      break;
    case 5:
      switch (idx){
        case 0: //  e11111
          res.e11111 = 0.0;
          res.e111111 = 0.0;
          res.e1111111 = 0.0;
          res.e11111111 = 0.0;
          res.e111111111 = 0.0;
          res.e1111111111 = 0.0;
          res.e11111111111 = 0.0;
          res.e111111111111 = 0.0;
          res.e1111111111111 = 0.0;
          res.e11111111111111 = 0.0;
          res.e111111111111111 = 0.0;
          res.e1111111111111111 = 0.0;
          res.e11111111111111111 = 0.0;
          res.e111111111111111111 = 0.0;
          res.e1111111111111111111 = 0.0;
          res.e11111111111111111111 = 0.0;
          res.e111111111111111111111 = 0.0;
          res.e1111111111111111111111 = 0.0;
          res.e11111111111111111111111 = 0.0;
          res.e111111111111111111111111 = 0.0;
          res.e1111111111111111111111111 = 0.0;
          res.e11111111111111111111111111 = 0.0;
          res.e111111111111111111111111111 = 0.0;
          res.e1111111111111111111111111111 = 0.0;
          res.e11111111111111111111111111111 = 0.0;
          res.e111111111111111111111111111111 = 0.0;
          break;
      }
      break;
    case 6:
      switch (idx){
        case 0: //  e111111
          res.e111111 = 0.0;
          res.e1111111 = 0.0;
          res.e11111111 = 0.0;
          res.e111111111 = 0.0;
          res.e1111111111 = 0.0;
          res.e11111111111 = 0.0;
          res.e111111111111 = 0.0;
          res.e1111111111111 = 0.0;
          res.e11111111111111 = 0.0;
          res.e111111111111111 = 0.0;
          res.e1111111111111111 = 0.0;
          res.e11111111111111111 = 0.0;
          res.e111111111111111111 = 0.0;
          res.e1111111111111111111 = 0.0;
          res.e11111111111111111111 = 0.0;
          res.e111111111111111111111 = 0.0;
          res.e1111111111111111111111 = 0.0;
          res.e11111111111111111111111 = 0.0;
          res.e111111111111111111111111 = 0.0;
          res.e1111111111111111111111111 = 0.0;
          res.e11111111111111111111111111 = 0.0;
          res.e111111111111111111111111111 = 0.0;
          res.e1111111111111111111111111111 = 0.0;
          res.e11111111111111111111111111111 = 0.0;
          res.e111111111111111111111111111111 = 0.0;
          break;
      }
      break;
    case 7:
      switch (idx){
        case 0: //  e1111111
          res.e1111111 = 0.0;
          res.e11111111 = 0.0;
          res.e111111111 = 0.0;
          res.e1111111111 = 0.0;
          res.e11111111111 = 0.0;
          res.e111111111111 = 0.0;
          res.e1111111111111 = 0.0;
          res.e11111111111111 = 0.0;
          res.e111111111111111 = 0.0;
          res.e1111111111111111 = 0.0;
          res.e11111111111111111 = 0.0;
          res.e111111111111111111 = 0.0;
          res.e1111111111111111111 = 0.0;
          res.e11111111111111111111 = 0.0;
          res.e111111111111111111111 = 0.0;
          res.e1111111111111111111111 = 0.0;
          res.e11111111111111111111111 = 0.0;
          res.e111111111111111111111111 = 0.0;
          res.e1111111111111111111111111 = 0.0;
          res.e11111111111111111111111111 = 0.0;
          res.e111111111111111111111111111 = 0.0;
          res.e1111111111111111111111111111 = 0.0;
          res.e11111111111111111111111111111 = 0.0;
          res.e111111111111111111111111111111 = 0.0;
          break;
      }
      break;
    case 8:
      switch (idx){
        case 0: //  e11111111
          res.e11111111 = 0.0;
          res.e111111111 = 0.0;
          res.e1111111111 = 0.0;
          res.e11111111111 = 0.0;
          res.e111111111111 = 0.0;
          res.e1111111111111 = 0.0;
          res.e11111111111111 = 0.0;
          res.e111111111111111 = 0.0;
          res.e1111111111111111 = 0.0;
          res.e11111111111111111 = 0.0;
          res.e111111111111111111 = 0.0;
          res.e1111111111111111111 = 0.0;
          res.e11111111111111111111 = 0.0;
          res.e111111111111111111111 = 0.0;
          res.e1111111111111111111111 = 0.0;
          res.e11111111111111111111111 = 0.0;
          res.e111111111111111111111111 = 0.0;
          res.e1111111111111111111111111 = 0.0;
          res.e11111111111111111111111111 = 0.0;
          res.e111111111111111111111111111 = 0.0;
          res.e1111111111111111111111111111 = 0.0;
          res.e11111111111111111111111111111 = 0.0;
          res.e111111111111111111111111111111 = 0.0;
          break;
      }
      break;
    case 9:
      switch (idx){
        case 0: //  e111111111
          res.e111111111 = 0.0;
          res.e1111111111 = 0.0;
          res.e11111111111 = 0.0;
          res.e111111111111 = 0.0;
          res.e1111111111111 = 0.0;
          res.e11111111111111 = 0.0;
          res.e111111111111111 = 0.0;
          res.e1111111111111111 = 0.0;
          res.e11111111111111111 = 0.0;
          res.e111111111111111111 = 0.0;
          res.e1111111111111111111 = 0.0;
          res.e11111111111111111111 = 0.0;
          res.e111111111111111111111 = 0.0;
          res.e1111111111111111111111 = 0.0;
          res.e11111111111111111111111 = 0.0;
          res.e111111111111111111111111 = 0.0;
          res.e1111111111111111111111111 = 0.0;
          res.e11111111111111111111111111 = 0.0;
          res.e111111111111111111111111111 = 0.0;
          res.e1111111111111111111111111111 = 0.0;
          res.e11111111111111111111111111111 = 0.0;
          res.e111111111111111111111111111111 = 0.0;
          break;
      }
      break;
    case 10:
      switch (idx){
        case 0: //  e1111111111
          res.e1111111111 = 0.0;
          res.e11111111111 = 0.0;
          res.e111111111111 = 0.0;
          res.e1111111111111 = 0.0;
          res.e11111111111111 = 0.0;
          res.e111111111111111 = 0.0;
          res.e1111111111111111 = 0.0;
          res.e11111111111111111 = 0.0;
          res.e111111111111111111 = 0.0;
          res.e1111111111111111111 = 0.0;
          res.e11111111111111111111 = 0.0;
          res.e111111111111111111111 = 0.0;
          res.e1111111111111111111111 = 0.0;
          res.e11111111111111111111111 = 0.0;
          res.e111111111111111111111111 = 0.0;
          res.e1111111111111111111111111 = 0.0;
          res.e11111111111111111111111111 = 0.0;
          res.e111111111111111111111111111 = 0.0;
          res.e1111111111111111111111111111 = 0.0;
          res.e11111111111111111111111111111 = 0.0;
          res.e111111111111111111111111111111 = 0.0;
          break;
      }
      break;
    case 11:
      switch (idx){
        case 0: //  e11111111111
          res.e11111111111 = 0.0;
          res.e111111111111 = 0.0;
          res.e1111111111111 = 0.0;
          res.e11111111111111 = 0.0;
          res.e111111111111111 = 0.0;
          res.e1111111111111111 = 0.0;
          res.e11111111111111111 = 0.0;
          res.e111111111111111111 = 0.0;
          res.e1111111111111111111 = 0.0;
          res.e11111111111111111111 = 0.0;
          res.e111111111111111111111 = 0.0;
          res.e1111111111111111111111 = 0.0;
          res.e11111111111111111111111 = 0.0;
          res.e111111111111111111111111 = 0.0;
          res.e1111111111111111111111111 = 0.0;
          res.e11111111111111111111111111 = 0.0;
          res.e111111111111111111111111111 = 0.0;
          res.e1111111111111111111111111111 = 0.0;
          res.e11111111111111111111111111111 = 0.0;
          res.e111111111111111111111111111111 = 0.0;
          break;
      }
      break;
    case 12:
      switch (idx){
        case 0: //  e111111111111
          res.e111111111111 = 0.0;
          res.e1111111111111 = 0.0;
          res.e11111111111111 = 0.0;
          res.e111111111111111 = 0.0;
          res.e1111111111111111 = 0.0;
          res.e11111111111111111 = 0.0;
          res.e111111111111111111 = 0.0;
          res.e1111111111111111111 = 0.0;
          res.e11111111111111111111 = 0.0;
          res.e111111111111111111111 = 0.0;
          res.e1111111111111111111111 = 0.0;
          res.e11111111111111111111111 = 0.0;
          res.e111111111111111111111111 = 0.0;
          res.e1111111111111111111111111 = 0.0;
          res.e11111111111111111111111111 = 0.0;
          res.e111111111111111111111111111 = 0.0;
          res.e1111111111111111111111111111 = 0.0;
          res.e11111111111111111111111111111 = 0.0;
          res.e111111111111111111111111111111 = 0.0;
          break;
      }
      break;
    case 13:
      switch (idx){
        case 0: //  e1111111111111
          res.e1111111111111 = 0.0;
          res.e11111111111111 = 0.0;
          res.e111111111111111 = 0.0;
          res.e1111111111111111 = 0.0;
          res.e11111111111111111 = 0.0;
          res.e111111111111111111 = 0.0;
          res.e1111111111111111111 = 0.0;
          res.e11111111111111111111 = 0.0;
          res.e111111111111111111111 = 0.0;
          res.e1111111111111111111111 = 0.0;
          res.e11111111111111111111111 = 0.0;
          res.e111111111111111111111111 = 0.0;
          res.e1111111111111111111111111 = 0.0;
          res.e11111111111111111111111111 = 0.0;
          res.e111111111111111111111111111 = 0.0;
          res.e1111111111111111111111111111 = 0.0;
          res.e11111111111111111111111111111 = 0.0;
          res.e111111111111111111111111111111 = 0.0;
          break;
      }
      break;
    case 14:
      switch (idx){
        case 0: //  e11111111111111
          res.e11111111111111 = 0.0;
          res.e111111111111111 = 0.0;
          res.e1111111111111111 = 0.0;
          res.e11111111111111111 = 0.0;
          res.e111111111111111111 = 0.0;
          res.e1111111111111111111 = 0.0;
          res.e11111111111111111111 = 0.0;
          res.e111111111111111111111 = 0.0;
          res.e1111111111111111111111 = 0.0;
          res.e11111111111111111111111 = 0.0;
          res.e111111111111111111111111 = 0.0;
          res.e1111111111111111111111111 = 0.0;
          res.e11111111111111111111111111 = 0.0;
          res.e111111111111111111111111111 = 0.0;
          res.e1111111111111111111111111111 = 0.0;
          res.e11111111111111111111111111111 = 0.0;
          res.e111111111111111111111111111111 = 0.0;
          break;
      }
      break;
    case 15:
      switch (idx){
        case 0: //  e111111111111111
          res.e111111111111111 = 0.0;
          res.e1111111111111111 = 0.0;
          res.e11111111111111111 = 0.0;
          res.e111111111111111111 = 0.0;
          res.e1111111111111111111 = 0.0;
          res.e11111111111111111111 = 0.0;
          res.e111111111111111111111 = 0.0;
          res.e1111111111111111111111 = 0.0;
          res.e11111111111111111111111 = 0.0;
          res.e111111111111111111111111 = 0.0;
          res.e1111111111111111111111111 = 0.0;
          res.e11111111111111111111111111 = 0.0;
          res.e111111111111111111111111111 = 0.0;
          res.e1111111111111111111111111111 = 0.0;
          res.e11111111111111111111111111111 = 0.0;
          res.e111111111111111111111111111111 = 0.0;
          break;
      }
      break;
    case 16:
      switch (idx){
        case 0: //  e1111111111111111
          res.e1111111111111111 = 0.0;
          res.e11111111111111111 = 0.0;
          res.e111111111111111111 = 0.0;
          res.e1111111111111111111 = 0.0;
          res.e11111111111111111111 = 0.0;
          res.e111111111111111111111 = 0.0;
          res.e1111111111111111111111 = 0.0;
          res.e11111111111111111111111 = 0.0;
          res.e111111111111111111111111 = 0.0;
          res.e1111111111111111111111111 = 0.0;
          res.e11111111111111111111111111 = 0.0;
          res.e111111111111111111111111111 = 0.0;
          res.e1111111111111111111111111111 = 0.0;
          res.e11111111111111111111111111111 = 0.0;
          res.e111111111111111111111111111111 = 0.0;
          break;
      }
      break;
    case 17:
      switch (idx){
        case 0: //  e11111111111111111
          res.e11111111111111111 = 0.0;
          res.e111111111111111111 = 0.0;
          res.e1111111111111111111 = 0.0;
          res.e11111111111111111111 = 0.0;
          res.e111111111111111111111 = 0.0;
          res.e1111111111111111111111 = 0.0;
          res.e11111111111111111111111 = 0.0;
          res.e111111111111111111111111 = 0.0;
          res.e1111111111111111111111111 = 0.0;
          res.e11111111111111111111111111 = 0.0;
          res.e111111111111111111111111111 = 0.0;
          res.e1111111111111111111111111111 = 0.0;
          res.e11111111111111111111111111111 = 0.0;
          res.e111111111111111111111111111111 = 0.0;
          break;
      }
      break;
    case 18:
      switch (idx){
        case 0: //  e111111111111111111
          res.e111111111111111111 = 0.0;
          res.e1111111111111111111 = 0.0;
          res.e11111111111111111111 = 0.0;
          res.e111111111111111111111 = 0.0;
          res.e1111111111111111111111 = 0.0;
          res.e11111111111111111111111 = 0.0;
          res.e111111111111111111111111 = 0.0;
          res.e1111111111111111111111111 = 0.0;
          res.e11111111111111111111111111 = 0.0;
          res.e111111111111111111111111111 = 0.0;
          res.e1111111111111111111111111111 = 0.0;
          res.e11111111111111111111111111111 = 0.0;
          res.e111111111111111111111111111111 = 0.0;
          break;
      }
      break;
    case 19:
      switch (idx){
        case 0: //  e1111111111111111111
          res.e1111111111111111111 = 0.0;
          res.e11111111111111111111 = 0.0;
          res.e111111111111111111111 = 0.0;
          res.e1111111111111111111111 = 0.0;
          res.e11111111111111111111111 = 0.0;
          res.e111111111111111111111111 = 0.0;
          res.e1111111111111111111111111 = 0.0;
          res.e11111111111111111111111111 = 0.0;
          res.e111111111111111111111111111 = 0.0;
          res.e1111111111111111111111111111 = 0.0;
          res.e11111111111111111111111111111 = 0.0;
          res.e111111111111111111111111111111 = 0.0;
          break;
      }
      break;
    case 20:
      switch (idx){
        case 0: //  e11111111111111111111
          res.e11111111111111111111 = 0.0;
          res.e111111111111111111111 = 0.0;
          res.e1111111111111111111111 = 0.0;
          res.e11111111111111111111111 = 0.0;
          res.e111111111111111111111111 = 0.0;
          res.e1111111111111111111111111 = 0.0;
          res.e11111111111111111111111111 = 0.0;
          res.e111111111111111111111111111 = 0.0;
          res.e1111111111111111111111111111 = 0.0;
          res.e11111111111111111111111111111 = 0.0;
          res.e111111111111111111111111111111 = 0.0;
          break;
      }
      break;
    case 21:
      switch (idx){
        case 0: //  e111111111111111111111
          res.e111111111111111111111 = 0.0;
          res.e1111111111111111111111 = 0.0;
          res.e11111111111111111111111 = 0.0;
          res.e111111111111111111111111 = 0.0;
          res.e1111111111111111111111111 = 0.0;
          res.e11111111111111111111111111 = 0.0;
          res.e111111111111111111111111111 = 0.0;
          res.e1111111111111111111111111111 = 0.0;
          res.e11111111111111111111111111111 = 0.0;
          res.e111111111111111111111111111111 = 0.0;
          break;
      }
      break;
    case 22:
      switch (idx){
        case 0: //  e1111111111111111111111
          res.e1111111111111111111111 = 0.0;
          res.e11111111111111111111111 = 0.0;
          res.e111111111111111111111111 = 0.0;
          res.e1111111111111111111111111 = 0.0;
          res.e11111111111111111111111111 = 0.0;
          res.e111111111111111111111111111 = 0.0;
          res.e1111111111111111111111111111 = 0.0;
          res.e11111111111111111111111111111 = 0.0;
          res.e111111111111111111111111111111 = 0.0;
          break;
      }
      break;
    case 23:
      switch (idx){
        case 0: //  e11111111111111111111111
          res.e11111111111111111111111 = 0.0;
          res.e111111111111111111111111 = 0.0;
          res.e1111111111111111111111111 = 0.0;
          res.e11111111111111111111111111 = 0.0;
          res.e111111111111111111111111111 = 0.0;
          res.e1111111111111111111111111111 = 0.0;
          res.e11111111111111111111111111111 = 0.0;
          res.e111111111111111111111111111111 = 0.0;
          break;
      }
      break;
    case 24:
      switch (idx){
        case 0: //  e111111111111111111111111
          res.e111111111111111111111111 = 0.0;
          res.e1111111111111111111111111 = 0.0;
          res.e11111111111111111111111111 = 0.0;
          res.e111111111111111111111111111 = 0.0;
          res.e1111111111111111111111111111 = 0.0;
          res.e11111111111111111111111111111 = 0.0;
          res.e111111111111111111111111111111 = 0.0;
          break;
      }
      break;
    case 25:
      switch (idx){
        case 0: //  e1111111111111111111111111
          res.e1111111111111111111111111 = 0.0;
          res.e11111111111111111111111111 = 0.0;
          res.e111111111111111111111111111 = 0.0;
          res.e1111111111111111111111111111 = 0.0;
          res.e11111111111111111111111111111 = 0.0;
          res.e111111111111111111111111111111 = 0.0;
          break;
      }
      break;
    case 26:
      switch (idx){
        case 0: //  e11111111111111111111111111
          res.e11111111111111111111111111 = 0.0;
          res.e111111111111111111111111111 = 0.0;
          res.e1111111111111111111111111111 = 0.0;
          res.e11111111111111111111111111111 = 0.0;
          res.e111111111111111111111111111111 = 0.0;
          break;
      }
      break;
    case 27:
      switch (idx){
        case 0: //  e111111111111111111111111111
          res.e111111111111111111111111111 = 0.0;
          res.e1111111111111111111111111111 = 0.0;
          res.e11111111111111111111111111111 = 0.0;
          res.e111111111111111111111111111111 = 0.0;
          break;
      }
      break;
    case 28:
      switch (idx){
        case 0: //  e1111111111111111111111111111
          res.e1111111111111111111111111111 = 0.0;
          res.e11111111111111111111111111111 = 0.0;
          res.e111111111111111111111111111111 = 0.0;
          break;
      }
      break;
    case 29:
      switch (idx){
        case 0: //  e11111111111111111111111111111
          res.e11111111111111111111111111111 = 0.0;
          res.e111111111111111111111111111111 = 0.0;
          break;
      }
      break;
    case 30:
      switch (idx){
        case 0: //  e111111111111111111111111111111
          res.e111111111111111111111111111111 = 0.0;
          break;
      }
      break;
  }
  return res;

}

void onumm1n30_truncate_im_to(imdir_t idx, ord_t order, onumm1n30_t* lhs, onumm1n30_t* res){

  // Copy number.
  *res = (*lhs);
  // Truncate all other values when necessary.
  // Real;
  switch (order){
    case 0:
      *res = onumm1n30_init();
      break;
    case 1:
      switch (idx){
        case 0: //  e1
          res->e1 = 0.0;
          res->e11 = 0.0;
          res->e111 = 0.0;
          res->e1111 = 0.0;
          res->e11111 = 0.0;
          res->e111111 = 0.0;
          res->e1111111 = 0.0;
          res->e11111111 = 0.0;
          res->e111111111 = 0.0;
          res->e1111111111 = 0.0;
          res->e11111111111 = 0.0;
          res->e111111111111 = 0.0;
          res->e1111111111111 = 0.0;
          res->e11111111111111 = 0.0;
          res->e111111111111111 = 0.0;
          res->e1111111111111111 = 0.0;
          res->e11111111111111111 = 0.0;
          res->e111111111111111111 = 0.0;
          res->e1111111111111111111 = 0.0;
          res->e11111111111111111111 = 0.0;
          res->e111111111111111111111 = 0.0;
          res->e1111111111111111111111 = 0.0;
          res->e11111111111111111111111 = 0.0;
          res->e111111111111111111111111 = 0.0;
          res->e1111111111111111111111111 = 0.0;
          res->e11111111111111111111111111 = 0.0;
          res->e111111111111111111111111111 = 0.0;
          res->e1111111111111111111111111111 = 0.0;
          res->e11111111111111111111111111111 = 0.0;
          res->e111111111111111111111111111111 = 0.0;
          break;
      }
      break;
    case 2:
      switch (idx){
        case 0: //  e11
          res->e11 = 0.0;
          res->e111 = 0.0;
          res->e1111 = 0.0;
          res->e11111 = 0.0;
          res->e111111 = 0.0;
          res->e1111111 = 0.0;
          res->e11111111 = 0.0;
          res->e111111111 = 0.0;
          res->e1111111111 = 0.0;
          res->e11111111111 = 0.0;
          res->e111111111111 = 0.0;
          res->e1111111111111 = 0.0;
          res->e11111111111111 = 0.0;
          res->e111111111111111 = 0.0;
          res->e1111111111111111 = 0.0;
          res->e11111111111111111 = 0.0;
          res->e111111111111111111 = 0.0;
          res->e1111111111111111111 = 0.0;
          res->e11111111111111111111 = 0.0;
          res->e111111111111111111111 = 0.0;
          res->e1111111111111111111111 = 0.0;
          res->e11111111111111111111111 = 0.0;
          res->e111111111111111111111111 = 0.0;
          res->e1111111111111111111111111 = 0.0;
          res->e11111111111111111111111111 = 0.0;
          res->e111111111111111111111111111 = 0.0;
          res->e1111111111111111111111111111 = 0.0;
          res->e11111111111111111111111111111 = 0.0;
          res->e111111111111111111111111111111 = 0.0;
          break;
      }
      break;
    case 3:
      switch (idx){
        case 0: //  e111
          res->e111 = 0.0;
          res->e1111 = 0.0;
          res->e11111 = 0.0;
          res->e111111 = 0.0;
          res->e1111111 = 0.0;
          res->e11111111 = 0.0;
          res->e111111111 = 0.0;
          res->e1111111111 = 0.0;
          res->e11111111111 = 0.0;
          res->e111111111111 = 0.0;
          res->e1111111111111 = 0.0;
          res->e11111111111111 = 0.0;
          res->e111111111111111 = 0.0;
          res->e1111111111111111 = 0.0;
          res->e11111111111111111 = 0.0;
          res->e111111111111111111 = 0.0;
          res->e1111111111111111111 = 0.0;
          res->e11111111111111111111 = 0.0;
          res->e111111111111111111111 = 0.0;
          res->e1111111111111111111111 = 0.0;
          res->e11111111111111111111111 = 0.0;
          res->e111111111111111111111111 = 0.0;
          res->e1111111111111111111111111 = 0.0;
          res->e11111111111111111111111111 = 0.0;
          res->e111111111111111111111111111 = 0.0;
          res->e1111111111111111111111111111 = 0.0;
          res->e11111111111111111111111111111 = 0.0;
          res->e111111111111111111111111111111 = 0.0;
          break;
      }
      break;
    case 4:
      switch (idx){
        case 0: //  e1111
          res->e1111 = 0.0;
          res->e11111 = 0.0;
          res->e111111 = 0.0;
          res->e1111111 = 0.0;
          res->e11111111 = 0.0;
          res->e111111111 = 0.0;
          res->e1111111111 = 0.0;
          res->e11111111111 = 0.0;
          res->e111111111111 = 0.0;
          res->e1111111111111 = 0.0;
          res->e11111111111111 = 0.0;
          res->e111111111111111 = 0.0;
          res->e1111111111111111 = 0.0;
          res->e11111111111111111 = 0.0;
          res->e111111111111111111 = 0.0;
          res->e1111111111111111111 = 0.0;
          res->e11111111111111111111 = 0.0;
          res->e111111111111111111111 = 0.0;
          res->e1111111111111111111111 = 0.0;
          res->e11111111111111111111111 = 0.0;
          res->e111111111111111111111111 = 0.0;
          res->e1111111111111111111111111 = 0.0;
          res->e11111111111111111111111111 = 0.0;
          res->e111111111111111111111111111 = 0.0;
          res->e1111111111111111111111111111 = 0.0;
          res->e11111111111111111111111111111 = 0.0;
          res->e111111111111111111111111111111 = 0.0;
          break;
      }
      break;
    case 5:
      switch (idx){
        case 0: //  e11111
          res->e11111 = 0.0;
          res->e111111 = 0.0;
          res->e1111111 = 0.0;
          res->e11111111 = 0.0;
          res->e111111111 = 0.0;
          res->e1111111111 = 0.0;
          res->e11111111111 = 0.0;
          res->e111111111111 = 0.0;
          res->e1111111111111 = 0.0;
          res->e11111111111111 = 0.0;
          res->e111111111111111 = 0.0;
          res->e1111111111111111 = 0.0;
          res->e11111111111111111 = 0.0;
          res->e111111111111111111 = 0.0;
          res->e1111111111111111111 = 0.0;
          res->e11111111111111111111 = 0.0;
          res->e111111111111111111111 = 0.0;
          res->e1111111111111111111111 = 0.0;
          res->e11111111111111111111111 = 0.0;
          res->e111111111111111111111111 = 0.0;
          res->e1111111111111111111111111 = 0.0;
          res->e11111111111111111111111111 = 0.0;
          res->e111111111111111111111111111 = 0.0;
          res->e1111111111111111111111111111 = 0.0;
          res->e11111111111111111111111111111 = 0.0;
          res->e111111111111111111111111111111 = 0.0;
          break;
      }
      break;
    case 6:
      switch (idx){
        case 0: //  e111111
          res->e111111 = 0.0;
          res->e1111111 = 0.0;
          res->e11111111 = 0.0;
          res->e111111111 = 0.0;
          res->e1111111111 = 0.0;
          res->e11111111111 = 0.0;
          res->e111111111111 = 0.0;
          res->e1111111111111 = 0.0;
          res->e11111111111111 = 0.0;
          res->e111111111111111 = 0.0;
          res->e1111111111111111 = 0.0;
          res->e11111111111111111 = 0.0;
          res->e111111111111111111 = 0.0;
          res->e1111111111111111111 = 0.0;
          res->e11111111111111111111 = 0.0;
          res->e111111111111111111111 = 0.0;
          res->e1111111111111111111111 = 0.0;
          res->e11111111111111111111111 = 0.0;
          res->e111111111111111111111111 = 0.0;
          res->e1111111111111111111111111 = 0.0;
          res->e11111111111111111111111111 = 0.0;
          res->e111111111111111111111111111 = 0.0;
          res->e1111111111111111111111111111 = 0.0;
          res->e11111111111111111111111111111 = 0.0;
          res->e111111111111111111111111111111 = 0.0;
          break;
      }
      break;
    case 7:
      switch (idx){
        case 0: //  e1111111
          res->e1111111 = 0.0;
          res->e11111111 = 0.0;
          res->e111111111 = 0.0;
          res->e1111111111 = 0.0;
          res->e11111111111 = 0.0;
          res->e111111111111 = 0.0;
          res->e1111111111111 = 0.0;
          res->e11111111111111 = 0.0;
          res->e111111111111111 = 0.0;
          res->e1111111111111111 = 0.0;
          res->e11111111111111111 = 0.0;
          res->e111111111111111111 = 0.0;
          res->e1111111111111111111 = 0.0;
          res->e11111111111111111111 = 0.0;
          res->e111111111111111111111 = 0.0;
          res->e1111111111111111111111 = 0.0;
          res->e11111111111111111111111 = 0.0;
          res->e111111111111111111111111 = 0.0;
          res->e1111111111111111111111111 = 0.0;
          res->e11111111111111111111111111 = 0.0;
          res->e111111111111111111111111111 = 0.0;
          res->e1111111111111111111111111111 = 0.0;
          res->e11111111111111111111111111111 = 0.0;
          res->e111111111111111111111111111111 = 0.0;
          break;
      }
      break;
    case 8:
      switch (idx){
        case 0: //  e11111111
          res->e11111111 = 0.0;
          res->e111111111 = 0.0;
          res->e1111111111 = 0.0;
          res->e11111111111 = 0.0;
          res->e111111111111 = 0.0;
          res->e1111111111111 = 0.0;
          res->e11111111111111 = 0.0;
          res->e111111111111111 = 0.0;
          res->e1111111111111111 = 0.0;
          res->e11111111111111111 = 0.0;
          res->e111111111111111111 = 0.0;
          res->e1111111111111111111 = 0.0;
          res->e11111111111111111111 = 0.0;
          res->e111111111111111111111 = 0.0;
          res->e1111111111111111111111 = 0.0;
          res->e11111111111111111111111 = 0.0;
          res->e111111111111111111111111 = 0.0;
          res->e1111111111111111111111111 = 0.0;
          res->e11111111111111111111111111 = 0.0;
          res->e111111111111111111111111111 = 0.0;
          res->e1111111111111111111111111111 = 0.0;
          res->e11111111111111111111111111111 = 0.0;
          res->e111111111111111111111111111111 = 0.0;
          break;
      }
      break;
    case 9:
      switch (idx){
        case 0: //  e111111111
          res->e111111111 = 0.0;
          res->e1111111111 = 0.0;
          res->e11111111111 = 0.0;
          res->e111111111111 = 0.0;
          res->e1111111111111 = 0.0;
          res->e11111111111111 = 0.0;
          res->e111111111111111 = 0.0;
          res->e1111111111111111 = 0.0;
          res->e11111111111111111 = 0.0;
          res->e111111111111111111 = 0.0;
          res->e1111111111111111111 = 0.0;
          res->e11111111111111111111 = 0.0;
          res->e111111111111111111111 = 0.0;
          res->e1111111111111111111111 = 0.0;
          res->e11111111111111111111111 = 0.0;
          res->e111111111111111111111111 = 0.0;
          res->e1111111111111111111111111 = 0.0;
          res->e11111111111111111111111111 = 0.0;
          res->e111111111111111111111111111 = 0.0;
          res->e1111111111111111111111111111 = 0.0;
          res->e11111111111111111111111111111 = 0.0;
          res->e111111111111111111111111111111 = 0.0;
          break;
      }
      break;
    case 10:
      switch (idx){
        case 0: //  e1111111111
          res->e1111111111 = 0.0;
          res->e11111111111 = 0.0;
          res->e111111111111 = 0.0;
          res->e1111111111111 = 0.0;
          res->e11111111111111 = 0.0;
          res->e111111111111111 = 0.0;
          res->e1111111111111111 = 0.0;
          res->e11111111111111111 = 0.0;
          res->e111111111111111111 = 0.0;
          res->e1111111111111111111 = 0.0;
          res->e11111111111111111111 = 0.0;
          res->e111111111111111111111 = 0.0;
          res->e1111111111111111111111 = 0.0;
          res->e11111111111111111111111 = 0.0;
          res->e111111111111111111111111 = 0.0;
          res->e1111111111111111111111111 = 0.0;
          res->e11111111111111111111111111 = 0.0;
          res->e111111111111111111111111111 = 0.0;
          res->e1111111111111111111111111111 = 0.0;
          res->e11111111111111111111111111111 = 0.0;
          res->e111111111111111111111111111111 = 0.0;
          break;
      }
      break;
    case 11:
      switch (idx){
        case 0: //  e11111111111
          res->e11111111111 = 0.0;
          res->e111111111111 = 0.0;
          res->e1111111111111 = 0.0;
          res->e11111111111111 = 0.0;
          res->e111111111111111 = 0.0;
          res->e1111111111111111 = 0.0;
          res->e11111111111111111 = 0.0;
          res->e111111111111111111 = 0.0;
          res->e1111111111111111111 = 0.0;
          res->e11111111111111111111 = 0.0;
          res->e111111111111111111111 = 0.0;
          res->e1111111111111111111111 = 0.0;
          res->e11111111111111111111111 = 0.0;
          res->e111111111111111111111111 = 0.0;
          res->e1111111111111111111111111 = 0.0;
          res->e11111111111111111111111111 = 0.0;
          res->e111111111111111111111111111 = 0.0;
          res->e1111111111111111111111111111 = 0.0;
          res->e11111111111111111111111111111 = 0.0;
          res->e111111111111111111111111111111 = 0.0;
          break;
      }
      break;
    case 12:
      switch (idx){
        case 0: //  e111111111111
          res->e111111111111 = 0.0;
          res->e1111111111111 = 0.0;
          res->e11111111111111 = 0.0;
          res->e111111111111111 = 0.0;
          res->e1111111111111111 = 0.0;
          res->e11111111111111111 = 0.0;
          res->e111111111111111111 = 0.0;
          res->e1111111111111111111 = 0.0;
          res->e11111111111111111111 = 0.0;
          res->e111111111111111111111 = 0.0;
          res->e1111111111111111111111 = 0.0;
          res->e11111111111111111111111 = 0.0;
          res->e111111111111111111111111 = 0.0;
          res->e1111111111111111111111111 = 0.0;
          res->e11111111111111111111111111 = 0.0;
          res->e111111111111111111111111111 = 0.0;
          res->e1111111111111111111111111111 = 0.0;
          res->e11111111111111111111111111111 = 0.0;
          res->e111111111111111111111111111111 = 0.0;
          break;
      }
      break;
    case 13:
      switch (idx){
        case 0: //  e1111111111111
          res->e1111111111111 = 0.0;
          res->e11111111111111 = 0.0;
          res->e111111111111111 = 0.0;
          res->e1111111111111111 = 0.0;
          res->e11111111111111111 = 0.0;
          res->e111111111111111111 = 0.0;
          res->e1111111111111111111 = 0.0;
          res->e11111111111111111111 = 0.0;
          res->e111111111111111111111 = 0.0;
          res->e1111111111111111111111 = 0.0;
          res->e11111111111111111111111 = 0.0;
          res->e111111111111111111111111 = 0.0;
          res->e1111111111111111111111111 = 0.0;
          res->e11111111111111111111111111 = 0.0;
          res->e111111111111111111111111111 = 0.0;
          res->e1111111111111111111111111111 = 0.0;
          res->e11111111111111111111111111111 = 0.0;
          res->e111111111111111111111111111111 = 0.0;
          break;
      }
      break;
    case 14:
      switch (idx){
        case 0: //  e11111111111111
          res->e11111111111111 = 0.0;
          res->e111111111111111 = 0.0;
          res->e1111111111111111 = 0.0;
          res->e11111111111111111 = 0.0;
          res->e111111111111111111 = 0.0;
          res->e1111111111111111111 = 0.0;
          res->e11111111111111111111 = 0.0;
          res->e111111111111111111111 = 0.0;
          res->e1111111111111111111111 = 0.0;
          res->e11111111111111111111111 = 0.0;
          res->e111111111111111111111111 = 0.0;
          res->e1111111111111111111111111 = 0.0;
          res->e11111111111111111111111111 = 0.0;
          res->e111111111111111111111111111 = 0.0;
          res->e1111111111111111111111111111 = 0.0;
          res->e11111111111111111111111111111 = 0.0;
          res->e111111111111111111111111111111 = 0.0;
          break;
      }
      break;
    case 15:
      switch (idx){
        case 0: //  e111111111111111
          res->e111111111111111 = 0.0;
          res->e1111111111111111 = 0.0;
          res->e11111111111111111 = 0.0;
          res->e111111111111111111 = 0.0;
          res->e1111111111111111111 = 0.0;
          res->e11111111111111111111 = 0.0;
          res->e111111111111111111111 = 0.0;
          res->e1111111111111111111111 = 0.0;
          res->e11111111111111111111111 = 0.0;
          res->e111111111111111111111111 = 0.0;
          res->e1111111111111111111111111 = 0.0;
          res->e11111111111111111111111111 = 0.0;
          res->e111111111111111111111111111 = 0.0;
          res->e1111111111111111111111111111 = 0.0;
          res->e11111111111111111111111111111 = 0.0;
          res->e111111111111111111111111111111 = 0.0;
          break;
      }
      break;
    case 16:
      switch (idx){
        case 0: //  e1111111111111111
          res->e1111111111111111 = 0.0;
          res->e11111111111111111 = 0.0;
          res->e111111111111111111 = 0.0;
          res->e1111111111111111111 = 0.0;
          res->e11111111111111111111 = 0.0;
          res->e111111111111111111111 = 0.0;
          res->e1111111111111111111111 = 0.0;
          res->e11111111111111111111111 = 0.0;
          res->e111111111111111111111111 = 0.0;
          res->e1111111111111111111111111 = 0.0;
          res->e11111111111111111111111111 = 0.0;
          res->e111111111111111111111111111 = 0.0;
          res->e1111111111111111111111111111 = 0.0;
          res->e11111111111111111111111111111 = 0.0;
          res->e111111111111111111111111111111 = 0.0;
          break;
      }
      break;
    case 17:
      switch (idx){
        case 0: //  e11111111111111111
          res->e11111111111111111 = 0.0;
          res->e111111111111111111 = 0.0;
          res->e1111111111111111111 = 0.0;
          res->e11111111111111111111 = 0.0;
          res->e111111111111111111111 = 0.0;
          res->e1111111111111111111111 = 0.0;
          res->e11111111111111111111111 = 0.0;
          res->e111111111111111111111111 = 0.0;
          res->e1111111111111111111111111 = 0.0;
          res->e11111111111111111111111111 = 0.0;
          res->e111111111111111111111111111 = 0.0;
          res->e1111111111111111111111111111 = 0.0;
          res->e11111111111111111111111111111 = 0.0;
          res->e111111111111111111111111111111 = 0.0;
          break;
      }
      break;
    case 18:
      switch (idx){
        case 0: //  e111111111111111111
          res->e111111111111111111 = 0.0;
          res->e1111111111111111111 = 0.0;
          res->e11111111111111111111 = 0.0;
          res->e111111111111111111111 = 0.0;
          res->e1111111111111111111111 = 0.0;
          res->e11111111111111111111111 = 0.0;
          res->e111111111111111111111111 = 0.0;
          res->e1111111111111111111111111 = 0.0;
          res->e11111111111111111111111111 = 0.0;
          res->e111111111111111111111111111 = 0.0;
          res->e1111111111111111111111111111 = 0.0;
          res->e11111111111111111111111111111 = 0.0;
          res->e111111111111111111111111111111 = 0.0;
          break;
      }
      break;
    case 19:
      switch (idx){
        case 0: //  e1111111111111111111
          res->e1111111111111111111 = 0.0;
          res->e11111111111111111111 = 0.0;
          res->e111111111111111111111 = 0.0;
          res->e1111111111111111111111 = 0.0;
          res->e11111111111111111111111 = 0.0;
          res->e111111111111111111111111 = 0.0;
          res->e1111111111111111111111111 = 0.0;
          res->e11111111111111111111111111 = 0.0;
          res->e111111111111111111111111111 = 0.0;
          res->e1111111111111111111111111111 = 0.0;
          res->e11111111111111111111111111111 = 0.0;
          res->e111111111111111111111111111111 = 0.0;
          break;
      }
      break;
    case 20:
      switch (idx){
        case 0: //  e11111111111111111111
          res->e11111111111111111111 = 0.0;
          res->e111111111111111111111 = 0.0;
          res->e1111111111111111111111 = 0.0;
          res->e11111111111111111111111 = 0.0;
          res->e111111111111111111111111 = 0.0;
          res->e1111111111111111111111111 = 0.0;
          res->e11111111111111111111111111 = 0.0;
          res->e111111111111111111111111111 = 0.0;
          res->e1111111111111111111111111111 = 0.0;
          res->e11111111111111111111111111111 = 0.0;
          res->e111111111111111111111111111111 = 0.0;
          break;
      }
      break;
    case 21:
      switch (idx){
        case 0: //  e111111111111111111111
          res->e111111111111111111111 = 0.0;
          res->e1111111111111111111111 = 0.0;
          res->e11111111111111111111111 = 0.0;
          res->e111111111111111111111111 = 0.0;
          res->e1111111111111111111111111 = 0.0;
          res->e11111111111111111111111111 = 0.0;
          res->e111111111111111111111111111 = 0.0;
          res->e1111111111111111111111111111 = 0.0;
          res->e11111111111111111111111111111 = 0.0;
          res->e111111111111111111111111111111 = 0.0;
          break;
      }
      break;
    case 22:
      switch (idx){
        case 0: //  e1111111111111111111111
          res->e1111111111111111111111 = 0.0;
          res->e11111111111111111111111 = 0.0;
          res->e111111111111111111111111 = 0.0;
          res->e1111111111111111111111111 = 0.0;
          res->e11111111111111111111111111 = 0.0;
          res->e111111111111111111111111111 = 0.0;
          res->e1111111111111111111111111111 = 0.0;
          res->e11111111111111111111111111111 = 0.0;
          res->e111111111111111111111111111111 = 0.0;
          break;
      }
      break;
    case 23:
      switch (idx){
        case 0: //  e11111111111111111111111
          res->e11111111111111111111111 = 0.0;
          res->e111111111111111111111111 = 0.0;
          res->e1111111111111111111111111 = 0.0;
          res->e11111111111111111111111111 = 0.0;
          res->e111111111111111111111111111 = 0.0;
          res->e1111111111111111111111111111 = 0.0;
          res->e11111111111111111111111111111 = 0.0;
          res->e111111111111111111111111111111 = 0.0;
          break;
      }
      break;
    case 24:
      switch (idx){
        case 0: //  e111111111111111111111111
          res->e111111111111111111111111 = 0.0;
          res->e1111111111111111111111111 = 0.0;
          res->e11111111111111111111111111 = 0.0;
          res->e111111111111111111111111111 = 0.0;
          res->e1111111111111111111111111111 = 0.0;
          res->e11111111111111111111111111111 = 0.0;
          res->e111111111111111111111111111111 = 0.0;
          break;
      }
      break;
    case 25:
      switch (idx){
        case 0: //  e1111111111111111111111111
          res->e1111111111111111111111111 = 0.0;
          res->e11111111111111111111111111 = 0.0;
          res->e111111111111111111111111111 = 0.0;
          res->e1111111111111111111111111111 = 0.0;
          res->e11111111111111111111111111111 = 0.0;
          res->e111111111111111111111111111111 = 0.0;
          break;
      }
      break;
    case 26:
      switch (idx){
        case 0: //  e11111111111111111111111111
          res->e11111111111111111111111111 = 0.0;
          res->e111111111111111111111111111 = 0.0;
          res->e1111111111111111111111111111 = 0.0;
          res->e11111111111111111111111111111 = 0.0;
          res->e111111111111111111111111111111 = 0.0;
          break;
      }
      break;
    case 27:
      switch (idx){
        case 0: //  e111111111111111111111111111
          res->e111111111111111111111111111 = 0.0;
          res->e1111111111111111111111111111 = 0.0;
          res->e11111111111111111111111111111 = 0.0;
          res->e111111111111111111111111111111 = 0.0;
          break;
      }
      break;
    case 28:
      switch (idx){
        case 0: //  e1111111111111111111111111111
          res->e1111111111111111111111111111 = 0.0;
          res->e11111111111111111111111111111 = 0.0;
          res->e111111111111111111111111111111 = 0.0;
          break;
      }
      break;
    case 29:
      switch (idx){
        case 0: //  e11111111111111111111111111111
          res->e11111111111111111111111111111 = 0.0;
          res->e111111111111111111111111111111 = 0.0;
          break;
      }
      break;
    case 30:
      switch (idx){
        case 0: //  e111111111111111111111111111111
          res->e111111111111111111111111111111 = 0.0;
          break;
      }
      break;
  }
}

void onumm1n30_print(  onumm1n30_t* lhs){

  // Print function.
  //  Real;
  printf("%.8g",lhs->r);
  //  Order 1;
  printf(" %+.8g*e1",lhs->e1);
  //  Order 2;
  printf(" %+.8g*e11",lhs->e11);
  //  Order 3;
  printf(" %+.8g*e111",lhs->e111);
  //  Order 4;
  printf(" %+.8g*e1111",lhs->e1111);
  //  Order 5;
  printf(" %+.8g*e11111",lhs->e11111);
  //  Order 6;
  printf(" %+.8g*e111111",lhs->e111111);
  //  Order 7;
  printf(" %+.8g*e1111111",lhs->e1111111);
  //  Order 8;
  printf(" %+.8g*e11111111",lhs->e11111111);
  //  Order 9;
  printf(" %+.8g*e111111111",lhs->e111111111);
  //  Order 10;
  printf(" %+.8g*e1111111111",lhs->e1111111111);
  //  Order 11;
  printf(" %+.8g*e11111111111",lhs->e11111111111);
  //  Order 12;
  printf(" %+.8g*e111111111111",lhs->e111111111111);
  //  Order 13;
  printf(" %+.8g*e1111111111111",lhs->e1111111111111);
  //  Order 14;
  printf(" %+.8g*e11111111111111",lhs->e11111111111111);
  //  Order 15;
  printf(" %+.8g*e111111111111111",lhs->e111111111111111);
  //  Order 16;
  printf(" %+.8g*e1111111111111111",lhs->e1111111111111111);
  //  Order 17;
  printf(" %+.8g*e11111111111111111",lhs->e11111111111111111);
  //  Order 18;
  printf(" %+.8g*e111111111111111111",lhs->e111111111111111111);
  //  Order 19;
  printf(" %+.8g*e1111111111111111111",lhs->e1111111111111111111);
  //  Order 20;
  printf(" %+.8g*e11111111111111111111",lhs->e11111111111111111111);
  //  Order 21;
  printf(" %+.8g*e111111111111111111111",lhs->e111111111111111111111);
  //  Order 22;
  printf(" %+.8g*e1111111111111111111111",lhs->e1111111111111111111111);
  //  Order 23;
  printf(" %+.8g*e11111111111111111111111",lhs->e11111111111111111111111);
  //  Order 24;
  printf(" %+.8g*e111111111111111111111111",lhs->e111111111111111111111111);
  //  Order 25;
  printf(" %+.8g*e1111111111111111111111111",lhs->e1111111111111111111111111);
  //  Order 26;
  printf(" %+.8g*e11111111111111111111111111",lhs->e11111111111111111111111111);
  //  Order 27;
  printf(" %+.8g*e111111111111111111111111111",lhs->e111111111111111111111111111);
  //  Order 28;
  printf(" %+.8g*e1111111111111111111111111111",lhs->e1111111111111111111111111111);
  //  Order 29;
  printf(" %+.8g*e11111111111111111111111111111",lhs->e11111111111111111111111111111);
  //  Order 30;
  printf(" %+.8g*e111111111111111111111111111111",lhs->e111111111111111111111111111111);
  printf("\n");

}

imdir_t onumm1n30_get_indx(imdir_t idx, ord_t order){

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
      }
      break;
    case 2:
      switch (idx){
        case 0:
          return 0;
          break;
      }
      break;
    case 3:
      switch (idx){
        case 0:
          return 0;
          break;
      }
      break;
    case 4:
      switch (idx){
        case 0:
          return 0;
          break;
      }
      break;
    case 5:
      switch (idx){
        case 0:
          return 0;
          break;
      }
      break;
    case 6:
      switch (idx){
        case 0:
          return 0;
          break;
      }
      break;
    case 7:
      switch (idx){
        case 0:
          return 0;
          break;
      }
      break;
    case 8:
      switch (idx){
        case 0:
          return 0;
          break;
      }
      break;
    case 9:
      switch (idx){
        case 0:
          return 0;
          break;
      }
      break;
    case 10:
      switch (idx){
        case 0:
          return 0;
          break;
      }
      break;
    case 11:
      switch (idx){
        case 0:
          return 0;
          break;
      }
      break;
    case 12:
      switch (idx){
        case 0:
          return 0;
          break;
      }
      break;
    case 13:
      switch (idx){
        case 0:
          return 0;
          break;
      }
      break;
    case 14:
      switch (idx){
        case 0:
          return 0;
          break;
      }
      break;
    case 15:
      switch (idx){
        case 0:
          return 0;
          break;
      }
      break;
    case 16:
      switch (idx){
        case 0:
          return 0;
          break;
      }
      break;
    case 17:
      switch (idx){
        case 0:
          return 0;
          break;
      }
      break;
    case 18:
      switch (idx){
        case 0:
          return 0;
          break;
      }
      break;
    case 19:
      switch (idx){
        case 0:
          return 0;
          break;
      }
      break;
    case 20:
      switch (idx){
        case 0:
          return 0;
          break;
      }
      break;
    case 21:
      switch (idx){
        case 0:
          return 0;
          break;
      }
      break;
    case 22:
      switch (idx){
        case 0:
          return 0;
          break;
      }
      break;
    case 23:
      switch (idx){
        case 0:
          return 0;
          break;
      }
      break;
    case 24:
      switch (idx){
        case 0:
          return 0;
          break;
      }
      break;
    case 25:
      switch (idx){
        case 0:
          return 0;
          break;
      }
      break;
    case 26:
      switch (idx){
        case 0:
          return 0;
          break;
      }
      break;
    case 27:
      switch (idx){
        case 0:
          return 0;
          break;
      }
      break;
    case 28:
      switch (idx){
        case 0:
          return 0;
          break;
      }
      break;
    case 29:
      switch (idx){
        case 0:
          return 0;
          break;
      }
      break;
    case 30:
      switch (idx){
        case 0:
          return 0;
          break;
      }
      break;
      default:
          return 0;
  }
  return 0;
}

