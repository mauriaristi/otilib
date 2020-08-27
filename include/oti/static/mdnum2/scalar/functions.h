#ifndef OTI_MDNUM2_SCALAR_FUNCTIONS_H
#define OTI_MDNUM2_SCALAR_FUNCTIONS_H

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic tangent function at (num).

@param[in] num: Oti number.
@param[in] dhl: Direction helper list object.
******************************************************************************************************/ 
mdnum2_t mdnum2_atanh(mdnum2_t* num);
void mdnum2_atanh_to(mdnum2_t* num, mdnum2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic sine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum2_t mdnum2_asinh(mdnum2_t* num);
void mdnum2_asinh_to(mdnum2_t* num, mdnum2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic cosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum2_t mdnum2_acosh(mdnum2_t* num);
void mdnum2_acosh_to(mdnum2_t* num, mdnum2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic tangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum2_t mdnum2_tanh(mdnum2_t* num);
void mdnum2_tanh_to(mdnum2_t* num, mdnum2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of square root function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum2_t mdnum2_sqrt(mdnum2_t* num);
void mdnum2_sqrt_to(mdnum2_t* num, mdnum2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of cubic root function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum2_t mdnum2_cbrt(mdnum2_t* num);
void mdnum2_cbrt_to(mdnum2_t* num, mdnum2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic cosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum2_t mdnum2_cosh(mdnum2_t* num);
void mdnum2_cosh_to(mdnum2_t* num, mdnum2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic sine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum2_t mdnum2_sinh(mdnum2_t* num);
void mdnum2_sinh_to(mdnum2_t* num, mdnum2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arcsine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum2_t mdnum2_asin(mdnum2_t* num);
void mdnum2_asin_to(mdnum2_t* num, mdnum2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arccosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum2_t mdnum2_acos(mdnum2_t* num);
void mdnum2_acos_to(mdnum2_t* num, mdnum2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arctangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum2_t mdnum2_atan(mdnum2_t* num);
void mdnum2_atan_to(mdnum2_t* num, mdnum2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of the tangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum2_t mdnum2_tan(mdnum2_t* num);
void mdnum2_tan_to(mdnum2_t* num, mdnum2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of function cosine at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum2_t mdnum2_cos(mdnum2_t* num);
void mdnum2_cos_to(mdnum2_t* num, mdnum2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of function sine at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum2_t mdnum2_sin(mdnum2_t* num );
void mdnum2_sin_to(mdnum2_t* num, mdnum2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of Logarithm at base b function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum2_t mdnum2_logb(mdnum2_t* num, double base);
void mdnum2_logb_to(mdnum2_t* num, double base, mdnum2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of Logarithm at base 10 function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum2_t mdnum2_log10(mdnum2_t* num);
void mdnum2_log10_to(mdnum2_t* num, mdnum2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum2_t mdnum2_log(mdnum2_t* num);
void mdnum2_log_to(mdnum2_t* num, mdnum2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum2_t mdnum2_exp(mdnum2_t* num);
void mdnum2_exp_to(mdnum2_t* num, mdnum2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum2_t mdnum2_pow(mdnum2_t* num, double e);
void mdnum2_pow_to(mdnum2_t* num, coeff_t e, mdnum2_t* res);
// ----------------------------------------------------------------------------------------------------

#endif