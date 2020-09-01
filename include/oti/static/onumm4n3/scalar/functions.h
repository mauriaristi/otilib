#ifndef OTI_ONUMM4N3_SCALAR_FUNCTIONS_H
#define OTI_ONUMM4N3_SCALAR_FUNCTIONS_H

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic tangent function at (num).

@param[in] num: Oti number.
@param[in] dhl: Direction helper list object.
******************************************************************************************************/ 
onumm4n3_t onumm4n3_atanh(onumm4n3_t* num);
void onumm4n3_atanh_to(onumm4n3_t* num, onumm4n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic sine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm4n3_t onumm4n3_asinh(onumm4n3_t* num);
void onumm4n3_asinh_to(onumm4n3_t* num, onumm4n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic cosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm4n3_t onumm4n3_acosh(onumm4n3_t* num);
void onumm4n3_acosh_to(onumm4n3_t* num, onumm4n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic tangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm4n3_t onumm4n3_tanh(onumm4n3_t* num);
void onumm4n3_tanh_to(onumm4n3_t* num, onumm4n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of square root function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm4n3_t onumm4n3_sqrt(onumm4n3_t* num);
void onumm4n3_sqrt_to(onumm4n3_t* num, onumm4n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of cubic root function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm4n3_t onumm4n3_cbrt(onumm4n3_t* num);
void onumm4n3_cbrt_to(onumm4n3_t* num, onumm4n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic cosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm4n3_t onumm4n3_cosh(onumm4n3_t* num);
void onumm4n3_cosh_to(onumm4n3_t* num, onumm4n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic sine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm4n3_t onumm4n3_sinh(onumm4n3_t* num);
void onumm4n3_sinh_to(onumm4n3_t* num, onumm4n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arcsine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm4n3_t onumm4n3_asin(onumm4n3_t* num);
void onumm4n3_asin_to(onumm4n3_t* num, onumm4n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arccosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm4n3_t onumm4n3_acos(onumm4n3_t* num);
void onumm4n3_acos_to(onumm4n3_t* num, onumm4n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arctangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm4n3_t onumm4n3_atan(onumm4n3_t* num);
void onumm4n3_atan_to(onumm4n3_t* num, onumm4n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of the tangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm4n3_t onumm4n3_tan(onumm4n3_t* num);
void onumm4n3_tan_to(onumm4n3_t* num, onumm4n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of function cosine at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm4n3_t onumm4n3_cos(onumm4n3_t* num);
void onumm4n3_cos_to(onumm4n3_t* num, onumm4n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of function sine at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm4n3_t onumm4n3_sin(onumm4n3_t* num );
void onumm4n3_sin_to(onumm4n3_t* num, onumm4n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of Logarithm at base b function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm4n3_t onumm4n3_logb(onumm4n3_t* num, double base);
void onumm4n3_logb_to(onumm4n3_t* num, double base, onumm4n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of Logarithm at base 10 function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm4n3_t onumm4n3_log10(onumm4n3_t* num);
void onumm4n3_log10_to(onumm4n3_t* num, onumm4n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm4n3_t onumm4n3_log(onumm4n3_t* num);
void onumm4n3_log_to(onumm4n3_t* num, onumm4n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm4n3_t onumm4n3_exp(onumm4n3_t* num);
void onumm4n3_exp_to(onumm4n3_t* num, onumm4n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm4n3_t onumm4n3_pow(onumm4n3_t* num, double e);
void onumm4n3_pow_to(onumm4n3_t* num, coeff_t e, onumm4n3_t* res);
// ----------------------------------------------------------------------------------------------------

#endif