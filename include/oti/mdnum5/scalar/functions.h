#ifndef OTI_MDNUM5_SCALAR_FUNCTIONS_H
#define OTI_MDNUM5_SCALAR_FUNCTIONS_H

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic tangent function at (num).

@param[in] num: Oti number.
@param[in] dhl: Direction helper list object.
******************************************************************************************************/ 
mdnum5_t mdnum5_atanh(mdnum5_t* num);
void mdnum5_atanh_to(mdnum5_t* num, mdnum5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic sine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum5_t mdnum5_asinh(mdnum5_t* num);
void mdnum5_asinh_to(mdnum5_t* num, mdnum5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic cosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum5_t mdnum5_acosh(mdnum5_t* num);
void mdnum5_acosh_to(mdnum5_t* num, mdnum5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic tangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum5_t mdnum5_tanh(mdnum5_t* num);
void mdnum5_tanh_to(mdnum5_t* num, mdnum5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of square root function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum5_t mdnum5_sqrt(mdnum5_t* num);
void mdnum5_sqrt_to(mdnum5_t* num, mdnum5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of cubic root function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum5_t mdnum5_cbrt(mdnum5_t* num);
void mdnum5_cbrt_to(mdnum5_t* num, mdnum5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic cosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum5_t mdnum5_cosh(mdnum5_t* num);
void mdnum5_cosh_to(mdnum5_t* num, mdnum5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic sine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum5_t mdnum5_sinh(mdnum5_t* num);
void mdnum5_sinh_to(mdnum5_t* num, mdnum5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arcsine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum5_t mdnum5_asin(mdnum5_t* num);
void mdnum5_asin_to(mdnum5_t* num, mdnum5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arccosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum5_t mdnum5_acos(mdnum5_t* num);
void mdnum5_acos_to(mdnum5_t* num, mdnum5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arctangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum5_t mdnum5_atan(mdnum5_t* num);
void mdnum5_atan_to(mdnum5_t* num, mdnum5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of the tangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum5_t mdnum5_tan(mdnum5_t* num);
void mdnum5_tan_to(mdnum5_t* num, mdnum5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of function cosine at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum5_t mdnum5_cos(mdnum5_t* num);
void mdnum5_cos_to(mdnum5_t* num, mdnum5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of function sine at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum5_t mdnum5_sin(mdnum5_t* num );
void mdnum5_sin_to(mdnum5_t* num, mdnum5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of Logarithm at base b function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum5_t mdnum5_logb(mdnum5_t* num, double base);
void mdnum5_logb_to(mdnum5_t* num, double base, mdnum5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of Logarithm at base 10 function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum5_t mdnum5_log10(mdnum5_t* num);
void mdnum5_log10_to(mdnum5_t* num, mdnum5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum5_t mdnum5_log(mdnum5_t* num);
void mdnum5_log_to(mdnum5_t* num, mdnum5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum5_t mdnum5_exp(mdnum5_t* num);
void mdnum5_exp_to(mdnum5_t* num, mdnum5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum5_t mdnum5_pow(mdnum5_t* num, double e);
void mdnum5_pow_to(mdnum5_t* num, coeff_t e, mdnum5_t* res);
// ----------------------------------------------------------------------------------------------------

#endif