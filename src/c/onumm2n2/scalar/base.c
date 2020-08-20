

// Not implemented correctly:
void onumm2n2_set_im_o(onumm2n2_t* num, imdir_t idx, ord_t order, onumm2n2_t* res){
    onumm2n2_set_item(num->r,idx,order,res);
}
void onumm2n2_set_deriv_r(coeff_t num, imdir_t idx, ord_t order, onumm2n2_t* res){
    *res=onumm2n2_init();
}
void onumm2n2_set_deriv_o(onumm2n2_t* num, imdir_t idx, ord_t order, onumm2n2_t* res){
    *res=onumm2n2_init();
}
void onumm2n2_extract_im_to( imdir_t idx, ord_t order, onumm2n2_t* num, onumm2n2_t* res){
    *res=onumm2n2_init();
}
onumm2n2_t onumm2n2_extract_im(imdir_t idx, ord_t order, onumm2n2_t* num){
    onumm2n2_t res = onumm2n2_init();
    return res;
}
onumm2n2_t onumm2n2_extract_deriv(imdir_t idx, ord_t order, onumm2n2_t* num){
    onumm2n2_t res = onumm2n2_init();
    return res;
}
void onumm2n2_extract_deriv_to(imdir_t idx, ord_t order, onumm2n2_t* num, onumm2n2_t* res){
	*res = onumm2n2_init();
}
void onumm2n2_get_im_to_o(imdir_t idx, ord_t order, onumm2n2_t* num, onumm2n2_t* res){
    coeff_t rres = onumm2n2_get_item(idx, order, num);
    onumm2n2_set_r(rres,res);
}
onumm2n2_t onumm2n2_get_im_o(imdir_t idx, ord_t order, onumm2n2_t* num){
    coeff_t rres = onumm2n2_get_item(idx, order, num);
    onumm2n2_t res;
    onumm2n2_set_r(rres,&res);
    return res;
}
void onumm2n2_get_im_to_r(imdir_t idx, ord_t order, onumm2n2_t* num, coeff_t* res){
    *res = onumm2n2_get_item(idx, order, num);
}

inline ord_t onumm2n2_get_order(onumm2n2_t* lhs){

	return 2;

}

onumm2n2_t onumm2n2_get_deriv_o( imdir_t idx, ord_t order, onumm2n2_t* num){

    onumm2n2_t res = onumm2n2_init();

    onumm2n2_get_deriv_to( idx, order, num, &res);
    
    return res;

}

void onumm2n2_get_deriv_to( imdir_t idx, ord_t order, onumm2n2_t* num, onumm2n2_t* res){

    coeff_t deriv = onumm2n2_get_deriv(idx,order,num);

    onumm2n2_set_r( deriv, res);

}

void onumm2n2_set_im_r(coeff_t num, imdir_t idx, ord_t order, onumm2n2_t* res){

    onumm2n2_set_item(num, idx,order,res);

}

onumm2n2_t onumm2n2_init(void){

  onumm2n2_t res;

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

  return res;

}

ndir_t onumm2n2_get_ndir_order(ord_t order, onumm2n2_t* num){

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
  }

  return res;

}

ndir_t onumm2n2_get_ndir_total(onumm2n2_t* num){

  ndir_t res;

  res = 3;

  return res;

}

onumm2n2_t onumm2n2_create_r(  coeff_t lhs){

  onumm2n2_t res;

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

  return res;

}

void onumm2n2_set_r(  coeff_t lhs, onumm2n2_t* res){

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

}

void onumm2n2_set_o(  onumm2n2_t* lhs, onumm2n2_t* res){

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

}

onumm2n2_t onumm2n2_get_order_im(ord_t order, onumm2n2_t* lhs){

  onumm2n2_t res;

  res = onumm2n2_init();
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
  }

  return res;

}

void onumm2n2_get_order_im_to(ord_t order, onumm2n2_t* lhs, onumm2n2_t* res){


  *res = onumm2n2_init();
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
  }

}

coeff_t onumm2n2_get_item(imdir_t idx, ord_t order, onumm2n2_t* lhs){

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
  }
  return res;

}

coeff_t onumm2n2_get_deriv(imdir_t idx, ord_t order, onumm2n2_t* lhs){

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
  }
  return res;

}

