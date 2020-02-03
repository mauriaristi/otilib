// ----------------------------------------------------------------------------------------------------
// --------------------------------------      STRUCTURES        --------------------------------------
// ----------------------------------------------------------------------------------------------------

typedef struct {
    arr_t            re;  ///< Real coefficient array.
    arr_t**        p_im;  ///< Imaginary coefficients. (all arrays).
    imdir_t**     p_idx;  ///< Directions associated to each coefficient per order.
    ndir_t*       p_nnz;  ///< Number of non zero coefficients per order.
    ndir_t*      p_size;  ///< Allocated size per order.
    ord_t         order;  ///< Truncation order of the number.
    uint64_t       nrows; ///< Number of rows.
    uint64_t       ncols; ///< Number of cols.
    uint64_t        size; ///< Size of array.
} soarr_t;                ///< Sparse OTI of arrays type.


// ----------------------------------------------------------------------------------------------------
// -------------------------------------    END STRUCTURES      ---------------------------------------
// ----------------------------------------------------------------------------------------------------