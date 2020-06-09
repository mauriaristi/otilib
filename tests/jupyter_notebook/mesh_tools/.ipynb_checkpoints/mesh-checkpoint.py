


import numpy as np










  
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::     CLASS  MESH       :::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
class mesh:
  
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

    # Initialize the system.

    self.elements      = [[],[],[],[]]
    
    self.groups      = []
    self.group_names = {}

    self.ndim = -1
    self.nodes     = None

    self.fespaces       = []
    
    self.operationCount = 0

    self.xyzInit        = 0

  #---------------------------------------------------------------------------------------------------

  # #***************************************************************************************************
  # @staticmethod
  # def from_file(filename):
    
  #   cdef mesh Th = mesh()
    
  #   parts = filename.split(".")
  #   end = parts[len(parts)-1] 
    
  #   if   end == 'msh':
      
      

  #   elif end == 'geo':

  #   # end

  #   return Th

  # #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  @staticmethod
  def from_gmsh( gmsh ):

    # First get the elements:
    Th = mesh()


    gmesh  = gmsh.model.mesh
    gmodel = gmsh.model

    # Organize first the nodes and element numbering into a contiguous sequence.
    gmesh.renumberNodes()
    gmesh.renumberElements()

    nodeTags, nodalCoord, parametricCoord = gmesh.getNodes() # this gets all Nodal coordinates.
    nodeTags -= 1 # Change to python indices.

    # Get the number of nodes:
    nNodes = nodeTags.size

    # Reshape the nodal coordinates to (nNodes x 3) matrix:
    nodalCoord = nodalCoord.reshape((nNodes,3))

    Th.ndim = gmodel.getDimension()

    # get the elements for each dimension
    for dim in range(Th.ndim+1):

      elTypes , elTags , nodeIdx = get_elements_from_gmsh( gmesh, dim=dim, tag=-1 )

      # Set the elements to the Mesh object.
      Th.elements[dim] = {}

      Th.elements[dim]['types'] = elTypes
      Th.elements[dim]['tags']  = elTags
      Th.elements[dim]['nodes'] = nodeIdx
      Th.elements[dim]['groups'] = []

    # end for 

    # Get all phisical groups
    physGroups = gmodel.getPhysicalGroups()
    for pg in physGroups:
      name = gmodel.getPhysicalName(*pg)
      Th.groups.append([pg[0],pg[1]])
      Th.group_names[name] = pg[1]
      entities = gmodel.getEntitiesForPhysicalGroup(*pg)
      for entity in entities:
        elTypes, elTags, nodeIdx = gmesh.getElements(pg[0],entity)
      # end for 

    # end for 

    Th.nodes = nodalCoord 

    return Th

  #---------------------------------------------------------------------------------------------------

  def get_all_elements_pd(self):

    import pandas as pd

    # Get first the number of elements:
    nels = self.get_number_elements()

    # Set the number of columns:

    # Col 1: Element Dimension 
    # Col 2: Element type
    # Col 3: Element tag
    # Col 4: Element nodes

    ncols = 4 #
    data = np.empty((nels,ncols),dtype=object)
    k = 0
    for dim in range(self.ndim+1):

      for j in range(self.elements[dim]['types'].size):

        for l in range(self.elements[dim]['tags'][j].size):
          k = int(self.elements[dim]['tags'][j][l]-1)
          data[k,0] = dim
          data[k,1] = element_type_name[self.elements[dim]['types'][j]]
          data[k,2] = self.elements[dim]['tags'][j][l]
          data[k,3] = self.elements[dim]['nodes'][j][l]
          # k+=1

    pd.option_context('display.max_rows', None, 'display.max_columns', None)
    
    return pd.DataFrame(
      data=data,
      index=data[:,2],
      columns = ["Dim","Type","Tag","Nodes"])




  #---------------------------------------------------------------------------------------------------

  def get_all_elements(self):


    # Get first the number of elements:
    nels = self.get_number_elements()

    # Set the number of columns:
    # Col 1: Element Dimension 
    # Col 2: Element type
    # Col 3: Element tag
    # Col 4: Element nodes
    ncols = 5 #
    data = np.emtpy((nels,ncols),dtype=object)




  #---------------------------------------------------------------------------------------------------

  def get_number_elements(self, dim = -1):

    nels = 0

    for dim in range(self.ndim+1):
      
      for j in range(self.elements[dim]['types'].size):

        nels += self.elements[dim]['tags'][j].size

      # end for

    # end for

    return nels 

  #---------------------------------------------------------------------------------------------------

  def to_vtk(self, dims = None, pd = None, pd_names= None):

    import vtk
    import vtk.util.numpy_support as np_support

    # First copy the nodal points to the VTK format.
    vtk_pts = vtk.vtkPoints()
    vtk_pts.SetData(np_support.numpy_to_vtk(self.nodes,deep=1))

    # Create the unstructured grid for all data.
    vtk_grid = vtk.vtkUnstructuredGrid()

    # Set the previously created points
    vtk_grid.SetPoints(vtk_pts)


    nels = self.get_number_elements()

    # Allocate to store all elements.
    vtk_grid.Allocate(nels)

    if type(dims) == type(None):

      loop_vals = range(4)

    elif type(dims) == int:

      loop_vals = [dims]

    else:

      loop_vals = dims

    # end if 

    # First loop through all dimensions.
    for dim in loop_vals:
      
      # Get the equivalent element type
      for etypei in range(self.elements[dim]['types'].size):
        
        # Get the equivalent VTK element type.
        vtk_type = element_type_map_vtk[ self.elements[dim]['types'][etypei] ]
    
        
        # Get numebr of elements and number of nodes per elements
        elementsi = self.elements[dim]['nodes'][etypei]
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
    
    # end for 


    if type(pd) == list:

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

    return vtk_grid
  #---------------------------------------------------------------------------------------------------


  #***************************************************************************************************
  def to_pv():    

    import pyvista as pv

    return pv.UnstructuredGrid(self.to_vtk())

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
  # def exportToVTK(self,filename,list pd=[],list pdNames=[]):
  #   """
  #   PURPOSE: Export mesh and solution functions to vtk format.

  #   """

  #   f = open(filename, "w")

  #   f.write("# vtk DataFile Version 4.1\n")# Header
  #   f.write("Exported OTI solution\n")# Header
  #   f.write("ASCII\n")# Header

  #   f.write("DATASET UNSTRUCTURED_GRID\n")

  #   #First add the point data 
  #   cdef np.ndarray nodesx = self.xcoords.real
  #   cdef np.ndarray nodesy = self.ycoords.real
  #   cdef np.ndarray nodesz = self.zcoords.real
  #   cdef uint64_t nnodes, nels, elDof
  #   cdef list humDir
    
  #   elDof = self.getBaseDOFs()
  #   nnodes = np.max( self.domainEls[:,:elDof] )


  #   f.write("POINTS "+str(nnodes)+" double\n")

  #   cdef uint64_t i, i0=0,j,k
  #   for i in range(nnodes):
  #     f.write(str(nodesx[i,i0])+" "+str(nodesy[i,i0])+" "+str(nodesz[i,i0])+"\n")
  #   # end for 

  #   # add the elements
  #   nels = self.domainEls.shape[0]

  #   f.write("CELLS "+str(nels)+" "+str(nels*( int( elDof+1 ) ) )+" \n")
  #   for i in range(nels):
  #     f.write(str(elDof)+" ")
  #     for j in range(elDof):
  #       f.write(str( int( self.domainEls[i,j] - 1 ) )+" ")
  #     #end for 
  #     f.write("\n")
  #   # end for 

  #   cdef uint64_t cellVtkType = self.getDomainVtkCellId(elDof)
  #   cdef uint64_t ndata, nImDir
  #   f.write("CELL_TYPES "+str(nels)+" \n")
  #   for i in range(nels):
  #     f.write(str(cellVtkType)+"\n")
  #   # end for 

  #   if len(pd)!=0:
  #     if len(pdNames)!=len(pd):
  #       f.close()
  #       raise ValueError("pd and pdNames must match one to one.")
  #     # end if 

  #     f.write("POINT_DATA "+str(nnodes)+"\n")

  #     for j in range(len(pd)):
        
  #       if type(pd[j]) == list:
  #         # vector data
          
  #         flist = pd[j]
  #         ndata = len(flist)
  #         nImDir = flist[i0].data.Ndir
  #         order  = flist[i0].data.order
          
  #         for ndir in range(nImDir):       
  #           e_dir = getLatexDir(ndir,order)
  #           # end if 
  #           f.write("VECTORS "+pdNames[j]+'-'+e_dir+" double\n")
  #           for i in range(nnodes):
  #             for k in range(ndata):
                
  #               f.write(str(flist[k].data.data[i,ndir])+" ")

  #             # end for 
  #             for k in range(ndata,3):
  #               f.write("0 ")
  #             # end for 
  #             f.write("\n")
  #           # end for 
  #         # end for 
  #       else:
  #         # point data
  #         f.write("")
  #         nImDir= pd[j].data.Ndir
  #         order = pd[j].data.order
  #         # f.write("SCALARS "+pdNames[j]+" double "+str(j)+"\n")
  #         for ndir in range(nImDir):
  #           e_dir = getLatexDir(ndir,order)
  #           f.write("SCALARS "+pdNames[j]+'-'+e_dir+" double\n")
  #           f.write("LOOKUP_TABLE default\n")
  #           for i in range(nnodes):
              
  #             f.write(str(pd[j].data.data[i,ndir])+" ")
              
  #             f.write("\n")
  #           # end for 
  #         # end for

  #       # end if 

  #     # end for 

  #   # end if 

  #   f.close()

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
  # def __repr__(self):
    
  #   cdef str out = ''
  #   cdef int64_t i
    

  #   out = "<OTI mesh with "
  #   out += str(self.xcoords.shape[0])+" nodes, "
  #   out += str(self.domainEls.shape[0])+ " " + elTypeNames[self.domainType-elNode]+"s, "
  #   for i in range(len(self.boundaEls)):
  #     out+= str(self.boundaEls[i].shape[0])+" "+elTypeNames[self.boundaType[i]-elNode]+"s, "

  #   out += ">"

  #   return out
  # #---------------------------------------------------------------------------------------------------


  # #***************************************************************************************************
  # def __str__(self):
    
  #   cdef str out = ''

  #   out += "< OTI mesh with "
  #   out += str(self.nodes.shape[0])
  #   out += " nodes and "

  #   for key in self.cells.keys():
      
  #     out += str(self.cells[key].shape[0])
  #     out += " "
  #     out += key + 's and '

  #   # end for
    
  #   out = out[:-4] + '>'

  #   return out
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

  

  

