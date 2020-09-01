#ifndef OTI_ONUMM4N4_SCALAR_ALGEBRA_H
#define OTI_ONUMM4N4_SCALAR_ALGEBRA_H

onumm4n4_t onumm4n4_abs(onumm4n4_t* num);
onumm4n4_t onumm4n4_div_ro(coeff_t num, onumm4n4_t* den);
onumm4n4_t onumm4n4_div_oo(onumm4n4_t* num, onumm4n4_t* den);
onumm4n4_t onumm4n4_div_or(onumm4n4_t* num, coeff_t val);
void onumm4n4_div_ro_to(coeff_t num, onumm4n4_t* den, onumm4n4_t* res);
void onumm4n4_div_oo_to(onumm4n4_t* num, onumm4n4_t* den, onumm4n4_t* res);
void onumm4n4_div_or_to(onumm4n4_t* num, coeff_t val, onumm4n4_t* res);
void onumm4n4_abs_to(onumm4n4_t* num, onumm4n4_t* res);

onumm4n4_t onumm4n4_neg(  onumm4n4_t* lhs);
void onumm4n4_neg_to(  onumm4n4_t* lhs, onumm4n4_t* res);
onumm4n4_t onumm4n4_sum_oo(  onumm4n4_t* lhs,  onumm4n4_t* rhs);
void onumm4n4_sum_oo_to(  onumm4n4_t* lhs,  onumm4n4_t* rhs, onumm4n4_t* res);
onumm4n4_t onumm4n4_sum_ro(  coeff_t lhs,  onumm4n4_t* rhs);
void onumm4n4_sum_ro_to(  coeff_t lhs,  onumm4n4_t* rhs, onumm4n4_t* res);
onumm4n4_t onumm4n4_sub_oo(  onumm4n4_t* lhs,  onumm4n4_t* rhs);
void onumm4n4_sub_oo_to(  onumm4n4_t* lhs,  onumm4n4_t* rhs, onumm4n4_t* res);
onumm4n4_t onumm4n4_sub_ro(  coeff_t lhs,  onumm4n4_t* rhs);
void onumm4n4_sub_ro_to(  coeff_t lhs,  onumm4n4_t* rhs, onumm4n4_t* res);
onumm4n4_t onumm4n4_sub_or(  onumm4n4_t* lhs,  coeff_t rhs);
void onumm4n4_sub_or_to(  onumm4n4_t* lhs,  coeff_t rhs, onumm4n4_t* res);
onumm4n4_t onumm4n4_mul_oo(  onumm4n4_t* lhs,  onumm4n4_t* rhs);
void onumm4n4_mul_oo_to(  onumm4n4_t* lhs,  onumm4n4_t* rhs, onumm4n4_t* res);
onumm4n4_t onumm4n4_mul_ro(  coeff_t lhs,  onumm4n4_t* rhs);
void onumm4n4_mul_ro_to(  coeff_t lhs,  onumm4n4_t* rhs, onumm4n4_t* res);
onumm4n4_t onumm4n4_trunc_mul_oo(  onumm4n4_t* lhs,  onumm4n4_t* rhs);
void onumm4n4_trunc_mul_oo_to(  onumm4n4_t* lhs,  onumm4n4_t* rhs, onumm4n4_t* res);
onumm4n4_t onumm4n4_gem_oo(  onumm4n4_t* a,  onumm4n4_t* b,  onumm4n4_t* c);
void onumm4n4_gem_oo_to(  onumm4n4_t* a,  onumm4n4_t* b,  onumm4n4_t* c, onumm4n4_t* res);
onumm4n4_t onumm4n4_gem_ro(  coeff_t a,  onumm4n4_t* b,  onumm4n4_t* c);
void onumm4n4_gem_ro_to(  coeff_t a,  onumm4n4_t* b,  onumm4n4_t* c, onumm4n4_t* res);
void onumm4n4_trunc_gem_oo_to( ord_t ord_lhs,  onumm4n4_t* a,  ord_t ord_rhs,  onumm4n4_t* b,  onumm4n4_t* c, onumm4n4_t* res);
onumm4n4_t onumm4n4_feval(coeff_t* feval_re, onumm4n4_t* x);
void onumm4n4_feval_to(coeff_t* feval_re, onumm4n4_t* x, onumm4n4_t* res);


#endif