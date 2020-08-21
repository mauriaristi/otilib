

// ****************************************************************************************************
void soti_atanh_to(sotinum_t* num, sotinum_t* res, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_atanh(num-><<<real_str>>>, <<<oti_order>>>, derivs);

    soti_feval_to(derivs, num, res, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void soti_asinh_to(sotinum_t* num, sotinum_t* res, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_asinh(num-><<<real_str>>>, <<<oti_order>>>, derivs);

    soti_feval_to(derivs, num, res, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void soti_acosh_to(sotinum_t* num, sotinum_t* res, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_acosh(num-><<<real_str>>>, <<<oti_order>>>, derivs);

    soti_feval_to(derivs, num, res, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void soti_tanh_to(sotinum_t* num, sotinum_t* res, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_tanh(num-><<<real_str>>>, <<<oti_order>>>, derivs);

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

    der_r_sqrt(num-><<<real_str>>>, <<<oti_order>>>, derivs);

    soti_feval_to(derivs, num, res, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void soti_cosh_to(sotinum_t* num, sotinum_t* res, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_cosh(num-><<<real_str>>>, <<<oti_order>>>, derivs);

    soti_feval_to(derivs, num, res, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void soti_sinh_to(sotinum_t* num, sotinum_t* res, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_sinh(num-><<<real_str>>>, <<<oti_order>>>, derivs);

    soti_feval_to(derivs, num, res, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void soti_asin_to(sotinum_t* num, sotinum_t* res, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_asin(num-><<<real_str>>>, <<<oti_order>>>, derivs);

    soti_feval_to(derivs, num, res, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void soti_acos_to(sotinum_t* num, sotinum_t* res, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_acos(num-><<<real_str>>>, <<<oti_order>>>, derivs);

    soti_feval_to(derivs, num, res, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void soti_atan_to(sotinum_t* num, sotinum_t* res, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_atan(num-><<<real_str>>>, <<<oti_order>>>, derivs);

    soti_feval_to(derivs, num, res, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void soti_tan_to(sotinum_t* num, sotinum_t* res, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_tan(num-><<<real_str>>>, <<<oti_order>>>, derivs);

    soti_feval_to(derivs, num, res, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void soti_cos_to(sotinum_t* num, sotinum_t* res, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_cos(num-><<<real_str>>>, <<<oti_order>>>, derivs);

    soti_feval_to(derivs, num, res, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void soti_sin_to(sotinum_t* num, sotinum_t* res, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_sin(num-><<<real_str>>>, <<<oti_order>>>, derivs);

    soti_feval_to(derivs, num, res, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void soti_logb_to(sotinum_t* num, double base, sotinum_t* res, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_logb(num-><<<real_str>>>, base, <<<oti_order>>>, derivs);

    soti_feval_to(derivs, num, res, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void soti_log10_to(sotinum_t* num, sotinum_t* res, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_log10(num-><<<real_str>>>, <<<oti_order>>>, derivs);

    soti_feval_to(derivs, num, res, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void soti_log_to(sotinum_t* num, sotinum_t* res, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_log(num-><<<real_str>>>, <<<oti_order>>>, derivs);

    soti_feval_to(derivs, num, res, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void soti_exp_to(sotinum_t* num, sotinum_t* res, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_exp(num-><<<real_str>>>, <<<oti_order>>>, derivs);

    soti_feval_to(derivs, num, res, dhl);

}
// ----------------------------------------------------------------------------------------------------


// ****************************************************************************************************
void soti_pow_to(sotinum_t* num, double e, sotinum_t* res, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_pow(num-><<<real_str>>>, e, <<<oti_order>>>, derivs);

    soti_feval_to(derivs, num, res, dhl);

}
// ----------------------------------------------------------------------------------------------------


