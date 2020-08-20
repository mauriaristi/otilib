#ifndef OTI_ONUMM1N3_SCALAR_FUNCTIONS_H
#define OTI_ONUMM1N3_SCALAR_FUNCTIONS_H

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic tangent function at (num).

@param[in] num: Oti number.
@param[in] dhl: Direction helper list object.
******************************************************************************************************/ 
onumm1n3_t onumm1n3_atanh(onumm1n3_t* num);
void onumm1n3_atanh_to(onumm1n3_t* num, onumm1n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic sine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n3_t onumm1n3_asinh(onumm1n3_t* num);
void onumm1n3_asinh_to(onumm1n3_t* num, onumm1n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic cosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n3_t onumm1n3_acosh(onumm1n3_t* num);
void onumm1n3_acosh_to(onumm1n3_t* num, onumm1n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic tangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n3_t onumm1n3_tanh(onumm1n3_t* num);
void onumm1n3_tanh_to(onumm1n3_t* num, onumm1n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of square root function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n3_t onumm1n3_sqrt(onumm1n3_t* num);
void onumm1n3_sqrt_to(onumm1n3_t* num, onumm1n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of cubic root function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n3_t onumm1n3_cbrt(onumm1n3_t* num);
void onumm1n3_cbrt_to(onumm1n3_t* num, onumm1n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic cosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n3_t onumm1n3_cosh(onumm1n3_t* num);
void onumm1n3_cosh_to(onumm1n3_t* num, onumm1n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic sine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n3_t onumm1n3_sinh(onumm1n3_t* num);
void onumm1n3_sinh_to(onumm1n3_t* num, onumm1n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arcsine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n3_t onumm1n3_asin(onumm1n3_t* num);
void onumm1n3_asin_to(onumm1n3_t* num, onumm1n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arccosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n3_t onumm1n3_acos(onumm1n3_t* num);
void onumm1n3_acos_to(onumm1n3_t* num, onumm1n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arctangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n3_t onumm1n3_atan(onumm1n3_t* num);
void onumm1n3_atan_to(onumm1n3_t* num, onumm1n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of the tangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n3_t onumm1n3_tan(onumm1n3_t* num);
void onumm1n3_tan_to(onumm1n3_t* num, onumm1n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of function cosine at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n3_t onumm1n3_cos(onumm1n3_t* num);
void onumm1n3_cos_to(onumm1n3_t* num, onumm1n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of function sine at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n3_t onumm1n3_sin(onumm1n3_t* num );
void onumm1n3_sin_to(onumm1n3_t* num, onumm1n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of Logarithm at base b function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n3_t onumm1n3_logb(onumm1n3_t* num, double base);
void onumm1n3_logb_to(onumm1n3_t* num, double base, onumm1n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of Logarithm at base 10 function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n3_t onumm1n3_log10(onumm1n3_t* num);
void onumm1n3_log10_to(onumm1n3_t* num, onumm1n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n3_t onumm1n3_log(onumm1n3_t* num);
void onumm1n3_log_to(onumm1n3_t* num, onumm1n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n3_t onumm1n3_exp(onumm1n3_t* num);
void onumm1n3_exp_to(onumm1n3_t* num, onumm1n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n3_t onumm1n3_pow(onumm1n3_t* num, double e);
void onumm1n3_pow_to(onumm1n3_t* num, coeff_t e, onumm1n3_t* res);
// ----------------------------------------------------------------------------------------------------

#endif