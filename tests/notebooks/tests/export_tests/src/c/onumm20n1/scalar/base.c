

// Not implemented correctly:
void onumm20n1_set_im_o(onumm20n1_t* num, imdir_t idx, ord_t order, onumm20n1_t* res){
    *res=onumm20n1_init();
}
void onumm20n1_extract_im_to( imdir_t idx, ord_t order, onumm20n1_t* num, onumm20n1_t* res){
    *res=onumm20n1_init();
}
onumm20n1_t onumm20n1_extract_im(imdir_t idx, ord_t order, onumm20n1_t* num){
    onumm20n1_t res = onumm20n1_init();
    return res;
}
onumm20n1_t onumm20n1_extract_deriv(imdir_t idx, ord_t order, onumm20n1_t* num){
    onumm20n1_t res = onumm20n1_init();
    return res;
}
void onumm20n1_extract_deriv_to(imdir_t idx, ord_t order, onumm20n1_t* num, onumm20n1_t* res){
	*res = onumm20n1_init();
}
void onumm20n1_get_im_to_o(imdir_t idx, ord_t order, onumm20n1_t* num, onumm20n1_t* res){
    coeff_t rres = onumm20n1_get_item(idx, order, num);
    onumm20n1_set_r(rres,res);
}
void onumm20n1_get_im_to_r(imdir_t idx, ord_t order, onumm20n1_t* num, coeff_t* res){
    *res = onumm20n1_get_im(idx, order, num);
}

inline ord_t onumm20n1_get_order(onumm20n1_t* lhs){

	return 1;

}

onumm20n1_t onumm20n1_get_deriv_o( imdir_t idx, ord_t order, onumm20n1_t* num){

    onumm20n1_t res = onumm20n1_init();

    onumm20n1_get_deriv_to( idx, order, num, &res);
    
    return res;

}

void onumm20n1_get_deriv_to( imdir_t idx, ord_t order, onumm20n1_t* num, onumm20n1_t* res){

    coeff_t deriv = onumm20n1_get_deriv(idx,order,num);

    onumm20n1_set_r( deriv, res);

}

void onumm20n1_set_im_r(coeff_t num, imdir_t idx, ord_t order, onumm20n1_t* res){

    onumm20n1_set_item(num, idx,order,res);

}

onumm20n1_t onumm20n1_init(){

  onumm20n1_t res;

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
  res.eA = 0.0;
  res.eB = 0.0;
  res.eC = 0.0;
  res.eD = 0.0;
  res.eE = 0.0;
  res.eF = 0.0;
  res.eG = 0.0;
  res.eH = 0.0;
  res.eI = 0.0;
  res.eJ = 0.0;
  res.eK = 0.0;

  return res;

}

ndir_t onumm20n1_get_ndir_order(ord_t order, onumm20n1_t* num){

  ndir_t res;

  switch(order){
    case 0:
      res = 1;
      break;
    case 1:
      res = 20;
      break;
  }

  return res;

}

ndir_t onumm20n1_get_ndir_total(onumm20n1_t* num){

  ndir_t res;

  res = 1;

  return res;

}

onumm20n1_t onumm20n1_create_r(  coeff_t lhs){

  onumm20n1_t res;

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
  res.eA = 0.0;
  res.eB = 0.0;
  res.eC = 0.0;
  res.eD = 0.0;
  res.eE = 0.0;
  res.eF = 0.0;
  res.eG = 0.0;
  res.eH = 0.0;
  res.eI = 0.0;
  res.eJ = 0.0;
  res.eK = 0.0;

  return res;

}

void onumm20n1_set_r(  coeff_t lhs, onumm20n1_t* res){

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
  res->eA = 0.0;
  res->eB = 0.0;
  res->eC = 0.0;
  res->eD = 0.0;
  res->eE = 0.0;
  res->eF = 0.0;
  res->eG = 0.0;
  res->eH = 0.0;
  res->eI = 0.0;
  res->eJ = 0.0;
  res->eK = 0.0;

}

void onumm20n1_set_o(  onumm20n1_t* lhs, onumm20n1_t* res){

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
  res->eA = lhs->eA;
  res->eB = lhs->eB;
  res->eC = lhs->eC;
  res->eD = lhs->eD;
  res->eE = lhs->eE;
  res->eF = lhs->eF;
  res->eG = lhs->eG;
  res->eH = lhs->eH;
  res->eI = lhs->eI;
  res->eJ = lhs->eJ;
  res->eK = lhs->eK;

}

