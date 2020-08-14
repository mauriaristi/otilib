#ifndef OTI_SPARSE_ARRAY_GAUSS_STRUCTURES_H
#define OTI_SPARSE_ARRAY_GAUSS_STRUCTURES_H

// ----------------------------------------------------------------------------------------------------
// --------------------------------------      STRUCTURES        --------------------------------------
// ----------------------------------------------------------------------------------------------------

typedef struct{
    arrso_t*      p_data; ///< Data array
    uint64_t      nrows;  ///< Number of rows.
    uint64_t      ncols;  ///< Number of cols.
    uint64_t       size;  ///< size of the array
    uint64_t        nip;  ///< Number of integration points.
    // uint64_t    offsetx;  ///< Offset x in the element formulation
    // uint64_t    offsety;  ///< Offset y in the element formulation
} fearrso_t;

// ----------------------------------------------------------------------------------------------------
// -------------------------------------    END STRUCTURES      ---------------------------------------
// ----------------------------------------------------------------------------------------------------


#endif