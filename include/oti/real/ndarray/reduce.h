#ifndef OTI_REAL_NDARRAY_REDUCE_H
#define OTI_REAL_NDARRAY_REDUCE_H

// -------------------------------------------------------------------------------------------------------
// ndarray reductions (Phase 2, src/c/real/ndarray/reduce.c).
//
// Determinism (include/oti/core/exec.h): for each output element the reduced elements are taken in
// the order of an ND_ITER_ORDER_K iteration of the input (operand 0 = the input) restricted to the
// reduced axes, cut into
// fixed blocks of OTI_EXEC_CHUNK_ELEMS elements; each block is reduced by nd_pairwise_sum() (or the
// sequential min / max / arg scan), and the block results are combined by a fixed pairwise tree in
// block order. The result is a function of (values, input layout, axes, build) only: identical for
// the serial, OpenMP and pthreads paths and every thread count. Parallel work is split over output
// elements or over blocks, never changing the tree.
//
// Exception: ARGMIN / ARGMAX scan the reduced elements in LOGICAL C order (not K order), so the
// first occurrence of an extremum or a NaN is the lowest C-order index, as NumPy returns.
//
// Edge semantics (NumPy): a SUM starts from the identity: the result is (+0.0) + the block tree, so
// the sum of negative zeros is +0.0, as np.sum([-0.0]); an empty sum is 0 and an empty prod 1;
// empty min / max / argmin / argmax fail with OTI_ERR_SHAPE; an empty mean is NaN; NaN propagates
// through min / max; argmin / argmax return the first occurrence in C order (the first NaN when
// there is one); var is two-pass (mean, then the sum of squared deviations) divided by
// max(N - ddof, 0), IEEE inf / NaN when that is 0; std is sqrt(var). For contiguous 1-D inputs of at
// most OTI_EXEC_CHUNK_ELEMS elements the sum agrees bitwise with np.sum (NumPy applies its pairwise
// scheme to the whole contiguous input); otherwise it agrees to rounding (NumPy neither blocks at
// 4096 nor combines partials with this tree).
// An output that may overlap the input is computed into a temporary and copied (as numpy.sum with
// out= does).
// -------------------------------------------------------------------------------------------------------

#include "oti/core/exec.h"
#include "oti/real/ndarray/structures.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @name Reduction codes
 * @{
 */
#define ND_RED_SUM      1  ///< Sum (pairwise).
#define ND_RED_PROD     2  ///< Product (pairwise tree).
#define ND_RED_MIN      3  ///< Minimum (NaN propagates).
#define ND_RED_MAX      4  ///< Maximum (NaN propagates).
#define ND_RED_MEAN     5  ///< sum / N.
#define ND_RED_VAR      6  ///< Two-pass variance with ddof.
#define ND_RED_STD      7  ///< sqrt(var).
#define ND_RED_ARGMIN   8  ///< First minimum in C order -> OTI_I64 (one axis, or the flattened array).
#define ND_RED_ARGMAX   9  ///< First maximum in C order -> OTI_I64.
#define ND_RED_ANY     10  ///< Any nonzero -> OTI_U8 (input OTI_F64 or OTI_U8).
#define ND_RED_ALL     11  ///< All nonzero -> OTI_U8.
/** @} */
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Reduces over axes into a new array (numpy.<op>(a, axis=axes, keepdims=...)).
 *
 * @param[in,out] ctx      Context, or NULL.
 * @param[in]     op       ND_RED_*.
 * @param[in]     a        Input (OTI_F64; OTI_U8 also for ANY / ALL).
 * @param[in]     naxes    Number of axes, or -1 for all axes (ARGMIN / ARGMAX: -1 means the index in the
 *                         flattened C-order array, as numpy.argmax(axis=None)). 0 reduces nothing.
 * @param[in]     axes     Axes (negative allowed, no repeats), or NULL with naxes -1.
 * @param[in]     keepdims 1 to keep reduced axes with extent 1.
 * @param[in]     ddof     Delta degrees of freedom (VAR, STD); ignored otherwise.
 * @param[out]    res      New retained array (rank 0 for a full reduction without keepdims).
 *
 * @return OTI_OK; OTI_ERR_ARGUMENT (op, repeated axis, ARGMIN / ARGMAX over several axes);
 *         OTI_ERR_INDEX (axis); OTI_ERR_DTYPE; OTI_ERR_SHAPE (empty min / max / arg*); statuses of
 *         nd_alloc(). Caller must release @p res via nd_release().
 */
int nd_reduce(oti_ctx* ctx, int32_t op, const ndarr_t* a, int32_t naxes, const int32_t* axes,
              int32_t keepdims, int64_t ddof, ndarr_t* res);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Reduces over axes into an existing output.
 *
 * @param[in,out] ctx      Context, or NULL.
 * @param[in]     op       ND_RED_*.
 * @param[in]     a        Input.
 * @param[in]     naxes    As nd_reduce().
 * @param[in]     axes     As nd_reduce().
 * @param[in]     keepdims Shape convention of @p out.
 * @param[in]     ddof     As nd_reduce().
 * @param[in,out] out      Writeable output of exactly the reduced shape and result dtype, free of
 *                         internal overlap; it may overlap @p a (then a temporary is used).
 *
 * @return As nd_reduce(), plus OTI_ERR_SHAPE (out shape), OTI_ERR_READONLY, OTI_ERR_LAYOUT (internal
 *         overlap of out), OTI_ERR_MEMORY (the overlap temporary).
 */
int nd_reduce_to(oti_ctx* ctx, int32_t op, const ndarr_t* a, int32_t naxes, const int32_t* axes,
                 int32_t keepdims, int64_t ddof, ndarr_t* out);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief The fixed in-block summation: NumPy's pairwise scheme.
 *
 * n < 8: sequential sum starting from +0.0. 8 <= n <= 128: eight accumulators r[j] = x[j], then
 * r[j] += x[j + 8i] over the largest multiple of 8, combined as
 * ((r0 + r1) + (r2 + r3)) + ((r4 + r5) + (r6 + r7)), then the remainder added sequentially.
 * n > 128: split at n2 = (n / 2) rounded down to a multiple of 8, sum both halves recursively, add.
 * nd_reduce(ND_RED_SUM) adds the identity last ((+0.0) + tree), which makes the sum of negative zeros
 * +0.0 for every n, as NumPy (whose reduction also starts from the identity).
 *
 * @param[in] x      First element.
 * @param[in] n      Number of elements, >= 0.
 * @param[in] stride Stride in elements (any sign).
 *
 * @return The block sum (+0.0 for n == 0).
 */
double nd_pairwise_sum(const double* x, int64_t n, int64_t stride);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Combines block results with the fixed pairwise tree (block order, halves split at n/2).
 *
 * @param[in] partials Block results in block order.
 * @param[in] n        Number of blocks, >= 1.
 * @param[in] op       ND_RED_SUM or ND_RED_PROD.
 *
 * @return The combined value.
 */
double nd_tree_combine(const double* partials, int64_t n, int32_t op);
// -------------------------------------------------------------------------------------------------------

#ifdef __cplusplus
}
#endif

#endif
