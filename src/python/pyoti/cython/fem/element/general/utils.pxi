

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
                              [],
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
vertexIndx = np.array([[ 0, ],] ,dtype=np.uint64) # Define the vertex indices of the line.
line1 = elbase.createElement( 1,            # Number of basis 
                              0,            # Characteristic order of the polynomials
                              elLine,       # Geometric type
                              elkindIso,    # Kind of element 
                              1,            # Number of dimensions
                              line1_iso,    # Basis functions.
                              [point1,],
                              [vertexIndx,])  
# ----------------------------------------------------------------------------------------------------

# ****************************************************************************************************
# 2 node line
vertexIndx = np.array([[ 0 ],     # Define the vertex indices of the line
                       [ 1 ]],dtype=np.uint64)
line2 = elbase.createElement( 2,            # Number of basis 
                              1,            # Characteristic order of the polynomials
                              elLine,       # Geometric type
                              elkindIso,    # Kind of element 
                              1,            # Number of dimensions
                              line2_iso,    # Basis functions.
                              [point1,],
                              [vertexIndx,])     
# ----------------------------------------------------------------------------------------------------

# ****************************************************************************************************
# 3 node line
vertexIndx = np.array([[ 0 ],     # Define the vertex indices of the line
                       [ 1 ]],dtype=np.uint64)
line3 = elbase.createElement( 3,            # Number of basis 
                              2,            # Characteristic order of the polynomials
                              elLine,       # Geometric type
                              elkindIso,    # Kind of element 
                              1,            # Number of dimensions
                              line3_iso,    # Basis functions.
                              [point1,],
                              [vertexIndx,])     
# ----------------------------------------------------------------------------------------------------

# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::  END LINE ELEMENTS   ::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::


# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::     LINE ELEMENTS LOBATTO   :::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

# ****************************************************************************************************
# 1 node line
vertexIndx = np.array([[ 0, ],] ,dtype=np.uint64) # Define the vertex indices of the line.
line1L = elbase.createElement(1,            # Number of basis 
                              0,            # Characteristic order of the polynomials
                              elLineL,      # Geometric type
                              elkindIso,    # Kind of element 
                              1,            # Number of dimensions
                              line1_iso,    # Basis functions.
                              [point1,],
                              [vertexIndx,])  
# ----------------------------------------------------------------------------------------------------

# ****************************************************************************************************
# 2 node line
vertexIndx = np.array([[ 0 ],     # Define the vertex indices of the line
                       [ 1 ]],dtype=np.uint64)
line2L = elbase.createElement(2,            # Number of basis 
                              1,            # Characteristic order of the polynomials
                              elLineL,      # Geometric type
                              elkindIso,    # Kind of element 
                              1,            # Number of dimensions
                              line2_iso,    # Basis functions.
                              [point1,],
                              [vertexIndx,])   
# ----------------------------------------------------------------------------------------------------

# ****************************************************************************************************
# 3 node line
vertexIndx = np.array([[ 0 ],     # Define the vertex indices of the line
                       [ 1 ]],dtype=np.uint64)
line3L = elbase.createElement(3,            # Number of basis 
                              2,            # Characteristic order of the polynomials
                              elLineL,      # Geometric type
                              elkindIso,    # Kind of element 
                              1,            # Number of dimensions
                              line3_iso,    # Basis functions.
                              [point1,],
                              [vertexIndx,])    
# ----------------------------------------------------------------------------------------------------

# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::  END LINE ELEMENTS LOBATTO   ::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::










# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::  TRIANGLE ELEMENTS   ::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

# ****************************************************************************************************
# 1 node Triangle
vertexIndx = np.array([[ 0, ],] ,dtype=np.uint64) # Define the vertex indices of the triangle.
edgeIndx = np.array([[ 0, ],],dtype=np.uint64)    # Define the edge indicesof the triangle.
tri1 = elbase.createElement(  1,            # Number of basis 
                              0,            # Characteristic order of the polynomials
                              elTriangle,   # Geometric type
                              elkindIso,    # Kind of element 
                              2,            # Number of dimensions
                              tri1_iso,     # Basis functions.
                              [point1, line1],
                              [vertexIndx,edgeIndx])   
# ----------------------------------------------------------------------------------------------------

