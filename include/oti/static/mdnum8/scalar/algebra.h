#ifndef OTI_MDNUM8_SCALAR_ALGEBRA_H
#define OTI_MDNUM8_SCALAR_ALGEBRA_H

mdnum8_t mdnum8_abs(mdnum8_t* num);
mdnum8_t mdnum8_div_ro(coeff_t num, mdnum8_t* den);
mdnum8_t mdnum8_div_oo(mdnum8_t* num, mdnum8_t* den);
mdnum8_t mdnum8_div_or(mdnum8_t* num, coeff_t val);
void mdnum8_div_ro_to(coeff_t num, mdnum8_t* den, mdnum8_t* res);
void mdnum8_div_oo_to(mdnum8_t* num, mdnum8_t* den, mdnum8_t* res);
void mdnum8_div_or_to(mdnum8_t* num, coeff_t val, mdnum8_t* res);
void mdnum8_abs_to(mdnum8_t* num, mdnum8_t* res);

mdnum8_t mdnum8_neg(  mdnum8_t* lhs);
void mdnum8_neg_to(  mdnum8_t* lhs, mdnum8_t* res);
mdnum8_t mdnum8_sum_oo(  mdnum8_t* lhs,  mdnum8_t* rhs);
void mdnum8_sum_oo_to(  mdnum8_t* lhs,  mdnum8_t* rhs, mdnum8_t* res);
mdnum8_t mdnum8_sum_ro(  coeff_t lhs,  mdnum8_t* rhs);
void mdnum8_sum_ro_to(  coeff_t lhs,  mdnum8_t* rhs, mdnum8_t* res);
mdnum8_t mdnum8_sub_oo(  mdnum8_t* lhs,  mdnum8_t* rhs);
void mdnum8_sub_oo_to(  mdnum8_t* lhs,  mdnum8_t* rhs, mdnum8_t* res);
mdnum8_t mdnum8_sub_ro(  coeff_t lhs,  mdnum8_t* rhs);
void mdnum8_sub_ro_to(  coeff_t lhs,  mdnum8_t* rhs, mdnum8_t* res);
mdnum8_t mdnum8_sub_or(  mdnum8_t* lhs,  coeff_t rhs);
void mdnum8_sub_or_to(  mdnum8_t* lhs,  coeff_t rhs, mdnum8_t* res);
mdnum8_t mdnum8_mul_oo(  mdnum8_t* lhs,  mdnum8_t* rhs);
void mdnum8_mul_oo_to(  mdnum8_t* lhs,  mdnum8_t* rhs, mdnum8_t* res);
mdnum8_t mdnum8_mul_ro(  coeff_t lhs,  mdnum8_t* rhs);
void mdnum8_mul_ro_to(  coeff_t lhs,  mdnum8_t* rhs, mdnum8_t* res);
mdnum8_t mdnum8_trunc_mul_oo(  mdnum8_t* lhs,  mdnum8_t* rhs);
void mdnum8_trunc_mul_oo_to(  mdnum8_t* lhs,  mdnum8_t* rhs, mdnum8_t* res);
mdnum8_t mdnum8_gem_oo(  mdnum8_t* a,  mdnum8_t* b,  mdnum8_t* c);
void mdnum8_gem_oo_to(  mdnum8_t* a,  mdnum8_t* b,  mdnum8_t* c, mdnum8_t* res);
mdnum8_t mdnum8_gem_ro(  coeff_t a,  mdnum8_t* b,  mdnum8_t* c);
void mdnum8_gem_ro_to(  coeff_t a,  mdnum8_t* b,  mdnum8_t* c, mdnum8_t* res);
void mdnum8_trunc_gem_oo_to( ord_t ord_lhs,  mdnum8_t* a,  ord_t ord_rhs,  mdnum8_t* b,  mdnum8_t* c, mdnum8_t* res);
void mdnum8_trunc_sum_oo_to(ord_t order, mdnum8_t* lhs,mdnum8_t* rhs, mdnum8_t* res);
void mdnum8_trunc_sub_oo_to(ord_t order, mdnum8_t* lhs,mdnum8_t* rhs, mdnum8_t* res);
mdnum8_t mdnum8_feval(coeff_t* feval_re, mdnum8_t* x);
void mdnum8_feval_to(coeff_t* feval_re, mdnum8_t* x, mdnum8_t* res);


#endif