#ifndef OTI_ONUMM2N4_SCALAR_ALGEBRA_H
#define OTI_ONUMM2N4_SCALAR_ALGEBRA_H

onumm2n4_t onumm2n4_abs(onumm2n4_t* num);
onumm2n4_t onumm2n4_div_ro(coeff_t num, onumm2n4_t* den);
onumm2n4_t onumm2n4_div_oo(onumm2n4_t* num, onumm2n4_t* den);
onumm2n4_t onumm2n4_div_or(onumm2n4_t* num, coeff_t val);
void onumm2n4_div_ro_to(coeff_t num, onumm2n4_t* den, onumm2n4_t* res);
void onumm2n4_div_oo_to(onumm2n4_t* num, onumm2n4_t* den, onumm2n4_t* res);
void onumm2n4_div_or_to(onumm2n4_t* num, coeff_t val, onumm2n4_t* res);
void onumm2n4_abs_to(onumm2n4_t* num, onumm2n4_t* res);

onumm2n4_t onumm2n4_neg(  onumm2n4_t* lhs);
void onumm2n4_neg_to(  onumm2n4_t* lhs, onumm2n4_t* res);
onumm2n4_t onumm2n4_sum_oo(  onumm2n4_t* lhs,  onumm2n4_t* rhs);
void onumm2n4_sum_oo_to(  onumm2n4_t* lhs,  onumm2n4_t* rhs, onumm2n4_t* res);
onumm2n4_t onumm2n4_sum_ro(  coeff_t lhs,  onumm2n4_t* rhs);
void onumm2n4_sum_ro_to(  coeff_t lhs,  onumm2n4_t* rhs, onumm2n4_t* res);
onumm2n4_t onumm2n4_sub_oo(  onumm2n4_t* lhs,  onumm2n4_t* rhs);
void onumm2n4_sub_oo_to(  onumm2n4_t* lhs,  onumm2n4_t* rhs, onumm2n4_t* res);
onumm2n4_t onumm2n4_sub_ro(  coeff_t lhs,  onumm2n4_t* rhs);
void onumm2n4_sub_ro_to(  coeff_t lhs,  onumm2n4_t* rhs, onumm2n4_t* res);
onumm2n4_t onumm2n4_sub_or(  onumm2n4_t* lhs,  coeff_t rhs);
void onumm2n4_sub_or_to(  onumm2n4_t* lhs,  coeff_t rhs, onumm2n4_t* res);
onumm2n4_t onumm2n4_mul_oo(  onumm2n4_t* lhs,  onumm2n4_t* rhs);
void onumm2n4_mul_oo_to(  onumm2n4_t* lhs,  onumm2n4_t* rhs, onumm2n4_t* res);
onumm2n4_t onumm2n4_mul_ro(  coeff_t lhs,  onumm2n4_t* rhs);
void onumm2n4_mul_ro_to(  coeff_t lhs,  onumm2n4_t* rhs, onumm2n4_t* res);
onumm2n4_t onumm2n4_trunc_mul_oo(  onumm2n4_t* lhs,  onumm2n4_t* rhs);
void onumm2n4_trunc_mul_oo_to(  onumm2n4_t* lhs,  onumm2n4_t* rhs, onumm2n4_t* res);
onumm2n4_t onumm2n4_gem_oo(  onumm2n4_t* a,  onumm2n4_t* b,  onumm2n4_t* c);
void onumm2n4_gem_oo_to(  onumm2n4_t* a,  onumm2n4_t* b,  onumm2n4_t* c, onumm2n4_t* res);
onumm2n4_t onumm2n4_gem_ro(  coeff_t a,  onumm2n4_t* b,  onumm2n4_t* c);
void onumm2n4_gem_ro_to(  coeff_t a,  onumm2n4_t* b,  onumm2n4_t* c, onumm2n4_t* res);
void onumm2n4_trunc_gem_oo_to( ord_t ord_lhs,  onumm2n4_t* a,  ord_t ord_rhs,  onumm2n4_t* b,  onumm2n4_t* c, onumm2n4_t* res);
onumm2n4_t onumm2n4_feval(coeff_t* feval_re, onumm2n4_t* x);
void onumm2n4_feval_to(coeff_t* feval_re, onumm2n4_t* x, onumm2n4_t* res);


#endif