#ifndef OTI_ONUMM7N2_SCALAR_BASE_H
#define OTI_ONUMM7N2_SCALAR_BASE_H

// Not implemented correctly:
void onumm7n2_set_im_o(onumm7n2_t* num, imdir_t idx, ord_t order, onumm7n2_t* res);
void onumm7n2_set_deriv_r(coeff_t num, imdir_t idx, ord_t order, onumm7n2_t* res);
void onumm7n2_set_deriv_o(onumm7n2_t* num, imdir_t idx, ord_t order, onumm7n2_t* res);
void onumm7n2_extract_im_to( imdir_t idx, ord_t order, onumm7n2_t* num, onumm7n2_t* res);
onumm7n2_t onumm7n2_extract_im(imdir_t idx, ord_t order, onumm7n2_t* num);
onumm7n2_t onumm7n2_extract_deriv(imdir_t idx, ord_t order, onumm7n2_t* num);
void onumm7n2_extract_deriv_to(imdir_t idx, ord_t order, onumm7n2_t* num, onumm7n2_t* res);
void onumm7n2_get_im_to_o(imdir_t idx, ord_t order, onumm7n2_t* num, onumm7n2_t* res);
onumm7n2_t onumm7n2_get_im_o(imdir_t idx, ord_t order, onumm7n2_t* num);
void onumm7n2_get_im_to_r(imdir_t idx, ord_t order, onumm7n2_t* num, coeff_t* res);

ord_t onumm7n2_get_order(onumm7n2_t* lhs);
onumm7n2_t onumm7n2_get_deriv_o( imdir_t idx, ord_t order, onumm7n2_t* num);
void onumm7n2_get_deriv_to( imdir_t idx, ord_t order, onumm7n2_t* num, onumm7n2_t* res);
void onumm7n2_set_im_r(coeff_t num, imdir_t idx, ord_t order, onumm7n2_t* res);

onumm7n2_t onumm7n2_init(void);
ndir_t onumm7n2_get_ndir_order(ord_t order, onumm7n2_t* num);
ndir_t onumm7n2_get_ndir_total(onumm7n2_t* num);
coeff_t* onumm7n2_get_order_address(ord_t order, onumm7n2_t* num);
onumm7n2_t onumm7n2_create_r(  coeff_t lhs);
void onumm7n2_set_r(  coeff_t lhs, onumm7n2_t* res);
void onumm7n2_set_o(  onumm7n2_t* lhs, onumm7n2_t* res);
onumm7n2_t onumm7n2_get_order_im(ord_t order, onumm7n2_t* lhs);
void onumm7n2_get_order_im_to(ord_t order, onumm7n2_t* lhs, onumm7n2_t* res);
coeff_t onumm7n2_get_item(imdir_t idx, ord_t order, onumm7n2_t* lhs);
coeff_t onumm7n2_get_deriv(imdir_t idx, ord_t order, onumm7n2_t* lhs);
void onumm7n2_set_item(coeff_t val, imdir_t idx, ord_t order, onumm7n2_t* x);
onumm7n2_t onumm7n2_copy(  onumm7n2_t* lhs);
void onumm7n2_copy_to(  onumm7n2_t* lhs, onumm7n2_t* res);
onumm7n2_t onumm7n2_taylor_integrate(coeff_t* deltas,onumm7n2_t* lhs);
void onumm7n2_taylor_integrate_to(coeff_t* deltas,onumm7n2_t* lhs, onumm7n2_t* res);
onumm7n2_t onumm7n2_truncate_im(imdir_t idx, ord_t order, onumm7n2_t* lhs);
void onumm7n2_truncate_im_to(imdir_t idx, ord_t order, onumm7n2_t* lhs, onumm7n2_t* res);
void onumm7n2_print(  onumm7n2_t* lhs);
imdir_t onumm7n2_get_indx(imdir_t idx, ord_t order);


#endif