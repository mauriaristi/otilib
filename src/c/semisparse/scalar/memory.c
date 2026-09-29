// Semi-sparse scalar: memory management and the per-thread workspace.


// Scratch workspace of each thread (zero-initialized equals sshelp_ws_init()).
static _Thread_local sshelp_ws_t ssoti_tls_ws;


// *******************************************************************************************************
// Prints an allocation error and exits, like the sparse types.
static void ssoti_out_of_memory(void){

    printf("ERROR: Not enough memory for a semi-sparse OTI number. Exiting...\n");
    exit(OTI_OutOfMemory);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Grows a workspace or exits.
static void ssoti_ws_need(sshelp_ws_t* ws, size_t ncoef, size_t nmap, size_t nbases){

    if (sshelp_ws_reserve(ws, ncoef, nmap, nbases) != SSHELP_OK){
        ssoti_out_of_memory();
    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Number of imaginary coefficients over k bases to order n, or exit when it overflows.
static ndir_t ssoti_nimag_checked(bases_t k, ord_t n){

    ndir_t nimag;

    if (sshelp_ndir_total_checked(k, n, &nimag) != SSHELP_OK){
        printf("ERROR: Semi-sparse OTI number with %u bases at order %u is too large. Exiting...\n",
            (unsigned)k, (unsigned)n);
        exit(OTI_OutOfMemory);
    }

    return nimag;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
sshelp_ws_t* ssoti_ws(void){

    return &ssoti_tls_ws;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void ssoti_ws_release(void){

    sshelp_ws_free(&ssoti_tls_ws);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
ssotinum_t ssoti_init(void){

    ssotinum_t num;

    num.re        = 0.0;
    num.p_im      = NULL;
    num.p_bases   = NULL;
    num.nbases    = 0;
    num.cap_bases = 0;
    num.act_order = 0;
    num.trc_order = 0;
    num.flag      = 1;

    return num;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
ssotinum_t ssoti_create_empty(const bases_t* bases, bases_t k, ord_t trc_order){

    ssotinum_t num = ssoti_init();
    ndir_t nimag = ssoti_nimag_checked(k, trc_order);

    num.trc_order = trc_order;

    if (k == 0){
        return num;
    }

    num.p_bases = (bases_t*)malloc((size_t)k * sizeof(bases_t));
    num.p_im    = (nimag > 0) ? (coeff_t*)calloc(nimag, sizeof(coeff_t)) : NULL;

    if (num.p_bases == NULL || (nimag > 0 && num.p_im == NULL)){
        ssoti_out_of_memory();
    }

    memcpy(num.p_bases, bases, (size_t)k * sizeof(bases_t));

    num.nbases    = k;
    num.cap_bases = k;

    return num;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
ssotinum_t ssoti_create_r(coeff_t re, ord_t trc_order){

    ssotinum_t num = ssoti_init();

    num.re        = re;
    num.trc_order = trc_order;

    return num;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
ssotinum_t ssoti_e(imdir_t idx, ord_t order, ord_t trc_order){

    bases_t g[256], bases[256], k = 0;
    ord_t i, trc = (trc_order > order) ? trc_order : order;
    ssotinum_t num;

    // Order 0 is the real unit.
    if (order == 0){
        return ssoti_create_r(1.0, trc);
    }

    if (sshelp_global_unrank(idx, order, g) != SSHELP_OK){
        printf("ERROR: Direction index %llu of order %u needs a base label above 65535. "
               "Exiting...\n", (unsigned long long)idx, (unsigned)order);
        exit(OTI_BadIndx);
    }

    // The labels come sorted; the active set is the distinct ones.
    for (i = 0; i < order; i++){

        if (k == 0 || bases[k - 1] != g[i]){
            bases[k++] = g[i];
        }

    }

    num = ssoti_create_empty(bases, k, trc);
    ssoti_set_item(1.0, idx, order, &num);

    return num;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void ssoti_reserve(ssotinum_t* num, bases_t cap, ord_t trc_order){

    bases_t new_cap;
    ord_t new_trc;
    ndir_t nimag, nused_old, nused_new;
    coeff_t* p_im;
    bases_t* p_bases;

    if (cap <= num->cap_bases && trc_order <= num->trc_order){
        return;
    }

    if (num->flag == 0){
        printf("ERROR: Cannot grow a semi-sparse OTI view. Exiting...\n");
        exit(OTI_BadIndx);
    }

    new_cap = (cap > num->cap_bases) ? cap : num->cap_bases;
    new_trc = (trc_order > num->trc_order) ? trc_order : num->trc_order;
    nimag   = ssoti_nimag_checked(new_cap, new_trc);

    // Order offsets depend only on (k, p), so the used prefix keeps its layout.
    if (new_cap > 0){

        p_im    = (nimag > 0) ? (coeff_t*)realloc(num->p_im, nimag * sizeof(coeff_t)) : num->p_im;
        p_bases = (bases_t*)realloc(num->p_bases, (size_t)new_cap * sizeof(bases_t));

        if ((nimag > 0 && p_im == NULL) || p_bases == NULL){
            ssoti_out_of_memory();
        }

        num->p_im    = p_im;
        num->p_bases = p_bases;

    }

    // New orders over the current bases start at zero.
    nused_old = sshelp_ndir_total(num->nbases, num->trc_order);
    nused_new = sshelp_ndir_total(num->nbases, new_trc);

    if (nused_new > nused_old){
        memset(num->p_im + nused_old, 0, (nused_new - nused_old) * sizeof(coeff_t));
    }

    num->cap_bases = new_cap;
    num->trc_order = new_trc;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void ssoti_free(ssotinum_t* num){

    if (num->flag != 0){

        free(num->p_im);
        free(num->p_bases);

    }

    *num = ssoti_init();

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
ssotinum_t ssoti_copy(const ssotinum_t* num){

    ssotinum_t res = ssoti_create_empty(num->p_bases, num->nbases, num->trc_order);

    ssoti_copy_to(num, &res);

    return res;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void ssoti_copy_to(const ssotinum_t* num, ssotinum_t* res){

    ndir_t nimag = sshelp_ndir_total(num->nbases, num->trc_order);

    if (num == res){
        return;
    }

    ssoti_reserve(res, num->nbases, num->trc_order);

    if (num->nbases > 0){

        memcpy(res->p_bases, num->p_bases, (size_t)num->nbases * sizeof(bases_t));
        memcpy(res->p_im, num->p_im, nimag * sizeof(coeff_t));

    }

    res->re        = num->re;
    res->nbases    = num->nbases;
    res->act_order = num->act_order;
    res->trc_order = num->trc_order;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void ssoti_add_bases(const bases_t* bases, bases_t k, ssotinum_t* num){

    sshelp_ws_t* ws = ssoti_ws();
    bases_t *p_union, *p_pos, nu, kold = num->nbases;
    ndir_t nimag;
    ord_t p;
    size_t nb = (size_t)kold + k;

    if (k == 0){
        return;
    }

    ssoti_ws_need(ws, 0, 0, 2 * nb);
    p_union = ws->p_bases;
    p_pos   = ws->p_bases + nb;

    nu = sshelp_union_bases(num->p_bases, kold, bases, k, p_union, p_pos, NULL);

    if (nu == kold){
        return;
    }

    ssoti_reserve(num, nu, num->trc_order);

    // The union may be moved by the workspace below, so store it first.
    memcpy(num->p_bases, p_union, (size_t)nu * sizeof(bases_t));

    if (sshelp_is_leading(p_pos, kold)){

        // Zero-extension in place, highest order first: every block moves up.
        for (p = num->trc_order; p >= 1; p--){

            ndir_t off_old = sshelp_order_offset(kold, p), n_old = sshelp_ndir_order(kold, p);
            ndir_t off_new = sshelp_order_offset(nu, p),   n_new = sshelp_ndir_order(nu, p);

            if (n_old > 0){
                memmove(num->p_im + off_new, num->p_im + off_old, n_old * sizeof(coeff_t));
            }

            memset(num->p_im + off_new + n_old, 0, (n_new - n_old) * sizeof(coeff_t));

        }

    } else {

        // Remap through scratch: the source layout is still the old set's.
        nimag = sshelp_ndir_total(nu, num->trc_order);

        // Growing only the coefficient buffer leaves p_pos (in the base buffer) in place.
        ssoti_ws_need(ws, nimag, 0, 0);

        ssoti_kernel_expand(num, p_pos, nu, num->trc_order, ws->p_coef);
        memcpy(num->p_im, ws->p_coef, nimag * sizeof(coeff_t));

    }

    num->nbases = nu;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void ssoti_set_r(coeff_t val, ssotinum_t* num){

    num->re        = val;
    num->nbases    = 0;
    num->act_order = 0;

}
// -------------------------------------------------------------------------------------------------------
