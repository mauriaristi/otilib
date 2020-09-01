

// Not implemented correctly:
void mdnum5_set_im_o(mdnum5_t* num, imdir_t idx, ord_t order, mdnum5_t* res){
    mdnum5_set_item(num->r,idx,order,res);
}
void mdnum5_set_deriv_r(coeff_t num, imdir_t idx, ord_t order, mdnum5_t* res){
    *res=mdnum5_init();
}
void mdnum5_set_deriv_o(mdnum5_t* num, imdir_t idx, ord_t order, mdnum5_t* res){
    *res=mdnum5_init();
}
void mdnum5_extract_im_to( imdir_t idx, ord_t order, mdnum5_t* num, mdnum5_t* res){
    *res=mdnum5_init();
}
mdnum5_t mdnum5_extract_im(imdir_t idx, ord_t order, mdnum5_t* num){
    mdnum5_t res = mdnum5_init();
    return res;
}
mdnum5_t mdnum5_extract_deriv(imdir_t idx, ord_t order, mdnum5_t* num){
    mdnum5_t res = mdnum5_init();
    return res;
}
void mdnum5_extract_deriv_to(imdir_t idx, ord_t order, mdnum5_t* num, mdnum5_t* res){
	*res = mdnum5_init();
}
void mdnum5_get_im_to_o(imdir_t idx, ord_t order, mdnum5_t* num, mdnum5_t* res){
    coeff_t rres = mdnum5_get_item(idx, order, num);
    mdnum5_set_r(rres,res);
}
mdnum5_t mdnum5_get_im_o(imdir_t idx, ord_t order, mdnum5_t* num){
    coeff_t rres = mdnum5_get_item(idx, order, num);
    mdnum5_t res;
    mdnum5_set_r(rres,&res);
    return res;
}
void mdnum5_get_im_to_r(imdir_t idx, ord_t order, mdnum5_t* num, coeff_t* res){
    *res = mdnum5_get_item(idx, order, num);
}

inline ord_t mdnum5_get_order(mdnum5_t* lhs){

	return 5;

}

mdnum5_t mdnum5_get_deriv_o( imdir_t idx, ord_t order, mdnum5_t* num){

    mdnum5_t res = mdnum5_init();

    mdnum5_get_deriv_to( idx, order, num, &res);
    
    return res;

}

void mdnum5_get_deriv_to( imdir_t idx, ord_t order, mdnum5_t* num, mdnum5_t* res){

    coeff_t deriv = mdnum5_get_deriv(idx,order,num);

    mdnum5_set_r( deriv, res);

}

void mdnum5_set_im_r(coeff_t num, imdir_t idx, ord_t order, mdnum5_t* res){

    mdnum5_set_item(num, idx,order,res);

}

mdnum5_t mdnum5_init(void){

  mdnum5_t res;

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
  // Order 4;
  res.e1234 = 0.0;
  res.e1235 = 0.0;
  res.e1245 = 0.0;
  res.e1345 = 0.0;
  res.e2345 = 0.0;
  // Order 5;
  res.e12345 = 0.0;

  return res;

}

ndir_t mdnum5_get_ndir_order(ord_t order, mdnum5_t* num){

  ndir_t res;

  switch(order){
    case 0:
      res = 1;
      break;
    case 1:
      res = 5;
      break;
    case 2:
      res = 10;
      break;
    case 3:
      res = 10;
      break;
    case 4:
      res = 5;
      break;
    case 5:
      res = 1;
      break;
  }

  return res;

}

ndir_t mdnum5_get_ndir_total(mdnum5_t* num){

  ndir_t res;

  res = 31;

  return res;

}

coeff_t* mdnum5_get_order_address(ord_t order, mdnum5_t* num){

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
  }
  return res;

}

mdnum5_t mdnum5_create_r(  coeff_t lhs){

  mdnum5_t res;

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
  // Order 4;
  res.e1234 = 0.0;
  res.e1235 = 0.0;
  res.e1245 = 0.0;
  res.e1345 = 0.0;
  res.e2345 = 0.0;
  // Order 5;
  res.e12345 = 0.0;

  return res;

}

