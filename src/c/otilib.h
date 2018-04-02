// c_otilib.c
#ifndef OTICORE_H
#define OTICORE_H


// ----------------------------------------------------------------------------------------------------
// ---------------------------------------      DEFINES         ---------------------------------------
// ----------------------------------------------------------------------------------------------------

#define MAX(a,b) ((a) > (b) ? a : b)
#define MIN(a,b) ((a) < (b) ? a : b)

// ----------------------------------------------------------------------------------------------------
// ----------------------------------      END DEFINES         ----------------------------------------
// ----------------------------------------------------------------------------------------------------


// ----------------------------------------------------------------------------------------------------
// --------------------------------------      STRUCTURES        --------------------------------------
// ----------------------------------------------------------------------------------------------------

typedef struct {
    uint16_t*        p_dirA;  // Array with all basis      Shape: (    Ndir,   order)
    uint8_t*         p_expA;  // Array with all exponents. Shape: (    Ndir,   order)
    uint16_t*        p_part;  // Array with all partitions Shape: (   Npart,   order)
    uint64_t*     p_multRes;  // Array with the multiplication results.
    uint64_t*     p_multInd;  // Array with the multiplication indices.
    uint64_t*    p_countOTI;  // Array with the number of elements for each number of variables possible.
    uint16_t*       p_udirA;  // User direction array.     Shape: (      nn,   order)
    uint8_t*        p_uexpA;  // User exponent  array.     Shape: (      nn,   order)
    uint16_t*       p_rdirA;  // Result direction array.   Shape: (      nn,   order)
    uint8_t*        p_rexpA;  // Result exponent  array.   Shape: (      nn,   order)
    uint16_t*       p_mdirA;  // Temporal direction array. Shape: (      nn,   order) -> nn: number of 
    uint8_t*        p_mexpA;  // Temporal exponent array.  Shape: (      nn,   order)        temp els
    uint16_t*      p_mapder;  // Temporal mapping array.   Shape: (      nn, 2*order)   
    uint8_t*       p_multpl;  // Array to hold multiples.  Shape: ( 2^order,   order)
    double*          p_fder;  // Preallocated array for general function evaluation. size: order+1
    double*         p_coefs;  // Preallocated array for general multiplication coefs. Shape: (Ndir,1)
    uint64_t*        p_indx;  // Preallocated array for general multiplication indx.  Shape: (Ndir,1)
    uint64_t           Ndir;  // Number of directions in the helper.
    uint64_t          Npart;  // Number of partitions in the helper.
    uint64_t          Nmult;  // Size of the multiplication vectors.
    uint16_t         Nbasis;  // Maximum number of basis in the helper.
    uint8_t              nn;  // Number of user arrays  
    uint8_t           order;  // Order of all directions in this set. 

} directionHelper;

typedef struct {
    double*         p_coefs;  // Array with all exponents. Shape: ( Ndir,  order)
    uint64_t           Ndir;  // Number of directions in the number.
    uint8_t           order;  // Maximum order of the number.
} otinum_t;

typedef struct {
    double*         p_coefs;  // Array with all Coefficients. Shape: ( 1, Ndir)
    uint64_t*        p_indx;  // Directions associated to each coefficient.
    uint64_t           size;  // Number of directions in the number.
    uint8_t           order;  // Maximum order of the number.
} sotinum_t;

// typedef struct {
//     double               e0;  // "Element with order zero"
//     double*         p_coefs;  // Array with all Coefficients. Shape: ( 1, Ndir)
//     uint64_t*        p_indx;  // Directions associated to each coefficient.
//     uint64_t          csize;  // Number of directions in the number.
//     uint8_t           order;  // Maximum order of the number.
// } sotinume_t;  // Sparse OTI number, order-based 


typedef struct{
    uint64_t*     p_data; // Data Array.
    uint64_t*     p_cols; // Array of corresponding column index of the data array.
    uint64_t*     p_rows; // Array of corresponding row index of the data array.
    uint64_t       sizex; // Number of rows.
    uint64_t       sizey; // Number of cols.
    uint64_t     nonzero; // Number of non zero elements in the matrix.
} coomat_ui64_t;

typedef struct{
    uint64_t*     p_data; // Data array
    uint64_t*  p_indices; // Array of column indices of each data entry.
    uint64_t*   p_indptr; // Array pointing the range of data values per matrix row.
    uint64_t       sizex; // Number of rows.
    uint64_t       nrows; // Number of cols.
    uint64_t     nonzero; // Number of non zero elements.
} csrmat_ui64_t;

typedef struct{
    sotinum_t*    p_data; // Data array
    uint64_t       nrows; // Number of rows.
    uint64_t       ncols; // Number of cols.
    uint64_t        size; // Total size of the array.
    uint8_t        order;
} sotiarray_t;

