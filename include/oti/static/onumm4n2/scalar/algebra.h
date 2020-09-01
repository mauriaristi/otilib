#ifndef OTI_ONUMM4N2_SCALAR_ALGEBRA_H
#define OTI_ONUMM4N2_SCALAR_ALGEBRA_H

onumm4n2_t onumm4n2_abs(onumm4n2_t* num);
onumm4n2_t onumm4n2_div_ro(coeff_t num, onumm4n2_t* den);
onumm4n2_t onumm4n2_div_oo(onumm4n2_t* num, onumm4n2_t* den);
onumm4n2_t onumm4n2_div_or(onumm4n2_t* num, coeff_t val);
void onumm4n2_div_ro_to(coeff_t num, onumm4n2_t* den, onumm4n2_t* res);
void onumm4n2_div_oo_to(onumm4n2_t* num, onumm4n2_t* den, onumm4n2_t* res);
void onumm4n2_div_or_to(onumm4n2_t* num, coeff_t val, onumm4n2_t* res);
void onumm4n2_abs_to(onumm4n2_t* num, onumm4n2_t* res);

onumm4n2_t onumm4n2_neg(  onumm4n2_t* lhs);
void onumm4n2_neg_to(  onumm4n2_t* lhs, onumm4n2_t* res);
onumm4n2_t onumm4n2_sum_oo(  onumm4n2_t* lhs,  onumm4n2_t* rhs);
void onumm4n2_sum_oo_to(  onumm4n2_t* lhs,  onumm4n2_t* rhs, onumm4n2_t* res);
onumm4n2_t onumm4n2_sum_ro(  coeff_t lhs,  onumm4n2_t* rhs);
void onumm4n2_sum_ro_to(  coeff_t lhs,  onumm4n2_t* rhs, onumm4n2_t* res);
onumm4n2_t onumm4n2_sub_oo(  onumm4n2_t* lhs,  onumm4n2_t* rhs);
void onumm4n2_sub_oo_to(  onumm4n2_t* lhs,  onumm4n2_t* rhs, onumm4n2_t* res);
onumm4n2_t onumm4n2_sub_ro(  coeff_t lhs,  onumm4n2_t* rhs);
void onumm4n2_sub_ro_to(  coeff_t lhs,  onumm4n2_t* rhs, onumm4n2_t* res);
onumm4n2_t onumm4n2_sub_or(  onumm4n2_t* lhs,  coeff_t rhs);
void onumm4n2_sub_or_to(  onumm4n2_t* lhs,  coeff_t rhs, onumm4n2_t* res);
onumm4n2_t onumm4n2_mul_oo(  onumm4n2_t* lhs,  onumm4n2_t* rhs);
void onumm4n2_mul_oo_to(  onumm4n2_t* lhs,  onumm4n2_t* rhs, onumm4n2_t* res);
onumm4n2_t onumm4n2_mul_ro(  coeff_t lhs,  onumm4n2_t* rhs);
void onumm4n2_mul_ro_to(  coeff_t lhs,  onumm4n2_t* rhs, onumm4n2_t* res);
onumm4n2_t onumm4n2_trunc_mul_oo(  onumm4n2_t* lhs,  onumm4n2_t* rhs);
void onumm4n2_trunc_mul_oo_to(  onumm4n2_t* lhs,  onumm4n2_t* rhs, onumm4n2_t* res);
onumm4n2_t onumm4n2_gem_oo(  onumm4n2_t* a,  onumm4n2_t* b,  onumm4n2_t* c);
void onumm4n2_gem_oo_to(  onumm4n2_t* a,  onumm4n2_t* b,  onumm4n2_t* c, onumm4n2_t* res);
onumm4n2_t onumm4n2_gem_ro(  coeff_t a,  onumm4n2_t* b,  onumm4n2_t* c);
void onumm4n2_gem_ro_to(  coeff_t a,  onumm4n2_t* b,  onumm4n2_t* c, onumm4n2_t* res);
void onumm4n2_trunc_gem_oo_to( ord_t ord_lhs,  onumm4n2_t* a,  ord_t ord_rhs,  onumm4n2_t* b,  onumm4n2_t* c, onumm4n2_t* res);
onumm4n2_t onumm4n2_feval(coeff_t* feval_re, onumm4n2_t* x);
void onumm4n2_feval_to(coeff_t* feval_re, onumm4n2_t* x, onumm4n2_t* res);


#endif