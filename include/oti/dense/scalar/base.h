#ifndef OTI_DENSE_SCALAR_BASE_H
#define OTI_DENSE_SCALAR_BASE_H

// Dense scalar: memory, element access, conversions and truncation (PLAN-dense-update.md).
//
// Conventions for the whole dense API (oti_, oarr_, arro_, fearr_, lilo_, csro_):
//   - A number is dense over the global bases 1..nact (otinum_t). Directions are given as global
//     (index, order) pairs, the same numbering as sotinum_t; a direction whose largest base is above
//     nact is structurally zero. Local and global numbering coincide, so there is no remap anywhere.
//   - Order rules, the same as semi-sparse: the result of an operation between two operands has
//     trc = max(trc_a, trc_b) and nact = max(nact_a, nact_b); an operand with a smaller nact or a
//     lower truncation order is zero-extended to that layout (a prefix of it). oti_truncate_order()
//     keeps trc. Assignment into an array raises the array's trc and nact. Bases are never dropped
//     automatically: oti_compact() only trims trailing all-zero bases.
//   - act_order of a result is an upper bound on its nonzero orders (kernels skip orders above it, so too
//     low a value silently drops coefficients; a tighter exact value is allowed): sum / sub: max(act_a,
//     act_b), a real operand counting as 0; neg, real scale, transpose, copy, get_item: unchanged; mul
//     and matmul: min(act_a + act_b, trc); gem: max(min(act_1 + act_2, trc), act_3); div, pow, every
//     function, solve / inv / det: trc (0 for a real result); truncate_order(o): min(act, o - 1);
//     extract_im(order): act - order (0 below); get_order_im(o): o (0 for the real part).
//   - Maximum order: trc_order and every direction order are at most _MAXORDER_OTI (150; ord_t
//     would allow 255, but stack tuples are sized _MAXORDER_OTI). Every creator, reserve, e,
//     set_item and `_to` that would exceed it returns DN_ERR_INDEX.
//   - The global truncation order (dhl.order, pyoti.core.set_trunc_order()) is never read.
//   - Statuses, never exit(): every function that can allocate returns int, DN_OK or a negative
//     DN_ERR_* code (include/oti/dense/scalar/structures.h). After a failure the result is valid
//     (safe to free) but its value is unspecified.
//   - Byte budget: no single coefficient buffer (a number's imaginary part, an array's blocks) may
//     exceed OTI_DENSE_MAX_MB megabytes (environment variable, read once per process; default the
//     physical memory, or 64 GiB when it cannot be queried). A larger but representable request
//     returns DN_ERR_MEMORY before allocating, instead of an overcommitted malloc that is killed
//     while it is zero-filled.
//   - `_to` variants write into an existing number @p res, grow its buffers as needed and replace
//     its nact, truncation order, active order and values. @p res may alias any input, except
//     where a function says "must not alias".
//   - Allocating variants (returning otinum_t) are C conveniences over the `_to` variants: on a
//     failure they return oti_init() with re = NaN. The Python layer uses the `_to` variants.
//   - Allocating functions return a new number the caller releases with oti_free().
//   - Scratch space comes from a per-thread workspace (oti_ws()); no function uses the dhelp p_im
//     scratch arrays or any other global temporary. Scalar operations may keep a bounded
//     coefficient buffer there (at most 64 KiB per thread; larger needs are malloc'd and freed in
//     the call); SoA operations keep only index buffers there (include/oti/dense/soa/base.h).
//   - Exceptions to "never exit()", all in shared code: conversions to the sparse types
//     (oti_to_soti(), oarr_to_arrso(), arro_to_arrso()) and the shared product tables
//     (sshelp_get_pair(), the dhelp multiplication tables) exit on an allocation failure.


// -------------------------------------------------------------------------------------------------------
// ---------------------------------------     MEMORY     ------------------------------------------------
// -------------------------------------------------------------------------------------------------------

/**
 * @brief Byte budget of a single dense coefficient buffer (see "Byte budget" above).
 *
 * OTI_DENSE_MAX_MB megabytes when that environment variable holds a positive integer, else the
 * physical memory, else 64 GiB. Read once per process; thread-safe. Callers that allocate buffers
 * derived from dense values (for example the Python get_all_ims output) use it to refuse oversized
 * requests before allocating.
 *
 * @return The budget in bytes (SIZE_MAX when it does not fit in size_t).
 */
size_t dn_max_bytes(void);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Real zero with no active bases and truncation order 0.
 *
 * @return Number with a NULL buffer. oti_free() on it is a no-op.
 */
otinum_t oti_init(void);
// -------------------------------------------------------------------------------------------------------