void mdnum5_set_r(  coeff_t lhs, mdnum5_t* res){

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
  // Order 4;
  res->e1234 = 0.0;
  res->e1235 = 0.0;
  res->e1245 = 0.0;
  res->e1345 = 0.0;
  res->e2345 = 0.0;
  // Order 5;
  res->e12345 = 0.0;

}

void mdnum5_set_o(  mdnum5_t* lhs, mdnum5_t* res){

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
  // Order 4;
  res->e1234 = lhs->e1234;
  res->e1235 = lhs->e1235;
  res->e1245 = lhs->e1245;
  res->e1345 = lhs->e1345;
  res->e2345 = lhs->e2345;
  // Order 5;
  res->e12345 = lhs->e12345;

}

mdnum5_t mdnum5_get_order_im(ord_t order, mdnum5_t* lhs){

  mdnum5_t res;

  res = mdnum5_init();
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
      break;
    case 4:
      // Order 4;
      res.e1234 = lhs->e1234;
      res.e1235 = lhs->e1235;
      res.e1245 = lhs->e1245;
      res.e1345 = lhs->e1345;
      res.e2345 = lhs->e2345;
      break;
    case 5:
      // Order 5;
      res.e12345 = lhs->e12345;
      break;
  }

  return res;

}

void mdnum5_get_order_im_to(ord_t order, mdnum5_t* lhs, mdnum5_t* res){


  *res = mdnum5_init();
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
      break;
    case 4:
      // Order 4;
      res->e1234 = lhs->e1234;
      res->e1235 = lhs->e1235;
      res->e1245 = lhs->e1245;
      res->e1345 = lhs->e1345;
      res->e2345 = lhs->e2345;
      break;
    case 5:
      // Order 5;
      res->e12345 = lhs->e12345;
      break;
  }

}

coeff_t mdnum5_get_item(imdir_t idx, ord_t order, mdnum5_t* lhs){

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
      }
      break;
    case 5:
      switch (idx){
        case 76:
          res = lhs->e12345;
          break;
      }
      break;
  }
  return res;

}

coeff_t mdnum5_get_deriv(imdir_t idx, ord_t order, mdnum5_t* lhs){

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
      }
      break;
    case 5:
      switch (idx){
        case 76:
          factor = 1.0000000000000000e+00;
          res = lhs->e12345*factor;
          break;
      }
      break;
  }
  return res;

}

void mdnum5_set_item(coeff_t val, imdir_t idx, ord_t order, mdnum5_t* x){

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
      }
      break;
    case 5:
      switch (idx){
        case 76:
          x->e12345 = val;
          break;
      }
      break;
  }
}

mdnum5_t mdnum5_copy(  mdnum5_t* lhs){

  mdnum5_t res;

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
  // Order 4;
  res.e1234 = lhs->e1234;
  res.e1235 = lhs->e1235;
  res.e1245 = lhs->e1245;
  res.e1345 = lhs->e1345;
  res.e2345 = lhs->e2345;
  // Order 5;
  res.e12345 = lhs->e12345;

  return res;

}

void mdnum5_copy_to(  mdnum5_t* lhs, mdnum5_t* res){

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
  // Order 4;
  res->e1234 = lhs->e1234;
  res->e1235 = lhs->e1235;
  res->e1245 = lhs->e1245;
  res->e1345 = lhs->e1345;
  res->e2345 = lhs->e2345;
  // Order 5;
  res->e12345 = lhs->e12345;

}

