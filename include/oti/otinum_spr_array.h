// otilib.c
#ifndef OTI_SPR_ARRAY_H
#define OTI_SPR_ARRAY_H
// ----------------------------------------------------------------------------------------------------
// ---------------------------------     EXTERNAL LIBRARIES     ---------------------------------------
// ----------------------------------------------------------------------------------------------------
#include "oti/darray.h"
#include "oti/otinum_spr.h"

// ----------------------------------------------------------------------------------------------------
// --------------------------------    END EXTERNAL LIBRARIES     -------------------------------------
// ----------------------------------------------------------------------------------------------------

typedef struct{
    sotinum_t*    p_data; ///< Data array
    uint64_t       nrows; ///< Number of rows.
    uint64_t       ncols; ///< Number of cols.
    uint64_t        size; ///< Total size of the array.
    ord_t          order; ///< Truncation order.
} soarr_t;

// typedef struct {
//     coeff_t          re; ///< Real coefficient.
//     coeff_t**      p_im; ///< Array with all imaginary coefficients per order.
//     imdir_t**     p_idx; ///< Directions associated to each coefficient per order.
//     ndir_t*       p_nnz; ///< Number of non zero coefficients per order.
//     ndir_t*      p_size; ///< Allocated size per order.
//     ord_t         order; ///< Truncation order of the number.
// } sotinum_t;             ///< Sparse OTI number type


// typedef struct{
//     arrcoeff_t        re;
//     arrcoeff_t**    p_im;
//     imdir_t**      p_idx;
//     ndir_t*        p_nnz;
//     ndir_t*       p_size;
//     uint64_t       nrows; ///< Number of rows.
//     uint64_t       ncols; ///< Number of cols.
//     uint64_t        size; ///< Total size of the array.
//     ord_t          order; ///< Truncation order.
// } soarr_t;


// ----------------------------------------------------------------------------------------------------
// -------------------------------------    END STRUCTURES      ---------------------------------------
// ----------------------------------------------------------------------------------------------------


// ----------------------------------------------------------------------------------------------------
// ------------------------------------     DECLARATIONS     ------------------------------------------
// ----------------------------------------------------------------------------------------------------