/**
 * @name Dense zero creation
 * @{
 */

/**
 * @brief Creates a zero number over bases 1..nact.
 *
 * @param[in] nact      Number of active bases.
 * @param[in] trc_order Truncation order.
 *
 * @return Newly allocated number with act_order = 0. Caller owns memory and must free via
 *         oti_free(). On failure, oti_init() with re = NaN.
 */
otinum_t oti_create_empty(bases_t nact, ord_t trc_order);

/**
 * @brief Makes an existing number a zero over bases 1..nact.
 *
 * @param[in]     nact      Number of active bases.
 * @param[in]     trc_order Truncation order.
 * @param[in,out] res       Number; its buffer is reused when large enough.
 *
 * @return DN_OK, or DN_ERR_MEMORY when the size overflows or the allocation fails.
 */
int oti_create_empty_to(bases_t nact, ord_t trc_order, otinum_t* res);

/** @} */
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Creates a real number with no active bases.
 *
 * @param[in] re        Real value.
 * @param[in] trc_order Truncation order.
 *
 * @return Number with no buffer (nothing to allocate). Caller may free via oti_free(). For
 *         trc_order > _MAXORDER_OTI, oti_init() with re = NaN.
 */
otinum_t oti_create_r(coeff_t re, ord_t trc_order);
// -------------------------------------------------------------------------------------------------------


/**
 * @name Dense imaginary unit
 * Coefficient 1 along a direction, zero elsewhere (the e() creator). nact is the largest base of
 * the direction, and the truncation order is the larger of @p trc_order and the direction's order,
 * so the coefficient is never dropped. Order 0 gives the real number 1.
 * @{
 */

/**
 * @brief Creates the imaginary unit along a global direction (allocating variant).
 *
 * @param[in] idx       Global direction index within @p order.
 * @param[in] order     Direction order.
 * @param[in] trc_order Requested truncation order.
 *
 * @return Newly allocated number. Caller must free via oti_free(). On failure (a base label above
 *         65535, or the size overflows), oti_init() with re = NaN.
 */
otinum_t oti_e(imdir_t idx, ord_t order, ord_t trc_order);

/**
 * @brief Makes an existing number the imaginary unit along a global direction.
 *
 * @param[in]     idx       Global direction index within @p order.
 * @param[in]     order     Direction order.
 * @param[in]     trc_order Requested truncation order.
 * @param[in,out] res       Number.
 *
 * @return DN_OK; DN_ERR_INDEX when a base of the direction exceeds 65535; DN_ERR_MEMORY.
 */
int oti_e_to(imdir_t idx, ord_t order, ord_t trc_order, otinum_t* res);

/** @} */
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Grows the buffer of a number to hold at least @p cap bases at @p trc_order.
 *
 * Keeps nact, act_order and every coefficient; if @p trc_order is above the current truncation
 * order, the new orders are zero and trc_order is raised. The required layout is
 * (max(cap, nact), max(trc_order, current trc)): if it fits the current allocation the buffer is
 * kept, otherwise exactly the required layout is allocated. Afterwards nbases = max(cap, nact) at
 * the new trc (it may drop: the allocation never shrinks, and nbases never overstates it). Never
 * the old nbases at a higher trc, which can be combinatorially larger.
 *
 * @param[in,out] num       Number.
 * @param[in]     cap       Required base capacity.
 * @param[in]     trc_order Required truncation order.
 *
 * @return DN_OK, or DN_ERR_MEMORY.
 */
int oti_reserve(otinum_t* num, bases_t cap, ord_t trc_order);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Releases the buffer of a number and resets it to oti_init().
 *
 * @param[in,out] num Number. Safe on oti_init() and on a number left by a failed call.
 */
void oti_free(otinum_t* num);
// -------------------------------------------------------------------------------------------------------


/**
 * @name Dense copy
 * @{
 */

/**
 * @brief Copies a number.
 *
 * @param[in] num Number to copy.
 *
 * @return Newly allocated copy with capacity nact. Caller must free via oti_free(). On failure,
 *         oti_init() with re = NaN.
 */
otinum_t oti_copy(const otinum_t* num);

/**
 * @brief Copies a number into an existing one.
 *
 * @param[in]     num Number to copy.
 * @param[in,out] res Destination; grown as needed. May alias @p num (no-op).
 *
 * @return DN_OK, or DN_ERR_MEMORY.
 */
int oti_copy_to(const otinum_t* num, otinum_t* res);

