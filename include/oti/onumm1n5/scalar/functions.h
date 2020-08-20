#ifndef OTI_ONUMM1N5_SCALAR_FUNCTIONS_H
#define OTI_ONUMM1N5_SCALAR_FUNCTIONS_H

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic tangent function at (num).

@param[in] num: Oti number.
@param[in] dhl: Direction helper list object.
******************************************************************************************************/ 
onumm1n5_t onumm1n5_atanh(onumm1n5_t* num);
void onumm1n5_atanh_to(onumm1n5_t* num, onumm1n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic sine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n5_t onumm1n5_asinh(onumm1n5_t* num);
void onumm1n5_asinh_to(onumm1n5_t* num, onumm1n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic cosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n5_t onumm1n5_acosh(onumm1n5_t* num);
void onumm1n5_acosh_to(onumm1n5_t* num, onumm1n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic tangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n5_t onumm1n5_tanh(onumm1n5_t* num);
void onumm1n5_tanh_to(onumm1n5_t* num, onumm1n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of square root function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n5_t onumm1n5_sqrt(onumm1n5_t* num);
void onumm1n5_sqrt_to(onumm1n5_t* num, onumm1n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of cubic root function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n5_t onumm1n5_cbrt(onumm1n5_t* num);
void onumm1n5_cbrt_to(onumm1n5_t* num, onumm1n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic cosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n5_t onumm1n5_cosh(onumm1n5_t* num);
void onumm1n5_cosh_to(onumm1n5_t* num, onumm1n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic sine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n5_t onumm1n5_sinh(onumm1n5_t* num);
void onumm1n5_sinh_to(onumm1n5_t* num, onumm1n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arcsine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n5_t onumm1n5_asin(onumm1n5_t* num);
void onumm1n5_asin_to(onumm1n5_t* num, onumm1n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arccosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n5_t onumm1n5_acos(onumm1n5_t* num);
void onumm1n5_acos_to(onumm1n5_t* num, onumm1n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arctangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n5_t onumm1n5_atan(onumm1n5_t* num);
void onumm1n5_atan_to(onumm1n5_t* num, onumm1n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of the tangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n5_t onumm1n5_tan(onumm1n5_t* num);
void onumm1n5_tan_to(onumm1n5_t* num, onumm1n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of function cosine at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n5_t onumm1n5_cos(onumm1n5_t* num);
void onumm1n5_cos_to(onumm1n5_t* num, onumm1n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of function sine at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n5_t onumm1n5_sin(onumm1n5_t* num );
void onumm1n5_sin_to(onumm1n5_t* num, onumm1n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of Logarithm at base b function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n5_t onumm1n5_logb(onumm1n5_t* num, double base);
void onumm1n5_logb_to(onumm1n5_t* num, double base, onumm1n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of Logarithm at base 10 function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n5_t onumm1n5_log10(onumm1n5_t* num);
void onumm1n5_log10_to(onumm1n5_t* num, onumm1n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n5_t onumm1n5_log(onumm1n5_t* num);
void onumm1n5_log_to(onumm1n5_t* num, onumm1n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n5_t onumm1n5_exp(onumm1n5_t* num);
void onumm1n5_exp_to(onumm1n5_t* num, onumm1n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n5_t onumm1n5_pow(onumm1n5_t* num, double e);
void onumm1n5_pow_to(onumm1n5_t* num, coeff_t e, onumm1n5_t* res);
// ----------------------------------------------------------------------------------------------------

#endif