# ****************************************************************************************************
# 3 node triangle
vertexIndx = np.array([[ 0 ],     # Define the vertex indices
                       [ 1 ],     # of the triangle.
                       [ 2 ]],dtype=np.uint64)

edgeIndx = np.array([[ 0, 1 ],     # Define the edge indices
                     [ 1, 2 ],     # of the triangle.
                     [ 2, 0 ]],dtype=np.uint64)

tri3 = elbase.createElement(  3,            # Number of basis 
                              1,            # Characteristic order of the polynomials
                              elTriangle,   # Geometric type
                              elkindIso,    # Kind of element 
                              2,            # Number of dimensions
                              tri3_iso,     # Basis functions.
                              [point1, line2],
                              [vertexIndx,edgeIndx])   
# ----------------------------------------------------------------------------------------------------

# ****************************************************************************************************
# 4 node triangle (bubble)
tri4 = elbase.createElement(  4,            # Number of basis 
                              2,            # Characteristic order of the polynomials
                              elTriangle,   # Geometric type
                              elkindIso,    # Kind of element 
                              2,            # Number of dimensions
                              tri4_iso,     # Basis functions.
                              [point1,line2],
                              [vertexIndx,edgeIndx])   
# ----------------------------------------------------------------------------------------------------

# ****************************************************************************************************
# 6 node triangle
vertexIndx = np.array([[ 0 ],     # Define the vertex indices  of the triangle.
                       [ 1 ],     
                       [ 2 ]],dtype=np.uint64)

edgeIndx = np.array([[ 0, 1, 3 ],     # Define the edge indices  of the triangle.
                     [ 1, 2, 4 ],     
                     [ 2, 0, 5 ]],dtype=np.uint64)

tri6 = elbase.createElement(  6,            # Number of basis 
                              2,            # Characteristic order of the polynomials
                              elTriangle,   # Geometric type
                              elkindIso,    # Kind of element 
                              2,            # Number of dimensions
                              tri6_iso,     # Basis functions.
                              [point1, line3],
                              [vertexIndx,edgeIndx])     
# ----------------------------------------------------------------------------------------------------

# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# :::::::::::::::::::::::::::::::::: END TRIANGLE ELEMENTS :::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::   TETRAHEDRAL ELEMENTS   ::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

# ****************************************************************************************************
# 1 node tetrahedra
vertexIndx = np.array([[ 0, ],] ,dtype=np.uint64) # Define the vertex indices of the tetrahedra.
edgeIndx = np.array([[ 0, ],],dtype=np.uint64)    # Define the edge indices of the tetrahedra.
faceIndx = np.array([[ 0, ],],dtype=np.uint64)    # Define the face indices of the tetrahedra.

tet1 = elbase.createElement(  1,            # Number of basis 
                              0,            # Characteristic order of the polynomials
                              elTetrahedra, # Geometric type
                              elkindIso,    # Kind of element 
                              3,            # Number of dimensions
                              tet1_iso,     # Basis functions.
                              [point1, line1, tri1],
                              [vertexIndx,edgeIndx,faceIndx])
# ----------------------------------------------------------------------------------------------------

# ****************************************************************************************************
# 4 node tetrahedra
vertexIndx = np.array([[ 0 ],     # Define the vertex indices of the tetrahedra.
                       [ 1 ],     
                       [ 2 ],
                       [ 3 ]],dtype=np.uint64)

edgeIndx = np.array([[ 0, 1,],     # Define the edge indices of the tetrahedra.
                     [ 1, 2 ],     
                     [ 2, 0 ],
                     [ 0, 3 ],
                     [ 1, 3 ],
                     [ 2, 3 ]],dtype=np.uint64)

faceIndx = np.array([[ 0, 1, 2],     # Define the face indices of the tetrahedra.
                     [ 0 ,3, 1],     
                     [ 1, 3, 2],
                     [ 0 ,2, 3]],dtype=np.uint64)

tet4 = elbase.createElement(  4,            # Number of basis 
                              1,            # Characteristic order of the polynomials
                              elTetrahedra, # Geometric type
                              elkindIso,    # Kind of element 
                              3,            # Number of dimensions
                              tet4_iso,     # Basis functions.
                              [point1, line2, tri3],
                              [vertexIndx,edgeIndx,faceIndx])
