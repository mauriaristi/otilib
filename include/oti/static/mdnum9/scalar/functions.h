#ifndef OTI_MDNUM9_SCALAR_FUNCTIONS_H
#define OTI_MDNUM9_SCALAR_FUNCTIONS_H

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic tangent function at (num).

@param[in] num: Oti number.
@param[in] dhl: Direction helper list object.
******************************************************************************************************/ 
mdnum9_t mdnum9_atanh(mdnum9_t* num);
void mdnum9_atanh_to(mdnum9_t* num, mdnum9_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic sine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum9_t mdnum9_asinh(mdnum9_t* num);
void mdnum9_asinh_to(mdnum9_t* num, mdnum9_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic cosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum9_t mdnum9_acosh(mdnum9_t* num);
void mdnum9_acosh_to(mdnum9_t* num, mdnum9_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic tangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum9_t mdnum9_tanh(mdnum9_t* num);
void mdnum9_tanh_to(mdnum9_t* num, mdnum9_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of square root function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum9_t mdnum9_sqrt(mdnum9_t* num);
void mdnum9_sqrt_to(mdnum9_t* num, mdnum9_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of cubic root function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum9_t mdnum9_cbrt(mdnum9_t* num);
void mdnum9_cbrt_to(mdnum9_t* num, mdnum9_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic cosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum9_t mdnum9_cosh(mdnum9_t* num);
void mdnum9_cosh_to(mdnum9_t* num, mdnum9_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic sine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum9_t mdnum9_sinh(mdnum9_t* num);
void mdnum9_sinh_to(mdnum9_t* num, mdnum9_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arcsine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum9_t mdnum9_asin(mdnum9_t* num);
void mdnum9_asin_to(mdnum9_t* num, mdnum9_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arccosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum9_t mdnum9_acos(mdnum9_t* num);
void mdnum9_acos_to(mdnum9_t* num, mdnum9_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arctangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum9_t mdnum9_atan(mdnum9_t* num);
void mdnum9_atan_to(mdnum9_t* num, mdnum9_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of the tangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum9_t mdnum9_tan(mdnum9_t* num);
void mdnum9_tan_to(mdnum9_t* num, mdnum9_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of function cosine at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum9_t mdnum9_cos(mdnum9_t* num);
void mdnum9_cos_to(mdnum9_t* num, mdnum9_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of function sine at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum9_t mdnum9_sin(mdnum9_t* num );
void mdnum9_sin_to(mdnum9_t* num, mdnum9_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of Logarithm at base b function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum9_t mdnum9_logb(mdnum9_t* num, double base);
void mdnum9_logb_to(mdnum9_t* num, double base, mdnum9_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of Logarithm at base 10 function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum9_t mdnum9_log10(mdnum9_t* num);
void mdnum9_log10_to(mdnum9_t* num, mdnum9_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum9_t mdnum9_log(mdnum9_t* num);
void mdnum9_log_to(mdnum9_t* num, mdnum9_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum9_t mdnum9_exp(mdnum9_t* num);
void mdnum9_exp_to(mdnum9_t* num, mdnum9_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum9_t mdnum9_pow(mdnum9_t* num, double e);
void mdnum9_pow_to(mdnum9_t* num, coeff_t e, mdnum9_t* res);
// ----------------------------------------------------------------------------------------------------

#endif