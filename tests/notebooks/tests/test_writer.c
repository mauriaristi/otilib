#include"test_writer.h"

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

void mdnum3_set_r_to(  coeff_t lhs, mdnum3_t* res){

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

void mdnum3_set_o_to(  mdnum3_t* lhs, mdnum3_t* res){

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

mdnum3_t mdnum3_neg(  mdnum3_t* lhs){

  mdnum3_t res;

  // Negation like function '-lhs'
  // Real;
  res.r = -lhs->r;
  // Order 1;
  res.e1 = -lhs->e1;
  res.e2 = -lhs->e2;
  res.e3 = -lhs->e3;
  // Order 2;
  res.e12 = -lhs->e12;
  res.e13 = -lhs->e13;
  res.e23 = -lhs->e23;
  // Order 3;
  res.e123 = -lhs->e123;

  return res;

}

void mdnum3_neg_to(  mdnum3_t* lhs, mdnum3_t* res){

  // Negation like function '-lhs'
  // Real;
  res->r = -lhs->r;
  // Order 1;
  res->e1 = -lhs->e1;
  res->e2 = -lhs->e2;
  res->e3 = -lhs->e3;
  // Order 2;
  res->e12 = -lhs->e12;
  res->e13 = -lhs->e13;
  res->e23 = -lhs->e23;
  // Order 3;
  res->e123 = -lhs->e123;

}

mdnum3_t mdnum3_add_oo(  mdnum3_t* lhs,  mdnum3_t* rhs){
  mdnum3_t res;

  // Addition like function 'lhs + rhs'
  //  Real
  res.r = lhs->r + rhs->r;
  // Order 1
  res.e1 = lhs->e1 + rhs->e1;
  res.e2 = lhs->e2 + rhs->e2;
  res.e3 = lhs->e3 + rhs->e3;
  // Order 2
  res.e12 = lhs->e12 + rhs->e12;
  res.e13 = lhs->e13 + rhs->e13;
  res.e23 = lhs->e23 + rhs->e23;
  // Order 3
  res.e123 = lhs->e123 + rhs->e123;

  return res;

}

void mdnum3_add_oo_to(  mdnum3_t* lhs,  mdnum3_t* rhs, mdnum3_t* res){
  // Addition like function 'lhs + rhs'
  //  Real
  res->r = lhs->r + rhs->r;
  // Order 1
  res->e1 = lhs->e1 + rhs->e1;
  res->e2 = lhs->e2 + rhs->e2;
  res->e3 = lhs->e3 + rhs->e3;
  // Order 2
  res->e12 = lhs->e12 + rhs->e12;
  res->e13 = lhs->e13 + rhs->e13;
  res->e23 = lhs->e23 + rhs->e23;
  // Order 3
  res->e123 = lhs->e123 + rhs->e123;

}

mdnum3_t mdnum3_add_ro(  coeff_t lhs,  mdnum3_t* rhs){
  mdnum3_t res;

  // Addition like function 'lhs + rhs'
  // Real;
  res.r = lhs + rhs->r;
  // Order 1;
  res.e1 =  + rhs->e1;
  res.e2 =  + rhs->e2;
  res.e3 =  + rhs->e3;
  // Order 2;
  res.e12 =  + rhs->e12;
  res.e13 =  + rhs->e13;
  res.e23 =  + rhs->e23;
  // Order 3;
  res.e123 =  + rhs->e123;

  return res;

}

void mdnum3_add_ro_to(  coeff_t lhs,  mdnum3_t* rhs, mdnum3_t* res){
  // Addition like function 'lhs + rhs'
  // Real;
  res->r = lhs + rhs->r;
  // Order 1;
  res->e1 =  + rhs->e1;
  res->e2 =  + rhs->e2;
  res->e3 =  + rhs->e3;
  // Order 2;
  res->e12 =  + rhs->e12;
  res->e13 =  + rhs->e13;
  res->e23 =  + rhs->e23;
  // Order 3;
  res->e123 =  + rhs->e123;

}

mdnum3_t mdnum3_sub_oo(  mdnum3_t lhs,  mdnum3_t* rhs){
  mdnum3_t res;

  // Addition like function 'lhs - rhs'
  //  Real
  res.r = lhs.r - rhs->r;
  // Order 1
  res.e1 = lhs.e1 - rhs->e1;
  res.e2 = lhs.e2 - rhs->e2;
  res.e3 = lhs.e3 - rhs->e3;
  // Order 2
  res.e12 = lhs.e12 - rhs->e12;
  res.e13 = lhs.e13 - rhs->e13;
  res.e23 = lhs.e23 - rhs->e23;
  // Order 3
  res.e123 = lhs.e123 - rhs->e123;

  return res;

}

void mdnum3_sub_oo_to(  mdnum3_t lhs,  mdnum3_t* rhs, mdnum3_t* res){
  // Addition like function 'lhs - rhs'
  //  Real
  res->r = lhs.r - rhs->r;
  // Order 1
  res->e1 = lhs.e1 - rhs->e1;
  res->e2 = lhs.e2 - rhs->e2;
  res->e3 = lhs.e3 - rhs->e3;
  // Order 2
  res->e12 = lhs.e12 - rhs->e12;
  res->e13 = lhs.e13 - rhs->e13;
  res->e23 = lhs.e23 - rhs->e23;
  // Order 3
  res->e123 = lhs.e123 - rhs->e123;

}

mdnum3_t mdnum3_sub_ro(  coeff_t lhs,  mdnum3_t* rhs){
  mdnum3_t res;

  // Addition like function 'lhs - rhs'
  // Real;
  res.r = lhs - rhs->r;
  // Order 1;
  res.e1 =  - rhs->e1;
  res.e2 =  - rhs->e2;
  res.e3 =  - rhs->e3;
  // Order 2;
  res.e12 =  - rhs->e12;
  res.e13 =  - rhs->e13;
  res.e23 =  - rhs->e23;
  // Order 3;
  res.e123 =  - rhs->e123;

  return res;

}

void mdnum3_sub_ro_to(  coeff_t lhs,  mdnum3_t* rhs, mdnum3_t* res){
  // Addition like function 'lhs - rhs'
  // Real;
  res->r = lhs - rhs->r;
  // Order 1;
  res->e1 =  - rhs->e1;
  res->e2 =  - rhs->e2;
  res->e3 =  - rhs->e3;
  // Order 2;
  res->e12 =  - rhs->e12;
  res->e13 =  - rhs->e13;
  res->e23 =  - rhs->e23;
  // Order 3;
  res->e123 =  - rhs->e123;

}

mdnum3_t mdnum3_sub_or(  mdnum3_t* lhs,  coeff_t rhs){
  mdnum3_t res;

  // Addition like function 'lhs - rhs'
  // Real;
  res.r = lhs->r - rhs;
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

void mdnum3_sub_or_to(  mdnum3_t* lhs,  coeff_t rhs, mdnum3_t* res){
  // Addition like function 'lhs - rhs'
  // Real;
  res->r = lhs->r - rhs;
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

mdnum3_t mdnum3_mul_oo(  mdnum3_t* lhs,  mdnum3_t* rhs){
  mdnum3_t res;

  //  Multiplication like function 'lhs * rhs'
  // Real;
  res.r = lhs->r * rhs->r;
  // Order 1;
  res.e1 = lhs->r * rhs->e1 + lhs->e1 * rhs->r;
  res.e2 = lhs->r * rhs->e2 + lhs->e2 * rhs->r;
  res.e3 = lhs->r * rhs->e3 + lhs->e3 * rhs->r;
  // Order 2;
  res.e12 = lhs->r * rhs->e12 + lhs->e12 * rhs->r + lhs->e1 * rhs->e2 
          + lhs->e2 * rhs->e1;
  res.e13 = lhs->r * rhs->e13 + lhs->e13 * rhs->r + lhs->e1 * rhs->e3 
          + lhs->e3 * rhs->e1;
  res.e23 = lhs->r * rhs->e23 + lhs->e23 * rhs->r + lhs->e2 * rhs->e3 
          + lhs->e3 * rhs->e2;
  // Order 3;
  res.e123 = lhs->r * rhs->e123 + lhs->e123 * rhs->r + lhs->e1 * rhs->e23 
           + lhs->e23 * rhs->e1 + lhs->e2 * rhs->e13 + lhs->e13 * rhs->e2 
           + lhs->e3 * rhs->e12 + lhs->e12 * rhs->e3;

  return res;

}

void mdnum3_mul_oo_to(  mdnum3_t* lhs,  mdnum3_t* rhs, mdnum3_t* res){
  //  Multiplication like function 'lhs * rhs'
  // Real;
  res->r = lhs->r * rhs->r;
  // Order 1;
  res->e1 = lhs->r * rhs->e1 + lhs->e1 * rhs->r;
  res->e2 = lhs->r * rhs->e2 + lhs->e2 * rhs->r;
  res->e3 = lhs->r * rhs->e3 + lhs->e3 * rhs->r;
  // Order 2;
  res->e12 = lhs->r * rhs->e12 + lhs->e12 * rhs->r + lhs->e1 * rhs->e2 
          + lhs->e2 * rhs->e1;
  res->e13 = lhs->r * rhs->e13 + lhs->e13 * rhs->r + lhs->e1 * rhs->e3 
          + lhs->e3 * rhs->e1;
  res->e23 = lhs->r * rhs->e23 + lhs->e23 * rhs->r + lhs->e2 * rhs->e3 
          + lhs->e3 * rhs->e2;
  // Order 3;
  res->e123 = lhs->r * rhs->e123 + lhs->e123 * rhs->r + lhs->e1 * rhs->e23 
           + lhs->e23 * rhs->e1 + lhs->e2 * rhs->e13 + lhs->e13 * rhs->e2 
           + lhs->e3 * rhs->e12 + lhs->e12 * rhs->e3;

}

mdnum3_t mdnum3_mul_ro(  coeff_t lhs,  mdnum3_t* rhs){
  mdnum3_t res;

  // Multiplication like function 'lhs * rhs'
  //  Real;
  res.r = lhs * rhs->r;
  // Order 1;
  res.e1 = lhs * rhs->e1;
  res.e2 = lhs * rhs->e2;
  res.e3 = lhs * rhs->e3;
  // Order 2;
  res.e12 = lhs * rhs->e12;
  res.e13 = lhs * rhs->e13;
  res.e23 = lhs * rhs->e23;
  // Order 3;
  res.e123 = lhs * rhs->e123;

  return res;

}

void mdnum3_mul_ro_to(  coeff_t lhs,  mdnum3_t* rhs, mdnum3_t* res){
  // Multiplication like function 'lhs * rhs'
  //  Real;
  res->r = lhs * rhs->r;
  // Order 1;
  res->e1 = lhs * rhs->e1;
  res->e2 = lhs * rhs->e2;
  res->e3 = lhs * rhs->e3;
  // Order 2;
  res->e12 = lhs * rhs->e12;
  res->e13 = lhs * rhs->e13;
  res->e23 = lhs * rhs->e23;
  // Order 3;
  res->e123 = lhs * rhs->e123;

}

mdnum3_t mdnum3_trunc_mul_oo(  mdnum3_t* lhs,  mdnum3_t* rhs){
  mdnum3_t res;

  res = mdnum3_init();

  //  Truncated multiplication like function 'lhs * rhs'
  // Order 2;
  res.e12 =  + lhs->e1 * rhs->e2 + lhs->e2 * rhs->e1;
  res.e13 =  + lhs->e1 * rhs->e3 + lhs->e3 * rhs->e1;
  res.e23 =  + lhs->e2 * rhs->e3 + lhs->e3 * rhs->e2;
  // Order 3;
  res.e123 =  + lhs->e1 * rhs->e23 + lhs->e23 * rhs->e1 + lhs->e2 * rhs->e13 
           + lhs->e13 * rhs->e2 + lhs->e3 * rhs->e12 + lhs->e12 * rhs->e3;

  return res;

}

void mdnum3_trunc_mul_oo_to(  mdnum3_t* lhs,  mdnum3_t* rhs, mdnum3_t* res){
   (*res) = mdnum3_init();

  //  Truncated multiplication like function 'lhs * rhs'
  // Order 2;
  res->e12 =  + lhs->e1 * rhs->e2 + lhs->e2 * rhs->e1;
  res->e13 =  + lhs->e1 * rhs->e3 + lhs->e3 * rhs->e1;
  res->e23 =  + lhs->e2 * rhs->e3 + lhs->e3 * rhs->e2;
  // Order 3;
  res->e123 =  + lhs->e1 * rhs->e23 + lhs->e23 * rhs->e1 + lhs->e2 * rhs->e13 
           + lhs->e13 * rhs->e2 + lhs->e3 * rhs->e12 + lhs->e12 * rhs->e3;

}

mdnum3_t mdnum3_gem_oo(  mdnum3_t* a,  mdnum3_t* b,  mdnum3_t* c){
  mdnum3_t res;

  //  General multiplication like function 'a * b + c'
  // Real;
  res.r = c->r + a->r * b->r;
  // Order 1;
  res.e1 = c->e1 + a->r * b->e1 + a->e1 * b->r;
  res.e2 = c->e2 + a->r * b->e2 + a->e2 * b->r;
  res.e3 = c->e3 + a->r * b->e3 + a->e3 * b->r;
  // Order 2;
  res.e12 = c->e12 + a->r * b->e12 + a->e12 * b->r + a->e1 * b->e2 
          + a->e2 * b->e1;
  res.e13 = c->e13 + a->r * b->e13 + a->e13 * b->r + a->e1 * b->e3 
          + a->e3 * b->e1;
  res.e23 = c->e23 + a->r * b->e23 + a->e23 * b->r + a->e2 * b->e3 
          + a->e3 * b->e2;
  // Order 3;
  res.e123 = c->e123 + a->r * b->e123 + a->e123 * b->r + a->e1 * b->e23 
           + a->e23 * b->e1 + a->e2 * b->e13 + a->e13 * b->e2 
           + a->e3 * b->e12 + a->e12 * b->e3;

  return res;

}

void mdnum3_gem_oo_to(  mdnum3_t* a,  mdnum3_t* b,  mdnum3_t* c, mdnum3_t* res){
  //  General multiplication like function 'a * b + c'
  // Real;
  res->r = c->r + a->r * b->r;
  // Order 1;
  res->e1 = c->e1 + a->r * b->e1 + a->e1 * b->r;
  res->e2 = c->e2 + a->r * b->e2 + a->e2 * b->r;
  res->e3 = c->e3 + a->r * b->e3 + a->e3 * b->r;
  // Order 2;
  res->e12 = c->e12 + a->r * b->e12 + a->e12 * b->r + a->e1 * b->e2 
          + a->e2 * b->e1;
  res->e13 = c->e13 + a->r * b->e13 + a->e13 * b->r + a->e1 * b->e3 
          + a->e3 * b->e1;
  res->e23 = c->e23 + a->r * b->e23 + a->e23 * b->r + a->e2 * b->e3 
          + a->e3 * b->e2;
  // Order 3;
  res->e123 = c->e123 + a->r * b->e123 + a->e123 * b->r + a->e1 * b->e23 
           + a->e23 * b->e1 + a->e2 * b->e13 + a->e13 * b->e2 
           + a->e3 * b->e12 + a->e12 * b->e3;

}

mdnum3_t mdnum3_gem_ro(  coeff_t a,  mdnum3_t* b,  mdnum3_t* c){
  mdnum3_t res;

  //  General multiplication like function 'a * b + c'
  // Real;
  res.r = c->r + a * b->r;
  // Order 1;
  res.e1 = c->e1 + a * b->e1;
  res.e2 = c->e2 + a * b->e2;
  res.e3 = c->e3 + a * b->e3;
  // Order 2;
  res.e12 = c->e12 + a * b->e12;
  res.e13 = c->e13 + a * b->e13;
  res.e23 = c->e23 + a * b->e23;
  // Order 3;
  res.e123 = c->e123 + a * b->e123;

  return res;

}

void mdnum3_gem_ro_to(  coeff_t a,  mdnum3_t* b,  mdnum3_t* c, mdnum3_t* res){
  //  General multiplication like function 'a * b + c'
  // Real;
  res->r = c->r + a * b->r;
  // Order 1;
  res->e1 = c->e1 + a * b->e1;
  res->e2 = c->e2 + a * b->e2;
  res->e3 = c->e3 + a * b->e3;
  // Order 2;
  res->e12 = c->e12 + a * b->e12;
  res->e13 = c->e13 + a * b->e13;
  res->e23 = c->e23 + a * b->e23;
  // Order 3;
  res->e123 = c->e123 + a * b->e123;

}

mdnum3_t mdnum3_feval(coeff_t* feval_re, mdnum3_t* x){

  mdnum3_t res;

  // feval function
  //  Definitions
  coeff_t factor=1, coef = 0;
  mdnum3_t tmp1, tmp2, deltax = (*x), deltax_power = (*x);
  deltax.r = 0.0;
  deltax_power.r = 0.0;
  mdnum3_set_r_to(0.0, &res);
  //  Real
  res.r = feval_re[0];
  // Order 1
  factor *=1;
  coef    = feval_re[1]/ factor;;
  mdnum3_gem_ro_to( coef, &deltax_power, &res, &res);
  deltax_power = mdnum3_mul_oo(&deltax_power,&deltax);
  // Order 2
  factor *=2;
  coef    = feval_re[2]/ factor;;
  mdnum3_gem_ro_to( coef, &deltax_power, &res, &res);
  deltax_power = mdnum3_mul_oo(&deltax_power,&deltax);
  // Order 3
  factor *=3;
  coef    = feval_re[3]/ factor;;
  mdnum3_gem_ro_to( coef, &deltax_power, &res, &res);

  return res;

}

void mdnum3_feval_to(coeff_t* feval_re, mdnum3_t* x, mdnum3_t* res){

  // feval function
  //  Definitions
  coeff_t factor=1, coef = 0;
  mdnum3_t tmp1, tmp2, deltax = (*x), deltax_power = (*x);
  deltax.r = 0.0;
  deltax_power.r = 0.0;
  mdnum3_set_r_to(0.0, res);
  //  Real
  res->r = feval_re[0];
  // Order 1
  factor *=1;
  coef    = feval_re[1]/ factor;;
  mdnum3_gem_ro_to( coef, &deltax_power, res, res);
  deltax_power = mdnum3_mul_oo(&deltax_power,&deltax);
  // Order 2
  factor *=2;
  coef    = feval_re[2]/ factor;;
  mdnum3_gem_ro_to( coef, &deltax_power, res, res);
  deltax_power = mdnum3_mul_oo(&deltax_power,&deltax);
  // Order 3
  factor *=3;
  coef    = feval_re[3]/ factor;;
  mdnum3_gem_ro_to( coef, &deltax_power, res, res);

}

