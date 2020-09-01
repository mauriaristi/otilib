

// Not implemented correctly:
void onumm5n3_set_im_o(onumm5n3_t* num, imdir_t idx, ord_t order, onumm5n3_t* res){
    onumm5n3_set_item(num->r,idx,order,res);
}
void onumm5n3_set_deriv_r(coeff_t num, imdir_t idx, ord_t order, onumm5n3_t* res){
    *res=onumm5n3_init();
}
void onumm5n3_set_deriv_o(onumm5n3_t* num, imdir_t idx, ord_t order, onumm5n3_t* res){
    *res=onumm5n3_init();
}
void onumm5n3_extract_im_to( imdir_t idx, ord_t order, onumm5n3_t* num, onumm5n3_t* res){
    *res=onumm5n3_init();
}
onumm5n3_t onumm5n3_extract_im(imdir_t idx, ord_t order, onumm5n3_t* num){
    onumm5n3_t res = onumm5n3_init();
    return res;
}
onumm5n3_t onumm5n3_extract_deriv(imdir_t idx, ord_t order, onumm5n3_t* num){
    onumm5n3_t res = onumm5n3_init();
    return res;
}
void onumm5n3_extract_deriv_to(imdir_t idx, ord_t order, onumm5n3_t* num, onumm5n3_t* res){
	*res = onumm5n3_init();
}
void onumm5n3_get_im_to_o(imdir_t idx, ord_t order, onumm5n3_t* num, onumm5n3_t* res){
    coeff_t rres = onumm5n3_get_item(idx, order, num);
    onumm5n3_set_r(rres,res);
}
onumm5n3_t onumm5n3_get_im_o(imdir_t idx, ord_t order, onumm5n3_t* num){
    coeff_t rres = onumm5n3_get_item(idx, order, num);
    onumm5n3_t res;
    onumm5n3_set_r(rres,&res);
    return res;
}
void onumm5n3_get_im_to_r(imdir_t idx, ord_t order, onumm5n3_t* num, coeff_t* res){
    *res = onumm5n3_get_item(idx, order, num);
}

inline ord_t onumm5n3_get_order(onumm5n3_t* lhs){

	return 3;

}

onumm5n3_t onumm5n3_get_deriv_o( imdir_t idx, ord_t order, onumm5n3_t* num){

    onumm5n3_t res = onumm5n3_init();

    onumm5n3_get_deriv_to( idx, order, num, &res);
    
    return res;

}

void onumm5n3_get_deriv_to( imdir_t idx, ord_t order, onumm5n3_t* num, onumm5n3_t* res){

    coeff_t deriv = onumm5n3_get_deriv(idx,order,num);

    onumm5n3_set_r( deriv, res);

}

void onumm5n3_set_im_r(coeff_t num, imdir_t idx, ord_t order, onumm5n3_t* res){

    onumm5n3_set_item(num, idx,order,res);

}

onumm5n3_t onumm5n3_init(void){

  onumm5n3_t res;

  // Init function
  // Real;
  res.r = 0.0;
  // Order 1;
  res.e1 = 0.0;
  res.e2 = 0.0;
  res.e3 = 0.0;
  res.e4 = 0.0;
  res.e5 = 0.0;
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
  res.e114 = 0.0;
  res.e124 = 0.0;
  res.e224 = 0.0;
  res.e134 = 0.0;
  res.e234 = 0.0;
  res.e334 = 0.0;
  res.e144 = 0.0;
  res.e244 = 0.0;
  res.e344 = 0.0;
  res.e444 = 0.0;
  res.e115 = 0.0;
  res.e125 = 0.0;
  res.e225 = 0.0;
  res.e135 = 0.0;
  res.e235 = 0.0;
  res.e335 = 0.0;
  res.e145 = 0.0;
  res.e245 = 0.0;
  res.e345 = 0.0;
  res.e445 = 0.0;
  res.e155 = 0.0;
  res.e255 = 0.0;
  res.e355 = 0.0;
  res.e455 = 0.0;
  res.e555 = 0.0;

  return res;

}

ndir_t onumm5n3_get_ndir_order(ord_t order, onumm5n3_t* num){

  ndir_t res;

  switch(order){
    case 0:
      res = 1;
      break;
    case 1:
      res = 5;
      break;
    case 2:
      res = 15;
      break;
    case 3:
      res = 35;
      break;
  }

  return res;

}

ndir_t onumm5n3_get_ndir_total(onumm5n3_t* num){

  ndir_t res;

  res = 21;

  return res;

}

