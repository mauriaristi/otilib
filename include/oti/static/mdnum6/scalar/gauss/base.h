#ifndef OTI_MDNUM6_SCALAR_GAUSS_BASE_H
#define OTI_MDNUM6_SCALAR_GAUSS_BASE_H

void     femdnum6_get_order_im_to( ord_t order, femdnum6_t* num, femdnum6_t* res);
femdnum6_t femdnum6_get_order_im(    ord_t order, femdnum6_t* num);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Get a specific imaginary direction from the number.

@param[in] idx   Index of imaginary direction.
@param[in] order Order of imaginary direction.
@param[in] num   Number.
@param[in] res   Result
@param[in] dhl   Direction helper list
******************************************************************************************************/
femdnum6_t femdnum6_get_im(    imdir_t idx, ord_t order, femdnum6_t* num);
void     femdnum6_get_im_to( imdir_t idx, ord_t order, femdnum6_t* num, femdnum6_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Get a specific derivative from the number.

@param[in] idx   Index of imaginary direction.
@param[in] order Order of imaginary direction.
@param[in] num   Number.
@param[in] res   Result
@param[in] dhl   Direction helper list
******************************************************************************************************/
femdnum6_t femdnum6_get_deriv(    imdir_t idx, ord_t order, femdnum6_t* num);
void     femdnum6_get_deriv_to( imdir_t idx, ord_t order, femdnum6_t* num, femdnum6_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Set a specific derivative.

@param[in] idx   Index of imaginary direction.
@param[in] order Order of imaginary direction.
@param[in] num   Number.
@param[in] res   Result
@param[in] dhl   Direction helper list
******************************************************************************************************/
void femdnum6_set_im_r(   coeff_t  val, imdir_t idx, ord_t order, femdnum6_t* num);
void femdnum6_set_im_o( mdnum6_t* val, imdir_t idx, ord_t order, femdnum6_t* num);
void femdnum6_set_im_f(  femdnum6_t* val, imdir_t idx, ord_t order, femdnum6_t* num);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Set a specific derivative.

@param[in] idx   Index of imaginary direction.
@param[in] order Order of imaginary direction.
@param[in] num   Number.
@param[in] res   Result
@param[in] dhl   Direction helper list
******************************************************************************************************/
void femdnum6_set_deriv_r(   coeff_t  val, imdir_t idx, ord_t order, femdnum6_t* num);
void femdnum6_set_deriv_o( mdnum6_t* val, imdir_t idx, ord_t order, femdnum6_t* num);
void femdnum6_set_deriv_f(  femdnum6_t* val, imdir_t idx, ord_t order, femdnum6_t* num);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Extract full derivative as oti number.

@param[in] num   Number.
@param[in] idx   Index of imaginary direction.
@param[in] order Order of imaginary direction.
@param[in] res   Result
@param[in] dhl   Direction helper list
******************************************************************************************************/
femdnum6_t femdnum6_extract_im(    imdir_t idx, ord_t order, femdnum6_t* num);
void     femdnum6_extract_im_to( imdir_t idx, ord_t order, femdnum6_t* num, femdnum6_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Extract full derivative as oti number.

@param[in] num   Number.
@param[in] idx   Index of imaginary direction.
@param[in] order Order of imaginary direction.
@param[in] res   Result
@param[in] dhl   Direction helper list
******************************************************************************************************/
femdnum6_t femdnum6_extract_deriv(    imdir_t idx, ord_t order, femdnum6_t* num);
void     femdnum6_extract_deriv_to( imdir_t idx, ord_t order, femdnum6_t* num, femdnum6_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Truncate by given imaginary direction.

@param[in] num   Number.
@param[in] idx   Index of imaginary direction.
@param[in] order Order of imaginary direction.
@param[in] res   Result
@param[in] dhl   Direction helper list
******************************************************************************************************/
femdnum6_t femdnum6_truncate_im(    imdir_t idx, ord_t order, femdnum6_t* num);
void     femdnum6_truncate_im_to( imdir_t idx, ord_t order, femdnum6_t* num, femdnum6_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Copy functions.

@param[in] num Number to copy into res.
@param[in] res Result
@param[in] dhl Direction helper list
******************************************************************************************************/
femdnum6_t femdnum6_copy(    femdnum6_t* src);
void     femdnum6_copy_to( femdnum6_t* src, femdnum6_t* dst);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Set all elements as given num.

@param[in] num Number to set in res.
@param[in] res Result
@param[in] dhl Direction helper list
******************************************************************************************************/
void femdnum6_set_r(    coeff_t num, femdnum6_t* res);
void femdnum6_set_o( mdnum6_t* num, femdnum6_t* res);
void femdnum6_set_f(  femdnum6_t* num, femdnum6_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Set a specific imaginary direction.

@param[in] num OTI number to set the item.
@param[in] k   Integration point to set.
@param[in] res Integration point to set.
@param[in] dhl Direction helper list
******************************************************************************************************/
void femdnum6_set_item_k_r(   coeff_t  num, uint64_t k, femdnum6_t* res);
void femdnum6_set_item_k_o( mdnum6_t* num, uint64_t k, femdnum6_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Getter

@param[in] num Gauss number to get the item.
@param[in] k   Integration point to get.
@param[in] dhl Direction helper list
******************************************************************************************************/
mdnum6_t femdnum6_get_item_k(   femdnum6_t* num, uint64_t k);
void      femdnum6_get_item_k_to(femdnum6_t* num, uint64_t k, mdnum6_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Create a gauss scalar filled with zeros.

@param[in] nIntPts Number of integration points. 
@param[in] nbases  Number of imaginary bases. 
@param[in] order   Truncation prder of the number
@param[in] dhl Direction helper list
******************************************************************************************************/
femdnum6_t femdnum6_zeros(uint64_t nIntPts);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Reserve memory for gauss scalar.

@param[in] nIntPts Number of integration points. 
@param[in] nbases  Number of imaginary bases. 
@param[in] order   Truncation prder of the number
@param[in] dhl Direction helper list
******************************************************************************************************/
femdnum6_t femdnum6_createEmpty(uint64_t nIntPts);
femdnum6_t femdnum6_empty_like(femdnum6_t* arr);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Free Gauss Sparse oti number.

@param[in] num FEmdnum6 to free
******************************************************************************************************/
void femdnum6_free(femdnum6_t* num);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Get OTI truncation order.

@param[in] num FEmdnum6
******************************************************************************************************/
ord_t femdnum6_get_order( femdnum6_t* num );
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Initialize a femdnum6 structure.

******************************************************************************************************/
femdnum6_t femdnum6_init(void);
// ----------------------------------------------------------------------------------------------------

#endif