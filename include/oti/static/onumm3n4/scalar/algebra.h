#ifndef OTI_ONUMM3N4_SCALAR_ALGEBRA_H
#define OTI_ONUMM3N4_SCALAR_ALGEBRA_H

onumm3n4_t onumm3n4_abs(onumm3n4_t* num);
onumm3n4_t onumm3n4_div_ro(coeff_t num, onumm3n4_t* den);
onumm3n4_t onumm3n4_div_oo(onumm3n4_t* num, onumm3n4_t* den);
onumm3n4_t onumm3n4_div_or(onumm3n4_t* num, coeff_t val);
void onumm3n4_div_ro_to(coeff_t num, onumm3n4_t* den, onumm3n4_t* res);
void onumm3n4_div_oo_to(onumm3n4_t* num, onumm3n4_t* den, onumm3n4_t* res);
void onumm3n4_div_or_to(onumm3n4_t* num, coeff_t val, onumm3n4_t* res);
void onumm3n4_abs_to(onumm3n4_t* num, onumm3n4_t* res);

onumm3n4_t onumm3n4_neg(  onumm3n4_t* lhs);
void onumm3n4_neg_to(  onumm3n4_t* lhs, onumm3n4_t* res);
onumm3n4_t onumm3n4_sum_oo(  onumm3n4_t* lhs,  onumm3n4_t* rhs);
void onumm3n4_sum_oo_to(  onumm3n4_t* lhs,  onumm3n4_t* rhs, onumm3n4_t* res);
onumm3n4_t onumm3n4_sum_ro(  coeff_t lhs,  onumm3n4_t* rhs);
void onumm3n4_sum_ro_to(  coeff_t lhs,  onumm3n4_t* rhs, onumm3n4_t* res);
onumm3n4_t onumm3n4_sub_oo(  onumm3n4_t* lhs,  onumm3n4_t* rhs);
void onumm3n4_sub_oo_to(  onumm3n4_t* lhs,  onumm3n4_t* rhs, onumm3n4_t* res);
onumm3n4_t onumm3n4_sub_ro(  coeff_t lhs,  onumm3n4_t* rhs);
void onumm3n4_sub_ro_to(  coeff_t lhs,  onumm3n4_t* rhs, onumm3n4_t* res);
onumm3n4_t onumm3n4_sub_or(  onumm3n4_t* lhs,  coeff_t rhs);
void onumm3n4_sub_or_to(  onumm3n4_t* lhs,  coeff_t rhs, onumm3n4_t* res);
onumm3n4_t onumm3n4_mul_oo(  onumm3n4_t* lhs,  onumm3n4_t* rhs);
void onumm3n4_mul_oo_to(  onumm3n4_t* lhs,  onumm3n4_t* rhs, onumm3n4_t* res);
onumm3n4_t onumm3n4_mul_ro(  coeff_t lhs,  onumm3n4_t* rhs);
void onumm3n4_mul_ro_to(  coeff_t lhs,  onumm3n4_t* rhs, onumm3n4_t* res);
onumm3n4_t onumm3n4_trunc_mul_oo(  onumm3n4_t* lhs,  onumm3n4_t* rhs);
void onumm3n4_trunc_mul_oo_to(  onumm3n4_t* lhs,  onumm3n4_t* rhs, onumm3n4_t* res);
onumm3n4_t onumm3n4_gem_oo(  onumm3n4_t* a,  onumm3n4_t* b,  onumm3n4_t* c);
void onumm3n4_gem_oo_to(  onumm3n4_t* a,  onumm3n4_t* b,  onumm3n4_t* c, onumm3n4_t* res);
onumm3n4_t onumm3n4_gem_ro(  coeff_t a,  onumm3n4_t* b,  onumm3n4_t* c);
void onumm3n4_gem_ro_to(  coeff_t a,  onumm3n4_t* b,  onumm3n4_t* c, onumm3n4_t* res);
void onumm3n4_trunc_gem_oo_to( ord_t ord_lhs,  onumm3n4_t* a,  ord_t ord_rhs,  onumm3n4_t* b,  onumm3n4_t* c, onumm3n4_t* res);
void onumm3n4_trunc_sum_oo_to(ord_t order, onumm3n4_t* lhs,onumm3n4_t* rhs, onumm3n4_t* res);
void onumm3n4_trunc_sub_oo_to(ord_t order, onumm3n4_t* lhs,onumm3n4_t* rhs, onumm3n4_t* res);
onumm3n4_t onumm3n4_feval(coeff_t* feval_re, onumm3n4_t* x);
void onumm3n4_feval_to(coeff_t* feval_re, onumm3n4_t* x, onumm3n4_t* res);


#endif