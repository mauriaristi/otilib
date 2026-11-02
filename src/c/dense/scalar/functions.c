// Dense scalar: Taylor series evaluation and elementary functions (include/oti/dense/scalar/functions.h).
//
// Unity-included from src/c/dense.c: static helpers here carry the dnsf_ prefix. Every function is the
// truncated Taylor series of oti_feval_to(); the powers of the imaginary part live in scratch (the
// thread's workspace for up to 64 KiB, else allocated and freed inside the call).


// *******************************************************************************************************
otinum_t oti_feval(const coeff_t* derivs, const otinum_t* num, dhelpl_t dhl){

    otinum_t res = oti_init();

    return dnsm_ret(oti_feval_to(derivs, num, &res, dhl), &res);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oti_feval_to(const coeff_t* derivs, const otinum_t* num, otinum_t* res, dhelpl_t dhl){

    bases_t k = num->nact;
    ord_t trc = num->trc_order, act = num->act_order, i, lo, hi;
    ndir_t n, off, nimag;
    size_t nbuf;
    const coeff_t *D, *P;
    coeff_t *W, *R, *Q, *spare, *tmp, *owned = NULL, factor = 1.0, c;
    int status;

    if (trc > _MAXORDER_OTI){
        return DN_ERR_INDEX;
    }

    // No imaginary part: f(num) is real, in the input's layout.
    if (k == 0 || act == 0 || trc == 0){

        status = oti_create_empty_to(k, trc, res);
        res->re = derivs[0];

        return status;

    }

    nimag = sshelp_ndir_total(k, trc);

    // Two buffers for the powers d^i (from order 2 on), plus the result when it overwrites num: the
    // workspace for up to 64 KiB, else a call-local allocation.
    nbuf = (size_t)((trc >= 2) ? 2 : 0) + (size_t)(res == num);
    W    = NULL;

    if (nbuf > 0){

        if ((size_t)nimag > SIZE_MAX / sizeof(coeff_t) / nbuf){
            return DN_ERR_MEMORY;
        }

        W = dnsm_scratch(nbuf * (size_t)nimag, &owned);

        if (W == NULL){
            return DN_ERR_MEMORY;
        }

    }

    if (res == num){

        R = W + (nbuf - 1) * (size_t)nimag;

    } else {

        status = dnsm_prepare(res, k, trc);

        if (status != DN_OK){

            dnsm_scratch_free(W, owned);
            return status;

        }

        R = res->p_im;

    }

    D = num->p_im;

    // R = f'(re) d.
    for (n = 0; n < nimag; n++){
        R[n] = derivs[1] * D[n];
    }

    // P holds d^(i-1) (orders i-1 .. min(trc, (i-1) act)); Q receives d^i (orders i..trc).
    P     = D;
    Q     = W;
    spare = (trc >= 2) ? W + nimag : NULL;

    for (i = 2; i <= trc; i++){

        factor *= i;
        c       = derivs[i] / factor;
        lo      = i - 1;
        hi      = ((unsigned)(i - 1) * act < trc) ? (ord_t)((i - 1) * act) : trc;
        off     = sshelp_order_offset(k, i);

        memset(Q + off, 0, (size_t)(nimag - off) * sizeof(coeff_t));
        dnsa_kernel_mul_mixed(P, k, lo, hi, D, k, 1, act, k, trc, Q, dhl);

        for (n = off; n < nimag; n++){
            R[n] += c * Q[n];
        }

        P     = Q;
        tmp   = spare;
        spare = Q;
        Q     = tmp;

    }

    if (res == num){
        memcpy(res->p_im, R, (size_t)nimag * sizeof(coeff_t));
    }

    dnsm_scratch_free(W, owned);

    res->re        = derivs[0];
    res->act_order = trc;

    return DN_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
otinum_t oti_exp(const otinum_t* num, dhelpl_t dhl){

    otinum_t res = oti_init();

    return dnsm_ret(oti_exp_to(num, &res, dhl), &res);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oti_exp_to(const otinum_t* num, otinum_t* res, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI + 1];

    // The derivative list is sized _MAXORDER_OTI + 1: a hand-built number above it is rejected.
    if (num->trc_order > _MAXORDER_OTI){
        return DN_ERR_INDEX;
    }

    der_r_exp(num->re, num->trc_order, derivs);

    return oti_feval_to(derivs, num, res, dhl);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
otinum_t oti_log(const otinum_t* num, dhelpl_t dhl){

    otinum_t res = oti_init();

    return dnsm_ret(oti_log_to(num, &res, dhl), &res);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oti_log_to(const otinum_t* num, otinum_t* res, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI + 1];

    // The derivative list is sized _MAXORDER_OTI + 1: a hand-built number above it is rejected.
    if (num->trc_order > _MAXORDER_OTI){
        return DN_ERR_INDEX;
    }

    der_r_log(num->re, num->trc_order, derivs);

    return oti_feval_to(derivs, num, res, dhl);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
otinum_t oti_log10(const otinum_t* num, dhelpl_t dhl){

    otinum_t res = oti_init();

    return dnsm_ret(oti_log10_to(num, &res, dhl), &res);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oti_log10_to(const otinum_t* num, otinum_t* res, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI + 1];

    // The derivative list is sized _MAXORDER_OTI + 1: a hand-built number above it is rejected.
    if (num->trc_order > _MAXORDER_OTI){
        return DN_ERR_INDEX;
    }

    der_r_log10(num->re, num->trc_order, derivs);

    return oti_feval_to(derivs, num, res, dhl);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
otinum_t oti_sqrt(const otinum_t* num, dhelpl_t dhl){

    otinum_t res = oti_init();

    return dnsm_ret(oti_sqrt_to(num, &res, dhl), &res);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oti_sqrt_to(const otinum_t* num, otinum_t* res, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI + 1];

    // The derivative list is sized _MAXORDER_OTI + 1: a hand-built number above it is rejected.
    if (num->trc_order > _MAXORDER_OTI){
        return DN_ERR_INDEX;
    }

    der_r_sqrt(num->re, num->trc_order, derivs);

    return oti_feval_to(derivs, num, res, dhl);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
otinum_t oti_cbrt(const otinum_t* num, dhelpl_t dhl){

    otinum_t res = oti_init();

    return dnsm_ret(oti_cbrt_to(num, &res, dhl), &res);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oti_cbrt_to(const otinum_t* num, otinum_t* res, dhelpl_t dhl){

    return oti_pow_to(num, 1.0 / 3.0, res, dhl);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
otinum_t oti_sin(const otinum_t* num, dhelpl_t dhl){

    otinum_t res = oti_init();

    return dnsm_ret(oti_sin_to(num, &res, dhl), &res);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oti_sin_to(const otinum_t* num, otinum_t* res, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI + 1];

    // The derivative list is sized _MAXORDER_OTI + 1: a hand-built number above it is rejected.
    if (num->trc_order > _MAXORDER_OTI){
        return DN_ERR_INDEX;
    }

    der_r_sin(num->re, num->trc_order, derivs);

    return oti_feval_to(derivs, num, res, dhl);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
otinum_t oti_cos(const otinum_t* num, dhelpl_t dhl){

    otinum_t res = oti_init();

    return dnsm_ret(oti_cos_to(num, &res, dhl), &res);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oti_cos_to(const otinum_t* num, otinum_t* res, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI + 1];

    // The derivative list is sized _MAXORDER_OTI + 1: a hand-built number above it is rejected.
    if (num->trc_order > _MAXORDER_OTI){
        return DN_ERR_INDEX;
    }

    der_r_cos(num->re, num->trc_order, derivs);

    return oti_feval_to(derivs, num, res, dhl);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
otinum_t oti_tan(const otinum_t* num, dhelpl_t dhl){

    otinum_t res = oti_init();

    return dnsm_ret(oti_tan_to(num, &res, dhl), &res);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oti_tan_to(const otinum_t* num, otinum_t* res, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI + 1];

    // The derivative list is sized _MAXORDER_OTI + 1: a hand-built number above it is rejected.
    if (num->trc_order > _MAXORDER_OTI){
        return DN_ERR_INDEX;
    }

    der_r_tan(num->re, num->trc_order, derivs);

    return oti_feval_to(derivs, num, res, dhl);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
otinum_t oti_asin(const otinum_t* num, dhelpl_t dhl){

    otinum_t res = oti_init();

    return dnsm_ret(oti_asin_to(num, &res, dhl), &res);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oti_asin_to(const otinum_t* num, otinum_t* res, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI + 1];

    // The derivative list is sized _MAXORDER_OTI + 1: a hand-built number above it is rejected.
    if (num->trc_order > _MAXORDER_OTI){
        return DN_ERR_INDEX;
    }

    der_r_asin(num->re, num->trc_order, derivs);

    return oti_feval_to(derivs, num, res, dhl);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
otinum_t oti_acos(const otinum_t* num, dhelpl_t dhl){

    otinum_t res = oti_init();

    return dnsm_ret(oti_acos_to(num, &res, dhl), &res);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oti_acos_to(const otinum_t* num, otinum_t* res, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI + 1];

    // The derivative list is sized _MAXORDER_OTI + 1: a hand-built number above it is rejected.
    if (num->trc_order > _MAXORDER_OTI){
        return DN_ERR_INDEX;
    }

    der_r_acos(num->re, num->trc_order, derivs);

    return oti_feval_to(derivs, num, res, dhl);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
otinum_t oti_atan(const otinum_t* num, dhelpl_t dhl){

    otinum_t res = oti_init();

    return dnsm_ret(oti_atan_to(num, &res, dhl), &res);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oti_atan_to(const otinum_t* num, otinum_t* res, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI + 1];

    // The derivative list is sized _MAXORDER_OTI + 1: a hand-built number above it is rejected.
    if (num->trc_order > _MAXORDER_OTI){
        return DN_ERR_INDEX;
    }

    der_r_atan(num->re, num->trc_order, derivs);

    return oti_feval_to(derivs, num, res, dhl);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
otinum_t oti_sinh(const otinum_t* num, dhelpl_t dhl){

    otinum_t res = oti_init();

    return dnsm_ret(oti_sinh_to(num, &res, dhl), &res);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oti_sinh_to(const otinum_t* num, otinum_t* res, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI + 1];

    // The derivative list is sized _MAXORDER_OTI + 1: a hand-built number above it is rejected.
    if (num->trc_order > _MAXORDER_OTI){
        return DN_ERR_INDEX;
    }

    der_r_sinh(num->re, num->trc_order, derivs);

    return oti_feval_to(derivs, num, res, dhl);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
otinum_t oti_cosh(const otinum_t* num, dhelpl_t dhl){

    otinum_t res = oti_init();

    return dnsm_ret(oti_cosh_to(num, &res, dhl), &res);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oti_cosh_to(const otinum_t* num, otinum_t* res, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI + 1];

    // The derivative list is sized _MAXORDER_OTI + 1: a hand-built number above it is rejected.
    if (num->trc_order > _MAXORDER_OTI){
        return DN_ERR_INDEX;
    }

    der_r_cosh(num->re, num->trc_order, derivs);

    return oti_feval_to(derivs, num, res, dhl);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
otinum_t oti_tanh(const otinum_t* num, dhelpl_t dhl){

    otinum_t res = oti_init();

    return dnsm_ret(oti_tanh_to(num, &res, dhl), &res);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oti_tanh_to(const otinum_t* num, otinum_t* res, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI + 1];

    // The derivative list is sized _MAXORDER_OTI + 1: a hand-built number above it is rejected.
    if (num->trc_order > _MAXORDER_OTI){
        return DN_ERR_INDEX;
    }

    der_r_tanh(num->re, num->trc_order, derivs);

    return oti_feval_to(derivs, num, res, dhl);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
otinum_t oti_asinh(const otinum_t* num, dhelpl_t dhl){

    otinum_t res = oti_init();

    return dnsm_ret(oti_asinh_to(num, &res, dhl), &res);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oti_asinh_to(const otinum_t* num, otinum_t* res, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI + 1];

    // The derivative list is sized _MAXORDER_OTI + 1: a hand-built number above it is rejected.
    if (num->trc_order > _MAXORDER_OTI){
        return DN_ERR_INDEX;
    }

    der_r_asinh(num->re, num->trc_order, derivs);

    return oti_feval_to(derivs, num, res, dhl);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
otinum_t oti_acosh(const otinum_t* num, dhelpl_t dhl){

    otinum_t res = oti_init();

    return dnsm_ret(oti_acosh_to(num, &res, dhl), &res);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oti_acosh_to(const otinum_t* num, otinum_t* res, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI + 1];

    // The derivative list is sized _MAXORDER_OTI + 1: a hand-built number above it is rejected.
    if (num->trc_order > _MAXORDER_OTI){
        return DN_ERR_INDEX;
    }

    der_r_acosh(num->re, num->trc_order, derivs);

    return oti_feval_to(derivs, num, res, dhl);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
otinum_t oti_atanh(const otinum_t* num, dhelpl_t dhl){

    otinum_t res = oti_init();

    return dnsm_ret(oti_atanh_to(num, &res, dhl), &res);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oti_atanh_to(const otinum_t* num, otinum_t* res, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI + 1];

    // The derivative list is sized _MAXORDER_OTI + 1: a hand-built number above it is rejected.
    if (num->trc_order > _MAXORDER_OTI){
        return DN_ERR_INDEX;
    }

    der_r_atanh(num->re, num->trc_order, derivs);

    return oti_feval_to(derivs, num, res, dhl);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
otinum_t oti_erf(const otinum_t* num, dhelpl_t dhl){

    otinum_t res = oti_init();

    return dnsm_ret(oti_erf_to(num, &res, dhl), &res);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oti_erf_to(const otinum_t* num, otinum_t* res, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI + 1];

    // The derivative list is sized _MAXORDER_OTI + 1: a hand-built number above it is rejected.
    if (num->trc_order > _MAXORDER_OTI){
        return DN_ERR_INDEX;
    }

    der_r_erf(num->re, num->trc_order, derivs);

    return oti_feval_to(derivs, num, res, dhl);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
otinum_t oti_pow(const otinum_t* num, coeff_t e, dhelpl_t dhl){

    otinum_t res = oti_init();

    return dnsm_ret(oti_pow_to(num, e, &res, dhl), &res);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oti_pow_to(const otinum_t* num, coeff_t e, otinum_t* res, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI + 1];

    // The derivative list is sized _MAXORDER_OTI + 1: a hand-built number above it is rejected.
    if (num->trc_order > _MAXORDER_OTI){
        return DN_ERR_INDEX;
    }

    der_r_pow(num->re, e, num->trc_order, derivs);

    return oti_feval_to(derivs, num, res, dhl);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
otinum_t oti_logb(const otinum_t* num, coeff_t base, dhelpl_t dhl){

    otinum_t res = oti_init();

    return dnsm_ret(oti_logb_to(num, base, &res, dhl), &res);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oti_logb_to(const otinum_t* num, coeff_t base, otinum_t* res, dhelpl_t dhl){

    coeff_t derivs[_MAXORDER_OTI + 1];

    // The derivative list is sized _MAXORDER_OTI + 1: a hand-built number above it is rejected.
    if (num->trc_order > _MAXORDER_OTI){
        return DN_ERR_INDEX;
    }

    der_r_logb(num->re, base, num->trc_order, derivs);

    return oti_feval_to(derivs, num, res, dhl);

}
// -------------------------------------------------------------------------------------------------------
