#ifndef OTI_REAL_BASE_H
#define OTI_REAL_BASE_H


/**************************************************************************************************//**
@brief Set all elements in array as num.

ARR[:,:] = num

@param[in] num: Scalar to set.
@param[in] arr: Array to be set..
******************************************************************************************************/ 
void darr_set_all( coeff_t num, darr_t* arr);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Get element at position i,j in p_array. 

res = ARR[i,j]

@param[inout] arr: Address of the array.
@param[in] i: Row
@param[in] j: Column
@param[in] shapey: Number of elements in the second dimension.
******************************************************************************************************/ 
coeff_t darr_get_item_i(  darr_t* arr, uint64_t i             );
coeff_t darr_get_item_ij( darr_t* arr, uint64_t i, uint64_t j );
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
void darr_set_item_i(  coeff_t num, uint64_t i,             darr_t* arr );
void darr_set_item_ij( coeff_t num, uint64_t i, uint64_t j, darr_t* arr );
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Copy memory in array, if necessary, reallocate.

RES = ARR

@param[in] arr: Array.
@param[in] res: Array.
******************************************************************************************************/ 
darr_t darr_copy(  darr_t* arr );

void   darr_copy_to(darr_t* src, darr_t* dst );
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Returns the size of the given array.

@param[in] arr: Array.
******************************************************************************************************/ 
uint64_t darr_getSize(darr_t* arr);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief C-level memory allocation of a real array setting all values to 1.

@param[inout] arr: Address of the array.
@param[in] shapex: Number of elements in the first  dimension.
@param[in] shapey: Number of elements in the second dimension.
******************************************************************************************************/ 
darr_t darr_ones( uint64_t nrows, uint64_t ncols);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief C-level memory allocation of a real array setting all values to 0.

@param[inout] p_array: Address of the array.
@param[in] shapex: Number of elements in the first  dimension.
@param[in] shapey: Number of elements in the second dimension.
******************************************************************************************************/ 
darr_t darr_zeros( uint64_t nrows, uint64_t ncols);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief C-level memory allocation of a real array creating an identity matrix.

@param[inout] p_array: Address of the array.
@param[in] size: Number of elements.
******************************************************************************************************/ 
darr_t darr_eye( uint64_t size);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Free all memory associated with the array.

@param[inout] arr: Address of the array.
******************************************************************************************************/ 
void darr_free(darr_t* arr);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief C-level memory allocation of array.

@param[in] shapex: Number of elements in the first  dimension.
@param[in] shapey: Number of elements in the second dimension.
******************************************************************************************************/ 
darr_t darr_createEmpty( uint64_t nrows, uint64_t ncols);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief C-level initialization of a darr_t variable.

******************************************************************************************************/ 
darr_t darr_init( void );
// ----------------------------------------------------------------------------------------------------



#endif