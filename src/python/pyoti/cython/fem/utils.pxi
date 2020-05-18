






# ----------------------------------------------------------------------------------------------------
# ---------------------------------------    CONSTANTS    --------------------------------------------
# ----------------------------------------------------------------------------------------------------


opNames = [ "None  ",
            "   +  ",
            "   -  ",
            "   *  ",
            "   /  ",
            "  **  ",
            "int1d ",
            "int2d ",
            "int3d ",
            "  dx  ",
            "  dy  ",
            "  dz  ",
            "  dxx ",
            "  dyy ",
            "  dzz ",
            "  dxy ",
            "  dxz ",
            "  dyz ",
            "  def "]

basisNames = ["N  ",
              "Nx ",
              "Ny ",
              "Nz ",
              "Nxx",
              "Nyy",
              "Nzz",
              "Nxy",
              "Nxz",
              "Nyz"]

kindNames = ["OTIARR",
             "OTINUM",
             "REAL  "]

elTypeNames = ["point",
               "line",
               "triangle",
               "quadrangle",
               "tetrahedra",
               "hexahedra"]

# ----------------------------------------------------------------------------------------------------










#*****************************************************************************************************
cdef object enum2string(int64_t enumId):
  """
  PURPOSE:    Returns a string with the name of the corresponding enum value given.

  """
  #***************************************************************************************************

  if   enumId == opAdd        :
    return "opAdd        "
  elif enumId == opSub        :
    return "opSub        "
  elif enumId == opMul        :
    return "opMul        "
  elif enumId == opTruediv    :
    return "opTruediv    "
  elif enumId == opPowr       :
    return "opPowr       "
  elif enumId == opInt1d      :
    return "opInt1d      "
  elif enumId == opInt2d      :
    return "opInt2d      "
  elif enumId == opInt3d      :
    return "opInt3d      "
  elif enumId == opDx         :
    return "opDx         "
  elif enumId == opDxx        :
    return "opDxx        "
  elif enumId == opDy         :
    return "opDy         "
  elif enumId == opDxy        :
    return "opDxy        "
  elif enumId == opDyy        :
    return "opDyy        "
  elif enumId == opDz         :
    return "opDz         "
  elif enumId == opDxz        :
    return "opDxz        "
  elif enumId == opDyz        :
    return "opDyz        "
  elif enumId == opDzz        :
    return "opDzz        "
  elif enumId == opDef        :
    return "opDef        "
  elif enumId == opOn         :
    return "opOn         "
  elif enumId == opNeg        :
    return "opNeg        "
  elif enumId == subOpDefBasis:
    return "subOpDefBasis"
  elif enumId == subOpDefKnown:
    return "subOpDefKnown"
  elif enumId == subOpInt     :
    return "subOpInt     "
  elif enumId == subOpNeg     :
    return "subOpNeg     "
  elif enumId == subOpMulRes  :
    return "subOpMulRes  "
  elif enumId == subOpMulKnown:
    return "subOpMulKnown"
  elif enumId == subOpOn      :
    return "subOpOn      "
  elif enumId == basisN       :
    return "basisN       "
  elif enumId == basisNx      :
    return "basisNx      "
  elif enumId == basisNxx     :
    return "basisNxx     "
  elif enumId == basisNy      :
    return "basisNy      "
  elif enumId == basisNxy     :
    return "basisNxy     "
  elif enumId == basisNyy     :
    return "basisNyy     "
  elif enumId == basisNz      :
    return "basisNz      "
  elif enumId == basisNxz     :
    return "basisNxz     "
  elif enumId == basisNyz     :
    return "basisNyz     "
  elif enumId == basisNzz     :
    return "basisNzz     "
  elif enumId == kindOtiArr   :
    return "kindOtiArr   "
  elif enumId == kindOtiNum   :
    return "kindOtiNum   "
  elif enumId == kindReal     :
    return "kindReal     "
  elif enumId == kindScalar   :
    return "kindScalar   "
  elif enumId == kindFunc     :
    return "kindFunc     "
  elif enumId == feConstant     :
    return "feConstant   "
  elif enumId == feVariable     :
    return "feVariable   "
  elif enumId == elNode       :
    return "elNode       "
  elif enumId == elLine       :
    return "elLine       "
  elif enumId == elTriangle   :
    return "elTriangle   "
  elif enumId == elQuadrangle :
    return "elQuadrangle "
  elif enumId == elTetrahedra :
    return "elTetrahedra "
  elif enumId == elHexahedra  :
    return "elHexahedra  "
  elif enumId == elkindIso    :
    return "elkindIso    "
  elif enumId == elkindAff    :
    return "elkindAff    "
  elif enumId == derN         :
    return "derN         "
  elif enumId == derNa        :
    return "derNa        "
  elif enumId == derNaa       :
    return "derNaa       "
  elif enumId == derNb        :
    return "derNb        "
  elif enumId == derNab       :
    return "derNab       "
  elif enumId == derNbb       :
    return "derNbb       "
  elif enumId == derNc        :
    return "derNc        "
  elif enumId == derNac       :
    return "derNac       "
  elif enumId == derNbc       :
    return "derNbc       "
  elif enumId == derNcc       :
    return "derNcc       "
  elif enumId == feNatTest    :
    return "feNatTest    "
  elif enumId == feNatUndef   :
    return "feNatUndef   "
  elif enumId == feNatDef     :
    return "feNatDef     "
  elif enumId == feNatDefConst:
    return "feNatDefConst"
  elif enumId == feNatOperRes :
    return "feNatOperRes "
  elif enumId == feNatPostIntK:
    return "feNatPostIntK"
  elif enumId == feNatPostIntF:
    return "feNatPostIntF"
  elif enumId == feNatBoundary:
    return "feNatBoundary"

