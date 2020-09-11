#ifndef OTI_ONUMM3N5_SCALAR_ALGEBRA_H
#define OTI_ONUMM3N5_SCALAR_ALGEBRA_H

onumm3n5_t onumm3n5_abs(onumm3n5_t* num);
onumm3n5_t onumm3n5_div_ro(coeff_t num, onumm3n5_t* den);
onumm3n5_t onumm3n5_div_oo(onumm3n5_t* num, onumm3n5_t* den);
onumm3n5_t onumm3n5_div_or(onumm3n5_t* num, coeff_t val);
void onumm3n5_div_ro_to(coeff_t num, onumm3n5_t* den, onumm3n5_t* res);
void onumm3n5_div_oo_to(onumm3n5_t* num, onumm3n5_t* den, onumm3n5_t* res);
void onumm3n5_div_or_to(onumm3n5_t* num, coeff_t val, onumm3n5_t* res);
void onumm3n5_abs_to(onumm3n5_t* num, onumm3n5_t* res);

onumm3n5_t onumm3n5_neg(  onumm3n5_t* lhs);
void onumm3n5_neg_to(  onumm3n5_t* lhs, onumm3n5_t* res);
onumm3n5_t onumm3n5_sum_oo(  onumm3n5_t* lhs,  onumm3n5_t* rhs);
void onumm3n5_sum_oo_to(  onumm3n5_t* lhs,  onumm3n5_t* rhs, onumm3n5_t* res);
onumm3n5_t onumm3n5_sum_ro(  coeff_t lhs,  onumm3n5_t* rhs);
void onumm3n5_sum_ro_to(  coeff_t lhs,  onumm3n5_t* rhs, onumm3n5_t* res);
onumm3n5_t onumm3n5_sub_oo(  onumm3n5_t* lhs,  onumm3n5_t* rhs);
void onumm3n5_sub_oo_to(  onumm3n5_t* lhs,  onumm3n5_t* rhs, onumm3n5_t* res);
onumm3n5_t onumm3n5_sub_ro(  coeff_t lhs,  onumm3n5_t* rhs);
void onumm3n5_sub_ro_to(  coeff_t lhs,  onumm3n5_t* rhs, onumm3n5_t* res);
onumm3n5_t onumm3n5_sub_or(  onumm3n5_t* lhs,  coeff_t rhs);
void onumm3n5_sub_or_to(  onumm3n5_t* lhs,  coeff_t rhs, onumm3n5_t* res);
onumm3n5_t onumm3n5_mul_oo(  onumm3n5_t* lhs,  onumm3n5_t* rhs);
void onumm3n5_mul_oo_to(  onumm3n5_t* lhs,  onumm3n5_t* rhs, onumm3n5_t* res);
onumm3n5_t onumm3n5_mul_ro(  coeff_t lhs,  onumm3n5_t* rhs);
void onumm3n5_mul_ro_to(  coeff_t lhs,  onumm3n5_t* rhs, onumm3n5_t* res);
onumm3n5_t onumm3n5_trunc_mul_oo(  onumm3n5_t* lhs,  onumm3n5_t* rhs);
void onumm3n5_trunc_mul_oo_to(  onumm3n5_t* lhs,  onumm3n5_t* rhs, onumm3n5_t* res);
onumm3n5_t onumm3n5_gem_oo(  onumm3n5_t* a,  onumm3n5_t* b,  onumm3n5_t* c);
void onumm3n5_gem_oo_to(  onumm3n5_t* a,  onumm3n5_t* b,  onumm3n5_t* c, onumm3n5_t* res);
onumm3n5_t onumm3n5_gem_ro(  coeff_t a,  onumm3n5_t* b,  onumm3n5_t* c);
void onumm3n5_gem_ro_to(  coeff_t a,  onumm3n5_t* b,  onumm3n5_t* c, onumm3n5_t* res);
void onumm3n5_trunc_gem_oo_to( ord_t ord_lhs,  onumm3n5_t* a,  ord_t ord_rhs,  onumm3n5_t* b,  onumm3n5_t* c, onumm3n5_t* res);
void onumm3n5_trunc_sum_oo_to(ord_t order, onumm3n5_t* lhs,onumm3n5_t* rhs, onumm3n5_t* res);
void onumm3n5_trunc_sub_oo_to(ord_t order, onumm3n5_t* lhs,onumm3n5_t* rhs, onumm3n5_t* res);
onumm3n5_t onumm3n5_feval(coeff_t* feval_re, onumm3n5_t* x);
void onumm3n5_feval_to(coeff_t* feval_re, onumm3n5_t* x, onumm3n5_t* res);


#endif