#ifndef OTI_MDNUM9_SCALAR_ALGEBRA_H
#define OTI_MDNUM9_SCALAR_ALGEBRA_H

mdnum9_t mdnum9_abs(mdnum9_t* num);
mdnum9_t mdnum9_div_ro(coeff_t num, mdnum9_t* den);
mdnum9_t mdnum9_div_oo(mdnum9_t* num, mdnum9_t* den);
mdnum9_t mdnum9_div_or(mdnum9_t* num, coeff_t val);
void mdnum9_div_ro_to(coeff_t num, mdnum9_t* den, mdnum9_t* res);
void mdnum9_div_oo_to(mdnum9_t* num, mdnum9_t* den, mdnum9_t* res);
void mdnum9_div_or_to(mdnum9_t* num, coeff_t val, mdnum9_t* res);
void mdnum9_abs_to(mdnum9_t* num, mdnum9_t* res);

mdnum9_t mdnum9_neg(  mdnum9_t* lhs);
void mdnum9_neg_to(  mdnum9_t* lhs, mdnum9_t* res);
mdnum9_t mdnum9_sum_oo(  mdnum9_t* lhs,  mdnum9_t* rhs);
void mdnum9_sum_oo_to(  mdnum9_t* lhs,  mdnum9_t* rhs, mdnum9_t* res);
mdnum9_t mdnum9_sum_ro(  coeff_t lhs,  mdnum9_t* rhs);
void mdnum9_sum_ro_to(  coeff_t lhs,  mdnum9_t* rhs, mdnum9_t* res);
mdnum9_t mdnum9_sub_oo(  mdnum9_t* lhs,  mdnum9_t* rhs);
void mdnum9_sub_oo_to(  mdnum9_t* lhs,  mdnum9_t* rhs, mdnum9_t* res);
mdnum9_t mdnum9_sub_ro(  coeff_t lhs,  mdnum9_t* rhs);
void mdnum9_sub_ro_to(  coeff_t lhs,  mdnum9_t* rhs, mdnum9_t* res);
mdnum9_t mdnum9_sub_or(  mdnum9_t* lhs,  coeff_t rhs);
void mdnum9_sub_or_to(  mdnum9_t* lhs,  coeff_t rhs, mdnum9_t* res);
mdnum9_t mdnum9_mul_oo(  mdnum9_t* lhs,  mdnum9_t* rhs);
void mdnum9_mul_oo_to(  mdnum9_t* lhs,  mdnum9_t* rhs, mdnum9_t* res);
mdnum9_t mdnum9_mul_ro(  coeff_t lhs,  mdnum9_t* rhs);
void mdnum9_mul_ro_to(  coeff_t lhs,  mdnum9_t* rhs, mdnum9_t* res);
mdnum9_t mdnum9_trunc_mul_oo(  mdnum9_t* lhs,  mdnum9_t* rhs);
void mdnum9_trunc_mul_oo_to(  mdnum9_t* lhs,  mdnum9_t* rhs, mdnum9_t* res);
mdnum9_t mdnum9_gem_oo(  mdnum9_t* a,  mdnum9_t* b,  mdnum9_t* c);
void mdnum9_gem_oo_to(  mdnum9_t* a,  mdnum9_t* b,  mdnum9_t* c, mdnum9_t* res);
mdnum9_t mdnum9_gem_ro(  coeff_t a,  mdnum9_t* b,  mdnum9_t* c);
void mdnum9_gem_ro_to(  coeff_t a,  mdnum9_t* b,  mdnum9_t* c, mdnum9_t* res);
void mdnum9_trunc_gem_oo_to( ord_t ord_lhs,  mdnum9_t* a,  ord_t ord_rhs,  mdnum9_t* b,  mdnum9_t* c, mdnum9_t* res);
void mdnum9_trunc_sum_oo_to(ord_t order, mdnum9_t* lhs,mdnum9_t* rhs, mdnum9_t* res);
void mdnum9_trunc_sub_oo_to(ord_t order, mdnum9_t* lhs,mdnum9_t* rhs, mdnum9_t* res);
mdnum9_t mdnum9_feval(coeff_t* feval_re, mdnum9_t* x);
void mdnum9_feval_to(coeff_t* feval_re, mdnum9_t* x, mdnum9_t* res);


#endif