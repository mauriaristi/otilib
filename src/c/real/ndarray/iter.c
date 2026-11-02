// Multi-operand strided iterator (include/oti/real/ndarray/iter.h; PLAN-ndarray-contracts.md 3.4 and
// 5.3-5.4). Unity-included from src/c/real_ndarray.c after validate.c (nd_internal_overlap); static
// helpers carry the ndi_ prefix and are also used by elementwise.c (same translation unit).
//
// nd_iter_init():
//   1. broadcasts the shapes (right-aligned, NumPy rules) of the ND_ITER_IN operands, or, without
//      inputs, takes the shape of the first output;
//   2. checks every ND_ITER_OUT shape for equality, every ND_ITER_REDUCE_OUT for broadcastability,
//      then writeability and internal overlap of the outputs;
//   3. drops the axes of extent 1 and orders the others (C: logical order; K: decreasing |stride| of
//      the driving operand, the one with the most non-zero-stride axes (ties: lowest index), ties by
//      axis index; a stable insertion sort; contracts S26);
//   4. merges adjacent axes (outer i, inner i + 1) where every operand has bs[i] == bs[i+1]*n[i+1].
// A zero-size space keeps one axis of extent 0; a single-element space one axis of extent 1. Only the
// entries in use are written (nop operands x ndim axes, perm for the kept axes): no full memset.
// bstrides is [axis][operand], so a carry in nd_iter_run() touches one cache line per axis.
//
// nd_iter_run() walks [start, start + count) in the linear order of the prepared space, one call of
// the inner function per maximal run along the innermost axis inside the range. A kernel cut into
// fixed chunks of linear indices therefore visits every element in the same inner call structure
// whatever the thread count; elementwise results depend only on the element (no cross-element state).

#include "oti/real/ndarray.h"


