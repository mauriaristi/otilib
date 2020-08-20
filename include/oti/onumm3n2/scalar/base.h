#ifndef OTI_ONUMM3N2_SCALAR_BASE_H
#define OTI_ONUMM3N2_SCALAR_BASE_H

// Not implemented correctly:
void onumm3n2_set_im_o(onumm3n2_t* num, imdir_t idx, ord_t order, onumm3n2_t* res);
void onumm3n2_extract_im_to(onumm3n2_t* num, imdir_t idx, ord_t order, onumm3n2_t* res);
onumm3n2_t onumm3n2_extract_im(imdir_t idx, ord_t order, onumm3n2_t* num);
onumm3n2_t onumm3n2_extract_deriv(imdir_t idx, ord_t order, onumm3n2_t* num);
void onumm3n2_extract_deriv_to(imdir_t idx, ord_t order, onumm3n2_t* num, onumm3n2_t* res);

ord_t onumm3n2_get_order(onumm3n2_t* lhs);
onumm3n2_t onumm3n2_get_deriv_o( imdir_t idx, ord_t order, onumm3n2_t* num);
void onumm3n2_get_deriv_to( imdir_t idx, ord_t order, onumm3n2_t* num, onumm3n2_t* res);
void onumm3n2_set_im_r(coeff_t num, imdir_t idx, ord_t order, onumm3n2_t* res);

onumm3n2_t onumm3n2_init();
ndir_t onumm3n2_get_ndir_order(ord_t order, onumm3n2_t* num);
ndir_t onumm3n2_get_ndir_total(onumm3n2_t* num);
onumm3n2_t onumm3n2_create_r(  coeff_t lhs);
void onumm3n2_set_r(  coeff_t lhs, onumm3n2_t* res);
void onumm3n2_set_o(  onumm3n2_t* lhs, onumm3n2_t* res);
onumm3n2_t onumm3n2_get_order_im(ord_t order, onumm3n2_t* lhs);
void onumm3n2_get_order_im_to(ord_t order, onumm3n2_t* lhs, onumm3n2_t* res);
coeff_t onumm3n2_get_item(imdir_t idx, ord_t order, onumm3n2_t* lhs);
coeff_t onumm3n2_get_deriv(imdir_t idx, ord_t order, onumm3n2_t* lhs);
void onumm3n2_set_item(coeff_t val, imdir_t idx, ord_t order, onumm3n2_t* x);
onumm3n2_t onumm3n2_copy(  onumm3n2_t* lhs);
void onumm3n2_copy_to(  onumm3n2_t* lhs, onumm3n2_t* res);
onumm3n2_t onumm3n2_taylor_integrate(coeff_t* deltas,onumm3n2_t* lhs);
void onumm3n2_taylor_integrate_to(coeff_t* deltas,onumm3n2_t* lhs, onumm3n2_t* res);
onumm3n2_t onumm3n2_truncate_im(imdir_t idx, ord_t order, onumm3n2_t* lhs);
void onumm3n2_truncate_im_to(imdir_t idx, ord_t order, onumm3n2_t* lhs, onumm3n2_t* res);
void onumm3n2_print(  onumm3n2_t* lhs);
onumm3n2_t onumm3n2_init();
ndir_t onumm3n2_get_ndir_order(ord_t order, onumm3n2_t* num);
ndir_t onumm3n2_get_ndir_total(onumm3n2_t* num);
onumm3n2_t onumm3n2_create_r(  coeff_t lhs);
void onumm3n2_set_r(  coeff_t lhs, onumm3n2_t* res);
void onumm3n2_set_o(  onumm3n2_t* lhs, onumm3n2_t* res);
onumm3n2_t onumm3n2_get_order_im(ord_t order, onumm3n2_t* lhs);
void onumm3n2_get_order_im_to(ord_t order, onumm3n2_t* lhs, onumm3n2_t* res);
coeff_t onumm3n2_get_item(imdir_t idx, ord_t order, onumm3n2_t* lhs);
coeff_t onumm3n2_get_deriv(imdir_t idx, ord_t order, onumm3n2_t* lhs);
void onumm3n2_set_item(coeff_t val, imdir_t idx, ord_t order, onumm3n2_t* x);
onumm3n2_t onumm3n2_copy(  onumm3n2_t* lhs);
void onumm3n2_copy_to(  onumm3n2_t* lhs, onumm3n2_t* res);
onumm3n2_t onumm3n2_taylor_integrate(coeff_t* deltas,onumm3n2_t* lhs);
void onumm3n2_taylor_integrate_to(coeff_t* deltas,onumm3n2_t* lhs, onumm3n2_t* res);
onumm3n2_t onumm3n2_truncate_im(imdir_t idx, ord_t order, onumm3n2_t* lhs);
void onumm3n2_truncate_im_to(imdir_t idx, ord_t order, onumm3n2_t* lhs, onumm3n2_t* res);
void onumm3n2_print(  onumm3n2_t* lhs);


#endif