

// ****************************************************************************************************
void mdnum2_atanh_to(mdnum2_t* num, mdnum2_t* res){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_atanh(num->r, 2, derivs);

    mdnum2_feval_to(derivs, num, res);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void mdnum2_asinh_to(mdnum2_t* num, mdnum2_t* res){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_asinh(num->r, 2, derivs);

    mdnum2_feval_to(derivs, num, res);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void mdnum2_acosh_to(mdnum2_t* num, mdnum2_t* res){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_acosh(num->r, 2, derivs);

    mdnum2_feval_to(derivs, num, res);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void mdnum2_tanh_to(mdnum2_t* num, mdnum2_t* res){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_tanh(num->r, 2, derivs);

    mdnum2_feval_to(derivs, num, res);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void mdnum2_cbrt_to(mdnum2_t* num, mdnum2_t* res){

    mdnum2_pow_to(num, 1./3., res);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void mdnum2_sqrt_to(mdnum2_t* num, mdnum2_t* res){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_sqrt(num->r, 2, derivs);

    mdnum2_feval_to(derivs, num, res);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void mdnum2_cosh_to(mdnum2_t* num, mdnum2_t* res){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_cosh(num->r, 2, derivs);

    mdnum2_feval_to(derivs, num, res);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void mdnum2_sinh_to(mdnum2_t* num, mdnum2_t* res){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_sinh(num->r, 2, derivs);

    mdnum2_feval_to(derivs, num, res);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void mdnum2_asin_to(mdnum2_t* num, mdnum2_t* res){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_asin(num->r, 2, derivs);

    mdnum2_feval_to(derivs, num, res);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void mdnum2_acos_to(mdnum2_t* num, mdnum2_t* res){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_acos(num->r, 2, derivs);

    mdnum2_feval_to(derivs, num, res);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void mdnum2_atan_to(mdnum2_t* num, mdnum2_t* res){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_atan(num->r, 2, derivs);

    mdnum2_feval_to(derivs, num, res);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void mdnum2_tan_to(mdnum2_t* num, mdnum2_t* res){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_tan(num->r, 2, derivs);

    mdnum2_feval_to(derivs, num, res);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void mdnum2_cos_to(mdnum2_t* num, mdnum2_t* res){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_cos(num->r, 2, derivs);

    mdnum2_feval_to(derivs, num, res);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void mdnum2_sin_to(mdnum2_t* num, mdnum2_t* res){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_sin(num->r, 2, derivs);

    mdnum2_feval_to(derivs, num, res);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void mdnum2_logb_to(mdnum2_t* num, double base, mdnum2_t* res){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_logb(num->r, base, 2, derivs);

    mdnum2_feval_to(derivs, num, res);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void mdnum2_log10_to(mdnum2_t* num, mdnum2_t* res){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_log10(num->r, 2, derivs);

    mdnum2_feval_to(derivs, num, res);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void mdnum2_log_to(mdnum2_t* num, mdnum2_t* res){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_log(num->r, 2, derivs);

    mdnum2_feval_to(derivs, num, res);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void mdnum2_exp_to(mdnum2_t* num, mdnum2_t* res){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_exp(num->r, 2, derivs);

    mdnum2_feval_to(derivs, num, res);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void mdnum2_pow_to(mdnum2_t* num, double e, mdnum2_t* res){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_pow(num->r, e, 2, derivs);

    mdnum2_feval_to(derivs, num, res);

}
// ----------------------------------------------------------------------------------------------------
