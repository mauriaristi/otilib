

// Not implemented correctly:
void mdnum6_set_im_o(mdnum6_t* num, imdir_t idx, ord_t order, mdnum6_t* res){
    mdnum6_set_item(num->r,idx,order,res);
}
void mdnum6_set_deriv_r(coeff_t num, imdir_t idx, ord_t order, mdnum6_t* res){
    *res=mdnum6_init();
}
void mdnum6_set_deriv_o(mdnum6_t* num, imdir_t idx, ord_t order, mdnum6_t* res){
    *res=mdnum6_init();
}
void mdnum6_extract_im_to( imdir_t idx, ord_t order, mdnum6_t* num, mdnum6_t* res){
    *res=mdnum6_init();
}
mdnum6_t mdnum6_extract_im(imdir_t idx, ord_t order, mdnum6_t* num){
    mdnum6_t res = mdnum6_init();
    return res;
}
mdnum6_t mdnum6_extract_deriv(imdir_t idx, ord_t order, mdnum6_t* num){
    mdnum6_t res = mdnum6_init();
    return res;
}
void mdnum6_extract_deriv_to(imdir_t idx, ord_t order, mdnum6_t* num, mdnum6_t* res){
	*res = mdnum6_init();
}
void mdnum6_get_im_to_o(imdir_t idx, ord_t order, mdnum6_t* num, mdnum6_t* res){
    coeff_t rres = mdnum6_get_item(idx, order, num);
    mdnum6_set_r(rres,res);
}
mdnum6_t mdnum6_get_im_o(imdir_t idx, ord_t order, mdnum6_t* num){
    coeff_t rres = mdnum6_get_item(idx, order, num);
    mdnum6_t res;
    mdnum6_set_r(rres,&res);
    return res;
}
void mdnum6_get_im_to_r(imdir_t idx, ord_t order, mdnum6_t* num, coeff_t* res){
    *res = mdnum6_get_item(idx, order, num);
}

inline ord_t mdnum6_get_order(mdnum6_t* lhs){

	return 6;

}

mdnum6_t mdnum6_get_deriv_o( imdir_t idx, ord_t order, mdnum6_t* num){

    mdnum6_t res = mdnum6_init();

    mdnum6_get_deriv_to( idx, order, num, &res);
    
    return res;

}

void mdnum6_get_deriv_to( imdir_t idx, ord_t order, mdnum6_t* num, mdnum6_t* res){

    coeff_t deriv = mdnum6_get_deriv(idx,order,num);

    mdnum6_set_r( deriv, res);

}

void mdnum6_set_im_r(coeff_t num, imdir_t idx, ord_t order, mdnum6_t* res){

    mdnum6_set_item(num, idx,order,res);

}

mdnum6_t mdnum6_init(void){

  mdnum6_t res;

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
  // Order 2;
  res.e12 = 0.0;
  res.e13 = 0.0;
  res.e23 = 0.0;
  res.e14 = 0.0;
  res.e24 = 0.0;
  res.e34 = 0.0;
  res.e15 = 0.0;
  res.e25 = 0.0;
  res.e35 = 0.0;
  res.e45 = 0.0;
  res.e16 = 0.0;
  res.e26 = 0.0;
  res.e36 = 0.0;
  res.e46 = 0.0;
  res.e56 = 0.0;
  // Order 3;
  res.e123 = 0.0;
  res.e124 = 0.0;
  res.e134 = 0.0;
  res.e234 = 0.0;
  res.e125 = 0.0;
  res.e135 = 0.0;
  res.e235 = 0.0;
  res.e145 = 0.0;
  res.e245 = 0.0;
  res.e345 = 0.0;
  res.e126 = 0.0;
  res.e136 = 0.0;
  res.e236 = 0.0;
  res.e146 = 0.0;
  res.e246 = 0.0;
  res.e346 = 0.0;
  res.e156 = 0.0;
  res.e256 = 0.0;
  res.e356 = 0.0;
  res.e456 = 0.0;
  // Order 4;
  res.e1234 = 0.0;
  res.e1235 = 0.0;
  res.e1245 = 0.0;
  res.e1345 = 0.0;
  res.e2345 = 0.0;
  res.e1236 = 0.0;
  res.e1246 = 0.0;
  res.e1346 = 0.0;
  res.e2346 = 0.0;
  res.e1256 = 0.0;
  res.e1356 = 0.0;
  res.e2356 = 0.0;
  res.e1456 = 0.0;
  res.e2456 = 0.0;
  res.e3456 = 0.0;
  // Order 5;
  res.e12345 = 0.0;
  res.e12346 = 0.0;
  res.e12356 = 0.0;
  res.e12456 = 0.0;
  res.e13456 = 0.0;
  res.e23456 = 0.0;
  // Order 6;
  res.e123456 = 0.0;

  return res;

}

ndir_t mdnum6_get_ndir_order(ord_t order, mdnum6_t* num){

  ndir_t res;

  switch(order){
    case 0:
      res = 1;
      break;
    case 1:
      res = 6;
      break;
    case 2:
      res = 15;
      break;
    case 3:
      res = 20;
      break;
    case 4:
      res = 15;
      break;
    case 5:
      res = 6;
      break;
    case 6:
      res = 1;
      break;
  }

  return res;

}

ndir_t mdnum6_get_ndir_total(mdnum6_t* num){

  ndir_t res;

  res = 63;

  return res;

}

coeff_t* mdnum6_get_order_address(ord_t order, mdnum6_t* num){

  coeff_t* res;

  switch(order){
    case 0:
      res = &num->r;
      break;
    case 1:
      res = &num->e1;
      break;
    case 2:
      res = &num->e12;
      break;
    case 3:
      res = &num->e123;
      break;
    case 4:
      res = &num->e1234;
      break;
    case 5:
      res = &num->e12345;
      break;
    case 6:
      res = &num->e123456;
      break;
  }
  return res;

}

mdnum6_t mdnum6_create_r(  coeff_t lhs){

  mdnum6_t res;

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
  // Order 2;
  res.e12 = 0.0;
  res.e13 = 0.0;
  res.e23 = 0.0;
  res.e14 = 0.0;
  res.e24 = 0.0;
  res.e34 = 0.0;
  res.e15 = 0.0;
  res.e25 = 0.0;
  res.e35 = 0.0;
  res.e45 = 0.0;
  res.e16 = 0.0;
  res.e26 = 0.0;
  res.e36 = 0.0;
  res.e46 = 0.0;
  res.e56 = 0.0;
  // Order 3;
  res.e123 = 0.0;
  res.e124 = 0.0;
  res.e134 = 0.0;
  res.e234 = 0.0;
  res.e125 = 0.0;
  res.e135 = 0.0;
  res.e235 = 0.0;
  res.e145 = 0.0;
  res.e245 = 0.0;
  res.e345 = 0.0;
  res.e126 = 0.0;
  res.e136 = 0.0;
  res.e236 = 0.0;
  res.e146 = 0.0;
  res.e246 = 0.0;
  res.e346 = 0.0;
  res.e156 = 0.0;
  res.e256 = 0.0;
  res.e356 = 0.0;
  res.e456 = 0.0;
  // Order 4;
  res.e1234 = 0.0;
  res.e1235 = 0.0;
  res.e1245 = 0.0;
  res.e1345 = 0.0;
  res.e2345 = 0.0;
  res.e1236 = 0.0;
  res.e1246 = 0.0;
  res.e1346 = 0.0;
  res.e2346 = 0.0;
  res.e1256 = 0.0;
  res.e1356 = 0.0;
  res.e2356 = 0.0;
  res.e1456 = 0.0;
  res.e2456 = 0.0;
  res.e3456 = 0.0;
  // Order 5;
  res.e12345 = 0.0;
  res.e12346 = 0.0;
  res.e12356 = 0.0;
  res.e12456 = 0.0;
  res.e13456 = 0.0;
  res.e23456 = 0.0;
  // Order 6;
  res.e123456 = 0.0;

  return res;

}

void mdnum6_set_r(  coeff_t lhs, mdnum6_t* res){

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
  // Order 2;
  res->e12 = 0.0;
  res->e13 = 0.0;
  res->e23 = 0.0;
  res->e14 = 0.0;
  res->e24 = 0.0;
  res->e34 = 0.0;
  res->e15 = 0.0;
  res->e25 = 0.0;
  res->e35 = 0.0;
  res->e45 = 0.0;
  res->e16 = 0.0;
  res->e26 = 0.0;
  res->e36 = 0.0;
  res->e46 = 0.0;
  res->e56 = 0.0;
  // Order 3;
  res->e123 = 0.0;
  res->e124 = 0.0;
  res->e134 = 0.0;
  res->e234 = 0.0;
  res->e125 = 0.0;
  res->e135 = 0.0;
  res->e235 = 0.0;
  res->e145 = 0.0;
  res->e245 = 0.0;
  res->e345 = 0.0;
  res->e126 = 0.0;
  res->e136 = 0.0;
  res->e236 = 0.0;
  res->e146 = 0.0;
  res->e246 = 0.0;
  res->e346 = 0.0;
  res->e156 = 0.0;
  res->e256 = 0.0;
  res->e356 = 0.0;
  res->e456 = 0.0;
  // Order 4;
  res->e1234 = 0.0;
  res->e1235 = 0.0;
  res->e1245 = 0.0;
  res->e1345 = 0.0;
  res->e2345 = 0.0;
  res->e1236 = 0.0;
  res->e1246 = 0.0;
  res->e1346 = 0.0;
  res->e2346 = 0.0;
  res->e1256 = 0.0;
  res->e1356 = 0.0;
  res->e2356 = 0.0;
  res->e1456 = 0.0;
  res->e2456 = 0.0;
  res->e3456 = 0.0;
  // Order 5;
  res->e12345 = 0.0;
  res->e12346 = 0.0;
  res->e12356 = 0.0;
  res->e12456 = 0.0;
  res->e13456 = 0.0;
  res->e23456 = 0.0;
  // Order 6;
  res->e123456 = 0.0;

}

void mdnum6_set_o(  mdnum6_t* lhs, mdnum6_t* res){

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
  // Order 2;
  res->e12 = lhs->e12;
  res->e13 = lhs->e13;
  res->e23 = lhs->e23;
  res->e14 = lhs->e14;
  res->e24 = lhs->e24;
  res->e34 = lhs->e34;
  res->e15 = lhs->e15;
  res->e25 = lhs->e25;
  res->e35 = lhs->e35;
  res->e45 = lhs->e45;
  res->e16 = lhs->e16;
  res->e26 = lhs->e26;
  res->e36 = lhs->e36;
  res->e46 = lhs->e46;
  res->e56 = lhs->e56;
  // Order 3;
  res->e123 = lhs->e123;
  res->e124 = lhs->e124;
  res->e134 = lhs->e134;
  res->e234 = lhs->e234;
  res->e125 = lhs->e125;
  res->e135 = lhs->e135;
  res->e235 = lhs->e235;
  res->e145 = lhs->e145;
  res->e245 = lhs->e245;
  res->e345 = lhs->e345;
  res->e126 = lhs->e126;
  res->e136 = lhs->e136;
  res->e236 = lhs->e236;
  res->e146 = lhs->e146;
  res->e246 = lhs->e246;
  res->e346 = lhs->e346;
  res->e156 = lhs->e156;
  res->e256 = lhs->e256;
  res->e356 = lhs->e356;
  res->e456 = lhs->e456;
  // Order 4;
  res->e1234 = lhs->e1234;
  res->e1235 = lhs->e1235;
  res->e1245 = lhs->e1245;
  res->e1345 = lhs->e1345;
  res->e2345 = lhs->e2345;
  res->e1236 = lhs->e1236;
  res->e1246 = lhs->e1246;
  res->e1346 = lhs->e1346;
  res->e2346 = lhs->e2346;
  res->e1256 = lhs->e1256;
  res->e1356 = lhs->e1356;
  res->e2356 = lhs->e2356;
  res->e1456 = lhs->e1456;
  res->e2456 = lhs->e2456;
  res->e3456 = lhs->e3456;
  // Order 5;
  res->e12345 = lhs->e12345;
  res->e12346 = lhs->e12346;
  res->e12356 = lhs->e12356;
  res->e12456 = lhs->e12456;
  res->e13456 = lhs->e13456;
  res->e23456 = lhs->e23456;
  // Order 6;
  res->e123456 = lhs->e123456;

}

