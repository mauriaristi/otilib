

// ****************************************************************************************************
void ssoti_atanh_to(semiotin_t* num, semiotin_t* res, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_atanh(num->re, num->trc_order, derivs);

    ssoti_feval_to(derivs, num, res, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void ssoti_asinh_to(semiotin_t* num, semiotin_t* res, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_asinh(num->re, num->trc_order, derivs);

    ssoti_feval_to(derivs, num, res, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void ssoti_acosh_to(semiotin_t* num, semiotin_t* res, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_acosh(num->re, num->trc_order, derivs);

    ssoti_feval_to(derivs, num, res, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void ssoti_tanh_to(semiotin_t* num, semiotin_t* res, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_tanh(num->re, num->trc_order, derivs);

    ssoti_feval_to(derivs, num, res, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void ssoti_cbrt_to(semiotin_t* num, semiotin_t* res, dhelpl_t dhl){

    ssoti_pow_to(num, 1./3., res, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void ssoti_sqrt_to(semiotin_t* num, semiotin_t* res, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_sqrt(num->re, num->trc_order, derivs);

    ssoti_feval_to(derivs, num, res, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void ssoti_cosh_to(semiotin_t* num, semiotin_t* res, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_cosh(num->re, num->trc_order, derivs);

    ssoti_feval_to(derivs, num, res, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void ssoti_sinh_to(semiotin_t* num, semiotin_t* res, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_sinh(num->re, num->trc_order, derivs);

    ssoti_feval_to(derivs, num, res, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void ssoti_asin_to(semiotin_t* num, semiotin_t* res, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_asin(num->re, num->trc_order, derivs);

    ssoti_feval_to(derivs, num, res, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void ssoti_acos_to(semiotin_t* num, semiotin_t* res, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_acos(num->re, num->trc_order, derivs);

    ssoti_feval_to(derivs, num, res, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void ssoti_atan_to(semiotin_t* num, semiotin_t* res, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_atan(num->re, num->trc_order, derivs);

    ssoti_feval_to(derivs, num, res, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void ssoti_tan_to(semiotin_t* num, semiotin_t* res, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_tan(num->re, num->trc_order, derivs);

    ssoti_feval_to(derivs, num, res, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void ssoti_cos_to(semiotin_t* num, semiotin_t* res, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_cos(num->re, num->trc_order, derivs);

    ssoti_feval_to(derivs, num, res, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void ssoti_sin_to(semiotin_t* num, semiotin_t* res, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_sin(num->re, num->trc_order, derivs);

    ssoti_feval_to(derivs, num, res, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void ssoti_logb_to(semiotin_t* num, double base, semiotin_t* res, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_logb(num->re, base, num->trc_order, derivs);

    ssoti_feval_to(derivs, num, res, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void ssoti_log10_to(semiotin_t* num, semiotin_t* res, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_log10(num->re, num->trc_order, derivs);

    ssoti_feval_to(derivs, num, res, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void ssoti_log_to(semiotin_t* num, semiotin_t* res, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_log(num->re, num->trc_order, derivs);

    ssoti_feval_to(derivs, num, res, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void ssoti_exp_to(semiotin_t* num, semiotin_t* res, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_exp(num->re, num->trc_order, derivs);

    ssoti_feval_to(derivs, num, res, dhl);

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void ssoti_pow_to(semiotin_t* num, double e, semiotin_t* res, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_pow(num->re, e, num->trc_order, derivs);

    ssoti_feval_to(derivs, num, res, dhl);

}
// ----------------------------------------------------------------------------------------------------


