// dladdr() / Dl_info under the Release build's -std=c99 on glibc (contracts S23): _GNU_SOURCE, not
// _POSIX_C_SOURCE, before any system header. Not defined on Apple.
#if !defined(__APPLE__) && !defined(_GNU_SOURCE)
#define _GNU_SOURCE
#endif

// The LAPACK / BLAS provider table, its one-time capability probe and the BLAS thread scopes
// (Phase 3; PLAN-ndarray-contracts.md 8.3, 8.4, 5.5; decisions S10, S11, S18).
//
// The default table stores the addresses of the routines linked at build time: name_ for every vendor
// but Accelerate, name$NEWLAPACK for Accelerate (lapack_config.h, written by CMake, says which). These
// declarations exist only in this file and are never called through their declared type; the
// wrappers in lapack.c cast each slot to its exact prototype. The probe then locates the image of
// dgemm with dladdr() and reads the optional thread-control symbols from it (dlopen(RTLD_NOLOAD) +
// dlsym(), RTLD_DEFAULT as fallback), because dlsym(RTLD_DEFAULT) misses libraries loaded
// RTLD_LOCAL, which is how Python loads extension modules.
//
// Capability symbols count only when they live in the provider's own image (the image of its dgemm;
// for Accelerate, anywhere inside Accelerate.framework): a symbol of another, independently loaded
// library found through RTLD_DEFAULT never sets a bit (checker W2 finding 5). The contention probe
// (S28) times small dgemm calls from a parallel region once per provider table.
//
// File-static helpers carry the olp_ prefix. The current-table pointer is published with a release
// store and read with an acquire load (S9); oti_blas_caps() is one acquire load of the once-probed
// table, never a probe per loop (critic W1 finding 9.2).

#include <dlfcn.h>
#include <limits.h>
#include <pthread.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#if defined(OTI_PARALLEL_OPENMP)
#include <omp.h>
#endif

#include "oti/core/exec.h"
#include "oti/core/lapack.h"
#include "oti/core/lapack_config.h"

#if !defined(OTI_LAPACK_VENDOR) || !defined(OTI_LAPACK_STRLEN)
#error "oti/core/lapack_config.h must define OTI_LAPACK_VENDOR and OTI_LAPACK_STRLEN"
#endif

// The routines of the default table, tier 1 then tier 2 (slot names of oti_lapack_provider_t).
#define OLP_ROUTINES(X)                                                                           \
    X(dgetrf) X(dgetrs) X(dtrsm) X(dtrmm) X(dgemm) X(ddot) X(daxpy) X(dscal) X(dnrm2) X(dcopy)    \
    X(dswap) X(dasum) X(idamax) X(dgemv) X(dger) X(dsyrk) X(dgesv) X(dgetri) X(dpotrf) X(dpotrs)  \
    X(dtrtrs) X(dgeqrf) X(dorgqr) X(dgelsd) X(dsyevd) X(dgeev) X(dgesdd)

#if OTI_LAPACK_VENDOR == OTI_LAPACK_VENDOR_ACCELERATE
#define OLP_DECLARE(name) extern void olp_sym_##name(void) __asm("_" #name "$NEWLAPACK");
#define OLP_ADDRESS(name) t->name = (oti_lapack_fn)&olp_sym_##name;
#else
#define OLP_DECLARE(name) extern void name##_(void);
#define OLP_ADDRESS(name) t->name = (oti_lapack_fn)&name##_;
#endif

OLP_ROUTINES(OLP_DECLARE)

// Prototypes of the optional symbols, called only through these types.
typedef int (*olp_int_void_t)(void);
typedef int (*olp_set_local_t)(int);
typedef char* (*olp_config_t)(void);
typedef int (*olp_set_threading_t)(unsigned);
typedef unsigned (*olp_get_threading_t)(void);

static pthread_once_t olp_once = PTHREAD_ONCE_INIT;

