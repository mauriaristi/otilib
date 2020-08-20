

// Not implemented correctly:
void mdnum3_set_im_o(mdnum3_t* num, imdir_t idx, ord_t order, mdnum3_t* res){
    mdnum3_set_item(num->r,idx,order,res);
}
void mdnum3_set_deriv_r(coeff_t num, imdir_t idx, ord_t order, mdnum3_t* res){
    *res=mdnum3_init();
}
void mdnum3_set_deriv_o(mdnum3_t* num, imdir_t idx, ord_t order, mdnum3_t* res){
    *res=mdnum3_init();
}
void mdnum3_extract_im_to( imdir_t idx, ord_t order, mdnum3_t* num, mdnum3_t* res){
    *res=mdnum3_init();
}
mdnum3_t mdnum3_extract_im(imdir_t idx, ord_t order, mdnum3_t* num){
    mdnum3_t res = mdnum3_init();
    return res;
}
mdnum3_t mdnum3_extract_deriv(imdir_t idx, ord_t order, mdnum3_t* num){
    mdnum3_t res = mdnum3_init();
    return res;
}
void mdnum3_extract_deriv_to(imdir_t idx, ord_t order, mdnum3_t* num, mdnum3_t* res){
	*res = mdnum3_init();
}
void mdnum3_get_im_to_o(imdir_t idx, ord_t order, mdnum3_t* num, mdnum3_t* res){
    coeff_t rres = mdnum3_get_item(idx, order, num);
    mdnum3_set_r(rres,res);
}
mdnum3_t mdnum3_get_im_o(imdir_t idx, ord_t order, mdnum3_t* num){
    coeff_t rres = mdnum3_get_item(idx, order, num);
    mdnum3_t res;
    mdnum3_set_r(rres,&res);
    return res;
}
void mdnum3_get_im_to_r(imdir_t idx, ord_t order, mdnum3_t* num, coeff_t* res){
    *res = mdnum3_get_item(idx, order, num);
}

inline ord_t mdnum3_get_order(mdnum3_t* lhs){

	return 3;

}

mdnum3_t mdnum3_get_deriv_o( imdir_t idx, ord_t order, mdnum3_t* num){

    mdnum3_t res = mdnum3_init();

    mdnum3_get_deriv_to( idx, order, num, &res);
    
    return res;

}

void mdnum3_get_deriv_to( imdir_t idx, ord_t order, mdnum3_t* num, mdnum3_t* res){

    coeff_t deriv = mdnum3_get_deriv(idx,order,num);

    mdnum3_set_r( deriv, res);

}

void mdnum3_set_im_r(coeff_t num, imdir_t idx, ord_t order, mdnum3_t* res){

    mdnum3_set_item(num, idx,order,res);

}

mdnum3_t mdnum3_init(void){

  mdnum3_t res;

  // Init function
  // Real;
  res.r = 0.0;
  // Order 1;
  res.e1 = 0.0;
  res.e2 = 0.0;
  res.e3 = 0.0;
  // Order 2;
  res.e12 = 0.0;
  res.e13 = 0.0;
  res.e23 = 0.0;
  // Order 3;
  res.e123 = 0.0;

  return res;

}

ndir_t mdnum3_get_ndir_order(ord_t order, mdnum3_t* num){

  ndir_t res;

  switch(order){
    case 0:
      res = 1;
      break;
    case 1:
      res = 3;
      break;
    case 2:
      res = 3;
      break;
    case 3:
      res = 1;
      break;
  }

  return res;

}

ndir_t mdnum3_get_ndir_total(mdnum3_t* num){

  ndir_t res;

  res = 7;

  return res;

}

mdnum3_t mdnum3_create_r(  coeff_t lhs){

  mdnum3_t res;

  // Assign like function 'lhs'
  // Real;
  res.r = lhs;
  // Order 1;
  res.e1 = 0.0;
  res.e2 = 0.0;
  res.e3 = 0.0;
  // Order 2;
  res.e12 = 0.0;
  res.e13 = 0.0;
  res.e23 = 0.0;
  // Order 3;
  res.e123 = 0.0;

  return res;

}

void mdnum3_set_r(  coeff_t lhs, mdnum3_t* res){

  // Assign like function 'lhs'
  // Real;
  res->r = lhs;
  // Order 1;
  res->e1 = 0.0;
  res->e2 = 0.0;
  res->e3 = 0.0;
  // Order 2;
  res->e12 = 0.0;
  res->e13 = 0.0;
  res->e23 = 0.0;
  // Order 3;
  res->e123 = 0.0;

}

