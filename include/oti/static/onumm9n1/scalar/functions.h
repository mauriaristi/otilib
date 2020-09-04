#ifndef OTI_ONUMM9N1_SCALAR_FUNCTIONS_H
#define OTI_ONUMM9N1_SCALAR_FUNCTIONS_H

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic tangent function at (num).

@param[in] num: Oti number.
@param[in] dhl: Direction helper list object.
******************************************************************************************************/ 
onumm9n1_t onumm9n1_atanh(onumm9n1_t* num);
void onumm9n1_atanh_to(onumm9n1_t* num, onumm9n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic sine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm9n1_t onumm9n1_asinh(onumm9n1_t* num);
void onumm9n1_asinh_to(onumm9n1_t* num, onumm9n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic cosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm9n1_t onumm9n1_acosh(onumm9n1_t* num);
void onumm9n1_acosh_to(onumm9n1_t* num, onumm9n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic tangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm9n1_t onumm9n1_tanh(onumm9n1_t* num);
void onumm9n1_tanh_to(onumm9n1_t* num, onumm9n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of square root function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm9n1_t onumm9n1_sqrt(onumm9n1_t* num);
void onumm9n1_sqrt_to(onumm9n1_t* num, onumm9n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of cubic root function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm9n1_t onumm9n1_cbrt(onumm9n1_t* num);
void onumm9n1_cbrt_to(onumm9n1_t* num, onumm9n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic cosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm9n1_t onumm9n1_cosh(onumm9n1_t* num);
void onumm9n1_cosh_to(onumm9n1_t* num, onumm9n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic sine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm9n1_t onumm9n1_sinh(onumm9n1_t* num);
void onumm9n1_sinh_to(onumm9n1_t* num, onumm9n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arcsine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm9n1_t onumm9n1_asin(onumm9n1_t* num);
void onumm9n1_asin_to(onumm9n1_t* num, onumm9n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arccosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm9n1_t onumm9n1_acos(onumm9n1_t* num);
void onumm9n1_acos_to(onumm9n1_t* num, onumm9n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arctangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm9n1_t onumm9n1_atan(onumm9n1_t* num);
void onumm9n1_atan_to(onumm9n1_t* num, onumm9n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of the tangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm9n1_t onumm9n1_tan(onumm9n1_t* num);
void onumm9n1_tan_to(onumm9n1_t* num, onumm9n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of function cosine at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm9n1_t onumm9n1_cos(onumm9n1_t* num);
void onumm9n1_cos_to(onumm9n1_t* num, onumm9n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of function sine at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm9n1_t onumm9n1_sin(onumm9n1_t* num );
void onumm9n1_sin_to(onumm9n1_t* num, onumm9n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of Logarithm at base b function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm9n1_t onumm9n1_logb(onumm9n1_t* num, double base);
void onumm9n1_logb_to(onumm9n1_t* num, double base, onumm9n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of Logarithm at base 10 function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm9n1_t onumm9n1_log10(onumm9n1_t* num);
void onumm9n1_log10_to(onumm9n1_t* num, onumm9n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm9n1_t onumm9n1_log(onumm9n1_t* num);
void onumm9n1_log_to(onumm9n1_t* num, onumm9n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm9n1_t onumm9n1_exp(onumm9n1_t* num);
void onumm9n1_exp_to(onumm9n1_t* num, onumm9n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm9n1_t onumm9n1_pow(onumm9n1_t* num, double e);
void onumm9n1_pow_to(onumm9n1_t* num, coeff_t e, onumm9n1_t* res);
// ----------------------------------------------------------------------------------------------------

#endif