#ifndef OTI_ONUMM20N1_SCALAR_FUNCTIONS_H
#define OTI_ONUMM20N1_SCALAR_FUNCTIONS_H

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic tangent function at (num).

@param[in] num: Oti number.
@param[in] dhl: Direction helper list object.
******************************************************************************************************/ 
onumm20n1_t onumm20n1_atanh(onumm20n1_t* num);
void onumm20n1_atanh_to(onumm20n1_t* num, onumm20n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic sine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm20n1_t onumm20n1_asinh(onumm20n1_t* num);
void onumm20n1_asinh_to(onumm20n1_t* num, onumm20n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic cosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm20n1_t onumm20n1_acosh(onumm20n1_t* num);
void onumm20n1_acosh_to(onumm20n1_t* num, onumm20n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic tangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm20n1_t onumm20n1_tanh(onumm20n1_t* num);
void onumm20n1_tanh_to(onumm20n1_t* num, onumm20n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of square root function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm20n1_t onumm20n1_sqrt(onumm20n1_t* num);
void onumm20n1_sqrt_to(onumm20n1_t* num, onumm20n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of cubic root function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm20n1_t onumm20n1_cbrt(onumm20n1_t* num);
void onumm20n1_cbrt_to(onumm20n1_t* num, onumm20n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic cosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm20n1_t onumm20n1_cosh(onumm20n1_t* num);
void onumm20n1_cosh_to(onumm20n1_t* num, onumm20n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic sine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm20n1_t onumm20n1_sinh(onumm20n1_t* num);
void onumm20n1_sinh_to(onumm20n1_t* num, onumm20n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arcsine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm20n1_t onumm20n1_asin(onumm20n1_t* num);
void onumm20n1_asin_to(onumm20n1_t* num, onumm20n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arccosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm20n1_t onumm20n1_acos(onumm20n1_t* num);
void onumm20n1_acos_to(onumm20n1_t* num, onumm20n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arctangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm20n1_t onumm20n1_atan(onumm20n1_t* num);
void onumm20n1_atan_to(onumm20n1_t* num, onumm20n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of the tangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm20n1_t onumm20n1_tan(onumm20n1_t* num);
void onumm20n1_tan_to(onumm20n1_t* num, onumm20n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of function cosine at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm20n1_t onumm20n1_cos(onumm20n1_t* num);
void onumm20n1_cos_to(onumm20n1_t* num, onumm20n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of function sine at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm20n1_t onumm20n1_sin(onumm20n1_t* num );
void onumm20n1_sin_to(onumm20n1_t* num, onumm20n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of Logarithm at base b function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm20n1_t onumm20n1_logb(onumm20n1_t* num, double base);
void onumm20n1_logb_to(onumm20n1_t* num, double base, onumm20n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of Logarithm at base 10 function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm20n1_t onumm20n1_log10(onumm20n1_t* num);
void onumm20n1_log10_to(onumm20n1_t* num, onumm20n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm20n1_t onumm20n1_log(onumm20n1_t* num);
void onumm20n1_log_to(onumm20n1_t* num, onumm20n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm20n1_t onumm20n1_exp(onumm20n1_t* num);
void onumm20n1_exp_to(onumm20n1_t* num, onumm20n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm20n1_t onumm20n1_pow(onumm20n1_t* num, double e);
void onumm20n1_pow_to(onumm20n1_t* num, coeff_t e, onumm20n1_t* res);
// ----------------------------------------------------------------------------------------------------

#endif