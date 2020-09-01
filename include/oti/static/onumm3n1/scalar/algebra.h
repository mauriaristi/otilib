#ifndef OTI_ONUMM3N1_SCALAR_ALGEBRA_H
#define OTI_ONUMM3N1_SCALAR_ALGEBRA_H

onumm3n1_t onumm3n1_abs(onumm3n1_t* num);
onumm3n1_t onumm3n1_div_ro(coeff_t num, onumm3n1_t* den);
onumm3n1_t onumm3n1_div_oo(onumm3n1_t* num, onumm3n1_t* den);
onumm3n1_t onumm3n1_div_or(onumm3n1_t* num, coeff_t val);
void onumm3n1_div_ro_to(coeff_t num, onumm3n1_t* den, onumm3n1_t* res);
void onumm3n1_div_oo_to(onumm3n1_t* num, onumm3n1_t* den, onumm3n1_t* res);
void onumm3n1_div_or_to(onumm3n1_t* num, coeff_t val, onumm3n1_t* res);
void onumm3n1_abs_to(onumm3n1_t* num, onumm3n1_t* res);

onumm3n1_t onumm3n1_neg(  onumm3n1_t* lhs);
void onumm3n1_neg_to(  onumm3n1_t* lhs, onumm3n1_t* res);
onumm3n1_t onumm3n1_sum_oo(  onumm3n1_t* lhs,  onumm3n1_t* rhs);
void onumm3n1_sum_oo_to(  onumm3n1_t* lhs,  onumm3n1_t* rhs, onumm3n1_t* res);
onumm3n1_t onumm3n1_sum_ro(  coeff_t lhs,  onumm3n1_t* rhs);
void onumm3n1_sum_ro_to(  coeff_t lhs,  onumm3n1_t* rhs, onumm3n1_t* res);
onumm3n1_t onumm3n1_sub_oo(  onumm3n1_t* lhs,  onumm3n1_t* rhs);
void onumm3n1_sub_oo_to(  onumm3n1_t* lhs,  onumm3n1_t* rhs, onumm3n1_t* res);
onumm3n1_t onumm3n1_sub_ro(  coeff_t lhs,  onumm3n1_t* rhs);
void onumm3n1_sub_ro_to(  coeff_t lhs,  onumm3n1_t* rhs, onumm3n1_t* res);
onumm3n1_t onumm3n1_sub_or(  onumm3n1_t* lhs,  coeff_t rhs);
void onumm3n1_sub_or_to(  onumm3n1_t* lhs,  coeff_t rhs, onumm3n1_t* res);
onumm3n1_t onumm3n1_mul_oo(  onumm3n1_t* lhs,  onumm3n1_t* rhs);
void onumm3n1_mul_oo_to(  onumm3n1_t* lhs,  onumm3n1_t* rhs, onumm3n1_t* res);
onumm3n1_t onumm3n1_mul_ro(  coeff_t lhs,  onumm3n1_t* rhs);
void onumm3n1_mul_ro_to(  coeff_t lhs,  onumm3n1_t* rhs, onumm3n1_t* res);
onumm3n1_t onumm3n1_trunc_mul_oo(  onumm3n1_t* lhs,  onumm3n1_t* rhs);
void onumm3n1_trunc_mul_oo_to(  onumm3n1_t* lhs,  onumm3n1_t* rhs, onumm3n1_t* res);
onumm3n1_t onumm3n1_gem_oo(  onumm3n1_t* a,  onumm3n1_t* b,  onumm3n1_t* c);
void onumm3n1_gem_oo_to(  onumm3n1_t* a,  onumm3n1_t* b,  onumm3n1_t* c, onumm3n1_t* res);
onumm3n1_t onumm3n1_gem_ro(  coeff_t a,  onumm3n1_t* b,  onumm3n1_t* c);
void onumm3n1_gem_ro_to(  coeff_t a,  onumm3n1_t* b,  onumm3n1_t* c, onumm3n1_t* res);
void onumm3n1_trunc_gem_oo_to( ord_t ord_lhs,  onumm3n1_t* a,  ord_t ord_rhs,  onumm3n1_t* b,  onumm3n1_t* c, onumm3n1_t* res);
onumm3n1_t onumm3n1_feval(coeff_t* feval_re, onumm3n1_t* x);
void onumm3n1_feval_to(coeff_t* feval_re, onumm3n1_t* x, onumm3n1_t* res);


#endif