#-----------------------------------------------------------------------------------------------------






# #*****************************************************************************************************
# def fem_integrationPointsWeights(uint64_t order, int64_t elementType):
#   """
#   PURPOSE:     Test to check if the integration points and weights are good.
#   """
#   cdef darray_t coords, weights
#   cdef np.ndarray np_coords, np_weights
#   c_fem_integrationPoints(order, elementType, &coords, &weights)
#   np_coords = darray_2_numpyArray(&coords )
#   np_weights = darray_2_numpyArray(&weights )


#   # Free arrays
#   c_darray_free(&coords)
#   c_darray_free(&weights)

#   return (np_coords, np_weights)
# #-----------------------------


# Create element objects.
# Point element
point1 = elBase.createNewElement(1,            # Number of basis 
                                 0,            # Characteristic order of the polynomials
                                 elNode,       # Geometric type
                                 elkindIso,    # Kind of element 
                                 0,            # Number of dimensions
                                 point1_iso,   # Basis functions.
                                 [])   

# Line elements
# 1 node line
line1 = elBase.createNewElement( 1,            # Number of basis 
                                 0,            # Characteristic order of the polynomials
                                 elLine,       # Geometric type
                                 elkindIso,    # Kind of element 
                                 1,            # Number of dimensions
                                 line1_iso,    # Basis functions.
                                 [point1,])   
# 2 node line
line2 = elBase.createNewElement( 2,            # Number of basis 
                                 1,            # Characteristic order of the polynomials
                                 elLine,       # Geometric type
                                 elkindIso,    # Kind of element 
                                 1,            # Number of dimensions
                                 line2_iso,    # Basis functions.
                                 [point1,])   
# 3 node line
line3 = elBase.createNewElement( 3,            # Number of basis 
                                 2,            # Characteristic order of the polynomials
                                 elLine,       # Geometric type
                                 elkindIso,    # Kind of element 
                                 1,            # Number of dimensions
                                 line2_iso,    # Basis functions.
                                 [point1,])   

# 2D elements:
# Triangle elements.
# 1 node Triangle
tri1 = elBase.createNewElement(  1,            # Number of basis 
                                 0,            # Characteristic order of the polynomials
                                 elTriangle,   # Geometric type
                                 elkindIso,    # Kind of element 
                                 2,            # Number of dimensions
                                 tri1_iso,     # Basis functions.
                                 [point1, line1])   
# 3 node triangle
tri3 = elBase.createNewElement(  3,            # Number of basis 
                                 1,            # Characteristic order of the polynomials
                                 elTriangle,   # Geometric type
                                 elkindIso,    # Kind of element 
                                 2,            # Number of dimensions
                                 tri3_iso,     # Basis functions.
                                 [point1, line2])   
# 4 node triangle (bubble)
tri4 = elBase.createNewElement(  4,            # Number of basis 
                                 2,            # Characteristic order of the polynomials
                                 elTriangle,   # Geometric type
                                 elkindIso,    # Kind of element 
                                 2,            # Number of dimensions
                                 tri4_iso,     # Basis functions.
                                 [point1,line2])   
# 6 node triangle
tri6 = elBase.createNewElement(  6,            # Number of basis 
                                 2,            # Characteristic order of the polynomials
                                 elTriangle,   # Geometric type
                                 elkindIso,    # Kind of element 
                                 2,            # Number of dimensions
                                 tri6_iso,     # Basis functions.
                                 [point1, line3])   

# Quadrangle elements.
# 1 node Quad
quad1 = elBase.createNewElement( 1,            # Number of basis 
                                 0,            # Characteristic order of the polynomials
                                 elQuadrangle, # Geometric type
                                 elkindIso,    # Kind of element 
                                 2,            # Number of dimensions
                                 quad1_iso,    # Basis functions.
                                 [point1, line1])   
