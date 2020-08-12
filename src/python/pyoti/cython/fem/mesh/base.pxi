

  
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::     CLASS  MESH       :::::::::::::::::::::::::::::::::::::::::
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

    # self.nodes       = None

    self.spaces      = []
    self.opCount     = 0
    self.xyzInit     = 0
    
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
    cdef str out = ''
    cdef int64_t i
    out = "< mesh (soti) object with "
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
    cdef str out = ''
    cdef int64_t i
    out = "< mesh (soti) object with "
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
  def export(self, filename, binary = True, dims = None, pd = None, pd_names= None):
    """
    This function loads a file in current format.

    INPUTS:

        - filename:       Name of the file to save.
        - binary(True):   
        - dims(None):     Dimensions to export.
        - pd(None):       Point Data (can be given in matso or numpy array formats).
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
    This function loads a file in current format.

    Currently supported filenames are 
     - *.msh (GMSH format)
     - *.geo (GMSH format)

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
    Th.x = array( nodalCoord[ : , 0 ] )
    Th.y = array( nodalCoord[ : , 1 ] )
    Th.z = array( nodalCoord[ : , 2 ] )

    return Th

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  @property
  def nnodes(self):
    """
    PORPUSE: Get Number of nodes.

    """
    #*************************************************************************************************
    
    return self.x.arr.nrows
    
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
    
    # for i in range(self.nnodes):

    #   res[i,0] = self.x[i,0].real
    #   res[i,1] = self.y[i,0].real
    #   res[i,2] = self.z[i,0].real

    # # end for 

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
    PORPUSE: Export mesh as vtk object. Requires VTK.

    INPUTS:

        - dims(None):      Dimensions to export.
        - pd(None):        Point Data (can be given in matso or numpy array formats).
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

          vtk_grid.GetPointData().SetVectors(vtk_array)

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
        - pd(None):       Point Data (can be given in matso or numpy array formats).
        - pd_names(None): Point data names to export.

    OUTPUTS:

        - grid: PyVista UnstructuredGrid object. 

    """
    #*************************************************************************************************
    import pyvista as pv

    return pv.UnstructuredGrid(self.to_vtk(dims = dims, pd = pd, pd_names= pd_names))
    # return pv.PolyData(self.to_vtk(dims = dims, pd = pd, pd_names= pd_names))

  #---------------------------------------------------------------------------------------------------
  

  # #***************************************************************************************************
  # @property
  # def domainElements(self):
    
  #   return self.domainEls

  # #---------------------------------------------------------------------------------------------------

  # #***************************************************************************************************
  # @property
  # def nx(self):
    
  #   return self.normalx

  # #---------------------------------------------------------------------------------------------------

  # #***************************************************************************************************
  # @property
  # def ny(self):
    
  #   return self.normaly

  # #---------------------------------------------------------------------------------------------------

  # #***************************************************************************************************
  # @property
  # def nz(self):
    
  #   return self.normalz

  # #---------------------------------------------------------------------------------------------------

  # #***************************************************************************************************
  # def pertBoundNormal(self, boundIds,  sotinum value, indv=False, incldCorners=True):
  #   """
  #   PORPUSE: To perturb the mesh in a specific direction.

  #   indv: Individually perturb the boundary

  #   """ 
  #   cdef uint64_t bdim = 0, bdof, i0=0, i1=1, nels, ndId, i, j
  #   cdef list alreadyPerturbedNodes=[]
  #   cdef sotinum_t tmpSoti

  #   if indv==False:

  #     # All boundary values are perturbed in the same fashion.

  #     # determine the dimensions of the boundary.
  #     bdim = self.ndim-1
      
  #     # Loop each
  #     for boundEls in self.elemTable[bdim]:

  #       nels = boundEls.shape[i0]
  #       bdof = boundEls.shape[i1]-1
  #       # Do the first and last items if incldCorners is true.
  #       for i in range(nels):
          
  #         for j in range(bdof):

  #           ndId = boundEls[i,j]-1
            
  #           if  ndId not in alreadyPerturbedNodes:

  #             alreadyPerturbedNodes.append(ndId)
              
  #             tmpSoti.p_coefs = NULL
  #             tmpSoti.p_indx = NULL
  #             tmpSoti.size = 0
              
  #             c_soti_sum( &self.xcoords.array.p_data[ndId], &value.num, tmpSoti,p_dH)

          
  #         # end for

  #       # end for 


  #   # else:

  #   #   # All boundary values are perturbed differently.


  #   # end if 



  # #---------------------------------------------------------------------------------------------------

  # #***************************************************************************************************
  # def pertDomainOnly(self, sotinum px, sotinum py, sotinum pz):
  #   """
  #   PORPUSE: To perturb the mesh in a specific direction.

  #   """
    
    

  # #---------------------------------------------------------------------------------------------------

  # #***************************************************************************************************
  # def computeNormals(self):


  #   self.normalx = np.zeros(self.xcoords.shape,dtype = np.double)
  #   self.normaly = np.zeros(self.xcoords.shape,dtype = np.double)
  #   self.normalz = np.zeros(self.xcoords.shape,dtype = np.double)

  #   nodesx = self.xcoords.real
  #   nodesy = self.ycoords.real
  #   nodesz = self.zcoords.real

  #   cdef int64_t i, j, k
  #   cdef np.ndarray boundEls
  #   for i in range( len( self.elemTable[self.ndim-1] ) ):
      
  #     boundEls = self.elemTable[self.ndim-1][i]
      
  #     for j in range( boundEls.shape[0] ):
        
  #       if self.ndim==1:
          
  #         # Boundary is made of points
  #         row,col=np.where(self.domainEls[:,:2]==boundEls[j,0])

  #         if row.size == 1:
  #           if col[0]==0:
  #             self.normalx[int(boundEls[j,0]-1),0]=-1.0
  #           else:
  #             self.normalx[int(boundEls[j,0]-1),0]=1.0
  #           # end if

  #       elif self.ndim==2:
  #         # Boundary is made of lines
          
  #         tangx = nodesx[int(boundEls[j,1]-1)]-nodesx[int(boundEls[j,0]-1)]
  #         tangy = nodesy[int(boundEls[j,1]-1)]-nodesy[int(boundEls[j,0]-1)]
  #         normtang = np.sqrt(tangx**2+tangy**2)

  #         normx = tangy/normtang
  #         normy = -tangx/normtang

  #         for k in range( int( boundEls.shape[1]-1 ) ):

  #           self.normalx[int(boundEls[j,k]-1),0]=self.normalx[int(boundEls[j,k]-1),0]+normx
  #           self.normaly[int(boundEls[j,k]-1),0]=self.normaly[int(boundEls[j,k]-1),0]+normy

  #         # end for


  #       # elif self.ndim==3:
  #         # Boundary is made of triangles

  #       # end if 

  #     # end for 

  #   # end for 

  #   #normalize again:

  #   if self.ndim>1:

  #     for i in range( len( self.elemTable[self.ndim-1] ) ):
        
  #       boundEls = self.elemTable[self.ndim-1][i]
        
  #       for j in range( boundEls.shape[0] ):
          
  #         for k in range( int( boundEls.shape[1]-1 ) ):

  #           normx = self.normalx[int(boundEls[j,k]-1),0]
  #           normy = self.normaly[int(boundEls[j,k]-1),0]
  #           normz = self.normalz[int(boundEls[j,k]-1),0]

  #           nnorm = np.sqrt(normx**2+normy**2+normz**2)

  #           self.normalx[int(boundEls[j,k]-1),0] = normx/nnorm
  #           self.normaly[int(boundEls[j,k]-1),0] = normy/nnorm
  #           self.normalz[int(boundEls[j,k]-1),0] = normz/nnorm

  #         # end for 
            
  #       # end for 

  #     # end for 




  # #---------------------------------------------------------------------------------------------------


    

  # #***************************************************************************************************
  # def getBoundNormals(self,list boundIds):

  #   normalx = np.zeros(self.xcoords.shape,dtype = np.double)
  #   normaly = np.zeros(self.xcoords.shape,dtype = np.double)
  #   normalz = np.zeros(self.xcoords.shape,dtype = np.double)

  #   nodesx = self.xcoords.real
  #   nodesy = self.ycoords.real
  #   nodesz = self.zcoords.real

  #   cdef int64_t i, j, k
  #   cdef np.ndarray boundEls

  #   for i in range( len( boundIds ) ):
      
  #     if type(boundIds[i]) == str:
  #       bId = self.nameIds[boundIds[i]]
  #     else:
  #       bId = boundIds[i]
  #     # end if 
  #     bIndx = self.elsIds[self.ndim-1].index(bId)
  #     boundEls = self.elemTable[self.ndim-1][bIndx]
      
  #     for j in range( boundEls.shape[0] ):
        
  #       if self.ndim==1:
  #         # Boundary is made of points
  #         row,col=np.where(self.domainEls[:,:2]==boundEls[j,0])
  #         if row.size == 1:
  #           if col[0]==0:
  #             normalx[int(boundEls[j,0]-1),0]=-1.0
  #           else:
  #             normalx[int(boundEls[j,0]-1),0]=1.0    
  #           # end if

  #       elif self.ndim==2:
  #         # Boundary is made of lines
          
  #         tangx = nodesx[int(boundEls[j,1]-1)]-nodesx[int(boundEls[j,0]-1)]
  #         tangy = nodesy[int(boundEls[j,1]-1)]-nodesy[int(boundEls[j,0]-1)]
  #         normtang = np.sqrt(tangx**2+tangy**2)

  #         normx = tangy/normtang
  #         normy = -tangx/normtang

  #         for k in range( int( boundEls.shape[1]-1 ) ):

  #           normalx[int(boundEls[j,k]-1),0]=normalx[int(boundEls[j,k]-1),0]+normx
  #           normaly[int(boundEls[j,k]-1),0]=normaly[int(boundEls[j,k]-1),0]+normy

  #         # end for


  #       # elif self.ndim==3:
  #         # Boundary is made of triangles

  #       # end if 

  #     # end for 

  #   # end for 

  #   #normalize again:

  #   if self.ndim>1:

  #     for i in range( len( boundIds ) ):
        
  #       if type(boundIds[i]) == str:
  #         bId = self.nameIds[boundIds[i]]
  #       else:
  #         bId = boundIds[i]
  #       # end if 
        
  #       bIndx = self.elsIds[self.ndim-1].index(bId)
  #       boundEls = self.elemTable[self.ndim-1][bIndx]

  #       for j in range( boundEls.shape[0] ):
          
  #         for k in range( int( boundEls.shape[1]-1 ) ):

  #           normx = normalx[int(boundEls[j,k]-1),0]
  #           normy = normaly[int(boundEls[j,k]-1),0]
  #           normz = normalz[int(boundEls[j,k]-1),0]

  #           nnorm = np.sqrt(normx**2+normy**2+normz**2)

  #           normalx[int(boundEls[j,k]-1),0] = normx/nnorm
  #           normaly[int(boundEls[j,k]-1),0] = normy/nnorm
  #           normalz[int(boundEls[j,k]-1),0] = normz/nnorm

  #         # end for 
            
  #       # end for 

  #     # end for 
  #   # end if 

  #   return (normalx,normaly,normalz)

  # #---------------------------------------------------------------------------------------------------

  # #***************************************************************************************************
  # cdef uint64_t getBaseDOFs(self):
  #   """
  #   PURPOSE: get the basic order 1 domain DOFs according to the element type.
  #   """
  #   cdef uint64_t res = 0

  #   if self.domainType == elLine:
      
  #     res = 2
      
  #   elif self.domainType == elTriangle:
      
  #     res = 3
      
  #   elif self.domainType == elQuadrangle:
    
  #     res = 4
    
  #   elif self.domainType == elTetrahedra:
      
  #     res = 4
    
  #   elif self.domainType == elHexahedra:
      
  #     res = 8
      
  #   # end if

  #   return res
  # #---------------------------------------------------------------------------------------------------

  # #***************************************************************************************************
  # cdef uint64_t getDomainVtkCellId(self, dofs):
  #   """
  #   PURPOSE: get the equivalent vtk number id of the element type.
  #   """
  #   cdef uint64_t res = 0
  #   if self.domainType == elLine:
  #     if dofs==2:
  #       res = 3
  #     elif dofs==3:
  #       res = 21
  #     # end if 
  #   elif self.domainType == elTriangle:
  #     if dofs==3:
  #       res = 5
  #     elif dofs==6:
  #       res = 22
  #     # end if 
  #   elif self.domainType == elQuadrangle:
  #     if dofs==4:
  #       res = 9
  #     elif dofs==8:
  #       res = 23
  #     # end if 
  #   elif self.domainType == elTetrahedra:
  #     if dofs==4:
  #       res = 10
  #     elif dofs==10:
  #       res = 24
  #     # end if 
  #   elif self.domainType == elHexahedra:
  #     if dofs==8:
  #       res = 3
  #     elif dofs==20:
  #       res = 25
  #     # end if 
  #   # end if
  #   return res
  # #---------------------------------------------------------------------------------------------------

  # #***************************************************************************************************
  # cpdef uint64_t getGlobalDOFBound(self,int64_t ndim, fespace space):
  #   """
  #   PURPOSE: get the total number of degrees of freedom of a mesh according to the interpolation
  #            functions.

  #   """


  #   cdef int64_t i,  nodei
  #   cdef uint64_t j, elemDOF
  #   cdef uint64_t gloabalDOF
  #   cdef list nodes = []


  #   # Get the DOF for the specifyed boundary.
  #   if space not in self.fespaces:
  #     raise ValueError("Finite Element space must belong to the mesh.")
  #   # end if 

  #   # Check first if the number of dimensions is valid.
  #   if ndim > space.elType.ndim:
    
  #     raise ValueError("The maximum dimension of the mesh is: ",space.elType.ndim )

  #   elif ndim == space.elType.ndim:

  #     return self.getGlobalDOF(space)

  #   # end if 

  #   elemDOF = space.elType.boundEls[ndim].nbasis

  #   if elemDOF > self.domainElDofs:
  #     raise ValueError("Mesh is not prepared for the number of D.O.Fs. of Finite Element Space")
  #   # end if 
    
  #   all_elements = np.array([])

  #   for i in range(len(space.mesh.elemTable[ndim])):
  #     LocalBoundEls = np.unique(space.mesh.elemTable[ndim][i][:,:elemDOF])
  #     all_elements = np.append(all_elements,LocalBoundEls)
  #   # end for 

  #   return len(np.unique(all_elements))
  # #---------------------------------------------------------------------------------------------------


  # #***************************************************************************************************
  # cpdef uint64_t getGlobalDOF(self,fespace space):
  #   """
  #   PURPOSE: get the total number of degrees of freedom of a mesh according to the interpolation
  #            functions.

  #   """


  #   cdef int64_t i,  nodei
  #   cdef uint64_t j, elemDOF 
  #   cdef uint64_t gloabalDOF
  #   cdef list nodes = []
    
  #   if space not in self.fespaces:

  #     raise ValueError("Finite Element space must belong to the mesh.")

  #   # end if 

  #   elemDOF = space.elType.nbasis

  #   if elemDOF > self.domainElDofs:

  #     raise ValueError("Mesh is not prepared for the number of D.O.Fs. of Finite Element Space")

  #   # end if 

  #   if elemDOF == self.domainElDofs:
    
  #     gloabalDOF =  self.xcoords.shape[0]
    
  #   else:

  #     # for i in range(self.domainEls.shape[0]):

  #     #   for j in range(elemDOF):

  #     #     nodei = self.domainEls[i,j]

  #     #     if nodei not in nodes:

  #     #       nodes.append(nodei)

  #     #     # end if 

  #     #   # end for

  #     # # end for

  #     gloabalDOF = np.max(self.domainEls[:,:elemDOF])  # this because it comes already ordered.

  #   # end if 

  #   return gloabalDOF
  # #---------------------------------------------------------------------------------------------------



    




  # #***************************************************************************************************
  # cdef uint64_t addNewOperation(self):
  #   """
  #   PURPOSE:  maintain global ids for operations.

  #   """

  #   self.operationCount += 1

  #   return self.operationCount
  # #---------------------------------------------------------------------------------------------------

  # #***************************************************************************************************
  # cdef uint64_t addNewSpace(self, fespace space):
  #   """
  #   PURPOSE:      creates a new Finite Element space and adds a new element to the stack list of 
  #                 spaces that defines the interpolation of elements in the mesh.

  #                 This function also redefines the node interpolation.

  #   """
  #   cdef uint64_t i
    
  #   self.fespaces.append(space)
    
  #   self.elTypes.append(space.elType)

  #   i = len(self.elTypes)

  #   if self.xyzInit == 0:

  #     # To preserve dimensions, use integer array slicing: coords[:,[i]]
  #     # --> Using coords[:, i ] removes one dimension.
  #     self.x = space.newFunction( self.xcoords )
  #     self.y = space.newFunction( self.ycoords )
  #     self.z = space.newFunction( self.zcoords )

  #     self.xyzInit = 1

  #   # end if 
      
  #   return i-1
  # #---------------------------------------------------------------------------------------------------



# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# :::::::::::::::::::::::::::::::::::: END OF CLASS OTIMESH ::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

  






