#ifndef OTI_ONUMM5N4_SCALAR_GAUSS_BASE_H
#define OTI_ONUMM5N4_SCALAR_GAUSS_BASE_H

void     feonumm5n4_get_order_im_to( ord_t order, feonumm5n4_t* num, feonumm5n4_t* res);
feonumm5n4_t feonumm5n4_get_order_im(    ord_t order, feonumm5n4_t* num);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Get a specific imaginary direction from the number.

@param[in] idx   Index of imaginary direction.
@param[in] order Order of imaginary direction.
@param[in] num   Number.
@param[in] res   Result
@param[in] dhl   Direction helper list
******************************************************************************************************/
feonumm5n4_t feonumm5n4_get_im(    imdir_t idx, ord_t order, feonumm5n4_t* num);
void     feonumm5n4_get_im_to( imdir_t idx, ord_t order, feonumm5n4_t* num, feonumm5n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Get a specific derivative from the number.

@param[in] idx   Index of imaginary direction.
@param[in] order Order of imaginary direction.
@param[in] num   Number.
@param[in] res   Result
@param[in] dhl   Direction helper list
******************************************************************************************************/
feonumm5n4_t feonumm5n4_get_deriv(    imdir_t idx, ord_t order, feonumm5n4_t* num);
void     feonumm5n4_get_deriv_to( imdir_t idx, ord_t order, feonumm5n4_t* num, feonumm5n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Set a specific derivative.

@param[in] idx   Index of imaginary direction.
@param[in] order Order of imaginary direction.
@param[in] num   Number.
@param[in] res   Result
@param[in] dhl   Direction helper list
******************************************************************************************************/
void feonumm5n4_set_im_r(   coeff_t  val, imdir_t idx, ord_t order, feonumm5n4_t* num);
void feonumm5n4_set_im_o( onumm5n4_t* val, imdir_t idx, ord_t order, feonumm5n4_t* num);
void feonumm5n4_set_im_f(  feonumm5n4_t* val, imdir_t idx, ord_t order, feonumm5n4_t* num);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Set a specific derivative.

@param[in] idx   Index of imaginary direction.
@param[in] order Order of imaginary direction.
@param[in] num   Number.
@param[in] res   Result
@param[in] dhl   Direction helper list
******************************************************************************************************/
void feonumm5n4_set_deriv_r(   coeff_t  val, imdir_t idx, ord_t order, feonumm5n4_t* num);
void feonumm5n4_set_deriv_o( onumm5n4_t* val, imdir_t idx, ord_t order, feonumm5n4_t* num);
void feonumm5n4_set_deriv_f(  feonumm5n4_t* val, imdir_t idx, ord_t order, feonumm5n4_t* num);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Extract full derivative as oti number.

@param[in] num   Number.
@param[in] idx   Index of imaginary direction.
@param[in] order Order of imaginary direction.
@param[in] res   Result
@param[in] dhl   Direction helper list
******************************************************************************************************/
feonumm5n4_t feonumm5n4_extract_im(    imdir_t idx, ord_t order, feonumm5n4_t* num);
void     feonumm5n4_extract_im_to( imdir_t idx, ord_t order, feonumm5n4_t* num, feonumm5n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Extract full derivative as oti number.

@param[in] num   Number.
@param[in] idx   Index of imaginary direction.
@param[in] order Order of imaginary direction.
@param[in] res   Result
@param[in] dhl   Direction helper list
******************************************************************************************************/
feonumm5n4_t feonumm5n4_extract_deriv(    imdir_t idx, ord_t order, feonumm5n4_t* num);
void     feonumm5n4_extract_deriv_to( imdir_t idx, ord_t order, feonumm5n4_t* num, feonumm5n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Truncate by given imaginary direction.

@param[in] num   Number.
@param[in] idx   Index of imaginary direction.
@param[in] order Order of imaginary direction.
@param[in] res   Result
@param[in] dhl   Direction helper list
******************************************************************************************************/
feonumm5n4_t feonumm5n4_truncate_im(    imdir_t idx, ord_t order, feonumm5n4_t* num);
void     feonumm5n4_truncate_im_to( imdir_t idx, ord_t order, feonumm5n4_t* num, feonumm5n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Copy functions.

@param[in] num Number to copy into res.
@param[in] res Result
@param[in] dhl Direction helper list
******************************************************************************************************/
feonumm5n4_t feonumm5n4_copy(    feonumm5n4_t* src);
void     feonumm5n4_copy_to( feonumm5n4_t* src, feonumm5n4_t* dst);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Set all elements as given num.

@param[in] num Number to set in res.
@param[in] res Result
@param[in] dhl Direction helper list
******************************************************************************************************/
void feonumm5n4_set_r(    coeff_t num, feonumm5n4_t* res);
void feonumm5n4_set_o( onumm5n4_t* num, feonumm5n4_t* res);
void feonumm5n4_set_f(  feonumm5n4_t* num, feonumm5n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Set a specific imaginary direction.

@param[in] num OTI number to set the item.
@param[in] k   Integration point to set.
@param[in] res Integration point to set.
@param[in] dhl Direction helper list
******************************************************************************************************/
void feonumm5n4_set_item_k_r(   coeff_t  num, uint64_t k, feonumm5n4_t* res);
void feonumm5n4_set_item_k_o( onumm5n4_t* num, uint64_t k, feonumm5n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Getter

@param[in] num Gauss number to get the item.
@param[in] k   Integration point to get.
@param[in] dhl Direction helper list
******************************************************************************************************/
onumm5n4_t feonumm5n4_get_item_k(   feonumm5n4_t* num, uint64_t k);
void      feonumm5n4_get_item_k_to(feonumm5n4_t* num, uint64_t k, onumm5n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Create a gauss scalar filled with zeros.

@param[in] nIntPts Number of integration points. 
@param[in] nbases  Number of imaginary bases. 
@param[in] order   Truncation prder of the number
@param[in] dhl Direction helper list
******************************************************************************************************/
feonumm5n4_t feonumm5n4_zeros(uint64_t nIntPts);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Reserve memory for gauss scalar.

@param[in] nIntPts Number of integration points. 
@param[in] nbases  Number of imaginary bases. 
@param[in] order   Truncation prder of the number
@param[in] dhl Direction helper list
******************************************************************************************************/
feonumm5n4_t feonumm5n4_createEmpty(uint64_t nIntPts);
feonumm5n4_t feonumm5n4_empty_like(feonumm5n4_t* arr);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Free Gauss Sparse oti number.

@param[in] num FEonumm5n4 to free
******************************************************************************************************/
void feonumm5n4_free(feonumm5n4_t* num);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Get OTI truncation order.

@param[in] num FEonumm5n4
******************************************************************************************************/
ord_t feonumm5n4_get_order( feonumm5n4_t* num );
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Initialize a feonumm5n4 structure.

******************************************************************************************************/
feonumm5n4_t feonumm5n4_init(void);
// ----------------------------------------------------------------------------------------------------

#endif