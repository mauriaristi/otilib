#ifndef OTI_ONUMM1N7_SCALAR_ALGEBRA_H
#define OTI_ONUMM1N7_SCALAR_ALGEBRA_H

onumm1n7_t onumm1n7_abs(onumm1n7_t* num);
onumm1n7_t onumm1n7_div_ro(coeff_t num, onumm1n7_t* den);
onumm1n7_t onumm1n7_div_oo(onumm1n7_t* num, onumm1n7_t* den);
onumm1n7_t onumm1n7_div_or(onumm1n7_t* num, coeff_t val);
void onumm1n7_div_ro_to(coeff_t num, onumm1n7_t* den, onumm1n7_t* res);
void onumm1n7_div_oo_to(onumm1n7_t* num, onumm1n7_t* den, onumm1n7_t* res);
void onumm1n7_div_or_to(onumm1n7_t* num, coeff_t val, onumm1n7_t* res);
void onumm1n7_abs_to(onumm1n7_t* num, onumm1n7_t* res);

onumm1n7_t onumm1n7_neg(  onumm1n7_t* lhs);
void onumm1n7_neg_to(  onumm1n7_t* lhs, onumm1n7_t* res);
onumm1n7_t onumm1n7_sum_oo(  onumm1n7_t* lhs,  onumm1n7_t* rhs);
void onumm1n7_sum_oo_to(  onumm1n7_t* lhs,  onumm1n7_t* rhs, onumm1n7_t* res);
onumm1n7_t onumm1n7_sum_ro(  coeff_t lhs,  onumm1n7_t* rhs);
void onumm1n7_sum_ro_to(  coeff_t lhs,  onumm1n7_t* rhs, onumm1n7_t* res);
onumm1n7_t onumm1n7_sub_oo(  onumm1n7_t* lhs,  onumm1n7_t* rhs);
void onumm1n7_sub_oo_to(  onumm1n7_t* lhs,  onumm1n7_t* rhs, onumm1n7_t* res);
onumm1n7_t onumm1n7_sub_ro(  coeff_t lhs,  onumm1n7_t* rhs);
void onumm1n7_sub_ro_to(  coeff_t lhs,  onumm1n7_t* rhs, onumm1n7_t* res);
onumm1n7_t onumm1n7_sub_or(  onumm1n7_t* lhs,  coeff_t rhs);
void onumm1n7_sub_or_to(  onumm1n7_t* lhs,  coeff_t rhs, onumm1n7_t* res);
onumm1n7_t onumm1n7_mul_oo(  onumm1n7_t* lhs,  onumm1n7_t* rhs);
void onumm1n7_mul_oo_to(  onumm1n7_t* lhs,  onumm1n7_t* rhs, onumm1n7_t* res);
onumm1n7_t onumm1n7_mul_ro(  coeff_t lhs,  onumm1n7_t* rhs);
void onumm1n7_mul_ro_to(  coeff_t lhs,  onumm1n7_t* rhs, onumm1n7_t* res);
onumm1n7_t onumm1n7_trunc_mul_oo(  onumm1n7_t* lhs,  onumm1n7_t* rhs);
void onumm1n7_trunc_mul_oo_to(  onumm1n7_t* lhs,  onumm1n7_t* rhs, onumm1n7_t* res);
onumm1n7_t onumm1n7_gem_oo(  onumm1n7_t* a,  onumm1n7_t* b,  onumm1n7_t* c);
void onumm1n7_gem_oo_to(  onumm1n7_t* a,  onumm1n7_t* b,  onumm1n7_t* c, onumm1n7_t* res);
onumm1n7_t onumm1n7_gem_ro(  coeff_t a,  onumm1n7_t* b,  onumm1n7_t* c);
void onumm1n7_gem_ro_to(  coeff_t a,  onumm1n7_t* b,  onumm1n7_t* c, onumm1n7_t* res);
void onumm1n7_trunc_gem_oo_to( ord_t ord_lhs,  onumm1n7_t* a,  ord_t ord_rhs,  onumm1n7_t* b,  onumm1n7_t* c, onumm1n7_t* res);
onumm1n7_t onumm1n7_feval(coeff_t* feval_re, onumm1n7_t* x);
void onumm1n7_feval_to(coeff_t* feval_re, onumm1n7_t* x, onumm1n7_t* res);


#endif