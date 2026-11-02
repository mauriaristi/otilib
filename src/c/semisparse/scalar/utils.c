// Semi-sparse scalars: order and derivative extraction, truncated products, rom_eval (PLAN-semisparse-
// sparse-leveling.md, Phase 2).
// Declarations in include/oti/semisparse/scalar/utils.h.


// -------------------------------------------------------------------------------------------------------
// ---------------------------------------     HELPERS     -----------------------------------------------
// -------------------------------------------------------------------------------------------------------

// *******************************************************************************************************
int ssutil_global_to_tuple(imdir_t idx, ord_t order, const bases_t* bases, bases_t k, bases_t* u){

    bases_t g[256];
    ord_t i;

    if (order == 0){
        return 1;
    }

    if (sshelp_global_unrank(idx, order, g) != SSHELP_OK){
        return 0;
    }

    // The map from global to local bases is increasing, so the local tuple stays sorted.
    for (i = 0; i < order; i++){

        if (!ssutil_base_search(g[i], bases, k, &u[i])){
            return 0;
        }

    }

    return 1;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void ssutil_expand_order_acc(const coeff_t* src, bases_t k, const bases_t* pos, bases_t ku, ord_t p,
                             uint64_t m, coeff_t alpha, coeff_t* dst){

    ndir_t Ns = sshelp_ndir_order(k, p), j;
    uint64_t e;
    bases_t u[256], v[256];
    ord_t i;
    sshelp_rank_tab_t tab;

    if (Ns == 0 || m == 0){
        return;
    }

    // Leading set: every direction keeps its local index (prefix property).
    if (sshelp_is_leading(pos, k)){

        uint64_t n = (uint64_t)Ns * m;

        for (e = 0; e < n; e++){
            dst[e] += alpha * src[e];
        }

        return;

    }

    if (sshelp_rank_tab_init(&tab, ku, p) != SSHELP_OK){
        ssoti_out_of_memory();
    }

    for (i = 0; i < p; i++){
        u[i] = 0;
    }

    for (j = 0; j < Ns; j++){

        const coeff_t* S = src + (uint64_t)j * m;
        coeff_t* D;

        for (i = 0; i < p; i++){
            v[i] = pos[u[i]];
        }

        D = dst + (uint64_t)sshelp_rank(v, p, &tab) * m;

        for (e = 0; e < m; e++){
            D[e] += alpha * S[e];
        }

        sshelp_next_dir(u, p, k);

    }

    sshelp_rank_tab_free(&tab);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
bases_t ssutil_mark_global_bases(ord_t p, const uint8_t* nz, ndir_t nvals, uint8_t* mark){

    bases_t g[256], count = 0;
    ndir_t d;
    ord_t i;

    for (d = 0; d < nvals; d++){

        if (!nz[d]){
            continue;
        }

        if (sshelp_global_unrank((imdir_t)d, p, g) != SSHELP_OK){
            continue;
        }

        for (i = 0; i < p; i++){

            if (!mark[g[i]]){

                mark[g[i]] = 1;
                count++;

            }

        }

    }

    return count;

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// ---------------------------------------     EXTRACTION     --------------------------------------------
// -------------------------------------------------------------------------------------------------------

// *******************************************************************************************************
// Shared body of ssoti_extract_im_to() and ssoti_extract_deriv_to().
static void ssoti_extract_common(imdir_t idx, ord_t order, const ssotinum_t* num, int deriv,
                                 ssotinum_t* res){

    bases_t k = num->nbases, gl[256], r[256], d[256];
    ord_t trc_r, act_r, s, i;
    ssotinum_t tmp;
    sshelp_rank_tab_t tab;

    if (order == 0){

        ssoti_copy_to(num, res);
        return;

    }

    // As soti_extract_im_to(): a direction above act_order gives a real zero.
    if (order > num->act_order || order > num->trc_order){

        ssoti_set_r(0.0, res);
        return;

    }

    trc_r = (ord_t)(num->trc_order - order);
    act_r = (ord_t)(num->act_order - order);
    tmp   = ssoti_create_empty(num->p_bases, k, trc_r);

    if (ssutil_global_to_tuple(idx, order, num->p_bases, k, gl)){

        coeff_t fg = deriv ? ssutil_tuple_factor(gl, order) : 1.0;

        if (sshelp_rank_tab_init(&tab, k, num->trc_order) != SSHELP_OK){
            ssoti_out_of_memory();
        }

        tmp.re = num->p_im[sshelp_order_offset(k, order) + sshelp_rank(gl, order, &tab)] * fg;

        // Every quotient direction r of order s maps to the input direction r * g of order s+order.
        for (s = 1; s <= act_r; s++){

            ndir_t Ns = sshelp_ndir_order(k, s), j;
            ndir_t off_src = sshelp_order_offset(k, (ord_t)(s + order));
            ndir_t off_dst = sshelp_order_offset(k, s);

            for (i = 0; i < s; i++){
                r[i] = 0;
            }

            for (j = 0; j < Ns; j++){

                coeff_t val;

                ssutil_merge_tuples(r, s, gl, order, d);
                val = num->p_im[off_src + sshelp_rank(d, (ord_t)(s + order), &tab)];

                if (deriv){
                    val *= ssutil_tuple_factor(d, (ord_t)(s + order)) / ssutil_tuple_factor(r, s);
                }

                tmp.p_im[off_dst + j] = val;
                sshelp_next_dir(r, s, k);

            }

        }

        sshelp_rank_tab_free(&tab);
        tmp.act_order = act_r;

    }

    ssoti_copy_to(&tmp, res);
    ssoti_free(&tmp);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
ssotinum_t ssoti_extract_im(imdir_t idx, ord_t order, const ssotinum_t* num){

    ssotinum_t res = ssoti_init();

    ssoti_extract_common(idx, order, num, 0, &res);

    return res;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void ssoti_extract_im_to(imdir_t idx, ord_t order, const ssotinum_t* num, ssotinum_t* res){

    ssoti_extract_common(idx, order, num, 0, res);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
ssotinum_t ssoti_extract_deriv(imdir_t idx, ord_t order, const ssotinum_t* num){

    ssotinum_t res = ssoti_init();

    ssoti_extract_common(idx, order, num, 1, &res);

    return res;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void ssoti_extract_deriv_to(imdir_t idx, ord_t order, const ssotinum_t* num, ssotinum_t* res){

    ssoti_extract_common(idx, order, num, 1, res);

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// ---------------------------------------     TRUNCATED ALGEBRA     -------------------------------------
// -------------------------------------------------------------------------------------------------------

// *******************************************************************************************************
void ssoti_trunc_sub_to(ord_t order, const ssotinum_t* num1, const ssotinum_t* num2,
                        ssotinum_t* res){

    bases_t *p_u, *pos1, *pos2, nu;
    size_t nbuf = (size_t)num1->nbases + num2->nbases + 1;
    ord_t trc = (num1->trc_order > num2->trc_order) ? num1->trc_order : num2->trc_order;
    ssotinum_t tmp;

    p_u  = (bases_t*)malloc(3 * nbuf * sizeof(bases_t));

    if (p_u == NULL){
        ssoti_out_of_memory();
    }

    pos1 = p_u + nbuf;
    pos2 = pos1 + nbuf;
    nu   = sshelp_union_bases(num1->p_bases, num1->nbases, num2->p_bases, num2->nbases, p_u, pos1,
                              pos2);
    tmp  = ssoti_create_empty(p_u, nu, trc);

    if (order == 0){

        tmp.re = num1->re - num2->re;

    } else if (order <= trc){

        coeff_t* dst = tmp.p_im + sshelp_order_offset(nu, order);

        if (order <= num1->act_order && order <= num1->trc_order){
            ssutil_expand_order_acc(num1->p_im + sshelp_order_offset(num1->nbases, order),
                                    num1->nbases, pos1, nu, order, 1, 1.0, dst);
        }

        if (order <= num2->act_order && order <= num2->trc_order){
            ssutil_expand_order_acc(num2->p_im + sshelp_order_offset(num2->nbases, order),
                                    num2->nbases, pos2, nu, order, 1, -1.0, dst);
        }

        tmp.act_order = order;

    }

    ssoti_copy_to(&tmp, res);
    ssoti_free(&tmp);
    free(p_u);

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// ---------------------------------------     ROM EVALUATION     ----------------------------------------
// -------------------------------------------------------------------------------------------------------

// *******************************************************************************************************
coeff_t ssoti_rom_eval(const ssotinum_t* num, const coeff_t* deltas){

    bases_t k = num->nbases, u[256];
    ord_t top = (num->act_order < num->trc_order) ? num->act_order : num->trc_order, p, i;
    coeff_t val = num->re;

    for (p = 1; p <= top; p++){

        ndir_t Np = sshelp_ndir_order(k, p), j;
        const coeff_t* C = num->p_im + sshelp_order_offset(k, p);

        for (i = 0; i < p; i++){
            u[i] = 0;
        }

        for (j = 0; j < Np; j++){

            coeff_t prod = C[j];

            if (prod != 0.0){

                for (i = 0; i < p; i++){
                    prod *= deltas[u[i]];
                }

                val += prod;

            }

            sshelp_next_dir(u, p, k);

        }

    }

    return val;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int ssoti_rom_eval_points(const ssotinum_t* num, const coeff_t* deltas, uint64_t npts,
                          coeff_t* out){

    bases_t k = num->nbases, u[256];
    ord_t top = (num->act_order < num->trc_order) ? num->act_order : num->trc_order, p, i;
    coeff_t* prod;
    uint64_t t;

    for (t = 0; t < npts; t++){
        out[t] = num->re;
    }

    if (top == 0 || npts == 0){
        return 0;
    }

    prod = (coeff_t*)malloc((size_t)npts * sizeof(coeff_t));

    if (prod == NULL){
        return OTI_OutOfMemory;
    }

    for (p = 1; p <= top; p++){

        ndir_t Np = sshelp_ndir_order(k, p), j;
        const coeff_t* C = num->p_im + sshelp_order_offset(k, p);

        for (i = 0; i < p; i++){
            u[i] = 0;
        }

        for (j = 0; j < Np; j++){

            if (C[j] != 0.0){

                const coeff_t* D0 = deltas + (uint64_t)u[0] * npts;

                for (t = 0; t < npts; t++){
                    prod[t] = C[j] * D0[t];
                }

                for (i = 1; i < p; i++){

                    const coeff_t* Di = deltas + (uint64_t)u[i] * npts;

                    for (t = 0; t < npts; t++){
                        prod[t] *= Di[t];
                    }

                }

                for (t = 0; t < npts; t++){
                    out[t] += prod[t];
                }

            }

            sshelp_next_dir(u, p, k);

        }

    }

    free(prod);

    return 0;

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// ---------------------------------------     GLOBAL LAYOUTS     ----------------------------------------
// -------------------------------------------------------------------------------------------------------

// *******************************************************************************************************
void ssoti_get_all_ims_to(const ssotinum_t* num, bases_t nbasis, ord_t order, int derivs,
                          coeff_t* out, uint64_t stride){

    bases_t k = num->nbases, u[256], g[256];
    ord_t top = (num->act_order < num->trc_order) ? num->act_order : num->trc_order, p, i;

    out[0] = num->re;

    if (order < top){
        top = order;
    }

    for (p = 1; p <= top; p++){

        ndir_t Np = sshelp_ndir_order(k, p), j;
        const coeff_t* C = num->p_im + sshelp_order_offset(k, p);
        uint64_t base = 1 + (uint64_t)sshelp_order_offset(nbasis, p);

        for (i = 0; i < p; i++){
            u[i] = 0;
        }

        for (j = 0; j < Np; j++){

            for (i = 0; i < p; i++){
                g[i] = num->p_bases[u[i]];
            }

            // The largest base is the last one; directions past nbasis are not in the layout.
            if (g[p - 1] <= nbasis){

                coeff_t val = C[j];

                if (derivs){
                    val *= ssutil_tuple_factor(u, p);
                }

                out[(base + sshelp_global_rank(g, p)) * stride] = val;

            }

            sshelp_next_dir(u, p, k);

        }

    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
bases_t ssoti_order_max_base(ord_t p, const ssotinum_t* num){

    bases_t k = num->nbases, u[256];
    ndir_t Np, j;
    const coeff_t* C;

    if (p == 0 || p > num->act_order || p > num->trc_order || k == 0){
        return 0;
    }

    Np = sshelp_ndir_order(k, p);
    C  = num->p_im + sshelp_order_offset(k, p);

    // Colex order: the last nonzero direction has the largest last (= largest) base.
    for (j = Np; j > 0; j--){

        if (C[j - 1] != 0.0){

            sshelp_unrank(j - 1, p, u);
            return num->p_bases[u[p - 1]];

        }

    }

    return 0;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void ssoti_scatter_order_im(ord_t p, const ssotinum_t* num, ndir_t width, coeff_t* out,
                            uint64_t stride){

    bases_t k = num->nbases, u[256], g[256];
    ndir_t Np, j;
    const coeff_t* C;
    ord_t i;

    if (p == 0){

        out[0] = num->re;
        return;

    }

    if (p > num->act_order || p > num->trc_order || k == 0){
        return;
    }

    Np = sshelp_ndir_order(k, p);
    C  = num->p_im + sshelp_order_offset(k, p);

    for (i = 0; i < p; i++){
        u[i] = 0;
    }

    for (j = 0; j < Np; j++){

        if (C[j] != 0.0){

            imdir_t gidx;

            for (i = 0; i < p; i++){
                g[i] = num->p_bases[u[i]];
            }

            gidx = sshelp_global_rank(g, p);

            if (gidx < width){
                out[(uint64_t)gidx * stride] = C[j];
            }

        }

        sshelp_next_dir(u, p, k);

    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void ssoti_add_order_im_global(ord_t p, const coeff_t* vals, ndir_t nvals, uint64_t stride,
                               ssotinum_t* num){

    uint8_t *mark, *nz;
    bases_t *newb, nnew = 0;
    ndir_t d;
    int any = 0;
    uint32_t b;

    if (p == 0){

        if (nvals > 0){
            num->re += vals[0];
        }

        return;

    }

    nz   = (uint8_t*)calloc((size_t)nvals + 1, 1);
    mark = (uint8_t*)calloc(65536, 1);

    if (nz == NULL || mark == NULL){
        ssoti_out_of_memory();
    }

    for (d = 0; d < nvals; d++){

        if (vals[(uint64_t)d * stride] != 0.0){

            nz[d] = 1;
            any   = 1;

        }

    }

    if (!any){

        free(nz);
        free(mark);
        return;

    }

    nnew = ssutil_mark_global_bases(p, nz, nvals, mark);
    newb = (bases_t*)malloc((size_t)nnew * sizeof(bases_t) + 1);

    if (newb == NULL){
        ssoti_out_of_memory();
    }

    nnew = 0;

    for (b = 1; b < 65536; b++){

        if (mark[b]){
            newb[nnew++] = (bases_t)b;
        }

    }

    // The sparse sum takes the larger truncation order.
    if (num->trc_order < p){
        ssoti_reserve(num, num->nbases, p);
    }

    ssoti_add_bases(newb, nnew, num);

    for (d = 0; d < nvals; d++){

        ndir_t l;

        if (nz[d] && sshelp_global_to_local((imdir_t)d, p, num->p_bases, num->nbases, &l) == 1){
            num->p_im[sshelp_order_offset(num->nbases, p) + l] += vals[(uint64_t)d * stride];
        }

    }

    if (num->act_order < p){
        num->act_order = p;
    }

    free(newb);
    free(nz);
    free(mark);

}
// -------------------------------------------------------------------------------------------------------