typedef struct{
    double*       p_data; // Data array
    uint64_t       nrows; // Number of rows.
    uint64_t       ncols; // Number of cols.
    uint64_t        size; // Total size of the array.
} darray_t;

typedef struct{
    sotiarray_t* p_data; // Data array
    uint64_t      nrows; // Number of rows.
    uint64_t      ncols; // Number of cols.
    uint64_t    nIntPts; // Number of integration points.
    uint64_t    offsetx; // Offset x in the element formulation
    uint64_t    offsety; // Offset y in the element formulation
    uint64_t       size; // size of the array
    uint8_t       order; // oti order
} femarray_t;


typedef struct elemprops_s{
    uint64_t          nbasis; // Number of basis - Number of degrees of freedom - Number of nodes.
    uint64_t           order; // Maximum order of 
    int64_t         geomBase; // Geometric element type - elLine, elTriangle, etc ...
    int64_t             kind; // Kind of element: Affine - IsoParametric
    uint8_t             ndim; // Number of dimensions of the element. (1 -> 1D, 2 -> 2D, 3 -> 3D)
    uint64_t         nIntPts; // Number of integration Points
    uint8_t             nder; // Number of total derivatives in the problem.
    uint8_t           isInit; // Initialization flag. 0: Not initialized, 1: Initialized.
    uint8_t         otiorder; // Order of the soti numbers inside.
    uint8_t     nDimAnalysis; // Number of dimensions of the analysis.
    darray_t     p_intPoints; // (nIntPts x ndim) Array with the integration points coordinates.
    darray_t    p_intWeights; // (nIntPts x 1   ) Array with the integration weights.
    darray_t*    p_evalBasis; // (nder) List of (nbasis x nIntPts) arrays with the evaluated basis
    femarray_t             J; // (nDimAn x nDimEl) Holder for Jacobian               
    femarray_t          Jinv; // (nDimEl x nDimAn) Holder for inverse of Jacobian      
    femarray_t          Jdet; // (1 x 1)           Holder for Determinant of Jacobian. 
    femarray_t*      p_basis; // (nder) List (1 x nbasis) basis of the function in spat. coords.
    femarray_t  p_detWeights; // ( 1 x 1 ) Array with the integration weights.
    int64_t (*f_basis)(int64_t,int64_t,darray_t*,void*,darray_t*); //  Interpolation function.

} elemProps_t;

// ----------------------------------------------------------------------------------------------------
// -------------------------------------    END STRUCTURES      ---------------------------------------
// ----------------------------------------------------------------------------------------------------





// ----------------------------------------------------------------------------------------------------
// -----------------------------------------      ENUMS        ----------------------------------------
// ----------------------------------------------------------------------------------------------------


// Enumerators to assign a code to FEM constants
enum c_oti_errors {  
  // Define operations identifiers.
  OTI_success      =     0,   // Success
  OTI_OutOfMemory  =    -1,   // Out of memory.
  OTI_BadIndx      =    -2,   // indexing error.
  OTI_NonPreComp   =    -3,   // No precomputed data is available.

  OTI_FEM_InvalidBaseId = -100,         // invalid base Id. It pops up when for example 
                                        // for P0 elements that only have 1 basis function
                                        // you ask for basis 2 (that does not exist).

  OTI_FEM_InvalidElementType = -101,    // Invalid basic element type 
                                        // (elLine, elTria, elQuad, elTetr, elHexa).

  OTI_FEM_NotImplemented     = -102,    // Operation not yet implemented.

  OTI_undetErr     = -20000             // Undetermined error.
  
};


// Enumerators to assign a code to FEM constants
enum operEnum {  
  // Define operations identifiers.
  opAdd         =   1 ,   // a +  b
  opSub         =   2 ,   // a -  b
  opMul         =   3 ,   // a *  b
  opTruediv     =   4 ,   // a /  b
  opPowr        =   5 ,   // a ** b
  opInt1d       =   6 ,   // int1d(a)
  opInt2d       =   7 ,   // int2d(a)
  opInt3d       =   8 ,   // int3d(a)
  opDx          =   9 ,   // dx(a)
  opDy          =   10,   // dy(a)
  opDz          =   11,   // dz(a)
  opDxx         =   12,   // dxx(a)
  opDyy         =   13,   // dyy(a)
  opDzz         =   14,   // dzz(a)
  opDxy         =   15,   // dxy(a)
  opDxz         =   16,   // dxz(a)
  opDyz         =   17,   // dyz(a)
  opDef         =   18,   // Define something (probably basis function arrays)
  opOn          =   19,   // Essential boundary definition integral.
  opNeg         =   20,   // -a


