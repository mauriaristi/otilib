inline ord_t onumm2n5_get_order(onumm2n5_t* lhs){

	return 5;

}

onumm2n5_t onumm2n5_get_deriv_o( imdir_t idx, ord_t order, onumm2n5_t* num){

    onumm2n5_t res = onumm2n5_init();
    
    onumm2n5_get_deriv_to( idx, order, num, &res);
    
    return res;

}

void onumm2n5_get_deriv_to( imdir_t idx, ord_t order, onumm2n5_t* num, onumm2n5_t* res){

    coeff_t deriv = onumm2n5_get_deriv(idx,order,num);

    onumm2n5_set_r( deriv, res);

}
// ----------------------------------------------------------------------------------------------------

onumm2n5_t onumm2n5_init(){

  onumm2n5_t res;

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
  // Order 4;
  res.e1111 = 0.0;
  res.e1112 = 0.0;
  res.e1122 = 0.0;
  res.e1222 = 0.0;
  res.e2222 = 0.0;
  // Order 5;
  res.e11111 = 0.0;
  res.e11112 = 0.0;
  res.e11122 = 0.0;
  res.e11222 = 0.0;
  res.e12222 = 0.0;
  res.e22222 = 0.0;

  return res;

}

onumm2n5_t onumm2n5_create_r(  coeff_t lhs){

  onumm2n5_t res;

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
  // Order 4;
  res.e1111 = 0.0;
  res.e1112 = 0.0;
  res.e1122 = 0.0;
  res.e1222 = 0.0;
  res.e2222 = 0.0;
  // Order 5;
  res.e11111 = 0.0;
  res.e11112 = 0.0;
  res.e11122 = 0.0;
  res.e11222 = 0.0;
  res.e12222 = 0.0;
  res.e22222 = 0.0;

  return res;

}

void onumm2n5_set_r(  coeff_t lhs, onumm2n5_t* res){

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
  // Order 4;
  res->e1111 = 0.0;
  res->e1112 = 0.0;
  res->e1122 = 0.0;
  res->e1222 = 0.0;
  res->e2222 = 0.0;
  // Order 5;
  res->e11111 = 0.0;
  res->e11112 = 0.0;
  res->e11122 = 0.0;
  res->e11222 = 0.0;
  res->e12222 = 0.0;
  res->e22222 = 0.0;

}

void onumm2n5_set_o(  onumm2n5_t* lhs, onumm2n5_t* res){

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
  // Order 4;
  res->e1111 = lhs->e1111;
  res->e1112 = lhs->e1112;
  res->e1122 = lhs->e1122;
  res->e1222 = lhs->e1222;
  res->e2222 = lhs->e2222;
  // Order 5;
  res->e11111 = lhs->e11111;
  res->e11112 = lhs->e11112;
  res->e11122 = lhs->e11122;
  res->e11222 = lhs->e11222;
  res->e12222 = lhs->e12222;
  res->e22222 = lhs->e22222;

}

onumm2n5_t onumm2n5_get_order_im(ord_t order, onumm2n5_t* lhs){

  onumm2n5_t res;

  res = onumm2n5_init();
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
    case 4:
      // Order 4;
      res.e1111 = lhs->e1111;
      res.e1112 = lhs->e1112;
      res.e1122 = lhs->e1122;
      res.e1222 = lhs->e1222;
      res.e2222 = lhs->e2222;
      break;
    case 5:
      // Order 5;
      res.e11111 = lhs->e11111;
      res.e11112 = lhs->e11112;
      res.e11122 = lhs->e11122;
      res.e11222 = lhs->e11222;
      res.e12222 = lhs->e12222;
      res.e22222 = lhs->e22222;
      break;
  }

  return res;

}

