#ifndef OTI_DENSE_SOA_STRUCTURES_H
#define OTI_DENSE_SOA_STRUCTURES_H

// -------------------------------------------------------------------------------------------------------
// --------------------------------------      STRUCTURES        -----------------------------------------
// -------------------------------------------------------------------------------------------------------

/**
 * @name Dense SoA array flags (oarr_t.flags)
 * @{
 */
#define OARR_GAUSS  0x1 ///< Gauss array: S = (nip, nrows, ncols), matricized as nip x (nrows * ncols).
#define OARR_VIEW   0x2 ///< Retained view (oarr_view_*()): shares the buffer and the meta of its root.
#define OARR_CANON  0x4 ///< Canonical root: owns its blocks, S compact in F order, block stride == size.
/** @} */

/**
 * @brief Dense OTI array, structure of arrays, on ndarr_t: every element dense over the global bases
 * 1..nact (PLAN-ndarray.md "SoA arrays are one (ndim + 1)-D ndarray", contracts 7.1, 11).
 *
 * @p blocks is one OTI_F64 descriptor of shape (nblocks, *S), nblocks = 1 + sshelp_ndir_total(nact,
 * trc_order), S of rank 0 .. OTI_ND_MAXDIM - 1. Axis 0 is the direction block: block 0 is the real part,
 * and order-p direction i (global index i, see otinum_t) is block 1 + sshelp_order_offset(nact, p) + i
 * (oarr_block_index()), so the blocks of one order are a slice. A root created by the library is
 * compact: inside a block the axes of S are in F order (the default, ND_LAYOUT_F) or C order
 * (oarr_zeros_nd_to() with ND_LAYOUT_C), and the block stride strides[0] equals the element count of a
 * block. A view (oarr_view_index(), oarr_view_transpose(), oarr_view_reshape()) has any strides on the
 * axes of S and the block stride of its root. The Gauss types use S = (nip, nrows, ncols), points
 * fastest (flag OARR_GAUSS).
 *
 * Canonical operands. Every function of the dense API accepts any array, views included: an operand
 * that is not canonical (S compact in F order and block stride == element count) is first packed into a
 * call-local canonical copy (one strided copy per block), so the kernels see the per-operand pointer
 * and block stride of a compact run. A `res` that is a view or a shared root (live views or exports)
 * receives the result through oarr_assign_to(): it must fit the shared layout (contracts 7.3), else
 * OTI_ERR_BUSY; nothing is clipped. OARR_CANON caches "a root laid out canonically", so that test is
 * one load on the common path: the library sets it whenever it lays out a root's blocks in F order
 * (every creator, `_to` result, growth and relayout) and clears it whenever the layout or the
 * ownership is otherwise (a C-order root, views, oarr_free()). Sharing is not cached: a view or an
 * export references the buffer, not this struct, so a call still reads the buffer's reference count.
 * A caller that edits @p blocks of a root directly must clear OARR_CANON. The matrix functions
 * (products, transpose, linear algebra, CSR, oarr_get_item_to(), oarr_set_item()) read a rank-2 S as an
 * nrows x ncols column-major matrix and reject any other rank with DN_ERR_SIZE; the elementwise
 * functions keep the shape of their operands (the binary ones broadcast them, NumPy rules).
 *
 * @p meta (OTI_META_DENSE, include/oti/core/meta.h) holds the layout shared by a root and its views:
 * meta->nbases = nact, trc_order and act_order (orders above act_order hold zeros).
 *
 * Ownership. A root (every creator and every `_to` result) holds one reference on its buffer (blocks
 * retained, ND_RETAINED) and one on its meta. A retained view (OARR_VIEW) holds one more reference on
 * each, so a root with live views (or exports of its buffer) cannot change its layout (OTI_ERR_BUSY,
 * contracts 7.2); writes through a view never change the layout. oarr_free() releases what an array
 * holds. A temporary view (oarr_view_matrix()) holds no reference: it must not outlive the array it
 * views and is only ever an input of a C call; oarr_free() on it only resets it. oarr_init() holds
 * nothing (meta NULL). Copying a root or a retained view by struct assignment and keeping both copies
 * is a double release: move it (reset the source).
 *
 * @p cap >= nact is the capacity of a root's buffer in bases at trc_order and the current S: the buffer
 * holds at least (1 + sshelp_ndir_total(cap, trc_order)) * size reals (never overstating the
 * allocation, see oarr_reserve()); 0 for a view or an array without a buffer. oarr_get_item_to()
 * returns a copy; oarr_get_block() returns a pointer into the buffer.
 */
typedef struct {
    ndarr_t       blocks; ///< OTI_F64 (nblocks, *S); axis 0 the direction block.
    oti_meta_t*     meta; ///< OTI_META_DENSE layout (nact, trc_order, act_order); NULL for oarr_init().
    bases_t          cap; ///< Capacity of a root's buffer, in bases (at trc_order and S); cap >= nact.
    int32_t        flags; ///< OARR_GAUSS | OARR_VIEW | OARR_CANON.
} oarr_t;                 ///< Dense SoA OTI array type.

/**
 * @brief LU factorization of a dense SoA matrix, for oarr_lu_solve().
 *
 * Holds a copy of the matrix whose real block is replaced by the LAPACK LU factors of the real part
 * (dgetrf), plus the pivots. The imaginary blocks are kept as they are: the solve uses them in the
 * order-by-order recurrence.
 */
typedef struct {
    oarr_t      A; ///< Matrix, real block = LU factors of the real part.
    int*   p_ipiv; ///< Pivot indices from dgetrf (1-based), length nrows.
} oarr_lu_t;      ///< Dense SoA LU factorization type.