# ----------------------------------------------------------------------------------------------------

# ****************************************************************************************************
# 10 node tetrahedra
vertexIndx = np.array([[ 0 ],             # Define the vertex indices of the tetrahedra.
                       [ 1 ],     
                       [ 2 ],
                       [ 3 ]],dtype=np.uint64)

edgeIndx = np.array([[ 0, 1, 4 ],         # Define the edge indices of the tetrahedra.
                     [ 1, 2, 5 ],     
                     [ 2, 0, 6 ],
                     [ 0, 3, 7 ],
                     [ 1, 3, 8 ],
                     [ 2, 3, 9 ]],dtype=np.uint64)

faceIndx = np.array([[ 0, 1, 2, 4, 5, 6], # Define the face indices of the tetrahedra.
                     [ 0 ,3, 1, 7, 8, 4],     
                     [ 1, 3, 2, 8, 9, 5],
                     [ 0 ,2, 3, 6, 9, 8]],dtype=np.uint64)

tet10 = elbase.createElement( 10,           # Number of basis 
                              1,            # Characteristic order of the polynomials
                              elTetrahedra, # Geometric type
                              elkindIso,    # Kind of element 
                              3,            # Number of dimensions
                              tet10_iso,    # Basis functions.
                              [point1, line3, tri6],
                              [vertexIndx,edgeIndx,faceIndx])
# ----------------------------------------------------------------------------------------------------

# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# :::::::::::::::::::::::::::::::: END TETRAHEDRAL ELEMENTS ::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::













# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::  QUADRANGLE ELEMENTS   ::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

# ****************************************************************************************************
# 1 node Quad
vertexIndx = np.array([[ 0, ],] ,dtype=np.uint64) # Define the vertex indices of the quad.
edgeIndx   = np.array([[ 0, ],],dtype=np.uint64)  # Define the edge indices of the quad.

quad1 = elbase.createElement( 1,            # Number of basis 
                              0,            # Characteristic order of the polynomials
                              elQuadrangle, # Geometric type
                              elkindIso,    # Kind of element 
                              2,            # Number of dimensions
                              quad1_iso,    # Basis functions.
                              [point1, line1],
                              [vertexIndx, edgeIndx])   
# ----------------------------------------------------------------------------------------------------

# ****************************************************************************************************
# 4 node Quad
vertexIndx = np.array([[ 0 ],     # Define the vertex indices of the quad.
                       [ 1 ],    
                       [ 2 ],
                       [ 3 ]],dtype=np.uint64)

edgeIndx = np.array([[ 0, 1 ],     # Define the edge indices of the quad.
                     [ 1, 2 ],
                     [ 2, 3 ],
                     [ 3, 0 ],
                     ],dtype=np.uint64)

quad4 = elbase.createElement( 4,            # Number of basis 
                              1,            # Characteristic order of the polynomials
                              elQuadrangle, # Geometric type
                              elkindIso,    # Kind of element 
                              2,            # Number of dimensions
                              quad4_iso,    # Basis functions.
                              [point1, line2],
                              [vertexIndx, edgeIndx])   
# ----------------------------------------------------------------------------------------------------

# ****************************************************************************************************
# 8 node Quad (serendipity)
vertexIndx = np.array([[ 0 ],     # Define the vertex indices of the quad.
                       [ 1 ],    
                       [ 2 ],
                       [ 3 ]],dtype=np.uint64)

edgeIndx = np.array([[ 0, 1, 4 ],     # Define the edge indices of the quad.
                     [ 1, 2, 5 ],
                     [ 2, 3, 6 ],
                     [ 3, 0, 7 ],
                     ],dtype=np.uint64)

quad8 = elbase.createElement( 8,            # Number of basis 
                              2,            # Characteristic order of the polynomials
                              elQuadrangle, # Geometric type
                              elkindIso,    # Kind of element 
                              2,            # Number of dimensions
                              quad8_iso,    # Basis functions.
                              [point1, line3],
                              [vertexIndx, edgeIndx])    
# ----------------------------------------------------------------------------------------------------

