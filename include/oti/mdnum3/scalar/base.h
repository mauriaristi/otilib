#ifndef OTI_MDNUM3_SCALAR_BASE_H
#define OTI_MDNUM3_SCALAR_BASE_H

// Not implemented correctly:
void mdnum3_set_im_o(mdnum3_t* num, imdir_t idx, ord_t order, mdnum3_t* res);
void mdnum3_set_deriv_r(coeff_t num, imdir_t idx, ord_t order, mdnum3_t* res);
void mdnum3_set_deriv_o(mdnum3_t* num, imdir_t idx, ord_t order, mdnum3_t* res);
void mdnum3_extract_im_to( imdir_t idx, ord_t order, mdnum3_t* num, mdnum3_t* res);
mdnum3_t mdnum3_extract_im(imdir_t idx, ord_t order, mdnum3_t* num);
mdnum3_t mdnum3_extract_deriv(imdir_t idx, ord_t order, mdnum3_t* num);
void mdnum3_extract_deriv_to(imdir_t idx, ord_t order, mdnum3_t* num, mdnum3_t* res);
void mdnum3_get_im_to_o(imdir_t idx, ord_t order, mdnum3_t* num, mdnum3_t* res);
mdnum3_t mdnum3_get_im_o(imdir_t idx, ord_t order, mdnum3_t* num);
void mdnum3_get_im_to_r(imdir_t idx, ord_t order, mdnum3_t* num, coeff_t* res);

ord_t mdnum3_get_order(mdnum3_t* lhs);
mdnum3_t mdnum3_get_deriv_o( imdir_t idx, ord_t order, mdnum3_t* num);
void mdnum3_get_deriv_to( imdir_t idx, ord_t order, mdnum3_t* num, mdnum3_t* res);
void mdnum3_set_im_r(coeff_t num, imdir_t idx, ord_t order, mdnum3_t* res);

mdnum3_t mdnum3_init(void);
ndir_t mdnum3_get_ndir_order(ord_t order, mdnum3_t* num);
ndir_t mdnum3_get_ndir_total(mdnum3_t* num);
mdnum3_t mdnum3_create_r(  coeff_t lhs);
void mdnum3_set_r(  coeff_t lhs, mdnum3_t* res);
void mdnum3_set_o(  mdnum3_t* lhs, mdnum3_t* res);
mdnum3_t mdnum3_get_order_im(ord_t order, mdnum3_t* lhs);
void mdnum3_get_order_im_to(ord_t order, mdnum3_t* lhs, mdnum3_t* res);
coeff_t mdnum3_get_item(imdir_t idx, ord_t order, mdnum3_t* lhs);
coeff_t mdnum3_get_deriv(imdir_t idx, ord_t order, mdnum3_t* lhs);
void mdnum3_set_item(coeff_t val, imdir_t idx, ord_t order, mdnum3_t* x);
mdnum3_t mdnum3_copy(  mdnum3_t* lhs);
void mdnum3_copy_to(  mdnum3_t* lhs, mdnum3_t* res);
mdnum3_t mdnum3_taylor_integrate(coeff_t* deltas,mdnum3_t* lhs);
void mdnum3_taylor_integrate_to(coeff_t* deltas,mdnum3_t* lhs, mdnum3_t* res);
mdnum3_t mdnum3_truncate_im(imdir_t idx, ord_t order, mdnum3_t* lhs);
void mdnum3_truncate_im_to(imdir_t idx, ord_t order, mdnum3_t* lhs, mdnum3_t* res);
void mdnum3_print(  mdnum3_t* lhs);
imdir_t mdnum3_get_indx(imdir_t idx, ord_t order);
mdnum3_t mdnum3_init(void);
ndir_t mdnum3_get_ndir_order(ord_t order, mdnum3_t* num);
ndir_t mdnum3_get_ndir_total(mdnum3_t* num);
mdnum3_t mdnum3_create_r(  coeff_t lhs);
void mdnum3_set_r(  coeff_t lhs, mdnum3_t* res);
void mdnum3_set_o(  mdnum3_t* lhs, mdnum3_t* res);
mdnum3_t mdnum3_get_order_im(ord_t order, mdnum3_t* lhs);
void mdnum3_get_order_im_to(ord_t order, mdnum3_t* lhs, mdnum3_t* res);
coeff_t mdnum3_get_item(imdir_t idx, ord_t order, mdnum3_t* lhs);
coeff_t mdnum3_get_deriv(imdir_t idx, ord_t order, mdnum3_t* lhs);
void mdnum3_set_item(coeff_t val, imdir_t idx, ord_t order, mdnum3_t* x);
mdnum3_t mdnum3_copy(  mdnum3_t* lhs);
void mdnum3_copy_to(  mdnum3_t* lhs, mdnum3_t* res);
mdnum3_t mdnum3_taylor_integrate(coeff_t* deltas,mdnum3_t* lhs);
void mdnum3_taylor_integrate_to(coeff_t* deltas,mdnum3_t* lhs, mdnum3_t* res);
mdnum3_t mdnum3_truncate_im(imdir_t idx, ord_t order, mdnum3_t* lhs);
void mdnum3_truncate_im_to(imdir_t idx, ord_t order, mdnum3_t* lhs, mdnum3_t* res);
void mdnum3_print(  mdnum3_t* lhs);
imdir_t mdnum3_get_indx(imdir_t idx, ord_t order);


#endif