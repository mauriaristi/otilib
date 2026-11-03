// Dense SoA arrays: elementwise algebra, functions, matrix products and transpose
// (include/oti/dense/soa/algebra.h). Template: src/c/semisparse/soa/algebra.c. Uses the statics of
// soa/base.c (dnob_nreals, dnob_result_shape) and soa/kernels.c (dnok_mul_acc, dnok_mul_acc_all,
// dnok_matmul_acc, dnok_matmul_fits), included just before this file.
//
// Operands are never expanded: a smaller-nact or lower-order operand is a prefix of the result
// layout and is read in place at its own block offsets. The result goes straight into `res`; when
// `res` aliases an operand whose layout differs from the result's (or for products, which read their
// operands while accumulating), the result is built in a call-local buffer that then replaces the
// buffer of `res`. Nothing coefficient-sized outlives a call. Unity-included from src/c/dense.c:
// static helpers carry the dnoa_ prefix.



// *******************************************************************************************************
// True when `res` is `x` or shares its buffer, so writing into `res` would overwrite `x`.
static inline int dnoa_aliases(const oarr_t* res, const oarr_t* x){

    return (res == x) || (oarr_data(res) != NULL && oarr_data(res) == oarr_data(x));

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// True when `x` is laid out over exactly (k, trc), so its blocks sit where the result's do.
static inline int dnoa_layout_is(const oarr_t* x, bases_t k, ord_t trc){

    return oarr_nact(x) == k && oarr_trc_order(x) == trc;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static inline ord_t dnoa_max_ord(ord_t a, ord_t b){

    return (a > b) ? a : b;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static inline bases_t dnoa_max_bases(bases_t a, bases_t b){

    return (a > b) ? a : b;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// act_order bound of a product: min(a + b, trc).
static inline ord_t dnoa_prod_act(ord_t a, ord_t b, ord_t trc){

    unsigned s = (unsigned)a + b;

    return (s < trc) ? (ord_t)s : trc;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// act_order of a division (as every function): trc, or 0 for a real result.
static inline void dnoa_set_act_function(oarr_t* res){

    oarr_set_act_order(res, (oarr_nact(res) == 0) ? 0 : oarr_trc_order(res));

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Destination of a result over (nact, trc, nrows x ncols): `res` itself, or a call-local array that
// replaces `res` at the end (dnoa_out_end()).
typedef struct {
    coeff_t*    p_r; ///< Where the result is written.
    oarr_t      own; ///< Call-local array (the result, when `res` aliases an operand), else empty.
    int       local; ///< Nonzero when the result is built in `own`.
    size_t        n; ///< Reals of the result layout.
    bases_t    nact; ///< Result nact.
    ord_t       trc; ///< Result truncation order.
} dnoa_out_t;
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Prepares the destination. With `local` set the result is built in a new array and `res` is not
// touched until dnoa_out_end(); otherwise `res` is shaped now (its values become unspecified). On a
// failure `res` is unchanged and nothing is allocated.
static int dnoa_out_begin(dnoa_out_t* out, oarr_t* res, int local, bases_t nact, ord_t trc,
                          uint64_t nrows, uint64_t ncols){

    uint64_t size;
    int status;

    out->own   = oarr_init();
    out->local = 0;
    out->nact  = nact;
    out->trc   = trc;

    if (dnob_shape_size(nrows, ncols, &size) != DN_OK || dnob_nreals(nact, trc, size, &out->n) != DN_OK){
        return DN_ERR_MEMORY;
    }

    if (local && out->n > 0){

        // The call-local result replaces the buffer of `res` at the end: never that of a view, nor one
        // shared with views or exports (contracts 7.2, 7.3).
        if (!dnob_can_replace(res)){
            return OTI_ERR_BUSY;
        }

        status = dnob_result_shape(&out->own, nact, nrows, ncols, trc, NULL);

        if (status != DN_OK){
            return status;
        }

        out->local = 1;
        out->p_r   = oarr_data(&out->own);

        return DN_OK;

    }

    status = dnob_result_shape(res, nact, nrows, ncols, trc, NULL);
    out->p_r = oarr_data(res);

    return status;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Finishes a result: moves a call-local array into `res` (releasing its old buffer) and sets
// act_order.
static void dnoa_out_end(dnoa_out_t* out, oarr_t* res, ord_t act){

    if (out->local){

        dnob_move(&out->own, res);
        out->local = 0;

    }

    oarr_set_act_order(res, (act < out->trc) ? act : out->trc);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Releases the destination after a failure (res keeps whatever valid state it had).
static void dnoa_out_abort(dnoa_out_t* out){

    oarr_free(&out->own);
    out->local = 0;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Number of order-p blocks an operand over (k, trc, act) contributes (orders above act are zero).
static inline ndir_t dnoa_nblk(bases_t k, ord_t trc, ord_t act, ord_t p){

    if (p > trc || p > act){
        return (p == 0) ? 1 : 0;
    }

    return sshelp_ndir_order(k, p);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// R = sa * a + sb * b over the result layout (k, trc): per order, the first blocks get both
// operands, then only the larger one, then zeros. Safe when R is the buffer of an operand laid out
// over (k, trc) (each value only reads the same position of that operand).
static void dnoa_axpby_kernel(coeff_t sa, const oarr_t* a, coeff_t sb, const oarr_t* b, bases_t k,
                              ord_t trc, coeff_t* R){

    uint64_t m = oarr_size(a);
    ord_t p;

    for (p = 0; p <= trc; p++){

        ndir_t Nr = (p == 0) ? 1 : sshelp_ndir_order(k, p);
        ndir_t Na = dnoa_nblk(oarr_nact(a), oarr_trc_order(a), oarr_act_order(a), p);
        ndir_t Nb = dnoa_nblk(oarr_nact(b), oarr_trc_order(b), oarr_act_order(b), p);
        size_t nboth = (size_t)((Na < Nb) ? Na : Nb) * m, na = (size_t)Na * m, nb = (size_t)Nb * m;
        size_t nr = (size_t)Nr * m, x;
        coeff_t* Rp = R + oarr_block_index(k, p, 0) * m;
        const coeff_t* Ap = (Na > 0) ? oarr_data(a) + oarr_block_index(oarr_nact(a), p, 0) * m : NULL;
        const coeff_t* Bp = (Nb > 0) ? oarr_data(b) + oarr_block_index(oarr_nact(b), p, 0) * m : NULL;

        for (x = 0; x < nboth; x++){
            Rp[x] = sa * Ap[x] + sb * Bp[x];
        }

        for (x = nboth; x < na; x++){
            Rp[x] = sa * Ap[x];
        }

        for (x = nboth; x < nb; x++){
            Rp[x] = sb * Bp[x];
        }

        for (x = (na > nb) ? na : nb; x < nr; x++){
            Rp[x] = 0.0;
        }

    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// res = sa * a + sb * b (sums and subtractions of arrays).
static int dnoa_axpby_to(coeff_t sa, const oarr_t* a, coeff_t sb, const oarr_t* b, oarr_t* res){

    bases_t k = dnoa_max_bases(oarr_nact(a), oarr_nact(b));
    ord_t trc = dnoa_max_ord(oarr_trc_order(a), oarr_trc_order(b));
    dnoa_out_t out;
    int local, status;

    if (oarr_nrows(a) != oarr_nrows(b) || oarr_ncols(a) != oarr_ncols(b)){
        return DN_ERR_SIZE;
    }

    // In place is safe when every aliased operand already has the result layout.
    local = (dnoa_aliases(res, a) && !dnoa_layout_is(a, k, trc))
            || (dnoa_aliases(res, b) && !dnoa_layout_is(b, k, trc));

    status = dnoa_out_begin(&out, res, local, k, trc, oarr_nrows(a), oarr_ncols(a));

    if (status != DN_OK){
        return status;
    }

    if (out.n > 0){
        dnoa_axpby_kernel(sa, a, sb, b, k, trc, out.p_r);
    }

    dnoa_out_end(&out, res, dnoa_max_ord(oarr_act_order(a), oarr_act_order(b)));

    return DN_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// res = sn * num + sa * arr, the scalar broadcast over the elements.
static int dnoa_axpby_oO_to(coeff_t sn, const otinum_t* num, coeff_t sa, const oarr_t* arr,
                            oarr_t* res){

    bases_t k = dnoa_max_bases(num->nact, oarr_nact(arr));
    ord_t trc = dnoa_max_ord(num->trc_order, oarr_trc_order(arr)), p;
    uint64_t m = oarr_size(arr);
    dnoa_out_t out;
    int status;

    status = dnoa_out_begin(&out, res, dnoa_aliases(res, arr) && !dnoa_layout_is(arr, k, trc), k, trc,
                            oarr_nrows(arr), oarr_ncols(arr));

    if (status != DN_OK){
        return status;
    }

    for (p = 0; p <= trc && out.n > 0; p++){

        ndir_t Nr = (p == 0) ? 1 : sshelp_ndir_order(k, p);
        ndir_t Na = dnoa_nblk(oarr_nact(arr), oarr_trc_order(arr), oarr_act_order(arr), p);
        ndir_t Nn = dnoa_nblk(num->nact, num->trc_order, num->act_order, p), i;
        coeff_t* Rp = out.p_r + oarr_block_index(k, p, 0) * m;
        const coeff_t* Ap = (Na > 0) ? oarr_data(arr) + oarr_block_index(oarr_nact(arr), p, 0) * m : NULL;
        const coeff_t* Cn = (p == 0) ? &num->re
                                     : num->p_im + ((Nn > 0) ? sshelp_order_offset(num->nact, p) : 0);

        for (i = 0; i < Nr; i++){

            coeff_t c = (i < Nn) ? sn * Cn[i] : 0.0;
            coeff_t* Ri = Rp + i * m;
            uint64_t e;

            if (i < Na){

                const coeff_t* Ai = Ap + i * m;

                for (e = 0; e < m; e++){
                    Ri[e] = c + sa * Ai[e];
                }

            } else {

                for (e = 0; e < m; e++){
                    Ri[e] = c;
                }

            }

        }

    }

    dnoa_out_end(&out, res, dnoa_max_ord(num->act_order, oarr_act_order(arr)));

    return DN_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// res = scale * arr + shift (shift added to the real block only).
static int dnoa_affine_to(coeff_t scale, const oarr_t* arr, coeff_t shift, oarr_t* res){

    size_t n, x;
    int status = oarr_copy_to(arr, res);

    if (status != DN_OK){
        return status;
    }

    n = (size_t)(1 + sshelp_ndir_total(oarr_nact(res), oarr_trc_order(res))) * oarr_size(res);

    if (scale != 1.0){

        for (x = 0; x < n; x++){
            oarr_data(res)[x] *= scale;
        }

    }

    if (shift != 0.0){

        for (x = 0; x < oarr_size(res); x++){
            oarr_data(res)[x] += shift;
        }

    }

    return DN_OK;

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// ---------------------------------------     ELEMENTWISE     -------------------------------------------
// -------------------------------------------------------------------------------------------------------

// *******************************************************************************************************
int oarr_sum_OO_to(const oarr_t* arr1, const oarr_t* arr2, oarr_t* res, dhelpl_t dhl){

    (void)dhl;

    return dnoa_axpby_to(1.0, arr1, 1.0, arr2, res);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oarr_sum_oO_to(const otinum_t* num, const oarr_t* arr1, oarr_t* res, dhelpl_t dhl){

    (void)dhl;

    return dnoa_axpby_oO_to(1.0, num, 1.0, arr1, res);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oarr_sum_rO_to(coeff_t val, const oarr_t* arr1, oarr_t* res, dhelpl_t dhl){

    (void)dhl;

    return dnoa_affine_to(1.0, arr1, val, res);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oarr_sub_OO_to(const oarr_t* arr1, const oarr_t* arr2, oarr_t* res, dhelpl_t dhl){

    (void)dhl;

    return dnoa_axpby_to(1.0, arr1, -1.0, arr2, res);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oarr_sub_oO_to(const otinum_t* num, const oarr_t* arr1, oarr_t* res, dhelpl_t dhl){

    (void)dhl;

    return dnoa_axpby_oO_to(1.0, num, -1.0, arr1, res);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oarr_sub_rO_to(coeff_t val, const oarr_t* arr1, oarr_t* res, dhelpl_t dhl){

    (void)dhl;

    return dnoa_affine_to(-1.0, arr1, val, res);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oarr_sub_Oo_to(const oarr_t* arr1, const otinum_t* num, oarr_t* res, dhelpl_t dhl){

    (void)dhl;

    return dnoa_axpby_oO_to(-1.0, num, 1.0, arr1, res);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oarr_sub_Or_to(const oarr_t* arr1, coeff_t val, oarr_t* res, dhelpl_t dhl){

    (void)dhl;

    return dnoa_affine_to(1.0, arr1, -val, res);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oarr_mul_OO_to(const oarr_t* arr1, const oarr_t* arr2, oarr_t* res, dhelpl_t dhl){

    bases_t k = dnoa_max_bases(oarr_nact(arr1), oarr_nact(arr2));
    ord_t trc = dnoa_max_ord(oarr_trc_order(arr1), oarr_trc_order(arr2));
    dnoa_out_t out;
    int status;

    if (oarr_nrows(arr1) != oarr_nrows(arr2) || oarr_ncols(arr1) != oarr_ncols(arr2)){
        return DN_ERR_SIZE;
    }

    // The product accumulates while it reads the operands: an aliased result is built locally.
    status = dnoa_out_begin(&out, res, dnoa_aliases(res, arr1) || dnoa_aliases(res, arr2), k, trc,
                            oarr_nrows(arr1), oarr_ncols(arr1));

    if (status != DN_OK){
        return status;
    }

    if (out.n > 0){

        memset(out.p_r, 0, out.n * sizeof(coeff_t));
        dnok_mul_acc_all(oarr_data(arr1), oarr_nact(arr1), 0, 0, oarr_act_order(arr1), oarr_data(arr2),
                         oarr_nact(arr2), 0,
                         oarr_act_order(arr2), k, trc, oarr_size(arr1), out.p_r, dhl);

    }

    dnoa_out_end(&out, res, dnoa_prod_act(oarr_act_order(arr1), oarr_act_order(arr2), trc));

    return DN_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oarr_mul_oO_to(const otinum_t* num, const oarr_t* arr1, oarr_t* res, dhelpl_t dhl){

    bases_t k = dnoa_max_bases(num->nact, oarr_nact(arr1));
    ord_t trc = dnoa_max_ord(num->trc_order, oarr_trc_order(arr1));
    ord_t ntop = (num->act_order < num->trc_order) ? num->act_order : num->trc_order;
    ndir_t nimag = sshelp_ndir_total(num->nact, ntop);
    coeff_t* C;
    dnoa_out_t out;
    int status;

    // The scalar's coefficients with the real part first, the block order of the kernel (call-local).
    if ((size_t)nimag >= SIZE_MAX / sizeof(coeff_t)){
        return DN_ERR_MEMORY;
    }

    C = (coeff_t*)malloc((1 + (size_t)nimag) * sizeof(coeff_t));

    if (C == NULL){
        return DN_ERR_MEMORY;
    }

    C[0] = num->re;

    if (nimag > 0){
        memcpy(C + 1, num->p_im, (size_t)nimag * sizeof(coeff_t));
    }

    status = dnoa_out_begin(&out, res, dnoa_aliases(res, arr1), k, trc, oarr_nrows(arr1),
                            oarr_ncols(arr1));

    if (status != DN_OK){

        free(C);
        return status;

    }

    if (out.n > 0){

        memset(out.p_r, 0, out.n * sizeof(coeff_t));
        dnok_mul_acc_all(C, num->nact, 1, 0, ntop, oarr_data(arr1), oarr_nact(arr1), 0,
                         oarr_act_order(arr1), k,
                         trc, oarr_size(arr1), out.p_r, dhl);

    }

    free(C);
    dnoa_out_end(&out, res, dnoa_prod_act(ntop, oarr_act_order(arr1), trc));

    return DN_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oarr_mul_rO_to(coeff_t val, const oarr_t* arr1, oarr_t* res, dhelpl_t dhl){

    (void)dhl;

    return dnoa_affine_to(val, arr1, 0.0, res);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oarr_div_OO_to(const oarr_t* arr1, const oarr_t* arr2, oarr_t* res, dhelpl_t dhl){

    oarr_t inv = oarr_init();
    int status;

    if (oarr_nrows(arr1) != oarr_nrows(arr2) || oarr_ncols(arr1) != oarr_ncols(arr2)){
        return DN_ERR_SIZE;
    }

    status = oarr_pow_to(arr2, -1.0, &inv, dhl);

    if (status == DN_OK){
        status = oarr_mul_OO_to(arr1, &inv, res, dhl);
    }

    if (status == DN_OK){
        dnoa_set_act_function(res);
    }

    oarr_free(&inv);

    return status;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oarr_div_oO_to(const otinum_t* num, const oarr_t* arr1, oarr_t* res, dhelpl_t dhl){

    oarr_t inv = oarr_init();
    int status = oarr_pow_to(arr1, -1.0, &inv, dhl);

    if (status == DN_OK){
        status = oarr_mul_oO_to(num, &inv, res, dhl);
    }

    if (status == DN_OK){
        dnoa_set_act_function(res);
    }

    oarr_free(&inv);

    return status;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oarr_div_rO_to(coeff_t val, const oarr_t* arr1, oarr_t* res, dhelpl_t dhl){

    int status = oarr_pow_to(arr1, -1.0, res, dhl);

    if (status == DN_OK){
        status = oarr_mul_rO_to(val, res, res, dhl);
    }

    return status;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oarr_div_Oo_to(const oarr_t* arr1, const otinum_t* num, oarr_t* res, dhelpl_t dhl){

    otinum_t inv = oti_init();
    int status = oti_pow_to(num, -1.0, &inv, dhl);

    if (status == DN_OK){
        status = oarr_mul_oO_to(&inv, arr1, res, dhl);
    }

    if (status == DN_OK){
        dnoa_set_act_function(res);
    }

    oti_free(&inv);

    return status;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oarr_div_Or_to(const oarr_t* arr1, coeff_t val, oarr_t* res, dhelpl_t dhl){

    return oarr_mul_rO_to(1.0 / val, arr1, res, dhl);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oarr_neg_to(const oarr_t* arr1, oarr_t* res, dhelpl_t dhl){

    (void)dhl;

    return dnoa_affine_to(-1.0, arr1, 0.0, res);

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// ---------------------------------------     FUNCTIONS     ---------------------------------------------
// -------------------------------------------------------------------------------------------------------

// *******************************************************************************************************
// First two Taylor terms for a run of n elements (oarr_feval_to() with act >= 1, trc >= 1): R gets
// f(re) in block 0 and f'(re) A_b in every imaginary block b. D is f(re) of the run, D + sd f'(re);
// A, R are block 0 of the run with block strides sa, sr.
static void dnoa_feval_head(const coeff_t* D, int64_t sd, const coeff_t* A, int64_t sa, coeff_t* R,
                            int64_t sr, uint64_t nblocks, int64_t n){

    uint64_t b;
    int64_t e;

    for (e = 0; e < n; e++){
        R[e] = D[e];
    }

    for (b = 1; b < nblocks; b++){

        for (e = 0; e < n; e++){
            R[(int64_t)b * sr + e] = D[sd + e] * A[(int64_t)b * sa + e];
        }

    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Taylor term i >= 2 for a run of n elements: Q = P * d (d the imaginary part of A; P = d^(i-1), its
// blocks below order i - 1 never read; Q zeroed from the first order-i block), then R += (Di / factor)
// Q from that block on. pnz is the whole-array nonzero flag of every P block (dnok_mul_acc()). Every
// operand is block 0 of the run with its block stride.
static void dnoa_feval_step(const coeff_t* P, int64_t sp, const uint8_t* pnz, const coeff_t* A,
                            int64_t sa, coeff_t* Q, int64_t sq, coeff_t* R, int64_t sr,
                            const coeff_t* Di, coeff_t factor, bases_t k, ord_t trc, ord_t act,
                            ord_t i, int64_t n, dhelpl_t dhl){

    uint64_t b, nblocks = dnob_nblocks(k, trc), b0 = oarr_block_index(k, i, 0);
    ord_t lo = (ord_t)(i - 1);
    ord_t hi = ((unsigned)(i - 1) * act < trc) ? (ord_t)((i - 1) * act) : trc;
    int64_t e;

    // d^i has orders >= i only: its lower blocks are never read.
    for (b = b0; b < nblocks; b++){
        memset(Q + (int64_t)b * sq, 0, (size_t)n * sizeof(coeff_t));
    }

    dnok_mul_acc(P, sp, k, 0, lo, hi, A, sa, k, 1, act, Q, sq, k, trc, n, pnz, dhl);

    for (b = b0; b < nblocks; b++){

        for (e = 0; e < n; e++){
            R[(int64_t)b * sr + e] += (Di[e] / factor) * Q[(int64_t)b * sq + e];
        }

    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Arguments of the feval chunks: the head (step == 0) or Taylor term `step` >= 2.
typedef struct {
    const coeff_t* derivs; ///< Per-element derivatives, order i at derivs + i * m.
    const coeff_t*      A; ///< Operand blocks.
    const coeff_t*      P; ///< Running power d^(step-1) (A for step 2).
    const uint8_t*    pnz; ///< Whole-array nonzero flags of the blocks of P.
    coeff_t*            Q; ///< Next running power d^step.
    coeff_t*            R; ///< Result blocks.
    uint64_t            m; ///< Block stride of every operand and number of elements.
    dhelpl_t          dhl; ///< Direction helper.
    coeff_t        factor; ///< step!.
    bases_t             k; ///< nact.
    ord_t             trc; ///< Truncation order.
    ord_t             act; ///< act_order of the operand.
    ord_t            step; ///< 0 for the head, else the Taylor term.
} dnoa_feval_job_t;
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static int dnoa_feval_chunk(void* arg, int64_t chunk, int32_t worker){

    const dnoa_feval_job_t* j = (const dnoa_feval_job_t*)arg;
    uint64_t e0 = (uint64_t)chunk * DNOK_CHUNK_ELEMS, e1 = e0 + DNOK_CHUNK_ELEMS;
    int64_t sm = (int64_t)j->m;

    (void)worker;

    if (e1 > j->m){
        e1 = j->m;
    }

    if (j->step == 0){

        dnoa_feval_head(j->derivs + e0, sm, j->A + e0, sm, j->R + e0, sm, dnob_nblocks(j->k, j->trc),
                        (int64_t)(e1 - e0));

    } else {

        dnoa_feval_step(j->P + e0, sm, j->pnz, j->A + e0, sm, j->Q + e0, sm, j->R + e0, sm,
                        j->derivs + (size_t)j->step * j->m + e0, j->factor, j->k, j->trc, j->act, j->step,
                        (int64_t)(e1 - e0), j->dhl);

    }

    return OTI_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// The Taylor series of oarr_feval_to() over all m elements (act >= 1, trc >= 1), in the fixed chunks of
// dnok_for(): the head, then one pass per term i = 2..trc over all chunks, so that the zero test of each
// running-power block covers the whole array (1.x at one thread, for every worker count). W1, W2 hold
// the running powers (W2 from order 3 on). Returns DN_OK or DN_ERR_MEMORY (the flag tables).
static int dnoa_feval_all(const coeff_t* derivs, const coeff_t* A, bases_t k, ord_t trc, ord_t act,
                          uint64_t m, coeff_t* R, coeff_t* W1, coeff_t* W2, dhelpl_t dhl){

    uint64_t nblocks = dnob_nblocks(k, trc);
    uint8_t nz_stack[2 * DNOK_NZ_STACK], *nz, *pnz, *qnz;
    dnoa_feval_job_t j;
    ord_t i;

    nz = (nblocks <= DNOK_NZ_STACK) ? nz_stack : (uint8_t*)malloc(2 * (size_t)nblocks);

    if (nz == NULL){
        return DN_ERR_MEMORY;
    }

    pnz = nz;
    qnz = nz + nblocks;

    j.derivs = derivs;  j.A = A;    j.R = R;      j.m = m;      j.dhl = dhl;
    j.k = k;            j.trc = trc; j.act = act; j.step = 0;   j.factor = 1.0;
    j.P = A;            j.pnz = pnz; j.Q = NULL;

    dnok_for(m, DNOK_NS_PAIR * 2.0 * (double)nblocks, dnoa_feval_chunk, &j);

    // P = d for the term 2: its blocks of orders 1 .. min(act, trc).
    if (trc >= 2){
        dnok_block_nz(A, (int64_t)m, m, 1, dnob_nblocks(k, (act < trc) ? act : trc), pnz);
    }

    for (i = 2; i <= trc; i++){

        ord_t lo = (ord_t)(i - 1);
        ord_t hi = ((unsigned)(i - 1) * act < trc) ? (ord_t)((i - 1) * act) : trc;
        ord_t qhi = ((unsigned)i * act < trc) ? (ord_t)(i * act) : trc;
        uint8_t* t;

        j.step   = i;
        j.factor = j.factor * i;
        j.Q      = (j.P == W1) ? W2 : W1;
        j.pnz    = pnz;

        dnok_for(m, DNOK_NS_PAIR * (dnok_pair_count(k, lo, hi, k, 1, act, trc)
                                    + 2.0 * (double)(nblocks - oarr_block_index(k, i, 0))),
                 dnoa_feval_chunk, &j);

        // The next term reads Q's blocks of orders i .. min(i * act, trc).
        if (i < trc){
            dnok_block_nz(j.Q, (int64_t)m, m, oarr_block_index(k, i, 0), dnob_nblocks(k, qhi), qnz);
        }

        j.P = j.Q;
        t   = pnz;
        pnz = qnz;
        qnz = t;

    }

    if (nz != nz_stack){
        free(nz);
    }

    return DN_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oarr_feval_to(const coeff_t* derivs, const oarr_t* arr1, oarr_t* res, dhelpl_t dhl){

    bases_t k = oarr_nact(arr1);
    ord_t trc = oarr_trc_order(arr1), act = oarr_act_order(arr1);
    uint64_t m = oarr_size(arr1);
    size_t nw, n;
    coeff_t *W = NULL, *W1, *W2;
    dnoa_out_t out;
    int status;

    // No imaginary part: f(arr) is real, in the input's layout.
    if (k == 0 || act == 0 || trc == 0 || m == 0){

        uint64_t e;

        status = oarr_zeros_to(k, oarr_nrows(arr1), oarr_ncols(arr1), trc, res);

        for (e = 0; e < m && status == DN_OK; e++){
            oarr_data(res)[e] = derivs[e];
        }

        return status;

    }

    if (dnob_nreals(k, trc, m, &n) != DN_OK){
        return DN_ERR_MEMORY;
    }

    // Running powers: one buffer for order 2, two from order 3 (call-local).
    nw = (trc >= 3) ? 2 : ((trc == 2) ? 1 : 0);

    if (nw > 0){

        if (n > SIZE_MAX / sizeof(coeff_t) / nw){
            return DN_ERR_MEMORY;
        }

        W = (coeff_t*)malloc(nw * n * sizeof(coeff_t));

        if (W == NULL){
            return DN_ERR_MEMORY;
        }

    }

    W1 = W;
    W2 = (nw == 2) ? W + n : NULL;

    status = dnoa_out_begin(&out, res, dnoa_aliases(res, arr1), k, trc, oarr_nrows(arr1),
                            oarr_ncols(arr1));

    if (status != DN_OK){

        free(W);
        return status;

    }

    status = dnoa_feval_all(derivs, oarr_data(arr1), k, trc, act, m, out.p_r, W1, W2, dhl);
    free(W);

    if (status != DN_OK){

        dnoa_out_abort(&out);
        return status;

    }

    dnoa_out_end(&out, res, trc);

    return DN_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Per-element derivatives derivs[i*m + e] = f^(i)(re_e), i = 0..trc, from a der_r_* function (with
// `fn`) or der_r_pow (`fn` NULL, exponent `ex`). Caller frees *p_derivs.
static int dnoa_derivs(const oarr_t* arr1, void (*fn)(coeff_t, ord_t, coeff_t*), coeff_t ex,
                       coeff_t** p_derivs){

    uint64_t e, m = oarr_size(arr1);
    ord_t trc = oarr_trc_order(arr1), i;
    coeff_t tmp[_MAXORDER_OTI + 1];
    coeff_t* derivs;

    *p_derivs = NULL;

    if (trc > _MAXORDER_OTI){
        return DN_ERR_INDEX;
    }

    if (m > SIZE_MAX / sizeof(coeff_t) / ((size_t)trc + 1)){
        return DN_ERR_MEMORY;
    }

    derivs = (coeff_t*)malloc(((size_t)trc + 1) * m * sizeof(coeff_t) + 1);

    if (derivs == NULL){
        return DN_ERR_MEMORY;
    }

    for (e = 0; e < m; e++){

        if (fn != NULL){
            fn(oarr_data(arr1)[e], trc, tmp);
        } else {
            der_r_pow(oarr_data(arr1)[e], ex, trc, tmp);
        }

        for (i = 0; i <= trc; i++){
            derivs[(size_t)i * m + e] = tmp[i];
        }

    }

    *p_derivs = derivs;

    return DN_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// f(arr1) through oarr_feval_to() for a der_r_* function (or der_r_pow when fn is NULL).
static int dnoa_function_to(const oarr_t* arr1, void (*fn)(coeff_t, ord_t, coeff_t*), coeff_t ex,
                            oarr_t* res, dhelpl_t dhl){

    coeff_t* derivs;
    int status = dnoa_derivs(arr1, fn, ex, &derivs);

    if (status == DN_OK){
        status = oarr_feval_to(derivs, arr1, res, dhl);
    }

    free(derivs);

    return status;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oarr_exp_to(const oarr_t* arr1, oarr_t* res, dhelpl_t dhl){

    return dnoa_function_to(arr1, der_r_exp, 0.0, res, dhl);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oarr_log_to(const oarr_t* arr1, oarr_t* res, dhelpl_t dhl){

    return dnoa_function_to(arr1, der_r_log, 0.0, res, dhl);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oarr_log10_to(const oarr_t* arr1, oarr_t* res, dhelpl_t dhl){

    return dnoa_function_to(arr1, der_r_log10, 0.0, res, dhl);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oarr_sqrt_to(const oarr_t* arr1, oarr_t* res, dhelpl_t dhl){

    return dnoa_function_to(arr1, der_r_sqrt, 0.0, res, dhl);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oarr_cbrt_to(const oarr_t* arr1, oarr_t* res, dhelpl_t dhl){

    return dnoa_function_to(arr1, NULL, 1.0 / 3.0, res, dhl);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oarr_sin_to(const oarr_t* arr1, oarr_t* res, dhelpl_t dhl){

    return dnoa_function_to(arr1, der_r_sin, 0.0, res, dhl);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oarr_cos_to(const oarr_t* arr1, oarr_t* res, dhelpl_t dhl){

    return dnoa_function_to(arr1, der_r_cos, 0.0, res, dhl);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oarr_tan_to(const oarr_t* arr1, oarr_t* res, dhelpl_t dhl){

    return dnoa_function_to(arr1, der_r_tan, 0.0, res, dhl);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oarr_asin_to(const oarr_t* arr1, oarr_t* res, dhelpl_t dhl){

    return dnoa_function_to(arr1, der_r_asin, 0.0, res, dhl);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oarr_acos_to(const oarr_t* arr1, oarr_t* res, dhelpl_t dhl){

    return dnoa_function_to(arr1, der_r_acos, 0.0, res, dhl);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oarr_atan_to(const oarr_t* arr1, oarr_t* res, dhelpl_t dhl){

    return dnoa_function_to(arr1, der_r_atan, 0.0, res, dhl);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oarr_sinh_to(const oarr_t* arr1, oarr_t* res, dhelpl_t dhl){

    return dnoa_function_to(arr1, der_r_sinh, 0.0, res, dhl);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oarr_cosh_to(const oarr_t* arr1, oarr_t* res, dhelpl_t dhl){

    return dnoa_function_to(arr1, der_r_cosh, 0.0, res, dhl);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oarr_tanh_to(const oarr_t* arr1, oarr_t* res, dhelpl_t dhl){

    return dnoa_function_to(arr1, der_r_tanh, 0.0, res, dhl);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oarr_asinh_to(const oarr_t* arr1, oarr_t* res, dhelpl_t dhl){

    return dnoa_function_to(arr1, der_r_asinh, 0.0, res, dhl);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oarr_acosh_to(const oarr_t* arr1, oarr_t* res, dhelpl_t dhl){

    return dnoa_function_to(arr1, der_r_acosh, 0.0, res, dhl);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oarr_atanh_to(const oarr_t* arr1, oarr_t* res, dhelpl_t dhl){

    return dnoa_function_to(arr1, der_r_atanh, 0.0, res, dhl);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oarr_erf_to(const oarr_t* arr1, oarr_t* res, dhelpl_t dhl){

    return dnoa_function_to(arr1, der_r_erf, 0.0, res, dhl);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oarr_pow_to(const oarr_t* arr1, coeff_t e, oarr_t* res, dhelpl_t dhl){

    return dnoa_function_to(arr1, NULL, e, res, dhl);

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// ---------------------------------------     MATRIX PRODUCTS     ---------------------------------------
// -------------------------------------------------------------------------------------------------------

// *******************************************************************************************************
int oarr_matmul_OO_to(const oarr_t* arr1, const oarr_t* arr2, oarr_t* res, dhelpl_t dhl){

    bases_t k = dnoa_max_bases(oarr_nact(arr1), oarr_nact(arr2));
    ord_t trc = dnoa_max_ord(oarr_trc_order(arr1), oarr_trc_order(arr2)), q;
    ord_t atop = oarr_act_order(arr1), btop = oarr_act_order(arr2);
    uint64_t nrows = oarr_nrows(arr1), ninner = oarr_ncols(arr1), ncols = oarr_ncols(arr2);
    ndir_t maxNq = 0;
    size_t nwork;
    coeff_t* work = NULL;
    dnoa_out_t out;
    int status;

    if (!dnob_is_matrix(arr1) || !dnob_is_matrix(arr2) || oarr_ncols(arr1) != oarr_nrows(arr2)){
        return DN_ERR_SIZE;
    }

    // The kernel's size checks, done before `res` is touched so that an error leaves it unchanged.
    if (nrows > 0 && ncols > 0){

        status = dnok_matmul_fits(oarr_nact(arr2), 0, btop, nrows, ninner, ncols);

        if (status != DN_OK){
            return status;
        }

    }

    // Scratch of one A_i x [order-q blocks of B] product, q >= 1 (identity products need none).
    for (q = 1; q <= btop && atop > 0; q++){

        ndir_t Nq = sshelp_ndir_order(oarr_nact(arr2), q);

        if (Nq > maxNq){
            maxNq = Nq;
        }

    }

    if (maxNq > 0 && nrows * ncols > SIZE_MAX / sizeof(coeff_t) / maxNq){
        return DN_ERR_MEMORY;
    }

    nwork = (size_t)(nrows * ncols) * (size_t)maxNq;

    if (nwork > 0){

        work = (coeff_t*)malloc(nwork * sizeof(coeff_t));

        if (work == NULL){
            return DN_ERR_MEMORY;
        }

    }

    status = dnoa_out_begin(&out, res, dnoa_aliases(res, arr1) || dnoa_aliases(res, arr2), k, trc,
                            nrows, ncols);

    if (status != DN_OK){

        free(work);
        return status;

    }

    if (out.n > 0){

        memset(out.p_r, 0, out.n * sizeof(coeff_t));
        status = dnok_matmul_acc(oarr_data(arr1), oarr_bstride(arr1), oarr_nact(arr1), 0, atop,
                                 oarr_data(arr2), oarr_bstride(arr2), oarr_nact(arr2), 0, btop, k, trc,
                                 nrows, ninner, ncols, 1.0, out.p_r, (int64_t)(nrows * ncols), work, dhl);

    }

    free(work);

    if (status != DN_OK){

        dnoa_out_abort(&out);
        return status;

    }

    dnoa_out_end(&out, res, dnoa_prod_act(atop, btop, trc));

    return DN_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oarr_transpose_to(const oarr_t* arr1, oarr_t* res, dhelpl_t dhl){

    bases_t k = oarr_nact(arr1);
    ord_t trc = oarr_trc_order(arr1), act = oarr_act_order(arr1);
    uint64_t nrows = oarr_nrows(arr1), ncols = oarr_ncols(arr1), size = oarr_size(arr1), r, c;
    size_t b, nblocks;
    dnoa_out_t out;
    int status;

    (void)dhl;

    if (!dnob_is_matrix(arr1)){
        return DN_ERR_SIZE;
    }

    status = dnoa_out_begin(&out, res, dnoa_aliases(res, arr1), k, trc, ncols, nrows);

    if (status != DN_OK){
        return status;
    }

    nblocks = (size > 0) ? out.n / size : 0;

    for (b = 0; b < nblocks; b++){

        const coeff_t* src = oarr_data(arr1) + b * size;
        coeff_t* dst = out.p_r + b * size;

        for (c = 0; c < ncols; c++){

            for (r = 0; r < nrows; r++){
                dst[c + r * ncols] = src[r + c * nrows];
            }

        }

    }

    dnoa_out_end(&out, res, act);

    return DN_OK;

}
// -------------------------------------------------------------------------------------------------------
