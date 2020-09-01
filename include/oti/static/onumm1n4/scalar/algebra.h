#ifndef OTI_ONUMM1N4_SCALAR_ALGEBRA_H
#define OTI_ONUMM1N4_SCALAR_ALGEBRA_H

onumm1n4_t onumm1n4_abs(onumm1n4_t* num);
onumm1n4_t onumm1n4_div_ro(coeff_t num, onumm1n4_t* den);
onumm1n4_t onumm1n4_div_oo(onumm1n4_t* num, onumm1n4_t* den);
onumm1n4_t onumm1n4_div_or(onumm1n4_t* num, coeff_t val);
void onumm1n4_div_ro_to(coeff_t num, onumm1n4_t* den, onumm1n4_t* res);
void onumm1n4_div_oo_to(onumm1n4_t* num, onumm1n4_t* den, onumm1n4_t* res);
void onumm1n4_div_or_to(onumm1n4_t* num, coeff_t val, onumm1n4_t* res);
void onumm1n4_abs_to(onumm1n4_t* num, onumm1n4_t* res);

onumm1n4_t onumm1n4_neg(  onumm1n4_t* lhs);
void onumm1n4_neg_to(  onumm1n4_t* lhs, onumm1n4_t* res);
onumm1n4_t onumm1n4_sum_oo(  onumm1n4_t* lhs,  onumm1n4_t* rhs);
void onumm1n4_sum_oo_to(  onumm1n4_t* lhs,  onumm1n4_t* rhs, onumm1n4_t* res);
onumm1n4_t onumm1n4_sum_ro(  coeff_t lhs,  onumm1n4_t* rhs);
void onumm1n4_sum_ro_to(  coeff_t lhs,  onumm1n4_t* rhs, onumm1n4_t* res);
onumm1n4_t onumm1n4_sub_oo(  onumm1n4_t* lhs,  onumm1n4_t* rhs);
void onumm1n4_sub_oo_to(  onumm1n4_t* lhs,  onumm1n4_t* rhs, onumm1n4_t* res);
onumm1n4_t onumm1n4_sub_ro(  coeff_t lhs,  onumm1n4_t* rhs);
void onumm1n4_sub_ro_to(  coeff_t lhs,  onumm1n4_t* rhs, onumm1n4_t* res);
onumm1n4_t onumm1n4_sub_or(  onumm1n4_t* lhs,  coeff_t rhs);
void onumm1n4_sub_or_to(  onumm1n4_t* lhs,  coeff_t rhs, onumm1n4_t* res);
onumm1n4_t onumm1n4_mul_oo(  onumm1n4_t* lhs,  onumm1n4_t* rhs);
void onumm1n4_mul_oo_to(  onumm1n4_t* lhs,  onumm1n4_t* rhs, onumm1n4_t* res);
onumm1n4_t onumm1n4_mul_ro(  coeff_t lhs,  onumm1n4_t* rhs);
void onumm1n4_mul_ro_to(  coeff_t lhs,  onumm1n4_t* rhs, onumm1n4_t* res);
onumm1n4_t onumm1n4_trunc_mul_oo(  onumm1n4_t* lhs,  onumm1n4_t* rhs);
void onumm1n4_trunc_mul_oo_to(  onumm1n4_t* lhs,  onumm1n4_t* rhs, onumm1n4_t* res);
onumm1n4_t onumm1n4_gem_oo(  onumm1n4_t* a,  onumm1n4_t* b,  onumm1n4_t* c);
void onumm1n4_gem_oo_to(  onumm1n4_t* a,  onumm1n4_t* b,  onumm1n4_t* c, onumm1n4_t* res);
onumm1n4_t onumm1n4_gem_ro(  coeff_t a,  onumm1n4_t* b,  onumm1n4_t* c);
void onumm1n4_gem_ro_to(  coeff_t a,  onumm1n4_t* b,  onumm1n4_t* c, onumm1n4_t* res);
void onumm1n4_trunc_gem_oo_to( ord_t ord_lhs,  onumm1n4_t* a,  ord_t ord_rhs,  onumm1n4_t* b,  onumm1n4_t* c, onumm1n4_t* res);
onumm1n4_t onumm1n4_feval(coeff_t* feval_re, onumm1n4_t* x);
void onumm1n4_feval_to(coeff_t* feval_re, onumm1n4_t* x, onumm1n4_t* res);


#endif