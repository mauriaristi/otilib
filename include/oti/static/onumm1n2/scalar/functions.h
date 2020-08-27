#ifndef OTI_ONUMM1N2_SCALAR_FUNCTIONS_H
#define OTI_ONUMM1N2_SCALAR_FUNCTIONS_H

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic tangent function at (num).

@param[in] num: Oti number.
@param[in] dhl: Direction helper list object.
******************************************************************************************************/ 
onumm1n2_t onumm1n2_atanh(onumm1n2_t* num);
void onumm1n2_atanh_to(onumm1n2_t* num, onumm1n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic sine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n2_t onumm1n2_asinh(onumm1n2_t* num);
void onumm1n2_asinh_to(onumm1n2_t* num, onumm1n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic cosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n2_t onumm1n2_acosh(onumm1n2_t* num);
void onumm1n2_acosh_to(onumm1n2_t* num, onumm1n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic tangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n2_t onumm1n2_tanh(onumm1n2_t* num);
void onumm1n2_tanh_to(onumm1n2_t* num, onumm1n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of square root function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n2_t onumm1n2_sqrt(onumm1n2_t* num);
void onumm1n2_sqrt_to(onumm1n2_t* num, onumm1n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of cubic root function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n2_t onumm1n2_cbrt(onumm1n2_t* num);
void onumm1n2_cbrt_to(onumm1n2_t* num, onumm1n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic cosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n2_t onumm1n2_cosh(onumm1n2_t* num);
void onumm1n2_cosh_to(onumm1n2_t* num, onumm1n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic sine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n2_t onumm1n2_sinh(onumm1n2_t* num);
void onumm1n2_sinh_to(onumm1n2_t* num, onumm1n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arcsine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n2_t onumm1n2_asin(onumm1n2_t* num);
void onumm1n2_asin_to(onumm1n2_t* num, onumm1n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arccosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n2_t onumm1n2_acos(onumm1n2_t* num);
void onumm1n2_acos_to(onumm1n2_t* num, onumm1n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arctangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n2_t onumm1n2_atan(onumm1n2_t* num);
void onumm1n2_atan_to(onumm1n2_t* num, onumm1n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of the tangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n2_t onumm1n2_tan(onumm1n2_t* num);
void onumm1n2_tan_to(onumm1n2_t* num, onumm1n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of function cosine at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n2_t onumm1n2_cos(onumm1n2_t* num);
void onumm1n2_cos_to(onumm1n2_t* num, onumm1n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of function sine at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n2_t onumm1n2_sin(onumm1n2_t* num );
void onumm1n2_sin_to(onumm1n2_t* num, onumm1n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of Logarithm at base b function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n2_t onumm1n2_logb(onumm1n2_t* num, double base);
void onumm1n2_logb_to(onumm1n2_t* num, double base, onumm1n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of Logarithm at base 10 function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n2_t onumm1n2_log10(onumm1n2_t* num);
void onumm1n2_log10_to(onumm1n2_t* num, onumm1n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n2_t onumm1n2_log(onumm1n2_t* num);
void onumm1n2_log_to(onumm1n2_t* num, onumm1n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n2_t onumm1n2_exp(onumm1n2_t* num);
void onumm1n2_exp_to(onumm1n2_t* num, onumm1n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm1n2_t onumm1n2_pow(onumm1n2_t* num, double e);
void onumm1n2_pow_to(onumm1n2_t* num, coeff_t e, onumm1n2_t* res);
// ----------------------------------------------------------------------------------------------------

#endif