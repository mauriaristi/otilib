

// Not implemented correctly:
void onumm1n4_set_im_o(onumm1n4_t* num, imdir_t idx, ord_t order, onumm1n4_t* res){
    onumm1n4_set_item(num->r,idx,order,res);
}
void onumm1n4_set_deriv_r(coeff_t num, imdir_t idx, ord_t order, onumm1n4_t* res){
    *res=onumm1n4_init();
}
void onumm1n4_set_deriv_o(onumm1n4_t* num, imdir_t idx, ord_t order, onumm1n4_t* res){
    *res=onumm1n4_init();
}
void onumm1n4_extract_im_to( imdir_t idx, ord_t order, onumm1n4_t* num, onumm1n4_t* res){
    *res=onumm1n4_init();
}
onumm1n4_t onumm1n4_extract_im(imdir_t idx, ord_t order, onumm1n4_t* num){
    onumm1n4_t res = onumm1n4_init();
    return res;
}
onumm1n4_t onumm1n4_extract_deriv(imdir_t idx, ord_t order, onumm1n4_t* num){
    onumm1n4_t res = onumm1n4_init();
    return res;
}
void onumm1n4_extract_deriv_to(imdir_t idx, ord_t order, onumm1n4_t* num, onumm1n4_t* res){
	*res = onumm1n4_init();
}
void onumm1n4_get_im_to_o(imdir_t idx, ord_t order, onumm1n4_t* num, onumm1n4_t* res){
    coeff_t rres = onumm1n4_get_item(idx, order, num);
    onumm1n4_set_r(rres,res);
}
onumm1n4_t onumm1n4_get_im_o(imdir_t idx, ord_t order, onumm1n4_t* num){
    coeff_t rres = onumm1n4_get_item(idx, order, num);
    onumm1n4_t res;
    onumm1n4_set_r(rres,&res);
    return res;
}
void onumm1n4_get_im_to_r(imdir_t idx, ord_t order, onumm1n4_t* num, coeff_t* res){
    *res = onumm1n4_get_item(idx, order, num);
}

inline ord_t onumm1n4_get_order(onumm1n4_t* lhs){

	return 4;

}

onumm1n4_t onumm1n4_get_deriv_o( imdir_t idx, ord_t order, onumm1n4_t* num){

    onumm1n4_t res = onumm1n4_init();

    onumm1n4_get_deriv_to( idx, order, num, &res);
    
    return res;

}

void onumm1n4_get_deriv_to( imdir_t idx, ord_t order, onumm1n4_t* num, onumm1n4_t* res){

    coeff_t deriv = onumm1n4_get_deriv(idx,order,num);

    onumm1n4_set_r( deriv, res);

}

void onumm1n4_set_im_r(coeff_t num, imdir_t idx, ord_t order, onumm1n4_t* res){

    onumm1n4_set_item(num, idx,order,res);

}

onumm1n4_t onumm1n4_init(void){

  onumm1n4_t res;

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

  return res;

}

ndir_t onumm1n4_get_ndir_order(ord_t order, onumm1n4_t* num){

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
  }

  return res;

}

ndir_t onumm1n4_get_ndir_total(onumm1n4_t* num){

  ndir_t res;

  res = 4;

  return res;

}

coeff_t* onumm1n4_get_order_address(ord_t order, onumm1n4_t* num){

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

onumm1n4_t onumm1n4_create_r(  coeff_t lhs){

  onumm1n4_t res;

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

  return res;

}

void onumm1n4_set_r(  coeff_t lhs, onumm1n4_t* res){

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

}

void onumm1n4_set_o(  onumm1n4_t* lhs, onumm1n4_t* res){

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

}

onumm1n4_t onumm1n4_get_order_im(ord_t order, onumm1n4_t* lhs){

  onumm1n4_t res;

  res = onumm1n4_init();
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
  }

  return res;

}

void onumm1n4_get_order_im_to(ord_t order, onumm1n4_t* lhs, onumm1n4_t* res){


  *res = onumm1n4_init();
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
  }

}

coeff_t onumm1n4_get_item(imdir_t idx, ord_t order, onumm1n4_t* lhs){

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
  }
  return res;

}

coeff_t onumm1n4_get_deriv(imdir_t idx, ord_t order, onumm1n4_t* lhs){

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
  }
  return res;

}

void onumm1n4_set_item(coeff_t val, imdir_t idx, ord_t order, onumm1n4_t* x){

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
  }
}

onumm1n4_t onumm1n4_copy(  onumm1n4_t* lhs){

  onumm1n4_t res;

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

  return res;

}

void onumm1n4_copy_to(  onumm1n4_t* lhs, onumm1n4_t* res){

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

}

onumm1n4_t onumm1n4_taylor_integrate(coeff_t* deltas,onumm1n4_t* lhs){

  onumm1n4_t res;

  res = onumm1n4_init();
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

  return res;

}

void onumm1n4_taylor_integrate_to(coeff_t* deltas,onumm1n4_t* lhs, onumm1n4_t* res){

  *res = onumm1n4_init();
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

}

onumm1n4_t onumm1n4_truncate_im(imdir_t idx, ord_t order, onumm1n4_t* lhs){

  onumm1n4_t res;

  // Copy number.
  res = (*lhs);
  // Truncate all other values when necessary.
  // Real;
  switch (order){
    case 0:
      res = onumm1n4_init();
      break;
    case 1:
      switch (idx){
        case 0: //  e1
          res.e1 = 0.0;
          res.e11 = 0.0;
          res.e111 = 0.0;
          res.e1111 = 0.0;
          break;
      }
      break;
    case 2:
      switch (idx){
        case 0: //  e11
          res.e11 = 0.0;
          res.e111 = 0.0;
          res.e1111 = 0.0;
          break;
      }
      break;
    case 3:
      switch (idx){
        case 0: //  e111
          res.e111 = 0.0;
          res.e1111 = 0.0;
          break;
      }
      break;
    case 4:
      switch (idx){
        case 0: //  e1111
          res.e1111 = 0.0;
          break;
      }
      break;
  }
  return res;

}

void onumm1n4_truncate_im_to(imdir_t idx, ord_t order, onumm1n4_t* lhs, onumm1n4_t* res){

  // Copy number.
  *res = (*lhs);
  // Truncate all other values when necessary.
  // Real;
  switch (order){
    case 0:
      *res = onumm1n4_init();
      break;
    case 1:
      switch (idx){
        case 0: //  e1
          res->e1 = 0.0;
          res->e11 = 0.0;
          res->e111 = 0.0;
          res->e1111 = 0.0;
          break;
      }
      break;
    case 2:
      switch (idx){
        case 0: //  e11
          res->e11 = 0.0;
          res->e111 = 0.0;
          res->e1111 = 0.0;
          break;
      }
      break;
    case 3:
      switch (idx){
        case 0: //  e111
          res->e111 = 0.0;
          res->e1111 = 0.0;
          break;
      }
      break;
    case 4:
      switch (idx){
        case 0: //  e1111
          res->e1111 = 0.0;
          break;
      }
      break;
  }
}

void onumm1n4_print(  onumm1n4_t* lhs){

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
  printf("\n");

}

imdir_t onumm1n4_get_indx(imdir_t idx, ord_t order){

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
      default:
          return 0;
  }
  return 0;
}