void onumm2n5_get_order_im_to(ord_t order, onumm2n5_t* lhs, onumm2n5_t* res){


  *res = onumm2n5_init();
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
    case 4:
      // Order 4;
      res->e1111 = lhs->e1111;
      res->e1112 = lhs->e1112;
      res->e1122 = lhs->e1122;
      res->e1222 = lhs->e1222;
      res->e2222 = lhs->e2222;
      break;
    case 5:
      // Order 5;
      res->e11111 = lhs->e11111;
      res->e11112 = lhs->e11112;
      res->e11122 = lhs->e11122;
      res->e11222 = lhs->e11222;
      res->e12222 = lhs->e12222;
      res->e22222 = lhs->e22222;
      break;
  }

}

coeff_t onumm2n5_get_item(imdir_t idx, ord_t order, onumm2n5_t* lhs){

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
      }
      break;
    case 5:
      switch (idx){
        case 0:
          res = lhs->e11111;
          break;
        case 1:
          res = lhs->e11112;
          break;
        case 2:
          res = lhs->e11122;
          break;
        case 3:
          res = lhs->e11222;
          break;
        case 4:
          res = lhs->e12222;
          break;
        case 5:
          res = lhs->e22222;
          break;
      }
      break;
  }
  return res;

}

coeff_t onumm2n5_get_deriv(imdir_t idx, ord_t order, onumm2n5_t* lhs){

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
      }
      break;
    case 5:
      switch (idx){
        case 0:
          factor = 1.2000000000000000e+02;
          res = lhs->e11111*factor;
          break;
        case 1:
          factor = 2.4000000000000000e+01;
          res = lhs->e11112*factor;
          break;
        case 2:
          factor = 1.2000000000000000e+01;
          res = lhs->e11122*factor;
          break;
        case 3:
          factor = 1.2000000000000000e+01;
          res = lhs->e11222*factor;
          break;
        case 4:
          factor = 2.4000000000000000e+01;
          res = lhs->e12222*factor;
          break;
        case 5:
          factor = 1.2000000000000000e+02;
          res = lhs->e22222*factor;
          break;
      }
      break;
  }
  return res;

}

void onumm2n5_set_item(coeff_t val, imdir_t idx, ord_t order, onumm2n5_t* x){

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
      }
      break;
    case 5:
      switch (idx){
        case 0:
          x->e11111 = val;
          break;
        case 1:
          x->e11112 = val;
          break;
        case 2:
          x->e11122 = val;
          break;
        case 3:
          x->e11222 = val;
          break;
        case 4:
          x->e12222 = val;
          break;
        case 5:
          x->e22222 = val;
          break;
      }
      break;
  }
}

onumm2n5_t onumm2n5_copy(  onumm2n5_t* lhs){

  onumm2n5_t res;

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
  // Order 4;
  res.e1111 = lhs->e1111;
  res.e1112 = lhs->e1112;
  res.e1122 = lhs->e1122;
  res.e1222 = lhs->e1222;
  res.e2222 = lhs->e2222;
  // Order 5;
  res.e11111 = lhs->e11111;
  res.e11112 = lhs->e11112;
  res.e11122 = lhs->e11122;
  res.e11222 = lhs->e11222;
  res.e12222 = lhs->e12222;
  res.e22222 = lhs->e22222;

  return res;

}

void onumm2n5_copy_to(  onumm2n5_t* lhs, onumm2n5_t* res){

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
  // Order 4;
  res->e1111 = lhs->e1111;
  res->e1112 = lhs->e1112;
  res->e1122 = lhs->e1122;
  res->e1222 = lhs->e1222;
  res->e2222 = lhs->e2222;
  // Order 5;
  res->e11111 = lhs->e11111;
  res->e11112 = lhs->e11112;
  res->e11122 = lhs->e11122;
  res->e11222 = lhs->e11222;
  res->e12222 = lhs->e12222;
  res->e22222 = lhs->e22222;

}

