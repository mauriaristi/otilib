#ifndef OTI_ONUMM20N1_SCALAR_BASE_H
#define OTI_ONUMM20N1_SCALAR_BASE_H

// Not implemented correctly:
void onumm20n1_set_im_o(onumm20n1_t* num, imdir_t idx, ord_t order, onumm20n1_t* res);
void onumm20n1_extract_im_to( imdir_t idx, ord_t order, onumm20n1_t* num, onumm20n1_t* res);
onumm20n1_t onumm20n1_extract_im(imdir_t idx, ord_t order, onumm20n1_t* num);
onumm20n1_t onumm20n1_extract_deriv(imdir_t idx, ord_t order, onumm20n1_t* num);
void onumm20n1_extract_deriv_to(imdir_t idx, ord_t order, onumm20n1_t* num, onumm20n1_t* res);
void onumm20n1_get_im_to_o(imdir_t idx, ord_t order, onumm20n1_t* num, onumm20n1_t* res);
void onumm20n1_get_im_to_r(imdir_t idx, ord_t order, onumm20n1_t* num, coeff_t* res);

ord_t onumm20n1_get_order(onumm20n1_t* lhs);
onumm20n1_t onumm20n1_get_deriv_o( imdir_t idx, ord_t order, onumm20n1_t* num);
void onumm20n1_get_deriv_to( imdir_t idx, ord_t order, onumm20n1_t* num, onumm20n1_t* res);
void onumm20n1_set_im_r(coeff_t num, imdir_t idx, ord_t order, onumm20n1_t* res);

onumm20n1_t onumm20n1_init();
ndir_t onumm20n1_get_ndir_order(ord_t order, onumm20n1_t* num);
ndir_t onumm20n1_get_ndir_total(onumm20n1_t* num);
onumm20n1_t onumm20n1_create_r(  coeff_t lhs);
void onumm20n1_set_r(  coeff_t lhs, onumm20n1_t* res);
void onumm20n1_set_o(  onumm20n1_t* lhs, onumm20n1_t* res);
onumm20n1_t onumm20n1_get_order_im(ord_t order, onumm20n1_t* lhs);
void onumm20n1_get_order_im_to(ord_t order, onumm20n1_t* lhs, onumm20n1_t* res);
coeff_t onumm20n1_get_item(imdir_t idx, ord_t order, onumm20n1_t* lhs);
coeff_t onumm20n1_get_deriv(imdir_t idx, ord_t order, onumm20n1_t* lhs);
void onumm20n1_set_item(coeff_t val, imdir_t idx, ord_t order, onumm20n1_t* x);
onumm20n1_t onumm20n1_copy(  onumm20n1_t* lhs);
void onumm20n1_copy_to(  onumm20n1_t* lhs, onumm20n1_t* res);
onumm20n1_t onumm20n1_taylor_integrate(coeff_t* deltas,onumm20n1_t* lhs);
void onumm20n1_taylor_integrate_to(coeff_t* deltas,onumm20n1_t* lhs, onumm20n1_t* res);
onumm20n1_t onumm20n1_truncate_im(imdir_t idx, ord_t order, onumm20n1_t* lhs);
void onumm20n1_truncate_im_to(imdir_t idx, ord_t order, onumm20n1_t* lhs, onumm20n1_t* res);
void onumm20n1_print(  onumm20n1_t* lhs);
onumm20n1_t onumm20n1_init();
ndir_t onumm20n1_get_ndir_order(ord_t order, onumm20n1_t* num);
ndir_t onumm20n1_get_ndir_total(onumm20n1_t* num);
onumm20n1_t onumm20n1_create_r(  coeff_t lhs);
void onumm20n1_set_r(  coeff_t lhs, onumm20n1_t* res);
void onumm20n1_set_o(  onumm20n1_t* lhs, onumm20n1_t* res);
onumm20n1_t onumm20n1_get_order_im(ord_t order, onumm20n1_t* lhs);
void onumm20n1_get_order_im_to(ord_t order, onumm20n1_t* lhs, onumm20n1_t* res);
coeff_t onumm20n1_get_item(imdir_t idx, ord_t order, onumm20n1_t* lhs);
coeff_t onumm20n1_get_deriv(imdir_t idx, ord_t order, onumm20n1_t* lhs);
void onumm20n1_set_item(coeff_t val, imdir_t idx, ord_t order, onumm20n1_t* x);
onumm20n1_t onumm20n1_copy(  onumm20n1_t* lhs);
void onumm20n1_copy_to(  onumm20n1_t* lhs, onumm20n1_t* res);
onumm20n1_t onumm20n1_taylor_integrate(coeff_t* deltas,onumm20n1_t* lhs);
void onumm20n1_taylor_integrate_to(coeff_t* deltas,onumm20n1_t* lhs, onumm20n1_t* res);
onumm20n1_t onumm20n1_truncate_im(imdir_t idx, ord_t order, onumm20n1_t* lhs);
void onumm20n1_truncate_im_to(imdir_t idx, ord_t order, onumm20n1_t* lhs, onumm20n1_t* res);
void onumm20n1_print(  onumm20n1_t* lhs);


#endif