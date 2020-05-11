#ifndef OTI_DENSE_SCALAR_FUNCTIONS_H
#define OTI_DENSE_SCALAR_FUNCTIONS_H

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic tangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
otinum_t oti_atanh(   otinum_t* num,                dhelpl_t dhl);
void     oti_atanh_to(otinum_t* num, otinum_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic sine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
otinum_t oti_asinh(   otinum_t* num,                dhelpl_t dhl);
void     oti_asinh_to(otinum_t* num, otinum_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic cosine function at (num).

@param[in] num OTI number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
otinum_t oti_acosh(   otinum_t* num,                dhelpl_t dhl);
void     oti_acosh_to(otinum_t* num, otinum_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic tangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
otinum_t oti_tanh(   otinum_t* num,                dhelpl_t dhl);
void     oti_tanh_to(otinum_t* num, otinum_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of square root function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
otinum_t oti_sqrt(   otinum_t* num,                dhelpl_t dhl);
void     oti_sqrt_to(otinum_t* num, otinum_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic cosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
otinum_t oti_cosh(   otinum_t* num,                dhelpl_t dhl);
void     oti_cosh_to(otinum_t* num, otinum_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic sine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
otinum_t oti_sinh(   otinum_t* num,                dhelpl_t dhl);
void     oti_sinh_to(otinum_t* num, otinum_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arcsine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
otinum_t oti_asin(   otinum_t* num,                dhelpl_t dhl);
void     oti_asin_to(otinum_t* num, otinum_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arccosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
otinum_t oti_acos(   otinum_t* num,                dhelpl_t dhl);
void     oti_acos_to(otinum_t* num, otinum_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arctangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
otinum_t oti_atan(   otinum_t* num,                dhelpl_t dhl);
void     oti_atan_to(otinum_t* num, otinum_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of the tangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
otinum_t oti_tan(   otinum_t* num,                dhelpl_t dhl);
void     oti_tan_to(otinum_t* num, otinum_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of function cosine at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
otinum_t oti_cos(   otinum_t* num,                dhelpl_t dhl);
void     oti_cos_to(otinum_t* num, otinum_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of function sine at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
otinum_t oti_sin(   otinum_t* num,                dhelpl_t dhl );
void     oti_sin_to(otinum_t* num, otinum_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of Logarithm at base b function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
otinum_t oti_logb(   otinum_t* num, double base,                dhelpl_t dhl);
void     oti_logb_to(otinum_t* num, double base, otinum_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of Logarithm at base 10 function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
otinum_t oti_log10(   otinum_t* num,                dhelpl_t dhl);
void     oti_log10_to(otinum_t* num, otinum_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
otinum_t oti_log(   otinum_t* num,                dhelpl_t dhl);
void     oti_log_to(otinum_t* num, otinum_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
otinum_t oti_exp(   otinum_t* num,                dhelpl_t dhl);
void     oti_exp_to(otinum_t* num, otinum_t* res, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
otinum_t oti_pow(   otinum_t* num, double e,                dhelpl_t dhl);
void     oti_pow_to(otinum_t* num, double e, otinum_t* res, dhelpl_t dhl);

// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of a function f at (num).

@param[in] feval_re Function, and its derivatives, evaluated at the real coefficient of num.
@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
otinum_t oti_feval(    coeff_t* feval_re, otinum_t* num,                dhelpl_t dhl );
void     oti_feval_to( coeff_t* feval_re, otinum_t* num, otinum_t* res, dhelpl_t dhl );
// ----------------------------------------------------------------------------------------------------

#endif