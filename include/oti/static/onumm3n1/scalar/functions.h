#ifndef OTI_ONUMM3N1_SCALAR_FUNCTIONS_H
#define OTI_ONUMM3N1_SCALAR_FUNCTIONS_H

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic tangent function at (num).

@param[in] num: Oti number.
@param[in] dhl: Direction helper list object.
******************************************************************************************************/ 
onumm3n1_t onumm3n1_atanh(onumm3n1_t* num);
void onumm3n1_atanh_to(onumm3n1_t* num, onumm3n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic sine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm3n1_t onumm3n1_asinh(onumm3n1_t* num);
void onumm3n1_asinh_to(onumm3n1_t* num, onumm3n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic cosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm3n1_t onumm3n1_acosh(onumm3n1_t* num);
void onumm3n1_acosh_to(onumm3n1_t* num, onumm3n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic tangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm3n1_t onumm3n1_tanh(onumm3n1_t* num);
void onumm3n1_tanh_to(onumm3n1_t* num, onumm3n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of square root function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm3n1_t onumm3n1_sqrt(onumm3n1_t* num);
void onumm3n1_sqrt_to(onumm3n1_t* num, onumm3n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of cubic root function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm3n1_t onumm3n1_cbrt(onumm3n1_t* num);
void onumm3n1_cbrt_to(onumm3n1_t* num, onumm3n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic cosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm3n1_t onumm3n1_cosh(onumm3n1_t* num);
void onumm3n1_cosh_to(onumm3n1_t* num, onumm3n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic sine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm3n1_t onumm3n1_sinh(onumm3n1_t* num);
void onumm3n1_sinh_to(onumm3n1_t* num, onumm3n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arcsine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm3n1_t onumm3n1_asin(onumm3n1_t* num);
void onumm3n1_asin_to(onumm3n1_t* num, onumm3n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arccosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm3n1_t onumm3n1_acos(onumm3n1_t* num);
void onumm3n1_acos_to(onumm3n1_t* num, onumm3n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arctangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm3n1_t onumm3n1_atan(onumm3n1_t* num);
void onumm3n1_atan_to(onumm3n1_t* num, onumm3n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of the tangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm3n1_t onumm3n1_tan(onumm3n1_t* num);
void onumm3n1_tan_to(onumm3n1_t* num, onumm3n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of function cosine at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm3n1_t onumm3n1_cos(onumm3n1_t* num);
void onumm3n1_cos_to(onumm3n1_t* num, onumm3n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of function sine at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm3n1_t onumm3n1_sin(onumm3n1_t* num );
void onumm3n1_sin_to(onumm3n1_t* num, onumm3n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of Logarithm at base b function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm3n1_t onumm3n1_logb(onumm3n1_t* num, double base);
void onumm3n1_logb_to(onumm3n1_t* num, double base, onumm3n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of Logarithm at base 10 function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm3n1_t onumm3n1_log10(onumm3n1_t* num);
void onumm3n1_log10_to(onumm3n1_t* num, onumm3n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm3n1_t onumm3n1_log(onumm3n1_t* num);
void onumm3n1_log_to(onumm3n1_t* num, onumm3n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm3n1_t onumm3n1_exp(onumm3n1_t* num);
void onumm3n1_exp_to(onumm3n1_t* num, onumm3n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm3n1_t onumm3n1_pow(onumm3n1_t* num, double e);
void onumm3n1_pow_to(onumm3n1_t* num, coeff_t e, onumm3n1_t* res);
// ----------------------------------------------------------------------------------------------------

#endif