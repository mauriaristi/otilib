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

    return 1 + (uint64_t)sshelp_ndir_total(oarr_nact(a), oarr_trc_order(a));

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// act_order of an array as a bound on its nonzero orders (0 for a real array).
static inline ord_t dngs_act(const oarr_t* a){

    return (oarr_nact(a) == 0) ? 0 : oarr_act_order(a);

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
// DN_OK when the Gauss descriptor (nblocks, nip, nrows, ncols) is representable (dnob_shape_size_s(),
// dnob_layout_ok(): every extent within int64_t and the product of the nonzero ones, in bytes, too),
// else DN_ERR_MEMORY. Checked before anything is modified.
static int dngs_check(uint64_t nblocks, uint64_t nrows, uint64_t ncols, uint64_t nip){

    dnob_shape_t S;
    uint64_t size;

    S.sdim   = 3;
    S.layout = ND_LAYOUT_F;
    S.ext[0] = nip;
    S.ext[1] = nrows;
    S.ext[2] = ncols;

    if (dnob_shape_size_s(&S, &size) != DN_OK){
        return DN_ERR_MEMORY;
    }

    return dnob_layout_ok(nblocks, &S);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Labels the embedded array of a Gauss value with its shape: blocks (nblocks, nip, nrows, ncols). The
// array's matricized shape is nip x (nrows * ncols) (the caller computed it so), which the label keeps.
static void dngs_label(feoarr_t* fe, uint64_t nrows, uint64_t ncols, uint64_t nip){

    dnob_shape_t S;

    S.sdim   = 3;
    S.layout = ND_LAYOUT_F;
    S.ext[0] = nip;
    S.ext[1] = nrows;
    S.ext[2] = ncols;

    dnob_set_layout(&fe->arr, (uint64_t)fe->arr.blocks.shape[0], &S);
    fe->arr.flags |= OARR_GAUSS;

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

    uint64_t nip = oarr_nrows(a), nb = dngs_nblocks(a), d, c, cs;
    size_t nreal;
    int status = dnob_result_shape(res, oarr_nact(a), nip, n, oarr_trc_order(a), &nreal);

    if (status != DN_OK){
        return status;
    }

    oarr_set_act_order(res, oarr_act_order(a));

    for (d = 0; d < nb; d++){

        for (c = 0; c < n; c++){

            cs = (cols == NULL) ? 0 : cols[c];
            memcpy(oarr_data(res) + d * oarr_size(res) + c * nip,
                   oarr_data(a) + d * oarr_size(a) + cs * nip,
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

    if (trc > oarr_trc_order(arr)){

        status = oarr_reserve(arr, oarr_nact(arr), oarr_nrows(arr), oarr_ncols(arr), trc);

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
    int status = dngs_grow_arr(oarr_nact(src), oarr_trc_order(src), dst);

    if (status != DN_OK){
        return status;
    }

    ms = oarr_nrows(src);
    md = oarr_nrows(dst);

    for (p = 0; p <= oarr_trc_order(dst); p++){

        // Block offsets once per order.
        bd = oarr_block_index(oarr_nact(dst), p, 0);
        bs = oarr_block_index(oarr_nact(src), p, 0);
        Nd = sshelp_ndir_order(oarr_nact(dst), p);
        Ns = (p <= oarr_trc_order(src)) ? sshelp_ndir_order(oarr_nact(src), p) : 0;

        for (i = 0; i < Nd; i++){

            D = oarr_data(dst) + (bd + i) * oarr_size(dst);

            for (c = 0; c < n; c++){

                coeff_t* Dc = D + dst_cols[c] * md + ip;

                if (i < Ns){

                    cs = (src_cols == NULL) ? c : src_cols[c];
                    S  = oarr_data(src) + (bs + i) * oarr_size(src) + cs * ms;

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

    if (act > oarr_act_order(dst)){
        oarr_set_act_order(dst, act);
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

    fe.arr = oarr_init();
    dngs_label(&fe, 0, 0, 0);

    return fe;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int fearr_zeros_to(bases_t nact, uint64_t nrows, uint64_t ncols, uint64_t nip, ord_t trc_order,
                   feoarr_t* res){

    uint64_t m;
    ndir_t nimag;
    int status;

    if (trc_order > _MAXORDER_OTI){
        return DN_ERR_INDEX;
    }

    if (dnob_shape_size(nrows, ncols, &m) != DN_OK
        || sshelp_ndir_total_checked(nact, trc_order, &nimag) != SSHELP_OK || nimag >= (ndir_t)INT64_MAX
        || dngs_check(1 + nimag, nrows, ncols, nip) != DN_OK){
        return DN_ERR_MEMORY;
    }

    status = oarr_zeros_to(nact, nip, m, trc_order, &res->arr);

    if (status != DN_OK){
        return status;
    }

    dngs_label(res, nrows, ncols, nip);

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

    if (fe == res){
        return DN_OK;
    }

    // The copy keeps the element shape (nip, nrows, ncols).
    return oarr_copy_to(&fe->arr, &res->arr);

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

    if (dnob_shape_size(nrows, ncols, &m) != DN_OK
        || dngs_check((uint64_t)fe->arr.blocks.shape[0], nrows, ncols, nip) != DN_OK
        || oarr_nrows(&fe->arr) != nip || oarr_ncols(&fe->arr) != m){
        return DN_ERR_SIZE;
    }

    dngs_label(fe, nrows, ncols, nip);

    return DN_OK;

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// ---------------------------------------     ACCESS     ------------------------------------------------
// -------------------------------------------------------------------------------------------------------

// *******************************************************************************************************
int fearr_get_ip_to(uint64_t ip, const feoarr_t* fe, oarr_t* res){

    DNOB_IN1(NULL, res, fearr_get_ip_to(ip, fe, c_.res));

    const oarr_t* a = &fe->arr;
    uint64_t nip = fearr_nip(fe), m = oarr_ncols(a), nb = dngs_nblocks(a), d, e;
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

    status = dnob_result_shape(res, oarr_nact(a), fearr_nrows(fe), fearr_ncols(fe), oarr_trc_order(a),
                               &nreal);

    if (status != DN_OK){
        return status;
    }

    oarr_set_act_order(res, oarr_act_order(a));

    for (d = 0; d < nb; d++){

        S = oarr_data(a) + d * oarr_size(a) + ip;
        D = oarr_data(res) + d * m;

        for (e = 0; e < m; e++){
            D[e] = S[e * nip];
        }

    }

    return DN_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int fearr_set_ip(const oarr_t* val, uint64_t ip, feoarr_t* fe){

    DNOB_IN1(val, NULL, fearr_set_ip(c_.in[0], ip, fe));

    oarr_t row = oarr_init();
    uint64_t *cols, e, m = oarr_ncols(&fe->arr);
    int status;

    if (oarr_nrows(val) != fearr_nrows(fe) || oarr_ncols(val) != fearr_ncols(fe)){
        return DN_ERR_SIZE;
    }

    if (ip >= fearr_nip(fe)){
        return DN_ERR_INDEX;
    }

    if (val == &fe->arr){
        return DN_ERR_ARGUMENT;
    }

    // val's m column-major entries, read as a 1 x m row (a view): its column e goes to point ip of
    // column e.
    status = oarr_view_matrix(val, 1, m, &row);

    if (status != DN_OK){
        return status;
    }

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

    status = dngs_block_cols(fearr_nrows(fe), fearr_ncols(fe), i0, ni, istep, j0, nj, jstep, &cols);

    // The ranges first (DN_ERR_INDEX, as 1.x), then the representability of the result shape (an
    // empty slice may name a huge extent), before res is touched.
    if (status == DN_OK && dngs_check(dngs_nblocks(&fe->arr), ni, nj, fearr_nip(fe)) != DN_OK){
        status = DN_ERR_MEMORY;
    }

    if (status == DN_OK){
        status = dngs_gather_cols(&fe->arr, cols, ni * nj, &res->arr);
    }

    if (status == DN_OK){
        dngs_label(res, ni, nj, fearr_nip(fe));
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
    int bcast = (fearr_nrows(val) == 1 && fearr_ncols(val) == 1 && (ni != 1 || nj != 1));
    int status;

    if (val == fe){
        return DN_ERR_ARGUMENT;
    }

    if (fearr_nip(val) != fearr_nip(fe) || (!bcast && (fearr_nrows(val) != ni
                                                       || fearr_ncols(val) != nj))){
        return DN_ERR_SIZE;
    }

    // An empty slice assigns nothing (and so grows nothing).
    if (ni == 0 || nj == 0){
        return DN_OK;
    }

    status = dngs_block_cols(fearr_nrows(fe), fearr_ncols(fe), i0, ni, istep, j0, nj, jstep, &dst_cols);

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

    status = dngs_scatter(&val->arr, src_cols, dst_cols, n, 0, fearr_nip(fe), &fe->arr);

    free(dst_cols);
    free(src_cols);

    return status;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int fearr_set_ijk_o(const otinum_t* num, uint64_t i, uint64_t j, uint64_t ip,
                    feoarr_t* fe){

    if (i >= fearr_nrows(fe) || j >= fearr_ncols(fe) || ip >= fearr_nip(fe)){
        return DN_ERR_INDEX;
    }

    return oarr_set_item(num, ip, i + j * fearr_nrows(fe), &fe->arr);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int fearr_set_ijk_r(coeff_t val, uint64_t i, uint64_t j, uint64_t ip, feoarr_t* fe){

    if (i >= fearr_nrows(fe) || j >= fearr_ncols(fe) || ip >= fearr_nip(fe)){
        return DN_ERR_INDEX;
    }

    return oarr_set_item_r(val, ip, i + j * fearr_nrows(fe), &fe->arr);

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// ---------------------------------------     BROADCASTS     --------------------------------------------
// -------------------------------------------------------------------------------------------------------

// *******************************************************************************************************
int fearr_from_oarr_to(const oarr_t* arr, uint64_t nip, feoarr_t* res){

    DNOB_IN1(arr, NULL, fearr_from_oarr_to(c_.in[0], nip, res));

    uint64_t nb = dngs_nblocks(arr), m = oarr_size(arr), d, e, t;
    feoarr_t tmp = fearr_init();
    feoarr_t* out = (arr == &res->arr) ? &tmp : res;
    const coeff_t* S;
    coeff_t* D;
    size_t nreal;
    int status = dngs_check(nb, oarr_nrows(arr), oarr_ncols(arr), nip);

    if (status == DN_OK){
        status = dnob_result_shape(&out->arr, oarr_nact(arr), nip, m, oarr_trc_order(arr), &nreal);
    }

    if (status != DN_OK){
        return status;
    }

    oarr_set_act_order(&out->arr, oarr_act_order(arr));

    for (d = 0; d < nb; d++){

        S = oarr_data(arr) + d * m;
        D = oarr_data(&out->arr) + d * oarr_size(&out->arr);

        for (e = 0; e < m; e++){

            for (t = 0; t < nip; t++){
                D[e * nip + t] = S[e];
            }

        }

    }

    dngs_label(out, oarr_nrows(arr), oarr_ncols(arr), nip);

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

    if (fearr_nrows(num) != 1 || fearr_ncols(num) != 1 || dnob_shape_size(nrows, ncols, &n) != DN_OK){
        return DN_ERR_SIZE;
    }

    if (dngs_check(dngs_nblocks(&num->arr), nrows, ncols, fearr_nip(num)) != DN_OK){
        return DN_ERR_MEMORY;
    }

    status = dngs_gather_cols(&num->arr, NULL, n, &res->arr);

    if (status == DN_OK){
        dngs_label(res, nrows, ncols, fearr_nip(num));
    }

    return status;

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// ---------------------------------------     LINEAR ALGEBRA     ----------------------------------------
// -------------------------------------------------------------------------------------------------------

// *******************************************************************************************************
int fearr_transpose_to(const feoarr_t* fe, feoarr_t* res){

    uint64_t n = fearr_nrows(fe), m = fearr_ncols(fe), r, c, nm;
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

        dngs_label(&tmp, m, n, fearr_nip(fe));
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

    uint64_t n = fearr_nrows(a), q = fearr_ncols(a), m = fearr_ncols(b), nip = fearr_nip(a);
    uint64_t sa, sb, sr, bp, bq, bpq, nm;
    bases_t ka = oarr_nact(&a->arr), kb = oarr_nact(&b->arr), k = (ka > kb) ? ka : kb, ui[256], uj[256];
    ord_t trc = (oarr_trc_order(&a->arr) > oarr_trc_order(&b->arr)) ? oarr_trc_order(&a->arr)
                                                                      : oarr_trc_order(&b->arr);
    ord_t atop = dngs_act(&a->arr), btop = dngs_act(&b->arr), p, pq;
    ndir_t i, j, Np, Nq;
    unsigned act;
    feoarr_t tmp = fearr_init();
    feoarr_t* out = (res == a || res == b) ? &tmp : res;
    dnok_pairsrc_t src;
    size_t nreal;
    int status;

    if (fearr_nrows(b) != q || fearr_nip(b) != nip){
        return DN_ERR_SIZE;
    }

    if (dnob_shape_size(n, m, &nm) != DN_OK){
        return DN_ERR_MEMORY;
    }

    status = dnob_result_shape(&out->arr, k, nip, nm, trc, &nreal);

    if (status != DN_OK){
        return status;
    }

    memset(oarr_data(&out->arr), 0, nreal * sizeof(coeff_t));

    sa = oarr_size(&a->arr);
    sb = oarr_size(&b->arr);
    sr = oarr_size(&out->arr);

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

                const coeff_t* Ai = oarr_data(&a->arr) + (bp + i) * sa;

                if (!dnok_all_zero(Ai, sa)){

                    dnok_tuple_reset(uj, pq);

                    for (j = 0; j < Nq; j++){

                        dngs_block_matmul(Ai, oarr_data(&b->arr) + (bq + j) * sb, n, q, m, nip,
                            oarr_data(&out->arr) + (bpq + dnok_pair_idx(&src, i, ui, j, uj)) * sr);

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
    oarr_set_act_order(&out->arr, (k == 0) ? 0 : (ord_t)((act < trc) ? act : trc));
    dngs_label(out, n, m, nip);

    if (out == &tmp){
        dngs_move(&tmp, res);
    }

    return DN_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int fearr_matmul_FO_to(const feoarr_t* a, const oarr_t* b, feoarr_t* res, dhelpl_t dhl){

    DNOB_IN1(b, NULL, fearr_matmul_FO_to(a, c_.in[0], res, dhl));

    uint64_t n = fearr_nrows(a), q = fearr_ncols(a), m = oarr_ncols(b), nip = fearr_nip(a), nn, nm;
    oarr_t av = oarr_init();
    feoarr_t out = fearr_init();
    int status;

    if (oarr_nrows(b) != q){
        return DN_ERR_SIZE;
    }

    if (dnob_shape_size(nip, n, &nn) != DN_OK || dnob_shape_size(n, m, &nm) != DN_OK){
        return DN_ERR_MEMORY;
    }

    // a.arr (nip x n*q, column-major over (ip, r, s)) is the same memory as an (nip*n) x q matrix.
    status = oarr_view_matrix(&a->arr, nn, q, &av);

    if (status == DN_OK){
        status = oarr_matmul_OO_to(&av, b, &out.arr, dhl);
    }

    if (status != DN_OK){

        fearr_free(&out);
        return status;

    }

    // The (nip*n) x m product is the nip x (n*m) layout of the per-point results.
    dngs_label(&out, n, m, nip);

    dngs_move(&out, res);

    return DN_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int fearr_matmul_OF_to(const oarr_t* a, const feoarr_t* b, feoarr_t* res, dhelpl_t dhl){

    DNOB_IN1(a, NULL, fearr_matmul_OF_to(c_.in[0], b, res, dhl));

    feoarr_t bt = fearr_init(), rt = fearr_init();
    oarr_t at = oarr_init();
    int status;

    if (oarr_ncols(a) != fearr_nrows(b)){
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

    DNOB_IN1(b, NULL, fearr_dot_product_FO_to(a, c_.in[0], res, dhl));

    uint64_t N = oarr_ncols(&a->arr);
    oarr_t bv = oarr_init(), av = oarr_init();
    feoarr_t out = fearr_init();
    int status;

    if (oarr_size(b) != N){
        return DN_ERR_SIZE;
    }

    // b's column-major entries as an N x 1 vector, a's array as an nip x N matrix (views).
    status = oarr_view_matrix(b, N, 1, &bv);

    if (status == DN_OK){
        status = oarr_view_matrix(&a->arr, fearr_nip(a), N, &av);
    }

    if (status == DN_OK){
        status = oarr_matmul_OO_to(&av, &bv, &out.arr, dhl);
    }

    if (status != DN_OK){

        fearr_free(&out);
        return status;

    }

    dngs_label(&out, 1, 1, fearr_nip(a));
    dngs_move(&out, res);

    return DN_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int fearr_dot_product_FF_to(const feoarr_t* a, const feoarr_t* b, feoarr_t* res,
                            dhelpl_t dhl){

    uint64_t N = oarr_ncols(&a->arr), nip = fearr_nip(a), nb, d, e, t;
    feoarr_t prod = fearr_init(), out = fearr_init();
    oarr_t va = oarr_init(), vb = oarr_init();
    const coeff_t* S;
    coeff_t* D;
    int status;

    if (oarr_ncols(&b->arr) != N || fearr_nip(b) != nip){
        return DN_ERR_SIZE;
    }

    // Elementwise over the matricized nip x N shape: the matrix shapes of a and b may differ.
    status = oarr_view_matrix(&a->arr, nip, N, &va);

    if (status == DN_OK){
        status = oarr_view_matrix(&b->arr, nip, N, &vb);
    }

    if (status == DN_OK){
        status = oarr_mul_OO_to(&va, &vb, &prod.arr, dhl);
    }

    if (status == DN_OK){
        status = fearr_zeros_to(oarr_nact(&prod.arr), 1, 1, nip, oarr_trc_order(&prod.arr), &out);
    }

    if (status != DN_OK){

        fearr_free(&prod);
        fearr_free(&out);
        return status;

    }

    // Sum of the N columns of the product.
    nb = dngs_nblocks(&prod.arr);
    oarr_set_act_order(&out.arr, oarr_act_order(&prod.arr));

    for (d = 0; d < nb; d++){

        S = oarr_data(&prod.arr) + d * oarr_size(&prod.arr);
        D = oarr_data(&out.arr) + d * nip;

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

    DNOB_IN1(NULL, res, fearr_integrate_to(val, w, c_.res, dhl));

    oarr_t wv = oarr_init(), vv = oarr_init();
    int status;

    if (fearr_nrows(w) != 1 || fearr_ncols(w) != 1 || fearr_nip(w) != fearr_nip(val)){
        return DN_ERR_SIZE;
    }

    // w (nip x 1) is the same memory as the 1 x nip row w^T, val's array an nip x (nrows * ncols)
    // matrix (views).
    status = oarr_view_matrix(&w->arr, 1, fearr_nip(w), &wv);

    if (status == DN_OK){
        status = oarr_view_matrix(&val->arr, fearr_nip(val), oarr_ncols(&val->arr), &vv);
    }

    if (status == DN_OK){
        status = oarr_matmul_OO_to(&wv, &vv, res, dhl);
    }

    if (status != DN_OK){
        return status;
    }

    // The 1 x (nrows*ncols) row is the column-major nrows x ncols matrix.
    dnob_reshape2(res, fearr_nrows(val), fearr_ncols(val));

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

    uint64_t n = fearr_nrows(fe), r, c, r1, r2, c1, c2, col, nip = fearr_nip(fe);
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
            oarr_data(&C[0])[r] = 1.0;
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
            oarr_set_act_order(&out.arr, (oarr_nact(&out.arr) == 0) ? 0 : oarr_trc_order(&out.arr));
            dngs_label(&out, 1, 1, nip);
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

    uint64_t n = fearr_nrows(fe), ip;
    feoarr_t out = fearr_init();
    oarr_t A = oarr_init();
    otinum_t dnum = oti_init();
    int status;

    if (fearr_ncols(fe) != n){
        return DN_ERR_SIZE;
    }

    if (n >= 1 && n <= 3){
        return dngs_closed_form(fe, res, NULL, dhl);
    }

    // n = 0 gives det 1 at every point (the empty product); n > 3 is an LU per point. The result keeps
    // the operand's nact and truncation order, as the closed forms do (also with no point to process).
    status = fearr_zeros_to(oarr_nact(&fe->arr), 1, 1, fearr_nip(fe), oarr_trc_order(&fe->arr), &out);

    if (status == DN_OK && n > 0 && oarr_nact(&fe->arr) > 0){
        oarr_set_act_order(&out.arr, oarr_trc_order(&fe->arr));
    }

    for (ip = 0; ip < fearr_nip(fe) && status == DN_OK; ip++){

        if (n == 0){

            oarr_data(&out.arr)[ip] = 1.0;
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

    uint64_t n = fearr_nrows(fe), ip;
    feoarr_t out = fearr_init();
    oarr_t A = oarr_init(), Ai = oarr_init();
    int status;

    if (fearr_ncols(fe) != n){
        return DN_ERR_SIZE;
    }

    if (n >= 1 && n <= 3){
        return dngs_closed_form(fe, NULL, res, dhl);
    }

    // The result keeps the operand's nact and truncation order (also with no point to process);
    // act_order is trc, as for every linear-algebra result.
    status = fearr_zeros_to(oarr_nact(&fe->arr), n, n, fearr_nip(fe), oarr_trc_order(&fe->arr), &out);

    if (status == DN_OK && oarr_nact(&fe->arr) > 0){
        oarr_set_act_order(&out.arr, oarr_trc_order(&fe->arr));
    }

    for (ip = 0; ip < fearr_nip(fe) && status == DN_OK && n > 0; ip++){

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