/** @} */
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Extends a number to be dense over bases 1..nact, keeping its value.
 *
 * Does nothing when @p nact <= num->nact. Otherwise the order blocks move to their offsets over the
 * new nact, highest order first (in place when the capacity suffices, else into a new buffer); the
 * new directions are zero.
 *
 * @param[in]     nact New number of active bases.
 * @param[in,out] num  Number.
 *
 * @return DN_OK, or DN_ERR_MEMORY.
 */
int oti_add_bases(bases_t nact, otinum_t* num);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Sets a number to a real value, keeping its truncation order. Sets nact and act_order to 0.
 *
 * Keeps the buffer (capacity), so a later operation into the number does not reallocate.
 *
 * @param[in]     val Real value.
 * @param[in,out] num Number.
 */
void oti_set_r(coeff_t val, otinum_t* num);
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
 * @return The coefficient; 0 when idx >= N_order(nact) (a base above nact) or order > trc_order.
 */
coeff_t oti_get_item(imdir_t idx, ord_t order, const otinum_t* num);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Sets the coefficient of a global direction.
 *
 * Grows nact to the largest base of the direction when needed; a zero for a direction outside
 * nact changes nothing (nact is not grown), a zero inside nact is stored. Raises act_order when
 * needed. Ignored when order > trc_order.
 *
 * @param[in]     val   Value.
 * @param[in]     idx   Global direction index within @p order.
 * @param[in]     order Direction order; 0 sets the real part.
 * @param[in,out] num   Number.
 *
 * @return DN_OK; DN_ERR_INDEX when a base of the direction exceeds 65535; DN_ERR_MEMORY.
 */
int oti_set_item(coeff_t val, imdir_t idx, ord_t order, otinum_t* num);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Derivative along a global direction: the coefficient times the product of the
 * factorials of the base multiplicities (dnutil_tuple_factor()).
 *
 * @param[in] idx   Global direction index within @p order.
 * @param[in] order Direction order.
 * @param[in] num   Number.
 *
 * @return The derivative value (0 for a direction outside the number).
 */
coeff_t oti_get_deriv(imdir_t idx, ord_t order, const otinum_t* num);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Density diagnostic: nonzero imaginary coefficients divided by imaginary slots.
 *
 * @param[in] num Number.
 *
 * @return Value in [0, 1]; 0 when there are no slots.
 */
double oti_density(const otinum_t* num);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Bytes used by the buffer of a number (its capacity), plus the struct.
 *
 * @param[in] num Number.
 *
 * @return Size in bytes.
 */
size_t oti_memory_size(const otinum_t* num);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Prints a number: real part, nact, orders, and every nonzero direction as global bases.
 *
 * @param[in] num Number.
 */
void oti_print(const otinum_t* num);
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// ---------------------------------------     CONVERSION     --------------------------------------------
// -------------------------------------------------------------------------------------------------------

/**
 * @name Dense from sparse
 * nact is the largest base present in a stored direction of the sparse number (explicit zeros
 * included); the truncation order is the sparse number's. Beware: one high label makes the number
 * large (C(nact+n, n) coefficients).
 * @{
 */

/**
 * @brief Converts a sparse number to dense (allocating variant).
 *
 * @param[in] num Sparse number.
 * @param[in] dhl Direction helper list.
 *
 * @return Newly allocated number. Caller must free via oti_free(). On failure, oti_init() with
 *         re = NaN.
 */
otinum_t oti_from_soti(const sotinum_t* num, dhelpl_t dhl);

/**
 * @brief Converts a sparse number to dense into an existing number.
 *
 * @param[in]     num Sparse number.
 * @param[in,out] res Dense result.
 * @param[in]     dhl Direction helper list.
 *
 * @return DN_OK, DN_ERR_INDEX (a base label above 65535), or DN_ERR_MEMORY. Never unranks through
 *         dhl: the sparse global index is the dense index (sshelp_global_unrank() for nact).
 */
int oti_from_soti_to(const sotinum_t* num, otinum_t* res, dhelpl_t dhl);

/** @} */
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Converts a dense number to sparse.
 *
 * Only nonzero coefficients are stored; each order comes out sorted by global index. The sparse
 * constructors exit on an allocation failure, as everywhere in the sparse module.
 *
 * @param[in] num Dense number.
 * @param[in] dhl Direction helper list.
 *
 * @return Newly allocated sparse number, same truncation order. Caller must free via soti_free().
 *         For trc_order > _MAXORDER_OTI, an empty sparse number (soti_init()) with re = NaN.
 */
