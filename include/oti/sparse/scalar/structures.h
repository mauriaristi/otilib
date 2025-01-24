#ifndef OTI_SPARSE_SCALAR_STRUCTURES_H
#define OTI_SPARSE_SCALAR_STRUCTURES_H

// ----------------------------------------------------------------------------------------------------
// --------------------------------------      STRUCTURES        --------------------------------------
// ----------------------------------------------------------------------------------------------------

typedef struct {
    coeff_t         re; ///< Dummy real coefficient to avoid allocation for real-only cases.
    coeff_t*   p_coeff; ///< (ncoeff) Array with OTI imaginary coefficients.
    soticore_t    _oti; ///< Sparse OTI core structure.
    // int64_t stride;    //// Defines a skip size two actual coefficients in p_coeff.
} sotinum_t;

typedef struct {
    zcoeff_t          re; ///< Dummy real coefficient to avoid allocation for real-only cases.
    zcoeff_t*    p_coeff; ///< (ncoeff) Array with OTI imaginary coefficients.
    soticore_t     _oti; ///< Sparse OTI core structure.
    // int64_t stride;    //// Defines a skip size two actual coefficients in p_coeff.
} zsotinum_t; // Complex OTI number.




// ----------------------------------------------------------------------------------------------------
// -------------------------------------    END STRUCTURES      ---------------------------------------
// ----------------------------------------------------------------------------------------------------

#endif