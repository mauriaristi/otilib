#ifndef OTI_ONUMM8N2_SCALAR_FUNCTIONS_H
#define OTI_ONUMM8N2_SCALAR_FUNCTIONS_H

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic tangent function at (num).

@param[in] num: Oti number.
@param[in] dhl: Direction helper list object.
******************************************************************************************************/ 
onumm8n2_t onumm8n2_atanh(onumm8n2_t* num);
void onumm8n2_atanh_to(onumm8n2_t* num, onumm8n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic sine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm8n2_t onumm8n2_asinh(onumm8n2_t* num);
void onumm8n2_asinh_to(onumm8n2_t* num, onumm8n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic cosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm8n2_t onumm8n2_acosh(onumm8n2_t* num);
void onumm8n2_acosh_to(onumm8n2_t* num, onumm8n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic tangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm8n2_t onumm8n2_tanh(onumm8n2_t* num);
void onumm8n2_tanh_to(onumm8n2_t* num, onumm8n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of square root function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm8n2_t onumm8n2_sqrt(onumm8n2_t* num);
void onumm8n2_sqrt_to(onumm8n2_t* num, onumm8n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of cubic root function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm8n2_t onumm8n2_cbrt(onumm8n2_t* num);
void onumm8n2_cbrt_to(onumm8n2_t* num, onumm8n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic cosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm8n2_t onumm8n2_cosh(onumm8n2_t* num);
void onumm8n2_cosh_to(onumm8n2_t* num, onumm8n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic sine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm8n2_t onumm8n2_sinh(onumm8n2_t* num);
void onumm8n2_sinh_to(onumm8n2_t* num, onumm8n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arcsine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm8n2_t onumm8n2_asin(onumm8n2_t* num);
void onumm8n2_asin_to(onumm8n2_t* num, onumm8n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arccosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm8n2_t onumm8n2_acos(onumm8n2_t* num);
void onumm8n2_acos_to(onumm8n2_t* num, onumm8n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arctangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm8n2_t onumm8n2_atan(onumm8n2_t* num);
void onumm8n2_atan_to(onumm8n2_t* num, onumm8n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of the tangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm8n2_t onumm8n2_tan(onumm8n2_t* num);
void onumm8n2_tan_to(onumm8n2_t* num, onumm8n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of function cosine at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm8n2_t onumm8n2_cos(onumm8n2_t* num);
void onumm8n2_cos_to(onumm8n2_t* num, onumm8n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of function sine at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm8n2_t onumm8n2_sin(onumm8n2_t* num );
void onumm8n2_sin_to(onumm8n2_t* num, onumm8n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of Logarithm at base b function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm8n2_t onumm8n2_logb(onumm8n2_t* num, double base);
void onumm8n2_logb_to(onumm8n2_t* num, double base, onumm8n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of Logarithm at base 10 function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm8n2_t onumm8n2_log10(onumm8n2_t* num);
void onumm8n2_log10_to(onumm8n2_t* num, onumm8n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm8n2_t onumm8n2_log(onumm8n2_t* num);
void onumm8n2_log_to(onumm8n2_t* num, onumm8n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm8n2_t onumm8n2_exp(onumm8n2_t* num);
void onumm8n2_exp_to(onumm8n2_t* num, onumm8n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm8n2_t onumm8n2_pow(onumm8n2_t* num, double e);
void onumm8n2_pow_to(onumm8n2_t* num, coeff_t e, onumm8n2_t* res);
// ----------------------------------------------------------------------------------------------------

#endif