mdnum6_t mdnum6_get_order_im(ord_t order, mdnum6_t* lhs){

  mdnum6_t res;

  res = mdnum6_init();
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
      break;
    case 2:
      // Order 2;
      res.e12 = lhs->e12;
      res.e13 = lhs->e13;
      res.e23 = lhs->e23;
      res.e14 = lhs->e14;
      res.e24 = lhs->e24;
      res.e34 = lhs->e34;
      res.e15 = lhs->e15;
      res.e25 = lhs->e25;
      res.e35 = lhs->e35;
      res.e45 = lhs->e45;
      res.e16 = lhs->e16;
      res.e26 = lhs->e26;
      res.e36 = lhs->e36;
      res.e46 = lhs->e46;
      res.e56 = lhs->e56;
      break;
    case 3:
      // Order 3;
      res.e123 = lhs->e123;
      res.e124 = lhs->e124;
      res.e134 = lhs->e134;
      res.e234 = lhs->e234;
      res.e125 = lhs->e125;
      res.e135 = lhs->e135;
      res.e235 = lhs->e235;
      res.e145 = lhs->e145;
      res.e245 = lhs->e245;
      res.e345 = lhs->e345;
      res.e126 = lhs->e126;
      res.e136 = lhs->e136;
      res.e236 = lhs->e236;
      res.e146 = lhs->e146;
      res.e246 = lhs->e246;
      res.e346 = lhs->e346;
      res.e156 = lhs->e156;
      res.e256 = lhs->e256;
      res.e356 = lhs->e356;
      res.e456 = lhs->e456;
      break;
    case 4:
      // Order 4;
      res.e1234 = lhs->e1234;
      res.e1235 = lhs->e1235;
      res.e1245 = lhs->e1245;
      res.e1345 = lhs->e1345;
      res.e2345 = lhs->e2345;
      res.e1236 = lhs->e1236;
      res.e1246 = lhs->e1246;
      res.e1346 = lhs->e1346;
      res.e2346 = lhs->e2346;
      res.e1256 = lhs->e1256;
      res.e1356 = lhs->e1356;
      res.e2356 = lhs->e2356;
      res.e1456 = lhs->e1456;
      res.e2456 = lhs->e2456;
      res.e3456 = lhs->e3456;
      break;
    case 5:
      // Order 5;
      res.e12345 = lhs->e12345;
      res.e12346 = lhs->e12346;
      res.e12356 = lhs->e12356;
      res.e12456 = lhs->e12456;
      res.e13456 = lhs->e13456;
      res.e23456 = lhs->e23456;
      break;
    case 6:
      // Order 6;
      res.e123456 = lhs->e123456;
      break;
  }

  return res;

}

void mdnum6_get_order_im_to(ord_t order, mdnum6_t* lhs, mdnum6_t* res){


  *res = mdnum6_init();
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
      break;
    case 2:
      // Order 2;
      res->e12 = lhs->e12;
      res->e13 = lhs->e13;
      res->e23 = lhs->e23;
      res->e14 = lhs->e14;
      res->e24 = lhs->e24;
      res->e34 = lhs->e34;
      res->e15 = lhs->e15;
      res->e25 = lhs->e25;
      res->e35 = lhs->e35;
      res->e45 = lhs->e45;
      res->e16 = lhs->e16;
      res->e26 = lhs->e26;
      res->e36 = lhs->e36;
      res->e46 = lhs->e46;
      res->e56 = lhs->e56;
      break;
    case 3:
      // Order 3;
      res->e123 = lhs->e123;
      res->e124 = lhs->e124;
      res->e134 = lhs->e134;
      res->e234 = lhs->e234;
      res->e125 = lhs->e125;
      res->e135 = lhs->e135;
      res->e235 = lhs->e235;
      res->e145 = lhs->e145;
      res->e245 = lhs->e245;
      res->e345 = lhs->e345;
      res->e126 = lhs->e126;
      res->e136 = lhs->e136;
      res->e236 = lhs->e236;
      res->e146 = lhs->e146;
      res->e246 = lhs->e246;
      res->e346 = lhs->e346;
      res->e156 = lhs->e156;
      res->e256 = lhs->e256;
      res->e356 = lhs->e356;
      res->e456 = lhs->e456;
      break;
    case 4:
      // Order 4;
      res->e1234 = lhs->e1234;
      res->e1235 = lhs->e1235;
      res->e1245 = lhs->e1245;
      res->e1345 = lhs->e1345;
      res->e2345 = lhs->e2345;
      res->e1236 = lhs->e1236;
      res->e1246 = lhs->e1246;
      res->e1346 = lhs->e1346;
      res->e2346 = lhs->e2346;
      res->e1256 = lhs->e1256;
      res->e1356 = lhs->e1356;
      res->e2356 = lhs->e2356;
      res->e1456 = lhs->e1456;
      res->e2456 = lhs->e2456;
      res->e3456 = lhs->e3456;
      break;
    case 5:
      // Order 5;
      res->e12345 = lhs->e12345;
      res->e12346 = lhs->e12346;
      res->e12356 = lhs->e12356;
      res->e12456 = lhs->e12456;
      res->e13456 = lhs->e13456;
      res->e23456 = lhs->e23456;
      break;
    case 6:
      // Order 6;
      res->e123456 = lhs->e123456;
      break;
  }

}

coeff_t mdnum6_get_item(imdir_t idx, ord_t order, mdnum6_t* lhs){

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
        case 6:
          res = lhs->e14;
          break;
        case 7:
          res = lhs->e24;
          break;
        case 8:
          res = lhs->e34;
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
      }
      break;
    case 3:
      switch (idx){
        case 5:
          res = lhs->e123;
          break;
        case 11:
          res = lhs->e124;
          break;
        case 13:
          res = lhs->e134;
          break;
        case 14:
          res = lhs->e234;
          break;
        case 21:
          res = lhs->e125;
          break;
        case 23:
          res = lhs->e135;
          break;
        case 24:
          res = lhs->e235;
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
        case 36:
          res = lhs->e126;
          break;
        case 38:
          res = lhs->e136;
          break;
        case 39:
          res = lhs->e236;
          break;
        case 41:
          res = lhs->e146;
          break;
        case 42:
          res = lhs->e246;
          break;
        case 43:
          res = lhs->e346;
          break;
        case 45:
          res = lhs->e156;
          break;
        case 46:
          res = lhs->e256;
          break;
        case 47:
          res = lhs->e356;
          break;
        case 48:
          res = lhs->e456;
          break;
      }
      break;
    case 4:
      switch (idx){
        case 20:
          res = lhs->e1234;
          break;
        case 40:
          res = lhs->e1235;
          break;
        case 46:
          res = lhs->e1245;
          break;
        case 48:
          res = lhs->e1345;
          break;
        case 49:
          res = lhs->e2345;
          break;
        case 75:
          res = lhs->e1236;
          break;
        case 81:
          res = lhs->e1246;
          break;
        case 83:
          res = lhs->e1346;
          break;
        case 84:
          res = lhs->e2346;
          break;
        case 91:
          res = lhs->e1256;
          break;
        case 93:
          res = lhs->e1356;
          break;
        case 94:
          res = lhs->e2356;
          break;
        case 96:
          res = lhs->e1456;
          break;
        case 97:
          res = lhs->e2456;
          break;
        case 98:
          res = lhs->e3456;
          break;
      }
      break;
    case 5:
      switch (idx){
        case 76:
          res = lhs->e12345;
          break;
        case 146:
          res = lhs->e12346;
          break;
        case 166:
          res = lhs->e12356;
          break;
        case 172:
          res = lhs->e12456;
          break;
        case 174:
          res = lhs->e13456;
          break;
        case 175:
          res = lhs->e23456;
          break;
      }
      break;
    case 6:
      switch (idx){
        case 286:
          res = lhs->e123456;
          break;
      }
      break;
  }
  return res;

}

coeff_t mdnum6_get_deriv(imdir_t idx, ord_t order, mdnum6_t* lhs){

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
      }
      break;
    case 3:
      switch (idx){
        case 5:
          factor = 1.0000000000000000e+00;
          res = lhs->e123*factor;
          break;
        case 11:
          factor = 1.0000000000000000e+00;
          res = lhs->e124*factor;
          break;
        case 13:
          factor = 1.0000000000000000e+00;
          res = lhs->e134*factor;
          break;
        case 14:
          factor = 1.0000000000000000e+00;
          res = lhs->e234*factor;
          break;
        case 21:
          factor = 1.0000000000000000e+00;
          res = lhs->e125*factor;
          break;
        case 23:
          factor = 1.0000000000000000e+00;
          res = lhs->e135*factor;
          break;
        case 24:
          factor = 1.0000000000000000e+00;
          res = lhs->e235*factor;
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
        case 36:
          factor = 1.0000000000000000e+00;
          res = lhs->e126*factor;
          break;
        case 38:
          factor = 1.0000000000000000e+00;
          res = lhs->e136*factor;
          break;
        case 39:
          factor = 1.0000000000000000e+00;
          res = lhs->e236*factor;
          break;
        case 41:
          factor = 1.0000000000000000e+00;
          res = lhs->e146*factor;
          break;
        case 42:
          factor = 1.0000000000000000e+00;
          res = lhs->e246*factor;
          break;
        case 43:
          factor = 1.0000000000000000e+00;
          res = lhs->e346*factor;
          break;
        case 45:
          factor = 1.0000000000000000e+00;
          res = lhs->e156*factor;
          break;
        case 46:
          factor = 1.0000000000000000e+00;
          res = lhs->e256*factor;
          break;
        case 47:
          factor = 1.0000000000000000e+00;
          res = lhs->e356*factor;
          break;
        case 48:
          factor = 1.0000000000000000e+00;
          res = lhs->e456*factor;
          break;
      }
      break;
    case 4:
      switch (idx){
        case 20:
          factor = 1.0000000000000000e+00;
          res = lhs->e1234*factor;
          break;
        case 40:
          factor = 1.0000000000000000e+00;
          res = lhs->e1235*factor;
          break;
        case 46:
          factor = 1.0000000000000000e+00;
          res = lhs->e1245*factor;
          break;
        case 48:
          factor = 1.0000000000000000e+00;
          res = lhs->e1345*factor;
          break;
        case 49:
          factor = 1.0000000000000000e+00;
          res = lhs->e2345*factor;
          break;
        case 75:
          factor = 1.0000000000000000e+00;
          res = lhs->e1236*factor;
          break;
        case 81:
          factor = 1.0000000000000000e+00;
          res = lhs->e1246*factor;
          break;
        case 83:
          factor = 1.0000000000000000e+00;
          res = lhs->e1346*factor;
          break;
        case 84:
          factor = 1.0000000000000000e+00;
          res = lhs->e2346*factor;
          break;
        case 91:
          factor = 1.0000000000000000e+00;
          res = lhs->e1256*factor;
          break;
        case 93:
          factor = 1.0000000000000000e+00;
          res = lhs->e1356*factor;
          break;
        case 94:
          factor = 1.0000000000000000e+00;
          res = lhs->e2356*factor;
          break;
        case 96:
          factor = 1.0000000000000000e+00;
          res = lhs->e1456*factor;
          break;
        case 97:
          factor = 1.0000000000000000e+00;
          res = lhs->e2456*factor;
          break;
        case 98:
          factor = 1.0000000000000000e+00;
          res = lhs->e3456*factor;
          break;
      }
      break;
    case 5:
      switch (idx){
        case 76:
          factor = 1.0000000000000000e+00;
          res = lhs->e12345*factor;
          break;
        case 146:
          factor = 1.0000000000000000e+00;
          res = lhs->e12346*factor;
          break;
        case 166:
          factor = 1.0000000000000000e+00;
          res = lhs->e12356*factor;
          break;
        case 172:
          factor = 1.0000000000000000e+00;
          res = lhs->e12456*factor;
          break;
        case 174:
          factor = 1.0000000000000000e+00;
          res = lhs->e13456*factor;
          break;
        case 175:
          factor = 1.0000000000000000e+00;
          res = lhs->e23456*factor;
          break;
      }
      break;
    case 6:
      switch (idx){
        case 286:
          factor = 1.0000000000000000e+00;
          res = lhs->e123456*factor;
          break;
      }
      break;
  }
  return res;

}

void mdnum6_set_item(coeff_t val, imdir_t idx, ord_t order, mdnum6_t* x){

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
        case 6:
          x->e14 = val;
          break;
        case 7:
          x->e24 = val;
          break;
        case 8:
          x->e34 = val;
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
      }
      break;
    case 3:
      switch (idx){
        case 5:
          x->e123 = val;
          break;
        case 11:
          x->e124 = val;
          break;
        case 13:
          x->e134 = val;
          break;
        case 14:
          x->e234 = val;
          break;
        case 21:
          x->e125 = val;
          break;
        case 23:
          x->e135 = val;
          break;
        case 24:
          x->e235 = val;
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
        case 36:
          x->e126 = val;
          break;
        case 38:
          x->e136 = val;
          break;
        case 39:
          x->e236 = val;
          break;
        case 41:
          x->e146 = val;
          break;
        case 42:
          x->e246 = val;
          break;
        case 43:
          x->e346 = val;
          break;
        case 45:
          x->e156 = val;
          break;
        case 46:
          x->e256 = val;
          break;
        case 47:
          x->e356 = val;
          break;
        case 48:
          x->e456 = val;
          break;
      }
      break;
    case 4:
      switch (idx){
        case 20:
          x->e1234 = val;
          break;
        case 40:
          x->e1235 = val;
          break;
        case 46:
          x->e1245 = val;
          break;
        case 48:
          x->e1345 = val;
          break;
        case 49:
          x->e2345 = val;
          break;
        case 75:
          x->e1236 = val;
          break;
        case 81:
          x->e1246 = val;
          break;
        case 83:
          x->e1346 = val;
          break;
        case 84:
          x->e2346 = val;
          break;
        case 91:
          x->e1256 = val;
          break;
        case 93:
          x->e1356 = val;
          break;
        case 94:
          x->e2356 = val;
          break;
        case 96:
          x->e1456 = val;
          break;
        case 97:
          x->e2456 = val;
          break;
        case 98:
          x->e3456 = val;
          break;
      }
      break;
    case 5:
      switch (idx){
        case 76:
          x->e12345 = val;
          break;
        case 146:
          x->e12346 = val;
          break;
        case 166:
          x->e12356 = val;
          break;
        case 172:
          x->e12456 = val;
          break;
        case 174:
          x->e13456 = val;
          break;
        case 175:
          x->e23456 = val;
          break;
      }
      break;
    case 6:
      switch (idx){
        case 286:
          x->e123456 = val;
          break;
      }
      break;
  }
}

