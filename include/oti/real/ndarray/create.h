#ifndef OTI_REAL_NDARRAY_CREATE_H
#define OTI_REAL_NDARRAY_CREATE_H

// -------------------------------------------------------------------------------------------------------
// ndarray creators, copies and view-or-copy conversions (Phase 1; src/c/real/ndarray/create.c).
// All creators make OTI_F64 arrays through nd_alloc(); `res` is a new retained array that the caller
// releases with nd_release(). Values follow NumPy (numpy.arange, numpy.linspace, numpy.eye, ...).
// -------------------------------------------------------------------------------------------------------

#include "oti/core/exec.h"
#include "oti/real/ndarray/structures.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @name Filled creators
 * Each makes a new OTI_F64 array of the given shape in ND_LAYOUT_C or ND_LAYOUT_F.
 * Statuses: OTI_OK, or those of nd_alloc().
 * @{
 */

/**
 * @brief New array with unspecified values (numpy.empty).
 *
 * @param[in,out] ctx    Context, or NULL.
 * @param[in]     ndim   0 .. OTI_ND_MAXDIM.
 * @param[in]     shape  ndim extents, >= 0.
 * @param[in]     layout ND_LAYOUT_C or ND_LAYOUT_F.
 * @param[out]    res    New retained array.
 *
 * @return Status of nd_alloc(). Caller must release @p res via nd_release().
 */
int nd_empty(oti_ctx* ctx, int32_t ndim, const int64_t* shape, int32_t layout, ndarr_t* res);

/**
 * @brief New array of the shape and dtype of @p src in its K layout (numpy.empty_like, S24).
 *
 * The axes are ordered by decreasing |stride| of @p src (ties by axis index) and the array is
 * compact, so C, F and the dense SoA block layout are kept; zero and negative strides become a
 * compact positive layout.
 *
 * @param[in,out] ctx         Context, or NULL.
 * @param[in]     src         Well-formed array (only shape, strides and dtype are read).
 * @param[in]     alloc_flags ND_ALLOC_ZERO | ND_ALLOC_GROWABLE.
 * @param[out]    res         New retained array.
 *
 * @return Status of nd_alloc_strided(). Caller must release @p res via nd_release().
 */
int nd_empty_like(oti_ctx* ctx, const ndarr_t* src, int32_t alloc_flags, ndarr_t* res);

/**
 * @brief New array of zeros (numpy.zeros).
 *
 * @param[in,out] ctx    Context, or NULL.
 * @param[in]     ndim   0 .. OTI_ND_MAXDIM.
 * @param[in]     shape  ndim extents, >= 0.
 * @param[in]     layout ND_LAYOUT_C or ND_LAYOUT_F.
 * @param[out]    res    New retained array.
 *
 * @return Status of nd_alloc(). Caller must release @p res via nd_release().
 */
int nd_zeros(oti_ctx* ctx, int32_t ndim, const int64_t* shape, int32_t layout, ndarr_t* res);

/**
 * @brief New array of ones (numpy.ones).
 *
 * @param[in,out] ctx    Context, or NULL.
 * @param[in]     ndim   0 .. OTI_ND_MAXDIM.
 * @param[in]     shape  ndim extents, >= 0.
 * @param[in]     layout ND_LAYOUT_C or ND_LAYOUT_F.
 * @param[out]    res    New retained array.
 *
 * @return Status of nd_alloc(). Caller must release @p res via nd_release().
 */
int nd_ones(oti_ctx* ctx, int32_t ndim, const int64_t* shape, int32_t layout, ndarr_t* res);

/**
 * @brief New array filled with a value (numpy.full).
 *
 * @param[in,out] ctx    Context, or NULL.
 * @param[in]     ndim   0 .. OTI_ND_MAXDIM.
 * @param[in]     shape  ndim extents, >= 0.
 * @param[in]     value  Fill value (NaN and signed zeros are stored as given).
 * @param[in]     layout ND_LAYOUT_C or ND_LAYOUT_F.
 * @param[out]    res    New retained array.
 *
 * @return Status of nd_alloc(). Caller must release @p res via nd_release().
 */
int nd_full(oti_ctx* ctx, int32_t ndim, const int64_t* shape, double value, int32_t layout,
            ndarr_t* res);

/** @} */
// -------------------------------------------------------------------------------------------------------


/**
 * @brief New n x m array with ones on diagonal k and zeros elsewhere (numpy.eye(n, m, k)).
 *
 * @param[in,out] ctx    Context, or NULL.
 * @param[in]     n      Rows, >= 0.
 * @param[in]     m      Columns, >= 0 (numpy's M=None is m = n).
 * @param[in]     k      Diagonal offset (> 0 above the main diagonal); any value.
 * @param[in]     layout ND_LAYOUT_C or ND_LAYOUT_F.
 * @param[out]    res    New retained 2-D array.
 *
 * @return OTI_OK; OTI_ERR_SHAPE (negative n or m); statuses of nd_alloc(). Caller must release @p res
 *         via nd_release().
 */
int nd_eye(oti_ctx* ctx, int64_t n, int64_t m, int64_t k, int32_t layout, ndarr_t* res);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief New 1-D array of evenly spaced values in [start, stop) (numpy.arange for floats).
 *
 * Length n = max(0, ceil((stop - start) / step)). Values follow NumPy's fill: y[0] = start,
 * y[1] = start + step, delta = y[1] - y[0] (the rounded effective increment), and y[i] = start +
 * i * delta for i >= 2. So np.arange(1e16, 1e16 + 10, 1) - 1e16 is ten zeros here too.
 *
 * @param[in,out] ctx   Context, or NULL.
 * @param[in]     start First value.
 * @param[in]     stop  End of the interval (excluded).
 * @param[in]     step  Spacing, not zero.
 * @param[out]    res   New retained 1-D array.
 *
 * @return OTI_OK; OTI_ERR_ARGUMENT (step 0, or a non-finite argument); OTI_ERR_SIZE (length above
 *         INT64_MAX); statuses of nd_alloc(). Caller must release @p res via nd_release().
 */
int nd_arange(oti_ctx* ctx, double start, double stop, double step, ndarr_t* res);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief New 1-D array of @p num evenly spaced values (numpy.linspace).
 *
 * NumPy's formula: div = endpoint ? num - 1 : num; step = (stop - start) / div; y[i] = i * step +
 * start when step != 0, else y[i] = (i / div) * (stop - start) + start; y[num-1] = stop when endpoint
 * and num > 1. num == 1 gives [start].
 *
 * @param[in,out] ctx      Context, or NULL.
 * @param[in]     start    First value.
 * @param[in]     stop     Last value (included when endpoint is 1).
 * @param[in]     num      Number of values, >= 0.
 * @param[in]     endpoint 1 to include stop, 0 to exclude it.
 * @param[out]    res      New retained 1-D array.
 *
 * @return OTI_OK; OTI_ERR_ARGUMENT (num < 0); statuses of nd_alloc(). Caller must release @p res via
 *         nd_release().
 */
int nd_linspace(oti_ctx* ctx, double start, double stop, int64_t num, int32_t endpoint, ndarr_t* res);
// -------------------------------------------------------------------------------------------------------


/**
 * @name Copies and view-or-copy conversions
 * @{
 */

/**
 * @brief New array with a copy of the values (numpy.array(copy=True, order=...)).
 *
 * ND_LAYOUT_K keeps the axis order of the source's memory (axes sorted by decreasing |stride|, ties
 * by axis index) with positive strides; ND_LAYOUT_A is F for an F- and not C-contiguous source, else
 * C. The dtype is kept.
 *
 * @param[in,out] ctx    Context, or NULL.
 * @param[in]     src    Well-formed descriptor.
 * @param[in]     layout ND_LAYOUT_C, _F, _A or _K.
 * @param[out]    res    New retained array.
 *
 * @return OTI_OK, OTI_ERR_ARGUMENT (layout), statuses of nd_alloc(). Caller must release @p res via
 *         nd_release().
 */
int nd_copy(oti_ctx* ctx, const ndarr_t* src, int32_t layout, ndarr_t* res);

/**
 * @brief C-contiguous version of an array: a retained view when it already is, else a C copy
 *        (numpy.ascontiguousarray; rank 0 stays rank 0).
 *
 * @param[in,out] ctx    Context, or NULL.
 * @param[in]     src    Well-formed descriptor. A view needs src->buf != NULL; a trusted temporary
 *                       (buf NULL) is always copied.
 * @param[out]    res    Retained array.
 * @param[out]    copied 1 if a copy was made, 0 for a view. May be NULL.
 *
 * @return OTI_OK, statuses of nd_view_retain() and nd_alloc(). Caller must release @p res via
 *         nd_release().
 */
int nd_ascontiguous(oti_ctx* ctx, const ndarr_t* src, ndarr_t* res, int32_t* copied);

/**
 * @brief F-contiguous version of an array: a retained view when it already is, else an F copy
 *        (numpy.asfortranarray).
 *
 * @param[in,out] ctx    Context, or NULL.
 * @param[in]     src    Well-formed descriptor (trusted temporaries are always copied).
 * @param[out]    res    Retained array.
 * @param[out]    copied 1 if a copy was made, 0 for a view. May be NULL.
 *
 * @return OTI_OK, statuses of nd_view_retain() and nd_alloc(). Caller must release @p res via
 *         nd_release().
 */
int nd_asfortran(oti_ctx* ctx, const ndarr_t* src, ndarr_t* res, int32_t* copied);

/**
 * @brief Reshapes: a retained view when nd_view_reshape() can express it, else a copy
 *        (numpy.reshape; one extent may be -1).
 *
 * @param[in,out] ctx    Context, or NULL.
 * @param[in]     src    Well-formed descriptor.
 * @param[in]     ndim   New rank, 0 .. OTI_ND_MAXDIM.
 * @param[in]     shape  New extents; at most one -1 (inferred).
 * @param[in]     layout Index order: ND_LAYOUT_C, _F or _A ('K' is not valid for reshape, as in NumPy).
 * @param[out]    res    Retained array.
 * @param[out]    copied 1 if a copy was made, 0 for a view. May be NULL.
 *
 * @return OTI_OK; OTI_ERR_SHAPE (sizes differ, several -1, -1 with a zero-size remainder);
 *         OTI_ERR_ARGUMENT (layout); statuses of nd_alloc(). Caller must release @p res via
 *         nd_release().
 */
int nd_reshape(oti_ctx* ctx, const ndarr_t* src, int32_t ndim, const int64_t* shape, int32_t layout,
               ndarr_t* res, int32_t* copied);

/** @} */
// -------------------------------------------------------------------------------------------------------

#ifdef __cplusplus
}
#endif

#endif
