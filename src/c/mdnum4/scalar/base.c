

// Not implemented correctly:
void mdnum4_set_im_o(mdnum4_t* num, imdir_t idx, ord_t order, mdnum4_t* res){
    mdnum4_set_item(num->r,idx,order,res);
}
void mdnum4_set_deriv_r(coeff_t num, imdir_t idx, ord_t order, mdnum4_t* res){
    *res=mdnum4_init();
}
void mdnum4_set_deriv_o(mdnum4_t* num, imdir_t idx, ord_t order, mdnum4_t* res){
    *res=mdnum4_init();
}
void mdnum4_extract_im_to( imdir_t idx, ord_t order, mdnum4_t* num, mdnum4_t* res){
    *res=mdnum4_init();
}
mdnum4_t mdnum4_extract_im(imdir_t idx, ord_t order, mdnum4_t* num){
    mdnum4_t res = mdnum4_init();
    return res;
}
mdnum4_t mdnum4_extract_deriv(imdir_t idx, ord_t order, mdnum4_t* num){
    mdnum4_t res = mdnum4_init();
    return res;
}
void mdnum4_extract_deriv_to(imdir_t idx, ord_t order, mdnum4_t* num, mdnum4_t* res){
	*res = mdnum4_init();
}
void mdnum4_get_im_to_o(imdir_t idx, ord_t order, mdnum4_t* num, mdnum4_t* res){
    coeff_t rres = mdnum4_get_item(idx, order, num);
    mdnum4_set_r(rres,res);
}
mdnum4_t mdnum4_get_im_o(imdir_t idx, ord_t order, mdnum4_t* num){
    coeff_t rres = mdnum4_get_item(idx, order, num);
    mdnum4_t res;
    mdnum4_set_r(rres,&res);
    return res;
}
void mdnum4_get_im_to_r(imdir_t idx, ord_t order, mdnum4_t* num, coeff_t* res){
    *res = mdnum4_get_item(idx, order, num);
}

inline ord_t mdnum4_get_order(mdnum4_t* lhs){

	return 4;

}

mdnum4_t mdnum4_get_deriv_o( imdir_t idx, ord_t order, mdnum4_t* num){

    mdnum4_t res = mdnum4_init();

    mdnum4_get_deriv_to( idx, order, num, &res);
    
    return res;

}

void mdnum4_get_deriv_to( imdir_t idx, ord_t order, mdnum4_t* num, mdnum4_t* res){

    coeff_t deriv = mdnum4_get_deriv(idx,order,num);

    mdnum4_set_r( deriv, res);

}

void mdnum4_set_im_r(coeff_t num, imdir_t idx, ord_t order, mdnum4_t* res){

    mdnum4_set_item(num, idx,order,res);

}

mdnum4_t mdnum4_init(void){

  mdnum4_t res;

  // Init function
  // Real;
  res.r = 0.0;
  // Order 1;
  res.e1 = 0.0;
  res.e2 = 0.0;
  res.e3 = 0.0;
  res.e4 = 0.0;
  // Order 2;
  res.e12 = 0.0;
  res.e13 = 0.0;
  res.e23 = 0.0;
  res.e14 = 0.0;
  res.e24 = 0.0;
  res.e34 = 0.0;
  // Order 3;
  res.e123 = 0.0;
  res.e124 = 0.0;
  res.e134 = 0.0;
  res.e234 = 0.0;
  // Order 4;
  res.e1234 = 0.0;

  return res;

}

ndir_t mdnum4_get_ndir_order(ord_t order, mdnum4_t* num){

  ndir_t res;

  switch(order){
    case 0:
      res = 1;
      break;
    case 1:
      res = 4;
      break;
    case 2:
      res = 6;
      break;
    case 3:
      res = 4;
      break;
    case 4:
      res = 1;
      break;
  }

  return res;

}

ndir_t mdnum4_get_ndir_total(mdnum4_t* num){

  ndir_t res;

  res = 15;

  return res;

}

