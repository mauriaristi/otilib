#ifndef OTI_DENSE_H
#define OTI_DENSE_H
// ----------------------------------------------------------------------------------------------------
// ---------------------------------     EXTERNAL LIBRARIES     ---------------------------------------
// ----------------------------------------------------------------------------------------------------

#include "oti/core.h"
#include "oti/real.h"

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
} otinum_t;  ///< OTI scalar type.


typedef struct {
    arr_t            re;  ///< Real Coefficient.
    arr_t**        p_im;  ///< Array of imaginary coefficients.
    ndir_t*      p_ndpo;  ///< Number of imaginary directions per order.
    ndir_t         ndir;  ///< Number of imaginary directions.
    bases_t      nbases;  ///< Number of bases.
    ord_t         order;  ///< Truncation order.
    uint64_t      nrows;  ///< Number of rows of every array.
    uint64_t      ncols;  ///< Number of columns of every array.
    uint64_t       size;  ///< Total number of elements in per array.
} oarr_t;     ///< OTI array type.


// ----------------------------------------------------------------------------------------------------
// -------------------------------------    END STRUCTURES      ---------------------------------------
// ----------------------------------------------------------------------------------------------------


// ----------------------------------------------------------------------------------------------------
// ------------------------------------     DECLARATIONS     ------------------------------------------
// ----------------------------------------------------------------------------------------------------
// to add to c_otilib.pxd



void dhelp_oarr_matmul_II(oarr_t* lhs, ord_t ord_lhs, // Input 1
                       oarr_t* rhs, ord_t ord_rhs, // Input 2
                       oarr_t* res, dhelpl_t dhl);
void dhelp_oarr_matmul_IR(oarr_t* lhs, oarr_t* rhs, ord_t ord_rhs, oarr_t* res, dhelpl_t dhl );
void dhelp_oarr_matmul_RI(oarr_t* lhs, oarr_t* rhs, ord_t ord_rhs, oarr_t* res, dhelpl_t dhl );
void dhelp_oarr_matmul_RR(oarr_t* lhs, oarr_t* rhs, oarr_t* res, dhelpl_t dhl);
// ARRAY



oarr_t oarr_feval(darr_t* feval_re, oarr_t* arr, dhelpl_t dhl );
void oarr_feval_to(darr_t* feval_re, oarr_t* arr, oarr_t* res, dhelpl_t dhl );

void oarr_trc_self_mul_r( darr_t* a, ord_t ord, oarr_t* res, dhelpl_t dhl);
void oarr_trc_self_sum(oarr_t* arr, ord_t ord, oarr_t* res, dhelpl_t dhl );
void oarr_trc_mul( oarr_t* arr1, ord_t ord1, oarr_t* arr2, ord_t ord2, oarr_t* res, dhelpl_t dhl );

// Algebra operations.

oarr_t oarr_neg( oarr_t* arr1, dhelpl_t dhl);
void oarr_neg_to(oarr_t* arr1, oarr_t* res, dhelpl_t dhl);

oarr_t oarr_sum_OO(oarr_t* arr1, oarr_t* arr2, dhelpl_t dhl);
void oarr_sum_OO_to(oarr_t* arr1, oarr_t* arr2, oarr_t* res, dhelpl_t dhl);
oarr_t oarr_sum_oO(otinum_t* num, oarr_t* arr1, dhelpl_t dhl);
void oarr_sum_oO_to(otinum_t* num, oarr_t* arr1, oarr_t* res, dhelpl_t dhl);
oarr_t oarr_sum_RO(darr_t* arr1, oarr_t* arr2, dhelpl_t dhl);
void oarr_sum_RO_to(darr_t* arr1, oarr_t* arr2, oarr_t* res, dhelpl_t dhl);
oarr_t oarr_sum_rO(coeff_t num,  oarr_t* arr1, dhelpl_t dhl);
void oarr_sum_rO_to(coeff_t num,  oarr_t* arr1, oarr_t* res, dhelpl_t dhl);

