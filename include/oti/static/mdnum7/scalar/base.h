#ifndef OTI_MDNUM7_SCALAR_BASE_H
#define OTI_MDNUM7_SCALAR_BASE_H

// Not implemented correctly:
void mdnum7_set_im_o(mdnum7_t* num, imdir_t idx, ord_t order, mdnum7_t* res);
void mdnum7_set_deriv_r(coeff_t num, imdir_t idx, ord_t order, mdnum7_t* res);
void mdnum7_set_deriv_o(mdnum7_t* num, imdir_t idx, ord_t order, mdnum7_t* res);
void mdnum7_extract_im_to( imdir_t idx, ord_t order, mdnum7_t* num, mdnum7_t* res);
mdnum7_t mdnum7_extract_im(imdir_t idx, ord_t order, mdnum7_t* num);
mdnum7_t mdnum7_extract_deriv(imdir_t idx, ord_t order, mdnum7_t* num);
void mdnum7_extract_deriv_to(imdir_t idx, ord_t order, mdnum7_t* num, mdnum7_t* res);
void mdnum7_get_im_to_o(imdir_t idx, ord_t order, mdnum7_t* num, mdnum7_t* res);
mdnum7_t mdnum7_get_im_o(imdir_t idx, ord_t order, mdnum7_t* num);
void mdnum7_get_im_to_r(imdir_t idx, ord_t order, mdnum7_t* num, coeff_t* res);

ord_t mdnum7_get_order(mdnum7_t* lhs);
mdnum7_t mdnum7_get_deriv_o( imdir_t idx, ord_t order, mdnum7_t* num);
void mdnum7_get_deriv_to( imdir_t idx, ord_t order, mdnum7_t* num, mdnum7_t* res);
void mdnum7_set_im_r(coeff_t num, imdir_t idx, ord_t order, mdnum7_t* res);

mdnum7_t mdnum7_init(void);
ndir_t mdnum7_get_ndir_order(ord_t order, mdnum7_t* num);
ndir_t mdnum7_get_ndir_total(mdnum7_t* num);
coeff_t* mdnum7_get_order_address(ord_t order, mdnum7_t* num);
mdnum7_t mdnum7_create_r(  coeff_t lhs);
void mdnum7_set_r(  coeff_t lhs, mdnum7_t* res);
void mdnum7_set_o(  mdnum7_t* lhs, mdnum7_t* res);
mdnum7_t mdnum7_get_order_im(ord_t order, mdnum7_t* lhs);
void mdnum7_get_order_im_to(ord_t order, mdnum7_t* lhs, mdnum7_t* res);
coeff_t mdnum7_get_item(imdir_t idx, ord_t order, mdnum7_t* lhs);
coeff_t mdnum7_get_deriv(imdir_t idx, ord_t order, mdnum7_t* lhs);
void mdnum7_set_item(coeff_t val, imdir_t idx, ord_t order, mdnum7_t* x);
mdnum7_t mdnum7_copy(  mdnum7_t* lhs);
void mdnum7_copy_to(  mdnum7_t* lhs, mdnum7_t* res);
mdnum7_t mdnum7_taylor_integrate(coeff_t* deltas,mdnum7_t* lhs);
void mdnum7_taylor_integrate_to(coeff_t* deltas,mdnum7_t* lhs, mdnum7_t* res);
mdnum7_t mdnum7_truncate_im(imdir_t idx, ord_t order, mdnum7_t* lhs);
void mdnum7_truncate_im_to(imdir_t idx, ord_t order, mdnum7_t* lhs, mdnum7_t* res);
void mdnum7_print(  mdnum7_t* lhs);
imdir_t mdnum7_get_indx(imdir_t idx, ord_t order);


#endif