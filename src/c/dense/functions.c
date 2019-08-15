// 
// This file contains the math functions of dense OTI numbers.
//



// ****************************************************************************************************
// otinum_t oti_atan2(otinum_t* num, otinum_t* y, dhelpl_t dhl){
//     coeff_t derivs[10];



//     return oti_feval(derivs, num, dhl);
// }
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
otinum_t oti_atanh(otinum_t* num, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_atanh(num->re, num->order, derivs);

    return oti_feval(derivs, num, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
otinum_t oti_asinh(otinum_t* num, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_asinh(num->re, num->order, derivs);

    return oti_feval(derivs, num, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
otinum_t oti_acosh(otinum_t* num, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_acosh(num->re, num->order, derivs);

    return oti_feval(derivs, num, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
otinum_t oti_tanh(otinum_t* num, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_tanh(num->re, num->order, derivs);

    return oti_feval(derivs, num, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
otinum_t oti_sqrt(otinum_t* num, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_sqrt(num->re, num->order, derivs);

    return oti_feval(derivs, num, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
otinum_t oti_cosh(otinum_t* num, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_cosh(num->re, num->order, derivs);

    return oti_feval(derivs, num, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
otinum_t oti_sinh(otinum_t* num, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_sinh(num->re, num->order, derivs);

    return oti_feval(derivs, num, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
otinum_t oti_asin(otinum_t* num, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_asin(num->re, num->order, derivs);

    return oti_feval(derivs, num, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
otinum_t oti_acos(otinum_t* num, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_acos(num->re, num->order, derivs);

    return oti_feval(derivs, num, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
otinum_t oti_atan(otinum_t* num, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_atan(num->re, num->order, derivs);

    return oti_feval(derivs, num, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
otinum_t oti_tan(otinum_t* num, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_tan(num->re, num->order, derivs);

    return oti_feval(derivs, num, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
otinum_t oti_cos(otinum_t* num, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_cos(num->re, num->order, derivs);

    return oti_feval(derivs, num, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
otinum_t oti_sin(otinum_t* num, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_sin(num->re, num->order, derivs);

    return oti_feval(derivs, num, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
otinum_t oti_logb(otinum_t* num, double base, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_logb(num->re, base, num->order, derivs);

    return oti_feval(derivs, num, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
otinum_t oti_log10(otinum_t* num, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_log10(num->re, num->order, derivs);

    return oti_feval(derivs, num, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
otinum_t oti_log(otinum_t* num, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_log(num->re, num->order, derivs);

    return oti_feval(derivs, num, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
otinum_t oti_exp(otinum_t* num, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_exp(num->re, num->order, derivs);

    return oti_feval(derivs, num, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
otinum_t oti_pow(otinum_t* num, double e, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_pow(num->re, e, num->order, derivs);

    return oti_feval(derivs, num, dhl);

}
// ----------------------------------------------------------------------------------------------------