

// ****************************************************************************************************
onumm9n2_t onumm9n2_atanh(onumm9n2_t* num){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_atanh(num->r, 2, derivs);

    return onumm9n2_feval(derivs, num);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
onumm9n2_t onumm9n2_asinh(onumm9n2_t* num){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_asinh(num->r, 2, derivs);

    return onumm9n2_feval(derivs, num);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
onumm9n2_t onumm9n2_acosh(onumm9n2_t* num){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_acosh(num->r, 2, derivs);

    return onumm9n2_feval(derivs, num);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
onumm9n2_t onumm9n2_tanh(onumm9n2_t* num){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_tanh(num->r, 2, derivs);

    return onumm9n2_feval(derivs, num);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
onumm9n2_t onumm9n2_cbrt(onumm9n2_t* num){

    return onumm9n2_pow(num,1./3.);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
onumm9n2_t onumm9n2_sqrt(onumm9n2_t* num){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_sqrt(num->r, 2, derivs);

    return onumm9n2_feval(derivs, num);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
onumm9n2_t onumm9n2_cosh(onumm9n2_t* num){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_cosh(num->r, 2, derivs);

    return onumm9n2_feval(derivs, num);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
onumm9n2_t onumm9n2_sinh(onumm9n2_t* num){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_sinh(num->r, 2, derivs);

    return onumm9n2_feval(derivs, num);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
onumm9n2_t onumm9n2_asin(onumm9n2_t* num){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_asin(num->r, 2, derivs);

    return onumm9n2_feval(derivs, num);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
onumm9n2_t onumm9n2_acos(onumm9n2_t* num){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_acos(num->r, 2, derivs);

    return onumm9n2_feval(derivs, num);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
onumm9n2_t onumm9n2_atan(onumm9n2_t* num){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_atan(num->r, 2, derivs);

    return onumm9n2_feval(derivs, num);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
onumm9n2_t onumm9n2_tan(onumm9n2_t* num){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_tan(num->r, 2, derivs);

    return onumm9n2_feval(derivs, num);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
onumm9n2_t onumm9n2_cos(onumm9n2_t* num){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_cos(num->r, 2, derivs);

    return onumm9n2_feval(derivs, num);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
onumm9n2_t onumm9n2_sin(onumm9n2_t* num){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_sin(num->r, 2, derivs);

    return onumm9n2_feval(derivs, num);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
onumm9n2_t onumm9n2_logb(onumm9n2_t* num, double base){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_logb(num->r, base, 2, derivs);

    return onumm9n2_feval(derivs, num);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
onumm9n2_t onumm9n2_log10(onumm9n2_t* num){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_log10(num->r, 2, derivs);

    return onumm9n2_feval(derivs, num);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
onumm9n2_t onumm9n2_log(onumm9n2_t* num){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_log(num->r, 2, derivs);

    return onumm9n2_feval(derivs, num);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
onumm9n2_t onumm9n2_exp(onumm9n2_t* num){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_exp(num->r, 2, derivs);

    return onumm9n2_feval(derivs, num);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
onumm9n2_t onumm9n2_pow(onumm9n2_t* num, double e){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_pow(num->r, e, 2, derivs);

    return onumm9n2_feval(derivs, num);

}
// ----------------------------------------------------------------------------------------------------
