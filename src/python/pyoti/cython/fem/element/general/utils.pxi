

# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::     POINT ELEMENT    ::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

# ****************************************************************************************************
point1 = elbase.createElement(1,            # Number of basis 
                              0,            # Characteristic order of the polynomials
                              elNode,       # Geometric type
                              elkindIso,    # Kind of element 
                              0,            # Number of dimensions
                              point1_iso,   # Basis functions.
                              [])
# ----------------------------------------------------------------------------------------------------

# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::  END  POINT ELEMENT  ::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::










# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::     LINE ELEMENTS    ::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

# ****************************************************************************************************
# 1 node line
line1 = elbase.createElement( 1,            # Number of basis 
                              0,            # Characteristic order of the polynomials
                              elLine,       # Geometric type
                              elkindIso,    # Kind of element 
                              1,            # Number of dimensions
                              line1_iso,    # Basis functions.
                              [point1,])
# ----------------------------------------------------------------------------------------------------

# ****************************************************************************************************
# 2 node line
line2 = elbase.createElement( 2,            # Number of basis 
                              1,            # Characteristic order of the polynomials
                              elLine,       # Geometric type
                              elkindIso,    # Kind of element 
                              1,            # Number of dimensions
                              line2_iso,    # Basis functions.
                              [point1,])   
# ----------------------------------------------------------------------------------------------------

# ****************************************************************************************************
# 3 node line
line3 = elbase.createElement( 3,            # Number of basis 
                              2,            # Characteristic order of the polynomials
                              elLine,       # Geometric type
                              elkindIso,    # Kind of element 
                              1,            # Number of dimensions
                              line3_iso,    # Basis functions.
                              [point1,])   
# ----------------------------------------------------------------------------------------------------

# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::  END LINE ELEMENTS   ::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::













# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::  TRIANGLE ELEMENTS   ::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

# ****************************************************************************************************
# 1 node Triangle
tri1 = elbase.createElement(  1,            # Number of basis 
                              0,            # Characteristic order of the polynomials
                              elTriangle,   # Geometric type
                              elkindIso,    # Kind of element 
                              2,            # Number of dimensions
                              tri1_iso,     # Basis functions.
                              [point1, line1])   
# ----------------------------------------------------------------------------------------------------

# ****************************************************************************************************
# 3 node triangle
tri3 = elbase.createElement(  3,            # Number of basis 
                              1,            # Characteristic order of the polynomials
                              elTriangle,   # Geometric type
                              elkindIso,    # Kind of element 
                              2,            # Number of dimensions
                              tri3_iso,     # Basis functions.
                              [point1, line2])   
# ----------------------------------------------------------------------------------------------------

# ****************************************************************************************************
# 4 node triangle (bubble)
tri4 = elbase.createElement(  4,            # Number of basis 
                              2,            # Characteristic order of the polynomials
                              elTriangle,   # Geometric type
                              elkindIso,    # Kind of element 
                              2,            # Number of dimensions
                              tri4_iso,     # Basis functions.
                              [point1,line2])   
# ----------------------------------------------------------------------------------------------------

# ****************************************************************************************************
# 6 node triangle
tri6 = elbase.createElement(  6,            # Number of basis 
                              2,            # Characteristic order of the polynomials
                              elTriangle,   # Geometric type
                              elkindIso,    # Kind of element 
                              2,            # Number of dimensions
                              tri6_iso,     # Basis functions.
                              [point1, line3])   
# ----------------------------------------------------------------------------------------------------

# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# :::::::::::::::::::::::::::::::::: END TRIANGLE ELEMENTS :::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::













# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::  QUADRANGLE ELEMENTS   ::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

# ****************************************************************************************************
# 1 node Quad
quad1 = elbase.createElement( 1,            # Number of basis 
                              0,            # Characteristic order of the polynomials
                              elQuadrangle, # Geometric type
                              elkindIso,    # Kind of element 
                              2,            # Number of dimensions
                              quad1_iso,    # Basis functions.
                              [point1, line1])   
# ----------------------------------------------------------------------------------------------------

