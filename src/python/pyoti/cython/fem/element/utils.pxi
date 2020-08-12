# Create element objects.
# Point element
point1 = elbaseso.createElement(1,            # Number of basis 
                                0,            # Characteristic order of the polynomials
                                elNode,       # Geometric type
                                elkindIso,    # Kind of element 
                                0,            # Number of dimensions
                                point1_iso,   # Basis functions.
                                [])   



# Line elements
# 1 node line
line1 = elbaseso.createElement( 1,            # Number of basis 
                                0,            # Characteristic order of the polynomials
                                elLine,       # Geometric type
                                elkindIso,    # Kind of element 
                                1,            # Number of dimensions
                                line1_iso,    # Basis functions.
                                [point1,])   
# 2 node line
line2 = elbaseso.createElement( 2,            # Number of basis 
                                1,            # Characteristic order of the polynomials
                                elLine,       # Geometric type
                                elkindIso,    # Kind of element 
                                1,            # Number of dimensions
                                line2_iso,    # Basis functions.
                                [point1,])   
# 3 node line
line3 = elbaseso.createElement( 3,            # Number of basis 
                                2,            # Characteristic order of the polynomials
                                elLine,       # Geometric type
                                elkindIso,    # Kind of element 
                                1,            # Number of dimensions
                                line2_iso,    # Basis functions.
                                [point1,])   



# 2D elements:
# Triangle elements.
# 1 node Triangle
tri1 = elbaseso.createElement(  1,            # Number of basis 
                                0,            # Characteristic order of the polynomials
                                elTriangle,   # Geometric type
                                elkindIso,    # Kind of element 
                                2,            # Number of dimensions
                                tri1_iso,     # Basis functions.
                                [point1, line1])   
# 3 node triangle
tri3 = elbaseso.createElement(  3,            # Number of basis 
                                1,            # Characteristic order of the polynomials
                                elTriangle,   # Geometric type
                                elkindIso,    # Kind of element 
                                2,            # Number of dimensions
                                tri3_iso,     # Basis functions.
                                [point1, line2])   
# 4 node triangle (bubble)
tri4 = elbaseso.createElement(  4,            # Number of basis 
                                2,            # Characteristic order of the polynomials
                                elTriangle,   # Geometric type
                                elkindIso,    # Kind of element 
                                2,            # Number of dimensions
                                tri4_iso,     # Basis functions.
                                [point1,line2])   

# 6 node triangle
tri6 = elbaseso.createElement(  6,            # Number of basis 
                                2,            # Characteristic order of the polynomials
                                elTriangle,   # Geometric type
                                elkindIso,    # Kind of element 
                                2,            # Number of dimensions
                                tri6_iso,     # Basis functions.
                                [point1, line3])   

# Quadrangle elements.
# 1 node Quad
quad1 = elbaseso.createElement( 1,            # Number of basis 
                                0,            # Characteristic order of the polynomials
                                elQuadrangle, # Geometric type
                                elkindIso,    # Kind of element 
                                2,            # Number of dimensions
                                quad1_iso,    # Basis functions.
                                [point1, line1])   
# 4 node Quad
quad4 = elbaseso.createElement( 4,            # Number of basis 
                                1,            # Characteristic order of the polynomials
                                elQuadrangle, # Geometric type
                                elkindIso,    # Kind of element 
                                2,            # Number of dimensions
                                quad4_iso,    # Basis functions.
                                [point1, line2])   
# 8 node Quad (serendipity)
quad8 = elbaseso.createElement( 8,            # Number of basis 
                                2,            # Characteristic order of the polynomials
                                elQuadrangle, # Geometric type
                                elkindIso,    # Kind of element 
                                2,            # Number of dimensions
                                quad8_iso,    # Basis functions.
                                [point1, line3])   
# 8 node Quad (serendipity)
quad9 = elbaseso.createElement( 9,            # Number of basis 
                                2,            # Characteristic order of the polynomials
                                elQuadrangle, # Geometric type
                                elkindIso,    # Kind of element 
                                2,            # Number of dimensions
                                quad9_iso,    # Basis functions.
                                [point1, line3])


# Tetrahedra elements.
# 1 node tetrahedra
tet1 = elbaseso.createElement(  1,            # Number of basis 
                                0,            # Characteristic order of the polynomials
                                elTetrahedra, # Geometric type
                                elkindIso,    # Kind of element 
                                3,            # Number of dimensions
                                tet1_iso,     # Basis functions.
                                [point1, line1, tri1])