  subOpDefBasis =   50,
  subOpDefKnown =   51,
  subOpInt      =   52,
  subOpNeg      =   53,
  subOpMulRes   =   54,
  subOpMulKnown =   55,
  subOpOn       =   56,
  subOpIntBound =   57,
  
  // Basis type for this case.
  basisN        =  101,   //      N
  basisNx       =  102,   //  dx( N )
  basisNxx      =  103,   // dxx( N )
  basisNy       =  104,   //  dy( N )
  basisNxy      =  105,   // dxy( N )
  basisNyy      =  106,   // dyy( N )
  basisNz       =  107,   //  dz( N )
  basisNxz      =  108,   // dxz( N )
  basisNyz      =  109,   // dyz( N )
  basisNzz      =  110,   // dzz( N )
  
  // Kind of data
  kindOtiArr    =  200,    //  Variable OTI array.
  kindOtiNum    =  201,    //  Constant OTI number. 
  kindReal      =  202,    //  Constant Real number.
  kindScalar    =  203,    //  .
  kindFunc      =  204,    //  Function.


  // Determine the type of FE variable, if Constant or Variable.
  constant      =  301,    // varConst
  variable      =  302,    // varVaria

  // Element geometric types 
  elNode        =  400,
  elLine        =  401,
  elTriangle    =  402,
  elQuadrangle  =  403,
  elTetrahedra  =  404,
  elHexahedra   =  405,

  // Element kind : Iso-parametric or Affine
  elkindIso     =  501,   // Isoparametric element. 
  elkindAff     =  502,    // Affine element.

  // Derivative types.
  derN          =  601,   //      N
  derNa         =  602,   //  da( N )
  derNaa        =  603,   // daa( N )
  derNb         =  604,   //  db( N )
  derNab        =  605,   // dab( N )
  derNbb        =  606,   // dbb( N )
  derNc         =  607,   //  dc( N )
  derNac        =  608,   // dac( N )
  derNbc        =  609,   // dbc( N )
  derNcc        =  610,   // dcc( N )

  // Nature of Finite Element Function
  feNatTest     =  701,   // Test function nature.
  feNatUndef    =  702,   // Undefined function nature.
  feNatDef      =  703,   // Defined function nature (already has data).
  feNatDefConst =  704,   // Defined constant function nature (that does not vary inside the domain).
  feNatOperRes  =  705,   // Defined as the result between a test and a undefined function.
  feNatPostIntK =  706,   // integral type operation for K matrix.
  feNatPostIntF =  707,   // integral type operation for F vector.
  feNatBoundary =  708    // Boundary definition. (essential)
};


// ----------------------------------------------------------------------------------------------------
// ----------------------------------------    END ENUMS      -----------------------------------------
// ----------------------------------------------------------------------------------------------------





// ----------------------------------------------------------------------------------------------------
// ------------------------------------     DECLARATIONS     ------------------------------------------
// ----------------------------------------------------------------------------------------------------
// to add to c_otilib.pxd









// added to c_otilib.pxd






void c_femarray_gaussIntegrateOverElement(femarray_t* p_arr1, elemProps_t* elem, sotiarray_t* p_arrRes, 
    directionHelper* p_dH);

void c_femarray_sub(femarray_t* p_arr1, femarray_t* p_arr2, femarray_t* p_arrRes, 
    directionHelper* p_dH);

void c_femarray_sum(femarray_t* p_arr1, femarray_t* p_arr2, femarray_t* p_arrRes, 
    directionHelper* p_dH);

void c_femarray_mul_oti(femarray_t* p_arr1, sotinum_t* num2, femarray_t* p_arrRes, 
    directionHelper* p_dH);

void c_femarray_mul_R(femarray_t* p_arr1, double num2, femarray_t* p_arrRes);

void c_femarray_matmul(femarray_t* p_arr1, femarray_t* p_arr2, femarray_t* p_arrRes, 
    directionHelper* p_dH);

void c_femarray_neg(femarray_t* p_arr1, femarray_t* p_arrRes);

void c_femarray_det(femarray_t* p_arr1, femarray_t* p_arrRes, directionHelper* p_dH);

void c_femarray_invert(femarray_t* p_arr1, femarray_t* p_arrRes, directionHelper* p_dH);

void c_femarray_getItem_ij(femarray_t* p_arr1, uint64_t i, uint64_t j,femarray_t* p_arrRes);

void c_femarray_getItem_k(femarray_t* p_arr1, uint64_t k, 
        sotiarray_t* p_arrRes);

void c_femarray_fromOther(femarray_t* p_arr1, femarray_t* p_res);

void c_femarray_getItem_ijk(femarray_t* p_arr1, uint64_t i, uint64_t j, uint64_t k, 
        sotinum_t* p_res);