mdnum6_t mdnum6_copy(  mdnum6_t* lhs){

  mdnum6_t res;

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
  // Order 2;
  res.e12 = lhs->e12;
  res.e13 = lhs->e13;
  res.e23 = lhs->e23;
  res.e14 = lhs->e14;
  res.e24 = lhs->e24;
  res.e34 = lhs->e34;
  res.e15 = lhs->e15;
  res.e25 = lhs->e25;
  res.e35 = lhs->e35;
  res.e45 = lhs->e45;
  res.e16 = lhs->e16;
  res.e26 = lhs->e26;
  res.e36 = lhs->e36;
  res.e46 = lhs->e46;
  res.e56 = lhs->e56;
  // Order 3;
  res.e123 = lhs->e123;
  res.e124 = lhs->e124;
  res.e134 = lhs->e134;
  res.e234 = lhs->e234;
  res.e125 = lhs->e125;
  res.e135 = lhs->e135;
  res.e235 = lhs->e235;
  res.e145 = lhs->e145;
  res.e245 = lhs->e245;
  res.e345 = lhs->e345;
  res.e126 = lhs->e126;
  res.e136 = lhs->e136;
  res.e236 = lhs->e236;
  res.e146 = lhs->e146;
  res.e246 = lhs->e246;
  res.e346 = lhs->e346;
  res.e156 = lhs->e156;
  res.e256 = lhs->e256;
  res.e356 = lhs->e356;
  res.e456 = lhs->e456;
  // Order 4;
  res.e1234 = lhs->e1234;
  res.e1235 = lhs->e1235;
  res.e1245 = lhs->e1245;
  res.e1345 = lhs->e1345;
  res.e2345 = lhs->e2345;
  res.e1236 = lhs->e1236;
  res.e1246 = lhs->e1246;
  res.e1346 = lhs->e1346;
  res.e2346 = lhs->e2346;
  res.e1256 = lhs->e1256;
  res.e1356 = lhs->e1356;
  res.e2356 = lhs->e2356;
  res.e1456 = lhs->e1456;
  res.e2456 = lhs->e2456;
  res.e3456 = lhs->e3456;
  // Order 5;
  res.e12345 = lhs->e12345;
  res.e12346 = lhs->e12346;
  res.e12356 = lhs->e12356;
  res.e12456 = lhs->e12456;
  res.e13456 = lhs->e13456;
  res.e23456 = lhs->e23456;
  // Order 6;
  res.e123456 = lhs->e123456;

  return res;

}

void mdnum6_copy_to(  mdnum6_t* lhs, mdnum6_t* res){

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
  // Order 2;
  res->e12 = lhs->e12;
  res->e13 = lhs->e13;
  res->e23 = lhs->e23;
  res->e14 = lhs->e14;
  res->e24 = lhs->e24;
  res->e34 = lhs->e34;
  res->e15 = lhs->e15;
  res->e25 = lhs->e25;
  res->e35 = lhs->e35;
  res->e45 = lhs->e45;
  res->e16 = lhs->e16;
  res->e26 = lhs->e26;
  res->e36 = lhs->e36;
  res->e46 = lhs->e46;
  res->e56 = lhs->e56;
  // Order 3;
  res->e123 = lhs->e123;
  res->e124 = lhs->e124;
  res->e134 = lhs->e134;
  res->e234 = lhs->e234;
  res->e125 = lhs->e125;
  res->e135 = lhs->e135;
  res->e235 = lhs->e235;
  res->e145 = lhs->e145;
  res->e245 = lhs->e245;
  res->e345 = lhs->e345;
  res->e126 = lhs->e126;
  res->e136 = lhs->e136;
  res->e236 = lhs->e236;
  res->e146 = lhs->e146;
  res->e246 = lhs->e246;
  res->e346 = lhs->e346;
  res->e156 = lhs->e156;
  res->e256 = lhs->e256;
  res->e356 = lhs->e356;
  res->e456 = lhs->e456;
  // Order 4;
  res->e1234 = lhs->e1234;
  res->e1235 = lhs->e1235;
  res->e1245 = lhs->e1245;
  res->e1345 = lhs->e1345;
  res->e2345 = lhs->e2345;
  res->e1236 = lhs->e1236;
  res->e1246 = lhs->e1246;
  res->e1346 = lhs->e1346;
  res->e2346 = lhs->e2346;
  res->e1256 = lhs->e1256;
  res->e1356 = lhs->e1356;
  res->e2356 = lhs->e2356;
  res->e1456 = lhs->e1456;
  res->e2456 = lhs->e2456;
  res->e3456 = lhs->e3456;
  // Order 5;
  res->e12345 = lhs->e12345;
  res->e12346 = lhs->e12346;
  res->e12356 = lhs->e12356;
  res->e12456 = lhs->e12456;
  res->e13456 = lhs->e13456;
  res->e23456 = lhs->e23456;
  // Order 6;
  res->e123456 = lhs->e123456;

}

mdnum6_t mdnum6_taylor_integrate(coeff_t* deltas,mdnum6_t* lhs){

  mdnum6_t res;

  res = mdnum6_init();
  coeff_t factor;
  // Taylor integration
  // Real;
  res.r = lhs->r;
  // Order 1;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],0)*pow(deltas[5],0);
  res.r += factor*lhs->e1;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],0)*pow(deltas[5],0);
  res.r += factor*lhs->e2;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],0)*pow(deltas[4],0)*pow(deltas[5],0);
  res.r += factor*lhs->e3;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],1)*pow(deltas[4],0)*pow(deltas[5],0);
  res.r += factor*lhs->e4;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],1)*pow(deltas[5],0);
  res.r += factor*lhs->e5;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],0)*pow(deltas[5],1);
  res.r += factor*lhs->e6;
  // Order 2;
  factor = pow(deltas[0],1)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],0)*pow(deltas[5],0);
  res.r += factor*lhs->e12;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],0)*pow(deltas[4],0)*pow(deltas[5],0);
  res.r += factor*lhs->e13;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],1)*pow(deltas[3],0)*pow(deltas[4],0)*pow(deltas[5],0);
  res.r += factor*lhs->e23;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],1)*pow(deltas[4],0)*pow(deltas[5],0);
  res.r += factor*lhs->e14;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],1)*pow(deltas[4],0)*pow(deltas[5],0);
  res.r += factor*lhs->e24;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],1)*pow(deltas[4],0)*pow(deltas[5],0);
  res.r += factor*lhs->e34;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],1)*pow(deltas[5],0);
  res.r += factor*lhs->e15;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],1)*pow(deltas[5],0);
  res.r += factor*lhs->e25;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],0)*pow(deltas[4],1)*pow(deltas[5],0);
  res.r += factor*lhs->e35;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],1)*pow(deltas[4],1)*pow(deltas[5],0);
  res.r += factor*lhs->e45;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],0)*pow(deltas[5],1);
  res.r += factor*lhs->e16;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],0)*pow(deltas[5],1);
  res.r += factor*lhs->e26;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],0)*pow(deltas[4],0)*pow(deltas[5],1);
  res.r += factor*lhs->e36;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],1)*pow(deltas[4],0)*pow(deltas[5],1);
  res.r += factor*lhs->e46;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],1)*pow(deltas[5],1);
  res.r += factor*lhs->e56;
  // Order 3;
  factor = pow(deltas[0],1)*pow(deltas[1],1)*pow(deltas[2],1)*pow(deltas[3],0)*pow(deltas[4],0)*pow(deltas[5],0);
  res.r += factor*lhs->e123;
  factor = pow(deltas[0],1)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],1)*pow(deltas[4],0)*pow(deltas[5],0);
  res.r += factor*lhs->e124;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],1)*pow(deltas[4],0)*pow(deltas[5],0);
  res.r += factor*lhs->e134;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],1)*pow(deltas[3],1)*pow(deltas[4],0)*pow(deltas[5],0);
  res.r += factor*lhs->e234;
  factor = pow(deltas[0],1)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],1)*pow(deltas[5],0);
  res.r += factor*lhs->e125;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],0)*pow(deltas[4],1)*pow(deltas[5],0);
  res.r += factor*lhs->e135;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],1)*pow(deltas[3],0)*pow(deltas[4],1)*pow(deltas[5],0);
  res.r += factor*lhs->e235;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],1)*pow(deltas[4],1)*pow(deltas[5],0);
  res.r += factor*lhs->e145;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],1)*pow(deltas[4],1)*pow(deltas[5],0);
  res.r += factor*lhs->e245;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],1)*pow(deltas[4],1)*pow(deltas[5],0);
  res.r += factor*lhs->e345;
  factor = pow(deltas[0],1)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],0)*pow(deltas[5],1);
  res.r += factor*lhs->e126;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],0)*pow(deltas[4],0)*pow(deltas[5],1);
  res.r += factor*lhs->e136;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],1)*pow(deltas[3],0)*pow(deltas[4],0)*pow(deltas[5],1);
  res.r += factor*lhs->e236;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],1)*pow(deltas[4],0)*pow(deltas[5],1);
  res.r += factor*lhs->e146;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],1)*pow(deltas[4],0)*pow(deltas[5],1);
  res.r += factor*lhs->e246;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],1)*pow(deltas[4],0)*pow(deltas[5],1);
  res.r += factor*lhs->e346;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],1)*pow(deltas[5],1);
  res.r += factor*lhs->e156;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],1)*pow(deltas[5],1);
  res.r += factor*lhs->e256;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],0)*pow(deltas[4],1)*pow(deltas[5],1);
  res.r += factor*lhs->e356;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],1)*pow(deltas[4],1)*pow(deltas[5],1);
  res.r += factor*lhs->e456;
  // Order 4;
  factor = pow(deltas[0],1)*pow(deltas[1],1)*pow(deltas[2],1)*pow(deltas[3],1)*pow(deltas[4],0)*pow(deltas[5],0);
  res.r += factor*lhs->e1234;
  factor = pow(deltas[0],1)*pow(deltas[1],1)*pow(deltas[2],1)*pow(deltas[3],0)*pow(deltas[4],1)*pow(deltas[5],0);
  res.r += factor*lhs->e1235;
  factor = pow(deltas[0],1)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],1)*pow(deltas[4],1)*pow(deltas[5],0);
  res.r += factor*lhs->e1245;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],1)*pow(deltas[4],1)*pow(deltas[5],0);
  res.r += factor*lhs->e1345;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],1)*pow(deltas[3],1)*pow(deltas[4],1)*pow(deltas[5],0);
  res.r += factor*lhs->e2345;
  factor = pow(deltas[0],1)*pow(deltas[1],1)*pow(deltas[2],1)*pow(deltas[3],0)*pow(deltas[4],0)*pow(deltas[5],1);
  res.r += factor*lhs->e1236;
  factor = pow(deltas[0],1)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],1)*pow(deltas[4],0)*pow(deltas[5],1);
  res.r += factor*lhs->e1246;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],1)*pow(deltas[4],0)*pow(deltas[5],1);
  res.r += factor*lhs->e1346;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],1)*pow(deltas[3],1)*pow(deltas[4],0)*pow(deltas[5],1);
  res.r += factor*lhs->e2346;
  factor = pow(deltas[0],1)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],1)*pow(deltas[5],1);
  res.r += factor*lhs->e1256;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],0)*pow(deltas[4],1)*pow(deltas[5],1);
  res.r += factor*lhs->e1356;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],1)*pow(deltas[3],0)*pow(deltas[4],1)*pow(deltas[5],1);
  res.r += factor*lhs->e2356;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],1)*pow(deltas[4],1)*pow(deltas[5],1);
  res.r += factor*lhs->e1456;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],1)*pow(deltas[4],1)*pow(deltas[5],1);
  res.r += factor*lhs->e2456;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],1)*pow(deltas[4],1)*pow(deltas[5],1);
  res.r += factor*lhs->e3456;
  // Order 5;
  factor = pow(deltas[0],1)*pow(deltas[1],1)*pow(deltas[2],1)*pow(deltas[3],1)*pow(deltas[4],1)*pow(deltas[5],0);
  res.r += factor*lhs->e12345;
  factor = pow(deltas[0],1)*pow(deltas[1],1)*pow(deltas[2],1)*pow(deltas[3],1)*pow(deltas[4],0)*pow(deltas[5],1);
  res.r += factor*lhs->e12346;
  factor = pow(deltas[0],1)*pow(deltas[1],1)*pow(deltas[2],1)*pow(deltas[3],0)*pow(deltas[4],1)*pow(deltas[5],1);
  res.r += factor*lhs->e12356;
  factor = pow(deltas[0],1)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],1)*pow(deltas[4],1)*pow(deltas[5],1);
  res.r += factor*lhs->e12456;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],1)*pow(deltas[4],1)*pow(deltas[5],1);
  res.r += factor*lhs->e13456;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],1)*pow(deltas[3],1)*pow(deltas[4],1)*pow(deltas[5],1);
  res.r += factor*lhs->e23456;
  // Order 6;
  factor = pow(deltas[0],1)*pow(deltas[1],1)*pow(deltas[2],1)*pow(deltas[3],1)*pow(deltas[4],1)*pow(deltas[5],1);
  res.r += factor*lhs->e123456;

  return res;

}

