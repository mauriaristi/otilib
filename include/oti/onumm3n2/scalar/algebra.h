#ifndef OTI_ONUMM3N2_SCALAR_ALGEBRA_H
#define OTI_ONUMM3N2_SCALAR_ALGEBRA_H

onumm3n2_t onumm3n2_neg(  onumm3n2_t* lhs);
void onumm3n2_neg_to(  onumm3n2_t* lhs, onumm3n2_t* res);
onumm3n2_t onumm3n2_add_oo(  onumm3n2_t* lhs,  onumm3n2_t* rhs);
void onumm3n2_add_oo_to(  onumm3n2_t* lhs,  onumm3n2_t* rhs, onumm3n2_t* res);
onumm3n2_t onumm3n2_add_ro(  coeff_t lhs,  onumm3n2_t* rhs);
void onumm3n2_add_ro_to(  coeff_t lhs,  onumm3n2_t* rhs, onumm3n2_t* res);
onumm3n2_t onumm3n2_sub_oo(  onumm3n2_t* lhs,  onumm3n2_t* rhs);
void onumm3n2_sub_oo_to(  onumm3n2_t* lhs,  onumm3n2_t* rhs, onumm3n2_t* res);
onumm3n2_t onumm3n2_sub_ro(  coeff_t lhs,  onumm3n2_t* rhs);
void onumm3n2_sub_ro_to(  coeff_t lhs,  onumm3n2_t* rhs, onumm3n2_t* res);
onumm3n2_t onumm3n2_sub_or(  onumm3n2_t* lhs,  coeff_t rhs);
void onumm3n2_sub_or_to(  onumm3n2_t* lhs,  coeff_t rhs, onumm3n2_t* res);
onumm3n2_t onumm3n2_mul_oo(  onumm3n2_t* lhs,  onumm3n2_t* rhs);
void onumm3n2_mul_oo_to(  onumm3n2_t* lhs,  onumm3n2_t* rhs, onumm3n2_t* res);
onumm3n2_t onumm3n2_mul_ro(  coeff_t lhs,  onumm3n2_t* rhs);
void onumm3n2_mul_ro_to(  coeff_t lhs,  onumm3n2_t* rhs, onumm3n2_t* res);
onumm3n2_t onumm3n2_trunc_mul_oo(  onumm3n2_t* lhs,  onumm3n2_t* rhs);
void onumm3n2_trunc_mul_oo_to(  onumm3n2_t* lhs,  onumm3n2_t* rhs, onumm3n2_t* res);
onumm3n2_t onumm3n2_gem_oo(  onumm3n2_t* a,  onumm3n2_t* b,  onumm3n2_t* c);
void onumm3n2_gem_oo_to(  onumm3n2_t* a,  onumm3n2_t* b,  onumm3n2_t* c, onumm3n2_t* res);
onumm3n2_t onumm3n2_gem_ro(  coeff_t a,  onumm3n2_t* b,  onumm3n2_t* c);
void onumm3n2_gem_ro_to(  coeff_t a,  onumm3n2_t* b,  onumm3n2_t* c, onumm3n2_t* res);
onumm3n2_t onumm3n2_feval(coeff_t* feval_re, onumm3n2_t* x);
void onumm3n2_feval_to(coeff_t* feval_re, onumm3n2_t* x, onumm3n2_t* res);
onumm3n2_t onumm3n2_neg(  onumm3n2_t* lhs);
void onumm3n2_neg_to(  onumm3n2_t* lhs, onumm3n2_t* res);
onumm3n2_t onumm3n2_add_oo(  onumm3n2_t* lhs,  onumm3n2_t* rhs);
void onumm3n2_add_oo_to(  onumm3n2_t* lhs,  onumm3n2_t* rhs, onumm3n2_t* res);
onumm3n2_t onumm3n2_add_ro(  coeff_t lhs,  onumm3n2_t* rhs);
void onumm3n2_add_ro_to(  coeff_t lhs,  onumm3n2_t* rhs, onumm3n2_t* res);
onumm3n2_t onumm3n2_sub_oo(  onumm3n2_t* lhs,  onumm3n2_t* rhs);
void onumm3n2_sub_oo_to(  onumm3n2_t* lhs,  onumm3n2_t* rhs, onumm3n2_t* res);
onumm3n2_t onumm3n2_sub_ro(  coeff_t lhs,  onumm3n2_t* rhs);
void onumm3n2_sub_ro_to(  coeff_t lhs,  onumm3n2_t* rhs, onumm3n2_t* res);
onumm3n2_t onumm3n2_sub_or(  onumm3n2_t* lhs,  coeff_t rhs);
void onumm3n2_sub_or_to(  onumm3n2_t* lhs,  coeff_t rhs, onumm3n2_t* res);
onumm3n2_t onumm3n2_mul_oo(  onumm3n2_t* lhs,  onumm3n2_t* rhs);
void onumm3n2_mul_oo_to(  onumm3n2_t* lhs,  onumm3n2_t* rhs, onumm3n2_t* res);
onumm3n2_t onumm3n2_mul_ro(  coeff_t lhs,  onumm3n2_t* rhs);
void onumm3n2_mul_ro_to(  coeff_t lhs,  onumm3n2_t* rhs, onumm3n2_t* res);
onumm3n2_t onumm3n2_trunc_mul_oo(  onumm3n2_t* lhs,  onumm3n2_t* rhs);
void onumm3n2_trunc_mul_oo_to(  onumm3n2_t* lhs,  onumm3n2_t* rhs, onumm3n2_t* res);
onumm3n2_t onumm3n2_gem_oo(  onumm3n2_t* a,  onumm3n2_t* b,  onumm3n2_t* c);
void onumm3n2_gem_oo_to(  onumm3n2_t* a,  onumm3n2_t* b,  onumm3n2_t* c, onumm3n2_t* res);
onumm3n2_t onumm3n2_gem_ro(  coeff_t a,  onumm3n2_t* b,  onumm3n2_t* c);
void onumm3n2_gem_ro_to(  coeff_t a,  onumm3n2_t* b,  onumm3n2_t* c, onumm3n2_t* res);
onumm3n2_t onumm3n2_feval(coeff_t* feval_re, onumm3n2_t* x);
void onumm3n2_feval_to(coeff_t* feval_re, onumm3n2_t* x, onumm3n2_t* res);


#endif