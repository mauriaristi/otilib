


/**************************************************************************************************//**
@brief Derivatives of the two argument inverse tangent function. 

@param x Evaluation point.
@param y Evaluation point.
@param order Maximum order of derivative requested.
@param[out] derivs Array with the derivatives information. It must come allocated.
******************************************************************************************************/
void der_r_atan2(coeff_t x, coeff_t y, ord_t order, coeff_t* derivs);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Derivatives of the base b logarith, function. 

@param x Evaluation point.
@param base Base of the logarithm.
@param order Maximum order of derivative requested.
@param[out] derivs Array with the derivatives information. It must come allocated.
******************************************************************************************************/
void der_r_logb(coeff_t x, coeff_t base, ord_t order, coeff_t* derivs);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Derivatives of the base 10 logarithm function. 

@param x Evaluation point.
@param order Maximum order of derivative requested.
@param[out] derivs Array with the derivatives information. It must come allocated.
******************************************************************************************************/
void der_r_log10(coeff_t x, ord_t order, coeff_t* derivs);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Derivatives of the inverse hyperbolic tangent function. 

@param x Evaluation point.
@param order Maximum order of derivative requested.
@param[out] derivs Array with the derivatives information. It must come allocated.
******************************************************************************************************/
void der_r_atanh(coeff_t x, ord_t order, coeff_t* derivs);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Derivatives of the inverse hyperbolic sine function. 

@param x Evaluation point.
@param order Maximum order of derivative requested.
@param[out] derivs Array with the derivatives information. It must come allocated.
******************************************************************************************************/
void der_r_asinh(coeff_t x, ord_t order, coeff_t* derivs);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Derivatives of the inverse hyperbolic cosine function. 

@param x Evaluation point.
@param order Maximum order of derivative requested.
@param[out] derivs Array with the derivatives information. It must come allocated.
******************************************************************************************************/
void der_r_acosh(coeff_t x, ord_t order, coeff_t* derivs);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Derivatives of the hyperbolic tangent function. 

@param x Evaluation point.
@param order Maximum order of derivative requested.
@param[out] derivs Array with the derivatives information. It must come allocated.
******************************************************************************************************/
void der_r_tanh(coeff_t x, ord_t order, coeff_t* derivs);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Derivatives of the square root function. 

@param x Evaluation point.
@param order Maximum order of derivative requested.
@param[out] derivs Array with the derivatives information. It must come allocated.
******************************************************************************************************/
void der_r_sqrt(coeff_t x, ord_t order, coeff_t* derivs);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Derivatives of the hyperbolic cosine function. 

@param x Evaluation point.
@param order Maximum order of derivative requested.
@param[out] derivs Array with the derivatives information. It must come allocated.
******************************************************************************************************/
void der_r_cosh(coeff_t x, ord_t order, coeff_t* derivs);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Derivatives of the hyperbolic sine function. 

@param x Evaluation point.
@param order Maximum order of derivative requested.
@param[out] derivs Array with the derivatives information. It must come allocated.
******************************************************************************************************/
void der_r_sinh(coeff_t x, ord_t order, coeff_t* derivs);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Derivatives of the inverse sine function. 

@param x Evaluation point.
@param order Maximum order of derivative requested.
@param[out] derivs Array with the derivatives information. It must come allocated.
******************************************************************************************************/
void der_r_asin(coeff_t x, ord_t order, coeff_t* derivs);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Derivatives of the inverse cosine function. 

@param x Evaluation point.
@param order Maximum order of derivative requested.
@param[out] derivs Array with the derivatives information. It must come allocated.
******************************************************************************************************/
void der_r_acos(coeff_t x, ord_t order, coeff_t* derivs);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Derivatives of the inverse tangent function. 

@param x Evaluation point.
@param order Maximum order of derivative requested.
@param[out] derivs Array with the derivatives information. It must come allocated.
******************************************************************************************************/
void der_r_atan(coeff_t x, ord_t order, coeff_t* derivs);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Derivatives of the tangent function. 

@param x Evaluation point.
@param order Maximum order of derivative requested.
@param[out] derivs Array with the derivatives information. It must come allocated.
******************************************************************************************************/
void der_r_tan(coeff_t x, ord_t order, coeff_t* derivs);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Derivatives of the cosine function. 

@param x Evaluation point.
@param order Maximum order of derivative requested.
@param[out] derivs Array with the derivatives information. It must come allocated.
******************************************************************************************************/
void der_r_cos(coeff_t x, ord_t order, coeff_t* derivs);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Derivatives of the sine function. 

@param x Evaluation point.
@param order Maximum order of derivative requested.
@param[out] derivs Array with the derivatives information. It must come allocated.
******************************************************************************************************/
void der_r_sin(coeff_t x, ord_t order, coeff_t* derivs);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Derivatives of the Natural logarithm function. 

@param x Evaluation point.
@param order Maximum order of derivative requested.
@param[out] derivs Array with the derivatives information. It must come allocated.
******************************************************************************************************/ 
void der_r_log(coeff_t x , ord_t order, coeff_t* derivs);
// ----------------------------------------------------------------------------------------------------


/**************************************************************************************************//**
@brief Derivatives of Exponential function.

@param x Evaluation point.
@param order Maximum order of derivative to be computed.
@param[out] derivs Array with the derivatives information. It must come allocated.
******************************************************************************************************/ 
void der_r_exp(coeff_t x, ord_t order, coeff_t* derivs);
// ----------------------------------------------------------------------------------------------------


/**************************************************************************************************//**
@brief Real derivatives of the power function. In particular useful for non integer exponents.

Evaluating    \f$    x^e    \f$

@param x Evaluation base of the power function.
@param e Exponent to power x.
@param order Maximum order of derivative to be retreived.
@param[out] derivs Array with the derivative information. It must come allocated.
******************************************************************************************************/ 
void der_r_pow(coeff_t x, coeff_t e, ord_t order, coeff_t* derivs);
// ----------------------------------------------------------------------------------------------------

// ----------------------------------------------------------------------------------------------------
// ---------------------------------    MATH FUNCTIONS    ---------------------------------------------
// ----------------------------------------------------------------------------------------------------


