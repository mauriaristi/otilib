// Semi-sparse SoA arrays: memory, element and block access, conversions to and from arrso_t,
// truncation. Conventions in include/oti/semisparse/soa/base.h. Reuses the scalar module's
// out-of-memory helper, workspace and overflow-checked coefficient count (ssoti_out_of_memory,
// ssoti_ws, ssoti_ws_need, ssoti_nimag_checked from semisparse/scalar/memory.c).


// *******************************************************************************************************
// Total elements of a shape, exiting on uint64_t overflow of the product.
static uint64_t oarrss_shape_size(uint64_t nrows, uint64_t ncols){

    if (ncols != 0 && nrows > UINT64_MAX / ncols){
        ssoti_out_of_memory();
    }

    return nrows * ncols;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Bytes of a (1 + nimag(k, trc)) * size coefficient buffer, exiting on overflow.
static size_t oarrss_databytes(bases_t k, ord_t trc, uint64_t size){

    ndir_t nimag = ssoti_nimag_checked(k, trc);
    uint64_t nblocks = 1 + nimag, nelems;

    if (nblocks != 0 && size > UINT64_MAX / nblocks){
        ssoti_out_of_memory();
    }

    nelems = nblocks * size;

    if (nelems != 0 && nelems > SIZE_MAX / sizeof(coeff_t)){
        ssoti_out_of_memory();
    }

    return (size_t)nelems * sizeof(coeff_t);

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// ---------------------------------------     MEMORY     ------------------------------------------------
// -------------------------------------------------------------------------------------------------------

// *******************************************************************************************************
oarrss_t oarrss_init(void){

    oarrss_t arr;

    arr.p_data    = NULL;
    arr.p_bases   = NULL;
    arr.nbases    = 0;
    arr.cap_bases = 0;
    arr.act_order = 0;
    arr.trc_order = 0;
    arr.nrows     = 0;
    arr.ncols     = 0;
    arr.size      = 0;
    arr.flag      = 1;

    return arr;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
oarrss_t oarrss_zeros(const bases_t* bases, bases_t k, uint64_t nrows, uint64_t ncols,
                      ord_t trc_order){

    oarrss_t arr = oarrss_init();
    uint64_t size = oarrss_shape_size(nrows, ncols);
    size_t nbytes = oarrss_databytes(k, trc_order, size);

    arr.trc_order = trc_order;
    arr.nrows     = nrows;
    arr.ncols     = ncols;
    arr.size      = size;

    if (k > 0){

        arr.p_bases = (bases_t*)malloc((size_t)k * sizeof(bases_t));

        if (arr.p_bases == NULL){
            ssoti_out_of_memory();
        }

        memcpy(arr.p_bases, bases, (size_t)k * sizeof(bases_t));

    }

    arr.p_data = (nbytes > 0) ? (coeff_t*)calloc(1, nbytes) : NULL;

    if (nbytes > 0 && arr.p_data == NULL){
        ssoti_out_of_memory();
    }

    arr.nbases    = k;
    arr.cap_bases = k;

    return arr;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
oarrss_t oarrss_from_real(const coeff_t* data, uint64_t nrows, uint64_t ncols, ord_t trc_order){

    oarrss_t arr = oarrss_zeros(NULL, 0, nrows, ncols, trc_order);

    if (data != NULL && arr.size > 0){
        memcpy(arr.p_data, data, (size_t)arr.size * sizeof(coeff_t));
    }

    return arr;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
oarrss_t oarrss_eye(uint64_t n, ord_t trc_order){

    oarrss_t arr = oarrss_zeros(NULL, 0, n, n, trc_order);
    uint64_t i;

    for (i = 0; i < n; i++){
        arr.p_data[i + i * n] = 1.0;
    }

    return arr;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void oarrss_reserve(oarrss_t* arr, bases_t cap, uint64_t nrows, uint64_t ncols, ord_t trc_order){

    uint64_t new_size = oarrss_shape_size(nrows, ncols);
    int same_size = (new_size == arr->size);
    int need_grow = (cap > arr->cap_bases) || (trc_order > arr->trc_order) || !same_size;

    if (need_grow){

        bases_t new_cap;
        ord_t new_trc;
        size_t new_bytes;
        bases_t* p_bases;
        coeff_t* p_data;

        if (arr->flag == 0){
            printf("ERROR: Cannot grow a semi-sparse SoA view. Exiting...\n");
            exit(OTI_BadIndx);
        }

        new_cap = (cap > arr->cap_bases) ? cap : arr->cap_bases;
        new_trc = (trc_order > arr->trc_order) ? trc_order : arr->trc_order;
        new_bytes = oarrss_databytes(new_cap, new_trc, new_size);

        if (new_cap > 0){

            p_bases = (bases_t*)realloc(arr->p_bases, (size_t)new_cap * sizeof(bases_t));

            if (p_bases == NULL){
                ssoti_out_of_memory();
            }

            arr->p_bases = p_bases;

        }

        p_data = (new_bytes > 0) ? (coeff_t*)realloc(arr->p_data, new_bytes) : arr->p_data;

        if (new_bytes > 0 && p_data == NULL){
            ssoti_out_of_memory();
        }

        arr->p_data = p_data;

        if (same_size){

            uint64_t nused_old = (1 + sshelp_ndir_total(arr->nbases, arr->trc_order)) * arr->size;
            uint64_t nused_new = (1 + sshelp_ndir_total(arr->nbases, new_trc)) * arr->size;

            if (nused_new > nused_old){
                memset(arr->p_data + nused_old, 0, (nused_new - nused_old) * sizeof(coeff_t));
            }

        }

        arr->cap_bases = new_cap;
        arr->trc_order = new_trc;

    }

    arr->nrows = nrows;
    arr->ncols = ncols;
    arr->size  = new_size;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void oarrss_free(oarrss_t* arr){

    if (arr->flag != 0){

        free(arr->p_data);
        free(arr->p_bases);

    }

    *arr = oarrss_init();

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
oarrss_t oarrss_copy(const oarrss_t* arr){

    oarrss_t res = oarrss_zeros(arr->p_bases, arr->nbases, arr->nrows, arr->ncols, arr->trc_order);

    oarrss_copy_to(arr, &res);

    return res;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void oarrss_copy_to(const oarrss_t* arr, oarrss_t* res){

    size_t nbytes;

    if (arr == res){
        return;
    }

    oarrss_reserve(res, arr->nbases, arr->nrows, arr->ncols, arr->trc_order);

    if (arr->nbases > 0){
        memcpy(res->p_bases, arr->p_bases, (size_t)arr->nbases * sizeof(bases_t));
    }

    nbytes = oarrss_databytes(arr->nbases, arr->trc_order, arr->size);
    memcpy(res->p_data, arr->p_data, nbytes);

    res->nbases    = arr->nbases;
    res->act_order = arr->act_order;
    res->trc_order = arr->trc_order;
    res->nrows     = arr->nrows;
    res->ncols     = arr->ncols;
    res->size      = arr->size;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void oarrss_kernel_expand(const oarrss_t* arr, const bases_t* pos, bases_t ku, ord_t trc,
                          coeff_t* dst){

    bases_t k = arr->nbases;
    int leading = sshelp_is_leading(pos, k);
    ord_t p, i, top = (arr->act_order < trc) ? arr->act_order : trc;
    ndir_t j, Ns, Nd;
    uint64_t m = arr->size;
    const coeff_t* S;
    coeff_t* D;
    sshelp_rank_tab_t tab = {NULL, 0, 0};
    bases_t u[256], v[256];

    memcpy(dst, arr->p_data, (size_t)m * sizeof(coeff_t));

    if (!leading && sshelp_rank_tab_init(&tab, ku, trc) != SSHELP_OK){
        ssoti_out_of_memory();
    }

    for (p = 1; p <= trc; p++){

        Nd = sshelp_ndir_order(ku, p);
        D  = dst + oarrss_block_index(ku, p, 0) * m;

        if (p > top || k == 0){

            memset(D, 0, (size_t)Nd * m * sizeof(coeff_t));
            continue;

        }

        Ns = sshelp_ndir_order(k, p);
        S  = arr->p_data + oarrss_block_index(k, p, 0) * m;

        if (leading){

            memcpy(D, S, (size_t)Ns * m * sizeof(coeff_t));
            memset(D + (size_t)Ns * m, 0, (size_t)(Nd - Ns) * m * sizeof(coeff_t));

        } else {

            memset(D, 0, (size_t)Nd * m * sizeof(coeff_t));

            for (i = 0; i < p; i++){
                u[i] = 0;
            }

            for (j = 0; j < Ns; j++){

                for (i = 0; i < p; i++){
                    v[i] = pos[u[i]];
                }

                memcpy(D + (size_t)sshelp_rank(v, p, &tab) * m, S + (size_t)j * m,
                    m * sizeof(coeff_t));
                sshelp_next_dir(u, p, k);

            }

        }

    }

    sshelp_rank_tab_free(&tab);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void oarrss_add_bases(const bases_t* bases, bases_t k, oarrss_t* arr){

    sshelp_ws_t* ws = ssoti_ws();
    bases_t *p_union, *p_pos, nu, kold = arr->nbases;
    size_t nb = (size_t)kold + k;
    ord_t p;

    if (k == 0){
        return;
    }

    ssoti_ws_need(ws, 0, 0, 2 * nb);
    p_union = ws->p_bases;
    p_pos   = ws->p_bases + nb;

    nu = sshelp_union_bases(arr->p_bases, kold, bases, k, p_union, p_pos, NULL);

    if (nu == kold){
        return;
    }

    oarrss_reserve(arr, nu, arr->nrows, arr->ncols, arr->trc_order);

    // The union may be moved by the workspace below, so store it first.
    memcpy(arr->p_bases, p_union, (size_t)nu * sizeof(bases_t));

    if (sshelp_is_leading(p_pos, kold)){

        // Zero-extension in place, highest order first: every block moves up by `size` stride.
        for (p = arr->trc_order; p >= 1; p--){

            ndir_t off_old = sshelp_order_offset(kold, p), n_old = sshelp_ndir_order(kold, p);
            ndir_t off_new = sshelp_order_offset(nu, p),   n_new = sshelp_ndir_order(nu, p);
            uint64_t m = arr->size;

            if (n_old > 0){
                memmove(arr->p_data + (1 + off_new) * m, arr->p_data + (1 + off_old) * m,
                    (size_t)n_old * m * sizeof(coeff_t));
            }

            memset(arr->p_data + (1 + off_new + n_old) * m, 0,
                (size_t)(n_new - n_old) * m * sizeof(coeff_t));

        }

    } else {

        // Remap through scratch: the source layout is still the old set's.
        size_t need = (size_t)(1 + sshelp_ndir_total(nu, arr->trc_order)) * arr->size;

        ssoti_ws_need(ws, need, 0, 0);

        oarrss_kernel_expand(arr, p_pos, nu, arr->trc_order, ws->p_coef);
        memcpy(arr->p_data, ws->p_coef, need * sizeof(coeff_t));

    }

    arr->nbases = nu;

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// ---------------------------------------     ACCESS     ------------------------------------------------
// -------------------------------------------------------------------------------------------------------

// *******************************************************************************************************
coeff_t* oarrss_get_block(imdir_t idx, ord_t order, const oarrss_t* arr){

    ndir_t local;

    if (order == 0){
        return arr->p_data;
    }

    if (order > arr->trc_order){
        return NULL;
    }

    if (sshelp_global_to_local(idx, order, arr->p_bases, arr->nbases, &local) != 1){
        return NULL;
    }

    return arr->p_data + oarrss_block_index(arr->nbases, order, local) * arr->size;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
ssotinum_t oarrss_get_item(uint64_t i, uint64_t j, const oarrss_t* arr){

    ssotinum_t res = ssoti_init();

    oarrss_get_item_to(i, j, arr, &res);

    return res;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void oarrss_get_item_to(uint64_t i, uint64_t j, const oarrss_t* arr, ssotinum_t* res){

    uint64_t e = i + j * arr->nrows;
    ord_t p;

    ssoti_reserve(res, arr->nbases, arr->trc_order);

    if (arr->nbases > 0){
        memcpy(res->p_bases, arr->p_bases, (size_t)arr->nbases * sizeof(bases_t));
    }

    res->re = arr->p_data[e];

    for (p = 1; p <= arr->trc_order; p++){

        ndir_t np  = sshelp_ndir_order(arr->nbases, p);
        ndir_t off = sshelp_order_offset(arr->nbases, p);
        ndir_t idx;

        for (idx = 0; idx < np; idx++){
            res->p_im[off + idx] = arr->p_data[oarrss_block_index(arr->nbases, p, idx) * arr->size + e];
        }

    }

    res->nbases    = arr->nbases;
    res->trc_order = arr->trc_order;
    res->act_order = arr->act_order;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void oarrss_set_item(const ssotinum_t* num, uint64_t i, uint64_t j, oarrss_t* arr){

    uint64_t e;
    ord_t p, top;
    ndir_t idx;

    oarrss_add_bases(num->p_bases, num->nbases, arr);

    e = i + j * arr->nrows;

    // Full overwrite: zero every existing slot of this element first.
    arr->p_data[e] = 0.0;

    for (p = 1; p <= arr->trc_order; p++){

        ndir_t np = sshelp_ndir_order(arr->nbases, p);

        for (idx = 0; idx < np; idx++){
            arr->p_data[oarrss_block_index(arr->nbases, p, idx) * arr->size + e] = 0.0;
        }

    }

    arr->p_data[e] = num->re;

    top = (num->act_order < arr->trc_order) ? num->act_order : arr->trc_order;

    for (p = 1; p <= top; p++){

        ndir_t np  = sshelp_ndir_order(num->nbases, p);
        ndir_t off = sshelp_order_offset(num->nbases, p);

        for (idx = 0; idx < np; idx++){

            coeff_t val = num->p_im[off + idx];
            imdir_t gidx;
            ndir_t aidx;

            if (val == 0.0){
                continue;
            }

            if (sshelp_local_to_global(idx, p, num->p_bases, num->nbases, &gidx) != SSHELP_OK){
                continue;
            }

            if (sshelp_global_to_local(gidx, p, arr->p_bases, arr->nbases, &aidx) != 1){
                continue;
            }

            arr->p_data[oarrss_block_index(arr->nbases, p, aidx) * arr->size + e] = val;

        }

    }

    if (top > arr->act_order){
        arr->act_order = top;
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void oarrss_set_item_r(coeff_t val, uint64_t i, uint64_t j, oarrss_t* arr){

    uint64_t e = i + j * arr->nrows;
    ord_t p;

    arr->p_data[e] = val;

    for (p = 1; p <= arr->trc_order; p++){

        ndir_t np = sshelp_ndir_order(arr->nbases, p);
        ndir_t idx;

        for (idx = 0; idx < np; idx++){
            arr->p_data[oarrss_block_index(arr->nbases, p, idx) * arr->size + e] = 0.0;
        }

    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
double oarrss_density(const oarrss_t* arr){

    ndir_t nimag = sshelp_ndir_total(arr->nbases, arr->trc_order);
    uint64_t nslots = (uint64_t)nimag * arr->size;
    uint64_t nnz = 0, n;

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
size_t oarrss_memory_size(const oarrss_t* arr){

    size_t bytes = sizeof(oarrss_t);

    bytes += (size_t)arr->cap_bases * sizeof(bases_t);
    bytes += oarrss_databytes(arr->cap_bases, arr->trc_order, arr->size);

    return bytes;

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// ---------------------------------------     CONVERSION     --------------------------------------------
// -------------------------------------------------------------------------------------------------------

// *******************************************************************************************************
oarrss_t oarrss_from_arrso(const arrso_t* arr, dhelpl_t dhl){

    uint64_t i, j, n = arr->size;
    ssotinum_t* tmp = NULL;
    bases_t* p_union = NULL;
    bases_t nu = 0;
    ord_t trc = 0;
    oarrss_t res;

    if (n > 0){

        tmp = (ssotinum_t*)malloc(n * sizeof(ssotinum_t));

        if (tmp == NULL){
            ssoti_out_of_memory();
        }

        trc = arr->p_data[0].trc_order;

    }

    // arrso_t stores elements row-major: (i, j) is p_data[j + i*ncols].
    for (i = 0; i < arr->nrows; i++){

        for (j = 0; j < arr->ncols; j++){

            uint64_t e_row = j + i * arr->ncols;
            bases_t* p_new;
            bases_t nnew;

            tmp[e_row] = ssoti_from_soti(&arr->p_data[e_row], dhl);

            if (arr->p_data[e_row].trc_order > trc){
                trc = arr->p_data[e_row].trc_order;
            }

            p_new = (bases_t*)malloc(((size_t)nu + tmp[e_row].nbases) * sizeof(bases_t) + 1);

            if (p_new == NULL){
                ssoti_out_of_memory();
            }

            nnew = sshelp_union_bases(p_union, nu, tmp[e_row].p_bases, tmp[e_row].nbases, p_new,
                NULL, NULL);

            free(p_union);
            p_union = p_new;
            nu      = nnew;

        }

    }

    // oarrss_t blocks are column-major: (i, j) is p_data[i + j*nrows].
    res = oarrss_zeros(p_union, nu, arr->nrows, arr->ncols, trc);

    for (i = 0; i < arr->nrows; i++){

        for (j = 0; j < arr->ncols; j++){

            uint64_t e_row = j + i * arr->ncols;

            oarrss_set_item(&tmp[e_row], i, j, &res);
            ssoti_free(&tmp[e_row]);

        }

    }

    free(p_union);
    free(tmp);

    return res;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
arrso_t oarrss_to_arrso(const oarrss_t* arr, dhelpl_t dhl){

    arrso_t res = arrso_zeros_bases(arr->nrows, arr->ncols, 0, 0, dhl);
    ssotinum_t tmp = ssoti_init();
    uint64_t i, j;

    for (i = 0; i < arr->nrows; i++){

        for (j = 0; j < arr->ncols; j++){

            sotinum_t stmp;

            oarrss_get_item_to(i, j, arr, &tmp);
            stmp = ssoti_to_soti(&tmp, dhl);
            // arrso_t stores elements row-major; arrso_set_item_ij_o handles the j + i*ncols mapping.
            arrso_set_item_ij_o(&stmp, i, j, &res, dhl);
            soti_free(&stmp);

        }

    }

    ssoti_free(&tmp);

    return res;

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// ---------------------------------------     TRUNCATION     --------------------------------------------
// -------------------------------------------------------------------------------------------------------

// *******************************************************************************************************
// Tells whether the sorted multiset `small` (length p) is contained in the sorted multiset `big`
// (length q).
static int oarrss_submultiset(const bases_t* small, ord_t p, const bases_t* big, ord_t q){

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
// Binary search of a global base label in a sorted active-base list.
static int oarrss_base_search(bases_t label, const bases_t* bases, bases_t k, bases_t* out){

    bases_t lo = 0, hi = k;

    while (lo < hi){

        bases_t mid = (bases_t)(lo + (hi - lo) / 2);

        if (bases[mid] == label){

            *out = mid;
            return 1;

        }

        if (bases[mid] < label){
            lo = (bases_t)(mid + 1);
        } else {
            hi = mid;
        }

    }

    return 0;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void oarrss_truncate_im_to(imdir_t idx, ord_t order, const oarrss_t* arr, oarrss_t* res){

    bases_t g[256], gl[256];
    ord_t q, i;
    int all_active = 1;

    oarrss_copy_to(arr, res);

    if (order == 0 || order > res->trc_order){
        return;
    }

    if (sshelp_global_unrank(idx, order, g) != SSHELP_OK){
        return;
    }

    for (i = 0; i < order; i++){

        if (!oarrss_base_search(g[i], res->p_bases, res->nbases, &gl[i])){

            all_active = 0;
            break;

        }

    }

    if (!all_active){
        return;
    }

    for (q = order; q <= res->trc_order; q++){

        ndir_t Nq = sshelp_ndir_order(res->nbases, q), jj;
        bases_t* dirs = (bases_t*)malloc((size_t)Nq * q * sizeof(bases_t) + 1);

        if (dirs == NULL){
            ssoti_out_of_memory();
        }

        sshelp_local_dirs(res->nbases, q, dirs);

        for (jj = 0; jj < Nq; jj++){

            if (oarrss_submultiset(gl, order, &dirs[(size_t)jj * q], q)){

                coeff_t* blk = res->p_data + oarrss_block_index(res->nbases, q, jj) * res->size;
                memset(blk, 0, (size_t)res->size * sizeof(coeff_t));

            }

        }

        free(dirs);

    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void oarrss_truncate_order_to(ord_t order, const oarrss_t* arr, oarrss_t* res){

    uint64_t off, nblocks;

    oarrss_copy_to(arr, res);

    // Order 0 removes everything, the real part included; the truncation order is kept
    // (ssoti_truncate_order_to()).
    if (order == 0){

        memset(res->p_data, 0, (size_t)res->size * sizeof(coeff_t));
        res->nbases    = 0;
        res->act_order = 0;
        return;

    }

    if (order > res->trc_order){
        return;
    }

    // Zero the blocks of orders >= order so that orders above act_order hold zeros.
    off     = oarrss_block_index(res->nbases, order, 0);
    nblocks = 1 + sshelp_ndir_total(res->nbases, res->trc_order);

    if (nblocks > off){
        memset(res->p_data + off * res->size, 0,
               (size_t)((nblocks - off) * res->size) * sizeof(coeff_t));
    }

    res->act_order = (res->act_order < order - 1) ? res->act_order : (ord_t)(order - 1);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void oarrss_get_order_im_to(ord_t order, const oarrss_t* arr, oarrss_t* res){

    ord_t p;

    oarrss_copy_to(arr, res);

    if (order != 0){
        memset(res->p_data, 0, (size_t)res->size * sizeof(coeff_t));
    }

    for (p = 1; p <= res->trc_order; p++){

        if (p == order){
            continue;
        }

        {
            ndir_t Np = sshelp_ndir_order(res->nbases, p);
            uint64_t off = oarrss_block_index(res->nbases, p, 0) * res->size;
            uint64_t len = (uint64_t)Np * res->size;

            memset(res->p_data + off, 0, len * sizeof(coeff_t));

        }

    }

    res->act_order = (order <= res->trc_order) ? order : res->trc_order;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Tells whether n reals starting at blk are all zero.
static int oarrss_block_is_zero(const coeff_t* blk, uint64_t n){

    uint64_t e;

    for (e = 0; e < n; e++){

        if (blk[e] != 0.0){
            return 0;
        }

    }

    return 1;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Highest order at or below `start` holding a nonzero block, or 0.
static ord_t oarrss_scan_act_order(const oarrss_t* arr, ord_t start){

    ord_t p;

    for (p = start; p >= 1; p--){

        ndir_t Np = sshelp_ndir_order(arr->nbases, p);
        uint64_t off = oarrss_block_index(arr->nbases, p, 0) * arr->size;
        uint64_t n = (uint64_t)Np * arr->size;

        if (!oarrss_block_is_zero(arr->p_data + off, n)){
            return p;
        }

    }

    return 0;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void oarrss_compact_to(const oarrss_t* arr, oarrss_t* res){

    bases_t k = arr->nbases, nu = 0, u_idx;
    uint8_t* keep;
    bases_t* keep_old_local = NULL;
    bases_t* new_bases = NULL;
    ord_t p;
    size_t need;
    sshelp_ws_t* ws = ssoti_ws();
    coeff_t* scratch;

    if (k == 0){

        oarrss_copy_to(arr, res);
        return;

    }

    keep = (uint8_t*)calloc(k, sizeof(uint8_t));

    if (keep == NULL){
        ssoti_out_of_memory();
    }

    for (u_idx = 0; u_idx < k; u_idx++){

        int used = 0;

        for (p = 1; p <= arr->trc_order && !used; p++){

            ndir_t Np = sshelp_ndir_order(k, p), jj;
            bases_t* dirs = (bases_t*)malloc((size_t)Np * p * sizeof(bases_t) + 1);

            if (dirs == NULL){
                ssoti_out_of_memory();
            }

            sshelp_local_dirs(k, p, dirs);

            for (jj = 0; jj < Np; jj++){

                ord_t d;
                int contains = 0;

                for (d = 0; d < p; d++){

                    if (dirs[(size_t)jj * p + d] == u_idx){

                        contains = 1;
                        break;

                    }

                }

                if (contains){

                    coeff_t* blk = arr->p_data + oarrss_block_index(k, p, jj) * arr->size;

                    if (!oarrss_block_is_zero(blk, arr->size)){

                        used = 1;
                        break;

                    }

                }

            }

            free(dirs);

        }

        if (used){

            keep[u_idx] = 1;
            nu++;

        }

    }

    if (nu == k){

        free(keep);
        oarrss_copy_to(arr, res);
        return;

    }

    keep_old_local = (bases_t*)malloc((size_t)nu * sizeof(bases_t) + 1);
    new_bases      = (bases_t*)malloc((size_t)nu * sizeof(bases_t) + 1);

    if (keep_old_local == NULL || new_bases == NULL){
        ssoti_out_of_memory();
    }

    {
        bases_t w = 0;

        for (u_idx = 0; u_idx < k; u_idx++){

            if (keep[u_idx]){

                keep_old_local[w] = u_idx;
                new_bases[w]      = arr->p_bases[u_idx];
                w++;

            }

        }

    }

    free(keep);

    need = (size_t)(1 + sshelp_ndir_total(nu, arr->trc_order)) * arr->size;
    ssoti_ws_need(ws, need, 0, 0);
    scratch = ws->p_coef;

    memcpy(scratch, arr->p_data, (size_t)arr->size * sizeof(coeff_t));

    for (p = 1; p <= arr->trc_order; p++){

        ndir_t Np_new = sshelp_ndir_order(nu, p);

        if (Np_new == 0){
            continue;
        }

        {
            sshelp_rank_tab_t tab;
            ndir_t* map = (ndir_t*)malloc((size_t)Np_new * sizeof(ndir_t));
            bases_t* u = (bases_t*)malloc((size_t)p * sizeof(bases_t) + 1);
            ndir_t jj;

            if (map == NULL || u == NULL ||
                sshelp_rank_tab_init(&tab, k, arr->trc_order) != SSHELP_OK){
                ssoti_out_of_memory();
            }

            sshelp_remap_order(nu, keep_old_local, p, &tab, map, u);

            for (jj = 0; jj < Np_new; jj++){

                coeff_t* src = arr->p_data + oarrss_block_index(k, p, map[jj]) * arr->size;
                coeff_t* dst = scratch + oarrss_block_index(nu, p, jj) * arr->size;

                memcpy(dst, src, (size_t)arr->size * sizeof(coeff_t));

            }

            sshelp_rank_tab_free(&tab);
            free(map);
            free(u);

        }

    }

    oarrss_reserve(res, nu, arr->nrows, arr->ncols, arr->trc_order);

    if (nu > 0){
        memcpy(res->p_bases, new_bases, (size_t)nu * sizeof(bases_t));
    }

    memcpy(res->p_data, scratch, need * sizeof(coeff_t));

    res->nbases    = nu;
    res->trc_order = arr->trc_order;
    res->nrows     = arr->nrows;
    res->ncols     = arr->ncols;
    res->size      = arr->size;
    res->act_order = oarrss_scan_act_order(res, arr->act_order);

    free(keep_old_local);
    free(new_bases);

}
// -------------------------------------------------------------------------------------------------------
