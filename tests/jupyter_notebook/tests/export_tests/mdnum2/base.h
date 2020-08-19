#ifndef MDNUM2__H
#define MDNUM2__H

//  Dependencies
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<stdint.h>
#include<inttypes.h>
#include<math.h>

typedef uint8_t ord_t;
typedef uint64_t imdir_t ;
typedef double coeff_t ;
// Scalar
typedef struct {
  // Real
  coeff_t r;
  // Order 1
  coeff_t e1;
  coeff_t e2;
  // Order 2
  coeff_t e12;
} mdnum2_t;


mdnum2_t mdnum2_init();
mdnum2_t mdnum2_create_r(  coeff_t lhs);
void mdnum2_set_r_to(  coeff_t lhs, mdnum2_t* res);
void mdnum2_set_o_to(  mdnum2_t* lhs, mdnum2_t* res);
coeff_t mdnum2_get_item(imdir_t idx, ord_t order, mdnum2_t* lhs);
void mdnum2_set_item(coeff_t val, imdir_t idx, ord_t order, mdnum2_t* x);
mdnum2_t mdnum2_copy(  mdnum2_t* lhs);
void mdnum2_copy_to(  mdnum2_t* lhs, mdnum2_t* res);
void mdnum2_print(  mdnum2_t* lhs);
mdnum2_t mdnum2_neg(  mdnum2_t* lhs);
void mdnum2_neg_to(  mdnum2_t* lhs, mdnum2_t* res);
mdnum2_t mdnum2_add_oo(  mdnum2_t* lhs,  mdnum2_t* rhs);
void mdnum2_add_oo_to(  mdnum2_t* lhs,  mdnum2_t* rhs, mdnum2_t* res);
mdnum2_t mdnum2_add_ro(  coeff_t lhs,  mdnum2_t* rhs);
void mdnum2_add_ro_to(  coeff_t lhs,  mdnum2_t* rhs, mdnum2_t* res);
mdnum2_t mdnum2_sub_oo(  mdnum2_t lhs,  mdnum2_t* rhs);
void mdnum2_sub_oo_to(  mdnum2_t lhs,  mdnum2_t* rhs, mdnum2_t* res);
mdnum2_t mdnum2_sub_ro(  coeff_t lhs,  mdnum2_t* rhs);
void mdnum2_sub_ro_to(  coeff_t lhs,  mdnum2_t* rhs, mdnum2_t* res);
mdnum2_t mdnum2_sub_or(  mdnum2_t* lhs,  coeff_t rhs);
void mdnum2_sub_or_to(  mdnum2_t* lhs,  coeff_t rhs, mdnum2_t* res);
mdnum2_t mdnum2_mul_oo(  mdnum2_t* lhs,  mdnum2_t* rhs);
void mdnum2_mul_oo_to(  mdnum2_t* lhs,  mdnum2_t* rhs, mdnum2_t* res);
mdnum2_t mdnum2_mul_ro(  coeff_t lhs,  mdnum2_t* rhs);
void mdnum2_mul_ro_to(  coeff_t lhs,  mdnum2_t* rhs, mdnum2_t* res);
mdnum2_t mdnum2_trunc_mul_oo(  mdnum2_t* lhs,  mdnum2_t* rhs);
void mdnum2_trunc_mul_oo_to(  mdnum2_t* lhs,  mdnum2_t* rhs, mdnum2_t* res);
mdnum2_t mdnum2_gem_oo(  mdnum2_t* a,  mdnum2_t* b,  mdnum2_t* c);
void mdnum2_gem_oo_to(  mdnum2_t* a,  mdnum2_t* b,  mdnum2_t* c, mdnum2_t* res);
mdnum2_t mdnum2_gem_ro(  coeff_t a,  mdnum2_t* b,  mdnum2_t* c);
void mdnum2_gem_ro_to(  coeff_t a,  mdnum2_t* b,  mdnum2_t* c, mdnum2_t* res);
mdnum2_t mdnum2_feval(coeff_t* feval_re, mdnum2_t* x);
void mdnum2_feval_to(coeff_t* feval_re, mdnum2_t* x, mdnum2_t* res);
mdnum2_t mdnum2_init();
mdnum2_t mdnum2_create_r(  coeff_t lhs);
void mdnum2_set_r_to(  coeff_t lhs, mdnum2_t* res);
void mdnum2_set_o_to(  mdnum2_t* lhs, mdnum2_t* res);
coeff_t mdnum2_get_item(imdir_t idx, ord_t order, mdnum2_t* lhs);
void mdnum2_set_item(coeff_t val, imdir_t idx, ord_t order, mdnum2_t* x);
mdnum2_t mdnum2_copy(  mdnum2_t* lhs);
void mdnum2_copy_to(  mdnum2_t* lhs, mdnum2_t* res);
void mdnum2_print(  mdnum2_t* lhs);
mdnum2_t mdnum2_neg(  mdnum2_t* lhs);
void mdnum2_neg_to(  mdnum2_t* lhs, mdnum2_t* res);
mdnum2_t mdnum2_add_oo(  mdnum2_t* lhs,  mdnum2_t* rhs);
void mdnum2_add_oo_to(  mdnum2_t* lhs,  mdnum2_t* rhs, mdnum2_t* res);
mdnum2_t mdnum2_add_ro(  coeff_t lhs,  mdnum2_t* rhs);
void mdnum2_add_ro_to(  coeff_t lhs,  mdnum2_t* rhs, mdnum2_t* res);
mdnum2_t mdnum2_sub_oo(  mdnum2_t lhs,  mdnum2_t* rhs);
void mdnum2_sub_oo_to(  mdnum2_t lhs,  mdnum2_t* rhs, mdnum2_t* res);
mdnum2_t mdnum2_sub_ro(  coeff_t lhs,  mdnum2_t* rhs);
void mdnum2_sub_ro_to(  coeff_t lhs,  mdnum2_t* rhs, mdnum2_t* res);
mdnum2_t mdnum2_sub_or(  mdnum2_t* lhs,  coeff_t rhs);
void mdnum2_sub_or_to(  mdnum2_t* lhs,  coeff_t rhs, mdnum2_t* res);
mdnum2_t mdnum2_mul_oo(  mdnum2_t* lhs,  mdnum2_t* rhs);
void mdnum2_mul_oo_to(  mdnum2_t* lhs,  mdnum2_t* rhs, mdnum2_t* res);
mdnum2_t mdnum2_mul_ro(  coeff_t lhs,  mdnum2_t* rhs);
void mdnum2_mul_ro_to(  coeff_t lhs,  mdnum2_t* rhs, mdnum2_t* res);
mdnum2_t mdnum2_trunc_mul_oo(  mdnum2_t* lhs,  mdnum2_t* rhs);
void mdnum2_trunc_mul_oo_to(  mdnum2_t* lhs,  mdnum2_t* rhs, mdnum2_t* res);
mdnum2_t mdnum2_gem_oo(  mdnum2_t* a,  mdnum2_t* b,  mdnum2_t* c);
void mdnum2_gem_oo_to(  mdnum2_t* a,  mdnum2_t* b,  mdnum2_t* c, mdnum2_t* res);
mdnum2_t mdnum2_gem_ro(  coeff_t a,  mdnum2_t* b,  mdnum2_t* c);
void mdnum2_gem_ro_to(  coeff_t a,  mdnum2_t* b,  mdnum2_t* c, mdnum2_t* res);
mdnum2_t mdnum2_feval(coeff_t* feval_re, mdnum2_t* x);
void mdnum2_feval_to(coeff_t* feval_re, mdnum2_t* x, mdnum2_t* res);

#endif