mdnum5_t mdnum5_taylor_integrate(coeff_t* deltas,mdnum5_t* lhs){

  mdnum5_t res;

  res = mdnum5_init();
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
  factor = pow(deltas[0],1)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],0);
  res.r += factor*lhs->e12;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],0)*pow(deltas[4],0);
  res.r += factor*lhs->e13;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],1)*pow(deltas[3],0)*pow(deltas[4],0);
  res.r += factor*lhs->e23;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],1)*pow(deltas[4],0);
  res.r += factor*lhs->e14;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],1)*pow(deltas[4],0);
  res.r += factor*lhs->e24;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],1)*pow(deltas[4],0);
  res.r += factor*lhs->e34;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],1);
  res.r += factor*lhs->e15;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],1);
  res.r += factor*lhs->e25;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],0)*pow(deltas[4],1);
  res.r += factor*lhs->e35;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],1)*pow(deltas[4],1);
  res.r += factor*lhs->e45;
  // Order 3;
  factor = pow(deltas[0],1)*pow(deltas[1],1)*pow(deltas[2],1)*pow(deltas[3],0)*pow(deltas[4],0);
  res.r += factor*lhs->e123;
  factor = pow(deltas[0],1)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],1)*pow(deltas[4],0);
  res.r += factor*lhs->e124;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],1)*pow(deltas[4],0);
  res.r += factor*lhs->e134;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],1)*pow(deltas[3],1)*pow(deltas[4],0);
  res.r += factor*lhs->e234;
  factor = pow(deltas[0],1)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],1);
  res.r += factor*lhs->e125;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],0)*pow(deltas[4],1);
  res.r += factor*lhs->e135;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],1)*pow(deltas[3],0)*pow(deltas[4],1);
  res.r += factor*lhs->e235;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],1)*pow(deltas[4],1);
  res.r += factor*lhs->e145;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],1)*pow(deltas[4],1);
  res.r += factor*lhs->e245;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],1)*pow(deltas[4],1);
  res.r += factor*lhs->e345;
  // Order 4;
  factor = pow(deltas[0],1)*pow(deltas[1],1)*pow(deltas[2],1)*pow(deltas[3],1)*pow(deltas[4],0);
  res.r += factor*lhs->e1234;
  factor = pow(deltas[0],1)*pow(deltas[1],1)*pow(deltas[2],1)*pow(deltas[3],0)*pow(deltas[4],1);
  res.r += factor*lhs->e1235;
  factor = pow(deltas[0],1)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],1)*pow(deltas[4],1);
  res.r += factor*lhs->e1245;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],1)*pow(deltas[4],1);
  res.r += factor*lhs->e1345;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],1)*pow(deltas[3],1)*pow(deltas[4],1);
  res.r += factor*lhs->e2345;
  // Order 5;
  factor = pow(deltas[0],1)*pow(deltas[1],1)*pow(deltas[2],1)*pow(deltas[3],1)*pow(deltas[4],1);
  res.r += factor*lhs->e12345;

  return res;

}