# ****************************************************************************************************
# 9 node Quad (shares quad8 edge and vertex indices)
quad9 = elbase.createElement( 9,            # Number of basis 
                              2,            # Characteristic order of the polynomials
                              elQuadrangle, # Geometric type
                              elkindIso,    # Kind of element 
                              2,            # Number of dimensions
                              quad9_iso,    # Basis functions.
                              [point1, line3],
                              [vertexIndx, edgeIndx]) 
# ----------------------------------------------------------------------------------------------------

# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::: END QUADRANGLE ELEMENTS ::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::



# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::  QUADRANGLE ELEMENTS LOBATTO  :::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

# ****************************************************************************************************
# 1 node Quad
vertexIndx = np.array([[ 0, ],] ,dtype=np.uint64) # Define the vertex indices of the quad.
edgeIndx = np.array([[ 0, ],],dtype=np.uint64)    # Define the edge indices of the quad.
quad1L = elbase.createElement( 1,           # Number of basis 
                              0,            # Characteristic order of the polynomials
                              elQuadrangleL,# Geometric type
                              elkindIso,    # Kind of element 
                              2,            # Number of dimensions
                              quad1_iso,    # Basis functions.
                              [point1, line1],
                              [vertexIndx, edgeIndx])   
# ----------------------------------------------------------------------------------------------------

# ****************************************************************************************************
# 4 node Quad
vertexIndx = np.array([[ 0 ],     # Define the vertex indices of the quad.
                       [ 1 ],    
                       [ 2 ],
                       [ 3 ]],dtype=np.uint64)

edgeIndx = np.array([[ 0, 1 ],     # Define the edge indices of the quad.
                     [ 1, 2 ],
                     [ 2, 3 ],
                     [ 3, 0 ],
                     ],dtype=np.uint64)
quad4L = elbase.createElement( 4,           # Number of basis 
                              1,            # Characteristic order of the polynomials
                              elQuadrangleL,# Geometric type
                              elkindIso,    # Kind of element 
                              2,            # Number of dimensions
                              quad4_iso,    # Basis functions.
                              [point1, line2L],
                              [vertexIndx, edgeIndx])   
# ----------------------------------------------------------------------------------------------------

# ****************************************************************************************************
# 8 node Quad (serendipity)
edgeIndx = np.array([[ 0, 1, 4 ],   # Define the edge indices of the quad.
                     [ 1, 2, 5 ],
                     [ 2, 3, 6 ],
                     [ 3, 0, 7 ],
                     ],dtype=np.uint64)
quad8L = elbase.createElement( 8,           # Number of basis 
                              2,            # Characteristic order of the polynomials
                              elQuadrangleL,# Geometric type
                              elkindIso,    # Kind of element 
                              2,            # Number of dimensions
                              quad8_iso,    # Basis functions.
                              [point1, line3L],
                              [vertexIndx, edgeIndx])   
# ----------------------------------------------------------------------------------------------------

# ****************************************************************************************************
# 9 node Quad
quad9L = elbase.createElement( 9,           # Number of basis 
                              2,            # Characteristic order of the polynomials
                              elQuadrangleL,# Geometric type
                              elkindIso,    # Kind of element 
                              2,            # Number of dimensions
                              quad9_iso,    # Basis functions.
                              [point1, line3L],
                              [vertexIndx, edgeIndx])
# ----------------------------------------------------------------------------------------------------

# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::: END QUADRANGLE ELEMENTS LOBATTO ::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::






# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# :::::::::::::::::::::::::::::::::   HEXAHEDRAL ELEMENTS   ::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

# ****************************************************************************************************
# 1 node hexahedra
vertexIndx = np.array([[ 0, ],] ,dtype=np.uint64) # Define the vertex indices of the hexahedra.
edgeIndx   = np.array([[ 0, ],] ,dtype=np.uint64) # Define the edge indices of the hexahedra.
faceIndx   = np.array([[ 0, ],] ,dtype=np.uint64) # Define the face indices of the hexahedra.

hex1 = elbase.createElement(  1,            # Number of basis 
                              0,            # Characteristic order of the polynomials
                              elHexahedra,  # Geometric type
                              elkindIso,    # Kind of element 
                              3,            # Number of dimensions
                              hex1_iso,     # Basis functions.
                              [point1, line1, quad1],
                              [ vertexIndx, edgeIndx, faceIndx])
# ----------------------------------------------------------------------------------------------------

