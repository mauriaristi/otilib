// ----------------------------------------------------------------------------------------------------
// --------------------------------------      STRUCTURES        --------------------------------------
// ----------------------------------------------------------------------------------------------------

// typedef struct {
//     somin_t*      p_data; ///< Pointer to array of Sparse otinums.
//     uint64_t       nrows; ///< Number of rows.
//     uint64_t       ncols; ///< Number of cols.
//     uint64_t        size; ///< Size of array.
//     ndir_t*       p_size; ///< Allocated size per order.
//     ord_t          order; ///< Truncation order of the number.
//     flag_t          flag; ///< Memory flag.
// } arrso_t;                ///< Array of OTIs type.

// Structure for array of sparse OTI numbers

typedef struct {
    sotinum_t*    p_data; ///< Pointer to array of Sparse otinums.
    uint64_t       nrows; ///< Number of rows.
    uint64_t       ncols; ///< Number of cols.
    uint64_t        size; ///< Size of array.
    flag_t          flag; ///< Memory flag.
} arrso_t;                ///< Array of OTIs type.
// ----------------------------------------------------------------------------------------------------
// -------------------------------------    END STRUCTURES      ---------------------------------------
// ----------------------------------------------------------------------------------------------------
