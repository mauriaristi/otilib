#ifndef OTI_SPARSE_H
#define OTI_SPARSE_H
// ----------------------------------------------------------------------------------------------------
// ---------------------------------     EXTERNAL LIBRARIES     ---------------------------------------
// ----------------------------------------------------------------------------------------------------

#include "oti/core.h"

// ----------------------------------------------------------------------------------------------------
// --------------------------------    END EXTERNAL LIBRARIES     -------------------------------------
// ----------------------------------------------------------------------------------------------------



// ----------------------------------------------------------------------------------------------------
// --------------------------------------      STRUCTURES        --------------------------------------
// ----------------------------------------------------------------------------------------------------

typedef struct {
    coeff_t          re; ///< Real coefficient.
    coeff_t**      p_im; ///< Array with all imaginary coefficients per order.
    imdir_t**     p_idx; ///< Directions associated to each coefficient per order.
    ndir_t*       p_nnz; ///< Number of non zero coefficients per order.
    ndir_t*      p_size; ///< Allocated size per order.
    ord_t         order; ///< Truncation order of the number.
} sotinum_t; ///< Sparse OTI number type

// ----------------------------------------------------------------------------------------------------
// -------------------------------------    END STRUCTURES      ---------------------------------------
// ----------------------------------------------------------------------------------------------------



// ----------------------------------------------------------------------------------------------------
// ------------------------------------     DECLARATIONS     ------------------------------------------
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Multiply two sparse oti numbers.

@param[in] num1 OTI number.
@param[in] num2 OTI number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
sotinum_t soti_mul(sotinum_t* num1, sotinum_t* num2, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Add two sparse oti numbers.

@param[in] num1 OTI number.
@param[in] num2 OTI number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
sotinum_t soti_sub(sotinum_t* num1, sotinum_t* num2, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Add two sparse oti numbers.

@param[in] num1 OTI number.
@param[in] num2 OTI number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
sotinum_t soti_sum(sotinum_t* num1, sotinum_t* num2, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Generate a temporal array with the allocated data

@param[in] ntmp Number of temporal array to be retreived.
@param[in] order Truncation order.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
sotinum_t soti_get_tmp(ndir_t ntmp, ord_t order, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Function that divides an oti number by a real number.

@param[in] num OTI number.
@param[in] val Real number to be added
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
sotinum_t soti_div_otireal(sotinum_t* num, coeff_t val, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Function that subtracts an oti number to a real number.

@param[in] val Real number to be added
@param[in] num OTI number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
sotinum_t soti_sub_realoti( coeff_t val, sotinum_t* num, dhelpl_t dhl);

/**************************************************************************************************//**
@brief Function that subtracts a real number to an oti number.

@param[in] num OTI number.
@param[in] val Real number to be added
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
sotinum_t soti_sub_otireal(sotinum_t* num, coeff_t val, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Function that negates an oti number.

@param[in] num OTI number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
sotinum_t soti_neg(sotinum_t* num, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Function that multiplies an oti number to a real number.

@param[in] val Real number to be added
@param[in] num OTI number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
sotinum_t soti_mul_real(coeff_t val, sotinum_t* num, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Function that adds an oti number to a real number.

@param[in] val Real number to be added
@param[in] num OTI number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
sotinum_t soti_sum_real(coeff_t val, sotinum_t* num, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Function that inserts the corresponding value in the arrays defining the oti number. If the 
array requires reallocation, it performs the reallocation in memory. This function preserves the order
of the indices.

@param[in] val Value to be set.
@param[in] idx Index of the imaginary direction
@param[in] order Order that defines the imaginary direction.
@param[inout] num OTI number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
void soti_insert_item(ndir_t pos, coeff_t val, imdir_t idx, ord_t order, sotinum_t* num, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Function that sets the specified item value.

@param[in] val Value to be set.
@param[in] idx Index of the imaginary direction
@param[in] order Order that defines the imaginary direction.
@param[inout] num OTI number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
void soti_set_item(coeff_t val, imdir_t idx, ord_t order, sotinum_t* num, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Function that gets the specified item value.

@param[in] idx Index of the imaginary direction
@param[in] order Order that defines the imaginary direction.
@param[in] num OTI number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
coeff_t soti_get_item(imdir_t idx, ord_t order, sotinum_t* num, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Copy to another sparse oti elements.

@param[in] num OTI number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
sotinum_t soti_copy(sotinum_t* num, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Print function for oti numbers

@param[in] num OTI number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
void soti_print(sotinum_t* num, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Free memory allocated for the given OTI number.

@param[in] num OTI number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
void soti_free(sotinum_t* num);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Create a new oti number with a real coefficient given by the input parameter and 

@param[in] num Real coefficient of the OTI number.
@param[in] order Truncation order.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
sotinum_t soti_createReal(coeff_t num, ord_t order, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Allocate a new sparse oti number in memory. Creation follows the standard memory sizes as 
indicated in dhl.

The number is created with a non-zero real coefficient (which is not initialized) and the creation in 
memory of the other elements correspond to zero value coefficients in the imaginary directions.

@param[in] order Truncation order.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
sotinum_t soti_createEmpty( ord_t order, dhelpl_t dhl); 
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Allocate a new sparse oti number in memory using a specified allocated size.

@param[in] nnz Array of length order containing the sizes per order to be allocated.
@param[in] order Truncation order.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
sotinum_t soti_createEmpty_predef(ndir_t* p_nnz, ord_t order, dhelpl_t dhl); 
// ----------------------------------------------------------------------------------------------------


// added to c_otilib.pxd




// ----------------------------------------------------------------------------------------------------
// ----------------------------------     END DECLARATIONS     ----------------------------------------
// ----------------------------------------------------------------------------------------------------


#endif