// *******************************************************************************************************
// Magnitude of a stride as uint64_t (no signed negation, so INT64_MIN is safe), for the K order.
static inline uint64_t ndi_mag(int64_t v){

    return (v < 0) ? (uint64_t)0 - (uint64_t)v : (uint64_t)v;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Element stride of operand a on axis ax of an ndim-axis iteration shape: 0 on a broadcast axis (a
// missing leading axis or an extent of 1 in a).
static inline int64_t ndi_stride(const ndarr_t* a, int32_t ndim, int32_t ax){

    int32_t d = ax - (ndim - a->ndim);

    return (d < 0 || a->shape[d] == 1) ? 0 : a->strides[d];

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Driving operand of the K order (contracts S26): the operand with the most non-zero strides on the
// kept axes axes[0 .. nkept); ties go to the lowest index.
static int32_t ndi_driver(int32_t nop, const ndarr_t* const* ops, int32_t ndim, const int32_t* axes,
                          int32_t nkept){

    int32_t best = 0, best_n = -1;
    int32_t i, j;

    for (i = 0; i < nop; i++){

        int32_t n = 0;

        for (j = 0; j < nkept; j++){
            n += (ndi_stride(ops[i], ndim, axes[j]) != 0);
        }

        if (n > best_n){
            best   = i;
            best_n = n;
        }

    }

    return best;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// K order of the kept axes: axes[0 .. nkept) in increasing index on entry, outermost first on exit, by
// decreasing |stride| of the driving operand drv (a stable insertion sort: ties stay in axis order).
static void ndi_k_sort(const ndarr_t* drv, int32_t ndim, int32_t* axes, int32_t nkept){

    int32_t j, m;

    for (j = 1; j < nkept; j++){

        int32_t ax = axes[j];
        uint64_t key = ndi_mag(ndi_stride(drv, ndim, ax));

        for (m = j - 1; m >= 0 && ndi_mag(ndi_stride(drv, ndim, axes[m])) < key; m--){
            axes[m + 1] = axes[m];
        }

        axes[m + 1] = ax;

    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Broadcast shape of the operands selected by `sel` (flags & sel != 0; every operand when op_flags is
// NULL), NumPy rules: right-aligned, an extent of 1 stretches, any other mismatch is OTI_ERR_SHAPE.
// *p_ndim = 0 when no operand is selected. Used by nd_iter_init() and the allocating elementwise
// variants (which need the shape before allocating the result).
static int ndi_broadcast_shape(int32_t nop, const ndarr_t* const* ops, const int32_t* op_flags,
                               int32_t sel, int32_t* p_ndim, int64_t* shape){

    int32_t ndim = 0;
    int32_t i, k;

    for (i = 0; i < nop; i++){

        const ndarr_t* a = ops[i];

        if (op_flags != NULL && (op_flags[i] & sel) == 0){
            continue;
        }

        if (a->ndim > ndim){

            // Shift the axes found so far to the right and pad with extent 1.
            int32_t shift = a->ndim - ndim;

            for (k = ndim - 1; k >= 0; k--){
                shape[k + shift] = shape[k];
            }

            for (k = 0; k < shift; k++){
                shape[k] = 1;
            }

            ndim = a->ndim;

        }

        for (k = 0; k < a->ndim; k++){

            int64_t e = a->shape[k];
            int32_t d = k + (ndim - a->ndim);

            if (e == shape[d] || e == 1){
                continue;
            }

            if (shape[d] == 1){
                shape[d] = e;
            } else {
                return OTI_ERR_SHAPE;
            }

        }

    }

    *p_ndim = ndim;

    return OTI_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Nonzero when operand a has exactly the shape (ndim, shape).
static inline int ndi_same_shape(const ndarr_t* a, int32_t ndim, const int64_t* shape){

    int32_t k;

    if (a->ndim != ndim){
        return 0;
    }

    for (k = 0; k < ndim; k++){
        if (a->shape[k] != shape[k]){
            return 0;
        }
    }

    return 1;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Nonzero when operand a broadcasts to (ndim, shape) without enlarging it.
static inline int ndi_broadcasts_to(const ndarr_t* a, int32_t ndim, const int64_t* shape){

    int32_t k;

    if (a->ndim > ndim){
        return 0;
    }

    for (k = 0; k < a->ndim; k++){

        int64_t e = a->shape[k];

        if (e != 1 && e != shape[k + (ndim - a->ndim)]){
            return 0;
        }

    }

    return 1;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Internal overlap of a reduction target: its stride-0 axes are the reduced (written-to-repeatedly)
// axes by design, so only the axes with a nonzero stride must be injective.
static int ndi_reduce_out_overlap(const ndarr_t* a){

    ndarr_t t;
    int32_t k, n = 0;

    t = *a;     // a temporary copy of the fields; never released.
    t.flags &= ~(ND_RETAINED | ND_EXPORTED);

    for (k = 0; k < a->ndim; k++){
        if (a->strides[k] != 0 || a->shape[k] <= 1){
            t.shape[n]   = a->shape[k];
            t.strides[n] = a->strides[k];
            n++;
        }
    }

    t.ndim = n;

    return nd_internal_overlap(&t);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Checks the operands of nd_iter_init() against the iteration shape: shapes first (every operand),
// then writeability (every output, also an empty one), then internal overlap (non-empty outputs).
static int ndi_check_ops(int32_t nop, const ndarr_t* const* ops, const int32_t* op_flags,
                         int32_t ndim, const int64_t* shape, int64_t size){

    int32_t i;

    for (i = 0; i < nop; i++){

        if ((op_flags[i] & ND_ITER_OUT) && !ndi_same_shape(ops[i], ndim, shape)){
            return OTI_ERR_SHAPE;
        }

        if ((op_flags[i] & ND_ITER_REDUCE_OUT) && !ndi_broadcasts_to(ops[i], ndim, shape)){
            return OTI_ERR_SHAPE;
        }

    }

    for (i = 0; i < nop; i++){
        if ((op_flags[i] & (ND_ITER_OUT | ND_ITER_REDUCE_OUT)) && !(ops[i]->flags & ND_WRITEABLE)){
            return OTI_ERR_READONLY;
        }
    }

    if (size == 0){
        return OTI_OK;
    }

    for (i = 0; i < nop; i++){

        if ((op_flags[i] & ND_ITER_OUT) && nd_internal_overlap(ops[i])){
            return OTI_ERR_LAYOUT;
        }

        if ((op_flags[i] & ND_ITER_REDUCE_OUT) && ndi_reduce_out_overlap(ops[i])){
            return OTI_ERR_LAYOUT;
        }

    }

    return OTI_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int nd_iter_init(nd_iter_t* it, int32_t nop, const ndarr_t* const* ops, const int32_t* op_flags,
                 int32_t order){

    int64_t shape[OTI_ND_MAXDIM];
    int64_t size = 1;
    int32_t axes[OTI_ND_MAXDIM];
    int32_t ndim = 0, nkept = 0, nin = 0;
    int32_t i, k, j, status;

    if (it == NULL || ops == NULL || op_flags == NULL || nop < 1 || nop > ND_ITER_MAXOPS
        || (order != ND_ITER_ORDER_C && order != ND_ITER_ORDER_K)){
        return OTI_ERR_ARGUMENT;
    }

    for (i = 0; i < nop; i++){

        int32_t f = op_flags[i];

        if (ops[i] == NULL || nd_itemsize(ops[i]->dtype) == 0
            || (f != ND_ITER_IN && f != ND_ITER_OUT && f != ND_ITER_REDUCE_OUT)){
            return OTI_ERR_ARGUMENT;
        }

        if (ops[i]->ndim < 0 || ops[i]->ndim > OTI_ND_MAXDIM){
            return OTI_ERR_SHAPE;
        }

        nin += (f == ND_ITER_IN);

    }

    // 1. The iteration shape.
    if (nin > 0){

        status = ndi_broadcast_shape(nop, ops, op_flags, ND_ITER_IN, &ndim, shape);

    } else {

        // No input: the first output defines the space (fill); with reduction targets only, their
        // broadcast does.
        status = OTI_OK;
        i = 0;

        while (i < nop && op_flags[i] != ND_ITER_OUT){
            i++;
        }

        if (i < nop){
            ndim = ops[i]->ndim;
            for (k = 0; k < ndim; k++){
                shape[k] = ops[i]->shape[k];
            }
        } else {
            status = ndi_broadcast_shape(nop, ops, NULL, 0, &ndim, shape);
        }

    }

    if (status != OTI_OK){
        return status;
    }

    for (k = 0; k < ndim; k++){
        if (shape[k] == 0){
            size = 0;
            break;
        }
    }

    if (size != 0){
        for (k = 0; k < ndim; k++){
            if (oti_ckd_mul_i64(size, shape[k], &size)){
                return OTI_ERR_SIZE;
            }
        }
    }

    // 2. Operand checks.
    status = ndi_check_ops(nop, ops, op_flags, ndim, shape, size);

    if (status != OTI_OK){
        return status;
    }

    // Fill the per-operand fields (only the entries in use; no memset).
    it->nop  = nop;
    it->size = size;

    for (i = 0; i < nop; i++){
        it->data[i]     = (char*)ops[i]->data;
        it->itemsize[i] = (int32_t)nd_itemsize(ops[i]->dtype);
    }

    // 3. Kept axes (extent > 1), then their order.
    if (size != 0){
        for (k = 0; k < ndim; k++){
            if (shape[k] > 1){
                axes[nkept++] = k;
            }
        }
    }

    if (nkept == 0){

        // Zero-size space: one axis of extent 0; single element: one axis of extent 1.
        it->ndim     = 1;
        it->shape[0] = (size == 0) ? 0 : 1;

        for (i = 0; i < nop; i++){
            it->bstrides[0][i] = 0;
        }

        return OTI_OK;

    }

    if (order == ND_ITER_ORDER_K){
        ndi_k_sort(ops[ndi_driver(nop, ops, ndim, axes, nkept)], ndim, axes, nkept);
    }

    // Byte strides of every operand on every kept axis, in iteration order (0 on broadcast axes;
    // bounded by the operand's validated span, so the products do not overflow).
    for (j = 0; j < nkept; j++){

        it->perm[j]  = axes[j];
        it->shape[j] = shape[axes[j]];

        for (i = 0; i < nop; i++){
            it->bstrides[j][i] = ndi_stride(ops[i], ndim, axes[j]) * (int64_t)it->itemsize[i];
        }

    }

    // 4. Coalescing, from the innermost pair outward: axis j (outer) merges into j + 1 (inner) when
    // every operand steps over the whole inner axis by its outer stride. The product is checked: a
    // stride times the full extent may exceed the span by one stride.
    {
        int32_t n = nkept;

        for (j = n - 2; j >= 0; j--){

            int ok = 1;

            for (i = 0; i < nop && ok; i++){

                int64_t step;

                ok = !oti_ckd_mul_i64(it->bstrides[j + 1][i], it->shape[j + 1], &step)
                     && it->bstrides[j][i] == step;

            }

            if (!ok){
                continue;
            }

            it->shape[j + 1] *= it->shape[j];       // bounded by size, which fits int64.

            for (k = j; k < n - 1; k++){
                it->shape[k] = it->shape[k + 1];
                for (i = 0; i < nop; i++){
                    it->bstrides[k][i] = it->bstrides[k + 1][i];
                }
            }

            n--;

        }

        it->ndim = n;
    }

    return OTI_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int nd_iter_run(const nd_iter_t* it, int64_t start, int64_t count, nd_inner_fn fn, void* arg){

    int64_t idx[OTI_ND_MAXDIM];
    char* ptr[ND_ITER_MAXOPS];
    int64_t ist[ND_ITER_MAXOPS];
    int32_t nop, inner, i, k;
    int64_t pos, rem;

    if (it == NULL || fn == NULL){
        return OTI_ERR_ARGUMENT;
    }

    if (start < 0 || count < 0 || start > it->size || count > it->size - start){
        return OTI_ERR_INDEX;
    }

    if (count == 0){
        return OTI_OK;
    }

    nop   = it->nop;
    inner = it->ndim - 1;

    for (i = 0; i < nop; i++){
        ptr[i] = it->data[i];
        ist[i] = it->bstrides[inner][i];
    }

    // One axis (every contiguous or coalesced case): a single run.
    if (inner == 0){

        for (i = 0; i < nop; i++){
            ptr[i] += start * ist[i];
        }

        return fn(arg, count, ptr, ist);

    }

    // Multi-index of start (innermost last), and the pointers of its row start.
    pos = start;

    for (k = inner; k >= 0; k--){

        idx[k] = pos % it->shape[k];
        pos   /= it->shape[k];

        if (k < inner){
            for (i = 0; i < nop; i++){
                ptr[i] += idx[k] * it->bstrides[k][i];
            }
        }

    }

    rem = count;

    for (;;){

        char* p[ND_ITER_MAXOPS];
        int64_t n = it->shape[inner] - idx[inner];
        int status;

        if (n > rem){
            n = rem;
        }

        for (i = 0; i < nop; i++){
            p[i] = ptr[i] + idx[inner] * ist[i];
        }

        status = fn(arg, n, p, ist);

        if (status != OTI_OK){
            return status;
        }

        rem -= n;

        if (rem == 0){
            return OTI_OK;
        }

        // Next row: carry through the outer axes. The pointers never leave the operands' spans (an
        // axis that wraps steps back by (extent - 1) strides instead of past its end).
        idx[inner] = 0;

        for (k = inner - 1; k >= 0; k--){

            if (idx[k] + 1 < it->shape[k]){

                idx[k]++;
                for (i = 0; i < nop; i++){
                    ptr[i] += it->bstrides[k][i];
                }
                break;

            }

            for (i = 0; i < nop; i++){
                ptr[i] -= (it->shape[k] - 1) * it->bstrides[k][i];
            }
            idx[k] = 0;

        }

    }

}
// -------------------------------------------------------------------------------------------------------
