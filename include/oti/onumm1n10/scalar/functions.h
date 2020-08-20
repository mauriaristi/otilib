#ifndef OTI_ONUMM1N10_SCALAR_FUNCTIONS_H
#define OTI_ONUMM1N10_SCALAR_FUNCTIONS_H

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic tangent function at (num).

@param[in] num: Oti number.
@param[in] dhl: Direction helper list object.
******************************************************************************************************/ 
onumm1n10_t onumm1n10_atanh(onumm1n10_t* num);
void onumm1n10_atanh_to(onumm1n10_t* num, onumm1n10_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic sine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n10_t onumm1n10_asinh(onumm1n10_t* num);
void onumm1n10_asinh_to(onumm1n10_t* num, onumm1n10_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic cosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n10_t onumm1n10_acosh(onumm1n10_t* num);
void onumm1n10_acosh_to(onumm1n10_t* num, onumm1n10_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic tangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n10_t onumm1n10_tanh(onumm1n10_t* num);
void onumm1n10_tanh_to(onumm1n10_t* num, onumm1n10_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of square root function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n10_t onumm1n10_sqrt(onumm1n10_t* num);
void onumm1n10_sqrt_to(onumm1n10_t* num, onumm1n10_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of cubic root function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n10_t onumm1n10_cbrt(onumm1n10_t* num);
void onumm1n10_cbrt_to(onumm1n10_t* num, onumm1n10_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic cosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n10_t onumm1n10_cosh(onumm1n10_t* num);
void onumm1n10_cosh_to(onumm1n10_t* num, onumm1n10_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic sine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n10_t onumm1n10_sinh(onumm1n10_t* num);
void onumm1n10_sinh_to(onumm1n10_t* num, onumm1n10_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arcsine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n10_t onumm1n10_asin(onumm1n10_t* num);
void onumm1n10_asin_to(onumm1n10_t* num, onumm1n10_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arccosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n10_t onumm1n10_acos(onumm1n10_t* num);
void onumm1n10_acos_to(onumm1n10_t* num, onumm1n10_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arctangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n10_t onumm1n10_atan(onumm1n10_t* num);
void onumm1n10_atan_to(onumm1n10_t* num, onumm1n10_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of the tangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n10_t onumm1n10_tan(onumm1n10_t* num);
void onumm1n10_tan_to(onumm1n10_t* num, onumm1n10_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of function cosine at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n10_t onumm1n10_cos(onumm1n10_t* num);
void onumm1n10_cos_to(onumm1n10_t* num, onumm1n10_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of function sine at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n10_t onumm1n10_sin(onumm1n10_t* num );
void onumm1n10_sin_to(onumm1n10_t* num, onumm1n10_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of Logarithm at base b function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n10_t onumm1n10_logb(onumm1n10_t* num, double base);
void onumm1n10_logb_to(onumm1n10_t* num, double base, onumm1n10_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of Logarithm at base 10 function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n10_t onumm1n10_log10(onumm1n10_t* num);
void onumm1n10_log10_to(onumm1n10_t* num, onumm1n10_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n10_t onumm1n10_log(onumm1n10_t* num);
void onumm1n10_log_to(onumm1n10_t* num, onumm1n10_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n10_t onumm1n10_exp(onumm1n10_t* num);
void onumm1n10_exp_to(onumm1n10_t* num, onumm1n10_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n10_t onumm1n10_pow(onumm1n10_t* num, double e);
void onumm1n10_pow_to(onumm1n10_t* num, coeff_t e, onumm1n10_t* res);
// ----------------------------------------------------------------------------------------------------

#endif