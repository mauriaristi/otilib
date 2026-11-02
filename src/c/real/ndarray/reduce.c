// ndarray reductions (include/oti/real/ndarray/reduce.h, Phase 2; PLAN-ndarray-contracts.md 3.4,
// 5.4, S14, S21, S24). Unity-included from src/c/real_ndarray.c after mask.c; uses iter.c's K sort
// helpers and elementwise.c's driver (nde_for, nde_alloc_k, nde_copy_into, nde_minimum /
// nde_maximum). Static helpers carry the ndr_ prefix.
//
// The reduced sequence of an output element (reduce.h): the reduced axes of extent > 1 in the
// input's K order (decreasing |stride|, ties by axis index; the input drives the K order of a
// reduction since it has the most non-zero-stride axes), walked as a row-major multi-index, so
// element k of the sequence is the k-th element of that walk. ARGMIN / ARGMAX take the reduced axes
// in logical order instead (S21), so k is the C-order index. Adjacent reduced axes are merged where
// the strides allow it (this does not change the sequence).
//
// The summation tree (SUM, MEAN, VAR, STD; PROD with * in place of +), for each output:
//   - the sequence is cut into blocks of B = OTI_EXEC_CHUNK_ELEMS elements, block b = [bB, bB + B);
//   - each block is summed by NumPy's pairwise scheme, nd_pairwise_sum(): n < 8 a sequential sum
//     from +0.0; 8 <= n <= 128 eight accumulators r[j] = x[j], r[j] += x[j + 8i] over the largest
//     multiple of 8, ((r0 + r1) + (r2 + r3)) + ((r4 + r5) + (r6 + r7)), then the rest added in
//     order; n > 128 split at n2 = n/2 rounded down to a multiple of 8, both halves, then added;
//   - the block sums are combined by nd_tree_combine() (block order, halves split at nb/2);
//   - SUM is (+0.0) + that value; MEAN is SUM / N; VAR is the same tree over (x - mean)^2, plus +0.0,
//     divided by max(N - ddof, 0); STD is sqrt(VAR).
// MIN / MAX / ANY / ALL / ARGMIN / ARGMAX scan the sequence in order; NaN propagates (the first NaN
// of the sequence), min / max order zeros as IEEE minimum / maximum (-0.0 < +0.0, NumPy), arg ties
// go to the first index (compared with <, so -0.0 and +0.0 tie, as NumPy).
//
// Memory order (critic W1 finding 7): when the reduced sequence is one strided axis and a kept axis
// has a smaller |stride| (sum(axis=0) of a C matrix), "lane mode" processes NDR_TILE outputs along
// that kept axis at once: the outer loop runs over the reduced sequence (eight rows at a time in
// the pairwise leaves), the inner loop over the tile of outputs, so the input is read row by row in
// memory order. Each lane follows exactly the tree above (the same additions in the same order), so
// lane mode and the one-output-at-a-time "sequence mode" give the same bits.
//
// Work units are (group, block) pairs: a group is one output (sequence mode) or one tile of lanes;
// with one block per output a unit writes its outputs, otherwise it stores block partials and a final
// pass combines them in block order. Units are independent, so the fixed chunks of units can run on
// any number of workers (nde_for, oti_exec_plan with NDR_NS_*) with bit-identical results.

#include <math.h>
#include <stdlib.h>
#include <string.h>

#include "oti/real/ndarray.h"

#define NDR_BLOCK    OTI_EXEC_CHUNK_ELEMS  // elements per block of the reduced sequence
#define NDR_TILE     128                   // outputs per lane-mode tile
#define NDR_LEVELS   10                    // recursion depth of a <= NDR_BLOCK pairwise split
#define NDR_PSTACK   256                   // block partials kept on the stack
#define NDR_UNIT_WORK (4 * OTI_EXEC_CHUNK_ELEMS)  // elements of work per chunk of units

// Cost per input element (ns, one core) of a reduction for oti_exec_plan() (contracts S27), measured
// like NDE_NS_* (build-orch/w2-scratch/nd-kern/bench_ns.c, 2^20 contiguous doubles): pairwise sums
// 0.11 (one sequence) to 0.17 (lanes), var 0.25 (two passes); min / max / arg scans; ANY / ALL stop
// at the first decisive element, so they take the floor of the arithmetic family.
#define NDR_NS_SUM   0.15
#define NDR_NS_SCAN  0.5

// Internal reduction kernels (the public ND_RED_* map onto these).
enum {
    NDR_K_SUM = 1,
    NDR_K_PROD,
    NDR_K_SSD,      // sum of squared deviations from a per-output mean (VAR, STD pass 2)
    NDR_K_MIN,
    NDR_K_MAX,
    NDR_K_ARGMIN,
    NDR_K_ARGMAX,
    NDR_K_ANY,
    NDR_K_ALL
};

// One reduction pass.
typedef struct {
    int32_t     kop;                        // NDR_K_*
    int32_t     op;                         // ND_RED_* (finalization)
    int32_t     u8;                         // input dtype is OTI_U8 (ANY / ALL)
    int32_t     odt;                        // output dtype
    int32_t     arg;                        // ARGMIN / ARGMAX
    int32_t     reserved;
    const char* in;                         // input element 0
    char*       out;                        // output element 0
    int32_t     nr;                         // reduced dims after merging (>= 1)
    int32_t     no;                         // other kept dims (outputs, without the lane axis)
    int64_t     rshape[OTI_ND_MAXDIM];      // reduced extents, innermost last
    int64_t     rstride[OTI_ND_MAXDIM];     // their input byte strides
    int64_t     n;                          // N, elements per output
    int64_t     nb;                         // blocks per output (0 when N == 0)
    int64_t     oshape[OTI_ND_MAXDIM];      // other kept extents, innermost last
    int64_t     oistr[OTI_ND_MAXDIM];       // their input byte strides
    int64_t     oostr[OTI_ND_MAXDIM];       // their output byte strides
    int64_t     wt;                         // lane axis extent (1 in sequence mode)
    int64_t     ls;                         // lane axis input byte stride
    int64_t     los;                        // lane axis output byte stride
    int64_t     tile;                       // lanes per group
    int64_t     ntiles;                     // groups per other-kept index
    int64_t     nunits;                     // groups x blocks
    int64_t     upc;                        // units per chunk
    double      div;                        // VAR / STD divisor, max(N - ddof, 0)
    double*     part;                       // block partials [output][block] (nb > 1)
    int64_t*    pidx;                       // block arg indices (ARGMIN / ARGMAX, nb > 1)
} ndr_plan_t;


