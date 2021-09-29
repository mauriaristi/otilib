#ifndef OTI_SEMISPARSE_SCALAR_FUNCTIONS_H
#define OTI_SEMISPARSE_SCALAR_FUNCTIONS_H

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic tangent function at (num).

@param[in] num: Oti number.
@param[in] dhl: Direction helper list object.
******************************************************************************************************/ 
semiotin_t ssoti_atanh(semiotin_t* num, dhelpl_t dhl);
void ssoti_atanh_to(semiotin_t* num, semiotin_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic sine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
semiotin_t ssoti_asinh(semiotin_t* num, dhelpl_t dhl);
void ssoti_asinh_to(semiotin_t* num, semiotin_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic cosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
semiotin_t ssoti_acosh(semiotin_t* num, dhelpl_t dhl);
void ssoti_acosh_to(semiotin_t* num, semiotin_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic tangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
semiotin_t ssoti_tanh(semiotin_t* num, dhelpl_t dhl);
void ssoti_tanh_to(semiotin_t* num, semiotin_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of square root function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
semiotin_t ssoti_sqrt(semiotin_t* num, dhelpl_t dhl);
void ssoti_sqrt_to(semiotin_t* num, semiotin_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of cubic root function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
semiotin_t ssoti_cbrt(semiotin_t* num, dhelpl_t dhl);
void ssoti_cbrt_to(semiotin_t* num, semiotin_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic cosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
semiotin_t ssoti_cosh(semiotin_t* num, dhelpl_t dhl);
void ssoti_cosh_to(semiotin_t* num, semiotin_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic sine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
semiotin_t ssoti_sinh(semiotin_t* num, dhelpl_t dhl);
void ssoti_sinh_to(semiotin_t* num, semiotin_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arcsine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
semiotin_t ssoti_asin(semiotin_t* num, dhelpl_t dhl);
void ssoti_asin_to(semiotin_t* num, semiotin_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arccosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
semiotin_t ssoti_acos(semiotin_t* num, dhelpl_t dhl);
void ssoti_acos_to(semiotin_t* num, semiotin_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arctangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
semiotin_t ssoti_atan(semiotin_t* num, dhelpl_t dhl);
void ssoti_atan_to(semiotin_t* num, semiotin_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of the tangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
semiotin_t ssoti_tan(semiotin_t* num, dhelpl_t dhl);
void ssoti_tan_to(semiotin_t* num, semiotin_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of function cosine at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
semiotin_t ssoti_cos(semiotin_t* num, dhelpl_t dhl);
void ssoti_cos_to(semiotin_t* num, semiotin_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of function sine at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
semiotin_t ssoti_sin(semiotin_t* num, dhelpl_t dhl );
void ssoti_sin_to(semiotin_t* num, semiotin_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of Logarithm at base b function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
semiotin_t ssoti_logb(semiotin_t* num, double base, dhelpl_t dhl);
void ssoti_logb_to(semiotin_t* num, double base, semiotin_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of Logarithm at base 10 function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
semiotin_t ssoti_log10(semiotin_t* num, dhelpl_t dhl);
void ssoti_log10_to(semiotin_t* num, semiotin_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
semiotin_t ssoti_log(semiotin_t* num, dhelpl_t dhl);
void ssoti_log_to(semiotin_t* num, semiotin_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
semiotin_t ssoti_exp(semiotin_t* num, dhelpl_t dhl);
void ssoti_exp_to(semiotin_t* num, semiotin_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
semiotin_t ssoti_pow(semiotin_t* num, double e, dhelpl_t dhl);
void ssoti_pow_to(semiotin_t* num, coeff_t e, semiotin_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of a function f at (num).

@param[in] feval_re Function, and its derivatives, evaluated at the real coefficient of num.
@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
semiotin_t ssoti_feval(coeff_t* feval_re, semiotin_t* num, dhelpl_t dhl );
semiotin_t ssoti_base_feval(coeff_t* feval_re, semiotin_t* num, dhelpl_t dhl );

void ssoti_feval_to(coeff_t* feval_re, semiotin_t* num, semiotin_t* res, dhelpl_t dhl );
// ----------------------------------------------------------------------------------------------------

#endif