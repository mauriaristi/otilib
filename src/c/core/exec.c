// pthread / POSIX declarations under the Release build's -std=c99 on glibc (contracts S23, the 1.3.1
// pattern of src/c/dense.c). Not defined on Apple, where _POSIX_C_SOURCE would instead hide
// non-POSIX declarations.
#if !defined(__APPLE__) && !defined(_POSIX_C_SOURCE)
#define _POSIX_C_SOURCE 200809L
#endif

#include "oti/core/exec.h"

// Execution layer, oti_ctx and the status helpers (Phase X; PLAN-ndarray-contracts.md sections 4
// and 5). Its own translation unit, compiled with -ffp-contract=off (contracts S12).
//
// File-static helpers carry the oe_ prefix. No locks on the hot path: the default context is written
// once under pthread_once and only read afterwards (S7); the last error of NULL / the default context
// is thread-local; the chunk dispenser uses the __atomic_* builtins on plain integers (S9).

#include <pthread.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#if defined(__APPLE__)
#include <sys/types.h>
#include <sys/sysctl.h>
#endif

#if defined(OTI_PARALLEL_OPENMP)
#if !defined(_OPENMP)
#error "OTI_PARALLEL_OPENMP is defined but this translation unit is not compiled with OpenMP"
#endif
#include <omp.h>
#define OE_HAVE_OPENMP 1
#else
#define OE_HAVE_OPENMP 0
#endif

// Determinism build rule (contracts 5.4): no fast-math in the execution layer. The configure-time
// check of CMAKE_C_FLAGS* covers the other translation units.
#if defined(__FAST_MATH__)
#error "otilib's execution layer must not be compiled with -ffast-math / -Ofast (contracts 5.4)"
#endif

// BLAS worker scopes (contracts 5.5). Phase 3 defines OTI_EXEC_BLAS_SCOPES once oti_blas_caps(),
// oti_blas_scope_enter() and oti_blas_scope_exit() exist (include/oti/core/lapack.h). Until then the
// capability mask is empty, so oti_parallel_for_blas() always takes the serial path; the scoped
// parallel path below is compiled either way and is what Phase 3 switches on.
#if defined(OTI_EXEC_BLAS_SCOPES)
#include "oti/core/lapack.h"
typedef oti_blas_scope_t oe_blas_scope_t;
#define OE_BLAS_PARALLEL_MASK (OTI_BLAS_CAP_LOCAL_CONTROL | OTI_BLAS_CAP_OMP_NESTED)
#else
typedef struct {
    int32_t kind;
} oe_blas_scope_t;
#define OE_BLAS_PARALLEL_MASK 0
#endif

// Budget of the default context when the physical memory cannot be queried: 64 GiB.
#define OE_BUDGET_FALLBACK_BYTES (INT64_C(64) << 30)

// The default context (what NULL means): written once by oe_default_init(), read-only afterwards.
static oti_ctx oe_default;
static pthread_once_t oe_default_once = PTHREAD_ONCE_INIT;

// Last error of NULL / the default context, one record per thread (contracts 4.3, [cM6]).
static _Thread_local int32_t     oe_tls_status;
static _Thread_local const char* oe_tls_where;
static _Thread_local const char* oe_tls_msg;

// Nonzero while the calling thread runs chunks as a library worker (oti_exec_in_parallel()).
static _Thread_local int oe_tls_in_worker;

// Padding that keeps the two hot counters of oe_loop_t off each other's cache line and off the line of
// the fields every claim reads (critic W1 finding 13.1). 128 bytes: Apple M-series lines are 128,
// x86 and most other ARM cores 64. Any two addresses this far apart lie on different lines, so no
// alignment of the (stack) struct is needed.
#define OE_CACHE_LINE 128

// Per-worker failure slots kept on the stack; a larger team allocates its slots (oe_parallel_for()).
#define OE_STACK_SLOTS 64

