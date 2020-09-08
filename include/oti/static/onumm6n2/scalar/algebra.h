#ifndef OTI_ONUMM6N2_SCALAR_ALGEBRA_H
#define OTI_ONUMM6N2_SCALAR_ALGEBRA_H

onumm6n2_t onumm6n2_abs(onumm6n2_t* num);
onumm6n2_t onumm6n2_div_ro(coeff_t num, onumm6n2_t* den);
onumm6n2_t onumm6n2_div_oo(onumm6n2_t* num, onumm6n2_t* den);
onumm6n2_t onumm6n2_div_or(onumm6n2_t* num, coeff_t val);
void onumm6n2_div_ro_to(coeff_t num, onumm6n2_t* den, onumm6n2_t* res);
void onumm6n2_div_oo_to(onumm6n2_t* num, onumm6n2_t* den, onumm6n2_t* res);
void onumm6n2_div_or_to(onumm6n2_t* num, coeff_t val, onumm6n2_t* res);
void onumm6n2_abs_to(onumm6n2_t* num, onumm6n2_t* res);

onumm6n2_t onumm6n2_neg(  onumm6n2_t* lhs);
void onumm6n2_neg_to(  onumm6n2_t* lhs, onumm6n2_t* res);
onumm6n2_t onumm6n2_sum_oo(  onumm6n2_t* lhs,  onumm6n2_t* rhs);
void onumm6n2_sum_oo_to(  onumm6n2_t* lhs,  onumm6n2_t* rhs, onumm6n2_t* res);
onumm6n2_t onumm6n2_sum_ro(  coeff_t lhs,  onumm6n2_t* rhs);
void onumm6n2_sum_ro_to(  coeff_t lhs,  onumm6n2_t* rhs, onumm6n2_t* res);
onumm6n2_t onumm6n2_sub_oo(  onumm6n2_t* lhs,  onumm6n2_t* rhs);
void onumm6n2_sub_oo_to(  onumm6n2_t* lhs,  onumm6n2_t* rhs, onumm6n2_t* res);
onumm6n2_t onumm6n2_sub_ro(  coeff_t lhs,  onumm6n2_t* rhs);
void onumm6n2_sub_ro_to(  coeff_t lhs,  onumm6n2_t* rhs, onumm6n2_t* res);
onumm6n2_t onumm6n2_sub_or(  onumm6n2_t* lhs,  coeff_t rhs);
void onumm6n2_sub_or_to(  onumm6n2_t* lhs,  coeff_t rhs, onumm6n2_t* res);
onumm6n2_t onumm6n2_mul_oo(  onumm6n2_t* lhs,  onumm6n2_t* rhs);
void onumm6n2_mul_oo_to(  onumm6n2_t* lhs,  onumm6n2_t* rhs, onumm6n2_t* res);
onumm6n2_t onumm6n2_mul_ro(  coeff_t lhs,  onumm6n2_t* rhs);
void onumm6n2_mul_ro_to(  coeff_t lhs,  onumm6n2_t* rhs, onumm6n2_t* res);
onumm6n2_t onumm6n2_trunc_mul_oo(  onumm6n2_t* lhs,  onumm6n2_t* rhs);
void onumm6n2_trunc_mul_oo_to(  onumm6n2_t* lhs,  onumm6n2_t* rhs, onumm6n2_t* res);
onumm6n2_t onumm6n2_gem_oo(  onumm6n2_t* a,  onumm6n2_t* b,  onumm6n2_t* c);
void onumm6n2_gem_oo_to(  onumm6n2_t* a,  onumm6n2_t* b,  onumm6n2_t* c, onumm6n2_t* res);
onumm6n2_t onumm6n2_gem_ro(  coeff_t a,  onumm6n2_t* b,  onumm6n2_t* c);
void onumm6n2_gem_ro_to(  coeff_t a,  onumm6n2_t* b,  onumm6n2_t* c, onumm6n2_t* res);
void onumm6n2_trunc_gem_oo_to( ord_t ord_lhs,  onumm6n2_t* a,  ord_t ord_rhs,  onumm6n2_t* b,  onumm6n2_t* c, onumm6n2_t* res);
onumm6n2_t onumm6n2_feval(coeff_t* feval_re, onumm6n2_t* x);
void onumm6n2_feval_to(coeff_t* feval_re, onumm6n2_t* x, onumm6n2_t* res);


#endif