mdnum4_t mdnum4_create_r(  coeff_t lhs){

  mdnum4_t res;

  // Assign like function 'lhs'
  // Real;
  res.r = lhs;
  // Order 1;
  res.e1 = 0.0;
  res.e2 = 0.0;
  res.e3 = 0.0;
  res.e4 = 0.0;
  // Order 2;
  res.e12 = 0.0;
  res.e13 = 0.0;
  res.e23 = 0.0;
  res.e14 = 0.0;
  res.e24 = 0.0;
  res.e34 = 0.0;
  // Order 3;
  res.e123 = 0.0;
  res.e124 = 0.0;
  res.e134 = 0.0;
  res.e234 = 0.0;
  // Order 4;
  res.e1234 = 0.0;

  return res;

}

void mdnum4_set_r(  coeff_t lhs, mdnum4_t* res){

  // Assign like function 'lhs'
  // Real;
  res->r = lhs;
  // Order 1;
  res->e1 = 0.0;
  res->e2 = 0.0;
  res->e3 = 0.0;
  res->e4 = 0.0;
  // Order 2;
  res->e12 = 0.0;
  res->e13 = 0.0;
  res->e23 = 0.0;
  res->e14 = 0.0;
  res->e24 = 0.0;
  res->e34 = 0.0;
  // Order 3;
  res->e123 = 0.0;
  res->e124 = 0.0;
  res->e134 = 0.0;
  res->e234 = 0.0;
  // Order 4;
  res->e1234 = 0.0;

}

void mdnum4_set_o(  mdnum4_t* lhs, mdnum4_t* res){

  // Assign like function 'lhs'
  // Real;
  res->r = lhs->r;
  // Order 1;
  res->e1 = lhs->e1;
  res->e2 = lhs->e2;
  res->e3 = lhs->e3;
  res->e4 = lhs->e4;
  // Order 2;
  res->e12 = lhs->e12;
  res->e13 = lhs->e13;
  res->e23 = lhs->e23;
  res->e14 = lhs->e14;
  res->e24 = lhs->e24;
  res->e34 = lhs->e34;
  // Order 3;
  res->e123 = lhs->e123;
  res->e124 = lhs->e124;
  res->e134 = lhs->e134;
  res->e234 = lhs->e234;
  // Order 4;
  res->e1234 = lhs->e1234;

}

mdnum4_t mdnum4_get_order_im(ord_t order, mdnum4_t* lhs){

  mdnum4_t res;

  res = mdnum4_init();
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
      break;
    case 2:
      // Order 2;
      res.e12 = lhs->e12;
      res.e13 = lhs->e13;
      res.e23 = lhs->e23;
      res.e14 = lhs->e14;
      res.e24 = lhs->e24;
      res.e34 = lhs->e34;
      break;
    case 3:
      // Order 3;
      res.e123 = lhs->e123;
      res.e124 = lhs->e124;
      res.e134 = lhs->e134;
      res.e234 = lhs->e234;
      break;
    case 4:
      // Order 4;
      res.e1234 = lhs->e1234;
      break;
  }

  return res;

}

void mdnum4_get_order_im_to(ord_t order, mdnum4_t* lhs, mdnum4_t* res){


  *res = mdnum4_init();
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
      break;
    case 2:
      // Order 2;
      res->e12 = lhs->e12;
      res->e13 = lhs->e13;
      res->e23 = lhs->e23;
      res->e14 = lhs->e14;
      res->e24 = lhs->e24;
      res->e34 = lhs->e34;
      break;
    case 3:
      // Order 3;
      res->e123 = lhs->e123;
      res->e124 = lhs->e124;
      res->e134 = lhs->e134;
      res->e234 = lhs->e234;
      break;
    case 4:
      // Order 4;
      res->e1234 = lhs->e1234;
      break;
  }

}

coeff_t mdnum4_get_item(imdir_t idx, ord_t order, mdnum4_t* lhs){

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
      }
      break;
    case 4:
      switch (idx){
        case 20:
          res = lhs->e1234;
          break;
      }
      break;
  }
  return res;

}

coeff_t mdnum4_get_deriv(imdir_t idx, ord_t order, mdnum4_t* lhs){

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
      }
      break;
    case 4:
      switch (idx){
        case 20:
          factor = 1.0000000000000000e+00;
          res = lhs->e1234*factor;
          break;
      }
      break;
  }
  return res;

}

