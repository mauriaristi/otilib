#ifndef OTI_MDNUM5_SCALAR_BASE_H
#define OTI_MDNUM5_SCALAR_BASE_H

// Not implemented correctly:
void mdnum5_set_im_o(mdnum5_t* num, imdir_t idx, ord_t order, mdnum5_t* res);
void mdnum5_set_deriv_r(coeff_t num, imdir_t idx, ord_t order, mdnum5_t* res);
void mdnum5_set_deriv_o(mdnum5_t* num, imdir_t idx, ord_t order, mdnum5_t* res);
void mdnum5_extract_im_to( imdir_t idx, ord_t order, mdnum5_t* num, mdnum5_t* res);
mdnum5_t mdnum5_extract_im(imdir_t idx, ord_t order, mdnum5_t* num);
mdnum5_t mdnum5_extract_deriv(imdir_t idx, ord_t order, mdnum5_t* num);
void mdnum5_extract_deriv_to(imdir_t idx, ord_t order, mdnum5_t* num, mdnum5_t* res);
void mdnum5_get_im_to_o(imdir_t idx, ord_t order, mdnum5_t* num, mdnum5_t* res);
mdnum5_t mdnum5_get_im_o(imdir_t idx, ord_t order, mdnum5_t* num);
void mdnum5_get_im_to_r(imdir_t idx, ord_t order, mdnum5_t* num, coeff_t* res);

ord_t mdnum5_get_order(mdnum5_t* lhs);
mdnum5_t mdnum5_get_deriv_o( imdir_t idx, ord_t order, mdnum5_t* num);
void mdnum5_get_deriv_to( imdir_t idx, ord_t order, mdnum5_t* num, mdnum5_t* res);
void mdnum5_set_im_r(coeff_t num, imdir_t idx, ord_t order, mdnum5_t* res);

mdnum5_t mdnum5_init(void);
ndir_t mdnum5_get_ndir_order(ord_t order, mdnum5_t* num);
ndir_t mdnum5_get_ndir_total(mdnum5_t* num);
coeff_t* mdnum5_get_order_address(ord_t order, mdnum5_t* num);
mdnum5_t mdnum5_create_r(  coeff_t lhs);
void mdnum5_set_r(  coeff_t lhs, mdnum5_t* res);
void mdnum5_set_o(  mdnum5_t* lhs, mdnum5_t* res);
mdnum5_t mdnum5_get_order_im(ord_t order, mdnum5_t* lhs);
void mdnum5_get_order_im_to(ord_t order, mdnum5_t* lhs, mdnum5_t* res);
coeff_t mdnum5_get_item(imdir_t idx, ord_t order, mdnum5_t* lhs);
coeff_t mdnum5_get_deriv(imdir_t idx, ord_t order, mdnum5_t* lhs);
void mdnum5_set_item(coeff_t val, imdir_t idx, ord_t order, mdnum5_t* x);
mdnum5_t mdnum5_copy(  mdnum5_t* lhs);
void mdnum5_copy_to(  mdnum5_t* lhs, mdnum5_t* res);
mdnum5_t mdnum5_taylor_integrate(coeff_t* deltas,mdnum5_t* lhs);
void mdnum5_taylor_integrate_to(coeff_t* deltas,mdnum5_t* lhs, mdnum5_t* res);
mdnum5_t mdnum5_truncate_im(imdir_t idx, ord_t order, mdnum5_t* lhs);
void mdnum5_truncate_im_to(imdir_t idx, ord_t order, mdnum5_t* lhs, mdnum5_t* res);
void mdnum5_print(  mdnum5_t* lhs);
imdir_t mdnum5_get_indx(imdir_t idx, ord_t order);


#endif