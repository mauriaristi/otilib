#ifndef OTI_ONUMM5N3_SCALAR_ALGEBRA_H
#define OTI_ONUMM5N3_SCALAR_ALGEBRA_H

onumm5n3_t onumm5n3_abs(onumm5n3_t* num);
onumm5n3_t onumm5n3_div_ro(coeff_t num, onumm5n3_t* den);
onumm5n3_t onumm5n3_div_oo(onumm5n3_t* num, onumm5n3_t* den);
onumm5n3_t onumm5n3_div_or(onumm5n3_t* num, coeff_t val);
void onumm5n3_div_ro_to(coeff_t num, onumm5n3_t* den, onumm5n3_t* res);
void onumm5n3_div_oo_to(onumm5n3_t* num, onumm5n3_t* den, onumm5n3_t* res);
void onumm5n3_div_or_to(onumm5n3_t* num, coeff_t val, onumm5n3_t* res);
void onumm5n3_abs_to(onumm5n3_t* num, onumm5n3_t* res);

onumm5n3_t onumm5n3_neg(  onumm5n3_t* lhs);
void onumm5n3_neg_to(  onumm5n3_t* lhs, onumm5n3_t* res);
onumm5n3_t onumm5n3_sum_oo(  onumm5n3_t* lhs,  onumm5n3_t* rhs);
void onumm5n3_sum_oo_to(  onumm5n3_t* lhs,  onumm5n3_t* rhs, onumm5n3_t* res);
onumm5n3_t onumm5n3_sum_ro(  coeff_t lhs,  onumm5n3_t* rhs);
void onumm5n3_sum_ro_to(  coeff_t lhs,  onumm5n3_t* rhs, onumm5n3_t* res);
onumm5n3_t onumm5n3_sub_oo(  onumm5n3_t* lhs,  onumm5n3_t* rhs);
void onumm5n3_sub_oo_to(  onumm5n3_t* lhs,  onumm5n3_t* rhs, onumm5n3_t* res);
onumm5n3_t onumm5n3_sub_ro(  coeff_t lhs,  onumm5n3_t* rhs);
void onumm5n3_sub_ro_to(  coeff_t lhs,  onumm5n3_t* rhs, onumm5n3_t* res);
onumm5n3_t onumm5n3_sub_or(  onumm5n3_t* lhs,  coeff_t rhs);
void onumm5n3_sub_or_to(  onumm5n3_t* lhs,  coeff_t rhs, onumm5n3_t* res);
onumm5n3_t onumm5n3_mul_oo(  onumm5n3_t* lhs,  onumm5n3_t* rhs);
void onumm5n3_mul_oo_to(  onumm5n3_t* lhs,  onumm5n3_t* rhs, onumm5n3_t* res);
onumm5n3_t onumm5n3_mul_ro(  coeff_t lhs,  onumm5n3_t* rhs);
void onumm5n3_mul_ro_to(  coeff_t lhs,  onumm5n3_t* rhs, onumm5n3_t* res);
onumm5n3_t onumm5n3_trunc_mul_oo(  onumm5n3_t* lhs,  onumm5n3_t* rhs);
void onumm5n3_trunc_mul_oo_to(  onumm5n3_t* lhs,  onumm5n3_t* rhs, onumm5n3_t* res);
onumm5n3_t onumm5n3_gem_oo(  onumm5n3_t* a,  onumm5n3_t* b,  onumm5n3_t* c);
void onumm5n3_gem_oo_to(  onumm5n3_t* a,  onumm5n3_t* b,  onumm5n3_t* c, onumm5n3_t* res);
onumm5n3_t onumm5n3_gem_ro(  coeff_t a,  onumm5n3_t* b,  onumm5n3_t* c);
void onumm5n3_gem_ro_to(  coeff_t a,  onumm5n3_t* b,  onumm5n3_t* c, onumm5n3_t* res);
void onumm5n3_trunc_gem_oo_to( ord_t ord_lhs,  onumm5n3_t* a,  ord_t ord_rhs,  onumm5n3_t* b,  onumm5n3_t* c, onumm5n3_t* res);
onumm5n3_t onumm5n3_feval(coeff_t* feval_re, onumm5n3_t* x);
void onumm5n3_feval_to(coeff_t* feval_re, onumm5n3_t* x, onumm5n3_t* res);


#endif