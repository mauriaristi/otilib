#ifndef OTI_SPARSE_H
#define OTI_SPARSE_H
// ----------------------------------------------------------------------------------------------------
// ---------------------------------     EXTERNAL LIBRARIES     ---------------------------------------
// ----------------------------------------------------------------------------------------------------

#include "oti/core.h"
#include "oti/base_math.h"

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
} sotinum_t;             ///< Sparse OTI number type

// ----------------------------------------------------------------------------------------------------
// -------------------------------------    END STRUCTURES      ---------------------------------------
// ----------------------------------------------------------------------------------------------------



// ----------------------------------------------------------------------------------------------------
// ------------------------------------     DECLARATIONS     ------------------------------------------
// ----------------------------------------------------------------------------------------------------




/**************************************************************************************************//**
@brief This function subtracts two sparse oti numbers. The result is held in a temporal 
sparse oti number that needs to be copied, either to a new sotinum type or to an already existing 
object. The memory returned should not be freed nor manipulated.

@param[in] num1: OTI number.
@param[in] num2: OTI number.
@param[in] dhl: Direction helper list object.
******************************************************************************************************/ 
sotinum_t soti_base_sub(sotinum_t* num1, sotinum_t* num2, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief This function adds two sparse oti numbers. The result is held in a temporal 
sparse oti number that needs to be copied, either to a new sotinum type or to an already existing 
object. The memory returned should not be freed nor manipulated.

@param[in] num1: OTI number.
@param[in] num2: OTI number.
@param[in] dhl: Direction helper list object.
******************************************************************************************************/ 
sotinum_t soti_base_sum(sotinum_t* num1, sotinum_t* num2, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------



/**************************************************************************************************//**
@brief This function multiplies two oti numbers num1 and num2. The result is held in a temporal 
sparse oti number that needs to be copied, either to a new sotinum type or to an already existing 
object. The memory returned should not be freed nor manipulated.

@param[in]    num1 Oti number 1.
@param[in]    num2 Oti number 2.
@param[in]    dhl  Direction helper list object.
******************************************************************************************************/
sotinum_t soti_base_feval(coeff_t* feval_re, sotinum_t* num, dhelpl_t dhl );
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief This function multiplies two oti numbers num1 and num2. The multiplication result is held
in a temporal oti number that needs to be copied. The memory returned should not be freed nor 
manipulated.

@param[in]    num1 Oti number 1.
@param[in]    num2 Oti number 2.
@param[in]    dhl  Direction helper list object.
******************************************************************************************************/ 
sotinum_t soti_base_mul(sotinum_t* num1, sotinum_t* num2, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------







// FUNCTIONS THAT ALLOCATE NEW MEMORY:


/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic tangent function at (num).

@param[in] num: Oti number.
@param[in] dhl: Direction helper list object.
******************************************************************************************************/ 
sotinum_t soti_atanh(sotinum_t* num, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic sine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
sotinum_t soti_asinh(sotinum_t* num, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic cosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
sotinum_t soti_acosh(sotinum_t* num, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic tangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
sotinum_t soti_tanh(sotinum_t* num, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of square root function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
sotinum_t soti_sqrt(sotinum_t* num, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic cosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
sotinum_t soti_cosh(sotinum_t* num, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic sine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
sotinum_t soti_sinh(sotinum_t* num, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arcsine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
sotinum_t soti_asin(sotinum_t* num, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arccosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
sotinum_t soti_acos(sotinum_t* num, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arctangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
sotinum_t soti_atan(sotinum_t* num, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of the tangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
sotinum_t soti_tan(sotinum_t* num, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of function cosine at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
sotinum_t soti_cos(sotinum_t* num, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of function sine at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
sotinum_t soti_sin(sotinum_t* num, dhelpl_t dhl );
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of Logarithm at base b function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
sotinum_t soti_logb(sotinum_t* num, double base, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of Logarithm at base 10 function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
sotinum_t soti_log10(sotinum_t* num, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
sotinum_t soti_log(sotinum_t* num, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
sotinum_t soti_exp(sotinum_t* num, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
sotinum_t soti_pow(sotinum_t* num, double e, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------
























/**************************************************************************************************//**
@brief Truncated self addition of two oti numbers. This function adds num1 and num2 just to obtain 
imaginary directions with orders greater than the given truncation order.

@param[in]    num1 Oti number 1.
@param[in]    ord  Truncation order.
@param[inout] res  OTI number out. It most come allocated. 
@param[in]    dhl  Direction helper list object.
******************************************************************************************************/ 
void soti_trunc_ssum(sotinum_t* num1, ord_t ord, sotinum_t* res, dhelpl_t dhl );
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Truncated integer power of an oti number. This function is useful for evaluation of functions 
at oti numbers.

The truncation is taken into account in the following manner. Ord1 and ord2 tells the function from 
which order to take into account the multiplication of coefficients from number 1 and number 2 
respectively. Then, standard OTI multiplication should be achieved if ord1 and ord2 are both equal 
to 0.

@param[in]    num1 Oti number 1.
@param[in]    ord1 Truncation order of num1. (>=1)
@param[in]    num2 Oti number 2.
@param[in]    ord2 Truncation order of num2. (>=1)
@param[inout] res  OTI number out. It most come allocated. 
@param[in]    dhl  Direction helper list object.
******************************************************************************************************/ 
void soti_trunc_mul(sotinum_t* num1, ord_t ord1, 
                    sotinum_t* num2, ord_t ord2, 
                    sotinum_t* dest, dhelpl_t dhl );
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Multiply by real only coefficients with order ord and greater.

@param[in] a real number to be set.
@param[in] ord Order.
@param[in] res Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/
void soti_trunc_smul_real(coeff_t a, ord_t ord, sotinum_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Copy information from src to dest. Does not check if memory needs to be reallocated.
Useful when copying data to a temporal sotinum.

@param[in] src  Oti number.
@param[in] dest Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/
void soti_set( sotinum_t* src, sotinum_t* dest, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Copy information from src to dest only with orders ord or greater. Does not check if memory 
needs to be reallocated. Useful when copying data to a temporal sotinum.

@param[in] src Oti number.
@param[in] ord Order.
@param[in] dest Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/
void soti_set_trunc( sotinum_t* src, ord_t ord, sotinum_t* dest, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Set a sparse otinum from a real number. Does not check if memory needs to be reallocated.
Useful when setting data to a temporal sotinum.

@param[in] a real number to be set.
@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
void soti_setFromReal( coeff_t a, sotinum_t* num, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of a function f at (num).

@param[in] feval_re Function, and its derivatives, evaluated at the real coefficient of num.
@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
sotinum_t soti_feval(coeff_t* feval_re, sotinum_t* num, dhelpl_t dhl );
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Divide two sparse oti numbers.

This function uses temporals 0 - 9.

@param[in] num1 OTI number.
@param[in] num2 OTI number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
sotinum_t soti_div(sotinum_t* num, sotinum_t* den, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief  Get the derivative corresponding to the index and order.

@param[in] idx Number of imaginary bases.
@param[in] order Truncation order of the number.
@param[in] num Address of the otin number to be modified.    
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
coeff_t soti_get_deriv( imdir_t idx, ord_t order, sotinum_t* num, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Multiply two sparse oti numbers.

This function uses temporals 0, 1, 2, 3, 4, 5.

@param[in] num1 OTI number.
@param[in] num2 OTI number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
sotinum_t soti_mul(sotinum_t* num1, sotinum_t* num2, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Subtract two sparse oti numbers.

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
@brief Generate a temporal sparse otinum with the allocated data in the direction helper.

@param[in] ntmp Number of temporal array to be retreived.
@param[in] order Truncation order.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
sotinum_t soti_get_tmp(ndir_t ntmp, ord_t order, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Function that divides an  a real number by an oti number.

@param[in] num OTI number.
@param[in] val Real number to be added
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
sotinum_t soti_div_realoti(coeff_t num, sotinum_t* den, dhelpl_t dhl);
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
@brief Copy to another (new) sparse oti elements.

@param[in] num OTI number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
sotinum_t soti_copy(sotinum_t* num, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Copy to another sparse oti elements (already created). This function checks wether reallocation
is necessary.

@param[in] num OTI number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
void soti_copy_to(sotinum_t* src, sotinum_t* dest, dhelpl_t dhl);
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