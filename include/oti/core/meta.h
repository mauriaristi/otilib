#ifndef OTI_CORE_META_H
#define OTI_CORE_META_H

// -------------------------------------------------------------------------------------------------------
// OTI layout metadata shared by an OTI array and all its OTI views (PLAN-ndarray.md "OTI views and
// metadata"; PLAN-ndarray-contracts.md section 7). Skeleton written in Phase C; implemented in
// src/c/core/meta.c by the dense agent in Phase 7a. It is the runtime active-set policy of the
// dense / semi-sparse unification: a dense meta has no labels (bases 1..nbases), a semi-sparse meta
// holds the sorted labels.
//
// Rules:
//   - Refcounting: refs counts the root array and every OTI view sharing the layout (NumPy exports
//     are counted by the buffer, nd_buffer_t). __atomic_* builtins on a plain int64_t.
//   - Fixed layout while views or exports live: every layout change is ONE transaction under ONE lock:
//     oti_meta_layout_begin() (refs == 1 and the buffer's layout lock), nd_grow_locked() if the
//     allocation must grow (never nd_grow(): the lock is not reentrant), the block moves,
//     oti_meta_relayout(), oti_meta_layout_end(). Otherwise OTI_ERR_BUSY.
//   - Growth through a view object always fails. A root with no live view or export grows through
//     any assignment key.
//   - out=view: the result must fit the shared layout (oti_meta_fits()); otherwise OTI_ERR_BUSY. It
//     never clips. act_order is never lowered through a view.
//   - Writeable public exports of imaginary blocks raise act_order to trc_order first; block 0 (the
//     real part) and the internal writable path (whose setter sets act itself) do not.
//   - bases_i64 is built eagerly (create, relayout), never lazily, so concurrent readers only read it.
//   - Reservations: dense nbases = K > 0 at creation sets the layout nact = K; nbases = 0 reserves
//     nothing; the buffer is still checked against the context's byte budget.
// -------------------------------------------------------------------------------------------------------

#include <stdint.h>

#include "oti/comm.h"
#include "oti/core/status.h"
#include "oti/real/ndarray/structures.h"

