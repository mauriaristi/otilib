#ifndef OTI_{module_name_upper}_SCALAR_BASE_H
#define OTI_{module_name_upper}_SCALAR_BASE_H

// Not implemented correctly:
void {num_func}_set_im_o({num_type}* num, imdir_t idx, ord_t order, {num_type}* res);
void {num_func}_set_deriv_r(coeff_t num, imdir_t idx, ord_t order, {num_type}* res);
void {num_func}_set_deriv_o({num_type}* num, imdir_t idx, ord_t order, {num_type}* res);
void {num_func}_extract_im_to( imdir_t idx, ord_t order, {num_type}* num, {num_type}* res);
{num_type} {num_func}_extract_im(imdir_t idx, ord_t order, {num_type}* num);
{num_type} {num_func}_extract_deriv(imdir_t idx, ord_t order, {num_type}* num);
void {num_func}_extract_deriv_to(imdir_t idx, ord_t order, {num_type}* num, {num_type}* res);
void {num_func}_get_im_to_o(imdir_t idx, ord_t order, {num_type}* num, {num_type}* res);
{num_type} {num_func}_get_im_o(imdir_t idx, ord_t order, {num_type}* num);
void {num_func}_get_im_to_r(imdir_t idx, ord_t order, {num_type}* num, coeff_t* res);

ord_t {num_func}_get_order({num_type}* lhs);
{num_type} {num_func}_get_deriv_o( imdir_t idx, ord_t order, {num_type}* num);
void {num_func}_get_deriv_to( imdir_t idx, ord_t order, {num_type}* num, {num_type}* res);
void {num_func}_set_im_r(coeff_t num, imdir_t idx, ord_t order, {num_type}* res);

{base_include}

#endif