

// ****************************************************************************************************
void onumm1n30_atanh_to(onumm1n30_t* num, onumm1n30_t* res){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_atanh(num->r, 30, derivs);

    onumm1n30_feval_to(derivs, num, res);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void onumm1n30_asinh_to(onumm1n30_t* num, onumm1n30_t* res){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_asinh(num->r, 30, derivs);

    onumm1n30_feval_to(derivs, num, res);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void onumm1n30_acosh_to(onumm1n30_t* num, onumm1n30_t* res){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_acosh(num->r, 30, derivs);

    onumm1n30_feval_to(derivs, num, res);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void onumm1n30_tanh_to(onumm1n30_t* num, onumm1n30_t* res){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_tanh(num->r, 30, derivs);

    onumm1n30_feval_to(derivs, num, res);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void onumm1n30_cbrt_to(onumm1n30_t* num, onumm1n30_t* res){

    onumm1n30_pow_to(num, 1./3., res);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void onumm1n30_sqrt_to(onumm1n30_t* num, onumm1n30_t* res){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_sqrt(num->r, 30, derivs);

    onumm1n30_feval_to(derivs, num, res);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void onumm1n30_cosh_to(onumm1n30_t* num, onumm1n30_t* res){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_cosh(num->r, 30, derivs);

    onumm1n30_feval_to(derivs, num, res);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void onumm1n30_sinh_to(onumm1n30_t* num, onumm1n30_t* res){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_sinh(num->r, 30, derivs);

    onumm1n30_feval_to(derivs, num, res);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void onumm1n30_asin_to(onumm1n30_t* num, onumm1n30_t* res){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_asin(num->r, 30, derivs);

    onumm1n30_feval_to(derivs, num, res);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void onumm1n30_acos_to(onumm1n30_t* num, onumm1n30_t* res){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_acos(num->r, 30, derivs);

    onumm1n30_feval_to(derivs, num, res);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void onumm1n30_atan_to(onumm1n30_t* num, onumm1n30_t* res){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_atan(num->r, 30, derivs);

    onumm1n30_feval_to(derivs, num, res);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void onumm1n30_tan_to(onumm1n30_t* num, onumm1n30_t* res){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_tan(num->r, 30, derivs);

    onumm1n30_feval_to(derivs, num, res);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void onumm1n30_cos_to(onumm1n30_t* num, onumm1n30_t* res){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_cos(num->r, 30, derivs);

    onumm1n30_feval_to(derivs, num, res);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void onumm1n30_sin_to(onumm1n30_t* num, onumm1n30_t* res){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_sin(num->r, 30, derivs);

    onumm1n30_feval_to(derivs, num, res);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void onumm1n30_logb_to(onumm1n30_t* num, double base, onumm1n30_t* res){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_logb(num->r, base, 30, derivs);

    onumm1n30_feval_to(derivs, num, res);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void onumm1n30_log10_to(onumm1n30_t* num, onumm1n30_t* res){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_log10(num->r, 30, derivs);

    onumm1n30_feval_to(derivs, num, res);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void onumm1n30_log_to(onumm1n30_t* num, onumm1n30_t* res){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_log(num->r, 30, derivs);

    onumm1n30_feval_to(derivs, num, res);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void onumm1n30_exp_to(onumm1n30_t* num, onumm1n30_t* res){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_exp(num->r, 30, derivs);

    onumm1n30_feval_to(derivs, num, res);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void onumm1n30_pow_to(onumm1n30_t* num, double e, onumm1n30_t* res){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_pow(num->r, e, 30, derivs);

    onumm1n30_feval_to(derivs, num, res);

}
// ----------------------------------------------------------------------------------------------------

