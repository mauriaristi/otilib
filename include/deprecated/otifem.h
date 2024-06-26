#ifndef OTIFEM_H
#define OTIFEM_H
// ----------------------------------------------------------------------------------------------------
// ---------------------------------     EXTERNAL LIBRARIES     ---------------------------------------
// ----------------------------------------------------------------------------------------------------

#include "oti/otinum_spr_array.h"

// ----------------------------------------------------------------------------------------------------
// --------------------------------    END EXTERNAL LIBRARIES     -------------------------------------
// ----------------------------------------------------------------------------------------------------

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
    uint8_t       order; ///< oti order
} femoarr_t;


typedef struct elemprops_s{
    uint64_t          nbasis; ///< Number of basis - Number of degrees of freedom - Number of nodes.
    uint64_t           order; ///< Maximum order of 
    int64_t         geomBase; ///< Geometric element type - elLine, elTriangle, etc ...
    int64_t             kind; ///< Kind of element: Affine - IsoParametric
    uint8_t             ndim; ///< Number of dimensions of the element. (1 -> 1D, 2 -> 2D, 3 -> 3D)
    uint64_t         nIntPts; ///< Number of integration Points
    uint8_t             nder; ///< Number of total derivatives in the problem.
    uint8_t           isInit; ///< Initialization flag. 0: Not initialized, 1: Initialized.
    uint8_t         otiorder; ///< Order of the soti numbers inside.
    uint8_t     nDimAnalysis; ///< Number of dimensions of the analysis.
    darray_t     p_intPoints; ///< (nIntPts x ndim) Array with the integration points coordinates.
    darray_t    p_intWeights; ///< (nIntPts x 1   ) Array with the integration weights.
    darray_t*    p_evalBasis; ///< (nder) List of (nbasis x nIntPts) arrays with the evaluated basis
    femoarr_t              J; ///< (nDimAn x nDimEl) Holder for Jacobian               
    femoarr_t           Jinv; ///< (nDimEl x nDimAn) Holder for inverse of Jacobian      
    femoarr_t           Jdet; ///< (1 x 1)           Holder for Determinant of Jacobian. 
    femoarr_t*       p_basis; ///< (nder) List (1 x nbasis) basis of the function in spat. coords.
    femoarr_t   p_detWeights; ///< ( 1 x 1 ) Array with the integration weights.
    int64_t (*f_basis)(int64_t,int64_t,darray_t*,void*,darray_t*); ///<  Interpolation function.

} elemProps_t;

// ----------------------------------------------------------------------------------------------------
// -------------------------------------    END STRUCTURES      ---------------------------------------
// ----------------------------------------------------------------------------------------------------





// ----------------------------------------------------------------------------------------------------
// -----------------------------------------      ENUMS        ----------------------------------------
// ----------------------------------------------------------------------------------------------------


// Enumerators to assign a code to FEM constants
enum operEnum {  
  // Define operations identifiers.
  opAdd         =   1 ,   ///< a +  b
  opSub         =   2 ,   ///< a -  b
  opMul         =   3 ,   ///< a *  b
  opTruediv     =   4 ,   ///< a /  b
  opPowr        =   5 ,   ///< a ** b
  opInt1d       =   6 ,   ///< int1d(a)
  opInt2d       =   7 ,   ///< int2d(a)
  opInt3d       =   8 ,   ///< int3d(a)
  opDx          =   9 ,   ///< dx(a)
  opDy          =   10,   ///< dy(a)
  opDz          =   11,   ///< dz(a)
  opDxx         =   12,   ///< dxx(a)
  opDyy         =   13,   ///< dyy(a)
  opDzz         =   14,   ///< dzz(a)
  opDxy         =   15,   ///< dxy(a)
  opDxz         =   16,   ///< dxz(a)
  opDyz         =   17,   ///< dyz(a)
  opDef         =   18,   ///< Define something (probably basis function arrays)
  opOn          =   19,   ///< Essential boundary definition integral.
  opNeg         =   20,   ///< -a


  subOpDefBasis =   50,   ///< 
  subOpDefKnown =   51,   ///< 
  subOpInt      =   52,   ///< 
  subOpNeg      =   53,   ///< 
  subOpMulRes   =   54,   ///< 
  subOpMulKnown =   55,   ///< 
  subOpOn       =   56,   ///< 
  subOpIntBound =   57,   ///< 
  
  // Basis type for this case.
  basisN        =  101,   ///<      N
  basisNx       =  102,   ///<  dx( N )
  basisNxx      =  103,   ///< dxx( N )
  basisNy       =  104,   ///<  dy( N )
  basisNxy      =  105,   ///< dxy( N )
  basisNyy      =  106,   ///< dyy( N )
  basisNz       =  107,   ///<  dz( N )
  basisNxz      =  108,   ///< dxz( N )
  basisNyz      =  109,   ///< dyz( N )
  basisNzz      =  110,   ///< dzz( N )
  
  // Kind of data
  kindOtiArr    =  200,    ///<  Variable OTI array.
  kindOtiNum    =  201,    ///<  Constant OTI number. 
  kindReal      =  202,    ///<  Constant Real number.
  kindScalar    =  203,    ///<  .
  kindFunc      =  204,    ///<  Function.


