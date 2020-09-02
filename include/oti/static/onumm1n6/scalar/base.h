#ifndef OTI_ONUMM1N6_SCALAR_BASE_H
#define OTI_ONUMM1N6_SCALAR_BASE_H

// Not implemented correctly:
void onumm1n6_set_im_o(onumm1n6_t* num, imdir_t idx, ord_t order, onumm1n6_t* res);
void onumm1n6_set_deriv_r(coeff_t num, imdir_t idx, ord_t order, onumm1n6_t* res);
void onumm1n6_set_deriv_o(onumm1n6_t* num, imdir_t idx, ord_t order, onumm1n6_t* res);
void onumm1n6_extract_im_to( imdir_t idx, ord_t order, onumm1n6_t* num, onumm1n6_t* res);
onumm1n6_t onumm1n6_extract_im(imdir_t idx, ord_t order, onumm1n6_t* num);
onumm1n6_t onumm1n6_extract_deriv(imdir_t idx, ord_t order, onumm1n6_t* num);
void onumm1n6_extract_deriv_to(imdir_t idx, ord_t order, onumm1n6_t* num, onumm1n6_t* res);
void onumm1n6_get_im_to_o(imdir_t idx, ord_t order, onumm1n6_t* num, onumm1n6_t* res);
onumm1n6_t onumm1n6_get_im_o(imdir_t idx, ord_t order, onumm1n6_t* num);
void onumm1n6_get_im_to_r(imdir_t idx, ord_t order, onumm1n6_t* num, coeff_t* res);

ord_t onumm1n6_get_order(onumm1n6_t* lhs);
onumm1n6_t onumm1n6_get_deriv_o( imdir_t idx, ord_t order, onumm1n6_t* num);
void onumm1n6_get_deriv_to( imdir_t idx, ord_t order, onumm1n6_t* num, onumm1n6_t* res);
void onumm1n6_set_im_r(coeff_t num, imdir_t idx, ord_t order, onumm1n6_t* res);

onumm1n6_t onumm1n6_init(void);
ndir_t onumm1n6_get_ndir_order(ord_t order, onumm1n6_t* num);
ndir_t onumm1n6_get_ndir_total(onumm1n6_t* num);
coeff_t* onumm1n6_get_order_address(ord_t order, onumm1n6_t* num);
onumm1n6_t onumm1n6_create_r(  coeff_t lhs);
void onumm1n6_set_r(  coeff_t lhs, onumm1n6_t* res);
void onumm1n6_set_o(  onumm1n6_t* lhs, onumm1n6_t* res);
onumm1n6_t onumm1n6_get_order_im(ord_t order, onumm1n6_t* lhs);
void onumm1n6_get_order_im_to(ord_t order, onumm1n6_t* lhs, onumm1n6_t* res);
coeff_t onumm1n6_get_item(imdir_t idx, ord_t order, onumm1n6_t* lhs);
coeff_t onumm1n6_get_deriv(imdir_t idx, ord_t order, onumm1n6_t* lhs);
void onumm1n6_set_item(coeff_t val, imdir_t idx, ord_t order, onumm1n6_t* x);
onumm1n6_t onumm1n6_copy(  onumm1n6_t* lhs);
void onumm1n6_copy_to(  onumm1n6_t* lhs, onumm1n6_t* res);
onumm1n6_t onumm1n6_taylor_integrate(coeff_t* deltas,onumm1n6_t* lhs);
void onumm1n6_taylor_integrate_to(coeff_t* deltas,onumm1n6_t* lhs, onumm1n6_t* res);
onumm1n6_t onumm1n6_truncate_im(imdir_t idx, ord_t order, onumm1n6_t* lhs);
void onumm1n6_truncate_im_to(imdir_t idx, ord_t order, onumm1n6_t* lhs, onumm1n6_t* res);
void onumm1n6_print(  onumm1n6_t* lhs);
imdir_t onumm1n6_get_indx(imdir_t idx, ord_t order);


#endif