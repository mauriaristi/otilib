#ifndef OTI_ONUMM8N1_SCALAR_FUNCTIONS_H
#define OTI_ONUMM8N1_SCALAR_FUNCTIONS_H

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic tangent function at (num).

@param[in] num: Oti number.
@param[in] dhl: Direction helper list object.
******************************************************************************************************/ 
onumm8n1_t onumm8n1_atanh(onumm8n1_t* num);
void onumm8n1_atanh_to(onumm8n1_t* num, onumm8n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic sine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm8n1_t onumm8n1_asinh(onumm8n1_t* num);
void onumm8n1_asinh_to(onumm8n1_t* num, onumm8n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic cosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm8n1_t onumm8n1_acosh(onumm8n1_t* num);
void onumm8n1_acosh_to(onumm8n1_t* num, onumm8n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic tangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm8n1_t onumm8n1_tanh(onumm8n1_t* num);
void onumm8n1_tanh_to(onumm8n1_t* num, onumm8n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of square root function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm8n1_t onumm8n1_sqrt(onumm8n1_t* num);
void onumm8n1_sqrt_to(onumm8n1_t* num, onumm8n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of cubic root function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm8n1_t onumm8n1_cbrt(onumm8n1_t* num);
void onumm8n1_cbrt_to(onumm8n1_t* num, onumm8n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic cosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm8n1_t onumm8n1_cosh(onumm8n1_t* num);
void onumm8n1_cosh_to(onumm8n1_t* num, onumm8n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic sine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm8n1_t onumm8n1_sinh(onumm8n1_t* num);
void onumm8n1_sinh_to(onumm8n1_t* num, onumm8n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arcsine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm8n1_t onumm8n1_asin(onumm8n1_t* num);
void onumm8n1_asin_to(onumm8n1_t* num, onumm8n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arccosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm8n1_t onumm8n1_acos(onumm8n1_t* num);
void onumm8n1_acos_to(onumm8n1_t* num, onumm8n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arctangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm8n1_t onumm8n1_atan(onumm8n1_t* num);
void onumm8n1_atan_to(onumm8n1_t* num, onumm8n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of the tangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm8n1_t onumm8n1_tan(onumm8n1_t* num);
void onumm8n1_tan_to(onumm8n1_t* num, onumm8n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of function cosine at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm8n1_t onumm8n1_cos(onumm8n1_t* num);
void onumm8n1_cos_to(onumm8n1_t* num, onumm8n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of function sine at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm8n1_t onumm8n1_sin(onumm8n1_t* num );
void onumm8n1_sin_to(onumm8n1_t* num, onumm8n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of Logarithm at base b function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm8n1_t onumm8n1_logb(onumm8n1_t* num, double base);
void onumm8n1_logb_to(onumm8n1_t* num, double base, onumm8n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of Logarithm at base 10 function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm8n1_t onumm8n1_log10(onumm8n1_t* num);
void onumm8n1_log10_to(onumm8n1_t* num, onumm8n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm8n1_t onumm8n1_log(onumm8n1_t* num);
void onumm8n1_log_to(onumm8n1_t* num, onumm8n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm8n1_t onumm8n1_exp(onumm8n1_t* num);
void onumm8n1_exp_to(onumm8n1_t* num, onumm8n1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm8n1_t onumm8n1_pow(onumm8n1_t* num, double e);
void onumm8n1_pow_to(onumm8n1_t* num, coeff_t e, onumm8n1_t* res);
// ----------------------------------------------------------------------------------------------------

#endif