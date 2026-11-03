// pthread / POSIX declarations under the Release build's -std=c99 on glibc (contracts S23, the 1.3.1
// pattern of src/c/dense.c). Not defined on Apple, where _POSIX_C_SOURCE would instead hide
// non-POSIX declarations.
#if !defined(__APPLE__) && !defined(_POSIX_C_SOURCE)
#define _POSIX_C_SOURCE 200809L
#endif

#include "oti/core/meta.h"

// OTI layout metadata (Phase 7a; PLAN-ndarray-contracts.md section 7, include/oti/core/meta.h). Its own
// translation unit, compiled with the options of src/c/core/exec.c.
//
// File-static helpers carry the om_ prefix. refs uses the __atomic_* builtins on a plain int64_t
// (decision S9). The other fields change only inside a layout transaction or through the act
// functions; concurrent mutation of one array from several host threads is not supported (contracts
// 1.7), so they are plain loads and stores.

#include <stdlib.h>
#include <string.h>

#include "oti/real/ndarray/buffer.h"

#ifdef OTI_ND_DEBUG
#include <assert.h>
#define OM_ASSERT(c) assert(c)
#else
#define OM_ASSERT(c) ((void)0)
#endif

// Largest layout base count: dense nact and the labels are bases_t.
#define OM_MAX_BASES 65535

// Countdown of oti_meta_test_fail_alloc(); 0 = disabled.
static int64_t om_fail_countdown = 0;


