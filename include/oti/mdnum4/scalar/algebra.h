#ifndef OTI_MDNUM4_SCALAR_ALGEBRA_H
#define OTI_MDNUM4_SCALAR_ALGEBRA_H

mdnum4_t mdnum4_abs(mdnum4_t* num);
mdnum4_t mdnum4_div_ro(coeff_t num, mdnum4_t* den);
mdnum4_t mdnum4_div_oo(mdnum4_t* num, mdnum4_t* den);
mdnum4_t mdnum4_div_or(mdnum4_t* num, coeff_t val);
void mdnum4_div_ro_to(coeff_t num, mdnum4_t* den, mdnum4_t* res);
void mdnum4_div_oo_to(mdnum4_t* num, mdnum4_t* den, mdnum4_t* res);
void mdnum4_div_or_to(mdnum4_t* num, coeff_t val, mdnum4_t* res);
void mdnum4_abs_to(mdnum4_t* num, mdnum4_t* res);

mdnum4_t mdnum4_neg(  mdnum4_t* lhs);
void mdnum4_neg_to(  mdnum4_t* lhs, mdnum4_t* res);
mdnum4_t mdnum4_sum_oo(  mdnum4_t* lhs,  mdnum4_t* rhs);
void mdnum4_sum_oo_to(  mdnum4_t* lhs,  mdnum4_t* rhs, mdnum4_t* res);
mdnum4_t mdnum4_sum_ro(  coeff_t lhs,  mdnum4_t* rhs);
void mdnum4_sum_ro_to(  coeff_t lhs,  mdnum4_t* rhs, mdnum4_t* res);
mdnum4_t mdnum4_sub_oo(  mdnum4_t* lhs,  mdnum4_t* rhs);
void mdnum4_sub_oo_to(  mdnum4_t* lhs,  mdnum4_t* rhs, mdnum4_t* res);
mdnum4_t mdnum4_sub_ro(  coeff_t lhs,  mdnum4_t* rhs);
void mdnum4_sub_ro_to(  coeff_t lhs,  mdnum4_t* rhs, mdnum4_t* res);
mdnum4_t mdnum4_sub_or(  mdnum4_t* lhs,  coeff_t rhs);
void mdnum4_sub_or_to(  mdnum4_t* lhs,  coeff_t rhs, mdnum4_t* res);
mdnum4_t mdnum4_mul_oo(  mdnum4_t* lhs,  mdnum4_t* rhs);
void mdnum4_mul_oo_to(  mdnum4_t* lhs,  mdnum4_t* rhs, mdnum4_t* res);
mdnum4_t mdnum4_mul_ro(  coeff_t lhs,  mdnum4_t* rhs);
void mdnum4_mul_ro_to(  coeff_t lhs,  mdnum4_t* rhs, mdnum4_t* res);
mdnum4_t mdnum4_trunc_mul_oo(  mdnum4_t* lhs,  mdnum4_t* rhs);
void mdnum4_trunc_mul_oo_to(  mdnum4_t* lhs,  mdnum4_t* rhs, mdnum4_t* res);
mdnum4_t mdnum4_gem_oo(  mdnum4_t* a,  mdnum4_t* b,  mdnum4_t* c);
void mdnum4_gem_oo_to(  mdnum4_t* a,  mdnum4_t* b,  mdnum4_t* c, mdnum4_t* res);
mdnum4_t mdnum4_gem_ro(  coeff_t a,  mdnum4_t* b,  mdnum4_t* c);
void mdnum4_gem_ro_to(  coeff_t a,  mdnum4_t* b,  mdnum4_t* c, mdnum4_t* res);
mdnum4_t mdnum4_feval(coeff_t* feval_re, mdnum4_t* x);
void mdnum4_feval_to(coeff_t* feval_re, mdnum4_t* x, mdnum4_t* res);
mdnum4_t mdnum4_neg(  mdnum4_t* lhs);
void mdnum4_neg_to(  mdnum4_t* lhs, mdnum4_t* res);
mdnum4_t mdnum4_sum_oo(  mdnum4_t* lhs,  mdnum4_t* rhs);
void mdnum4_sum_oo_to(  mdnum4_t* lhs,  mdnum4_t* rhs, mdnum4_t* res);
mdnum4_t mdnum4_sum_ro(  coeff_t lhs,  mdnum4_t* rhs);
void mdnum4_sum_ro_to(  coeff_t lhs,  mdnum4_t* rhs, mdnum4_t* res);
mdnum4_t mdnum4_sub_oo(  mdnum4_t* lhs,  mdnum4_t* rhs);
void mdnum4_sub_oo_to(  mdnum4_t* lhs,  mdnum4_t* rhs, mdnum4_t* res);
mdnum4_t mdnum4_sub_ro(  coeff_t lhs,  mdnum4_t* rhs);
void mdnum4_sub_ro_to(  coeff_t lhs,  mdnum4_t* rhs, mdnum4_t* res);
mdnum4_t mdnum4_sub_or(  mdnum4_t* lhs,  coeff_t rhs);
void mdnum4_sub_or_to(  mdnum4_t* lhs,  coeff_t rhs, mdnum4_t* res);
mdnum4_t mdnum4_mul_oo(  mdnum4_t* lhs,  mdnum4_t* rhs);
void mdnum4_mul_oo_to(  mdnum4_t* lhs,  mdnum4_t* rhs, mdnum4_t* res);
mdnum4_t mdnum4_mul_ro(  coeff_t lhs,  mdnum4_t* rhs);
void mdnum4_mul_ro_to(  coeff_t lhs,  mdnum4_t* rhs, mdnum4_t* res);
mdnum4_t mdnum4_trunc_mul_oo(  mdnum4_t* lhs,  mdnum4_t* rhs);
void mdnum4_trunc_mul_oo_to(  mdnum4_t* lhs,  mdnum4_t* rhs, mdnum4_t* res);
mdnum4_t mdnum4_gem_oo(  mdnum4_t* a,  mdnum4_t* b,  mdnum4_t* c);
void mdnum4_gem_oo_to(  mdnum4_t* a,  mdnum4_t* b,  mdnum4_t* c, mdnum4_t* res);
mdnum4_t mdnum4_gem_ro(  coeff_t a,  mdnum4_t* b,  mdnum4_t* c);
void mdnum4_gem_ro_to(  coeff_t a,  mdnum4_t* b,  mdnum4_t* c, mdnum4_t* res);
mdnum4_t mdnum4_feval(coeff_t* feval_re, mdnum4_t* x);
void mdnum4_feval_to(coeff_t* feval_re, mdnum4_t* x, mdnum4_t* res);


#endif