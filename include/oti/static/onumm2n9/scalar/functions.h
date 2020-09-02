#ifndef OTI_ONUMM2N9_SCALAR_FUNCTIONS_H
#define OTI_ONUMM2N9_SCALAR_FUNCTIONS_H

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic tangent function at (num).

@param[in] num: Oti number.
@param[in] dhl: Direction helper list object.
******************************************************************************************************/ 
onumm2n9_t onumm2n9_atanh(onumm2n9_t* num);
void onumm2n9_atanh_to(onumm2n9_t* num, onumm2n9_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic sine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n9_t onumm2n9_asinh(onumm2n9_t* num);
void onumm2n9_asinh_to(onumm2n9_t* num, onumm2n9_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic cosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n9_t onumm2n9_acosh(onumm2n9_t* num);
void onumm2n9_acosh_to(onumm2n9_t* num, onumm2n9_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic tangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n9_t onumm2n9_tanh(onumm2n9_t* num);
void onumm2n9_tanh_to(onumm2n9_t* num, onumm2n9_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of square root function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n9_t onumm2n9_sqrt(onumm2n9_t* num);
void onumm2n9_sqrt_to(onumm2n9_t* num, onumm2n9_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of cubic root function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n9_t onumm2n9_cbrt(onumm2n9_t* num);
void onumm2n9_cbrt_to(onumm2n9_t* num, onumm2n9_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic cosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n9_t onumm2n9_cosh(onumm2n9_t* num);
void onumm2n9_cosh_to(onumm2n9_t* num, onumm2n9_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic sine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n9_t onumm2n9_sinh(onumm2n9_t* num);
void onumm2n9_sinh_to(onumm2n9_t* num, onumm2n9_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arcsine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n9_t onumm2n9_asin(onumm2n9_t* num);
void onumm2n9_asin_to(onumm2n9_t* num, onumm2n9_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arccosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n9_t onumm2n9_acos(onumm2n9_t* num);
void onumm2n9_acos_to(onumm2n9_t* num, onumm2n9_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arctangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n9_t onumm2n9_atan(onumm2n9_t* num);
void onumm2n9_atan_to(onumm2n9_t* num, onumm2n9_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of the tangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n9_t onumm2n9_tan(onumm2n9_t* num);
void onumm2n9_tan_to(onumm2n9_t* num, onumm2n9_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of function cosine at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n9_t onumm2n9_cos(onumm2n9_t* num);
void onumm2n9_cos_to(onumm2n9_t* num, onumm2n9_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of function sine at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n9_t onumm2n9_sin(onumm2n9_t* num );
void onumm2n9_sin_to(onumm2n9_t* num, onumm2n9_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of Logarithm at base b function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n9_t onumm2n9_logb(onumm2n9_t* num, double base);
void onumm2n9_logb_to(onumm2n9_t* num, double base, onumm2n9_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of Logarithm at base 10 function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n9_t onumm2n9_log10(onumm2n9_t* num);
void onumm2n9_log10_to(onumm2n9_t* num, onumm2n9_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n9_t onumm2n9_log(onumm2n9_t* num);
void onumm2n9_log_to(onumm2n9_t* num, onumm2n9_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n9_t onumm2n9_exp(onumm2n9_t* num);
void onumm2n9_exp_to(onumm2n9_t* num, onumm2n9_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n9_t onumm2n9_pow(onumm2n9_t* num, double e);
void onumm2n9_pow_to(onumm2n9_t* num, coeff_t e, onumm2n9_t* res);
// ----------------------------------------------------------------------------------------------------

#endif