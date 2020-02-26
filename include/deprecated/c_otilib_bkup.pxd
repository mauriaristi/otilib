

#-----------------------------------------------------------------------------------------------------
#-----------------------------------   IMPORT EXTERNAL C FUNCTIONS   ---------------------------------
#-----------------------------------------------------------------------------------------------------
# File created just to remove all warnings from numpy.
# cdef extern from "pyoti/numpy_warning.h" nogil:
#   cdef int NPY_NO_DEPRECATED_API;

cdef extern from "oti/oti.h" nogil:
  
  

  

  

  

  

    
  cdef enum operEnum :  
    opAdd         =   1 , 
    opSub         =   2 , 
    opMul         =   3 , 
    opTruediv     =   4 , 
    opPowr        =   5 , 
    opInt1d       =   6 , 
    opInt2d       =   7 , 
    opInt3d       =   8 , 
    opDx          =   9 , 
    opDy          =   10, 
    opDz          =   11, 
    opDxx         =   12, 
    opDyy         =   13, 
    opDzz         =   14, 
    opDxy         =   15, 
    opDxz         =   16, 
    opDyz         =   17, 
    opDef         =   18, 
    opOn          =   19, 
    opNeg         =   20, 
    subOpDefBasis =   50, 
    subOpDefKnown =   51, 
    subOpInt      =   52, 
    subOpNeg      =   53, 
    subOpMulRes   =   54, 
    subOpMulKnown =   55, 
    subOpOn       =   56, 
    subOpIntBound =   57, 
    basisN        =  101, 
    basisNx       =  102, 
    basisNxx      =  103, 
    basisNy       =  104, 
    basisNxy      =  105, 
    basisNyy      =  106, 
    basisNz       =  107, 
    basisNxz      =  108, 
    basisNyz      =  109, 
    basisNzz      =  110, 
    kindOtiArr    =  200, 
    kindOtiNum    =  201, 
    kindReal      =  202, 
    kindScalar    =  203, 
    kindFunc      =  204, 
    feConstant    =  301, 
    feVariable    =  302, 
    elNode        =  400, 
    elLine        =  401, 
    elTriangle    =  402, 
    elQuadrangle  =  403, 
    elTetrahedra  =  404, 
    elHexahedra   =  405, 
    elkindIso     =  501, 
    elkindAff     =  502, 
    derN          =  601, 
    derNa         =  602, 
    derNaa        =  603, 
    derNb         =  604, 
    derNab        =  605, 
    derNbb        =  606, 
    derNc         =  607, 
    derNac        =  608, 
    derNbc        =  609, 
    derNcc        =  610, 
    feNatTest     =  701, 
    feNatUndef    =  702, 
    feNatDef      =  703, 
    feNatDefConst =  704, 
    feNatOperRes  =  705, 
    feNatPostIntK =  706, 
    feNatPostIntF =  707, 
    feNatBoundary =  708  

  

  #---------------------------------------------------------------------------------------------------












  # Include functions from "fem.h"
  #---------------------------------------------------------------------------------------------------
  uint8_t elem_is_started(   elem_t* elem );
  uint8_t elem_is_allocated( elem_t* elem );
  void elem_clear_flag_start(elem_t* elem );
  void elem_clear_flag_alloc(elem_t* elem );
  void elem_raise_flag_start(elem_t* elem );
  void elem_raise_flag_alloc(elem_t* elem );
  int64_t elem_end(elem_t* elem);

  int64_t elem_free( elem_t* elem );
  
  elem_t  elem_init(  );

  int64_t elem_start( elem_t* elem, uint64_t nbasis, int64_t geomBase, int64_t kind, uint8_t  ndim,
                int64_t (*basis_f)( int64_t, int64_t, darr_t*, void*, darr_t*) );

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








#-----------------------------------------------------------------------------------------------------
