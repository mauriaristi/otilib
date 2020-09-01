#ifndef OTI_ONUMM4N5_SCALAR_FUNCTIONS_H
#define OTI_ONUMM4N5_SCALAR_FUNCTIONS_H

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic tangent function at (num).

@param[in] num: Oti number.
@param[in] dhl: Direction helper list object.
******************************************************************************************************/ 
onumm4n5_t onumm4n5_atanh(onumm4n5_t* num);
void onumm4n5_atanh_to(onumm4n5_t* num, onumm4n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic sine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm4n5_t onumm4n5_asinh(onumm4n5_t* num);
void onumm4n5_asinh_to(onumm4n5_t* num, onumm4n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic cosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm4n5_t onumm4n5_acosh(onumm4n5_t* num);
void onumm4n5_acosh_to(onumm4n5_t* num, onumm4n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic tangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm4n5_t onumm4n5_tanh(onumm4n5_t* num);
void onumm4n5_tanh_to(onumm4n5_t* num, onumm4n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of square root function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm4n5_t onumm4n5_sqrt(onumm4n5_t* num);
void onumm4n5_sqrt_to(onumm4n5_t* num, onumm4n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of cubic root function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm4n5_t onumm4n5_cbrt(onumm4n5_t* num);
void onumm4n5_cbrt_to(onumm4n5_t* num, onumm4n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic cosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm4n5_t onumm4n5_cosh(onumm4n5_t* num);
void onumm4n5_cosh_to(onumm4n5_t* num, onumm4n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic sine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm4n5_t onumm4n5_sinh(onumm4n5_t* num);
void onumm4n5_sinh_to(onumm4n5_t* num, onumm4n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arcsine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm4n5_t onumm4n5_asin(onumm4n5_t* num);
void onumm4n5_asin_to(onumm4n5_t* num, onumm4n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arccosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm4n5_t onumm4n5_acos(onumm4n5_t* num);
void onumm4n5_acos_to(onumm4n5_t* num, onumm4n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arctangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm4n5_t onumm4n5_atan(onumm4n5_t* num);
void onumm4n5_atan_to(onumm4n5_t* num, onumm4n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of the tangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm4n5_t onumm4n5_tan(onumm4n5_t* num);
void onumm4n5_tan_to(onumm4n5_t* num, onumm4n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of function cosine at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm4n5_t onumm4n5_cos(onumm4n5_t* num);
void onumm4n5_cos_to(onumm4n5_t* num, onumm4n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of function sine at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm4n5_t onumm4n5_sin(onumm4n5_t* num );
void onumm4n5_sin_to(onumm4n5_t* num, onumm4n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of Logarithm at base b function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm4n5_t onumm4n5_logb(onumm4n5_t* num, double base);
void onumm4n5_logb_to(onumm4n5_t* num, double base, onumm4n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of Logarithm at base 10 function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm4n5_t onumm4n5_log10(onumm4n5_t* num);
void onumm4n5_log10_to(onumm4n5_t* num, onumm4n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm4n5_t onumm4n5_log(onumm4n5_t* num);
void onumm4n5_log_to(onumm4n5_t* num, onumm4n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm4n5_t onumm4n5_exp(onumm4n5_t* num);
void onumm4n5_exp_to(onumm4n5_t* num, onumm4n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm4n5_t onumm4n5_pow(onumm4n5_t* num, double e);
void onumm4n5_pow_to(onumm4n5_t* num, coeff_t e, onumm4n5_t* res);
// ----------------------------------------------------------------------------------------------------

#endif