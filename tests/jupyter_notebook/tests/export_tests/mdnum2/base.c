#include"mdnum2.h"

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

mdnum2_t mdnum2_neg(  mdnum2_t* lhs){

  mdnum2_t res;

  // Negation like function '-lhs'
  // Real;
  res.r = -lhs->r;
  // Order 1;
  res.e1 = -lhs->e1;
  res.e2 = -lhs->e2;
  // Order 2;
  res.e12 = -lhs->e12;

  return res;

}

void mdnum2_neg_to(  mdnum2_t* lhs, mdnum2_t* res){

  // Negation like function '-lhs'
  // Real;
  res->r = -lhs->r;
  // Order 1;
  res->e1 = -lhs->e1;
  res->e2 = -lhs->e2;
  // Order 2;
  res->e12 = -lhs->e12;

}

mdnum2_t mdnum2_add_oo(  mdnum2_t* lhs,  mdnum2_t* rhs){
  mdnum2_t res;

  // Addition like function 'lhs + rhs'
  //  Real
  res.r = lhs->r + rhs->r;
  // Order 1
  res.e1 = lhs->e1 + rhs->e1;
  res.e2 = lhs->e2 + rhs->e2;
  // Order 2
  res.e12 = lhs->e12 + rhs->e12;

  return res;

}

void mdnum2_add_oo_to(  mdnum2_t* lhs,  mdnum2_t* rhs, mdnum2_t* res){
  // Addition like function 'lhs + rhs'
  //  Real
  res->r = lhs->r + rhs->r;
  // Order 1
  res->e1 = lhs->e1 + rhs->e1;
  res->e2 = lhs->e2 + rhs->e2;
  // Order 2
  res->e12 = lhs->e12 + rhs->e12;

}

mdnum2_t mdnum2_add_ro(  coeff_t lhs,  mdnum2_t* rhs){
  mdnum2_t res;

  // Addition like function 'lhs + rhs'
  // Real;
  res.r = lhs + rhs->r;
  // Order 1;
  res.e1 =  + rhs->e1;
  res.e2 =  + rhs->e2;
  // Order 2;
  res.e12 =  + rhs->e12;

  return res;

}

void mdnum2_add_ro_to(  coeff_t lhs,  mdnum2_t* rhs, mdnum2_t* res){
  // Addition like function 'lhs + rhs'
  // Real;
  res->r = lhs + rhs->r;
  // Order 1;
  res->e1 =  + rhs->e1;
  res->e2 =  + rhs->e2;
  // Order 2;
  res->e12 =  + rhs->e12;

}

mdnum2_t mdnum2_sub_oo(  mdnum2_t lhs,  mdnum2_t* rhs){
  mdnum2_t res;

  // Addition like function 'lhs - rhs'
  //  Real
  res.r = lhs.r - rhs->r;
  // Order 1
  res.e1 = lhs.e1 - rhs->e1;
  res.e2 = lhs.e2 - rhs->e2;
  // Order 2
  res.e12 = lhs.e12 - rhs->e12;

  return res;

}

void mdnum2_sub_oo_to(  mdnum2_t lhs,  mdnum2_t* rhs, mdnum2_t* res){
  // Addition like function 'lhs - rhs'
  //  Real
  res->r = lhs.r - rhs->r;
  // Order 1
  res->e1 = lhs.e1 - rhs->e1;
  res->e2 = lhs.e2 - rhs->e2;
  // Order 2
  res->e12 = lhs.e12 - rhs->e12;

}

mdnum2_t mdnum2_sub_ro(  coeff_t lhs,  mdnum2_t* rhs){
  mdnum2_t res;

  // Addition like function 'lhs - rhs'
  // Real;
  res.r = lhs - rhs->r;
  // Order 1;
  res.e1 =  - rhs->e1;
  res.e2 =  - rhs->e2;
  // Order 2;
  res.e12 =  - rhs->e12;

  return res;

}

