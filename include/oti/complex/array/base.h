#ifndef OTI_COMPLEX_BASE_H
#define OTI_COMPLEX_BASE_H


/**************************************************************************************************//**
@brief Set all elements in array as num.

ARR[:,:] = num

@param[in] num: Scalar to set.
@param[in] arr: Array to be set..
******************************************************************************************************/ 
void carr_set_all(   ccoeff_t num, carr_t* arr);
void carr_set_all_r( ccoeff_t num, carr_t* arr);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Get element at position i,j in p_array. 

res = ARR[i,j]

@param[inout] arr: Address of the array.
@param[in] i: Row
@param[in] j: Column
******************************************************************************************************/ 
ccoeff_t carr_get_item_i(  carr_t* arr, uint64_t i             );
ccoeff_t carr_get_item_ij( carr_t* arr, uint64_t i, uint64_t j );

void carr_get_item_ij_to( carr_t* arr, uint64_t i, uint64_t j, ccoeff_t* res );
void carr_get_item_i_to(  carr_t* arr, uint64_t i,             ccoeff_t* res );
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Get slice of a  fedarr object.

@param[in]    val    Value to set in res array.
@param[in]    starti Starting row index.
@param[in]    stopi  Final row index.
@param[in]    stepi  Row step.
@param[in]    startj Starting column index.
@param[in]    stopj  Final column index.
@param[in]    stepj  Column step.
@param[inout] res    Address of the result holder
******************************************************************************************************/ 
carr_t carr_get_slice(    carr_t* arr, 
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj  );
void   carr_get_slice_to( carr_t* arr, 
                          int64_t starti, int64_t stopi, int64_t stepi,
                          int64_t startj, int64_t stopj, int64_t stepj,
                          carr_t* res);
// ----------------------------------------------------------------------------------------------------



/**************************************************************************************************//**
@brief Set an item at position i,j in p_array. To be called only when p_array has already been created
and has some correct values in it.

ARR[i,j] = num

@param[in] num: Value to be set.
@param[in] i: Row
@param[in] j: Column
@param[inout] arr: Array to be set.
******************************************************************************************************/ 
void carr_set_item_i(    ccoeff_t num, uint64_t i,             carr_t* arr );
void carr_set_item_i_r(  ccoeff_t num, uint64_t i,             carr_t* arr );
void carr_set_item_ij(   ccoeff_t num, uint64_t i, uint64_t j, carr_t* arr );
void carr_set_item_ij_r( ccoeff_t num, uint64_t i, uint64_t j, carr_t* arr );
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Copy memory in array, if necessary, reallocate.

RES = ARR

@param[in] arr: Array.
@param[in] res: Array.
******************************************************************************************************/ 
carr_t carr_copy(    carr_t* arr              );
void   carr_copy_to( carr_t* src, carr_t* dst );
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Returns the size of the given array.

@param[in] arr: Array.
******************************************************************************************************/ 
uint64_t carr_getSize(carr_t* arr);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief C-level memory allocation of a real array setting all values to 1.

@param[inout] arr: Address of the array.
@param[in] shapex: Number of elements in the first  dimension.
@param[in] shapey: Number of elements in the second dimension.
******************************************************************************************************/ 
carr_t carr_ones( uint64_t nrows, uint64_t ncols);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief C-level memory allocation of a real array setting all values to 0.

@param[inout] p_array: Address of the array.
@param[in] shapex: Number of elements in the first  dimension.
@param[in] shapey: Number of elements in the second dimension.
******************************************************************************************************/ 
carr_t carr_zeros( uint64_t nrows, uint64_t ncols);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief C-level memory allocation of a real array creating an identity matrix.

@param[inout] p_array: Address of the array.
@param[in] size: Number of elements.
******************************************************************************************************/ 
carr_t carr_eye( uint64_t size);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Free all memory associated with the array.

@param[inout] arr: Address of the array.
******************************************************************************************************/ 
void carr_free(carr_t* arr);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief C-level memory allocation of array.

@param[in] shapex: Number of elements in the first  dimension.
@param[in] shapey: Number of elements in the second dimension.
******************************************************************************************************/ 
carr_t carr_createEmpty( uint64_t nrows, uint64_t ncols);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief C-level initialization of a carr_t variable.

******************************************************************************************************/ 
carr_t carr_init( void );
// ----------------------------------------------------------------------------------------------------



#endif