#           UTILITY FUNCTIONS:

#
def get_elements_from_gmsh( mesh, dim=-1, tag=-1 ):
  """
  This function allows to get the elements from a gmsh mesh and reshape the 
  nodal indices accordingly.
  """
  elTypes, elTags, nodes = mesh.getElements(dim=dim,tag=tag)
  
  for i in range(len(elTypes)):
    
    # Get the number of elements.
    numelsi = elTags[i].size

    # Reshape and set the node indices to a "0" notation.
    nodes[i] = nodes[i].reshape((numelsi,int(nodes[i].size// numelsi))) - 1
  
  # end for     
  
  return elTypes,elTags,nodes

#

def map_indices(idxSrc,idxMap):
  
  srcShape = idxSrc.shape
  reshaped = idxSrc.reshape(idxSrc.size)

  for i in range(reshaped.size):
  
    reshaped[i] = idxMap[ reshaped[i] ]

  # end for

  return reshaped.reshape(idxSrc.shape)






element_type_name = np.empty(100,dtype=object)
element_type_name[15] = 'point'
element_type_name[1]  = 'line2'
element_type_name[2]  = 'tri3'
element_type_name[3]  = 'quad4'
element_type_name[8]  = 'line3'
element_type_name[9]  = 'tri6'
element_type_name[16]  = 'quad6'




element_type_map_vtk= np.empty(100,dtype=int)
element_type_map_vtk[15] = 1
element_type_map_vtk[1]  = 3
element_type_map_vtk[2]  = 5
element_type_map_vtk[3]  = 9
element_type_map_vtk[8]  = 21
element_type_map_vtk[9]  = 22
element_type_map_vtk[16] = 23