sotinum_t oti_to_soti(const otinum_t* num, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// ---------------------------------------     TRUNCATION     --------------------------------------------
// -------------------------------------------------------------------------------------------------------

/**
 * @name Dense truncation of a direction
 * Zeroes a direction and every higher-order direction that contains it (same result as
 * soti_truncate_im()). nact is kept; call oti_compact() to trim trailing emptied bases.
 * @{
 */

/**
 * @brief Truncates a direction (allocating variant).
 *
 * @param[in] idx   Global direction index within @p order.
 * @param[in] order Direction order (>= 1).
 * @param[in] num   Number.
 *
 * @return Newly allocated result. Caller must free via oti_free().
 */
otinum_t oti_truncate_im(imdir_t idx, ord_t order, const otinum_t* num);

/**
 * @brief Truncates a direction into an existing number.
 *
 * @param[in]     idx   Global direction index within @p order.
 * @param[in]     order Direction order (>= 1).
 * @param[in]     num   Number.
 * @param[in,out] res   Result; may alias @p num.
 *
 * @return DN_OK, or DN_ERR_MEMORY.
 */
int oti_truncate_im_to(imdir_t idx, ord_t order, const otinum_t* num, otinum_t* res);

/** @} */
// -------------------------------------------------------------------------------------------------------


/**
 * @name Dense truncation of orders
 * Zeroes orders @p order and higher and lowers act_order to at most order-1, keeping the
 * truncation order and nact (same result as soti_truncate_order()). Order 0 gives a real zero.
 * @{
 */

/**
 * @brief Truncates orders (allocating variant).
 *
 * @param[in] order First order removed.
 * @param[in] num   Number.
 *
 * @return Newly allocated result. Caller must free via oti_free().
 */
otinum_t oti_truncate_order(ord_t order, const otinum_t* num);

/**
 * @brief Truncates orders into an existing number.
 *
 * @param[in]     order First order removed.
 * @param[in]     num   Number.
 * @param[in,out] res   Result; may alias @p num.
 *
 * @return DN_OK, or DN_ERR_MEMORY.
 */
int oti_truncate_order_to(ord_t order, const otinum_t* num, otinum_t* res);

/** @} */
// -------------------------------------------------------------------------------------------------------


/**
 * @name Dense single-order extraction
 * Keeps only the coefficients of one order, zero elsewhere including the real part (same result
 * as soti_get_order_im()). Order 0 keeps only the real part. nact and trc are kept.
 * @{
 */

/**
 * @brief Extracts one order (allocating variant).
 *
 * @param[in] order Order to keep.
 * @param[in] num   Number.
 *
 * @return Newly allocated result. Caller must free via oti_free().
 */
otinum_t oti_get_order_im(ord_t order, const otinum_t* num);

/**
 * @brief Extracts one order into an existing number.
 *
 * @param[in]     order Order to keep.
 * @param[in]     num   Number.
 * @param[in,out] res   Result; may alias @p num.
 *
 * @return DN_OK, or DN_ERR_MEMORY.
 */
int oti_get_order_im_to(ord_t order, const otinum_t* num, otinum_t* res);

/** @} */
// -------------------------------------------------------------------------------------------------------


/**
 * @name Dense compaction
 * Lowers nact to the largest base used by a nonzero coefficient (trailing bases only: a zero base
 * below it stays, since the number is dense over 1..nact) and act_order to the highest order with
 * a nonzero. The value and the truncation order are unchanged.
 * @{
 */

/**
 * @brief Compacts a number (allocating variant).
 *
 * @param[in] num Number.
 *
 * @return Newly allocated result with capacity equal to its new nact. Caller must free via
 *         oti_free().
 */
otinum_t oti_compact(const otinum_t* num);

/**
 * @brief Compacts a number into an existing one.
 *
 * @param[in]     num Number.
 * @param[in,out] res Result; may alias @p num (then compacted in place, without shrinking).
 *
 * @return DN_OK, or DN_ERR_MEMORY.
 */
int oti_compact_to(const otinum_t* num, otinum_t* res);

/** @} */
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// ---------------------------------------     WORKSPACE     ---------------------------------------------
// -------------------------------------------------------------------------------------------------------

/**
 * @brief The calling thread's scratch workspace for dense operations.
 *
 * Thread-local; grown by the operations as needed and kept between calls. It holds index buffers
 * and, for scalar operations only, a coefficient buffer of at most 64 KiB; larger coefficient
 * buffers are allocated and freed inside each call. The workspace is released automatically when
 * the thread exits (a pthread key destructor), so dense operations must not be called from another
 * library's thread-exit destructor: it may run after ours and would use the released workspace.
 *
 * @return Pointer to the workspace of the calling thread.
 */
sshelp_ws_t* oti_ws(void);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Releases the calling thread's scratch workspace.
 */
void oti_ws_release(void);
// -------------------------------------------------------------------------------------------------------

#endif
