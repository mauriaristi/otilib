#ifndef OTI_ONUMM2N9_SCALAR_ALGEBRA_H
#define OTI_ONUMM2N9_SCALAR_ALGEBRA_H

onumm2n9_t onumm2n9_abs(onumm2n9_t* num);
onumm2n9_t onumm2n9_div_ro(coeff_t num, onumm2n9_t* den);
onumm2n9_t onumm2n9_div_oo(onumm2n9_t* num, onumm2n9_t* den);
onumm2n9_t onumm2n9_div_or(onumm2n9_t* num, coeff_t val);
void onumm2n9_div_ro_to(coeff_t num, onumm2n9_t* den, onumm2n9_t* res);
void onumm2n9_div_oo_to(onumm2n9_t* num, onumm2n9_t* den, onumm2n9_t* res);
void onumm2n9_div_or_to(onumm2n9_t* num, coeff_t val, onumm2n9_t* res);
void onumm2n9_abs_to(onumm2n9_t* num, onumm2n9_t* res);

onumm2n9_t onumm2n9_neg(  onumm2n9_t* lhs);
void onumm2n9_neg_to(  onumm2n9_t* lhs, onumm2n9_t* res);
onumm2n9_t onumm2n9_sum_oo(  onumm2n9_t* lhs,  onumm2n9_t* rhs);
void onumm2n9_sum_oo_to(  onumm2n9_t* lhs,  onumm2n9_t* rhs, onumm2n9_t* res);
onumm2n9_t onumm2n9_sum_ro(  coeff_t lhs,  onumm2n9_t* rhs);
void onumm2n9_sum_ro_to(  coeff_t lhs,  onumm2n9_t* rhs, onumm2n9_t* res);
onumm2n9_t onumm2n9_sub_oo(  onumm2n9_t* lhs,  onumm2n9_t* rhs);
void onumm2n9_sub_oo_to(  onumm2n9_t* lhs,  onumm2n9_t* rhs, onumm2n9_t* res);
onumm2n9_t onumm2n9_sub_ro(  coeff_t lhs,  onumm2n9_t* rhs);
void onumm2n9_sub_ro_to(  coeff_t lhs,  onumm2n9_t* rhs, onumm2n9_t* res);
onumm2n9_t onumm2n9_sub_or(  onumm2n9_t* lhs,  coeff_t rhs);
void onumm2n9_sub_or_to(  onumm2n9_t* lhs,  coeff_t rhs, onumm2n9_t* res);
onumm2n9_t onumm2n9_mul_oo(  onumm2n9_t* lhs,  onumm2n9_t* rhs);
void onumm2n9_mul_oo_to(  onumm2n9_t* lhs,  onumm2n9_t* rhs, onumm2n9_t* res);
onumm2n9_t onumm2n9_mul_ro(  coeff_t lhs,  onumm2n9_t* rhs);
void onumm2n9_mul_ro_to(  coeff_t lhs,  onumm2n9_t* rhs, onumm2n9_t* res);
onumm2n9_t onumm2n9_trunc_mul_oo(  onumm2n9_t* lhs,  onumm2n9_t* rhs);
void onumm2n9_trunc_mul_oo_to(  onumm2n9_t* lhs,  onumm2n9_t* rhs, onumm2n9_t* res);
onumm2n9_t onumm2n9_gem_oo(  onumm2n9_t* a,  onumm2n9_t* b,  onumm2n9_t* c);
void onumm2n9_gem_oo_to(  onumm2n9_t* a,  onumm2n9_t* b,  onumm2n9_t* c, onumm2n9_t* res);
onumm2n9_t onumm2n9_gem_ro(  coeff_t a,  onumm2n9_t* b,  onumm2n9_t* c);
void onumm2n9_gem_ro_to(  coeff_t a,  onumm2n9_t* b,  onumm2n9_t* c, onumm2n9_t* res);
void onumm2n9_trunc_gem_oo_to( ord_t ord_lhs,  onumm2n9_t* a,  ord_t ord_rhs,  onumm2n9_t* b,  onumm2n9_t* c, onumm2n9_t* res);
onumm2n9_t onumm2n9_feval(coeff_t* feval_re, onumm2n9_t* x);
void onumm2n9_feval_to(coeff_t* feval_re, onumm2n9_t* x, onumm2n9_t* res);


#endif