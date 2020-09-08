#ifndef OTI_ONUMM8N2_SCALAR_ALGEBRA_H
#define OTI_ONUMM8N2_SCALAR_ALGEBRA_H

onumm8n2_t onumm8n2_abs(onumm8n2_t* num);
onumm8n2_t onumm8n2_div_ro(coeff_t num, onumm8n2_t* den);
onumm8n2_t onumm8n2_div_oo(onumm8n2_t* num, onumm8n2_t* den);
onumm8n2_t onumm8n2_div_or(onumm8n2_t* num, coeff_t val);
void onumm8n2_div_ro_to(coeff_t num, onumm8n2_t* den, onumm8n2_t* res);
void onumm8n2_div_oo_to(onumm8n2_t* num, onumm8n2_t* den, onumm8n2_t* res);
void onumm8n2_div_or_to(onumm8n2_t* num, coeff_t val, onumm8n2_t* res);
void onumm8n2_abs_to(onumm8n2_t* num, onumm8n2_t* res);

onumm8n2_t onumm8n2_neg(  onumm8n2_t* lhs);
void onumm8n2_neg_to(  onumm8n2_t* lhs, onumm8n2_t* res);
onumm8n2_t onumm8n2_sum_oo(  onumm8n2_t* lhs,  onumm8n2_t* rhs);
void onumm8n2_sum_oo_to(  onumm8n2_t* lhs,  onumm8n2_t* rhs, onumm8n2_t* res);
onumm8n2_t onumm8n2_sum_ro(  coeff_t lhs,  onumm8n2_t* rhs);
void onumm8n2_sum_ro_to(  coeff_t lhs,  onumm8n2_t* rhs, onumm8n2_t* res);
onumm8n2_t onumm8n2_sub_oo(  onumm8n2_t* lhs,  onumm8n2_t* rhs);
void onumm8n2_sub_oo_to(  onumm8n2_t* lhs,  onumm8n2_t* rhs, onumm8n2_t* res);
onumm8n2_t onumm8n2_sub_ro(  coeff_t lhs,  onumm8n2_t* rhs);
void onumm8n2_sub_ro_to(  coeff_t lhs,  onumm8n2_t* rhs, onumm8n2_t* res);
onumm8n2_t onumm8n2_sub_or(  onumm8n2_t* lhs,  coeff_t rhs);
void onumm8n2_sub_or_to(  onumm8n2_t* lhs,  coeff_t rhs, onumm8n2_t* res);
onumm8n2_t onumm8n2_mul_oo(  onumm8n2_t* lhs,  onumm8n2_t* rhs);
void onumm8n2_mul_oo_to(  onumm8n2_t* lhs,  onumm8n2_t* rhs, onumm8n2_t* res);
onumm8n2_t onumm8n2_mul_ro(  coeff_t lhs,  onumm8n2_t* rhs);
void onumm8n2_mul_ro_to(  coeff_t lhs,  onumm8n2_t* rhs, onumm8n2_t* res);
onumm8n2_t onumm8n2_trunc_mul_oo(  onumm8n2_t* lhs,  onumm8n2_t* rhs);
void onumm8n2_trunc_mul_oo_to(  onumm8n2_t* lhs,  onumm8n2_t* rhs, onumm8n2_t* res);
onumm8n2_t onumm8n2_gem_oo(  onumm8n2_t* a,  onumm8n2_t* b,  onumm8n2_t* c);
void onumm8n2_gem_oo_to(  onumm8n2_t* a,  onumm8n2_t* b,  onumm8n2_t* c, onumm8n2_t* res);
onumm8n2_t onumm8n2_gem_ro(  coeff_t a,  onumm8n2_t* b,  onumm8n2_t* c);
void onumm8n2_gem_ro_to(  coeff_t a,  onumm8n2_t* b,  onumm8n2_t* c, onumm8n2_t* res);
void onumm8n2_trunc_gem_oo_to( ord_t ord_lhs,  onumm8n2_t* a,  ord_t ord_rhs,  onumm8n2_t* b,  onumm8n2_t* c, onumm8n2_t* res);
onumm8n2_t onumm8n2_feval(coeff_t* feval_re, onumm8n2_t* x);
void onumm8n2_feval_to(coeff_t* feval_re, onumm8n2_t* x, onumm8n2_t* res);


#endif