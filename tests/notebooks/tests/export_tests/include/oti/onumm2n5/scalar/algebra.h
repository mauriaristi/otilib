#ifndef OTI_ONUMM2N5_SCALAR_ALGEBRA_H
#define OTI_ONUMM2N5_SCALAR_ALGEBRA_H

onumm2n5_t onumm2n5_neg(  onumm2n5_t* lhs);
void onumm2n5_neg_to(  onumm2n5_t* lhs, onumm2n5_t* res);
onumm2n5_t onumm2n5_add_oo(  onumm2n5_t* lhs,  onumm2n5_t* rhs);
void onumm2n5_add_oo_to(  onumm2n5_t* lhs,  onumm2n5_t* rhs, onumm2n5_t* res);
onumm2n5_t onumm2n5_add_ro(  coeff_t lhs,  onumm2n5_t* rhs);
void onumm2n5_add_ro_to(  coeff_t lhs,  onumm2n5_t* rhs, onumm2n5_t* res);
onumm2n5_t onumm2n5_sub_oo(  onumm2n5_t lhs,  onumm2n5_t* rhs);
void onumm2n5_sub_oo_to(  onumm2n5_t lhs,  onumm2n5_t* rhs, onumm2n5_t* res);
onumm2n5_t onumm2n5_sub_ro(  coeff_t lhs,  onumm2n5_t* rhs);
void onumm2n5_sub_ro_to(  coeff_t lhs,  onumm2n5_t* rhs, onumm2n5_t* res);
onumm2n5_t onumm2n5_sub_or(  onumm2n5_t* lhs,  coeff_t rhs);
void onumm2n5_sub_or_to(  onumm2n5_t* lhs,  coeff_t rhs, onumm2n5_t* res);
onumm2n5_t onumm2n5_mul_oo(  onumm2n5_t* lhs,  onumm2n5_t* rhs);
void onumm2n5_mul_oo_to(  onumm2n5_t* lhs,  onumm2n5_t* rhs, onumm2n5_t* res);
onumm2n5_t onumm2n5_mul_ro(  coeff_t lhs,  onumm2n5_t* rhs);
void onumm2n5_mul_ro_to(  coeff_t lhs,  onumm2n5_t* rhs, onumm2n5_t* res);
onumm2n5_t onumm2n5_trunc_mul_oo(  onumm2n5_t* lhs,  onumm2n5_t* rhs);
void onumm2n5_trunc_mul_oo_to(  onumm2n5_t* lhs,  onumm2n5_t* rhs, onumm2n5_t* res);
onumm2n5_t onumm2n5_gem_oo(  onumm2n5_t* a,  onumm2n5_t* b,  onumm2n5_t* c);
void onumm2n5_gem_oo_to(  onumm2n5_t* a,  onumm2n5_t* b,  onumm2n5_t* c, onumm2n5_t* res);
onumm2n5_t onumm2n5_gem_ro(  coeff_t a,  onumm2n5_t* b,  onumm2n5_t* c);
void onumm2n5_gem_ro_to(  coeff_t a,  onumm2n5_t* b,  onumm2n5_t* c, onumm2n5_t* res);
onumm2n5_t onumm2n5_feval(coeff_t* feval_re, onumm2n5_t* x);
void onumm2n5_feval_to(coeff_t* feval_re, onumm2n5_t* x, onumm2n5_t* res);
onumm2n5_t onumm2n5_neg(  onumm2n5_t* lhs);
void onumm2n5_neg_to(  onumm2n5_t* lhs, onumm2n5_t* res);
onumm2n5_t onumm2n5_add_oo(  onumm2n5_t* lhs,  onumm2n5_t* rhs);
void onumm2n5_add_oo_to(  onumm2n5_t* lhs,  onumm2n5_t* rhs, onumm2n5_t* res);
onumm2n5_t onumm2n5_add_ro(  coeff_t lhs,  onumm2n5_t* rhs);
void onumm2n5_add_ro_to(  coeff_t lhs,  onumm2n5_t* rhs, onumm2n5_t* res);
onumm2n5_t onumm2n5_sub_oo(  onumm2n5_t lhs,  onumm2n5_t* rhs);
void onumm2n5_sub_oo_to(  onumm2n5_t lhs,  onumm2n5_t* rhs, onumm2n5_t* res);
onumm2n5_t onumm2n5_sub_ro(  coeff_t lhs,  onumm2n5_t* rhs);
void onumm2n5_sub_ro_to(  coeff_t lhs,  onumm2n5_t* rhs, onumm2n5_t* res);
onumm2n5_t onumm2n5_sub_or(  onumm2n5_t* lhs,  coeff_t rhs);
void onumm2n5_sub_or_to(  onumm2n5_t* lhs,  coeff_t rhs, onumm2n5_t* res);
onumm2n5_t onumm2n5_mul_oo(  onumm2n5_t* lhs,  onumm2n5_t* rhs);
void onumm2n5_mul_oo_to(  onumm2n5_t* lhs,  onumm2n5_t* rhs, onumm2n5_t* res);
onumm2n5_t onumm2n5_mul_ro(  coeff_t lhs,  onumm2n5_t* rhs);
void onumm2n5_mul_ro_to(  coeff_t lhs,  onumm2n5_t* rhs, onumm2n5_t* res);
onumm2n5_t onumm2n5_trunc_mul_oo(  onumm2n5_t* lhs,  onumm2n5_t* rhs);
void onumm2n5_trunc_mul_oo_to(  onumm2n5_t* lhs,  onumm2n5_t* rhs, onumm2n5_t* res);
onumm2n5_t onumm2n5_gem_oo(  onumm2n5_t* a,  onumm2n5_t* b,  onumm2n5_t* c);
void onumm2n5_gem_oo_to(  onumm2n5_t* a,  onumm2n5_t* b,  onumm2n5_t* c, onumm2n5_t* res);
onumm2n5_t onumm2n5_gem_ro(  coeff_t a,  onumm2n5_t* b,  onumm2n5_t* c);
void onumm2n5_gem_ro_to(  coeff_t a,  onumm2n5_t* b,  onumm2n5_t* c, onumm2n5_t* res);
onumm2n5_t onumm2n5_feval(coeff_t* feval_re, onumm2n5_t* x);
void onumm2n5_feval_to(coeff_t* feval_re, onumm2n5_t* x, onumm2n5_t* res);


#endif