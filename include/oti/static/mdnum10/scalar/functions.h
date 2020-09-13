#ifndef OTI_MDNUM10_SCALAR_FUNCTIONS_H
#define OTI_MDNUM10_SCALAR_FUNCTIONS_H

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic tangent function at (num).

@param[in] num: Oti number.
@param[in] dhl: Direction helper list object.
******************************************************************************************************/ 
mdnum10_t mdnum10_atanh(mdnum10_t* num);
void mdnum10_atanh_to(mdnum10_t* num, mdnum10_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic sine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum10_t mdnum10_asinh(mdnum10_t* num);
void mdnum10_asinh_to(mdnum10_t* num, mdnum10_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic cosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum10_t mdnum10_acosh(mdnum10_t* num);
void mdnum10_acosh_to(mdnum10_t* num, mdnum10_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic tangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum10_t mdnum10_tanh(mdnum10_t* num);
void mdnum10_tanh_to(mdnum10_t* num, mdnum10_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of square root function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum10_t mdnum10_sqrt(mdnum10_t* num);
void mdnum10_sqrt_to(mdnum10_t* num, mdnum10_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of cubic root function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum10_t mdnum10_cbrt(mdnum10_t* num);
void mdnum10_cbrt_to(mdnum10_t* num, mdnum10_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic cosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum10_t mdnum10_cosh(mdnum10_t* num);
void mdnum10_cosh_to(mdnum10_t* num, mdnum10_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic sine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum10_t mdnum10_sinh(mdnum10_t* num);
void mdnum10_sinh_to(mdnum10_t* num, mdnum10_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arcsine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum10_t mdnum10_asin(mdnum10_t* num);
void mdnum10_asin_to(mdnum10_t* num, mdnum10_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arccosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum10_t mdnum10_acos(mdnum10_t* num);
void mdnum10_acos_to(mdnum10_t* num, mdnum10_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arctangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum10_t mdnum10_atan(mdnum10_t* num);
void mdnum10_atan_to(mdnum10_t* num, mdnum10_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of the tangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum10_t mdnum10_tan(mdnum10_t* num);
void mdnum10_tan_to(mdnum10_t* num, mdnum10_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of function cosine at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum10_t mdnum10_cos(mdnum10_t* num);
void mdnum10_cos_to(mdnum10_t* num, mdnum10_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of function sine at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum10_t mdnum10_sin(mdnum10_t* num );
void mdnum10_sin_to(mdnum10_t* num, mdnum10_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of Logarithm at base b function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum10_t mdnum10_logb(mdnum10_t* num, double base);
void mdnum10_logb_to(mdnum10_t* num, double base, mdnum10_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of Logarithm at base 10 function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum10_t mdnum10_log10(mdnum10_t* num);
void mdnum10_log10_to(mdnum10_t* num, mdnum10_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum10_t mdnum10_log(mdnum10_t* num);
void mdnum10_log_to(mdnum10_t* num, mdnum10_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum10_t mdnum10_exp(mdnum10_t* num);
void mdnum10_exp_to(mdnum10_t* num, mdnum10_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum10_t mdnum10_pow(mdnum10_t* num, double e);
void mdnum10_pow_to(mdnum10_t* num, coeff_t e, mdnum10_t* res);
// ----------------------------------------------------------------------------------------------------

#endif