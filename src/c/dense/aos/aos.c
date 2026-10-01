// Dense AoS arrays (arro_t): memory, items, conversions, elementwise algebra, matmul, and linear
// algebra through the SoA layout (include/oti/dense/aos/aos.h).
//
// Owner: WP4 (dense-port). Unity-included from src/c/dense.c, so every static helper here carries
// the prefix dnaa_ (all dense sources share one translation unit). Elements are independent
// otinum_t: elementwise operations run the scalar `_to` kernels over them with OpenMP (each thread
// has its own oti_ws() workspace), and the first error status of any element is returned.


// *******************************************************************************************************
// Records the first non-OK status of an element (called from inside OpenMP loops).
static void dnaa_record(int st, int* p_status){

    if (st != DN_OK){

        #pragma omp critical(dnaa_status)
        {
            if (*p_status == DN_OK){
                *p_status = st;
            }
        }

    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// True when num points at an element of arr.
static int dnaa_inside(const otinum_t* num, const arro_t* arr){

    uintptr_t n = (uintptr_t)num, lo = (uintptr_t)arr->p_data;

    return arr->p_data != NULL && arr->size > 0 && n >= lo && n < lo + arr->size * sizeof(otinum_t);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// The scalar operand of a scalar-array operation. When it is an element of the array or of the result,
// the operation could overwrite it or free it (the result is resized first): a copy in *p_local is
// used instead. Returns NULL when that copy fails. The caller releases *p_local with oti_free().
static const otinum_t* dnaa_stable(const otinum_t* num, const arro_t* arr1, const arro_t* res,
                                   otinum_t* p_local){

    if (!dnaa_inside(num, arr1) && !dnaa_inside(num, res)){
        return num;
    }

    return (oti_copy_to(num, p_local) == DN_OK) ? p_local : NULL;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
arro_t arro_init(void){

    arro_t arr;

    arr.p_data = NULL;
    arr.nrows  = 0;
    arr.ncols  = 0;
    arr.size   = 0;

    return arr;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void arro_free(arro_t* arr){

    uint64_t e;

    if (arr == NULL){
        return;
    }

    if (arr->p_data != NULL){

        for (e = 0; e < arr->size; e++){
            oti_free(&arr->p_data[e]);
        }

    }

    free(arr->p_data);

    *arr = arro_init();

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int arro_resize(uint64_t nrows, uint64_t ncols, ord_t trc_order, arro_t* arr){

    uint64_t e, size = nrows * ncols, old = arr->size;
    otinum_t* p_data;

    if (nrows != 0 && size / nrows != ncols){
        return DN_ERR_MEMORY;
    }

    if (size != old){

        if (size > old && trc_order > _MAXORDER_OTI){
            return DN_ERR_INDEX;
        }

        if (size >= SIZE_MAX / sizeof(otinum_t)){
            return DN_ERR_MEMORY;
        }

        // Shrinking: the elements past the new size go first; a failed realloc keeps the (smaller) array.
        for (e = size; e < old; e++){
            oti_free(&arr->p_data[e]);
        }

        if (size < old){
            arr->size = size;
        }

        p_data = (otinum_t*)realloc(arr->p_data, (size_t)size * sizeof(otinum_t) + 1);

        if (p_data == NULL){

            if (size < old){
                arr->nrows = size;          // consistent (size x 1) shape after a failed shrink.
                arr->ncols = 1;
                return DN_ERR_MEMORY;
            }

            return DN_ERR_MEMORY;

        }

        for (e = old; e < size; e++){
            p_data[e] = oti_create_r(0.0, trc_order);
        }

        arr->p_data = p_data;

    }

    arr->nrows = nrows;
    arr->ncols = ncols;
    arr->size  = size;

    return DN_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int arro_zeros_to(uint64_t nrows, uint64_t ncols, ord_t trc_order, arro_t* res){

    uint64_t e;
    int status = arro_resize(nrows, ncols, trc_order, res);

    if (status != DN_OK){
        return status;
    }

    for (e = 0; e < res->size; e++){

        status = oti_create_empty_to(0, trc_order, &res->p_data[e]);

        if (status != DN_OK){
            return status;
        }

    } // end for

    return DN_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int arro_copy_to(const arro_t* arr1, arro_t* res){

    uint64_t e;
    int status;

    if (arr1 == res){
        return DN_OK;
    }

    status = arro_resize(arr1->nrows, arr1->ncols, 0, res);

    if (status != DN_OK){
        return status;
    }

    for (e = 0; e < arr1->size; e++){

        status = oti_copy_to(&arr1->p_data[e], &res->p_data[e]);

        if (status != DN_OK){
            return status;
        }

    } // end for

    return DN_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
const otinum_t* arro_get_item_ptr(uint64_t i, uint64_t j, const arro_t* arr1){

    if (i >= arr1->nrows || j >= arr1->ncols){
        return NULL;
    }

    return &arr1->p_data[j + i * arr1->ncols];

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int arro_set_item(const otinum_t* num, uint64_t i, uint64_t j, arro_t* arr1){

    if (i >= arr1->nrows || j >= arr1->ncols){
        return DN_ERR_INDEX;
    }

    return oti_copy_to(num, &arr1->p_data[j + i * arr1->ncols]);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int arro_set_item_r(coeff_t val, uint64_t i, uint64_t j, arro_t* arr1){

    if (i >= arr1->nrows || j >= arr1->ncols){
        return DN_ERR_INDEX;
    }

    oti_set_r(val, &arr1->p_data[j + i * arr1->ncols]);

    return DN_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int arro_from_arrso_to(const arrso_t* arr1, arro_t* res, dhelpl_t dhl){

    uint64_t e;
    int status = arro_resize(arr1->nrows, arr1->ncols, 0, res);

    if (status != DN_OK){
        return status;
    }

    for (e = 0; e < arr1->size; e++){

        status = oti_from_soti_to(&arr1->p_data[e], &res->p_data[e], dhl);

        if (status != DN_OK){
            return status;
        }

    } // end for

    return DN_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
arrso_t arro_to_arrso(const arro_t* arr1, dhelpl_t dhl){

    arrso_t res = arrso_init();
    uint64_t e;

    if (arr1->size >= SIZE_MAX / sizeof(sotinum_t)){
        return res;
    }

    res.p_data = (sotinum_t*)malloc((size_t)arr1->size * sizeof(sotinum_t) + 1);

    if (res.p_data == NULL){
        return res;
    }

    for (e = 0; e < arr1->size; e++){
        res.p_data[e] = oti_to_soti(&arr1->p_data[e], dhl);
    }

    res.nrows = arr1->nrows;
    res.ncols = arr1->ncols;
    res.size  = arr1->size;
    res.flag  = 1;

    return res;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int arro_to_oarr(const arro_t* arr1, oarr_t* res){

    uint64_t e, i, j, s, size = arr1->size, bp[_MAXORDER_OTI + 1];
    bases_t k = 0;
    ord_t trc = 0, act = 0, p, top;
    ndir_t np, idx, src;
    int status;

    for (e = 0; e < size; e++){

        k   = (arr1->p_data[e].nact > k) ? arr1->p_data[e].nact : k;
        trc = (arr1->p_data[e].trc_order > trc) ? arr1->p_data[e].trc_order : trc;
        act = (arr1->p_data[e].act_order > act) ? arr1->p_data[e].act_order : act;

    }

    // The capacity rule and the zero fill of exactly the new layout (never the old layout of res).
    status = oarr_zeros_to(k, arr1->nrows, arr1->ncols, trc, res);

    if (status != DN_OK){
        return status;
    }

    res->act_order = (act < trc) ? act : trc;

    for (p = 1; p <= trc; p++){
        bp[p] = 1 + sshelp_order_offset(k, p);
    }

    // Element (i, j), row-major here, goes to i + j*nrows of every column-major block. A smaller
    // nact or lower trc is a prefix of the layout: the order-p coefficients keep their index.
    for (e = 0; e < size; e++){

        const otinum_t* x = &arr1->p_data[e];

        i = e / arr1->ncols;
        j = e % arr1->ncols;
        s = i + j * arr1->nrows;

        res->p_data[s] = x->re;
        top            = (x->trc_order < trc) ? x->trc_order : trc;

        for (p = 1; p <= top; p++){

            np  = sshelp_ndir_order(x->nact, p);
            src = sshelp_order_offset(x->nact, p);

            for (idx = 0; idx < np; idx++){
                res->p_data[(bp[p] + idx) * size + s] = x->p_im[src + idx];
            }

        } // end for

    } // end for

    return DN_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int arro_from_oarr(const oarr_t* arr1, arro_t* res){

    uint64_t e, i, j, s, size = arr1->size, bp[_MAXORDER_OTI + 1];
    ord_t p, trc = arr1->trc_order;
    ndir_t np, idx, off;
    int status;

    status = arro_resize(arr1->nrows, arr1->ncols, trc, res);

    if (status != DN_OK){
        return status;
    }

    for (p = 1; p <= trc; p++){
        bp[p] = 1 + sshelp_order_offset(arr1->nact, p);
    }

    for (e = 0; e < size; e++){

        otinum_t* x = &res->p_data[e];

        i = e / arr1->ncols;
        j = e % arr1->ncols;
        s = i + j * arr1->nrows;

        status = oti_create_empty_to(arr1->nact, trc, x);

        if (status != DN_OK){
            return status;
        }

        x->re        = arr1->p_data[s];
        x->act_order = (arr1->act_order < trc) ? arr1->act_order : trc;

        for (p = 1; p <= trc; p++){

            np  = sshelp_ndir_order(arr1->nact, p);
            off = sshelp_order_offset(arr1->nact, p);

            for (idx = 0; idx < np; idx++){
                x->p_im[off + idx] = arr1->p_data[(bp[p] + idx) * size + s];
            }

        } // end for

    } // end for

    return DN_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int arro_sum_OO_to(const arro_t* arr1, const arro_t* arr2, arro_t* res, dhelpl_t dhl){

    int64_t e;
    int status;

    if (arr1->nrows != arr2->nrows || arr1->ncols != arr2->ncols){
        return DN_ERR_SIZE;
    }

    status = arro_resize(arr1->nrows, arr1->ncols, 0, res);

    if (status != DN_OK){
        return status;
    }

    #pragma omp parallel for schedule(dynamic, 16) if (arr1->size >= 64)
    for (e = 0; e < (int64_t)arr1->size; e++){
        dnaa_record(oti_sum_oo_to(&arr1->p_data[e], &arr2->p_data[e], &res->p_data[e], dhl), &status);
    } // end for

    return status;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int arro_sub_OO_to(const arro_t* arr1, const arro_t* arr2, arro_t* res, dhelpl_t dhl){

    int64_t e;
    int status;

    if (arr1->nrows != arr2->nrows || arr1->ncols != arr2->ncols){
        return DN_ERR_SIZE;
    }

    status = arro_resize(arr1->nrows, arr1->ncols, 0, res);

    if (status != DN_OK){
        return status;
    }

    #pragma omp parallel for schedule(dynamic, 16) if (arr1->size >= 64)
    for (e = 0; e < (int64_t)arr1->size; e++){
        dnaa_record(oti_sub_oo_to(&arr1->p_data[e], &arr2->p_data[e], &res->p_data[e], dhl), &status);
    } // end for

    return status;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int arro_mul_OO_to(const arro_t* arr1, const arro_t* arr2, arro_t* res, dhelpl_t dhl){

    int64_t e;
    int status;

    if (arr1->nrows != arr2->nrows || arr1->ncols != arr2->ncols){
        return DN_ERR_SIZE;
    }

    status = arro_resize(arr1->nrows, arr1->ncols, 0, res);

    if (status != DN_OK){
        return status;
    }

    #pragma omp parallel for schedule(dynamic, 16) if (arr1->size >= 64)
    for (e = 0; e < (int64_t)arr1->size; e++){
        dnaa_record(oti_mul_oo_to(&arr1->p_data[e], &arr2->p_data[e], &res->p_data[e], dhl), &status);
    } // end for

    return status;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int arro_div_OO_to(const arro_t* arr1, const arro_t* arr2, arro_t* res, dhelpl_t dhl){

    int64_t e;
    int status;

    if (arr1->nrows != arr2->nrows || arr1->ncols != arr2->ncols){
        return DN_ERR_SIZE;
    }

    status = arro_resize(arr1->nrows, arr1->ncols, 0, res);

    if (status != DN_OK){
        return status;
    }

    #pragma omp parallel for schedule(dynamic, 16) if (arr1->size >= 64)
    for (e = 0; e < (int64_t)arr1->size; e++){
        dnaa_record(oti_div_oo_to(&arr1->p_data[e], &arr2->p_data[e], &res->p_data[e], dhl), &status);
    } // end for

    return status;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int arro_sum_oO_to(const otinum_t* num, const arro_t* arr1, arro_t* res, dhelpl_t dhl){

    int64_t e;
    otinum_t local = oti_init();
    const otinum_t* p_num = dnaa_stable(num, arr1, res, &local);
    int status = (p_num == NULL) ? DN_ERR_MEMORY : arro_resize(arr1->nrows, arr1->ncols, 0, res);

    if (status != DN_OK){

        oti_free(&local);
        return status;

    }

    #pragma omp parallel for schedule(dynamic, 16) if (arr1->size >= 64)
    for (e = 0; e < (int64_t)arr1->size; e++){
        dnaa_record(oti_sum_oo_to(p_num, &arr1->p_data[e], &res->p_data[e], dhl), &status);
    } // end for

    oti_free(&local);

    return status;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int arro_sum_rO_to(coeff_t val, const arro_t* arr1, arro_t* res, dhelpl_t dhl){

    int64_t e;
    int status = arro_resize(arr1->nrows, arr1->ncols, 0, res);

    if (status != DN_OK){
        return status;
    }

    #pragma omp parallel for schedule(dynamic, 16) if (arr1->size >= 64)
    for (e = 0; e < (int64_t)arr1->size; e++){
        dnaa_record(oti_sum_or_to(&arr1->p_data[e], val, &res->p_data[e], dhl), &status);
    } // end for

    return status;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int arro_sub_oO_to(const otinum_t* num, const arro_t* arr1, arro_t* res, dhelpl_t dhl){

    int64_t e;
    otinum_t local = oti_init();
    const otinum_t* p_num = dnaa_stable(num, arr1, res, &local);
    int status = (p_num == NULL) ? DN_ERR_MEMORY : arro_resize(arr1->nrows, arr1->ncols, 0, res);

    if (status != DN_OK){

        oti_free(&local);
        return status;

    }

    #pragma omp parallel for schedule(dynamic, 16) if (arr1->size >= 64)
    for (e = 0; e < (int64_t)arr1->size; e++){
        dnaa_record(oti_sub_oo_to(p_num, &arr1->p_data[e], &res->p_data[e], dhl), &status);
    } // end for

    oti_free(&local);

    return status;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int arro_sub_rO_to(coeff_t val, const arro_t* arr1, arro_t* res, dhelpl_t dhl){

    int64_t e;
    int status = arro_resize(arr1->nrows, arr1->ncols, 0, res);

    if (status != DN_OK){
        return status;
    }

    #pragma omp parallel for schedule(dynamic, 16) if (arr1->size >= 64)
    for (e = 0; e < (int64_t)arr1->size; e++){
        dnaa_record(oti_sub_ro_to(val, &arr1->p_data[e], &res->p_data[e], dhl), &status);
    } // end for

    return status;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int arro_sub_Oo_to(const arro_t* arr1, const otinum_t* num, arro_t* res, dhelpl_t dhl){

    int64_t e;
    otinum_t local = oti_init();
    const otinum_t* p_num = dnaa_stable(num, arr1, res, &local);
    int status = (p_num == NULL) ? DN_ERR_MEMORY : arro_resize(arr1->nrows, arr1->ncols, 0, res);

    if (status != DN_OK){

        oti_free(&local);
        return status;

    }

    #pragma omp parallel for schedule(dynamic, 16) if (arr1->size >= 64)
    for (e = 0; e < (int64_t)arr1->size; e++){
        dnaa_record(oti_sub_oo_to(&arr1->p_data[e], p_num, &res->p_data[e], dhl), &status);
    } // end for

    oti_free(&local);

    return status;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int arro_sub_Or_to(const arro_t* arr1, coeff_t val, arro_t* res, dhelpl_t dhl){

    int64_t e;
    int status = arro_resize(arr1->nrows, arr1->ncols, 0, res);

    if (status != DN_OK){
        return status;
    }

    #pragma omp parallel for schedule(dynamic, 16) if (arr1->size >= 64)
    for (e = 0; e < (int64_t)arr1->size; e++){
        dnaa_record(oti_sub_or_to(&arr1->p_data[e], val, &res->p_data[e], dhl), &status);
    } // end for

    return status;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int arro_mul_oO_to(const otinum_t* num, const arro_t* arr1, arro_t* res, dhelpl_t dhl){

    int64_t e;
    otinum_t local = oti_init();
    const otinum_t* p_num = dnaa_stable(num, arr1, res, &local);
    int status = (p_num == NULL) ? DN_ERR_MEMORY : arro_resize(arr1->nrows, arr1->ncols, 0, res);

    if (status != DN_OK){

        oti_free(&local);
        return status;

    }

    #pragma omp parallel for schedule(dynamic, 16) if (arr1->size >= 64)
    for (e = 0; e < (int64_t)arr1->size; e++){
        dnaa_record(oti_mul_oo_to(p_num, &arr1->p_data[e], &res->p_data[e], dhl), &status);
    } // end for

    oti_free(&local);

    return status;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int arro_mul_rO_to(coeff_t val, const arro_t* arr1, arro_t* res, dhelpl_t dhl){

    int64_t e;
    int status = arro_resize(arr1->nrows, arr1->ncols, 0, res);

    if (status != DN_OK){
        return status;
    }

    #pragma omp parallel for schedule(dynamic, 16) if (arr1->size >= 64)
    for (e = 0; e < (int64_t)arr1->size; e++){
        dnaa_record(oti_mul_or_to(&arr1->p_data[e], val, &res->p_data[e], dhl), &status);
    } // end for

    return status;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int arro_div_oO_to(const otinum_t* num, const arro_t* arr1, arro_t* res, dhelpl_t dhl){

    int64_t e;
    otinum_t local = oti_init();
    const otinum_t* p_num = dnaa_stable(num, arr1, res, &local);
    int status = (p_num == NULL) ? DN_ERR_MEMORY : arro_resize(arr1->nrows, arr1->ncols, 0, res);

    if (status != DN_OK){

        oti_free(&local);
        return status;

    }

    #pragma omp parallel for schedule(dynamic, 16) if (arr1->size >= 64)
    for (e = 0; e < (int64_t)arr1->size; e++){
        dnaa_record(oti_div_oo_to(p_num, &arr1->p_data[e], &res->p_data[e], dhl), &status);
    } // end for

    oti_free(&local);

    return status;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int arro_div_rO_to(coeff_t val, const arro_t* arr1, arro_t* res, dhelpl_t dhl){

    int64_t e;
    int status = arro_resize(arr1->nrows, arr1->ncols, 0, res);

    if (status != DN_OK){
        return status;
    }

    #pragma omp parallel for schedule(dynamic, 16) if (arr1->size >= 64)
    for (e = 0; e < (int64_t)arr1->size; e++){
        dnaa_record(oti_div_ro_to(val, &arr1->p_data[e], &res->p_data[e], dhl), &status);
    } // end for

    return status;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int arro_div_Oo_to(const arro_t* arr1, const otinum_t* num, arro_t* res, dhelpl_t dhl){

    int64_t e;
    otinum_t local = oti_init();
    const otinum_t* p_num = dnaa_stable(num, arr1, res, &local);
    int status = (p_num == NULL) ? DN_ERR_MEMORY : arro_resize(arr1->nrows, arr1->ncols, 0, res);

    if (status != DN_OK){

        oti_free(&local);
        return status;

    }

    #pragma omp parallel for schedule(dynamic, 16) if (arr1->size >= 64)
    for (e = 0; e < (int64_t)arr1->size; e++){
        dnaa_record(oti_div_oo_to(&arr1->p_data[e], p_num, &res->p_data[e], dhl), &status);
    } // end for

    oti_free(&local);

    return status;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int arro_div_Or_to(const arro_t* arr1, coeff_t val, arro_t* res, dhelpl_t dhl){

    int64_t e;
    int status = arro_resize(arr1->nrows, arr1->ncols, 0, res);

    if (status != DN_OK){
        return status;
    }

    #pragma omp parallel for schedule(dynamic, 16) if (arr1->size >= 64)
    for (e = 0; e < (int64_t)arr1->size; e++){
        dnaa_record(oti_div_or_to(&arr1->p_data[e], val, &res->p_data[e], dhl), &status);
    } // end for

    return status;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int arro_neg_to(const arro_t* arr1, arro_t* res, dhelpl_t dhl){

    int64_t e;
    int status = arro_resize(arr1->nrows, arr1->ncols, 0, res);

    if (status != DN_OK){
        return status;
    }

    #pragma omp parallel for schedule(dynamic, 16) if (arr1->size >= 64)
    for (e = 0; e < (int64_t)arr1->size; e++){
        dnaa_record(oti_neg_to(&arr1->p_data[e], &res->p_data[e], dhl), &status);
    } // end for

    return status;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int arro_exp_to(const arro_t* arr1, arro_t* res, dhelpl_t dhl){

    int64_t e;
    int status = arro_resize(arr1->nrows, arr1->ncols, 0, res);

    if (status != DN_OK){
        return status;
    }

    #pragma omp parallel for schedule(dynamic, 16) if (arr1->size >= 64)
    for (e = 0; e < (int64_t)arr1->size; e++){
        dnaa_record(oti_exp_to(&arr1->p_data[e], &res->p_data[e], dhl), &status);
    } // end for

    return status;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int arro_log_to(const arro_t* arr1, arro_t* res, dhelpl_t dhl){

    int64_t e;
    int status = arro_resize(arr1->nrows, arr1->ncols, 0, res);

    if (status != DN_OK){
        return status;
    }

    #pragma omp parallel for schedule(dynamic, 16) if (arr1->size >= 64)
    for (e = 0; e < (int64_t)arr1->size; e++){
        dnaa_record(oti_log_to(&arr1->p_data[e], &res->p_data[e], dhl), &status);
    } // end for

    return status;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int arro_log10_to(const arro_t* arr1, arro_t* res, dhelpl_t dhl){

    int64_t e;
    int status = arro_resize(arr1->nrows, arr1->ncols, 0, res);

    if (status != DN_OK){
        return status;
    }

    #pragma omp parallel for schedule(dynamic, 16) if (arr1->size >= 64)
    for (e = 0; e < (int64_t)arr1->size; e++){
        dnaa_record(oti_log10_to(&arr1->p_data[e], &res->p_data[e], dhl), &status);
    } // end for

    return status;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int arro_sqrt_to(const arro_t* arr1, arro_t* res, dhelpl_t dhl){

    int64_t e;
    int status = arro_resize(arr1->nrows, arr1->ncols, 0, res);

    if (status != DN_OK){
        return status;
    }

    #pragma omp parallel for schedule(dynamic, 16) if (arr1->size >= 64)
    for (e = 0; e < (int64_t)arr1->size; e++){
        dnaa_record(oti_sqrt_to(&arr1->p_data[e], &res->p_data[e], dhl), &status);
    } // end for

    return status;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int arro_cbrt_to(const arro_t* arr1, arro_t* res, dhelpl_t dhl){

    int64_t e;
    int status = arro_resize(arr1->nrows, arr1->ncols, 0, res);

    if (status != DN_OK){
        return status;
    }

    #pragma omp parallel for schedule(dynamic, 16) if (arr1->size >= 64)
    for (e = 0; e < (int64_t)arr1->size; e++){
        dnaa_record(oti_cbrt_to(&arr1->p_data[e], &res->p_data[e], dhl), &status);
    } // end for

    return status;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int arro_sin_to(const arro_t* arr1, arro_t* res, dhelpl_t dhl){

    int64_t e;
    int status = arro_resize(arr1->nrows, arr1->ncols, 0, res);

    if (status != DN_OK){
        return status;
    }

    #pragma omp parallel for schedule(dynamic, 16) if (arr1->size >= 64)
    for (e = 0; e < (int64_t)arr1->size; e++){
        dnaa_record(oti_sin_to(&arr1->p_data[e], &res->p_data[e], dhl), &status);
    } // end for

    return status;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int arro_cos_to(const arro_t* arr1, arro_t* res, dhelpl_t dhl){

    int64_t e;
    int status = arro_resize(arr1->nrows, arr1->ncols, 0, res);

    if (status != DN_OK){
        return status;
    }

    #pragma omp parallel for schedule(dynamic, 16) if (arr1->size >= 64)
    for (e = 0; e < (int64_t)arr1->size; e++){
        dnaa_record(oti_cos_to(&arr1->p_data[e], &res->p_data[e], dhl), &status);
    } // end for

    return status;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int arro_tan_to(const arro_t* arr1, arro_t* res, dhelpl_t dhl){

    int64_t e;
    int status = arro_resize(arr1->nrows, arr1->ncols, 0, res);

    if (status != DN_OK){
        return status;
    }

    #pragma omp parallel for schedule(dynamic, 16) if (arr1->size >= 64)
    for (e = 0; e < (int64_t)arr1->size; e++){
        dnaa_record(oti_tan_to(&arr1->p_data[e], &res->p_data[e], dhl), &status);
    } // end for

    return status;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int arro_asin_to(const arro_t* arr1, arro_t* res, dhelpl_t dhl){

    int64_t e;
    int status = arro_resize(arr1->nrows, arr1->ncols, 0, res);

    if (status != DN_OK){
        return status;
    }

    #pragma omp parallel for schedule(dynamic, 16) if (arr1->size >= 64)
    for (e = 0; e < (int64_t)arr1->size; e++){
        dnaa_record(oti_asin_to(&arr1->p_data[e], &res->p_data[e], dhl), &status);
    } // end for

    return status;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int arro_acos_to(const arro_t* arr1, arro_t* res, dhelpl_t dhl){

    int64_t e;
    int status = arro_resize(arr1->nrows, arr1->ncols, 0, res);

    if (status != DN_OK){
        return status;
    }

    #pragma omp parallel for schedule(dynamic, 16) if (arr1->size >= 64)
    for (e = 0; e < (int64_t)arr1->size; e++){
        dnaa_record(oti_acos_to(&arr1->p_data[e], &res->p_data[e], dhl), &status);
    } // end for

    return status;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int arro_atan_to(const arro_t* arr1, arro_t* res, dhelpl_t dhl){

    int64_t e;
    int status = arro_resize(arr1->nrows, arr1->ncols, 0, res);

    if (status != DN_OK){
        return status;
    }

    #pragma omp parallel for schedule(dynamic, 16) if (arr1->size >= 64)
    for (e = 0; e < (int64_t)arr1->size; e++){
        dnaa_record(oti_atan_to(&arr1->p_data[e], &res->p_data[e], dhl), &status);
    } // end for

    return status;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int arro_sinh_to(const arro_t* arr1, arro_t* res, dhelpl_t dhl){

    int64_t e;
    int status = arro_resize(arr1->nrows, arr1->ncols, 0, res);

    if (status != DN_OK){
        return status;
    }

    #pragma omp parallel for schedule(dynamic, 16) if (arr1->size >= 64)
    for (e = 0; e < (int64_t)arr1->size; e++){
        dnaa_record(oti_sinh_to(&arr1->p_data[e], &res->p_data[e], dhl), &status);
    } // end for

    return status;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int arro_cosh_to(const arro_t* arr1, arro_t* res, dhelpl_t dhl){

    int64_t e;
    int status = arro_resize(arr1->nrows, arr1->ncols, 0, res);

    if (status != DN_OK){
        return status;
    }

    #pragma omp parallel for schedule(dynamic, 16) if (arr1->size >= 64)
    for (e = 0; e < (int64_t)arr1->size; e++){
        dnaa_record(oti_cosh_to(&arr1->p_data[e], &res->p_data[e], dhl), &status);
    } // end for

    return status;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int arro_tanh_to(const arro_t* arr1, arro_t* res, dhelpl_t dhl){

    int64_t e;
    int status = arro_resize(arr1->nrows, arr1->ncols, 0, res);

    if (status != DN_OK){
        return status;
    }

    #pragma omp parallel for schedule(dynamic, 16) if (arr1->size >= 64)
    for (e = 0; e < (int64_t)arr1->size; e++){
        dnaa_record(oti_tanh_to(&arr1->p_data[e], &res->p_data[e], dhl), &status);
    } // end for

    return status;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int arro_asinh_to(const arro_t* arr1, arro_t* res, dhelpl_t dhl){

    int64_t e;
    int status = arro_resize(arr1->nrows, arr1->ncols, 0, res);

    if (status != DN_OK){
        return status;
    }

    #pragma omp parallel for schedule(dynamic, 16) if (arr1->size >= 64)
    for (e = 0; e < (int64_t)arr1->size; e++){
        dnaa_record(oti_asinh_to(&arr1->p_data[e], &res->p_data[e], dhl), &status);
    } // end for

    return status;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int arro_acosh_to(const arro_t* arr1, arro_t* res, dhelpl_t dhl){

    int64_t e;
    int status = arro_resize(arr1->nrows, arr1->ncols, 0, res);

    if (status != DN_OK){
        return status;
    }

    #pragma omp parallel for schedule(dynamic, 16) if (arr1->size >= 64)
    for (e = 0; e < (int64_t)arr1->size; e++){
        dnaa_record(oti_acosh_to(&arr1->p_data[e], &res->p_data[e], dhl), &status);
    } // end for

    return status;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int arro_atanh_to(const arro_t* arr1, arro_t* res, dhelpl_t dhl){

    int64_t e;
    int status = arro_resize(arr1->nrows, arr1->ncols, 0, res);

    if (status != DN_OK){
        return status;
    }

    #pragma omp parallel for schedule(dynamic, 16) if (arr1->size >= 64)
    for (e = 0; e < (int64_t)arr1->size; e++){
        dnaa_record(oti_atanh_to(&arr1->p_data[e], &res->p_data[e], dhl), &status);
    } // end for

    return status;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int arro_erf_to(const arro_t* arr1, arro_t* res, dhelpl_t dhl){

    int64_t e;
    int status = arro_resize(arr1->nrows, arr1->ncols, 0, res);

    if (status != DN_OK){
        return status;
    }

    #pragma omp parallel for schedule(dynamic, 16) if (arr1->size >= 64)
    for (e = 0; e < (int64_t)arr1->size; e++){
        dnaa_record(oti_erf_to(&arr1->p_data[e], &res->p_data[e], dhl), &status);
    } // end for

    return status;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int arro_pow_to(const arro_t* arr1, coeff_t ex, arro_t* res, dhelpl_t dhl){

    int64_t e;
    int status = arro_resize(arr1->nrows, arr1->ncols, 0, res);

    if (status != DN_OK){
        return status;
    }

    #pragma omp parallel for schedule(dynamic, 16) if (arr1->size >= 64)
    for (e = 0; e < (int64_t)arr1->size; e++){
        dnaa_record(oti_pow_to(&arr1->p_data[e], ex, &res->p_data[e], dhl), &status);
    } // end for

    return status;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int arro_truncate_im_to(imdir_t idx, ord_t order, const arro_t* arr1, arro_t* res, dhelpl_t dhl){

    int64_t e;
    int status = arro_resize(arr1->nrows, arr1->ncols, 0, res);

    if (status != DN_OK){
        return status;
    }

    #pragma omp parallel for schedule(dynamic, 16) if (arr1->size >= 64)
    for (e = 0; e < (int64_t)arr1->size; e++){
        dnaa_record(oti_truncate_im_to(idx, order, &arr1->p_data[e], &res->p_data[e]), &status);
    } // end for

    return status;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int arro_truncate_order_to(ord_t order, const arro_t* arr1, arro_t* res, dhelpl_t dhl){

    int64_t e;
    int status = arro_resize(arr1->nrows, arr1->ncols, 0, res);

    if (status != DN_OK){
        return status;
    }

    #pragma omp parallel for schedule(dynamic, 16) if (arr1->size >= 64)
    for (e = 0; e < (int64_t)arr1->size; e++){
        dnaa_record(oti_truncate_order_to(order, &arr1->p_data[e], &res->p_data[e]), &status);
    } // end for

    return status;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int arro_get_order_im_to(ord_t order, const arro_t* arr1, arro_t* res, dhelpl_t dhl){

    int64_t e;
    int status = arro_resize(arr1->nrows, arr1->ncols, 0, res);

    if (status != DN_OK){
        return status;
    }

    #pragma omp parallel for schedule(dynamic, 16) if (arr1->size >= 64)
    for (e = 0; e < (int64_t)arr1->size; e++){
        dnaa_record(oti_get_order_im_to(order, &arr1->p_data[e], &res->p_data[e]), &status);
    } // end for

    return status;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int arro_compact_to(const arro_t* arr1, arro_t* res, dhelpl_t dhl){

    int64_t e;
    int status = arro_resize(arr1->nrows, arr1->ncols, 0, res);

    if (status != DN_OK){
        return status;
    }

    #pragma omp parallel for schedule(dynamic, 16) if (arr1->size >= 64)
    for (e = 0; e < (int64_t)arr1->size; e++){
        dnaa_record(oti_compact_to(&arr1->p_data[e], &res->p_data[e]), &status);
    } // end for

    return status;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int arro_matmul_OO_to(const arro_t* arr1, const arro_t* arr2, arro_t* res, dhelpl_t dhl){

    uint64_t n = arr1->nrows, m = arr1->ncols, p = arr2->ncols;
    int64_t e;
    arro_t tmp = arro_init();
    int status;

    if (arr2->nrows != m){
        return DN_ERR_SIZE;
    }

    // Each output element accumulates its products (gem: acc = a * b + acc); nact and trc grow to the
    // maximum over the row and column. The result is built apart so that it may alias an operand.
    status = arro_zeros_to(n, p, 0, &tmp);

    if (status != DN_OK){
        arro_free(&tmp);
        return status;
    }

    #pragma omp parallel for schedule(dynamic, 4) if (n * p >= 16)
    for (e = 0; e < (int64_t)(n * p); e++){

        uint64_t i = (uint64_t)e / p, j = (uint64_t)e % p, l;
        otinum_t* acc = &tmp.p_data[e];

        if (m > 0){
            dnaa_record(oti_mul_oo_to(&arr1->p_data[i * m], &arr2->p_data[j], acc, dhl), &status);
        }

        for (l = 1; l < m; l++){
            dnaa_record(oti_gem_oo_to(&arr1->p_data[l + i * m], &arr2->p_data[j + l * p], acc, acc,
                                      dhl), &status);
        } // end for

    } // end for

    if (status == DN_OK){

        arro_free(res);
        *res = tmp;

    } else {
        arro_free(&tmp);
    }

    return status;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int arro_transpose_to(const arro_t* arr1, arro_t* res){

    uint64_t i, j;
    arro_t tmp = arro_init();
    int status = arro_zeros_to(arr1->ncols, arr1->nrows, 0, &tmp);

    for (i = 0; i < arr1->nrows && status == DN_OK; i++){

        for (j = 0; j < arr1->ncols && status == DN_OK; j++){
            status = oti_copy_to(&arr1->p_data[j + i * arr1->ncols], &tmp.p_data[i + j * arr1->nrows]);
        } // end for

    } // end for

    if (status == DN_OK){

        arro_free(res);
        *res = tmp;

    } else {
        arro_free(&tmp);
    }

    return status;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int arro_solve_to(const arro_t* K, const arro_t* b, arro_t* x, dhelpl_t dhl){

    oarr_t sK = oarr_init(), sb = oarr_init(), sx = oarr_init();
    int status = arro_to_oarr(K, &sK);

    if (status == DN_OK){
        status = arro_to_oarr(b, &sb);
    }

    if (status == DN_OK){
        status = oarr_solve_to(&sK, &sb, &sx, dhl);
    }

    if (status == DN_OK){
        status = arro_from_oarr(&sx, x);
    }

    oarr_free(&sK);
    oarr_free(&sb);
    oarr_free(&sx);

    return status;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int arro_inv_to(const arro_t* A, arro_t* res, dhelpl_t dhl){

    oarr_t sA = oarr_init(), sr = oarr_init();
    int status = arro_to_oarr(A, &sA);

    if (status == DN_OK){
        status = oarr_inv_to(&sA, &sr, dhl);
    }

    if (status == DN_OK){
        status = arro_from_oarr(&sr, res);
    }

    oarr_free(&sA);
    oarr_free(&sr);

    return status;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int arro_det_to(const arro_t* A, otinum_t* res, dhelpl_t dhl){

    oarr_t sA = oarr_init();
    int status = arro_to_oarr(A, &sA);

    if (status == DN_OK){
        status = oarr_det_to(&sA, res, dhl);
    }

    oarr_free(&sA);

    return status;

}
// -------------------------------------------------------------------------------------------------------