coeff_t* onumm5n3_get_order_address(ord_t order, onumm5n3_t* num){

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

onumm5n3_t onumm5n3_create_r(  coeff_t lhs){

  onumm5n3_t res;

  // Assign like function 'lhs'
  // Real;
  res.r = lhs;
  // Order 1;
  res.e1 = 0.0;
  res.e2 = 0.0;
  res.e3 = 0.0;
  res.e4 = 0.0;
  res.e5 = 0.0;
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
  res.e114 = 0.0;
  res.e124 = 0.0;
  res.e224 = 0.0;
  res.e134 = 0.0;
  res.e234 = 0.0;
  res.e334 = 0.0;
  res.e144 = 0.0;
  res.e244 = 0.0;
  res.e344 = 0.0;
  res.e444 = 0.0;
  res.e115 = 0.0;
  res.e125 = 0.0;
  res.e225 = 0.0;
  res.e135 = 0.0;
  res.e235 = 0.0;
  res.e335 = 0.0;
  res.e145 = 0.0;
  res.e245 = 0.0;
  res.e345 = 0.0;
  res.e445 = 0.0;
  res.e155 = 0.0;
  res.e255 = 0.0;
  res.e355 = 0.0;
  res.e455 = 0.0;
  res.e555 = 0.0;

  return res;

}

void onumm5n3_set_r(  coeff_t lhs, onumm5n3_t* res){

  // Assign like function 'lhs'
  // Real;
  res->r = lhs;
  // Order 1;
  res->e1 = 0.0;
  res->e2 = 0.0;
  res->e3 = 0.0;
  res->e4 = 0.0;
  res->e5 = 0.0;
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
  res->e114 = 0.0;
  res->e124 = 0.0;
  res->e224 = 0.0;
  res->e134 = 0.0;
  res->e234 = 0.0;
  res->e334 = 0.0;
  res->e144 = 0.0;
  res->e244 = 0.0;
  res->e344 = 0.0;
  res->e444 = 0.0;
  res->e115 = 0.0;
  res->e125 = 0.0;
  res->e225 = 0.0;
  res->e135 = 0.0;
  res->e235 = 0.0;
  res->e335 = 0.0;
  res->e145 = 0.0;
  res->e245 = 0.0;
  res->e345 = 0.0;
  res->e445 = 0.0;
  res->e155 = 0.0;
  res->e255 = 0.0;
  res->e355 = 0.0;
  res->e455 = 0.0;
  res->e555 = 0.0;

}

void onumm5n3_set_o(  onumm5n3_t* lhs, onumm5n3_t* res){

  // Assign like function 'lhs'
  // Real;
  res->r = lhs->r;
  // Order 1;
  res->e1 = lhs->e1;
  res->e2 = lhs->e2;
  res->e3 = lhs->e3;
  res->e4 = lhs->e4;
  res->e5 = lhs->e5;
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
  res->e114 = lhs->e114;
  res->e124 = lhs->e124;
  res->e224 = lhs->e224;
  res->e134 = lhs->e134;
  res->e234 = lhs->e234;
  res->e334 = lhs->e334;
  res->e144 = lhs->e144;
  res->e244 = lhs->e244;
  res->e344 = lhs->e344;
  res->e444 = lhs->e444;
  res->e115 = lhs->e115;
  res->e125 = lhs->e125;
  res->e225 = lhs->e225;
  res->e135 = lhs->e135;
  res->e235 = lhs->e235;
  res->e335 = lhs->e335;
  res->e145 = lhs->e145;
  res->e245 = lhs->e245;
  res->e345 = lhs->e345;
  res->e445 = lhs->e445;
  res->e155 = lhs->e155;
  res->e255 = lhs->e255;
  res->e355 = lhs->e355;
  res->e455 = lhs->e455;
  res->e555 = lhs->e555;

}

onumm5n3_t onumm5n3_get_order_im(ord_t order, onumm5n3_t* lhs){

  onumm5n3_t res;

  res = onumm5n3_init();
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
      res.e114 = lhs->e114;
      res.e124 = lhs->e124;
      res.e224 = lhs->e224;
      res.e134 = lhs->e134;
      res.e234 = lhs->e234;
      res.e334 = lhs->e334;
      res.e144 = lhs->e144;
      res.e244 = lhs->e244;
      res.e344 = lhs->e344;
      res.e444 = lhs->e444;
      res.e115 = lhs->e115;
      res.e125 = lhs->e125;
      res.e225 = lhs->e225;
      res.e135 = lhs->e135;
      res.e235 = lhs->e235;
      res.e335 = lhs->e335;
      res.e145 = lhs->e145;
      res.e245 = lhs->e245;
      res.e345 = lhs->e345;
      res.e445 = lhs->e445;
      res.e155 = lhs->e155;
      res.e255 = lhs->e255;
      res.e355 = lhs->e355;
      res.e455 = lhs->e455;
      res.e555 = lhs->e555;
      break;
  }

  return res;

}

void onumm5n3_get_order_im_to(ord_t order, onumm5n3_t* lhs, onumm5n3_t* res){


  *res = onumm5n3_init();
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
      res->e114 = lhs->e114;
      res->e124 = lhs->e124;
      res->e224 = lhs->e224;
      res->e134 = lhs->e134;
      res->e234 = lhs->e234;
      res->e334 = lhs->e334;
      res->e144 = lhs->e144;
      res->e244 = lhs->e244;
      res->e344 = lhs->e344;
      res->e444 = lhs->e444;
      res->e115 = lhs->e115;
      res->e125 = lhs->e125;
      res->e225 = lhs->e225;
      res->e135 = lhs->e135;
      res->e235 = lhs->e235;
      res->e335 = lhs->e335;
      res->e145 = lhs->e145;
      res->e245 = lhs->e245;
      res->e345 = lhs->e345;
      res->e445 = lhs->e445;
      res->e155 = lhs->e155;
      res->e255 = lhs->e255;
      res->e355 = lhs->e355;
      res->e455 = lhs->e455;
      res->e555 = lhs->e555;
      break;
  }

}

coeff_t onumm5n3_get_item(imdir_t idx, ord_t order, onumm5n3_t* lhs){

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
        case 10:
          res = lhs->e114;
          break;
        case 11:
          res = lhs->e124;
          break;
        case 12:
          res = lhs->e224;
          break;
        case 13:
          res = lhs->e134;
          break;
        case 14:
          res = lhs->e234;
          break;
        case 15:
          res = lhs->e334;
          break;
        case 16:
          res = lhs->e144;
          break;
        case 17:
          res = lhs->e244;
          break;
        case 18:
          res = lhs->e344;
          break;
        case 19:
          res = lhs->e444;
          break;
        case 20:
          res = lhs->e115;
          break;
        case 21:
          res = lhs->e125;
          break;
        case 22:
          res = lhs->e225;
          break;
        case 23:
          res = lhs->e135;
          break;
        case 24:
          res = lhs->e235;
          break;
        case 25:
          res = lhs->e335;
          break;
        case 26:
          res = lhs->e145;
          break;
        case 27:
          res = lhs->e245;
          break;
        case 28:
          res = lhs->e345;
          break;
        case 29:
          res = lhs->e445;
          break;
        case 30:
          res = lhs->e155;
          break;
        case 31:
          res = lhs->e255;
          break;
        case 32:
          res = lhs->e355;
          break;
        case 33:
          res = lhs->e455;
          break;
        case 34:
          res = lhs->e555;
          break;
      }
      break;
  }
  return res;

}