void mdnum5_taylor_integrate_to(coeff_t* deltas,mdnum5_t* lhs, mdnum5_t* res){

  *res = mdnum5_init();
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
  factor = pow(deltas[0],1)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],0);
  res->r += factor*lhs->e12;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],0)*pow(deltas[4],0);
  res->r += factor*lhs->e13;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],1)*pow(deltas[3],0)*pow(deltas[4],0);
  res->r += factor*lhs->e23;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],1)*pow(deltas[4],0);
  res->r += factor*lhs->e14;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],1)*pow(deltas[4],0);
  res->r += factor*lhs->e24;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],1)*pow(deltas[4],0);
  res->r += factor*lhs->e34;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],1);
  res->r += factor*lhs->e15;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],1);
  res->r += factor*lhs->e25;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],0)*pow(deltas[4],1);
  res->r += factor*lhs->e35;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],1)*pow(deltas[4],1);
  res->r += factor*lhs->e45;
  // Order 3;
  factor = pow(deltas[0],1)*pow(deltas[1],1)*pow(deltas[2],1)*pow(deltas[3],0)*pow(deltas[4],0);
  res->r += factor*lhs->e123;
  factor = pow(deltas[0],1)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],1)*pow(deltas[4],0);
  res->r += factor*lhs->e124;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],1)*pow(deltas[4],0);
  res->r += factor*lhs->e134;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],1)*pow(deltas[3],1)*pow(deltas[4],0);
  res->r += factor*lhs->e234;
  factor = pow(deltas[0],1)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],1);
  res->r += factor*lhs->e125;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],0)*pow(deltas[4],1);
  res->r += factor*lhs->e135;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],1)*pow(deltas[3],0)*pow(deltas[4],1);
  res->r += factor*lhs->e235;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],1)*pow(deltas[4],1);
  res->r += factor*lhs->e145;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],1)*pow(deltas[4],1);
  res->r += factor*lhs->e245;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],1)*pow(deltas[4],1);
  res->r += factor*lhs->e345;
  // Order 4;
  factor = pow(deltas[0],1)*pow(deltas[1],1)*pow(deltas[2],1)*pow(deltas[3],1)*pow(deltas[4],0);
  res->r += factor*lhs->e1234;
  factor = pow(deltas[0],1)*pow(deltas[1],1)*pow(deltas[2],1)*pow(deltas[3],0)*pow(deltas[4],1);
  res->r += factor*lhs->e1235;
  factor = pow(deltas[0],1)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],1)*pow(deltas[4],1);
  res->r += factor*lhs->e1245;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],1)*pow(deltas[4],1);
  res->r += factor*lhs->e1345;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],1)*pow(deltas[3],1)*pow(deltas[4],1);
  res->r += factor*lhs->e2345;
  // Order 5;
  factor = pow(deltas[0],1)*pow(deltas[1],1)*pow(deltas[2],1)*pow(deltas[3],1)*pow(deltas[4],1);
  res->r += factor*lhs->e12345;

}

