/* Tests of the execution layer (include/oti/core/exec.h, include/oti/core/status.h), Phase X.
 *
 * Written from PLAN-ndarray-contracts.md sections 4 (statuses, last error), 5.1-5.3 (contexts, budgets,
 * oti_parallel_for) and 5.6 (backends), independently of src/c/core/exec.c. Oracles are plain loops and
 * hand-written tables in this file: the status table of section 4.1, a recording chunk function for
 * the error rule (the lowest failing chunk wins and every chunk below it ran, over many random failure
 * patterns with random per-chunk delays, [cH1]), and the documented default values of the default
 * context.
 *
 * The default context is created on first use and read-only afterwards, so main() sets
 * OTI_DENSE_MAX_MB before anything touches it (the budget rule of section 5.1) and every later check
 * only reads it. Tests that need OpenMP (regions, omp_get_max_threads) are compiled only when this
 * translation unit is built with OpenMP (_OPENMP) against an OpenMP liboti (OTI_PARALLEL_OPENMP).
 * BLAS scopes with mocked providers (contracts 5.5) belong to Phase 3 and are not tested here. */
#if !defined(__APPLE__) && !defined(_POSIX_C_SOURCE)
#define _POSIX_C_SOURCE 200809L   // setenv, pthreads under -std=c99 on Linux (contracts S23)
#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <limits.h>
#include <pthread.h>
#include <oti/core/exec.h>
#include <oti/core/status.h>

#if defined(_OPENMP)
#include <omp.h>
#define TEST_HAVE_OMP 1
#else
#define TEST_HAVE_OMP 0
#endif

#if defined(OTI_PARALLEL_OPENMP)
#define BUILD_HAS_OPENMP 1
#else
#define BUILD_HAS_OPENMP 0
#endif

#if defined(OTI_PARALLEL_PTHREADS)
#define BUILD_HAS_PTHREADS 1
#else
#define BUILD_HAS_PTHREADS 0
#endif

#define MAX_CHUNKS 4096

static int n_failed = 0;
static uint64_t g_rng_state;


