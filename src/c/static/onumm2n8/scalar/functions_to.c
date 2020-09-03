

// ****************************************************************************************************
void onumm2n8_atanh_to(onumm2n8_t* num, onumm2n8_t* res){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_atanh(num->r, 8, derivs);

    onumm2n8_feval_to(derivs, num, res);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void onumm2n8_asinh_to(onumm2n8_t* num, onumm2n8_t* res){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_asinh(num->r, 8, derivs);

    onumm2n8_feval_to(derivs, num, res);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void onumm2n8_acosh_to(onumm2n8_t* num, onumm2n8_t* res){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_acosh(num->r, 8, derivs);

    onumm2n8_feval_to(derivs, num, res);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void onumm2n8_tanh_to(onumm2n8_t* num, onumm2n8_t* res){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_tanh(num->r, 8, derivs);

    onumm2n8_feval_to(derivs, num, res);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void onumm2n8_cbrt_to(onumm2n8_t* num, onumm2n8_t* res){

    onumm2n8_pow_to(num, 1./3., res);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void onumm2n8_sqrt_to(onumm2n8_t* num, onumm2n8_t* res){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_sqrt(num->r, 8, derivs);

    onumm2n8_feval_to(derivs, num, res);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void onumm2n8_cosh_to(onumm2n8_t* num, onumm2n8_t* res){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_cosh(num->r, 8, derivs);

    onumm2n8_feval_to(derivs, num, res);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void onumm2n8_sinh_to(onumm2n8_t* num, onumm2n8_t* res){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_sinh(num->r, 8, derivs);

    onumm2n8_feval_to(derivs, num, res);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void onumm2n8_asin_to(onumm2n8_t* num, onumm2n8_t* res){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_asin(num->r, 8, derivs);

    onumm2n8_feval_to(derivs, num, res);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void onumm2n8_acos_to(onumm2n8_t* num, onumm2n8_t* res){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_acos(num->r, 8, derivs);

    onumm2n8_feval_to(derivs, num, res);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void onumm2n8_atan_to(onumm2n8_t* num, onumm2n8_t* res){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_atan(num->r, 8, derivs);

    onumm2n8_feval_to(derivs, num, res);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void onumm2n8_tan_to(onumm2n8_t* num, onumm2n8_t* res){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_tan(num->r, 8, derivs);

    onumm2n8_feval_to(derivs, num, res);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void onumm2n8_cos_to(onumm2n8_t* num, onumm2n8_t* res){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_cos(num->r, 8, derivs);

    onumm2n8_feval_to(derivs, num, res);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void onumm2n8_sin_to(onumm2n8_t* num, onumm2n8_t* res){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_sin(num->r, 8, derivs);

    onumm2n8_feval_to(derivs, num, res);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void onumm2n8_logb_to(onumm2n8_t* num, double base, onumm2n8_t* res){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_logb(num->r, base, 8, derivs);

    onumm2n8_feval_to(derivs, num, res);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void onumm2n8_log10_to(onumm2n8_t* num, onumm2n8_t* res){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_log10(num->r, 8, derivs);

    onumm2n8_feval_to(derivs, num, res);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void onumm2n8_log_to(onumm2n8_t* num, onumm2n8_t* res){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_log(num->r, 8, derivs);

    onumm2n8_feval_to(derivs, num, res);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void onumm2n8_exp_to(onumm2n8_t* num, onumm2n8_t* res){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_exp(num->r, 8, derivs);

    onumm2n8_feval_to(derivs, num, res);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void onumm2n8_pow_to(onumm2n8_t* num, double e, onumm2n8_t* res){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_pow(num->r, e, 8, derivs);

    onumm2n8_feval_to(derivs, num, res);

}
// ----------------------------------------------------------------------------------------------------
