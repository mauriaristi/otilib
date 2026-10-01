// Dense Gauss-point types, SoA batched over integration points (include/oti/dense/gauss/gauss.h).
// Template: src/c/semisparse/gauss/gauss.c.
//
// A feoarr_t embeds one oarr_t of shape nip x (nrows * ncols). Everything elementwise is the oarr_t
// operation on it; this file adds point and entry access, broadcasts, per-point matrix products, dot
// products, integration, det and inv. An operand over fewer bases is a prefix of the larger layout, so
// it is read in place at its own block offsets (no expansion). Products on reinterpreted shapes pass a
// view: a struct copy of an oarr_t with another (nrows, ncols) pointing at the same p_data, only ever
// used as an input. Unity-included from src/c/dense.c: static helpers carry the dngs_ prefix; reuses
// dnob_result_shape() / dnob_shape_size() of soa/base.c and the dnok_pairsrc_* product-index sources
// of soa/kernels.c. Every scratch buffer is allocated and freed within the call.


// *******************************************************************************************************
// Number of direction blocks (the real one included) of an array.
static inline uint64_t dngs_nblocks(const oarr_t* a){

    return 1 + (uint64_t)sshelp_ndir_total(a->nact, a->trc_order);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// act_order of an array as a bound on its nonzero orders (0 for a real array).
static inline ord_t dngs_act(const oarr_t* a){

    return (a->nact == 0) ? 0 : a->act_order;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Replaces *res by *tmp (moving its buffers) and resets *tmp.
static void dngs_move(feoarr_t* tmp, feoarr_t* res){

    fearr_free(res);
    *res = *tmp;
    *tmp = fearr_init();

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Tells whether every index start + t*step, t < count, lies in [0, bound), without overflow: an
// arithmetic progression is in range when its two ends are. An empty progression is in range.
static int dngs_range_ok(uint64_t start, uint64_t count, int64_t step, uint64_t bound){

    uint64_t mag, span;

    if (count == 0){
        return 1;
    }

    if (start >= bound){
        return 0;
    }

    if (step == 0 || count == 1){
        return 1;
    }

    // |step| without overflow (also for INT64_MIN).
    mag = (step > 0) ? (uint64_t)step : (uint64_t)(-(step + 1)) + 1;

    // Room left from start in the step's direction, in steps: count - 1 must fit.
    span = (step > 0) ? (bound - 1 - start) / mag : start / mag;

    return count - 1 <= span;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Column list of a strided block: cols[ii + jj*ni] = i + j*nrows for row i0 + ii*istep and column
// j0 + jj*jstep. *p_cols is allocated (release with free()). The ranges are checked before anything is
// allocated: DN_ERR_INDEX when an entry is outside, DN_ERR_MEMORY when the list cannot be allocated.
static int dngs_block_cols(uint64_t nrows, uint64_t ncols, uint64_t i0, uint64_t ni, int64_t istep,
                           uint64_t j0, uint64_t nj, int64_t jstep, uint64_t** p_cols){

    uint64_t n, ii, jj, i, j, *cols;

    *p_cols = NULL;

    if (!dngs_range_ok(i0, (nj > 0) ? ni : 0, istep, nrows)
        || !dngs_range_ok(j0, (ni > 0) ? nj : 0, jstep, ncols)){
        return DN_ERR_INDEX;
    }

    if (dnob_shape_size(ni, nj, &n) != DN_OK || n > SIZE_MAX / sizeof(uint64_t) - 1){
        return DN_ERR_MEMORY;
    }

    cols = (uint64_t*)malloc((size_t)n * sizeof(uint64_t) + 1);

    if (cols == NULL){
        return DN_ERR_MEMORY;
    }

    // In range, so the unsigned (wrapping) arithmetic gives the exact index.
    for (jj = 0; jj < nj; jj++){

        j = j0 + jj * (uint64_t)jstep;

        for (ii = 0; ii < ni; ii++){

            i = i0 + ii * (uint64_t)istep;
            cols[ii + jj * ni] = i + j * nrows;

        }

    }

    *p_cols = cols;

    return DN_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// res (nip x n) = columns cols[0..n) of a (nip x *), same nact and orders (cols NULL: all zeros, i.e.
// column 0 repeated). res must not alias a.
static int dngs_gather_cols(const oarr_t* a, const uint64_t* cols, uint64_t n, oarr_t* res){

    uint64_t nip = a->nrows, nb = dngs_nblocks(a), d, c, cs;
    size_t nreal;
    int status = dnob_result_shape(res, a->nact, nip, n, a->trc_order, &nreal);

    if (status != DN_OK){
        return status;
    }

    res->act_order = a->act_order;

    for (d = 0; d < nb; d++){

        for (c = 0; c < n; c++){

            cs = (cols == NULL) ? 0 : cols[c];
            memcpy(res->p_data + d * res->size + c * nip, a->p_data + d * a->size + cs * nip,
                (size_t)nip * sizeof(coeff_t));

        }

    }

    return DN_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Grows an array in place to at least (nact, trc), keeping its values.
static int dngs_grow_arr(bases_t nact, ord_t trc, oarr_t* arr){

    int status;

    if (trc > arr->trc_order){

        status = oarr_reserve(arr, arr->nact, arr->nrows, arr->ncols, trc);

        if (status != DN_OK){
            return status;
        }

    }

    return oarr_add_bases(nact, arr);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Overwrites entries of dst with entries of src, both nip x * with the same nip: column dst_cols[c]
// (a point offset `ip` and stride `step` inside it, for ns values) receives column src_cols[c]
// (identity when NULL) of src, for c < n. dst grows to src's nact and order first; directions src does
// not have are written as zeros. src != dst.
//
// With step = 1 and ns = nip whole columns move; with ns = 1 one point (ip) of each column moves, src
// then being a plain array whose column c holds that point's value (src->nrows == 1).
static int dngs_scatter(const oarr_t* src, const uint64_t* src_cols, const uint64_t* dst_cols,
                        uint64_t n, uint64_t ip, uint64_t ns, oarr_t* dst){

    uint64_t bs, bd, c, cs, t, ms, md;
    ndir_t i, Ns, Nd;
    ord_t p, act = dngs_act(src);
    const coeff_t* S;
    coeff_t* D;
    int status = dngs_grow_arr(src->nact, src->trc_order, dst);

    if (status != DN_OK){
        return status;
    }

    ms = src->nrows;
    md = dst->nrows;

    for (p = 0; p <= dst->trc_order; p++){

        // Block offsets once per order.
        bd = oarr_block_index(dst->nact, p, 0);
        bs = oarr_block_index(src->nact, p, 0);
        Nd = sshelp_ndir_order(dst->nact, p);
        Ns = (p <= src->trc_order) ? sshelp_ndir_order(src->nact, p) : 0;

        for (i = 0; i < Nd; i++){

            D = dst->p_data + (bd + i) * dst->size;

            for (c = 0; c < n; c++){

                coeff_t* Dc = D + dst_cols[c] * md + ip;

                if (i < Ns){

                    cs = (src_cols == NULL) ? c : src_cols[c];
                    S  = src->p_data + (bs + i) * src->size + cs * ms;

                    for (t = 0; t < ns; t++){
                        Dc[t] = S[t];
                    }

                } else {

                    for (t = 0; t < ns; t++){
                        Dc[t] = 0.0;
                    }

                }

            }

        }

    }

    if (act > dst->act_order){
        dst->act_order = act;
    }

    return DN_OK;

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// ---------------------------------------     MEMORY     ------------------------------------------------
// -------------------------------------------------------------------------------------------------------

// *******************************************************************************************************
feoarr_t fearr_init(void){

    feoarr_t fe;

    fe.arr   = oarr_init();
    fe.nrows = 0;
    fe.ncols = 0;
    fe.nip   = 0;

    return fe;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int fearr_zeros_to(bases_t nact, uint64_t nrows, uint64_t ncols, uint64_t nip, ord_t trc_order,
                   feoarr_t* res){

    uint64_t m;
    int status;

    if (dnob_shape_size(nrows, ncols, &m) != DN_OK){
        return DN_ERR_MEMORY;
    }

    status = oarr_zeros_to(nact, nip, m, trc_order, &res->arr);

    if (status != DN_OK){
        return status;
    }

    res->nrows = nrows;
    res->ncols = ncols;
    res->nip   = nip;

    return DN_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void fearr_free(feoarr_t* fe){

    oarr_free(&fe->arr);
    *fe = fearr_init();

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int fearr_copy_to(const feoarr_t* fe, feoarr_t* res){

    int status;

    if (fe == res){
        return DN_OK;
    }

    status = oarr_copy_to(&fe->arr, &res->arr);

    if (status != DN_OK){
        return status;
    }

    res->nrows = fe->nrows;
    res->ncols = fe->ncols;
    res->nip   = fe->nip;

    return DN_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int fearr_grow(bases_t nact, ord_t trc_order, feoarr_t* fe){

    return dngs_grow_arr(nact, trc_order, &fe->arr);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int fearr_set_shape(uint64_t nrows, uint64_t ncols, uint64_t nip, feoarr_t* fe){

    uint64_t m;

    if (dnob_shape_size(nrows, ncols, &m) != DN_OK || fe->arr.nrows != nip || fe->arr.ncols != m){
        return DN_ERR_SIZE;
    }

    fe->nrows = nrows;
    fe->ncols = ncols;
    fe->nip   = nip;

    return DN_OK;

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// ---------------------------------------     ACCESS     ------------------------------------------------
// -------------------------------------------------------------------------------------------------------

// *******************************************************************************************************
int fearr_get_ip_to(uint64_t ip, const feoarr_t* fe, oarr_t* res){

    const oarr_t* a = &fe->arr;
    uint64_t nip = fe->nip, m = a->ncols, nb = dngs_nblocks(a), d, e;
    const coeff_t* S;
    coeff_t* D;
    size_t nreal;
    int status;

    if (ip >= nip){
        return DN_ERR_INDEX;
    }

    if (res == a){
        return DN_ERR_ARGUMENT;
    }

    status = dnob_result_shape(res, a->nact, fe->nrows, fe->ncols, a->trc_order, &nreal);

    if (status != DN_OK){
        return status;
    }

    res->act_order = a->act_order;

    for (d = 0; d < nb; d++){

        S = a->p_data + d * a->size + ip;
        D = res->p_data + d * m;

        for (e = 0; e < m; e++){
            D[e] = S[e * nip];
        }

    }

    return DN_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int fearr_set_ip(const oarr_t* val, uint64_t ip, feoarr_t* fe){

    oarr_t row;
    uint64_t *cols, e, m = fe->arr.ncols;
    int status;

    if (val->nrows != fe->nrows || val->ncols != fe->ncols){
        return DN_ERR_SIZE;
    }

    if (ip >= fe->nip){
        return DN_ERR_INDEX;
    }

    if (val == &fe->arr){
        return DN_ERR_ARGUMENT;
    }

    // val's m column-major entries, read as a 1 x m row: its column e goes to point ip of column e.
    row       = *val;
    row.nrows = 1;
    row.ncols = m;

    cols = (uint64_t*)malloc((size_t)m * sizeof(uint64_t) + 1);

    if (cols == NULL){
        return DN_ERR_MEMORY;
    }

    for (e = 0; e < m; e++){
        cols[e] = e;
    }

    status = dngs_scatter(&row, NULL, cols, m, ip, 1, &fe->arr);

    free(cols);

    return status;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int fearr_get_slice_to(const feoarr_t* fe, uint64_t i0, uint64_t ni, int64_t istep,
                       uint64_t j0, uint64_t nj, int64_t jstep, feoarr_t* res){

    uint64_t* cols;
    int status;

    if (res == fe){
        return DN_ERR_ARGUMENT;
    }

    status = dngs_block_cols(fe->nrows, fe->ncols, i0, ni, istep, j0, nj, jstep, &cols);

    if (status == DN_OK){
        status = dngs_gather_cols(&fe->arr, cols, ni * nj, &res->arr);
    }

    if (status == DN_OK){

        res->nrows = ni;
        res->ncols = nj;
        res->nip   = fe->nip;

    }

    free(cols);

    return status;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int fearr_set_slice(const feoarr_t* val, uint64_t i0, uint64_t ni, int64_t istep, uint64_t j0,
                    uint64_t nj, int64_t jstep, feoarr_t* fe){

    uint64_t n, c;
    uint64_t *dst_cols, *src_cols = NULL;
    int bcast = (val->nrows == 1 && val->ncols == 1 && (ni != 1 || nj != 1));
    int status;

    if (val == fe){
        return DN_ERR_ARGUMENT;
    }

    if (val->nip != fe->nip || (!bcast && (val->nrows != ni || val->ncols != nj))){
        return DN_ERR_SIZE;
    }

    // An empty slice assigns nothing (and so grows nothing).
    if (ni == 0 || nj == 0){
        return DN_OK;
    }

    status = dngs_block_cols(fe->nrows, fe->ncols, i0, ni, istep, j0, nj, jstep, &dst_cols);

    if (status != DN_OK){
        return status;
    }

    // In range: ni and nj are bounded (or the list was allocated), so the product fits.
    n = ni * nj;

    // A 1 x 1 value is column 0 of val for every destination entry.
    if (bcast){

        src_cols = (uint64_t*)malloc((size_t)n * sizeof(uint64_t) + 1);

        if (src_cols == NULL){

            free(dst_cols);
            return DN_ERR_MEMORY;

        }

        for (c = 0; c < n; c++){
            src_cols[c] = 0;
        }

    }

    status = dngs_scatter(&val->arr, src_cols, dst_cols, n, 0, fe->nip, &fe->arr);

    free(dst_cols);
    free(src_cols);

    return status;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int fearr_set_ijk_o(const otinum_t* num, uint64_t i, uint64_t j, uint64_t ip,
                    feoarr_t* fe){

    if (i >= fe->nrows || j >= fe->ncols || ip >= fe->nip){
        return DN_ERR_INDEX;
    }

    return oarr_set_item(num, ip, i + j * fe->nrows, &fe->arr);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int fearr_set_ijk_r(coeff_t val, uint64_t i, uint64_t j, uint64_t ip, feoarr_t* fe){

    if (i >= fe->nrows || j >= fe->ncols || ip >= fe->nip){
        return DN_ERR_INDEX;
    }

    return oarr_set_item_r(val, ip, i + j * fe->nrows, &fe->arr);

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// ---------------------------------------     BROADCASTS     --------------------------------------------
// -------------------------------------------------------------------------------------------------------

// *******************************************************************************************************
int fearr_from_oarr_to(const oarr_t* arr, uint64_t nip, feoarr_t* res){

    uint64_t nb = dngs_nblocks(arr), m = arr->size, d, e, t;
    feoarr_t tmp = fearr_init();
    feoarr_t* out = (arr == &res->arr) ? &tmp : res;
    const coeff_t* S;
    coeff_t* D;
    size_t nreal;
    int status = dnob_result_shape(&out->arr, arr->nact, nip, m, arr->trc_order, &nreal);

    if (status != DN_OK){
        return status;
    }

    out->arr.act_order = arr->act_order;

    for (d = 0; d < nb; d++){

        S = arr->p_data + d * m;
        D = out->arr.p_data + d * out->arr.size;

        for (e = 0; e < m; e++){

            for (t = 0; t < nip; t++){
                D[e * nip + t] = S[e];
            }

        }

    }

    out->nrows = arr->nrows;
    out->ncols = arr->ncols;
    out->nip   = nip;

    if (out == &tmp){
        dngs_move(&tmp, res);
    }

    return DN_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int fearr_bcast_to(const feoarr_t* num, uint64_t nrows, uint64_t ncols, feoarr_t* res){

    uint64_t n;
    int status;

    if (num == res){
        return DN_ERR_ARGUMENT;
    }

    if (num->nrows != 1 || num->ncols != 1 || dnob_shape_size(nrows, ncols, &n) != DN_OK){
        return DN_ERR_SIZE;
    }

    status = dngs_gather_cols(&num->arr, NULL, n, &res->arr);

    if (status == DN_OK){

        res->nrows = nrows;
        res->ncols = ncols;
        res->nip   = num->nip;

    }

    return status;

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// ---------------------------------------     LINEAR ALGEBRA     ----------------------------------------
// -------------------------------------------------------------------------------------------------------

// *******************************************************************************************************
int fearr_transpose_to(const feoarr_t* fe, feoarr_t* res){

    uint64_t n = fe->nrows, m = fe->ncols, r, c, nm;
    uint64_t* cols;
    feoarr_t tmp = fearr_init();
    int status;

    if (dnob_shape_size(n, m, &nm) != DN_OK || nm > SIZE_MAX / sizeof(uint64_t) - 1){
        return DN_ERR_MEMORY;
    }

    cols = (uint64_t*)malloc((size_t)nm * sizeof(uint64_t) + 1);

    if (cols == NULL){
        return DN_ERR_MEMORY;
    }

    // Result entry (r, c), r < m, c < n, is entry (c, r) of fe.
    for (c = 0; c < n; c++){

        for (r = 0; r < m; r++){
            cols[r + c * m] = c + r * n;
        }

    }

    status = dngs_gather_cols(&fe->arr, cols, nm, &tmp.arr);

    if (status == DN_OK){

        tmp.nrows = m;
        tmp.ncols = n;
        tmp.nip   = fe->nip;
        dngs_move(&tmp, res);

    }

    fearr_free(&tmp);
    free(cols);

    return status;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Rc[t] += sum_s Ac[r + s*n][t] * Bc[s + c*q][t] for every point t: the per-point n x q times q x m
// product of one pair of direction blocks, accumulated into one result block.
static void dngs_block_matmul(const coeff_t* A, const coeff_t* B, uint64_t n, uint64_t q, uint64_t m,
                              uint64_t nip, coeff_t* R){

    uint64_t r, s, c, t;

    for (c = 0; c < m; c++){

        for (s = 0; s < q; s++){

            const coeff_t* Bc = B + (s + c * q) * nip;

            for (r = 0; r < n; r++){

                const coeff_t* Ac = A + (r + s * n) * nip;
                coeff_t* Rc = R + (r + c * n) * nip;

                for (t = 0; t < nip; t++){
                    Rc[t] += Ac[t] * Bc[t];
                }

            }

        }

    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int fearr_matmul_FF_to(const feoarr_t* a, const feoarr_t* b, feoarr_t* res, dhelpl_t dhl){

    uint64_t n = a->nrows, q = a->ncols, m = b->ncols, nip = a->nip, sa, sb, sr, bp, bq, bpq, nm;
    bases_t ka = a->arr.nact, kb = b->arr.nact, k = (ka > kb) ? ka : kb, ui[256], uj[256];
    ord_t trc = (a->arr.trc_order > b->arr.trc_order) ? a->arr.trc_order : b->arr.trc_order;
    ord_t atop = dngs_act(&a->arr), btop = dngs_act(&b->arr), p, pq;
    ndir_t i, j, Np, Nq;
    unsigned act;
    feoarr_t tmp = fearr_init();
    feoarr_t* out = (res == a || res == b) ? &tmp : res;
    dnok_pairsrc_t src;
    size_t nreal;
    int status;

    if (b->nrows != q || b->nip != nip){
        return DN_ERR_SIZE;
    }

    if (dnob_shape_size(n, m, &nm) != DN_OK){
        return DN_ERR_MEMORY;
    }

    status = dnob_result_shape(&out->arr, k, nip, nm, trc, &nreal);

    if (status != DN_OK){
        return status;
    }

    memset(out->arr.p_data, 0, nreal * sizeof(coeff_t));

    sa = a->arr.size;
    sb = b->arr.size;
    sr = out->arr.size;

    for (p = 0; p <= atop; p++){

        // Block offsets once per order (direction i of order p is block bp + i).
        bp = oarr_block_index(ka, p, 0);
        Np = sshelp_ndir_order(ka, p);

        for (pq = 0; pq <= btop && p + pq <= trc; pq++){

            bq  = oarr_block_index(kb, pq, 0);
            bpq = oarr_block_index(k, (ord_t)(p + pq), 0);
            Nq  = sshelp_ndir_order(kb, pq);
            src = dnok_pairsrc_init(k, p, pq, dhl);

            dnok_tuple_reset(ui, p);

            for (i = 0; i < Np; i++){

                const coeff_t* Ai = a->arr.p_data + (bp + i) * sa;

                if (!dnok_all_zero(Ai, sa)){

                    dnok_tuple_reset(uj, pq);

                    for (j = 0; j < Nq; j++){

                        dngs_block_matmul(Ai, b->arr.p_data + (bq + j) * sb, n, q, m, nip,
                            out->arr.p_data + (bpq + dnok_pair_idx(&src, i, ui, j, uj)) * sr);

                        if (pq > 0){
                            sshelp_next_dir(uj, pq, k);
                        }

                    }

                }

                if (p > 0){
                    sshelp_next_dir(ui, p, k);
                }

            }

            dnok_pairsrc_free(&src);

        }

    }

    act = (unsigned)atop + btop;
    out->arr.act_order = (k == 0) ? 0 : (ord_t)((act < trc) ? act : trc);
    out->nrows = n;
    out->ncols = m;
    out->nip   = nip;

    if (out == &tmp){
        dngs_move(&tmp, res);
    }

    return DN_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int fearr_matmul_FO_to(const feoarr_t* a, const oarr_t* b, feoarr_t* res, dhelpl_t dhl){

    uint64_t n = a->nrows, q = a->ncols, m = b->ncols, nip = a->nip, nn, nm;
    oarr_t av;
    feoarr_t out = fearr_init();
    int status;

    if (b->nrows != q){
        return DN_ERR_SIZE;
    }

    if (dnob_shape_size(nip, n, &nn) != DN_OK || dnob_shape_size(n, m, &nm) != DN_OK){
        return DN_ERR_MEMORY;
    }

    // a.arr (nip x n*q, column-major over (ip, r, s)) is the same memory as an (nip*n) x q matrix.
    av       = a->arr;
    av.nrows = nn;
    av.ncols = q;

    status = oarr_matmul_OO_to(&av, b, &out.arr, dhl);

    if (status != DN_OK){

        fearr_free(&out);
        return status;

    }

    // The (nip*n) x m product is the nip x (n*m) layout of the per-point results.
    out.arr.nrows = nip;
    out.arr.ncols = nm;
    out.nrows     = n;
    out.ncols     = m;
    out.nip       = nip;

    dngs_move(&out, res);

    return DN_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int fearr_matmul_OF_to(const oarr_t* a, const feoarr_t* b, feoarr_t* res, dhelpl_t dhl){

    feoarr_t bt = fearr_init(), rt = fearr_init();
    oarr_t at = oarr_init();
    int status;

    if (a->ncols != b->nrows){
        return DN_ERR_SIZE;
    }

    // (a b_ip)^T = b_ip^T a^T.
    status = fearr_transpose_to(b, &bt);

    if (status == DN_OK){
        status = oarr_transpose_to(a, &at, dhl);
    }

    if (status == DN_OK){
        status = fearr_matmul_FO_to(&bt, &at, &rt, dhl);
    }

    if (status == DN_OK){
        status = fearr_transpose_to(&rt, res);
    }

    fearr_free(&bt);
    fearr_free(&rt);
    oarr_free(&at);

    return status;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int fearr_dot_product_FO_to(const feoarr_t* a, const oarr_t* b, feoarr_t* res,
                            dhelpl_t dhl){

    uint64_t N = a->arr.ncols;
    oarr_t bv;
    feoarr_t out = fearr_init();
    int status;

    if (b->size != N){
        return DN_ERR_SIZE;
    }

    // b's column-major entries as an N x 1 vector.
    bv       = *b;
    bv.nrows = N;
    bv.ncols = 1;

    status = oarr_matmul_OO_to(&a->arr, &bv, &out.arr, dhl);

    if (status != DN_OK){

        fearr_free(&out);
        return status;

    }

    out.nrows = 1;
    out.ncols = 1;
    out.nip   = a->nip;
    dngs_move(&out, res);

    return DN_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int fearr_dot_product_FF_to(const feoarr_t* a, const feoarr_t* b, feoarr_t* res,
                            dhelpl_t dhl){

    uint64_t N = a->arr.ncols, nip = a->nip, nb, d, e, t;
    feoarr_t prod = fearr_init(), out = fearr_init();
    const coeff_t* S;
    coeff_t* D;
    int status;

    if (b->arr.ncols != N || b->nip != nip){
        return DN_ERR_SIZE;
    }

    status = oarr_mul_OO_to(&a->arr, &b->arr, &prod.arr, dhl);

    if (status == DN_OK){
        status = fearr_zeros_to(prod.arr.nact, 1, 1, nip, prod.arr.trc_order, &out);
    }

    if (status != DN_OK){

        fearr_free(&prod);
        fearr_free(&out);
        return status;

    }

    // Sum of the N columns of the product.
    nb = dngs_nblocks(&prod.arr);
    out.arr.act_order = prod.arr.act_order;

    for (d = 0; d < nb; d++){

        S = prod.arr.p_data + d * prod.arr.size;
        D = out.arr.p_data + d * nip;

        for (e = 0; e < N; e++){

            for (t = 0; t < nip; t++){
                D[t] += S[e * nip + t];
            }

        }

    }

    dngs_move(&out, res);
    fearr_free(&prod);

    return DN_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int fearr_integrate_to(const feoarr_t* val, const feoarr_t* w, oarr_t* res, dhelpl_t dhl){

    oarr_t wv;
    int status;

    if (w->nrows != 1 || w->ncols != 1 || w->nip != val->nip){
        return DN_ERR_SIZE;
    }

    // w (nip x 1) is the same memory as the 1 x nip row w^T.
    wv       = w->arr;
    wv.nrows = 1;
    wv.ncols = w->nip;

    status = oarr_matmul_OO_to(&wv, &val->arr, res, dhl);

    if (status != DN_OK){
        return status;
    }

    // The 1 x (nrows*ncols) row is the column-major nrows x ncols matrix.
    res->nrows = val->nrows;
    res->ncols = val->ncols;

    return DN_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// out = x * y - u * v (entry vectors over the points).
static int dngs_cross2(const oarr_t* x, const oarr_t* y, const oarr_t* u, const oarr_t* v, oarr_t* out,
                       dhelpl_t dhl){

    oarr_t t1 = oarr_init(), t2 = oarr_init();
    int status = oarr_mul_OO_to(x, y, &t1, dhl);

    if (status == DN_OK){
        status = oarr_mul_OO_to(u, v, &t2, dhl);
    }

    if (status == DN_OK){
        status = oarr_sub_OO_to(&t1, &t2, out, dhl);
    }

    oarr_free(&t1);
    oarr_free(&t2);

    return status;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Closed-form det (and, with inv != NULL, inverse) for 1 <= n <= 3, batched over the points: every
// entry is an nip x 1 array and the cofactors are products and differences of them.
static int dngs_closed_form(const feoarr_t* fe, feoarr_t* det, feoarr_t* inv, dhelpl_t dhl){

    uint64_t n = fe->nrows, r, c, r1, r2, c1, c2, col, nip = fe->nip;
    oarr_t E[9], C[9], d = oarr_init(), rd = oarr_init(), t = oarr_init();
    feoarr_t out = fearr_init();
    int status = DN_OK;

    for (r = 0; r < 9; r++){

        E[r] = oarr_init();
        C[r] = oarr_init();

    }

    for (c = 0; c < n && status == DN_OK; c++){

        for (r = 0; r < n && status == DN_OK; r++){

            col    = r + c * n;
            status = dngs_gather_cols(&fe->arr, &col, 1, &E[r + 3 * c]);

        }

    }

    // Cofactors C[r + 3c]; with them det = sum_c a_0c C_0c and inv_rc = C_cr / det.
    if (status == DN_OK && n == 1){

        status = oarr_copy_to(&E[0], &d);

        if (status == DN_OK){
            status = oarr_zeros_to(0, nip, 1, 0, &C[0]);
        }

        for (r = 0; status == DN_OK && r < nip; r++){
            C[0].p_data[r] = 1.0;
        }

    } else if (status == DN_OK && n == 2){

        status = oarr_copy_to(&E[1 + 3], &C[0]);                               // C00 =  a11

        if (status == DN_OK){ status = oarr_neg_to(&E[1], &C[3], dhl); }        // C01 = -a10
        if (status == DN_OK){ status = oarr_neg_to(&E[3], &C[1], dhl); }        // C10 = -a01
        if (status == DN_OK){ status = oarr_copy_to(&E[0], &C[1 + 3]); }        // C11 =  a00
        if (status == DN_OK){ status = dngs_cross2(&E[0], &E[1 + 3], &E[3], &E[1], &d, dhl); }

    } else if (status == DN_OK){

        for (r = 0; r < 3 && status == DN_OK; r++){

            r1 = (r + 1) % 3;
            r2 = (r + 2) % 3;

            for (c = 0; c < 3 && status == DN_OK; c++){

                c1 = (c + 1) % 3;
                c2 = (c + 2) % 3;
                status = dngs_cross2(&E[r1 + 3 * c1], &E[r2 + 3 * c2], &E[r1 + 3 * c2],
                                     &E[r2 + 3 * c1], &C[r + 3 * c], dhl);

            }

        }

        if (status == DN_OK){
            status = oarr_mul_OO_to(&E[0], &C[0], &d, dhl);
        }

        for (c = 1; c < 3 && status == DN_OK; c++){

            status = oarr_mul_OO_to(&E[3 * c], &C[3 * c], &t, dhl);

            if (status == DN_OK){
                status = oarr_sum_OO_to(&d, &t, &d, dhl);
            }

        }

    }

    if (status == DN_OK && det != NULL){

        status = oarr_copy_to(&d, &out.arr);

        if (status == DN_OK){

            // act_order of a determinant is trc (0 for a real result), as on the LU path, not the
            // tighter product bound of the cofactor expansion.
            out.arr.act_order = (out.arr.nact == 0) ? 0 : out.arr.trc_order;
            out.nrows = 1;
            out.ncols = 1;
            out.nip   = nip;
            dngs_move(&out, det);

        }

    }

    if (status == DN_OK && inv != NULL){

        status = fearr_zeros_to(0, n, n, nip, 0, &out);

        if (status == DN_OK){
            status = oarr_div_rO_to(1.0, &d, &rd, dhl);
        }

        for (c = 0; c < n && status == DN_OK; c++){

            for (r = 0; r < n && status == DN_OK; r++){

                col    = r + c * n;
                status = oarr_mul_OO_to(&C[c + 3 * r], &rd, &t, dhl);

                if (status == DN_OK){
                    status = dngs_scatter(&t, NULL, &col, 1, 0, nip, &out.arr);
                }

            }

        }

        if (status == DN_OK){
            dngs_move(&out, inv);
        }

    }

    for (r = 0; r < 9; r++){

        oarr_free(&E[r]);
        oarr_free(&C[r]);

    }

    oarr_free(&d);
    oarr_free(&rd);
    oarr_free(&t);
    fearr_free(&out);

    return status;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int fearr_det_to(const feoarr_t* fe, feoarr_t* res, dhelpl_t dhl){

    uint64_t n = fe->nrows, ip;
    feoarr_t out = fearr_init();
    oarr_t A = oarr_init();
    otinum_t dnum = oti_init();
    int status;

    if (fe->ncols != n){
        return DN_ERR_SIZE;
    }

    if (n >= 1 && n <= 3){
        return dngs_closed_form(fe, res, NULL, dhl);
    }

    // n = 0 gives det 1 at every point (the empty product); n > 3 is an LU per point. The result keeps
    // the operand's nact and truncation order, as the closed forms do (also with no point to process).
    status = fearr_zeros_to(fe->arr.nact, 1, 1, fe->nip, fe->arr.trc_order, &out);

    if (status == DN_OK && n > 0 && fe->arr.nact > 0){
        out.arr.act_order = fe->arr.trc_order;
    }

    for (ip = 0; ip < fe->nip && status == DN_OK; ip++){

        if (n == 0){

            out.arr.p_data[ip] = 1.0;
            continue;

        }

        status = fearr_get_ip_to(ip, fe, &A);

        if (status == DN_OK){
            status = oarr_det_to(&A, &dnum, dhl);
        }

        if (status == DN_OK){
            status = fearr_set_ijk_o(&dnum, 0, 0, ip, &out);
        }

    }

    if (status == DN_OK){
        dngs_move(&out, res);
    }

    fearr_free(&out);
    oarr_free(&A);
    oti_free(&dnum);

    return status;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int fearr_inv_to(const feoarr_t* fe, feoarr_t* res, dhelpl_t dhl){

    uint64_t n = fe->nrows, ip;
    feoarr_t out = fearr_init();
    oarr_t A = oarr_init(), Ai = oarr_init();
    int status;

    if (fe->ncols != n){
        return DN_ERR_SIZE;
    }

    if (n >= 1 && n <= 3){
        return dngs_closed_form(fe, NULL, res, dhl);
    }

    // The result keeps the operand's nact and truncation order (also with no point to process);
    // act_order is trc, as for every linear-algebra result.
    status = fearr_zeros_to(fe->arr.nact, n, n, fe->nip, fe->arr.trc_order, &out);

    if (status == DN_OK && fe->arr.nact > 0){
        out.arr.act_order = fe->arr.trc_order;
    }

    for (ip = 0; ip < fe->nip && status == DN_OK && n > 0; ip++){

        status = fearr_get_ip_to(ip, fe, &A);

        if (status == DN_OK){
            status = oarr_inv_to(&A, &Ai, dhl);
        }

        if (status == DN_OK){
            status = fearr_set_ip(&Ai, ip, &out);
        }

    }

    if (status == DN_OK){
        dngs_move(&out, res);
    }

    fearr_free(&out);
    oarr_free(&A);
    oarr_free(&Ai);

    return status;

}
// -------------------------------------------------------------------------------------------------------