oarr_t oarr_sub_OO(oarr_t* arr1, oarr_t* arr2, dhelpl_t dhl);
void oarr_sub_OO_to(oarr_t* arr1, oarr_t* arr2, oarr_t* res, dhelpl_t dhl);
oarr_t oarr_sub_oO(otinum_t* num, oarr_t* arr1, dhelpl_t dhl);
void oarr_sub_oO_to(otinum_t* num, oarr_t* arr1, oarr_t* res, dhelpl_t dhl);
oarr_t oarr_sub_Oo(oarr_t* arr1, otinum_t* num, dhelpl_t dhl);
void oarr_sub_Oo_to(oarr_t* arr1, otinum_t* num, oarr_t* res, dhelpl_t dhl);
oarr_t oarr_sub_RO(darr_t* arr1, oarr_t* arr2, dhelpl_t dhl);
void oarr_sub_RO_to(darr_t* arr1, oarr_t* arr2, oarr_t* res, dhelpl_t dhl);
oarr_t oarr_sub_OR(oarr_t* arr1, darr_t* arr2, dhelpl_t dhl);
void oarr_sub_OR_to(oarr_t* arr1, darr_t* arr2, oarr_t* res, dhelpl_t dhl);
oarr_t oarr_sub_rO(coeff_t num,  oarr_t* arr1, dhelpl_t dhl);
void oarr_sub_rO_to(coeff_t num,  oarr_t* arr1, oarr_t* res, dhelpl_t dhl);
oarr_t oarr_sub_Or( oarr_t* arr1, coeff_t num, dhelpl_t dhl);
void oarr_sub_Or_to( oarr_t* arr1, coeff_t num, oarr_t* res, dhelpl_t dhl);

oarr_t oarr_mul_OO(oarr_t* arr1, oarr_t* arr2, dhelpl_t dhl);
void oarr_mul_OO_to(oarr_t* arr1, oarr_t* arr2, oarr_t* res, dhelpl_t dhl);
oarr_t oarr_mul_oO(otinum_t* num, oarr_t* arr1, dhelpl_t dhl);
void oarr_mul_oO_to(otinum_t* num, oarr_t* arr1, oarr_t* res, dhelpl_t dhl);
oarr_t oarr_mul_RO(darr_t* arr1, oarr_t* arr2, dhelpl_t dhl);
void oarr_mul_RO_to(darr_t* arr1, oarr_t* arr2, oarr_t* res, dhelpl_t dhl);
oarr_t oarr_mul_rO(coeff_t num,  oarr_t* arr1, dhelpl_t dhl);
void oarr_mul_rO_to(coeff_t num,  oarr_t* arr1, oarr_t* res, dhelpl_t dhl);



oarr_t oarr_div_OO(oarr_t* arr1, oarr_t* arr2, dhelpl_t dhl);
void oarr_div_OO_to(oarr_t* arr1, oarr_t* arr2, oarr_t* res, dhelpl_t dhl);
oarr_t oarr_div_oO(otinum_t* num, oarr_t* arr1, dhelpl_t dhl);
void oarr_div_oO_to(otinum_t* num, oarr_t* arr1, oarr_t* res, dhelpl_t dhl);
oarr_t oarr_div_Oo(oarr_t* arr1, otinum_t* num, dhelpl_t dhl);
void oarr_div_Oo_to(oarr_t* arr1, otinum_t* num, oarr_t* res, dhelpl_t dhl);
oarr_t oarr_div_RO(darr_t* arr1, oarr_t* arr2, dhelpl_t dhl);
void oarr_div_RO_to(darr_t* arr1, oarr_t* arr2, oarr_t* res, dhelpl_t dhl);
oarr_t oarr_div_OR(oarr_t* arr1, darr_t* arr2, dhelpl_t dhl);
void oarr_div_OR_to(oarr_t* arr1, darr_t* arr2, oarr_t* res, dhelpl_t dhl);
oarr_t oarr_div_rO(coeff_t num,  oarr_t* arr1, dhelpl_t dhl);
void oarr_div_rO_to(coeff_t num,  oarr_t* arr1, oarr_t* res, dhelpl_t dhl);
oarr_t oarr_div_Or( oarr_t* arr1, coeff_t num, dhelpl_t dhl);
void oarr_div_Or_to( oarr_t* arr1, coeff_t num, oarr_t* res, dhelpl_t dhl);



// Helper:
void dhelp_oarr_mul_RI(oarr_t* lhs, oarr_t* rhs, ord_t ord_rhs, oarr_t* res, dhelpl_t dhl );
void dhelp_oarr_mul_RR(oarr_t* lhs, oarr_t* rhs, oarr_t* res, dhelpl_t dhl);
void dhelp_oarr_mul_II(oarr_t* lhs, ord_t ord_lhs, oarr_t* rhs, ord_t ord_rhs, oarr_t* res, dhelpl_t dhl);

void dhelp_oarr_mul_rR(otinum_t* lhs, oarr_t* rhs, oarr_t* res, dhelpl_t dhl);
void dhelp_oarr_mul_rI(otinum_t* lhs, oarr_t* rhs, ord_t ord_rhs, oarr_t* res, dhelpl_t dhl );
void dhelp_oarr_mul_Ri(oarr_t* lhs, otinum_t* rhs, ord_t ord_rhs, oarr_t* res, dhelpl_t dhl );
void dhelp_oarr_mul_iI(otinum_t* lhs, ord_t ord_lhs, oarr_t* rhs, ord_t ord_rhs, oarr_t* res, dhelpl_t dhl);


