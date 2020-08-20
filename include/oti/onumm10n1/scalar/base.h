#ifndef OTI_ONUMM10N1_SCALAR_BASE_H
#define OTI_ONUMM10N1_SCALAR_BASE_H

// Not implemented correctly:
void onumm10n1_set_im_o(onumm10n1_t* num, imdir_t idx, ord_t order, onumm10n1_t* res);
void onumm10n1_set_deriv_r(coeff_t num, imdir_t idx, ord_t order, onumm10n1_t* res);
void onumm10n1_set_deriv_o(onumm10n1_t* num, imdir_t idx, ord_t order, onumm10n1_t* res);
void onumm10n1_extract_im_to( imdir_t idx, ord_t order, onumm10n1_t* num, onumm10n1_t* res);
onumm10n1_t onumm10n1_extract_im(imdir_t idx, ord_t order, onumm10n1_t* num);
onumm10n1_t onumm10n1_extract_deriv(imdir_t idx, ord_t order, onumm10n1_t* num);
void onumm10n1_extract_deriv_to(imdir_t idx, ord_t order, onumm10n1_t* num, onumm10n1_t* res);
void onumm10n1_get_im_to_o(imdir_t idx, ord_t order, onumm10n1_t* num, onumm10n1_t* res);
onumm10n1_t onumm10n1_get_im_o(imdir_t idx, ord_t order, onumm10n1_t* num);
void onumm10n1_get_im_to_r(imdir_t idx, ord_t order, onumm10n1_t* num, coeff_t* res);

ord_t onumm10n1_get_order(onumm10n1_t* lhs);
onumm10n1_t onumm10n1_get_deriv_o( imdir_t idx, ord_t order, onumm10n1_t* num);
void onumm10n1_get_deriv_to( imdir_t idx, ord_t order, onumm10n1_t* num, onumm10n1_t* res);
void onumm10n1_set_im_r(coeff_t num, imdir_t idx, ord_t order, onumm10n1_t* res);

onumm10n1_t onumm10n1_init(void);
ndir_t onumm10n1_get_ndir_order(ord_t order, onumm10n1_t* num);
ndir_t onumm10n1_get_ndir_total(onumm10n1_t* num);
onumm10n1_t onumm10n1_create_r(  coeff_t lhs);
void onumm10n1_set_r(  coeff_t lhs, onumm10n1_t* res);
void onumm10n1_set_o(  onumm10n1_t* lhs, onumm10n1_t* res);
onumm10n1_t onumm10n1_get_order_im(ord_t order, onumm10n1_t* lhs);
void onumm10n1_get_order_im_to(ord_t order, onumm10n1_t* lhs, onumm10n1_t* res);
coeff_t onumm10n1_get_item(imdir_t idx, ord_t order, onumm10n1_t* lhs);
coeff_t onumm10n1_get_deriv(imdir_t idx, ord_t order, onumm10n1_t* lhs);
void onumm10n1_set_item(coeff_t val, imdir_t idx, ord_t order, onumm10n1_t* x);
onumm10n1_t onumm10n1_copy(  onumm10n1_t* lhs);
void onumm10n1_copy_to(  onumm10n1_t* lhs, onumm10n1_t* res);
onumm10n1_t onumm10n1_taylor_integrate(coeff_t* deltas,onumm10n1_t* lhs);
void onumm10n1_taylor_integrate_to(coeff_t* deltas,onumm10n1_t* lhs, onumm10n1_t* res);
onumm10n1_t onumm10n1_truncate_im(imdir_t idx, ord_t order, onumm10n1_t* lhs);
void onumm10n1_truncate_im_to(imdir_t idx, ord_t order, onumm10n1_t* lhs, onumm10n1_t* res);
void onumm10n1_print(  onumm10n1_t* lhs);
imdir_t onumm10n1_get_indx(imdir_t idx, ord_t order);
onumm10n1_t onumm10n1_init(void);
ndir_t onumm10n1_get_ndir_order(ord_t order, onumm10n1_t* num);
ndir_t onumm10n1_get_ndir_total(onumm10n1_t* num);
onumm10n1_t onumm10n1_create_r(  coeff_t lhs);
void onumm10n1_set_r(  coeff_t lhs, onumm10n1_t* res);
void onumm10n1_set_o(  onumm10n1_t* lhs, onumm10n1_t* res);
onumm10n1_t onumm10n1_get_order_im(ord_t order, onumm10n1_t* lhs);
void onumm10n1_get_order_im_to(ord_t order, onumm10n1_t* lhs, onumm10n1_t* res);
coeff_t onumm10n1_get_item(imdir_t idx, ord_t order, onumm10n1_t* lhs);
coeff_t onumm10n1_get_deriv(imdir_t idx, ord_t order, onumm10n1_t* lhs);
void onumm10n1_set_item(coeff_t val, imdir_t idx, ord_t order, onumm10n1_t* x);
onumm10n1_t onumm10n1_copy(  onumm10n1_t* lhs);
void onumm10n1_copy_to(  onumm10n1_t* lhs, onumm10n1_t* res);
onumm10n1_t onumm10n1_taylor_integrate(coeff_t* deltas,onumm10n1_t* lhs);
void onumm10n1_taylor_integrate_to(coeff_t* deltas,onumm10n1_t* lhs, onumm10n1_t* res);
onumm10n1_t onumm10n1_truncate_im(imdir_t idx, ord_t order, onumm10n1_t* lhs);
void onumm10n1_truncate_im_to(imdir_t idx, ord_t order, onumm10n1_t* lhs, onumm10n1_t* res);
void onumm10n1_print(  onumm10n1_t* lhs);
imdir_t onumm10n1_get_indx(imdir_t idx, ord_t order);


#endif