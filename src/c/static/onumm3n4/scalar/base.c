

// Not implemented correctly:
void onumm3n4_set_im_o(onumm3n4_t* num, imdir_t idx, ord_t order, onumm3n4_t* res){
    onumm3n4_set_item(num->r,idx,order,res);
}
void onumm3n4_set_deriv_r(coeff_t num, imdir_t idx, ord_t order, onumm3n4_t* res){
    *res=onumm3n4_init();
}
void onumm3n4_set_deriv_o(onumm3n4_t* num, imdir_t idx, ord_t order, onumm3n4_t* res){
    *res=onumm3n4_init();
}
void onumm3n4_extract_im_to( imdir_t idx, ord_t order, onumm3n4_t* num, onumm3n4_t* res){
    *res=onumm3n4_init();
}
onumm3n4_t onumm3n4_extract_im(imdir_t idx, ord_t order, onumm3n4_t* num){
    onumm3n4_t res = onumm3n4_init();
    return res;
}
onumm3n4_t onumm3n4_extract_deriv(imdir_t idx, ord_t order, onumm3n4_t* num){
    onumm3n4_t res = onumm3n4_init();
    return res;
}
void onumm3n4_extract_deriv_to(imdir_t idx, ord_t order, onumm3n4_t* num, onumm3n4_t* res){
	*res = onumm3n4_init();
}
void onumm3n4_get_im_to_o(imdir_t idx, ord_t order, onumm3n4_t* num, onumm3n4_t* res){
    coeff_t rres = onumm3n4_get_item(idx, order, num);
    onumm3n4_set_r(rres,res);
}
onumm3n4_t onumm3n4_get_im_o(imdir_t idx, ord_t order, onumm3n4_t* num){
    coeff_t rres = onumm3n4_get_item(idx, order, num);
    onumm3n4_t res;
    onumm3n4_set_r(rres,&res);
    return res;
}
void onumm3n4_get_im_to_r(imdir_t idx, ord_t order, onumm3n4_t* num, coeff_t* res){
    *res = onumm3n4_get_item(idx, order, num);
}

inline ord_t onumm3n4_get_order(onumm3n4_t* lhs){

	return 4;

}

onumm3n4_t onumm3n4_get_deriv_o( imdir_t idx, ord_t order, onumm3n4_t* num){

    onumm3n4_t res = onumm3n4_init();

    onumm3n4_get_deriv_to( idx, order, num, &res);
    
    return res;

}

void onumm3n4_get_deriv_to( imdir_t idx, ord_t order, onumm3n4_t* num, onumm3n4_t* res){

    coeff_t deriv = onumm3n4_get_deriv(idx,order,num);

    onumm3n4_set_r( deriv, res);

}

void onumm3n4_set_im_r(coeff_t num, imdir_t idx, ord_t order, onumm3n4_t* res){

    onumm3n4_set_item(num, idx,order,res);

}

onumm3n4_t onumm3n4_init(void){

  onumm3n4_t res;

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
  // Order 3;
  res.e111 = 0.0;
  res.e112 = 0.0;
  res.e122 = 0.0;
  res.e222 = 0.0;
  res.e113 = 0.0;
  res.e123 = 0.0;
  res.e223 = 0.0;
  res.e133 = 0.0;
  res.e233 = 0.0;
  res.e333 = 0.0;
  // Order 4;
  res.e1111 = 0.0;
  res.e1112 = 0.0;
  res.e1122 = 0.0;
  res.e1222 = 0.0;
  res.e2222 = 0.0;
  res.e1113 = 0.0;
  res.e1123 = 0.0;
  res.e1223 = 0.0;
  res.e2223 = 0.0;
  res.e1133 = 0.0;
  res.e1233 = 0.0;
  res.e2233 = 0.0;
  res.e1333 = 0.0;
  res.e2333 = 0.0;
  res.e3333 = 0.0;

  return res;

}

ndir_t onumm3n4_get_ndir_order(ord_t order, onumm3n4_t* num){

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
    case 3:
      res = 10;
      break;
    case 4:
      res = 15;
      break;
  }

  return res;

}

ndir_t onumm3n4_get_ndir_total(onumm3n4_t* num){

  ndir_t res;

  res = 20;

  return res;

}

