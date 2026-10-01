#ifndef OTI_DENSE_SOA_BASE_H
#define OTI_DENSE_SOA_BASE_H

// Dense SoA arrays: memory, element and block access, conversions, truncation.
//
// Conventions follow include/oti/dense/scalar/base.h: functions that can allocate return a DN_*
// status; `_to` variants write into an existing array, grow it as needed and replace its nact,
// shape, truncation order and values; @p res may alias any input, except where a function says
// "must not alias". Operations between two arrays work over nact = max(nact_1, nact_2) and the
// larger truncation order (as arrso_t).
//
// No coefficient-sized buffer outlives a call: SoA operations write straight into @p res, and when
// @p res aliases an operand the result is built in a call-local buffer (malloc/free inside the call)
// and moved in. Only small index buffers live in the per-thread workspace (oti_ws()).


/**
 * @brief Block number of direction @p i of order @p p (order 0: the real block).
 *
 * Computes a binomial coefficient: kernels compute the first block of an order once and add the
 * index (bp + i), never call this per direction.
 *
 * @param[in] k Number of active bases.
 * @param[in] p Order.
 * @param[in] i Direction index within order p (0 for p = 0).
 *
 * @return 0 for p = 0, otherwise 1 + sshelp_order_offset(k, p) + i.
 */
