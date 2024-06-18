#ifndef OTI_ONUMM2N3_SCALAR_ALGEBRA_H
#define OTI_ONUMM2N3_SCALAR_ALGEBRA_H

onumm2n3_t onumm2n3_abs(onumm2n3_t* num);
onumm2n3_t onumm2n3_div_ro(coeff_t num, onumm2n3_t* den);
onumm2n3_t onumm2n3_div_oo(onumm2n3_t* num, onumm2n3_t* den);
onumm2n3_t onumm2n3_div_or(onumm2n3_t* num, coeff_t val);
void onumm2n3_div_ro_to(coeff_t num, onumm2n3_t* den, onumm2n3_t* res);
void onumm2n3_div_oo_to(onumm2n3_t* num, onumm2n3_t* den, onumm2n3_t* res);
void onumm2n3_div_or_to(onumm2n3_t* num, coeff_t val, onumm2n3_t* res);
void onumm2n3_abs_to(onumm2n3_t* num, onumm2n3_t* res);

onumm2n3_t onumm2n3_neg(  onumm2n3_t* lhs);
void onumm2n3_neg_to(  onumm2n3_t* lhs, onumm2n3_t* res);
onumm2n3_t onumm2n3_sum_oo(  onumm2n3_t* lhs,  onumm2n3_t* rhs);
void onumm2n3_sum_oo_to(  onumm2n3_t* lhs,  onumm2n3_t* rhs, onumm2n3_t* res);
onumm2n3_t onumm2n3_sum_ro(  coeff_t lhs,  onumm2n3_t* rhs);
void onumm2n3_sum_ro_to(  coeff_t lhs,  onumm2n3_t* rhs, onumm2n3_t* res);
onumm2n3_t onumm2n3_sub_oo(  onumm2n3_t* lhs,  onumm2n3_t* rhs);
void onumm2n3_sub_oo_to(  onumm2n3_t* lhs,  onumm2n3_t* rhs, onumm2n3_t* res);
onumm2n3_t onumm2n3_sub_ro(  coeff_t lhs,  onumm2n3_t* rhs);
void onumm2n3_sub_ro_to(  coeff_t lhs,  onumm2n3_t* rhs, onumm2n3_t* res);
onumm2n3_t onumm2n3_sub_or(  onumm2n3_t* lhs,  coeff_t rhs);
void onumm2n3_sub_or_to(  onumm2n3_t* lhs,  coeff_t rhs, onumm2n3_t* res);
onumm2n3_t onumm2n3_mul_oo(  onumm2n3_t* lhs,  onumm2n3_t* rhs);
void onumm2n3_mul_oo_to(  onumm2n3_t* lhs,  onumm2n3_t* rhs, onumm2n3_t* res);
onumm2n3_t onumm2n3_mul_ro(  coeff_t lhs,  onumm2n3_t* rhs);
void onumm2n3_mul_ro_to(  coeff_t lhs,  onumm2n3_t* rhs, onumm2n3_t* res);
onumm2n3_t onumm2n3_trunc_mul_oo(  onumm2n3_t* lhs,  onumm2n3_t* rhs);
void onumm2n3_trunc_mul_oo_to(  onumm2n3_t* lhs,  onumm2n3_t* rhs, onumm2n3_t* res);
onumm2n3_t onumm2n3_gem_oo(  onumm2n3_t* a,  onumm2n3_t* b,  onumm2n3_t* c);
void onumm2n3_gem_oo_to(  onumm2n3_t* a,  onumm2n3_t* b,  onumm2n3_t* c, onumm2n3_t* res);
onumm2n3_t onumm2n3_gem_ro(  coeff_t a,  onumm2n3_t* b,  onumm2n3_t* c);
void onumm2n3_gem_ro_to(  coeff_t a,  onumm2n3_t* b,  onumm2n3_t* c, onumm2n3_t* res);
void onumm2n3_trunc_gem_oo_to( ord_t ord_lhs,  onumm2n3_t* a,  ord_t ord_rhs,  onumm2n3_t* b,  onumm2n3_t* c, onumm2n3_t* res);
void onumm2n3_trunc_sum_oo_to(ord_t order, onumm2n3_t* lhs,onumm2n3_t* rhs, onumm2n3_t* res);
void onumm2n3_trunc_sub_oo_to(ord_t order, onumm2n3_t* lhs,onumm2n3_t* rhs, onumm2n3_t* res);
onumm2n3_t onumm2n3_feval(coeff_t* feval_re, onumm2n3_t* x);
void onumm2n3_feval_to(coeff_t* feval_re, onumm2n3_t* x, onumm2n3_t* res);


#endif