// Lowest failure of one worker: chunk index (INT64_MAX if none) and its status.
typedef struct {
    int64_t fail;
    int     status;
} oe_slot_t;

// Shared state of one parallel loop: the chunk dispenser of contracts 5.3 (S17).
typedef struct {
    int64_t      n_chunks;    // read-only during the loop, like the next four fields.
    oti_chunk_fn fn;
    void*        arg;
    oe_slot_t*   slots;       // one per worker, written by its worker once, read after the region.
    int          blas_scope;  // nonzero: each worker runs inside a BLAS thread scope.
    char         pad0[OE_CACHE_LINE];
    int64_t      next;        // next chunk to claim (__atomic_fetch_add).
    char         pad1[OE_CACHE_LINE];
    int64_t      first_fail;  // lowest failing chunk index so far (CAS-min); INT64_MAX if none.
    char         pad2[OE_CACHE_LINE];
} oe_loop_t;


// *******************************************************************************************************
const char* oti_status_string(int status){

    if (status > 0){
        return "LAPACK_INFO: singular matrix (exactly zero pivot)";
    }

    switch (status){
    case OTI_OK:
        return "OTI_OK: success";
    case OTI_ERR_SIZE:
        return "OTI_ERR_SIZE: size or count overflow, or does not fit LAPACK's 32-bit integers";
    case OTI_ERR_MEMORY:
        return "OTI_ERR_MEMORY: allocation failed or over the byte budget";
    case OTI_ERR_PIVOT:
        return "OTI_ERR_PIVOT: invalid pivot indices";
    case OTI_ERR_INDEX:
        return "OTI_ERR_INDEX: index, axis, direction or order out of range";
    case OTI_ERR_ARGUMENT:
        return "OTI_ERR_ARGUMENT: invalid argument";
    case OTI_ERR_SHAPE:
        return "OTI_ERR_SHAPE: incompatible shapes, broadcast failure or too many dimensions";
    case OTI_ERR_BUSY:
        return "OTI_ERR_BUSY: growth or relayout refused (live views or exports, borrowed buffer)";
    case OTI_ERR_DTYPE:
        return "OTI_ERR_DTYPE: unsupported or mismatched dtype or buffer format";
    case OTI_ERR_LAYOUT:
        return "OTI_ERR_LAYOUT: internal overlap of an output, unsupported strides or span violation";
    case OTI_ERR_CONVERGE:
        return "OTI_ERR_CONVERGE: iteration did not converge";
    case OTI_ERR_NOTPD:
        return "OTI_ERR_NOTPD: matrix is not positive definite";
    case OTI_ERR_BACKEND:
        return "OTI_ERR_BACKEND: parallel backend not compiled in";
    case OTI_ERR_READONLY:
        return "OTI_ERR_READONLY: destination is not writeable";
    default:
        return "OTI_ERR_UNKNOWN: unknown status";
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Physical memory in bytes, or 0 when it cannot be queried (the rule of dn_max_bytes()).
static int64_t oe_physical_bytes(void){

#if defined(__APPLE__)
    uint64_t mem = 0;
    size_t len = sizeof(mem);

    if (sysctlbyname("hw.memsize", &mem, &len, NULL, 0) == 0 && len == sizeof(mem)){
        return (mem > (uint64_t)INT64_MAX) ? INT64_MAX : (int64_t)mem;
    }

    return 0;
#elif defined(_SC_PHYS_PAGES) && defined(_SC_PAGE_SIZE)
    long pages = sysconf(_SC_PHYS_PAGES), page = sysconf(_SC_PAGE_SIZE);

    if (pages > 0 && page > 0){
        return ((uint64_t)pages > (uint64_t)INT64_MAX / (uint64_t)page) ? INT64_MAX
               : (int64_t)pages * (int64_t)page;
    }

    return 0;
#else
    return 0;
#endif

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Default budget: OTI_DENSE_MAX_MB MiB when that variable holds a positive integer, else the physical
// memory, else 64 GiB (dense's rule, include/oti/dense/scalar/base.h). Saturates at INT64_MAX.
static int64_t oe_default_budget(void){

    const char* env = getenv("OTI_DENSE_MAX_MB");
    int64_t phys;

    if (env != NULL && env[0] >= '0' && env[0] <= '9'){

        char* end = NULL;
        unsigned long long mb = strtoull(env, &end, 10);

        if (*end == '\0' && mb > 0){
            return (mb > ((uint64_t)INT64_MAX >> 20)) ? INT64_MAX : (int64_t)(mb << 20);
        }

    }

    phys = oe_physical_bytes();

    return (phys > 0) ? phys : OE_BUDGET_FALLBACK_BYTES;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Builds the default context; run once, through pthread_once.
static void oe_default_init(void){

    int64_t budget = oe_default_budget();

    (void)oti_ctx_init(&oe_default);
    oe_default.max_alloc_bytes = budget;
    oe_default.max_temp_bytes  = budget;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Nonzero when ctx means the default context: NULL or the default's own pointer ([cM6]). Comparing
// the address needs no initialization.
static inline int oe_is_default(const oti_ctx* ctx){

    return ctx == NULL || ctx == &oe_default;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// The context to read: ctx, or the (initialized) default for NULL / the default's pointer.
static inline const oti_ctx* oe_resolve(const oti_ctx* ctx){

    return oe_is_default(ctx) ? oti_ctx_default() : ctx;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void oti_exec_init(oti_exec_t* exec){

    if (exec == NULL){
        return;
    }

    memset(exec, 0, sizeof(*exec));
    exec->struct_size        = (int32_t)sizeof(oti_exec_t);
    exec->backend            = OTI_BACKEND_DEFAULT;
    exec->nthreads           = 0;
    exec->blas_policy        = OTI_BLAS_SERIAL_IN_REGIONS;
    exec->min_parallel_elems = OTI_EXEC_MIN_PARALLEL_DEFAULT;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oti_ctx_init(oti_ctx* ctx){

    if (ctx == NULL){
        return OTI_ERR_ARGUMENT;
    }

    memset(ctx, 0, sizeof(*ctx));
    ctx->struct_size     = (int32_t)sizeof(oti_ctx);
    ctx->device_type     = OTI_DEVICE_CPU;
    ctx->device_id       = 0;
    oti_exec_init(&ctx->exec);
    ctx->max_alloc_bytes = 0;
    ctx->max_temp_bytes  = 0;
    ctx->stream          = NULL;
    ctx->last_status     = OTI_OK;
    ctx->last_where      = NULL;
    ctx->last_msg        = NULL;

    return OTI_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
const oti_ctx* oti_ctx_default(void){

    (void)pthread_once(&oe_default_once, oe_default_init);

    return &oe_default;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oti_exec_backend_available(int32_t backend){

    switch (backend){
    case OTI_BACKEND_DEFAULT:
    case OTI_BACKEND_SERIAL:
        return 1;
    case OTI_BACKEND_OPENMP:
        return OE_HAVE_OPENMP;
    default:
        return 0;       // OTI_BACKEND_PTHREADS is Phase P; any other value is unknown.
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// The concrete backend of a policy: DEFAULT resolves to the build's (OpenMP when compiled in, else
// serial). OTI_ERR_BACKEND when the requested backend is not compiled in or unknown (contracts 5.6).
static int oe_backend(const oti_exec_t* exec, int32_t* p_backend){

    int32_t backend = exec->backend;

    if (!oti_exec_backend_available(backend)){
        return OTI_ERR_BACKEND;
    }

    if (backend == OTI_BACKEND_DEFAULT){
        backend = OE_HAVE_OPENMP ? OTI_BACKEND_OPENMP : OTI_BACKEND_SERIAL;
    }

    *p_backend = backend;

    return OTI_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oti_ctx_check(const oti_ctx* ctx){

    int32_t backend;

    if (oe_is_default(ctx)){
        return OTI_OK;
    }

    // Exact sizes until the ABI v0 header versions the struct (contracts 5.1). Reserved fields are not
    // inspected, so that a later version may give them a meaning.
    if (ctx->struct_size != (int32_t)sizeof(oti_ctx)
        || ctx->exec.struct_size != (int32_t)sizeof(oti_exec_t)){
        return OTI_ERR_ARGUMENT;
    }

    if (ctx->device_type != OTI_DEVICE_CPU || ctx->device_id != 0){
        return OTI_ERR_ARGUMENT;
    }

    if (ctx->max_alloc_bytes < 0 || ctx->max_temp_bytes < 0){
        return OTI_ERR_ARGUMENT;
    }

    if (ctx->exec.nthreads < 0 || ctx->exec.min_parallel_elems < 0){
        return OTI_ERR_ARGUMENT;
    }

    if (ctx->exec.blas_policy != OTI_BLAS_INHERIT
        && ctx->exec.blas_policy != OTI_BLAS_SERIAL_IN_REGIONS){
        return OTI_ERR_ARGUMENT;
    }

    return oe_backend(&ctx->exec, &backend);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void oti_ctx_set_error(oti_ctx* ctx, int status, const char* where, const char* msg){

    if (oe_is_default(ctx)){

        oe_tls_status = (int32_t)status;
        oe_tls_where  = where;
        oe_tls_msg    = msg;
        return;

    }

    ctx->last_status = (int32_t)status;
    ctx->last_where  = where;
    ctx->last_msg    = msg;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oti_ctx_last_error(const oti_ctx* ctx, const char** where, const char** msg){

    int status;
    const char* w;
    const char* m;

    if (oe_is_default(ctx)){
        status = oe_tls_status;
        w      = oe_tls_where;
        m      = oe_tls_msg;
    } else {
        status = ctx->last_status;
        w      = ctx->last_where;
        m      = ctx->last_msg;
    }

    if (where != NULL){
        *where = w;
    }

    if (msg != NULL){
        *msg = m;
    }

    return status;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void oti_ctx_clear_error(oti_ctx* ctx){

    oti_ctx_set_error(ctx, OTI_OK, NULL, NULL);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Per-allocation cap of a context: its max_alloc_bytes, or the default's when 0 (S6).
static inline int64_t oe_alloc_cap(const oti_ctx* ctx){

    const oti_ctx* c = oe_resolve(ctx);

    return (c->max_alloc_bytes > 0) ? c->max_alloc_bytes : oti_ctx_default()->max_alloc_bytes;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oti_ctx_check_alloc(const oti_ctx* ctx, int64_t nbytes){

    if (nbytes < 0){
        return OTI_ERR_ARGUMENT;
    }

    return (nbytes > oe_alloc_cap(ctx)) ? OTI_ERR_MEMORY : OTI_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oti_ctx_check_temp(const oti_ctx* ctx, int64_t nbytes){

    const oti_ctx* c = oe_resolve(ctx);
    int64_t cap;

    if (nbytes < 0){
        return OTI_ERR_ARGUMENT;
    }

    cap = (c->max_temp_bytes > 0) ? c->max_temp_bytes : oe_alloc_cap(c);

    return (nbytes > cap) ? OTI_ERR_MEMORY : OTI_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oti_exec_in_parallel(void){

    if (oe_tls_in_worker){
        return 1;
    }

#if OE_HAVE_OPENMP
    // omp_get_level() also counts an inactive (one-thread) enclosing region, which is still a region
    // the caller opened: no parallelism is started inside it (principle 4).
    return omp_in_parallel() || omp_get_level() > 0;
#else
    return 0;
#endif

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Workers of a valid, resolved context (the body of oti_exec_max_workers()).
static int32_t oe_max_workers(const oti_ctx* c){

    int32_t backend;

    if (oe_backend(&c->exec, &backend) != OTI_OK || backend == OTI_BACKEND_SERIAL
        || oti_exec_in_parallel()){
        return 1;
    }

#if OE_HAVE_OPENMP
    {
        int32_t n = (c->exec.nthreads > 0) ? c->exec.nthreads : (int32_t)omp_get_max_threads();
        return (n > 1) ? n : 1;
    }
#else
    return 1;
#endif

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int32_t oti_exec_max_workers(const oti_ctx* ctx){

    return oe_max_workers(oe_resolve(ctx));

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oti_exec_parallel_ok(const oti_ctx* ctx, int64_t work_items, int64_t min_items){

    const oti_ctx* c = oe_resolve(ctx);
    int64_t threshold = (min_items > 0) ? min_items : c->exec.min_parallel_elems;

    return work_items >= threshold && oe_max_workers(c) > 1;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oti_serial_for(int64_t n_chunks, oti_chunk_fn fn, void* arg){

    int64_t c;

    // An empty or negative range runs nothing, like range(n): fn is only needed when a chunk runs.
    if (n_chunks <= 0){
        return OTI_OK;
    }

    if (fn == NULL){
        return OTI_ERR_ARGUMENT;
    }

    for (c = 0; c < n_chunks; c++){

        int status = fn(arg, c, 0);

        if (status != OTI_OK){
            return status;
        }

    }

    return OTI_OK;

}
// -------------------------------------------------------------------------------------------------------


// The dispenser and the worker scopes serve the threaded backends only (OpenMP now, the pthreads pool
// of Phase P).
#if OE_HAVE_OPENMP || defined(OTI_PARALLEL_PTHREADS)
// *******************************************************************************************************
// Lowers *p to v if v is smaller (CAS-min on a plain integer, S9).
static inline void oe_atomic_min(int64_t* p, int64_t v){

    int64_t cur = __atomic_load_n(p, __ATOMIC_RELAXED);

    while (v < cur
           && !__atomic_compare_exchange_n(p, &cur, v, 1, __ATOMIC_RELAXED, __ATOMIC_RELAXED)){
        // cur was reloaded by the failed exchange.
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// The chunk dispenser of one worker (contracts 5.3, [cH1]): claims chunks in increasing order and
// stops at the end or once its claim lies above a known failure. A claimed chunk below the final
// failure always runs, so every chunk below the returned index has run. The worker's own lowest
// failure (it stops at its first) is returned in *p_fail / *p_status; INT64_MAX if none. Shared with
// the pthreads pool of Phase P.
static void oe_dispense(oe_loop_t* loop, int32_t worker, int64_t* p_fail, int* p_status){

    *p_fail   = INT64_MAX;
    *p_status = OTI_OK;

    for (;;){

        int64_t c = __atomic_fetch_add(&loop->next, 1, __ATOMIC_RELAXED);
        int status;

        // Unsigned compare: a counter that wrapped past INT64_MAX (n_chunks within `workers` of it)
        // reads as huge and stops the worker instead of running a negative chunk.
        if ((uint64_t)c >= (uint64_t)loop->n_chunks
            || c > __atomic_load_n(&loop->first_fail, __ATOMIC_RELAXED)){
            return;
        }

        status = loop->fn(loop->arg, c, worker);

        if (status != OTI_OK){

            *p_fail   = c;
            *p_status = status;
            oe_atomic_min(&loop->first_fail, c);
            return;

        }

    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Enters the worker's BLAS thread scope. A failure leaves kind 0 (nothing to restore) and the chunks
// still run (contracts 5.5, [cL9]).
static inline void oe_blas_enter(oe_blas_scope_t* scope){

#if defined(OTI_EXEC_BLAS_SCOPES)
    // The return (1: BLAS is single-threaded here, 0: cannot be ensured) is not a status, and the
    // callee sets scope->kind itself (0 when nothing changed): never overwrite it here, or
    // oti_blas_scope_exit() would restore nothing.
    (void)oti_blas_scope_enter(scope);
#else
    scope->kind = 0;
#endif

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Leaves the worker's BLAS thread scope; called on every path, after the worker's last chunk.
static inline void oe_blas_exit(oe_blas_scope_t* scope){

#if defined(OTI_EXEC_BLAS_SCOPES)
    oti_blas_scope_exit(scope);
#else
    (void)scope;
#endif

}
// -------------------------------------------------------------------------------------------------------
#endif


#if OE_HAVE_OPENMP
// *******************************************************************************************************
// Body of one OpenMP worker: marks the thread as a library worker, runs the dispenser (inside a BLAS
// scope when asked) and stores its own lowest failure in its slot. No barrier of its own: the region's
// closing barrier publishes the slots to the caller, which takes the minimum (critic W1 finding 1).
static void oe_omp_worker(oe_loop_t* loop){

    int32_t worker = (int32_t)omp_get_thread_num();
    int saved = oe_tls_in_worker;
    oe_blas_scope_t scope;

    oe_tls_in_worker = 1;

    if (loop->blas_scope){
        oe_blas_enter(&scope);
    }

    oe_dispense(loop, worker, &loop->slots[worker].fail, &loop->slots[worker].status);

    if (loop->blas_scope){
        oe_blas_exit(&scope);
    }

    oe_tls_in_worker = saved;

}
// -------------------------------------------------------------------------------------------------------
#endif


// *******************************************************************************************************
// Shared body of oti_parallel_for() and oti_parallel_for_blas(): validates, then runs inline or on the
// OpenMP backend. blas_scope is nonzero only when the BLAS capabilities allow parallel batch loops.
static int oe_parallel_for(oti_ctx* ctx, int64_t n_chunks, oti_chunk_fn fn, void* arg,
                           int blas_scope){

    const oti_ctx* c = oe_resolve(ctx);
    int32_t backend;
    int32_t workers;
    int status = oti_ctx_check(ctx);

    if (status != OTI_OK){
        return status;
    }

    if (n_chunks <= 0){
        return OTI_OK;
    }

    if (fn == NULL){
        return OTI_ERR_ARGUMENT;
    }

    (void)oe_backend(&c->exec, &backend);      // valid: checked above.
    workers = oe_max_workers(c);

    if (backend == OTI_BACKEND_SERIAL || n_chunks <= 1 || workers <= 1){
        return oti_serial_for(n_chunks, fn, arg);
    }

#if OE_HAVE_OPENMP
    {
        oe_loop_t loop;
        oe_slot_t stack_slots[OE_STACK_SLOTS];
        oe_slot_t* slots = stack_slots;
        int64_t best = INT64_MAX;
        int32_t w;

        // Never more workers than chunks (S27): a 2-chunk loop wakes 2 threads, not the whole team.
        if ((int64_t)workers > n_chunks){
            workers = (int32_t)n_chunks;
        }

        // The team is at most the num_threads value, so `workers` slots cover every worker index.
        // Without memory for a larger team, run with the stack slots' worth of workers.
        if (workers > OE_STACK_SLOTS){
            slots = (oe_slot_t*)malloc((size_t)workers * sizeof(oe_slot_t));
            if (slots == NULL){
                slots   = stack_slots;
                workers = OE_STACK_SLOTS;
            }
        }

        for (w = 0; w < workers; w++){
            slots[w].fail   = INT64_MAX;      // a slot whose thread is not in the team stays empty.
            slots[w].status = OTI_OK;
        }

        loop.n_chunks   = n_chunks;
        loop.fn         = fn;
        loop.arg        = arg;
        loop.slots      = slots;
        loop.blas_scope = blas_scope;
        loop.next       = 0;
        loop.first_fail = INT64_MAX;

        // A clause, never omp_set_num_threads(): the caller's settings stay as they were.
#pragma omp parallel num_threads(workers)
        oe_omp_worker(&loop);

        // Lowest failing chunk over the workers; its status is the result ([cH1]).
        for (w = 0; w < workers; w++){
            if (slots[w].fail < best){
                best   = slots[w].fail;
                status = slots[w].status;
            }
        }

        if (slots != stack_slots){
            free(slots);
        }

        return status;
    }
#else
    (void)blas_scope;
    return oti_serial_for(n_chunks, fn, arg);
#endif

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oti_parallel_for(oti_ctx* ctx, int64_t n_chunks, oti_chunk_fn fn, void* arg){

    return oe_parallel_for(ctx, n_chunks, fn, arg, 0);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// BLAS capabilities that allow parallel batch loops (contracts 5.5); 0 until Phase 3.
static inline int32_t oe_blas_parallel_caps(void){

#if defined(OTI_EXEC_BLAS_SCOPES)
    return oti_blas_caps() & OE_BLAS_PARALLEL_MASK;
#else
    return OE_BLAS_PARALLEL_MASK;
#endif

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oti_parallel_for_blas(oti_ctx* ctx, int64_t n_chunks, oti_chunk_fn fn, void* arg){

    const oti_ctx* c = oe_resolve(ctx);
    int status = oti_ctx_check(ctx);

    if (status != OTI_OK){
        return status;
    }

    if (c->exec.blas_policy == OTI_BLAS_SERIAL_IN_REGIONS && oe_blas_parallel_caps() != 0){
        return oe_parallel_for(ctx, n_chunks, fn, arg, 1);
    }

    // BLAS keeps its own threads; the batch loop runs serially (principle 1).
    return oti_serial_for(n_chunks, fn, arg);

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// ------------------------------------   LOOP PLANNING (S27)   ------------------------------------------
// -------------------------------------------------------------------------------------------------------

// The cost model of oti_exec_plan() (documented in exec.h): a team size w is acceptable when the serial
// time reaches OE_PLAN_K region costs R(w) = oe_region_a + oe_region_b * w nanoseconds.
#define OE_PLAN_K              4.0
#define OE_REGION_FLOOR_NS     1000.0   // no region is assumed cheaper (the probe's pre-filter).
#define OE_REGION_FALLBACK_A   1000.0   // R(w) without a probe: 1 us + 3 us * w (macOS libomp).
#define OE_REGION_FALLBACK_B   3000.0
#define OE_PROBE_REPS          3        // timed regions per probed team size (median), after a warm-up.

// Region-cost model, written once by oe_probe_regions() and read-only afterwards.
static double oe_region_a = OE_REGION_FALLBACK_A;
static double oe_region_b = OE_REGION_FALLBACK_B;
#if OE_HAVE_OPENMP
static int    oe_region_probed;         // 1 when a and b were measured on this machine.
#endif
static pthread_once_t oe_region_once = PTHREAD_ONCE_INIT;


#if OE_HAVE_OPENMP
// *******************************************************************************************************
// Chunk function of the probe: nothing to do.
static int oe_probe_noop(void* arg, int64_t chunk, int32_t worker){

    (void)arg;
    (void)chunk;
    (void)worker;

    return OTI_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Monotonic time in nanoseconds, or a negative value when the clock is unavailable.
static double oe_now_ns(void){

    struct timespec ts;

    if (clock_gettime(CLOCK_MONOTONIC, &ts) != 0){
        return -1.0;
    }

    return (double)ts.tv_sec * 1e9 + (double)ts.tv_nsec;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Cost in nanoseconds of one oti_parallel_for() region of `workers` workers and as many no-op chunks:
// the median of OE_PROBE_REPS timed regions after one warm-up region. Negative when it cannot measure.
static double oe_time_region(int32_t workers){

    double t[OE_PROBE_REPS];
    oti_ctx run;
    int i, j;

    (void)oti_ctx_init(&run);
    run.exec.nthreads = workers;

    if (oti_parallel_for(&run, workers, oe_probe_noop, NULL) != OTI_OK){
        return -1.0;
    }

    for (i = 0; i < OE_PROBE_REPS; i++){

        double t0 = oe_now_ns();
        int status = oti_parallel_for(&run, workers, oe_probe_noop, NULL);
        double t1 = oe_now_ns();

        if (status != OTI_OK || t0 < 0.0 || t1 < 0.0){
            return -1.0;
        }

        t[i] = t1 - t0;

    }

    for (i = 1; i < OE_PROBE_REPS; i++){            // insertion sort of three values.
        double v = t[i];
        for (j = i - 1; j >= 0 && t[j] > v; j--){
            t[j + 1] = t[j];
        }
        t[j + 1] = v;
    }

    return t[OE_PROBE_REPS / 2];

}
// -------------------------------------------------------------------------------------------------------
#endif


// *******************************************************************************************************
// Measures the region-cost line once per process (through pthread_once): regions of 2 workers and of
// omp_get_max_threads() workers. Keeps the fallback constants when it cannot measure.
static void oe_probe_regions(void){

#if OE_HAVE_OPENMP
    int32_t m = (int32_t)omp_get_max_threads();
    double c2, cm, a, b;

    c2 = oe_time_region(2);
    cm = (m > 2) ? oe_time_region(m) : c2;

    if (!(c2 > 0.0) || !(cm > 0.0)){
        return;
    }

    if (m > 2){
        b = (cm - c2) / (double)(m - 2);
        b = (b > 0.0) ? b : 0.0;
        a = c2 - 2.0 * b;
    } else {
        b = c2 / 2.0;                 // one measured size: proportional to the team.
        a = 0.0;
    }

    oe_region_a      = a;
    oe_region_b      = b;
    oe_region_probed = 1;
#endif

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// R(w) in nanoseconds, never below OE_REGION_FLOOR_NS. The model must already be probed.
static inline double oe_region_cost(int32_t workers){

    double r = oe_region_a + oe_region_b * (double)workers;

    return (r > OE_REGION_FLOOR_NS) ? r : OE_REGION_FLOOR_NS;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int32_t oti_exec_plan(const oti_ctx* ctx, int64_t n_items, int64_t chunk_items, double ns_per_item){

    int64_t n_chunks;
    int32_t wmax, w, best = 0;
    double t_serial, t_chunk, t_best;

    // !(x > 0) also rejects NaN; the upper bound rejects infinity.
    if (n_items <= 0 || chunk_items <= 0 || !(ns_per_item > 0.0) || ns_per_item > 1e300){
        return 0;
    }

    n_chunks = oti_exec_nchunks(n_items, chunk_items);

    if (n_chunks < 2 || oti_ctx_check(ctx) != OTI_OK){
        return 0;
    }

    wmax = oe_max_workers(oe_resolve(ctx));         // 1 for SERIAL and inside a region.

    if ((int64_t)wmax > n_chunks){
        wmax = (int32_t)n_chunks;
    }

    t_serial = (double)n_items * ns_per_item;

    if (wmax < 2 || t_serial < OE_PLAN_K * OE_REGION_FLOOR_NS){
        return 0;                                   // never probes for a loop this small.
    }

    (void)pthread_once(&oe_region_once, oe_probe_regions);

    t_chunk = t_serial / (double)n_chunks;
    t_best  = t_serial;

    // Candidates 2, 4, 8, ... below wmax, then wmax itself.
    for (w = 2; ; w = (w > wmax / 2) ? wmax : 2 * w){

        double r = oe_region_cost(w);

        if (t_serial >= OE_PLAN_K * r){

            // ceil(n_chunks / w) without n_chunks + w - 1, which overflows near INT64_MAX.
            int64_t per_worker = n_chunks / w + (n_chunks % w != 0);
            double t = (double)per_worker * t_chunk + r;

            if (t < t_best){
                t_best = t;
                best   = w;
            }

        }

        if (w == wmax){
            break;
        }

    }

    return best;

}
// -------------------------------------------------------------------------------------------------------
