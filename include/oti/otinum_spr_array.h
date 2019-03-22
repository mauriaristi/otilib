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
    sotinum_t*    p_data; // Data array
    uint64_t       nrows; // Number of rows.
    uint64_t       ncols; // Number of cols.
    uint64_t        size; // Total size of the array.
    ord_t          order;
} sotiarray_t;

// ----------------------------------------------------------------------------------------------------
// -------------------------------------    END STRUCTURES      ---------------------------------------
// ----------------------------------------------------------------------------------------------------


// ----------------------------------------------------------------------------------------------------
// ------------------------------------     DECLARATIONS     ------------------------------------------
// ----------------------------------------------------------------------------------------------------


void sotiarray_setItemR_indx( coeff_t num, uint64_t i, sotiarray_t* p_array, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------


void sotiarray_setItemOTI_indx( sotinum_t* num, uint64_t i, sotiarray_t* p_array, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------


void sotiarray_oti_div(sotiarray_t* p_arr1, sotinum_t* num2,
                       sotiarray_t* p_arrRes, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------


void sotiarray_matdiv_otioti(sotiarray_t* p_arr1, sotiarray_t* p_arr2,
                             sotiarray_t* p_arrRes, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------


void sotiarray_div_R(sotiarray_t* p_arr1, coeff_t num2, sotiarray_t* p_arrRes, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------


void sotiarray_R_div(sotiarray_t* p_arr1, coeff_t num2, 
                     sotiarray_t* p_arrRes, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------


void sotiarray_div_oti(sotiarray_t* p_arr1, sotinum_t* num2,
                       sotiarray_t* p_arrRes, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------


void sotiarray_invert(sotiarray_t* p_arr1, sotiarray_t* p_arrRes, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------


void sotiarray_det(sotiarray_t* p_arr1, sotinum_t* p_res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------


void sotiarray_transpose(sotiarray_t* p_arr1, sotiarray_t* p_arrRes, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------


void sotiarray_mul_sotiarr(sotiarray_t* p_arr1, sotiarray_t* p_arr2,
                           sotiarray_t* p_arrRes, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------


void sotiarray_neg(sotiarray_t* p_arr1, sotiarray_t* p_arrRes, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------


void sotiarray_matsub_Roti(sotiarray_t* p_arr1, darray_t* p_arr2, 
                           sotiarray_t* p_arrRes, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------


void sotiarray_matsub_otiR(sotiarray_t* p_arr1, darray_t* p_arr2,
                           sotiarray_t* p_arrRes, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------


void sotiarray_matsub_otioti(sotiarray_t* p_arr1, sotiarray_t* p_arr2, 
                             sotiarray_t* p_arrRes, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------


void sotiarray_oti_sub(sotiarray_t* p_arr1, sotinum_t* num2, 
                       sotiarray_t* p_arrRes, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------


void sotiarray_R_sub(sotiarray_t* p_arr1, coeff_t num2, 
                     sotiarray_t* p_arrRes, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------


void sotiarray_sub_oti(sotiarray_t* p_arr1, sotinum_t* num2,
                       sotiarray_t* p_arrRes, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------


void sotiarray_sub_R(sotiarray_t* p_arr1, coeff_t num2,
                     sotiarray_t* p_arrRe, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------


void sotiarray_mul_oti(sotiarray_t* p_arr1, sotinum_t* num2,
                       sotiarray_t* p_arrRes, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------


void sotiarray_mul_R(sotiarray_t* p_arr1, coeff_t num2, sotiarray_t* p_arrRes);
// ----------------------------------------------------------------------------------------------------


void sotiarray_sum_oti(sotiarray_t* p_arr1, sotinum_t* num2, 
                       sotiarray_t* p_arrRes, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------


void sotiarray_sum_R(sotiarray_t* p_arr1, coeff_t num2, sotiarray_t* p_arrRes, dhelpl_t dhl); 
// ----------------------------------------------------------------------------------------------------


void sotiarray_matmul_otiR(sotiarray_t* p_arr1, darray_t* p_arr2, 
                           sotiarray_t* p_arrRes, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------


void sotiarray_matmul_Roti(darray_t* p_arr1, sotiarray_t* p_arr2, 
                           sotiarray_t* p_arrRes, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------


void sotiarray_matmul_otioti(sotiarray_t* p_arr1, sotiarray_t* p_arr2, 
                             sotiarray_t* p_arrRes, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------


void sotiarray_matsum_otiR(sotiarray_t* p_arr1, darray_t* p_arr2, sotiarray_t* p_arrRes);
// ----------------------------------------------------------------------------------------------------


void sotiarray_matsum_otioti(sotiarray_t* p_arr1, sotiarray_t* p_arr2, 
                             sotiarray_t* p_arrRes, dhelpl_t dhl);
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
@brief Set an item at position i,j in p_array. To be called only when p_array has already been created
and has some correct values in it. 

@param[in] i: row
@param[in] j: column
@param[inout] p_array: Address of the array.
@param[in] dhl: Direction helper list.
******************************************************************************************************/ 
void sotiarray_setItemR( coeff_t num, uint64_t i, uint64_t j, sotiarray_t* p_array, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------


void sotiarray_setAllItems( sotinum_t* num, sotiarray_t* p_array, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Set an item at position i,j in p_array. To be called only when p_array has already been created
and has some correct values in it. 

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