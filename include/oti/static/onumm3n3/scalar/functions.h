#ifndef OTI_ONUMM3N3_SCALAR_FUNCTIONS_H
#define OTI_ONUMM3N3_SCALAR_FUNCTIONS_H

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic tangent function at (num).

@param[in] num: Oti number.
@param[in] dhl: Direction helper list object.
******************************************************************************************************/ 
onumm3n3_t onumm3n3_atanh(onumm3n3_t* num);
void onumm3n3_atanh_to(onumm3n3_t* num, onumm3n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic sine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm3n3_t onumm3n3_asinh(onumm3n3_t* num);
void onumm3n3_asinh_to(onumm3n3_t* num, onumm3n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic cosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm3n3_t onumm3n3_acosh(onumm3n3_t* num);
void onumm3n3_acosh_to(onumm3n3_t* num, onumm3n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic tangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm3n3_t onumm3n3_tanh(onumm3n3_t* num);
void onumm3n3_tanh_to(onumm3n3_t* num, onumm3n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of square root function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm3n3_t onumm3n3_sqrt(onumm3n3_t* num);
void onumm3n3_sqrt_to(onumm3n3_t* num, onumm3n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of cubic root function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm3n3_t onumm3n3_cbrt(onumm3n3_t* num);
void onumm3n3_cbrt_to(onumm3n3_t* num, onumm3n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic cosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm3n3_t onumm3n3_cosh(onumm3n3_t* num);
void onumm3n3_cosh_to(onumm3n3_t* num, onumm3n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic sine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm3n3_t onumm3n3_sinh(onumm3n3_t* num);
void onumm3n3_sinh_to(onumm3n3_t* num, onumm3n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arcsine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm3n3_t onumm3n3_asin(onumm3n3_t* num);
void onumm3n3_asin_to(onumm3n3_t* num, onumm3n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arccosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm3n3_t onumm3n3_acos(onumm3n3_t* num);
void onumm3n3_acos_to(onumm3n3_t* num, onumm3n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arctangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm3n3_t onumm3n3_atan(onumm3n3_t* num);
void onumm3n3_atan_to(onumm3n3_t* num, onumm3n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of the tangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm3n3_t onumm3n3_tan(onumm3n3_t* num);
void onumm3n3_tan_to(onumm3n3_t* num, onumm3n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of function cosine at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm3n3_t onumm3n3_cos(onumm3n3_t* num);
void onumm3n3_cos_to(onumm3n3_t* num, onumm3n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of function sine at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm3n3_t onumm3n3_sin(onumm3n3_t* num );
void onumm3n3_sin_to(onumm3n3_t* num, onumm3n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of Logarithm at base b function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm3n3_t onumm3n3_logb(onumm3n3_t* num, double base);
void onumm3n3_logb_to(onumm3n3_t* num, double base, onumm3n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of Logarithm at base 10 function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm3n3_t onumm3n3_log10(onumm3n3_t* num);
void onumm3n3_log10_to(onumm3n3_t* num, onumm3n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm3n3_t onumm3n3_log(onumm3n3_t* num);
void onumm3n3_log_to(onumm3n3_t* num, onumm3n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm3n3_t onumm3n3_exp(onumm3n3_t* num);
void onumm3n3_exp_to(onumm3n3_t* num, onumm3n3_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm3n3_t onumm3n3_pow(onumm3n3_t* num, double e);
void onumm3n3_pow_to(onumm3n3_t* num, coeff_t e, onumm3n3_t* res);
// ----------------------------------------------------------------------------------------------------

#endif