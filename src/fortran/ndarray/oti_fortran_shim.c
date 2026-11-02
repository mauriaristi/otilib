// Fortran C-descriptor shim of the ndarray module (oti_fortran_shim.h; PLAN-ndarray.md "Fortran
// interoperability", Phase F2). Compiled per Fortran vendor against that vendor's ISO_Fortran_binding.h;
// the private BIND(C) interfaces of oti_real_ndarray.f90 call the otif_* entry points below.
//
// Protocol of one module procedure:
//   1. otif_prep_*(req, inputs...): validates and wraps the Fortran inputs (borrowed temporaries) and
//      the scalar arguments into a request held by the Fortran caller (type(otif_req), no allocation);
//   2. otif_run(req, r, layout, nthreads): r is a LOCAL allocatable temporary of the caller's rank (the
//      module hands it over with move_alloc: the gfortran SAVE / dtype workaround of decision 24). The
//      shim CFI_allocate()s it with the operation's extents, (a) in Fortran index order or (b) reversed,
//      and the core writes into it through the operation's `_to` variant (no copy); operations without a
//      `_to` variant (solve, inv, det, eye, arange, linspace) are computed and copied in one pass;
//   or otif_run_into(req, out, nthreads): the same into an existing Fortran array (solve through
//      nd_solve_to, in place).
//   Both run the core with a user oti_ctx built from nthreads (0 = inherit, 1 = serial; contracts S29)
//   and copy a core failure recorded in it to the calling thread's last error, which the module reads.
// File-static prefix: otif_.

#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include "oti_fortran_shim.h"

// Operations of a request.
#define OTIF_OP_BINARY    1
#define OTIF_OP_UNARY     2
#define OTIF_OP_REDUCE    3
#define OTIF_OP_MATMUL    4
#define OTIF_OP_FULL      5
#define OTIF_OP_SOLVE    16
#define OTIF_OP_INV      17
#define OTIF_OP_DET      18
#define OTIF_OP_EYE      19
#define OTIF_OP_ARANGE   20
#define OTIF_OP_LINSPACE 21

// Result layouts of otif_run (PLAN-ndarray.md "Results in C order": (a) default, (b) opt-in).
#define OTIF_LAYOUT_FORTRAN  0
#define OTIF_LAYOUT_REVERSED 1

#define OTIF_MAGIC 0x4f544946   // "OTIF": a request filled by an otif_prep_* call
#define OTIF_REQ_WORDS 192      // size of type(otif_req) in oti_real_ndarray.f90, in int64 words

// A request: the borrowed inputs and the scalar arguments of one operation.
typedef struct {
    int32_t magic;
    int32_t op;        // OTIF_OP_*
    int32_t code;      // ND_OP_*, ND_FN_* or ND_RED_*
    int32_t axis;      // reduction axis (0-based), or -1 for all axes
    int32_t keepdims;
    int32_t endpoint;
    int32_t ndim;      // OTIF_OP_FULL: rank of the result
    int32_t reserved;
    int64_t ddof;
    int64_t n, m, k;   // OTIF_OP_EYE; n is also the number of points of OTIF_OP_LINSPACE
    double  v0, v1, v2;
    int64_t shape[OTI_FORTRAN_MAXRANK];
    ndarr_t in[2];
} otif_req_t;

OTI_ND_STATIC_ASSERT(sizeof(otif_req_t) <= 8 * OTIF_REQ_WORDS, "type(otif_req) is too small");
OTI_ND_STATIC_ASSERT(CFI_MAX_RANK >= OTI_FORTRAN_MAXRANK, "vendor CFI_MAX_RANK below 15");

// Alignment of double without C11's _Alignof.
typedef struct {
    char   c;
    double d;
} otif_align_t;

#define OTIF_ALIGN_DOUBLE ((uintptr_t)offsetof(otif_align_t, d))


