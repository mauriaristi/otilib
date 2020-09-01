#ifndef OTI_ONUMM4N1_SCALAR_BASE_H
#define OTI_ONUMM4N1_SCALAR_BASE_H

// Not implemented correctly:
void onumm4n1_set_im_o(onumm4n1_t* num, imdir_t idx, ord_t order, onumm4n1_t* res);
void onumm4n1_set_deriv_r(coeff_t num, imdir_t idx, ord_t order, onumm4n1_t* res);
void onumm4n1_set_deriv_o(onumm4n1_t* num, imdir_t idx, ord_t order, onumm4n1_t* res);
void onumm4n1_extract_im_to( imdir_t idx, ord_t order, onumm4n1_t* num, onumm4n1_t* res);
onumm4n1_t onumm4n1_extract_im(imdir_t idx, ord_t order, onumm4n1_t* num);
onumm4n1_t onumm4n1_extract_deriv(imdir_t idx, ord_t order, onumm4n1_t* num);
void onumm4n1_extract_deriv_to(imdir_t idx, ord_t order, onumm4n1_t* num, onumm4n1_t* res);
void onumm4n1_get_im_to_o(imdir_t idx, ord_t order, onumm4n1_t* num, onumm4n1_t* res);
onumm4n1_t onumm4n1_get_im_o(imdir_t idx, ord_t order, onumm4n1_t* num);
void onumm4n1_get_im_to_r(imdir_t idx, ord_t order, onumm4n1_t* num, coeff_t* res);

ord_t onumm4n1_get_order(onumm4n1_t* lhs);
onumm4n1_t onumm4n1_get_deriv_o( imdir_t idx, ord_t order, onumm4n1_t* num);
void onumm4n1_get_deriv_to( imdir_t idx, ord_t order, onumm4n1_t* num, onumm4n1_t* res);
void onumm4n1_set_im_r(coeff_t num, imdir_t idx, ord_t order, onumm4n1_t* res);

onumm4n1_t onumm4n1_init(void);
ndir_t onumm4n1_get_ndir_order(ord_t order, onumm4n1_t* num);
ndir_t onumm4n1_get_ndir_total(onumm4n1_t* num);
coeff_t* onumm4n1_get_order_address(ord_t order, onumm4n1_t* num);
onumm4n1_t onumm4n1_create_r(  coeff_t lhs);
void onumm4n1_set_r(  coeff_t lhs, onumm4n1_t* res);
void onumm4n1_set_o(  onumm4n1_t* lhs, onumm4n1_t* res);
onumm4n1_t onumm4n1_get_order_im(ord_t order, onumm4n1_t* lhs);
void onumm4n1_get_order_im_to(ord_t order, onumm4n1_t* lhs, onumm4n1_t* res);
coeff_t onumm4n1_get_item(imdir_t idx, ord_t order, onumm4n1_t* lhs);
coeff_t onumm4n1_get_deriv(imdir_t idx, ord_t order, onumm4n1_t* lhs);
void onumm4n1_set_item(coeff_t val, imdir_t idx, ord_t order, onumm4n1_t* x);
onumm4n1_t onumm4n1_copy(  onumm4n1_t* lhs);
void onumm4n1_copy_to(  onumm4n1_t* lhs, onumm4n1_t* res);
onumm4n1_t onumm4n1_taylor_integrate(coeff_t* deltas,onumm4n1_t* lhs);
void onumm4n1_taylor_integrate_to(coeff_t* deltas,onumm4n1_t* lhs, onumm4n1_t* res);
onumm4n1_t onumm4n1_truncate_im(imdir_t idx, ord_t order, onumm4n1_t* lhs);
void onumm4n1_truncate_im_to(imdir_t idx, ord_t order, onumm4n1_t* lhs, onumm4n1_t* res);
void onumm4n1_print(  onumm4n1_t* lhs);
imdir_t onumm4n1_get_indx(imdir_t idx, ord_t order);


#endif