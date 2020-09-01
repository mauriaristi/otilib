#ifndef OTI_ONUMM4N4_SCALAR_BASE_H
#define OTI_ONUMM4N4_SCALAR_BASE_H

// Not implemented correctly:
void onumm4n4_set_im_o(onumm4n4_t* num, imdir_t idx, ord_t order, onumm4n4_t* res);
void onumm4n4_set_deriv_r(coeff_t num, imdir_t idx, ord_t order, onumm4n4_t* res);
void onumm4n4_set_deriv_o(onumm4n4_t* num, imdir_t idx, ord_t order, onumm4n4_t* res);
void onumm4n4_extract_im_to( imdir_t idx, ord_t order, onumm4n4_t* num, onumm4n4_t* res);
onumm4n4_t onumm4n4_extract_im(imdir_t idx, ord_t order, onumm4n4_t* num);
onumm4n4_t onumm4n4_extract_deriv(imdir_t idx, ord_t order, onumm4n4_t* num);
void onumm4n4_extract_deriv_to(imdir_t idx, ord_t order, onumm4n4_t* num, onumm4n4_t* res);
void onumm4n4_get_im_to_o(imdir_t idx, ord_t order, onumm4n4_t* num, onumm4n4_t* res);
onumm4n4_t onumm4n4_get_im_o(imdir_t idx, ord_t order, onumm4n4_t* num);
void onumm4n4_get_im_to_r(imdir_t idx, ord_t order, onumm4n4_t* num, coeff_t* res);

ord_t onumm4n4_get_order(onumm4n4_t* lhs);
onumm4n4_t onumm4n4_get_deriv_o( imdir_t idx, ord_t order, onumm4n4_t* num);
void onumm4n4_get_deriv_to( imdir_t idx, ord_t order, onumm4n4_t* num, onumm4n4_t* res);
void onumm4n4_set_im_r(coeff_t num, imdir_t idx, ord_t order, onumm4n4_t* res);

onumm4n4_t onumm4n4_init(void);
ndir_t onumm4n4_get_ndir_order(ord_t order, onumm4n4_t* num);
ndir_t onumm4n4_get_ndir_total(onumm4n4_t* num);
coeff_t* onumm4n4_get_order_address(ord_t order, onumm4n4_t* num);
onumm4n4_t onumm4n4_create_r(  coeff_t lhs);
void onumm4n4_set_r(  coeff_t lhs, onumm4n4_t* res);
void onumm4n4_set_o(  onumm4n4_t* lhs, onumm4n4_t* res);
onumm4n4_t onumm4n4_get_order_im(ord_t order, onumm4n4_t* lhs);
void onumm4n4_get_order_im_to(ord_t order, onumm4n4_t* lhs, onumm4n4_t* res);
coeff_t onumm4n4_get_item(imdir_t idx, ord_t order, onumm4n4_t* lhs);
coeff_t onumm4n4_get_deriv(imdir_t idx, ord_t order, onumm4n4_t* lhs);
void onumm4n4_set_item(coeff_t val, imdir_t idx, ord_t order, onumm4n4_t* x);
onumm4n4_t onumm4n4_copy(  onumm4n4_t* lhs);
void onumm4n4_copy_to(  onumm4n4_t* lhs, onumm4n4_t* res);
onumm4n4_t onumm4n4_taylor_integrate(coeff_t* deltas,onumm4n4_t* lhs);
void onumm4n4_taylor_integrate_to(coeff_t* deltas,onumm4n4_t* lhs, onumm4n4_t* res);
onumm4n4_t onumm4n4_truncate_im(imdir_t idx, ord_t order, onumm4n4_t* lhs);
void onumm4n4_truncate_im_to(imdir_t idx, ord_t order, onumm4n4_t* lhs, onumm4n4_t* res);
void onumm4n4_print(  onumm4n4_t* lhs);
imdir_t onumm4n4_get_indx(imdir_t idx, ord_t order);


#endif