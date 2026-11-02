#ifndef OTI_REAL_NDARRAY_COMPAT_DARR_H
#define OTI_REAL_NDARRAY_COMPAT_DARR_H

// -------------------------------------------------------------------------------------------------------
// Zero-copy adapters between the legacy real array darr_t and ndarr_t (PLAN-ndarray.md Phase 6a;
// src/c/real/ndarray/compat_darr.c). They exist until the last darr_t user (static, Phase 10) has
// moved onto ndarr_t.
//
// A darr_t is always a row-major (C-contiguous) nrows x ncols F64 matrix: element (i, j) is at
// p_data[j + i*ncols], size == nrows*ncols, p_data from malloc (freed by darr_free()). It has no
// reference count, no read-only flag and no notion of a borrowed span, so every adapter states who
// frees what and what may outlive what:
//
//   nd_from_darr(ND_DARR_BORROW)  temporary ndarr_t (buf NULL) over src->p_data. src keeps the
//                                 memory: the view is valid only until darr_free(src) or any
//                                 operation that reallocates src. Nothing to release (nd_release()
//                                 only resets it).
//   nd_from_darr(ND_DARR_RETAIN)  retained ndarr_t with its own control block, but the memory still
//                                 belongs to src (no release callback): src must outlive the LAST
//                                 reference, including retained views and exports made from it.
//                                 Release it with nd_release(); darr_free(src) afterwards.
//   nd_from_darr(ND_DARR_TAKE)    retained ndarr_t that takes over src->p_data: it is freed with
//                                 free() when the last reference is released. Ownership passes ON
//                                 ENTRY (contracts 1.5): src is reset to the empty darr_t on every
//                                 path, and on failure the memory has already been freed. Never call
//                                 darr_free(src) on the old contents.
//   nd_as_darr                    darr_t VIEW of a C-contiguous F64 ndarr_t of rank <= 2. The memory
//                                 belongs to the array's buffer: never darr_free() the result; it is
//                                 valid while some reference keeps that buffer alive and the buffer
//                                 is not grown (nd_grow() invalidates it, like any temporary).
//
// The resulting descriptors follow the ndarray rules of include/oti/real/ndarray/structures.h.
// -------------------------------------------------------------------------------------------------------

#include "oti/comm.h"
#include "oti/real/array/structures.h"
#include "oti/core/exec.h"
#include "oti/real/ndarray/structures.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @name Adapter modes (nd_from_darr())
 * @{
 */
#define ND_DARR_BORROW  0 ///< Temporary view; src keeps and frees the memory.
#define ND_DARR_RETAIN  1 ///< Retained view; src keeps the memory and must outlive every reference.
#define ND_DARR_TAKE    2 ///< Retained array that owns the memory (free() at the last release).
/** @} */
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Describes a darr_t as an ndarr_t of shape (nrows, ncols), C-contiguous, writeable, without
 *        copying.
 *
 * See the file comment for the lifetime rules of each mode. An empty darr_t (size 0, p_data NULL
 * allowed) gives an empty array of shape (nrows, ncols).
 *
 * @param[in,out] ctx  Context, or NULL (checked by oti_ctx_check() for RETAIN and TAKE).
 * @param[in,out] src  The darr_t. Reset to the empty darr_t (darr_init() state) by ND_DARR_TAKE on
 *                     every path; unchanged otherwise.
 * @param[in]     mode ND_DARR_BORROW, ND_DARR_RETAIN or ND_DARR_TAKE.
 * @param[out]    out  BORROW: temporary (buf NULL); RETAIN / TAKE: new retained array (refs 1).
 *                     Must be empty or a temporary on entry. Empty on failure.
 *
 * @return OTI_OK; OTI_ERR_ARGUMENT (NULL, mode, size != nrows*ncols, NULL p_data with size > 0, an
 *         invalid context); OTI_ERR_SIZE (an extent above INT64_MAX or a byte count overflow);
 *         OTI_ERR_LAYOUT (p_data not aligned to 8 bytes); OTI_ERR_MEMORY (control block);
 *         OTI_ERR_BACKEND (context). RETAIN / TAKE: caller must release @p out via nd_release().
 */
int nd_from_darr(oti_ctx* ctx, darr_t* src, int32_t mode, ndarr_t* out);

/**
 * @brief Describes a C-contiguous OTI_F64 ndarr_t of rank <= 2 as a darr_t view, without copying.
 *
 * Shapes map as rank 0 -> 1 x 1, (n,) -> 1 x n (a row, as darr_t vectors were), (m, n) -> m x n.
 * The view never owns memory: do not call darr_free() on it (see the file comment).
 *
 * @param[in]  a         Well-formed descriptor.
 * @param[in]  writeable 1 if the view will be written (then @p a must be ND_WRITEABLE), 0 for reads.
 * @param[out] out       darr_t view; set to the empty darr_t on failure.
 *
 * @return OTI_OK; OTI_ERR_ARGUMENT (NULL); OTI_ERR_DTYPE (not OTI_F64); OTI_ERR_SHAPE (rank > 2);
 *         OTI_ERR_LAYOUT (not C-contiguous); OTI_ERR_READONLY (@p writeable on a read-only array).
 */
int nd_as_darr(const ndarr_t* a, int32_t writeable, darr_t* out);

#ifdef __cplusplus
}
#endif

#endif
