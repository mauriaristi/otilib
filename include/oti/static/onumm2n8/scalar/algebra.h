#ifndef OTI_ONUMM2N8_SCALAR_ALGEBRA_H
#define OTI_ONUMM2N8_SCALAR_ALGEBRA_H

onumm2n8_t onumm2n8_abs(onumm2n8_t* num);
onumm2n8_t onumm2n8_div_ro(coeff_t num, onumm2n8_t* den);
onumm2n8_t onumm2n8_div_oo(onumm2n8_t* num, onumm2n8_t* den);
onumm2n8_t onumm2n8_div_or(onumm2n8_t* num, coeff_t val);
void onumm2n8_div_ro_to(coeff_t num, onumm2n8_t* den, onumm2n8_t* res);
void onumm2n8_div_oo_to(onumm2n8_t* num, onumm2n8_t* den, onumm2n8_t* res);
void onumm2n8_div_or_to(onumm2n8_t* num, coeff_t val, onumm2n8_t* res);
void onumm2n8_abs_to(onumm2n8_t* num, onumm2n8_t* res);

onumm2n8_t onumm2n8_neg(  onumm2n8_t* lhs);
void onumm2n8_neg_to(  onumm2n8_t* lhs, onumm2n8_t* res);
onumm2n8_t onumm2n8_sum_oo(  onumm2n8_t* lhs,  onumm2n8_t* rhs);
void onumm2n8_sum_oo_to(  onumm2n8_t* lhs,  onumm2n8_t* rhs, onumm2n8_t* res);
onumm2n8_t onumm2n8_sum_ro(  coeff_t lhs,  onumm2n8_t* rhs);
void onumm2n8_sum_ro_to(  coeff_t lhs,  onumm2n8_t* rhs, onumm2n8_t* res);
onumm2n8_t onumm2n8_sub_oo(  onumm2n8_t* lhs,  onumm2n8_t* rhs);
void onumm2n8_sub_oo_to(  onumm2n8_t* lhs,  onumm2n8_t* rhs, onumm2n8_t* res);
onumm2n8_t onumm2n8_sub_ro(  coeff_t lhs,  onumm2n8_t* rhs);
void onumm2n8_sub_ro_to(  coeff_t lhs,  onumm2n8_t* rhs, onumm2n8_t* res);
onumm2n8_t onumm2n8_sub_or(  onumm2n8_t* lhs,  coeff_t rhs);
void onumm2n8_sub_or_to(  onumm2n8_t* lhs,  coeff_t rhs, onumm2n8_t* res);
onumm2n8_t onumm2n8_mul_oo(  onumm2n8_t* lhs,  onumm2n8_t* rhs);
void onumm2n8_mul_oo_to(  onumm2n8_t* lhs,  onumm2n8_t* rhs, onumm2n8_t* res);
onumm2n8_t onumm2n8_mul_ro(  coeff_t lhs,  onumm2n8_t* rhs);
void onumm2n8_mul_ro_to(  coeff_t lhs,  onumm2n8_t* rhs, onumm2n8_t* res);
onumm2n8_t onumm2n8_trunc_mul_oo(  onumm2n8_t* lhs,  onumm2n8_t* rhs);
void onumm2n8_trunc_mul_oo_to(  onumm2n8_t* lhs,  onumm2n8_t* rhs, onumm2n8_t* res);
onumm2n8_t onumm2n8_gem_oo(  onumm2n8_t* a,  onumm2n8_t* b,  onumm2n8_t* c);
void onumm2n8_gem_oo_to(  onumm2n8_t* a,  onumm2n8_t* b,  onumm2n8_t* c, onumm2n8_t* res);
onumm2n8_t onumm2n8_gem_ro(  coeff_t a,  onumm2n8_t* b,  onumm2n8_t* c);
void onumm2n8_gem_ro_to(  coeff_t a,  onumm2n8_t* b,  onumm2n8_t* c, onumm2n8_t* res);
void onumm2n8_trunc_gem_oo_to( ord_t ord_lhs,  onumm2n8_t* a,  ord_t ord_rhs,  onumm2n8_t* b,  onumm2n8_t* c, onumm2n8_t* res);
void onumm2n8_trunc_sum_oo_to(ord_t order, onumm2n8_t* lhs,onumm2n8_t* rhs, onumm2n8_t* res);
void onumm2n8_trunc_sub_oo_to(ord_t order, onumm2n8_t* lhs,onumm2n8_t* rhs, onumm2n8_t* res);
onumm2n8_t onumm2n8_feval(coeff_t* feval_re, onumm2n8_t* x);
void onumm2n8_feval_to(coeff_t* feval_re, onumm2n8_t* x, onumm2n8_t* res);


#endif