#ifndef OTI_SEMISPARSE_CSR_H
#define OTI_SEMISPARSE_CSR_H

// Semi-sparse OTI sparse matrices: SoA CSR, triplet (lil) builder, solve (PLAN-semisparse-sparse-
// leveling.md, Phase 6).
//
// A CSR matrix of semi-sparse OTI numbers is one sparsity pattern (indices, indptr, int64 like SciPy's
// index arrays, so NumPy views of them feed scipy.sparse without a copy) and one nnz x 1 SoA array of
// values (oarrss_t): one active set for the whole matrix and one real nnz-vector per direction. Block 0
// of the values is the real part of the matrix, in CSR order.
//
// The builder (lilss_t) collects entries with their own active sets, as pyoti.sparse's lil_matrix
// does: setting an entry overwrites it, reading a missing entry gives nothing (the caller returns a
// zero). lilss_to_csr() sorts the entries by row and column and lays them out over the union of their
// active sets and the largest truncation order.

// -------------------------------------------------------------------------------------------------------
// ---------------------------------------     STATUS CODES     ------------------------------------------
// -------------------------------------------------------------------------------------------------------

#define CSRSS_OK            0  ///< Success.
#define CSRSS_ERR_SIZE    (-1) ///< Incompatible shapes (same value as OTI_LINALG_ERR_SIZE).
#define CSRSS_ERR_INDEX  (-10) ///< Invalid CSR pattern (indptr not monotone, index out of range).
#define CSRSS_ERR_SET    (-11) ///< The matrix's active set is not contained in the array's.
#define CSRSS_ERR_ORDER  (-12) ///< Order out of range (solve right-hand side).


// -------------------------------------------------------------------------------------------------------
// ---------------------------------------      STRUCTURES      ------------------------------------------
// -------------------------------------------------------------------------------------------------------

/**
 * @brief Triplet builder of a sparse matrix of semi-sparse OTI numbers (backs lil_matrix).
 *
 * Entries are kept in insertion order in p_val / p_row / p_col, each value with its own active set
 * and truncation order. An open-addressing hash table (p_slot, entry index + 1, 0 = empty) finds the
 * entry of a position in O(1).
 */
typedef struct {
    ssotinum_t*  p_val; ///< Entry values, length nnz (capacity cap).
    uint64_t*    p_row; ///< Entry rows, length nnz.
    uint64_t*    p_col; ///< Entry columns, length nnz.
    uint64_t*   p_slot; ///< Hash table of entry index + 1 (0 = empty), length nslot.
    uint64_t       nnz; ///< Number of stored entries.
    uint64_t       cap; ///< Capacity of p_val, p_row and p_col.
    uint64_t     nslot; ///< Hash table length, a power of two (0 before the first insertion).
    uint64_t     nrows; ///< Number of rows.
    uint64_t     ncols; ///< Number of columns.
} lilss_t;               ///< Semi-sparse triplet builder type.

/**
 * @brief Read-only view of a CSR matrix of semi-sparse OTI numbers.
 *
 * The buffers belong to the caller (the Python csr_matrix holds them); the view never frees them.
 * Row r holds entries p_indptr[r] .. p_indptr[r+1]-1, entry t at column p_indices[t] with value
 * element t of p_val (an nnz x 1 SoA array).
 */
typedef struct {
    const oarrss_t*   p_val; ///< Values, nnz x 1, one active set.
    const int64_t* p_indices; ///< Column of each entry, length nnz.
    const int64_t*  p_indptr; ///< Row starts, length nrows + 1.
    uint64_t          nrows; ///< Number of rows.
    uint64_t          ncols; ///< Number of columns.
} csrss_t;                    ///< Semi-sparse CSR view type.


// -------------------------------------------------------------------------------------------------------
// ---------------------------------------    TRIPLET BUILDER   ------------------------------------------
// -------------------------------------------------------------------------------------------------------

/**
 * @brief Creates an empty builder.
 *
 * @param[in] nrows Number of rows.
 * @param[in] ncols Number of columns.
 *
 * @return Empty builder (no allocation). Release with lilss_free().
 */
lilss_t lilss_init(uint64_t nrows, uint64_t ncols);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Releases every entry and buffer of a builder and leaves it empty (same shape).
 *
 * @param[in,out] lil Builder.
 */
void lilss_free(lilss_t* lil);
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
const ssotinum_t* lilss_get(const lilss_t* lil, uint64_t i, uint64_t j);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Sets the value at a position (copy; overwrites a stored entry, like pyoti.sparse).
 *
 * @param[in,out] lil Builder.
 * @param[in]     i   Row, < nrows.
 * @param[in]     j   Column, < ncols.
 * @param[in]     val Value, copied with its active set and truncation order.
 */
void lilss_set(lilss_t* lil, uint64_t i, uint64_t j, const ssotinum_t* val);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Sets a real value at a position (order 0, no bases; overwrites a stored entry).
 *
 * @param[in,out] lil Builder.
 * @param[in]     i   Row, < nrows.
 * @param[in]     j   Column, < ncols.
 * @param[in]     val Real value.
 */
void lilss_set_r(lilss_t* lil, uint64_t i, uint64_t j, coeff_t val);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Adds a value to a position (a missing entry starts at zero): entry = entry + val.
 *
 * Same result as a get, an OTI sum and a set, without the temporaries.
 *
 * @param[in,out] lil Builder.
 * @param[in]     i   Row, < nrows.
 * @param[in]     j   Column, < ncols.
 * @param[in]     val Value to add.
 * @param[in]     dhl Direction helper list.
 */
