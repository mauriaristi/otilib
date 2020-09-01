#ifndef OTI_ONUMM5N5_SCALAR_ALGEBRA_H
#define OTI_ONUMM5N5_SCALAR_ALGEBRA_H

onumm5n5_t onumm5n5_abs(onumm5n5_t* num);
onumm5n5_t onumm5n5_div_ro(coeff_t num, onumm5n5_t* den);
onumm5n5_t onumm5n5_div_oo(onumm5n5_t* num, onumm5n5_t* den);
onumm5n5_t onumm5n5_div_or(onumm5n5_t* num, coeff_t val);
void onumm5n5_div_ro_to(coeff_t num, onumm5n5_t* den, onumm5n5_t* res);
void onumm5n5_div_oo_to(onumm5n5_t* num, onumm5n5_t* den, onumm5n5_t* res);
void onumm5n5_div_or_to(onumm5n5_t* num, coeff_t val, onumm5n5_t* res);
void onumm5n5_abs_to(onumm5n5_t* num, onumm5n5_t* res);

onumm5n5_t onumm5n5_neg(  onumm5n5_t* lhs);
void onumm5n5_neg_to(  onumm5n5_t* lhs, onumm5n5_t* res);
onumm5n5_t onumm5n5_sum_oo(  onumm5n5_t* lhs,  onumm5n5_t* rhs);
void onumm5n5_sum_oo_to(  onumm5n5_t* lhs,  onumm5n5_t* rhs, onumm5n5_t* res);
onumm5n5_t onumm5n5_sum_ro(  coeff_t lhs,  onumm5n5_t* rhs);
void onumm5n5_sum_ro_to(  coeff_t lhs,  onumm5n5_t* rhs, onumm5n5_t* res);
onumm5n5_t onumm5n5_sub_oo(  onumm5n5_t* lhs,  onumm5n5_t* rhs);
void onumm5n5_sub_oo_to(  onumm5n5_t* lhs,  onumm5n5_t* rhs, onumm5n5_t* res);
onumm5n5_t onumm5n5_sub_ro(  coeff_t lhs,  onumm5n5_t* rhs);
void onumm5n5_sub_ro_to(  coeff_t lhs,  onumm5n5_t* rhs, onumm5n5_t* res);
onumm5n5_t onumm5n5_sub_or(  onumm5n5_t* lhs,  coeff_t rhs);
void onumm5n5_sub_or_to(  onumm5n5_t* lhs,  coeff_t rhs, onumm5n5_t* res);
onumm5n5_t onumm5n5_mul_oo(  onumm5n5_t* lhs,  onumm5n5_t* rhs);
void onumm5n5_mul_oo_to(  onumm5n5_t* lhs,  onumm5n5_t* rhs, onumm5n5_t* res);
onumm5n5_t onumm5n5_mul_ro(  coeff_t lhs,  onumm5n5_t* rhs);
void onumm5n5_mul_ro_to(  coeff_t lhs,  onumm5n5_t* rhs, onumm5n5_t* res);
onumm5n5_t onumm5n5_trunc_mul_oo(  onumm5n5_t* lhs,  onumm5n5_t* rhs);
void onumm5n5_trunc_mul_oo_to(  onumm5n5_t* lhs,  onumm5n5_t* rhs, onumm5n5_t* res);
onumm5n5_t onumm5n5_gem_oo(  onumm5n5_t* a,  onumm5n5_t* b,  onumm5n5_t* c);
void onumm5n5_gem_oo_to(  onumm5n5_t* a,  onumm5n5_t* b,  onumm5n5_t* c, onumm5n5_t* res);
onumm5n5_t onumm5n5_gem_ro(  coeff_t a,  onumm5n5_t* b,  onumm5n5_t* c);
void onumm5n5_gem_ro_to(  coeff_t a,  onumm5n5_t* b,  onumm5n5_t* c, onumm5n5_t* res);
void onumm5n5_trunc_gem_oo_to( ord_t ord_lhs,  onumm5n5_t* a,  ord_t ord_rhs,  onumm5n5_t* b,  onumm5n5_t* c, onumm5n5_t* res);
onumm5n5_t onumm5n5_feval(coeff_t* feval_re, onumm5n5_t* x);
void onumm5n5_feval_to(coeff_t* feval_re, onumm5n5_t* x, onumm5n5_t* res);


#endif