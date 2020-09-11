#ifndef OTI_ONUMM2N7_SCALAR_ALGEBRA_H
#define OTI_ONUMM2N7_SCALAR_ALGEBRA_H

onumm2n7_t onumm2n7_abs(onumm2n7_t* num);
onumm2n7_t onumm2n7_div_ro(coeff_t num, onumm2n7_t* den);
onumm2n7_t onumm2n7_div_oo(onumm2n7_t* num, onumm2n7_t* den);
onumm2n7_t onumm2n7_div_or(onumm2n7_t* num, coeff_t val);
void onumm2n7_div_ro_to(coeff_t num, onumm2n7_t* den, onumm2n7_t* res);
void onumm2n7_div_oo_to(onumm2n7_t* num, onumm2n7_t* den, onumm2n7_t* res);
void onumm2n7_div_or_to(onumm2n7_t* num, coeff_t val, onumm2n7_t* res);
void onumm2n7_abs_to(onumm2n7_t* num, onumm2n7_t* res);

onumm2n7_t onumm2n7_neg(  onumm2n7_t* lhs);
void onumm2n7_neg_to(  onumm2n7_t* lhs, onumm2n7_t* res);
onumm2n7_t onumm2n7_sum_oo(  onumm2n7_t* lhs,  onumm2n7_t* rhs);
void onumm2n7_sum_oo_to(  onumm2n7_t* lhs,  onumm2n7_t* rhs, onumm2n7_t* res);
onumm2n7_t onumm2n7_sum_ro(  coeff_t lhs,  onumm2n7_t* rhs);
void onumm2n7_sum_ro_to(  coeff_t lhs,  onumm2n7_t* rhs, onumm2n7_t* res);
onumm2n7_t onumm2n7_sub_oo(  onumm2n7_t* lhs,  onumm2n7_t* rhs);
void onumm2n7_sub_oo_to(  onumm2n7_t* lhs,  onumm2n7_t* rhs, onumm2n7_t* res);
onumm2n7_t onumm2n7_sub_ro(  coeff_t lhs,  onumm2n7_t* rhs);
void onumm2n7_sub_ro_to(  coeff_t lhs,  onumm2n7_t* rhs, onumm2n7_t* res);
onumm2n7_t onumm2n7_sub_or(  onumm2n7_t* lhs,  coeff_t rhs);
void onumm2n7_sub_or_to(  onumm2n7_t* lhs,  coeff_t rhs, onumm2n7_t* res);
onumm2n7_t onumm2n7_mul_oo(  onumm2n7_t* lhs,  onumm2n7_t* rhs);
void onumm2n7_mul_oo_to(  onumm2n7_t* lhs,  onumm2n7_t* rhs, onumm2n7_t* res);
onumm2n7_t onumm2n7_mul_ro(  coeff_t lhs,  onumm2n7_t* rhs);
void onumm2n7_mul_ro_to(  coeff_t lhs,  onumm2n7_t* rhs, onumm2n7_t* res);
onumm2n7_t onumm2n7_trunc_mul_oo(  onumm2n7_t* lhs,  onumm2n7_t* rhs);
void onumm2n7_trunc_mul_oo_to(  onumm2n7_t* lhs,  onumm2n7_t* rhs, onumm2n7_t* res);
onumm2n7_t onumm2n7_gem_oo(  onumm2n7_t* a,  onumm2n7_t* b,  onumm2n7_t* c);
void onumm2n7_gem_oo_to(  onumm2n7_t* a,  onumm2n7_t* b,  onumm2n7_t* c, onumm2n7_t* res);
onumm2n7_t onumm2n7_gem_ro(  coeff_t a,  onumm2n7_t* b,  onumm2n7_t* c);
void onumm2n7_gem_ro_to(  coeff_t a,  onumm2n7_t* b,  onumm2n7_t* c, onumm2n7_t* res);
void onumm2n7_trunc_gem_oo_to( ord_t ord_lhs,  onumm2n7_t* a,  ord_t ord_rhs,  onumm2n7_t* b,  onumm2n7_t* c, onumm2n7_t* res);
void onumm2n7_trunc_sum_oo_to(ord_t order, onumm2n7_t* lhs,onumm2n7_t* rhs, onumm2n7_t* res);
void onumm2n7_trunc_sub_oo_to(ord_t order, onumm2n7_t* lhs,onumm2n7_t* rhs, onumm2n7_t* res);
onumm2n7_t onumm2n7_feval(coeff_t* feval_re, onumm2n7_t* x);
void onumm2n7_feval_to(coeff_t* feval_re, onumm2n7_t* x, onumm2n7_t* res);


#endif