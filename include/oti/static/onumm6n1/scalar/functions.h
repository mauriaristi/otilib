#ifndef OTI_ONUMM6N1_SCALAR_FUNCTIONS_H
#define OTI_ONUMM6N1_SCALAR_FUNCTIONS_H

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic tangent function at (num).

@param[in] num: Oti number.
@param[in] dhl: Direction helper list object.
******************************************************************************************************/ 
onumm6n1_t onumm6n1_atanh(onumm6n1_t* num);
void onumm6n1_atanh_to(onumm6n1_t* num, onumm6n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic sine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm6n1_t onumm6n1_asinh(onumm6n1_t* num);
void onumm6n1_asinh_to(onumm6n1_t* num, onumm6n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic cosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm6n1_t onumm6n1_acosh(onumm6n1_t* num);
void onumm6n1_acosh_to(onumm6n1_t* num, onumm6n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic tangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm6n1_t onumm6n1_tanh(onumm6n1_t* num);
void onumm6n1_tanh_to(onumm6n1_t* num, onumm6n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of square root function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm6n1_t onumm6n1_sqrt(onumm6n1_t* num);
void onumm6n1_sqrt_to(onumm6n1_t* num, onumm6n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of cubic root function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm6n1_t onumm6n1_cbrt(onumm6n1_t* num);
void onumm6n1_cbrt_to(onumm6n1_t* num, onumm6n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic cosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm6n1_t onumm6n1_cosh(onumm6n1_t* num);
void onumm6n1_cosh_to(onumm6n1_t* num, onumm6n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic sine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm6n1_t onumm6n1_sinh(onumm6n1_t* num);
void onumm6n1_sinh_to(onumm6n1_t* num, onumm6n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arcsine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm6n1_t onumm6n1_asin(onumm6n1_t* num);
void onumm6n1_asin_to(onumm6n1_t* num, onumm6n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arccosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm6n1_t onumm6n1_acos(onumm6n1_t* num);
void onumm6n1_acos_to(onumm6n1_t* num, onumm6n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arctangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm6n1_t onumm6n1_atan(onumm6n1_t* num);
void onumm6n1_atan_to(onumm6n1_t* num, onumm6n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of the tangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm6n1_t onumm6n1_tan(onumm6n1_t* num);
void onumm6n1_tan_to(onumm6n1_t* num, onumm6n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of function cosine at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm6n1_t onumm6n1_cos(onumm6n1_t* num);
void onumm6n1_cos_to(onumm6n1_t* num, onumm6n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of function sine at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm6n1_t onumm6n1_sin(onumm6n1_t* num );
void onumm6n1_sin_to(onumm6n1_t* num, onumm6n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of Logarithm at base b function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm6n1_t onumm6n1_logb(onumm6n1_t* num, double base);
void onumm6n1_logb_to(onumm6n1_t* num, double base, onumm6n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of Logarithm at base 10 function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm6n1_t onumm6n1_log10(onumm6n1_t* num);
void onumm6n1_log10_to(onumm6n1_t* num, onumm6n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm6n1_t onumm6n1_log(onumm6n1_t* num);
void onumm6n1_log_to(onumm6n1_t* num, onumm6n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm6n1_t onumm6n1_exp(onumm6n1_t* num);
void onumm6n1_exp_to(onumm6n1_t* num, onumm6n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm6n1_t onumm6n1_pow(onumm6n1_t* num, double e);
void onumm6n1_pow_to(onumm6n1_t* num, coeff_t e, onumm6n1_t* res);
// ----------------------------------------------------------------------------------------------------

#endif