void mdnum6_taylor_integrate_to(coeff_t* deltas,mdnum6_t* lhs, mdnum6_t* res){

  *res = mdnum6_init();
  coeff_t factor;
  // Taylor integration
  // Real;
  res->r = lhs->r;
  // Order 1;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],0)*pow(deltas[5],0);
  res->r += factor*lhs->e1;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],0)*pow(deltas[5],0);
  res->r += factor*lhs->e2;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],0)*pow(deltas[4],0)*pow(deltas[5],0);
  res->r += factor*lhs->e3;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],1)*pow(deltas[4],0)*pow(deltas[5],0);
  res->r += factor*lhs->e4;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],1)*pow(deltas[5],0);
  res->r += factor*lhs->e5;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],0)*pow(deltas[5],1);
  res->r += factor*lhs->e6;
  // Order 2;
  factor = pow(deltas[0],1)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],0)*pow(deltas[5],0);
  res->r += factor*lhs->e12;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],0)*pow(deltas[4],0)*pow(deltas[5],0);
  res->r += factor*lhs->e13;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],1)*pow(deltas[3],0)*pow(deltas[4],0)*pow(deltas[5],0);
  res->r += factor*lhs->e23;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],1)*pow(deltas[4],0)*pow(deltas[5],0);
  res->r += factor*lhs->e14;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],1)*pow(deltas[4],0)*pow(deltas[5],0);
  res->r += factor*lhs->e24;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],1)*pow(deltas[4],0)*pow(deltas[5],0);
  res->r += factor*lhs->e34;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],1)*pow(deltas[5],0);
  res->r += factor*lhs->e15;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],1)*pow(deltas[5],0);
  res->r += factor*lhs->e25;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],0)*pow(deltas[4],1)*pow(deltas[5],0);
  res->r += factor*lhs->e35;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],1)*pow(deltas[4],1)*pow(deltas[5],0);
  res->r += factor*lhs->e45;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],0)*pow(deltas[5],1);
  res->r += factor*lhs->e16;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],0)*pow(deltas[5],1);
  res->r += factor*lhs->e26;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],0)*pow(deltas[4],0)*pow(deltas[5],1);
  res->r += factor*lhs->e36;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],1)*pow(deltas[4],0)*pow(deltas[5],1);
  res->r += factor*lhs->e46;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],1)*pow(deltas[5],1);
  res->r += factor*lhs->e56;
  // Order 3;
  factor = pow(deltas[0],1)*pow(deltas[1],1)*pow(deltas[2],1)*pow(deltas[3],0)*pow(deltas[4],0)*pow(deltas[5],0);
  res->r += factor*lhs->e123;
  factor = pow(deltas[0],1)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],1)*pow(deltas[4],0)*pow(deltas[5],0);
  res->r += factor*lhs->e124;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],1)*pow(deltas[4],0)*pow(deltas[5],0);
  res->r += factor*lhs->e134;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],1)*pow(deltas[3],1)*pow(deltas[4],0)*pow(deltas[5],0);
  res->r += factor*lhs->e234;
  factor = pow(deltas[0],1)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],1)*pow(deltas[5],0);
  res->r += factor*lhs->e125;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],0)*pow(deltas[4],1)*pow(deltas[5],0);
  res->r += factor*lhs->e135;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],1)*pow(deltas[3],0)*pow(deltas[4],1)*pow(deltas[5],0);
  res->r += factor*lhs->e235;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],1)*pow(deltas[4],1)*pow(deltas[5],0);
  res->r += factor*lhs->e145;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],1)*pow(deltas[4],1)*pow(deltas[5],0);
  res->r += factor*lhs->e245;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],1)*pow(deltas[4],1)*pow(deltas[5],0);
  res->r += factor*lhs->e345;
  factor = pow(deltas[0],1)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],0)*pow(deltas[5],1);
  res->r += factor*lhs->e126;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],0)*pow(deltas[4],0)*pow(deltas[5],1);
  res->r += factor*lhs->e136;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],1)*pow(deltas[3],0)*pow(deltas[4],0)*pow(deltas[5],1);
  res->r += factor*lhs->e236;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],1)*pow(deltas[4],0)*pow(deltas[5],1);
  res->r += factor*lhs->e146;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],1)*pow(deltas[4],0)*pow(deltas[5],1);
  res->r += factor*lhs->e246;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],1)*pow(deltas[4],0)*pow(deltas[5],1);
  res->r += factor*lhs->e346;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],1)*pow(deltas[5],1);
  res->r += factor*lhs->e156;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],1)*pow(deltas[5],1);
  res->r += factor*lhs->e256;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],0)*pow(deltas[4],1)*pow(deltas[5],1);
  res->r += factor*lhs->e356;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],1)*pow(deltas[4],1)*pow(deltas[5],1);
  res->r += factor*lhs->e456;
  // Order 4;
  factor = pow(deltas[0],1)*pow(deltas[1],1)*pow(deltas[2],1)*pow(deltas[3],1)*pow(deltas[4],0)*pow(deltas[5],0);
  res->r += factor*lhs->e1234;
  factor = pow(deltas[0],1)*pow(deltas[1],1)*pow(deltas[2],1)*pow(deltas[3],0)*pow(deltas[4],1)*pow(deltas[5],0);
  res->r += factor*lhs->e1235;
  factor = pow(deltas[0],1)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],1)*pow(deltas[4],1)*pow(deltas[5],0);
  res->r += factor*lhs->e1245;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],1)*pow(deltas[4],1)*pow(deltas[5],0);
  res->r += factor*lhs->e1345;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],1)*pow(deltas[3],1)*pow(deltas[4],1)*pow(deltas[5],0);
  res->r += factor*lhs->e2345;
  factor = pow(deltas[0],1)*pow(deltas[1],1)*pow(deltas[2],1)*pow(deltas[3],0)*pow(deltas[4],0)*pow(deltas[5],1);
  res->r += factor*lhs->e1236;
  factor = pow(deltas[0],1)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],1)*pow(deltas[4],0)*pow(deltas[5],1);
  res->r += factor*lhs->e1246;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],1)*pow(deltas[4],0)*pow(deltas[5],1);
  res->r += factor*lhs->e1346;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],1)*pow(deltas[3],1)*pow(deltas[4],0)*pow(deltas[5],1);
  res->r += factor*lhs->e2346;
  factor = pow(deltas[0],1)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],1)*pow(deltas[5],1);
  res->r += factor*lhs->e1256;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],0)*pow(deltas[4],1)*pow(deltas[5],1);
  res->r += factor*lhs->e1356;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],1)*pow(deltas[3],0)*pow(deltas[4],1)*pow(deltas[5],1);
  res->r += factor*lhs->e2356;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],1)*pow(deltas[4],1)*pow(deltas[5],1);
  res->r += factor*lhs->e1456;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],1)*pow(deltas[4],1)*pow(deltas[5],1);
  res->r += factor*lhs->e2456;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],1)*pow(deltas[4],1)*pow(deltas[5],1);
  res->r += factor*lhs->e3456;
  // Order 5;
  factor = pow(deltas[0],1)*pow(deltas[1],1)*pow(deltas[2],1)*pow(deltas[3],1)*pow(deltas[4],1)*pow(deltas[5],0);
  res->r += factor*lhs->e12345;
  factor = pow(deltas[0],1)*pow(deltas[1],1)*pow(deltas[2],1)*pow(deltas[3],1)*pow(deltas[4],0)*pow(deltas[5],1);
  res->r += factor*lhs->e12346;
  factor = pow(deltas[0],1)*pow(deltas[1],1)*pow(deltas[2],1)*pow(deltas[3],0)*pow(deltas[4],1)*pow(deltas[5],1);
  res->r += factor*lhs->e12356;
  factor = pow(deltas[0],1)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],1)*pow(deltas[4],1)*pow(deltas[5],1);
  res->r += factor*lhs->e12456;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],1)*pow(deltas[4],1)*pow(deltas[5],1);
  res->r += factor*lhs->e13456;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],1)*pow(deltas[3],1)*pow(deltas[4],1)*pow(deltas[5],1);
  res->r += factor*lhs->e23456;
  // Order 6;
  factor = pow(deltas[0],1)*pow(deltas[1],1)*pow(deltas[2],1)*pow(deltas[3],1)*pow(deltas[4],1)*pow(deltas[5],1);
  res->r += factor*lhs->e123456;

}

