#ifndef OTI_ONUMM2N2_SCALAR_FUNCTIONS_H
#define OTI_ONUMM2N2_SCALAR_FUNCTIONS_H

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic tangent function at (num).

@param[in] num: Oti number.
@param[in] dhl: Direction helper list object.
******************************************************************************************************/ 
onumm2n2_t onumm2n2_atanh(onumm2n2_t* num);
void onumm2n2_atanh_to(onumm2n2_t* num, onumm2n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic sine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n2_t onumm2n2_asinh(onumm2n2_t* num);
void onumm2n2_asinh_to(onumm2n2_t* num, onumm2n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic cosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n2_t onumm2n2_acosh(onumm2n2_t* num);
void onumm2n2_acosh_to(onumm2n2_t* num, onumm2n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic tangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n2_t onumm2n2_tanh(onumm2n2_t* num);
void onumm2n2_tanh_to(onumm2n2_t* num, onumm2n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of square root function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n2_t onumm2n2_sqrt(onumm2n2_t* num);
void onumm2n2_sqrt_to(onumm2n2_t* num, onumm2n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of cubic root function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n2_t onumm2n2_cbrt(onumm2n2_t* num);
void onumm2n2_cbrt_to(onumm2n2_t* num, onumm2n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic cosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n2_t onumm2n2_cosh(onumm2n2_t* num);
void onumm2n2_cosh_to(onumm2n2_t* num, onumm2n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic sine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n2_t onumm2n2_sinh(onumm2n2_t* num);
void onumm2n2_sinh_to(onumm2n2_t* num, onumm2n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arcsine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n2_t onumm2n2_asin(onumm2n2_t* num);
void onumm2n2_asin_to(onumm2n2_t* num, onumm2n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arccosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n2_t onumm2n2_acos(onumm2n2_t* num);
void onumm2n2_acos_to(onumm2n2_t* num, onumm2n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arctangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n2_t onumm2n2_atan(onumm2n2_t* num);
void onumm2n2_atan_to(onumm2n2_t* num, onumm2n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of the tangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n2_t onumm2n2_tan(onumm2n2_t* num);
void onumm2n2_tan_to(onumm2n2_t* num, onumm2n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of function cosine at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n2_t onumm2n2_cos(onumm2n2_t* num);
void onumm2n2_cos_to(onumm2n2_t* num, onumm2n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of function sine at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n2_t onumm2n2_sin(onumm2n2_t* num );
void onumm2n2_sin_to(onumm2n2_t* num, onumm2n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of Logarithm at base b function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n2_t onumm2n2_logb(onumm2n2_t* num, double base);
void onumm2n2_logb_to(onumm2n2_t* num, double base, onumm2n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of Logarithm at base 10 function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n2_t onumm2n2_log10(onumm2n2_t* num);
void onumm2n2_log10_to(onumm2n2_t* num, onumm2n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n2_t onumm2n2_log(onumm2n2_t* num);
void onumm2n2_log_to(onumm2n2_t* num, onumm2n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n2_t onumm2n2_exp(onumm2n2_t* num);
void onumm2n2_exp_to(onumm2n2_t* num, onumm2n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm2n2_t onumm2n2_pow(onumm2n2_t* num, double e);
void onumm2n2_pow_to(onumm2n2_t* num, coeff_t e, onumm2n2_t* res);
// ----------------------------------------------------------------------------------------------------

#endif