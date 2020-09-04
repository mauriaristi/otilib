#ifndef OTI_ONUMM7N1_SCALAR_FUNCTIONS_H
#define OTI_ONUMM7N1_SCALAR_FUNCTIONS_H

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic tangent function at (num).

@param[in] num: Oti number.
@param[in] dhl: Direction helper list object.
******************************************************************************************************/ 
onumm7n1_t onumm7n1_atanh(onumm7n1_t* num);
void onumm7n1_atanh_to(onumm7n1_t* num, onumm7n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic sine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm7n1_t onumm7n1_asinh(onumm7n1_t* num);
void onumm7n1_asinh_to(onumm7n1_t* num, onumm7n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic cosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm7n1_t onumm7n1_acosh(onumm7n1_t* num);
void onumm7n1_acosh_to(onumm7n1_t* num, onumm7n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic tangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm7n1_t onumm7n1_tanh(onumm7n1_t* num);
void onumm7n1_tanh_to(onumm7n1_t* num, onumm7n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of square root function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm7n1_t onumm7n1_sqrt(onumm7n1_t* num);
void onumm7n1_sqrt_to(onumm7n1_t* num, onumm7n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of cubic root function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm7n1_t onumm7n1_cbrt(onumm7n1_t* num);
void onumm7n1_cbrt_to(onumm7n1_t* num, onumm7n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic cosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm7n1_t onumm7n1_cosh(onumm7n1_t* num);
void onumm7n1_cosh_to(onumm7n1_t* num, onumm7n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic sine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm7n1_t onumm7n1_sinh(onumm7n1_t* num);
void onumm7n1_sinh_to(onumm7n1_t* num, onumm7n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arcsine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm7n1_t onumm7n1_asin(onumm7n1_t* num);
void onumm7n1_asin_to(onumm7n1_t* num, onumm7n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arccosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm7n1_t onumm7n1_acos(onumm7n1_t* num);
void onumm7n1_acos_to(onumm7n1_t* num, onumm7n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arctangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm7n1_t onumm7n1_atan(onumm7n1_t* num);
void onumm7n1_atan_to(onumm7n1_t* num, onumm7n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of the tangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm7n1_t onumm7n1_tan(onumm7n1_t* num);
void onumm7n1_tan_to(onumm7n1_t* num, onumm7n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of function cosine at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm7n1_t onumm7n1_cos(onumm7n1_t* num);
void onumm7n1_cos_to(onumm7n1_t* num, onumm7n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of function sine at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm7n1_t onumm7n1_sin(onumm7n1_t* num );
void onumm7n1_sin_to(onumm7n1_t* num, onumm7n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of Logarithm at base b function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm7n1_t onumm7n1_logb(onumm7n1_t* num, double base);
void onumm7n1_logb_to(onumm7n1_t* num, double base, onumm7n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of Logarithm at base 10 function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm7n1_t onumm7n1_log10(onumm7n1_t* num);
void onumm7n1_log10_to(onumm7n1_t* num, onumm7n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm7n1_t onumm7n1_log(onumm7n1_t* num);
void onumm7n1_log_to(onumm7n1_t* num, onumm7n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm7n1_t onumm7n1_exp(onumm7n1_t* num);
void onumm7n1_exp_to(onumm7n1_t* num, onumm7n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm7n1_t onumm7n1_pow(onumm7n1_t* num, double e);
void onumm7n1_pow_to(onumm7n1_t* num, coeff_t e, onumm7n1_t* res);
// ----------------------------------------------------------------------------------------------------

#endif