void oarr_trunc_mul( oarr_t* arr1, ord_t ord1, oarr_t* arr2, ord_t ord2, oarr_t* res, dhelpl_t dhl );


// base:

void oarr_set_all_r( coeff_t num, oarr_t* arr, dhelpl_t dhl);
void oarr_set_item_i_r( coeff_t num, uint64_t i, oarr_t* arr, dhelpl_t dhl);
void oarr_set_item_ij_r( coeff_t num, uint64_t i, uint64_t j, oarr_t* arr, dhelpl_t dhl);
void oarr_set_all_o( otinum_t* num, oarr_t* arr, dhelpl_t dhl);
void oarr_set_item_i_o( otinum_t* num, uint64_t i, oarr_t* arr, dhelpl_t dhl);
void oarr_set_item_ij_o( otinum_t* num, uint64_t i, uint64_t j, oarr_t* arr, dhelpl_t dhl);

otinum_t oarr_get_item_i(oarr_t* arr, uint64_t i, dhelpl_t dhl);
otinum_t oarr_get_item_ij(oarr_t* arr, uint64_t i, uint64_t j, dhelpl_t dhl);

void oarr_get_item_i_to(oarr_t* p_array, uint64_t i, uint64_t j, otinum_t* res, dhelpl_t dhl);
void oarr_get_item_ij_to(oarr_t* p_array, uint64_t i, uint64_t j, otinum_t* res, dhelpl_t dhl);

void oarr_copy_to(oarr_t* arr, oarr_t* res, dhelpl_t dhl);
oarr_t oarr_copy(oarr_t* arr, dhelpl_t dhl);

oarr_t oarr_ones(uint64_t nrows, uint64_t ncols, bases_t nbases, ord_t order, dhelpl_t dhl);
oarr_t oarr_zeros(uint64_t nrows, uint64_t ncols, bases_t nbases, ord_t order, dhelpl_t dhl);
oarr_t oarr_eye(uint64_t size, bases_t nbases, ord_t order, dhelpl_t dhl);

void oarr_free(oarr_t* arr);
oarr_t oarr_createEmpty( uint64_t nrows, uint64_t ncols, bases_t nbases, ord_t order, dhelpl_t dhl);