# 4 node tetrahedra
tet4 = elbaseso.createElement(  4,            # Number of basis 
                                1,            # Characteristic order of the polynomials
                                elTetrahedra, # Geometric type
                                elkindIso,    # Kind of element 
                                3,            # Number of dimensions
                                tet4_iso,     # Basis functions.
                                [point1, line2, tri3])
# 10 node tetrahedra
tet10 = elbaseso.createElement( 10,           # Number of basis 
                                1,            # Characteristic order of the polynomials
                                elTetrahedra, # Geometric type
                                elkindIso,    # Kind of element 
                                3,            # Number of dimensions
                                tet10_iso,    # Basis functions.
                                [point1, line3, tri6])


# Hexahedra elements.
# 1 node hexahedra
hex1 = elbaseso.createElement(  1,            # Number of basis 
                                0,            # Characteristic order of the polynomials
                                elHexahedra,  # Geometric type
                                elkindIso,    # Kind of element 
                                3,            # Number of dimensions
                                hex1_iso,     # Basis functions.
                                [point1, line1, quad1])
# 4 node hexahedra
hex8 = elbaseso.createElement(  8,            # Number of basis 
                                1,            # Characteristic order of the polynomials
                                elHexahedra,  # Geometric type
                                elkindIso,    # Kind of element 
                                3,            # Number of dimensions
                                hex8_iso,     # Basis functions.
                                [point1, line2, quad4])