coeff_t onumm5n3_get_deriv(imdir_t idx, ord_t order, onumm5n3_t* lhs){

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
        case 10:
          factor = 2.0000000000000000e+00;
          res = lhs->e114*factor;
          break;
        case 11:
          factor = 1.0000000000000000e+00;
          res = lhs->e124*factor;
          break;
        case 12:
          factor = 2.0000000000000000e+00;
          res = lhs->e224*factor;
          break;
        case 13:
          factor = 1.0000000000000000e+00;
          res = lhs->e134*factor;
          break;
        case 14:
          factor = 1.0000000000000000e+00;
          res = lhs->e234*factor;
          break;
        case 15:
          factor = 2.0000000000000000e+00;
          res = lhs->e334*factor;
          break;
        case 16:
          factor = 2.0000000000000000e+00;
          res = lhs->e144*factor;
          break;
        case 17:
          factor = 2.0000000000000000e+00;
          res = lhs->e244*factor;
          break;
        case 18:
          factor = 2.0000000000000000e+00;
          res = lhs->e344*factor;
          break;
        case 19:
          factor = 6.0000000000000000e+00;
          res = lhs->e444*factor;
          break;
        case 20:
          factor = 2.0000000000000000e+00;
          res = lhs->e115*factor;
          break;
        case 21:
          factor = 1.0000000000000000e+00;
          res = lhs->e125*factor;
          break;
        case 22:
          factor = 2.0000000000000000e+00;
          res = lhs->e225*factor;
          break;
        case 23:
          factor = 1.0000000000000000e+00;
          res = lhs->e135*factor;
          break;
        case 24:
          factor = 1.0000000000000000e+00;
          res = lhs->e235*factor;
          break;
        case 25:
          factor = 2.0000000000000000e+00;
          res = lhs->e335*factor;
          break;
        case 26:
          factor = 1.0000000000000000e+00;
          res = lhs->e145*factor;
          break;
        case 27:
          factor = 1.0000000000000000e+00;
          res = lhs->e245*factor;
          break;
        case 28:
          factor = 1.0000000000000000e+00;
          res = lhs->e345*factor;
          break;
        case 29:
          factor = 2.0000000000000000e+00;
          res = lhs->e445*factor;
          break;
        case 30:
          factor = 2.0000000000000000e+00;
          res = lhs->e155*factor;
          break;
        case 31:
          factor = 2.0000000000000000e+00;
          res = lhs->e255*factor;
          break;
        case 32:
          factor = 2.0000000000000000e+00;
          res = lhs->e355*factor;
          break;
        case 33:
          factor = 2.0000000000000000e+00;
          res = lhs->e455*factor;
          break;
        case 34:
          factor = 6.0000000000000000e+00;
          res = lhs->e555*factor;
          break;
      }
      break;
  }
  return res;

}

void onumm5n3_set_item(coeff_t val, imdir_t idx, ord_t order, onumm5n3_t* x){

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
        case 10:
          x->e114 = val;
          break;
        case 11:
          x->e124 = val;
          break;
        case 12:
          x->e224 = val;
          break;
        case 13:
          x->e134 = val;
          break;
        case 14:
          x->e234 = val;
          break;
        case 15:
          x->e334 = val;
          break;
        case 16:
          x->e144 = val;
          break;
        case 17:
          x->e244 = val;
          break;
        case 18:
          x->e344 = val;
          break;
        case 19:
          x->e444 = val;
          break;
        case 20:
          x->e115 = val;
          break;
        case 21:
          x->e125 = val;
          break;
        case 22:
          x->e225 = val;
          break;
        case 23:
          x->e135 = val;
          break;
        case 24:
          x->e235 = val;
          break;
        case 25:
          x->e335 = val;
          break;
        case 26:
          x->e145 = val;
          break;
        case 27:
          x->e245 = val;
          break;
        case 28:
          x->e345 = val;
          break;
        case 29:
          x->e445 = val;
          break;
        case 30:
          x->e155 = val;
          break;
        case 31:
          x->e255 = val;
          break;
        case 32:
          x->e355 = val;
          break;
        case 33:
          x->e455 = val;
          break;
        case 34:
          x->e555 = val;
          break;
      }
      break;
  }
}

onumm5n3_t onumm5n3_copy(  onumm5n3_t* lhs){

  onumm5n3_t res;

  // Assign like function 'lhs'
  // Real;
  res.r = lhs->r;
  // Order 1;
  res.e1 = lhs->e1;
  res.e2 = lhs->e2;
  res.e3 = lhs->e3;
  res.e4 = lhs->e4;
  res.e5 = lhs->e5;
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
  res.e114 = lhs->e114;
  res.e124 = lhs->e124;
  res.e224 = lhs->e224;
  res.e134 = lhs->e134;
  res.e234 = lhs->e234;
  res.e334 = lhs->e334;
  res.e144 = lhs->e144;
  res.e244 = lhs->e244;
  res.e344 = lhs->e344;
  res.e444 = lhs->e444;
  res.e115 = lhs->e115;
  res.e125 = lhs->e125;
  res.e225 = lhs->e225;
  res.e135 = lhs->e135;
  res.e235 = lhs->e235;
  res.e335 = lhs->e335;
  res.e145 = lhs->e145;
  res.e245 = lhs->e245;
  res.e345 = lhs->e345;
  res.e445 = lhs->e445;
  res.e155 = lhs->e155;
  res.e255 = lhs->e255;
  res.e355 = lhs->e355;
  res.e455 = lhs->e455;
  res.e555 = lhs->e555;

  return res;

}

void onumm5n3_copy_to(  onumm5n3_t* lhs, onumm5n3_t* res){

  // Assign like function 'lhs'
  // Real;
  res->r = lhs->r;
  // Order 1;
  res->e1 = lhs->e1;
  res->e2 = lhs->e2;
  res->e3 = lhs->e3;
  res->e4 = lhs->e4;
  res->e5 = lhs->e5;
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
  res->e114 = lhs->e114;
  res->e124 = lhs->e124;
  res->e224 = lhs->e224;
  res->e134 = lhs->e134;
  res->e234 = lhs->e234;
  res->e334 = lhs->e334;
  res->e144 = lhs->e144;
  res->e244 = lhs->e244;
  res->e344 = lhs->e344;
  res->e444 = lhs->e444;
  res->e115 = lhs->e115;
  res->e125 = lhs->e125;
  res->e225 = lhs->e225;
  res->e135 = lhs->e135;
  res->e235 = lhs->e235;
  res->e335 = lhs->e335;
  res->e145 = lhs->e145;
  res->e245 = lhs->e245;
  res->e345 = lhs->e345;
  res->e445 = lhs->e445;
  res->e155 = lhs->e155;
  res->e255 = lhs->e255;
  res->e355 = lhs->e355;
  res->e455 = lhs->e455;
  res->e555 = lhs->e555;

}

