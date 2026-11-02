#ifndef OTI_REAL_NDARRAY_VIEWS_H
#define OTI_REAL_NDARRAY_VIEWS_H

// -------------------------------------------------------------------------------------------------------
// ndarray views (Phase 1, src/c/real/ndarray/views.c) and advanced indexing (Phase 5, index.c).
//
// View functions write a TEMPORARY descriptor into `out`: it borrows src's reference (same buf,
// ND_RETAINED clear), allocates nothing and cannot fail on the buffer's state. To keep a view beyond
// the lifetime of src, pass it to nd_view_retain(). `out` must be empty or a temporary on entry (it
// is overwritten without being released; OTI_ND_DEBUG asserts it). `out` may be the same object as
// src only when src is a temporary: over a retained src the reference would be lost.
// A view keeps src's ND_WRITEABLE, except broadcast_to and diagonal, which are always read-only (as in
// NumPy), and any view that nd_internal_overlap() flags. Contiguity flags are recomputed.
// Advanced indexing (integer arrays, masks) always copies (nd_index_get()) or scatters
// (nd_index_set()).
// -------------------------------------------------------------------------------------------------------

#include "oti/core/exec.h"
#include "oti/real/ndarray/structures.h"

#ifdef __cplusplus
extern "C" {
#endif

// -------------------------------------------------------------------------------------------------------
// --------------------------------------      STRUCTURES        -----------------------------------------
// -------------------------------------------------------------------------------------------------------

/**
 * @name Index item kinds (nd_index_t.kind)
 * @{
 */
#define ND_IDX_INT       0 ///< An integer: drops the axis. Negative values count from the end.
#define ND_IDX_SLICE     1 ///< start:stop:step, NumPy normalization (nd_slice_normalize()).
#define ND_IDX_NEWAXIS   2 ///< Inserts an axis of extent 1.
#define ND_IDX_ELLIPSIS  3 ///< Expands to the axes not otherwise indexed (at most one).
#define ND_IDX_ARRAY     4 ///< Advanced: an OTI_I64 index array or an OTI_U8 mask (Phase 5 only).
/** @} */

/**
 * @name Slice field presence (nd_index_t.has)
 * @{
 */
#define ND_HAS_START  0x1 ///< start was given (else None).
#define ND_HAS_STOP   0x2 ///< stop was given (else None).
#define ND_HAS_STEP   0x4 ///< step was given (else 1).
/** @} */

/**
 * @brief One item of an index tuple.
 */
typedef struct {
    int32_t         kind;   ///< ND_IDX_*.
    int32_t         has;    ///< ND_HAS_* (slices).
    int64_t         start;  ///< INT: the index; SLICE: start.
    int64_t         stop;   ///< SLICE: stop.
    int64_t         step;   ///< SLICE: step (non-zero when given).
    const ndarr_t*  arr;    ///< ARRAY: OTI_I64 or OTI_U8 descriptor; NULL otherwise.
} nd_index_t;

// -------------------------------------------------------------------------------------------------------
// -------------------------------------    END STRUCTURES      ------------------------------------------
// -------------------------------------------------------------------------------------------------------


/**
 * @name Helpers
 * @{
 */

/**
 * @brief Normalizes a slice against an extent, as PySlice_AdjustIndices does.
 *
 * step defaults to 1; for step > 0 start defaults to 0 and stop to n; for step < 0 start defaults to
 * n - 1 and stop to "before 0". Negative start / stop add n, then clip to [0, n] (step > 0) or
 * [-1, n - 1] (step < 0). len = max(0, ceil((stop - start) / step)).
 *
 * @param[in]  n      Extent of the axis, >= 0.
 * @param[in]  s      Slice item (kind ND_IDX_SLICE).
 * @param[out] start  First index (meaningful when len > 0).
 * @param[out] step   Step.
 * @param[out] len    Number of selected indices.
 *
 * @return OTI_OK, or OTI_ERR_ARGUMENT for a step of 0.
 */
int nd_slice_normalize(int64_t n, const nd_index_t* s, int64_t* start, int64_t* step, int64_t* len);

/**
 * @brief Normalizes an axis number (negative counts from the end).
 *
 * @param[in]  axis Axis, -ndim <= axis < ndim.
 * @param[in]  ndim Rank.
 * @param[out] res  Axis in [0, ndim).
 *
 * @return OTI_OK, or OTI_ERR_INDEX (NumPy's AxisError).
 */
int nd_normalize_axis(int32_t axis, int32_t ndim, int32_t* res);

/**
 * @brief Broadcast shape of several operands (NumPy rules: align right, extent 1 stretches).
 *
 * @param[in]  nops  Number of operands, >= 1.
 * @param[in]  ops   Operands.
 * @param[out] ndim  Rank of the result (max rank).
 * @param[out] shape Extents of the result, OTI_ND_MAXDIM entries available.
 *
 * @return OTI_OK, or OTI_ERR_SHAPE when two extents differ and neither is 1.
 */
int nd_broadcast_shapes(int32_t nops, const ndarr_t* const* ops, int32_t* ndim, int64_t* shape);

/** @} */
// -------------------------------------------------------------------------------------------------------


/**
 * @name Basic views (NumPy basic indexing and axis manipulation)
 * @{
 */

/**
 * @brief Basic indexing: integers, slices, newaxis and one ellipsis (a[i, 1:5:2, None, ...]).
 *
 * Fewer items than axes index the leading axes (an implicit trailing ellipsis). An integer drops its
 * axis, so a[i] on a 2-D array is 1-D (decision 1).
 *
 * @param[in]  src  Well-formed descriptor.
 * @param[in]  nidx Number of items, >= 0.
 * @param[in]  idx  Items; ND_IDX_ARRAY is not allowed here.
 * @param[out] out  Temporary view (may be @p src itself).
 *
 * @return OTI_OK; OTI_ERR_INDEX (integer out of range, too many indices, two ellipses);
 *         OTI_ERR_ARGUMENT (step 0, ND_IDX_ARRAY); OTI_ERR_SHAPE (result rank > OTI_ND_MAXDIM).
 */
int nd_view_index(const ndarr_t* src, int32_t nidx, const nd_index_t* idx, ndarr_t* out);

/**
 * @brief Permutes axes (numpy.transpose / permute_dims).
 *
 * @param[in]  src   Well-formed descriptor.
 * @param[in]  naxes src->ndim, or 0 together with axes == NULL to reverse the axes.
 * @param[in]  axes  Permutation of 0 .. ndim-1 (negative values allowed), or NULL.
 * @param[out] out   Temporary view.
 *
 * @return OTI_OK; OTI_ERR_ARGUMENT (wrong count, repeated axis); OTI_ERR_INDEX (axis out of range).
 */
int nd_view_transpose(const ndarr_t* src, int32_t naxes, const int32_t* axes, ndarr_t* out);

/**
 * @brief Swaps two axes (numpy.swapaxes).
 *
 * @param[in]  src   Well-formed descriptor.
 * @param[in]  axis1 Axis (negative allowed).
 * @param[in]  axis2 Axis (negative allowed).
 * @param[out] out   Temporary view.
 *
 * @return OTI_OK, or OTI_ERR_INDEX.
 */
int nd_view_swapaxes(const ndarr_t* src, int32_t axis1, int32_t axis2, ndarr_t* out);

/**
 * @brief Removes axes of extent 1 (numpy.squeeze).
 *
 * @param[in]  src   Well-formed descriptor.
 * @param[in]  naxes Number of axes, or 0 with axes == NULL for every axis of extent 1.
 * @param[in]  axes  Axes to remove, or NULL.
 * @param[out] out   Temporary view.
 *
 * @return OTI_OK; OTI_ERR_SHAPE (an axis has extent != 1); OTI_ERR_INDEX; OTI_ERR_ARGUMENT (repeat).
 */
int nd_view_squeeze(const ndarr_t* src, int32_t naxes, const int32_t* axes, ndarr_t* out);

/**
 * @brief Inserts axes of extent 1 at the given positions of the result (numpy.expand_dims).
 *
 * @param[in]  src   Well-formed descriptor.
 * @param[in]  naxes Number of new axes, >= 1.
 * @param[in]  axes  Positions in the result (negative allowed, normalized against ndim + naxes).
 * @param[out] out   Temporary view.
 *
 * @return OTI_OK; OTI_ERR_INDEX; OTI_ERR_ARGUMENT (repeat); OTI_ERR_SHAPE (rank > OTI_ND_MAXDIM).
 */
int nd_view_expand_dims(const ndarr_t* src, int32_t naxes, const int32_t* axes, ndarr_t* out);

/**
 * @brief Read-only broadcast view to a shape (numpy.broadcast_to): stretched axes get stride 0.
 *
 * @param[in]  src   Well-formed descriptor.
 * @param[in]  ndim  Target rank, >= src->ndim.
 * @param[in]  shape Target extents.
 * @param[out] out   Temporary view with ND_WRITEABLE cleared.
 *
 * @return OTI_OK, or OTI_ERR_SHAPE.
 */
int nd_view_broadcast_to(const ndarr_t* src, int32_t ndim, const int64_t* shape, ndarr_t* out);

/**
 * @brief Read-only view of a diagonal (numpy.diagonal(offset, axis1, axis2)); the diagonal becomes
 *        the last axis.
 *
 * @param[in]  src    Well-formed descriptor with ndim >= 2.
 * @param[in]  offset Diagonal offset (> 0 above the main diagonal).
 * @param[in]  axis1  First axis (negative allowed).
 * @param[in]  axis2  Second axis, different from axis1.
 * @param[out] out    Temporary view with ND_WRITEABLE cleared (length 0 when the offset is outside).
 *
 * @return OTI_OK; OTI_ERR_SHAPE (ndim < 2); OTI_ERR_INDEX; OTI_ERR_ARGUMENT (same axis).
 */
int nd_view_diagonal(const ndarr_t* src, int64_t offset, int32_t axis1, int32_t axis2, ndarr_t* out);

/**
 * @brief Reshape as a view, when the strides allow it (NumPy's _attempt_nocopy_reshape rule).
 *
 * @param[in]  src    Well-formed descriptor.
 * @param[in]  ndim   New rank.
 * @param[in]  shape  New extents (one -1 allowed).
 * @param[in]  layout ND_LAYOUT_C, _F or _A (index order).
 * @param[out] out    Temporary view.
 *
 * @return OTI_OK; OTI_ERR_LAYOUT when no view exists (recorded as the last error; nd_reshape()
 *         instead copies, through a private non-recording helper); OTI_ERR_SHAPE; OTI_ERR_SIZE (the
 *         target's non-zero extents overflow int64); OTI_ERR_ARGUMENT.
 */
int nd_view_reshape(const ndarr_t* src, int32_t ndim, const int64_t* shape, int32_t layout,
                    ndarr_t* out);

/** @} */
// -------------------------------------------------------------------------------------------------------


/**
 * @name Advanced indexing (Phase 5)
 * NumPy rules: an OTI_U8 mask is equivalent to its nonzero() integer arrays; integer arrays broadcast
 * together; when the advanced items are adjacent their result axes replace them in place, otherwise
 * they go first (NumPy's axis placement rule). OTI_F64 or any other dtype as an index is
 * OTI_ERR_DTYPE (IndexError in NumPy terms, TypeError here).
 * @{
 */

/**
 * @brief Gathers with a mixed index (copy).
 *
 * @param[in,out] ctx  Context, or NULL.
 * @param[in]     src  Well-formed descriptor.
 * @param[in]     nidx Number of items.
 * @param[in]     idx  Items; at least one ND_IDX_ARRAY.
 * @param[out]    res  New retained C-contiguous array.
 *
 * @return OTI_OK; OTI_ERR_INDEX (out of range, mask shape mismatch); OTI_ERR_SHAPE; OTI_ERR_DTYPE;
 *         statuses of nd_alloc(). Caller must release @p res via nd_release().
 */
int nd_index_get(oti_ctx* ctx, const ndarr_t* src, int32_t nidx, const nd_index_t* idx, ndarr_t* res);

/**
 * @brief Scatters values with a mixed index (dst[idx] = values).
 *
 * values broadcasts to the indexed shape. Duplicate indices: the last write in index order wins; the
 * scatter is serial whenever duplicates are possible. values overlapping dst is first copied
 * (snapshot semantics).
 *
 * @param[in,out] ctx    Context, or NULL.
 * @param[in,out] dst    Writeable destination without internal overlap.
 * @param[in]     nidx   Number of items.
 * @param[in]     idx    Items; at least one ND_IDX_ARRAY.
 * @param[in]     values Values (same dtype as dst, or OTI_U8 / OTI_I64 into OTI_F64).
 *
 * @return OTI_OK; OTI_ERR_READONLY; OTI_ERR_LAYOUT; OTI_ERR_INDEX; OTI_ERR_SHAPE; OTI_ERR_DTYPE;
 *         OTI_ERR_MEMORY.
 */
int nd_index_set(oti_ctx* ctx, ndarr_t* dst, int32_t nidx, const nd_index_t* idx,
                 const ndarr_t* values);

/** @} */
// -------------------------------------------------------------------------------------------------------

#ifdef __cplusplus
}
#endif

#endif
