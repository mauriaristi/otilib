#ifndef OTI_ONUMM2N1_SCALAR_FUNCTIONS_H
#define OTI_ONUMM2N1_SCALAR_FUNCTIONS_H

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic tangent function at (num).

@param[in] num: Oti number.
@param[in] dhl: Direction helper list object.
******************************************************************************************************/ 
onumm2n1_t onumm2n1_atanh(onumm2n1_t* num);
void onumm2n1_atanh_to(onumm2n1_t* num, onumm2n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic sine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n1_t onumm2n1_asinh(onumm2n1_t* num);
void onumm2n1_asinh_to(onumm2n1_t* num, onumm2n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic cosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n1_t onumm2n1_acosh(onumm2n1_t* num);
void onumm2n1_acosh_to(onumm2n1_t* num, onumm2n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic tangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n1_t onumm2n1_tanh(onumm2n1_t* num);
void onumm2n1_tanh_to(onumm2n1_t* num, onumm2n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of square root function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n1_t onumm2n1_sqrt(onumm2n1_t* num);
void onumm2n1_sqrt_to(onumm2n1_t* num, onumm2n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of cubic root function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n1_t onumm2n1_cbrt(onumm2n1_t* num);
void onumm2n1_cbrt_to(onumm2n1_t* num, onumm2n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic cosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n1_t onumm2n1_cosh(onumm2n1_t* num);
void onumm2n1_cosh_to(onumm2n1_t* num, onumm2n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic sine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n1_t onumm2n1_sinh(onumm2n1_t* num);
void onumm2n1_sinh_to(onumm2n1_t* num, onumm2n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arcsine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n1_t onumm2n1_asin(onumm2n1_t* num);
void onumm2n1_asin_to(onumm2n1_t* num, onumm2n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arccosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n1_t onumm2n1_acos(onumm2n1_t* num);
void onumm2n1_acos_to(onumm2n1_t* num, onumm2n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arctangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n1_t onumm2n1_atan(onumm2n1_t* num);
void onumm2n1_atan_to(onumm2n1_t* num, onumm2n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of the tangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n1_t onumm2n1_tan(onumm2n1_t* num);
void onumm2n1_tan_to(onumm2n1_t* num, onumm2n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of function cosine at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n1_t onumm2n1_cos(onumm2n1_t* num);
void onumm2n1_cos_to(onumm2n1_t* num, onumm2n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of function sine at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n1_t onumm2n1_sin(onumm2n1_t* num );
void onumm2n1_sin_to(onumm2n1_t* num, onumm2n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of Logarithm at base b function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n1_t onumm2n1_logb(onumm2n1_t* num, double base);
void onumm2n1_logb_to(onumm2n1_t* num, double base, onumm2n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of Logarithm at base 10 function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n1_t onumm2n1_log10(onumm2n1_t* num);
void onumm2n1_log10_to(onumm2n1_t* num, onumm2n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n1_t onumm2n1_log(onumm2n1_t* num);
void onumm2n1_log_to(onumm2n1_t* num, onumm2n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n1_t onumm2n1_exp(onumm2n1_t* num);
void onumm2n1_exp_to(onumm2n1_t* num, onumm2n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n1_t onumm2n1_pow(onumm2n1_t* num, double e);
void onumm2n1_pow_to(onumm2n1_t* num, coeff_t e, onumm2n1_t* res);
// ----------------------------------------------------------------------------------------------------

#endif