coeff_t* onumm3n4_get_order_address(ord_t order, onumm3n4_t* num){

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

onumm3n4_t onumm3n4_create_r(  coeff_t lhs){

  onumm3n4_t res;

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
  // Order 3;
  res.e111 = 0.0;
  res.e112 = 0.0;
  res.e122 = 0.0;
  res.e222 = 0.0;
  res.e113 = 0.0;
  res.e123 = 0.0;
  res.e223 = 0.0;
  res.e133 = 0.0;
  res.e233 = 0.0;
  res.e333 = 0.0;
  // Order 4;
  res.e1111 = 0.0;
  res.e1112 = 0.0;
  res.e1122 = 0.0;
  res.e1222 = 0.0;
  res.e2222 = 0.0;
  res.e1113 = 0.0;
  res.e1123 = 0.0;
  res.e1223 = 0.0;
  res.e2223 = 0.0;
  res.e1133 = 0.0;
  res.e1233 = 0.0;
  res.e2233 = 0.0;
  res.e1333 = 0.0;
  res.e2333 = 0.0;
  res.e3333 = 0.0;

  return res;

}

void onumm3n4_set_r(  coeff_t lhs, onumm3n4_t* res){

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
  // Order 3;
  res->e111 = 0.0;
  res->e112 = 0.0;
  res->e122 = 0.0;
  res->e222 = 0.0;
  res->e113 = 0.0;
  res->e123 = 0.0;
  res->e223 = 0.0;
  res->e133 = 0.0;
  res->e233 = 0.0;
  res->e333 = 0.0;
  // Order 4;
  res->e1111 = 0.0;
  res->e1112 = 0.0;
  res->e1122 = 0.0;
  res->e1222 = 0.0;
  res->e2222 = 0.0;
  res->e1113 = 0.0;
  res->e1123 = 0.0;
  res->e1223 = 0.0;
  res->e2223 = 0.0;
  res->e1133 = 0.0;
  res->e1233 = 0.0;
  res->e2233 = 0.0;
  res->e1333 = 0.0;
  res->e2333 = 0.0;
  res->e3333 = 0.0;

}

void onumm3n4_set_o(  onumm3n4_t* lhs, onumm3n4_t* res){

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
  // Order 3;
  res->e111 = lhs->e111;
  res->e112 = lhs->e112;
  res->e122 = lhs->e122;
  res->e222 = lhs->e222;
  res->e113 = lhs->e113;
  res->e123 = lhs->e123;
  res->e223 = lhs->e223;
  res->e133 = lhs->e133;
  res->e233 = lhs->e233;
  res->e333 = lhs->e333;
  // Order 4;
  res->e1111 = lhs->e1111;
  res->e1112 = lhs->e1112;
  res->e1122 = lhs->e1122;
  res->e1222 = lhs->e1222;
  res->e2222 = lhs->e2222;
  res->e1113 = lhs->e1113;
  res->e1123 = lhs->e1123;
  res->e1223 = lhs->e1223;
  res->e2223 = lhs->e2223;
  res->e1133 = lhs->e1133;
  res->e1233 = lhs->e1233;
  res->e2233 = lhs->e2233;
  res->e1333 = lhs->e1333;
  res->e2333 = lhs->e2333;
  res->e3333 = lhs->e3333;

}

onumm3n4_t onumm3n4_get_order_im(ord_t order, onumm3n4_t* lhs){

  onumm3n4_t res;

  res = onumm3n4_init();
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
    case 3:
      // Order 3;
      res.e111 = lhs->e111;
      res.e112 = lhs->e112;
      res.e122 = lhs->e122;
      res.e222 = lhs->e222;
      res.e113 = lhs->e113;
      res.e123 = lhs->e123;
      res.e223 = lhs->e223;
      res.e133 = lhs->e133;
      res.e233 = lhs->e233;
      res.e333 = lhs->e333;
      break;
    case 4:
      // Order 4;
      res.e1111 = lhs->e1111;
      res.e1112 = lhs->e1112;
      res.e1122 = lhs->e1122;
      res.e1222 = lhs->e1222;
      res.e2222 = lhs->e2222;
      res.e1113 = lhs->e1113;
      res.e1123 = lhs->e1123;
      res.e1223 = lhs->e1223;
      res.e2223 = lhs->e2223;
      res.e1133 = lhs->e1133;
      res.e1233 = lhs->e1233;
      res.e2233 = lhs->e2233;
      res.e1333 = lhs->e1333;
      res.e2333 = lhs->e2333;
      res.e3333 = lhs->e3333;
      break;
  }

  return res;

}

void onumm3n4_get_order_im_to(ord_t order, onumm3n4_t* lhs, onumm3n4_t* res){


  *res = onumm3n4_init();
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
    case 3:
      // Order 3;
      res->e111 = lhs->e111;
      res->e112 = lhs->e112;
      res->e122 = lhs->e122;
      res->e222 = lhs->e222;
      res->e113 = lhs->e113;
      res->e123 = lhs->e123;
      res->e223 = lhs->e223;
      res->e133 = lhs->e133;
      res->e233 = lhs->e233;
      res->e333 = lhs->e333;
      break;
    case 4:
      // Order 4;
      res->e1111 = lhs->e1111;
      res->e1112 = lhs->e1112;
      res->e1122 = lhs->e1122;
      res->e1222 = lhs->e1222;
      res->e2222 = lhs->e2222;
      res->e1113 = lhs->e1113;
      res->e1123 = lhs->e1123;
      res->e1223 = lhs->e1223;
      res->e2223 = lhs->e2223;
      res->e1133 = lhs->e1133;
      res->e1233 = lhs->e1233;
      res->e2233 = lhs->e2233;
      res->e1333 = lhs->e1333;
      res->e2333 = lhs->e2333;
      res->e3333 = lhs->e3333;
      break;
  }

}

