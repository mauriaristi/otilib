#ifndef OTI_FEM_ELEMENT_SOTI_STRUCTURES_H
#define OTI_FEM_ELEMENT_SOTI_STRUCTURES_H

// ----------------------------------------------------------------------------------------------------
// --------------------------------------      STRUCTURES        --------------------------------------
// ----------------------------------------------------------------------------------------------------


typedef struct elemso_s{    
    // FEM Properties
    uint64_t          nbasis; ///< Number of basis - Number of degrees of freedom - Number of nodes.
    uint64_t           order; ///< Integration order of the Element.
    int64_t         geomBase; ///< Geometric element type - elLine, elTriangle, etc ...
    int64_t             kind; ///< Kind of element: Affine - IsoParametric
    uint8_t             ndim; ///< Number of dimensions of the element. (1 -> 1D, 2 -> 2D, 3 -> 3D)
    uint64_t             nip; ///< Number of integration Points
    uint8_t             nder; ///< Number of total derivatives in the problem.
    uint8_t           isInit; ///< Initialization flag. 0: Not initialized, 1: Initialized.
    uint8_t     nDimAnalysis; ///< Number of dimensions of the analysis.
    fesoti_t              xi; ///< Gauss scalar with the canonical   xi point coordinates.
    fesoti_t             eta; ///< Gauss scalar with the canonical  eta point coordinates.
    fesoti_t            zeta; ///< Gauss scalar with the canonical zeta point coordinates.
    fesoti_t               w; ///< Gauss scalar with the integration weights.
    fearrso_t*   p_evalBasis; ///< (4) List of Gauss arrays (nbasis, 1) with the evaluated basis functions.
                              // p_evalBasis[0] -> N  
                              // p_evalBasis[1] -> Na 
                              // p_evalBasis[2] -> Nb 
                              // p_evalBasis[3] -> Nc 
                              // p_evalBasis[4] -> Naa
                              // p_evalBasis[5] -> Nab
                              // p_evalBasis[6] -> Nbb
                              // p_evalBasis[7] -> Nac
                              // p_evalBasis[8] -> Nbc
                              // p_evalBasis[9] -> Ncc
} elemso_t;


typedef struct elemso_spt_s{    
    // FEM Spatial variables 
    fearrso_t         J; ///< Gauss array (nDimAn x nDimEl) for Elemental Jacobian.
    fearrso_t      Jinv; ///< Gauss array (nDimEl x nDimAn) for Elemental inverse of Jacobian.
    fesoti_t       Jdet; ///< Gauss scalar with with the determinant of Jacobian.
    fesoti_t   p_w_detJ; ///< Gauss scalar with integration weights.
    fearrso_t*  p_basis; ///< (nder) List (1 x nbasis) basis of the function in spatial coords.
                         //  p_basis[0] -> N  
                         //  p_basis[1] -> Nx 
                         //  p_basis[2] -> Ny 
                         //  p_basis[3] -> Nz 
                         //  p_basis[4] -> Nxx
                         //  p_basis[5] -> Nxy
                         //  p_basis[6] -> Nyy
                         //  p_basis[7] -> Nxz
                         //  p_basis[8] -> Nyz
                         //  p_basis[9] -> Nzz
} elemso_spt_t;


 

// ----------------------------------------------------------------------------------------------------
// -------------------------------------    END STRUCTURES      ---------------------------------------
// ----------------------------------------------------------------------------------------------------



#endif 