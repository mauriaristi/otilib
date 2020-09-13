#ifndef OTI_MDNUM6_SCALAR_BASE_H
#define OTI_MDNUM6_SCALAR_BASE_H

// Not implemented correctly:
void mdnum6_set_im_o(mdnum6_t* num, imdir_t idx, ord_t order, mdnum6_t* res);
void mdnum6_set_deriv_r(coeff_t num, imdir_t idx, ord_t order, mdnum6_t* res);
void mdnum6_set_deriv_o(mdnum6_t* num, imdir_t idx, ord_t order, mdnum6_t* res);
void mdnum6_extract_im_to( imdir_t idx, ord_t order, mdnum6_t* num, mdnum6_t* res);
mdnum6_t mdnum6_extract_im(imdir_t idx, ord_t order, mdnum6_t* num);
mdnum6_t mdnum6_extract_deriv(imdir_t idx, ord_t order, mdnum6_t* num);
void mdnum6_extract_deriv_to(imdir_t idx, ord_t order, mdnum6_t* num, mdnum6_t* res);
void mdnum6_get_im_to_o(imdir_t idx, ord_t order, mdnum6_t* num, mdnum6_t* res);
mdnum6_t mdnum6_get_im_o(imdir_t idx, ord_t order, mdnum6_t* num);
void mdnum6_get_im_to_r(imdir_t idx, ord_t order, mdnum6_t* num, coeff_t* res);

ord_t mdnum6_get_order(mdnum6_t* lhs);
mdnum6_t mdnum6_get_deriv_o( imdir_t idx, ord_t order, mdnum6_t* num);
void mdnum6_get_deriv_to( imdir_t idx, ord_t order, mdnum6_t* num, mdnum6_t* res);
void mdnum6_set_im_r(coeff_t num, imdir_t idx, ord_t order, mdnum6_t* res);

mdnum6_t mdnum6_init(void);
ndir_t mdnum6_get_ndir_order(ord_t order, mdnum6_t* num);
ndir_t mdnum6_get_ndir_total(mdnum6_t* num);
coeff_t* mdnum6_get_order_address(ord_t order, mdnum6_t* num);
mdnum6_t mdnum6_create_r(  coeff_t lhs);
void mdnum6_set_r(  coeff_t lhs, mdnum6_t* res);
void mdnum6_set_o(  mdnum6_t* lhs, mdnum6_t* res);
mdnum6_t mdnum6_get_order_im(ord_t order, mdnum6_t* lhs);
void mdnum6_get_order_im_to(ord_t order, mdnum6_t* lhs, mdnum6_t* res);
coeff_t mdnum6_get_item(imdir_t idx, ord_t order, mdnum6_t* lhs);
coeff_t mdnum6_get_deriv(imdir_t idx, ord_t order, mdnum6_t* lhs);
void mdnum6_set_item(coeff_t val, imdir_t idx, ord_t order, mdnum6_t* x);
mdnum6_t mdnum6_copy(  mdnum6_t* lhs);
void mdnum6_copy_to(  mdnum6_t* lhs, mdnum6_t* res);
mdnum6_t mdnum6_taylor_integrate(coeff_t* deltas,mdnum6_t* lhs);
void mdnum6_taylor_integrate_to(coeff_t* deltas,mdnum6_t* lhs, mdnum6_t* res);
mdnum6_t mdnum6_truncate_im(imdir_t idx, ord_t order, mdnum6_t* lhs);
void mdnum6_truncate_im_to(imdir_t idx, ord_t order, mdnum6_t* lhs, mdnum6_t* res);
void mdnum6_print(  mdnum6_t* lhs);
imdir_t mdnum6_get_indx(imdir_t idx, ord_t order);


#endif