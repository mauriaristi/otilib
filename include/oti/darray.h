#ifndef DARRAY_H
#define DARRAY_H
// ----------------------------------------------------------------------------------------------------
// ---------------------------------     EXTERNAL LIBRARIES     ---------------------------------------
// ----------------------------------------------------------------------------------------------------
#include "oti/core.h" // Requires error codes, stdlib.h and string libraries.
#include <stdlib.h>
#include <string.h>
// ----------------------------------------------------------------------------------------------------
// --------------------------------    END EXTERNAL LIBRARIES     -------------------------------------
// ----------------------------------------------------------------------------------------------------

typedef struct{
    double*       p_data; // Data array
    uint64_t       nrows; // Number of rows.
    uint64_t       ncols; // Number of cols.
    uint64_t        size; // Total size of the array.
} darray_t;


// ----------------------------------------------------------------------------------------------------
// -------------------------------------    END STRUCTURES      ---------------------------------------
// ----------------------------------------------------------------------------------------------------


// ----------------------------------------------------------------------------------------------------
// ------------------------------------     DECLARATIONS     ------------------------------------------
// ----------------------------------------------------------------------------------------------------



/**************************************************************************************************//**
@brief Broadcasted subtraction of a scalar by an array. 

@param[in] p_arr1: Address of the array.
@param[in] num: scalar
@param[inout] p_arrres: Resulting array.
******************************************************************************************************/ 
void darray_r_sub(darray_t* p_arr1, double num, darray_t* p_arrres);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Negate an array. 

@param[in]      p_arr1: Address of the array.
@param[inout] p_arrres: Resulting array.
******************************************************************************************************/
void darray_neg(darray_t* p_arr1, darray_t* p_arrres);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Broadcasted multiplication of a scalar by an array. 

@param[in] p_arr1: Address of the array.
@param[in] num: Scalar
@param[inout] p_arrres: Resulting array.
******************************************************************************************************/
void darray_mul_r(darray_t* p_arr1, double num, darray_t* p_arrres);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Broadcasted subtraction of an array by a scalar. 

@param[in] p_arr1: Address of the array.
@param[in] num: Scalar.
@param[inout] p_arrres: Resulting array.
******************************************************************************************************/
void darray_sub_r(darray_t* p_arr1, double num, darray_t* p_arrres);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Broadcasted addition of an array by a scalar. 

@param[in] p_arr1: Address of the array.
@param[in] num: Scalar.
@param[inout] p_arrres: Resulting array.
******************************************************************************************************/
void darray_sum_r(darray_t* p_arr1, double num, darray_t* p_arrres);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Elementwise division of arrays. Must have same dimensions. 

@param[in] p_arr1: Address of the array 1.
@param[in] p_arr2: Address of the array 2.
@param[inout] p_arrres: Resulting array.
******************************************************************************************************/
void darray_div(darray_t* p_arr1, darray_t* p_arr2, darray_t* p_arrres);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Elementwise multiplication of arrays. Must have same dimensions. 

@param[in] p_arr1: Address of the array 1.
@param[in] p_arr2: Address of the array 2.
@param[inout] p_arrres: Resulting array.
******************************************************************************************************/
void darray_mul(darray_t* p_arr1, darray_t* p_arr2, darray_t* p_arrres);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Elementwise subtraction of arrays. Must have same dimensions. 

@param[in] p_arr1: Address of the array 1.
@param[in] p_arr2: Address of the array 2.
@param[inout] p_arrres: Resulting array.
******************************************************************************************************/
void darray_sub(darray_t* p_arr1, darray_t* p_arr2, darray_t* p_arrres);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Elementwise addition of arrays. Must have same dimensions. 

@param[in] p_arr1: Address of the array 1.
@param[in] p_arr2: Address of the array 2.
@param[inout] p_arrres: Resulting array.
******************************************************************************************************/
void darray_sum(darray_t* p_arr1, darray_t* p_arr2, darray_t* p_arrres);
// ----------------------------------------------------------------------------------------------------











/**************************************************************************************************//**
@brief Get element at position i,j in p_array. 

@param[inout] p_array: Address of the array.
@param[in] i: Row
@param[in] j: Column
@param[in] shapey: Number of elements in the second dimension.
******************************************************************************************************/ 
void darray_getItem(darray_t* p_array, uint64_t i, uint64_t j, coeff_t* num); 
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Set an item at position i,j in p_array. To be called only when p_array has already been created
and has some correct values in it.

@param[in] num: Value to be set.
@param[in] i: Row
@param[in] j: Column
@param[inout] p_array: Address of the array.
******************************************************************************************************/ 
void darray_setItem( coeff_t num, uint64_t i, uint64_t j, darray_t* p_array);
// ----------------------------------------------------------------------------------------------------


/**************************************************************************************************//**
@brief C-level memory allocation of a real array setting all values to 1.

@param[inout] p_array: Address of the array.
@param[in] shapex: Number of elements in the first  dimension.
@param[in] shapey: Number of elements in the second dimension.
******************************************************************************************************/ 
int64_t darray_ones(darray_t* p_array, uint64_t nrows, uint64_t ncols);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief C-level memory allocation of a real array setting all values to 0.

@param[inout] p_array: Address of the array.
@param[in] shapex: Number of elements in the first  dimension.
@param[in] shapey: Number of elements in the second dimension.
******************************************************************************************************/ 
int64_t darray_zeros(darray_t* p_array, uint64_t nrows, uint64_t ncols);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Free all memory associated with the array.

@param[inout] p_array: Address of the array.
******************************************************************************************************/ 
void darray_free(darray_t* p_array);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief C-level memory allocation of array.

@param[inout] p_array: Address of the array to be allocated.
@param[in] shapex: Number of elements in the first  dimension.
@param[in] shapey: Number of elements in the second dimension.
******************************************************************************************************/ 
int64_t darray_createEmpty(darray_t* p_array, uint64_t nrows, uint64_t ncols);
// ----------------------------------------------------------------------------------------------------

// ----------------------------------------------------------------------------------------------------
// ----------------------------------     END DECLARATIONS     ----------------------------------------
// ----------------------------------------------------------------------------------------------------

#endif