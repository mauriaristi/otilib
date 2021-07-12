

// ****************************************************************************************************
void soti_atanh_to(sotinum_t* num, sotinum_t* res, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_atanh(num->re, num->trc_order, derivs);

    soti_feval_to(derivs, num, res, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void soti_asinh_to(sotinum_t* num, sotinum_t* res, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_asinh(num->re, num->trc_order, derivs);

    soti_feval_to(derivs, num, res, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void soti_acosh_to(sotinum_t* num, sotinum_t* res, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_acosh(num->re, num->trc_order, derivs);

    soti_feval_to(derivs, num, res, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void soti_tanh_to(sotinum_t* num, sotinum_t* res, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_tanh(num->re, num->trc_order, derivs);

    soti_feval_to(derivs, num, res, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void soti_cbrt_to(sotinum_t* num, sotinum_t* res, dhelpl_t dhl){

    soti_pow_to(num, 1./3., res, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void soti_sqrt_to(sotinum_t* num, sotinum_t* res, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_sqrt(num->re, num->trc_order, derivs);

    soti_feval_to(derivs, num, res, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void soti_cosh_to(sotinum_t* num, sotinum_t* res, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_cosh(num->re, num->trc_order, derivs);

    soti_feval_to(derivs, num, res, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void soti_sinh_to(sotinum_t* num, sotinum_t* res, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_sinh(num->re, num->trc_order, derivs);

    soti_feval_to(derivs, num, res, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void soti_asin_to(sotinum_t* num, sotinum_t* res, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_asin(num->re, num->trc_order, derivs);

    soti_feval_to(derivs, num, res, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void soti_acos_to(sotinum_t* num, sotinum_t* res, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_acos(num->re, num->trc_order, derivs);

    soti_feval_to(derivs, num, res, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void soti_atan_to(sotinum_t* num, sotinum_t* res, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_atan(num->re, num->trc_order, derivs);

    soti_feval_to(derivs, num, res, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void soti_tan_to(sotinum_t* num, sotinum_t* res, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_tan(num->re, num->trc_order, derivs);

    soti_feval_to(derivs, num, res, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void soti_cos_to(sotinum_t* num, sotinum_t* res, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_cos(num->re, num->trc_order, derivs);

    soti_feval_to(derivs, num, res, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void soti_sin_to(sotinum_t* num, sotinum_t* res, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_sin(num->re, num->trc_order, derivs);

    soti_feval_to(derivs, num, res, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void soti_logb_to(sotinum_t* num, double base, sotinum_t* res, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_logb(num->re, base, num->trc_order, derivs);

    soti_feval_to(derivs, num, res, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void soti_log10_to(sotinum_t* num, sotinum_t* res, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_log10(num->re, num->trc_order, derivs);

    soti_feval_to(derivs, num, res, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void soti_log_to(sotinum_t* num, sotinum_t* res, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_log(num->re, num->trc_order, derivs);

    soti_feval_to(derivs, num, res, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void soti_exp_to(sotinum_t* num, sotinum_t* res, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_exp(num->re, num->trc_order, derivs);

    soti_feval_to(derivs, num, res, dhl);

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void soti_pow_to(sotinum_t* num, double e, sotinum_t* res, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_pow(num->re, e, num->trc_order, derivs);

    soti_feval_to(derivs, num, res, dhl);

}
// ----------------------------------------------------------------------------------------------------


