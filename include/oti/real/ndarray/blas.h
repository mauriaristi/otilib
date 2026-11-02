#ifndef OTI_REAL_NDARRAY_BLAS_H
#define OTI_REAL_NDARRAY_BLAS_H

// -------------------------------------------------------------------------------------------------------
// ndarray BLAS dispatch: products and level-1/2 helpers (Phase 3, src/c/real/ndarray/blas.c).
// Every call goes through the C wrappers of include/oti/core/lapack.h (never a vendor symbol).
//
// Dispatch rules (PLAN-ndarray-contracts.md section 9):
//   - A 2-D operand (n0, n1) with element strides (s0, s1) is used directly as
//       'N' when (n0 <= 1 or s0 == 1) and (n1 <= 1 or s1 >= max(1, n0)): ld = n1 <= 1 ? max(1, n0) : s1;
//       'T' when (n1 <= 1 or s1 == 1) and (n0 <= 1 or s0 >= max(1, n1)): ld = n0 <= 1 ? max(1, n1) : s0;
//     preferring 'N'; otherwise it is packed into an F-order temporary ('N', ld = max(1, n0)).
//   - Output C (m, n): 'N'-usable -> direct; else 'T'-usable -> C^T = B^T A^T (operands swapped,
//     transposes flipped); else an F-order temporary, copied out (C is copied in first when
//     beta != 0).
//   - m == 0 or n == 0: no call. k == 0: no call, C = (beta == 0 ? 0 : beta * C). Every leading
//     dimension passed is >= max(1, rows), also for empty matrices (no XERBLA reachable).
//   - Level 1: ddot, daxpy, dcopy, dswap take negative strides directly (pointer = lowest address,
//     data + (n-1)*stride, with the negative inc); dnrm2, dscal, dasum, idamax, and the vectors of
//     dgemv / dger, need inc > 0 and pack otherwise. Zero strides always pack (n > 1).
//   - Every dimension, leading dimension and increment passes oti_lapack_fits_i64() (else
//     OTI_ERR_SIZE); packs and temporaries are checked with oti_ctx_check_temp().
//   - Provider-level calls never get an output overlapping an input. nd_matmul_to() and nd_dot_to()
//     handle an overlapping `out` (ND_SHARE_MAYBE or EXACT) with a temporary, as numpy.matmul does;
//     nd_gemm(), nd_gemv(), nd_ger() and the level-1 functions reject one with OTI_ERR_LAYOUT.
//   - Batched matmul loops over the broadcast batch axes in C order with oti_parallel_for_blas().
// -------------------------------------------------------------------------------------------------------

