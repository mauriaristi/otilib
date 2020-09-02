

// Not implemented correctly:
void onumm0n0_set_im_o(onumm0n0_t* num, imdir_t idx, ord_t order, onumm0n0_t* res){
    onumm0n0_set_item(num->r,idx,order,res);
}
void onumm0n0_set_deriv_r(coeff_t num, imdir_t idx, ord_t order, onumm0n0_t* res){
    *res=onumm0n0_init();
}
void onumm0n0_set_deriv_o(onumm0n0_t* num, imdir_t idx, ord_t order, onumm0n0_t* res){
    *res=onumm0n0_init();
}
void onumm0n0_extract_im_to( imdir_t idx, ord_t order, onumm0n0_t* num, onumm0n0_t* res){
    *res=onumm0n0_init();
}
onumm0n0_t onumm0n0_extract_im(imdir_t idx, ord_t order, onumm0n0_t* num){
    onumm0n0_t res = onumm0n0_init();
    return res;
}
onumm0n0_t onumm0n0_extract_deriv(imdir_t idx, ord_t order, onumm0n0_t* num){
    onumm0n0_t res = onumm0n0_init();
    return res;
}
void onumm0n0_extract_deriv_to(imdir_t idx, ord_t order, onumm0n0_t* num, onumm0n0_t* res){
	*res = onumm0n0_init();
}
void onumm0n0_get_im_to_o(imdir_t idx, ord_t order, onumm0n0_t* num, onumm0n0_t* res){
    coeff_t rres = onumm0n0_get_item(idx, order, num);
    onumm0n0_set_r(rres,res);
}
onumm0n0_t onumm0n0_get_im_o(imdir_t idx, ord_t order, onumm0n0_t* num){
    coeff_t rres = onumm0n0_get_item(idx, order, num);
    onumm0n0_t res;
    onumm0n0_set_r(rres,&res);
    return res;
}
void onumm0n0_get_im_to_r(imdir_t idx, ord_t order, onumm0n0_t* num, coeff_t* res){
    *res = onumm0n0_get_item(idx, order, num);
}

inline ord_t onumm0n0_get_order(onumm0n0_t* lhs){

	return 0;

}

onumm0n0_t onumm0n0_get_deriv_o( imdir_t idx, ord_t order, onumm0n0_t* num){

    onumm0n0_t res = onumm0n0_init();

    onumm0n0_get_deriv_to( idx, order, num, &res);
    
    return res;

}

void onumm0n0_get_deriv_to( imdir_t idx, ord_t order, onumm0n0_t* num, onumm0n0_t* res){

    coeff_t deriv = onumm0n0_get_deriv(idx,order,num);

    onumm0n0_set_r( deriv, res);

}

void onumm0n0_set_im_r(coeff_t num, imdir_t idx, ord_t order, onumm0n0_t* res){

    onumm0n0_set_item(num, idx,order,res);

}

onumm0n0_t onumm0n0_init(void){

  onumm0n0_t res;

  // Init function
  // Real;
  res.r = 0.0;

  return res;

}

ndir_t onumm0n0_get_ndir_order(ord_t order, onumm0n0_t* num){

  ndir_t res;

  switch(order){
    case 0:
      res = 1;
      break;
  }

  return res;

}

ndir_t onumm0n0_get_ndir_total(onumm0n0_t* num){

  ndir_t res;

  res = 0;

  return res;

}

coeff_t* onumm0n0_get_order_address(ord_t order, onumm0n0_t* num){

  coeff_t* res;

  switch(order){
    case 0:
      res = &num->r;
      break;
  }
  return res;

}

onumm0n0_t onumm0n0_create_r(  coeff_t lhs){

  onumm0n0_t res;

  // Assign like function 'lhs'
  // Real;
  res.r = lhs;

  return res;

}

void onumm0n0_set_r(  coeff_t lhs, onumm0n0_t* res){

  // Assign like function 'lhs'
  // Real;
  res->r = lhs;

}

void onumm0n0_set_o(  onumm0n0_t* lhs, onumm0n0_t* res){

  // Assign like function 'lhs'
  // Real;
  res->r = lhs->r;

}

onumm0n0_t onumm0n0_get_order_im(ord_t order, onumm0n0_t* lhs){

  onumm0n0_t res;

  res = onumm0n0_init();
  switch( order ){
    case 0:
      // Assign like function 'lhs'
      // Real;
      res.r = lhs->r;
      break;
  }

  return res;

}

void onumm0n0_get_order_im_to(ord_t order, onumm0n0_t* lhs, onumm0n0_t* res){


  *res = onumm0n0_init();
  switch( order ){
    case 0:
      // Assign like function 'lhs'
      // Real;
      res->r = lhs->r;
      break;
  }

}

coeff_t onumm0n0_get_item(imdir_t idx, ord_t order, onumm0n0_t* lhs){

  coeff_t res;

  // Get Imaginary coefficient.
  res = 0.0;
  // Real;
  switch (order){
    case 0:
      res = lhs->r;
      break;
  }
  return res;

}

coeff_t onumm0n0_get_deriv(imdir_t idx, ord_t order, onumm0n0_t* lhs){

  coeff_t res;

  coeff_t factor;
  // Get Imaginary coefficient.
  res = 0.0;
  // Real;
  switch (order){
    case 0:
      res = lhs->r;
      break;
  }
  return res;

}

void onumm0n0_set_item(coeff_t val, imdir_t idx, ord_t order, onumm0n0_t* x){

  // Set Imaginary coefficient.
  // Real;
  switch (order){
    case 0:
      x->r = val;
      break;
  }
}

onumm0n0_t onumm0n0_copy(  onumm0n0_t* lhs){

  onumm0n0_t res;

  // Assign like function 'lhs'
  // Real;
  res.r = lhs->r;

  return res;

}

void onumm0n0_copy_to(  onumm0n0_t* lhs, onumm0n0_t* res){

  // Assign like function 'lhs'
  // Real;
  res->r = lhs->r;

}

onumm0n0_t onumm0n0_taylor_integrate(coeff_t* deltas,onumm0n0_t* lhs){

  onumm0n0_t res;

  res = onumm0n0_init();
  coeff_t factor;
  // Taylor integration
  // Real;
  res.r = lhs->r;

  return res;

}

void onumm0n0_taylor_integrate_to(coeff_t* deltas,onumm0n0_t* lhs, onumm0n0_t* res){

  *res = onumm0n0_init();
  coeff_t factor;
  // Taylor integration
  // Real;
  res->r = lhs->r;

}

onumm0n0_t onumm0n0_truncate_im(imdir_t idx, ord_t order, onumm0n0_t* lhs){

  onumm0n0_t res;

  // Copy number.
  res = (*lhs);
  // Truncate all other values when necessary.
  // Real;
  switch (order){
    case 0:
      res = onumm0n0_init();
      break;
  }
  return res;

}

void onumm0n0_truncate_im_to(imdir_t idx, ord_t order, onumm0n0_t* lhs, onumm0n0_t* res){

  // Copy number.
  *res = (*lhs);
  // Truncate all other values when necessary.
  // Real;
  switch (order){
    case 0:
      *res = onumm0n0_init();
      break;
  }
}

void onumm0n0_print(  onumm0n0_t* lhs){

  // Print function.
  //  Real;
  printf("%.8g",lhs->r);
  printf("\n");

}

imdir_t onumm0n0_get_indx(imdir_t idx, ord_t order){

  // Real;
  switch (order){
    case 0:
      return 0;
      break;
      default:
          return 0;
  }
  return 0;
}