void c_femarray_setItem_ij(femarray_t* p_arr1, uint64_t i, uint64_t j, femarray_t* p_arrRes);

void c_femarray_setItem_k( sotiarray_t* p_arr1 , uint64_t k, femarray_t* p_arrRes);

void c_femarray_setItem_ijk(sotinum_t* p_num, uint64_t i, uint64_t j, uint64_t k, 
        femarray_t* p_arrRes);

void c_femarray_zeros(femarray_t* p_array, uint64_t nrows, uint64_t ncols, 
                    uint64_t offsetx, uint64_t offsety, uint64_t nIntPts, uint8_t order);

void c_femarray_free(femarray_t* p_array);

void c_femarray_createEmpty(femarray_t* p_array, uint64_t nrows, uint64_t ncols, 
                    uint64_t offsetx, uint64_t offsety, uint64_t nIntPts, uint8_t order);











int64_t c_fem_defFunctFrom_otiFunc(sotiarray_t* p_arr1, uint64_t derIndx, elemProps_t* elem, femarray_t* p_arrRes,
    directionHelper* p_dH);

int64_t c_fem_defFunctFrom_oti(sotinum_t* num, uint64_t derIndx, elemProps_t* elem, femarray_t* p_arrRes,
    directionHelper* p_dH);

int64_t c_fem_defFunctFrom_R(double num, uint64_t derIndx, elemProps_t* elem, femarray_t* p_arrRes,
    directionHelper* p_dH);

int64_t c_fem_defineSpatial( elemProps_t* elem, uint16_t derFlags, directionHelper* p_dH);

int64_t c_fem_computeJacobian( elemProps_t* elem, sotiarray_t* xcoords, sotiarray_t* ycoords,
                               sotiarray_t* zcoords, directionHelper* p_dH);

int64_t c_fem_unInitElement(elemProps_t* elem);

int64_t c_fem_initElement(uint64_t order, uint8_t otiorder,uint8_t nDimAnalysis, elemProps_t* elem);

int64_t c_fem_integrateSOTIfunct(sotiarray_t* f_eval, darray_t* weights, sotinum_t* res,
                                 directionHelper* p_dH);

int64_t c_fem_integrationPoints(uint64_t order, int64_t elementType, 
                                darray_t* coords, darray_t* weights);

uint64_t c_fem_addLineIntegrationPoints(uint8_t numberOfPermutations, uint64_t startPoint, 
                                           double a,  double w,
                                           darray_t* coords, darray_t* weights);

uint64_t c_fem_addTriangleIntegrationPoints(uint8_t numberOfPermutations, uint64_t startPoint, 
                                           double a, double b, double c, double w,
                                           darray_t* coords, darray_t* weights);

int64_t c_fem_basisFunctions_N_QuadSerendP2_2Diso(int64_t basisId, int64_t basisDer, darray_t* coords,   
                                              void* other_data, darray_t* evalBasis);

int64_t c_fem_basisFunctions_N_QuadP1_2Diso(int64_t basisId, int64_t basisDer, darray_t* coords,   
                                              void* other_data, darray_t* evalBasis);

int64_t c_fem_basisFunctions_N_TriangP2_2Diso(int64_t basisId, int64_t basisDer, darray_t* coords,   
                                              void* other_data, darray_t* evalBasis);

int64_t c_fem_basisFunctions_N_TriangP1_2Diso(int64_t basisId, int64_t basisDer, darray_t* coords,   
                                              void* other_data, darray_t* evalBasis);

int64_t c_fem_basisFunctions_N_TriangP0_2Diso(int64_t basisId, int64_t basisDer, darray_t* coords,   
                                              void* other_data, darray_t* evalBasis);

int64_t c_fem_basisFunctions_N_LineP2_1Diso(int64_t basisId, int64_t basisDer, darray_t* coords,   
                                              void* other_data, darray_t* evalBasis);

int64_t c_fem_basisFunctions_N_LineP1_1Diso(int64_t basisId, int64_t basisDer, darray_t* coords,   
                                              void* other_data, darray_t* evalBasis);

int64_t c_fem_basisFunctions_N_PntP0_0Diso(int64_t basisId, int64_t basisDer, darray_t* coords,   
                                              void* other_data, darray_t* evalBasis);







inline void c_darray_getItem(darray_t* p_array, uint64_t i, uint64_t j, double* num);

inline void c_darray_setItem( double num, uint64_t i, uint64_t j, darray_t* p_array);

int64_t c_darray_zeros(darray_t* p_array, uint64_t nrows, uint64_t ncols);

void c_darray_free(darray_t* p_array);

int64_t c_darray_createEmpty(darray_t* p_array, uint64_t nrows, uint64_t ncols);



