#ifndef OTI_REAL_SCALAR_GAUSS_BASE_H
#define OTI_REAL_SCALAR_GAUSS_BASE_H


/**************************************************************************************************//**
@brief Copy functions.

@param[in] num Number to copy into res.
@param[in] res Result
******************************************************************************************************/
fednum_t fednum_copy(    fednum_t* src               );
void     fednum_copy_to( fednum_t* src, fednum_t* dst);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Set all elements as given num.

@param[in] num Number to set in res.
@param[in] res Result
******************************************************************************************************/
void fednum_set_r(    coeff_t num, fednum_t* res);
void fednum_set_f(  fednum_t* num, fednum_t* res);
// ----------------------------------------------------------------------------------------------------


/**************************************************************************************************//**
@brief Set a specific imaginary direction.

@param[in] num real number to set the item.
@param[in] k   Integration point to set.
@param[in] res Integration point to set.
******************************************************************************************************/
void fednum_set_item_k_r(   coeff_t  num, uint64_t k, fednum_t* res);
// ----------------------------------------------------------------------------------------------------


/**************************************************************************************************//**
@brief Getter

@param[in] num Gauss number to get the item.
@param[in] k   Integration point to get.
******************************************************************************************************/
coeff_t fednum_get_item_k(   fednum_t* num, uint64_t k              );
void    fednum_get_item_k_to(fednum_t* num, uint64_t k, coeff_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Create a gauss scalar filled with zeros.

@param[in] nIntPts Number of integration points. 
******************************************************************************************************/
fednum_t fednum_zeros(uint64_t nIntPts);
// ----------------------------------------------------------------------------------------------------


/**************************************************************************************************//**
@brief Reserve memory for gauss scalar.

@param[in] nIntPts Number of integration points. 
******************************************************************************************************/
fednum_t fednum_createEmpty(uint64_t nIntPts);
fednum_t fednum_empty_like(fednum_t* arr);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Free Gauss Sparse real number.

@param[in] num fednum to free
******************************************************************************************************/
void fednum_free(fednum_t* num);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Initialize a fednum structure.

******************************************************************************************************/
fednum_t fednum_init(void);
// ----------------------------------------------------------------------------------------------------



#endif