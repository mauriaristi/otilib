#ifndef OTI_MDNUM2_SCALAR_BASE_H
#define OTI_MDNUM2_SCALAR_BASE_H

// Not implemented correctly:
void mdnum2_set_im_o(mdnum2_t* num, imdir_t idx, ord_t order, mdnum2_t* res);
void mdnum2_set_deriv_r(coeff_t num, imdir_t idx, ord_t order, mdnum2_t* res);
void mdnum2_set_deriv_o(mdnum2_t* num, imdir_t idx, ord_t order, mdnum2_t* res);
void mdnum2_extract_im_to( imdir_t idx, ord_t order, mdnum2_t* num, mdnum2_t* res);
mdnum2_t mdnum2_extract_im(imdir_t idx, ord_t order, mdnum2_t* num);
mdnum2_t mdnum2_extract_deriv(imdir_t idx, ord_t order, mdnum2_t* num);
void mdnum2_extract_deriv_to(imdir_t idx, ord_t order, mdnum2_t* num, mdnum2_t* res);
void mdnum2_get_im_to_o(imdir_t idx, ord_t order, mdnum2_t* num, mdnum2_t* res);
mdnum2_t mdnum2_get_im_o(imdir_t idx, ord_t order, mdnum2_t* num);
void mdnum2_get_im_to_r(imdir_t idx, ord_t order, mdnum2_t* num, coeff_t* res);

ord_t mdnum2_get_order(mdnum2_t* lhs);
mdnum2_t mdnum2_get_deriv_o( imdir_t idx, ord_t order, mdnum2_t* num);
void mdnum2_get_deriv_to( imdir_t idx, ord_t order, mdnum2_t* num, mdnum2_t* res);
void mdnum2_set_im_r(coeff_t num, imdir_t idx, ord_t order, mdnum2_t* res);

mdnum2_t mdnum2_init(void);
ndir_t mdnum2_get_ndir_order(ord_t order, mdnum2_t* num);
ndir_t mdnum2_get_ndir_total(mdnum2_t* num);
mdnum2_t mdnum2_create_r(  coeff_t lhs);
void mdnum2_set_r(  coeff_t lhs, mdnum2_t* res);
void mdnum2_set_o(  mdnum2_t* lhs, mdnum2_t* res);
mdnum2_t mdnum2_get_order_im(ord_t order, mdnum2_t* lhs);
void mdnum2_get_order_im_to(ord_t order, mdnum2_t* lhs, mdnum2_t* res);
coeff_t mdnum2_get_item(imdir_t idx, ord_t order, mdnum2_t* lhs);
coeff_t mdnum2_get_deriv(imdir_t idx, ord_t order, mdnum2_t* lhs);
void mdnum2_set_item(coeff_t val, imdir_t idx, ord_t order, mdnum2_t* x);
mdnum2_t mdnum2_copy(  mdnum2_t* lhs);
void mdnum2_copy_to(  mdnum2_t* lhs, mdnum2_t* res);
mdnum2_t mdnum2_taylor_integrate(coeff_t* deltas,mdnum2_t* lhs);
void mdnum2_taylor_integrate_to(coeff_t* deltas,mdnum2_t* lhs, mdnum2_t* res);
mdnum2_t mdnum2_truncate_im(imdir_t idx, ord_t order, mdnum2_t* lhs);
void mdnum2_truncate_im_to(imdir_t idx, ord_t order, mdnum2_t* lhs, mdnum2_t* res);
void mdnum2_print(  mdnum2_t* lhs);
imdir_t mdnum2_get_indx(imdir_t idx, ord_t order);
mdnum2_t mdnum2_init(void);
ndir_t mdnum2_get_ndir_order(ord_t order, mdnum2_t* num);
ndir_t mdnum2_get_ndir_total(mdnum2_t* num);
mdnum2_t mdnum2_create_r(  coeff_t lhs);
void mdnum2_set_r(  coeff_t lhs, mdnum2_t* res);
void mdnum2_set_o(  mdnum2_t* lhs, mdnum2_t* res);
mdnum2_t mdnum2_get_order_im(ord_t order, mdnum2_t* lhs);
void mdnum2_get_order_im_to(ord_t order, mdnum2_t* lhs, mdnum2_t* res);
coeff_t mdnum2_get_item(imdir_t idx, ord_t order, mdnum2_t* lhs);
coeff_t mdnum2_get_deriv(imdir_t idx, ord_t order, mdnum2_t* lhs);
void mdnum2_set_item(coeff_t val, imdir_t idx, ord_t order, mdnum2_t* x);
mdnum2_t mdnum2_copy(  mdnum2_t* lhs);
void mdnum2_copy_to(  mdnum2_t* lhs, mdnum2_t* res);
mdnum2_t mdnum2_taylor_integrate(coeff_t* deltas,mdnum2_t* lhs);
void mdnum2_taylor_integrate_to(coeff_t* deltas,mdnum2_t* lhs, mdnum2_t* res);
mdnum2_t mdnum2_truncate_im(imdir_t idx, ord_t order, mdnum2_t* lhs);
void mdnum2_truncate_im_to(imdir_t idx, ord_t order, mdnum2_t* lhs, mdnum2_t* res);
void mdnum2_print(  mdnum2_t* lhs);
imdir_t mdnum2_get_indx(imdir_t idx, ord_t order);


#endif