#ifndef OTI_FEM_ENUMS_H
#define OTI_FEM_ENUMS_H

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
  opDxy         =   13,   ///< dxy(a)
  opDyy         =   14,   ///< dyy(a)
  opDxz         =   15,   ///< dxz(a)
  opDyz         =   16,   ///< dyz(a)
  opDzz         =   17,   ///< dzz(a)
  opDef         =   18,   ///< Define something (probably basis function arrays)
  opOn          =   19,   ///< Essential boundary definition integral.
  opNeg         =   20,   ///< -a
  opDxi         =   21,   ///< dxi      (a)
  opDeta        =   22,   ///< deta     (a)
  opDzeta       =   23,   ///< dzeta    (a)
  opDxixi       =   24,   ///< dxixi    (a)
  opDxieta      =   25,   ///< dxieta   (a)
  opDetaeta     =   26,   ///< detaeta  (a)
  opDxizeta     =   27,   ///< dxizeta  (a)
  opDetazeta    =   28,   ///< detazeta (a)
  opDzetazeta   =   29,   ///< dzetazeta(a)


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
  basisNy       =  103,   ///<  dy( N )
  basisNz       =  104,   ///<  dz( N )
  basisNxx      =  105,   ///< dxx( N )
  basisNxy      =  106,   ///< dxy( N )
  basisNyy      =  107,   ///< dyy( N )
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
  feConstant    =  301,    ///< varConst
  feVariable    =  302,    ///< varVaria

  // Element geometric types 
  elNode        =  400,    ///< Point.
  elLine        =  401,    ///< Line.
  elTriangle    =  402,    ///< Triangle.
  elQuadrangle  =  403,    ///< Quad.
  elTetrahedra  =  404,    ///< Tetra (4 triangle faces).
  elHexahedra   =  405,    ///< Brick.

  // Element kind : Iso-parametric or Affine
  elkindIso     =  501,    ///< Isoparametric element. 
  elkindAff     =  502,    ///< Affine element.

  // Derivative types.
  derN          =  601,   ///<      N
  derNa         =  602,   ///<  da( N )
  derNb         =  603,   ///<  db( N )
  derNc         =  604,   ///<  dc( N )
  derNaa        =  605,   ///< daa( N )
  derNab        =  606,   ///< dab( N )
  derNbb        =  607,   ///< dbb( N )
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


#endif