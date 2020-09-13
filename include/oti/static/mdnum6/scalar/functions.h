#ifndef OTI_MDNUM6_SCALAR_FUNCTIONS_H
#define OTI_MDNUM6_SCALAR_FUNCTIONS_H

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic tangent function at (num).

@param[in] num: Oti number.
@param[in] dhl: Direction helper list object.
******************************************************************************************************/ 
mdnum6_t mdnum6_atanh(mdnum6_t* num);
void mdnum6_atanh_to(mdnum6_t* num, mdnum6_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic sine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum6_t mdnum6_asinh(mdnum6_t* num);
void mdnum6_asinh_to(mdnum6_t* num, mdnum6_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic cosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum6_t mdnum6_acosh(mdnum6_t* num);
void mdnum6_acosh_to(mdnum6_t* num, mdnum6_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic tangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum6_t mdnum6_tanh(mdnum6_t* num);
void mdnum6_tanh_to(mdnum6_t* num, mdnum6_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of square root function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum6_t mdnum6_sqrt(mdnum6_t* num);
void mdnum6_sqrt_to(mdnum6_t* num, mdnum6_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of cubic root function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum6_t mdnum6_cbrt(mdnum6_t* num);
void mdnum6_cbrt_to(mdnum6_t* num, mdnum6_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic cosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum6_t mdnum6_cosh(mdnum6_t* num);
void mdnum6_cosh_to(mdnum6_t* num, mdnum6_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic sine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum6_t mdnum6_sinh(mdnum6_t* num);
void mdnum6_sinh_to(mdnum6_t* num, mdnum6_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arcsine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum6_t mdnum6_asin(mdnum6_t* num);
void mdnum6_asin_to(mdnum6_t* num, mdnum6_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arccosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum6_t mdnum6_acos(mdnum6_t* num);
void mdnum6_acos_to(mdnum6_t* num, mdnum6_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arctangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum6_t mdnum6_atan(mdnum6_t* num);
void mdnum6_atan_to(mdnum6_t* num, mdnum6_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of the tangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum6_t mdnum6_tan(mdnum6_t* num);
void mdnum6_tan_to(mdnum6_t* num, mdnum6_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of function cosine at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum6_t mdnum6_cos(mdnum6_t* num);
void mdnum6_cos_to(mdnum6_t* num, mdnum6_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of function sine at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum6_t mdnum6_sin(mdnum6_t* num );
void mdnum6_sin_to(mdnum6_t* num, mdnum6_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of Logarithm at base b function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum6_t mdnum6_logb(mdnum6_t* num, double base);
void mdnum6_logb_to(mdnum6_t* num, double base, mdnum6_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of Logarithm at base 10 function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum6_t mdnum6_log10(mdnum6_t* num);
void mdnum6_log10_to(mdnum6_t* num, mdnum6_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum6_t mdnum6_log(mdnum6_t* num);
void mdnum6_log_to(mdnum6_t* num, mdnum6_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum6_t mdnum6_exp(mdnum6_t* num);
void mdnum6_exp_to(mdnum6_t* num, mdnum6_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum6_t mdnum6_pow(mdnum6_t* num, double e);
void mdnum6_pow_to(mdnum6_t* num, coeff_t e, mdnum6_t* res);
// ----------------------------------------------------------------------------------------------------

#endif