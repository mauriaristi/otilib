#ifndef OTI_SEMISPARSE_SCALAR_STRUCTURES_H
#define OTI_SEMISPARSE_SCALAR_STRUCTURES_H

// ----------------------------------------------------------------------------------------------------
// --------------------------------------      STRUCTURES        --------------------------------------
// ----------------------------------------------------------------------------------------------------


typedef struct {
    coeff_t          re; ///< Real coefficient.
    coeff_t**      p_im; ///< Array with all imaginary coefficients per order.
    bases_t      nbases; ///< Number of basis for current oti number.
    ord_t     act_order; ///< Actual order of the number (does not det mem. Is <= trc_order).
    ord_t     trc_order; ///< Truncation order of the number. (Determines memory for number).
    flag_t         flag; ///< Memory flag.
} semiotin_t;          ///< Semi sparse OTI number type.
  

// ----------------------------------------------------------------------------------------------------
// -------------------------------------    END STRUCTURES      ---------------------------------------
// ----------------------------------------------------------------------------------------------------

#endif