#ifndef OTI_ONUMM9N1_SCALAR_ALGEBRA_H
#define OTI_ONUMM9N1_SCALAR_ALGEBRA_H

onumm9n1_t onumm9n1_abs(onumm9n1_t* num);
onumm9n1_t onumm9n1_div_ro(coeff_t num, onumm9n1_t* den);
onumm9n1_t onumm9n1_div_oo(onumm9n1_t* num, onumm9n1_t* den);
onumm9n1_t onumm9n1_div_or(onumm9n1_t* num, coeff_t val);
void onumm9n1_div_ro_to(coeff_t num, onumm9n1_t* den, onumm9n1_t* res);
void onumm9n1_div_oo_to(onumm9n1_t* num, onumm9n1_t* den, onumm9n1_t* res);
void onumm9n1_div_or_to(onumm9n1_t* num, coeff_t val, onumm9n1_t* res);
void onumm9n1_abs_to(onumm9n1_t* num, onumm9n1_t* res);

onumm9n1_t onumm9n1_neg(  onumm9n1_t* lhs);
void onumm9n1_neg_to(  onumm9n1_t* lhs, onumm9n1_t* res);
onumm9n1_t onumm9n1_sum_oo(  onumm9n1_t* lhs,  onumm9n1_t* rhs);
void onumm9n1_sum_oo_to(  onumm9n1_t* lhs,  onumm9n1_t* rhs, onumm9n1_t* res);
onumm9n1_t onumm9n1_sum_ro(  coeff_t lhs,  onumm9n1_t* rhs);
void onumm9n1_sum_ro_to(  coeff_t lhs,  onumm9n1_t* rhs, onumm9n1_t* res);
onumm9n1_t onumm9n1_sub_oo(  onumm9n1_t* lhs,  onumm9n1_t* rhs);
void onumm9n1_sub_oo_to(  onumm9n1_t* lhs,  onumm9n1_t* rhs, onumm9n1_t* res);
onumm9n1_t onumm9n1_sub_ro(  coeff_t lhs,  onumm9n1_t* rhs);
void onumm9n1_sub_ro_to(  coeff_t lhs,  onumm9n1_t* rhs, onumm9n1_t* res);
onumm9n1_t onumm9n1_sub_or(  onumm9n1_t* lhs,  coeff_t rhs);
void onumm9n1_sub_or_to(  onumm9n1_t* lhs,  coeff_t rhs, onumm9n1_t* res);
onumm9n1_t onumm9n1_mul_oo(  onumm9n1_t* lhs,  onumm9n1_t* rhs);
void onumm9n1_mul_oo_to(  onumm9n1_t* lhs,  onumm9n1_t* rhs, onumm9n1_t* res);
onumm9n1_t onumm9n1_mul_ro(  coeff_t lhs,  onumm9n1_t* rhs);
void onumm9n1_mul_ro_to(  coeff_t lhs,  onumm9n1_t* rhs, onumm9n1_t* res);
onumm9n1_t onumm9n1_trunc_mul_oo(  onumm9n1_t* lhs,  onumm9n1_t* rhs);
void onumm9n1_trunc_mul_oo_to(  onumm9n1_t* lhs,  onumm9n1_t* rhs, onumm9n1_t* res);
onumm9n1_t onumm9n1_gem_oo(  onumm9n1_t* a,  onumm9n1_t* b,  onumm9n1_t* c);
void onumm9n1_gem_oo_to(  onumm9n1_t* a,  onumm9n1_t* b,  onumm9n1_t* c, onumm9n1_t* res);
onumm9n1_t onumm9n1_gem_ro(  coeff_t a,  onumm9n1_t* b,  onumm9n1_t* c);
void onumm9n1_gem_ro_to(  coeff_t a,  onumm9n1_t* b,  onumm9n1_t* c, onumm9n1_t* res);
void onumm9n1_trunc_gem_oo_to( ord_t ord_lhs,  onumm9n1_t* a,  ord_t ord_rhs,  onumm9n1_t* b,  onumm9n1_t* c, onumm9n1_t* res);
void onumm9n1_trunc_sum_oo_to(ord_t order, onumm9n1_t* lhs,onumm9n1_t* rhs, onumm9n1_t* res);
void onumm9n1_trunc_sub_oo_to(ord_t order, onumm9n1_t* lhs,onumm9n1_t* rhs, onumm9n1_t* res);
onumm9n1_t onumm9n1_feval(coeff_t* feval_re, onumm9n1_t* x);
void onumm9n1_feval_to(coeff_t* feval_re, onumm9n1_t* x, onumm9n1_t* res);


#endif