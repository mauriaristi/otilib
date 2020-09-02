#ifndef OTI_ONUMM2N8_SCALAR_FUNCTIONS_H
#define OTI_ONUMM2N8_SCALAR_FUNCTIONS_H

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic tangent function at (num).

@param[in] num: Oti number.
@param[in] dhl: Direction helper list object.
******************************************************************************************************/ 
onumm2n8_t onumm2n8_atanh(onumm2n8_t* num);
void onumm2n8_atanh_to(onumm2n8_t* num, onumm2n8_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic sine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n8_t onumm2n8_asinh(onumm2n8_t* num);
void onumm2n8_asinh_to(onumm2n8_t* num, onumm2n8_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic cosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n8_t onumm2n8_acosh(onumm2n8_t* num);
void onumm2n8_acosh_to(onumm2n8_t* num, onumm2n8_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic tangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n8_t onumm2n8_tanh(onumm2n8_t* num);
void onumm2n8_tanh_to(onumm2n8_t* num, onumm2n8_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of square root function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n8_t onumm2n8_sqrt(onumm2n8_t* num);
void onumm2n8_sqrt_to(onumm2n8_t* num, onumm2n8_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of cubic root function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n8_t onumm2n8_cbrt(onumm2n8_t* num);
void onumm2n8_cbrt_to(onumm2n8_t* num, onumm2n8_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic cosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n8_t onumm2n8_cosh(onumm2n8_t* num);
void onumm2n8_cosh_to(onumm2n8_t* num, onumm2n8_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic sine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n8_t onumm2n8_sinh(onumm2n8_t* num);
void onumm2n8_sinh_to(onumm2n8_t* num, onumm2n8_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arcsine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n8_t onumm2n8_asin(onumm2n8_t* num);
void onumm2n8_asin_to(onumm2n8_t* num, onumm2n8_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arccosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n8_t onumm2n8_acos(onumm2n8_t* num);
void onumm2n8_acos_to(onumm2n8_t* num, onumm2n8_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arctangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n8_t onumm2n8_atan(onumm2n8_t* num);
void onumm2n8_atan_to(onumm2n8_t* num, onumm2n8_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of the tangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n8_t onumm2n8_tan(onumm2n8_t* num);
void onumm2n8_tan_to(onumm2n8_t* num, onumm2n8_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of function cosine at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n8_t onumm2n8_cos(onumm2n8_t* num);
void onumm2n8_cos_to(onumm2n8_t* num, onumm2n8_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of function sine at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n8_t onumm2n8_sin(onumm2n8_t* num );
void onumm2n8_sin_to(onumm2n8_t* num, onumm2n8_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of Logarithm at base b function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n8_t onumm2n8_logb(onumm2n8_t* num, double base);
void onumm2n8_logb_to(onumm2n8_t* num, double base, onumm2n8_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of Logarithm at base 10 function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n8_t onumm2n8_log10(onumm2n8_t* num);
void onumm2n8_log10_to(onumm2n8_t* num, onumm2n8_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n8_t onumm2n8_log(onumm2n8_t* num);
void onumm2n8_log_to(onumm2n8_t* num, onumm2n8_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n8_t onumm2n8_exp(onumm2n8_t* num);
void onumm2n8_exp_to(onumm2n8_t* num, onumm2n8_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n8_t onumm2n8_pow(onumm2n8_t* num, double e);
void onumm2n8_pow_to(onumm2n8_t* num, coeff_t e, onumm2n8_t* res);
// ----------------------------------------------------------------------------------------------------

#endif