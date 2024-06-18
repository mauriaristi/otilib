#ifndef OTI_ONUMM1N4_SCALAR_FUNCTIONS_H
#define OTI_ONUMM1N4_SCALAR_FUNCTIONS_H

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic tangent function at (num).

@param[in] num: Oti number.
@param[in] dhl: Direction helper list object.
******************************************************************************************************/ 
onumm1n4_t onumm1n4_atanh(onumm1n4_t* num);
void onumm1n4_atanh_to(onumm1n4_t* num, onumm1n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic sine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n4_t onumm1n4_asinh(onumm1n4_t* num);
void onumm1n4_asinh_to(onumm1n4_t* num, onumm1n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic cosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n4_t onumm1n4_acosh(onumm1n4_t* num);
void onumm1n4_acosh_to(onumm1n4_t* num, onumm1n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic tangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n4_t onumm1n4_tanh(onumm1n4_t* num);
void onumm1n4_tanh_to(onumm1n4_t* num, onumm1n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of square root function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n4_t onumm1n4_sqrt(onumm1n4_t* num);
void onumm1n4_sqrt_to(onumm1n4_t* num, onumm1n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of cubic root function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n4_t onumm1n4_cbrt(onumm1n4_t* num);
void onumm1n4_cbrt_to(onumm1n4_t* num, onumm1n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic cosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n4_t onumm1n4_cosh(onumm1n4_t* num);
void onumm1n4_cosh_to(onumm1n4_t* num, onumm1n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic sine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n4_t onumm1n4_sinh(onumm1n4_t* num);
void onumm1n4_sinh_to(onumm1n4_t* num, onumm1n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arcsine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n4_t onumm1n4_asin(onumm1n4_t* num);
void onumm1n4_asin_to(onumm1n4_t* num, onumm1n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arccosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n4_t onumm1n4_acos(onumm1n4_t* num);
void onumm1n4_acos_to(onumm1n4_t* num, onumm1n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arctangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n4_t onumm1n4_atan(onumm1n4_t* num);
void onumm1n4_atan_to(onumm1n4_t* num, onumm1n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of the tangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n4_t onumm1n4_tan(onumm1n4_t* num);
void onumm1n4_tan_to(onumm1n4_t* num, onumm1n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of function cosine at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n4_t onumm1n4_cos(onumm1n4_t* num);
void onumm1n4_cos_to(onumm1n4_t* num, onumm1n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of function sine at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n4_t onumm1n4_sin(onumm1n4_t* num );
void onumm1n4_sin_to(onumm1n4_t* num, onumm1n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of Logarithm at base b function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n4_t onumm1n4_logb(onumm1n4_t* num, double base);
void onumm1n4_logb_to(onumm1n4_t* num, double base, onumm1n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of Logarithm at base 10 function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n4_t onumm1n4_log10(onumm1n4_t* num);
void onumm1n4_log10_to(onumm1n4_t* num, onumm1n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n4_t onumm1n4_log(onumm1n4_t* num);
void onumm1n4_log_to(onumm1n4_t* num, onumm1n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n4_t onumm1n4_exp(onumm1n4_t* num);
void onumm1n4_exp_to(onumm1n4_t* num, onumm1n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n4_t onumm1n4_pow(onumm1n4_t* num, double e);
void onumm1n4_pow_to(onumm1n4_t* num, coeff_t e, onumm1n4_t* res);
// ----------------------------------------------------------------------------------------------------

#endif