onumm5n3_t onumm5n3_taylor_integrate(coeff_t* deltas,onumm5n3_t* lhs){

  onumm5n3_t res;

  res = onumm5n3_init();
  coeff_t factor;
  // Taylor integration
  // Real;
  res.r = lhs->r;
  // Order 1;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],0);
  res.r += factor*lhs->e1;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],0);
  res.r += factor*lhs->e2;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],0)*pow(deltas[4],0);
  res.r += factor*lhs->e3;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],1)*pow(deltas[4],0);
  res.r += factor*lhs->e4;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],1);
  res.r += factor*lhs->e5;
  // Order 2;
  factor = pow(deltas[0],2)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],0);
  res.r += factor*lhs->e11;
  factor = pow(deltas[0],1)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],0);
  res.r += factor*lhs->e12;
  factor = pow(deltas[0],0)*pow(deltas[1],2)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],0);
  res.r += factor*lhs->e22;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],0)*pow(deltas[4],0);
  res.r += factor*lhs->e13;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],1)*pow(deltas[3],0)*pow(deltas[4],0);
  res.r += factor*lhs->e23;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],2)*pow(deltas[3],0)*pow(deltas[4],0);
  res.r += factor*lhs->e33;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],1)*pow(deltas[4],0);
  res.r += factor*lhs->e14;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],1)*pow(deltas[4],0);
  res.r += factor*lhs->e24;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],1)*pow(deltas[4],0);
  res.r += factor*lhs->e34;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],2)*pow(deltas[4],0);
  res.r += factor*lhs->e44;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],1);
  res.r += factor*lhs->e15;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],1);
  res.r += factor*lhs->e25;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],0)*pow(deltas[4],1);
  res.r += factor*lhs->e35;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],1)*pow(deltas[4],1);
  res.r += factor*lhs->e45;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],2);
  res.r += factor*lhs->e55;
  // Order 3;
  factor = pow(deltas[0],3)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],0);
  res.r += factor*lhs->e111;
  factor = pow(deltas[0],2)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],0);
  res.r += factor*lhs->e112;
  factor = pow(deltas[0],1)*pow(deltas[1],2)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],0);
  res.r += factor*lhs->e122;
  factor = pow(deltas[0],0)*pow(deltas[1],3)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],0);
  res.r += factor*lhs->e222;
  factor = pow(deltas[0],2)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],0)*pow(deltas[4],0);
  res.r += factor*lhs->e113;
  factor = pow(deltas[0],1)*pow(deltas[1],1)*pow(deltas[2],1)*pow(deltas[3],0)*pow(deltas[4],0);
  res.r += factor*lhs->e123;
  factor = pow(deltas[0],0)*pow(deltas[1],2)*pow(deltas[2],1)*pow(deltas[3],0)*pow(deltas[4],0);
  res.r += factor*lhs->e223;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],2)*pow(deltas[3],0)*pow(deltas[4],0);
  res.r += factor*lhs->e133;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],2)*pow(deltas[3],0)*pow(deltas[4],0);
  res.r += factor*lhs->e233;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],3)*pow(deltas[3],0)*pow(deltas[4],0);
  res.r += factor*lhs->e333;
  factor = pow(deltas[0],2)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],1)*pow(deltas[4],0);
  res.r += factor*lhs->e114;
  factor = pow(deltas[0],1)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],1)*pow(deltas[4],0);
  res.r += factor*lhs->e124;
  factor = pow(deltas[0],0)*pow(deltas[1],2)*pow(deltas[2],0)*pow(deltas[3],1)*pow(deltas[4],0);
  res.r += factor*lhs->e224;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],1)*pow(deltas[4],0);
  res.r += factor*lhs->e134;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],1)*pow(deltas[3],1)*pow(deltas[4],0);
  res.r += factor*lhs->e234;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],2)*pow(deltas[3],1)*pow(deltas[4],0);
  res.r += factor*lhs->e334;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],2)*pow(deltas[4],0);
  res.r += factor*lhs->e144;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],2)*pow(deltas[4],0);
  res.r += factor*lhs->e244;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],2)*pow(deltas[4],0);
  res.r += factor*lhs->e344;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],3)*pow(deltas[4],0);
  res.r += factor*lhs->e444;
  factor = pow(deltas[0],2)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],1);
  res.r += factor*lhs->e115;
  factor = pow(deltas[0],1)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],1);
  res.r += factor*lhs->e125;
  factor = pow(deltas[0],0)*pow(deltas[1],2)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],1);
  res.r += factor*lhs->e225;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],0)*pow(deltas[4],1);
  res.r += factor*lhs->e135;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],1)*pow(deltas[3],0)*pow(deltas[4],1);
  res.r += factor*lhs->e235;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],2)*pow(deltas[3],0)*pow(deltas[4],1);
  res.r += factor*lhs->e335;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],1)*pow(deltas[4],1);
  res.r += factor*lhs->e145;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],1)*pow(deltas[4],1);
  res.r += factor*lhs->e245;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],1)*pow(deltas[4],1);
  res.r += factor*lhs->e345;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],2)*pow(deltas[4],1);
  res.r += factor*lhs->e445;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],2);
  res.r += factor*lhs->e155;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],2);
  res.r += factor*lhs->e255;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],0)*pow(deltas[4],2);
  res.r += factor*lhs->e355;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],1)*pow(deltas[4],2);
  res.r += factor*lhs->e455;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],3);
  res.r += factor*lhs->e555;

  return res;

}

