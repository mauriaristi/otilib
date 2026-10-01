#ifndef OTI_DENSE_CSR_H
#define OTI_DENSE_CSR_H

// Dense OTI sparse matrices: SoA CSR, triplet (lil) builder, solve (PLAN-dense-update.md, WP7; the
// semi-sparse src/c/semisparse/csr/csr.c without remaps).
//
// A CSR matrix of dense OTI numbers is one sparsity pattern (indices, indptr, int64 like SciPy's
// index arrays, so NumPy views of them feed scipy.sparse without a copy) and one nnz x 1 SoA array of
// values (oarr_t): one nact for the whole matrix and one real nnz-vector per direction. Block 0
// of the values is the real part of the matrix, in CSR order.
//
// The builder (lilo_t) collects entries with their own nact and orders, as pyoti.sparse's lil_matrix
// does: setting an entry overwrites it, reading a missing entry gives nothing (the caller returns a
// zero). lilo_to_csr() sorts the entries by row and column and lays them out over the largest nact
// and the largest truncation order of the entries. Nothing here calls exit(). These functions return
// only CSRO_* codes: a DN_ERR_* from an inner call is mapped (DN_ERR_SIZE -> CSRO_ERR_SIZE,
// DN_ERR_MEMORY -> CSRO_ERR_MEMORY, DN_ERR_INDEX -> CSRO_ERR_INDEX).

// -------------------------------------------------------------------------------------------------------
// ---------------------------------------     STATUS CODES     ------------------------------------------
// -------------------------------------------------------------------------------------------------------

#define CSRO_OK            0  ///< Success (DN_OK).
#define CSRO_ERR_SIZE    (-1) ///< Incompatible shapes (DN_ERR_SIZE, OTI_LINALG_ERR_SIZE).
#define CSRO_ERR_MEMORY  (-2) ///< An allocation failed or a size overflows (DN_ERR_MEMORY).
#define CSRO_ERR_INDEX  (-10) ///< Invalid CSR pattern (indptr not monotone, index out of range).
#define CSRO_ERR_NACT   (-11) ///< The matrix's nact is larger than the array's.
#define CSRO_ERR_ORDER  (-12) ///< Order out of range (solve right-hand side).


// -------------------------------------------------------------------------------------------------------
// ---------------------------------------      STRUCTURES      ------------------------------------------
// -------------------------------------------------------------------------------------------------------

/**
 * @brief Triplet builder of a sparse matrix of dense OTI numbers (backs lil_matrix).
 *
 * Entries are kept in insertion order in p_val / p_row / p_col, each value with its own nact and
 * truncation order. An open-addressing hash table (p_slot, entry index + 1, 0 = empty) finds the
 * entry of a position in O(1).
 */
typedef struct {
    otinum_t*  p_val; ///< Entry values, length nnz (capacity cap).
    uint64_t*  p_row; ///< Entry rows, length nnz.
    uint64_t*  p_col; ///< Entry columns, length nnz.
    uint64_t* p_slot; ///< Hash table of entry index + 1 (0 = empty), length nslot.
    uint64_t     nnz; ///< Number of stored entries.
    uint64_t     cap; ///< Capacity of p_val, p_row and p_col.
    uint64_t   nslot; ///< Hash table length, a power of two (0 before the first insertion).
    uint64_t   nrows; ///< Number of rows.
    uint64_t   ncols; ///< Number of columns.
} lilo_t;             ///< Dense triplet builder type.

/**
 * @brief Read-only view of a CSR matrix of dense OTI numbers.
 *
 * The buffers belong to the caller (the Python csr_matrix holds them); the view never frees them.
 * Row r holds entries p_indptr[r] .. p_indptr[r+1]-1, entry t at column p_indices[t] with value
 * element t of p_val (an nnz x 1 SoA array).
 */
typedef struct {
    const oarr_t*      p_val; ///< Values, nnz x 1, one nact for the whole matrix.
    const int64_t* p_indices; ///< Column of each entry, length nnz.
    const int64_t*  p_indptr; ///< Row starts, length nrows + 1.
    uint64_t           nrows; ///< Number of rows.
    uint64_t           ncols; ///< Number of columns.
} csro_t;                     ///< Dense CSR view type.


// -------------------------------------------------------------------------------------------------------
// ---------------------------------------    TRIPLET BUILDER   ------------------------------------------
// -------------------------------------------------------------------------------------------------------

/**
 * @brief Creates an empty builder.
 *
 * @param[in] nrows Number of rows.
 * @param[in] ncols Number of columns.
 *
 * @return Empty builder (no allocation). Release with lilo_free().
 */