#ifdef __cplusplus
extern "C" {
#endif

// -------------------------------------------------------------------------------------------------------
// --------------------------------------      CONSTANTS         -----------------------------------------
// -------------------------------------------------------------------------------------------------------

/**
 * @name Metadata kinds (oti_meta_t.kind)
 * @{
 */
#define OTI_META_DENSE   0 ///< Dense: no labels; the active bases are 1..nbases.
#define OTI_META_BASES   1 ///< Semi-sparse: sorted labels in bases[0 .. nbases-1].
/** @} */
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// --------------------------------------      STRUCTURES        -----------------------------------------
// -------------------------------------------------------------------------------------------------------

/**
 * @brief Layout metadata of an OTI array, shared by the root and its OTI views.
 *
 * Fields other than refs may be read directly; they change only inside a layout transaction
 * (oti_meta_layout_begin() .. oti_meta_layout_end()) or through the act functions.
 */
typedef struct oti_meta_s {
    int64_t   refs;       ///< Root plus OTI views (atomic; use the functions below).
    int32_t   kind;       ///< OTI_META_DENSE or OTI_META_BASES.
    int32_t   trc_order;  ///< Layout truncation order: blocks exist for orders 0..trc_order.
    int32_t   act_order;  ///< Highest order that may hold nonzeros anywhere in the buffer (shared).
    int32_t   nbases;     ///< Layout bases k (dense: nact; semi-sparse: number of labels).
    int32_t   cap_bases;  ///< Capacity of bases (semi-sparse), >= nbases; 0 for dense.
    int32_t   reserved;   ///< Zero.
    bases_t*  bases;      ///< Sorted labels, length nbases; NULL for dense. Owned by the meta.
    int64_t*  bases_i64;  ///< int64 copy of bases for oti_view; NULL for dense. Owned by the meta.
} oti_meta_t;

// -------------------------------------------------------------------------------------------------------
// -------------------------------------    END STRUCTURES      ------------------------------------------
// -------------------------------------------------------------------------------------------------------


/**
 * @name Lifetime and refcounting
 * @{
 */

/**
 * @brief Creates a metadata block (refs 1).
 *
 * @param[in]  kind      OTI_META_DENSE or OTI_META_BASES.
 * @param[in]  trc_order Truncation order, 0 .. _MAXORDER_OTI.
 * @param[in]  nbases    Layout bases (dense nact, or the number of labels).
 * @param[in]  bases     Sorted, distinct labels (OTI_META_BASES), copied; NULL for dense.
 * @param[in]  cap_bases Capacity of the labels array, >= nbases (OTI_META_BASES); ignored for dense.
 * @param[out] res       New metadata block.
 *
 * @return OTI_OK; OTI_ERR_ARGUMENT (kind, unsorted or duplicate labels, NULL); OTI_ERR_INDEX (order
 *         above the maximum); OTI_ERR_MEMORY. Caller owns the reference and must release it via
 *         oti_meta_release(). On failure *res is NULL.
 */
int oti_meta_create(int32_t kind, int32_t trc_order, int32_t nbases, const bases_t* bases,
                    int32_t cap_bases, oti_meta_t** res);

/**
 * @brief Adds a reference (relaxed increment).
 *
 * @param[in,out] m Metadata block, not NULL.
 *
 * @return @p m. The caller must release the new reference via oti_meta_release().
 */
oti_meta_t* oti_meta_retain(oti_meta_t* m);

/**
 * @brief Drops a reference (acquire-release); frees the block and its arrays at zero.
 *
 * @param[in,out] m Pointer to the caller's reference; set to NULL. NULL or *m == NULL is a no-op.
 */
void oti_meta_release(oti_meta_t** m);

/**
 * @brief Tells whether OTI views share this layout.
 *
 * @param[in] m Metadata block.
 *
 * @return 1 if refs > 1, else 0.
 */
int oti_meta_shared(const oti_meta_t* m);

/** @} */
// -------------------------------------------------------------------------------------------------------


/**
 * @name Layout transactions
 * @{
 */

/**
 * @brief Starts a layout change: requires refs == 1 and takes the buffer's layout lock.
 *
 * @param[in,out] m   Metadata block of the root array.
 * @param[in,out] buf The root array's control block.
 *
 * @return OTI_OK (the lock is held until oti_meta_layout_end()); OTI_ERR_BUSY when OTI views share
 *         the meta, or the buffer has other references, exports, or a held lock.
 */
int oti_meta_layout_begin(oti_meta_t* m, nd_buffer_t* buf);

/**
 * @brief Changes the layout fields inside a transaction (after the blocks were moved).
 *
 * Replaces trc_order, nbases and (OTI_META_BASES) the labels, growing the labels array when needed,
 * and rebuilds bases_i64. act_order is clipped to the new trc_order.
 *
 * @param[in,out] m         Metadata block whose transaction is open.
 * @param[in]     trc_order New truncation order.
 * @param[in]     nbases    New layout bases.
 * @param[in]     bases     New sorted labels (OTI_META_BASES), copied; NULL for dense.
 *
 * @return OTI_OK; OTI_ERR_ARGUMENT; OTI_ERR_INDEX; OTI_ERR_MEMORY (the fields are unchanged).
 */
int oti_meta_relayout(oti_meta_t* m, int32_t trc_order, int32_t nbases, const bases_t* bases);

/**
 * @brief Ends a layout change: releases the buffer's layout lock.
 *
 * @param[in,out] m   Metadata block whose transaction is open.
 * @param[in,out] buf The control block passed to oti_meta_layout_begin().
 */
void oti_meta_layout_end(oti_meta_t* m, nd_buffer_t* buf);

/** @} */
// -------------------------------------------------------------------------------------------------------


/**
 * @name Active order and fit
 * @{
 */

/**
 * @brief Raises act_order to max(act_order, min(act, trc_order)). Never lowers it.
 *
 * @param[in,out] m   Metadata block.
 * @param[in]     act Highest order that may now hold nonzeros.
 */
void oti_meta_raise_act(oti_meta_t* m, int32_t act);

/**
 * @brief Sets an exact act_order (may lower it) after an operation recomputed the whole array.
 *
 * Only for an unshared meta (debug builds assert refs == 1); through a view use oti_meta_raise_act().
 *
 * @param[in,out] m   Metadata block, not shared.
 * @param[in]     act New active order, 0 .. trc_order.
 */
void oti_meta_set_act(oti_meta_t* m, int32_t act);

/**
 * @brief Tells whether a value of the given layout can be written into this layout without relayout.
 *
 * @param[in] m      Metadata block.
 * @param[in] trc    The value's truncation order.
 * @param[in] nbases The value's number of bases (dense nact, or labels).
 * @param[in] bases  The value's sorted labels (OTI_META_BASES), or NULL for dense.
 *
 * @return 1 if trc <= m->trc_order and the value's bases are a subset of the meta's (dense:
 *         nbases <= m->nbases), else 0.
 */
int oti_meta_fits(const oti_meta_t* m, int32_t trc, int32_t nbases, const bases_t* bases);

/** @} */
// -------------------------------------------------------------------------------------------------------

#ifdef __cplusplus
}
#endif

#endif
