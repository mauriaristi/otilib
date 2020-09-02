#ifndef OTI_ONUMM1N9_SCALAR_BASE_H
#define OTI_ONUMM1N9_SCALAR_BASE_H

// Not implemented correctly:
void onumm1n9_set_im_o(onumm1n9_t* num, imdir_t idx, ord_t order, onumm1n9_t* res);
void onumm1n9_set_deriv_r(coeff_t num, imdir_t idx, ord_t order, onumm1n9_t* res);
void onumm1n9_set_deriv_o(onumm1n9_t* num, imdir_t idx, ord_t order, onumm1n9_t* res);
void onumm1n9_extract_im_to( imdir_t idx, ord_t order, onumm1n9_t* num, onumm1n9_t* res);
onumm1n9_t onumm1n9_extract_im(imdir_t idx, ord_t order, onumm1n9_t* num);
onumm1n9_t onumm1n9_extract_deriv(imdir_t idx, ord_t order, onumm1n9_t* num);
void onumm1n9_extract_deriv_to(imdir_t idx, ord_t order, onumm1n9_t* num, onumm1n9_t* res);
void onumm1n9_get_im_to_o(imdir_t idx, ord_t order, onumm1n9_t* num, onumm1n9_t* res);
onumm1n9_t onumm1n9_get_im_o(imdir_t idx, ord_t order, onumm1n9_t* num);
void onumm1n9_get_im_to_r(imdir_t idx, ord_t order, onumm1n9_t* num, coeff_t* res);

ord_t onumm1n9_get_order(onumm1n9_t* lhs);
onumm1n9_t onumm1n9_get_deriv_o( imdir_t idx, ord_t order, onumm1n9_t* num);
void onumm1n9_get_deriv_to( imdir_t idx, ord_t order, onumm1n9_t* num, onumm1n9_t* res);
void onumm1n9_set_im_r(coeff_t num, imdir_t idx, ord_t order, onumm1n9_t* res);

onumm1n9_t onumm1n9_init(void);
ndir_t onumm1n9_get_ndir_order(ord_t order, onumm1n9_t* num);
ndir_t onumm1n9_get_ndir_total(onumm1n9_t* num);
coeff_t* onumm1n9_get_order_address(ord_t order, onumm1n9_t* num);
onumm1n9_t onumm1n9_create_r(  coeff_t lhs);
void onumm1n9_set_r(  coeff_t lhs, onumm1n9_t* res);
void onumm1n9_set_o(  onumm1n9_t* lhs, onumm1n9_t* res);
onumm1n9_t onumm1n9_get_order_im(ord_t order, onumm1n9_t* lhs);
void onumm1n9_get_order_im_to(ord_t order, onumm1n9_t* lhs, onumm1n9_t* res);
coeff_t onumm1n9_get_item(imdir_t idx, ord_t order, onumm1n9_t* lhs);
coeff_t onumm1n9_get_deriv(imdir_t idx, ord_t order, onumm1n9_t* lhs);
void onumm1n9_set_item(coeff_t val, imdir_t idx, ord_t order, onumm1n9_t* x);
onumm1n9_t onumm1n9_copy(  onumm1n9_t* lhs);
void onumm1n9_copy_to(  onumm1n9_t* lhs, onumm1n9_t* res);
onumm1n9_t onumm1n9_taylor_integrate(coeff_t* deltas,onumm1n9_t* lhs);
void onumm1n9_taylor_integrate_to(coeff_t* deltas,onumm1n9_t* lhs, onumm1n9_t* res);
onumm1n9_t onumm1n9_truncate_im(imdir_t idx, ord_t order, onumm1n9_t* lhs);
void onumm1n9_truncate_im_to(imdir_t idx, ord_t order, onumm1n9_t* lhs, onumm1n9_t* res);
void onumm1n9_print(  onumm1n9_t* lhs);
imdir_t onumm1n9_get_indx(imdir_t idx, ord_t order);


#endif