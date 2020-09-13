#ifndef OTI_MDNUM8_SCALAR_BASE_H
#define OTI_MDNUM8_SCALAR_BASE_H

// Not implemented correctly:
void mdnum8_set_im_o(mdnum8_t* num, imdir_t idx, ord_t order, mdnum8_t* res);
void mdnum8_set_deriv_r(coeff_t num, imdir_t idx, ord_t order, mdnum8_t* res);
void mdnum8_set_deriv_o(mdnum8_t* num, imdir_t idx, ord_t order, mdnum8_t* res);
void mdnum8_extract_im_to( imdir_t idx, ord_t order, mdnum8_t* num, mdnum8_t* res);
mdnum8_t mdnum8_extract_im(imdir_t idx, ord_t order, mdnum8_t* num);
mdnum8_t mdnum8_extract_deriv(imdir_t idx, ord_t order, mdnum8_t* num);
void mdnum8_extract_deriv_to(imdir_t idx, ord_t order, mdnum8_t* num, mdnum8_t* res);
void mdnum8_get_im_to_o(imdir_t idx, ord_t order, mdnum8_t* num, mdnum8_t* res);
mdnum8_t mdnum8_get_im_o(imdir_t idx, ord_t order, mdnum8_t* num);
void mdnum8_get_im_to_r(imdir_t idx, ord_t order, mdnum8_t* num, coeff_t* res);

ord_t mdnum8_get_order(mdnum8_t* lhs);
mdnum8_t mdnum8_get_deriv_o( imdir_t idx, ord_t order, mdnum8_t* num);
void mdnum8_get_deriv_to( imdir_t idx, ord_t order, mdnum8_t* num, mdnum8_t* res);
void mdnum8_set_im_r(coeff_t num, imdir_t idx, ord_t order, mdnum8_t* res);

mdnum8_t mdnum8_init(void);
ndir_t mdnum8_get_ndir_order(ord_t order, mdnum8_t* num);
ndir_t mdnum8_get_ndir_total(mdnum8_t* num);
coeff_t* mdnum8_get_order_address(ord_t order, mdnum8_t* num);
mdnum8_t mdnum8_create_r(  coeff_t lhs);
void mdnum8_set_r(  coeff_t lhs, mdnum8_t* res);
void mdnum8_set_o(  mdnum8_t* lhs, mdnum8_t* res);
mdnum8_t mdnum8_get_order_im(ord_t order, mdnum8_t* lhs);
void mdnum8_get_order_im_to(ord_t order, mdnum8_t* lhs, mdnum8_t* res);
coeff_t mdnum8_get_item(imdir_t idx, ord_t order, mdnum8_t* lhs);
coeff_t mdnum8_get_deriv(imdir_t idx, ord_t order, mdnum8_t* lhs);
void mdnum8_set_item(coeff_t val, imdir_t idx, ord_t order, mdnum8_t* x);
mdnum8_t mdnum8_copy(  mdnum8_t* lhs);
void mdnum8_copy_to(  mdnum8_t* lhs, mdnum8_t* res);
mdnum8_t mdnum8_taylor_integrate(coeff_t* deltas,mdnum8_t* lhs);
void mdnum8_taylor_integrate_to(coeff_t* deltas,mdnum8_t* lhs, mdnum8_t* res);
mdnum8_t mdnum8_truncate_im(imdir_t idx, ord_t order, mdnum8_t* lhs);
void mdnum8_truncate_im_to(imdir_t idx, ord_t order, mdnum8_t* lhs, mdnum8_t* res);
void mdnum8_print(  mdnum8_t* lhs);
imdir_t mdnum8_get_indx(imdir_t idx, ord_t order);


#endif