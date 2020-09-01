#ifndef OTI_ONUMM3N5_SCALAR_FUNCTIONS_H
#define OTI_ONUMM3N5_SCALAR_FUNCTIONS_H

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic tangent function at (num).

@param[in] num: Oti number.
@param[in] dhl: Direction helper list object.
******************************************************************************************************/ 
onumm3n5_t onumm3n5_atanh(onumm3n5_t* num);
void onumm3n5_atanh_to(onumm3n5_t* num, onumm3n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic sine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm3n5_t onumm3n5_asinh(onumm3n5_t* num);
void onumm3n5_asinh_to(onumm3n5_t* num, onumm3n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic cosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm3n5_t onumm3n5_acosh(onumm3n5_t* num);
void onumm3n5_acosh_to(onumm3n5_t* num, onumm3n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic tangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm3n5_t onumm3n5_tanh(onumm3n5_t* num);
void onumm3n5_tanh_to(onumm3n5_t* num, onumm3n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of square root function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm3n5_t onumm3n5_sqrt(onumm3n5_t* num);
void onumm3n5_sqrt_to(onumm3n5_t* num, onumm3n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of cubic root function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm3n5_t onumm3n5_cbrt(onumm3n5_t* num);
void onumm3n5_cbrt_to(onumm3n5_t* num, onumm3n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic cosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm3n5_t onumm3n5_cosh(onumm3n5_t* num);
void onumm3n5_cosh_to(onumm3n5_t* num, onumm3n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic sine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm3n5_t onumm3n5_sinh(onumm3n5_t* num);
void onumm3n5_sinh_to(onumm3n5_t* num, onumm3n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arcsine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm3n5_t onumm3n5_asin(onumm3n5_t* num);
void onumm3n5_asin_to(onumm3n5_t* num, onumm3n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arccosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm3n5_t onumm3n5_acos(onumm3n5_t* num);
void onumm3n5_acos_to(onumm3n5_t* num, onumm3n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arctangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm3n5_t onumm3n5_atan(onumm3n5_t* num);
void onumm3n5_atan_to(onumm3n5_t* num, onumm3n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of the tangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm3n5_t onumm3n5_tan(onumm3n5_t* num);
void onumm3n5_tan_to(onumm3n5_t* num, onumm3n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of function cosine at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm3n5_t onumm3n5_cos(onumm3n5_t* num);
void onumm3n5_cos_to(onumm3n5_t* num, onumm3n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of function sine at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm3n5_t onumm3n5_sin(onumm3n5_t* num );
void onumm3n5_sin_to(onumm3n5_t* num, onumm3n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of Logarithm at base b function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm3n5_t onumm3n5_logb(onumm3n5_t* num, double base);
void onumm3n5_logb_to(onumm3n5_t* num, double base, onumm3n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of Logarithm at base 10 function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm3n5_t onumm3n5_log10(onumm3n5_t* num);
void onumm3n5_log10_to(onumm3n5_t* num, onumm3n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm3n5_t onumm3n5_log(onumm3n5_t* num);
void onumm3n5_log_to(onumm3n5_t* num, onumm3n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm3n5_t onumm3n5_exp(onumm3n5_t* num);
void onumm3n5_exp_to(onumm3n5_t* num, onumm3n5_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm3n5_t onumm3n5_pow(onumm3n5_t* num, double e);
void onumm3n5_pow_to(onumm3n5_t* num, coeff_t e, onumm3n5_t* res);
// ----------------------------------------------------------------------------------------------------

#endif