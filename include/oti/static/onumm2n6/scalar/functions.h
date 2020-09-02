#ifndef OTI_ONUMM2N6_SCALAR_FUNCTIONS_H
#define OTI_ONUMM2N6_SCALAR_FUNCTIONS_H

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic tangent function at (num).

@param[in] num: Oti number.
@param[in] dhl: Direction helper list object.
******************************************************************************************************/ 
onumm2n6_t onumm2n6_atanh(onumm2n6_t* num);
void onumm2n6_atanh_to(onumm2n6_t* num, onumm2n6_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic sine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n6_t onumm2n6_asinh(onumm2n6_t* num);
void onumm2n6_asinh_to(onumm2n6_t* num, onumm2n6_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic cosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n6_t onumm2n6_acosh(onumm2n6_t* num);
void onumm2n6_acosh_to(onumm2n6_t* num, onumm2n6_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic tangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n6_t onumm2n6_tanh(onumm2n6_t* num);
void onumm2n6_tanh_to(onumm2n6_t* num, onumm2n6_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of square root function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n6_t onumm2n6_sqrt(onumm2n6_t* num);
void onumm2n6_sqrt_to(onumm2n6_t* num, onumm2n6_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of cubic root function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n6_t onumm2n6_cbrt(onumm2n6_t* num);
void onumm2n6_cbrt_to(onumm2n6_t* num, onumm2n6_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic cosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n6_t onumm2n6_cosh(onumm2n6_t* num);
void onumm2n6_cosh_to(onumm2n6_t* num, onumm2n6_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic sine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n6_t onumm2n6_sinh(onumm2n6_t* num);
void onumm2n6_sinh_to(onumm2n6_t* num, onumm2n6_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arcsine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n6_t onumm2n6_asin(onumm2n6_t* num);
void onumm2n6_asin_to(onumm2n6_t* num, onumm2n6_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arccosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n6_t onumm2n6_acos(onumm2n6_t* num);
void onumm2n6_acos_to(onumm2n6_t* num, onumm2n6_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arctangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n6_t onumm2n6_atan(onumm2n6_t* num);
void onumm2n6_atan_to(onumm2n6_t* num, onumm2n6_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of the tangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n6_t onumm2n6_tan(onumm2n6_t* num);
void onumm2n6_tan_to(onumm2n6_t* num, onumm2n6_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of function cosine at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n6_t onumm2n6_cos(onumm2n6_t* num);
void onumm2n6_cos_to(onumm2n6_t* num, onumm2n6_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of function sine at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n6_t onumm2n6_sin(onumm2n6_t* num );
void onumm2n6_sin_to(onumm2n6_t* num, onumm2n6_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of Logarithm at base b function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n6_t onumm2n6_logb(onumm2n6_t* num, double base);
void onumm2n6_logb_to(onumm2n6_t* num, double base, onumm2n6_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of Logarithm at base 10 function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n6_t onumm2n6_log10(onumm2n6_t* num);
void onumm2n6_log10_to(onumm2n6_t* num, onumm2n6_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n6_t onumm2n6_log(onumm2n6_t* num);
void onumm2n6_log_to(onumm2n6_t* num, onumm2n6_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n6_t onumm2n6_exp(onumm2n6_t* num);
void onumm2n6_exp_to(onumm2n6_t* num, onumm2n6_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n6_t onumm2n6_pow(onumm2n6_t* num, double e);
void onumm2n6_pow_to(onumm2n6_t* num, coeff_t e, onumm2n6_t* res);
// ----------------------------------------------------------------------------------------------------

#endif