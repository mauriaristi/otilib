#ifndef OTI_ONUMM1N30_SCALAR_ALGEBRA_H
#define OTI_ONUMM1N30_SCALAR_ALGEBRA_H

onumm1n30_t onumm1n30_abs(onumm1n30_t* num);
onumm1n30_t onumm1n30_div_ro(coeff_t num, onumm1n30_t* den);
onumm1n30_t onumm1n30_div_oo(onumm1n30_t* num, onumm1n30_t* den);
onumm1n30_t onumm1n30_div_or(onumm1n30_t* num, coeff_t val);
void onumm1n30_div_ro_to(coeff_t num, onumm1n30_t* den, onumm1n30_t* res);
void onumm1n30_div_oo_to(onumm1n30_t* num, onumm1n30_t* den, onumm1n30_t* res);
void onumm1n30_div_or_to(onumm1n30_t* num, coeff_t val, onumm1n30_t* res);
void onumm1n30_abs_to(onumm1n30_t* num, onumm1n30_t* res);

onumm1n30_t onumm1n30_neg(  onumm1n30_t* lhs);
void onumm1n30_neg_to(  onumm1n30_t* lhs, onumm1n30_t* res);
onumm1n30_t onumm1n30_sum_oo(  onumm1n30_t* lhs,  onumm1n30_t* rhs);
void onumm1n30_sum_oo_to(  onumm1n30_t* lhs,  onumm1n30_t* rhs, onumm1n30_t* res);
onumm1n30_t onumm1n30_sum_ro(  coeff_t lhs,  onumm1n30_t* rhs);
void onumm1n30_sum_ro_to(  coeff_t lhs,  onumm1n30_t* rhs, onumm1n30_t* res);
onumm1n30_t onumm1n30_sub_oo(  onumm1n30_t* lhs,  onumm1n30_t* rhs);
void onumm1n30_sub_oo_to(  onumm1n30_t* lhs,  onumm1n30_t* rhs, onumm1n30_t* res);
onumm1n30_t onumm1n30_sub_ro(  coeff_t lhs,  onumm1n30_t* rhs);
void onumm1n30_sub_ro_to(  coeff_t lhs,  onumm1n30_t* rhs, onumm1n30_t* res);
onumm1n30_t onumm1n30_sub_or(  onumm1n30_t* lhs,  coeff_t rhs);
void onumm1n30_sub_or_to(  onumm1n30_t* lhs,  coeff_t rhs, onumm1n30_t* res);
onumm1n30_t onumm1n30_mul_oo(  onumm1n30_t* lhs,  onumm1n30_t* rhs);
void onumm1n30_mul_oo_to(  onumm1n30_t* lhs,  onumm1n30_t* rhs, onumm1n30_t* res);
onumm1n30_t onumm1n30_mul_ro(  coeff_t lhs,  onumm1n30_t* rhs);
void onumm1n30_mul_ro_to(  coeff_t lhs,  onumm1n30_t* rhs, onumm1n30_t* res);
onumm1n30_t onumm1n30_trunc_mul_oo(  onumm1n30_t* lhs,  onumm1n30_t* rhs);
void onumm1n30_trunc_mul_oo_to(  onumm1n30_t* lhs,  onumm1n30_t* rhs, onumm1n30_t* res);
onumm1n30_t onumm1n30_gem_oo(  onumm1n30_t* a,  onumm1n30_t* b,  onumm1n30_t* c);
void onumm1n30_gem_oo_to(  onumm1n30_t* a,  onumm1n30_t* b,  onumm1n30_t* c, onumm1n30_t* res);
onumm1n30_t onumm1n30_gem_ro(  coeff_t a,  onumm1n30_t* b,  onumm1n30_t* c);
void onumm1n30_gem_ro_to(  coeff_t a,  onumm1n30_t* b,  onumm1n30_t* c, onumm1n30_t* res);
void onumm1n30_trunc_gem_oo_to( ord_t ord_lhs,  onumm1n30_t* a,  ord_t ord_rhs,  onumm1n30_t* b,  onumm1n30_t* c, onumm1n30_t* res);
void onumm1n30_trunc_sum_oo_to(ord_t order, onumm1n30_t* lhs,onumm1n30_t* rhs, onumm1n30_t* res);
void onumm1n30_trunc_sub_oo_to(ord_t order, onumm1n30_t* lhs,onumm1n30_t* rhs, onumm1n30_t* res);
onumm1n30_t onumm1n30_feval(coeff_t* feval_re, onumm1n30_t* x);
void onumm1n30_feval_to(coeff_t* feval_re, onumm1n30_t* x, onumm1n30_t* res);


#endif