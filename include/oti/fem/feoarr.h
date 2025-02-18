#ifndef OTI_FEM_FEOARR_H
#define OTI_FEM_FEOARR_H
// ARRAY:

/**************************************************************************************************//**
@brief 

@param[in]
******************************************************************************************************/ 
void feoarr_gaussIntegrateOverElement(feoarr_t* arr1, elemProps_t* elem, oarr_t* res, 
    dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief 

@param[in]
******************************************************************************************************/
void feoarr_sub_FF_to(feoarr_t* arr1, feoarr_t* arr2, feoarr_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief 

@param[in]
******************************************************************************************************/
void feoarr_sum_FF_to(feoarr_t* arr1, feoarr_t* arr2, feoarr_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief 

@param[in]
******************************************************************************************************/
void feoarr_neg_to(feoarr_t* arr, feoarr_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief 

@param[in]
******************************************************************************************************/
void feoarr_mul_oF_to( otinum_t* num, feoarr_t* arr, feoarr_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief 

@param[in]
******************************************************************************************************/
void feoarr_mul_rF_to(coeff_t num, feoarr_t* arr, feoarr_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief 

@param[in]
******************************************************************************************************/
void feoarr_matmul_to(feoarr_t* lhs, feoarr_t* rhs, feoarr_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief 

@param[in]
******************************************************************************************************/
void feoarr_det_to(feoarr_t* arr, feoarr_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief 

@param[in]
******************************************************************************************************/
void feoarr_invert_to(feoarr_t* arr, feoarr_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief 

@param[in]
******************************************************************************************************/
void feoarr_copy_to(feoarr_t* src, feoarr_t* dst, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief 

@param[in]
******************************************************************************************************/
feoarr_t feoarr_copy(feoarr_t* src, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief 

@param[in]
******************************************************************************************************/
void feoarr_get_item_ij_to(feoarr_t* arr, uint64_t i, uint64_t j, feoarr_t* res,dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief 

@param[in]
******************************************************************************************************/
void feoarr_get_item_k_to(feoarr_t* arr, uint64_t k, oarr_t* res,dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief 

@param[in]
******************************************************************************************************/
void feoarr_get_item_ijk_to(feoarr_t* arr, uint64_t i, uint64_t j, uint64_t k, otinum_t* res,dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief 

@param[in]
******************************************************************************************************/
void feoarr_set_item_ij(feoarr_t* arr, uint64_t i, uint64_t j, feoarr_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief 

@param[in]
******************************************************************************************************/
void feoarr_set_item_k( oarr_t* arr , uint64_t k, feoarr_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief 

@param[in]
******************************************************************************************************/
void feoarr_set_item_ijk(otinum_t* num, uint64_t i, uint64_t j, uint64_t k, feoarr_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief 

@param[in]
******************************************************************************************************/
feoarr_t feoarr_zeros( uint64_t nrows, uint64_t ncols, uint64_t offsetx, uint64_t offsety, 
                       uint64_t nIntPts, bases_t nbases, ord_t order, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief 

@param[in]
******************************************************************************************************/
void feoarr_free(feoarr_t* arr);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief 

@param[in]
******************************************************************************************************/
feoarr_t feoarr_init( void );
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief 

@param[in]
******************************************************************************************************/
feoarr_t feoarr_createEmpty( uint64_t nrows, uint64_t ncols, uint64_t offsetx, uint64_t offsety, 
                             uint64_t nIntPts, bases_t nbases, ord_t order, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

#endif