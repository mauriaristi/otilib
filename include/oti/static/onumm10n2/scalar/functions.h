#ifndef OTI_ONUMM10N2_SCALAR_FUNCTIONS_H
#define OTI_ONUMM10N2_SCALAR_FUNCTIONS_H

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic tangent function at (num).

@param[in] num: Oti number.
@param[in] dhl: Direction helper list object.
******************************************************************************************************/ 
onumm10n2_t onumm10n2_atanh(onumm10n2_t* num);
void onumm10n2_atanh_to(onumm10n2_t* num, onumm10n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic sine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm10n2_t onumm10n2_asinh(onumm10n2_t* num);
void onumm10n2_asinh_to(onumm10n2_t* num, onumm10n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic cosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm10n2_t onumm10n2_acosh(onumm10n2_t* num);
void onumm10n2_acosh_to(onumm10n2_t* num, onumm10n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic tangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm10n2_t onumm10n2_tanh(onumm10n2_t* num);
void onumm10n2_tanh_to(onumm10n2_t* num, onumm10n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of square root function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm10n2_t onumm10n2_sqrt(onumm10n2_t* num);
void onumm10n2_sqrt_to(onumm10n2_t* num, onumm10n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of cubic root function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm10n2_t onumm10n2_cbrt(onumm10n2_t* num);
void onumm10n2_cbrt_to(onumm10n2_t* num, onumm10n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic cosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm10n2_t onumm10n2_cosh(onumm10n2_t* num);
void onumm10n2_cosh_to(onumm10n2_t* num, onumm10n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic sine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm10n2_t onumm10n2_sinh(onumm10n2_t* num);
void onumm10n2_sinh_to(onumm10n2_t* num, onumm10n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arcsine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm10n2_t onumm10n2_asin(onumm10n2_t* num);
void onumm10n2_asin_to(onumm10n2_t* num, onumm10n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arccosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm10n2_t onumm10n2_acos(onumm10n2_t* num);
void onumm10n2_acos_to(onumm10n2_t* num, onumm10n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arctangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm10n2_t onumm10n2_atan(onumm10n2_t* num);
void onumm10n2_atan_to(onumm10n2_t* num, onumm10n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of the tangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm10n2_t onumm10n2_tan(onumm10n2_t* num);
void onumm10n2_tan_to(onumm10n2_t* num, onumm10n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of function cosine at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm10n2_t onumm10n2_cos(onumm10n2_t* num);
void onumm10n2_cos_to(onumm10n2_t* num, onumm10n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of function sine at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm10n2_t onumm10n2_sin(onumm10n2_t* num );
void onumm10n2_sin_to(onumm10n2_t* num, onumm10n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of Logarithm at base b function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm10n2_t onumm10n2_logb(onumm10n2_t* num, double base);
void onumm10n2_logb_to(onumm10n2_t* num, double base, onumm10n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of Logarithm at base 10 function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm10n2_t onumm10n2_log10(onumm10n2_t* num);
void onumm10n2_log10_to(onumm10n2_t* num, onumm10n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm10n2_t onumm10n2_log(onumm10n2_t* num);
void onumm10n2_log_to(onumm10n2_t* num, onumm10n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm10n2_t onumm10n2_exp(onumm10n2_t* num);
void onumm10n2_exp_to(onumm10n2_t* num, onumm10n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm10n2_t onumm10n2_pow(onumm10n2_t* num, double e);
void onumm10n2_pow_to(onumm10n2_t* num, coeff_t e, onumm10n2_t* res);
// ----------------------------------------------------------------------------------------------------

#endif