#ifndef OTI_SEMISPARSE_SCALAR_GAUSS_BASE_H
#define OTI_SEMISPARSE_SCALAR_GAUSS_BASE_H



void     fessoti_get_order_im_to( ord_t order, fessoti_t* num, fessoti_t* res, dhelpl_t dhl);
fessoti_t fessoti_get_order_im(    ord_t order, fessoti_t* num,                dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Get a specific imaginary direction from the number.

@param[in] idx   Index of imaginary direction.
@param[in] order Order of imaginary direction.
@param[in] num   Number.
@param[in] res   Result
@param[in] dhl   Direction helper list
******************************************************************************************************/
fessoti_t fessoti_get_im(    imdir_t idx, ord_t order, fessoti_t* num,                dhelpl_t dhl);
void     fessoti_get_im_to( imdir_t idx, ord_t order, fessoti_t* num, fessoti_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Get a specific derivative from the number.

@param[in] idx   Index of imaginary direction.
@param[in] order Order of imaginary direction.
@param[in] num   Number.
@param[in] res   Result
@param[in] dhl   Direction helper list
******************************************************************************************************/
fessoti_t fessoti_get_deriv(    imdir_t idx, ord_t order, fessoti_t* num,                dhelpl_t dhl);
void     fessoti_get_deriv_to( imdir_t idx, ord_t order, fessoti_t* num, fessoti_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Set a specific derivative.

@param[in] idx   Index of imaginary direction.
@param[in] order Order of imaginary direction.
@param[in] num   Number.
@param[in] res   Result
@param[in] dhl   Direction helper list
******************************************************************************************************/
void fessoti_set_im_r(   coeff_t  val, imdir_t idx, ord_t order, fessoti_t* num, dhelpl_t dhl);
void fessoti_set_im_o( semiotin_t* val, imdir_t idx, ord_t order, fessoti_t* num, dhelpl_t dhl);
void fessoti_set_im_f(  fessoti_t* val, imdir_t idx, ord_t order, fessoti_t* num, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------


/**************************************************************************************************//**
@brief Set a specific derivative.

@param[in] idx   Index of imaginary direction.
@param[in] order Order of imaginary direction.
@param[in] num   Number.
@param[in] res   Result
@param[in] dhl   Direction helper list
******************************************************************************************************/
void fessoti_set_deriv_r(   coeff_t  val, imdir_t idx, ord_t order, fessoti_t* num, dhelpl_t dhl);
void fessoti_set_deriv_o( semiotin_t* val, imdir_t idx, ord_t order, fessoti_t* num, dhelpl_t dhl);
void fessoti_set_deriv_f(  fessoti_t* val, imdir_t idx, ord_t order, fessoti_t* num, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------



/**************************************************************************************************//**
@brief Extract full derivative as oti number.

@param[in] num   Number.
@param[in] idx   Index of imaginary direction.
@param[in] order Order of imaginary direction.
@param[in] res   Result
@param[in] dhl   Direction helper list
******************************************************************************************************/
fessoti_t fessoti_extract_im(    imdir_t idx, ord_t order, fessoti_t* num,                dhelpl_t dhl);
void     fessoti_extract_im_to( imdir_t idx, ord_t order, fessoti_t* num, fessoti_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Extract full derivative as oti number.

@param[in] num   Number.
@param[in] idx   Index of imaginary direction.
@param[in] order Order of imaginary direction.
@param[in] res   Result
@param[in] dhl   Direction helper list
******************************************************************************************************/
fessoti_t fessoti_extract_deriv(    imdir_t idx, ord_t order, fessoti_t* num,                dhelpl_t dhl);
void     fessoti_extract_deriv_to( imdir_t idx, ord_t order, fessoti_t* num, fessoti_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Truncate by given imaginary direction.

@param[in] num   Number.
@param[in] idx   Index of imaginary direction.
@param[in] order Order of imaginary direction.
@param[in] res   Result
@param[in] dhl   Direction helper list
******************************************************************************************************/
fessoti_t fessoti_truncate_im(    imdir_t idx, ord_t order, fessoti_t* num,                dhelpl_t dhl);
void     fessoti_truncate_im_to( imdir_t idx, ord_t order, fessoti_t* num, fessoti_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------


/**************************************************************************************************//**
@brief Copy functions.

@param[in] num Number to copy into res.
@param[in] res Result
@param[in] dhl Direction helper list
******************************************************************************************************/
fessoti_t fessoti_copy(    fessoti_t* src,                dhelpl_t dhl);
void     fessoti_copy_to( fessoti_t* src, fessoti_t* dst, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Set all elements as given num.

@param[in] num Number to set in res.
@param[in] res Result
@param[in] dhl Direction helper list
******************************************************************************************************/
void fessoti_set_r(    coeff_t num, fessoti_t* res, dhelpl_t dhl);
void fessoti_set_o( semiotin_t* num, fessoti_t* res, dhelpl_t dhl);
void fessoti_set_f(  fessoti_t* num, fessoti_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------


/**************************************************************************************************//**
@brief Set a specific imaginary direction.

@param[in] num OTI number to set the item.
@param[in] k   Integration point to set.
@param[in] res Integration point to set.
@param[in] dhl Direction helper list
******************************************************************************************************/
void fessoti_set_item_k_r(   coeff_t  num, uint64_t k, fessoti_t* res, dhelpl_t dhl);
void fessoti_set_item_k_o( semiotin_t* num, uint64_t k, fessoti_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------


/**************************************************************************************************//**
@brief Getter

@param[in] num Gauss number to get the item.
@param[in] k   Integration point to get.
@param[in] dhl Direction helper list
******************************************************************************************************/
semiotin_t fessoti_get_item_k(   fessoti_t* num, uint64_t k,                 dhelpl_t dhl);
void      fessoti_get_item_k_to(fessoti_t* num, uint64_t k, semiotin_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Create a gauss scalar filled with zeros.

@param[in] nIntPts Number of integration points. 
@param[in] nbases  Number of imaginary bases. 
@param[in] order   Truncation prder of the number
@param[in] dhl Direction helper list
******************************************************************************************************/
fessoti_t fessoti_zeros_bases(uint64_t nIntPts, bases_t nbases, ord_t order, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------


/**************************************************************************************************//**
@brief Reserve memory for gauss scalar.

@param[in] nIntPts Number of integration points. 
@param[in] nbases  Number of imaginary bases. 
@param[in] order   Truncation prder of the number
@param[in] dhl Direction helper list
******************************************************************************************************/
fessoti_t fessoti_createEmpty_bases(uint64_t nIntPts, bases_t nbases, ord_t order, dhelpl_t dhl);
fessoti_t fessoti_empty_like(fessoti_t* arr, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Free Gauss Sparse oti number.

@param[in] num FEsoti to free
******************************************************************************************************/
void fessoti_free(fessoti_t* num);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Get OTI truncation order.

@param[in] num FEsoti
******************************************************************************************************/
ord_t fessoti_get_order( fessoti_t* num );
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Initialize a fesoti structure.

******************************************************************************************************/
fessoti_t fessoti_init(void);
// ----------------------------------------------------------------------------------------------------


#endif