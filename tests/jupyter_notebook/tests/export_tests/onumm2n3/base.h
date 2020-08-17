#ifndef ONUMM2N3__H
#define ONUMM2N3__H

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
  coeff_t e11;
  coeff_t e12;
  coeff_t e22;
  // Order 3
  coeff_t e111;
  coeff_t e112;
  coeff_t e122;
  coeff_t e222;
} onumm2n3_t;

// Array
typedef struct {
  // Data
  onumm2n3_t* p_data;
  uint64_t nrows;
  uint64_t ncols;
  uint64_t size ;
} oarrm2n3_t;

// Gauss Scalar
typedef struct {
  // Data
  onumm2n3_t* p_data;
  uint64_t nip;
} feonumm2n3_t;

// Gauss Array
typedef struct {
  // Data
  oarrm2n3_t* p_data;
  uint64_t nrows;
  uint64_t ncols;
  uint64_t size ;
  uint64_t nip  ;
} feoarrm2n3_t;


onumm2n3_t onumm2n3_init();
onumm2n3_t onumm2n3_create_r(  coeff_t lhs);
void onumm2n3_set_r_to(  coeff_t lhs, onumm2n3_t* res);
void onumm2n3_set_o_to(  onumm2n3_t* lhs, onumm2n3_t* res);
coeff_t onumm2n3_get_item(imdir_t idx, ord_t order, onumm2n3_t* lhs);
void onumm2n3_set_item(coeff_t val, imdir_t idx, ord_t order, onumm2n3_t* x);
onumm2n3_t onumm2n3_copy(  onumm2n3_t* lhs);
void onumm2n3_copy_to(  onumm2n3_t* lhs, onumm2n3_t* res);
void onumm2n3_print(  onumm2n3_t* lhs);
onumm2n3_t onumm2n3_neg(  onumm2n3_t* lhs);
void onumm2n3_neg_to(  onumm2n3_t* lhs, onumm2n3_t* res);
onumm2n3_t onumm2n3_add_oo(  onumm2n3_t* lhs,  onumm2n3_t* rhs);
void onumm2n3_add_oo_to(  onumm2n3_t* lhs,  onumm2n3_t* rhs, onumm2n3_t* res);
onumm2n3_t onumm2n3_add_ro(  coeff_t lhs,  onumm2n3_t* rhs);
void onumm2n3_add_ro_to(  coeff_t lhs,  onumm2n3_t* rhs, onumm2n3_t* res);
onumm2n3_t onumm2n3_sub_oo(  onumm2n3_t lhs,  onumm2n3_t* rhs);
void onumm2n3_sub_oo_to(  onumm2n3_t lhs,  onumm2n3_t* rhs, onumm2n3_t* res);
onumm2n3_t onumm2n3_sub_ro(  coeff_t lhs,  onumm2n3_t* rhs);
void onumm2n3_sub_ro_to(  coeff_t lhs,  onumm2n3_t* rhs, onumm2n3_t* res);
onumm2n3_t onumm2n3_sub_or(  onumm2n3_t* lhs,  coeff_t rhs);
void onumm2n3_sub_or_to(  onumm2n3_t* lhs,  coeff_t rhs, onumm2n3_t* res);
onumm2n3_t onumm2n3_mul_oo(  onumm2n3_t* lhs,  onumm2n3_t* rhs);
void onumm2n3_mul_oo_to(  onumm2n3_t* lhs,  onumm2n3_t* rhs, onumm2n3_t* res);
onumm2n3_t onumm2n3_mul_ro(  coeff_t lhs,  onumm2n3_t* rhs);
void onumm2n3_mul_ro_to(  coeff_t lhs,  onumm2n3_t* rhs, onumm2n3_t* res);
onumm2n3_t onumm2n3_trunc_mul_oo(  onumm2n3_t* lhs,  onumm2n3_t* rhs);
void onumm2n3_trunc_mul_oo_to(  onumm2n3_t* lhs,  onumm2n3_t* rhs, onumm2n3_t* res);
onumm2n3_t onumm2n3_gem_oo(  onumm2n3_t* a,  onumm2n3_t* b,  onumm2n3_t* c);
void onumm2n3_gem_oo_to(  onumm2n3_t* a,  onumm2n3_t* b,  onumm2n3_t* c, onumm2n3_t* res);
onumm2n3_t onumm2n3_gem_ro(  coeff_t a,  onumm2n3_t* b,  onumm2n3_t* c);
void onumm2n3_gem_ro_to(  coeff_t a,  onumm2n3_t* b,  onumm2n3_t* c, onumm2n3_t* res);
onumm2n3_t onumm2n3_feval(coeff_t* feval_re, onumm2n3_t* x);
void onumm2n3_feval_to(coeff_t* feval_re, onumm2n3_t* x, onumm2n3_t* res);

#endif