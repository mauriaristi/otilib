#ifndef OTI_MDNUM9_SCALAR_GAUSS_BASE_H
#define OTI_MDNUM9_SCALAR_GAUSS_BASE_H

void     femdnum9_get_order_im_to( ord_t order, femdnum9_t* num, femdnum9_t* res);
femdnum9_t femdnum9_get_order_im(    ord_t order, femdnum9_t* num);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Get a specific imaginary direction from the number.

@param[in] idx   Index of imaginary direction.
@param[in] order Order of imaginary direction.
@param[in] num   Number.
@param[in] res   Result
@param[in] dhl   Direction helper list
******************************************************************************************************/
femdnum9_t femdnum9_get_im(    imdir_t idx, ord_t order, femdnum9_t* num);
void     femdnum9_get_im_to( imdir_t idx, ord_t order, femdnum9_t* num, femdnum9_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Get a specific derivative from the number.

@param[in] idx   Index of imaginary direction.
@param[in] order Order of imaginary direction.
@param[in] num   Number.
@param[in] res   Result
@param[in] dhl   Direction helper list
******************************************************************************************************/
femdnum9_t femdnum9_get_deriv(    imdir_t idx, ord_t order, femdnum9_t* num);
void     femdnum9_get_deriv_to( imdir_t idx, ord_t order, femdnum9_t* num, femdnum9_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Set a specific derivative.

@param[in] idx   Index of imaginary direction.
@param[in] order Order of imaginary direction.
@param[in] num   Number.
@param[in] res   Result
@param[in] dhl   Direction helper list
******************************************************************************************************/
void femdnum9_set_im_r(   coeff_t  val, imdir_t idx, ord_t order, femdnum9_t* num);
void femdnum9_set_im_o( mdnum9_t* val, imdir_t idx, ord_t order, femdnum9_t* num);
void femdnum9_set_im_f(  femdnum9_t* val, imdir_t idx, ord_t order, femdnum9_t* num);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Set a specific derivative.

@param[in] idx   Index of imaginary direction.
@param[in] order Order of imaginary direction.
@param[in] num   Number.
@param[in] res   Result
@param[in] dhl   Direction helper list
******************************************************************************************************/
void femdnum9_set_deriv_r(   coeff_t  val, imdir_t idx, ord_t order, femdnum9_t* num);
void femdnum9_set_deriv_o( mdnum9_t* val, imdir_t idx, ord_t order, femdnum9_t* num);
void femdnum9_set_deriv_f(  femdnum9_t* val, imdir_t idx, ord_t order, femdnum9_t* num);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Extract full derivative as oti number.

@param[in] num   Number.
@param[in] idx   Index of imaginary direction.
@param[in] order Order of imaginary direction.
@param[in] res   Result
@param[in] dhl   Direction helper list
******************************************************************************************************/
femdnum9_t femdnum9_extract_im(    imdir_t idx, ord_t order, femdnum9_t* num);
void     femdnum9_extract_im_to( imdir_t idx, ord_t order, femdnum9_t* num, femdnum9_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Extract full derivative as oti number.

@param[in] num   Number.
@param[in] idx   Index of imaginary direction.
@param[in] order Order of imaginary direction.
@param[in] res   Result
@param[in] dhl   Direction helper list
******************************************************************************************************/
femdnum9_t femdnum9_extract_deriv(    imdir_t idx, ord_t order, femdnum9_t* num);
void     femdnum9_extract_deriv_to( imdir_t idx, ord_t order, femdnum9_t* num, femdnum9_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Truncate by given imaginary direction.

@param[in] num   Number.
@param[in] idx   Index of imaginary direction.
@param[in] order Order of imaginary direction.
@param[in] res   Result
@param[in] dhl   Direction helper list
******************************************************************************************************/
femdnum9_t femdnum9_truncate_im(    imdir_t idx, ord_t order, femdnum9_t* num);
void     femdnum9_truncate_im_to( imdir_t idx, ord_t order, femdnum9_t* num, femdnum9_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Copy functions.

@param[in] num Number to copy into res.
@param[in] res Result
@param[in] dhl Direction helper list
******************************************************************************************************/
femdnum9_t femdnum9_copy(    femdnum9_t* src);
void     femdnum9_copy_to( femdnum9_t* src, femdnum9_t* dst);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Set all elements as given num.

@param[in] num Number to set in res.
@param[in] res Result
@param[in] dhl Direction helper list
******************************************************************************************************/
void femdnum9_set_r(    coeff_t num, femdnum9_t* res);
void femdnum9_set_o( mdnum9_t* num, femdnum9_t* res);
void femdnum9_set_f(  femdnum9_t* num, femdnum9_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Set a specific imaginary direction.

@param[in] num OTI number to set the item.
@param[in] k   Integration point to set.
@param[in] res Integration point to set.
@param[in] dhl Direction helper list
******************************************************************************************************/
void femdnum9_set_item_k_r(   coeff_t  num, uint64_t k, femdnum9_t* res);
void femdnum9_set_item_k_o( mdnum9_t* num, uint64_t k, femdnum9_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Getter

@param[in] num Gauss number to get the item.
@param[in] k   Integration point to get.
@param[in] dhl Direction helper list
******************************************************************************************************/
mdnum9_t femdnum9_get_item_k(   femdnum9_t* num, uint64_t k);
void      femdnum9_get_item_k_to(femdnum9_t* num, uint64_t k, mdnum9_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Create a gauss scalar filled with zeros.

@param[in] nIntPts Number of integration points. 
@param[in] nbases  Number of imaginary bases. 
@param[in] order   Truncation prder of the number
@param[in] dhl Direction helper list
******************************************************************************************************/
femdnum9_t femdnum9_zeros(uint64_t nIntPts);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Reserve memory for gauss scalar.

@param[in] nIntPts Number of integration points. 
@param[in] nbases  Number of imaginary bases. 
@param[in] order   Truncation prder of the number
@param[in] dhl Direction helper list
******************************************************************************************************/
femdnum9_t femdnum9_createEmpty(uint64_t nIntPts);
femdnum9_t femdnum9_empty_like(femdnum9_t* arr);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Free Gauss Sparse oti number.

@param[in] num FEmdnum9 to free
******************************************************************************************************/
void femdnum9_free(femdnum9_t* num);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Get OTI truncation order.

@param[in] num FEmdnum9
******************************************************************************************************/
ord_t femdnum9_get_order( femdnum9_t* num );
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Initialize a femdnum9 structure.

******************************************************************************************************/
femdnum9_t femdnum9_init(void);
// ----------------------------------------------------------------------------------------------------

#endif