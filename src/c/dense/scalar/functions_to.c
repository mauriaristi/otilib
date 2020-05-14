// 
// This file contains the math functions of dense OTI numbers.
//


// void oti_atanh_to(otinum_t* num, otinum_t* res, dhelpl_t dhl);
// void oti_asinh_to(otinum_t* num, otinum_t* res, dhelpl_t dhl);
// void oti_acosh_to(otinum_t* num, otinum_t* res, dhelpl_t dhl);
// void oti_tanh_to(otinum_t* num, otinum_t* res, dhelpl_t dhl);
// void oti_sqrt_to(otinum_t* num, otinum_t* res, dhelpl_t dhl);
// void oti_cosh_to(otinum_t* num, otinum_t* res, dhelpl_t dhl);
// void oti_sinh_to(otinum_t* num, otinum_t* res, dhelpl_t dhl);
// void oti_asin_to(otinum_t* num, otinum_t* res, dhelpl_t dhl);
// void oti_acos_to(otinum_t* num, otinum_t* res, dhelpl_t dhl);
// void oti_atan_to(otinum_t* num, otinum_t* res, dhelpl_t dhl);
// void oti_tan_to(otinum_t* num, otinum_t* res, dhelpl_t dhl);
// void oti_cos_to(otinum_t* num, otinum_t* res, dhelpl_t dhl);
// void oti_sin_to(otinum_t* num, otinum_t* res, dhelpl_t dhl);
// void oti_logb_to(otinum_t* num, double base, otinum_t* res, dhelpl_t dhl);
// void oti_log10_to(otinum_t* num, otinum_t* res, dhelpl_t dhl);
// void oti_log_to(otinum_t* num, otinum_t* res, dhelpl_t dhl);
// void oti_exp_to(otinum_t* num, otinum_t* res, dhelpl_t dhl);
// void oti_pow_to(otinum_t* num, double e, otinum_t* res, dhelpl_t dhl);























// ****************************************************************************************************
// void oti_atan2_to(otinum_t* num, otinum_t* y, otinum_t* res, dhelpl_t dhl){
//     coeff_t derivs[10];



//     oti_feval_to(derivs, num, res, dhl);
// }
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void oti_atanh_to(otinum_t* num, otinum_t* res, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_atanh(num->re, num->order, derivs);

    oti_feval_to(derivs, num, res, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void oti_asinh_to(otinum_t* num, otinum_t* res, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_asinh(num->re, num->order, derivs);

    oti_feval_to(derivs, num, res, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void oti_acosh_to(otinum_t* num, otinum_t* res, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_acosh(num->re, num->order, derivs);

    oti_feval_to(derivs, num, res, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void oti_tanh_to(otinum_t* num, otinum_t* res, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_tanh(num->re, num->order, derivs);

    oti_feval_to(derivs, num, res, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void oti_sqrt_to(otinum_t* num, otinum_t* res, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_sqrt(num->re, num->order, derivs);

    oti_feval_to(derivs, num, res, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void oti_cosh_to(otinum_t* num, otinum_t* res, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_cosh(num->re, num->order, derivs);

    oti_feval_to(derivs, num, res, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void oti_sinh_to(otinum_t* num, otinum_t* res, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_sinh(num->re, num->order, derivs);

    oti_feval_to(derivs, num, res, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void oti_asin_to(otinum_t* num, otinum_t* res, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_asin(num->re, num->order, derivs);

    oti_feval_to(derivs, num, res, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void oti_acos_to(otinum_t* num, otinum_t* res, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_acos(num->re, num->order, derivs);

    oti_feval_to(derivs, num, res, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void oti_atan_to(otinum_t* num, otinum_t* res, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_atan(num->re, num->order, derivs);

    oti_feval_to(derivs, num, res, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void oti_tan_to(otinum_t* num, otinum_t* res, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_tan(num->re, num->order, derivs);

    oti_feval_to(derivs, num, res, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void oti_cos_to(otinum_t* num, otinum_t* res, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_cos(num->re, num->order, derivs);

    oti_feval_to(derivs, num, res, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void oti_sin_to(otinum_t* num, otinum_t* res, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_sin(num->re, num->order, derivs);

    oti_feval_to(derivs, num, res, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void oti_logb_to(otinum_t* num, double base, otinum_t* res, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_logb(num->re, base, num->order, derivs);

    oti_feval_to(derivs, num, res, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void oti_log10_to(otinum_t* num, otinum_t* res, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_log10(num->re, num->order, derivs);

    oti_feval_to(derivs, num, res, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void oti_log_to(otinum_t* num, otinum_t* res, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_log(num->re, num->order, derivs);

    oti_feval_to(derivs, num, res, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void oti_exp_to(otinum_t* num, otinum_t* res, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_exp(num->re, num->order, derivs);

    oti_feval_to(derivs, num, res, dhl);

}
// ----------------------------------------------------------------------------------------------------

// ****************************************************************************************************
void oti_pow_to(otinum_t* num, double e, otinum_t* res, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI+1];

    der_r_pow(num->re, e, num->order, derivs);

    oti_feval_to(derivs, num, res, dhl);

}
// ----------------------------------------------------------------------------------------------------

