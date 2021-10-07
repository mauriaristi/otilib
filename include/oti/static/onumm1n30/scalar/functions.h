#ifndef OTI_ONUMM1N30_SCALAR_FUNCTIONS_H
#define OTI_ONUMM1N30_SCALAR_FUNCTIONS_H

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic tangent function at (num).

@param[in] num: Oti number.
@param[in] dhl: Direction helper list object.
******************************************************************************************************/ 
onumm1n30_t onumm1n30_atanh(onumm1n30_t* num);
void onumm1n30_atanh_to(onumm1n30_t* num, onumm1n30_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic sine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n30_t onumm1n30_asinh(onumm1n30_t* num);
void onumm1n30_asinh_to(onumm1n30_t* num, onumm1n30_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic cosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n30_t onumm1n30_acosh(onumm1n30_t* num);
void onumm1n30_acosh_to(onumm1n30_t* num, onumm1n30_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic tangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n30_t onumm1n30_tanh(onumm1n30_t* num);
void onumm1n30_tanh_to(onumm1n30_t* num, onumm1n30_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of square root function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n30_t onumm1n30_sqrt(onumm1n30_t* num);
void onumm1n30_sqrt_to(onumm1n30_t* num, onumm1n30_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of cubic root function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n30_t onumm1n30_cbrt(onumm1n30_t* num);
void onumm1n30_cbrt_to(onumm1n30_t* num, onumm1n30_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic cosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n30_t onumm1n30_cosh(onumm1n30_t* num);
void onumm1n30_cosh_to(onumm1n30_t* num, onumm1n30_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic sine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n30_t onumm1n30_sinh(onumm1n30_t* num);
void onumm1n30_sinh_to(onumm1n30_t* num, onumm1n30_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arcsine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n30_t onumm1n30_asin(onumm1n30_t* num);
void onumm1n30_asin_to(onumm1n30_t* num, onumm1n30_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arccosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n30_t onumm1n30_acos(onumm1n30_t* num);
void onumm1n30_acos_to(onumm1n30_t* num, onumm1n30_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arctangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n30_t onumm1n30_atan(onumm1n30_t* num);
void onumm1n30_atan_to(onumm1n30_t* num, onumm1n30_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of the tangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n30_t onumm1n30_tan(onumm1n30_t* num);
void onumm1n30_tan_to(onumm1n30_t* num, onumm1n30_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of function cosine at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n30_t onumm1n30_cos(onumm1n30_t* num);
void onumm1n30_cos_to(onumm1n30_t* num, onumm1n30_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of function sine at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n30_t onumm1n30_sin(onumm1n30_t* num );
void onumm1n30_sin_to(onumm1n30_t* num, onumm1n30_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of Logarithm at base b function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n30_t onumm1n30_logb(onumm1n30_t* num, double base);
void onumm1n30_logb_to(onumm1n30_t* num, double base, onumm1n30_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of Logarithm at base 10 function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n30_t onumm1n30_log10(onumm1n30_t* num);
void onumm1n30_log10_to(onumm1n30_t* num, onumm1n30_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n30_t onumm1n30_log(onumm1n30_t* num);
void onumm1n30_log_to(onumm1n30_t* num, onumm1n30_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n30_t onumm1n30_exp(onumm1n30_t* num);
void onumm1n30_exp_to(onumm1n30_t* num, onumm1n30_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n30_t onumm1n30_pow(onumm1n30_t* num, double e);
void onumm1n30_pow_to(onumm1n30_t* num, coeff_t e, onumm1n30_t* res);
// ----------------------------------------------------------------------------------------------------

#endif