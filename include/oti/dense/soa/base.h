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
//
// Shapes: every extent and the product of the nonzero extents must fit int64_t (the descriptor's
// type), also for an empty shape; otherwise DN_ERR_MEMORY with @p res unchanged. Phase 7b: the element
// shape S has any rank 0 .. OTI_ND_MAXDIM - 1 (include/oti/dense/soa/structures.h). The elementwise
// functions keep the shape of their operands (the array-array ones broadcast them, NumPy rules;
// DN_ERR_SIZE when they do not broadcast); the matrix functions (products, transpose, linear algebra,
// CSR, oarr_get_item_to(), oarr_set_item()) take arrays of element rank 2 only (DN_ERR_SIZE otherwise);
// a Gauss array passes them an oarr_view_matrix() view.
//
// Any operand may be a view (canonical operands, structures.h): a non-canonical input is packed into a
// call-local copy first. Views and shared roots as results (contracts 7.3): a `res` that is a view, or a
// root with live views or exports, receives the result through oarr_assign_to(): its shape must be the
// result's (DN_ERR_SIZE otherwise) and the result must fit its shared layout (nact and truncation order
// within the meta's), else OTI_ERR_BUSY; nothing is clipped, directions the result lacks are written as
// zeros in the view's region, and act_order is only raised. A root that nobody shares is replaced as in
// 1.x (it may change its layout and shape). In-place layout changes (oarr_reserve(), oarr_add_bases(),
// oarr_grow_layout(), growth by assignment) return OTI_ERR_BUSY for a view or a shared root.


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


/**
 * @brief Builds a view of an array as an nrows x ncols matrix of the same size (a reshape).
 *
 * The view's blocks descriptor is a temporary over the same data (no reference is taken) and it
 * borrows the array's meta: it must not outlive @p arr, is only ever an input of a C call (never a
 * `res`), and oarr_free() on it only resets it. Used for the Gauss products on reinterpreted shapes
 * (contracts 7.1: views instead of struct copies of a retained descriptor).
 *
 * @param[in]  arr   Array (owning or a view), compact.
 * @param[in]  nrows Rows of the view.
 * @param[in]  ncols Columns of the view; nrows * ncols must equal the array's size.
 * @param[out] view  View; overwritten without being released. May be @p arr only when that is a view.
 *
 * @return DN_OK, DN_ERR_SIZE (another size, or a non-compact array) or DN_ERR_ARGUMENT (NULL, or
 *         @p view == @p arr for an owning array).
 */
int oarr_view_matrix(const oarr_t* arr, uint64_t nrows, uint64_t ncols, oarr_t* view);
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

// -------------------------------------------------------------------------------------------------------
// -------------------------------------     N-D ARRAYS (7b)     ----------------------------------------
// -------------------------------------------------------------------------------------------------------

/**
 * @name Dense SoA n-D arrays, views and indexing (Phase 7b, contracts 7.2-7.5, 11.2-11.7)
 * Keys are nd_index_t items (include/oti/real/ndarray/views.h) on the element axes S; the block axis is
 * never indexed. Results named `res` follow the `_to` rule of this file (views and shared roots receive
 * them through oarr_assign_to()); the view functions make `res` a retained view (OARR_VIEW) after
 * releasing what it held.
 * @{
 */

/**
 * @brief Zero array of any element shape, with a layout reservation (contracts 7.5).
 *
 * @param[in]  nact      Active bases 1..nact of the layout (0: none). Every block exists (all zero,
 *                       act_order 0), so later values over nact' <= nact and trc' <= trc_order never
 *                       relayout the array.
 * @param[in]  ndim      Rank of S, 0 .. OTI_ND_MAXDIM - 1.
 * @param[in]  shape     ndim extents >= 0 (NULL when ndim is 0).
 * @param[in]  layout    ND_LAYOUT_F (canonical) or ND_LAYOUT_C: order of the axes inside a block.
 * @param[in]  trc_order Truncation order, <= _MAXORDER_OTI.
 * @param[out] res       Result.
 *
 * @return DN_OK; DN_ERR_ARGUMENT; DN_ERR_SIZE (rank or negative extent); DN_ERR_INDEX (order);
 *         DN_ERR_MEMORY (the layout exceeds the byte budget, checked before allocating); OTI_ERR_BUSY.
 */
int oarr_zeros_nd_to(bases_t nact, int32_t ndim, const int64_t* shape, int32_t layout, ord_t trc_order,
                     oarr_t* res);

/**
 * @brief Real array (no bases) from a real descriptor of any shape and strides (a copy).
 *
 * @param[in]  data      OTI_F64 descriptor (well formed).
 * @param[in]  trc_order Truncation order.
 * @param[in]  layout    ND_LAYOUT_F or ND_LAYOUT_C.
 * @param[out] res       Result of element shape data->shape.
 *
 * @return As oarr_zeros_nd_to(); OTI_ERR_DTYPE for another dtype.
 */