mdnum5_t mdnum5_truncate_im(imdir_t idx, ord_t order, mdnum5_t* lhs){

  mdnum5_t res;

  // Copy number.
  res = (*lhs);
  // Truncate all other values when necessary.
  // Real;
  switch (order){
    case 0:
      res = mdnum5_init();
      break;
    case 1:
      switch (idx){
        case 0: //  e1
          res.e1 = 0.0;
          res.e12 = 0.0;
          res.e13 = 0.0;
          res.e14 = 0.0;
          res.e15 = 0.0;
          res.e123 = 0.0;
          res.e124 = 0.0;
          res.e134 = 0.0;
          res.e125 = 0.0;
          res.e135 = 0.0;
          res.e145 = 0.0;
          res.e1234 = 0.0;
          res.e1235 = 0.0;
          res.e1245 = 0.0;
          res.e1345 = 0.0;
          res.e12345 = 0.0;
          break;
        case 1: //  e2
          res.e2 = 0.0;
          res.e12 = 0.0;
          res.e23 = 0.0;
          res.e24 = 0.0;
          res.e25 = 0.0;
          res.e123 = 0.0;
          res.e124 = 0.0;
          res.e234 = 0.0;
          res.e125 = 0.0;
          res.e235 = 0.0;
          res.e245 = 0.0;
          res.e1234 = 0.0;
          res.e1235 = 0.0;
          res.e1245 = 0.0;
          res.e2345 = 0.0;
          res.e12345 = 0.0;
          break;
        case 2: //  e3
          res.e3 = 0.0;
          res.e13 = 0.0;
          res.e23 = 0.0;
          res.e34 = 0.0;
          res.e35 = 0.0;
          res.e123 = 0.0;
          res.e134 = 0.0;
          res.e234 = 0.0;
          res.e135 = 0.0;
          res.e235 = 0.0;
          res.e345 = 0.0;
          res.e1234 = 0.0;
          res.e1235 = 0.0;
          res.e1345 = 0.0;
          res.e2345 = 0.0;
          res.e12345 = 0.0;
          break;
        case 3: //  e4
          res.e4 = 0.0;
          res.e14 = 0.0;
          res.e24 = 0.0;
          res.e34 = 0.0;
          res.e45 = 0.0;
          res.e124 = 0.0;
          res.e134 = 0.0;
          res.e234 = 0.0;
          res.e145 = 0.0;
          res.e245 = 0.0;
          res.e345 = 0.0;
          res.e1234 = 0.0;
          res.e1245 = 0.0;
          res.e1345 = 0.0;
          res.e2345 = 0.0;
          res.e12345 = 0.0;
          break;
        case 4: //  e5
          res.e5 = 0.0;
          res.e15 = 0.0;
          res.e25 = 0.0;
          res.e35 = 0.0;
          res.e45 = 0.0;
          res.e125 = 0.0;
          res.e135 = 0.0;
          res.e235 = 0.0;
          res.e145 = 0.0;
          res.e245 = 0.0;
          res.e345 = 0.0;
          res.e1235 = 0.0;
          res.e1245 = 0.0;
          res.e1345 = 0.0;
          res.e2345 = 0.0;
          res.e12345 = 0.0;
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
          res.e1234 = 0.0;
          res.e1235 = 0.0;
          res.e1245 = 0.0;
          res.e12345 = 0.0;
          break;
        case 3: //  e13
          res.e13 = 0.0;
          res.e123 = 0.0;
          res.e134 = 0.0;
          res.e135 = 0.0;
          res.e1234 = 0.0;
          res.e1235 = 0.0;
          res.e1345 = 0.0;
          res.e12345 = 0.0;
          break;
        case 4: //  e23
          res.e23 = 0.0;
          res.e123 = 0.0;
          res.e234 = 0.0;
          res.e235 = 0.0;
          res.e1234 = 0.0;
          res.e1235 = 0.0;
          res.e2345 = 0.0;
          res.e12345 = 0.0;
          break;
        case 6: //  e14
          res.e14 = 0.0;
          res.e124 = 0.0;
          res.e134 = 0.0;
          res.e145 = 0.0;
          res.e1234 = 0.0;
          res.e1245 = 0.0;
          res.e1345 = 0.0;
          res.e12345 = 0.0;
          break;
        case 7: //  e24
          res.e24 = 0.0;
          res.e124 = 0.0;
          res.e234 = 0.0;
          res.e245 = 0.0;
          res.e1234 = 0.0;
          res.e1245 = 0.0;
          res.e2345 = 0.0;
          res.e12345 = 0.0;
          break;
        case 8: //  e34
          res.e34 = 0.0;
          res.e134 = 0.0;
          res.e234 = 0.0;
          res.e345 = 0.0;
          res.e1234 = 0.0;
          res.e1345 = 0.0;
          res.e2345 = 0.0;
          res.e12345 = 0.0;
          break;
        case 10: //  e15
          res.e15 = 0.0;
          res.e125 = 0.0;
          res.e135 = 0.0;
          res.e145 = 0.0;
          res.e1235 = 0.0;
          res.e1245 = 0.0;
          res.e1345 = 0.0;
          res.e12345 = 0.0;
          break;
        case 11: //  e25
          res.e25 = 0.0;
          res.e125 = 0.0;
          res.e235 = 0.0;
          res.e245 = 0.0;
          res.e1235 = 0.0;
          res.e1245 = 0.0;
          res.e2345 = 0.0;
          res.e12345 = 0.0;
          break;
        case 12: //  e35
          res.e35 = 0.0;
          res.e135 = 0.0;
          res.e235 = 0.0;
          res.e345 = 0.0;
          res.e1235 = 0.0;
          res.e1345 = 0.0;
          res.e2345 = 0.0;
          res.e12345 = 0.0;
          break;
        case 13: //  e45
          res.e45 = 0.0;
          res.e145 = 0.0;
          res.e245 = 0.0;
          res.e345 = 0.0;
          res.e1245 = 0.0;
          res.e1345 = 0.0;
          res.e2345 = 0.0;
          res.e12345 = 0.0;
          break;
      }
      break;
    case 3:
      switch (idx){
        case 5: //  e123
          res.e123 = 0.0;
          res.e1234 = 0.0;
          res.e1235 = 0.0;
          res.e12345 = 0.0;
          break;
        case 11: //  e124
          res.e124 = 0.0;
          res.e1234 = 0.0;
          res.e1245 = 0.0;
          res.e12345 = 0.0;
          break;
        case 13: //  e134
          res.e134 = 0.0;
          res.e1234 = 0.0;
          res.e1345 = 0.0;
          res.e12345 = 0.0;
          break;
        case 14: //  e234
          res.e234 = 0.0;
          res.e1234 = 0.0;
          res.e2345 = 0.0;
          res.e12345 = 0.0;
          break;
        case 21: //  e125
          res.e125 = 0.0;
          res.e1235 = 0.0;
          res.e1245 = 0.0;
          res.e12345 = 0.0;
          break;
        case 23: //  e135
          res.e135 = 0.0;
          res.e1235 = 0.0;
          res.e1345 = 0.0;
          res.e12345 = 0.0;
          break;
        case 24: //  e235
          res.e235 = 0.0;
          res.e1235 = 0.0;
          res.e2345 = 0.0;
          res.e12345 = 0.0;
          break;
        case 26: //  e145
          res.e145 = 0.0;
          res.e1245 = 0.0;
          res.e1345 = 0.0;
          res.e12345 = 0.0;
          break;
        case 27: //  e245
          res.e245 = 0.0;
          res.e1245 = 0.0;
          res.e2345 = 0.0;
          res.e12345 = 0.0;
          break;
        case 28: //  e345
          res.e345 = 0.0;
          res.e1345 = 0.0;
          res.e2345 = 0.0;
          res.e12345 = 0.0;
          break;
      }
      break;
    case 4:
      switch (idx){
        case 20: //  e1234
          res.e1234 = 0.0;
          res.e12345 = 0.0;
          break;
        case 40: //  e1235
          res.e1235 = 0.0;
          res.e12345 = 0.0;
          break;
        case 46: //  e1245
          res.e1245 = 0.0;
          res.e12345 = 0.0;
          break;
        case 48: //  e1345
          res.e1345 = 0.0;
          res.e12345 = 0.0;
          break;
        case 49: //  e2345
          res.e2345 = 0.0;
          res.e12345 = 0.0;
          break;
      }
      break;
    case 5:
      switch (idx){
        case 76: //  e12345
          res.e12345 = 0.0;
          break;
      }
      break;
  }
  return res;

}

