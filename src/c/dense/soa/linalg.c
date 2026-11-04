// Dense SoA linear algebra (PLAN-dense-update.md): LU, solve, inverse, determinant through the oti_d*
// LAPACK wrappers (include/oti/dense/soa/linalg.h).
//
// Owner: WP3 (dense-port). Unity-included from src/c/dense.c, so every static helper here carries the
// prefix dnol_ (all dense sources share one translation unit).


// *******************************************************************************************************
// Allocates nblocks * blocksize reals, checking the byte count and the dense byte budget. Returns NULL
// on overflow, above the budget, or on failure
// (and never NULL for a zero count, so that NULL means failure).
static coeff_t* dnol_alloc(uint64_t nblocks, uint64_t blocksize){

    if (blocksize != 0 && nblocks > SIZE_MAX / sizeof(coeff_t) / blocksize){
        return NULL;
    }

    // A scratch buffer far above the byte budget is refused before anything is written to it.
    if (dnsm_budget(nblocks * blocksize) != DN_OK){
        return NULL;
    }

    return (coeff_t*)malloc((size_t)(nblocks * blocksize) * sizeof(coeff_t) + 1);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// A call-local buffer of nbytes from the calling thread's scratch arena (nd_alloc(ND_ALLOC_SCRATCH),
// the 7a allocation fix): *p gets its memory, `hold` keeps it until nd_release(hold), which must run on
// this thread before the call returns. coeff_bytes > 0 also charges that many coefficient bytes to the
// dense byte budget (dnsm_budget()). DN_ERR_MEMORY on a failure (hold left empty).
static int dnol_scratch(size_t nbytes, size_t coeff_bytes, ndarr_t* hold, void** p){

    int64_t len = (nbytes > 0) ? (int64_t)nbytes : 1;

    nd_init_empty(hold);
    *p = NULL;

    if (nbytes > (size_t)INT64_MAX || (coeff_bytes > 0 && dnsm_budget(coeff_bytes / sizeof(coeff_t))
                                                         != DN_OK)){
        return DN_ERR_MEMORY;
    }

    if (nd_alloc(NULL, OTI_U8, 1, &len, ND_LAYOUT_C, ND_ALLOC_SCRATCH, hold) != OTI_OK){
        return DN_ERR_MEMORY;
    }

    *p = hold->data;

    return DN_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// A call-local canonical array over (nact, trc) of element shape S on the scratch arena (meta in its
// extra zone): for the arrays that never leave a call (inv's identity, solve's LU copy). Released by
// oarr_free() on this thread. The contents are unspecified.
static int dnol_scratch_array(bases_t nact, const dnob_shape_t* S, ord_t trc, oarr_t* res){

    uint64_t size;
    size_t need;
    int status;

    *res = oarr_init();

    if (dnob_shape_size_s(S, &size) != DN_OK || dnob_nreals(nact, trc, size, &need) != DN_OK
        || dnob_layout_ok(dnob_nblocks(nact, trc), S) != DN_OK){
        return DN_ERR_MEMORY;
    }

    status = dnob_new_owned_f(res, need, nact, trc, ND_ALLOC_SCRATCH);

    if (status != DN_OK){
        return status;
    }

    res->cap = nact;
    dnob_set_layout(res, dnob_nblocks(nact, trc), S);

    return DN_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// LU factorization of a canonical square matrix on the scratch arena: lu->A a scratch copy of A, the
// pivots in `ipiv_hold` (released with dnol_lu_scratch_free()). Returns as oarr_lu_factor().
static int dnol_lu_scratch(const oarr_t* A, oarr_lu_t* lu, ndarr_t* ipiv_hold){

    dnob_shape_t S = dnob_shape_of(A);
    size_t n;
    int info = 0, status;
    void* p;

    lu->A      = oarr_init();
    lu->p_ipiv = NULL;
    nd_init_empty(ipiv_hold);
    S.layout   = ND_LAYOUT_F;

    status = dnol_scratch_array(oarr_nact(A), &S, oarr_trc_order(A), &lu->A);

    if (status != DN_OK){
        return status;
    }

    n = dnob_used(A);

    if (n > 0){
        memcpy(oarr_data(&lu->A), oarr_data(A), n * sizeof(coeff_t));
    }

    oarr_set_act_order(&lu->A, oarr_act_order(A));

    status = dnol_scratch((size_t)oarr_nrows(A) * sizeof(int), 0, ipiv_hold, &p);

    if (status != DN_OK){
        return status;
    }

    lu->p_ipiv = (int*)p;

    if (oarr_nrows(A) > 0){

        oti_dgetrf((int)oarr_nrows(A), (int)oarr_nrows(A), oarr_data(&lu->A), (int)oarr_nrows(A),
                   lu->p_ipiv, &info);

        if (info < 0){
            return DN_ERR_ARGUMENT;
        }

    }

    return info;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Releases a dnol_lu_scratch() factorization.
static void dnol_lu_scratch_free(oarr_lu_t* lu, ndarr_t* ipiv_hold){

    oarr_free(&lu->A);
    nd_release(ipiv_hold);
    lu->p_ipiv = NULL;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Tells whether the product a * b fits the LAPACK integers, without wrapping around in uint64_t.
static int dnol_fits_prod(uint64_t a, uint64_t b){

    return oti_lapack_fits(a) && (a == 0 || b <= UINT64_MAX / a) && oti_lapack_fits(a * b);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Largest N_p(k) for p in 1..trc (at least 1).
static ndir_t dnol_max_ndir(bases_t k, ord_t trc){

    ndir_t n, nmax = 1;
    ord_t p;

    for (p = 1; p <= trc; p++){

        n    = sshelp_ndir_order(k, p);
        nmax = (n > nmax) ? n : nmax;

    }

    return nmax;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oarr_lu_factor(const oarr_t* A, oarr_lu_t* lu){

    DNOB_IN1(A, NULL, oarr_lu_factor(c_.in[0], lu));

    int info = 0, status;

    if (lu == NULL){
        return DN_ERR_ARGUMENT;
    }

    lu->A      = oarr_init();
    lu->p_ipiv = NULL;

    if (A == NULL){
        return DN_ERR_ARGUMENT;
    }

    if (!dnob_is_matrix(A) || oarr_nrows(A) != oarr_ncols(A) || !oti_lapack_fits(oarr_nrows(A))){
        return DN_ERR_SIZE;
    }

    status = oarr_copy_to(A, &lu->A);

    if (status != DN_OK){
        return status;
    }

    lu->p_ipiv = (int*)malloc((size_t)oarr_nrows(A) * sizeof(int) + 1);

    if (lu->p_ipiv == NULL){
        return DN_ERR_MEMORY;
    }

    if (oarr_nrows(A) > 0){

        oti_dgetrf((int)oarr_nrows(A), (int)oarr_nrows(A), oarr_data(&lu->A), (int)oarr_nrows(A),
                   lu->p_ipiv, &info);

        if (info < 0){
            return DN_ERR_ARGUMENT;
        }

    }

    return info;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void oarr_lu_free(oarr_lu_t* lu){

    if (lu == NULL){
        return;
    }

    oarr_free(&lu->A);
    free(lu->p_ipiv);

    lu->p_ipiv = NULL;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oarr_lu_solve(const oarr_lu_t* lu, const oarr_t* b, oarr_t* x, dhelpl_t dhl){

    DNOB_IN1(b, x, oarr_lu_solve(lu, c_.in[0], c_.res, dhl));

    const oarr_t* A;
    uint64_t n, m, sa, sx, i;
    bases_t nu;
    ord_t trc, atop, act, p, s;
    ndir_t nimag, Np;
    size_t nreals;
    coeff_t *Aexp = NULL, *X = NULL, *work = NULL;
    const coeff_t* Au;
    int status = DN_OK, info = 0;

    if (lu == NULL || b == NULL || x == NULL){
        return DN_ERR_ARGUMENT;
    }

    A = &lu->A;
    n = oarr_nrows(A);
    m = oarr_ncols(b);

    if (!dnob_is_matrix(A) || !dnob_is_matrix(b) || oarr_nrows(A) != oarr_ncols(A) || oarr_nrows(b) != n
        || !oti_lapack_fits(n) || !oti_lapack_fits(m)){
        return DN_ERR_SIZE;
    }

    if (n > 0 && lu->p_ipiv == NULL){
        return DN_ERR_ARGUMENT;
    }

    for (i = 0; i < n; i++){

        if (lu->p_ipiv[i] < 1 || (uint64_t)lu->p_ipiv[i] > n){
            return DN_ERR_PIVOT;
        }

    }

    // A factorization of a singular matrix: info > 0 as dgetrf gives it (the first zero pivot, 1-based).
    for (i = 0; i < n; i++){

        if (oarr_data(A)[i + i * n] == 0.0){
            return (int)(i + 1);
        }

    }

    sa  = n * n;
    sx  = n * m;
    nu  = (oarr_nact(A) > oarr_nact(b)) ? oarr_nact(A) : oarr_nact(b);
    trc = (oarr_trc_order(A) > oarr_trc_order(b)) ? oarr_trc_order(A) : oarr_trc_order(b);

    if (sshelp_ndir_total_checked(nu, trc, &nimag) != SSHELP_OK){
        return DN_ERR_MEMORY;
    }

    atop = (oarr_act_order(A) < trc) ? oarr_act_order(A) : trc;
    act  = (atop > 0) ? trc : ((oarr_act_order(b) < trc) ? oarr_act_order(b) : trc);

    // The solution scratch X and the expanded A go through the dense byte budget (dnob_nreals())
    // before anything is allocated or zero-filled.
    if (dnob_nreals(nu, trc, sx, &nreals) != DN_OK ||
        (atop != 0 && oarr_nact(A) != nu && dnob_nreals(nu, trc, sa, &nreals) != DN_OK)){
        return DN_ERR_MEMORY;
    }

    for (p = 1; p <= act; p++){

        if (!dnol_fits_prod(m, sshelp_ndir_order(nu, p))){
            return DN_ERR_SIZE;
        }

    }

    // X starts as B (in the layout over nu bases) and is solved in place order by order.
    X    = dnol_alloc(1 + nimag, sx);
    work = dnol_alloc(dnol_max_ndir(nu, trc), sx);

    if (atop == 0 || oarr_nact(A) == nu){
        Au = oarr_data(A);                     // A is used in place (only its real block when atop = 0).
    } else {
        Aexp = dnol_alloc(1 + nimag, sa);
        Au   = Aexp;
    }

    // An empty A has no buffer (Au == NULL) without any allocation failing.
    if (X == NULL || work == NULL || (Au == NULL && sa > 0)){
        status = DN_ERR_MEMORY;
        goto cleanup;
    }

    if (Aexp != NULL){
        oarr_kernel_expand(A, nu, trc, Aexp);
    }

    oarr_kernel_expand(b, nu, trc, X);

    if (n > 0 && m > 0){

        // Order 0: K_re X_0 = B_0 (Au's real block holds the LU factors).
        oti_dgetrs('N', (int)n, (int)m, Au, (int)n, lu->p_ipiv, X, (int)n, &info);

        for (p = 1; p <= act; p++){

            // X_p = B_p - sum_s K_s X_{p-s}; one order pair per call so only order p is written
            // (the kernel reads the order-(p-s) blocks and writes the order-p ones: disjoint).
            for (s = 1; s <= p && s <= atop; s++){

                status = oarr_kernel_matmul_acc(Au, s, s, X, p - s, p - s, nu, trc, n, n, m, -1.0, X,
                                                work, dhl);

                if (status != DN_OK){
                    goto cleanup;
                }

            } // end for

            // All order-p right-hand sides at once: an n x (m * N_p) matrix.
            Np = sshelp_ndir_order(nu, p);
            oti_dgetrs('N', (int)n, (int)(m * Np), Au, (int)n, lu->p_ipiv,
                       X + oarr_block_index(nu, p, 0) * sx, (int)n, &info);

        } // end for

    } // end if

    // Store (x may alias b).
    status = oarr_reserve(x, nu, n, m, trc);

    if (status != DN_OK){
        goto cleanup;
    }

    status = dnob_set_nact_trc(x, nu, trc);

    if (status != DN_OK){
        goto cleanup;
    }

    if (sx > 0){
        memcpy(oarr_data(x), X, (size_t)((1 + nimag) * sx) * sizeof(coeff_t));
    }

    // Conventions: trc (0 for a real result).
    oarr_set_act_order(x, (atop == 0 && oarr_act_order(b) == 0) ? 0 : trc);

cleanup:

    free(X);
    free(work);
    free(Aexp);

    return status;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oarr_solve_to(const oarr_t* K, const oarr_t* b, oarr_t* x, dhelpl_t dhl){

    DNOB_IN2(K, b, x, oarr_solve_to(c_.in[0], c_.in[1], c_.res, dhl));

    oarr_lu_t lu;
    ndarr_t ipiv;
    int status;

    if (K == NULL){
        return DN_ERR_ARGUMENT;
    }

    if (!dnob_is_matrix(K) || oarr_nrows(K) != oarr_ncols(K) || !oti_lapack_fits(oarr_nrows(K))){
        return DN_ERR_SIZE;
    }

    // The LU copy and the pivots never leave the call: the scratch arena (the 7a allocation fix).
    status = dnol_lu_scratch(K, &lu, &ipiv);

    if (status == DN_OK){
        status = oarr_lu_solve(&lu, b, x, dhl);
    }

    dnol_lu_scratch_free(&lu, &ipiv);

    return status;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oarr_inv_to(const oarr_t* A, oarr_t* res, dhelpl_t dhl){

    DNOB_IN1(A, res, oarr_inv_to(c_.in[0], c_.res, dhl));

    oarr_t eye = oarr_init();
    int status;

    if (A == NULL || res == NULL){
        return DN_ERR_ARGUMENT;
    }

    if (!dnob_is_matrix(A) || oarr_nrows(A) != oarr_ncols(A) || !oti_lapack_fits(oarr_nrows(A))){
        return DN_ERR_SIZE;
    }

    // The identity never leaves the call: the scratch arena (the 7a allocation fix).
    {
        dnob_shape_t S = dnob_shape2(oarr_nrows(A), oarr_nrows(A));
        uint64_t i, nr = oarr_nrows(A);

        status = dnol_scratch_array(0, &S, oarr_trc_order(A), &eye);

        if (status == DN_OK){

            if (dnob_used(&eye) > 0){
                memset(oarr_data(&eye), 0, dnob_used(&eye) * sizeof(coeff_t));
            }

            for (i = 0; i < nr; i++){
                oarr_data(&eye)[i + i * nr] = 1.0;
            }

            oarr_set_act_order(&eye, 0);

        }

    }

    if (status == DN_OK){
        status = oarr_solve_to(A, &eye, res, dhl);
    }

    oarr_free(&eye);

    return status;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Adds scale * trace of every imaginary block of P (orders lo..trc) to the coefficients of t (which has
// the same layout as P: coefficient d of t is block 1 + d of P).
static void dnol_trace_acc(const coeff_t* P, uint64_t n, ord_t lo, coeff_t scale, otinum_t* t){

    ndir_t d, d0 = sshelp_order_offset(t->nact, lo);
    ndir_t nimag = sshelp_ndir_total(t->nact, t->trc_order);
    uint64_t r, sa = n * n;
    const coeff_t* Pd;
    coeff_t tr;

    for (d = d0; d < nimag; d++){

        Pd = P + (1 + d) * sa;
        tr = 0.0;

        for (r = 0; r < n; r++){
            tr += Pd[r + r * n];
        }

        t->p_im[d] += scale * tr;

    } // end for

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oarr_det_to(const oarr_t* A, otinum_t* res, dhelpl_t dhl){

    DNOB_IN1(A, NULL, oarr_det_to(c_.in[0], res, dhl));

    uint64_t n, sa, r;
    bases_t k;
    ord_t trc, atop, mo;
    ndir_t nimag = 0, nimag_a = 0;
    coeff_t *LU = NULL, *M = NULL, *P = NULL, *Q = NULL, *work = NULL, *tmp, det0 = 1.0;
    int *ipiv = NULL, info = 0, status = DN_OK;
    otinum_t t = oti_init();
    ndarr_t lu_hold, ipiv_hold;
    void* vp = NULL;

    nd_init_empty(&lu_hold);
    nd_init_empty(&ipiv_hold);

    if (A == NULL || res == NULL){
        return DN_ERR_ARGUMENT;
    }

    n   = oarr_nrows(A);
    sa  = n * n;
    k   = oarr_nact(A);
    trc = oarr_trc_order(A);

    if (!dnob_is_matrix(A) || oarr_nrows(A) != oarr_ncols(A) || !oti_lapack_fits(n)){
        return DN_ERR_SIZE;
    }

    atop = (oarr_act_order(A) < trc) ? oarr_act_order(A) : trc;

    if (sshelp_ndir_total_checked(k, trc, &nimag) != SSHELP_OK){
        return DN_ERR_MEMORY;
    }

    nimag_a = sshelp_ndir_total(k, atop);           // imaginary blocks that can be nonzero.

    if (!dnol_fits_prod(n, nimag_a)){
        return DN_ERR_SIZE;
    }

    // The LU copy of the real part and the pivots never leave the call: the scratch arena.
    if (sa > SIZE_MAX / sizeof(coeff_t)
        || dnol_scratch((size_t)sa * sizeof(coeff_t), (size_t)sa * sizeof(coeff_t), &lu_hold, &vp)
           != DN_OK
        || (LU = (coeff_t*)vp, dnol_scratch((size_t)n * sizeof(int), 0, &ipiv_hold, &vp)) != DN_OK){
        status = DN_ERR_MEMORY;
        goto cleanup;
    }

    ipiv = (int*)vp;

    // det of the real part from its LU factors.
    if (sa > 0){
        memcpy(LU, oarr_data(A), (size_t)sa * sizeof(coeff_t));
    }

    if (n > 0){

        oti_dgetrf((int)n, (int)n, LU, (int)n, ipiv, &info);

        if (info != 0){
            status = (info > 0) ? info : DN_ERR_ARGUMENT;
            goto cleanup;
        }

    }

    // 7c: det0 moves to nd_slogdet's rule, sign * exp(sum log|u_ii|) (contracts S20, 9.4; critic W2
    // finding 3), so that det(omat).real equals numpy.linalg.det on diag(1e200, 1e200, 1e-200,
    // 1e-200). 7a keeps the plain product of the pivots, bit for bit.
    for (r = 0; r < n; r++){

        det0 *= LU[r + r * n];

        if (ipiv[r] != (int)(r + 1)){
            det0 = -det0;
        }

    } // end for

    if (k == 0 || atop == 0 || n == 0){

        // No imaginary part: a real determinant over the matrix's bases (never dropped).
        status = oti_create_empty_to(k, trc, res);

        if (status == DN_OK){
            res->re = det0;
        }

        goto cleanup;

    }

    // M = A_re^-1 (A - A_re): imaginary blocks only, all solved with one dgetrs.
    M    = dnol_alloc(1 + nimag, sa);
    P    = dnol_alloc(1 + nimag, sa);
    Q    = dnol_alloc(1 + nimag, sa);
    work = dnol_alloc(dnol_max_ndir(k, trc), sa);

    if (M == NULL || P == NULL || Q == NULL || work == NULL){
        status = DN_ERR_MEMORY;
        goto cleanup;
    }

    memset(M, 0, (size_t)((1 + nimag) * sa) * sizeof(coeff_t));
    memcpy(M + sa, oarr_data(A) + sa, (size_t)(nimag_a * sa) * sizeof(coeff_t));
    oti_dgetrs('N', (int)n, (int)(n * nimag_a), LU, (int)n, ipiv, M + sa, (int)n, &info);

    // t = sum_m (-1)^(m+1) tr(M^m) / m. P holds M^(m-1), with orders m-1 .. trc.
    status = oti_create_empty_to(k, trc, &t);

    if (status != DN_OK){
        goto cleanup;
    }

    memcpy(P, M, (size_t)((1 + nimag) * sa) * sizeof(coeff_t));
    dnol_trace_acc(P, n, 1, 1.0, &t);

    for (mo = 2; mo <= trc; mo++){

        memset(Q, 0, (size_t)((1 + nimag) * sa) * sizeof(coeff_t));
        status = oarr_kernel_matmul_acc(P, mo - 1, trc, M, 1, atop, k, trc, n, n, n, 1.0, Q, work,
                                        dhl);

        if (status != DN_OK){
            goto cleanup;
        }

        dnol_trace_acc(Q, n, mo, ((mo % 2) ? 1.0 : -1.0) / mo, &t);

        tmp = P;
        P   = Q;
        Q   = tmp;

    } // end for

    t.act_order = trc;

    // det = det0 * exp(t).
    status = oti_exp_to(&t, res, dhl);

    if (status == DN_OK){
        status = oti_mul_or_to(res, det0, res, dhl);
    }

cleanup:

    oti_free(&t);
    nd_release(&lu_hold);
    nd_release(&ipiv_hold);
    free(M);
    free(P);
    free(Q);
    free(work);

    return status;

}
// -------------------------------------------------------------------------------------------------------
