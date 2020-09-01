#ifndef OTI_MDNUM3_SCALAR_FUNCTIONS_H
#define OTI_MDNUM3_SCALAR_FUNCTIONS_H

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic tangent function at (num).

@param[in] num: Oti number.
@param[in] dhl: Direction helper list object.
******************************************************************************************************/ 
mdnum3_t mdnum3_atanh(mdnum3_t* num);
void mdnum3_atanh_to(mdnum3_t* num, mdnum3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic sine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum3_t mdnum3_asinh(mdnum3_t* num);
void mdnum3_asinh_to(mdnum3_t* num, mdnum3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic cosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum3_t mdnum3_acosh(mdnum3_t* num);
void mdnum3_acosh_to(mdnum3_t* num, mdnum3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic tangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum3_t mdnum3_tanh(mdnum3_t* num);
void mdnum3_tanh_to(mdnum3_t* num, mdnum3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of square root function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum3_t mdnum3_sqrt(mdnum3_t* num);
void mdnum3_sqrt_to(mdnum3_t* num, mdnum3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of cubic root function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum3_t mdnum3_cbrt(mdnum3_t* num);
void mdnum3_cbrt_to(mdnum3_t* num, mdnum3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic cosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum3_t mdnum3_cosh(mdnum3_t* num);
void mdnum3_cosh_to(mdnum3_t* num, mdnum3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic sine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum3_t mdnum3_sinh(mdnum3_t* num);
void mdnum3_sinh_to(mdnum3_t* num, mdnum3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arcsine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum3_t mdnum3_asin(mdnum3_t* num);
void mdnum3_asin_to(mdnum3_t* num, mdnum3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arccosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum3_t mdnum3_acos(mdnum3_t* num);
void mdnum3_acos_to(mdnum3_t* num, mdnum3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arctangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum3_t mdnum3_atan(mdnum3_t* num);
void mdnum3_atan_to(mdnum3_t* num, mdnum3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of the tangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum3_t mdnum3_tan(mdnum3_t* num);
void mdnum3_tan_to(mdnum3_t* num, mdnum3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of function cosine at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum3_t mdnum3_cos(mdnum3_t* num);
void mdnum3_cos_to(mdnum3_t* num, mdnum3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of function sine at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum3_t mdnum3_sin(mdnum3_t* num );
void mdnum3_sin_to(mdnum3_t* num, mdnum3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of Logarithm at base b function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum3_t mdnum3_logb(mdnum3_t* num, double base);
void mdnum3_logb_to(mdnum3_t* num, double base, mdnum3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of Logarithm at base 10 function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum3_t mdnum3_log10(mdnum3_t* num);
void mdnum3_log10_to(mdnum3_t* num, mdnum3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum3_t mdnum3_log(mdnum3_t* num);
void mdnum3_log_to(mdnum3_t* num, mdnum3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum3_t mdnum3_exp(mdnum3_t* num);
void mdnum3_exp_to(mdnum3_t* num, mdnum3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum3_t mdnum3_pow(mdnum3_t* num, double e);
void mdnum3_pow_to(mdnum3_t* num, coeff_t e, mdnum3_t* res);
// ----------------------------------------------------------------------------------------------------

#endif