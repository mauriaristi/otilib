

// ****************************************************************************************************
onumm1n7_t onumm1n7_atanh(onumm1n7_t* num){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_atanh(num->r, 7, derivs);

    return onumm1n7_feval(derivs, num);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
onumm1n7_t onumm1n7_asinh(onumm1n7_t* num){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_asinh(num->r, 7, derivs);

    return onumm1n7_feval(derivs, num);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
onumm1n7_t onumm1n7_acosh(onumm1n7_t* num){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_acosh(num->r, 7, derivs);

    return onumm1n7_feval(derivs, num);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
onumm1n7_t onumm1n7_tanh(onumm1n7_t* num){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_tanh(num->r, 7, derivs);

    return onumm1n7_feval(derivs, num);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
onumm1n7_t onumm1n7_cbrt(onumm1n7_t* num){

    return onumm1n7_pow(num,1./3.);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
onumm1n7_t onumm1n7_sqrt(onumm1n7_t* num){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_sqrt(num->r, 7, derivs);

    return onumm1n7_feval(derivs, num);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
onumm1n7_t onumm1n7_cosh(onumm1n7_t* num){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_cosh(num->r, 7, derivs);

    return onumm1n7_feval(derivs, num);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
onumm1n7_t onumm1n7_sinh(onumm1n7_t* num){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_sinh(num->r, 7, derivs);

    return onumm1n7_feval(derivs, num);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
onumm1n7_t onumm1n7_asin(onumm1n7_t* num){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_asin(num->r, 7, derivs);

    return onumm1n7_feval(derivs, num);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
onumm1n7_t onumm1n7_acos(onumm1n7_t* num){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_acos(num->r, 7, derivs);

    return onumm1n7_feval(derivs, num);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
onumm1n7_t onumm1n7_atan(onumm1n7_t* num){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_atan(num->r, 7, derivs);

    return onumm1n7_feval(derivs, num);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
onumm1n7_t onumm1n7_tan(onumm1n7_t* num){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_tan(num->r, 7, derivs);

    return onumm1n7_feval(derivs, num);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
onumm1n7_t onumm1n7_cos(onumm1n7_t* num){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_cos(num->r, 7, derivs);

    return onumm1n7_feval(derivs, num);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
onumm1n7_t onumm1n7_sin(onumm1n7_t* num){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_sin(num->r, 7, derivs);

    return onumm1n7_feval(derivs, num);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
onumm1n7_t onumm1n7_logb(onumm1n7_t* num, double base){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_logb(num->r, base, 7, derivs);

    return onumm1n7_feval(derivs, num);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
onumm1n7_t onumm1n7_log10(onumm1n7_t* num){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_log10(num->r, 7, derivs);

    return onumm1n7_feval(derivs, num);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
onumm1n7_t onumm1n7_log(onumm1n7_t* num){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_log(num->r, 7, derivs);

    return onumm1n7_feval(derivs, num);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
onumm1n7_t onumm1n7_exp(onumm1n7_t* num){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_exp(num->r, 7, derivs);

    return onumm1n7_feval(derivs, num);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
onumm1n7_t onumm1n7_pow(onumm1n7_t* num, double e){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_pow(num->r, e, 7, derivs);

    return onumm1n7_feval(derivs, num);

}
// ----------------------------------------------------------------------------------------------------
