

// Not implemented correctly:
void onumm9n2_set_im_o(onumm9n2_t* num, imdir_t idx, ord_t order, onumm9n2_t* res){
    onumm9n2_set_item(num->r,idx,order,res);
}
void onumm9n2_set_deriv_r(coeff_t num, imdir_t idx, ord_t order, onumm9n2_t* res){
    *res=onumm9n2_init();
}
void onumm9n2_set_deriv_o(onumm9n2_t* num, imdir_t idx, ord_t order, onumm9n2_t* res){
    *res=onumm9n2_init();
}
void onumm9n2_extract_im_to( imdir_t idx, ord_t order, onumm9n2_t* num, onumm9n2_t* res){
    *res=onumm9n2_init();
}
onumm9n2_t onumm9n2_extract_im(imdir_t idx, ord_t order, onumm9n2_t* num){
    onumm9n2_t res = onumm9n2_init();
    return res;
}
onumm9n2_t onumm9n2_extract_deriv(imdir_t idx, ord_t order, onumm9n2_t* num){
    onumm9n2_t res = onumm9n2_init();
    return res;
}
void onumm9n2_extract_deriv_to(imdir_t idx, ord_t order, onumm9n2_t* num, onumm9n2_t* res){
	*res = onumm9n2_init();
}
void onumm9n2_get_im_to_o(imdir_t idx, ord_t order, onumm9n2_t* num, onumm9n2_t* res){
    coeff_t rres = onumm9n2_get_item(idx, order, num);
    onumm9n2_set_r(rres,res);
}
onumm9n2_t onumm9n2_get_im_o(imdir_t idx, ord_t order, onumm9n2_t* num){
    coeff_t rres = onumm9n2_get_item(idx, order, num);
    onumm9n2_t res;
    onumm9n2_set_r(rres,&res);
    return res;
}
void onumm9n2_get_im_to_r(imdir_t idx, ord_t order, onumm9n2_t* num, coeff_t* res){
    *res = onumm9n2_get_item(idx, order, num);
}

inline ord_t onumm9n2_get_order(onumm9n2_t* lhs){

	return 2;

}

onumm9n2_t onumm9n2_get_deriv_o( imdir_t idx, ord_t order, onumm9n2_t* num){

    onumm9n2_t res = onumm9n2_init();

    onumm9n2_get_deriv_to( idx, order, num, &res);
    
    return res;

}

void onumm9n2_get_deriv_to( imdir_t idx, ord_t order, onumm9n2_t* num, onumm9n2_t* res){

    coeff_t deriv = onumm9n2_get_deriv(idx,order,num);

    onumm9n2_set_r( deriv, res);

}

void onumm9n2_set_im_r(coeff_t num, imdir_t idx, ord_t order, onumm9n2_t* res){

    onumm9n2_set_item(num, idx,order,res);

}

onumm9n2_t onumm9n2_init(void){

  onumm9n2_t res;

  // Init function
  // Real;
  res.r = 0.0;
  // Order 1;
  res.e1 = 0.0;
  res.e2 = 0.0;
  res.e3 = 0.0;
  res.e4 = 0.0;
  res.e5 = 0.0;
  res.e6 = 0.0;
  res.e7 = 0.0;
  res.e8 = 0.0;
  res.e9 = 0.0;
  // Order 2;
  res.e11 = 0.0;
  res.e12 = 0.0;
  res.e22 = 0.0;
  res.e13 = 0.0;
  res.e23 = 0.0;
  res.e33 = 0.0;
  res.e14 = 0.0;
  res.e24 = 0.0;
  res.e34 = 0.0;
  res.e44 = 0.0;
  res.e15 = 0.0;
  res.e25 = 0.0;
  res.e35 = 0.0;
  res.e45 = 0.0;
  res.e55 = 0.0;
  res.e16 = 0.0;
  res.e26 = 0.0;
  res.e36 = 0.0;
  res.e46 = 0.0;
  res.e56 = 0.0;
  res.e66 = 0.0;
  res.e17 = 0.0;
  res.e27 = 0.0;
  res.e37 = 0.0;
  res.e47 = 0.0;
  res.e57 = 0.0;
  res.e67 = 0.0;
  res.e77 = 0.0;
  res.e18 = 0.0;
  res.e28 = 0.0;
  res.e38 = 0.0;
  res.e48 = 0.0;
  res.e58 = 0.0;
  res.e68 = 0.0;
  res.e78 = 0.0;
  res.e88 = 0.0;
  res.e19 = 0.0;
  res.e29 = 0.0;
  res.e39 = 0.0;
  res.e49 = 0.0;
  res.e59 = 0.0;
  res.e69 = 0.0;
  res.e79 = 0.0;
  res.e89 = 0.0;
  res.e99 = 0.0;

  return res;

}

ndir_t onumm9n2_get_ndir_order(ord_t order, onumm9n2_t* num){

  ndir_t res;

  switch(order){
    case 0:
      res = 1;
      break;
    case 1:
      res = 9;
      break;
    case 2:
      res = 45;
      break;
  }

  return res;

}

ndir_t onumm9n2_get_ndir_total(onumm9n2_t* num){

  ndir_t res;

  res = 10;

  return res;

}

coeff_t* onumm9n2_get_order_address(ord_t order, onumm9n2_t* num){

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
  }
  return res;

}

onumm9n2_t onumm9n2_create_r(  coeff_t lhs){

  onumm9n2_t res;

  // Assign like function 'lhs'
  // Real;
  res.r = lhs;
  // Order 1;
  res.e1 = 0.0;
  res.e2 = 0.0;
  res.e3 = 0.0;
  res.e4 = 0.0;
  res.e5 = 0.0;
  res.e6 = 0.0;
  res.e7 = 0.0;
  res.e8 = 0.0;
  res.e9 = 0.0;
  // Order 2;
  res.e11 = 0.0;
  res.e12 = 0.0;
  res.e22 = 0.0;
  res.e13 = 0.0;
  res.e23 = 0.0;
  res.e33 = 0.0;
  res.e14 = 0.0;
  res.e24 = 0.0;
  res.e34 = 0.0;
  res.e44 = 0.0;
  res.e15 = 0.0;
  res.e25 = 0.0;
  res.e35 = 0.0;
  res.e45 = 0.0;
  res.e55 = 0.0;
  res.e16 = 0.0;
  res.e26 = 0.0;
  res.e36 = 0.0;
  res.e46 = 0.0;
  res.e56 = 0.0;
  res.e66 = 0.0;
  res.e17 = 0.0;
  res.e27 = 0.0;
  res.e37 = 0.0;
  res.e47 = 0.0;
  res.e57 = 0.0;
  res.e67 = 0.0;
  res.e77 = 0.0;
  res.e18 = 0.0;
  res.e28 = 0.0;
  res.e38 = 0.0;
  res.e48 = 0.0;
  res.e58 = 0.0;
  res.e68 = 0.0;
  res.e78 = 0.0;
  res.e88 = 0.0;
  res.e19 = 0.0;
  res.e29 = 0.0;
  res.e39 = 0.0;
  res.e49 = 0.0;
  res.e59 = 0.0;
  res.e69 = 0.0;
  res.e79 = 0.0;
  res.e89 = 0.0;
  res.e99 = 0.0;

  return res;

}

void onumm9n2_set_r(  coeff_t lhs, onumm9n2_t* res){

  // Assign like function 'lhs'
  // Real;
  res->r = lhs;
  // Order 1;
  res->e1 = 0.0;
  res->e2 = 0.0;
  res->e3 = 0.0;
  res->e4 = 0.0;
  res->e5 = 0.0;
  res->e6 = 0.0;
  res->e7 = 0.0;
  res->e8 = 0.0;
  res->e9 = 0.0;
  // Order 2;
  res->e11 = 0.0;
  res->e12 = 0.0;
  res->e22 = 0.0;
  res->e13 = 0.0;
  res->e23 = 0.0;
  res->e33 = 0.0;
  res->e14 = 0.0;
  res->e24 = 0.0;
  res->e34 = 0.0;
  res->e44 = 0.0;
  res->e15 = 0.0;
  res->e25 = 0.0;
  res->e35 = 0.0;
  res->e45 = 0.0;
  res->e55 = 0.0;
  res->e16 = 0.0;
  res->e26 = 0.0;
  res->e36 = 0.0;
  res->e46 = 0.0;
  res->e56 = 0.0;
  res->e66 = 0.0;
  res->e17 = 0.0;
  res->e27 = 0.0;
  res->e37 = 0.0;
  res->e47 = 0.0;
  res->e57 = 0.0;
  res->e67 = 0.0;
  res->e77 = 0.0;
  res->e18 = 0.0;
  res->e28 = 0.0;
  res->e38 = 0.0;
  res->e48 = 0.0;
  res->e58 = 0.0;
  res->e68 = 0.0;
  res->e78 = 0.0;
  res->e88 = 0.0;
  res->e19 = 0.0;
  res->e29 = 0.0;
  res->e39 = 0.0;
  res->e49 = 0.0;
  res->e59 = 0.0;
  res->e69 = 0.0;
  res->e79 = 0.0;
  res->e89 = 0.0;
  res->e99 = 0.0;

}

