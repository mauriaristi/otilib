#ifndef OTI_DENSE_H
#define OTI_DENSE_H
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
    coeff_t          re;  ///< Real Coefficient.
    coeff_t**      p_im;  ///< Array of imaginary coefficients.
    ndir_t*      p_ndpo;  ///< Number of imaginary directions per order.
    ndir_t         ndir;  ///< Number of imaginary directions.
    bases_t      nbases;  ///< Number of bases.
    ord_t         order;  ///< Truncation order. 
} otinum_t;

// ----------------------------------------------------------------------------------------------------
// -------------------------------------    END STRUCTURES      ---------------------------------------
// ----------------------------------------------------------------------------------------------------


// ----------------------------------------------------------------------------------------------------
// ------------------------------------     DECLARATIONS     ------------------------------------------
// ----------------------------------------------------------------------------------------------------
// to add to c_otilib.pxd


/**************************************************************************************************//**
@brief Evaluation of inverse 4 quadrant tangent function at (num).

@param[in] num Oti number. Numerator.
@param[in] den OTI number. Denominator.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
// otinum_t oti_atan2(otinum_t* num, otinum_t* y, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic tangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
otinum_t oti_atanh(otinum_t* num, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic sine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
otinum_t oti_asinh(otinum_t* num, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic cosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
otinum_t oti_acosh(otinum_t* num, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic tangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
otinum_t oti_tanh(otinum_t* num, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of square root function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
otinum_t oti_sqrt(otinum_t* num, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic cosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
otinum_t oti_cosh(otinum_t* num, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic sine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
otinum_t oti_sinh(otinum_t* num, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arcsine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
otinum_t oti_asin(otinum_t* num, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arccosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
otinum_t oti_acos(otinum_t* num, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arctangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
otinum_t oti_atan(otinum_t* num, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of the tangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
otinum_t oti_tan(otinum_t* num, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of function cosine at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
otinum_t oti_cos(otinum_t* num, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of function sine at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
otinum_t oti_sin(otinum_t* num, dhelpl_t dhl );
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of Logarithm at base b function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
otinum_t oti_logb(otinum_t* num, double base, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of Logarithm at base 10 function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
otinum_t oti_log10(otinum_t* num, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
otinum_t oti_log(otinum_t* num, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
otinum_t oti_exp(otinum_t* num, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
otinum_t oti_pow(otinum_t* num, double e, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of a function f at (num).

@param[in] feval_re Function, and its derivatives, evaluated at the real coefficient of num.
@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
otinum_t oti_feval(coeff_t* feval_re, otinum_t* num, dhelpl_t dhl );
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Truncated self addition of two oti numbers. This function adds num1 and num2 just to obtain 
imaginary directions with orders greater than the given truncation order.

@param[in]    num1 Oti number 1.
@param[in]    ord  Truncation order.
@param[inout] res  OTI number out. It most come allocated. 
@param[in]    dhl  Direction helper list object.
******************************************************************************************************/ 
void oti_trunc_ssum(otinum_t* num1,  
                   ord_t ord, otinum_t* res,  dhelpl_t dhl );
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
void oti_trunc_mul(otinum_t* num1, ord_t ord1, 
	               otinum_t* num2, ord_t ord2, 
	               otinum_t* res, dhelpl_t dhl );
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Truncated Self multiplication of an oti number with a real number.