onumm2n5_t onumm2n5_taylor_integrate(coeff_t* deltas,onumm2n5_t* lhs){

  onumm2n5_t res;

  coeff_t factor;
  // Taylor integration
  // Real;
  res.r = lhs->r;
  // Order 1;
  factor = pow(deltas[0],1)*pow(deltas[1],0);
  res.e1 = factor*lhs->e1;
  factor = pow(deltas[0],0)*pow(deltas[1],1);
  res.e2 = factor*lhs->e2;
  // Order 2;
  factor = pow(deltas[0],2)*pow(deltas[1],0);
  res.e11 = factor*lhs->e11;
  factor = pow(deltas[0],1)*pow(deltas[1],1);
  res.e12 = factor*lhs->e12;
  factor = pow(deltas[0],0)*pow(deltas[1],2);
  res.e22 = factor*lhs->e22;
  // Order 3;
  factor = pow(deltas[0],3)*pow(deltas[1],0);
  res.e111 = factor*lhs->e111;
  factor = pow(deltas[0],2)*pow(deltas[1],1);
  res.e112 = factor*lhs->e112;
  factor = pow(deltas[0],1)*pow(deltas[1],2);
  res.e122 = factor*lhs->e122;
  factor = pow(deltas[0],0)*pow(deltas[1],3);
  res.e222 = factor*lhs->e222;
  // Order 4;
  factor = pow(deltas[0],4)*pow(deltas[1],0);
  res.e1111 = factor*lhs->e1111;
  factor = pow(deltas[0],3)*pow(deltas[1],1);
  res.e1112 = factor*lhs->e1112;
  factor = pow(deltas[0],2)*pow(deltas[1],2);
  res.e1122 = factor*lhs->e1122;
  factor = pow(deltas[0],1)*pow(deltas[1],3);
  res.e1222 = factor*lhs->e1222;
  factor = pow(deltas[0],0)*pow(deltas[1],4);
  res.e2222 = factor*lhs->e2222;
  // Order 5;
  factor = pow(deltas[0],5)*pow(deltas[1],0);
  res.e11111 = factor*lhs->e11111;
  factor = pow(deltas[0],4)*pow(deltas[1],1);
  res.e11112 = factor*lhs->e11112;
  factor = pow(deltas[0],3)*pow(deltas[1],2);
  res.e11122 = factor*lhs->e11122;
  factor = pow(deltas[0],2)*pow(deltas[1],3);
  res.e11222 = factor*lhs->e11222;
  factor = pow(deltas[0],1)*pow(deltas[1],4);
  res.e12222 = factor*lhs->e12222;
  factor = pow(deltas[0],0)*pow(deltas[1],5);
  res.e22222 = factor*lhs->e22222;

  return res;

}

