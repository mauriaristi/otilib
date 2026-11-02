#ifndef OTI_SEMISPARSE_SCALAR_BASE_H
#define OTI_SEMISPARSE_SCALAR_BASE_H

// Semi-sparse scalar: memory, element access, conversions and truncation.
//
// Conventions for the whole ssoti_ API:
//   - Directions are given as global (index, order) pairs, the same numbering as sotinum_t.
//   - Allocating functions return a new number the caller releases with ssoti_free().
//   - A `_to` variant writes into an existing number @p res, grows its buffers as needed and
//     replaces its active set, truncation order and values. @p res may alias any input.
//   - Scratch space comes from a per-thread workspace (ssoti_ws()); no function uses the dhelp
//     p_im scratch arrays.
//   - Allocation failures print a message and exit(OTI_OutOfMemory), like the sparse types.


// -------------------------------------------------------------------------------------------------------
// ---------------------------------------     MEMORY     ------------------------------------------------
// -------------------------------------------------------------------------------------------------------

/**
 * @brief Real zero with no active bases and truncation order 0.
 *
 * @return Number with NULL buffers (flag = 1). ssoti_free() on it is a no-op.
 */
ssotinum_t ssoti_init(void);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Creates a zero number over the given active bases.
 *
 * @param[in] bases     Active global bases, strictly increasing, length @p k. May be NULL if k = 0.
 * @param[in] k         Number of active bases.
 * @param[in] trc_order Truncation order.
 *
 * @return Newly allocated number with act_order = 0. Caller owns memory and must free via
 *         ssoti_free().
 */
ssotinum_t ssoti_create_empty(const bases_t* bases, bases_t k, ord_t trc_order);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Creates a real number with no active bases.
 *
 * @param[in] re        Real value.
 * @param[in] trc_order Truncation order.
 *
 * @return Newly allocated number (no buffers). Caller must free via ssoti_free().
 */
ssotinum_t ssoti_create_r(coeff_t re, ord_t trc_order);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Creates the imaginary unit along a direction: coefficient 1 along it, zero elsewhere.
 *
 * Semi-sparse counterpart of the e() creators of the sparse, dense and static types. The active
 * set is the distinct bases of the direction, and the truncation order is the larger of
 * @p trc_order and the direction's order, so the coefficient is never dropped.
 *
 * @param[in] idx       Global direction index within @p order.
 * @param[in] order     Direction order; 0 gives the real number 1.
 * @param[in] trc_order Requested truncation order.
 *
 * @return Newly allocated number. Caller must free via ssoti_free(). Exits with OTI_BadIndx if the
 *         direction needs a base label above 65535.
 */
ssotinum_t ssoti_e(imdir_t idx, ord_t order, ord_t trc_order);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Grows the buffers of a number to hold at least @p cap bases at @p trc_order.
 *
 * Keeps nbases, the active set and every coefficient; if @p trc_order is above the current
 * truncation order, the new orders are zero and trc_order is raised.
 *
 * @param[in,out] num       Number (must own its memory).
 * @param[in]     cap       Required base capacity.
 * @param[in]     trc_order Required truncation order.
 */
void ssoti_reserve(ssotinum_t* num, bases_t cap, ord_t trc_order);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Releases the buffers of a number and resets it to ssoti_init().
 *
 * Does nothing to the buffers of a view (flag = 0).
 *
 * @param[in,out] num Number.
 */
void ssoti_free(ssotinum_t* num);
// -------------------------------------------------------------------------------------------------------


/**
 * @name Semi-sparse copy
 * @{
 */

/**
 * @brief Copies a number.
 *
 * @param[in] num Number to copy.
 *
 * @return Newly allocated copy with capacity nbases. Caller must free via ssoti_free().
 */
ssotinum_t ssoti_copy(const ssotinum_t* num);

/**
 * @brief Copies a number into an existing one.
 *
 * @param[in]     num Number to copy.
 * @param[in,out] res Destination; grown as needed.
 */
void ssoti_copy_to(const ssotinum_t* num, ssotinum_t* res);