void c_sotiarray_setItemR_indx( double num, uint64_t i, sotiarray_t* p_array);

void c_sotiarray_setItemOTI_indx( sotinum_t* num, uint64_t i, sotiarray_t* p_array);

void c_sotiarray_oti_div(sotiarray_t* p_arr1, sotinum_t* num2, sotiarray_t* p_arrRes, 
                        directionHelper* p_dH);

void c_sotiarray_matdiv_otioti(sotiarray_t* p_arr1, sotiarray_t* p_arr2, sotiarray_t* p_arrRes, 
                        directionHelper* p_dH);

void c_sotiarray_div_R(sotiarray_t* p_arr1, double num2, sotiarray_t* p_arrRes);

void c_sotiarray_R_div(sotiarray_t* p_arr1, double num2, sotiarray_t* p_arrRes, 
                        directionHelper* p_dH);

void c_sotiarray_div_oti(sotiarray_t* p_arr1, sotinum_t* num2, sotiarray_t* p_arrRes, 
                        directionHelper* p_dH);

void c_sotiarray_invert(sotiarray_t* p_arr1, sotiarray_t* p_arrRes, directionHelper* p_dH);

void c_sotiarray_det(sotiarray_t* p_arr1, sotinum_t* p_res, directionHelper* p_dH);

void c_sotiarray_transpose(sotiarray_t* p_arr1, sotiarray_t* p_arrRes);

void c_sotiarray_mul_sotiarr(sotiarray_t* p_arr1, sotiarray_t* p_arr2, sotiarray_t* p_arrRes, 
                        directionHelper* p_dH);

void c_sotiarray_neg(sotiarray_t* p_arr1, sotiarray_t* p_arrRes);

void c_sotiarray_matsub_Roti(sotiarray_t* p_arr1, darray_t* p_arr2, sotiarray_t* p_arrRes);

void c_sotiarray_matsub_otiR(sotiarray_t* p_arr1, darray_t* p_arr2, sotiarray_t* p_arrRes);

void c_sotiarray_matsub_otioti(sotiarray_t* p_arr1, sotiarray_t* p_arr2, sotiarray_t* p_arrRes, 
                        directionHelper* p_dH);

void c_sotiarray_oti_sub(sotiarray_t* p_arr1, sotinum_t* num2, sotiarray_t* p_arrRes, 
                        directionHelper* p_dH);

void c_sotiarray_R_sub(sotiarray_t* p_arr1, double num2, sotiarray_t* p_arrRes);

void c_sotiarray_sub_oti(sotiarray_t* p_arr1, sotinum_t* num2, sotiarray_t* p_arrRes, 
                        directionHelper* p_dH);

void c_sotiarray_sub_R(sotiarray_t* p_arr1, double num2, sotiarray_t* p_arrRes);

void c_sotiarray_mul_oti(sotiarray_t* p_arr1, sotinum_t* num2, sotiarray_t* p_arrRes, 
                        directionHelper* p_dH);

void c_sotiarray_mul_R(sotiarray_t* p_arr1, double num2, sotiarray_t* p_arrRes);

void c_sotiarray_sum_oti(sotiarray_t* p_arr1, sotinum_t* num2, sotiarray_t* p_arrRes, 
                        directionHelper* p_dH);

void c_sotiarray_sum_R(sotiarray_t* p_arr1, double num2, sotiarray_t* p_arrRes); 

void c_sotiarray_matmul_otiR(sotiarray_t* p_arr1, darray_t* p_arr2, sotiarray_t* p_arrRes, 
                        directionHelper* p_dH);

void c_sotiarray_matmul_Roti(darray_t* p_arr1, sotiarray_t* p_arr2, sotiarray_t* p_arrRes, 
                        directionHelper* p_dH);

void c_sotiarray_matmul_otioti(sotiarray_t* p_arr1, sotiarray_t* p_arr2, sotiarray_t* p_arrRes, 
                        directionHelper* p_dH);

void c_sotiarray_matsum_otiR(sotiarray_t* p_arr1, darray_t* p_arr2, sotiarray_t* p_arrRes);

void c_sotiarray_matsum_otioti(sotiarray_t* p_arr1, sotiarray_t* p_arr2, sotiarray_t* p_arrRes, 
                        directionHelper* p_dH);

void c_sotiarray_getItem(sotiarray_t* p_array, uint64_t i, uint64_t j, sotinum_t* num);

void c_sotiarray_setItemR( double num, uint64_t i, uint64_t j,sotiarray_t* p_array);

void c_sotiarray_setAllItems( sotinum_t* num, sotiarray_t* p_array);

void c_sotiarray_setItemOTI( sotinum_t* num, uint64_t i, uint64_t j,sotiarray_t* p_array);

