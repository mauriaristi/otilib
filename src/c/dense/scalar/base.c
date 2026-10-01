// Dense scalar: element access, conversions to and from sotinum_t, truncation and compaction
// (include/oti/dense/scalar/base.h).
//
// Unity-included from src/c/dense.c: static helpers here carry the dnsb_ prefix. A global direction is
// its own index in a dense number (prefix property), so no remap happens anywhere in this file.


// *******************************************************************************************************
// Tells whether the multiset v (length nv) contains the multiset u (length nu) with at least the same
// multiplicities. Both are sorted ascending.
static int dnsb_contains(const bases_t* v, ord_t nv, const bases_t* u, ord_t nu){

    ord_t i = 0, j = 0;

    while (j < nu){

        if (i >= nv){
            return 0;
        }

        if (v[i] == u[j]){

            i++;
            j++;

        } else if (v[i] < u[j]){

            i++;

        } else {

            return 0;

        }

    }

    return 1;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Derivative factor of a global direction: product of the factorials of its base multiplicities.
// Uses sshelp_global_unrank() only, so it covers every label up to 65535.
static coeff_t dnsb_deriv_factor(imdir_t idx, ord_t order){

    bases_t g[256];

    if (order == 0 || sshelp_global_unrank(idx, order, g) != SSHELP_OK){
        return 1.0;
    }

    return dnutil_tuple_factor(g, order);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Largest base (1-based) of the order-p direction with index idx.
static bases_t dnsb_max_base(ndir_t idx, ord_t p){

    bases_t u[256];

    sshelp_unrank(idx, p, u);

    return (bases_t)(u[p - 1] + 1);

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// ---------------------------------------     ACCESS     ------------------------------------------------
// -------------------------------------------------------------------------------------------------------

// *******************************************************************************************************
coeff_t oti_get_item(imdir_t idx, ord_t order, const otinum_t* num){

    if (order == 0){
        return (idx == 0) ? num->re : 0.0;
    }

    if (order > num->trc_order || !dnutil_dir_inside(idx, order, num->nact)){
        return 0.0;
    }

    return num->p_im[sshelp_order_offset(num->nact, order) + idx];

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oti_set_item(coeff_t val, imdir_t idx, ord_t order, otinum_t* num){

    bases_t g[256];
    int status;

    if (order == 0){

        num->re = val;
        return DN_OK;

    }

    if (order > num->trc_order){
        return DN_OK;
    }

    if (!dnutil_dir_inside(idx, order, num->nact)){

        // Nothing stored there and nothing to store: do not grow for a zero.
        if (val == 0.0){
            return DN_OK;
        }

        if (sshelp_global_unrank(idx, order, g) != SSHELP_OK){
            return DN_ERR_INDEX;
        }

        status = oti_add_bases(g[order - 1], num);

        if (status != DN_OK){
            return status;
        }

    }

    num->p_im[sshelp_order_offset(num->nact, order) + idx] = val;

    if (val != 0.0 && order > num->act_order){
        num->act_order = order;
    }

    return DN_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
coeff_t oti_get_deriv(imdir_t idx, ord_t order, const otinum_t* num){

    coeff_t coef = oti_get_item(idx, order, num);

    if (coef == 0.0){
        return 0.0;
    }

    return coef * dnsb_deriv_factor(idx, order);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
double oti_density(const otinum_t* num){

    ndir_t total = sshelp_ndir_total(num->nact, num->trc_order);
    ndir_t nz = 0, i;

    if (total == 0){
        return 0.0;
    }

    for (i = 0; i < total; i++){

        if (num->p_im[i] != 0.0){
            nz++;
        }

    }

    return (double)nz / (double)total;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
size_t oti_memory_size(const otinum_t* num){

    return sizeof(otinum_t) + (size_t)dnsm_capacity(num) * sizeof(coeff_t);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void oti_print(const otinum_t* num){

    bases_t u[256];
    ord_t p, j;
    ndir_t off, n, li;

    printf("  act_ord: " _PORDT ", trc_ord: " _PORDT ", nact: " _PBASEST ", re: " _PCOEFFT "\n",
        num->act_order, num->trc_order, num->nact, num->re);

    printf("      VALUE   ,    IMDIR  \n");
    printf("  " _PCOEFFT " , [0]\n", num->re);

    for (p = 1; p <= num->act_order && num->nact > 0; p++){

        off = sshelp_order_offset(num->nact, p);
        n   = sshelp_ndir_order(num->nact, p);

        for (li = 0; li < n; li++){

            if (num->p_im[off + li] == 0.0){
                continue;
            }

            printf("  " _PCOEFFT " , ", num->p_im[off + li]);

            sshelp_unrank(li, p, u);

            for (j = 0; j < p; j++){
                u[j]++;
            }

            printArrayUI16(u, p);

            printf("\n");

        }

    }

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// ---------------------------------------     CONVERSION     --------------------------------------------
// -------------------------------------------------------------------------------------------------------

// *******************************************************************************************************
otinum_t oti_from_soti(const sotinum_t* num, dhelpl_t dhl){

    otinum_t res = oti_init();

    return dnsm_ret(oti_from_soti_to(num, &res, dhl), &res);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oti_from_soti_to(const sotinum_t* num, otinum_t* res, dhelpl_t dhl){

    bases_t g[256], nact = 0;
    ord_t ordi, p, act = 0;
    ndir_t i, off;
    int status;

    (void)dhl;

    // nact is the largest base of any stored direction (explicit zeros included).
    for (ordi = 0; ordi < num->act_order; ordi++){

        p = ordi + 1;

        for (i = 0; i < num->p_nnz[ordi]; i++){

            if (sshelp_global_unrank(num->p_idx[ordi][i], p, g) != SSHELP_OK){
                return DN_ERR_INDEX;
            }

            if (g[p - 1] > nact){
                nact = g[p - 1];
            }

        }

        if (num->p_nnz[ordi] > 0){
            act = p;
        }

    }

    status = oti_create_empty_to(nact, num->trc_order, res);

    if (status != DN_OK){
        return status;
    }

    res->re = num->re;

    for (ordi = 0; ordi < act; ordi++){

        p   = ordi + 1;
        off = sshelp_order_offset(nact, p);

        for (i = 0; i < num->p_nnz[ordi]; i++){
            res->p_im[off + num->p_idx[ordi][i]] = num->p_im[ordi][i];
        }

    }

    res->act_order = (nact == 0) ? 0 : act;

    return DN_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
sotinum_t oti_to_soti(const otinum_t* num, dhelpl_t dhl){

    ndir_t p_nnz[_MAXORDER_OTI];
    ord_t ordi, p, act_order = 0;
    ndir_t off, n, li, pos;
    coeff_t val;
    sotinum_t res;

    // p_nnz is sized _MAXORDER_OTI: a hand-built number above it gives an empty number, re = NaN.
    if (num->trc_order > _MAXORDER_OTI){

        res    = soti_init();
        res.re = NAN;

        return res;

    }

    for (ordi = 0; ordi < num->trc_order; ordi++){

        p   = ordi + 1;
        off = sshelp_order_offset(num->nact, p);
        n   = (p <= num->act_order) ? sshelp_ndir_order(num->nact, p) : 0;
        p_nnz[ordi] = 0;

        for (li = 0; li < n; li++){

            if (num->p_im[off + li] != 0.0){
                p_nnz[ordi]++;
            }

        }

        if (p_nnz[ordi] > 0){
            act_order = p;
        }

    }

    res = soti_createEmpty_predef(p_nnz, num->trc_order, dhl);
    res.re = num->re;
    res.act_order = act_order;

    // Local and global indices coincide, and a block is already sorted by index.
    for (ordi = 0; ordi < act_order; ordi++){

        p   = ordi + 1;
        off = sshelp_order_offset(num->nact, p);
        n   = sshelp_ndir_order(num->nact, p);
        pos = 0;

        for (li = 0; li < n; li++){

            val = num->p_im[off + li];

            if (val != 0.0){

                res.p_im[ordi][pos]  = val;
                res.p_idx[ordi][pos] = (imdir_t)li;
                pos++;

            }

        }

        res.p_nnz[ordi] = pos;

    }

    return res;

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// ---------------------------------------     TRUNCATION     --------------------------------------------
// -------------------------------------------------------------------------------------------------------

// *******************************************************************************************************
otinum_t oti_truncate_im(imdir_t idx, ord_t order, const otinum_t* num){

    otinum_t res = oti_init();

    return dnsm_ret(oti_truncate_im_to(idx, order, num, &res), &res);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oti_truncate_im_to(imdir_t idx, ord_t order, const otinum_t* num, otinum_t* res){

    bases_t u_target[256], v[256], k;
    ndir_t off, n, li, total;
    ord_t dord;
    int status;

    // A no-op when res == num, a full copy otherwise; everything below works on res.
    status = oti_copy_to(num, res);

    if (status != DN_OK){
        return status;
    }

    k = res->nact;

    if (order == 0){

        total = sshelp_ndir_total(k, res->trc_order);

        if (total > 0){
            memset(res->p_im, 0, (size_t)total * sizeof(coeff_t));
        }

        res->re        = 0.0;
        res->act_order = 0;

        return DN_OK;

    }

    // A direction with a base above nact, or above act_order: nothing contains it.
    if (order > res->act_order || !dnutil_dir_inside(idx, order, k)){
        return DN_OK;
    }

    sshelp_unrank((ndir_t)idx, order, u_target);

    for (dord = order; dord <= res->act_order; dord++){

        off = sshelp_order_offset(k, dord);
        n   = sshelp_ndir_order(k, dord);

        memset(v, 0, (size_t)dord * sizeof(bases_t));

        for (li = 0; li < n; li++){

            if (dnsb_contains(v, dord, u_target, order)){
                res->p_im[off + li] = 0.0;
            }

            sshelp_next_dir(v, dord, k);

        }

    }

    return DN_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
otinum_t oti_truncate_order(ord_t order, const otinum_t* num){

    otinum_t res = oti_init();

    return dnsm_ret(oti_truncate_order_to(order, num, &res), &res);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oti_truncate_order_to(ord_t order, const otinum_t* num, otinum_t* res){

    ndir_t off, nimag;
    int status = oti_copy_to(num, res);

    if (status != DN_OK){
        return status;
    }

    if (order > res->trc_order){
        return DN_OK;
    }

    // Keep trc_order and nact; zero orders >= order so that orders above act_order hold zeros. Order 0
    // removes everything, the real part included (soti_truncate_order).
    if (order == 0){
        res->re = 0.0;
    }

    off   = (order == 0) ? 0 : sshelp_order_offset(res->nact, order);
    nimag = sshelp_ndir_total(res->nact, res->trc_order);

    if (nimag > off){
        memset(res->p_im + off, 0, (size_t)(nimag - off) * sizeof(coeff_t));
    }

    if (order == 0 || res->act_order > order - 1){
        res->act_order = (order == 0) ? 0 : (ord_t)(order - 1);
    }

    return DN_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
otinum_t oti_get_order_im(ord_t order, const otinum_t* num){

    otinum_t res = oti_init();

    return dnsm_ret(oti_get_order_im_to(order, num, &res), &res);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oti_get_order_im_to(ord_t order, const otinum_t* num, otinum_t* res){

    ord_t p;
    ndir_t off, n, total;
    int status = oti_copy_to(num, res);

    if (status != DN_OK){
        return status;
    }

    if (order == 0){

        total = sshelp_ndir_total(res->nact, res->trc_order);

        if (total > 0){
            memset(res->p_im, 0, (size_t)total * sizeof(coeff_t));
        }

        res->act_order = 0;

        return DN_OK;

    }

    res->re = 0.0;

    for (p = 1; p <= res->trc_order; p++){

        if (p == order){
            continue;
        }

        off = sshelp_order_offset(res->nact, p);
        n   = sshelp_ndir_order(res->nact, p);

        if (n > 0){
            memset(res->p_im + off, 0, (size_t)n * sizeof(coeff_t));
        }

    }

    res->act_order = (order <= res->act_order && res->nact > 0) ? order : 0;

    return DN_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
otinum_t oti_compact(const otinum_t* num){

    otinum_t res = oti_init();

    return dnsm_ret(oti_compact_to(num, &res), &res);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oti_compact_to(const otinum_t* num, otinum_t* res){

    bases_t k = num->nact, new_k = 0, b;
    ord_t p, new_act = 0, trc = num->trc_order;
    ndir_t j, n, off_old, off_new, nimag_new, start;
    const coeff_t* C;
    coeff_t re = num->re;

    // Colex order: the last nonzero of each order has the largest base of that order.
    for (p = 1; p <= num->act_order && k > 0; p++){

        n = sshelp_ndir_order(k, p);
        C = num->p_im + sshelp_order_offset(k, p);

        for (j = n; j > 0; j--){

            if (C[j - 1] != 0.0){

                b = dnsb_max_base(j - 1, p);
                new_k   = (b > new_k) ? b : new_k;
                new_act = p;
                break;

            }

        }

    }

    if (new_k == 0){
        new_act = 0;
    }

    nimag_new = sshelp_ndir_total(new_k, trc);

    if (res == num){

        // In place, lowest order first: new offsets and blocks are no larger than the old ones.
        for (p = 1; p <= new_act; p++){

            off_old = sshelp_order_offset(k, p);
            off_new = sshelp_order_offset(new_k, p);
            n       = sshelp_ndir_order(new_k, p);

            memmove(res->p_im + off_new, res->p_im + off_old, (size_t)n * sizeof(coeff_t));

        }

    } else {

        int status = dnsm_prepare(res, new_k, trc);

        if (status != DN_OK){
            return status;
        }

        for (p = 1; p <= new_act; p++){

            off_old = sshelp_order_offset(k, p);
            off_new = sshelp_order_offset(new_k, p);
            n       = sshelp_ndir_order(new_k, p);

            memcpy(res->p_im + off_new, num->p_im + off_old, (size_t)n * sizeof(coeff_t));

        }

    }

    // Orders above the new act_order are zero.
    start = sshelp_order_offset(new_k, (ord_t)(new_act + 1));

    if (nimag_new > start){
        memset(res->p_im + start, 0, (size_t)(nimag_new - start) * sizeof(coeff_t));
    }

    res->re        = re;
    res->nact      = new_k;
    res->trc_order = trc;
    res->act_order = new_act;

    return DN_OK;

}
// -------------------------------------------------------------------------------------------------------