void onumm9n2_set_o(  onumm9n2_t* lhs, onumm9n2_t* res){

  // Assign like function 'lhs'
  // Real;
  res->r = lhs->r;
  // Order 1;
  res->e1 = lhs->e1;
  res->e2 = lhs->e2;
  res->e3 = lhs->e3;
  res->e4 = lhs->e4;
  res->e5 = lhs->e5;
  res->e6 = lhs->e6;
  res->e7 = lhs->e7;
  res->e8 = lhs->e8;
  res->e9 = lhs->e9;
  // Order 2;
  res->e11 = lhs->e11;
  res->e12 = lhs->e12;
  res->e22 = lhs->e22;
  res->e13 = lhs->e13;
  res->e23 = lhs->e23;
  res->e33 = lhs->e33;
  res->e14 = lhs->e14;
  res->e24 = lhs->e24;
  res->e34 = lhs->e34;
  res->e44 = lhs->e44;
  res->e15 = lhs->e15;
  res->e25 = lhs->e25;
  res->e35 = lhs->e35;
  res->e45 = lhs->e45;
  res->e55 = lhs->e55;
  res->e16 = lhs->e16;
  res->e26 = lhs->e26;
  res->e36 = lhs->e36;
  res->e46 = lhs->e46;
  res->e56 = lhs->e56;
  res->e66 = lhs->e66;
  res->e17 = lhs->e17;
  res->e27 = lhs->e27;
  res->e37 = lhs->e37;
  res->e47 = lhs->e47;
  res->e57 = lhs->e57;
  res->e67 = lhs->e67;
  res->e77 = lhs->e77;
  res->e18 = lhs->e18;
  res->e28 = lhs->e28;
  res->e38 = lhs->e38;
  res->e48 = lhs->e48;
  res->e58 = lhs->e58;
  res->e68 = lhs->e68;
  res->e78 = lhs->e78;
  res->e88 = lhs->e88;
  res->e19 = lhs->e19;
  res->e29 = lhs->e29;
  res->e39 = lhs->e39;
  res->e49 = lhs->e49;
  res->e59 = lhs->e59;
  res->e69 = lhs->e69;
  res->e79 = lhs->e79;
  res->e89 = lhs->e89;
  res->e99 = lhs->e99;

}

onumm9n2_t onumm9n2_get_order_im(ord_t order, onumm9n2_t* lhs){

  onumm9n2_t res;

  res = onumm9n2_init();
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
      res.e4 = lhs->e4;
      res.e5 = lhs->e5;
      res.e6 = lhs->e6;
      res.e7 = lhs->e7;
      res.e8 = lhs->e8;
      res.e9 = lhs->e9;
      break;
    case 2:
      // Order 2;
      res.e11 = lhs->e11;
      res.e12 = lhs->e12;
      res.e22 = lhs->e22;
      res.e13 = lhs->e13;
      res.e23 = lhs->e23;
      res.e33 = lhs->e33;
      res.e14 = lhs->e14;
      res.e24 = lhs->e24;
      res.e34 = lhs->e34;
      res.e44 = lhs->e44;
      res.e15 = lhs->e15;
      res.e25 = lhs->e25;
      res.e35 = lhs->e35;
      res.e45 = lhs->e45;
      res.e55 = lhs->e55;
      res.e16 = lhs->e16;
      res.e26 = lhs->e26;
      res.e36 = lhs->e36;
      res.e46 = lhs->e46;
      res.e56 = lhs->e56;
      res.e66 = lhs->e66;
      res.e17 = lhs->e17;
      res.e27 = lhs->e27;
      res.e37 = lhs->e37;
      res.e47 = lhs->e47;
      res.e57 = lhs->e57;
      res.e67 = lhs->e67;
      res.e77 = lhs->e77;
      res.e18 = lhs->e18;
      res.e28 = lhs->e28;
      res.e38 = lhs->e38;
      res.e48 = lhs->e48;
      res.e58 = lhs->e58;
      res.e68 = lhs->e68;
      res.e78 = lhs->e78;
      res.e88 = lhs->e88;
      res.e19 = lhs->e19;
      res.e29 = lhs->e29;
      res.e39 = lhs->e39;
      res.e49 = lhs->e49;
      res.e59 = lhs->e59;
      res.e69 = lhs->e69;
      res.e79 = lhs->e79;
      res.e89 = lhs->e89;
      res.e99 = lhs->e99;
      break;
  }

  return res;

}

void onumm9n2_get_order_im_to(ord_t order, onumm9n2_t* lhs, onumm9n2_t* res){


  *res = onumm9n2_init();
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
      res->e4 = lhs->e4;
      res->e5 = lhs->e5;
      res->e6 = lhs->e6;
      res->e7 = lhs->e7;
      res->e8 = lhs->e8;
      res->e9 = lhs->e9;
      break;
    case 2:
      // Order 2;
      res->e11 = lhs->e11;
      res->e12 = lhs->e12;
      res->e22 = lhs->e22;
      res->e13 = lhs->e13;
      res->e23 = lhs->e23;
      res->e33 = lhs->e33;
      res->e14 = lhs->e14;
      res->e24 = lhs->e24;
      res->e34 = lhs->e34;
      res->e44 = lhs->e44;
      res->e15 = lhs->e15;
      res->e25 = lhs->e25;
      res->e35 = lhs->e35;
      res->e45 = lhs->e45;
      res->e55 = lhs->e55;
      res->e16 = lhs->e16;
      res->e26 = lhs->e26;
      res->e36 = lhs->e36;
      res->e46 = lhs->e46;
      res->e56 = lhs->e56;
      res->e66 = lhs->e66;
      res->e17 = lhs->e17;
      res->e27 = lhs->e27;
      res->e37 = lhs->e37;
      res->e47 = lhs->e47;
      res->e57 = lhs->e57;
      res->e67 = lhs->e67;
      res->e77 = lhs->e77;
      res->e18 = lhs->e18;
      res->e28 = lhs->e28;
      res->e38 = lhs->e38;
      res->e48 = lhs->e48;
      res->e58 = lhs->e58;
      res->e68 = lhs->e68;
      res->e78 = lhs->e78;
      res->e88 = lhs->e88;
      res->e19 = lhs->e19;
      res->e29 = lhs->e29;
      res->e39 = lhs->e39;
      res->e49 = lhs->e49;
      res->e59 = lhs->e59;
      res->e69 = lhs->e69;
      res->e79 = lhs->e79;
      res->e89 = lhs->e89;
      res->e99 = lhs->e99;
      break;
  }

}

