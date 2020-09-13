#ifndef OTI_MDNUM10_SCALAR_BASE_H
#define OTI_MDNUM10_SCALAR_BASE_H

// Not implemented correctly:
void mdnum10_set_im_o(mdnum10_t* num, imdir_t idx, ord_t order, mdnum10_t* res);
void mdnum10_set_deriv_r(coeff_t num, imdir_t idx, ord_t order, mdnum10_t* res);
void mdnum10_set_deriv_o(mdnum10_t* num, imdir_t idx, ord_t order, mdnum10_t* res);
void mdnum10_extract_im_to( imdir_t idx, ord_t order, mdnum10_t* num, mdnum10_t* res);
mdnum10_t mdnum10_extract_im(imdir_t idx, ord_t order, mdnum10_t* num);
mdnum10_t mdnum10_extract_deriv(imdir_t idx, ord_t order, mdnum10_t* num);
void mdnum10_extract_deriv_to(imdir_t idx, ord_t order, mdnum10_t* num, mdnum10_t* res);
void mdnum10_get_im_to_o(imdir_t idx, ord_t order, mdnum10_t* num, mdnum10_t* res);
mdnum10_t mdnum10_get_im_o(imdir_t idx, ord_t order, mdnum10_t* num);
void mdnum10_get_im_to_r(imdir_t idx, ord_t order, mdnum10_t* num, coeff_t* res);

ord_t mdnum10_get_order(mdnum10_t* lhs);
mdnum10_t mdnum10_get_deriv_o( imdir_t idx, ord_t order, mdnum10_t* num);
void mdnum10_get_deriv_to( imdir_t idx, ord_t order, mdnum10_t* num, mdnum10_t* res);
void mdnum10_set_im_r(coeff_t num, imdir_t idx, ord_t order, mdnum10_t* res);

mdnum10_t mdnum10_init(void);
ndir_t mdnum10_get_ndir_order(ord_t order, mdnum10_t* num);
ndir_t mdnum10_get_ndir_total(mdnum10_t* num);
coeff_t* mdnum10_get_order_address(ord_t order, mdnum10_t* num);
mdnum10_t mdnum10_create_r(  coeff_t lhs);
void mdnum10_set_r(  coeff_t lhs, mdnum10_t* res);
void mdnum10_set_o(  mdnum10_t* lhs, mdnum10_t* res);
mdnum10_t mdnum10_get_order_im(ord_t order, mdnum10_t* lhs);
void mdnum10_get_order_im_to(ord_t order, mdnum10_t* lhs, mdnum10_t* res);
coeff_t mdnum10_get_item(imdir_t idx, ord_t order, mdnum10_t* lhs);
coeff_t mdnum10_get_deriv(imdir_t idx, ord_t order, mdnum10_t* lhs);
void mdnum10_set_item(coeff_t val, imdir_t idx, ord_t order, mdnum10_t* x);
mdnum10_t mdnum10_copy(  mdnum10_t* lhs);
void mdnum10_copy_to(  mdnum10_t* lhs, mdnum10_t* res);
mdnum10_t mdnum10_taylor_integrate(coeff_t* deltas,mdnum10_t* lhs);
void mdnum10_taylor_integrate_to(coeff_t* deltas,mdnum10_t* lhs, mdnum10_t* res);
mdnum10_t mdnum10_truncate_im(imdir_t idx, ord_t order, mdnum10_t* lhs);
void mdnum10_truncate_im_to(imdir_t idx, ord_t order, mdnum10_t* lhs, mdnum10_t* res);
void mdnum10_print(  mdnum10_t* lhs);
imdir_t mdnum10_get_indx(imdir_t idx, ord_t order);


#endif