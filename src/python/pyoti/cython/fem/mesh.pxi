











  
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

    # Initialize the system.

    self.elements      = []
    
    self.element_ids       = []
    self.element_ids_names = {}

    
    self.nodes     = []

    # self.normalx   = np.array([])     
    # self.normaly   = np.array([])     
    # self.normalz   = np.array([])     
    
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


    gmsh


    return Th

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

  

  






