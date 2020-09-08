#ifndef OTI_ONUMM6N2_SCALAR_FUNCTIONS_H
#define OTI_ONUMM6N2_SCALAR_FUNCTIONS_H

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic tangent function at (num).

@param[in] num: Oti number.
@param[in] dhl: Direction helper list object.
******************************************************************************************************/ 
onumm6n2_t onumm6n2_atanh(onumm6n2_t* num);
void onumm6n2_atanh_to(onumm6n2_t* num, onumm6n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic sine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm6n2_t onumm6n2_asinh(onumm6n2_t* num);
void onumm6n2_asinh_to(onumm6n2_t* num, onumm6n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic cosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm6n2_t onumm6n2_acosh(onumm6n2_t* num);
void onumm6n2_acosh_to(onumm6n2_t* num, onumm6n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic tangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm6n2_t onumm6n2_tanh(onumm6n2_t* num);
void onumm6n2_tanh_to(onumm6n2_t* num, onumm6n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of square root function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm6n2_t onumm6n2_sqrt(onumm6n2_t* num);
void onumm6n2_sqrt_to(onumm6n2_t* num, onumm6n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of cubic root function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm6n2_t onumm6n2_cbrt(onumm6n2_t* num);
void onumm6n2_cbrt_to(onumm6n2_t* num, onumm6n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic cosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm6n2_t onumm6n2_cosh(onumm6n2_t* num);
void onumm6n2_cosh_to(onumm6n2_t* num, onumm6n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic sine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm6n2_t onumm6n2_sinh(onumm6n2_t* num);
void onumm6n2_sinh_to(onumm6n2_t* num, onumm6n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arcsine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm6n2_t onumm6n2_asin(onumm6n2_t* num);
void onumm6n2_asin_to(onumm6n2_t* num, onumm6n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arccosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm6n2_t onumm6n2_acos(onumm6n2_t* num);
void onumm6n2_acos_to(onumm6n2_t* num, onumm6n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arctangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm6n2_t onumm6n2_atan(onumm6n2_t* num);
void onumm6n2_atan_to(onumm6n2_t* num, onumm6n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of the tangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm6n2_t onumm6n2_tan(onumm6n2_t* num);
void onumm6n2_tan_to(onumm6n2_t* num, onumm6n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of function cosine at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm6n2_t onumm6n2_cos(onumm6n2_t* num);
void onumm6n2_cos_to(onumm6n2_t* num, onumm6n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of function sine at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm6n2_t onumm6n2_sin(onumm6n2_t* num );
void onumm6n2_sin_to(onumm6n2_t* num, onumm6n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of Logarithm at base b function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm6n2_t onumm6n2_logb(onumm6n2_t* num, double base);
void onumm6n2_logb_to(onumm6n2_t* num, double base, onumm6n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of Logarithm at base 10 function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm6n2_t onumm6n2_log10(onumm6n2_t* num);
void onumm6n2_log10_to(onumm6n2_t* num, onumm6n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm6n2_t onumm6n2_log(onumm6n2_t* num);
void onumm6n2_log_to(onumm6n2_t* num, onumm6n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm6n2_t onumm6n2_exp(onumm6n2_t* num);
void onumm6n2_exp_to(onumm6n2_t* num, onumm6n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm6n2_t onumm6n2_pow(onumm6n2_t* num, double e);
void onumm6n2_pow_to(onumm6n2_t* num, coeff_t e, onumm6n2_t* res);
// ----------------------------------------------------------------------------------------------------

#endif