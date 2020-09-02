#ifndef OTI_ONUMM2N9_SCALAR_BASE_H
#define OTI_ONUMM2N9_SCALAR_BASE_H

// Not implemented correctly:
void onumm2n9_set_im_o(onumm2n9_t* num, imdir_t idx, ord_t order, onumm2n9_t* res);
void onumm2n9_set_deriv_r(coeff_t num, imdir_t idx, ord_t order, onumm2n9_t* res);
void onumm2n9_set_deriv_o(onumm2n9_t* num, imdir_t idx, ord_t order, onumm2n9_t* res);
void onumm2n9_extract_im_to( imdir_t idx, ord_t order, onumm2n9_t* num, onumm2n9_t* res);
onumm2n9_t onumm2n9_extract_im(imdir_t idx, ord_t order, onumm2n9_t* num);
onumm2n9_t onumm2n9_extract_deriv(imdir_t idx, ord_t order, onumm2n9_t* num);
void onumm2n9_extract_deriv_to(imdir_t idx, ord_t order, onumm2n9_t* num, onumm2n9_t* res);
void onumm2n9_get_im_to_o(imdir_t idx, ord_t order, onumm2n9_t* num, onumm2n9_t* res);
onumm2n9_t onumm2n9_get_im_o(imdir_t idx, ord_t order, onumm2n9_t* num);
void onumm2n9_get_im_to_r(imdir_t idx, ord_t order, onumm2n9_t* num, coeff_t* res);

ord_t onumm2n9_get_order(onumm2n9_t* lhs);
onumm2n9_t onumm2n9_get_deriv_o( imdir_t idx, ord_t order, onumm2n9_t* num);
void onumm2n9_get_deriv_to( imdir_t idx, ord_t order, onumm2n9_t* num, onumm2n9_t* res);
void onumm2n9_set_im_r(coeff_t num, imdir_t idx, ord_t order, onumm2n9_t* res);

onumm2n9_t onumm2n9_init(void);
ndir_t onumm2n9_get_ndir_order(ord_t order, onumm2n9_t* num);
ndir_t onumm2n9_get_ndir_total(onumm2n9_t* num);
coeff_t* onumm2n9_get_order_address(ord_t order, onumm2n9_t* num);
onumm2n9_t onumm2n9_create_r(  coeff_t lhs);
void onumm2n9_set_r(  coeff_t lhs, onumm2n9_t* res);
void onumm2n9_set_o(  onumm2n9_t* lhs, onumm2n9_t* res);
onumm2n9_t onumm2n9_get_order_im(ord_t order, onumm2n9_t* lhs);
void onumm2n9_get_order_im_to(ord_t order, onumm2n9_t* lhs, onumm2n9_t* res);
coeff_t onumm2n9_get_item(imdir_t idx, ord_t order, onumm2n9_t* lhs);
coeff_t onumm2n9_get_deriv(imdir_t idx, ord_t order, onumm2n9_t* lhs);
void onumm2n9_set_item(coeff_t val, imdir_t idx, ord_t order, onumm2n9_t* x);
onumm2n9_t onumm2n9_copy(  onumm2n9_t* lhs);
void onumm2n9_copy_to(  onumm2n9_t* lhs, onumm2n9_t* res);
onumm2n9_t onumm2n9_taylor_integrate(coeff_t* deltas,onumm2n9_t* lhs);
void onumm2n9_taylor_integrate_to(coeff_t* deltas,onumm2n9_t* lhs, onumm2n9_t* res);
onumm2n9_t onumm2n9_truncate_im(imdir_t idx, ord_t order, onumm2n9_t* lhs);
void onumm2n9_truncate_im_to(imdir_t idx, ord_t order, onumm2n9_t* lhs, onumm2n9_t* res);
void onumm2n9_print(  onumm2n9_t* lhs);
imdir_t onumm2n9_get_indx(imdir_t idx, ord_t order);


#endif