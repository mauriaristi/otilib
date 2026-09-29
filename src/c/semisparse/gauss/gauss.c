// Semi-sparse Gauss-point types, SoA batched over integration points (PLAN-semisparse-sparse-
// leveling.md, Phase 4). Declarations and layout in include/oti/semisparse/gauss/gauss.h.
//
// A feoarrss_t embeds one oarrss_t of shape nip x (nrows * ncols). Everything elementwise is the
// oarrss_t operation on it; this file adds point and entry access, broadcasts, per-point matrix
// products, dot products, integration, det and inv. Reuses, from the same unity build, the SoA
// internals oarrss_shape_size, oarrss_kernel_expand and the product-index sources of
// src/c/semisparse/soa/kernels.c. Every scratch buffer here is allocated and freed within the call.


// *******************************************************************************************************
// Allocates n coefficients (at least one byte), exiting when out of memory.
static coeff_t* fe_alloc(size_t n, int zero){

    coeff_t* p;

    if (n > SIZE_MAX / sizeof(coeff_t)){
        ssoti_out_of_memory();
    }

    p = zero ? (coeff_t*)calloc(n + 1, sizeof(coeff_t)) : (coeff_t*)malloc(n * sizeof(coeff_t) + 1);

    if (p == NULL){
        ssoti_out_of_memory();
    }

    return p;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Allocates n bases (at least one byte), exiting when out of memory.
static bases_t* fe_alloc_bases(size_t n){

    bases_t* p = (bases_t*)malloc(n * sizeof(bases_t) + 1);

    if (p == NULL){
        ssoti_out_of_memory();
    }

    return p;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Number of direction blocks (real one included) of an array.
static inline uint64_t fe_nblocks(const oarrss_t* a){

    return 1 + (uint64_t)sshelp_ndir_total(a->nbases, a->trc_order);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Exits on an index or shape error.
static void fe_fail(const char* what){

    printf("ERROR: %s in semi-sparse Gauss-point operation. Exiting...\n", what);
    exit(OTI_BadIndx);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Positions of the sorted set `sub` inside the sorted superset `sup` (every label must be present).
static void fe_positions(const bases_t* sub, bases_t ksub, const bases_t* sup, bases_t ksup,
                         bases_t* pos){

    bases_t i, u = 0;

    for (i = 0; i < ksub; i++){

        while (u < ksup && sup[u] < sub[i]){
            u++;
        }

        if (u == ksup || sup[u] != sub[i]){
            fe_fail("Active set not contained in the destination set");
        }

        pos[i] = u;

    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Coefficients of `src` in the layout of the superset (bases, k) at order trc >= src's order.
// Returns src->p_data when the layouts already match (*tmp = NULL); otherwise a new buffer, also
// stored in *tmp for the caller to free.
static const coeff_t* fe_in_layout(const oarrss_t* src, const bases_t* bases, bases_t k, ord_t trc,
                                   coeff_t** tmp){

    bases_t* pos;
    uint64_t nb = 1 + (uint64_t)sshelp_ndir_total(k, trc);

    *tmp = NULL;

    if (src->nbases == k && src->trc_order == trc){
        return src->p_data;
    }

    pos  = fe_alloc_bases(src->nbases);
    *tmp = fe_alloc((size_t)(nb * src->size), 0);

    fe_positions(src->p_bases, src->nbases, bases, k, pos);
    oarrss_kernel_expand(src, pos, k, trc, *tmp);

    free(pos);

    return *tmp;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// res (nip x n) = columns cols[0..n) of a (nip x *), same active set and order. res != a.
static void fe_gather_cols(const oarrss_t* a, const uint64_t* cols, uint64_t n, oarrss_t* res){

    uint64_t nip = a->nrows, nb = fe_nblocks(a), d, c;
    bases_t k = a->nbases;
    ord_t trc = a->trc_order, act = a->act_order;

    oarrss_reserve(res, k, nip, n, trc);

    if (k > 0){
        memcpy(res->p_bases, a->p_bases, (size_t)k * sizeof(bases_t));
    }

    res->nbases    = k;
    res->trc_order = trc;
    res->act_order = act;

    for (d = 0; d < nb; d++){

        for (c = 0; c < n; c++){
            memcpy(res->p_data + d * res->size + c * nip, a->p_data + d * a->size + cols[c] * nip,
                (size_t)nip * sizeof(coeff_t));
        }

    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Writes column src_cols[c] (identity when NULL) of src (nip x *) into column dst_cols[c] of dst,
// for c < n, growing dst's set and order to include src's. src != dst.
static void fe_scatter_cols(const oarrss_t* src, const uint64_t* src_cols, const uint64_t* dst_cols,
                            uint64_t n, oarrss_t* dst){

    uint64_t nip = dst->nrows, nb, d, c;
    const coeff_t* S;
    coeff_t* tmp;
    ord_t act;

    if (src->nrows != nip){
        fe_fail("Number of integration points mismatch");
    }

    if (src->trc_order > dst->trc_order){
        oarrss_reserve(dst, dst->nbases, dst->nrows, dst->ncols, src->trc_order);
    }

    oarrss_add_bases(src->p_bases, src->nbases, dst);

    nb = fe_nblocks(dst);
    S  = fe_in_layout(src, dst->p_bases, dst->nbases, dst->trc_order, &tmp);

    for (d = 0; d < nb; d++){

        for (c = 0; c < n; c++){

            uint64_t cs = (src_cols == NULL) ? c : src_cols[c];

            memcpy(dst->p_data + d * dst->size + dst_cols[c] * nip, S + d * src->size + cs * nip,
                (size_t)nip * sizeof(coeff_t));

        }

    }

    act = (src->act_order < src->trc_order) ? src->act_order : src->trc_order;

    if (act > dst->act_order){
        dst->act_order = act;
    }

    free(tmp);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Replaces *res by *tmp (moving its buffers) and resets *tmp.
static void fe_move(feoarrss_t* tmp, feoarrss_t* res){

    feoarrss_free(res);
    *res = *tmp;
    *tmp = feoarrss_init();

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// ---------------------------------------     MEMORY     ------------------------------------------------
// -------------------------------------------------------------------------------------------------------

// *******************************************************************************************************
feoarrss_t feoarrss_init(void){

    feoarrss_t fe;

    fe.arr   = oarrss_init();
    fe.nrows = 0;
    fe.ncols = 0;
    fe.nip   = 0;

    return fe;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
feoarrss_t feoarrss_zeros(const bases_t* bases, bases_t k, uint64_t nrows, uint64_t ncols,
                          uint64_t nip, ord_t trc_order){

    feoarrss_t fe = feoarrss_init();

    fe.arr   = oarrss_zeros(bases, k, nip, oarrss_shape_size(nrows, ncols), trc_order);
    fe.nrows = nrows;
    fe.ncols = ncols;
    fe.nip   = nip;

    return fe;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void feoarrss_free(feoarrss_t* fe){

    oarrss_free(&fe->arr);
    *fe = feoarrss_init();

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void feoarrss_copy_to(const feoarrss_t* fe, feoarrss_t* res){

    if (fe == res){
        return;
    }

    oarrss_copy_to(&fe->arr, &res->arr);
    feoarrss_set_shape(fe->nrows, fe->ncols, fe->nip, res);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void feoarrss_grow(const bases_t* bases, bases_t k, ord_t trc_order, feoarrss_t* fe){

    if (trc_order > fe->arr.trc_order){
        oarrss_reserve(&fe->arr, fe->arr.nbases, fe->arr.nrows, fe->arr.ncols, trc_order);
    }

    oarrss_add_bases(bases, k, &fe->arr);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void feoarrss_set_shape(uint64_t nrows, uint64_t ncols, uint64_t nip, feoarrss_t* fe){

    fe->nrows = nrows;
    fe->ncols = ncols;
    fe->nip   = nip;

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// ---------------------------------------     ACCESS     ------------------------------------------------
// -------------------------------------------------------------------------------------------------------

// *******************************************************************************************************
void feoarrss_get_ip_to(uint64_t ip, const feoarrss_t* fe, oarrss_t* res){

    const oarrss_t* a = &fe->arr;
    uint64_t nip = fe->nip, m = a->ncols, nb = fe_nblocks(a), d, e;
    bases_t k = a->nbases;

    if (ip >= nip){
        fe_fail("Integration point index out of range");
    }

    oarrss_reserve(res, k, fe->nrows, fe->ncols, a->trc_order);

    if (k > 0){
        memcpy(res->p_bases, a->p_bases, (size_t)k * sizeof(bases_t));
    }

    res->nbases    = k;
    res->trc_order = a->trc_order;
    res->act_order = a->act_order;

    for (d = 0; d < nb; d++){

        const coeff_t* S = a->p_data + d * a->size + ip;
        coeff_t* D = res->p_data + d * m;

        for (e = 0; e < m; e++){
            D[e] = S[e * nip];
        }

    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void feoarrss_set_ip(const oarrss_t* val, uint64_t ip, feoarrss_t* fe){

    oarrss_t* a = &fe->arr;
    uint64_t nip = fe->nip, m, nb, d, e;
    const coeff_t* S;
    coeff_t* tmp;
    ord_t act;

    if (ip >= nip){
        fe_fail("Integration point index out of range");
    }

    if (val->nrows != fe->nrows || val->ncols != fe->ncols){
        fe_fail("Shape mismatch");
    }

    feoarrss_grow(val->p_bases, val->nbases, val->trc_order, fe);

    m  = a->ncols;
    nb = fe_nblocks(a);
    S  = fe_in_layout(val, a->p_bases, a->nbases, a->trc_order, &tmp);

    for (d = 0; d < nb; d++){

        coeff_t* D = a->p_data + d * a->size + ip;
        const coeff_t* Sd = S + d * m;

        for (e = 0; e < m; e++){
            D[e * nip] = Sd[e];
        }

    }

    act = (val->act_order < val->trc_order) ? val->act_order : val->trc_order;

    if (act > a->act_order){
        a->act_order = act;
    }

    free(tmp);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void feoarrss_get_slice_to(const feoarrss_t* fe, uint64_t i0, uint64_t ni, int64_t istep,
                           uint64_t j0, uint64_t nj, int64_t jstep, feoarrss_t* res){

    uint64_t n = ni * nj, ii, jj;
    uint64_t* cols;

    if (res == fe){
        fe_fail("Aliased slice destination");
    }

    cols = (uint64_t*)malloc((size_t)n * sizeof(uint64_t) + 1);

    if (cols == NULL){
        ssoti_out_of_memory();
    }

    for (jj = 0; jj < nj; jj++){

        for (ii = 0; ii < ni; ii++){

            uint64_t i = (uint64_t)((int64_t)i0 + (int64_t)ii * istep);
            uint64_t j = (uint64_t)((int64_t)j0 + (int64_t)jj * jstep);

            if (i >= fe->nrows || j >= fe->ncols){
                free(cols);
                fe_fail("Index out of range");
            }

            cols[ii + jj * ni] = i + j * fe->nrows;

        }

    }

    fe_gather_cols(&fe->arr, cols, n, &res->arr);
    feoarrss_set_shape(ni, nj, fe->nip, res);

    free(cols);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void feoarrss_set_slice(const feoarrss_t* val, uint64_t i0, uint64_t ni, int64_t istep, uint64_t j0,
                        uint64_t nj, int64_t jstep, feoarrss_t* fe){

    uint64_t n = ni * nj, ii, jj, c;
    uint64_t *dst_cols, *src_cols = NULL;
    int bcast = (val->nrows == 1 && val->ncols == 1 && n != 1);

    if (val == fe){
        fe_fail("Aliased slice source");
    }

    if (val->nip != fe->nip){
        fe_fail("Number of integration points mismatch");
    }

    if (!bcast && (val->nrows != ni || val->ncols != nj)){
        fe_fail("Shape mismatch");
    }

    dst_cols = (uint64_t*)malloc((size_t)n * sizeof(uint64_t) + 1);

    if (dst_cols == NULL){
        ssoti_out_of_memory();
    }

    for (jj = 0; jj < nj; jj++){

        for (ii = 0; ii < ni; ii++){

            uint64_t i = (uint64_t)((int64_t)i0 + (int64_t)ii * istep);
            uint64_t j = (uint64_t)((int64_t)j0 + (int64_t)jj * jstep);

            if (i >= fe->nrows || j >= fe->ncols){
                free(dst_cols);
                fe_fail("Index out of range");
            }

            dst_cols[ii + jj * ni] = i + j * fe->nrows;

        }

    }

    if (bcast){

        src_cols = (uint64_t*)calloc((size_t)n + 1, sizeof(uint64_t));

        if (src_cols == NULL){
            ssoti_out_of_memory();
        }

        for (c = 0; c < n; c++){
            src_cols[c] = 0;
        }

    }

    fe_scatter_cols(&val->arr, src_cols, dst_cols, n, &fe->arr);

    free(dst_cols);
    free(src_cols);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void feoarrss_set_ijk_o(const ssotinum_t* num, uint64_t i, uint64_t j, uint64_t ip,
                        feoarrss_t* fe){

    if (i >= fe->nrows || j >= fe->ncols || ip >= fe->nip){
        fe_fail("Index out of range");
    }

    feoarrss_grow(num->p_bases, num->nbases, num->trc_order, fe);
    oarrss_set_item(num, ip, i + j * fe->nrows, &fe->arr);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void feoarrss_set_ijk_r(coeff_t val, uint64_t i, uint64_t j, uint64_t ip, feoarrss_t* fe){

    if (i >= fe->nrows || j >= fe->ncols || ip >= fe->nip){
        fe_fail("Index out of range");
    }

    oarrss_set_item_r(val, ip, i + j * fe->nrows, &fe->arr);

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// ---------------------------------------     BROADCASTS     --------------------------------------------
// -------------------------------------------------------------------------------------------------------

// *******************************************************************************************************
void feoarrss_from_oarrss_to(const oarrss_t* arr, uint64_t nip, feoarrss_t* res){

    uint64_t nb = fe_nblocks(arr), m = arr->size, d, e, t;
    bases_t k = arr->nbases;

    oarrss_reserve(&res->arr, k, nip, m, arr->trc_order);

    if (k > 0){
        memcpy(res->arr.p_bases, arr->p_bases, (size_t)k * sizeof(bases_t));
    }

    res->arr.nbases    = k;
    res->arr.trc_order = arr->trc_order;
    res->arr.act_order = arr->act_order;

    for (d = 0; d < nb; d++){

        const coeff_t* S = arr->p_data + d * m;
        coeff_t* D = res->arr.p_data + d * res->arr.size;

        for (e = 0; e < m; e++){

            for (t = 0; t < nip; t++){
                D[e * nip + t] = S[e];
            }

        }

    }

    feoarrss_set_shape(arr->nrows, arr->ncols, nip, res);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void feoarrss_bcast_to(const feoarrss_t* num, uint64_t nrows, uint64_t ncols, feoarrss_t* res){

    uint64_t n = oarrss_shape_size(nrows, ncols);
    uint64_t* cols;

    if (num == res){
        fe_fail("Aliased broadcast destination");
    }

    if (num->nrows != 1 || num->ncols != 1){
        fe_fail("Broadcast of a non-scalar");
    }

    cols = (uint64_t*)calloc((size_t)n + 1, sizeof(uint64_t));

    if (cols == NULL){
        ssoti_out_of_memory();
    }

    fe_gather_cols(&num->arr, cols, n, &res->arr);
    feoarrss_set_shape(nrows, ncols, num->nip, res);

    free(cols);

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// ---------------------------------------     LINEAR ALGEBRA     ----------------------------------------
// -------------------------------------------------------------------------------------------------------

// *******************************************************************************************************
void feoarrss_transpose_to(const feoarrss_t* fe, feoarrss_t* res){

    uint64_t n = fe->nrows, m = fe->ncols, r, c;
    uint64_t* cols;
    feoarrss_t tmp = feoarrss_init();

    cols = (uint64_t*)malloc((size_t)(n * m) * sizeof(uint64_t) + 1);

    if (cols == NULL){
        ssoti_out_of_memory();
    }

    // Result entry (r, c), r < m, c < n, is entry (c, r) of fe.
    for (c = 0; c < n; c++){

        for (r = 0; r < m; r++){
            cols[r + c * m] = c + r * n;
        }

    }

    fe_gather_cols(&fe->arr, cols, n * m, &tmp.arr);
    feoarrss_set_shape(m, n, fe->nip, &tmp);
    fe_move(&tmp, res);

    free(cols);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int feoarrss_matmul_FF_to(const feoarrss_t* a, const feoarrss_t* b, feoarrss_t* res, dhelpl_t dhl){

    uint64_t n = a->nrows, q = a->ncols, m = b->ncols, nip = a->nip;
    uint64_t sa = a->arr.size, sb = b->arr.size, sr, c, s, r, t;
    bases_t ka = a->arr.nbases, kb = b->arr.nbases, nu;
    bases_t *p_u, *pos_a, *pos_b;
    ord_t trc, atop, btop, p, pq;
    ndir_t nimag, i, j, Np, Nq;
    coeff_t *R, *tmp_a, *tmp_b;
    const coeff_t *A, *B;
    feoarrss_t out = feoarrss_init();
    oarrss_pairsrc_t src;

    if (b->nrows != q || b->nip != nip){
        return OTI_LINALG_ERR_SIZE;
    }

    sr  = oarrss_shape_size(nip, oarrss_shape_size(n, m));
    trc = (a->arr.trc_order > b->arr.trc_order) ? a->arr.trc_order : b->arr.trc_order;

    p_u   = fe_alloc_bases((size_t)ka + kb);
    pos_a = fe_alloc_bases(ka);
    pos_b = fe_alloc_bases(kb);
    nu    = sshelp_union_bases(a->arr.p_bases, ka, b->arr.p_bases, kb, p_u, pos_a, pos_b);
    nimag = ssoti_nimag_checked(nu, trc);

    A = fe_in_layout(&a->arr, p_u, nu, trc, &tmp_a);
    B = fe_in_layout(&b->arr, p_u, nu, trc, &tmp_b);
    R = fe_alloc((size_t)((1 + (uint64_t)nimag) * sr), 1);

    atop = (a->arr.act_order < trc) ? a->arr.act_order : trc;
    btop = (b->arr.act_order < trc) ? b->arr.act_order : trc;

    for (p = 0; p <= atop; p++){

        uint64_t bp = oarrss_block_index(nu, p, 0);

        Np = sshelp_ndir_order(nu, p);

        // Block offsets once per order (block of direction i of order p: bp + i).
        for (pq = 0; pq <= btop && p + pq <= trc; pq++){

            uint64_t bq = oarrss_block_index(nu, pq, 0), bpq = oarrss_block_index(nu, p + pq, 0);

            Nq  = sshelp_ndir_order(nu, pq);
            src = oarrss_pairsrc_init(nu, p, pq, dhl);

            for (i = 0; i < Np; i++){

                const coeff_t* Ai = A + (bp + i) * sa;

                if (oarrss_all_zero(Ai, sa)){
                    continue;
                }

                for (j = 0; j < Nq; j++){

                    const coeff_t* Bj = B + (bq + j) * sb;
                    coeff_t* Rd = R + (bpq + oarrss_pairsrc_idx(&src, i, j)) * sr;

                    for (c = 0; c < m; c++){

                        for (s = 0; s < q; s++){

                            const coeff_t* Bc = Bj + (s + c * q) * nip;

                            for (r = 0; r < n; r++){

                                const coeff_t* Ac = Ai + (r + s * n) * nip;
                                coeff_t* Rc = Rd + (r + c * n) * nip;

                                for (t = 0; t < nip; t++){
                                    Rc[t] += Ac[t] * Bc[t];
                                }

                            }

                        }

                    }

                }

            }

            oarrss_pairsrc_free(&src);

        }

    }

    out.arr = oarrss_init();
    oarrss_reserve(&out.arr, nu, nip, oarrss_shape_size(n, m), trc);

    if (nu > 0){
        memcpy(out.arr.p_bases, p_u, (size_t)nu * sizeof(bases_t));
    }

    memcpy(out.arr.p_data, R, (size_t)((1 + (uint64_t)nimag) * sr) * sizeof(coeff_t));
    out.arr.nbases    = nu;
    out.arr.trc_order = trc;
    out.arr.act_order = (atop + btop < trc) ? (ord_t)(atop + btop) : trc;
    feoarrss_set_shape(n, m, nip, &out);

    fe_move(&out, res);

    free(R);
    free(tmp_a);
    free(tmp_b);
    free(p_u);
    free(pos_a);
    free(pos_b);

    return 0;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int feoarrss_matmul_FO_to(const feoarrss_t* a, const oarrss_t* b, feoarrss_t* res, dhelpl_t dhl){

    uint64_t n = a->nrows, q = a->ncols, m = b->ncols, nip = a->nip;
    oarrss_t av;
    feoarrss_t out = feoarrss_init();
    int status;

    if (b->nrows != q){
        return OTI_LINALG_ERR_SIZE;
    }

    // a.arr (nip x n*q, column-major over (ip, r, s)) is the same memory as an (nip*n) x q matrix.
    av       = a->arr;
    av.nrows = oarrss_shape_size(nip, n);
    av.ncols = q;
    av.flag  = 0;

    status = oarrss_matmul_OO_to(&av, b, &out.arr, dhl);

    if (status != 0){
        feoarrss_free(&out);
        return status;
    }

    // The (nip*n) x m product is the nip x (n*m) layout of the per-point results.
    out.arr.nrows = nip;
    out.arr.ncols = oarrss_shape_size(n, m);
    feoarrss_set_shape(n, m, nip, &out);

    fe_move(&out, res);

    return 0;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int feoarrss_matmul_OF_to(const oarrss_t* a, const feoarrss_t* b, feoarrss_t* res, dhelpl_t dhl){

    feoarrss_t bt = feoarrss_init(), rt = feoarrss_init();
    oarrss_t at = oarrss_init();
    int status;

    if (a->ncols != b->nrows){
        return OTI_LINALG_ERR_SIZE;
    }

    // (a b_ip)^T = b_ip^T a^T.
    feoarrss_transpose_to(b, &bt);
    oarrss_transpose_to(a, &at, dhl);

    status = feoarrss_matmul_FO_to(&bt, &at, &rt, dhl);

    if (status == 0){
        feoarrss_transpose_to(&rt, res);
    }

    feoarrss_free(&bt);
    feoarrss_free(&rt);
    oarrss_free(&at);

    return status;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int feoarrss_dot_product_FO_to(const feoarrss_t* a, const oarrss_t* b, feoarrss_t* res,
                               dhelpl_t dhl){

    uint64_t N = a->arr.ncols;
    oarrss_t bv;
    feoarrss_t out = feoarrss_init();
    int status;

    if (b->size != N){
        return OTI_LINALG_ERR_SIZE;
    }

    // b's column-major entries as an N x 1 vector.
    bv       = *b;
    bv.nrows = N;
    bv.ncols = 1;
    bv.flag  = 0;

    status = oarrss_matmul_OO_to(&a->arr, &bv, &out.arr, dhl);

    if (status != 0){
        feoarrss_free(&out);
        return status;
    }

    feoarrss_set_shape(1, 1, a->nip, &out);
    fe_move(&out, res);

    return 0;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int feoarrss_dot_product_FF_to(const feoarrss_t* a, const feoarrss_t* b, feoarrss_t* res,
                               dhelpl_t dhl){

    uint64_t N = a->arr.ncols, nip = a->nip, nb, d, e, t;
    feoarrss_t prod = feoarrss_init(), out;

    if (b->arr.ncols != N || b->nip != nip){
        return OTI_LINALG_ERR_SIZE;
    }

    oarrss_mul_OO_to(&a->arr, &b->arr, &prod.arr, dhl);

    // Sum of the N columns of the product.
    nb  = fe_nblocks(&prod.arr);
    out = feoarrss_zeros(prod.arr.p_bases, prod.arr.nbases, 1, 1, nip, prod.arr.trc_order);
    out.arr.act_order = prod.arr.act_order;

    for (d = 0; d < nb; d++){

        const coeff_t* S = prod.arr.p_data + d * prod.arr.size;
        coeff_t* D = out.arr.p_data + d * nip;

        for (e = 0; e < N; e++){

            for (t = 0; t < nip; t++){
                D[t] += S[e * nip + t];
            }

        }

    }

    fe_move(&out, res);
    feoarrss_free(&prod);

    return 0;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int feoarrss_integrate_to(const feoarrss_t* val, const feoarrss_t* w, oarrss_t* res, dhelpl_t dhl){

    oarrss_t wv;
    int status;

    if (w->nrows != 1 || w->ncols != 1 || w->nip != val->nip){
        return OTI_LINALG_ERR_SIZE;
    }

    // w (nip x 1) is the same memory as the 1 x nip row w^T.
    wv       = w->arr;
    wv.nrows = 1;
    wv.ncols = w->nip;
    wv.flag  = 0;

    status = oarrss_matmul_OO_to(&wv, &val->arr, res, dhl);

    if (status != 0){
        return status;
    }

    // The 1 x (nrows*ncols) row is the column-major nrows x ncols matrix.
    res->nrows = val->nrows;
    res->ncols = val->ncols;

    return 0;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// out (nip x 1) = entry (i, j) of fe at every point.
static void fe_entry(const feoarrss_t* fe, uint64_t i, uint64_t j, oarrss_t* out){

    uint64_t col = i + j * fe->nrows;

    fe_gather_cols(&fe->arr, &col, 1, out);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// out = x * y - u * v (entry vectors over the points).
static void fe_cross2(const oarrss_t* x, const oarrss_t* y, const oarrss_t* u, const oarrss_t* v,
                      oarrss_t* out, dhelpl_t dhl){

    oarrss_t t1 = oarrss_init(), t2 = oarrss_init();

    oarrss_mul_OO_to(x, y, &t1, dhl);
    oarrss_mul_OO_to(u, v, &t2, dhl);
    oarrss_sub_OO_to(&t1, &t2, out, dhl);

    oarrss_free(&t1);
    oarrss_free(&t2);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Closed-form det (and, with inv != NULL, inverse) for n <= 3, batched over the points.
static void fe_closed_form(const feoarrss_t* fe, feoarrss_t* det, feoarrss_t* inv, dhelpl_t dhl){

    uint64_t n = fe->nrows, r, c, nip = fe->nip;
    oarrss_t E[9], C[9], d = oarrss_init(), rd = oarrss_init(), t = oarrss_init();

    for (r = 0; r < 9; r++){
        E[r] = oarrss_init();
        C[r] = oarrss_init();
    }

    for (c = 0; c < n; c++){

        for (r = 0; r < n; r++){
            fe_entry(fe, r, c, &E[r + 3 * c]);
        }

    }

    // Cofactors C[r + 3c]; with them det = sum_c a_0c C_0c and inv_rc = C_cr / det.
    if (n == 1){

        oarrss_copy_to(&E[0], &d);
        C[0] = oarrss_zeros(NULL, 0, nip, 1, 0);

        for (r = 0; r < nip; r++){
            C[0].p_data[r] = 1.0;
        }

    } else if (n == 2){

        oarrss_copy_to(&E[1 + 3], &C[0]);        // C00 =  a11
        oarrss_neg_to(&E[1], &C[3], dhl);        // C01 = -a10
        oarrss_neg_to(&E[3], &C[1], dhl);        // C10 = -a01
        oarrss_copy_to(&E[0], &C[1 + 3]);        // C11 =  a00
        fe_cross2(&E[0], &E[1 + 3], &E[3], &E[1], &d, dhl);

    } else {

        for (r = 0; r < 3; r++){

            uint64_t r1 = (r + 1) % 3, r2 = (r + 2) % 3;

            for (c = 0; c < 3; c++){

                uint64_t c1 = (c + 1) % 3, c2 = (c + 2) % 3;

                fe_cross2(&E[r1 + 3 * c1], &E[r2 + 3 * c2], &E[r1 + 3 * c2], &E[r2 + 3 * c1],
                          &C[r + 3 * c], dhl);

            }

        }

        oarrss_mul_OO_to(&E[0], &C[0], &d, dhl);

        for (c = 1; c < 3; c++){
            oarrss_mul_OO_to(&E[3 * c], &C[3 * c], &t, dhl);
            oarrss_sum_OO_to(&d, &t, &d, dhl);
        }

    }

    if (det != NULL){

        feoarrss_t out = feoarrss_init();

        oarrss_copy_to(&d, &out.arr);
        feoarrss_set_shape(1, 1, nip, &out);
        fe_move(&out, det);

    }

    if (inv != NULL){

        feoarrss_t out = feoarrss_zeros(NULL, 0, n, n, nip, 0);

        oarrss_div_rO_to(1.0, &d, &rd, dhl);

        for (c = 0; c < n; c++){

            for (r = 0; r < n; r++){

                uint64_t col = r + c * n;

                oarrss_mul_OO_to(&C[c + 3 * r], &rd, &t, dhl);
                fe_scatter_cols(&t, NULL, &col, 1, &out.arr);

            }

        }

        fe_move(&out, inv);

    }

    for (r = 0; r < 9; r++){
        oarrss_free(&E[r]);
        oarrss_free(&C[r]);
    }

    oarrss_free(&d);
    oarrss_free(&rd);
    oarrss_free(&t);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int feoarrss_det_to(const feoarrss_t* fe, feoarrss_t* res, dhelpl_t dhl){

    uint64_t n = fe->nrows, ip;
    feoarrss_t out;
    oarrss_t A = oarrss_init(), s = oarrss_init();
    ssotinum_t dnum = ssoti_init();
    int status = 0;

    if (fe->ncols != n){
        return OTI_LINALG_ERR_SIZE;
    }

    if (n >= 1 && n <= 3){
        fe_closed_form(fe, res, NULL, dhl);
        return 0;
    }

    out = feoarrss_zeros(NULL, 0, 1, 1, fe->nip, 0);

    for (ip = 0; ip < fe->nip && status == 0; ip++){

        feoarrss_get_ip_to(ip, fe, &A);
        status = oarrss_det_to(&A, &dnum, dhl);

        if (status == 0){

            oarrss_free(&s);
            s = oarrss_zeros(NULL, 0, 1, 1, dnum.trc_order);
            oarrss_set_item(&dnum, 0, 0, &s);
            feoarrss_set_ip(&s, ip, &out);

        }

    }

    if (status == 0){
        fe_move(&out, res);
    }

    feoarrss_free(&out);
    oarrss_free(&A);
    oarrss_free(&s);
    ssoti_free(&dnum);

    return status;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int feoarrss_inv_to(const feoarrss_t* fe, feoarrss_t* res, dhelpl_t dhl){

    uint64_t n = fe->nrows, ip;
    feoarrss_t out;
    oarrss_t A = oarrss_init(), Ai = oarrss_init();
    int status = 0;

    if (fe->ncols != n){
        return OTI_LINALG_ERR_SIZE;
    }

    if (n >= 1 && n <= 3){
        fe_closed_form(fe, NULL, res, dhl);
        return 0;
    }

    out = feoarrss_zeros(NULL, 0, n, n, fe->nip, 0);

    for (ip = 0; ip < fe->nip && status == 0; ip++){

        feoarrss_get_ip_to(ip, fe, &A);
        status = oarrss_inv_to(&A, &Ai, dhl);

        if (status == 0){
            feoarrss_set_ip(&Ai, ip, &out);
        }

    }

    if (status == 0){
        fe_move(&out, res);
    }

    feoarrss_free(&out);
    oarrss_free(&A);
    oarrss_free(&Ai);

    return status;

}
// -------------------------------------------------------------------------------------------------------
