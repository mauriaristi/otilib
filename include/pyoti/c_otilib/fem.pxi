
cdef extern from "oti/oti.h" nogil:

  # Defs from "fem.h"
  ctypedef struct elem_t:
    uint64_t      nbasis
    uint64_t       order
    int64_t     geomBase
    int64_t         kind
    uint8_t         ndim
    uint64_t     nIntPts
    uint8_t         nder
    uint8_t       isInit
    uint8_t nDimAnalysis
    darr_t        intPts
    darr_t        intWts
    darr_t*  p_evalBasis

  ctypedef struct elemso_t:
    # FE Properties
    uint64_t          nbasis # Number of basis - Number of degrees of freedom - Number of nodes.
    uint64_t           order # Integration order of the Element.
    int64_t         geomBase # Geometric element type - elLine, elTriangle, etc ...
    int64_t             kind # Kind of element: Affine - IsoParametric
    uint8_t             ndim # Number of dimensions of the element. (1 -> 1D, 2 -> 2D, 3 -> 3D)
    uint64_t             nip # Number of integration Points
    uint8_t             nder # Number of total derivatives in the problem.
    uint8_t           isInit # Initialization flag. 0: Not initialized, 1: Initialized.
    uint8_t     nDimAnalysis # Number of dimensions of the analysis.
    fesoti_t              xi # Gauss scalar with the canonical   xi point coordinates.
    fesoti_t             eta # Gauss scalar with the canonical  eta point coordinates.
    fesoti_t            zeta # Gauss scalar with the canonical zeta point coordinates.
    fesoti_t               w # Gauss scalar with the integration weights.
    fearrso_t*   p_evalBasis # (4) List of Gauss arrays (nbasis, 1) with the evaluated basis functions.


  ctypedef struct elemso_spt_t:
    # FEM Spatial variables 
    fearrso_t         J; # Gauss array (nDimAn x nDimEl) for Elemental Jacobian.
    fearrso_t      Jinv; # Gauss array (nDimEl x nDimAn) for Elemental inverse of Jacobian.
    fesoti_t       Jdet; # Gauss scalar with with the determinant of Jacobian.
    fesoti_t   p_w_detJ; # Gauss scalar with integration weights.
    fearrso_t*  p_basis; # (4) List of Gauss arrays (nbasis, 1) with the evaluated spatial basis functions. 
  
  # Include functions from "fem.h"
  #---------------------------------------------------------------------------------------------------


  

  # Gauss :: Array



  
  uint8_t elemso_is_started(   elemso_t* elemso );
  uint8_t elemso_is_allocated( elemso_t* elemso );
  void elemso_clear_flag_start(elemso_t* elemso );
  void elemso_raise_flag_start(elemso_t* elemso );
  void elemso_clear_flag_alloc(elemso_t* elemso );
  void elemso_raise_flag_alloc(elemso_t* elemso );
  int64_t elemso_end(elemso_t* elemso);
  int64_t elemso_free( elemso_t* elemso );
  elemso_t  elemso_init(  );
  int64_t elemso_start( elemso_t* elemso, uint64_t nbasis, int64_t geomBase,int64_t kind, uint8_t ndim, dhelpl_t dhl);
  int64_t elemso_allocate(elemso_t* elemso, uint64_t intorder, bases_t bases, ord_t order, dhelpl_t dhl);



  # Element
  uint8_t elem_is_started(   elem_t* elem );
  uint8_t elem_is_allocated( elem_t* elem );
  void elem_clear_flag_start(elem_t* elem );
  void elem_clear_flag_alloc(elem_t* elem );
  void elem_raise_flag_start(elem_t* elem );
  void elem_raise_flag_alloc(elem_t* elem );
  int64_t elem_end(elem_t* elem);
  int64_t elem_free( elem_t* elem );
  elem_t  elem_init(  );
  int64_t elem_start( elem_t* elem, uint64_t nbasis, int64_t geomBase, int64_t kind, uint8_t  ndim);
  int64_t elem_allocate(elem_t* elem, uint64_t intorder );
  int64_t fem_basisFunctions_N_QuadSerendP2_2Diso(int64_t basisId, int64_t basisDer, darr_t* coords,   
                                                void* other_data, darr_t* evalBasis);
  int64_t fem_basisFunctions_N_QuadP1_2Diso(int64_t basisId, int64_t basisDer, darr_t* coords,   
                                                void* other_data, darr_t* evalBasis);
  int64_t fem_basisFunctions_N_TriangP2_2Diso(int64_t basisId, int64_t basisDer, darr_t* coords,   
                                                void* other_data, darr_t* evalBasis);
  int64_t fem_basisFunctions_N_TriangP1_2Diso(int64_t basisId, int64_t basisDer, darr_t* coords,   
                                                void* other_data, darr_t* evalBasis);
  int64_t fem_basisFunctions_N_TriangP0_2Diso(int64_t basisId, int64_t basisDer, darr_t* coords,   
                                                void* other_data, darr_t* evalBasis);
  int64_t fem_basisFunctions_N_LineP2_1Diso(int64_t basisId, int64_t basisDer, darr_t* coords,   
                                                void* other_data, darr_t* evalBasis);
  int64_t fem_basisFunctions_N_LineP1_1Diso(int64_t basisId, int64_t basisDer, darr_t* coords,   
                                                void* other_data, darr_t* evalBasis);
  int64_t fem_basisFunctions_N_PntP0_0Diso(int64_t basisId, int64_t basisDer, darr_t* coords,   
                                                void* other_data, darr_t* evalBasis);

#-----------------------------------------------------------------------------------------------------

