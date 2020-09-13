#ifndef OTI_MDNUM6_SCALAR_ALGEBRA_H
#define OTI_MDNUM6_SCALAR_ALGEBRA_H

mdnum6_t mdnum6_abs(mdnum6_t* num);
mdnum6_t mdnum6_div_ro(coeff_t num, mdnum6_t* den);
mdnum6_t mdnum6_div_oo(mdnum6_t* num, mdnum6_t* den);
mdnum6_t mdnum6_div_or(mdnum6_t* num, coeff_t val);
void mdnum6_div_ro_to(coeff_t num, mdnum6_t* den, mdnum6_t* res);
void mdnum6_div_oo_to(mdnum6_t* num, mdnum6_t* den, mdnum6_t* res);
void mdnum6_div_or_to(mdnum6_t* num, coeff_t val, mdnum6_t* res);
void mdnum6_abs_to(mdnum6_t* num, mdnum6_t* res);

mdnum6_t mdnum6_neg(  mdnum6_t* lhs);
void mdnum6_neg_to(  mdnum6_t* lhs, mdnum6_t* res);
mdnum6_t mdnum6_sum_oo(  mdnum6_t* lhs,  mdnum6_t* rhs);
void mdnum6_sum_oo_to(  mdnum6_t* lhs,  mdnum6_t* rhs, mdnum6_t* res);
mdnum6_t mdnum6_sum_ro(  coeff_t lhs,  mdnum6_t* rhs);
void mdnum6_sum_ro_to(  coeff_t lhs,  mdnum6_t* rhs, mdnum6_t* res);
mdnum6_t mdnum6_sub_oo(  mdnum6_t* lhs,  mdnum6_t* rhs);
void mdnum6_sub_oo_to(  mdnum6_t* lhs,  mdnum6_t* rhs, mdnum6_t* res);
mdnum6_t mdnum6_sub_ro(  coeff_t lhs,  mdnum6_t* rhs);
void mdnum6_sub_ro_to(  coeff_t lhs,  mdnum6_t* rhs, mdnum6_t* res);
mdnum6_t mdnum6_sub_or(  mdnum6_t* lhs,  coeff_t rhs);
void mdnum6_sub_or_to(  mdnum6_t* lhs,  coeff_t rhs, mdnum6_t* res);
mdnum6_t mdnum6_mul_oo(  mdnum6_t* lhs,  mdnum6_t* rhs);
void mdnum6_mul_oo_to(  mdnum6_t* lhs,  mdnum6_t* rhs, mdnum6_t* res);
mdnum6_t mdnum6_mul_ro(  coeff_t lhs,  mdnum6_t* rhs);
void mdnum6_mul_ro_to(  coeff_t lhs,  mdnum6_t* rhs, mdnum6_t* res);
mdnum6_t mdnum6_trunc_mul_oo(  mdnum6_t* lhs,  mdnum6_t* rhs);
void mdnum6_trunc_mul_oo_to(  mdnum6_t* lhs,  mdnum6_t* rhs, mdnum6_t* res);
mdnum6_t mdnum6_gem_oo(  mdnum6_t* a,  mdnum6_t* b,  mdnum6_t* c);
void mdnum6_gem_oo_to(  mdnum6_t* a,  mdnum6_t* b,  mdnum6_t* c, mdnum6_t* res);
mdnum6_t mdnum6_gem_ro(  coeff_t a,  mdnum6_t* b,  mdnum6_t* c);
void mdnum6_gem_ro_to(  coeff_t a,  mdnum6_t* b,  mdnum6_t* c, mdnum6_t* res);
void mdnum6_trunc_gem_oo_to( ord_t ord_lhs,  mdnum6_t* a,  ord_t ord_rhs,  mdnum6_t* b,  mdnum6_t* c, mdnum6_t* res);
void mdnum6_trunc_sum_oo_to(ord_t order, mdnum6_t* lhs,mdnum6_t* rhs, mdnum6_t* res);
void mdnum6_trunc_sub_oo_to(ord_t order, mdnum6_t* lhs,mdnum6_t* rhs, mdnum6_t* res);
mdnum6_t mdnum6_feval(coeff_t* feval_re, mdnum6_t* x);
void mdnum6_feval_to(coeff_t* feval_re, mdnum6_t* x, mdnum6_t* res);


#endif