coeff_t onumm9n2_get_item(imdir_t idx, ord_t order, onumm9n2_t* lhs){

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
        case 3:
          res = lhs->e4;
          break;
        case 4:
          res = lhs->e5;
          break;
        case 5:
          res = lhs->e6;
          break;
        case 6:
          res = lhs->e7;
          break;
        case 7:
          res = lhs->e8;
          break;
        case 8:
          res = lhs->e9;
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
        case 6:
          res = lhs->e14;
          break;
        case 7:
          res = lhs->e24;
          break;
        case 8:
          res = lhs->e34;
          break;
        case 9:
          res = lhs->e44;
          break;
        case 10:
          res = lhs->e15;
          break;
        case 11:
          res = lhs->e25;
          break;
        case 12:
          res = lhs->e35;
          break;
        case 13:
          res = lhs->e45;
          break;
        case 14:
          res = lhs->e55;
          break;
        case 15:
          res = lhs->e16;
          break;
        case 16:
          res = lhs->e26;
          break;
        case 17:
          res = lhs->e36;
          break;
        case 18:
          res = lhs->e46;
          break;
        case 19:
          res = lhs->e56;
          break;
        case 20:
          res = lhs->e66;
          break;
        case 21:
          res = lhs->e17;
          break;
        case 22:
          res = lhs->e27;
          break;
        case 23:
          res = lhs->e37;
          break;
        case 24:
          res = lhs->e47;
          break;
        case 25:
          res = lhs->e57;
          break;
        case 26:
          res = lhs->e67;
          break;
        case 27:
          res = lhs->e77;
          break;
        case 28:
          res = lhs->e18;
          break;
        case 29:
          res = lhs->e28;
          break;
        case 30:
          res = lhs->e38;
          break;
        case 31:
          res = lhs->e48;
          break;
        case 32:
          res = lhs->e58;
          break;
        case 33:
          res = lhs->e68;
          break;
        case 34:
          res = lhs->e78;
          break;
        case 35:
          res = lhs->e88;
          break;
        case 36:
          res = lhs->e19;
          break;
        case 37:
          res = lhs->e29;
          break;
        case 38:
          res = lhs->e39;
          break;
        case 39:
          res = lhs->e49;
          break;
        case 40:
          res = lhs->e59;
          break;
        case 41:
          res = lhs->e69;
          break;
        case 42:
          res = lhs->e79;
          break;
        case 43:
          res = lhs->e89;
          break;
        case 44:
          res = lhs->e99;
          break;
      }
      break;
  }
  return res;

}

coeff_t onumm9n2_get_deriv(imdir_t idx, ord_t order, onumm9n2_t* lhs){

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
        case 3:
          factor = 1.0000000000000000e+00;
          res = lhs->e4*factor;
          break;
        case 4:
          factor = 1.0000000000000000e+00;
          res = lhs->e5*factor;
          break;
        case 5:
          factor = 1.0000000000000000e+00;
          res = lhs->e6*factor;
          break;
        case 6:
          factor = 1.0000000000000000e+00;
          res = lhs->e7*factor;
          break;
        case 7:
          factor = 1.0000000000000000e+00;
          res = lhs->e8*factor;
          break;
        case 8:
          factor = 1.0000000000000000e+00;
          res = lhs->e9*factor;
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
        case 6:
          factor = 1.0000000000000000e+00;
          res = lhs->e14*factor;
          break;
        case 7:
          factor = 1.0000000000000000e+00;
          res = lhs->e24*factor;
          break;
        case 8:
          factor = 1.0000000000000000e+00;
          res = lhs->e34*factor;
          break;
        case 9:
          factor = 2.0000000000000000e+00;
          res = lhs->e44*factor;
          break;
        case 10:
          factor = 1.0000000000000000e+00;
          res = lhs->e15*factor;
          break;
        case 11:
          factor = 1.0000000000000000e+00;
          res = lhs->e25*factor;
          break;
        case 12:
          factor = 1.0000000000000000e+00;
          res = lhs->e35*factor;
          break;
        case 13:
          factor = 1.0000000000000000e+00;
          res = lhs->e45*factor;
          break;
        case 14:
          factor = 2.0000000000000000e+00;
          res = lhs->e55*factor;
          break;
        case 15:
          factor = 1.0000000000000000e+00;
          res = lhs->e16*factor;
          break;
        case 16:
          factor = 1.0000000000000000e+00;
          res = lhs->e26*factor;
          break;
        case 17:
          factor = 1.0000000000000000e+00;
          res = lhs->e36*factor;
          break;
        case 18:
          factor = 1.0000000000000000e+00;
          res = lhs->e46*factor;
          break;
        case 19:
          factor = 1.0000000000000000e+00;
          res = lhs->e56*factor;
          break;
        case 20:
          factor = 2.0000000000000000e+00;
          res = lhs->e66*factor;
          break;
        case 21:
          factor = 1.0000000000000000e+00;
          res = lhs->e17*factor;
          break;
        case 22:
          factor = 1.0000000000000000e+00;
          res = lhs->e27*factor;
          break;
        case 23:
          factor = 1.0000000000000000e+00;
          res = lhs->e37*factor;
          break;
        case 24:
          factor = 1.0000000000000000e+00;
          res = lhs->e47*factor;
          break;
        case 25:
          factor = 1.0000000000000000e+00;
          res = lhs->e57*factor;
          break;
        case 26:
          factor = 1.0000000000000000e+00;
          res = lhs->e67*factor;
          break;
        case 27:
          factor = 2.0000000000000000e+00;
          res = lhs->e77*factor;
          break;
        case 28:
          factor = 1.0000000000000000e+00;
          res = lhs->e18*factor;
          break;
        case 29:
          factor = 1.0000000000000000e+00;
          res = lhs->e28*factor;
          break;
        case 30:
          factor = 1.0000000000000000e+00;
          res = lhs->e38*factor;
          break;
        case 31:
          factor = 1.0000000000000000e+00;
          res = lhs->e48*factor;
          break;
        case 32:
          factor = 1.0000000000000000e+00;
          res = lhs->e58*factor;
          break;
        case 33:
          factor = 1.0000000000000000e+00;
          res = lhs->e68*factor;
          break;
        case 34:
          factor = 1.0000000000000000e+00;
          res = lhs->e78*factor;
          break;
        case 35:
          factor = 2.0000000000000000e+00;
          res = lhs->e88*factor;
          break;
        case 36:
          factor = 1.0000000000000000e+00;
          res = lhs->e19*factor;
          break;
        case 37:
          factor = 1.0000000000000000e+00;
          res = lhs->e29*factor;
          break;
        case 38:
          factor = 1.0000000000000000e+00;
          res = lhs->e39*factor;
          break;
        case 39:
          factor = 1.0000000000000000e+00;
          res = lhs->e49*factor;
          break;
        case 40:
          factor = 1.0000000000000000e+00;
          res = lhs->e59*factor;
          break;
        case 41:
          factor = 1.0000000000000000e+00;
          res = lhs->e69*factor;
          break;
        case 42:
          factor = 1.0000000000000000e+00;
          res = lhs->e79*factor;
          break;
        case 43:
          factor = 1.0000000000000000e+00;
          res = lhs->e89*factor;
          break;
        case 44:
          factor = 2.0000000000000000e+00;
          res = lhs->e99*factor;
          break;
      }
      break;
  }
  return res;

}

void onumm9n2_set_item(coeff_t val, imdir_t idx, ord_t order, onumm9n2_t* x){

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
        case 3:
          x->e4 = val;
          break;
        case 4:
          x->e5 = val;
          break;
        case 5:
          x->e6 = val;
          break;
        case 6:
          x->e7 = val;
          break;
        case 7:
          x->e8 = val;
          break;
        case 8:
          x->e9 = val;
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
        case 6:
          x->e14 = val;
          break;
        case 7:
          x->e24 = val;
          break;
        case 8:
          x->e34 = val;
          break;
        case 9:
          x->e44 = val;
          break;
        case 10:
          x->e15 = val;
          break;
        case 11:
          x->e25 = val;
          break;
        case 12:
          x->e35 = val;
          break;
        case 13:
          x->e45 = val;
          break;
        case 14:
          x->e55 = val;
          break;
        case 15:
          x->e16 = val;
          break;
        case 16:
          x->e26 = val;
          break;
        case 17:
          x->e36 = val;
          break;
        case 18:
          x->e46 = val;
          break;
        case 19:
          x->e56 = val;
          break;
        case 20:
          x->e66 = val;
          break;
        case 21:
          x->e17 = val;
          break;
        case 22:
          x->e27 = val;
          break;
        case 23:
          x->e37 = val;
          break;
        case 24:
          x->e47 = val;
          break;
        case 25:
          x->e57 = val;
          break;
        case 26:
          x->e67 = val;
          break;
        case 27:
          x->e77 = val;
          break;
        case 28:
          x->e18 = val;
          break;
        case 29:
          x->e28 = val;
          break;
        case 30:
          x->e38 = val;
          break;
        case 31:
          x->e48 = val;
          break;
        case 32:
          x->e58 = val;
          break;
        case 33:
          x->e68 = val;
          break;
        case 34:
          x->e78 = val;
          break;
        case 35:
          x->e88 = val;
          break;
        case 36:
          x->e19 = val;
          break;
        case 37:
          x->e29 = val;
          break;
        case 38:
          x->e39 = val;
          break;
        case 39:
          x->e49 = val;
          break;
        case 40:
          x->e59 = val;
          break;
        case 41:
          x->e69 = val;
          break;
        case 42:
          x->e79 = val;
          break;
        case 43:
          x->e89 = val;
          break;
        case 44:
          x->e99 = val;
          break;
      }
      break;
  }
}