int oarr_from_real_nd_to(const ndarr_t* data, ord_t trc_order, int32_t layout, oarr_t* res);

/**
 * @brief 0-D array holding one scalar (its nact and truncation order).
 *
 * @param[in]  num Scalar.
 * @param[out] res Result.
 *
 * @return As oarr_zeros_nd_to().
 */
int oarr_from_oti_to(const otinum_t* num, oarr_t* res);

/**
 * @brief Copies the element at a full index (one integer per axis; negative ones count from the end).
 *
 * @param[in]  arr   Array (any view).
 * @param[in]  n     Number of indices, oarr_ndim(arr).
 * @param[in]  index Indices.
 * @param[out] res   Scalar over the array's layout (nact, truncation and active orders).
 *
 * @return DN_OK; DN_ERR_INDEX (out of range, or n != ndim); DN_ERR_MEMORY; DN_ERR_ARGUMENT.
 */
int oarr_get_elem_to(const oarr_t* arr, int32_t n, const int64_t* index, otinum_t* res);

/**
 * @brief Grows the layout of a root to at least (nact, trc_order) in place, zero-extending every
 *        element (contracts 11.6 G4, `reserve`).
 *
 * @param[in,out] arr       Root (or an empty array).
 * @param[in]     nact      Required active bases.
 * @param[in]     trc_order Required truncation order.
 *
 * @return DN_OK (also when nothing grows); OTI_ERR_BUSY for a view, or a root with live views or
 *         exports, when the layout would change; DN_ERR_INDEX; DN_ERR_MEMORY.
 */
int oarr_grow_layout(oarr_t* arr, bases_t nact, ord_t trc_order);

/**
 * @brief dst[...] = src, src broadcast to dst's shape (NumPy's assignment rule S1: trailing axes
 *        aligned, extent 1 stretched, leading axes of extent 1 dropped).
 *
 * Growth rule (contracts 11.6 G1): a root nobody shares grows to hold src's layout (truncation order
 * and bases, the elements already there zero-extended); a view or a shared root must already hold it
 * (contracts 7.3), else OTI_ERR_BUSY and nothing changes. Directions src lacks are written as zeros in
 * dst; act_order is raised to src's (never lowered). A src that may share memory with dst is copied
 * first (rule S2: the result is as if src were a snapshot).
 *
 * @param[in]     src Value (any view).
 * @param[in,out] dst Destination (root or view).
 *
 * @return DN_OK; DN_ERR_SIZE (does not broadcast); OTI_ERR_BUSY; OTI_ERR_READONLY; DN_ERR_MEMORY;
 *         DN_ERR_ARGUMENT.
 */
int oarr_assign_to(const oarr_t* src, oarr_t* dst);

/**
 * @brief Basic indexing as a retained view: integers drop their axis, slices keep it, newaxis inserts
 *        one, one ellipsis expands (NumPy rules; contracts 11.3 I1, 11.4 V1).
 *
 * The view shares the buffer and the meta of @p src (one more reference on each), so while it lives
 * the root's layout is fixed (contracts 7.2). Writes through it reach the root.
 *
 * @param[in]  src  Array (root or view).
 * @param[in]  nidx Number of key items, <= 64.
 * @param[in]  idx  Items; ND_IDX_ARRAY is not allowed (DN_ERR_ARGUMENT).
 * @param[out] res  Retained view; what it held is released.
 *
 * @return DN_OK; OTI_ERR_INDEX (out of range, too many indices); OTI_ERR_ARGUMENT; OTI_ERR_SHAPE
 *         (result rank above OTI_ND_MAXDIM).
 */
int oarr_view_index(const oarr_t* src, int32_t nidx, const nd_index_t* idx, oarr_t* res);

/**
 * @brief Permutes the element axes as a retained view (.T, transpose()).
 *
 * @param[in]  src   Array.
 * @param[in]  naxes oarr_ndim(src), or 0 with @p axes NULL to reverse the axes.
 * @param[in]  axes  Permutation (negative values allowed), or NULL.
 * @param[out] res   Retained view.
 *
 * @return DN_OK; DN_ERR_ARGUMENT (count, repeat); DN_ERR_INDEX.
 */
int oarr_view_transpose(const oarr_t* src, int32_t naxes, const int32_t* axes, oarr_t* res);