  // Determine the type of FE variable, if Constant or Variable.
  constant      =  301,    ///< varConst
  variable      =  302,    ///< varVaria

  // Element geometric types 
  elNode        =  400,    ///< 
  elLine        =  401,    ///< 
  elTriangle    =  402,    ///< 
  elQuadrangle  =  403,    ///< 
  elTetrahedra  =  404,    ///< 
  elHexahedra   =  405,    ///< 

  // Element kind : Iso-parametric or Affine
  elkindIso     =  501,    ///< Isoparametric element. 
  elkindAff     =  502,    ///< Affine element.

  // Derivative types.
  derN          =  601,   ///<      N
  derNa         =  602,   ///<  da( N )
  derNaa        =  603,   ///< daa( N )
  derNb         =  604,   ///<  db( N )
  derNab        =  605,   ///< dab( N )
  derNbb        =  606,   ///< dbb( N )
  derNc         =  607,   ///<  dc( N )
  derNac        =  608,   ///< dac( N )
  derNbc        =  609,   ///< dbc( N )
  derNcc        =  610,   ///< dcc( N )

  // Nature of Finite Element Function
  feNatTest     =  701,   ///< Test function nature.
  feNatUndef    =  702,   ///< Undefined function nature.
  feNatDef      =  703,   ///< Defined function nature (already has data).
  feNatDefConst =  704,   ///< Defined constant function nature (that does not vary inside the domain).
  feNatOperRes  =  705,   ///< Defined as the result between a test and a undefined function.
  feNatPostIntK =  706,   ///< integral type operation for K matrix.
  feNatPostIntF =  707,   ///< integral type operation for F vector.
  feNatBoundary =  708    ///< Boundary definition. (essential)
};


// ----------------------------------------------------------------------------------------------------
// ----------------------------------------    END ENUMS      -----------------------------------------
// ----------------------------------------------------------------------------------------------------





// ----------------------------------------------------------------------------------------------------
// ------------------------------------     DECLARATIONS     ------------------------------------------
// ----------------------------------------------------------------------------------------------------


