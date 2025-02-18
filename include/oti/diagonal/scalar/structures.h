#ifndef OTI_DIAGONAL_SCALAR_STRUCTURES_H
#define OTI_DIAGONAL_SCALAR_STRUCTURES_H

// ----------------------------------------------------------------------------------------------------
// --------------------------------------      STRUCTURES        --------------------------------------
// ----------------------------------------------------------------------------------------------------

typedef struct {
    coeff_t*      p_im; ///< Array with all imaginary coefficients per order.
    imdir_t*   p_bases; ///< Directions associated to each coefficient per order.
    ndir_t*      p_nnz; ///< Number of non zero coefficients per order.
    ndir_t*     p_size; ///< Allocated size per order.
    ord_t    act_order; ///< Actual order of the number.
    ord_t    trc_order; ///< Truncation order of the number.
    flag_t       flags; ///< Memory flag.
} sdoti_t;              ///< Sparse Diagonal OTI number type.


// ----------------------------------------------------------------------------------------------------
// -------------------------------------    END STRUCTURES      ---------------------------------------
// ----------------------------------------------------------------------------------------------------

#endif