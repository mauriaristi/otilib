// Semi-sparse scalar: element access, conversions to/from sotinum_t, truncation and compaction.


// *******************************************************************************************************
// Comparator for qsort() over bases_t labels, used by ssoti_from_soti() to sort raw base labels.
static int ssoti_base_cmp_bases(const void* a, const void* b){

    bases_t x = *(const bases_t*)a;
    bases_t y = *(const bases_t*)b;

    return (x > y) - (x < y);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Tells whether the multiset v (length nv, nondecreasing) contains the multiset u (length nu,
// nondecreasing) with at least the same multiplicities. Both must be sorted ascending.
static int ssoti_base_contains(const bases_t* v, ord_t nv, const bases_t* u, ord_t nu){

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
// Factorial of a small order, as a coeff_t (matches dhelp_get_deriv_factor's scale).
static coeff_t ssoti_base_factorial(ord_t n){

    coeff_t r = 1.0;
    ord_t i;

    for (i = 2; i <= n; i++){
        r *= (coeff_t)i;
    }

    return r;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Derivative factor of a global direction: the product of the factorials of its base multiplicities.
// Computed from sshelp_global_unrank() only, so it covers labels up to 65535 (no dhelp table lookup).
static coeff_t ssoti_base_deriv_factor(imdir_t idx, ord_t order){

    bases_t g[_MAXORDER_OTI];
    coeff_t factor = 1.0;
    ord_t i = 0, mult;

    if (order == 0){
        return 1.0;
    }

    sshelp_global_unrank(idx, order, g);

    while (i < order){

        mult = 1;

        while (i + mult < order && g[i + mult] == g[i]){
            mult++;
        }

        factor *= ssoti_base_factorial(mult);
        i += mult;

    }

    return factor;

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// ---------------------------------------     ACCESS     ------------------------------------------------
// -------------------------------------------------------------------------------------------------------

// *******************************************************************************************************
coeff_t ssoti_get_item(imdir_t idx, ord_t order, const ssotinum_t* num){

    ndir_t local_idx;
    int found;

    if (order == 0){
        return num->re;
    }

    if (order > num->trc_order){
        return 0.0;
    }

    found = sshelp_global_to_local(idx, order, num->p_bases, num->nbases, &local_idx);

    if (found != 1){
        return 0.0;
    }

    return num->p_im[sshelp_order_offset(num->nbases, order) + local_idx];

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void ssoti_set_item(coeff_t val, imdir_t idx, ord_t order, ssotinum_t* num){

    bases_t g[_MAXORDER_OTI];
    bases_t unique_g[_MAXORDER_OTI];
    ord_t m = 0, i;
    ndir_t local_idx;
    int found;

    if (order == 0){

        num->re = val;
        return;

    }

    if (order > num->trc_order){
        return;
    }

    found = sshelp_global_to_local(idx, order, num->p_bases, num->nbases, &local_idx);

    if (found != 1){

        if (val == 0.0){
            // Nothing stored there yet and nothing to add: don't grow the set for a zero.
            return;
        }

        sshelp_global_unrank(idx, order, g);

        for (i = 0; i < order; i++){

            if (m == 0 || unique_g[m - 1] != g[i]){
                unique_g[m++] = g[i];
            }

        }

        ssoti_add_bases(unique_g, m, num);

        found = sshelp_global_to_local(idx, order, num->p_bases, num->nbases, &local_idx);

    }

    num->p_im[sshelp_order_offset(num->nbases, order) + local_idx] = val;

    if (val != 0.0 && order > num->act_order){
        num->act_order = order;
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
coeff_t ssoti_get_deriv(imdir_t idx, ord_t order, const ssotinum_t* num){

    coeff_t coef = ssoti_get_item(idx, order, num);

    return coef * ssoti_base_deriv_factor(idx, order);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
double ssoti_density(const ssotinum_t* num){

    ndir_t total = sshelp_ndir_total(num->nbases, num->trc_order);
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
size_t ssoti_memory_size(const ssotinum_t* num){

    size_t size = sizeof(ssotinum_t);
    ndir_t nimag_cap;

    if (num->cap_bases == 0){
        return size;
    }

    nimag_cap = sshelp_ndir_total(num->cap_bases, num->trc_order);

    size += (size_t)num->cap_bases * sizeof(bases_t);
    size += (size_t)nimag_cap * sizeof(coeff_t);

    return size;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void ssoti_print(const ssotinum_t* num){

    bases_t gg[_MAXORDER_OTI];
    bases_t i;
    ord_t p, j;
    ndir_t off, n, li;

    printf("  act_ord: " _PORDT ", trc_ord: " _PORDT ", nbases: " _PBASEST ", re: " _PCOEFFT "\n",
        num->act_order, num->trc_order, num->nbases, num->re);

    printf("  active bases: [");

    for (i = 0; i < num->nbases; i++){

        if (i > 0){
            printf(", ");
        }

        printf(_PBASEST, num->p_bases[i]);

    }

    printf("]\n");

    printf("      VALUE   ,    IMDIR  \n");
    printf("  " _PCOEFFT " , [0]\n", num->re);

    for (p = 1; p <= num->act_order; p++){

        off = sshelp_order_offset(num->nbases, p);
        n   = sshelp_ndir_order(num->nbases, p);

        for (li = 0; li < n; li++){

            if (num->p_im[off + li] == 0.0){
                continue;
            }

            printf("  " _PCOEFFT " , ", num->p_im[off + li]);

            sshelp_unrank(li, p, gg);

            for (j = 0; j < p; j++){
                gg[j] = num->p_bases[gg[j]];
            }

            printArrayUI16(gg, p);

            printf("\n");

        }

    }

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// ---------------------------------------     CONVERSION     --------------------------------------------
// -------------------------------------------------------------------------------------------------------

// *******************************************************************************************************
ssotinum_t ssoti_from_soti(const sotinum_t* num, dhelpl_t dhl){

    sshelp_ws_t* ws = ssoti_ws();
    bases_t g[_MAXORDER_OTI];
    bases_t* p_raw;
    ndir_t total_raw = 0, pos = 0, nk = 0, i;
    ord_t ordi, p, j;
    ssotinum_t res;

    (void)dhl;

    for (ordi = 0; ordi < num->act_order; ordi++){
        total_raw += (ndir_t)num->p_nnz[ordi] * (ordi + 1);
    }

    if (total_raw > 0){
        ssoti_ws_need(ws, 0, 0, (size_t)total_raw);
    }

    p_raw = ws->p_bases;

    for (ordi = 0; ordi < num->act_order; ordi++){

        p = ordi + 1;

        for (i = 0; i < num->p_nnz[ordi]; i++){

            sshelp_global_unrank(num->p_idx[ordi][i], p, g);

            for (j = 0; j < p; j++){
                p_raw[pos++] = g[j];
            }

        }

    }

    if (total_raw > 1){
        qsort(p_raw, total_raw, sizeof(bases_t), ssoti_base_cmp_bases);
    }

    for (i = 0; i < total_raw; i++){

        if (nk == 0 || p_raw[nk - 1] != p_raw[i]){
            p_raw[nk++] = p_raw[i];
        }

    }

    res = ssoti_create_empty(p_raw, (bases_t)nk, num->trc_order);
    res.re = num->re;

    for (ordi = 0; ordi < num->act_order; ordi++){

        p = ordi + 1;

        for (i = 0; i < num->p_nnz[ordi]; i++){
            ssoti_set_item(num->p_im[ordi][i], num->p_idx[ordi][i], p, &res);
        }

    }

    return res;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
sotinum_t ssoti_to_soti(const ssotinum_t* num, dhelpl_t dhl){

    ndir_t p_nnz[_MAXORDER_OTI];
    ord_t ordi, p, act_order = 0;
    ndir_t off, n, li, pos;
    coeff_t val;
    imdir_t gidx;
    int status;
    sotinum_t res;

    for (ordi = 0; ordi < num->trc_order; ordi++){

        p   = ordi + 1;
        off = sshelp_order_offset(num->nbases, p);
        n   = sshelp_ndir_order(num->nbases, p);
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

    for (ordi = 0; ordi < act_order; ordi++){

        p   = ordi + 1;
        off = sshelp_order_offset(num->nbases, p);
        n   = sshelp_ndir_order(num->nbases, p);
        pos = 0;

        for (li = 0; li < n; li++){

            val = num->p_im[off + li];

            if (val != 0.0){

                status = sshelp_local_to_global(li, p, num->p_bases, num->nbases, &gidx);

                if (status != SSHELP_OK){
                    printf("ERROR: Semi-sparse to sparse conversion: global index overflow.\n");
                    exit(OTI_OutOfMemory);
                }

                res.p_im[ordi][pos]  = val;
                res.p_idx[ordi][pos] = gidx;
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
ssotinum_t ssoti_truncate_im(imdir_t idx, ord_t order, const ssotinum_t* num){

    ssotinum_t res = ssoti_init();

    ssoti_truncate_im_to(idx, order, num, &res);

    return res;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void ssoti_truncate_im_to(imdir_t idx, ord_t order, const ssotinum_t* num, ssotinum_t* res){

    bases_t u_target[_MAXORDER_OTI];
    bases_t v[_MAXORDER_OTI];
    ndir_t target_local, off, n, li, total;
    ord_t dord, i;
    int found;

    // Safe regardless of aliasing: a no-op when res == num, a full copy otherwise. Every
    // remaining read/write below happens on res, never on num.
    ssoti_copy_to(num, res);

    if (order == 0){

        total = sshelp_ndir_total(res->nbases, res->trc_order);

        if (total > 0){
            memset(res->p_im, 0, total * sizeof(coeff_t));
        }

        res->re        = 0.0;
        res->act_order = 0;

        return;

    }

    found = sshelp_global_to_local(idx, order, res->p_bases, res->nbases, &target_local);

    if (found != 1 || order > res->act_order){
        // Either idx uses a base outside the active set (nothing can contain it), or nothing
        // at or above 'order' is active: no truncation needed.
        return;
    }

    sshelp_unrank(target_local, order, u_target);

    for (dord = order; dord <= res->act_order; dord++){

        off = sshelp_order_offset(res->nbases, dord);
        n   = sshelp_ndir_order(res->nbases, dord);

        for (i = 0; i < dord; i++){
            v[i] = 0;
        }

        for (li = 0; li < n; li++){

            if (ssoti_base_contains(v, dord, u_target, order)){
                res->p_im[off + li] = 0.0;
            }

            if (li + 1 < n){
                sshelp_next_dir(v, dord, res->nbases);
            }

        }

    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
ssotinum_t ssoti_truncate_order(ord_t order, const ssotinum_t* num){

    ssotinum_t res = ssoti_init();

    ssoti_truncate_order_to(order, num, &res);

    return res;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void ssoti_truncate_order_to(ord_t order, const ssotinum_t* num, ssotinum_t* res){

    ndir_t off, nimag;

    ssoti_copy_to(num, res);

    // Order 0 removes everything, the real part included (soti_truncate_order).
    if (order == 0){

        ssoti_set_r(0.0, res);
        return;

    }

    if (order > res->trc_order){
        return;
    }

    // Keep trc_order; zero orders >= order so that orders above act_order hold zeros.
    off   = sshelp_order_offset(res->nbases, order);
    nimag = sshelp_ndir_total(res->nbases, res->trc_order);

    if (nimag > off){
        memset(res->p_im + off, 0, (nimag - off) * sizeof(coeff_t));
    }

    res->act_order = (res->act_order < order - 1) ? res->act_order : (ord_t)(order - 1);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
ssotinum_t ssoti_get_order_im(ord_t order, const ssotinum_t* num){

    ssotinum_t res = ssoti_init();

    ssoti_get_order_im_to(order, num, &res);

    return res;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void ssoti_get_order_im_to(ord_t order, const ssotinum_t* num, ssotinum_t* res){

    ord_t p;
    ndir_t off, n, total;

    ssoti_copy_to(num, res);

    if (order == 0){

        total = sshelp_ndir_total(res->nbases, res->trc_order);

        if (total > 0){
            memset(res->p_im, 0, total * sizeof(coeff_t));
        }

        res->act_order = 0;

        return;

    }

    res->re = 0.0;

    for (p = 1; p <= res->trc_order; p++){

        if (p == order){
            continue;
        }

        off = sshelp_order_offset(res->nbases, p);
        n   = sshelp_ndir_order(res->nbases, p);

        if (n > 0){
            memset(res->p_im + off, 0, n * sizeof(coeff_t));
        }

    }

    res->act_order = (order <= res->trc_order) ? order : 0;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
ssotinum_t ssoti_compact(const ssotinum_t* num){

    ssotinum_t res = ssoti_init();

    ssoti_compact_to(num, &res);

    return res;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void ssoti_compact_to(const ssotinum_t* num, ssotinum_t* res){

    sshelp_ws_t* ws;
    bases_t old_k = num->nbases, new_k = 0, i;
    bases_t *keep, *new_bases, *pos, *v;
    ord_t p, new_act = 0;
    ndir_t off_old, off_new, n, li, nimag_new, nimag_bound, new_li;
    coeff_t* p_new_im;
    coeff_t val;

    if (old_k == 0){

        if (res != num){
            ssoti_copy_to(num, res);
        }

        return;

    }

    ws = ssoti_ws();
    nimag_bound = sshelp_ndir_total(old_k, num->trc_order);

    ssoti_ws_need(ws, (size_t)nimag_bound, 0, (size_t)old_k * 3 + (size_t)num->trc_order);

    keep      = ws->p_bases;
    new_bases = ws->p_bases + old_k;
    pos       = ws->p_bases + 2 * old_k;
    v         = ws->p_bases + 3 * old_k;
    p_new_im  = ws->p_coef;

    for (i = 0; i < old_k; i++){
        keep[i] = 0;
    }

    // Pass 1: mark every base used by any nonzero coefficient, and the highest such order.
    for (p = 1; p <= num->act_order; p++){

        n       = sshelp_ndir_order(old_k, p);
        off_old = sshelp_order_offset(old_k, p);

        for (i = 0; i < p; i++){
            v[i] = 0;
        }

        for (li = 0; li < n; li++){

            if (num->p_im[off_old + li] != 0.0){

                new_act = p;

                for (i = 0; i < p; i++){
                    keep[v[i]] = 1;
                }

            }

            if (li + 1 < n){
                sshelp_next_dir(v, p, old_k);
            }

        }

    }

    for (i = 0; i < old_k; i++){

        if (keep[i]){

            pos[i] = new_k;
            new_bases[new_k] = num->p_bases[i];
            new_k++;

        }

    }

    nimag_new = sshelp_ndir_total(new_k, num->trc_order);
    memset(p_new_im, 0, (size_t)nimag_new * sizeof(coeff_t));

    // Pass 2: move every kept nonzero to its new local index (colex rank of the mapped tuple).
    for (p = 1; p <= new_act; p++){

        n       = sshelp_ndir_order(old_k, p);
        off_old = sshelp_order_offset(old_k, p);
        off_new = sshelp_order_offset(new_k, p);

        for (i = 0; i < p; i++){
            v[i] = 0;
        }

        for (li = 0; li < n; li++){

            val = num->p_im[off_old + li];

            if (val != 0.0){

                new_li = 0;

                for (i = 0; i < p; i++){
                    new_li += (ndir_t)sshelp_comb((uint64_t)pos[v[i]] + i, i + 1);
                }

                p_new_im[off_new + new_li] = val;

            }

            if (li + 1 < n){
                sshelp_next_dir(v, p, old_k);
            }

        }

    }

    // Every read of num above is done: safe now even when res aliases num.
    ssoti_reserve(res, new_k, num->trc_order);

    memcpy(res->p_bases, new_bases, (size_t)new_k * sizeof(bases_t));

    if (nimag_new > 0){
        memcpy(res->p_im, p_new_im, (size_t)nimag_new * sizeof(coeff_t));
    }

    res->re        = num->re;
    res->nbases    = new_k;
    res->act_order = new_act;
    res->trc_order = num->trc_order;

}
// -------------------------------------------------------------------------------------------------------