void onumm2n2_set_item(coeff_t val, imdir_t idx, ord_t order, onumm2n2_t* x){

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
  }
}

onumm2n2_t onumm2n2_copy(  onumm2n2_t* lhs){

  onumm2n2_t res;

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

  return res;

}

void onumm2n2_copy_to(  onumm2n2_t* lhs, onumm2n2_t* res){

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

}

onumm2n2_t onumm2n2_taylor_integrate(coeff_t* deltas,onumm2n2_t* lhs){

  onumm2n2_t res;

  coeff_t factor;
  // Taylor integration
  // Real;
  res.r = lhs->r;
  // Order 1;
  factor = pow(deltas[0],1)*pow(deltas[1],0);
  res.e1 = factor*lhs->e1;
  factor = pow(deltas[0],0)*pow(deltas[1],1);
  res.e2 = factor*lhs->e2;
  // Order 2;
  factor = pow(deltas[0],2)*pow(deltas[1],0);
  res.e11 = factor*lhs->e11;
  factor = pow(deltas[0],1)*pow(deltas[1],1);
  res.e12 = factor*lhs->e12;
  factor = pow(deltas[0],0)*pow(deltas[1],2);
  res.e22 = factor*lhs->e22;

  return res;

}

void onumm2n2_taylor_integrate_to(coeff_t* deltas,onumm2n2_t* lhs, onumm2n2_t* res){

  coeff_t factor;
  // Taylor integration
  // Real;
  res->r = lhs->r;
  // Order 1;
  factor = pow(deltas[0],1)*pow(deltas[1],0);
  res->e1 = factor*lhs->e1;
  factor = pow(deltas[0],0)*pow(deltas[1],1);
  res->e2 = factor*lhs->e2;
  // Order 2;
  factor = pow(deltas[0],2)*pow(deltas[1],0);
  res->e11 = factor*lhs->e11;
  factor = pow(deltas[0],1)*pow(deltas[1],1);
  res->e12 = factor*lhs->e12;
  factor = pow(deltas[0],0)*pow(deltas[1],2);
  res->e22 = factor*lhs->e22;

}

onumm2n2_t onumm2n2_truncate_im(imdir_t idx, ord_t order, onumm2n2_t* lhs){

  onumm2n2_t res;

  // Copy number.
  res = (*lhs);
  // Truncate all other values when necessary.
  // Real;
  switch (order){
    case 0:
      res = onumm2n2_init();
      break;
    case 1:
      switch (idx){
        case 0: //  e1
          res.e1 = 0.0;
          res.e11 = 0.0;
          res.e12 = 0.0;
          break;
        case 1: //  e2
          res.e2 = 0.0;
          res.e12 = 0.0;
          res.e22 = 0.0;
          break;
      }
      break;
    case 2:
      switch (idx){
        case 0: //  e11
          res.e11 = 0.0;
          break;
        case 1: //  e12
          res.e12 = 0.0;
          break;
        case 2: //  e22
          res.e22 = 0.0;
          break;
      }
      break;
  }
  return res;

}

void onumm2n2_truncate_im_to(imdir_t idx, ord_t order, onumm2n2_t* lhs, onumm2n2_t* res){

  // Copy number.
  *res = (*lhs);
  // Truncate all other values when necessary.
  // Real;
  switch (order){
    case 0:
      *res = onumm2n2_init();
      break;
    case 1:
      switch (idx){
        case 0: //  e1
          res->e1 = 0.0;
          res->e11 = 0.0;
          res->e12 = 0.0;
          break;
        case 1: //  e2
          res->e2 = 0.0;
          res->e12 = 0.0;
          res->e22 = 0.0;
          break;
      }
      break;
    case 2:
      switch (idx){
        case 0: //  e11
          res->e11 = 0.0;
          break;
        case 1: //  e12
          res->e12 = 0.0;
          break;
        case 2: //  e22
          res->e22 = 0.0;
          break;
      }
      break;
  }
}

void onumm2n2_print(  onumm2n2_t* lhs){

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
  printf("\n");

}

imdir_t onumm2n2_get_indx(imdir_t idx, ord_t order){

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
      default:
          return 0;
  }
  return 0;
}