onumm9n2_t onumm9n2_copy(  onumm9n2_t* lhs){

  onumm9n2_t res;

  // Assign like function 'lhs'
  // Real;
  res.r = lhs->r;
  // Order 1;
  res.e1 = lhs->e1;
  res.e2 = lhs->e2;
  res.e3 = lhs->e3;
  res.e4 = lhs->e4;
  res.e5 = lhs->e5;
  res.e6 = lhs->e6;
  res.e7 = lhs->e7;
  res.e8 = lhs->e8;
  res.e9 = lhs->e9;
  // Order 2;
  res.e11 = lhs->e11;
  res.e12 = lhs->e12;
  res.e22 = lhs->e22;
  res.e13 = lhs->e13;
  res.e23 = lhs->e23;
  res.e33 = lhs->e33;
  res.e14 = lhs->e14;
  res.e24 = lhs->e24;
  res.e34 = lhs->e34;
  res.e44 = lhs->e44;
  res.e15 = lhs->e15;
  res.e25 = lhs->e25;
  res.e35 = lhs->e35;
  res.e45 = lhs->e45;
  res.e55 = lhs->e55;
  res.e16 = lhs->e16;
  res.e26 = lhs->e26;
  res.e36 = lhs->e36;
  res.e46 = lhs->e46;
  res.e56 = lhs->e56;
  res.e66 = lhs->e66;
  res.e17 = lhs->e17;
  res.e27 = lhs->e27;
  res.e37 = lhs->e37;
  res.e47 = lhs->e47;
  res.e57 = lhs->e57;
  res.e67 = lhs->e67;
  res.e77 = lhs->e77;
  res.e18 = lhs->e18;
  res.e28 = lhs->e28;
  res.e38 = lhs->e38;
  res.e48 = lhs->e48;
  res.e58 = lhs->e58;
  res.e68 = lhs->e68;
  res.e78 = lhs->e78;
  res.e88 = lhs->e88;
  res.e19 = lhs->e19;
  res.e29 = lhs->e29;
  res.e39 = lhs->e39;
  res.e49 = lhs->e49;
  res.e59 = lhs->e59;
  res.e69 = lhs->e69;
  res.e79 = lhs->e79;
  res.e89 = lhs->e89;
  res.e99 = lhs->e99;

  return res;

}

void onumm9n2_copy_to(  onumm9n2_t* lhs, onumm9n2_t* res){

  // Assign like function 'lhs'
  // Real;
  res->r = lhs->r;
  // Order 1;
  res->e1 = lhs->e1;
  res->e2 = lhs->e2;
  res->e3 = lhs->e3;
  res->e4 = lhs->e4;
  res->e5 = lhs->e5;
  res->e6 = lhs->e6;
  res->e7 = lhs->e7;
  res->e8 = lhs->e8;
  res->e9 = lhs->e9;
  // Order 2;
  res->e11 = lhs->e11;
  res->e12 = lhs->e12;
  res->e22 = lhs->e22;
  res->e13 = lhs->e13;
  res->e23 = lhs->e23;
  res->e33 = lhs->e33;
  res->e14 = lhs->e14;
  res->e24 = lhs->e24;
  res->e34 = lhs->e34;
  res->e44 = lhs->e44;
  res->e15 = lhs->e15;
  res->e25 = lhs->e25;
  res->e35 = lhs->e35;
  res->e45 = lhs->e45;
  res->e55 = lhs->e55;
  res->e16 = lhs->e16;
  res->e26 = lhs->e26;
  res->e36 = lhs->e36;
  res->e46 = lhs->e46;
  res->e56 = lhs->e56;
  res->e66 = lhs->e66;
  res->e17 = lhs->e17;
  res->e27 = lhs->e27;
  res->e37 = lhs->e37;
  res->e47 = lhs->e47;
  res->e57 = lhs->e57;
  res->e67 = lhs->e67;
  res->e77 = lhs->e77;
  res->e18 = lhs->e18;
  res->e28 = lhs->e28;
  res->e38 = lhs->e38;
  res->e48 = lhs->e48;
  res->e58 = lhs->e58;
  res->e68 = lhs->e68;
  res->e78 = lhs->e78;
  res->e88 = lhs->e88;
  res->e19 = lhs->e19;
  res->e29 = lhs->e29;
  res->e39 = lhs->e39;
  res->e49 = lhs->e49;
  res->e59 = lhs->e59;
  res->e69 = lhs->e69;
  res->e79 = lhs->e79;
  res->e89 = lhs->e89;
  res->e99 = lhs->e99;

}

