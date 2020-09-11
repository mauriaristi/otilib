#ifndef OTI_ONUMM10N1_SCALAR_ALGEBRA_H
#define OTI_ONUMM10N1_SCALAR_ALGEBRA_H

onumm10n1_t onumm10n1_abs(onumm10n1_t* num);
onumm10n1_t onumm10n1_div_ro(coeff_t num, onumm10n1_t* den);
onumm10n1_t onumm10n1_div_oo(onumm10n1_t* num, onumm10n1_t* den);
onumm10n1_t onumm10n1_div_or(onumm10n1_t* num, coeff_t val);
void onumm10n1_div_ro_to(coeff_t num, onumm10n1_t* den, onumm10n1_t* res);
void onumm10n1_div_oo_to(onumm10n1_t* num, onumm10n1_t* den, onumm10n1_t* res);
void onumm10n1_div_or_to(onumm10n1_t* num, coeff_t val, onumm10n1_t* res);
void onumm10n1_abs_to(onumm10n1_t* num, onumm10n1_t* res);

onumm10n1_t onumm10n1_neg(  onumm10n1_t* lhs);
void onumm10n1_neg_to(  onumm10n1_t* lhs, onumm10n1_t* res);
onumm10n1_t onumm10n1_sum_oo(  onumm10n1_t* lhs,  onumm10n1_t* rhs);
void onumm10n1_sum_oo_to(  onumm10n1_t* lhs,  onumm10n1_t* rhs, onumm10n1_t* res);
onumm10n1_t onumm10n1_sum_ro(  coeff_t lhs,  onumm10n1_t* rhs);
void onumm10n1_sum_ro_to(  coeff_t lhs,  onumm10n1_t* rhs, onumm10n1_t* res);
onumm10n1_t onumm10n1_sub_oo(  onumm10n1_t* lhs,  onumm10n1_t* rhs);
void onumm10n1_sub_oo_to(  onumm10n1_t* lhs,  onumm10n1_t* rhs, onumm10n1_t* res);
onumm10n1_t onumm10n1_sub_ro(  coeff_t lhs,  onumm10n1_t* rhs);
void onumm10n1_sub_ro_to(  coeff_t lhs,  onumm10n1_t* rhs, onumm10n1_t* res);
onumm10n1_t onumm10n1_sub_or(  onumm10n1_t* lhs,  coeff_t rhs);
void onumm10n1_sub_or_to(  onumm10n1_t* lhs,  coeff_t rhs, onumm10n1_t* res);
onumm10n1_t onumm10n1_mul_oo(  onumm10n1_t* lhs,  onumm10n1_t* rhs);
void onumm10n1_mul_oo_to(  onumm10n1_t* lhs,  onumm10n1_t* rhs, onumm10n1_t* res);
onumm10n1_t onumm10n1_mul_ro(  coeff_t lhs,  onumm10n1_t* rhs);
void onumm10n1_mul_ro_to(  coeff_t lhs,  onumm10n1_t* rhs, onumm10n1_t* res);
onumm10n1_t onumm10n1_trunc_mul_oo(  onumm10n1_t* lhs,  onumm10n1_t* rhs);
void onumm10n1_trunc_mul_oo_to(  onumm10n1_t* lhs,  onumm10n1_t* rhs, onumm10n1_t* res);
onumm10n1_t onumm10n1_gem_oo(  onumm10n1_t* a,  onumm10n1_t* b,  onumm10n1_t* c);
void onumm10n1_gem_oo_to(  onumm10n1_t* a,  onumm10n1_t* b,  onumm10n1_t* c, onumm10n1_t* res);
onumm10n1_t onumm10n1_gem_ro(  coeff_t a,  onumm10n1_t* b,  onumm10n1_t* c);
void onumm10n1_gem_ro_to(  coeff_t a,  onumm10n1_t* b,  onumm10n1_t* c, onumm10n1_t* res);
void onumm10n1_trunc_gem_oo_to( ord_t ord_lhs,  onumm10n1_t* a,  ord_t ord_rhs,  onumm10n1_t* b,  onumm10n1_t* c, onumm10n1_t* res);
void onumm10n1_trunc_sum_oo_to(ord_t order, onumm10n1_t* lhs,onumm10n1_t* rhs, onumm10n1_t* res);
void onumm10n1_trunc_sub_oo_to(ord_t order, onumm10n1_t* lhs,onumm10n1_t* rhs, onumm10n1_t* res);
onumm10n1_t onumm10n1_feval(coeff_t* feval_re, onumm10n1_t* x);
void onumm10n1_feval_to(coeff_t* feval_re, onumm10n1_t* x, onumm10n1_t* res);


#endif