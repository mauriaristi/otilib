#ifndef OTI_ONUMM2N10_SCALAR_FUNCTIONS_H
#define OTI_ONUMM2N10_SCALAR_FUNCTIONS_H

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic tangent function at (num).

@param[in] num: Oti number.
@param[in] dhl: Direction helper list object.
******************************************************************************************************/ 
onumm2n10_t onumm2n10_atanh(onumm2n10_t* num);
void onumm2n10_atanh_to(onumm2n10_t* num, onumm2n10_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic sine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n10_t onumm2n10_asinh(onumm2n10_t* num);
void onumm2n10_asinh_to(onumm2n10_t* num, onumm2n10_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic cosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n10_t onumm2n10_acosh(onumm2n10_t* num);
void onumm2n10_acosh_to(onumm2n10_t* num, onumm2n10_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic tangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n10_t onumm2n10_tanh(onumm2n10_t* num);
void onumm2n10_tanh_to(onumm2n10_t* num, onumm2n10_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of square root function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n10_t onumm2n10_sqrt(onumm2n10_t* num);
void onumm2n10_sqrt_to(onumm2n10_t* num, onumm2n10_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of cubic root function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n10_t onumm2n10_cbrt(onumm2n10_t* num);
void onumm2n10_cbrt_to(onumm2n10_t* num, onumm2n10_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic cosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n10_t onumm2n10_cosh(onumm2n10_t* num);
void onumm2n10_cosh_to(onumm2n10_t* num, onumm2n10_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic sine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n10_t onumm2n10_sinh(onumm2n10_t* num);
void onumm2n10_sinh_to(onumm2n10_t* num, onumm2n10_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arcsine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n10_t onumm2n10_asin(onumm2n10_t* num);
void onumm2n10_asin_to(onumm2n10_t* num, onumm2n10_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arccosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n10_t onumm2n10_acos(onumm2n10_t* num);
void onumm2n10_acos_to(onumm2n10_t* num, onumm2n10_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arctangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n10_t onumm2n10_atan(onumm2n10_t* num);
void onumm2n10_atan_to(onumm2n10_t* num, onumm2n10_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of the tangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n10_t onumm2n10_tan(onumm2n10_t* num);
void onumm2n10_tan_to(onumm2n10_t* num, onumm2n10_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of function cosine at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n10_t onumm2n10_cos(onumm2n10_t* num);
void onumm2n10_cos_to(onumm2n10_t* num, onumm2n10_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of function sine at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n10_t onumm2n10_sin(onumm2n10_t* num );
void onumm2n10_sin_to(onumm2n10_t* num, onumm2n10_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of Logarithm at base b function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n10_t onumm2n10_logb(onumm2n10_t* num, double base);
void onumm2n10_logb_to(onumm2n10_t* num, double base, onumm2n10_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of Logarithm at base 10 function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n10_t onumm2n10_log10(onumm2n10_t* num);
void onumm2n10_log10_to(onumm2n10_t* num, onumm2n10_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n10_t onumm2n10_log(onumm2n10_t* num);
void onumm2n10_log_to(onumm2n10_t* num, onumm2n10_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n10_t onumm2n10_exp(onumm2n10_t* num);
void onumm2n10_exp_to(onumm2n10_t* num, onumm2n10_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n10_t onumm2n10_pow(onumm2n10_t* num, double e);
void onumm2n10_pow_to(onumm2n10_t* num, coeff_t e, onumm2n10_t* res);
// ----------------------------------------------------------------------------------------------------

#endif