/** @} */
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Adds bases to the active set of a number, keeping its value.
 *
 * The new active set is the union of the current one and @p bases. Coefficients are moved to
 * their new local positions (zero-extension when the current set is a leading part of the union,
 * remap otherwise); new directions are zero.
 *
 * @param[in]     bases Global bases to add, strictly increasing, length @p k.
 * @param[in]     k     Number of bases to add.
 * @param[in,out] num   Number (must own its memory).
 */
void ssoti_add_bases(const bases_t* bases, bases_t k, ssotinum_t* num);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Sets a number to a real value, keeping its truncation order. Clears the active set.
 *
 * @param[in]     val Real value.
 * @param[in,out] num Number.
 */
void ssoti_set_r(coeff_t val, ssotinum_t* num);
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// ---------------------------------------     ACCESS     ------------------------------------------------
// -------------------------------------------------------------------------------------------------------

/**
 * @brief Coefficient of a global direction.
 *
 * @param[in] idx   Global direction index within @p order.
 * @param[in] order Direction order; 0 gives the real part.
 * @param[in] num   Number.
 *
 * @return The coefficient; 0 when a base of the direction is not active or order > trc_order.
 */
coeff_t ssoti_get_item(imdir_t idx, ord_t order, const ssotinum_t* num);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Sets the coefficient of a global direction.
 *
 * Adds the bases of the direction to the active set when they are missing (unless @p val is 0,
 * which is then a no-op). Raises act_order when needed. Ignored when order > trc_order.
 *
 * @param[in]     val   Value.
 * @param[in]     idx   Global direction index within @p order.
 * @param[in]     order Direction order; 0 sets the real part.
 * @param[in,out] num   Number.
 */
void ssoti_set_item(coeff_t val, imdir_t idx, ord_t order, ssotinum_t* num);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Derivative along a global direction: the coefficient times the product of the
 * factorials of the base multiplicities.
 *
 * @param[in] idx   Global direction index within @p order.
 * @param[in] order Direction order.
 * @param[in] num   Number.
 *
 * @return The derivative value.
 */
coeff_t ssoti_get_deriv(imdir_t idx, ord_t order, const ssotinum_t* num);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Density diagnostic: nonzero imaginary coefficients divided by imaginary slots.
 *
 * @param[in] num Number.
 *
 * @return Value in [0, 1]; 0 when there are no slots.
 */
double ssoti_density(const ssotinum_t* num);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Bytes used by the buffers of a number (its capacity), plus the struct.
 *
 * @param[in] num Number.
 *
 * @return Size in bytes.
 */
size_t ssoti_memory_size(const ssotinum_t* num);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Prints a number: real part, active bases, and every nonzero direction as global bases.
 *
 * @param[in] num Number.
 */
void ssoti_print(const ssotinum_t* num);
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// ---------------------------------------     CONVERSION     --------------------------------------------
// -------------------------------------------------------------------------------------------------------

/**
 * @brief Converts a sparse number to semi-sparse.
 *
 * The active set is every base present in a stored direction of @p num (explicit zeros included),
 * sorted.
 *
 * @param[in] num Sparse number.
 * @param[in] dhl Direction helper list.
 *
 * @return Newly allocated number with the same truncation order. Caller must free via
 *         ssoti_free().
 */
