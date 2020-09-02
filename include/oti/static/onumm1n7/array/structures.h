#ifndef OTI_ONUMM1N7_ARRAY_STRUCTURES_H
#define OTI_ONUMM1N7_ARRAY_STRUCTURES_H

// ----------------------------------------------------------------------------------------------------
// --------------------------------------      STRUCTURES        --------------------------------------
// ----------------------------------------------------------------------------------------------------

// Structure for array of sparse OTI numbers (2D)

typedef struct {
    onumm1n7_t*    p_data; ///< Pointer to array of Sparse otinums.
    uint64_t       nrows; ///< Number of rows.
    uint64_t       ncols; ///< Number of cols.
    uint64_t        size; ///< Size of array.
    flag_t          flag; ///< Memory flag.
} oarrm1n7_t;                ///< Array of OTIs type.

// ----------------------------------------------------------------------------------------------------
// -------------------------------------    END STRUCTURES      ---------------------------------------
// ----------------------------------------------------------------------------------------------------

#endif