coeff_t onumm3n4_get_item(imdir_t idx, ord_t order, onumm3n4_t* lhs){

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
        case 4:
          res = lhs->e113;
          break;
        case 5:
          res = lhs->e123;
          break;
        case 6:
          res = lhs->e223;
          break;
        case 7:
          res = lhs->e133;
          break;
        case 8:
          res = lhs->e233;
          break;
        case 9:
          res = lhs->e333;
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
        case 5:
          res = lhs->e1113;
          break;
        case 6:
          res = lhs->e1123;
          break;
        case 7:
          res = lhs->e1223;
          break;
        case 8:
          res = lhs->e2223;
          break;
        case 9:
          res = lhs->e1133;
          break;
        case 10:
          res = lhs->e1233;
          break;
        case 11:
          res = lhs->e2233;
          break;
        case 12:
          res = lhs->e1333;
          break;
        case 13:
          res = lhs->e2333;
          break;
        case 14:
          res = lhs->e3333;
          break;
      }
      break;
  }
  return res;

}

coeff_t onumm3n4_get_deriv(imdir_t idx, ord_t order, onumm3n4_t* lhs){

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
        case 4:
          factor = 2.0000000000000000e+00;
          res = lhs->e113*factor;
          break;
        case 5:
          factor = 1.0000000000000000e+00;
          res = lhs->e123*factor;
          break;
        case 6:
          factor = 2.0000000000000000e+00;
          res = lhs->e223*factor;
          break;
        case 7:
          factor = 2.0000000000000000e+00;
          res = lhs->e133*factor;
          break;
        case 8:
          factor = 2.0000000000000000e+00;
          res = lhs->e233*factor;
          break;
        case 9:
          factor = 6.0000000000000000e+00;
          res = lhs->e333*factor;
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
        case 5:
          factor = 6.0000000000000000e+00;
          res = lhs->e1113*factor;
          break;
        case 6:
          factor = 2.0000000000000000e+00;
          res = lhs->e1123*factor;
          break;
        case 7:
          factor = 2.0000000000000000e+00;
          res = lhs->e1223*factor;
          break;
        case 8:
          factor = 6.0000000000000000e+00;
          res = lhs->e2223*factor;
          break;
        case 9:
          factor = 4.0000000000000000e+00;
          res = lhs->e1133*factor;
          break;
        case 10:
          factor = 2.0000000000000000e+00;
          res = lhs->e1233*factor;
          break;
        case 11:
          factor = 4.0000000000000000e+00;
          res = lhs->e2233*factor;
          break;
        case 12:
          factor = 6.0000000000000000e+00;
          res = lhs->e1333*factor;
          break;
        case 13:
          factor = 6.0000000000000000e+00;
          res = lhs->e2333*factor;
          break;
        case 14:
          factor = 2.4000000000000000e+01;
          res = lhs->e3333*factor;
          break;
      }
      break;
  }
  return res;

}

void onumm3n4_set_item(coeff_t val, imdir_t idx, ord_t order, onumm3n4_t* x){

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
        case 4:
          x->e113 = val;
          break;
        case 5:
          x->e123 = val;
          break;
        case 6:
          x->e223 = val;
          break;
        case 7:
          x->e133 = val;
          break;
        case 8:
          x->e233 = val;
          break;
        case 9:
          x->e333 = val;
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
        case 5:
          x->e1113 = val;
          break;
        case 6:
          x->e1123 = val;
          break;
        case 7:
          x->e1223 = val;
          break;
        case 8:
          x->e2223 = val;
          break;
        case 9:
          x->e1133 = val;
          break;
        case 10:
          x->e1233 = val;
          break;
        case 11:
          x->e2233 = val;
          break;
        case 12:
          x->e1333 = val;
          break;
        case 13:
          x->e2333 = val;
          break;
        case 14:
          x->e3333 = val;
          break;
      }
      break;
  }
}

onumm3n4_t onumm3n4_copy(  onumm3n4_t* lhs){

  onumm3n4_t res;

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
  // Order 3;
  res.e111 = lhs->e111;
  res.e112 = lhs->e112;
  res.e122 = lhs->e122;
  res.e222 = lhs->e222;
  res.e113 = lhs->e113;
  res.e123 = lhs->e123;
  res.e223 = lhs->e223;
  res.e133 = lhs->e133;
  res.e233 = lhs->e233;
  res.e333 = lhs->e333;
  // Order 4;
  res.e1111 = lhs->e1111;
  res.e1112 = lhs->e1112;
  res.e1122 = lhs->e1122;
  res.e1222 = lhs->e1222;
  res.e2222 = lhs->e2222;
  res.e1113 = lhs->e1113;
  res.e1123 = lhs->e1123;
  res.e1223 = lhs->e1223;
  res.e2223 = lhs->e2223;
  res.e1133 = lhs->e1133;
  res.e1233 = lhs->e1233;
  res.e2233 = lhs->e2233;
  res.e1333 = lhs->e1333;
  res.e2333 = lhs->e2333;
  res.e3333 = lhs->e3333;

  return res;

}