onumm20n1_t onumm20n1_get_order_im(ord_t order, onumm20n1_t* lhs){

  onumm20n1_t res;

  res = onumm20n1_init();
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
      res.eA = lhs->eA;
      res.eB = lhs->eB;
      res.eC = lhs->eC;
      res.eD = lhs->eD;
      res.eE = lhs->eE;
      res.eF = lhs->eF;
      res.eG = lhs->eG;
      res.eH = lhs->eH;
      res.eI = lhs->eI;
      res.eJ = lhs->eJ;
      res.eK = lhs->eK;
      break;
  }

  return res;

}

void onumm20n1_get_order_im_to(ord_t order, onumm20n1_t* lhs, onumm20n1_t* res){


  *res = onumm20n1_init();
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
      res->eA = lhs->eA;
      res->eB = lhs->eB;
      res->eC = lhs->eC;
      res->eD = lhs->eD;
      res->eE = lhs->eE;
      res->eF = lhs->eF;
      res->eG = lhs->eG;
      res->eH = lhs->eH;
      res->eI = lhs->eI;
      res->eJ = lhs->eJ;
      res->eK = lhs->eK;
      break;
  }

}

coeff_t onumm20n1_get_item(imdir_t idx, ord_t order, onumm20n1_t* lhs){

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
        case 9:
          res = lhs->eA;
          break;
        case 10:
          res = lhs->eB;
          break;
        case 11:
          res = lhs->eC;
          break;
        case 12:
          res = lhs->eD;
          break;
        case 13:
          res = lhs->eE;
          break;
        case 14:
          res = lhs->eF;
          break;
        case 15:
          res = lhs->eG;
          break;
        case 16:
          res = lhs->eH;
          break;
        case 17:
          res = lhs->eI;
          break;
        case 18:
          res = lhs->eJ;
          break;
        case 19:
          res = lhs->eK;
          break;
      }
      break;
  }
  return res;

}

coeff_t onumm20n1_get_deriv(imdir_t idx, ord_t order, onumm20n1_t* lhs){

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
        case 9:
          factor = 1.0000000000000000e+00;
          res = lhs->eA*factor;
          break;
        case 10:
          factor = 1.0000000000000000e+00;
          res = lhs->eB*factor;
          break;
        case 11:
          factor = 1.0000000000000000e+00;
          res = lhs->eC*factor;
          break;
        case 12:
          factor = 1.0000000000000000e+00;
          res = lhs->eD*factor;
          break;
        case 13:
          factor = 1.0000000000000000e+00;
          res = lhs->eE*factor;
          break;
        case 14:
          factor = 1.0000000000000000e+00;
          res = lhs->eF*factor;
          break;
        case 15:
          factor = 1.0000000000000000e+00;
          res = lhs->eG*factor;
          break;
        case 16:
          factor = 1.0000000000000000e+00;
          res = lhs->eH*factor;
          break;
        case 17:
          factor = 1.0000000000000000e+00;
          res = lhs->eI*factor;
          break;
        case 18:
          factor = 1.0000000000000000e+00;
          res = lhs->eJ*factor;
          break;
        case 19:
          factor = 1.0000000000000000e+00;
          res = lhs->eK*factor;
          break;
      }
      break;
  }
  return res;

}

void onumm20n1_set_item(coeff_t val, imdir_t idx, ord_t order, onumm20n1_t* x){

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
        case 9:
          x->eA = val;
          break;
        case 10:
          x->eB = val;
          break;
        case 11:
          x->eC = val;
          break;
        case 12:
          x->eD = val;
          break;
        case 13:
          x->eE = val;
          break;
        case 14:
          x->eF = val;
          break;
        case 15:
          x->eG = val;
          break;
        case 16:
          x->eH = val;
          break;
        case 17:
          x->eI = val;
          break;
        case 18:
          x->eJ = val;
          break;
        case 19:
          x->eK = val;
          break;
      }
      break;
  }
}

onumm20n1_t onumm20n1_copy(  onumm20n1_t* lhs){

  onumm20n1_t res;

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
  res.eA = lhs->eA;
  res.eB = lhs->eB;
  res.eC = lhs->eC;
  res.eD = lhs->eD;
  res.eE = lhs->eE;
  res.eF = lhs->eF;
  res.eG = lhs->eG;
  res.eH = lhs->eH;
  res.eI = lhs->eI;
  res.eJ = lhs->eJ;
  res.eK = lhs->eK;

  return res;

}

