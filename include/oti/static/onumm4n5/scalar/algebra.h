#ifndef OTI_ONUMM4N5_SCALAR_ALGEBRA_H
#define OTI_ONUMM4N5_SCALAR_ALGEBRA_H

onumm4n5_t onumm4n5_abs(onumm4n5_t* num);
onumm4n5_t onumm4n5_div_ro(coeff_t num, onumm4n5_t* den);
onumm4n5_t onumm4n5_div_oo(onumm4n5_t* num, onumm4n5_t* den);
onumm4n5_t onumm4n5_div_or(onumm4n5_t* num, coeff_t val);
void onumm4n5_div_ro_to(coeff_t num, onumm4n5_t* den, onumm4n5_t* res);
void onumm4n5_div_oo_to(onumm4n5_t* num, onumm4n5_t* den, onumm4n5_t* res);
void onumm4n5_div_or_to(onumm4n5_t* num, coeff_t val, onumm4n5_t* res);
void onumm4n5_abs_to(onumm4n5_t* num, onumm4n5_t* res);

onumm4n5_t onumm4n5_neg(  onumm4n5_t* lhs);
void onumm4n5_neg_to(  onumm4n5_t* lhs, onumm4n5_t* res);
onumm4n5_t onumm4n5_sum_oo(  onumm4n5_t* lhs,  onumm4n5_t* rhs);
void onumm4n5_sum_oo_to(  onumm4n5_t* lhs,  onumm4n5_t* rhs, onumm4n5_t* res);
onumm4n5_t onumm4n5_sum_ro(  coeff_t lhs,  onumm4n5_t* rhs);
void onumm4n5_sum_ro_to(  coeff_t lhs,  onumm4n5_t* rhs, onumm4n5_t* res);
onumm4n5_t onumm4n5_sub_oo(  onumm4n5_t* lhs,  onumm4n5_t* rhs);
void onumm4n5_sub_oo_to(  onumm4n5_t* lhs,  onumm4n5_t* rhs, onumm4n5_t* res);
onumm4n5_t onumm4n5_sub_ro(  coeff_t lhs,  onumm4n5_t* rhs);
void onumm4n5_sub_ro_to(  coeff_t lhs,  onumm4n5_t* rhs, onumm4n5_t* res);
onumm4n5_t onumm4n5_sub_or(  onumm4n5_t* lhs,  coeff_t rhs);
void onumm4n5_sub_or_to(  onumm4n5_t* lhs,  coeff_t rhs, onumm4n5_t* res);
onumm4n5_t onumm4n5_mul_oo(  onumm4n5_t* lhs,  onumm4n5_t* rhs);
void onumm4n5_mul_oo_to(  onumm4n5_t* lhs,  onumm4n5_t* rhs, onumm4n5_t* res);
onumm4n5_t onumm4n5_mul_ro(  coeff_t lhs,  onumm4n5_t* rhs);
void onumm4n5_mul_ro_to(  coeff_t lhs,  onumm4n5_t* rhs, onumm4n5_t* res);
onumm4n5_t onumm4n5_trunc_mul_oo(  onumm4n5_t* lhs,  onumm4n5_t* rhs);
void onumm4n5_trunc_mul_oo_to(  onumm4n5_t* lhs,  onumm4n5_t* rhs, onumm4n5_t* res);
onumm4n5_t onumm4n5_gem_oo(  onumm4n5_t* a,  onumm4n5_t* b,  onumm4n5_t* c);
void onumm4n5_gem_oo_to(  onumm4n5_t* a,  onumm4n5_t* b,  onumm4n5_t* c, onumm4n5_t* res);
onumm4n5_t onumm4n5_gem_ro(  coeff_t a,  onumm4n5_t* b,  onumm4n5_t* c);
void onumm4n5_gem_ro_to(  coeff_t a,  onumm4n5_t* b,  onumm4n5_t* c, onumm4n5_t* res);
void onumm4n5_trunc_gem_oo_to( ord_t ord_lhs,  onumm4n5_t* a,  ord_t ord_rhs,  onumm4n5_t* b,  onumm4n5_t* c, onumm4n5_t* res);
onumm4n5_t onumm4n5_feval(coeff_t* feval_re, onumm4n5_t* x);
void onumm4n5_feval_to(coeff_t* feval_re, onumm4n5_t* x, onumm4n5_t* res);


#endif