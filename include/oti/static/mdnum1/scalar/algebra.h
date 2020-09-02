#ifndef OTI_MDNUM1_SCALAR_ALGEBRA_H
#define OTI_MDNUM1_SCALAR_ALGEBRA_H

mdnum1_t mdnum1_abs(mdnum1_t* num);
mdnum1_t mdnum1_div_ro(coeff_t num, mdnum1_t* den);
mdnum1_t mdnum1_div_oo(mdnum1_t* num, mdnum1_t* den);
mdnum1_t mdnum1_div_or(mdnum1_t* num, coeff_t val);
void mdnum1_div_ro_to(coeff_t num, mdnum1_t* den, mdnum1_t* res);
void mdnum1_div_oo_to(mdnum1_t* num, mdnum1_t* den, mdnum1_t* res);
void mdnum1_div_or_to(mdnum1_t* num, coeff_t val, mdnum1_t* res);
void mdnum1_abs_to(mdnum1_t* num, mdnum1_t* res);

mdnum1_t mdnum1_neg(  mdnum1_t* lhs);
void mdnum1_neg_to(  mdnum1_t* lhs, mdnum1_t* res);
mdnum1_t mdnum1_sum_oo(  mdnum1_t* lhs,  mdnum1_t* rhs);
void mdnum1_sum_oo_to(  mdnum1_t* lhs,  mdnum1_t* rhs, mdnum1_t* res);
mdnum1_t mdnum1_sum_ro(  coeff_t lhs,  mdnum1_t* rhs);
void mdnum1_sum_ro_to(  coeff_t lhs,  mdnum1_t* rhs, mdnum1_t* res);
mdnum1_t mdnum1_sub_oo(  mdnum1_t* lhs,  mdnum1_t* rhs);
void mdnum1_sub_oo_to(  mdnum1_t* lhs,  mdnum1_t* rhs, mdnum1_t* res);
mdnum1_t mdnum1_sub_ro(  coeff_t lhs,  mdnum1_t* rhs);
void mdnum1_sub_ro_to(  coeff_t lhs,  mdnum1_t* rhs, mdnum1_t* res);
mdnum1_t mdnum1_sub_or(  mdnum1_t* lhs,  coeff_t rhs);
void mdnum1_sub_or_to(  mdnum1_t* lhs,  coeff_t rhs, mdnum1_t* res);
mdnum1_t mdnum1_mul_oo(  mdnum1_t* lhs,  mdnum1_t* rhs);
void mdnum1_mul_oo_to(  mdnum1_t* lhs,  mdnum1_t* rhs, mdnum1_t* res);
mdnum1_t mdnum1_mul_ro(  coeff_t lhs,  mdnum1_t* rhs);
void mdnum1_mul_ro_to(  coeff_t lhs,  mdnum1_t* rhs, mdnum1_t* res);
mdnum1_t mdnum1_trunc_mul_oo(  mdnum1_t* lhs,  mdnum1_t* rhs);
void mdnum1_trunc_mul_oo_to(  mdnum1_t* lhs,  mdnum1_t* rhs, mdnum1_t* res);
mdnum1_t mdnum1_gem_oo(  mdnum1_t* a,  mdnum1_t* b,  mdnum1_t* c);
void mdnum1_gem_oo_to(  mdnum1_t* a,  mdnum1_t* b,  mdnum1_t* c, mdnum1_t* res);
mdnum1_t mdnum1_gem_ro(  coeff_t a,  mdnum1_t* b,  mdnum1_t* c);
void mdnum1_gem_ro_to(  coeff_t a,  mdnum1_t* b,  mdnum1_t* c, mdnum1_t* res);
void mdnum1_trunc_gem_oo_to( ord_t ord_lhs,  mdnum1_t* a,  ord_t ord_rhs,  mdnum1_t* b,  mdnum1_t* c, mdnum1_t* res);
mdnum1_t mdnum1_feval(coeff_t* feval_re, mdnum1_t* x);
void mdnum1_feval_to(coeff_t* feval_re, mdnum1_t* x, mdnum1_t* res);


#endif