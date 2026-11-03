#ifndef OTI_DENSE_SOA_STRUCTURES_H
#define OTI_DENSE_SOA_STRUCTURES_H

// -------------------------------------------------------------------------------------------------------
// --------------------------------------      STRUCTURES        -----------------------------------------
// -------------------------------------------------------------------------------------------------------

/**
 * @brief Dense OTI array, structure of arrays, on ndarr_t: every element dense over the global bases
 * 1..nact (PLAN-ndarray.md "SoA arrays are one (ndim + 1)-D ndarray", contracts 7.1).
 *
 * @p blocks is one OTI_F64 descriptor of shape (nblocks, *S), nblocks = 1 + sshelp_ndir_total(nact,
 * trc_order). Axis 0 is the direction block: block 0 is the real part, and order-p direction i (global
 * index i, see otinum_t) is block 1 + sshelp_order_offset(nact, p) + i (oarr_block_index()), so the
 * blocks of one order are a slice. Inside a block the axes of S are in F order. Phase 7a uses S =
 * (nrows, ncols), strides (nrows*ncols, 1, nrows), and for the Gauss types S = (nip, nrows, ncols),
 * strides (nip*nrows*ncols, 1, nip, nip*nrows), always compact: the block stride strides[0] equals the
 * element count of a block. The matrix accessors read S as its F-order matricization: oarr_nrows() =
 * S[0], oarr_ncols() = the product of the other extents, so element (r, c) of a block is at r + c*nrows
 * and all blocks of one order form one nrows x (ncols * N_p(k)) column-major matrix.
 *
 * @p meta (OTI_META_DENSE, include/oti/core/meta.h) holds the layout shared by an array and its views:
 * meta->nbases = nact, trc_order and act_order (orders above act_order hold zeros).
 *
 * Ownership. An owning array (every creator and every `_to` result) holds one reference on its
 * buffer (blocks retained, ND_RETAINED) and one on its meta; oarr_free() releases both. A view
 * (oarr_view_matrix()) has a temporary blocks descriptor and borrows the meta of the array it views:
 * it must not outlive that array, is only ever an input of a C call, and oarr_free() on it only resets
 * it. oarr_init() holds neither (meta NULL). Copying an owning oarr_t by
 * struct assignment and keeping both copies is a double release: move it (reset the source) or build
 * a view.
 *
 * @p nbases >= nact is the capacity of the buffer in bases at trc_order and the current S: the buffer
 * holds at least (1 + sshelp_ndir_total(nbases, trc_order)) * size reals (never overstating the
 * allocation, see oarr_reserve()); 0 for a view or an array without a buffer. oarr_get_item_to()
 * returns a copy; oarr_get_block() returns a pointer into the buffer.
 */
typedef struct {
    ndarr_t       blocks; ///< OTI_F64 (nblocks, *S); axis 0 the direction block, F order inside a block.
    oti_meta_t*     meta; ///< OTI_META_DENSE layout (nact, trc_order, act_order); NULL for oarr_init().
    bases_t       nbases; ///< Capacity of the buffer, in bases (at trc_order and S); nbases >= nact.
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
 * @brief Sets act_order: the exact value for an owning array (it may lower it); through a view it is
 *        only raised, never lowered (contracts 7.3: other regions of the shared buffer may hold
 *        nonzeros).
 *
 * @param[in,out] a   Array with a meta.
 * @param[in]     act New active order, <= trc_order.
 */
static inline void oarr_set_act_order(oarr_t* a, ord_t act){
    if ((a->blocks.flags & ND_RETAINED) || (int32_t)act > a->meta->act_order){
        a->meta->act_order = (int32_t)act;
    }
}

/**
 * @brief Tells whether an array owns its buffer and meta (as opposed to a view or oarr_init()).
 *
 * @param[in] a Array.
 *
 * @return 1 if blocks is retained, else 0.
 */
static inline int oarr_owns(const oarr_t* a){
    return (a->blocks.flags & ND_RETAINED) != 0;
}

/** @} */
// -------------------------------------------------------------------------------------------------------

#endif
