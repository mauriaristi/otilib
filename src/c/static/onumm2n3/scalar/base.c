

// Not implemented correctly:
void onumm2n3_set_im_o(onumm2n3_t* num, imdir_t idx, ord_t order, onumm2n3_t* res){
    onumm2n3_set_item(num->r,idx,order,res);
}
void onumm2n3_set_deriv_r(coeff_t num, imdir_t idx, ord_t order, onumm2n3_t* res){
    *res=onumm2n3_init();
}
void onumm2n3_set_deriv_o(onumm2n3_t* num, imdir_t idx, ord_t order, onumm2n3_t* res){
    *res=onumm2n3_init();
}
void onumm2n3_extract_im_to( imdir_t idx, ord_t order, onumm2n3_t* num, onumm2n3_t* res){
    *res=onumm2n3_init();
}
onumm2n3_t onumm2n3_extract_im(imdir_t idx, ord_t order, onumm2n3_t* num){
    onumm2n3_t res = onumm2n3_init();
    return res;
}
onumm2n3_t onumm2n3_extract_deriv(imdir_t idx, ord_t order, onumm2n3_t* num){
    onumm2n3_t res = onumm2n3_init();
    return res;
}
void onumm2n3_extract_deriv_to(imdir_t idx, ord_t order, onumm2n3_t* num, onumm2n3_t* res){
	*res = onumm2n3_init();
}
void onumm2n3_get_im_to_o(imdir_t idx, ord_t order, onumm2n3_t* num, onumm2n3_t* res){
    coeff_t rres = onumm2n3_get_item(idx, order, num);
    onumm2n3_set_r(rres,res);
}
onumm2n3_t onumm2n3_get_im_o(imdir_t idx, ord_t order, onumm2n3_t* num){
    coeff_t rres = onumm2n3_get_item(idx, order, num);
    onumm2n3_t res;
    onumm2n3_set_r(rres,&res);
    return res;
}
void onumm2n3_get_im_to_r(imdir_t idx, ord_t order, onumm2n3_t* num, coeff_t* res){
    *res = onumm2n3_get_item(idx, order, num);
}

inline ord_t onumm2n3_get_order(onumm2n3_t* lhs){

	return 3;

}

onumm2n3_t onumm2n3_get_deriv_o( imdir_t idx, ord_t order, onumm2n3_t* num){

    onumm2n3_t res = onumm2n3_init();

    onumm2n3_get_deriv_to( idx, order, num, &res);
    
    return res;

}

void onumm2n3_get_deriv_to( imdir_t idx, ord_t order, onumm2n3_t* num, onumm2n3_t* res){

    coeff_t deriv = onumm2n3_get_deriv(idx,order,num);

    onumm2n3_set_r( deriv, res);

}

void onumm2n3_set_im_r(coeff_t num, imdir_t idx, ord_t order, onumm2n3_t* res){

    onumm2n3_set_item(num, idx,order,res);

}

onumm2n3_t onumm2n3_init(void){

  onumm2n3_t res;

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

  return res;

}

ndir_t onumm2n3_get_ndir_order(ord_t order, onumm2n3_t* num){

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
  }

  return res;

}

ndir_t onumm2n3_get_ndir_total(onumm2n3_t* num){

  ndir_t res;

  res = 6;

  return res;

}

coeff_t* onumm2n3_get_order_address(ord_t order, onumm2n3_t* num){

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
  }
  return res;

}

onumm2n3_t onumm2n3_create_r(  coeff_t lhs){

  onumm2n3_t res;

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

  return res;

}

void onumm2n3_set_r(  coeff_t lhs, onumm2n3_t* res){

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

}

void onumm2n3_set_o(  onumm2n3_t* lhs, onumm2n3_t* res){

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

}

onumm2n3_t onumm2n3_get_order_im(ord_t order, onumm2n3_t* lhs){

  onumm2n3_t res;

  res = onumm2n3_init();
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
  }

  return res;

}

void onumm2n3_get_order_im_to(ord_t order, onumm2n3_t* lhs, onumm2n3_t* res){


  *res = onumm2n3_init();
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
  }

}