void c_sotiarray_zeros(sotiarray_t* p_array, uint64_t shapex, uint64_t shapey, uint8_t order);

void c_sotiarray_free(sotiarray_t* p_array);

void c_sotiarray_createEmpty(sotiarray_t* p_array, uint64_t shapex, uint64_t shapey, uint8_t order);



void c_soti_fdiv(double numx, sotinum_t* numy, sotinum_t* res, directionHelper* p_dH);

void c_soti_divf(sotinum_t* numx, double numy, sotinum_t* res);

void c_soti_div(sotinum_t* numx, sotinum_t* numy, sotinum_t* res, directionHelper* p_dH);

double c_soti_getReal(sotinum_t* num);

void c_soti_atan2(sotinum_t* numx, sotinum_t* numy, directionHelper* p_dH, sotinum_t* res);

void c_soti_logb(sotinum_t* num, int base, directionHelper* p_dH, sotinum_t* res);

void c_soti_log10(sotinum_t* num, directionHelper* p_dH, sotinum_t* res);

void c_soti_atanh(sotinum_t* num, directionHelper* p_dH, sotinum_t* res);

void c_soti_asinh(sotinum_t* num, directionHelper* p_dH, sotinum_t* res);

void c_soti_acosh(sotinum_t* num, directionHelper* p_dH, sotinum_t* res);

void c_soti_tanh(sotinum_t* num, directionHelper* p_dH, sotinum_t* res);

void c_soti_sqrt(sotinum_t* num, directionHelper* p_dH, sotinum_t* res);

void c_soti_cosh(sotinum_t* num, directionHelper* p_dH, sotinum_t* res);

void c_soti_sinh(sotinum_t* num, directionHelper* p_dH, sotinum_t* res);

void c_soti_asin(sotinum_t* num, directionHelper* p_dH, sotinum_t* res);

void c_soti_acos(sotinum_t* num, directionHelper* p_dH, sotinum_t* res);

void c_soti_atan(sotinum_t* num, directionHelper* p_dH, sotinum_t* res);

void c_soti_tan(sotinum_t* num, directionHelper* p_dH, sotinum_t* res);

void c_soti_cos(sotinum_t* num, directionHelper* p_dH, sotinum_t* res);

void c_soti_sin(sotinum_t* num, directionHelper* p_dH, sotinum_t* res);

void c_soti_log(sotinum_t* num, directionHelper* p_dH, sotinum_t* res);

void c_soti_exp(sotinum_t* num, directionHelper* p_dH, sotinum_t* res);
 
void c_soti_derivFunc(double* fder, sotinum_t* g, directionHelper* p_dH, sotinum_t* feval);

void c_soti_smulf(sotinum_t* num1, double num2);

void c_soti_copy(sotinum_t* res, sotinum_t* num1);

void c_soti_pow(sotinum_t* num, double exponent, directionHelper* p_dH,sotinum_t* res);

void c_soti_ipowfast(sotinum_t* num1, uint8_t exp, sotinum_t* res, directionHelper* p_dH); 

void c_soti_ipow(sotinum_t* num1, uint8_t exp, sotinum_t* res, directionHelper* p_dH);

void c_soti_neg( sotinum_t* num1, sotinum_t* res);

void c_soti_fsub(sotinum_t* num1, double num2, sotinum_t* res);

void c_soti_subf(sotinum_t* num1, double num2, sotinum_t* res);

void c_soti_sub(sotinum_t* num1, sotinum_t* num2, sotinum_t* res, directionHelper* p_dH);

void c_soti_sumf(sotinum_t* num1, double num2, sotinum_t* res);

void c_soti_mulf(sotinum_t* num1, double num2, sotinum_t* res);

void c_soti_mul(sotinum_t* num1, sotinum_t* num2, sotinum_t* res, directionHelper* p_dH);

void c_soti_sum(sotinum_t* num1, sotinum_t* num2, sotinum_t* res, directionHelper* p_dH);

void c_soti_free(sotinum_t* numHolder);

void c_soti_createFromReal(double num, sotinum_t* numHolder, uint8_t order);

void c_soti_createEmpty(sotinum_t* numHolder, uint64_t ncoefs, uint8_t order);



coomat_ui64_t c_oti_matform( uint64_t nvar, uint8_t order, directionHelper* p_dH);

void c_oti_atan2(otinum_t* numx, otinum_t* numy, directionHelper* p_dH, otinum_t* res);

void c_oti_logb(otinum_t* num, int base, directionHelper* p_dH, otinum_t* res);

void c_oti_log10(otinum_t* num, directionHelper* p_dH, otinum_t* res);

void c_oti_atanh(otinum_t* num, directionHelper* p_dH, otinum_t* res);

