#ifndef OTI_ONUMM8N1_SCALAR_ALGEBRA_H
#define OTI_ONUMM8N1_SCALAR_ALGEBRA_H

onumm8n1_t onumm8n1_abs(onumm8n1_t* num);
onumm8n1_t onumm8n1_div_ro(coeff_t num, onumm8n1_t* den);
onumm8n1_t onumm8n1_div_oo(onumm8n1_t* num, onumm8n1_t* den);
onumm8n1_t onumm8n1_div_or(onumm8n1_t* num, coeff_t val);
void onumm8n1_div_ro_to(coeff_t num, onumm8n1_t* den, onumm8n1_t* res);
void onumm8n1_div_oo_to(onumm8n1_t* num, onumm8n1_t* den, onumm8n1_t* res);
void onumm8n1_div_or_to(onumm8n1_t* num, coeff_t val, onumm8n1_t* res);
void onumm8n1_abs_to(onumm8n1_t* num, onumm8n1_t* res);

onumm8n1_t onumm8n1_neg(  onumm8n1_t* lhs);
void onumm8n1_neg_to(  onumm8n1_t* lhs, onumm8n1_t* res);
onumm8n1_t onumm8n1_sum_oo(  onumm8n1_t* lhs,  onumm8n1_t* rhs);
void onumm8n1_sum_oo_to(  onumm8n1_t* lhs,  onumm8n1_t* rhs, onumm8n1_t* res);
onumm8n1_t onumm8n1_sum_ro(  coeff_t lhs,  onumm8n1_t* rhs);
void onumm8n1_sum_ro_to(  coeff_t lhs,  onumm8n1_t* rhs, onumm8n1_t* res);
onumm8n1_t onumm8n1_sub_oo(  onumm8n1_t* lhs,  onumm8n1_t* rhs);
void onumm8n1_sub_oo_to(  onumm8n1_t* lhs,  onumm8n1_t* rhs, onumm8n1_t* res);
onumm8n1_t onumm8n1_sub_ro(  coeff_t lhs,  onumm8n1_t* rhs);
void onumm8n1_sub_ro_to(  coeff_t lhs,  onumm8n1_t* rhs, onumm8n1_t* res);
onumm8n1_t onumm8n1_sub_or(  onumm8n1_t* lhs,  coeff_t rhs);
void onumm8n1_sub_or_to(  onumm8n1_t* lhs,  coeff_t rhs, onumm8n1_t* res);
onumm8n1_t onumm8n1_mul_oo(  onumm8n1_t* lhs,  onumm8n1_t* rhs);
void onumm8n1_mul_oo_to(  onumm8n1_t* lhs,  onumm8n1_t* rhs, onumm8n1_t* res);
onumm8n1_t onumm8n1_mul_ro(  coeff_t lhs,  onumm8n1_t* rhs);
void onumm8n1_mul_ro_to(  coeff_t lhs,  onumm8n1_t* rhs, onumm8n1_t* res);
onumm8n1_t onumm8n1_trunc_mul_oo(  onumm8n1_t* lhs,  onumm8n1_t* rhs);
void onumm8n1_trunc_mul_oo_to(  onumm8n1_t* lhs,  onumm8n1_t* rhs, onumm8n1_t* res);
onumm8n1_t onumm8n1_gem_oo(  onumm8n1_t* a,  onumm8n1_t* b,  onumm8n1_t* c);
void onumm8n1_gem_oo_to(  onumm8n1_t* a,  onumm8n1_t* b,  onumm8n1_t* c, onumm8n1_t* res);
onumm8n1_t onumm8n1_gem_ro(  coeff_t a,  onumm8n1_t* b,  onumm8n1_t* c);
void onumm8n1_gem_ro_to(  coeff_t a,  onumm8n1_t* b,  onumm8n1_t* c, onumm8n1_t* res);
void onumm8n1_trunc_gem_oo_to( ord_t ord_lhs,  onumm8n1_t* a,  ord_t ord_rhs,  onumm8n1_t* b,  onumm8n1_t* c, onumm8n1_t* res);
onumm8n1_t onumm8n1_feval(coeff_t* feval_re, onumm8n1_t* x);
void onumm8n1_feval_to(coeff_t* feval_re, onumm8n1_t* x, onumm8n1_t* res);


#endif