#ifndef OTI_ONUMM1N9_SCALAR_FUNCTIONS_H
#define OTI_ONUMM1N9_SCALAR_FUNCTIONS_H

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic tangent function at (num).

@param[in] num: Oti number.
@param[in] dhl: Direction helper list object.
******************************************************************************************************/ 
onumm1n9_t onumm1n9_atanh(onumm1n9_t* num);
void onumm1n9_atanh_to(onumm1n9_t* num, onumm1n9_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic sine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n9_t onumm1n9_asinh(onumm1n9_t* num);
void onumm1n9_asinh_to(onumm1n9_t* num, onumm1n9_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic cosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n9_t onumm1n9_acosh(onumm1n9_t* num);
void onumm1n9_acosh_to(onumm1n9_t* num, onumm1n9_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic tangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n9_t onumm1n9_tanh(onumm1n9_t* num);
void onumm1n9_tanh_to(onumm1n9_t* num, onumm1n9_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of square root function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n9_t onumm1n9_sqrt(onumm1n9_t* num);
void onumm1n9_sqrt_to(onumm1n9_t* num, onumm1n9_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of cubic root function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n9_t onumm1n9_cbrt(onumm1n9_t* num);
void onumm1n9_cbrt_to(onumm1n9_t* num, onumm1n9_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic cosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n9_t onumm1n9_cosh(onumm1n9_t* num);
void onumm1n9_cosh_to(onumm1n9_t* num, onumm1n9_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic sine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n9_t onumm1n9_sinh(onumm1n9_t* num);
void onumm1n9_sinh_to(onumm1n9_t* num, onumm1n9_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arcsine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n9_t onumm1n9_asin(onumm1n9_t* num);
void onumm1n9_asin_to(onumm1n9_t* num, onumm1n9_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arccosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n9_t onumm1n9_acos(onumm1n9_t* num);
void onumm1n9_acos_to(onumm1n9_t* num, onumm1n9_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arctangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n9_t onumm1n9_atan(onumm1n9_t* num);
void onumm1n9_atan_to(onumm1n9_t* num, onumm1n9_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of the tangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n9_t onumm1n9_tan(onumm1n9_t* num);
void onumm1n9_tan_to(onumm1n9_t* num, onumm1n9_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of function cosine at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n9_t onumm1n9_cos(onumm1n9_t* num);
void onumm1n9_cos_to(onumm1n9_t* num, onumm1n9_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of function sine at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n9_t onumm1n9_sin(onumm1n9_t* num );
void onumm1n9_sin_to(onumm1n9_t* num, onumm1n9_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of Logarithm at base b function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n9_t onumm1n9_logb(onumm1n9_t* num, double base);
void onumm1n9_logb_to(onumm1n9_t* num, double base, onumm1n9_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of Logarithm at base 10 function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n9_t onumm1n9_log10(onumm1n9_t* num);
void onumm1n9_log10_to(onumm1n9_t* num, onumm1n9_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n9_t onumm1n9_log(onumm1n9_t* num);
void onumm1n9_log_to(onumm1n9_t* num, onumm1n9_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n9_t onumm1n9_exp(onumm1n9_t* num);
void onumm1n9_exp_to(onumm1n9_t* num, onumm1n9_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n9_t onumm1n9_pow(onumm1n9_t* num, double e);
void onumm1n9_pow_to(onumm1n9_t* num, coeff_t e, onumm1n9_t* res);
// ----------------------------------------------------------------------------------------------------

#endif