void onumm3n4_copy_to(  onumm3n4_t* lhs, onumm3n4_t* res){

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
  // Order 3;
  res->e111 = lhs->e111;
  res->e112 = lhs->e112;
  res->e122 = lhs->e122;
  res->e222 = lhs->e222;
  res->e113 = lhs->e113;
  res->e123 = lhs->e123;
  res->e223 = lhs->e223;
  res->e133 = lhs->e133;
  res->e233 = lhs->e233;
  res->e333 = lhs->e333;
  // Order 4;
  res->e1111 = lhs->e1111;
  res->e1112 = lhs->e1112;
  res->e1122 = lhs->e1122;
  res->e1222 = lhs->e1222;
  res->e2222 = lhs->e2222;
  res->e1113 = lhs->e1113;
  res->e1123 = lhs->e1123;
  res->e1223 = lhs->e1223;
  res->e2223 = lhs->e2223;
  res->e1133 = lhs->e1133;
  res->e1233 = lhs->e1233;
  res->e2233 = lhs->e2233;
  res->e1333 = lhs->e1333;
  res->e2333 = lhs->e2333;
  res->e3333 = lhs->e3333;

}

onumm3n4_t onumm3n4_taylor_integrate(coeff_t* deltas,onumm3n4_t* lhs){

  onumm3n4_t res;

  res = onumm3n4_init();
  coeff_t factor;
  // Taylor integration
  // Real;
  res.r = lhs->r;
  // Order 1;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],0);
  res.r += factor*lhs->e1;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],0);
  res.r += factor*lhs->e2;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],1);
  res.r += factor*lhs->e3;
  // Order 2;
  factor = pow(deltas[0],2)*pow(deltas[1],0)*pow(deltas[2],0);
  res.r += factor*lhs->e11;
  factor = pow(deltas[0],1)*pow(deltas[1],1)*pow(deltas[2],0);
  res.r += factor*lhs->e12;
  factor = pow(deltas[0],0)*pow(deltas[1],2)*pow(deltas[2],0);
  res.r += factor*lhs->e22;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],1);
  res.r += factor*lhs->e13;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],1);
  res.r += factor*lhs->e23;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],2);
  res.r += factor*lhs->e33;
  // Order 3;
  factor = pow(deltas[0],3)*pow(deltas[1],0)*pow(deltas[2],0);
  res.r += factor*lhs->e111;
  factor = pow(deltas[0],2)*pow(deltas[1],1)*pow(deltas[2],0);
  res.r += factor*lhs->e112;
  factor = pow(deltas[0],1)*pow(deltas[1],2)*pow(deltas[2],0);
  res.r += factor*lhs->e122;
  factor = pow(deltas[0],0)*pow(deltas[1],3)*pow(deltas[2],0);
  res.r += factor*lhs->e222;
  factor = pow(deltas[0],2)*pow(deltas[1],0)*pow(deltas[2],1);
  res.r += factor*lhs->e113;
  factor = pow(deltas[0],1)*pow(deltas[1],1)*pow(deltas[2],1);
  res.r += factor*lhs->e123;
  factor = pow(deltas[0],0)*pow(deltas[1],2)*pow(deltas[2],1);
  res.r += factor*lhs->e223;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],2);
  res.r += factor*lhs->e133;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],2);
  res.r += factor*lhs->e233;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],3);
  res.r += factor*lhs->e333;
  // Order 4;
  factor = pow(deltas[0],4)*pow(deltas[1],0)*pow(deltas[2],0);
  res.r += factor*lhs->e1111;
  factor = pow(deltas[0],3)*pow(deltas[1],1)*pow(deltas[2],0);
  res.r += factor*lhs->e1112;
  factor = pow(deltas[0],2)*pow(deltas[1],2)*pow(deltas[2],0);
  res.r += factor*lhs->e1122;
  factor = pow(deltas[0],1)*pow(deltas[1],3)*pow(deltas[2],0);
  res.r += factor*lhs->e1222;
  factor = pow(deltas[0],0)*pow(deltas[1],4)*pow(deltas[2],0);
  res.r += factor*lhs->e2222;
  factor = pow(deltas[0],3)*pow(deltas[1],0)*pow(deltas[2],1);
  res.r += factor*lhs->e1113;
  factor = pow(deltas[0],2)*pow(deltas[1],1)*pow(deltas[2],1);
  res.r += factor*lhs->e1123;
  factor = pow(deltas[0],1)*pow(deltas[1],2)*pow(deltas[2],1);
  res.r += factor*lhs->e1223;
  factor = pow(deltas[0],0)*pow(deltas[1],3)*pow(deltas[2],1);
  res.r += factor*lhs->e2223;
  factor = pow(deltas[0],2)*pow(deltas[1],0)*pow(deltas[2],2);
  res.r += factor*lhs->e1133;
  factor = pow(deltas[0],1)*pow(deltas[1],1)*pow(deltas[2],2);
  res.r += factor*lhs->e1233;
  factor = pow(deltas[0],0)*pow(deltas[1],2)*pow(deltas[2],2);
  res.r += factor*lhs->e2233;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],3);
  res.r += factor*lhs->e1333;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],3);
  res.r += factor*lhs->e2333;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],4);
  res.r += factor*lhs->e3333;

  return res;

}

