#ifndef OTI_ONUMM1N20_SCALAR_FUNCTIONS_H
#define OTI_ONUMM1N20_SCALAR_FUNCTIONS_H

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic tangent function at (num).

@param[in] num: Oti number.
@param[in] dhl: Direction helper list object.
******************************************************************************************************/ 
onumm1n20_t onumm1n20_atanh(onumm1n20_t* num);
void onumm1n20_atanh_to(onumm1n20_t* num, onumm1n20_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic sine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n20_t onumm1n20_asinh(onumm1n20_t* num);
void onumm1n20_asinh_to(onumm1n20_t* num, onumm1n20_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic cosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n20_t onumm1n20_acosh(onumm1n20_t* num);
void onumm1n20_acosh_to(onumm1n20_t* num, onumm1n20_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic tangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n20_t onumm1n20_tanh(onumm1n20_t* num);
void onumm1n20_tanh_to(onumm1n20_t* num, onumm1n20_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of square root function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n20_t onumm1n20_sqrt(onumm1n20_t* num);
void onumm1n20_sqrt_to(onumm1n20_t* num, onumm1n20_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of cubic root function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n20_t onumm1n20_cbrt(onumm1n20_t* num);
void onumm1n20_cbrt_to(onumm1n20_t* num, onumm1n20_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic cosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n20_t onumm1n20_cosh(onumm1n20_t* num);
void onumm1n20_cosh_to(onumm1n20_t* num, onumm1n20_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic sine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n20_t onumm1n20_sinh(onumm1n20_t* num);
void onumm1n20_sinh_to(onumm1n20_t* num, onumm1n20_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arcsine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n20_t onumm1n20_asin(onumm1n20_t* num);
void onumm1n20_asin_to(onumm1n20_t* num, onumm1n20_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arccosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n20_t onumm1n20_acos(onumm1n20_t* num);
void onumm1n20_acos_to(onumm1n20_t* num, onumm1n20_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arctangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n20_t onumm1n20_atan(onumm1n20_t* num);
void onumm1n20_atan_to(onumm1n20_t* num, onumm1n20_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of the tangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n20_t onumm1n20_tan(onumm1n20_t* num);
void onumm1n20_tan_to(onumm1n20_t* num, onumm1n20_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of function cosine at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n20_t onumm1n20_cos(onumm1n20_t* num);
void onumm1n20_cos_to(onumm1n20_t* num, onumm1n20_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of function sine at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n20_t onumm1n20_sin(onumm1n20_t* num );
void onumm1n20_sin_to(onumm1n20_t* num, onumm1n20_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of Logarithm at base b function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n20_t onumm1n20_logb(onumm1n20_t* num, double base);
void onumm1n20_logb_to(onumm1n20_t* num, double base, onumm1n20_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of Logarithm at base 10 function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n20_t onumm1n20_log10(onumm1n20_t* num);
void onumm1n20_log10_to(onumm1n20_t* num, onumm1n20_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n20_t onumm1n20_log(onumm1n20_t* num);
void onumm1n20_log_to(onumm1n20_t* num, onumm1n20_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n20_t onumm1n20_exp(onumm1n20_t* num);
void onumm1n20_exp_to(onumm1n20_t* num, onumm1n20_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n20_t onumm1n20_pow(onumm1n20_t* num, double e);
void onumm1n20_pow_to(onumm1n20_t* num, coeff_t e, onumm1n20_t* res);
// ----------------------------------------------------------------------------------------------------

#endif