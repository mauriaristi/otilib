#ifndef OTI_DENSE_SCALAR_UTILS_H
#define OTI_DENSE_SCALAR_UTILS_H

// Dense scalars: order and derivative extraction, truncated products, rom_eval.
//
// Conventions shared with the SoA versions (include/oti/dense/soa/utils.h):
//   - directions given as (idx, order) are GLOBAL, same numbering as sotinum_t; for a dense number
//     over bases 1..nact they are also its own indices (prefix property);
//   - "global layout" arrays (get_all_ims, get_order_im_array) index an order-p direction by its
//     global index, which for bases 1..n is below N_p(n) = C(n+p-1, p);
//   - the derivative factor of a direction is the product of the factorials of its base
//     multiplicities, as dhelp_get_deriv_factor() computes it.


// -------------------------------------------------------------------------------------------------------
// ----------------------------------------     INLINE HELPERS     ---------------------------------------
// -------------------------------------------------------------------------------------------------------

/**
 * @brief Derivative factor of a sorted tuple: product of the factorials of its multiplicities.
 *
 * @param[in] u Sorted tuple of bases (0- or 1-based), length @p p.
 * @param[in] p Order.
 *
 * @return prod_b m_b!, where m_b is the number of times base b occurs in @p u. 1 for p = 0.
 */