mdnum6_t mdnum6_truncate_im(imdir_t idx, ord_t order, mdnum6_t* lhs){

  mdnum6_t res;

  // Copy number.
  res = (*lhs);
  // Truncate all other values when necessary.
  // Real;
  switch (order){
    case 0:
      res = mdnum6_init();
      break;
    case 1:
      switch (idx){
        case 0: //  e1
          res.e1 = 0.0;
          res.e12 = 0.0;
          res.e13 = 0.0;
          res.e14 = 0.0;
          res.e15 = 0.0;
          res.e16 = 0.0;
          res.e123 = 0.0;
          res.e124 = 0.0;
          res.e134 = 0.0;
          res.e125 = 0.0;
          res.e135 = 0.0;
          res.e145 = 0.0;
          res.e126 = 0.0;
          res.e136 = 0.0;
          res.e146 = 0.0;
          res.e156 = 0.0;
          res.e1234 = 0.0;
          res.e1235 = 0.0;
          res.e1245 = 0.0;
          res.e1345 = 0.0;
          res.e1236 = 0.0;
          res.e1246 = 0.0;
          res.e1346 = 0.0;
          res.e1256 = 0.0;
          res.e1356 = 0.0;
          res.e1456 = 0.0;
          res.e12345 = 0.0;
          res.e12346 = 0.0;
          res.e12356 = 0.0;
          res.e12456 = 0.0;
          res.e13456 = 0.0;
          res.e123456 = 0.0;
          break;
        case 1: //  e2
          res.e2 = 0.0;
          res.e12 = 0.0;
          res.e23 = 0.0;
          res.e24 = 0.0;
          res.e25 = 0.0;
          res.e26 = 0.0;
          res.e123 = 0.0;
          res.e124 = 0.0;
          res.e234 = 0.0;
          res.e125 = 0.0;
          res.e235 = 0.0;
          res.e245 = 0.0;
          res.e126 = 0.0;
          res.e236 = 0.0;
          res.e246 = 0.0;
          res.e256 = 0.0;
          res.e1234 = 0.0;
          res.e1235 = 0.0;
          res.e1245 = 0.0;
          res.e2345 = 0.0;
          res.e1236 = 0.0;
          res.e1246 = 0.0;
          res.e2346 = 0.0;
          res.e1256 = 0.0;
          res.e2356 = 0.0;
          res.e2456 = 0.0;
          res.e12345 = 0.0;
          res.e12346 = 0.0;
          res.e12356 = 0.0;
          res.e12456 = 0.0;
          res.e23456 = 0.0;
          res.e123456 = 0.0;
          break;
        case 2: //  e3
          res.e3 = 0.0;
          res.e13 = 0.0;
          res.e23 = 0.0;
          res.e34 = 0.0;
          res.e35 = 0.0;
          res.e36 = 0.0;
          res.e123 = 0.0;
          res.e134 = 0.0;
          res.e234 = 0.0;
          res.e135 = 0.0;
          res.e235 = 0.0;
          res.e345 = 0.0;
          res.e136 = 0.0;
          res.e236 = 0.0;
          res.e346 = 0.0;
          res.e356 = 0.0;
          res.e1234 = 0.0;
          res.e1235 = 0.0;
          res.e1345 = 0.0;
          res.e2345 = 0.0;
          res.e1236 = 0.0;
          res.e1346 = 0.0;
          res.e2346 = 0.0;
          res.e1356 = 0.0;
          res.e2356 = 0.0;
          res.e3456 = 0.0;
          res.e12345 = 0.0;
          res.e12346 = 0.0;
          res.e12356 = 0.0;
          res.e13456 = 0.0;
          res.e23456 = 0.0;
          res.e123456 = 0.0;
          break;
        case 3: //  e4
          res.e4 = 0.0;
          res.e14 = 0.0;
          res.e24 = 0.0;
          res.e34 = 0.0;
          res.e45 = 0.0;
          res.e46 = 0.0;
          res.e124 = 0.0;
          res.e134 = 0.0;
          res.e234 = 0.0;
          res.e145 = 0.0;
          res.e245 = 0.0;
          res.e345 = 0.0;
          res.e146 = 0.0;
          res.e246 = 0.0;
          res.e346 = 0.0;
          res.e456 = 0.0;
          res.e1234 = 0.0;
          res.e1245 = 0.0;
          res.e1345 = 0.0;
          res.e2345 = 0.0;
          res.e1246 = 0.0;
          res.e1346 = 0.0;
          res.e2346 = 0.0;
          res.e1456 = 0.0;
          res.e2456 = 0.0;
          res.e3456 = 0.0;
          res.e12345 = 0.0;
          res.e12346 = 0.0;
          res.e12456 = 0.0;
          res.e13456 = 0.0;
          res.e23456 = 0.0;
          res.e123456 = 0.0;
          break;
        case 4: //  e5
          res.e5 = 0.0;
          res.e15 = 0.0;
          res.e25 = 0.0;
          res.e35 = 0.0;
          res.e45 = 0.0;
          res.e56 = 0.0;
          res.e125 = 0.0;
          res.e135 = 0.0;
          res.e235 = 0.0;
          res.e145 = 0.0;
          res.e245 = 0.0;
          res.e345 = 0.0;
          res.e156 = 0.0;
          res.e256 = 0.0;
          res.e356 = 0.0;
          res.e456 = 0.0;
          res.e1235 = 0.0;
          res.e1245 = 0.0;
          res.e1345 = 0.0;
          res.e2345 = 0.0;
          res.e1256 = 0.0;
          res.e1356 = 0.0;
          res.e2356 = 0.0;
          res.e1456 = 0.0;
          res.e2456 = 0.0;
          res.e3456 = 0.0;
          res.e12345 = 0.0;
          res.e12356 = 0.0;
          res.e12456 = 0.0;
          res.e13456 = 0.0;
          res.e23456 = 0.0;
          res.e123456 = 0.0;
          break;
        case 5: //  e6
          res.e6 = 0.0;
          res.e16 = 0.0;
          res.e26 = 0.0;
          res.e36 = 0.0;
          res.e46 = 0.0;
          res.e56 = 0.0;
          res.e126 = 0.0;
          res.e136 = 0.0;
          res.e236 = 0.0;
          res.e146 = 0.0;
          res.e246 = 0.0;
          res.e346 = 0.0;
          res.e156 = 0.0;
          res.e256 = 0.0;
          res.e356 = 0.0;
          res.e456 = 0.0;
          res.e1236 = 0.0;
          res.e1246 = 0.0;
          res.e1346 = 0.0;
          res.e2346 = 0.0;
          res.e1256 = 0.0;
          res.e1356 = 0.0;
          res.e2356 = 0.0;
          res.e1456 = 0.0;
          res.e2456 = 0.0;
          res.e3456 = 0.0;
          res.e12346 = 0.0;
          res.e12356 = 0.0;
          res.e12456 = 0.0;
          res.e13456 = 0.0;
          res.e23456 = 0.0;
          res.e123456 = 0.0;
          break;
      }
      break;
    case 2:
      switch (idx){
        case 1: //  e12
          res.e12 = 0.0;
          res.e123 = 0.0;
          res.e124 = 0.0;
          res.e125 = 0.0;
          res.e126 = 0.0;
          res.e1234 = 0.0;
          res.e1235 = 0.0;
          res.e1245 = 0.0;
          res.e1236 = 0.0;
          res.e1246 = 0.0;
          res.e1256 = 0.0;
          res.e12345 = 0.0;
          res.e12346 = 0.0;
          res.e12356 = 0.0;
          res.e12456 = 0.0;
          res.e123456 = 0.0;
          break;
        case 3: //  e13
          res.e13 = 0.0;
          res.e123 = 0.0;
          res.e134 = 0.0;
          res.e135 = 0.0;
          res.e136 = 0.0;
          res.e1234 = 0.0;
          res.e1235 = 0.0;
          res.e1345 = 0.0;
          res.e1236 = 0.0;
          res.e1346 = 0.0;
          res.e1356 = 0.0;
          res.e12345 = 0.0;
          res.e12346 = 0.0;
          res.e12356 = 0.0;
          res.e13456 = 0.0;
          res.e123456 = 0.0;
          break;
        case 4: //  e23
          res.e23 = 0.0;
          res.e123 = 0.0;
          res.e234 = 0.0;
          res.e235 = 0.0;
          res.e236 = 0.0;
          res.e1234 = 0.0;
          res.e1235 = 0.0;
          res.e2345 = 0.0;
          res.e1236 = 0.0;
          res.e2346 = 0.0;
          res.e2356 = 0.0;
          res.e12345 = 0.0;
          res.e12346 = 0.0;
          res.e12356 = 0.0;
          res.e23456 = 0.0;
          res.e123456 = 0.0;
          break;
        case 6: //  e14
          res.e14 = 0.0;
          res.e124 = 0.0;
          res.e134 = 0.0;
          res.e145 = 0.0;
          res.e146 = 0.0;
          res.e1234 = 0.0;
          res.e1245 = 0.0;
          res.e1345 = 0.0;
          res.e1246 = 0.0;
          res.e1346 = 0.0;
          res.e1456 = 0.0;
          res.e12345 = 0.0;
          res.e12346 = 0.0;
          res.e12456 = 0.0;
          res.e13456 = 0.0;
          res.e123456 = 0.0;
          break;
        case 7: //  e24
          res.e24 = 0.0;
          res.e124 = 0.0;
          res.e234 = 0.0;
          res.e245 = 0.0;
          res.e246 = 0.0;
          res.e1234 = 0.0;
          res.e1245 = 0.0;
          res.e2345 = 0.0;
          res.e1246 = 0.0;
          res.e2346 = 0.0;
          res.e2456 = 0.0;
          res.e12345 = 0.0;
          res.e12346 = 0.0;
          res.e12456 = 0.0;
          res.e23456 = 0.0;
          res.e123456 = 0.0;
          break;
        case 8: //  e34
          res.e34 = 0.0;
          res.e134 = 0.0;
          res.e234 = 0.0;
          res.e345 = 0.0;
          res.e346 = 0.0;
          res.e1234 = 0.0;
          res.e1345 = 0.0;
          res.e2345 = 0.0;
          res.e1346 = 0.0;
          res.e2346 = 0.0;
          res.e3456 = 0.0;
          res.e12345 = 0.0;
          res.e12346 = 0.0;
          res.e13456 = 0.0;
          res.e23456 = 0.0;
          res.e123456 = 0.0;
          break;
        case 10: //  e15
          res.e15 = 0.0;
          res.e125 = 0.0;
          res.e135 = 0.0;
          res.e145 = 0.0;
          res.e156 = 0.0;
          res.e1235 = 0.0;
          res.e1245 = 0.0;
          res.e1345 = 0.0;
          res.e1256 = 0.0;
          res.e1356 = 0.0;
          res.e1456 = 0.0;
          res.e12345 = 0.0;
          res.e12356 = 0.0;
          res.e12456 = 0.0;
          res.e13456 = 0.0;
          res.e123456 = 0.0;
          break;
        case 11: //  e25
          res.e25 = 0.0;
          res.e125 = 0.0;
          res.e235 = 0.0;
          res.e245 = 0.0;
          res.e256 = 0.0;
          res.e1235 = 0.0;
          res.e1245 = 0.0;
          res.e2345 = 0.0;
          res.e1256 = 0.0;
          res.e2356 = 0.0;
          res.e2456 = 0.0;
          res.e12345 = 0.0;
          res.e12356 = 0.0;
          res.e12456 = 0.0;
          res.e23456 = 0.0;
          res.e123456 = 0.0;
          break;
        case 12: //  e35
          res.e35 = 0.0;
          res.e135 = 0.0;
          res.e235 = 0.0;
          res.e345 = 0.0;
          res.e356 = 0.0;
          res.e1235 = 0.0;
          res.e1345 = 0.0;
          res.e2345 = 0.0;
          res.e1356 = 0.0;
          res.e2356 = 0.0;
          res.e3456 = 0.0;
          res.e12345 = 0.0;
          res.e12356 = 0.0;
          res.e13456 = 0.0;
          res.e23456 = 0.0;
          res.e123456 = 0.0;
          break;
        case 13: //  e45
          res.e45 = 0.0;
          res.e145 = 0.0;
          res.e245 = 0.0;
          res.e345 = 0.0;
          res.e456 = 0.0;
          res.e1245 = 0.0;
          res.e1345 = 0.0;
          res.e2345 = 0.0;
          res.e1456 = 0.0;
          res.e2456 = 0.0;
          res.e3456 = 0.0;
          res.e12345 = 0.0;
          res.e12456 = 0.0;
          res.e13456 = 0.0;
          res.e23456 = 0.0;
          res.e123456 = 0.0;
          break;
        case 15: //  e16
          res.e16 = 0.0;
          res.e126 = 0.0;
          res.e136 = 0.0;
          res.e146 = 0.0;
          res.e156 = 0.0;
          res.e1236 = 0.0;
          res.e1246 = 0.0;
          res.e1346 = 0.0;
          res.e1256 = 0.0;
          res.e1356 = 0.0;
          res.e1456 = 0.0;
          res.e12346 = 0.0;
          res.e12356 = 0.0;
          res.e12456 = 0.0;
          res.e13456 = 0.0;
          res.e123456 = 0.0;
          break;
        case 16: //  e26
          res.e26 = 0.0;
          res.e126 = 0.0;
          res.e236 = 0.0;
          res.e246 = 0.0;
          res.e256 = 0.0;
          res.e1236 = 0.0;
          res.e1246 = 0.0;
          res.e2346 = 0.0;
          res.e1256 = 0.0;
          res.e2356 = 0.0;
          res.e2456 = 0.0;
          res.e12346 = 0.0;
          res.e12356 = 0.0;
          res.e12456 = 0.0;
          res.e23456 = 0.0;
          res.e123456 = 0.0;
          break;
        case 17: //  e36
          res.e36 = 0.0;
          res.e136 = 0.0;
          res.e236 = 0.0;
          res.e346 = 0.0;
          res.e356 = 0.0;
          res.e1236 = 0.0;
          res.e1346 = 0.0;
          res.e2346 = 0.0;
          res.e1356 = 0.0;
          res.e2356 = 0.0;
          res.e3456 = 0.0;
          res.e12346 = 0.0;
          res.e12356 = 0.0;
          res.e13456 = 0.0;
          res.e23456 = 0.0;
          res.e123456 = 0.0;
          break;
        case 18: //  e46
          res.e46 = 0.0;
          res.e146 = 0.0;
          res.e246 = 0.0;
          res.e346 = 0.0;
          res.e456 = 0.0;
          res.e1246 = 0.0;
          res.e1346 = 0.0;
          res.e2346 = 0.0;
          res.e1456 = 0.0;
          res.e2456 = 0.0;
          res.e3456 = 0.0;
          res.e12346 = 0.0;
          res.e12456 = 0.0;
          res.e13456 = 0.0;
          res.e23456 = 0.0;
          res.e123456 = 0.0;
          break;
        case 19: //  e56
          res.e56 = 0.0;
          res.e156 = 0.0;
          res.e256 = 0.0;
          res.e356 = 0.0;
          res.e456 = 0.0;
          res.e1256 = 0.0;
          res.e1356 = 0.0;
          res.e2356 = 0.0;
          res.e1456 = 0.0;
          res.e2456 = 0.0;
          res.e3456 = 0.0;
          res.e12356 = 0.0;
          res.e12456 = 0.0;
          res.e13456 = 0.0;
          res.e23456 = 0.0;
          res.e123456 = 0.0;
          break;
      }
      break;
    case 3:
      switch (idx){
        case 5: //  e123
          res.e123 = 0.0;
          res.e1234 = 0.0;
          res.e1235 = 0.0;
          res.e1236 = 0.0;
          res.e12345 = 0.0;
          res.e12346 = 0.0;
          res.e12356 = 0.0;
          res.e123456 = 0.0;
          break;
        case 11: //  e124
          res.e124 = 0.0;
          res.e1234 = 0.0;
          res.e1245 = 0.0;
          res.e1246 = 0.0;
          res.e12345 = 0.0;
          res.e12346 = 0.0;
          res.e12456 = 0.0;
          res.e123456 = 0.0;
          break;
        case 13: //  e134
          res.e134 = 0.0;
          res.e1234 = 0.0;
          res.e1345 = 0.0;
          res.e1346 = 0.0;
          res.e12345 = 0.0;
          res.e12346 = 0.0;
          res.e13456 = 0.0;
          res.e123456 = 0.0;
          break;
        case 14: //  e234
          res.e234 = 0.0;
          res.e1234 = 0.0;
          res.e2345 = 0.0;
          res.e2346 = 0.0;
          res.e12345 = 0.0;
          res.e12346 = 0.0;
          res.e23456 = 0.0;
          res.e123456 = 0.0;
          break;
        case 21: //  e125
          res.e125 = 0.0;
          res.e1235 = 0.0;
          res.e1245 = 0.0;
          res.e1256 = 0.0;
          res.e12345 = 0.0;
          res.e12356 = 0.0;
          res.e12456 = 0.0;
          res.e123456 = 0.0;
          break;
        case 23: //  e135
          res.e135 = 0.0;
          res.e1235 = 0.0;
          res.e1345 = 0.0;
          res.e1356 = 0.0;
          res.e12345 = 0.0;
          res.e12356 = 0.0;
          res.e13456 = 0.0;
          res.e123456 = 0.0;
          break;
        case 24: //  e235
          res.e235 = 0.0;
          res.e1235 = 0.0;
          res.e2345 = 0.0;
          res.e2356 = 0.0;
          res.e12345 = 0.0;
          res.e12356 = 0.0;
          res.e23456 = 0.0;
          res.e123456 = 0.0;
          break;
        case 26: //  e145
          res.e145 = 0.0;
          res.e1245 = 0.0;
          res.e1345 = 0.0;
          res.e1456 = 0.0;
          res.e12345 = 0.0;
          res.e12456 = 0.0;
          res.e13456 = 0.0;
          res.e123456 = 0.0;
          break;
        case 27: //  e245
          res.e245 = 0.0;
          res.e1245 = 0.0;
          res.e2345 = 0.0;
          res.e2456 = 0.0;
          res.e12345 = 0.0;
          res.e12456 = 0.0;
          res.e23456 = 0.0;
          res.e123456 = 0.0;
          break;
        case 28: //  e345
          res.e345 = 0.0;
          res.e1345 = 0.0;
          res.e2345 = 0.0;
          res.e3456 = 0.0;
          res.e12345 = 0.0;
          res.e13456 = 0.0;
          res.e23456 = 0.0;
          res.e123456 = 0.0;
          break;
        case 36: //  e126
          res.e126 = 0.0;
          res.e1236 = 0.0;
          res.e1246 = 0.0;
          res.e1256 = 0.0;
          res.e12346 = 0.0;
          res.e12356 = 0.0;
          res.e12456 = 0.0;
          res.e123456 = 0.0;
          break;
        case 38: //  e136
          res.e136 = 0.0;
          res.e1236 = 0.0;
          res.e1346 = 0.0;
          res.e1356 = 0.0;
          res.e12346 = 0.0;
          res.e12356 = 0.0;
          res.e13456 = 0.0;
          res.e123456 = 0.0;
          break;
        case 39: //  e236
          res.e236 = 0.0;
          res.e1236 = 0.0;
          res.e2346 = 0.0;
          res.e2356 = 0.0;
          res.e12346 = 0.0;
          res.e12356 = 0.0;
          res.e23456 = 0.0;
          res.e123456 = 0.0;
          break;
        case 41: //  e146
          res.e146 = 0.0;
          res.e1246 = 0.0;
          res.e1346 = 0.0;
          res.e1456 = 0.0;
          res.e12346 = 0.0;
          res.e12456 = 0.0;
          res.e13456 = 0.0;
          res.e123456 = 0.0;
          break;
        case 42: //  e246
          res.e246 = 0.0;
          res.e1246 = 0.0;
          res.e2346 = 0.0;
          res.e2456 = 0.0;
          res.e12346 = 0.0;
          res.e12456 = 0.0;
          res.e23456 = 0.0;
          res.e123456 = 0.0;
          break;
        case 43: //  e346
          res.e346 = 0.0;
          res.e1346 = 0.0;
          res.e2346 = 0.0;
          res.e3456 = 0.0;
          res.e12346 = 0.0;
          res.e13456 = 0.0;
          res.e23456 = 0.0;
          res.e123456 = 0.0;
          break;
        case 45: //  e156
          res.e156 = 0.0;
          res.e1256 = 0.0;
          res.e1356 = 0.0;
          res.e1456 = 0.0;
          res.e12356 = 0.0;
          res.e12456 = 0.0;
          res.e13456 = 0.0;
          res.e123456 = 0.0;
          break;
        case 46: //  e256
          res.e256 = 0.0;
          res.e1256 = 0.0;
          res.e2356 = 0.0;
          res.e2456 = 0.0;
          res.e12356 = 0.0;
          res.e12456 = 0.0;
          res.e23456 = 0.0;
          res.e123456 = 0.0;
          break;
        case 47: //  e356
          res.e356 = 0.0;
          res.e1356 = 0.0;
          res.e2356 = 0.0;
          res.e3456 = 0.0;
          res.e12356 = 0.0;
          res.e13456 = 0.0;
          res.e23456 = 0.0;
          res.e123456 = 0.0;
          break;
        case 48: //  e456
          res.e456 = 0.0;
          res.e1456 = 0.0;
          res.e2456 = 0.0;
          res.e3456 = 0.0;
          res.e12456 = 0.0;
          res.e13456 = 0.0;
          res.e23456 = 0.0;
          res.e123456 = 0.0;
          break;
      }
      break;
    case 4:
      switch (idx){
        case 20: //  e1234
          res.e1234 = 0.0;
          res.e12345 = 0.0;
          res.e12346 = 0.0;
          res.e123456 = 0.0;
          break;
        case 40: //  e1235
          res.e1235 = 0.0;
          res.e12345 = 0.0;
          res.e12356 = 0.0;
          res.e123456 = 0.0;
          break;
        case 46: //  e1245
          res.e1245 = 0.0;
          res.e12345 = 0.0;
          res.e12456 = 0.0;
          res.e123456 = 0.0;
          break;
        case 48: //  e1345
          res.e1345 = 0.0;
          res.e12345 = 0.0;
          res.e13456 = 0.0;
          res.e123456 = 0.0;
          break;
        case 49: //  e2345
          res.e2345 = 0.0;
          res.e12345 = 0.0;
          res.e23456 = 0.0;
          res.e123456 = 0.0;
          break;
        case 75: //  e1236
          res.e1236 = 0.0;
          res.e12346 = 0.0;
          res.e12356 = 0.0;
          res.e123456 = 0.0;
          break;
        case 81: //  e1246
          res.e1246 = 0.0;
          res.e12346 = 0.0;
          res.e12456 = 0.0;
          res.e123456 = 0.0;
          break;
        case 83: //  e1346
          res.e1346 = 0.0;
          res.e12346 = 0.0;
          res.e13456 = 0.0;
          res.e123456 = 0.0;
          break;
        case 84: //  e2346
          res.e2346 = 0.0;
          res.e12346 = 0.0;
          res.e23456 = 0.0;
          res.e123456 = 0.0;
          break;
        case 91: //  e1256
          res.e1256 = 0.0;
          res.e12356 = 0.0;
          res.e12456 = 0.0;
          res.e123456 = 0.0;
          break;
        case 93: //  e1356
          res.e1356 = 0.0;
          res.e12356 = 0.0;
          res.e13456 = 0.0;
          res.e123456 = 0.0;
          break;
        case 94: //  e2356
          res.e2356 = 0.0;
          res.e12356 = 0.0;
          res.e23456 = 0.0;
          res.e123456 = 0.0;
          break;
        case 96: //  e1456
          res.e1456 = 0.0;
          res.e12456 = 0.0;
          res.e13456 = 0.0;
          res.e123456 = 0.0;
          break;
        case 97: //  e2456
          res.e2456 = 0.0;
          res.e12456 = 0.0;
          res.e23456 = 0.0;
          res.e123456 = 0.0;
          break;
        case 98: //  e3456
          res.e3456 = 0.0;
          res.e13456 = 0.0;
          res.e23456 = 0.0;
          res.e123456 = 0.0;
          break;
      }
      break;
    case 5:
      switch (idx){
        case 76: //  e12345
          res.e12345 = 0.0;
          res.e123456 = 0.0;
          break;
        case 146: //  e12346
          res.e12346 = 0.0;
          res.e123456 = 0.0;
          break;
        case 166: //  e12356
          res.e12356 = 0.0;
          res.e123456 = 0.0;
          break;
        case 172: //  e12456
          res.e12456 = 0.0;
          res.e123456 = 0.0;
          break;
        case 174: //  e13456
          res.e13456 = 0.0;
          res.e123456 = 0.0;
          break;
        case 175: //  e23456
          res.e23456 = 0.0;
          res.e123456 = 0.0;
          break;
      }
      break;
    case 6:
      switch (idx){
        case 286: //  e123456
          res.e123456 = 0.0;
          break;
      }
      break;
  }
  return res;

}

