// Semi-sparse AoS arrays (arrss_t). See include/oti/semisparse/array/array.h.


// *******************************************************************************************************
arrss_t arrss_init(void){

    arrss_t arr;

    arr.p_data = NULL;
    arr.nrows  = 0;
    arr.ncols  = 0;
    arr.size   = 0;
    arr.flag   = 1;

    return arr;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
arrss_t arrss_zeros(uint64_t nrows, uint64_t ncols, ord_t trc_order){

    arrss_t arr = arrss_init();

    arrss_resize(nrows, ncols, trc_order, &arr);

    return arr;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void arrss_resize(uint64_t nrows, uint64_t ncols, ord_t trc_order, arrss_t* arr){

    uint64_t e, size = nrows * ncols;
    ssotinum_t* p_data;

    if (size != arr->size){

        for (e = size; e < arr->size; e++){
            ssoti_free(&arr->p_data[e]);
        }

        p_data = (ssotinum_t*)realloc(arr->p_data, (size_t)size * sizeof(ssotinum_t) + 1);

        if (p_data == NULL){
            ssoti_out_of_memory();
        }

        for (e = arr->size; e < size; e++){
            p_data[e] = ssoti_create_r(0.0, trc_order);
        }

        arr->p_data = p_data;

    }

    arr->nrows = nrows;
    arr->ncols = ncols;
    arr->size  = size;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void arrss_free(arrss_t* arr){

    uint64_t e;

    if (arr->flag != 0){

        for (e = 0; e < arr->size; e++){
            ssoti_free(&arr->p_data[e]);
        }

        free(arr->p_data);

    }

    *arr = arrss_init();

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void arrss_copy_to(const arrss_t* arr1, arrss_t* res){

    uint64_t e;

    if (arr1 == res){
        return;
    }

    arrss_resize(arr1->nrows, arr1->ncols, 0, res);

    for (e = 0; e < arr1->size; e++){
        ssoti_copy_to(&arr1->p_data[e], &res->p_data[e]);
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
arrss_t arrss_copy(const arrss_t* arr1){

    arrss_t res = arrss_init();

    arrss_copy_to(arr1, &res);

    return res;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
const ssotinum_t* arrss_get_item_ptr(uint64_t i, uint64_t j, const arrss_t* arr1){

    return &arr1->p_data[j + i * arr1->ncols];

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void arrss_set_item(const ssotinum_t* num, uint64_t i, uint64_t j, arrss_t* arr1){

    ssoti_copy_to(num, &arr1->p_data[j + i * arr1->ncols]);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void arrss_set_item_r(coeff_t val, uint64_t i, uint64_t j, arrss_t* arr1){

    ssoti_set_r(val, &arr1->p_data[j + i * arr1->ncols]);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
arrss_t arrss_from_arrso(const arrso_t* arr1, dhelpl_t dhl){

    arrss_t res = arrss_zeros(arr1->nrows, arr1->ncols, 0);
    uint64_t e;

    for (e = 0; e < arr1->size; e++){

        ssoti_free(&res.p_data[e]);
        res.p_data[e] = ssoti_from_soti(&arr1->p_data[e], dhl);

    }

    return res;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
arrso_t arrss_to_arrso(const arrss_t* arr1, dhelpl_t dhl){

    arrso_t res = arrso_init();
    uint64_t e;

    res.p_data = (sotinum_t*)malloc((size_t)arr1->size * sizeof(sotinum_t) + 1);

    if (res.p_data == NULL){
        ssoti_out_of_memory();
    }

    for (e = 0; e < arr1->size; e++){
        res.p_data[e] = ssoti_to_soti(&arr1->p_data[e], dhl);
    }

    res.nrows = arr1->nrows;
    res.ncols = arr1->ncols;
    res.size  = arr1->size;
    res.flag  = 1;

    return res;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// qsort comparator for base labels.
static int arrss_cmp_bases(const void* a, const void* b){

    bases_t x = *(const bases_t*)a, y = *(const bases_t*)b;

    return (x > y) - (x < y);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void arrss_to_oarrss(const arrss_t* arr1, oarrss_t* res){

    uint64_t e, n = arr1->nrows, m = arr1->ncols;
    size_t total = 0, t, maxk = 0;
    bases_t *p_u, ku = 0, *pos;
    ord_t trc = 0, act = 0;
    ndir_t nimag, d;
    coeff_t* dst;

    // Union of the sets (sort and unique the concatenated lists); truncation order = the largest.
    for (e = 0; e < arr1->size; e++){

        total += arr1->p_data[e].nbases;
        maxk   = (arr1->p_data[e].nbases > maxk) ? arr1->p_data[e].nbases : maxk;

    }

    p_u = (bases_t*)malloc(total * sizeof(bases_t) + 1);
    pos = (bases_t*)malloc(maxk * sizeof(bases_t) + 1);

    if (p_u == NULL || pos == NULL){
        ssoti_out_of_memory();
    }

    for (e = 0, t = 0; e < arr1->size; e++){

        const ssotinum_t* x = &arr1->p_data[e];

        memcpy(p_u + t, x->p_bases, (size_t)x->nbases * sizeof(bases_t));
        t  += x->nbases;
        trc = (x->trc_order > trc) ? x->trc_order : trc;

    }

    qsort(p_u, total, sizeof(bases_t), arrss_cmp_bases);

    for (t = 0; t < total; t++){

        if (ku == 0 || p_u[ku - 1] != p_u[t]){
            p_u[ku++] = p_u[t];
        }

    }

    nimag = ssoti_nimag_checked(ku, trc);
    oarrss_reserve(res, ku, n, m, trc);
    memset(res->p_data, 0, (size_t)((1 + nimag) * arr1->size) * sizeof(coeff_t));

    if (ku > 0){
        memcpy(res->p_bases, p_u, (size_t)ku * sizeof(bases_t));
    }

    res->nbases    = ku;
    res->trc_order = trc;

    dst = (coeff_t*)malloc((size_t)nimag * sizeof(coeff_t) + 1);

    if (dst == NULL){
        ssoti_out_of_memory();
    }

    // Element (i, j) (row-major here) goes to i + j*n in every block (column-major).
    for (e = 0; e < arr1->size; e++){

        const ssotinum_t* x = &arr1->p_data[e];
        uint64_t i = e / m, j = e % m, s = i + j * n;
        for (d = 0; d < x->nbases; d++){

            // Binary search of the element's base in the union.
            size_t lo = 0, hi = ku, mid;

            while (lo < hi){

                mid = lo + (hi - lo) / 2;

                if (p_u[mid] < x->p_bases[d]){
                    lo = mid + 1;
                } else {
                    hi = mid;
                }

            }

            pos[d] = (bases_t)lo;

        }

        ssoti_kernel_expand(x, pos, ku, trc, dst);

        res->p_data[s] = x->re;

        for (d = 0; d < nimag; d++){
            res->p_data[(1 + d) * arr1->size + s] = dst[d];
        }

        act = (x->act_order > act) ? x->act_order : act;

    }

    res->act_order = (act < trc) ? act : trc;

    free(dst);
    free(p_u);
    free(pos);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void arrss_from_oarrss(const oarrss_t* arr1, arrss_t* res){

    uint64_t i, j;

    arrss_resize(arr1->nrows, arr1->ncols, arr1->trc_order, res);

    for (i = 0; i < arr1->nrows; i++){

        for (j = 0; j < arr1->ncols; j++){
            oarrss_get_item_to(i, j, arr1, &res->p_data[j + i * arr1->ncols]);
        }

    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void arrss_sum_OO_to(const arrss_t* arr1, const arrss_t* arr2, arrss_t* res, dhelpl_t dhl){

    int64_t e;

    if (arr1->nrows != arr2->nrows || arr1->ncols != arr2->ncols){
        printf("ERROR: Semi-sparse array shapes do not match. Exiting...\n");
        exit(OTI_BadIndx);
    }

    arrss_resize(arr1->nrows, arr1->ncols, 0, res);

    #pragma omp parallel for schedule(dynamic, 16) if (arr1->size >= 64)
    for (e = 0; e < (int64_t)arr1->size; e++){
        ssoti_sum_oo_to(&arr1->p_data[e], &arr2->p_data[e], &res->p_data[e], dhl);
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void arrss_sum_oO_to(const ssotinum_t* num, const arrss_t* arr1, arrss_t* res, dhelpl_t dhl){

    int64_t e;

    arrss_resize(arr1->nrows, arr1->ncols, 0, res);

    #pragma omp parallel for schedule(dynamic, 16) if (arr1->size >= 64)
    for (e = 0; e < (int64_t)arr1->size; e++){
        ssoti_sum_oo_to(num, &arr1->p_data[e], &res->p_data[e], dhl);
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void arrss_sum_rO_to(coeff_t val, const arrss_t* arr1, arrss_t* res, dhelpl_t dhl){

    int64_t e;

    arrss_resize(arr1->nrows, arr1->ncols, 0, res);

    #pragma omp parallel for schedule(dynamic, 16) if (arr1->size >= 64)
    for (e = 0; e < (int64_t)arr1->size; e++){
        ssoti_sum_or_to(&arr1->p_data[e], val, &res->p_data[e], dhl);
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void arrss_sub_OO_to(const arrss_t* arr1, const arrss_t* arr2, arrss_t* res, dhelpl_t dhl){

    int64_t e;

    if (arr1->nrows != arr2->nrows || arr1->ncols != arr2->ncols){
        printf("ERROR: Semi-sparse array shapes do not match. Exiting...\n");
        exit(OTI_BadIndx);
    }

    arrss_resize(arr1->nrows, arr1->ncols, 0, res);

    #pragma omp parallel for schedule(dynamic, 16) if (arr1->size >= 64)
    for (e = 0; e < (int64_t)arr1->size; e++){
        ssoti_sub_oo_to(&arr1->p_data[e], &arr2->p_data[e], &res->p_data[e], dhl);
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void arrss_sub_oO_to(const ssotinum_t* num, const arrss_t* arr1, arrss_t* res, dhelpl_t dhl){

    int64_t e;

    arrss_resize(arr1->nrows, arr1->ncols, 0, res);

    #pragma omp parallel for schedule(dynamic, 16) if (arr1->size >= 64)
    for (e = 0; e < (int64_t)arr1->size; e++){
        ssoti_sub_oo_to(num, &arr1->p_data[e], &res->p_data[e], dhl);
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void arrss_sub_rO_to(coeff_t val, const arrss_t* arr1, arrss_t* res, dhelpl_t dhl){

    int64_t e;

    arrss_resize(arr1->nrows, arr1->ncols, 0, res);

    #pragma omp parallel for schedule(dynamic, 16) if (arr1->size >= 64)
    for (e = 0; e < (int64_t)arr1->size; e++){
        ssoti_sub_ro_to(val, &arr1->p_data[e], &res->p_data[e], dhl);
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void arrss_sub_Oo_to(const arrss_t* arr1, const ssotinum_t* num, arrss_t* res, dhelpl_t dhl){

    int64_t e;

    arrss_resize(arr1->nrows, arr1->ncols, 0, res);

    #pragma omp parallel for schedule(dynamic, 16) if (arr1->size >= 64)
    for (e = 0; e < (int64_t)arr1->size; e++){
        ssoti_sub_oo_to(&arr1->p_data[e], num, &res->p_data[e], dhl);
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void arrss_sub_Or_to(const arrss_t* arr1, coeff_t val, arrss_t* res, dhelpl_t dhl){

    int64_t e;

    arrss_resize(arr1->nrows, arr1->ncols, 0, res);

    #pragma omp parallel for schedule(dynamic, 16) if (arr1->size >= 64)
    for (e = 0; e < (int64_t)arr1->size; e++){
        ssoti_sub_or_to(&arr1->p_data[e], val, &res->p_data[e], dhl);
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void arrss_mul_OO_to(const arrss_t* arr1, const arrss_t* arr2, arrss_t* res, dhelpl_t dhl){

    int64_t e;

    if (arr1->nrows != arr2->nrows || arr1->ncols != arr2->ncols){
        printf("ERROR: Semi-sparse array shapes do not match. Exiting...\n");
        exit(OTI_BadIndx);
    }

    arrss_resize(arr1->nrows, arr1->ncols, 0, res);

    #pragma omp parallel for schedule(dynamic, 16) if (arr1->size >= 64)
    for (e = 0; e < (int64_t)arr1->size; e++){
        ssoti_mul_oo_to(&arr1->p_data[e], &arr2->p_data[e], &res->p_data[e], dhl);
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void arrss_mul_oO_to(const ssotinum_t* num, const arrss_t* arr1, arrss_t* res, dhelpl_t dhl){

    int64_t e;

    arrss_resize(arr1->nrows, arr1->ncols, 0, res);

    #pragma omp parallel for schedule(dynamic, 16) if (arr1->size >= 64)
    for (e = 0; e < (int64_t)arr1->size; e++){
        ssoti_mul_oo_to(num, &arr1->p_data[e], &res->p_data[e], dhl);
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void arrss_mul_rO_to(coeff_t val, const arrss_t* arr1, arrss_t* res, dhelpl_t dhl){

    int64_t e;

    arrss_resize(arr1->nrows, arr1->ncols, 0, res);

    #pragma omp parallel for schedule(dynamic, 16) if (arr1->size >= 64)
    for (e = 0; e < (int64_t)arr1->size; e++){
        ssoti_mul_or_to(&arr1->p_data[e], val, &res->p_data[e], dhl);
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void arrss_div_OO_to(const arrss_t* arr1, const arrss_t* arr2, arrss_t* res, dhelpl_t dhl){

    int64_t e;

    if (arr1->nrows != arr2->nrows || arr1->ncols != arr2->ncols){
        printf("ERROR: Semi-sparse array shapes do not match. Exiting...\n");
        exit(OTI_BadIndx);
    }

    arrss_resize(arr1->nrows, arr1->ncols, 0, res);

    #pragma omp parallel for schedule(dynamic, 16) if (arr1->size >= 64)
    for (e = 0; e < (int64_t)arr1->size; e++){
        ssoti_div_oo_to(&arr1->p_data[e], &arr2->p_data[e], &res->p_data[e], dhl);
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void arrss_div_oO_to(const ssotinum_t* num, const arrss_t* arr1, arrss_t* res, dhelpl_t dhl){

    int64_t e;

    arrss_resize(arr1->nrows, arr1->ncols, 0, res);

    #pragma omp parallel for schedule(dynamic, 16) if (arr1->size >= 64)
    for (e = 0; e < (int64_t)arr1->size; e++){
        ssoti_div_oo_to(num, &arr1->p_data[e], &res->p_data[e], dhl);
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void arrss_div_rO_to(coeff_t val, const arrss_t* arr1, arrss_t* res, dhelpl_t dhl){

    int64_t e;

    arrss_resize(arr1->nrows, arr1->ncols, 0, res);

    #pragma omp parallel for schedule(dynamic, 16) if (arr1->size >= 64)
    for (e = 0; e < (int64_t)arr1->size; e++){
        ssoti_div_ro_to(val, &arr1->p_data[e], &res->p_data[e], dhl);
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void arrss_div_Oo_to(const arrss_t* arr1, const ssotinum_t* num, arrss_t* res, dhelpl_t dhl){

    int64_t e;

    arrss_resize(arr1->nrows, arr1->ncols, 0, res);

    #pragma omp parallel for schedule(dynamic, 16) if (arr1->size >= 64)
    for (e = 0; e < (int64_t)arr1->size; e++){
        ssoti_div_oo_to(&arr1->p_data[e], num, &res->p_data[e], dhl);
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void arrss_div_Or_to(const arrss_t* arr1, coeff_t val, arrss_t* res, dhelpl_t dhl){

    int64_t e;

    arrss_resize(arr1->nrows, arr1->ncols, 0, res);

    #pragma omp parallel for schedule(dynamic, 16) if (arr1->size >= 64)
    for (e = 0; e < (int64_t)arr1->size; e++){
        ssoti_div_or_to(&arr1->p_data[e], val, &res->p_data[e], dhl);
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void arrss_neg_to(const arrss_t* arr1, arrss_t* res, dhelpl_t dhl){

    int64_t e;

    arrss_resize(arr1->nrows, arr1->ncols, 0, res);

    #pragma omp parallel for schedule(dynamic, 16) if (arr1->size >= 64)
    for (e = 0; e < (int64_t)arr1->size; e++){
        ssoti_neg_to(&arr1->p_data[e], &res->p_data[e], dhl);
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void arrss_exp_to(const arrss_t* arr1, arrss_t* res, dhelpl_t dhl){

    int64_t e;

    arrss_resize(arr1->nrows, arr1->ncols, 0, res);

    #pragma omp parallel for schedule(dynamic, 16) if (arr1->size >= 64)
    for (e = 0; e < (int64_t)arr1->size; e++){
        ssoti_exp_to(&arr1->p_data[e], &res->p_data[e], dhl);
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void arrss_log_to(const arrss_t* arr1, arrss_t* res, dhelpl_t dhl){

    int64_t e;

    arrss_resize(arr1->nrows, arr1->ncols, 0, res);

    #pragma omp parallel for schedule(dynamic, 16) if (arr1->size >= 64)
    for (e = 0; e < (int64_t)arr1->size; e++){
        ssoti_log_to(&arr1->p_data[e], &res->p_data[e], dhl);
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void arrss_log10_to(const arrss_t* arr1, arrss_t* res, dhelpl_t dhl){

    int64_t e;

    arrss_resize(arr1->nrows, arr1->ncols, 0, res);

    #pragma omp parallel for schedule(dynamic, 16) if (arr1->size >= 64)
    for (e = 0; e < (int64_t)arr1->size; e++){
        ssoti_log10_to(&arr1->p_data[e], &res->p_data[e], dhl);
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void arrss_sqrt_to(const arrss_t* arr1, arrss_t* res, dhelpl_t dhl){

    int64_t e;

    arrss_resize(arr1->nrows, arr1->ncols, 0, res);

    #pragma omp parallel for schedule(dynamic, 16) if (arr1->size >= 64)
    for (e = 0; e < (int64_t)arr1->size; e++){
        ssoti_sqrt_to(&arr1->p_data[e], &res->p_data[e], dhl);
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void arrss_cbrt_to(const arrss_t* arr1, arrss_t* res, dhelpl_t dhl){

    int64_t e;

    arrss_resize(arr1->nrows, arr1->ncols, 0, res);

    #pragma omp parallel for schedule(dynamic, 16) if (arr1->size >= 64)
    for (e = 0; e < (int64_t)arr1->size; e++){
        ssoti_cbrt_to(&arr1->p_data[e], &res->p_data[e], dhl);
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void arrss_sin_to(const arrss_t* arr1, arrss_t* res, dhelpl_t dhl){

    int64_t e;

    arrss_resize(arr1->nrows, arr1->ncols, 0, res);

    #pragma omp parallel for schedule(dynamic, 16) if (arr1->size >= 64)
    for (e = 0; e < (int64_t)arr1->size; e++){
        ssoti_sin_to(&arr1->p_data[e], &res->p_data[e], dhl);
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void arrss_cos_to(const arrss_t* arr1, arrss_t* res, dhelpl_t dhl){

    int64_t e;

    arrss_resize(arr1->nrows, arr1->ncols, 0, res);

    #pragma omp parallel for schedule(dynamic, 16) if (arr1->size >= 64)
    for (e = 0; e < (int64_t)arr1->size; e++){
        ssoti_cos_to(&arr1->p_data[e], &res->p_data[e], dhl);
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void arrss_tan_to(const arrss_t* arr1, arrss_t* res, dhelpl_t dhl){

    int64_t e;

    arrss_resize(arr1->nrows, arr1->ncols, 0, res);

    #pragma omp parallel for schedule(dynamic, 16) if (arr1->size >= 64)
    for (e = 0; e < (int64_t)arr1->size; e++){
        ssoti_tan_to(&arr1->p_data[e], &res->p_data[e], dhl);
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void arrss_asin_to(const arrss_t* arr1, arrss_t* res, dhelpl_t dhl){

    int64_t e;

    arrss_resize(arr1->nrows, arr1->ncols, 0, res);

    #pragma omp parallel for schedule(dynamic, 16) if (arr1->size >= 64)
    for (e = 0; e < (int64_t)arr1->size; e++){
        ssoti_asin_to(&arr1->p_data[e], &res->p_data[e], dhl);
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void arrss_acos_to(const arrss_t* arr1, arrss_t* res, dhelpl_t dhl){

    int64_t e;

    arrss_resize(arr1->nrows, arr1->ncols, 0, res);

    #pragma omp parallel for schedule(dynamic, 16) if (arr1->size >= 64)
    for (e = 0; e < (int64_t)arr1->size; e++){
        ssoti_acos_to(&arr1->p_data[e], &res->p_data[e], dhl);
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void arrss_atan_to(const arrss_t* arr1, arrss_t* res, dhelpl_t dhl){

    int64_t e;

    arrss_resize(arr1->nrows, arr1->ncols, 0, res);

    #pragma omp parallel for schedule(dynamic, 16) if (arr1->size >= 64)
    for (e = 0; e < (int64_t)arr1->size; e++){
        ssoti_atan_to(&arr1->p_data[e], &res->p_data[e], dhl);
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void arrss_sinh_to(const arrss_t* arr1, arrss_t* res, dhelpl_t dhl){

    int64_t e;

    arrss_resize(arr1->nrows, arr1->ncols, 0, res);

    #pragma omp parallel for schedule(dynamic, 16) if (arr1->size >= 64)
    for (e = 0; e < (int64_t)arr1->size; e++){
        ssoti_sinh_to(&arr1->p_data[e], &res->p_data[e], dhl);
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void arrss_cosh_to(const arrss_t* arr1, arrss_t* res, dhelpl_t dhl){

    int64_t e;

    arrss_resize(arr1->nrows, arr1->ncols, 0, res);

    #pragma omp parallel for schedule(dynamic, 16) if (arr1->size >= 64)
    for (e = 0; e < (int64_t)arr1->size; e++){
        ssoti_cosh_to(&arr1->p_data[e], &res->p_data[e], dhl);
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void arrss_tanh_to(const arrss_t* arr1, arrss_t* res, dhelpl_t dhl){

    int64_t e;

    arrss_resize(arr1->nrows, arr1->ncols, 0, res);

    #pragma omp parallel for schedule(dynamic, 16) if (arr1->size >= 64)
    for (e = 0; e < (int64_t)arr1->size; e++){
        ssoti_tanh_to(&arr1->p_data[e], &res->p_data[e], dhl);
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void arrss_asinh_to(const arrss_t* arr1, arrss_t* res, dhelpl_t dhl){

    int64_t e;

    arrss_resize(arr1->nrows, arr1->ncols, 0, res);

    #pragma omp parallel for schedule(dynamic, 16) if (arr1->size >= 64)
    for (e = 0; e < (int64_t)arr1->size; e++){
        ssoti_asinh_to(&arr1->p_data[e], &res->p_data[e], dhl);
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void arrss_acosh_to(const arrss_t* arr1, arrss_t* res, dhelpl_t dhl){

    int64_t e;

    arrss_resize(arr1->nrows, arr1->ncols, 0, res);

    #pragma omp parallel for schedule(dynamic, 16) if (arr1->size >= 64)
    for (e = 0; e < (int64_t)arr1->size; e++){
        ssoti_acosh_to(&arr1->p_data[e], &res->p_data[e], dhl);
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void arrss_atanh_to(const arrss_t* arr1, arrss_t* res, dhelpl_t dhl){

    int64_t e;

    arrss_resize(arr1->nrows, arr1->ncols, 0, res);

    #pragma omp parallel for schedule(dynamic, 16) if (arr1->size >= 64)
    for (e = 0; e < (int64_t)arr1->size; e++){
        ssoti_atanh_to(&arr1->p_data[e], &res->p_data[e], dhl);
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void arrss_erf_to(const arrss_t* arr1, arrss_t* res, dhelpl_t dhl){

    int64_t e;

    arrss_resize(arr1->nrows, arr1->ncols, 0, res);

    #pragma omp parallel for schedule(dynamic, 16) if (arr1->size >= 64)
    for (e = 0; e < (int64_t)arr1->size; e++){
        ssoti_erf_to(&arr1->p_data[e], &res->p_data[e], dhl);
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void arrss_pow_to(const arrss_t* arr1, coeff_t ex, arrss_t* res, dhelpl_t dhl){

    int64_t e;

    arrss_resize(arr1->nrows, arr1->ncols, 0, res);

    #pragma omp parallel for schedule(dynamic, 16) if (arr1->size >= 64)
    for (e = 0; e < (int64_t)arr1->size; e++){
        ssoti_pow_to(&arr1->p_data[e], ex, &res->p_data[e], dhl);
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void arrss_truncate_im_to(imdir_t idx, ord_t order, const arrss_t* arr1, arrss_t* res, dhelpl_t dhl){

    int64_t e;

    arrss_resize(arr1->nrows, arr1->ncols, 0, res);

    #pragma omp parallel for schedule(dynamic, 16) if (arr1->size >= 64)
    for (e = 0; e < (int64_t)arr1->size; e++){
        ssoti_truncate_im_to(idx, order, &arr1->p_data[e], &res->p_data[e]);
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void arrss_truncate_order_to(ord_t order, const arrss_t* arr1, arrss_t* res, dhelpl_t dhl){

    int64_t e;

    arrss_resize(arr1->nrows, arr1->ncols, 0, res);

    #pragma omp parallel for schedule(dynamic, 16) if (arr1->size >= 64)
    for (e = 0; e < (int64_t)arr1->size; e++){
        ssoti_truncate_order_to(order, &arr1->p_data[e], &res->p_data[e]);
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void arrss_get_order_im_to(ord_t order, const arrss_t* arr1, arrss_t* res, dhelpl_t dhl){

    int64_t e;

    arrss_resize(arr1->nrows, arr1->ncols, 0, res);

    #pragma omp parallel for schedule(dynamic, 16) if (arr1->size >= 64)
    for (e = 0; e < (int64_t)arr1->size; e++){
        ssoti_get_order_im_to(order, &arr1->p_data[e], &res->p_data[e]);
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void arrss_compact_to(const arrss_t* arr1, arrss_t* res, dhelpl_t dhl){

    int64_t e;

    arrss_resize(arr1->nrows, arr1->ncols, 0, res);

    #pragma omp parallel for schedule(dynamic, 16) if (arr1->size >= 64)
    for (e = 0; e < (int64_t)arr1->size; e++){
        ssoti_compact_to(&arr1->p_data[e], &res->p_data[e]);
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void arrss_matmul_OO_to(const arrss_t* arr1, const arrss_t* arr2, arrss_t* res, dhelpl_t dhl){

    uint64_t n = arr1->nrows, m = arr1->ncols, p = arr2->ncols;
    int64_t e;
    arrss_t tmp;

    if (arr2->nrows != m){
        printf("ERROR: Semi-sparse matmul shapes do not match. Exiting...\n");
        exit(OTI_BadIndx);
    }

    // Accumulate each output element, merging sets as needed; one product scratch per thread.
    tmp = arrss_zeros(n, p, 0);

    #pragma omp parallel if (n * p >= 16)
    {

        ssotinum_t prod = ssoti_init();

        #pragma omp for schedule(dynamic, 4)
        for (e = 0; e < (int64_t)(n * p); e++){

            uint64_t i = (uint64_t)e / p, j = (uint64_t)e % p, l;
            ssotinum_t* acc = &tmp.p_data[e];

            if (m > 0){
                ssoti_mul_oo_to(&arr1->p_data[i * m], &arr2->p_data[j], acc, dhl);
            }

            for (l = 1; l < m; l++){

                ssoti_mul_oo_to(&arr1->p_data[l + i * m], &arr2->p_data[j + l * p], &prod, dhl);
                ssoti_sum_oo_to(acc, &prod, acc, dhl);

            }

        }

        ssoti_free(&prod);

    }

    arrss_free(res);
    *res = tmp;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void arrss_transpose_to(const arrss_t* arr1, arrss_t* res){

    uint64_t i, j;
    arrss_t tmp = arrss_zeros(arr1->ncols, arr1->nrows, 0);

    for (i = 0; i < arr1->nrows; i++){

        for (j = 0; j < arr1->ncols; j++){
            ssoti_copy_to(&arr1->p_data[j + i * arr1->ncols], &tmp.p_data[i + j * arr1->nrows]);
        }

    }

    if (res != arr1){
        arrss_free(res);
    } else {
        arrss_free((arrss_t*)arr1);
    }

    *res = tmp;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int arrss_solve_to(const arrss_t* K, const arrss_t* b, arrss_t* x, dhelpl_t dhl){

    oarrss_t sK = oarrss_init(), sb = oarrss_init(), sx = oarrss_init();
    int status;

    arrss_to_oarrss(K, &sK);
    arrss_to_oarrss(b, &sb);

    status = oarrss_solve_to(&sK, &sb, &sx, dhl);

    if (status == 0){
        arrss_from_oarrss(&sx, x);
    }

    oarrss_free(&sK);
    oarrss_free(&sb);
    oarrss_free(&sx);

    return status;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int arrss_inv_to(const arrss_t* A, arrss_t* res, dhelpl_t dhl){

    oarrss_t sA = oarrss_init(), sr = oarrss_init();
    int status;

    arrss_to_oarrss(A, &sA);

    status = oarrss_inv_to(&sA, &sr, dhl);

    if (status == 0){
        arrss_from_oarrss(&sr, res);
    }

    oarrss_free(&sA);
    oarrss_free(&sr);

    return status;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int arrss_det_to(const arrss_t* A, ssotinum_t* res, dhelpl_t dhl){

    oarrss_t sA = oarrss_init();
    int status;

    arrss_to_oarrss(A, &sA);

    status = oarrss_det_to(&sA, res, dhl);

    oarrss_free(&sA);

    return status;

}
// -------------------------------------------------------------------------------------------------------