void mdnum2_sub_ro_to(  coeff_t lhs,  mdnum2_t* rhs, mdnum2_t* res){
  // Addition like function 'lhs - rhs'
  // Real;
  res->r = lhs - rhs->r;
  // Order 1;
  res->e1 =  - rhs->e1;
  res->e2 =  - rhs->e2;
  // Order 2;
  res->e12 =  - rhs->e12;

}

mdnum2_t mdnum2_sub_or(  mdnum2_t* lhs,  coeff_t rhs){
  mdnum2_t res;

  // Addition like function 'lhs - rhs'
  // Real;
  res.r = lhs->r - rhs;
  // Order 1;
  res.e1 = lhs->e1;
  res.e2 = lhs->e2;
  // Order 2;
  res.e12 = lhs->e12;

  return res;

}

void mdnum2_sub_or_to(  mdnum2_t* lhs,  coeff_t rhs, mdnum2_t* res){
  // Addition like function 'lhs - rhs'
  // Real;
  res->r = lhs->r - rhs;
  // Order 1;
  res->e1 = lhs->e1;
  res->e2 = lhs->e2;
  // Order 2;
  res->e12 = lhs->e12;

}

mdnum2_t mdnum2_mul_oo(  mdnum2_t* lhs,  mdnum2_t* rhs){
  mdnum2_t res;

  //  Multiplication like function 'lhs * rhs'
  // Real;
  res.r = lhs->r * rhs->r;
  // Order 1;
  res.e1 = lhs->r * rhs->e1 + lhs->e1 * rhs->r;
  res.e2 = lhs->r * rhs->e2 + lhs->e2 * rhs->r;
  // Order 2;
  res.e12 = lhs->r * rhs->e12 + lhs->e12 * rhs->r + lhs->e1 * rhs->e2 
          + lhs->e2 * rhs->e1;

  return res;

}

void mdnum2_mul_oo_to(  mdnum2_t* lhs,  mdnum2_t* rhs, mdnum2_t* res){
  //  Multiplication like function 'lhs * rhs'
  // Real;
  res->r = lhs->r * rhs->r;
  // Order 1;
  res->e1 = lhs->r * rhs->e1 + lhs->e1 * rhs->r;
  res->e2 = lhs->r * rhs->e2 + lhs->e2 * rhs->r;
  // Order 2;
  res->e12 = lhs->r * rhs->e12 + lhs->e12 * rhs->r + lhs->e1 * rhs->e2 
          + lhs->e2 * rhs->e1;

}

mdnum2_t mdnum2_mul_ro(  coeff_t lhs,  mdnum2_t* rhs){
  mdnum2_t res;

  // Multiplication like function 'lhs * rhs'
  //  Real;
  res.r = lhs * rhs->r;
  // Order 1;
  res.e1 = lhs * rhs->e1;
  res.e2 = lhs * rhs->e2;
  // Order 2;
  res.e12 = lhs * rhs->e12;

  return res;

}

void mdnum2_mul_ro_to(  coeff_t lhs,  mdnum2_t* rhs, mdnum2_t* res){
  // Multiplication like function 'lhs * rhs'
  //  Real;
  res->r = lhs * rhs->r;
  // Order 1;
  res->e1 = lhs * rhs->e1;
  res->e2 = lhs * rhs->e2;
  // Order 2;
  res->e12 = lhs * rhs->e12;

}

mdnum2_t mdnum2_trunc_mul_oo(  mdnum2_t* lhs,  mdnum2_t* rhs){
  mdnum2_t res;

  res = mdnum2_init();

  //  Truncated multiplication like function 'lhs * rhs'
  // Order 2;
  res.e12 =  + lhs->e1 * rhs->e2 + lhs->e2 * rhs->e1;

  return res;

}

void mdnum2_trunc_mul_oo_to(  mdnum2_t* lhs,  mdnum2_t* rhs, mdnum2_t* res){
   (*res) = mdnum2_init();

  //  Truncated multiplication like function 'lhs * rhs'
  // Order 2;
  res->e12 =  + lhs->e1 * rhs->e2 + lhs->e2 * rhs->e1;

}

