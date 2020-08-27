

// Not implemented correctly:
void onumm1n10_set_im_o(onumm1n10_t* num, imdir_t idx, ord_t order, onumm1n10_t* res){
    onumm1n10_set_item(num->r,idx,order,res);
}
void onumm1n10_set_deriv_r(coeff_t num, imdir_t idx, ord_t order, onumm1n10_t* res){
    *res=onumm1n10_init();
}
void onumm1n10_set_deriv_o(onumm1n10_t* num, imdir_t idx, ord_t order, onumm1n10_t* res){
    *res=onumm1n10_init();
}
void onumm1n10_extract_im_to( imdir_t idx, ord_t order, onumm1n10_t* num, onumm1n10_t* res){
    *res=onumm1n10_init();
}
onumm1n10_t onumm1n10_extract_im(imdir_t idx, ord_t order, onumm1n10_t* num){
    onumm1n10_t res = onumm1n10_init();
    return res;
}
onumm1n10_t onumm1n10_extract_deriv(imdir_t idx, ord_t order, onumm1n10_t* num){
    onumm1n10_t res = onumm1n10_init();
    return res;
}
void onumm1n10_extract_deriv_to(imdir_t idx, ord_t order, onumm1n10_t* num, onumm1n10_t* res){
	*res = onumm1n10_init();
}
void onumm1n10_get_im_to_o(imdir_t idx, ord_t order, onumm1n10_t* num, onumm1n10_t* res){
    coeff_t rres = onumm1n10_get_item(idx, order, num);
    onumm1n10_set_r(rres,res);
}
onumm1n10_t onumm1n10_get_im_o(imdir_t idx, ord_t order, onumm1n10_t* num){
    coeff_t rres = onumm1n10_get_item(idx, order, num);
    onumm1n10_t res;
    onumm1n10_set_r(rres,&res);
    return res;
}
void onumm1n10_get_im_to_r(imdir_t idx, ord_t order, onumm1n10_t* num, coeff_t* res){
    *res = onumm1n10_get_item(idx, order, num);
}

inline ord_t onumm1n10_get_order(onumm1n10_t* lhs){

	return 10;

}

onumm1n10_t onumm1n10_get_deriv_o( imdir_t idx, ord_t order, onumm1n10_t* num){

    onumm1n10_t res = onumm1n10_init();

    onumm1n10_get_deriv_to( idx, order, num, &res);
    
    return res;

}

void onumm1n10_get_deriv_to( imdir_t idx, ord_t order, onumm1n10_t* num, onumm1n10_t* res){

    coeff_t deriv = onumm1n10_get_deriv(idx,order,num);

    onumm1n10_set_r( deriv, res);

}

void onumm1n10_set_im_r(coeff_t num, imdir_t idx, ord_t order, onumm1n10_t* res){

    onumm1n10_set_item(num, idx,order,res);

}

onumm1n10_t onumm1n10_init(void){

  onumm1n10_t res;

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

  return res;

}

ndir_t onumm1n10_get_ndir_order(ord_t order, onumm1n10_t* num){

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
  }

  return res;

}

ndir_t onumm1n10_get_ndir_total(onumm1n10_t* num){

  ndir_t res;

  res = 10;

  return res;

}

onumm1n10_t onumm1n10_create_r(  coeff_t lhs){

  onumm1n10_t res;

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

  return res;

}

void onumm1n10_set_r(  coeff_t lhs, onumm1n10_t* res){

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

}

void onumm1n10_set_o(  onumm1n10_t* lhs, onumm1n10_t* res){

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

}

onumm1n10_t onumm1n10_get_order_im(ord_t order, onumm1n10_t* lhs){

  onumm1n10_t res;

  res = onumm1n10_init();
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
  }

  return res;

}

void onumm1n10_get_order_im_to(ord_t order, onumm1n10_t* lhs, onumm1n10_t* res){


  *res = onumm1n10_init();
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
  }

}

coeff_t onumm1n10_get_item(imdir_t idx, ord_t order, onumm1n10_t* lhs){

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
  }
  return res;

}

coeff_t onumm1n10_get_deriv(imdir_t idx, ord_t order, onumm1n10_t* lhs){

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
  }
  return res;

}

void onumm1n10_set_item(coeff_t val, imdir_t idx, ord_t order, onumm1n10_t* x){

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
  }
}

onumm1n10_t onumm1n10_copy(  onumm1n10_t* lhs){

  onumm1n10_t res;

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

  return res;

}

void onumm1n10_copy_to(  onumm1n10_t* lhs, onumm1n10_t* res){

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

}

onumm1n10_t onumm1n10_taylor_integrate(coeff_t* deltas,onumm1n10_t* lhs){

  onumm1n10_t res;

  res = onumm1n10_init();
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

  return res;

}

void onumm1n10_taylor_integrate_to(coeff_t* deltas,onumm1n10_t* lhs, onumm1n10_t* res){

  *res = onumm1n10_init();
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

}

onumm1n10_t onumm1n10_truncate_im(imdir_t idx, ord_t order, onumm1n10_t* lhs){

  onumm1n10_t res;

  // Copy number.
  res = (*lhs);
  // Truncate all other values when necessary.
  // Real;
  switch (order){
    case 0:
      res = onumm1n10_init();
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
          break;
      }
      break;
    case 8:
      switch (idx){
        case 0: //  e11111111
          res.e11111111 = 0.0;
          res.e111111111 = 0.0;
          res.e1111111111 = 0.0;
          break;
      }
      break;
    case 9:
      switch (idx){
        case 0: //  e111111111
          res.e111111111 = 0.0;
          res.e1111111111 = 0.0;
          break;
      }
      break;
    case 10:
      switch (idx){
        case 0: //  e1111111111
          res.e1111111111 = 0.0;
          break;
      }
      break;
  }
  return res;

}

void onumm1n10_truncate_im_to(imdir_t idx, ord_t order, onumm1n10_t* lhs, onumm1n10_t* res){

  // Copy number.
  *res = (*lhs);
  // Truncate all other values when necessary.
  // Real;
  switch (order){
    case 0:
      *res = onumm1n10_init();
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
          break;
      }
      break;
    case 8:
      switch (idx){
        case 0: //  e11111111
          res->e11111111 = 0.0;
          res->e111111111 = 0.0;
          res->e1111111111 = 0.0;
          break;
      }
      break;
    case 9:
      switch (idx){
        case 0: //  e111111111
          res->e111111111 = 0.0;
          res->e1111111111 = 0.0;
          break;
      }
      break;
    case 10:
      switch (idx){
        case 0: //  e1111111111
          res->e1111111111 = 0.0;
          break;
      }
      break;
  }
}

void onumm1n10_print(  onumm1n10_t* lhs){

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
  printf("\n");

}

imdir_t onumm1n10_get_indx(imdir_t idx, ord_t order){

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
      default:
          return 0;
  }
  return 0;
}

