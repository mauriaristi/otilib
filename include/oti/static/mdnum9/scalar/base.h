#ifndef OTI_MDNUM9_SCALAR_BASE_H
#define OTI_MDNUM9_SCALAR_BASE_H

// Not implemented correctly:
void mdnum9_set_im_o(mdnum9_t* num, imdir_t idx, ord_t order, mdnum9_t* res);
void mdnum9_set_deriv_r(coeff_t num, imdir_t idx, ord_t order, mdnum9_t* res);
void mdnum9_set_deriv_o(mdnum9_t* num, imdir_t idx, ord_t order, mdnum9_t* res);
void mdnum9_extract_im_to( imdir_t idx, ord_t order, mdnum9_t* num, mdnum9_t* res);
mdnum9_t mdnum9_extract_im(imdir_t idx, ord_t order, mdnum9_t* num);
mdnum9_t mdnum9_extract_deriv(imdir_t idx, ord_t order, mdnum9_t* num);
void mdnum9_extract_deriv_to(imdir_t idx, ord_t order, mdnum9_t* num, mdnum9_t* res);
void mdnum9_get_im_to_o(imdir_t idx, ord_t order, mdnum9_t* num, mdnum9_t* res);
mdnum9_t mdnum9_get_im_o(imdir_t idx, ord_t order, mdnum9_t* num);
void mdnum9_get_im_to_r(imdir_t idx, ord_t order, mdnum9_t* num, coeff_t* res);

ord_t mdnum9_get_order(mdnum9_t* lhs);
mdnum9_t mdnum9_get_deriv_o( imdir_t idx, ord_t order, mdnum9_t* num);
void mdnum9_get_deriv_to( imdir_t idx, ord_t order, mdnum9_t* num, mdnum9_t* res);
void mdnum9_set_im_r(coeff_t num, imdir_t idx, ord_t order, mdnum9_t* res);

mdnum9_t mdnum9_init(void);
ndir_t mdnum9_get_ndir_order(ord_t order, mdnum9_t* num);
ndir_t mdnum9_get_ndir_total(mdnum9_t* num);
coeff_t* mdnum9_get_order_address(ord_t order, mdnum9_t* num);
mdnum9_t mdnum9_create_r(  coeff_t lhs);
void mdnum9_set_r(  coeff_t lhs, mdnum9_t* res);
void mdnum9_set_o(  mdnum9_t* lhs, mdnum9_t* res);
mdnum9_t mdnum9_get_order_im(ord_t order, mdnum9_t* lhs);
void mdnum9_get_order_im_to(ord_t order, mdnum9_t* lhs, mdnum9_t* res);
coeff_t mdnum9_get_item(imdir_t idx, ord_t order, mdnum9_t* lhs);
coeff_t mdnum9_get_deriv(imdir_t idx, ord_t order, mdnum9_t* lhs);
void mdnum9_set_item(coeff_t val, imdir_t idx, ord_t order, mdnum9_t* x);
mdnum9_t mdnum9_copy(  mdnum9_t* lhs);
void mdnum9_copy_to(  mdnum9_t* lhs, mdnum9_t* res);
mdnum9_t mdnum9_taylor_integrate(coeff_t* deltas,mdnum9_t* lhs);
void mdnum9_taylor_integrate_to(coeff_t* deltas,mdnum9_t* lhs, mdnum9_t* res);
mdnum9_t mdnum9_truncate_im(imdir_t idx, ord_t order, mdnum9_t* lhs);
void mdnum9_truncate_im_to(imdir_t idx, ord_t order, mdnum9_t* lhs, mdnum9_t* res);
void mdnum9_print(  mdnum9_t* lhs);
imdir_t mdnum9_get_indx(imdir_t idx, ord_t order);


#endif