static inline uint64_t oarr_block_index(bases_t k, ord_t p, ndir_t i){

    return (p == 0) ? 0 : 1 + sshelp_order_offset(k, p) + i;

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// ---------------------------------------     MEMORY     ------------------------------------------------
// -------------------------------------------------------------------------------------------------------

/**
 * @brief Empty 0 x 0 array with no bases and truncation order 0.
 *
 * @return Array with a NULL buffer. oarr_free() on it is a no-op.
 */
oarr_t oarr_init(void);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Makes an array a zero nrows x ncols array over bases 1..nact.
 *
 * @param[in]     nact      Number of active bases.
 * @param[in]     nrows     Number of rows.
 * @param[in]     ncols     Number of columns.
 * @param[in]     trc_order Truncation order.
 * @param[in,out] res       Array (act_order = 0 on return); its buffer is reused when large enough.
 *
 * @return DN_OK, or DN_ERR_MEMORY when the size overflows or the allocation fails.
 */
int oarr_zeros_to(bases_t nact, uint64_t nrows, uint64_t ncols, ord_t trc_order, oarr_t* res);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Makes an array a real array (nact = 0) from a column-major buffer.
 *
 * @param[in]     data      nrows*ncols reals, column-major. May be NULL for zeros.
 * @param[in]     nrows     Number of rows.
 * @param[in]     ncols     Number of columns.
 * @param[in]     trc_order Truncation order.
 * @param[in,out] res       Array.
 *
 * @return DN_OK, or DN_ERR_MEMORY.
 */
int oarr_from_real_to(const coeff_t* data, uint64_t nrows, uint64_t ncols, ord_t trc_order,
                      oarr_t* res);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Makes an array the n x n identity matrix (nact = 0).
 *
 * @param[in]     n         Number of rows and columns.
 * @param[in]     trc_order Truncation order.
 * @param[in,out] res       Array.
 *
 * @return DN_OK, or DN_ERR_MEMORY.
 */
int oarr_eye_to(uint64_t n, ord_t trc_order, oarr_t* res);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Grows the buffer of an array to hold at least @p cap bases at @p trc_order with the given
 * shape.
 *
 * Keeps the values when the size (nrows*ncols) is unchanged; otherwise the contents are undefined
 * and the caller rewrites them. Raises trc_order when needed (new orders are zero when the size is
 * unchanged). Sets nrows, ncols and size; keeps nact and act_order. The required layout is
 * (max(cap, nact), max(trc_order, current trc), new size): if it fits the current allocation the
 * buffer is kept, otherwise exactly the required layout is allocated; afterwards nbases =
 * max(cap, nact) (it may drop; never the old nbases at a higher trc or another size).
 *
 * @param[in,out] arr       Array.
 * @param[in]     cap       Required base capacity.
 * @param[in]     nrows     Number of rows.
 * @param[in]     ncols     Number of columns.
 * @param[in]     trc_order Required truncation order.
 *
 * @return DN_OK, or DN_ERR_MEMORY.
 */
int oarr_reserve(oarr_t* arr, bases_t cap, uint64_t nrows, uint64_t ncols, ord_t trc_order);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Releases the buffer of an array and resets it to oarr_init().
 *
 * @param[in,out] arr Array. Safe on oarr_init() and on an array left by a failed call.
 */
void oarr_free(oarr_t* arr);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Copies an array into an existing one.
 *
 * @param[in]     arr Array to copy.
 * @param[in,out] res Destination; grown as needed. May alias @p arr (no-op).
 *
 * @return DN_OK, or DN_ERR_MEMORY.
 */
int oarr_copy_to(const oarr_t* arr, oarr_t* res);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Extends an array to be dense over bases 1..nact, keeping its values.
 *
 * Does nothing when @p nact <= arr->nact. Otherwise the blocks move to their offsets over the new
 * nact, highest order first (in place when the capacity suffices); new blocks are zero.
 *
 * @param[in]     nact New number of active bases.
 * @param[in,out] arr  Array.
 *
 * @return DN_OK, or DN_ERR_MEMORY.
 */
int oarr_add_bases(bases_t nact, oarr_t* arr);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Writes the blocks of an array in the layout of a larger (nact, trc).
 *
 * Block version of oti_kernel_expand() (zero-extension): writes the real block and orders 1..trc;
 * blocks the array does not have are zero.
 *
 * @param[in]  arr Array, with arr->nact <= @p ku.
 * @param[in]  ku  Number of bases of the target layout.
 * @param[in]  trc Truncation order of the target layout.
 * @param[out] dst (1 + sshelp_ndir_total(ku, trc)) * arr->size reals. Must not alias arr->p_data.
 */
void oarr_kernel_expand(const oarr_t* arr, bases_t ku, ord_t trc, coeff_t* dst);
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// ---------------------------------------     ACCESS     ------------------------------------------------
// -------------------------------------------------------------------------------------------------------

/**
 * @brief Block of a direction given as a global (index, order) pair.
 *
 * @param[in] idx   Global direction index within @p order.
 * @param[in] order Direction order; 0 gives the real block.
 * @param[in] arr   Array.
 *
 * @return Pointer to the nrows x ncols column-major block inside arr->p_data, or NULL when a base of
 *         the direction is above nact or order > trc_order. Valid until the array is resized.
 */
coeff_t* oarr_get_block(imdir_t idx, ord_t order, const oarr_t* arr);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Element (i, j) into an existing scalar (a copy, with the array's nact and orders).
 *
 * @param[in]     i   Row.
 * @param[in]     j   Column.
 * @param[in]     arr Array.
 * @param[in,out] res Scalar; grown as needed.
 *
 * @return DN_OK, DN_ERR_INDEX (i or j out of range) or DN_ERR_MEMORY.
 */
int oarr_get_item_to(uint64_t i, uint64_t j, const oarr_t* arr, otinum_t* res);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Sets element (i, j) from a dense scalar.
 *
 * Assignment rule: raises the array's nact to the scalar's (oarr_add_bases()) and its truncation
 * order to the scalar's (zero-extending the entries already there), so no coefficient of @p num is
 * dropped. Raises act_order when needed.
 *
 * @param[in]     num Scalar.
 * @param[in]     i   Row.
 * @param[in]     j   Column.
 * @param[in,out] arr Array.
 *
 * @return DN_OK, DN_ERR_INDEX or DN_ERR_MEMORY.
 */
int oarr_set_item(const otinum_t* num, uint64_t i, uint64_t j, oarr_t* arr);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Sets element (i, j) to a real value (all its imaginary coefficients to zero).
 *
 * @param[in]     val Real value.
 * @param[in]     i   Row.
 * @param[in]     j   Column.
 * @param[in,out] arr Array.
 *
 * @return DN_OK, or DN_ERR_INDEX.
 */
int oarr_set_item_r(coeff_t val, uint64_t i, uint64_t j, oarr_t* arr);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Density diagnostic: nonzero imaginary coefficients divided by imaginary slots.
 *
 * @param[in] arr Array.
 *
 * @return Value in [0, 1]; 0 when there are no slots.
 */
double oarr_density(const oarr_t* arr);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Bytes used by the buffer of an array (at least its capacity at the current trc and size, which
 * may understate the real allocation after a result lowered trc or changed shape), plus the struct.
 *
 * @param[in] arr Array.
 *
 * @return Size in bytes.
 */
size_t oarr_memory_size(const oarr_t* arr);
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// ---------------------------------------     CONVERSION     --------------------------------------------
// -------------------------------------------------------------------------------------------------------

/**
 * @brief Converts a sparse array to a dense SoA array.
 *
 * nact is the largest base of any element; the truncation order is the largest element truncation
 * order (real elements often have order 0).
 *
 * @param[in]     arr Sparse array.
 * @param[in,out] res Dense array.
 * @param[in]     dhl Direction helper list.
 *
 * @return DN_OK, DN_ERR_INDEX or DN_ERR_MEMORY.
 */
int oarr_from_arrso_to(const arrso_t* arr, oarr_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Converts a dense SoA array to a sparse array (nonzero coefficients only).
 *
 * @param[in] arr SoA array.
 * @param[in] dhl Direction helper list.
 *
 * @return Newly allocated sparse array. Caller must free via arrso_free(). The sparse
 *         constructors exit on an allocation failure, as everywhere in the sparse module.
 */
arrso_t oarr_to_arrso(const oarr_t* arr, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @name Dense SoA truncation
 * Array versions of oti_truncate_im(), oti_truncate_order(), oti_get_order_im() and
 * oti_compact(), applied to every element.
 * @{
 */

/**
 * @brief Truncates a direction in every element into an existing array.
 *
 * @param[in]     idx   Global direction index within @p order.
 * @param[in]     order Direction order (>= 1).
 * @param[in]     arr   Array.
 * @param[in,out] res   Result; may alias @p arr.
 *
 * @return DN_OK, or DN_ERR_MEMORY.
 */
int oarr_truncate_im_to(imdir_t idx, ord_t order, const oarr_t* arr, oarr_t* res);

/**
 * @brief Removes orders @p order and higher in every element into an existing array (keeps trc).
 *
 * @param[in]     order First order removed.
 * @param[in]     arr   Array.
 * @param[in,out] res   Result; may alias @p arr.
 *
 * @return DN_OK, or DN_ERR_MEMORY.
 */
int oarr_truncate_order_to(ord_t order, const oarr_t* arr, oarr_t* res);

/**
 * @brief Keeps only one order in every element into an existing array.
 *
 * @param[in]     order Order to keep.
 * @param[in]     arr   Array.
 * @param[in,out] res   Result; may alias @p arr.
 *
 * @return DN_OK, or DN_ERR_MEMORY.
 */
int oarr_get_order_im_to(ord_t order, const oarr_t* arr, oarr_t* res);

/**
 * @brief Trims trailing all-zero bases (every block of the base zero) and lowers act_order.
 *
 * @param[in]     arr Array.
 * @param[in,out] res Result; may alias @p arr (then compacted in place, without shrinking).
 *
 * @return DN_OK, or DN_ERR_MEMORY.
 */
int oarr_compact_to(const oarr_t* arr, oarr_t* res);

/** @} */
// -------------------------------------------------------------------------------------------------------

#endif
