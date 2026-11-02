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

    int info = 0, status;

    if (lu == NULL){
        return DN_ERR_ARGUMENT;
    }

    lu->A      = oarr_init();
    lu->p_ipiv = NULL;

    if (A == NULL){
        return DN_ERR_ARGUMENT;
    }

    if (A->nrows != A->ncols || !oti_lapack_fits(A->nrows)){
        return DN_ERR_SIZE;
    }

    status = oarr_copy_to(A, &lu->A);

    if (status != DN_OK){
        return status;
    }

    lu->p_ipiv = (int*)malloc((size_t)A->nrows * sizeof(int) + 1);

    if (lu->p_ipiv == NULL){
        return DN_ERR_MEMORY;
    }

    if (A->nrows > 0){

        oti_dgetrf((int)A->nrows, (int)A->nrows, lu->A.p_data, (int)A->nrows, lu->p_ipiv, &info);

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
    n = A->nrows;
    m = b->ncols;

    if (A->nrows != A->ncols || b->nrows != n || !oti_lapack_fits(n) || !oti_lapack_fits(m)){
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

        if (A->p_data[i + i * n] == 0.0){
            return (int)(i + 1);
        }

    }

    sa  = n * n;
    sx  = n * m;
    nu  = (A->nact > b->nact) ? A->nact : b->nact;
    trc = (A->trc_order > b->trc_order) ? A->trc_order : b->trc_order;

    if (sshelp_ndir_total_checked(nu, trc, &nimag) != SSHELP_OK){
        return DN_ERR_MEMORY;
    }

    atop = (A->act_order < trc) ? A->act_order : trc;
    act  = (atop > 0) ? trc : ((b->act_order < trc) ? b->act_order : trc);

    // The solution scratch X and the expanded A go through the dense byte budget (dnob_nreals())
    // before anything is allocated or zero-filled.
    if (dnob_nreals(nu, trc, sx, &nreals) != DN_OK ||
        (atop != 0 && A->nact != nu && dnob_nreals(nu, trc, sa, &nreals) != DN_OK)){
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

    if (atop == 0 || A->nact == nu){
        Au = A->p_data;                     // A is used in place (only its real block when atop = 0).
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

    if (sx > 0){
        memcpy(x->p_data, X, (size_t)((1 + nimag) * sx) * sizeof(coeff_t));
    }

    x->nact      = nu;
    x->trc_order = trc;
    x->act_order = (atop == 0 && b->act_order == 0) ? 0 : trc;     // conventions: trc (0 if real).

cleanup:

    free(X);
    free(work);
    free(Aexp);

    return status;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oarr_solve_to(const oarr_t* K, const oarr_t* b, oarr_t* x, dhelpl_t dhl){

    oarr_lu_t lu;
    int status = oarr_lu_factor(K, &lu);

    if (status == DN_OK){
        status = oarr_lu_solve(&lu, b, x, dhl);
    }

    oarr_lu_free(&lu);

    return status;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oarr_inv_to(const oarr_t* A, oarr_t* res, dhelpl_t dhl){

    oarr_t eye = oarr_init();
    int status;

    if (A == NULL || res == NULL){
        return DN_ERR_ARGUMENT;
    }

    if (A->nrows != A->ncols || !oti_lapack_fits(A->nrows)){
        return DN_ERR_SIZE;
    }

    status = oarr_eye_to(A->nrows, A->trc_order, &eye);

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

    uint64_t n, sa, r;
    bases_t k;
    ord_t trc, atop, mo;
    ndir_t nimag = 0, nimag_a = 0;
    coeff_t *LU = NULL, *M = NULL, *P = NULL, *Q = NULL, *work = NULL, *tmp, det0 = 1.0;
    int *ipiv = NULL, info = 0, status = DN_OK;
    otinum_t t = oti_init();

    if (A == NULL || res == NULL){
        return DN_ERR_ARGUMENT;
    }

    n   = A->nrows;
    sa  = n * n;
    k   = A->nact;
    trc = A->trc_order;

    if (A->nrows != A->ncols || !oti_lapack_fits(n)){
        return DN_ERR_SIZE;
    }

    atop = (A->act_order < trc) ? A->act_order : trc;

    if (sshelp_ndir_total_checked(k, trc, &nimag) != SSHELP_OK){
        return DN_ERR_MEMORY;
    }

    nimag_a = sshelp_ndir_total(k, atop);           // imaginary blocks that can be nonzero.

    if (!dnol_fits_prod(n, nimag_a)){
        return DN_ERR_SIZE;
    }

    LU   = dnol_alloc(1, sa);
    ipiv = (int*)malloc((size_t)n * sizeof(int) + 1);

    if (LU == NULL || ipiv == NULL){
        status = DN_ERR_MEMORY;
        goto cleanup;
    }

    // det of the real part from its LU factors.
    if (sa > 0){
        memcpy(LU, A->p_data, (size_t)sa * sizeof(coeff_t));
    }

    if (n > 0){

        oti_dgetrf((int)n, (int)n, LU, (int)n, ipiv, &info);

        if (info != 0){
            status = (info > 0) ? info : DN_ERR_ARGUMENT;
            goto cleanup;
        }

    }

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
    memcpy(M + sa, A->p_data + sa, (size_t)(nimag_a * sa) * sizeof(coeff_t));
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
    free(LU);
    free(ipiv);
    free(M);
    free(P);
    free(Q);
    free(work);

    return status;

}
// -------------------------------------------------------------------------------------------------------