onumm9n2_t onumm9n2_taylor_integrate(coeff_t* deltas,onumm9n2_t* lhs){

  onumm9n2_t res;

  res = onumm9n2_init();
  coeff_t factor;
  // Taylor integration
  // Real;
  res.r = lhs->r;
  // Order 1;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],0)*pow(deltas[5],0)*pow(deltas[6],0)*pow(deltas[7],0)*pow(deltas[8],0);
  res.r += factor*lhs->e1;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],0)*pow(deltas[5],0)*pow(deltas[6],0)*pow(deltas[7],0)*pow(deltas[8],0);
  res.r += factor*lhs->e2;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],0)*pow(deltas[4],0)*pow(deltas[5],0)*pow(deltas[6],0)*pow(deltas[7],0)*pow(deltas[8],0);
  res.r += factor*lhs->e3;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],1)*pow(deltas[4],0)*pow(deltas[5],0)*pow(deltas[6],0)*pow(deltas[7],0)*pow(deltas[8],0);
  res.r += factor*lhs->e4;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],1)*pow(deltas[5],0)*pow(deltas[6],0)*pow(deltas[7],0)*pow(deltas[8],0);
  res.r += factor*lhs->e5;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],0)*pow(deltas[5],1)*pow(deltas[6],0)*pow(deltas[7],0)*pow(deltas[8],0);
  res.r += factor*lhs->e6;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],0)*pow(deltas[5],0)*pow(deltas[6],1)*pow(deltas[7],0)*pow(deltas[8],0);
  res.r += factor*lhs->e7;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],0)*pow(deltas[5],0)*pow(deltas[6],0)*pow(deltas[7],1)*pow(deltas[8],0);
  res.r += factor*lhs->e8;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],0)*pow(deltas[5],0)*pow(deltas[6],0)*pow(deltas[7],0)*pow(deltas[8],1);
  res.r += factor*lhs->e9;
  // Order 2;
  factor = pow(deltas[0],2)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],0)*pow(deltas[5],0)*pow(deltas[6],0)*pow(deltas[7],0)*pow(deltas[8],0);
  res.r += factor*lhs->e11;
  factor = pow(deltas[0],1)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],0)*pow(deltas[5],0)*pow(deltas[6],0)*pow(deltas[7],0)*pow(deltas[8],0);
  res.r += factor*lhs->e12;
  factor = pow(deltas[0],0)*pow(deltas[1],2)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],0)*pow(deltas[5],0)*pow(deltas[6],0)*pow(deltas[7],0)*pow(deltas[8],0);
  res.r += factor*lhs->e22;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],0)*pow(deltas[4],0)*pow(deltas[5],0)*pow(deltas[6],0)*pow(deltas[7],0)*pow(deltas[8],0);
  res.r += factor*lhs->e13;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],1)*pow(deltas[3],0)*pow(deltas[4],0)*pow(deltas[5],0)*pow(deltas[6],0)*pow(deltas[7],0)*pow(deltas[8],0);
  res.r += factor*lhs->e23;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],2)*pow(deltas[3],0)*pow(deltas[4],0)*pow(deltas[5],0)*pow(deltas[6],0)*pow(deltas[7],0)*pow(deltas[8],0);
  res.r += factor*lhs->e33;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],1)*pow(deltas[4],0)*pow(deltas[5],0)*pow(deltas[6],0)*pow(deltas[7],0)*pow(deltas[8],0);
  res.r += factor*lhs->e14;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],1)*pow(deltas[4],0)*pow(deltas[5],0)*pow(deltas[6],0)*pow(deltas[7],0)*pow(deltas[8],0);
  res.r += factor*lhs->e24;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],1)*pow(deltas[4],0)*pow(deltas[5],0)*pow(deltas[6],0)*pow(deltas[7],0)*pow(deltas[8],0);
  res.r += factor*lhs->e34;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],2)*pow(deltas[4],0)*pow(deltas[5],0)*pow(deltas[6],0)*pow(deltas[7],0)*pow(deltas[8],0);
  res.r += factor*lhs->e44;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],1)*pow(deltas[5],0)*pow(deltas[6],0)*pow(deltas[7],0)*pow(deltas[8],0);
  res.r += factor*lhs->e15;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],1)*pow(deltas[5],0)*pow(deltas[6],0)*pow(deltas[7],0)*pow(deltas[8],0);
  res.r += factor*lhs->e25;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],0)*pow(deltas[4],1)*pow(deltas[5],0)*pow(deltas[6],0)*pow(deltas[7],0)*pow(deltas[8],0);
  res.r += factor*lhs->e35;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],1)*pow(deltas[4],1)*pow(deltas[5],0)*pow(deltas[6],0)*pow(deltas[7],0)*pow(deltas[8],0);
  res.r += factor*lhs->e45;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],2)*pow(deltas[5],0)*pow(deltas[6],0)*pow(deltas[7],0)*pow(deltas[8],0);
  res.r += factor*lhs->e55;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],0)*pow(deltas[5],1)*pow(deltas[6],0)*pow(deltas[7],0)*pow(deltas[8],0);
  res.r += factor*lhs->e16;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],0)*pow(deltas[5],1)*pow(deltas[6],0)*pow(deltas[7],0)*pow(deltas[8],0);
  res.r += factor*lhs->e26;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],0)*pow(deltas[4],0)*pow(deltas[5],1)*pow(deltas[6],0)*pow(deltas[7],0)*pow(deltas[8],0);
  res.r += factor*lhs->e36;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],1)*pow(deltas[4],0)*pow(deltas[5],1)*pow(deltas[6],0)*pow(deltas[7],0)*pow(deltas[8],0);
  res.r += factor*lhs->e46;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],1)*pow(deltas[5],1)*pow(deltas[6],0)*pow(deltas[7],0)*pow(deltas[8],0);
  res.r += factor*lhs->e56;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],0)*pow(deltas[5],2)*pow(deltas[6],0)*pow(deltas[7],0)*pow(deltas[8],0);
  res.r += factor*lhs->e66;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],0)*pow(deltas[5],0)*pow(deltas[6],1)*pow(deltas[7],0)*pow(deltas[8],0);
  res.r += factor*lhs->e17;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],0)*pow(deltas[5],0)*pow(deltas[6],1)*pow(deltas[7],0)*pow(deltas[8],0);
  res.r += factor*lhs->e27;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],0)*pow(deltas[4],0)*pow(deltas[5],0)*pow(deltas[6],1)*pow(deltas[7],0)*pow(deltas[8],0);
  res.r += factor*lhs->e37;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],1)*pow(deltas[4],0)*pow(deltas[5],0)*pow(deltas[6],1)*pow(deltas[7],0)*pow(deltas[8],0);
  res.r += factor*lhs->e47;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],1)*pow(deltas[5],0)*pow(deltas[6],1)*pow(deltas[7],0)*pow(deltas[8],0);
  res.r += factor*lhs->e57;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],0)*pow(deltas[5],1)*pow(deltas[6],1)*pow(deltas[7],0)*pow(deltas[8],0);
  res.r += factor*lhs->e67;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],0)*pow(deltas[5],0)*pow(deltas[6],2)*pow(deltas[7],0)*pow(deltas[8],0);
  res.r += factor*lhs->e77;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],0)*pow(deltas[5],0)*pow(deltas[6],0)*pow(deltas[7],1)*pow(deltas[8],0);
  res.r += factor*lhs->e18;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],0)*pow(deltas[5],0)*pow(deltas[6],0)*pow(deltas[7],1)*pow(deltas[8],0);
  res.r += factor*lhs->e28;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],0)*pow(deltas[4],0)*pow(deltas[5],0)*pow(deltas[6],0)*pow(deltas[7],1)*pow(deltas[8],0);
  res.r += factor*lhs->e38;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],1)*pow(deltas[4],0)*pow(deltas[5],0)*pow(deltas[6],0)*pow(deltas[7],1)*pow(deltas[8],0);
  res.r += factor*lhs->e48;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],1)*pow(deltas[5],0)*pow(deltas[6],0)*pow(deltas[7],1)*pow(deltas[8],0);
  res.r += factor*lhs->e58;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],0)*pow(deltas[5],1)*pow(deltas[6],0)*pow(deltas[7],1)*pow(deltas[8],0);
  res.r += factor*lhs->e68;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],0)*pow(deltas[5],0)*pow(deltas[6],1)*pow(deltas[7],1)*pow(deltas[8],0);
  res.r += factor*lhs->e78;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],0)*pow(deltas[5],0)*pow(deltas[6],0)*pow(deltas[7],2)*pow(deltas[8],0);
  res.r += factor*lhs->e88;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],0)*pow(deltas[5],0)*pow(deltas[6],0)*pow(deltas[7],0)*pow(deltas[8],1);
  res.r += factor*lhs->e19;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],0)*pow(deltas[5],0)*pow(deltas[6],0)*pow(deltas[7],0)*pow(deltas[8],1);
  res.r += factor*lhs->e29;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],0)*pow(deltas[4],0)*pow(deltas[5],0)*pow(deltas[6],0)*pow(deltas[7],0)*pow(deltas[8],1);
  res.r += factor*lhs->e39;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],1)*pow(deltas[4],0)*pow(deltas[5],0)*pow(deltas[6],0)*pow(deltas[7],0)*pow(deltas[8],1);
  res.r += factor*lhs->e49;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],1)*pow(deltas[5],0)*pow(deltas[6],0)*pow(deltas[7],0)*pow(deltas[8],1);
  res.r += factor*lhs->e59;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],0)*pow(deltas[5],1)*pow(deltas[6],0)*pow(deltas[7],0)*pow(deltas[8],1);
  res.r += factor*lhs->e69;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],0)*pow(deltas[5],0)*pow(deltas[6],1)*pow(deltas[7],0)*pow(deltas[8],1);
  res.r += factor*lhs->e79;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],0)*pow(deltas[5],0)*pow(deltas[6],0)*pow(deltas[7],1)*pow(deltas[8],1);
  res.r += factor*lhs->e89;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],0)*pow(deltas[5],0)*pow(deltas[6],0)*pow(deltas[7],0)*pow(deltas[8],2);
  res.r += factor*lhs->e99;

  return res;

}

