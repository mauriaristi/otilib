#ifndef OTI_DENSE_SCALAR_STRUCTURES_H
#define OTI_DENSE_SCALAR_STRUCTURES_H
// ----------------------------------------------------------------------------------------------------
// --------------------------------------      STRUCTURES        --------------------------------------
// ----------------------------------------------------------------------------------------------------

typedef struct {
    coeff_t          re;  ///< Real Coefficient.
    coeff_t**      p_im;  ///< Array of imaginary coefficients.
    ndir_t*      p_ndpo;  ///< Number of imaginary directions per order.
    ndir_t         ndir;  ///< Number of imaginary directions.
    bases_t      nbases;  ///< Number of bases.
    ord_t         order;  ///< Truncation order. 
} otinum_t;  ///< OTI scalar type.

// ----------------------------------------------------------------------------------------------------
// -------------------------------------    END STRUCTURES      ---------------------------------------
// ----------------------------------------------------------------------------------------------------

#endif