# 10 node hexahedra
hex20 = elbaseso.createElement( 20,           # Number of basis 
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



















# Create element objects.
# Point element
dpoint1 = elbased.createElement(1,            # Number of basis 
                                0,            # Characteristic order of the polynomials
                                elNode,       # Geometric type
                                elkindIso,    # Kind of element 
                                0,            # Number of dimensions
                                point1_iso,   # Basis functions.
                                [])   



# Line elements
# 1 node line
dline1 = elbased.createElement( 1,            # Number of basis 
                                0,            # Characteristic order of the polynomials
                                elLine,       # Geometric type
                                elkindIso,    # Kind of element 
                                1,            # Number of dimensions
                                line1_iso,    # Basis functions.
                                [dpoint1,])   
# 2 node line
dline2 = elbased.createElement( 2,            # Number of basis 
                                1,            # Characteristic order of the polynomials
                                elLine,       # Geometric type
                                elkindIso,    # Kind of element 
                                1,            # Number of dimensions
                                line2_iso,    # Basis functions.
                                [dpoint1,])   
# 3 node line
dline3 = elbased.createElement( 3,            # Number of basis 
                                2,            # Characteristic order of the polynomials
                                elLine,       # Geometric type
                                elkindIso,    # Kind of element 
                                1,            # Number of dimensions
                                line2_iso,    # Basis functions.
                                [dpoint1,])   



# 2D elements:
# Triangle elements.
# 1 node Triangle
dtri1 = elbased.createElement(  1,            # Number of basis 
                                0,            # Characteristic order of the polynomials
                                elTriangle,   # Geometric type
                                elkindIso,    # Kind of element 
                                2,            # Number of dimensions
                                tri1_iso,     # Basis functions.
                                [dpoint1, dline1])   
# 3 node triangle
dtri3 = elbased.createElement(  3,            # Number of basis 
                                1,            # Characteristic order of the polynomials
                                elTriangle,   # Geometric type
                                elkindIso,    # Kind of element 
                                2,            # Number of dimensions
                                tri3_iso,     # Basis functions.
                                [dpoint1, dline2])   
# 4 node triangle (bubble)
dtri4 = elbased.createElement(  4,            # Number of basis 
                                2,            # Characteristic order of the polynomials
                                elTriangle,   # Geometric type
                                elkindIso,    # Kind of element 
                                2,            # Number of dimensions
                                tri4_iso,     # Basis functions.
                                [dpoint1,dline2])   

# 6 node triangle
dtri6 = elbased.createElement(  6,            # Number of basis 
                                2,            # Characteristic order of the polynomials
                                elTriangle,   # Geometric type
                                elkindIso,    # Kind of element 
                                2,            # Number of dimensions
                                tri6_iso,     # Basis functions.
                                [dpoint1, dline3])   

# Quadrangle elements.
# 1 node Quad
dquad1 = elbased.createElement( 1,            # Number of basis 
                                0,            # Characteristic order of the polynomials
                                elQuadrangle, # Geometric type
                                elkindIso,    # Kind of element 
                                2,            # Number of dimensions
                                quad1_iso,    # Basis functions.
                                [dpoint1, dline1])   
# 4 node Quad
dquad4 = elbased.createElement( 4,            # Number of basis 
                                1,            # Characteristic order of the polynomials
                                elQuadrangle, # Geometric type
                                elkindIso,    # Kind of element 
                                2,            # Number of dimensions
                                quad4_iso,    # Basis functions.
                                [dpoint1, dline2])   
# 8 node Quad (serendipity)
dquad8 = elbased.createElement( 8,            # Number of basis 
                                2,            # Characteristic order of the polynomials
                                elQuadrangle, # Geometric type
                                elkindIso,    # Kind of element 
                                2,            # Number of dimensions
                                quad8_iso,    # Basis functions.
                                [dpoint1, dline3])   
# 8 node Quad (serendipity)
dquad9 = elbased.createElement( 9,            # Number of basis 
                                2,            # Characteristic order of the polynomials
                                elQuadrangle, # Geometric type
                                elkindIso,    # Kind of element 
                                2,            # Number of dimensions
                                quad9_iso,    # Basis functions.
                                [dpoint1, dline3])


# Tetrahedra elements.
# 1 node tetrahedra
dtet1 = elbased.createElement(  1,            # Number of basis 
                                0,            # Characteristic order of the polynomials
                                elTetrahedra, # Geometric type
                                elkindIso,    # Kind of element 
                                3,            # Number of dimensions
                                tet1_iso,     # Basis functions.
                                [dpoint1, dline1, dtri1])
# 4 node tetrahedra
dtet4 = elbased.createElement(  4,            # Number of basis 
                                1,            # Characteristic order of the polynomials
                                elTetrahedra, # Geometric type
                                elkindIso,    # Kind of element 
                                3,            # Number of dimensions
                                tet4_iso,     # Basis functions.
                                [dpoint1, dline2, dtri3])
# 10 node tetrahedra
dtet10 = elbased.createElement( 10,           # Number of basis 
                                1,            # Characteristic order of the polynomials
                                elTetrahedra, # Geometric type
                                elkindIso,    # Kind of element 
                                3,            # Number of dimensions
                                tet10_iso,    # Basis functions.
                                [dpoint1, dline3, dtri6])


# Hexahedra elements.
# 1 node hexahedra
dhex1 = elbased.createElement(  1,            # Number of basis 
                                0,            # Characteristic order of the polynomials
                                elHexahedra,  # Geometric type
                                elkindIso,    # Kind of element 
                                3,            # Number of dimensions
                                hex1_iso,     # Basis functions.
                                [dpoint1, dline1, dquad1])
# 4 node hexahedra
dhex8 = elbased.createElement(  8,            # Number of basis 
                                1,            # Characteristic order of the polynomials
                                elHexahedra,  # Geometric type
                                elkindIso,    # Kind of element 
                                3,            # Number of dimensions
                                hex8_iso,     # Basis functions.
                                [dpoint1, dline2, dquad4])
# 10 node hexahedra
dhex20 = elbased.createElement( 20,           # Number of basis 
                                2,            # Characteristic order of the polynomials
                                elHexahedra,  # Geometric type
                                elkindIso,    # Kind of element 
                                3,            # Number of dimensions
                                hex20_iso,    # Basis functions.
                                [dpoint1, dline3, dquad8])



delements = {}
delements['point']=[]
delements['point'].append(dpoint1)

delements['line']=[]
delements['line'].append(dline1) # Order 0
delements['line'].append(dline2) # Order 1
delements['line'].append(dline3) # Order 2

delements['triangle']=[]
delements['triangle'].append(dtri1) # Order 0
delements['triangle'].append(dtri3) # Order 1
delements['triangle'].append(dtri6) # Order 2

delements['bubble']=[]
delements['bubble'].append(dtri1) # Order 0
delements['bubble'].append(dtri3) # Order 1
delements['bubble'].append(dtri4) # Order 1.b

delements['quad']=[]
delements['quad'].append(dquad1) # Order 0
delements['quad'].append(dquad4) # Order 1
delements['quad'].append(dquad9) # Order 2

delements['serendipity']=[]
delements['serendipity'].append(dquad1) # Order 0
delements['serendipity'].append(dquad4) # Order 1
delements['serendipity'].append(dquad8) # Order 2

delements['tetra']=[]
delements['tetra'].append(dtet1 ) # Order 0
delements['tetra'].append(dtet4 ) # Order 1
# elements['tetra'].append(tet10) # Order 2

delements['brick']=[]
delements['brick'].append(dhex1 ) # Order 0
delements['brick'].append(dhex8 ) # Order 1
delements['brick'].append(dhex20) # Order 2