void onumm9n2_taylor_integrate_to(coeff_t* deltas,onumm9n2_t* lhs, onumm9n2_t* res){

  *res = onumm9n2_init();
  coeff_t factor;
  // Taylor integration
  // Real;
  res->r = lhs->r;
  // Order 1;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],0)*pow(deltas[5],0)*pow(deltas[6],0)*pow(deltas[7],0)*pow(deltas[8],0);
  res->r += factor*lhs->e1;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],0)*pow(deltas[5],0)*pow(deltas[6],0)*pow(deltas[7],0)*pow(deltas[8],0);
  res->r += factor*lhs->e2;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],0)*pow(deltas[4],0)*pow(deltas[5],0)*pow(deltas[6],0)*pow(deltas[7],0)*pow(deltas[8],0);
  res->r += factor*lhs->e3;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],1)*pow(deltas[4],0)*pow(deltas[5],0)*pow(deltas[6],0)*pow(deltas[7],0)*pow(deltas[8],0);
  res->r += factor*lhs->e4;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],1)*pow(deltas[5],0)*pow(deltas[6],0)*pow(deltas[7],0)*pow(deltas[8],0);
  res->r += factor*lhs->e5;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],0)*pow(deltas[5],1)*pow(deltas[6],0)*pow(deltas[7],0)*pow(deltas[8],0);
  res->r += factor*lhs->e6;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],0)*pow(deltas[5],0)*pow(deltas[6],1)*pow(deltas[7],0)*pow(deltas[8],0);
  res->r += factor*lhs->e7;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],0)*pow(deltas[5],0)*pow(deltas[6],0)*pow(deltas[7],1)*pow(deltas[8],0);
  res->r += factor*lhs->e8;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],0)*pow(deltas[5],0)*pow(deltas[6],0)*pow(deltas[7],0)*pow(deltas[8],1);
  res->r += factor*lhs->e9;
  // Order 2;
  factor = pow(deltas[0],2)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],0)*pow(deltas[5],0)*pow(deltas[6],0)*pow(deltas[7],0)*pow(deltas[8],0);
  res->r += factor*lhs->e11;
  factor = pow(deltas[0],1)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],0)*pow(deltas[5],0)*pow(deltas[6],0)*pow(deltas[7],0)*pow(deltas[8],0);
  res->r += factor*lhs->e12;
  factor = pow(deltas[0],0)*pow(deltas[1],2)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],0)*pow(deltas[5],0)*pow(deltas[6],0)*pow(deltas[7],0)*pow(deltas[8],0);
  res->r += factor*lhs->e22;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],0)*pow(deltas[4],0)*pow(deltas[5],0)*pow(deltas[6],0)*pow(deltas[7],0)*pow(deltas[8],0);
  res->r += factor*lhs->e13;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],1)*pow(deltas[3],0)*pow(deltas[4],0)*pow(deltas[5],0)*pow(deltas[6],0)*pow(deltas[7],0)*pow(deltas[8],0);
  res->r += factor*lhs->e23;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],2)*pow(deltas[3],0)*pow(deltas[4],0)*pow(deltas[5],0)*pow(deltas[6],0)*pow(deltas[7],0)*pow(deltas[8],0);
  res->r += factor*lhs->e33;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],1)*pow(deltas[4],0)*pow(deltas[5],0)*pow(deltas[6],0)*pow(deltas[7],0)*pow(deltas[8],0);
  res->r += factor*lhs->e14;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],1)*pow(deltas[4],0)*pow(deltas[5],0)*pow(deltas[6],0)*pow(deltas[7],0)*pow(deltas[8],0);
  res->r += factor*lhs->e24;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],1)*pow(deltas[4],0)*pow(deltas[5],0)*pow(deltas[6],0)*pow(deltas[7],0)*pow(deltas[8],0);
  res->r += factor*lhs->e34;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],2)*pow(deltas[4],0)*pow(deltas[5],0)*pow(deltas[6],0)*pow(deltas[7],0)*pow(deltas[8],0);
  res->r += factor*lhs->e44;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],1)*pow(deltas[5],0)*pow(deltas[6],0)*pow(deltas[7],0)*pow(deltas[8],0);
  res->r += factor*lhs->e15;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],1)*pow(deltas[5],0)*pow(deltas[6],0)*pow(deltas[7],0)*pow(deltas[8],0);
  res->r += factor*lhs->e25;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],0)*pow(deltas[4],1)*pow(deltas[5],0)*pow(deltas[6],0)*pow(deltas[7],0)*pow(deltas[8],0);
  res->r += factor*lhs->e35;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],1)*pow(deltas[4],1)*pow(deltas[5],0)*pow(deltas[6],0)*pow(deltas[7],0)*pow(deltas[8],0);
  res->r += factor*lhs->e45;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],2)*pow(deltas[5],0)*pow(deltas[6],0)*pow(deltas[7],0)*pow(deltas[8],0);
  res->r += factor*lhs->e55;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],0)*pow(deltas[5],1)*pow(deltas[6],0)*pow(deltas[7],0)*pow(deltas[8],0);
  res->r += factor*lhs->e16;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],0)*pow(deltas[5],1)*pow(deltas[6],0)*pow(deltas[7],0)*pow(deltas[8],0);
  res->r += factor*lhs->e26;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],0)*pow(deltas[4],0)*pow(deltas[5],1)*pow(deltas[6],0)*pow(deltas[7],0)*pow(deltas[8],0);
  res->r += factor*lhs->e36;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],1)*pow(deltas[4],0)*pow(deltas[5],1)*pow(deltas[6],0)*pow(deltas[7],0)*pow(deltas[8],0);
  res->r += factor*lhs->e46;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],1)*pow(deltas[5],1)*pow(deltas[6],0)*pow(deltas[7],0)*pow(deltas[8],0);
  res->r += factor*lhs->e56;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],0)*pow(deltas[5],2)*pow(deltas[6],0)*pow(deltas[7],0)*pow(deltas[8],0);
  res->r += factor*lhs->e66;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],0)*pow(deltas[5],0)*pow(deltas[6],1)*pow(deltas[7],0)*pow(deltas[8],0);
  res->r += factor*lhs->e17;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],0)*pow(deltas[5],0)*pow(deltas[6],1)*pow(deltas[7],0)*pow(deltas[8],0);
  res->r += factor*lhs->e27;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],0)*pow(deltas[4],0)*pow(deltas[5],0)*pow(deltas[6],1)*pow(deltas[7],0)*pow(deltas[8],0);
  res->r += factor*lhs->e37;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],1)*pow(deltas[4],0)*pow(deltas[5],0)*pow(deltas[6],1)*pow(deltas[7],0)*pow(deltas[8],0);
  res->r += factor*lhs->e47;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],1)*pow(deltas[5],0)*pow(deltas[6],1)*pow(deltas[7],0)*pow(deltas[8],0);
  res->r += factor*lhs->e57;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],0)*pow(deltas[5],1)*pow(deltas[6],1)*pow(deltas[7],0)*pow(deltas[8],0);
  res->r += factor*lhs->e67;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],0)*pow(deltas[5],0)*pow(deltas[6],2)*pow(deltas[7],0)*pow(deltas[8],0);
  res->r += factor*lhs->e77;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],0)*pow(deltas[5],0)*pow(deltas[6],0)*pow(deltas[7],1)*pow(deltas[8],0);
  res->r += factor*lhs->e18;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],0)*pow(deltas[5],0)*pow(deltas[6],0)*pow(deltas[7],1)*pow(deltas[8],0);
  res->r += factor*lhs->e28;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],0)*pow(deltas[4],0)*pow(deltas[5],0)*pow(deltas[6],0)*pow(deltas[7],1)*pow(deltas[8],0);
  res->r += factor*lhs->e38;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],1)*pow(deltas[4],0)*pow(deltas[5],0)*pow(deltas[6],0)*pow(deltas[7],1)*pow(deltas[8],0);
  res->r += factor*lhs->e48;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],1)*pow(deltas[5],0)*pow(deltas[6],0)*pow(deltas[7],1)*pow(deltas[8],0);
  res->r += factor*lhs->e58;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],0)*pow(deltas[5],1)*pow(deltas[6],0)*pow(deltas[7],1)*pow(deltas[8],0);
  res->r += factor*lhs->e68;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],0)*pow(deltas[5],0)*pow(deltas[6],1)*pow(deltas[7],1)*pow(deltas[8],0);
  res->r += factor*lhs->e78;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],0)*pow(deltas[5],0)*pow(deltas[6],0)*pow(deltas[7],2)*pow(deltas[8],0);
  res->r += factor*lhs->e88;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],0)*pow(deltas[5],0)*pow(deltas[6],0)*pow(deltas[7],0)*pow(deltas[8],1);
  res->r += factor*lhs->e19;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],0)*pow(deltas[5],0)*pow(deltas[6],0)*pow(deltas[7],0)*pow(deltas[8],1);
  res->r += factor*lhs->e29;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],0)*pow(deltas[4],0)*pow(deltas[5],0)*pow(deltas[6],0)*pow(deltas[7],0)*pow(deltas[8],1);
  res->r += factor*lhs->e39;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],1)*pow(deltas[4],0)*pow(deltas[5],0)*pow(deltas[6],0)*pow(deltas[7],0)*pow(deltas[8],1);
  res->r += factor*lhs->e49;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],1)*pow(deltas[5],0)*pow(deltas[6],0)*pow(deltas[7],0)*pow(deltas[8],1);
  res->r += factor*lhs->e59;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],0)*pow(deltas[5],1)*pow(deltas[6],0)*pow(deltas[7],0)*pow(deltas[8],1);
  res->r += factor*lhs->e69;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],0)*pow(deltas[5],0)*pow(deltas[6],1)*pow(deltas[7],0)*pow(deltas[8],1);
  res->r += factor*lhs->e79;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],0)*pow(deltas[5],0)*pow(deltas[6],0)*pow(deltas[7],1)*pow(deltas[8],1);
  res->r += factor*lhs->e89;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],0)*pow(deltas[5],0)*pow(deltas[6],0)*pow(deltas[7],0)*pow(deltas[8],2);
  res->r += factor*lhs->e99;

}