void mdnum4_set_item(coeff_t val, imdir_t idx, ord_t order, mdnum4_t* x){

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
      }
      break;
    case 4:
      switch (idx){
        case 20:
          x->e1234 = val;
          break;
      }
      break;
  }
}

mdnum4_t mdnum4_copy(  mdnum4_t* lhs){

  mdnum4_t res;

  // Assign like function 'lhs'
  // Real;
  res.r = lhs->r;
  // Order 1;
  res.e1 = lhs->e1;
  res.e2 = lhs->e2;
  res.e3 = lhs->e3;
  res.e4 = lhs->e4;
  // Order 2;
  res.e12 = lhs->e12;
  res.e13 = lhs->e13;
  res.e23 = lhs->e23;
  res.e14 = lhs->e14;
  res.e24 = lhs->e24;
  res.e34 = lhs->e34;
  // Order 3;
  res.e123 = lhs->e123;
  res.e124 = lhs->e124;
  res.e134 = lhs->e134;
  res.e234 = lhs->e234;
  // Order 4;
  res.e1234 = lhs->e1234;

  return res;

}

void mdnum4_copy_to(  mdnum4_t* lhs, mdnum4_t* res){

  // Assign like function 'lhs'
  // Real;
  res->r = lhs->r;
  // Order 1;
  res->e1 = lhs->e1;
  res->e2 = lhs->e2;
  res->e3 = lhs->e3;
  res->e4 = lhs->e4;
  // Order 2;
  res->e12 = lhs->e12;
  res->e13 = lhs->e13;
  res->e23 = lhs->e23;
  res->e14 = lhs->e14;
  res->e24 = lhs->e24;
  res->e34 = lhs->e34;
  // Order 3;
  res->e123 = lhs->e123;
  res->e124 = lhs->e124;
  res->e134 = lhs->e134;
  res->e234 = lhs->e234;
  // Order 4;
  res->e1234 = lhs->e1234;

}

mdnum4_t mdnum4_taylor_integrate(coeff_t* deltas,mdnum4_t* lhs){

  mdnum4_t res;

  coeff_t factor;
  // Taylor integration
  // Real;
  res.r = lhs->r;
  // Order 1;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0);
  res.e1 = factor*lhs->e1;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],0);
  res.e2 = factor*lhs->e2;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],0);
  res.e3 = factor*lhs->e3;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],1);
  res.e4 = factor*lhs->e4;
  // Order 2;
  factor = pow(deltas[0],1)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],0);
  res.e12 = factor*lhs->e12;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],0);
  res.e13 = factor*lhs->e13;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],1)*pow(deltas[3],0);
  res.e23 = factor*lhs->e23;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],1);
  res.e14 = factor*lhs->e14;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],1);
  res.e24 = factor*lhs->e24;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],1);
  res.e34 = factor*lhs->e34;
  // Order 3;
  factor = pow(deltas[0],1)*pow(deltas[1],1)*pow(deltas[2],1)*pow(deltas[3],0);
  res.e123 = factor*lhs->e123;
  factor = pow(deltas[0],1)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],1);
  res.e124 = factor*lhs->e124;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],1);
  res.e134 = factor*lhs->e134;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],1)*pow(deltas[3],1);
  res.e234 = factor*lhs->e234;
  // Order 4;
  factor = pow(deltas[0],1)*pow(deltas[1],1)*pow(deltas[2],1)*pow(deltas[3],1);
  res.e1234 = factor*lhs->e1234;

  return res;

}

void mdnum4_taylor_integrate_to(coeff_t* deltas,mdnum4_t* lhs, mdnum4_t* res){

  coeff_t factor;
  // Taylor integration
  // Real;
  res->r = lhs->r;
  // Order 1;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0);
  res->e1 = factor*lhs->e1;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],0);
  res->e2 = factor*lhs->e2;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],0);
  res->e3 = factor*lhs->e3;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],1);
  res->e4 = factor*lhs->e4;
  // Order 2;
  factor = pow(deltas[0],1)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],0);
  res->e12 = factor*lhs->e12;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],0);
  res->e13 = factor*lhs->e13;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],1)*pow(deltas[3],0);
  res->e23 = factor*lhs->e23;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],1);
  res->e14 = factor*lhs->e14;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],1);
  res->e24 = factor*lhs->e24;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],1);
  res->e34 = factor*lhs->e34;
  // Order 3;
  factor = pow(deltas[0],1)*pow(deltas[1],1)*pow(deltas[2],1)*pow(deltas[3],0);
  res->e123 = factor*lhs->e123;
  factor = pow(deltas[0],1)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],1);
  res->e124 = factor*lhs->e124;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],1);
  res->e134 = factor*lhs->e134;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],1)*pow(deltas[3],1);
  res->e234 = factor*lhs->e234;
  // Order 4;
  factor = pow(deltas[0],1)*pow(deltas[1],1)*pow(deltas[2],1)*pow(deltas[3],1);
  res->e1234 = factor*lhs->e1234;

}

