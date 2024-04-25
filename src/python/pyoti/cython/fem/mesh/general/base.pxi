
  
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::     CLASS  MESH      ::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
cdef class mesh:
  
  #---------------------------------------------------------------------------------------------------
  #------------------------------------   DEFINITION OF ATTRIBUTES   ---------------------------------
  #---------------------------------------------------------------------------------------------------


  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  def __init__(self): 
    """
    PURPOSE:      Constructor of the Mesh class for Finite Elements using OTI algebra.
                  
    PARAMETERS:   

              filename:  File name of the source file.
                  
    """

    # Initialize the values in the mesh.

    self.elements    = [ None, None, None, None ]
    self.groups      = []
    self.group_names = {}
    self.group_ids   = {}

    self.ndim        = -1

    self.x           = None
    self.y           = None
    self.z           = None

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************      
  def __repr__(self):
    """
    PORPUSE: Representation of the object.

    """
    #*************************************************************************************************
    global alg

    cdef str out = ''
    cdef int64_t i
    out = "< mesh ("+alg.__name__+") object with "
    out += str(self.nodes.shape[0])+" nodes, "
    out += str(self.get_number_elements())+" elements "
    out += "of types ( "

    for elem_dim in self.elements:    
      if elem_dim is not None:
        for i in range(len(elem_dim['types'])):

          elmType = elem_dim['types'][i]
          
          out += element_type_name[elmType] + " (" + str(elem_dim['indices'][i].shape[0]) + ")"
          out += ", "
          
        # end for 
      # end if
    # end for 
    
    out = out[:len(out)-2]+" )"

    out += " >"

    return out
  #---------------------------------------------------------------------------------------------------


  #***************************************************************************************************
  def __str__(self):
    """
    PORPUSE: String conversion of the object.

    """
    #*************************************************************************************************
    global alg
    
    cdef str out = ''
    cdef int64_t i
    out = "< mesh ("+alg.__name__+") object with "
    out += str(self.nnodes)+" nodes, "
    out += str(self.get_number_elements())+" elements "
    out += "of types: "

    for elem_dim in self.elements:    
      if elem_dim is not None:
        for i in range(len(elem_dim['types'])):

          elmType = elem_dim['types'][i]
          
          out += element_type_name[elmType] + " (" + str(elem_dim['indices'][i].shape[0]) + ")"
          out += ", "

        # end for 
      # end if
    # end for 
    
    out = out[:len(out)-2]

    out += " >"

    return out
  #---------------------------------------------------------------------------------------------------


  #***************************************************************************************************
  def export(self, filename, binary = True, dims = None, pd = None, pd_names= None):
    """
    This function loads a file in current format.

    INPUTS:

        - filename:       Name of the file to save.
        - binary(True):   
        - dims(None):     Dimensions to export.
        - pd(None):       Point Data (can be given in numpy array formats).
        - pd_names(None): Point data names to export.

    OUTPUTS:

        - saved file.

    """

    pv_grid = self.to_pv(dims = dims, pd = pd, pd_names= pd_names)
    
    pv_grid.save( filename, binary=binary)

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  @staticmethod
  def load(filename, generate = True, generate_level = 3):
    """
    PORPUSE: This function loads a file with format given by its extension. This function uses gmsh to 
             open the data

    Currently supported filenames are 
     - *.msh (GMSH format)
     - *.geo (GMSH format)


    INPUTS: 

    - filename: String with the filename including extension.
    - generate: (Boolean, optional, default True) Perform mesh generation from gmsh.
    - generate_level: (Integer, optional, default 3) Mesh generation option for the number of dimenions
                      to be generated..


    """

    import gmsh

    gmsh.initialize()
    gmsh.open(filename)
    
    if generate:    
      gmsh.model.mesh.generate(generate_level)
    # end if 

    Th = mesh.from_gmsh(gmsh)

    gmsh.finalize()

    return Th

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  @staticmethod
  def from_gmsh( gmsh ):
    """
    PORPUSE: Load from a gmsh object.

    """
    #*************************************************************************************************
    
    global alg

    # First get the elements:
    Th = mesh()


    gmesh  = gmsh.model.mesh
    gmodel = gmsh.model

    # Organize first the nodes and element numbering into a contiguous sequence.
    gmesh.renumberNodes()
    gmesh.renumberElements()

    # Get enodal values.
    nodeTags, nodalCoords, parametricCoord = gmesh.getNodes() # this gets all Nodal coordinates.
    nodeTags -= 1 # Change to python indices.
    # print(nodeTags)
    # Get the number of nodes:
    nNodes = nodeTags.size

    # Reshape the nodal coordinates to (nNodes x 3) matrix:
    nodalCoord = np.zeros((nNodes,3),dtype=np.float64)
    nodalCoord[nodeTags,:] = nodalCoords.reshape((nNodes,3))

    Th.ndim = gmodel.getDimension()

    # get the elements for each dimension
    for dim in range(Th.ndim+1):

      elTypes , elTags , nodeIdx = get_elements_from_gmsh( gmesh, dim=dim, tag=-1 )

      # Set the elements to the Mesh object.
      Th.elements[dim] = {}

      Th.elements[dim]['types']   = elTypes
      Th.elements[dim]['tags']    = elTags
      Th.elements[dim]['indices'] = nodeIdx
      # Th.elements[dim]['groups'] = []
      
      # print( gmodel.getEntities(dim=dim) )
      # for tag in range(1,len(elTags)+1):

      #   Th.elements[dim]['groups'].append(gmodel.getPhysicalGroupsForEntity(dim = dim, tag=tag))

      # # end for 

    # end for 

    # Get all phisical groups
    physGroups = gmodel.getPhysicalGroups()

    # Loop through all physical groups.
    for pg in physGroups:

      name = gmodel.getPhysicalName(*pg)
      dim = pg[0]
      
      # if  Th.groups[dim] is None:
      #   Th.groups[dim] = []
      # # end if 

      # Th.groups[ pg[1] ] ={}

      # print( name, pg[0], pg[1] )

      Th.groups.append( [ pg[0], pg[1] ])
      
      Th.group_ids[ pg[1] ] = name

      Th.group_names[name] = {}
      
      gname = Th.group_names[name]
      gname['dim']   = pg[0] 
      gname['id']    = pg[1]

      # Get the nodes that belong to the physical group.
      pgNodeTags, pgNodeCoords = gmesh.getNodesForPhysicalGroup(*pg)
      
      gname['nodes'] = pgNodeTags - 1
      
      entities = gmodel.getEntitiesForPhysicalGroup(*pg)
      
      gname['entities'] = entities
      
      gname['members'] = []

      k = 0

      for entity in entities:
        
        # elTypes, elTags, nodeIdx = gmesh.getElements(pg[0],entity)
        elTypes, elTags, nodeIdx = get_elements_from_gmsh( gmesh, dim=pg[0], tag=entity )
        # pgNodeTags, pgNodeCoords, pgNodeParamCoords = mesh.getNodes( dim=pg[0], tag=entity )
        gname['members'].append({})
        gname['members'][k]['types']   = elTypes
        gname['members'][k]['tags']    = elTags
        gname['members'][k]['nodes']   = pgNodeTags
        gname['members'][k]['indices'] = nodeIdx
        k += 1
        # print('Entity:'    , entity    )
        # print('-- Types:\n', elTypes   )
        # print('-- Tags:\n',  elTags    )
        # print('-- Nodes:\n', nodeIdx   )
        # print("\n"                     )
    
      # end for 

    # end for 

    # Th.nodes = nodalCoord 
    Th.x = alg.array( nodalCoord[ : , 0 ] )
    Th.y = alg.array( nodalCoord[ : , 1 ] )
    Th.z = alg.array( nodalCoord[ : , 2 ] )

    return Th

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  @property
  def nnodes(self):
    """
    PORPUSE: Get Number of nodes.

    """
    #*************************************************************************************************
    
    return self.x.shape[0]
    
  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  @property
  def nodes(self):
    """
    PORPUSE: Get nodes as numpy array.

    """
    #*************************************************************************************************
    
    cdef np.ndarray[coeff_t, ndim=2] res
    cdef int64_t i
    
    res = np.c_[self.x.real,self.y.real,self.z.real]

    return res   

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  def get_all_elements_pd(self):
    """
    PORPUSE: Export object as a pandas dataframe.

    """
    #*************************************************************************************************
    
    import pandas as pd
    
    data  = self.get_all_elements()

    pd.option_context('display.max_rows', None, 'display.max_columns', None)
    
    return pd.DataFrame(
      data=data,
      index=data[:,2],
      columns = ["Dim","Type","Tag","Nodes"])

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  def get_all_elements(self, dims = None):
    """
    PORPUSE: Get all the elements in a numpy array.

    """
    #*************************************************************************************************

    cdef uint64_t k, j, l, dim
    # Get first the number of elements:
    nels = self.get_number_elements()

    # Set the number of columns:

    # Col 1: Element Dimension 
    # Col 2: Element type
    # Col 3: Element tag
    # Col 4: Element nodes

    ncols = 4 
    
    data  = np.empty((nels,ncols),dtype=object)
    
    k     = 0

    for dim in range(self.ndim+1):

      elem_dim = self.elements[dim]

      if elem_dim is not None:
        for j in range(elem_dim['types'].size):
          for l in range(elem_dim['tags'][j].size):

            k = int(elem_dim['tags'][j][l]-1)

            data[k,0] = dim
            data[k,1] = element_type_name[elem_dim['types'][j]]
            data[k,2] = elem_dim['tags'][j][l]
            data[k,3] = elem_dim['indices'][j][l]
            # data[k,4] = elem_dim['groups'][j][l]
            # k+=1

          # end for 
        # end for 
      # end if
    # end for
    
    return data

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  def get_number_elements(self, dims = None):
    """
    PORPUSE: Get the total number of elements for a given dimension.

    """
    #*************************************************************************************************

    nels = 0

    if type(dims) == type(None):
      loop_vals = range(self.ndim+1)
    elif type(dims) == int:
      loop_vals = [dims]
    else:
      loop_vals = dims
    # end if 

    for dim in loop_vals:
      
      elem_dim = self.elements[dim]

      if elem_dim is not None:        
        for j in range(elem_dim['types'].size):

          nels += elem_dim['tags'][j].size

        # end for
      # end if 
    # end for

    return nels

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  def to_vtk(self, dims = None, pd = None, pd_names= None, linearize = False):
    """
    PORPUSE: Export mesh as vtk object. (Requires VTK).

    INPUTS:

        - dims(None):      Dimensions to export.
        - pd(None):        Point Data (can be given in numpy array formats).
        - pd_names(None):  Point data names to export.
        - linearize(None): Export as linear (order 1) elements. 

    OUTPUTS:

        - grid: VTK UnstructuredGrid object.

    """
    #*************************************************************************************************
    
    import vtk
    import vtk.util.numpy_support as np_support

    # First copy the nodal points to the VTK format.
    vtk_pts = vtk.vtkPoints()
    vtk_pts.SetData( np_support.numpy_to_vtk( self.nodes, deep=1 ) )

    # Create the unstructured grid for all data.
    vtk_grid = vtk.vtkUnstructuredGrid()
    # vtk_grid = vtk.vtkPolyData()

    # Set the previously created points
    vtk_grid.SetPoints(vtk_pts)

    nels = self.get_number_elements()

    # Allocate to store all elements.
    vtk_grid.Allocate(nels)

    if type(dims) == type(None):
      loop_vals = range(self.ndim+1)
    elif type(dims) == int:
      loop_vals = [dims]
    else:
      loop_vals = dims
    # end if 

    # First loop through all dimensions.
    for dim in loop_vals:
      
      elem_dim = self.elements[dim]

      if elem_dim is not None:

        # Get the equivalent element type
        for etypei in range(elem_dim['types'].size):
          
          # Get the equivalent VTK element type.
          vtk_type = element_type_map_vtk[ elem_dim['types'][etypei] ]
      
          
          # Get numebr of elements and number of nodes per elements
          elementsi = elem_dim['indices'][etypei]
          nelsi, nnodes_el = elementsi.shape
      
          # Loop for all elements in the array:
      
          for elem in range(nelsi):
      
            vtk_grid.InsertNextCell(
              vtk_type,         # Set element type.
              nnodes_el,        # Number of nodes in this cell.
              elementsi[ elem ] # Nodal indices.
              )
          # end for
        # end for 
      # end if     
    # end for 

    if type(pd) == list :

      for i in range(len(pd)):

        pdi = pd[i]
      
        if len(pdi.shape) == 1:

          # Setting 1D data
          vtk_array = np_support.numpy_to_vtk(pdi,deep=1)
          vtk_array.SetName(pd_names[i])

          vtk_grid.GetPointData().SetScalars(vtk_array)
          
        elif pdi.shape[1] == 1:

          # Setting 1D data
          vtk_array = np_support.numpy_to_vtk(pdi,deep=1)
          vtk_array.SetName(pd_names[i])

          vtk_grid.GetPointData().SetScalars(vtk_array)
          
        else:
          
          vtk_array = np_support.numpy_to_vtk(pdi,deep=1)
          vtk_array.SetName(pd_names[i])
          vtk_obj = vtk_grid.GetPointData().GetVectors()
          vtk_grid.GetPointData().SetVectors(vtk_array)
          if vtk_obj is not None:
            vtk_grid.GetPointData().AddArray(vtk_obj)
          # end if
        # end if
      # end for 
    # end if 

    return vtk_grid
  #---------------------------------------------------------------------------------------------------


  #***************************************************************************************************
  def to_pv(self, dims = None, pd = None, pd_names= None):    
    """
    PORPUSE: Export mesh as PyVista object. Requires PyVista.

    INPUTS:

        - dims(None):     Dimensions to export.
        - pd(None):       Point Data (can be given in numpy array formats).
        - pd_names(None): Point data names to export.

    OUTPUTS:

        - grid: PyVista UnstructuredGrid object. 

    """
    #*************************************************************************************************
    import pyvista as pv

    return pv.UnstructuredGrid(self.to_vtk(dims = dims, pd = pd, pd_names= pd_names))

  #---------------------------------------------------------------------------------------------------


# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# :::::::::::::::::::::::::::::::::::: END OF CLASS MESH :: ::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

  






