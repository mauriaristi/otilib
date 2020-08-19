mdnum3_t mdnum3_init(){

  mdnum3_t res;

  // Init function
  // Real;
  res.r = 0.0;
  // Order 1;
  res.e1 = 0.0;
  res.e2 = 0.0;
  res.e3 = 0.0;
  // Order 2;
  res.e12 = 0.0;
  res.e13 = 0.0;
  res.e23 = 0.0;
  // Order 3;
  res.e123 = 0.0;

  return res;

}

mdnum3_t mdnum3_create_r(  coeff_t lhs){

  mdnum3_t res;

  // Assign like function 'lhs'
  // Real;
  res.r = lhs;
  // Order 1;
  res.e1 = 0.0;
  res.e2 = 0.0;
  res.e3 = 0.0;
  // Order 2;
  res.e12 = 0.0;
  res.e13 = 0.0;
  res.e23 = 0.0;
  // Order 3;
  res.e123 = 0.0;

  return res;

}

void mdnum3_set_r(  coeff_t lhs, mdnum3_t* res){

  // Assign like function 'lhs'
  // Real;
  res->r = lhs;
  // Order 1;
  res->e1 = 0.0;
  res->e2 = 0.0;
  res->e3 = 0.0;
  // Order 2;
  res->e12 = 0.0;
  res->e13 = 0.0;
  res->e23 = 0.0;
  // Order 3;
  res->e123 = 0.0;

}

void mdnum3_set_o(  mdnum3_t* lhs, mdnum3_t* res){

  // Assign like function 'lhs'
  // Real;
  res->r = lhs->r;
  // Order 1;
  res->e1 = lhs->e1;
  res->e2 = lhs->e2;
  res->e3 = lhs->e3;
  // Order 2;
  res->e12 = lhs->e12;
  res->e13 = lhs->e13;
  res->e23 = lhs->e23;
  // Order 3;
  res->e123 = lhs->e123;

}

coeff_t mdnum3_get_item(imdir_t idx, ord_t order, mdnum3_t* lhs){

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
          res = lhs->e12;
          break;
        case 1:
          res = lhs->e13;
          break;
        case 2:
          res = lhs->e23;
          break;
      }
      break;
    case 3:
      switch (idx){
        case 0:
          res = lhs->e123;
          break;
      }
      break;
  }
  return res;

}

void mdnum3_set_item(coeff_t val, imdir_t idx, ord_t order, mdnum3_t* x){

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
          x->e12 = val;
          break;
        case 1:
          x->e13 = val;
          break;
        case 2:
          x->e23 = val;
          break;
      }
      break;
    case 3:
      switch (idx){
        case 0:
          x->e123 = val;
          break;
      }
      break;
  }
}

mdnum3_t mdnum3_copy(  mdnum3_t* lhs){

  mdnum3_t res;

  // Assign like function 'lhs'
  // Real;
  res.r = lhs->r;
  // Order 1;
  res.e1 = lhs->e1;
  res.e2 = lhs->e2;
  res.e3 = lhs->e3;
  // Order 2;
  res.e12 = lhs->e12;
  res.e13 = lhs->e13;
  res.e23 = lhs->e23;
  // Order 3;
  res.e123 = lhs->e123;

  return res;

}

void mdnum3_copy_to(  mdnum3_t* lhs, mdnum3_t* res){

  // Assign like function 'lhs'
  // Real;
  res->r = lhs->r;
  // Order 1;
  res->e1 = lhs->e1;
  res->e2 = lhs->e2;
  res->e3 = lhs->e3;
  // Order 2;
  res->e12 = lhs->e12;
  res->e13 = lhs->e13;
  res->e23 = lhs->e23;
  // Order 3;
  res->e123 = lhs->e123;

}

void mdnum3_print(  mdnum3_t* lhs){

  // Print function.
  //  Real;
  printf("%.8g",lhs->r);
  //  Order 1;
  printf(" %+.8g*e1",lhs->e1);
  printf(" %+.8g*e2",lhs->e2);
  printf(" %+.8g*e3",lhs->e3);
  //  Order 2;
  printf(" %+.8g*e12",lhs->e12);
  printf(" %+.8g*e13",lhs->e13);
  printf(" %+.8g*e23",lhs->e23);
  //  Order 3;
  printf(" %+.8g*e123",lhs->e123);
  printf("\n");

}

