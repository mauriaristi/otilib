// Semi-sparse scalar: Taylor series evaluation and elementary functions.


// *******************************************************************************************************
ssotinum_t ssoti_feval(const coeff_t* derivs, const ssotinum_t* num, dhelpl_t dhl){

    ssotinum_t res = ssoti_init();

    ssoti_feval_to(derivs, num, &res, dhl);

    return res;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void ssoti_feval_to(const coeff_t* derivs, const ssotinum_t* num, ssotinum_t* res, dhelpl_t dhl){

    sshelp_ws_t* ws = ssoti_ws();
    bases_t k = num->nbases;
    ord_t trc = num->trc_order, act = num->act_order, i, lo, hi;
    ndir_t n, nimag = ssoti_nimag_checked(k, trc);
    coeff_t *P, *Q, *R, *tmp, factor = 1.0, c;

    // No imaginary part: f(num) is real.
    if (k == 0 || act == 0 || trc == 0){

        ssoti_copy_to(num, res);
        res->re = derivs[0];
        res->act_order = 0;

        if (res->nbases > 0){
            memset(res->p_im, 0, nimag * sizeof(coeff_t));
        }

        return;

    }

    ssoti_ws_need(ws, 3 * (size_t)nimag, 0, 0);
    R = ws->p_coef;
    P = R + nimag;
    Q = P + nimag;

    // R = f'(re) d, P = d.
    for (n = 0; n < nimag; n++){

        P[n] = num->p_im[n];
        R[n] = derivs[1] * P[n];

    }

    // P holds d^(i-1) (orders i-1 .. min(trc, (i-1) act)); Q = d^i.
    for (i = 2; i <= trc; i++){

        factor *= i;
        c       = derivs[i] / factor;
        lo      = i - 1;
        hi      = ((unsigned)(i - 1) * act < trc) ? (ord_t)((i - 1) * act) : trc;

        memset(Q, 0, nimag * sizeof(coeff_t));
        ssoti_kernel_mul_acc(P, lo, hi, num->p_im, 1, act, k, trc, Q, dhl);

        for (n = sshelp_order_offset(k, i); n < nimag; n++){
            R[n] += c * Q[n];
        }

        tmp = P;
        P   = Q;
        Q   = tmp;

    }

    ssoti_reserve(res, k, trc);

    if (res != num){
        memcpy(res->p_bases, num->p_bases, (size_t)k * sizeof(bases_t));
    }

    memcpy(res->p_im, R, nimag * sizeof(coeff_t));

    res->re        = derivs[0];
    res->nbases    = k;
    res->trc_order = trc;
    res->act_order = trc;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
ssotinum_t ssoti_exp(const ssotinum_t* num, dhelpl_t dhl){

    ssotinum_t res = ssoti_init();

    ssoti_exp_to(num, &res, dhl);

    return res;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void ssoti_exp_to(const ssotinum_t* num, ssotinum_t* res, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI + 1];

    der_r_exp(num->re, num->trc_order, derivs);
    ssoti_feval_to(derivs, num, res, dhl);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
ssotinum_t ssoti_log(const ssotinum_t* num, dhelpl_t dhl){

    ssotinum_t res = ssoti_init();

    ssoti_log_to(num, &res, dhl);

    return res;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void ssoti_log_to(const ssotinum_t* num, ssotinum_t* res, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI + 1];

    der_r_log(num->re, num->trc_order, derivs);
    ssoti_feval_to(derivs, num, res, dhl);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
ssotinum_t ssoti_log10(const ssotinum_t* num, dhelpl_t dhl){

    ssotinum_t res = ssoti_init();

    ssoti_log10_to(num, &res, dhl);

    return res;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void ssoti_log10_to(const ssotinum_t* num, ssotinum_t* res, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI + 1];

    der_r_log10(num->re, num->trc_order, derivs);
    ssoti_feval_to(derivs, num, res, dhl);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
ssotinum_t ssoti_sqrt(const ssotinum_t* num, dhelpl_t dhl){

    ssotinum_t res = ssoti_init();

    ssoti_sqrt_to(num, &res, dhl);

    return res;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void ssoti_sqrt_to(const ssotinum_t* num, ssotinum_t* res, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI + 1];

    der_r_sqrt(num->re, num->trc_order, derivs);
    ssoti_feval_to(derivs, num, res, dhl);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
ssotinum_t ssoti_sin(const ssotinum_t* num, dhelpl_t dhl){

    ssotinum_t res = ssoti_init();

    ssoti_sin_to(num, &res, dhl);

    return res;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void ssoti_sin_to(const ssotinum_t* num, ssotinum_t* res, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI + 1];

    der_r_sin(num->re, num->trc_order, derivs);
    ssoti_feval_to(derivs, num, res, dhl);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
ssotinum_t ssoti_cos(const ssotinum_t* num, dhelpl_t dhl){

    ssotinum_t res = ssoti_init();

    ssoti_cos_to(num, &res, dhl);

    return res;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void ssoti_cos_to(const ssotinum_t* num, ssotinum_t* res, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI + 1];

    der_r_cos(num->re, num->trc_order, derivs);
    ssoti_feval_to(derivs, num, res, dhl);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
ssotinum_t ssoti_tan(const ssotinum_t* num, dhelpl_t dhl){

    ssotinum_t res = ssoti_init();

    ssoti_tan_to(num, &res, dhl);

    return res;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void ssoti_tan_to(const ssotinum_t* num, ssotinum_t* res, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI + 1];

    der_r_tan(num->re, num->trc_order, derivs);
    ssoti_feval_to(derivs, num, res, dhl);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
ssotinum_t ssoti_asin(const ssotinum_t* num, dhelpl_t dhl){

    ssotinum_t res = ssoti_init();

    ssoti_asin_to(num, &res, dhl);

    return res;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void ssoti_asin_to(const ssotinum_t* num, ssotinum_t* res, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI + 1];

    der_r_asin(num->re, num->trc_order, derivs);
    ssoti_feval_to(derivs, num, res, dhl);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
ssotinum_t ssoti_acos(const ssotinum_t* num, dhelpl_t dhl){

    ssotinum_t res = ssoti_init();

    ssoti_acos_to(num, &res, dhl);

    return res;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void ssoti_acos_to(const ssotinum_t* num, ssotinum_t* res, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI + 1];

    der_r_acos(num->re, num->trc_order, derivs);
    ssoti_feval_to(derivs, num, res, dhl);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
ssotinum_t ssoti_atan(const ssotinum_t* num, dhelpl_t dhl){

    ssotinum_t res = ssoti_init();

    ssoti_atan_to(num, &res, dhl);

    return res;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void ssoti_atan_to(const ssotinum_t* num, ssotinum_t* res, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI + 1];

    der_r_atan(num->re, num->trc_order, derivs);
    ssoti_feval_to(derivs, num, res, dhl);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
ssotinum_t ssoti_sinh(const ssotinum_t* num, dhelpl_t dhl){

    ssotinum_t res = ssoti_init();

    ssoti_sinh_to(num, &res, dhl);

    return res;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void ssoti_sinh_to(const ssotinum_t* num, ssotinum_t* res, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI + 1];

    der_r_sinh(num->re, num->trc_order, derivs);
    ssoti_feval_to(derivs, num, res, dhl);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
ssotinum_t ssoti_cosh(const ssotinum_t* num, dhelpl_t dhl){

    ssotinum_t res = ssoti_init();

    ssoti_cosh_to(num, &res, dhl);

    return res;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void ssoti_cosh_to(const ssotinum_t* num, ssotinum_t* res, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI + 1];

    der_r_cosh(num->re, num->trc_order, derivs);
    ssoti_feval_to(derivs, num, res, dhl);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
ssotinum_t ssoti_tanh(const ssotinum_t* num, dhelpl_t dhl){

    ssotinum_t res = ssoti_init();

    ssoti_tanh_to(num, &res, dhl);

    return res;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void ssoti_tanh_to(const ssotinum_t* num, ssotinum_t* res, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI + 1];

    der_r_tanh(num->re, num->trc_order, derivs);
    ssoti_feval_to(derivs, num, res, dhl);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
ssotinum_t ssoti_asinh(const ssotinum_t* num, dhelpl_t dhl){

    ssotinum_t res = ssoti_init();

    ssoti_asinh_to(num, &res, dhl);

    return res;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void ssoti_asinh_to(const ssotinum_t* num, ssotinum_t* res, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI + 1];

    der_r_asinh(num->re, num->trc_order, derivs);
    ssoti_feval_to(derivs, num, res, dhl);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
ssotinum_t ssoti_acosh(const ssotinum_t* num, dhelpl_t dhl){

    ssotinum_t res = ssoti_init();

    ssoti_acosh_to(num, &res, dhl);

    return res;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void ssoti_acosh_to(const ssotinum_t* num, ssotinum_t* res, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI + 1];

    der_r_acosh(num->re, num->trc_order, derivs);
    ssoti_feval_to(derivs, num, res, dhl);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
ssotinum_t ssoti_atanh(const ssotinum_t* num, dhelpl_t dhl){

    ssotinum_t res = ssoti_init();

    ssoti_atanh_to(num, &res, dhl);

    return res;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void ssoti_atanh_to(const ssotinum_t* num, ssotinum_t* res, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI + 1];

    der_r_atanh(num->re, num->trc_order, derivs);
    ssoti_feval_to(derivs, num, res, dhl);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
ssotinum_t ssoti_erf(const ssotinum_t* num, dhelpl_t dhl){

    ssotinum_t res = ssoti_init();

    ssoti_erf_to(num, &res, dhl);

    return res;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void ssoti_erf_to(const ssotinum_t* num, ssotinum_t* res, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI + 1];

    der_r_erf(num->re, num->trc_order, derivs);
    ssoti_feval_to(derivs, num, res, dhl);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
ssotinum_t ssoti_cbrt(const ssotinum_t* num, dhelpl_t dhl){

    ssotinum_t res = ssoti_init();

    ssoti_cbrt_to(num, &res, dhl);

    return res;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void ssoti_cbrt_to(const ssotinum_t* num, ssotinum_t* res, dhelpl_t dhl){

    ssoti_pow_to(num, 1.0 / 3.0, res, dhl);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
ssotinum_t ssoti_pow(const ssotinum_t* num, coeff_t e, dhelpl_t dhl){

    ssotinum_t res = ssoti_init();

    ssoti_pow_to(num, e, &res, dhl);

    return res;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void ssoti_pow_to(const ssotinum_t* num, coeff_t e, ssotinum_t* res, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI + 1];

    der_r_pow(num->re, e, num->trc_order, derivs);
    ssoti_feval_to(derivs, num, res, dhl);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
ssotinum_t ssoti_logb(const ssotinum_t* num, coeff_t base, dhelpl_t dhl){

    ssotinum_t res = ssoti_init();

    ssoti_logb_to(num, base, &res, dhl);

    return res;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void ssoti_logb_to(const ssotinum_t* num, coeff_t base, ssotinum_t* res, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI + 1];

    der_r_logb(num->re, base, num->trc_order, derivs);
    ssoti_feval_to(derivs, num, res, dhl);

}
// -------------------------------------------------------------------------------------------------------

