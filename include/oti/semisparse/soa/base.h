#ifndef OTI_SEMISPARSE_SOA_BASE_H
#define OTI_SEMISPARSE_SOA_BASE_H

// Semi-sparse SoA arrays: memory, element and block access, conversions.
//
// Conventions follow include/oti/semisparse/scalar/base.h: allocating functions return an array
// the caller releases with oarrss_free(); `_to` variants write into an existing array, grow it as
// needed and replace its set, shape, truncation order and values; @p res may alias any input.
// Operations between two arrays work over the union of their active sets and the larger
// truncation order (as arrso_t).



/**
 * @brief Block number of local direction @p i of order @p p (order 0: the real block).
 *
 * @param[in] k Number of bases.
 * @param[in] p Order.
 * @param[in] i Local direction index within order p (0 for p = 0).
 *
 * @return 0 for p = 0, otherwise 1 + sshelp_order_offset(k, p) + i.
 */
static inline uint64_t oarrss_block_index(bases_t k, ord_t p, ndir_t i){

    return (p == 0) ? 0 : 1 + sshelp_order_offset(k, p) + i;

}
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// ---------------------------------------     MEMORY     ------------------------------------------------
// -------------------------------------------------------------------------------------------------------

/**
 * @brief Empty 0 x 0 array with no bases and truncation order 0.
 *
 * @return Array with NULL buffers (flag = 1). oarrss_free() on it is a no-op.
 */
oarrss_t oarrss_init(void);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Creates a zero array over the given active bases.
 *
 * @param[in] bases     Active global bases, strictly increasing, length @p k. May be NULL if k = 0.
 * @param[in] k         Number of active bases.
 * @param[in] nrows     Number of rows.
 * @param[in] ncols     Number of columns.
 * @param[in] trc_order Truncation order.
 *
 * @return Newly allocated array (act_order = 0). Caller must free via oarrss_free().
 */
oarrss_t oarrss_zeros(const bases_t* bases, bases_t k, uint64_t nrows, uint64_t ncols,
                      ord_t trc_order);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Creates a real array (no bases) from a column-major buffer.
 *
 * @param[in] data      nrows*ncols reals, column-major. May be NULL for zeros.
 * @param[in] nrows     Number of rows.
 * @param[in] ncols     Number of columns.
 * @param[in] trc_order Truncation order.
 *
 * @return Newly allocated array. Caller must free via oarrss_free().
 */
oarrss_t oarrss_from_real(const coeff_t* data, uint64_t nrows, uint64_t ncols, ord_t trc_order);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Creates an identity matrix with no bases.
 *
 * @param[in] n         Number of rows and columns.
 * @param[in] trc_order Truncation order.
 *
 * @return Newly allocated array. Caller must free via oarrss_free().
 */
oarrss_t oarrss_eye(uint64_t n, ord_t trc_order);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Grows the buffers of an array to hold at least @p cap bases at @p trc_order with the
 * given shape.
 *
 * Keeps the values when the size (nrows*ncols) is unchanged; otherwise the contents are
 * undefined and the caller rewrites them. Raises trc_order when needed (new orders are zero when
 * the size is unchanged). Sets nrows, ncols and size.
 *
 * @param[in,out] arr       Array (must own its memory).
 * @param[in]     cap       Required base capacity.
 * @param[in]     nrows     Number of rows.
 * @param[in]     ncols     Number of columns.
 * @param[in]     trc_order Required truncation order.
 */
void oarrss_reserve(oarrss_t* arr, bases_t cap, uint64_t nrows, uint64_t ncols, ord_t trc_order);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Releases the buffers of an array and resets it to oarrss_init().
 *
 * Does nothing to the buffers of a view (flag = 0).
 *
 * @param[in,out] arr Array.
 */
void oarrss_free(oarrss_t* arr);
// -------------------------------------------------------------------------------------------------------


/**
 * @name Semi-sparse SoA copy
 * @{
 */

/**
 * @brief Copies an array.
 *
 * @param[in] arr Array to copy.
 *
 * @return Newly allocated copy. Caller must free via oarrss_free().
 */
oarrss_t oarrss_copy(const oarrss_t* arr);

/**
 * @brief Copies an array into an existing one.
 *
 * @param[in]     arr Array to copy.
 * @param[in,out] res Destination; grown as needed.
 */
void oarrss_copy_to(const oarrss_t* arr, oarrss_t* res);

/** @} */
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Adds bases to the active set of an array, keeping its values.
 *
 * Blocks move to their new positions (zero-extension when the current set is a leading part of
 * the union, remap otherwise); new directions are zero.
 *
 * @param[in]     bases Global bases to add, strictly increasing, length @p k.
 * @param[in]     k     Number of bases to add.
 * @param[in,out] arr   Array (must own its memory).
 */
void oarrss_add_bases(const bases_t* bases, bases_t k, oarrss_t* arr);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Writes the blocks of an array in the layout of a larger active set.
 *
 * Block version of ssoti_kernel_expand(): the target set contains the array's set and @p pos is
 * the position of each of its bases there. Writes the real block and orders 1..trc.
 *
 * @param[in]  arr  Array.
 * @param[in]  pos  Target position of each base of @p arr, length arr->nbases.
 * @param[in]  ku   Number of bases of the target set.
 * @param[in]  trc  Truncation order of the target layout.
 * @param[out] dst  (1 + sshelp_ndir_total(ku, trc)) * arr->size reals. Must not alias arr->p_data.
 */