void onumm20n1_copy_to(  onumm20n1_t* lhs, onumm20n1_t* res){

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
  res->eA = lhs->eA;
  res->eB = lhs->eB;
  res->eC = lhs->eC;
  res->eD = lhs->eD;
  res->eE = lhs->eE;
  res->eF = lhs->eF;
  res->eG = lhs->eG;
  res->eH = lhs->eH;
  res->eI = lhs->eI;
  res->eJ = lhs->eJ;
  res->eK = lhs->eK;

}

onumm20n1_t onumm20n1_taylor_integrate(coeff_t* deltas,onumm20n1_t* lhs){

  onumm20n1_t res;

  coeff_t factor;
  // Taylor integration
  // Real;
  res.r = lhs->r;
  // Order 1;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],0)*pow(deltas[5],0)*pow(deltas[6],0)*pow(deltas[7],0)*pow(deltas[8],0)*pow(deltas[9],0)*pow(deltas[10],0)*pow(deltas[11],0)*pow(deltas[12],0)*pow(deltas[13],0)*pow(deltas[14],0)*pow(deltas[15],0)*pow(deltas[16],0)*pow(deltas[17],0)*pow(deltas[18],0)*pow(deltas[19],0);
  res.e1 = factor*lhs->e1;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],0)*pow(deltas[5],0)*pow(deltas[6],0)*pow(deltas[7],0)*pow(deltas[8],0)*pow(deltas[9],0)*pow(deltas[10],0)*pow(deltas[11],0)*pow(deltas[12],0)*pow(deltas[13],0)*pow(deltas[14],0)*pow(deltas[15],0)*pow(deltas[16],0)*pow(deltas[17],0)*pow(deltas[18],0)*pow(deltas[19],0);
  res.e2 = factor*lhs->e2;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],0)*pow(deltas[4],0)*pow(deltas[5],0)*pow(deltas[6],0)*pow(deltas[7],0)*pow(deltas[8],0)*pow(deltas[9],0)*pow(deltas[10],0)*pow(deltas[11],0)*pow(deltas[12],0)*pow(deltas[13],0)*pow(deltas[14],0)*pow(deltas[15],0)*pow(deltas[16],0)*pow(deltas[17],0)*pow(deltas[18],0)*pow(deltas[19],0);
  res.e3 = factor*lhs->e3;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],1)*pow(deltas[4],0)*pow(deltas[5],0)*pow(deltas[6],0)*pow(deltas[7],0)*pow(deltas[8],0)*pow(deltas[9],0)*pow(deltas[10],0)*pow(deltas[11],0)*pow(deltas[12],0)*pow(deltas[13],0)*pow(deltas[14],0)*pow(deltas[15],0)*pow(deltas[16],0)*pow(deltas[17],0)*pow(deltas[18],0)*pow(deltas[19],0);
  res.e4 = factor*lhs->e4;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],1)*pow(deltas[5],0)*pow(deltas[6],0)*pow(deltas[7],0)*pow(deltas[8],0)*pow(deltas[9],0)*pow(deltas[10],0)*pow(deltas[11],0)*pow(deltas[12],0)*pow(deltas[13],0)*pow(deltas[14],0)*pow(deltas[15],0)*pow(deltas[16],0)*pow(deltas[17],0)*pow(deltas[18],0)*pow(deltas[19],0);
  res.e5 = factor*lhs->e5;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],0)*pow(deltas[5],1)*pow(deltas[6],0)*pow(deltas[7],0)*pow(deltas[8],0)*pow(deltas[9],0)*pow(deltas[10],0)*pow(deltas[11],0)*pow(deltas[12],0)*pow(deltas[13],0)*pow(deltas[14],0)*pow(deltas[15],0)*pow(deltas[16],0)*pow(deltas[17],0)*pow(deltas[18],0)*pow(deltas[19],0);
  res.e6 = factor*lhs->e6;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],0)*pow(deltas[5],0)*pow(deltas[6],1)*pow(deltas[7],0)*pow(deltas[8],0)*pow(deltas[9],0)*pow(deltas[10],0)*pow(deltas[11],0)*pow(deltas[12],0)*pow(deltas[13],0)*pow(deltas[14],0)*pow(deltas[15],0)*pow(deltas[16],0)*pow(deltas[17],0)*pow(deltas[18],0)*pow(deltas[19],0);
  res.e7 = factor*lhs->e7;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],0)*pow(deltas[5],0)*pow(deltas[6],0)*pow(deltas[7],1)*pow(deltas[8],0)*pow(deltas[9],0)*pow(deltas[10],0)*pow(deltas[11],0)*pow(deltas[12],0)*pow(deltas[13],0)*pow(deltas[14],0)*pow(deltas[15],0)*pow(deltas[16],0)*pow(deltas[17],0)*pow(deltas[18],0)*pow(deltas[19],0);
  res.e8 = factor*lhs->e8;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],0)*pow(deltas[5],0)*pow(deltas[6],0)*pow(deltas[7],0)*pow(deltas[8],1)*pow(deltas[9],0)*pow(deltas[10],0)*pow(deltas[11],0)*pow(deltas[12],0)*pow(deltas[13],0)*pow(deltas[14],0)*pow(deltas[15],0)*pow(deltas[16],0)*pow(deltas[17],0)*pow(deltas[18],0)*pow(deltas[19],0);
  res.e9 = factor*lhs->e9;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],0)*pow(deltas[5],0)*pow(deltas[6],0)*pow(deltas[7],0)*pow(deltas[8],0)*pow(deltas[9],0)*pow(deltas[10],0)*pow(deltas[11],0)*pow(deltas[12],0)*pow(deltas[13],0)*pow(deltas[14],0)*pow(deltas[15],0)*pow(deltas[16],0)*pow(deltas[17],0)*pow(deltas[18],0)*pow(deltas[19],0);
  res.eA = factor*lhs->eA;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],0)*pow(deltas[5],0)*pow(deltas[6],0)*pow(deltas[7],0)*pow(deltas[8],0)*pow(deltas[9],0)*pow(deltas[10],0)*pow(deltas[11],0)*pow(deltas[12],0)*pow(deltas[13],0)*pow(deltas[14],0)*pow(deltas[15],0)*pow(deltas[16],0)*pow(deltas[17],0)*pow(deltas[18],0)*pow(deltas[19],0);
  res.eB = factor*lhs->eB;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],0)*pow(deltas[5],0)*pow(deltas[6],0)*pow(deltas[7],0)*pow(deltas[8],0)*pow(deltas[9],0)*pow(deltas[10],0)*pow(deltas[11],0)*pow(deltas[12],0)*pow(deltas[13],0)*pow(deltas[14],0)*pow(deltas[15],0)*pow(deltas[16],0)*pow(deltas[17],0)*pow(deltas[18],0)*pow(deltas[19],0);
  res.eC = factor*lhs->eC;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],0)*pow(deltas[5],0)*pow(deltas[6],0)*pow(deltas[7],0)*pow(deltas[8],0)*pow(deltas[9],0)*pow(deltas[10],0)*pow(deltas[11],0)*pow(deltas[12],0)*pow(deltas[13],0)*pow(deltas[14],0)*pow(deltas[15],0)*pow(deltas[16],0)*pow(deltas[17],0)*pow(deltas[18],0)*pow(deltas[19],0);
  res.eD = factor*lhs->eD;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],0)*pow(deltas[5],0)*pow(deltas[6],0)*pow(deltas[7],0)*pow(deltas[8],0)*pow(deltas[9],0)*pow(deltas[10],0)*pow(deltas[11],0)*pow(deltas[12],0)*pow(deltas[13],0)*pow(deltas[14],0)*pow(deltas[15],0)*pow(deltas[16],0)*pow(deltas[17],0)*pow(deltas[18],0)*pow(deltas[19],0);
  res.eE = factor*lhs->eE;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],0)*pow(deltas[5],0)*pow(deltas[6],0)*pow(deltas[7],0)*pow(deltas[8],0)*pow(deltas[9],0)*pow(deltas[10],0)*pow(deltas[11],0)*pow(deltas[12],0)*pow(deltas[13],0)*pow(deltas[14],0)*pow(deltas[15],0)*pow(deltas[16],0)*pow(deltas[17],0)*pow(deltas[18],0)*pow(deltas[19],0);
  res.eF = factor*lhs->eF;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],0)*pow(deltas[5],0)*pow(deltas[6],0)*pow(deltas[7],0)*pow(deltas[8],0)*pow(deltas[9],0)*pow(deltas[10],0)*pow(deltas[11],0)*pow(deltas[12],0)*pow(deltas[13],0)*pow(deltas[14],0)*pow(deltas[15],0)*pow(deltas[16],0)*pow(deltas[17],0)*pow(deltas[18],0)*pow(deltas[19],0);
  res.eG = factor*lhs->eG;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],0)*pow(deltas[5],0)*pow(deltas[6],0)*pow(deltas[7],0)*pow(deltas[8],0)*pow(deltas[9],0)*pow(deltas[10],0)*pow(deltas[11],0)*pow(deltas[12],0)*pow(deltas[13],0)*pow(deltas[14],0)*pow(deltas[15],0)*pow(deltas[16],0)*pow(deltas[17],0)*pow(deltas[18],0)*pow(deltas[19],0);
  res.eH = factor*lhs->eH;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],0)*pow(deltas[5],0)*pow(deltas[6],0)*pow(deltas[7],0)*pow(deltas[8],0)*pow(deltas[9],0)*pow(deltas[10],0)*pow(deltas[11],0)*pow(deltas[12],0)*pow(deltas[13],0)*pow(deltas[14],0)*pow(deltas[15],0)*pow(deltas[16],0)*pow(deltas[17],0)*pow(deltas[18],0)*pow(deltas[19],0);
  res.eI = factor*lhs->eI;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],0)*pow(deltas[5],0)*pow(deltas[6],0)*pow(deltas[7],0)*pow(deltas[8],0)*pow(deltas[9],0)*pow(deltas[10],0)*pow(deltas[11],0)*pow(deltas[12],0)*pow(deltas[13],0)*pow(deltas[14],0)*pow(deltas[15],0)*pow(deltas[16],0)*pow(deltas[17],0)*pow(deltas[18],0)*pow(deltas[19],0);
  res.eJ = factor*lhs->eJ;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],0)*pow(deltas[5],0)*pow(deltas[6],0)*pow(deltas[7],0)*pow(deltas[8],0)*pow(deltas[9],0)*pow(deltas[10],0)*pow(deltas[11],0)*pow(deltas[12],0)*pow(deltas[13],0)*pow(deltas[14],0)*pow(deltas[15],0)*pow(deltas[16],0)*pow(deltas[17],0)*pow(deltas[18],0)*pow(deltas[19],0);
  res.eK = factor*lhs->eK;

  return res;

}

