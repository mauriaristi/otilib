

// ****************************************************************************************************
semiotin_t ssoti_atanh(semiotin_t* num, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_atanh(num->re, num->trc_order, derivs);

    return ssoti_feval(derivs, num, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
semiotin_t ssoti_asinh(semiotin_t* num, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_asinh(num->re, num->trc_order, derivs);

    return ssoti_feval(derivs, num, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
semiotin_t ssoti_acosh(semiotin_t* num, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_acosh(num->re, num->trc_order, derivs);

    return ssoti_feval(derivs, num, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
semiotin_t ssoti_tanh(semiotin_t* num, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_tanh(num->re, num->trc_order, derivs);

    return ssoti_feval(derivs, num, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
semiotin_t ssoti_cbrt(semiotin_t* num, dhelpl_t dhl){

    return ssoti_pow(num,1./3.,dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
semiotin_t ssoti_sqrt(semiotin_t* num, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_sqrt(num->re, num->trc_order, derivs);

    return ssoti_feval(derivs, num, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
semiotin_t ssoti_cosh(semiotin_t* num, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_cosh(num->re, num->trc_order, derivs);

    return ssoti_feval(derivs, num, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
semiotin_t ssoti_sinh(semiotin_t* num, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_sinh(num->re, num->trc_order, derivs);

    return ssoti_feval(derivs, num, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
semiotin_t ssoti_asin(semiotin_t* num, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_asin(num->re, num->trc_order, derivs);

    return ssoti_feval(derivs, num, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
semiotin_t ssoti_acos(semiotin_t* num, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_acos(num->re, num->trc_order, derivs);

    return ssoti_feval(derivs, num, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
semiotin_t ssoti_atan(semiotin_t* num, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_atan(num->re, num->trc_order, derivs);

    return ssoti_feval(derivs, num, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
semiotin_t ssoti_tan(semiotin_t* num, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_tan(num->re, num->trc_order, derivs);

    return ssoti_feval(derivs, num, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
semiotin_t ssoti_cos(semiotin_t* num, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_cos(num->re, num->trc_order, derivs);

    return ssoti_feval(derivs, num, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
semiotin_t ssoti_sin(semiotin_t* num, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_sin(num->re, num->trc_order, derivs);

    return ssoti_feval(derivs, num, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
semiotin_t ssoti_logb(semiotin_t* num, double base, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_logb(num->re, base, num->trc_order, derivs);

    return ssoti_feval(derivs, num, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
semiotin_t ssoti_log10(semiotin_t* num, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_log10(num->re, num->trc_order, derivs);

    return ssoti_feval(derivs, num, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
semiotin_t ssoti_log(semiotin_t* num, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_log(num->re, num->trc_order, derivs);

    return ssoti_feval(derivs, num, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
semiotin_t ssoti_exp(semiotin_t* num, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_exp(num->re, num->trc_order, derivs);

    return ssoti_feval(derivs, num, dhl);

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
semiotin_t ssoti_pow(semiotin_t* num, double e, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_pow(num->re, e, num->trc_order, derivs);

    return ssoti_feval(derivs, num, dhl);

}
// ----------------------------------------------------------------------------------------------------