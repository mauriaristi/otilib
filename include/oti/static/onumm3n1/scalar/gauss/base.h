#ifndef OTI_ONUMM3N1_SCALAR_GAUSS_BASE_H
#define OTI_ONUMM3N1_SCALAR_GAUSS_BASE_H

void     feonumm3n1_get_order_im_to( ord_t order, feonumm3n1_t* num, feonumm3n1_t* res);
feonumm3n1_t feonumm3n1_get_order_im(    ord_t order, feonumm3n1_t* num);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Get a specific imaginary direction from the number.

@param[in] idx   Index of imaginary direction.
@param[in] order Order of imaginary direction.
@param[in] num   Number.
@param[in] res   Result
@param[in] dhl   Direction helper list
******************************************************************************************************/
feonumm3n1_t feonumm3n1_get_im(    imdir_t idx, ord_t order, feonumm3n1_t* num);
void     feonumm3n1_get_im_to( imdir_t idx, ord_t order, feonumm3n1_t* num, feonumm3n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Get a specific derivative from the number.

@param[in] idx   Index of imaginary direction.
@param[in] order Order of imaginary direction.
@param[in] num   Number.
@param[in] res   Result
@param[in] dhl   Direction helper list
******************************************************************************************************/
feonumm3n1_t feonumm3n1_get_deriv(    imdir_t idx, ord_t order, feonumm3n1_t* num);
void     feonumm3n1_get_deriv_to( imdir_t idx, ord_t order, feonumm3n1_t* num, feonumm3n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Set a specific derivative.

@param[in] idx   Index of imaginary direction.
@param[in] order Order of imaginary direction.
@param[in] num   Number.
@param[in] res   Result
@param[in] dhl   Direction helper list
******************************************************************************************************/
void feonumm3n1_set_im_r(   coeff_t  val, imdir_t idx, ord_t order, feonumm3n1_t* num);
void feonumm3n1_set_im_o( onumm3n1_t* val, imdir_t idx, ord_t order, feonumm3n1_t* num);
void feonumm3n1_set_im_f(  feonumm3n1_t* val, imdir_t idx, ord_t order, feonumm3n1_t* num);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Set a specific derivative.

@param[in] idx   Index of imaginary direction.
@param[in] order Order of imaginary direction.
@param[in] num   Number.
@param[in] res   Result
@param[in] dhl   Direction helper list
******************************************************************************************************/
void feonumm3n1_set_deriv_r(   coeff_t  val, imdir_t idx, ord_t order, feonumm3n1_t* num);
void feonumm3n1_set_deriv_o( onumm3n1_t* val, imdir_t idx, ord_t order, feonumm3n1_t* num);
void feonumm3n1_set_deriv_f(  feonumm3n1_t* val, imdir_t idx, ord_t order, feonumm3n1_t* num);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Extract full derivative as oti number.

@param[in] num   Number.
@param[in] idx   Index of imaginary direction.
@param[in] order Order of imaginary direction.
@param[in] res   Result
@param[in] dhl   Direction helper list
******************************************************************************************************/
feonumm3n1_t feonumm3n1_extract_im(    imdir_t idx, ord_t order, feonumm3n1_t* num);
void     feonumm3n1_extract_im_to( imdir_t idx, ord_t order, feonumm3n1_t* num, feonumm3n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Extract full derivative as oti number.

@param[in] num   Number.
@param[in] idx   Index of imaginary direction.
@param[in] order Order of imaginary direction.
@param[in] res   Result
@param[in] dhl   Direction helper list
******************************************************************************************************/
feonumm3n1_t feonumm3n1_extract_deriv(    imdir_t idx, ord_t order, feonumm3n1_t* num);
void     feonumm3n1_extract_deriv_to( imdir_t idx, ord_t order, feonumm3n1_t* num, feonumm3n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Truncate by given imaginary direction.

@param[in] num   Number.
@param[in] idx   Index of imaginary direction.
@param[in] order Order of imaginary direction.
@param[in] res   Result
@param[in] dhl   Direction helper list
******************************************************************************************************/
feonumm3n1_t feonumm3n1_truncate_im(    imdir_t idx, ord_t order, feonumm3n1_t* num);
void     feonumm3n1_truncate_im_to( imdir_t idx, ord_t order, feonumm3n1_t* num, feonumm3n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Copy functions.

@param[in] num Number to copy into res.
@param[in] res Result
@param[in] dhl Direction helper list
******************************************************************************************************/
feonumm3n1_t feonumm3n1_copy(    feonumm3n1_t* src);
void     feonumm3n1_copy_to( feonumm3n1_t* src, feonumm3n1_t* dst);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Set all elements as given num.

@param[in] num Number to set in res.
@param[in] res Result
@param[in] dhl Direction helper list
******************************************************************************************************/
void feonumm3n1_set_r(    coeff_t num, feonumm3n1_t* res);
void feonumm3n1_set_o( onumm3n1_t* num, feonumm3n1_t* res);
void feonumm3n1_set_f(  feonumm3n1_t* num, feonumm3n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Set a specific imaginary direction.

@param[in] num OTI number to set the item.
@param[in] k   Integration point to set.
@param[in] res Integration point to set.
@param[in] dhl Direction helper list
******************************************************************************************************/
void feonumm3n1_set_item_k_r(   coeff_t  num, uint64_t k, feonumm3n1_t* res);
void feonumm3n1_set_item_k_o( onumm3n1_t* num, uint64_t k, feonumm3n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Getter

@param[in] num Gauss number to get the item.
@param[in] k   Integration point to get.
@param[in] dhl Direction helper list
******************************************************************************************************/
onumm3n1_t feonumm3n1_get_item_k(   feonumm3n1_t* num, uint64_t k);
void      feonumm3n1_get_item_k_to(feonumm3n1_t* num, uint64_t k, onumm3n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Create a gauss scalar filled with zeros.

@param[in] nIntPts Number of integration points. 
@param[in] nbases  Number of imaginary bases. 
@param[in] order   Truncation prder of the number
@param[in] dhl Direction helper list
******************************************************************************************************/
feonumm3n1_t feonumm3n1_zeros(uint64_t nIntPts);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Reserve memory for gauss scalar.

@param[in] nIntPts Number of integration points. 
@param[in] nbases  Number of imaginary bases. 
@param[in] order   Truncation prder of the number
@param[in] dhl Direction helper list
******************************************************************************************************/
feonumm3n1_t feonumm3n1_createEmpty(uint64_t nIntPts);
feonumm3n1_t feonumm3n1_empty_like(feonumm3n1_t* arr);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Free Gauss Sparse oti number.

@param[in] num FEonumm3n1 to free
******************************************************************************************************/
void feonumm3n1_free(feonumm3n1_t* num);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Get OTI truncation order.

@param[in] num FEonumm3n1
******************************************************************************************************/
ord_t feonumm3n1_get_order( feonumm3n1_t* num );
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Initialize a feonumm3n1 structure.

******************************************************************************************************/
feonumm3n1_t feonumm3n1_init(void);
// ----------------------------------------------------------------------------------------------------

#endif