void onumm2n5_taylor_integrate_to(coeff_t* deltas,onumm2n5_t* lhs, onumm2n5_t* res){

  coeff_t factor;
  // Taylor integration
  // Real;
  res->r = lhs->r;
  // Order 1;
  factor = pow(deltas[0],1)*pow(deltas[1],0);
  res->e1 = factor*lhs->e1;
  factor = pow(deltas[0],0)*pow(deltas[1],1);
  res->e2 = factor*lhs->e2;
  // Order 2;
  factor = pow(deltas[0],2)*pow(deltas[1],0);
  res->e11 = factor*lhs->e11;
  factor = pow(deltas[0],1)*pow(deltas[1],1);
  res->e12 = factor*lhs->e12;
  factor = pow(deltas[0],0)*pow(deltas[1],2);
  res->e22 = factor*lhs->e22;
  // Order 3;
  factor = pow(deltas[0],3)*pow(deltas[1],0);
  res->e111 = factor*lhs->e111;
  factor = pow(deltas[0],2)*pow(deltas[1],1);
  res->e112 = factor*lhs->e112;
  factor = pow(deltas[0],1)*pow(deltas[1],2);
  res->e122 = factor*lhs->e122;
  factor = pow(deltas[0],0)*pow(deltas[1],3);
  res->e222 = factor*lhs->e222;
  // Order 4;
  factor = pow(deltas[0],4)*pow(deltas[1],0);
  res->e1111 = factor*lhs->e1111;
  factor = pow(deltas[0],3)*pow(deltas[1],1);
  res->e1112 = factor*lhs->e1112;
  factor = pow(deltas[0],2)*pow(deltas[1],2);
  res->e1122 = factor*lhs->e1122;
  factor = pow(deltas[0],1)*pow(deltas[1],3);
  res->e1222 = factor*lhs->e1222;
  factor = pow(deltas[0],0)*pow(deltas[1],4);
  res->e2222 = factor*lhs->e2222;
  // Order 5;
  factor = pow(deltas[0],5)*pow(deltas[1],0);
  res->e11111 = factor*lhs->e11111;
  factor = pow(deltas[0],4)*pow(deltas[1],1);
  res->e11112 = factor*lhs->e11112;
  factor = pow(deltas[0],3)*pow(deltas[1],2);
  res->e11122 = factor*lhs->e11122;
  factor = pow(deltas[0],2)*pow(deltas[1],3);
  res->e11222 = factor*lhs->e11222;
  factor = pow(deltas[0],1)*pow(deltas[1],4);
  res->e12222 = factor*lhs->e12222;
  factor = pow(deltas[0],0)*pow(deltas[1],5);
  res->e22222 = factor*lhs->e22222;

}

onumm2n5_t onumm2n5_truncate_im(imdir_t idx, ord_t order, onumm2n5_t* lhs){

  onumm2n5_t res;

  // Copy number.
  res = (*lhs);
  // Truncate all other values when necessary.
  // Real;
  switch (order){
    case 0:
      res = onumm2n5_init();
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
          res.e1111 = 0.0;
          res.e1112 = 0.0;
          res.e1122 = 0.0;
          res.e1222 = 0.0;
          res.e11111 = 0.0;
          res.e11112 = 0.0;
          res.e11122 = 0.0;
          res.e11222 = 0.0;
          res.e12222 = 0.0;
          break;
        case 1: //  e2
          res.e2 = 0.0;
          res.e12 = 0.0;
          res.e22 = 0.0;
          res.e112 = 0.0;
          res.e122 = 0.0;
          res.e222 = 0.0;
          res.e1112 = 0.0;
          res.e1122 = 0.0;
          res.e1222 = 0.0;
          res.e2222 = 0.0;
          res.e11112 = 0.0;
          res.e11122 = 0.0;
          res.e11222 = 0.0;
          res.e12222 = 0.0;
          res.e22222 = 0.0;
          break;
      }
      break;
    case 2:
      switch (idx){
        case 0: //  e11
          res.e11 = 0.0;
          res.e111 = 0.0;
          res.e112 = 0.0;
          res.e1111 = 0.0;
          res.e1112 = 0.0;
          res.e1122 = 0.0;
          res.e11111 = 0.0;
          res.e11112 = 0.0;
          res.e11122 = 0.0;
          res.e11222 = 0.0;
          break;
        case 1: //  e12
          res.e12 = 0.0;
          res.e112 = 0.0;
          res.e122 = 0.0;
          res.e1112 = 0.0;
          res.e1122 = 0.0;
          res.e1222 = 0.0;
          res.e11112 = 0.0;
          res.e11122 = 0.0;
          res.e11222 = 0.0;
          res.e12222 = 0.0;
          break;
        case 2: //  e22
          res.e22 = 0.0;
          res.e122 = 0.0;
          res.e222 = 0.0;
          res.e1122 = 0.0;
          res.e1222 = 0.0;
          res.e2222 = 0.0;
          res.e11122 = 0.0;
          res.e11222 = 0.0;
          res.e12222 = 0.0;
          res.e22222 = 0.0;
          break;
      }
      break;
    case 3:
      switch (idx){
        case 0: //  e111
          res.e111 = 0.0;
          res.e1111 = 0.0;
          res.e1112 = 0.0;
          res.e11111 = 0.0;
          res.e11112 = 0.0;
          res.e11122 = 0.0;
          break;
        case 1: //  e112
          res.e112 = 0.0;
          res.e1112 = 0.0;
          res.e1122 = 0.0;
          res.e11112 = 0.0;
          res.e11122 = 0.0;
          res.e11222 = 0.0;
          break;
        case 2: //  e122
          res.e122 = 0.0;
          res.e1122 = 0.0;
          res.e1222 = 0.0;
          res.e11122 = 0.0;
          res.e11222 = 0.0;
          res.e12222 = 0.0;
          break;
        case 3: //  e222
          res.e222 = 0.0;
          res.e1222 = 0.0;
          res.e2222 = 0.0;
          res.e11222 = 0.0;
          res.e12222 = 0.0;
          res.e22222 = 0.0;
          break;
      }
      break;
    case 4:
      switch (idx){
        case 0: //  e1111
          res.e1111 = 0.0;
          res.e11111 = 0.0;
          res.e11112 = 0.0;
          break;
        case 1: //  e1112
          res.e1112 = 0.0;
          res.e11112 = 0.0;
          res.e11122 = 0.0;
          break;
        case 2: //  e1122
          res.e1122 = 0.0;
          res.e11122 = 0.0;
          res.e11222 = 0.0;
          break;
        case 3: //  e1222
          res.e1222 = 0.0;
          res.e11222 = 0.0;
          res.e12222 = 0.0;
          break;
        case 4: //  e2222
          res.e2222 = 0.0;
          res.e12222 = 0.0;
          res.e22222 = 0.0;
          break;
      }
      break;
    case 5:
      switch (idx){
        case 0: //  e11111
          res.e11111 = 0.0;
          break;
        case 1: //  e11112
          res.e11112 = 0.0;
          break;
        case 2: //  e11122
          res.e11122 = 0.0;
          break;
        case 3: //  e11222
          res.e11222 = 0.0;
          break;
        case 4: //  e12222
          res.e12222 = 0.0;
          break;
        case 5: //  e22222
          res.e22222 = 0.0;
          break;
      }
      break;
  }
  return res;

}