void onumm3n4_taylor_integrate_to(coeff_t* deltas,onumm3n4_t* lhs, onumm3n4_t* res){

  *res = onumm3n4_init();
  coeff_t factor;
  // Taylor integration
  // Real;
  res->r = lhs->r;
  // Order 1;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],0);
  res->r += factor*lhs->e1;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],0);
  res->r += factor*lhs->e2;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],1);
  res->r += factor*lhs->e3;
  // Order 2;
  factor = pow(deltas[0],2)*pow(deltas[1],0)*pow(deltas[2],0);
  res->r += factor*lhs->e11;
  factor = pow(deltas[0],1)*pow(deltas[1],1)*pow(deltas[2],0);
  res->r += factor*lhs->e12;
  factor = pow(deltas[0],0)*pow(deltas[1],2)*pow(deltas[2],0);
  res->r += factor*lhs->e22;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],1);
  res->r += factor*lhs->e13;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],1);
  res->r += factor*lhs->e23;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],2);
  res->r += factor*lhs->e33;
  // Order 3;
  factor = pow(deltas[0],3)*pow(deltas[1],0)*pow(deltas[2],0);
  res->r += factor*lhs->e111;
  factor = pow(deltas[0],2)*pow(deltas[1],1)*pow(deltas[2],0);
  res->r += factor*lhs->e112;
  factor = pow(deltas[0],1)*pow(deltas[1],2)*pow(deltas[2],0);
  res->r += factor*lhs->e122;
  factor = pow(deltas[0],0)*pow(deltas[1],3)*pow(deltas[2],0);
  res->r += factor*lhs->e222;
  factor = pow(deltas[0],2)*pow(deltas[1],0)*pow(deltas[2],1);
  res->r += factor*lhs->e113;
  factor = pow(deltas[0],1)*pow(deltas[1],1)*pow(deltas[2],1);
  res->r += factor*lhs->e123;
  factor = pow(deltas[0],0)*pow(deltas[1],2)*pow(deltas[2],1);
  res->r += factor*lhs->e223;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],2);
  res->r += factor*lhs->e133;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],2);
  res->r += factor*lhs->e233;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],3);
  res->r += factor*lhs->e333;
  // Order 4;
  factor = pow(deltas[0],4)*pow(deltas[1],0)*pow(deltas[2],0);
  res->r += factor*lhs->e1111;
  factor = pow(deltas[0],3)*pow(deltas[1],1)*pow(deltas[2],0);
  res->r += factor*lhs->e1112;
  factor = pow(deltas[0],2)*pow(deltas[1],2)*pow(deltas[2],0);
  res->r += factor*lhs->e1122;
  factor = pow(deltas[0],1)*pow(deltas[1],3)*pow(deltas[2],0);
  res->r += factor*lhs->e1222;
  factor = pow(deltas[0],0)*pow(deltas[1],4)*pow(deltas[2],0);
  res->r += factor*lhs->e2222;
  factor = pow(deltas[0],3)*pow(deltas[1],0)*pow(deltas[2],1);
  res->r += factor*lhs->e1113;
  factor = pow(deltas[0],2)*pow(deltas[1],1)*pow(deltas[2],1);
  res->r += factor*lhs->e1123;
  factor = pow(deltas[0],1)*pow(deltas[1],2)*pow(deltas[2],1);
  res->r += factor*lhs->e1223;
  factor = pow(deltas[0],0)*pow(deltas[1],3)*pow(deltas[2],1);
  res->r += factor*lhs->e2223;
  factor = pow(deltas[0],2)*pow(deltas[1],0)*pow(deltas[2],2);
  res->r += factor*lhs->e1133;
  factor = pow(deltas[0],1)*pow(deltas[1],1)*pow(deltas[2],2);
  res->r += factor*lhs->e1233;
  factor = pow(deltas[0],0)*pow(deltas[1],2)*pow(deltas[2],2);
  res->r += factor*lhs->e2233;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],3);
  res->r += factor*lhs->e1333;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],3);
  res->r += factor*lhs->e2333;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],4);
  res->r += factor*lhs->e3333;

}