/**************************************************************************************************//**
@brief 

@param[in]
******************************************************************************************************/ 
void femoarr_gaussIntegrateOverElement(femoarr_t* p_arr1, elemProps_t* elem, sotiarray_t* p_arrRes, 
    dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief 

@param[in]
******************************************************************************************************/ 
void femoarr_sub(femoarr_t* p_arr1, femoarr_t* p_arr2, femoarr_t* p_arrRes, 
    dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief 

@param[in]
******************************************************************************************************/ 
void femoarr_sum(femoarr_t* p_arr1, femoarr_t* p_arr2, femoarr_t* p_arrRes, 
    dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief 

@param[in]
******************************************************************************************************/ 
void femoarr_mul_oti(femoarr_t* p_arr1, otinum_t* num2, femoarr_t* p_arrRes, 
    dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief 

@param[in]
******************************************************************************************************/ 
void femoarr_mul_R(femoarr_t* p_arr1, double num2, femoarr_t* p_arrRes);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief 

@param[in]
******************************************************************************************************/ 
void femoarr_matmul(femoarr_t* p_arr1, femoarr_t* p_arr2, femoarr_t* p_arrRes, 
    dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief 

@param[in]
******************************************************************************************************/ 
void femoarr_neg(femoarr_t* p_arr1, femoarr_t* p_arrRes);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief 

@param[in]
******************************************************************************************************/ 
void femoarr_det(femoarr_t* p_arr1, femoarr_t* p_arrRes, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief 

@param[in]
******************************************************************************************************/ 
void femoarr_invert(femoarr_t* p_arr1, femoarr_t* p_arrRes, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief 

@param[in]
******************************************************************************************************/ 
void femoarr_getItem_ij(femoarr_t* p_arr1, uint64_t i, uint64_t j,femoarr_t* p_arrRes);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief 

@param[in]
******************************************************************************************************/ 
void femoarr_getItem_k(femoarr_t* p_arr1, uint64_t k, 
        sotiarray_t* p_arrRes);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief 

@param[in]
******************************************************************************************************/ 
void femoarr_fromOther(femoarr_t* p_arr1, femoarr_t* p_res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief 

@param[in]
******************************************************************************************************/ 
void femoarr_getItem_ijk(femoarr_t* p_arr1, uint64_t i, uint64_t j, uint64_t k, 
        otinum_t* p_res);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief 

@param[in]
******************************************************************************************************/ 
void femoarr_setItem_ij(femoarr_t* p_arr1, uint64_t i, uint64_t j, femoarr_t* p_arrRes);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief 

@param[in]
******************************************************************************************************/ 
void femoarr_setItem_k( sotiarray_t* p_arr1 , uint64_t k, femoarr_t* p_arrRes);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief 

@param[in]
******************************************************************************************************/ 
void femoarr_setItem_ijk(otinum_t* p_num, uint64_t i, uint64_t j, uint64_t k, 
        femoarr_t* p_arrRes);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Allocate a femarray object and set all elements to zero.

@param[inout] p_array: Array.
@param[in] nrows: Number of rows.
@param[in] ncols: Number of columns.
@param[in] order: Truncation order.
******************************************************************************************************/ 
void femoarr_zeros(femoarr_t* p_array, uint64_t nrows, uint64_t ncols, 
                    uint64_t offsetx, uint64_t offsety, uint64_t nIntPts, uint8_t order);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Free all memory associated with the array.

@param[inout] p_array: Array.
******************************************************************************************************/ 
void femoarr_free(femoarr_t* p_array);
// ----------------------------------------------------------------------------------------------------

/**************************************************************************************************//**
@brief Allocate a femarray object. 

@param[inout] p_array: Array.
@param[in] nrows: Number of rows.
@param[in] ncols: Number of columns.
@param[in] order: Truncation order.
******************************************************************************************************/ 
void femoarr_createEmpty(femoarr_t* p_array, uint64_t nrows, uint64_t ncols, 
                    uint64_t offsetx, uint64_t offsety, uint64_t nIntPts, uint8_t order);
// ----------------------------------------------------------------------------------------------------











int64_t fem_defFunctFrom_otiFunc(sotiarray_t* p_arr1, uint64_t derIndx, elemProps_t* elem, femoarr_t* p_arrRes,
    dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

int64_t fem_defFunctFrom_oti(otinum_t* num, uint64_t derIndx, elemProps_t* elem, femoarr_t* p_arrRes,
    dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

int64_t fem_defFunctFrom_R(double num, uint64_t derIndx, elemProps_t* elem, femoarr_t* p_arrRes,
    dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

int64_t fem_defineSpatial( elemProps_t* elem, uint16_t derFlags, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

int64_t fem_computeJacobian( elemProps_t* elem, sotiarray_t* xcoords, sotiarray_t* ycoords,
                               sotiarray_t* zcoords, dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

int64_t fem_unInitElement(elemProps_t* elem);
// ----------------------------------------------------------------------------------------------------

int64_t fem_initElement(uint64_t order, uint8_t otiorder,uint8_t nDimAnalysis, elemProps_t* elem);
// ----------------------------------------------------------------------------------------------------

int64_t fem_integrateSOTIfunct(sotiarray_t* f_eval, darray_t* weights, otinum_t* res,
                                 dhelpl_t dhl);
// ----------------------------------------------------------------------------------------------------

int64_t fem_integrationPoints(uint64_t order, int64_t elementType, 
                                darray_t* coords, darray_t* weights);
// ----------------------------------------------------------------------------------------------------

uint64_t fem_addLineIntegrationPoints(uint8_t numberOfPermutations, uint64_t startPoint, 
                                           double a,  double w,
                                           darray_t* coords, darray_t* weights);
// ----------------------------------------------------------------------------------------------------

uint64_t fem_addTriangleIntegrationPoints(uint8_t numberOfPermutations, uint64_t startPoint, 
                                           double a, double b, double c, double w,
                                           darray_t* coords, darray_t* weights);
// ----------------------------------------------------------------------------------------------------

int64_t fem_basisFunctions_N_QuadSerendP2_2Diso(int64_t basisId, int64_t basisDer, darray_t* coords,   
                                              void* other_data, darray_t* evalBasis);
// ----------------------------------------------------------------------------------------------------

int64_t fem_basisFunctions_N_QuadP1_2Diso(int64_t basisId, int64_t basisDer, darray_t* coords,   
                                              void* other_data, darray_t* evalBasis);
// ----------------------------------------------------------------------------------------------------

int64_t fem_basisFunctions_N_TriangP2_2Diso(int64_t basisId, int64_t basisDer, darray_t* coords,   
                                              void* other_data, darray_t* evalBasis);
// ----------------------------------------------------------------------------------------------------

int64_t fem_basisFunctions_N_TriangP1_2Diso(int64_t basisId, int64_t basisDer, darray_t* coords,   
                                              void* other_data, darray_t* evalBasis);
// ----------------------------------------------------------------------------------------------------

int64_t fem_basisFunctions_N_TriangP0_2Diso(int64_t basisId, int64_t basisDer, darray_t* coords,   
                                              void* other_data, darray_t* evalBasis);
// ----------------------------------------------------------------------------------------------------

int64_t fem_basisFunctions_N_LineP2_1Diso(int64_t basisId, int64_t basisDer, darray_t* coords,   
                                              void* other_data, darray_t* evalBasis);
// ----------------------------------------------------------------------------------------------------

int64_t fem_basisFunctions_N_LineP1_1Diso(int64_t basisId, int64_t basisDer, darray_t* coords,   
                                              void* other_data, darray_t* evalBasis);
// ----------------------------------------------------------------------------------------------------

int64_t fem_basisFunctions_N_PntP0_0Diso(int64_t basisId, int64_t basisDer, darray_t* coords,   
                                              void* other_data, darray_t* evalBasis);
// ----------------------------------------------------------------------------------------------------

// ----------------------------------------------------------------------------------------------------
// ----------------------------------     END DECLARATIONS     ----------------------------------------
// ----------------------------------------------------------------------------------------------------



#endif