#ifndef OTI_SPARSE_ARRAY_GAUSS_BASE_H
#define OTI_SPARSE_ARRAY_GAUSS_BASE_H



/**************************************************************************************************//**
@brief Copy Gauss array.

@param[in] src. Item to copy.
@param[in] res  Result.
@param[in] dhl  Direction helper list.
******************************************************************************************************/
fearrso_t fearrso_copy(   fearrso_t* src,                 dhelpl_t dhl);
void      fearrso_copy_to(fearrso_t* src, fearrso_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief 

@param[in] arr Gauss array.

@param[in] res Gauss array, result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
arrso_t   fearrso_get_item_k(  fearrso_t* arr, uint64_t k,                         dhelpl_t dhl);
sotinum_t fearrso_get_item_ijk(fearrso_t* arr, uint64_t i, uint64_t j, uint64_t k, dhelpl_t dhl);

void fearrso_get_item_ij_to(  fearrso_t* arr, uint64_t i, uint64_t j, 
                              fearrso_t* res, dhelpl_t dhl);

void fearrso_get_item_k_to(   fearrso_t* arr, uint64_t k, 
                                arrso_t* res, dhelpl_t dhl);

void fearrso_get_item_ijk_to( fearrso_t* arr, uint64_t i, uint64_t j, uint64_t k, 
                              sotinum_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------


/**************************************************************************************************//**
@brief Item setters

@param[in] elm   Element to set
@param[in] i     Row.
@param[in] j     Column.
@param[in] k     Integration point.
@param[in] dhl   Direction helper list.
******************************************************************************************************/
void fearrso_set_item_ij( fesoti_t* elm, uint64_t i, uint64_t j,
                          // 
                          fearrso_t* res, dhelpl_t dhl);

void fearrso_set_item_k(    arrso_t* elm, 
                          uint64_t k, 
                          fearrso_t* res, dhelpl_t dhl);

void fearrso_set_item_ijk(sotinum_t* elm, uint64_t i, uint64_t j, 
                          uint64_t k, 
                          fearrso_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief 

@param[in]
@param[in] dhl Direction helper list.
******************************************************************************************************/
void fearrso_set_all_o( sotinum_t* num, fearrso_t* arr, dhelpl_t dhl );
void fearrso_set_all_r(    coeff_t num, fearrso_t* arr, dhelpl_t dhl );
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Create a gauss array of Zeros.

@param[in] nrows    Number of rows
@param[in] ncols    Number of columns
@param[in] offsetx  Offset in the row direction.
@param[in] offsety  Offset in the column direction.
@param[in] nIntPts  Number of integration points.
@param[in] nbases   Number of imaginary basis.
@param[in] order    Truncation order of the number.
@param[in] dhl      Direction helper list.
******************************************************************************************************/
fearrso_t fearrso_zeros_bases( uint64_t nrows,   uint64_t ncols, 
                               // uint64_t offsetx, uint64_t offsety, 
                               uint64_t nIntPts, bases_t  nbases, 
                               ord_t    order,   dhelpl_t dhl     );
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Create an empty gauss object.

@param[in] nrows    Number of rows
@param[in] ncols    Number of columns
@param[in] offsetx  Offset in the row direction.
@param[in] offsety  Offset in the column direction.
@param[in] nIntPts  Number of integration points.
@param[in] nbases   Number of imaginary basis.
@param[in] order    Truncation order of the number.
@param[in] dhl      Direction helper list.
******************************************************************************************************/
fearrso_t fearrso_createEmpty_bases( uint64_t nrows,   uint64_t ncols, 
                                     // uint64_t offsetx, uint64_t offsety, 
                                     uint64_t nIntPts, bases_t  nbases, 
                                     ord_t    order,   dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Free memory of Gauss array.

@param[in] arr. Gauss array to free memory.
******************************************************************************************************/
void fearrso_free(fearrso_t* arr);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Initialization of Gauss array

******************************************************************************************************/
fearrso_t fearrso_init(void);
// ----------------------------------------------------------------------------------------------------


/**************************************************************************************************//**
@brief Get the max trunctation order of the OTI structure.

@param[in] arr. Gauss array.
@param[in] dhl. Direction helper list.
@param[out] ord. Maximum truncation order.
******************************************************************************************************/
ord_t fearrso_get_order(fearrso_t* arr);
// ----------------------------------------------------------------------------------------------------







#endif