lilo_t lilo_init(uint64_t nrows, uint64_t ncols);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Releases every entry and buffer of a builder and leaves it empty (same shape).
 *
 * @param[in,out] lil Builder.
 */
void lilo_free(lilo_t* lil);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Stored value at a position.
 *
 * @param[in] lil Builder.
 * @param[in] i   Row, < nrows.
 * @param[in] j   Column, < ncols.
 *
 * @return Pointer to the stored value (valid until the next insertion), or NULL when the position
 *         holds no entry.
 */
const otinum_t* lilo_get(const lilo_t* lil, uint64_t i, uint64_t j);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Sets the value at a position (copy; overwrites a stored entry, like pyoti.sparse).
 *
 * @param[in,out] lil Builder.
 * @param[in]     i   Row, < nrows.
 * @param[in]     j   Column, < ncols.
 * @param[in]     val Value, copied with its nact and truncation order. May point into @p lil (a
 *                    lilo_get() result): it is copied before the builder can grow.
 *
 * @return CSRO_OK, CSRO_ERR_INDEX (a position out of range) or CSRO_ERR_MEMORY.
 */
int lilo_set(lilo_t* lil, uint64_t i, uint64_t j, const otinum_t* val);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Sets a real value at a position (order 0, nact 0; overwrites a stored entry).
 *
 * @param[in,out] lil Builder.
 * @param[in]     i   Row, < nrows.
 * @param[in]     j   Column, < ncols.
 * @param[in]     val Real value.
 *
 * @return CSRO_OK, CSRO_ERR_INDEX or CSRO_ERR_MEMORY.
 */
int lilo_set_r(lilo_t* lil, uint64_t i, uint64_t j, coeff_t val);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Adds a value to a position (a missing entry starts at zero): entry = entry + val.
 *
 * Same result as a get, an OTI sum and a set, without the temporaries.
 *
 * @param[in,out] lil Builder.
 * @param[in]     i   Row, < nrows.
 * @param[in]     j   Column, < ncols.
 * @param[in]     val Value to add. May point into @p lil (a lilo_get() result): it is copied before
 *                    the builder can grow.
 * @param[in]     dhl Direction helper list.
 *
 * @return CSRO_OK, CSRO_ERR_INDEX (a position out of range) or CSRO_ERR_MEMORY.
 */
