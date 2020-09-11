#ifndef OTI_ONUMM9N2_SCALAR_ALGEBRA_H
#define OTI_ONUMM9N2_SCALAR_ALGEBRA_H

onumm9n2_t onumm9n2_abs(onumm9n2_t* num);
onumm9n2_t onumm9n2_div_ro(coeff_t num, onumm9n2_t* den);
onumm9n2_t onumm9n2_div_oo(onumm9n2_t* num, onumm9n2_t* den);
onumm9n2_t onumm9n2_div_or(onumm9n2_t* num, coeff_t val);
void onumm9n2_div_ro_to(coeff_t num, onumm9n2_t* den, onumm9n2_t* res);
void onumm9n2_div_oo_to(onumm9n2_t* num, onumm9n2_t* den, onumm9n2_t* res);
void onumm9n2_div_or_to(onumm9n2_t* num, coeff_t val, onumm9n2_t* res);
void onumm9n2_abs_to(onumm9n2_t* num, onumm9n2_t* res);

onumm9n2_t onumm9n2_neg(  onumm9n2_t* lhs);
void onumm9n2_neg_to(  onumm9n2_t* lhs, onumm9n2_t* res);
onumm9n2_t onumm9n2_sum_oo(  onumm9n2_t* lhs,  onumm9n2_t* rhs);
void onumm9n2_sum_oo_to(  onumm9n2_t* lhs,  onumm9n2_t* rhs, onumm9n2_t* res);
onumm9n2_t onumm9n2_sum_ro(  coeff_t lhs,  onumm9n2_t* rhs);
void onumm9n2_sum_ro_to(  coeff_t lhs,  onumm9n2_t* rhs, onumm9n2_t* res);
onumm9n2_t onumm9n2_sub_oo(  onumm9n2_t* lhs,  onumm9n2_t* rhs);
void onumm9n2_sub_oo_to(  onumm9n2_t* lhs,  onumm9n2_t* rhs, onumm9n2_t* res);
onumm9n2_t onumm9n2_sub_ro(  coeff_t lhs,  onumm9n2_t* rhs);
void onumm9n2_sub_ro_to(  coeff_t lhs,  onumm9n2_t* rhs, onumm9n2_t* res);
onumm9n2_t onumm9n2_sub_or(  onumm9n2_t* lhs,  coeff_t rhs);
void onumm9n2_sub_or_to(  onumm9n2_t* lhs,  coeff_t rhs, onumm9n2_t* res);
onumm9n2_t onumm9n2_mul_oo(  onumm9n2_t* lhs,  onumm9n2_t* rhs);
void onumm9n2_mul_oo_to(  onumm9n2_t* lhs,  onumm9n2_t* rhs, onumm9n2_t* res);
onumm9n2_t onumm9n2_mul_ro(  coeff_t lhs,  onumm9n2_t* rhs);
void onumm9n2_mul_ro_to(  coeff_t lhs,  onumm9n2_t* rhs, onumm9n2_t* res);
onumm9n2_t onumm9n2_trunc_mul_oo(  onumm9n2_t* lhs,  onumm9n2_t* rhs);
void onumm9n2_trunc_mul_oo_to(  onumm9n2_t* lhs,  onumm9n2_t* rhs, onumm9n2_t* res);
onumm9n2_t onumm9n2_gem_oo(  onumm9n2_t* a,  onumm9n2_t* b,  onumm9n2_t* c);
void onumm9n2_gem_oo_to(  onumm9n2_t* a,  onumm9n2_t* b,  onumm9n2_t* c, onumm9n2_t* res);
onumm9n2_t onumm9n2_gem_ro(  coeff_t a,  onumm9n2_t* b,  onumm9n2_t* c);
void onumm9n2_gem_ro_to(  coeff_t a,  onumm9n2_t* b,  onumm9n2_t* c, onumm9n2_t* res);
void onumm9n2_trunc_gem_oo_to( ord_t ord_lhs,  onumm9n2_t* a,  ord_t ord_rhs,  onumm9n2_t* b,  onumm9n2_t* c, onumm9n2_t* res);
void onumm9n2_trunc_sum_oo_to(ord_t order, onumm9n2_t* lhs,onumm9n2_t* rhs, onumm9n2_t* res);
void onumm9n2_trunc_sub_oo_to(ord_t order, onumm9n2_t* lhs,onumm9n2_t* rhs, onumm9n2_t* res);
onumm9n2_t onumm9n2_feval(coeff_t* feval_re, onumm9n2_t* x);
void onumm9n2_feval_to(coeff_t* feval_re, onumm9n2_t* x, onumm9n2_t* res);


#endif