void onumm20n1_taylor_integrate_to(coeff_t* deltas,onumm20n1_t* lhs, onumm20n1_t* res){

  coeff_t factor;
  // Taylor integration
  // Real;
  res->r = lhs->r;
  // Order 1;
  factor = pow(deltas[0],1)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],0)*pow(deltas[5],0)*pow(deltas[6],0)*pow(deltas[7],0)*pow(deltas[8],0)*pow(deltas[9],0)*pow(deltas[10],0)*pow(deltas[11],0)*pow(deltas[12],0)*pow(deltas[13],0)*pow(deltas[14],0)*pow(deltas[15],0)*pow(deltas[16],0)*pow(deltas[17],0)*pow(deltas[18],0)*pow(deltas[19],0);
  res->e1 = factor*lhs->e1;
  factor = pow(deltas[0],0)*pow(deltas[1],1)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],0)*pow(deltas[5],0)*pow(deltas[6],0)*pow(deltas[7],0)*pow(deltas[8],0)*pow(deltas[9],0)*pow(deltas[10],0)*pow(deltas[11],0)*pow(deltas[12],0)*pow(deltas[13],0)*pow(deltas[14],0)*pow(deltas[15],0)*pow(deltas[16],0)*pow(deltas[17],0)*pow(deltas[18],0)*pow(deltas[19],0);
  res->e2 = factor*lhs->e2;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],1)*pow(deltas[3],0)*pow(deltas[4],0)*pow(deltas[5],0)*pow(deltas[6],0)*pow(deltas[7],0)*pow(deltas[8],0)*pow(deltas[9],0)*pow(deltas[10],0)*pow(deltas[11],0)*pow(deltas[12],0)*pow(deltas[13],0)*pow(deltas[14],0)*pow(deltas[15],0)*pow(deltas[16],0)*pow(deltas[17],0)*pow(deltas[18],0)*pow(deltas[19],0);
  res->e3 = factor*lhs->e3;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],1)*pow(deltas[4],0)*pow(deltas[5],0)*pow(deltas[6],0)*pow(deltas[7],0)*pow(deltas[8],0)*pow(deltas[9],0)*pow(deltas[10],0)*pow(deltas[11],0)*pow(deltas[12],0)*pow(deltas[13],0)*pow(deltas[14],0)*pow(deltas[15],0)*pow(deltas[16],0)*pow(deltas[17],0)*pow(deltas[18],0)*pow(deltas[19],0);
  res->e4 = factor*lhs->e4;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],1)*pow(deltas[5],0)*pow(deltas[6],0)*pow(deltas[7],0)*pow(deltas[8],0)*pow(deltas[9],0)*pow(deltas[10],0)*pow(deltas[11],0)*pow(deltas[12],0)*pow(deltas[13],0)*pow(deltas[14],0)*pow(deltas[15],0)*pow(deltas[16],0)*pow(deltas[17],0)*pow(deltas[18],0)*pow(deltas[19],0);
  res->e5 = factor*lhs->e5;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],0)*pow(deltas[5],1)*pow(deltas[6],0)*pow(deltas[7],0)*pow(deltas[8],0)*pow(deltas[9],0)*pow(deltas[10],0)*pow(deltas[11],0)*pow(deltas[12],0)*pow(deltas[13],0)*pow(deltas[14],0)*pow(deltas[15],0)*pow(deltas[16],0)*pow(deltas[17],0)*pow(deltas[18],0)*pow(deltas[19],0);
  res->e6 = factor*lhs->e6;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],0)*pow(deltas[5],0)*pow(deltas[6],1)*pow(deltas[7],0)*pow(deltas[8],0)*pow(deltas[9],0)*pow(deltas[10],0)*pow(deltas[11],0)*pow(deltas[12],0)*pow(deltas[13],0)*pow(deltas[14],0)*pow(deltas[15],0)*pow(deltas[16],0)*pow(deltas[17],0)*pow(deltas[18],0)*pow(deltas[19],0);
  res->e7 = factor*lhs->e7;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],0)*pow(deltas[5],0)*pow(deltas[6],0)*pow(deltas[7],1)*pow(deltas[8],0)*pow(deltas[9],0)*pow(deltas[10],0)*pow(deltas[11],0)*pow(deltas[12],0)*pow(deltas[13],0)*pow(deltas[14],0)*pow(deltas[15],0)*pow(deltas[16],0)*pow(deltas[17],0)*pow(deltas[18],0)*pow(deltas[19],0);
  res->e8 = factor*lhs->e8;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],0)*pow(deltas[5],0)*pow(deltas[6],0)*pow(deltas[7],0)*pow(deltas[8],1)*pow(deltas[9],0)*pow(deltas[10],0)*pow(deltas[11],0)*pow(deltas[12],0)*pow(deltas[13],0)*pow(deltas[14],0)*pow(deltas[15],0)*pow(deltas[16],0)*pow(deltas[17],0)*pow(deltas[18],0)*pow(deltas[19],0);
  res->e9 = factor*lhs->e9;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],0)*pow(deltas[5],0)*pow(deltas[6],0)*pow(deltas[7],0)*pow(deltas[8],0)*pow(deltas[9],0)*pow(deltas[10],0)*pow(deltas[11],0)*pow(deltas[12],0)*pow(deltas[13],0)*pow(deltas[14],0)*pow(deltas[15],0)*pow(deltas[16],0)*pow(deltas[17],0)*pow(deltas[18],0)*pow(deltas[19],0);
  res->eA = factor*lhs->eA;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],0)*pow(deltas[5],0)*pow(deltas[6],0)*pow(deltas[7],0)*pow(deltas[8],0)*pow(deltas[9],0)*pow(deltas[10],0)*pow(deltas[11],0)*pow(deltas[12],0)*pow(deltas[13],0)*pow(deltas[14],0)*pow(deltas[15],0)*pow(deltas[16],0)*pow(deltas[17],0)*pow(deltas[18],0)*pow(deltas[19],0);
  res->eB = factor*lhs->eB;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],0)*pow(deltas[5],0)*pow(deltas[6],0)*pow(deltas[7],0)*pow(deltas[8],0)*pow(deltas[9],0)*pow(deltas[10],0)*pow(deltas[11],0)*pow(deltas[12],0)*pow(deltas[13],0)*pow(deltas[14],0)*pow(deltas[15],0)*pow(deltas[16],0)*pow(deltas[17],0)*pow(deltas[18],0)*pow(deltas[19],0);
  res->eC = factor*lhs->eC;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],0)*pow(deltas[5],0)*pow(deltas[6],0)*pow(deltas[7],0)*pow(deltas[8],0)*pow(deltas[9],0)*pow(deltas[10],0)*pow(deltas[11],0)*pow(deltas[12],0)*pow(deltas[13],0)*pow(deltas[14],0)*pow(deltas[15],0)*pow(deltas[16],0)*pow(deltas[17],0)*pow(deltas[18],0)*pow(deltas[19],0);
  res->eD = factor*lhs->eD;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],0)*pow(deltas[5],0)*pow(deltas[6],0)*pow(deltas[7],0)*pow(deltas[8],0)*pow(deltas[9],0)*pow(deltas[10],0)*pow(deltas[11],0)*pow(deltas[12],0)*pow(deltas[13],0)*pow(deltas[14],0)*pow(deltas[15],0)*pow(deltas[16],0)*pow(deltas[17],0)*pow(deltas[18],0)*pow(deltas[19],0);
  res->eE = factor*lhs->eE;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],0)*pow(deltas[5],0)*pow(deltas[6],0)*pow(deltas[7],0)*pow(deltas[8],0)*pow(deltas[9],0)*pow(deltas[10],0)*pow(deltas[11],0)*pow(deltas[12],0)*pow(deltas[13],0)*pow(deltas[14],0)*pow(deltas[15],0)*pow(deltas[16],0)*pow(deltas[17],0)*pow(deltas[18],0)*pow(deltas[19],0);
  res->eF = factor*lhs->eF;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],0)*pow(deltas[5],0)*pow(deltas[6],0)*pow(deltas[7],0)*pow(deltas[8],0)*pow(deltas[9],0)*pow(deltas[10],0)*pow(deltas[11],0)*pow(deltas[12],0)*pow(deltas[13],0)*pow(deltas[14],0)*pow(deltas[15],0)*pow(deltas[16],0)*pow(deltas[17],0)*pow(deltas[18],0)*pow(deltas[19],0);
  res->eG = factor*lhs->eG;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],0)*pow(deltas[5],0)*pow(deltas[6],0)*pow(deltas[7],0)*pow(deltas[8],0)*pow(deltas[9],0)*pow(deltas[10],0)*pow(deltas[11],0)*pow(deltas[12],0)*pow(deltas[13],0)*pow(deltas[14],0)*pow(deltas[15],0)*pow(deltas[16],0)*pow(deltas[17],0)*pow(deltas[18],0)*pow(deltas[19],0);
  res->eH = factor*lhs->eH;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],0)*pow(deltas[5],0)*pow(deltas[6],0)*pow(deltas[7],0)*pow(deltas[8],0)*pow(deltas[9],0)*pow(deltas[10],0)*pow(deltas[11],0)*pow(deltas[12],0)*pow(deltas[13],0)*pow(deltas[14],0)*pow(deltas[15],0)*pow(deltas[16],0)*pow(deltas[17],0)*pow(deltas[18],0)*pow(deltas[19],0);
  res->eI = factor*lhs->eI;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],0)*pow(deltas[5],0)*pow(deltas[6],0)*pow(deltas[7],0)*pow(deltas[8],0)*pow(deltas[9],0)*pow(deltas[10],0)*pow(deltas[11],0)*pow(deltas[12],0)*pow(deltas[13],0)*pow(deltas[14],0)*pow(deltas[15],0)*pow(deltas[16],0)*pow(deltas[17],0)*pow(deltas[18],0)*pow(deltas[19],0);
  res->eJ = factor*lhs->eJ;
  factor = pow(deltas[0],0)*pow(deltas[1],0)*pow(deltas[2],0)*pow(deltas[3],0)*pow(deltas[4],0)*pow(deltas[5],0)*pow(deltas[6],0)*pow(deltas[7],0)*pow(deltas[8],0)*pow(deltas[9],0)*pow(deltas[10],0)*pow(deltas[11],0)*pow(deltas[12],0)*pow(deltas[13],0)*pow(deltas[14],0)*pow(deltas[15],0)*pow(deltas[16],0)*pow(deltas[17],0)*pow(deltas[18],0)*pow(deltas[19],0);
  res->eK = factor*lhs->eK;

}