// *******************************************************************************************************
void oti_meta_test_fail_alloc(int64_t countdown){

    __atomic_store_n(&om_fail_countdown, countdown > 0 ? countdown : 0, __ATOMIC_RELAXED);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// malloc through the failure injection (oti_meta_test_fail_alloc()). One relaxed load when off.
static void* om_malloc(size_t nbytes){

    int64_t c = __atomic_load_n(&om_fail_countdown, __ATOMIC_RELAXED);

    while (c > 0){
        if (__atomic_compare_exchange_n(&om_fail_countdown, &c, c - 1, 1, __ATOMIC_RELAXED,
                                        __ATOMIC_RELAXED)){
            if (c == 1){
                return NULL;
            }
            break;
        }
    }

    return malloc(nbytes > 0 ? nbytes : 1);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// OTI_OK when labels[0 .. n-1] are strictly increasing (sorted and distinct), else OTI_ERR_ARGUMENT.
static int om_check_labels(const bases_t* labels, int32_t n){

    int32_t i;

    if (n > 0 && labels == NULL){
        return OTI_ERR_ARGUMENT;
    }

    for (i = 1; i < n; i++){
        if (labels[i] <= labels[i - 1]){
            return OTI_ERR_ARGUMENT;
        }
    }

    return OTI_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Checks the layout arguments shared by oti_meta_create() and oti_meta_relayout().
static int om_check_layout(int32_t kind, int32_t trc_order, int32_t nbases, const bases_t* bases){

    if (kind != OTI_META_DENSE && kind != OTI_META_BASES){
        return OTI_ERR_ARGUMENT;
    }
    if (trc_order < 0 || trc_order > _MAXORDER_OTI){
        return OTI_ERR_INDEX;
    }
    if (nbases < 0 || nbases > OM_MAX_BASES){
        return OTI_ERR_ARGUMENT;
    }
    if (kind == OTI_META_DENSE){
        return (bases == NULL) ? OTI_OK : OTI_ERR_ARGUMENT;
    }

    return om_check_labels(bases, nbases);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Allocates the labels arrays of a capacity (at least one entry each); OTI_ERR_MEMORY leaves both NULL.
static int om_alloc_labels(int32_t cap, bases_t** p_bases, int64_t** p_i64){

    size_t n = (cap > 0) ? (size_t)cap : 1;

    *p_bases = (bases_t*)om_malloc(n * sizeof(bases_t));
    *p_i64   = (*p_bases != NULL) ? (int64_t*)om_malloc(n * sizeof(int64_t)) : NULL;

    if (*p_i64 == NULL){
        free(*p_bases);
        *p_bases = NULL;
        return OTI_ERR_MEMORY;
    }

    return OTI_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Copies n labels (memmove: src may be the meta's own array) and rebuilds their int64 copy.
static void om_store_labels(oti_meta_t* m, const bases_t* src, int32_t n){

    int32_t i;

    if (n > 0){
        memmove(m->bases, src, (size_t)n * sizeof(bases_t));
    }
    for (i = 0; i < n; i++){
        m->bases_i64[i] = (int64_t)m->bases[i];
    }

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// ---------------------------------     LIFETIME AND REFCOUNTING     ------------------------------------
// -------------------------------------------------------------------------------------------------------

// *******************************************************************************************************
int oti_meta_create(int32_t kind, int32_t trc_order, int32_t nbases, const bases_t* bases,
                    int32_t cap_bases, oti_meta_t** res){

    oti_meta_t* m;
    int st;

    if (res == NULL){
        return OTI_ERR_ARGUMENT;
    }
    *res = NULL;

    st = om_check_layout(kind, trc_order, nbases, bases);
    if (st != OTI_OK){
        return st;
    }
    if (kind == OTI_META_BASES && (cap_bases < nbases || cap_bases > OM_MAX_BASES)){
        return OTI_ERR_ARGUMENT;
    }

    m = (oti_meta_t*)om_malloc(sizeof(oti_meta_t));
    if (m == NULL){
        return OTI_ERR_MEMORY;
    }

    m->refs      = 1;
    m->kind      = kind;
    m->trc_order = trc_order;
    m->act_order = 0;
    m->nbases    = nbases;
    m->cap_bases = 0;
    m->reserved  = 0;
    m->bases     = NULL;
    m->bases_i64 = NULL;

    if (kind == OTI_META_BASES){

        if (om_alloc_labels(cap_bases, &m->bases, &m->bases_i64) != OTI_OK){
            free(m);
            return OTI_ERR_MEMORY;
        }
        m->cap_bases = cap_bases;
        om_store_labels(m, bases, nbases);

    }

    *res = m;

    return OTI_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
oti_meta_t* oti_meta_retain(oti_meta_t* m){

    OM_ASSERT(m != NULL && __atomic_load_n(&m->refs, __ATOMIC_RELAXED) > 0);
    __atomic_fetch_add(&m->refs, 1, __ATOMIC_RELAXED);

    return m;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void oti_meta_release(oti_meta_t** m){

    oti_meta_t* p;

    if (m == NULL || *m == NULL){
        return;
    }
    p  = *m;
    *m = NULL;

    OM_ASSERT(__atomic_load_n(&p->refs, __ATOMIC_RELAXED) > 0);
    if (__atomic_sub_fetch(&p->refs, 1, __ATOMIC_ACQ_REL) == 0){
        free(p->bases);
        free(p->bases_i64);
        free(p);
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oti_meta_shared(const oti_meta_t* m){

    return __atomic_load_n(&m->refs, __ATOMIC_ACQUIRE) > 1;

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// ---------------------------------     LAYOUT TRANSACTIONS     -----------------------------------------
// -------------------------------------------------------------------------------------------------------

// *******************************************************************************************************
int oti_meta_layout_begin(oti_meta_t* m, nd_buffer_t* buf){

    if (m == NULL || buf == NULL){
        return OTI_ERR_ARGUMENT;
    }
    if (__atomic_load_n(&m->refs, __ATOMIC_ACQUIRE) != 1){
        return OTI_ERR_BUSY;
    }

    return nd_buffer_lock_layout(buf);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oti_meta_relayout(oti_meta_t* m, int32_t trc_order, int32_t nbases, const bases_t* bases){

    int st;

    if (m == NULL){
        return OTI_ERR_ARGUMENT;
    }
    OM_ASSERT(__atomic_load_n(&m->refs, __ATOMIC_RELAXED) == 1);

    st = om_check_layout(m->kind, trc_order, nbases, bases);
    if (st != OTI_OK){
        return st;
    }

    if (m->kind == OTI_META_BASES){

        if (nbases > m->cap_bases){

            // New arrays first, so that a failure leaves the fields unchanged and `bases` may point
            // into the old labels.
            bases_t* nb;
            int64_t* ni;

            if (om_alloc_labels(nbases, &nb, &ni) != OTI_OK){
                return OTI_ERR_MEMORY;
            }
            if (nbases > 0){
                memcpy(nb, bases, (size_t)nbases * sizeof(bases_t));
            }
            free(m->bases);
            free(m->bases_i64);
            m->bases     = nb;
            m->bases_i64 = ni;
            m->cap_bases = nbases;
            om_store_labels(m, m->bases, nbases);

        } else {

            om_store_labels(m, bases, nbases);

        }

    }

    m->trc_order = trc_order;
    m->nbases    = nbases;
    if (m->act_order > trc_order){
        m->act_order = trc_order;
    }

    return OTI_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void oti_meta_layout_end(oti_meta_t* m, nd_buffer_t* buf){

    (void)m;

    if (buf != NULL){
        nd_buffer_unlock_layout(buf);
    }

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// ---------------------------------     ACTIVE ORDER AND FIT     ----------------------------------------
// -------------------------------------------------------------------------------------------------------

// *******************************************************************************************************
void oti_meta_raise_act(oti_meta_t* m, int32_t act){

    if (act > m->trc_order){
        act = m->trc_order;
    }
    if (act > m->act_order){
        m->act_order = act;
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void oti_meta_set_act(oti_meta_t* m, int32_t act){

    OM_ASSERT(__atomic_load_n(&m->refs, __ATOMIC_RELAXED) == 1);

    if (act > m->trc_order){
        act = m->trc_order;
    }
    m->act_order = (act > 0) ? act : 0;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Label i of a layout: labels[i] when given, else i + 1 (dense: bases 1..n).
static inline int64_t om_label(const bases_t* labels, int32_t i){

    return (labels != NULL) ? (int64_t)labels[i] : (int64_t)i + 1;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oti_meta_fits(const oti_meta_t* m, int32_t trc, int32_t nbases, const bases_t* bases){

    const bases_t* mb = (m->kind == OTI_META_BASES) ? m->bases : NULL;
    int32_t i = 0, j = 0;

    if (trc < 0 || nbases < 0 || trc > m->trc_order){
        return 0;
    }
    if (nbases == 0){
        return 1;
    }
    if (mb == NULL && bases == NULL){
        return nbases <= m->nbases;
    }
    if (mb == NULL){
        // Labels into bases 1..m->nbases: the sorted labels fit when the largest does.
        return bases[0] >= 1 && (int64_t)bases[nbases - 1] <= (int64_t)m->nbases;
    }

    // Sorted merge: every label of the value must be one of the meta's.
    while (i < nbases){

        int64_t v = om_label(bases, i);

        while (j < m->nbases && (int64_t)mb[j] < v){
            j++;
        }
        if (j == m->nbases || (int64_t)mb[j] != v){
            return 0;
        }
        i++;
        j++;

    }

    return 1;

}
// -------------------------------------------------------------------------------------------------------
