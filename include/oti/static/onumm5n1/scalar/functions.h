#ifndef OTI_ONUMM5N1_SCALAR_FUNCTIONS_H
#define OTI_ONUMM5N1_SCALAR_FUNCTIONS_H

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic tangent function at (num).

@param[in] num: Oti number.
@param[in] dhl: Direction helper list object.
******************************************************************************************************/ 
onumm5n1_t onumm5n1_atanh(onumm5n1_t* num);
void onumm5n1_atanh_to(onumm5n1_t* num, onumm5n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic sine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm5n1_t onumm5n1_asinh(onumm5n1_t* num);
void onumm5n1_asinh_to(onumm5n1_t* num, onumm5n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic cosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm5n1_t onumm5n1_acosh(onumm5n1_t* num);
void onumm5n1_acosh_to(onumm5n1_t* num, onumm5n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic tangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm5n1_t onumm5n1_tanh(onumm5n1_t* num);
void onumm5n1_tanh_to(onumm5n1_t* num, onumm5n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of square root function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm5n1_t onumm5n1_sqrt(onumm5n1_t* num);
void onumm5n1_sqrt_to(onumm5n1_t* num, onumm5n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of cubic root function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm5n1_t onumm5n1_cbrt(onumm5n1_t* num);
void onumm5n1_cbrt_to(onumm5n1_t* num, onumm5n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic cosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm5n1_t onumm5n1_cosh(onumm5n1_t* num);
void onumm5n1_cosh_to(onumm5n1_t* num, onumm5n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic sine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm5n1_t onumm5n1_sinh(onumm5n1_t* num);
void onumm5n1_sinh_to(onumm5n1_t* num, onumm5n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arcsine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm5n1_t onumm5n1_asin(onumm5n1_t* num);
void onumm5n1_asin_to(onumm5n1_t* num, onumm5n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arccosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm5n1_t onumm5n1_acos(onumm5n1_t* num);
void onumm5n1_acos_to(onumm5n1_t* num, onumm5n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arctangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm5n1_t onumm5n1_atan(onumm5n1_t* num);
void onumm5n1_atan_to(onumm5n1_t* num, onumm5n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of the tangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm5n1_t onumm5n1_tan(onumm5n1_t* num);
void onumm5n1_tan_to(onumm5n1_t* num, onumm5n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of function cosine at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm5n1_t onumm5n1_cos(onumm5n1_t* num);
void onumm5n1_cos_to(onumm5n1_t* num, onumm5n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of function sine at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm5n1_t onumm5n1_sin(onumm5n1_t* num );
void onumm5n1_sin_to(onumm5n1_t* num, onumm5n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of Logarithm at base b function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm5n1_t onumm5n1_logb(onumm5n1_t* num, double base);
void onumm5n1_logb_to(onumm5n1_t* num, double base, onumm5n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of Logarithm at base 10 function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm5n1_t onumm5n1_log10(onumm5n1_t* num);
void onumm5n1_log10_to(onumm5n1_t* num, onumm5n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm5n1_t onumm5n1_log(onumm5n1_t* num);
void onumm5n1_log_to(onumm5n1_t* num, onumm5n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm5n1_t onumm5n1_exp(onumm5n1_t* num);
void onumm5n1_exp_to(onumm5n1_t* num, onumm5n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm5n1_t onumm5n1_pow(onumm5n1_t* num, double e);
void onumm5n1_pow_to(onumm5n1_t* num, coeff_t e, onumm5n1_t* res);
// ----------------------------------------------------------------------------------------------------

#endif