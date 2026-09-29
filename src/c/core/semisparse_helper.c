// Index helpers for semi-sparse OTI numbers. See include/oti/core/semisparse.h.


// *******************************************************************************************************
// Largest c in [m-1, hi] with C(c, m) <= r (combinatorial number system step). m >= 1.
static uint64_t sshelp_largest_c(uint64_t r, uint64_t m, uint64_t hi){

    uint64_t lo = m - 1, mid;

    // C(lo, m) = 0 <= r always holds; C(c, m) is nondecreasing in c.
    while (lo < hi){

        mid = lo + (hi - lo + 1) / 2;

        if (sshelp_comb(mid, m) <= r){
            lo = mid;
        } else {
            hi = mid - 1;
        }

    }

    return lo;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int sshelp_ndir_total_checked(bases_t k, ord_t n, ndir_t* p_nimag){

    uint64_t total = sshelp_comb((uint64_t)k + n, n);

    if (total == SSHELP_COMB_OVERFLOW || total > SIZE_MAX / sizeof(coeff_t)){
        return SSHELP_ERR_OVERFLOW;
    }

    if (p_nimag != NULL){
        *p_nimag = total - 1;
    }

    return SSHELP_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
bases_t sshelp_union_bases(const bases_t* a, bases_t na, const bases_t* b, bases_t nb,
                           bases_t* res, bases_t* pos_a, bases_t* pos_b){

    bases_t i = 0, j = 0, n = 0, x, y;
    int ta, tb;

    // Positions of a base that is not consumed this step are overwritten when it is.
    while (i < na && j < nb){

        x  = a[i];
        y  = b[j];
        ta = x <= y;
        tb = y <= x;

        res[n] = ta ? x : y;

        if (pos_a != NULL){
            pos_a[i] = n;
        }

        if (pos_b != NULL){
            pos_b[j] = n;
        }

        i += ta;
        j += tb;
        n++;

    }

    while (i < na){

        if (pos_a != NULL){
            pos_a[i] = n;
        }

        res[n++] = a[i++];

    }

    while (j < nb){

        if (pos_b != NULL){
            pos_b[j] = n;
        }

        res[n++] = b[j++];

    }

    return n;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int sshelp_rank_tab_init(sshelp_rank_tab_t* tab, bases_t k, ord_t n){

    size_t i, u;
    uint64_t c;

    tab->p_c = NULL;
    tab->k   = k;
    tab->n   = n;

    if (k == 0 || n == 0){
        return SSHELP_OK;
    }

    tab->p_c = (ndir_t*)malloc((size_t)n * k * sizeof(ndir_t));

    if (tab->p_c == NULL){
        return SSHELP_ERR_MEMORY;
    }

    for (i = 0; i < n; i++){

        for (u = 0; u < k; u++){

            c = sshelp_comb(u + i, i + 1);

            if (c == SSHELP_COMB_OVERFLOW){
                sshelp_rank_tab_free(tab);
                return SSHELP_ERR_OVERFLOW;
            }

            tab->p_c[i * k + u] = c;

        }

    }

    return SSHELP_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void sshelp_rank_tab_free(sshelp_rank_tab_t* tab){

    free(tab->p_c);

    tab->p_c = NULL;
    tab->k   = 0;
    tab->n   = 0;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void sshelp_unrank(ndir_t idx, ord_t p, bases_t* u){

    uint64_t c, r = idx;
    int i;

    // C(c, m) >= c - m + 1 for c >= m, so c <= r + m - 1.
    for (i = (int)p - 1; i >= 0; i--){

        c    = sshelp_largest_c(r, (uint64_t)i + 1, r + (uint64_t)i);
        r   -= sshelp_comb(c, (uint64_t)i + 1);
        u[i] = (bases_t)(c - (uint64_t)i);

    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void sshelp_local_dirs(bases_t k, ord_t p, bases_t* out){

    ndir_t j, ndir = sshelp_ndir_order(k, p);
    ord_t i;

    if (ndir == 0){
        return;
    }

    for (i = 0; i < p; i++){
        out[i] = 0;
    }

    for (j = 1; j < ndir; j++){

        for (i = 0; i < p; i++){
            out[j * p + i] = out[(j - 1) * p + i];
        }

        sshelp_next_dir(&out[j * p], p, k);

    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void sshelp_remap_order(bases_t k_src, const bases_t* pos, ord_t p,
                        const sshelp_rank_tab_t* tab_dst, ndir_t* map, bases_t* u){

    ndir_t j, r, ndir = sshelp_ndir_order(k_src, p);
    const ndir_t* c = tab_dst->p_c;
    size_t kd = tab_dst->k;
    ord_t i;

    if (ndir == 0){
        return;
    }

    for (i = 0; i < p; i++){
        u[i] = 0;
    }

    for (j = 0; j < ndir; j++){

        r = 0;

        for (i = 0; i < p; i++){
            r += c[i * kd + pos[u[i]]];
        }

        map[j] = r;

        sshelp_next_dir(u, p, k_src);

    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
imdir_t sshelp_global_rank(const bases_t* g, ord_t p){

    uint64_t c, r = 0;
    ord_t i;

    for (i = 0; i < p; i++){

        c = sshelp_comb((uint64_t)g[i] - 1 + i, (uint64_t)i + 1);

        if (c == SSHELP_COMB_OVERFLOW || c >= SSHELP_COMB_OVERFLOW - r){
            return SSHELP_COMB_OVERFLOW;
        }

        r += c;

    }

    return r;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int sshelp_global_unrank(imdir_t idx, ord_t p, bases_t* g){

    uint64_t c, hi, bound, r = idx;
    int i;

    for (i = (int)p - 1; i >= 0; i--){

        // Label g = c - i + 1 <= 65535 means c <= 65534 + i; also c <= r + i.
        bound = (uint64_t)UINT16_MAX - 1 + (uint64_t)i;
        hi    = (r > bound) ? bound : r + (uint64_t)i;
        hi    = (hi > bound) ? bound : hi;
        c     = sshelp_largest_c(r, (uint64_t)i + 1, hi);
        r    -= sshelp_comb(c, (uint64_t)i + 1);
        g[i]  = (bases_t)(c - (uint64_t)i + 1);

    }

    // A remainder means the index needs a label above 65535.
    return (r == 0) ? SSHELP_OK : SSHELP_ERR_RANGE;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int sshelp_local_to_global(ndir_t idx, ord_t p, const bases_t* bases, bases_t k, imdir_t* p_idx){

    bases_t u[256];
    imdir_t r;
    ord_t i;

    if (idx >= sshelp_ndir_order(k, p)){
        return SSHELP_ERR_RANGE;
    }

    sshelp_unrank(idx, p, u);

    // Local order is preserved by the sorted map, so the mapped tuple is already sorted.
    for (i = 0; i < p; i++){
        u[i] = bases[u[i]];
    }

    r = sshelp_global_rank(u, p);

    if (r == SSHELP_COMB_OVERFLOW){
        return SSHELP_ERR_OVERFLOW;
    }

    *p_idx = r;

    return SSHELP_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int sshelp_global_to_local(imdir_t idx, ord_t p, const bases_t* bases, bases_t k, ndir_t* p_idx){

    bases_t g[256];
    ndir_t r = 0;
    size_t lo, hi, mid;
    ord_t i;

    if (sshelp_global_unrank(idx, p, g) != SSHELP_OK){
        return SSHELP_ERR_RANGE;
    }

    for (i = 0; i < p; i++){

        // Binary search of g[i] in the active bases.
        lo = 0;
        hi = k;

        while (lo < hi){

            mid = lo + (hi - lo) / 2;

            if (bases[mid] < g[i]){
                lo = mid + 1;
            } else {
                hi = mid;
            }

        }

        if (lo == k || bases[lo] != g[i]){
            return 0;
        }

        r += sshelp_comb(lo + i, (uint64_t)i + 1);

    }

    *p_idx = r;

    return 1;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Local product-table cache for sshelp_get_pair(), keyed by (k, p, q) with p <= q (see the header
// doc). Append-only singly linked list: nodes are only ever prepended, never freed or moved while
// reachable, so sshelp_cache_find() can walk it lock-free concurrently with an insertion under the
// critical section below (the new node's fields, including `next`, are fully set before the head
// pointer is published with a release store).
typedef struct sshelp_cache_node {
    bases_t                   k;
    ord_t                  p, q; ///< Canonical: p <= q.
    ndir_t              stride; ///< N_q(k).
    imdir_t*             p_tab; ///< NULL until built, or permanently NULL when over budget.
    int                  ready; ///< 0 until the build/skip decision is made and published.
    struct sshelp_cache_node* next;
} sshelp_cache_node_t;

static sshelp_cache_node_t* sshelp_cache_head        = NULL;
static uint64_t             sshelp_cache_bytes_used  = 0;
static int                  sshelp_cache_limit_set   = 0;
static uint64_t             sshelp_cache_limit_bytes = 0;
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static sshelp_cache_node_t* sshelp_cache_find(bases_t k, ord_t p, ord_t q){

    sshelp_cache_node_t* node = __atomic_load_n(&sshelp_cache_head, __ATOMIC_ACQUIRE);

    while (node != NULL){

        if (node->k == k && node->p == p && node->q == q){
            return node;
        }

        node = node->next;

    }

    return NULL;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Builds node->p_tab with the rank method (sshelp_prod_rank()), or decides to skip it when the
// cache's total size would exceed its budget. Only called from sshelp_cache_get_or_build(), already
// inside the critical section: sshelp_cache_bytes_used / _limit_* need no atomics of their own.
static void sshelp_cache_build(sshelp_cache_node_t* node){

    ndir_t Np = sshelp_ndir_order(node->k, node->p);
    ndir_t Nq = node->stride;
    uint64_t n_entries = (uint64_t)Np * (uint64_t)Nq;
    uint64_t bytes = n_entries * sizeof(imdir_t);
    bases_t *dirs_p, *dirs_q;
    sshelp_rank_tab_t tab;
    imdir_t* p_tab;
    ndir_t i, j;

    if (!sshelp_cache_limit_set){

        char* env = getenv("OTI_SS_TABLE_CACHE_MB");

        sshelp_cache_limit_bytes = (uint64_t)SSHELP_CACHE_DEFAULT_MB * 1024ull * 1024ull;

        if (env != NULL){

            char* end = NULL;
            unsigned long long mb = strtoull(env, &end, 10);

            if (end != env && *end == '\0'){
                sshelp_cache_limit_bytes = (uint64_t)mb * 1024ull * 1024ull;
            }

        }

        sshelp_cache_limit_set = 1;

    }

    if (Np == 0 || Nq == 0 || sshelp_cache_bytes_used + bytes > sshelp_cache_limit_bytes){

        // Decided: stays NULL, the caller keeps using the per-call rank fallback.
        __atomic_store_n(&node->ready, 1, __ATOMIC_RELEASE);
        return;

    }

    dirs_p = (bases_t*)malloc((size_t)Np * node->p * sizeof(bases_t));
    dirs_q = (bases_t*)malloc((size_t)Nq * node->q * sizeof(bases_t));
    p_tab  = (imdir_t*)malloc((size_t)n_entries * sizeof(imdir_t));

    if (dirs_p == NULL || dirs_q == NULL || p_tab == NULL
        || sshelp_rank_tab_init(&tab, node->k, node->p + node->q) != SSHELP_OK){
        printf("ERROR: Not enough memory for the semi-sparse product-table cache. Exiting...\n");
        exit(OTI_OutOfMemory);
    }

    sshelp_local_dirs(node->k, node->p, dirs_p);
    sshelp_local_dirs(node->k, node->q, dirs_q);

    for (i = 0; i < Np; i++){

        for (j = 0; j < Nq; j++){

            p_tab[i * Nq + j] = sshelp_prod_rank(&dirs_p[i * node->p], node->p,
                                                 &dirs_q[j * node->q], node->q, &tab);

        }

    }

    sshelp_rank_tab_free(&tab);
    free(dirs_p);
    free(dirs_q);

    sshelp_cache_bytes_used += bytes;

    // Payload before the flag: any thread that acquire-loads ready == 1 also sees this table.
    __atomic_store_n(&node->p_tab, p_tab, __ATOMIC_RELAXED);
    __atomic_store_n(&node->ready, 1, __ATOMIC_RELEASE);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Finds or creates the cache node for a canonical (k, p, q) (p <= q), and makes sure its build/skip
// decision has been made before returning it. Double-checked, like dhelp_get_multtabl(): a lock-free
// check outside the critical section for the common case (node exists and is ready), a second check
// inside it to cover a concurrent first build.
static sshelp_cache_node_t* sshelp_cache_get_or_build(bases_t k, ord_t p, ord_t q){

    sshelp_cache_node_t* node = sshelp_cache_find(k, p, q);

    if (node == NULL){

        #pragma omp critical(oti_ss_cache)
        {

            node = sshelp_cache_find(k, p, q);

            if (node == NULL){

                node = (sshelp_cache_node_t*)malloc(sizeof(sshelp_cache_node_t));

                if (node == NULL){
                    printf("ERROR: Not enough memory for the semi-sparse product-table cache. "
                        "Exiting...\n");
                    exit(OTI_OutOfMemory);
                }

                node->k      = k;
                node->p      = p;
                node->q      = q;
                node->stride = sshelp_ndir_order(k, q);
                node->p_tab  = NULL;
                node->ready  = 0;
                node->next   = sshelp_cache_head;

                __atomic_store_n(&sshelp_cache_head, node, __ATOMIC_RELEASE);

            }

        }

    }

    if (__atomic_load_n(&node->ready, __ATOMIC_ACQUIRE) == 0){

        #pragma omp critical(oti_ss_cache)
        {

            if (__atomic_load_n(&node->ready, __ATOMIC_ACQUIRE) == 0){
                sshelp_cache_build(node);
            }

        }

    }

    return node;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void sshelp_cache_free(void){

    sshelp_cache_node_t* node = sshelp_cache_head;
    sshelp_cache_node_t* next;

    while (node != NULL){

        next = node->next;
        free(node->p_tab);
        free(node);
        node = next;

    }

    sshelp_cache_head        = NULL;
    sshelp_cache_bytes_used  = 0;
    sshelp_cache_limit_set   = 0;
    sshelp_cache_limit_bytes = 0;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
sshelp_pair_t sshelp_get_pair(bases_t k, ord_t p, ord_t q, dhelpl_t dhl){

    sshelp_pair_t pair;
    const imdir2d_t* p_tabl;
    unsigned ord_res = (unsigned)p + q;
    sshelp_cache_node_t* node;
    ord_t cp, cq;

    pair.p_tab     = NULL;
    pair.stride    = 0;
    pair.transpose = p > q;

    if (ord_res <= dhl.ndh && k <= dhl.p_dh[ord_res - 1].Nbasis){

        // Rows are the smaller order (dhelp_init_multtabls).
        p_tabl      = dhelp_get_multtabl((ord_t)ord_res, (p > q) ? q : p, dhl);
        pair.p_tab  = p_tabl->p_arr;
        pair.stride = p_tabl->shape[1];

        return pair;

    }

    // Beyond the global table's reach: a lazily built, process-wide local table, within budget.
    cp = (p < q) ? p : q;
    cq = (p < q) ? q : p;

    node = sshelp_cache_get_or_build(k, cp, cq);

    pair.p_tab  = node->p_tab;
    pair.stride = node->stride;

    return pair;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
sshelp_ws_t sshelp_ws_init(void){

    sshelp_ws_t ws;

    ws.p_coef  = NULL;
    ws.p_map   = NULL;
    ws.p_bases = NULL;
    ws.ncoef   = 0;
    ws.nmap    = 0;
    ws.nbases  = 0;

    return ws;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int sshelp_ws_reserve(sshelp_ws_t* ws, size_t ncoef, size_t nmap, size_t nbases){

    if (ncoef > SIZE_MAX / sizeof(coeff_t) || nmap > SIZE_MAX / sizeof(ndir_t)
        || nbases > SIZE_MAX / sizeof(bases_t)){
        return SSHELP_ERR_OVERFLOW;
    }

    if (ncoef > ws->ncoef){

        free(ws->p_coef);
        ws->p_coef = (coeff_t*)malloc(ncoef * sizeof(coeff_t));
        ws->ncoef  = (ws->p_coef == NULL) ? 0 : ncoef;

        if (ws->p_coef == NULL){
            return SSHELP_ERR_MEMORY;
        }

    }

    if (nmap > ws->nmap){

        free(ws->p_map);
        ws->p_map = (ndir_t*)malloc(nmap * sizeof(ndir_t));
        ws->nmap  = (ws->p_map == NULL) ? 0 : nmap;

        if (ws->p_map == NULL){
            return SSHELP_ERR_MEMORY;
        }

    }

    if (nbases > ws->nbases){

        free(ws->p_bases);
        ws->p_bases = (bases_t*)malloc(nbases * sizeof(bases_t));
        ws->nbases  = (ws->p_bases == NULL) ? 0 : nbases;

        if (ws->p_bases == NULL){
            return SSHELP_ERR_MEMORY;
        }

    }

    return SSHELP_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void sshelp_ws_free(sshelp_ws_t* ws){

    free(ws->p_coef);
    free(ws->p_map);
    free(ws->p_bases);

    *ws = sshelp_ws_init();

}
// -------------------------------------------------------------------------------------------------------
