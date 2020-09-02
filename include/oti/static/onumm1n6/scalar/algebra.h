#ifndef OTI_ONUMM1N6_SCALAR_ALGEBRA_H
#define OTI_ONUMM1N6_SCALAR_ALGEBRA_H

onumm1n6_t onumm1n6_abs(onumm1n6_t* num);
onumm1n6_t onumm1n6_div_ro(coeff_t num, onumm1n6_t* den);
onumm1n6_t onumm1n6_div_oo(onumm1n6_t* num, onumm1n6_t* den);
onumm1n6_t onumm1n6_div_or(onumm1n6_t* num, coeff_t val);
void onumm1n6_div_ro_to(coeff_t num, onumm1n6_t* den, onumm1n6_t* res);
void onumm1n6_div_oo_to(onumm1n6_t* num, onumm1n6_t* den, onumm1n6_t* res);
void onumm1n6_div_or_to(onumm1n6_t* num, coeff_t val, onumm1n6_t* res);
void onumm1n6_abs_to(onumm1n6_t* num, onumm1n6_t* res);

onumm1n6_t onumm1n6_neg(  onumm1n6_t* lhs);
void onumm1n6_neg_to(  onumm1n6_t* lhs, onumm1n6_t* res);
onumm1n6_t onumm1n6_sum_oo(  onumm1n6_t* lhs,  onumm1n6_t* rhs);
void onumm1n6_sum_oo_to(  onumm1n6_t* lhs,  onumm1n6_t* rhs, onumm1n6_t* res);
onumm1n6_t onumm1n6_sum_ro(  coeff_t lhs,  onumm1n6_t* rhs);
void onumm1n6_sum_ro_to(  coeff_t lhs,  onumm1n6_t* rhs, onumm1n6_t* res);
onumm1n6_t onumm1n6_sub_oo(  onumm1n6_t* lhs,  onumm1n6_t* rhs);
void onumm1n6_sub_oo_to(  onumm1n6_t* lhs,  onumm1n6_t* rhs, onumm1n6_t* res);
onumm1n6_t onumm1n6_sub_ro(  coeff_t lhs,  onumm1n6_t* rhs);
void onumm1n6_sub_ro_to(  coeff_t lhs,  onumm1n6_t* rhs, onumm1n6_t* res);
onumm1n6_t onumm1n6_sub_or(  onumm1n6_t* lhs,  coeff_t rhs);
void onumm1n6_sub_or_to(  onumm1n6_t* lhs,  coeff_t rhs, onumm1n6_t* res);
onumm1n6_t onumm1n6_mul_oo(  onumm1n6_t* lhs,  onumm1n6_t* rhs);
void onumm1n6_mul_oo_to(  onumm1n6_t* lhs,  onumm1n6_t* rhs, onumm1n6_t* res);
onumm1n6_t onumm1n6_mul_ro(  coeff_t lhs,  onumm1n6_t* rhs);
void onumm1n6_mul_ro_to(  coeff_t lhs,  onumm1n6_t* rhs, onumm1n6_t* res);
onumm1n6_t onumm1n6_trunc_mul_oo(  onumm1n6_t* lhs,  onumm1n6_t* rhs);
void onumm1n6_trunc_mul_oo_to(  onumm1n6_t* lhs,  onumm1n6_t* rhs, onumm1n6_t* res);
onumm1n6_t onumm1n6_gem_oo(  onumm1n6_t* a,  onumm1n6_t* b,  onumm1n6_t* c);
void onumm1n6_gem_oo_to(  onumm1n6_t* a,  onumm1n6_t* b,  onumm1n6_t* c, onumm1n6_t* res);
onumm1n6_t onumm1n6_gem_ro(  coeff_t a,  onumm1n6_t* b,  onumm1n6_t* c);
void onumm1n6_gem_ro_to(  coeff_t a,  onumm1n6_t* b,  onumm1n6_t* c, onumm1n6_t* res);
void onumm1n6_trunc_gem_oo_to( ord_t ord_lhs,  onumm1n6_t* a,  ord_t ord_rhs,  onumm1n6_t* b,  onumm1n6_t* c, onumm1n6_t* res);
onumm1n6_t onumm1n6_feval(coeff_t* feval_re, onumm1n6_t* x);
void onumm1n6_feval_to(coeff_t* feval_re, onumm1n6_t* x, onumm1n6_t* res);


#endif