void onumm5n3_taylor_integrate_to(coeff_t* deltas,onumm5n3_t* lhs, onumm5n3_t* res){

  *res = onumm5n3_init();
  coeff_t factor;
  // Taylor integration
  // Real;
  res->r = lhs->r;
  // Order 1;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],0);
  res->r += factor*lhs->e1;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],0);
  res->r += factor*lhs->e2;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],0)*pow(deltas[4],0);
  res->r += factor*lhs->e3;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],1)*pow(deltas[4],0);
  res->r += factor*lhs->e4;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],1);
  res->r += factor*lhs->e5;
  // Order 2;
  factor = pow(deltas[0],2)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],0);
  res->r += factor*lhs->e11;
  factor = pow(deltas[0],1)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],0);
  res->r += factor*lhs->e12;
  factor = pow(deltas[0],0)*pow(deltas[1],2)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],0);
  res->r += factor*lhs->e22;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],0)*pow(deltas[4],0);
  res->r += factor*lhs->e13;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],1)*pow(deltas[3],0)*pow(deltas[4],0);
  res->r += factor*lhs->e23;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],2)*pow(deltas[3],0)*pow(deltas[4],0);
  res->r += factor*lhs->e33;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],1)*pow(deltas[4],0);
  res->r += factor*lhs->e14;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],1)*pow(deltas[4],0);
  res->r += factor*lhs->e24;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],1)*pow(deltas[4],0);
  res->r += factor*lhs->e34;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],2)*pow(deltas[4],0);
  res->r += factor*lhs->e44;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],1);
  res->r += factor*lhs->e15;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],1);
  res->r += factor*lhs->e25;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],0)*pow(deltas[4],1);
  res->r += factor*lhs->e35;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],1)*pow(deltas[4],1);
  res->r += factor*lhs->e45;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],2);
  res->r += factor*lhs->e55;
  // Order 3;
  factor = pow(deltas[0],3)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],0);
  res->r += factor*lhs->e111;
  factor = pow(deltas[0],2)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],0);
  res->r += factor*lhs->e112;
  factor = pow(deltas[0],1)*pow(deltas[1],2)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],0);
  res->r += factor*lhs->e122;
  factor = pow(deltas[0],0)*pow(deltas[1],3)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],0);
  res->r += factor*lhs->e222;
  factor = pow(deltas[0],2)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],0)*pow(deltas[4],0);
  res->r += factor*lhs->e113;
  factor = pow(deltas[0],1)*pow(deltas[1],1)*pow(deltas[2],1)*pow(deltas[3],0)*pow(deltas[4],0);
  res->r += factor*lhs->e123;
  factor = pow(deltas[0],0)*pow(deltas[1],2)*pow(deltas[2],1)*pow(deltas[3],0)*pow(deltas[4],0);
  res->r += factor*lhs->e223;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],2)*pow(deltas[3],0)*pow(deltas[4],0);
  res->r += factor*lhs->e133;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],2)*pow(deltas[3],0)*pow(deltas[4],0);
  res->r += factor*lhs->e233;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],3)*pow(deltas[3],0)*pow(deltas[4],0);
  res->r += factor*lhs->e333;
  factor = pow(deltas[0],2)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],1)*pow(deltas[4],0);
  res->r += factor*lhs->e114;
  factor = pow(deltas[0],1)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],1)*pow(deltas[4],0);
  res->r += factor*lhs->e124;
  factor = pow(deltas[0],0)*pow(deltas[1],2)*pow(deltas[2],0)*pow(deltas[3],1)*pow(deltas[4],0);
  res->r += factor*lhs->e224;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],1)*pow(deltas[4],0);
  res->r += factor*lhs->e134;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],1)*pow(deltas[3],1)*pow(deltas[4],0);
  res->r += factor*lhs->e234;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],2)*pow(deltas[3],1)*pow(deltas[4],0);
  res->r += factor*lhs->e334;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],2)*pow(deltas[4],0);
  res->r += factor*lhs->e144;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],2)*pow(deltas[4],0);
  res->r += factor*lhs->e244;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],2)*pow(deltas[4],0);
  res->r += factor*lhs->e344;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],3)*pow(deltas[4],0);
  res->r += factor*lhs->e444;
  factor = pow(deltas[0],2)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],1);
  res->r += factor*lhs->e115;
  factor = pow(deltas[0],1)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],1);
  res->r += factor*lhs->e125;
  factor = pow(deltas[0],0)*pow(deltas[1],2)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],1);
  res->r += factor*lhs->e225;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],0)*pow(deltas[4],1);
  res->r += factor*lhs->e135;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],1)*pow(deltas[3],0)*pow(deltas[4],1);
  res->r += factor*lhs->e235;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],2)*pow(deltas[3],0)*pow(deltas[4],1);
  res->r += factor*lhs->e335;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],1)*pow(deltas[4],1);
  res->r += factor*lhs->e145;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],1)*pow(deltas[4],1);
  res->r += factor*lhs->e245;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],1)*pow(deltas[4],1);
  res->r += factor*lhs->e345;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],2)*pow(deltas[4],1);
  res->r += factor*lhs->e445;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],2);
  res->r += factor*lhs->e155;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],2);
  res->r += factor*lhs->e255;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],0)*pow(deltas[4],2);
  res->r += factor*lhs->e355;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],1)*pow(deltas[4],2);
  res->r += factor*lhs->e455;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],3);
  res->r += factor*lhs->e555;

}

