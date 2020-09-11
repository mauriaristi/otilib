#ifndef OTI_ONUMM1N3_SCALAR_ALGEBRA_H
#define OTI_ONUMM1N3_SCALAR_ALGEBRA_H

onumm1n3_t onumm1n3_abs(onumm1n3_t* num);
onumm1n3_t onumm1n3_div_ro(coeff_t num, onumm1n3_t* den);
onumm1n3_t onumm1n3_div_oo(onumm1n3_t* num, onumm1n3_t* den);
onumm1n3_t onumm1n3_div_or(onumm1n3_t* num, coeff_t val);
void onumm1n3_div_ro_to(coeff_t num, onumm1n3_t* den, onumm1n3_t* res);
void onumm1n3_div_oo_to(onumm1n3_t* num, onumm1n3_t* den, onumm1n3_t* res);
void onumm1n3_div_or_to(onumm1n3_t* num, coeff_t val, onumm1n3_t* res);
void onumm1n3_abs_to(onumm1n3_t* num, onumm1n3_t* res);

onumm1n3_t onumm1n3_neg(  onumm1n3_t* lhs);
void onumm1n3_neg_to(  onumm1n3_t* lhs, onumm1n3_t* res);
onumm1n3_t onumm1n3_sum_oo(  onumm1n3_t* lhs,  onumm1n3_t* rhs);
void onumm1n3_sum_oo_to(  onumm1n3_t* lhs,  onumm1n3_t* rhs, onumm1n3_t* res);
onumm1n3_t onumm1n3_sum_ro(  coeff_t lhs,  onumm1n3_t* rhs);
void onumm1n3_sum_ro_to(  coeff_t lhs,  onumm1n3_t* rhs, onumm1n3_t* res);
onumm1n3_t onumm1n3_sub_oo(  onumm1n3_t* lhs,  onumm1n3_t* rhs);
void onumm1n3_sub_oo_to(  onumm1n3_t* lhs,  onumm1n3_t* rhs, onumm1n3_t* res);
onumm1n3_t onumm1n3_sub_ro(  coeff_t lhs,  onumm1n3_t* rhs);
void onumm1n3_sub_ro_to(  coeff_t lhs,  onumm1n3_t* rhs, onumm1n3_t* res);
onumm1n3_t onumm1n3_sub_or(  onumm1n3_t* lhs,  coeff_t rhs);
void onumm1n3_sub_or_to(  onumm1n3_t* lhs,  coeff_t rhs, onumm1n3_t* res);
onumm1n3_t onumm1n3_mul_oo(  onumm1n3_t* lhs,  onumm1n3_t* rhs);
void onumm1n3_mul_oo_to(  onumm1n3_t* lhs,  onumm1n3_t* rhs, onumm1n3_t* res);
onumm1n3_t onumm1n3_mul_ro(  coeff_t lhs,  onumm1n3_t* rhs);
void onumm1n3_mul_ro_to(  coeff_t lhs,  onumm1n3_t* rhs, onumm1n3_t* res);
onumm1n3_t onumm1n3_trunc_mul_oo(  onumm1n3_t* lhs,  onumm1n3_t* rhs);
void onumm1n3_trunc_mul_oo_to(  onumm1n3_t* lhs,  onumm1n3_t* rhs, onumm1n3_t* res);
onumm1n3_t onumm1n3_gem_oo(  onumm1n3_t* a,  onumm1n3_t* b,  onumm1n3_t* c);
void onumm1n3_gem_oo_to(  onumm1n3_t* a,  onumm1n3_t* b,  onumm1n3_t* c, onumm1n3_t* res);
onumm1n3_t onumm1n3_gem_ro(  coeff_t a,  onumm1n3_t* b,  onumm1n3_t* c);
void onumm1n3_gem_ro_to(  coeff_t a,  onumm1n3_t* b,  onumm1n3_t* c, onumm1n3_t* res);
void onumm1n3_trunc_gem_oo_to( ord_t ord_lhs,  onumm1n3_t* a,  ord_t ord_rhs,  onumm1n3_t* b,  onumm1n3_t* c, onumm1n3_t* res);
void onumm1n3_trunc_sum_oo_to(ord_t order, onumm1n3_t* lhs,onumm1n3_t* rhs, onumm1n3_t* res);
void onumm1n3_trunc_sub_oo_to(ord_t order, onumm1n3_t* lhs,onumm1n3_t* rhs, onumm1n3_t* res);
onumm1n3_t onumm1n3_feval(coeff_t* feval_re, onumm1n3_t* x);
void onumm1n3_feval_to(coeff_t* feval_re, onumm1n3_t* x, onumm1n3_t* res);


#endif