int lilo_add(lilo_t* lil, uint64_t i, uint64_t j, const otinum_t* val, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Adds a dense block to the positions rows x cols: entry(rows[a], cols[b]) += blk(a, b).
 *
 * The FEM scatter of an element matrix in one call, with the result of one lilo_add() per block
 * element. A new entry is written straight from the block, and a stored entry whose layout holds
 * the block's (nact, trc) is updated in place, so only new or grown entries allocate. Repeated rows
 * or columns add up. Nothing changes when a check fails, and the entry and hash capacity for the whole
 * block is reserved before any entry changes; only a value allocation can fail midway, and then
 * (CSRO_ERR_MEMORY) the block may be partially added, with the builder still valid.
 *
 * @param[in,out] lil  Builder.
 * @param[in]     rows Global row of each block row, length nr, each < lil->nrows.
 * @param[in]     nr   Number of block rows.
 * @param[in]     cols Global column of each block column, length nc, each < lil->ncols.
 * @param[in]     nc   Number of block columns.
 * @param[in]     blk  Block, nr x nc.
 * @param[in]     dhl  Direction helper list.
 *
 * @return CSRO_OK, CSRO_ERR_SIZE (blk is not nr x nc), CSRO_ERR_INDEX (a row or column out of
 *         range) or CSRO_ERR_MEMORY.
 */
int lilo_add_block(lilo_t* lil, const uint64_t* rows, uint64_t nr, const uint64_t* cols,
                   uint64_t nc, const oarr_t* blk, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Copies a builder (every entry, same insertion order).
 *
 * @param[in]     src Builder to copy.
 * @param[in,out] dst Destination; its previous contents are released.
 *
 * @return CSRO_OK, or CSRO_ERR_MEMORY.
 */
int lilo_copy_to(const lilo_t* src, lilo_t* dst);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Largest truncation order over the entries (0 for an empty builder).
 *
 * @param[in] lil Builder.
 *
 * @return Order.
 */
ord_t lilo_trc_order(const lilo_t* lil);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Entries sorted by row, then column: a CSR pattern of entry numbers.
 *
 * @param[in]  lil    Builder.
 * @param[out] perm   Entry index of CSR position t, length lil->nnz.
 * @param[out] indptr Row starts, length nrows + 1.
 *
 * @return CSRO_OK, or CSRO_ERR_MEMORY.
 */
int lilo_sorted(const lilo_t* lil, uint64_t* perm, int64_t* indptr);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Converts a builder to CSR.
 *
 * The values are laid out over the largest nact of the entries, at their largest truncation
 * order; every stored entry is kept (explicit zeros too, like pyoti.sparse).
 *
 * @param[in]  lil     Builder.
 * @param[out] val     Values: an owned nnz x 1 array (any previous contents are released first).
 * @param[out] indices Column of each entry, length lil->nnz.
 * @param[out] indptr  Row starts, length nrows + 1.
 *
 * @return CSRO_OK, or CSRO_ERR_MEMORY. Caller owns @p val (oarr_free()).
 */
int lilo_to_csr(const lilo_t* lil, oarr_t* val, int64_t* indices, int64_t* indptr);
// -------------------------------------------------------------------------------------------------------


// -------------------------------------------------------------------------------------------------------
// ---------------------------------------          CSR         ------------------------------------------
// -------------------------------------------------------------------------------------------------------

/**
 * @brief Checks a CSR pattern: indptr[0] = 0, nondecreasing, indptr[nrows] = nnz, 0 <= index < ncols,
 * and the values are nnz x 1.
 *
 * Column indices need not be sorted within a row, and duplicates are allowed (they add up in every
 * product, as in SciPy).
 *
 * @param[in] K Matrix.
 *
 * @return CSRO_OK, CSRO_ERR_INDEX or CSRO_ERR_SIZE.
 */
int csro_check(const csro_t* K);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Dense copy of a CSR matrix (duplicate entries added up).
 *
 * @param[in]     K   Matrix.
 * @param[in,out] res Destination, reshaped to nrows x ncols with the matrix's nact and orders.
 *
 * @return CSRO_OK, or CSRO_ERR_MEMORY.
 */
int csro_to_dense(const csro_t* K, oarr_t* res);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Matrix product with a dense SoA array, res = K x.
 *
 * The result has nact = max(nact_K, nact_x) and the larger truncation order (a lower-order operand
 * is zero-extended). Neither operand is copied or expanded: both are prefixes of the result's layout,
 * so their blocks are read at their own offsets through the product tables of the result's nact
 * (table-driven, like the elementwise SoA product; private dncs_ kernels, or the per-operand-nact
 * statics of src/c/dense/soa/kernels.c).
 *
 * @param[in]     K   Matrix, nrows x ncols.
 * @param[in]     x   Array, ncols x m. Must not be K's value array (CSRO_ERR_SIZE).
 * @param[in,out] res Result, nrows x m. Must not alias @p x.
 * @param[in]     dhl Direction helper list.
 *
 * @return CSRO_OK, CSRO_ERR_SIZE (res unchanged) or CSRO_ERR_MEMORY.
 */
int csro_matmul_to(const csro_t* K, const oarr_t* x, oarr_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Starts a block solve of K u = b: u = b over nact = max(nact_K, nact_b), at the larger of
 * their truncation orders.
 *
 * @param[in]     K Matrix, n x n.
 * @param[in]     b Right-hand side, n x m.
 * @param[in,out] u Solution holder, reshaped to n x m; its real block and order blocks then hold b's.
 *                  Must not be K's value array (CSRO_ERR_SIZE).
 *
 * @return CSRO_OK, CSRO_ERR_SIZE (u unchanged) or CSRO_ERR_MEMORY.
 */
int csro_solve_init(const csro_t* K, const oarr_t* b, oarr_t* u);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Right-hand side of order n of the block solve: u_n -= sum_{p=1..n} [K_p u_(n-p)]_n.
 *
 * On entry the order-n blocks of @p u hold b's, and orders 0 .. n-1 are already solved; on return
 * the order-n blocks hold the right-hand side of the real system K_0 u_n = rhs_n (every order-n
 * direction at once, one nrows x (m * N_n) column-major matrix). Only products landing on order n
 * are formed.
 *
 * @param[in]     K   Matrix, n x n; its nact must not exceed u's.
 * @param[in,out] u   Solution in progress (from csro_solve_init()).
 * @param[in]     n   Order, 1 <= n <= u->trc_order.
 * @param[in]     dhl Direction helper list.
 *
 * @return CSRO_OK, CSRO_ERR_SIZE, CSRO_ERR_NACT, CSRO_ERR_ORDER or CSRO_ERR_MEMORY.
 */
int csro_solve_rhs(const csro_t* K, oarr_t* u, ord_t n, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


#endif