onumm5n3_t onumm5n3_truncate_im(imdir_t idx, ord_t order, onumm5n3_t* lhs){

  onumm5n3_t res;

  // Copy number.
  res = (*lhs);
  // Truncate all other values when necessary.
  // Real;
  switch (order){
    case 0:
      res = onumm5n3_init();
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
          res.e111 = 0.0;
          res.e112 = 0.0;
          res.e122 = 0.0;
          res.e113 = 0.0;
          res.e123 = 0.0;
          res.e133 = 0.0;
          res.e114 = 0.0;
          res.e124 = 0.0;
          res.e134 = 0.0;
          res.e144 = 0.0;
          res.e115 = 0.0;
          res.e125 = 0.0;
          res.e135 = 0.0;
          res.e145 = 0.0;
          res.e155 = 0.0;
          break;
        case 1: //  e2
          res.e2 = 0.0;
          res.e12 = 0.0;
          res.e22 = 0.0;
          res.e23 = 0.0;
          res.e24 = 0.0;
          res.e25 = 0.0;
          res.e112 = 0.0;
          res.e122 = 0.0;
          res.e222 = 0.0;
          res.e123 = 0.0;
          res.e223 = 0.0;
          res.e233 = 0.0;
          res.e124 = 0.0;
          res.e224 = 0.0;
          res.e234 = 0.0;
          res.e244 = 0.0;
          res.e125 = 0.0;
          res.e225 = 0.0;
          res.e235 = 0.0;
          res.e245 = 0.0;
          res.e255 = 0.0;
          break;
        case 2: //  e3
          res.e3 = 0.0;
          res.e13 = 0.0;
          res.e23 = 0.0;
          res.e33 = 0.0;
          res.e34 = 0.0;
          res.e35 = 0.0;
          res.e113 = 0.0;
          res.e123 = 0.0;
          res.e223 = 0.0;
          res.e133 = 0.0;
          res.e233 = 0.0;
          res.e333 = 0.0;
          res.e134 = 0.0;
          res.e234 = 0.0;
          res.e334 = 0.0;
          res.e344 = 0.0;
          res.e135 = 0.0;
          res.e235 = 0.0;
          res.e335 = 0.0;
          res.e345 = 0.0;
          res.e355 = 0.0;
          break;
        case 3: //  e4
          res.e4 = 0.0;
          res.e14 = 0.0;
          res.e24 = 0.0;
          res.e34 = 0.0;
          res.e44 = 0.0;
          res.e45 = 0.0;
          res.e114 = 0.0;
          res.e124 = 0.0;
          res.e224 = 0.0;
          res.e134 = 0.0;
          res.e234 = 0.0;
          res.e334 = 0.0;
          res.e144 = 0.0;
          res.e244 = 0.0;
          res.e344 = 0.0;
          res.e444 = 0.0;
          res.e145 = 0.0;
          res.e245 = 0.0;
          res.e345 = 0.0;
          res.e445 = 0.0;
          res.e455 = 0.0;
          break;
        case 4: //  e5
          res.e5 = 0.0;
          res.e15 = 0.0;
          res.e25 = 0.0;
          res.e35 = 0.0;
          res.e45 = 0.0;
          res.e55 = 0.0;
          res.e115 = 0.0;
          res.e125 = 0.0;
          res.e225 = 0.0;
          res.e135 = 0.0;
          res.e235 = 0.0;
          res.e335 = 0.0;
          res.e145 = 0.0;
          res.e245 = 0.0;
          res.e345 = 0.0;
          res.e445 = 0.0;
          res.e155 = 0.0;
          res.e255 = 0.0;
          res.e355 = 0.0;
          res.e455 = 0.0;
          res.e555 = 0.0;
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
          res.e114 = 0.0;
          res.e115 = 0.0;
          break;
        case 1: //  e12
          res.e12 = 0.0;
          res.e112 = 0.0;
          res.e122 = 0.0;
          res.e123 = 0.0;
          res.e124 = 0.0;
          res.e125 = 0.0;
          break;
        case 2: //  e22
          res.e22 = 0.0;
          res.e122 = 0.0;
          res.e222 = 0.0;
          res.e223 = 0.0;
          res.e224 = 0.0;
          res.e225 = 0.0;
          break;
        case 3: //  e13
          res.e13 = 0.0;
          res.e113 = 0.0;
          res.e123 = 0.0;
          res.e133 = 0.0;
          res.e134 = 0.0;
          res.e135 = 0.0;
          break;
        case 4: //  e23
          res.e23 = 0.0;
          res.e123 = 0.0;
          res.e223 = 0.0;
          res.e233 = 0.0;
          res.e234 = 0.0;
          res.e235 = 0.0;
          break;
        case 5: //  e33
          res.e33 = 0.0;
          res.e133 = 0.0;
          res.e233 = 0.0;
          res.e333 = 0.0;
          res.e334 = 0.0;
          res.e335 = 0.0;
          break;
        case 6: //  e14
          res.e14 = 0.0;
          res.e114 = 0.0;
          res.e124 = 0.0;
          res.e134 = 0.0;
          res.e144 = 0.0;
          res.e145 = 0.0;
          break;
        case 7: //  e24
          res.e24 = 0.0;
          res.e124 = 0.0;
          res.e224 = 0.0;
          res.e234 = 0.0;
          res.e244 = 0.0;
          res.e245 = 0.0;
          break;
        case 8: //  e34
          res.e34 = 0.0;
          res.e134 = 0.0;
          res.e234 = 0.0;
          res.e334 = 0.0;
          res.e344 = 0.0;
          res.e345 = 0.0;
          break;
        case 9: //  e44
          res.e44 = 0.0;
          res.e144 = 0.0;
          res.e244 = 0.0;
          res.e344 = 0.0;
          res.e444 = 0.0;
          res.e445 = 0.0;
          break;
        case 10: //  e15
          res.e15 = 0.0;
          res.e115 = 0.0;
          res.e125 = 0.0;
          res.e135 = 0.0;
          res.e145 = 0.0;
          res.e155 = 0.0;
          break;
        case 11: //  e25
          res.e25 = 0.0;
          res.e125 = 0.0;
          res.e225 = 0.0;
          res.e235 = 0.0;
          res.e245 = 0.0;
          res.e255 = 0.0;
          break;
        case 12: //  e35
          res.e35 = 0.0;
          res.e135 = 0.0;
          res.e235 = 0.0;
          res.e335 = 0.0;
          res.e345 = 0.0;
          res.e355 = 0.0;
          break;
        case 13: //  e45
          res.e45 = 0.0;
          res.e145 = 0.0;
          res.e245 = 0.0;
          res.e345 = 0.0;
          res.e445 = 0.0;
          res.e455 = 0.0;
          break;
        case 14: //  e55
          res.e55 = 0.0;
          res.e155 = 0.0;
          res.e255 = 0.0;
          res.e355 = 0.0;
          res.e455 = 0.0;
          res.e555 = 0.0;
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
        case 4: //  e113
          res.e113 = 0.0;
          break;
        case 5: //  e123
          res.e123 = 0.0;
          break;
        case 6: //  e223
          res.e223 = 0.0;
          break;
        case 7: //  e133
          res.e133 = 0.0;
          break;
        case 8: //  e233
          res.e233 = 0.0;
          break;
        case 9: //  e333
          res.e333 = 0.0;
          break;
        case 10: //  e114
          res.e114 = 0.0;
          break;
        case 11: //  e124
          res.e124 = 0.0;
          break;
        case 12: //  e224
          res.e224 = 0.0;
          break;
        case 13: //  e134
          res.e134 = 0.0;
          break;
        case 14: //  e234
          res.e234 = 0.0;
          break;
        case 15: //  e334
          res.e334 = 0.0;
          break;
        case 16: //  e144
          res.e144 = 0.0;
          break;
        case 17: //  e244
          res.e244 = 0.0;
          break;
        case 18: //  e344
          res.e344 = 0.0;
          break;
        case 19: //  e444
          res.e444 = 0.0;
          break;
        case 20: //  e115
          res.e115 = 0.0;
          break;
        case 21: //  e125
          res.e125 = 0.0;
          break;
        case 22: //  e225
          res.e225 = 0.0;
          break;
        case 23: //  e135
          res.e135 = 0.0;
          break;
        case 24: //  e235
          res.e235 = 0.0;
          break;
        case 25: //  e335
          res.e335 = 0.0;
          break;
        case 26: //  e145
          res.e145 = 0.0;
          break;
        case 27: //  e245
          res.e245 = 0.0;
          break;
        case 28: //  e345
          res.e345 = 0.0;
          break;
        case 29: //  e445
          res.e445 = 0.0;
          break;
        case 30: //  e155
          res.e155 = 0.0;
          break;
        case 31: //  e255
          res.e255 = 0.0;
          break;
        case 32: //  e355
          res.e355 = 0.0;
          break;
        case 33: //  e455
          res.e455 = 0.0;
          break;
        case 34: //  e555
          res.e555 = 0.0;
          break;
      }
      break;
  }
  return res;

}