void mdnum5_truncate_im_to(imdir_t idx, ord_t order, mdnum5_t* lhs, mdnum5_t* res){

  // Copy number.
  *res = (*lhs);
  // Truncate all other values when necessary.
  // Real;
  switch (order){
    case 0:
      *res = mdnum5_init();
      break;
    case 1:
      switch (idx){
        case 0: //  e1
          res->e1 = 0.0;
          res->e12 = 0.0;
          res->e13 = 0.0;
          res->e14 = 0.0;
          res->e15 = 0.0;
          res->e123 = 0.0;
          res->e124 = 0.0;
          res->e134 = 0.0;
          res->e125 = 0.0;
          res->e135 = 0.0;
          res->e145 = 0.0;
          res->e1234 = 0.0;
          res->e1235 = 0.0;
          res->e1245 = 0.0;
          res->e1345 = 0.0;
          res->e12345 = 0.0;
          break;
        case 1: //  e2
          res->e2 = 0.0;
          res->e12 = 0.0;
          res->e23 = 0.0;
          res->e24 = 0.0;
          res->e25 = 0.0;
          res->e123 = 0.0;
          res->e124 = 0.0;
          res->e234 = 0.0;
          res->e125 = 0.0;
          res->e235 = 0.0;
          res->e245 = 0.0;
          res->e1234 = 0.0;
          res->e1235 = 0.0;
          res->e1245 = 0.0;
          res->e2345 = 0.0;
          res->e12345 = 0.0;
          break;
        case 2: //  e3
          res->e3 = 0.0;
          res->e13 = 0.0;
          res->e23 = 0.0;
          res->e34 = 0.0;
          res->e35 = 0.0;
          res->e123 = 0.0;
          res->e134 = 0.0;
          res->e234 = 0.0;
          res->e135 = 0.0;
          res->e235 = 0.0;
          res->e345 = 0.0;
          res->e1234 = 0.0;
          res->e1235 = 0.0;
          res->e1345 = 0.0;
          res->e2345 = 0.0;
          res->e12345 = 0.0;
          break;
        case 3: //  e4
          res->e4 = 0.0;
          res->e14 = 0.0;
          res->e24 = 0.0;
          res->e34 = 0.0;
          res->e45 = 0.0;
          res->e124 = 0.0;
          res->e134 = 0.0;
          res->e234 = 0.0;
          res->e145 = 0.0;
          res->e245 = 0.0;
          res->e345 = 0.0;
          res->e1234 = 0.0;
          res->e1245 = 0.0;
          res->e1345 = 0.0;
          res->e2345 = 0.0;
          res->e12345 = 0.0;
          break;
        case 4: //  e5
          res->e5 = 0.0;
          res->e15 = 0.0;
          res->e25 = 0.0;
          res->e35 = 0.0;
          res->e45 = 0.0;
          res->e125 = 0.0;
          res->e135 = 0.0;
          res->e235 = 0.0;
          res->e145 = 0.0;
          res->e245 = 0.0;
          res->e345 = 0.0;
          res->e1235 = 0.0;
          res->e1245 = 0.0;
          res->e1345 = 0.0;
          res->e2345 = 0.0;
          res->e12345 = 0.0;
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
          res->e1234 = 0.0;
          res->e1235 = 0.0;
          res->e1245 = 0.0;
          res->e12345 = 0.0;
          break;
        case 3: //  e13
          res->e13 = 0.0;
          res->e123 = 0.0;
          res->e134 = 0.0;
          res->e135 = 0.0;
          res->e1234 = 0.0;
          res->e1235 = 0.0;
          res->e1345 = 0.0;
          res->e12345 = 0.0;
          break;
        case 4: //  e23
          res->e23 = 0.0;
          res->e123 = 0.0;
          res->e234 = 0.0;
          res->e235 = 0.0;
          res->e1234 = 0.0;
          res->e1235 = 0.0;
          res->e2345 = 0.0;
          res->e12345 = 0.0;
          break;
        case 6: //  e14
          res->e14 = 0.0;
          res->e124 = 0.0;
          res->e134 = 0.0;
          res->e145 = 0.0;
          res->e1234 = 0.0;
          res->e1245 = 0.0;
          res->e1345 = 0.0;
          res->e12345 = 0.0;
          break;
        case 7: //  e24
          res->e24 = 0.0;
          res->e124 = 0.0;
          res->e234 = 0.0;
          res->e245 = 0.0;
          res->e1234 = 0.0;
          res->e1245 = 0.0;
          res->e2345 = 0.0;
          res->e12345 = 0.0;
          break;
        case 8: //  e34
          res->e34 = 0.0;
          res->e134 = 0.0;
          res->e234 = 0.0;
          res->e345 = 0.0;
          res->e1234 = 0.0;
          res->e1345 = 0.0;
          res->e2345 = 0.0;
          res->e12345 = 0.0;
          break;
        case 10: //  e15
          res->e15 = 0.0;
          res->e125 = 0.0;
          res->e135 = 0.0;
          res->e145 = 0.0;
          res->e1235 = 0.0;
          res->e1245 = 0.0;
          res->e1345 = 0.0;
          res->e12345 = 0.0;
          break;
        case 11: //  e25
          res->e25 = 0.0;
          res->e125 = 0.0;
          res->e235 = 0.0;
          res->e245 = 0.0;
          res->e1235 = 0.0;
          res->e1245 = 0.0;
          res->e2345 = 0.0;
          res->e12345 = 0.0;
          break;
        case 12: //  e35
          res->e35 = 0.0;
          res->e135 = 0.0;
          res->e235 = 0.0;
          res->e345 = 0.0;
          res->e1235 = 0.0;
          res->e1345 = 0.0;
          res->e2345 = 0.0;
          res->e12345 = 0.0;
          break;
        case 13: //  e45
          res->e45 = 0.0;
          res->e145 = 0.0;
          res->e245 = 0.0;
          res->e345 = 0.0;
          res->e1245 = 0.0;
          res->e1345 = 0.0;
          res->e2345 = 0.0;
          res->e12345 = 0.0;
          break;
      }
      break;
    case 3:
      switch (idx){
        case 5: //  e123
          res->e123 = 0.0;
          res->e1234 = 0.0;
          res->e1235 = 0.0;
          res->e12345 = 0.0;
          break;
        case 11: //  e124
          res->e124 = 0.0;
          res->e1234 = 0.0;
          res->e1245 = 0.0;
          res->e12345 = 0.0;
          break;
        case 13: //  e134
          res->e134 = 0.0;
          res->e1234 = 0.0;
          res->e1345 = 0.0;
          res->e12345 = 0.0;
          break;
        case 14: //  e234
          res->e234 = 0.0;
          res->e1234 = 0.0;
          res->e2345 = 0.0;
          res->e12345 = 0.0;
          break;
        case 21: //  e125
          res->e125 = 0.0;
          res->e1235 = 0.0;
          res->e1245 = 0.0;
          res->e12345 = 0.0;
          break;
        case 23: //  e135
          res->e135 = 0.0;
          res->e1235 = 0.0;
          res->e1345 = 0.0;
          res->e12345 = 0.0;
          break;
        case 24: //  e235
          res->e235 = 0.0;
          res->e1235 = 0.0;
          res->e2345 = 0.0;
          res->e12345 = 0.0;
          break;
        case 26: //  e145
          res->e145 = 0.0;
          res->e1245 = 0.0;
          res->e1345 = 0.0;
          res->e12345 = 0.0;
          break;
        case 27: //  e245
          res->e245 = 0.0;
          res->e1245 = 0.0;
          res->e2345 = 0.0;
          res->e12345 = 0.0;
          break;
        case 28: //  e345
          res->e345 = 0.0;
          res->e1345 = 0.0;
          res->e2345 = 0.0;
          res->e12345 = 0.0;
          break;
      }
      break;
    case 4:
      switch (idx){
        case 20: //  e1234
          res->e1234 = 0.0;
          res->e12345 = 0.0;
          break;
        case 40: //  e1235
          res->e1235 = 0.0;
          res->e12345 = 0.0;
          break;
        case 46: //  e1245
          res->e1245 = 0.0;
          res->e12345 = 0.0;
          break;
        case 48: //  e1345
          res->e1345 = 0.0;
          res->e12345 = 0.0;
          break;
        case 49: //  e2345
          res->e2345 = 0.0;
          res->e12345 = 0.0;
          break;
      }
      break;
    case 5:
      switch (idx){
        case 76: //  e12345
          res->e12345 = 0.0;
          break;
      }
      break;
  }
}

void mdnum5_print(  mdnum5_t* lhs){

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
  //  Order 4;
  printf(" %+.8g*e1234",lhs->e1234);
  printf(" %+.8g*e1235",lhs->e1235);
  printf(" %+.8g*e1245",lhs->e1245);
  printf(" %+.8g*e1345",lhs->e1345);
  printf(" %+.8g*e2345",lhs->e2345);
  //  Order 5;
  printf(" %+.8g*e12345",lhs->e12345);
  printf("\n");

}

imdir_t mdnum5_get_indx(imdir_t idx, ord_t order){

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
      }
      break;
    case 5:
      switch (idx){
        case 0:
          return 76;
          break;
      }
      break;
      default:
          return 0;
  }
  return 0;
}

