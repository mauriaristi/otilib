#ifndef OTI_CORE_EXEC_H
#define OTI_CORE_EXEC_H

// -------------------------------------------------------------------------------------------------------
// Execution context (oti_ctx) and execution layer (oti_exec_t, oti_parallel_for)
// (PLAN-ndarray.md "Parallel execution" and "Determinism"; PLAN-ndarray-contracts.md section 5).
//
// Principles (the library's parallelization philosophy):
//   1. One level of parallelism per operation. Without reliable local BLAS thread control (or a
//      provider proven to serialize itself inside liboti's OpenMP regions), BLAS owns the
//      parallelism and liboti's batch loops around BLAS calls run serially.
//   2. The caller owns the machine: no process-wide thread setting is ever changed (no
//      omp_set_num_threads(), no openblas_set_num_threads()). A positive nthreads is applied with the
//      OpenMP num_threads clause of one region only.
//   3. Determinism: library elementwise kernels and reductions give bit-identical results for every
//      thread count and backend, on a fixed platform and build. Work is cut into fixed logical chunks
//      (OTI_EXEC_CHUNK_ELEMS) that the serial path uses too; reductions combine chunk results with a
//      fixed pairwise tree in chunk order. Build rules: no -ffast-math / -Ofast, no vector math
//      library (-fveclib, glibc libmvec, `omp simd` around libm calls), -ffp-contract=off on
//      src/c/core/exec.c and on the ndarray unity src/c/real_ndarray.c only. Vendor BLAS/LAPACK and
//      MPI results are not covered.
//   4. No parallelism inside an enclosing parallel region (an OpenMP region or a library worker):
//      oti_parallel_for() then runs the chunks inline, in order.
//   5. Distributed memory is a layer above the kernels (a later liboti_mpi add-on).
//
// Contexts:
//   - Every operation takes an `oti_ctx *`; NULL means the default context. The default context is
//     created on first use (pthread_once), is never freed, and is read-only afterwards; its last error
//     is thread-local. A ctx equal to oti_ctx_default() is treated exactly like NULL everywhere: the
//     default is never written. A user context is initialized with oti_ctx_init(), may be used by
//     one host thread at a time, and holds its own last error.
//   - Until the shared liboti exists (PLAN-pip-install.md), liboti is linked statically into every
//     Cython module, so each module has its own default context, budgets, last-error slots, LAPACK
//     provider table and capability probe. An error recorded by one module is not visible from
//     another; budgets apply per module. Only the serial and OpenMP backends are supported in Python
//     until then (decision 17).
//
// Implemented in src/c/core/exec.c (Phase X), with the __atomic_* builtins, _Thread_local and
// pthread_once already used by the core (no <stdatomic.h>: release builds use -std=c99).
// -------------------------------------------------------------------------------------------------------

#include <stdint.h>

#include "oti/core/status.h"