void c_oti_asinh(otinum_t* num, directionHelper* p_dH, otinum_t* res);

void c_oti_acosh(otinum_t* num, directionHelper* p_dH, otinum_t* res);

void c_oti_tanh(otinum_t* num, directionHelper* p_dH, otinum_t* res);

void c_oti_sqrt(otinum_t* num, directionHelper* p_dH, otinum_t* res);

void c_oti_cosh(otinum_t* num, directionHelper* p_dH, otinum_t* res);

void c_oti_sinh(otinum_t* num, directionHelper* p_dH, otinum_t* res);

void c_oti_asin(otinum_t* num, directionHelper* p_dH, otinum_t* res);

void c_oti_acos(otinum_t* num, directionHelper* p_dH, otinum_t* res);

void c_oti_atan(otinum_t* num, directionHelper* p_dH, otinum_t* res);

void c_oti_tan(otinum_t* num, directionHelper* p_dH, otinum_t* res);

void c_oti_cos(otinum_t* num, directionHelper* p_dH, otinum_t* res);

void c_oti_sin(otinum_t* num, directionHelper* p_dH, otinum_t* res);

void c_oti_log(otinum_t* num, directionHelper* p_dH, otinum_t* res);

void c_oti_exp(otinum_t* num, directionHelper* p_dH, otinum_t* res);

void c_oti_pow(otinum_t* num, double exponent, directionHelper* p_dH,otinum_t* res);

double c_oti_FaaDiBruno(uint64_t indx, double* fder, otinum_t* g, directionHelper* p_dH);

void c_oti_derivFunc(double* fder, otinum_t* g, directionHelper* p_dH, otinum_t* feval);

void c_oti_collapseDirA(uint16_t* array, uint8_t order, uint16_t* dirA, uint8_t* expA);

void c_oti_expandDirA(uint16_t* p_dirA,uint8_t* p_expA, uint8_t order, uint16_t* p_expandArr);

double* c_oti_num2mat(otinum_t* num, uint64_t size, directionHelper* p_dH);

void c_oti_mulf(otinum_t* num1, double num2, otinum_t* res);

void c_oti_mul(otinum_t* num1, otinum_t* num2, otinum_t* res, directionHelper* p_dH);

void c_oti_sub(otinum_t* num1, otinum_t* num2, otinum_t* res);

void c_oti_neg(otinum_t* num1);

void c_oti_changeOrderToNew(otinum_t* num, uint8_t neword, directionHelper* p_dH , otinum_t* res);

void c_oti_sum(otinum_t* num1, otinum_t* num2, otinum_t* res);

void c_oti_free(otinum_t* numHolder);

void c_oti_createEmpty(otinum_t* numHolder,   uint64_t ndir, uint8_t order);

inline void c_oti_copy(otinum_t* numDest, otinum_t* numSrc);

void c_oti_changeOrder(otinum_t* num, uint8_t neword, directionHelper* p_dH );




uint64_t c_helper_multMultiIndxFast(uint64_t* indx, uint8_t nindx, uint8_t order, 
                                directionHelper* p_dH, uint8_t* error);

void c_helper_ordDirExpA(uint16_t* p_dirA, uint8_t* multiple, uint8_t order, 
                        uint16_t* p_ndirA, uint8_t* p_nexpA);

void c_helper_getMultpl(uint8_t* p_expA, uint8_t order, directionHelper* p_dH, uint64_t* Nmultpl);

uint64_t c_helper_multIndxFast(uint64_t indx1, uint64_t indx2, uint8_t order, directionHelper* p_dH, 
                               uint8_t* error);

void c_helper_load(  uint8_t maxorder, char* strLocation, directionHelper** p_dH);

void c_helper_free(directionHelper* p_dH , uint8_t maxorder );

uint64_t c_helper_findIndex(uint16_t* p_dirA,  uint8_t* p_expA, uint8_t order, directionHelper* p_dH);

uint64_t c_helper_multIndx(uint64_t indx1, uint64_t indx2, uint8_t order, directionHelper* p_dH, 
                            uint8_t* error);

uint16_t* c_helper_getDirA(uint64_t indx, uint8_t order, directionHelper* p_dH);

uint8_t*  c_helper_getExpA(uint64_t indx, uint8_t order, directionHelper* p_dH);

inline uint8_t* c_helper_getUExpA( uint8_t order, uint8_t n, directionHelper* p_dH);

inline uint16_t* c_helper_getUDirA( uint8_t order, uint8_t n, directionHelper* p_dH);

uint64_t c_helper_findMaxDir(uint64_t index, uint8_t order, directionHelper* p_dH);

uint64_t c_helper_getNels( uint64_t m, uint8_t order, directionHelper* p_dH);

