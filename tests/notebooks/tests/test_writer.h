#ifndef TEST_WRITER__H
#define TEST_WRITER__H

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
  coeff_t e3;
  // Order 2
  coeff_t e12;
  coeff_t e13;
  coeff_t e23;
  // Order 3
  coeff_t e123;
} mdnum3_t;

// Array
typedef struct {
  // Data
  mdnum3_t* p_data;
  uint64_t nrows;
  uint64_t ncols;
  uint64_t size ;
} mdarr3_t;

// Gauss Scalar
typedef struct {
  // Data
  mdnum3_t* p_data;
  uint64_t nip;
} femdnum3_t;

// Gauss Array
typedef struct {
  // Data
  mdarr3_t* p_data;
  uint64_t nrows;
  uint64_t ncols;
  uint64_t size ;
  uint64_t nip  ;
} femdarr3_t;


mdnum3_t mdnum3_init();
mdnum3_t mdnum3_create_r(  coeff_t lhs);
void mdnum3_set_r_to(  coeff_t lhs, mdnum3_t* res);
void mdnum3_set_o_to(  mdnum3_t* lhs, mdnum3_t* res);
coeff_t mdnum3_get_item(imdir_t idx, ord_t order, mdnum3_t* lhs);
mdnum3_t mdnum3_copy(  mdnum3_t* lhs);
void mdnum3_copy_to(  mdnum3_t* lhs, mdnum3_t* res);
void mdnum3_print(  mdnum3_t* lhs);
mdnum3_t mdnum3_neg(  mdnum3_t* lhs);
void mdnum3_neg_to(  mdnum3_t* lhs, mdnum3_t* res);
mdnum3_t mdnum3_add_oo(  mdnum3_t* lhs,  mdnum3_t* rhs);
void mdnum3_add_oo_to(  mdnum3_t* lhs,  mdnum3_t* rhs, mdnum3_t* res);
mdnum3_t mdnum3_add_ro(  coeff_t lhs,  mdnum3_t* rhs);
void mdnum3_add_ro_to(  coeff_t lhs,  mdnum3_t* rhs, mdnum3_t* res);
mdnum3_t mdnum3_sub_oo(  mdnum3_t lhs,  mdnum3_t* rhs);
void mdnum3_sub_oo_to(  mdnum3_t lhs,  mdnum3_t* rhs, mdnum3_t* res);
mdnum3_t mdnum3_sub_ro(  coeff_t lhs,  mdnum3_t* rhs);
void mdnum3_sub_ro_to(  coeff_t lhs,  mdnum3_t* rhs, mdnum3_t* res);
mdnum3_t mdnum3_sub_or(  mdnum3_t* lhs,  coeff_t rhs);
void mdnum3_sub_or_to(  mdnum3_t* lhs,  coeff_t rhs, mdnum3_t* res);
mdnum3_t mdnum3_mul_oo(  mdnum3_t* lhs,  mdnum3_t* rhs);
void mdnum3_mul_oo_to(  mdnum3_t* lhs,  mdnum3_t* rhs, mdnum3_t* res);
mdnum3_t mdnum3_mul_ro(  coeff_t lhs,  mdnum3_t* rhs);
void mdnum3_mul_ro_to(  coeff_t lhs,  mdnum3_t* rhs, mdnum3_t* res);
mdnum3_t mdnum3_trunc_mul_oo(  mdnum3_t* lhs,  mdnum3_t* rhs);
void mdnum3_trunc_mul_oo_to(  mdnum3_t* lhs,  mdnum3_t* rhs, mdnum3_t* res);
mdnum3_t mdnum3_gem_oo(  mdnum3_t* a,  mdnum3_t* b,  mdnum3_t* c);
void mdnum3_gem_oo_to(  mdnum3_t* a,  mdnum3_t* b,  mdnum3_t* c, mdnum3_t* res);
mdnum3_t mdnum3_gem_ro(  coeff_t a,  mdnum3_t* b,  mdnum3_t* c);
void mdnum3_gem_ro_to(  coeff_t a,  mdnum3_t* b,  mdnum3_t* c, mdnum3_t* res);
mdnum3_t mdnum3_feval(coeff_t* feval_re, mdnum3_t* x);
void mdnum3_feval_to(coeff_t* feval_re, mdnum3_t* x, mdnum3_t* res);

#endif