

// ****************************************************************************************************
onumm1n9_t onumm1n9_atanh(onumm1n9_t* num){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_atanh(num->r, 9, derivs);

    return onumm1n9_feval(derivs, num);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
onumm1n9_t onumm1n9_asinh(onumm1n9_t* num){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_asinh(num->r, 9, derivs);

    return onumm1n9_feval(derivs, num);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
onumm1n9_t onumm1n9_acosh(onumm1n9_t* num){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_acosh(num->r, 9, derivs);

    return onumm1n9_feval(derivs, num);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
onumm1n9_t onumm1n9_tanh(onumm1n9_t* num){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_tanh(num->r, 9, derivs);

    return onumm1n9_feval(derivs, num);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
onumm1n9_t onumm1n9_cbrt(onumm1n9_t* num){

    return onumm1n9_pow(num,1./3.);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
onumm1n9_t onumm1n9_sqrt(onumm1n9_t* num){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_sqrt(num->r, 9, derivs);

    return onumm1n9_feval(derivs, num);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
onumm1n9_t onumm1n9_cosh(onumm1n9_t* num){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_cosh(num->r, 9, derivs);

    return onumm1n9_feval(derivs, num);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
onumm1n9_t onumm1n9_sinh(onumm1n9_t* num){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_sinh(num->r, 9, derivs);

    return onumm1n9_feval(derivs, num);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
onumm1n9_t onumm1n9_asin(onumm1n9_t* num){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_asin(num->r, 9, derivs);

    return onumm1n9_feval(derivs, num);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
onumm1n9_t onumm1n9_acos(onumm1n9_t* num){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_acos(num->r, 9, derivs);

    return onumm1n9_feval(derivs, num);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
onumm1n9_t onumm1n9_atan(onumm1n9_t* num){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_atan(num->r, 9, derivs);

    return onumm1n9_feval(derivs, num);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
onumm1n9_t onumm1n9_tan(onumm1n9_t* num){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_tan(num->r, 9, derivs);

    return onumm1n9_feval(derivs, num);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
onumm1n9_t onumm1n9_cos(onumm1n9_t* num){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_cos(num->r, 9, derivs);

    return onumm1n9_feval(derivs, num);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
onumm1n9_t onumm1n9_sin(onumm1n9_t* num){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_sin(num->r, 9, derivs);

    return onumm1n9_feval(derivs, num);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
onumm1n9_t onumm1n9_logb(onumm1n9_t* num, double base){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_logb(num->r, base, 9, derivs);

    return onumm1n9_feval(derivs, num);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
onumm1n9_t onumm1n9_log10(onumm1n9_t* num){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_log10(num->r, 9, derivs);

    return onumm1n9_feval(derivs, num);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
onumm1n9_t onumm1n9_log(onumm1n9_t* num){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_log(num->r, 9, derivs);

    return onumm1n9_feval(derivs, num);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
onumm1n9_t onumm1n9_exp(onumm1n9_t* num){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_exp(num->r, 9, derivs);

    return onumm1n9_feval(derivs, num);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
onumm1n9_t onumm1n9_pow(onumm1n9_t* num, double e){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_pow(num->r, e, 9, derivs);

    return onumm1n9_feval(derivs, num);

}
// ----------------------------------------------------------------------------------------------------
