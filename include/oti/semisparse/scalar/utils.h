#ifndef OTI_SEMISPARSE_SCALAR_UTILS_H
#define OTI_SEMISPARSE_SCALAR_UTILS_H

// Semi-sparse scalars: order and derivative extraction, truncated products, rom_eval (PLAN-semisparse-
// sparse-leveling.md, Phase 2).
//
// Conventions shared with the SoA versions (include/oti/semisparse/soa/utils.h):
//   - directions given as (idx, order) are GLOBAL, same numbering as sotinum_t;
//   - "global layout" arrays (get_all_ims, get_order_im_array) index an order-p direction by its
//     global index, which for bases 1..n is below N_p(n) = C(n+p-1, p) (the prefix property);
//   - the derivative factor of a direction is the product of the factorials of its base
//     multiplicities, as dhelp_get_deriv_factor() computes it.


// -------------------------------------------------------------------------------------------------------
// ----------------------------------------     INLINE HELPERS     ---------------------------------------
// -------------------------------------------------------------------------------------------------------

/**
 * @brief Derivative factor of a sorted tuple: product of the factorials of its multiplicities.
 *
 * @param[in] u Sorted tuple (local or global bases), length @p p.
 * @param[in] p Order.
 *
 * @return prod_b m_b!, where m_b is the number of times base b occurs in @p u. 1 for p = 0.
 */
static inline coeff_t ssutil_tuple_factor(const bases_t* u, ord_t p){

    coeff_t factor = 1.0;
    coeff_t run = 1.0;
    ord_t i;

    for (i = 1; i < p; i++){

        if (u[i] == u[i - 1]){

            run += 1.0;
            factor *= run;

        } else {

            run = 1.0;

        }

    }

    return factor;

}
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Merges two sorted tuples into one sorted tuple.
 *
 * @param[in]  a  First tuple, length @p p.
 * @param[in]  p  Length of @p a.
 * @param[in]  b  Second tuple, length @p q.
 * @param[in]  q  Length of @p b.
 * @param[out] out Merged tuple, length p + q. Must not alias @p a or @p b.
 */
static inline void ssutil_merge_tuples(const bases_t* a, ord_t p, const bases_t* b, ord_t q,
                                       bases_t* out){

    ord_t i = 0, j = 0, n = 0;

    while (i < p || j < q){

        if (j == q || (i < p && a[i] <= b[j])){
            out[n++] = a[i++];
        } else {
            out[n++] = b[j++];
        }

    }

}
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Binary search of a global base label in a sorted active-base list.
 *
 * @param[in]  label Global base label.
 * @param[in]  bases Sorted active bases, length @p k.
 * @param[in]  k     Number of active bases.
 * @param[out] out   Local position of @p label when found.
 *
 * @return 1 when found, 0 otherwise.
 */