mdnum4_t mdnum4_truncate_im(imdir_t idx, ord_t order, mdnum4_t* lhs){

  mdnum4_t res;

  // Copy number.
  res = (*lhs);
  // Truncate all other values when necessary.
  // Real;
  switch (order){
    case 0:
      res = mdnum4_init();
      break;
    case 1:
      switch (idx){
        case 0: //  e1
          res.e1 = 0.0;
          res.e12 = 0.0;
          res.e13 = 0.0;
          res.e14 = 0.0;
          res.e123 = 0.0;
          res.e124 = 0.0;
          res.e134 = 0.0;
          res.e1234 = 0.0;
          break;
        case 1: //  e2
          res.e2 = 0.0;
          res.e12 = 0.0;
          res.e23 = 0.0;
          res.e24 = 0.0;
          res.e123 = 0.0;
          res.e124 = 0.0;
          res.e234 = 0.0;
          res.e1234 = 0.0;
          break;
        case 2: //  e3
          res.e3 = 0.0;
          res.e13 = 0.0;
          res.e23 = 0.0;
          res.e34 = 0.0;
          res.e123 = 0.0;
          res.e134 = 0.0;
          res.e234 = 0.0;
          res.e1234 = 0.0;
          break;
        case 3: //  e4
          res.e4 = 0.0;
          res.e14 = 0.0;
          res.e24 = 0.0;
          res.e34 = 0.0;
          res.e124 = 0.0;
          res.e134 = 0.0;
          res.e234 = 0.0;
          res.e1234 = 0.0;
          break;
      }
      break;
    case 2:
      switch (idx){
        case 1: //  e12
          res.e12 = 0.0;
          res.e123 = 0.0;
          res.e124 = 0.0;
          res.e1234 = 0.0;
          break;
        case 3: //  e13
          res.e13 = 0.0;
          res.e123 = 0.0;
          res.e134 = 0.0;
          res.e1234 = 0.0;
          break;
        case 4: //  e23
          res.e23 = 0.0;
          res.e123 = 0.0;
          res.e234 = 0.0;
          res.e1234 = 0.0;
          break;
        case 6: //  e14
          res.e14 = 0.0;
          res.e124 = 0.0;
          res.e134 = 0.0;
          res.e1234 = 0.0;
          break;
        case 7: //  e24
          res.e24 = 0.0;
          res.e124 = 0.0;
          res.e234 = 0.0;
          res.e1234 = 0.0;
          break;
        case 8: //  e34
          res.e34 = 0.0;
          res.e134 = 0.0;
          res.e234 = 0.0;
          res.e1234 = 0.0;
          break;
      }
      break;
    case 3:
      switch (idx){
        case 5: //  e123
          res.e123 = 0.0;
          res.e1234 = 0.0;
          break;
        case 11: //  e124
          res.e124 = 0.0;
          res.e1234 = 0.0;
          break;
        case 13: //  e134
          res.e134 = 0.0;
          res.e1234 = 0.0;
          break;
        case 14: //  e234
          res.e234 = 0.0;
          res.e1234 = 0.0;
          break;
      }
      break;
    case 4:
      switch (idx){
        case 20: //  e1234
          res.e1234 = 0.0;
          break;
      }
      break;
  }
  return res;

}

