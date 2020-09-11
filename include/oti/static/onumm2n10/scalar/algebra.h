#ifndef OTI_ONUMM2N10_SCALAR_ALGEBRA_H
#define OTI_ONUMM2N10_SCALAR_ALGEBRA_H

onumm2n10_t onumm2n10_abs(onumm2n10_t* num);
onumm2n10_t onumm2n10_div_ro(coeff_t num, onumm2n10_t* den);
onumm2n10_t onumm2n10_div_oo(onumm2n10_t* num, onumm2n10_t* den);
onumm2n10_t onumm2n10_div_or(onumm2n10_t* num, coeff_t val);
void onumm2n10_div_ro_to(coeff_t num, onumm2n10_t* den, onumm2n10_t* res);
void onumm2n10_div_oo_to(onumm2n10_t* num, onumm2n10_t* den, onumm2n10_t* res);
void onumm2n10_div_or_to(onumm2n10_t* num, coeff_t val, onumm2n10_t* res);
void onumm2n10_abs_to(onumm2n10_t* num, onumm2n10_t* res);

onumm2n10_t onumm2n10_neg(  onumm2n10_t* lhs);
void onumm2n10_neg_to(  onumm2n10_t* lhs, onumm2n10_t* res);
onumm2n10_t onumm2n10_sum_oo(  onumm2n10_t* lhs,  onumm2n10_t* rhs);
void onumm2n10_sum_oo_to(  onumm2n10_t* lhs,  onumm2n10_t* rhs, onumm2n10_t* res);
onumm2n10_t onumm2n10_sum_ro(  coeff_t lhs,  onumm2n10_t* rhs);
void onumm2n10_sum_ro_to(  coeff_t lhs,  onumm2n10_t* rhs, onumm2n10_t* res);
onumm2n10_t onumm2n10_sub_oo(  onumm2n10_t* lhs,  onumm2n10_t* rhs);
void onumm2n10_sub_oo_to(  onumm2n10_t* lhs,  onumm2n10_t* rhs, onumm2n10_t* res);
onumm2n10_t onumm2n10_sub_ro(  coeff_t lhs,  onumm2n10_t* rhs);
void onumm2n10_sub_ro_to(  coeff_t lhs,  onumm2n10_t* rhs, onumm2n10_t* res);
onumm2n10_t onumm2n10_sub_or(  onumm2n10_t* lhs,  coeff_t rhs);
void onumm2n10_sub_or_to(  onumm2n10_t* lhs,  coeff_t rhs, onumm2n10_t* res);
onumm2n10_t onumm2n10_mul_oo(  onumm2n10_t* lhs,  onumm2n10_t* rhs);
void onumm2n10_mul_oo_to(  onumm2n10_t* lhs,  onumm2n10_t* rhs, onumm2n10_t* res);
onumm2n10_t onumm2n10_mul_ro(  coeff_t lhs,  onumm2n10_t* rhs);
void onumm2n10_mul_ro_to(  coeff_t lhs,  onumm2n10_t* rhs, onumm2n10_t* res);
onumm2n10_t onumm2n10_trunc_mul_oo(  onumm2n10_t* lhs,  onumm2n10_t* rhs);
void onumm2n10_trunc_mul_oo_to(  onumm2n10_t* lhs,  onumm2n10_t* rhs, onumm2n10_t* res);
onumm2n10_t onumm2n10_gem_oo(  onumm2n10_t* a,  onumm2n10_t* b,  onumm2n10_t* c);
void onumm2n10_gem_oo_to(  onumm2n10_t* a,  onumm2n10_t* b,  onumm2n10_t* c, onumm2n10_t* res);
onumm2n10_t onumm2n10_gem_ro(  coeff_t a,  onumm2n10_t* b,  onumm2n10_t* c);
void onumm2n10_gem_ro_to(  coeff_t a,  onumm2n10_t* b,  onumm2n10_t* c, onumm2n10_t* res);
void onumm2n10_trunc_gem_oo_to( ord_t ord_lhs,  onumm2n10_t* a,  ord_t ord_rhs,  onumm2n10_t* b,  onumm2n10_t* c, onumm2n10_t* res);
void onumm2n10_trunc_sum_oo_to(ord_t order, onumm2n10_t* lhs,onumm2n10_t* rhs, onumm2n10_t* res);
void onumm2n10_trunc_sub_oo_to(ord_t order, onumm2n10_t* lhs,onumm2n10_t* rhs, onumm2n10_t* res);
onumm2n10_t onumm2n10_feval(coeff_t* feval_re, onumm2n10_t* x);
void onumm2n10_feval_to(coeff_t* feval_re, onumm2n10_t* x, onumm2n10_t* res);


#endif