static inline int ssutil_base_search(bases_t label, const bases_t* bases, bases_t k, bases_t* out){

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


// -------------------------------------------------------------------------------------------------------
// ----------------------------------------     DECLARATIONS     -----------------------------------------
// -------------------------------------------------------------------------------------------------------

/**
 * @brief Maps a global direction onto a number's active set.
 *
 * @param[in]  idx   Global direction index.
 * @param[in]  order Direction order, 1 <= order <= 255.
 * @param[in]  bases Sorted active bases, length @p k.
 * @param[in]  k     Number of active bases.
 * @param[out] u     Local tuple of the direction (sorted), length @p order.
 *
 * @return 1 when every base of the direction is active (then @p u is set), 0 otherwise.
 */
int ssutil_global_to_tuple(imdir_t idx, ord_t order, const bases_t* bases, bases_t k, bases_t* u);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Adds @p alpha times one order of a coefficient layout into another active set's layout.
 *
 * The source holds the order-@p p directions over @p k bases as consecutive runs of @p m reals
 * (one run per direction, local index order). Each run is added, scaled by @p alpha, to the run
 * of the same direction in the destination, which holds the order-@p p directions over @p ku bases.
 * pos[u] is the destination position of source base u (from sshelp_union_bases()). When the
 * source set is a leading part of the destination set the runs keep their offsets (no index work).
 *
 * @param[in]     src   Source runs, N_p(k) * m reals.
 * @param[in]     k     Number of source bases.
 * @param[in]     pos   Destination position of each source base, length @p k.
 * @param[in]     ku    Number of destination bases.
 * @param[in]     p     Order, p >= 1.
 * @param[in]     m     Reals per direction run.
 * @param[in]     alpha Scale factor.
 * @param[in,out] dst   Destination runs, N_p(ku) * m reals.
 */
void ssutil_expand_order_acc(const coeff_t* src, bases_t k, const bases_t* pos, bases_t ku, ord_t p,
                             uint64_t m, coeff_t alpha, coeff_t* dst);
// -------------------------------------------------------------------------------------------------------


/**
 * @name Semi-sparse imaginary-direction extraction
 * Returns the number formed by the coefficients of every direction that contains the given
 * direction, divided by it (same result as soti_extract_im()): coefficient d / g of the result is
 * coefficient d of the input. The result keeps the active set; its truncation order is
 * trc_order - order and its real part is the coefficient of the direction. Order 0 copies the
 * number; a direction of order above act_order, or with an inactive base, gives zero.
 * @{
 */

/**
 * @brief Extracts the coefficients that contain a direction (allocating variant).
 *
 * @param[in] idx   Global direction index.
 * @param[in] order Direction order.
 * @param[in] num   Number.
 *
 * @return Newly allocated result. Caller must free via ssoti_free().
 */
ssotinum_t ssoti_extract_im(imdir_t idx, ord_t order, const ssotinum_t* num);

/**
 * @brief Extracts the coefficients that contain a direction into an existing number.
 *
 * @param[in]     idx   Global direction index.
 * @param[in]     order Direction order.
 * @param[in]     num   Number.
 * @param[in,out] res   Result; may alias @p num.
 */
void ssoti_extract_im_to(imdir_t idx, ord_t order, const ssotinum_t* num, ssotinum_t* res);

/** @} */
// -------------------------------------------------------------------------------------------------------


/**
 * @name Semi-sparse derivative extraction
 * Like ssoti_extract_im(), with the coefficients scaled so that the result holds derivatives (same
 * result as soti_extract_deriv()): coefficient d / g of the result is coefficient d of the input
 * times factor(d) / factor(d / g), and the real part is the derivative along the direction.
 * @{
 */

/**
 * @brief Extracts the derivatives that contain a direction (allocating variant).
 *
 * @param[in] idx   Global direction index.
 * @param[in] order Direction order.
 * @param[in] num   Number.
 *
 * @return Newly allocated result. Caller must free via ssoti_free().
 */
ssotinum_t ssoti_extract_deriv(imdir_t idx, ord_t order, const ssotinum_t* num);

/**
 * @brief Extracts the derivatives that contain a direction into an existing number.
 *
 * @param[in]     idx   Global direction index.
 * @param[in]     order Direction order.
 * @param[in]     num   Number.
 * @param[in,out] res   Result; may alias @p num.
 */
void ssoti_extract_deriv_to(imdir_t idx, ord_t order, const ssotinum_t* num, ssotinum_t* res);

/** @} */
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Truncated subtraction: keeps only the order-@p order part of num1 - num2.
 *
 * Same result as soti_trunc_sub_oo_to(): the result is over the union of the active sets with the
 * larger truncation order, and every order other than @p order (the real part included, unless
 * @p order is 0) is zero.
 *
 * @param[in]     order Order to keep.
 * @param[in]     num1  First operand.
 * @param[in]     num2  Second operand.
 * @param[in,out] res   Result; may alias either operand.
 */
void ssoti_trunc_sub_to(ord_t order, const ssotinum_t* num1, const ssotinum_t* num2,
                        ssotinum_t* res);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Evaluates the Taylor polynomial of a number at a perturbation of its active bases.
 *
 * Returns re + sum_d c_d prod_{u in d} delta[u], the value soti_taylor_integrate() computes, with
 * one delta per active base (local order).
 *
 * @param[in] num    Number.
 * @param[in] deltas Perturbation of each active base, length num->nbases. May be NULL when
 *                   num->nbases is 0.
 *
 * @return Value of the polynomial.
 */
coeff_t ssoti_rom_eval(const ssotinum_t* num, const coeff_t* deltas);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Evaluates the Taylor polynomial of a number at many perturbations at once.
 *
 * out[t] = re + sum_d c_d prod_{u in d} deltas[u * npts + t], for t < @p npts.
 *
 * @param[in]  num    Number.
 * @param[in]  deltas Perturbations, num->nbases rows of @p npts reals (row u = local base u).
 * @param[in]  npts   Number of evaluation points.
 * @param[out] out    Values, length @p npts.
 *
 * @return 0, or OTI_OutOfMemory when the scratch row cannot be allocated.
 */
int ssoti_rom_eval_points(const ssotinum_t* num, const coeff_t* deltas, uint64_t npts,
                          coeff_t* out);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Writes a number's coefficients (or derivatives) in the global layout of (nbasis, order).
 *
 * out[d * stride] receives the coefficient of global position d: d = 0 is the real part and the
 * order-p direction with global index g sits at 1 + (C(nbasis+p-1, p-1) - 1) + g, the ordering of
 * matso.get_all_ims(). Directions of order above @p order or using a base above @p nbasis are
 * skipped; other positions are left untouched (the caller zeroes @p out).
 *
 * @param[in]     num    Number.
 * @param[in]     nbasis Number of global bases of the layout.
 * @param[in]     order  Highest order of the layout.
 * @param[in]     derivs Nonzero to write derivatives (coefficient times derivative factor).
 * @param[in,out] out    Layout, C(nbasis+order, order) positions spaced by @p stride.
 * @param[in]     stride Distance between consecutive positions, in reals.
 */
void ssoti_get_all_ims_to(const ssotinum_t* num, bases_t nbasis, ord_t order, int derivs,
                          coeff_t* out, uint64_t stride);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Largest global base used by a nonzero order-@p p coefficient.
 *
 * @param[in] p   Order, p >= 1.
 * @param[in] num Number.
 *
 * @return The base label, or 0 when every order-@p p coefficient is zero.
 */
bases_t ssoti_order_max_base(ord_t p, const ssotinum_t* num);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Writes the order-@p p coefficients of a number at their global indices.
 *
 * out[g * stride] = coefficient of the order-p direction with global index g, for every nonzero
 * coefficient with g < @p width; other positions are left untouched. Order 0 writes the real part
 * at out[0].
 *
 * @param[in]     p      Order.
 * @param[in]     num    Number.
 * @param[in]     width  Number of global positions of @p out.
 * @param[in,out] out    Global positions.
 * @param[in]     stride Distance between consecutive positions, in reals.
 */
void ssoti_scatter_order_im(ord_t p, const ssotinum_t* num, ndir_t width, coeff_t* out,
                            uint64_t stride);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Adds order-@p p coefficients given at their global indices to a number.
 *
 * num += sum_g vals[g * stride] e(g, p) for g < @p nvals. The active set grows by the bases of every
 * nonzero value, and the truncation order is raised to @p p when lower (the sparse sum
 * `num + sotinum` of set_order_im_from_array()). Order 0 adds vals[0] to the real part.
 *
 * @param[in]     p      Order.
 * @param[in]     vals   Values at global indices.
 * @param[in]     nvals  Number of values.
 * @param[in]     stride Distance between consecutive values, in reals.
 * @param[in,out] num    Number.
 */
void ssoti_add_order_im_global(ord_t p, const coeff_t* vals, ndir_t nvals, uint64_t stride,
                               ssotinum_t* num);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Marks the bases of the order-@p p global directions with a nonzero flag.
 *
 * For each g < @p nvals with nz[g] != 0, unranks the global direction (g, p) and sets
 * mark[b] = 1 for each of its bases b (mark has 65536 entries).
 *
 * @param[in]     p     Order, p >= 1.
 * @param[in]     nz    Nonzero flags, length @p nvals.
 * @param[in]     nvals Number of global directions.
 * @param[in,out] mark  Base marks, 65536 entries.
 *
 * @return Number of distinct bases marked by this call.
 */
bases_t ssutil_mark_global_bases(ord_t p, const uint8_t* nz, ndir_t nvals, uint8_t* mark);
// -------------------------------------------------------------------------------------------------------

#endif