void mdnum4_truncate_im_to(imdir_t idx, ord_t order, mdnum4_t* lhs, mdnum4_t* res){

  // Copy number.
  *res = (*lhs);
  // Truncate all other values when necessary.
  // Real;
  switch (order){
    case 0:
      *res = mdnum4_init();
      break;
    case 1:
      switch (idx){
        case 0: //  e1
          res->e1 = 0.0;
          res->e12 = 0.0;
          res->e13 = 0.0;
          res->e14 = 0.0;
          res->e123 = 0.0;
          res->e124 = 0.0;
          res->e134 = 0.0;
          res->e1234 = 0.0;
          break;
        case 1: //  e2
          res->e2 = 0.0;
          res->e12 = 0.0;
          res->e23 = 0.0;
          res->e24 = 0.0;
          res->e123 = 0.0;
          res->e124 = 0.0;
          res->e234 = 0.0;
          res->e1234 = 0.0;
          break;
        case 2: //  e3
          res->e3 = 0.0;
          res->e13 = 0.0;
          res->e23 = 0.0;
          res->e34 = 0.0;
          res->e123 = 0.0;
          res->e134 = 0.0;
          res->e234 = 0.0;
          res->e1234 = 0.0;
          break;
        case 3: //  e4
          res->e4 = 0.0;
          res->e14 = 0.0;
          res->e24 = 0.0;
          res->e34 = 0.0;
          res->e124 = 0.0;
          res->e134 = 0.0;
          res->e234 = 0.0;
          res->e1234 = 0.0;
          break;
      }
      break;
    case 2:
      switch (idx){
        case 1: //  e12
          res->e12 = 0.0;
          res->e123 = 0.0;
          res->e124 = 0.0;
          res->e1234 = 0.0;
          break;
        case 3: //  e13
          res->e13 = 0.0;
          res->e123 = 0.0;
          res->e134 = 0.0;
          res->e1234 = 0.0;
          break;
        case 4: //  e23
          res->e23 = 0.0;
          res->e123 = 0.0;
          res->e234 = 0.0;
          res->e1234 = 0.0;
          break;
        case 6: //  e14
          res->e14 = 0.0;
          res->e124 = 0.0;
          res->e134 = 0.0;
          res->e1234 = 0.0;
          break;
        case 7: //  e24
          res->e24 = 0.0;
          res->e124 = 0.0;
          res->e234 = 0.0;
          res->e1234 = 0.0;
          break;
        case 8: //  e34
          res->e34 = 0.0;
          res->e134 = 0.0;
          res->e234 = 0.0;
          res->e1234 = 0.0;
          break;
      }
      break;
    case 3:
      switch (idx){
        case 5: //  e123
          res->e123 = 0.0;
          res->e1234 = 0.0;
          break;
        case 11: //  e124
          res->e124 = 0.0;
          res->e1234 = 0.0;
          break;
        case 13: //  e134
          res->e134 = 0.0;
          res->e1234 = 0.0;
          break;
        case 14: //  e234
          res->e234 = 0.0;
          res->e1234 = 0.0;
          break;
      }
      break;
    case 4:
      switch (idx){
        case 20: //  e1234
          res->e1234 = 0.0;
          break;
      }
      break;
  }
}

void mdnum4_print(  mdnum4_t* lhs){

  // Print function.
  //  Real;
  printf("%.8g",lhs->r);
  //  Order 1;
  printf(" %+.8g*e1",lhs->e1);
  printf(" %+.8g*e2",lhs->e2);
  printf(" %+.8g*e3",lhs->e3);
  printf(" %+.8g*e4",lhs->e4);
  //  Order 2;
  printf(" %+.8g*e12",lhs->e12);
  printf(" %+.8g*e13",lhs->e13);
  printf(" %+.8g*e23",lhs->e23);
  printf(" %+.8g*e14",lhs->e14);
  printf(" %+.8g*e24",lhs->e24);
  printf(" %+.8g*e34",lhs->e34);
  //  Order 3;
  printf(" %+.8g*e123",lhs->e123);
  printf(" %+.8g*e124",lhs->e124);
  printf(" %+.8g*e134",lhs->e134);
  printf(" %+.8g*e234",lhs->e234);
  //  Order 4;
  printf(" %+.8g*e1234",lhs->e1234);
  printf("\n");

}

imdir_t mdnum4_get_indx(imdir_t idx, ord_t order){

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
      }
      break;
    case 4:
      switch (idx){
        case 0:
          return 20;
          break;
      }
      break;
      default:
          return 0;
  }
  return 0;
}

