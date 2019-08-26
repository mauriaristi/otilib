











  
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::     CLASS  OTIMESH    :::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
cdef class mesh:
  
  #---------------------------------------------------------------------------------------------------
  #------------------------------------   DEFINITION OF ATTRIBUTES   ---------------------------------
  #---------------------------------------------------------------------------------------------------



  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  def __init__(self, filename, uint8_t otiorder = 1): 
    """
    PURPOSE:      Constructor of the Mesh class for Finite Elements using OTI algebra.
                  
    PARAMETERS:   

              filename:  File name of the source file.
                  
    """

    # nodes, self.cells, self.point_data, self.cell_data, self.field_data = meshio.read(filename)
    # self.nodes = sarray( nodes, order = order)

    
    self.cells      = {}
    self.point_data = {}
    self.cell_data  = {}
    self.field_data = {}

    self.elemTable  = []    
    
    self.domainEls = np.array([])     
    self.normalx   = np.array([])     
    self.normaly   = np.array([])     
    self.normalz   = np.array([])     
    self.boundaEls      = []  
    self.boundaType     = []  
    self.boundaElsIds   = []  
    self.elsIds         = [] 


    self.fespaces   = []
    self.elTypes    = []
    self.nameIds = {}
    self.otiorder = otiorder

    self.operationCount = 0
    self.xyzInit = 0   #



    self.readFromGMSH(filename)
    self.computeNormals()
  #---------------------------------------------------------------------------------------------------


  #***************************************************************************************************
  @property
  def domainElements(self):
    
    return self.domainEls

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  @property
  def nx(self):
    
    return self.normalx

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  @property
  def ny(self):
    
    return self.normaly

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  @property
  def nz(self):
    
    return self.normalz

  #---------------------------------------------------------------------------------------------------

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

  #***************************************************************************************************
  def computeNormals(self):


    self.normalx = np.zeros(self.xcoords.shape,dtype = np.double)
    self.normaly = np.zeros(self.xcoords.shape,dtype = np.double)
    self.normalz = np.zeros(self.xcoords.shape,dtype = np.double)

    nodesx = self.xcoords.real
    nodesy = self.ycoords.real
    nodesz = self.zcoords.real

    cdef int64_t i, j, k
    cdef np.ndarray boundEls
    for i in range( len( self.elemTable[self.ndim-1] ) ):
      
      boundEls = self.elemTable[self.ndim-1][i]
      
      for j in range( boundEls.shape[0] ):
        
        if self.ndim==1:
          # Boundary is made of points
          row,col=np.where(self.domainEls[:,:2]==boundEls[j,0])
          if row.size == 1:
            if col[0]==0:
              self.normalx[int(boundEls[j,0]-1),0]=-1.0
            else:
              self.normalx[int(boundEls[j,0]-1),0]=1.0
            # end if

        elif self.ndim==2:
          # Boundary is made of lines
          
          tangx = nodesx[int(boundEls[j,1]-1)]-nodesx[int(boundEls[j,0]-1)]
          tangy = nodesy[int(boundEls[j,1]-1)]-nodesy[int(boundEls[j,0]-1)]
          normtang = np.sqrt(tangx**2+tangy**2)

          normx = tangy/normtang
          normy = -tangx/normtang

          for k in range( int( boundEls.shape[1]-1 ) ):

            self.normalx[int(boundEls[j,k]-1),0]=self.normalx[int(boundEls[j,k]-1),0]+normx
            self.normaly[int(boundEls[j,k]-1),0]=self.normaly[int(boundEls[j,k]-1),0]+normy

          # end for


        # elif self.ndim==3:
          # Boundary is made of triangles

        # end if 

      # end for 

    # end for 

    #normalize again:

    if self.ndim>1:

      for i in range( len( self.elemTable[self.ndim-1] ) ):
        
        boundEls = self.elemTable[self.ndim-1][i]
        
        for j in range( boundEls.shape[0] ):
          
          for k in range( int( boundEls.shape[1]-1 ) ):

            normx = self.normalx[int(boundEls[j,k]-1),0]
            normy = self.normaly[int(boundEls[j,k]-1),0]
            normz = self.normalz[int(boundEls[j,k]-1),0]

            nnorm = np.sqrt(normx**2+normy**2+normz**2)

            self.normalx[int(boundEls[j,k]-1),0] = normx/nnorm
            self.normaly[int(boundEls[j,k]-1),0] = normy/nnorm
            self.normalz[int(boundEls[j,k]-1),0] = normz/nnorm

          # end for 
            
        # end for 

      # end for 




  #---------------------------------------------------------------------------------------------------




  #***************************************************************************************************
  def getBoundNormals(self,list boundIds):


    normalx = np.zeros(self.xcoords.shape,dtype = np.double)
    normaly = np.zeros(self.xcoords.shape,dtype = np.double)
    normalz = np.zeros(self.xcoords.shape,dtype = np.double)

    nodesx = self.xcoords.real
    nodesy = self.ycoords.real
    nodesz = self.zcoords.real

    cdef int64_t i, j, k
    cdef np.ndarray boundEls
    for i in range( len( boundIds ) ):
      
      if type(boundIds[i]) == str:
        bId = self.nameIds[boundIds[i]]
      else:
        bId = boundIds[i]
      # end if 
      bIndx = self.elsIds[self.ndim-1].index(bId)
      boundEls = self.elemTable[self.ndim-1][bIndx]
      
      for j in range( boundEls.shape[0] ):
        
        if self.ndim==1:
          # Boundary is made of points
          row,col=np.where(self.domainEls[:,:2]==boundEls[j,0])
          if row.size == 1:
            if col[0]==0:
              normalx[int(boundEls[j,0]-1),0]=-1.0
            else:
              normalx[int(boundEls[j,0]-1),0]=1.0
            # end if

        elif self.ndim==2:
          # Boundary is made of lines
          
          tangx = nodesx[int(boundEls[j,1]-1)]-nodesx[int(boundEls[j,0]-1)]
          tangy = nodesy[int(boundEls[j,1]-1)]-nodesy[int(boundEls[j,0]-1)]
          normtang = np.sqrt(tangx**2+tangy**2)

          normx = tangy/normtang
          normy = -tangx/normtang

          for k in range( int( boundEls.shape[1]-1 ) ):

            normalx[int(boundEls[j,k]-1),0]=normalx[int(boundEls[j,k]-1),0]+normx
            normaly[int(boundEls[j,k]-1),0]=normaly[int(boundEls[j,k]-1),0]+normy

          # end for


        # elif self.ndim==3:
          # Boundary is made of triangles

        # end if 

      # end for 

    # end for 

    #normalize again:

    if self.ndim>1:

      for i in range( len( boundIds ) ):
        
        if type(boundIds[i]) == str:
          bId = self.nameIds[boundIds[i]]
        else:
          bId = boundIds[i]
        # end if 
        
        bIndx = self.elsIds[self.ndim-1].index(bId)
        boundEls = self.elemTable[self.ndim-1][bIndx]

        for j in range( boundEls.shape[0] ):
          
          for k in range( int( boundEls.shape[1]-1 ) ):

            normx = normalx[int(boundEls[j,k]-1),0]
            normy = normaly[int(boundEls[j,k]-1),0]
            normz = normalz[int(boundEls[j,k]-1),0]

            nnorm = np.sqrt(normx**2+normy**2+normz**2)

            normalx[int(boundEls[j,k]-1),0] = normx/nnorm
            normaly[int(boundEls[j,k]-1),0] = normy/nnorm
            normalz[int(boundEls[j,k]-1),0] = normz/nnorm

          # end for 
            
        # end for 

      # end for 
    # end if 

    return (normalx,normaly,normalz)

  #---------------------------------------------------------------------------------------------------



  #***************************************************************************************************
  def exportToVTK(self,filename,list pd=[],list pdNames=[]):
    """
    PURPOSE: Export mesh and solution functions to vtk format.

    """

    f = open(filename, "w")

    f.write("# vtk DataFile Version 4.1\n")# Header
    f.write("Exported OTI solution\n")# Header
    f.write("ASCII\n")# Header

    f.write("DATASET UNSTRUCTURED_GRID\n")

    #First add the point data 
    cdef np.ndarray nodesx = self.xcoords.real
    cdef np.ndarray nodesy = self.ycoords.real
    cdef np.ndarray nodesz = self.zcoords.real
    cdef uint64_t nnodes, nels, elDof
    cdef list humDir
    
    elDof = self.getBaseDOFs()
    nnodes = np.max( self.domainEls[:,:elDof] )


    f.write("POINTS "+str(nnodes)+" double\n")

    cdef uint64_t i, i0=0,j,k
    for i in range(nnodes):
      f.write(str(nodesx[i,i0])+" "+str(nodesy[i,i0])+" "+str(nodesz[i,i0])+"\n")
    # end for 

    # add the elements
    nels = self.domainEls.shape[0]

    f.write("CELLS "+str(nels)+" "+str(nels*( int( elDof+1 ) ) )+" \n")
    for i in range(nels):
      f.write(str(elDof)+" ")
      for j in range(elDof):
        f.write(str( int( self.domainEls[i,j] - 1 ) )+" ")
      #end for 
      f.write("\n")
    # end for 

    cdef uint64_t cellVtkType = self.getDomainVtkCellId(elDof)
    cdef uint64_t ndata, nImDir
    f.write("CELL_TYPES "+str(nels)+" \n")
    for i in range(nels):
      f.write(str(cellVtkType)+"\n")
    # end for 

    if len(pd)!=0:
      if len(pdNames)!=len(pd):
        f.close()
        raise ValueError("pd and pdNames must match one to one.")
      # end if 

      f.write("POINT_DATA "+str(nnodes)+"\n")

      for j in range(len(pd)):
        if type(pd[j]) == list:
          # vector data
          
          flist = pd[j]
          ndata = len(flist)
          nImDir = flist[i0].data.Ndir
          order  = flist[i0].data.order
          
          for ndir in range(nImDir):       
            e_dir = getLatexDir(ndir,order)
            # end if 
            f.write("VECTORS "+pdNames[j]+'-'+e_dir+" double\n")
            for i in range(nnodes):
              for k in range(ndata):
                
                f.write(str(flist[k].data.data[i,ndir])+" ")

              # end for 
              for k in range(ndata,3):
                f.write("0 ")
              # end for 
              f.write("\n")
            # end for 
          # end for 
        else:
          # point data
          f.write("")
          nImDir= pd[j].data.Ndir
          order = pd[j].data.order
          # f.write("SCALARS "+pdNames[j]+" double "+str(j)+"\n")
          for ndir in range(nImDir):
            e_dir = getLatexDir(ndir,order)
            f.write("SCALARS "+pdNames[j]+'-'+e_dir+" double\n")
            f.write("LOOKUP_TABLE default\n")
            for i in range(nnodes):
              
              f.write(str(pd[j].data.data[i,ndir])+" ")
              
              f.write("\n")
            # end for 
          # end for

        # end if 

      # end for 

    # end if 






    f.close()

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  cdef uint64_t getBaseDOFs(self):
    """
    PURPOSE: get the basic order 1 domain DOFs according to the element type.
    """
    cdef uint64_t res = 0
    if self.domainType == elLine:
      
      res = 2
      
    elif self.domainType == elTriangle:
      
      res = 3
      
    elif self.domainType == elQuadrangle:
    
      res = 4
    
    elif self.domainType == elTetrahedra:
      
      res = 4
    
    elif self.domainType == elHexahedra:
      
      res = 8
      
    # end if

    return res
  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  cdef uint64_t getDomainVtkCellId(self, dofs):
    """
    PURPOSE: get the equivalent vtk number id of the element type.
    """
    cdef uint64_t res = 0
    if self.domainType == elLine:
      if dofs==2:
        res = 3
      elif dofs==3:
        res = 21
      # end if 
    elif self.domainType == elTriangle:
      if dofs==3:
        res = 5
      elif dofs==6:
        res = 22
      # end if 
    elif self.domainType == elQuadrangle:
      if dofs==4:
        res = 9
      elif dofs==8:
        res = 23
      # end if 
    elif self.domainType == elTetrahedra:
      if dofs==4:
        res = 10
      elif dofs==10:
        res = 24
      # end if 
    elif self.domainType == elHexahedra:
      if dofs==8:
        res = 3
      elif dofs==20:
        res = 25
      # end if 
    # end if
    return res
  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  cpdef uint64_t getGlobalDOFBound(self,int64_t ndim, fespace2 space):
    """
    PURPOSE: get the total number of degrees of freedom of a mesh according to the interpolation
             functions.

    """


    cdef int64_t i,  nodei
    cdef uint64_t j, elemDOF
    cdef uint64_t gloabalDOF
    cdef list nodes = []


    # Get the DOF for the specifyed boundary.
    if space not in self.fespaces:
      raise ValueError("Finite Element space must belong to the mesh.")
    # end if 

    # Check first if the number of dimensions is valid.
    if ndim > space.elType.ndim:
    
      raise ValueError("The maximum dimension of the mesh is: ",space.elType.ndim )

    elif ndim == space.elType.ndim:

      return self.getGlobalDOF(space)

    # end if 

    elemDOF = space.elType.boundEls[ndim].nbasis

    if elemDOF > self.domainElDofs:
      raise ValueError("Mesh is not prepared for the number of D.O.Fs. of Finite Element Space")
    # end if 
    
    all_elements = np.array([])

    for i in range(len(space.mesh.elemTable[ndim])):
      LocalBoundEls = np.unique(space.mesh.elemTable[ndim][i][:,:elemDOF])
      all_elements = np.append(all_elements,LocalBoundEls)
    # end for 

    return len(np.unique(all_elements))
  #---------------------------------------------------------------------------------------------------


  #***************************************************************************************************
  cpdef uint64_t getGlobalDOF(self,fespace2 space):
    """
    PURPOSE: get the total number of degrees of freedom of a mesh according to the interpolation
             functions.

    """


    cdef int64_t i,  nodei
    cdef uint64_t j, elemDOF 
    cdef uint64_t gloabalDOF
    cdef list nodes = []
    
    if space not in self.fespaces:

      raise ValueError("Finite Element space must belong to the mesh.")

    # end if 

    elemDOF = space.elType.nbasis

    if elemDOF > self.domainElDofs:

      raise ValueError("Mesh is not prepared for the number of D.O.Fs. of Finite Element Space")

    # end if 

    if elemDOF == self.domainElDofs:
    
      gloabalDOF =  self.xcoords.shape[0]
    
    else:

      # for i in range(self.domainEls.shape[0]):

      #   for j in range(elemDOF):

      #     nodei = self.domainEls[i,j]

      #     if nodei not in nodes:

      #       nodes.append(nodei)

      #     # end if 

      #   # end for

      # # end for

      gloabalDOF = np.max(self.domainEls[:,:elemDOF])  # this because it comes already ordered.

    # end if 

    return gloabalDOF
  #---------------------------------------------------------------------------------------------------



  #***************************************************************************************************
  def readFromGMSH(self,filename):
    """
    PURPOSE:   Read a mesh from a GMSH file.
    """
    
    # cdef list keywords = ['MeshFormat',         
    #                       'PhysicalNames',      
    #                       'Nodes',              
    #                       'Elements',           
    #                       'Periodic',           
    #                       'NodeData',           
    #                       'ElementData',        
    #                       'ElementNodeData',    
    #                       'InterpolationScheme']

    # f = open(filename, 'r')

    # for line in f:
    #   if line[0] == '$':
    #     print("found one keyword: ", line)
    #   # end if 
    # # end for

    cdef int64_t i,nodeIdx,eIdx

    f = open(filename, 'r')
    #read the headings
    f.readline().split()   # $MeshFormat
    f.readline().split()   # version-number file-type data-size
    f.readline().split()   # $EndMeshFormat 

    nels_per_dimension = np.zeros(4,dtype = np.uint64)
    maxElType = 0

    for line in  f  :

      #------------------------------ $Nodes
      if line.find("$Nodes") != -1:

        values = f.readline().split()
        print("Detecting number of nodes: ", values)
        nnodes = int(values[0])
        nodes =np.zeros(shape=(nnodes,3))

        for i in range(nnodes):
          values = f.readline().split()
          nodeIdx = int(values[0])
          nodes[nodeIdx-1][0]=float(values[1])     #convert the index to start from zero
          nodes[nodeIdx-1][1]=float(values[2])
          nodes[nodeIdx-1][2]=float(values[3])
        # end for

        f.readline()# $EndNodes

      # end if

      #-----------------------------  $PhysicalNames
      if line.find("$PhysicalNames") != -1:
        # number of physical groups
        values  = f.readline().split()
        npg_names = int(values[0])
        pg_names  = {}
        # Physical dimensions
        physDim   = np.zeros(npg_names,dtype = np.uint8)
        for i in range(npg_names):

          values = f.readline().split()

          name = values[2].split("\"")[1] 
          pg_names[name]=int(values[1])
          physDim[i]

        # end for

        f.readline() # $EndPhysicalNames

      # end if 

      #-----------------------------  $Elements
      if line.find("$Elements") != -1:

        nlines  = 0
        nlines2 = 0
        nquads  = 0
        ntria   = 0
        ntria2  = 0
        npoints = 0
        nquads2 = 0
        
        values = f.readline().split()
        nelems = int(values[0])
        # Quatratic second order (8 nodes)
        element = np.zeros(shape=(nelems,9),dtype=np.int)
        # Triangle second order (6 nodes)
        # element = np.zeros(shape=(nelems,7),dtype=np.int)
        
        elementType =np.zeros(shape=(nelems),dtype=np.int)
        pg = np.zeros(shape=(nelems),dtype=np.int)
        
        for i in range(nelems):

          values = f.readline().split()
          eIdx = int(values[0])-1            #convert the index to start from zero
          eType = int(values[1])

          if eType > maxElType:
            maxElType = eType
          # end if 

          ntags = int(values[2])
          elementType[eIdx]=eType

          if ntags>0 :
            pg[eIdx] = int(values[3])      # physical Group
          
          if eType == 1:         #  Lines
            element[eIdx][0]= int(values[3+ntags]) 
            element[eIdx][1]= int(values[3+ntags +1]) 
            nlines +=1
            nels_per_dimension[1]+=1

          elif eType == 2:         #  Triangles
            element[eIdx][0]= int(values[3+ntags]) 
            element[eIdx][1]= int(values[3+ntags +1]) 
            element[eIdx][2]= int(values[3+ntags +2] ) 
            ntria  +=1
            nels_per_dimension[2]+=1

          elif eType == 8:         #  3 node lines
            element[eIdx][0]= int(values[3+ntags]) 
            element[eIdx][1]= int(values[3+ntags +1]) 
            element[eIdx][2]= int(values[3+ntags +2] ) 
            nlines2  +=1
            nels_per_dimension[1]+=1
          
          elif eType == 3:         #  quadrangle
            element[eIdx][0]= int(values[3+ntags]) 
            element[eIdx][1]= int(values[3+ntags +1]) 
            element[eIdx][2]= int(values[3+ntags +2] ) 
            element[eIdx][3]= int(values[3+ntags +3] ) 
            nquads  +=1
            nels_per_dimension[2]+=1

          elif eType == 9:         #  second order Triangles

            element[eIdx][0]= int(values[3+ntags]) 
            element[eIdx][1]= int(values[3+ntags +1]) 
            element[eIdx][2]= int(values[3+ntags +2] ) 
            element[eIdx][3]= int(values[3+ntags +3] ) 
            element[eIdx][4]= int(values[3+ntags +4] ) 
            element[eIdx][5]= int(values[3+ntags +5] ) 
            ntria2  +=1
            nels_per_dimension[2]+=1

          elif eType == 15:         #  Point
            element[eIdx][0]= int(values[3+ntags]) 
            npoints +=1
            nels_per_dimension[0]+=1

          elif eType == 16:         #  second order Quads - Serendipity
            element[eIdx][0]= int(values[3+ntags])     
            element[eIdx][1]= int(values[3+ntags +1])  
            element[eIdx][2]= int(values[3+ntags +2] ) 
            element[eIdx][3]= int(values[3+ntags +3] ) 
            element[eIdx][4]= int(values[3+ntags +4] ) 
            element[eIdx][5]= int(values[3+ntags +5] ) 
            element[eIdx][6]= int(values[3+ntags +6] ) 
            element[eIdx][7]= int(values[3+ntags +7] ) 
            nquads2  +=1
            nels_per_dimension[2]+=1

          else:

            raise ValueError("Element type :"+str(eType)+" is not yet supported. ")

          # end if 

        # end for

      # end if 

    # end for 

    f.close()

    print("Read nodes")

    print("Read elements")
    print(element)
    print(element[element.shape[0]-1])


    
    # print('Number of nodes per dimension: ',nels_per_dimension)

    # determine the dimension of the problem.
    for i in range(3,-1,-1):
      if nels_per_dimension[i]!=0:
        maxdim = i
        break
      # end if 
    # end if

    self.ndim = maxdim

    # Determine the basic geometry of the domain
    eType = elementType[ elementType.shape[0] - 1 ]

    if   eType == 1 or eType == 8 : #  Lines

      self.baseGeomType = elLine

    elif eType == 2 or eType == 9 : #  Triangles

      self.baseGeomType = elTriangle

    elif eType == 3 or eType == 16: #  quadrangle

      self.baseGeomType = elQuadrangle

    else:

      self.baseGeomType = -1

    # end if 


    # print("Max element type: ", maxElType)


    # print("Max dimension: ", maxdim)


    self.nameIds = pg_names


    lines     = np.zeros(shape=(nlines, 3),dtype=np.uint64) # 2 points +pg
    lines2    = np.zeros(shape=(nlines2,4),dtype=np.uint64) # 3 points +pg
    triangle  = np.zeros(shape=(ntria,  4),dtype=np.uint64) # 3 points +pg
    triangle2 = np.zeros(shape=(ntria2, 7),dtype=np.uint64) # 6 points +pg
    points    = np.zeros(shape=(npoints,2),dtype=np.uint64) # 1 points +pg
    quads     = np.zeros(shape=(nquads, 5),dtype=np.uint64) # 4 points +pg
    quads2    = np.zeros(shape=(nquads2,9),dtype=np.uint64) # 8 points +pg


    j   = 0
    jl2 = 0
    jt  = 0
    jt2 = 0
    jq  = 0
    jq2 = 0
    jp  = 0

    # print("Element Types:")
    # print(elementType)

    start_j    = 0
    start_jl2  = 0
    start_jt   = 0
    start_jt2  = 0
    start_jq   = 0
    start_jq2  = 0
    start_jp   = 0

    end_j      = 0
    end_jl2    = 0
    end_jt     = 0
    end_jt2    = 0
    end_jq     = 0
    end_jq2    = 0
    end_jp     = 0

    pg_j    = 0
    pg_jl2  = 0
    pg_jt   = 0
    pg_jt2  = 0
    pg_jq   = 0
    pg_jq2  = 0
    pg_jp   = 0

    self.elsIds    = [[],[],[],[]]
    self.elemTable = [[],[],[],[]]



    for i in range(nelems):

      if elementType[i] == 1:

        lines[j][0]=element[i][0]
        lines[j][1]=element[i][1]
        lines[j][2]=pg[i]
        
        
        if j!=0 and pg[i] != pg_j:
          
          end_j = j
          self.elemTable[1].append(lines[start_j:end_j,:])
          self.elsIds[1].append(pg_j)
          start_j = end_j
          pg_j = pg[i]
        
        else:
        
          pg_j = pg[i]
        
        # end if 

        j += 1

      elif elementType[i] == 2:

        triangle[jt][0]=element[i][0]
        triangle[jt][1]=element[i][1]
        triangle[jt][2]=element[i][2]
        triangle[jt][3]=pg[i]

        if jt!=0 and pg[i] != pg_jt:
          
          end_jt = jt
          self.elemTable[2].append(triangle[start_jt:end_jt,:])
          self.elsIds[2].append(pg_jt)
          start_jt = end_jt
          pg_jt = pg[i]
        
        else:
        
          pg_jt = pg[i]
        
        # end if 

        jt +=1

      elif elementType[i] == 3:
      
        quads[jq][0]=element[i][0]
        quads[jq][1]=element[i][1]
        quads[jq][2]=element[i][2]
        quads[jq][3]=element[i][3]
        quads[jq][4]=pg[i]

        if jq!=0 and pg[i] != pg_jq:
          
          end_jq = jq
          self.elemTable[2].append(quads[start_jq:end_jq,:])
          self.elsIds[2].append(pg_jq)
          start_jq = end_jq
          pg_jq = pg[i]
        
        else:
        
          pg_jq = pg[i]
        
        # end if 

        jq +=1
      
      elif elementType[i] == 8:

        lines2[jl2][0]=element[i][0]
        lines2[jl2][1]=element[i][1]
        lines2[jl2][2]=element[i][2]
        lines2[jl2][3]=pg[i]

        if jl2!=0 and pg[i] != pg_jl2:
          
          end_jl2 = jl2
          self.elemTable[1].append(lines2[start_jl2:end_jl2,:])
          self.elsIds[1].append(pg_jl2)
          start_jl2 = end_jl2
          pg_jl2 = pg[i]
        
        else:
        
          pg_jl2 = pg[i]
        
        # end if 

        jl2 +=1
      
      
      elif elementType[i] == 9:

        triangle2[jt2][0]=element[i][0]
        triangle2[jt2][1]=element[i][1]
        triangle2[jt2][2]=element[i][2]
        triangle2[jt2][3]=element[i][3]
        triangle2[jt2][4]=element[i][4]
        triangle2[jt2][5]=element[i][5]
        triangle2[jt2][6]=pg[i]

        if jt2!=0 and pg[i] != pg_jt2:
          
          end_jt2 = jt2
          self.elemTable[2].append(triangle2[start_jt2:end_jt2,:])
          self.elsIds[2].append(pg_jt2)
          start_jt2 = end_jt2
          pg_jt2 = pg[i]
        
        else:
        
          pg_jt2 = pg[i]
        
        # end if 

        jt2 +=1

      elif elementType[i] == 16:
      
        quads2[jq2][0]=element[i][0]
        quads2[jq2][1]=element[i][1]
        quads2[jq2][2]=element[i][2]
        quads2[jq2][3]=element[i][3]
        quads2[jq2][4]=element[i][4]
        quads2[jq2][5]=element[i][5]
        quads2[jq2][6]=element[i][6]
        quads2[jq2][7]=element[i][7]
        quads2[jq2][8]=pg[i]

        if jq2!=0 and pg[i] != pg_jq2:
          
          end_jq2 = jq2
          self.elemTable[2].append(quads2[start_jq2:end_jq2,:])
          self.elsIds[2].append(pg_jq2)
          start_jq2 = end_jq2
          pg_jq2 = pg[i]
        
        else:
        
          pg_jq2 = pg[i]
        
        # end if 

        jq2 +=1

      elif elementType[i] == 15:
        points[jp][0]= element[i][0]
        points[jp][1]= pg[i]
        if jp!=0 and pg[i] != pg_jp:
          
          end_jp = jp
          self.elemTable[0].append(points[start_jp:end_jp,:])
          self.elsIds[0].append(pg_jp)
          start_jp = end_jp
          pg_jp = pg[i]
        
        else:
        
          pg_jp = pg[i]
        
        # end if 

        jp +=1
    
      # end if 

    # end for 

    
    if j!=0:
          
      end_j = j
      self.elemTable[1].append(lines[start_j:end_j,:])
      self.elsIds[1].append(pg_j)

    # end if 

    if jt!=0:
          
      end_jt = jt
      self.elemTable[2].append(triangle[start_jt:end_jt,:])
      self.elsIds[2].append(pg_jt)

    # end if 

    if jq!=0:
          
      end_jq = jq
      self.elemTable[2].append(quads[start_jq:end_jq,:])
      self.elsIds[2].append(pg_jq)

    # end if 

    if jl2!=0:
          
      end_jl2 = jl2
      self.elemTable[1].append(lines2[start_jl2:end_jl2,:])
      self.elsIds[1].append(pg_jl2)

    # end if 

    if jt2!=0:
          
      end_jt2 = jt2
      self.elemTable[2].append(triangle2[start_jt2:end_jt2,:])
      self.elsIds[2].append(pg_jt2)

    # end if 

    if jq2!=0 :
          
      end_jq2 = jq2
      self.elemTable[2].append(quads2[start_jq2:end_jq2,:])
      self.elsIds[2].append(pg_jq2)

    # end if 


    if jp!=0 :
          
      end_jp = jp
      self.elemTable[0].append(points[start_jp:end_jp,:])
      self.elsIds[0].append(pg_jp)

    # end if 

    # print("points: ")
    # print(points)

    # print()
    # print("lines P1: ")
    # print(lines)

    # print()
    # print("lines P2: ")
    # print(lines2)

    # print()
    # print("triang P1: ")
    # print(triangle)

    # print()
    # print("triang P2: ")
    # print(triangle2)

    # print()
    # print("Quad P1: ")
    # print(quads)

    # print()
    # print("Quad P2: ")
    # print(quads2)

    
    self.boundaEls = []

    
    self.boundaType = []


    if npoints>0:
      # self.elemTable[0].append(points)
      self.boundaEls.append(points)
      self.boundaType.append(elNode)
    # end if

    if nlines>0:
      # self.elemTable[1].append(lines)
      if self.ndim>1:
        self.boundaEls.append(lines)
        self.boundaType.append(elLine)
      else:
        self.domainEls=lines
        self.domainType = elLine
        self.domainElDofs = 2
      # end if 
    # end if

    if nlines2>0:
      # self.elemTable[1].append(lines2)
      if self.ndim>1:
        self.boundaEls.append(lines2)
        self.boundaType.append(elLine)
      else:
        self.domainEls=lines2
        self.domainType = elLine
        self.domainElDofs=3
      # end if   
    # end if

    if ntria>0:
      # self.elemTable[2].append(triangle)
      if self.ndim>2:
        self.boundaEls.append(triangle)
        self.boundaType.append(elTriangle)
      else:
        self.domainEls=triangle
        self.domainType = elTriangle
        self.domainElDofs=3
      # end if 
    # end if

    if ntria2>0:
      # self.elemTable[2].append(triangle2)
      if self.ndim>2:
        self.boundaEls.append(triangle2)
        self.boundaType.append(elTriangle)
      else:
        self.domainEls=triangle2
        self.domainType = elTriangle
        self.domainElDofs=6
      # end if 
    # end if

    if nquads>0:
      # self.elemTable[2].append(quads)
      if self.ndim>2:
        self.boundaEls.append(quads)
        self.boundaType.append(elQuadrangle)
      else:
        self.domainEls=quads
        self.domainType = elQuadrangle
        self.domainElDofs=4
      # end if 
    # end if

    if nquads2>0:
      # self.elemTable[2].append(quads2)
      if self.ndim>2:
        self.boundaEls.append(quads2)
        self.boundaType.append(elQuadrangle)
      else:
        self.domainEls=quads2
        self.domainType = elQuadrangle
        self.domainElDofs=8
      # end if 
    # end if







    if nquads2>0:


      # Reorder for quads order 2.

      # reorder elements 
      order1 = np.unique(self.domainElements[:,0:4])
      order2 = np.unique(self.domainElements[:,4:8])


      new2old = np.append(order1,order2)
      old2new = np.empty_like(new2old)
      nodesNew = np.empty_like(nodes)
      for i in range(len(new2old)):
        old2new[int(new2old[i]-1)]=int(i+1)
        nodesNew[i] = nodes[int(new2old[i]-1)]
      # end for 
      nodes=nodesNew

      print("new2old: ")

      print(new2old)

      print("\nold2new: ")
      print(old2new)

      for i in range(len(self.elemTable)):
        for j in range(len(self.elemTable[i])):
          for k in range(len(self.elemTable[i][j])):
            for l in range(len(self.elemTable[i][j][k])-1):
              self.elemTable[i][j][k][l] = old2new[int(self.elemTable[i][j][k][l]-1)]
            # end for 
          # end for 
        # end for 
      # end for 

    elif ntria2>0:

      # reorder elements 
      order1 = np.unique(self.domainElements[:,0:3])
      order2 = np.unique(self.domainElements[:,3:6])


      new2old = np.append(order1,order2)
      old2new = np.empty_like(new2old)
      nodesNew = np.empty_like(nodes)
      for i in range(len(new2old)):
        old2new[int(new2old[i]-1)]=int(i+1)
        nodesNew[i] = nodes[int(new2old[i]-1)]
      # end for 
      nodes=nodesNew

      print("new2old: ")

      print(new2old)

      print("\nold2new: ")
      print(old2new)

      for i in range(len(self.elemTable)):
        for j in range(len(self.elemTable[i])):
          for k in range(len(self.elemTable[i][j])):
            for l in range(len(self.elemTable[i][j][k])-1):
              self.elemTable[i][j][k][l] = old2new[int(self.elemTable[i][j][k][l]-1)]
            # end for 
          # end for 
        # end for 
      # end for 

    # end if
      








    self.xcoords = sarray( nodes[:,[0]], order = self.otiorder)
    self.ycoords = sarray( nodes[:,[1]], order = self.otiorder)
    self.zcoords = sarray( nodes[:,[2]], order = self.otiorder)

    # self.domainElements = 

    # return (nodes,element,elementType,pg_names)
  #---------------------------------------------------------------------------------------------------
    

  #***************************************************************************************************      
  def __repr__(self):
    
    cdef str out = ''
    cdef int64_t i
    

    out = "<OTI mesh with "
    out += str(self.xcoords.shape[0])+" nodes, "
    out += str(self.domainEls.shape[0])+ " " + elTypeNames[self.domainType-elNode]+"s, "
    for i in range(len(self.boundaEls)):
      out+= str(self.boundaEls[i].shape[0])+" "+elTypeNames[self.boundaType[i]-elNode]+"s, "

    out += ">"

    return out
  #---------------------------------------------------------------------------------------------------


  #***************************************************************************************************
  def __str__(self):
    
    cdef str out = ''

    out += "< OTI mesh with "
    out += str(self.nodes.shape[0])
    out += " nodes and "

    for key in self.cells.keys():
      
      out += str(self.cells[key].shape[0])
      out += " "
      out += key + 's and '

    # end for
    
    out = out[:-4] + '>'

    return out
  #---------------------------------------------------------------------------------------------------


  #***************************************************************************************************
  cdef uint64_t addNewOperation(self):
    """
    PURPOSE:  maintain global ids for operations.

    """

    self.operationCount += 1

    return self.operationCount
  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  cdef uint64_t addNewSpace(self,fespace2 space):
    """
    PURPOSE:      creates a new Finite Element space and adds a new element to the stack list of 
                  spaces that defines the interpolation of elements in the mesh.

                  This function also redefines the node interpolation.

    """
    cdef uint64_t i
    
    self.fespaces.append(space)
    
    self.elTypes.append(space.elType)

    i = len(self.elTypes)

    if self.xyzInit == 0:

      # To preserve dimensions, use integer array slicing: coords[:,[i]]
      # --> Using coords[:, i ] removes one dimension.
      self.x = space.newFunction( self.xcoords )
      self.y = space.newFunction( self.ycoords )
      self.z = space.newFunction( self.zcoords )

      self.xyzInit = 1

    # end if 
      
    return i-1
  #---------------------------------------------------------------------------------------------------



# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# :::::::::::::::::::::::::::::::::::: END OF CLASS OTIMESH ::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

  

  






