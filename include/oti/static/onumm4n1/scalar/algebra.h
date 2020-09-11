#ifndef OTI_ONUMM4N1_SCALAR_ALGEBRA_H
#define OTI_ONUMM4N1_SCALAR_ALGEBRA_H

onumm4n1_t onumm4n1_abs(onumm4n1_t* num);
onumm4n1_t onumm4n1_div_ro(coeff_t num, onumm4n1_t* den);
onumm4n1_t onumm4n1_div_oo(onumm4n1_t* num, onumm4n1_t* den);
onumm4n1_t onumm4n1_div_or(onumm4n1_t* num, coeff_t val);
void onumm4n1_div_ro_to(coeff_t num, onumm4n1_t* den, onumm4n1_t* res);
void onumm4n1_div_oo_to(onumm4n1_t* num, onumm4n1_t* den, onumm4n1_t* res);
void onumm4n1_div_or_to(onumm4n1_t* num, coeff_t val, onumm4n1_t* res);
void onumm4n1_abs_to(onumm4n1_t* num, onumm4n1_t* res);

onumm4n1_t onumm4n1_neg(  onumm4n1_t* lhs);
void onumm4n1_neg_to(  onumm4n1_t* lhs, onumm4n1_t* res);
onumm4n1_t onumm4n1_sum_oo(  onumm4n1_t* lhs,  onumm4n1_t* rhs);
void onumm4n1_sum_oo_to(  onumm4n1_t* lhs,  onumm4n1_t* rhs, onumm4n1_t* res);
onumm4n1_t onumm4n1_sum_ro(  coeff_t lhs,  onumm4n1_t* rhs);
void onumm4n1_sum_ro_to(  coeff_t lhs,  onumm4n1_t* rhs, onumm4n1_t* res);
onumm4n1_t onumm4n1_sub_oo(  onumm4n1_t* lhs,  onumm4n1_t* rhs);
void onumm4n1_sub_oo_to(  onumm4n1_t* lhs,  onumm4n1_t* rhs, onumm4n1_t* res);
onumm4n1_t onumm4n1_sub_ro(  coeff_t lhs,  onumm4n1_t* rhs);
void onumm4n1_sub_ro_to(  coeff_t lhs,  onumm4n1_t* rhs, onumm4n1_t* res);
onumm4n1_t onumm4n1_sub_or(  onumm4n1_t* lhs,  coeff_t rhs);
void onumm4n1_sub_or_to(  onumm4n1_t* lhs,  coeff_t rhs, onumm4n1_t* res);
onumm4n1_t onumm4n1_mul_oo(  onumm4n1_t* lhs,  onumm4n1_t* rhs);
void onumm4n1_mul_oo_to(  onumm4n1_t* lhs,  onumm4n1_t* rhs, onumm4n1_t* res);
onumm4n1_t onumm4n1_mul_ro(  coeff_t lhs,  onumm4n1_t* rhs);
void onumm4n1_mul_ro_to(  coeff_t lhs,  onumm4n1_t* rhs, onumm4n1_t* res);
onumm4n1_t onumm4n1_trunc_mul_oo(  onumm4n1_t* lhs,  onumm4n1_t* rhs);
void onumm4n1_trunc_mul_oo_to(  onumm4n1_t* lhs,  onumm4n1_t* rhs, onumm4n1_t* res);
onumm4n1_t onumm4n1_gem_oo(  onumm4n1_t* a,  onumm4n1_t* b,  onumm4n1_t* c);
void onumm4n1_gem_oo_to(  onumm4n1_t* a,  onumm4n1_t* b,  onumm4n1_t* c, onumm4n1_t* res);
onumm4n1_t onumm4n1_gem_ro(  coeff_t a,  onumm4n1_t* b,  onumm4n1_t* c);
void onumm4n1_gem_ro_to(  coeff_t a,  onumm4n1_t* b,  onumm4n1_t* c, onumm4n1_t* res);
void onumm4n1_trunc_gem_oo_to( ord_t ord_lhs,  onumm4n1_t* a,  ord_t ord_rhs,  onumm4n1_t* b,  onumm4n1_t* c, onumm4n1_t* res);
void onumm4n1_trunc_sum_oo_to(ord_t order, onumm4n1_t* lhs,onumm4n1_t* rhs, onumm4n1_t* res);
void onumm4n1_trunc_sub_oo_to(ord_t order, onumm4n1_t* lhs,onumm4n1_t* rhs, onumm4n1_t* res);
onumm4n1_t onumm4n1_feval(coeff_t* feval_re, onumm4n1_t* x);
void onumm4n1_feval_to(coeff_t* feval_re, onumm4n1_t* x, onumm4n1_t* res);


#endif