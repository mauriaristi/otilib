#ifndef OTI_MDNUM1_SCALAR_FUNCTIONS_H
#define OTI_MDNUM1_SCALAR_FUNCTIONS_H

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic tangent function at (num).

@param[in] num: Oti number.
@param[in] dhl: Direction helper list object.
******************************************************************************************************/ 
mdnum1_t mdnum1_atanh(mdnum1_t* num);
void mdnum1_atanh_to(mdnum1_t* num, mdnum1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic sine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum1_t mdnum1_asinh(mdnum1_t* num);
void mdnum1_asinh_to(mdnum1_t* num, mdnum1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of inverse hyperbolic cosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum1_t mdnum1_acosh(mdnum1_t* num);
void mdnum1_acosh_to(mdnum1_t* num, mdnum1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic tangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum1_t mdnum1_tanh(mdnum1_t* num);
void mdnum1_tanh_to(mdnum1_t* num, mdnum1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of square root function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum1_t mdnum1_sqrt(mdnum1_t* num);
void mdnum1_sqrt_to(mdnum1_t* num, mdnum1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of cubic root function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum1_t mdnum1_cbrt(mdnum1_t* num);
void mdnum1_cbrt_to(mdnum1_t* num, mdnum1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic cosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum1_t mdnum1_cosh(mdnum1_t* num);
void mdnum1_cosh_to(mdnum1_t* num, mdnum1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of hiperbolic sine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum1_t mdnum1_sinh(mdnum1_t* num);
void mdnum1_sinh_to(mdnum1_t* num, mdnum1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arcsine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum1_t mdnum1_asin(mdnum1_t* num);
void mdnum1_asin_to(mdnum1_t* num, mdnum1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arccosine function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum1_t mdnum1_acos(mdnum1_t* num);
void mdnum1_acos_to(mdnum1_t* num, mdnum1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of arctangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum1_t mdnum1_atan(mdnum1_t* num);
void mdnum1_atan_to(mdnum1_t* num, mdnum1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of the tangent function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum1_t mdnum1_tan(mdnum1_t* num);
void mdnum1_tan_to(mdnum1_t* num, mdnum1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of function cosine at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum1_t mdnum1_cos(mdnum1_t* num);
void mdnum1_cos_to(mdnum1_t* num, mdnum1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of function sine at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum1_t mdnum1_sin(mdnum1_t* num );
void mdnum1_sin_to(mdnum1_t* num, mdnum1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of Logarithm at base b function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum1_t mdnum1_logb(mdnum1_t* num, double base);
void mdnum1_logb_to(mdnum1_t* num, double base, mdnum1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of Logarithm at base 10 function at (num).

@param[in] num Oti number.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum1_t mdnum1_log10(mdnum1_t* num);
void mdnum1_log10_to(mdnum1_t* num, mdnum1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum1_t mdnum1_log(mdnum1_t* num);
void mdnum1_log_to(mdnum1_t* num, mdnum1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum1_t mdnum1_exp(mdnum1_t* num);
void mdnum1_exp_to(mdnum1_t* num, mdnum1_t* res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Evaluation of natural logarithm function at (num).

@param[in] num Oti number.
@param[in] b Real number. Base of the logarithm to be evaluated.
@param[in] dhl Direction helper list object.
******************************************************************************************************/ 
mdnum1_t mdnum1_pow(mdnum1_t* num, double e);
void mdnum1_pow_to(mdnum1_t* num, coeff_t e, mdnum1_t* res);
// ----------------------------------------------------------------------------------------------------

#endif