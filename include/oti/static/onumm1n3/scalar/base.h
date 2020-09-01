#ifndef OTI_ONUMM1N3_SCALAR_BASE_H
#define OTI_ONUMM1N3_SCALAR_BASE_H

// Not implemented correctly:
void onumm1n3_set_im_o(onumm1n3_t* num, imdir_t idx, ord_t order, onumm1n3_t* res);
void onumm1n3_set_deriv_r(coeff_t num, imdir_t idx, ord_t order, onumm1n3_t* res);
void onumm1n3_set_deriv_o(onumm1n3_t* num, imdir_t idx, ord_t order, onumm1n3_t* res);
void onumm1n3_extract_im_to( imdir_t idx, ord_t order, onumm1n3_t* num, onumm1n3_t* res);
onumm1n3_t onumm1n3_extract_im(imdir_t idx, ord_t order, onumm1n3_t* num);
onumm1n3_t onumm1n3_extract_deriv(imdir_t idx, ord_t order, onumm1n3_t* num);
void onumm1n3_extract_deriv_to(imdir_t idx, ord_t order, onumm1n3_t* num, onumm1n3_t* res);
void onumm1n3_get_im_to_o(imdir_t idx, ord_t order, onumm1n3_t* num, onumm1n3_t* res);
onumm1n3_t onumm1n3_get_im_o(imdir_t idx, ord_t order, onumm1n3_t* num);
void onumm1n3_get_im_to_r(imdir_t idx, ord_t order, onumm1n3_t* num, coeff_t* res);

ord_t onumm1n3_get_order(onumm1n3_t* lhs);
onumm1n3_t onumm1n3_get_deriv_o( imdir_t idx, ord_t order, onumm1n3_t* num);
void onumm1n3_get_deriv_to( imdir_t idx, ord_t order, onumm1n3_t* num, onumm1n3_t* res);
void onumm1n3_set_im_r(coeff_t num, imdir_t idx, ord_t order, onumm1n3_t* res);

onumm1n3_t onumm1n3_init(void);
ndir_t onumm1n3_get_ndir_order(ord_t order, onumm1n3_t* num);
ndir_t onumm1n3_get_ndir_total(onumm1n3_t* num);
coeff_t* onumm1n3_get_order_address(ord_t order, onumm1n3_t* num);
onumm1n3_t onumm1n3_create_r(  coeff_t lhs);
void onumm1n3_set_r(  coeff_t lhs, onumm1n3_t* res);
void onumm1n3_set_o(  onumm1n3_t* lhs, onumm1n3_t* res);
onumm1n3_t onumm1n3_get_order_im(ord_t order, onumm1n3_t* lhs);
void onumm1n3_get_order_im_to(ord_t order, onumm1n3_t* lhs, onumm1n3_t* res);
coeff_t onumm1n3_get_item(imdir_t idx, ord_t order, onumm1n3_t* lhs);
coeff_t onumm1n3_get_deriv(imdir_t idx, ord_t order, onumm1n3_t* lhs);
void onumm1n3_set_item(coeff_t val, imdir_t idx, ord_t order, onumm1n3_t* x);
onumm1n3_t onumm1n3_copy(  onumm1n3_t* lhs);
void onumm1n3_copy_to(  onumm1n3_t* lhs, onumm1n3_t* res);
onumm1n3_t onumm1n3_taylor_integrate(coeff_t* deltas,onumm1n3_t* lhs);
void onumm1n3_taylor_integrate_to(coeff_t* deltas,onumm1n3_t* lhs, onumm1n3_t* res);
onumm1n3_t onumm1n3_truncate_im(imdir_t idx, ord_t order, onumm1n3_t* lhs);
void onumm1n3_truncate_im_to(imdir_t idx, ord_t order, onumm1n3_t* lhs, onumm1n3_t* res);
void onumm1n3_print(  onumm1n3_t* lhs);
imdir_t onumm1n3_get_indx(imdir_t idx, ord_t order);


#endif