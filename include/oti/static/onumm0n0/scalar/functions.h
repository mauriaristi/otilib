#ifndef OTI_ONUMM0N0_SCALAR_FUNCTIONS_H
#define OTI_ONUMM0N0_SCALAR_FUNCTIONS_H

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic tangent function at (num).

@param[in] num: Oti number.
@param[in] dhl: Direction helper list object.
******************************************************************************************************/ 
onumm0n0_t onumm0n0_atanh(onumm0n0_t* num);
void onumm0n0_atanh_to(onumm0n0_t* num, onumm0n0_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic sine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm0n0_t onumm0n0_asinh(onumm0n0_t* num);
void onumm0n0_asinh_to(onumm0n0_t* num, onumm0n0_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic cosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm0n0_t onumm0n0_acosh(onumm0n0_t* num);
void onumm0n0_acosh_to(onumm0n0_t* num, onumm0n0_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic tangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm0n0_t onumm0n0_tanh(onumm0n0_t* num);
void onumm0n0_tanh_to(onumm0n0_t* num, onumm0n0_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of square root function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm0n0_t onumm0n0_sqrt(onumm0n0_t* num);
void onumm0n0_sqrt_to(onumm0n0_t* num, onumm0n0_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of cubic root function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm0n0_t onumm0n0_cbrt(onumm0n0_t* num);
void onumm0n0_cbrt_to(onumm0n0_t* num, onumm0n0_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic cosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm0n0_t onumm0n0_cosh(onumm0n0_t* num);
void onumm0n0_cosh_to(onumm0n0_t* num, onumm0n0_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic sine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm0n0_t onumm0n0_sinh(onumm0n0_t* num);
void onumm0n0_sinh_to(onumm0n0_t* num, onumm0n0_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arcsine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm0n0_t onumm0n0_asin(onumm0n0_t* num);
void onumm0n0_asin_to(onumm0n0_t* num, onumm0n0_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arccosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm0n0_t onumm0n0_acos(onumm0n0_t* num);
void onumm0n0_acos_to(onumm0n0_t* num, onumm0n0_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arctangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm0n0_t onumm0n0_atan(onumm0n0_t* num);
void onumm0n0_atan_to(onumm0n0_t* num, onumm0n0_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of the tangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm0n0_t onumm0n0_tan(onumm0n0_t* num);
void onumm0n0_tan_to(onumm0n0_t* num, onumm0n0_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of function cosine at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm0n0_t onumm0n0_cos(onumm0n0_t* num);
void onumm0n0_cos_to(onumm0n0_t* num, onumm0n0_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of function sine at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm0n0_t onumm0n0_sin(onumm0n0_t* num );
void onumm0n0_sin_to(onumm0n0_t* num, onumm0n0_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of Logarithm at base b function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm0n0_t onumm0n0_logb(onumm0n0_t* num, double base);
void onumm0n0_logb_to(onumm0n0_t* num, double base, onumm0n0_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of Logarithm at base 10 function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm0n0_t onumm0n0_log10(onumm0n0_t* num);
void onumm0n0_log10_to(onumm0n0_t* num, onumm0n0_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm0n0_t onumm0n0_log(onumm0n0_t* num);
void onumm0n0_log_to(onumm0n0_t* num, onumm0n0_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm0n0_t onumm0n0_exp(onumm0n0_t* num);
void onumm0n0_exp_to(onumm0n0_t* num, onumm0n0_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm0n0_t onumm0n0_pow(onumm0n0_t* num, double e);
void onumm0n0_pow_to(onumm0n0_t* num, coeff_t e, onumm0n0_t* res);
// ----------------------------------------------------------------------------------------------------

#endif