// -------------------------------------------------------------------------------------------------------
// --------------------------------------    PAIRWISE KERNELS    -----------------------------------------
// -------------------------------------------------------------------------------------------------------

// *******************************************************************************************************
// d * d (keeps the square a separate rounding: no FMA, -ffp-contract=off).
static inline double ndr_sq(double d){

    return d * d;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// One-sequence pairwise kernels over n elements at byte stride bs (NumPy's pairwise_sum, see the file
// comment). Variables inside LOAD: p_ (element address) and m (the SSD mean).
#define NDR_PAIRWISE(NAME, INIT, OP, LOAD)                                                           \
static double NAME(const char* x, int64_t n, int64_t bs, double m){                                  \
    int64_t i;                                                                                       \
    int32_t j;                                                                                       \
    (void)m;                                                                                         \
    if (n < 8){                                                                                      \
        double res = (INIT);                                                                         \
        for (i = 0; i < n; i++){ const char* p_ = x + i * bs; res = res OP (LOAD); }                 \
        return res;                                                                                  \
    }                                                                                                \
    if (n <= 128){                                                                                   \
        double r[8], res;                                                                            \
        for (j = 0; j < 8; j++){ const char* p_ = x + j * bs; r[j] = (LOAD); }                       \
        for (i = 8; i < n - (n % 8); i += 8){                                                        \
            for (j = 0; j < 8; j++){ const char* p_ = x + (i + j) * bs; r[j] = r[j] OP (LOAD); }     \
        }                                                                                            \
        res = ((r[0] OP r[1]) OP (r[2] OP r[3])) OP ((r[4] OP r[5]) OP (r[6] OP r[7]));              \
        for (; i < n; i++){ const char* p_ = x + i * bs; res = res OP (LOAD); }                      \
        return res;                                                                                  \
    }                                                                                                \
    {                                                                                                \
        int64_t n2 = n / 2;                                                                          \
        n2 -= n2 % 8;                                                                                \
        return NAME(x, n2, bs, m) OP NAME(x + n2 * bs, n - n2, bs, m);                               \
    }                                                                                                \
}

NDR_PAIRWISE(ndr_pw_sum, 0.0, +, *(const double*)p_)
NDR_PAIRWISE(ndr_pw_prod, 1.0, *, *(const double*)p_)
NDR_PAIRWISE(ndr_pw_ssd, 0.0, +, ndr_sq(*(const double*)p_ - m))
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Lane pairwise kernels: for each lane l < w, the same tree as NDR_PAIRWISE over rows 0 .. n-1, where
// row i of lane l is at x + i*rs + l*LS (LS is the literal 8 in the contiguous variant, so the inner
// lane loops vectorize). m[l] is the SSD mean of lane l. out gets w results; scratch holds
// (8 + NDR_LEVELS) * NDR_TILE doubles: the leaf accumulators, then one right-half vector per level.
#define NDR_PAIRWISE_LANES(NAME, INIT, OP, LOAD, LS)                                                 \
static void NAME(const char* x, int64_t n, int64_t rs, int64_t ls, int32_t w, const double* m,      \
                 double* out, double* scratch){                                                      \
    int64_t i;                                                                                       \
    int32_t j, l;                                                                                    \
    (void)ls;                                                                                        \
    (void)m;                                                                                         \
    if (n < 8){                                                                                      \
        for (l = 0; l < w; l++){ out[l] = (INIT); }                                                  \
        for (i = 0; i < n; i++){                                                                     \
            const char* row = x + i * rs;                                                            \
            for (l = 0; l < w; l++){ const char* p_ = row + l * (LS); out[l] = out[l] OP (LOAD); }   \
        }                                                                                            \
        return;                                                                                      \
    }                                                                                                \
    if (n <= 128){                                                                                   \
        double* r = scratch;                                                                         \
        for (j = 0; j < 8; j++){                                                                     \
            const char* row = x + j * rs;                                                            \
            double* rj = r + j * NDR_TILE;                                                           \
            for (l = 0; l < w; l++){ const char* p_ = row + l * (LS); rj[l] = (LOAD); }              \
        }                                                                                            \
        for (i = 8; i < n - (n % 8); i += 8){                                                        \
            for (j = 0; j < 8; j++){                                                                 \
                const char* row = x + (i + j) * rs;                                                  \
                double* rj = r + j * NDR_TILE;                                                       \
                for (l = 0; l < w; l++){ const char* p_ = row + l * (LS); rj[l] = rj[l] OP (LOAD); } \
            }                                                                                        \
        }                                                                                            \
        for (l = 0; l < w; l++){                                                                     \
            out[l] = ((r[l] OP r[NDR_TILE + l]) OP (r[2 * NDR_TILE + l] OP r[3 * NDR_TILE + l]))     \
                     OP ((r[4 * NDR_TILE + l] OP r[5 * NDR_TILE + l])                                \
                         OP (r[6 * NDR_TILE + l] OP r[7 * NDR_TILE + l]));                           \
        }                                                                                            \
        for (; i < n; i++){                                                                          \
            const char* row = x + i * rs;                                                            \
            for (l = 0; l < w; l++){ const char* p_ = row + l * (LS); out[l] = out[l] OP (LOAD); }   \
        }                                                                                            \
        return;                                                                                      \
    }                                                                                                \
    {                                                                                                \
        int64_t n2 = n / 2;                                                                          \
        n2 -= n2 % 8;                                                                                \
        NAME(x, n2, rs, ls, w, m, out, scratch);                                                     \
        NAME(x + n2 * rs, n - n2, rs, ls, w, m, scratch, scratch + NDR_TILE);                        \
        for (l = 0; l < w; l++){ out[l] = out[l] OP scratch[l]; }                                    \
    }                                                                                                \
}

NDR_PAIRWISE_LANES(ndr_pwl_sum_c, 0.0, +, *(const double*)p_, 8)
NDR_PAIRWISE_LANES(ndr_pwl_sum_s, 0.0, +, *(const double*)p_, ls)
NDR_PAIRWISE_LANES(ndr_pwl_prod_c, 1.0, *, *(const double*)p_, 8)
NDR_PAIRWISE_LANES(ndr_pwl_prod_s, 1.0, *, *(const double*)p_, ls)
NDR_PAIRWISE_LANES(ndr_pwl_ssd_c, 0.0, +, ndr_sq(*(const double*)p_ - m[l]), 8)
NDR_PAIRWISE_LANES(ndr_pwl_ssd_s, 0.0, +, ndr_sq(*(const double*)p_ - m[l]), ls)
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
double nd_pairwise_sum(const double* x, int64_t n, int64_t stride){

    if (x == NULL || n <= 0){
        return 0.0;
    }

    return ndr_pw_sum((const char*)x, n, stride * (int64_t)sizeof(double), 0.0);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// The fixed block tree of a sum or product (halves split at n/2, left half first).
static double ndr_tree_sp(const double* v, int64_t n, int32_t prod){

    int64_t h;

    if (n == 1){
        return v[0];
    }

    h = n / 2;

    return prod ? ndr_tree_sp(v, h, 1) * ndr_tree_sp(v + h, n - h, 1)
                : ndr_tree_sp(v, h, 0) + ndr_tree_sp(v + h, n - h, 0);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
double nd_tree_combine(const double* partials, int64_t n, int32_t op){

    if (op != ND_RED_SUM && op != ND_RED_PROD){
        return NAN;
    }

    if (partials == NULL || n <= 0){
        return (op == ND_RED_PROD) ? 1.0 : 0.0;
    }

    return ndr_tree_sp(partials, n, op == ND_RED_PROD);

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// ----------------------------------------    SCAN KERNELS    -------------------------------------------
// -------------------------------------------------------------------------------------------------------

// *******************************************************************************************************
// Truth value of an element of an ANY / ALL input (OTI_U8 byte or OTI_F64; NaN is true).
static inline int ndr_truth(const char* p, int32_t u8){

    return u8 ? (*(const uint8_t*)p != 0) : (*(const double*)p != 0.0);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Nonzero when (v, i) is a better arg candidate than (bv, bi) that comes earlier in the sequence:
// the first NaN wins, else a strictly smaller (argmin) or larger (argmax) value.
static inline int ndr_arg_better(double v, double bv, int32_t is_max){

    if (bv != bv){
        return 0;
    }

    if (v != v){
        return 1;
    }

    return is_max ? (v > bv) : (v < bv);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Running IEEE minimum (is_max 0) or maximum of non-NaN values: y replaces acc when strictly smaller
// (larger), or when both are zeros and y has the preferred sign (-0.0 for the minimum, +0.0 for the
// maximum). A NaN y never replaces (callers keep a NaN flag and rescan for the first NaN). Written
// with branches: they predict well, and a select would put the compare on the loop-carried chain.
static inline double ndr_mm(double acc, double y, int32_t is_max){

    if (is_max){
        if (y > acc){
            return y;
        }
        if (y == 0.0 && acc == 0.0 && !signbit(y)){
            return y;
        }
        return acc;
    }

    if (y < acc){
        return y;
    }

    if (y == 0.0 && acc == 0.0 && signbit(y)){
        return y;
    }

    return acc;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Index of the first NaN among n elements at byte stride bs (n if none).
static int64_t ndr_first_nan(const char* x, int64_t n, int64_t bs){

    int64_t i;

    for (i = 0; i < n; i++){
        double y = *(const double*)(x + i * bs);
        if (y != y){
            return i;
        }
    }

    return n;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Scan of n >= 1 elements at byte stride bs for MIN / MAX / ANY / ALL / ARGMIN / ARGMAX: the value
// (*v, for ANY / ALL 0.0 or 1.0) and for the arg kernels the index of the winner (*ix, from 0).
// Min / max / arg run a branch-light pass over the non-NaN values with a NaN flag; when a NaN was
// seen, the result is the first NaN (and its index), found by a rescan. This is exactly the result
// of the sequential NaN-propagating scan (nde_minimum / nde_maximum, first occurrence).
static void ndr_scan(int32_t kop, int32_t u8, const char* x, int64_t n, int64_t bs, double* v,
                     int64_t* ix){

    int64_t i;

    switch (kop){
    case NDR_K_MIN:
    case NDR_K_MAX: {
        // Four independent accumulators (exact: the minimum of non-NaN values does not depend on
        // the order, signed zeros included), combined at the end.
        int32_t is_max = (kop == NDR_K_MAX);
        double acc = *(const double*)x, a1 = acc, a2 = acc, a3 = acc;
        int nan = (acc != acc);
        for (i = 1; i + 4 <= n; i += 4){
            double y0 = *(const double*)(x + i * bs), y1 = *(const double*)(x + (i + 1) * bs);
            double y2 = *(const double*)(x + (i + 2) * bs), y3 = *(const double*)(x + (i + 3) * bs);
            nan |= (y0 != y0) | (y1 != y1) | (y2 != y2) | (y3 != y3);
            acc = ndr_mm(acc, y0, is_max);
            a1  = ndr_mm(a1, y1, is_max);
            a2  = ndr_mm(a2, y2, is_max);
            a3  = ndr_mm(a3, y3, is_max);
        }
        for (; i < n; i++){
            double y = *(const double*)(x + i * bs);
            nan |= (y != y);
            acc = ndr_mm(acc, y, is_max);
        }
        acc = ndr_mm(ndr_mm(acc, a1, is_max), ndr_mm(a2, a3, is_max), is_max);
        if (nan){
            acc = *(const double*)(x + ndr_first_nan(x, n, bs) * bs);
        }
        *v = acc;
        return;
    }
    case NDR_K_ARGMIN:
    case NDR_K_ARGMAX: {
        double best = *(const double*)x;
        int64_t bi = 0;
        int nan = (best != best);
        if (kop == NDR_K_ARGMAX){
            for (i = 1; i < n; i++){
                double y = *(const double*)(x + i * bs);
                nan |= (y != y);
                if (y > best){
                    best = y;
                    bi   = i;
                }
            }
        } else {
            for (i = 1; i < n; i++){
                double y = *(const double*)(x + i * bs);
                nan |= (y != y);
                if (y < best){
                    best = y;
                    bi   = i;
                }
            }
        }
        if (nan){
            bi   = ndr_first_nan(x, n, bs);
            best = *(const double*)(x + bi * bs);
        }
        *v  = best;
        *ix = bi;
        return;
    }
    case NDR_K_ANY: {
        int t = 0;
        for (i = 0; i < n && !t; i++){
            t = ndr_truth(x + i * bs, u8);
        }
        *v = t ? 1.0 : 0.0;
        return;
    }
    default: {
        int t = 1;
        for (i = 0; i < n && t; i++){
            t = ndr_truth(x + i * bs, u8);
        }
        *v = t ? 1.0 : 0.0;
        return;
    }
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Lane scan: ndr_scan for w lanes, row i of lane l at x + i*rs + l*ls; rows in sequence order. The
// same NaN flag and first-NaN rescan per lane.
static void ndr_scan_lanes(int32_t kop, int32_t u8, const char* x, int64_t n, int64_t rs,
                           int64_t ls, int32_t w, double* v, int64_t* ix){

    unsigned char nan[NDR_TILE];
    int any_nan = 0;
    int64_t i;
    int32_t l;

    switch (kop){
    case NDR_K_MIN:
    case NDR_K_MAX: {
        int32_t is_max = (kop == NDR_K_MAX);
        for (l = 0; l < w; l++){
            v[l]   = *(const double*)(x + l * ls);
            nan[l] = (unsigned char)(v[l] != v[l]);
        }
        for (i = 1; i < n; i++){
            const char* row = x + i * rs;
            for (l = 0; l < w; l++){
                double y = *(const double*)(row + l * ls);
                nan[l] |= (unsigned char)(y != y);
                v[l] = ndr_mm(v[l], y, is_max);
            }
        }
        for (l = 0; l < w; l++){
            if (nan[l]){
                v[l] = *(const double*)(x + l * ls + ndr_first_nan(x + l * ls, n, rs) * rs);
            }
        }
        return;
    }
    case NDR_K_ARGMIN:
    case NDR_K_ARGMAX:
        for (l = 0; l < w; l++){
            v[l]    = *(const double*)(x + l * ls);
            ix[l]   = 0;
            nan[l]  = (unsigned char)(v[l] != v[l]);
        }
        for (i = 1; i < n; i++){
            const char* row = x + i * rs;
            for (l = 0; l < w; l++){
                double y = *(const double*)(row + l * ls);
                int take = (kop == NDR_K_ARGMAX) ? (y > v[l]) : (y < v[l]);
                nan[l] |= (unsigned char)(y != y);
                v[l]  = take ? y : v[l];
                ix[l] = take ? i : ix[l];
            }
        }
        for (l = 0; l < w; l++){
            any_nan |= nan[l];
        }
        if (any_nan){
            for (l = 0; l < w; l++){
                if (nan[l]){
                    ix[l] = ndr_first_nan(x + l * ls, n, rs);
                    v[l]  = *(const double*)(x + l * ls + ix[l] * rs);
                }
            }
        }
        return;
    default:
        for (l = 0; l < w; l++){
            v[l] = (kop == NDR_K_ALL) ? 1.0 : 0.0;
        }
        for (i = 0; i < n; i++){
            const char* row = x + i * rs;
            for (l = 0; l < w; l++){
                int t = ndr_truth(row + l * ls, u8);
                if (kop == NDR_K_ANY ? t : !t){
                    v[l] = t ? 1.0 : 0.0;
                }
            }
        }
        return;
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Combines two block results of a scan or tree kernel, a from the earlier block.
static inline double ndr_join(int32_t kop, double a, double b){

    switch (kop){
    case NDR_K_PROD:
        return a * b;
    case NDR_K_MIN:
        return nde_minimum(a, b);
    case NDR_K_MAX:
        return nde_maximum(a, b);
    case NDR_K_ANY:
        return (a != 0.0 || b != 0.0) ? 1.0 : 0.0;
    case NDR_K_ALL:
        return (a != 0.0 && b != 0.0) ? 1.0 : 0.0;
    default:
        return a + b;
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// The fixed block tree (block order, halves split at n/2) of n >= 1 block results; for the arg
// kernels the indices ride along (the earlier block wins a tie, the first NaN wins).
static double ndr_tree(int32_t kop, const double* v, const int64_t* ix, int64_t n, int64_t* bi){

    double a, b;
    int64_t ia = 0, ib = 0, h;

    if (n == 1){
        if (ix != NULL){
            *bi = ix[0];
        }
        return v[0];
    }

    h = n / 2;
    a = ndr_tree(kop, v, ix, h, &ia);
    b = ndr_tree(kop, v + h, (ix != NULL) ? ix + h : NULL, n - h, &ib);

    if (kop == NDR_K_ARGMIN || kop == NDR_K_ARGMAX){
        if (ndr_arg_better(b, a, kop == NDR_K_ARGMAX)){
            *bi = ib;
            return b;
        }
        *bi = ia;
        return a;
    }

    return ndr_join(kop, a, b);

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// ----------------------------------------    THE DRIVER    ---------------------------------------------
// -------------------------------------------------------------------------------------------------------

// *******************************************************************************************************
// Writes the final value of one output: (+0.0) + sum, mean, variance, ... (reduce.h), as the output
// dtype. v is the combined tree / scan value (the identity when N == 0), ix the arg index.
static void ndr_store(const ndr_plan_t* p, char* dst, double v, int64_t ix){

    switch (p->kop){
    case NDR_K_SUM:
        v = 0.0 + v;
        if (p->op != ND_RED_SUM){
            v = v / (double)p->n;                   // MEAN, and the mean pass of VAR / STD
        }
        break;
    case NDR_K_SSD:
        v = (0.0 + v) / p->div;
        if (p->op == ND_RED_STD){
            v = sqrt(v);
        }
        break;
    case NDR_K_ARGMIN:
    case NDR_K_ARGMAX:
        memcpy(dst, &ix, sizeof(ix));
        return;
    case NDR_K_ANY:
    case NDR_K_ALL:
        *(uint8_t*)dst = (uint8_t)(v != 0.0);
        return;
    default:
        break;
    }

    memcpy(dst, &v, sizeof(v));

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Gathers elements [k0, k0 + n) of the reduced sequence (nr > 1 dims) of the output whose element 0
// is x into buf as doubles (an OTI_U8 input as 0.0 / 1.0).
static void ndr_gather(const ndr_plan_t* p, const char* x, int64_t k0, int64_t n, double* buf){

    int64_t idx[OTI_ND_MAXDIM];
    int64_t off = 0, rem = k0, i;
    int32_t d, nr = p->nr;

    for (d = nr - 1; d >= 0; d--){
        idx[d] = rem % p->rshape[d];
        rem   /= p->rshape[d];
        off   += idx[d] * p->rstride[d];
    }

    for (i = 0; i < n; i++){

        const char* e = x + off;

        buf[i] = p->u8 ? (double)(*(const uint8_t*)e != 0) : *(const double*)e;

        for (d = nr - 1; d >= 0; d--){
            if (idx[d] + 1 < p->rshape[d]){
                idx[d]++;
                off += p->rstride[d];
                break;
            }
            off   -= (p->rshape[d] - 1) * p->rstride[d];
            idx[d] = 0;
        }

    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Block b of one group: w lanes whose element 0 is at x (lane l at x + l*ls), outputs at y (lane l
// at y + l*los, read for the SSD means). Results in v[0 .. w) (and ix for the arg kernels, as
// sequence indices).
static void ndr_unit(const ndr_plan_t* p, const char* x, const char* y, int32_t w, int64_t b,
                     double* v, int64_t* ix, double* m, double* scratch, double* gbuf){

    int64_t k0 = b * NDR_BLOCK;
    int64_t nk = p->n - k0;
    int32_t kop = p->kop, l;
    const char* xb;
    int64_t bs;

    if (nk > NDR_BLOCK){
        nk = NDR_BLOCK;
    }

    if (kop == NDR_K_SSD){
        for (l = 0; l < w; l++){
            memcpy(&m[l], y + l * p->los, sizeof(double));
        }
    }

    if (p->nr > 1){
        ndr_gather(p, x, k0, nk, gbuf);             // sequence mode only (w == 1)
        xb = (const char*)gbuf;
        bs = (int64_t)sizeof(double);
    } else {
        xb = x + k0 * p->rstride[0];
        bs = p->rstride[0];
    }

    if (w == 1){

        int32_t u8 = (p->nr > 1) ? 0 : p->u8;

        switch (kop){
        case NDR_K_SUM:
            v[0] = ndr_pw_sum(xb, nk, bs, 0.0);
            break;
        case NDR_K_PROD:
            v[0] = ndr_pw_prod(xb, nk, bs, 0.0);
            break;
        case NDR_K_SSD:
            v[0] = ndr_pw_ssd(xb, nk, bs, m[0]);
            break;
        default:
            ndr_scan(kop, u8, xb, nk, bs, v, ix);
            break;
        }

    } else {

        int c = (p->ls == 8);

        switch (kop){
        case NDR_K_SUM:
            (c ? ndr_pwl_sum_c : ndr_pwl_sum_s)(xb, nk, bs, p->ls, w, m, v, scratch);
            break;
        case NDR_K_PROD:
            (c ? ndr_pwl_prod_c : ndr_pwl_prod_s)(xb, nk, bs, p->ls, w, m, v, scratch);
            break;
        case NDR_K_SSD:
            (c ? ndr_pwl_ssd_c : ndr_pwl_ssd_s)(xb, nk, bs, p->ls, w, m, v, scratch);
            break;
        default:
            ndr_scan_lanes(kop, p->u8, xb, nk, bs, p->ls, w, v, ix);
            break;
        }

    }

    if (kop == NDR_K_ARGMIN || kop == NDR_K_ARGMAX){
        for (l = 0; l < w; l++){
            ix[l] += k0;
        }
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Input and output byte offsets of the other-kept multi-index of linear index lin (innermost last).
static void ndr_decode(const ndr_plan_t* p, int64_t lin, int64_t* idx, int64_t* ib, int64_t* ob){

    int32_t d;

    *ib = 0;
    *ob = 0;

    for (d = p->no - 1; d >= 0; d--){
        idx[d] = lin % p->oshape[d];
        lin   /= p->oshape[d];
        *ib   += idx[d] * p->oistr[d];
        *ob   += idx[d] * p->oostr[d];
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Steps the other-kept multi-index by one (row-major), updating the offsets; wraps to 0 at the end.
static void ndr_advance(const ndr_plan_t* p, int64_t* idx, int64_t* ib, int64_t* ob){

    int32_t d;

    for (d = p->no - 1; d >= 0; d--){

        if (idx[d] + 1 < p->oshape[d]){
            idx[d]++;
            *ib += p->oistr[d];
            *ob += p->oostr[d];
            return;
        }

        *ib   -= (p->oshape[d] - 1) * p->oistr[d];
        *ob   -= (p->oshape[d] - 1) * p->oostr[d];
        idx[d] = 0;

    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Chunk function: units [c*upc, min((c+1)*upc, nunits)), unit u = (group u / nb, block u % nb), group
// g = (other-kept index g / ntiles, tile g % ntiles). Writes its outputs (nb == 1) or its block
// partials (nb > 1); never anything else, and records no error.
static int ndr_chunk(void* arg, int64_t c, int32_t worker){

    const ndr_plan_t* p = (const ndr_plan_t*)arg;
    double scratch[(8 + NDR_LEVELS) * NDR_TILE];
    double v[NDR_TILE], m[NDR_TILE];
    int64_t ix[NDR_TILE];
    double gbuf[NDR_BLOCK];
    int64_t idx[OTI_ND_MAXDIM];
    int64_t u = c * p->upc, u1 = u + p->upc;
    int64_t g, b, t, lin, ib, ob;
    int32_t l;

    (void)worker;

    if (u1 > p->nunits){
        u1 = p->nunits;
    }

    g   = u / p->nb;
    b   = u % p->nb;
    t   = g % p->ntiles;
    lin = g / p->ntiles;
    ndr_decode(p, lin, idx, &ib, &ob);

    for (; u < u1; u++){

        int64_t first = t * p->tile;
        int32_t w = (int32_t)((p->wt - first < p->tile) ? p->wt - first : p->tile);

        ndr_unit(p, p->in + ib + first * p->ls, p->out + ob + first * p->los, w, b, v, ix, m,
                 scratch, gbuf);

        if (p->nb == 1){

            for (l = 0; l < w; l++){
                ndr_store(p, p->out + ob + (first + l) * p->los, v[l], p->arg ? ix[l] : 0);
            }

        } else {

            int64_t o = lin * p->wt + first;

            for (l = 0; l < w; l++){
                p->part[(o + l) * p->nb + b] = v[l];
                if (p->pidx != NULL){
                    p->pidx[(o + l) * p->nb + b] = ix[l];
                }
            }

        }

        if (++b == p->nb){
            b = 0;
            if (++t == p->ntiles){
                t = 0;
                lin++;
                ndr_advance(p, idx, &ib, &ob);
            }
        }

    }

    return OTI_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Final pass when nb != 1: every output combines its block partials in block order (or takes the
// identity of an empty sequence) and is stored.
static void ndr_final(const ndr_plan_t* p, int64_t m_out){

    int64_t idx[OTI_ND_MAXDIM];
    int64_t lin, nlin = m_out / p->wt, ib, ob, l;
    double ident = (p->kop == NDR_K_PROD || p->kop == NDR_K_ALL) ? 1.0 : 0.0;

    ndr_decode(p, 0, idx, &ib, &ob);

    for (lin = 0; lin < nlin; lin++){

        for (l = 0; l < p->wt; l++){

            int64_t o = lin * p->wt + l, bi = 0;
            double v = ident;

            if (p->nb > 0){
                v = ndr_tree(p->kop, p->part + o * p->nb, (p->pidx != NULL) ? p->pidx + o * p->nb : NULL,
                             p->nb, &bi);
            }

            ndr_store(p, p->out + ob + l * p->los, v, bi);

        }

        ndr_advance(p, idx, &ib, &ob);

    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Runs one pass of p over m_out outputs: units in fixed chunks (serial or parallel, nde_for), then
// the final pass if needed. Partials live on the stack when few, else in a malloc'd workspace whose
// byte count (values, plus indices for the arg kernels), added to `live` (the bytes of the
// operation's other temporaries held at the same time: the overlap result of nd_reduce_to), is
// checked against the temp budget first (contracts 5.2, S6; checker W2 finding 1).
static int ndr_pass(oti_ctx* ctx, ndr_plan_t* p, int64_t m_out, int64_t live){

    double pstack[NDR_PSTACK];
    int64_t istack[NDR_PSTACK];
    int64_t np = 0, unit_work, nchunks;
    int status = OTI_OK;
    int arg = (p->kop == NDR_K_ARGMIN || p->kop == NDR_K_ARGMAX);
    double ns = (p->kop == NDR_K_ANY || p->kop == NDR_K_ALL) ? NDE_NS_ARITH
                : (p->kop >= NDR_K_MIN) ? NDR_NS_SCAN : NDR_NS_SUM;

    p->part = NULL;
    p->pidx = NULL;

    if (p->nb > 1){

        np = m_out * p->nb;                         // <= 2 * (input size) / NDR_BLOCK: fits.

        if (np <= NDR_PSTACK){
            p->part = pstack;
            p->pidx = arg ? istack : NULL;
        } else {

            int64_t nbytes;

            if (oti_ckd_mul_i64(np, arg ? 16 : 8, &nbytes) || oti_ckd_add_i64(nbytes, live, &nbytes)){
                return OTI_ERR_SIZE;
            }

            status = oti_ctx_check_temp(ctx, nbytes);

            if (status != OTI_OK){
                return status;
            }

            p->part = (double*)malloc((size_t)np * sizeof(double));
            p->pidx = arg ? (int64_t*)malloc((size_t)np * sizeof(int64_t)) : NULL;
            if (p->part == NULL || (arg && p->pidx == NULL)){
                status = OTI_ERR_MEMORY;
            }
        }

    }

    if (status == OTI_OK && p->nb > 0){

        int64_t per = (p->n < NDR_BLOCK) ? p->n : NDR_BLOCK;

        p->nunits = (m_out / p->wt) * p->ntiles * p->nb;
        unit_work = per * p->tile;
        p->upc    = (unit_work >= NDR_UNIT_WORK) ? 1 : NDR_UNIT_WORK / unit_work;
        nchunks   = oti_exec_nchunks(p->nunits, p->upc);

        status = nde_for(ctx, m_out * p->n, p->upc * unit_work, ns, nchunks, ndr_chunk, p);

    }

    if (status == OTI_OK && p->nb != 1){
        ndr_final(p, m_out);
    }

    if (p->part != pstack){
        free(p->part);
        free(p->pidx);
    }

    return status;

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// ---------------------------------------    ARGUMENTS & PLAN    ----------------------------------------
// -------------------------------------------------------------------------------------------------------

// *******************************************************************************************************
// Result dtype of a reduction, or 0 for an unknown code.
static int32_t ndr_out_dtype(int32_t op){

    if (op >= ND_RED_SUM && op <= ND_RED_STD){
        return OTI_F64;
    }

    if (op == ND_RED_ARGMIN || op == ND_RED_ARGMAX){
        return OTI_I64;
    }

    if (op == ND_RED_ANY || op == ND_RED_ALL){
        return OTI_U8;
    }

    return 0;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Checks op, the input and the axes; red[k] = 1 for every reduced axis. Then the shape of the result
// (keepdims convention) into (*ondim, oshape). Statuses in the header's order: ARGUMENT (op, NULL,
// naxes, repeats, arg over several axes), DTYPE, INDEX (axis), SHAPE (empty min / max / arg).
static int ndr_args(int32_t op, const ndarr_t* a, int32_t naxes, const int32_t* axes,
                    int32_t keepdims, int32_t* red, int32_t* ondim, int64_t* oshape){

    int32_t k, nd, n = 0;
    int64_t nred = 1;

    if (ndr_out_dtype(op) == 0 || a == NULL || naxes < -1 || (naxes > 0 && axes == NULL)){
        return OTI_ERR_ARGUMENT;
    }

    if ((op == ND_RED_ARGMIN || op == ND_RED_ARGMAX) && naxes != -1 && naxes != 1){
        return OTI_ERR_ARGUMENT;
    }

    nde_debug_input(a);

    if (!(a->dtype == OTI_F64 || ((op == ND_RED_ANY || op == ND_RED_ALL) && a->dtype == OTI_U8))){
        return OTI_ERR_DTYPE;
    }

    nd = a->ndim;

    for (k = 0; k < nd; k++){
        red[k] = (naxes == -1);
    }

    for (k = 0; k < naxes; k++){

        int32_t ax = axes[k];

        if (ax < -nd || ax >= nd){
            return OTI_ERR_INDEX;
        }

        ax = (ax < 0) ? ax + nd : ax;

        if (red[ax]){
            return OTI_ERR_ARGUMENT;
        }

        red[ax] = 1;

    }

    keepdims = (keepdims != 0);

    for (k = 0; k < nd; k++){

        if (red[k]){
            nred = (a->shape[k] == 0) ? 0 : nred;
            if (keepdims){
                oshape[n++] = 1;
            }
        } else {
            oshape[n++] = a->shape[k];
        }

    }

    if (nred == 0 && (op == ND_RED_MIN || op == ND_RED_MAX || op == ND_RED_ARGMIN
                      || op == ND_RED_ARGMAX)){
        return OTI_ERR_SHAPE;
    }

    *ondim = n;

    return OTI_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Fills the plan of reduction op of a NON-EMPTY input a into out (shape and dtype already checked;
// empty inputs go to ndr_identity, so every input stride converted here is span-bounded). Returns the
// number of outputs (0: nothing to do).
static int64_t ndr_plan(int32_t op, const ndarr_t* a, const int32_t* red, int32_t keepdims,
                        int64_t ddof, ndarr_t* out, ndr_plan_t* p){

    int32_t rax[OTI_ND_MAXDIM], kax[OTI_ND_MAXDIM];
    int32_t nr = 0, nk = 0, k, j, lane = -1;
    int64_t isz = nd_itemsize(a->dtype), osz = nd_itemsize(out->dtype);
    int64_t n = 1, m_out = 1;
    int arg = (op == ND_RED_ARGMIN || op == ND_RED_ARGMAX);

    memset(p, 0, sizeof(*p));
    p->op  = op;
    p->u8  = (a->dtype == OTI_U8);
    p->odt = out->dtype;
    p->in  = (const char*)a->data;
    p->out = (char*)out->data;
    p->arg = arg;

    switch (op){
    case ND_RED_PROD:
        p->kop = NDR_K_PROD;
        break;
    case ND_RED_MIN:
        p->kop = NDR_K_MIN;
        break;
    case ND_RED_MAX:
        p->kop = NDR_K_MAX;
        break;
    case ND_RED_ARGMIN:
        p->kop = NDR_K_ARGMIN;
        break;
    case ND_RED_ARGMAX:
        p->kop = NDR_K_ARGMAX;
        break;
    case ND_RED_ANY:
        p->kop = NDR_K_ANY;
        break;
    case ND_RED_ALL:
        p->kop = NDR_K_ALL;
        break;
    default:
        p->kop = NDR_K_SUM;                         // SUM, MEAN, VAR / STD (mean pass first)
        break;
    }

    // Axes: reduced (extent > 1) and kept (extent > 1, with their output axis).
    for (k = 0; k < a->ndim; k++){

        if (red[k]){

            if (a->shape[k] == 0){
                n = 0;
            }

            if (a->shape[k] > 1){
                rax[nr++] = k;
            }

        } else {

            if (a->shape[k] != 1){
                kax[nk++] = k;
            }

            m_out *= a->shape[k];                   // bounded by the input size.

        }

    }

    // Reduced sequence: K order (arg: logical order), then merged.
    if (!arg){
        ndi_k_sort(a, a->ndim, rax, nr);
    }

    for (j = 0; j < nr; j++){
        p->rshape[j]  = a->shape[rax[j]];
        p->rstride[j] = a->strides[rax[j]] * isz;
        if (n != 0){
            n *= p->rshape[j];
        }
    }

    for (j = nr - 2; j >= 0; j--){

        int64_t step;

        if (oti_ckd_mul_i64(p->rstride[j + 1], p->rshape[j + 1], &step) || p->rstride[j] != step){
            continue;
        }

        p->rshape[j + 1] *= p->rshape[j];
        for (k = j; k < nr - 1; k++){
            p->rshape[k]  = p->rshape[k + 1];
            p->rstride[k] = p->rstride[k + 1];
        }
        nr--;

    }

    if (nr == 0){
        nr = 1;
        p->rshape[0]  = 1;
        p->rstride[0] = 0;
    }

    p->nr = nr;
    p->n  = n;
    p->nb = (n == 0) ? 0 : oti_exec_nchunks(n, NDR_BLOCK);

    // NumPy's divisor max(N - ddof, 0); N - ddof can only overflow for a negative ddof.
    if (ddof >= 0){
        p->div = (ddof >= n) ? 0.0 : (double)(n - ddof);
    } else if (n > INT64_MAX + ddof){
        p->div = (double)n - (double)ddof;
    } else {
        p->div = (double)(n - ddof);
    }

    if (m_out == 0){
        return 0;
    }

    // Kept axes by decreasing |input stride| (memory order of the outputs); the last one is the lane
    // axis when the reduced sequence is one axis with a larger |stride|.
    ndi_k_sort(a, a->ndim, kax, nk);

    if (nk > 0 && nr == 1 && n > 1){

        int32_t inner = kax[nk - 1];
        uint64_t ms = ndi_mag(a->strides[inner] * isz), mr = ndi_mag(p->rstride[0]);

        if (ms < mr){
            lane = inner;
        }

    }

    p->wt   = 1;
    p->tile = 1;

    for (j = 0; j < nk; j++){

        int32_t ax = kax[j], ox = 0;

        // Output axis of input axis ax: count the axes before it that the output keeps.
        for (k = 0; k < ax; k++){
            ox += (!red[k] || keepdims);
        }

        if (ax == lane){
            p->wt   = a->shape[ax];
            p->ls   = a->strides[ax] * isz;
            p->los  = out->strides[ox] * osz;
            p->tile = NDR_TILE;
        } else {
            p->oshape[p->no] = a->shape[ax];
            p->oistr[p->no]  = a->strides[ax] * isz;
            p->oostr[p->no]  = out->strides[ox] * osz;
            p->no++;
        }

    }

    p->ntiles = oti_exec_nchunks(p->wt, p->tile);

    return m_out;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Fill kernel for an OTI_U8 output: every element of the run gets the byte k->reserved.
static int ndr_k_fill_u8(void* arg, int64_t n, char* const* p, const int64_t* bs){

    const nde_karg_t* k = (const nde_karg_t*)arg;
    char* po = p[k->io];
    int64_t so = bs[k->io], i;

    for (i = 0; i < n; i++){
        po[i * so] = (char)k->reserved;
    }

    return OTI_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Result of a reduction of an EMPTY input (N == 0; MIN / MAX / ARG* were rejected): every output gets
// the identity value (reduce.h): SUM 0, PROD 1, MEAN NaN, VAR 0 / max(-ddof, 0), STD its sqrt, ANY 0,
// ALL 1. Only out is walked (a non-empty, validated descriptor); the input's strides, which validation
// leaves unrestricted for an empty array, are never read (checker W2 finding 6).
static int ndr_identity(oti_ctx* ctx, int32_t op, int64_t ddof, ndarr_t* out){

    const ndarr_t* ops[1];
    int32_t flags[1] = {ND_ITER_OUT};
    nde_karg_t k = {0, 0, 0, 0, 0.0};
    nd_inner_fn fn = nde_k_fill;
    nd_iter_t it;
    int status;

    if (nd_size(out) == 0){
        return OTI_OK;
    }

    switch (op){
    case ND_RED_PROD:
        k.s = 1.0;
        break;
    case ND_RED_MEAN:
        k.s = NAN;
        break;
    case ND_RED_VAR:
    case ND_RED_STD:
        k.s = (ddof >= 0) ? NAN : 0.0;              // 0 / 0, or 0 / -ddof
        break;
    case ND_RED_ANY:
    case ND_RED_ALL:
        fn         = ndr_k_fill_u8;
        k.reserved = (op == ND_RED_ALL);
        break;
    default:
        break;                                      // SUM: +0.0
    }

    ops[0] = out;

    if (nde_try_flat(ctx, fn, &k, NDE_NS_ARITH, 1, ops, 0, &status)){
        return status;
    }

    status = nd_iter_init(&it, 1, ops, flags, ND_ITER_ORDER_K);

    return (status == OTI_OK) ? nde_run(ctx, &it, fn, &k, NDE_NS_ARITH) : status;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Reduction of a into out (checked; no overlap with a). VAR / STD run the mean pass into out, then
// the deviation pass, which reads each mean back from out before overwriting it. `live` is the byte
// count of the caller's temporaries held meanwhile (ndr_pass). An empty input only writes identities.
static int ndr_run(oti_ctx* ctx, int32_t op, const ndarr_t* a, const int32_t* red, int32_t keepdims,
                   int64_t ddof, int64_t live, ndarr_t* out){

    ndr_plan_t p;
    int64_t m_out;
    int status;

    if (nd_size(a) == 0){
        return ndr_identity(ctx, op, ddof, out);
    }

    m_out = ndr_plan(op, a, red, keepdims, ddof, out, &p);

    if (m_out == 0){
        return OTI_OK;
    }

    status = ndr_pass(ctx, &p, m_out, live);

    if (status == OTI_OK && (op == ND_RED_VAR || op == ND_RED_STD)){
        p.kop  = NDR_K_SSD;
        status = ndr_pass(ctx, &p, m_out, live);
    }

    return status;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// A descriptor of a's kept axes in the result's shape (reduced axes: extent 1 with keepdims, else
// dropped), so that nde_alloc_k() gives the K layout of the input over the kept axes (S24).
static void ndr_kept_view(const ndarr_t* a, const int32_t* red, int32_t keepdims, ndarr_t* v){

    int32_t k, n = 0;

    nd_init_empty(v);
    v->dtype = a->dtype;

    for (k = 0; k < a->ndim; k++){
        if (!red[k] || keepdims){
            v->shape[n]   = red[k] ? 1 : a->shape[k];
            v->strides[n] = a->strides[k];
            n++;
        }
    }

    v->ndim = n;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int nd_reduce(oti_ctx* ctx, int32_t op, const ndarr_t* a, int32_t naxes, const int32_t* axes,
              int32_t keepdims, int64_t ddof, ndarr_t* res){

    int32_t red[OTI_ND_MAXDIM], ondim = 0;
    int64_t oshape[OTI_ND_MAXDIM];
    const ndarr_t* like;
    ndarr_t kv;
    int status;

    if (res == NULL){
        status = OTI_ERR_ARGUMENT;
    } else {

        nde_debug_res(res);
        nd_init_empty(res);
        status = oti_ctx_check(ctx);

        if (status == OTI_OK){
            status = ndr_args(op, a, naxes, axes, keepdims, red, &ondim, oshape);
        }

        if (status == OTI_OK){
            keepdims = (keepdims != 0);
            ndr_kept_view(a, red, keepdims, &kv);
            like   = &kv;
            status = nde_alloc_k(ctx, ndr_out_dtype(op), 1, &like, ondim, oshape, 0, res);
        }

        if (status == OTI_OK){

            status = ndr_run(ctx, op, a, red, keepdims, ddof, 0, res);

            if (status != OTI_OK){
                nd_release(res);
            }

        }

    }

    if (status != OTI_OK){
        oti_ctx_set_error(ctx, status, "nd_reduce", NULL);
    }

    return status;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Checks of nd_reduce_to's output: exact reduced shape, result dtype, writeable, no internal overlap.
static int ndr_check_out(int32_t op, const ndarr_t* out, int32_t ondim, const int64_t* oshape){

    int32_t k;

    nde_debug_input(out);

    if (out->ndim != ondim){
        return OTI_ERR_SHAPE;
    }

    for (k = 0; k < ondim; k++){
        if (out->shape[k] != oshape[k]){
            return OTI_ERR_SHAPE;
        }
    }

    if (out->dtype != ndr_out_dtype(op)){
        return OTI_ERR_DTYPE;
    }

    if (!(out->flags & ND_WRITEABLE)){
        return OTI_ERR_READONLY;
    }

    if (nd_size(out) > 0 && nd_internal_overlap(out)){
        return OTI_ERR_LAYOUT;
    }

    return OTI_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int nd_reduce_to(oti_ctx* ctx, int32_t op, const ndarr_t* a, int32_t naxes, const int32_t* axes,
                 int32_t keepdims, int64_t ddof, ndarr_t* out){

    int32_t red[OTI_ND_MAXDIM], ondim = 0;
    int64_t oshape[OTI_ND_MAXDIM];
    int status = oti_ctx_check(ctx);

    if (status == OTI_OK){
        status = (out == NULL) ? OTI_ERR_ARGUMENT
                               : ndr_args(op, a, naxes, axes, keepdims, red, &ondim, oshape);
    }

    if (status == OTI_OK){
        keepdims = (keepdims != 0);
        status   = ndr_check_out(op, out, ondim, oshape);
    }

    if (status == OTI_OK){

        if (nd_size(out) > 0 && nd_size(a) > 0 && nd_may_share_memory(out, a) != ND_SHARE_NONE){

            // Overlap (S14, [cM7]): reduce into a temporary in out's K layout, then copy.
            const ndarr_t* like = out;
            ndarr_t tmp;

            nd_init_empty(&tmp);
            status = nde_alloc_k(ctx, out->dtype, 1, &like, out->ndim, out->shape, 1, &tmp);

            if (status == OTI_OK){
                status = ndr_run(ctx, op, a, red, keepdims, ddof,
                                 nd_size(&tmp) * nd_itemsize(tmp.dtype), &tmp);
            }

            if (status == OTI_OK){
                status = nde_copy_into(ctx, &tmp, out);
            }

            nd_release(&tmp);

        } else {
            status = ndr_run(ctx, op, a, red, keepdims, ddof, 0, out);
        }

    }

    if (status != OTI_OK){
        oti_ctx_set_error(ctx, status, "nd_reduce_to", NULL);
    }

    return status;

}
// -------------------------------------------------------------------------------------------------------
