mdnum2_t mdnum2_init(){

  mdnum2_t res;

  // Init function
  // Real;
  res.r = 0.0;
  // Order 1;
  res.e1 = 0.0;
  res.e2 = 0.0;
  // Order 2;
  res.e12 = 0.0;

  return res;

}

mdnum2_t mdnum2_create_r(  coeff_t lhs){

  mdnum2_t res;

  // Assign like function 'lhs'
  // Real;
  res.r = lhs;
  // Order 1;
  res.e1 = 0.0;
  res.e2 = 0.0;
  // Order 2;
  res.e12 = 0.0;

  return res;

}

void mdnum2_set_r_to(  coeff_t lhs, mdnum2_t* res){

  // Assign like function 'lhs'
  // Real;
  res->r = lhs;
  // Order 1;
  res->e1 = 0.0;
  res->e2 = 0.0;
  // Order 2;
  res->e12 = 0.0;

}

void mdnum2_set_o_to(  mdnum2_t* lhs, mdnum2_t* res){

  // Assign like function 'lhs'
  // Real;
  res->r = lhs->r;
  // Order 1;
  res->e1 = lhs->e1;
  res->e2 = lhs->e2;
  // Order 2;
  res->e12 = lhs->e12;

}

coeff_t mdnum2_get_item(imdir_t idx, ord_t order, mdnum2_t* lhs){

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
          res = lhs->e12;
          break;
      }
      break;
  }
  return res;

}

void mdnum2_set_item(coeff_t val, imdir_t idx, ord_t order, mdnum2_t* x){

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
          x->e12 = val;
          break;
      }
      break;
  }
}

mdnum2_t mdnum2_copy(  mdnum2_t* lhs){

  mdnum2_t res;

  // Assign like function 'lhs'
  // Real;
  res.r = lhs->r;
  // Order 1;
  res.e1 = lhs->e1;
  res.e2 = lhs->e2;
  // Order 2;
  res.e12 = lhs->e12;

  return res;

}

void mdnum2_copy_to(  mdnum2_t* lhs, mdnum2_t* res){

  // Assign like function 'lhs'
  // Real;
  res->r = lhs->r;
  // Order 1;
  res->e1 = lhs->e1;
  res->e2 = lhs->e2;
  // Order 2;
  res->e12 = lhs->e12;

}

void mdnum2_print(  mdnum2_t* lhs){

  // Print function.
  //  Real;
  printf("%.8g",lhs->r);
  //  Order 1;
  printf(" %+.8g*e1",lhs->e1);
  printf(" %+.8g*e2",lhs->e2);
  //  Order 2;
  printf(" %+.8g*e12",lhs->e12);
  printf("\n");

}

