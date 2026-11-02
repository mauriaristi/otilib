// Zero-copy adapters between the legacy darr_t and ndarr_t (include/oti/real/ndarray/compat_darr.h;
// PLAN-ndarray.md Phase 6a). Included last from src/c/real_ndarray.c; uses buffer.c's ndb_wrap,
// ndb_contig_strides and checked arithmetic. File-static prefix: ndd_.

#include <stdlib.h>
#include <string.h>

#include "oti/real/ndarray/compat_darr.h"


// *******************************************************************************************************
// Release callback of ND_DARR_TAKE: the darr_t memory came from malloc (darr_t's allocator).
static void ndd_free(void* p){

    free(p);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Builds the temporary C-contiguous descriptor of a darr_t (no reference). Checks the darr_t fields.
static int ndd_describe(const darr_t* src, ndarr_t* d){

    int64_t shape[2], strides[2], size, bytes;
    int st;

    if (src->nrows > (uint64_t)INT64_MAX || src->ncols > (uint64_t)INT64_MAX){
        return OTI_ERR_SIZE;
    }
    shape[0] = (int64_t)src->nrows;
    shape[1] = (int64_t)src->ncols;
    if (oti_ckd_mul_i64(shape[0], shape[1], &size) || oti_ckd_mul_i64(size, 8, &bytes)){
        return OTI_ERR_SIZE;
    }
    if (src->size != (uint64_t)size || (size > 0 && src->p_data == NULL)){
        return OTI_ERR_ARGUMENT;
    }
    st = ndb_contig_strides(2, shape, ND_LAYOUT_C, strides);
    if (st != OTI_OK){
        return st;
    }

    return ndb_wrap_trusted(size > 0 ? (void*)src->p_data : NULL, OTI_F64, 2, shape, strides, 1, d);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// nd_from_darr() without last-error recording.
static int ndd_from_darr(oti_ctx* ctx, darr_t* src, int32_t mode, ndarr_t* out){

    nd_release_fn release = NULL;
    void* mem = NULL;
    int64_t nbytes = -1;
    ndarr_t d;
    int st;

    if (out == NULL || src == NULL ||
        (mode != ND_DARR_BORROW && mode != ND_DARR_RETAIN && mode != ND_DARR_TAKE)){
        if (out != NULL){
            NDB_ASSERT_RECV(out);
            nd_init_empty(out);
        }
        return OTI_ERR_ARGUMENT;
    }
    NDB_ASSERT_RECV(out);
    nd_init_empty(out);
    if (mode == ND_DARR_TAKE){
        // Ownership passes on entry (contracts 1.5): src is emptied whatever happens next, and the
        // memory is freed exactly once (by the buffer, or here / by ndb_wrap on failure).
        mem = (void*)src->p_data;
        release = (mem != NULL) ? ndd_free : NULL;
        nd_init_empty(&d);
        st = ndd_describe(src, &d);
        src->p_data = NULL;
        src->nrows = 0;
        src->ncols = 0;
        src->size = 0;
        if (st == OTI_OK){
            st = oti_ctx_check(ctx);
        }
        if (st != OTI_OK){
            if (release != NULL){
                release(mem);
            }
            return st;
        }
    } else {
        nd_init_empty(&d);
        st = ndd_describe(src, &d);
        if (st != OTI_OK){
            return st;
        }
        if (mode == ND_DARR_BORROW){
            *out = d;
            return OTI_OK;
        }
        st = oti_ctx_check(ctx);
        if (st != OTI_OK){
            return st;
        }
    }
    // RETAIN / TAKE: a control block over the span [p_data, p_data + 8*size) when there is one.
    if (d.data != NULL){
        nbytes = nd_size(&d) * 8;
    }

    return ndb_wrap(&d, d.data, d.data != NULL ? nbytes : -1, release, mem, out);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int nd_from_darr(oti_ctx* ctx, darr_t* src, int32_t mode, ndarr_t* out){

    int st = ndd_from_darr(ctx, src, mode, out);

    if (st != OTI_OK){
        oti_ctx_set_error(ctx, st, "nd_from_darr", NULL);
    }

    return st;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int nd_as_darr(const ndarr_t* a, int32_t writeable, darr_t* out){

    int64_t nrows, ncols;
    ndarr_t t;
    int st = OTI_OK;

    if (out != NULL){
        out->p_data = NULL;
        out->nrows = 0;
        out->ncols = 0;
        out->size = 0;
    }
    if (a == NULL || out == NULL){
        st = OTI_ERR_ARGUMENT;
    } else {
        NDB_ASSERT_INPUT(a);
        t = *a;
        nd_update_flags(&t);
        if (a->dtype != OTI_F64){
            st = OTI_ERR_DTYPE;
        } else if (a->ndim > 2){
            st = OTI_ERR_SHAPE;
        } else if (!(t.flags & ND_C_CONTIG)){
            st = OTI_ERR_LAYOUT;
        } else if (writeable && !(a->flags & ND_WRITEABLE)){
            st = OTI_ERR_READONLY;
        }
    }
    if (st != OTI_OK){
        oti_ctx_set_error(NULL, st, "nd_as_darr", NULL);
        return st;
    }
    nrows = (a->ndim == 2) ? a->shape[0] : 1;
    ncols = (a->ndim == 2) ? a->shape[1] : (a->ndim == 1) ? a->shape[0] : 1;
    out->p_data = (coeff_t*)a->data;
    out->nrows = (uint64_t)nrows;
    out->ncols = (uint64_t)ncols;
    out->size = (uint64_t)(nrows * ncols);

    return OTI_OK;

}
// -------------------------------------------------------------------------------------------------------
