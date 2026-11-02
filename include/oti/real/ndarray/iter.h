#ifndef OTI_REAL_NDARRAY_ITER_H
#define OTI_REAL_NDARRAY_ITER_H

// -------------------------------------------------------------------------------------------------------
// Multi-operand strided iterator (Phase 1, src/c/real/ndarray/iter.c).
//
// nd_iter_init() broadcasts the operands to one iteration shape, drops axes of extent 1, chooses the
// axis order and coalesces adjacent axes that are contiguous for every operand. The iteration space
// is then walked in its own linear order by nd_iter_run(), which hands the inner function runs along
// the innermost axis. A run never crosses a chunk boundary, so a kernel cut into fixed logical chunks
// of OTI_EXEC_CHUNK_ELEMS elements (chunk c = [c*CH, min((c+1)*CH, size))) visits every element in the
// same code path whatever the thread count (determinism, include/oti/core/exec.h).
// The iterator works in BYTES (operands may have different dtypes) and is a stack object (~2.4 KiB):
// it holds no reference and allocates nothing.
// -------------------------------------------------------------------------------------------------------

#include "oti/real/ndarray/structures.h"

#ifdef __cplusplus
extern "C" {
#endif

// -------------------------------------------------------------------------------------------------------
// --------------------------------------      CONSTANTS         -----------------------------------------
// -------------------------------------------------------------------------------------------------------

/** @brief Maximum number of operands of one iterator. */
#define ND_ITER_MAXOPS 8

/**
 * @name Operand flags (nd_iter_init())
 * @{
 */
#define ND_ITER_IN          0x1 ///< Read; broadcasts to the iteration shape.
#define ND_ITER_OUT         0x2 ///< Written; must have exactly the iteration shape, be ND_WRITEABLE
                                ///< and free of internal overlap.
#define ND_ITER_REDUCE_OUT  0x4 ///< Written reduction target: may have stride 0 on reduced axes.
/** @} */

/**
 * @name Iteration orders (nd_iter_init())
 * @{
 */
#define ND_ITER_ORDER_C  0 ///< Logical row-major order of the iteration shape.
#define ND_ITER_ORDER_K  1 ///< Memory order of the driving operand: the operand with the most
                           ///< axes of non-zero stride (ties: the lowest operand index, so the
                           ///< output of a `_to` call wins a tie); axes by decreasing |byte
                           ///< stride| of that operand, ties by axis index (contracts S26).
/** @} */
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// --------------------------------------      STRUCTURES        -----------------------------------------
// -------------------------------------------------------------------------------------------------------

/**
 * @brief Prepared iteration over up to ND_ITER_MAXOPS operands.
 *
 * After nd_iter_init(): axes are ordered outermost first, innermost last; ndim >= 1 (a rank-0 or
 * single-element iteration has one axis of extent 1 or 0).
 */
typedef struct {
    int32_t  nop;                                     ///< Number of operands.
    int32_t  ndim;                                    ///< Axes after coalescing, >= 1.
    int64_t  size;                                    ///< Total elements of the iteration space.
    int64_t  shape[OTI_ND_MAXDIM];                    ///< Extents, innermost last.
    int64_t  bstrides[OTI_ND_MAXDIM][ND_ITER_MAXOPS]; ///< Byte strides, [axis][operand]: one
                                                      ///< cache line per axis (contracts S26).
    char*    data[ND_ITER_MAXOPS];                    ///< Byte pointer of element 0 per operand.
    int32_t  itemsize[ND_ITER_MAXOPS];                ///< Bytes per element per operand.
    int32_t  perm[OTI_ND_MAXDIM];                     ///< Source axis of each kept axis (extent > 1)
                                                      ///< in iteration order, before coalescing;
                                                      ///< entries past the kept axes are unspecified
                                                      ///< (diagnostics and tests).
} nd_iter_t;

/**
 * @brief Inner loop called by nd_iter_run().
 *
 * @param[in,out] arg      Caller data.
 * @param[in]     n        Elements in this run, >= 1.
 * @param[in]     ptrs     nop byte pointers of the run's first element.
 * @param[in]     bstrides nop byte strides along the run.
 *
 * @return OTI_OK, or a status that stops the walk.
 */
typedef int (*nd_inner_fn)(void* arg, int64_t n, char* const* ptrs, const int64_t* bstrides);

// -------------------------------------------------------------------------------------------------------
// -------------------------------------    END STRUCTURES      ------------------------------------------
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Prepares an iteration.
 *
 * The iteration shape is the broadcast of the ND_ITER_IN operands and must equal the shape of every
 * ND_ITER_OUT operand; an ND_ITER_REDUCE_OUT operand broadcasts (its stride-0 axes are the reduced
 * axes). Axes of extent 1 are dropped and adjacent axes merged when every operand's byte strides
 * allow it. Negative strides are kept (no axis flipping).
 *
 * @param[out] it       Iterator.
 * @param[in]  nop      1 .. ND_ITER_MAXOPS.
 * @param[in]  ops      Operands (well-formed).
 * @param[in]  op_flags One ND_ITER_* flag per operand.
 * @param[in]  order    ND_ITER_ORDER_C or ND_ITER_ORDER_K.
 *
 * @return OTI_OK; OTI_ERR_SHAPE (broadcast failure, output shape mismatch); OTI_ERR_SIZE (the
 *         broadcast element count overflows int64); OTI_ERR_READONLY; OTI_ERR_LAYOUT (an output
 *         with internal overlap); OTI_ERR_ARGUMENT (NULL, nop, flags, order, unknown dtype).
 */
int nd_iter_init(nd_iter_t* it, int32_t nop, const ndarr_t* const* ops, const int32_t* op_flags,
                 int32_t order);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Walks the linear range [start, start + count) of the iteration space.
 *
 * Calls @p fn once per maximal run along the innermost axis inside the range, in increasing linear
 * order. Stops at the first non-OTI_OK return and returns it.
 *
 * @param[in]     it    Prepared iterator.
 * @param[in]     start First linear index, 0 <= start <= it->size.
 * @param[in]     count Number of elements, start + count <= it->size.
 * @param[in]     fn    Inner function.
 * @param[in,out] arg   Passed to @p fn.
 *
 * @return OTI_OK, the first failing status of @p fn, OTI_ERR_INDEX for a range outside the space,
 *         or OTI_ERR_ARGUMENT for a NULL iterator or function.
 */
int nd_iter_run(const nd_iter_t* it, int64_t start, int64_t count, nd_inner_fn fn, void* arg);
// -------------------------------------------------------------------------------------------------------

#ifdef __cplusplus
}
#endif

#endif