onumm20n1_t onumm20n1_truncate_im(imdir_t idx, ord_t order, onumm20n1_t* lhs){

  onumm20n1_t res;

  // Copy number.
  res = (*lhs);
  // Truncate all other values when necessary.
  // Real;
  switch (order){
    case 0:
      res = onumm20n1_init();
      break;
    case 1:
      switch (idx){
        case 0: //  e1
          res.e1 = 0.0;
          break;
        case 1: //  e2
          res.e2 = 0.0;
          break;
        case 2: //  e3
          res.e3 = 0.0;
          break;
        case 3: //  e4
          res.e4 = 0.0;
          break;
        case 4: //  e5
          res.e5 = 0.0;
          break;
        case 5: //  e6
          res.e6 = 0.0;
          break;
        case 6: //  e7
          res.e7 = 0.0;
          break;
        case 7: //  e8
          res.e8 = 0.0;
          break;
        case 8: //  e9
          res.e9 = 0.0;
          break;
        case 9: //  eA
          res.eA = 0.0;
          break;
        case 10: //  eB
          res.eB = 0.0;
          break;
        case 11: //  eC
          res.eC = 0.0;
          break;
        case 12: //  eD
          res.eD = 0.0;
          break;
        case 13: //  eE
          res.eE = 0.0;
          break;
        case 14: //  eF
          res.eF = 0.0;
          break;
        case 15: //  eG
          res.eG = 0.0;
          break;
        case 16: //  eH
          res.eH = 0.0;
          break;
        case 17: //  eI
          res.eI = 0.0;
          break;
        case 18: //  eJ
          res.eJ = 0.0;
          break;
        case 19: //  eK
          res.eK = 0.0;
          break;
      }
      break;
  }
  return res;

}