void mdnum6_truncate_im_to(imdir_t idx, ord_t order, mdnum6_t* lhs, mdnum6_t* res){

  // Copy number.
  *res = (*lhs);
  // Truncate all other values when necessary.
  // Real;
  switch (order){
    case 0:
      *res = mdnum6_init();
      break;
    case 1:
      switch (idx){
        case 0: //  e1
          res->e1 = 0.0;
          res->e12 = 0.0;
          res->e13 = 0.0;
          res->e14 = 0.0;
          res->e15 = 0.0;
          res->e16 = 0.0;
          res->e123 = 0.0;
          res->e124 = 0.0;
          res->e134 = 0.0;
          res->e125 = 0.0;
          res->e135 = 0.0;
          res->e145 = 0.0;
          res->e126 = 0.0;
          res->e136 = 0.0;
          res->e146 = 0.0;
          res->e156 = 0.0;
          res->e1234 = 0.0;
          res->e1235 = 0.0;
          res->e1245 = 0.0;
          res->e1345 = 0.0;
          res->e1236 = 0.0;
          res->e1246 = 0.0;
          res->e1346 = 0.0;
          res->e1256 = 0.0;
          res->e1356 = 0.0;
          res->e1456 = 0.0;
          res->e12345 = 0.0;
          res->e12346 = 0.0;
          res->e12356 = 0.0;
          res->e12456 = 0.0;
          res->e13456 = 0.0;
          res->e123456 = 0.0;
          break;
        case 1: //  e2
          res->e2 = 0.0;
          res->e12 = 0.0;
          res->e23 = 0.0;
          res->e24 = 0.0;
          res->e25 = 0.0;
          res->e26 = 0.0;
          res->e123 = 0.0;
          res->e124 = 0.0;
          res->e234 = 0.0;
          res->e125 = 0.0;
          res->e235 = 0.0;
          res->e245 = 0.0;
          res->e126 = 0.0;
          res->e236 = 0.0;
          res->e246 = 0.0;
          res->e256 = 0.0;
          res->e1234 = 0.0;
          res->e1235 = 0.0;
          res->e1245 = 0.0;
          res->e2345 = 0.0;
          res->e1236 = 0.0;
          res->e1246 = 0.0;
          res->e2346 = 0.0;
          res->e1256 = 0.0;
          res->e2356 = 0.0;
          res->e2456 = 0.0;
          res->e12345 = 0.0;
          res->e12346 = 0.0;
          res->e12356 = 0.0;
          res->e12456 = 0.0;
          res->e23456 = 0.0;
          res->e123456 = 0.0;
          break;
        case 2: //  e3
          res->e3 = 0.0;
          res->e13 = 0.0;
          res->e23 = 0.0;
          res->e34 = 0.0;
          res->e35 = 0.0;
          res->e36 = 0.0;
          res->e123 = 0.0;
          res->e134 = 0.0;
          res->e234 = 0.0;
          res->e135 = 0.0;
          res->e235 = 0.0;
          res->e345 = 0.0;
          res->e136 = 0.0;
          res->e236 = 0.0;
          res->e346 = 0.0;
          res->e356 = 0.0;
          res->e1234 = 0.0;
          res->e1235 = 0.0;
          res->e1345 = 0.0;
          res->e2345 = 0.0;
          res->e1236 = 0.0;
          res->e1346 = 0.0;
          res->e2346 = 0.0;
          res->e1356 = 0.0;
          res->e2356 = 0.0;
          res->e3456 = 0.0;
          res->e12345 = 0.0;
          res->e12346 = 0.0;
          res->e12356 = 0.0;
          res->e13456 = 0.0;
          res->e23456 = 0.0;
          res->e123456 = 0.0;
          break;
        case 3: //  e4
          res->e4 = 0.0;
          res->e14 = 0.0;
          res->e24 = 0.0;
          res->e34 = 0.0;
          res->e45 = 0.0;
          res->e46 = 0.0;
          res->e124 = 0.0;
          res->e134 = 0.0;
          res->e234 = 0.0;
          res->e145 = 0.0;
          res->e245 = 0.0;
          res->e345 = 0.0;
          res->e146 = 0.0;
          res->e246 = 0.0;
          res->e346 = 0.0;
          res->e456 = 0.0;
          res->e1234 = 0.0;
          res->e1245 = 0.0;
          res->e1345 = 0.0;
          res->e2345 = 0.0;
          res->e1246 = 0.0;
          res->e1346 = 0.0;
          res->e2346 = 0.0;
          res->e1456 = 0.0;
          res->e2456 = 0.0;
          res->e3456 = 0.0;
          res->e12345 = 0.0;
          res->e12346 = 0.0;
          res->e12456 = 0.0;
          res->e13456 = 0.0;
          res->e23456 = 0.0;
          res->e123456 = 0.0;
          break;
        case 4: //  e5
          res->e5 = 0.0;
          res->e15 = 0.0;
          res->e25 = 0.0;
          res->e35 = 0.0;
          res->e45 = 0.0;
          res->e56 = 0.0;
          res->e125 = 0.0;
          res->e135 = 0.0;
          res->e235 = 0.0;
          res->e145 = 0.0;
          res->e245 = 0.0;
          res->e345 = 0.0;
          res->e156 = 0.0;
          res->e256 = 0.0;
          res->e356 = 0.0;
          res->e456 = 0.0;
          res->e1235 = 0.0;
          res->e1245 = 0.0;
          res->e1345 = 0.0;
          res->e2345 = 0.0;
          res->e1256 = 0.0;
          res->e1356 = 0.0;
          res->e2356 = 0.0;
          res->e1456 = 0.0;
          res->e2456 = 0.0;
          res->e3456 = 0.0;
          res->e12345 = 0.0;
          res->e12356 = 0.0;
          res->e12456 = 0.0;
          res->e13456 = 0.0;
          res->e23456 = 0.0;
          res->e123456 = 0.0;
          break;
        case 5: //  e6
          res->e6 = 0.0;
          res->e16 = 0.0;
          res->e26 = 0.0;
          res->e36 = 0.0;
          res->e46 = 0.0;
          res->e56 = 0.0;
          res->e126 = 0.0;
          res->e136 = 0.0;
          res->e236 = 0.0;
          res->e146 = 0.0;
          res->e246 = 0.0;
          res->e346 = 0.0;
          res->e156 = 0.0;
          res->e256 = 0.0;
          res->e356 = 0.0;
          res->e456 = 0.0;
          res->e1236 = 0.0;
          res->e1246 = 0.0;
          res->e1346 = 0.0;
          res->e2346 = 0.0;
          res->e1256 = 0.0;
          res->e1356 = 0.0;
          res->e2356 = 0.0;
          res->e1456 = 0.0;
          res->e2456 = 0.0;
          res->e3456 = 0.0;
          res->e12346 = 0.0;
          res->e12356 = 0.0;
          res->e12456 = 0.0;
          res->e13456 = 0.0;
          res->e23456 = 0.0;
          res->e123456 = 0.0;
          break;
      }
      break;
    case 2:
      switch (idx){
        case 1: //  e12
          res->e12 = 0.0;
          res->e123 = 0.0;
          res->e124 = 0.0;
          res->e125 = 0.0;
          res->e126 = 0.0;
          res->e1234 = 0.0;
          res->e1235 = 0.0;
          res->e1245 = 0.0;
          res->e1236 = 0.0;
          res->e1246 = 0.0;
          res->e1256 = 0.0;
          res->e12345 = 0.0;
          res->e12346 = 0.0;
          res->e12356 = 0.0;
          res->e12456 = 0.0;
          res->e123456 = 0.0;
          break;
        case 3: //  e13
          res->e13 = 0.0;
          res->e123 = 0.0;
          res->e134 = 0.0;
          res->e135 = 0.0;
          res->e136 = 0.0;
          res->e1234 = 0.0;
          res->e1235 = 0.0;
          res->e1345 = 0.0;
          res->e1236 = 0.0;
          res->e1346 = 0.0;
          res->e1356 = 0.0;
          res->e12345 = 0.0;
          res->e12346 = 0.0;
          res->e12356 = 0.0;
          res->e13456 = 0.0;
          res->e123456 = 0.0;
          break;
        case 4: //  e23
          res->e23 = 0.0;
          res->e123 = 0.0;
          res->e234 = 0.0;
          res->e235 = 0.0;
          res->e236 = 0.0;
          res->e1234 = 0.0;
          res->e1235 = 0.0;
          res->e2345 = 0.0;
          res->e1236 = 0.0;
          res->e2346 = 0.0;
          res->e2356 = 0.0;
          res->e12345 = 0.0;
          res->e12346 = 0.0;
          res->e12356 = 0.0;
          res->e23456 = 0.0;
          res->e123456 = 0.0;
          break;
        case 6: //  e14
          res->e14 = 0.0;
          res->e124 = 0.0;
          res->e134 = 0.0;
          res->e145 = 0.0;
          res->e146 = 0.0;
          res->e1234 = 0.0;
          res->e1245 = 0.0;
          res->e1345 = 0.0;
          res->e1246 = 0.0;
          res->e1346 = 0.0;
          res->e1456 = 0.0;
          res->e12345 = 0.0;
          res->e12346 = 0.0;
          res->e12456 = 0.0;
          res->e13456 = 0.0;
          res->e123456 = 0.0;
          break;
        case 7: //  e24
          res->e24 = 0.0;
          res->e124 = 0.0;
          res->e234 = 0.0;
          res->e245 = 0.0;
          res->e246 = 0.0;
          res->e1234 = 0.0;
          res->e1245 = 0.0;
          res->e2345 = 0.0;
          res->e1246 = 0.0;
          res->e2346 = 0.0;
          res->e2456 = 0.0;
          res->e12345 = 0.0;
          res->e12346 = 0.0;
          res->e12456 = 0.0;
          res->e23456 = 0.0;
          res->e123456 = 0.0;
          break;
        case 8: //  e34
          res->e34 = 0.0;
          res->e134 = 0.0;
          res->e234 = 0.0;
          res->e345 = 0.0;
          res->e346 = 0.0;
          res->e1234 = 0.0;
          res->e1345 = 0.0;
          res->e2345 = 0.0;
          res->e1346 = 0.0;
          res->e2346 = 0.0;
          res->e3456 = 0.0;
          res->e12345 = 0.0;
          res->e12346 = 0.0;
          res->e13456 = 0.0;
          res->e23456 = 0.0;
          res->e123456 = 0.0;
          break;
        case 10: //  e15
          res->e15 = 0.0;
          res->e125 = 0.0;
          res->e135 = 0.0;
          res->e145 = 0.0;
          res->e156 = 0.0;
          res->e1235 = 0.0;
          res->e1245 = 0.0;
          res->e1345 = 0.0;
          res->e1256 = 0.0;
          res->e1356 = 0.0;
          res->e1456 = 0.0;
          res->e12345 = 0.0;
          res->e12356 = 0.0;
          res->e12456 = 0.0;
          res->e13456 = 0.0;
          res->e123456 = 0.0;
          break;
        case 11: //  e25
          res->e25 = 0.0;
          res->e125 = 0.0;
          res->e235 = 0.0;
          res->e245 = 0.0;
          res->e256 = 0.0;
          res->e1235 = 0.0;
          res->e1245 = 0.0;
          res->e2345 = 0.0;
          res->e1256 = 0.0;
          res->e2356 = 0.0;
          res->e2456 = 0.0;
          res->e12345 = 0.0;
          res->e12356 = 0.0;
          res->e12456 = 0.0;
          res->e23456 = 0.0;
          res->e123456 = 0.0;
          break;
        case 12: //  e35
          res->e35 = 0.0;
          res->e135 = 0.0;
          res->e235 = 0.0;
          res->e345 = 0.0;
          res->e356 = 0.0;
          res->e1235 = 0.0;
          res->e1345 = 0.0;
          res->e2345 = 0.0;
          res->e1356 = 0.0;
          res->e2356 = 0.0;
          res->e3456 = 0.0;
          res->e12345 = 0.0;
          res->e12356 = 0.0;
          res->e13456 = 0.0;
          res->e23456 = 0.0;
          res->e123456 = 0.0;
          break;
        case 13: //  e45
          res->e45 = 0.0;
          res->e145 = 0.0;
          res->e245 = 0.0;
          res->e345 = 0.0;
          res->e456 = 0.0;
          res->e1245 = 0.0;
          res->e1345 = 0.0;
          res->e2345 = 0.0;
          res->e1456 = 0.0;
          res->e2456 = 0.0;
          res->e3456 = 0.0;
          res->e12345 = 0.0;
          res->e12456 = 0.0;
          res->e13456 = 0.0;
          res->e23456 = 0.0;
          res->e123456 = 0.0;
          break;
        case 15: //  e16
          res->e16 = 0.0;
          res->e126 = 0.0;
          res->e136 = 0.0;
          res->e146 = 0.0;
          res->e156 = 0.0;
          res->e1236 = 0.0;
          res->e1246 = 0.0;
          res->e1346 = 0.0;
          res->e1256 = 0.0;
          res->e1356 = 0.0;
          res->e1456 = 0.0;
          res->e12346 = 0.0;
          res->e12356 = 0.0;
          res->e12456 = 0.0;
          res->e13456 = 0.0;
          res->e123456 = 0.0;
          break;
        case 16: //  e26
          res->e26 = 0.0;
          res->e126 = 0.0;
          res->e236 = 0.0;
          res->e246 = 0.0;
          res->e256 = 0.0;
          res->e1236 = 0.0;
          res->e1246 = 0.0;
          res->e2346 = 0.0;
          res->e1256 = 0.0;
          res->e2356 = 0.0;
          res->e2456 = 0.0;
          res->e12346 = 0.0;
          res->e12356 = 0.0;
          res->e12456 = 0.0;
          res->e23456 = 0.0;
          res->e123456 = 0.0;
          break;
        case 17: //  e36
          res->e36 = 0.0;
          res->e136 = 0.0;
          res->e236 = 0.0;
          res->e346 = 0.0;
          res->e356 = 0.0;
          res->e1236 = 0.0;
          res->e1346 = 0.0;
          res->e2346 = 0.0;
          res->e1356 = 0.0;
          res->e2356 = 0.0;
          res->e3456 = 0.0;
          res->e12346 = 0.0;
          res->e12356 = 0.0;
          res->e13456 = 0.0;
          res->e23456 = 0.0;
          res->e123456 = 0.0;
          break;
        case 18: //  e46
          res->e46 = 0.0;
          res->e146 = 0.0;
          res->e246 = 0.0;
          res->e346 = 0.0;
          res->e456 = 0.0;
          res->e1246 = 0.0;
          res->e1346 = 0.0;
          res->e2346 = 0.0;
          res->e1456 = 0.0;
          res->e2456 = 0.0;
          res->e3456 = 0.0;
          res->e12346 = 0.0;
          res->e12456 = 0.0;
          res->e13456 = 0.0;
          res->e23456 = 0.0;
          res->e123456 = 0.0;
          break;
        case 19: //  e56
          res->e56 = 0.0;
          res->e156 = 0.0;
          res->e256 = 0.0;
          res->e356 = 0.0;
          res->e456 = 0.0;
          res->e1256 = 0.0;
          res->e1356 = 0.0;
          res->e2356 = 0.0;
          res->e1456 = 0.0;
          res->e2456 = 0.0;
          res->e3456 = 0.0;
          res->e12356 = 0.0;
          res->e12456 = 0.0;
          res->e13456 = 0.0;
          res->e23456 = 0.0;
          res->e123456 = 0.0;
          break;
      }
      break;
    case 3:
      switch (idx){
        case 5: //  e123
          res->e123 = 0.0;
          res->e1234 = 0.0;
          res->e1235 = 0.0;
          res->e1236 = 0.0;
          res->e12345 = 0.0;
          res->e12346 = 0.0;
          res->e12356 = 0.0;
          res->e123456 = 0.0;
          break;
        case 11: //  e124
          res->e124 = 0.0;
          res->e1234 = 0.0;
          res->e1245 = 0.0;
          res->e1246 = 0.0;
          res->e12345 = 0.0;
          res->e12346 = 0.0;
          res->e12456 = 0.0;
          res->e123456 = 0.0;
          break;
        case 13: //  e134
          res->e134 = 0.0;
          res->e1234 = 0.0;
          res->e1345 = 0.0;
          res->e1346 = 0.0;
          res->e12345 = 0.0;
          res->e12346 = 0.0;
          res->e13456 = 0.0;
          res->e123456 = 0.0;
          break;
        case 14: //  e234
          res->e234 = 0.0;
          res->e1234 = 0.0;
          res->e2345 = 0.0;
          res->e2346 = 0.0;
          res->e12345 = 0.0;
          res->e12346 = 0.0;
          res->e23456 = 0.0;
          res->e123456 = 0.0;
          break;
        case 21: //  e125
          res->e125 = 0.0;
          res->e1235 = 0.0;
          res->e1245 = 0.0;
          res->e1256 = 0.0;
          res->e12345 = 0.0;
          res->e12356 = 0.0;
          res->e12456 = 0.0;
          res->e123456 = 0.0;
          break;
        case 23: //  e135
          res->e135 = 0.0;
          res->e1235 = 0.0;
          res->e1345 = 0.0;
          res->e1356 = 0.0;
          res->e12345 = 0.0;
          res->e12356 = 0.0;
          res->e13456 = 0.0;
          res->e123456 = 0.0;
          break;
        case 24: //  e235
          res->e235 = 0.0;
          res->e1235 = 0.0;
          res->e2345 = 0.0;
          res->e2356 = 0.0;
          res->e12345 = 0.0;
          res->e12356 = 0.0;
          res->e23456 = 0.0;
          res->e123456 = 0.0;
          break;
        case 26: //  e145
          res->e145 = 0.0;
          res->e1245 = 0.0;
          res->e1345 = 0.0;
          res->e1456 = 0.0;
          res->e12345 = 0.0;
          res->e12456 = 0.0;
          res->e13456 = 0.0;
          res->e123456 = 0.0;
          break;
        case 27: //  e245
          res->e245 = 0.0;
          res->e1245 = 0.0;
          res->e2345 = 0.0;
          res->e2456 = 0.0;
          res->e12345 = 0.0;
          res->e12456 = 0.0;
          res->e23456 = 0.0;
          res->e123456 = 0.0;
          break;
        case 28: //  e345
          res->e345 = 0.0;
          res->e1345 = 0.0;
          res->e2345 = 0.0;
          res->e3456 = 0.0;
          res->e12345 = 0.0;
          res->e13456 = 0.0;
          res->e23456 = 0.0;
          res->e123456 = 0.0;
          break;
        case 36: //  e126
          res->e126 = 0.0;
          res->e1236 = 0.0;
          res->e1246 = 0.0;
          res->e1256 = 0.0;
          res->e12346 = 0.0;
          res->e12356 = 0.0;
          res->e12456 = 0.0;
          res->e123456 = 0.0;
          break;
        case 38: //  e136
          res->e136 = 0.0;
          res->e1236 = 0.0;
          res->e1346 = 0.0;
          res->e1356 = 0.0;
          res->e12346 = 0.0;
          res->e12356 = 0.0;
          res->e13456 = 0.0;
          res->e123456 = 0.0;
          break;
        case 39: //  e236
          res->e236 = 0.0;
          res->e1236 = 0.0;
          res->e2346 = 0.0;
          res->e2356 = 0.0;
          res->e12346 = 0.0;
          res->e12356 = 0.0;
          res->e23456 = 0.0;
          res->e123456 = 0.0;
          break;
        case 41: //  e146
          res->e146 = 0.0;
          res->e1246 = 0.0;
          res->e1346 = 0.0;
          res->e1456 = 0.0;
          res->e12346 = 0.0;
          res->e12456 = 0.0;
          res->e13456 = 0.0;
          res->e123456 = 0.0;
          break;
        case 42: //  e246
          res->e246 = 0.0;
          res->e1246 = 0.0;
          res->e2346 = 0.0;
          res->e2456 = 0.0;
          res->e12346 = 0.0;
          res->e12456 = 0.0;
          res->e23456 = 0.0;
          res->e123456 = 0.0;
          break;
        case 43: //  e346
          res->e346 = 0.0;
          res->e1346 = 0.0;
          res->e2346 = 0.0;
          res->e3456 = 0.0;
          res->e12346 = 0.0;
          res->e13456 = 0.0;
          res->e23456 = 0.0;
          res->e123456 = 0.0;
          break;
        case 45: //  e156
          res->e156 = 0.0;
          res->e1256 = 0.0;
          res->e1356 = 0.0;
          res->e1456 = 0.0;
          res->e12356 = 0.0;
          res->e12456 = 0.0;
          res->e13456 = 0.0;
          res->e123456 = 0.0;
          break;
        case 46: //  e256
          res->e256 = 0.0;
          res->e1256 = 0.0;
          res->e2356 = 0.0;
          res->e2456 = 0.0;
          res->e12356 = 0.0;
          res->e12456 = 0.0;
          res->e23456 = 0.0;
          res->e123456 = 0.0;
          break;
        case 47: //  e356
          res->e356 = 0.0;
          res->e1356 = 0.0;
          res->e2356 = 0.0;
          res->e3456 = 0.0;
          res->e12356 = 0.0;
          res->e13456 = 0.0;
          res->e23456 = 0.0;
          res->e123456 = 0.0;
          break;
        case 48: //  e456
          res->e456 = 0.0;
          res->e1456 = 0.0;
          res->e2456 = 0.0;
          res->e3456 = 0.0;
          res->e12456 = 0.0;
          res->e13456 = 0.0;
          res->e23456 = 0.0;
          res->e123456 = 0.0;
          break;
      }
      break;
    case 4:
      switch (idx){
        case 20: //  e1234
          res->e1234 = 0.0;
          res->e12345 = 0.0;
          res->e12346 = 0.0;
          res->e123456 = 0.0;
          break;
        case 40: //  e1235
          res->e1235 = 0.0;
          res->e12345 = 0.0;
          res->e12356 = 0.0;
          res->e123456 = 0.0;
          break;
        case 46: //  e1245
          res->e1245 = 0.0;
          res->e12345 = 0.0;
          res->e12456 = 0.0;
          res->e123456 = 0.0;
          break;
        case 48: //  e1345
          res->e1345 = 0.0;
          res->e12345 = 0.0;
          res->e13456 = 0.0;
          res->e123456 = 0.0;
          break;
        case 49: //  e2345
          res->e2345 = 0.0;
          res->e12345 = 0.0;
          res->e23456 = 0.0;
          res->e123456 = 0.0;
          break;
        case 75: //  e1236
          res->e1236 = 0.0;
          res->e12346 = 0.0;
          res->e12356 = 0.0;
          res->e123456 = 0.0;
          break;
        case 81: //  e1246
          res->e1246 = 0.0;
          res->e12346 = 0.0;
          res->e12456 = 0.0;
          res->e123456 = 0.0;
          break;
        case 83: //  e1346
          res->e1346 = 0.0;
          res->e12346 = 0.0;
          res->e13456 = 0.0;
          res->e123456 = 0.0;
          break;
        case 84: //  e2346
          res->e2346 = 0.0;
          res->e12346 = 0.0;
          res->e23456 = 0.0;
          res->e123456 = 0.0;
          break;
        case 91: //  e1256
          res->e1256 = 0.0;
          res->e12356 = 0.0;
          res->e12456 = 0.0;
          res->e123456 = 0.0;
          break;
        case 93: //  e1356
          res->e1356 = 0.0;
          res->e12356 = 0.0;
          res->e13456 = 0.0;
          res->e123456 = 0.0;
          break;
        case 94: //  e2356
          res->e2356 = 0.0;
          res->e12356 = 0.0;
          res->e23456 = 0.0;
          res->e123456 = 0.0;
          break;
        case 96: //  e1456
          res->e1456 = 0.0;
          res->e12456 = 0.0;
          res->e13456 = 0.0;
          res->e123456 = 0.0;
          break;
        case 97: //  e2456
          res->e2456 = 0.0;
          res->e12456 = 0.0;
          res->e23456 = 0.0;
          res->e123456 = 0.0;
          break;
        case 98: //  e3456
          res->e3456 = 0.0;
          res->e13456 = 0.0;
          res->e23456 = 0.0;
          res->e123456 = 0.0;
          break;
      }
      break;
    case 5:
      switch (idx){
        case 76: //  e12345
          res->e12345 = 0.0;
          res->e123456 = 0.0;
          break;
        case 146: //  e12346
          res->e12346 = 0.0;
          res->e123456 = 0.0;
          break;
        case 166: //  e12356
          res->e12356 = 0.0;
          res->e123456 = 0.0;
          break;
        case 172: //  e12456
          res->e12456 = 0.0;
          res->e123456 = 0.0;
          break;
        case 174: //  e13456
          res->e13456 = 0.0;
          res->e123456 = 0.0;
          break;
        case 175: //  e23456
          res->e23456 = 0.0;
          res->e123456 = 0.0;
          break;
      }
      break;
    case 6:
      switch (idx){
        case 286: //  e123456
          res->e123456 = 0.0;
          break;
      }
      break;
  }
}

