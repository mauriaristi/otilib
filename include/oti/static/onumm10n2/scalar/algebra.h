#ifndef OTI_ONUMM10N2_SCALAR_ALGEBRA_H
#define OTI_ONUMM10N2_SCALAR_ALGEBRA_H

onumm10n2_t onumm10n2_abs(onumm10n2_t* num);
onumm10n2_t onumm10n2_div_ro(coeff_t num, onumm10n2_t* den);
onumm10n2_t onumm10n2_div_oo(onumm10n2_t* num, onumm10n2_t* den);
onumm10n2_t onumm10n2_div_or(onumm10n2_t* num, coeff_t val);
void onumm10n2_div_ro_to(coeff_t num, onumm10n2_t* den, onumm10n2_t* res);
void onumm10n2_div_oo_to(onumm10n2_t* num, onumm10n2_t* den, onumm10n2_t* res);
void onumm10n2_div_or_to(onumm10n2_t* num, coeff_t val, onumm10n2_t* res);
void onumm10n2_abs_to(onumm10n2_t* num, onumm10n2_t* res);

onumm10n2_t onumm10n2_neg(  onumm10n2_t* lhs);
void onumm10n2_neg_to(  onumm10n2_t* lhs, onumm10n2_t* res);
onumm10n2_t onumm10n2_sum_oo(  onumm10n2_t* lhs,  onumm10n2_t* rhs);
void onumm10n2_sum_oo_to(  onumm10n2_t* lhs,  onumm10n2_t* rhs, onumm10n2_t* res);
onumm10n2_t onumm10n2_sum_ro(  coeff_t lhs,  onumm10n2_t* rhs);
void onumm10n2_sum_ro_to(  coeff_t lhs,  onumm10n2_t* rhs, onumm10n2_t* res);
onumm10n2_t onumm10n2_sub_oo(  onumm10n2_t* lhs,  onumm10n2_t* rhs);
void onumm10n2_sub_oo_to(  onumm10n2_t* lhs,  onumm10n2_t* rhs, onumm10n2_t* res);
onumm10n2_t onumm10n2_sub_ro(  coeff_t lhs,  onumm10n2_t* rhs);
void onumm10n2_sub_ro_to(  coeff_t lhs,  onumm10n2_t* rhs, onumm10n2_t* res);
onumm10n2_t onumm10n2_sub_or(  onumm10n2_t* lhs,  coeff_t rhs);
void onumm10n2_sub_or_to(  onumm10n2_t* lhs,  coeff_t rhs, onumm10n2_t* res);
onumm10n2_t onumm10n2_mul_oo(  onumm10n2_t* lhs,  onumm10n2_t* rhs);
void onumm10n2_mul_oo_to(  onumm10n2_t* lhs,  onumm10n2_t* rhs, onumm10n2_t* res);
onumm10n2_t onumm10n2_mul_ro(  coeff_t lhs,  onumm10n2_t* rhs);
void onumm10n2_mul_ro_to(  coeff_t lhs,  onumm10n2_t* rhs, onumm10n2_t* res);
onumm10n2_t onumm10n2_trunc_mul_oo(  onumm10n2_t* lhs,  onumm10n2_t* rhs);
void onumm10n2_trunc_mul_oo_to(  onumm10n2_t* lhs,  onumm10n2_t* rhs, onumm10n2_t* res);
onumm10n2_t onumm10n2_gem_oo(  onumm10n2_t* a,  onumm10n2_t* b,  onumm10n2_t* c);
void onumm10n2_gem_oo_to(  onumm10n2_t* a,  onumm10n2_t* b,  onumm10n2_t* c, onumm10n2_t* res);
onumm10n2_t onumm10n2_gem_ro(  coeff_t a,  onumm10n2_t* b,  onumm10n2_t* c);
void onumm10n2_gem_ro_to(  coeff_t a,  onumm10n2_t* b,  onumm10n2_t* c, onumm10n2_t* res);
void onumm10n2_trunc_gem_oo_to( ord_t ord_lhs,  onumm10n2_t* a,  ord_t ord_rhs,  onumm10n2_t* b,  onumm10n2_t* c, onumm10n2_t* res);
onumm10n2_t onumm10n2_feval(coeff_t* feval_re, onumm10n2_t* x);
void onumm10n2_feval_to(coeff_t* feval_re, onumm10n2_t* x, onumm10n2_t* res);


#endif