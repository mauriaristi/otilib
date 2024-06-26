
# ----------------------------------------------------------------------------------------------------
# ---------------------------------------    CONSTANTS    --------------------------------------------
# ----------------------------------------------------------------------------------------------------

element_type_name = np.empty(100,dtype=object)
# Supported
element_type_name[15] = "point1"

element_type_name[1 ] = "line2"
element_type_name[8 ] = "line3"

element_type_name[2 ] = "tri3"
element_type_name[9 ] = "tri6"

element_type_name[3 ] = "quad4"
element_type_name[16] = "quad8"
element_type_name[10] = "quad9"

element_type_name[4 ] = "tet4"
element_type_name[11] = "tet10"

element_type_name[5 ] = "hex8"
element_type_name[17] = "hex20"

# Wedge elements
element_type_name[6 ] = "wedge6"#"PRI_6"
element_type_name[18] = "wedge15"#"PRI_15"


# Unsupported
element_type_name[7 ] = "PYR_5"
element_type_name[12] = "hex27"
element_type_name[13] = "PRI_18"
element_type_name[14] = "PYR_14"
element_type_name[19] = "PYR_13"
element_type_name[20] = "tri9"
element_type_name[21] = "tri10"
element_type_name[22] = "tri12"
element_type_name[23] = "tri15"
element_type_name[24] = "tri15I"
element_type_name[25] = "tri21"
element_type_name[26] = "line4"
element_type_name[27] = "line5"
element_type_name[28] = "line6"
element_type_name[29] = "tet20"
element_type_name[30] = "tet35"
element_type_name[31] = "tet56"
element_type_name[32] = "tet22"
element_type_name[33] = "tet28"
element_type_name[36] = "quad16"
element_type_name[37] = "quad25"
element_type_name[38] = "quad36"
element_type_name[39] = "quad12"
element_type_name[40] = "quad16I"
element_type_name[41] = "quad20"
element_type_name[42] = "tri28"
element_type_name[43] = "tri36"
element_type_name[44] = "tri45"
element_type_name[45] = "tri55"
element_type_name[46] = "tri66"
element_type_name[47] = "quad49"
element_type_name[48] = "quad64"
element_type_name[49] = "quad81"
element_type_name[50] = "quad100"
element_type_name[51] = "quad121"
element_type_name[52] = "tri18"
element_type_name[53] = "tri21I"
element_type_name[54] = "tri24"
element_type_name[55] = "tri27"
element_type_name[56] = "tri30"




element_type_map_vtk= np.empty(100, dtype=int)

element_type_map_vtk[15] = 1   # "point"

element_type_map_vtk[1 ] = 3   # "line2"
element_type_map_vtk[8 ] = 21  # "line3"

element_type_map_vtk[2 ] = 5   # "tri3"
element_type_map_vtk[9 ] = 22  # "tri6"

element_type_map_vtk[3 ] = 9   # "quad4"
element_type_map_vtk[16] = 23  # "quad8"
element_type_map_vtk[10] = 28  # "quad9"

element_type_map_vtk[4 ] = 10  # "tet4"
element_type_map_vtk[11] = 24  # "tet10"

element_type_map_vtk[5 ] = 12  # "hex8"
element_type_map_vtk[17] = 25  # "hex20"

element_type_map_vtk[6 ] = 13  # "wedge6"
element_type_map_vtk[18] = 26  # "wedge15"




element_geom_type = np.empty(100,dtype=object)
# Supported
element_geom_type[15] = elNode

element_geom_type[1 ] = elLine
element_geom_type[8 ] = elLine

element_geom_type[2 ] = elTriangle
element_geom_type[9 ] = elTriangle

element_geom_type[3 ] = elQuadrangle
element_geom_type[16] = elQuadrangle
element_geom_type[10] = elQuadrangle

element_geom_type[4 ] = elTetrahedra
element_geom_type[11] = elTetrahedra

