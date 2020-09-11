#ifndef OTI_ONUMM1N9_SCALAR_ALGEBRA_H
#define OTI_ONUMM1N9_SCALAR_ALGEBRA_H

onumm1n9_t onumm1n9_abs(onumm1n9_t* num);
onumm1n9_t onumm1n9_div_ro(coeff_t num, onumm1n9_t* den);
onumm1n9_t onumm1n9_div_oo(onumm1n9_t* num, onumm1n9_t* den);
onumm1n9_t onumm1n9_div_or(onumm1n9_t* num, coeff_t val);
void onumm1n9_div_ro_to(coeff_t num, onumm1n9_t* den, onumm1n9_t* res);
void onumm1n9_div_oo_to(onumm1n9_t* num, onumm1n9_t* den, onumm1n9_t* res);
void onumm1n9_div_or_to(onumm1n9_t* num, coeff_t val, onumm1n9_t* res);
void onumm1n9_abs_to(onumm1n9_t* num, onumm1n9_t* res);

onumm1n9_t onumm1n9_neg(  onumm1n9_t* lhs);
void onumm1n9_neg_to(  onumm1n9_t* lhs, onumm1n9_t* res);
onumm1n9_t onumm1n9_sum_oo(  onumm1n9_t* lhs,  onumm1n9_t* rhs);
void onumm1n9_sum_oo_to(  onumm1n9_t* lhs,  onumm1n9_t* rhs, onumm1n9_t* res);
onumm1n9_t onumm1n9_sum_ro(  coeff_t lhs,  onumm1n9_t* rhs);
void onumm1n9_sum_ro_to(  coeff_t lhs,  onumm1n9_t* rhs, onumm1n9_t* res);
onumm1n9_t onumm1n9_sub_oo(  onumm1n9_t* lhs,  onumm1n9_t* rhs);
void onumm1n9_sub_oo_to(  onumm1n9_t* lhs,  onumm1n9_t* rhs, onumm1n9_t* res);
onumm1n9_t onumm1n9_sub_ro(  coeff_t lhs,  onumm1n9_t* rhs);
void onumm1n9_sub_ro_to(  coeff_t lhs,  onumm1n9_t* rhs, onumm1n9_t* res);
onumm1n9_t onumm1n9_sub_or(  onumm1n9_t* lhs,  coeff_t rhs);
void onumm1n9_sub_or_to(  onumm1n9_t* lhs,  coeff_t rhs, onumm1n9_t* res);
onumm1n9_t onumm1n9_mul_oo(  onumm1n9_t* lhs,  onumm1n9_t* rhs);
void onumm1n9_mul_oo_to(  onumm1n9_t* lhs,  onumm1n9_t* rhs, onumm1n9_t* res);
onumm1n9_t onumm1n9_mul_ro(  coeff_t lhs,  onumm1n9_t* rhs);
void onumm1n9_mul_ro_to(  coeff_t lhs,  onumm1n9_t* rhs, onumm1n9_t* res);
onumm1n9_t onumm1n9_trunc_mul_oo(  onumm1n9_t* lhs,  onumm1n9_t* rhs);
void onumm1n9_trunc_mul_oo_to(  onumm1n9_t* lhs,  onumm1n9_t* rhs, onumm1n9_t* res);
onumm1n9_t onumm1n9_gem_oo(  onumm1n9_t* a,  onumm1n9_t* b,  onumm1n9_t* c);
void onumm1n9_gem_oo_to(  onumm1n9_t* a,  onumm1n9_t* b,  onumm1n9_t* c, onumm1n9_t* res);
onumm1n9_t onumm1n9_gem_ro(  coeff_t a,  onumm1n9_t* b,  onumm1n9_t* c);
void onumm1n9_gem_ro_to(  coeff_t a,  onumm1n9_t* b,  onumm1n9_t* c, onumm1n9_t* res);
void onumm1n9_trunc_gem_oo_to( ord_t ord_lhs,  onumm1n9_t* a,  ord_t ord_rhs,  onumm1n9_t* b,  onumm1n9_t* c, onumm1n9_t* res);
void onumm1n9_trunc_sum_oo_to(ord_t order, onumm1n9_t* lhs,onumm1n9_t* rhs, onumm1n9_t* res);
void onumm1n9_trunc_sub_oo_to(ord_t order, onumm1n9_t* lhs,onumm1n9_t* rhs, onumm1n9_t* res);
onumm1n9_t onumm1n9_feval(coeff_t* feval_re, onumm1n9_t* x);
void onumm1n9_feval_to(coeff_t* feval_re, onumm1n9_t* x, onumm1n9_t* res);


#endif