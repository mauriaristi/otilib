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
} sotiarray_t;

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
// } sotiarray_t;


// ----------------------------------------------------------------------------------------------------
// -------------------------------------    END STRUCTURES      ---------------------------------------
// ----------------------------------------------------------------------------------------------------


// ----------------------------------------------------------------------------------------------------
// ------------------------------------     DECLARATIONS     ------------------------------------------
// ----------------------------------------------------------------------------------------------------




/**************************************************************************************************//**
@brief Inverse of a sotiarray. The inverse is only computed for small matrices of size up to 3x3.

@param[in] p_arr1: sotiarray.
@param[inout] p_arrRes: Address of the result.
@param[in] dhl: Direction helper list.
******************************************************************************************************/
void sotiarray_invert(sotiarray_t* p_arr1, sotiarray_t* p_arrRes, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Determinant of a sotiarray.

@param[in] p_arr1: sotiarray.
@param[inout] p_arrRes: Address of the result.
@param[in] dhl: Direction helper list.
******************************************************************************************************/
void sotiarray_det(sotiarray_t* p_arr1, sotinum_t* p_res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Transpose a sotiarray.

@param[in] p_arr1: sotiarray.
@param[inout] p_arrRes: Address of the result.
@param[in] dhl: Direction helper list.
******************************************************************************************************/
void sotiarray_transpose(sotiarray_t* p_arr1, sotiarray_t* p_arrRes, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------


/**************************************************************************************************//**
@brief Negate a sotiarray.

@param[in] p_arr1: sotiarray.
@param[inout] p_arrRes: Address of the result.
@param[in] dhl: Direction helper list.
******************************************************************************************************/
void sotiarray_neg(sotiarray_t* p_arr1, sotiarray_t* p_arrRes, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------





/**************************************************************************************************//**
@brief Subtract a Real array by a sotiarray.

@param[in] p_arr1: sotiarray.
@param[in] p_arr2: Real array.
@param[inout] p_arrRes: Address of the result.
@param[in] dhl: Direction helper list.
******************************************************************************************************/
void sotiarray_matsub_Roti(sotiarray_t* p_arr1, darray_t* p_arr2, 
                           sotiarray_t* p_arrRes, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Subtract a sotiarray by a real array.

@param[in] p_arr1: sotiarray.
@param[in] p_arr2: Real array.
@param[inout] p_arrRes: Address of the result.
@param[in] dhl: Direction helper list.
******************************************************************************************************/
void sotiarray_matsub_otiR(sotiarray_t* p_arr1, darray_t* p_arr2,
                           sotiarray_t* p_arrRes, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Subtract two sotiarrays.

@param[in] p_arr1: sotiarray.
@param[in] p_arr2 sotiarray.
@param[inout] p_arrRes: Address of the result.
@param[in] dhl: Direction helper list.
******************************************************************************************************/
void sotiarray_matsub_otioti(sotiarray_t* p_arr1, sotiarray_t* p_arr2, 
                             sotiarray_t* p_arrRes, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------


/**************************************************************************************************//**
@brief Multiply a sotiarray with a real array.

@param[in] p_arr1: sotiarray.
@param[in] p_arr2: real array.
@param[inout] p_arrRes: Address of the result.
@param[in] dhl: Direction helper list.
******************************************************************************************************/
void sotiarray_matmul_otiR(sotiarray_t* p_arr1, darray_t* p_arr2, 
                           sotiarray_t* p_arrRes, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Multiply a real array times a sotiarray.

@param[in] p_arr1: real array.
@param[in] p_arr2: sotiarray.
@param[inout] p_arrRes: Address of the result.
@param[in] dhl: Direction helper list.
******************************************************************************************************/
void sotiarray_matmul_Roti(darray_t* p_arr1, sotiarray_t* p_arr2, 
                           sotiarray_t* p_arrRes, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Multiply two sotiarrays.

@param[in] p_arr1: sotiarray.
@param[in] p_arr2: sotiarray.
@param[inout] p_arrRes: Address of the result.
@param[in] dhl: Direction helper list.
******************************************************************************************************/
void sotiarray_matmul_otioti(sotiarray_t* p_arr1, sotiarray_t* p_arr2, 
                             sotiarray_t* p_arrRes, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Add a sotiarray with a real array.

@param[in] p_arr1: sotiarray.
@param[in] p_arr2: real array.
@param[inout] p_arrRes: Address of the result.
@param[in] dhl: Direction helper list.
******************************************************************************************************/
void sotiarray_matsum_otiR(sotiarray_t* p_arr1, darray_t* p_arr2, sotiarray_t* p_arrRes);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Add two sotiarray elements

@param[in] p_arr1: sotiarray.
@param[in] p_arr2: sotiarray.
@param[inout] p_arrRes: Address of the result.
@param[in] dhl: Direction helper list.
******************************************************************************************************/
void sotiarray_matsum_otioti(sotiarray_t* p_arr1, sotiarray_t* p_arr2, 
                             sotiarray_t* p_arrRes, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

















/**************************************************************************************************//**
@brief Elementise multiplication of a sotiarray by another sotiarray.

@param[in] p_arr1: sotiarray.
@param[in] p_arr2: sotiarray.
@param[inout] p_arrRes: Address of the result.
@param[in] dhl: Direction helper list.
******************************************************************************************************/
void sotiarray_mul_sotiarr(sotiarray_t* p_arr1, sotiarray_t* p_arr2,
                           sotiarray_t* p_arrRes, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------





/**************************************************************************************************//**
@brief Elementise division of a sotiarray by another sotiarray.

@param[in] p_arr1: sotiarray.
@param[in] p_arr2: sotiarray.
@param[inout] p_arrRes: Address of the result.
@param[in] dhl: Direction helper list.
******************************************************************************************************/
void sotiarray_matdiv_otioti(sotiarray_t* p_arr1, sotiarray_t* p_arr2,
                             sotiarray_t* p_arrRes, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------


/**************************************************************************************************//**
@brief Divide a sotiarray by a real number.

@param[in] p_arr1: sotiarray.
@param[in] num2: Real number.
@param[inout] p_arrRes: Address of the result.
@param[in] dhl: Direction helper list.
******************************************************************************************************/
void sotiarray_div_R(sotiarray_t* p_arr1, coeff_t num2, sotiarray_t* p_arrRes, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------




/**************************************************************************************************//**
@brief Divide a sotiarray by an OTI number.

@param[in] p_arr1: sotiarray.
@param[in] num2: OTI number.
@param[inout] p_arrRes: Address of the result.
@param[in] dhl: Direction helper list.
******************************************************************************************************/
void sotiarray_div_oti(sotiarray_t* p_arr1, sotinum_t* num2,
                       sotiarray_t* p_arrRes, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Divide an OTI number every element of a sotiarray.

@param[in] p_arr1: sotiarray.
@param[in] num2: OTI number.
@param[inout] p_arrRes: Address of the result.
@param[in] dhl: Direction helper list.
******************************************************************************************************/
void sotiarray_oti_div(sotiarray_t* p_arr1, sotinum_t* num2,
                       sotiarray_t* p_arrRes, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Divide real number by a sotiarray (elementwise.

@param[in] p_arr1: sotiarray.
@param[in] num2: Real number.
@param[inout] p_arrRes: Address of the result.
@param[in] dhl: Direction helper list.
******************************************************************************************************/
void sotiarray_R_div(sotiarray_t* p_arr1, coeff_t num2, 
                     sotiarray_t* p_arrRes, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------


/**************************************************************************************************//**
@brief Subtract an OTI number by a sotiarray.

@param[in] p_arr1: sotiarray.
@param[in] num2: OTI number.
@param[inout] p_arrRes: Address of the result.
@param[in] dhl: Direction helper list.
******************************************************************************************************/
void sotiarray_oti_sub(sotiarray_t* p_arr1, sotinum_t* num2, 
                       sotiarray_t* p_arrRes, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Subtract real number by a sotiarray.

@param[in] p_arr1: sotiarray.
@param[in] num2: real number.
@param[inout] p_arrRes: Address of the result.
@param[in] dhl: Direction helper list.
******************************************************************************************************/
void sotiarray_R_sub(sotiarray_t* p_arr1, coeff_t num2, 
                     sotiarray_t* p_arrRes, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Subtract a sotiarray by a sotinum.

@param[in] p_arr1: sotiarray.
@param[in] num2: OTI number.
@param[inout] p_arrRes: Address of the result.
@param[in] dhl: Direction helper list.
******************************************************************************************************/
void sotiarray_sub_oti(sotiarray_t* p_arr1, sotinum_t* num2,
                       sotiarray_t* p_arrRes, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Subtract a sotiarray by a real number.

@param[in] p_arr1: sotiarray.
@param[in] num2: Real number.
@param[inout] p_arrRes: Address of the result.
@param[in] dhl: Direction helper list.
******************************************************************************************************/
void sotiarray_sub_R(sotiarray_t* p_arr1, coeff_t num2,
                     sotiarray_t* p_arrRe, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Multiply a sotiarray by a sotinum.

@param[in] p_arr1: sotiarray.
@param[in] num2: OTI number.
@param[inout] p_arrRes: Address of the result.
@param[in] dhl: Direction helper list.
******************************************************************************************************/
void sotiarray_mul_oti(sotiarray_t* p_arr1, sotinum_t* num2,
                       sotiarray_t* p_arrRes, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Multiply a sotiarray by a real number.

@param[in] p_arr1: sotiarray.
@param[in] num2: real number.
@param[inout] p_arrRes: Address of the result.
@param[in] dhl: Direction helper list.
******************************************************************************************************/
void sotiarray_mul_R(sotiarray_t* p_arr1, coeff_t num2, sotiarray_t* p_arrRes);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Add a sotiarray by a sotinum.

@param[in] p_arr1: sotiarray.
@param[in] num2: OTI number.
@param[inout] p_arrRes: Address of the result.
@param[in] dhl: Direction helper list.
******************************************************************************************************/
void sotiarray_sum_oti(sotiarray_t* p_arr1, sotinum_t* num2, 
                       sotiarray_t* p_arrRes, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Add a sotiarray by a real number.

@param[in] p_arr1: sotiarray.
@param[in] num2: real number.
@param[inout] p_arrRes: Address of the result.
@param[in] dhl: Direction helper list.
******************************************************************************************************/
void sotiarray_sum_R(sotiarray_t* p_arr1, coeff_t num2, sotiarray_t* p_arrRes, dhelpl_t dhl); 
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Get element from sotiarray

@param[in] p_array: Address of the array.
@param[in] i: row
@param[in] j: column
@param[inout] num: sotinum with the result.
@param[in] dhl: Direction helper list.
******************************************************************************************************/
void sotiarray_getItem(sotiarray_t* p_array, uint64_t i, uint64_t j, sotinum_t* num, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Set an item at position i in p_array from a real number.

@param[in] num: Real number.
@param[in] i: row
@param[in] j: column
@param[inout] p_array: Address of the array.
@param[in] dhl: Direction helper list.
******************************************************************************************************/ 
void sotiarray_setItemR_indx( coeff_t num, uint64_t i, sotiarray_t* p_array, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Set an item at position i in p_array. 

@param[in] num: OTI number.
@param[in] i: Global index of the item to be set.
@param[inout] p_array: Address of the array.
@param[in] dhl: Direction helper list.
******************************************************************************************************/ 
void sotiarray_setItemOTI_indx( sotinum_t* num, uint64_t i, sotiarray_t* p_array, dhelpl_t dhl);
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
void sotiarray_setItemR( coeff_t num, uint64_t i, uint64_t j, sotiarray_t* p_array, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Sets all items in a sotiarray to the specified number.

@param[in] num: 
@param[inout] p_array: Address of the array.
@param[in] dhl: Direction helper list.
******************************************************************************************************/ 
void sotiarray_setAllItems( sotinum_t* num, sotiarray_t* p_array, dhelpl_t dhl);
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
void sotiarray_setItemOTI( sotinum_t* num, uint64_t i, uint64_t j, 
                           sotiarray_t* p_array, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Allocate memory to create an sotiarray object with all elements equal to zero. 

@param[inout] p_array: Address of the array.
@param[in] shapex: Number of rows
@param[in] shapey: Number of columns
@param[in] order: Truncation order
@param[in] dhl: Direction helper list.
******************************************************************************************************/ 
void sotiarray_zeros(sotiarray_t* p_array, uint64_t shapex, uint64_t shapey, 
                     ord_t order, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Free memory of object. 

@param[inout] p_array: Address of the array.
@param[in] dhl: Direction helper list.
******************************************************************************************************/ 
void sotiarray_free(sotiarray_t* p_array, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Allocate memory to create an sotiarray object. 

@param[inout] p_array: Address of the array.
@param[in] shapex: Number of rows
@param[in] shapey: Number of columns
@param[in] order: Truncation order
@param[in] dhl: Direction helper list.
******************************************************************************************************/ 
void sotiarray_createEmpty(sotiarray_t* p_array, uint64_t shapex, uint64_t shapey, 
                           ord_t order, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

// ----------------------------------------------------------------------------------------------------
// ----------------------------------     END DECLARATIONS     ----------------------------------------
// ----------------------------------------------------------------------------------------------------

#endif