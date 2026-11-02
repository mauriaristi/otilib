// Validator checks of the Fortran shim on hand-built descriptors (src/fortran/ndarray/tests). Compiled
// per vendor like the shim; called from test_nd_shim_c.f90 through otif_test_shim_c(). Builds the
// descriptors that a conforming Fortran program cannot produce (rank 16, wrong type or elem_len,
// packed or misaligned strides, assumed size, flang's zero-size dims) and checks every status.

#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include "oti_fortran_shim.h"

// Entry points of the shim used here (not in oti_fortran_shim.h: the module's private interface).
int otif_run(const void* req, CFI_cdesc_t* r, int32_t layout, int32_t nthreads);
int otif_run_into(const void* req, CFI_cdesc_t* out, int32_t nthreads);
int otif_make_ctx(int32_t nthreads, oti_ctx* ctx);
int otif_prep_unary(void* req, int32_t fn, const CFI_cdesc_t* a);

static int g_fail = 0;
static int g_verbose = 1;


// *******************************************************************************************************
static void ck(int cond, const char* what){

    if (!cond){
        g_fail++;
    }
    if (g_verbose || !cond){
        printf("  %s %s\n", cond ? "PASS" : "FAIL", what);
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Status of oti_fortran_wrap, checking that a failure is recorded as the last error with its name.
static int wrap_status(const CFI_cdesc_t* d, int32_t writeable, ndarr_t* nd){

    const char* where = NULL;
    int st;

    oti_ctx_clear_error(NULL);
    st = oti_fortran_wrap(d, writeable, nd);
    if (st != OTI_OK){
        ck(oti_ctx_last_error(NULL, &where, NULL) == st && where != NULL &&
           strcmp(where, "oti_fortran_wrap") == 0, "  failure recorded as last error");
    }

    return st;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int otif_test_shim_c(int verbose){

    static double buf[64];
    double x0 = 3.5;
    CFI_CDESC_T(OTI_FORTRAN_MAXRANK) storage;
    CFI_CDESC_T(16) storage16;
    CFI_cdesc_t* d = (CFI_cdesc_t*)&storage;
    CFI_cdesc_t* d16 = (CFI_cdesc_t*)&storage16;
    CFI_index_t ext[16];
    int64_t req[192];
    ndarr_t nd;
    int k, st;

    g_fail = 0;
    g_verbose = verbose;
    for (k = 0; k < 64; k++){
        buf[k] = (double)k;
    }
    for (k = 0; k < 16; k++){
        ext[k] = 1;
    }
    nd_init_empty(&nd);

    // A plain rank-2 array: Fortran strides, no copy, F contiguous.
    ext[0] = 3;
    ext[1] = 4;
    st = CFI_establish(d, buf, CFI_attribute_other, CFI_type_double, sizeof(double), 2, ext);
    ck(st == CFI_SUCCESS, "CFI_establish rank 2");
    st = wrap_status(d, 0, &nd);
    ck(st == OTI_OK && nd.ndim == 2 && nd.shape[0] == 3 && nd.shape[1] == 4 && nd.strides[0] == 1 &&
       nd.strides[1] == 3 && nd.data == (void*)buf && nd.buf == NULL, "rank 2 wraps without a copy");
    ck((nd.flags & ND_F_CONTIG) && !(nd.flags & ND_WRITEABLE), "rank 2 is F contiguous, read-only");
    ck(oti_fortran_is_contiguous(d) == 1, "own contiguity: compact rank 2");
    st = wrap_status(d, 1, &nd);
    ck(st == OTI_OK && (nd.flags & ND_WRITEABLE), "writeable wrap sets ND_WRITEABLE");

    // Strided and reversed (negative sm): element strides, data at the first element.
    d->dim[1].sm = 2 * 3 * (CFI_index_t)sizeof(double);
    d->dim[1].extent = 2;
    ck(oti_fortran_is_contiguous(d) == 0, "own contiguity: strided dim 2");
    d->dim[0].sm = -(CFI_index_t)sizeof(double);
    d->base_addr = &buf[2];
    st = wrap_status(d, 0, &nd);
    ck(st == OTI_OK && nd.strides[0] == -1 && nd.strides[1] == 6 && nd.data == (void*)&buf[2],
       "reversed and strided dims give strides (-1, 6)");
    ck(st == OTI_OK && ((double*)nd.data)[nd.strides[0] * 2 + nd.strides[1]] == 6.0,
       "element (2, 1) of the reversed view reads buf[6]");

    // Rank 0: the address of the scalar, contiguous.
    st = CFI_establish(d, &x0, CFI_attribute_other, CFI_type_double, sizeof(double), 0, NULL);
    st = st == CFI_SUCCESS ? wrap_status(d, 0, &nd) : st;
    ck(st == OTI_OK && nd.ndim == 0 && nd.data == (void*)&x0, "rank 0 wraps the scalar's address");
    ck(oti_fortran_is_contiguous(d) == 1, "own contiguity: rank 0 (no CFI_is_contiguous call)");

    // Rank 15 accepted, rank 16 rejected (CFI_establish(16) is not trusted: set the rank by hand).
    st = CFI_establish(d16, buf, CFI_attribute_other, CFI_type_double, sizeof(double), 15, ext);
    st = st == CFI_SUCCESS ? wrap_status(d16, 0, &nd) : st;
    ck(st == OTI_OK && nd.ndim == 15 && nd.shape[0] == 3 && nd.shape[1] == 4, "rank 15 accepted");
    d16->rank = 16;
    d16->dim[15].lower_bound = 0;
    d16->dim[15].extent = 1;
    d16->dim[15].sm = (CFI_index_t)sizeof(double);
    ck(wrap_status(d16, 0, &nd) == OTI_ERR_SHAPE, "rank 16 rejected (OTI_ERR_SHAPE)");
    ck(oti_fortran_is_contiguous(d16) == OTI_ERR_ARGUMENT, "own contiguity: rank 16 rejected");

    // Type and elem_len.
    ext[0] = 4;
    st = CFI_establish(d, buf, CFI_attribute_other, CFI_type_float, sizeof(float), 1, ext);
    ck(st == CFI_SUCCESS && wrap_status(d, 0, &nd) == OTI_ERR_DTYPE, "real(c_float) rejected");
    st = CFI_establish(d, buf, CFI_attribute_other, CFI_type_double, sizeof(double), 1, ext);
    d->elem_len = 4;
    ck(st == CFI_SUCCESS && wrap_status(d, 0, &nd) == OTI_ERR_DTYPE, "elem_len 4 rejected");

    // Attribute.
    st = CFI_establish(d, buf, CFI_attribute_other, CFI_type_double, sizeof(double), 1, ext);
    d->attribute = 77;
    ck(st == CFI_SUCCESS && wrap_status(d, 0, &nd) == OTI_ERR_ARGUMENT, "unknown attribute rejected");
    st = CFI_establish(d, NULL, CFI_attribute_allocatable, CFI_type_double, sizeof(double), 1, NULL);
    ck(st == CFI_SUCCESS && wrap_status(d, 0, &nd) == OTI_ERR_ARGUMENT,
       "unallocated allocatable rejected");
    st = CFI_establish(d, buf, CFI_attribute_pointer, CFI_type_double, sizeof(double), 1, ext);
    st = st == CFI_SUCCESS ? wrap_status(d, 0, &nd) : st;
    ck(st == OTI_OK && nd.shape[0] == 4, "associated pointer accepted");

    // Assumed size, packed stride, misaligned base.
    st = CFI_establish(d, buf, CFI_attribute_other, CFI_type_double, sizeof(double), 1, ext);
    d->dim[0].extent = -1;
    ck(st == CFI_SUCCESS && wrap_status(d, 0, &nd) == OTI_ERR_SHAPE, "assumed size (extent -1) rejected");
    d->dim[0].extent = 3;
    d->dim[0].sm = 12;
    ck(wrap_status(d, 0, &nd) == OTI_ERR_LAYOUT, "sm = 12 (packed component) rejected");
    d->dim[0].sm = 8;
    d->base_addr = (char*)buf + 4;
    ck(wrap_status(d, 0, &nd) == OTI_ERR_LAYOUT, "misaligned base_addr rejected");

    // Size 0 first: flang's lower_bound 1 and sm 0, and a nonsense sm, give a compact empty array.
    ext[0] = 3;
    ext[1] = 0;
    st = CFI_establish(d, buf, CFI_attribute_other, CFI_type_double, sizeof(double), 2, ext);
    d->dim[0].sm = 0;
    d->dim[1].lower_bound = 1;
    d->dim[1].sm = 12;
    d->base_addr = (char*)buf + 4;
    st = st == CFI_SUCCESS ? wrap_status(d, 0, &nd) : st;
    ck(st == OTI_OK && nd.ndim == 2 && nd.shape[0] == 3 && nd.shape[1] == 0 && nd.data == NULL,
       "zero-size array: no stride or alignment logic, data NULL");
    ck(oti_fortran_is_contiguous(d) == 1, "own contiguity: size 0");

    // The run entry points reject wrong result descriptors and unprepared requests.
    ext[0] = 4;
    memset(req, 0, sizeof(req));
    st = CFI_establish(d, buf, CFI_attribute_other, CFI_type_double, sizeof(double), 1, ext);
    ck(st == CFI_SUCCESS && otif_run(req, d, 0, 0) == OTI_ERR_ARGUMENT, "otif_run: unprepared request");
    ck(otif_prep_unary(req, ND_FN_SQRT, d) == OTI_OK, "otif_prep_unary on a plain array");
    ck(otif_run(req, d, 0, 0) == OTI_ERR_ARGUMENT, "otif_run: result not allocatable");
    ck(otif_run(req, d, 7, 0) == OTI_ERR_ARGUMENT, "otif_run: unknown layout");
    // An allocated allocatable: established unallocated (CFI_establish needs NULL), then filled by hand.
    st = CFI_establish(d16, NULL, CFI_attribute_allocatable, CFI_type_double, sizeof(double), 1, NULL);
    ck(st == CFI_SUCCESS, "CFI_establish of an unallocated allocatable");
    d16->base_addr = buf;
    d16->dim[0].lower_bound = 1;
    d16->dim[0].extent = 4;
    d16->dim[0].sm = (CFI_index_t)sizeof(double);
    ck(otif_run(req, d16, 0, 0) == OTI_ERR_ARGUMENT, "otif_run: result already allocated");
    ck(otif_run_into(req, d, 0) == OTI_OK && buf[2] == 1.4142135623730951 && buf[3] == 1.7320508075688772,
       "otif_run_into: in-place sqrt");
    ck(otif_prep_unary(req, ND_FN_SQRT, d16) == OTI_ERR_ARGUMENT, "otif_prep: input not attribute other");
    ck(otif_run(req, d16, 0, 0) == OTI_ERR_ARGUMENT, "a failed prep leaves the request unusable");

    // Hostile extents (checker W2 finding 7): checked products before any stride; nothing allocated.
    ext[0] = 0;
    ext[1] = (CFI_index_t)1 << 32;
    ext[2] = (CFI_index_t)1 << 32;
    st = CFI_establish(d, buf, CFI_attribute_other, CFI_type_double, sizeof(double), 3, ext);
    ck(st == CFI_SUCCESS && wrap_status(d, 0, &nd) == OTI_ERR_SIZE,
       "empty (0, 2^32, 2^32): extent product overflows -> OTI_ERR_SIZE");
    ext[0] = (CFI_index_t)1 << 31;
    ext[1] = (CFI_index_t)1 << 31;
    st = CFI_establish(d, buf, CFI_attribute_other, CFI_type_double, sizeof(double), 2, ext);
    d->dim[0].sm = 8;
    d->dim[1].sm = 8;
    ck(st == CFI_SUCCESS && wrap_status(d, 0, &nd) == OTI_ERR_SIZE,
       "(2^31, 2^31): 2^62 elements fit, 2^65 bytes do not -> OTI_ERR_SIZE");
    ck(otif_prep_unary(req, ND_FN_SQRT, d) == OTI_ERR_SIZE, "otif_prep rejects it too");
    d->dim[1].sm = (CFI_index_t)8 << 31;
    ck(oti_fortran_is_contiguous(d) == 1, "own contiguity: (2^31, 2^31) compact, no overflow");
    d->dim[0].extent = (CFI_index_t)1 << 61;
    d->dim[1].extent = 4;
    ck(oti_fortran_is_contiguous(d) == OTI_ERR_SIZE,
       "own contiguity: 8 * 2^61 overflows -> OTI_ERR_SIZE");
    d->dim[0].extent = 4;
    d->dim[0].sm = 8;
    d->dim[1].extent = (CFI_index_t)1 << 61;
    d->dim[1].sm = 32;
    ck(oti_fortran_is_contiguous(d) == 1, "own contiguity: the last extent's product is never formed");
    d->dim[1].extent = -1;
    ck(oti_fortran_is_contiguous(d) == OTI_ERR_SHAPE, "own contiguity: negative extent");

    // The call context (contracts S29): nthreads 0 inherits, 1 is serial, < 0 is rejected.
    {
        oti_ctx ctx;
        ck(otif_make_ctx(1, &ctx) == OTI_OK && ctx.exec.nthreads == 1 && oti_ctx_check(&ctx) == OTI_OK &&
           oti_exec_max_workers(&ctx) == 1, "otif_make_ctx(1): a valid serial context");
        ck(otif_make_ctx(0, &ctx) == OTI_OK && ctx.exec.nthreads == 0 && ctx.max_alloc_bytes == 0,
           "otif_make_ctx(0): inherit, default budgets");
        ck(otif_make_ctx(-2, &ctx) == OTI_ERR_ARGUMENT, "otif_make_ctx(-2): OTI_ERR_ARGUMENT");
    }

    // A core failure inside the call's user context reaches the thread's record (nd_last_error()).
    {
        const char* where = NULL;
        CFI_CDESC_T(1) small;
        CFI_cdesc_t* ds = (CFI_cdesc_t*)&small;

        ext[0] = 3;
        st = CFI_establish(ds, buf, CFI_attribute_other, CFI_type_double, sizeof(double), 1, ext);
        ext[0] = 4;
        st = st == CFI_SUCCESS
             ? CFI_establish(d, &buf[8], CFI_attribute_other, CFI_type_double, sizeof(double), 1, ext)
             : st;
        ck(st == CFI_SUCCESS && otif_prep_unary(req, ND_FN_SQRT, ds) == OTI_OK,
           "prep sqrt of 3 elements");
        oti_ctx_clear_error(NULL);
        ck(otif_run_into(req, d, 1) == OTI_ERR_SHAPE &&
           oti_ctx_last_error(NULL, &where, NULL) == OTI_ERR_SHAPE && where != NULL &&
           strcmp(where, "nd_unary_to") == 0, "core failure in a user context mirrored as nd_unary_to");
    }

    nd_init_empty(&nd);
    oti_ctx_clear_error(NULL);

    return g_fail;

}
// -------------------------------------------------------------------------------------------------------