mdnum2_t mdnum2_gem_oo(  mdnum2_t* a,  mdnum2_t* b,  mdnum2_t* c){
  mdnum2_t res;

  //  General multiplication like function 'a * b + c'
  // Real;
  res.r = c->r + a->r * b->r;
  // Order 1;
  res.e1 = c->e1 + a->r * b->e1 + a->e1 * b->r;
  res.e2 = c->e2 + a->r * b->e2 + a->e2 * b->r;
  // Order 2;
  res.e12 = c->e12 + a->r * b->e12 + a->e12 * b->r + a->e1 * b->e2 
          + a->e2 * b->e1;

  return res;

}

void mdnum2_gem_oo_to(  mdnum2_t* a,  mdnum2_t* b,  mdnum2_t* c, mdnum2_t* res){
  //  General multiplication like function 'a * b + c'
  // Real;
  res->r = c->r + a->r * b->r;
  // Order 1;
  res->e1 = c->e1 + a->r * b->e1 + a->e1 * b->r;
  res->e2 = c->e2 + a->r * b->e2 + a->e2 * b->r;
  // Order 2;
  res->e12 = c->e12 + a->r * b->e12 + a->e12 * b->r + a->e1 * b->e2 
          + a->e2 * b->e1;

}

mdnum2_t mdnum2_gem_ro(  coeff_t a,  mdnum2_t* b,  mdnum2_t* c){
  mdnum2_t res;

  //  General multiplication like function 'a * b + c'
  // Real;
  res.r = c->r + a * b->r;
  // Order 1;
  res.e1 = c->e1 + a * b->e1;
  res.e2 = c->e2 + a * b->e2;
  // Order 2;
  res.e12 = c->e12 + a * b->e12;

  return res;

}

void mdnum2_gem_ro_to(  coeff_t a,  mdnum2_t* b,  mdnum2_t* c, mdnum2_t* res){
  //  General multiplication like function 'a * b + c'
  // Real;
  res->r = c->r + a * b->r;
  // Order 1;
  res->e1 = c->e1 + a * b->e1;
  res->e2 = c->e2 + a * b->e2;
  // Order 2;
  res->e12 = c->e12 + a * b->e12;

}

mdnum2_t mdnum2_feval(coeff_t* feval_re, mdnum2_t* x){

  mdnum2_t res;

  // feval function
  //  Definitions
  coeff_t factor=1, coef = 0;
  mdnum2_t tmp1, tmp2, deltax = (*x), deltax_power = (*x);
  deltax.r = 0.0;
  deltax_power.r = 0.0;
  mdnum2_set_r_to(0.0, &res);
  //  Real
  res.r = feval_re[0];
  // Order 1
  factor *=1;
  coef    = feval_re[1]/ factor;;
  mdnum2_gem_ro_to( coef, &deltax_power, &res, &res);
  deltax_power = mdnum2_mul_oo(&deltax_power,&deltax);
  // Order 2
  factor *=2;
  coef    = feval_re[2]/ factor;;
  mdnum2_gem_ro_to( coef, &deltax_power, &res, &res);

  return res;

}

void mdnum2_feval_to(coeff_t* feval_re, mdnum2_t* x, mdnum2_t* res){

  // feval function
  //  Definitions
  coeff_t factor=1, coef = 0;
  mdnum2_t tmp1, tmp2, deltax = (*x), deltax_power = (*x);
  deltax.r = 0.0;
  deltax_power.r = 0.0;
  mdnum2_set_r_to(0.0, res);
  //  Real
  res->r = feval_re[0];
  // Order 1
  factor *=1;
  coef    = feval_re[1]/ factor;;
  mdnum2_gem_ro_to( coef, &deltax_power, res, res);
  deltax_power = mdnum2_mul_oo(&deltax_power,&deltax);
  // Order 2
  factor *=2;
  coef    = feval_re[2]/ factor;;
  mdnum2_gem_ro_to( coef, &deltax_power, res, res);

}

