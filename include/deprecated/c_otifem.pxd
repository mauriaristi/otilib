from c_otilib cimport *

#-----------------------------------------------------------------------------------------------------
#-----------------------------------   IMPORT EXTERNAL C FUNCTIONS   ---------------------------------
#-----------------------------------------------------------------------------------------------------
cdef extern from "oti/otifem.h" :

  ctypedef struct femarray_t:
    sotiarray_t* p_data
    uint64_t      nrows
    uint64_t      ncols
    uint64_t    nIntPts
    uint64_t    offsetx
    uint64_t    offsety
    uint64_t       size
    uint8_t       order

  ctypedef struct elemProps_t: 
    uint64_t          nbasis; # Number of basis - Number of degrees of freedom - Number of nodes.
    uint64_t           order; # Maximum order of 
    int64_t         geomBase; # Geometric element type - elLine, elTriangle, etc ...
    int64_t             kind; # Kind of element: Affine - IsoParametric
    uint8_t             ndim; # Number of dimensions of the element. (1 -> 1D, 2 -> 2D, 3 -> 3D)
    uint64_t         nIntPts; # Number of integration Points
    uint8_t             nder; # Number of total derivatives in the problem.
    uint8_t           isInit; # Initialization flag. 0: Not initialized, 1: Initialized.
    uint8_t         otiorder; # Order of the soti numbers inside.
    uint8_t     nDimAnalysis; # Number of dimensions of the analysis.
    darray_t     p_intPoints; # (nIntPts x ndim) Array with the integration points coordinates.
    darray_t    p_intWeights; # (nIntPts x 1   ) Array with the integration weights.
    darray_t*    p_evalBasis; # (nder) List of (nbasis x nIntPts) arrays with the evaluated basis
    femarray_t             J; # Holder for Jacobian               
    femarray_t          Jinv; # Holder for inverse of Jacobian      
    femarray_t          Jdet; # Holder for Determinant of Jacobian. 
    femarray_t*      p_basis; # (nder) List (1 x nbasis) basis of the function in spat. coords.
    femarray_t  p_detWeights; # (nIntPts x 1   ) Array with the integration weights.
    int64_t (*f_basis)(int64_t,int64_t,darray_t*,void*,darray_t*); #  Interpolation function.

  

  
  #---------------------------------------------------------------------------------------------------




  # Enums
  # Enumerator to assign a code to operators
  cdef enum operEnum:
    opAdd        ,
    opSub        ,
    opMul        ,
    opTruediv    ,
    opPowr       ,
    opInt1d      ,
    opInt2d      ,
    opInt3d      ,
    opDx         ,
    opDxx        ,
    opDy         ,
    opDxy        ,
    opDyy        ,
    opDz         ,
    opDxz        ,
    opDyz        ,
    opDzz        ,
    opDef        ,
    opOn         ,
    opNeg        ,
    subOpDefBasis,
    subOpDefKnown,
    subOpInt     ,
    subOpNeg     ,
    subOpMulRes  ,
    subOpMulKnown,
    subOpOn      ,
    basisN       ,
    basisNx      ,
    basisNxx     ,
    basisNy      ,
    basisNxy     ,
    basisNyy     ,
    basisNz      ,
    basisNxz     ,
    basisNyz     ,
    basisNzz     ,
    kindOtiArr   ,
    kindOtiNum   ,
    kindReal     ,
    kindScalar   ,
    kindFunc     ,
    constant     ,
    variable     ,
    elNode       ,
    elLine       ,
    elTriangle   ,
    elQuadrangle ,
    elTetrahedra ,
    elHexahedra  ,
    elkindIso    ,
    elkindAff    ,
    derN         ,
    derNa        ,
    derNaa       ,
    derNb        ,
    derNab       ,
    derNbb       ,
    derNc        ,
    derNac       ,
    derNbc       ,
    derNcc       ,
    feNatTest    ,
    feNatUndef   ,
    feNatDef     ,
    feNatDefConst,
    feNatOperRes ,
    feNatPostIntK,
    feNatPostIntF,
    feNatBoundary 

  #---------------------------------------------------------------------------------------------------
  int64_t c_fem_defFunctFrom_otiFunc(sotiarray_t* p_arr1, uint64_t derIndx, elemProps_t* elem, femarray_t* p_arrRes,
      directionHelper* p_dH)

  int64_t c_fem_defFunctFrom_oti(sotinum_t* num, uint64_t derIndx, elemProps_t* elem, femarray_t* p_arrRes,
      directionHelper* p_dH)

  int64_t c_fem_defFunctFrom_R(double num, uint64_t derIndx, elemProps_t* elem, femarray_t* p_arrRes,
      directionHelper* p_dH)




  void c_femarray_neg(femarray_t* p_arr1, femarray_t* p_arrRes)

  void c_femarray_fromOther(femarray_t* p_arr1, femarray_t* p_res)

  int64_t c_fem_basisFunctions_N_LineP2_1Diso(int64_t basisId, int64_t basisDer, darray_t* coords,   
                                                void* other_data, darray_t* evalBasis)

  int64_t c_fem_basisFunctions_N_LineP1_1Diso(int64_t basisId, int64_t basisDer, darray_t* coords,   
                                                void* other_data, darray_t* evalBasis)

  int64_t c_fem_basisFunctions_N_PntP0_0Diso(int64_t basisId, int64_t basisDer, darray_t* coords,   
                                                void* other_data, darray_t* evalBasis)

  void c_femarray_gaussIntegrateOverElement(femarray_t* p_arr1, elemProps_t* elem, sotiarray_t* p_arrRes, 
    directionHelper* p_dH)

  int64_t c_fem_defineSpatial( elemProps_t* elem, uint16_t derFlags, directionHelper* p_dH)

  int64_t c_fem_computeJacobian( elemProps_t* elem, sotiarray_t* xcoords, sotiarray_t* ycoords,
                                 sotiarray_t* zcoords, directionHelper* p_dH)

  void c_femarray_sub(femarray_t* p_arr1, femarray_t* p_arr2, femarray_t* p_arrRes, 
    directionHelper* p_dH)

  void c_femarray_sum(femarray_t* p_arr1, femarray_t* p_arr2, femarray_t* p_arrRes, 
      directionHelper* p_dH)

  void c_femarray_mul_oti(femarray_t* p_arr1, sotinum_t* num2, femarray_t* p_arrRes, 
      directionHelper* p_dH)

  void c_femarray_mul_R(femarray_t* p_arr1, double num2, femarray_t* p_arrRes)

  void c_femarray_matmul(femarray_t* p_arr1, femarray_t* p_arr2, femarray_t* p_arrRes, 
      directionHelper* p_dH)

  void c_femarray_det(femarray_t* p_arr1, femarray_t* p_arrRes, directionHelper* p_dH)

  void c_femarray_invert(femarray_t* p_arr1, femarray_t* p_arrRes, directionHelper* p_dH)

  void c_femarray_getItem_ij(femarray_t* p_arr1, uint64_t i, uint64_t j,femarray_t* p_arrRes)

  void c_femarray_getItem_k(femarray_t* p_arr1, uint64_t k, 
          sotiarray_t* p_arrRes)

  void c_femarray_getItem_ijk(femarray_t* p_arr1, uint64_t i, uint64_t j, uint64_t k, 
          sotinum_t* p_res)

  void c_femarray_setItem_ij(femarray_t* p_arr1, uint64_t i, uint64_t j, femarray_t* p_arrRes)

  void c_femarray_setItem_k( sotiarray_t* p_arr1 , uint64_t k, femarray_t* p_arrRes)

  void c_femarray_setItem_ijk(sotinum_t* p_num, uint64_t i, uint64_t j, uint64_t k, 
          femarray_t* p_arrRes)

  void c_femarray_invert(femarray_t* p_arr1, femarray_t* p_arrRes, directionHelper* p_dH)

  void c_femarray_zeros(femarray_t* p_array, uint64_t nrows, uint64_t ncols, 
                      uint64_t offsetx, uint64_t offsety, uint64_t nIntPts, uint8_t order)

  void c_femarray_free(femarray_t* p_array)

  void c_femarray_createEmpty(femarray_t* p_array, uint64_t nrows, uint64_t ncols, 
                      uint64_t offsetx, uint64_t offsety, uint64_t nIntPts, uint8_t order)

  int64_t c_fem_unInitElement(elemProps_t* elem)

  int64_t c_fem_initElement(uint64_t order, uint8_t otiorder,uint8_t nDimAnalysis, elemProps_t* elem)

  int64_t c_fem_integrateSOTIfunct(sotiarray_t* f_eval, darray_t* weights, sotinum_t* res,
                                   directionHelper* p_dH)
  
  int64_t c_fem_integrationPoints(uint64_t order, int64_t elementType, 
                                  darray_t* coords, darray_t* weights)

  uint64_t c_fem_addLineIntegrationPoints(uint8_t numberOfPermutations, uint64_t startPoint, 
                                             double a,  double w,
                                             darray_t* coords, darray_t* weights)

  uint64_t c_fem_addTriangleIntegrationPoints(uint8_t numberOfPermutations, uint64_t startPoint, 
                                             double a, double b, double c, double w,
                                             darray_t* coords, darray_t* weights)

  int64_t c_fem_basisFunctions_N_QuadSerendP2_2Diso(int64_t basisId, int64_t basisDer, darray_t* coords,   
                                              void* other_data, darray_t* evalBasis)

  int64_t c_fem_basisFunctions_N_QuadP1_2Diso(int64_t basisId, int64_t basisDer, darray_t* coords,   
                                              void* other_data, darray_t* evalBasis)


  int64_t c_fem_basisFunctions_N_TriangP2_2Diso(int64_t basisId, int64_t basisDer, darray_t* coords,   
                                              void* other_data, darray_t* evalBasis)


  int64_t c_fem_basisFunctions_N_TriangP1_2Diso(int64_t basisId, int64_t basisDer, darray_t* coords,   
                                              void* other_data, darray_t* evalBasis)


  int64_t c_fem_basisFunctions_N_TriangP0_2Diso(int64_t basisId, int64_t basisDer, darray_t* coords,   
                                              void* other_data, darray_t* evalBasis)

  int64_t c_fem_basisFunctions_N_LineP2_1Diso(int64_t basisId, int64_t basisDer, darray_t* coords,   
                                              void* other_data, darray_t* evalBasis)

  int64_t c_fem_basisFunctions_N_LineP1_1Diso(int64_t basisId, int64_t basisDer, darray_t* coords,   
                                              void* other_data, darray_t* evalBasis)

  int64_t c_fem_basisFunctions_N_PntP0_0Diso(int64_t basisId, int64_t basisDer, darray_t* coords,   
                                              void* other_data, darray_t* evalBasis)


#-----------------------------------------------------------------------------------------------------







#-----------------------------------------------------------------------------------------------------