static inline coeff_t dnutil_tuple_factor(const bases_t* u, ord_t p){

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
 * @param[in]  a   First tuple, length @p p.
 * @param[in]  p   Length of @p a.
 * @param[in]  b   Second tuple, length @p q.
 * @param[in]  q   Length of @p b.
 * @param[out] out Merged tuple, length p + q. Must not alias @p a or @p b.
 */
static inline void dnutil_merge_tuples(const bases_t* a, ord_t p, const bases_t* b, ord_t q,
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
 * @brief Tells whether a global direction lies inside a dense layout over bases 1..nact.
 *
 * By the prefix property this is idx < N_order(nact); no unranking is needed.
 *
 * @param[in] idx   Global direction index within @p order.
 * @param[in] order Direction order (0 is always inside).
 * @param[in] nact  Number of active bases.
 *
 * @return 1 when every base of the direction is <= nact, else 0.
 */
static inline int dnutil_dir_inside(imdir_t idx, ord_t order, bases_t nact){

    return order == 0 ? idx == 0 : (ndir_t)idx < sshelp_ndir_order(nact, order);

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// ----------------------------------------     DECLARATIONS     -----------------------------------------
// -------------------------------------------------------------------------------------------------------

/**
 * @name Dense imaginary-direction extraction
 * Returns the number formed by the coefficients of every direction that contains the given
 * direction, divided by it (same result as soti_extract_im()): coefficient d / g of the result is
 * coefficient d of the input. The result keeps nact; its truncation order is trc_order - order and
 * its real part is the coefficient of the direction. Order 0 copies the number; a direction of order
 * above act_order, or with a base above nact, gives zero; order > trc_order gives a real zero with
 * truncation order 0.
 * @{
 */

/**
 * @brief Extracts the coefficients that contain a direction (allocating variant).
 *
 * @param[in] idx   Global direction index.
 * @param[in] order Direction order.
 * @param[in] num   Number.
 *
 * @return Newly allocated result. Caller must free via oti_free().
 */
otinum_t oti_extract_im(imdir_t idx, ord_t order, const otinum_t* num);

/**
 * @brief Extracts the coefficients that contain a direction into an existing number.
 *
 * @param[in]     idx   Global direction index.
 * @param[in]     order Direction order.
 * @param[in]     num   Number.
 * @param[in,out] res   Result; may alias @p num.
 *
 * @return DN_OK, or a DN_ERR_* status (the result is then unspecified but freeable).
 */
int oti_extract_im_to(imdir_t idx, ord_t order, const otinum_t* num, otinum_t* res);

/** @} */
// -------------------------------------------------------------------------------------------------------


/**
 * @name Dense derivative extraction
 * Like oti_extract_im(), with the coefficients scaled so that the result holds derivatives (same
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
 * @return Newly allocated result. Caller must free via oti_free().
 */
otinum_t oti_extract_deriv(imdir_t idx, ord_t order, const otinum_t* num);

/**
 * @brief Extracts the derivatives that contain a direction into an existing number.
 *
 * @param[in]     idx   Global direction index.
 * @param[in]     order Direction order.
 * @param[in]     num   Number.
 * @param[in,out] res   Result; may alias @p num.
 *
 * @return DN_OK, or a DN_ERR_* status (the result is then unspecified but freeable).
 */
int oti_extract_deriv_to(imdir_t idx, ord_t order, const otinum_t* num, otinum_t* res);

/** @} */
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Truncated subtraction: keeps only the order-@p order part of num1 - num2.
 *
 * Same result as soti_trunc_sub_oo_to(): the result has nact = max(nact_1, nact_2) and the larger
 * truncation order, and every order other than @p order (the real part included, unless @p order
 * is 0) is zero.
 *
 * @param[in]     order Order to keep.
 * @param[in]     num1  First operand.
 * @param[in]     num2  Second operand.
 * @param[in,out] res   Result; may alias either operand.
 *
 * @return DN_OK, or a DN_ERR_* status (the result is then unspecified but freeable).
 */
int oti_trunc_sub_to(ord_t order, const otinum_t* num1, const otinum_t* num2, otinum_t* res);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Evaluates the Taylor polynomial of a number at a perturbation of its bases.
 *
 * Returns re + sum_d c_d prod_{b in d} delta[b - 1], the value soti_taylor_integrate() computes,
 * with one delta per active base (delta[u] perturbs base u + 1).
 *
 * @param[in] num    Number.
 * @param[in] deltas Perturbation of each base 1..nact, length num->nact. May be NULL when
 *                   num->nact is 0.
 *
 * @return Value of the polynomial.
 */
coeff_t oti_rom_eval(const otinum_t* num, const coeff_t* deltas);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Evaluates the Taylor polynomial of a number at many perturbations at once.
 *
 * out[t] = re + sum_d c_d prod_{b in d} deltas[(b - 1) * npts + t], for t < @p npts.
 *
 * @param[in]  num    Number.
 * @param[in]  deltas Perturbations, num->nact rows of @p npts reals (row u = base u + 1).
 * @param[in]  npts   Number of evaluation points.
 * @param[out] out    Values, length @p npts.
 *
 * @return DN_OK, or DN_ERR_MEMORY when the scratch row cannot be allocated.
 */
int oti_rom_eval_points(const otinum_t* num, const coeff_t* deltas, uint64_t npts, coeff_t* out);
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
void oti_get_all_ims_to(const otinum_t* num, bases_t nbasis, ord_t order, int derivs,
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
bases_t oti_order_max_base(ord_t p, const otinum_t* num);
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
void oti_scatter_order_im(ord_t p, const otinum_t* num, ndir_t width, coeff_t* out,
                          uint64_t stride);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Adds order-@p p coefficients given at their global indices to a number.
 *
 * num += sum_g vals[g * stride] e(g, p) for g < @p nvals. nact grows to the largest base of any
 * nonzero value, and the truncation order is raised to @p p when lower (the sparse sum
 * `num + sotinum` of set_order_im_from_array()). Order 0 adds vals[0] to the real part.
 *
 * @param[in]     p      Order.
 * @param[in]     vals   Values at global indices.
 * @param[in]     nvals  Number of values.
 * @param[in]     stride Distance between consecutive values, in reals.
 * @param[in,out] num    Number.
 *
 * @return DN_OK, DN_ERR_INDEX (a base above 65535) or DN_ERR_MEMORY.
 */
int oti_add_order_im_global(ord_t p, const coeff_t* vals, ndir_t nvals, uint64_t stride,
                            otinum_t* num);
// -------------------------------------------------------------------------------------------------------

#endif