void mdnum6_print(  mdnum6_t* lhs){

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
  //  Order 2;
  printf(" %+.8g*e12",lhs->e12);
  printf(" %+.8g*e13",lhs->e13);
  printf(" %+.8g*e23",lhs->e23);
  printf(" %+.8g*e14",lhs->e14);
  printf(" %+.8g*e24",lhs->e24);
  printf(" %+.8g*e34",lhs->e34);
  printf(" %+.8g*e15",lhs->e15);
  printf(" %+.8g*e25",lhs->e25);
  printf(" %+.8g*e35",lhs->e35);
  printf(" %+.8g*e45",lhs->e45);
  printf(" %+.8g*e16",lhs->e16);
  printf(" %+.8g*e26",lhs->e26);
  printf(" %+.8g*e36",lhs->e36);
  printf(" %+.8g*e46",lhs->e46);
  printf(" %+.8g*e56",lhs->e56);
  //  Order 3;
  printf(" %+.8g*e123",lhs->e123);
  printf(" %+.8g*e124",lhs->e124);
  printf(" %+.8g*e134",lhs->e134);
  printf(" %+.8g*e234",lhs->e234);
  printf(" %+.8g*e125",lhs->e125);
  printf(" %+.8g*e135",lhs->e135);
  printf(" %+.8g*e235",lhs->e235);
  printf(" %+.8g*e145",lhs->e145);
  printf(" %+.8g*e245",lhs->e245);
  printf(" %+.8g*e345",lhs->e345);
  printf(" %+.8g*e126",lhs->e126);
  printf(" %+.8g*e136",lhs->e136);
  printf(" %+.8g*e236",lhs->e236);
  printf(" %+.8g*e146",lhs->e146);
  printf(" %+.8g*e246",lhs->e246);
  printf(" %+.8g*e346",lhs->e346);
  printf(" %+.8g*e156",lhs->e156);
  printf(" %+.8g*e256",lhs->e256);
  printf(" %+.8g*e356",lhs->e356);
  printf(" %+.8g*e456",lhs->e456);
  //  Order 4;
  printf(" %+.8g*e1234",lhs->e1234);
  printf(" %+.8g*e1235",lhs->e1235);
  printf(" %+.8g*e1245",lhs->e1245);
  printf(" %+.8g*e1345",lhs->e1345);
  printf(" %+.8g*e2345",lhs->e2345);
  printf(" %+.8g*e1236",lhs->e1236);
  printf(" %+.8g*e1246",lhs->e1246);
  printf(" %+.8g*e1346",lhs->e1346);
  printf(" %+.8g*e2346",lhs->e2346);
  printf(" %+.8g*e1256",lhs->e1256);
  printf(" %+.8g*e1356",lhs->e1356);
  printf(" %+.8g*e2356",lhs->e2356);
  printf(" %+.8g*e1456",lhs->e1456);
  printf(" %+.8g*e2456",lhs->e2456);
  printf(" %+.8g*e3456",lhs->e3456);
  //  Order 5;
  printf(" %+.8g*e12345",lhs->e12345);
  printf(" %+.8g*e12346",lhs->e12346);
  printf(" %+.8g*e12356",lhs->e12356);
  printf(" %+.8g*e12456",lhs->e12456);
  printf(" %+.8g*e13456",lhs->e13456);
  printf(" %+.8g*e23456",lhs->e23456);
  //  Order 6;
  printf(" %+.8g*e123456",lhs->e123456);
  printf("\n");

}

