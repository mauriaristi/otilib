#ifndef OTI_ONUMM1N6_SCALAR_FUNCTIONS_H
#define OTI_ONUMM1N6_SCALAR_FUNCTIONS_H

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic tangent function at (num).

@param[in] num: Oti number.
@param[in] dhl: Direction helper list object.
******************************************************************************************************/ 
onumm1n6_t onumm1n6_atanh(onumm1n6_t* num);
void onumm1n6_atanh_to(onumm1n6_t* num, onumm1n6_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic sine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n6_t onumm1n6_asinh(onumm1n6_t* num);
void onumm1n6_asinh_to(onumm1n6_t* num, onumm1n6_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic cosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n6_t onumm1n6_acosh(onumm1n6_t* num);
void onumm1n6_acosh_to(onumm1n6_t* num, onumm1n6_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic tangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n6_t onumm1n6_tanh(onumm1n6_t* num);
void onumm1n6_tanh_to(onumm1n6_t* num, onumm1n6_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of square root function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n6_t onumm1n6_sqrt(onumm1n6_t* num);
void onumm1n6_sqrt_to(onumm1n6_t* num, onumm1n6_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of cubic root function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n6_t onumm1n6_cbrt(onumm1n6_t* num);
void onumm1n6_cbrt_to(onumm1n6_t* num, onumm1n6_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic cosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n6_t onumm1n6_cosh(onumm1n6_t* num);
void onumm1n6_cosh_to(onumm1n6_t* num, onumm1n6_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic sine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n6_t onumm1n6_sinh(onumm1n6_t* num);
void onumm1n6_sinh_to(onumm1n6_t* num, onumm1n6_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arcsine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n6_t onumm1n6_asin(onumm1n6_t* num);
void onumm1n6_asin_to(onumm1n6_t* num, onumm1n6_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arccosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n6_t onumm1n6_acos(onumm1n6_t* num);
void onumm1n6_acos_to(onumm1n6_t* num, onumm1n6_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arctangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n6_t onumm1n6_atan(onumm1n6_t* num);
void onumm1n6_atan_to(onumm1n6_t* num, onumm1n6_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of the tangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n6_t onumm1n6_tan(onumm1n6_t* num);
void onumm1n6_tan_to(onumm1n6_t* num, onumm1n6_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of function cosine at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n6_t onumm1n6_cos(onumm1n6_t* num);
void onumm1n6_cos_to(onumm1n6_t* num, onumm1n6_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of function sine at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n6_t onumm1n6_sin(onumm1n6_t* num );
void onumm1n6_sin_to(onumm1n6_t* num, onumm1n6_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of Logarithm at base b function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n6_t onumm1n6_logb(onumm1n6_t* num, double base);
void onumm1n6_logb_to(onumm1n6_t* num, double base, onumm1n6_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of Logarithm at base 10 function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n6_t onumm1n6_log10(onumm1n6_t* num);
void onumm1n6_log10_to(onumm1n6_t* num, onumm1n6_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n6_t onumm1n6_log(onumm1n6_t* num);
void onumm1n6_log_to(onumm1n6_t* num, onumm1n6_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n6_t onumm1n6_exp(onumm1n6_t* num);
void onumm1n6_exp_to(onumm1n6_t* num, onumm1n6_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n6_t onumm1n6_pow(onumm1n6_t* num, double e);
void onumm1n6_pow_to(onumm1n6_t* num, coeff_t e, onumm1n6_t* res);
// ----------------------------------------------------------------------------------------------------

#endif