#ifndef OTI_ONUMM4N1_SCALAR_FUNCTIONS_H
#define OTI_ONUMM4N1_SCALAR_FUNCTIONS_H

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic tangent function at (num).

@param[in] num: Oti number.
@param[in] dhl: Direction helper list object.
******************************************************************************************************/ 
onumm4n1_t onumm4n1_atanh(onumm4n1_t* num);
void onumm4n1_atanh_to(onumm4n1_t* num, onumm4n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic sine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm4n1_t onumm4n1_asinh(onumm4n1_t* num);
void onumm4n1_asinh_to(onumm4n1_t* num, onumm4n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic cosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm4n1_t onumm4n1_acosh(onumm4n1_t* num);
void onumm4n1_acosh_to(onumm4n1_t* num, onumm4n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic tangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm4n1_t onumm4n1_tanh(onumm4n1_t* num);
void onumm4n1_tanh_to(onumm4n1_t* num, onumm4n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of square root function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm4n1_t onumm4n1_sqrt(onumm4n1_t* num);
void onumm4n1_sqrt_to(onumm4n1_t* num, onumm4n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of cubic root function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm4n1_t onumm4n1_cbrt(onumm4n1_t* num);
void onumm4n1_cbrt_to(onumm4n1_t* num, onumm4n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic cosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm4n1_t onumm4n1_cosh(onumm4n1_t* num);
void onumm4n1_cosh_to(onumm4n1_t* num, onumm4n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic sine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm4n1_t onumm4n1_sinh(onumm4n1_t* num);
void onumm4n1_sinh_to(onumm4n1_t* num, onumm4n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arcsine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm4n1_t onumm4n1_asin(onumm4n1_t* num);
void onumm4n1_asin_to(onumm4n1_t* num, onumm4n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arccosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm4n1_t onumm4n1_acos(onumm4n1_t* num);
void onumm4n1_acos_to(onumm4n1_t* num, onumm4n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arctangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm4n1_t onumm4n1_atan(onumm4n1_t* num);
void onumm4n1_atan_to(onumm4n1_t* num, onumm4n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of the tangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm4n1_t onumm4n1_tan(onumm4n1_t* num);
void onumm4n1_tan_to(onumm4n1_t* num, onumm4n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of function cosine at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm4n1_t onumm4n1_cos(onumm4n1_t* num);
void onumm4n1_cos_to(onumm4n1_t* num, onumm4n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of function sine at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm4n1_t onumm4n1_sin(onumm4n1_t* num );
void onumm4n1_sin_to(onumm4n1_t* num, onumm4n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of Logarithm at base b function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm4n1_t onumm4n1_logb(onumm4n1_t* num, double base);
void onumm4n1_logb_to(onumm4n1_t* num, double base, onumm4n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of Logarithm at base 10 function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm4n1_t onumm4n1_log10(onumm4n1_t* num);
void onumm4n1_log10_to(onumm4n1_t* num, onumm4n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm4n1_t onumm4n1_log(onumm4n1_t* num);
void onumm4n1_log_to(onumm4n1_t* num, onumm4n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm4n1_t onumm4n1_exp(onumm4n1_t* num);
void onumm4n1_exp_to(onumm4n1_t* num, onumm4n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm4n1_t onumm4n1_pow(onumm4n1_t* num, double e);
void onumm4n1_pow_to(onumm4n1_t* num, coeff_t e, onumm4n1_t* res);
// ----------------------------------------------------------------------------------------------------

#endif