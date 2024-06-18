#ifndef OTI_ONUMM2N1_SCALAR_ALGEBRA_H
#define OTI_ONUMM2N1_SCALAR_ALGEBRA_H

onumm2n1_t onumm2n1_abs(onumm2n1_t* num);
onumm2n1_t onumm2n1_div_ro(coeff_t num, onumm2n1_t* den);
onumm2n1_t onumm2n1_div_oo(onumm2n1_t* num, onumm2n1_t* den);
onumm2n1_t onumm2n1_div_or(onumm2n1_t* num, coeff_t val);
void onumm2n1_div_ro_to(coeff_t num, onumm2n1_t* den, onumm2n1_t* res);
void onumm2n1_div_oo_to(onumm2n1_t* num, onumm2n1_t* den, onumm2n1_t* res);
void onumm2n1_div_or_to(onumm2n1_t* num, coeff_t val, onumm2n1_t* res);
void onumm2n1_abs_to(onumm2n1_t* num, onumm2n1_t* res);

onumm2n1_t onumm2n1_neg(  onumm2n1_t* lhs);
void onumm2n1_neg_to(  onumm2n1_t* lhs, onumm2n1_t* res);
onumm2n1_t onumm2n1_sum_oo(  onumm2n1_t* lhs,  onumm2n1_t* rhs);
void onumm2n1_sum_oo_to(  onumm2n1_t* lhs,  onumm2n1_t* rhs, onumm2n1_t* res);
onumm2n1_t onumm2n1_sum_ro(  coeff_t lhs,  onumm2n1_t* rhs);
void onumm2n1_sum_ro_to(  coeff_t lhs,  onumm2n1_t* rhs, onumm2n1_t* res);
onumm2n1_t onumm2n1_sub_oo(  onumm2n1_t* lhs,  onumm2n1_t* rhs);
void onumm2n1_sub_oo_to(  onumm2n1_t* lhs,  onumm2n1_t* rhs, onumm2n1_t* res);
onumm2n1_t onumm2n1_sub_ro(  coeff_t lhs,  onumm2n1_t* rhs);
void onumm2n1_sub_ro_to(  coeff_t lhs,  onumm2n1_t* rhs, onumm2n1_t* res);
onumm2n1_t onumm2n1_sub_or(  onumm2n1_t* lhs,  coeff_t rhs);
void onumm2n1_sub_or_to(  onumm2n1_t* lhs,  coeff_t rhs, onumm2n1_t* res);
onumm2n1_t onumm2n1_mul_oo(  onumm2n1_t* lhs,  onumm2n1_t* rhs);
void onumm2n1_mul_oo_to(  onumm2n1_t* lhs,  onumm2n1_t* rhs, onumm2n1_t* res);
onumm2n1_t onumm2n1_mul_ro(  coeff_t lhs,  onumm2n1_t* rhs);
void onumm2n1_mul_ro_to(  coeff_t lhs,  onumm2n1_t* rhs, onumm2n1_t* res);
onumm2n1_t onumm2n1_trunc_mul_oo(  onumm2n1_t* lhs,  onumm2n1_t* rhs);
void onumm2n1_trunc_mul_oo_to(  onumm2n1_t* lhs,  onumm2n1_t* rhs, onumm2n1_t* res);
onumm2n1_t onumm2n1_gem_oo(  onumm2n1_t* a,  onumm2n1_t* b,  onumm2n1_t* c);
void onumm2n1_gem_oo_to(  onumm2n1_t* a,  onumm2n1_t* b,  onumm2n1_t* c, onumm2n1_t* res);
onumm2n1_t onumm2n1_gem_ro(  coeff_t a,  onumm2n1_t* b,  onumm2n1_t* c);
void onumm2n1_gem_ro_to(  coeff_t a,  onumm2n1_t* b,  onumm2n1_t* c, onumm2n1_t* res);
void onumm2n1_trunc_gem_oo_to( ord_t ord_lhs,  onumm2n1_t* a,  ord_t ord_rhs,  onumm2n1_t* b,  onumm2n1_t* c, onumm2n1_t* res);
void onumm2n1_trunc_sum_oo_to(ord_t order, onumm2n1_t* lhs,onumm2n1_t* rhs, onumm2n1_t* res);
void onumm2n1_trunc_sub_oo_to(ord_t order, onumm2n1_t* lhs,onumm2n1_t* rhs, onumm2n1_t* res);
onumm2n1_t onumm2n1_feval(coeff_t* feval_re, onumm2n1_t* x);
void onumm2n1_feval_to(coeff_t* feval_re, onumm2n1_t* x, onumm2n1_t* res);


#endif