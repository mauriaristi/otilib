#ifndef OTI_ONUMM0N0_SCALAR_ALGEBRA_H
#define OTI_ONUMM0N0_SCALAR_ALGEBRA_H

onumm0n0_t onumm0n0_abs(onumm0n0_t* num);
onumm0n0_t onumm0n0_div_ro(coeff_t num, onumm0n0_t* den);
onumm0n0_t onumm0n0_div_oo(onumm0n0_t* num, onumm0n0_t* den);
onumm0n0_t onumm0n0_div_or(onumm0n0_t* num, coeff_t val);
void onumm0n0_div_ro_to(coeff_t num, onumm0n0_t* den, onumm0n0_t* res);
void onumm0n0_div_oo_to(onumm0n0_t* num, onumm0n0_t* den, onumm0n0_t* res);
void onumm0n0_div_or_to(onumm0n0_t* num, coeff_t val, onumm0n0_t* res);
void onumm0n0_abs_to(onumm0n0_t* num, onumm0n0_t* res);

onumm0n0_t onumm0n0_neg(  onumm0n0_t* lhs);
void onumm0n0_neg_to(  onumm0n0_t* lhs, onumm0n0_t* res);
onumm0n0_t onumm0n0_sum_oo(  onumm0n0_t* lhs,  onumm0n0_t* rhs);
void onumm0n0_sum_oo_to(  onumm0n0_t* lhs,  onumm0n0_t* rhs, onumm0n0_t* res);
onumm0n0_t onumm0n0_sum_ro(  coeff_t lhs,  onumm0n0_t* rhs);
void onumm0n0_sum_ro_to(  coeff_t lhs,  onumm0n0_t* rhs, onumm0n0_t* res);
onumm0n0_t onumm0n0_sub_oo(  onumm0n0_t* lhs,  onumm0n0_t* rhs);
void onumm0n0_sub_oo_to(  onumm0n0_t* lhs,  onumm0n0_t* rhs, onumm0n0_t* res);
onumm0n0_t onumm0n0_sub_ro(  coeff_t lhs,  onumm0n0_t* rhs);
void onumm0n0_sub_ro_to(  coeff_t lhs,  onumm0n0_t* rhs, onumm0n0_t* res);
onumm0n0_t onumm0n0_sub_or(  onumm0n0_t* lhs,  coeff_t rhs);
void onumm0n0_sub_or_to(  onumm0n0_t* lhs,  coeff_t rhs, onumm0n0_t* res);
onumm0n0_t onumm0n0_mul_oo(  onumm0n0_t* lhs,  onumm0n0_t* rhs);
void onumm0n0_mul_oo_to(  onumm0n0_t* lhs,  onumm0n0_t* rhs, onumm0n0_t* res);
onumm0n0_t onumm0n0_mul_ro(  coeff_t lhs,  onumm0n0_t* rhs);
void onumm0n0_mul_ro_to(  coeff_t lhs,  onumm0n0_t* rhs, onumm0n0_t* res);
onumm0n0_t onumm0n0_trunc_mul_oo(  onumm0n0_t* lhs,  onumm0n0_t* rhs);
void onumm0n0_trunc_mul_oo_to(  onumm0n0_t* lhs,  onumm0n0_t* rhs, onumm0n0_t* res);
onumm0n0_t onumm0n0_gem_oo(  onumm0n0_t* a,  onumm0n0_t* b,  onumm0n0_t* c);
void onumm0n0_gem_oo_to(  onumm0n0_t* a,  onumm0n0_t* b,  onumm0n0_t* c, onumm0n0_t* res);
onumm0n0_t onumm0n0_gem_ro(  coeff_t a,  onumm0n0_t* b,  onumm0n0_t* c);
void onumm0n0_gem_ro_to(  coeff_t a,  onumm0n0_t* b,  onumm0n0_t* c, onumm0n0_t* res);
void onumm0n0_trunc_gem_oo_to( ord_t ord_lhs,  onumm0n0_t* a,  ord_t ord_rhs,  onumm0n0_t* b,  onumm0n0_t* c, onumm0n0_t* res);
void onumm0n0_trunc_sum_oo_to(ord_t order, onumm0n0_t* lhs,onumm0n0_t* rhs, onumm0n0_t* res);
void onumm0n0_trunc_sub_oo_to(ord_t order, onumm0n0_t* lhs,onumm0n0_t* rhs, onumm0n0_t* res);
onumm0n0_t onumm0n0_feval(coeff_t* feval_re, onumm0n0_t* x);
void onumm0n0_feval_to(coeff_t* feval_re, onumm0n0_t* x, onumm0n0_t* res);


#endif