inline uint64_t c_helper_getNParts( uint8_t order, directionHelper* p_dH);

inline uint16_t c_helper_getSet( uint8_t order,uint64_t i,uint64_t j, directionHelper* p_dH);

void c_helper_insertIndx(uint64_t* p_indxArray,uint64_t indx,uint64_t *size,
    double * p_coefArray, double coef);





uint64_t c_ndir(uint64_t nvar,uint8_t order);

uint16_t c_maxUI16(uint64_t a,uint64_t b);

void c_printArrayDBL(double* ptr_,uint64_t n);

void c_printArrayUI64(uint64_t* ptr_,uint64_t n);

void c_minUI64(uint64_t a,uint64_t b,uint64_t* minnum,uint64_t* maxnum );

uint64_t c_multDirections_dH(uint64_t indx1m1, uint64_t indx2m1, directionHelper* p_dH, uint8_t* error );

uint64_t c_binarySearch_dH( uint16_t*  ptr_dirA, uint8_t*  ptr_expA, directionHelper* p_dH);

void c_loadDirA( char* strLocation,uint8_t order, uint16_t ndir, uint16_t** dirA, uint64_t* Ndir);

void c_loadExpA( char* strLocation,uint8_t order, uint16_t ndir, uint8_t** expA, uint64_t* Ndir);

void c_loadCount( char* strLocation,uint8_t order, uint16_t ndir, uint64_t** count);

void c_loadParts( char* strLocation,uint8_t order, uint16_t ndir, uint16_t** p_parts, uint64_t* Nparts);

void c_loadDirHelper(  char* strLocation, uint8_t order, uint16_t ndir, uint8_t nhelps, directionHelper* dirHelp);

void c_freeDirHelper(  directionHelper* dirHelp);

uint64_t c_fastpow(uint64_t b,uint16_t exp);

uint64_t c_fastfact(uint8_t exp);

uint64_t c_convToIndex(uint16_t* ptr_dirA,uint8_t* ptr_expA, uint8_t order);

void     c_printArrayUI16(uint16_t* ptr_,uint8_t size);

void     c_printArrayUI8(uint8_t* ptr_,uint8_t size);

void     c_mapDirArray( uint16_t*  ptr_dirA1, uint16_t*  ptr_dirA2,   uint8_t  order,
                    uint16_t* ptr_mdirA1, uint16_t* ptr_mdirA2, uint16_t* ptr_mapder);

void     c_mapDirArrayNoMapder( uint16_t*  ptr_dirA1, uint16_t*  ptr_dirA2,   uint8_t  order,
                    uint16_t* ptr_mdirA1, uint16_t* ptr_mdirA2);

uint64_t c_binarySearch(  uint16_t* ptr_dirArray, uint8_t* ptr_expArray,
                          uint16_t* ptr_dirA,     uint8_t* ptr_expA,     uint8_t order,
                          uint64_t  N, uint16_t* ptr_mdirA1, uint16_t* ptr_mdirA2);

void     c_convToDirExp(uint64_t index, uint8_t order, uint16_t* ptr_dirA, uint8_t* ptr_expA);

void     c_reMapDirArray( uint16_t*  ptr_mdirA1, uint16_t* ptr_mapder, uint8_t order,
                      uint16_t* ptr_dirA1);

uint8_t  c_sumUI8(uint8_t* ptr_,uint8_t n);

uint64_t c_multDirections(uint16_t* ptr_dirArray, uint8_t* ptr_expArray,
                        uint16_t* ptr_dirA1,  uint8_t* ptr_expA1,
                        uint16_t* ptr_dirA2,  uint8_t* ptr_expA2, 
                        uint16_t* ptr_mdirA1, uint8_t* ptr_mexpA1,
                        uint16_t* ptr_mdirA2, uint16_t* ptr_mdirA3, 
                        uint16_t* ptr_mapder, 
                        uint8_t order, uint64_t N, uint8_t* error );

uint64_t c_binarySearchUI64(  uint64_t* ptr_indxArray, uint64_t indx,uint64_t  N);

void     c_mapPartition(uint16_t part,  uint16_t*  ptr_dir,  uint8_t  order, 
                    uint16_t*  ptr_map);

void     c_orderDirExpArray(uint16_t* dirA,    uint8_t*    multExpA ,uint8_t pos,
             uint16_t* newDirA, uint8_t* newExpA, uint8_t order);

void* c_malloc_ptr(uint64_t numberOfElements, uint64_t sizeOfElement);

void c_free_ptr(void** ptrAddress);


// ----------------------------------------------------------------------------------------------------
// ----------------------------------     END DECLARATIONS     ----------------------------------------
// ----------------------------------------------------------------------------------------------------

#endif