#ifdef __cplusplus
extern "C" {
#endif

// -------------------------------------------------------------------------------------------------------
// --------------------------------------      CONSTANTS         -----------------------------------------
// -------------------------------------------------------------------------------------------------------

/**
 * @name Parallel backends (oti_exec_t.backend)
 * The build chooses which exist: -DOTI_PARALLEL=openmp (default) | pthreads | serial. SERIAL always
 * exists. A request for a backend that is not compiled in fails with OTI_ERR_BACKEND.
 * @{
 */
#define OTI_BACKEND_DEFAULT   (-1) ///< The build's default backend.
#define OTI_BACKEND_SERIAL      0  ///< Chunks run inline, in order.
#define OTI_BACKEND_OPENMP      1  ///< One OpenMP parallel region per call.
#define OTI_BACKEND_PTHREADS    2  ///< The library pool (Phase P; gated on the shared liboti).
/** @} */
// -------------------------------------------------------------------------------------------------------


/**
 * @name BLAS policies (oti_exec_t.blas_policy)
 * @{
 */
#define OTI_BLAS_INHERIT             0 ///< Never touch BLAS threads; BLAS batch loops run serially.
#define OTI_BLAS_SERIAL_IN_REGIONS   1 ///< Batch loops run in parallel when BLAS can be kept to one
                                       ///< thread per worker (local thread control, or OMP_NESTED);
                                       ///< else they run serially.
/** @} */
// -------------------------------------------------------------------------------------------------------


/**
 * @name Execution constants
 * @{
 */
#define OTI_EXEC_CHUNK_ELEMS            4096 ///< Fixed logical chunk of library kernels and reductions.
#define OTI_EXEC_MIN_PARALLEL_DEFAULT   4096 ///< Default oti_exec_t.min_parallel_elems.
/** @} */
// OTI_DEVICE_CPU is defined in oti/core/status.h.
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// --------------------------------------      STRUCTURES        -----------------------------------------
// -------------------------------------------------------------------------------------------------------

/**
 * @brief Execution policy of a context.
 */
typedef struct {
    int32_t struct_size;         ///< sizeof(oti_exec_t); set by oti_exec_init().
    int32_t backend;             ///< OTI_BACKEND_*.
    int32_t nthreads;            ///< Workers per region; 0 = inherit (omp_get_max_threads()).
    int32_t blas_policy;         ///< OTI_BLAS_*.
    int64_t min_parallel_elems;  ///< Default work threshold below which a loop runs serially.
    int64_t reserved[4];         ///< Zero.
} oti_exec_t;

/**
 * @brief Execution context: device, execution policy, byte budgets and last error.
 *
 * POD, versioned by struct_size. The ABI v0 header (PLAN-core-multilang.md Phase 1b) exposes it as an
 * opaque handle; inside the library its fields are read directly. Only the fields marked "user" may
 * be changed by the owner of a user context, between calls.
 */
typedef struct oti_ctx_s {
    int32_t      struct_size;      ///< sizeof(oti_ctx); set by oti_ctx_init().
    int32_t      device_type;      ///< user: OTI_DEVICE_CPU (the only accepted value).
    int32_t      device_id;        ///< user: 0.
    int32_t      flags;            ///< Zero (reserved).
    oti_exec_t   exec;             ///< user: execution policy.
    int64_t      max_alloc_bytes;  ///< user: budget of one allocation in bytes; 0 = library default.
    int64_t      max_temp_bytes;   ///< user: budget of one operation's temporaries; 0 = max_alloc_bytes.
    void*        stream;           ///< Reserved for device streams; NULL.
    int32_t      last_status;      ///< Last failure recorded in this (user) context; OTI_OK if none.
    int32_t      reserved0;        ///< Zero.
    const char*  last_where;       ///< Static name of the failing function, or NULL.
    const char*  last_msg;         ///< Static message, or NULL.
    int64_t      reserved[8];      ///< Zero.
} oti_ctx;

/**
 * @brief Chunk function run by oti_parallel_for().
 *
 * @param[in,out] arg    Caller data.
 * @param[in]     chunk  Logical chunk index, 0 <= chunk < n_chunks.
 * @param[in]     worker Worker index, 0 <= worker < oti_exec_max_workers(ctx); 0 on the serial path.
 *
 * @return OTI_OK or a status. Must not call back into Python, must not release retained descriptors
 *         and must not change process-wide thread settings.
 */
typedef int (*oti_chunk_fn)(void* arg, int64_t chunk, int32_t worker);

// -------------------------------------------------------------------------------------------------------
// -------------------------------------    END STRUCTURES      ------------------------------------------
// -------------------------------------------------------------------------------------------------------


/**
 * @name Context lifetime
 * @{
 */

/**
 * @brief Sets an execution policy to the defaults.
 *
 * backend OTI_BACKEND_DEFAULT, nthreads 0, blas_policy OTI_BLAS_SERIAL_IN_REGIONS,
 * min_parallel_elems OTI_EXEC_MIN_PARALLEL_DEFAULT.
 *
 * @param[out] exec Policy to initialize. Must not be NULL.
 */
void oti_exec_init(oti_exec_t* exec);

/**
 * @brief Initializes a caller-allocated user context with the defaults.
 *
 * Sets struct_size, device OTI_DEVICE_CPU / 0, oti_exec_init() policy, budgets 0 (library default),
 * no last error. Allocates nothing; a user context needs no destructor.
 *
 * @param[out] ctx Context to initialize.
 *
 * @return OTI_OK, or OTI_ERR_ARGUMENT if @p ctx is NULL.
 */
int oti_ctx_init(oti_ctx* ctx);

/**
 * @brief The default context (what NULL means), created on first use.
 *
 * Read-only after creation. Budgets: OTI_DENSE_MAX_MB MiB when that environment variable holds
 * a positive integer (the dense rule, kept for compatibility), else the physical memory, else 64 GiB.
 * One per copy of liboti (one per Cython module until the shared liboti exists).
 *
 * @return Pointer to the process-lifetime default context. Never NULL. Not owned by the caller.
 */
const oti_ctx* oti_ctx_default(void);

/**
 * @brief Checks a context before use.
 *
 * @param[in] ctx Context, or NULL (the default, always valid).
 *
 * @return OTI_OK; OTI_ERR_ARGUMENT for a bad struct_size, a device other than the CPU, a negative
 *         budget or an unknown policy value; OTI_ERR_BACKEND for a backend not compiled in.
 */
int oti_ctx_check(const oti_ctx* ctx);

/** @} */
// -------------------------------------------------------------------------------------------------------


/**
 * @name Last error
 * Statuses are the primary channel; the last error adds where and why. Failing public functions call
 * oti_ctx_set_error() once, at the outermost level. Success never clears it.
 * @{
 */

/**
 * @brief Records a failure in a context.
 *
 * For a user context it writes ctx->last_status / last_where / last_msg. For NULL, or a pointer equal
 * to oti_ctx_default(), it writes the calling thread's thread-local record and never the default
 * context itself. Never allocates.
 *
 * @param[in,out] ctx    Context, or NULL.
 * @param[in]     status The failing status (negative, or a positive LAPACK info).
 * @param[in]     where  Static string naming the public function (e.g. "nd_matmul"); not copied.
 * @param[in]     msg    Static message, or NULL; not copied.
 */
void oti_ctx_set_error(oti_ctx* ctx, int status, const char* where, const char* msg);

/**
 * @brief Reads the last failure recorded in a context (the calling thread's, for NULL or the
 *        default context's pointer).
 *
 * @param[in]  ctx   Context, or NULL.
 * @param[out] where Static function name, or NULL if none. May be NULL.
 * @param[out] msg   Static message, or NULL if none. May be NULL.
 *
 * @return The recorded status, or OTI_OK if nothing was recorded.
 */
int oti_ctx_last_error(const oti_ctx* ctx, const char** where, const char** msg);

/**
 * @brief Clears the last error of a context (the calling thread's, for NULL or the default context's
 *        pointer).
 *
 * @param[in,out] ctx Context, or NULL.
 */
void oti_ctx_clear_error(oti_ctx* ctx);

/** @} */
// -------------------------------------------------------------------------------------------------------


/**
 * @name Byte budgets
 * Budgets are caps checked before allocating, not running totals: nothing is accounted at release.
 * @{
 */

/**
 * @brief Checks one allocation against the context's max_alloc_bytes.
 *
 * @param[in] ctx    Context, or NULL.
 * @param[in] nbytes Requested bytes (already computed with checked arithmetic), >= 0.
 *
 * @return OTI_OK, or OTI_ERR_MEMORY if @p nbytes exceeds the budget.
 */
int oti_ctx_check_alloc(const oti_ctx* ctx, int64_t nbytes);

/**
 * @brief Checks the total temporaries of one operation (packs, workspaces) against max_temp_bytes.
 *
 * @param[in] ctx    Context, or NULL.
 * @param[in] nbytes Sum of the operation's temporary bytes, >= 0.
 *
 * @return OTI_OK, or OTI_ERR_MEMORY if @p nbytes exceeds the budget.
 */
int oti_ctx_check_temp(const oti_ctx* ctx, int64_t nbytes);

/** @} */
// -------------------------------------------------------------------------------------------------------


/**
 * @name Backend queries
 * @{
 */

/**
 * @brief Tells whether a backend is compiled into this liboti.
 *
 * @param[in] backend OTI_BACKEND_*.
 *
 * @return 1 if available (SERIAL always is; DEFAULT resolves to the build default), 0 otherwise.
 */
int oti_exec_backend_available(int32_t backend);

/**
 * @brief Tells whether the calling thread is inside a parallel region.
 *
 * True inside an OpenMP region (omp_in_parallel()) and inside any library worker (a thread-local
 * flag set by oti_parallel_for() and the pool).
 *
 * @return 1 or 0.
 */
int oti_exec_in_parallel(void);

/**
 * @brief Number of workers a parallel loop of this context would use now.
 *
 * @param[in] ctx Context, or NULL.
 *
 * @return 1 for SERIAL, inside a parallel region, or when only one thread is available; otherwise
 *         nthreads, or omp_get_max_threads() when nthreads is 0. Never below 1.
 */
int32_t oti_exec_max_workers(const oti_ctx* ctx);

/**
 * @brief Decides whether a loop over @p work_items items is run in parallel.
 *
 * @param[in] ctx        Context, or NULL.
 * @param[in] work_items Items of work in the loop (elements, matrices, ...).
 * @param[in] min_items  Threshold of this loop; <= 0 uses ctx->exec.min_parallel_elems. Existing loops
 *                       keep their thresholds (dense SoA 4096, AoS 64, semi-sparse AoS 64).
 *
 * @return 1 if work_items >= threshold and oti_exec_max_workers(ctx) > 1, else 0.
 */
int oti_exec_parallel_ok(const oti_ctx* ctx, int64_t work_items, int64_t min_items);

/**
 * @brief Number of logical chunks of @p chunk_items items covering @p n_items items.
 *
 * @param[in] n_items     Items, >= 0.
 * @param[in] chunk_items Items per chunk, > 0. Must not depend on the thread count.
 *
 * @return ceil(n_items / chunk_items); 0 when n_items is 0.
 */
static inline int64_t oti_exec_nchunks(int64_t n_items, int64_t chunk_items){
    return n_items <= 0 ? 0 : 1 + (n_items - 1) / chunk_items;
}

/** @} */
// -------------------------------------------------------------------------------------------------------


/**
 * @name Chunked loops
 * The error rule: the returned status is that of the lowest-index failing chunk. Every chunk below
 * it has run; chunks above a known failure may be skipped. Outputs are unspecified after a failure.
 * Chunk functions run on the calling thread or on worker threads; a worker never holds the GIL.
 * @{
 */

/**
 * @brief Runs chunks 0 .. n_chunks-1 inline, in order (the reference path).
 *
 * @param[in]     n_chunks Number of chunks, >= 0.
 * @param[in]     fn       Chunk function (worker index 0).
 * @param[in,out] arg      Passed to @p fn.
 *
 * @return OTI_OK, or the status of the first failing chunk (later chunks are not run).
 */
int oti_serial_for(int64_t n_chunks, oti_chunk_fn fn, void* arg);

/**
 * @brief Runs chunks 0 .. n_chunks-1 on the context's backend.
 *
 * Runs inline (as oti_serial_for()) when n_chunks <= 1, inside a parallel region, or with one worker.
 * The library dispenses chunks itself (a worksharing `schedule(dynamic)` is nonmonotonic by default
 * since OpenMP 5.0): the OpenMP backend opens one `#pragma omp parallel num_threads(min(workers,
 * n_chunks))` region (workers = oti_exec_max_workers(ctx); a clause, never a process-wide setting)
 * with no barrier of its own (S27). Each worker claims c = __atomic_fetch_add(&next, 1) and stops when
 * c >= n_chunks or c > first_fail, so chunks are claimed in increasing order; it keeps its own lowest
 * failure, and the minimum over the workers is taken after the region. The pthreads pool uses the
 * same dispenser. Never changes process-wide settings. Callers decide with
 * oti_exec_parallel_ok() whether to call this or oti_serial_for().
 *
 * @param[in,out] ctx      Context, or NULL.
 * @param[in]     n_chunks Number of chunks, >= 0.
 * @param[in]     fn       Chunk function; must be safe to run concurrently on distinct chunks.
 * @param[in,out] arg      Passed to @p fn.
 *
 * @return OTI_OK, the lowest-index chunk failure, or OTI_ERR_BACKEND if the context asks for a backend
 *         that is not compiled in (nothing is run).
 */
int oti_parallel_for(oti_ctx* ctx, int64_t n_chunks, oti_chunk_fn fn, void* arg);

/**
 * @brief oti_parallel_for() for chunks that call BLAS / LAPACK.
 *
 * Runs in parallel only when ctx->exec.blas_policy is OTI_BLAS_SERIAL_IN_REGIONS and oti_blas_caps()
 * (include/oti/core/lapack.h) has OTI_BLAS_CAP_LOCAL_CONTROL or OTI_BLAS_CAP_OMP_NESTED; each
 * worker then enters oti_blas_scope_enter() before its first chunk and leaves it
 * with oti_blas_scope_exit() on every path (with OMP_NESTED alone they change nothing). Otherwise the
 * chunks run serially and BLAS keeps its own threading (principle 1). Until Phase 3 provides
 * oti_blas_caps(), it is oti_serial_for().
 *
 * @param[in,out] ctx      Context, or NULL.
 * @param[in]     n_chunks Number of chunks, >= 0.
 * @param[in]     fn       Chunk function.
 * @param[in,out] arg      Passed to @p fn.
 *
 * @return As oti_parallel_for().
 */
int oti_parallel_for_blas(oti_ctx* ctx, int64_t n_chunks, oti_chunk_fn fn, void* arg);

/** @} */
// -------------------------------------------------------------------------------------------------------

#ifdef __cplusplus
}
#endif

#endif
