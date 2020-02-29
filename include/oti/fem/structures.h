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


typedef struct{
  darr_t*      p_data; ///< Data array
  uint64_t      nrows; ///< Number of rows.
  uint64_t      ncols; ///< Number of cols.
  uint64_t    nIntPts; ///< Number of integration points.
  uint64_t    offsetx; ///< Offset x in the element formulation
  uint64_t    offsety; ///< Offset y in the element formulation
  uint64_t       size; ///< size of the array
} fedarr_t;


typedef struct elemprops_s{
    // OTI properties
    ord_t           otiorder; ///< Order of the oti numbers inside.
    bases_t        otinbases; ///< Number of bases of the oti algebra.
    // FEM Properties
    uint64_t          nbasis; ///< Number of basis - Number of degrees of freedom - Number of nodes.
    uint64_t           order; ///< Maximum order of 
    int64_t         geomBase; ///< Geometric element type - elLine, elTriangle, etc ...
    int64_t             kind; ///< Kind of element: Affine - IsoParametric
    uint8_t             ndim; ///< Number of dimensions of the element. (1 -> 1D, 2 -> 2D, 3 -> 3D)
    uint64_t         nIntPts; ///< Number of integration Points
    uint8_t             nder; ///< Number of total derivatives in the problem.
    uint8_t           isInit; ///< Initialization flag. 0: Not initialized, 1: Initialized.
    uint8_t     nDimAnalysis; ///< Number of dimensions of the analysis.
    darr_t       p_intPoints; ///< (nIntPts x ndim) Array with the integration points coordinates.
    darr_t      p_intWeights; ///< (nIntPts x 1   ) Array with the integration weights.
    darr_t*      p_evalBasis; ///< (nder) List of (nbasis x nIntPts) arrays with the evaluated basis
    feoarr_t               J; ///< (nDimAn x nDimEl) Holder for Jacobian               
    feoarr_t            Jinv; ///< (nDimEl x nDimAn) Holder for inverse of Jacobian      
    feoarr_t            Jdet; ///< (1 x 1)           Holder for Determinant of Jacobian. 
    feoarr_t*        p_basis; ///< (nder) List (1 x nbasis) basis of the function in spat. coords.
    feoarr_t    p_detWeights; ///< ( 1 x 1 ) Array with the integration weights.
    int64_t (*f_basis)(int64_t,int64_t,darr_t*,void*,darr_t*); ///<  Interpolation function.
} elemProps_t;

typedef struct elem_s{    
    // FEM Properties
    uint64_t          nbasis; ///< Number of basis - Number of degrees of freedom - Number of nodes.
    uint64_t           order; ///< Integration order of the Element.
    int64_t         geomBase; ///< Geometric element type - elLine, elTriangle, etc ...
    int64_t             kind; ///< Kind of element: Affine - IsoParametric
    uint8_t             ndim; ///< Number of dimensions of the element. (1 -> 1D, 2 -> 2D, 3 -> 3D)
    uint64_t         nIntPts; ///< Number of integration Points
    uint8_t             nder; ///< Number of total derivatives in the problem.
    uint8_t           isInit; ///< Initialization flag. 0: Not initialized, 1: Initialized.
    uint8_t     nDimAnalysis; ///< Number of dimensions of the analysis.
    darr_t            intPts; ///< (nIntPts x ndim) Array with the integration point coordinates.
    darr_t            intWts; ///< (nIntPts x 1   ) Array with the integration weights.
    darr_t*      p_evalBasis; ///< (nder) List of (nbasis x nIntPts) arrays with the evaluated basis functions.
                              // p_evalBasis[0] -> N  
                              // p_evalBasis[1] -> Na 
                              // p_evalBasis[2] -> Naa
                              // p_evalBasis[3] -> Nb 
                              // p_evalBasis[4] -> Nab
                              // p_evalBasis[5] -> Nbb
                              // p_evalBasis[6] -> Nc 
                              // p_evalBasis[7] -> Nac
                              // p_evalBasis[8] -> Nbc
                              // p_evalBasis[9] -> Ncc
    int64_t (*f_basis)(int64_t,int64_t,darr_t*,void*,darr_t*); ///<  Interpolation function.
    // 
} elem_t;


    // // This is something else
    // // OTI properties
    // ord_t           otiorder; ///< Order of the oti numbers inside.
    // bases_t        otinbases; ///< Number of bases of the oti algebra.
    // feoarr_t               J; ///< (nDimAn x nDimEl) Holder for Jacobian  
    // feoarr_t            Jinv; ///< (nDimEl x nDimAn) Holder for inverse of Jacobian
    // feoarr_t            Jdet; ///< (1 x 1)           Holder for Determinant of Jacobian.
    // feoarr_t*        p_basis; ///< (nder) List (1 x nbasis) basis of the function in spat. coords.
    // feoarr_t    p_detWeights; ///< ( 1 x 1 ) Array with the integration weights.



 

// ----------------------------------------------------------------------------------------------------
// -------------------------------------    END STRUCTURES      ---------------------------------------
// ----------------------------------------------------------------------------------------------------
