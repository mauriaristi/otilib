#ifndef OTI_ONUMM5N3_SCALAR_FUNCTIONS_H
#define OTI_ONUMM5N3_SCALAR_FUNCTIONS_H

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic tangent function at (num).

@param[in] num: Oti number.
@param[in] dhl: Direction helper list object.
******************************************************************************************************/ 
onumm5n3_t onumm5n3_atanh(onumm5n3_t* num);
void onumm5n3_atanh_to(onumm5n3_t* num, onumm5n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic sine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm5n3_t onumm5n3_asinh(onumm5n3_t* num);
void onumm5n3_asinh_to(onumm5n3_t* num, onumm5n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic cosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm5n3_t onumm5n3_acosh(onumm5n3_t* num);
void onumm5n3_acosh_to(onumm5n3_t* num, onumm5n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic tangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm5n3_t onumm5n3_tanh(onumm5n3_t* num);
void onumm5n3_tanh_to(onumm5n3_t* num, onumm5n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of square root function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm5n3_t onumm5n3_sqrt(onumm5n3_t* num);
void onumm5n3_sqrt_to(onumm5n3_t* num, onumm5n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of cubic root function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm5n3_t onumm5n3_cbrt(onumm5n3_t* num);
void onumm5n3_cbrt_to(onumm5n3_t* num, onumm5n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic cosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm5n3_t onumm5n3_cosh(onumm5n3_t* num);
void onumm5n3_cosh_to(onumm5n3_t* num, onumm5n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic sine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm5n3_t onumm5n3_sinh(onumm5n3_t* num);
void onumm5n3_sinh_to(onumm5n3_t* num, onumm5n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arcsine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm5n3_t onumm5n3_asin(onumm5n3_t* num);
void onumm5n3_asin_to(onumm5n3_t* num, onumm5n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arccosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm5n3_t onumm5n3_acos(onumm5n3_t* num);
void onumm5n3_acos_to(onumm5n3_t* num, onumm5n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arctangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm5n3_t onumm5n3_atan(onumm5n3_t* num);
void onumm5n3_atan_to(onumm5n3_t* num, onumm5n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of the tangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm5n3_t onumm5n3_tan(onumm5n3_t* num);
void onumm5n3_tan_to(onumm5n3_t* num, onumm5n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of function cosine at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm5n3_t onumm5n3_cos(onumm5n3_t* num);
void onumm5n3_cos_to(onumm5n3_t* num, onumm5n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of function sine at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm5n3_t onumm5n3_sin(onumm5n3_t* num );
void onumm5n3_sin_to(onumm5n3_t* num, onumm5n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of Logarithm at base b function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm5n3_t onumm5n3_logb(onumm5n3_t* num, double base);
void onumm5n3_logb_to(onumm5n3_t* num, double base, onumm5n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of Logarithm at base 10 function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm5n3_t onumm5n3_log10(onumm5n3_t* num);
void onumm5n3_log10_to(onumm5n3_t* num, onumm5n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm5n3_t onumm5n3_log(onumm5n3_t* num);
void onumm5n3_log_to(onumm5n3_t* num, onumm5n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm5n3_t onumm5n3_exp(onumm5n3_t* num);
void onumm5n3_exp_to(onumm5n3_t* num, onumm5n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm5n3_t onumm5n3_pow(onumm5n3_t* num, double e);
void onumm5n3_pow_to(onumm5n3_t* num, coeff_t e, onumm5n3_t* res);
// ----------------------------------------------------------------------------------------------------

#endif