ssotinum_t ssoti_from_soti(const sotinum_t* num, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Converts a semi-sparse number to sparse.
 *
 * Only nonzero coefficients are stored; each order comes out sorted by global index.
 *
 * @param[in] num Semi-sparse number.
 * @param[in] dhl Direction helper list.
 *
 * @return Newly allocated sparse number. Caller must free via soti_free().
 */
sotinum_t ssoti_to_soti(const ssotinum_t* num, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// ---------------------------------------     TRUNCATION     --------------------------------------------
// -------------------------------------------------------------------------------------------------------

/**
 * @name Semi-sparse truncation of a direction
 * Zeroes a direction and every higher-order direction that contains it (same result as
 * soti_truncate_im()). The active set is kept; call ssoti_compact() to drop emptied bases.
 * @{
 */

/**
 * @brief Truncates a direction (allocating variant).
 *
 * @param[in] idx   Global direction index within @p order.
 * @param[in] order Direction order (>= 1).
 * @param[in] num   Number.
 *
 * @return Newly allocated result. Caller must free via ssoti_free().
 */
ssotinum_t ssoti_truncate_im(imdir_t idx, ord_t order, const ssotinum_t* num);

/**
 * @brief Truncates a direction into an existing number.
 *
 * @param[in]     idx   Global direction index within @p order.
 * @param[in]     order Direction order (>= 1).
 * @param[in]     num   Number.
 * @param[in,out] res   Result; may alias @p num.
 */
void ssoti_truncate_im_to(imdir_t idx, ord_t order, const ssotinum_t* num, ssotinum_t* res);

/** @} */
// -------------------------------------------------------------------------------------------------------


/**
 * @name Semi-sparse truncation of orders
 * Zeroes orders @p order and higher and lowers act_order to at most order-1, keeping the
 * truncation order (same result as soti_truncate_order()). Order 0 gives a real zero.
 * @{
 */

/**
 * @brief Truncates orders (allocating variant).
 *
 * @param[in] order First order removed.
 * @param[in] num   Number.
 *
 * @return Newly allocated result. Caller must free via ssoti_free().
 */
ssotinum_t ssoti_truncate_order(ord_t order, const ssotinum_t* num);

/**
 * @brief Truncates orders into an existing number.
 *
 * @param[in]     order First order removed.
 * @param[in]     num   Number.
 * @param[in,out] res   Result; may alias @p num.
 */
void ssoti_truncate_order_to(ord_t order, const ssotinum_t* num, ssotinum_t* res);

/** @} */
// -------------------------------------------------------------------------------------------------------


/**
 * @name Semi-sparse single-order extraction
 * Keeps only the coefficients of one order, zero elsewhere including the real part (same result
 * as soti_get_order_im()). Order 0 keeps only the real part.
 * @{
 */

/**
 * @brief Extracts one order (allocating variant).
 *
 * @param[in] order Order to keep.
 * @param[in] num   Number.
 *
 * @return Newly allocated result. Caller must free via ssoti_free().
 */
ssotinum_t ssoti_get_order_im(ord_t order, const ssotinum_t* num);

/**
 * @brief Extracts one order into an existing number.
 *
 * @param[in]     order Order to keep.
 * @param[in]     num   Number.
 * @param[in,out] res   Result; may alias @p num.
 */
void ssoti_get_order_im_to(ord_t order, const ssotinum_t* num, ssotinum_t* res);

/** @} */
// -------------------------------------------------------------------------------------------------------


/**
 * @name Semi-sparse compaction
 * Removes every active base whose directions are all zero and lowers act_order to the highest
 * order with a nonzero. The value is unchanged.
 * @{
 */

/**
 * @brief Compacts a number (allocating variant).
 *
 * @param[in] num Number.
 *
 * @return Newly allocated result with capacity equal to its new nbases. Caller must free via
 *         ssoti_free().
 */
ssotinum_t ssoti_compact(const ssotinum_t* num);

/**
 * @brief Compacts a number into an existing one.
 *
 * @param[in]     num Number.
 * @param[in,out] res Result; may alias @p num (then compacted in place, without shrinking).
 */
void ssoti_compact_to(const ssotinum_t* num, ssotinum_t* res);

/** @} */
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// ---------------------------------------     WORKSPACE     ---------------------------------------------
// -------------------------------------------------------------------------------------------------------

/**
 * @brief The calling thread's scratch workspace for semi-sparse scalar operations.
 *
 * Thread-local; grown by the operations as needed and kept between calls.
 *
 * @return Pointer to the workspace of the calling thread.
 */
sshelp_ws_t* ssoti_ws(void);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Releases the calling thread's scratch workspace.
 */
void ssoti_ws_release(void);
// -------------------------------------------------------------------------------------------------------

#endif
