#ifndef OTI_ONUMM1N20_SCALAR_ALGEBRA_H
#define OTI_ONUMM1N20_SCALAR_ALGEBRA_H

onumm1n20_t onumm1n20_abs(onumm1n20_t* num);
onumm1n20_t onumm1n20_div_ro(coeff_t num, onumm1n20_t* den);
onumm1n20_t onumm1n20_div_oo(onumm1n20_t* num, onumm1n20_t* den);
onumm1n20_t onumm1n20_div_or(onumm1n20_t* num, coeff_t val);
void onumm1n20_div_ro_to(coeff_t num, onumm1n20_t* den, onumm1n20_t* res);
void onumm1n20_div_oo_to(onumm1n20_t* num, onumm1n20_t* den, onumm1n20_t* res);
void onumm1n20_div_or_to(onumm1n20_t* num, coeff_t val, onumm1n20_t* res);
void onumm1n20_abs_to(onumm1n20_t* num, onumm1n20_t* res);

onumm1n20_t onumm1n20_neg(  onumm1n20_t* lhs);
void onumm1n20_neg_to(  onumm1n20_t* lhs, onumm1n20_t* res);
onumm1n20_t onumm1n20_sum_oo(  onumm1n20_t* lhs,  onumm1n20_t* rhs);
void onumm1n20_sum_oo_to(  onumm1n20_t* lhs,  onumm1n20_t* rhs, onumm1n20_t* res);
onumm1n20_t onumm1n20_sum_ro(  coeff_t lhs,  onumm1n20_t* rhs);
void onumm1n20_sum_ro_to(  coeff_t lhs,  onumm1n20_t* rhs, onumm1n20_t* res);
onumm1n20_t onumm1n20_sub_oo(  onumm1n20_t* lhs,  onumm1n20_t* rhs);
void onumm1n20_sub_oo_to(  onumm1n20_t* lhs,  onumm1n20_t* rhs, onumm1n20_t* res);
onumm1n20_t onumm1n20_sub_ro(  coeff_t lhs,  onumm1n20_t* rhs);
void onumm1n20_sub_ro_to(  coeff_t lhs,  onumm1n20_t* rhs, onumm1n20_t* res);
onumm1n20_t onumm1n20_sub_or(  onumm1n20_t* lhs,  coeff_t rhs);
void onumm1n20_sub_or_to(  onumm1n20_t* lhs,  coeff_t rhs, onumm1n20_t* res);
onumm1n20_t onumm1n20_mul_oo(  onumm1n20_t* lhs,  onumm1n20_t* rhs);
void onumm1n20_mul_oo_to(  onumm1n20_t* lhs,  onumm1n20_t* rhs, onumm1n20_t* res);
onumm1n20_t onumm1n20_mul_ro(  coeff_t lhs,  onumm1n20_t* rhs);
void onumm1n20_mul_ro_to(  coeff_t lhs,  onumm1n20_t* rhs, onumm1n20_t* res);
onumm1n20_t onumm1n20_trunc_mul_oo(  onumm1n20_t* lhs,  onumm1n20_t* rhs);
void onumm1n20_trunc_mul_oo_to(  onumm1n20_t* lhs,  onumm1n20_t* rhs, onumm1n20_t* res);
onumm1n20_t onumm1n20_gem_oo(  onumm1n20_t* a,  onumm1n20_t* b,  onumm1n20_t* c);
void onumm1n20_gem_oo_to(  onumm1n20_t* a,  onumm1n20_t* b,  onumm1n20_t* c, onumm1n20_t* res);
onumm1n20_t onumm1n20_gem_ro(  coeff_t a,  onumm1n20_t* b,  onumm1n20_t* c);
void onumm1n20_gem_ro_to(  coeff_t a,  onumm1n20_t* b,  onumm1n20_t* c, onumm1n20_t* res);
void onumm1n20_trunc_gem_oo_to( ord_t ord_lhs,  onumm1n20_t* a,  ord_t ord_rhs,  onumm1n20_t* b,  onumm1n20_t* c, onumm1n20_t* res);
void onumm1n20_trunc_sum_oo_to(ord_t order, onumm1n20_t* lhs,onumm1n20_t* rhs, onumm1n20_t* res);
void onumm1n20_trunc_sub_oo_to(ord_t order, onumm1n20_t* lhs,onumm1n20_t* rhs, onumm1n20_t* res);
onumm1n20_t onumm1n20_feval(coeff_t* feval_re, onumm1n20_t* x);
void onumm1n20_feval_to(coeff_t* feval_re, onumm1n20_t* x, onumm1n20_t* res);


#endif