void onumm5n3_truncate_im_to(imdir_t idx, ord_t order, onumm5n3_t* lhs, onumm5n3_t* res){

  // Copy number.
  *res = (*lhs);
  // Truncate all other values when necessary.
  // Real;
  switch (order){
    case 0:
      *res = onumm5n3_init();
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
          res->e111 = 0.0;
          res->e112 = 0.0;
          res->e122 = 0.0;
          res->e113 = 0.0;
          res->e123 = 0.0;
          res->e133 = 0.0;
          res->e114 = 0.0;
          res->e124 = 0.0;
          res->e134 = 0.0;
          res->e144 = 0.0;
          res->e115 = 0.0;
          res->e125 = 0.0;
          res->e135 = 0.0;
          res->e145 = 0.0;
          res->e155 = 0.0;
          break;
        case 1: //  e2
          res->e2 = 0.0;
          res->e12 = 0.0;
          res->e22 = 0.0;
          res->e23 = 0.0;
          res->e24 = 0.0;
          res->e25 = 0.0;
          res->e112 = 0.0;
          res->e122 = 0.0;
          res->e222 = 0.0;
          res->e123 = 0.0;
          res->e223 = 0.0;
          res->e233 = 0.0;
          res->e124 = 0.0;
          res->e224 = 0.0;
          res->e234 = 0.0;
          res->e244 = 0.0;
          res->e125 = 0.0;
          res->e225 = 0.0;
          res->e235 = 0.0;
          res->e245 = 0.0;
          res->e255 = 0.0;
          break;
        case 2: //  e3
          res->e3 = 0.0;
          res->e13 = 0.0;
          res->e23 = 0.0;
          res->e33 = 0.0;
          res->e34 = 0.0;
          res->e35 = 0.0;
          res->e113 = 0.0;
          res->e123 = 0.0;
          res->e223 = 0.0;
          res->e133 = 0.0;
          res->e233 = 0.0;
          res->e333 = 0.0;
          res->e134 = 0.0;
          res->e234 = 0.0;
          res->e334 = 0.0;
          res->e344 = 0.0;
          res->e135 = 0.0;
          res->e235 = 0.0;
          res->e335 = 0.0;
          res->e345 = 0.0;
          res->e355 = 0.0;
          break;
        case 3: //  e4
          res->e4 = 0.0;
          res->e14 = 0.0;
          res->e24 = 0.0;
          res->e34 = 0.0;
          res->e44 = 0.0;
          res->e45 = 0.0;
          res->e114 = 0.0;
          res->e124 = 0.0;
          res->e224 = 0.0;
          res->e134 = 0.0;
          res->e234 = 0.0;
          res->e334 = 0.0;
          res->e144 = 0.0;
          res->e244 = 0.0;
          res->e344 = 0.0;
          res->e444 = 0.0;
          res->e145 = 0.0;
          res->e245 = 0.0;
          res->e345 = 0.0;
          res->e445 = 0.0;
          res->e455 = 0.0;
          break;
        case 4: //  e5
          res->e5 = 0.0;
          res->e15 = 0.0;
          res->e25 = 0.0;
          res->e35 = 0.0;
          res->e45 = 0.0;
          res->e55 = 0.0;
          res->e115 = 0.0;
          res->e125 = 0.0;
          res->e225 = 0.0;
          res->e135 = 0.0;
          res->e235 = 0.0;
          res->e335 = 0.0;
          res->e145 = 0.0;
          res->e245 = 0.0;
          res->e345 = 0.0;
          res->e445 = 0.0;
          res->e155 = 0.0;
          res->e255 = 0.0;
          res->e355 = 0.0;
          res->e455 = 0.0;
          res->e555 = 0.0;
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
          res->e114 = 0.0;
          res->e115 = 0.0;
          break;
        case 1: //  e12
          res->e12 = 0.0;
          res->e112 = 0.0;
          res->e122 = 0.0;
          res->e123 = 0.0;
          res->e124 = 0.0;
          res->e125 = 0.0;
          break;
        case 2: //  e22
          res->e22 = 0.0;
          res->e122 = 0.0;
          res->e222 = 0.0;
          res->e223 = 0.0;
          res->e224 = 0.0;
          res->e225 = 0.0;
          break;
        case 3: //  e13
          res->e13 = 0.0;
          res->e113 = 0.0;
          res->e123 = 0.0;
          res->e133 = 0.0;
          res->e134 = 0.0;
          res->e135 = 0.0;
          break;
        case 4: //  e23
          res->e23 = 0.0;
          res->e123 = 0.0;
          res->e223 = 0.0;
          res->e233 = 0.0;
          res->e234 = 0.0;
          res->e235 = 0.0;
          break;
        case 5: //  e33
          res->e33 = 0.0;
          res->e133 = 0.0;
          res->e233 = 0.0;
          res->e333 = 0.0;
          res->e334 = 0.0;
          res->e335 = 0.0;
          break;
        case 6: //  e14
          res->e14 = 0.0;
          res->e114 = 0.0;
          res->e124 = 0.0;
          res->e134 = 0.0;
          res->e144 = 0.0;
          res->e145 = 0.0;
          break;
        case 7: //  e24
          res->e24 = 0.0;
          res->e124 = 0.0;
          res->e224 = 0.0;
          res->e234 = 0.0;
          res->e244 = 0.0;
          res->e245 = 0.0;
          break;
        case 8: //  e34
          res->e34 = 0.0;
          res->e134 = 0.0;
          res->e234 = 0.0;
          res->e334 = 0.0;
          res->e344 = 0.0;
          res->e345 = 0.0;
          break;
        case 9: //  e44
          res->e44 = 0.0;
          res->e144 = 0.0;
          res->e244 = 0.0;
          res->e344 = 0.0;
          res->e444 = 0.0;
          res->e445 = 0.0;
          break;
        case 10: //  e15
          res->e15 = 0.0;
          res->e115 = 0.0;
          res->e125 = 0.0;
          res->e135 = 0.0;
          res->e145 = 0.0;
          res->e155 = 0.0;
          break;
        case 11: //  e25
          res->e25 = 0.0;
          res->e125 = 0.0;
          res->e225 = 0.0;
          res->e235 = 0.0;
          res->e245 = 0.0;
          res->e255 = 0.0;
          break;
        case 12: //  e35
          res->e35 = 0.0;
          res->e135 = 0.0;
          res->e235 = 0.0;
          res->e335 = 0.0;
          res->e345 = 0.0;
          res->e355 = 0.0;
          break;
        case 13: //  e45
          res->e45 = 0.0;
          res->e145 = 0.0;
          res->e245 = 0.0;
          res->e345 = 0.0;
          res->e445 = 0.0;
          res->e455 = 0.0;
          break;
        case 14: //  e55
          res->e55 = 0.0;
          res->e155 = 0.0;
          res->e255 = 0.0;
          res->e355 = 0.0;
          res->e455 = 0.0;
          res->e555 = 0.0;
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
        case 4: //  e113
          res->e113 = 0.0;
          break;
        case 5: //  e123
          res->e123 = 0.0;
          break;
        case 6: //  e223
          res->e223 = 0.0;
          break;
        case 7: //  e133
          res->e133 = 0.0;
          break;
        case 8: //  e233
          res->e233 = 0.0;
          break;
        case 9: //  e333
          res->e333 = 0.0;
          break;
        case 10: //  e114
          res->e114 = 0.0;
          break;
        case 11: //  e124
          res->e124 = 0.0;
          break;
        case 12: //  e224
          res->e224 = 0.0;
          break;
        case 13: //  e134
          res->e134 = 0.0;
          break;
        case 14: //  e234
          res->e234 = 0.0;
          break;
        case 15: //  e334
          res->e334 = 0.0;
          break;
        case 16: //  e144
          res->e144 = 0.0;
          break;
        case 17: //  e244
          res->e244 = 0.0;
          break;
        case 18: //  e344
          res->e344 = 0.0;
          break;
        case 19: //  e444
          res->e444 = 0.0;
          break;
        case 20: //  e115
          res->e115 = 0.0;
          break;
        case 21: //  e125
          res->e125 = 0.0;
          break;
        case 22: //  e225
          res->e225 = 0.0;
          break;
        case 23: //  e135
          res->e135 = 0.0;
          break;
        case 24: //  e235
          res->e235 = 0.0;
          break;
        case 25: //  e335
          res->e335 = 0.0;
          break;
        case 26: //  e145
          res->e145 = 0.0;
          break;
        case 27: //  e245
          res->e245 = 0.0;
          break;
        case 28: //  e345
          res->e345 = 0.0;
          break;
        case 29: //  e445
          res->e445 = 0.0;
          break;
        case 30: //  e155
          res->e155 = 0.0;
          break;
        case 31: //  e255
          res->e255 = 0.0;
          break;
        case 32: //  e355
          res->e355 = 0.0;
          break;
        case 33: //  e455
          res->e455 = 0.0;
          break;
        case 34: //  e555
          res->e555 = 0.0;
          break;
      }
      break;
  }
}