/**************************************************************************************************//**
@brief Evaluation of inverse 4 quadrant tangent function at (num).

@param[in] num Oti number. Numerator.
@param[in] den OTI number. Denominator.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
// otinum_t oti_atan2(otinum_t* num, otinum_t* y, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Generate a temporal sparse otinum with the allocated data in the direction helper.

@param[in] ntmp Number of temporal array to be retreived.
@param[in] order Truncation order.
@param[in] order Truncation order.
@param[in] dhl Direction helper list object.
******************************************************************************************************/
otinum_t oti_get_tmp( ndir_t ntmp, ord_t order, bases_t nbases, dhelpl_t dhl);
otinum_t oti_get_rtmp( ndir_t ntmp, ord_t order, bases_t nbases, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic tangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
otinum_t oti_atanh(otinum_t* num, dhelpl_t dhl);
void oti_atanh_to(otinum_t* num, otinum_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic sine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
otinum_t oti_asinh(otinum_t* num, dhelpl_t dhl);
void oti_asinh_to(otinum_t* num, otinum_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic cosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
otinum_t oti_acosh(otinum_t* num, dhelpl_t dhl);
void oti_acosh_to(otinum_t* num, otinum_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic tangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
otinum_t oti_tanh(otinum_t* num, dhelpl_t dhl);
void oti_tanh_to(otinum_t* num, otinum_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of square root function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
otinum_t oti_sqrt(otinum_t* num, dhelpl_t dhl);
void oti_sqrt_to(otinum_t* num, otinum_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic cosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
otinum_t oti_cosh(otinum_t* num, dhelpl_t dhl);
void oti_cosh_to(otinum_t* num, otinum_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic sine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
otinum_t oti_sinh(otinum_t* num, dhelpl_t dhl);
void oti_sinh_to(otinum_t* num, otinum_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arcsine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
otinum_t oti_asin(otinum_t* num, dhelpl_t dhl);
void oti_asin_to(otinum_t* num, otinum_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arccosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
otinum_t oti_acos(otinum_t* num, dhelpl_t dhl);
void oti_acos_to(otinum_t* num, otinum_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arctangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
otinum_t oti_atan(otinum_t* num, dhelpl_t dhl);
void oti_atan_to(otinum_t* num, otinum_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of the tangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
otinum_t oti_tan(otinum_t* num, dhelpl_t dhl);
void oti_tan_to(otinum_t* num, otinum_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of function cosine at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
otinum_t oti_cos(otinum_t* num, dhelpl_t dhl);
void oti_cos_to(otinum_t* num, otinum_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of function sine at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
otinum_t oti_sin(otinum_t* num, dhelpl_t dhl );
void oti_sin_to(otinum_t* num, otinum_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of Logarithm at base b function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
otinum_t oti_logb(otinum_t* num, double base, dhelpl_t dhl);
void oti_logb_to(otinum_t* num, double base, otinum_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of Logarithm at base 10 function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
otinum_t oti_log10(otinum_t* num, dhelpl_t dhl);
void oti_log10_to(otinum_t* num, otinum_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
otinum_t oti_log(otinum_t* num, dhelpl_t dhl);
void oti_log_to(otinum_t* num, otinum_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
otinum_t oti_exp(otinum_t* num, dhelpl_t dhl);
void oti_exp_to(otinum_t* num, otinum_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
otinum_t oti_pow(otinum_t* num, double e, dhelpl_t dhl);
void oti_pow_to(otinum_t* num, double e, otinum_t* res, dhelpl_t dhl);

// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of a function f at (num).

@param[in] feval_re Function, and its derivatives, evaluated at the real coefficient of num.
@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
otinum_t oti_feval(coeff_t* feval_re, otinum_t* num, dhelpl_t dhl );
void oti_feval_to(coeff_t* feval_re, otinum_t* num, otinum_t* res, dhelpl_t dhl );
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
void oti_neg_to(otinum_t* num1, otinum_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Subtract oti number by a real.

@param[in] a real number
@param[in] num2 Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 

// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief subtract two oti numbers.

@param[in] num1 Oti number
@param[in] num2 Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
otinum_t oti_sub_oo(otinum_t* num1, otinum_t* num2, dhelpl_t dhl);
otinum_t oti_sub_or(otinum_t* num1, coeff_t a, dhelpl_t dhl);
otinum_t oti_sub_ro(coeff_t a, otinum_t* num2, dhelpl_t dhl);

void oti_sub_or_to(otinum_t* num1, coeff_t a, otinum_t* res, dhelpl_t dhl);
void oti_sub_ro_to(coeff_t a, otinum_t* num2, otinum_t* res, dhelpl_t dhl);
void oti_sub_oo_to(otinum_t* num1, otinum_t* num2, otinum_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Division between two oti numbers.

@param[in] num Oti number
@param[in] den Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
otinum_t oti_div_oo(otinum_t* num, otinum_t* den, dhelpl_t dhl );
otinum_t oti_div_ro(coeff_t num, otinum_t* den, dhelpl_t dhl );
otinum_t oti_div_or(otinum_t* num, coeff_t den, dhelpl_t dhl );

void oti_div_or_to(otinum_t* num, coeff_t den, otinum_t* res, dhelpl_t dhl );
void oti_div_ro_to(coeff_t num, otinum_t* den, otinum_t* res, dhelpl_t dhl );
void oti_div_oo_to(otinum_t* num, otinum_t* den, otinum_t* res, dhelpl_t dhl );
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Multiplication between two oti numbers.

@param[in] num1 Oti number
@param[in] num2 Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
otinum_t oti_mul_oo(otinum_t* num1, otinum_t* num2, dhelpl_t dhl);
otinum_t oti_mul_ro(coeff_t a, otinum_t* num1, dhelpl_t dhl);

void oti_mul_oo_to(otinum_t* num1, otinum_t* num2, otinum_t* res, dhelpl_t dhl);
void oti_mul_ro_to(coeff_t a, otinum_t* num1, otinum_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Addition of two oti numbers.

@param[in] num1 Oti number
@param[in] num2 Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
otinum_t oti_sum_oo(otinum_t* num1, otinum_t* num2, dhelpl_t dhl);
otinum_t oti_sum_ro(coeff_t a, otinum_t* num1, dhelpl_t dhl);

void oti_sum_oo_to(otinum_t* num1, otinum_t* num2, otinum_t* res, dhelpl_t dhl);
void oti_sum_ro_to(coeff_t a, otinum_t* num1, otinum_t* res, dhelpl_t dhl);
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
@brief Initialize otinum_t struct, Initializing all pointers to NULL and seting order to 0.

******************************************************************************************************/ 
otinum_t oti_init( void );
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Assign an oti number copying the values from another oti number.

@param[in] OTI number.
@param[inout] num Address of the oti number to be assigned.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
otinum_t oti_copy(otinum_t* num, dhelpl_t dhl);
void oti_copy_to( otinum_t* num, otinum_t* res, dhelpl_t dhl);
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

// #include "c/otinum_dense.c"

#endif