void mdnum3_set_o(  mdnum3_t* lhs, mdnum3_t* res){

  // Assign like function 'lhs'
  // Real;
  res->r = lhs->r;
  // Order 1;
  res->e1 = lhs->e1;
  res->e2 = lhs->e2;
  res->e3 = lhs->e3;
  // Order 2;
  res->e12 = lhs->e12;
  res->e13 = lhs->e13;
  res->e23 = lhs->e23;
  // Order 3;
  res->e123 = lhs->e123;

}

mdnum3_t mdnum3_get_order_im(ord_t order, mdnum3_t* lhs){

  mdnum3_t res;

  res = mdnum3_init();
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
      res.e12 = lhs->e12;
      res.e13 = lhs->e13;
      res.e23 = lhs->e23;
      break;
    case 3:
      // Order 3;
      res.e123 = lhs->e123;
      break;
  }

  return res;

}

void mdnum3_get_order_im_to(ord_t order, mdnum3_t* lhs, mdnum3_t* res){


  *res = mdnum3_init();
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
      res->e12 = lhs->e12;
      res->e13 = lhs->e13;
      res->e23 = lhs->e23;
      break;
    case 3:
      // Order 3;
      res->e123 = lhs->e123;
      break;
  }

}

coeff_t mdnum3_get_item(imdir_t idx, ord_t order, mdnum3_t* lhs){

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
        case 1:
          res = lhs->e12;
          break;
        case 3:
          res = lhs->e13;
          break;
        case 4:
          res = lhs->e23;
          break;
      }
      break;
    case 3:
      switch (idx){
        case 5:
          res = lhs->e123;
          break;
      }
      break;
  }
  return res;

}

coeff_t mdnum3_get_deriv(imdir_t idx, ord_t order, mdnum3_t* lhs){

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
        case 1:
          factor = 1.0000000000000000e+00;
          res = lhs->e12*factor;
          break;
        case 3:
          factor = 1.0000000000000000e+00;
          res = lhs->e13*factor;
          break;
        case 4:
          factor = 1.0000000000000000e+00;
          res = lhs->e23*factor;
          break;
      }
      break;
    case 3:
      switch (idx){
        case 5:
          factor = 1.0000000000000000e+00;
          res = lhs->e123*factor;
          break;
      }
      break;
  }
  return res;

}

void mdnum3_set_item(coeff_t val, imdir_t idx, ord_t order, mdnum3_t* x){

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
        case 1:
          x->e12 = val;
          break;
        case 3:
          x->e13 = val;
          break;
        case 4:
          x->e23 = val;
          break;
      }
      break;
    case 3:
      switch (idx){
        case 5:
          x->e123 = val;
          break;
      }
      break;
  }
}

mdnum3_t mdnum3_copy(  mdnum3_t* lhs){

  mdnum3_t res;

  // Assign like function 'lhs'
  // Real;
  res.r = lhs->r;
  // Order 1;
  res.e1 = lhs->e1;
  res.e2 = lhs->e2;
  res.e3 = lhs->e3;
  // Order 2;
  res.e12 = lhs->e12;
  res.e13 = lhs->e13;
  res.e23 = lhs->e23;
  // Order 3;
  res.e123 = lhs->e123;

  return res;

}

void mdnum3_copy_to(  mdnum3_t* lhs, mdnum3_t* res){

  // Assign like function 'lhs'
  // Real;
  res->r = lhs->r;
  // Order 1;
  res->e1 = lhs->e1;
  res->e2 = lhs->e2;
  res->e3 = lhs->e3;
  // Order 2;
  res->e12 = lhs->e12;
  res->e13 = lhs->e13;
  res->e23 = lhs->e23;
  // Order 3;
  res->e123 = lhs->e123;

}

mdnum3_t mdnum3_taylor_integrate(coeff_t* deltas,mdnum3_t* lhs){

  mdnum3_t res;

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
  factor = pow(deltas[0],1)*pow(deltas[1],1)*pow(deltas[2],0);
  res.e12 = factor*lhs->e12;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],1);
  res.e13 = factor*lhs->e13;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],1);
  res.e23 = factor*lhs->e23;
  // Order 3;
  factor = pow(deltas[0],1)*pow(deltas[1],1)*pow(deltas[2],1);
  res.e123 = factor*lhs->e123;

  return res;

}

