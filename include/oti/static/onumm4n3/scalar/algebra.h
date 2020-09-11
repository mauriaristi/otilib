#ifndef OTI_ONUMM4N3_SCALAR_ALGEBRA_H
#define OTI_ONUMM4N3_SCALAR_ALGEBRA_H

onumm4n3_t onumm4n3_abs(onumm4n3_t* num);
onumm4n3_t onumm4n3_div_ro(coeff_t num, onumm4n3_t* den);
onumm4n3_t onumm4n3_div_oo(onumm4n3_t* num, onumm4n3_t* den);
onumm4n3_t onumm4n3_div_or(onumm4n3_t* num, coeff_t val);
void onumm4n3_div_ro_to(coeff_t num, onumm4n3_t* den, onumm4n3_t* res);
void onumm4n3_div_oo_to(onumm4n3_t* num, onumm4n3_t* den, onumm4n3_t* res);
void onumm4n3_div_or_to(onumm4n3_t* num, coeff_t val, onumm4n3_t* res);
void onumm4n3_abs_to(onumm4n3_t* num, onumm4n3_t* res);

onumm4n3_t onumm4n3_neg(  onumm4n3_t* lhs);
void onumm4n3_neg_to(  onumm4n3_t* lhs, onumm4n3_t* res);
onumm4n3_t onumm4n3_sum_oo(  onumm4n3_t* lhs,  onumm4n3_t* rhs);
void onumm4n3_sum_oo_to(  onumm4n3_t* lhs,  onumm4n3_t* rhs, onumm4n3_t* res);
onumm4n3_t onumm4n3_sum_ro(  coeff_t lhs,  onumm4n3_t* rhs);
void onumm4n3_sum_ro_to(  coeff_t lhs,  onumm4n3_t* rhs, onumm4n3_t* res);
onumm4n3_t onumm4n3_sub_oo(  onumm4n3_t* lhs,  onumm4n3_t* rhs);
void onumm4n3_sub_oo_to(  onumm4n3_t* lhs,  onumm4n3_t* rhs, onumm4n3_t* res);
onumm4n3_t onumm4n3_sub_ro(  coeff_t lhs,  onumm4n3_t* rhs);
void onumm4n3_sub_ro_to(  coeff_t lhs,  onumm4n3_t* rhs, onumm4n3_t* res);
onumm4n3_t onumm4n3_sub_or(  onumm4n3_t* lhs,  coeff_t rhs);
void onumm4n3_sub_or_to(  onumm4n3_t* lhs,  coeff_t rhs, onumm4n3_t* res);
onumm4n3_t onumm4n3_mul_oo(  onumm4n3_t* lhs,  onumm4n3_t* rhs);
void onumm4n3_mul_oo_to(  onumm4n3_t* lhs,  onumm4n3_t* rhs, onumm4n3_t* res);
onumm4n3_t onumm4n3_mul_ro(  coeff_t lhs,  onumm4n3_t* rhs);
void onumm4n3_mul_ro_to(  coeff_t lhs,  onumm4n3_t* rhs, onumm4n3_t* res);
onumm4n3_t onumm4n3_trunc_mul_oo(  onumm4n3_t* lhs,  onumm4n3_t* rhs);
void onumm4n3_trunc_mul_oo_to(  onumm4n3_t* lhs,  onumm4n3_t* rhs, onumm4n3_t* res);
onumm4n3_t onumm4n3_gem_oo(  onumm4n3_t* a,  onumm4n3_t* b,  onumm4n3_t* c);
void onumm4n3_gem_oo_to(  onumm4n3_t* a,  onumm4n3_t* b,  onumm4n3_t* c, onumm4n3_t* res);
onumm4n3_t onumm4n3_gem_ro(  coeff_t a,  onumm4n3_t* b,  onumm4n3_t* c);
void onumm4n3_gem_ro_to(  coeff_t a,  onumm4n3_t* b,  onumm4n3_t* c, onumm4n3_t* res);
void onumm4n3_trunc_gem_oo_to( ord_t ord_lhs,  onumm4n3_t* a,  ord_t ord_rhs,  onumm4n3_t* b,  onumm4n3_t* c, onumm4n3_t* res);
void onumm4n3_trunc_sum_oo_to(ord_t order, onumm4n3_t* lhs,onumm4n3_t* rhs, onumm4n3_t* res);
void onumm4n3_trunc_sub_oo_to(ord_t order, onumm4n3_t* lhs,onumm4n3_t* rhs, onumm4n3_t* res);
onumm4n3_t onumm4n3_feval(coeff_t* feval_re, onumm4n3_t* x);
void onumm4n3_feval_to(coeff_t* feval_re, onumm4n3_t* x, onumm4n3_t* res);


#endif