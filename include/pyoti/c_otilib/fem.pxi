
cdef extern from "oti/oti.h" nogil:


  # From oti/fem/enums.h

  cdef enum operEnum : # {  
    opAdd         =   1 ,
    opSub         =   2 ,
    opMul         =   3 ,
    opTruediv     =   4 ,
    opPowr        =   5 ,
    
    opInt0d       =  60 ,
    opInt1d       =   6 ,
    opInt2d       =   7 ,
    opInt3d       =   8 ,

    opDx          =   9 ,
    opDy          =   10,
    opDz          =   11,
    opDxx         =   12,
    opDxy         =   13,
    opDyy         =   14,
    opDxz         =   15,
    opDyz         =   16,
    opDzz         =   17,

    opDef         =   18,
    opDefData     =   61,
    opOn          =   19,
    opNeg         =   20,

    opDxi         =   21,
    opDeta        =   22,
    opDzeta       =   23,
    opDxixi       =   24,
    opDxieta      =   25,
    opDetaeta     =   26,
    opDxizeta     =   27,
    opDetazeta    =   28,
    opDzetazeta   =   29,

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
    basisNy       =  103,
    basisNz       =  104,
    basisNxx      =  105,
    basisNxy      =  106,
    basisNyy      =  107,
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
    derNb         =  603,
    derNc         =  604,
    derNaa        =  605,
    derNab        =  606,
    derNbb        =  607,
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
    feNatBoundary =  708,
    feUndefined   =  709 
  # };

  # From oti/fem/gauss/array/oarr/structures.h

  ctypedef struct feoarr_t: # {
      oarr_t*      p_data;
      uint64_t      nrows;
      uint64_t      ncols;
      uint64_t    nIntPts;
      uint64_t    offsetx;
      uint64_t    offsety;
      uint64_t       size;
      bases_t      nbases;
      ord_t         order;
  # } feoarr_t;
  
  # From oti/fem/element/real/structures.h

  ctypedef struct elemProps_t: # {
      ord_t           otiorder;
      bases_t        otinbases;
      uint64_t          nbasis;
      uint64_t           order;
      int64_t         geomBase;
      int64_t             kind;
      uint8_t             ndim;
      uint64_t         nIntPts;
      uint8_t             nder;
      uint8_t           isInit;
      uint8_t     nDimAnalysis;
      darr_t       p_intPoints;
      darr_t      p_intWeights;
      darr_t*      p_evalBasis;
      feoarr_t               J;
      feoarr_t            Jinv;
      feoarr_t            Jdet;
      feoarr_t*        p_basis;
      feoarr_t    p_detWeights;
      int64_t (*f_basis)(int64_t,int64_t,darr_t*,void*,darr_t*);
  # } elemProps_t;
  ctypedef struct elem_t: # {    
      uint64_t          nbasis;
      uint64_t           order;
      int64_t         geomBase;
      int64_t             kind;
      uint8_t             ndim;
      uint64_t         nIntPts;
      uint8_t             nder;
      uint8_t           isInit;
      uint8_t     nDimAnalysis;
      darr_t            intPts;
      darr_t            intWts;
      darr_t*      p_evalBasis;
  # } elem_t;


  # From oti/fem/element/soti/structures.h

  ctypedef struct elemso_t: # {    
      uint64_t          nbasis;
      uint64_t           order;
      int64_t         geomBase;
      int64_t             kind;
      uint8_t             ndim;
      uint64_t             nip;
      uint8_t             nder;
      uint8_t           isInit;
      uint8_t     nDimAnalysis;
      fesoti_t              xi;
      fesoti_t             eta;
      fesoti_t            zeta;
      fesoti_t               w;
      fearrso_t*   p_evalBasis;
  # } elemso_t;
  ctypedef struct elemso_spt_t: # {    
      fearrso_t         J;
      fearrso_t      Jinv;
      fesoti_t       Jdet;
      fesoti_t   p_w_detJ;
      fearrso_t*  p_basis;
  # } elemso_spt_t;
   


  


  # From oti/fem/gauss/array/darr/structures.h

  ctypedef struct fedarr_t: # {
      arrso_t*      p_data;
      uint64_t      nrows;
      uint64_t      ncols;
      uint64_t    nIntPts;
      uint64_t    offsetx;
      uint64_t    offsety;
      uint64_t       size;
  # } fedarr_t;


  # From oti/fem/gauss/scalar/real/structures.h

  ctypedef struct fereal_t: # {
      coeff_t*  p_data;
      uint64_t    nIntPts;
  # } fereal_t;


  # From oti/fem/gauss/scalar/otinum/structures.h

  ctypedef struct feotinum_t: # {
      otinum_t*  p_data;
      uint64_t   nIntPts;
  # } feotinum_t;


  # =========================================================================================

  # From oti/fem/integration_points.h



  # From oti/fem/element.h



  # From oti/fem/feoarr.h

  void feoarr_gaussIntegrateOverElement(feoarr_t* arr1, elemProps_t* elem, oarr_t* res,
      dhelpl_t dhl);
  void feoarr_sub_FF_to(feoarr_t* arr1, feoarr_t* arr2, feoarr_t* res, dhelpl_t dhl);
  void feoarr_sum_FF_to(feoarr_t* arr1, feoarr_t* arr2, feoarr_t* res, dhelpl_t dhl);
  void feoarr_neg_to(feoarr_t* arr, feoarr_t* res, dhelpl_t dhl);
  void feoarr_mul_oF_to( otinum_t* num, feoarr_t* arr, feoarr_t* res, dhelpl_t dhl);
  void feoarr_mul_rF_to(coeff_t num, feoarr_t* arr, feoarr_t* res, dhelpl_t dhl);
  void feoarr_matmul_to(feoarr_t* lhs, feoarr_t* rhs, feoarr_t* res, dhelpl_t dhl);
  void feoarr_det_to(feoarr_t* arr, feoarr_t* res, dhelpl_t dhl);
  void feoarr_invert_to(feoarr_t* arr, feoarr_t* res, dhelpl_t dhl);
  void feoarr_copy_to(feoarr_t* src, feoarr_t* dst, dhelpl_t dhl);
  feoarr_t feoarr_copy(feoarr_t* src, dhelpl_t dhl);
  void feoarr_get_item_ij_to(feoarr_t* arr, uint64_t i, uint64_t j, feoarr_t* res,dhelpl_t dhl);
  void feoarr_get_item_k_to(feoarr_t* arr, uint64_t k, oarr_t* res,dhelpl_t dhl);
  void feoarr_get_item_ijk_to(feoarr_t* arr, uint64_t i, uint64_t j, uint64_t k, otinum_t* res,dhelpl_t dhl);
  void feoarr_set_item_ij(feoarr_t* arr, uint64_t i, uint64_t j, feoarr_t* res, dhelpl_t dhl);
  void feoarr_set_item_k( oarr_t* arr , uint64_t k, feoarr_t* res, dhelpl_t dhl);
  void feoarr_set_item_ijk(otinum_t* num, uint64_t i, uint64_t j, uint64_t k, feoarr_t* res, dhelpl_t dhl);
  feoarr_t feoarr_zeros( uint64_t nrows, uint64_t ncols, uint64_t offsetx, uint64_t offsety,
                         uint64_t nIntPts, bases_t nbases, ord_t order, dhelpl_t dhl);
  
  void feoarr_free(feoarr_t* arr);
  feoarr_t feoarr_init();
  feoarr_t feoarr_createEmpty( uint64_t nrows, uint64_t ncols, uint64_t offsetx, uint64_t offsety,
                               uint64_t nIntPts, bases_t nbases, ord_t order, dhelpl_t dhl);


  # From oti/fem/gauss.h



  # From oti/fem/functions.h

  int64_t fem_defFunctFrom_otiFunc(oarr_t* arr1, uint64_t derIndx, elemProps_t* elem, feoarr_t* res,
      dhelpl_t dhl);
  int64_t fem_defFunctFrom_oti(otinum_t* num, uint64_t derIndx, elemProps_t* elem, feoarr_t* res,
      dhelpl_t dhl);
  int64_t fem_defFunctFrom_R(coeff_t num, uint64_t derIndx, elemProps_t* elem, feoarr_t* res,
      dhelpl_t dhl);
  int64_t fem_defineSpatial( elemProps_t* elem, uint16_t derFlags, dhelpl_t dhl);
  int64_t fem_computeJacobian( elemProps_t* elem, oarr_t* xcoords, oarr_t* ycoords,
                                 oarr_t* zcoords, dhelpl_t dhl);
  int64_t fem_unInitElement(elemProps_t* elem);
  int64_t fem_initElement(uint64_t order, uint8_t otiorder,uint8_t nDimAnalysis, elemProps_t* elem);
  int64_t fem_integrateSOTIfunct(oarr_t* f_eval, darr_t* weights, otinum_t* res,
                                   dhelpl_t dhl);


  # From oti/fem/basis_functions.h

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


  # From oti/fem/element/real/base.h

  uint8_t elem_is_started(   elem_t* elem );
  uint8_t elem_is_allocated( elem_t* elem );
  void elem_clear_flag_start(elem_t* elem );
  void elem_raise_flag_start(elem_t* elem );
  void elem_clear_flag_alloc(elem_t* elem );
  void elem_raise_flag_alloc(elem_t* elem );
  int64_t elem_end(elem_t* elem);
  int64_t elem_free( elem_t* elem );
  elem_t  elem_init();
  int64_t elem_start(elem_t* elem, uint64_t nbasis, int64_t geomBase, int64_t  kind,   uint8_t  ndim);
  int64_t elem_allocate(elem_t* elem, uint64_t intorder );


  # From oti/fem/element/soti/base.h

  uint8_t elemso_is_started(   elemso_t* elemso );
  uint8_t elemso_is_allocated( elemso_t* elemso );
  void elemso_clear_flag_start(elemso_t* elemso );
  void elemso_raise_flag_start(elemso_t* elemso );
  void elemso_clear_flag_alloc(elemso_t* elemso );
  void elemso_raise_flag_alloc(elemso_t* elemso );
  int64_t elemso_end(elemso_t* elemso);
  int64_t elemso_free( elemso_t* elemso );
  elemso_t  elemso_init();
  int64_t elemso_start( elemso_t* elemso, uint64_t nbasis, int64_t geomBase,
                        int64_t kind, uint8_t ndim, dhelpl_t dhl);
  int64_t elemso_allocate(elemso_t* elemso, uint64_t intorder, bases_t bases, ord_t order, dhelpl_t dhl);


  # From oti/fem/gauss/scalar.h



  # From oti/fem/gauss/array.h



  # From oti/fem/gauss/array/feoarr.h



  # From oti/fem/gauss/array/fedarr.h



  # From oti/fem/gauss/array/oarr/utils.h



  # From oti/fem/gauss/array/oarr/algebra.h

  void feoarr_sub_FF_to(feoarr_t* arr1, feoarr_t* arr2, feoarr_t* res, dhelpl_t dhl);
  void feoarr_sum_FF_to(feoarr_t* arr1, feoarr_t* arr2, feoarr_t* res, dhelpl_t dhl);
  void feoarr_neg_to(feoarr_t* arr, feoarr_t* res, dhelpl_t dhl);
  void feoarr_mul_oF_to( otinum_t* num, feoarr_t* arr, feoarr_t* res, dhelpl_t dhl);
  void feoarr_mul_rF_to(coeff_t num, feoarr_t* arr, feoarr_t* res, dhelpl_t dhl);
  void feoarr_matmul_to(feoarr_t* lhs, feoarr_t* rhs, feoarr_t* res, dhelpl_t dhl);
  void feoarr_det_to(feoarr_t* arr, feoarr_t* res, dhelpl_t dhl);
  void feoarr_invert_to(feoarr_t* arr, feoarr_t* res, dhelpl_t dhl);


  # From oti/fem/gauss/array/oarr/base.h

  void feoarr_copy_to(feoarr_t* src, feoarr_t* dst, dhelpl_t dhl);
  feoarr_t feoarr_copy(feoarr_t* src, dhelpl_t dhl);
  void feoarr_get_item_ij_to(feoarr_t* arr, uint64_t i, uint64_t j, feoarr_t* res,dhelpl_t dhl);
  void feoarr_get_item_k_to(feoarr_t* arr, uint64_t k, oarr_t* res,dhelpl_t dhl);
  void feoarr_get_item_ijk_to(feoarr_t* arr, uint64_t i, uint64_t j, uint64_t k, otinum_t* res,dhelpl_t dhl);
  void feoarr_set_item_ij(feoarr_t* arr, uint64_t i, uint64_t j, feoarr_t* res, dhelpl_t dhl);
  void feoarr_set_item_k( oarr_t* arr , uint64_t k, feoarr_t* res, dhelpl_t dhl);
  void feoarr_set_item_ijk(otinum_t* num, uint64_t i, uint64_t j, uint64_t k, feoarr_t* res, dhelpl_t dhl);
  feoarr_t feoarr_zeros( uint64_t nrows, uint64_t ncols, uint64_t offsetx, uint64_t offsety,
                         uint64_t nIntPts, bases_t nbases, ord_t order, dhelpl_t dhl);
  void feoarr_free(feoarr_t* arr);
  feoarr_t feoarr_init();
  feoarr_t feoarr_createEmpty( uint64_t nrows, uint64_t ncols, uint64_t offsetx, uint64_t offsety,
                               uint64_t nIntPts, bases_t nbases, ord_t order, dhelpl_t dhl);


  # From oti/fem/gauss/array/darr/utils.h



  # From oti/fem/gauss/array/darr/algebra.h



  # From oti/fem/gauss/array/darr/base.h



  # From oti/fem/gauss/scalar/feotinum.h



  # From oti/fem/gauss/scalar/fereal.h



  # From oti/fem/gauss/scalar/real/utils.h



  # From oti/fem/gauss/scalar/real/algebra.h



  # From oti/fem/gauss/scalar/real/base.h



  # From oti/fem/gauss/scalar/otinum/utils.h



  # From oti/fem/gauss/scalar/otinum/algebra.h



  # From oti/fem/gauss/scalar/otinum/base.h



  # From oti/fem/integration_points/base.h

  int64_t fem_integrationPoints(uint64_t order, int64_t elementType,
                                  darr_t* coords, darr_t* weights);
  uint64_t fem_addLineIntegrationPoints(uint8_t numberOfPermutations, uint64_t startPoint,
                                             double a,  double w,
                                             darr_t* coords, darr_t* weights);
  uint64_t fem_addTriangleIntegrationPoints(uint8_t numberOfPermutations, uint64_t startPoint,
                                             double a, double b, double c, double w,
                                             darr_t* coords, darr_t* weights);
  uint64_t fem_addTetrahedraIntegrationPoints(uint8_t numberOfPermutations, uint64_t startPoint,
                                             double a, double b, double c,  double d, double w,
                                             darr_t* coords, darr_t* weights);
  int64_t fem_intPts_soti( uint64_t order, int64_t elementType,
                           fesoti_t*  xi,   fesoti_t*   eta,   fesoti_t* zeta,
                           fesoti_t* weights, dhelpl_t dhl);
  uint64_t fem_addLineIntPts_soti(uint8_t nperm, uint64_t start, double a,  double w,
                                  fesoti_t* xi, fesoti_t* eta, fesoti_t* zeta,
                                  fesoti_t* weights, dhelpl_t dhl);
  uint64_t fem_addTriangleIntPts_soti(uint8_t nperm, uint64_t start,
                                      double a, double b, double c, double w,
                                      fesoti_t* xi, fesoti_t* eta, fesoti_t* zeta,
                                      fesoti_t* weights, dhelpl_t dhl);
  uint64_t fem_addTetrahedraIntPts_soti(uint8_t nperm, uint64_t start,
                                        double a, double b, double c, double d, double w,
                                        fesoti_t* xi, fesoti_t* eta, fesoti_t* zeta,
                                        fesoti_t* weights, dhelpl_t dhl);



#-----------------------------------------------------------------------------------------------------

