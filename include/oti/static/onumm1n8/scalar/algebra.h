#ifndef OTI_ONUMM1N8_SCALAR_ALGEBRA_H
#define OTI_ONUMM1N8_SCALAR_ALGEBRA_H

onumm1n8_t onumm1n8_abs(onumm1n8_t* num);
onumm1n8_t onumm1n8_div_ro(coeff_t num, onumm1n8_t* den);
onumm1n8_t onumm1n8_div_oo(onumm1n8_t* num, onumm1n8_t* den);
onumm1n8_t onumm1n8_div_or(onumm1n8_t* num, coeff_t val);
void onumm1n8_div_ro_to(coeff_t num, onumm1n8_t* den, onumm1n8_t* res);
void onumm1n8_div_oo_to(onumm1n8_t* num, onumm1n8_t* den, onumm1n8_t* res);
void onumm1n8_div_or_to(onumm1n8_t* num, coeff_t val, onumm1n8_t* res);
void onumm1n8_abs_to(onumm1n8_t* num, onumm1n8_t* res);

onumm1n8_t onumm1n8_neg(  onumm1n8_t* lhs);
void onumm1n8_neg_to(  onumm1n8_t* lhs, onumm1n8_t* res);
onumm1n8_t onumm1n8_sum_oo(  onumm1n8_t* lhs,  onumm1n8_t* rhs);
void onumm1n8_sum_oo_to(  onumm1n8_t* lhs,  onumm1n8_t* rhs, onumm1n8_t* res);
onumm1n8_t onumm1n8_sum_ro(  coeff_t lhs,  onumm1n8_t* rhs);
void onumm1n8_sum_ro_to(  coeff_t lhs,  onumm1n8_t* rhs, onumm1n8_t* res);
onumm1n8_t onumm1n8_sub_oo(  onumm1n8_t* lhs,  onumm1n8_t* rhs);
void onumm1n8_sub_oo_to(  onumm1n8_t* lhs,  onumm1n8_t* rhs, onumm1n8_t* res);
onumm1n8_t onumm1n8_sub_ro(  coeff_t lhs,  onumm1n8_t* rhs);
void onumm1n8_sub_ro_to(  coeff_t lhs,  onumm1n8_t* rhs, onumm1n8_t* res);
onumm1n8_t onumm1n8_sub_or(  onumm1n8_t* lhs,  coeff_t rhs);
void onumm1n8_sub_or_to(  onumm1n8_t* lhs,  coeff_t rhs, onumm1n8_t* res);
onumm1n8_t onumm1n8_mul_oo(  onumm1n8_t* lhs,  onumm1n8_t* rhs);
void onumm1n8_mul_oo_to(  onumm1n8_t* lhs,  onumm1n8_t* rhs, onumm1n8_t* res);
onumm1n8_t onumm1n8_mul_ro(  coeff_t lhs,  onumm1n8_t* rhs);
void onumm1n8_mul_ro_to(  coeff_t lhs,  onumm1n8_t* rhs, onumm1n8_t* res);
onumm1n8_t onumm1n8_trunc_mul_oo(  onumm1n8_t* lhs,  onumm1n8_t* rhs);
void onumm1n8_trunc_mul_oo_to(  onumm1n8_t* lhs,  onumm1n8_t* rhs, onumm1n8_t* res);
onumm1n8_t onumm1n8_gem_oo(  onumm1n8_t* a,  onumm1n8_t* b,  onumm1n8_t* c);
void onumm1n8_gem_oo_to(  onumm1n8_t* a,  onumm1n8_t* b,  onumm1n8_t* c, onumm1n8_t* res);
onumm1n8_t onumm1n8_gem_ro(  coeff_t a,  onumm1n8_t* b,  onumm1n8_t* c);
void onumm1n8_gem_ro_to(  coeff_t a,  onumm1n8_t* b,  onumm1n8_t* c, onumm1n8_t* res);
void onumm1n8_trunc_gem_oo_to( ord_t ord_lhs,  onumm1n8_t* a,  ord_t ord_rhs,  onumm1n8_t* b,  onumm1n8_t* c, onumm1n8_t* res);
void onumm1n8_trunc_sum_oo_to(ord_t order, onumm1n8_t* lhs,onumm1n8_t* rhs, onumm1n8_t* res);
void onumm1n8_trunc_sub_oo_to(ord_t order, onumm1n8_t* lhs,onumm1n8_t* rhs, onumm1n8_t* res);
onumm1n8_t onumm1n8_feval(coeff_t* feval_re, onumm1n8_t* x);
void onumm1n8_feval_to(coeff_t* feval_re, onumm1n8_t* x, onumm1n8_t* res);


#endif