onumm9n2_t onumm9n2_truncate_im(imdir_t idx, ord_t order, onumm9n2_t* lhs){

  onumm9n2_t res;

  // Copy number.
  res = (*lhs);
  // Truncate all other values when necessary.
  // Real;
  switch (order){
    case 0:
      res = onumm9n2_init();
      break;
    case 1:
      switch (idx){
        case 0: //  e1
          res.e1 = 0.0;
          res.e11 = 0.0;
          res.e12 = 0.0;
          res.e13 = 0.0;
          res.e14 = 0.0;
          res.e15 = 0.0;
          res.e16 = 0.0;
          res.e17 = 0.0;
          res.e18 = 0.0;
          res.e19 = 0.0;
          break;
        case 1: //  e2
          res.e2 = 0.0;
          res.e12 = 0.0;
          res.e22 = 0.0;
          res.e23 = 0.0;
          res.e24 = 0.0;
          res.e25 = 0.0;
          res.e26 = 0.0;
          res.e27 = 0.0;
          res.e28 = 0.0;
          res.e29 = 0.0;
          break;
        case 2: //  e3
          res.e3 = 0.0;
          res.e13 = 0.0;
          res.e23 = 0.0;
          res.e33 = 0.0;
          res.e34 = 0.0;
          res.e35 = 0.0;
          res.e36 = 0.0;
          res.e37 = 0.0;
          res.e38 = 0.0;
          res.e39 = 0.0;
          break;
        case 3: //  e4
          res.e4 = 0.0;
          res.e14 = 0.0;
          res.e24 = 0.0;
          res.e34 = 0.0;
          res.e44 = 0.0;
          res.e45 = 0.0;
          res.e46 = 0.0;
          res.e47 = 0.0;
          res.e48 = 0.0;
          res.e49 = 0.0;
          break;
        case 4: //  e5
          res.e5 = 0.0;
          res.e15 = 0.0;
          res.e25 = 0.0;
          res.e35 = 0.0;
          res.e45 = 0.0;
          res.e55 = 0.0;
          res.e56 = 0.0;
          res.e57 = 0.0;
          res.e58 = 0.0;
          res.e59 = 0.0;
          break;
        case 5: //  e6
          res.e6 = 0.0;
          res.e16 = 0.0;
          res.e26 = 0.0;
          res.e36 = 0.0;
          res.e46 = 0.0;
          res.e56 = 0.0;
          res.e66 = 0.0;
          res.e67 = 0.0;
          res.e68 = 0.0;
          res.e69 = 0.0;
          break;
        case 6: //  e7
          res.e7 = 0.0;
          res.e17 = 0.0;
          res.e27 = 0.0;
          res.e37 = 0.0;
          res.e47 = 0.0;
          res.e57 = 0.0;
          res.e67 = 0.0;
          res.e77 = 0.0;
          res.e78 = 0.0;
          res.e79 = 0.0;
          break;
        case 7: //  e8
          res.e8 = 0.0;
          res.e18 = 0.0;
          res.e28 = 0.0;
          res.e38 = 0.0;
          res.e48 = 0.0;
          res.e58 = 0.0;
          res.e68 = 0.0;
          res.e78 = 0.0;
          res.e88 = 0.0;
          res.e89 = 0.0;
          break;
        case 8: //  e9
          res.e9 = 0.0;
          res.e19 = 0.0;
          res.e29 = 0.0;
          res.e39 = 0.0;
          res.e49 = 0.0;
          res.e59 = 0.0;
          res.e69 = 0.0;
          res.e79 = 0.0;
          res.e89 = 0.0;
          res.e99 = 0.0;
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
        case 6: //  e14
          res.e14 = 0.0;
          break;
        case 7: //  e24
          res.e24 = 0.0;
          break;
        case 8: //  e34
          res.e34 = 0.0;
          break;
        case 9: //  e44
          res.e44 = 0.0;
          break;
        case 10: //  e15
          res.e15 = 0.0;
          break;
        case 11: //  e25
          res.e25 = 0.0;
          break;
        case 12: //  e35
          res.e35 = 0.0;
          break;
        case 13: //  e45
          res.e45 = 0.0;
          break;
        case 14: //  e55
          res.e55 = 0.0;
          break;
        case 15: //  e16
          res.e16 = 0.0;
          break;
        case 16: //  e26
          res.e26 = 0.0;
          break;
        case 17: //  e36
          res.e36 = 0.0;
          break;
        case 18: //  e46
          res.e46 = 0.0;
          break;
        case 19: //  e56
          res.e56 = 0.0;
          break;
        case 20: //  e66
          res.e66 = 0.0;
          break;
        case 21: //  e17
          res.e17 = 0.0;
          break;
        case 22: //  e27
          res.e27 = 0.0;
          break;
        case 23: //  e37
          res.e37 = 0.0;
          break;
        case 24: //  e47
          res.e47 = 0.0;
          break;
        case 25: //  e57
          res.e57 = 0.0;
          break;
        case 26: //  e67
          res.e67 = 0.0;
          break;
        case 27: //  e77
          res.e77 = 0.0;
          break;
        case 28: //  e18
          res.e18 = 0.0;
          break;
        case 29: //  e28
          res.e28 = 0.0;
          break;
        case 30: //  e38
          res.e38 = 0.0;
          break;
        case 31: //  e48
          res.e48 = 0.0;
          break;
        case 32: //  e58
          res.e58 = 0.0;
          break;
        case 33: //  e68
          res.e68 = 0.0;
          break;
        case 34: //  e78
          res.e78 = 0.0;
          break;
        case 35: //  e88
          res.e88 = 0.0;
          break;
        case 36: //  e19
          res.e19 = 0.0;
          break;
        case 37: //  e29
          res.e29 = 0.0;
          break;
        case 38: //  e39
          res.e39 = 0.0;
          break;
        case 39: //  e49
          res.e49 = 0.0;
          break;
        case 40: //  e59
          res.e59 = 0.0;
          break;
        case 41: //  e69
          res.e69 = 0.0;
          break;
        case 42: //  e79
          res.e79 = 0.0;
          break;
        case 43: //  e89
          res.e89 = 0.0;
          break;
        case 44: //  e99
          res.e99 = 0.0;
          break;
      }
      break;
  }
  return res;

}