void oarrss_kernel_expand(const oarrss_t* arr, const bases_t* pos, bases_t ku, ord_t trc,
                          coeff_t* dst);
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
 * @return Pointer to the nrows x ncols column-major block inside arr->p_data, or NULL when a base
 *         of the direction is not active or order > trc_order. Valid until the array is resized.
 */
coeff_t* oarrss_get_block(imdir_t idx, ord_t order, const oarrss_t* arr);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Element (i, j) as a semi-sparse scalar over the array's active set.
 *
 * @param[in] i   Row.
 * @param[in] j   Column.
 * @param[in] arr Array.
 *
 * @return Newly allocated scalar. Caller must free via ssoti_free().
 */
ssotinum_t oarrss_get_item(uint64_t i, uint64_t j, const oarrss_t* arr);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Element (i, j) into an existing scalar.
 *
 * @param[in]     i   Row.
 * @param[in]     j   Column.
 * @param[in]     arr Array.
 * @param[in,out] res Scalar; grown as needed.
 */
void oarrss_get_item_to(uint64_t i, uint64_t j, const oarrss_t* arr, ssotinum_t* res);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Sets element (i, j) from a semi-sparse scalar.
 *
 * Adds the scalar's bases to the array's set when needed (oarrss_add_bases()). Orders of the
 * scalar above the array's truncation order are dropped. Raises act_order when needed.
 *
 * @param[in]     num Scalar.
 * @param[in]     i   Row.
 * @param[in]     j   Column.
 * @param[in,out] arr Array.
 */
void oarrss_set_item(const ssotinum_t* num, uint64_t i, uint64_t j, oarrss_t* arr);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Sets element (i, j) to a real value (all its imaginary coefficients to zero).
 *
 * @param[in]     val Real value.
 * @param[in]     i   Row.
 * @param[in]     j   Column.
 * @param[in,out] arr Array.
 */
void oarrss_set_item_r(coeff_t val, uint64_t i, uint64_t j, oarrss_t* arr);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Density diagnostic: nonzero imaginary coefficients divided by imaginary slots.
 *
 * @param[in] arr Array.
 *
 * @return Value in [0, 1]; 0 when there are no slots.
 */
double oarrss_density(const oarrss_t* arr);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Bytes used by the buffers of an array (its capacity), plus the struct.
 *
 * @param[in] arr Array.
 *
 * @return Size in bytes.
 */
size_t oarrss_memory_size(const oarrss_t* arr);
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// ---------------------------------------     CONVERSION     --------------------------------------------
// -------------------------------------------------------------------------------------------------------

/**
 * @brief Converts a sparse array to a semi-sparse SoA array.
 *
 * The active set is the union of the bases of every element; the truncation order is the
 * largest element truncation order (real elements often have order 0).
 *
 * @param[in] arr Sparse array.
 * @param[in] dhl Direction helper list.
 *
 * @return Newly allocated array. Caller must free via oarrss_free().
 */
oarrss_t oarrss_from_arrso(const arrso_t* arr, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Converts a semi-sparse SoA array to a sparse array (nonzero coefficients only).
 *
 * @param[in] arr SoA array.
 * @param[in] dhl Direction helper list.
 *
 * @return Newly allocated sparse array. Caller must free via arrso_free().
 */
arrso_t oarrss_to_arrso(const oarrss_t* arr, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @name Semi-sparse SoA truncation
 * Array versions of ssoti_truncate_im(), ssoti_truncate_order() and ssoti_get_order_im(), applied
 * to every element.
 * @{
 */

/**
 * @brief Truncates a direction in every element into an existing array.
 *
 * @param[in]     idx   Global direction index within @p order.
 * @param[in]     order Direction order (>= 1).
 * @param[in]     arr   Array.
 * @param[in,out] res   Result; may alias @p arr.
 */
void oarrss_truncate_im_to(imdir_t idx, ord_t order, const oarrss_t* arr, oarrss_t* res);

/**
 * @brief Removes orders @p order and higher in every element into an existing array.
 *
 * @param[in]     order First order removed.
 * @param[in]     arr   Array.
 * @param[in,out] res   Result; may alias @p arr.
 */
void oarrss_truncate_order_to(ord_t order, const oarrss_t* arr, oarrss_t* res);

/**
 * @brief Keeps only one order in every element into an existing array.
 *
 * @param[in]     order Order to keep.
 * @param[in]     arr   Array.
 * @param[in,out] res   Result; may alias @p arr.
 */
void oarrss_get_order_im_to(ord_t order, const oarrss_t* arr, oarrss_t* res);

/**
 * @brief Removes every active base whose blocks are all zero, into an existing array.
 *
 * @param[in]     arr Array.
 * @param[in,out] res Result; may alias @p arr.
 */
void oarrss_compact_to(const oarrss_t* arr, oarrss_t* res);

/** @} */
// -------------------------------------------------------------------------------------------------------

#endif
