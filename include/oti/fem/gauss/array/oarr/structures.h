#ifndef OTI_FEM_GAUSS_ARRAY_OARR_STRUCTURES_H
#define OTI_FEM_GAUSS_ARRAY_OARR_STRUCTURES_H


// ----------------------------------------------------------------------------------------------------
// --------------------------------------      STRUCTURES        --------------------------------------
// ----------------------------------------------------------------------------------------------------

typedef struct{
    oarr_t*      p_data; ///< Data array
    uint64_t      nrows; ///< Number of rows.
    uint64_t      ncols; ///< Number of cols.
    uint64_t    nIntPts; ///< Number of integration points.
    uint64_t    offsetx; ///< Offset x in the element formulation
    uint64_t    offsety; ///< Offset y in the element formulation
    uint64_t       size; ///< size of the array
    bases_t      nbases; ///< Number of bases
    ord_t         order; ///< oti order    
} feoarr_t;

// ----------------------------------------------------------------------------------------------------
// -------------------------------------    END STRUCTURES      ---------------------------------------
// ----------------------------------------------------------------------------------------------------



#endif