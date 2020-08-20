#ifndef OTI_ONUMM1N2_SCALAR_ALGEBRA_H
#define OTI_ONUMM1N2_SCALAR_ALGEBRA_H

onumm1n2_t onumm1n2_abs(onumm1n2_t* num);
onumm1n2_t onumm1n2_div_ro(coeff_t num, onumm1n2_t* den);
onumm1n2_t onumm1n2_div_oo(onumm1n2_t* num, onumm1n2_t* den);
onumm1n2_t onumm1n2_div_or(onumm1n2_t* num, coeff_t val);
void onumm1n2_div_ro_to(coeff_t num, onumm1n2_t* den, onumm1n2_t* res);
void onumm1n2_div_oo_to(onumm1n2_t* num, onumm1n2_t* den, onumm1n2_t* res);
void onumm1n2_div_or_to(onumm1n2_t* num, coeff_t val, onumm1n2_t* res);
void onumm1n2_abs_to(onumm1n2_t* num, onumm1n2_t* res);

onumm1n2_t onumm1n2_neg(  onumm1n2_t* lhs);
void onumm1n2_neg_to(  onumm1n2_t* lhs, onumm1n2_t* res);
onumm1n2_t onumm1n2_sum_oo(  onumm1n2_t* lhs,  onumm1n2_t* rhs);
void onumm1n2_sum_oo_to(  onumm1n2_t* lhs,  onumm1n2_t* rhs, onumm1n2_t* res);
onumm1n2_t onumm1n2_sum_ro(  coeff_t lhs,  onumm1n2_t* rhs);
void onumm1n2_sum_ro_to(  coeff_t lhs,  onumm1n2_t* rhs, onumm1n2_t* res);
onumm1n2_t onumm1n2_sub_oo(  onumm1n2_t* lhs,  onumm1n2_t* rhs);
void onumm1n2_sub_oo_to(  onumm1n2_t* lhs,  onumm1n2_t* rhs, onumm1n2_t* res);
onumm1n2_t onumm1n2_sub_ro(  coeff_t lhs,  onumm1n2_t* rhs);
void onumm1n2_sub_ro_to(  coeff_t lhs,  onumm1n2_t* rhs, onumm1n2_t* res);
onumm1n2_t onumm1n2_sub_or(  onumm1n2_t* lhs,  coeff_t rhs);
void onumm1n2_sub_or_to(  onumm1n2_t* lhs,  coeff_t rhs, onumm1n2_t* res);
onumm1n2_t onumm1n2_mul_oo(  onumm1n2_t* lhs,  onumm1n2_t* rhs);
void onumm1n2_mul_oo_to(  onumm1n2_t* lhs,  onumm1n2_t* rhs, onumm1n2_t* res);
onumm1n2_t onumm1n2_mul_ro(  coeff_t lhs,  onumm1n2_t* rhs);
void onumm1n2_mul_ro_to(  coeff_t lhs,  onumm1n2_t* rhs, onumm1n2_t* res);
onumm1n2_t onumm1n2_trunc_mul_oo(  onumm1n2_t* lhs,  onumm1n2_t* rhs);
void onumm1n2_trunc_mul_oo_to(  onumm1n2_t* lhs,  onumm1n2_t* rhs, onumm1n2_t* res);
onumm1n2_t onumm1n2_gem_oo(  onumm1n2_t* a,  onumm1n2_t* b,  onumm1n2_t* c);
void onumm1n2_gem_oo_to(  onumm1n2_t* a,  onumm1n2_t* b,  onumm1n2_t* c, onumm1n2_t* res);
onumm1n2_t onumm1n2_gem_ro(  coeff_t a,  onumm1n2_t* b,  onumm1n2_t* c);
void onumm1n2_gem_ro_to(  coeff_t a,  onumm1n2_t* b,  onumm1n2_t* c, onumm1n2_t* res);
onumm1n2_t onumm1n2_feval(coeff_t* feval_re, onumm1n2_t* x);
void onumm1n2_feval_to(coeff_t* feval_re, onumm1n2_t* x, onumm1n2_t* res);
onumm1n2_t onumm1n2_neg(  onumm1n2_t* lhs);
void onumm1n2_neg_to(  onumm1n2_t* lhs, onumm1n2_t* res);
onumm1n2_t onumm1n2_sum_oo(  onumm1n2_t* lhs,  onumm1n2_t* rhs);
void onumm1n2_sum_oo_to(  onumm1n2_t* lhs,  onumm1n2_t* rhs, onumm1n2_t* res);
onumm1n2_t onumm1n2_sum_ro(  coeff_t lhs,  onumm1n2_t* rhs);
void onumm1n2_sum_ro_to(  coeff_t lhs,  onumm1n2_t* rhs, onumm1n2_t* res);
onumm1n2_t onumm1n2_sub_oo(  onumm1n2_t* lhs,  onumm1n2_t* rhs);
void onumm1n2_sub_oo_to(  onumm1n2_t* lhs,  onumm1n2_t* rhs, onumm1n2_t* res);
onumm1n2_t onumm1n2_sub_ro(  coeff_t lhs,  onumm1n2_t* rhs);
void onumm1n2_sub_ro_to(  coeff_t lhs,  onumm1n2_t* rhs, onumm1n2_t* res);
onumm1n2_t onumm1n2_sub_or(  onumm1n2_t* lhs,  coeff_t rhs);
void onumm1n2_sub_or_to(  onumm1n2_t* lhs,  coeff_t rhs, onumm1n2_t* res);
onumm1n2_t onumm1n2_mul_oo(  onumm1n2_t* lhs,  onumm1n2_t* rhs);
void onumm1n2_mul_oo_to(  onumm1n2_t* lhs,  onumm1n2_t* rhs, onumm1n2_t* res);
onumm1n2_t onumm1n2_mul_ro(  coeff_t lhs,  onumm1n2_t* rhs);
void onumm1n2_mul_ro_to(  coeff_t lhs,  onumm1n2_t* rhs, onumm1n2_t* res);
onumm1n2_t onumm1n2_trunc_mul_oo(  onumm1n2_t* lhs,  onumm1n2_t* rhs);
void onumm1n2_trunc_mul_oo_to(  onumm1n2_t* lhs,  onumm1n2_t* rhs, onumm1n2_t* res);
onumm1n2_t onumm1n2_gem_oo(  onumm1n2_t* a,  onumm1n2_t* b,  onumm1n2_t* c);
void onumm1n2_gem_oo_to(  onumm1n2_t* a,  onumm1n2_t* b,  onumm1n2_t* c, onumm1n2_t* res);
onumm1n2_t onumm1n2_gem_ro(  coeff_t a,  onumm1n2_t* b,  onumm1n2_t* c);
void onumm1n2_gem_ro_to(  coeff_t a,  onumm1n2_t* b,  onumm1n2_t* c, onumm1n2_t* res);
onumm1n2_t onumm1n2_feval(coeff_t* feval_re, onumm1n2_t* x);
void onumm1n2_feval_to(coeff_t* feval_re, onumm1n2_t* x, onumm1n2_t* res);


#endif