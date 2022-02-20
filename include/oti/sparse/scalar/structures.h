#ifndef OTI_SPARSE_SCALAR_STRUCTURES_H
#define OTI_SPARSE_SCALAR_STRUCTURES_H

// ----------------------------------------------------------------------------------------------------
// --------------------------------------      STRUCTURES        --------------------------------------
// ----------------------------------------------------------------------------------------------------

// typedef struct {
//     coeff_t          re; ///< Real coefficient.
//     coeff_t**      p_im; ///< Array with all imaginary coefficients per order.
// } soticoef_t;            ///< Sparse OTI number type

typedef struct {
    coeff_t          re; ///< Real coefficient.
    coeff_t**      p_im; ///< Array with all imaginary coefficients per order.
    imdir_t**     p_idx; ///< Directions associated to each coefficient per order.
    ndir_t*       p_nnz; ///< Number of non zero coefficients per order.
    ndir_t*      p_size; ///< Allocated size per order.
    ord_t     act_order; ///< Actual order of the number.
    ord_t     trc_order; ///< Truncation order of the number.
    flag_t         flag; ///< Memory flag.
} sotinum_t;             ///< Sparse OTI number type.


typedef struct {
    coeff_t          re; ///< Real coefficient.
    coeff_t**      p_im; ///< Array with all imaginary coefficients per order.
    imdir_t**     p_idx; ///< Directions associated to each coefficient per order.
    ndir_t*       p_nnz; ///< Number of non zero coefficients per order.
} somin_t;               ///< Minimal sparse OTI number type. 

typedef struct {
    sotinum_t*   p_data; ///< Temporal list.
    ndir_t        nTmps; ///< Number of temporals.
} sotmpl_t;               ///< Direction helper specific for Sparse OTI type.


// ----------------------------------------------------------------------------------------------------
// -------------------------------------    END STRUCTURES      ---------------------------------------
// ----------------------------------------------------------------------------------------------------

#endif