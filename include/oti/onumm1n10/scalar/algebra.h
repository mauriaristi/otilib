#ifndef OTI_ONUMM1N10_SCALAR_ALGEBRA_H
#define OTI_ONUMM1N10_SCALAR_ALGEBRA_H

onumm1n10_t onumm1n10_abs(onumm1n10_t* num);
onumm1n10_t onumm1n10_div_ro(coeff_t num, onumm1n10_t* den);
onumm1n10_t onumm1n10_div_oo(onumm1n10_t* num, onumm1n10_t* den);
onumm1n10_t onumm1n10_div_or(onumm1n10_t* num, coeff_t val);
void onumm1n10_div_ro_to(coeff_t num, onumm1n10_t* den, onumm1n10_t* res);
void onumm1n10_div_oo_to(onumm1n10_t* num, onumm1n10_t* den, onumm1n10_t* res);
void onumm1n10_div_or_to(onumm1n10_t* num, coeff_t val, onumm1n10_t* res);
void onumm1n10_abs_to(onumm1n10_t* num, onumm1n10_t* res);

onumm1n10_t onumm1n10_neg(  onumm1n10_t* lhs);
void onumm1n10_neg_to(  onumm1n10_t* lhs, onumm1n10_t* res);
onumm1n10_t onumm1n10_sum_oo(  onumm1n10_t* lhs,  onumm1n10_t* rhs);
void onumm1n10_sum_oo_to(  onumm1n10_t* lhs,  onumm1n10_t* rhs, onumm1n10_t* res);
onumm1n10_t onumm1n10_sum_ro(  coeff_t lhs,  onumm1n10_t* rhs);
void onumm1n10_sum_ro_to(  coeff_t lhs,  onumm1n10_t* rhs, onumm1n10_t* res);
onumm1n10_t onumm1n10_sub_oo(  onumm1n10_t* lhs,  onumm1n10_t* rhs);
void onumm1n10_sub_oo_to(  onumm1n10_t* lhs,  onumm1n10_t* rhs, onumm1n10_t* res);
onumm1n10_t onumm1n10_sub_ro(  coeff_t lhs,  onumm1n10_t* rhs);
void onumm1n10_sub_ro_to(  coeff_t lhs,  onumm1n10_t* rhs, onumm1n10_t* res);
onumm1n10_t onumm1n10_sub_or(  onumm1n10_t* lhs,  coeff_t rhs);
void onumm1n10_sub_or_to(  onumm1n10_t* lhs,  coeff_t rhs, onumm1n10_t* res);
onumm1n10_t onumm1n10_mul_oo(  onumm1n10_t* lhs,  onumm1n10_t* rhs);
void onumm1n10_mul_oo_to(  onumm1n10_t* lhs,  onumm1n10_t* rhs, onumm1n10_t* res);
onumm1n10_t onumm1n10_mul_ro(  coeff_t lhs,  onumm1n10_t* rhs);
void onumm1n10_mul_ro_to(  coeff_t lhs,  onumm1n10_t* rhs, onumm1n10_t* res);
onumm1n10_t onumm1n10_trunc_mul_oo(  onumm1n10_t* lhs,  onumm1n10_t* rhs);
void onumm1n10_trunc_mul_oo_to(  onumm1n10_t* lhs,  onumm1n10_t* rhs, onumm1n10_t* res);
onumm1n10_t onumm1n10_gem_oo(  onumm1n10_t* a,  onumm1n10_t* b,  onumm1n10_t* c);
void onumm1n10_gem_oo_to(  onumm1n10_t* a,  onumm1n10_t* b,  onumm1n10_t* c, onumm1n10_t* res);
onumm1n10_t onumm1n10_gem_ro(  coeff_t a,  onumm1n10_t* b,  onumm1n10_t* c);
void onumm1n10_gem_ro_to(  coeff_t a,  onumm1n10_t* b,  onumm1n10_t* c, onumm1n10_t* res);
onumm1n10_t onumm1n10_feval(coeff_t* feval_re, onumm1n10_t* x);
void onumm1n10_feval_to(coeff_t* feval_re, onumm1n10_t* x, onumm1n10_t* res);
onumm1n10_t onumm1n10_neg(  onumm1n10_t* lhs);
void onumm1n10_neg_to(  onumm1n10_t* lhs, onumm1n10_t* res);
onumm1n10_t onumm1n10_sum_oo(  onumm1n10_t* lhs,  onumm1n10_t* rhs);
void onumm1n10_sum_oo_to(  onumm1n10_t* lhs,  onumm1n10_t* rhs, onumm1n10_t* res);
onumm1n10_t onumm1n10_sum_ro(  coeff_t lhs,  onumm1n10_t* rhs);
void onumm1n10_sum_ro_to(  coeff_t lhs,  onumm1n10_t* rhs, onumm1n10_t* res);
onumm1n10_t onumm1n10_sub_oo(  onumm1n10_t* lhs,  onumm1n10_t* rhs);
void onumm1n10_sub_oo_to(  onumm1n10_t* lhs,  onumm1n10_t* rhs, onumm1n10_t* res);
onumm1n10_t onumm1n10_sub_ro(  coeff_t lhs,  onumm1n10_t* rhs);
void onumm1n10_sub_ro_to(  coeff_t lhs,  onumm1n10_t* rhs, onumm1n10_t* res);
onumm1n10_t onumm1n10_sub_or(  onumm1n10_t* lhs,  coeff_t rhs);
void onumm1n10_sub_or_to(  onumm1n10_t* lhs,  coeff_t rhs, onumm1n10_t* res);
onumm1n10_t onumm1n10_mul_oo(  onumm1n10_t* lhs,  onumm1n10_t* rhs);
void onumm1n10_mul_oo_to(  onumm1n10_t* lhs,  onumm1n10_t* rhs, onumm1n10_t* res);
onumm1n10_t onumm1n10_mul_ro(  coeff_t lhs,  onumm1n10_t* rhs);
void onumm1n10_mul_ro_to(  coeff_t lhs,  onumm1n10_t* rhs, onumm1n10_t* res);
onumm1n10_t onumm1n10_trunc_mul_oo(  onumm1n10_t* lhs,  onumm1n10_t* rhs);
void onumm1n10_trunc_mul_oo_to(  onumm1n10_t* lhs,  onumm1n10_t* rhs, onumm1n10_t* res);
onumm1n10_t onumm1n10_gem_oo(  onumm1n10_t* a,  onumm1n10_t* b,  onumm1n10_t* c);
void onumm1n10_gem_oo_to(  onumm1n10_t* a,  onumm1n10_t* b,  onumm1n10_t* c, onumm1n10_t* res);
onumm1n10_t onumm1n10_gem_ro(  coeff_t a,  onumm1n10_t* b,  onumm1n10_t* c);
void onumm1n10_gem_ro_to(  coeff_t a,  onumm1n10_t* b,  onumm1n10_t* c, onumm1n10_t* res);
onumm1n10_t onumm1n10_feval(coeff_t* feval_re, onumm1n10_t* x);
void onumm1n10_feval_to(coeff_t* feval_re, onumm1n10_t* x, onumm1n10_t* res);


#endif