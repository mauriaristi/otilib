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

#ifdef _OPENMP
#include <omp.h>
#endif


// *******************************************************************************************************
// True when `res` is `x` or shares its buffer, so writing into `res` would overwrite `x`.
static inline int dnoa_aliases(const oarr_t* res, const oarr_t* x){

    return (res == x) || (res->p_data != NULL && res->p_data == x->p_data);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// True when `x` is laid out over exactly (k, trc), so its blocks sit where the result's do.
static inline int dnoa_layout_is(const oarr_t* x, bases_t k, ord_t trc){

    return x->nact == k && x->trc_order == trc;

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

    res->act_order = (res->nact == 0) ? 0 : res->trc_order;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Destination of a result over (nact, trc, nrows x ncols): `res` itself, or a call-local buffer that
// replaces the buffer of `res` at the end (dnoa_out_end()).
typedef struct {
    coeff_t*    p_r; ///< Where the result is written.
    coeff_t*  p_own; ///< Call-local buffer (the result, when `res` aliases an operand), else NULL.
    size_t        n; ///< Reals of the result layout.
    bases_t    nact; ///< Result nact.
    ord_t       trc; ///< Result truncation order.
    uint64_t  nrows; ///< Result rows.
    uint64_t  ncols; ///< Result columns.
} dnoa_out_t;
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Prepares the destination. With `local` set the result is built in a new buffer and `res` is not
// touched until dnoa_out_end(); otherwise `res` is shaped now (its values become unspecified). On a
// failure `res` is unchanged and nothing is allocated.
static int dnoa_out_begin(dnoa_out_t* out, oarr_t* res, int local, bases_t nact, ord_t trc,
                          uint64_t nrows, uint64_t ncols){

    uint64_t size;
    int status;

    out->p_own = NULL;
    out->nact  = nact;
    out->trc   = trc;
    out->nrows = nrows;
    out->ncols = ncols;

    if (dnob_shape_size(nrows, ncols, &size) != DN_OK || dnob_nreals(nact, trc, size, &out->n) != DN_OK){
        return DN_ERR_MEMORY;
    }

    if (local && out->n > 0){

        out->p_own = (coeff_t*)malloc(out->n * sizeof(coeff_t));

        if (out->p_own == NULL){
            return DN_ERR_MEMORY;
        }

        out->p_r = out->p_own;

        return DN_OK;

    }

    status = dnob_result_shape(res, nact, nrows, ncols, trc, NULL);
    out->p_r = res->p_data;

    return status;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Finishes a result: moves a call-local buffer into `res` and sets its layout and act_order.
static void dnoa_out_end(dnoa_out_t* out, oarr_t* res, ord_t act){

    if (out->p_own != NULL){

        free(res->p_data);
        res->p_data = out->p_own;
        res->nbases = out->nact;
        out->p_own  = NULL;

    }

    res->nact      = out->nact;
    res->trc_order = out->trc;
    res->act_order = (act < out->trc) ? act : out->trc;
    res->nrows     = out->nrows;
    res->ncols     = out->ncols;
    res->size      = out->nrows * out->ncols;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Releases the destination after a failure (res keeps whatever valid state it had).
static void dnoa_out_abort(dnoa_out_t* out){

    free(out->p_own);
    out->p_own = NULL;

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

    uint64_t m = a->size;
    ord_t p;

    for (p = 0; p <= trc; p++){

        ndir_t Nr = (p == 0) ? 1 : sshelp_ndir_order(k, p);
        ndir_t Na = dnoa_nblk(a->nact, a->trc_order, a->act_order, p);
        ndir_t Nb = dnoa_nblk(b->nact, b->trc_order, b->act_order, p);
        size_t nboth = (size_t)((Na < Nb) ? Na : Nb) * m, na = (size_t)Na * m, nb = (size_t)Nb * m;
        size_t nr = (size_t)Nr * m, x;
        coeff_t* Rp = R + oarr_block_index(k, p, 0) * m;
        const coeff_t* Ap = (Na > 0) ? a->p_data + oarr_block_index(a->nact, p, 0) * m : NULL;
        const coeff_t* Bp = (Nb > 0) ? b->p_data + oarr_block_index(b->nact, p, 0) * m : NULL;

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

    bases_t k = dnoa_max_bases(a->nact, b->nact);
    ord_t trc = dnoa_max_ord(a->trc_order, b->trc_order);
    dnoa_out_t out;
    int local, status;

    if (a->nrows != b->nrows || a->ncols != b->ncols){
        return DN_ERR_SIZE;
    }

    // In place is safe when every aliased operand already has the result layout.
    local = (dnoa_aliases(res, a) && !dnoa_layout_is(a, k, trc))
            || (dnoa_aliases(res, b) && !dnoa_layout_is(b, k, trc));

    status = dnoa_out_begin(&out, res, local, k, trc, a->nrows, a->ncols);

    if (status != DN_OK){
        return status;
    }

    if (out.n > 0){
        dnoa_axpby_kernel(sa, a, sb, b, k, trc, out.p_r);
    }

    dnoa_out_end(&out, res, dnoa_max_ord(a->act_order, b->act_order));

    return DN_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// res = sn * num + sa * arr, the scalar broadcast over the elements.
static int dnoa_axpby_oO_to(coeff_t sn, const otinum_t* num, coeff_t sa, const oarr_t* arr,
                            oarr_t* res){

    bases_t k = dnoa_max_bases(num->nact, arr->nact);
    ord_t trc = dnoa_max_ord(num->trc_order, arr->trc_order), p;
    uint64_t m = arr->size;
    dnoa_out_t out;
    int status;

    status = dnoa_out_begin(&out, res, dnoa_aliases(res, arr) && !dnoa_layout_is(arr, k, trc), k, trc,
                            arr->nrows, arr->ncols);

    if (status != DN_OK){
        return status;
    }

    for (p = 0; p <= trc && out.n > 0; p++){

        ndir_t Nr = (p == 0) ? 1 : sshelp_ndir_order(k, p);
        ndir_t Na = dnoa_nblk(arr->nact, arr->trc_order, arr->act_order, p);
        ndir_t Nn = dnoa_nblk(num->nact, num->trc_order, num->act_order, p), i;
        coeff_t* Rp = out.p_r + oarr_block_index(k, p, 0) * m;
        const coeff_t* Ap = (Na > 0) ? arr->p_data + oarr_block_index(arr->nact, p, 0) * m : NULL;
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

    dnoa_out_end(&out, res, dnoa_max_ord(num->act_order, arr->act_order));

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

    n = (size_t)(1 + sshelp_ndir_total(res->nact, res->trc_order)) * res->size;

    if (scale != 1.0){

        for (x = 0; x < n; x++){
            res->p_data[x] *= scale;
        }

    }

    if (shift != 0.0){

        for (x = 0; x < res->size; x++){
            res->p_data[x] += shift;
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

    bases_t k = dnoa_max_bases(arr1->nact, arr2->nact);
    ord_t trc = dnoa_max_ord(arr1->trc_order, arr2->trc_order);
    dnoa_out_t out;
    int status;

    if (arr1->nrows != arr2->nrows || arr1->ncols != arr2->ncols){
        return DN_ERR_SIZE;
    }

    // The product accumulates while it reads the operands: an aliased result is built locally.
    status = dnoa_out_begin(&out, res, dnoa_aliases(res, arr1) || dnoa_aliases(res, arr2), k, trc,
                            arr1->nrows, arr1->ncols);

    if (status != DN_OK){
        return status;
    }

    if (out.n > 0){

        memset(out.p_r, 0, out.n * sizeof(coeff_t));
        dnok_mul_acc_all(arr1->p_data, arr1->nact, 0, 0, arr1->act_order, arr2->p_data, arr2->nact, 0,
                         arr2->act_order, k, trc, arr1->size, out.p_r, dhl);

    }

    dnoa_out_end(&out, res, dnoa_prod_act(arr1->act_order, arr2->act_order, trc));

    return DN_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oarr_mul_oO_to(const otinum_t* num, const oarr_t* arr1, oarr_t* res, dhelpl_t dhl){

    bases_t k = dnoa_max_bases(num->nact, arr1->nact);
    ord_t trc = dnoa_max_ord(num->trc_order, arr1->trc_order);
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

    status = dnoa_out_begin(&out, res, dnoa_aliases(res, arr1), k, trc, arr1->nrows, arr1->ncols);

    if (status != DN_OK){

        free(C);
        return status;

    }

    if (out.n > 0){

        memset(out.p_r, 0, out.n * sizeof(coeff_t));
        dnok_mul_acc_all(C, num->nact, 1, 0, ntop, arr1->p_data, arr1->nact, 0, arr1->act_order, k,
                         trc, arr1->size, out.p_r, dhl);

    }

    free(C);
    dnoa_out_end(&out, res, dnoa_prod_act(ntop, arr1->act_order, trc));

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

    if (arr1->nrows != arr2->nrows || arr1->ncols != arr2->ncols){
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
// Taylor series of the elements [e0, e1) (oarr_feval_to() with act >= 1, trc >= 1): R gets
// f(re) + sum_i f^(i)(re)/i! d^i with d the imaginary part of A. W1, W2 hold the running powers
// (W2 is only used from order 3 on).
static void dnoa_feval_range(const coeff_t* derivs, const coeff_t* A, bases_t k, ord_t trc, ord_t act,
                             uint64_t m, uint64_t e0, uint64_t e1, coeff_t* R, coeff_t* W1,
                             coeff_t* W2, dhelpl_t dhl){

    size_t b, nblocks = 1 + sshelp_ndir_total(k, trc);
    const coeff_t* P = A;
    coeff_t *Q, factor = 1.0;
    uint64_t e;
    ord_t i;

    for (e = e0; e < e1; e++){
        R[e] = derivs[e];
    }

    for (b = 1; b < nblocks; b++){

        for (e = e0; e < e1; e++){
            R[b * m + e] = derivs[m + e] * A[b * m + e];
        }

    }

    for (i = 2; i <= trc; i++){

        ord_t lo = (ord_t)(i - 1);
        ord_t hi = ((unsigned)(i - 1) * act < trc) ? (ord_t)((i - 1) * act) : trc;
        const coeff_t* d_i = derivs + (size_t)i * m;
        size_t b0 = oarr_block_index(k, i, 0);

        factor *= i;
        Q = (P == W1) ? W2 : W1;

        // d^i has orders >= i only: its lower blocks are never read.
        for (b = b0; b < nblocks; b++){
            memset(Q + b * m + e0, 0, (size_t)(e1 - e0) * sizeof(coeff_t));
        }

        dnok_mul_acc(P, k, 0, lo, hi, A, k, 1, act, k, trc, m, e0, e1, Q, dhl);

        for (b = b0; b < nblocks; b++){

            for (e = e0; e < e1; e++){
                R[b * m + e] += (d_i[e] / factor) * Q[b * m + e];
            }

        }

        P = Q;

    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oarr_feval_to(const coeff_t* derivs, const oarr_t* arr1, oarr_t* res, dhelpl_t dhl){

    bases_t k = arr1->nact;
    ord_t trc = arr1->trc_order, act = arr1->act_order;
    uint64_t m = arr1->size;
    size_t nw, n;
    coeff_t *W = NULL, *W1, *W2;
    dnoa_out_t out;
    int status;

    // No imaginary part: f(arr) is real, in the input's layout.
    if (k == 0 || act == 0 || trc == 0 || m == 0){

        uint64_t e;

        status = oarr_zeros_to(k, arr1->nrows, arr1->ncols, trc, res);

        for (e = 0; e < m && status == DN_OK; e++){
            res->p_data[e] = derivs[e];
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

    status = dnoa_out_begin(&out, res, dnoa_aliases(res, arr1), k, trc, arr1->nrows, arr1->ncols);

    if (status != DN_OK){

        free(W);
        return status;

    }

#ifdef _OPENMP
    if (m >= DNOK_OMP_MIN_ELEMS && !omp_in_parallel() && omp_get_max_threads() > 1){

        #pragma omp parallel
        {
            uint64_t nt  = (uint64_t)omp_get_num_threads();
            uint64_t tid = (uint64_t)omp_get_thread_num();

            dnoa_feval_range(derivs, arr1->p_data, k, trc, act, m, (m * tid) / nt,
                             (m * (tid + 1)) / nt, out.p_r, W1, W2, dhl);

        }

    } else {

        dnoa_feval_range(derivs, arr1->p_data, k, trc, act, m, 0, m, out.p_r, W1, W2, dhl);

    }
#else
    dnoa_feval_range(derivs, arr1->p_data, k, trc, act, m, 0, m, out.p_r, W1, W2, dhl);
#endif

    free(W);
    dnoa_out_end(&out, res, trc);

    return DN_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Per-element derivatives derivs[i*m + e] = f^(i)(re_e), i = 0..trc, from a der_r_* function (with
// `fn`) or der_r_pow (`fn` NULL, exponent `ex`). Caller frees *p_derivs.
static int dnoa_derivs(const oarr_t* arr1, void (*fn)(coeff_t, ord_t, coeff_t*), coeff_t ex,
                       coeff_t** p_derivs){

    uint64_t e, m = arr1->size;
    ord_t trc = arr1->trc_order, i;
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
            fn(arr1->p_data[e], trc, tmp);
        } else {
            der_r_pow(arr1->p_data[e], ex, trc, tmp);
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

    bases_t k = dnoa_max_bases(arr1->nact, arr2->nact);
    ord_t trc = dnoa_max_ord(arr1->trc_order, arr2->trc_order), q;
    ord_t atop = arr1->act_order, btop = arr2->act_order;
    uint64_t nrows = arr1->nrows, ninner = arr1->ncols, ncols = arr2->ncols;
    ndir_t maxNq = 0;
    size_t nwork;
    coeff_t* work = NULL;
    dnoa_out_t out;
    int status;

    if (arr1->ncols != arr2->nrows){
        return DN_ERR_SIZE;
    }

    // The kernel's size checks, done before `res` is touched so that an error leaves it unchanged.
    if (nrows > 0 && ncols > 0){

        status = dnok_matmul_fits(arr2->nact, 0, btop, nrows, ninner, ncols);

        if (status != DN_OK){
            return status;
        }

    }

    // Scratch of one A_i x [order-q blocks of B] product, q >= 1 (identity products need none).
    for (q = 1; q <= btop && atop > 0; q++){

        ndir_t Nq = sshelp_ndir_order(arr2->nact, q);

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
        status = dnok_matmul_acc(arr1->p_data, arr1->nact, 0, atop, arr2->p_data, arr2->nact, 0, btop,
                                 k, trc, nrows, ninner, ncols, 1.0, out.p_r, work, dhl);

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

    bases_t k = arr1->nact;
    ord_t trc = arr1->trc_order, act = arr1->act_order;
    uint64_t nrows = arr1->nrows, ncols = arr1->ncols, size = arr1->size, r, c;
    size_t b, nblocks;
    dnoa_out_t out;
    int status;

    (void)dhl;

    status = dnoa_out_begin(&out, res, dnoa_aliases(res, arr1), k, trc, ncols, nrows);

    if (status != DN_OK){
        return status;
    }

    nblocks = (size > 0) ? out.n / size : 0;

    for (b = 0; b < nblocks; b++){

        const coeff_t* src = arr1->p_data + b * size;
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
