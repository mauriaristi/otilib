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

    return (res == arr) || (oarr_data(res) != NULL && oarr_data(res) == oarr_data(arr));

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Installs a call-local array into res, releasing res's old buffer.
static void dnou_install(oarr_t* tmp, oarr_t* res){

    dnob_move(tmp, res);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// The array the result is written to: res itself, or the call-local tmp when res is an operand. Makes
// it a zero array of element shape S over nact bases at truncation order trc (act_order 0).
static int dnou_target_s(oarr_t* res, int alias, oarr_t* tmp, bases_t nact, const dnob_shape_t* S,
                         ord_t trc, oarr_t** p_out){

    size_t n;
    int status;

    *p_out = alias ? tmp : res;

    // The call-local result replaces the buffer of `res`: not that of a view or a shared array.
    if (alias && !dnob_can_replace(res)){
        return OTI_ERR_BUSY;
    }

    status = dnob_result_shape_s(*p_out, nact, S, trc, &n);

    if (status == DN_OK){

        if (n > 0){
            memset(oarr_data(*p_out), 0, n * sizeof(coeff_t));
        }

        oarr_set_act_order(*p_out, 0);

    }

    return status;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// dnou_target_s() for the element shape of `like` (elementwise results).
static int dnou_target(oarr_t* res, int alias, oarr_t* tmp, bases_t nact, const oarr_t* like,
                       ord_t trc, oarr_t** p_out){

    dnob_shape_t S = dnob_shape_of(like);

    S.layout = ND_LAYOUT_F;

    return dnou_target_s(res, alias, tmp, nact, &S, trc, p_out);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// dnou_target_s() for the matrix shape nrows x ncols.
static int dnou_target2(oarr_t* res, int alias, oarr_t* tmp, bases_t nact, uint64_t nrows,
                        uint64_t ncols, ord_t trc, oarr_t** p_out){

    dnob_shape_t S = dnob_shape2(nrows, ncols);

    return dnou_target_s(res, alias, tmp, nact, &S, trc, p_out);

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

    return (oarr_act_order(arr) < oarr_trc_order(arr)) ? oarr_act_order(arr) : oarr_trc_order(arr);

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// ---------------------------------------     EXTRACTION     --------------------------------------------
// -------------------------------------------------------------------------------------------------------

// *******************************************************************************************************
// Shared body of oarr_extract_im_to() and oarr_extract_deriv_to(): the block version of
// oti_extract_im_to() / oti_extract_deriv_to().
static int dnou_extract_common(imdir_t idx, ord_t order, const oarr_t* arr, int deriv, oarr_t* res){

    bases_t k = oarr_nact(arr), gl[256], r[256], d[256];
    uint64_t m = oarr_size(arr), e, bs, bd;
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
    if (order > oarr_trc_order(arr)){

        status = dnou_target(res, alias, &tmp, 0, arr, 0, &out);

        return dnou_finish(status, alias, &tmp, res);

    }

    trc_r  = (ord_t)(oarr_trc_order(arr) - order);
    status = dnou_target(res, alias, &tmp, k, arr, trc_r, &out);

    if (status != DN_OK){
        return dnou_finish(status, alias, &tmp, res);
    }

    // A direction above act_order, or with a base above nact, gives zero (in the layout (nact, trc_r)).
    if (order > oarr_act_order(arr) || !dnutil_dir_inside(idx, order, k)){
        return dnou_finish(DN_OK, alias, &tmp, res);
    }

    act_r = (ord_t)(oarr_act_order(arr) - order);

    if (sshelp_rank_tab_init(&tab, k, oarr_trc_order(arr)) != SSHELP_OK){

        oarr_free(&tmp);
        return DN_ERR_MEMORY;

    }

    sshelp_unrank((ndir_t)idx, order, gl);
    fg  = deriv ? dnutil_tuple_factor(gl, order) : 1.0;
    src = oarr_data(arr) + oarr_block_index(k, order, idx) * m;

    for (e = 0; e < m; e++){
        oarr_data(out)[e] = fg * src[e];
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
            src = oarr_data(arr) + (bs + sshelp_rank(d, so, &tab)) * m;
            dst = oarr_data(out) + (bd + j) * m;
            f   = deriv ? dnutil_tuple_factor(d, so) / dnutil_tuple_factor(r, s) : 1.0;

            for (e = 0; e < m; e++){
                dst[e] = f * src[e];
            }

            sshelp_next_dir(r, s, k);

        } // end for

    } // end for

    sshelp_rank_tab_free(&tab);

    oarr_set_act_order(out, (k == 0) ? 0 : act_r);

    return dnou_finish(DN_OK, alias, &tmp, res);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oarr_extract_im_to(imdir_t idx, ord_t order, const oarr_t* arr, oarr_t* res){

    DNOB_IN1(arr, res, oarr_extract_im_to(idx, order, c_.in[0], c_.res));

    return dnou_extract_common(idx, order, arr, 0, res);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oarr_extract_deriv_to(imdir_t idx, ord_t order, const oarr_t* arr, oarr_t* res){

    DNOB_IN1(arr, res, oarr_extract_deriv_to(idx, order, c_.in[0], c_.res));

    return dnou_extract_common(idx, order, arr, 1, res);

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// ---------------------------------------     TRUNCATED ALGEBRA     -------------------------------------
// -------------------------------------------------------------------------------------------------------

// *******************************************************************************************************
int oarr_trunc_matmul_OO_to(ord_t orda, const oarr_t* A, ord_t ordb, const oarr_t* B,
                            oarr_t* res, dhelpl_t dhl){

    DNOB_IN2(A, B, res, oarr_trunc_matmul_OO_to(orda, c_.in[0], ordb, c_.in[1], c_.res, dhl));

    uint64_t nrows = oarr_nrows(A), ninner = oarr_ncols(A), ncols = oarr_ncols(B);
    uint64_t sa = nrows * ninner, sb = ninner * ncols, sr = nrows * ncols, e;
    bases_t nu = (oarr_nact(A) > oarr_nact(B)) ? oarr_nact(A) : oarr_nact(B);
    ord_t trc = (oarr_trc_order(A) > oarr_trc_order(B)) ? oarr_trc_order(A) : oarr_trc_order(B);
    unsigned ordr = (unsigned)orda + ordb;
    ndir_t Na = 0, Nb = 0, i, j;
    const coeff_t *Ea = NULL, *Eb = NULL;
    coeff_t *work = NULL, *R;
    oarr_t tmp = oarr_init(), *out;
    int alias = dnou_alias(res, A) || dnou_alias(res, B), status;
    dnok_pairsrc_t src;
    bases_t ui[256], uj[256];

    if (!dnob_is_matrix(A) || !dnob_is_matrix(B) || oarr_ncols(A) != oarr_nrows(B)){
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
            Ea = oarr_data(A);

        } else if (orda <= dnou_top(A)){

            Na = sshelp_ndir_order(oarr_nact(A), orda);
            Ea = oarr_data(A) + oarr_block_index(oarr_nact(A), orda, 0) * sa;

        }

        if (ordb == 0){

            Nb = 1;
            Eb = oarr_data(B);

        } else if (ordb <= dnou_top(B)){

            Nb = sshelp_ndir_order(oarr_nact(B), ordb);
            Eb = oarr_data(B) + oarr_block_index(oarr_nact(B), ordb, 0) * sb;

        }

        if (!oti_lapack_fits(ncols * Nb)){
            return DN_ERR_SIZE;
        }

    }

    status = dnou_target2(res, alias, &tmp, nu, nrows, ncols, trc, &out);

    if (status != DN_OK){
        return dnou_finish(status, alias, &tmp, res);
    }

    if (Ea != NULL && Eb != NULL && Na > 0 && Nb > 0 && sr > 0 && ninner > 0){

        R = oarr_data(out) + oarr_block_index(nu, (ord_t)ordr, 0) * sr;

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

        oarr_set_act_order(out, (ord_t)ordr);

    } // end if

    return dnou_finish(DN_OK, alias, &tmp, res);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oarr_trunc_sub_OO_to(ord_t order, const oarr_t* A, const oarr_t* B, oarr_t* res){

    DNOB_IN2(A, B, res, oarr_trunc_sub_OO_to(order, c_.in[0], c_.in[1], c_.res));

    bases_t nu = (oarr_nact(A) > oarr_nact(B)) ? oarr_nact(A) : oarr_nact(B);
    ord_t trc = (oarr_trc_order(A) > oarr_trc_order(B)) ? oarr_trc_order(A) : oarr_trc_order(B);
    uint64_t m = oarr_size(A), e, i, n;
    oarr_t tmp = oarr_init(), *out;
    int alias = dnou_alias(res, A) || dnou_alias(res, B), status;
    const coeff_t* S;
    coeff_t* D;

    if (!dnob_same_shape(A, B)){
        return DN_ERR_SIZE;
    }

    status = dnou_target(res, alias, &tmp, nu, A, trc, &out);

    if (status != DN_OK){
        return dnou_finish(status, alias, &tmp, res);
    }

    if (order == 0){

        for (e = 0; e < m; e++){
            oarr_data(out)[e] = oarr_data(A)[e] - oarr_data(B)[e];
        }

    } else if (order <= trc && nu > 0){

        D = oarr_data(out) + oarr_block_index(nu, order, 0) * m;

        if (order <= dnou_top(A) && oarr_nact(A) > 0){

            n = sshelp_ndir_order(oarr_nact(A), order);
            S = oarr_data(A) + oarr_block_index(oarr_nact(A), order, 0) * m;

            for (i = 0; i < n * m; i++){
                D[i] += S[i];
            }

        }

        if (order <= dnou_top(B) && oarr_nact(B) > 0){

            n = sshelp_ndir_order(oarr_nact(B), order);
            S = oarr_data(B) + oarr_block_index(oarr_nact(B), order, 0) * m;

            for (i = 0; i < n * m; i++){
                D[i] -= S[i];
            }

        }

        oarr_set_act_order(out, order);

    } // end if

    return dnou_finish(DN_OK, alias, &tmp, res);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oarr_dot_product_OO_to(const oarr_t* A, const oarr_t* B, otinum_t* res, dhelpl_t dhl){

    DNOB_IN2(A, B, NULL, oarr_dot_product_OO_to(c_.in[0], c_.in[1], res, dhl));

    uint64_t m = oarr_size(A), e;
    bases_t nu = (oarr_nact(A) > oarr_nact(B)) ? oarr_nact(A) : oarr_nact(B);
    ord_t trc = (oarr_trc_order(A) > oarr_trc_order(B)) ? oarr_trc_order(A) : oarr_trc_order(B);
    ord_t atop = dnou_top(A), btop = dnou_top(B), p, q;
    otinum_t tmp = oti_init();
    coeff_t s, re;
    int status;

    if (oarr_size(A) != oarr_size(B)){
        return DN_ERR_SIZE;
    }

    status = oti_create_empty_to(nu, trc, &tmp);

    if (status != DN_OK){
        return status;
    }

    re = 0.0;

    for (e = 0; e < m; e++){
        re += oarr_data(A)[e] * oarr_data(B)[e];
    }

    tmp.re = re;

    for (p = 0; p <= atop; p++){

        ndir_t Np = (p == 0) ? 1 : sshelp_ndir_order(oarr_nact(A), p), i, j;
        uint64_t bp = oarr_block_index(oarr_nact(A), p, 0);

        for (q = 0; q <= btop && p + q <= trc; q++){

            ndir_t Nq = (q == 0) ? 1 : sshelp_ndir_order(oarr_nact(B), q);
            uint64_t bq = oarr_block_index(oarr_nact(B), q, 0);
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

                const coeff_t* Ai = oarr_data(A) + (bp + i) * m;

                if (!dnou_zero(Ai, m)){

                    dnok_tuple_reset(uj, q);

                    for (j = 0; j < Nq; j++){

                        const coeff_t* Bj = oarr_data(B) + (bq + j) * m;

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

    DNOB_IN1(arr, res, oarr_rom_eval_to(c_.in[0], deltas, c_.res));

    bases_t k = oarr_nact(arr), u[256];
    uint64_t m = oarr_size(arr), e, bp;
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
        memcpy(val, oarr_data(arr), (size_t)m * sizeof(coeff_t));
    }

    for (p = 1; p <= top; p++){

        ndir_t Np = sshelp_ndir_order(k, p), j;

        bp = oarr_block_index(k, p, 0);
        memset(u, 0, (size_t)p * sizeof(bases_t));

        for (j = 0; j < Np; j++){

            const coeff_t* blk = oarr_data(arr) + (bp + j) * m;
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
    status = oarr_zeros_nd_to(0, oarr_ndim(arr), arr->blocks.shape + 1, ND_LAYOUT_F, 0, res);

    if (status == DN_OK && m > 0){
        memcpy(oarr_data(res), val, (size_t)m * sizeof(coeff_t));
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

    DNOB_IN1(arr, NULL, oarr_get_all_ims_to(c_.in[0], nbasis, order, derivs, out));

    bases_t k = oarr_nact(arr), kk = (oarr_nact(arr) < nbasis) ? oarr_nact(arr) : nbasis, u[256];
    uint64_t m = oarr_size(arr), nr = oarr_nrows(arr), nc = oarr_ncols(arr), bs, d0;
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
    dnou_block_to_rowmajor(oarr_data(arr), nr, nc, 1.0, out, nc);

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

            dnou_block_to_rowmajor(oarr_data(arr) + (bs + j) * m, nr, nc, f, out + (d0 + j) * m, nc);

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

    bases_t k = oarr_nact(arr);
    uint64_t m = oarr_size(arr), bp;
    ndir_t Np, j;

    if (p == 0 || p > dnou_top(arr) || k == 0){
        return 0;
    }

    // A view is read through a canonical copy.
    if (!dnob_canon(arr)){

        oarr_t t = oarr_init();
        dnob_shape_t S = dnob_shape_of(arr);
        bases_t b = 0;

        S.layout = ND_LAYOUT_F;

        if (dnob_pack(arr, &S, &t) == DN_OK){
            b = oarr_order_max_base(p, &t);
        }

        oarr_free(&t);

        return b;

    }

    Np = sshelp_ndir_order(k, p);
    bp = oarr_block_index(k, p, 0);

    // Colex order: the last nonzero direction has the largest last (= largest) base.
    for (j = Np; j > 0; j--){

        if (!dnou_zero(oarr_data(arr) + (bp + j - 1) * m, m)){
            return dnsb_max_base(j - 1, p);
        }

    }

    return 0;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oarr_get_order_im_array_to(ord_t p, const oarr_t* arr, ndir_t width, coeff_t* out){

    DNOB_IN1(arr, NULL, oarr_get_order_im_array_to(p, c_.in[0], width, out));

    bases_t k = oarr_nact(arr);
    uint64_t m = oarr_size(arr), nr = oarr_nrows(arr), nc = oarr_ncols(arr), ldo = nc * width, bp;
    ndir_t Np, j;

    if (width != 0 && (ldo / width != nc || m > SIZE_MAX / sizeof(coeff_t) / width)){
        return DN_ERR_MEMORY;
    }

    memset(out, 0, (size_t)(m * width) * sizeof(coeff_t));

    if (width == 0){
        return DN_OK;
    }

    if (p == 0){

        dnou_block_to_rowmajor(oarr_data(arr), nr, nc, 1.0, out, ldo);
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
        dnou_block_to_rowmajor(oarr_data(arr) + (bp + j) * m, nr, nc, 1.0, out + nc * (uint64_t)j, ldo);
    }

    return DN_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oarr_add_order_im_array(ord_t p, const coeff_t* vals, ndir_t width, oarr_t* arr){

    DNOB_INPLACE(arr, oarr_add_order_im_array(p, vals, width, c_.res));

    uint64_t nr = oarr_nrows(arr), nc = oarr_ncols(arr), ldi = nc * width, r, c, bp;
    ndir_t g, gmax = 0;
    bases_t gl[256], k;
    coeff_t* blk;
    int any = 0, status;

    if (width == 0 || oarr_size(arr) == 0){
        return DN_OK;
    }

    if (p == 0){

        for (r = 0; r < nr; r++){

            for (c = 0; c < nc; c++){
                oarr_data(arr)[r + c * nr] += vals[r * ldi + c];
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

    k = (gl[p - 1] > oarr_nact(arr)) ? gl[p - 1] : oarr_nact(arr);

    // The sparse sum takes the larger truncation order; capacity for the new layout first.
    status = oarr_reserve(arr, k, nr, nc, p);

    if (status == DN_OK){
        status = oarr_add_bases(k, arr);
    }

    if (status != DN_OK){
        return status;
    }

    bp = oarr_block_index(oarr_nact(arr), p, 0);

    for (g = 0; g <= gmax; g++){

        blk = oarr_data(arr) + (bp + g) * oarr_size(arr);

        for (r = 0; r < nr; r++){

            for (c = 0; c < nc; c++){
                blk[r + c * nr] += vals[r * ldi + c + nc * (uint64_t)g];
            }

        }

    } // end for

    if (oarr_act_order(arr) < p){
        oarr_set_act_order(arr, p);
    }

    return DN_OK;

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// ---------------------------------------     FILTERS AND INTERPOLATION     -----------------------------
// -------------------------------------------------------------------------------------------------------

// *******************************************************************************************************
int oarr_moving_average_to(const oarr_t* arr, uint64_t size, oarr_t* res){

    DNOB_IN1(arr, res, oarr_moving_average_to(c_.in[0], size, c_.res));

    uint64_t n = oarr_size(arr), k, j, b, nblocks;
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
    nblocks = 1 + sshelp_ndir_total(oarr_nact(arr), top);

    // res may alias arr: the result is then built in a call-local array.
    status = dnou_target2(res, alias, &tmp, oarr_nact(arr), n, 1, oarr_trc_order(arr), &out);

    if (status != DN_OK){
        return dnou_finish(status, alias, &tmp, res);
    }

    // Same operation order as the sparse filter, so every coefficient matches it exactly.
    for (b = 0; b < nblocks; b++){

        const coeff_t* src = oarr_data(arr) + b * n;
        coeff_t* dst = oarr_data(out) + b * n;

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

    oarr_set_act_order(out, oarr_act_order(arr));

    return dnou_finish(DN_OK, alias, &tmp, res);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oarr_interp1d_o_to(const oarr_t* xvals, const oarr_t* yvals, const otinum_t* x, otinum_t* res,
                       dhelpl_t dhl){

    DNOB_IN2(xvals, yvals, NULL, oarr_interp1d_o_to(c_.in[0], c_.in[1], x, res, dhl));

    uint64_t n = oarr_nrows(xvals), start, finish, mid, rang;
    const coeff_t* xr = oarr_data(xvals);
    coeff_t xv = x->re;
    otinum_t y0 = oti_init(), y1 = oti_init(), x0 = oti_init(), x1 = oti_init(), dy = oti_init();
    otinum_t dx = oti_init(), slope = oti_init(), t = oti_init();
    int status;

    if (n == 0 || oarr_size(xvals) == 0 || oarr_nrows(yvals) < n || oarr_ncols(yvals) == 0){
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

    DNOB_IN3(xvals, yvals, X, res, oarr_interp1d_O_to(c_.in[0], c_.in[1], c_.in[2], c_.res, dhl));

    ord_t trc = oarr_trc_order(X);
    otinum_t xe = oti_init(), ye = oti_init();
    uint64_t e, m;
    oarr_t tmp = oarr_init(), *out;
    int alias = dnou_alias(res, X) || dnou_alias(res, xvals) || dnou_alias(res, yvals), status;

    if (oarr_trc_order(xvals) > trc){
        trc = oarr_trc_order(xvals);
    }

    if (oarr_trc_order(yvals) > trc){
        trc = oarr_trc_order(yvals);
    }

    // res may alias X, xvals or yvals: the result is then built in a call-local array. Elements in flat
    // F order (X is canonical, any rank).
    status = dnou_target(res, alias, &tmp, 0, X, trc, &out);
    m      = oarr_size(X);

    for (e = 0; e < m && status == DN_OK; e++){

        nd_index_t key[OTI_ND_MAXDIM];
        int64_t index[OTI_ND_MAXDIM];
        int32_t d;

        dnob_unflat(X, e, index);
        status = oarr_get_elem_to(X, oarr_ndim(X), index, &xe);

        if (status == DN_OK){
            status = oarr_interp1d_o_to(xvals, yvals, &xe, &ye, dhl);
        }

        for (d = 0; d < oarr_ndim(X); d++){

            key[d].kind  = ND_IDX_INT;
            key[d].has   = 0;
            key[d].start = index[d];
            key[d].stop  = 0;
            key[d].step  = 0;
            key[d].arr   = NULL;

        }

        if (status == DN_OK){
            status = oarr_index_set_o(out, oarr_ndim(X), key, &ye);
        }

    } // end for

    oti_free(&xe);
    oti_free(&ye);

    return dnou_finish(status, alias, &tmp, res);

}
// -------------------------------------------------------------------------------------------------------
