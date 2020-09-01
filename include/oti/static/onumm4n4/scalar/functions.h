#ifndef OTI_ONUMM4N4_SCALAR_FUNCTIONS_H
#define OTI_ONUMM4N4_SCALAR_FUNCTIONS_H

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic tangent function at (num).

@param[in] num: Oti number.
@param[in] dhl: Direction helper list object.
******************************************************************************************************/ 
onumm4n4_t onumm4n4_atanh(onumm4n4_t* num);
void onumm4n4_atanh_to(onumm4n4_t* num, onumm4n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic sine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm4n4_t onumm4n4_asinh(onumm4n4_t* num);
void onumm4n4_asinh_to(onumm4n4_t* num, onumm4n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic cosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm4n4_t onumm4n4_acosh(onumm4n4_t* num);
void onumm4n4_acosh_to(onumm4n4_t* num, onumm4n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic tangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm4n4_t onumm4n4_tanh(onumm4n4_t* num);
void onumm4n4_tanh_to(onumm4n4_t* num, onumm4n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of square root function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm4n4_t onumm4n4_sqrt(onumm4n4_t* num);
void onumm4n4_sqrt_to(onumm4n4_t* num, onumm4n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of cubic root function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm4n4_t onumm4n4_cbrt(onumm4n4_t* num);
void onumm4n4_cbrt_to(onumm4n4_t* num, onumm4n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic cosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm4n4_t onumm4n4_cosh(onumm4n4_t* num);
void onumm4n4_cosh_to(onumm4n4_t* num, onumm4n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic sine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm4n4_t onumm4n4_sinh(onumm4n4_t* num);
void onumm4n4_sinh_to(onumm4n4_t* num, onumm4n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arcsine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm4n4_t onumm4n4_asin(onumm4n4_t* num);
void onumm4n4_asin_to(onumm4n4_t* num, onumm4n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arccosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm4n4_t onumm4n4_acos(onumm4n4_t* num);
void onumm4n4_acos_to(onumm4n4_t* num, onumm4n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arctangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm4n4_t onumm4n4_atan(onumm4n4_t* num);
void onumm4n4_atan_to(onumm4n4_t* num, onumm4n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of the tangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm4n4_t onumm4n4_tan(onumm4n4_t* num);
void onumm4n4_tan_to(onumm4n4_t* num, onumm4n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of function cosine at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm4n4_t onumm4n4_cos(onumm4n4_t* num);
void onumm4n4_cos_to(onumm4n4_t* num, onumm4n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of function sine at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm4n4_t onumm4n4_sin(onumm4n4_t* num );
void onumm4n4_sin_to(onumm4n4_t* num, onumm4n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of Logarithm at base b function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm4n4_t onumm4n4_logb(onumm4n4_t* num, double base);
void onumm4n4_logb_to(onumm4n4_t* num, double base, onumm4n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of Logarithm at base 10 function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm4n4_t onumm4n4_log10(onumm4n4_t* num);
void onumm4n4_log10_to(onumm4n4_t* num, onumm4n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm4n4_t onumm4n4_log(onumm4n4_t* num);
void onumm4n4_log_to(onumm4n4_t* num, onumm4n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm4n4_t onumm4n4_exp(onumm4n4_t* num);
void onumm4n4_exp_to(onumm4n4_t* num, onumm4n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm4n4_t onumm4n4_pow(onumm4n4_t* num, double e);
void onumm4n4_pow_to(onumm4n4_t* num, coeff_t e, onumm4n4_t* res);
// ----------------------------------------------------------------------------------------------------

#endif