# *****************************************************************************************************
# 4 node Quad
quad4 = elbase.createElement( 4,            # Number of basis 
                              1,            # Characteristic order of the polynomials
                              elQuadrangle, # Geometric type
                              elkindIso,    # Kind of element 
                              2,            # Number of dimensions
                              quad4_iso,    # Basis functions.
                              [point1, line2])   
# ----------------------------------------------------------------------------------------------------

# ****************************************************************************************************
# 8 node Quad (serendipity)
quad8 = elbase.createElement( 8,            # Number of basis 
                              2,            # Characteristic order of the polynomials
                              elQuadrangle, # Geometric type
                              elkindIso,    # Kind of element 
                              2,            # Number of dimensions
                              quad8_iso,    # Basis functions.
                              [point1, line3])   
# ----------------------------------------------------------------------------------------------------

# ****************************************************************************************************
# 8 node Quad (serendipity)
quad9 = elbase.createElement( 9,            # Number of basis 
                              2,            # Characteristic order of the polynomials
                              elQuadrangle, # Geometric type
                              elkindIso,    # Kind of element 
                              2,            # Number of dimensions
                              quad9_iso,    # Basis functions.
                              [point1, line3])
# ----------------------------------------------------------------------------------------------------

# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::: END QUADRANGLE ELEMENTS ::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::


# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::   TETRAHEDRAL ELEMENTS   ::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

# ****************************************************************************************************
# 1 node tetrahedra
tet1 = elbase.createElement(  1,            # Number of basis 
                              0,            # Characteristic order of the polynomials
                              elTetrahedra, # Geometric type
                              elkindIso,    # Kind of element 
                              3,            # Number of dimensions
                              tet1_iso,     # Basis functions.
                              [point1, line1, tri1])
# ----------------------------------------------------------------------------------------------------

# ****************************************************************************************************
# 4 node tetrahedra
tet4 = elbase.createElement(  4,            # Number of basis 
                              1,            # Characteristic order of the polynomials
                              elTetrahedra, # Geometric type
                              elkindIso,    # Kind of element 
                              3,            # Number of dimensions
                              tet4_iso,     # Basis functions.
                              [point1, line2, tri3])
# ----------------------------------------------------------------------------------------------------

# ****************************************************************************************************
# 10 node tetrahedra
tet10 = elbase.createElement( 10,           # Number of basis 
                              1,            # Characteristic order of the polynomials
                              elTetrahedra, # Geometric type
                              elkindIso,    # Kind of element 
                              3,            # Number of dimensions
                              tet10_iso,    # Basis functions.
                              [point1, line3, tri6])
# ----------------------------------------------------------------------------------------------------

# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# :::::::::::::::::::::::::::::::: END TETRAHEDRAL ELEMENTS ::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::



# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# :::::::::::::::::::::::::::::::::   HEXAHEDRAL ELEMENTS   ::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

# ****************************************************************************************************
# 1 node hexahedra
hex1 = elbase.createElement(  1,            # Number of basis 
                              0,            # Characteristic order of the polynomials
                              elHexahedra,  # Geometric type
                              elkindIso,    # Kind of element 
                              3,            # Number of dimensions
                              hex1_iso,     # Basis functions.
                              [point1, line1, quad1])
# ----------------------------------------------------------------------------------------------------

# ****************************************************************************************************
# 4 node hexahedra
hex8 = elbase.createElement(  8,            # Number of basis 
                              1,            # Characteristic order of the polynomials
                              elHexahedra,  # Geometric type
                              elkindIso,    # Kind of element 
                              3,            # Number of dimensions
                              hex8_iso,     # Basis functions.
                              [point1, line2, quad4])
# ----------------------------------------------------------------------------------------------------

# ****************************************************************************************************
# 10 node hexahedra
hex20 = elbase.createElement( 20,           # Number of basis 
                              2,            # Characteristic order of the polynomials
                              elHexahedra,  # Geometric type
                              elkindIso,    # Kind of element 
                              3,            # Number of dimensions
                              hex20_iso,    # Basis functions.
                              [point1, line3, quad8])
# ----------------------------------------------------------------------------------------------------

# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::: END HEXAHEDRAL ELEMENTS ::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::







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

