#ifndef OTI_SPARSE_SCALAR_GAUSS_BASE_H
#define OTI_SPARSE_SCALAR_GAUSS_BASE_H



void     fesoti_get_order_im_to( ord_t order, fesoti_t* num, fesoti_t* res, dhelpl_t dhl);
fesoti_t fesoti_get_order_im(    ord_t order, fesoti_t* num,                dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Get a specific imaginary direction from the number.

@param[in] idx   Index of imaginary direction.
@param[in] order Order of imaginary direction.
@param[in] num   Number.
@param[in] res   Result
@param[in] dhl   Direction helper list
******************************************************************************************************/
fesoti_t fesoti_get_im(    imdir_t idx, ord_t order, fesoti_t* num,                dhelpl_t dhl);
void     fesoti_get_im_to( imdir_t idx, ord_t order, fesoti_t* num, fesoti_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Get a specific derivative from the number.

@param[in] idx   Index of imaginary direction.
@param[in] order Order of imaginary direction.
@param[in] num   Number.
@param[in] res   Result
@param[in] dhl   Direction helper list
******************************************************************************************************/
fesoti_t fesoti_get_deriv(    imdir_t idx, ord_t order, fesoti_t* num,                dhelpl_t dhl);
void     fesoti_get_deriv_to( imdir_t idx, ord_t order, fesoti_t* num, fesoti_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Set a specific derivative.

@param[in] idx   Index of imaginary direction.
@param[in] order Order of imaginary direction.
@param[in] num   Number.
@param[in] res   Result
@param[in] dhl   Direction helper list
******************************************************************************************************/
void fesoti_set_im_r(   coeff_t  val, imdir_t idx, ord_t order, fesoti_t* num, dhelpl_t dhl);
void fesoti_set_im_o( sotinum_t* val, imdir_t idx, ord_t order, fesoti_t* num, dhelpl_t dhl);
void fesoti_set_im_f(  fesoti_t* val, imdir_t idx, ord_t order, fesoti_t* num, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------


/**************************************************************************************************//**
@brief Set a specific derivative.

@param[in] idx   Index of imaginary direction.
@param[in] order Order of imaginary direction.
@param[in] num   Number.
@param[in] res   Result
@param[in] dhl   Direction helper list
******************************************************************************************************/
void fesoti_set_deriv_r(   coeff_t  val, imdir_t idx, ord_t order, fesoti_t* num, dhelpl_t dhl);
void fesoti_set_deriv_o( sotinum_t* val, imdir_t idx, ord_t order, fesoti_t* num, dhelpl_t dhl);
void fesoti_set_deriv_f(  fesoti_t* val, imdir_t idx, ord_t order, fesoti_t* num, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------



/**************************************************************************************************//**
@brief Extract full derivative as oti number.

@param[in] num   Number.
@param[in] idx   Index of imaginary direction.
@param[in] order Order of imaginary direction.
@param[in] res   Result
@param[in] dhl   Direction helper list
******************************************************************************************************/
fesoti_t fesoti_extract_im(    imdir_t idx, ord_t order, fesoti_t* num,                dhelpl_t dhl);
void     fesoti_extract_im_to( imdir_t idx, ord_t order, fesoti_t* num, fesoti_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Extract full derivative as oti number.

@param[in] num   Number.
@param[in] idx   Index of imaginary direction.
@param[in] order Order of imaginary direction.
@param[in] res   Result
@param[in] dhl   Direction helper list
******************************************************************************************************/
fesoti_t fesoti_extract_deriv(    imdir_t idx, ord_t order, fesoti_t* num,                dhelpl_t dhl);
void     fesoti_extract_deriv_to( imdir_t idx, ord_t order, fesoti_t* num, fesoti_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Truncate by given imaginary direction.

@param[in] num   Number.
@param[in] idx   Index of imaginary direction.
@param[in] order Order of imaginary direction.
@param[in] res   Result
@param[in] dhl   Direction helper list
******************************************************************************************************/
fesoti_t fesoti_truncate_im(    imdir_t idx, ord_t order, fesoti_t* num,                dhelpl_t dhl);
void     fesoti_truncate_im_to( imdir_t idx, ord_t order, fesoti_t* num, fesoti_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**
 * @name Sparse OTI Gauss Number Order Truncation Variants
 * Functions that remove all terms of a given order and higher at every integration point.
 * @{
 */

/**
 * @brief Truncates all terms of order @p ord and higher at every integration point, into an
 *        existing destination.
 *
 * Applies soti_truncate_order_to() at each integration point. The real part is the term of order
 * zero, so @p ord = 0 sets @p res to zero at every integration point, including the real parts.
 * For @p ord >= 1 the real parts and all imaginary directions of order 1 to @p ord - 1 are kept.
 *
 * @param[in]     ord  Lowest order to remove. Terms of order 0 to @p ord - 1 are kept.
 * @param[in]     num  Gauss-point number to truncate. Must not be NULL.
 * @param[in,out] res  Pre-allocated destination. Must have the same number of integration points
 *                     as @p num. Each integration point may be reallocated, following the rules
 *                     of soti_truncate_order_to().
 * @param[in]     dhl  Direction helper list object.
 *
 * @see fesoti_truncate_order() for the allocating variant.
 */
void     fesoti_truncate_order_to( ord_t ord, fesoti_t* num, fesoti_t* res, dhelpl_t dhl);

/**
 * @brief Truncates all terms of order @p ord and higher at every integration point (allocating
 *        variant).
 *
 * Same semantics as fesoti_truncate_order_to(): @p ord = 0 returns zero at every integration
 * point, including the real parts; for @p ord >= 1 the real parts and all imaginary directions of
 * order 1 to @p ord - 1 are kept.
 *
 * @param[in] ord  Lowest order to remove. Terms of order 0 to @p ord - 1 are kept.
 * @param[in] num  Gauss-point number to truncate. Must not be NULL.
 * @param[in] dhl  Direction helper list object.
 *
 * @return Newly allocated fesoti_t with the same number of integration points as @p num. Caller
 *         owns memory and must free via fesoti_free().
 *
 * @see fesoti_truncate_order_to() for the existing-destination variant.
 */
fesoti_t fesoti_truncate_order(    ord_t ord, fesoti_t* num,               dhelpl_t dhl);

/** @} */
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Copy functions.

@param[in] num Number to copy into res.
@param[in] res Result
@param[in] dhl Direction helper list
******************************************************************************************************/
fesoti_t fesoti_copy(    fesoti_t* src,                dhelpl_t dhl);
void     fesoti_copy_to( fesoti_t* src, fesoti_t* dst, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Set all elements as given num.

@param[in] num Number to set in res.
@param[in] res Result
@param[in] dhl Direction helper list
******************************************************************************************************/
void fesoti_set_r(    coeff_t num, fesoti_t* res, dhelpl_t dhl);
void fesoti_set_o( sotinum_t* num, fesoti_t* res, dhelpl_t dhl);
void fesoti_set_f(  fesoti_t* num, fesoti_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------


/**************************************************************************************************//**
@brief Set a specific imaginary direction.

@param[in] num OTI number to set the item.
@param[in] k   Integration point to set.
@param[in] res Integration point to set.
@param[in] dhl Direction helper list
******************************************************************************************************/
void fesoti_set_item_k_r(   coeff_t  num, uint64_t k, fesoti_t* res, dhelpl_t dhl);
void fesoti_set_item_k_o( sotinum_t* num, uint64_t k, fesoti_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------


/**************************************************************************************************//**
@brief Getter

@param[in] num Gauss number to get the item.
@param[in] k   Integration point to get.
@param[in] dhl Direction helper list
******************************************************************************************************/
sotinum_t fesoti_get_item_k(   fesoti_t* num, uint64_t k,                 dhelpl_t dhl);
void      fesoti_get_item_k_to(fesoti_t* num, uint64_t k, sotinum_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Create a gauss scalar filled with zeros.

@param[in] nIntPts Number of integration points. 
@param[in] nbases  Number of imaginary bases. 
@param[in] order   Truncation prder of the number
@param[in] dhl Direction helper list
******************************************************************************************************/
fesoti_t fesoti_zeros_bases(uint64_t nIntPts, bases_t nbases, ord_t order, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------


/**************************************************************************************************//**
@brief Reserve memory for gauss scalar.

@param[in] nIntPts Number of integration points. 
@param[in] nbases  Number of imaginary bases. 
@param[in] order   Truncation prder of the number
@param[in] dhl Direction helper list
******************************************************************************************************/
fesoti_t fesoti_createEmpty_bases(uint64_t nIntPts, bases_t nbases, ord_t order, dhelpl_t dhl);
fesoti_t fesoti_empty_like(fesoti_t* arr, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Free Gauss Sparse oti number.

@param[in] num FEsoti to free
******************************************************************************************************/
void fesoti_free(fesoti_t* num);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Get OTI truncation order.

@param[in] num FEsoti
******************************************************************************************************/
ord_t fesoti_get_order( fesoti_t* num );
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Initialize a fesoti structure.

******************************************************************************************************/
fesoti_t fesoti_init(void);
// ----------------------------------------------------------------------------------------------------


#endif