#ifndef OTI_MDNUM5_SCALAR_ALGEBRA_H
#define OTI_MDNUM5_SCALAR_ALGEBRA_H

mdnum5_t mdnum5_abs(mdnum5_t* num);
mdnum5_t mdnum5_div_ro(coeff_t num, mdnum5_t* den);
mdnum5_t mdnum5_div_oo(mdnum5_t* num, mdnum5_t* den);
mdnum5_t mdnum5_div_or(mdnum5_t* num, coeff_t val);
void mdnum5_div_ro_to(coeff_t num, mdnum5_t* den, mdnum5_t* res);
void mdnum5_div_oo_to(mdnum5_t* num, mdnum5_t* den, mdnum5_t* res);
void mdnum5_div_or_to(mdnum5_t* num, coeff_t val, mdnum5_t* res);
void mdnum5_abs_to(mdnum5_t* num, mdnum5_t* res);

mdnum5_t mdnum5_neg(  mdnum5_t* lhs);
void mdnum5_neg_to(  mdnum5_t* lhs, mdnum5_t* res);
mdnum5_t mdnum5_sum_oo(  mdnum5_t* lhs,  mdnum5_t* rhs);
void mdnum5_sum_oo_to(  mdnum5_t* lhs,  mdnum5_t* rhs, mdnum5_t* res);
mdnum5_t mdnum5_sum_ro(  coeff_t lhs,  mdnum5_t* rhs);
void mdnum5_sum_ro_to(  coeff_t lhs,  mdnum5_t* rhs, mdnum5_t* res);
mdnum5_t mdnum5_sub_oo(  mdnum5_t* lhs,  mdnum5_t* rhs);
void mdnum5_sub_oo_to(  mdnum5_t* lhs,  mdnum5_t* rhs, mdnum5_t* res);
mdnum5_t mdnum5_sub_ro(  coeff_t lhs,  mdnum5_t* rhs);
void mdnum5_sub_ro_to(  coeff_t lhs,  mdnum5_t* rhs, mdnum5_t* res);
mdnum5_t mdnum5_sub_or(  mdnum5_t* lhs,  coeff_t rhs);
void mdnum5_sub_or_to(  mdnum5_t* lhs,  coeff_t rhs, mdnum5_t* res);
mdnum5_t mdnum5_mul_oo(  mdnum5_t* lhs,  mdnum5_t* rhs);
void mdnum5_mul_oo_to(  mdnum5_t* lhs,  mdnum5_t* rhs, mdnum5_t* res);
mdnum5_t mdnum5_mul_ro(  coeff_t lhs,  mdnum5_t* rhs);
void mdnum5_mul_ro_to(  coeff_t lhs,  mdnum5_t* rhs, mdnum5_t* res);
mdnum5_t mdnum5_trunc_mul_oo(  mdnum5_t* lhs,  mdnum5_t* rhs);
void mdnum5_trunc_mul_oo_to(  mdnum5_t* lhs,  mdnum5_t* rhs, mdnum5_t* res);
mdnum5_t mdnum5_gem_oo(  mdnum5_t* a,  mdnum5_t* b,  mdnum5_t* c);
void mdnum5_gem_oo_to(  mdnum5_t* a,  mdnum5_t* b,  mdnum5_t* c, mdnum5_t* res);
mdnum5_t mdnum5_gem_ro(  coeff_t a,  mdnum5_t* b,  mdnum5_t* c);
void mdnum5_gem_ro_to(  coeff_t a,  mdnum5_t* b,  mdnum5_t* c, mdnum5_t* res);
void mdnum5_trunc_gem_oo_to( ord_t ord_lhs,  mdnum5_t* a,  ord_t ord_rhs,  mdnum5_t* b,  mdnum5_t* c, mdnum5_t* res);
mdnum5_t mdnum5_feval(coeff_t* feval_re, mdnum5_t* x);
void mdnum5_feval_to(coeff_t* feval_re, mdnum5_t* x, mdnum5_t* res);


#endif