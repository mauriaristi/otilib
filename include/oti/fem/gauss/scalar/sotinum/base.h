#ifndef OTI_FEM_GAUSS_SCALAR_SOTINUM_BASE_H
#define OTI_FEM_GAUSS_SCALAR_SOTINUM_BASE_H





/**************************************************************************************************//**
@brief Setter.

@param[in] num Number to set in res.
@param[in] res Result
@param[in] dhl Direction helper list
******************************************************************************************************/
void fesoti_set_all_o( sotinum_t* num, fesoti_t* res, dhelpl_t dhl);
void fesoti_set_all_r(    coeff_t num, fesoti_t* res, dhelpl_t dhl);
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
@brief Free Gauss Sparse oti number.

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
@brief Initialize a fesoti structure.

******************************************************************************************************/
fesoti_t fesoti_init(void);
// ----------------------------------------------------------------------------------------------------


#endif