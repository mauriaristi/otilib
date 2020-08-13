



// ****************************************************************************************************
void soti_atanh_to(sotinum_t* num, sotinum_t* res){{

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_atanh(num->re, num->order, derivs);

    soti_feval_to(derivs, num, res, dhl);

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void soti_asinh_to(sotinum_t* num, sotinum_t* res){{

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_asinh(num->re, num->order, derivs);

    soti_feval_to(derivs, num, res, dhl);

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void soti_acosh_to(sotinum_t* num, sotinum_t* res){{

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_acosh(num->re, num->order, derivs);

    soti_feval_to(derivs, num, res, dhl);

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void soti_tanh_to(sotinum_t* num, sotinum_t* res){{

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_tanh(num->re, num->order, derivs);

    soti_feval_to(derivs, num, res, dhl);

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void soti_cbrt_to(sotinum_t* num, sotinum_t* res){{

    soti_pow_to(num, 1./3., res, dhl);

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void soti_sqrt_to(sotinum_t* num, sotinum_t* res){{

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_sqrt(num->re, num->order, derivs);

    soti_feval_to(derivs, num, res, dhl);

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void soti_cosh_to(sotinum_t* num, sotinum_t* res){{

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_cosh(num->re, num->order, derivs);

    soti_feval_to(derivs, num, res, dhl);

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void soti_sinh_to(sotinum_t* num, sotinum_t* res){{

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_sinh(num->re, num->order, derivs);

    soti_feval_to(derivs, num, res, dhl);

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void soti_asin_to(sotinum_t* num, sotinum_t* res){{

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_asin(num->re, num->order, derivs);

    soti_feval_to(derivs, num, res, dhl);

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void soti_acos_to(sotinum_t* num, sotinum_t* res){{

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_acos(num->re, num->order, derivs);

    soti_feval_to(derivs, num, res, dhl);

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void soti_atan_to(sotinum_t* num, sotinum_t* res){{

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_atan(num->re, num->order, derivs);

    soti_feval_to(derivs, num, res, dhl);

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void soti_tan_to(sotinum_t* num, sotinum_t* res){{

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_tan(num->re, num->order, derivs);

    soti_feval_to(derivs, num, res, dhl);

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void soti_cos_to(sotinum_t* num, sotinum_t* res){{

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_cos(num->re, num->order, derivs);

    soti_feval_to(derivs, num, res, dhl);

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void soti_sin_to(sotinum_t* num, sotinum_t* res){{

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_sin(num->re, num->order, derivs);

    soti_feval_to(derivs, num, res, dhl);

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void soti_logb_to(sotinum_t* num, double base, sotinum_t* res){{

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_logb(num->re, base, num->order, derivs);

    soti_feval_to(derivs, num, res, dhl);

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void soti_log10_to(sotinum_t* num, sotinum_t* res){{

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_log10(num->re, num->order, derivs);

    soti_feval_to(derivs, num, res, dhl);

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void soti_log_to(sotinum_t* num, sotinum_t* res){{

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_log(num->re, num->order, derivs);

    soti_feval_to(derivs, num, res, dhl);

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void soti_exp_to(sotinum_t* num, sotinum_t* res){{

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_exp(num->re, num->order, derivs);

    soti_feval_to(derivs, num, res, dhl);

}}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void soti_pow_to(sotinum_t* num, double e, sotinum_t* res){{

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_pow(num->re, e, num->order, derivs);

    soti_feval_to(derivs, num, res, dhl);

}}
// ----------------------------------------------------------------------------------------------------



























// ****************************************************************************************************
sotinum_t soti_atanh(sotinum_t* num){{

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_atanh(num->re, num->order, derivs);

    return soti_feval(derivs, num, dhl);

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
sotinum_t soti_asinh(sotinum_t* num){{

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_asinh(num->re, num->order, derivs);

    return soti_feval(derivs, num, dhl);

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
sotinum_t soti_acosh(sotinum_t* num){{

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_acosh(num->re, num->order, derivs);

    return soti_feval(derivs, num, dhl);

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
sotinum_t soti_tanh(sotinum_t* num){{

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_tanh(num->re, num->order, derivs);

    return soti_feval(derivs, num, dhl);

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
sotinum_t soti_cbrt(sotinum_t* num){{

    return soti_pow(num,1./3.,dhl);

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
sotinum_t soti_sqrt(sotinum_t* num){{

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_sqrt(num->re, num->order, derivs);

    return soti_feval(derivs, num, dhl);

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
sotinum_t soti_cosh(sotinum_t* num){{

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_cosh(num->re, num->order, derivs);

    return soti_feval(derivs, num, dhl);

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
sotinum_t soti_sinh(sotinum_t* num){{

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_sinh(num->re, num->order, derivs);

    return soti_feval(derivs, num, dhl);

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
sotinum_t soti_asin(sotinum_t* num){{

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_asin(num->re, num->order, derivs);

    return soti_feval(derivs, num, dhl);

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
sotinum_t soti_acos(sotinum_t* num){{

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_acos(num->re, num->order, derivs);

    return soti_feval(derivs, num, dhl);

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
sotinum_t soti_atan(sotinum_t* num){{

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_atan(num->re, num->order, derivs);

    return soti_feval(derivs, num, dhl);

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
sotinum_t soti_tan(sotinum_t* num){{

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_tan(num->re, num->order, derivs);

    return soti_feval(derivs, num, dhl);

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
sotinum_t soti_cos(sotinum_t* num){{

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_cos(num->re, num->order, derivs);

    return soti_feval(derivs, num, dhl);

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
sotinum_t soti_sin(sotinum_t* num){{

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_sin(num->re, num->order, derivs);

    return soti_feval(derivs, num, dhl);

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
sotinum_t soti_logb(sotinum_t* num, double base){{

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_logb(num->re, base, num->order, derivs);

    return soti_feval(derivs, num, dhl);

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
sotinum_t soti_log10(sotinum_t* num){{

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_log10(num->re, num->order, derivs);

    return soti_feval(derivs, num, dhl);

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
sotinum_t soti_log(sotinum_t* num){{

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_log(num->re, num->order, derivs);

    return soti_feval(derivs, num, dhl);

}}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
sotinum_t soti_exp(sotinum_t* num){{

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_exp(num->re, num->order, derivs);

    return soti_feval(derivs, num, dhl);

}}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
sotinum_t soti_pow(sotinum_t* num, double e){{

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_pow(num->re, e, num->order, derivs);

    return soti_feval(derivs, num, dhl);

}}
// ----------------------------------------------------------------------------------------------------


















