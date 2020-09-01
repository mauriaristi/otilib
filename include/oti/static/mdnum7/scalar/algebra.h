#ifndef OTI_MDNUM7_SCALAR_ALGEBRA_H
#define OTI_MDNUM7_SCALAR_ALGEBRA_H

mdnum7_t mdnum7_abs(mdnum7_t* num);
mdnum7_t mdnum7_div_ro(coeff_t num, mdnum7_t* den);
mdnum7_t mdnum7_div_oo(mdnum7_t* num, mdnum7_t* den);
mdnum7_t mdnum7_div_or(mdnum7_t* num, coeff_t val);
void mdnum7_div_ro_to(coeff_t num, mdnum7_t* den, mdnum7_t* res);
void mdnum7_div_oo_to(mdnum7_t* num, mdnum7_t* den, mdnum7_t* res);
void mdnum7_div_or_to(mdnum7_t* num, coeff_t val, mdnum7_t* res);
void mdnum7_abs_to(mdnum7_t* num, mdnum7_t* res);

mdnum7_t mdnum7_neg(  mdnum7_t* lhs);
void mdnum7_neg_to(  mdnum7_t* lhs, mdnum7_t* res);
mdnum7_t mdnum7_sum_oo(  mdnum7_t* lhs,  mdnum7_t* rhs);
void mdnum7_sum_oo_to(  mdnum7_t* lhs,  mdnum7_t* rhs, mdnum7_t* res);
mdnum7_t mdnum7_sum_ro(  coeff_t lhs,  mdnum7_t* rhs);
void mdnum7_sum_ro_to(  coeff_t lhs,  mdnum7_t* rhs, mdnum7_t* res);
mdnum7_t mdnum7_sub_oo(  mdnum7_t* lhs,  mdnum7_t* rhs);
void mdnum7_sub_oo_to(  mdnum7_t* lhs,  mdnum7_t* rhs, mdnum7_t* res);
mdnum7_t mdnum7_sub_ro(  coeff_t lhs,  mdnum7_t* rhs);
void mdnum7_sub_ro_to(  coeff_t lhs,  mdnum7_t* rhs, mdnum7_t* res);
mdnum7_t mdnum7_sub_or(  mdnum7_t* lhs,  coeff_t rhs);
void mdnum7_sub_or_to(  mdnum7_t* lhs,  coeff_t rhs, mdnum7_t* res);
mdnum7_t mdnum7_mul_oo(  mdnum7_t* lhs,  mdnum7_t* rhs);
void mdnum7_mul_oo_to(  mdnum7_t* lhs,  mdnum7_t* rhs, mdnum7_t* res);
mdnum7_t mdnum7_mul_ro(  coeff_t lhs,  mdnum7_t* rhs);
void mdnum7_mul_ro_to(  coeff_t lhs,  mdnum7_t* rhs, mdnum7_t* res);
mdnum7_t mdnum7_trunc_mul_oo(  mdnum7_t* lhs,  mdnum7_t* rhs);
void mdnum7_trunc_mul_oo_to(  mdnum7_t* lhs,  mdnum7_t* rhs, mdnum7_t* res);
mdnum7_t mdnum7_gem_oo(  mdnum7_t* a,  mdnum7_t* b,  mdnum7_t* c);
void mdnum7_gem_oo_to(  mdnum7_t* a,  mdnum7_t* b,  mdnum7_t* c, mdnum7_t* res);
mdnum7_t mdnum7_gem_ro(  coeff_t a,  mdnum7_t* b,  mdnum7_t* c);
void mdnum7_gem_ro_to(  coeff_t a,  mdnum7_t* b,  mdnum7_t* c, mdnum7_t* res);
void mdnum7_trunc_gem_oo_to( ord_t ord_lhs,  mdnum7_t* a,  ord_t ord_rhs,  mdnum7_t* b,  mdnum7_t* c, mdnum7_t* res);
mdnum7_t mdnum7_feval(coeff_t* feval_re, mdnum7_t* x);
void mdnum7_feval_to(coeff_t* feval_re, mdnum7_t* x, mdnum7_t* res);


#endif