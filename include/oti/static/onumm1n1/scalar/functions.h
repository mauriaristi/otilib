#ifndef OTI_ONUMM1N1_SCALAR_FUNCTIONS_H
#define OTI_ONUMM1N1_SCALAR_FUNCTIONS_H

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic tangent function at (num).

@param[in] num: Oti number.
@param[in] dhl: Direction helper list object.
******************************************************************************************************/ 
onumm1n1_t onumm1n1_atanh(onumm1n1_t* num);
void onumm1n1_atanh_to(onumm1n1_t* num, onumm1n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic sine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n1_t onumm1n1_asinh(onumm1n1_t* num);
void onumm1n1_asinh_to(onumm1n1_t* num, onumm1n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic cosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n1_t onumm1n1_acosh(onumm1n1_t* num);
void onumm1n1_acosh_to(onumm1n1_t* num, onumm1n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic tangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n1_t onumm1n1_tanh(onumm1n1_t* num);
void onumm1n1_tanh_to(onumm1n1_t* num, onumm1n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of square root function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n1_t onumm1n1_sqrt(onumm1n1_t* num);
void onumm1n1_sqrt_to(onumm1n1_t* num, onumm1n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of cubic root function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n1_t onumm1n1_cbrt(onumm1n1_t* num);
void onumm1n1_cbrt_to(onumm1n1_t* num, onumm1n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic cosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n1_t onumm1n1_cosh(onumm1n1_t* num);
void onumm1n1_cosh_to(onumm1n1_t* num, onumm1n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic sine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n1_t onumm1n1_sinh(onumm1n1_t* num);
void onumm1n1_sinh_to(onumm1n1_t* num, onumm1n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arcsine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n1_t onumm1n1_asin(onumm1n1_t* num);
void onumm1n1_asin_to(onumm1n1_t* num, onumm1n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arccosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n1_t onumm1n1_acos(onumm1n1_t* num);
void onumm1n1_acos_to(onumm1n1_t* num, onumm1n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arctangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n1_t onumm1n1_atan(onumm1n1_t* num);
void onumm1n1_atan_to(onumm1n1_t* num, onumm1n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of the tangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n1_t onumm1n1_tan(onumm1n1_t* num);
void onumm1n1_tan_to(onumm1n1_t* num, onumm1n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of function cosine at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n1_t onumm1n1_cos(onumm1n1_t* num);
void onumm1n1_cos_to(onumm1n1_t* num, onumm1n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of function sine at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n1_t onumm1n1_sin(onumm1n1_t* num );
void onumm1n1_sin_to(onumm1n1_t* num, onumm1n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of Logarithm at base b function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n1_t onumm1n1_logb(onumm1n1_t* num, double base);
void onumm1n1_logb_to(onumm1n1_t* num, double base, onumm1n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of Logarithm at base 10 function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n1_t onumm1n1_log10(onumm1n1_t* num);
void onumm1n1_log10_to(onumm1n1_t* num, onumm1n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n1_t onumm1n1_log(onumm1n1_t* num);
void onumm1n1_log_to(onumm1n1_t* num, onumm1n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n1_t onumm1n1_exp(onumm1n1_t* num);
void onumm1n1_exp_to(onumm1n1_t* num, onumm1n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n1_t onumm1n1_pow(onumm1n1_t* num, double e);
void onumm1n1_pow_to(onumm1n1_t* num, coeff_t e, onumm1n1_t* res);
// ----------------------------------------------------------------------------------------------------

#endif