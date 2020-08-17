#ifndef OTI_SPARSE_ARRAY_GAUSS_BASE_H
#define OTI_SPARSE_ARRAY_GAUSS_BASE_H




void      fearrso_get_order_im_to( ord_t order, fearrso_t* arr, fearrso_t* res, dhelpl_t dhl);
fearrso_t fearrso_get_order_im(    ord_t order, fearrso_t* arr,                 dhelpl_t dhl);

fearrso_t fearrso_get_deriv(   imdir_t idx, ord_t order, fearrso_t* arr,                 dhelpl_t dhl);
void      fearrso_get_deriv_to(imdir_t idx, ord_t order, fearrso_t* arr, fearrso_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

fearrso_t fearrso_get_im(      imdir_t idx, ord_t order, fearrso_t* arr,                 dhelpl_t dhl);
void      fearrso_get_im_to(   imdir_t idx, ord_t order, fearrso_t* arr, fearrso_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

fearrso_t fearrso_truncate_im(   imdir_t idx, ord_t order, fearrso_t* arr,                 dhelpl_t dhl);
void      fearrso_truncate_im_to(imdir_t idx, ord_t order, fearrso_t* arr, fearrso_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------



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
@brief  Imaginary direction getters.

@param[in] arr Gauss array.

@param[in] res Gauss array, result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
fearrso_t fearrso_get_im(    imdir_t idx, ord_t order, fearrso_t* arr,                 dhelpl_t dhl);
void      fearrso_get_im_to( imdir_t idx, ord_t order, fearrso_t* arr, fearrso_t* res, dhelpl_t dhl);

fearrso_t fearrso_get_deriv(    imdir_t idx, ord_t order, fearrso_t* arr,                 dhelpl_t dhl);
void      fearrso_get_deriv_to( imdir_t idx, ord_t order, fearrso_t* arr, fearrso_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------




/**************************************************************************************************//**
@brief  Imaginary derivative extractors.

@param[in] idx Imagianry index.
@param[in] order Imagianry index.
@param[in] arr Gauss array.
@param[in] res Gauss array, result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
fearrso_t fearrso_extract_im(    imdir_t idx, ord_t order, fearrso_t* arr,                  dhelpl_t dhl);
void      fearrso_extract_im_to( imdir_t idx, ord_t order, fearrso_t* arr,  fearrso_t* res, dhelpl_t dhl);

fearrso_t fearrso_extract_deriv(    imdir_t idx, ord_t order, fearrso_t* arr,                 dhelpl_t dhl);
void      fearrso_extract_deriv_to( imdir_t idx, ord_t order, fearrso_t* arr, fearrso_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------






/**************************************************************************************************//**
@brief  Item getters.

@param[in] arr Gauss array.

@param[in] res Gauss array, result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
arrso_t   fearrso_get_item_k(  fearrso_t* arr, uint64_t k,                         dhelpl_t dhl);
fesoti_t  fearrso_get_item_ij( fearrso_t* arr, uint64_t i, uint64_t j,             dhelpl_t dhl);
sotinum_t fearrso_get_item_ijk(fearrso_t* arr, uint64_t i, uint64_t j, uint64_t k, dhelpl_t dhl);

void fearrso_get_item_ij_to(  fearrso_t* arr, uint64_t i, uint64_t j, 
                               fesoti_t* res, dhelpl_t dhl);

void fearrso_get_item_k_to(   fearrso_t* arr, uint64_t k, 
                                arrso_t* res, dhelpl_t dhl);

void fearrso_get_item_ijk_to( fearrso_t* arr, uint64_t i, uint64_t j, uint64_t k, 
                              sotinum_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Get slice from fearrso object.

@param[in]    arr    array to get slice.
@param[in]    starti Starting row index.
@param[in]    stopi  Final row index.
@param[in]    stepi  Row step.
@param[in]    startj Starting column index.
@param[in]    stopj  Final column index.
@param[in]    stepj  Column step.
@param[inout] res    Address of the result holder (if any)
@param[in]    dhl    Direction helper list object.
******************************************************************************************************/ 
fearrso_t fearrso_get_slice(fearrso_t* arr, 
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj, 
                           dhelpl_t dhl);

void      fearrso_get_slice_to(fearrso_t* arr, 
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj, 
                          fearrso_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------















/**************************************************************************************************//**
@brief Item setters

@param[in] elm   Element to set
@param[in] i     Row.
@param[in] j     Column.
@param[in] k     Integration point.
@param[in] dhl   Direction helper list.
******************************************************************************************************/
void fearrso_set_item_ij_r(   coeff_t  elm, uint64_t i, uint64_t j,
                            fearrso_t* res, dhelpl_t dhl);

void fearrso_set_item_ij_o(  sotinum_t* elm, uint64_t i, uint64_t j,
                             fearrso_t* res, dhelpl_t dhl);

void fearrso_set_item_ij_f(  fesoti_t* elm, uint64_t i, uint64_t j,
                            fearrso_t* res, dhelpl_t dhl);

void fearrso_set_item_k_r(    coeff_t  elm, uint64_t k, 
                            fearrso_t* res, dhelpl_t dhl);

void fearrso_set_item_k_o(  sotinum_t* elm, uint64_t k, 
                            fearrso_t* res, dhelpl_t dhl);

void fearrso_set_item_k_R(    arrso_t* elm, uint64_t k, 
                          fearrso_t* res, dhelpl_t dhl);

void fearrso_set_item_k_O(    arrso_t* elm, uint64_t k, 
                          fearrso_t* res, dhelpl_t dhl);

void fearrso_set_item_ijk_r(   coeff_t  elm, uint64_t i, uint64_t j, uint64_t k, 
                             fearrso_t* res, dhelpl_t dhl);

void fearrso_set_item_ijk_o( sotinum_t* elm, uint64_t i, uint64_t j, uint64_t k, 
                             fearrso_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------







/**************************************************************************************************//**
@brief Set slice to fearrso object.

@param[in]    val    Value to set in res array.
@param[in]    starti Starting row index.
@param[in]    stopi  Final row index.
@param[in]    stepi  Row step.
@param[in]    startj Starting column index.
@param[in]    stopj  Final column index.
@param[in]    stepj  Column step.
@param[inout] res    Address of the result holder
@param[in]    dhl    Direction helper list object.
******************************************************************************************************/ 
void fearrso_set_slice_r( coeff_t val, 
                         int64_t starti, int64_t stopi, int64_t stepi,
                         int64_t startj, int64_t stopj, int64_t stepj,
                          fearrso_t* res, dhelpl_t dhl);
void fearrso_set_slice_o( sotinum_t* val, 
                         int64_t starti, int64_t stopi, int64_t stepi,
                         int64_t startj, int64_t stopj, int64_t stepj,
                          fearrso_t* res, dhelpl_t dhl);
void fearrso_set_slice_f( fesoti_t* val, 
                         int64_t starti, int64_t stopi, int64_t stepi,
                         int64_t startj, int64_t stopj, int64_t stepj,
                          fearrso_t* res, dhelpl_t dhl);
void fearrso_set_slice_O( arrso_t* val, 
                         int64_t starti, int64_t stopi, int64_t stepi,
                         int64_t startj, int64_t stopj, int64_t stepj,
                          fearrso_t* res, dhelpl_t dhl);
void fearrso_set_slice_F( fearrso_t* val, 
                         int64_t starti, int64_t stopi, int64_t stepi,
                         int64_t startj, int64_t stopj, int64_t stepj,
                          fearrso_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------





/**************************************************************************************************//**
@brief Broadcasted setter.

@param[in]
@param[in] dhl Direction helper list.
******************************************************************************************************/
void fearrso_set_all_o( sotinum_t* num, fearrso_t* arr, dhelpl_t dhl );
void fearrso_set_all_r(   coeff_t  num, fearrso_t* arr, dhelpl_t dhl );
void fearrso_set_all_f(  fesoti_t* num, fearrso_t* arr, dhelpl_t dhl );

void fearrso_set_r(    coeff_t src, fearrso_t* res, dhelpl_t dhl );
void fearrso_set_o( sotinum_t* src, fearrso_t* res, dhelpl_t dhl );
void fearrso_set_f(  fesoti_t* src, fearrso_t* res, dhelpl_t dhl );

void fearrso_set_R(    darr_t* src, fearrso_t* res, dhelpl_t dhl );
void fearrso_set_O(   arrso_t* src, fearrso_t* res, dhelpl_t dhl );
void fearrso_set_F( fearrso_t* src, fearrso_t* res, dhelpl_t dhl );

// ----------------------------------------------------------------------------------------------------


/**************************************************************************************************//**
@brief Create a gauss array as the identity matrix.

@param[in] size     Size of the matrix (final shape: <size,size>)
@param[in] offsetx  Offset in the row direction.
@param[in] offsety  Offset in the column direction.
@param[in] nIntPts  Number of integration points.
@param[in] nbases   Number of imaginary basis.
@param[in] order    Truncation order of the number.
@param[in] dhl      Direction helper list.
******************************************************************************************************/
fearrso_t fearrso_eye_bases( uint64_t size,
                               uint64_t nip, bases_t  nbases, 
                               ord_t    order,   dhelpl_t dhl     );
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
@brief Create a gauss array of ones.

@param[in] nrows    Number of rows
@param[in] ncols    Number of columns
@param[in] offsetx  Offset in the row direction.
@param[in] offsety  Offset in the column direction.
@param[in] nIntPts  Number of integration points.
@param[in] nbases   Number of imaginary basis.
@param[in] order    Truncation order of the number.
@param[in] dhl      Direction helper list.
******************************************************************************************************/
fearrso_t fearrso_ones_bases( uint64_t nrows,   uint64_t ncols, 
                               uint64_t nip, bases_t  nbases, 
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