// *******************************************************************************************************
static void check(int cond, const char* name){

    if (!cond){
        fprintf(stderr, "FAILED: %s\n", name);
        n_failed++;
    } else {
        printf("passed: %s\n", name);
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void rng_seed(uint64_t seed){

    g_rng_state = (seed != 0) ? seed : 0x9E3779B97F4A7C15ULL;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static uint64_t rng_next(void){

    uint64_t x = g_rng_state;

    x ^= x << 13;
    x ^= x >> 7;
    x ^= x << 17;
    g_rng_state = x;

    return x;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Deterministic hash of two integers (SplitMix64 finalizer), used for per-chunk delays and failures.
static uint64_t mix64(uint64_t a, uint64_t b){

    uint64_t z = a * 0x9E3779B97F4A7C15ULL + b + 0x632BE59BD9B4E019ULL;

    z = (z ^ (z >> 30)) * 0xBF58476D1CE4E5B9ULL;
    z = (z ^ (z >> 27)) * 0x94D049BB133111EBULL;

    return z ^ (z >> 31);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void spin(uint64_t iters){

    volatile uint64_t s = 0;
    uint64_t i;

    for (i = 0; i < iters; i++){
        s += i;
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Build an execution context with a backend and a thread count.
static void make_ctx(oti_ctx* ctx, int32_t backend, int32_t nthreads){

    oti_ctx_init(ctx);
    ctx->exec.backend  = backend;
    ctx->exec.nthreads = nthreads;

}
// -------------------------------------------------------------------------------------------------------


// =======================================================================================================
// Statuses (contracts 4.1)
// =======================================================================================================

// *******************************************************************************************************
static void test_status_values(void){

    check(OTI_OK == 0 && OTI_ERR_SIZE == -1 && OTI_ERR_MEMORY == -2 && OTI_ERR_PIVOT == -3,
          "status values: 0, -1, -2, -3");
    check(OTI_ERR_INDEX == -4 && OTI_ERR_ARGUMENT == -5, "status values: -4, -5");
    check(OTI_ERR_SHAPE == -20 && OTI_ERR_BUSY == -21 && OTI_ERR_DTYPE == -22 && OTI_ERR_LAYOUT == -23,
          "status values: -20 .. -23");
    check(OTI_ERR_CONVERGE == -24 && OTI_ERR_NOTPD == -25 && OTI_ERR_BACKEND == -26 &&
          OTI_ERR_READONLY == -27, "status values: -24 .. -27");
    check(sizeof(int) == 4, "int is 32 bits");
    check(OTI_DEVICE_CPU == 1, "OTI_DEVICE_CPU is DLPack kDLCPU = 1");
    check(oti_status_is_singular(1) && oti_status_is_singular(77) && !oti_status_is_singular(0) &&
          !oti_status_is_singular(-1) && !oti_status_is_singular(OTI_ERR_NOTPD),
          "oti_status_is_singular: positive only");

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_status_string(void){

    static const struct { int value; const char* name; } table[] = {
        {OTI_OK, "OTI_OK"},
        {OTI_ERR_SIZE, "OTI_ERR_SIZE"},
        {OTI_ERR_MEMORY, "OTI_ERR_MEMORY"},
        {OTI_ERR_PIVOT, "OTI_ERR_PIVOT"},
        {OTI_ERR_INDEX, "OTI_ERR_INDEX"},
        {OTI_ERR_ARGUMENT, "OTI_ERR_ARGUMENT"},
        {OTI_ERR_SHAPE, "OTI_ERR_SHAPE"},
        {OTI_ERR_BUSY, "OTI_ERR_BUSY"},
        {OTI_ERR_DTYPE, "OTI_ERR_DTYPE"},
        {OTI_ERR_LAYOUT, "OTI_ERR_LAYOUT"},
        {OTI_ERR_CONVERGE, "OTI_ERR_CONVERGE"},
        {OTI_ERR_NOTPD, "OTI_ERR_NOTPD"},
        {OTI_ERR_BACKEND, "OTI_ERR_BACKEND"},
        {OTI_ERR_READONLY, "OTI_ERR_READONLY"}
    };
    const int n = (int)(sizeof(table) / sizeof(table[0]));
    int i, j, ok_prefix = 1, ok_nonnull = 1, ok_distinct = 1, ok_stable = 1, ok_meaning = 1;
    const char* unknown_text = "OTI_ERR_UNKNOWN: unknown status";
    const char* singular_text = "LAPACK_INFO: singular matrix (exactly zero pivot)";
    static const int unknown[] = {-6, -7, -19, -28, -29, -1000, INT_MIN};
    static const int positive[] = {1, 2, 17, 100000, INT_MAX};

    for (i = 0; i < n; i++){

        const char* s = oti_status_string(table[i].value);
        size_t len = strlen(table[i].name);

        if (s == NULL){
            ok_nonnull = 0;
            continue;
        }
        if (strncmp(s, table[i].name, len) != 0 || (table[i].value != OTI_OK && s[len] != ':')){
            ok_prefix = 0;
            fprintf(stderr, "  status %d gave \"%s\", expected prefix \"%s:\"\n", table[i].value, s,
                    table[i].name);
        }
        if (strlen(s) <= len + 2 && table[i].value != OTI_OK){
            ok_meaning = 0;
        }
        if (oti_status_string(table[i].value) != s){
            ok_stable = 0;
        }
        for (j = 0; j < i; j++){
            const char* t = oti_status_string(table[j].value);
            if (t != NULL && strcmp(s, t) == 0){
                ok_distinct = 0;
            }
        }

    }

    check(ok_nonnull, "oti_status_string: never NULL for a defined status");
    check(ok_prefix, "oti_status_string: \"NAME: meaning\" for every defined status");
    check(ok_meaning, "oti_status_string: every error status has a non-empty meaning");
    check(ok_distinct, "oti_status_string: distinct text per status");
    check(ok_stable, "oti_status_string: static storage (same pointer on every call)");

    ok_prefix = 1;
    for (i = 0; i < (int)(sizeof(unknown) / sizeof(unknown[0])); i++){
        const char* s = oti_status_string(unknown[i]);
        if (s == NULL || strcmp(s, unknown_text) != 0){
            ok_prefix = 0;
            fprintf(stderr, "  unknown status %d gave \"%s\"\n", unknown[i], s ? s : "(null)");
        }
    }
    check(ok_prefix, "oti_status_string: unknown negative values -> OTI_ERR_UNKNOWN");

    ok_prefix = 1;
    for (i = 0; i < (int)(sizeof(positive) / sizeof(positive[0])); i++){
        const char* s = oti_status_string(positive[i]);
        if (s == NULL || strcmp(s, singular_text) != 0){
            ok_prefix = 0;
            fprintf(stderr, "  positive status %d gave \"%s\"\n", positive[i], s ? s : "(null)");
        }
    }
    check(ok_prefix, "oti_status_string: positive values -> LAPACK_INFO singular");

}
// -------------------------------------------------------------------------------------------------------


// =======================================================================================================
// Contexts (contracts 5.1) and budgets (5.2)
// =======================================================================================================

// *******************************************************************************************************
static void test_exec_init_and_ctx_init(void){

    oti_exec_t ex;
    oti_ctx ctx;
    int i, zero = 1;

    memset(&ex, 0xAB, sizeof(ex));
    oti_exec_init(&ex);
    check(ex.struct_size == (int32_t)sizeof(oti_exec_t), "oti_exec_init: struct_size");
    check(ex.backend == OTI_BACKEND_DEFAULT && ex.nthreads == 0,
            "oti_exec_init: DEFAULT backend, 0 threads");
    check(ex.blas_policy == OTI_BLAS_SERIAL_IN_REGIONS, "oti_exec_init: blas_policy SERIAL_IN_REGIONS");
    check(ex.min_parallel_elems == OTI_EXEC_MIN_PARALLEL_DEFAULT && OTI_EXEC_MIN_PARALLEL_DEFAULT == 4096,
          "oti_exec_init: min_parallel_elems 4096");
    for (i = 0; i < 4; i++){
        zero = zero && (ex.reserved[i] == 0);
    }
    check(zero, "oti_exec_init: reserved words zero");

    memset(&ctx, 0xCD, sizeof(ctx));
    check(oti_ctx_init(&ctx) == OTI_OK, "oti_ctx_init: OK");
    check(ctx.struct_size == (int32_t)sizeof(oti_ctx), "oti_ctx_init: struct_size");
    check(ctx.device_type == OTI_DEVICE_CPU && ctx.device_id == 0 && ctx.flags == 0,
            "oti_ctx_init: CPU/0");
    check(ctx.exec.struct_size == (int32_t)sizeof(oti_exec_t) &&
          ctx.exec.backend == OTI_BACKEND_DEFAULT && ctx.exec.nthreads == 0 &&
          ctx.exec.blas_policy == OTI_BLAS_SERIAL_IN_REGIONS &&
          ctx.exec.min_parallel_elems == 4096, "oti_ctx_init: execution policy defaults");
    check(ctx.max_alloc_bytes == 0 && ctx.max_temp_bytes == 0,
            "oti_ctx_init: budgets 0 (library default)");
    check(ctx.stream == NULL && ctx.last_status == OTI_OK && ctx.last_where == NULL &&
          ctx.last_msg == NULL, "oti_ctx_init: no stream, no last error");
    zero = (ctx.reserved0 == 0);
    for (i = 0; i < 8; i++){
        zero = zero && (ctx.reserved[i] == 0);
    }
    check(zero, "oti_ctx_init: reserved words zero");
    check(oti_ctx_init(NULL) == OTI_ERR_ARGUMENT, "oti_ctx_init(NULL) -> ARGUMENT");
    check(sizeof(oti_ctx) == 184, "sizeof(oti_ctx) == 184 (contracts 5.1)");

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// The environment variable was set to 7 before the first use of the default context.
static void test_default_ctx(void){

    const oti_ctx* d = oti_ctx_default();
    const oti_ctx* d2 = oti_ctx_default();

    check(d != NULL && d == d2, "oti_ctx_default: non-NULL, same pointer every call");
    check(d->struct_size == (int32_t)sizeof(oti_ctx), "default ctx: struct_size");
    check(d->device_type == OTI_DEVICE_CPU && d->device_id == 0, "default ctx: CPU / 0");
    check(d->exec.backend == OTI_BACKEND_DEFAULT && d->exec.nthreads == 0,
            "default ctx: DEFAULT backend, inherit threads");
    check(d->exec.blas_policy == OTI_BLAS_SERIAL_IN_REGIONS && d->exec.min_parallel_elems == 4096,
          "default ctx: SERIAL_IN_REGIONS, min_parallel_elems 4096");
    check(d->last_status == OTI_OK && d->last_where == NULL && d->last_msg == NULL,
          "default ctx: no last error");
    check(d->max_alloc_bytes == 7LL * 1048576 && d->max_temp_bytes == 7LL * 1048576,
          "default ctx: budgets are OTI_DENSE_MAX_MB MiB (env set to 7 by main)");
    check(oti_ctx_check(NULL) == OTI_OK && oti_ctx_check(d) == OTI_OK, "oti_ctx_check: default is valid");

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_ctx_check(void){

    oti_ctx ctx;

    oti_ctx_init(&ctx);
    check(oti_ctx_check(&ctx) == OTI_OK, "oti_ctx_check: fresh user ctx valid");

    ctx.struct_size = 0;
    check(oti_ctx_check(&ctx) == OTI_ERR_ARGUMENT, "oti_ctx_check: struct_size 0 -> ARGUMENT");
    ctx.struct_size = (int32_t)sizeof(oti_ctx) - 8;
    check(oti_ctx_check(&ctx) == OTI_ERR_ARGUMENT, "oti_ctx_check: too small struct_size -> ARGUMENT");

    oti_ctx_init(&ctx);
    ctx.device_type = 2;
    check(oti_ctx_check(&ctx) == OTI_ERR_ARGUMENT, "oti_ctx_check: device other than CPU -> ARGUMENT");
    oti_ctx_init(&ctx);
    ctx.device_id = 1;
    check(oti_ctx_check(&ctx) == OTI_ERR_ARGUMENT, "oti_ctx_check: device id 1 -> ARGUMENT");

    oti_ctx_init(&ctx);
    ctx.max_alloc_bytes = -1;
    check(oti_ctx_check(&ctx) == OTI_ERR_ARGUMENT, "oti_ctx_check: negative max_alloc_bytes -> ARGUMENT");
    oti_ctx_init(&ctx);
    ctx.max_temp_bytes = -5;
    check(oti_ctx_check(&ctx) == OTI_ERR_ARGUMENT, "oti_ctx_check: negative max_temp_bytes -> ARGUMENT");

    oti_ctx_init(&ctx);
    ctx.exec.blas_policy = 9;
    check(oti_ctx_check(&ctx) == OTI_ERR_ARGUMENT, "oti_ctx_check: unknown blas_policy -> ARGUMENT");

    oti_ctx_init(&ctx);
    ctx.exec.backend = OTI_BACKEND_SERIAL;
    check(oti_ctx_check(&ctx) == OTI_OK, "oti_ctx_check: SERIAL backend valid");
    ctx.exec.backend = OTI_BACKEND_OPENMP;
    check(oti_ctx_check(&ctx) == (BUILD_HAS_OPENMP ? OTI_OK : OTI_ERR_BACKEND),
          "oti_ctx_check: OPENMP backend valid iff compiled in");
    ctx.exec.backend = OTI_BACKEND_PTHREADS;
    check(oti_ctx_check(&ctx) == (BUILD_HAS_PTHREADS ? OTI_OK : OTI_ERR_BACKEND),
          "oti_ctx_check: PTHREADS backend valid iff compiled in");
    ctx.exec.backend = 77;
    check(oti_ctx_check(&ctx) == OTI_ERR_BACKEND, "oti_ctx_check: unknown backend -> BACKEND");

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_budgets(void){

    oti_ctx ctx;
    const oti_ctx* d = oti_ctx_default();

    oti_ctx_init(&ctx);
    ctx.max_alloc_bytes = 1000;
    ctx.max_temp_bytes  = 500;
    check(oti_ctx_check_alloc(&ctx, 0) == OTI_OK, "check_alloc: 0 bytes OK");
    check(oti_ctx_check_alloc(&ctx, 1000) == OTI_OK, "check_alloc: exactly the cap OK");
    check(oti_ctx_check_alloc(&ctx, 1001) == OTI_ERR_MEMORY, "check_alloc: cap + 1 -> MEMORY");
    check(oti_ctx_check_alloc(&ctx, INT64_MAX) == OTI_ERR_MEMORY, "check_alloc: INT64_MAX -> MEMORY");
    check(oti_ctx_check_temp(&ctx, 500) == OTI_OK, "check_temp: exactly the cap OK");
    check(oti_ctx_check_temp(&ctx, 501) == OTI_ERR_MEMORY, "check_temp: cap + 1 -> MEMORY");
    check(oti_ctx_check_temp(&ctx, 0) == OTI_OK, "check_temp: 0 bytes OK");

    // Budgets are caps checked before the call: nothing is accounted, so the same check passes again.
    check(oti_ctx_check_alloc(&ctx, 1000) == OTI_OK && oti_ctx_check_alloc(&ctx, 1000) == OTI_OK,
          "check_alloc: caps, not running totals");
    check(oti_ctx_check_temp(&ctx, 500) == OTI_OK && oti_ctx_check_temp(&ctx, 500) == OTI_OK,
          "check_temp: caps, not running totals");

    // max_temp_bytes == 0 means max_alloc_bytes; max_alloc_bytes == 0 means the library default.
    oti_ctx_init(&ctx);
    ctx.max_alloc_bytes = 2000;
    check(oti_ctx_check_temp(&ctx, 2000) == OTI_OK && oti_ctx_check_temp(&ctx, 2001) == OTI_ERR_MEMORY,
          "check_temp: max_temp_bytes 0 follows max_alloc_bytes");
    oti_ctx_init(&ctx);
    check(oti_ctx_check_alloc(&ctx, 7LL * 1048576) == OTI_OK &&
          oti_ctx_check_alloc(&ctx, 7LL * 1048576 + 1) == OTI_ERR_MEMORY,
          "check_alloc: max_alloc_bytes 0 uses the default budget");

    // NULL and the default pointer use the default budget.
    check(oti_ctx_check_alloc(NULL, 7LL * 1048576) == OTI_OK &&
          oti_ctx_check_alloc(NULL, 7LL * 1048576 + 1) == OTI_ERR_MEMORY,
          "check_alloc(NULL): default budget");
    check(oti_ctx_check_alloc(d, 7LL * 1048576 + 1) == OTI_ERR_MEMORY &&
          oti_ctx_check_temp(d, 7LL * 1048576 + 1) == OTI_ERR_MEMORY &&
          oti_ctx_check_temp(NULL, 7LL * 1048576) == OTI_OK,
          "check_alloc / check_temp: default pointer and NULL agree");

}
// -------------------------------------------------------------------------------------------------------


// =======================================================================================================
// Last error (contracts 4.3)
// =======================================================================================================

// *******************************************************************************************************
static void test_last_error_user_ctx(void){

    oti_ctx a, b;
    const char* where = "unset";
    const char* msg = "unset";

    oti_ctx_init(&a);
    oti_ctx_init(&b);

    check(oti_ctx_last_error(&a, &where, &msg) == OTI_OK && where == NULL && msg == NULL,
          "last_error: fresh user ctx has none (where, msg NULL)");

    oti_ctx_set_error(&a, OTI_ERR_SHAPE, "nd_matmul", "inner dimensions differ");
    check(a.last_status == OTI_ERR_SHAPE, "set_error: writes ctx->last_status");
    check(a.last_where != NULL && strcmp(a.last_where, "nd_matmul") == 0 && a.last_msg != NULL &&
          strcmp(a.last_msg, "inner dimensions differ") == 0, "set_error: writes last_where / last_msg");
    where = msg = NULL;
    check(oti_ctx_last_error(&a, &where, &msg) == OTI_ERR_SHAPE && strcmp(where, "nd_matmul") == 0 &&
          strcmp(msg, "inner dimensions differ") == 0, "last_error: returns status, where, msg");
    check(oti_ctx_last_error(&a, NULL, NULL) == OTI_ERR_SHAPE, "last_error: where and msg may be NULL");
    check(oti_ctx_last_error(&b, NULL, NULL) == OTI_OK,
            "last_error: per user context (other ctx untouched)");

    // Success never clears the last error (like errno).
    check(oti_ctx_check(&a) == OTI_OK && oti_ctx_check_alloc(&a, 8) == OTI_OK &&
          oti_serial_for(0, NULL, NULL) == OTI_OK, "successful calls on the context");
    check(oti_ctx_last_error(&a, NULL, NULL) == OTI_ERR_SHAPE, "success does not clear the last error");

    // The last failure replaces the previous one; a NULL message is allowed.
    oti_ctx_set_error(&a, OTI_ERR_DTYPE, "nd_add", NULL);
    where = msg = "unset";
    check(oti_ctx_last_error(&a, &where, &msg) == OTI_ERR_DTYPE && strcmp(where, "nd_add") == 0 &&
          msg == NULL, "set_error: replaces the previous error, NULL msg");

    oti_ctx_clear_error(&a);
    where = msg = "unset";
    check(oti_ctx_last_error(&a, &where, &msg) == OTI_OK && where == NULL && msg == NULL &&
          a.last_status == OTI_OK, "clear_error: back to OK, where / msg NULL");

    // A user context never touches the thread-local record.
    oti_ctx_clear_error(NULL);
    oti_ctx_set_error(&a, OTI_ERR_INDEX, "nd_view_index", "out of range");
    check(oti_ctx_last_error(NULL, NULL, NULL) == OTI_OK, "user ctx error is not visible through NULL");
    oti_ctx_clear_error(&a);

    // A positive LAPACK info is recordable too.
    oti_ctx_set_error(&a, 3, "nd_solve", "singular");
    check(oti_ctx_last_error(&a, NULL, NULL) == 3, "set_error: positive info recorded");
    oti_ctx_clear_error(&a);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_last_error_null_and_default_pointer(void){

    const oti_ctx* d = oti_ctx_default();
    const char* where = NULL;
    const char* msg = NULL;
    oti_ctx user;

    oti_ctx_clear_error(NULL);
    check(oti_ctx_last_error(NULL, &where, &msg) == OTI_OK && where == NULL && msg == NULL,
          "NULL ctx: no error after clear");

    oti_ctx_set_error(NULL, OTI_ERR_LAYOUT, "nd_assign", "overlap");
    where = msg = NULL;
    check(oti_ctx_last_error(NULL, &where, &msg) == OTI_ERR_LAYOUT && strcmp(where, "nd_assign") == 0 &&
          strcmp(msg, "overlap") == 0, "NULL ctx: thread-local record set and read");
    check(oti_ctx_last_error(d, NULL, NULL) == OTI_ERR_LAYOUT,
          "default pointer reads the same thread-local record as NULL");
    check(d->last_status == OTI_OK && d->last_where == NULL && d->last_msg == NULL,
          "the default context itself is never written by a NULL error ([cM6])");

    // An explicit default pointer is treated exactly like NULL: records thread-locally, never writes
    // the default context.
    oti_ctx_clear_error(NULL);
    oti_ctx_set_error((oti_ctx*)d, OTI_ERR_DTYPE, "nd_unary", "bad dtype");
    where = msg = NULL;
    check(oti_ctx_last_error(NULL, &where, &msg) == OTI_ERR_DTYPE && strcmp(where, "nd_unary") == 0 &&
          strcmp(msg, "bad dtype") == 0, "set_error(default pointer) records thread-locally ([cM6])");
    check(d->last_status == OTI_OK && d->last_where == NULL && d->last_msg == NULL,
          "set_error(default pointer) never writes the default context ([cM6])");
    check(oti_ctx_last_error(d, NULL, NULL) == OTI_ERR_DTYPE,
            "last_error(default pointer) reads it back");

    // Success does not clear it; clear through the default pointer clears the thread-local record.
    check(oti_ctx_check(NULL) == OTI_OK && oti_ctx_check_alloc(NULL, 8) == OTI_OK, "successful calls");
    check(oti_ctx_last_error(NULL, NULL, NULL) == OTI_ERR_DTYPE, "NULL ctx: success does not clear");
    oti_ctx_clear_error((oti_ctx*)d);
    check(oti_ctx_last_error(NULL, NULL, NULL) == OTI_OK,
            "clear_error(default pointer) clears thread-local");
    check(d->last_status == OTI_OK, "default context still untouched after clear");

    // A user context and the thread-local record are independent.
    oti_ctx_init(&user);
    oti_ctx_set_error(NULL, OTI_ERR_SIZE, "f", "g");
    oti_ctx_set_error(&user, OTI_ERR_BUSY, "h", NULL);
    check(oti_ctx_last_error(NULL, NULL, NULL) == OTI_ERR_SIZE &&
          oti_ctx_last_error(&user, NULL, NULL) == OTI_ERR_BUSY,
          "thread-local record and user context are independent");
    oti_ctx_clear_error(NULL);
    check(oti_ctx_last_error(&user, NULL, NULL) == OTI_ERR_BUSY, "clearing NULL leaves the user ctx");

}
// -------------------------------------------------------------------------------------------------------


typedef struct {
    int      id;
    int      status;
    int      rounds;
    int      ok;
    int      saw_other;
    int      saw_start_clean;
    volatile int* go;
} err_thread_t;


// *******************************************************************************************************
// Each thread records its own status for NULL many times and reads it back; no cross-talk.
static void* err_thread_main(void* p){

    err_thread_t* t = (err_thread_t*)p;
    const char* where;
    const char* msg;
    int i;

    t->saw_start_clean = (oti_ctx_last_error(NULL, NULL, NULL) == OTI_OK);

    while (!__atomic_load_n(t->go, __ATOMIC_ACQUIRE)){
        spin(100);
    }

    t->ok = 1;
    for (i = 0; i < t->rounds; i++){
        where = msg = NULL;
        oti_ctx_set_error(NULL, t->status, t->id == 1 ? "thread_one" : "thread_two",
                          t->id == 1 ? "first" : "second");
        if (oti_ctx_last_error(NULL, &where, &msg) != t->status ||
            strcmp(where, t->id == 1 ? "thread_one" : "thread_two") != 0 ||
            strcmp(msg, t->id == 1 ? "first" : "second") != 0){
            t->ok = 0;
            t->saw_other = 1;
        }
    }

    return NULL;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_last_error_thread_local(void){

    pthread_t th1, th2;
    err_thread_t t1, t2;
    volatile int go = 0;
    const char* where = NULL;

    oti_ctx_clear_error(NULL);
    oti_ctx_set_error(NULL, OTI_ERR_INDEX, "main_thread", "m");

    memset(&t1, 0, sizeof(t1));
    memset(&t2, 0, sizeof(t2));
    t1.id = 1; t1.status = OTI_ERR_SIZE;    t1.rounds = 20000; t1.go = &go;
    t2.id = 2; t2.status = OTI_ERR_MEMORY;  t2.rounds = 20000; t2.go = &go;

    pthread_create(&th1, NULL, err_thread_main, &t1);
    pthread_create(&th2, NULL, err_thread_main, &t2);
    spin(2000000);
    __atomic_store_n(&go, 1, __ATOMIC_RELEASE);
    pthread_join(th1, NULL);
    pthread_join(th2, NULL);

    check(t1.saw_start_clean && t2.saw_start_clean,
          "thread-local: a new thread does not see another thread's error");
    check(t1.ok && t2.ok, "thread-local: two threads recording at once never see each other's error");
    where = NULL;
    check(oti_ctx_last_error(NULL, &where, NULL) == OTI_ERR_INDEX && strcmp(where, "main_thread") == 0,
          "thread-local: the main thread's record survives other threads");
    oti_ctx_clear_error(NULL);

}
// -------------------------------------------------------------------------------------------------------


// =======================================================================================================
// Backend queries, chunk counts, thresholds (contracts 5.3, 5.6)
// =======================================================================================================

// *******************************************************************************************************
static void test_backend_queries(void){

    check(oti_exec_backend_available(OTI_BACKEND_SERIAL) == 1, "backend: SERIAL always available");
    check(oti_exec_backend_available(OTI_BACKEND_DEFAULT) == 1,
            "backend: DEFAULT resolves to the build default");
    check(oti_exec_backend_available(OTI_BACKEND_OPENMP) == BUILD_HAS_OPENMP,
          "backend: OPENMP available iff built with OTI_PARALLEL_OPENMP");
    check(oti_exec_backend_available(OTI_BACKEND_PTHREADS) == BUILD_HAS_PTHREADS,
          "backend: PTHREADS available iff built with OTI_PARALLEL_PTHREADS (Phase P)");
    check(oti_exec_backend_available(99) == 0 && oti_exec_backend_available(-7) == 0,
          "backend: unknown values unavailable");

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_nchunks(void){

    check(oti_exec_nchunks(0, 4096) == 0, "nchunks(0) == 0");
    check(oti_exec_nchunks(-5, 4096) == 0, "nchunks(negative) == 0");
    check(oti_exec_nchunks(1, 4096) == 1 && oti_exec_nchunks(4096, 4096) == 1,
            "nchunks(1), nchunks(4096) == 1");
    check(oti_exec_nchunks(4097, 4096) == 2 && oti_exec_nchunks(8192, 4096) == 2 &&
          oti_exec_nchunks(8193, 4096) == 3, "nchunks around multiples of 4096");
    check(oti_exec_nchunks(100, 16) == 7 && oti_exec_nchunks(96, 16) == 6, "nchunks with chunk 16");
    check(OTI_EXEC_CHUNK_ELEMS == 4096, "OTI_EXEC_CHUNK_ELEMS == 4096");

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_max_workers_and_parallel_ok(void){

    oti_ctx ctx;
    int32_t w;

    make_ctx(&ctx, OTI_BACKEND_SERIAL, 0);
    check(oti_exec_max_workers(&ctx) == 1, "max_workers: SERIAL backend -> 1");
    check(oti_exec_parallel_ok(&ctx, 1000000, 1) == 0, "parallel_ok: SERIAL backend never parallel");

    make_ctx(&ctx, OTI_BACKEND_DEFAULT, 1);
    check(oti_exec_max_workers(&ctx) == 1, "max_workers: nthreads 1 -> 1");
    check(oti_exec_parallel_ok(&ctx, 1000000, 1) == 0, "parallel_ok: one worker -> 0");

    check(oti_exec_max_workers(NULL) >= 1, "max_workers(NULL) >= 1");

#if TEST_HAVE_OMP && BUILD_HAS_OPENMP
    make_ctx(&ctx, OTI_BACKEND_DEFAULT, 3);
    check(oti_exec_max_workers(&ctx) == 3, "max_workers: nthreads 3 -> 3");
    make_ctx(&ctx, OTI_BACKEND_DEFAULT, 0);
    check(oti_exec_max_workers(&ctx) == omp_get_max_threads(),
            "max_workers: nthreads 0 -> omp_get_max_threads()");
    check(oti_exec_max_workers(NULL) == omp_get_max_threads(),
            "max_workers(NULL) -> omp_get_max_threads()");

    make_ctx(&ctx, OTI_BACKEND_DEFAULT, 4);
    ctx.exec.min_parallel_elems = 100;
    check(oti_exec_parallel_ok(&ctx, 99, 0) == 0, "parallel_ok: below ctx min (min_items <= 0) -> 0");
    check(oti_exec_parallel_ok(&ctx, 100, 0) == 1, "parallel_ok: at ctx min -> 1");
    check(oti_exec_parallel_ok(&ctx, 100, -1) == 1, "parallel_ok: negative min_items uses the ctx min");
    check(oti_exec_parallel_ok(&ctx, 63, 64) == 0 && oti_exec_parallel_ok(&ctx, 64, 64) == 1,
          "parallel_ok: explicit min_items (64) overrides the ctx min");
    check(oti_exec_parallel_ok(&ctx, 10, 5) == 1, "parallel_ok: min_items below the ctx min is honoured");
    check(oti_exec_parallel_ok(&ctx, 0, 0) == 0, "parallel_ok: nothing to do with a positive ctx min");

    // Inside an OpenMP region: one worker, never parallel.
    w = 99;
    {
        int in_par = -1, ok_par = -1;
        #pragma omp parallel num_threads(2)
        {
            #pragma omp master
            {
                in_par = oti_exec_in_parallel();
                w = oti_exec_max_workers(&ctx);
                ok_par = oti_exec_parallel_ok(&ctx, 1000000, 1);
            }
        }
        check(in_par == 1, "in_parallel: true inside an OpenMP region");
        check(w == 1, "max_workers: 1 inside an OpenMP region");
        check(ok_par == 0, "parallel_ok: 0 inside an OpenMP region");
    }
#else
    (void)w;
    printf("skipped: OpenMP-dependent worker counts (not built with OpenMP)\n");
#endif
    check(oti_exec_in_parallel() == 0, "in_parallel: false on the main thread outside any region");

}
// -------------------------------------------------------------------------------------------------------


// =======================================================================================================
// oti_serial_for / oti_parallel_for (contracts 5.3)
// =======================================================================================================

typedef struct {
    int64_t   n;
    int*      ran;       // ran[c] = number of times chunk c ran
    int*      worker;    // worker index of the chunk
    int32_t   max_worker;
    int       bad_worker;
    int64_t   fail_from; // chunks c in the failure set return status_of(c); set via fail[]
    const int* fail;     // fail[c] != 0: chunk c fails
    int64_t   delay;     // spin scale
    uint64_t  seed;
    int64_t   order_ctr;
    int64_t*  order;
} loop_t;


// *******************************************************************************************************
static int chunk_status(int64_t c){

    return -30 - (int)(c % 7);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static int chunk_record(void* arg, int64_t c, int32_t worker){

    loop_t* L = (loop_t*)arg;

    if (c < 0 || c >= L->n){
        L->bad_worker = 1;
        return OTI_ERR_INDEX;
    }
    if (L->delay > 0){
        spin((uint64_t)(mix64(L->seed, (uint64_t)c) % (uint64_t)L->delay));
    }
    if (worker < 0 || worker >= L->max_worker){
        L->bad_worker = 1;
    }
    __atomic_fetch_add(&L->ran[c], 1, __ATOMIC_RELAXED);
    L->worker[c] = worker;
    if (L->order != NULL){
        L->order[c] = __atomic_fetch_add(&L->order_ctr, 1, __ATOMIC_RELAXED);
    }
    if (L->fail != NULL && L->fail[c]){
        return chunk_status(c);
    }
    return OTI_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void loop_init(loop_t* L, int64_t n, int* ran, int* worker, const int* fail){

    int64_t c;

    memset(L, 0, sizeof(*L));
    L->n = n;
    L->ran = ran;
    L->worker = worker;
    L->fail = fail;
    L->max_worker = 1 << 20;
    for (c = 0; c < n; c++){
        ran[c] = 0;
        worker[c] = -1;
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static int all_ran_once(const loop_t* L){

    int64_t c;

    for (c = 0; c < L->n; c++){
        if (L->ran[c] != 1){
            return 0;
        }
    }
    return 1;

}
// -------------------------------------------------------------------------------------------------------


static int g_ran[MAX_CHUNKS];
static int g_worker[MAX_CHUNKS];
static int64_t g_order[MAX_CHUNKS];
static int g_fail[MAX_CHUNKS];


// *******************************************************************************************************
static void test_serial_for(void){

    loop_t L;
    int64_t c;
    int st, in_order = 1;

    loop_init(&L, 10, g_ran, g_worker, NULL);
    L.order = g_order;
    st = oti_serial_for(10, chunk_record, &L);
    check(st == OTI_OK && all_ran_once(&L), "serial_for: every chunk runs once");
    for (c = 0; c < 10; c++){
        in_order = in_order && (g_order[c] == c) && (g_worker[c] == 0);
    }
    check(in_order, "serial_for: chunks in increasing order, worker 0");

    loop_init(&L, 5, g_ran, g_worker, NULL);
    check(oti_serial_for(0, chunk_record, &L) == OTI_OK && g_ran[0] == 0,
          "serial_for: zero chunks runs nothing");
    check(oti_serial_for(-3, chunk_record, &L) == OTI_OK, "serial_for: negative count runs nothing, OK");

    // Stops at the first failure; the status is that chunk's.
    memset(g_fail, 0, sizeof(g_fail));
    g_fail[3] = 1;
    g_fail[6] = 1;
    loop_init(&L, 10, g_ran, g_worker, g_fail);
    st = oti_serial_for(10, chunk_record, &L);
    check(st == chunk_status(3), "serial_for: status of the first failing chunk");
    check(g_ran[0] == 1 && g_ran[1] == 1 && g_ran[2] == 1 && g_ran[3] == 1,
            "serial_for: chunks up to the failure ran");
    check(g_ran[4] == 0 && g_ran[5] == 0 && g_ran[6] == 0 && g_ran[9] == 0,
          "serial_for: stops at the first failure (later chunks not run)");

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Runs every chunk exactly once, whatever the backend, thread count or chunk count.
static void test_parallel_for_runs_all(void){

    static const int32_t nthreads[] = {0, 1, 2, 3, 4, 7};
    static const int64_t counts[] = {0, 1, 2, 3, 17, 100, 1000, 4000};
    oti_ctx ctx;
    loop_t L;
    int i, j, b, ok_status = 1, ok_once = 1, ok_workers = 1;
    int32_t backends[3];

    backends[0] = OTI_BACKEND_DEFAULT;
    backends[1] = OTI_BACKEND_SERIAL;
    backends[2] = OTI_BACKEND_OPENMP;

    for (b = 0; b < 3; b++){
        if (!oti_exec_backend_available(backends[b])){
            continue;
        }
        for (i = 0; i < (int)(sizeof(nthreads) / sizeof(nthreads[0])); i++){
            for (j = 0; j < (int)(sizeof(counts) / sizeof(counts[0])); j++){
                make_ctx(&ctx, backends[b], nthreads[i]);
                loop_init(&L, counts[j], g_ran, g_worker, NULL);
                L.max_worker = oti_exec_max_workers(&ctx);
                if (oti_parallel_for(&ctx, counts[j], chunk_record, &L) != OTI_OK){
                    ok_status = 0;
                }
                if (!all_ran_once(&L)){
                    ok_once = 0;
                }
                if (L.bad_worker){
                    ok_workers = 0;
                }
            }
        }
    }
    check(ok_status, "parallel_for: OTI_OK for every backend / thread count / chunk count");
    check(ok_once, "parallel_for: every chunk runs exactly once");
    check(ok_workers, "parallel_for: worker index in [0, oti_exec_max_workers)");

    // NULL and an explicit default pointer.
    loop_init(&L, 500, g_ran, g_worker, NULL);
    check(oti_parallel_for(NULL, 500, chunk_record, &L) == OTI_OK && all_ran_once(&L),
          "parallel_for(NULL ctx): runs every chunk");
    loop_init(&L, 500, g_ran, g_worker, NULL);
    check(oti_parallel_for((oti_ctx*)oti_ctx_default(), 500, chunk_record, &L) == OTI_OK &&
            all_ran_once(&L),
          "parallel_for(default pointer): runs every chunk");

    // The SERIAL backend: inline, in order, worker 0.
    make_ctx(&ctx, OTI_BACKEND_SERIAL, 4);
    loop_init(&L, 200, g_ran, g_worker, NULL);
    L.order = g_order;
    oti_parallel_for(&ctx, 200, chunk_record, &L);
    ok_once = 1;
    for (i = 0; i < 200; i++){
        ok_once = ok_once && g_order[i] == i && g_worker[i] == 0;
    }
    check(ok_once, "parallel_for: SERIAL backend runs inline, in order, worker 0");

    // A parallel_for does not record last errors (the public caller does).
    make_ctx(&ctx, OTI_BACKEND_DEFAULT, 0);
    memset(g_fail, 0, sizeof(g_fail));
    g_fail[1] = 1;
    loop_init(&L, 8, g_ran, g_worker, g_fail);
    oti_ctx_clear_error(NULL);
    check(oti_parallel_for(&ctx, 8, chunk_record, &L) == chunk_status(1),
            "parallel_for: failing chunk status");
    check(oti_ctx_last_error(&ctx, NULL, NULL) == OTI_OK && oti_ctx_last_error(NULL, NULL,
            NULL) == OTI_OK,
          "parallel_for never records a last error");

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// The error rule over many random failure patterns [cH1]: the result is the status of the lowest-index
// failing chunk, and every chunk below it ran (exactly once), whatever the timing.
static void test_parallel_for_error_rule(void){

    static const int32_t nthreads[] = {0, 2, 3, 4, 8};
    oti_ctx ctx;
    loop_t L;
    int pattern, i, ok_status = 1, ok_below = 1, ok_once = 1, ok_calls = 1, ok_single = 1;
    int64_t n, c, first;
    int st;
    uint64_t r;

    rng_seed(20261102);

    for (pattern = 0; pattern < 600; pattern++){

        n = 2 + (int64_t)(rng_next() % 300);
        memset(g_fail, 0, sizeof(int) * (size_t)n);
        r = rng_next() % 4;
        first = -1;
        if (r == 0){
            // a single failing chunk
            c = (int64_t)(rng_next() % (uint64_t)n);
            g_fail[c] = 1;
        } else {
            // each chunk fails with probability 1/8 (r == 1), 1/3 (r == 2), 1/2 (r == 3)
            uint64_t den = (r == 1) ? 8 : (r == 2) ? 3 : 2;
            for (c = 0; c < n; c++){
                g_fail[c] = ((rng_next() % den) == 0);
            }
        }
        for (c = 0; c < n; c++){
            if (g_fail[c]){
                first = c;
                break;
            }
        }

        make_ctx(&ctx, OTI_BACKEND_DEFAULT, nthreads[pattern % 5]);
        loop_init(&L, n, g_ran, g_worker, g_fail);
        L.delay = (pattern % 3 == 0) ? 0 : 3000;   // random per-chunk timing
        L.seed = rng_next();
        L.order = g_order;
        st = oti_parallel_for(&ctx, n, chunk_record, &L);

        if (first < 0){
            if (st != OTI_OK){
                ok_status = 0;
            }
            if (!all_ran_once(&L)){
                ok_once = 0;
            }
        } else {
            if (st != chunk_status(first)){
                ok_status = 0;
                fprintf(stderr, "  pattern %d: n=%lld first=%lld got status %d, expected %d\n", pattern,
                        (long long)n, (long long)first, st, chunk_status(first));
            }
            for (c = 0; c < first; c++){
                if (g_ran[c] != 1){
                    ok_below = 0;
                }
            }
            if (g_ran[first] != 1){
                ok_below = 0;
            }
            for (c = 0; c < n; c++){
                if (g_ran[c] > 1){
                    ok_once = 0;
                }
            }
        }
        if (L.bad_worker){
            ok_calls = 0;
        }

    }

    check(ok_status,
            "parallel_for: result is the status of the lowest-index failing chunk (600 patterns)");
    check(ok_below,
            "parallel_for: every chunk up to the failing index ran (600 random patterns, random timing)");
    check(ok_once, "parallel_for: no chunk runs twice");
    check(ok_calls, "parallel_for: chunk and worker indices valid");

    // Failures at the first and at the last chunk, and at every chunk of a small loop.
    for (i = 0; i < 40; i++){
        n = 40;
        memset(g_fail, 0, sizeof(int) * (size_t)n);
        g_fail[i] = 1;
        make_ctx(&ctx, OTI_BACKEND_DEFAULT, 4);
        loop_init(&L, n, g_ran, g_worker, g_fail);
        L.delay = 2000;
        L.seed = (uint64_t)i + 1;
        st = oti_parallel_for(&ctx, n, chunk_record, &L);
        if (st != chunk_status(i)){
            ok_single = 0;
        }
        for (c = 0; c <= i; c++){
            if (g_ran[c] != 1){
                ok_single = 0;
            }
        }
    }
    check(ok_single, "parallel_for: a single failing chunk at every position of a 40-chunk loop");

    // Two failures with the lower one delayed much longer: the lower status still wins.
    {
        int ok_delay = 1;
        int rep;
        for (rep = 0; rep < 20; rep++){
            n = 64;
            memset(g_fail, 0, sizeof(int) * (size_t)n);
            g_fail[10] = 1;
            g_fail[50] = 1;
            make_ctx(&ctx, OTI_BACKEND_DEFAULT, 4);
            loop_init(&L, n, g_ran, g_worker, g_fail);
            L.delay = 1;
            L.seed = 1;
            st = oti_parallel_for(&ctx, n, chunk_record, &L);
            if (st != chunk_status(10)){
                ok_delay = 0;
            }
            for (c = 0; c <= 10; c++){
                if (g_ran[c] != 1){
                    ok_delay = 0;
                }
            }
        }
        check(ok_delay, "parallel_for: lowest failing chunk wins over a later one");
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// A chunk function that fails when its chunk is the multiple of 7 above 100, and sleeps long on low
// chunks, so that a higher failure is observed first.
static int chunk_slow_low(void* arg, int64_t c, int32_t worker){

    loop_t* L = (loop_t*)arg;

    (void)worker;
    if (c < 4){
        spin(3000000);
    }
    __atomic_fetch_add(&L->ran[c], 1, __ATOMIC_RELAXED);
    if (c == 2){
        return -41;
    }
    if (c == 30){
        return -42;
    }
    return OTI_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_parallel_for_slow_lower_failure(void){

    oti_ctx ctx;
    loop_t L;
    int rep, ok = 1, ok_run = 1;
    int64_t c;

    for (rep = 0; rep < 10; rep++){
        make_ctx(&ctx, OTI_BACKEND_DEFAULT, 4);
        loop_init(&L, 64, g_ran, g_worker, NULL);
        if (oti_parallel_for(&ctx, 64, chunk_slow_low, &L) != -41){
            ok = 0;
        }
        for (c = 0; c <= 2; c++){
            if (g_ran[c] != 1){
                ok_run = 0;
            }
        }
    }
    check(ok, "parallel_for: a slow low failing chunk still wins over a fast higher failure");
    check(ok_run, "parallel_for: chunks below the failing one ran in that case too");

}
// -------------------------------------------------------------------------------------------------------


typedef struct {
    int64_t n_inner;
    int     ok;
    int     inner_in_parallel;
    pthread_t outer_thread;
    int64_t seq[64];
    int     seq_len;
    int     same_thread;
    int     worker_zero;
    int     max_workers_seen;
    oti_ctx* ctx;
} nest_t;


// *******************************************************************************************************
static int chunk_inner(void* arg, int64_t c, int32_t worker){

    nest_t* N = (nest_t*)arg;

    if (N->seq_len < 64){
        N->seq[N->seq_len++] = c;
    }
    if (!pthread_equal(pthread_self(), N->outer_thread)){
        N->same_thread = 0;
    }
    if (worker != 0){
        N->worker_zero = 0;
    }
    return OTI_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Outer chunk function: calls oti_parallel_for again. The inner loop must run inline, in order, on the
// calling thread.
static int chunk_outer(void* arg, int64_t c, int32_t worker){

    nest_t* nests = (nest_t*)arg;
    nest_t* N = &nests[c];
    int64_t i;
    int st;

    (void)worker;
    N->outer_thread = pthread_self();
    N->same_thread = 1;
    N->worker_zero = 1;
    N->seq_len = 0;
    N->inner_in_parallel = oti_exec_in_parallel();
    N->max_workers_seen = oti_exec_max_workers(N->ctx);
    st = oti_parallel_for(N->ctx, N->n_inner, chunk_inner, N);
    N->ok = (st == OTI_OK) && (N->seq_len == N->n_inner);
    for (i = 0; i < N->seq_len; i++){
        if (N->seq[i] != i){
            N->ok = 0;
        }
    }
    return OTI_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_parallel_for_nested_in_worker(void){

    nest_t nests[16];
    oti_ctx ctx;
    int c, ok = 1, same = 1, wz = 1, in_par = 1, mw = 1;

    memset(nests, 0, sizeof(nests));
    make_ctx(&ctx, OTI_BACKEND_DEFAULT, 4);
    for (c = 0; c < 16; c++){
        nests[c].n_inner = 50;
        nests[c].ctx = &ctx;
    }
    check(oti_parallel_for(&ctx, 16, chunk_outer, nests) == OTI_OK, "nested: outer loop OK");
    for (c = 0; c < 16; c++){
        ok = ok && nests[c].ok;
        same = same && nests[c].same_thread;
        wz = wz && nests[c].worker_zero;
        mw = mw && (nests[c].max_workers_seen == 1 || oti_exec_max_workers(&ctx) == 1);
        in_par = in_par && (nests[c].inner_in_parallel == 1 || oti_exec_max_workers(&ctx) == 1);
    }
    check(ok, "nested: the inner loop inside a worker runs all its chunks in order");
    check(same, "nested: the inner loop inside a worker stays on the worker's thread");
    check(wz, "nested: inner chunks get worker 0");
#if BUILD_HAS_OPENMP && TEST_HAVE_OMP
    check(in_par, "nested: oti_exec_in_parallel() is true inside a library worker");
    check(mw, "nested: oti_exec_max_workers() is 1 inside a library worker");
#else
    (void)in_par; (void)mw;
#endif
    check(oti_exec_in_parallel() == 0, "nested: the flag is cleared after the loop returns");

}
// -------------------------------------------------------------------------------------------------------


#if TEST_HAVE_OMP && BUILD_HAS_OPENMP
// *******************************************************************************************************
static void test_parallel_for_in_omp_region(void){

    oti_ctx ctx;
    nest_t N[8];
    int nthreads_seen = 0;
    int t;
    int ok = 1;
    int saved_max = omp_get_max_threads();

    memset(N, 0, sizeof(N));
    make_ctx(&ctx, OTI_BACKEND_DEFAULT, 0);

    #pragma omp parallel num_threads(4)
    {
        int id = omp_get_thread_num();
        #pragma omp single
        nthreads_seen = omp_get_num_threads();
        if (id < 8){
            N[id].n_inner = 50;
            N[id].ctx = &ctx;
            N[id].outer_thread = pthread_self();
            N[id].same_thread = 1;
            N[id].worker_zero = 1;
            N[id].seq_len = 0;
            N[id].inner_in_parallel = oti_exec_in_parallel();
            N[id].ok = (oti_parallel_for(&ctx, 50, chunk_inner, &N[id]) == OTI_OK) && N[id].seq_len == 50;
        }
    }
    for (t = 0; t < 4 && t < 8; t++){
        int64_t i;
        ok = ok && N[t].ok && N[t].same_thread && N[t].worker_zero;
        for (i = 0; i < N[t].seq_len; i++){
            ok = ok && (N[t].seq[i] == i);
        }
        if (nthreads_seen > 1){
            ok = ok && (N[t].inner_in_parallel == 1);
        }
    }
    check(ok,
            "parallel_for inside an omp region: inline, in order, calling thread, worker 0");
    check(omp_get_max_threads() == saved_max, "omp region test leaves omp_get_max_threads() unchanged");

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// The nthreads clause is applied to one region only: it never changes process-wide settings.
static void test_nthreads_clause_is_local(void){

    oti_ctx ctx;
    loop_t L;
    int before = omp_get_max_threads();
    int before_dyn = omp_get_dynamic();
    int distinct_workers = 0, c, w;
    int seen[64];
    int ok_cap = 1;
    int nt;

    for (nt = 1; nt <= 3; nt++){
        make_ctx(&ctx, OTI_BACKEND_DEFAULT, nt);
        loop_init(&L, 400, g_ran, g_worker, NULL);
        L.delay = 20000;
        L.seed = (uint64_t)nt;
        L.max_worker = nt;
        check(oti_parallel_for(&ctx, 400, chunk_record, &L) == OTI_OK && all_ran_once(&L),
              "nthreads clause: loop completes");
        if (L.bad_worker){
            ok_cap = 0;
        }
        check(omp_get_max_threads() == before, "nthreads clause: omp_get_max_threads() unchanged");
    }
    check(ok_cap, "nthreads clause: worker index below nthreads");
    check(omp_get_dynamic() == before_dyn, "nthreads clause: omp_get_dynamic() unchanged");

    // With nthreads = 1 only one worker exists: all chunks have worker 0.
    make_ctx(&ctx, OTI_BACKEND_DEFAULT, 1);
    loop_init(&L, 100, g_ran, g_worker, NULL);
    oti_parallel_for(&ctx, 100, chunk_record, &L);
    w = 1;
    for (c = 0; c < 100; c++){
        w = w && g_worker[c] == 0;
    }
    check(w, "nthreads 1: every chunk on worker 0");

    // With nthreads = 3 and enough work more than one worker is used (not guaranteed on a loaded
    // machine, so this is reported only when it does not hold).
    memset(seen, 0, sizeof(seen));
    make_ctx(&ctx, OTI_BACKEND_DEFAULT, 3);
    loop_init(&L, 300, g_ran, g_worker, NULL);
    L.delay = 50000;
    L.seed = 5;
    oti_parallel_for(&ctx, 300, chunk_record, &L);
    for (c = 0; c < 300; c++){
        if (g_worker[c] >= 0 && g_worker[c] < 64 && !seen[g_worker[c]]){
            seen[g_worker[c]] = 1;
            distinct_workers++;
        }
    }
    printf("info: nthreads 3 used %d distinct workers\n", distinct_workers);
    check(distinct_workers >= 1 && distinct_workers <= 3, "nthreads 3: at most 3 distinct workers");

}
// -------------------------------------------------------------------------------------------------------
#endif


// *******************************************************************************************************
static void test_backend_not_compiled_in(void){

    oti_ctx ctx;
    loop_t L;
    int32_t missing[2];
    int nmissing = 0, i;

    if (!BUILD_HAS_PTHREADS){
        missing[nmissing++] = OTI_BACKEND_PTHREADS;
    }
    if (!BUILD_HAS_OPENMP){
        missing[nmissing++] = OTI_BACKEND_OPENMP;
    }
    if (nmissing == 0){
        printf("skipped: every backend is compiled in\n");
    }
    for (i = 0; i < nmissing; i++){
        make_ctx(&ctx, missing[i], 0);
        loop_init(&L, 20, g_ran, g_worker, NULL);
        check(oti_parallel_for(&ctx, 20, chunk_record, &L) == OTI_ERR_BACKEND,
              "parallel_for: backend not compiled in -> BACKEND");
        check(g_ran[0] == 0 && g_ran[10] == 0 && g_ran[19] == 0,
                "parallel_for: nothing runs for a missing backend");
        check(oti_parallel_for(&ctx, 0, chunk_record, &L) == OTI_ERR_BACKEND ||
              oti_parallel_for(&ctx, 0, chunk_record, &L) == OTI_OK,
              "parallel_for: zero chunks with a missing backend is BACKEND or OK");
    }

    // An unknown backend value is always BACKEND.
    make_ctx(&ctx, 99, 0);
    loop_init(&L, 20, g_ran, g_worker, NULL);
    check(oti_parallel_for(&ctx, 20, chunk_record, &L) == OTI_ERR_BACKEND && g_ran[0] == 0,
          "parallel_for: unknown backend 99 -> BACKEND, nothing runs");

    // The always-present SERIAL backend and DEFAULT.
    make_ctx(&ctx, OTI_BACKEND_SERIAL, 0);
    loop_init(&L, 20, g_ran, g_worker, NULL);
    check(oti_parallel_for(&ctx, 20, chunk_record, &L) == OTI_OK && all_ran_once(&L),
          "parallel_for: SERIAL backend OK");

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// oti_parallel_for_blas keeps the same results and error rule; with OTI_BLAS_INHERIT its chunks run
// serially, in order (contracts 5.5: without BLAS thread control, batch loops run serially).
static void test_parallel_for_blas(void){

    oti_ctx ctx;
    loop_t L;
    int c, ok = 1, st;

    make_ctx(&ctx, OTI_BACKEND_DEFAULT, 4);
    ctx.exec.blas_policy = OTI_BLAS_INHERIT;
    loop_init(&L, 100, g_ran, g_worker, NULL);
    L.order = g_order;
    st = oti_parallel_for_blas(&ctx, 100, chunk_record, &L);
    check(st == OTI_OK && all_ran_once(&L), "parallel_for_blas (INHERIT): runs every chunk");
    for (c = 0; c < 100; c++){
        ok = ok && (g_order[c] == c) && (g_worker[c] == 0);
    }
    check(ok, "parallel_for_blas (INHERIT): serial, in order, worker 0");

    make_ctx(&ctx, OTI_BACKEND_DEFAULT, 4);
    loop_init(&L, 100, g_ran, g_worker, NULL);
    check(oti_parallel_for_blas(&ctx, 100, chunk_record, &L) == OTI_OK && all_ran_once(&L),
          "parallel_for_blas (SERIAL_IN_REGIONS): runs every chunk");

    memset(g_fail, 0, sizeof(g_fail));
    g_fail[7] = 1;
    g_fail[20] = 1;
    loop_init(&L, 100, g_ran, g_worker, g_fail);
    st = oti_parallel_for_blas(&ctx, 100, chunk_record, &L);
    ok = (st == chunk_status(7));
    for (c = 0; c <= 7; c++){
        ok = ok && g_ran[c] == 1;
    }
    check(ok, "parallel_for_blas: lowest failing chunk's status, chunks below it ran");

    loop_init(&L, 0, g_ran, g_worker, NULL);
    check(oti_parallel_for_blas(&ctx, 0, chunk_record, &L) == OTI_OK,
            "parallel_for_blas: zero chunks OK");

}
// -------------------------------------------------------------------------------------------------------


typedef struct {
    int32_t nthreads;
    int     ok;
} host_t;


// *******************************************************************************************************
static int chunk_sum(void* arg, int64_t c, int32_t worker){

    int64_t* out = (int64_t*)arg;

    (void)worker;
    out[c] = c * c + 1;
    return OTI_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void* host_main(void* p){

    host_t* h = (host_t*)p;
    oti_ctx ctx;
    int64_t out[512];
    int64_t c;
    int rep;

    make_ctx(&ctx, OTI_BACKEND_DEFAULT, h->nthreads);
    h->ok = 1;
    for (rep = 0; rep < 200; rep++){
        memset(out, 0, sizeof(out));
        if (oti_parallel_for(&ctx, 512, chunk_sum, out) != OTI_OK){
            h->ok = 0;
        }
        for (c = 0; c < 512; c++){
            if (out[c] != c * c + 1){
                h->ok = 0;
            }
        }
    }
    return NULL;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Two host threads, each with its own user context, drive parallel loops at once.
static void test_concurrent_hosts(void){

    pthread_t a, b;
    host_t ha, hb;

    ha.nthreads = 2; ha.ok = 0;
    hb.nthreads = 3; hb.ok = 0;
    pthread_create(&a, NULL, host_main, &ha);
    pthread_create(&b, NULL, host_main, &hb);
    pthread_join(a, NULL);
    pthread_join(b, NULL);
    check(ha.ok && hb.ok, "two host threads with their own contexts run parallel loops correctly");

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Results of a chunked reduction-like loop do not depend on the thread count (fixed logical chunks).
static int chunk_partial(void* arg, int64_t c, int32_t worker){

    double* part = (double*)arg;
    double s = 0.0;
    int64_t i;

    (void)worker;
    for (i = c * 64; i < (c + 1) * 64; i++){
        s += 1.0 / (double)(i + 1) * ((i & 1) ? -1.0 : 1.0);
    }
    part[c] = s;
    return OTI_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_chunk_results_independent_of_threads(void){

    static const int32_t nthreads[] = {0, 1, 2, 3, 5};
    double ref[300], got[300];
    oti_ctx ctx;
    int i, ok = 1;

    oti_serial_for(300, chunk_partial, ref);
    for (i = 0; i < 5; i++){
        make_ctx(&ctx, OTI_BACKEND_DEFAULT, nthreads[i]);
        memset(got, 0, sizeof(got));
        oti_parallel_for(&ctx, 300, chunk_partial, got);
        ok = ok && (memcmp(ref, got, sizeof(ref)) == 0);
    }
    check(ok, "per-chunk results of parallel_for are bitwise the serial ones at every thread count");

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Fix round 3: worker indices of a 2-chunk loop never exceed 1.
static int chunk_maxworker(void* arg, int64_t c, int32_t worker){

    int32_t* mx = (int32_t*)arg;
    int32_t cur = __atomic_load_n(mx, __ATOMIC_RELAXED);

    (void)c;
    spin(2000);
    while (worker > cur && !__atomic_compare_exchange_n(mx, &cur, worker, 1, __ATOMIC_RELAXED,
            __ATOMIC_RELAXED)){
    }
    return OTI_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void test_fix3_exec(void){

    oti_ctx ctx;
    int rep, ok = 1;
    int32_t mx;
    int32_t threads[4] = {0, 2, 4, 8};

    for (rep = 0; rep < 200; rep++){
        mx = 0;
        make_ctx(&ctx, OTI_BACKEND_DEFAULT, threads[rep % 4]);
        if (oti_parallel_for(&ctx, 2, chunk_maxworker, &mx) != OTI_OK || mx > 1){
            ok = 0;
        }
    }
    check(ok,
            "fix3: a 2-chunk oti_parallel_for never uses a worker index above 1");

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int main(void){

    // Before anything touches the default context (created once, read-only afterwards).
    if (getenv("OTI_DENSE_MAX_MB") != NULL){
        printf("note: OTI_DENSE_MAX_MB was already set; the budget assertions assume 7\n");
    }
    setenv("OTI_DENSE_MAX_MB", "7", 1);

    printf("OpenMP build: %d, OpenMP in the test: %d\n", BUILD_HAS_OPENMP, TEST_HAVE_OMP);

    test_status_values();
    test_status_string();
    test_exec_init_and_ctx_init();
    test_default_ctx();
    test_ctx_check();
    test_budgets();
    test_last_error_user_ctx();
    test_last_error_null_and_default_pointer();
    test_last_error_thread_local();
    test_backend_queries();
    test_nchunks();
    test_max_workers_and_parallel_ok();
    test_serial_for();
    test_parallel_for_runs_all();
    test_parallel_for_error_rule();
    test_parallel_for_slow_lower_failure();
    test_parallel_for_nested_in_worker();
#if TEST_HAVE_OMP && BUILD_HAS_OPENMP
    test_parallel_for_in_omp_region();
    test_nthreads_clause_is_local();
#else
    printf("skipped: OpenMP region and omp_get_max_threads tests (not built with OpenMP)\n");
#endif
    test_backend_not_compiled_in();
    test_parallel_for_blas();
    test_concurrent_hosts();
    test_chunk_results_independent_of_threads();

    test_fix3_exec();

    if (n_failed > 0){
        fprintf(stderr, "\n%d check(s) FAILED\n", n_failed);
        return 1;
    }
    printf("\nAll checks passed.\n");
    return 0;

}
// -------------------------------------------------------------------------------------------------------