@param[in] a Real number.
@param[in] ord Truncation order.
@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
void oti_trunc_smul_real(coeff_t a, ord_t ord, otinum_t* num, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Negate an oti numbers.

@param[in] num1 Oti number
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
otinum_t oti_neg(otinum_t* num1, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Subtract oti number by a real.

@param[in] a real number
@param[in] num2 Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
otinum_t oti_sub_otireal(otinum_t* num1, coeff_t a, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Subtract real by an oti number.

@param[in] a real number
@param[in] num2 Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
otinum_t oti_sub_realoti(coeff_t a, otinum_t* num2, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------


/**************************************************************************************************//**
@brief subtract two oti numbers.

@param[in] num1 Oti number
@param[in] num2 Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
otinum_t oti_sub(otinum_t* num1, otinum_t* num2, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Division of a real by an oti number.

@param[in] num Oti number
@param[in] den Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
otinum_t oti_div_realoti(coeff_t num, otinum_t* den, dhelpl_t dhl );
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Division of a real by an oti number.

@param[in] num Oti number
@param[in] den Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
otinum_t oti_div_otireal(otinum_t* num, coeff_t den, dhelpl_t dhl );
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Division between two oti numbers.

@param[in] num Oti number
@param[in] den Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
otinum_t oti_div(otinum_t* num, otinum_t* den, dhelpl_t dhl );
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Multiplication between two oti numbers.

@param[in] num1 Oti number
@param[in] num2 Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
otinum_t oti_mul(otinum_t* num1, otinum_t* num2, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Multiplication of an oti numbers and a real number

@param[in] a Real number.
@param[in] num2 Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
otinum_t oti_mul_real(coeff_t a, otinum_t* num1, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Addition of two oti numbers.

@param[in] num1 Oti number
@param[in] num2 Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
otinum_t oti_sum(otinum_t* num1, otinum_t* num2, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Addition of two oti numbers.

@param[in] num1 Oti number to be copied.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
otinum_t oti_copy(otinum_t* num, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Addition of one oti number and a scalar number.

@param[in] a Real number
@param[in] num1 Oti number. 
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
otinum_t oti_sum_real(coeff_t a, otinum_t* num1, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------


/**************************************************************************************************//**
@brief Addition of one oti number and a scalar number, driven by an already created oti number.

@param[in] nbases New number of imaginary bases.
@param[in] num1 New truncation order of the number.
@param[inout] num Address of the oti number to receive the result.    
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
void oti_sum_real_r(coeff_t a, otinum_t* num1, otinum_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief  Set the value of an imaginary coefficient given the index and order.

@param[in] a Coefficient to be implemented.
@param[in] idx index of the imaginary direction.
@param[in] order Order of the imagianry direction.
@param[inout] num Address of the otin number to be modified.    
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
void oti_setIm_IdxOrd( coeff_t a, imdir_t idx, ord_t order, otinum_t* num, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief  Get the imaginary direction coefficient given the index and order.

@param[in] idx Number of imaginary bases.
@param[in] order Truncation order of the number.
@param[in] num Address of the otin number to be modified.    
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
coeff_t oti_get( imdir_t idx, ord_t order, otinum_t* num, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief  Get the derivative corresponding to the index and order.

@param[in] idx Number of imaginary bases.
@param[in] order Truncation order of the number.
@param[in] num Address of the otin number to be modified.    
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
coeff_t oti_get_deriv( imdir_t idx, ord_t order, otinum_t* num, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Create Zero.

@param[in] nbases Number of imaginary bases.
@param[in] order Truncation order of the number.
@param[inout] num Address of the object to be created.    
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
otinum_t oti_createZero( bases_t nbases, ord_t order, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Allocation of a dense oti number.

@param[in] nbases Number of imaginary bases.
@param[in] order Truncation order of the number.
@param[inout] num Address of the object to be created.    
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
otinum_t oti_createEmpty( bases_t nbases, ord_t order, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Assign an oti number copying the values from another oti number.

@param[in] OTI number.
@param[inout] num Address of the oti number to be assigned
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
void oti_set( otinum_t* num, otinum_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Assign an oti number the value of a given real number.

@param[in] a Real number.
@param[inout] num Address of the oti number to be assigned
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
void oti_setFromReal( coeff_t a, otinum_t* num, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Print an oti number to console.

@param[in] num Address of the oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
void oti_print( otinum_t* num, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Free the memory in an oti number object.

@param[in] num Address of the oti number.  
******************************************************************************************************/ 
void oti_free( otinum_t* num );
// ----------------------------------------------------------------------------------------------------


// ----------------------------------------------------------------------------------------------------
// ----------------------------------     END DECLARATIONS     ----------------------------------------
// ----------------------------------------------------------------------------------------------------

#endif