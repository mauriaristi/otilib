
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
    # int64_t (*f_basis)(int64_t,int64_t,darr_t*,void*,darr_t*) nogil


  
  # Include functions from "fem.h"
  #---------------------------------------------------------------------------------------------------


  

  # Gauss :: Array

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

