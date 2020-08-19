#ifndef OTI_MDNUM2_SCALAR_BASE_H
#define OTI_MDNUM2_SCALAR_BASE_H

mdnum2_t mdnum2_init();
mdnum2_t mdnum2_create_r(  coeff_t lhs);
void mdnum2_set_r_to(  coeff_t lhs, mdnum2_t* res);
void mdnum2_set_o_to(  mdnum2_t* lhs, mdnum2_t* res);
coeff_t mdnum2_get_item(imdir_t idx, ord_t order, mdnum2_t* lhs);
void mdnum2_set_item(coeff_t val, imdir_t idx, ord_t order, mdnum2_t* x);
mdnum2_t mdnum2_copy(  mdnum2_t* lhs);
void mdnum2_copy_to(  mdnum2_t* lhs, mdnum2_t* res);
void mdnum2_print(  mdnum2_t* lhs);
mdnum2_t mdnum2_init();
mdnum2_t mdnum2_create_r(  coeff_t lhs);
void mdnum2_set_r_to(  coeff_t lhs, mdnum2_t* res);
void mdnum2_set_o_to(  mdnum2_t* lhs, mdnum2_t* res);
coeff_t mdnum2_get_item(imdir_t idx, ord_t order, mdnum2_t* lhs);
void mdnum2_set_item(coeff_t val, imdir_t idx, ord_t order, mdnum2_t* x);
mdnum2_t mdnum2_copy(  mdnum2_t* lhs);
void mdnum2_copy_to(  mdnum2_t* lhs, mdnum2_t* res);
void mdnum2_print(  mdnum2_t* lhs);


#endif