onumm3n4_t onumm3n4_truncate_im(imdir_t idx, ord_t order, onumm3n4_t* lhs){

  onumm3n4_t res;

  // Copy number.
  res = (*lhs);
  // Truncate all other values when necessary.
  // Real;
  switch (order){
    case 0:
      res = onumm3n4_init();
      break;
    case 1:
      switch (idx){
        case 0: //  e1
          res.e1 = 0.0;
          res.e11 = 0.0;
          res.e12 = 0.0;
          res.e13 = 0.0;
          res.e111 = 0.0;
          res.e112 = 0.0;
          res.e122 = 0.0;
          res.e113 = 0.0;
          res.e123 = 0.0;
          res.e133 = 0.0;
          res.e1111 = 0.0;
          res.e1112 = 0.0;
          res.e1122 = 0.0;
          res.e1222 = 0.0;
          res.e1113 = 0.0;
          res.e1123 = 0.0;
          res.e1223 = 0.0;
          res.e1133 = 0.0;
          res.e1233 = 0.0;
          res.e1333 = 0.0;
          break;
        case 1: //  e2
          res.e2 = 0.0;
          res.e12 = 0.0;
          res.e22 = 0.0;
          res.e23 = 0.0;
          res.e112 = 0.0;
          res.e122 = 0.0;
          res.e222 = 0.0;
          res.e123 = 0.0;
          res.e223 = 0.0;
          res.e233 = 0.0;
          res.e1112 = 0.0;
          res.e1122 = 0.0;
          res.e1222 = 0.0;
          res.e2222 = 0.0;
          res.e1123 = 0.0;
          res.e1223 = 0.0;
          res.e2223 = 0.0;
          res.e1233 = 0.0;
          res.e2233 = 0.0;
          res.e2333 = 0.0;
          break;
        case 2: //  e3
          res.e3 = 0.0;
          res.e13 = 0.0;
          res.e23 = 0.0;
          res.e33 = 0.0;
          res.e113 = 0.0;
          res.e123 = 0.0;
          res.e223 = 0.0;
          res.e133 = 0.0;
          res.e233 = 0.0;
          res.e333 = 0.0;
          res.e1113 = 0.0;
          res.e1123 = 0.0;
          res.e1223 = 0.0;
          res.e2223 = 0.0;
          res.e1133 = 0.0;
          res.e1233 = 0.0;
          res.e2233 = 0.0;
          res.e1333 = 0.0;
          res.e2333 = 0.0;
          res.e3333 = 0.0;
          break;
      }
      break;
    case 2:
      switch (idx){
        case 0: //  e11
          res.e11 = 0.0;
          res.e111 = 0.0;
          res.e112 = 0.0;
          res.e113 = 0.0;
          res.e1111 = 0.0;
          res.e1112 = 0.0;
          res.e1122 = 0.0;
          res.e1113 = 0.0;
          res.e1123 = 0.0;
          res.e1133 = 0.0;
          break;
        case 1: //  e12
          res.e12 = 0.0;
          res.e112 = 0.0;
          res.e122 = 0.0;
          res.e123 = 0.0;
          res.e1112 = 0.0;
          res.e1122 = 0.0;
          res.e1222 = 0.0;
          res.e1123 = 0.0;
          res.e1223 = 0.0;
          res.e1233 = 0.0;
          break;
        case 2: //  e22
          res.e22 = 0.0;
          res.e122 = 0.0;
          res.e222 = 0.0;
          res.e223 = 0.0;
          res.e1122 = 0.0;
          res.e1222 = 0.0;
          res.e2222 = 0.0;
          res.e1223 = 0.0;
          res.e2223 = 0.0;
          res.e2233 = 0.0;
          break;
        case 3: //  e13
          res.e13 = 0.0;
          res.e113 = 0.0;
          res.e123 = 0.0;
          res.e133 = 0.0;
          res.e1113 = 0.0;
          res.e1123 = 0.0;
          res.e1223 = 0.0;
          res.e1133 = 0.0;
          res.e1233 = 0.0;
          res.e1333 = 0.0;
          break;
        case 4: //  e23
          res.e23 = 0.0;
          res.e123 = 0.0;
          res.e223 = 0.0;
          res.e233 = 0.0;
          res.e1123 = 0.0;
          res.e1223 = 0.0;
          res.e2223 = 0.0;
          res.e1233 = 0.0;
          res.e2233 = 0.0;
          res.e2333 = 0.0;
          break;
        case 5: //  e33
          res.e33 = 0.0;
          res.e133 = 0.0;
          res.e233 = 0.0;
          res.e333 = 0.0;
          res.e1133 = 0.0;
          res.e1233 = 0.0;
          res.e2233 = 0.0;
          res.e1333 = 0.0;
          res.e2333 = 0.0;
          res.e3333 = 0.0;
          break;
      }
      break;
    case 3:
      switch (idx){
        case 0: //  e111
          res.e111 = 0.0;
          res.e1111 = 0.0;
          res.e1112 = 0.0;
          res.e1113 = 0.0;
          break;
        case 1: //  e112
          res.e112 = 0.0;
          res.e1112 = 0.0;
          res.e1122 = 0.0;
          res.e1123 = 0.0;
          break;
        case 2: //  e122
          res.e122 = 0.0;
          res.e1122 = 0.0;
          res.e1222 = 0.0;
          res.e1223 = 0.0;
          break;
        case 3: //  e222
          res.e222 = 0.0;
          res.e1222 = 0.0;
          res.e2222 = 0.0;
          res.e2223 = 0.0;
          break;
        case 4: //  e113
          res.e113 = 0.0;
          res.e1113 = 0.0;
          res.e1123 = 0.0;
          res.e1133 = 0.0;
          break;
        case 5: //  e123
          res.e123 = 0.0;
          res.e1123 = 0.0;
          res.e1223 = 0.0;
          res.e1233 = 0.0;
          break;
        case 6: //  e223
          res.e223 = 0.0;
          res.e1223 = 0.0;
          res.e2223 = 0.0;
          res.e2233 = 0.0;
          break;
        case 7: //  e133
          res.e133 = 0.0;
          res.e1133 = 0.0;
          res.e1233 = 0.0;
          res.e1333 = 0.0;
          break;
        case 8: //  e233
          res.e233 = 0.0;
          res.e1233 = 0.0;
          res.e2233 = 0.0;
          res.e2333 = 0.0;
          break;
        case 9: //  e333
          res.e333 = 0.0;
          res.e1333 = 0.0;
          res.e2333 = 0.0;
          res.e3333 = 0.0;
          break;
      }
      break;
    case 4:
      switch (idx){
        case 0: //  e1111
          res.e1111 = 0.0;
          break;
        case 1: //  e1112
          res.e1112 = 0.0;
          break;
        case 2: //  e1122
          res.e1122 = 0.0;
          break;
        case 3: //  e1222
          res.e1222 = 0.0;
          break;
        case 4: //  e2222
          res.e2222 = 0.0;
          break;
        case 5: //  e1113
          res.e1113 = 0.0;
          break;
        case 6: //  e1123
          res.e1123 = 0.0;
          break;
        case 7: //  e1223
          res.e1223 = 0.0;
          break;
        case 8: //  e2223
          res.e2223 = 0.0;
          break;
        case 9: //  e1133
          res.e1133 = 0.0;
          break;
        case 10: //  e1233
          res.e1233 = 0.0;
          break;
        case 11: //  e2233
          res.e2233 = 0.0;
          break;
        case 12: //  e1333
          res.e1333 = 0.0;
          break;
        case 13: //  e2333
          res.e2333 = 0.0;
          break;
        case 14: //  e3333
          res.e3333 = 0.0;
          break;
      }
      break;
  }
  return res;

}