imdir_t mdnum6_get_indx(imdir_t idx, ord_t order){

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
        case 3:
          return 6;
          break;
        case 4:
          return 7;
          break;
        case 5:
          return 8;
          break;
        case 6:
          return 10;
          break;
        case 7:
          return 11;
          break;
        case 8:
          return 12;
          break;
        case 9:
          return 13;
          break;
        case 10:
          return 15;
          break;
        case 11:
          return 16;
          break;
        case 12:
          return 17;
          break;
        case 13:
          return 18;
          break;
        case 14:
          return 19;
          break;
      }
      break;
    case 3:
      switch (idx){
        case 0:
          return 5;
          break;
        case 1:
          return 11;
          break;
        case 2:
          return 13;
          break;
        case 3:
          return 14;
          break;
        case 4:
          return 21;
          break;
        case 5:
          return 23;
          break;
        case 6:
          return 24;
          break;
        case 7:
          return 26;
          break;
        case 8:
          return 27;
          break;
        case 9:
          return 28;
          break;
        case 10:
          return 36;
          break;
        case 11:
          return 38;
          break;
        case 12:
          return 39;
          break;
        case 13:
          return 41;
          break;
        case 14:
          return 42;
          break;
        case 15:
          return 43;
          break;
        case 16:
          return 45;
          break;
        case 17:
          return 46;
          break;
        case 18:
          return 47;
          break;
        case 19:
          return 48;
          break;
      }
      break;
    case 4:
      switch (idx){
        case 0:
          return 20;
          break;
        case 1:
          return 40;
          break;
        case 2:
          return 46;
          break;
        case 3:
          return 48;
          break;
        case 4:
          return 49;
          break;
        case 5:
          return 75;
          break;
        case 6:
          return 81;
          break;
        case 7:
          return 83;
          break;
        case 8:
          return 84;
          break;
        case 9:
          return 91;
          break;
        case 10:
          return 93;
          break;
        case 11:
          return 94;
          break;
        case 12:
          return 96;
          break;
        case 13:
          return 97;
          break;
        case 14:
          return 98;
          break;
      }
      break;
    case 5:
      switch (idx){
        case 0:
          return 76;
          break;
        case 1:
          return 146;
          break;
        case 2:
          return 166;
          break;
        case 3:
          return 172;
          break;
        case 4:
          return 174;
          break;
        case 5:
          return 175;
          break;
      }
      break;
    case 6:
      switch (idx){
        case 0:
          return 286;
          break;
      }
      break;
      default:
          return 0;
  }
  return 0;
}

