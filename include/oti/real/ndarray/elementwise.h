#ifndef OTI_REAL_NDARRAY_ELEMENTWISE_H
#define OTI_REAL_NDARRAY_ELEMENTWISE_H

// -------------------------------------------------------------------------------------------------------
// ndarray elementwise operations: arithmetic, math functions, assignment (Phase 1) and comparisons
// into OTI_U8 masks (Phase 2). Sources: src/c/real/ndarray/elementwise.c, functions.c, mask.c.
//
// Rules:
//   - NumPy broadcasting. Arithmetic and functions take and give OTI_F64; comparisons give OTI_U8;
//     logical operations take and give OTI_U8.
//   - IEEE results with no status for division by zero, overflow or invalid operations (NumPy only
//     warns). NaN propagates; maximum / minimum propagate NaN (numpy.maximum, not fmax).
//   - `_to` variants: `out` must have exactly the broadcast shape, the result dtype, ND_WRITEABLE
//     (else OTI_ERR_READONLY) and no internal overlap (else OTI_ERR_LAYOUT). out may be exactly an
//     input (nd_may_share_memory() == ND_SHARE_EXACT); any other possible overlap goes through a
//     temporary charged to the context's temp budget.
//   - Iteration (ND_ITER_ORDER_K, see iter.h): values do not depend on the order, only the memory
//     walk.
//   - Allocating variants: `res` is a new retained, compact array in the K layout of the inputs
//     (NumPy's rule, contracts S24): its axes are ordered as the iterator orders the inputs, so a
//     C, an F or the dense SoA block layout (nblocks, *S) with F order inside a block is kept.
//   - Parallel: elements are cut into chunks of OTI_EXEC_CHUNK_ELEMS; whether to run in parallel is
//     a per-kernel-family threshold from a cost model (contracts S27, Phase 2), never 0 for real
//     kernels; bit-identical at every thread count.
//   - Scalar exponents of POW use NumPy's fast paths: 2 -> x*x, 0.5 -> sqrt(x), -1 -> 1/x, 1 -> x,
//     0 -> 1; any other exponent calls pow().
// -------------------------------------------------------------------------------------------------------