void onumm2n5_truncate_im_to(imdir_t idx, ord_t order, onumm2n5_t* lhs, onumm2n5_t* res){

  // Copy number.
  res = (*lhs);
  // Truncate all other values when necessary.
  // Real;
  switch (order){
    case 0:
      res = onumm2n5_init();
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
          res.e1111 = 0.0;
          res.e1112 = 0.0;
          res.e1122 = 0.0;
          res.e1222 = 0.0;
          res.e11111 = 0.0;
          res.e11112 = 0.0;
          res.e11122 = 0.0;
          res.e11222 = 0.0;
          res.e12222 = 0.0;
          break;
        case 1: //  e2
          res.e2 = 0.0;
          res.e12 = 0.0;
          res.e22 = 0.0;
          res.e112 = 0.0;
          res.e122 = 0.0;
          res.e222 = 0.0;
          res.e1112 = 0.0;
          res.e1122 = 0.0;
          res.e1222 = 0.0;
          res.e2222 = 0.0;
          res.e11112 = 0.0;
          res.e11122 = 0.0;
          res.e11222 = 0.0;
          res.e12222 = 0.0;
          res.e22222 = 0.0;
          break;
      }
      break;
    case 2:
      switch (idx){
        case 0: //  e11
          res.e11 = 0.0;
          res.e111 = 0.0;
          res.e112 = 0.0;
          res.e1111 = 0.0;
          res.e1112 = 0.0;
          res.e1122 = 0.0;
          res.e11111 = 0.0;
          res.e11112 = 0.0;
          res.e11122 = 0.0;
          res.e11222 = 0.0;
          break;
        case 1: //  e12
          res.e12 = 0.0;
          res.e112 = 0.0;
          res.e122 = 0.0;
          res.e1112 = 0.0;
          res.e1122 = 0.0;
          res.e1222 = 0.0;
          res.e11112 = 0.0;
          res.e11122 = 0.0;
          res.e11222 = 0.0;
          res.e12222 = 0.0;
          break;
        case 2: //  e22
          res.e22 = 0.0;
          res.e122 = 0.0;
          res.e222 = 0.0;
          res.e1122 = 0.0;
          res.e1222 = 0.0;
          res.e2222 = 0.0;
          res.e11122 = 0.0;
          res.e11222 = 0.0;
          res.e12222 = 0.0;
          res.e22222 = 0.0;
          break;
      }
      break;
    case 3:
      switch (idx){
        case 0: //  e111
          res.e111 = 0.0;
          res.e1111 = 0.0;
          res.e1112 = 0.0;
          res.e11111 = 0.0;
          res.e11112 = 0.0;
          res.e11122 = 0.0;
          break;
        case 1: //  e112
          res.e112 = 0.0;
          res.e1112 = 0.0;
          res.e1122 = 0.0;
          res.e11112 = 0.0;
          res.e11122 = 0.0;
          res.e11222 = 0.0;
          break;
        case 2: //  e122
          res.e122 = 0.0;
          res.e1122 = 0.0;
          res.e1222 = 0.0;
          res.e11122 = 0.0;
          res.e11222 = 0.0;
          res.e12222 = 0.0;
          break;
        case 3: //  e222
          res.e222 = 0.0;
          res.e1222 = 0.0;
          res.e2222 = 0.0;
          res.e11222 = 0.0;
          res.e12222 = 0.0;
          res.e22222 = 0.0;
          break;
      }
      break;
    case 4:
      switch (idx){
        case 0: //  e1111
          res.e1111 = 0.0;
          res.e11111 = 0.0;
          res.e11112 = 0.0;
          break;
        case 1: //  e1112
          res.e1112 = 0.0;
          res.e11112 = 0.0;
          res.e11122 = 0.0;
          break;
        case 2: //  e1122
          res.e1122 = 0.0;
          res.e11122 = 0.0;
          res.e11222 = 0.0;
          break;
        case 3: //  e1222
          res.e1222 = 0.0;
          res.e11222 = 0.0;
          res.e12222 = 0.0;
          break;
        case 4: //  e2222
          res.e2222 = 0.0;
          res.e12222 = 0.0;
          res.e22222 = 0.0;
          break;
      }
      break;
    case 5:
      switch (idx){
        case 0: //  e11111
          res.e11111 = 0.0;
          break;
        case 1: //  e11112
          res.e11112 = 0.0;
          break;
        case 2: //  e11122
          res.e11122 = 0.0;
          break;
        case 3: //  e11222
          res.e11222 = 0.0;
          break;
        case 4: //  e12222
          res.e12222 = 0.0;
          break;
        case 5: //  e22222
          res.e22222 = 0.0;
          break;
      }
      break;
  }
}

void onumm2n5_print(  onumm2n5_t* lhs){

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
  //  Order 4;
  printf(" %+.8g*e1111",lhs->e1111);
  printf(" %+.8g*e1112",lhs->e1112);
  printf(" %+.8g*e1122",lhs->e1122);
  printf(" %+.8g*e1222",lhs->e1222);
  printf(" %+.8g*e2222",lhs->e2222);
  //  Order 5;
  printf(" %+.8g*e11111",lhs->e11111);
  printf(" %+.8g*e11112",lhs->e11112);
  printf(" %+.8g*e11122",lhs->e11122);
  printf(" %+.8g*e11222",lhs->e11222);
  printf(" %+.8g*e12222",lhs->e12222);
  printf(" %+.8g*e22222",lhs->e22222);
  printf("\n");

}