# 4 node Quad
quad4 = elBase.createNewElement( 4,            # Number of basis 
                                 1,            # Characteristic order of the polynomials
                                 elQuadrangle, # Geometric type
                                 elkindIso,    # Kind of element 
                                 2,            # Number of dimensions
                                 quad4_iso,    # Basis functions.
                                 [point1, line2])   
# 8 node Quad (serendipity)
quad8 = elBase.createNewElement( 8,            # Number of basis 
                                 2,            # Characteristic order of the polynomials
                                 elQuadrangle, # Geometric type
                                 elkindIso,    # Kind of element 
                                 2,            # Number of dimensions
                                 quad8_iso,    # Basis functions.
                                 [point1, line3])   
# 8 node Quad (serendipity)
quad9 = elBase.createNewElement( 9,            # Number of basis 
                                 2,            # Characteristic order of the polynomials
                                 elQuadrangle, # Geometric type
                                 elkindIso,    # Kind of element 
                                 2,            # Number of dimensions
                                 quad9_iso,    # Basis functions.
                                 [point1, line3])


# Tetrahedra elements.
# 1 node tetrahedra
tet1 = elBase.createNewElement(  1,            # Number of basis 
                                 0,            # Characteristic order of the polynomials
                                 elTetrahedra, # Geometric type
                                 elkindIso,    # Kind of element 
                                 3,            # Number of dimensions
                                 tet1_iso,     # Basis functions.
                                 [point1, line1, tri1])
# 4 node tetrahedra
tet4 = elBase.createNewElement(  4,            # Number of basis 
                                 1,            # Characteristic order of the polynomials
                                 elTetrahedra, # Geometric type
                                 elkindIso,    # Kind of element 
                                 3,            # Number of dimensions
                                 tet4_iso,     # Basis functions.
                                 [point1, line2, tri3])
# # 10 node tetrahedra
# tet10 = elBase.createNewElement( 10,          \ # Number of basis 
#                                  1,           \ # Characteristic order of the polynomials
#                                  elTetrahedra,\ # Geometric type
#                                  elkindIso,   \ # Kind of element 
#                                  3,           \ # Number of dimensions
#                                  tet10_iso,   \ # Basis functions.
#                                  [point1, line3, tri6])


# Hexahedra elements.
# 1 node hexahedra
hex1 = elBase.createNewElement(  1,            # Number of basis 
                                 0,            # Characteristic order of the polynomials
                                 elHexahedra,  # Geometric type
                                 elkindIso,    # Kind of element 
                                 3,            # Number of dimensions
                                 hex1_iso,     # Basis functions.
                                 [point1, line1, quad1])
# 4 node hexahedra
hex8 = elBase.createNewElement(  8,            # Number of basis 
                                 1,            # Characteristic order of the polynomials
                                 elHexahedra,  # Geometric type
                                 elkindIso,    # Kind of element 
                                 3,            # Number of dimensions
                                 hex8_iso,     # Basis functions.
                                 [point1, line2, quad4])
# 10 node hexahedra
hex20 = elBase.createNewElement( 20,           # Number of basis 
                                 2,            # Characteristic order of the polynomials
                                 elHexahedra,  # Geometric type
                                 elkindIso,    # Kind of element 
                                 3,            # Number of dimensions
                                 hex20_iso,    # Basis functions.
                                 [point1, line3, quad8])

elements = {}
elements['point']=[]
elements['point'].append(point1)

elements['line']=[]
elements['line'].append(line1) # Order 0
elements['line'].append(line2) # Order 1
elements['line'].append(line3) # Order 2

elements['triangle']=[]
elements['triangle'].append(tri1) # Order 0
elements['triangle'].append(tri3) # Order 1
elements['triangle'].append(tri6) # Order 2

elements['bubble']=[]
elements['bubble'].append(tri1) # Order 0
elements['bubble'].append(tri3) # Order 1
elements['bubble'].append(tri4) # Order 1.b

elements['quad']=[]
elements['quad'].append(quad1) # Order 0
elements['quad'].append(quad4) # Order 1
elements['quad'].append(quad9) # Order 2

elements['serendipity']=[]
elements['serendipity'].append(quad1) # Order 0
elements['serendipity'].append(quad4) # Order 1
elements['serendipity'].append(quad8) # Order 2

elements['tetra']=[]
elements['tetra'].append(tet1 ) # Order 0
elements['tetra'].append(tet4 ) # Order 1
# elements['tetra'].append(tet10) # Order 2

elements['brick']=[]
elements['brick'].append(hex1 ) # Order 0
elements['brick'].append(hex8 ) # Order 1
elements['brick'].append(hex20) # Order 2

