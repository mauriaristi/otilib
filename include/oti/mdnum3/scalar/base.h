#ifndef OTI_MDNUM3_SCALAR_BASE_H
#define OTI_MDNUM3_SCALAR_BASE_H

mdnum3_t mdnum3_init();
mdnum3_t mdnum3_create_r(  coeff_t lhs);
void mdnum3_set_r(  coeff_t lhs, mdnum3_t* res);
void mdnum3_set_o(  mdnum3_t* lhs, mdnum3_t* res);
coeff_t mdnum3_get_item(imdir_t idx, ord_t order, mdnum3_t* lhs);
void mdnum3_set_item(coeff_t val, imdir_t idx, ord_t order, mdnum3_t* x);
mdnum3_t mdnum3_copy(  mdnum3_t* lhs);
void mdnum3_copy_to(  mdnum3_t* lhs, mdnum3_t* res);
void mdnum3_print(  mdnum3_t* lhs);
mdnum3_t mdnum3_init();
mdnum3_t mdnum3_create_r(  coeff_t lhs);
void mdnum3_set_r(  coeff_t lhs, mdnum3_t* res);
void mdnum3_set_o(  mdnum3_t* lhs, mdnum3_t* res);
coeff_t mdnum3_get_item(imdir_t idx, ord_t order, mdnum3_t* lhs);
void mdnum3_set_item(coeff_t val, imdir_t idx, ord_t order, mdnum3_t* x);
mdnum3_t mdnum3_copy(  mdnum3_t* lhs);
void mdnum3_copy_to(  mdnum3_t* lhs, mdnum3_t* res);
void mdnum3_print(  mdnum3_t* lhs);


#endif