void onumm3n4_truncate_im_to(imdir_t idx, ord_t order, onumm3n4_t* lhs, onumm3n4_t* res){

  // Copy number.
  *res = (*lhs);
  // Truncate all other values when necessary.
  // Real;
  switch (order){
    case 0:
      *res = onumm3n4_init();
      break;
    case 1:
      switch (idx){
        case 0: //  e1
          res->e1 = 0.0;
          res->e11 = 0.0;
          res->e12 = 0.0;
          res->e13 = 0.0;
          res->e111 = 0.0;
          res->e112 = 0.0;
          res->e122 = 0.0;
          res->e113 = 0.0;
          res->e123 = 0.0;
          res->e133 = 0.0;
          res->e1111 = 0.0;
          res->e1112 = 0.0;
          res->e1122 = 0.0;
          res->e1222 = 0.0;
          res->e1113 = 0.0;
          res->e1123 = 0.0;
          res->e1223 = 0.0;
          res->e1133 = 0.0;
          res->e1233 = 0.0;
          res->e1333 = 0.0;
          break;
        case 1: //  e2
          res->e2 = 0.0;
          res->e12 = 0.0;
          res->e22 = 0.0;
          res->e23 = 0.0;
          res->e112 = 0.0;
          res->e122 = 0.0;
          res->e222 = 0.0;
          res->e123 = 0.0;
          res->e223 = 0.0;
          res->e233 = 0.0;
          res->e1112 = 0.0;
          res->e1122 = 0.0;
          res->e1222 = 0.0;
          res->e2222 = 0.0;
          res->e1123 = 0.0;
          res->e1223 = 0.0;
          res->e2223 = 0.0;
          res->e1233 = 0.0;
          res->e2233 = 0.0;
          res->e2333 = 0.0;
          break;
        case 2: //  e3
          res->e3 = 0.0;
          res->e13 = 0.0;
          res->e23 = 0.0;
          res->e33 = 0.0;
          res->e113 = 0.0;
          res->e123 = 0.0;
          res->e223 = 0.0;
          res->e133 = 0.0;
          res->e233 = 0.0;
          res->e333 = 0.0;
          res->e1113 = 0.0;
          res->e1123 = 0.0;
          res->e1223 = 0.0;
          res->e2223 = 0.0;
          res->e1133 = 0.0;
          res->e1233 = 0.0;
          res->e2233 = 0.0;
          res->e1333 = 0.0;
          res->e2333 = 0.0;
          res->e3333 = 0.0;
          break;
      }
      break;
    case 2:
      switch (idx){
        case 0: //  e11
          res->e11 = 0.0;
          res->e111 = 0.0;
          res->e112 = 0.0;
          res->e113 = 0.0;
          res->e1111 = 0.0;
          res->e1112 = 0.0;
          res->e1122 = 0.0;
          res->e1113 = 0.0;
          res->e1123 = 0.0;
          res->e1133 = 0.0;
          break;
        case 1: //  e12
          res->e12 = 0.0;
          res->e112 = 0.0;
          res->e122 = 0.0;
          res->e123 = 0.0;
          res->e1112 = 0.0;
          res->e1122 = 0.0;
          res->e1222 = 0.0;
          res->e1123 = 0.0;
          res->e1223 = 0.0;
          res->e1233 = 0.0;
          break;
        case 2: //  e22
          res->e22 = 0.0;
          res->e122 = 0.0;
          res->e222 = 0.0;
          res->e223 = 0.0;
          res->e1122 = 0.0;
          res->e1222 = 0.0;
          res->e2222 = 0.0;
          res->e1223 = 0.0;
          res->e2223 = 0.0;
          res->e2233 = 0.0;
          break;
        case 3: //  e13
          res->e13 = 0.0;
          res->e113 = 0.0;
          res->e123 = 0.0;
          res->e133 = 0.0;
          res->e1113 = 0.0;
          res->e1123 = 0.0;
          res->e1223 = 0.0;
          res->e1133 = 0.0;
          res->e1233 = 0.0;
          res->e1333 = 0.0;
          break;
        case 4: //  e23
          res->e23 = 0.0;
          res->e123 = 0.0;
          res->e223 = 0.0;
          res->e233 = 0.0;
          res->e1123 = 0.0;
          res->e1223 = 0.0;
          res->e2223 = 0.0;
          res->e1233 = 0.0;
          res->e2233 = 0.0;
          res->e2333 = 0.0;
          break;
        case 5: //  e33
          res->e33 = 0.0;
          res->e133 = 0.0;
          res->e233 = 0.0;
          res->e333 = 0.0;
          res->e1133 = 0.0;
          res->e1233 = 0.0;
          res->e2233 = 0.0;
          res->e1333 = 0.0;
          res->e2333 = 0.0;
          res->e3333 = 0.0;
          break;
      }
      break;
    case 3:
      switch (idx){
        case 0: //  e111
          res->e111 = 0.0;
          res->e1111 = 0.0;
          res->e1112 = 0.0;
          res->e1113 = 0.0;
          break;
        case 1: //  e112
          res->e112 = 0.0;
          res->e1112 = 0.0;
          res->e1122 = 0.0;
          res->e1123 = 0.0;
          break;
        case 2: //  e122
          res->e122 = 0.0;
          res->e1122 = 0.0;
          res->e1222 = 0.0;
          res->e1223 = 0.0;
          break;
        case 3: //  e222
          res->e222 = 0.0;
          res->e1222 = 0.0;
          res->e2222 = 0.0;
          res->e2223 = 0.0;
          break;
        case 4: //  e113
          res->e113 = 0.0;
          res->e1113 = 0.0;
          res->e1123 = 0.0;
          res->e1133 = 0.0;
          break;
        case 5: //  e123
          res->e123 = 0.0;
          res->e1123 = 0.0;
          res->e1223 = 0.0;
          res->e1233 = 0.0;
          break;
        case 6: //  e223
          res->e223 = 0.0;
          res->e1223 = 0.0;
          res->e2223 = 0.0;
          res->e2233 = 0.0;
          break;
        case 7: //  e133
          res->e133 = 0.0;
          res->e1133 = 0.0;
          res->e1233 = 0.0;
          res->e1333 = 0.0;
          break;
        case 8: //  e233
          res->e233 = 0.0;
          res->e1233 = 0.0;
          res->e2233 = 0.0;
          res->e2333 = 0.0;
          break;
        case 9: //  e333
          res->e333 = 0.0;
          res->e1333 = 0.0;
          res->e2333 = 0.0;
          res->e3333 = 0.0;
          break;
      }
      break;
    case 4:
      switch (idx){
        case 0: //  e1111
          res->e1111 = 0.0;
          break;
        case 1: //  e1112
          res->e1112 = 0.0;
          break;
        case 2: //  e1122
          res->e1122 = 0.0;
          break;
        case 3: //  e1222
          res->e1222 = 0.0;
          break;
        case 4: //  e2222
          res->e2222 = 0.0;
          break;
        case 5: //  e1113
          res->e1113 = 0.0;
          break;
        case 6: //  e1123
          res->e1123 = 0.0;
          break;
        case 7: //  e1223
          res->e1223 = 0.0;
          break;
        case 8: //  e2223
          res->e2223 = 0.0;
          break;
        case 9: //  e1133
          res->e1133 = 0.0;
          break;
        case 10: //  e1233
          res->e1233 = 0.0;
          break;
        case 11: //  e2233
          res->e2233 = 0.0;
          break;
        case 12: //  e1333
          res->e1333 = 0.0;
          break;
        case 13: //  e2333
          res->e2333 = 0.0;
          break;
        case 14: //  e3333
          res->e3333 = 0.0;
          break;
      }
      break;
  }
}

