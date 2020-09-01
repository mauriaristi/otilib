#ifndef OTI_ONUMM5N5_SCALAR_FUNCTIONS_H
#define OTI_ONUMM5N5_SCALAR_FUNCTIONS_H

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic tangent function at (num).

@param[in] num: Oti number.
@param[in] dhl: Direction helper list object.
******************************************************************************************************/ 
onumm5n5_t onumm5n5_atanh(onumm5n5_t* num);
void onumm5n5_atanh_to(onumm5n5_t* num, onumm5n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic sine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm5n5_t onumm5n5_asinh(onumm5n5_t* num);
void onumm5n5_asinh_to(onumm5n5_t* num, onumm5n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic cosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm5n5_t onumm5n5_acosh(onumm5n5_t* num);
void onumm5n5_acosh_to(onumm5n5_t* num, onumm5n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic tangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm5n5_t onumm5n5_tanh(onumm5n5_t* num);
void onumm5n5_tanh_to(onumm5n5_t* num, onumm5n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of square root function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm5n5_t onumm5n5_sqrt(onumm5n5_t* num);
void onumm5n5_sqrt_to(onumm5n5_t* num, onumm5n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of cubic root function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm5n5_t onumm5n5_cbrt(onumm5n5_t* num);
void onumm5n5_cbrt_to(onumm5n5_t* num, onumm5n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic cosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm5n5_t onumm5n5_cosh(onumm5n5_t* num);
void onumm5n5_cosh_to(onumm5n5_t* num, onumm5n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic sine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm5n5_t onumm5n5_sinh(onumm5n5_t* num);
void onumm5n5_sinh_to(onumm5n5_t* num, onumm5n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arcsine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm5n5_t onumm5n5_asin(onumm5n5_t* num);
void onumm5n5_asin_to(onumm5n5_t* num, onumm5n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arccosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm5n5_t onumm5n5_acos(onumm5n5_t* num);
void onumm5n5_acos_to(onumm5n5_t* num, onumm5n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arctangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm5n5_t onumm5n5_atan(onumm5n5_t* num);
void onumm5n5_atan_to(onumm5n5_t* num, onumm5n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of the tangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm5n5_t onumm5n5_tan(onumm5n5_t* num);
void onumm5n5_tan_to(onumm5n5_t* num, onumm5n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of function cosine at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm5n5_t onumm5n5_cos(onumm5n5_t* num);
void onumm5n5_cos_to(onumm5n5_t* num, onumm5n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of function sine at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm5n5_t onumm5n5_sin(onumm5n5_t* num );
void onumm5n5_sin_to(onumm5n5_t* num, onumm5n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of Logarithm at base b function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm5n5_t onumm5n5_logb(onumm5n5_t* num, double base);
void onumm5n5_logb_to(onumm5n5_t* num, double base, onumm5n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of Logarithm at base 10 function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm5n5_t onumm5n5_log10(onumm5n5_t* num);
void onumm5n5_log10_to(onumm5n5_t* num, onumm5n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm5n5_t onumm5n5_log(onumm5n5_t* num);
void onumm5n5_log_to(onumm5n5_t* num, onumm5n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm5n5_t onumm5n5_exp(onumm5n5_t* num);
void onumm5n5_exp_to(onumm5n5_t* num, onumm5n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm5n5_t onumm5n5_pow(onumm5n5_t* num, double e);
void onumm5n5_pow_to(onumm5n5_t* num, coeff_t e, onumm5n5_t* res);
// ----------------------------------------------------------------------------------------------------

#endif