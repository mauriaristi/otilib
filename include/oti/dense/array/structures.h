#ifndef OTI_DENSE_ARRAY_STRUCTURES_H
#define OTI_DENSE_ARRAY_STRUCTURES_H

// ----------------------------------------------------------------------------------------------------
// --------------------------------------      STRUCTURES        --------------------------------------
// ----------------------------------------------------------------------------------------------------

typedef struct {
    arr_t            re;  ///< Real Coefficient.
    arr_t**        p_im;  ///< Array of imaginary coefficients.
    ndir_t*      p_ndpo;  ///< Number of imaginary directions per order.
    ndir_t         ndir;  ///< Number of imaginary directions.
    bases_t      nbases;  ///< Number of bases.
    ord_t         order;  ///< Truncation order.
    uint64_t      nrows;  ///< Number of rows of every array.
    uint64_t      ncols;  ///< Number of columns of every array.
    uint64_t       size;  ///< Total number of elements in per array.
} oarr_t;     ///< OTI array type.

// ----------------------------------------------------------------------------------------------------
// -------------------------------------    END STRUCTURES      ---------------------------------------
// ----------------------------------------------------------------------------------------------------

#endif