#ifndef OTI_ONUMM0N0_SCALAR_BASE_H
#define OTI_ONUMM0N0_SCALAR_BASE_H

// Not implemented correctly:
void onumm0n0_set_im_o(onumm0n0_t* num, imdir_t idx, ord_t order, onumm0n0_t* res);
void onumm0n0_set_deriv_r(coeff_t num, imdir_t idx, ord_t order, onumm0n0_t* res);
void onumm0n0_set_deriv_o(onumm0n0_t* num, imdir_t idx, ord_t order, onumm0n0_t* res);
void onumm0n0_extract_im_to( imdir_t idx, ord_t order, onumm0n0_t* num, onumm0n0_t* res);
onumm0n0_t onumm0n0_extract_im(imdir_t idx, ord_t order, onumm0n0_t* num);
onumm0n0_t onumm0n0_extract_deriv(imdir_t idx, ord_t order, onumm0n0_t* num);
void onumm0n0_extract_deriv_to(imdir_t idx, ord_t order, onumm0n0_t* num, onumm0n0_t* res);
void onumm0n0_get_im_to_o(imdir_t idx, ord_t order, onumm0n0_t* num, onumm0n0_t* res);
onumm0n0_t onumm0n0_get_im_o(imdir_t idx, ord_t order, onumm0n0_t* num);
void onumm0n0_get_im_to_r(imdir_t idx, ord_t order, onumm0n0_t* num, coeff_t* res);

ord_t onumm0n0_get_order(onumm0n0_t* lhs);
onumm0n0_t onumm0n0_get_deriv_o( imdir_t idx, ord_t order, onumm0n0_t* num);
void onumm0n0_get_deriv_to( imdir_t idx, ord_t order, onumm0n0_t* num, onumm0n0_t* res);
void onumm0n0_set_im_r(coeff_t num, imdir_t idx, ord_t order, onumm0n0_t* res);

onumm0n0_t onumm0n0_init(void);
ndir_t onumm0n0_get_ndir_order(ord_t order, onumm0n0_t* num);
ndir_t onumm0n0_get_ndir_total(onumm0n0_t* num);
coeff_t* onumm0n0_get_order_address(ord_t order, onumm0n0_t* num);
onumm0n0_t onumm0n0_create_r(  coeff_t lhs);
void onumm0n0_set_r(  coeff_t lhs, onumm0n0_t* res);
void onumm0n0_set_o(  onumm0n0_t* lhs, onumm0n0_t* res);
onumm0n0_t onumm0n0_get_order_im(ord_t order, onumm0n0_t* lhs);
void onumm0n0_get_order_im_to(ord_t order, onumm0n0_t* lhs, onumm0n0_t* res);
coeff_t onumm0n0_get_item(imdir_t idx, ord_t order, onumm0n0_t* lhs);
coeff_t onumm0n0_get_deriv(imdir_t idx, ord_t order, onumm0n0_t* lhs);
void onumm0n0_set_item(coeff_t val, imdir_t idx, ord_t order, onumm0n0_t* x);
onumm0n0_t onumm0n0_copy(  onumm0n0_t* lhs);
void onumm0n0_copy_to(  onumm0n0_t* lhs, onumm0n0_t* res);
onumm0n0_t onumm0n0_taylor_integrate(coeff_t* deltas,onumm0n0_t* lhs);
void onumm0n0_taylor_integrate_to(coeff_t* deltas,onumm0n0_t* lhs, onumm0n0_t* res);
onumm0n0_t onumm0n0_truncate_im(imdir_t idx, ord_t order, onumm0n0_t* lhs);
void onumm0n0_truncate_im_to(imdir_t idx, ord_t order, onumm0n0_t* lhs, onumm0n0_t* res);
void onumm0n0_print(  onumm0n0_t* lhs);
imdir_t onumm0n0_get_indx(imdir_t idx, ord_t order);


#endif