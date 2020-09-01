#ifndef OTI_ONUMM5N4_SCALAR_ALGEBRA_H
#define OTI_ONUMM5N4_SCALAR_ALGEBRA_H

onumm5n4_t onumm5n4_abs(onumm5n4_t* num);
onumm5n4_t onumm5n4_div_ro(coeff_t num, onumm5n4_t* den);
onumm5n4_t onumm5n4_div_oo(onumm5n4_t* num, onumm5n4_t* den);
onumm5n4_t onumm5n4_div_or(onumm5n4_t* num, coeff_t val);
void onumm5n4_div_ro_to(coeff_t num, onumm5n4_t* den, onumm5n4_t* res);
void onumm5n4_div_oo_to(onumm5n4_t* num, onumm5n4_t* den, onumm5n4_t* res);
void onumm5n4_div_or_to(onumm5n4_t* num, coeff_t val, onumm5n4_t* res);
void onumm5n4_abs_to(onumm5n4_t* num, onumm5n4_t* res);

onumm5n4_t onumm5n4_neg(  onumm5n4_t* lhs);
void onumm5n4_neg_to(  onumm5n4_t* lhs, onumm5n4_t* res);
onumm5n4_t onumm5n4_sum_oo(  onumm5n4_t* lhs,  onumm5n4_t* rhs);
void onumm5n4_sum_oo_to(  onumm5n4_t* lhs,  onumm5n4_t* rhs, onumm5n4_t* res);
onumm5n4_t onumm5n4_sum_ro(  coeff_t lhs,  onumm5n4_t* rhs);
void onumm5n4_sum_ro_to(  coeff_t lhs,  onumm5n4_t* rhs, onumm5n4_t* res);
onumm5n4_t onumm5n4_sub_oo(  onumm5n4_t* lhs,  onumm5n4_t* rhs);
void onumm5n4_sub_oo_to(  onumm5n4_t* lhs,  onumm5n4_t* rhs, onumm5n4_t* res);
onumm5n4_t onumm5n4_sub_ro(  coeff_t lhs,  onumm5n4_t* rhs);
void onumm5n4_sub_ro_to(  coeff_t lhs,  onumm5n4_t* rhs, onumm5n4_t* res);
onumm5n4_t onumm5n4_sub_or(  onumm5n4_t* lhs,  coeff_t rhs);
void onumm5n4_sub_or_to(  onumm5n4_t* lhs,  coeff_t rhs, onumm5n4_t* res);
onumm5n4_t onumm5n4_mul_oo(  onumm5n4_t* lhs,  onumm5n4_t* rhs);
void onumm5n4_mul_oo_to(  onumm5n4_t* lhs,  onumm5n4_t* rhs, onumm5n4_t* res);
onumm5n4_t onumm5n4_mul_ro(  coeff_t lhs,  onumm5n4_t* rhs);
void onumm5n4_mul_ro_to(  coeff_t lhs,  onumm5n4_t* rhs, onumm5n4_t* res);
onumm5n4_t onumm5n4_trunc_mul_oo(  onumm5n4_t* lhs,  onumm5n4_t* rhs);
void onumm5n4_trunc_mul_oo_to(  onumm5n4_t* lhs,  onumm5n4_t* rhs, onumm5n4_t* res);
onumm5n4_t onumm5n4_gem_oo(  onumm5n4_t* a,  onumm5n4_t* b,  onumm5n4_t* c);
void onumm5n4_gem_oo_to(  onumm5n4_t* a,  onumm5n4_t* b,  onumm5n4_t* c, onumm5n4_t* res);
onumm5n4_t onumm5n4_gem_ro(  coeff_t a,  onumm5n4_t* b,  onumm5n4_t* c);
void onumm5n4_gem_ro_to(  coeff_t a,  onumm5n4_t* b,  onumm5n4_t* c, onumm5n4_t* res);
void onumm5n4_trunc_gem_oo_to( ord_t ord_lhs,  onumm5n4_t* a,  ord_t ord_rhs,  onumm5n4_t* b,  onumm5n4_t* c, onumm5n4_t* res);
onumm5n4_t onumm5n4_feval(coeff_t* feval_re, onumm5n4_t* x);
void onumm5n4_feval_to(coeff_t* feval_re, onumm5n4_t* x, onumm5n4_t* res);


#endif