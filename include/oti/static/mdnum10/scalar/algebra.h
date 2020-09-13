#ifndef OTI_MDNUM10_SCALAR_ALGEBRA_H
#define OTI_MDNUM10_SCALAR_ALGEBRA_H

mdnum10_t mdnum10_abs(mdnum10_t* num);
mdnum10_t mdnum10_div_ro(coeff_t num, mdnum10_t* den);
mdnum10_t mdnum10_div_oo(mdnum10_t* num, mdnum10_t* den);
mdnum10_t mdnum10_div_or(mdnum10_t* num, coeff_t val);
void mdnum10_div_ro_to(coeff_t num, mdnum10_t* den, mdnum10_t* res);
void mdnum10_div_oo_to(mdnum10_t* num, mdnum10_t* den, mdnum10_t* res);
void mdnum10_div_or_to(mdnum10_t* num, coeff_t val, mdnum10_t* res);
void mdnum10_abs_to(mdnum10_t* num, mdnum10_t* res);

mdnum10_t mdnum10_neg(  mdnum10_t* lhs);
void mdnum10_neg_to(  mdnum10_t* lhs, mdnum10_t* res);
mdnum10_t mdnum10_sum_oo(  mdnum10_t* lhs,  mdnum10_t* rhs);
void mdnum10_sum_oo_to(  mdnum10_t* lhs,  mdnum10_t* rhs, mdnum10_t* res);
mdnum10_t mdnum10_sum_ro(  coeff_t lhs,  mdnum10_t* rhs);
void mdnum10_sum_ro_to(  coeff_t lhs,  mdnum10_t* rhs, mdnum10_t* res);
mdnum10_t mdnum10_sub_oo(  mdnum10_t* lhs,  mdnum10_t* rhs);
void mdnum10_sub_oo_to(  mdnum10_t* lhs,  mdnum10_t* rhs, mdnum10_t* res);
mdnum10_t mdnum10_sub_ro(  coeff_t lhs,  mdnum10_t* rhs);
void mdnum10_sub_ro_to(  coeff_t lhs,  mdnum10_t* rhs, mdnum10_t* res);
mdnum10_t mdnum10_sub_or(  mdnum10_t* lhs,  coeff_t rhs);
void mdnum10_sub_or_to(  mdnum10_t* lhs,  coeff_t rhs, mdnum10_t* res);
mdnum10_t mdnum10_mul_oo(  mdnum10_t* lhs,  mdnum10_t* rhs);
void mdnum10_mul_oo_to(  mdnum10_t* lhs,  mdnum10_t* rhs, mdnum10_t* res);
mdnum10_t mdnum10_mul_ro(  coeff_t lhs,  mdnum10_t* rhs);
void mdnum10_mul_ro_to(  coeff_t lhs,  mdnum10_t* rhs, mdnum10_t* res);
mdnum10_t mdnum10_trunc_mul_oo(  mdnum10_t* lhs,  mdnum10_t* rhs);
void mdnum10_trunc_mul_oo_to(  mdnum10_t* lhs,  mdnum10_t* rhs, mdnum10_t* res);
mdnum10_t mdnum10_gem_oo(  mdnum10_t* a,  mdnum10_t* b,  mdnum10_t* c);
void mdnum10_gem_oo_to(  mdnum10_t* a,  mdnum10_t* b,  mdnum10_t* c, mdnum10_t* res);
mdnum10_t mdnum10_gem_ro(  coeff_t a,  mdnum10_t* b,  mdnum10_t* c);
void mdnum10_gem_ro_to(  coeff_t a,  mdnum10_t* b,  mdnum10_t* c, mdnum10_t* res);
void mdnum10_trunc_gem_oo_to( ord_t ord_lhs,  mdnum10_t* a,  ord_t ord_rhs,  mdnum10_t* b,  mdnum10_t* c, mdnum10_t* res);
void mdnum10_trunc_sum_oo_to(ord_t order, mdnum10_t* lhs,mdnum10_t* rhs, mdnum10_t* res);
void mdnum10_trunc_sub_oo_to(ord_t order, mdnum10_t* lhs,mdnum10_t* rhs, mdnum10_t* res);
mdnum10_t mdnum10_feval(coeff_t* feval_re, mdnum10_t* x);
void mdnum10_feval_to(coeff_t* feval_re, mdnum10_t* x, mdnum10_t* res);


#endif