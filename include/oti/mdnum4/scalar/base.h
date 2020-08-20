#ifndef OTI_MDNUM4_SCALAR_BASE_H
#define OTI_MDNUM4_SCALAR_BASE_H

// Not implemented correctly:
void mdnum4_set_im_o(mdnum4_t* num, imdir_t idx, ord_t order, mdnum4_t* res);
void mdnum4_set_deriv_r(coeff_t num, imdir_t idx, ord_t order, mdnum4_t* res);
void mdnum4_set_deriv_o(mdnum4_t* num, imdir_t idx, ord_t order, mdnum4_t* res);
void mdnum4_extract_im_to( imdir_t idx, ord_t order, mdnum4_t* num, mdnum4_t* res);
mdnum4_t mdnum4_extract_im(imdir_t idx, ord_t order, mdnum4_t* num);
mdnum4_t mdnum4_extract_deriv(imdir_t idx, ord_t order, mdnum4_t* num);
void mdnum4_extract_deriv_to(imdir_t idx, ord_t order, mdnum4_t* num, mdnum4_t* res);
void mdnum4_get_im_to_o(imdir_t idx, ord_t order, mdnum4_t* num, mdnum4_t* res);
mdnum4_t mdnum4_get_im_o(imdir_t idx, ord_t order, mdnum4_t* num);
void mdnum4_get_im_to_r(imdir_t idx, ord_t order, mdnum4_t* num, coeff_t* res);

ord_t mdnum4_get_order(mdnum4_t* lhs);
mdnum4_t mdnum4_get_deriv_o( imdir_t idx, ord_t order, mdnum4_t* num);
void mdnum4_get_deriv_to( imdir_t idx, ord_t order, mdnum4_t* num, mdnum4_t* res);
void mdnum4_set_im_r(coeff_t num, imdir_t idx, ord_t order, mdnum4_t* res);

mdnum4_t mdnum4_init(void);
ndir_t mdnum4_get_ndir_order(ord_t order, mdnum4_t* num);
ndir_t mdnum4_get_ndir_total(mdnum4_t* num);
mdnum4_t mdnum4_create_r(  coeff_t lhs);
void mdnum4_set_r(  coeff_t lhs, mdnum4_t* res);
void mdnum4_set_o(  mdnum4_t* lhs, mdnum4_t* res);
mdnum4_t mdnum4_get_order_im(ord_t order, mdnum4_t* lhs);
void mdnum4_get_order_im_to(ord_t order, mdnum4_t* lhs, mdnum4_t* res);
coeff_t mdnum4_get_item(imdir_t idx, ord_t order, mdnum4_t* lhs);
coeff_t mdnum4_get_deriv(imdir_t idx, ord_t order, mdnum4_t* lhs);
void mdnum4_set_item(coeff_t val, imdir_t idx, ord_t order, mdnum4_t* x);
mdnum4_t mdnum4_copy(  mdnum4_t* lhs);
void mdnum4_copy_to(  mdnum4_t* lhs, mdnum4_t* res);
mdnum4_t mdnum4_taylor_integrate(coeff_t* deltas,mdnum4_t* lhs);
void mdnum4_taylor_integrate_to(coeff_t* deltas,mdnum4_t* lhs, mdnum4_t* res);
mdnum4_t mdnum4_truncate_im(imdir_t idx, ord_t order, mdnum4_t* lhs);
void mdnum4_truncate_im_to(imdir_t idx, ord_t order, mdnum4_t* lhs, mdnum4_t* res);
void mdnum4_print(  mdnum4_t* lhs);
imdir_t mdnum4_get_indx(imdir_t idx, ord_t order);
mdnum4_t mdnum4_init(void);
ndir_t mdnum4_get_ndir_order(ord_t order, mdnum4_t* num);
ndir_t mdnum4_get_ndir_total(mdnum4_t* num);
mdnum4_t mdnum4_create_r(  coeff_t lhs);
void mdnum4_set_r(  coeff_t lhs, mdnum4_t* res);
void mdnum4_set_o(  mdnum4_t* lhs, mdnum4_t* res);
mdnum4_t mdnum4_get_order_im(ord_t order, mdnum4_t* lhs);
void mdnum4_get_order_im_to(ord_t order, mdnum4_t* lhs, mdnum4_t* res);
coeff_t mdnum4_get_item(imdir_t idx, ord_t order, mdnum4_t* lhs);
coeff_t mdnum4_get_deriv(imdir_t idx, ord_t order, mdnum4_t* lhs);
void mdnum4_set_item(coeff_t val, imdir_t idx, ord_t order, mdnum4_t* x);
mdnum4_t mdnum4_copy(  mdnum4_t* lhs);
void mdnum4_copy_to(  mdnum4_t* lhs, mdnum4_t* res);
mdnum4_t mdnum4_taylor_integrate(coeff_t* deltas,mdnum4_t* lhs);
void mdnum4_taylor_integrate_to(coeff_t* deltas,mdnum4_t* lhs, mdnum4_t* res);
mdnum4_t mdnum4_truncate_im(imdir_t idx, ord_t order, mdnum4_t* lhs);
void mdnum4_truncate_im_to(imdir_t idx, ord_t order, mdnum4_t* lhs, mdnum4_t* res);
void mdnum4_print(  mdnum4_t* lhs);
imdir_t mdnum4_get_indx(imdir_t idx, ord_t order);


#endif