void onumm9n2_truncate_im_to(imdir_t idx, ord_t order, onumm9n2_t* lhs, onumm9n2_t* res){

  // Copy number.
  *res = (*lhs);
  // Truncate all other values when necessary.
  // Real;
  switch (order){
    case 0:
      *res = onumm9n2_init();
      break;
    case 1:
      switch (idx){
        case 0: //  e1
          res->e1 = 0.0;
          res->e11 = 0.0;
          res->e12 = 0.0;
          res->e13 = 0.0;
          res->e14 = 0.0;
          res->e15 = 0.0;
          res->e16 = 0.0;
          res->e17 = 0.0;
          res->e18 = 0.0;
          res->e19 = 0.0;
          break;
        case 1: //  e2
          res->e2 = 0.0;
          res->e12 = 0.0;
          res->e22 = 0.0;
          res->e23 = 0.0;
          res->e24 = 0.0;
          res->e25 = 0.0;
          res->e26 = 0.0;
          res->e27 = 0.0;
          res->e28 = 0.0;
          res->e29 = 0.0;
          break;
        case 2: //  e3
          res->e3 = 0.0;
          res->e13 = 0.0;
          res->e23 = 0.0;
          res->e33 = 0.0;
          res->e34 = 0.0;
          res->e35 = 0.0;
          res->e36 = 0.0;
          res->e37 = 0.0;
          res->e38 = 0.0;
          res->e39 = 0.0;
          break;
        case 3: //  e4
          res->e4 = 0.0;
          res->e14 = 0.0;
          res->e24 = 0.0;
          res->e34 = 0.0;
          res->e44 = 0.0;
          res->e45 = 0.0;
          res->e46 = 0.0;
          res->e47 = 0.0;
          res->e48 = 0.0;
          res->e49 = 0.0;
          break;
        case 4: //  e5
          res->e5 = 0.0;
          res->e15 = 0.0;
          res->e25 = 0.0;
          res->e35 = 0.0;
          res->e45 = 0.0;
          res->e55 = 0.0;
          res->e56 = 0.0;
          res->e57 = 0.0;
          res->e58 = 0.0;
          res->e59 = 0.0;
          break;
        case 5: //  e6
          res->e6 = 0.0;
          res->e16 = 0.0;
          res->e26 = 0.0;
          res->e36 = 0.0;
          res->e46 = 0.0;
          res->e56 = 0.0;
          res->e66 = 0.0;
          res->e67 = 0.0;
          res->e68 = 0.0;
          res->e69 = 0.0;
          break;
        case 6: //  e7
          res->e7 = 0.0;
          res->e17 = 0.0;
          res->e27 = 0.0;
          res->e37 = 0.0;
          res->e47 = 0.0;
          res->e57 = 0.0;
          res->e67 = 0.0;
          res->e77 = 0.0;
          res->e78 = 0.0;
          res->e79 = 0.0;
          break;
        case 7: //  e8
          res->e8 = 0.0;
          res->e18 = 0.0;
          res->e28 = 0.0;
          res->e38 = 0.0;
          res->e48 = 0.0;
          res->e58 = 0.0;
          res->e68 = 0.0;
          res->e78 = 0.0;
          res->e88 = 0.0;
          res->e89 = 0.0;
          break;
        case 8: //  e9
          res->e9 = 0.0;
          res->e19 = 0.0;
          res->e29 = 0.0;
          res->e39 = 0.0;
          res->e49 = 0.0;
          res->e59 = 0.0;
          res->e69 = 0.0;
          res->e79 = 0.0;
          res->e89 = 0.0;
          res->e99 = 0.0;
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
        case 6: //  e14
          res->e14 = 0.0;
          break;
        case 7: //  e24
          res->e24 = 0.0;
          break;
        case 8: //  e34
          res->e34 = 0.0;
          break;
        case 9: //  e44
          res->e44 = 0.0;
          break;
        case 10: //  e15
          res->e15 = 0.0;
          break;
        case 11: //  e25
          res->e25 = 0.0;
          break;
        case 12: //  e35
          res->e35 = 0.0;
          break;
        case 13: //  e45
          res->e45 = 0.0;
          break;
        case 14: //  e55
          res->e55 = 0.0;
          break;
        case 15: //  e16
          res->e16 = 0.0;
          break;
        case 16: //  e26
          res->e26 = 0.0;
          break;
        case 17: //  e36
          res->e36 = 0.0;
          break;
        case 18: //  e46
          res->e46 = 0.0;
          break;
        case 19: //  e56
          res->e56 = 0.0;
          break;
        case 20: //  e66
          res->e66 = 0.0;
          break;
        case 21: //  e17
          res->e17 = 0.0;
          break;
        case 22: //  e27
          res->e27 = 0.0;
          break;
        case 23: //  e37
          res->e37 = 0.0;
          break;
        case 24: //  e47
          res->e47 = 0.0;
          break;
        case 25: //  e57
          res->e57 = 0.0;
          break;
        case 26: //  e67
          res->e67 = 0.0;
          break;
        case 27: //  e77
          res->e77 = 0.0;
          break;
        case 28: //  e18
          res->e18 = 0.0;
          break;
        case 29: //  e28
          res->e28 = 0.0;
          break;
        case 30: //  e38
          res->e38 = 0.0;
          break;
        case 31: //  e48
          res->e48 = 0.0;
          break;
        case 32: //  e58
          res->e58 = 0.0;
          break;
        case 33: //  e68
          res->e68 = 0.0;
          break;
        case 34: //  e78
          res->e78 = 0.0;
          break;
        case 35: //  e88
          res->e88 = 0.0;
          break;
        case 36: //  e19
          res->e19 = 0.0;
          break;
        case 37: //  e29
          res->e29 = 0.0;
          break;
        case 38: //  e39
          res->e39 = 0.0;
          break;
        case 39: //  e49
          res->e49 = 0.0;
          break;
        case 40: //  e59
          res->e59 = 0.0;
          break;
        case 41: //  e69
          res->e69 = 0.0;
          break;
        case 42: //  e79
          res->e79 = 0.0;
          break;
        case 43: //  e89
          res->e89 = 0.0;
          break;
        case 44: //  e99
          res->e99 = 0.0;
          break;
      }
      break;
  }
}

void onumm9n2_print(  onumm9n2_t* lhs){

  // Print function.
  //  Real;
  printf("%.8g",lhs->r);
  //  Order 1;
  printf(" %+.8g*e1",lhs->e1);
  printf(" %+.8g*e2",lhs->e2);
  printf(" %+.8g*e3",lhs->e3);
  printf(" %+.8g*e4",lhs->e4);
  printf(" %+.8g*e5",lhs->e5);
  printf(" %+.8g*e6",lhs->e6);
  printf(" %+.8g*e7",lhs->e7);
  printf(" %+.8g*e8",lhs->e8);
  printf(" %+.8g*e9",lhs->e9);
  //  Order 2;
  printf(" %+.8g*e11",lhs->e11);
  printf(" %+.8g*e12",lhs->e12);
  printf(" %+.8g*e22",lhs->e22);
  printf(" %+.8g*e13",lhs->e13);
  printf(" %+.8g*e23",lhs->e23);
  printf(" %+.8g*e33",lhs->e33);
  printf(" %+.8g*e14",lhs->e14);
  printf(" %+.8g*e24",lhs->e24);
  printf(" %+.8g*e34",lhs->e34);
  printf(" %+.8g*e44",lhs->e44);
  printf(" %+.8g*e15",lhs->e15);
  printf(" %+.8g*e25",lhs->e25);
  printf(" %+.8g*e35",lhs->e35);
  printf(" %+.8g*e45",lhs->e45);
  printf(" %+.8g*e55",lhs->e55);
  printf(" %+.8g*e16",lhs->e16);
  printf(" %+.8g*e26",lhs->e26);
  printf(" %+.8g*e36",lhs->e36);
  printf(" %+.8g*e46",lhs->e46);
  printf(" %+.8g*e56",lhs->e56);
  printf(" %+.8g*e66",lhs->e66);
  printf(" %+.8g*e17",lhs->e17);
  printf(" %+.8g*e27",lhs->e27);
  printf(" %+.8g*e37",lhs->e37);
  printf(" %+.8g*e47",lhs->e47);
  printf(" %+.8g*e57",lhs->e57);
  printf(" %+.8g*e67",lhs->e67);
  printf(" %+.8g*e77",lhs->e77);
  printf(" %+.8g*e18",lhs->e18);
  printf(" %+.8g*e28",lhs->e28);
  printf(" %+.8g*e38",lhs->e38);
  printf(" %+.8g*e48",lhs->e48);
  printf(" %+.8g*e58",lhs->e58);
  printf(" %+.8g*e68",lhs->e68);
  printf(" %+.8g*e78",lhs->e78);
  printf(" %+.8g*e88",lhs->e88);
  printf(" %+.8g*e19",lhs->e19);
  printf(" %+.8g*e29",lhs->e29);
  printf(" %+.8g*e39",lhs->e39);
  printf(" %+.8g*e49",lhs->e49);
  printf(" %+.8g*e59",lhs->e59);
  printf(" %+.8g*e69",lhs->e69);
  printf(" %+.8g*e79",lhs->e79);
  printf(" %+.8g*e89",lhs->e89);
  printf(" %+.8g*e99",lhs->e99);
  printf("\n");

}

imdir_t onumm9n2_get_indx(imdir_t idx, ord_t order){

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
        case 21:
          return 21;
          break;
        case 22:
          return 22;
          break;
        case 23:
          return 23;
          break;
        case 24:
          return 24;
          break;
        case 25:
          return 25;
          break;
        case 26:
          return 26;
          break;
        case 27:
          return 27;
          break;
        case 28:
          return 28;
          break;
        case 29:
          return 29;
          break;
        case 30:
          return 30;
          break;
        case 31:
          return 31;
          break;
        case 32:
          return 32;
          break;
        case 33:
          return 33;
          break;
        case 34:
          return 34;
          break;
        case 35:
          return 35;
          break;
        case 36:
          return 36;
          break;
        case 37:
          return 37;
          break;
        case 38:
          return 38;
          break;
        case 39:
          return 39;
          break;
        case 40:
          return 40;
          break;
        case 41:
          return 41;
          break;
        case 42:
          return 42;
          break;
        case 43:
          return 43;
          break;
        case 44:
          return 44;
          break;
      }
      break;
      default:
          return 0;
  }
  return 0;
}

