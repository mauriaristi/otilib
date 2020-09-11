#ifndef OTI_ONUMM2N6_SCALAR_ALGEBRA_H
#define OTI_ONUMM2N6_SCALAR_ALGEBRA_H

onumm2n6_t onumm2n6_abs(onumm2n6_t* num);
onumm2n6_t onumm2n6_div_ro(coeff_t num, onumm2n6_t* den);
onumm2n6_t onumm2n6_div_oo(onumm2n6_t* num, onumm2n6_t* den);
onumm2n6_t onumm2n6_div_or(onumm2n6_t* num, coeff_t val);
void onumm2n6_div_ro_to(coeff_t num, onumm2n6_t* den, onumm2n6_t* res);
void onumm2n6_div_oo_to(onumm2n6_t* num, onumm2n6_t* den, onumm2n6_t* res);
void onumm2n6_div_or_to(onumm2n6_t* num, coeff_t val, onumm2n6_t* res);
void onumm2n6_abs_to(onumm2n6_t* num, onumm2n6_t* res);

onumm2n6_t onumm2n6_neg(  onumm2n6_t* lhs);
void onumm2n6_neg_to(  onumm2n6_t* lhs, onumm2n6_t* res);
onumm2n6_t onumm2n6_sum_oo(  onumm2n6_t* lhs,  onumm2n6_t* rhs);
void onumm2n6_sum_oo_to(  onumm2n6_t* lhs,  onumm2n6_t* rhs, onumm2n6_t* res);
onumm2n6_t onumm2n6_sum_ro(  coeff_t lhs,  onumm2n6_t* rhs);
void onumm2n6_sum_ro_to(  coeff_t lhs,  onumm2n6_t* rhs, onumm2n6_t* res);
onumm2n6_t onumm2n6_sub_oo(  onumm2n6_t* lhs,  onumm2n6_t* rhs);
void onumm2n6_sub_oo_to(  onumm2n6_t* lhs,  onumm2n6_t* rhs, onumm2n6_t* res);
onumm2n6_t onumm2n6_sub_ro(  coeff_t lhs,  onumm2n6_t* rhs);
void onumm2n6_sub_ro_to(  coeff_t lhs,  onumm2n6_t* rhs, onumm2n6_t* res);
onumm2n6_t onumm2n6_sub_or(  onumm2n6_t* lhs,  coeff_t rhs);
void onumm2n6_sub_or_to(  onumm2n6_t* lhs,  coeff_t rhs, onumm2n6_t* res);
onumm2n6_t onumm2n6_mul_oo(  onumm2n6_t* lhs,  onumm2n6_t* rhs);
void onumm2n6_mul_oo_to(  onumm2n6_t* lhs,  onumm2n6_t* rhs, onumm2n6_t* res);
onumm2n6_t onumm2n6_mul_ro(  coeff_t lhs,  onumm2n6_t* rhs);
void onumm2n6_mul_ro_to(  coeff_t lhs,  onumm2n6_t* rhs, onumm2n6_t* res);
onumm2n6_t onumm2n6_trunc_mul_oo(  onumm2n6_t* lhs,  onumm2n6_t* rhs);
void onumm2n6_trunc_mul_oo_to(  onumm2n6_t* lhs,  onumm2n6_t* rhs, onumm2n6_t* res);
onumm2n6_t onumm2n6_gem_oo(  onumm2n6_t* a,  onumm2n6_t* b,  onumm2n6_t* c);
void onumm2n6_gem_oo_to(  onumm2n6_t* a,  onumm2n6_t* b,  onumm2n6_t* c, onumm2n6_t* res);
onumm2n6_t onumm2n6_gem_ro(  coeff_t a,  onumm2n6_t* b,  onumm2n6_t* c);
void onumm2n6_gem_ro_to(  coeff_t a,  onumm2n6_t* b,  onumm2n6_t* c, onumm2n6_t* res);
void onumm2n6_trunc_gem_oo_to( ord_t ord_lhs,  onumm2n6_t* a,  ord_t ord_rhs,  onumm2n6_t* b,  onumm2n6_t* c, onumm2n6_t* res);
void onumm2n6_trunc_sum_oo_to(ord_t order, onumm2n6_t* lhs,onumm2n6_t* rhs, onumm2n6_t* res);
void onumm2n6_trunc_sub_oo_to(ord_t order, onumm2n6_t* lhs,onumm2n6_t* rhs, onumm2n6_t* res);
onumm2n6_t onumm2n6_feval(coeff_t* feval_re, onumm2n6_t* x);
void onumm2n6_feval_to(coeff_t* feval_re, onumm2n6_t* x, onumm2n6_t* res);


#endif