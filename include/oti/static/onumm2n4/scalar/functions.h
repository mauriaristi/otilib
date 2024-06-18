#ifndef OTI_ONUMM2N4_SCALAR_FUNCTIONS_H
#define OTI_ONUMM2N4_SCALAR_FUNCTIONS_H

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic tangent function at (num).

@param[in] num: Oti number.
@param[in] dhl: Direction helper list object.
******************************************************************************************************/ 
onumm2n4_t onumm2n4_atanh(onumm2n4_t* num);
void onumm2n4_atanh_to(onumm2n4_t* num, onumm2n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic sine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n4_t onumm2n4_asinh(onumm2n4_t* num);
void onumm2n4_asinh_to(onumm2n4_t* num, onumm2n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic cosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n4_t onumm2n4_acosh(onumm2n4_t* num);
void onumm2n4_acosh_to(onumm2n4_t* num, onumm2n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic tangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n4_t onumm2n4_tanh(onumm2n4_t* num);
void onumm2n4_tanh_to(onumm2n4_t* num, onumm2n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of square root function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n4_t onumm2n4_sqrt(onumm2n4_t* num);
void onumm2n4_sqrt_to(onumm2n4_t* num, onumm2n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of cubic root function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n4_t onumm2n4_cbrt(onumm2n4_t* num);
void onumm2n4_cbrt_to(onumm2n4_t* num, onumm2n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic cosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n4_t onumm2n4_cosh(onumm2n4_t* num);
void onumm2n4_cosh_to(onumm2n4_t* num, onumm2n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic sine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n4_t onumm2n4_sinh(onumm2n4_t* num);
void onumm2n4_sinh_to(onumm2n4_t* num, onumm2n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arcsine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n4_t onumm2n4_asin(onumm2n4_t* num);
void onumm2n4_asin_to(onumm2n4_t* num, onumm2n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arccosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n4_t onumm2n4_acos(onumm2n4_t* num);
void onumm2n4_acos_to(onumm2n4_t* num, onumm2n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arctangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n4_t onumm2n4_atan(onumm2n4_t* num);
void onumm2n4_atan_to(onumm2n4_t* num, onumm2n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of the tangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n4_t onumm2n4_tan(onumm2n4_t* num);
void onumm2n4_tan_to(onumm2n4_t* num, onumm2n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of function cosine at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n4_t onumm2n4_cos(onumm2n4_t* num);
void onumm2n4_cos_to(onumm2n4_t* num, onumm2n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of function sine at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n4_t onumm2n4_sin(onumm2n4_t* num );
void onumm2n4_sin_to(onumm2n4_t* num, onumm2n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of Logarithm at base b function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n4_t onumm2n4_logb(onumm2n4_t* num, double base);
void onumm2n4_logb_to(onumm2n4_t* num, double base, onumm2n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of Logarithm at base 10 function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n4_t onumm2n4_log10(onumm2n4_t* num);
void onumm2n4_log10_to(onumm2n4_t* num, onumm2n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n4_t onumm2n4_log(onumm2n4_t* num);
void onumm2n4_log_to(onumm2n4_t* num, onumm2n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n4_t onumm2n4_exp(onumm2n4_t* num);
void onumm2n4_exp_to(onumm2n4_t* num, onumm2n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n4_t onumm2n4_pow(onumm2n4_t* num, double e);
void onumm2n4_pow_to(onumm2n4_t* num, coeff_t e, onumm2n4_t* res);
// ----------------------------------------------------------------------------------------------------

#endif