#include "oti/core/exec.h"
#include "oti/real/ndarray/structures.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @name Products
 * @{
 */

/**
 * @brief numpy.matmul into a new array: 1-D operands are promoted (prepend / append an axis, removed
 *        afterwards); leading axes broadcast; rank-0 operands are OTI_ERR_SHAPE.
 *
 * @param[in,out] ctx Context, or NULL.
 * @param[in]     a   OTI_F64, ndim >= 1.
 * @param[in]     b   OTI_F64, ndim >= 1.
 * @param[out]    res New retained C-contiguous array.
 *
 * @return OTI_OK; OTI_ERR_SHAPE; OTI_ERR_DTYPE; OTI_ERR_SIZE; OTI_ERR_MEMORY. Caller must release @p res
 *         via nd_release().
 */
int nd_matmul(oti_ctx* ctx, const ndarr_t* a, const ndarr_t* b, ndarr_t* res);

/**
 * @brief numpy.matmul into an existing output.
 *
 * @param[in,out] ctx Context, or NULL.
 * @param[in]     a   OTI_F64, ndim >= 1.
 * @param[in]     b   OTI_F64, ndim >= 1.
 * @param[in,out] out Writeable OTI_F64 output of exactly the result shape; may overlap a or b.
 *
 * @return As nd_matmul(), plus OTI_ERR_READONLY and OTI_ERR_LAYOUT (internal overlap of out).
 */
int nd_matmul_to(oti_ctx* ctx, const ndarr_t* a, const ndarr_t* b, ndarr_t* out);

/**
 * @brief numpy.dot for ndim <= 2 into a new array (0-D: scalar product; 1-D . 1-D: ddot; 2-D . 1-D
 *        and 1-D . 2-D: dgemv; 2-D . 2-D: dgemm). N-D dot (tensordot) is a later phase.
 *
 * @param[in,out] ctx Context, or NULL.
 * @param[in]     a   OTI_F64, ndim <= 2.
 * @param[in]     b   OTI_F64, ndim <= 2.
 * @param[out]    res New retained array (rank 0 for 1-D . 1-D).
 *
 * @return OTI_OK; OTI_ERR_SHAPE (mismatch, or ndim > 2); OTI_ERR_DTYPE; OTI_ERR_SIZE; OTI_ERR_MEMORY.
 *         Caller must release @p res via nd_release().
 */
int nd_dot(oti_ctx* ctx, const ndarr_t* a, const ndarr_t* b, ndarr_t* res);

/**
 * @brief numpy.dot for ndim <= 2 into an existing output (numpy.dot(a, b, out=out)).
 *
 * @param[in,out] ctx Context, or NULL.
 * @param[in]     a   OTI_F64, ndim <= 2.
 * @param[in]     b   OTI_F64, ndim <= 2.
 * @param[in,out] out Writeable OTI_F64 output of exactly the result shape (rank 0 for 1-D . 1-D), free
 *                    of internal overlap; it may overlap a or b (then a temporary is used).
 *
 * @return As nd_dot(), plus OTI_ERR_READONLY and OTI_ERR_LAYOUT (internal overlap of out).
 */
int nd_dot_to(oti_ctx* ctx, const ndarr_t* a, const ndarr_t* b, ndarr_t* out);

/**
 * @brief General product on 2-D views: c = alpha op(a) op(b) + beta c (dgemm with the layout rules).
 *
 * @param[in,out] ctx    Context, or NULL.
 * @param[in]     transa 1 to use a^T.
 * @param[in]     transb 1 to use b^T.
 * @param[in]     alpha  Scalar.
 * @param[in]     a      2-D OTI_F64.
 * @param[in]     b      2-D OTI_F64.
 * @param[in]     beta   Scalar; 0 means c is not read.
 * @param[in,out] c      2-D writeable OTI_F64, not overlapping a or b (else OTI_ERR_LAYOUT).
 *
 * @return OTI_OK; OTI_ERR_SHAPE; OTI_ERR_DTYPE; OTI_ERR_READONLY; OTI_ERR_LAYOUT; OTI_ERR_SIZE;
 *         OTI_ERR_MEMORY.
 */
int nd_gemm(oti_ctx* ctx, int32_t transa, int32_t transb, double alpha, const ndarr_t* a,
            const ndarr_t* b, double beta, ndarr_t* c);

/**
 * @brief Matrix-vector product: y = alpha op(a) x + beta y (dgemv).
 *
 * @param[in,out] ctx   Context, or NULL.
 * @param[in]     trans 1 to use a^T.
 * @param[in]     alpha Scalar.
 * @param[in]     a     2-D OTI_F64.
 * @param[in]     x     1-D OTI_F64.
 * @param[in]     beta  Scalar; 0 means y is not read.
 * @param[in,out] y     1-D writeable OTI_F64, not overlapping a or x.
 *
 * @return As nd_gemm().
 */
int nd_gemv(oti_ctx* ctx, int32_t trans, double alpha, const ndarr_t* a, const ndarr_t* x,
            double beta, ndarr_t* y);

/**
 * @brief Rank-1 update: a = alpha x y^T + a (dger; a C-order a is updated as a^T += alpha y x^T).
 *
 * @param[in,out] ctx   Context, or NULL.
 * @param[in]     alpha Scalar.
 * @param[in]     x     1-D OTI_F64 of length a.shape[0].
 * @param[in]     y     1-D OTI_F64 of length a.shape[1].
 * @param[in,out] a     2-D writeable OTI_F64, not overlapping x or y.
 *
 * @return As nd_gemm().
 */
int nd_ger(oti_ctx* ctx, double alpha, const ndarr_t* x, const ndarr_t* y, ndarr_t* a);

/** @} */
// -------------------------------------------------------------------------------------------------------


/**
 * @name Level 1 on 1-D arrays
 * Statuses: OTI_OK, OTI_ERR_SHAPE (not 1-D, length mismatch), OTI_ERR_DTYPE, OTI_ERR_READONLY,
 * OTI_ERR_LAYOUT (an output overlapping an input), OTI_ERR_SIZE, OTI_ERR_MEMORY (pack).
 * @{
 */

/**
 * @brief Inner product of two vectors (ddot; numpy.vdot for real 1-D arrays).
 *
 * @param[in,out] ctx Context, or NULL.
 * @param[in]     x   1-D OTI_F64.
 * @param[in]     y   1-D OTI_F64 of the same length.
 * @param[out]    res The product (0.0 for empty vectors).
 *
 * @return Status.
 */
int nd_vdot(oti_ctx* ctx, const ndarr_t* x, const ndarr_t* y, double* res);

/**
 * @brief y = alpha x + y (daxpy).
 *
 * @param[in,out] ctx   Context, or NULL.
 * @param[in]     alpha Scalar.
 * @param[in]     x     1-D OTI_F64.
 * @param[in,out] y     1-D writeable OTI_F64 of the same length.
 *
 * @return Status.
 */
int nd_axpy(oti_ctx* ctx, double alpha, const ndarr_t* x, ndarr_t* y);

/**
 * @brief x = alpha x (dscal).
 *
 * @param[in,out] ctx   Context, or NULL.
 * @param[in]     alpha Scalar.
 * @param[in,out] x     1-D writeable OTI_F64.
 *
 * @return Status.
 */
int nd_scal(oti_ctx* ctx, double alpha, ndarr_t* x);

/**
 * @brief Euclidean norm (dnrm2).
 *
 * @param[in,out] ctx Context, or NULL.
 * @param[in]     x   1-D OTI_F64.
 * @param[out]    res The norm (0.0 for an empty vector).
 *
 * @return Status.
 */
int nd_nrm2(oti_ctx* ctx, const ndarr_t* x, double* res);

/**
 * @brief Sum of absolute values (dasum).
 *
 * @param[in,out] ctx Context, or NULL.
 * @param[in]     x   1-D OTI_F64.
 * @param[out]    res The sum.
 *
 * @return Status.
 */
int nd_asum(oti_ctx* ctx, const ndarr_t* x, double* res);

/**
 * @brief Index of the first element of largest absolute value (idamax), 0-based.
 *
 * @param[in,out] ctx Context, or NULL.
 * @param[in]     x   1-D OTI_F64.
 * @param[out]    res 0-based index; -1 for an empty vector.
 *
 * @return Status.
 */
int nd_iamax(oti_ctx* ctx, const ndarr_t* x, int64_t* res);

/** @} */
// -------------------------------------------------------------------------------------------------------

#ifdef __cplusplus
}
#endif

#endif
