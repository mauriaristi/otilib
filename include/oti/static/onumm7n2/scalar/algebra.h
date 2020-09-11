#ifndef OTI_ONUMM7N2_SCALAR_ALGEBRA_H
#define OTI_ONUMM7N2_SCALAR_ALGEBRA_H

onumm7n2_t onumm7n2_abs(onumm7n2_t* num);
onumm7n2_t onumm7n2_div_ro(coeff_t num, onumm7n2_t* den);
onumm7n2_t onumm7n2_div_oo(onumm7n2_t* num, onumm7n2_t* den);
onumm7n2_t onumm7n2_div_or(onumm7n2_t* num, coeff_t val);
void onumm7n2_div_ro_to(coeff_t num, onumm7n2_t* den, onumm7n2_t* res);
void onumm7n2_div_oo_to(onumm7n2_t* num, onumm7n2_t* den, onumm7n2_t* res);
void onumm7n2_div_or_to(onumm7n2_t* num, coeff_t val, onumm7n2_t* res);
void onumm7n2_abs_to(onumm7n2_t* num, onumm7n2_t* res);

onumm7n2_t onumm7n2_neg(  onumm7n2_t* lhs);
void onumm7n2_neg_to(  onumm7n2_t* lhs, onumm7n2_t* res);
onumm7n2_t onumm7n2_sum_oo(  onumm7n2_t* lhs,  onumm7n2_t* rhs);
void onumm7n2_sum_oo_to(  onumm7n2_t* lhs,  onumm7n2_t* rhs, onumm7n2_t* res);
onumm7n2_t onumm7n2_sum_ro(  coeff_t lhs,  onumm7n2_t* rhs);
void onumm7n2_sum_ro_to(  coeff_t lhs,  onumm7n2_t* rhs, onumm7n2_t* res);
onumm7n2_t onumm7n2_sub_oo(  onumm7n2_t* lhs,  onumm7n2_t* rhs);
void onumm7n2_sub_oo_to(  onumm7n2_t* lhs,  onumm7n2_t* rhs, onumm7n2_t* res);
onumm7n2_t onumm7n2_sub_ro(  coeff_t lhs,  onumm7n2_t* rhs);
void onumm7n2_sub_ro_to(  coeff_t lhs,  onumm7n2_t* rhs, onumm7n2_t* res);
onumm7n2_t onumm7n2_sub_or(  onumm7n2_t* lhs,  coeff_t rhs);
void onumm7n2_sub_or_to(  onumm7n2_t* lhs,  coeff_t rhs, onumm7n2_t* res);
onumm7n2_t onumm7n2_mul_oo(  onumm7n2_t* lhs,  onumm7n2_t* rhs);
void onumm7n2_mul_oo_to(  onumm7n2_t* lhs,  onumm7n2_t* rhs, onumm7n2_t* res);
onumm7n2_t onumm7n2_mul_ro(  coeff_t lhs,  onumm7n2_t* rhs);
void onumm7n2_mul_ro_to(  coeff_t lhs,  onumm7n2_t* rhs, onumm7n2_t* res);
onumm7n2_t onumm7n2_trunc_mul_oo(  onumm7n2_t* lhs,  onumm7n2_t* rhs);
void onumm7n2_trunc_mul_oo_to(  onumm7n2_t* lhs,  onumm7n2_t* rhs, onumm7n2_t* res);
onumm7n2_t onumm7n2_gem_oo(  onumm7n2_t* a,  onumm7n2_t* b,  onumm7n2_t* c);
void onumm7n2_gem_oo_to(  onumm7n2_t* a,  onumm7n2_t* b,  onumm7n2_t* c, onumm7n2_t* res);
onumm7n2_t onumm7n2_gem_ro(  coeff_t a,  onumm7n2_t* b,  onumm7n2_t* c);
void onumm7n2_gem_ro_to(  coeff_t a,  onumm7n2_t* b,  onumm7n2_t* c, onumm7n2_t* res);
void onumm7n2_trunc_gem_oo_to( ord_t ord_lhs,  onumm7n2_t* a,  ord_t ord_rhs,  onumm7n2_t* b,  onumm7n2_t* c, onumm7n2_t* res);
void onumm7n2_trunc_sum_oo_to(ord_t order, onumm7n2_t* lhs,onumm7n2_t* rhs, onumm7n2_t* res);
void onumm7n2_trunc_sub_oo_to(ord_t order, onumm7n2_t* lhs,onumm7n2_t* rhs, onumm7n2_t* res);
onumm7n2_t onumm7n2_feval(coeff_t* feval_re, onumm7n2_t* x);
void onumm7n2_feval_to(coeff_t* feval_re, onumm7n2_t* x, onumm7n2_t* res);


#endif