// The default table (written once under olp_once), the host table, and the current one.
static oti_lapack_provider_t olp_default;
static oti_lapack_provider_t olp_host;
static const oti_lapack_provider_t* olp_current = NULL;

// Contention measurement of the default table (0) and the host table (1): state 0 = not measured,
// 2 = measured (value published by the release store of state). Measured under olp_cont_lock.
static int32_t         olp_cont_state[2] = { 0, 0 };
static double          olp_cont_value[2] = { 0.0, 0.0 };
static pthread_mutex_t olp_cont_lock = PTHREAD_MUTEX_INITIALIZER;


// *******************************************************************************************************
// Converts a function pointer to an object pointer for dladdr() (POSIX allows it; ISO C does not
// define the cast, so the bits are copied).
static inline void* olp_fn_to_ptr(oti_lapack_fn fn){

    void* p = NULL;

    if (sizeof(p) == sizeof(fn)){
        memcpy(&p, &fn, sizeof(p));
    }

    return p;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// The inverse of olp_fn_to_ptr(), for dlsym() results.
static inline oti_lapack_fn olp_ptr_to_fn(void* p){

    oti_lapack_fn fn = NULL;

    if (p != NULL && sizeof(p) == sizeof(fn)){
        memcpy(&fn, &p, sizeof(fn));
    }

    return fn;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// dlsym() in the provider's image first, then in the global scope.
static oti_lapack_fn olp_lookup(void* handle, const char* name){

    void* p = NULL;

    if (handle != NULL){
        p = dlsym(handle, name);
    }
    if (p == NULL){
        p = dlsym(RTLD_DEFAULT, name);
    }

    return olp_ptr_to_fn(p);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Image path of an address (dladdr), or NULL. The string may be dyld's or the loader's own storage:
// compare or copy it before the next dladdr call.
static const char* olp_image_of(void* addr){

    Dl_info info;

    if (addr == NULL){
        return NULL;
    }

    memset(&info, 0, sizeof(info));

    if (dladdr(addr, &info) == 0 || info.dli_fname == NULL){
        return NULL;
    }

    return info.dli_fname;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// 1 when an image path lies inside Accelerate (vecLib's libBLAS / libLAPACK are inside the framework).
static int olp_is_accelerate(const char* path){

    return path != NULL && (strstr(path, "Accelerate.framework") != NULL
                            || strstr(path, "vecLib.framework") != NULL);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// 1 when two image paths name the same image: equal strings, equal real paths (a symlinked stub such
// as conda's libblas -> libopenblas), or both inside Accelerate (one verified umbrella: dgemm$NEWLAPACK
// in libBLAS, BLASSetThreading in the same framework).
static int olp_same_image(const char* a, const char* b){

    char* ra;
    char* rb;
    int   same;

    if (a == NULL || b == NULL){
        return 0;
    }
    if (strcmp(a, b) == 0 || (olp_is_accelerate(a) && olp_is_accelerate(b))){
        return 1;
    }

    ra   = realpath(a, NULL);
    rb   = realpath(b, NULL);
    same = ra != NULL && rb != NULL && strcmp(ra, rb) == 0;
    free(ra);
    free(rb);

    return same;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// A capability symbol of the provider: looked up in its image (then globally), and kept only when it
// lies in the provider's own image `prov` (NULL: unknown, nothing is kept).
static oti_lapack_fn olp_lookup_own(void* handle, const char* prov, const char* name){

    oti_lapack_fn f = olp_lookup(handle, name);

    if (f == NULL || prov == NULL){
        return NULL;
    }

    return olp_same_image(olp_image_of(olp_fn_to_ptr(f)), prov) ? f : NULL;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Accelerate's per-thread BLASSetThreading / BLASGetThreading: kept only if a test call
// BLASSetThreading(BLASGetThreading()) returns 0 ([cL9]).
static int32_t olp_probe_accel_threading(oti_lapack_provider_t* t){

    olp_set_threading_t set;
    olp_get_threading_t get;

    if (t->blas_set_threading == NULL || t->blas_get_threading == NULL){
        t->blas_set_threading = NULL;
        t->blas_get_threading = NULL;
        return 0;
    }

    set = (olp_set_threading_t)t->blas_set_threading;
    get = (olp_get_threading_t)t->blas_get_threading;

    if (set(get()) != 0){
        t->blas_set_threading = NULL;
        t->blas_get_threading = NULL;
        return 0;
    }

    return OTI_BLAS_CAP_ACCEL_THREADING;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// OMP_NESTED (S18): an OpenMP-built OpenBLAS (openblas_get_parallel() == 2) whose omp_in_parallel
// resolves to the same image as liboti's own, in an OTI_PARALLEL_OPENMP build.
static int32_t olp_probe_omp_nested(void* handle){

#if defined(OTI_PARALLEL_OPENMP)
    oti_lapack_fn theirs = olp_lookup(handle, "omp_in_parallel");
    const char*   p_theirs;
    const char*   p_ours;
    char          ours[4096];
    int (*mine)(void) = &omp_in_parallel;

    if (handle == NULL || theirs == NULL){
        return 0;
    }

    // dladdr's dli_fname may point into storage reused by the next call: copy the first one.
    p_ours = olp_image_of(olp_fn_to_ptr((oti_lapack_fn)mine));

    if (p_ours == NULL || strlen(p_ours) >= sizeof(ours)){
        return 0;
    }

    memcpy(ours, p_ours, strlen(p_ours) + 1);
    p_theirs = olp_image_of(olp_fn_to_ptr(theirs));

    return (p_theirs != NULL && strcmp(ours, p_theirs) == 0) ? OTI_BLAS_CAP_OMP_NESTED : 0;
#else
    (void)handle;
    return 0;
#endif

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// The run-time probe of a table (8.3, 8.4): vendor and convention of an Accelerate image, then the
// optional capabilities and the name, each from the provider's own image only.
static void olp_probe(oti_lapack_provider_t* t){

    const char*    p0     = olp_image_of(olp_fn_to_ptr(t->dgemm));
    const char*    prov   = NULL;
    char           path[PATH_MAX + 1];
    void*          handle = NULL;
    oti_lapack_fn  f;
    int32_t        caps   = 0;

    t->set_threads_local  = NULL;
    t->blas_set_threading = NULL;
    t->blas_get_threading = NULL;

    // dli_fname is only valid until the next dladdr call: keep a copy.
    if (p0 != NULL && strlen(p0) < sizeof(path)){
        memcpy(path, p0, strlen(p0) + 1);
        prov = path;
    }

    if (olp_is_accelerate(prov)){
        t->vendor            = OTI_LAPACK_VENDOR_ACCELERATE;
        t->strlen_convention = OTI_STRLEN_NONE;
        t->name              = "Apple Accelerate ($NEWLAPACK)";
    }

    if (prov != NULL){
        handle = dlopen(prov, RTLD_LAZY | RTLD_NOLOAD);
    }

    // OpenBLAS: build type, name, local thread control (exported only by some builds).
    f = olp_lookup_own(handle, prov, "openblas_get_parallel");

    if (f != NULL){

        int par = ((olp_int_void_t)f)();

        if (t->vendor == OTI_LAPACK_VENDOR_GENERIC || t->vendor == OTI_LAPACK_VENDOR_UNKNOWN){
            t->vendor = OTI_LAPACK_VENDOR_OPENBLAS;
        }
        if (par == 0){
            caps |= OTI_BLAS_CAP_SERIAL_BUILD;
        } else if (par == 2){
            caps |= olp_probe_omp_nested(handle);
        }

    }

    f = olp_lookup_own(handle, prov, "openblas_get_config");

    if (f != NULL){
        const char* cfg = ((olp_config_t)f)();
        if (cfg != NULL){
            t->name = cfg;
        }
    }

    f = olp_lookup_own(handle, prov, "openblas_set_num_threads_local");

    if (f == NULL){
        f = olp_lookup_own(handle, prov, "mkl_set_num_threads_local");
    }
    if (f != NULL){
        t->set_threads_local = f;
        caps |= OTI_BLAS_CAP_LOCAL_THREADS;
    }

    // Accelerate (macOS >= 15).
    t->blas_set_threading = olp_lookup_own(handle, prov, "BLASSetThreading");
    t->blas_get_threading = olp_lookup_own(handle, prov, "BLASGetThreading");
    caps |= olp_probe_accel_threading(t);

    // BLIS (unverified: no BLIS on the development machine).
    f = olp_lookup_own(handle, prov, "bli_info_get_enable_threading");

    if (f != NULL && ((olp_int_void_t)f)() == 0){
        caps |= OTI_BLAS_CAP_SERIAL_BUILD;
    }

    if (handle != NULL){
        dlclose(handle);   // RTLD_NOLOAD took a reference on an image that stays loaded
    }

    t->caps = caps;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void oti_lapack_test_probe(oti_lapack_provider_t* t){

    if (t != NULL && t->dgemm != NULL){
        olp_probe(t);
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Builds and probes the default table, then publishes it (pthread_once).
static void olp_init(void){

    oti_lapack_provider_t* t = &olp_default;

    memset(t, 0, sizeof(*t));

    t->struct_size       = (int32_t)sizeof(*t);
    t->vendor            = OTI_LAPACK_VENDOR;
    t->int_size          = 4;
    t->strlen_convention = OTI_LAPACK_STRLEN;
    t->name              = OTI_LAPACK_VENDOR == OTI_LAPACK_VENDOR_ACCELERATE
                           ? "Apple Accelerate ($NEWLAPACK)"
                           : OTI_LAPACK_VENDOR == OTI_LAPACK_VENDOR_OPENBLAS ? "OpenBLAS"
                           : OTI_LAPACK_VENDOR == OTI_LAPACK_VENDOR_MKL ? "Intel oneMKL"
                           : OTI_LAPACK_VENDOR == OTI_LAPACK_VENDOR_BLIS ? "BLIS / libFLAME"
                           : "Fortran LAPACK";

    OLP_ROUTINES(OLP_ADDRESS)

    olp_probe(t);

    __atomic_store_n(&olp_current, (const oti_lapack_provider_t*)t, __ATOMIC_RELEASE);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
const oti_lapack_provider_t* oti_lapack_provider(void){

    const oti_lapack_provider_t* p = __atomic_load_n(&olp_current, __ATOMIC_ACQUIRE);

    if (p == NULL){
        pthread_once(&olp_once, olp_init);
        p = __atomic_load_n(&olp_current, __ATOMIC_ACQUIRE);
    }

    return p;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// 1 when every tier-1 slot of a table is set.
static int olp_has_required(const oti_lapack_provider_t* p){

    return p->dgetrf != NULL && p->dgetrs != NULL && p->dtrsm != NULL && p->dtrmm != NULL
           && p->dgemm != NULL && p->ddot != NULL && p->daxpy != NULL && p->dscal != NULL
           && p->dnrm2 != NULL && p->dcopy != NULL && p->dswap != NULL && p->dasum != NULL
           && p->idamax != NULL && p->dgemv != NULL && p->dger != NULL && p->dsyrk != NULL
           && p->dgesv != NULL && p->dgetri != NULL && p->dpotrf != NULL && p->dpotrs != NULL
           && p->dtrtrs != NULL;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oti_lapack_provider_set(const oti_lapack_provider_t* p){

    oti_lapack_provider_t* h = &olp_host;
    int32_t caps = 0;

    // The default table is built first, so that a later first use never replaces the host's table.
    (void)oti_lapack_provider();

    if (p == NULL){
        __atomic_store_n(&olp_current, (const oti_lapack_provider_t*)&olp_default, __ATOMIC_RELEASE);
        return OTI_OK;
    }

    if (p->struct_size < (int32_t)sizeof(oti_lapack_provider_t) || p->int_size != 4
        || (p->strlen_convention != OTI_STRLEN_NONE
            && p->strlen_convention != OTI_STRLEN_END_SIZE_T)
        || !olp_has_required(p)){
        oti_ctx_set_error(NULL, OTI_ERR_ARGUMENT, "oti_lapack_provider_set",
                          "struct_size, int_size, strlen_convention or a required slot is invalid");
        return OTI_ERR_ARGUMENT;
    }

    // Called only while no otilib call runs (contract), so the host slot may be rewritten in place.
    memcpy(h, p, sizeof(*h));
    h->struct_size = (int32_t)sizeof(*h);
    h->reserved0   = 0;

    if (h->name == NULL){
        h->name = "host provider";
    }
    if (h->set_threads_local != NULL){
        caps |= OTI_BLAS_CAP_LOCAL_THREADS;
    }

    caps |= olp_probe_accel_threading(h);
    h->caps = caps;

    // A new host table is measured again on its first parallel batch (S28).
    __atomic_store_n(&olp_cont_state[1], 0, __ATOMIC_RELEASE);

    __atomic_store_n(&olp_current, (const oti_lapack_provider_t*)h, __ATOMIC_RELEASE);

    return OTI_OK;

}
// -------------------------------------------------------------------------------------------------------


#if defined(OTI_PARALLEL_OPENMP)
#define OLP_PROBE_CALLS 256   // 8 x 8 dgemm calls per worker (about 25 us of work)

// *******************************************************************************************************
static double olp_median3(double a, double b, double c){

    if (a > b){ double t = a; a = b; b = t; }
    if (b > c){ double t = b; b = c; c = t; }
    if (a > b){ double t = a; a = b; b = t; }

    return b;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// OLP_PROBE_CALLS 8 x 8 dgemm calls on private operands; work is true inside the timed region.
static void olp_probe_calls(int work){

    double a[64], b[64], c[64];
    int i;

    for (i = 0; i < 64; i++){
        a[i] = 1.0 / (double)(1 + i);
        b[i] = (double)(i % 7) - 3.0;
    }

    for (i = 0; work && i < OLP_PROBE_CALLS; i++){
        oti_dgemm('N', 'N', 8, 8, 8, 1.0, a, 8, b, 8, 0.0, c, 8);
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// One timed region of T workers (each in its BLAS scope; work = 0: the empty region). Returns the
// wall time; *team the actual team size.
static double olp_probe_region(int T, int work, int* team){

    double t0 = omp_get_wtime();

    #pragma omp parallel num_threads(T)
    {
        oti_blas_scope_t sc;

        (void)oti_blas_scope_enter(&sc);
        olp_probe_calls(work);
        oti_blas_scope_exit(&sc);

        if (omp_get_thread_num() == 0){
            *team = omp_get_num_threads();
        }
    }

    return omp_get_wtime() - t0;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// The contention measurement of oti_blas_contention_ns() (documented in lapack.h).
static double olp_measure_contention(void){

    double s[3], e[3], w[3], t1, tT, cont;
    int T = omp_get_max_threads(), team = 1, i;

    if (T > 8){
        T = 8;
    }
    if (T < 2){
        return 0.0;
    }

    olp_probe_calls(1);                                  // warm-up

    for (i = 0; i < 3; i++){
        double t0 = omp_get_wtime();
        olp_probe_calls(1);
        s[i] = omp_get_wtime() - t0;
    }

    (void)olp_probe_region(T, 1, &team);                 // warm-up (wakes the team)

    for (i = 0; i < 3; i++){
        e[i] = olp_probe_region(T, 0, &team);
        w[i] = olp_probe_region(T, 1, &team);
    }

    if (team < 2){
        return 0.0;
    }

    t1 = olp_median3(s[0], s[1], s[2]) / OLP_PROBE_CALLS;
    tT = (olp_median3(w[0], w[1], w[2]) - olp_median3(e[0], e[1], e[2]))
         / ((double)OLP_PROBE_CALLS * (double)team);

    if (!(t1 > 0.0) || !(tT > 0.0)){
        return 0.0;
    }

    cont = (tT - t1 / (double)team) * 1e9;

    return cont > 0.0 ? cont : 0.0;

}
// -------------------------------------------------------------------------------------------------------
#endif


// *******************************************************************************************************
double oti_blas_contention_ns(void){

    const oti_lapack_provider_t* p = oti_lapack_provider();
    int slot = p == &olp_default ? 0 : 1;

    if (__atomic_load_n(&olp_cont_state[slot], __ATOMIC_ACQUIRE) == 2){
        return olp_cont_value[slot];
    }
    if (!(p->caps & (OTI_BLAS_CAP_LOCAL_CONTROL | OTI_BLAS_CAP_OMP_NESTED))){
        return 0.0;                                      // batch loops stay serial anyway
    }

#if defined(OTI_PARALLEL_OPENMP)
    if (oti_exec_in_parallel()){
        return 0.0;                                      // never measure inside a region
    }

    pthread_mutex_lock(&olp_cont_lock);

    if (__atomic_load_n(&olp_cont_state[slot], __ATOMIC_ACQUIRE) != 2){
        olp_cont_value[slot] = olp_measure_contention();
        __atomic_store_n(&olp_cont_state[slot], 2, __ATOMIC_RELEASE);
    }

    pthread_mutex_unlock(&olp_cont_lock);

    return olp_cont_value[slot];
#else
    return 0.0;
#endif

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int32_t oti_blas_caps(void){

    return oti_lapack_provider()->caps;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oti_blas_scope_enter(oti_blas_scope_t* scope){

    const oti_lapack_provider_t* p = oti_lapack_provider();
    int32_t caps = p->caps;

    if (scope == NULL){
        return 0;
    }

    scope->kind  = 0;
    scope->saved = 0;

    if ((caps & OTI_BLAS_CAP_LOCAL_THREADS) && p->set_threads_local != NULL){
        scope->saved = (int32_t)((olp_set_local_t)p->set_threads_local)(1);
        scope->kind  = OTI_BLAS_CAP_LOCAL_THREADS;
        return 1;
    }

    if ((caps & OTI_BLAS_CAP_ACCEL_THREADING) && p->blas_set_threading != NULL
        && p->blas_get_threading != NULL){

        unsigned saved = ((olp_get_threading_t)p->blas_get_threading)();

        // 1 is BLAS_THREADING_SINGLE_THREADED; a non-zero return means nothing changed ([cL9]).
        if (((olp_set_threading_t)p->blas_set_threading)(1u) != 0){
            return 0;
        }

        scope->saved = (int32_t)saved;
        scope->kind  = OTI_BLAS_CAP_ACCEL_THREADING;
        return 1;

    }

    return (caps & (OTI_BLAS_CAP_SERIAL_BUILD | OTI_BLAS_CAP_OMP_NESTED)) ? 1 : 0;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void oti_blas_scope_exit(oti_blas_scope_t* scope){

    const oti_lapack_provider_t* p;

    if (scope == NULL){
        return;
    }

    p = oti_lapack_provider();

    if (scope->kind == OTI_BLAS_CAP_LOCAL_THREADS && p->set_threads_local != NULL){
        (void)((olp_set_local_t)p->set_threads_local)((int)scope->saved);
    } else if (scope->kind == OTI_BLAS_CAP_ACCEL_THREADING && p->blas_set_threading != NULL){
        (void)((olp_set_threading_t)p->blas_set_threading)((unsigned)scope->saved);
    }

    scope->kind  = 0;
    scope->saved = 0;

}
// -------------------------------------------------------------------------------------------------------
