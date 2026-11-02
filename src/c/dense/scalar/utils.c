// Dense scalars: order and derivative extraction, truncated subtraction, rom_eval, global layouts
// (include/oti/dense/scalar/utils.h).
//
// Unity-included from src/c/dense.c: static helpers here carry the dnsu_ prefix. Global layouts need no
// ranking: the order-p directions over bases 1..n are the global indices 0 .. N_p(n)-1.


// *******************************************************************************************************
// Installs a call-local result into res, releasing res's old buffer.
static void dnsu_install(otinum_t* tmp, otinum_t* res){

    free(res->p_im);
    *res = *tmp;
    *tmp = oti_init();

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// ---------------------------------------     EXTRACTION     --------------------------------------------
// -------------------------------------------------------------------------------------------------------

// *******************************************************************************************************
// Shared body of oti_extract_im_to() and oti_extract_deriv_to().
static int dnsu_extract_common(imdir_t idx, ord_t order, const otinum_t* num, int deriv,
                               otinum_t* res){

    bases_t k = num->nact, gl[256], r[256], d[256];
    ord_t trc_r, act_r, s;
    ndir_t Ns, j, off_src, off_dst;
    otinum_t tmp = oti_init();
    sshelp_rank_tab_t tab;
    coeff_t fg, val;
    int status;

    if (order == 0){
        return oti_copy_to(num, res);
    }

    // Order above trc: a real zero with truncation order 0.
    if (order > num->trc_order){

        status = oti_create_empty_to(0, 0, res);

        return status;

    }

    trc_r = (ord_t)(num->trc_order - order);

    // A direction above act_order, or with a base above nact, gives zero (in the layout (nact, trc_r)).
    if (order > num->act_order || !dnutil_dir_inside(idx, order, k)){

        status = oti_create_empty_to(k, trc_r, &tmp);

        if (status == DN_OK){
            dnsu_install(&tmp, res);
        }

        oti_free(&tmp);

        return status;

    }

    act_r  = (ord_t)(num->act_order - order);
    status = oti_create_empty_to(k, trc_r, &tmp);

    if (status != DN_OK){
        return status;
    }

    if (sshelp_rank_tab_init(&tab, k, num->trc_order) != SSHELP_OK){

        oti_free(&tmp);
        return DN_ERR_MEMORY;

    }

    sshelp_unrank((ndir_t)idx, order, gl);
    fg = deriv ? dnutil_tuple_factor(gl, order) : 1.0;

    tmp.re = num->p_im[sshelp_order_offset(k, order) + idx] * fg;

    // Every quotient direction r of order s maps to the input direction r * g of order s + order.
    for (s = 1; s <= act_r; s++){

        Ns      = sshelp_ndir_order(k, s);
        off_src = sshelp_order_offset(k, (ord_t)(s + order));
        off_dst = sshelp_order_offset(k, s);

        memset(r, 0, (size_t)s * sizeof(bases_t));

        for (j = 0; j < Ns; j++){

            dnutil_merge_tuples(r, s, gl, order, d);
            val = num->p_im[off_src + sshelp_rank(d, (ord_t)(s + order), &tab)];

            if (deriv && val != 0.0){
                val *= dnutil_tuple_factor(d, (ord_t)(s + order)) / dnutil_tuple_factor(r, s);
            }

            tmp.p_im[off_dst + j] = val;
            sshelp_next_dir(r, s, k);

        }

    }

    sshelp_rank_tab_free(&tab);

    tmp.act_order = (k == 0) ? 0 : act_r;
    dnsu_install(&tmp, res);

    return DN_OK;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
otinum_t oti_extract_im(imdir_t idx, ord_t order, const otinum_t* num){

    otinum_t res = oti_init();

    return dnsm_ret(dnsu_extract_common(idx, order, num, 0, &res), &res);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oti_extract_im_to(imdir_t idx, ord_t order, const otinum_t* num, otinum_t* res){

    return dnsu_extract_common(idx, order, num, 0, res);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
otinum_t oti_extract_deriv(imdir_t idx, ord_t order, const otinum_t* num){

    otinum_t res = oti_init();

    return dnsm_ret(dnsu_extract_common(idx, order, num, 1, &res), &res);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oti_extract_deriv_to(imdir_t idx, ord_t order, const otinum_t* num, otinum_t* res){

    return dnsu_extract_common(idx, order, num, 1, res);

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// ---------------------------------------     TRUNCATED ALGEBRA     -------------------------------------
// -------------------------------------------------------------------------------------------------------

// *******************************************************************************************************
int oti_trunc_sub_to(ord_t order, const otinum_t* num1, const otinum_t* num2, otinum_t* res){

    bases_t k = (num1->nact > num2->nact) ? num1->nact : num2->nact;
    ord_t trc = (num1->trc_order > num2->trc_order) ? num1->trc_order : num2->trc_order;
    otinum_t tmp = oti_init();
    otinum_t* dst = (res == num1 || res == num2) ? &tmp : res;
    coeff_t* D;
    const coeff_t* S;
    ndir_t i, n;
    int status = oti_create_empty_to(k, trc, dst);

    if (status != DN_OK){
        return status;
    }

    if (order == 0){

        dst->re = num1->re - num2->re;

    } else if (order <= trc && k > 0){

        D = dst->p_im + sshelp_order_offset(k, order);

        if (order <= num1->act_order && num1->nact > 0){

            n = sshelp_ndir_order(num1->nact, order);
            S = num1->p_im + sshelp_order_offset(num1->nact, order);

            for (i = 0; i < n; i++){
                D[i] += S[i];
            }

        }

        if (order <= num2->act_order && num2->nact > 0){

            n = sshelp_ndir_order(num2->nact, order);
            S = num2->p_im + sshelp_order_offset(num2->nact, order);

            for (i = 0; i < n; i++){
                D[i] -= S[i];
            }

        }

        dst->act_order = order;

    }

    if (dst == &tmp){
        dnsu_install(&tmp, res);
    }

    return DN_OK;

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// ---------------------------------------     ROM EVALUATION     ----------------------------------------
// -------------------------------------------------------------------------------------------------------

// *******************************************************************************************************
coeff_t oti_rom_eval(const otinum_t* num, const coeff_t* deltas){

    bases_t k = num->nact, u[256];
    ord_t top = (k == 0) ? 0 : num->act_order, p, i;
    ndir_t Np, j;
    const coeff_t* C;
    coeff_t prod, val = num->re;

    for (p = 1; p <= top; p++){

        Np = sshelp_ndir_order(k, p);
        C  = num->p_im + sshelp_order_offset(k, p);

        memset(u, 0, (size_t)p * sizeof(bases_t));

        for (j = 0; j < Np; j++){

            prod = C[j];

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
int oti_rom_eval_points(const otinum_t* num, const coeff_t* deltas, uint64_t npts, coeff_t* out){

    bases_t k = num->nact, u[256];
    ord_t top = (k == 0) ? 0 : num->act_order, p, i;
    ndir_t Np, j;
    const coeff_t *C, *Di;
    coeff_t* prod;
    uint64_t t;

    for (t = 0; t < npts; t++){
        out[t] = num->re;
    }

    if (top == 0 || npts == 0){
        return DN_OK;
    }

    if (npts > SIZE_MAX / sizeof(coeff_t)){
        return DN_ERR_MEMORY;
    }

    prod = (coeff_t*)malloc((size_t)npts * sizeof(coeff_t));

    if (prod == NULL){
        return DN_ERR_MEMORY;
    }

    for (p = 1; p <= top; p++){

        Np = sshelp_ndir_order(k, p);
        C  = num->p_im + sshelp_order_offset(k, p);

        memset(u, 0, (size_t)p * sizeof(bases_t));

        for (j = 0; j < Np; j++){

            if (C[j] != 0.0){

                Di = deltas + (uint64_t)u[0] * npts;

                for (t = 0; t < npts; t++){
                    prod[t] = C[j] * Di[t];
                }

                for (i = 1; i < p; i++){

                    Di = deltas + (uint64_t)u[i] * npts;

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

    return DN_OK;

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// ---------------------------------------     GLOBAL LAYOUTS     ----------------------------------------
// -------------------------------------------------------------------------------------------------------

// *******************************************************************************************************
void oti_get_all_ims_to(const otinum_t* num, bases_t nbasis, ord_t order, int derivs,
                        coeff_t* out, uint64_t stride){

    bases_t k = (num->nact < nbasis) ? num->nact : nbasis, u[256];
    ord_t top = (num->nact == 0) ? 0 : num->act_order, p;
    ndir_t Np, j;
    const coeff_t* C;
    uint64_t base;

    out[0] = num->re;

    if (order < top){
        top = order;
    }

    // Directions past nbasis are the indices from N_p(nbasis) on: only the first N_p(k) are written.
    for (p = 1; p <= top && k > 0; p++){

        Np   = sshelp_ndir_order(k, p);
        C    = num->p_im + sshelp_order_offset(num->nact, p);
        base = 1 + (uint64_t)sshelp_order_offset(nbasis, p);

        if (!derivs){

            for (j = 0; j < Np; j++){
                out[(base + j) * stride] = C[j];
            }

            continue;

        }

        memset(u, 0, (size_t)p * sizeof(bases_t));

        for (j = 0; j < Np; j++){

            out[(base + j) * stride] = (C[j] == 0.0) ? 0.0 : C[j] * dnutil_tuple_factor(u, p);
            sshelp_next_dir(u, p, k);

        }

    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
bases_t oti_order_max_base(ord_t p, const otinum_t* num){

    bases_t k = num->nact;
    ndir_t Np, j;
    const coeff_t* C;

    if (p == 0 || p > num->act_order || k == 0){
        return 0;
    }

    Np = sshelp_ndir_order(k, p);
    C  = num->p_im + sshelp_order_offset(k, p);

    // Colex order: the last nonzero direction has the largest base.
    for (j = Np; j > 0; j--){

        if (C[j - 1] != 0.0){
            return dnsb_max_base(j - 1, p);
        }

    }

    return 0;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void oti_scatter_order_im(ord_t p, const otinum_t* num, ndir_t width, coeff_t* out,
                          uint64_t stride){

    ndir_t Np, j;
    const coeff_t* C;

    if (p == 0){

        out[0] = num->re;
        return;

    }

    if (p > num->act_order || num->nact == 0){
        return;
    }

    Np = sshelp_ndir_order(num->nact, p);
    C  = num->p_im + sshelp_order_offset(num->nact, p);

    if (Np > width){
        Np = width;
    }

    for (j = 0; j < Np; j++){

        if (C[j] != 0.0){
            out[(uint64_t)j * stride] = C[j];
        }

    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int oti_add_order_im_global(ord_t p, const coeff_t* vals, ndir_t nvals, uint64_t stride,
                            otinum_t* num){

    bases_t g[256], k;
    ndir_t d, dmax = 0, off;
    int any = 0, status;
    coeff_t* D;

    if (p == 0){

        if (nvals > 0){
            num->re += vals[0];
        }

        return DN_OK;

    }

    for (d = nvals; d > 0; d--){

        if (vals[(uint64_t)(d - 1) * stride] != 0.0){

            dmax = d - 1;
            any  = 1;
            break;

        }

    }

    if (!any){
        return DN_OK;
    }

    // The largest nonzero index has the largest base (colex order).
    if (sshelp_global_unrank((imdir_t)dmax, p, g) != SSHELP_OK){
        return DN_ERR_INDEX;
    }

    k = (g[p - 1] > num->nact) ? g[p - 1] : num->nact;

    // The sparse sum takes the larger truncation order.
    status = dnsa_grow(num, k, (p > num->trc_order) ? p : num->trc_order);

    if (status != DN_OK){
        return status;
    }

    off = sshelp_order_offset(k, p);
    D   = num->p_im + off;

    for (d = 0; d <= dmax; d++){
        D[d] += vals[(uint64_t)d * stride];
    }

    if (num->act_order < p){
        num->act_order = p;
    }

    return DN_OK;

}
// -------------------------------------------------------------------------------------------------------
