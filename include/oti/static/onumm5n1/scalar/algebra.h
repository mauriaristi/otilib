#ifndef OTI_ONUMM5N1_SCALAR_ALGEBRA_H
#define OTI_ONUMM5N1_SCALAR_ALGEBRA_H

onumm5n1_t onumm5n1_abs(onumm5n1_t* num);
onumm5n1_t onumm5n1_div_ro(coeff_t num, onumm5n1_t* den);
onumm5n1_t onumm5n1_div_oo(onumm5n1_t* num, onumm5n1_t* den);
onumm5n1_t onumm5n1_div_or(onumm5n1_t* num, coeff_t val);
void onumm5n1_div_ro_to(coeff_t num, onumm5n1_t* den, onumm5n1_t* res);
void onumm5n1_div_oo_to(onumm5n1_t* num, onumm5n1_t* den, onumm5n1_t* res);
void onumm5n1_div_or_to(onumm5n1_t* num, coeff_t val, onumm5n1_t* res);
void onumm5n1_abs_to(onumm5n1_t* num, onumm5n1_t* res);

onumm5n1_t onumm5n1_neg(  onumm5n1_t* lhs);
void onumm5n1_neg_to(  onumm5n1_t* lhs, onumm5n1_t* res);
onumm5n1_t onumm5n1_sum_oo(  onumm5n1_t* lhs,  onumm5n1_t* rhs);
void onumm5n1_sum_oo_to(  onumm5n1_t* lhs,  onumm5n1_t* rhs, onumm5n1_t* res);
onumm5n1_t onumm5n1_sum_ro(  coeff_t lhs,  onumm5n1_t* rhs);
void onumm5n1_sum_ro_to(  coeff_t lhs,  onumm5n1_t* rhs, onumm5n1_t* res);
onumm5n1_t onumm5n1_sub_oo(  onumm5n1_t* lhs,  onumm5n1_t* rhs);
void onumm5n1_sub_oo_to(  onumm5n1_t* lhs,  onumm5n1_t* rhs, onumm5n1_t* res);
onumm5n1_t onumm5n1_sub_ro(  coeff_t lhs,  onumm5n1_t* rhs);
void onumm5n1_sub_ro_to(  coeff_t lhs,  onumm5n1_t* rhs, onumm5n1_t* res);
onumm5n1_t onumm5n1_sub_or(  onumm5n1_t* lhs,  coeff_t rhs);
void onumm5n1_sub_or_to(  onumm5n1_t* lhs,  coeff_t rhs, onumm5n1_t* res);
onumm5n1_t onumm5n1_mul_oo(  onumm5n1_t* lhs,  onumm5n1_t* rhs);
void onumm5n1_mul_oo_to(  onumm5n1_t* lhs,  onumm5n1_t* rhs, onumm5n1_t* res);
onumm5n1_t onumm5n1_mul_ro(  coeff_t lhs,  onumm5n1_t* rhs);
void onumm5n1_mul_ro_to(  coeff_t lhs,  onumm5n1_t* rhs, onumm5n1_t* res);
onumm5n1_t onumm5n1_trunc_mul_oo(  onumm5n1_t* lhs,  onumm5n1_t* rhs);
void onumm5n1_trunc_mul_oo_to(  onumm5n1_t* lhs,  onumm5n1_t* rhs, onumm5n1_t* res);
onumm5n1_t onumm5n1_gem_oo(  onumm5n1_t* a,  onumm5n1_t* b,  onumm5n1_t* c);
void onumm5n1_gem_oo_to(  onumm5n1_t* a,  onumm5n1_t* b,  onumm5n1_t* c, onumm5n1_t* res);
onumm5n1_t onumm5n1_gem_ro(  coeff_t a,  onumm5n1_t* b,  onumm5n1_t* c);
void onumm5n1_gem_ro_to(  coeff_t a,  onumm5n1_t* b,  onumm5n1_t* c, onumm5n1_t* res);
void onumm5n1_trunc_gem_oo_to( ord_t ord_lhs,  onumm5n1_t* a,  ord_t ord_rhs,  onumm5n1_t* b,  onumm5n1_t* c, onumm5n1_t* res);
onumm5n1_t onumm5n1_feval(coeff_t* feval_re, onumm5n1_t* x);
void onumm5n1_feval_to(coeff_t* feval_re, onumm5n1_t* x, onumm5n1_t* res);


#endif