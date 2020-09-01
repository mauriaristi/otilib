#ifndef OTI_ONUMM5N2_SCALAR_FUNCTIONS_H
#define OTI_ONUMM5N2_SCALAR_FUNCTIONS_H

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic tangent function at (num).

@param[in] num: Oti number.
@param[in] dhl: Direction helper list object.
******************************************************************************************************/ 
onumm5n2_t onumm5n2_atanh(onumm5n2_t* num);
void onumm5n2_atanh_to(onumm5n2_t* num, onumm5n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic sine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm5n2_t onumm5n2_asinh(onumm5n2_t* num);
void onumm5n2_asinh_to(onumm5n2_t* num, onumm5n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic cosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm5n2_t onumm5n2_acosh(onumm5n2_t* num);
void onumm5n2_acosh_to(onumm5n2_t* num, onumm5n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic tangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm5n2_t onumm5n2_tanh(onumm5n2_t* num);
void onumm5n2_tanh_to(onumm5n2_t* num, onumm5n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of square root function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm5n2_t onumm5n2_sqrt(onumm5n2_t* num);
void onumm5n2_sqrt_to(onumm5n2_t* num, onumm5n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of cubic root function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm5n2_t onumm5n2_cbrt(onumm5n2_t* num);
void onumm5n2_cbrt_to(onumm5n2_t* num, onumm5n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic cosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm5n2_t onumm5n2_cosh(onumm5n2_t* num);
void onumm5n2_cosh_to(onumm5n2_t* num, onumm5n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic sine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm5n2_t onumm5n2_sinh(onumm5n2_t* num);
void onumm5n2_sinh_to(onumm5n2_t* num, onumm5n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arcsine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm5n2_t onumm5n2_asin(onumm5n2_t* num);
void onumm5n2_asin_to(onumm5n2_t* num, onumm5n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arccosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm5n2_t onumm5n2_acos(onumm5n2_t* num);
void onumm5n2_acos_to(onumm5n2_t* num, onumm5n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arctangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm5n2_t onumm5n2_atan(onumm5n2_t* num);
void onumm5n2_atan_to(onumm5n2_t* num, onumm5n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of the tangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm5n2_t onumm5n2_tan(onumm5n2_t* num);
void onumm5n2_tan_to(onumm5n2_t* num, onumm5n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of function cosine at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm5n2_t onumm5n2_cos(onumm5n2_t* num);
void onumm5n2_cos_to(onumm5n2_t* num, onumm5n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of function sine at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm5n2_t onumm5n2_sin(onumm5n2_t* num );
void onumm5n2_sin_to(onumm5n2_t* num, onumm5n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of Logarithm at base b function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm5n2_t onumm5n2_logb(onumm5n2_t* num, double base);
void onumm5n2_logb_to(onumm5n2_t* num, double base, onumm5n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of Logarithm at base 10 function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm5n2_t onumm5n2_log10(onumm5n2_t* num);
void onumm5n2_log10_to(onumm5n2_t* num, onumm5n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm5n2_t onumm5n2_log(onumm5n2_t* num);
void onumm5n2_log_to(onumm5n2_t* num, onumm5n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm5n2_t onumm5n2_exp(onumm5n2_t* num);
void onumm5n2_exp_to(onumm5n2_t* num, onumm5n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm5n2_t onumm5n2_pow(onumm5n2_t* num, double e);
void onumm5n2_pow_to(onumm5n2_t* num, coeff_t e, onumm5n2_t* res);
// ----------------------------------------------------------------------------------------------------

#endif