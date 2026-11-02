// Dense scalar: memory management and the per-thread workspace (include/oti/dense/scalar/base.h).
//
// Unity-included from src/c/dense.c: static helpers here carry the dnsm_ prefix. Later dense files use
// dnsm_nimag(), dnsm_budget(), dnsm_prepare(), dnsm_ret(), dnsm_scratch() and dnsm_ws_need().


#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#if defined(__APPLE__)
#include <sys/types.h>
#include <sys/sysctl.h>
#endif

// Budget of one dense coefficient buffer when the physical memory cannot be queried: 64 GiB.
#define DNSM_BUDGET_FALLBACK_BYTES (64ull << 30)

// Largest coefficient buffer, in bytes, a dense allocation may request (dnsm_budget()). Set once, from
// OTI_DENSE_MAX_MB or the physical memory: a request far above the memory would otherwise get a
// successful malloc on systems that overcommit (macOS) and be killed while it is zero-filled.
static uint64_t dnsm_budget_bytes;
static pthread_once_t dnsm_budget_once = PTHREAD_ONCE_INIT;

// Scratch workspace of each thread. It lives on the heap (allocated on the first use of the thread) so
// that the thread-exit destructor of the key below can still reach it: thread-local storage itself may
// already be gone when key destructors run (macOS releases it from its own key destructor). The
// static copy is the fallback when that allocation fails (then it is not released at thread exit).
static _Thread_local sshelp_ws_t* dnsm_tls_wsp;
static _Thread_local sshelp_ws_t dnsm_tls_ws;

// Key whose destructor releases the workspace of a thread when it exits (short-lived threads, such as
// Python worker threads or re-created OpenMP teams, would otherwise leak it).
static pthread_key_t dnsm_ws_key;
static pthread_once_t dnsm_ws_once = PTHREAD_ONCE_INIT;
static int dnsm_ws_key_ok;              // set only by a successful pthread_key_create().

// Nonzero while the thread's workspace coefficient buffer is handed out by dnsm_scratch().
static _Thread_local int dnsm_tls_held;


