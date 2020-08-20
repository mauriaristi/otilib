#ifndef OTI_MDNUM4_SCALAR_FUNCTIONS_H
#define OTI_MDNUM4_SCALAR_FUNCTIONS_H

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic tangent function at (num).

@param[in] num: Oti number.
@param[in] dhl: Direction helper list object.
******************************************************************************************************/ 
mdnum4_t mdnum4_atanh(mdnum4_t* num);
void mdnum4_atanh_to(mdnum4_t* num, mdnum4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic sine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum4_t mdnum4_asinh(mdnum4_t* num);
void mdnum4_asinh_to(mdnum4_t* num, mdnum4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic cosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum4_t mdnum4_acosh(mdnum4_t* num);
void mdnum4_acosh_to(mdnum4_t* num, mdnum4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic tangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum4_t mdnum4_tanh(mdnum4_t* num);
void mdnum4_tanh_to(mdnum4_t* num, mdnum4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of square root function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum4_t mdnum4_sqrt(mdnum4_t* num);
void mdnum4_sqrt_to(mdnum4_t* num, mdnum4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of cubic root function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum4_t mdnum4_cbrt(mdnum4_t* num);
void mdnum4_cbrt_to(mdnum4_t* num, mdnum4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic cosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum4_t mdnum4_cosh(mdnum4_t* num);
void mdnum4_cosh_to(mdnum4_t* num, mdnum4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic sine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum4_t mdnum4_sinh(mdnum4_t* num);
void mdnum4_sinh_to(mdnum4_t* num, mdnum4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arcsine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum4_t mdnum4_asin(mdnum4_t* num);
void mdnum4_asin_to(mdnum4_t* num, mdnum4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arccosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum4_t mdnum4_acos(mdnum4_t* num);
void mdnum4_acos_to(mdnum4_t* num, mdnum4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arctangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum4_t mdnum4_atan(mdnum4_t* num);
void mdnum4_atan_to(mdnum4_t* num, mdnum4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of the tangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum4_t mdnum4_tan(mdnum4_t* num);
void mdnum4_tan_to(mdnum4_t* num, mdnum4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of function cosine at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum4_t mdnum4_cos(mdnum4_t* num);
void mdnum4_cos_to(mdnum4_t* num, mdnum4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of function sine at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum4_t mdnum4_sin(mdnum4_t* num );
void mdnum4_sin_to(mdnum4_t* num, mdnum4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of Logarithm at base b function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum4_t mdnum4_logb(mdnum4_t* num, double base);
void mdnum4_logb_to(mdnum4_t* num, double base, mdnum4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of Logarithm at base 10 function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum4_t mdnum4_log10(mdnum4_t* num);
void mdnum4_log10_to(mdnum4_t* num, mdnum4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum4_t mdnum4_log(mdnum4_t* num);
void mdnum4_log_to(mdnum4_t* num, mdnum4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum4_t mdnum4_exp(mdnum4_t* num);
void mdnum4_exp_to(mdnum4_t* num, mdnum4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum4_t mdnum4_pow(mdnum4_t* num, double e);
void mdnum4_pow_to(mdnum4_t* num, coeff_t e, mdnum4_t* res);
// ----------------------------------------------------------------------------------------------------

#endif