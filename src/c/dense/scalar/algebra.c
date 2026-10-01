// Dense scalar: kernels and algebra (include/oti/dense/scalar/algebra.h).
//
// Unity-included from src/c/dense.c: static helpers here carry the dnsa_ prefix. Local and global
// numbering coincide, so an operand over fewer bases is read in place at its own offsets: its order-p
// block is the first N_p(k_small) directions of the larger layout, and the product index of two of its
// directions is the same whatever the layout. Later dense files use dnsa_kernel_mul_mixed() and
// dnsa_grow().


// *******************************************************************************************************
// Rank-fallback product of one order pair, R[rank(u_i + u_j)] += A[i] * B[j], over Np x Nq directions
// of bases below kt (the larger of the operands' nact). Walks the tuples with sshelp_next_dir(), so the
// only allocation is the binomial table; if even that fails, the global rank of the merged labels is
// used instead (slower, never fails).
static void dnsa_kernel_pair_rank(const coeff_t* A, ord_t p, ndir_t Np, const coeff_t* B, ord_t q,
                                  ndir_t Nq, bases_t kt, coeff_t* R){

    bases_t u[256], v[256], w[256];
    sshelp_rank_tab_t tab;
    int have_tab = (sshelp_rank_tab_init(&tab, kt, p + q) == SSHELP_OK);
    ndir_t i, j;
    ord_t t;
    coeff_t ai;

    memset(u, 0, (size_t)p * sizeof(bases_t));

    for (i = 0; i < Np; i++){

        ai = A[i];

        if (ai != 0.0){

            memset(v, 0, (size_t)q * sizeof(bases_t));

            for (j = 0; j < Nq; j++){

                if (have_tab){

                    R[sshelp_prod_rank(u, p, v, q, &tab)] += ai * B[j];

                } else {

                    dnutil_merge_tuples(u, p, v, q, w);

                    for (t = 0; t < p + q; t++){
                        w[t]++;
                    }

                    R[sshelp_global_rank(w, p + q)] += ai * B[j];

                }

                sshelp_next_dir(v, q, kt);

            }

        }

        sshelp_next_dir(u, p, kt);

    }

    if (have_tab){
        sshelp_rank_tab_free(&tab);
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Product of coefficient buffers over different nact, read in place: accumulates a_p * b_q into res_im
// for p in [alo, ahi], q in [blo, bhi], p + q <= trc, where a_im is dense over bases 1..ka, b_im over
// 1..kb and res_im over 1..k (ka, kb <= k).
static void dnsa_kernel_mul_mixed(const coeff_t* a_im, bases_t ka, ord_t alo, ord_t ahi,
                                  const coeff_t* b_im, bases_t kb, ord_t blo, ord_t bhi,
                                  bases_t k, ord_t trc, coeff_t* res_im, dhelpl_t dhl){

    bases_t kt = (ka > kb) ? ka : kb;
    ord_t p, q;
    ndir_t i, j, Np, Nq;
    const coeff_t *A, *B;
    const imdir_t* T;
    coeff_t *R, c;
    sshelp_pair_t pair;

    if (ka == 0 || kb == 0){
        return;
    }

    for (p = alo; p <= ahi && p + blo <= trc; p++){

        Np = sshelp_ndir_order(ka, p);
        A  = a_im + sshelp_order_offset(ka, p);

        for (q = blo; q <= bhi && p + q <= trc; q++){

            Nq = sshelp_ndir_order(kb, q);
            B  = b_im   + sshelp_order_offset(kb, q);
            R  = res_im + sshelp_order_offset(k, p + q);

            // Product indices are global: the pair over the larger operand's bases covers both.
            pair = sshelp_get_pair(kt, p, q, dhl);

            if (pair.p_tab == NULL){

                dnsa_kernel_pair_rank(A, p, Np, B, q, Nq, kt, R);

            } else if (!pair.transpose){

                // Table rows are order-p directions.
                for (i = 0; i < Np; i++){

                    c = A[i];

                    if (c == 0.0){
                        continue;
                    }

                    T = pair.p_tab + i * pair.stride;

                    for (j = 0; j < Nq; j++){
                        R[T[j]] += c * B[j];
                    }

                }

            } else {

                // Table rows are order-q directions.
                for (j = 0; j < Nq; j++){

                    c = B[j];

                    if (c == 0.0){
                        continue;
                    }

                    T = pair.p_tab + j * pair.stride;

                    for (i = 0; i < Np; i++){
                        R[T[i]] += A[i] * c;
                    }

                }

            }

        }

    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void oti_kernel_mul_acc(const coeff_t* a_im, ord_t alo, ord_t ahi,
                        const coeff_t* b_im, ord_t blo, ord_t bhi,
                        bases_t k, ord_t trc, coeff_t* res_im, dhelpl_t dhl){

    dnsa_kernel_mul_mixed(a_im, k, alo, ahi, b_im, k, blo, bhi, k, trc, res_im, dhl);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void oti_kernel_expand(const otinum_t* num, bases_t ku, ord_t trc, coeff_t* dst_im){

    bases_t k = num->nact;
    ord_t p, top = (num->act_order < trc) ? num->act_order : trc;
    ndir_t Ns, Nd;
    coeff_t* D;

    for (p = 1; p <= trc; p++){

        Nd = sshelp_ndir_order(ku, p);
        D  = dst_im + sshelp_order_offset(ku, p);
        Ns = (p <= top) ? sshelp_ndir_order(k, p) : 0;

        // Colex prefix: the source block is the first Ns target directions.
        if (Ns > 0){
            memcpy(D, num->p_im + sshelp_order_offset(k, p), (size_t)Ns * sizeof(coeff_t));
        }

        memset(D + Ns, 0, (size_t)(Nd - Ns) * sizeof(coeff_t));

    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Grows a number in place to the layout (nact, trc), keeping its value (zero-extension).
static int dnsa_grow(otinum_t* num, bases_t nact, ord_t trc){

    int status = oti_reserve(num, nact, trc);

    if (status != DN_OK){
        return status;
    }

    // Cannot fail: the capacity now holds the new layout.
    return oti_add_bases(nact, num);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// R = sa * a + sb * b over the layout (k, trc), each operand read in place at its own offsets.
static void dnsa_axpby_im(coeff_t sa, const otinum_t* a, coeff_t sb, const otinum_t* b, bases_t k,
                          ord_t trc, coeff_t* R){

    ord_t p;
    ndir_t i, na, nb, n, nmin;
    const coeff_t *A, *B;
    coeff_t* D;

    for (p = 1; p <= trc; p++){

        n  = sshelp_ndir_order(k, p);
        D  = R + sshelp_order_offset(k, p);
        na = (p <= a->act_order) ? sshelp_ndir_order(a->nact, p) : 0;
        nb = (p <= b->act_order) ? sshelp_ndir_order(b->nact, p) : 0;
        A  = (na > 0) ? a->p_im + sshelp_order_offset(a->nact, p) : NULL;
        B  = (nb > 0) ? b->p_im + sshelp_order_offset(b->nact, p) : NULL;

        nmin = (na < nb) ? na : nb;

        for (i = 0; i < nmin; i++){
            D[i] = sa * A[i] + sb * B[i];
        }

        for (i = nmin; i < na; i++){
            D[i] = sa * A[i];
        }

        for (i = nmin; i < nb; i++){
            D[i] = sb * B[i];
        }

        i = (na > nb) ? na : nb;
        memset(D + i, 0, (size_t)(n - i) * sizeof(coeff_t));

    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Scales the used coefficients of a number (orders 1..act_order).
static void dnsa_scale_im(coeff_t val, otinum_t* num){

    ndir_t i, n = sshelp_order_offset(num->nact, (ord_t)(num->act_order + 1));

    if (num->nact == 0 || num->act_order == 0){
        return;
    }

    for (i = 0; i < n; i++){
        num->p_im[i] *= val;
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// self = s_self * self + s_other * other in place (self != other); self is grown first.
static int dnsa_axpby_inplace(coeff_t s_self, otinum_t* self, coeff_t s_other, const otinum_t* other){

    bases_t k = (self->nact > other->nact) ? self->nact : other->nact;
    ord_t p, trc = (self->trc_order > other->trc_order) ? self->trc_order : other->trc_order;
    ord_t top = (other->nact == 0) ? 0 : other->act_order;
    ndir_t i, n;
    const coeff_t* B;
    coeff_t* D;
    int status = dnsa_grow(self, k, trc);

    if (status != DN_OK){
        return status;
    }

    if (s_self != 1.0){
        dnsa_scale_im(s_self, self);
    }

    for (p = 1; p <= top; p++){

        n = sshelp_ndir_order(other->nact, p);
        B = other->p_im + sshelp_order_offset(other->nact, p);
        D = self->p_im  + sshelp_order_offset(k, p);

        for (i = 0; i < n; i++){
            D[i] += s_other * B[i];
        }

    }

    self->re = s_self * self->re + s_other * other->re;

    if (top > self->act_order){
        self->act_order = top;
    }

    return DN_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// res = sa * a + sb * b (sums and subtractions).
static int dnsa_axpby_to(coeff_t sa, const otinum_t* a, coeff_t sb, const otinum_t* b, otinum_t* res){

    bases_t k = (a->nact > b->nact) ? a->nact : b->nact;
    ord_t trc = (a->trc_order > b->trc_order) ? a->trc_order : b->trc_order;
    ord_t act_a = (a->nact == 0) ? 0 : a->act_order, act_b = (b->nact == 0) ? 0 : b->act_order;
    ord_t act = (act_a > act_b) ? act_a : act_b;
    coeff_t re = sa * a->re + sb * b->re;
    int status;

    if (a == b){

        status = oti_copy_to(a, res);

        if (status == DN_OK){
            dnsa_scale_im(sa + sb, res);
            res->re = re;
        }

        return status;

    }

    if (res == a){
        return dnsa_axpby_inplace(sa, res, sb, b);
    }

    if (res == b){
        return dnsa_axpby_inplace(sb, res, sa, a);
    }

    status = dnsm_prepare(res, k, trc);

    if (status != DN_OK){
        return status;
    }

    dnsa_axpby_im(sa, a, sb, b, k, trc, res->p_im);

    res->re        = re;
    res->act_order = (k == 0) ? 0 : act;

    return DN_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// R += a * b over k bases, real parts included except re_a * re_b, truncated at order trc (R may have a
// higher truncation order: offsets depend only on k); returns the act_order bound of the added terms.
static ord_t dnsa_mul_acc(const otinum_t* a, const otinum_t* b, bases_t k, ord_t trc, coeff_t* R,
                          dhelpl_t dhl){

    ord_t atop = (a->nact == 0) ? 0 : ((a->act_order < trc) ? a->act_order : trc);
    ord_t btop = (b->nact == 0) ? 0 : ((b->act_order < trc) ? b->act_order : trc);
    ord_t p;
    ndir_t i, n;
    const coeff_t* S;
    coeff_t* D;
    unsigned act;

    // Real x imaginary.
    if (b->re != 0.0){

        for (p = 1; p <= atop; p++){

            n = sshelp_ndir_order(a->nact, p);
            S = a->p_im + sshelp_order_offset(a->nact, p);
            D = R + sshelp_order_offset(k, p);

            for (i = 0; i < n; i++){
                D[i] += b->re * S[i];
            }

        }

    }

    if (a->re != 0.0){

        for (p = 1; p <= btop; p++){

            n = sshelp_ndir_order(b->nact, p);
            S = b->p_im + sshelp_order_offset(b->nact, p);
            D = R + sshelp_order_offset(k, p);

            for (i = 0; i < n; i++){
                D[i] += a->re * S[i];
            }

        }

    }

    // Imaginary x imaginary.
    if (atop > 0 && btop > 0){
        dnsa_kernel_mul_mixed(a->p_im, a->nact, 1, atop, b->p_im, b->nact, 1, btop, k, trc, R, dhl);
    }

    act = (unsigned)atop + btop;

    return (ord_t)((act < trc) ? act : trc);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// res = a * b. When res aliases an operand the product is built in scratch first (the workspace for up
// to 64 KiB, else a call-local buffer that then becomes res's buffer).
static int dnsa_mul_to(const otinum_t* a, const otinum_t* b, otinum_t* res, dhelpl_t dhl){

    bases_t k = (a->nact > b->nact) ? a->nact : b->nact;
    ord_t act, trc = (a->trc_order > b->trc_order) ? a->trc_order : b->trc_order;
    coeff_t re = a->re * b->re, *R, *owned;
    ndir_t nimag;
    int status = dnsm_nimag(k, trc, &nimag);

    if (status != DN_OK){
        return status;
    }

    if ((res == a || res == b) && nimag > 0){

        R = dnsm_scratch((size_t)nimag, &owned);

        if (R == NULL){
            return DN_ERR_MEMORY;
        }

        memset(R, 0, (size_t)nimag * sizeof(coeff_t));
        act = dnsa_mul_acc(a, b, k, trc, R, dhl);

        if (owned != NULL){

            // A call-local buffer becomes res's buffer (no copy).
            free(res->p_im);
            res->p_im   = owned;
            res->nbases = k;

        } else {

            status = dnsm_prepare(res, k, trc);

            if (status == DN_OK){
                memcpy(res->p_im, R, (size_t)nimag * sizeof(coeff_t));
            }

            dnsm_scratch_free(R, NULL);

            if (status != DN_OK){
                return status;
            }

        }

    } else {

        status = dnsm_prepare(res, k, trc);

        if (status != DN_OK){
            return status;
        }

        if (nimag > 0){
            memset(res->p_im, 0, (size_t)nimag * sizeof(coeff_t));
        }

        act = dnsa_mul_acc(a, b, k, trc, res->p_im, dhl);

    }

    res->re        = re;
    res->nact      = k;
    res->trc_order = trc;
    res->act_order = (k == 0) ? 0 : act;

    return DN_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
otinum_t oti_sum_oo(const otinum_t* num1, const otinum_t* num2, dhelpl_t dhl){

    otinum_t res = oti_init();

    return dnsm_ret(oti_sum_oo_to(num1, num2, &res, dhl), &res);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
otinum_t oti_sum_or(const otinum_t* num1, coeff_t val, dhelpl_t dhl){

    otinum_t res = oti_init();

    return dnsm_ret(oti_sum_or_to(num1, val, &res, dhl), &res);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oti_sum_oo_to(const otinum_t* num1, const otinum_t* num2, otinum_t* res, dhelpl_t dhl){

    (void)dhl;

    return dnsa_axpby_to(1.0, num1, 1.0, num2, res);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oti_sum_or_to(const otinum_t* num1, coeff_t val, otinum_t* res, dhelpl_t dhl){

    int status = oti_copy_to(num1, res);

    (void)dhl;
    res->re += val;

    return status;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
otinum_t oti_sub_oo(const otinum_t* num1, const otinum_t* num2, dhelpl_t dhl){

    otinum_t res = oti_init();

    return dnsm_ret(oti_sub_oo_to(num1, num2, &res, dhl), &res);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
otinum_t oti_sub_or(const otinum_t* num1, coeff_t val, dhelpl_t dhl){

    otinum_t res = oti_init();

    return dnsm_ret(oti_sub_or_to(num1, val, &res, dhl), &res);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
otinum_t oti_sub_ro(coeff_t val, const otinum_t* num1, dhelpl_t dhl){

    otinum_t res = oti_init();

    return dnsm_ret(oti_sub_ro_to(val, num1, &res, dhl), &res);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oti_sub_oo_to(const otinum_t* num1, const otinum_t* num2, otinum_t* res, dhelpl_t dhl){

    (void)dhl;

    return dnsa_axpby_to(1.0, num1, -1.0, num2, res);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oti_sub_or_to(const otinum_t* num1, coeff_t val, otinum_t* res, dhelpl_t dhl){

    int status = oti_copy_to(num1, res);

    (void)dhl;
    res->re -= val;

    return status;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oti_sub_ro_to(coeff_t val, const otinum_t* num1, otinum_t* res, dhelpl_t dhl){

    int status = oti_neg_to(num1, res, dhl);

    res->re += val;

    return status;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
otinum_t oti_neg(const otinum_t* num, dhelpl_t dhl){

    otinum_t res = oti_init();

    return dnsm_ret(oti_neg_to(num, &res, dhl), &res);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oti_neg_to(const otinum_t* num, otinum_t* res, dhelpl_t dhl){

    return oti_mul_or_to(num, -1.0, res, dhl);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
otinum_t oti_mul_oo(const otinum_t* num1, const otinum_t* num2, dhelpl_t dhl){

    otinum_t res = oti_init();

    return dnsm_ret(oti_mul_oo_to(num1, num2, &res, dhl), &res);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
otinum_t oti_mul_or(const otinum_t* num1, coeff_t val, dhelpl_t dhl){

    otinum_t res = oti_init();

    return dnsm_ret(oti_mul_or_to(num1, val, &res, dhl), &res);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oti_mul_oo_to(const otinum_t* num1, const otinum_t* num2, otinum_t* res, dhelpl_t dhl){

    return dnsa_mul_to(num1, num2, res, dhl);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oti_mul_or_to(const otinum_t* num1, coeff_t val, otinum_t* res, dhelpl_t dhl){

    int status = oti_copy_to(num1, res);

    (void)dhl;

    if (status != DN_OK){
        return status;
    }

    dnsa_scale_im(val, res);
    res->re *= val;

    return DN_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oti_gem_oo_to(const otinum_t* num1, const otinum_t* num2, const otinum_t* num3,
                  otinum_t* res, dhelpl_t dhl){

    bases_t k = (num1->nact > num2->nact) ? num1->nact : num2->nact;
    ord_t act, ptrc = (num1->trc_order > num2->trc_order) ? num1->trc_order : num2->trc_order;
    ord_t trc = (num3->trc_order > ptrc) ? num3->trc_order : ptrc;
    otinum_t prod;
    int status;

    // res aliases a factor: the product goes to scratch first.
    if (res == num1 || res == num2){

        prod   = oti_init();
        status = dnsa_mul_to(num1, num2, &prod, dhl);

        if (status == DN_OK){
            status = dnsa_axpby_to(1.0, &prod, 1.0, num3, res);
        }

        oti_free(&prod);

        return status;

    }

    k = (num3->nact > k) ? num3->nact : k;

    // res = num3 in the layout of the result, then the product accumulates straight into it. The
    // product is truncated at its own order ptrc = max(trc_1, trc_2), as num1 * num2 + num3 is: a
    // higher trc_3 only zero-extends it. Offsets depend only on k, so the cap bounds orders only.
    if (res == num3){

        status = dnsa_grow(res, k, trc);

    } else {

        status = dnsm_prepare(res, k, trc);

        if (status == DN_OK){

            oti_kernel_expand(num3, k, trc, res->p_im);
            res->re        = num3->re;
            res->act_order = num3->act_order;

        }

    }

    if (status != DN_OK){
        return status;
    }

    act = dnsa_mul_acc(num1, num2, k, ptrc, res->p_im, dhl);

    // act = max(min(act_1 + act_2, ptrc), act_3).
    res->re += num1->re * num2->re;

    if (act > res->act_order){
        res->act_order = act;
    }

    if (res->nact == 0){
        res->act_order = 0;
    }

    return DN_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
otinum_t oti_div_oo(const otinum_t* num, const otinum_t* den, dhelpl_t dhl){

    otinum_t res = oti_init();

    return dnsm_ret(oti_div_oo_to(num, den, &res, dhl), &res);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
otinum_t oti_div_ro(coeff_t val, const otinum_t* den, dhelpl_t dhl){

    otinum_t res = oti_init();

    return dnsm_ret(oti_div_ro_to(val, den, &res, dhl), &res);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
otinum_t oti_div_or(const otinum_t* num, coeff_t val, dhelpl_t dhl){

    otinum_t res = oti_init();

    return dnsm_ret(oti_div_or_to(num, val, &res, dhl), &res);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oti_div_oo_to(const otinum_t* num, const otinum_t* den, otinum_t* res, dhelpl_t dhl){

    otinum_t inv = oti_init();
    int status;

    // num * den^-1: the product uses the layouts of both operands.
    status = oti_pow_to(den, -1.0, &inv, dhl);

    if (status == DN_OK){
        status = dnsa_mul_to(num, &inv, res, dhl);
    }

    oti_free(&inv);

    return status;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oti_div_ro_to(coeff_t val, const otinum_t* den, otinum_t* res, dhelpl_t dhl){

    int status = oti_pow_to(den, -1.0, res, dhl);

    if (status != DN_OK){
        return status;
    }

    return oti_mul_or_to(res, val, res, dhl);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oti_div_or_to(const otinum_t* num, coeff_t val, otinum_t* res, dhelpl_t dhl){

    return oti_mul_or_to(num, 1.0 / val, res, dhl);

}
// -------------------------------------------------------------------------------------------------------
