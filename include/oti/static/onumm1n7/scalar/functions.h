#ifndef OTI_ONUMM1N7_SCALAR_FUNCTIONS_H
#define OTI_ONUMM1N7_SCALAR_FUNCTIONS_H

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic tangent function at (num).

@param[in] num: Oti number.
@param[in] dhl: Direction helper list object.
******************************************************************************************************/ 
onumm1n7_t onumm1n7_atanh(onumm1n7_t* num);
void onumm1n7_atanh_to(onumm1n7_t* num, onumm1n7_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic sine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n7_t onumm1n7_asinh(onumm1n7_t* num);
void onumm1n7_asinh_to(onumm1n7_t* num, onumm1n7_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic cosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n7_t onumm1n7_acosh(onumm1n7_t* num);
void onumm1n7_acosh_to(onumm1n7_t* num, onumm1n7_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic tangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n7_t onumm1n7_tanh(onumm1n7_t* num);
void onumm1n7_tanh_to(onumm1n7_t* num, onumm1n7_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of square root function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n7_t onumm1n7_sqrt(onumm1n7_t* num);
void onumm1n7_sqrt_to(onumm1n7_t* num, onumm1n7_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of cubic root function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n7_t onumm1n7_cbrt(onumm1n7_t* num);
void onumm1n7_cbrt_to(onumm1n7_t* num, onumm1n7_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic cosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n7_t onumm1n7_cosh(onumm1n7_t* num);
void onumm1n7_cosh_to(onumm1n7_t* num, onumm1n7_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic sine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n7_t onumm1n7_sinh(onumm1n7_t* num);
void onumm1n7_sinh_to(onumm1n7_t* num, onumm1n7_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arcsine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n7_t onumm1n7_asin(onumm1n7_t* num);
void onumm1n7_asin_to(onumm1n7_t* num, onumm1n7_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arccosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n7_t onumm1n7_acos(onumm1n7_t* num);
void onumm1n7_acos_to(onumm1n7_t* num, onumm1n7_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arctangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n7_t onumm1n7_atan(onumm1n7_t* num);
void onumm1n7_atan_to(onumm1n7_t* num, onumm1n7_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of the tangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n7_t onumm1n7_tan(onumm1n7_t* num);
void onumm1n7_tan_to(onumm1n7_t* num, onumm1n7_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of function cosine at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n7_t onumm1n7_cos(onumm1n7_t* num);
void onumm1n7_cos_to(onumm1n7_t* num, onumm1n7_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of function sine at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n7_t onumm1n7_sin(onumm1n7_t* num );
void onumm1n7_sin_to(onumm1n7_t* num, onumm1n7_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of Logarithm at base b function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n7_t onumm1n7_logb(onumm1n7_t* num, double base);
void onumm1n7_logb_to(onumm1n7_t* num, double base, onumm1n7_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of Logarithm at base 10 function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n7_t onumm1n7_log10(onumm1n7_t* num);
void onumm1n7_log10_to(onumm1n7_t* num, onumm1n7_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n7_t onumm1n7_log(onumm1n7_t* num);
void onumm1n7_log_to(onumm1n7_t* num, onumm1n7_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n7_t onumm1n7_exp(onumm1n7_t* num);
void onumm1n7_exp_to(onumm1n7_t* num, onumm1n7_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n7_t onumm1n7_pow(onumm1n7_t* num, double e);
void onumm1n7_pow_to(onumm1n7_t* num, coeff_t e, onumm1n7_t* res);
// ----------------------------------------------------------------------------------------------------

#endif