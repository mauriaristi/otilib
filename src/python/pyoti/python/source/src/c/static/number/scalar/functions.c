



// ****************************************************************************************************
sotinum_t soti_atanh(sotinum_t* num, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_atanh(num-><<<real_str>>>, <<<oti_order>>>, derivs);

    return soti_feval(derivs, num, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
sotinum_t soti_asinh(sotinum_t* num, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_asinh(num-><<<real_str>>>, <<<oti_order>>>, derivs);

    return soti_feval(derivs, num, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
sotinum_t soti_acosh(sotinum_t* num, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_acosh(num-><<<real_str>>>, <<<oti_order>>>, derivs);

    return soti_feval(derivs, num, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
sotinum_t soti_tanh(sotinum_t* num, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_tanh(num-><<<real_str>>>, <<<oti_order>>>, derivs);

    return soti_feval(derivs, num, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
sotinum_t soti_cbrt(sotinum_t* num, dhelpl_t dhl){

    return soti_pow(num,1./3.,dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
sotinum_t soti_sqrt(sotinum_t* num, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_sqrt(num-><<<real_str>>>, <<<oti_order>>>, derivs);

    return soti_feval(derivs, num, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
sotinum_t soti_cosh(sotinum_t* num, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_cosh(num-><<<real_str>>>, <<<oti_order>>>, derivs);

    return soti_feval(derivs, num, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
sotinum_t soti_sinh(sotinum_t* num, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_sinh(num-><<<real_str>>>, <<<oti_order>>>, derivs);

    return soti_feval(derivs, num, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
sotinum_t soti_asin(sotinum_t* num, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_asin(num-><<<real_str>>>, <<<oti_order>>>, derivs);

    return soti_feval(derivs, num, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
sotinum_t soti_acos(sotinum_t* num, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_acos(num-><<<real_str>>>, <<<oti_order>>>, derivs);

    return soti_feval(derivs, num, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
sotinum_t soti_atan(sotinum_t* num, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_atan(num-><<<real_str>>>, <<<oti_order>>>, derivs);

    return soti_feval(derivs, num, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
sotinum_t soti_tan(sotinum_t* num, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_tan(num-><<<real_str>>>, <<<oti_order>>>, derivs);

    return soti_feval(derivs, num, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
sotinum_t soti_cos(sotinum_t* num, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_cos(num-><<<real_str>>>, <<<oti_order>>>, derivs);

    return soti_feval(derivs, num, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
sotinum_t soti_sin(sotinum_t* num, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_sin(num-><<<real_str>>>, <<<oti_order>>>, derivs);

    return soti_feval(derivs, num, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
sotinum_t soti_logb(sotinum_t* num, double base, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_logb(num-><<<real_str>>>, base, <<<oti_order>>>, derivs);

    return soti_feval(derivs, num, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
sotinum_t soti_log10(sotinum_t* num, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_log10(num-><<<real_str>>>, <<<oti_order>>>, derivs);

    return soti_feval(derivs, num, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
sotinum_t soti_log(sotinum_t* num, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_log(num-><<<real_str>>>, <<<oti_order>>>, derivs);

    return soti_feval(derivs, num, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
sotinum_t soti_exp(sotinum_t* num, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_exp(num-><<<real_str>>>, <<<oti_order>>>, derivs);

    return soti_feval(derivs, num, dhl);

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
sotinum_t soti_pow(sotinum_t* num, double e, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_pow(num-><<<real_str>>>, e, <<<oti_order>>>, derivs);

    return soti_feval(derivs, num, dhl);

}
// ----------------------------------------------------------------------------------------------------


















