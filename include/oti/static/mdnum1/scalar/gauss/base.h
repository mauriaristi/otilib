#ifndef OTI_MDNUM1_SCALAR_GAUSS_BASE_H
#define OTI_MDNUM1_SCALAR_GAUSS_BASE_H

void     femdnum1_get_order_im_to( ord_t order, femdnum1_t* num, femdnum1_t* res);
femdnum1_t femdnum1_get_order_im(    ord_t order, femdnum1_t* num);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Get a specific imaginary direction from the number.

@param[in] idx   Index of imaginary direction.
@param[in] order Order of imaginary direction.
@param[in] num   Number.
@param[in] res   Result
@param[in] dhl   Direction helper list
******************************************************************************************************/
femdnum1_t femdnum1_get_im(    imdir_t idx, ord_t order, femdnum1_t* num);
void     femdnum1_get_im_to( imdir_t idx, ord_t order, femdnum1_t* num, femdnum1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Get a specific derivative from the number.

@param[in] idx   Index of imaginary direction.
@param[in] order Order of imaginary direction.
@param[in] num   Number.
@param[in] res   Result
@param[in] dhl   Direction helper list
******************************************************************************************************/
femdnum1_t femdnum1_get_deriv(    imdir_t idx, ord_t order, femdnum1_t* num);
void     femdnum1_get_deriv_to( imdir_t idx, ord_t order, femdnum1_t* num, femdnum1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Set a specific derivative.

@param[in] idx   Index of imaginary direction.
@param[in] order Order of imaginary direction.
@param[in] num   Number.
@param[in] res   Result
@param[in] dhl   Direction helper list
******************************************************************************************************/
void femdnum1_set_im_r(   coeff_t  val, imdir_t idx, ord_t order, femdnum1_t* num);
void femdnum1_set_im_o( mdnum1_t* val, imdir_t idx, ord_t order, femdnum1_t* num);
void femdnum1_set_im_f(  femdnum1_t* val, imdir_t idx, ord_t order, femdnum1_t* num);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Set a specific derivative.

@param[in] idx   Index of imaginary direction.
@param[in] order Order of imaginary direction.
@param[in] num   Number.
@param[in] res   Result
@param[in] dhl   Direction helper list
******************************************************************************************************/
void femdnum1_set_deriv_r(   coeff_t  val, imdir_t idx, ord_t order, femdnum1_t* num);
void femdnum1_set_deriv_o( mdnum1_t* val, imdir_t idx, ord_t order, femdnum1_t* num);
void femdnum1_set_deriv_f(  femdnum1_t* val, imdir_t idx, ord_t order, femdnum1_t* num);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Extract full derivative as oti number.

@param[in] num   Number.
@param[in] idx   Index of imaginary direction.
@param[in] order Order of imaginary direction.
@param[in] res   Result
@param[in] dhl   Direction helper list
******************************************************************************************************/
femdnum1_t femdnum1_extract_im(    imdir_t idx, ord_t order, femdnum1_t* num);
void     femdnum1_extract_im_to( imdir_t idx, ord_t order, femdnum1_t* num, femdnum1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Extract full derivative as oti number.

@param[in] num   Number.
@param[in] idx   Index of imaginary direction.
@param[in] order Order of imaginary direction.
@param[in] res   Result
@param[in] dhl   Direction helper list
******************************************************************************************************/
femdnum1_t femdnum1_extract_deriv(    imdir_t idx, ord_t order, femdnum1_t* num);
void     femdnum1_extract_deriv_to( imdir_t idx, ord_t order, femdnum1_t* num, femdnum1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Truncate by given imaginary direction.

@param[in] num   Number.
@param[in] idx   Index of imaginary direction.
@param[in] order Order of imaginary direction.
@param[in] res   Result
@param[in] dhl   Direction helper list
******************************************************************************************************/
femdnum1_t femdnum1_truncate_im(    imdir_t idx, ord_t order, femdnum1_t* num);
void     femdnum1_truncate_im_to( imdir_t idx, ord_t order, femdnum1_t* num, femdnum1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Copy functions.

@param[in] num Number to copy into res.
@param[in] res Result
@param[in] dhl Direction helper list
******************************************************************************************************/
femdnum1_t femdnum1_copy(    femdnum1_t* src);
void     femdnum1_copy_to( femdnum1_t* src, femdnum1_t* dst);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Set all elements as given num.

@param[in] num Number to set in res.
@param[in] res Result
@param[in] dhl Direction helper list
******************************************************************************************************/
void femdnum1_set_r(    coeff_t num, femdnum1_t* res);
void femdnum1_set_o( mdnum1_t* num, femdnum1_t* res);
void femdnum1_set_f(  femdnum1_t* num, femdnum1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Set a specific imaginary direction.

@param[in] num OTI number to set the item.
@param[in] k   Integration point to set.
@param[in] res Integration point to set.
@param[in] dhl Direction helper list
******************************************************************************************************/
void femdnum1_set_item_k_r(   coeff_t  num, uint64_t k, femdnum1_t* res);
void femdnum1_set_item_k_o( mdnum1_t* num, uint64_t k, femdnum1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Getter

@param[in] num Gauss number to get the item.
@param[in] k   Integration point to get.
@param[in] dhl Direction helper list
******************************************************************************************************/
mdnum1_t femdnum1_get_item_k(   femdnum1_t* num, uint64_t k);
void      femdnum1_get_item_k_to(femdnum1_t* num, uint64_t k, mdnum1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Create a gauss scalar filled with zeros.

@param[in] nIntPts Number of integration points. 
@param[in] nbases  Number of imaginary bases. 
@param[in] order   Truncation prder of the number
@param[in] dhl Direction helper list
******************************************************************************************************/
femdnum1_t femdnum1_zeros(uint64_t nIntPts);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Reserve memory for gauss scalar.

@param[in] nIntPts Number of integration points. 
@param[in] nbases  Number of imaginary bases. 
@param[in] order   Truncation prder of the number
@param[in] dhl Direction helper list
******************************************************************************************************/
femdnum1_t femdnum1_createEmpty(uint64_t nIntPts);
femdnum1_t femdnum1_empty_like(femdnum1_t* arr);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Free Gauss Sparse oti number.

@param[in] num FEmdnum1 to free
******************************************************************************************************/
void femdnum1_free(femdnum1_t* num);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Get OTI truncation order.

@param[in] num FEmdnum1
******************************************************************************************************/
ord_t femdnum1_get_order( femdnum1_t* num );
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Initialize a femdnum1 structure.

******************************************************************************************************/
femdnum1_t femdnum1_init(void);
// ----------------------------------------------------------------------------------------------------

#endif