#ifndef OTI_ONUMM2N5_SCALAR_FUNCTIONS_H
#define OTI_ONUMM2N5_SCALAR_FUNCTIONS_H

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic tangent function at (num).

@param[in] num: Oti number.
@param[in] dhl: Direction helper list object.
******************************************************************************************************/ 
onumm2n5_t onumm2n5_atanh(onumm2n5_t* num);
void onumm2n5_atanh_to(onumm2n5_t* num, onumm2n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic sine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n5_t onumm2n5_asinh(onumm2n5_t* num);
void onumm2n5_asinh_to(onumm2n5_t* num, onumm2n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic cosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n5_t onumm2n5_acosh(onumm2n5_t* num);
void onumm2n5_acosh_to(onumm2n5_t* num, onumm2n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic tangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n5_t onumm2n5_tanh(onumm2n5_t* num);
void onumm2n5_tanh_to(onumm2n5_t* num, onumm2n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of square root function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n5_t onumm2n5_sqrt(onumm2n5_t* num);
void onumm2n5_sqrt_to(onumm2n5_t* num, onumm2n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of cubic root function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n5_t onumm2n5_cbrt(onumm2n5_t* num);
void onumm2n5_cbrt_to(onumm2n5_t* num, onumm2n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic cosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n5_t onumm2n5_cosh(onumm2n5_t* num);
void onumm2n5_cosh_to(onumm2n5_t* num, onumm2n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic sine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n5_t onumm2n5_sinh(onumm2n5_t* num);
void onumm2n5_sinh_to(onumm2n5_t* num, onumm2n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arcsine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n5_t onumm2n5_asin(onumm2n5_t* num);
void onumm2n5_asin_to(onumm2n5_t* num, onumm2n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arccosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n5_t onumm2n5_acos(onumm2n5_t* num);
void onumm2n5_acos_to(onumm2n5_t* num, onumm2n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arctangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n5_t onumm2n5_atan(onumm2n5_t* num);
void onumm2n5_atan_to(onumm2n5_t* num, onumm2n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of the tangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n5_t onumm2n5_tan(onumm2n5_t* num);
void onumm2n5_tan_to(onumm2n5_t* num, onumm2n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of function cosine at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n5_t onumm2n5_cos(onumm2n5_t* num);
void onumm2n5_cos_to(onumm2n5_t* num, onumm2n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of function sine at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n5_t onumm2n5_sin(onumm2n5_t* num );
void onumm2n5_sin_to(onumm2n5_t* num, onumm2n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of Logarithm at base b function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n5_t onumm2n5_logb(onumm2n5_t* num, double base);
void onumm2n5_logb_to(onumm2n5_t* num, double base, onumm2n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of Logarithm at base 10 function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n5_t onumm2n5_log10(onumm2n5_t* num);
void onumm2n5_log10_to(onumm2n5_t* num, onumm2n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n5_t onumm2n5_log(onumm2n5_t* num);
void onumm2n5_log_to(onumm2n5_t* num, onumm2n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n5_t onumm2n5_exp(onumm2n5_t* num);
void onumm2n5_exp_to(onumm2n5_t* num, onumm2n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n5_t onumm2n5_pow(onumm2n5_t* num, double e);
void onumm2n5_pow_to(onumm2n5_t* num, coeff_t e, onumm2n5_t* res);
// ----------------------------------------------------------------------------------------------------

#endif