void onumm5n3_print(  onumm5n3_t* lhs){

  // Print function.
  //  Real;
  printf("%.8g",lhs->r);
  //  Order 1;
  printf(" %+.8g*e1",lhs->e1);
  printf(" %+.8g*e2",lhs->e2);
  printf(" %+.8g*e3",lhs->e3);
  printf(" %+.8g*e4",lhs->e4);
  printf(" %+.8g*e5",lhs->e5);
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
  printf(" %+.8g*e114",lhs->e114);
  printf(" %+.8g*e124",lhs->e124);
  printf(" %+.8g*e224",lhs->e224);
  printf(" %+.8g*e134",lhs->e134);
  printf(" %+.8g*e234",lhs->e234);
  printf(" %+.8g*e334",lhs->e334);
  printf(" %+.8g*e144",lhs->e144);
  printf(" %+.8g*e244",lhs->e244);
  printf(" %+.8g*e344",lhs->e344);
  printf(" %+.8g*e444",lhs->e444);
  printf(" %+.8g*e115",lhs->e115);
  printf(" %+.8g*e125",lhs->e125);
  printf(" %+.8g*e225",lhs->e225);
  printf(" %+.8g*e135",lhs->e135);
  printf(" %+.8g*e235",lhs->e235);
  printf(" %+.8g*e335",lhs->e335);
  printf(" %+.8g*e145",lhs->e145);
  printf(" %+.8g*e245",lhs->e245);
  printf(" %+.8g*e345",lhs->e345);
  printf(" %+.8g*e445",lhs->e445);
  printf(" %+.8g*e155",lhs->e155);
  printf(" %+.8g*e255",lhs->e255);
  printf(" %+.8g*e355",lhs->e355);
  printf(" %+.8g*e455",lhs->e455);
  printf(" %+.8g*e555",lhs->e555);
  printf("\n");

}

imdir_t onumm5n3_get_indx(imdir_t idx, ord_t order){

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
      }
      break;
      default:
          return 0;
  }
  return 0;
}