void lilss_add(lilss_t* lil, uint64_t i, uint64_t j, const ssotinum_t* val, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Adds a dense block to the positions rows x cols: entry(rows[a], cols[b]) += blk(a, b).
 *
 * The FEM scatter of an element matrix in one call, with the result of one lilss_add() per block
 * element. A new entry is written straight from the block, and a stored entry over the block's
 * active set is updated in place, so only new entries allocate. Repeated rows or columns add up.
 * Nothing changes when a check fails.
 *
 * @param[in,out] lil  Builder.
 * @param[in]     rows Global row of each block row, length nr, each < lil->nrows.
 * @param[in]     nr   Number of block rows.
 * @param[in]     cols Global column of each block column, length nc, each < lil->ncols.
 * @param[in]     nc   Number of block columns.
 * @param[in]     blk  Block, nr x nc.
 * @param[in]     dhl  Direction helper list.
 *
 * @return CSRSS_OK, CSRSS_ERR_SIZE (blk is not nr x nc) or CSRSS_ERR_INDEX (a row or column out of
 *         range).
 */
int lilss_add_block(lilss_t* lil, const uint64_t* rows, uint64_t nr, const uint64_t* cols, uint64_t nc,
                    const oarrss_t* blk, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Copies a builder (every entry, same insertion order).
 *
 * @param[in]     src Builder to copy.
 * @param[in,out] dst Destination; its previous contents are released.
 */
void lilss_copy_to(const lilss_t* src, lilss_t* dst);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Largest truncation order over the entries (0 for an empty builder).
 *
 * @param[in] lil Builder.
 *
 * @return Order.
 */
ord_t lilss_trc_order(const lilss_t* lil);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Entries sorted by row, then column: a CSR pattern of entry numbers.
 *
 * @param[in]  lil    Builder.
 * @param[out] perm   Entry index of CSR position t, length lil->nnz.
 * @param[out] indptr Row starts, length nrows + 1.
 *
 * @return CSRSS_OK. Allocation failures exit, as in the rest of the semi-sparse module.
 */
int lilss_sorted(const lilss_t* lil, uint64_t* perm, int64_t* indptr);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Converts a builder to CSR.
 *
 * The values are laid out over the union of the entries' active sets, at the largest truncation
 * order of the entries; every stored entry is kept (explicit zeros too, like pyoti.sparse).
 *
 * @param[in]  lil     Builder.
 * @param[out] val     Values: an owned nnz x 1 array (any previous contents are released first).
 * @param[out] indices Column of each entry, length lil->nnz.
 * @param[out] indptr  Row starts, length nrows + 1.
 *
 * @return CSRSS_OK. Caller owns @p val (oarrss_free()).
 */
int lilss_to_csr(const lilss_t* lil, oarrss_t* val, int64_t* indices, int64_t* indptr);
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
 * @return CSRSS_OK, CSRSS_ERR_INDEX or CSRSS_ERR_SIZE.
 */
int csrss_check(const csrss_t* K);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Dense copy of a CSR matrix (duplicate entries added up).
 *
 * @param[in]     K   Matrix.
 * @param[in,out] res Destination, reshaped to nrows x ncols over the matrix's active set and
 *                    truncation order.
 */
void csrss_to_dense(const csrss_t* K, oarrss_t* res);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Matrix product with a dense SoA array, res = K x.
 *
 * The result's active set is the union of K's and x's, and its truncation order the larger of the
 * two (a lower-order operand is zero-extended). Neither operand is copied or expanded: the product
 * indices come from remaps of each operand's local directions into the union and the product tables
 * of the union (table-driven, like the elementwise SoA product).
 *
 * @param[in]     K   Matrix, nrows x ncols.
 * @param[in]     x   Array, ncols x m.
 * @param[in,out] res Result, nrows x m. Must not alias @p x.
 * @param[in]     dhl Direction helper list.
 *
 * @return CSRSS_OK, or CSRSS_ERR_SIZE (res unchanged).
 */
int csrss_matmul_to(const csrss_t* K, const oarrss_t* x, oarrss_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Starts a block solve of K u = b: u = b over the union of K's and b's active sets, at the
 * larger of their truncation orders.
 *
 * @param[in]     K Matrix, n x n.
 * @param[in]     b Right-hand side, n x m.
 * @param[in,out] u Solution holder, reshaped to n x m; its real block and order blocks then hold b's.
 *
 * @return CSRSS_OK, or CSRSS_ERR_SIZE (u unchanged).
 */
int csrss_solve_init(const csrss_t* K, const oarrss_t* b, oarrss_t* u);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Right-hand side of order n of the block solve: u_n -= sum_{p=1..n} [K_p u_(n-p)]_n.
 *
 * On entry the order-n blocks of @p u hold b's, and orders 0 .. n-1 are already solved; on return
 * the order-n blocks hold the right-hand side of the real system K_0 u_n = rhs_n (every order-n
 * direction at once, one nrows x (m * N_n) column-major matrix). Only products landing on order n
 * are formed.
 *
 * @param[in]     K   Matrix, n x n; its active set must be contained in u's.
 * @param[in,out] u   Solution in progress (from csrss_solve_init()).
 * @param[in]     n   Order, 1 <= n <= u->trc_order.
 * @param[in]     dhl Direction helper list.
 *
 * @return CSRSS_OK, CSRSS_ERR_SIZE, CSRSS_ERR_SET or CSRSS_ERR_ORDER.
 */
int csrss_solve_rhs(const csrss_t* K, oarrss_t* u, ord_t n, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


#endif
