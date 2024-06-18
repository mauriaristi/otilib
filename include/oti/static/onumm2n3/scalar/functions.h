#ifndef OTI_ONUMM2N3_SCALAR_FUNCTIONS_H
#define OTI_ONUMM2N3_SCALAR_FUNCTIONS_H

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic tangent function at (num).

@param[in] num: Oti number.
@param[in] dhl: Direction helper list object.
******************************************************************************************************/ 
onumm2n3_t onumm2n3_atanh(onumm2n3_t* num);
void onumm2n3_atanh_to(onumm2n3_t* num, onumm2n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic sine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n3_t onumm2n3_asinh(onumm2n3_t* num);
void onumm2n3_asinh_to(onumm2n3_t* num, onumm2n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic cosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n3_t onumm2n3_acosh(onumm2n3_t* num);
void onumm2n3_acosh_to(onumm2n3_t* num, onumm2n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic tangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n3_t onumm2n3_tanh(onumm2n3_t* num);
void onumm2n3_tanh_to(onumm2n3_t* num, onumm2n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of square root function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n3_t onumm2n3_sqrt(onumm2n3_t* num);
void onumm2n3_sqrt_to(onumm2n3_t* num, onumm2n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of cubic root function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n3_t onumm2n3_cbrt(onumm2n3_t* num);
void onumm2n3_cbrt_to(onumm2n3_t* num, onumm2n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic cosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n3_t onumm2n3_cosh(onumm2n3_t* num);
void onumm2n3_cosh_to(onumm2n3_t* num, onumm2n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic sine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n3_t onumm2n3_sinh(onumm2n3_t* num);
void onumm2n3_sinh_to(onumm2n3_t* num, onumm2n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arcsine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n3_t onumm2n3_asin(onumm2n3_t* num);
void onumm2n3_asin_to(onumm2n3_t* num, onumm2n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arccosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n3_t onumm2n3_acos(onumm2n3_t* num);
void onumm2n3_acos_to(onumm2n3_t* num, onumm2n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arctangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n3_t onumm2n3_atan(onumm2n3_t* num);
void onumm2n3_atan_to(onumm2n3_t* num, onumm2n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of the tangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n3_t onumm2n3_tan(onumm2n3_t* num);
void onumm2n3_tan_to(onumm2n3_t* num, onumm2n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of function cosine at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n3_t onumm2n3_cos(onumm2n3_t* num);
void onumm2n3_cos_to(onumm2n3_t* num, onumm2n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of function sine at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n3_t onumm2n3_sin(onumm2n3_t* num );
void onumm2n3_sin_to(onumm2n3_t* num, onumm2n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of Logarithm at base b function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n3_t onumm2n3_logb(onumm2n3_t* num, double base);
void onumm2n3_logb_to(onumm2n3_t* num, double base, onumm2n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of Logarithm at base 10 function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n3_t onumm2n3_log10(onumm2n3_t* num);
void onumm2n3_log10_to(onumm2n3_t* num, onumm2n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n3_t onumm2n3_log(onumm2n3_t* num);
void onumm2n3_log_to(onumm2n3_t* num, onumm2n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n3_t onumm2n3_exp(onumm2n3_t* num);
void onumm2n3_exp_to(onumm2n3_t* num, onumm2n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n3_t onumm2n3_pow(onumm2n3_t* num, double e);
void onumm2n3_pow_to(onumm2n3_t* num, coeff_t e, onumm2n3_t* res);
// ----------------------------------------------------------------------------------------------------

#endif