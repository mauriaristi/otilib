#ifndef OTI_SEMISPARSE_SOA_STRUCTURES_H
#define OTI_SEMISPARSE_SOA_STRUCTURES_H

// -------------------------------------------------------------------------------------------------------
// --------------------------------------      STRUCTURES        -----------------------------------------
// -------------------------------------------------------------------------------------------------------

/**
 * @brief Semi-sparse OTI array, structure of arrays: one active set for every element.
 *
 * With k = nbases, the array holds 1 + sshelp_ndir_total(k, trc_order) blocks of `size` reals.
 * Block 0 is the real part; order-p local direction i is block 1 + sshelp_order_offset(k, p) + i.
 * Each block is an nrows x ncols column-major matrix (element (r, c) at r + c*nrows), so all
 * blocks of one order form one nrows x (ncols * N_p(k)) column-major matrix.
 *
 * p_data holds at least (1 + sshelp_ndir_total(cap_bases, trc_order)) * size reals. Orders above
 * act_order hold zeros.
 */
typedef struct {
    coeff_t*    p_data; ///< Blocks, column-major; block 0 = real part.
    bases_t*   p_bases; ///< Sorted active global bases shared by every element, length nbases.
    bases_t     nbases; ///< Number of active bases (k).
    bases_t  cap_bases; ///< Allocated capacity of p_bases and p_data, in bases.
    ord_t    act_order; ///< Highest order that may hold nonzeros (<= trc_order).
    ord_t    trc_order; ///< Truncation order.
    uint64_t     nrows; ///< Number of rows.
    uint64_t     ncols; ///< Number of columns.
    uint64_t      size; ///< nrows * ncols.
    flag_t        flag; ///< Memory flag: 1 if the array owns its buffers, 0 for a view.
} oarrss_t;             ///< Semi-sparse SoA OTI array type.

/**
 * @brief LU factorization of a semi-sparse SoA matrix, for oarrss_lu_solve().
 *
 * Holds a copy of the matrix whose real block is replaced by the LAPACK LU factors of the real
 * part (dgetrf), plus the pivots. The imaginary blocks are kept as they are: the solve uses them
 * in the order-by-order recurrence.
 */
typedef struct {
    oarrss_t    A; ///< Matrix, real block = LU factors of the real part.
    int*   p_ipiv; ///< Pivot indices from dgetrf (1-based), length nrows.
} oarrss_lu_t;    ///< Semi-sparse SoA LU factorization type.

// -------------------------------------------------------------------------------------------------------
// -------------------------------------    END STRUCTURES      ------------------------------------------
// -------------------------------------------------------------------------------------------------------

#endif