// *******************************************************************************************************
// Physical memory of the machine in bytes, or 0 when it cannot be queried.
static uint64_t dnsm_physical_bytes(void){

#if defined(__APPLE__)
    uint64_t mem = 0;
    size_t len = sizeof(mem);

    if (sysctlbyname("hw.memsize", &mem, &len, NULL, 0) == 0 && len == sizeof(mem)){
        return mem;
    }

    return 0;
#elif defined(_SC_PHYS_PAGES) && defined(_SC_PAGE_SIZE)
    long pages = sysconf(_SC_PHYS_PAGES), page = sysconf(_SC_PAGE_SIZE);

    if (pages > 0 && page > 0 && (uint64_t)pages <= UINT64_MAX / (uint64_t)page){
        return (uint64_t)pages * (uint64_t)page;
    }

    return 0;
#else
    return 0;
#endif

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Sets dnsm_budget_bytes (once, through pthread_once): OTI_DENSE_MAX_MB when it is a positive integer,
// else the physical memory, else DNSM_BUDGET_FALLBACK_BYTES.
static void dnsm_budget_init(void){

    const char* env = getenv("OTI_DENSE_MAX_MB");
    uint64_t phys;

    if (env != NULL && env[0] >= '0' && env[0] <= '9'){

        char* end = NULL;
        unsigned long long mb = strtoull(env, &end, 10);

        if (*end == '\0' && mb > 0){
            dnsm_budget_bytes = (mb > (UINT64_MAX >> 20)) ? UINT64_MAX : (uint64_t)mb << 20;
            return;
        }

    }

    phys = dnsm_physical_bytes();
    dnsm_budget_bytes = (phys != 0) ? phys : DNSM_BUDGET_FALLBACK_BYTES;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// DN_ERR_MEMORY when a buffer of nreals coefficients exceeds the dense byte budget (OTI_DENSE_MAX_MB,
// default the physical memory), else DN_OK. Called by the size gates dnsm_nimag() and dnob_nreals().
static int dnsm_budget(uint64_t nreals){

    pthread_once(&dnsm_budget_once, dnsm_budget_init);

    if (nreals > dnsm_budget_bytes / sizeof(coeff_t)){
        return DN_ERR_MEMORY;
    }

    return DN_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Number of imaginary coefficients over k bases to order n: DN_ERR_INDEX above _MAXORDER_OTI (stack
// tuples are sized by it), DN_ERR_MEMORY when the index type or the byte count overflows, or the buffer
// exceeds the byte budget (dnsm_budget()).
static int dnsm_nimag(bases_t k, ord_t n, ndir_t* p_nimag){

    if (n > _MAXORDER_OTI){
        return DN_ERR_INDEX;
    }

    if (sshelp_ndir_total_checked(k, n, p_nimag) != SSHELP_OK){
        return DN_ERR_MEMORY;
    }

    return dnsm_budget((uint64_t)*p_nimag);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Coefficients the buffer of a number is known to hold.
static inline ndir_t dnsm_capacity(const otinum_t* num){

    return (num->p_im == NULL) ? 0 : sshelp_ndir_total(num->nbases, num->trc_order);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Grows the calling thread's workspace (index buffers only).
static inline int dnsm_ws_need(sshelp_ws_t* ws, size_t nmap, size_t nbases){

    if (sshelp_ws_reserve(ws, 0, nmap, nbases) != SSHELP_OK){
        return DN_ERR_MEMORY;
    }

    return DN_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Coefficient scratch of n values: the calling thread's workspace buffer when it needs at most
// DNSM_WS_COEF_BYTES and is not already handed out (kept between calls), else a call-local allocation
// (*p_owned set). Release it with dnsm_scratch_free(p, *p_owned). NULL on failure. Nested uses are
// safe: while the workspace buffer is held, further requests get their own allocation.
#define DNSM_WS_COEF_BYTES ((size_t)64 * 1024)

static coeff_t* dnsm_scratch(size_t n, coeff_t** p_owned){

    sshelp_ws_t* ws = oti_ws();

    *p_owned = NULL;

    if (n > SIZE_MAX / sizeof(coeff_t)){
        return NULL;
    }

    if (!dnsm_tls_held && n * sizeof(coeff_t) <= DNSM_WS_COEF_BYTES
        && sshelp_ws_reserve(ws, n, 0, 0) == SSHELP_OK){

        dnsm_tls_held = 1;

        return ws->p_coef;

    }

    *p_owned = (coeff_t*)malloc((n > 0 ? n : 1) * sizeof(coeff_t));

    return *p_owned;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Releases a scratch from dnsm_scratch(): frees a call-local allocation, or hands the workspace buffer
// back. p is the pointer dnsm_scratch() returned (NULL is a no-op).
static void dnsm_scratch_free(coeff_t* p, coeff_t* owned){

    if (owned != NULL){
        free(owned);
    } else if (p != NULL){
        dnsm_tls_held = 0;
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Gives num the layout (nact, trc) with its buffer large enough, keeping no coefficients (the caller
// writes all of them). re and act_order are left for the caller. On failure num is left valid.
static int dnsm_prepare(otinum_t* num, bases_t nact, ord_t trc){

    ndir_t need, cap = dnsm_capacity(num);
    coeff_t* p_im;
    int status = dnsm_nimag(nact, trc, &need);

    if (status != DN_OK){
        return status;
    }

    if (need <= cap){

        // Keep the capacity in bases valid for the new truncation order: nbases at trc must still fit
        // the buffer, which holds for the old nbases only if trc does not grow.
        if (trc > num->trc_order || num->nbases < nact){
            num->nbases = nact;
        }

    } else {

        p_im = (coeff_t*)malloc((size_t)need * sizeof(coeff_t));

        if (p_im == NULL){
            return DN_ERR_MEMORY;
        }

        free(num->p_im);
        num->p_im   = p_im;
        num->nbases = nact;

    }

    num->nact      = nact;
    num->trc_order = trc;

    return DN_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Result of an allocating variant: the number on success, else oti_init() with re = NaN.
static otinum_t dnsm_ret(int status, otinum_t* res){

    if (status != DN_OK){

        oti_free(res);
        res->re = NAN;

    }

    return *res;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Thread-exit destructor of the workspace key: frees the exiting thread's workspace.
static void dnsm_ws_destroy(void* p_ws){

    sshelp_ws_free((sshelp_ws_t*)p_ws);
    free(p_ws);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Creates the key (once per process).
static void dnsm_ws_key_create(void){

    dnsm_ws_key_ok = (pthread_key_create(&dnsm_ws_key, dnsm_ws_destroy) == 0);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Allocates the calling thread's workspace and registers it with the destructor key (once per thread;
// the slow path of oti_ws()). Returns the static fallback workspace when that fails.
static sshelp_ws_t* dnsm_ws_register(void){

    sshelp_ws_t* p_ws = (sshelp_ws_t*)calloc(1, sizeof(sshelp_ws_t));    // zeros == sshelp_ws_init().

    (void)pthread_once(&dnsm_ws_once, dnsm_ws_key_create);

    // Without a key of our own (its creation failed) the key value is not ours to use: keep the
    // static fallback instead of touching a key that may belong to another library.
    if (p_ws == NULL || !dnsm_ws_key_ok || pthread_setspecific(dnsm_ws_key, p_ws) != 0){

        free(p_ws);
        p_ws = &dnsm_tls_ws;

    }

    dnsm_tls_wsp = p_ws;

    return p_ws;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
sshelp_ws_t* oti_ws(void){

    return (dnsm_tls_wsp != NULL) ? dnsm_tls_wsp : dnsm_ws_register();

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void oti_ws_release(void){

    sshelp_ws_free((dnsm_tls_wsp != NULL) ? dnsm_tls_wsp : &dnsm_tls_ws);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
size_t dn_max_bytes(void){

    pthread_once(&dnsm_budget_once, dnsm_budget_init);

    return (dnsm_budget_bytes > (uint64_t)SIZE_MAX) ? SIZE_MAX : (size_t)dnsm_budget_bytes;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
otinum_t oti_init(void){

    otinum_t num;

    num.re        = 0.0;
    num.p_im      = NULL;
    num.nbases    = 0;
    num.nact      = 0;
    num.trc_order = 0;
    num.act_order = 0;

    return num;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
otinum_t oti_create_empty(bases_t nact, ord_t trc_order){

    otinum_t res = oti_init();

    return dnsm_ret(oti_create_empty_to(nact, trc_order, &res), &res);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oti_create_empty_to(bases_t nact, ord_t trc_order, otinum_t* res){

    ndir_t nimag;
    int status = dnsm_prepare(res, nact, trc_order);

    if (status != DN_OK){
        return status;
    }

    nimag = sshelp_ndir_total(nact, trc_order);

    if (nimag > 0){
        memset(res->p_im, 0, (size_t)nimag * sizeof(coeff_t));
    }

    res->re        = 0.0;
    res->act_order = 0;

    return DN_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
otinum_t oti_create_r(coeff_t re, ord_t trc_order){

    otinum_t num = oti_init();

    // Above the maximum order: the allocating-variant failure value.
    if (trc_order > _MAXORDER_OTI){

        num.re = NAN;
        return num;

    }

    num.re        = re;
    num.trc_order = trc_order;

    return num;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
otinum_t oti_e(imdir_t idx, ord_t order, ord_t trc_order){

    otinum_t res = oti_init();

    return dnsm_ret(oti_e_to(idx, order, trc_order, &res), &res);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oti_e_to(imdir_t idx, ord_t order, ord_t trc_order, otinum_t* res){

    bases_t g[256];
    ord_t trc = (trc_order > order) ? trc_order : order;
    int status;

    if (trc > _MAXORDER_OTI){
        return DN_ERR_INDEX;
    }

    // Order 0 is the real unit.
    if (order == 0){

        status = oti_create_empty_to(0, trc, res);
        res->re = 1.0;

        return status;

    }

    if (sshelp_global_unrank(idx, order, g) != SSHELP_OK){
        return DN_ERR_INDEX;
    }

    // The labels come sorted: the last one is the largest base.
    status = oti_create_empty_to(g[order - 1], trc, res);

    if (status != DN_OK){
        return status;
    }

    res->p_im[sshelp_order_offset(res->nact, order) + idx] = 1.0;
    res->act_order = order;

    return DN_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oti_reserve(otinum_t* num, bases_t cap, ord_t trc_order){

    bases_t new_cap = (cap > num->nact) ? cap : num->nact;
    ord_t new_trc = (trc_order > num->trc_order) ? trc_order : num->trc_order;
    ndir_t nimag, nused_old, nused_new;
    coeff_t* p_im;
    int status;

    if (cap <= num->nbases && trc_order <= num->trc_order){
        return DN_OK;
    }

    status = dnsm_nimag(new_cap, new_trc, &nimag);

    if (status != DN_OK){
        return status;
    }

    // Keep the buffer when the required layout fits it, else allocate exactly that layout. Order
    // offsets depend only on (nact, p), so the used prefix keeps its place either way.
    if (nimag > dnsm_capacity(num)){

        p_im = (coeff_t*)realloc(num->p_im, (size_t)nimag * sizeof(coeff_t));

        if (p_im == NULL){
            return DN_ERR_MEMORY;
        }

        num->p_im = p_im;

    }

    // New orders over the current bases start at zero.
    nused_old = sshelp_ndir_total(num->nact, num->trc_order);
    nused_new = sshelp_ndir_total(num->nact, new_trc);

    if (nused_new > nused_old){
        memset(num->p_im + nused_old, 0, (size_t)(nused_new - nused_old) * sizeof(coeff_t));
    }

    // Never the old nbases at a higher trc: that can overstate the allocation.
    num->nbases    = new_cap;
    num->trc_order = new_trc;

    return DN_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void oti_free(otinum_t* num){

    free(num->p_im);
    *num = oti_init();

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
otinum_t oti_copy(const otinum_t* num){

    otinum_t res = oti_init();

    return dnsm_ret(oti_copy_to(num, &res), &res);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oti_copy_to(const otinum_t* num, otinum_t* res){

    ndir_t nimag;
    int status;

    if (num == res){
        return DN_OK;
    }

    status = dnsm_prepare(res, num->nact, num->trc_order);

    if (status != DN_OK){
        return status;
    }

    nimag = sshelp_ndir_total(num->nact, num->trc_order);

    if (nimag > 0){
        memcpy(res->p_im, num->p_im, (size_t)nimag * sizeof(coeff_t));
    }

    res->re        = num->re;
    res->act_order = num->act_order;

    return DN_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oti_add_bases(bases_t nact, otinum_t* num){

    bases_t kold = num->nact;
    ord_t p, trc = num->trc_order;
    ndir_t nimag, off_old, off_new, n_old, n_new;
    coeff_t* p_im;
    int status;

    if (nact <= kold){
        return DN_OK;
    }

    status = dnsm_nimag(nact, trc, &nimag);

    if (status != DN_OK){
        return status;
    }

    if (nimag <= dnsm_capacity(num)){

        // Zero-extension in place, highest order first: every block moves up.
        for (p = trc; p >= 1; p--){

            off_old = sshelp_order_offset(kold, p);
            n_old   = sshelp_ndir_order(kold, p);
            off_new = sshelp_order_offset(nact, p);
            n_new   = sshelp_ndir_order(nact, p);

            if (n_old > 0){
                memmove(num->p_im + off_new, num->p_im + off_old, (size_t)n_old * sizeof(coeff_t));
            }

            memset(num->p_im + off_new + n_old, 0, (size_t)(n_new - n_old) * sizeof(coeff_t));

        }

        if (num->nbases < nact){
            num->nbases = nact;
        }

    } else {

        p_im = (coeff_t*)malloc((size_t)nimag * sizeof(coeff_t));

        if (p_im == NULL){
            return DN_ERR_MEMORY;
        }

        for (p = 1; p <= trc; p++){

            off_old = sshelp_order_offset(kold, p);
            n_old   = sshelp_ndir_order(kold, p);
            off_new = sshelp_order_offset(nact, p);
            n_new   = sshelp_ndir_order(nact, p);

            if (n_old > 0){
                memcpy(p_im + off_new, num->p_im + off_old, (size_t)n_old * sizeof(coeff_t));
            }

            memset(p_im + off_new + n_old, 0, (size_t)(n_new - n_old) * sizeof(coeff_t));

        }

        free(num->p_im);
        num->p_im   = p_im;
        num->nbases = nact;

    }

    num->nact = nact;

    return DN_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void oti_set_r(coeff_t val, otinum_t* num){

    num->re        = val;
    num->nact      = 0;
    num->act_order = 0;

}
// -------------------------------------------------------------------------------------------------------