element_geom_type[5 ] = elHexahedra
element_geom_type[17] = elHexahedra

element_geom_type[6 ] = elWedge
element_geom_type[18] = elWedge



element = {}

# Node element. (Order 0 element)
element[15] = point1

# Order 1 ('Linear') elements.
element[1 ] = line2
element[2 ] = tri3
element[3 ] = quad4
element[4 ] = tet4
element[5 ] = hex8

# Order 2. ('Quadratic') elements
element[8 ] = line3
element[9 ] = tri6
element[10] = quad9
element[11] = tet10

# Serendipity elements.
element[16] = quad8
element[17] = hex20

# Wedge elements.
element[6 ] = wedge6
element[18] = wedge15








#-----------------------------------------------------------------------------------------------------
  

#           UTILITY FUNCTIONS:

#*****************************************************************************************************
def end_elements():
  """
  This function deallocates all elements if already allocated.
  """
  #***************************************************************************************************
  
  for elem in element.values():
    elem.end()
  # end for 

#-----------------------------------------------------------------------------------------------------


#*****************************************************************************************************
def get_elements_from_gmsh( mesh, dim=-1, tag=-1 ):
  """
  This function allows to get the elements from a gmsh mesh and reshape the 
  nodal indices accordingly.
  """
  #***************************************************************************************************
  elTypes, elTags, nodes = mesh.getElements(dim=dim,tag=tag)
  
  for i in range(len(elTypes)):
    
    # Get the number of elements.
    numelsi = elTags[i].size

    # Reshape and set the node indices to a "0" notation.
    nodes[i] = nodes[i].reshape((numelsi,int(nodes[i].size// numelsi))) - 1
  
  # end for     
  
  return elTypes,elTags,nodes

#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
def map_indices(idxSrc,idxMap):
  """
  PURPOSE: 
  """
  #***************************************************************************************************
  srcShape = idxSrc.shape
  reshaped = idxSrc.reshape(idxSrc.size)

  for i in range(reshaped.size):
  
    reshaped[i] = idxMap[ reshaped[i] ]

  # end for

  return reshaped.reshape(idxSrc.shape)

#-----------------------------------------------------------------------------------------------------




#*****************************************************************************************************
def line(double a, double b, double he = 1.0, ndivs = None, element_order = 1, save=False, real= False):
  """
  PURPOSE: Define a 1D line mesh in the domain [a,b] with an element size he. The order of the element
  can be specified. 

  The output contains the physical groups named as follows:

  .. code-block::
  
      [left]                                  [right]
        |               [domain]                 |
        |                  v                     |
        [----------------------------------------]

  :param a: Starting point.
  :type a: float
  :param b: Ending point. 
  :type b: float
  :param he: <float> Element size. (default he = 1.0)
  :type he: float
  :param ndivs: Number of subdivisions of the line.
  :type ndivs: int, optional. Devault ndivs=None.
  :param element_order: Order of polynomial basis functions of the elements in the mesh 
  :type element_order: int, optional, default element_order=1.                            
  :param save: Bool to save mesh into file.
  :type save: Bool, default save=False
  :param real: Bool to create a mesh with intrinsic double arrays, otherwise use oti arrays.
  :type real: Bool, default real=False

  """
  #***************************************************************************************************
  import gmsh

  cdef object res
  
  gmsh.initialize()
  # gmsh.fltk.initialize()

  # Lets create a simple square element:
  model = gmsh.model
  geo   = model.geo
  option= gmsh.option

  P1 = geo.addPoint( a,  0, 0, he, 1)
  P2 = geo.addPoint( b,  0, 0, he, 2)

  L1 = geo.addLine(P1,P2) # Line

  model.addPhysicalGroup( 0, [P1],        101 )
  model.addPhysicalGroup( 0, [P2],        102 )

  model.addPhysicalGroup( 1, [L1],        201 )

  model.setPhysicalName( 0, 101, "left"     )
  model.setPhysicalName( 0, 102, "right"    )

  model.setPhysicalName( 1, 201, "domain"   )

  geo.synchronize()
  
  option.setNumber('Mesh.ElementOrder',element_order)
  
  if ndivs is not None:
  
    # Set number of divisions
    model.mesh.setTransfiniteCurve(L1, ndivs + 1 )
  
  # end if 

  model.mesh.generate(1)

  if save:
    gmsh.write("line.msh")
  # end if 

  res = mesh.from_gmsh(gmsh)

  gmsh.finalize()

  return res

#-----------------------------------------------------------------------------------------------------




#*****************************************************************************************************
def square(double width, double hight, double he = 1e30, ndivs = None, element_order = 1, quads = False, 
           quad_incomplete = 1, quad_linear = 1, structured = False, save=False, real= False):
  """
  Define a square mesh according to the given parameters. This function uses gmsh as the mesh generation
  backend.

  :param width:  Width of the square.
  :type  width: float.

  :param hight:  Height of the square.
  :type  hight: float.

  :param he: Size of elements in the mesh. Defaults to 1e30. 
  :type  he: float, optional. Default he= 1e30.

  :param ndivs: Number of element divisions. [ndivx,ndivy]. If integer, sets both. 
  :type  ndivs:   list or int, optional. Default ndivsNone.

  :param element_order: Order of element to be implemented. Default 1
  :type  element_order: int, optional. Default element_order = 1.

  :param quads: Bool to define if qued elements are to be generated. Defaluts to False. 
  :type  quads:   bool, optional. Default quads = False

  :param quad_incomplete: <int>: Indicates if quads are serendipity or not. Defaults to 1.
  :type  quad_incomplete: int, optional. Default quad_incomplete = 1.

  :param quad_linear: <int>: Defaults to 1.
  :type  quad_linear: int, optional. Default quad_linear=1.
  
  :param structured: <Bool>: Bool to set structured mesh. Defaults to False.
  :type  structured: bool, optional. Default structured=False.
  
  :param save: <Bool>: Bool to save mesh. Defaults False.
  :type  save: bool, optional. Default save=False.

  :param real: <Bool>: Not used. Defaults False.
  :type  real: bool, optional. Default real=False.

  :returns: a pyoti.fem.mesh object.

  """
  #***************************************************************************************************
  import gmsh

  cdef object res

  gmsh.initialize()
  # gmsh.fltk.initialize()

  # Lets create a simple square element:
  model = gmsh.model
  geo   = model.geo
  option= gmsh.option

  P1 = geo.addPoint( -width/2.0,    hight/2.0, 0, he, 1)
  P2 = geo.addPoint( -width/2.0,   -hight/2.0, 0, he, 2)
  P3 = geo.addPoint(  width/2.0,    hight/2.0, 0, he, 3)
  P4 = geo.addPoint(  width/2.0,   -hight/2.0, 0, he, 4)

  L1 = geo.addLine(P1,P2) # Left
  L2 = geo.addLine(P2,P4) # bottom
  L3 = geo.addLine(P4,P3) # right
  L4 = geo.addLine(P3,P1) # up

  loop1 = geo.addCurveLoop([L1,L2,L3,L4])

  surface = geo.addPlaneSurface([loop1])

  model.addPhysicalGroup( 0, [P1],        101 )
  model.addPhysicalGroup( 0, [P2],        102 )
  model.addPhysicalGroup( 0, [P3],        103 )
  model.addPhysicalGroup( 0, [P4],        104 )

  model.addPhysicalGroup( 1, [L1],        201 )
  model.addPhysicalGroup( 1, [L2],        202 )
  model.addPhysicalGroup( 1, [L3],        203 )
  model.addPhysicalGroup( 1, [L4],        204 )

  model.addPhysicalGroup( 2, [surface],   301 )

  model.setPhysicalName( 0, 101, "topleft"     )
  model.setPhysicalName( 0, 102, "bottomleft"  )
  model.setPhysicalName( 0, 103, "topright"    )
  model.setPhysicalName( 0, 104, "bottomright" )

  model.setPhysicalName( 1, 201, "left"        )
  model.setPhysicalName( 1, 202, "bottom"      )
  model.setPhysicalName( 1, 203, "right"       )
  model.setPhysicalName( 1, 204, "top"         )

  model.setPhysicalName( 2, 301, "domain"      )


  geo.synchronize()
  
  option.setNumber('Mesh.ElementOrder',element_order)
  

  # Recombine if quads are wanted.
  if quads:
    
    # Set body to recombine into quads.
    option.setNumber('Mesh.SecondOrderIncomplete',quad_incomplete)
    option.setNumber('Mesh.SecondOrderLinear',    quad_linear    )
    option.setNumber('Mesh.RecombineAll',         1)

  else:

    option.setNumber('Mesh.SecondOrderIncomplete',quad_incomplete)
    option.setNumber('Mesh.SecondOrderLinear',    quad_linear    )
    option.setNumber('Mesh.RecombineAll',         0)

  # end if 


  if ndivs is not None:

    if type(ndivs) == list:
      ndivx,ndivy = ndivs
    else:
      ndivx = ndivs
      ndivy = ndivs
    # end if
    
    # Set horizontal divisions
    model.mesh.setTransfiniteCurve(L2, ndivx+1 )
    model.mesh.setTransfiniteCurve(L4, ndivx+1 )

    # Set vertical divisions
    model.mesh.setTransfiniteCurve(L1, ndivy+1 )
    model.mesh.setTransfiniteCurve(L3, ndivy+1 )
  # end if 

  if structured:
    model.mesh.setTransfiniteSurface(surface)
  # end if 

  model.mesh.generate(2)

  if save:
    gmsh.write("square.msh")
  # end if 

  res = mesh.from_gmsh(gmsh)
  
  gmsh.finalize()

  return res

#-----------------------------------------------------------------------------------------------------




#*****************************************************************************************************
cpdef op_int2d(mesh Th, matso f, intorder = None, region = None ):
  """
  PURPOSE: Integrate over 2D elements.
  """
  #***************************************************************************************************
  
  global alg

  cdef int64_t  i, j, ii
  cdef object integral, tmp2, tmp1, fh
  cdef elbase elem

  els = Th.elements[2]

  integral = alg.zero()
  
  end_elements()
  
  #integrate 2D a fem array.
  for j in range(els['types'].size):

    elem = element[ els['types'][j] ]

    if not elem.is_allocated():
      
      elem.end()
      elem.allocate(intorder)
      elem.allocate_spatial(2,compute_Jinv = False)

      # Here the temporals shhould be created.
      fh   = alg.zeros( ( elem.nbasis, 1 ) )      
      tmp1 = alg.zero(nip=elem.nip)      
      tmp2 = alg.zero()

    # end if 

    elm_nodes = els['indices'][j]

    for i in range(elm_nodes.shape[0]):

      elem.set_coordinates(Th.x,Th.y,Th.z,elm_nodes[i,:])
      elem.compute_jacobian()

      for ii in range(elem.nbasis):
        fh[ii,0] = f[ int(elm_nodes[i,ii]),0]
      # end for 
      
      alg.dot_product(fh,elem.N,out=tmp1)
      alg.gauss_integrate( tmp1, elem.w_dJ, out=tmp2)
      alg.sum(tmp2,integral, out=integral)
            
      # integral = integral + gauss_integrate( dot_product( fh, elem.N), elem.w_dJ)
              
      # integral = integral + oti.dot_product( fh, oti.gauss_integrate( element.N, element.w_dJ) )

    # end for

  # end for
  
  end_elements()
  
  return integral

#-----------------------------------------------------------------------------------------------------














