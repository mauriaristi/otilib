#ifndef OTI_ONUMM4N2_SCALAR_FUNCTIONS_H
#define OTI_ONUMM4N2_SCALAR_FUNCTIONS_H

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic tangent function at (num).

@param[in] num: Oti number.
@param[in] dhl: Direction helper list object.
******************************************************************************************************/ 
onumm4n2_t onumm4n2_atanh(onumm4n2_t* num);
void onumm4n2_atanh_to(onumm4n2_t* num, onumm4n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic sine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm4n2_t onumm4n2_asinh(onumm4n2_t* num);
void onumm4n2_asinh_to(onumm4n2_t* num, onumm4n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic cosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm4n2_t onumm4n2_acosh(onumm4n2_t* num);
void onumm4n2_acosh_to(onumm4n2_t* num, onumm4n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic tangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm4n2_t onumm4n2_tanh(onumm4n2_t* num);
void onumm4n2_tanh_to(onumm4n2_t* num, onumm4n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of square root function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm4n2_t onumm4n2_sqrt(onumm4n2_t* num);
void onumm4n2_sqrt_to(onumm4n2_t* num, onumm4n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of cubic root function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm4n2_t onumm4n2_cbrt(onumm4n2_t* num);
void onumm4n2_cbrt_to(onumm4n2_t* num, onumm4n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic cosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm4n2_t onumm4n2_cosh(onumm4n2_t* num);
void onumm4n2_cosh_to(onumm4n2_t* num, onumm4n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic sine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm4n2_t onumm4n2_sinh(onumm4n2_t* num);
void onumm4n2_sinh_to(onumm4n2_t* num, onumm4n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arcsine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm4n2_t onumm4n2_asin(onumm4n2_t* num);
void onumm4n2_asin_to(onumm4n2_t* num, onumm4n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arccosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm4n2_t onumm4n2_acos(onumm4n2_t* num);
void onumm4n2_acos_to(onumm4n2_t* num, onumm4n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arctangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm4n2_t onumm4n2_atan(onumm4n2_t* num);
void onumm4n2_atan_to(onumm4n2_t* num, onumm4n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of the tangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm4n2_t onumm4n2_tan(onumm4n2_t* num);
void onumm4n2_tan_to(onumm4n2_t* num, onumm4n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of function cosine at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm4n2_t onumm4n2_cos(onumm4n2_t* num);
void onumm4n2_cos_to(onumm4n2_t* num, onumm4n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of function sine at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm4n2_t onumm4n2_sin(onumm4n2_t* num );
void onumm4n2_sin_to(onumm4n2_t* num, onumm4n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of Logarithm at base b function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm4n2_t onumm4n2_logb(onumm4n2_t* num, double base);
void onumm4n2_logb_to(onumm4n2_t* num, double base, onumm4n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of Logarithm at base 10 function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm4n2_t onumm4n2_log10(onumm4n2_t* num);
void onumm4n2_log10_to(onumm4n2_t* num, onumm4n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm4n2_t onumm4n2_log(onumm4n2_t* num);
void onumm4n2_log_to(onumm4n2_t* num, onumm4n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm4n2_t onumm4n2_exp(onumm4n2_t* num);
void onumm4n2_exp_to(onumm4n2_t* num, onumm4n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm4n2_t onumm4n2_pow(onumm4n2_t* num, double e);
void onumm4n2_pow_to(onumm4n2_t* num, coeff_t e, onumm4n2_t* res);
// ----------------------------------------------------------------------------------------------------

#endif