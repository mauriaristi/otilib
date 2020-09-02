#ifndef OTI_ONUMM1N8_SCALAR_FUNCTIONS_H
#define OTI_ONUMM1N8_SCALAR_FUNCTIONS_H

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic tangent function at (num).

@param[in] num: Oti number.
@param[in] dhl: Direction helper list object.
******************************************************************************************************/ 
onumm1n8_t onumm1n8_atanh(onumm1n8_t* num);
void onumm1n8_atanh_to(onumm1n8_t* num, onumm1n8_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic sine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n8_t onumm1n8_asinh(onumm1n8_t* num);
void onumm1n8_asinh_to(onumm1n8_t* num, onumm1n8_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic cosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n8_t onumm1n8_acosh(onumm1n8_t* num);
void onumm1n8_acosh_to(onumm1n8_t* num, onumm1n8_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic tangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n8_t onumm1n8_tanh(onumm1n8_t* num);
void onumm1n8_tanh_to(onumm1n8_t* num, onumm1n8_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of square root function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n8_t onumm1n8_sqrt(onumm1n8_t* num);
void onumm1n8_sqrt_to(onumm1n8_t* num, onumm1n8_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of cubic root function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n8_t onumm1n8_cbrt(onumm1n8_t* num);
void onumm1n8_cbrt_to(onumm1n8_t* num, onumm1n8_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic cosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n8_t onumm1n8_cosh(onumm1n8_t* num);
void onumm1n8_cosh_to(onumm1n8_t* num, onumm1n8_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic sine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n8_t onumm1n8_sinh(onumm1n8_t* num);
void onumm1n8_sinh_to(onumm1n8_t* num, onumm1n8_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arcsine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n8_t onumm1n8_asin(onumm1n8_t* num);
void onumm1n8_asin_to(onumm1n8_t* num, onumm1n8_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arccosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n8_t onumm1n8_acos(onumm1n8_t* num);
void onumm1n8_acos_to(onumm1n8_t* num, onumm1n8_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arctangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n8_t onumm1n8_atan(onumm1n8_t* num);
void onumm1n8_atan_to(onumm1n8_t* num, onumm1n8_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of the tangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n8_t onumm1n8_tan(onumm1n8_t* num);
void onumm1n8_tan_to(onumm1n8_t* num, onumm1n8_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of function cosine at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n8_t onumm1n8_cos(onumm1n8_t* num);
void onumm1n8_cos_to(onumm1n8_t* num, onumm1n8_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of function sine at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n8_t onumm1n8_sin(onumm1n8_t* num );
void onumm1n8_sin_to(onumm1n8_t* num, onumm1n8_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of Logarithm at base b function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n8_t onumm1n8_logb(onumm1n8_t* num, double base);
void onumm1n8_logb_to(onumm1n8_t* num, double base, onumm1n8_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of Logarithm at base 10 function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n8_t onumm1n8_log10(onumm1n8_t* num);
void onumm1n8_log10_to(onumm1n8_t* num, onumm1n8_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n8_t onumm1n8_log(onumm1n8_t* num);
void onumm1n8_log_to(onumm1n8_t* num, onumm1n8_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n8_t onumm1n8_exp(onumm1n8_t* num);
void onumm1n8_exp_to(onumm1n8_t* num, onumm1n8_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n8_t onumm1n8_pow(onumm1n8_t* num, double e);
void onumm1n8_pow_to(onumm1n8_t* num, coeff_t e, onumm1n8_t* res);
// ----------------------------------------------------------------------------------------------------

#endif