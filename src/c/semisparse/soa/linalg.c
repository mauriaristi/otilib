// Semi-sparse SoA arrays: linear algebra (LU, solve, inverse, determinant).


// *******************************************************************************************************
// Allocates nblocks * blocksize reals, checking the byte count. Returns NULL on overflow or failure.
static coeff_t* oarrss_linalg_alloc(uint64_t nblocks, uint64_t blocksize){

    if (blocksize != 0 && nblocks > SIZE_MAX / sizeof(coeff_t) / blocksize){
        return NULL;
    }

    return (coeff_t*)malloc((size_t)(nblocks * blocksize) * sizeof(coeff_t) + 1);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Largest N_p(k) for p in 1..trc (at least 1).
static ndir_t oarrss_linalg_max_ndir(bases_t k, ord_t trc){

    ndir_t n, nmax = 1;
    ord_t p;

    for (p = 1; p <= trc; p++){

        n = sshelp_ndir_order(k, p);
        nmax = (n > nmax) ? n : nmax;

    }

    return nmax;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oarrss_lu_factor(const oarrss_t* A, oarrss_lu_t* lu){

    int info = 0;

    lu->A      = oarrss_init();
    lu->p_ipiv = NULL;

    if (A->nrows != A->ncols || !oti_lapack_fits(A->nrows)){
        return OTI_LINALG_ERR_SIZE;
    }

    lu->A      = oarrss_copy(A);
    lu->p_ipiv = (int*)malloc((size_t)A->nrows * sizeof(int) + 1);

    if (lu->p_ipiv == NULL){
        return OTI_LINALG_ERR_MEMORY;
    }

    if (A->nrows > 0){
        oti_dgetrf((int)A->nrows, (int)A->nrows, lu->A.p_data, (int)A->nrows, lu->p_ipiv, &info);
    }

    return info;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void oarrss_lu_free(oarrss_lu_t* lu){

    oarrss_free(&lu->A);
    free(lu->p_ipiv);

    lu->p_ipiv = NULL;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oarrss_lu_solve(const oarrss_lu_t* lu, const oarrss_t* b, oarrss_t* x, dhelpl_t dhl){

    const oarrss_t* A = &lu->A;
    uint64_t n = A->nrows, m = b->ncols, sa = n * n, sx = n * m;
    size_t nb = (size_t)A->nbases + b->nbases;
    bases_t *p_u = NULL, *pos_a, *pos_b, nu;
    ord_t trc = (A->trc_order > b->trc_order) ? A->trc_order : b->trc_order;
    ord_t atop, act, p, s;
    ndir_t nimag, Np, i;
    coeff_t *Aexp = NULL, *X = NULL, *work = NULL;
    const coeff_t* Au;
    int status = 0, info = 0;

    if (b->nrows != n || !oti_lapack_fits(n) || !oti_lapack_fits(m)){
        return OTI_LINALG_ERR_SIZE;
    }

    for (i = 0; i < n; i++){

        if (lu->p_ipiv[i] < 1 || (uint64_t)lu->p_ipiv[i] > n){
            return OTI_LINALG_ERR_PIVOT;
        }

    }

    // Union of the sets.
    p_u = (bases_t*)malloc(2 * nb * sizeof(bases_t) + 1);

    if (p_u == NULL){
        return OTI_LINALG_ERR_MEMORY;
    }

    pos_a = p_u + nb;
    pos_b = pos_a + A->nbases;
    nu    = sshelp_union_bases(A->p_bases, A->nbases, b->p_bases, b->nbases, p_u, pos_a, pos_b);

    if (sshelp_ndir_total_checked(nu, trc, &nimag) != SSHELP_OK){
        free(p_u);
        return OTI_LINALG_ERR_SIZE;
    }

    atop = (A->act_order < trc) ? A->act_order : trc;
    act  = (atop > 0) ? trc : ((b->act_order < trc) ? b->act_order : trc);

    for (p = 1; p <= act; p++){

        if (!oti_lapack_fits(m * sshelp_ndir_order(nu, p))){
            free(p_u);
            return OTI_LINALG_ERR_SIZE;
        }

    }

    // Operands in the union layout; X starts as B and is solved in place order by order.
    X    = oarrss_linalg_alloc(1 + nimag, sx);
    work = oarrss_linalg_alloc(oarrss_linalg_max_ndir(nu, trc), sx);

    if (A->nbases == nu && A->trc_order >= trc){
        Au = A->p_data;
    } else {
        Aexp = oarrss_linalg_alloc(1 + nimag, sa);
        Au   = Aexp;
    }

    // An empty A has no buffer (Au == NULL) without any allocation failing.
    if (X == NULL || work == NULL || (Au == NULL && sa > 0)){
        status = OTI_LINALG_ERR_MEMORY;
        goto cleanup;
    }

    if (Aexp != NULL){
        oarrss_kernel_expand(A, pos_a, nu, trc, Aexp);
    }

    oarrss_kernel_expand(b, pos_b, nu, trc, X);

    if (n > 0 && m > 0){

        // Order 0: K_re X_0 = B_0 (Au's real block holds the LU factors).
        oti_dgetrs('N', (int)n, (int)m, Au, (int)n, lu->p_ipiv, X, (int)n, &info);

        for (p = 1; p <= act; p++){

            // X_p = B_p - sum_s K_s X_{p-s}; one order pair per call so only order p is written
            // (the kernel reads the order-(p-s) blocks and writes the order-p ones: disjoint).
            for (s = 1; s <= p && s <= atop; s++){

                status = oarrss_kernel_matmul_acc(Au, s, s, X, p - s, p - s, nu, trc, n, n, m,
                                                  -1.0, X, work, dhl);

                if (status != 0){
                    goto cleanup;
                }

            }

            // All order-p right-hand sides at once: an n x (m * N_p) matrix.
            Np = sshelp_ndir_order(nu, p);
            oti_dgetrs('N', (int)n, (int)(m * Np), Au, (int)n, lu->p_ipiv,
                       X + oarrss_block_index(nu, p, 0) * sx, (int)n, &info);

        }

    }

    // Store (x may alias b).
    oarrss_reserve(x, nu, n, m, trc);

    if (nu > 0){
        memcpy(x->p_bases, p_u, (size_t)nu * sizeof(bases_t));
    }

    memcpy(x->p_data, X, (size_t)((1 + nimag) * sx) * sizeof(coeff_t));

    x->nbases    = nu;
    x->trc_order = trc;
    x->act_order = act;

cleanup:

    free(p_u);
    free(X);
    free(work);
    free(Aexp);

    return status;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oarrss_solve_to(const oarrss_t* K, const oarrss_t* b, oarrss_t* x, dhelpl_t dhl){

    oarrss_lu_t lu;
    int status = oarrss_lu_factor(K, &lu);

    if (status == 0){
        status = oarrss_lu_solve(&lu, b, x, dhl);
    }

    oarrss_lu_free(&lu);

    return status;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oarrss_inv_to(const oarrss_t* A, oarrss_t* res, dhelpl_t dhl){

    oarrss_t eye;
    int status;

    if (A->nrows != A->ncols){
        return OTI_LINALG_ERR_SIZE;
    }

    eye    = oarrss_eye(A->nrows, A->trc_order);
    status = oarrss_solve_to(A, &eye, res, dhl);

    oarrss_free(&eye);

    return status;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Adds scale * trace of every imaginary block of P (orders lo..trc) to the coefficients of t.
static void oarrss_linalg_trace_acc(const coeff_t* P, uint64_t n, ord_t lo, coeff_t scale,
                                    ssotinum_t* t){

    ndir_t d, d0 = sshelp_order_offset(t->nbases, lo);
    ndir_t nimag = sshelp_ndir_total(t->nbases, t->trc_order);
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

    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oarrss_det_to(const oarrss_t* A, ssotinum_t* res, dhelpl_t dhl){

    uint64_t n = A->nrows, sa = n * n, r;
    bases_t k = A->nbases;
    ord_t trc = A->trc_order, atop = (A->act_order < trc) ? A->act_order : trc, mo;
    ndir_t nimag = 0;
    coeff_t *LU = NULL, *M = NULL, *P = NULL, *Q = NULL, *work = NULL, *tmp, det0 = 1.0;
    int *ipiv = NULL, info = 0, status = 0;
    ssotinum_t t = ssoti_init();

    if (A->nrows != A->ncols || !oti_lapack_fits(n)){
        return OTI_LINALG_ERR_SIZE;
    }

    if (sshelp_ndir_total_checked(k, trc, &nimag) != SSHELP_OK || !oti_lapack_fits(n * nimag)){
        return OTI_LINALG_ERR_SIZE;
    }

    LU   = oarrss_linalg_alloc(1, sa);
    ipiv = (int*)malloc((size_t)n * sizeof(int) + 1);

    if (LU == NULL || ipiv == NULL){
        status = OTI_LINALG_ERR_MEMORY;
        goto cleanup;
    }

    // det of the real part from its LU factors.
    memcpy(LU, A->p_data, (size_t)sa * sizeof(coeff_t));

    if (n > 0){
        oti_dgetrf((int)n, (int)n, LU, (int)n, ipiv, &info);
    }

    if (info > 0){
        status = info;
        goto cleanup;
    }

    for (r = 0; r < n; r++){

        det0 *= LU[r + r * n];

        if (ipiv[r] != (int)(r + 1)){
            det0 = -det0;
        }

    }

    if (k == 0 || atop == 0 || n == 0){

        ssoti_set_r(det0, res);
        res->trc_order = trc;
        goto cleanup;

    }

    // M = A_re^-1 (A - A_re): imaginary blocks only, all solved with one dgetrs.
    M    = oarrss_linalg_alloc(1 + nimag, sa);
    P    = oarrss_linalg_alloc(1 + nimag, sa);
    Q    = oarrss_linalg_alloc(1 + nimag, sa);
    work = oarrss_linalg_alloc(oarrss_linalg_max_ndir(k, trc), sa);

    if (M == NULL || P == NULL || Q == NULL || work == NULL){
        status = OTI_LINALG_ERR_MEMORY;
        goto cleanup;
    }

    memset(M, 0, (size_t)sa * sizeof(coeff_t));
    memcpy(M + sa, A->p_data + sa, (size_t)(nimag * sa) * sizeof(coeff_t));
    oti_dgetrs('N', (int)n, (int)(n * nimag), LU, (int)n, ipiv, M + sa, (int)n, &info);

    // t = sum_m (-1)^(m+1) tr(M^m) / m. P holds M^(m-1), with orders m-1 .. trc.
    t = ssoti_create_empty(A->p_bases, k, trc);
    memcpy(P, M, (size_t)((1 + nimag) * sa) * sizeof(coeff_t));
    oarrss_linalg_trace_acc(P, n, 1, 1.0, &t);

    for (mo = 2; mo <= trc; mo++){

        memset(Q, 0, (size_t)((1 + nimag) * sa) * sizeof(coeff_t));
        status = oarrss_kernel_matmul_acc(P, mo - 1, trc, M, 1, atop, k, trc, n, n, n, 1.0, Q,
                                          work, dhl);

        if (status != 0){
            goto cleanup;
        }

        oarrss_linalg_trace_acc(Q, n, mo, ((mo % 2) ? 1.0 : -1.0) / mo, &t);

        tmp = P;
        P   = Q;
        Q   = tmp;

    }

    t.act_order = trc;

    // det = det0 * exp(t).
    ssoti_exp_to(&t, res, dhl);
    ssoti_mul_or_to(res, det0, res, dhl);

cleanup:

    ssoti_free(&t);
    free(LU);
    free(ipiv);
    free(M);
    free(P);
    free(Q);
    free(work);

    return status;

}
// -------------------------------------------------------------------------------------------------------
