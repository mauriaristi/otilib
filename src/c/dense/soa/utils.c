// Dense SoA arrays: order and derivative plumbing, trunc_matmul / trunc_sub / dot_product, rom_eval,
// global layouts, moving_average and interp1d (include/oti/dense/soa/utils.h). Template:
// src/c/semisparse/soa/utils.c.
//
// Unity-included from src/c/dense.c: static helpers carry the dnou_ prefix. A dense array over bases
// 1..nact has local numbering equal to global numbering, so there are no unions, remaps or ranks of
// bases lists: an operand over fewer bases is a prefix of the result layout and is read in place at its
// own block offsets. Temporaries are malloc'd and freed inside each call: no coefficient-sized buffer
// outlives a call.


// -------------------------------------------------------------------------------------------------------
// ---------------------------------------     HELPERS     -----------------------------------------------
// -------------------------------------------------------------------------------------------------------

// *******************************************************************************************************
// Tells whether res shares its buffer with arr (then results go through a call-local array).
static int dnou_alias(const oarr_t* res, const oarr_t* arr){

    return (res == arr) || (res->p_data != NULL && res->p_data == arr->p_data);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Installs a call-local array into res, releasing res's old buffer.
static void dnou_install(oarr_t* tmp, oarr_t* res){

    free(res->p_data);
    *res = *tmp;
    *tmp = oarr_init();

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// The array the result is written to: res itself, or the call-local tmp when res is an operand. Makes
// it a zero nrows x ncols array over nact bases at truncation order trc (act_order 0).
static int dnou_target(oarr_t* res, int alias, oarr_t* tmp, bases_t nact, uint64_t nrows,
                       uint64_t ncols, ord_t trc, oarr_t** p_out){

    *p_out = alias ? tmp : res;

    return oarr_zeros_to(nact, nrows, ncols, trc, *p_out);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Finishes a call: when the result was built in the call-local array (alias set), installs it on
// success; releases the call-local array either way.
static int dnou_finish(int status, int alias, oarr_t* tmp, oarr_t* res){

    if (status == DN_OK && alias){
        dnou_install(tmp, res);
    }

    oarr_free(tmp);

    return status;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Tells whether n reals are all zero.
static int dnou_zero(const coeff_t* x, uint64_t n){

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
// Highest order whose blocks can hold nonzeros.
static inline ord_t dnou_top(const oarr_t* arr){

    return (arr->act_order < arr->trc_order) ? arr->act_order : arr->trc_order;

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// ---------------------------------------     EXTRACTION     --------------------------------------------
// -------------------------------------------------------------------------------------------------------

// *******************************************************************************************************
// Shared body of oarr_extract_im_to() and oarr_extract_deriv_to(): the block version of
// oti_extract_im_to() / oti_extract_deriv_to().
static int dnou_extract_common(imdir_t idx, ord_t order, const oarr_t* arr, int deriv, oarr_t* res){

    bases_t k = arr->nact, gl[256], r[256], d[256];
    uint64_t m = arr->size, e, bs, bd;
    ord_t trc_r, act_r, s, so;
    ndir_t Ns, j;
    oarr_t tmp = oarr_init(), *out;
    int alias = dnou_alias(res, arr), status;
    sshelp_rank_tab_t tab;
    coeff_t fg, f;
    const coeff_t* src;
    coeff_t* dst;

    if (order == 0){
        return oarr_copy_to(arr, res);
    }

    // Order above trc: a real zero array with truncation order 0.
    if (order > arr->trc_order){

        status = dnou_target(res, alias, &tmp, 0, arr->nrows, arr->ncols, 0, &out);

        return dnou_finish(status, alias, &tmp, res);

    }

    trc_r  = (ord_t)(arr->trc_order - order);
    status = dnou_target(res, alias, &tmp, k, arr->nrows, arr->ncols, trc_r, &out);

    if (status != DN_OK){
        return dnou_finish(status, alias, &tmp, res);
    }

    // A direction above act_order, or with a base above nact, gives zero (in the layout (nact, trc_r)).
    if (order > arr->act_order || !dnutil_dir_inside(idx, order, k)){
        return dnou_finish(DN_OK, alias, &tmp, res);
    }

    act_r = (ord_t)(arr->act_order - order);

    if (sshelp_rank_tab_init(&tab, k, arr->trc_order) != SSHELP_OK){

        oarr_free(&tmp);
        return DN_ERR_MEMORY;

    }

    sshelp_unrank((ndir_t)idx, order, gl);
    fg  = deriv ? dnutil_tuple_factor(gl, order) : 1.0;
    src = arr->p_data + oarr_block_index(k, order, idx) * m;

    for (e = 0; e < m; e++){
        out->p_data[e] = fg * src[e];
    }

    // Every quotient direction r of order s maps to the input direction r * g of order s + order.
    for (s = 1; s <= act_r; s++){

        Ns = sshelp_ndir_order(k, s);
        so = (ord_t)(s + order);
        bd = oarr_block_index(k, s, 0);
        bs = oarr_block_index(k, so, 0);

        memset(r, 0, (size_t)s * sizeof(bases_t));

        for (j = 0; j < Ns; j++){

            dnutil_merge_tuples(r, s, gl, order, d);
            src = arr->p_data + (bs + sshelp_rank(d, so, &tab)) * m;
            dst = out->p_data + (bd + j) * m;
            f   = deriv ? dnutil_tuple_factor(d, so) / dnutil_tuple_factor(r, s) : 1.0;

            for (e = 0; e < m; e++){
                dst[e] = f * src[e];
            }

            sshelp_next_dir(r, s, k);

        } // end for

    } // end for

    sshelp_rank_tab_free(&tab);

    out->act_order = (k == 0) ? 0 : act_r;

    return dnou_finish(DN_OK, alias, &tmp, res);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oarr_extract_im_to(imdir_t idx, ord_t order, const oarr_t* arr, oarr_t* res){

    return dnou_extract_common(idx, order, arr, 0, res);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oarr_extract_deriv_to(imdir_t idx, ord_t order, const oarr_t* arr, oarr_t* res){

    return dnou_extract_common(idx, order, arr, 1, res);

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// ---------------------------------------     TRUNCATED ALGEBRA     -------------------------------------
// -------------------------------------------------------------------------------------------------------

// *******************************************************************************************************
int oarr_trunc_matmul_OO_to(ord_t orda, const oarr_t* A, ord_t ordb, const oarr_t* B,
                            oarr_t* res, dhelpl_t dhl){

    uint64_t nrows = A->nrows, ninner = A->ncols, ncols = B->ncols;
    uint64_t sa = nrows * ninner, sb = ninner * ncols, sr = nrows * ncols, e;
    bases_t nu = (A->nact > B->nact) ? A->nact : B->nact;
    ord_t trc = (A->trc_order > B->trc_order) ? A->trc_order : B->trc_order;
    unsigned ordr = (unsigned)orda + ordb;
    ndir_t Na = 0, Nb = 0, i, j;
    const coeff_t *Ea = NULL, *Eb = NULL;
    coeff_t *work = NULL, *R;
    oarr_t tmp = oarr_init(), *out;
    int alias = dnou_alias(res, A) || dnou_alias(res, B), status;
    dnok_pairsrc_t src;
    bases_t ui[256], uj[256];

    if (A->ncols != B->nrows){
        return DN_ERR_SIZE;
    }

    if (!oti_lapack_fits(nrows) || !oti_lapack_fits(ninner) || !oti_lapack_fits(ncols)){
        return DN_ERR_SIZE;
    }

    // Each operand's order block is a prefix of the layout over nu bases: only its own directions
    // are read, the rest are zero.
    if (ordr <= trc){

        if (orda == 0){

            Na = 1;
            Ea = A->p_data;

        } else if (orda <= dnou_top(A)){

            Na = sshelp_ndir_order(A->nact, orda);
            Ea = A->p_data + oarr_block_index(A->nact, orda, 0) * sa;

        }

        if (ordb == 0){

            Nb = 1;
            Eb = B->p_data;

        } else if (ordb <= dnou_top(B)){

            Nb = sshelp_ndir_order(B->nact, ordb);
            Eb = B->p_data + oarr_block_index(B->nact, ordb, 0) * sb;

        }

        if (!oti_lapack_fits(ncols * Nb)){
            return DN_ERR_SIZE;
        }

    }

    status = dnou_target(res, alias, &tmp, nu, nrows, ncols, trc, &out);

    if (status != DN_OK){
        return dnou_finish(status, alias, &tmp, res);
    }

    if (Ea != NULL && Eb != NULL && Na > 0 && Nb > 0 && sr > 0 && ninner > 0){

        R = out->p_data + oarr_block_index(nu, (ord_t)ordr, 0) * sr;

        if (orda == 0){

            // A_0 [B_1 ... B_Nb]: the order-ordb blocks of B and of the result are contiguous.
            oti_dgemm('N', 'N', (int)nrows, (int)(ncols * Nb), (int)ninner, 1.0, Ea, (int)nrows, Eb,
                      (int)ninner, 0.0, R, (int)nrows);

        } else if (ordb == 0){

            for (i = 0; i < Na; i++){

                const coeff_t* Ai = Ea + (uint64_t)i * sa;

                if (dnou_zero(Ai, sa)){
                    continue;
                }

                oti_dgemm('N', 'N', (int)nrows, (int)ncols, (int)ninner, 1.0, Ai, (int)nrows, Eb,
                          (int)ninner, 0.0, R + (uint64_t)i * sr, (int)nrows);

            } // end for

        } else {

            work = (sr < SIZE_MAX / sizeof(coeff_t) / Nb - 1)
                   ? (coeff_t*)malloc((size_t)sr * Nb * sizeof(coeff_t) + 1) : NULL;

            if (work == NULL){
                return dnou_finish(DN_ERR_MEMORY, alias, &tmp, res);
            }

            src = dnok_pairsrc_init(nu, orda, ordb, dhl);
            dnok_tuple_reset(ui, orda);

            for (i = 0; i < Na; i++){

                const coeff_t* Ai = Ea + (uint64_t)i * sa;

                if (!dnou_zero(Ai, sa)){

                    oti_dgemm('N', 'N', (int)nrows, (int)(ncols * Nb), (int)ninner, 1.0, Ai,
                              (int)nrows, Eb, (int)ninner, 0.0, work, (int)nrows);

                    dnok_tuple_reset(uj, ordb);

                    for (j = 0; j < Nb; j++){

                        const coeff_t* Wj = work + (uint64_t)j * sr;
                        ndir_t d = dnok_pair_idx(&src, i, ui, j, uj);
                        coeff_t* Rd = R + (uint64_t)d * sr;

                        for (e = 0; e < sr; e++){
                            Rd[e] += Wj[e];
                        }

                        if (src.fallback){
                            sshelp_next_dir(uj, ordb, nu);
                        }

                    } // end for

                }

                if (src.fallback){
                    sshelp_next_dir(ui, orda, nu);
                }

            } // end for

            dnok_pairsrc_free(&src);
            free(work);

        } // end if

        out->act_order = (ord_t)ordr;

    } // end if

    return dnou_finish(DN_OK, alias, &tmp, res);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oarr_trunc_sub_OO_to(ord_t order, const oarr_t* A, const oarr_t* B, oarr_t* res){

    bases_t nu = (A->nact > B->nact) ? A->nact : B->nact;
    ord_t trc = (A->trc_order > B->trc_order) ? A->trc_order : B->trc_order;
    uint64_t m = A->size, e, i, n;
    oarr_t tmp = oarr_init(), *out;
    int alias = dnou_alias(res, A) || dnou_alias(res, B), status;
    const coeff_t* S;
    coeff_t* D;

    if (A->nrows != B->nrows || A->ncols != B->ncols){
        return DN_ERR_SIZE;
    }

    status = dnou_target(res, alias, &tmp, nu, A->nrows, A->ncols, trc, &out);

    if (status != DN_OK){
        return dnou_finish(status, alias, &tmp, res);
    }

    if (order == 0){

        for (e = 0; e < m; e++){
            out->p_data[e] = A->p_data[e] - B->p_data[e];
        }

    } else if (order <= trc && nu > 0){

        D = out->p_data + oarr_block_index(nu, order, 0) * m;

        if (order <= dnou_top(A) && A->nact > 0){

            n = sshelp_ndir_order(A->nact, order);
            S = A->p_data + oarr_block_index(A->nact, order, 0) * m;

            for (i = 0; i < n * m; i++){
                D[i] += S[i];
            }

        }

        if (order <= dnou_top(B) && B->nact > 0){

            n = sshelp_ndir_order(B->nact, order);
            S = B->p_data + oarr_block_index(B->nact, order, 0) * m;

            for (i = 0; i < n * m; i++){
                D[i] -= S[i];
            }

        }

        out->act_order = order;

    } // end if

    return dnou_finish(DN_OK, alias, &tmp, res);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oarr_dot_product_OO_to(const oarr_t* A, const oarr_t* B, otinum_t* res, dhelpl_t dhl){

    uint64_t m = A->size, e;
    bases_t nu = (A->nact > B->nact) ? A->nact : B->nact;
    ord_t trc = (A->trc_order > B->trc_order) ? A->trc_order : B->trc_order;
    ord_t atop = dnou_top(A), btop = dnou_top(B), p, q;
    otinum_t tmp = oti_init();
    coeff_t s, re;
    int status;

    if (A->size != B->size){
        return DN_ERR_SIZE;
    }

    status = oti_create_empty_to(nu, trc, &tmp);

    if (status != DN_OK){
        return status;
    }

    re = 0.0;

    for (e = 0; e < m; e++){
        re += A->p_data[e] * B->p_data[e];
    }

    tmp.re = re;

    for (p = 0; p <= atop; p++){

        ndir_t Np = (p == 0) ? 1 : sshelp_ndir_order(A->nact, p), i, j;
        uint64_t bp = oarr_block_index(A->nact, p, 0);

        for (q = 0; q <= btop && p + q <= trc; q++){

            ndir_t Nq = (q == 0) ? 1 : sshelp_ndir_order(B->nact, q);
            uint64_t bq = oarr_block_index(B->nact, q, 0);
            coeff_t* Rq;
            dnok_pairsrc_t src;
            bases_t ui[256], uj[256];

            if (p + q == 0 || Np == 0 || Nq == 0){
                continue;
            }

            src = dnok_pairsrc_init(nu, p, q, dhl);
            Rq  = tmp.p_im + sshelp_order_offset(nu, (ord_t)(p + q));
            dnok_tuple_reset(ui, p);

            for (i = 0; i < Np; i++){

                const coeff_t* Ai = A->p_data + (bp + i) * m;

                if (!dnou_zero(Ai, m)){

                    dnok_tuple_reset(uj, q);

                    for (j = 0; j < Nq; j++){

                        const coeff_t* Bj = B->p_data + (bq + j) * m;

                        s = 0.0;

                        for (e = 0; e < m; e++){
                            s += Ai[e] * Bj[e];
                        }

                        Rq[dnok_pair_idx(&src, i, ui, j, uj)] += s;

                        if (src.fallback){
                            sshelp_next_dir(uj, q, nu);
                        }

                    } // end for

                }

                if (src.fallback){
                    sshelp_next_dir(ui, p, nu);
                }

            } // end for

            dnok_pairsrc_free(&src);

        } // end for

    } // end for

    tmp.act_order = (nu == 0) ? 0 : (((unsigned)atop + btop < trc) ? (ord_t)(atop + btop) : trc);

    status = oti_copy_to(&tmp, res);
    oti_free(&tmp);

    return status;

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// ---------------------------------------     ROM EVALUATION     ----------------------------------------
// -------------------------------------------------------------------------------------------------------

// *******************************************************************************************************
int oarr_rom_eval_to(const oarr_t* arr, const coeff_t* deltas, oarr_t* res){

    bases_t k = arr->nact, u[256];
    uint64_t m = arr->size, e, bp;
    ord_t top = (k == 0) ? 0 : dnou_top(arr), p, i;
    coeff_t* val;
    int status;

    if (m > SIZE_MAX / sizeof(coeff_t) - 1){
        return DN_ERR_MEMORY;
    }

    val = (coeff_t*)malloc((size_t)m * sizeof(coeff_t) + 1);

    if (val == NULL){
        return DN_ERR_MEMORY;
    }

    if (m > 0){
        memcpy(val, arr->p_data, (size_t)m * sizeof(coeff_t));
    }

    for (p = 1; p <= top; p++){

        ndir_t Np = sshelp_ndir_order(k, p), j;

        bp = oarr_block_index(k, p, 0);
        memset(u, 0, (size_t)p * sizeof(bases_t));

        for (j = 0; j < Np; j++){

            const coeff_t* blk = arr->p_data + (bp + j) * m;
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

        } // end for

    } // end for

    // Only now touch res (it may alias arr).
    status = oarr_zeros_to(0, arr->nrows, arr->ncols, 0, res);

    if (status == DN_OK && m > 0){
        memcpy(res->p_data, val, (size_t)m * sizeof(coeff_t));
    }

    free(val);

    return status;

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// ---------------------------------------     GLOBAL LAYOUTS     ----------------------------------------
// -------------------------------------------------------------------------------------------------------

// *******************************************************************************************************
// Copies a column-major nrows x ncols block into a row-major one (scaled).
static void dnou_block_to_rowmajor(const coeff_t* blk, uint64_t nrows, uint64_t ncols, coeff_t f,
                                   coeff_t* out, uint64_t ldo){

    uint64_t r, c;

    for (r = 0; r < nrows; r++){

        for (c = 0; c < ncols; c++){
            out[r * ldo + c] = f * blk[r + c * nrows];
        }

    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oarr_get_all_ims_to(const oarr_t* arr, bases_t nbasis, ord_t order, int derivs, coeff_t* out){

    bases_t k = arr->nact, kk = (arr->nact < nbasis) ? arr->nact : nbasis, u[256];
    uint64_t m = arr->size, nr = arr->nrows, nc = arr->ncols, bs, d0;
    ord_t top = (k == 0) ? 0 : dnou_top(arr), p;
    ndir_t ntot, Np, j;
    int status = dnsm_nimag(nbasis, order, &ntot);

    if (status != DN_OK){
        return status;
    }

    if (ntot >= UINT64_MAX / (m + 1) - 1 || (1 + (uint64_t)ntot) * m > SIZE_MAX / sizeof(coeff_t)){
        return DN_ERR_MEMORY;
    }

    memset(out, 0, (size_t)((1 + (uint64_t)ntot) * m) * sizeof(coeff_t));
    dnou_block_to_rowmajor(arr->p_data, nr, nc, 1.0, out, nc);

    if (order < top){
        top = order;
    }

    // Directions past nbasis are the indices from N_p(nbasis) on: only the first N_p(min) are written.
    for (p = 1; p <= top && kk > 0; p++){

        Np = sshelp_ndir_order(kk, p);
        bs = oarr_block_index(k, p, 0);
        d0 = 1 + (uint64_t)sshelp_order_offset(nbasis, p);

        if (derivs){
            memset(u, 0, (size_t)p * sizeof(bases_t));
        }

        for (j = 0; j < Np; j++){

            coeff_t f = derivs ? dnutil_tuple_factor(u, p) : 1.0;

            dnou_block_to_rowmajor(arr->p_data + (bs + j) * m, nr, nc, f, out + (d0 + j) * m, nc);

            if (derivs){
                sshelp_next_dir(u, p, kk);
            }

        } // end for

    } // end for

    return DN_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
bases_t oarr_order_max_base(ord_t p, const oarr_t* arr){

    bases_t k = arr->nact;
    uint64_t m = arr->size, bp;
    ndir_t Np, j;

    if (p == 0 || p > dnou_top(arr) || k == 0){
        return 0;
    }

    Np = sshelp_ndir_order(k, p);
    bp = oarr_block_index(k, p, 0);

    // Colex order: the last nonzero direction has the largest last (= largest) base.
    for (j = Np; j > 0; j--){

        if (!dnou_zero(arr->p_data + (bp + j - 1) * m, m)){
            return dnsb_max_base(j - 1, p);
        }

    }

    return 0;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oarr_get_order_im_array_to(ord_t p, const oarr_t* arr, ndir_t width, coeff_t* out){

    bases_t k = arr->nact;
    uint64_t m = arr->size, nr = arr->nrows, nc = arr->ncols, ldo = nc * width, bp;
    ndir_t Np, j;

    if (width != 0 && (ldo / width != nc || m > SIZE_MAX / sizeof(coeff_t) / width)){
        return DN_ERR_MEMORY;
    }

    memset(out, 0, (size_t)(m * width) * sizeof(coeff_t));

    if (width == 0){
        return DN_OK;
    }

    if (p == 0){

        dnou_block_to_rowmajor(arr->p_data, nr, nc, 1.0, out, ldo);
        return DN_OK;

    }

    if (p > dnou_top(arr) || k == 0){
        return DN_OK;
    }

    // The global index of a direction is its own index.
    Np = sshelp_ndir_order(k, p);
    bp = oarr_block_index(k, p, 0);

    if (Np > width){
        Np = width;
    }

    for (j = 0; j < Np; j++){
        dnou_block_to_rowmajor(arr->p_data + (bp + j) * m, nr, nc, 1.0, out + nc * (uint64_t)j, ldo);
    }

    return DN_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oarr_add_order_im_array(ord_t p, const coeff_t* vals, ndir_t width, oarr_t* arr){

    uint64_t nr = arr->nrows, nc = arr->ncols, ldi = nc * width, r, c, bp;
    ndir_t g, gmax = 0;
    bases_t gl[256], k;
    coeff_t* blk;
    int any = 0, status;

    if (width == 0 || arr->size == 0){
        return DN_OK;
    }

    if (p == 0){

        for (r = 0; r < nr; r++){

            for (c = 0; c < nc; c++){
                arr->p_data[r + c * nr] += vals[r * ldi + c];
            }

        }

        return DN_OK;

    }

    // Largest global index with a nonzero value in any element (the largest base, in colex order).
    for (g = width; g > 0 && !any; g--){

        for (r = 0; r < nr && !any; r++){

            if (!dnou_zero(vals + r * ldi + nc * (uint64_t)(g - 1), nc)){

                gmax = g - 1;
                any  = 1;

            }

        }

    }

    if (!any){
        return DN_OK;
    }

    if (sshelp_global_unrank((imdir_t)gmax, p, gl) != SSHELP_OK){
        return DN_ERR_INDEX;
    }

    k = (gl[p - 1] > arr->nact) ? gl[p - 1] : arr->nact;

    // The sparse sum takes the larger truncation order; capacity for the new layout first.
    status = oarr_reserve(arr, k, nr, nc, p);

    if (status == DN_OK){
        status = oarr_add_bases(k, arr);
    }

    if (status != DN_OK){
        return status;
    }

    bp = oarr_block_index(arr->nact, p, 0);

    for (g = 0; g <= gmax; g++){

        blk = arr->p_data + (bp + g) * arr->size;

        for (r = 0; r < nr; r++){

            for (c = 0; c < nc; c++){
                blk[r + c * nr] += vals[r * ldi + c + nc * (uint64_t)g];
            }

        }

    } // end for

    if (arr->act_order < p){
        arr->act_order = p;
    }

    return DN_OK;

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// ---------------------------------------     FILTERS AND INTERPOLATION     -----------------------------
// -------------------------------------------------------------------------------------------------------

// *******************************************************************************************************
int oarr_moving_average_to(const oarr_t* arr, uint64_t size, oarr_t* res){

    uint64_t n = arr->size, k, j, b, nblocks;
    int64_t left, right;
    ord_t top = dnou_top(arr);
    coeff_t factor;
    oarr_t tmp = oarr_init(), *out;
    int alias = dnou_alias(res, arr), status;

    if (size == 0){
        return DN_ERR_SIZE;
    }

    factor  = 1.0 / (coeff_t)size;
    left    = (int64_t)size - (int64_t)(size / 2) - 1;
    right   = (int64_t)size - left;
    nblocks = 1 + sshelp_ndir_total(arr->nact, top);

    // res may alias arr: the result is then built in a call-local array.
    status = dnou_target(res, alias, &tmp, arr->nact, n, 1, arr->trc_order, &out);

    if (status != DN_OK){
        return dnou_finish(status, alias, &tmp, res);
    }

    // Same operation order as the sparse filter, so every coefficient matches it exactly.
    for (b = 0; b < nblocks; b++){

        const coeff_t* src = arr->p_data + b * n;
        coeff_t* dst = out->p_data + b * n;

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

        } // end for

    } // end for

    out->act_order = arr->act_order;

    return dnou_finish(DN_OK, alias, &tmp, res);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oarr_interp1d_o_to(const oarr_t* xvals, const oarr_t* yvals, const otinum_t* x, otinum_t* res,
                       dhelpl_t dhl){

    uint64_t n = xvals->nrows, start, finish, mid, rang;
    const coeff_t* xr = xvals->p_data;
    coeff_t xv = x->re;
    otinum_t y0 = oti_init(), y1 = oti_init(), x0 = oti_init(), x1 = oti_init(), dy = oti_init();
    otinum_t dx = oti_init(), slope = oti_init(), t = oti_init();
    int status;

    if (n == 0 || xvals->size == 0 || yvals->nrows < n || yvals->ncols == 0){
        return DN_ERR_SIZE;
    }

    if (xv < xr[0] || n == 1){
        return oarr_get_item_to(0, 0, yvals, res);
    }

    if (xv > xr[n - 1]){
        return oarr_get_item_to(n - 1, 0, yvals, res);
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

    status = oarr_get_item_to(mid - 1, 0, yvals, &y0);

    if (status == DN_OK){
        status = oarr_get_item_to(mid, 0, yvals, &y1);
    }

    if (status == DN_OK){
        status = oarr_get_item_to(mid - 1, 0, xvals, &x0);
    }

    if (status == DN_OK){
        status = oarr_get_item_to(mid, 0, xvals, &x1);
    }

    if (status == DN_OK){
        status = oti_sub_oo_to(&y1, &y0, &dy, dhl);
    }

    if (status == DN_OK){
        status = oti_sub_oo_to(&x1, &x0, &dx, dhl);
    }

    if (status == DN_OK){
        status = oti_div_oo_to(&dy, &dx, &slope, dhl);
    }

    if (status == DN_OK){
        status = oti_sub_oo_to(x, &x0, &t, dhl);
    }

    if (status == DN_OK){
        status = oti_mul_oo_to(&slope, &t, &dy, dhl);
    }

    if (status == DN_OK){
        status = oti_sum_oo_to(&dy, &y0, res, dhl);
    }

    oti_free(&y0);
    oti_free(&y1);
    oti_free(&x0);
    oti_free(&x1);
    oti_free(&dy);
    oti_free(&dx);
    oti_free(&slope);
    oti_free(&t);

    return status;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oarr_interp1d_O_to(const oarr_t* xvals, const oarr_t* yvals, const oarr_t* X, oarr_t* res,
                       dhelpl_t dhl){

    ord_t trc = X->trc_order;
    otinum_t xe = oti_init(), ye = oti_init();
    uint64_t i, j;
    oarr_t tmp = oarr_init(), *out;
    int alias = dnou_alias(res, X) || dnou_alias(res, xvals) || dnou_alias(res, yvals), status;

    if (xvals->trc_order > trc){
        trc = xvals->trc_order;
    }

    if (yvals->trc_order > trc){
        trc = yvals->trc_order;
    }

    // res may alias X, xvals or yvals: the result is then built in a call-local array.
    status = dnou_target(res, alias, &tmp, 0, X->nrows, X->ncols, trc, &out);

    for (j = 0; j < X->ncols && status == DN_OK; j++){

        for (i = 0; i < X->nrows && status == DN_OK; i++){

            status = oarr_get_item_to(i, j, X, &xe);

            if (status == DN_OK){
                status = oarr_interp1d_o_to(xvals, yvals, &xe, &ye, dhl);
            }

            if (status == DN_OK){
                status = oarr_set_item(&ye, i, j, out);
            }

        } // end for

    } // end for

    oti_free(&xe);
    oti_free(&ye);

    return dnou_finish(status, alias, &tmp, res);

}
// -------------------------------------------------------------------------------------------------------