void onumm20n1_truncate_im_to(imdir_t idx, ord_t order, onumm20n1_t* lhs, onumm20n1_t* res){

  // Copy number.
  *res = (*lhs);
  // Truncate all other values when necessary.
  // Real;
  switch (order){
    case 0:
      *res = onumm20n1_init();
      break;
    case 1:
      switch (idx){
        case 0: //  e1
          res->e1 = 0.0;
          break;
        case 1: //  e2
          res->e2 = 0.0;
          break;
        case 2: //  e3
          res->e3 = 0.0;
          break;
        case 3: //  e4
          res->e4 = 0.0;
          break;
        case 4: //  e5
          res->e5 = 0.0;
          break;
        case 5: //  e6
          res->e6 = 0.0;
          break;
        case 6: //  e7
          res->e7 = 0.0;
          break;
        case 7: //  e8
          res->e8 = 0.0;
          break;
        case 8: //  e9
          res->e9 = 0.0;
          break;
        case 9: //  eA
          res->eA = 0.0;
          break;
        case 10: //  eB
          res->eB = 0.0;
          break;
        case 11: //  eC
          res->eC = 0.0;
          break;
        case 12: //  eD
          res->eD = 0.0;
          break;
        case 13: //  eE
          res->eE = 0.0;
          break;
        case 14: //  eF
          res->eF = 0.0;
          break;
        case 15: //  eG
          res->eG = 0.0;
          break;
        case 16: //  eH
          res->eH = 0.0;
          break;
        case 17: //  eI
          res->eI = 0.0;
          break;
        case 18: //  eJ
          res->eJ = 0.0;
          break;
        case 19: //  eK
          res->eK = 0.0;
          break;
      }
      break;
  }
}

void onumm20n1_print(  onumm20n1_t* lhs){

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
  printf(" %+.8g*eA",lhs->eA);
  printf(" %+.8g*eB",lhs->eB);
  printf(" %+.8g*eC",lhs->eC);
  printf(" %+.8g*eD",lhs->eD);
  printf(" %+.8g*eE",lhs->eE);
  printf(" %+.8g*eF",lhs->eF);
  printf(" %+.8g*eG",lhs->eG);
  printf(" %+.8g*eH",lhs->eH);
  printf(" %+.8g*eI",lhs->eI);
  printf(" %+.8g*eJ",lhs->eJ);
  printf(" %+.8g*eK",lhs->eK);
  printf("\n");

}