/**
 * @brief Reshapes the element axes as a retained view, when the strides allow it.
 *
 * @param[in]  src    Array.
 * @param[in]  ndim   New rank.
 * @param[in]  shape  New extents (one -1 allowed).
 * @param[in]  layout Index order, ND_LAYOUT_C (NumPy's default) or ND_LAYOUT_F.
 * @param[out] res    Retained view.
 *
 * @return DN_OK; OTI_ERR_LAYOUT when no view exists (oarr_reshape_copy_to() then copies);
 *         DN_ERR_SIZE (size mismatch, rank); DN_ERR_ARGUMENT.
 */
int oarr_view_reshape(const oarr_t* src, int32_t ndim, const int64_t* shape, int32_t layout,
                      oarr_t* res);

/**
 * @brief Reshapes into a new root (a copy, compact in the index order @p layout).
 *
 * @param[in]  src    Array.
 * @param[in]  ndim   New rank.
 * @param[in]  shape  New extents (one -1 allowed).
 * @param[in]  layout Index order.
 * @param[out] res    Result.
 *
 * @return As oarr_view_reshape(), without OTI_ERR_LAYOUT; DN_ERR_MEMORY.
 */
int oarr_reshape_copy_to(const oarr_t* src, int32_t ndim, const int64_t* shape, int32_t layout,
                         oarr_t* res);

/**
 * @brief Indexing with any key, advanced items included (integer arrays, masks: Phase 5's
 *        nd_index_get() on the block array), as a new root (a copy).
 *
 * @param[in]  src  Array.
 * @param[in]  nidx Number of items, <= 64.
 * @param[in]  idx  Items.
 * @param[out] res  Result.
 *
 * @return DN_OK; OTI_ERR_INDEX; OTI_ERR_SHAPE (index arrays that do not broadcast); OTI_ERR_DTYPE;
 *         DN_ERR_SIZE; DN_ERR_MEMORY; DN_ERR_ARGUMENT.
 */
int oarr_index_get_to(const oarr_t* src, int32_t nidx, const nd_index_t* idx, oarr_t* res);

/**
 * @brief dst[idx] = src with any key (basic: oarr_assign_to() into the region; advanced:
 *        nd_index_set() on the block array, duplicates: the last write wins).
 *
 * The growth rule of oarr_assign_to() applies to @p dst; the key is checked before anything changes.
 *
 * @param[in,out] dst  Destination.
 * @param[in]     nidx Number of items.
 * @param[in]     idx  Items.
 * @param[in]     src  Value (broadcast to the indexed shape).
 *
 * @return As oarr_assign_to() and oarr_index_get_to().
 */
int oarr_index_set(oarr_t* dst, int32_t nidx, const nd_index_t* idx, const oarr_t* src);

/**
 * @brief dst[idx] = num (a scalar broadcast to the indexed region; one element is written in place).
 *
 * @param[in,out] dst  Destination.
 * @param[in]     nidx Number of items.
 * @param[in]     idx  Items.
 * @param[in]     num  Scalar.
 *
 * @return As oarr_index_set().
 */
int oarr_index_set_o(oarr_t* dst, int32_t nidx, const nd_index_t* idx, const otinum_t* num);

/**
 * @brief dst[idx] = val (a real: every direction of the region becomes zero; never grows).
 *
 * @param[in,out] dst  Destination.
 * @param[in]     nidx Number of items.
 * @param[in]     idx  Items.
 * @param[in]     val  Value.
 *
 * @return As oarr_index_set().
 */
int oarr_index_set_r(oarr_t* dst, int32_t nidx, const nd_index_t* idx, coeff_t val);

/**
 * @brief Reshapes a canonical root in place, in F index order (a relabel: no data moves). Views of the
 *        root keep their own shapes.
 *
 * @param[in,out] arr   Root, compact in F order (every `_to` result).
 * @param[in]     ndim  New rank.
 * @param[in]     shape New extents (one -1 allowed); same element count.
 *
 * @return DN_OK; DN_ERR_ARGUMENT (not a root); OTI_ERR_LAYOUT (not compact in F order); DN_ERR_SIZE.
 */
int oarr_reshape_root(oarr_t* arr, int32_t ndim, const int64_t* shape);

/**
 * @brief Tells whether the layout of an array is pinned: a view, or a root with live views, other
 *        references or exports (it then receives results through oarr_assign_to(), see above).
 *
 * @param[in] arr Array (NULL gives 0).
 *
 * @return 1 when pinned, else 0.
 */
int oarr_is_shared(const oarr_t* arr);

/**
 * @brief Raises the shared act_order of an array to min(act, trc_order) (never lowers it): before a
 *        writeable export of an imaginary block (contracts 7.4) or a write through an internal path.
 *
 * @param[in,out] arr Array with a meta (no-op otherwise).
 * @param[in]     act Order.
 */
void oarr_raise_act(oarr_t* arr, ord_t act);

/** @} */
// -------------------------------------------------------------------------------------------------------

#endif
