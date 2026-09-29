// Semi-sparse OTI sparse matrices: SoA CSR, triplet (lil) builder, solve (PLAN-semisparse-sparse-
// leveling.md, Phase 6).
// Declarations in include/oti/semisparse/csr/csr.h.
//
// Unity-included from src/c/semisparse.c after the SoA files, so the SoA product-index helpers
// (oarrss_pairsrc_*, soa/kernels.c) and ssoti_out_of_memory() (scalar/memory.c) are in scope.


// -------------------------------------------------------------------------------------------------------
// ---------------------------------------     LOCAL HELPERS     -----------------------------------------
// -------------------------------------------------------------------------------------------------------

// *******************************************************************************************************
// malloc that exits on failure (never returns NULL, also for n == 0).
static void* csrss_malloc(size_t n){

    void* p = malloc(n + 1);

    if (p == NULL){
        ssoti_out_of_memory();
    }

    return p;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// calloc that exits on failure (never returns NULL, also for n == 0).
static void* csrss_calloc(size_t n){

    void* p = calloc(1, n + 1);

    if (p == NULL){
        ssoti_out_of_memory();
    }

    return p;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Hash of a matrix position (splitmix64 finalizer).
static inline uint64_t lilss_hash(uint64_t i, uint64_t j){

    uint64_t h = i * 0x9E3779B97F4A7C15ULL ^ (j + 0x632BE59BD9B4E019ULL);

    h ^= h >> 30;
    h *= 0xBF58476D1CE4E5B9ULL;
    h ^= h >> 27;
    h *= 0x94D049BB133111EBULL;
    h ^= h >> 31;

    return h;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Slot of position (i, j): the slot holding its entry, or the empty slot where it would go.
// Requires nslot > 0.
static inline uint64_t lilss_slot(const lilss_t* lil, uint64_t i, uint64_t j){

    uint64_t mask = lil->nslot - 1;
    uint64_t s = lilss_hash(i, j) & mask;

    for (;;){

        uint64_t e = lil->p_slot[s];

        if (e == 0){
            return s;
        }

        if (lil->p_row[e - 1] == i && lil->p_col[e - 1] == j){
            return s;
        }

        s = (s + 1) & mask;

    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Rebuilds the hash table with nslot slots (a power of two above twice the entry count).
static void lilss_rehash(lilss_t* lil, uint64_t nslot){

    uint64_t e;

    free(lil->p_slot);

    lil->nslot  = nslot;
    lil->p_slot = (uint64_t*)csrss_calloc((size_t)nslot * sizeof(uint64_t));

    for (e = 0; e < lil->nnz; e++){
        lil->p_slot[lilss_slot(lil, lil->p_row[e], lil->p_col[e])] = e + 1;
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Entry index of position (i, j), inserting an entry when there is none. *created tells which; a new
// entry's value is uninitialized (the caller writes it).
static uint64_t lilss_entry(lilss_t* lil, uint64_t i, uint64_t j, int* created){

    uint64_t s, e;

    if (2 * (lil->nnz + 1) > lil->nslot){
        lilss_rehash(lil, (lil->nslot == 0) ? 64 : 2 * lil->nslot);
    }

    s = lilss_slot(lil, i, j);

    if (lil->p_slot[s] != 0){

        *created = 0;
        return lil->p_slot[s] - 1;

    }

    if (lil->nnz == lil->cap){

        uint64_t cap = (lil->cap == 0) ? 64 : 2 * lil->cap;
        ssotinum_t* p_val = (ssotinum_t*)realloc(lil->p_val, (size_t)cap * sizeof(ssotinum_t));
        uint64_t* p_row = (uint64_t*)realloc(lil->p_row, (size_t)cap * sizeof(uint64_t));
        uint64_t* p_col;

        if (p_val == NULL || p_row == NULL){
            ssoti_out_of_memory();
        }

        lil->p_val = p_val;
        lil->p_row = p_row;
        p_col = (uint64_t*)realloc(lil->p_col, (size_t)cap * sizeof(uint64_t));

        if (p_col == NULL){
            ssoti_out_of_memory();
        }

        lil->p_col = p_col;
        lil->cap   = cap;

    }

    e = lil->nnz++;
    lil->p_row[e]  = i;
    lil->p_col[e]  = j;
    lil->p_slot[s] = e + 1;
    *created = 1;

    return e;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Adds element t of a SoA array to a scalar in place when the scalar has the array's active set and at
// least its truncation order (the coefficients then line up, since order offsets depend only on the
// number of bases). Returns 1 when done, 0 (scalar unchanged) otherwise.
static int lilss_add_soa_inplace(ssotinum_t* v, const oarrss_t* arr, uint64_t t){

    ndir_t k, nimag;

    if (v->nbases != arr->nbases || v->trc_order < arr->trc_order){
        return 0;
    }

    if (arr->nbases > 0 && memcmp(v->p_bases, arr->p_bases, (size_t)arr->nbases * sizeof(bases_t)) != 0){
        return 0;
    }

    nimag = ssoti_nimag_checked(arr->nbases, arr->trc_order);
    v->re += arr->p_data[t];

    for (k = 0; k < nimag; k++){
        v->p_im[k] += arr->p_data[(1 + k) * arr->size + t];
    }

    if (arr->act_order > v->act_order){
        v->act_order = arr->act_order;
    }

    return 1;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Tells whether n reals are all zero.
static int csrss_all_zero(const coeff_t* x, uint64_t n){

    uint64_t e;

    for (e = 0; e < n; e++){

        if (x[e] != 0.0){
            return 0;
        }

    }

    return 1;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Per-order remaps of a set's local directions into a larger set's (orders 1..n); map[p] is NULL when
// the set is a leading part of the larger one (identity map at every order).
typedef struct {
    ndir_t*  map[256]; ///< map[p][i]: local index in the larger set of local direction i of order p.
    ord_t          n; ///< Highest order mapped.
} csrss_remap_t;
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Identity remaps (a set onto itself, or onto a set it leads) for orders 1..n.
static void csrss_remap_identity(csrss_remap_t* rm, ord_t n){

    unsigned p;

    rm->n = n;

    for (p = 0; p < 256; p++){
        rm->map[p] = NULL;
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Builds the remaps of a k-base set whose bases sit at pos[] in a ku-base set, for orders 1..n.
static void csrss_remap_init(csrss_remap_t* rm, bases_t k, const bases_t* pos, bases_t ku, ord_t n){

    ord_t p;
    sshelp_rank_tab_t tab;
    bases_t u[256];

    csrss_remap_identity(rm, n);

    if (k == 0 || n == 0 || sshelp_is_leading(pos, k)){
        return;
    }

    if (sshelp_rank_tab_init(&tab, ku, n) != SSHELP_OK){
        ssoti_out_of_memory();
    }

    for (p = 1; p <= n; p++){

        rm->map[p] = (ndir_t*)csrss_malloc((size_t)sshelp_ndir_order(k, p) * sizeof(ndir_t));
        sshelp_remap_order(k, pos, p, &tab, rm->map[p], u);

    }

    sshelp_rank_tab_free(&tab);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
static void csrss_remap_free(csrss_remap_t* rm){

    ord_t p;

    for (p = 0; p <= rm->n; p++){

        free(rm->map[p]);
        rm->map[p] = NULL;

    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Local index in the larger set of local direction i of order p (order 0: the real part, 0).
static inline ndir_t csrss_remap_idx(const csrss_remap_t* rm, ord_t p, ndir_t i){

    if (p == 0 || rm->map[p] == NULL){
        return i;
    }

    return rm->map[p][i];

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// rd[r + c*ldr] += alpha * sum_t v[t] * xj[indices[t] + c*ldx] for every row r and column c < m.
static inline void csrss_spmm_block(const csrss_t* K, const coeff_t* v, const coeff_t* xj,
                                    uint64_t ldx, uint64_t m, coeff_t alpha, coeff_t* rd,
                                    uint64_t ldr){

    uint64_t r, c;
    int64_t t;
    const int64_t* ptr = K->p_indptr;
    const int64_t* idx = K->p_indices;

    for (c = 0; c < m; c++){

        const coeff_t* x = xj + c * ldx;
        coeff_t* y = rd + c * ldr;

        for (r = 0; r < K->nrows; r++){

            coeff_t s = 0.0;

            for (t = ptr[r]; t < ptr[r + 1]; t++){
                s += v[t] * x[idx[t]];
            }

            y[r] += alpha * s;

        }

    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// R += alpha * [K_p X_q] over the ku-base union set, for plo <= p <= phi, qlo <= q <= qhi and
// rlo <= p + q <= rhi. K's values are over kK bases (remap rK), X's over kX bases (remap rX, blocks of
// ldx = ncols(K) * m reals); R is over ku bases, blocks of ldr = nrows(K) * m reals.
static void csrss_kernel_acc(const csrss_t* K, const csrss_remap_t* rK, ord_t plo, ord_t phi,
                             const oarrss_t* X, const csrss_remap_t* rX, ord_t qlo, ord_t qhi,
                             bases_t ku, ord_t rlo, ord_t rhi, coeff_t alpha, coeff_t* R,
                             dhelpl_t dhl){

    const oarrss_t* V = K->p_val;
    bases_t kK = V->nbases, kX = X->nbases;
    uint64_t nnz = V->size, m = X->ncols, ldx = X->size, ldr = K->nrows * X->ncols;
    uint8_t* xnz;
    uint64_t nxb, b;
    ord_t p, q;

    if (qhi > X->trc_order){
        qhi = X->trc_order;
    }

    if (phi > V->trc_order){
        phi = V->trc_order;
    }

    // Nonzero flag of every X block up to order qhi.
    nxb = 1 + sshelp_ndir_total(kX, qhi);
    xnz = (uint8_t*)csrss_malloc((size_t)nxb);

    for (b = 0; b < nxb; b++){
        xnz[b] = !csrss_all_zero(X->p_data + b * ldx, ldx);
    }

    for (p = plo; p <= phi; p++){

        ndir_t Np = sshelp_ndir_order(kK, p), i;
        uint64_t bp = oarrss_block_index(kK, p, 0);

        // Block offsets once per order (block of direction i of order p: bp + i).
        for (q = qlo; q <= qhi; q++){

            ndir_t Nq = sshelp_ndir_order(kX, q), j;
            uint64_t bq, bpq;
            oarrss_pairsrc_t src;

            if (p + q < rlo || p + q > rhi){
                continue;
            }

            bq  = oarrss_block_index(kX, q, 0);
            bpq = oarrss_block_index(ku, p + q, 0);
            src = oarrss_pairsrc_init(ku, p, q, dhl);

            for (i = 0; i < Np; i++){

                const coeff_t* Ki = V->p_data + (bp + i) * nnz;
                ndir_t iu = csrss_remap_idx(rK, p, i);

                if (csrss_all_zero(Ki, nnz)){
                    continue;
                }

                for (j = 0; j < Nq; j++){

                    uint64_t bx = bq + j;
                    ndir_t ju, d;

                    if (!xnz[bx]){
                        continue;
                    }

                    ju = csrss_remap_idx(rX, q, j);
                    d  = oarrss_pairsrc_idx(&src, iu, ju);

                    csrss_spmm_block(K, Ki, X->p_data + bx * ldx, K->ncols, m, alpha,
                        R + (bpq + d) * ldr, K->nrows);

                }

            }

            oarrss_pairsrc_free(&src);

        }

    }

    free(xnz);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Positions of the k bases of `small` inside the ku bases of `big` (both sorted). Returns 1 when every
// base is found, 0 otherwise.
static int csrss_positions(const bases_t* small, bases_t k, const bases_t* big, bases_t ku,
                           bases_t* pos){

    bases_t a = 0, b = 0;

    while (a < k){

        while (b < ku && big[b] < small[a]){
            b++;
        }

        if (b == ku || big[b] != small[a]){
            return 0;
        }

        pos[a++] = b++;

    }

    return 1;

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// ---------------------------------------    TRIPLET BUILDER   ------------------------------------------
// -------------------------------------------------------------------------------------------------------

// *******************************************************************************************************
lilss_t lilss_init(uint64_t nrows, uint64_t ncols){

    lilss_t lil;

    lil.p_val  = NULL;
    lil.p_row  = NULL;
    lil.p_col  = NULL;
    lil.p_slot = NULL;
    lil.nnz    = 0;
    lil.cap    = 0;
    lil.nslot  = 0;
    lil.nrows  = nrows;
    lil.ncols  = ncols;

    return lil;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void lilss_free(lilss_t* lil){

    uint64_t e;

    for (e = 0; e < lil->nnz; e++){
        ssoti_free(&lil->p_val[e]);
    }

    free(lil->p_val);
    free(lil->p_row);
    free(lil->p_col);
    free(lil->p_slot);

    *lil = lilss_init(lil->nrows, lil->ncols);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
const ssotinum_t* lilss_get(const lilss_t* lil, uint64_t i, uint64_t j){

    uint64_t e;

    if (lil->nnz == 0){
        return NULL;
    }

    e = lil->p_slot[lilss_slot(lil, i, j)];

    return (e == 0) ? NULL : &lil->p_val[e - 1];

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void lilss_set(lilss_t* lil, uint64_t i, uint64_t j, const ssotinum_t* val){

    int created;
    uint64_t e = lilss_entry(lil, i, j, &created);

    if (created){
        lil->p_val[e] = ssoti_copy(val);
    } else {
        ssoti_copy_to(val, &lil->p_val[e]);
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void lilss_set_r(lilss_t* lil, uint64_t i, uint64_t j, coeff_t val){

    int created;
    uint64_t e = lilss_entry(lil, i, j, &created);

    // A real replaces the entry entirely (order 0, no bases), as a new sotinum does in pyoti.sparse.
    if (!created){
        ssoti_free(&lil->p_val[e]);
    }

    lil->p_val[e] = ssoti_create_r(val, 0);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void lilss_add(lilss_t* lil, uint64_t i, uint64_t j, const ssotinum_t* val, dhelpl_t dhl){

    int created;
    uint64_t e = lilss_entry(lil, i, j, &created);

    if (created){
        lil->p_val[e] = ssoti_copy(val);
    } else {
        ssoti_sum_oo_to(&lil->p_val[e], val, &lil->p_val[e], dhl);
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int lilss_add_block(lilss_t* lil, const uint64_t* rows, uint64_t nr, const uint64_t* cols, uint64_t nc,
                    const oarrss_t* blk, dhelpl_t dhl){

    ssotinum_t v;
    uint64_t a, b;

    if (blk->nrows != nr || blk->ncols != nc){
        return CSRSS_ERR_SIZE;
    }

    for (a = 0; a < nr; a++){

        if (rows[a] >= lil->nrows){
            return CSRSS_ERR_INDEX;
        }

    }

    for (b = 0; b < nc; b++){

        if (cols[b] >= lil->ncols){
            return CSRSS_ERR_INDEX;
        }

    }

    // Column by column, the order of the SoA elements. A new entry is written straight from the
    // block; a stored one over the block's set takes the block's coefficients in place (the SoA
    // block of local direction k is 1 + k, the scalar's coefficient k); any other goes through a sum.
    v = ssoti_init();

    for (b = 0; b < nc; b++){

        for (a = 0; a < nr; a++){

            int created;
            uint64_t e = lilss_entry(lil, rows[a], cols[b], &created);

            if (created){

                lil->p_val[e] = ssoti_init();
                oarrss_get_item_to(a, b, blk, &lil->p_val[e]);

            } else if (!lilss_add_soa_inplace(&lil->p_val[e], blk, a + b * nr)){

                oarrss_get_item_to(a, b, blk, &v);
                ssoti_sum_oo_to(&lil->p_val[e], &v, &lil->p_val[e], dhl);

            }

        }

    }

    ssoti_free(&v);

    return CSRSS_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void lilss_copy_to(const lilss_t* src, lilss_t* dst){

    uint64_t e;

    if (src == dst){
        return;
    }

    lilss_free(dst);

    dst->nrows = src->nrows;
    dst->ncols = src->ncols;

    if (src->nnz == 0){
        return;
    }

    dst->cap   = src->nnz;
    dst->nnz   = src->nnz;
    dst->p_val = (ssotinum_t*)csrss_malloc((size_t)src->nnz * sizeof(ssotinum_t));
    dst->p_row = (uint64_t*)csrss_malloc((size_t)src->nnz * sizeof(uint64_t));
    dst->p_col = (uint64_t*)csrss_malloc((size_t)src->nnz * sizeof(uint64_t));

    memcpy(dst->p_row, src->p_row, (size_t)src->nnz * sizeof(uint64_t));
    memcpy(dst->p_col, src->p_col, (size_t)src->nnz * sizeof(uint64_t));

    for (e = 0; e < src->nnz; e++){
        dst->p_val[e] = ssoti_copy(&src->p_val[e]);
    }

    dst->nslot  = src->nslot;
    dst->p_slot = (uint64_t*)csrss_malloc((size_t)src->nslot * sizeof(uint64_t));
    memcpy(dst->p_slot, src->p_slot, (size_t)src->nslot * sizeof(uint64_t));

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
ord_t lilss_trc_order(const lilss_t* lil){

    ord_t trc = 0;
    uint64_t e;

    for (e = 0; e < lil->nnz; e++){

        if (lil->p_val[e].trc_order > trc){
            trc = lil->p_val[e].trc_order;
        }

    }

    return trc;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int lilss_sorted(const lilss_t* lil, uint64_t* perm, int64_t* indptr){

    uint64_t n = lil->nnz, e, c, r;
    uint64_t* bycol = (uint64_t*)csrss_malloc((size_t)n * sizeof(uint64_t));
    uint64_t* cstart = (uint64_t*)csrss_calloc((size_t)(lil->ncols + 1) * sizeof(uint64_t));

    // Stable counting sort by column, then by row: rows in order, columns sorted within each row.
    for (e = 0; e < n; e++){
        cstart[lil->p_col[e] + 1]++;
    }

    for (c = 0; c < lil->ncols; c++){
        cstart[c + 1] += cstart[c];
    }

    for (e = 0; e < n; e++){
        bycol[cstart[lil->p_col[e]]++] = e;
    }

    free(cstart);

    for (r = 0; r <= lil->nrows; r++){
        indptr[r] = 0;
    }

    for (e = 0; e < n; e++){
        indptr[lil->p_row[e] + 1]++;
    }

    for (r = 0; r < lil->nrows; r++){
        indptr[r + 1] += indptr[r];
    }

    // indptr[r] is used as the fill cursor of row r, then shifted back.
    for (e = 0; e < n; e++){

        uint64_t s = bycol[e];

        perm[indptr[lil->p_row[s]]++] = s;

    }

    for (r = lil->nrows; r > 0; r--){
        indptr[r] = indptr[r - 1];
    }

    indptr[0] = 0;

    free(bycol);

    return CSRSS_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int lilss_to_csr(const lilss_t* lil, oarrss_t* val, int64_t* indices, int64_t* indptr){

    uint64_t n = lil->nnz, t, e;
    uint8_t* used = (uint8_t*)csrss_calloc(65536);
    bases_t* upos = (bases_t*)csrss_malloc(65536 * sizeof(bases_t));
    bases_t* ubases = (bases_t*)csrss_malloc(65536 * sizeof(bases_t));
    bases_t* pos = (bases_t*)csrss_malloc(65536 * sizeof(bases_t));
    uint64_t* perm = (uint64_t*)csrss_malloc((size_t)n * sizeof(uint64_t));
    const ssotinum_t* last = NULL;
    csrss_remap_t rm;
    ord_t trc = 0, act = 0, p;
    bases_t ku = 0;
    uint32_t label;

    // Union of the entries' active sets, largest truncation and active orders.
    for (e = 0; e < n; e++){

        const ssotinum_t* v = &lil->p_val[e];
        bases_t u;

        for (u = 0; u < v->nbases; u++){
            used[v->p_bases[u]] = 1;
        }

        if (v->trc_order > trc){
            trc = v->trc_order;
        }

        if (v->act_order > act){
            act = v->act_order;
        }

    }

    for (label = 0; label < 65536; label++){

        if (used[label]){

            upos[label]  = ku;
            ubases[ku++] = (bases_t)label;

        }

    }

    free(used);

    if (act > trc){
        act = trc;
    }

    oarrss_free(val);
    *val = oarrss_zeros(ubases, ku, n, 1, trc);
    val->act_order = act;

    lilss_sorted(lil, perm, indptr);
    csrss_remap_identity(&rm, 0);

    for (t = 0; t < n; t++){

        const ssotinum_t* v = &lil->p_val[perm[t]];
        ord_t top = (v->act_order < trc) ? v->act_order : trc;

        indices[t] = (int64_t)lil->p_col[perm[t]];
        val->p_data[t] = v->re;

        if (v->nbases == 0 || top == 0){
            continue;
        }

        // Remaps are rebuilt only when the entry's set differs from the previous one's.
        if (last == NULL || last->nbases != v->nbases ||
            memcmp(last->p_bases, v->p_bases, (size_t)v->nbases * sizeof(bases_t)) != 0){

            bases_t u;

            csrss_remap_free(&rm);

            for (u = 0; u < v->nbases; u++){
                pos[u] = upos[v->p_bases[u]];
            }

            csrss_remap_init(&rm, v->nbases, pos, ku, trc);

        }

        last = v;

        for (p = 1; p <= top; p++){

            ndir_t Np = sshelp_ndir_order(v->nbases, p), i;
            ndir_t off = sshelp_order_offset(v->nbases, p);
            coeff_t* D = val->p_data + oarrss_block_index(ku, p, 0) * n + t;

            for (i = 0; i < Np; i++){
                D[csrss_remap_idx(&rm, p, i) * n] = v->p_im[off + i];
            }

        }

    }

    csrss_remap_free(&rm);
    free(upos);
    free(ubases);
    free(pos);
    free(perm);

    return CSRSS_OK;

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// ---------------------------------------          CSR         ------------------------------------------
// -------------------------------------------------------------------------------------------------------

// *******************************************************************************************************
int csrss_check(const csrss_t* K){

    const oarrss_t* V = K->p_val;
    uint64_t nnz = V->size, r;
    int64_t t;

    if (V->ncols != 1 && nnz > 0){
        return CSRSS_ERR_SIZE;
    }

    if (K->p_indptr[0] != 0 || (uint64_t)K->p_indptr[K->nrows] != nnz){
        return CSRSS_ERR_INDEX;
    }

    for (r = 0; r < K->nrows; r++){

        if (K->p_indptr[r + 1] < K->p_indptr[r]){
            return CSRSS_ERR_INDEX;
        }

        for (t = K->p_indptr[r]; t < K->p_indptr[r + 1]; t++){

            if (K->p_indices[t] < 0 || (uint64_t)K->p_indices[t] >= K->ncols){
                return CSRSS_ERR_INDEX;
            }

        }

    }

    return CSRSS_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void csrss_to_dense(const csrss_t* K, oarrss_t* res){

    const oarrss_t* V = K->p_val;
    uint64_t nnz = V->size, nb = 1 + sshelp_ndir_total(V->nbases, V->trc_order), b, r;
    uint64_t size = K->nrows * K->ncols;
    oarrss_t out = oarrss_zeros(V->p_bases, V->nbases, K->nrows, K->ncols, V->trc_order);

    for (b = 0; b < nb; b++){

        const coeff_t* src = V->p_data + b * nnz;
        coeff_t* dst = out.p_data + b * size;

        for (r = 0; r < K->nrows; r++){

            int64_t t;

            for (t = K->p_indptr[r]; t < K->p_indptr[r + 1]; t++){
                dst[r + (uint64_t)K->p_indices[t] * K->nrows] += src[t];
            }

        }

    }

    out.act_order = V->act_order;

    oarrss_free(res);
    *res = out;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int csrss_matmul_to(const csrss_t* K, const oarrss_t* x, oarrss_t* res, dhelpl_t dhl){

    const oarrss_t* V = K->p_val;
    bases_t kK = V->nbases, kx = x->nbases, nu;
    bases_t* U = (bases_t*)csrss_malloc(((size_t)kK + kx) * sizeof(bases_t));
    bases_t* posK = (bases_t*)csrss_malloc(((size_t)kK + 1) * sizeof(bases_t));
    bases_t* posX = (bases_t*)csrss_malloc(((size_t)kx + 1) * sizeof(bases_t));
    ord_t trc = (V->trc_order > x->trc_order) ? V->trc_order : x->trc_order;
    ord_t aK = (V->act_order < V->trc_order) ? V->act_order : V->trc_order;
    ord_t ax = (x->act_order < x->trc_order) ? x->act_order : x->trc_order;
    csrss_remap_t rK, rX;
    oarrss_t out;

    if (K->ncols != x->nrows){

        free(U);
        free(posK);
        free(posX);
        return CSRSS_ERR_SIZE;

    }

    nu = sshelp_union_bases(V->p_bases, kK, x->p_bases, kx, U, posK, posX);
    out = oarrss_zeros(U, nu, K->nrows, x->ncols, trc);

    csrss_remap_init(&rK, kK, posK, nu, trc);
    csrss_remap_init(&rX, kx, posX, nu, trc);

    if (out.size > 0 && V->size > 0){
        csrss_kernel_acc(K, &rK, 0, aK, x, &rX, 0, ax, nu, 0, trc, 1.0, out.p_data, dhl);
    }

    out.act_order = ((unsigned)aK + ax > trc) ? trc : (ord_t)(aK + ax);

    csrss_remap_free(&rK);
    csrss_remap_free(&rX);
    free(U);
    free(posK);
    free(posX);

    oarrss_free(res);
    *res = out;

    return CSRSS_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int csrss_solve_init(const csrss_t* K, const oarrss_t* b, oarrss_t* u){

    const oarrss_t* V = K->p_val;
    bases_t kK = V->nbases, kb = b->nbases, nu;
    bases_t* U;
    bases_t* posK;
    bases_t* posB;
    ord_t trc = (V->trc_order > b->trc_order) ? V->trc_order : b->trc_order;
    oarrss_t out;

    if (K->nrows != K->ncols || K->nrows != b->nrows){
        return CSRSS_ERR_SIZE;
    }

    U    = (bases_t*)csrss_malloc(((size_t)kK + kb) * sizeof(bases_t));
    posK = (bases_t*)csrss_malloc(((size_t)kK + 1) * sizeof(bases_t));
    posB = (bases_t*)csrss_malloc(((size_t)kb + 1) * sizeof(bases_t));

    nu  = sshelp_union_bases(V->p_bases, kK, b->p_bases, kb, U, posK, posB);
    out = oarrss_zeros(U, nu, b->nrows, b->ncols, trc);

    if (out.size > 0){
        oarrss_kernel_expand(b, posB, nu, trc, out.p_data);
    }

    out.act_order = (b->act_order < trc) ? b->act_order : trc;

    free(U);
    free(posK);
    free(posB);

    oarrss_free(u);
    *u = out;

    return CSRSS_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int csrss_solve_rhs(const csrss_t* K, oarrss_t* u, ord_t n, dhelpl_t dhl){

    const oarrss_t* V = K->p_val;
    bases_t kK = V->nbases;
    bases_t* posK;
    ord_t aK = (V->act_order < V->trc_order) ? V->act_order : V->trc_order;
    ord_t phi = (aK < n) ? aK : n;
    csrss_remap_t rK;

    if (K->nrows != K->ncols || K->ncols != u->nrows){
        return CSRSS_ERR_SIZE;
    }

    if (n == 0 || n > u->trc_order){
        return CSRSS_ERR_ORDER;
    }

    posK = (bases_t*)csrss_malloc(((size_t)kK + 1) * sizeof(bases_t));

    if (!csrss_positions(V->p_bases, kK, u->p_bases, u->nbases, posK)){

        free(posK);
        return CSRSS_ERR_SET;

    }

    if (phi >= 1 && u->size > 0 && V->size > 0){

        csrss_remap_t rU;

        csrss_remap_init(&rK, kK, posK, u->nbases, n);
        csrss_remap_identity(&rU, 0);

        // Reads orders 0 .. n-1 of u, writes order n only: no overlap.
        csrss_kernel_acc(K, &rK, 1, phi, u, &rU, 0, (ord_t)(n - 1), u->nbases, n, n, -1.0,
            u->p_data, dhl);

        csrss_remap_free(&rK);

        if (u->act_order < n){
            u->act_order = n;
        }

    }

    free(posK);

    return CSRSS_OK;

}
// -------------------------------------------------------------------------------------------------------
