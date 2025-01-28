#ifndef OTI_SPARSE_CORE_STRUCTURES_H
#define OTI_SPARSE_CORE_STRUCTURES_H

// -------------------------------------------------------------------------------------------------------
// --------------------------------------      STRUCTURES        -----------------------------------------
// -------------------------------------------------------------------------------------------------------

typedef struct {
    ndir_t       nbases; ///< Actual number of bases. 64-bits for convenience (and not bases_t).
    ndir_t       ncoeff; ///< Total number of coefficients contained in the p_coeff and p_imidx arrays.
    ord_t      flags[8]; ///< Contains 8 contiguous bytes with some flags of for the OTI number.
                         ///< TODO: Consider moving these flags to each OTI structure. Typically, that will
                         ///< handle memory rather than this OTI struct.
    imdir_t*    p_imidx; ///< (ncoeff) Indices of the im. dirs associated to each coefficient per order.
    bases_t*    p_bases; ///< (nbases) Array with the active bases in the OTI number.
    ndir_t*    p_ordptr; ///< (act_order+2) Array with the start-end positions of the coeffs for each order.
                         ///< flags[0]:  Truncation order.
                         ///< flags[1]:  Actual order of the number.
                         ///< flags[2]:  Mem. ownership flag: 1 if this structure owns memory, 0 otherwise
                         ///< flags[3:]: not in use.
    // int64_t    coef_str; ///< Stride of coefficient array.
    // int64_t    indx_str; ///< Stride of indices array.
} soticore_t;             ///< Sparse OTI number type.

// -------------------------------------------------------------------------------------------------------
// -------------------------------------    END STRUCTURES      ------------------------------------------
// -------------------------------------------------------------------------------------------------------

#endif