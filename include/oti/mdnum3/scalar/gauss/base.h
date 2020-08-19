#ifndef OTI_MDNUM3_SCALAR_GAUSS_BASE_H
#define OTI_MDNUM3_SCALAR_GAUSS_BASE_H

void     femdnum3_get_order_im_to( ord_t order, femdnum3_t* num, femdnum3_t* res);
femdnum3_t femdnum3_get_order_im(    ord_t order, femdnum3_t* num);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Get a specific imaginary direction from the number.

@param[in] idx   Index of imaginary direction.
@param[in] order Order of imaginary direction.
@param[in] num   Number.
@param[in] res   Result
@param[in] dhl   Direction helper list
******************************************************************************************************/
femdnum3_t femdnum3_get_im(    imdir_t idx, ord_t order, femdnum3_t* num);
void     femdnum3_get_im_to( imdir_t idx, ord_t order, femdnum3_t* num, femdnum3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Get a specific derivative from the number.

@param[in] idx   Index of imaginary direction.
@param[in] order Order of imaginary direction.
@param[in] num   Number.
@param[in] res   Result
@param[in] dhl   Direction helper list
******************************************************************************************************/
femdnum3_t femdnum3_get_deriv(    imdir_t idx, ord_t order, femdnum3_t* num);
void     femdnum3_get_deriv_to( imdir_t idx, ord_t order, femdnum3_t* num, femdnum3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Set a specific derivative.

@param[in] idx   Index of imaginary direction.
@param[in] order Order of imaginary direction.
@param[in] num   Number.
@param[in] res   Result
@param[in] dhl   Direction helper list
******************************************************************************************************/
void femdnum3_set_im_r(   coeff_t  val, imdir_t idx, ord_t order, femdnum3_t* num);
void femdnum3_set_im_o( mdnum3_t* val, imdir_t idx, ord_t order, femdnum3_t* num);
void femdnum3_set_im_f(  femdnum3_t* val, imdir_t idx, ord_t order, femdnum3_t* num);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Set a specific derivative.

@param[in] idx   Index of imaginary direction.
@param[in] order Order of imaginary direction.
@param[in] num   Number.
@param[in] res   Result
@param[in] dhl   Direction helper list
******************************************************************************************************/
void femdnum3_set_deriv_r(   coeff_t  val, imdir_t idx, ord_t order, femdnum3_t* num);
void femdnum3_set_deriv_o( mdnum3_t* val, imdir_t idx, ord_t order, femdnum3_t* num);
void femdnum3_set_deriv_f(  femdnum3_t* val, imdir_t idx, ord_t order, femdnum3_t* num);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Extract full derivative as oti number.

@param[in] num   Number.
@param[in] idx   Index of imaginary direction.
@param[in] order Order of imaginary direction.
@param[in] res   Result
@param[in] dhl   Direction helper list
******************************************************************************************************/
femdnum3_t femdnum3_extract_im(    imdir_t idx, ord_t order, femdnum3_t* num);
void     femdnum3_extract_im_to( imdir_t idx, ord_t order, femdnum3_t* num, femdnum3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Extract full derivative as oti number.

@param[in] num   Number.
@param[in] idx   Index of imaginary direction.
@param[in] order Order of imaginary direction.
@param[in] res   Result
@param[in] dhl   Direction helper list
******************************************************************************************************/
femdnum3_t femdnum3_extract_deriv(    imdir_t idx, ord_t order, femdnum3_t* num);
void     femdnum3_extract_deriv_to( imdir_t idx, ord_t order, femdnum3_t* num, femdnum3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Truncate by given imaginary direction.

@param[in] num   Number.
@param[in] idx   Index of imaginary direction.
@param[in] order Order of imaginary direction.
@param[in] res   Result
@param[in] dhl   Direction helper list
******************************************************************************************************/
femdnum3_t femdnum3_truncate_im(    imdir_t idx, ord_t order, femdnum3_t* num);
void     femdnum3_truncate_im_to( imdir_t idx, ord_t order, femdnum3_t* num, femdnum3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Copy functions.

@param[in] num Number to copy into res.
@param[in] res Result
@param[in] dhl Direction helper list
******************************************************************************************************/
femdnum3_t femdnum3_copy(    femdnum3_t* src);
void     femdnum3_copy_to( femdnum3_t* src, femdnum3_t* dst);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Set all elements as given num.

@param[in] num Number to set in res.
@param[in] res Result
@param[in] dhl Direction helper list
******************************************************************************************************/
void femdnum3_set_r(    coeff_t num, femdnum3_t* res);
void femdnum3_set_o( mdnum3_t* num, femdnum3_t* res);
void femdnum3_set_f(  femdnum3_t* num, femdnum3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Set a specific imaginary direction.

@param[in] num OTI number to set the item.
@param[in] k   Integration point to set.
@param[in] res Integration point to set.
@param[in] dhl Direction helper list
******************************************************************************************************/
void femdnum3_set_item_k_r(   coeff_t  num, uint64_t k, femdnum3_t* res);
void femdnum3_set_item_k_o( mdnum3_t* num, uint64_t k, femdnum3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Getter

@param[in] num Gauss number to get the item.
@param[in] k   Integration point to get.
@param[in] dhl Direction helper list
******************************************************************************************************/
mdnum3_t femdnum3_get_item_k(   femdnum3_t* num, uint64_t k);
void      femdnum3_get_item_k_to(femdnum3_t* num, uint64_t k, mdnum3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Create a gauss scalar filled with zeros.

@param[in] nIntPts Number of integration points. 
@param[in] nbases  Number of imaginary bases. 
@param[in] order   Truncation prder of the number
@param[in] dhl Direction helper list
******************************************************************************************************/
femdnum3_t femdnum3_zeros(uint64_t nIntPts);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Reserve memory for gauss scalar.

@param[in] nIntPts Number of integration points. 
@param[in] nbases  Number of imaginary bases. 
@param[in] order   Truncation prder of the number
@param[in] dhl Direction helper list
******************************************************************************************************/
femdnum3_t femdnum3_createEmpty(uint64_t nIntPts);
femdnum3_t femdnum3_empty_like(femdnum3_t* arr);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Free Gauss Sparse oti number.

@param[in] num FEmdnum3 to free
******************************************************************************************************/
void femdnum3_free(femdnum3_t* num);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Get OTI truncation order.

@param[in] num FEmdnum3
******************************************************************************************************/
ord_t femdnum3_get_order( femdnum3_t* num );
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Initialize a femdnum3 structure.

******************************************************************************************************/
femdnum3_t femdnum3_init(void);
// ----------------------------------------------------------------------------------------------------

#endif