# ****************************************************************************************************
# 4 node hexahedra
vertexIndx = np.array([[ 0 ],       # Define the vertex indices of the hexahedra.
                       [ 1 ],    
                       [ 2 ],
                       [ 3 ],
                       [ 4 ],
                       [ 5 ],
                       [ 6 ],
                       [ 7 ],],dtype=np.uint64)

edgeIndx = np.array([[ 0, 1 ],   # Define the edge indices of the hexahedra.
                     [ 1, 2 ],
                     [ 2, 3 ],
                     [ 3, 0 ],
                     [ 4, 5 ],
                     [ 5, 6 ],
                     [ 6, 7 ],
                     [ 7, 4 ],
                     [ 0, 4 ],
                     [ 1, 5 ],
                     [ 2, 6 ],
                     [ 3, 7 ],
                     ],dtype=np.uint64)

faceIndx = np.array([[ 0, 3, 2, 1 ],   # Define the face indices of the hexahedra.
                     [ 4, 5, 6, 7 ],
                     [ 0, 1, 5, 4 ],
                     [ 1, 2, 6, 5 ],
                     [ 2, 3, 7, 6 ],
                     [ 3, 0, 4, 7 ],
                     ],dtype=np.uint64)

hex8 = elbase.createElement(  8,            # Number of basis 
                              1,            # Characteristic order of the polynomials
                              elHexahedra,  # Geometric type
                              elkindIso,    # Kind of element 
                              3,            # Number of dimensions
                              hex8_iso,     # Basis functions.
                              [point1, line2, quad4],
                              [ vertexIndx, edgeIndx, faceIndx])
# ----------------------------------------------------------------------------------------------------

# ****************************************************************************************************
# 10 node hexahedra
edgeIndx = np.array([[ 0, 1,  8 ],   # Define the edge indices of the hexahedra.
                     [ 1, 2, 11 ],
                     [ 2, 3, 13 ],
                     [ 3, 0,  9 ],
                     [ 4, 5, 16 ],
                     [ 5, 6, 18 ],
                     [ 6, 7, 19 ],
                     [ 7, 4, 17 ],
                     [ 0, 4, 10 ],
                     [ 1, 5, 12 ],
                     [ 2, 6, 14 ],
                     [ 3, 7, 15 ],
                     ],dtype=np.uint64)

faceIndx = np.array([[ 0, 3, 2, 1,  9, 13, 11,  8 ],   # Define the face indices of the hexahedra.
                     [ 4, 5, 6, 7, 16, 18, 19, 17 ],
                     [ 0, 1, 5, 4,  8, 12, 16, 10 ],
                     [ 1, 2, 6, 5, 11, 14, 18, 12 ],
                     [ 2, 3, 7, 6, 13, 15, 19, 14 ],
                     [ 3, 0, 4, 7,  9, 10, 17, 15 ],
                     ],dtype=np.uint64)

hex20 = elbase.createElement( 20,           # Number of basis 
                              2,            # Characteristic order of the polynomials
                              elHexahedra,  # Geometric type
                              elkindIso,    # Kind of element 
                              3,            # Number of dimensions
                              hex20_iso,    # Basis functions.
                              [point1, line3, quad8],
                              [ vertexIndx, edgeIndx, faceIndx])
# ----------------------------------------------------------------------------------------------------

# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::: END HEXAHEDRAL ELEMENTS ::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::


# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# :::::::::::::::::::::::::::::::::   HEXAHEDRAL ELEMENTS LOBATTO  :::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

# ****************************************************************************************************
# 1 node hexahedra
vertexIndx = np.array([[ 0, ],] ,dtype=np.uint64) # Define the vertex indices of the hexahedra.
edgeIndx   = np.array([[ 0, ],] ,dtype=np.uint64) # Define the edge indices of the hexahedra.
faceIndx   = np.array([[ 0, ],] ,dtype=np.uint64) # Define the face indices of the hexahedra.

hex1L = elbase.createElement(  1,           # Number of basis 
                              0,            # Characteristic order of the polynomials
                              elHexahedraL, # Geometric type
                              elkindIso,    # Kind of element 
                              3,            # Number of dimensions
                              hex1_iso,     # Basis functions.
                              [point1, line1L, quad1L],
                              [ vertexIndx, edgeIndx, faceIndx])
