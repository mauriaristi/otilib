#ifndef OTI_MDNUM2_SCALAR_GAUSS_BASE_H
#define OTI_MDNUM2_SCALAR_GAUSS_BASE_H

void     femdnum2_get_order_im_to( ord_t order, femdnum2_t* num, femdnum2_t* res);
femdnum2_t femdnum2_get_order_im(    ord_t order, femdnum2_t* num);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Get a specific imaginary direction from the number.

@param[in] idx   Index of imaginary direction.
@param[in] order Order of imaginary direction.
@param[in] num   Number.
@param[in] res   Result
@param[in] dhl   Direction helper list
******************************************************************************************************/
femdnum2_t femdnum2_get_im(    imdir_t idx, ord_t order, femdnum2_t* num);
void     femdnum2_get_im_to( imdir_t idx, ord_t order, femdnum2_t* num, femdnum2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Get a specific derivative from the number.

@param[in] idx   Index of imaginary direction.
@param[in] order Order of imaginary direction.
@param[in] num   Number.
@param[in] res   Result
@param[in] dhl   Direction helper list
******************************************************************************************************/
femdnum2_t femdnum2_get_deriv(    imdir_t idx, ord_t order, femdnum2_t* num);
void     femdnum2_get_deriv_to( imdir_t idx, ord_t order, femdnum2_t* num, femdnum2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Set a specific derivative.

@param[in] idx   Index of imaginary direction.
@param[in] order Order of imaginary direction.
@param[in] num   Number.
@param[in] res   Result
@param[in] dhl   Direction helper list
******************************************************************************************************/
void femdnum2_set_im_r(   coeff_t  val, imdir_t idx, ord_t order, femdnum2_t* num);
void femdnum2_set_im_o( mdnum2_t* val, imdir_t idx, ord_t order, femdnum2_t* num);
void femdnum2_set_im_f(  femdnum2_t* val, imdir_t idx, ord_t order, femdnum2_t* num);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Set a specific derivative.

@param[in] idx   Index of imaginary direction.
@param[in] order Order of imaginary direction.
@param[in] num   Number.
@param[in] res   Result
@param[in] dhl   Direction helper list
******************************************************************************************************/
void femdnum2_set_deriv_r(   coeff_t  val, imdir_t idx, ord_t order, femdnum2_t* num);
void femdnum2_set_deriv_o( mdnum2_t* val, imdir_t idx, ord_t order, femdnum2_t* num);
void femdnum2_set_deriv_f(  femdnum2_t* val, imdir_t idx, ord_t order, femdnum2_t* num);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Extract full derivative as oti number.

@param[in] num   Number.
@param[in] idx   Index of imaginary direction.
@param[in] order Order of imaginary direction.
@param[in] res   Result
@param[in] dhl   Direction helper list
******************************************************************************************************/
femdnum2_t femdnum2_extract_im(    imdir_t idx, ord_t order, femdnum2_t* num);
void     femdnum2_extract_im_to( imdir_t idx, ord_t order, femdnum2_t* num, femdnum2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Extract full derivative as oti number.

@param[in] num   Number.
@param[in] idx   Index of imaginary direction.
@param[in] order Order of imaginary direction.
@param[in] res   Result
@param[in] dhl   Direction helper list
******************************************************************************************************/
femdnum2_t femdnum2_extract_deriv(    imdir_t idx, ord_t order, femdnum2_t* num);
void     femdnum2_extract_deriv_to( imdir_t idx, ord_t order, femdnum2_t* num, femdnum2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Truncate by given imaginary direction.

@param[in] num   Number.
@param[in] idx   Index of imaginary direction.
@param[in] order Order of imaginary direction.
@param[in] res   Result
@param[in] dhl   Direction helper list
******************************************************************************************************/
femdnum2_t femdnum2_truncate_im(    imdir_t idx, ord_t order, femdnum2_t* num);
void     femdnum2_truncate_im_to( imdir_t idx, ord_t order, femdnum2_t* num, femdnum2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Copy functions.

@param[in] num Number to copy into res.
@param[in] res Result
@param[in] dhl Direction helper list
******************************************************************************************************/
femdnum2_t femdnum2_copy(    femdnum2_t* src);
void     femdnum2_copy_to( femdnum2_t* src, femdnum2_t* dst);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Set all elements as given num.

@param[in] num Number to set in res.
@param[in] res Result
@param[in] dhl Direction helper list
******************************************************************************************************/
void femdnum2_set_r(    coeff_t num, femdnum2_t* res);
void femdnum2_set_o( mdnum2_t* num, femdnum2_t* res);
void femdnum2_set_f(  femdnum2_t* num, femdnum2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Set a specific imaginary direction.

@param[in] num OTI number to set the item.
@param[in] k   Integration point to set.
@param[in] res Integration point to set.
@param[in] dhl Direction helper list
******************************************************************************************************/
void femdnum2_set_item_k_r(   coeff_t  num, uint64_t k, femdnum2_t* res);
void femdnum2_set_item_k_o( mdnum2_t* num, uint64_t k, femdnum2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Getter

@param[in] num Gauss number to get the item.
@param[in] k   Integration point to get.
@param[in] dhl Direction helper list
******************************************************************************************************/
mdnum2_t femdnum2_get_item_k(   femdnum2_t* num, uint64_t k);
void      femdnum2_get_item_k_to(femdnum2_t* num, uint64_t k, mdnum2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Create a gauss scalar filled with zeros.

@param[in] nIntPts Number of integration points. 
@param[in] nbases  Number of imaginary bases. 
@param[in] order   Truncation prder of the number
@param[in] dhl Direction helper list
******************************************************************************************************/
femdnum2_t femdnum2_zeros(uint64_t nIntPts);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Reserve memory for gauss scalar.

@param[in] nIntPts Number of integration points. 
@param[in] nbases  Number of imaginary bases. 
@param[in] order   Truncation prder of the number
@param[in] dhl Direction helper list
******************************************************************************************************/
femdnum2_t femdnum2_createEmpty(uint64_t nIntPts);
femdnum2_t femdnum2_empty_like(femdnum2_t* arr);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Free Gauss Sparse oti number.

@param[in] num FEmdnum2 to free
******************************************************************************************************/
void femdnum2_free(femdnum2_t* num);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Get OTI truncation order.

@param[in] num FEmdnum2
******************************************************************************************************/
ord_t femdnum2_get_order( femdnum2_t* num );
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Initialize a femdnum2 structure.

******************************************************************************************************/
femdnum2_t femdnum2_init(void);
// ----------------------------------------------------------------------------------------------------

#endif