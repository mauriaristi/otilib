#ifndef OTI_MDNUM1_SCALAR_BASE_H
#define OTI_MDNUM1_SCALAR_BASE_H

// Not implemented correctly:
void mdnum1_set_im_o(mdnum1_t* num, imdir_t idx, ord_t order, mdnum1_t* res);
void mdnum1_set_deriv_r(coeff_t num, imdir_t idx, ord_t order, mdnum1_t* res);
void mdnum1_set_deriv_o(mdnum1_t* num, imdir_t idx, ord_t order, mdnum1_t* res);
void mdnum1_extract_im_to( imdir_t idx, ord_t order, mdnum1_t* num, mdnum1_t* res);
mdnum1_t mdnum1_extract_im(imdir_t idx, ord_t order, mdnum1_t* num);
mdnum1_t mdnum1_extract_deriv(imdir_t idx, ord_t order, mdnum1_t* num);
void mdnum1_extract_deriv_to(imdir_t idx, ord_t order, mdnum1_t* num, mdnum1_t* res);
void mdnum1_get_im_to_o(imdir_t idx, ord_t order, mdnum1_t* num, mdnum1_t* res);
mdnum1_t mdnum1_get_im_o(imdir_t idx, ord_t order, mdnum1_t* num);
void mdnum1_get_im_to_r(imdir_t idx, ord_t order, mdnum1_t* num, coeff_t* res);

ord_t mdnum1_get_order(mdnum1_t* lhs);
mdnum1_t mdnum1_get_deriv_o( imdir_t idx, ord_t order, mdnum1_t* num);
void mdnum1_get_deriv_to( imdir_t idx, ord_t order, mdnum1_t* num, mdnum1_t* res);
void mdnum1_set_im_r(coeff_t num, imdir_t idx, ord_t order, mdnum1_t* res);

mdnum1_t mdnum1_init(void);
ndir_t mdnum1_get_ndir_order(ord_t order, mdnum1_t* num);
ndir_t mdnum1_get_ndir_total(mdnum1_t* num);
coeff_t* mdnum1_get_order_address(ord_t order, mdnum1_t* num);
mdnum1_t mdnum1_create_r(  coeff_t lhs);
void mdnum1_set_r(  coeff_t lhs, mdnum1_t* res);
void mdnum1_set_o(  mdnum1_t* lhs, mdnum1_t* res);
mdnum1_t mdnum1_get_order_im(ord_t order, mdnum1_t* lhs);
void mdnum1_get_order_im_to(ord_t order, mdnum1_t* lhs, mdnum1_t* res);
coeff_t mdnum1_get_item(imdir_t idx, ord_t order, mdnum1_t* lhs);
coeff_t mdnum1_get_deriv(imdir_t idx, ord_t order, mdnum1_t* lhs);
void mdnum1_set_item(coeff_t val, imdir_t idx, ord_t order, mdnum1_t* x);
mdnum1_t mdnum1_copy(  mdnum1_t* lhs);
void mdnum1_copy_to(  mdnum1_t* lhs, mdnum1_t* res);
mdnum1_t mdnum1_taylor_integrate(coeff_t* deltas,mdnum1_t* lhs);
void mdnum1_taylor_integrate_to(coeff_t* deltas,mdnum1_t* lhs, mdnum1_t* res);
mdnum1_t mdnum1_truncate_im(imdir_t idx, ord_t order, mdnum1_t* lhs);
void mdnum1_truncate_im_to(imdir_t idx, ord_t order, mdnum1_t* lhs, mdnum1_t* res);
void mdnum1_print(  mdnum1_t* lhs);
imdir_t mdnum1_get_indx(imdir_t idx, ord_t order);


#endif