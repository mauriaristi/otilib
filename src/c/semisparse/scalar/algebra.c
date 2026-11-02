// Semi-sparse scalar: kernels and algebra.


// *******************************************************************************************************
// Rank-fallback product of one order pair: res_r[rank(u_i ∪ u_j)] += A[i] * B[j].
static void ssoti_kernel_pair_rank(const coeff_t* A, ord_t p, const coeff_t* B, ord_t q,
                                   bases_t k, coeff_t* R){

    ndir_t i, j, Np = sshelp_ndir_order(k, p), Nq = sshelp_ndir_order(k, q);
    bases_t *dirs_p, *dirs_q;
    sshelp_rank_tab_t tab;
    coeff_t ai;

    dirs_p = (bases_t*)malloc((size_t)Np * p * sizeof(bases_t));
    dirs_q = (bases_t*)malloc((size_t)Nq * q * sizeof(bases_t));

    if (dirs_p == NULL || dirs_q == NULL || sshelp_rank_tab_init(&tab, k, p + q) != SSHELP_OK){
        ssoti_out_of_memory();
    }

    sshelp_local_dirs(k, p, dirs_p);
    sshelp_local_dirs(k, q, dirs_q);

    for (i = 0; i < Np; i++){

        ai = A[i];

        if (ai == 0.0){
            continue;
        }

        for (j = 0; j < Nq; j++){
            R[sshelp_prod_rank(&dirs_p[i * p], p, &dirs_q[j * q], q, &tab)] += ai * B[j];
        }

    }

    sshelp_rank_tab_free(&tab);
    free(dirs_p);
    free(dirs_q);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void ssoti_kernel_mul_acc(const coeff_t* a_im, ord_t alo, ord_t ahi,
                          const coeff_t* b_im, ord_t blo, ord_t bhi,
                          bases_t k, ord_t trc, coeff_t* res_im, dhelpl_t dhl){

    ord_t p, q;
    ndir_t i, j, Np, Nq;
    const coeff_t *A, *B;
    const imdir_t* T;
    coeff_t *R, c;
    sshelp_pair_t pair;

    if (k == 0){
        return;
    }

    for (p = alo; p <= ahi && p + blo <= trc; p++){

        Np = sshelp_ndir_order(k, p);
        A  = a_im + sshelp_order_offset(k, p);

        for (q = blo; q <= bhi && p + q <= trc; q++){

            Nq   = sshelp_ndir_order(k, q);
            B    = b_im   + sshelp_order_offset(k, q);
            R    = res_im + sshelp_order_offset(k, p + q);
            pair = sshelp_get_pair(k, p, q, dhl);

            if (pair.p_tab == NULL){

                ssoti_kernel_pair_rank(A, p, B, q, k, R);

            } else if (!pair.transpose){

                // Table rows are order-p directions.
                for (i = 0; i < Np; i++){

                    c = A[i];

                    if (c == 0.0){
                        continue;
                    }

                    T = pair.p_tab + i * pair.stride;

                    for (j = 0; j < Nq; j++){
                        R[T[j]] += c * B[j];
                    }

                }

            } else {

                // Table rows are order-q directions.
                for (j = 0; j < Nq; j++){

                    c = B[j];

                    if (c == 0.0){
                        continue;
                    }

                    T = pair.p_tab + j * pair.stride;

                    for (i = 0; i < Np; i++){
                        R[T[i]] += A[i] * c;
                    }

                }

            }

        }

    }

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void ssoti_kernel_expand(const ssotinum_t* num, const bases_t* pos, bases_t ku, ord_t trc,
                         coeff_t* dst_im){

    bases_t k = num->nbases, u[256], v[256];
    int leading = sshelp_is_leading(pos, k);
    ord_t p, i, top = (num->act_order < trc) ? num->act_order : trc;
    ndir_t j, Ns, Nd;
    const coeff_t* S;
    coeff_t* D;
    sshelp_rank_tab_t tab = {NULL, 0, 0};

    if (!leading && sshelp_rank_tab_init(&tab, ku, trc) != SSHELP_OK){
        ssoti_out_of_memory();
    }

    for (p = 1; p <= trc; p++){

        Nd = sshelp_ndir_order(ku, p);
        D  = dst_im + sshelp_order_offset(ku, p);

        if (p > top || k == 0){

            memset(D, 0, Nd * sizeof(coeff_t));
            continue;

        }

        Ns = sshelp_ndir_order(k, p);
        S  = num->p_im + sshelp_order_offset(k, p);

        if (leading){

            // Colex prefix: the source block is the first Ns destination directions.
            memcpy(D, S, Ns * sizeof(coeff_t));
            memset(D + Ns, 0, (Nd - Ns) * sizeof(coeff_t));

        } else {

            memset(D, 0, Nd * sizeof(coeff_t));

            for (i = 0; i < p; i++){
                u[i] = 0;
            }

            for (j = 0; j < Ns; j++){

                for (i = 0; i < p; i++){
                    v[i] = pos[u[i]];
                }

                D[sshelp_rank(v, p, &tab)] = S[j];
                sshelp_next_dir(u, p, k);

            }

        }

    }

    sshelp_rank_tab_free(&tab);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Operands of a binary operation in the layout of the union of their sets.
typedef struct {
    const coeff_t* p_a; ///< First operand, union layout (may be the operand's own buffer).
    const coeff_t* p_b; ///< Second operand, union layout.
    coeff_t*       p_r; ///< Result scratch, union layout, zeroed.
    const bases_t* p_u; ///< Union of the sets.
    bases_t         nu; ///< Size of the union.
    ord_t          trc; ///< Truncation order of the result.
    ndir_t       nimag; ///< Imaginary coefficients of the result.
} ssoti_binop_t;
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Builds the union layout of two operands in the calling thread's workspace.
static ssoti_binop_t ssoti_binop_prepare(const ssotinum_t* a, const ssotinum_t* b){

    sshelp_ws_t* ws = ssoti_ws();
    ssoti_binop_t op;
    size_t nb = (size_t)a->nbases + b->nbases;
    bases_t *p_u, *pos_a, *pos_b;
    coeff_t *p_ea, *p_eb;
    int own_a, own_b;

    op.trc = (a->trc_order > b->trc_order) ? a->trc_order : b->trc_order;

    ssoti_ws_need(ws, 0, 0, 2 * nb + 1);
    p_u   = ws->p_bases;
    pos_a = ws->p_bases + nb;
    pos_b = pos_a + a->nbases;

    op.nu    = sshelp_union_bases(a->p_bases, a->nbases, b->p_bases, b->nbases, p_u, pos_a, pos_b);
    op.nimag = ssoti_nimag_checked(op.nu, op.trc);
    op.p_u   = p_u;

    // An operand whose set is the union and whose buffer holds every order of the result is used
    // in place (offsets do not depend on trc); otherwise it is expanded, with zeros above its
    // own truncation order.
    own_a = (a->nbases == op.nu && a->trc_order >= op.trc);
    own_b = (b->nbases == op.nu && b->trc_order >= op.trc);

    ssoti_ws_need(ws, (size_t)op.nimag * (1 + !own_a + !own_b), 0, 0);

    op.p_r = ws->p_coef;
    p_ea   = op.p_r + op.nimag;
    p_eb   = p_ea + (own_a ? 0 : op.nimag);

    memset(op.p_r, 0, op.nimag * sizeof(coeff_t));

    if (own_a){
        op.p_a = a->p_im;
    } else {
        ssoti_kernel_expand(a, pos_a, op.nu, op.trc, p_ea);
        op.p_a = p_ea;
    }

    if (own_b){
        op.p_b = b->p_im;
    } else {
        ssoti_kernel_expand(b, pos_b, op.nu, op.trc, p_eb);
        op.p_b = p_eb;
    }

    return op;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// Stores the result scratch of a binary operation into res.
static void ssoti_binop_store(const ssoti_binop_t* op, coeff_t re, ord_t act, ssotinum_t* res){

    ssoti_reserve(res, op->nu, op->trc);

    if (op->nu > 0){

        memcpy(res->p_bases, op->p_u, (size_t)op->nu * sizeof(bases_t));
        memcpy(res->p_im, op->p_r, op->nimag * sizeof(coeff_t));

    }

    res->re        = re;
    res->nbases    = op->nu;
    res->trc_order = op->trc;
    res->act_order = (act < op->trc) ? act : op->trc;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// res = sa * a + sb * b (sums and subtractions).
static void ssoti_axpby_to(coeff_t sa, const ssotinum_t* a, coeff_t sb, const ssotinum_t* b,
                           ssotinum_t* res){

    ssoti_binop_t op = ssoti_binop_prepare(a, b);
    ndir_t i;

    for (i = 0; i < op.nimag; i++){
        op.p_r[i] = sa * op.p_a[i] + sb * op.p_b[i];
    }

    ssoti_binop_store(&op, sa * a->re + sb * b->re,
        (a->act_order > b->act_order) ? a->act_order : b->act_order, res);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
// res = a * b.
static void ssoti_mul_to(const ssotinum_t* a, const ssotinum_t* b, ssotinum_t* res, dhelpl_t dhl){

    ssoti_binop_t op = ssoti_binop_prepare(a, b);
    ord_t atop = (a->act_order < op.trc) ? a->act_order : op.trc;
    ord_t btop = (b->act_order < op.trc) ? b->act_order : op.trc;
    ndir_t i;

    // Real x imaginary.
    for (i = 0; i < op.nimag; i++){
        op.p_r[i] = a->re * op.p_b[i] + b->re * op.p_a[i];
    }

    // Imaginary x imaginary.
    if (atop > 0 && btop > 0){
        ssoti_kernel_mul_acc(op.p_a, 1, atop, op.p_b, 1, btop, op.nu, op.trc, op.p_r, dhl);
    }

    ssoti_binop_store(&op, a->re * b->re, (ord_t)((unsigned)atop + btop > 255 ? 255 : atop + btop),
        res);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
ssotinum_t ssoti_sum_oo(const ssotinum_t* num1, const ssotinum_t* num2, dhelpl_t dhl){

    ssotinum_t res = ssoti_init();

    ssoti_sum_oo_to(num1, num2, &res, dhl);

    return res;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
ssotinum_t ssoti_sum_or(const ssotinum_t* num1, coeff_t val, dhelpl_t dhl){

    ssotinum_t res = ssoti_init();

    ssoti_sum_or_to(num1, val, &res, dhl);

    return res;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void ssoti_sum_oo_to(const ssotinum_t* num1, const ssotinum_t* num2, ssotinum_t* res,
                     dhelpl_t dhl){

    (void)dhl;
    ssoti_axpby_to(1.0, num1, 1.0, num2, res);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void ssoti_sum_or_to(const ssotinum_t* num1, coeff_t val, ssotinum_t* res, dhelpl_t dhl){

    (void)dhl;
    ssoti_copy_to(num1, res);
    res->re += val;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
ssotinum_t ssoti_sub_oo(const ssotinum_t* num1, const ssotinum_t* num2, dhelpl_t dhl){

    ssotinum_t res = ssoti_init();

    ssoti_sub_oo_to(num1, num2, &res, dhl);

    return res;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
ssotinum_t ssoti_sub_or(const ssotinum_t* num1, coeff_t val, dhelpl_t dhl){

    ssotinum_t res = ssoti_init();

    ssoti_sub_or_to(num1, val, &res, dhl);

    return res;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
ssotinum_t ssoti_sub_ro(coeff_t val, const ssotinum_t* num1, dhelpl_t dhl){

    ssotinum_t res = ssoti_init();

    ssoti_sub_ro_to(val, num1, &res, dhl);

    return res;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void ssoti_sub_oo_to(const ssotinum_t* num1, const ssotinum_t* num2, ssotinum_t* res,
                     dhelpl_t dhl){

    (void)dhl;
    ssoti_axpby_to(1.0, num1, -1.0, num2, res);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void ssoti_sub_or_to(const ssotinum_t* num1, coeff_t val, ssotinum_t* res, dhelpl_t dhl){

    (void)dhl;
    ssoti_copy_to(num1, res);
    res->re -= val;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void ssoti_sub_ro_to(coeff_t val, const ssotinum_t* num1, ssotinum_t* res, dhelpl_t dhl){

    ssoti_neg_to(num1, res, dhl);
    res->re += val;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
ssotinum_t ssoti_neg(const ssotinum_t* num, dhelpl_t dhl){

    ssotinum_t res = ssoti_init();

    ssoti_neg_to(num, &res, dhl);

    return res;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void ssoti_neg_to(const ssotinum_t* num, ssotinum_t* res, dhelpl_t dhl){

    ssoti_mul_or_to(num, -1.0, res, dhl);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
ssotinum_t ssoti_mul_oo(const ssotinum_t* num1, const ssotinum_t* num2, dhelpl_t dhl){

    ssotinum_t res = ssoti_init();

    ssoti_mul_oo_to(num1, num2, &res, dhl);

    return res;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
ssotinum_t ssoti_mul_or(const ssotinum_t* num1, coeff_t val, dhelpl_t dhl){

    ssotinum_t res = ssoti_init();

    ssoti_mul_or_to(num1, val, &res, dhl);

    return res;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void ssoti_mul_oo_to(const ssotinum_t* num1, const ssotinum_t* num2, ssotinum_t* res,
                     dhelpl_t dhl){

    ssoti_mul_to(num1, num2, res, dhl);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void ssoti_mul_or_to(const ssotinum_t* num1, coeff_t val, ssotinum_t* res, dhelpl_t dhl){

    ndir_t i, nimag;

    (void)dhl;
    ssoti_copy_to(num1, res);

    nimag = sshelp_ndir_total(res->nbases, res->trc_order);

    for (i = 0; i < nimag; i++){
        res->p_im[i] *= val;
    }

    res->re *= val;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void ssoti_gem_oo_to(const ssotinum_t* num1, const ssotinum_t* num2, const ssotinum_t* num3,
                     ssotinum_t* res, dhelpl_t dhl){

    ssotinum_t prod = ssoti_init();

    // The product goes to scratch first, so res may alias any input.
    ssoti_mul_oo_to(num1, num2, &prod, dhl);
    ssoti_sum_oo_to(&prod, num3, res, dhl);
    ssoti_free(&prod);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
ssotinum_t ssoti_div_oo(const ssotinum_t* num, const ssotinum_t* den, dhelpl_t dhl){

    ssotinum_t res = ssoti_init();

    ssoti_div_oo_to(num, den, &res, dhl);

    return res;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
ssotinum_t ssoti_div_ro(coeff_t val, const ssotinum_t* den, dhelpl_t dhl){

    ssotinum_t res = ssoti_init();

    ssoti_div_ro_to(val, den, &res, dhl);

    return res;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
ssotinum_t ssoti_div_or(const ssotinum_t* num, coeff_t val, dhelpl_t dhl){

    ssotinum_t res = ssoti_init();

    ssoti_div_or_to(num, val, &res, dhl);

    return res;

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void ssoti_div_oo_to(const ssotinum_t* num, const ssotinum_t* den, ssotinum_t* res,
                     dhelpl_t dhl){

    ssotinum_t inv = ssoti_init();

    ssoti_pow_to(den, -1.0, &inv, dhl);
    ssoti_mul_oo_to(num, &inv, res, dhl);
    ssoti_free(&inv);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void ssoti_div_ro_to(coeff_t val, const ssotinum_t* den, ssotinum_t* res, dhelpl_t dhl){

    ssoti_pow_to(den, -1.0, res, dhl);
    ssoti_mul_or_to(res, val, res, dhl);

}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void ssoti_div_or_to(const ssotinum_t* num, coeff_t val, ssotinum_t* res, dhelpl_t dhl){

    ssoti_mul_or_to(num, 1.0 / val, res, dhl);

}
// -------------------------------------------------------------------------------------------------------
