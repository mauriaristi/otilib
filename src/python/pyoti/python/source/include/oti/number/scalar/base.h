#ifndef OTI_SPARSE_SCALAR_BASE_H
#define OTI_SPARSE_SCALAR_BASE_H

// Not implemented correctly:
void soti_set_im_o(sotinum_t* num, imdir_t idx, ord_t order, sotinum_t* res, dhelpl_t dhl);
void soti_set_deriv_r(coeff_t num, imdir_t idx, ord_t order, sotinum_t* res, dhelpl_t dhl);
void soti_set_deriv_o(sotinum_t* num, imdir_t idx, ord_t order, sotinum_t* res, dhelpl_t dhl);
void soti_extract_im_to( imdir_t idx, ord_t order, sotinum_t* num, sotinum_t* res, dhelpl_t dhl);
sotinum_t soti_extract_im(imdir_t idx, ord_t order, sotinum_t* num,  dhelpl_t dhl);
sotinum_t soti_extract_deriv(imdir_t idx, ord_t order, sotinum_t* num,  dhelpl_t dhl);
void soti_extract_deriv_to(imdir_t idx, ord_t order, sotinum_t* num, sotinum_t* res, dhelpl_t dhl);
void soti_get_im_to_o(imdir_t idx, ord_t order, sotinum_t* num, sotinum_t* res, dhelpl_t dhl);
sotinum_t soti_get_im_o(imdir_t idx, ord_t order, sotinum_t* num, dhelpl_t dhl);
void soti_get_im_to_r(imdir_t idx, ord_t order, sotinum_t* num, coeff_t* res, dhelpl_t dhl);








ord_t soti_get_order(sotinum_t* lhs);
sotinum_t soti_get_deriv_o( imdir_t idx, ord_t order, sotinum_t* num, dhelpl_t dhl);
void soti_get_deriv_to( imdir_t idx, ord_t order, sotinum_t* num, sotinum_t* res, dhelpl_t dhl);
void soti_set_im_r(coeff_t num, imdir_t idx, ord_t order, sotinum_t* res, dhelpl_t dhl);


<<<base_include>>>



#endif