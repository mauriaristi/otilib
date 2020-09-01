#ifndef OTI_ONUMM3N2_SCALAR_FUNCTIONS_H
#define OTI_ONUMM3N2_SCALAR_FUNCTIONS_H

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic tangent function at (num).

@param[in] num: Oti number.
@param[in] dhl: Direction helper list object.
******************************************************************************************************/ 
onumm3n2_t onumm3n2_atanh(onumm3n2_t* num);
void onumm3n2_atanh_to(onumm3n2_t* num, onumm3n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic sine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm3n2_t onumm3n2_asinh(onumm3n2_t* num);
void onumm3n2_asinh_to(onumm3n2_t* num, onumm3n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic cosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm3n2_t onumm3n2_acosh(onumm3n2_t* num);
void onumm3n2_acosh_to(onumm3n2_t* num, onumm3n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic tangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm3n2_t onumm3n2_tanh(onumm3n2_t* num);
void onumm3n2_tanh_to(onumm3n2_t* num, onumm3n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of square root function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm3n2_t onumm3n2_sqrt(onumm3n2_t* num);
void onumm3n2_sqrt_to(onumm3n2_t* num, onumm3n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of cubic root function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm3n2_t onumm3n2_cbrt(onumm3n2_t* num);
void onumm3n2_cbrt_to(onumm3n2_t* num, onumm3n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic cosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm3n2_t onumm3n2_cosh(onumm3n2_t* num);
void onumm3n2_cosh_to(onumm3n2_t* num, onumm3n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic sine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm3n2_t onumm3n2_sinh(onumm3n2_t* num);
void onumm3n2_sinh_to(onumm3n2_t* num, onumm3n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arcsine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm3n2_t onumm3n2_asin(onumm3n2_t* num);
void onumm3n2_asin_to(onumm3n2_t* num, onumm3n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arccosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm3n2_t onumm3n2_acos(onumm3n2_t* num);
void onumm3n2_acos_to(onumm3n2_t* num, onumm3n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arctangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm3n2_t onumm3n2_atan(onumm3n2_t* num);
void onumm3n2_atan_to(onumm3n2_t* num, onumm3n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of the tangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm3n2_t onumm3n2_tan(onumm3n2_t* num);
void onumm3n2_tan_to(onumm3n2_t* num, onumm3n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of function cosine at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm3n2_t onumm3n2_cos(onumm3n2_t* num);
void onumm3n2_cos_to(onumm3n2_t* num, onumm3n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of function sine at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm3n2_t onumm3n2_sin(onumm3n2_t* num );
void onumm3n2_sin_to(onumm3n2_t* num, onumm3n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of Logarithm at base b function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm3n2_t onumm3n2_logb(onumm3n2_t* num, double base);
void onumm3n2_logb_to(onumm3n2_t* num, double base, onumm3n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of Logarithm at base 10 function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm3n2_t onumm3n2_log10(onumm3n2_t* num);
void onumm3n2_log10_to(onumm3n2_t* num, onumm3n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm3n2_t onumm3n2_log(onumm3n2_t* num);
void onumm3n2_log_to(onumm3n2_t* num, onumm3n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm3n2_t onumm3n2_exp(onumm3n2_t* num);
void onumm3n2_exp_to(onumm3n2_t* num, onumm3n2_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
onumm3n2_t onumm3n2_pow(onumm3n2_t* num, double e);
void onumm3n2_pow_to(onumm3n2_t* num, coeff_t e, onumm3n2_t* res);
// ----------------------------------------------------------------------------------------------------

#endif