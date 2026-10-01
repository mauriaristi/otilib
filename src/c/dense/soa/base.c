// Dense SoA arrays: memory, element and block access, conversions to and from arrso_t, truncation
// and compaction (include/oti/dense/soa/base.h). Template: src/c/semisparse/soa/base.c.
//
// A dense array over bases 1..nact is the semi-sparse layout of the active set [1..nact], so a
// smaller-nact array is a prefix of a larger one: order-p block i of the small layout is block i of
// order p in the large one. Unity-included from src/c/dense.c: static helpers carry the dnob_ prefix.


// *******************************************************************************************************
// nrows * ncols into *p_size; DN_ERR_MEMORY when the product overflows uint64_t.
static int dnob_shape_size(uint64_t nrows, uint64_t ncols, uint64_t* p_size){

    if (ncols != 0 && nrows > UINT64_MAX / ncols){
        return DN_ERR_MEMORY;
    }

    *p_size = nrows * ncols;

    return DN_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Reals of a (1 + nimag(k, trc)) * size buffer into *p_n; DN_ERR_MEMORY when the count or its byte
// size overflows, or the buffer exceeds the dense byte budget (dnsm_budget()).
static int dnob_nreals(bases_t k, ord_t trc, uint64_t size, size_t* p_n){

    ndir_t nimag;
    uint64_t nblocks;

    if (sshelp_ndir_total_checked(k, trc, &nimag) != SSHELP_OK){
        return DN_ERR_MEMORY;
    }

    nblocks = 1 + (uint64_t)nimag;

    if (size != 0 && nblocks > UINT64_MAX / size){
        return DN_ERR_MEMORY;
    }

    if (nblocks * size > SIZE_MAX / sizeof(coeff_t) || dnsm_budget(nblocks * size) != DN_OK){
        return DN_ERR_MEMORY;
    }

    *p_n = (size_t)(nblocks * size);

    return DN_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Reals the layout of an array uses (1 + nimag(nact, trc)) * size. Only for valid arrays, whose count
// was checked when the buffer was allocated.
static inline size_t dnob_used(const oarr_t* arr){

    return (size_t)(1 + sshelp_ndir_total(arr->nact, arr->trc_order)) * arr->size;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Reals the buffer of an array holds at least, from its capacity (0 without a buffer).
static inline size_t dnob_capacity(const oarr_t* arr){

    if (arr->p_data == NULL){
        return 0;
    }

    return (size_t)(1 + sshelp_ndir_total(arr->nbases, arr->trc_order)) * arr->size;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Shapes `res` as an nrows x ncols array over bases 1..nact at truncation order trc, with a buffer of
// at least that layout. The contents are unspecified (the caller writes every value) and act_order
// is left to the caller. The buffer is kept when it is large enough; otherwise a new one replaces it.
// On a failure `res` is unchanged. Returns DN_OK, DN_ERR_INDEX (trc above _MAXORDER_OTI) or
// DN_ERR_MEMORY; *p_n gets the reals of the layout.
static int dnob_result_shape(oarr_t* res, bases_t nact, uint64_t nrows, uint64_t ncols, ord_t trc,
                             size_t* p_n){

    uint64_t size;
    size_t need, have;

    if (trc > _MAXORDER_OTI){
        return DN_ERR_INDEX;
    }

    if (dnob_shape_size(nrows, ncols, &size) != DN_OK || dnob_nreals(nact, trc, size, &need) != DN_OK){
        return DN_ERR_MEMORY;
    }

    have = dnob_capacity(res);

    if (need > have){

        coeff_t* p_new = (coeff_t*)malloc(need * sizeof(coeff_t));

        if (p_new == NULL){
            return DN_ERR_MEMORY;
        }

        free(res->p_data);
        res->p_data = p_new;
        res->nbases = nact;

    } else if (size == res->size && trc <= res->trc_order){

        // The capacity in bases stays valid at a lower truncation order.
        res->nbases = (res->nbases > nact) ? res->nbases : nact;

    } else {

        // Another shape: the buffer holds the layout, but its capacity in bases is only known to
        // cover nact.
        res->nbases = nact;

    }

    res->nact      = nact;
    res->trc_order = trc;
    res->nrows     = nrows;
    res->ncols     = ncols;
    res->size      = size;

    if (p_n != NULL){
        *p_n = need;
    }

    return DN_OK;

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// ---------------------------------------     MEMORY     ------------------------------------------------
// -------------------------------------------------------------------------------------------------------

// *******************************************************************************************************
oarr_t oarr_init(void){

    oarr_t arr;

    arr.p_data    = NULL;
    arr.nbases    = 0;
    arr.nact      = 0;
    arr.trc_order = 0;
    arr.act_order = 0;
    arr.nrows     = 0;
    arr.ncols     = 0;
    arr.size      = 0;

    return arr;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oarr_zeros_to(bases_t nact, uint64_t nrows, uint64_t ncols, ord_t trc_order, oarr_t* res){

    size_t n;
    int status = dnob_result_shape(res, nact, nrows, ncols, trc_order, &n);

    if (status != DN_OK){
        return status;
    }

    if (n > 0){
        memset(res->p_data, 0, n * sizeof(coeff_t));
    }

    res->act_order = 0;

    return DN_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oarr_from_real_to(const coeff_t* data, uint64_t nrows, uint64_t ncols, ord_t trc_order,
                      oarr_t* res){

    int status = oarr_zeros_to(0, nrows, ncols, trc_order, res);

    if (status != DN_OK){
        return status;
    }

    if (data != NULL && res->size > 0){
        memcpy(res->p_data, data, (size_t)res->size * sizeof(coeff_t));
    }

    return DN_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oarr_eye_to(uint64_t n, ord_t trc_order, oarr_t* res){

    uint64_t i;
    int status = oarr_zeros_to(0, n, n, trc_order, res);

    if (status != DN_OK){
        return status;
    }

    for (i = 0; i < n; i++){
        res->p_data[i + i * n] = 1.0;
    }

    return DN_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oarr_reserve(oarr_t* arr, bases_t cap, uint64_t nrows, uint64_t ncols, ord_t trc_order){

    uint64_t size;
    ord_t trc = (trc_order > arr->trc_order) ? trc_order : arr->trc_order;
    bases_t new_cap = (cap > arr->nact) ? cap : arr->nact;
    size_t need, have = dnob_capacity(arr);
    int same;

    if (trc > _MAXORDER_OTI){
        return DN_ERR_INDEX;
    }

    if (dnob_shape_size(nrows, ncols, &size) != DN_OK || dnob_nreals(new_cap, trc, size, &need) != DN_OK){
        return DN_ERR_MEMORY;
    }

    same = (size == arr->size);

    // Capacity rule: keep the buffer when the required layout (new_cap, trc, size) fits it,
    // otherwise allocate exactly that layout; nbases becomes new_cap either way.
    if (need > have){

        coeff_t* p_new;

        if (same){

            // Keeps the values: the layout over nact is unchanged.
            p_new = (coeff_t*)realloc(arr->p_data, need * sizeof(coeff_t));

            if (p_new == NULL){
                return DN_ERR_MEMORY;
            }

        } else {

            // Another size: the contents are undefined, so nothing is copied.
            p_new = (coeff_t*)malloc(need * sizeof(coeff_t));

            if (p_new == NULL){
                return DN_ERR_MEMORY;
            }

            free(arr->p_data);

        }

        arr->p_data = p_new;

    }

    // Same size and a higher order: the new orders are appended after the old ones, zero.
    if (same && size > 0){

        size_t n_old = dnob_used(arr);
        size_t n_new = (size_t)(1 + sshelp_ndir_total(arr->nact, trc)) * size;

        if (n_new > n_old){
            memset(arr->p_data + n_old, 0, (n_new - n_old) * sizeof(coeff_t));
        }

    }

    arr->nbases    = new_cap;
    arr->trc_order = trc;
    arr->nrows     = nrows;
    arr->ncols     = ncols;
    arr->size      = size;

    return DN_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void oarr_free(oarr_t* arr){

    free(arr->p_data);
    *arr = oarr_init();

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oarr_copy_to(const oarr_t* arr, oarr_t* res){

    size_t n;
    int status;

    if (arr == res){
        return DN_OK;
    }

    status = dnob_result_shape(res, arr->nact, arr->nrows, arr->ncols, arr->trc_order, &n);

    if (status != DN_OK){
        return status;
    }

    if (n > 0){
        memcpy(res->p_data, arr->p_data, n * sizeof(coeff_t));
    }

    res->act_order = arr->act_order;

    return DN_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void oarr_kernel_expand(const oarr_t* arr, bases_t ku, ord_t trc, coeff_t* dst){

    bases_t k = arr->nact;
    ord_t p, top = (arr->act_order < trc) ? arr->act_order : trc;
    uint64_t m = arr->size;
    ndir_t Ns, Nd;
    coeff_t* D;

    if (m == 0){
        return;
    }

    memcpy(dst, arr->p_data, (size_t)m * sizeof(coeff_t));

    for (p = 1; p <= trc; p++){

        Nd = sshelp_ndir_order(ku, p);
        D  = dst + oarr_block_index(ku, p, 0) * m;
        Ns = (p > top || k == 0) ? 0 : sshelp_ndir_order(k, p);

        // Prefix property: the order-p blocks of the smaller layout are the first Ns of the larger.
        if (Ns > 0){
            memcpy(D, arr->p_data + oarr_block_index(k, p, 0) * m, (size_t)Ns * m * sizeof(coeff_t));
        }

        memset(D + (size_t)Ns * m, 0, (size_t)(Nd - Ns) * m * sizeof(coeff_t));

    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oarr_add_bases(bases_t nact, oarr_t* arr){

    bases_t kold = arr->nact;
    uint64_t m = arr->size;
    size_t need;
    ord_t p;

    if (nact <= kold){
        return DN_OK;
    }

    if (dnob_nreals(nact, arr->trc_order, m, &need) != DN_OK){
        return DN_ERR_MEMORY;
    }

    if (need == 0){

        arr->nact   = nact;
        arr->nbases = (arr->nbases > nact) ? arr->nbases : nact;

        return DN_OK;

    }

    if (nact <= arr->nbases && arr->p_data != NULL){

        // In place, highest order first: every order block moves up (its offset grows with k), so
        // the source of a lower order is never overwritten before it moves.
        for (p = arr->trc_order; p >= 1; p--){

            ndir_t off_old = sshelp_order_offset(kold, p), n_old = sshelp_ndir_order(kold, p);
            ndir_t off_new = sshelp_order_offset(nact, p), n_new = sshelp_ndir_order(nact, p);

            if (n_old > 0){
                memmove(arr->p_data + (1 + off_new) * m, arr->p_data + (1 + off_old) * m,
                        (size_t)n_old * m * sizeof(coeff_t));
            }

            memset(arr->p_data + (1 + off_new + n_old) * m, 0,
                   (size_t)(n_new - n_old) * m * sizeof(coeff_t));

        }

    } else {

        coeff_t* p_new = (coeff_t*)malloc(need * sizeof(coeff_t));

        if (p_new == NULL){
            return DN_ERR_MEMORY;
        }

        oarr_kernel_expand(arr, nact, arr->trc_order, p_new);
        free(arr->p_data);

        arr->p_data = p_new;
        arr->nbases = nact;

    }

    arr->nact = nact;

    return DN_OK;

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// ---------------------------------------     ACCESS     ------------------------------------------------
// -------------------------------------------------------------------------------------------------------

// *******************************************************************************************************
coeff_t* oarr_get_block(imdir_t idx, ord_t order, const oarr_t* arr){

    if (order == 0){
        return arr->p_data;
    }

    if (order > arr->trc_order || idx >= sshelp_ndir_order(arr->nact, order)){
        return NULL;
    }

    return arr->p_data + oarr_block_index(arr->nact, order, idx) * arr->size;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oarr_get_item_to(uint64_t i, uint64_t j, const oarr_t* arr, otinum_t* res){

    uint64_t e, m = arr->size;
    ndir_t n, nimag;
    int status;

    if (i >= arr->nrows || j >= arr->ncols){
        return DN_ERR_INDEX;
    }

    e     = i + j * arr->nrows;
    nimag = sshelp_ndir_total(arr->nact, arr->trc_order);

    status = oti_reserve(res, arr->nact, arr->trc_order);

    if (status != DN_OK){
        return status;
    }

    // The scalar and block layouts match: coefficient n of the scalar is block 1 + n.
    res->re = arr->p_data[e];

    for (n = 0; n < nimag; n++){
        res->p_im[n] = arr->p_data[(1 + n) * m + e];
    }

    res->nact      = arr->nact;
    res->trc_order = arr->trc_order;
    res->act_order = arr->act_order;

    return DN_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Zeroes every coefficient of element e (the real part included).
static void dnob_clear_elem(uint64_t e, oarr_t* arr){

    size_t b, nblocks = 1 + sshelp_ndir_total(arr->nact, arr->trc_order);

    for (b = 0; b < nblocks; b++){
        arr->p_data[b * arr->size + e] = 0.0;
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oarr_set_item(const otinum_t* num, uint64_t i, uint64_t j, oarr_t* arr){

    uint64_t e, m;
    ord_t p, top;
    int status;

    if (i >= arr->nrows || j >= arr->ncols){
        return DN_ERR_INDEX;
    }

    // Assignment rule: raise nact and the truncation order so that no coefficient of num is lost.
    status = oarr_add_bases(num->nact, arr);

    if (status == DN_OK && num->trc_order > arr->trc_order){
        status = oarr_reserve(arr, arr->nact, arr->nrows, arr->ncols, num->trc_order);
    }

    if (status != DN_OK){
        return status;
    }

    m = arr->size;
    e = i + j * arr->nrows;

    dnob_clear_elem(e, arr);
    arr->p_data[e] = num->re;

    top = (num->act_order < num->trc_order) ? num->act_order : num->trc_order;

    for (p = 1; p <= top && num->nact > 0; p++){

        ndir_t np = sshelp_ndir_order(num->nact, p), idx;
        const coeff_t* src = num->p_im + sshelp_order_offset(num->nact, p);
        coeff_t* dst = arr->p_data + oarr_block_index(arr->nact, p, 0) * m + e;

        for (idx = 0; idx < np; idx++){
            dst[idx * m] = src[idx];
        }

    }

    if (top > arr->act_order){
        arr->act_order = top;
    }

    return DN_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oarr_set_item_r(coeff_t val, uint64_t i, uint64_t j, oarr_t* arr){

    uint64_t e;

    if (i >= arr->nrows || j >= arr->ncols){
        return DN_ERR_INDEX;
    }

    e = i + j * arr->nrows;

    dnob_clear_elem(e, arr);
    arr->p_data[e] = val;

    return DN_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
double oarr_density(const oarr_t* arr){

    size_t nslots = dnob_used(arr) - arr->size, n, nnz = 0;

    if (nslots == 0){
        return 0.0;
    }

    for (n = 0; n < nslots; n++){

        if (arr->p_data[arr->size + n] != 0.0){
            nnz++;
        }

    }

    return (double)nnz / (double)nslots;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
size_t oarr_memory_size(const oarr_t* arr){

    return sizeof(oarr_t) + dnob_capacity(arr) * sizeof(coeff_t);

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// ---------------------------------------     CONVERSION     --------------------------------------------
// -------------------------------------------------------------------------------------------------------

// *******************************************************************************************************
int oarr_from_arrso_to(const arrso_t* arr, oarr_t* res, dhelpl_t dhl){

    uint64_t i, j, m;
    bases_t nact = 0;
    ord_t trc = 0, act = 0, ordi;
    bases_t g[256];
    int status;

    (void)dhl;

    // First pass: the layout (largest base of a stored direction, largest truncation order).
    for (i = 0; i < arr->size; i++){

        const sotinum_t* el = &arr->p_data[i];

        if (el->trc_order > trc){
            trc = el->trc_order;
        }

        for (ordi = 0; ordi < el->trc_order; ordi++){

            ndir_t n;

            if (el->p_nnz[ordi] > 0 && ordi + 1 > act){
                act = (ord_t)(ordi + 1);
            }

            for (n = 0; n < el->p_nnz[ordi]; n++){

                if (sshelp_global_unrank(el->p_idx[ordi][n], (ord_t)(ordi + 1), g) != SSHELP_OK){
                    return DN_ERR_INDEX;
                }

                if (g[ordi] > nact){
                    nact = g[ordi];
                }

            }

        }

    }

    status = oarr_zeros_to(nact, arr->nrows, arr->ncols, trc, res);

    if (status != DN_OK){
        return status;
    }

    m = res->size;

    // arrso_t is row-major, (i, j) at p_data[j + i*ncols]; oarr_t blocks are column-major.
    for (i = 0; i < arr->nrows; i++){

        for (j = 0; j < arr->ncols; j++){

            const sotinum_t* el = &arr->p_data[j + i * arr->ncols];
            uint64_t e = i + j * arr->nrows;

            res->p_data[e] = el->re;

            for (ordi = 0; ordi < el->trc_order; ordi++){

                coeff_t* blk = res->p_data + oarr_block_index(nact, (ord_t)(ordi + 1), 0) * m + e;
                ndir_t n;

                for (n = 0; n < el->p_nnz[ordi]; n++){
                    blk[(size_t)el->p_idx[ordi][n] * m] += el->p_im[ordi][n];
                }

            }

        }

    }

    res->act_order = act;

    return DN_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
arrso_t oarr_to_arrso(const oarr_t* arr, dhelpl_t dhl){

    arrso_t res = arrso_zeros_bases(arr->nrows, arr->ncols, 0, 0, dhl);
    bases_t k = arr->nact;
    ord_t trc = arr->trc_order;
    uint64_t i, j, m = arr->size;

    for (i = 0; i < arr->nrows; i++){

        for (j = 0; j < arr->ncols; j++){

            uint64_t e = i + j * arr->nrows;
            ndir_t p_nnz[_MAXORDER_OTI];
            ord_t ordi, act = 0;
            sotinum_t tmp;

            for (ordi = 0; ordi < trc; ordi++){

                const coeff_t* blk = arr->p_data + oarr_block_index(k, (ord_t)(ordi + 1), 0) * m + e;
                ndir_t n, np = sshelp_ndir_order(k, (ord_t)(ordi + 1));

                p_nnz[ordi] = 0;

                for (n = 0; n < np; n++){

                    if (blk[n * m] != 0.0){
                        p_nnz[ordi]++;
                    }

                }

                if (p_nnz[ordi] > 0){
                    act = (ord_t)(ordi + 1);
                }

            }

            tmp = soti_createEmpty_predef(p_nnz, trc, dhl);
            tmp.re        = arr->p_data[e];
            tmp.act_order = act;

            // Local and global numbering coincide, so each order comes out sorted by global index.
            for (ordi = 0; ordi < trc; ordi++){

                const coeff_t* blk = arr->p_data + oarr_block_index(k, (ord_t)(ordi + 1), 0) * m + e;
                ndir_t n, np = sshelp_ndir_order(k, (ord_t)(ordi + 1)), pos = 0;

                for (n = 0; n < np && pos < p_nnz[ordi]; n++){

                    if (blk[n * m] != 0.0){

                        tmp.p_im[ordi][pos]  = blk[n * m];
                        tmp.p_idx[ordi][pos] = (imdir_t)n;
                        pos++;

                    }

                }

                tmp.p_nnz[ordi] = pos;

            }

            arrso_set_item_ij_o(&tmp, i, j, &res, dhl);
            soti_free(&tmp);

        }

    }

    return res;

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// ---------------------------------------     TRUNCATION     --------------------------------------------
// -------------------------------------------------------------------------------------------------------

// *******************************************************************************************************
// Tells whether the sorted multiset `small` (length p) is contained in the sorted multiset `big`
// (length q).
static int dnob_submultiset(const bases_t* small, ord_t p, const bases_t* big, ord_t q){

    ord_t si = 0, bi = 0;

    while (si < p && bi < q){

        if (small[si] == big[bi]){

            si++;
            bi++;

        } else if (big[bi] < small[si]){

            bi++;

        } else {

            return 0;

        }

    }

    return si == p;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oarr_truncate_im_to(imdir_t idx, ord_t order, const oarr_t* arr, oarr_t* res){

    bases_t g[256], u[256];
    ord_t q, i;
    int status = oarr_copy_to(arr, res);

    if (status != DN_OK){
        return status;
    }

    if (order == 0 || order > res->trc_order || idx >= sshelp_ndir_order(res->nact, order)){
        return DN_OK;
    }

    // Local bases of the direction (global base b is local base b - 1).
    sshelp_unrank(idx, order, g);

    // Every direction of order q >= order that contains it, visited in local index order.
    for (q = order; q <= res->trc_order; q++){

        ndir_t Nq = sshelp_ndir_order(res->nact, q), jj;
        coeff_t* b0 = res->p_data + oarr_block_index(res->nact, q, 0) * res->size;

        for (i = 0; i < q; i++){
            u[i] = 0;
        }

        for (jj = 0; jj < Nq; jj++){

            if (dnob_submultiset(g, order, u, q)){
                memset(b0 + jj * res->size, 0, (size_t)res->size * sizeof(coeff_t));
            }

            sshelp_next_dir(u, q, res->nact);

        }

    }

    return DN_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oarr_truncate_order_to(ord_t order, const oarr_t* arr, oarr_t* res){

    size_t off, n;
    int status = oarr_copy_to(arr, res);

    if (status != DN_OK){
        return status;
    }

    // Order 0 removes everything, the real part included; nact and trc are kept.
    if (order == 0){

        n = dnob_used(res);

        if (n > 0){
            memset(res->p_data, 0, n * sizeof(coeff_t));
        }

        res->act_order = 0;

        return DN_OK;

    }

    if (order > res->trc_order){
        return DN_OK;
    }

    off = (size_t)oarr_block_index(res->nact, order, 0) * res->size;
    n   = dnob_used(res);

    if (n > off){
        memset(res->p_data + off, 0, (n - off) * sizeof(coeff_t));
    }

    if (res->act_order > order - 1){
        res->act_order = (ord_t)(order - 1);
    }

    return DN_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oarr_get_order_im_to(ord_t order, const oarr_t* arr, oarr_t* res){

    size_t n, lo, hi;
    int status = oarr_copy_to(arr, res);

    if (status != DN_OK){
        return status;
    }

    n = dnob_used(res);

    if (n == 0){
        return DN_OK;
    }

    // Blocks [lo, hi) are the kept order; everything else is zeroed.
    if (order > res->trc_order){

        lo = hi = 0;

    } else {

        lo = (size_t)oarr_block_index(res->nact, order, 0) * res->size;
        hi = lo + (size_t)sshelp_ndir_order(res->nact, order) * res->size;

    }

    memset(res->p_data, 0, lo * sizeof(coeff_t));
    memset(res->p_data + hi, 0, (n - hi) * sizeof(coeff_t));

    res->act_order = (order <= res->trc_order) ? order : res->trc_order;

    return DN_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Tells whether n reals starting at x are all zero.
static int dnob_all_zero(const coeff_t* x, size_t n){

    size_t e;

    for (e = 0; e < n; e++){

        if (x[e] != 0.0){
            return 0;
        }

    }

    return 1;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oarr_compact_to(const oarr_t* arr, oarr_t* res){

    bases_t k = arr->nact, knew = 0;
    uint64_t m = arr->size;
    ord_t p, act = 0;
    size_t n;
    int status;

    // Smallest nact that keeps every nonzero block: by the prefix property, the order-p directions
    // over bases 1..k' are the first N_p(k') of the order, so it is the smallest k' above the last
    // nonzero block of each order.
    for (p = 1; p <= arr->trc_order && k > 0 && m > 0; p++){

        const coeff_t* b0 = arr->p_data + oarr_block_index(k, p, 0) * m;
        ndir_t np = sshelp_ndir_order(k, p), last = np;

        while (last > 0 && dnob_all_zero(b0 + (last - 1) * m, (size_t)m)){
            last--;
        }

        if (last == 0){
            continue;
        }

        act = p;

        while (sshelp_ndir_order(knew, p) < last){
            knew++;
        }

    }

    if (res != arr){

        status = dnob_result_shape(res, knew, arr->nrows, arr->ncols, arr->trc_order, &n);

        if (status != DN_OK){
            return status;
        }

    }

    // The new layout is a prefix: moving order blocks down in increasing order never overwrites a
    // block not yet moved (offsets only shrink with k).
    if (m > 0){

        if (res != arr){
            memcpy(res->p_data, arr->p_data, (size_t)m * sizeof(coeff_t));
        }

        for (p = 1; p <= arr->trc_order && knew > 0; p++){

            memmove(res->p_data + oarr_block_index(knew, p, 0) * m,
                    arr->p_data + oarr_block_index(k, p, 0) * m,
                    (size_t)sshelp_ndir_order(knew, p) * m * sizeof(coeff_t));

        }

    }

    res->nact      = knew;
    res->act_order = act;

    return DN_OK;

}
// -------------------------------------------------------------------------------------------------------
