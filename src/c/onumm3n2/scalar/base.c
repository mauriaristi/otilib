

// Not implemented correctly:
void onumm3n2_set_im_o(onumm3n2_t* num, imdir_t idx, ord_t order, onumm3n2_t* res){
    *res=onumm3n2_init();
}
void onumm3n2_extract_im_to(onumm3n2_t* num, imdir_t idx, ord_t order, onumm3n2_t* res){
    *res=onumm3n2_init();
}
onumm3n2_t onumm3n2_extract_im(imdir_t idx, ord_t order, onumm3n2_t* num){
    onumm3n2_t res = onumm3n2_init();
    return res;
}
onumm3n2_t onumm3n2_extract_deriv(imdir_t idx, ord_t order, onumm3n2_t* num){
    onumm3n2_t res = onumm3n2_init();
    return res;
}
void onumm3n2_extract_deriv_to(imdir_t idx, ord_t order, onumm3n2_t* num, onumm3n2_t* res){
	*res = onumm3n2_init();
}

inline ord_t onumm3n2_get_order(onumm3n2_t* lhs){

	return 2;

}

onumm3n2_t onumm3n2_get_deriv_o( imdir_t idx, ord_t order, onumm3n2_t* num){

    onumm3n2_t res = onumm3n2_init();

    onumm3n2_get_deriv_to( idx, order, num, &res);
    
    return res;

}

void onumm3n2_get_deriv_to( imdir_t idx, ord_t order, onumm3n2_t* num, onumm3n2_t* res){

    coeff_t deriv = onumm3n2_get_deriv(idx,order,num);

    onumm3n2_set_r( deriv, res);

}

void onumm3n2_set_im_r(coeff_t num, imdir_t idx, ord_t order, onumm3n2_t* res){

    onumm3n2_set_item(num, idx,order,res);

}

onumm3n2_t onumm3n2_init(){

  onumm3n2_t res;

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

  return res;

}

ndir_t onumm3n2_get_ndir_order(ord_t order, onumm3n2_t* num){

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
  }

  return res;

}

ndir_t onumm3n2_get_ndir_total(onumm3n2_t* num){

  ndir_t res;

  res = 4;

  return res;

}

onumm3n2_t onumm3n2_create_r(  coeff_t lhs){

  onumm3n2_t res;

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

  return res;

}

void onumm3n2_set_r(  coeff_t lhs, onumm3n2_t* res){

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

}

void onumm3n2_set_o(  onumm3n2_t* lhs, onumm3n2_t* res){

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

}

onumm3n2_t onumm3n2_get_order_im(ord_t order, onumm3n2_t* lhs){

  onumm3n2_t res;

  res = onumm3n2_init();
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
  }

  return res;

}

void onumm3n2_get_order_im_to(ord_t order, onumm3n2_t* lhs, onumm3n2_t* res){


  *res = onumm3n2_init();
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
  }

}

coeff_t onumm3n2_get_item(imdir_t idx, ord_t order, onumm3n2_t* lhs){

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
  }
  return res;

}

coeff_t onumm3n2_get_deriv(imdir_t idx, ord_t order, onumm3n2_t* lhs){

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
  }
  return res;

}

void onumm3n2_set_item(coeff_t val, imdir_t idx, ord_t order, onumm3n2_t* x){

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
  }
}

onumm3n2_t onumm3n2_copy(  onumm3n2_t* lhs){

  onumm3n2_t res;

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

  return res;

}

void onumm3n2_copy_to(  onumm3n2_t* lhs, onumm3n2_t* res){

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

}