void onumm3n4_print(  onumm3n4_t* lhs){

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
  //  Order 3;
  printf(" %+.8g*e111",lhs->e111);
  printf(" %+.8g*e112",lhs->e112);
  printf(" %+.8g*e122",lhs->e122);
  printf(" %+.8g*e222",lhs->e222);
  printf(" %+.8g*e113",lhs->e113);
  printf(" %+.8g*e123",lhs->e123);
  printf(" %+.8g*e223",lhs->e223);
  printf(" %+.8g*e133",lhs->e133);
  printf(" %+.8g*e233",lhs->e233);
  printf(" %+.8g*e333",lhs->e333);
  //  Order 4;
  printf(" %+.8g*e1111",lhs->e1111);
  printf(" %+.8g*e1112",lhs->e1112);
  printf(" %+.8g*e1122",lhs->e1122);
  printf(" %+.8g*e1222",lhs->e1222);
  printf(" %+.8g*e2222",lhs->e2222);
  printf(" %+.8g*e1113",lhs->e1113);
  printf(" %+.8g*e1123",lhs->e1123);
  printf(" %+.8g*e1223",lhs->e1223);
  printf(" %+.8g*e2223",lhs->e2223);
  printf(" %+.8g*e1133",lhs->e1133);
  printf(" %+.8g*e1233",lhs->e1233);
  printf(" %+.8g*e2233",lhs->e2233);
  printf(" %+.8g*e1333",lhs->e1333);
  printf(" %+.8g*e2333",lhs->e2333);
  printf(" %+.8g*e3333",lhs->e3333);
  printf("\n");

}

imdir_t onumm3n4_get_indx(imdir_t idx, ord_t order){

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
      }
      break;
      default:
          return 0;
  }
  return 0;
}

