#ifndef OTI_REAL_ARRAY_GAUSS_BASE_H
#define OTI_REAL_ARRAY_GAUSS_BASE_H



/**************************************************************************************************//**
@brief Copy Gauss array.

@param[in] src. Item to copy.
@param[in] res  Result.
******************************************************************************************************/
fedarr_t fedarr_copy(   fedarr_t* src               );
void     fedarr_copy_to(fedarr_t* src, fedarr_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief  Item getters.

@param[in] arr Gauss array.

@param[in] res Gauss array, result.
@param[in] dhl Direction helper list.
******************************************************************************************************/
darr_t   fedarr_get_item_k(  fedarr_t* arr, uint64_t k                         );
fednum_t fedarr_get_item_ij( fedarr_t* arr, uint64_t i, uint64_t j             );
coeff_t  fedarr_get_item_ijk(fedarr_t* arr, uint64_t i, uint64_t j, uint64_t k );

void fedarr_get_item_ij_to(  fedarr_t* arr, uint64_t i, uint64_t j, fednum_t* res);

void fedarr_get_item_k_to(   fedarr_t* arr, uint64_t k, darr_t* res);

void fedarr_get_item_ijk_to( fedarr_t* arr, uint64_t i, uint64_t j, uint64_t k, coeff_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Get slice from fedarr object.

@param[in]    arr    array to get slice.
@param[in]    starti Starting row index.
@param[in]    stopi  Final row index.
@param[in]    stepi  Row step.
@param[in]    startj Starting column index.
@param[in]    stopj  Final column index.
@param[in]    stepj  Column step.
@param[inout] res    Address of the result holder (if any)
******************************************************************************************************/ 
fedarr_t fedarr_get_slice(fedarr_t* arr, 
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj );

void     fedarr_get_slice_to(fedarr_t* arr, 
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj, 
                          fedarr_t* res);
// ----------------------------------------------------------------------------------------------------















/**************************************************************************************************//**
@brief Item setters

@param[in] elm   Element to set
@param[in] i     Row.
@param[in] j     Column.
@param[in] k     Integration point.
******************************************************************************************************/
void fedarr_set_item_ij_r(   coeff_t  elm, uint64_t i, uint64_t j, fedarr_t* res);
void fedarr_set_item_ij_f(  fednum_t* elm, uint64_t i, uint64_t j, fedarr_t* res);

void fedarr_set_item_k_r(    coeff_t  elm, uint64_t k, fedarr_t* res);
void fedarr_set_item_k_R(     darr_t* elm, uint64_t k, fedarr_t* res);

void fedarr_set_item_ijk_r(   coeff_t  elm, uint64_t i, uint64_t j, uint64_t k, fedarr_t* res);
// ----------------------------------------------------------------------------------------------------







/**************************************************************************************************//**
@brief Set slice to fedarr object.

@param[in]    val    Value to set in res array.
@param[in]    starti Starting row index.
@param[in]    stopi  Final row index.
@param[in]    stepi  Row step.
@param[in]    startj Starting column index.
@param[in]    stopj  Final column index.
@param[in]    stepj  Column step.
@param[inout] res    Address of the result holder
******************************************************************************************************/ 
void fedarr_set_slice_r( coeff_t val, 
                         int64_t starti, int64_t stopi, int64_t stepi,
                         int64_t startj, int64_t stopj, int64_t stepj,
                          fedarr_t* res);
void fedarr_set_slice_f( fednum_t* val, 
                         int64_t starti, int64_t stopi, int64_t stepi,
                         int64_t startj, int64_t stopj, int64_t stepj,
                          fedarr_t* res);
void fedarr_set_slice_F( fedarr_t* val, 
                         int64_t starti, int64_t stopi, int64_t stepi,
                         int64_t startj, int64_t stopj, int64_t stepj,
                          fedarr_t* res);
// ----------------------------------------------------------------------------------------------------




/**************************************************************************************************//**
@brief Broadcasted setter.

@param[in]
******************************************************************************************************/
void fedarr_set_all_r(   coeff_t  num, fedarr_t* arr );
void fedarr_set_all_f(  fednum_t* num, fedarr_t* arr );

void fedarr_set_r(    coeff_t src, fedarr_t* res );
void fedarr_set_f(  fednum_t* src, fedarr_t* res );

void fedarr_set_R(    darr_t* src, fedarr_t* res );
void fedarr_set_F(  fedarr_t* src, fedarr_t* res );

// ----------------------------------------------------------------------------------------------------


/**************************************************************************************************//**
@brief Create a gauss array as the identity matrix.

@param[in] size     Size of the matrix (final shape: <size,size>)
@param[in] offsetx  Offset in the row direction.
@param[in] offsety  Offset in the column direction.
@param[in] nIntPts  Number of integration points.
******************************************************************************************************/
fedarr_t fedarr_eye( uint64_t size, uint64_t nip );
// ----------------------------------------------------------------------------------------------------


/**************************************************************************************************//**
@brief Create a gauss array of Zeros.

@param[in] nrows    Number of rows
@param[in] ncols    Number of columns
@param[in] nIntPts  Number of integration points.
******************************************************************************************************/
fedarr_t fedarr_zeros( uint64_t nrows, uint64_t ncols, uint64_t nIntPts );
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Create a gauss array of ones.

@param[in] nrows    Number of rows
@param[in] ncols    Number of columns
@param[in] offsetx  Offset in the row direction.
@param[in] offsety  Offset in the column direction.
@param[in] nIntPts  Number of integration points.
******************************************************************************************************/
fedarr_t fedarr_ones( uint64_t nrows, uint64_t ncols, uint64_t nip );
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Create an empty gauss object.

@param[in] nrows    Number of rows
@param[in] ncols    Number of columns
@param[in] offsetx  Offset in the row direction.
@param[in] offsety  Offset in the column direction.
@param[in] nIntPts  Number of integration points.
******************************************************************************************************/
fedarr_t fedarr_createEmpty( uint64_t nrows, uint64_t ncols, uint64_t nIntPts );
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Free memory of Gauss array.

@param[in] arr. Gauss array to free memory.
******************************************************************************************************/
void fedarr_free(fedarr_t* arr);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Initialization of Gauss array

******************************************************************************************************/
fedarr_t fedarr_init(void);
// ----------------------------------------------------------------------------------------------------


#endif