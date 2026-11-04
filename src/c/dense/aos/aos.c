// Dense AoS arrays (arro_t): memory, items, conversions, elementwise algebra, matmul, and linear
// algebra through the SoA layout (include/oti/dense/aos/aos.h).
//
// Owner: WP4 (dense-port). Unity-included from src/c/dense.c, so every static helper here carries
// the prefix dnaa_ (all dense sources share one translation unit). Elements are independent
// otinum_t: elementwise operations run the scalar `_to` kernels over them in fixed chunks through
// oti_parallel_for() (each worker has its own oti_ws() workspace), and the status of the lowest
// failing chunk is returned (contracts 5.3).


/// Elementwise loops may run in parallel from this many elements (the 1.x threshold, contracts 5.8).
#define DNAA_MIN_ELEMS 64

/// Fixed logical chunk of the elementwise loops, in elements. 1.x used `schedule(dynamic, 16)`; the
/// library dispenser claims a chunk with one atomic operation on a shared counter plus a call, so a
/// chunk of 256 elements (tens of microseconds of scalar OTI work) keeps that cost negligible (critic
/// W3 finding 2). Elements are independent: the chunk changes no value.
#define DNAA_CHUNK_ELEMS 256

/// matmul runs in parallel from this many output elements (the 1.x threshold), in chunks of this many.
/// An output element costs ncols(A) scalar products (gem), at least about 1 us at FEM sizes, so 16
/// outputs per chunk are >= 10 us of work per claim while an n x p result still has n * p / 16
/// chunks to balance (1.x: `dynamic, 4`).
#define DNAA_MATMUL_MIN_ELEMS 16
#define DNAA_MATMUL_CHUNK_ELEMS 16

/// Cost classes of an element operation (dnaa_ns()).
#define DNAA_LINEAR  0 ///< Sums, scalings, truncations: linear in the coefficients.
#define DNAA_PRODUCT 1 ///< Products, divisions, functions: about quadratic in the coefficients.

// Element operation of a chunked loop: which arguments it takes (dnaa_elem()).
#define DNAA_OO   0 ///< f_oo(a[e], b[e], r[e], dhl).
#define DNAA_NO   1 ///< f_oo(num, a[e], r[e], dhl).
#define DNAA_ON   2 ///< f_oo(a[e], num, r[e], dhl).
#define DNAA_OR   3 ///< f_or(a[e], val, r[e], dhl).
#define DNAA_RO   4 ///< f_ro(val, a[e], r[e], dhl).
#define DNAA_U    5 ///< f_u(a[e], r[e], dhl).
#define DNAA_TIM  6 ///< oti_truncate_im_to(idx, order, a[e], r[e]).
#define DNAA_TOR  7 ///< f_to(order, a[e], r[e]).
#define DNAA_C    8 ///< oti_compact_to(a[e], r[e]).


