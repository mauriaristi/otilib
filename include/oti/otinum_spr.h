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
    coeff_t          re;  ///< Real coefficient.
    coeff_t**      p_im;  ///< Array with all imaginary coefficients per order.
    imdir_t**     p_idx;  ///< Directions associated to each coefficient per order.
    ndir_t*       p_nnz;  ///< Number of non zero coefficients per order.
    ndir_t*      p_size;  ///< Allocated size per order.
    ord_t         order;  ///< Truncation order of the number.
} sotinum_t; ///< Sparse OTI number type

// ----------------------------------------------------------------------------------------------------
// -------------------------------------    END STRUCTURES      ---------------------------------------
// ----------------------------------------------------------------------------------------------------



// ----------------------------------------------------------------------------------------------------
// ------------------------------------     DECLARATIONS     ------------------------------------------
// ----------------------------------------------------------------------------------------------------
// to add to c_otilib.pxd

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


// added to c_otilib.pxd


// void c_soti_fdiv(double numx, sotinum_t* numy, sotinum_t* res, directionHelper* p_dH);

// void c_soti_divf(sotinum_t* numx, double numy, sotinum_t* res);

// void c_soti_div(sotinum_t* numx, sotinum_t* numy, sotinum_t* res, directionHelper* p_dH);

// double c_soti_getReal(sotinum_t* num);

// void c_soti_atan2(sotinum_t* numx, sotinum_t* numy, directionHelper* p_dH, sotinum_t* res);

// void c_soti_logb(sotinum_t* num, int base, directionHelper* p_dH, sotinum_t* res);

// void c_soti_log10(sotinum_t* num, directionHelper* p_dH, sotinum_t* res);

// void c_soti_atanh(sotinum_t* num, directionHelper* p_dH, sotinum_t* res);

// void c_soti_asinh(sotinum_t* num, directionHelper* p_dH, sotinum_t* res);

// void c_soti_acosh(sotinum_t* num, directionHelper* p_dH, sotinum_t* res);

// void c_soti_tanh(sotinum_t* num, directionHelper* p_dH, sotinum_t* res);

// void c_soti_sqrt(sotinum_t* num, directionHelper* p_dH, sotinum_t* res);

// void c_soti_cosh(sotinum_t* num, directionHelper* p_dH, sotinum_t* res);

// void c_soti_sinh(sotinum_t* num, directionHelper* p_dH, sotinum_t* res);

// void c_soti_asin(sotinum_t* num, directionHelper* p_dH, sotinum_t* res);

// void c_soti_acos(sotinum_t* num, directionHelper* p_dH, sotinum_t* res);

// void c_soti_atan(sotinum_t* num, directionHelper* p_dH, sotinum_t* res);

// void c_soti_tan(sotinum_t* num, directionHelper* p_dH, sotinum_t* res);

// void c_soti_cos(sotinum_t* num, directionHelper* p_dH, sotinum_t* res);

// void c_soti_sin(sotinum_t* num, directionHelper* p_dH, sotinum_t* res);

// void c_soti_log(sotinum_t* num, directionHelper* p_dH, sotinum_t* res);

// void c_soti_exp(sotinum_t* num, directionHelper* p_dH, sotinum_t* res);
 
// void c_soti_derivFunc(double* fder, sotinum_t* g, directionHelper* p_dH, sotinum_t* feval);

// void c_soti_smulf(sotinum_t* num1, double num2);

// void c_soti_copy(sotinum_t* res, sotinum_t* num1);

// void c_soti_pow(sotinum_t* num, double exponent, directionHelper* p_dH,sotinum_t* res);

// void c_soti_ipowfast(sotinum_t* num1, uint8_t exp, sotinum_t* res, directionHelper* p_dH); 

// void c_soti_ipow(sotinum_t* num1, uint8_t exp, sotinum_t* res, directionHelper* p_dH);

// void c_soti_neg( sotinum_t* num1, sotinum_t* res);

// void c_soti_fsub(sotinum_t* num1, double num2, sotinum_t* res);

// void c_soti_subf(sotinum_t* num1, double num2, sotinum_t* res);

// void c_soti_sub(sotinum_t* num1, sotinum_t* num2, sotinum_t* res, directionHelper* p_dH);

// void c_soti_sumf(sotinum_t* num1, double num2, sotinum_t* res);

// void c_soti_mulf(sotinum_t* num1, double num2, sotinum_t* res);

// void c_soti_mul(sotinum_t* num1, sotinum_t* num2, sotinum_t* res, directionHelper* p_dH);

// void c_soti_sum(sotinum_t* num1, sotinum_t* num2, sotinum_t* res, directionHelper* p_dH);

// void c_soti_free(sotinum_t* numHolder);


// ----------------------------------------------------------------------------------------------------
// ----------------------------------     END DECLARATIONS     ----------------------------------------
// ----------------------------------------------------------------------------------------------------


#endif