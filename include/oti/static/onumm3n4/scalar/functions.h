#ifndef OTI_ONUMM3N4_SCALAR_FUNCTIONS_H
#define OTI_ONUMM3N4_SCALAR_FUNCTIONS_H

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic tangent function at (num).

@param[in] num: Oti number.
@param[in] dhl: Direction helper list object.
******************************************************************************************************/ 
onumm3n4_t onumm3n4_atanh(onumm3n4_t* num);
void onumm3n4_atanh_to(onumm3n4_t* num, onumm3n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic sine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm3n4_t onumm3n4_asinh(onumm3n4_t* num);
void onumm3n4_asinh_to(onumm3n4_t* num, onumm3n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic cosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm3n4_t onumm3n4_acosh(onumm3n4_t* num);
void onumm3n4_acosh_to(onumm3n4_t* num, onumm3n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic tangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm3n4_t onumm3n4_tanh(onumm3n4_t* num);
void onumm3n4_tanh_to(onumm3n4_t* num, onumm3n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of square root function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm3n4_t onumm3n4_sqrt(onumm3n4_t* num);
void onumm3n4_sqrt_to(onumm3n4_t* num, onumm3n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of cubic root function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm3n4_t onumm3n4_cbrt(onumm3n4_t* num);
void onumm3n4_cbrt_to(onumm3n4_t* num, onumm3n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic cosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm3n4_t onumm3n4_cosh(onumm3n4_t* num);
void onumm3n4_cosh_to(onumm3n4_t* num, onumm3n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic sine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm3n4_t onumm3n4_sinh(onumm3n4_t* num);
void onumm3n4_sinh_to(onumm3n4_t* num, onumm3n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arcsine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm3n4_t onumm3n4_asin(onumm3n4_t* num);
void onumm3n4_asin_to(onumm3n4_t* num, onumm3n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arccosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm3n4_t onumm3n4_acos(onumm3n4_t* num);
void onumm3n4_acos_to(onumm3n4_t* num, onumm3n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arctangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm3n4_t onumm3n4_atan(onumm3n4_t* num);
void onumm3n4_atan_to(onumm3n4_t* num, onumm3n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of the tangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm3n4_t onumm3n4_tan(onumm3n4_t* num);
void onumm3n4_tan_to(onumm3n4_t* num, onumm3n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of function cosine at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm3n4_t onumm3n4_cos(onumm3n4_t* num);
void onumm3n4_cos_to(onumm3n4_t* num, onumm3n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of function sine at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm3n4_t onumm3n4_sin(onumm3n4_t* num );
void onumm3n4_sin_to(onumm3n4_t* num, onumm3n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of Logarithm at base b function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm3n4_t onumm3n4_logb(onumm3n4_t* num, double base);
void onumm3n4_logb_to(onumm3n4_t* num, double base, onumm3n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of Logarithm at base 10 function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm3n4_t onumm3n4_log10(onumm3n4_t* num);
void onumm3n4_log10_to(onumm3n4_t* num, onumm3n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm3n4_t onumm3n4_log(onumm3n4_t* num);
void onumm3n4_log_to(onumm3n4_t* num, onumm3n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm3n4_t onumm3n4_exp(onumm3n4_t* num);
void onumm3n4_exp_to(onumm3n4_t* num, onumm3n4_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm3n4_t onumm3n4_pow(onumm3n4_t* num, double e);
void onumm3n4_pow_to(onumm3n4_t* num, coeff_t e, onumm3n4_t* res);
// ----------------------------------------------------------------------------------------------------

#endif