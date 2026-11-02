#ifndef OTI_DENSE_SOA_STRUCTURES_H
#define OTI_DENSE_SOA_STRUCTURES_H

// -------------------------------------------------------------------------------------------------------
// --------------------------------------      STRUCTURES        -----------------------------------------
// -------------------------------------------------------------------------------------------------------

/**
 * @brief Dense OTI array, structure of arrays: every element dense over the global bases 1..nact.
 *
 * With k = nact, the array holds 1 + sshelp_ndir_total(k, trc_order) blocks of `size` reals in one
 * buffer. Block 0 is the real part; order-p direction i (global index i, see otinum_t) is block
 * 1 + sshelp_order_offset(k, p) + i. Each block is an nrows x ncols column-major matrix (element
 * (r, c) at r + c*nrows), so all blocks of one order form one nrows x (ncols * N_p(k)) column-major
 * matrix.
 *
 * p_data holds at least (1 + sshelp_ndir_total(nbases, trc_order)) * size reals, with nbases >= nact
 * the capacity in bases at the current trc_order and size (never overstating the allocation, see
 * oarr_reserve()). Orders above act_order hold zeros. There is no ownership flag: the array owns
 * p_data and oarr_free() always releases it. oarr_get_item_to() returns a copy; oarr_get_block()
 * returns a pointer into p_data.
 */
typedef struct {
    coeff_t*    p_data; ///< Blocks, column-major; block 0 = real part.
    bases_t     nbases; ///< Capacity of p_data, in bases (at trc_order and size); nbases >= nact.
    bases_t       nact; ///< Number of active bases k: every element is dense over bases 1..k.
    ord_t    trc_order; ///< Truncation order.
    ord_t    act_order; ///< Highest order that may hold nonzeros (<= trc_order).
    uint64_t     nrows; ///< Number of rows.
    uint64_t     ncols; ///< Number of columns.
    uint64_t      size; ///< nrows * ncols.
} oarr_t;               ///< Dense SoA OTI array type.

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

#endif
