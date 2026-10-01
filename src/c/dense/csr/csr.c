// Dense OTI sparse matrices: SoA CSR, triplet (lil) builder, solve (include/oti/dense/csr/csr.h).
// Template: src/c/semisparse/csr/csr.c, without remaps: a matrix's values (nact_K) and an array's
// blocks (nact_x) are prefixes of the result layout (max nact), read in place at their own offsets
// with product indices from sshelp_get_pair() over the result's nact (dnok_pairsrc_* of
// src/c/dense/soa/kernels.c, earlier in the unity build). Only CSRO_* codes come out; nothing here
// ends the process. Unity-included from src/c/dense.c: static helpers carry the dncs_ prefix.


// -------------------------------------------------------------------------------------------------------
// ---------------------------------------     LOCAL HELPERS     -----------------------------------------
// -------------------------------------------------------------------------------------------------------

// *******************************************************************************************************
// CSRO_* code of a DN_* status of an inner call.
static int dncs_status(int status){

    switch (status){
        case DN_OK:         return CSRO_OK;
        case DN_ERR_SIZE:   return CSRO_ERR_SIZE;
        case DN_ERR_MEMORY: return CSRO_ERR_MEMORY;
        default:            return CSRO_ERR_INDEX;
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Hash of a matrix position (splitmix64 finalizer).
static inline uint64_t dncs_hash(uint64_t i, uint64_t j){

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
// Slot of position (i, j) in a table of nslot slots: the slot holding its entry, or the empty slot
// where it would go. Requires nslot > 0 and a table that is not full.
static inline uint64_t dncs_slot(const uint64_t* p_slot, uint64_t nslot, const uint64_t* p_row,
                                 const uint64_t* p_col, uint64_t i, uint64_t j){

    uint64_t mask = nslot - 1;
    uint64_t s = dncs_hash(i, j) & mask;

    for (;;){

        uint64_t e = p_slot[s];

        if (e == 0 || (p_row[e - 1] == i && p_col[e - 1] == j)){
            return s;
        }

        s = (s + 1) & mask;

    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Rebuilds the hash table with nslot slots. On an allocation failure the old table is kept.
static int dncs_rehash(lilo_t* lil, uint64_t nslot){

    uint64_t* p_slot;
    uint64_t e;

    if (nslot > SIZE_MAX / sizeof(uint64_t)){
        return CSRO_ERR_MEMORY;
    }

    p_slot = (uint64_t*)calloc((size_t)nslot, sizeof(uint64_t));

    if (p_slot == NULL){
        return CSRO_ERR_MEMORY;
    }

    for (e = 0; e < lil->nnz; e++){
        p_slot[dncs_slot(p_slot, nslot, lil->p_row, lil->p_col, lil->p_row[e], lil->p_col[e])] = e + 1;
    }

    free(lil->p_slot);
    lil->p_slot = p_slot;
    lil->nslot  = nslot;

    return CSRO_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Grows the entry arrays to hold at least `cap` entries. On a failure the arrays stay valid.
static int dncs_grow_entries(lilo_t* lil, uint64_t cap){

    otinum_t* p_val;
    uint64_t *p_row, *p_col;

    if (cap <= lil->cap){
        return CSRO_OK;
    }

    if (cap > SIZE_MAX / sizeof(otinum_t)){
        return CSRO_ERR_MEMORY;
    }

    p_val = (otinum_t*)realloc(lil->p_val, (size_t)cap * sizeof(otinum_t));

    if (p_val == NULL){
        return CSRO_ERR_MEMORY;
    }

    lil->p_val = p_val;
    p_row = (uint64_t*)realloc(lil->p_row, (size_t)cap * sizeof(uint64_t));

    if (p_row == NULL){
        return CSRO_ERR_MEMORY;
    }

    lil->p_row = p_row;
    p_col = (uint64_t*)realloc(lil->p_col, (size_t)cap * sizeof(uint64_t));

    if (p_col == NULL){
        return CSRO_ERR_MEMORY;
    }

    lil->p_col = p_col;
    lil->cap   = cap;

    return CSRO_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Entry index of position (i, j), inserting an entry when there is none (*created tells which). A new
// entry's value is a real zero of order 0 (oti_init()), so the builder stays valid whatever the
// caller does next.
static int dncs_entry(lilo_t* lil, uint64_t i, uint64_t j, int* created, uint64_t* p_e){

    uint64_t s = 0, e;
    int status;

    // Probe first: an update of a stored entry never grows anything.
    if (lil->nslot > 0){

        s = dncs_slot(lil->p_slot, lil->nslot, lil->p_row, lil->p_col, i, j);

        if (lil->p_slot[s] != 0){

            *created = 0;
            *p_e     = lil->p_slot[s] - 1;

            return CSRO_OK;

        }

    }

    if (2 * (lil->nnz + 1) > lil->nslot){

        status = dncs_rehash(lil, (lil->nslot == 0) ? 64 : 2 * lil->nslot);

        if (status != CSRO_OK){
            return status;
        }

        s = dncs_slot(lil->p_slot, lil->nslot, lil->p_row, lil->p_col, i, j);

    }

    if (lil->nnz == lil->cap){

        status = dncs_grow_entries(lil, (lil->cap == 0) ? 64 : 2 * lil->cap);

        if (status != CSRO_OK){
            return status;
        }

    }

    e = lil->nnz++;
    lil->p_val[e]  = oti_init();
    lil->p_row[e]  = i;
    lil->p_col[e]  = j;
    lil->p_slot[s] = e + 1;
    *created = 1;
    *p_e     = e;

    return CSRO_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Reserves entry and hash capacity for `extra` more entries, so that the next `extra` insertions
// cannot fail on the builder's own arrays. Nothing changes on a failure.
static int dncs_reserve(lilo_t* lil, uint64_t extra){

    uint64_t need, nslot;
    int status;

    if (extra > UINT64_MAX / 4 - lil->nnz){
        return CSRO_ERR_MEMORY;
    }

    need = lil->nnz + extra;

    if (need > lil->cap){

        uint64_t cap = (lil->cap == 0) ? 64 : 2 * lil->cap;

        status = dncs_grow_entries(lil, (cap > need) ? cap : need);

        if (status != CSRO_OK){
            return status;
        }

    }

    // dncs_entry() inserts without rehashing while 2 * (nnz + 1) <= nslot.
    if (2 * need > lil->nslot){

        nslot = (lil->nslot == 0) ? 64 : 2 * lil->nslot;

        while (nslot < 2 * need){
            nslot *= 2;
        }

        status = dncs_rehash(lil, nslot);

        if (status != CSRO_OK){
            return status;
        }

    }

    return CSRO_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Removes the entry just created by dncs_entry() (the last one) after a failed write. Its slot can
// be cleared: no entry inserted before it probed past a slot that was then empty.
static void dncs_entry_undo(lilo_t* lil, uint64_t e){

    uint64_t s = dncs_slot(lil->p_slot, lil->nslot, lil->p_row, lil->p_col, lil->p_row[e],
                           lil->p_col[e]);

    oti_free(&lil->p_val[e]);
    lil->p_slot[s] = 0;
    lil->nnz--;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Grows a stored value so that its layout holds (nact, trc): coefficients kept, new ones zero.
static int dncs_grow_value(otinum_t* v, bases_t nact, ord_t trc){

    bases_t k = (nact > v->nact) ? nact : v->nact;
    ord_t t = (trc > v->trc_order) ? trc : v->trc_order;
    int status;

    if (k == v->nact && t == v->trc_order){
        return DN_OK;
    }

    // One allocation for both: the capacity first, then the order blocks move within it.
    status = oti_reserve(v, k, t);

    if (status == DN_OK){
        status = oti_add_bases(k, v);
    }

    return status;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// v += (re, im) in place, the addend over ks bases up to order top: its coefficient n is im[n*stride]
// (an otinum_t's p_im with stride 1, or element t of a SoA array: p_data + size + t, stride size).
// Requires v's layout to hold (ks, top).
static void dncs_acc(otinum_t* v, coeff_t re, const coeff_t* im, size_t stride, bases_t ks,
                     ord_t top, ord_t act){

    ord_t p;

    v->re += re;

    for (p = 1; p <= top && ks > 0; p++){

        ndir_t np = sshelp_ndir_order(ks, p), idx;
        coeff_t* dst = v->p_im + sshelp_order_offset(v->nact, p);
        const coeff_t* src = im + (size_t)sshelp_order_offset(ks, p) * stride;

        for (idx = 0; idx < np; idx++){
            dst[idx] += src[idx * stride];
        }

    }

    if (act > v->act_order){
        v->act_order = act;
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// True when `a` is the array `v` or shares its buffer.
static inline int dncs_same_array(const oarr_t* a, const oarr_t* v){

    return a == v || (a->p_data != NULL && a->p_data == v->p_data);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// rd[r + c*ldr] += alpha * sum_t v[t] * xj[indices[t] + c*ldx] for every row r and column c < m.
static inline void dncs_spmm_block(const csro_t* K, const coeff_t* v, const coeff_t* xj, uint64_t ldx,
                                   uint64_t m, coeff_t alpha, coeff_t* rd, uint64_t ldr){

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
// R += alpha * [K_p X_q] over the result layout of k bases, for plo <= p <= phi, qlo <= q <= qhi and
// rlo <= p + q <= rhi. K's values are over their own nact and X's blocks over X's (prefixes of k);
// X's blocks are ncols(K) * m reals, R's nrows(K) * m. R must not overlap the blocks of X read.
static int dncs_kernel_acc(const csro_t* K, ord_t plo, ord_t phi, const oarr_t* X, ord_t qlo,
                           ord_t qhi, bases_t k, ord_t rlo, ord_t rhi, coeff_t alpha, coeff_t* R,
                           dhelpl_t dhl){

    const oarr_t* V = K->p_val;
    bases_t kK = V->nact, kX = X->nact;
    uint64_t nnz = V->size, m = X->ncols, ldx = X->size, ldr = K->nrows * X->ncols;
    uint8_t* xnz;
    size_t nxb, b;
    ord_t p, q;
    bases_t ui[256], uj[256];

    if (qhi > X->trc_order){
        qhi = X->trc_order;
    }

    if (phi > V->trc_order){
        phi = V->trc_order;
    }

    // Nonzero flag of every X block up to order qhi (one byte per block).
    nxb = 1 + sshelp_ndir_total(kX, qhi);
    xnz = (uint8_t*)malloc(nxb);

    if (xnz == NULL){
        return CSRO_ERR_MEMORY;
    }

    for (b = 0; b < nxb; b++){
        xnz[b] = !dnok_all_zero(X->p_data + b * ldx, ldx);
    }

    for (p = plo; p <= phi; p++){

        // Block offsets once per order (direction i of order p: block bp + i).
        ndir_t Np = sshelp_ndir_order(kK, p), i;
        uint64_t bp = oarr_block_index(kK, p, 0);

        for (q = qlo; q <= qhi; q++){

            ndir_t Nq = sshelp_ndir_order(kX, q), j;
            uint64_t bq, bpq;
            dnok_pairsrc_t src;

            if (p + q < rlo || p + q > rhi || Np == 0 || Nq == 0){
                continue;
            }

            bq  = oarr_block_index(kX, q, 0);
            bpq = oarr_block_index(k, (ord_t)(p + q), 0);
            src = dnok_pairsrc_init(k, p, q, dhl);
            dnok_tuple_reset(ui, p);

            for (i = 0; i < Np; i++){

                const coeff_t* Ki = V->p_data + (bp + i) * nnz;

                if (!dnok_all_zero(Ki, nnz)){

                    dnok_tuple_reset(uj, q);

                    for (j = 0; j < Nq; j++){

                        if (xnz[bq + j]){

                            ndir_t d = dnok_pair_idx(&src, i, ui, j, uj);

                            dncs_spmm_block(K, Ki, X->p_data + (bq + j) * ldx, K->ncols, m, alpha,
                                            R + (bpq + d) * ldr, K->nrows);

                        }

                        if (src.fallback){
                            sshelp_next_dir(uj, q, k);
                        }

                    }

                }

                if (src.fallback){
                    sshelp_next_dir(ui, p, k);
                }

            }

            dnok_pairsrc_free(&src);

        }

    }

    free(xnz);

    return CSRO_OK;

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// ---------------------------------------    TRIPLET BUILDER   ------------------------------------------
// -------------------------------------------------------------------------------------------------------

// *******************************************************************************************************
lilo_t lilo_init(uint64_t nrows, uint64_t ncols){

    lilo_t lil;

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
void lilo_free(lilo_t* lil){

    uint64_t e;

    for (e = 0; e < lil->nnz; e++){
        oti_free(&lil->p_val[e]);
    }

    free(lil->p_val);
    free(lil->p_row);
    free(lil->p_col);
    free(lil->p_slot);

    *lil = lilo_init(lil->nrows, lil->ncols);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
const otinum_t* lilo_get(const lilo_t* lil, uint64_t i, uint64_t j){

    uint64_t e;

    if (lil->nnz == 0 || lil->nslot == 0){
        return NULL;
    }

    e = lil->p_slot[dncs_slot(lil->p_slot, lil->nslot, lil->p_row, lil->p_col, i, j)];

    return (e == 0) ? NULL : &lil->p_val[e - 1];

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Tells whether a value lies inside the builder's entry array (a lilo_get() result), which an insertion
// may move.
static int dncs_inside(const lilo_t* lil, const otinum_t* val){

    uintptr_t v = (uintptr_t)val, lo = (uintptr_t)lil->p_val;

    return lil->p_val != NULL && v >= lo && v < lo + (uintptr_t)lil->cap * sizeof(otinum_t);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Calls fn(lil, i, j, val, dhl) with val copied to a call-local number first when it lies inside the
// builder (the entry array may move during the call).
static int dncs_with_copy(lilo_t* lil, uint64_t i, uint64_t j, const otinum_t* val, dhelpl_t dhl,
                          int (*fn)(lilo_t*, uint64_t, uint64_t, const otinum_t*, dhelpl_t)){

    otinum_t tmp;
    int status;

    if (!dncs_inside(lil, val)){
        return fn(lil, i, j, val, dhl);
    }

    tmp    = oti_init();
    status = oti_copy_to(val, &tmp);
    status = (status == DN_OK) ? fn(lil, i, j, &tmp, dhl) : dncs_status(status);
    oti_free(&tmp);

    return status;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// lilo_set() for a value that does not point into the builder.
static int dncs_set(lilo_t* lil, uint64_t i, uint64_t j, const otinum_t* val, dhelpl_t dhl){

    int created, status;
    uint64_t e;

    (void)dhl;

    status = dncs_entry(lil, i, j, &created, &e);

    if (status != CSRO_OK){
        return status;
    }

    status = oti_copy_to(val, &lil->p_val[e]);

    if (status != DN_OK && created){
        dncs_entry_undo(lil, e);
    }

    return dncs_status(status);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int lilo_set(lilo_t* lil, uint64_t i, uint64_t j, const otinum_t* val){

    dhelpl_t none;

    if (i >= lil->nrows || j >= lil->ncols){
        return CSRO_ERR_INDEX;
    }

    // dncs_set() does not use the direction helper.
    memset(&none, 0, sizeof(none));

    return dncs_with_copy(lil, i, j, val, none, dncs_set);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int lilo_set_r(lilo_t* lil, uint64_t i, uint64_t j, coeff_t val){

    int created, status;
    uint64_t e;

    if (i >= lil->nrows || j >= lil->ncols){
        return CSRO_ERR_INDEX;
    }

    status = dncs_entry(lil, i, j, &created, &e);

    if (status != CSRO_OK){
        return status;
    }

    // A real replaces the entry entirely (order 0, no bases), as a new sotinum does in pyoti.sparse.
    // The buffer is kept for a later update; its capacity is valid at the lower order.
    oti_set_r(val, &lil->p_val[e]);
    lil->p_val[e].trc_order = 0;

    return CSRO_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// lilo_add() for a value that does not point into the builder.
static int dncs_add(lilo_t* lil, uint64_t i, uint64_t j, const otinum_t* val, dhelpl_t dhl){

    int created, status;
    uint64_t e;
    otinum_t* v;
    ord_t top = (val->act_order < val->trc_order) ? val->act_order : val->trc_order;

    (void)dhl;

    status = dncs_entry(lil, i, j, &created, &e);

    if (status != CSRO_OK){
        return status;
    }

    v = &lil->p_val[e];

    if (created){

        status = oti_copy_to(val, v);

        if (status != DN_OK){
            dncs_entry_undo(lil, e);
        }

        return dncs_status(status);

    }

    // entry + val: grow the entry to the sum's layout (a no-op when it holds val's), then add val's
    // coefficients at their own offsets (the same values as oti_sum_oo_to()).
    status = dncs_grow_value(v, val->nact, val->trc_order);

    if (status != DN_OK){
        return dncs_status(status);
    }

    dncs_acc(v, val->re, val->p_im, 1, val->nact, top, val->act_order);

    return CSRO_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int lilo_add(lilo_t* lil, uint64_t i, uint64_t j, const otinum_t* val, dhelpl_t dhl){

    if (i >= lil->nrows || j >= lil->ncols){
        return CSRO_ERR_INDEX;
    }

    return dncs_with_copy(lil, i, j, val, dhl, dncs_add);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int lilo_add_block(lilo_t* lil, const uint64_t* rows, uint64_t nr, const uint64_t* cols,
                   uint64_t nc, const oarr_t* blk, dhelpl_t dhl){

    uint64_t a, b, m = blk->size;
    ord_t top = (blk->act_order < blk->trc_order) ? blk->act_order : blk->trc_order;
    const coeff_t* im;
    int status;

    (void)dhl;

    if (blk->nrows != nr || blk->ncols != nc){
        return CSRO_ERR_SIZE;
    }

    for (a = 0; a < nr; a++){

        if (rows[a] >= lil->nrows){
            return CSRO_ERR_INDEX;
        }

    }

    for (b = 0; b < nc; b++){

        if (cols[b] >= lil->ncols){
            return CSRO_ERR_INDEX;
        }

    }

    // Entry and hash capacity for every block element up front: from here on only a value
    // allocation can fail. One check per call when the builder already has room.
    status = dncs_reserve(lil, blk->size);

    if (status != CSRO_OK){
        return status;
    }

    // The addend's coefficients (block 1 + n of element t is coefficient n); none for a real block,
    // whose buffer holds only the real block.
    im = (blk->nact > 0 && blk->trc_order > 0) ? blk->p_data + m : NULL;

    // Column by column, the order of the SoA elements. A new entry is written straight from the
    // block; a stored one is grown to the block's layout when needed and takes the block's
    // coefficients in place. No temporaries.
    for (b = 0; b < nc; b++){

        for (a = 0; a < nr; a++){

            uint64_t t = a + b * nr, e;
            int created;

            status = dncs_entry(lil, rows[a], cols[b], &created, &e);

            if (status != CSRO_OK){
                return status;
            }

            if (created){

                status = oarr_get_item_to(a, b, blk, &lil->p_val[e]);

                if (status != DN_OK){

                    dncs_entry_undo(lil, e);
                    return dncs_status(status);

                }

                continue;

            }

            status = dncs_grow_value(&lil->p_val[e], blk->nact, blk->trc_order);

            if (status != DN_OK){
                return dncs_status(status);
            }

            dncs_acc(&lil->p_val[e], blk->p_data[t], (im != NULL) ? im + t : NULL, (size_t)m, blk->nact,
                     top, blk->act_order);

        }

    }

    return CSRO_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int lilo_copy_to(const lilo_t* src, lilo_t* dst){

    uint64_t e;
    int status;

    if (src == dst){
        return CSRO_OK;
    }

    lilo_free(dst);

    dst->nrows = src->nrows;
    dst->ncols = src->ncols;

    if (src->nnz == 0){
        return CSRO_OK;
    }

    status = dncs_grow_entries(dst, src->nnz);

    if (status == CSRO_OK){

        dst->p_slot = (uint64_t*)malloc((size_t)src->nslot * sizeof(uint64_t));

        if (dst->p_slot == NULL){
            status = CSRO_ERR_MEMORY;
        }

    }

    if (status != CSRO_OK){

        lilo_free(dst);
        return status;

    }

    memcpy(dst->p_row, src->p_row, (size_t)src->nnz * sizeof(uint64_t));
    memcpy(dst->p_col, src->p_col, (size_t)src->nnz * sizeof(uint64_t));
    memcpy(dst->p_slot, src->p_slot, (size_t)src->nslot * sizeof(uint64_t));
    dst->nslot = src->nslot;

    for (e = 0; e < src->nnz; e++){

        dst->p_val[e] = oti_init();
        dst->nnz      = e + 1;
        status        = oti_copy_to(&src->p_val[e], &dst->p_val[e]);

        if (status != DN_OK){

            lilo_free(dst);
            return dncs_status(status);

        }

    }

    return CSRO_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
ord_t lilo_trc_order(const lilo_t* lil){

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
int lilo_sorted(const lilo_t* lil, uint64_t* perm, int64_t* indptr){

    uint64_t n = lil->nnz, e, c, r;
    uint64_t *bycol, *cstart;

    if (lil->ncols >= SIZE_MAX / sizeof(uint64_t) || n > SIZE_MAX / sizeof(uint64_t)){
        return CSRO_ERR_MEMORY;
    }

    bycol  = (uint64_t*)malloc((size_t)n * sizeof(uint64_t) + 1);
    cstart = (uint64_t*)calloc((size_t)lil->ncols + 1, sizeof(uint64_t));

    if (bycol == NULL || cstart == NULL){

        free(bycol);
        free(cstart);
        return CSRO_ERR_MEMORY;

    }

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

    return CSRO_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int lilo_to_csr(const lilo_t* lil, oarr_t* val, int64_t* indices, int64_t* indptr){

    uint64_t n = lil->nnz, t, e;
    uint64_t* perm;
    ord_t trc = 0, act = 0, p;
    bases_t k = 0;
    int status;

    // Layout: the largest nact, truncation order and active order of the entries.
    for (e = 0; e < n; e++){

        const otinum_t* v = &lil->p_val[e];
        ord_t va = (v->act_order < v->trc_order) ? v->act_order : v->trc_order;

        if (v->nact > k){
            k = v->nact;
        }

        if (v->trc_order > trc){
            trc = v->trc_order;
        }

        if (va > act){
            act = va;
        }

    }

    if (n > SIZE_MAX / sizeof(uint64_t)){
        return CSRO_ERR_MEMORY;
    }

    perm = (uint64_t*)malloc((size_t)n * sizeof(uint64_t) + 1);

    if (perm == NULL){
        return CSRO_ERR_MEMORY;
    }

    oarr_free(val);
    status = dncs_status(oarr_zeros_to(k, n, 1, trc, val));

    if (status == CSRO_OK){
        status = lilo_sorted(lil, perm, indptr);
    }

    if (status != CSRO_OK){

        free(perm);
        return status;

    }

    for (t = 0; t < n; t++){

        const otinum_t* v = &lil->p_val[perm[t]];
        ord_t top = (v->act_order < v->trc_order) ? v->act_order : v->trc_order;

        indices[t]     = (int64_t)lil->p_col[perm[t]];
        val->p_data[t] = v->re;

        // Prefix property: the entry's order-p direction i is direction i of the layout.
        for (p = 1; p <= top && v->nact > 0; p++){

            ndir_t Np = sshelp_ndir_order(v->nact, p), i;
            const coeff_t* S = v->p_im + sshelp_order_offset(v->nact, p);
            coeff_t* D = val->p_data + oarr_block_index(k, p, 0) * n + t;

            for (i = 0; i < Np; i++){
                D[i * n] = S[i];
            }

        }

    }

    val->act_order = act;
    free(perm);

    return CSRO_OK;

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// ---------------------------------------          CSR         ------------------------------------------
// -------------------------------------------------------------------------------------------------------

// *******************************************************************************************************
int csro_check(const csro_t* K){

    const oarr_t* V = K->p_val;
    uint64_t nnz = V->size, r;
    int64_t t;

    if (V->ncols != 1 && nnz > 0){
        return CSRO_ERR_SIZE;
    }

    if (K->p_indptr[0] != 0 || K->p_indptr[K->nrows] < 0 || (uint64_t)K->p_indptr[K->nrows] != nnz){
        return CSRO_ERR_INDEX;
    }

    for (r = 0; r < K->nrows; r++){

        if (K->p_indptr[r + 1] < K->p_indptr[r]){
            return CSRO_ERR_INDEX;
        }

    }

    for (r = 0; r < K->nrows; r++){

        for (t = K->p_indptr[r]; t < K->p_indptr[r + 1]; t++){

            if (K->p_indices[t] < 0 || (uint64_t)K->p_indices[t] >= K->ncols){
                return CSRO_ERR_INDEX;
            }

        }

    }

    return CSRO_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int csro_to_dense(const csro_t* K, oarr_t* res){

    const oarr_t* V = K->p_val;
    uint64_t nnz = V->size, r, size;
    size_t nb, b;
    oarr_t out = oarr_init();
    int status;

    // Built apart and moved in, so res may be the matrix's own value array.
    status = dncs_status(oarr_zeros_to(V->nact, K->nrows, K->ncols, V->trc_order, &out));

    if (status != CSRO_OK){
        return status;
    }

    size = out.size;
    nb   = (size_t)(1 + sshelp_ndir_total(V->nact, V->trc_order));

    for (b = 0; b < nb && size > 0 && nnz > 0; b++){

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

    oarr_free(res);
    *res = out;

    return CSRO_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int csro_matmul_to(const csro_t* K, const oarr_t* x, oarr_t* res, dhelpl_t dhl){

    const oarr_t* V = K->p_val;
    bases_t k = (V->nact > x->nact) ? V->nact : x->nact;
    ord_t trc = (V->trc_order > x->trc_order) ? V->trc_order : x->trc_order;
    ord_t aK = (V->act_order < V->trc_order) ? V->act_order : V->trc_order;
    ord_t ax = (x->act_order < x->trc_order) ? x->act_order : x->trc_order;
    oarr_t local = oarr_init();
    oarr_t* out = (res == V) ? &local : res;
    size_t n;
    int status;

    if (K->ncols != x->nrows || dncs_same_array(x, V)){
        return CSRO_ERR_SIZE;
    }

    // Straight into res; into a local array when res is the matrix's own value array.
    status = dncs_status(dnob_result_shape(out, k, K->nrows, x->ncols, trc, &n));

    if (status != CSRO_OK){
        return status;
    }

    if (n > 0){
        memset(out->p_data, 0, n * sizeof(coeff_t));
    }

    if (n > 0 && V->size > 0){
        status = dncs_kernel_acc(K, 0, aK, x, 0, ax, k, 0, trc, 1.0, out->p_data, dhl);
    }

    out->act_order = ((unsigned)aK + ax > trc) ? trc : (ord_t)(aK + ax);

    if (out == &local){

        if (status == CSRO_OK){

            oarr_free(res);
            *res = local;

        } else {

            oarr_free(&local);

        }

    }

    return status;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int csro_solve_init(const csro_t* K, const oarr_t* b, oarr_t* u){

    const oarr_t* V = K->p_val;
    bases_t k = (V->nact > b->nact) ? V->nact : b->nact;
    ord_t trc = (V->trc_order > b->trc_order) ? V->trc_order : b->trc_order;
    ord_t act = b->act_order;
    int status;

    if (K->nrows != K->ncols || K->nrows != b->nrows || dncs_same_array(u, V)){
        return CSRO_ERR_SIZE;
    }

    if (u == b){

        // In place: raise the order (new orders zero), then zero-extend the bases.
        status = oarr_reserve(u, k, u->nrows, u->ncols, trc);

        if (status == DN_OK){
            status = oarr_add_bases(k, u);
        }

    } else {

        status = dnob_result_shape(u, k, b->nrows, b->ncols, trc, NULL);

        if (status == DN_OK){
            oarr_kernel_expand(b, k, trc, u->p_data);
        }

    }

    if (status != DN_OK){
        return dncs_status(status);
    }

    u->act_order = (act < trc) ? act : trc;

    return CSRO_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int csro_solve_rhs(const csro_t* K, oarr_t* u, ord_t n, dhelpl_t dhl){

    const oarr_t* V = K->p_val;
    ord_t aK = (V->act_order < V->trc_order) ? V->act_order : V->trc_order;
    ord_t phi = (aK < n) ? aK : n;
    int status = CSRO_OK;

    if (K->nrows != K->ncols || K->ncols != u->nrows){
        return CSRO_ERR_SIZE;
    }

    if (n == 0 || n > u->trc_order){
        return CSRO_ERR_ORDER;
    }

    if (V->nact > u->nact){
        return CSRO_ERR_NACT;
    }

    if (phi >= 1 && u->size > 0 && V->size > 0){

        // Reads orders 0 .. n-1 of u, writes order n only: no overlap.
        status = dncs_kernel_acc(K, 1, phi, u, 0, (ord_t)(n - 1), u->nact, n, n, -1.0, u->p_data, dhl);

        if (status == CSRO_OK && u->act_order < n){
            u->act_order = n;
        }

    }

    return status;

}
// -------------------------------------------------------------------------------------------------------
