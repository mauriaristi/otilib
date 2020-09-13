#ifndef OTI_MDNUM7_SCALAR_FUNCTIONS_H
#define OTI_MDNUM7_SCALAR_FUNCTIONS_H

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic tangent function at (num).

@param[in] num: Oti number.
@param[in] dhl: Direction helper list object.
******************************************************************************************************/ 
mdnum7_t mdnum7_atanh(mdnum7_t* num);
void mdnum7_atanh_to(mdnum7_t* num, mdnum7_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic sine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum7_t mdnum7_asinh(mdnum7_t* num);
void mdnum7_asinh_to(mdnum7_t* num, mdnum7_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic cosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum7_t mdnum7_acosh(mdnum7_t* num);
void mdnum7_acosh_to(mdnum7_t* num, mdnum7_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic tangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum7_t mdnum7_tanh(mdnum7_t* num);
void mdnum7_tanh_to(mdnum7_t* num, mdnum7_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of square root function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum7_t mdnum7_sqrt(mdnum7_t* num);
void mdnum7_sqrt_to(mdnum7_t* num, mdnum7_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of cubic root function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum7_t mdnum7_cbrt(mdnum7_t* num);
void mdnum7_cbrt_to(mdnum7_t* num, mdnum7_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic cosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum7_t mdnum7_cosh(mdnum7_t* num);
void mdnum7_cosh_to(mdnum7_t* num, mdnum7_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic sine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum7_t mdnum7_sinh(mdnum7_t* num);
void mdnum7_sinh_to(mdnum7_t* num, mdnum7_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arcsine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum7_t mdnum7_asin(mdnum7_t* num);
void mdnum7_asin_to(mdnum7_t* num, mdnum7_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arccosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum7_t mdnum7_acos(mdnum7_t* num);
void mdnum7_acos_to(mdnum7_t* num, mdnum7_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arctangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum7_t mdnum7_atan(mdnum7_t* num);
void mdnum7_atan_to(mdnum7_t* num, mdnum7_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of the tangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum7_t mdnum7_tan(mdnum7_t* num);
void mdnum7_tan_to(mdnum7_t* num, mdnum7_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of function cosine at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum7_t mdnum7_cos(mdnum7_t* num);
void mdnum7_cos_to(mdnum7_t* num, mdnum7_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of function sine at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum7_t mdnum7_sin(mdnum7_t* num );
void mdnum7_sin_to(mdnum7_t* num, mdnum7_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of Logarithm at base b function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum7_t mdnum7_logb(mdnum7_t* num, double base);
void mdnum7_logb_to(mdnum7_t* num, double base, mdnum7_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of Logarithm at base 10 function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum7_t mdnum7_log10(mdnum7_t* num);
void mdnum7_log10_to(mdnum7_t* num, mdnum7_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum7_t mdnum7_log(mdnum7_t* num);
void mdnum7_log_to(mdnum7_t* num, mdnum7_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum7_t mdnum7_exp(mdnum7_t* num);
void mdnum7_exp_to(mdnum7_t* num, mdnum7_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum7_t mdnum7_pow(mdnum7_t* num, double e);
void mdnum7_pow_to(mdnum7_t* num, coeff_t e, mdnum7_t* res);
// ----------------------------------------------------------------------------------------------------

#endif