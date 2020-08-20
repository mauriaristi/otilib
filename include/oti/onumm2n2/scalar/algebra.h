#ifndef OTI_ONUMM2N2_SCALAR_ALGEBRA_H
#define OTI_ONUMM2N2_SCALAR_ALGEBRA_H

onumm2n2_t onumm2n2_abs(onumm2n2_t* num);
onumm2n2_t onumm2n2_div_ro(coeff_t num, onumm2n2_t* den);
onumm2n2_t onumm2n2_div_oo(onumm2n2_t* num, onumm2n2_t* den);
onumm2n2_t onumm2n2_div_or(onumm2n2_t* num, coeff_t val);
void onumm2n2_div_ro_to(coeff_t num, onumm2n2_t* den, onumm2n2_t* res);
void onumm2n2_div_oo_to(onumm2n2_t* num, onumm2n2_t* den, onumm2n2_t* res);
void onumm2n2_div_or_to(onumm2n2_t* num, coeff_t val, onumm2n2_t* res);
void onumm2n2_abs_to(onumm2n2_t* num, onumm2n2_t* res);

onumm2n2_t onumm2n2_neg(  onumm2n2_t* lhs);
void onumm2n2_neg_to(  onumm2n2_t* lhs, onumm2n2_t* res);
onumm2n2_t onumm2n2_sum_oo(  onumm2n2_t* lhs,  onumm2n2_t* rhs);
void onumm2n2_sum_oo_to(  onumm2n2_t* lhs,  onumm2n2_t* rhs, onumm2n2_t* res);
onumm2n2_t onumm2n2_sum_ro(  coeff_t lhs,  onumm2n2_t* rhs);
void onumm2n2_sum_ro_to(  coeff_t lhs,  onumm2n2_t* rhs, onumm2n2_t* res);
onumm2n2_t onumm2n2_sub_oo(  onumm2n2_t* lhs,  onumm2n2_t* rhs);
void onumm2n2_sub_oo_to(  onumm2n2_t* lhs,  onumm2n2_t* rhs, onumm2n2_t* res);
onumm2n2_t onumm2n2_sub_ro(  coeff_t lhs,  onumm2n2_t* rhs);
void onumm2n2_sub_ro_to(  coeff_t lhs,  onumm2n2_t* rhs, onumm2n2_t* res);
onumm2n2_t onumm2n2_sub_or(  onumm2n2_t* lhs,  coeff_t rhs);
void onumm2n2_sub_or_to(  onumm2n2_t* lhs,  coeff_t rhs, onumm2n2_t* res);
onumm2n2_t onumm2n2_mul_oo(  onumm2n2_t* lhs,  onumm2n2_t* rhs);
void onumm2n2_mul_oo_to(  onumm2n2_t* lhs,  onumm2n2_t* rhs, onumm2n2_t* res);
onumm2n2_t onumm2n2_mul_ro(  coeff_t lhs,  onumm2n2_t* rhs);
void onumm2n2_mul_ro_to(  coeff_t lhs,  onumm2n2_t* rhs, onumm2n2_t* res);
onumm2n2_t onumm2n2_trunc_mul_oo(  onumm2n2_t* lhs,  onumm2n2_t* rhs);
void onumm2n2_trunc_mul_oo_to(  onumm2n2_t* lhs,  onumm2n2_t* rhs, onumm2n2_t* res);
onumm2n2_t onumm2n2_gem_oo(  onumm2n2_t* a,  onumm2n2_t* b,  onumm2n2_t* c);
void onumm2n2_gem_oo_to(  onumm2n2_t* a,  onumm2n2_t* b,  onumm2n2_t* c, onumm2n2_t* res);
onumm2n2_t onumm2n2_gem_ro(  coeff_t a,  onumm2n2_t* b,  onumm2n2_t* c);
void onumm2n2_gem_ro_to(  coeff_t a,  onumm2n2_t* b,  onumm2n2_t* c, onumm2n2_t* res);
onumm2n2_t onumm2n2_feval(coeff_t* feval_re, onumm2n2_t* x);
void onumm2n2_feval_to(coeff_t* feval_re, onumm2n2_t* x, onumm2n2_t* res);
onumm2n2_t onumm2n2_neg(  onumm2n2_t* lhs);
void onumm2n2_neg_to(  onumm2n2_t* lhs, onumm2n2_t* res);
onumm2n2_t onumm2n2_sum_oo(  onumm2n2_t* lhs,  onumm2n2_t* rhs);
void onumm2n2_sum_oo_to(  onumm2n2_t* lhs,  onumm2n2_t* rhs, onumm2n2_t* res);
onumm2n2_t onumm2n2_sum_ro(  coeff_t lhs,  onumm2n2_t* rhs);
void onumm2n2_sum_ro_to(  coeff_t lhs,  onumm2n2_t* rhs, onumm2n2_t* res);
onumm2n2_t onumm2n2_sub_oo(  onumm2n2_t* lhs,  onumm2n2_t* rhs);
void onumm2n2_sub_oo_to(  onumm2n2_t* lhs,  onumm2n2_t* rhs, onumm2n2_t* res);
onumm2n2_t onumm2n2_sub_ro(  coeff_t lhs,  onumm2n2_t* rhs);
void onumm2n2_sub_ro_to(  coeff_t lhs,  onumm2n2_t* rhs, onumm2n2_t* res);
onumm2n2_t onumm2n2_sub_or(  onumm2n2_t* lhs,  coeff_t rhs);
void onumm2n2_sub_or_to(  onumm2n2_t* lhs,  coeff_t rhs, onumm2n2_t* res);
onumm2n2_t onumm2n2_mul_oo(  onumm2n2_t* lhs,  onumm2n2_t* rhs);
void onumm2n2_mul_oo_to(  onumm2n2_t* lhs,  onumm2n2_t* rhs, onumm2n2_t* res);
onumm2n2_t onumm2n2_mul_ro(  coeff_t lhs,  onumm2n2_t* rhs);
void onumm2n2_mul_ro_to(  coeff_t lhs,  onumm2n2_t* rhs, onumm2n2_t* res);
onumm2n2_t onumm2n2_trunc_mul_oo(  onumm2n2_t* lhs,  onumm2n2_t* rhs);
void onumm2n2_trunc_mul_oo_to(  onumm2n2_t* lhs,  onumm2n2_t* rhs, onumm2n2_t* res);
onumm2n2_t onumm2n2_gem_oo(  onumm2n2_t* a,  onumm2n2_t* b,  onumm2n2_t* c);
void onumm2n2_gem_oo_to(  onumm2n2_t* a,  onumm2n2_t* b,  onumm2n2_t* c, onumm2n2_t* res);
onumm2n2_t onumm2n2_gem_ro(  coeff_t a,  onumm2n2_t* b,  onumm2n2_t* c);
void onumm2n2_gem_ro_to(  coeff_t a,  onumm2n2_t* b,  onumm2n2_t* c, onumm2n2_t* res);
onumm2n2_t onumm2n2_feval(coeff_t* feval_re, onumm2n2_t* x);
void onumm2n2_feval_to(coeff_t* feval_re, onumm2n2_t* x, onumm2n2_t* res);


#endif