/**************************************************************************************************//**
@brief Inverse of a sparse OTI array. The inverse is only computed for small matrices of size up to 3x3.

@param[in] p_arr1: soarr.
@param[inout] p_arrRes: Address of the result.
@param[in] dhl: Direction helper list.
******************************************************************************************************/
void soarr_invert(soarr_t* p_arr1, soarr_t* p_arrRes, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Determinant of a sparse OTI array.

@param[in] p_arr1: sparse OTI array.
@param[inout] p_arrRes: Address of the result.
@param[in] dhl: Direction helper list.
******************************************************************************************************/
void soarr_det(soarr_t* p_arr1, sotinum_t* p_res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Transpose a sparse OTI array.

@param[in] p_arr1: sparse OTI array.
@param[inout] p_arrRes: Address of the result.
@param[in] dhl: Direction helper list.
******************************************************************************************************/
void soarr_transpose(soarr_t* p_arr1, soarr_t* p_arrRes, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------


/**************************************************************************************************//**
@brief Negate a sparse OTI array.

@param[in] p_arr1: sparse OTI array.
@param[inout] p_arrRes: Address of the result.
@param[in] dhl: Direction helper list.
******************************************************************************************************/
void soarr_neg(soarr_t* p_arr1, soarr_t* p_arrRes, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------





/**************************************************************************************************//**
@brief Subtract a Real array by a sparse OTI array.

@param[in] p_arr1: sparse OTI array.
@param[in] p_arr2: Real array.
@param[inout] p_arrRes: Address of the result.
@param[in] dhl: Direction helper list.
******************************************************************************************************/
void soarr_matsub_Roti(soarr_t* p_arr1, darray_t* p_arr2, 
                           soarr_t* p_arrRes, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Subtract a sparse OTI array by a real array.

@param[in] p_arr1: sparse OTI array.
@param[in] p_arr2: Real array.
@param[inout] p_arrRes: Address of the result.
@param[in] dhl: Direction helper list.
******************************************************************************************************/
void soarr_matsub_otiR(soarr_t* p_arr1, darray_t* p_arr2,
                           soarr_t* p_arrRes, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Subtract two soarrs.

@param[in] p_arr1: sparse OTI array.
@param[in] p_arr2 sparse OTI array.
@param[inout] p_arrRes: Address of the result.
@param[in] dhl: Direction helper list.
******************************************************************************************************/
void soarr_matsub_otioti(soarr_t* p_arr1, soarr_t* p_arr2, 
                             soarr_t* p_arrRes, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------


/**************************************************************************************************//**
@brief Multiply a sparse OTI array with a real array.

@param[in] p_arr1: sparse OTI array.
@param[in] p_arr2: real array.
@param[inout] p_arrRes: Address of the result.
@param[in] dhl: Direction helper list.
******************************************************************************************************/
void soarr_matmul_otiR(soarr_t* p_arr1, darray_t* p_arr2, 
                           soarr_t* p_arrRes, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Multiply a real array times a sparse OTI array.

@param[in] p_arr1: real array.
@param[in] p_arr2: sparse OTI array.
@param[inout] p_arrRes: Address of the result.
@param[in] dhl: Direction helper list.
******************************************************************************************************/
void soarr_matmul_Roti(darray_t* p_arr1, soarr_t* p_arr2, 
                           soarr_t* p_arrRes, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Multiply two soarrs.

@param[in] p_arr1: sparse OTI array.
@param[in] p_arr2: sparse OTI array.
@param[inout] p_arrRes: Address of the result.
@param[in] dhl: Direction helper list.
******************************************************************************************************/
void soarr_matmul_otioti(soarr_t* p_arr1, soarr_t* p_arr2, 
                             soarr_t* p_arrRes, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Add a sparse OTI array with a real array.

@param[in] p_arr1: sparse OTI array.
@param[in] p_arr2: real array.
@param[inout] p_arrRes: Address of the result.
@param[in] dhl: Direction helper list.
******************************************************************************************************/
void soarr_matsum_otiR(soarr_t* p_arr1, darray_t* p_arr2, soarr_t* p_arrRes);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Add two sparse OTI array elements

@param[in] p_arr1: sparse OTI array.
@param[in] p_arr2: sparse OTI array.
@param[inout] p_arrRes: Address of the result.
@param[in] dhl: Direction helper list.
******************************************************************************************************/
void soarr_matsum_otioti(soarr_t* p_arr1, soarr_t* p_arr2, 
                             soarr_t* p_arrRes, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

















/**************************************************************************************************//**
@brief Elementise multiplication of a sparse OTI array by another sparse OTI array.

@param[in] p_arr1: sparse OTI array.
@param[in] p_arr2: sparse OTI array.
@param[inout] p_arrRes: Address of the result.
@param[in] dhl: Direction helper list.
******************************************************************************************************/
void soarr_mul_sotiarr(soarr_t* p_arr1, soarr_t* p_arr2,
                           soarr_t* p_arrRes, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------





/**************************************************************************************************//**
@brief Elementise division of a sparse OTI array by another sparse OTI array.

@param[in] p_arr1: sparse OTI array.
@param[in] p_arr2: sparse OTI array.
@param[inout] p_arrRes: Address of the result.
@param[in] dhl: Direction helper list.
******************************************************************************************************/
void soarr_matdiv_otioti(soarr_t* p_arr1, soarr_t* p_arr2,
                             soarr_t* p_arrRes, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------


/**************************************************************************************************//**
@brief Divide a sparse OTI array by a real number.

@param[in] p_arr1: sparse OTI array.
@param[in] num2: Real number.
@param[inout] p_arrRes: Address of the result.
@param[in] dhl: Direction helper list.
******************************************************************************************************/
void soarr_div_R(soarr_t* p_arr1, coeff_t num2, soarr_t* p_arrRes, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------




/**************************************************************************************************//**
@brief Divide a sparse OTI array by an OTI number.

@param[in] p_arr1: sparse OTI array.
@param[in] num2: OTI number.
@param[inout] p_arrRes: Address of the result.
@param[in] dhl: Direction helper list.
******************************************************************************************************/
void soarr_div_oti(soarr_t* p_arr1, sotinum_t* num2,
                       soarr_t* p_arrRes, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Divide an OTI number every element of a sparse OTI array.

@param[in] p_arr1: sparse OTI array.
@param[in] num2: OTI number.
@param[inout] p_arrRes: Address of the result.
@param[in] dhl: Direction helper list.
******************************************************************************************************/
void soarr_oti_div(soarr_t* p_arr1, sotinum_t* num2,
                       soarr_t* p_arrRes, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Divide real number by a sparse OTI array (elementwise.

@param[in] p_arr1: sparse OTI array.
@param[in] num2: Real number.
@param[inout] p_arrRes: Address of the result.
@param[in] dhl: Direction helper list.
******************************************************************************************************/
void soarr_R_div(soarr_t* p_arr1, coeff_t num2, 
                     soarr_t* p_arrRes, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------


/**************************************************************************************************//**
@brief Subtract an OTI number by a sparse OTI array.

@param[in] p_arr1: sparse OTI array.
@param[in] num2: OTI number.
@param[inout] p_arrRes: Address of the result.
@param[in] dhl: Direction helper list.
******************************************************************************************************/
void soarr_oti_sub(soarr_t* p_arr1, sotinum_t* num2, 
                       soarr_t* p_arrRes, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Subtract real number by a sparse OTI array.

@param[in] p_arr1: sparse OTI array.
@param[in] num2: real number.
@param[inout] p_arrRes: Address of the result.
@param[in] dhl: Direction helper list.
******************************************************************************************************/
void soarr_R_sub(soarr_t* p_arr1, coeff_t num2, 
                     soarr_t* p_arrRes, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Subtract a sparse OTI array by a sotinum.

@param[in] p_arr1: sparse OTI array.
@param[in] num2: OTI number.
@param[inout] p_arrRes: Address of the result.
@param[in] dhl: Direction helper list.
******************************************************************************************************/
void soarr_sub_oti(soarr_t* p_arr1, sotinum_t* num2,
                       soarr_t* p_arrRes, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Subtract a sparse OTI array by a real number.

@param[in] p_arr1: sparse OTI array.
@param[in] num2: Real number.
@param[inout] p_arrRes: Address of the result.
@param[in] dhl: Direction helper list.
******************************************************************************************************/
void soarr_sub_R(soarr_t* p_arr1, coeff_t num2,
                     soarr_t* p_arrRe, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Multiply a sparse OTI array by a sotinum.

@param[in] p_arr1: sparse OTI array.
@param[in] num2: OTI number.
@param[inout] p_arrRes: Address of the result.
@param[in] dhl: Direction helper list.
******************************************************************************************************/
void soarr_mul_oti(soarr_t* p_arr1, sotinum_t* num2,
                       soarr_t* p_arrRes, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Multiply a sparse OTI array by a real number.

@param[in] p_arr1: sparse OTI array.
@param[in] num2: real number.
@param[inout] p_arrRes: Address of the result.
@param[in] dhl: Direction helper list.
******************************************************************************************************/
void soarr_mul_R(soarr_t* p_arr1, coeff_t num2, soarr_t* p_arrRes);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Add a sparse OTI array by a sotinum.

@param[in] p_arr1: sparse OTI array.
@param[in] num2: OTI number.
@param[inout] p_arrRes: Address of the result.
@param[in] dhl: Direction helper list.
******************************************************************************************************/
void soarr_sum_oti(soarr_t* p_arr1, sotinum_t* num2, 
                       soarr_t* p_arrRes, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Add a sparse OTI array by a real number.

@param[in] p_arr1: sparse OTI array.
@param[in] num2: real number.
@param[inout] p_arrRes: Address of the result.
@param[in] dhl: Direction helper list.
******************************************************************************************************/
void soarr_sum_R(soarr_t* p_arr1, coeff_t num2, soarr_t* p_arrRes, dhelpl_t dhl); 
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Get element from a sparse OTI array

@param[in] p_array: Address of the array.
@param[in] i: row
@param[in] j: column
@param[inout] num: sotinum with the result.
@param[in] dhl: Direction helper list.
******************************************************************************************************/
void soarr_getItem(soarr_t* p_array, uint64_t i, uint64_t j, sotinum_t* num, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Set an item at position i in p_array from a real number.

@param[in] num: Real number.
@param[in] i: row
@param[in] j: column
@param[inout] p_array: Address of the array.
@param[in] dhl: Direction helper list.
******************************************************************************************************/ 
void soarr_setItemR_indx( coeff_t num, uint64_t i, soarr_t* p_array, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Set an item at position i in p_array. 

@param[in] num: OTI number.
@param[in] i: Global index of the item to be set.
@param[inout] p_array: Address of the array.
@param[in] dhl: Direction helper list.
******************************************************************************************************/ 
void soarr_setItemOTI_indx( sotinum_t* num, uint64_t i, soarr_t* p_array, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Set an item at position i,j in p_array from a real number. To be called only when p_array has 
already been created and has some correct values in it. 

@param[in] num: Real number.
@param[in] i: row
@param[in] j: column
@param[inout] p_array: Address of the array.
@param[in] dhl: Direction helper list.
******************************************************************************************************/ 
void soarr_setItemR( coeff_t num, uint64_t i, uint64_t j, soarr_t* p_array, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Sets all items in a soarr to the specified number.

@param[in] num: 
@param[inout] p_array: Address of the array.
@param[in] dhl: Direction helper list.
******************************************************************************************************/ 
void soarr_setAllItems( sotinum_t* num, soarr_t* p_array, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Set an item at position i,j in p_array. To be called only when p_array has already been created
and has some correct values in it. 

@param[in] num: OTI number.
@param[in] i: row
@param[in] j: column
@param[inout] p_array: Address of the array.
@param[in] dhl: Direction helper list.
******************************************************************************************************/ 
void soarr_setItemOTI( sotinum_t* num, uint64_t i, uint64_t j, 
                           soarr_t* p_array, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Allocate memory to create an soarr object with all elements equal to zero. 

@param[inout] p_array: Address of the array.
@param[in] shapex: Number of rows
@param[in] shapey: Number of columns
@param[in] order: Truncation order
@param[in] dhl: Direction helper list.
******************************************************************************************************/ 
void soarr_zeros(soarr_t* p_array, uint64_t shapex, uint64_t shapey, 
                     ord_t order, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Free memory of object. 

@param[inout] p_array: Address of the array.
@param[in] dhl: Direction helper list.
******************************************************************************************************/ 
void soarr_free(soarr_t* p_array, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Allocate memory to create an soarr object. 

@param[inout] p_array: Address of the array.
@param[in] shapex: Number of rows
@param[in] shapey: Number of columns
@param[in] order: Truncation order
@param[in] dhl: Direction helper list.
******************************************************************************************************/ 
void soarr_createEmpty(soarr_t* p_array, uint64_t shapex, uint64_t shapey, 
                           ord_t order, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

// ----------------------------------------------------------------------------------------------------
// ----------------------------------     END DECLARATIONS     ----------------------------------------
// ----------------------------------------------------------------------------------------------------

#endif