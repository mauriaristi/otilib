#ifndef OTI_ONUMM1N5_SCALAR_ALGEBRA_H
#define OTI_ONUMM1N5_SCALAR_ALGEBRA_H

onumm1n5_t onumm1n5_abs(onumm1n5_t* num);
onumm1n5_t onumm1n5_div_ro(coeff_t num, onumm1n5_t* den);
onumm1n5_t onumm1n5_div_oo(onumm1n5_t* num, onumm1n5_t* den);
onumm1n5_t onumm1n5_div_or(onumm1n5_t* num, coeff_t val);
void onumm1n5_div_ro_to(coeff_t num, onumm1n5_t* den, onumm1n5_t* res);
void onumm1n5_div_oo_to(onumm1n5_t* num, onumm1n5_t* den, onumm1n5_t* res);
void onumm1n5_div_or_to(onumm1n5_t* num, coeff_t val, onumm1n5_t* res);
void onumm1n5_abs_to(onumm1n5_t* num, onumm1n5_t* res);

onumm1n5_t onumm1n5_neg(  onumm1n5_t* lhs);
void onumm1n5_neg_to(  onumm1n5_t* lhs, onumm1n5_t* res);
onumm1n5_t onumm1n5_sum_oo(  onumm1n5_t* lhs,  onumm1n5_t* rhs);
void onumm1n5_sum_oo_to(  onumm1n5_t* lhs,  onumm1n5_t* rhs, onumm1n5_t* res);
onumm1n5_t onumm1n5_sum_ro(  coeff_t lhs,  onumm1n5_t* rhs);
void onumm1n5_sum_ro_to(  coeff_t lhs,  onumm1n5_t* rhs, onumm1n5_t* res);
onumm1n5_t onumm1n5_sub_oo(  onumm1n5_t* lhs,  onumm1n5_t* rhs);
void onumm1n5_sub_oo_to(  onumm1n5_t* lhs,  onumm1n5_t* rhs, onumm1n5_t* res);
onumm1n5_t onumm1n5_sub_ro(  coeff_t lhs,  onumm1n5_t* rhs);
void onumm1n5_sub_ro_to(  coeff_t lhs,  onumm1n5_t* rhs, onumm1n5_t* res);
onumm1n5_t onumm1n5_sub_or(  onumm1n5_t* lhs,  coeff_t rhs);
void onumm1n5_sub_or_to(  onumm1n5_t* lhs,  coeff_t rhs, onumm1n5_t* res);
onumm1n5_t onumm1n5_mul_oo(  onumm1n5_t* lhs,  onumm1n5_t* rhs);
void onumm1n5_mul_oo_to(  onumm1n5_t* lhs,  onumm1n5_t* rhs, onumm1n5_t* res);
onumm1n5_t onumm1n5_mul_ro(  coeff_t lhs,  onumm1n5_t* rhs);
void onumm1n5_mul_ro_to(  coeff_t lhs,  onumm1n5_t* rhs, onumm1n5_t* res);
onumm1n5_t onumm1n5_trunc_mul_oo(  onumm1n5_t* lhs,  onumm1n5_t* rhs);
void onumm1n5_trunc_mul_oo_to(  onumm1n5_t* lhs,  onumm1n5_t* rhs, onumm1n5_t* res);
onumm1n5_t onumm1n5_gem_oo(  onumm1n5_t* a,  onumm1n5_t* b,  onumm1n5_t* c);
void onumm1n5_gem_oo_to(  onumm1n5_t* a,  onumm1n5_t* b,  onumm1n5_t* c, onumm1n5_t* res);
onumm1n5_t onumm1n5_gem_ro(  coeff_t a,  onumm1n5_t* b,  onumm1n5_t* c);
void onumm1n5_gem_ro_to(  coeff_t a,  onumm1n5_t* b,  onumm1n5_t* c, onumm1n5_t* res);
void onumm1n5_trunc_gem_oo_to( ord_t ord_lhs,  onumm1n5_t* a,  ord_t ord_rhs,  onumm1n5_t* b,  onumm1n5_t* c, onumm1n5_t* res);
void onumm1n5_trunc_sum_oo_to(ord_t order, onumm1n5_t* lhs,onumm1n5_t* rhs, onumm1n5_t* res);
void onumm1n5_trunc_sub_oo_to(ord_t order, onumm1n5_t* lhs,onumm1n5_t* rhs, onumm1n5_t* res);
onumm1n5_t onumm1n5_feval(coeff_t* feval_re, onumm1n5_t* x);
void onumm1n5_feval_to(coeff_t* feval_re, onumm1n5_t* x, onumm1n5_t* res);


#endif