#ifndef OTI_MDNUM8_SCALAR_FUNCTIONS_H
#define OTI_MDNUM8_SCALAR_FUNCTIONS_H

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic tangent function at (num).

@param[in] num: Oti number.
@param[in] dhl: Direction helper list object.
******************************************************************************************************/ 
mdnum8_t mdnum8_atanh(mdnum8_t* num);
void mdnum8_atanh_to(mdnum8_t* num, mdnum8_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic sine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum8_t mdnum8_asinh(mdnum8_t* num);
void mdnum8_asinh_to(mdnum8_t* num, mdnum8_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic cosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum8_t mdnum8_acosh(mdnum8_t* num);
void mdnum8_acosh_to(mdnum8_t* num, mdnum8_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic tangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum8_t mdnum8_tanh(mdnum8_t* num);
void mdnum8_tanh_to(mdnum8_t* num, mdnum8_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of square root function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum8_t mdnum8_sqrt(mdnum8_t* num);
void mdnum8_sqrt_to(mdnum8_t* num, mdnum8_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of cubic root function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum8_t mdnum8_cbrt(mdnum8_t* num);
void mdnum8_cbrt_to(mdnum8_t* num, mdnum8_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic cosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum8_t mdnum8_cosh(mdnum8_t* num);
void mdnum8_cosh_to(mdnum8_t* num, mdnum8_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic sine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum8_t mdnum8_sinh(mdnum8_t* num);
void mdnum8_sinh_to(mdnum8_t* num, mdnum8_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arcsine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum8_t mdnum8_asin(mdnum8_t* num);
void mdnum8_asin_to(mdnum8_t* num, mdnum8_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arccosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum8_t mdnum8_acos(mdnum8_t* num);
void mdnum8_acos_to(mdnum8_t* num, mdnum8_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arctangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum8_t mdnum8_atan(mdnum8_t* num);
void mdnum8_atan_to(mdnum8_t* num, mdnum8_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of the tangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum8_t mdnum8_tan(mdnum8_t* num);
void mdnum8_tan_to(mdnum8_t* num, mdnum8_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of function cosine at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum8_t mdnum8_cos(mdnum8_t* num);
void mdnum8_cos_to(mdnum8_t* num, mdnum8_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of function sine at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum8_t mdnum8_sin(mdnum8_t* num );
void mdnum8_sin_to(mdnum8_t* num, mdnum8_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of Logarithm at base b function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum8_t mdnum8_logb(mdnum8_t* num, double base);
void mdnum8_logb_to(mdnum8_t* num, double base, mdnum8_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of Logarithm at base 10 function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum8_t mdnum8_log10(mdnum8_t* num);
void mdnum8_log10_to(mdnum8_t* num, mdnum8_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum8_t mdnum8_log(mdnum8_t* num);
void mdnum8_log_to(mdnum8_t* num, mdnum8_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum8_t mdnum8_exp(mdnum8_t* num);
void mdnum8_exp_to(mdnum8_t* num, mdnum8_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum8_t mdnum8_pow(mdnum8_t* num, double e);
void mdnum8_pow_to(mdnum8_t* num, coeff_t e, mdnum8_t* res);
// ----------------------------------------------------------------------------------------------------

#endif