coeff_t onumm2n3_get_item(imdir_t idx, ord_t order, onumm2n3_t* lhs){

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
  }
  return res;

}

coeff_t onumm2n3_get_deriv(imdir_t idx, ord_t order, onumm2n3_t* lhs){

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
  }
  return res;

}

void onumm2n3_set_item(coeff_t val, imdir_t idx, ord_t order, onumm2n3_t* x){

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
  }
}

onumm2n3_t onumm2n3_copy(  onumm2n3_t* lhs){

  onumm2n3_t res;

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

  return res;

}

void onumm2n3_copy_to(  onumm2n3_t* lhs, onumm2n3_t* res){

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

}

onumm2n3_t onumm2n3_taylor_integrate(coeff_t* deltas,onumm2n3_t* lhs){

  onumm2n3_t res;

  res = onumm2n3_init();
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

  return res;

}

void onumm2n3_taylor_integrate_to(coeff_t* deltas,onumm2n3_t* lhs, onumm2n3_t* res){

  *res = onumm2n3_init();
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

}

onumm2n3_t onumm2n3_truncate_im(imdir_t idx, ord_t order, onumm2n3_t* lhs){

  onumm2n3_t res;

  // Copy number.
  res = (*lhs);
  // Truncate all other values when necessary.
  // Real;
  switch (order){
    case 0:
      res = onumm2n3_init();
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
          break;
        case 1: //  e2
          res.e2 = 0.0;
          res.e12 = 0.0;
          res.e22 = 0.0;
          res.e112 = 0.0;
          res.e122 = 0.0;
          res.e222 = 0.0;
          break;
      }
      break;
    case 2:
      switch (idx){
        case 0: //  e11
          res.e11 = 0.0;
          res.e111 = 0.0;
          res.e112 = 0.0;
          break;
        case 1: //  e12
          res.e12 = 0.0;
          res.e112 = 0.0;
          res.e122 = 0.0;
          break;
        case 2: //  e22
          res.e22 = 0.0;
          res.e122 = 0.0;
          res.e222 = 0.0;
          break;
      }
      break;
    case 3:
      switch (idx){
        case 0: //  e111
          res.e111 = 0.0;
          break;
        case 1: //  e112
          res.e112 = 0.0;
          break;
        case 2: //  e122
          res.e122 = 0.0;
          break;
        case 3: //  e222
          res.e222 = 0.0;
          break;
      }
      break;
  }
  return res;

}

void onumm2n3_truncate_im_to(imdir_t idx, ord_t order, onumm2n3_t* lhs, onumm2n3_t* res){

  // Copy number.
  *res = (*lhs);
  // Truncate all other values when necessary.
  // Real;
  switch (order){
    case 0:
      *res = onumm2n3_init();
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
          break;
        case 1: //  e2
          res->e2 = 0.0;
          res->e12 = 0.0;
          res->e22 = 0.0;
          res->e112 = 0.0;
          res->e122 = 0.0;
          res->e222 = 0.0;
          break;
      }
      break;
    case 2:
      switch (idx){
        case 0: //  e11
          res->e11 = 0.0;
          res->e111 = 0.0;
          res->e112 = 0.0;
          break;
        case 1: //  e12
          res->e12 = 0.0;
          res->e112 = 0.0;
          res->e122 = 0.0;
          break;
        case 2: //  e22
          res->e22 = 0.0;
          res->e122 = 0.0;
          res->e222 = 0.0;
          break;
      }
      break;
    case 3:
      switch (idx){
        case 0: //  e111
          res->e111 = 0.0;
          break;
        case 1: //  e112
          res->e112 = 0.0;
          break;
        case 2: //  e122
          res->e122 = 0.0;
          break;
        case 3: //  e222
          res->e222 = 0.0;
          break;
      }
      break;
  }
}

void onumm2n3_print(  onumm2n3_t* lhs){

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
  printf("\n");

}

imdir_t onumm2n3_get_indx(imdir_t idx, ord_t order){

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
      default:
          return 0;
  }
  return 0;
}