// *******************************************************************************************************
// An elementwise loop over the elements of an AoS array, for oti_parallel_for() (contracts 5.3).
typedef struct {
    int (*f_oo)(const otinum_t*, const otinum_t*, otinum_t*, dhelpl_t); ///< DNAA_OO, NO, ON.
    int (*f_or)(const otinum_t*, coeff_t, otinum_t*, dhelpl_t);         ///< DNAA_OR.
    int (*f_ro)(coeff_t, const otinum_t*, otinum_t*, dhelpl_t);         ///< DNAA_RO.
    int (*f_u)(const otinum_t*, otinum_t*, dhelpl_t);                   ///< DNAA_U.
    int (*f_to)(ord_t, const otinum_t*, otinum_t*);                     ///< DNAA_TOR.
    const otinum_t*   a; ///< First array operand (elements).
    const otinum_t*   b; ///< Second array operand (DNAA_OO).
    const otinum_t* num; ///< Scalar operand (DNAA_NO, DNAA_ON).
    otinum_t*         r; ///< Result elements.
    uint64_t          n; ///< Number of elements.
    dhelpl_t        dhl; ///< Direction helper.
    coeff_t         val; ///< Real operand (DNAA_OR, DNAA_RO).
    imdir_t         idx; ///< Direction (DNAA_TIM).
    int            kind; ///< DNAA_*.
    ord_t         order; ///< Order (DNAA_TIM, DNAA_TOR).
} dnaa_job_t;
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// A job of the given kind over the elements of a into r (the other fields zero).
static dnaa_job_t dnaa_job(int kind, const arro_t* a, arro_t* r){

    dnaa_job_t j;

    memset(&j, 0, sizeof(j));
    j.kind = kind;
    j.a    = arro_data(a);
    j.r    = arro_data(r);
    j.n    = arro_size(a);

    return j;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Runs the operation of a job on element e.
static inline int dnaa_elem(const dnaa_job_t* j, uint64_t e){

    switch (j->kind){
    case DNAA_OO:  return j->f_oo(&j->a[e], &j->b[e], &j->r[e], j->dhl);
    case DNAA_NO:  return j->f_oo(j->num, &j->a[e], &j->r[e], j->dhl);
    case DNAA_ON:  return j->f_oo(&j->a[e], j->num, &j->r[e], j->dhl);
    case DNAA_OR:  return j->f_or(&j->a[e], j->val, &j->r[e], j->dhl);
    case DNAA_RO:  return j->f_ro(j->val, &j->a[e], &j->r[e], j->dhl);
    case DNAA_U:   return j->f_u(&j->a[e], &j->r[e], j->dhl);
    case DNAA_TIM: return oti_truncate_im_to(j->idx, j->order, &j->a[e], &j->r[e]);
    case DNAA_TOR: return j->f_to(j->order, &j->a[e], &j->r[e]);
    default:       return oti_compact_to(&j->a[e], &j->r[e]);
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Chunk of an elementwise loop: elements [chunk * DNAA_CHUNK_ELEMS, ...), stopping at the first
// failure (the lowest failing chunk decides the status of the loop, contracts 5.3).
static int dnaa_chunk(void* arg, int64_t chunk, int32_t worker){

    const dnaa_job_t* j = (const dnaa_job_t*)arg;
    uint64_t e = (uint64_t)chunk * DNAA_CHUNK_ELEMS, e1 = e + DNAA_CHUNK_ELEMS;
    int st = DN_OK;

    (void)worker;

    if (e1 > j->n){
        e1 = j->n;
    }

    for (; e < e1 && st == DN_OK; e++){
        st = dnaa_elem(j, e);
    }

    return st;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Estimated serial cost (ns, one core) of one element operation on numbers like `num`, for
// oti_exec_plan() (contracts S27): a fixed call cost plus the coefficients (linear class) or their
// pairs (product class). An estimate only: it decides the worker count, never the values.
static double dnaa_ns(const otinum_t* num, int cls){

    double c = 1.0;

    if (num != NULL && num->trc_order <= _MAXORDER_OTI){
        c += (double)sshelp_ndir_total(num->nact, num->trc_order);
    }

    return (cls == DNAA_LINEAR) ? 30.0 + 0.5 * c : 50.0 + 0.15 * c * c;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Runs fn over the n_items items of a loop in fixed chunks of `chunk` items (contracts 5.3, 5.8; S27):
// in parallel with the worker count of oti_exec_plan() for ns nanoseconds per item, when n_items
// reaches the loop's 1.x threshold `floor` and the plan gives >= 2 workers; serially otherwise. The
// items are independent, so the values do not depend on the choice; the status is that of the lowest
// failing chunk.
static int dnaa_for(int64_t n_items, int64_t floor, int64_t chunk, double ns, oti_chunk_fn fn,
                    void* arg){

    int64_t nch = oti_exec_nchunks(n_items, chunk);

    if (n_items >= floor && nch >= 2){

        int32_t w = oti_exec_plan(NULL, n_items, chunk, ns);

        if (w >= 2){

            oti_ctx run = *oti_ctx_default();

            run.exec.nthreads = w;

            return oti_parallel_for(&run, nch, fn, arg);

        }

    }

    return oti_serial_for(nch, fn, arg);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Runs an elementwise job over its elements; ns from the first element of `like` and the class.
static int dnaa_run(dnaa_job_t* j, const otinum_t* like, int cls){

    return dnaa_for((int64_t)j->n, DNAA_MIN_ELEMS, DNAA_CHUNK_ELEMS, dnaa_ns(j->n > 0 ? like : NULL, cls),
                    dnaa_chunk, j);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// True when num points at an element of arr.
static int dnaa_inside(const otinum_t* num, const arro_t* arr){

    uintptr_t n = (uintptr_t)num, lo = (uintptr_t)arro_data(arr);

    return arro_data(arr) != NULL && arro_size(arr) > 0 && n >= lo
        && n < lo + arro_size(arr) * sizeof(otinum_t);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// The scalar operand of a scalar-array operation. When it is an element of the array or of the result,
// the operation could overwrite it or free it (the result is resized first): a copy in *p_local is
// used instead. Returns NULL when that copy fails. The caller releases *p_local with oti_free().
static const otinum_t* dnaa_stable(const otinum_t* num, const arro_t* arr1, const arro_t* res,
                                   otinum_t* p_local){

    if (!dnaa_inside(num, arr1) && !dnaa_inside(num, res)){
        return num;
    }

    return (oti_copy_to(num, p_local) == DN_OK) ? p_local : NULL;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Element store of an AoS array: one allocation holding a count and the element structs. It is the
// release context of the array's nd_buffer_t (nd_wrap()); dnaa_store_release() frees its first n
// elements, then the store, exactly once when the last reference goes.
typedef struct {
    uint64_t    n; ///< Elements owned by the store (freed with it).
    otinum_t e[1]; ///< Elements (at least one slot is allocated, also for an empty array).
} dnaa_store_t;
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void dnaa_store_release(void* ctx){

    dnaa_store_t* st = (dnaa_store_t*)ctx;
    uint64_t e;

    for (e = 0; e < st->n; e++){
        oti_free(&st->e[e]);
    }

    free(st);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Bytes of a store with `size` element slots (at least one); 0 when that overflows size_t.
static size_t dnaa_store_bytes(uint64_t size){

    uint64_t slots = (size > 0) ? size : 1;

    if (slots > (SIZE_MAX - offsetof(dnaa_store_t, e)) / sizeof(otinum_t)){
        return 0;
    }

    return offsetof(dnaa_store_t, e) + (size_t)slots * sizeof(otinum_t);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// The store of an owning array (the span base given to nd_wrap()).
static inline dnaa_store_t* dnaa_store_of(const arro_t* arr){

    return (dnaa_store_t*)nd_buffer_base(arr->elems.buf);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Writes the compact row-major layout (nrows, ncols) over the `re` fields into a descriptor whose data
// is already set.
static void dnaa_set_layout(ndarr_t* d, uint64_t nrows, uint64_t ncols){

    d->ndim       = 2;
    d->dtype      = OTI_F64;
    d->shape[0]   = (int64_t)nrows;
    d->shape[1]   = (int64_t)ncols;
    d->strides[0] = (int64_t)ncols * ARRO_W;
    d->strides[1] = ARRO_W;
    nd_update_flags(d);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Writes the compact row-major layout of an element shape S (ndim extents) over the `re` fields.
static void dnaa_set_shape(ndarr_t* d, int32_t ndim, const int64_t* shape){

    int64_t st = ARRO_W;
    int32_t k;

    d->ndim  = ndim;
    d->dtype = OTI_F64;

    for (k = ndim - 1; k >= 0; k--){

        d->shape[k]   = shape[k];
        d->strides[k] = st;
        st *= (shape[k] > 0) ? shape[k] : 1;

    }

    nd_update_flags(d);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Tells whether two arrays have the same element shape.
static int dnaa_same_shape(const arro_t* a, const arro_t* b){

    int32_t d;

    if (a->elems.ndim != b->elems.ndim){
        return 0;
    }

    for (d = 0; d < a->elems.ndim; d++){

        if (a->elems.shape[d] != b->elems.shape[d]){
            return 0;
        }

    }

    return 1;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// A new store of `size` slots holding no element yet (n = 0), wrapped in a retained descriptor of shape
// (nrows, ncols). On a failure (DN_ERR_MEMORY) nothing remains allocated.
static int dnaa_store_new(uint64_t nrows, uint64_t ncols, uint64_t size, ndarr_t* out){

    size_t nbytes = dnaa_store_bytes(size);
    dnaa_store_t* st;
    ndarr_t d;

    nd_init_empty(out);

    if (nbytes == 0 || nbytes > (size_t)INT64_MAX){
        return DN_ERR_MEMORY;
    }

    st = (dnaa_store_t*)malloc(nbytes);

    if (st == NULL){
        return DN_ERR_MEMORY;
    }

    st->n = 0;

    nd_init_empty(&d);
    d.data  = &st->e[0].re;
    d.flags = ND_WRITEABLE;
    dnaa_set_layout(&d, nrows, ncols);

    // Ownership of the store passes to the buffer: a failed wrap releases it through the callback.
    return (nd_wrap(NULL, &d, st, (int64_t)nbytes, dnaa_store_release, st, out) == OTI_OK) ? DN_OK
                                                                                          : DN_ERR_MEMORY;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// DN_OK when an nrows x ncols AoS shape is representable in its descriptor: both extents and their
// product, times the element struct size (the row stride and the span in bytes), within int64_t, also
// for an empty shape such as (0, 2^63 - 1) whose row stride would overflow; else DN_ERR_MEMORY.
// Checked before anything is modified.
static int dnaa_check_shape(uint64_t nrows, uint64_t ncols){

    uint64_t lim = (uint64_t)INT64_MAX / sizeof(otinum_t);

    if (nrows > lim || ncols > lim){
        return DN_ERR_MEMORY;
    }

    if (nrows != 0 && ncols != 0 && nrows > lim / ncols){
        return DN_ERR_MEMORY;
    }

    return DN_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// OTI_ERR_BUSY when the element store of an owning array is shared (another reference or a live export
// of its buffer, e.g. a 7b `.real` export): its elements must not be moved or freed under it
// (compatibility rule G1, contracts 7.2). DN_OK otherwise (also for an array without a buffer).
static int dnaa_check_unshared(const arro_t* arr){

    if (!(arr->elems.flags & ND_RETAINED)){
        return DN_OK;
    }

    if (nd_buffer_refs(arr->elems.buf) == 1 && nd_buffer_exports(arr->elems.buf) == 0){
        return DN_OK;
    }

    return OTI_ERR_BUSY;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
arro_t arro_init(void){

    arro_t arr;

    nd_init_empty(&arr.elems);
    arr.elems.flags = ND_C_CONTIG | ND_F_CONTIG | ND_WRITEABLE;
    dnaa_set_layout(&arr.elems, 0, 0);

    return arr;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void arro_free(arro_t* arr){

    if (arr == NULL){
        return;
    }

    // The buffer's callback frees every element and the store.
    if (arr->elems.flags & ND_RETAINED){
        nd_release(&arr->elems);
    }

    *arr = arro_init();

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int arro_resize(uint64_t nrows, uint64_t ncols, ord_t trc_order, arro_t* arr){

    uint64_t e, size = nrows * ncols, old, keep;
    int owns = (arr->elems.flags & ND_RETAINED) != 0;
    dnaa_store_t *st_old, *st_new;
    ndarr_t d;
    int status;

    if (nrows != 0 && size / nrows != ncols){
        return DN_ERR_MEMORY;
    }

    if (dnaa_check_shape(nrows, ncols) != DN_OK){
        return DN_ERR_MEMORY;
    }

    old = owns ? arro_size(arr) : 0;

    // The same shape: nothing changes.
    if (nrows == arro_nrows(arr) && ncols == arro_ncols(arr) && (owns || size == 0)){
        return DN_OK;
    }

    // Any other shape is a layout change: refused while the store is shared.
    status = dnaa_check_unshared(arr);

    if (status != DN_OK){
        return status;
    }

    // The same number of elements: only the shape changes (a buffer-less array keeps none).
    if (size == old){

        dnaa_set_layout(&arr->elems, nrows, ncols);

        return DN_OK;

    }

    if (size > old && trc_order > _MAXORDER_OTI){
        return DN_ERR_INDEX;
    }

    if (size >= SIZE_MAX / sizeof(otinum_t)){
        return DN_ERR_MEMORY;
    }

    // The new store first, so that a failure leaves the array unchanged.
    status = dnaa_store_new(nrows, ncols, size, &d);

    if (status != DN_OK){
        return status;
    }

    // Move the kept element structs (their coefficient buffers change owner), add real zeros.
    st_new = (dnaa_store_t*)nd_buffer_base(d.buf);
    keep   = (size < old) ? size : old;

    if (keep > 0){
        memcpy(st_new->e, arro_data(arr), (size_t)keep * sizeof(otinum_t));
    }

    st_new->n = keep;

    for (e = keep; e < size; e++){

        st_new->e[e] = oti_create_r(0.0, trc_order);
        st_new->n    = e + 1;

    }

    // The old store frees the elements past the new size; the moved ones are no longer its own.
    if (owns){

        st_old = dnaa_store_of(arr);

        for (e = size; e < old; e++){
            oti_free(&st_old->e[e]);
        }

        st_old->n = 0;
        nd_release(&arr->elems);

    }

    nd_move(&d, &arr->elems);

    return DN_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int arro_reshape(int32_t ndim, const int64_t* shape, arro_t* arr){

    uint64_t size = 1;
    int32_t d;

    if (arr == NULL || ndim < 0 || ndim > OTI_ND_MAXDIM - 1 || (ndim > 0 && shape == NULL)){
        return DN_ERR_SIZE;
    }

    for (d = 0; d < ndim; d++){

        if (shape[d] < 0 || (shape[d] != 0 && size > UINT64_MAX / (uint64_t)shape[d])){
            return DN_ERR_SIZE;
        }

        size *= (uint64_t)shape[d];

    }

    if (size != arro_size(arr)){
        return DN_ERR_SIZE;
    }

    dnaa_set_shape(&arr->elems, ndim, shape);

    return DN_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// The result of an elementwise function of arr1: res resized to arr1's size, then given arr1's shape.
static int dnaa_resize_like(const arro_t* arr1, ord_t trc_order, arro_t* res){

    int status = arro_resize(arro_nrows(arr1), arro_ncols(arr1), trc_order, res);

    if (status == DN_OK && arro_ndim(arr1) != 2){
        dnaa_set_shape(&res->elems, arro_ndim(arr1), arr1->elems.shape);
    }

    return status;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int arro_zeros_to(uint64_t nrows, uint64_t ncols, ord_t trc_order, arro_t* res){

    uint64_t e, n;
    otinum_t* d;
    int status = arro_resize(nrows, ncols, trc_order, res);

    if (status != DN_OK){
        return status;
    }

    // Size and data read once: the loop calls a function the compiler cannot see through.
    n = arro_size(res);
    d = arro_data(res);

    for (e = 0; e < n; e++){

        status = oti_create_empty_to(0, trc_order, &d[e]);

        if (status != DN_OK){
            return status;
        }

    } // end for

    return DN_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int arro_copy_to(const arro_t* arr1, arro_t* res){

    uint64_t e;
    int status;

    if (arr1 == res){
        return DN_OK;
    }

    status = dnaa_resize_like(arr1, 0, res);

    if (status != DN_OK){
        return status;
    }

    const otinum_t* x = arro_data(arr1);
    otinum_t* d = arro_data(res);
    uint64_t n = arro_size(arr1);

    for (e = 0; e < n; e++){

        status = oti_copy_to(&x[e], &d[e]);

        if (status != DN_OK){
            return status;
        }

    } // end for

    return DN_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
const otinum_t* arro_get_item_ptr(uint64_t i, uint64_t j, const arro_t* arr1){

    if (i >= arro_nrows(arr1) || j >= arro_ncols(arr1)){
        return NULL;
    }

    return &arro_data(arr1)[j + i * arro_ncols(arr1)];

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int arro_set_item(const otinum_t* num, uint64_t i, uint64_t j, arro_t* arr1){

    if (i >= arro_nrows(arr1) || j >= arro_ncols(arr1)){
        return DN_ERR_INDEX;
    }

    return oti_copy_to(num, &arro_data(arr1)[j + i * arro_ncols(arr1)]);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int arro_set_item_r(coeff_t val, uint64_t i, uint64_t j, arro_t* arr1){

    if (i >= arro_nrows(arr1) || j >= arro_ncols(arr1)){
        return DN_ERR_INDEX;
    }

    oti_set_r(val, &arro_data(arr1)[j + i * arro_ncols(arr1)]);

    return DN_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int arro_from_arrso_to(const arrso_t* arr1, arro_t* res, dhelpl_t dhl){

    uint64_t e;
    int status = arro_resize(arr1->nrows, arr1->ncols, 0, res);

    if (status != DN_OK){
        return status;
    }

    for (e = 0; e < arr1->size; e++){

        status = oti_from_soti_to(&arr1->p_data[e], &arro_data(res)[e], dhl);

        if (status != DN_OK){
            return status;
        }

    } // end for

    return DN_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
arrso_t arro_to_arrso(const arro_t* arr1, dhelpl_t dhl){

    arrso_t res = arrso_init();
    uint64_t e;

    if (arro_size(arr1) >= SIZE_MAX / sizeof(sotinum_t)){
        return res;
    }

    res.p_data = (sotinum_t*)malloc((size_t)arro_size(arr1) * sizeof(sotinum_t) + 1);

    if (res.p_data == NULL){
        return res;
    }

    const otinum_t* x = arro_data(arr1);
    uint64_t n = arro_size(arr1);

    for (e = 0; e < n; e++){
        res.p_data[e] = oti_to_soti(&x[e], dhl);
    }

    res.nrows = arro_nrows(arr1);
    res.ncols = arro_ncols(arr1);
    res.size  = arro_size(arr1);
    res.flag  = 1;

    return res;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int arro_zeros_nd_to(int32_t ndim, const int64_t* shape, ord_t trc_order, arro_t* res){

    uint64_t nr = 1, nc = 1;
    int32_t d;
    int status;

    if (ndim < 0 || ndim > OTI_ND_MAXDIM - 1 || (ndim > 0 && shape == NULL)){
        return DN_ERR_SIZE;
    }

    for (d = 0; d < ndim; d++){

        if (shape[d] < 0){
            return DN_ERR_SIZE;
        }

        if (d == 0){
            nr = (uint64_t)shape[0];
        } else if (shape[d] != 0 && nc > (uint64_t)INT64_MAX / (uint64_t)shape[d]){
            return DN_ERR_MEMORY;
        } else {
            nc *= (uint64_t)shape[d];
        }

    }

    status = arro_zeros_to(nr, nc, trc_order, res);

    return (status == DN_OK) ? arro_reshape(ndim, shape, res) : status;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int arro_to_oarr(const arro_t* arr1, oarr_t* res){

    DNOB_IN1(NULL, res, arro_to_oarr(arr1, c_.res));

    uint64_t e, i, j, s, size = arro_size(arr1), bp[_MAXORDER_OTI + 1];
    bases_t k = 0;
    ord_t trc = 0, act = 0, p, top;
    ndir_t np, idx, src;
    int status;

    for (e = 0; e < size; e++){

        k   = (arro_data(arr1)[e].nact > k) ? arro_data(arr1)[e].nact : k;
        trc = (arro_data(arr1)[e].trc_order > trc) ? arro_data(arr1)[e].trc_order : trc;
        act = (arro_data(arr1)[e].act_order > act) ? arro_data(arr1)[e].act_order : act;

    }

    // The capacity rule and the zero fill of exactly the new layout (never the old layout of res). A
    // matrix becomes a column-major SoA array (1.x); any other rank a C-order one, whose flat element
    // order is the AoS row-major order (same for ranks 0 and 1).
    if (arro_ndim(arr1) == 2){
        status = oarr_zeros_to(k, arro_nrows(arr1), arro_ncols(arr1), trc, res);
    } else {
        status = oarr_zeros_nd_to(k, arro_ndim(arr1), arr1->elems.shape, ND_LAYOUT_C, trc, res);
    }

    if (status != DN_OK){
        return status;
    }

    oarr_set_act_order(res, (act < trc) ? act : trc);

    for (p = 1; p <= trc; p++){
        bp[p] = 1 + sshelp_order_offset(k, p);
    }

    // Element (i, j), row-major here, goes to i + j*nrows of every column-major block. A smaller
    // nact or lower trc is a prefix of the layout: the order-p coefficients keep their index. The
    // shapes and data pointers are read once (the loop calls functions the compiler cannot see).
    const otinum_t* xd = arro_data(arr1);
    coeff_t* rd = oarr_data(res);
    uint64_t nr = arro_nrows(arr1), nc = arro_ncols(arr1);
    int mat = arro_ndim(arr1) == 2;

    for (e = 0; e < size; e++){

        const otinum_t* x = &xd[e];

        i = e / nc;
        j = e % nc;
        s = mat ? i + j * nr : e;

        rd[s] = x->re;
        top   = (x->trc_order < trc) ? x->trc_order : trc;

        for (p = 1; p <= top; p++){

            np  = sshelp_ndir_order(x->nact, p);
            src = sshelp_order_offset(x->nact, p);

            for (idx = 0; idx < np; idx++){
                rd[(bp[p] + idx) * size + s] = x->p_im[src + idx];
            }

        } // end for

    } // end for

    return DN_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int arro_from_oarr(const oarr_t* arr1, arro_t* res){

    DNOB_IN1(arr1, NULL, arro_from_oarr(c_.in[0], res));

    // Ranks above 2: read through a C-order copy relabelled as a vector (its flat order is the AoS
    // row-major order; a canonical array is column-major), then given the shape back.
    if (oarr_ndim(arr1) > 2){

        oarr_t t = oarr_init();
        dnob_shape_t S = dnob_shape_of(arr1), V;
        int st;

        S.layout = ND_LAYOUT_C;
        V.sdim   = 1;
        V.layout = ND_LAYOUT_F;
        V.ext[0] = oarr_size(arr1);
        st       = dnob_pack(arr1, &S, &t);

        if (st == DN_OK){

            dnob_set_layout(&t, (uint64_t)t.blocks.shape[0], &V);
            st = arro_from_oarr(&t, res);

        }

        if (st == DN_OK){
            st = arro_reshape(oarr_ndim(arr1), arr1->blocks.shape + 1, res);
        }

        oarr_free(&t);

        return st;

    }

    uint64_t e, i, j, s, size = oarr_size(arr1), bp[_MAXORDER_OTI + 1];
    ord_t p, trc = oarr_trc_order(arr1);
    ndir_t np, idx, off;
    int status;

    status = arro_resize(oarr_nrows(arr1), oarr_ncols(arr1), trc, res);

    // Ranks 0 and 1 keep their shape (the matricization is n x 1 / 1 x 1, the same flat order).
    if (status == DN_OK && oarr_ndim(arr1) != 2){
        status = arro_reshape(oarr_ndim(arr1), arr1->blocks.shape + 1, res);
    }

    if (status != DN_OK){
        return status;
    }

    for (p = 1; p <= trc; p++){
        bp[p] = 1 + sshelp_order_offset(oarr_nact(arr1), p);
    }

    // Shapes, layout and data pointers read once (the loop calls functions the compiler cannot see).
    otinum_t* rd = arro_data(res);
    const coeff_t* xd = oarr_data(arr1);
    uint64_t nr = oarr_nrows(arr1), nc = oarr_ncols(arr1);
    bases_t k = oarr_nact(arr1);
    ord_t act = (oarr_act_order(arr1) < trc) ? oarr_act_order(arr1) : trc;

    for (e = 0; e < size; e++){

        otinum_t* x = &rd[e];

        i = e / nc;
        j = e % nc;
        s = i + j * nr;

        status = oti_create_empty_to(k, trc, x);

        if (status != DN_OK){
            return status;
        }

        x->re        = xd[s];
        x->act_order = act;

        for (p = 1; p <= trc; p++){

            np  = sshelp_ndir_order(k, p);
            off = sshelp_order_offset(k, p);

            for (idx = 0; idx < np; idx++){
                x->p_im[off + idx] = xd[(bp[p] + idx) * size + s];
            }

        } // end for

    } // end for

    return DN_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int arro_sum_OO_to(const arro_t* arr1, const arro_t* arr2, arro_t* res, dhelpl_t dhl){

    dnaa_job_t j;
    int status;

    if (!dnaa_same_shape(arr1, arr2)){
        return DN_ERR_SIZE;
    }

    status = dnaa_resize_like(arr1, 0, res);

    if (status != DN_OK){
        return status;
    }

    j = dnaa_job(DNAA_OO, arr1, res);
    j.dhl  = dhl;
    j.f_oo = oti_sum_oo_to;
    j.b    = arro_data(arr2);

    status = dnaa_run(&j, arro_data(arr1), DNAA_LINEAR);

    return status;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int arro_sub_OO_to(const arro_t* arr1, const arro_t* arr2, arro_t* res, dhelpl_t dhl){

    dnaa_job_t j;
    int status;

    if (!dnaa_same_shape(arr1, arr2)){
        return DN_ERR_SIZE;
    }

    status = dnaa_resize_like(arr1, 0, res);

    if (status != DN_OK){
        return status;
    }

    j = dnaa_job(DNAA_OO, arr1, res);
    j.dhl  = dhl;
    j.f_oo = oti_sub_oo_to;
    j.b    = arro_data(arr2);

    status = dnaa_run(&j, arro_data(arr1), DNAA_LINEAR);

    return status;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int arro_mul_OO_to(const arro_t* arr1, const arro_t* arr2, arro_t* res, dhelpl_t dhl){

    dnaa_job_t j;
    int status;

    if (!dnaa_same_shape(arr1, arr2)){
        return DN_ERR_SIZE;
    }

    status = dnaa_resize_like(arr1, 0, res);

    if (status != DN_OK){
        return status;
    }

    j = dnaa_job(DNAA_OO, arr1, res);
    j.dhl  = dhl;
    j.f_oo = oti_mul_oo_to;
    j.b    = arro_data(arr2);

    status = dnaa_run(&j, arro_data(arr1), DNAA_PRODUCT);

    return status;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int arro_div_OO_to(const arro_t* arr1, const arro_t* arr2, arro_t* res, dhelpl_t dhl){

    dnaa_job_t j;
    int status;

    if (!dnaa_same_shape(arr1, arr2)){
        return DN_ERR_SIZE;
    }

    status = dnaa_resize_like(arr1, 0, res);

    if (status != DN_OK){
        return status;
    }

    j = dnaa_job(DNAA_OO, arr1, res);
    j.dhl  = dhl;
    j.f_oo = oti_div_oo_to;
    j.b    = arro_data(arr2);

    status = dnaa_run(&j, arro_data(arr1), DNAA_PRODUCT);

    return status;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int arro_sum_oO_to(const otinum_t* num, const arro_t* arr1, arro_t* res, dhelpl_t dhl){

    dnaa_job_t j;
    otinum_t local = oti_init();
    const otinum_t* p_num = dnaa_stable(num, arr1, res, &local);
    int status = (p_num == NULL) ? DN_ERR_MEMORY : dnaa_resize_like(arr1, 0,
                                                               res);

    if (status != DN_OK){

        oti_free(&local);
        return status;

    }

    j = dnaa_job(DNAA_NO, arr1, res);
    j.dhl  = dhl;
    j.f_oo = oti_sum_oo_to;
    j.num  = p_num;

    status = dnaa_run(&j, arro_data(arr1), DNAA_LINEAR);

    oti_free(&local);

    return status;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int arro_sum_rO_to(coeff_t val, const arro_t* arr1, arro_t* res, dhelpl_t dhl){

    dnaa_job_t j;
    int status = dnaa_resize_like(arr1, 0, res);

    if (status != DN_OK){
        return status;
    }

    j = dnaa_job(DNAA_OR, arr1, res);
    j.dhl  = dhl;
    j.f_or = oti_sum_or_to;
    j.val  = val;

    status = dnaa_run(&j, arro_data(arr1), DNAA_LINEAR);

    return status;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int arro_sub_oO_to(const otinum_t* num, const arro_t* arr1, arro_t* res, dhelpl_t dhl){

    dnaa_job_t j;
    otinum_t local = oti_init();
    const otinum_t* p_num = dnaa_stable(num, arr1, res, &local);
    int status = (p_num == NULL) ? DN_ERR_MEMORY : dnaa_resize_like(arr1, 0,
                                                               res);

    if (status != DN_OK){

        oti_free(&local);
        return status;

    }

    j = dnaa_job(DNAA_NO, arr1, res);
    j.dhl  = dhl;
    j.f_oo = oti_sub_oo_to;
    j.num  = p_num;

    status = dnaa_run(&j, arro_data(arr1), DNAA_LINEAR);

    oti_free(&local);

    return status;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int arro_sub_rO_to(coeff_t val, const arro_t* arr1, arro_t* res, dhelpl_t dhl){

    dnaa_job_t j;
    int status = dnaa_resize_like(arr1, 0, res);

    if (status != DN_OK){
        return status;
    }

    j = dnaa_job(DNAA_RO, arr1, res);
    j.dhl  = dhl;
    j.f_ro = oti_sub_ro_to;
    j.val  = val;

    status = dnaa_run(&j, arro_data(arr1), DNAA_LINEAR);

    return status;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int arro_sub_Oo_to(const arro_t* arr1, const otinum_t* num, arro_t* res, dhelpl_t dhl){

    dnaa_job_t j;
    otinum_t local = oti_init();
    const otinum_t* p_num = dnaa_stable(num, arr1, res, &local);
    int status = (p_num == NULL) ? DN_ERR_MEMORY : dnaa_resize_like(arr1, 0,
                                                               res);

    if (status != DN_OK){

        oti_free(&local);
        return status;

    }

    j = dnaa_job(DNAA_ON, arr1, res);
    j.dhl  = dhl;
    j.f_oo = oti_sub_oo_to;
    j.num  = p_num;

    status = dnaa_run(&j, arro_data(arr1), DNAA_LINEAR);

    oti_free(&local);

    return status;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int arro_sub_Or_to(const arro_t* arr1, coeff_t val, arro_t* res, dhelpl_t dhl){

    dnaa_job_t j;
    int status = dnaa_resize_like(arr1, 0, res);

    if (status != DN_OK){
        return status;
    }

    j = dnaa_job(DNAA_OR, arr1, res);
    j.dhl  = dhl;
    j.f_or = oti_sub_or_to;
    j.val  = val;

    status = dnaa_run(&j, arro_data(arr1), DNAA_LINEAR);

    return status;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int arro_mul_oO_to(const otinum_t* num, const arro_t* arr1, arro_t* res, dhelpl_t dhl){

    dnaa_job_t j;
    otinum_t local = oti_init();
    const otinum_t* p_num = dnaa_stable(num, arr1, res, &local);
    int status = (p_num == NULL) ? DN_ERR_MEMORY : dnaa_resize_like(arr1, 0,
                                                               res);

    if (status != DN_OK){

        oti_free(&local);
        return status;

    }

    j = dnaa_job(DNAA_NO, arr1, res);
    j.dhl  = dhl;
    j.f_oo = oti_mul_oo_to;
    j.num  = p_num;

    status = dnaa_run(&j, arro_data(arr1), DNAA_PRODUCT);

    oti_free(&local);

    return status;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int arro_mul_rO_to(coeff_t val, const arro_t* arr1, arro_t* res, dhelpl_t dhl){

    dnaa_job_t j;
    int status = dnaa_resize_like(arr1, 0, res);

    if (status != DN_OK){
        return status;
    }

    j = dnaa_job(DNAA_OR, arr1, res);
    j.dhl  = dhl;
    j.f_or = oti_mul_or_to;
    j.val  = val;

    status = dnaa_run(&j, arro_data(arr1), DNAA_LINEAR);

    return status;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int arro_div_oO_to(const otinum_t* num, const arro_t* arr1, arro_t* res, dhelpl_t dhl){

    dnaa_job_t j;
    otinum_t local = oti_init();
    const otinum_t* p_num = dnaa_stable(num, arr1, res, &local);
    int status = (p_num == NULL) ? DN_ERR_MEMORY : dnaa_resize_like(arr1, 0,
                                                               res);

    if (status != DN_OK){

        oti_free(&local);
        return status;

    }

    j = dnaa_job(DNAA_NO, arr1, res);
    j.dhl  = dhl;
    j.f_oo = oti_div_oo_to;
    j.num  = p_num;

    status = dnaa_run(&j, arro_data(arr1), DNAA_PRODUCT);

    oti_free(&local);

    return status;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int arro_div_rO_to(coeff_t val, const arro_t* arr1, arro_t* res, dhelpl_t dhl){

    dnaa_job_t j;
    int status = dnaa_resize_like(arr1, 0, res);

    if (status != DN_OK){
        return status;
    }

    j = dnaa_job(DNAA_RO, arr1, res);
    j.dhl  = dhl;
    j.f_ro = oti_div_ro_to;
    j.val  = val;

    status = dnaa_run(&j, arro_data(arr1), DNAA_PRODUCT);

    return status;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int arro_div_Oo_to(const arro_t* arr1, const otinum_t* num, arro_t* res, dhelpl_t dhl){

    dnaa_job_t j;
    otinum_t local = oti_init();
    const otinum_t* p_num = dnaa_stable(num, arr1, res, &local);
    int status = (p_num == NULL) ? DN_ERR_MEMORY : dnaa_resize_like(arr1, 0,
                                                               res);

    if (status != DN_OK){

        oti_free(&local);
        return status;

    }

    j = dnaa_job(DNAA_ON, arr1, res);
    j.dhl  = dhl;
    j.f_oo = oti_div_oo_to;
    j.num  = p_num;

    status = dnaa_run(&j, arro_data(arr1), DNAA_PRODUCT);

    oti_free(&local);

    return status;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int arro_div_Or_to(const arro_t* arr1, coeff_t val, arro_t* res, dhelpl_t dhl){

    dnaa_job_t j;
    int status = dnaa_resize_like(arr1, 0, res);

    if (status != DN_OK){
        return status;
    }

    j = dnaa_job(DNAA_OR, arr1, res);
    j.dhl  = dhl;
    j.f_or = oti_div_or_to;
    j.val  = val;

    status = dnaa_run(&j, arro_data(arr1), DNAA_LINEAR);

    return status;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int arro_neg_to(const arro_t* arr1, arro_t* res, dhelpl_t dhl){

    dnaa_job_t j;
    int status = dnaa_resize_like(arr1, 0, res);

    if (status != DN_OK){
        return status;
    }

    j = dnaa_job(DNAA_U, arr1, res);
    j.dhl  = dhl;
    j.f_u  = oti_neg_to;

    status = dnaa_run(&j, arro_data(arr1), DNAA_LINEAR);

    return status;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int arro_exp_to(const arro_t* arr1, arro_t* res, dhelpl_t dhl){

    dnaa_job_t j;
    int status = dnaa_resize_like(arr1, 0, res);

    if (status != DN_OK){
        return status;
    }

    j = dnaa_job(DNAA_U, arr1, res);
    j.dhl  = dhl;
    j.f_u  = oti_exp_to;

    status = dnaa_run(&j, arro_data(arr1), DNAA_PRODUCT);

    return status;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int arro_log_to(const arro_t* arr1, arro_t* res, dhelpl_t dhl){

    dnaa_job_t j;
    int status = dnaa_resize_like(arr1, 0, res);

    if (status != DN_OK){
        return status;
    }

    j = dnaa_job(DNAA_U, arr1, res);
    j.dhl  = dhl;
    j.f_u  = oti_log_to;

    status = dnaa_run(&j, arro_data(arr1), DNAA_PRODUCT);

    return status;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int arro_log10_to(const arro_t* arr1, arro_t* res, dhelpl_t dhl){

    dnaa_job_t j;
    int status = dnaa_resize_like(arr1, 0, res);

    if (status != DN_OK){
        return status;
    }

    j = dnaa_job(DNAA_U, arr1, res);
    j.dhl  = dhl;
    j.f_u  = oti_log10_to;

    status = dnaa_run(&j, arro_data(arr1), DNAA_PRODUCT);

    return status;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int arro_sqrt_to(const arro_t* arr1, arro_t* res, dhelpl_t dhl){

    dnaa_job_t j;
    int status = dnaa_resize_like(arr1, 0, res);

    if (status != DN_OK){
        return status;
    }

    j = dnaa_job(DNAA_U, arr1, res);
    j.dhl  = dhl;
    j.f_u  = oti_sqrt_to;

    status = dnaa_run(&j, arro_data(arr1), DNAA_PRODUCT);

    return status;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int arro_cbrt_to(const arro_t* arr1, arro_t* res, dhelpl_t dhl){

    dnaa_job_t j;
    int status = dnaa_resize_like(arr1, 0, res);

    if (status != DN_OK){
        return status;
    }

    j = dnaa_job(DNAA_U, arr1, res);
    j.dhl  = dhl;
    j.f_u  = oti_cbrt_to;

    status = dnaa_run(&j, arro_data(arr1), DNAA_PRODUCT);

    return status;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int arro_sin_to(const arro_t* arr1, arro_t* res, dhelpl_t dhl){

    dnaa_job_t j;
    int status = dnaa_resize_like(arr1, 0, res);

    if (status != DN_OK){
        return status;
    }

    j = dnaa_job(DNAA_U, arr1, res);
    j.dhl  = dhl;
    j.f_u  = oti_sin_to;

    status = dnaa_run(&j, arro_data(arr1), DNAA_PRODUCT);

    return status;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int arro_cos_to(const arro_t* arr1, arro_t* res, dhelpl_t dhl){

    dnaa_job_t j;
    int status = dnaa_resize_like(arr1, 0, res);

    if (status != DN_OK){
        return status;
    }

    j = dnaa_job(DNAA_U, arr1, res);
    j.dhl  = dhl;
    j.f_u  = oti_cos_to;

    status = dnaa_run(&j, arro_data(arr1), DNAA_PRODUCT);

    return status;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int arro_tan_to(const arro_t* arr1, arro_t* res, dhelpl_t dhl){

    dnaa_job_t j;
    int status = dnaa_resize_like(arr1, 0, res);

    if (status != DN_OK){
        return status;
    }

    j = dnaa_job(DNAA_U, arr1, res);
    j.dhl  = dhl;
    j.f_u  = oti_tan_to;

    status = dnaa_run(&j, arro_data(arr1), DNAA_PRODUCT);

    return status;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int arro_asin_to(const arro_t* arr1, arro_t* res, dhelpl_t dhl){

    dnaa_job_t j;
    int status = dnaa_resize_like(arr1, 0, res);

    if (status != DN_OK){
        return status;
    }

    j = dnaa_job(DNAA_U, arr1, res);
    j.dhl  = dhl;
    j.f_u  = oti_asin_to;

    status = dnaa_run(&j, arro_data(arr1), DNAA_PRODUCT);

    return status;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int arro_acos_to(const arro_t* arr1, arro_t* res, dhelpl_t dhl){

    dnaa_job_t j;
    int status = dnaa_resize_like(arr1, 0, res);

    if (status != DN_OK){
        return status;
    }

    j = dnaa_job(DNAA_U, arr1, res);
    j.dhl  = dhl;
    j.f_u  = oti_acos_to;

    status = dnaa_run(&j, arro_data(arr1), DNAA_PRODUCT);

    return status;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int arro_atan_to(const arro_t* arr1, arro_t* res, dhelpl_t dhl){

    dnaa_job_t j;
    int status = dnaa_resize_like(arr1, 0, res);

    if (status != DN_OK){
        return status;
    }

    j = dnaa_job(DNAA_U, arr1, res);
    j.dhl  = dhl;
    j.f_u  = oti_atan_to;

    status = dnaa_run(&j, arro_data(arr1), DNAA_PRODUCT);

    return status;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int arro_sinh_to(const arro_t* arr1, arro_t* res, dhelpl_t dhl){

    dnaa_job_t j;
    int status = dnaa_resize_like(arr1, 0, res);

    if (status != DN_OK){
        return status;
    }

    j = dnaa_job(DNAA_U, arr1, res);
    j.dhl  = dhl;
    j.f_u  = oti_sinh_to;

    status = dnaa_run(&j, arro_data(arr1), DNAA_PRODUCT);

    return status;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int arro_cosh_to(const arro_t* arr1, arro_t* res, dhelpl_t dhl){

    dnaa_job_t j;
    int status = dnaa_resize_like(arr1, 0, res);

    if (status != DN_OK){
        return status;
    }

    j = dnaa_job(DNAA_U, arr1, res);
    j.dhl  = dhl;
    j.f_u  = oti_cosh_to;

    status = dnaa_run(&j, arro_data(arr1), DNAA_PRODUCT);

    return status;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int arro_tanh_to(const arro_t* arr1, arro_t* res, dhelpl_t dhl){

    dnaa_job_t j;
    int status = dnaa_resize_like(arr1, 0, res);

    if (status != DN_OK){
        return status;
    }

    j = dnaa_job(DNAA_U, arr1, res);
    j.dhl  = dhl;
    j.f_u  = oti_tanh_to;

    status = dnaa_run(&j, arro_data(arr1), DNAA_PRODUCT);

    return status;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int arro_asinh_to(const arro_t* arr1, arro_t* res, dhelpl_t dhl){

    dnaa_job_t j;
    int status = dnaa_resize_like(arr1, 0, res);

    if (status != DN_OK){
        return status;
    }

    j = dnaa_job(DNAA_U, arr1, res);
    j.dhl  = dhl;
    j.f_u  = oti_asinh_to;

    status = dnaa_run(&j, arro_data(arr1), DNAA_PRODUCT);

    return status;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int arro_acosh_to(const arro_t* arr1, arro_t* res, dhelpl_t dhl){

    dnaa_job_t j;
    int status = dnaa_resize_like(arr1, 0, res);

    if (status != DN_OK){
        return status;
    }

    j = dnaa_job(DNAA_U, arr1, res);
    j.dhl  = dhl;
    j.f_u  = oti_acosh_to;

    status = dnaa_run(&j, arro_data(arr1), DNAA_PRODUCT);

    return status;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int arro_atanh_to(const arro_t* arr1, arro_t* res, dhelpl_t dhl){

    dnaa_job_t j;
    int status = dnaa_resize_like(arr1, 0, res);

    if (status != DN_OK){
        return status;
    }

    j = dnaa_job(DNAA_U, arr1, res);
    j.dhl  = dhl;
    j.f_u  = oti_atanh_to;

    status = dnaa_run(&j, arro_data(arr1), DNAA_PRODUCT);

    return status;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int arro_erf_to(const arro_t* arr1, arro_t* res, dhelpl_t dhl){

    dnaa_job_t j;
    int status = dnaa_resize_like(arr1, 0, res);

    if (status != DN_OK){
        return status;
    }

    j = dnaa_job(DNAA_U, arr1, res);
    j.dhl  = dhl;
    j.f_u  = oti_erf_to;

    status = dnaa_run(&j, arro_data(arr1), DNAA_PRODUCT);

    return status;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int arro_pow_to(const arro_t* arr1, coeff_t ex, arro_t* res, dhelpl_t dhl){

    dnaa_job_t j;
    int status = dnaa_resize_like(arr1, 0, res);

    if (status != DN_OK){
        return status;
    }

    j = dnaa_job(DNAA_OR, arr1, res);
    j.dhl  = dhl;
    j.f_or = oti_pow_to;
    j.val  = ex;

    status = dnaa_run(&j, arro_data(arr1), DNAA_PRODUCT);

    return status;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int arro_truncate_im_to(imdir_t idx, ord_t order, const arro_t* arr1, arro_t* res, dhelpl_t dhl){

    dnaa_job_t j;
    int status = dnaa_resize_like(arr1, 0, res);

    if (status != DN_OK){
        return status;
    }

    j = dnaa_job(DNAA_TIM, arr1, res);
    j.idx   = idx;
    j.order = order;

    status = dnaa_run(&j, arro_data(arr1), DNAA_LINEAR);

    return status;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int arro_truncate_order_to(ord_t order, const arro_t* arr1, arro_t* res, dhelpl_t dhl){

    dnaa_job_t j;
    int status = dnaa_resize_like(arr1, 0, res);

    if (status != DN_OK){
        return status;
    }

    j = dnaa_job(DNAA_TOR, arr1, res);
    j.f_to  = oti_truncate_order_to;
    j.order = order;

    status = dnaa_run(&j, arro_data(arr1), DNAA_LINEAR);

    return status;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int arro_get_order_im_to(ord_t order, const arro_t* arr1, arro_t* res, dhelpl_t dhl){

    dnaa_job_t j;
    int status = dnaa_resize_like(arr1, 0, res);

    if (status != DN_OK){
        return status;
    }

    j = dnaa_job(DNAA_TOR, arr1, res);
    j.f_to  = oti_get_order_im_to;
    j.order = order;

    status = dnaa_run(&j, arro_data(arr1), DNAA_LINEAR);

    return status;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int arro_compact_to(const arro_t* arr1, arro_t* res, dhelpl_t dhl){

    dnaa_job_t j;
    int status = dnaa_resize_like(arr1, 0, res);

    if (status != DN_OK){
        return status;
    }

    j = dnaa_job(DNAA_C, arr1, res);

    status = dnaa_run(&j, arro_data(arr1), DNAA_LINEAR);

    return status;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// The output elements of a matmul, for oti_parallel_for().
typedef struct {
    const otinum_t* a; ///< First factor, n x m, row-major.
    const otinum_t* b; ///< Second factor, m x p, row-major.
    otinum_t*       r; ///< Result, n x p, row-major (zeros on entry).
    uint64_t        m; ///< Inner dimension.
    uint64_t        p; ///< Result columns.
    uint64_t        n; ///< Number of output elements, n * p.
    dhelpl_t      dhl; ///< Direction helper.
} dnaa_mm_job_t;
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Output elements [chunk * DNAA_MATMUL_CHUNK_ELEMS, ...): each accumulates its products (gem: acc =
// a * b + acc), stopping at the first failure.
static int dnaa_matmul_chunk(void* arg, int64_t chunk, int32_t worker){

    const dnaa_mm_job_t* j = (const dnaa_mm_job_t*)arg;
    uint64_t e = (uint64_t)chunk * DNAA_MATMUL_CHUNK_ELEMS, e1 = e + DNAA_MATMUL_CHUNK_ELEMS, l;
    int st = DN_OK;

    (void)worker;

    if (e1 > j->n){
        e1 = j->n;
    }

    for (; e < e1 && st == DN_OK; e++){

        uint64_t i = e / j->p, c = e % j->p;
        otinum_t* acc = &j->r[e];

        if (j->m > 0){
            st = oti_mul_oo_to(&j->a[i * j->m], &j->b[c], acc, j->dhl);
        }

        for (l = 1; l < j->m && st == DN_OK; l++){
            st = oti_gem_oo_to(&j->a[l + i * j->m], &j->b[c + l * j->p], acc, acc, j->dhl);
        }

    }

    return st;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int arro_matmul_OO_to(const arro_t* arr1, const arro_t* arr2, arro_t* res, dhelpl_t dhl){

    uint64_t n = arro_nrows(arr1), m = arro_ncols(arr1), p = arro_ncols(arr2);
    dnaa_mm_job_t j;
    arro_t tmp = arro_init();
    int status;

    if (arro_nrows(arr2) != m){
        return DN_ERR_SIZE;
    }

    // The result replaces the store of res: refused while that store is shared.
    status = dnaa_check_unshared(res);

    if (status != DN_OK){
        return status;
    }

    // Each output element accumulates its products (gem: acc = a * b + acc); nact and trc grow to the
    // maximum over the row and column. The result is built apart so that it may alias an operand.
    status = arro_zeros_to(n, p, 0, &tmp);

    if (status != DN_OK){
        arro_free(&tmp);
        return status;
    }

    j.a   = arro_data(arr1);
    j.b   = arro_data(arr2);
    j.r   = arro_data(&tmp);
    j.m   = m;
    j.p   = p;
    j.n   = n * p;
    j.dhl = dhl;

    status = dnaa_for((int64_t)(n * p), DNAA_MATMUL_MIN_ELEMS, DNAA_MATMUL_CHUNK_ELEMS,
                      (double)m * dnaa_ns((m > 0 && n * p > 0) ? arro_data(arr1) : NULL, DNAA_PRODUCT),
                      dnaa_matmul_chunk, &j);

    if (status == DN_OK){

        arro_free(res);
        *res = tmp;

    } else {
        arro_free(&tmp);
    }

    return status;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int arro_transpose_to(const arro_t* arr1, arro_t* res){

    uint64_t i, j;
    arro_t tmp = arro_init();
    int status = dnaa_check_unshared(res);

    // The result replaces the store of res: refused while that store is shared.
    if (status != DN_OK){
        return status;
    }

    const otinum_t* x = arro_data(arr1);
    uint64_t nr = arro_nrows(arr1), nc = arro_ncols(arr1);
    otinum_t* d;

    status = arro_zeros_to(nc, nr, 0, &tmp);
    d      = arro_data(&tmp);

    for (i = 0; i < nr && status == DN_OK; i++){

        for (j = 0; j < nc && status == DN_OK; j++){
            status = oti_copy_to(&x[j + i * nc], &d[i + j * nr]);
        } // end for

    } // end for

    if (status == DN_OK){

        arro_free(res);
        *res = tmp;

    } else {
        arro_free(&tmp);
    }

    return status;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int arro_solve_to(const arro_t* K, const arro_t* b, arro_t* x, dhelpl_t dhl){

    oarr_t sK = oarr_init(), sb = oarr_init(), sx = oarr_init();
    int status = arro_to_oarr(K, &sK);

    if (status == DN_OK){
        status = arro_to_oarr(b, &sb);
    }

    if (status == DN_OK){
        status = oarr_solve_to(&sK, &sb, &sx, dhl);
    }

    if (status == DN_OK){
        status = arro_from_oarr(&sx, x);
    }

    oarr_free(&sK);
    oarr_free(&sb);
    oarr_free(&sx);

    return status;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int arro_inv_to(const arro_t* A, arro_t* res, dhelpl_t dhl){

    oarr_t sA = oarr_init(), sr = oarr_init();
    int status = arro_to_oarr(A, &sA);

    if (status == DN_OK){
        status = oarr_inv_to(&sA, &sr, dhl);
    }

    if (status == DN_OK){
        status = arro_from_oarr(&sr, res);
    }

    oarr_free(&sA);
    oarr_free(&sr);

    return status;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int arro_det_to(const arro_t* A, otinum_t* res, dhelpl_t dhl){

    oarr_t sA = oarr_init();
    int status = arro_to_oarr(A, &sA);

    if (status == DN_OK){
        status = oarr_det_to(&sA, res, dhl);
    }

    oarr_free(&sA);

    return status;

}
// -------------------------------------------------------------------------------------------------------
