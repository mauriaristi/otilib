#ifndef OTI_ONUMM20N1_SCALAR_ALGEBRA_H
#define OTI_ONUMM20N1_SCALAR_ALGEBRA_H

onumm20n1_t onumm20n1_neg(  onumm20n1_t* lhs);
void onumm20n1_neg_to(  onumm20n1_t* lhs, onumm20n1_t* res);
onumm20n1_t onumm20n1_add_oo(  onumm20n1_t* lhs,  onumm20n1_t* rhs);
void onumm20n1_add_oo_to(  onumm20n1_t* lhs,  onumm20n1_t* rhs, onumm20n1_t* res);
onumm20n1_t onumm20n1_add_ro(  coeff_t lhs,  onumm20n1_t* rhs);
void onumm20n1_add_ro_to(  coeff_t lhs,  onumm20n1_t* rhs, onumm20n1_t* res);
onumm20n1_t onumm20n1_sub_oo(  onumm20n1_t* lhs,  onumm20n1_t* rhs);
void onumm20n1_sub_oo_to(  onumm20n1_t* lhs,  onumm20n1_t* rhs, onumm20n1_t* res);
onumm20n1_t onumm20n1_sub_ro(  coeff_t lhs,  onumm20n1_t* rhs);
void onumm20n1_sub_ro_to(  coeff_t lhs,  onumm20n1_t* rhs, onumm20n1_t* res);
onumm20n1_t onumm20n1_sub_or(  onumm20n1_t* lhs,  coeff_t rhs);
void onumm20n1_sub_or_to(  onumm20n1_t* lhs,  coeff_t rhs, onumm20n1_t* res);
onumm20n1_t onumm20n1_mul_oo(  onumm20n1_t* lhs,  onumm20n1_t* rhs);
void onumm20n1_mul_oo_to(  onumm20n1_t* lhs,  onumm20n1_t* rhs, onumm20n1_t* res);
onumm20n1_t onumm20n1_mul_ro(  coeff_t lhs,  onumm20n1_t* rhs);
void onumm20n1_mul_ro_to(  coeff_t lhs,  onumm20n1_t* rhs, onumm20n1_t* res);
onumm20n1_t onumm20n1_trunc_mul_oo(  onumm20n1_t* lhs,  onumm20n1_t* rhs);
void onumm20n1_trunc_mul_oo_to(  onumm20n1_t* lhs,  onumm20n1_t* rhs, onumm20n1_t* res);
onumm20n1_t onumm20n1_gem_oo(  onumm20n1_t* a,  onumm20n1_t* b,  onumm20n1_t* c);
void onumm20n1_gem_oo_to(  onumm20n1_t* a,  onumm20n1_t* b,  onumm20n1_t* c, onumm20n1_t* res);
onumm20n1_t onumm20n1_gem_ro(  coeff_t a,  onumm20n1_t* b,  onumm20n1_t* c);
void onumm20n1_gem_ro_to(  coeff_t a,  onumm20n1_t* b,  onumm20n1_t* c, onumm20n1_t* res);
onumm20n1_t onumm20n1_feval(coeff_t* feval_re, onumm20n1_t* x);
void onumm20n1_feval_to(coeff_t* feval_re, onumm20n1_t* x, onumm20n1_t* res);
onumm20n1_t onumm20n1_neg(  onumm20n1_t* lhs);
void onumm20n1_neg_to(  onumm20n1_t* lhs, onumm20n1_t* res);
onumm20n1_t onumm20n1_add_oo(  onumm20n1_t* lhs,  onumm20n1_t* rhs);
void onumm20n1_add_oo_to(  onumm20n1_t* lhs,  onumm20n1_t* rhs, onumm20n1_t* res);
onumm20n1_t onumm20n1_add_ro(  coeff_t lhs,  onumm20n1_t* rhs);
void onumm20n1_add_ro_to(  coeff_t lhs,  onumm20n1_t* rhs, onumm20n1_t* res);
onumm20n1_t onumm20n1_sub_oo(  onumm20n1_t* lhs,  onumm20n1_t* rhs);
void onumm20n1_sub_oo_to(  onumm20n1_t* lhs,  onumm20n1_t* rhs, onumm20n1_t* res);
onumm20n1_t onumm20n1_sub_ro(  coeff_t lhs,  onumm20n1_t* rhs);
void onumm20n1_sub_ro_to(  coeff_t lhs,  onumm20n1_t* rhs, onumm20n1_t* res);
onumm20n1_t onumm20n1_sub_or(  onumm20n1_t* lhs,  coeff_t rhs);
void onumm20n1_sub_or_to(  onumm20n1_t* lhs,  coeff_t rhs, onumm20n1_t* res);
onumm20n1_t onumm20n1_mul_oo(  onumm20n1_t* lhs,  onumm20n1_t* rhs);
void onumm20n1_mul_oo_to(  onumm20n1_t* lhs,  onumm20n1_t* rhs, onumm20n1_t* res);
onumm20n1_t onumm20n1_mul_ro(  coeff_t lhs,  onumm20n1_t* rhs);
void onumm20n1_mul_ro_to(  coeff_t lhs,  onumm20n1_t* rhs, onumm20n1_t* res);
onumm20n1_t onumm20n1_trunc_mul_oo(  onumm20n1_t* lhs,  onumm20n1_t* rhs);
void onumm20n1_trunc_mul_oo_to(  onumm20n1_t* lhs,  onumm20n1_t* rhs, onumm20n1_t* res);
onumm20n1_t onumm20n1_gem_oo(  onumm20n1_t* a,  onumm20n1_t* b,  onumm20n1_t* c);
void onumm20n1_gem_oo_to(  onumm20n1_t* a,  onumm20n1_t* b,  onumm20n1_t* c, onumm20n1_t* res);
onumm20n1_t onumm20n1_gem_ro(  coeff_t a,  onumm20n1_t* b,  onumm20n1_t* c);
void onumm20n1_gem_ro_to(  coeff_t a,  onumm20n1_t* b,  onumm20n1_t* c, onumm20n1_t* res);
onumm20n1_t onumm20n1_feval(coeff_t* feval_re, onumm20n1_t* x);
void onumm20n1_feval_to(coeff_t* feval_re, onumm20n1_t* x, onumm20n1_t* res);


#endif