#ifndef OTI_ONUMM10N1_SCALAR_FUNCTIONS_H
#define OTI_ONUMM10N1_SCALAR_FUNCTIONS_H

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic tangent function at (num).

@param[in] num: Oti number.
@param[in] dhl: Direction helper list object.
******************************************************************************************************/ 
onumm10n1_t onumm10n1_atanh(onumm10n1_t* num);
void onumm10n1_atanh_to(onumm10n1_t* num, onumm10n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic sine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm10n1_t onumm10n1_asinh(onumm10n1_t* num);
void onumm10n1_asinh_to(onumm10n1_t* num, onumm10n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic cosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm10n1_t onumm10n1_acosh(onumm10n1_t* num);
void onumm10n1_acosh_to(onumm10n1_t* num, onumm10n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic tangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm10n1_t onumm10n1_tanh(onumm10n1_t* num);
void onumm10n1_tanh_to(onumm10n1_t* num, onumm10n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of square root function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm10n1_t onumm10n1_sqrt(onumm10n1_t* num);
void onumm10n1_sqrt_to(onumm10n1_t* num, onumm10n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of cubic root function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm10n1_t onumm10n1_cbrt(onumm10n1_t* num);
void onumm10n1_cbrt_to(onumm10n1_t* num, onumm10n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic cosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm10n1_t onumm10n1_cosh(onumm10n1_t* num);
void onumm10n1_cosh_to(onumm10n1_t* num, onumm10n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic sine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm10n1_t onumm10n1_sinh(onumm10n1_t* num);
void onumm10n1_sinh_to(onumm10n1_t* num, onumm10n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arcsine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm10n1_t onumm10n1_asin(onumm10n1_t* num);
void onumm10n1_asin_to(onumm10n1_t* num, onumm10n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arccosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm10n1_t onumm10n1_acos(onumm10n1_t* num);
void onumm10n1_acos_to(onumm10n1_t* num, onumm10n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arctangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm10n1_t onumm10n1_atan(onumm10n1_t* num);
void onumm10n1_atan_to(onumm10n1_t* num, onumm10n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of the tangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm10n1_t onumm10n1_tan(onumm10n1_t* num);
void onumm10n1_tan_to(onumm10n1_t* num, onumm10n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of function cosine at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm10n1_t onumm10n1_cos(onumm10n1_t* num);
void onumm10n1_cos_to(onumm10n1_t* num, onumm10n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of function sine at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm10n1_t onumm10n1_sin(onumm10n1_t* num );
void onumm10n1_sin_to(onumm10n1_t* num, onumm10n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of Logarithm at base b function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm10n1_t onumm10n1_logb(onumm10n1_t* num, double base);
void onumm10n1_logb_to(onumm10n1_t* num, double base, onumm10n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of Logarithm at base 10 function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm10n1_t onumm10n1_log10(onumm10n1_t* num);
void onumm10n1_log10_to(onumm10n1_t* num, onumm10n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm10n1_t onumm10n1_log(onumm10n1_t* num);
void onumm10n1_log_to(onumm10n1_t* num, onumm10n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm10n1_t onumm10n1_exp(onumm10n1_t* num);
void onumm10n1_exp_to(onumm10n1_t* num, onumm10n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm10n1_t onumm10n1_pow(onumm10n1_t* num, double e);
void onumm10n1_pow_to(onumm10n1_t* num, coeff_t e, onumm10n1_t* res);
// ----------------------------------------------------------------------------------------------------

#endif