onumm3n2_t onumm3n2_taylor_integrate(coeff_t* deltas,onumm3n2_t* lhs){

  onumm3n2_t res;

  coeff_t factor;
  // Taylor integration
  // Real;
  res.r = lhs->r;
  // Order 1;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],0);
  res.e1 = factor*lhs->e1;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],0);
  res.e2 = factor*lhs->e2;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],1);
  res.e3 = factor*lhs->e3;
  // Order 2;
  factor = pow(deltas[0],2)*pow(deltas[1],0)*pow(deltas[2],0);
  res.e11 = factor*lhs->e11;
  factor = pow(deltas[0],1)*pow(deltas[1],1)*pow(deltas[2],0);
  res.e12 = factor*lhs->e12;
  factor = pow(deltas[0],0)*pow(deltas[1],2)*pow(deltas[2],0);
  res.e22 = factor*lhs->e22;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],1);
  res.e13 = factor*lhs->e13;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],1);
  res.e23 = factor*lhs->e23;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],2);
  res.e33 = factor*lhs->e33;

  return res;

}

void onumm3n2_taylor_integrate_to(coeff_t* deltas,onumm3n2_t* lhs, onumm3n2_t* res){

  coeff_t factor;
  // Taylor integration
  // Real;
  res->r = lhs->r;
  // Order 1;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],0);
  res->e1 = factor*lhs->e1;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],0);
  res->e2 = factor*lhs->e2;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],1);
  res->e3 = factor*lhs->e3;
  // Order 2;
  factor = pow(deltas[0],2)*pow(deltas[1],0)*pow(deltas[2],0);
  res->e11 = factor*lhs->e11;
  factor = pow(deltas[0],1)*pow(deltas[1],1)*pow(deltas[2],0);
  res->e12 = factor*lhs->e12;
  factor = pow(deltas[0],0)*pow(deltas[1],2)*pow(deltas[2],0);
  res->e22 = factor*lhs->e22;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],1);
  res->e13 = factor*lhs->e13;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],1);
  res->e23 = factor*lhs->e23;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],2);
  res->e33 = factor*lhs->e33;

}

onumm3n2_t onumm3n2_truncate_im(imdir_t idx, ord_t order, onumm3n2_t* lhs){

  onumm3n2_t res;

  // Copy number.
  res = (*lhs);
  // Truncate all other values when necessary.
  // Real;
  switch (order){
    case 0:
      res = onumm3n2_init();
      break;
    case 1:
      switch (idx){
        case 0: //  e1
          res.e1 = 0.0;
          res.e11 = 0.0;
          res.e12 = 0.0;
          res.e13 = 0.0;
          break;
        case 1: //  e2
          res.e2 = 0.0;
          res.e12 = 0.0;
          res.e22 = 0.0;
          res.e23 = 0.0;
          break;
        case 2: //  e3
          res.e3 = 0.0;
          res.e13 = 0.0;
          res.e23 = 0.0;
          res.e33 = 0.0;
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
        case 3: //  e13
          res.e13 = 0.0;
          break;
        case 4: //  e23
          res.e23 = 0.0;
          break;
        case 5: //  e33
          res.e33 = 0.0;
          break;
      }
      break;
  }
  return res;

}

void onumm3n2_truncate_im_to(imdir_t idx, ord_t order, onumm3n2_t* lhs, onumm3n2_t* res){

  // Copy number.
  *res = (*lhs);
  // Truncate all other values when necessary.
  // Real;
  switch (order){
    case 0:
      *res = onumm3n2_init();
      break;
    case 1:
      switch (idx){
        case 0: //  e1
          res->e1 = 0.0;
          res->e11 = 0.0;
          res->e12 = 0.0;
          res->e13 = 0.0;
          break;
        case 1: //  e2
          res->e2 = 0.0;
          res->e12 = 0.0;
          res->e22 = 0.0;
          res->e23 = 0.0;
          break;
        case 2: //  e3
          res->e3 = 0.0;
          res->e13 = 0.0;
          res->e23 = 0.0;
          res->e33 = 0.0;
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
        case 3: //  e13
          res->e13 = 0.0;
          break;
        case 4: //  e23
          res->e23 = 0.0;
          break;
        case 5: //  e33
          res->e33 = 0.0;
          break;
      }
      break;
  }
}

void onumm3n2_print(  onumm3n2_t* lhs){

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
  printf("\n");

}

