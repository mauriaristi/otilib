#ifndef OTI_ONUMM7N2_SCALAR_FUNCTIONS_H
#define OTI_ONUMM7N2_SCALAR_FUNCTIONS_H

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic tangent function at (num).

@param[in] num: Oti number.
@param[in] dhl: Direction helper list object.
******************************************************************************************************/ 
onumm7n2_t onumm7n2_atanh(onumm7n2_t* num);
void onumm7n2_atanh_to(onumm7n2_t* num, onumm7n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic sine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm7n2_t onumm7n2_asinh(onumm7n2_t* num);
void onumm7n2_asinh_to(onumm7n2_t* num, onumm7n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic cosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm7n2_t onumm7n2_acosh(onumm7n2_t* num);
void onumm7n2_acosh_to(onumm7n2_t* num, onumm7n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic tangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm7n2_t onumm7n2_tanh(onumm7n2_t* num);
void onumm7n2_tanh_to(onumm7n2_t* num, onumm7n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of square root function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm7n2_t onumm7n2_sqrt(onumm7n2_t* num);
void onumm7n2_sqrt_to(onumm7n2_t* num, onumm7n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of cubic root function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm7n2_t onumm7n2_cbrt(onumm7n2_t* num);
void onumm7n2_cbrt_to(onumm7n2_t* num, onumm7n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic cosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm7n2_t onumm7n2_cosh(onumm7n2_t* num);
void onumm7n2_cosh_to(onumm7n2_t* num, onumm7n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic sine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm7n2_t onumm7n2_sinh(onumm7n2_t* num);
void onumm7n2_sinh_to(onumm7n2_t* num, onumm7n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arcsine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm7n2_t onumm7n2_asin(onumm7n2_t* num);
void onumm7n2_asin_to(onumm7n2_t* num, onumm7n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arccosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm7n2_t onumm7n2_acos(onumm7n2_t* num);
void onumm7n2_acos_to(onumm7n2_t* num, onumm7n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arctangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm7n2_t onumm7n2_atan(onumm7n2_t* num);
void onumm7n2_atan_to(onumm7n2_t* num, onumm7n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of the tangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm7n2_t onumm7n2_tan(onumm7n2_t* num);
void onumm7n2_tan_to(onumm7n2_t* num, onumm7n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of function cosine at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm7n2_t onumm7n2_cos(onumm7n2_t* num);
void onumm7n2_cos_to(onumm7n2_t* num, onumm7n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of function sine at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm7n2_t onumm7n2_sin(onumm7n2_t* num );
void onumm7n2_sin_to(onumm7n2_t* num, onumm7n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of Logarithm at base b function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm7n2_t onumm7n2_logb(onumm7n2_t* num, double base);
void onumm7n2_logb_to(onumm7n2_t* num, double base, onumm7n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of Logarithm at base 10 function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm7n2_t onumm7n2_log10(onumm7n2_t* num);
void onumm7n2_log10_to(onumm7n2_t* num, onumm7n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm7n2_t onumm7n2_log(onumm7n2_t* num);
void onumm7n2_log_to(onumm7n2_t* num, onumm7n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm7n2_t onumm7n2_exp(onumm7n2_t* num);
void onumm7n2_exp_to(onumm7n2_t* num, onumm7n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm7n2_t onumm7n2_pow(onumm7n2_t* num, double e);
void onumm7n2_pow_to(onumm7n2_t* num, coeff_t e, onumm7n2_t* res);
// ----------------------------------------------------------------------------------------------------

#endif