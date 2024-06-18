#ifndef OTI_ONUMM3N3_SCALAR_ALGEBRA_H
#define OTI_ONUMM3N3_SCALAR_ALGEBRA_H

onumm3n3_t onumm3n3_abs(onumm3n3_t* num);
onumm3n3_t onumm3n3_div_ro(coeff_t num, onumm3n3_t* den);
onumm3n3_t onumm3n3_div_oo(onumm3n3_t* num, onumm3n3_t* den);
onumm3n3_t onumm3n3_div_or(onumm3n3_t* num, coeff_t val);
void onumm3n3_div_ro_to(coeff_t num, onumm3n3_t* den, onumm3n3_t* res);
void onumm3n3_div_oo_to(onumm3n3_t* num, onumm3n3_t* den, onumm3n3_t* res);
void onumm3n3_div_or_to(onumm3n3_t* num, coeff_t val, onumm3n3_t* res);
void onumm3n3_abs_to(onumm3n3_t* num, onumm3n3_t* res);

onumm3n3_t onumm3n3_neg(  onumm3n3_t* lhs);
void onumm3n3_neg_to(  onumm3n3_t* lhs, onumm3n3_t* res);
onumm3n3_t onumm3n3_sum_oo(  onumm3n3_t* lhs,  onumm3n3_t* rhs);
void onumm3n3_sum_oo_to(  onumm3n3_t* lhs,  onumm3n3_t* rhs, onumm3n3_t* res);
onumm3n3_t onumm3n3_sum_ro(  coeff_t lhs,  onumm3n3_t* rhs);
void onumm3n3_sum_ro_to(  coeff_t lhs,  onumm3n3_t* rhs, onumm3n3_t* res);
onumm3n3_t onumm3n3_sub_oo(  onumm3n3_t* lhs,  onumm3n3_t* rhs);
void onumm3n3_sub_oo_to(  onumm3n3_t* lhs,  onumm3n3_t* rhs, onumm3n3_t* res);
onumm3n3_t onumm3n3_sub_ro(  coeff_t lhs,  onumm3n3_t* rhs);
void onumm3n3_sub_ro_to(  coeff_t lhs,  onumm3n3_t* rhs, onumm3n3_t* res);
onumm3n3_t onumm3n3_sub_or(  onumm3n3_t* lhs,  coeff_t rhs);
void onumm3n3_sub_or_to(  onumm3n3_t* lhs,  coeff_t rhs, onumm3n3_t* res);
onumm3n3_t onumm3n3_mul_oo(  onumm3n3_t* lhs,  onumm3n3_t* rhs);
void onumm3n3_mul_oo_to(  onumm3n3_t* lhs,  onumm3n3_t* rhs, onumm3n3_t* res);
onumm3n3_t onumm3n3_mul_ro(  coeff_t lhs,  onumm3n3_t* rhs);
void onumm3n3_mul_ro_to(  coeff_t lhs,  onumm3n3_t* rhs, onumm3n3_t* res);
onumm3n3_t onumm3n3_trunc_mul_oo(  onumm3n3_t* lhs,  onumm3n3_t* rhs);
void onumm3n3_trunc_mul_oo_to(  onumm3n3_t* lhs,  onumm3n3_t* rhs, onumm3n3_t* res);
onumm3n3_t onumm3n3_gem_oo(  onumm3n3_t* a,  onumm3n3_t* b,  onumm3n3_t* c);
void onumm3n3_gem_oo_to(  onumm3n3_t* a,  onumm3n3_t* b,  onumm3n3_t* c, onumm3n3_t* res);
onumm3n3_t onumm3n3_gem_ro(  coeff_t a,  onumm3n3_t* b,  onumm3n3_t* c);
void onumm3n3_gem_ro_to(  coeff_t a,  onumm3n3_t* b,  onumm3n3_t* c, onumm3n3_t* res);
void onumm3n3_trunc_gem_oo_to( ord_t ord_lhs,  onumm3n3_t* a,  ord_t ord_rhs,  onumm3n3_t* b,  onumm3n3_t* c, onumm3n3_t* res);
void onumm3n3_trunc_sum_oo_to(ord_t order, onumm3n3_t* lhs,onumm3n3_t* rhs, onumm3n3_t* res);
void onumm3n3_trunc_sub_oo_to(ord_t order, onumm3n3_t* lhs,onumm3n3_t* rhs, onumm3n3_t* res);
onumm3n3_t onumm3n3_feval(coeff_t* feval_re, onumm3n3_t* x);
void onumm3n3_feval_to(coeff_t* feval_re, onumm3n3_t* x, onumm3n3_t* res);


#endif