// -------------------------------------------------------------------------------------------------------
// -------------------------------------    END STRUCTURES      ------------------------------------------
// -------------------------------------------------------------------------------------------------------


/**
 * @name Dense SoA accessors
 * Read the layout of an array from its blocks descriptor and its meta. Valid on owning arrays, views
 * and oarr_init() (which reads as a 0 x 0 real array of order 0).
 * @{
 */

/**
 * @brief Coefficients of an array: block 0 (the real part), then the direction blocks.
 *
 * @param[in] a Array.
 *
 * @return blocks.data as coeff_t* (NULL when no buffer was ever allocated). Not owned by the caller;
 *         valid until the array is resized.
 */
static inline coeff_t* oarr_data(const oarr_t* a){
    return (coeff_t*)a->blocks.data;
}

/**
 * @brief The block descriptor of an array, (nblocks, *S) (for bindings that cannot name the field).
 *
 * @param[in] a Array.
 *
 * @return &a->blocks.
 */
static inline ndarr_t* oarr_blocks(oarr_t* a){
    return &a->blocks;
}

/**
 * @brief Number of element axes: the rank of S (blocks.ndim - 1).
 *
 * @param[in] a Array.
 *
 * @return ndim of the OTI array (0 for a scalar-shaped array).
 */
static inline int32_t oarr_ndim(const oarr_t* a){
    return a->blocks.ndim - 1;
}

/**
 * @brief Extent of element axis d: S[d].
 *
 * @param[in] a Array.
 * @param[in] d Axis, 0 <= d < oarr_ndim(a).
 *
 * @return The extent.
 */
static inline int64_t oarr_shape(const oarr_t* a, int32_t d){
    return a->blocks.shape[1 + d];
}

/**
 * @brief Rows of the matricized element shape: S[0] (1 for a rank-0 S).
 *
 * @param[in] a Array.
 *
 * @return nrows.
 */
static inline uint64_t oarr_nrows(const oarr_t* a){
    return (a->blocks.ndim >= 2) ? (uint64_t)a->blocks.shape[1] : 1;
}

/**
 * @brief Columns of the matricized element shape: the product of S[1..] (ncols for a matrix,
 *        nrows * ncols for a Gauss array, 1 for a rank-1 S).
 *
 * @param[in] a Array.
 *
 * @return ncols.
 */
static inline uint64_t oarr_ncols(const oarr_t* a){
    uint64_t n = 1;
    int32_t d;
    for (d = 2; d < a->blocks.ndim; d++){
        n *= (uint64_t)a->blocks.shape[d];
    }
    return n;
}

/**
 * @brief Elements of one block: the product of S.
 *
 * @param[in] a Array.
 *
 * @return nrows * ncols.
 */
static inline uint64_t oarr_size(const oarr_t* a){
    return oarr_nrows(a) * oarr_ncols(a);
}

/**
 * @brief Capacity of a root's buffer in bases (critic W3 finding 7; 0 for a view).
 *
 * @param[in] a Array.
 *
 * @return cap.
 */
static inline bases_t oarr_capacity(const oarr_t* a){
    return a->cap;
}

/**
 * @brief Tells whether an array is a retained view (oarr_view_*()).
 *
 * @param[in] a Array.
 *
 * @return 1 for a view, else 0.
 */
static inline int oarr_is_view(const oarr_t* a){
    return (a->flags & OARR_VIEW) != 0;
}

/**
 * @brief Block stride in reals (blocks.strides[0]; the block size of a compact array).
 *
 * @param[in] a Array.
 *
 * @return The stride between consecutive direction blocks.
 */
static inline int64_t oarr_bstride(const oarr_t* a){
    return a->blocks.strides[0];
}

/**
 * @brief Number of active bases k: every element is dense over bases 1..k.
 *
 * @param[in] a Array.
 *
 * @return meta->nbases, or 0 for oarr_init().
 */
static inline bases_t oarr_nact(const oarr_t* a){
    return (a->meta != NULL) ? (bases_t)a->meta->nbases : 0;
}

/**
 * @brief Truncation order.
 *
 * @param[in] a Array.
 *
 * @return meta->trc_order, or 0 for oarr_init().
 */
static inline ord_t oarr_trc_order(const oarr_t* a){
    return (a->meta != NULL) ? (ord_t)a->meta->trc_order : 0;
}

/**
 * @brief Highest order that may hold nonzeros (<= trc_order).
 *
 * @param[in] a Array.
 *
 * @return meta->act_order, or 0 for oarr_init().
 */
static inline ord_t oarr_act_order(const oarr_t* a){
    return (a->meta != NULL) ? (ord_t)a->meta->act_order : 0;
}

/**
 * @brief Tells whether an array is a root: it owns its buffer and meta (as opposed to a view, retained
 *        or temporary, or oarr_init()).
 *
 * @param[in] a Array.
 *
 * @return 1 if blocks is retained and the array is not a view, else 0.
 */
static inline int oarr_owns(const oarr_t* a){
    return (a->blocks.flags & ND_RETAINED) != 0 && !(a->flags & OARR_VIEW);
}

/**
 * @brief Sets act_order: the exact value for a root (it may lower it); through a view it is only
 *        raised, never lowered (contracts 7.3: other regions of the shared buffer may hold nonzeros).
 *
 * @param[in,out] a   Array with a meta.
 * @param[in]     act New active order, <= trc_order.
 */
static inline void oarr_set_act_order(oarr_t* a, ord_t act){
    if (oarr_owns(a) || (int32_t)act > a->meta->act_order){
        a->meta->act_order = (int32_t)act;
    }
}

/** @} */
// -------------------------------------------------------------------------------------------------------

#endif