# ----------------------------------------------------------------------------------------------------

# ****************************************************************************************************
# 4 node hexahedra
vertexIndx = np.array([[ 0 ],       # Define the vertex indices of the hexahedra.
                       [ 1 ],    
                       [ 2 ],
                       [ 3 ],
                       [ 4 ],
                       [ 5 ],
                       [ 6 ],
                       [ 7 ],],dtype=np.uint64)

edgeIndx = np.array([[ 0, 1 ],   # Define the edge indices of the hexahedra.
                     [ 1, 2 ],
                     [ 2, 3 ],
                     [ 3, 0 ],
                     [ 4, 5 ],
                     [ 5, 6 ],
                     [ 6, 7 ],
                     [ 7, 4 ],
                     [ 0, 4 ],
                     [ 1, 5 ],
                     [ 2, 6 ],
                     [ 3, 7 ],
                     ],dtype=np.uint64)

faceIndx = np.array([[ 0, 3, 2, 1 ],   # Define the face indices of the hexahedra.
                     [ 4, 5, 6, 7 ],
                     [ 0, 1, 5, 4 ],
                     [ 1, 2, 6, 5 ],
                     [ 2, 3, 7, 6 ],
                     [ 3, 0, 4, 7 ],
                     ],dtype=np.uint64)

hex8L = elbase.createElement(  8,           # Number of basis 
                              1,            # Characteristic order of the polynomials
                              elHexahedraL, # Geometric type
                              elkindIso,    # Kind of element 
                              3,            # Number of dimensions
                              hex8_iso,     # Basis functions.
                              [point1, line2L, quad4L],
                              [ vertexIndx, edgeIndx, faceIndx])
# ----------------------------------------------------------------------------------------------------

# ****************************************************************************************************
# 10 node hexahedra
edgeIndx = np.array([[ 0, 1,  8 ],   # Define the edge indices of the hexahedra.
                     [ 1, 2, 11 ],
                     [ 2, 3, 13 ],
                     [ 3, 0,  9 ],
                     [ 4, 5, 16 ],
                     [ 5, 6, 18 ],
                     [ 6, 7, 19 ],
                     [ 7, 4, 17 ],
                     [ 0, 4, 10 ],
                     [ 1, 5, 12 ],
                     [ 2, 6, 14 ],
                     [ 3, 7, 15 ],
                     ],dtype=np.uint64)

faceIndx = np.array([[ 0, 3, 2, 1,  9, 13, 11,  8 ],   # Define the face indices of the hexahedra.
                     [ 4, 5, 6, 7, 16, 18, 19, 17 ],
                     [ 0, 1, 5, 4,  8, 12, 16, 10 ],
                     [ 1, 2, 6, 5, 11, 14, 18, 12 ],
                     [ 2, 3, 7, 6, 13, 15, 19, 14 ],
                     [ 3, 0, 4, 7,  9, 10, 17, 15 ],
                     ],dtype=np.uint64)

hex20L = elbase.createElement( 20,          # Number of basis 
                              2,            # Characteristic order of the polynomials
                              elHexahedraL, # Geometric type
                              elkindIso,    # Kind of element 
                              3,            # Number of dimensions
                              hex20_iso,    # Basis functions.
                              [point1, line3L, quad8L],
                              [ vertexIndx, edgeIndx, faceIndx])
# ----------------------------------------------------------------------------------------------------

# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::: END HEXAHEDRAL ELEMENTS LOBATTO  :::::::::::::::::::::::::::::::::
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
elements['tetra'].append(tet10) # Order 2

elements['brick']=[]
elements['brick'].append(hex1 ) # Order 0
elements['brick'].append(hex8 ) # Order 1
elements['brick'].append(hex20) # Order 2




# Supported
element_list = {}

element_list[15] = elements['point'][0]

element_list[1 ] = elements['line']
element_list[8 ] = elements['line']

element_list[2 ] = elements['triangle']
element_list[9 ] = elements['triangle']

element_list[3 ] = elements['serendipity']
element_list[16] = elements['serendipity']
element_list[10] = elements['quad']

element_list[4 ] = elements['tetra']
element_list[11] = elements['tetra']

element_list[5 ] = elements['brick']
element_list[17] = elements['brick']