void mdnum3_taylor_integrate_to(coeff_t* deltas,mdnum3_t* lhs, mdnum3_t* res){

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
  factor = pow(deltas[0],1)*pow(deltas[1],1)*pow(deltas[2],0);
  res->e12 = factor*lhs->e12;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],1);
  res->e13 = factor*lhs->e13;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],1);
  res->e23 = factor*lhs->e23;
  // Order 3;
  factor = pow(deltas[0],1)*pow(deltas[1],1)*pow(deltas[2],1);
  res->e123 = factor*lhs->e123;

}

mdnum3_t mdnum3_truncate_im(imdir_t idx, ord_t order, mdnum3_t* lhs){

  mdnum3_t res;

  // Copy number.
  res = (*lhs);
  // Truncate all other values when necessary.
  // Real;
  switch (order){
    case 0:
      res = mdnum3_init();
      break;
    case 1:
      switch (idx){
        case 0: //  e1
          res.e1 = 0.0;
          res.e12 = 0.0;
          res.e13 = 0.0;
          res.e123 = 0.0;
          break;
        case 1: //  e2
          res.e2 = 0.0;
          res.e12 = 0.0;
          res.e23 = 0.0;
          res.e123 = 0.0;
          break;
        case 2: //  e3
          res.e3 = 0.0;
          res.e13 = 0.0;
          res.e23 = 0.0;
          res.e123 = 0.0;
          break;
      }
      break;
    case 2:
      switch (idx){
        case 1: //  e12
          res.e12 = 0.0;
          res.e123 = 0.0;
          break;
        case 3: //  e13
          res.e13 = 0.0;
          res.e123 = 0.0;
          break;
        case 4: //  e23
          res.e23 = 0.0;
          res.e123 = 0.0;
          break;
      }
      break;
    case 3:
      switch (idx){
        case 5: //  e123
          res.e123 = 0.0;
          break;
      }
      break;
  }
  return res;

}

void mdnum3_truncate_im_to(imdir_t idx, ord_t order, mdnum3_t* lhs, mdnum3_t* res){

  // Copy number.
  *res = (*lhs);
  // Truncate all other values when necessary.
  // Real;
  switch (order){
    case 0:
      *res = mdnum3_init();
      break;
    case 1:
      switch (idx){
        case 0: //  e1
          res->e1 = 0.0;
          res->e12 = 0.0;
          res->e13 = 0.0;
          res->e123 = 0.0;
          break;
        case 1: //  e2
          res->e2 = 0.0;
          res->e12 = 0.0;
          res->e23 = 0.0;
          res->e123 = 0.0;
          break;
        case 2: //  e3
          res->e3 = 0.0;
          res->e13 = 0.0;
          res->e23 = 0.0;
          res->e123 = 0.0;
          break;
      }
      break;
    case 2:
      switch (idx){
        case 1: //  e12
          res->e12 = 0.0;
          res->e123 = 0.0;
          break;
        case 3: //  e13
          res->e13 = 0.0;
          res->e123 = 0.0;
          break;
        case 4: //  e23
          res->e23 = 0.0;
          res->e123 = 0.0;
          break;
      }
      break;
    case 3:
      switch (idx){
        case 5: //  e123
          res->e123 = 0.0;
          break;
      }
      break;
  }
}

void mdnum3_print(  mdnum3_t* lhs){

  // Print function.
  //  Real;
  printf("%.8g",lhs->r);
  //  Order 1;
  printf(" %+.8g*e1",lhs->e1);
  printf(" %+.8g*e2",lhs->e2);
  printf(" %+.8g*e3",lhs->e3);
  //  Order 2;
  printf(" %+.8g*e12",lhs->e12);
  printf(" %+.8g*e13",lhs->e13);
  printf(" %+.8g*e23",lhs->e23);
  //  Order 3;
  printf(" %+.8g*e123",lhs->e123);
  printf("\n");

}

imdir_t mdnum3_get_indx(imdir_t idx, ord_t order){

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
          return 1;
          break;
        case 1:
          return 3;
          break;
        case 2:
          return 4;
          break;
      }
      break;
    case 3:
      switch (idx){
        case 0:
          return 5;
          break;
      }
      break;
      default:
          return 0;
  }
  return 0;
}