#include "oti/core/exec.h"
#include "oti/real/ndarray/structures.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @name Binary operation codes
 * @{
 */
#define ND_OP_ADD          1  ///< a + b
#define ND_OP_SUB          2  ///< a - b
#define ND_OP_MUL          3  ///< a * b
#define ND_OP_DIV          4  ///< a / b
#define ND_OP_POW          5  ///< pow(a, b)
#define ND_OP_MAXIMUM      6  ///< numpy.maximum (NaN propagates)
#define ND_OP_MINIMUM      7  ///< numpy.minimum (NaN propagates)
#define ND_OP_EQ          16  ///< a == b -> OTI_U8 (Phase 2)
#define ND_OP_NE          17  ///< a != b -> OTI_U8 (Phase 2)
#define ND_OP_LT          18  ///< a <  b -> OTI_U8 (Phase 2)
#define ND_OP_LE          19  ///< a <= b -> OTI_U8 (Phase 2)
#define ND_OP_GT          20  ///< a >  b -> OTI_U8 (Phase 2)
#define ND_OP_GE          21  ///< a >= b -> OTI_U8 (Phase 2)
#define ND_OP_AND         24  ///< mask & mask (Phase 2)
#define ND_OP_OR          25  ///< mask | mask (Phase 2)
#define ND_OP_XOR         26  ///< mask ^ mask (Phase 2)
/** @} */
// -------------------------------------------------------------------------------------------------------


/**
 * @name Unary function codes
 * The libm function of the same name, element by element (no vector math library).
 * @{
 */
#define ND_FN_NEG          1  ///< -x
#define ND_FN_ABS          2  ///< fabs
#define ND_FN_SQRT         3  ///< sqrt
#define ND_FN_CBRT         4  ///< cbrt
#define ND_FN_EXP          5  ///< exp
#define ND_FN_EXP2         6  ///< exp2
#define ND_FN_EXPM1        7  ///< expm1
#define ND_FN_LOG          8  ///< log
#define ND_FN_LOG2         9  ///< log2
#define ND_FN_LOG10       10  ///< log10
#define ND_FN_LOG1P       11  ///< log1p
#define ND_FN_SIN         12  ///< sin
#define ND_FN_COS         13  ///< cos
#define ND_FN_TAN         14  ///< tan
#define ND_FN_ASIN        15  ///< asin (numpy.arcsin)
#define ND_FN_ACOS        16  ///< acos
#define ND_FN_ATAN        17  ///< atan
#define ND_FN_SINH        18  ///< sinh
#define ND_FN_COSH        19  ///< cosh
#define ND_FN_TANH        20  ///< tanh
#define ND_FN_ASINH       21  ///< asinh
#define ND_FN_ACOSH       22  ///< acosh
#define ND_FN_ATANH       23  ///< atanh
#define ND_FN_FLOOR       24  ///< floor
#define ND_FN_CEIL        25  ///< ceil
#define ND_FN_TRUNC       26  ///< trunc
#define ND_FN_RINT        27  ///< rint (round half to even, as numpy.rint)
#define ND_FN_SQUARE      28  ///< x*x
#define ND_FN_RECIPROCAL  29  ///< 1/x
#define ND_FN_SIGN        30  ///< numpy.sign: -1, +1, NaN for NaN, +0.0 for both zeros
#define ND_FN_NOT         40  ///< logical not of an OTI_U8 mask (Phase 2)
/** @} */
// -------------------------------------------------------------------------------------------------------


/**
 * @name Binary operations
 * @{
 */

/**
 * @brief out = a (op) b, broadcasting.
 *
 * @param[in,out] ctx Context, or NULL.
 * @param[in]     op  ND_OP_*.
 * @param[in]     a   Left operand.
 * @param[in]     b   Right operand.
 * @param[in,out] out Existing output (see the rules above).
 *
 * @return OTI_OK; OTI_ERR_ARGUMENT (unknown op); OTI_ERR_DTYPE; OTI_ERR_SHAPE; OTI_ERR_READONLY;
 *         OTI_ERR_LAYOUT; OTI_ERR_MEMORY (overlap temporary).
 */
int nd_binary_to(oti_ctx* ctx, int32_t op, const ndarr_t* a, const ndarr_t* b, ndarr_t* out);

/**
 * @brief res = a (op) b in a new array.
 *
 * @param[in,out] ctx Context, or NULL.
 * @param[in]     op  ND_OP_*.
 * @param[in]     a   Left operand.
 * @param[in]     b   Right operand.
 * @param[out]    res New retained array.
 *
 * @return As nd_binary_to(), plus the statuses of nd_alloc(). Caller must release @p res via
 *         nd_release().
 */
int nd_binary(oti_ctx* ctx, int32_t op, const ndarr_t* a, const ndarr_t* b, ndarr_t* res);

/**
 * @brief out = a (op) s, or s (op) a, with a real scalar.
 *
 * @param[in,out] ctx         Context, or NULL.
 * @param[in]     op          ND_OP_* (arithmetic or comparison).
 * @param[in]     a           Array operand.
 * @param[in]     s           Scalar operand.
 * @param[in]     scalar_left 1 for s (op) a, 0 for a (op) s.
 * @param[in,out] out         Existing output with a's shape.
 *
 * @return As nd_binary_to().
 */
int nd_binary_scalar_to(oti_ctx* ctx, int32_t op, const ndarr_t* a, double s, int32_t scalar_left,
                        ndarr_t* out);

/**
 * @brief res = a (op) s, or s (op) a, in a new array.
 *
 * @param[in,out] ctx         Context, or NULL.
 * @param[in]     op          ND_OP_*.
 * @param[in]     a           Array operand.
 * @param[in]     s           Scalar operand.
 * @param[in]     scalar_left 1 for s (op) a, 0 for a (op) s.
 * @param[out]    res         New retained array.
 *
 * @return As nd_binary(). Caller must release @p res via nd_release().
 */
int nd_binary_scalar(oti_ctx* ctx, int32_t op, const ndarr_t* a, double s, int32_t scalar_left,
                     ndarr_t* res);

/** @} */
// -------------------------------------------------------------------------------------------------------


/**
 * @name Unary functions
 * @{
 */

/**
 * @brief out = fn(a).
 *
 * @param[in,out] ctx Context, or NULL.
 * @param[in]     fn  ND_FN_*.
 * @param[in]     a   Operand.
 * @param[in,out] out Existing output with a's shape.
 *
 * @return OTI_OK; OTI_ERR_ARGUMENT; OTI_ERR_DTYPE; OTI_ERR_SHAPE; OTI_ERR_READONLY; OTI_ERR_LAYOUT;
 *         OTI_ERR_MEMORY.
 */
int nd_unary_to(oti_ctx* ctx, int32_t fn, const ndarr_t* a, ndarr_t* out);

/**
 * @brief res = fn(a) in a new array.
 *
 * @param[in,out] ctx Context, or NULL.
 * @param[in]     fn  ND_FN_*.
 * @param[in]     a   Operand.
 * @param[out]    res New retained array.
 *
 * @return As nd_unary_to(), plus the statuses of nd_alloc(). Caller must release @p res via
 *         nd_release().
 */
int nd_unary(oti_ctx* ctx, int32_t fn, const ndarr_t* a, ndarr_t* res);

/** @} */
// -------------------------------------------------------------------------------------------------------


/**
 * @name Assignment
 * @{
 */

/**
 * @brief dst[...] = src with broadcasting and snapshot semantics.
 *
 * The result is as if src were copied first: a possible overlap (ND_SHARE_MAYBE) goes through a
 * temporary; an exact alias is a no-op. Same dtype, or OTI_U8 / OTI_I64 into OTI_F64 (numeric
 * conversion); anything else is OTI_ERR_DTYPE.
 *
 * @param[in,out] ctx Context, or NULL.
 * @param[in]     src Source; broadcasts to dst's shape.
 * @param[in,out] dst Writeable destination without internal overlap.
 *
 * @return OTI_OK; OTI_ERR_SHAPE; OTI_ERR_DTYPE; OTI_ERR_READONLY; OTI_ERR_LAYOUT; OTI_ERR_MEMORY.
 */
int nd_assign(oti_ctx* ctx, const ndarr_t* src, ndarr_t* dst);

/**
 * @brief dst[...] = value.
 *
 * @param[in,out] ctx   Context, or NULL.
 * @param[in,out] dst   Writeable destination (OTI_F64) without internal overlap.
 * @param[in]     value Value.
 *
 * @return OTI_OK; OTI_ERR_DTYPE; OTI_ERR_READONLY; OTI_ERR_LAYOUT.
 */
int nd_fill(oti_ctx* ctx, ndarr_t* dst, double value);

/** @} */
// -------------------------------------------------------------------------------------------------------

#ifdef __cplusplus
}
#endif

#endif
