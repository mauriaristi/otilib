#ifndef OTI_ONUMM5N4_SCALAR_FUNCTIONS_H
#define OTI_ONUMM5N4_SCALAR_FUNCTIONS_H

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic tangent function at (num).

@param[in] num: Oti number.
@param[in] dhl: Direction helper list object.
******************************************************************************************************/ 
onumm5n4_t onumm5n4_atanh(onumm5n4_t* num);
void onumm5n4_atanh_to(onumm5n4_t* num, onumm5n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic sine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm5n4_t onumm5n4_asinh(onumm5n4_t* num);
void onumm5n4_asinh_to(onumm5n4_t* num, onumm5n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic cosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm5n4_t onumm5n4_acosh(onumm5n4_t* num);
void onumm5n4_acosh_to(onumm5n4_t* num, onumm5n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic tangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm5n4_t onumm5n4_tanh(onumm5n4_t* num);
void onumm5n4_tanh_to(onumm5n4_t* num, onumm5n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of square root function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm5n4_t onumm5n4_sqrt(onumm5n4_t* num);
void onumm5n4_sqrt_to(onumm5n4_t* num, onumm5n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of cubic root function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm5n4_t onumm5n4_cbrt(onumm5n4_t* num);
void onumm5n4_cbrt_to(onumm5n4_t* num, onumm5n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic cosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm5n4_t onumm5n4_cosh(onumm5n4_t* num);
void onumm5n4_cosh_to(onumm5n4_t* num, onumm5n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic sine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm5n4_t onumm5n4_sinh(onumm5n4_t* num);
void onumm5n4_sinh_to(onumm5n4_t* num, onumm5n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arcsine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm5n4_t onumm5n4_asin(onumm5n4_t* num);
void onumm5n4_asin_to(onumm5n4_t* num, onumm5n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arccosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm5n4_t onumm5n4_acos(onumm5n4_t* num);
void onumm5n4_acos_to(onumm5n4_t* num, onumm5n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arctangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm5n4_t onumm5n4_atan(onumm5n4_t* num);
void onumm5n4_atan_to(onumm5n4_t* num, onumm5n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of the tangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm5n4_t onumm5n4_tan(onumm5n4_t* num);
void onumm5n4_tan_to(onumm5n4_t* num, onumm5n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of function cosine at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm5n4_t onumm5n4_cos(onumm5n4_t* num);
void onumm5n4_cos_to(onumm5n4_t* num, onumm5n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of function sine at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm5n4_t onumm5n4_sin(onumm5n4_t* num );
void onumm5n4_sin_to(onumm5n4_t* num, onumm5n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of Logarithm at base b function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm5n4_t onumm5n4_logb(onumm5n4_t* num, double base);
void onumm5n4_logb_to(onumm5n4_t* num, double base, onumm5n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of Logarithm at base 10 function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm5n4_t onumm5n4_log10(onumm5n4_t* num);
void onumm5n4_log10_to(onumm5n4_t* num, onumm5n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm5n4_t onumm5n4_log(onumm5n4_t* num);
void onumm5n4_log_to(onumm5n4_t* num, onumm5n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm5n4_t onumm5n4_exp(onumm5n4_t* num);
void onumm5n4_exp_to(onumm5n4_t* num, onumm5n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm5n4_t onumm5n4_pow(onumm5n4_t* num, double e);
void onumm5n4_pow_to(onumm5n4_t* num, coeff_t e, onumm5n4_t* res);
// ----------------------------------------------------------------------------------------------------

#endif