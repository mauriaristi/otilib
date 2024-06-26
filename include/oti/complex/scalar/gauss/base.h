#ifndef OTI_COMPLEX_SCALAR_GAUSS_BASE_H
#define OTI_COMPLEX_SCALAR_GAUSS_BASE_H


/**************************************************************************************************//**
@brief Copy functions.

@param[in] num Number to copy into res.
@param[in] res Result
******************************************************************************************************/
fecnum_t fecnum_copy(    fecnum_t* src               );
void     fecnum_copy_to( fecnum_t* src, fecnum_t* dst);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Set all elements as given num.

@param[in] num Number to set in res.
@param[in] res Result
******************************************************************************************************/
void fecnum_set_r(    ccoeff_t num, fecnum_t* res);
void fecnum_set_f(  fecnum_t* num, fecnum_t* res);
// ----------------------------------------------------------------------------------------------------


/**************************************************************************************************//**
@brief Set a specific imaginary direction.

@param[in] num real number to set the item.
@param[in] k   Integration point to set.
@param[in] res Integration point to set.
******************************************************************************************************/
void fecnum_set_item_k_r(   ccoeff_t  num, uint64_t k, fecnum_t* res);
// ----------------------------------------------------------------------------------------------------


/**************************************************************************************************//**
@brief Getter

@param[in] num Gauss number to get the item.
@param[in] k   Integration point to get.
******************************************************************************************************/
ccoeff_t fecnum_get_item_k(   fecnum_t* num, uint64_t k              );
void    fecnum_get_item_k_to(fecnum_t* num, uint64_t k, ccoeff_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Create a gauss scalar filled with zeros.

@param[in] nIntPts Number of integration points. 
******************************************************************************************************/
fecnum_t fecnum_zeros(uint64_t nIntPts);
// ----------------------------------------------------------------------------------------------------


/**************************************************************************************************//**
@brief Reserve memory for gauss scalar.

@param[in] nIntPts Number of integration points. 
******************************************************************************************************/
fecnum_t fecnum_createEmpty(uint64_t nIntPts);
fecnum_t fecnum_empty_like(fecnum_t* arr);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Free Gauss Sparse real number.

@param[in] num fecnum to free
******************************************************************************************************/
void fecnum_free(fecnum_t* num);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Initialize a fecnum structure.

******************************************************************************************************/
fecnum_t fecnum_init(void);
// ----------------------------------------------------------------------------------------------------



#endif