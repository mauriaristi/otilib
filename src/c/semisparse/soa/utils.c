// Semi-sparse SoA arrays: order and derivative plumbing, trunc_dot / trunc_sub / dot_product,
// rom_eval, interp1d, moving_average, inv_block (PLAN-semisparse-sparse-leveling.md, Phase 2).
// Declarations in include/oti/semisparse/soa/utils.h. Unity-built after soa/kernels.c, whose
// product-index source (oarrss_pairsrc_*) it reuses. Temporaries are malloc'd and freed per call,
// so no result-sized buffer outlives a call (plan Phase 0).


// -------------------------------------------------------------------------------------------------------
// ---------------------------------------     HELPERS     -----------------------------------------------
// -------------------------------------------------------------------------------------------------------

// *******************************************************************************************************
// Makes res a zero nrows x ncols array over the given bases at truncation order trc (act_order 0).
static void oarrss_util_setup(oarrss_t* res, const bases_t* bases, bases_t k, uint64_t nrows,
                              uint64_t ncols, ord_t trc){

    uint64_t size = nrows * ncols;
    ndir_t nimag = ssoti_nimag_checked(k, trc);

    if (ncols != 0 && nrows > UINT64_MAX / ncols){
        ssoti_out_of_memory();
    }

    oarrss_reserve(res, k, nrows, ncols, trc);

    if (k > 0){
        memcpy(res->p_bases, bases, (size_t)k * sizeof(bases_t));
    }

    // The order offsets depend only on (k, p), so a lower truncation order keeps a valid layout.
    if (size > 0){
        memset(res->p_data, 0, (size_t)(1 + nimag) * size * sizeof(coeff_t));
    }

    res->nbases    = k;
    res->trc_order = trc;
    res->act_order = 0;
    res->nrows     = nrows;
    res->ncols     = ncols;
    res->size      = size;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Tells whether res shares its buffer with arr (then results go through a temporary).
static int oarrss_util_alias(const oarrss_t* res, const oarrss_t* arr){

    return (res == arr) || (res->p_data != NULL && res->p_data == arr->p_data);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Tells whether n reals are all zero.
static int oarrss_util_zero(const coeff_t* x, uint64_t n){

    uint64_t e;

    for (e = 0; e < n; e++){

        if (x[e] != 0.0){
            return 0;
        }

    }

    return 1;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Order-p blocks of arr in the layout of a union set of nu bases (pos from sshelp_union_bases()), or
// NULL when they are all zero. A pointer into arr when arr's set is the union; otherwise a buffer
// returned through *owned (caller frees).
static const coeff_t* oarrss_util_order_view(const oarrss_t* arr, ord_t p, const bases_t* pos,
                                             bases_t nu, coeff_t** owned){

    ndir_t Nu;
    coeff_t* buf;

    *owned = NULL;

    if (p == 0){
        return arr->p_data;
    }

    if (p > arr->act_order || p > arr->trc_order || arr->nbases == 0){
        return NULL;
    }

    if (arr->nbases == nu){
        return arr->p_data + oarrss_block_index(nu, p, 0) * arr->size;
    }

    Nu  = sshelp_ndir_order(nu, p);
    buf = (coeff_t*)calloc((size_t)Nu * arr->size + 1, sizeof(coeff_t));

    if (buf == NULL){
        ssoti_out_of_memory();
    }

    ssutil_expand_order_acc(arr->p_data + oarrss_block_index(arr->nbases, p, 0) * arr->size,
                            arr->nbases, pos, nu, p, arr->size, 1.0, buf);

    *owned = buf;

    return buf;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Union of two arrays' active sets: one malloc'd buffer holding the union and both position maps.
// Returns the buffer (caller frees); *nu, *pos_a and *pos_b point into it.
static bases_t* oarrss_util_union(const oarrss_t* A, const oarrss_t* B, bases_t* nu, bases_t** pos_a,
                                  bases_t** pos_b){

    size_t nb = (size_t)A->nbases + B->nbases + 1;
    bases_t* buf = (bases_t*)malloc(3 * nb * sizeof(bases_t));

    if (buf == NULL){
        ssoti_out_of_memory();
    }

    *pos_a = buf + nb;
    *pos_b = *pos_a + nb;
    *nu    = sshelp_union_bases(A->p_bases, A->nbases, B->p_bases, B->nbases, buf, *pos_a, *pos_b);

    return buf;

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// ---------------------------------------     EXTRACTION     --------------------------------------------
// -------------------------------------------------------------------------------------------------------

// *******************************************************************************************************
// Shared body of oarrss_extract_im_to() and oarrss_extract_deriv_to().
static void oarrss_extract_common(imdir_t idx, ord_t order, const oarrss_t* arr, int deriv,
                                  oarrss_t* res){

    bases_t k = arr->nbases, gl[256], r[256], d[256];
    uint64_t m = arr->size, e;
    ord_t trc_r, act_r, s, i;
    oarrss_t tmp = oarrss_init();
    oarrss_t* out;
    int alias = oarrss_util_alias(res, arr);
    sshelp_rank_tab_t tab;

    if (order == 0){

        oarrss_copy_to(arr, res);
        return;

    }

    out = alias ? &tmp : res;

    // As arrso_extract_im(): a direction above act_order gives a real zero.
    if (order > arr->act_order || order > arr->trc_order){

        oarrss_util_setup(out, NULL, 0, arr->nrows, arr->ncols, 0);

    } else {

        trc_r = (ord_t)(arr->trc_order - order);
        act_r = (ord_t)(arr->act_order - order);

        oarrss_util_setup(out, arr->p_bases, k, arr->nrows, arr->ncols, trc_r);

        if (ssutil_global_to_tuple(idx, order, arr->p_bases, k, gl)){

            coeff_t fg = deriv ? ssutil_tuple_factor(gl, order) : 1.0;
            const coeff_t* src;

            if (sshelp_rank_tab_init(&tab, k, arr->trc_order) != SSHELP_OK){
                ssoti_out_of_memory();
            }

            src = arr->p_data + oarrss_block_index(k, order, sshelp_rank(gl, order, &tab)) * m;

            for (e = 0; e < m; e++){
                out->p_data[e] = fg * src[e];
            }

            for (s = 1; s <= act_r; s++){

                ndir_t Ns = sshelp_ndir_order(k, s), j;
                ord_t so = (ord_t)(s + order);

                for (i = 0; i < s; i++){
                    r[i] = 0;
                }

                for (j = 0; j < Ns; j++){

                    coeff_t* dst = out->p_data + oarrss_block_index(k, s, j) * m;
                    coeff_t f = 1.0;

                    ssutil_merge_tuples(r, s, gl, order, d);
                    src = arr->p_data + oarrss_block_index(k, so, sshelp_rank(d, so, &tab)) * m;

                    if (deriv){
                        f = ssutil_tuple_factor(d, so) / ssutil_tuple_factor(r, s);
                    }

                    for (e = 0; e < m; e++){
                        dst[e] = f * src[e];
                    }

                    sshelp_next_dir(r, s, k);

                }

            }

            sshelp_rank_tab_free(&tab);
            out->act_order = act_r;

        }

    }

    if (alias){

        oarrss_copy_to(&tmp, res);
        oarrss_free(&tmp);

    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void oarrss_extract_im_to(imdir_t idx, ord_t order, const oarrss_t* arr, oarrss_t* res){

    oarrss_extract_common(idx, order, arr, 0, res);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void oarrss_extract_deriv_to(imdir_t idx, ord_t order, const oarrss_t* arr, oarrss_t* res){

    oarrss_extract_common(idx, order, arr, 1, res);

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// ---------------------------------------     TRUNCATED ALGEBRA     -------------------------------------
// -------------------------------------------------------------------------------------------------------

// *******************************************************************************************************
int oarrss_trunc_matmul_OO_to(ord_t orda, const oarrss_t* A, ord_t ordb, const oarrss_t* B,
                              oarrss_t* res, dhelpl_t dhl){

    uint64_t nrows = A->nrows, ninner = A->ncols, ncols = B->ncols;
    uint64_t sa = nrows * ninner, sr = nrows * ncols, e;
    ord_t trc = (A->trc_order > B->trc_order) ? A->trc_order : B->trc_order;
    unsigned ordr = (unsigned)orda + ordb;
    bases_t *p_u, *pos_a, *pos_b, nu;
    const coeff_t *Ea = NULL, *Eb = NULL;
    coeff_t *own_a = NULL, *own_b = NULL, *work = NULL, *R;
    oarrss_t tmp = oarrss_init();
    oarrss_t* out;
    int alias = oarrss_util_alias(res, A) || oarrss_util_alias(res, B);
    ndir_t Na, Nb, i, j;

    if (A->ncols != B->nrows){
        return OTI_LINALG_ERR_SIZE;
    }

    if (!oti_lapack_fits(nrows) || !oti_lapack_fits(ninner) || !oti_lapack_fits(ncols)){
        return OTI_LINALG_ERR_SIZE;
    }

    p_u = oarrss_util_union(A, B, &nu, &pos_a, &pos_b);
    out = alias ? &tmp : res;

    Na = sshelp_ndir_order(nu, orda);
    Nb = sshelp_ndir_order(nu, ordb);

    if (ordr <= trc && !oti_lapack_fits(ncols * Nb)){

        free(p_u);
        return OTI_LINALG_ERR_SIZE;

    }

    if (ordr <= trc){

        Ea = oarrss_util_order_view(A, orda, pos_a, nu, &own_a);
        Eb = oarrss_util_order_view(B, ordb, pos_b, nu, &own_b);

    }

    oarrss_util_setup(out, p_u, nu, nrows, ncols, trc);

    if (Ea != NULL && Eb != NULL && sr > 0 && ninner > 0){

        R = out->p_data + oarrss_block_index(nu, (ord_t)ordr, 0) * sr;

        if (orda == 0){

            // A_0 [B_1 ... B_Nb]: the order-ordb blocks of B and of the result are contiguous.
            oti_dgemm('N', 'N', (int)nrows, (int)(ncols * Nb), (int)ninner, 1.0, Ea, (int)nrows,
                      Eb, (int)ninner, 0.0, R, (int)nrows);

        } else if (ordb == 0){

            for (i = 0; i < Na; i++){

                const coeff_t* Ai = Ea + (uint64_t)i * sa;

                if (oarrss_util_zero(Ai, sa)){
                    continue;
                }

                oti_dgemm('N', 'N', (int)nrows, (int)ncols, (int)ninner, 1.0, Ai, (int)nrows, Eb,
                          (int)ninner, 0.0, R + (uint64_t)i * sr, (int)nrows);

            }

        } else {

            oarrss_pairsrc_t src = oarrss_pairsrc_init(nu, orda, ordb, dhl);

            work = (coeff_t*)malloc((size_t)sr * Nb * sizeof(coeff_t) + 1);

            if (work == NULL){
                ssoti_out_of_memory();
            }

            for (i = 0; i < Na; i++){

                const coeff_t* Ai = Ea + (uint64_t)i * sa;

                if (oarrss_util_zero(Ai, sa)){
                    continue;
                }

                oti_dgemm('N', 'N', (int)nrows, (int)(ncols * Nb), (int)ninner, 1.0, Ai,
                          (int)nrows, Eb, (int)ninner, 0.0, work, (int)nrows);

                for (j = 0; j < Nb; j++){

                    const coeff_t* Wj = work + (uint64_t)j * sr;
                    coeff_t* Rd = R + (uint64_t)oarrss_pairsrc_idx(&src, i, j) * sr;

                    for (e = 0; e < sr; e++){
                        Rd[e] += Wj[e];
                    }

                }

            }

            oarrss_pairsrc_free(&src);
            free(work);

        }

        out->act_order = (ord_t)ordr;

    }

    free(own_a);
    free(own_b);
    free(p_u);

    if (alias){

        oarrss_copy_to(&tmp, res);
        oarrss_free(&tmp);

    }

    return 0;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oarrss_trunc_sub_OO_to(ord_t order, const oarrss_t* A, const oarrss_t* B, oarrss_t* res){

    ord_t trc = (A->trc_order > B->trc_order) ? A->trc_order : B->trc_order;
    uint64_t m = A->size, e;
    bases_t *p_u, *pos_a, *pos_b, nu;
    oarrss_t tmp = oarrss_init();
    oarrss_t* out;
    int alias = oarrss_util_alias(res, A) || oarrss_util_alias(res, B);

    if (A->nrows != B->nrows || A->ncols != B->ncols){
        return OTI_LINALG_ERR_SIZE;
    }

    p_u = oarrss_util_union(A, B, &nu, &pos_a, &pos_b);
    out = alias ? &tmp : res;

    oarrss_util_setup(out, p_u, nu, A->nrows, A->ncols, trc);

    if (order == 0){

        for (e = 0; e < m; e++){
            out->p_data[e] = A->p_data[e] - B->p_data[e];
        }

    } else if (order <= trc){

        coeff_t* dst = out->p_data + oarrss_block_index(nu, order, 0) * m;

        if (order <= A->act_order && order <= A->trc_order && A->nbases > 0){
            ssutil_expand_order_acc(A->p_data + oarrss_block_index(A->nbases, order, 0) * m,
                                    A->nbases, pos_a, nu, order, m, 1.0, dst);
        }

        if (order <= B->act_order && order <= B->trc_order && B->nbases > 0){
            ssutil_expand_order_acc(B->p_data + oarrss_block_index(B->nbases, order, 0) * m,
                                    B->nbases, pos_b, nu, order, m, -1.0, dst);
        }

        out->act_order = order;

    }

    free(p_u);

    if (alias){

        oarrss_copy_to(&tmp, res);
        oarrss_free(&tmp);

    }

    return 0;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oarrss_dot_product_OO_to(const oarrss_t* A, const oarrss_t* B, ssotinum_t* res, dhelpl_t dhl){

    uint64_t m = A->size, e;
    ord_t trc = (A->trc_order > B->trc_order) ? A->trc_order : B->trc_order;
    ord_t atop = (A->act_order < A->trc_order) ? A->act_order : A->trc_order;
    ord_t btop = (B->act_order < B->trc_order) ? B->act_order : B->trc_order;
    ord_t p, q;
    bases_t *p_u, *pos_a, *pos_b, nu;
    coeff_t *own_a = NULL, *own_b = NULL, s;
    const coeff_t *Ea, *Eb;
    ssotinum_t tmp;

    if (A->size != B->size){
        return OTI_LINALG_ERR_SIZE;
    }

    p_u = oarrss_util_union(A, B, &nu, &pos_a, &pos_b);

    // Operands over another set are expanded once into the union layout, orders 0..own trc.
    if (A->nbases == nu){

        Ea = A->p_data;

    } else {

        own_a = (coeff_t*)malloc((size_t)(1 + ssoti_nimag_checked(nu, A->trc_order)) * m
                                 * sizeof(coeff_t) + 1);

        if (own_a == NULL){
            ssoti_out_of_memory();
        }

        oarrss_kernel_expand(A, pos_a, nu, A->trc_order, own_a);
        Ea = own_a;

    }

    if (B->nbases == nu){

        Eb = B->p_data;

    } else {

        own_b = (coeff_t*)malloc((size_t)(1 + ssoti_nimag_checked(nu, B->trc_order)) * m
                                 * sizeof(coeff_t) + 1);

        if (own_b == NULL){
            ssoti_out_of_memory();
        }

        oarrss_kernel_expand(B, pos_b, nu, B->trc_order, own_b);
        Eb = own_b;

    }

    tmp = ssoti_create_empty(p_u, nu, trc);

    s = 0.0;

    for (e = 0; e < m; e++){
        s += Ea[e] * Eb[e];
    }

    tmp.re = s;

    for (p = 0; p <= atop; p++){

        ndir_t Np = sshelp_ndir_order(nu, p), i, j;

        for (q = 0; q <= btop && p + q <= trc; q++){

            ndir_t Nq = sshelp_ndir_order(nu, q);
            uint64_t bp, bq;
            coeff_t* Rq;
            oarrss_pairsrc_t src;

            if (p + q == 0){
                continue;
            }

            src = oarrss_pairsrc_init(nu, p, q, dhl);
            Rq  = tmp.p_im + sshelp_order_offset(nu, (ord_t)(p + q));
            bp  = oarrss_block_index(nu, p, 0);
            bq  = oarrss_block_index(nu, q, 0);

            for (i = 0; i < Np; i++){

                const coeff_t* Ai = Ea + (bp + i) * m;

                if (oarrss_util_zero(Ai, m)){
                    continue;
                }

                for (j = 0; j < Nq; j++){

                    const coeff_t* Bj = Eb + (bq + j) * m;

                    s = 0.0;

                    for (e = 0; e < m; e++){
                        s += Ai[e] * Bj[e];
                    }

                    Rq[oarrss_pairsrc_idx(&src, i, j)] += s;

                }

            }

            oarrss_pairsrc_free(&src);

        }

    }

    tmp.act_order = ((unsigned)atop + btop < trc) ? (ord_t)(atop + btop) : trc;

    ssoti_copy_to(&tmp, res);
    ssoti_free(&tmp);

    free(own_a);
    free(own_b);
    free(p_u);

    return 0;

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// ---------------------------------------     ROM EVALUATION     ----------------------------------------
// -------------------------------------------------------------------------------------------------------

// *******************************************************************************************************
void oarrss_rom_eval_to(const oarrss_t* arr, const coeff_t* deltas, oarrss_t* res){

    bases_t k = arr->nbases, u[256];
    uint64_t m = arr->size, e;
    ord_t top = (arr->act_order < arr->trc_order) ? arr->act_order : arr->trc_order, p, i;
    coeff_t* val = (coeff_t*)malloc((size_t)m * sizeof(coeff_t) + 1);

    if (val == NULL){
        ssoti_out_of_memory();
    }

    memcpy(val, arr->p_data, (size_t)m * sizeof(coeff_t));

    for (p = 1; p <= top; p++){

        ndir_t Np = sshelp_ndir_order(k, p), j;

        for (i = 0; i < p; i++){
            u[i] = 0;
        }

        for (j = 0; j < Np; j++){

            const coeff_t* blk = arr->p_data + oarrss_block_index(k, p, j) * m;
            coeff_t mono = 1.0;

            for (i = 0; i < p; i++){
                mono *= deltas[u[i]];
            }

            if (mono != 0.0){

                for (e = 0; e < m; e++){
                    val[e] += blk[e] * mono;
                }

            }

            sshelp_next_dir(u, p, k);

        }

    }

    oarrss_util_setup(res, NULL, 0, arr->nrows, arr->ncols, 0);
    memcpy(res->p_data, val, (size_t)m * sizeof(coeff_t));
    free(val);

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// ---------------------------------------     GLOBAL LAYOUTS     ----------------------------------------
// -------------------------------------------------------------------------------------------------------

// *******************************************************************************************************
// Copies a column-major nrows x ncols block into a row-major one (scaled).
static void oarrss_util_block_to_rowmajor(const coeff_t* blk, uint64_t nrows, uint64_t ncols,
                                          coeff_t f, coeff_t* out, uint64_t ldo){

    uint64_t r, c;

    for (r = 0; r < nrows; r++){

        for (c = 0; c < ncols; c++){
            out[r * ldo + c] = f * blk[r + c * nrows];
        }

    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void oarrss_get_all_ims_to(const oarrss_t* arr, bases_t nbasis, ord_t order, int derivs,
                           coeff_t* out){

    bases_t k = arr->nbases, u[256], g[256];
    uint64_t m = arr->size, nr = arr->nrows, nc = arr->ncols;
    ord_t top = (arr->act_order < arr->trc_order) ? arr->act_order : arr->trc_order, p, i;
    ndir_t ntot = sshelp_ndir_total(nbasis, order);

    memset(out, 0, (size_t)(1 + ntot) * m * sizeof(coeff_t));
    oarrss_util_block_to_rowmajor(arr->p_data, nr, nc, 1.0, out, nc);

    if (order < top){
        top = order;
    }

    for (p = 1; p <= top; p++){

        ndir_t Np = sshelp_ndir_order(k, p), j;
        uint64_t base = 1 + (uint64_t)sshelp_order_offset(nbasis, p);

        for (i = 0; i < p; i++){
            u[i] = 0;
        }

        for (j = 0; j < Np; j++){

            for (i = 0; i < p; i++){
                g[i] = arr->p_bases[u[i]];
            }

            if (g[p - 1] <= nbasis){

                coeff_t f = derivs ? ssutil_tuple_factor(u, p) : 1.0;
                uint64_t d = base + sshelp_global_rank(g, p);

                oarrss_util_block_to_rowmajor(arr->p_data + oarrss_block_index(k, p, j) * m, nr, nc,
                                              f, out + d * m, nc);

            }

            sshelp_next_dir(u, p, k);

        }

    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
bases_t oarrss_order_max_base(ord_t p, const oarrss_t* arr){

    bases_t k = arr->nbases, u[256];
    uint64_t m = arr->size;
    ndir_t Np, j;

    if (p == 0 || p > arr->act_order || p > arr->trc_order || k == 0){
        return 0;
    }

    Np = sshelp_ndir_order(k, p);

    // Colex order: the last nonzero direction has the largest last (= largest) base.
    for (j = Np; j > 0; j--){

        if (!oarrss_util_zero(arr->p_data + oarrss_block_index(k, p, j - 1) * m, m)){

            sshelp_unrank(j - 1, p, u);
            return arr->p_bases[u[p - 1]];

        }

    }

    return 0;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void oarrss_get_order_im_array_to(ord_t p, const oarrss_t* arr, ndir_t width, coeff_t* out){

    bases_t k = arr->nbases, u[256], g[256];
    uint64_t m = arr->size, nr = arr->nrows, nc = arr->ncols, ldo = nc * width;
    ord_t i;
    ndir_t Np, j;

    memset(out, 0, (size_t)m * width * sizeof(coeff_t));

    if (width == 0){
        return;
    }

    if (p == 0){

        oarrss_util_block_to_rowmajor(arr->p_data, nr, nc, 1.0, out, ldo);
        return;

    }

    if (p > arr->act_order || p > arr->trc_order || k == 0){
        return;
    }

    Np = sshelp_ndir_order(k, p);

    for (i = 0; i < p; i++){
        u[i] = 0;
    }

    for (j = 0; j < Np; j++){

        imdir_t gidx;

        for (i = 0; i < p; i++){
            g[i] = arr->p_bases[u[i]];
        }

        gidx = sshelp_global_rank(g, p);

        if (gidx < width){
            oarrss_util_block_to_rowmajor(arr->p_data + oarrss_block_index(k, p, j) * m, nr, nc,
                                          1.0, out + nc * (uint64_t)gidx, ldo);
        }

        sshelp_next_dir(u, p, k);

    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void oarrss_add_order_im_array(ord_t p, const coeff_t* in, ndir_t width, oarrss_t* arr){

    uint64_t nr = arr->nrows, nc = arr->ncols, ldi = nc * width, r, c;
    uint8_t *nz, *mark;
    bases_t *newb, nnew;
    ndir_t gidx;
    uint32_t b;
    int any = 0;

    if (width == 0 || arr->size == 0){
        return;
    }

    if (p == 0){

        for (r = 0; r < nr; r++){

            for (c = 0; c < nc; c++){
                arr->p_data[r + c * nr] += in[r * ldi + c];
            }

        }

        return;

    }

    nz   = (uint8_t*)calloc((size_t)width + 1, 1);
    mark = (uint8_t*)calloc(65536, 1);

    if (nz == NULL || mark == NULL){
        ssoti_out_of_memory();
    }

    for (r = 0; r < nr; r++){

        const coeff_t* row = in + r * ldi;

        for (gidx = 0; gidx < width; gidx++){

            const coeff_t* seg = row + nc * (uint64_t)gidx;

            if (!nz[gidx] && !oarrss_util_zero(seg, nc)){

                nz[gidx] = 1;
                any      = 1;

            }

        }

    }

    if (!any){

        free(nz);
        free(mark);
        return;

    }

    nnew = ssutil_mark_global_bases(p, nz, width, mark);
    newb = (bases_t*)malloc((size_t)nnew * sizeof(bases_t) + 1);

    if (newb == NULL){
        ssoti_out_of_memory();
    }

    nnew = 0;

    for (b = 1; b < 65536; b++){

        if (mark[b]){
            newb[nnew++] = (bases_t)b;
        }

    }

    // The sparse sum takes the larger truncation order.
    if (arr->trc_order < p){
        oarrss_reserve(arr, arr->cap_bases, nr, nc, p);
    }

    oarrss_add_bases(newb, nnew, arr);

    for (gidx = 0; gidx < width; gidx++){

        ndir_t l;
        coeff_t* blk;

        if (!nz[gidx]){
            continue;
        }

        if (sshelp_global_to_local((imdir_t)gidx, p, arr->p_bases, arr->nbases, &l) != 1){
            continue;
        }

        blk = arr->p_data + oarrss_block_index(arr->nbases, p, l) * arr->size;

        for (r = 0; r < nr; r++){

            for (c = 0; c < nc; c++){
                blk[r + c * nr] += in[r * ldi + c + nc * (uint64_t)gidx];
            }

        }

    }

    if (arr->act_order < p){
        arr->act_order = p;
    }

    free(newb);
    free(nz);
    free(mark);

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// ---------------------------------------     FILTERS AND INTERPOLATION     -----------------------------
// -------------------------------------------------------------------------------------------------------

// *******************************************************************************************************
int oarrss_moving_average_to(const oarrss_t* arr, uint64_t size, oarrss_t* res){

    uint64_t n = arr->size, k, j, b, nblocks;
    int64_t left, right;
    ord_t top = (arr->act_order < arr->trc_order) ? arr->act_order : arr->trc_order;
    coeff_t factor;

    if (size == 0){
        return OTI_LINALG_ERR_SIZE;
    }

    factor  = 1.0 / (coeff_t)size;
    left    = (int64_t)size - (int64_t)(size / 2) - 1;
    right   = (int64_t)size - left;
    nblocks = 1 + sshelp_ndir_total(arr->nbases, top);

    oarrss_util_setup(res, arr->p_bases, arr->nbases, n, 1, arr->trc_order);

    // Same operation order as the sparse filter, so every coefficient matches it exactly.
    for (b = 0; b < nblocks; b++){

        const coeff_t* src = arr->p_data + b * n;
        coeff_t* dst = res->p_data + b * n;

        for (k = 0; k < n; k++){

            int64_t lo = (int64_t)k - left, hi = (int64_t)k + right;
            uint64_t startj = (lo > 0) ? (uint64_t)lo : 0;
            uint64_t endj = (hi < (int64_t)n) ? (uint64_t)hi : n;
            int64_t nmis_s = (lo < 0) ? -lo : 0;
            int64_t nmis_e = (hi > (int64_t)n) ? hi - (int64_t)n : 0;
            coeff_t value = 0.0;

            if (nmis_s > 0){
                value = factor * (src[startj] * (coeff_t)nmis_s);
            }

            if (nmis_e > 0){
                value = value + factor * (src[endj - 1] * (coeff_t)nmis_e);
            }

            for (j = startj; j < endj; j++){
                value += src[j] * factor;
            }

            dst[k] = value;

        }

    }

    res->act_order = arr->act_order;

    return 0;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oarrss_interp1d_o_to(const oarrss_t* xvals, const oarrss_t* yvals, const ssotinum_t* x,
                         ssotinum_t* res, dhelpl_t dhl){

    uint64_t n = xvals->nrows, start, finish, mid, rang;
    const coeff_t* xr = xvals->p_data;
    coeff_t xv = x->re;
    ssotinum_t y0, y1, x0, x1, dy, dx, slope, t;

    if (n == 0 || xvals->size == 0 || yvals->nrows < n || yvals->ncols == 0){
        return OTI_LINALG_ERR_SIZE;
    }

    if (xv < xr[0] || n == 1){

        oarrss_get_item_to(0, 0, yvals, res);
        return 0;

    }

    if (xv > xr[n - 1]){

        oarrss_get_item_to(n - 1, 0, yvals, res);
        return 0;

    }

    // Bisection of the sparse interp1d(), 1-based: x[mid-1] <= x.re <= x[mid] at the end.
    start  = 1;
    finish = n;
    rang   = finish - start;
    mid    = (finish + start) / 2;

    while (rang > 1){

        if (xv > xr[mid - 1]){
            start = mid;
        } else {
            finish = mid;
        }

        rang = finish - start;
        mid  = (finish + start) / 2;

    }

    y0 = oarrss_get_item(mid - 1, 0, yvals);
    y1 = oarrss_get_item(mid, 0, yvals);
    x0 = oarrss_get_item(mid - 1, 0, xvals);
    x1 = oarrss_get_item(mid, 0, xvals);
    dy = ssoti_sub_oo(&y1, &y0, dhl);
    dx = ssoti_sub_oo(&x1, &x0, dhl);
    slope = ssoti_div_oo(&dy, &dx, dhl);
    t = ssoti_sub_oo(x, &x0, dhl);

    ssoti_mul_oo_to(&slope, &t, &dy, dhl);
    ssoti_sum_oo_to(&dy, &y0, res, dhl);

    ssoti_free(&y0);
    ssoti_free(&y1);
    ssoti_free(&x0);
    ssoti_free(&x1);
    ssoti_free(&dy);
    ssoti_free(&dx);
    ssoti_free(&slope);
    ssoti_free(&t);

    return 0;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oarrss_interp1d_O_to(const oarrss_t* xvals, const oarrss_t* yvals, const oarrss_t* X,
                         oarrss_t* res, dhelpl_t dhl){

    ord_t trc = X->trc_order;
    ssotinum_t xe = ssoti_init(), ye = ssoti_init();
    uint64_t i, j;
    int status = 0;

    if (xvals->trc_order > trc){
        trc = xvals->trc_order;
    }

    if (yvals->trc_order > trc){
        trc = yvals->trc_order;
    }

    oarrss_util_setup(res, NULL, 0, X->nrows, X->ncols, trc);

    for (j = 0; j < X->ncols && status == 0; j++){

        for (i = 0; i < X->nrows && status == 0; i++){

            oarrss_get_item_to(i, j, X, &xe);
            status = oarrss_interp1d_o_to(xvals, yvals, &xe, &ye, dhl);

            if (status == 0){
                oarrss_set_item(&ye, i, j, res);
            }

        }

    }

    ssoti_free(&xe);
    ssoti_free(&ye);

    return status;

}
// -------------------------------------------------------------------------------------------------------