// *******************************************************************************************************
// Records a failure detected by the shim (the calling thread's last error) and returns it.
static int otif_fail(int st, const char* where, const char* msg){

    oti_ctx_set_error(NULL, st, where, msg);

    return st;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// *res = a * b for a, b >= 0; returns 1 on int64_t overflow (C99: no __builtin_mul_overflow assumed).
static int otif_mul_overflows(int64_t a, int64_t b, int64_t* res){

    if (a != 0 && b > INT64_MAX / a){
        return 1;
    }
    *res = a * b;

    return 0;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oti_fortran_is_contiguous(const CFI_cdesc_t* d){

    int64_t expect;
    int k;

    if (d == NULL || d->rank > OTI_FORTRAN_MAXRANK){
        return OTI_ERR_ARGUMENT;
    }
    for (k = 0; k < d->rank; k++){
        if (d->dim[k].extent < 0){
            return OTI_ERR_SHAPE;
        }
        if (d->dim[k].extent == 0){
            return 1;
        }
    }
    expect = (int64_t)d->elem_len;
    for (k = 0; k < d->rank; k++){
        if (d->dim[k].extent > 1 && (int64_t)d->dim[k].sm != expect){
            return 0;
        }
        // The stride the next dimension needs; the last dimension's product is never used.
        if (k + 1 < d->rank && otif_mul_overflows(expect, (int64_t)d->dim[k].extent, &expect)){
            return OTI_ERR_SIZE;
        }
    }

    return 1;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Checks the header fields of a real(c_double) descriptor (not the data). attr is the attribute the
// caller requires, or -1 for any of the three standard ones.
static int otif_check_header(const CFI_cdesc_t* d, int attr, const char* where){

    if (d == NULL){
        return otif_fail(OTI_ERR_ARGUMENT, where, "NULL descriptor");
    }
    if (d->type != CFI_type_double || d->elem_len != sizeof(double)){
        return otif_fail(OTI_ERR_DTYPE, where,
                         "not a real(c_double) descriptor (or a shim built for another vendor)");
    }
    if (d->rank > OTI_FORTRAN_MAXRANK){
        return otif_fail(OTI_ERR_SHAPE, where, "rank above 15");
    }
    if (d->attribute != CFI_attribute_other && d->attribute != CFI_attribute_allocatable &&
        d->attribute != CFI_attribute_pointer){
        return otif_fail(OTI_ERR_ARGUMENT, where, "unknown descriptor attribute");
    }
    if (attr >= 0 && d->attribute != attr){
        return otif_fail(OTI_ERR_ARGUMENT, where, "unexpected descriptor attribute");
    }

    return OTI_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Wraps a checked-header descriptor as a temporary ndarr_t. reversed: ndarray axis k is Fortran axis
// rank - 1 - k (results of layout (b)); otherwise axis k is Fortran axis k.
static int otif_wrap_desc(const CFI_cdesc_t* d, int32_t writeable, int32_t reversed, ndarr_t* out,
                          const char* where){

    int64_t shape[OTI_FORTRAN_MAXRANK], strides[OTI_FORTRAN_MAXRANK];
    int32_t rank = (int32_t)d->rank;
    int32_t k, f, empty = 0;
    int64_t step = 1, size = 1;

    nd_init_empty(out);
    // An unallocated / disassociated descriptor has undefined extents: test it first.
    if (d->attribute != CFI_attribute_other && d->base_addr == NULL){
        return otif_fail(OTI_ERR_ARGUMENT, where, "unallocated or disassociated array");
    }
    for (k = 0; k < rank; k++){
        if (d->dim[k].extent < 0){
            return otif_fail(OTI_ERR_SHAPE, where, "assumed-size array (extent -1)");
        }
        if (d->dim[k].extent == 0){
            empty = 1;
        }
    }
    // Checked size and byte count (contracts 2.3) before any stride is built: the product of the
    // non-zero extents, then times the element size, must fit int64_t (also for an empty array).
    for (k = 0; k < rank; k++){
        if (d->dim[k].extent > 0 && otif_mul_overflows(size, (int64_t)d->dim[k].extent, &size)){
            return otif_fail(OTI_ERR_SIZE, where, "extent product overflows int64");
        }
    }
    if (otif_mul_overflows(size, (int64_t)sizeof(double), &size)){
        return otif_fail(OTI_ERR_SIZE, where, "byte count overflows int64");
    }

    // Size 0 first: no stride or address logic (flang sends sm = 0 and lower_bound = 1 there).
    if (empty){
        for (k = 0; k < rank; k++){
            f = reversed ? rank - 1 - k : k;
            shape[k] = (int64_t)d->dim[f].extent;
        }
        for (k = rank - 1; k >= 0; k--){
            strides[k] = step;   // compact C strides (<= size, checked above); never read
            step = shape[k] > 1 ? step * shape[k] : step;
        }
        return nd_wrap_trusted(NULL, OTI_F64, rank, shape, strides, writeable, out);
    }

    if (d->base_addr == NULL){
        return otif_fail(OTI_ERR_ARGUMENT, where, "NULL base_addr of a non-empty array");
    }
    if ((uintptr_t)d->base_addr % OTIF_ALIGN_DOUBLE != 0){
        return otif_fail(OTI_ERR_LAYOUT, where, "base_addr not aligned for real(c_double)");
    }
    for (k = 0; k < rank; k++){
        f = reversed ? rank - 1 - k : k;
        if (d->dim[f].sm % (CFI_index_t)sizeof(double) != 0){
            return otif_fail(OTI_ERR_LAYOUT, where,
                             "stride not a multiple of the element size (packed derived type?)");
        }
        shape[k] = (int64_t)d->dim[f].extent;
        strides[k] = (int64_t)(d->dim[f].sm / (CFI_index_t)sizeof(double));
    }

    return nd_wrap_trusted(d->base_addr, OTI_F64, rank, shape, strides, writeable, out);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oti_fortran_wrap(const CFI_cdesc_t* d, int32_t writeable, ndarr_t* out){

    int st;

    if (out == NULL){
        return otif_fail(OTI_ERR_ARGUMENT, "oti_fortran_wrap", "NULL output");
    }
    nd_init_empty(out);
    st = otif_check_header(d, -1, "oti_fortran_wrap");
    if (st != OTI_OK){
        return st;
    }

    return otif_wrap_desc(d, writeable != 0, 0, out, "oti_fortran_wrap");

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Wraps one input of a request: an ordinary (attribute other) real(c_double) dummy, read-only.
static int otif_input(const CFI_cdesc_t* d, ndarr_t* out, const char* where){

    int st;

    nd_init_empty(out);
    st = otif_check_header(d, CFI_attribute_other, where);
    if (st != OTI_OK){
        return st;
    }

    return otif_wrap_desc(d, 0, 0, out, where);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Starts a request.
static int otif_req_start(otif_req_t* req, int32_t op, const char* where){

    if (req == NULL){
        return otif_fail(OTI_ERR_ARGUMENT, where, "NULL request");
    }
    memset(req, 0, sizeof(*req));
    nd_init_empty(&req->in[0]);
    nd_init_empty(&req->in[1]);
    req->op = op;
    req->axis = -1;

    return OTI_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Completes a request: marks it valid only if every step succeeded.
static int otif_req_done(otif_req_t* req, int st){

    req->magic = st == OTI_OK ? OTIF_MAGIC : 0;

    return st;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// req: out = a (op) b, NumPy broadcasting.
int otif_prep_binary(otif_req_t* req, int32_t op, const CFI_cdesc_t* a, const CFI_cdesc_t* b){

    int st = otif_req_start(req, OTIF_OP_BINARY, "otif_prep_binary");

    if (st != OTI_OK){
        return st;
    }
    req->code = op;
    st = otif_input(a, &req->in[0], "otif_prep_binary");
    if (st == OTI_OK){
        st = otif_input(b, &req->in[1], "otif_prep_binary");
    }

    return otif_req_done(req, st);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// req: out = fn(a).
int otif_prep_unary(otif_req_t* req, int32_t fn, const CFI_cdesc_t* a){

    int st = otif_req_start(req, OTIF_OP_UNARY, "otif_prep_unary");

    if (st != OTI_OK){
        return st;
    }
    req->code = fn;
    st = otif_input(a, &req->in[0], "otif_prep_unary");

    return otif_req_done(req, st);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// req: reduction of a over Fortran dimension dim (1 .. rank), or over every axis for dim == 0.
int otif_prep_reduce(otif_req_t* req, int32_t op, const CFI_cdesc_t* a, int32_t dim, int32_t keepdims,
                     int64_t ddof){

    int st = otif_req_start(req, OTIF_OP_REDUCE, "otif_prep_reduce");

    if (st != OTI_OK){
        return st;
    }
    req->code = op;
    req->keepdims = keepdims != 0;
    req->ddof = ddof;
    st = otif_input(a, &req->in[0], "otif_prep_reduce");
    if (st == OTI_OK && (dim < 0 || dim > req->in[0].ndim)){
        st = otif_fail(OTI_ERR_INDEX, "otif_prep_reduce", "dim outside 1 .. rank(array)");
    }
    req->axis = dim - 1;

    return otif_req_done(req, st);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// req: numpy.matmul(a, b).
int otif_prep_matmul(otif_req_t* req, const CFI_cdesc_t* a, const CFI_cdesc_t* b){

    int st = otif_req_start(req, OTIF_OP_MATMUL, "otif_prep_matmul");

    if (st != OTI_OK){
        return st;
    }
    st = otif_input(a, &req->in[0], "otif_prep_matmul");
    if (st == OTI_OK){
        st = otif_input(b, &req->in[1], "otif_prep_matmul");
    }

    return otif_req_done(req, st);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// req: x with a x = b (numpy.linalg.solve).
int otif_prep_solve(otif_req_t* req, const CFI_cdesc_t* a, const CFI_cdesc_t* b){

    int st = otif_req_start(req, OTIF_OP_SOLVE, "otif_prep_solve");

    if (st != OTI_OK){
        return st;
    }
    st = otif_input(a, &req->in[0], "otif_prep_solve");
    if (st == OTI_OK){
        st = otif_input(b, &req->in[1], "otif_prep_solve");
    }

    return otif_req_done(req, st);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// req: inverse (kind 0) or determinant (kind 1) of a.
int otif_prep_matrix(otif_req_t* req, int32_t kind, const CFI_cdesc_t* a){

    int st = otif_req_start(req, kind == 1 ? OTIF_OP_DET : OTIF_OP_INV, "otif_prep_matrix");

    if (st != OTI_OK){
        return st;
    }
    if (kind != 0 && kind != 1){
        return otif_req_done(req, otif_fail(OTI_ERR_ARGUMENT, "otif_prep_matrix", "unknown kind"));
    }
    st = otif_input(a, &req->in[0], "otif_prep_matrix");

    return otif_req_done(req, st);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// req: an array of extents shape(1:ndim) (Fortran order) filled with value.
int otif_prep_full(otif_req_t* req, int32_t ndim, const int64_t* shape, double value){

    int32_t k;
    int st = otif_req_start(req, OTIF_OP_FULL, "otif_prep_full");

    if (st != OTI_OK){
        return st;
    }
    if (ndim < 0 || ndim > OTI_FORTRAN_MAXRANK){
        return otif_req_done(req, otif_fail(OTI_ERR_SHAPE, "otif_prep_full", "rank above 15"));
    }
    if (ndim > 0 && shape == NULL){
        return otif_req_done(req, otif_fail(OTI_ERR_ARGUMENT, "otif_prep_full", "NULL shape"));
    }
    for (k = 0; k < ndim; k++){
        if (shape[k] < 0){
            return otif_req_done(req, otif_fail(OTI_ERR_SHAPE, "otif_prep_full", "negative extent"));
        }
        req->shape[k] = shape[k];
    }
    req->ndim = ndim;
    req->v0 = value;

    return otif_req_done(req, OTI_OK);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// req: numpy.eye(n, m, k).
int otif_prep_eye(otif_req_t* req, int64_t n, int64_t m, int64_t k){

    int st = otif_req_start(req, OTIF_OP_EYE, "otif_prep_eye");

    if (st != OTI_OK){
        return st;
    }
    req->n = n;
    req->m = m;
    req->k = k;

    return otif_req_done(req, OTI_OK);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// req: numpy.arange(start, stop, step).
int otif_prep_arange(otif_req_t* req, double start, double stop, double step){

    int st = otif_req_start(req, OTIF_OP_ARANGE, "otif_prep_arange");

    if (st != OTI_OK){
        return st;
    }
    req->v0 = start;
    req->v1 = stop;
    req->v2 = step;

    return otif_req_done(req, OTI_OK);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// req: numpy.linspace(start, stop, num, endpoint).
int otif_prep_linspace(otif_req_t* req, double start, double stop, int64_t num, int32_t endpoint){

    int st = otif_req_start(req, OTIF_OP_LINSPACE, "otif_prep_linspace");

    if (st != OTI_OK){
        return st;
    }
    req->v0 = start;
    req->v1 = stop;
    req->n = num;
    req->endpoint = endpoint != 0;

    return otif_req_done(req, OTI_OK);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// numpy.matmul result shape (1-D operands promoted and their axis removed, batch axes broadcast).
static int otif_matmul_shape(const ndarr_t* a, const ndarr_t* b, int32_t* ndim, int64_t* shape){

    int32_t na = a->ndim, nb = b->ndim, nba, nbb, nbatch, k, n = 0;
    int64_t ak, bk, ea, eb;

    if (na < 1 || nb < 1){
        return OTI_ERR_SHAPE;   // nd_matmul_to() records it
    }
    ak = a->shape[na - 1];
    bk = nb == 1 ? b->shape[0] : b->shape[nb - 2];
    if (ak != bk){
        return OTI_ERR_SHAPE;
    }
    nba = na > 2 ? na - 2 : 0;
    nbb = nb > 2 ? nb - 2 : 0;
    nbatch = nba > nbb ? nba : nbb;
    for (k = 0; k < nbatch; k++){
        ea = k - (nbatch - nba) >= 0 ? a->shape[k - (nbatch - nba)] : 1;
        eb = k - (nbatch - nbb) >= 0 ? b->shape[k - (nbatch - nbb)] : 1;
        if (ea != eb && ea != 1 && eb != 1){
            return OTI_ERR_SHAPE;
        }
        shape[n++] = ea == 1 ? eb : ea;
    }
    if (na > 1){
        shape[n++] = a->shape[na - 2];
    }
    if (nb > 1){
        shape[n++] = b->shape[nb - 1];
    }
    *ndim = n;

    return OTI_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Result shape of an operation with a `_to` variant (ndarray axis order). Shape failures are left to
// the `_to` call itself where it reports them, so the recorded last error names the core function.
static int otif_result_shape(const otif_req_t* req, int32_t* ndim, int64_t* shape){

    const ndarr_t* ops[2];
    const ndarr_t* a = &req->in[0];
    int32_t k, n = 0;
    int st;

    switch (req->op){
    case OTIF_OP_BINARY:
        ops[0] = &req->in[0];
        ops[1] = &req->in[1];
        st = nd_broadcast_shapes(2, ops, ndim, shape);
        return st;
    case OTIF_OP_UNARY:
        *ndim = a->ndim;
        for (k = 0; k < a->ndim; k++){
            shape[k] = a->shape[k];
        }
        return OTI_OK;
    case OTIF_OP_REDUCE:
        for (k = 0; k < a->ndim; k++){
            if (req->axis < 0 || k == req->axis){
                if (req->keepdims){
                    shape[n++] = 1;
                }
            } else {
                shape[n++] = a->shape[k];
            }
        }
        *ndim = n;
        return OTI_OK;
    case OTIF_OP_MATMUL:
        st = otif_matmul_shape(&req->in[0], &req->in[1], ndim, shape);
        if (st != OTI_OK){
            return otif_fail(st, "otif_run", "matmul operand shapes do not match (numpy.matmul rules)");
        }
        return OTI_OK;
    case OTIF_OP_FULL:
        *ndim = req->ndim;
        for (k = 0; k < req->ndim; k++){
            shape[k] = req->shape[k];
        }
        return OTI_OK;
    default:
        return otif_fail(OTI_ERR_ARGUMENT, "otif_run", "operation without a direct form");
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Runs an operation with a `_to` variant into an existing output.
static int otif_exec_to(oti_ctx* ctx, const otif_req_t* req, ndarr_t* out){

    int32_t axis = req->axis;

    switch (req->op){
    case OTIF_OP_BINARY:
        return nd_binary_to(ctx, req->code, &req->in[0], &req->in[1], out);
    case OTIF_OP_UNARY:
        return nd_unary_to(ctx, req->code, &req->in[0], out);
    case OTIF_OP_REDUCE:
        return nd_reduce_to(ctx, req->code, &req->in[0], axis < 0 ? -1 : 1, axis < 0 ? NULL : &axis,
                            req->keepdims, req->ddof, out);
    case OTIF_OP_MATMUL:
        return nd_matmul_to(ctx, &req->in[0], &req->in[1], out);
    case OTIF_OP_FULL:
        return nd_fill(ctx, out, req->v0);
    default:
        return otif_fail(OTI_ERR_ARGUMENT, "otif_run", "operation without a direct form");
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Runs an operation without a `_to` variant into a new retained array.
static int otif_compute(oti_ctx* ctx, const otif_req_t* req, ndarr_t* res){

    nd_init_empty(res);
    switch (req->op){
    case OTIF_OP_SOLVE:
        return nd_solve(ctx, &req->in[0], &req->in[1], res);
    case OTIF_OP_INV:
        return nd_inv(ctx, &req->in[0], res);
    case OTIF_OP_DET:
        return nd_det(ctx, &req->in[0], res);
    case OTIF_OP_EYE:
        return nd_eye(ctx, req->n, req->m, req->k, ND_LAYOUT_F, res);
    case OTIF_OP_ARANGE:
        return nd_arange(ctx, req->v0, req->v1, req->v2, res);
    case OTIF_OP_LINSPACE:
        return nd_linspace(ctx, req->v0, req->v1, req->n, req->endpoint, res);
    default:
        return otif_fail(OTI_ERR_ARGUMENT, "otif_run", "unknown operation");
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// The context of one call: a user context with the default policy and budgets (0 = the default's,
// S6) and exec.nthreads = nthreads (0 = inherit, 1 = serial). Called by otif_run / otif_run_into and
// by the conformance tests.
int otif_make_ctx(int32_t nthreads, oti_ctx* ctx){

    int st;

    if (ctx == NULL){
        return otif_fail(OTI_ERR_ARGUMENT, "otif_make_ctx", "NULL context");
    }
    st = oti_ctx_init(ctx);
    if (st != OTI_OK){
        return otif_fail(st, "otif_make_ctx", "oti_ctx_init failed");
    }
    if (nthreads < 0){
        return otif_fail(OTI_ERR_ARGUMENT, "otif_make_ctx", "nthreads < 0");
    }
    ctx->exec.nthreads = nthreads;

    return OTI_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// A failure recorded in the call's user context is copied to the calling thread's record (what
// nd_last_error() reads); failures recorded by the shim itself are already there.
static int otif_mirror_error(const oti_ctx* ctx, int st){

    const char* where = NULL;
    const char* msg = NULL;

    if (st != OTI_OK && oti_ctx_last_error(ctx, &where, &msg) == st){
        oti_ctx_set_error(NULL, st, where, msg);
    }

    return st;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// 1 for the operations that write straight into the output through a `_to` variant.
static int otif_is_direct(int32_t op){

    return op == OTIF_OP_BINARY || op == OTIF_OP_UNARY || op == OTIF_OP_REDUCE || op == OTIF_OP_MATMUL ||
           op == OTIF_OP_FULL;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Allocates the local Fortran temporary r (allocatable, unallocated) with the ndarray extents shape,
// in layout (a) (Fortran extents = shape) or (b) (Fortran extents = shape reversed), and wraps it.
static int otif_allocate(CFI_cdesc_t* r, int32_t ndim, const int64_t* shape, int32_t layout,
                         ndarr_t* out){

    CFI_index_t lb[OTI_FORTRAN_MAXRANK + 1], ub[OTI_FORTRAN_MAXRANK + 1];
    int32_t k, f;
    int st;

    if (ndim != (int32_t)r->rank){
        return otif_fail(OTI_ERR_SHAPE, "otif_run",
                         "the result array's rank differs from the operation's result rank");
    }
    for (k = 0; k < ndim; k++){
        f = layout == OTIF_LAYOUT_REVERSED ? ndim - 1 - k : k;
        lb[f] = 1;
        ub[f] = (CFI_index_t)shape[k];
    }
    if (CFI_allocate(r, lb, ub, 0) != CFI_SUCCESS || r->base_addr == NULL){
        return otif_fail(OTI_ERR_MEMORY, "otif_run", "CFI_allocate failed");
    }
    if (oti_fortran_is_contiguous(r) != 1){
        (void)CFI_deallocate(r);
        return otif_fail(OTI_ERR_LAYOUT, "otif_run", "CFI_allocate gave a non-contiguous array");
    }
    st = otif_wrap_desc(r, 1, layout == OTIF_LAYOUT_REVERSED, out, "otif_run");
    if (st != OTI_OK){
        (void)CFI_deallocate(r);
    }

    return st;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Runs a request into r: real(c_double), allocatable, intent(out), unallocated, of the result's rank,
// with nthreads workers (0 = inherit). On failure r is left unallocated.
int otif_run(const otif_req_t* req, CFI_cdesc_t* r, int32_t layout, int32_t nthreads){

    int64_t shape[OTI_ND_MAXDIM];
    int32_t ndim = 0;
    ndarr_t out, res;
    oti_ctx ctx;
    int st;

    nd_init_empty(&out);
    nd_init_empty(&res);
    if (req == NULL || req->magic != OTIF_MAGIC){
        return otif_fail(OTI_ERR_ARGUMENT, "otif_run", "request not prepared");
    }
    if (layout != OTIF_LAYOUT_FORTRAN && layout != OTIF_LAYOUT_REVERSED){
        return otif_fail(OTI_ERR_ARGUMENT, "otif_run", "unknown result layout");
    }
    st = otif_check_header(r, CFI_attribute_allocatable, "otif_run");
    if (st != OTI_OK){
        return st;
    }
    if (r->base_addr != NULL){
        return otif_fail(OTI_ERR_ARGUMENT, "otif_run", "result array already allocated");
    }
    st = otif_make_ctx(nthreads, &ctx);
    if (st != OTI_OK){
        return st;
    }

    if (otif_is_direct(req->op)){
        st = otif_result_shape(req, &ndim, shape);
        if (st == OTI_OK && ndim > OTI_FORTRAN_MAXRANK){
            st = otif_fail(OTI_ERR_SHAPE, "otif_run", "result rank above 15");
        }
        if (st == OTI_OK){
            st = otif_allocate(r, ndim, shape, layout, &out);
            if (st == OTI_OK){
                st = otif_exec_to(&ctx, req, &out);
            }
        } else if (req->op == OTIF_OP_BINARY){
            // Let the core report the broadcast failure under its own name.
            st = nd_binary_to(&ctx, req->code, &req->in[0], &req->in[1], &out);
            st = st == OTI_OK ? OTI_ERR_SHAPE : st;
        }
    } else {
        st = otif_compute(&ctx, req, &res);
        if (st == OTI_OK){
            // A positive LAPACK info leaves res empty (nd_solve, nd_inv): it is returned as is.
            st = res.ndim > OTI_FORTRAN_MAXRANK
                 ? otif_fail(OTI_ERR_SHAPE, "otif_run", "result rank above 15")
                 : otif_allocate(r, res.ndim, res.shape, layout, &out);
            if (st == OTI_OK){
                st = nd_assign(&ctx, &res, &out);
            }
        }
        nd_release(&res);
    }
    if (st != OTI_OK && r->base_addr != NULL){
        (void)CFI_deallocate(r);
    }

    return otif_mirror_error(&ctx, st);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Runs a request into an existing Fortran array (attribute other, written in place, index order (a)),
// with nthreads workers (0 = inherit).
int otif_run_into(const otif_req_t* req, CFI_cdesc_t* out, int32_t nthreads){

    int64_t shape[OTI_ND_MAXDIM];
    int32_t ndim = 0, k;
    ndarr_t o, res;
    oti_ctx ctx;
    int st;

    nd_init_empty(&o);
    nd_init_empty(&res);
    if (req == NULL || req->magic != OTIF_MAGIC){
        return otif_fail(OTI_ERR_ARGUMENT, "otif_run_into", "request not prepared");
    }
    st = otif_check_header(out, CFI_attribute_other, "otif_run_into");
    if (st == OTI_OK){
        st = otif_wrap_desc(out, 1, 0, &o, "otif_run_into");
    }
    if (st == OTI_OK){
        st = otif_make_ctx(nthreads, &ctx);
    }
    if (st != OTI_OK){
        return st;
    }

    if (otif_is_direct(req->op)){
        if (req->op == OTIF_OP_FULL){
            // nd_fill() takes any shape: check the requested one here.
            st = otif_result_shape(req, &ndim, shape);
            for (k = 0; st == OTI_OK && k < ndim; k++){
                st = shape[k] == o.shape[k] ? OTI_OK : OTI_ERR_SHAPE;
            }
            if (st == OTI_OK && ndim != o.ndim){
                st = OTI_ERR_SHAPE;
            }
            if (st != OTI_OK){
                return otif_fail(st, "otif_run_into", "output shape differs from the requested shape");
            }
        }
        return otif_mirror_error(&ctx, otif_exec_to(&ctx, req, &o));
    }
    if (req->op == OTIF_OP_SOLVE){
        // In place through the core's `_to` form (S29): no result array, no copy.
        return otif_mirror_error(&ctx, nd_solve_to(&ctx, &req->in[0], &req->in[1], &o));
    }

    st = otif_compute(&ctx, req, &res);
    if (st == OTI_OK){
        if (res.ndim != o.ndim){
            st = OTI_ERR_SHAPE;
        }
        for (k = 0; st == OTI_OK && k < res.ndim; k++){
            st = res.shape[k] == o.shape[k] ? OTI_OK : OTI_ERR_SHAPE;
        }
        if (st != OTI_OK){
            (void)otif_fail(st, "otif_run_into", "output shape differs from the result shape");
        } else {
            st = nd_assign(&ctx, &res, &o);
        }
    }
    nd_release(&res);

    return otif_mirror_error(&ctx, st);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Fortran-callable form of oti_fortran_wrap (one C name per interface): nd is type(ndarr_t).
int otif_borrow(const CFI_cdesc_t* a, int32_t writeable, ndarr_t* nd){

    return oti_fortran_wrap(a, writeable, nd);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Size of the shim's structures as compiled, for the module's self-check: info(1) sizeof(ndarr_t),
// info(2) sizeof(otif_req_t), info(3) OTIF_REQ_WORDS, info(4) CFI_MAX_RANK, info(5) CFI_type_double.
void otif_layout_info(int64_t* info){

    info[0] = (int64_t)sizeof(ndarr_t);
    info[1] = (int64_t)sizeof(otif_req_t);
    info[2] = OTIF_REQ_WORDS;
    info[3] = CFI_MAX_RANK;
    info[4] = (int64_t)CFI_type_double;

}
// -------------------------------------------------------------------------------------------------------
