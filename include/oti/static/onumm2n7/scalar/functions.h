#ifndef OTI_ONUMM2N7_SCALAR_FUNCTIONS_H
#define OTI_ONUMM2N7_SCALAR_FUNCTIONS_H

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic tangent function at (num).

@param[in] num: Oti number.
@param[in] dhl: Direction helper list object.
******************************************************************************************************/ 
onumm2n7_t onumm2n7_atanh(onumm2n7_t* num);
void onumm2n7_atanh_to(onumm2n7_t* num, onumm2n7_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic sine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n7_t onumm2n7_asinh(onumm2n7_t* num);
void onumm2n7_asinh_to(onumm2n7_t* num, onumm2n7_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic cosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n7_t onumm2n7_acosh(onumm2n7_t* num);
void onumm2n7_acosh_to(onumm2n7_t* num, onumm2n7_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic tangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n7_t onumm2n7_tanh(onumm2n7_t* num);
void onumm2n7_tanh_to(onumm2n7_t* num, onumm2n7_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of square root function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n7_t onumm2n7_sqrt(onumm2n7_t* num);
void onumm2n7_sqrt_to(onumm2n7_t* num, onumm2n7_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of cubic root function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n7_t onumm2n7_cbrt(onumm2n7_t* num);
void onumm2n7_cbrt_to(onumm2n7_t* num, onumm2n7_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic cosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n7_t onumm2n7_cosh(onumm2n7_t* num);
void onumm2n7_cosh_to(onumm2n7_t* num, onumm2n7_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic sine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n7_t onumm2n7_sinh(onumm2n7_t* num);
void onumm2n7_sinh_to(onumm2n7_t* num, onumm2n7_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arcsine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n7_t onumm2n7_asin(onumm2n7_t* num);
void onumm2n7_asin_to(onumm2n7_t* num, onumm2n7_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arccosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n7_t onumm2n7_acos(onumm2n7_t* num);
void onumm2n7_acos_to(onumm2n7_t* num, onumm2n7_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arctangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n7_t onumm2n7_atan(onumm2n7_t* num);
void onumm2n7_atan_to(onumm2n7_t* num, onumm2n7_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of the tangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n7_t onumm2n7_tan(onumm2n7_t* num);
void onumm2n7_tan_to(onumm2n7_t* num, onumm2n7_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of function cosine at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n7_t onumm2n7_cos(onumm2n7_t* num);
void onumm2n7_cos_to(onumm2n7_t* num, onumm2n7_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of function sine at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n7_t onumm2n7_sin(onumm2n7_t* num );
void onumm2n7_sin_to(onumm2n7_t* num, onumm2n7_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of Logarithm at base b function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n7_t onumm2n7_logb(onumm2n7_t* num, double base);
void onumm2n7_logb_to(onumm2n7_t* num, double base, onumm2n7_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of Logarithm at base 10 function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n7_t onumm2n7_log10(onumm2n7_t* num);
void onumm2n7_log10_to(onumm2n7_t* num, onumm2n7_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n7_t onumm2n7_log(onumm2n7_t* num);
void onumm2n7_log_to(onumm2n7_t* num, onumm2n7_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n7_t onumm2n7_exp(onumm2n7_t* num);
void onumm2n7_exp_to(onumm2n7_t* num, onumm2n7_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n7_t onumm2n7_pow(onumm2n7_t* num, double e);
void onumm2n7_pow_to(onumm2n7_t* num, coeff_t e, onumm2n7_t* res);
// ----------------------------------------------------------------------------------------------------

#endif