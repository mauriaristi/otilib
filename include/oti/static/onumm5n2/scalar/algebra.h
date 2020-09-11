#ifndef OTI_ONUMM5N2_SCALAR_ALGEBRA_H
#define OTI_ONUMM5N2_SCALAR_ALGEBRA_H

onumm5n2_t onumm5n2_abs(onumm5n2_t* num);
onumm5n2_t onumm5n2_div_ro(coeff_t num, onumm5n2_t* den);
onumm5n2_t onumm5n2_div_oo(onumm5n2_t* num, onumm5n2_t* den);
onumm5n2_t onumm5n2_div_or(onumm5n2_t* num, coeff_t val);
void onumm5n2_div_ro_to(coeff_t num, onumm5n2_t* den, onumm5n2_t* res);
void onumm5n2_div_oo_to(onumm5n2_t* num, onumm5n2_t* den, onumm5n2_t* res);
void onumm5n2_div_or_to(onumm5n2_t* num, coeff_t val, onumm5n2_t* res);
void onumm5n2_abs_to(onumm5n2_t* num, onumm5n2_t* res);

onumm5n2_t onumm5n2_neg(  onumm5n2_t* lhs);
void onumm5n2_neg_to(  onumm5n2_t* lhs, onumm5n2_t* res);
onumm5n2_t onumm5n2_sum_oo(  onumm5n2_t* lhs,  onumm5n2_t* rhs);
void onumm5n2_sum_oo_to(  onumm5n2_t* lhs,  onumm5n2_t* rhs, onumm5n2_t* res);
onumm5n2_t onumm5n2_sum_ro(  coeff_t lhs,  onumm5n2_t* rhs);
void onumm5n2_sum_ro_to(  coeff_t lhs,  onumm5n2_t* rhs, onumm5n2_t* res);
onumm5n2_t onumm5n2_sub_oo(  onumm5n2_t* lhs,  onumm5n2_t* rhs);
void onumm5n2_sub_oo_to(  onumm5n2_t* lhs,  onumm5n2_t* rhs, onumm5n2_t* res);
onumm5n2_t onumm5n2_sub_ro(  coeff_t lhs,  onumm5n2_t* rhs);
void onumm5n2_sub_ro_to(  coeff_t lhs,  onumm5n2_t* rhs, onumm5n2_t* res);
onumm5n2_t onumm5n2_sub_or(  onumm5n2_t* lhs,  coeff_t rhs);
void onumm5n2_sub_or_to(  onumm5n2_t* lhs,  coeff_t rhs, onumm5n2_t* res);
onumm5n2_t onumm5n2_mul_oo(  onumm5n2_t* lhs,  onumm5n2_t* rhs);
void onumm5n2_mul_oo_to(  onumm5n2_t* lhs,  onumm5n2_t* rhs, onumm5n2_t* res);
onumm5n2_t onumm5n2_mul_ro(  coeff_t lhs,  onumm5n2_t* rhs);
void onumm5n2_mul_ro_to(  coeff_t lhs,  onumm5n2_t* rhs, onumm5n2_t* res);
onumm5n2_t onumm5n2_trunc_mul_oo(  onumm5n2_t* lhs,  onumm5n2_t* rhs);
void onumm5n2_trunc_mul_oo_to(  onumm5n2_t* lhs,  onumm5n2_t* rhs, onumm5n2_t* res);
onumm5n2_t onumm5n2_gem_oo(  onumm5n2_t* a,  onumm5n2_t* b,  onumm5n2_t* c);
void onumm5n2_gem_oo_to(  onumm5n2_t* a,  onumm5n2_t* b,  onumm5n2_t* c, onumm5n2_t* res);
onumm5n2_t onumm5n2_gem_ro(  coeff_t a,  onumm5n2_t* b,  onumm5n2_t* c);
void onumm5n2_gem_ro_to(  coeff_t a,  onumm5n2_t* b,  onumm5n2_t* c, onumm5n2_t* res);
void onumm5n2_trunc_gem_oo_to( ord_t ord_lhs,  onumm5n2_t* a,  ord_t ord_rhs,  onumm5n2_t* b,  onumm5n2_t* c, onumm5n2_t* res);
void onumm5n2_trunc_sum_oo_to(ord_t order, onumm5n2_t* lhs,onumm5n2_t* rhs, onumm5n2_t* res);
void onumm5n2_trunc_sub_oo_to(ord_t order, onumm5n2_t* lhs,onumm5n2_t* rhs, onumm5n2_t* res);
onumm5n2_t onumm5n2_feval(coeff_t* feval_re, onumm5n2_t* x);
void onumm5n2_feval_to(coeff_t* feval_re, onumm5n2_t* x, onumm5n2_t* res);


#endif