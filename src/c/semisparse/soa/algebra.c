// Semi-sparse SoA arrays: elementwise algebra, functions, matrix products and transpose.
// Conventions in include/oti/semisparse/soa/algebra.h and soa/base.h. Reuses the scalar module's
// workspace helpers (ssoti_ws, ssoti_ws_need, ssoti_out_of_memory, ssoti_nimag_checked) and the
// kernels of src/c/semisparse/soa/kernels.c (oarrss_kernel_mul_acc, oarrss_kernel_matmul_acc),
// included just before this file.
//
// Memory: every operation writes its result straight into `res` when `res` does not alias an
// operand. When it does, the result is built in a call-local buffer and copied in. Expanded
// operands and scratch are call-local too, so nothing result- or operand-sized outlives a call; only
// the small index buffers (union of bases, position maps) stay in the thread workspace.

#ifdef _OPENMP
#include <omp.h>
#endif


// *******************************************************************************************************
static void oarrss_dim_check(const oarrss_t* a, const oarrss_t* b){

    if (a->nrows != b->nrows || a->ncols != b->ncols){

        printf("ERROR: Shape mismatch in semi-sparse SoA elementwise operation. Exiting...\n");
        exit(OTI_BadIndx);

    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// True when `res` is `x` or shares its coefficient buffer, so writing into `res` would overwrite `x`.
static int oarrss_res_aliases(const oarrss_t* res, const oarrss_t* x){

    return (res == x) || (res->p_data != NULL && res->p_data == x->p_data);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Call-local coefficient buffer (freed by the caller before it returns); NULL for ncoef == 0.
static coeff_t* oarrss_scratch_alloc(size_t ncoef){

    coeff_t* p_buf;

    if (ncoef == 0){
        return NULL;
    }

    p_buf = (coeff_t*)malloc(ncoef * sizeof(coeff_t));

    if (p_buf == NULL){
        ssoti_out_of_memory();
    }

    return p_buf;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Shapes `res` as a result over `nu` bases (whose sorted labels are `p_u`) and truncation order `trc`,
// without changing its contents, and returns its coefficient buffer.
static coeff_t* oarrss_result_begin(oarrss_t* res, const bases_t* p_u, bases_t nu, ord_t trc,
                                    uint64_t nrows, uint64_t ncols){

    oarrss_reserve(res, nu, nrows, ncols, trc);

    if (nu > 0){
        memmove(res->p_bases, p_u, (size_t)nu * sizeof(bases_t));
    }

    return res->p_data;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Marks `res` as holding a finished result computed in its own buffer by oarrss_result_begin().
static void oarrss_result_end(oarrss_t* res, bases_t nu, ord_t trc, ord_t act, uint64_t nrows,
                              uint64_t ncols){

    res->nbases    = nu;
    res->trc_order = trc;
    res->act_order = (act < trc) ? act : trc;
    res->nrows     = nrows;
    res->ncols     = ncols;
    res->size      = nrows * ncols;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Operands of a binary array operation in the layout of the union of their sets. The result goes
// straight into the destination unless it aliases an operand, in which case it goes into `p_tmp`
// first. `p_tmp` also holds the expanded operands; nothing here outlives the operation.
typedef struct {
    const coeff_t* p_a;
    const coeff_t* p_b;
    coeff_t*       p_r;
    coeff_t*       p_tmp;
    const bases_t* p_u;
    bases_t         nu;
    ord_t          trc;
    ndir_t       nimag;
    int         direct;
    uint64_t      size, nrows, ncols;
} oarrss_binop_t;
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static oarrss_binop_t oarrss_binop_prepare(const oarrss_t* a, const oarrss_t* b, oarrss_t* res){

    sshelp_ws_t* ws = ssoti_ws();
    oarrss_binop_t op;
    size_t nb = (size_t)a->nbases + b->nbases;
    bases_t *p_u, *pos_a, *pos_b;
    coeff_t *p_ea, *p_eb;
    int own_a, own_b;
    size_t need;

    op.size  = a->size;
    op.nrows = a->nrows;
    op.ncols = a->ncols;
    op.trc   = (a->trc_order > b->trc_order) ? a->trc_order : b->trc_order;

    // Index buffers only (bases and position maps); the coefficient buffers below are call-local.
    ssoti_ws_need(ws, 0, 0, 2 * nb + 1);
    p_u   = ws->p_bases;
    pos_a = ws->p_bases + nb;
    pos_b = pos_a + a->nbases;

    op.nu    = sshelp_union_bases(a->p_bases, a->nbases, b->p_bases, b->nbases, p_u, pos_a, pos_b);
    op.nimag = ssoti_nimag_checked(op.nu, op.trc);
    op.p_u   = p_u;

    own_a = (a->nbases == op.nu && a->trc_order >= op.trc);
    own_b = (b->nbases == op.nu && b->trc_order >= op.trc);

    op.direct = !oarrss_res_aliases(res, a) && !oarrss_res_aliases(res, b);

    need = (size_t)(1 + op.nimag) * op.size;

    op.p_tmp = oarrss_scratch_alloc(need * (!op.direct + !own_a + !own_b));

    if (op.direct){

        op.p_r = oarrss_result_begin(res, p_u, op.nu, op.trc, op.nrows, op.ncols);
        p_ea   = op.p_tmp;

    } else {

        op.p_r = op.p_tmp;
        p_ea   = op.p_tmp + need;

    }

    p_eb = p_ea + (own_a ? 0 : need);

    if (own_a){
        op.p_a = a->p_data;
    } else {
        oarrss_kernel_expand(a, pos_a, op.nu, op.trc, p_ea);
        op.p_a = p_ea;
    }

    if (own_b){
        op.p_b = b->p_data;
    } else {
        oarrss_kernel_expand(b, pos_b, op.nu, op.trc, p_eb);
        op.p_b = p_eb;
    }

    return op;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Finishes a binary or mixed array operation: moves an aliased result into `res` and releases the
// call-local buffer.
static void oarrss_binop_finish(oarrss_binop_t* op, ord_t act, oarrss_t* res){

    if (!op->direct){

        size_t nbytes = (size_t)(1 + op->nimag) * op->size * sizeof(coeff_t);
        coeff_t* p_dst = oarrss_result_begin(res, op->p_u, op->nu, op->trc, op->nrows, op->ncols);

        memcpy(p_dst, op->p_r, nbytes);

    }

    oarrss_result_end(res, op->nu, op->trc, act, op->nrows, op->ncols);

    free(op->p_tmp);
    op->p_tmp = NULL;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// res = sa * a + sb * b (sums and subtractions).
static void oarrss_axpby_to(coeff_t sa, const oarrss_t* a, coeff_t sb, const oarrss_t* b,
                            oarrss_t* res){

    oarrss_binop_t op = oarrss_binop_prepare(a, b, res);
    size_t n = (size_t)(1 + op.nimag) * op.size, i;
    ord_t act = (a->act_order > b->act_order) ? a->act_order : b->act_order;

    for (i = 0; i < n; i++){
        op.p_r[i] = sa * op.p_a[i] + sb * op.p_b[i];
    }

    oarrss_binop_finish(&op, act, res);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Writes the blocks of a semi-sparse scalar in the layout of a larger active set, broadcast over
// `m` elements per direction (array version of the scalar's ssoti_kernel_expand()).
static void oarrss_kernel_expand_scalar(const ssotinum_t* num, const bases_t* pos, bases_t ku,
                                        ord_t trc, uint64_t m, coeff_t* dst){

    bases_t k = num->nbases;
    int leading = sshelp_is_leading(pos, k);
    ord_t p, i, top = (num->act_order < trc) ? num->act_order : trc;
    ndir_t j, Ns, Nd;
    coeff_t* D;
    sshelp_rank_tab_t tab = {NULL, 0, 0};
    bases_t u[256], v[256];
    uint64_t e;

    for (e = 0; e < m; e++){
        dst[e] = num->re;
    }

    if (!leading && sshelp_rank_tab_init(&tab, ku, trc) != SSHELP_OK){
        ssoti_out_of_memory();
    }

    for (p = 1; p <= trc; p++){

        Nd = sshelp_ndir_order(ku, p);
        D  = dst + oarrss_block_index(ku, p, 0) * m;

        if (p > top || k == 0){

            memset(D, 0, (size_t)Nd * m * sizeof(coeff_t));
            continue;

        }

        Ns = sshelp_ndir_order(k, p);

        if (leading){

            for (j = 0; j < Ns; j++){

                coeff_t val = num->p_im[sshelp_order_offset(k, p) + j];
                coeff_t* blk = D + (size_t)j * m;

                for (e = 0; e < m; e++){
                    blk[e] = val;
                }

            }

            memset(D + (size_t)Ns * m, 0, (size_t)(Nd - Ns) * m * sizeof(coeff_t));

        } else {

            memset(D, 0, (size_t)Nd * m * sizeof(coeff_t));

            for (i = 0; i < p; i++){
                u[i] = 0;
            }

            for (j = 0; j < Ns; j++){

                coeff_t val = num->p_im[sshelp_order_offset(k, p) + j];
                coeff_t* blk;

                for (i = 0; i < p; i++){
                    v[i] = pos[u[i]];
                }

                blk = D + (size_t)sshelp_rank(v, p, &tab) * m;

                for (e = 0; e < m; e++){
                    blk[e] = val;
                }

                sshelp_next_dir(u, p, k);

            }

        }

    }

    sshelp_rank_tab_free(&tab);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Operands of a scalar/array operation in the layout of the union of their sets, in an
// oarrss_binop_t: `p_a` is the scalar broadcast over the elements, `p_b` the array.
static oarrss_binop_t oarrss_mixop_prepare(const ssotinum_t* num, const oarrss_t* arr,
                                           oarrss_t* res){

    sshelp_ws_t* ws = ssoti_ws();
    oarrss_binop_t op;
    size_t nb = (size_t)num->nbases + arr->nbases;
    bases_t *p_u, *pos_o, *pos_O;
    coeff_t *p_eo, *p_eO;
    int own_O;
    size_t need;

    op.size  = arr->size;
    op.nrows = arr->nrows;
    op.ncols = arr->ncols;
    op.trc   = (num->trc_order > arr->trc_order) ? num->trc_order : arr->trc_order;

    ssoti_ws_need(ws, 0, 0, 2 * nb + 1);
    p_u   = ws->p_bases;
    pos_o = ws->p_bases + nb;
    pos_O = pos_o + num->nbases;

    op.nu    = sshelp_union_bases(num->p_bases, num->nbases, arr->p_bases, arr->nbases, p_u, pos_o,
                pos_O);
    op.nimag = ssoti_nimag_checked(op.nu, op.trc);
    op.p_u   = p_u;

    own_O     = (arr->nbases == op.nu && arr->trc_order >= op.trc);
    op.direct = !oarrss_res_aliases(res, arr);

    need = (size_t)(1 + op.nimag) * op.size;

    op.p_tmp = oarrss_scratch_alloc(need * (!op.direct + 1 + !own_O));

    if (op.direct){

        op.p_r = oarrss_result_begin(res, p_u, op.nu, op.trc, op.nrows, op.ncols);
        p_eo   = op.p_tmp;

    } else {

        op.p_r = op.p_tmp;
        p_eo   = op.p_tmp + need;

    }

    p_eO = p_eo + need;

    oarrss_kernel_expand_scalar(num, pos_o, op.nu, op.trc, op.size, p_eo);
    op.p_a = p_eo;

    if (own_O){
        op.p_b = arr->p_data;
    } else {
        oarrss_kernel_expand(arr, pos_O, op.nu, op.trc, p_eO);
        op.p_b = p_eO;
    }

    return op;

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// ---------------------------------------     ELEMENTWISE     -------------------------------------------
// -------------------------------------------------------------------------------------------------------

// *******************************************************************************************************
void oarrss_sum_OO_to(const oarrss_t* arr1, const oarrss_t* arr2, oarrss_t* res, dhelpl_t dhl){

    (void)dhl;
    oarrss_dim_check(arr1, arr2);
    oarrss_axpby_to(1.0, arr1, 1.0, arr2, res);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void oarrss_sum_oO_to(const ssotinum_t* num, const oarrss_t* arr1, oarrss_t* res, dhelpl_t dhl){

    oarrss_binop_t op = oarrss_mixop_prepare(num, arr1, res);
    size_t n = (size_t)(1 + op.nimag) * op.size, i;
    ord_t act = (num->act_order > arr1->act_order) ? num->act_order : arr1->act_order;

    (void)dhl;

    for (i = 0; i < n; i++){
        op.p_r[i] = op.p_a[i] + op.p_b[i];
    }

    oarrss_binop_finish(&op, act, res);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void oarrss_sum_rO_to(coeff_t val, const oarrss_t* arr1, oarrss_t* res, dhelpl_t dhl){

    uint64_t e;

    (void)dhl;
    oarrss_copy_to(arr1, res);

    for (e = 0; e < res->size; e++){
        res->p_data[e] += val;
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void oarrss_sub_OO_to(const oarrss_t* arr1, const oarrss_t* arr2, oarrss_t* res, dhelpl_t dhl){

    (void)dhl;
    oarrss_dim_check(arr1, arr2);
    oarrss_axpby_to(1.0, arr1, -1.0, arr2, res);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void oarrss_sub_oO_to(const ssotinum_t* num, const oarrss_t* arr1, oarrss_t* res, dhelpl_t dhl){

    oarrss_binop_t op = oarrss_mixop_prepare(num, arr1, res);
    size_t n = (size_t)(1 + op.nimag) * op.size, i;
    ord_t act = (num->act_order > arr1->act_order) ? num->act_order : arr1->act_order;

    (void)dhl;

    for (i = 0; i < n; i++){
        op.p_r[i] = op.p_a[i] - op.p_b[i];
    }

    oarrss_binop_finish(&op, act, res);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void oarrss_sub_rO_to(coeff_t val, const oarrss_t* arr1, oarrss_t* res, dhelpl_t dhl){

    uint64_t e;

    oarrss_neg_to(arr1, res, dhl);

    for (e = 0; e < res->size; e++){
        res->p_data[e] += val;
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void oarrss_sub_Oo_to(const oarrss_t* arr1, const ssotinum_t* num, oarrss_t* res, dhelpl_t dhl){

    oarrss_binop_t op = oarrss_mixop_prepare(num, arr1, res);
    size_t n = (size_t)(1 + op.nimag) * op.size, i;
    ord_t act = (num->act_order > arr1->act_order) ? num->act_order : arr1->act_order;

    (void)dhl;

    for (i = 0; i < n; i++){
        op.p_r[i] = op.p_b[i] - op.p_a[i];
    }

    oarrss_binop_finish(&op, act, res);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void oarrss_sub_Or_to(const oarrss_t* arr1, coeff_t val, oarrss_t* res, dhelpl_t dhl){

    (void)dhl;
    oarrss_copy_to(arr1, res);
    { uint64_t e; for (e = 0; e < res->size; e++){ res->p_data[e] -= val; } }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void oarrss_mul_OO_to(const oarrss_t* arr1, const oarrss_t* arr2, oarrss_t* res, dhelpl_t dhl){

    oarrss_binop_t op;
    size_t n;
    ord_t atop, btop, act;

    oarrss_dim_check(arr1, arr2);
    op = oarrss_binop_prepare(arr1, arr2, res);
    n  = (size_t)(1 + op.nimag) * op.size;

    memset(op.p_r, 0, n * sizeof(coeff_t));

    atop = (arr1->act_order < op.trc) ? arr1->act_order : op.trc;
    btop = (arr2->act_order < op.trc) ? arr2->act_order : op.trc;

    oarrss_kernel_mul_acc(op.p_a, 0, atop, op.p_b, 0, btop, op.nu, op.trc, op.size, 0, op.size,
        op.p_r, dhl);

    act = (ord_t)(((unsigned)atop + btop > 255) ? 255 : (atop + btop));

    oarrss_binop_finish(&op, act, res);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void oarrss_mul_oO_to(const ssotinum_t* num, const oarrss_t* arr1, oarrss_t* res, dhelpl_t dhl){

    oarrss_binop_t op = oarrss_mixop_prepare(num, arr1, res);
    size_t n = (size_t)(1 + op.nimag) * op.size;
    ord_t atop = (num->act_order < op.trc) ? num->act_order : op.trc;
    ord_t Otop = (arr1->act_order < op.trc) ? arr1->act_order : op.trc;
    ord_t act;

    memset(op.p_r, 0, n * sizeof(coeff_t));
    oarrss_kernel_mul_acc(op.p_a, 0, atop, op.p_b, 0, Otop, op.nu, op.trc, op.size, 0, op.size,
        op.p_r, dhl);

    act = (ord_t)(((unsigned)atop + Otop > 255) ? 255 : (atop + Otop));

    oarrss_binop_finish(&op, act, res);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void oarrss_mul_rO_to(coeff_t val, const oarrss_t* arr1, oarrss_t* res, dhelpl_t dhl){

    size_t n;
    uint64_t i;

    (void)dhl;
    oarrss_copy_to(arr1, res);

    n = (size_t)(1 + sshelp_ndir_total(res->nbases, res->trc_order)) * res->size;

    for (i = 0; i < n; i++){
        res->p_data[i] *= val;
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void oarrss_div_OO_to(const oarrss_t* arr1, const oarrss_t* arr2, oarrss_t* res, dhelpl_t dhl){

    oarrss_t inv = oarrss_init();

    oarrss_pow_to(arr2, -1.0, &inv, dhl);
    oarrss_mul_OO_to(arr1, &inv, res, dhl);
    oarrss_free(&inv);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void oarrss_div_oO_to(const ssotinum_t* num, const oarrss_t* arr1, oarrss_t* res, dhelpl_t dhl){

    oarrss_t inv = oarrss_init();

    oarrss_pow_to(arr1, -1.0, &inv, dhl);
    oarrss_mul_oO_to(num, &inv, res, dhl);
    oarrss_free(&inv);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void oarrss_div_rO_to(coeff_t val, const oarrss_t* arr1, oarrss_t* res, dhelpl_t dhl){

    oarrss_pow_to(arr1, -1.0, res, dhl);
    oarrss_mul_rO_to(val, res, res, dhl);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void oarrss_div_Oo_to(const oarrss_t* arr1, const ssotinum_t* num, oarrss_t* res, dhelpl_t dhl){

    ssotinum_t inv = ssoti_init();

    ssoti_pow_to(num, -1.0, &inv, dhl);
    oarrss_mul_oO_to(&inv, arr1, res, dhl);
    ssoti_free(&inv);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void oarrss_div_Or_to(const oarrss_t* arr1, coeff_t val, oarrss_t* res, dhelpl_t dhl){

    oarrss_mul_rO_to(1.0 / val, arr1, res, dhl);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void oarrss_neg_to(const oarrss_t* arr1, oarrss_t* res, dhelpl_t dhl){

    size_t n, i;

    (void)dhl;
    oarrss_copy_to(arr1, res);

    n = (size_t)(1 + sshelp_ndir_total(res->nbases, res->trc_order)) * res->size;

    for (i = 0; i < n; i++){
        res->p_data[i] = -res->p_data[i];
    }

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// ---------------------------------------     FUNCTIONS     ---------------------------------------------
// -------------------------------------------------------------------------------------------------------

// *******************************************************************************************************
void oarrss_feval_to(const coeff_t* derivs, const oarrss_t* arr1, oarrss_t* res, dhelpl_t dhl){

    bases_t k = arr1->nbases;
    ord_t trc = arr1->trc_order, act = arr1->act_order, i;
    ndir_t nimag = ssoti_nimag_checked(k, trc);
    uint64_t m = arr1->size;
    size_t nblock = (size_t)(1 + nimag) * m;
    coeff_t *P, *Q, *R, *tmp, *p_buf, factor = 1.0;
    int direct = !oarrss_res_aliases(res, arr1);

    if (k == 0 || act == 0 || trc == 0 || m == 0){

        uint64_t e;
        ndir_t nimag_res;

        oarrss_copy_to(arr1, res);

        for (e = 0; e < res->size; e++){
            res->p_data[e] = derivs[e];
        }

        nimag_res = sshelp_ndir_total(res->nbases, res->trc_order);

        if (nimag_res > 0){
            memset(res->p_data + res->size, 0, (size_t)nimag_res * res->size * sizeof(coeff_t));
        }

        res->act_order = 0;

        return;

    }

    // P and Q ping-pong the running power; R is the result, which goes straight into `res` unless it
    // aliases the operand. Everything is call-local.
    p_buf = oarrss_scratch_alloc(nblock * (2 + !direct));

    if (direct){

        R = oarrss_result_begin(res, arr1->p_bases, k, trc, arr1->nrows, arr1->ncols);
        P = p_buf;

    } else {

        R = p_buf;
        P = p_buf + nblock;

    }

    Q = P + nblock;

    memcpy(P, arr1->p_data, nblock * sizeof(coeff_t));

    // R = f'(re_e) d, per element: the order-1 derivative varies per element (derivs[m + e]), so
    // every direction block is scaled by the *same-element* factor, not a single global scalar.
    {
        size_t b, nblocks = nblock / m;
        uint64_t e;

        for (b = 1; b < nblocks; b++){
            for (e = 0; e < m; e++){
                R[b * m + e] = derivs[m + e] * P[b * m + e];
            }
        }
    }

    for (i = 2; i <= trc; i++){

        ord_t lo = (ord_t)(i - 1);
        ord_t hi = ((unsigned)(i - 1) * act < trc) ? (ord_t)((i - 1) * act) : trc;
        const coeff_t* d_i = derivs + (size_t)i * m;
        uint64_t start_block;

        factor *= i;

        memset(Q, 0, nblock * sizeof(coeff_t));

        if (m >= 4096){

#ifdef _OPENMP
            #pragma omp parallel
            {
                int nt  = omp_get_num_threads();
                int tid = omp_get_thread_num();
                uint64_t e0 = (m * (uint64_t)tid) / (uint64_t)nt;
                uint64_t e1 = (m * (uint64_t)(tid + 1)) / (uint64_t)nt;

                oarrss_kernel_mul_acc(P, lo, hi, arr1->p_data, 1, act, k, trc, m, e0, e1, Q, dhl);

            }
#else
            oarrss_kernel_mul_acc(P, lo, hi, arr1->p_data, 1, act, k, trc, m, 0, m, Q, dhl);
#endif

        } else {

            oarrss_kernel_mul_acc(P, lo, hi, arr1->p_data, 1, act, k, trc, m, 0, m, Q, dhl);

        }

        start_block = 1 + sshelp_order_offset(k, i);

        {
            size_t b, nblocks = nblock / m;
            uint64_t e;

            for (b = start_block; b < nblocks; b++){
                for (e = 0; e < m; e++){
                    R[b * m + e] += (d_i[e] / factor) * Q[b * m + e];
                }
            }
        }

        tmp = P;
        P   = Q;
        Q   = tmp;

    }

    if (!direct){

        oarrss_result_begin(res, arr1->p_bases, k, trc, arr1->nrows, arr1->ncols);
        memcpy(res->p_data + m, R + m, (nblock - m) * sizeof(coeff_t));

    }

    {
        uint64_t e;
        for (e = 0; e < m; e++){
            res->p_data[e] = derivs[e];
        }
    }

    oarrss_result_end(res, k, trc, trc, arr1->nrows, arr1->ncols);
    free(p_buf);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Per-element derivatives f(re_e), ..., f^(trc)(re_e) for a simple der_r_* function, one call per
// distinct semi-sparse function below. Caller frees the returned buffer.
static coeff_t* oarrss_derivs_alloc(const oarrss_t* arr1, void (*fn)(coeff_t, ord_t, coeff_t*)){

    uint64_t e, m = arr1->size;
    ord_t trc = arr1->trc_order, i;
    coeff_t* derivs = (coeff_t*)malloc((size_t)(trc + 1) * m * sizeof(coeff_t));
    coeff_t tmp[_MAXORDER_OTI + 1];

    if (derivs == NULL){
        ssoti_out_of_memory();
    }

    for (e = 0; e < m; e++){

        fn(arr1->p_data[e], trc, tmp);

        for (i = 0; i <= trc; i++){
            derivs[(size_t)i * m + e] = tmp[i];
        }

    }

    return derivs;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static coeff_t* oarrss_derivs_alloc_pow(const oarrss_t* arr1, coeff_t e_exp){

    uint64_t e, m = arr1->size;
    ord_t trc = arr1->trc_order, i;
    coeff_t* derivs = (coeff_t*)malloc((size_t)(trc + 1) * m * sizeof(coeff_t));
    coeff_t tmp[_MAXORDER_OTI + 1];

    if (derivs == NULL){
        ssoti_out_of_memory();
    }

    for (e = 0; e < m; e++){

        der_r_pow(arr1->p_data[e], e_exp, trc, tmp);

        for (i = 0; i <= trc; i++){
            derivs[(size_t)i * m + e] = tmp[i];
        }

    }

    return derivs;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void oarrss_exp_to(const oarrss_t* arr1, oarrss_t* res, dhelpl_t dhl){

    coeff_t* derivs = oarrss_derivs_alloc(arr1, der_r_exp);

    oarrss_feval_to(derivs, arr1, res, dhl);
    free(derivs);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void oarrss_log_to(const oarrss_t* arr1, oarrss_t* res, dhelpl_t dhl){

    coeff_t* derivs = oarrss_derivs_alloc(arr1, der_r_log);

    oarrss_feval_to(derivs, arr1, res, dhl);
    free(derivs);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void oarrss_log10_to(const oarrss_t* arr1, oarrss_t* res, dhelpl_t dhl){

    coeff_t* derivs = oarrss_derivs_alloc(arr1, der_r_log10);

    oarrss_feval_to(derivs, arr1, res, dhl);
    free(derivs);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void oarrss_sqrt_to(const oarrss_t* arr1, oarrss_t* res, dhelpl_t dhl){

    coeff_t* derivs = oarrss_derivs_alloc(arr1, der_r_sqrt);

    oarrss_feval_to(derivs, arr1, res, dhl);
    free(derivs);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void oarrss_pow_to(const oarrss_t* arr1, coeff_t e, oarrss_t* res, dhelpl_t dhl){

    coeff_t* derivs = oarrss_derivs_alloc_pow(arr1, e);

    oarrss_feval_to(derivs, arr1, res, dhl);
    free(derivs);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void oarrss_cbrt_to(const oarrss_t* arr1, oarrss_t* res, dhelpl_t dhl){

    oarrss_pow_to(arr1, 1.0 / 3.0, res, dhl);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void oarrss_sin_to(const oarrss_t* arr1, oarrss_t* res, dhelpl_t dhl){

    coeff_t* derivs = oarrss_derivs_alloc(arr1, der_r_sin);

    oarrss_feval_to(derivs, arr1, res, dhl);
    free(derivs);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void oarrss_cos_to(const oarrss_t* arr1, oarrss_t* res, dhelpl_t dhl){

    coeff_t* derivs = oarrss_derivs_alloc(arr1, der_r_cos);

    oarrss_feval_to(derivs, arr1, res, dhl);
    free(derivs);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void oarrss_tan_to(const oarrss_t* arr1, oarrss_t* res, dhelpl_t dhl){

    coeff_t* derivs = oarrss_derivs_alloc(arr1, der_r_tan);

    oarrss_feval_to(derivs, arr1, res, dhl);
    free(derivs);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void oarrss_asin_to(const oarrss_t* arr1, oarrss_t* res, dhelpl_t dhl){

    coeff_t* derivs = oarrss_derivs_alloc(arr1, der_r_asin);

    oarrss_feval_to(derivs, arr1, res, dhl);
    free(derivs);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void oarrss_acos_to(const oarrss_t* arr1, oarrss_t* res, dhelpl_t dhl){

    coeff_t* derivs = oarrss_derivs_alloc(arr1, der_r_acos);

    oarrss_feval_to(derivs, arr1, res, dhl);
    free(derivs);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void oarrss_atan_to(const oarrss_t* arr1, oarrss_t* res, dhelpl_t dhl){

    coeff_t* derivs = oarrss_derivs_alloc(arr1, der_r_atan);

    oarrss_feval_to(derivs, arr1, res, dhl);
    free(derivs);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void oarrss_sinh_to(const oarrss_t* arr1, oarrss_t* res, dhelpl_t dhl){

    coeff_t* derivs = oarrss_derivs_alloc(arr1, der_r_sinh);

    oarrss_feval_to(derivs, arr1, res, dhl);
    free(derivs);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void oarrss_cosh_to(const oarrss_t* arr1, oarrss_t* res, dhelpl_t dhl){

    coeff_t* derivs = oarrss_derivs_alloc(arr1, der_r_cosh);

    oarrss_feval_to(derivs, arr1, res, dhl);
    free(derivs);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void oarrss_tanh_to(const oarrss_t* arr1, oarrss_t* res, dhelpl_t dhl){

    coeff_t* derivs = oarrss_derivs_alloc(arr1, der_r_tanh);

    oarrss_feval_to(derivs, arr1, res, dhl);
    free(derivs);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void oarrss_asinh_to(const oarrss_t* arr1, oarrss_t* res, dhelpl_t dhl){

    coeff_t* derivs = oarrss_derivs_alloc(arr1, der_r_asinh);

    oarrss_feval_to(derivs, arr1, res, dhl);
    free(derivs);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void oarrss_acosh_to(const oarrss_t* arr1, oarrss_t* res, dhelpl_t dhl){

    coeff_t* derivs = oarrss_derivs_alloc(arr1, der_r_acosh);

    oarrss_feval_to(derivs, arr1, res, dhl);
    free(derivs);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void oarrss_atanh_to(const oarrss_t* arr1, oarrss_t* res, dhelpl_t dhl){

    coeff_t* derivs = oarrss_derivs_alloc(arr1, der_r_atanh);

    oarrss_feval_to(derivs, arr1, res, dhl);
    free(derivs);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void oarrss_erf_to(const oarrss_t* arr1, oarrss_t* res, dhelpl_t dhl){

    coeff_t* derivs = oarrss_derivs_alloc(arr1, der_r_erf);

    oarrss_feval_to(derivs, arr1, res, dhl);
    free(derivs);

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// ---------------------------------------     MATRIX PRODUCTS     ---------------------------------------
// -------------------------------------------------------------------------------------------------------

// *******************************************************************************************************
int oarrss_matmul_OO_to(const oarrss_t* arr1, const oarrss_t* arr2, oarrss_t* res, dhelpl_t dhl){

    sshelp_ws_t* ws = ssoti_ws();
    bases_t *p_u, *pos_a, *pos_b, nu;
    size_t nb = (size_t)arr1->nbases + arr2->nbases;
    ord_t trc, atop, btop, act;
    ndir_t nimag, maxNq, q;
    coeff_t *p_ea, *p_eb, *R, *work, *p_buf;
    uint64_t nrows = arr1->nrows, ninner = arr1->ncols, ncols = arr2->ncols;
    size_t needR, needWork, needA, needB;
    int own_a, own_b, status, direct;

    if (arr1->ncols != arr2->nrows){
        return OTI_LINALG_ERR_SIZE;
    }

    trc = (arr1->trc_order > arr2->trc_order) ? arr1->trc_order : arr2->trc_order;

    ssoti_ws_need(ws, 0, 0, 2 * nb + 1);
    p_u   = ws->p_bases;
    pos_a = ws->p_bases + nb;
    pos_b = pos_a + arr1->nbases;

    nu    = sshelp_union_bases(arr1->p_bases, arr1->nbases, arr2->p_bases, arr2->nbases, p_u, pos_a,
             pos_b);
    nimag = ssoti_nimag_checked(nu, trc);

    atop = (arr1->act_order < trc) ? arr1->act_order : trc;
    btop = (arr2->act_order < trc) ? arr2->act_order : trc;

    maxNq = 0;

    for (q = 0; q <= btop; q++){

        ndir_t Nq = sshelp_ndir_order(nu, (ord_t)q);

        if (Nq > maxNq){
            maxNq = Nq;
        }

    }

    // The kernel's size checks, done before `res` is touched so that an error leaves it unchanged.
    if (nrows > 0 && ncols > 0){

        if (!oti_lapack_fits(nrows) || !oti_lapack_fits(ninner) || !oti_lapack_fits(ncols)){
            return OTI_LINALG_ERR_SIZE;
        }

        for (q = 0; q <= btop; q++){

            if (!oti_lapack_fits(ncols * sshelp_ndir_order(nu, (ord_t)q))){
                return OTI_LINALG_ERR_SIZE;
            }

        }

    }

    own_a  = (arr1->nbases == nu && arr1->trc_order >= trc);
    own_b  = (arr2->nbases == nu && arr2->trc_order >= trc);
    direct = !oarrss_res_aliases(res, arr1) && !oarrss_res_aliases(res, arr2);

    needR    = (size_t)(1 + nimag) * nrows * ncols;
    needWork = (size_t)nrows * ncols * maxNq;
    needA    = own_a ? 0 : (size_t)(1 + nimag) * arr1->size;
    needB    = own_b ? 0 : (size_t)(1 + nimag) * arr2->size;

    // The product accumulates straight into `res` unless it aliases an operand; the work buffer and
    // the expanded operands are call-local, so nothing result-sized outlives the call.
    p_buf = oarrss_scratch_alloc((direct ? 0 : needR) + needWork + needA + needB);

    if (direct){

        R    = oarrss_result_begin(res, p_u, nu, trc, nrows, ncols);
        work = p_buf;

    } else {

        R    = p_buf;
        work = R + needR;

    }

    p_ea = work + needWork;
    p_eb = p_ea + needA;

    if (needR > 0){
        memset(R, 0, needR * sizeof(coeff_t));
    }

    if (own_a){
        p_ea = arr1->p_data;
    } else {
        oarrss_kernel_expand(arr1, pos_a, nu, trc, p_ea);
    }

    if (own_b){
        p_eb = arr2->p_data;
    } else {
        oarrss_kernel_expand(arr2, pos_b, nu, trc, p_eb);
    }

    status = oarrss_kernel_matmul_acc(p_ea, 0, atop, p_eb, 0, btop, nu, trc, nrows, ninner, ncols,
        1.0, R, work, dhl);

    if (status != 0){

        free(p_buf);
        return status;

    }

    if (!direct){

        R = oarrss_result_begin(res, p_u, nu, trc, nrows, ncols);
        memcpy(R, p_buf, needR * sizeof(coeff_t));

    }

    act = (ord_t)(((unsigned)atop + btop > 255) ? 255 : (atop + btop));

    oarrss_result_end(res, nu, trc, act, nrows, ncols);
    free(p_buf);

    return 0;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void oarrss_transpose_to(const oarrss_t* arr1, oarrss_t* res, dhelpl_t dhl){

    bases_t k = arr1->nbases;
    ord_t trc = arr1->trc_order, act = arr1->act_order;
    ndir_t nimag = sshelp_ndir_total(k, trc);
    size_t nblocks = 1 + nimag;
    uint64_t nrows = arr1->nrows, ncols = arr1->ncols, size = arr1->size;
    int direct = !oarrss_res_aliases(res, arr1);
    coeff_t *T, *p_buf = NULL;
    size_t b;
    uint64_t r, c;

    (void)dhl;

    // Straight into `res` unless it aliases the operand, which needs a call-local copy.
    if (direct){
        T = oarrss_result_begin(res, arr1->p_bases, k, trc, ncols, nrows);
    } else {
        T = p_buf = oarrss_scratch_alloc(nblocks * size);
    }

    for (b = 0; b < nblocks; b++){

        const coeff_t* src = arr1->p_data + b * size;
        coeff_t* dst = T + b * size;

        for (r = 0; r < nrows; r++){

            for (c = 0; c < ncols; c++){
                dst[c + r * ncols] = src[r + c * nrows];
            }

        }

    }

    if (!direct){

        T = oarrss_result_begin(res, arr1->p_bases, k, trc, ncols, nrows);
        memcpy(T, p_buf, nblocks * size * sizeof(coeff_t));
        free(p_buf);

    }

    oarrss_result_end(res, k, trc, act, ncols, nrows);

}
// -------------------------------------------------------------------------------------------------------
