




#-----------------------------------------------------------------------------------------------------






# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# :::::::::::::::::::::::::::::::::     CLASS  FEPROBLEM    ::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
cdef class feproblem:

  #---------------------------------------------------------------------------------------------------
  #------------------------------------   DEFINITION OF ATTRIBUTES   ---------------------------------
  #---------------------------------------------------------------------------------------------------
  
  # Global variables:
  cdef public otimat   K     # Stiffness Matrix
  cdef public otimat   Knobc # Stiffness Matrix before boundary conditions.
  cdef public ndarray  f     # Force vector
  cdef public ndarray  fnobc # Force vector before Boundary Conditions.
  cdef public ndarray  u     # General Solution Vector.
  cdef public mesh     mesh

  # Only for usable for the 
  cdef void** defFunc           # Constant holders for the assembly loop.  
  

  cdef public uint64_t intorder
  cdef np.ndarray      derCompFlags

  # Operations associated with K
  cdef public list Koper

  # Operations associated with f
  cdef public list Foper

  # Other important things
  cdef public list      solFunc 
  cdef public list     testFunc 
  cdef public list     undefFuncToCheck  # Undefined functions that require to be checked before 
                                         # assembly.
  cdef public uint8_t DOF   # Degrees of Freedom.

  cdef public fefunction problem

  # Flagging convention
  cdef public uint64_t flags 

  cdef public uint64_t m      # Number of variables in the problem 
    # Conventions:
    # Bit  0 - Is the system assembled? True - 1  False - 0
    # Bit  1 - 
    # Bit  2 - 
    # Bit  3 - 
    # Bit  4 - 
    # Bit  5 - 
    # Bit  6 - 
    # Bit  7 - 
    # Bit  8 - 
    # Bit  9 - 
    # Bit 10 - 

  cdef public uint64_t eDOF              # Elemental degrees of freedom
  cdef public list     eDOFBound
  cdef np.ndarray      eDOF_per_sol      # Elemental degrees of freedom per element.
  cdef public list     eDOF_per_solBound # Elemental degrees of freedom per element Boundary.
  cdef np.ndarray      nDOF_per_sol      # Global degrees of freedom per element.
  cdef public list     nDOF_per_solBound
  cdef public uint64_t globalDOF
  cdef public list     globalDOFBound
  cdef np.ndarray      nDOF_global_per_systemDOF
  cdef public list     nDOF_global_per_systemDOFBound  
  cdef np.ndarray      eOffset_per_StateVariable
  cdef public list     eOffset_per_StateVariableBound
  cdef np.ndarray      eId_per_DOF
  cdef public list     eId_per_DOFBound
  cdef uint8_t     boundaryFlag
  

  cdef public list       functionList 
  cdef np.ndarray  expandedOperations
  cdef public uint64_t  tmp_indx # defines the number of temporal elements in the operations.
  cdef public uint64_t  noper
  cdef public uint64_t  noperK
  cdef public uint64_t  noperf
  cdef public uint64_t  noperBC
  cdef public uint64_t  noperDirichlet
  cdef public uint64_t  noperNeumann
  cdef public uint64_t  ndeffunc
  cdef public uint64_t nIntPts

  cdef public list defFuncList
  cdef uint64_t    nDefFunc
  cdef uint64_t    nOTIs
  cdef uint64_t    nReals
  cdef public list tmpIndx     # Temporal lists.
  cdef public list tmpIndxFunc # Temporal lists.
  cdef public list tmpIndxPos  # temporal list
  cdef public list tmpTypes
  cdef public list tmpShapesOffsets
  cdef public list integrables
  cdef public list uniqueOper

  cdef public uint8_t order



  cdef np.ndarray      expOperK
  cdef np.ndarray      expOperf
  cdef np.ndarray      expOperBCDir
  cdef np.ndarray      expOperBCNeu
  

  


  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  def __init__(self, list solution, list test, fefunction expr, uint64_t m = 1, uint8_t order = 1):
    """
    PURPOSE:      Constructor of the finite element problem class. Its main purpose is to define 
                  a class to hold the governing variational equation and the boundary conditions.
                  
                  This class holds the solver and the assembler.
    
    """

    cdef uint64_t i, dofSolu_i, dofTest_i
    cdef fefunction funcSolu, funcTest
    cdef elBase elType
    cdef uint64_t globalDOF,k,j
    cdef int64_t ii


    # initialization
    self.undefFuncToCheck = []
    self.Koper = []
    self.Foper = []
    self.solFunc = []
    self.testFunc = []
    self.eDOFBound = []
    self.eDOF_per_solBound = []
    self.nDOF_per_solBound = []
    self.globalDOFBound = []
    self.nDOF_global_per_systemDOFBound = []
    self.eOffset_per_StateVariableBound = []
    self.eId_per_DOFBound = []
    self.functionList = []
    self.defFuncList = []
    self.tmpIndx = []
    self.tmpIndxFunc = []
    self.tmpIndxPos = []
    self.tmpTypes = []
    self.tmpShapesOffsets = []
    self.integrables = []
    self.uniqueOper = []
    self.expandedOperations = np.array([])
    self.expOperK = np.array([])
    self.expOperf = np.array([])
    self.expOperBCDir = np.array([])
    self.expOperBCNeu = np.array([])
    self.derCompFlags = np.array([])
    self.eDOF_per_sol = np.array([])
    self.nDOF_per_sol = np.array([])
    self.nDOF_global_per_systemDOF = np.array([])
    self.eOffset_per_StateVariable = np.array([])
    self.eId_per_DOF = np.array([])



    self.DOF = len(test) # Number of solution variables sets the total degrees of freedom 
                         # of the problem
      
    if len(solution)!= self.DOF:
      raise ValueError("Incorrect input functions. "+
                       "Test and solution functions must match one to one.")
    # end if 

    self.solFunc  = solution.copy()
    self.testFunc = test.copy()
    self.flags = 0 # nothing has been done.
    

    self.problem = expr
    self.problem.reorderBoundOpers() # Reorder boundary operations: First on then int2d.
    self.intorder = self.problem.intorder

    # have a closer reference to the mesh
    self.mesh = self.problem.baseSpace.mesh
    self.m = m

    # # Check input 
    # self.checkInput()
    
    self.eDOF = 0
    self.eDOF_per_sol = np.empty(self.DOF+1,dtype = np.uint64)
    
    i=0
    self.eDOF_per_sol[i] = 0

    self.globalDOF = 0
    self.globalDOFBound = [0,0,0]
    

    self.nDOF_global_per_systemDOF = np.zeros(self.DOF+1,dtype = np.uint64)
    self.nDOF_global_per_systemDOFBound = [[],[],[]]
    self.nDOF_global_per_systemDOFBound[0] = np.zeros(self.DOF+1,dtype = np.uint64)
    self.nDOF_global_per_systemDOFBound[1] = np.zeros(self.DOF+1,dtype = np.uint64)
    self.nDOF_global_per_systemDOFBound[2] = np.zeros(self.DOF+1,dtype = np.uint64)

    self.nDOF_per_sol= np.zeros(self.DOF+1,dtype = np.uint64)
    self.nDOF_per_solBound = [[],[],[]]
    self.nDOF_per_solBound[0] = np.zeros(self.DOF+1,dtype = np.uint64)
    self.nDOF_per_solBound[1] = np.zeros(self.DOF+1,dtype = np.uint64)
    self.nDOF_per_solBound[2] = np.zeros(self.DOF+1,dtype = np.uint64)

    self.eDOF_per_solBound = [[],[],[]]
    self.eDOFBound = [0,0,0]
    self.eDOF_per_solBound[0] = np.zeros(self.DOF+1,dtype = np.uint64)
    self.eDOF_per_solBound[1] = np.zeros(self.DOF+1,dtype = np.uint64)
    self.eDOF_per_solBound[2] = np.zeros(self.DOF+1,dtype = np.uint64)

    for i in range(self.DOF):

      funcSolu = self.solFunc[i]
      funcTest = self.testFunc[i]

      # get the degrees of freedom per function
      dofSolu_i = funcSolu.baseSpace.elType.nbasis
      dofTest_i = funcTest.baseSpace.elType.nbasis

      if dofSolu_i != dofTest_i:
        raise ValueError("Test and solution functions must match one to one its D.O.F.s.")
      # end if 

      
      self.eDOF             += dofSolu_i
      self.eDOF_per_sol[i+1] = self.eDOF

      self.nDOF_global_per_systemDOF[i+1] = self.mesh.getGlobalDOF(self.solFunc[i].baseSpace)

      self.globalDOF += self.nDOF_global_per_systemDOF[i+1]
      self.nDOF_per_sol[i+1] = self.globalDOF

      for ii in range(len(funcSolu.baseSpace.elType.boundEls)):
        
        dofSolu_i = funcSolu.baseSpace.elType.boundEls[ii].nbasis
        
        self.eDOFBound[ii] = int(self.eDOFBound[ii] + dofSolu_i)
        self.eDOF_per_solBound[ii][i+1] = self.eDOFBound[ii]
        self.nDOF_global_per_systemDOFBound[ii][i+1] = self.mesh.getGlobalDOFBound(ii,self.solFunc[i].baseSpace)

        self.globalDOFBound[ii] = int(self.globalDOFBound[ii] + self.nDOF_global_per_systemDOFBound[ii][i+1])
        self.nDOF_per_solBound[ii][i+1] = self.globalDOF

      # end for 


    # End for


    # print("Elemental DOFs: ", self.eDOF)
    # print("Elemental DOFs offset per state variable: ", self.eDOF_per_sol)

    # print("\nElemental DOFs for the boundaries: ", self.eDOFBound)
    # print("Elemental DOFs offset per state variable for the boundaries: ", self.eDOF_per_solBound)


    # print("\nGlobal DOFs : ", self.globalDOF)
    # print("Global DOFs offsets : ", self.nDOF_per_sol)
    # print("Global DOF per system DOF : ", self.nDOF_global_per_systemDOF)
    
    # print("\nGlobal DOFs  for the boundaries: ", self.globalDOFBound)
    # print("Global DOFs offsets  for the boundaries: ", self.nDOF_per_solBound)
    # print("Global DOF per system DOF  for the boundaries: ", self.nDOF_global_per_systemDOFBound)


    
    self.eOffset_per_StateVariable = np.zeros(self.eDOF,dtype = np.uint64)
    self.eOffset_per_StateVariableBound = [[],[],[]]
    self.eOffset_per_StateVariableBound[0] = np.zeros(self.eDOFBound[0],dtype = np.uint64)
    self.eOffset_per_StateVariableBound[1] = np.zeros(self.eDOFBound[1],dtype = np.uint64)
    self.eOffset_per_StateVariableBound[2] = np.zeros(self.eDOFBound[2],dtype = np.uint64)

    self.eId_per_DOF = np.zeros(self.eDOF,dtype = np.uint64)
    self.eId_per_DOFBound = [[],[],[]]
    self.eId_per_DOFBound[0] = np.zeros(self.eDOFBound[0],dtype = np.uint64)
    self.eId_per_DOFBound[1] = np.zeros(self.eDOFBound[1],dtype = np.uint64)
    self.eId_per_DOFBound[2] = np.zeros(self.eDOFBound[2],dtype = np.uint64)

    globalDOF = 0

    globalDOFBound=[0,0,0]
    
    k=0
    kk=[0,0,0]

    for i in range(self.DOF):

      self.eOffset_per_StateVariable[ self.eDOF_per_sol[i] : self.eDOF_per_sol[i+1] ] = globalDOF

      for j in range( np.uint64( self.eDOF_per_sol[i+1] - self.eDOF_per_sol[i] ) ):

        self.eId_per_DOF[k] = j

        k+=1

      # end for      

      for ii in range(3):
        
        if self.eDOFBound[ii]!= 0:

          self.eOffset_per_StateVariableBound[ii][self.eDOF_per_solBound[ii][i]: self.eDOF_per_solBound[ii][i+1] ] = globalDOF #globalDOFBound[ii]

          for j in range(np.uint64(self.eDOF_per_solBound[ii][i+1]-self.eDOF_per_solBound[ii][i])):

            self.eId_per_DOFBound[ii][kk[ii]] = j
            kk[ii]=kk[ii]+1

          # end for

          globalDOFBound[ii] += self.nDOF_global_per_systemDOFBound[ii][i+1]

        # end if

      # end for 

      globalDOF += self.nDOF_global_per_systemDOF[i+1]

    # end for

    




    print("\nNode id corresponding to each element DOF: ",self.eId_per_DOF)
    print("\nNode id corresponding to each element DOF for the boundaries: ",self.eId_per_DOFBound)
    print("\nGlobal offsets per node: ", self.eOffset_per_StateVariable)
    print("\nGlobal offsets per node for the boundaries: ", self.eOffset_per_StateVariableBound)
    


    
    # initialize flags for computation of derivatives. 
    self.derCompFlags = np.zeros(len(self.mesh.elTypes),dtype = np.uint16) # initialize flags for computation of derivatives.


    self.functionList = fem_getOrderedFuncList(self.problem.baseFunc)
    self.expandedOperations =   np.zeros((self.problem.Koper.shape[0]+\
                                          self.problem.foper.shape[0]+\
                                          self.problem.essentialOper.shape[0],15),dtype = np.int64)
    self.tmp_indx     = 0
    self.noper        = 0

    self.defFuncList  = []
    self.tmpShapesOffsets = []

    self.nDefFunc     = 0
    self.nOTIs        = 0
    self.nReals       = 0
    self.ndeffunc     = 0

    self.tmpIndx      = [None]*len(self.functionList)
    self.tmpIndxFunc  = [None]*len(self.functionList)
    self.tmpTypes     = [None]*len(self.functionList)
    self.tmpIndxPos   = [None]*len(self.functionList)

    self.integrables  = []
    self.uniqueOper   = []

    self.boundaryFlag = 0
    
    self.expandOperMatrix(self.problem.Koper)
    self.noperK = self.noper
    # print(self.expandedOperations[0:self.noperK,:])
    

    self.expandOperMatrix(self.problem.foper)
    self.noperf = self.noper
    # print(self.expandedOperations[self.noperK:self.noperf,:])

    self.boundaryFlag = 1

    self.uniqueOper   = []
    self.noperNeumann = self.noperf 
    self.expandOperMatrixBound(self.problem.essentialOper)
    self.noperBC = self.noper
    self.noperDirichlet = self.noper
    # print(self.expandedOperations[self.noperf:self.noperBC])

    self.expandedOperations = self.expandedOperations[:self.noper,:]
    self.uniqueOper   = []
    # print(self.expandedOperations)





  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  @property
  def eDOF_perSolution(self):
    return self.eDOF_per_sol
  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  @property
  def operMat(self):
    return self.expandedOperations
  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  @property
  def derFlags(self):
    return self.derCompFlags
  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  @property
  def nDOF_global_perSystemDOF(self):
    return self.nDOF_global_per_systemDOF
  #---------------------------------------------------------------------------------------------------


  #***************************************************************************************************      
  def __repr__(self):
    
    out  = "< OTI Finite Element problem >"

    return out
  #---------------------------------------------------------------------------------------------------


  #***************************************************************************************************
  def __str__(self):
    
    out  = "< OTI Finite Element problem >"

    return out
  #---------------------------------------------------------------------------------------------------
  
  #***************************************************************************************************
  cpdef solve(self):
    """
    PURPOSE:      To solve the system defined in the problem.
    
    """

    import time
    cdef int64_t i
    cdef double tstr, tend

    # First check that the system is not solved already.
    if ~(self.flags & 1) :
      
      tstr = time.time()
      
      self.assembleSystem()
      
      tend = time.time()

      print("Assembly time: ",tend-tstr," seconds")


      tstr = time.time()

      self.u = solve(self.K,self.f)
      
      tend = time.time()      

      print("Solution time: ",tend-tstr," seconds")


      # Set the variables with the corresponding data.
      for i in range(self.nDOF_global_per_systemDOF.shape[0]-1):
        
        self.solFunc[i].data = zeros(shape=(self.nDOF_global_per_systemDOF[i+1],), m=self.m, maxorder = self.mesh.otiorder)
        self.solFunc[i].data.data[:] = self.u.data[self.nDOF_per_sol[i]:self.nDOF_per_sol[i+1],:]

      # end for 

    # end if 

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  def solveLU(self,**kwargs):
    """
    PURPOSE:      To solve the system defined in the problem.
    
    """

    import time
    cdef int64_t i
    cdef double tstr, tend

    # First check that the system is not solved already.
    if ~(self.flags & 1) :
      
      tstr = time.time()
      
      self.assembleSystem()
      
      tend = time.time()

      print("Assembly time: ",tend-tstr," seconds")


      tstr = time.time()

      self.u = solveLU(self.K,self.f,**kwargs)
      
      tend = time.time()      

      print("Solution time: ",tend-tstr," seconds")


      # Set the variables with the corresponding data.
      for i in range(self.nDOF_global_per_systemDOF.shape[0]-1):
        
        self.solFunc[i].data = zeros(shape=(self.nDOF_global_per_systemDOF[i+1],), m=self.m, maxorder = self.mesh.otiorder)
        self.solFunc[i].data.data[:] = self.u.data[self.nDOF_per_sol[i]:self.nDOF_per_sol[i+1],:]

      # end for 

    # end if 

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  cpdef assembleSystem(self):
    """
    PURPOSE:      To assemble the system in order to prepare for solution.
    
    """

    cdef int64_t       elementIndx,  operIndx, dataKind
    # cdef sotiarray_t*  defFunc 
    cdef sotiarray_t*  tmpDataFunc
    cdef sotinum_t*    tmpDataSotinum
    # cdef double*       tmpDataDouble

    cdef femarray_t*   tmpFE_funcs
    cdef uint64_t      ntmpFE
    cdef elBase        elType, elTypeBoundary
    
    cdef sndarray      sotiArrayDummy  # used to get c-level information.
    cdef sotinum       sotiDummy  # used to get c-level information.
    cdef fefunction    fefuncDummy
    cdef double        doubleDummy

    cdef double        realnum
    cdef elemProps_t** p_elements
    cdef sotinum_t     tmp, emptyNum

    cdef uint16_t      derCompFlag

    cdef femarray_t    jacobian
    cdef femarray_t    invJacobian
    cdef femarray_t    detJacobian

    cdef uint8_t       nDimAnalysis
    cdef uint64_t      nElements, boundaElDofs, globBoundEDofs
    cdef int64_t       operId, derIndx, elemIndx, tmpIndx, tmpIndx1, tmpIndx2, dataIndx
    cdef int64_t       elemRegion, operIntRegion
    cdef int64_t       i0=0, i1=1, i2=2, i3=3, i4=4, i5=5 ,i6=6, i7=7, i8=8, i9=9, i10 = 10 
    cdef int64_t       i11=11, i12=12, i13=13, i14=14, i15=15

    cdef sotiarray_t   Ke, fe  # Elemental stiffness and force arrays.



    global p_dH

    c_soti_createEmpty(&emptyNum,0,self.mesh.otiorder)


    cdef uint64_t ii, jj, kk       # Iteration indices.
    cdef uint64_t nElsMesh
    self.order = self.mesh.otiorder
     
    # print("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++")
    # print("                        Assembling FE problem.                            ")
    # print("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++")

    # 0. Check if the non-solution undefined functions have been solved.

    # 1. Initialization.
    # print(" - 1. Allocating data.")

    # Create an array to hold the element definitions.
    p_elements  = <elemProps_t**> c_malloc_ptr( len(self.mesh.elTypes), sizeof(elemProps_t*))

    # In this array the data is stored.
    self.defFunc = <void**> c_malloc_ptr( self.ndeffunc, sizeof(void*) )

    # print(" - 1.1  Adding constant data to the stack.")
    for ii in range(self.ndeffunc):
      
      fefuncDummy = self.defFuncList[ii] # fefunction 
      dataKind = self.tmpTypes[fefuncDummy.funcid]# type of data
      
      # print("       Setting element ", ii," as ", c_fem_get_enum_string(dataKind) )
      
      if   (dataKind == kindFunc  ):
        
        sotiArrayDummy = fefuncDummy.data
        self.defFunc[ii] = <void*> &sotiArrayDummy.array

      elif (dataKind == kindScalar):

        sotiDummy = fefuncDummy.data
        # print("       data: ", sotiDummy )
        self.defFunc[ii] = <void*> &sotiDummy.num

      # end if

    # end for 


    

    # print(" - 2. Initializing element types.")
    # 1.1 Initialize the Elements (compute number of integration points, its coordinates)
    # This must consider test and solution can be described by different interpolations.
    
    ii=0

    nDimAnalysis = self.mesh.ndim
    nElements    = len(self.mesh.elTypes)

    # print("       * Detected number of elements types in the mesh: ", nElements);

    for elType in self.mesh.elTypes:
      
      elType.initElement(self.intorder,self.mesh.otiorder,nDimAnalysis)
       
      if ii == 0 :
        self.nIntPts = elType.elemProps.nIntPts
      # end if 

      p_elements[ii] = &elType.elemProps
      # print("\n Defined Interpolation type  "+str(ii))
      # print(c_elemprops_print(&elType.elemProps))

      ii += 1
    
    # end for
    # print("\n")
    # print(" - 3. Initializing temporal functions:\n")
    ntmpFE = len(self.tmpShapesOffsets)
    # Allocate temporal holders 
    tmpFE_funcs = <femarray_t*> c_malloc_ptr( ntmpFE, sizeof(femarray_t) )

    for ii in range(ntmpFE):

      shape  = self.tmpShapesOffsets[ii][0]
      offset = self.tmpShapesOffsets[ii][1]
      # print("     * Initializing temporal function ",ii," of shape ", shape, " and offset ", offset)
      c_femarray_zeros(&tmpFE_funcs[ii],shape[0],shape[1],    \
        offset[0],offset[1],self.nIntPts,self.order)

      # print(c_femarray_print(&tmpFE_funcs[ii]))

    # end for

    
    # print(" - 4. Initializing global Stiffness and Force arrays.")
    # # Allocate sizes for global K and for F.
    self.K = otimat((self.globalDOF, self.globalDOF), self.m, self.mesh.otiorder, 2)
    self.f = zeros(shape=(self.globalDOF,), m=self.m, maxorder = self.mesh.otiorder)
    
    # Allocate sizes for elemental K and F.

    # print(" - 5. Allocating Elemental Stiffness matrix: \n")
    c_sotiarray_zeros( &Ke, self.eDOF, self.eDOF, self.mesh.otiorder)
    # print( c_sotiarray_print(&Ke) )
    
    # print(" - 6. Allocating Elemental force vector: \n")
    c_sotiarray_zeros( &fe, self.eDOF,       1  , self.mesh.otiorder)
    # print( c_sotiarray_print(&fe) )
    


    # # Create the holders for the coordinates arrays.

    cdef sotiarray_t* Xcoo_g = NULL # Global coordinates.
    cdef sotiarray_t* Ycoo_g = NULL # Global coordinates.
    cdef sotiarray_t* Zcoo_g = NULL # Global coordinates.

    cdef sotiarray_t xcoo_e # Space for local coordinates.
    cdef sotiarray_t ycoo_e # Space for local coordinates.
    cdef sotiarray_t zcoo_e # Space for local coordinates.
    # cdef sotiarray_t tmp_e  # temporal array

    Xcoo_g = &self.mesh.xcoords.array # get the arrays.
    Ycoo_g = &self.mesh.ycoords.array # get the arrays.
    Zcoo_g = &self.mesh.zcoords.array # get the arrays.

    # Allocate shapes for local coordinate arrays.
    # print(" - 7. Allocating elemental coord arrays for ",self.mesh.domainElDofs," nodes per element:")
    c_sotiarray_zeros( &xcoo_e, self.mesh.domainElDofs, 1, self.mesh.otiorder )
    c_sotiarray_zeros( &ycoo_e, self.mesh.domainElDofs, 1, self.mesh.otiorder )
    c_sotiarray_zeros( &zcoo_e, self.mesh.domainElDofs, 1, self.mesh.otiorder )
    # c_sotiarray_zeros( &tmp_e,  self.mesh.domainElDofs, 1, self.mesh.otiorder )

    

    

    nElsMesh = self.mesh.domainEls.shape[0]

    # # Assembly loop
    # print(" ")
    # print("==============================================================================")
    # print("                      Loop per element in the mesh                            ")
    # print("==============================================================================")

    # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
    # # # # # # # # # # # # # # # # GLOBAL ASSEMBLY LOOP  # # # # # # # # # # # # # # 
    # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
    # Loop for each element
    for ii in range(nElsMesh):

      # Get the element region.
      # print("before reading")
      elemRegion = self.mesh.domainEls[ii,self.mesh.domainElDofs]
      # print(" ")
      # print("  ---------------------------------------------------------------------")
      # print("  >>>> Element ", ii, " in region ", elemRegion, " ", self.mesh.domainEls[ii])
      # print("  ---------------------------------------------------------------------")


      
      
      # print("  Initializing Elemental stiffness matrix.")
      c_sotiarray_setAllItems(&emptyNum,&Ke)
      # print( c_sotiarray_print(&Ke) )

      # print("  Initializing Elemental force vector.")
      c_sotiarray_setAllItems(&emptyNum,&fe)
      # print( c_sotiarray_print(&fe) )


   
      # Get the elemental coordinates
      for jj in range(self.mesh.domainElDofs):

        xcoo_e.p_data[jj] = Xcoo_g[i0].p_data[ int(self.mesh.domainEls[ii,jj]-1) ]
        ycoo_e.p_data[jj] = Ycoo_g[i0].p_data[ int(self.mesh.domainEls[ii,jj]-1) ]
        zcoo_e.p_data[jj] = Zcoo_g[i0].p_data[ int(self.mesh.domainEls[ii,jj]-1) ]

      # end for

      # print("  Got the following coordinates: ")
      # print("    * X: ")
      # print( c_sotiarray_print(&xcoo_e) )
      # print("    * Y: ")
      # print( c_sotiarray_print(&ycoo_e) )
      # print("    * Z: ")
      # print( c_sotiarray_print(&zcoo_e) )

      # print(" ")
      # print("  Initializing the local interpolation data: ")
      for jj in range(nElements):  
        
        derCompFlag = self.derCompFlags[jj]  
        
        if jj==0 and derCompFlag == 0:

          # print("           Initializing information of interpolations ", jj)
          # print("           Computation flags: ", bin(1))   

          c_fem_computeJacobian(p_elements[jj], &xcoo_e, &ycoo_e, &zcoo_e, p_dH)
          # print("Computed Jacobian")
          # print( c_elemprops_print_perElement(p_elements[jj]) )

          c_fem_defineSpatial(  p_elements[jj], 1, p_dH)
          # print("Defined Spatial")
          # print( c_elemprops_print_perElement(p_elements[jj]) )

        elif derCompFlag != 0 : # This must guarantee that the first element is initialized 
          
          # print("           Initializing information of interpolations ", jj)
          # print("           Computation flags: ", bin(derCompFlag))   

          c_fem_computeJacobian(p_elements[jj], &xcoo_e, &ycoo_e, &zcoo_e, p_dH)
          # print("Computed Jacobian")
          # print( c_elemprops_print_perElement(p_elements[jj]) )
          
          c_fem_defineSpatial(  p_elements[jj], derCompFlag, p_dH)
          # print("Defined Spatial")
          # print( c_elemprops_print_perElement(p_elements[jj]) )

        # end if 

      # end for 
      
      
      # print(" \n\n\n\n")
      # print("  ----------------------------------------------------------------------------")
      # print("              Looping for each operation of Stiffness matrix                  ")
      # print("  ----------------------------------------------------------------------------")


      for jj in range(0,self.noperf):    # Defining operations for K.

        operId = self.expandedOperations[jj,i0]

        # print("\n    * Got operation ", c_fem_get_enum_string(operId) )

        if   operId == subOpDefBasis:

          tmpIndx  = self.expandedOperations[jj,i1]
          elemIndx = self.expandedOperations[jj,i6]
          derIndx  = self.expandedOperations[jj,i7]

          # print("Temporal "+ str(tmpIndx)+" array before: ")
          # print(c_femarray_print(&tmpFE_funcs[tmpIndx]))
          c_femarray_fromOther(&p_elements[elemIndx][i0].p_basis[derIndx], &tmpFE_funcs[tmpIndx])

          # print("\n       Defined temporal ",tmpIndx)
          # print(c_femarray_print(&tmpFE_funcs[tmpIndx]))
          # print("\n")
         
        elif operId == subOpDefKnown:

          tmpIndx  = self.expandedOperations[jj,i1]
          elemIndx = self.expandedOperations[jj,i6]
          derIndx  = self.expandedOperations[jj,i7]
          dataIndx = self.expandedOperations[jj,i8]
          dataKind = self.expandedOperations[jj,i9]

          # print("             Got kind ",c_fem_get_enum_string(dataKind))

          if   (dataKind == kindFunc  ):

            # Will use the array xcoord_e
            tmpDataFunc = <sotiarray_t*> self.defFunc[dataIndx]

            for kk in range(p_elements[elemIndx][i0].nbasis):

              xcoo_e.p_data[kk] = tmpDataFunc[i0].p_data[int(self.mesh.domainEls[ii,kk]-1)]

            # end for

            # print("Function evaluated at the points\n", c_sotiarray_print(&xcoo_e) )


            c_fem_defFunctFrom_otiFunc(&xcoo_e, derIndx, p_elements[elemIndx], &tmpFE_funcs[tmpIndx],p_dH)


          elif (dataKind == kindScalar):

            tmpDataSotinum = <sotinum_t*> self.defFunc[dataIndx]
            # print( c_soti_print(tmpDataSotinum) )
            c_fem_defFunctFrom_oti(tmpDataSotinum, derIndx, p_elements[elemIndx], &tmpFE_funcs[tmpIndx],p_dH)

          # end if 

          # print("\n  Defined temporal ",tmpIndx)
          # print(c_femarray_print(&tmpFE_funcs[tmpIndx]))
          # print("\n")


        elif operId == subOpInt     :

          operIntRegion = self.expandedOperations[jj,i1]
          tmpIndx2      = self.expandedOperations[jj,i2]# Extract number of integrations to perform. 

          if (elemRegion ==  operIntRegion) or (operIntRegion == -1) :
            
            
            for tmpIndx1 in range(tmpIndx2):

              tmpIndx = self.expandedOperations[jj,3+tmpIndx1]

              # print("             Integrating element ", tmpIndx)
              # print(c_femarray_print(&tmpFE_funcs[tmpIndx]))
              # print("\n             Into element Ke", tmpIndx)
              # print(c_sotiarray_print(&Ke))

              if jj >=  self.noperK:

                c_femarray_gaussIntegrateOverElement( &tmpFE_funcs[tmpIndx], p_elements[i0], &fe, p_dH)

              else:

                c_femarray_gaussIntegrateOverElement( &tmpFE_funcs[tmpIndx], p_elements[i0], &Ke, p_dH)

              # end if 

              # print("\n Ke:")
              # print(c_sotiarray_print(&Ke))

            # end for 

          # end if 

        elif operId == subOpNeg     :

          tmpIndx  = self.expandedOperations[jj,i1]
          tmpIndx1 = self.expandedOperations[jj,i6]

          
          c_femarray_neg(&tmpFE_funcs[tmpIndx1],&tmpFE_funcs[tmpIndx])

          # print("\n         Computed temporal ", tmpIndx)
          # print(c_femarray_print(&tmpFE_funcs[tmpIndx]))
          # print('\n')


        elif operId == subOpMulRes or operId == subOpMulKnown :

          tmpIndx  = self.expandedOperations[jj,i1]
          tmpIndx1 = self.expandedOperations[jj,i6]
          tmpIndx2 = self.expandedOperations[jj,i7]

          # print("Multipliyng :")
          # print(c_femarray_print(&tmpFE_funcs[tmpIndx1]))
          # print(c_femarray_print(&tmpFE_funcs[tmpIndx2]))
          # print("\nComputed temporal ", tmpIndx)

          c_femarray_matmul( &tmpFE_funcs[tmpIndx1], &tmpFE_funcs[tmpIndx2], &tmpFE_funcs[tmpIndx],p_dH)
          
          # print("\n  Computed temporal ", tmpIndx)
          # print(c_femarray_print(&tmpFE_funcs[tmpIndx]))
          # print('\n')

        # end if 
        


      # end for 
      # print(" ")
      # print("  After performing the operations, the following is obtained:")
      


      # print(" ")
      # print("  Ke:")
      # print(c_sotiarray_print(&Ke))

      # print(" ")
      # print("  fe:")
      # print(c_sotiarray_print(&fe))




      # print("Assembling in system.")

      # Assemble in the global stiffness matrix

      self.c_assembleInGlobals(&Ke,&fe, self.mesh.domainEls[ii])

      # print("After assembling in system.")
      # print("\n")
      # print("Assembled System. \n")
      # print(self.K.elements[0].toarray())
      # print(" ")
      # print(self.f)

      # print("\n")

    # end for
    # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
    # # # # # # # # # # # # # # END OF GLOBAL ASSEMBLY LOOP # # # # # # # # # # # # # 
    # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 

    # After assembly.

    # print("\n\n\n")
    # print("Assembled System before applying boundary conditions. \n")
    # print(self.K.elements[0].toarray())
    # print(" ")
    # print(self.f)
    
    # print("\n\n\n")



    c_sotiarray_free( &Ke )
    c_sotiarray_free( &fe )

    

    
    for jj in range(xcoo_e.size):
    
      xcoo_e.p_data[jj] = emptyNum
      ycoo_e.p_data[jj] = emptyNum
      zcoo_e.p_data[jj] = emptyNum
    
    # end if 



    
    

    # Xcoo_g = NULL
    # Ycoo_g = NULL
    # Zcoo_g = NULL

    
    

    




    c_sotiarray_free(&xcoo_e)
    c_sotiarray_free(&ycoo_e)
    c_sotiarray_free(&zcoo_e)
    # c_sotiarray_free(&tmp_e)


    # Uninit the elements
    # print(" - 2. unInitializing element types.")
    
    ii=0

    for elType in self.mesh.elTypes:

      # print("Uninit domain element ",ii)

      elType.uninitElement() 

      p_elements[ii] = NULL

      ii += 1
    
    # end for





































    cdef uint64_t globalOffset, imDir, matIndex
    cdef int64_t kkk, elIndx, dirBoundDim, dirBoundIndx, dirElId, dirNodeIndx
    cdef int64_t dirDatakind, dirDataIndx , dirGlobOffset,
    cdef double TGV = 1e30
    cdef sotinum_t tmpSoti1, tmpSoti2, tmpSoti3
    cdef np.ndarray dirElems = np.array([])







    # print(" ")
    # print("==============================================================================")
    # print("                      Loop per Neumann boundary integration                   ")
    # print("==============================================================================")

    cdef uint64_t neuStartPos = self.noperf
    cdef uint64_t neuEndPos   = neuStartPos
    cdef int64_t elemNumOfDim,  boundElIndx
    cdef int64_t neuBoundDim, neuBoundIndx, neuIntKeOrfe
    cdef np.ndarray neuElems = np.array([])

    cdef uint8_t selectElements = 1

    kk = self.noperf
    while kk < self.noperNeumann: # Loop while all kk are within the range of Neumann BC's.

      # print("kk: ",kk)
      # The first element is always a definition operation. 
      # It has information about the element interpolation type, boundary dimensions, etc.

      operId = self.expandedOperations[kk,i0] # This is redundant at this stage.

      neuBoundDim  = self.expandedOperations[kk,i6]
      neuBoundIndx = self.expandedOperations[kk,i7]
      # print("")
      # print("Got: boundary of dimension ", neuBoundDim," and index ", neuBoundIndx) 
      # print("Boundary id: ", self.mesh.elsIds[neuBoundDim][neuBoundIndx])

      neuElems     = self.mesh.elemTable[neuBoundDim][neuBoundIndx]
      neuStartPos = kk

      # Initialize all relevant data:
      ii = 0
      # 1. Initialize element types:
      for elType in self.mesh.elTypes:
        
        elTypeBoundary = elType.boundEls[neuBoundDim]
        elTypeBoundary.initElement(self.intorder,self.mesh.otiorder,nDimAnalysis)
         
        if ii == 0 :
          self.nIntPts = elTypeBoundary.elemProps.nIntPts
        # end if 

        p_elements[ii] = &elTypeBoundary.elemProps
        # print("\n Defined Interpolation type  "+str(ii))
        # print(c_elemprops_print(&elTypeBoundary.elemProps))

        ii += 1
    
      # end for
     
      # print(" - 6. Allocating Elemental force vector: \n")
      c_sotiarray_zeros( &Ke, self.eDOFBound[neuBoundDim], self.eDOFBound[neuBoundDim], self.mesh.otiorder)
      c_sotiarray_zeros( &fe, self.eDOFBound[neuBoundDim],                       1    , self.mesh.otiorder)
      # print( c_sotiarray_print(&fe) )



      c_sotiarray_zeros( &xcoo_e, self.eDOFBound[neuBoundDim], 1, self.mesh.otiorder )
      c_sotiarray_zeros( &ycoo_e, self.eDOFBound[neuBoundDim], 1, self.mesh.otiorder )
      c_sotiarray_zeros( &zcoo_e, self.eDOFBound[neuBoundDim], 1, self.mesh.otiorder )
      # c_sotiarray_zeros( &tmp_e,  self.eDOFBound[neuBoundDim], 1, self.mesh.otiorder )

      nElsMesh = neuElems.shape[0]

      # print("Element data:\n",neuElems)
      # print(neuElems.shape[i0],", ",neuElems.shape[i1])
      # print("")

      # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
      # # # # # # # # # # # # # # # # GLOBAL ASSEMBLY LOOP  # # # # # # # # # # # # # # 
      # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # 
      # Loop for each element
      for ii in range(nElsMesh):


        # print(" ")
        # print("  ---------------------------------------------------------------------")
        # print("  >>>> Element ", ii, ": ", self.mesh.domainEls[ii])
        # print("  ---------------------------------------------------------------------")

        # print("  Initializing Elemental stiffness matrix.")
        c_sotiarray_setAllItems(&emptyNum,&Ke)
        # print( c_sotiarray_print(&Ke) )

        # print("  Initializing Elemental force vector.")
        c_sotiarray_setAllItems(&emptyNum,&fe)
        # print( c_sotiarray_print(&fe) )

        # Get the elemental coordinates
        for jj in range( np.uint64( neuElems.shape[1]-1 ) ):

          # print("Getting coordinates of", int(neuElems[ii,jj]-1))

          # print("Here 1")
          xcoo_e.p_data[jj] = Xcoo_g[i0].p_data[ int(neuElems[ii,jj]-1) ]
          # print("Here 2")
          ycoo_e.p_data[jj] = Ycoo_g[i0].p_data[ int(neuElems[ii,jj]-1) ]
          # print("Here 3")
          zcoo_e.p_data[jj] = Zcoo_g[i0].p_data[ int(neuElems[ii,jj]-1) ]

        # end for

        # print("  Got the following coordinates: ")
        # print("    * X: ")
        # print( c_sotiarray_print(&xcoo_e) )
        # print("    * Y: ")
        # print( c_sotiarray_print(&ycoo_e) )
        # print("    * Z: ")
        # print( c_sotiarray_print(&zcoo_e) )

        

        # print(" ")
        # print("  Initializing the local interpolation data: ")
        for jj in range(nElements):  
          
          # print("           Initializing information of interpolations ", jj)
          # print("           Computation flags: ", bin(1))   

          c_fem_computeJacobian(p_elements[jj], &xcoo_e, &ycoo_e, &zcoo_e, p_dH)
          c_fem_defineSpatial(  p_elements[jj], 1, p_dH)

          # print( c_elemprops_print_perElement(p_elements[jj]) )

        # end for 


        # print(" \n\n\n\n")
        # print("  ----------------------------------------------------------------------------")
        # print("                         Looping for each operation                           ")
        # print("  ----------------------------------------------------------------------------")
        
        kk = neuStartPos
        # print("> kk : ", kk)
        operId = 0
        while operId != subOpInt:
          # print(" -- kk : ", kk)
          

          operId = self.expandedOperations[kk,i0]

          # print('Got ',c_fem_get_enum_string(operId))
          if   operId == subOpDefBasis:
            # print("\n --- In ",c_fem_get_enum_string(operId))
            tmpIndx  = self.expandedOperations[kk,i1 ]
            elemIndx = self.expandedOperations[kk,i11]
            derIndx  = self.expandedOperations[kk,i8 ]

            # print("Temporal "+ str(tmpIndx)+" array before: ")
            # print(c_femarray_print(&tmpFE_funcs[tmpIndx]))
            c_femarray_fromOther(&p_elements[elemIndx][i0].p_basis[derIndx], &tmpFE_funcs[tmpIndx])

            # print("\n       Defined temporal ",tmpIndx)
            # print(c_femarray_print(&tmpFE_funcs[tmpIndx]))
            # print("\n")

          elif operId == subOpDefKnown:
            # print("\n --- In ",c_fem_get_enum_string(operId))

            tmpIndx  = self.expandedOperations[kk,i1 ]
            elemIndx = self.expandedOperations[kk,i11]
            derIndx  = self.expandedOperations[kk,i8 ]
            dataIndx = self.expandedOperations[kk,i9 ]
            dataKind = self.expandedOperations[kk,i10]

            # print("             Got kind ",c_fem_get_enum_string(dataKind))

            if   (dataKind == kindFunc  ):

              # Will use the array xcoord_e
              tmpDataFunc = <sotiarray_t*> self.defFunc[dataIndx]

              for jj in range(p_elements[elemIndx][i0].nbasis):

                xcoo_e.p_data[jj] = tmpDataFunc[i0].p_data[int(neuElems[ii,jj]-1)]

              # end for

              # print( c_sotiarray_print(&xcoo_e) )


              c_fem_defFunctFrom_otiFunc(&xcoo_e, derIndx, p_elements[elemIndx], &tmpFE_funcs[tmpIndx],p_dH)


            elif (dataKind == kindScalar):

              tmpDataSotinum = <sotinum_t*> self.defFunc[dataIndx]
              # print( c_soti_print(tmpDataSotinum) )
              c_fem_defFunctFrom_oti(tmpDataSotinum, derIndx, p_elements[elemIndx], &tmpFE_funcs[tmpIndx],p_dH)

            # end if 

            # print("\n       Defined temporal ",tmpIndx)
            # print(c_femarray_print(&tmpFE_funcs[tmpIndx]))
            # print("\n")


          elif operId == subOpInt     :
            # print("\n --- In ",c_fem_get_enum_string(operId))
            operIntRegion = self.expandedOperations[kk,i1]
            tmpIndx2      = self.expandedOperations[kk,i2]# Extract number of integrations to perform.   
            neuIntKeOrfe  = self.expandedOperations[kk,i3]# Extract number of integrations to perform.  

            for tmpIndx1 in range(tmpIndx2):
              
              tmpIndx = self.expandedOperations[kk,4+tmpIndx1]
              
              # print(" Integrating temporal index ", tmpIndx)
              # print(c_femarray_print(&tmpFE_funcs[tmpIndx]))
              # detect if this is an operation for Ke or fe
              if  neuIntKeOrfe==1 :

                c_femarray_gaussIntegrateOverElement( &tmpFE_funcs[tmpIndx], p_elements[i0], &fe, p_dH)

              else:
             
                c_femarray_gaussIntegrateOverElement( &tmpFE_funcs[tmpIndx], p_elements[i0], &Ke, p_dH) 
             
              # end if   

             
              # print("here 2")

              # print("\n Ke:")
              # print(c_sotiarray_print(&Ke))

              # print("\n fe:")
              # print(c_sotiarray_print(&fe))

            # end for 


          elif operId == subOpNeg     :
            # print("\n --- In ",c_fem_get_enum_string(operId))
            tmpIndx  = self.expandedOperations[kk,i1]
            tmpIndx1 = self.expandedOperations[kk,i7]

            
            c_femarray_neg(&tmpFE_funcs[tmpIndx1],&tmpFE_funcs[tmpIndx])

            # print("\n         Computed temporal ", tmpIndx)
            # print(c_femarray_print(&tmpFE_funcs[tmpIndx]))
            # print('\n')
          elif operId == subOpMulRes or operId == subOpMulKnown :
            # print("\n --- In ",c_fem_get_enum_string(operId))
            tmpIndx  = self.expandedOperations[kk,i1]
            tmpIndx1 = self.expandedOperations[kk,i7]
            tmpIndx2 = self.expandedOperations[kk,i8]

            # print("Multipliyng :")
            # print(c_femarray_print(&tmpFE_funcs[tmpIndx1]))
            # print(c_femarray_print(&tmpFE_funcs[tmpIndx2]))
            # print("\nComputed temporal ", tmpIndx)

            c_femarray_matmul( &tmpFE_funcs[tmpIndx1], &tmpFE_funcs[tmpIndx2], &tmpFE_funcs[tmpIndx],p_dH)
            
            # print("\n          Computed temporal ", tmpIndx)
            # print(c_femarray_print(&tmpFE_funcs[tmpIndx]))
            # print('\n')

          # end if 

          




          kk += 1

        # end while

        # print("here")

        # print("\n Ke:")
        # print(c_sotiarray_print(&Ke))

        # print("\n fe:")
        # print(c_sotiarray_print(&fe))
        # print('\n before:')
        # print(self.f)  

        self.c_assembleInGlobalsBound( neuBoundDim, &Ke , &fe,  neuElems[ii])

        # print("\n after")
        # print(self.f)
      # end for 



      # uninit elements....
      c_sotiarray_free( &Ke )
      c_sotiarray_free( &fe )

      for jj in range(xcoo_e.size):
    
        xcoo_e.p_data[jj] = emptyNum
        ycoo_e.p_data[jj] = emptyNum
        zcoo_e.p_data[jj] = emptyNum
      
      # end if 

      c_sotiarray_free(&xcoo_e)
      c_sotiarray_free(&ycoo_e)
      c_sotiarray_free(&zcoo_e)
      # c_sotiarray_free(&tmp_e)

      ii = 0
      # 1. inInitialize element types:
      for elType in self.mesh.elTypes:
        # print("Uninit element ",ii," of boundary ", self.mesh.elsIds[neuBoundDim][neuBoundIndx])
        elTypeBoundary = elType.boundEls[neuBoundDim]
        elTypeBoundary.uninitElement()
         
        p_elements[ii] = NULL

        ii += 1
    
      # end for

    

    # end while



















    











    # print(" ")
    # print("==============================================================================")
    # print("                    Loop per Dirichlet boundary integration                   ")
    # print("==============================================================================")
    


    # Loop per operation in the Boundary operations "on".
    kk = self.noperNeumann
    while kk < self.noperDirichlet:

      # The first element in each iteration has the information about 

      operId = self.expandedOperations[kk,i0]

      # if operId != subOpOn:

      
      dirBoundDim  = self.expandedOperations[kk,i6]
      dirBoundIndx = self.expandedOperations[kk,i7]
      dirElems     = self.mesh.elemTable[dirBoundDim][dirBoundIndx]
      
      
      kk += 1

      dirGlobOffset= self.expandedOperations[kk,i4]
      dirDataIndx = self.expandedOperations[kk,i7]
      dirDatakind = self.expandedOperations[kk,i8]

      # print("Got ", c_fem_get_enum_string(dirDatakind)," with offset ", dirGlobOffset, " and index of data ", dirDataIndx)


      for ii in range( np.uint64( dirElems.shape[i0] ) ):
        #Setting Dirichlet Boundary condition for element.
        # print("\nSetting Dirichlet Boundary condition for element: ", dirElems[ii])

        for dirNodeIndx in range(dirElems.shape[i1]-1):
          
          dirElId = dirElems[ii,dirNodeIndx] - 1

          if dirDatakind == kindFunc:
            
            tmpDataFunc = <sotiarray_t*> self.defFunc[dirDataIndx]

            c_sotiarray_getItem(tmpDataFunc,dirElId,0,&tmpSoti1)

          elif dirDatakind == kindScalar:
            
            tmpDataSotinum = <sotinum_t*> self.defFunc[dirDataIndx]

            tmpSoti1 = tmpDataSotinum[i0]

          # end if
          # print("\nSetting ", dirElId+1, " with: ")
          # print(c_soti_print(&tmpSoti1))
          


          # multiply times TGV
          c_soti_mulf(&tmpSoti1,TGV,&tmpSoti2)

          c_soti_createFromReal(TGV,&tmpSoti3,self.mesh.otiorder)

          # Set both K and f with the data.
          # print("\nSetting K[ ", dirElId+dirGlobOffset,', ',dirElId+dirGlobOffset, "; with: ")
          # print(c_soti_print(&tmpSoti3))

          self.K.c_setSumFromSotinum([dirElId+dirGlobOffset,dirElId+dirGlobOffset], &tmpSoti3)


          matIndex = self.f.Ndir*(dirElId+dirGlobOffset)


          for kkk in range(np.int64(tmpSoti2.size)):

            imDir = tmpSoti2.p_indx[kkk]

            self.f.p_data[matIndex+imDir] += tmpSoti2.p_coefs[kkk] # this must have the same dimensions....

          # end for


          c_soti_free(&tmpSoti2)
          c_soti_free(&tmpSoti3)


          # set tmpSoti2 in the matrix and in the force vector.




        # end for 

      # end for 

      kk+=1


    # end while 


    self.flags = self.flags|1 # Raise assembled flag.




    for ii in range(ntmpFE):

      c_femarray_free(&tmpFE_funcs[ii])

    # end for 

    c_free_ptr( <void**> &tmpFE_funcs)



    c_free_ptr( <void**> &p_elements   )

    # Free the data pointer just after being used.
    c_free_ptr( <void**> &self.defFunc )

  #---------------------------------------------------------------------------------------------------





  #***************************************************************************************************
  cdef void c_assembleInGlobalsBound(self,int64_t ndim, sotiarray_t* Ke, sotiarray_t* fe, np.ndarray elements):
    """
    PORPUSE: Assemble the local elemental stiffness and force arrays in the global equivalents.

    """
    # ************************************************************************************************
    
    cdef uint64_t ii, jj, iZero_ = 0, iOne_ = 1, matIndex = 0, imDir
    cdef uint64_t posx, posy
    cdef sotinum_t tmp
    cdef list pos = [0,0]
    # print("\n Given element: ", elements)
    # print("Offsets: ", self.eOffset_per_StateVariable)
    # print("Ids: ", self.eId_per_DOF )
    for ii in range(fe[iZero_].nrows):

      pos[iZero_] = elements[self.eId_per_DOFBound[ndim][ii]] - 1 + self.eOffset_per_StateVariableBound[ndim][ii]

      # print("\nSetting position fe and Ke ii: ", ii, " equivalent to ",pos[iZero_])

      for jj in range(Ke[iZero_].ncols):

        # Get the element ii,jj of the elemental matrix.
        c_sotiarray_getItem( Ke, ii, jj, &tmp)



        pos[ iOne_] = elements[self.eId_per_DOFBound[ndim][jj]] - 1 + self.eOffset_per_StateVariableBound[ndim][jj]

        # print("Setting position ", ii,",", jj, " equivalent to ",pos[iZero_],",",pos[iOne_])
        
        # pos[ iOne_] = jj


        self.K.c_setSumFromSotinum(pos, &tmp)



        # end if


      # end for 
      
      # Add the values to the force load vector.

      c_sotiarray_getItem( fe, ii, 0, &tmp)

      matIndex = self.f.Ndir*pos[iZero_]
      # end if 

      for jj in range(tmp.size):

        imDir = tmp.p_indx[jj]

        self.f.p_data[matIndex+imDir] -= tmp.p_coefs[jj] # this must have the same dimensions....

      # end for




    # end for 


    # self.K.elements

  #---------------------------------------------------------------------------------------------------
  


  #***************************************************************************************************
  cdef void c_assembleInGlobals(self,sotiarray_t* Ke, sotiarray_t* fe, np.ndarray elements):
    """
    PORPUSE: Assemble the local elemental stifness and force arrays in the global equivalents.

    """
    # ************************************************************************************************

    cdef uint64_t ii, jj, iZero_ = 0, iOne_ = 1, matIndex = 0, imDir
    cdef uint64_t posx, posy
    cdef sotinum_t tmp
    cdef list pos = [0,0]
    # print("\n Given element: ", elements)
    # print("Offsets: ", self.eOffset_per_StateVariable)
    # print("Ids: ", self.eId_per_DOF )
    for ii in range(Ke[iZero_].nrows):

      pos[iZero_] = elements[self.eId_per_DOF[ii]] - 1 + self.eOffset_per_StateVariable[ii]

      # print("\nSetting position fe and Ke ii: ", ii, " equivalent to ",pos[iZero_])
      
      for jj in range(Ke[iZero_].ncols):

        # Get the element ii,jj of the elemental matrix.
        c_sotiarray_getItem( Ke, ii, jj, &tmp)



        pos[ iOne_] = elements[self.eId_per_DOF[jj]] - 1 + self.eOffset_per_StateVariable[jj]

        # print("Setting position ", ii,",", jj, " equivalent to ",pos[iZero_],",",pos[iOne_])
        
        # pos[ iOne_] = jj


        self.K.c_setSumFromSotinum(pos, &tmp)



        # end if


      # end for 


      # Add the values to the force load vector.

      # print("here1")

      c_sotiarray_getItem( fe, ii, 0, &tmp)

      matIndex = self.f.Ndir*pos[iZero_]


      for jj in range(tmp.size):

        imDir = tmp.p_indx[jj]

        self.f.p_data[matIndex+imDir] -= tmp.p_coefs[jj] # this must have the same dimensions....

      # end for
      # print("here2")



    # end for 


    # self.K.elements

  #---------------------------------------------------------------------------------------------------






  #***************************************************************************************************
  cpdef appendBasicInfo(self,int64_t subOpType, uint64_t funcId, list shape, list position):
    """
    PORPUSE: Append basic information common to many types of operations:

    DESCRIPTION: Sets the following position of current row as follows:

    Position |  Description
    ---------+----------------------------------------------------
    0.       |  SubOperation Id.
    ---------+----------------------------------------------------
    1.       |  Index of temporal array that holds it.
    ---------+----------------------------------------------------
    2.       |  Shape x of the result operation
    ---------+----------------------------------------------------
    3.       |  Shape y of the result operation
    ---------+----------------------------------------------------
    4.       |  Global offset in x
    ---------+----------------------------------------------------
    5.       |  Global offset in y
    ---------+----------------------------------------------------
    6.       |                      ---                   
    ---------+----------------------------------------------------
    7.       |                      ---                      
    ---------+----------------------------------------------------
    8.       |                      ---
    ---------+----------------------------------------------------
    9.       |                      --- 
    ---------+----------------------------------------------------

    """
    # ************************************************************************************************
    cdef list offset

    self.expandedOperations[self.noper,0] = subOpType        # 0. SubOperation Id
    # Index of the temporal value that will hold 
    # the result of the operation
    self.expandedOperations[self.noper,1] = self.tmp_indx    # 1. Index of temporal array that holds it.
    
    # Set temporal list with element.
    self.tmpIndx[funcId] = self.tmp_indx

    self.tmp_indx +=1

    self.expandedOperations[self.noper,2] = shape[0]         # 2. Shape x of the result operation
    self.expandedOperations[self.noper,3] = shape[1]         # 3. Shape y of the result operation 
    


    
      
      
    # compute  offset.
    offset = fem_getOffset(position,self.solFunc,self.testFunc,self.eDOF_per_sol)

    self.tmpShapesOffsets.append([shape,offset])

    self.expandedOperations[self.noper,4] = offset[0]        # 4. Global offset in x
    self.expandedOperations[self.noper,5] = offset[1]        # 5. Global offset in y
    
    # else:

    #   # compute  offset.
    #   offset = fem_getOffset(position,self.solFunc,self.testFunc,self.nDOF_per_sol)

    #   self.tmpShapesOffsets.append([shape,offset])

    #   self.expandedOperations[self.noper,4] = offset[0]        # 4. Global offset in x
    #   self.expandedOperations[self.noper,5] = offset[1]        # 5. Global offset in y

    # # end if 




  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  cpdef expandOperDef(self,fefunction res, fefunction func1):
    """
    PORPUSE: Expand Definition operation.

    DESCRIPTION: Add basic information, such as index, the shape and offset of the temporal array 
                 that will hold the data.

    Position |  Description
             |-----------------------|----------------------------
             |    Unknown/test       |     Known function         
    ---------|-----------------------|----------------------------
    0.       |    subOpDefBasis      |      subOpDefKnown         
    ---------|-----------------------|----------------------------
    1.       |      Index of temporal array that holds it.        
    ---------|----------------------------------------------------
    2.       |          Shape x of the result operation           
    ---------|----------------------------------------------------
    3.       |          Shape y of the result operation           
    ---------|----------------------------------------------------
    4.       |                Global offset in x                  
    ---------|----------------------------------------------------
    5.       |                Global offset in y                  
    ---------|----------------------------------------------------
    6.       |                Base element index                   
    ---------|----------------------------------------------------
    7.       |                  Id of basis                       
    ---------|-----------------------|----------------------------
    8.       |         -             |   Index where to find data 
    ---------|-----------------------|----------------------------
    9.       |         -             |   Kind of data             
    ---------|-----------------------|----------------------------
    

    """
    # ************************************************************************************************
    
    cdef int64_t dataKind 

    # case 1: Definition of test and solution functions.
    if func1.nature == feNatTest or func1.nature == feNatUndef:
      
      # Set first 6 positions with basic info.
      self.appendBasicInfo(subOpDefBasis, res.funcid, func1.shape, res.position)
      
      # Additional info.
      # Base element type. (where to get basis functions)
      self.expandedOperations[self.noper,6] = self.mesh.elTypes.index(func1.baseSpace.elType)
      
      # Id of the basis function to be used (what derivative to use).
      self.expandedOperations[self.noper,7] = res.interpDer - basisN
    

    # case 2:  when the function is known
    else: # case when func1.nature == feNatDef:
      
      # Set first 6 positions with basic info.
      self.appendBasicInfo(subOpDefKnown, res.funcid, func1.shape, res.position)

      # Base element type.
      self.expandedOperations[self.noper,6] = self.mesh.elTypes.index(func1.baseSpace.elType)

      # id of the basis function to be used.
      self.expandedOperations[self.noper,7] = res.interpDer - basisN

      self.defFuncList.append(func1)
      self.tmpIndxFunc[res.funcid] = self.ndeffunc
      # Add operations
      self.expandedOperations[self.noper,8] = self.ndeffunc # Defined element index.        
      
      dataKind = fem_getDataKind(func1.data)
      
      self.ndeffunc += 1

      self.expandedOperations[self.noper,9] = dataKind      # kind of function.
      self.tmpTypes[res.funcid] = dataKind
      
    # end if 

    self.noper += 1

  #---------------------------------------------------------------------------------------------------
  
  #***************************************************************************************************
  cdef expandOperMul(self,fefunction res, fefunction func1,fefunction func2):
    """
    PORPUSE: Expand multiplication operation.

    DESCRIPTION: Add basic information, such as index, the shape and offset of the temporal array 
                 that will hold the data, as well as information about the sources.

    Position |  Description
             |-----------------------|----------------------------
             |    Unknown/test       |     Known function
    ---------|-----------------------|----------------------------
    0.       |    subOpMulRes        |      subOpMulKnown
    ---------|-----------------------|----------------------------
    1.       |      Index of temporal array that holds it.
    ---------|----------------------------------------------------
    2.       |          Shape x of the result operation
    ---------|----------------------------------------------------
    3.       |          Shape y of the result operation
    ---------|----------------------------------------------------
    4.       |                Global offset in x
    ---------|----------------------------------------------------
    5.       |                Global offset in y
    ---------|----------------------------------------------------
    6.       |          Index of first multiplicand 
    ---------|----------------------------------------------------
    7.       |          Index of second multiplicand               
    ---------|-----------------------|----------------------------
    8.       |         -             |   Kind of data 
    ---------|-----------------------|----------------------------
    9.       |                       -
    ---------|----------------------------------------------------
    

    """
    # ************************************************************************************************
    
    # case 1: Multiplication with defined function.
    if func1.nature == feNatDef:
      
      # Set first 6 positions with basic info.
      self.appendBasicInfo(subOpMulRes, res.funcid, res.shape, res.position)
      
      # Index of the temporal value that will hold 
      # self.expandedOperations[self.noper,6] = self.tmpIndx[func2.funcid]  # Second element.
      
      # # get the index where to find the data.
      # self.expandedOperations[self.noper,7] = self.tmpIndxFunc[func1.funcid]
      
      # # Get the kind of data and add it to the element
      # self.expandedOperations[self.noper,8] = self.tmpTypes[func1.funcid] # Type of data

      self.expandedOperations[self.noper,6] = self.tmpIndx[func1.funcid] # position of first element.
      self.expandedOperations[self.noper,7] = self.tmpIndx[func2.funcid] # position of Second element.

    # 2. Multiplication with defined function
    elif func2.nature == feNatDef:

      # Set first 6 positions with basic info. #subOpMulKnown
      self.appendBasicInfo(subOpMulRes, res.funcid, res.shape, res.position)
      # Index of the temporal value that will hold 
      # self.expandedOperations[self.noper,6] = self.tmpIndx[func1.funcid] # Index of first element.
      
      # # get the index where to find the data.
      # self.expandedOperations[self.noper,7] = self.tmpIndxFunc[func2.funcid] 

      # # Get the kind of data and add it to the element
      # self.expandedOperations[self.noper,8] = self.tmpTypes[func2.funcid]# Type of data

      self.expandedOperations[self.noper,6] = self.tmpIndx[func1.funcid] # position of first element.
      self.expandedOperations[self.noper,7] = self.tmpIndx[func2.funcid] # position of Second element.

    # 3. Multiplication between test and other function.
    else:

      # Set first 6 positions with basic info.
      self.appendBasicInfo(subOpMulRes, res.funcid, res.shape, res.position)

      self.expandedOperations[self.noper,6] = self.tmpIndx[func1.funcid] # position of first element.
      self.expandedOperations[self.noper,7] = self.tmpIndx[func2.funcid] # position of Second element.

    # end if 
    self.noper+=1
  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  cdef expandOperNeg(self, fefunction res, fefunction func1):
    """
    PORPUSE: Expand multiplication operation.

    DESCRIPTION: Add basic information, such as index, the shape and offset of the temporal array 
                 that will hold the data, as well as information about the sources.

    Position |  Description
             |-----------------------|----------------------------
             |    Unknown/test       |     Known function         
    ---------|-----------------------|----------------------------
    0.       |                  subOpNeg                          
    ---------|----------------------------------------------------
    1.       |      Index of temporal array that holds it.        
    ---------|----------------------------------------------------
    2.       |          Shape x of the result operation           
    ---------|----------------------------------------------------
    3.       |          Shape y of the result operation           
    ---------|----------------------------------------------------
    4.       |                Global offset in x                  
    ---------|----------------------------------------------------
    5.       |                Global offset in y                  
    ---------|----------------------------------------------------
    6.       |          Index of element to be negated            
    ---------|----------------------------------------------------
    7.       |                       -                            
    ---------|----------------------------------------------------
    8.       |                       -                            
    ---------|----------------------------------------------------
    9.       |                       -                            
    ---------|----------------------------------------------------
    

    """
    # ************************************************************************************************
    
    # Set first 6 positions with basic info.
    self.appendBasicInfo(subOpNeg, res.funcid, res.shape, res.position)

    # position.
    self.expandedOperations[self.noper,6] = self.tmpIndx[func1.funcid]

    self.noper += 1

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  cdef expandOperInt(self, fefunction res, fefunction func1):
    """
    PORPUSE: Expand integration over domain operation.

    DESCRIPTION: Adds all integration temporals that will be integrated and added to the elemental
                 variables.

    Position |  Description
    ---------|----------------------------------------------------
    0.       |                   subOpInt
    ---------|----------------------------------------------------
    1.       |              Integration Region
    ---------|----------------------------------------------------
    2.       |      Number of integration operations defined
    ---------|----------------------------------------------------
    3.       |          Index of integration element 1
    ---------|----------------------------------------------------
    4.       |          Index of integration element 2
    ---------|----------------------------------------------------
    5.       |                      ....
    ---------|----------------------------------------------------
    6.       |                      ....
    ---------|----------------------------------------------------
    7.       |                      ....           
    ---------|----------------------------------------------------
    8.       |                      ....
    ---------|----------------------------------------------------
    9.       |                      ....
    ---------|----------------------------------------------------
    

    """
    # ************************************************************************************************
    cdef int64_t ii

    # Corroborate that there has been addition operations (stack multiple elements)
    if len(self.integrables) == 0:
      # if not, add the current integration element to it.
      self.integrables.append(self.tmpIndx[func1.funcid])
    # end if 

    # Add operation    
    self.expandedOperations[self.noper,0] = subOpInt
    

    # Define the integration region:
    self.expandedOperations[self.noper,1] = int(res.data)


    # Add the number of integrations that will be performed.
    self.expandedOperations[self.noper,2] = len(self.integrables) 
    if len(self.integrables)>7:
      raise ValueError("Integration operations must be less than 8 at each operation. i.e.,"+ \
        "The number of sum operations must not exceed 7 at each integration call.")
    # end if

    # Add Index of the temporal value to be integrated.
    for ii in range(len(self.integrables)):

      self.expandedOperations[self.noper,ii+3] = self.integrables [ii] 

    # end for 

    self.integrables = [] # empty the integrable s list.

    self.noper+=1

  #---------------------------------------------------------------------------------------------------

  

  #***************************************************************************************************
  cdef expandOperAdd(self, fefunction res , fefunction func1, fefunction func2):
    """
    PORPUSE: Expand addition operation.

    DESCRIPTION: Addition basically stacks the elements to be integrated later on. 
                 Otherwise, it does nothing.

    """
    # ************************************************************************************************

    if func1.nature == feNatOperRes and func2.nature == feNatOperRes or \
       func1.nature == feNatTest and func2.nature == feNatTest:
      
      # Check if the function is already in the integrable list.
      if self.tmpIndx[func1.funcid] not in self.integrables:
        self.integrables.append(self.tmpIndx[func1.funcid])
      # end if 

      # Check if the function is already in the integrable list.
      if self.tmpIndx[func2.funcid] not in self.integrables:
        self.integrables.append(self.tmpIndx[func2.funcid])
      # end if 

    # end if
  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  cpdef expandOperMatrix(self, np.ndarray matrix, uint8_t onlyOn = 0 ):
    """
    PORPUSE: Expand operation matrix.

    DESCRIPTION: Given the operation matrix, generate the codes for excecution in the assembly 
                 procedure.

    """
    # ************************************************************************************************
    cdef int64_t operIndx
    
    cdef fefunction func1, func2, res

    for operIndx in range(matrix.shape[0]):
      
      operId    = matrix[operIndx,0]
      resInd    = matrix[operIndx,1]
      func1Ind  = matrix[operIndx,2]
      func2Ind  = matrix[operIndx,3]

      if resInd not in self.uniqueOper:
        
        self.uniqueOper.append(resInd)

        res   = self.functionList[resInd]
        func1 = self.functionList[func1Ind]
        func2 = self.functionList[func2Ind]

        # -----------------------------
        #     DEFINITION OPERATIONS
        # -----------------------------
        if operId == opDef or operId == opDx or operId == opDy or operId == opDz: 
          
          self.expandOperDef( res, func1)
          self.setDerFlag(operId)

        # -----------------------------
        #     ADDITION OPERATIONS
        # -----------------------------
        elif operId == opAdd:
          
          self.expandOperAdd( res, func1, func2)

        # -----------------------------
        #     INTEGRATION OPERATIONS
        # -----------------------------
        elif operId == opInt3d or operId == opInt2d:

          self.expandOperInt( res, func1)

          if operId == opInt2d:

            self.noperNeumann = self.noper

          # end if 

        # -----------------------------
        #     NEGATION OPERATIONS
        # -----------------------------
        elif operId == opNeg:    
          
          self.expandOperNeg( res, func1)

        # -----------------------------
        #   MULTIPLICATION OPERATIONS
        # -----------------------------
        elif operId == opMul:  

          self.expandOperMul(res, func1, func2)

        # end if 

      # end if

    # end for
  #---------------------------------------------------------------------------------------------------











  #***************************************************************************************************
  cpdef appendBasicInfoBound(self,int64_t subOpType, uint64_t funcId, list shape, \
                         list position, int64_t bDim,):
    """
    PORPUSE: Append basic information common to many types of operations:

    DESCRIPTION: Sets the following position of current row as follows:

    Position |  Description
    ---------+----------------------------------------------------
    0.       |  SubOperation Id.
    ---------+----------------------------------------------------
    1.       |  Index of temporal array that holds it.
    ---------+----------------------------------------------------
    2.       |  Shape x of the result operation
    ---------+----------------------------------------------------
    3.       |  Shape y of the result operation
    ---------+----------------------------------------------------
    4.       |  Global offset in x
    ---------+----------------------------------------------------
    5.       |  Global offset in y
    ---------+----------------------------------------------------
    6.       |  Boundary Dimension              
    ---------+----------------------------------------------------
    7.       |                      ---                      
    ---------+----------------------------------------------------
    8.       |                      ---
    ---------+----------------------------------------------------
    9.       |                      --- 
    ---------+----------------------------------------------------

    """
    # ************************************************************************************************
    cdef list offset

    self.expandedOperations[self.noper,0] = subOpType        # 0. SubOperation Id
    # Index of the temporal value that will hold 
    # the result of the operation
    self.expandedOperations[self.noper,1] = self.tmp_indx    # 1. Index of temporal array that holds it.
    
    # Set temporal list with element.
    self.tmpIndx[funcId] = self.tmp_indx
    self.tmpIndxPos[funcId] = self.noper

    self.tmp_indx +=1

    self.expandedOperations[self.noper,2] = shape[0]         # 2. Shape x of the result operation
    self.expandedOperations[self.noper,3] = shape[1]         # 3. Shape y of the result operation 
    

    
    offset = fem_getOffset(position,self.solFunc,self.testFunc,self.eDOF_per_solBound[bDim])
    # print("\n1. Got position: ", position," with translates to offset: ", offset)
    # compute  offset.
    # offset = fem_getOffset(position,self.solFunc,self.testFunc,self.nDOF_per_sol  )

    # print("2. Got position: ", position," with translates to offset: ", offset)

    self.tmpShapesOffsets.append([shape,offset])

    self.expandedOperations[self.noper,4] = offset[0]     # 4. Global offset in x
    self.expandedOperations[self.noper,5] = offset[1]     # 5. Global offset in y
    self.expandedOperations[self.noper,6] = bDim          # 6. Boundary Dimension


  #---------------------------------------------------------------------------------------------------


  #***************************************************************************************************
  cpdef expandOperDefBound(self,fefunction res, fefunction func1, int64_t bDim, int64_t bIndx):
    """
    PORPUSE: Expand Definition operation.

    DESCRIPTION: Add basic information, such as index, the shape and offset of the temporal array 
                 that will hold the data.

    Position |  Description
             |-----------------------+----------------------------
             |    Unknown/test       |     Known function         
    ---------+-----------------------+----------------------------
    0.       |    subOpDefBasis      |      subOpDefKnown         
    ---------+-----------------------+----------------------------
    1.       |      Index of temporal array that holds it.        
    ---------+----------------------------------------------------
    2.       |          Shape x of the result operation           
    ---------+----------------------------------------------------
    3.       |          Shape y of the result operation           
    ---------+----------------------------------------------------
    4.       |                Global offset in x                  
    ---------+----------------------------------------------------
    5.       |                Global offset in y                 
    ---------+----------------------------------------------------
    6.       |                Boundary Dimension                 
    ---------+----------------------------------------------------
    7.       |             Boundary Element index                 
    ---------+----------------------------------------------------
    8.       |                  Id of basis                       
    ---------+-----------------------+----------------------------
    9.       |         -             |   Index where to find data 
    ---------+-----------------------+----------------------------
    10.      |         -             |   Kind of data             
    ---------+-----------------------+----------------------------
    11.      |               Base element index                   
    ---------+----------------------------------------------------

    """
    # ************************************************************************************************
    
    cdef int64_t dataKind, dof
    cdef list shape

    # Compute shape: 
    dof = func1.baseSpace.elType.boundEls[bDim].nbasis

    shape = [dof,1]


    # case 1: Definition of test and solution functions.
    if func1.nature == feNatTest or func1.nature == feNatUndef:
      
      # Set first 6 positions with basic info.
      # self.appendBasicInfoBound(subOpDefBasis, res.funcid, shape, res.position, bDim)
      self.appendBasicInfoBound(subOpDefBasis, res.funcid, res.shapeBounds[bDim], res.position, bDim)
      
      # Additional info.
      # Base element type. (where to get basis functions)
      self.expandedOperations[self.noper,7] = bIndx
      
      # Id of the basis function to be used (what derivative to use).
      self.expandedOperations[self.noper,8] = res.interpDer - basisN
      self.expandedOperations[self.noper,11] = self.mesh.elTypes.index(func1.baseSpace.elType)
    

    # case 2:  when the function is known
    else: # case when func1.nature == feNatDef:
      
      # Set first 6 positions with basic info.
      self.appendBasicInfoBound(subOpDefKnown, res.funcid, res.shapeBounds[bDim], res.position, bDim)

      # Base element type.
      self.expandedOperations[self.noper,7] = bIndx

      # id of the basis function to be used.
      self.expandedOperations[self.noper,8] = res.interpDer - basisN

      self.defFuncList.append(func1)
      self.tmpIndxFunc[res.funcid] = self.ndeffunc
      # Add operations
      self.expandedOperations[self.noper,9] = self.ndeffunc # Defined element index.        
      
      dataKind = fem_getDataKind(func1.data)
      
      self.ndeffunc += 1

      self.expandedOperations[self.noper,10] = dataKind      # kind of function.
      self.tmpTypes[res.funcid] = dataKind

      self.expandedOperations[self.noper,11] = self.mesh.elTypes.index(func1.baseSpace.elType)
      
    # end if 

    self.noper += 1

  #---------------------------------------------------------------------------------------------------


  #***************************************************************************************************
  cdef expandOperNegBound(self, fefunction res, fefunction func1, int64_t bDim):
    """
    PORPUSE: Expand multiplication operation.

    DESCRIPTION: Add basic information, such as index, the shape and offset of the temporal array 
                 that will hold the data, as well as information about the sources.

    Position |  Description
             |-----------------------|----------------------------
             |    Unknown/test       |     Known function         
    ---------|-----------------------|----------------------------
    0.       |                  subOpNeg                          
    ---------|----------------------------------------------------
    1.       |      Index of temporal array that holds it.        
    ---------|----------------------------------------------------
    2.       |          Shape x of the result operation           
    ---------|----------------------------------------------------
    3.       |          Shape y of the result operation           
    ---------|----------------------------------------------------
    4.       |                Global offset in x                  
    ---------|----------------------------------------------------
    5.       |                Global offset in y                  
    ---------|----------------------------------------------------
    6.       |                Boundary Dimension                  
    ---------|----------------------------------------------------
    7.       |          Index of element to be negated            
    ---------|----------------------------------------------------
    8.       |                       -                            
    ---------|----------------------------------------------------
    9.       |                       -                            
    ---------|----------------------------------------------------
    

    """
    # ************************************************************************************************
    cdef int64_t dof
    cdef list shape

    # Compute shape: 
    dof = func1.baseSpace.elType.boundEls[bDim].nbasis

    shape = [dof,1]

    # Set first 6 positions with basic info.
    # self.appendBasicInfoBound(subOpNeg, res.funcid, shape, res.position, bDim)
    self.appendBasicInfoBound(subOpNeg, res.funcid, res.shapeBounds[bDim], res.position, bDim)

    # position.
    self.expandedOperations[self.noper,7] = self.tmpIndx[func1.funcid]

    self.noper += 1

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  cdef expandOperIntBound(self, fefunction res, fefunction func1):
    """
    PORPUSE: Expand integration over domain operation.

    DESCRIPTION: Adds all integration temporals that will be integrated and added to the elemental
                 variables.

    Position |  Description
    ---------|----------------------------------------------------
    0.       |                   subOpInt
    ---------|----------------------------------------------------
    1.       |              Integration Region
    ---------|----------------------------------------------------
    2.       |      Number of integration operations defined
    ---------|----------------------------------------------------
    3.       |     Integration to Ke(0) or to fe(1) flag
    ---------|----------------------------------------------------
    4.       |     Index where operation element 1 is defined
    ---------|----------------------------------------------------
    5.       |     Index where operation element 2 is defined
    ---------|----------------------------------------------------
    6.       |                      ....                          
    ---------|----------------------------------------------------
    7.       |                      ....                          
    ---------|----------------------------------------------------
    8.       |                      ....                          
    ---------|----------------------------------------------------
    9.       |                      ....                          
    ---------|----------------------------------------------------
    10.      |                      ....                          
    ---------|----------------------------------------------------
    

    """
    # ************************************************************************************************
    cdef int64_t ii

    # Corroborate that there has been addition operations (stack multiple elements)
    if len(self.integrables) == 0:
      # if not, add the current integration element to it.
      self.integrables.append(self.tmpIndx[func1.funcid])
    # end if 

    # Add operation    
    self.expandedOperations[self.noper,0] = subOpInt
    

    # Define the integration region:
    self.expandedOperations[self.noper,1] = int(res.data)


    # Add the number of integrations that will be performed.
    self.expandedOperations[self.noper,2] = len(self.integrables) 

    if func1.nature == feNatOperRes:
      # Operation is for Ke
      self.expandedOperations[self.noper,3] = 0
    else:
      # Operation is for fe
      self.expandedOperations[self.noper,3] = 1       
    # end if 

    if len(self.integrables) > 11 :
      raise ValueError("Integration functions must be less than 12 at each operation. i.e.,"+ \
        " the number of sum operations must not exceed 11 at each integration call.")
    # end if

    # Add Index of the temporal value to be integrated.
    for ii in range(len(self.integrables)):

      self.expandedOperations[self.noper,ii+4] = self.integrables[ii] 

    # end for 

    self.integrables = [] # empty the integrable s list.

    self.noper += 1

  #---------------------------------------------------------------------------------------------------


  #***************************************************************************************************
  cdef expandOperAddBound(self, fefunction res , fefunction func1, fefunction func2):
    """
    PORPUSE: Expand addition operation.

    DESCRIPTION: Addition basically stacks the elements to be integrated later on. 
                 Otherwise, it does nothing.

    """
    # ************************************************************************************************

    if func1.nature == feNatOperRes and func2.nature == feNatOperRes or \
       func1.nature == feNatTest and func2.nature == feNatTest:
      
      # Check if the function is already in the integrable list.
      if self.tmpIndx[func1.funcid] not in self.integrables:
        self.integrables.append(self.tmpIndx[func1.funcid])
      # end if 

      # Check if the function is already in the integrable list.
      if self.tmpIndx[func2.funcid] not in self.integrables:
        self.integrables.append(self.tmpIndx[func2.funcid])
      # end if 

    # end if
  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  cdef expandOperMulBound(self,fefunction res, fefunction func1,fefunction func2, int64_t bDim):
    """
    PORPUSE: Expand multiplication operation.

    DESCRIPTION: Add basic information, such as index, the shape and offset of the temporal array 
                 that will hold the data, as well as information about the sources.

    Position |  Description
             |-----------------------|----------------------------
             |    Unknown/test       |     Known function
    ---------+-----------------------|----------------------------
    0.       |    subOpMulRes        |      subOpMulKnown
    ---------+-----------------------|----------------------------
    1.       |      Index of temporal array that holds it.
    ---------+----------------------------------------------------
    2.       |          Shape x of the result operation
    ---------+----------------------------------------------------
    3.       |          Shape y of the result operation
    ---------+----------------------------------------------------
    4.       |                Global offset in x
    ---------+----------------------------------------------------
    5.       |                Global offset in y
    ---------+----------------------------------------------------
    6.       |                Boundary Dimension                 
    ---------+----------------------------------------------------
    7.       |          Index of first multiplicand 
    ---------+----------------------------------------------------
    8.       |          Index of second multiplicand               
    ---------+----------------------------------------------------
    9.       |          Flag to integrate in Ke(1) or in fe(0)                
    ---------+----------------------------------------------------
    

    """
    # ************************************************************************************************
    
    


    # case 1: Multiplication with defined function.
    if func1.nature == feNatDef:
      
      # Set first 6 positions with basic info.
      # self.appendBasicInfoBound(subOpMulRes, res.funcid, shape, res.position, bDim)
      self.appendBasicInfoBound(subOpMulRes, res.funcid, res.shapeBounds[bDim], res.position, bDim)
      
      # Index of the temporal value that will hold 
      # self.expandedOperations[self.noper,6] = self.tmpIndx[func2.funcid]  # Second element.
      
      # # get the index where to find the data.
      # self.expandedOperations[self.noper,7] = self.tmpIndxFunc[func1.funcid]
      
      # # Get the kind of data and add it to the element
      # self.expandedOperations[self.noper,8] = self.tmpTypes[func1.funcid] # Type of data

      self.expandedOperations[self.noper,7] = self.tmpIndx[func1.funcid] # position of first element.
      self.expandedOperations[self.noper,8] = self.tmpIndx[func2.funcid] # position of Second element.

    # 2. Multiplication with defined function
    elif func2.nature == feNatDef:

      # Set first 6 positions with basic info. #subOpMulKnown
      # self.appendBasicInfoBound(subOpMulRes, res.funcid, shape, res.position, bDim)
      self.appendBasicInfoBound(subOpMulRes, res.funcid, res.shapeBounds[bDim], res.position, bDim)
      # Index of the temporal value that will hold 
      # self.expandedOperations[self.noper,6] = self.tmpIndx[func1.funcid] # Index of first element.
      
      # # get the index where to find the data.
      # self.expandedOperations[self.noper,7] = self.tmpIndxFunc[func2.funcid] 

      # # Get the kind of data and add it to the element
      # self.expandedOperations[self.noper,8] = self.tmpTypes[func2.funcid]# Type of data

      self.expandedOperations[self.noper,7] = self.tmpIndx[func1.funcid] # position of first element.
      self.expandedOperations[self.noper,8] = self.tmpIndx[func2.funcid] # position of Second element.

    # 3. Multiplication between test and other function.
    else:

      # Set first 6 positions with basic info.
      # self.appendBasicInfoBound(subOpMulRes, res.funcid, shape, res.position, bDim)
      self.appendBasicInfoBound(subOpMulRes, res.funcid, res.shapeBounds[bDim], res.position, bDim)

      self.expandedOperations[self.noper,7] = self.tmpIndx[func1.funcid] # position of first element.
      self.expandedOperations[self.noper,8] = self.tmpIndx[func2.funcid] # position of Second element.

    # end if 
    self.noper+=1
  #---------------------------------------------------------------------------------------------------


  #***************************************************************************************************
  cdef expandOperOnBound(self, fefunction res, fefunction func1,fefunction func2, int64_t bDim):
    """
    PORPUSE: Expand integration over domain operation.

    DESCRIPTION: Adds all integration temporals that will be integrated and added to the elemental
                 variables.

    Position |  Description
    ---------|----------------------------------------------------
    0.       |                  subOpOn
    ---------|----------------------------------------------------
    1.       |                 Boundary Id.
    ---------|----------------------------------------------------
    2.       |          Shape x of the result operation
    ---------|----------------------------------------------------
    3.       |          Shape y of the result operation
    ---------|----------------------------------------------------
    4.       |                Global offset in x
    ---------|----------------------------------------------------
    5.       |                Global offset in y
    ---------+----------------------------------------------------
    6.       |                Boundary Dimension                 
    ---------+----------------------------------------------------
    7.       |            Index where to find data
    ---------|----------------------------------------------------
    8.       |                  Kind of data           
    ---------|----------------------------------------------------
    9.       |                      ....
    ---------|----------------------------------------------------
    

    """
    # ************************************************************************************************
    
    cdef int64_t dof
    cdef list shape, offset

    # Compute shape: 
    dof = func1.baseSpace.elType.boundEls[bDim].nbasis

    shape = [1,1]
       
    # Set first 6 positions with basic info.
    self.appendBasicInfoBound( subOpOn, func1.funcid, shape, func2.position, bDim)

    # reset offsets to absolute global positions.
    offset = fem_getOffset(func2.position, self.solFunc, self.testFunc, self.nDOF_per_sol )
    self.expandedOperations[self.noper,4] = offset[0]     # 4. Global offset in x
    self.expandedOperations[self.noper,5] = offset[1]     # 5. Global offset in y

    # Remove creation of temporal. it is not needed in this case.

    # Set temporal list with element.
    self.tmpIndx[res.funcid] = None

    self.tmp_indx -= 1
    del self.tmpShapesOffsets[len(self.tmpShapesOffsets)-1]


    # Add the region
    self.expandedOperations[self.noper,1] = int(res.data)
    
    # get the index where to find the data.
    self.expandedOperations[self.noper,7] = self.tmpIndxFunc[func1.funcid]
    
    # Get the kind of data and add it to the element
    self.expandedOperations[self.noper,8] = self.tmpTypes[func1.funcid]# Type of data

    self.noper+=1

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  cpdef expandOperMatrixBound(self, np.ndarray matrix, uint8_t onlyOn = 0 ):
    """
    PORPUSE: Expand operation matrix for boundary conditions.

    DESCRIPTION: Given the operation matrix, generate the codes for execution in the assembly 
                 procedure for the boundary operations.

    """
    # ************************************************************************************************
    cdef int64_t operIndx_search, operIndx, startPos=0, endPos=0
    cdef int64_t regionId, regionDim, regionIndx, regionDOFs
    cdef fefunction func1, func2, res

    # print(" Received operation matrix: ")
    # print(matrix)
    # print("")

    for operIndx_search in range(matrix.shape[0]):
      
      # Search first for Integration or On operations.
      operId    = matrix[operIndx_search,0]

      if operId == opOn or operId == opInt2d:

        endPos = operIndx_search + 1
        resInd    = matrix[operIndx_search,1]
        
        res   = self.functionList[resInd]

        # self.integrables = []

        # print(res)

        # Get the region Id.
        regionId = int(res.data)

        # Search the region in the mesh.
        for regionDim in range(4):
        
          if regionId in self.mesh.elsIds[regionDim]:
        
            regionIndx  = self.mesh.elsIds[regionDim].index(regionId)
            break
        
          # end if 
        
        # end for 

        # print("Got ",c_fem_get_enum_string(operId)," in elements of dimension: ", regionDim, ", with index ",regionIndx, " and id: ", regionId)

        # regionDim:  Dimensions of the boundary.
        # regionIndx: Index where the data of this boundary is stored.
        # regionId:   Id of the boundary.

        # loop through all operations until this one.
        for operIndx in range(startPos,endPos):

          operId    = matrix[operIndx,0]
          resInd    = matrix[operIndx,1]
          func1Ind  = matrix[operIndx,2]
          func2Ind  = matrix[operIndx,3]
          

          # Always add the definition 
          res   = self.functionList[resInd]
          func1 = self.functionList[func1Ind]
          func2 = self.functionList[func2Ind]


          # print("\n",operIndx," Got operation: ",c_fem_get_enum_string(operId))
          # print("res:   ",res)
          # print("func1: ",func1)
          # print("func2: ",func2)

          # -----------------------------
          #     DEFINITION OPERATIONS
          # -----------------------------
          if operId == opDef: # or operId == opDx or operId == opDy or operId == opDz: # Other not supported
            
            self.expandOperDefBound( res, func1 , regionDim, regionIndx)

          # -----------------------------
          #     ADDITION OPERATIONS
          # -----------------------------
          elif operId == opAdd:
            
            self.expandOperAddBound( res, func1, func2)

          # -----------------------------
          #     INTEGRATION OPERATIONS
          # -----------------------------
          elif operId == opInt2d:

            self.expandOperIntBound( res, func1)

            self.noperNeumann = self.noper
            

          # -----------------------------
          #     NEGATION OPERATIONS
          # -----------------------------
          elif operId == opNeg:    
            
            self.expandOperNegBound( res, func1, regionDim)

          # -----------------------------
          #   MULTIPLICATION OPERATIONS
          # -----------------------------
          elif operId == opMul:  

            self.expandOperMulBound(res, func1, func2, regionDim)

          # -----------------------------
          #         ON OPERATIONS
          # -----------------------------
          elif operId == opOn:  

            self.expandOperOnBound(res, func1, func2, regionDim)

          # end if 

        # end for 
        
        startPos = endPos

      # end if 


    # end for
  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************  
  cdef void setDerFlag(self, int64_t operId):
    """
    PORPUSE: Raise the flag that tracks the derivative in need to be computed per element.

    """
    # ************************************************************************************************
    cdef uint16_t flag
    cdef uint64_t elPos = self.expandedOperations[self.noper-1,6]


    if   operId == opDef:

      flag = self.derCompFlags[elPos]
      self.derCompFlags[elPos] = flag | 1

    elif operId == opDx :

      flag = self.derCompFlags[elPos]
      self.derCompFlags[elPos] = flag | 1<<1

    elif operId == opDy :

      flag = self.derCompFlags[elPos]
      self.derCompFlags[elPos] = flag | 1<<3

    elif operId == opDz :

      flag = self.derCompFlags[elPos]
      self.derCompFlags[elPos] = flag | 1<<6

    elif operId == opDxx :

      flag = self.derCompFlags[elPos]
      self.derCompFlags[elPos] = flag | 1<<2

    elif operId == opDxy :

      flag = self.derCompFlags[elPos]
      self.derCompFlags[elPos] = flag | 1<<4

    elif operId == opDyy :

      flag = self.derCompFlags[elPos]
      self.derCompFlags[elPos] = flag | 1<<5

    elif operId == opDxz :

      flag = self.derCompFlags[elPos]
      self.derCompFlags[elPos] = flag | 1<<7

    elif operId == opDyz :

      flag = self.derCompFlags[elPos]
      self.derCompFlags[elPos] = flag | 1<<8

    elif operId == opDzz :

      flag = self.derCompFlags[elPos]
      self.derCompFlags[elPos] = flag | 1<<9

    # end if 

  #---------------------------------------------------------------------------------------------------


  


  #***************************************************************************************************  
  cpdef applyBoundConds(self):
    """
    PORPUSE:  Apply correspondingly the boundary conditions defined in the problem.

    """


    cdef uint64_t nBoundOper = 0,
    # Expand Boundary operations: Boundary integrals and Dirichlet conditions. 

    diBoundCond = []
    nBoundOper  = self.problem.essentialOper.shape[0]
    end_pos     = []
    start_pos   = []
    start_flag  = 0

    for operIndx in range(int(nBoundOper)):

      operId = self.problem.essentialOper[nBoundOper-operIndx-1,0]

      if operId == opInt2d:

        start_flag = 1
        end_pos.append(nBoundOper-operIndx-1)

      elif operId == opOn:

        diBoundCond.append(nBoundOper-operIndx-1)

        if operIndx!= 0 and start_flag == 1:
          
          start_flag = 0
          start_pos.append(nBoundOper-operIndx-1)

        # end if 

      elif operIndx == nBoundOper-1 and start_flag == 1:

        start_pos.append(nBoundOper-operIndx-1)

      # end if 

    # end for


    # Expand boundary operations.

    print('start:   ',start_pos)
    print('stop:    ',end_pos)
    print('on Oper: ',diBoundCond)

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************


# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::: END OF CLASS FEPROBLEM :::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
















  
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::     CLASS  OTIMESH    :::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
cdef class mesh:
  
  #---------------------------------------------------------------------------------------------------
  #------------------------------------   DEFINITION OF ATTRIBUTES   ---------------------------------
  #---------------------------------------------------------------------------------------------------

  cdef public dict     cells        # Elements
  cdef public dict     point_data   # Contains information of the points
  cdef public dict     cell_data    # Contains information of the elements
  cdef public dict     field_data   # Contains labels.
  cdef public dict     nameIds      # Contains labels.
  cdef public uint8_t  ndim         # Characteristic number of dimensions in the mesh.
  cdef public sndarray xcoords      # Nodal coordinates as sndarrays.
  cdef public sndarray ycoords      # Nodal coordinates as sndarrays.
  cdef public sndarray zcoords      # Nodal coordinates as sndarrays.
  cdef public uint8_t  otiorder     # order of the oti numbers it contains.
  cdef public int64_t  baseGeomType # Basic geometric type

  cdef public list elemTable        # List of elements in each dimension 
                                    #[ 0D elems ->    ... ,
                                    #  1D elems ->    ... ,
                                    #  2D elems ->    ... ,
                                    #  3D elems ->    ... ]

  cdef np.ndarray   domainEls       # Elements that define the domain.
  cdef np.ndarray   normalx         # x component of the boundary normal
  cdef np.ndarray   normaly         # y component of the boundary normal
  cdef np.ndarray   normalz         # z component of the boundary normal
  cdef public  int64_t domainType    # Geometric type of the domain.
  cdef public uint64_t domainElDofs  # D.O.Fs of the domain element.
  cdef public  list boundaEls       # Elements that define the boundary elements.
  cdef public  list boundaType      # Geometric type of the boundaries.
  cdef public  list boundaElsIds    # Ids of the boundary elements 
  cdef public  list elsIds
 
  cdef public list fespaces         # List of finite element spaces that are currently in the mesh.
                                    # Is this required? or maybe only add the element types only?
 
  cdef public list elTypes          # List of interpolating functions defined for the triangulation.

  cdef public uint64_t operationCount

  cdef public fefunction x
  cdef public fefunction y
  cdef public fefunction z
  cdef public uint8_t    xyzInit    # flag for initialization of x,y,z

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

  

  






















































# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# :::::::::::::::::::::::::::::::::::     CLASS  FESPACE    ::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
cdef class fespace2:

  #---------------------------------------------------------------------------------------------------
  #------------------------------------   DEFINITION OF ATTRIBUTES   ---------------------------------
  #---------------------------------------------------------------------------------------------------

  cdef public mesh    mesh        # Triangulation related to this space.
  cdef public elBase  elType     # Element type that defines the interpolation functions.
  cdef public uint8_t fespaceId  # Id of the finite element space in the mesh.


  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  def __init__(self, mesh mesh, elBase elType):
    """
    PURPOSE:      Constructor of the finite element space class. Its main purpose is to define 
                  a class to relate the triangulation with interpolation functions defined by the
                  element type.

    INPUTS:

            -> mesh:     Mesh that defines the domain of the function.

            -> elementType:  Defines the interpolation functions of the discretized domain.

    """
    
    self.mesh       = mesh         # Reference to the mesh
    self.elType     = elType       # Reference to the element type.
    self.fespaceId  = self.mesh.addNewSpace(self) # Stack


    # TODO: How to add warning on how to require mesh and element type?
    
  #---------------------------------------------------------------------------------------------------



  #***************************************************************************************************
  cdef uint64_t addNewOperation(self):
    """
    PURPOSE:      Add a new Finite Element operation. 
                  Returns an Id of the operation

    """
    
    return self.mesh.addNewOperation()

  #---------------------------------------------------------------------------------------------------


  #***************************************************************************************************
  def newTestFunction(self, kind = None):
    """
    PURPOSE:      Add a new Finite Element function. 
                  As such, it is added to the operation stack as a variable definition.

    """
    
    res = fefunction(self, feNatTest)

    return res
  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  def newUndefinedFunction(self):
    """
    PURPOSE:      Add a new Finite Element function that will be defined by solving a 
                  Finite element problem

    """
    
    res = fefunction(self, feNatUndef)

    return res
  #---------------------------------------------------------------------------------------------------


  #***************************************************************************************************
  def newFunction(self, object data):
    """
    PURPOSE:      Add a new Finite Element function that is defined in the space.

    """
    cdef object data_conv

    if type(data) in number_types:

      data_conv = data + 0*se(1 ,order = self.mesh.otiorder )

    elif type(data) == sotinum or  type(data) == sndarray or type(data) == ndarray:
    
      data_conv = data

    elif type(data) == np.ndarray:

      data_conv = sarray(data,self.mesh.otiorder)

    else:

      raise ValueError("Can't create function from data type ",type(data) )

    # end if 



    res = fefunction(self, feNatDef, data = data_conv) 
    res.shape = [1,1]
    return res
  #---------------------------------------------------------------------------------------------------


# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::: END OF CLASS FESPACE2 ::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

















# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# :::::::::::::::::::::::::::::::::     CLASS  FEFUNCTION    :::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
cdef class fefunction:

  #---------------------------------------------------------------------------------------------------
  #------------------------------------   DEFINITION OF ATTRIBUTES   ---------------------------------
  #---------------------------------------------------------------------------------------------------

  cdef public fespace2    baseSpace     # Finite element space at which the variable is associated.
  
  cdef public int64_t     interpDer     # Interpolation derivative that is required in this operation.

  cdef public uint64_t    intorder      # Polynomial order. The interpolation basis define an order.
                                        # Then, the operations will increase the order of the 
                                        # equivalent polynomials. That will modify the integration 
                                        # parameters for numerical computations.

  cdef public uint64_t    funcid        # Global Id of the function. 

  cdef public int64_t     nature        # Nature of the function: 
                                        #    feNatTest, feNatUndef, feNatDef

  cdef public list shape      
  cdef public list shapeBounds                
  cdef public list position             # position in the matrix.
  
  cdef public object   data             # Data of the object, if defined already.
  cdef public list     baseFunc         # A list to know which vars are associated to the number.


  cdef np.ndarray  Koper                # Operations defined for Stiffness matrix.
  cdef np.ndarray  foper                # Operations defined for Force vector.
  cdef np.ndarray  essentialOper        # Operations defined for boundary conditions.

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  def __init__(self, fespace2 baseSpace, int64_t nature, int64_t interpDer = basisN, \
               object data = None ):
    """
    PURPOSE:      Constructor of the finite element space class. Its main purpose is to define 
                  a common parameter to store all the procedures and variables to be performed
                  during the Finite Element calculations.

    INPUTS:

          -> baseSpace: Finite element space that this function is associated.

          -> nature:    Nature of the problem. Can be:
                        * feNatTest:  For test function
                        * feNatUndef: For function that will be defined by solving a FE problem. 
                        * feNatDef:   Defined, and has data already.

          -> interpDer: *Optional* Basis function derivative with which it will be approximated.

    """
    #*************************************************************************************************

    self.baseSpace  = baseSpace

    self.interpDer  = interpDer

    self.nature = nature

    self.intorder  = self.baseSpace.elType.order  # modify it outside if required.

    self.funcid    = self.baseSpace.addNewOperation()
    
    if self.nature == feNatDef:

      self.position = [0]
      self.data = data

    else:

      self.position = [self.funcid]
      self.data = None

    # end if 

    self.baseFunc = [ self ] 

    if self.nature == feNatTest:

      self.shape = [baseSpace.elType.nbasis,1]

    elif self.nature == feNatUndef:

      self.shape = [1,baseSpace.elType.nbasis]

    else:

      self.shape = [1,1]

    # end if 
                      # 0D, 1D, 2D
    self.shapeBounds = [[], [], []]

    cdef int64_t i

    for i in range(len(baseSpace.elType.boundEls)):

      if self.nature == feNatTest:

        self.shapeBounds[i] = [baseSpace.elType.boundEls[i].nbasis,1]

      elif self.nature == feNatUndef:

        self.shapeBounds[i] = [1,baseSpace.elType.boundEls[i].nbasis]

      else:

        self.shapeBounds[i] = [1,1]

      # end if 

    # end for 
    

    self.Koper        = np.array([[opDef, self.funcid, self.funcid, 0]],dtype = np.int64) # definitions goes only in the matrix. 

    self.foper        = np.array([[opDef, self.funcid, self.funcid, 0]],dtype = np.int64) #

    self.essentialOper= np.array([[opDef, self.funcid, self.funcid, 0]],dtype = np.int64) # 


  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  @property
  def operK(self):
    return self.Koper
  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  @property
  def operf(self):
    return self.foper
  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  @property
  def operEssential(self):
    return self.essentialOper
  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  @staticmethod
  cdef fefunction newFromOperation(int64_t operId, fefunction func1, fefunction func2):
    """
    PURPOSE:  Create a new element from 


    INPUTS:  

      -> operId:Id that characterizes the operation.

              opAdd    , opSub    , opMul    , 
              opTruediv, opPowr   , opInt1d  , 
              opInt2d  , opInt3d  , opDx     , 
              opDxx    , opDy     , opDxy    , 
              opDyy    , opDz     , opDxz    , 
              opDyz    , opDzz    , opDef    ,                   
    """
    #*************************************************************************************************
    
    cdef fefunction res = <fefunction> fefunction.__new__(fefunction)
    cdef np.ndarray newOperation 
    res.interpDer  = basisN

    
    # % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % %
    # % % % % % % % % % % % % % % % % %     MULTIPLICATION      % % % % % % % % % % % % % % %
    # % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % %
    if operId == opMul:
      

      if func1.nature == feNatDef and func2.nature == feNatDef:
        
        # TODO: Operation between two defined functions that have
        #       different spaces should be performed as an operation
        #       to be done later rather than an operation inplace.

        # Perform the operation
        res = func1.baseSpace.newFunction(func1.data*func2.data)
        
        res.intorder = func1.intorder + func2.intorder

        return res

      # end if 

      # The base space is that of the greatest  order
      if func1.baseSpace.elType.order > func2.baseSpace.elType.order:
        res.baseSpace = func1.baseSpace
      else:
        res.baseSpace = func2.baseSpace
      # end if 

      res.intorder = func1.intorder + func2.intorder
      res.funcid   = res.baseSpace.addNewOperation()

      res.baseFunc = func1.baseFunc.copy()

      # Add only unique base functions, i.e., do not duplicate.
      for base in func2.baseFunc:
        if base not in res.baseFunc:
          res.baseFunc.append(base)
        # end if 
      # end for 

      # Add itself to the list of baseFunctions
      res.baseFunc.append(res)

      # Organize the operation matrix

      # case 1: test * undef funct
      if func1.nature == feNatTest and func2.nature == feNatUndef:

        res.Koper = func1.Koper.copy()
        res.Koper = np.append(res.Koper,func2.Koper,axis=0)
        res.Koper = np.append(res.Koper,\
                             [[operId,res.funcid,func1.funcid,func2.funcid]],\
                              axis = 0)
        res.foper = np.array([],dtype=np.uint64)
        
        # append both operation matrices
        res.essentialOper = func1.essentialOper.copy()
        res.essentialOper = np.append(res.essentialOper,func2.essentialOper, axis = 0)

        # add new operation to the operations
        res.essentialOper = np.append(res.essentialOper, \
                              [[operId,res.funcid,func1.funcid,func2.funcid]],\
                              axis = 0)

        res.nature = feNatOperRes
        res.shape =    [func1.shape[0],func2.shape[1]]
        res.shapeBounds = [[],[],[]]
        
        for i in range(3):
          if len(func1.shapeBounds[i])!=0:
            res.shapeBounds[i] = [func1.shapeBounds[i][0],func2.shapeBounds[i][1]]
          # end if 
        # end for 
        
        res.position = [func1.position[0],func2.position[0]]

      # case 2: undef funct * test
      elif func1.nature == feNatUndef and func2.nature == feNatTest:

        # append both operation matrices
        res.Koper = func1.Koper.copy()
        res.Koper = np.append(res.Koper,func2.Koper,axis=0)
        
        # add new operation to the operations
        res.Koper = np.append(res.Koper,\
                             [[operId,res.funcid,func2.funcid,func1.funcid]],\
                              axis = 0)

        # initialize the other two operation matrices as void.
        res.foper = np.array([],dtype=np.int64)
        
        # append both operation matrices
        res.essentialOper = func1.essentialOper.copy()
        res.essentialOper = np.append(res.essentialOper,func2.essentialOper, axis = 0)

        # add new operation to the operations
        res.essentialOper = np.append(res.essentialOper, \
                              [[operId,res.funcid,func2.funcid,func1.funcid]],\
                              axis = 0)

        res.nature = feNatOperRes
        res.shape    = [func2.shape[0],    func1.shape[1] ]
        res.shapeBounds = [[],[],[]]
        
        for i in range(3):
          if len(func1.shapeBounds[i])!=0:
            res.shapeBounds[i] = [func2.shapeBounds[i][0],func1.shapeBounds[i][1]]
          # end if 
        # end for 

        res.position = [func2.position[0],func1.position[0]]


      # case 3: def funct * test
      elif func1.nature == feNatTest and func2.nature == feNatDef:
        
        # append both operation matrices
        res.foper = func1.foper.copy()
        res.foper = np.append(res.foper,func2.foper, axis = 0)

        # add new operation to the operations
        res.foper = np.append(res.foper, \
                              [[operId,res.funcid,func1.funcid,func2.funcid]],\
                              axis = 0)

        # append both operation matrices
        res.Koper = func1.Koper.copy()
        res.Koper = np.append(res.Koper,func2.Koper, axis = 0)

        # add new operation to the operations
        res.Koper = np.append(res.Koper, \
                              [[operId,res.funcid,func1.funcid,func2.funcid]],\
                              axis = 0)

        # append both operation matrices
        res.essentialOper = func1.essentialOper.copy()
        res.essentialOper = np.append(res.essentialOper,func2.essentialOper, axis = 0)

        # add new operation to the operations
        res.essentialOper = np.append(res.essentialOper, \
                              [[operId,res.funcid,func1.funcid,func2.funcid]],\
                              axis = 0)

        res.nature = feNatTest
        res.shape = func1.shape.copy()
        res.shapeBounds = func1.shapeBounds.copy()
        res.position = func1.position.copy()

      # case 4: def funct * test
      elif func1.nature == feNatDef and func2.nature == feNatTest:

        # append both operation matrices
        res.foper = func2.foper.copy()
        res.foper = np.append(res.foper,func1.foper, axis = 0)

        # add new operation to the operations
        res.foper = np.append(res.foper, \
                              [[operId,res.funcid,func2.funcid,func1.funcid]],\
                              axis = 0)

        # append both operation matrices
        res.Koper = func1.Koper.copy()
        res.Koper = np.append(res.Koper,func2.Koper, axis = 0)

        # add new operation to the operations
        res.Koper = np.append(res.Koper, \
                              [[operId,res.funcid,func1.funcid,func2.funcid]],\
                              axis = 0)

        # append both operation matrices
        res.essentialOper = func1.essentialOper.copy()
        res.essentialOper = np.append(res.essentialOper,func2.essentialOper, axis = 0)

        # add new operation to the operations
        res.essentialOper = np.append(res.essentialOper, \
                              [[operId,res.funcid,func1.funcid,func2.funcid]],\
                              axis = 0)

        res.nature = feNatTest
        res.shape = func2.shape.copy()
        res.shapeBounds = func2.shapeBounds.copy()
        res.position = func2.position.copy()


      # case 5: Undef * def funct
      elif func1.nature == feNatUndef and func2.nature == feNatDef:
        
        # append both operation matrices
        res.foper = func1.foper.copy()
        res.foper = np.append(res.foper,func2.foper, axis = 0)

        # add new operation to the operations
        res.foper = np.append(res.foper, \
                              [[operId,res.funcid,func1.funcid,func2.funcid]],\
                              axis = 0)

        # append both operation matrices
        res.Koper = func1.Koper.copy()
        res.Koper = np.append(res.Koper,func2.Koper, axis = 0)

        # add new operation to the operations
        res.Koper = np.append(res.Koper, \
                              [[operId,res.funcid,func1.funcid,func2.funcid]],\
                              axis = 0)

        # append both operation matrices
        res.essentialOper = func1.essentialOper.copy()
        res.essentialOper = np.append(res.essentialOper,func2.essentialOper, axis = 0)

        # add new operation to the operations
        res.essentialOper = np.append(res.essentialOper, \
                              [[operId,res.funcid,func1.funcid,func2.funcid]],\
                              axis = 0)

        res.nature = feNatUndef
        res.shape = func1.shape.copy()
        res.shapeBounds = func1.shapeBounds.copy()
        res.position = func1.position.copy()

      # case 6: def funct * Undef
      elif func1.nature == feNatDef and func2.nature == feNatUndef:

        # append both operation matrices
        res.foper = func2.foper.copy()
        res.foper = np.append(res.foper,func1.foper, axis = 0)

        # add new operation to the operations
        res.foper = np.append(res.foper, \
                              [[operId,res.funcid,func2.funcid,func1.funcid]],\
                              axis = 0)
        # append both operation matrices
        res.Koper = func1.Koper.copy()
        res.Koper = np.append(res.Koper,func2.Koper, axis = 0)

        # add new operation to the operations
        res.Koper = np.append(res.Koper, \
                              [[operId,res.funcid,func1.funcid,func2.funcid]],\
                              axis = 0)

        # append both operation matrices
        res.essentialOper = func1.essentialOper.copy()
        res.essentialOper = np.append(res.essentialOper,func2.essentialOper, axis = 0)

        # add new operation to the operations
        res.essentialOper = np.append(res.essentialOper, \
                              [[operId,res.funcid,func1.funcid,func2.funcid]],\
                              axis = 0)

        res.nature = feNatUndef
        res.shape = func2.shape.copy()
        res.shapeBounds = func2.shapeBounds.copy()
        res.position = func2.position.copy()


      # case 5: Undef * def funct
      elif func1.nature == feNatOperRes and func2.nature == feNatDef:
        
        # append both operation matrices
        res.foper = func1.foper.copy()
        res.foper = np.append(res.foper,func2.foper, axis = 0)

        # add new operation to the operations
        res.foper = np.append(res.foper, \
                              [[operId,res.funcid,func1.funcid,func2.funcid]],\
                              axis = 0)


        # append both operation matrices
        res.Koper = func1.Koper.copy()
        res.Koper = np.append(res.Koper,func2.Koper, axis = 0)

        # add new operation to the operations
        res.Koper = np.append(res.Koper, \
                              [[operId,res.funcid,func1.funcid,func2.funcid]],\
                              axis = 0)

        # append both operation matrices
        res.essentialOper = func1.essentialOper.copy()
        res.essentialOper = np.append(res.essentialOper,func2.essentialOper, axis = 0)

        # add new operation to the operations
        res.essentialOper = np.append(res.essentialOper, \
                              [[operId,res.funcid,func1.funcid,func2.funcid]],\
                              axis = 0)

        res.nature = feNatOperRes
        res.shape = func1.shape.copy()
        res.shapeBounds = func1.shapeBounds.copy()
        res.position = func1.position.copy()

      # case 6: def funct * Undef
      elif func1.nature == feNatDef and func2.nature == feNatOperRes:

        # append both operation matrices
        res.foper = func2.foper.copy()
        res.foper = np.append(res.foper,func1.foper, axis = 0)

        # add new operation to the operations
        res.foper = np.append(res.foper, \
                              [[operId,res.funcid,func2.funcid,func1.funcid]],\
                              axis = 0)

        # append both operation matrices
        res.Koper = func1.Koper.copy()
        res.Koper = np.append(res.Koper,func2.Koper, axis = 0)

        # add new operation to the operations
        res.Koper = np.append(res.Koper, \
                              [[operId,res.funcid,func1.funcid,func2.funcid]],\
                              axis = 0)

        # append both operation matrices
        res.essentialOper = func1.essentialOper.copy()
        res.essentialOper = np.append(res.essentialOper,func2.essentialOper, axis = 0)

        # add new operation to the operations
        res.essentialOper = np.append(res.essentialOper, \
                              [[operId,res.funcid,func1.funcid,func2.funcid]],\
                              axis = 0)

        res.nature = feNatOperRes
        res.shape = func2.shape.copy()
        res.shapeBounds = func2.shapeBounds.copy()
        res.position = func2.position.copy()

      else:

        raise ValueError("Can't operate the functions.")

      # end if 


    # % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % %
    # % % % % % % % % % % % % % % %   ADDITION / SUBTRACTION  % % % % % % % % % % % % % % % %
    # % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % %
    elif operId == opAdd or operId == opSub:   # Addition

      # If both are defined.
      if func1.nature == feNatDef and func2.nature == feNatDef:
        
        # Perform the operation
        if operId == opAdd:
          res = func1.baseSpace.newFunction(func1.data+func2.data)
        else:
          res = func1.baseSpace.newFunction(func1.data-func2.data)
        # end if 

        res.intorder = max(func1.intorder , func2.intorder)

        return res

      # end if 

      # The base space is that of the greatest order
      if func1.baseSpace.elType.order > func2.baseSpace.elType.order:
        res.baseSpace = func1.baseSpace
      else:
        res.baseSpace = func2.baseSpace
      # end if 

      res.intorder = max(func1.intorder,func2.intorder)
      res.funcid   = res.baseSpace.addNewOperation()

      res.baseFunc = func1.baseFunc.copy()

      # Add only unique base functions, i.e., do not duplicate.
      for base in func2.baseFunc:
        if base not in res.baseFunc:
          res.baseFunc.append(base)
        # end if 
      # end for 

      # Add itself to the list of baseFunctions
      res.baseFunc.append(res)

      # Organize the operation matrix
      
      # case 1: operation result +/- operation result
      if func1.nature == feNatOperRes and func2.nature == feNatOperRes:

        # append both operation matrices
        res.Koper = func1.Koper.copy()
        res.Koper = np.append(res.Koper,func2.Koper,axis=0)
        
        # add new operation to the operations
        res.Koper = np.append(res.Koper,\
                             [[operId,res.funcid,func1.funcid,func2.funcid]],\
                              axis = 0)

        # initialize the other two operation matrices as void.
        res.foper = np.array([],dtype=np.int64)
        res.essentialOper = np.array([],dtype=np.int64)
        res.nature = feNatOperRes

      # case 2: post integral +/- post integral
      elif func1.nature == feNatPostIntK and func2.nature == feNatPostIntK:

        # The base space is that of the greatest order
        if func1.baseSpace.elType.order > func2.baseSpace.elType.order:
          res.baseSpace = func1.baseSpace
        else:
          res.baseSpace = func2.baseSpace
        # end if 

        res.intorder = max(func1.intorder,func2.intorder)
        res.funcid   = res.baseSpace.addNewOperation()

        res.baseFunc = func1.baseFunc.copy()

        # Add only unique base functions, i.e., do not duplicate.
        for base in func2.baseFunc:
          if base not in res.baseFunc:
            res.baseFunc.append(base)
          # end if 
        # end for 

        # Add itself to the list of baseFunctions
        res.baseFunc.append(res)
        
        # add new operation to the operation matrix
        if func1.foper.ndim != 1 and func2.foper.ndim != 1:
          
          # append both foper matrices
          res.foper = np.append(func1.foper,func2.foper, axis = 0)
        
        elif func1.foper.ndim == 1 and func2.foper.ndim != 1:

          res.foper = func2.foper.copy()

        elif func1.foper.ndim != 1 and func2.foper.ndim == 1:

          res.foper = func1.foper.copy()

        else: 
          
          res.foper = func1.foper.copy()

        # end if 


        # add new operation to the operation matrix
        if func1.Koper.ndim != 1 and func2.Koper.ndim != 1:
          
          # append both Koper matrices
          res.Koper = np.append(func1.Koper,func2.Koper, axis = 0)
        
        elif func1.Koper.ndim == 1 and func2.Koper.ndim != 1:

          res.Koper = func2.Koper.copy()

        elif func1.Koper.ndim != 1 and func2.Koper.ndim == 1:

          res.Koper = func1.Koper.copy()

        else: 
          
          res.Koper = func1.Koper.copy()

        # end if 

        
        # add new operation to the operation matrix
        if func1.essentialOper.ndim != 1 and func2.essentialOper.ndim != 1:
          
          # append both essentialOper matrices
          res.essentialOper = np.append(func1.essentialOper,func2.essentialOper, axis = 0)
        
        elif func1.essentialOper.ndim == 1 and func2.essentialOper.ndim != 1:

          res.essentialOper = func2.essentialOper.copy()

        elif func1.essentialOper.ndim != 1 and func2.essentialOper.ndim == 1:

          res.essentialOper = func1.essentialOper.copy()

        else: 
          
          res.essentialOper = func1.essentialOper.copy()

        # end if 
        

        res.nature = feNatPostIntK

      # elif func1.nature == feNatTest and func2.nature == feNatPostIntF:

      # elif func1.nature == feNatPostIntF and func2.nature == feNatTest:

      # elif func1.nature == feNatPostIntF and func2.nature == feNatPostIntF:


      elif func1.nature == feNatTest and func2.nature == feNatTest:

        # append both operation matrices
        res.foper = func1.foper.copy()
        res.foper = np.append(res.foper,func2.foper, axis = 0)

        # add new operation to the operations
        res.foper = np.append(res.foper, \
                              [[operId,res.funcid,func1.funcid,func2.funcid]],\
                              axis = 0)

        # initialize the other two operation matrices as void.
        res.Koper = np.array([],dtype=np.int64)
        
        res.essentialOper = func1.essentialOper.copy()
        res.essentialOper = np.append(res.essentialOper, func2.essentialOper, axis = 0)
        # add new operation to the operations
        res.essentialOper = np.append(res.essentialOper, \
                              [[operId,res.funcid,func1.funcid,func2.funcid]],\
                              axis = 0)

        res.nature = feNatTest

      else:

        raise ValueError("Can't operate the functions.")

      # end if 

      res.shape = []
      res.shapeBounds = [[],[],[]]
      res.position=[0]


    # % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % %
    # % % % % % % % % % % % % % % %       DOMAIN INTEGRAL     % % % % % % % % % % % % % % % %
    # % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % %
    elif operId == opInt3d:   # integral over domain

        res.baseSpace = func1.baseSpace
        
        res.intorder = func1.intorder
        res.funcid   = res.baseSpace.addNewOperation()

        res.baseFunc = func1.baseFunc.copy()
        
        # Add itself to the list of baseFunctions
        res.baseFunc.append(res)

        if func1.nature == feNatTest:

          # append both foper matrices
          res.foper = func1.foper.copy()

          # append both Koper matrices
          res.Koper = np.array([],dtype=np.int64)

          # add new operation to the operation matrix
          res.foper = np.append(res.foper,\
                               [[operId,res.funcid,func1.funcid,0]],\
                                axis = 0)

          # initialize the other two operation matrices as void.
          res.essentialOper = np.array([],dtype=np.int64)

        elif func1.nature == feNatOperRes:

          # append both foper matrices
          res.foper = np.array([],dtype=np.int64)

          # append both Koper matrices
          res.Koper = func1.Koper.copy()

          # add new operation to the operation matrix
          res.Koper = np.append(res.Koper,\
                               [[operId,res.funcid,func1.funcid,0]],\
                                axis = 0)

          # initialize the other two operation matrices as void.
          res.essentialOper = np.array([],dtype=np.int64)

        else:

          raise ValueError("Domain integral only supports natures "+\
            str(feNatTest)+" or "+str(feNatOperRes)+".")

        # end if 
        # TODO: ADD INDICATION TO THE INTEGRATION REGION!
        res.nature   = feNatPostIntK 
        res.shape    = []
        res.shapeBounds = [[],[],[]]
        res.position = [0]


    # % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % %
    # % % % % % % % % % % % % % % %      BOUNDARY  INTEGRAL     % % % % % % % % % % % % % % %
    # % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % %
    elif operId == opInt2d:   # integral over boundary

      res.baseSpace = func1.baseSpace
      
      res.intorder = func1.intorder
      res.funcid   = res.baseSpace.addNewOperation()

      res.baseFunc = func1.baseFunc.copy()
      
      # Add itself to the list of baseFunctions
      res.baseFunc.append(res)

      if func1.nature == feNatTest:

        # append both Koper matrices
        res.Koper = np.array([],dtype=np.int64)

        # add new operation to the operation matrix
        res.foper = np.array([],dtype=np.int64)

        res.essentialOper = func1.essentialOper.copy()

        # add new operation to the operation matrix
        
        res.essentialOper = np.append(res.essentialOper,\
                             [[operId,res.funcid,func1.funcid,func2.funcid]],\
                              axis = 0)

      elif func1.nature == feNatOperRes:

        # append both Koper matrices
        res.Koper = np.array([],dtype=np.int64)

        # add new operation to the operation matrix
        res.foper = np.array([],dtype=np.int64)

        res.essentialOper = func1.essentialOper.copy()

        # add new operation to the operation matrix
        
        res.essentialOper = np.append(res.essentialOper,\
                             [[operId,res.funcid,func1.funcid,func2.funcid]],\
                              axis = 0)
      
      else:

        raise ValueError("Boundary integral only supports natures "+\
            str(feNatTest)+" or "+str(feNatOperRes)+".")

      # end if 

      # TODO: ADD INDICATION TO THE INTEGRATION REGION!
      res.nature = feNatPostIntK
      res.shape  = []
      res.shapeBounds = [[],[],[]]
      res.position=[0]


    # % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % %
    # % % % % % % % % % % % % % % %    BOUNDARY CONDITION     % % % % % % % % % % % % % % % %
    # % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % %
    elif operId == opOn:   # Boundary value condition.

      res.baseSpace = func1.baseSpace
      
      res.intorder = func1.intorder
      res.funcid   = res.baseSpace.addNewOperation()

      res.baseFunc = func1.baseFunc.copy()
      
      # Add itself to the list of baseFunctions
      res.baseFunc.append(res)

      # append both foper matrices
      res.foper = func1.foper.copy()

      # append both Koper matrices
      res.Koper = np.array([],dtype=np.int64)

      # add new operation to the operation matrix
      if func1.essentialOper.ndim != 1:
        res.essentialOper = np.append(func1.essentialOper,\
                           [[operId,res.funcid,func1.funcid,func2.funcid]],\
                            axis = 0)
      else:
        res.essentialOper = np.array([[operId,res.funcid,func1.funcid,func2.funcid]],dtype=np.int64)
      # end if 

      # initialize the other two operation matrices as void.
      res.foper = np.array([],dtype=np.int64)


      # TODO: ADD INDICATION TO THE INTEGRATION REGION!
      res.nature = feNatPostIntK
      res.shape =[]
      res.shapeBounds = [[],[],[]]
      res.position = [0] #  Add here the position of the variable that is being defined.

    # % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % %
    # % % % % % % % % % % % % % % % % % % %    NEGATION     % % % % % % % % % % % % % % % % % 
    # % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % %
    elif operId == opNeg:   # Negation operation.

      if func1.nature == feNatDef :
        
        # TODO: Operation between two defined functions that have
        #       different spaces should be performed as an operation
        #       to be done later rather than an operation inplace.

        # Perform the operation
        res = func1.baseSpace.newFunction(-func1.data)

        return res

      # end if 

      res.baseSpace = func1.baseSpace
      
      res.intorder = func1.intorder
      res.funcid   = res.baseSpace.addNewOperation()

      res.baseFunc = func1.baseFunc.copy()
      
      # Add itself to the list of baseFunctions
      res.baseFunc.append(res)

      # append both foper matrices
      res.foper = func1.foper.copy()

      if res.foper.ndim != 1:
        res.foper = np.append(res.foper,\
                           [[operId,res.funcid,func1.funcid,0]],\
                            axis = 0)
      # end if 

      res.Koper = func1.Koper.copy()
      if res.Koper.ndim != 1:
        res.Koper = np.append(res.Koper,\
                           [[operId,res.funcid,func1.funcid,0]],\
                            axis = 0)
      # end if 

      res.essentialOper = func1.essentialOper.copy()
      if res.essentialOper.ndim != 1:
        res.essentialOper = np.append(res.essentialOper,\
                           [[operId,res.funcid,func1.funcid,0]],\
                            axis = 0)
      # end if 


      # TODO: ADD INDICATION TO THE INTEGRATION REGION!
      res.nature = func1.nature
      res.shape = func1.shape.copy()
      res.shapeBounds = func1.shapeBounds.copy()
      res.position = func1.position.copy()


    # % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % %
    # % % % % % % % % % % % % % % % % % % %    DERIV. X     % % % % % % % % % % % % % % % % % 
    # % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % %
    elif operId == opDx or operId == opDy or operId == opDz:   # Derivative with respect to x.

      # For now: Not supported dx( dx(...) )

      res.baseSpace = func1.baseSpace
      
      res.intorder = func1.intorder-1

      if func1.interpDer != basisN:
        raise ValueError("multiple concatenation of derivative operations is "+
                         "currently not supported")

      if   operId == opDx:

        res.interpDer= basisNx 

      elif operId == opDy:

        res.interpDer= basisNy 

      elif operId == opDz:

        res.interpDer= basisNz  

      # end if 

      res.funcid   = res.baseSpace.addNewOperation()

      res.baseFunc = func1.baseFunc.copy()
      
      # Add itself to the list of baseFunctions
      res.baseFunc.append(res)

      # append both foper matrices
      res.foper = func1.foper.copy()

      if res.foper.ndim != 1:
        res.foper = np.append(res.foper,\
                           [[operId,res.funcid,func1.funcid,0]],\
                            axis = 0)
      # end if 

      res.Koper = func1.Koper.copy()
      if res.Koper.ndim != 1:
        res.Koper = np.append(res.Koper,\
                           [[operId,res.funcid,func1.funcid,0]],\
                            axis = 0)
      # end if 

      res.essentialOper = func1.essentialOper.copy()
      if res.essentialOper.ndim != 1:
        res.essentialOper = np.append(res.essentialOper,\
                           [[operId,res.funcid,func1.funcid,0]],\
                            axis = 0)
      # end if 


      # TODO: ADD INDICATION TO THE INTEGRATION REGION!
      res.nature = func1.nature
      res.shape = func1.shape.copy()
      res.shapeBounds = func1.shapeBounds.copy()
      res.position = func1.position.copy()
      
    
    # % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % %
    # % % % % % % % % % % % % % % %        NOT DEFINED        % % % % % % % % % % % % % % % %
    # % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % % %
    else:

      raise ValueError("Operation with id "+ str(operId) + " is not defined.")

    # end if 

    return res
  #---------------------------------------------------------------------------------------------------


  #***************************************************************************************************      
  def reorderBoundOpers(self):
    """
    PORPUSE:  Reorder the boundary operations such that first are done all those related with 
              Dirichlet conditions and newmann conditions

    """
    cdef int64_t start = 0, end = 0, i
    cdef uint64_t iZero_ = 0 

    cdef np.ndarray newBoundOper = np.array([], dtype = np.int64)

    for i in range(self.essentialOper.shape[iZero_]):


      if self.essentialOper[i,iZero_] == opInt2d:

        end = i+1

        # add new operation to the operation matrix
        if newBoundOper.ndim != 1:

          newBoundOper = np.append(self.essentialOper[start:end,:] , \
                                    newBoundOper , \
                                    axis = iZero_)


        else:

          newBoundOper = self.essentialOper[start:end,:]

        # end if 

        start = end

      elif self.essentialOper[i,iZero_] == opOn:

        end = i+1
        # add new operation to the operation matrix
        if newBoundOper.ndim != 1:
          newBoundOper = np.append(newBoundOper , \
                                    self.essentialOper[start:end,:]  , \
                                    axis = iZero_)

        else:

          newBoundOper = self.essentialOper[start:end,:]

        # end if 

        start = end

      # end if 

    # end for 

    self.essentialOper =  newBoundOper

  #---------------------------------------------------------------------------------------------------



  #***************************************************************************************************      
  def __repr__(self):
    
    if self.nature == feNatDef:
    
      out = "<FE function"
      out += " id "+str(self.funcid)
      out += ", Nature "+ str(self.nature)
      out += ", iord "+ str(self.intorder)
      out += ", data:\n"
      out += repr(self.data)
      out += "\n>"
    
    else:
    
      out = "<FE function"
      out += " id "+str(self.funcid)
      out += ", Nature "+ str(self.nature)
      out += ", iord "+ str(self.intorder)
      out += ">"
    
    # end if 

    return out
  #---------------------------------------------------------------------------------------------------


  #***************************************************************************************************
  def __str__(self):
    
    # if self.nature == feNatDef:
    #   out = "<FE function"
    #   out += " id "+str(self.funcid)
    #   out += ", Nature "+ str(self.nature)
    #   out += ", iord "+ str(self.intorder)
    #   out += ", data:\n"
    #   out += str(self.data)
    #   out += "\n>"
    
    # else:
    
    out = "<FE function"
    out += " id "+str(self.funcid)
    out += ", Nature "+ str(self.nature)
    out += ", iord "+ str(self.intorder)
    out += ">"
    
    # end if 

    return out
  #---------------------------------------------------------------------------------------------------


  #***************************************************************************************************
  def __neg__(self):
    
    cdef fefunction res 
    res   = fefunction.newFromOperation(opNeg,self,None)            

    return res
  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  def __add__(self,other):
    
    cdef fefunction res 
    cdef fefunction func1
    cdef fefunction func2
    
    type1 = type(self)
    type2 = type(other)
    
    if type1 == type2:   # Case both are of class fefunction
      
      func1 = self
      func2 = other
      res   = fefunction.newFromOperation(opAdd,func1,func2)

    # end if 
            

    return res
  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  def __sub__(self,other):
    
    return self + (-other)
  #---------------------------------------------------------------------------------------------------


  #***************************************************************************************************
  def __mul__(self,other):
    
    cdef fefunction res 
    cdef fefunction func1
    cdef fefunction func2
    
    type1 = type(self)    
    type2 = type(other)
    
    if type1 == type2:   # Case both are of class fefunction
      
      func1 = self
      func2 = other
      res   = fefunction.newFromOperation(opMul,func1,func2)

    elif type2 == fefunction:
      
      func2 = other
      func1 = func2.baseSpace.newFunction(self)

      res = func1*func2 

    elif type1 == fefunction:

      func1 = self
      func2 = func1.baseSpace.newFunction(other)
      
      res = func1*func2

    else:

      return NotImplemented

    # end if 



    return res
  #---------------------------------------------------------------------------------------------------


  # #***************************************************************************************************
  # def __truediv__(self,other):
    
  #   cdef fevar res 
  #   cdef fevar S
    
  #   type1 = type(self)
  #   type2 = type(other)
    
  #   if type1 == type2: # invalid operation ?
      
  #     S = self
  #     res = fevar(S.base)
  #     res.kind = fem_checkFevarKind(opTruediv,(S.kind,other.kind) )
  #     res.intorder= S.intorder+other.intorder # Check this! ... Is this really possible?

  #     res.pos = S.base.msh.addNewVariable(res.kind)

  #     # S.base.msh.addOper('/', S, other, res)
  #     S.base.msh.addOperNp([opTruediv,    \
  #           S.num,     S.kind,     S.pos, \
  #       other.num, other.kind, other.pos, \
  #         res.num,   res.kind,   res.pos     ])

  #     # Add vars
  #     res.baseVars = list(set(S.baseVars+other.baseVars))

  #   # end if 

  #   return res
  # #---------------------------------------------------------------------------------------------------

  # #***************************************************************************************************
  # def __pow__(self,exp,z):
    
  #   cdef fevar res 
  #   cdef fevar S
    
    
  #   S = self 
  #   res = fevar(S.base)
  #   res.kind = fem_checkFevarKind(opPowr,(S.kind,) )
  #   res.intorder = S.intorder*exp

  #   res.pos = S.base.msh.addNewVariable(res.kind)

  #   # Deprecated:
  #   # S.base.msh.addOperConst('pow', S, exp, res)

  #   S.base.msh.addOperNp([opPowr,                         \
  #     S.num,    S.kind,  S.pos,                           \
  #     S.base.msh.addNewConstant(np.float64(exp), kindReal) , kindReal , \
  #     res.num, res.kind, res.pos])

  #   # Add vars
  #   res.baseVars = self.baseVars.copy()
  #   # TODO: Add to constant arrays.

  #   return res
  # #---------------------------------------------------------------------------------------------------

  # #***************************************************************************************************
  # def set(self,expr):
    
  #   self.data = expr
  #   self.varTyp = constant
  #   type1 = type(expr)
  #   self.baseVars = []

  #   if type1 == sndarray:
      
  #     # TODO: check that the data has correct dimensions.
  #     self.kind = kindOtiArr

  #   elif type1 == sotinum:

  #     self.kind = kindOtiNum

  #   elif type1 in number_types:
      
  #     self.kind = kindReal

  #   # end if 
  # #---------------------------------------------------------------------------------------------------



# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::: END OF CLASS FEFUNCTION ::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::






















































































# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::     CLASS  elBase    ::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
cdef class elBase:
  
  #---------------------------------------------------------------------------------------------------
  #------------------------------------   DEFINITION OF ATTRIBUTES   ---------------------------------
  #---------------------------------------------------------------------------------------------------

  cdef int a
  cdef public uint8_t elorder # Element type order
  cdef elemProps_t elemProps  # Properties of the element.
  cdef public list  boundEls

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  def __init__(self):
    """
    PURPOSE:      Constructor of the base element class. Its main purpose is to 
                  allow a base for every new element definition.


    """
    
    self.a=1

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  def __dealloc__(self):
    """

    PURPOSE:      Destructor of the base element class. 


    """
    # print("trying Dealloc elBase")
    if self.elemProps.isInit:
      c_fem_unInitElement(&self.elemProps)
    # end if 
    # print("finished Dealloc elBase")

  #---------------------------------------------------------------------------------------------------
  
  #***************************************************************************************************
  @staticmethod
  cdef elBase createNewElement(uint64_t nbasis, uint64_t order, int64_t geomBase, \
                               int64_t  kind,   uint8_t  ndim, \
              int64_t (*basis_f)(int64_t,int64_t,darray_t*,void*,darray_t*), list boundEls ):
    """
    PURPOSE:      C-level constructor of the Element class. Use this when adding new element types.

    DESCRIPTION:  Creates and associates an element that can be called from the Problem class.

    PARAMETERS:

      -> nbasis:   Number of basis - Number of degrees of freedom - Number of nodes.

      -> order:    Maximum order of the element.

      -> geomBase: Geometric element type - elLine, elTriangle, etc ...

      -> kind:     Kind of element: Affine - IsoParametric

      -> ndim:     Number of dimensions of the element. (1 -> 1D, 2 -> 2D, 3 -> 3D)

      -> basis_f:  Interpolation function.

      -> boundEls: List of the already defined interpolation functions that define the boundary 
                   interpolation, in the following order.  --> [0D, 1D, 2D]

    RESULT:       
            A new elBase object is created.

    EXAMPLE:

            TriP1 = elBase.createNewElement(3,           \ # Number of basis 
                                            1,           \ # Characteristic order of the polynomials
                                            elTriangle,  \ # Geometric type
                                            elkindiso,   \ # Kind of element 
                                            2,           \ # Number of dimensions
                                            &c_fem_basisFunctions_N_TriangP1_2Diso) # Basis functions.

                  
    """
    #*************************************************************************************************

    # create new empty object:
    cdef elBase newElement = <elBase> elBase.__new__(elBase)
    cdef uint64_t nder = 0

    newElement.elemProps.nbasis   = nbasis
    newElement.elemProps.order    = order
    newElement.elemProps.geomBase = geomBase
    newElement.elemProps.kind     = kind
    newElement.elemProps.ndim     = ndim
    newElement.elemProps.f_basis  = basis_f

    if ndim == 0:

      nder = 1

    elif ndim == 1:

      nder = 3

    elif ndim == 2:

      nder = 6

    elif ndim == 3:

      nder = 10

    # end if

    newElement.elemProps.nder                = nder
    newElement.elemProps.isInit              = 0
    newElement.elemProps.nIntPts             = 0
    newElement.elemProps.p_intPoints.p_data  = NULL
    newElement.elemProps.p_intPoints.ncols   = 0
    newElement.elemProps.p_intPoints.nrows   = 0
    newElement.elemProps.p_intPoints.size    = 0 
    newElement.elemProps.p_intWeights.p_data = NULL
    newElement.elemProps.p_intWeights.ncols  = 0
    newElement.elemProps.p_intWeights.nrows  = 0
    newElement.elemProps.p_intWeights.size   = 0 
    newElement.elemProps.p_evalBasis         = NULL

    # newElement.elemProps.f_init   = &
    # newElement.elemProps.f_unInit = &


    newElement.elorder = order
    newElement.a = 10
    newElement.boundEls = boundEls

    return newElement
  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  cpdef initElement(self, uint64_t order, uint8_t otiorder, uint8_t nDimAnalysis):

    c_fem_initElement( order, otiorder, nDimAnalysis,&self.elemProps)


  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  cpdef uninitElement(self):
    if self.elemProps.isInit == 1:
      c_fem_unInitElement(&self.elemProps)
    # end if 

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  @property
  def intWeights(self):
    """
    PURPOSE:      Get self.elemProps.intWeights

    """
    #*************************************************************************************************

    return  darray_2_numpyArray(&self.elemProps.p_intWeights)

  #---------------------------------------------------------------------------------------------------


  #***************************************************************************************************
  @property
  def intPoints(self):
    """
    PURPOSE:      Get self.elemProps.intPoints

    """
    #*************************************************************************************************

    return darray_2_numpyArray(&self.elemProps.p_intPoints)

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  @property
  def nIntPts(self):
    """
    PURPOSE:      Get self.elemProps.nIntPts

    """
    #*************************************************************************************************

    return self.elemProps.nIntPts

  #---------------------------------------------------------------------------------------------------


  #***************************************************************************************************
  @property
  def nder(self):
    """
    PURPOSE:      Get self.elemProps.nder

    """
    #*************************************************************************************************

    return self.elemProps.nder

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  @property
  def nIntPts(self):
    """
    PURPOSE:      Get self.elemProps.nIntPts

    """
    #*************************************************************************************************

    return self.elemProps.nIntPts

  #---------------------------------------------------------------------------------------------------



  #***************************************************************************************************
  @property
  def isInit(self):
    """
    PURPOSE:      Get self.elemProps.isInit

    """
    #*************************************************************************************************

    return self.elemProps.isInit

  #---------------------------------------------------------------------------------------------------



  #***************************************************************************************************
  @property
  def nbasis(self):
    """
    PURPOSE:      Get self.elemProps.nbasis

    """
    #*************************************************************************************************

    return self.elemProps.nbasis

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  @property
  def order(self):
    """
    PURPOSE:      Get self.elemProps.order

    """
    #*************************************************************************************************

    return self.elemProps.order

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  @property
  def geomBase(self):
    """
    PURPOSE:      Get self.elemProps.geomBase

    """
    #*************************************************************************************************

    return self.elemProps.geomBase

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  @property
  def kind(self):
    """
    PURPOSE:      Get self.elemProps.kind

    """
    #*************************************************************************************************

    return self.elemProps.kind

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  @property
  def ndim(self):
    """
    PURPOSE:      Get self.elemProps.ndim

    """
    #*************************************************************************************************

    return self.elemProps.ndim

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  cdef sndarray Ke(self,sndarray coords, np.ndarray connect, other):
    """
    PURPOSE:      Given the nodal coordinates, etc, calculate the elemental stiffness matrix for this
                  problem.
                  
    """
    cdef sndarray res = spzeros((1,1))
    return res
  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  cdef sndarray fe(self,sndarray coords, np.ndarray connect, other):
    """
    PURPOSE:      Given the nodal coordinates, etc, calculate the elemental force vector a 
                  problem.
                  
    """
    


    cdef sndarray res = spzeros((1,1))
    return res
  #---------------------------------------------------------------------------------------------------



# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# :::::::::::::::::::::::::::::::::::: END OF CLASS elBase :::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::









































































































































































# ----------------------------------------------------------------------------------------------------
# ---------------------------------------    CONSTANTS    --------------------------------------------
# ----------------------------------------------------------------------------------------------------


opNames = [ "None  ","   +  ","   -  ","   *  ","   /  ","  **  ","int1d ","int2d ",
            "int3d ","  dx  ","  dy  ","  dz  ","  dxx ","  dyy ",
            "  dzz ","  dxy ","  dxz ","  dyz ","  def "]

basisNames = ["N  ","Nx ","Ny ","Nz ","Nxx",
              "Nyy","Nzz","Nxy","Nxz","Nyz"]

kindNames = ["OTIARR","OTINUM","REAL  "]

elTypeNames = ["point","line","triangle","quadrangle","tetrahedra","hexahedra"]



PntP0 = elBase.createNewElement(1,            # Number of basis 
                                0,            # Characteristic order of the polynomials
                                elNode,       # Geometric type
                                elkindIso,    # Kind of element 
                                0,            # Number of dimensions
                                &c_fem_basisFunctions_N_PntP0_0Diso, # Basis functions.
                                [] ) # List of boundary element interpolators

LineP1 = elBase.createNewElement(2,            # Number of basis 
                                 1,            # Characteristic order of the polynomials
                                 elLine,       # Geometric type
                                 elkindIso,    # Kind of element 
                                 1,            # Number of dimensions
                                 &c_fem_basisFunctions_N_LineP1_1Diso, # Basis functions.
                                 [PntP0] ) # List of boundary element interpolators


LineP2 = elBase.createNewElement(3,            # Number of basis 
                                 2,            # Characteristic order of the polynomials
                                 elLine,       # Geometric type
                                 elkindIso,    # Kind of element 
                                 1,            # Number of dimensions
                                 &c_fem_basisFunctions_N_LineP2_1Diso, # Basis functions.
                                 [PntP0] ) # List of boundary element interpolators


# TriP0 = elBase.createNewElement(1,            # Number of basis 
#                                 0,            # Characteristic order of the polynomials
#                                 elTriangle,   # Geometric type
#                                 elkindIso,    # Kind of element 
#                                 2,            # Number of dimensions
#                                 &c_fem_basisFunctions_N_TriangP0_2Diso , # Basis functions.
#                                  [PntP0] ) # List of boundary element interpolators


TriP1 = elBase.createNewElement(3,            # Number of basis 
                                1,            # Characteristic order of the polynomials
                                elTriangle,   # Geometric type
                                elkindIso,    # Kind of element 
                                2,            # Number of dimensions
                                &c_fem_basisFunctions_N_TriangP1_2Diso, # Basis functions.
                                [PntP0,LineP1] ) # List of boundary element interpolators


TriP2 = elBase.createNewElement(6,            # Number of basis 
                                2,            # Characteristic order of the polynomials
                                elTriangle,   # Geometric type
                                elkindIso,    # Kind of element 
                                2,            # Number of dimensions
                                &c_fem_basisFunctions_N_TriangP2_2Diso, # Basis functions.
                                [PntP0,LineP2] ) # List of boundary element interpolators


QuadP1 = elBase.createNewElement(4,            # Number of basis 
                                 1,            # Characteristic order of the polynomials
                                 elQuadrangle, # Geometric type
                                 elkindIso,    # Kind of element 
                                 2,            # Number of dimensions
                                 &c_fem_basisFunctions_N_QuadP1_2Diso, # Basis functions.
                                 [PntP0,LineP1] ) # List of boundary element interpolators


QuadSerP2 = elBase.createNewElement(8,            # Number of basis 
                                    2,            # Characteristic order of the polynomials or 2?
                                    elQuadrangle, # Geometric type
                                    elkindIso,    # Kind of element 
                                    2,            # Number of dimensions
                                    &c_fem_basisFunctions_N_QuadSerendP2_2Diso, # Basis functions.
                                    [PntP0,LineP2] ) # List of boundary element interpolators


# ----------------------------------------------------------------------------------------------------
























































# ----------------------------------------------------------------------------------------------------
# -------------------------------------    AUX FUNCTIONS    ------------------------------------------
# ----------------------------------------------------------------------------------------------------


#*****************************************************************************************************
cpdef intOmega(fefunction func1, region = -1):
  """ 
  PURPOSE: Domain integral

  """

  cdef fefunction res 
  cdef fefunction func2 =  <fefunction> fefunction.__new__(fefunction)
  cdef int64_t regionIdNum

  res   = fefunction.newFromOperation(opInt3d,func1,func2)

  type1 = type(region)

  if type1 == str:
    regionIdNum = res.baseSpace.mesh.nameIds[region]
  else:
    regionIdNum = region
  # end if 

  res.data = region

  return res
#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cpdef intGamma( boundaryId, fefunction func1 ):
  """ 
  PURPOSE: Boundary integral

  """

  cdef fefunction res 
  cdef fefunction func2 =  <fefunction> fefunction.__new__(fefunction)
  cdef int64_t boundIdNum
  
  res   = fefunction.newFromOperation(opInt2d,func1,func2)

  type1 = type(boundaryId)
  
  if type1 == str:
    boundIdNum = res.baseSpace.mesh.nameIds[boundaryId]
  else:
    boundIdNum = boundaryId
  # end if 

  res.data = boundIdNum

  return res
#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cpdef on(boundaryId, fefunction func1, in2): # define Dirichlet boundary conditions.
  """
  PURPOSE: Define essential (Dirichlet) boundary conditions for a finite element problem.

  INPUTS: 

    -> func1:   Undefined variable that will be set in the boundaries

    -> in2:   Value at the boundary. This, for now, is only defined by defined FE function class.


  """

  cdef fefunction res, func2
  cdef int64_t boundIdNum 

  type1 = type(boundaryId)
  type2 = type(in2)

  if type2 == fefunction:
    func2 = in2
  else:
    func2 = func1.baseSpace.newFunction(in2)
  # end if 

  res   = fefunction.newFromOperation(opOn,func2,func1)
    
  if type1 == str:
    boundIdNum = res.baseSpace.mesh.nameIds[boundaryId]
  else:
    boundIdNum = boundaryId
  # end if 

  res.data = boundIdNum

  return res

#-----------------------------------------------------------------------------------------------------


#*****************************************************************************************************
cpdef dx(fefunction func1):
  """
  PURPOSE: Define derivative of a Finite Element function.

  INPUTS: 

    -> func1:   Finite element function that will be derived.

  """ 

  cdef fefunction res 

  res   = fefunction.newFromOperation(opDx,func1,None)

  return res
#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cpdef dy(fefunction func1):
  """
  PURPOSE: Define derivative of a Finite Element function.

  INPUTS: 

    -> func1:   Finite element function that will be derived.

  """ 

  cdef fefunction res 

  res   = fefunction.newFromOperation(opDy,func1,None)

  return res
#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cpdef dz(fefunction func1):
  """
  PURPOSE: Define derivative of a Finite Element function.

  INPUTS: 

    -> func1:   Finite element function that will be derived.

  """ 

  cdef fefunction res 

  res   = fefunction.newFromOperation(opDz,func1,None)

  return res
#-----------------------------------------------------------------------------------------------------







#*****************************************************************************************************
cdef np.ndarray darray_2_numpyArray(darray_t* array ):
  """
    
  PURPOSE:      Convert a darray_t to numpy array for test purposes.

  """
  cdef np.ndarray nparray
  cdef double tmp
  cdef uint64_t i, j

  nparray = np.empty((array[0].nrows,array[0].ncols),dtype = np.float64)

  for i in range(array[0].nrows):
    
    for j in range(array[0].ncols):

      c_darray_getItem(array,i,j,&tmp)
      nparray[i,j] = tmp 

    # end for

  # end for

  return nparray

#-----------------------------------------------------------------------------------------------------




#*****************************************************************************************************
def fem_integrationPointsWeights(uint64_t order, int64_t elementType):
  """
  PURPOSE:     Test to check if the integration points and weights are good.
  """
  cdef darray_t coords, weights
  cdef np.ndarray np_coords, np_weights
  c_fem_integrationPoints(order, elementType, &coords, &weights)
  np_coords = darray_2_numpyArray(&coords )
  np_weights = darray_2_numpyArray(&weights )


  # Free arrays
  c_darray_free(&coords)
  c_darray_free(&weights)

  return (np_coords, np_weights)
#-----------------------------------------------------------------------------------------------------






#*****************************************************************************************************
def fem_readOperMat(mesh meshObj, np.ndarray mat):
  """
  DESCRIPTION:  Function to convert to a human readable format the operation stack produced 
                by operating finite element Variables.



  """
  cdef uint64_t i,j
  cdef uint64_t shape0 = mat.shape[0]
  out = ""
  space = " "
  # opNames
  for i in range(shape0):

    out += opNames[mat[i,0]]
    out += space
    
    if mat[i,0] <= np.uint64(opTruediv):
      
      # print(" In basic operations")

      # out += str(meshObj.elements[mat[i,1]])
      out += kindNames[mat[i,2]]
      out += space+str(mat[i,3])
      out += ' with '
      # out += str(meshObj.elements[mat[i,4]])
      out += kindNames[mat[i,5]]
      out += space+str(mat[i,6])
      out += ' in '
      # out += str(meshObj.elements[mat[i,7]])
      out += kindNames[mat[i,8]]
      out += space+str(mat[i,9])

    elif mat[i,0] == opDef:
      
      # print(" In definition operation")
      # out += kindNames[mat[i,5]]
      # out += space+str(mat[i,6])
      out += kindNames[mat[i,3]]
      out += space+str(mat[i,4])
      out += " as "
      j = mat[i,1]-basisN
      out += basisNames[j]
      
      

    elif mat[i,0] == opPowr: # Power function

      # print(" In power operation")
      # out += str(meshObj.elements[mat[i,1]])
      out += kindNames[mat[i,2]]
      out += space+str(mat[i,3])
      out += " by exp "
      out += str(meshObj.constObj[mat[i,5]][mat[i,4]])

    elif mat[i,0] <= opInt3d: # integrals

      # print(" In Integration operation")
      # out += "variable "
      # out += str(meshObj.elements[mat[i,2]])
      out += kindNames[mat[i,3]]
      out += space+str(mat[i,4])
      out += ' in '
      # out += str(meshObj.elements[mat[i,5]])
      out += kindNames[mat[i,6]]
      out += space+str(mat[i,7])

    out += '\n'

  print(out)
  # return out
#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cpdef int64_t fem_getDataKind(object data):
  """
  PURPOSE:     Get the kind of data 

  """
  cdef int64_t res
  if type(data) == sndarray:
        
    res = kindFunc      # kind of function.

  elif type(data) == sotinum:
        
    res = kindScalar

  elif type(data) in number_types:
        
    res = kindReal

  else:

     raise ValueError("Undefined data kind. ")

  # end if

  return res
#-----------------------------------------------------------------------------------------------------




#*****************************************************************************************************
cpdef list fem_getOffset(list position,list solFunc,list testFunc,np.ndarray eDOF_per_sol):
  """
  PURPOSE:     Get the equivalent offset of the starting position 

  """
  cdef list eqPos = fem_getEqvPosition( position, solFunc, testFunc)
  cdef list res = [0,0]
  cdef uint64_t zero = 0, one = 1
    
  res[zero] = eDOF_per_sol[eqPos[zero]]

  res[one] = eDOF_per_sol[eqPos[one]]

  return res

#-----------------------------------------------------------------------------------------------------




#*****************************************************************************************************
cpdef list fem_getEqvPosition(list position,list solFunc,list testFunc):
  """
  PURPOSE:    Convert a position given by function ids, into problem local coordinates.

  """
  cdef int64_t i,j
  cdef uint64_t res, funcId, funcId2
  cdef fefunction func

  if len(position)==1:
    
    funcId = position[0]

    if funcId == 0:
      return [0,0]
    # end if 

    for i in range(len(solFunc)):
      func = solFunc[i]
      if func.funcid == funcId:
        return [i,0]
      # end if 
    # end for

    for i in range(len(testFunc)):
      func = testFunc[i]
      if func.funcid == funcId:
        return [i,0]
      # end if 
    # end for
    print("Position before error: ", position)
    raise ValueError("Position defined with respect to a variable that is not in the problem functions!")

  else:
    
    funcId = position[0]
    funcId2= position[1]

    for j in range(len(solFunc)):
      func = solFunc[j]
      if func.funcid == funcId2:
        break
      # end if 
    # end for

    for i in range(len(testFunc)):
      func = testFunc[i]
      if func.funcid == funcId:
        break
      # end if 
    # end for
    return [i, j]
  # end if


#-----------------------------------------------------------------------------------------------------


#*****************************************************************************************************
cpdef uint64_t fem_getEqvPositionIndx(list position,list solFunc,list testFunc):
  """
  PURPOSE:    Convert a position given by function ids, into problem local coordinates.

  """
  #***************************************************************************************************

  cdef int64_t i,j
  cdef uint64_t res, funcId, funcId2
  cdef fefunction func

  if len(position)==1:
    funcId = position[0]
    for i in range(len(solFunc)):
      func = solFunc[i]
      if func.funcid == funcId:
        return i
      # end if 
    # end for

    for i in range(len(testFunc)):
      func = solFunc[i]
      if func.funcid == funcId:
        return i
      # end if 
    # end for
    
    raise ValueError("Position defined with respect to a variable that is not in the problem functions!")
  else:
    funcId = position[0]
    funcId2= position[1]
    for j in range(len(solFunc)):
      func = solFunc[j]
      if func.funcid == funcId2:
        break
      # end if 
    # end for

    for i in range(len(testFunc)):
      func = testFunc[i]
      if func.funcid == funcId:
        break
      # end if 
    # end for
    return i*len(testFunc)+ j
  # end if


#-----------------------------------------------------------------------------------------------------


#*****************************************************************************************************
cpdef list fem_getOrderedFuncList(list funcList):
  """
  PURPOSE:    Generate a list of operations such that the elements match one-to-one with the 
              function ids of the element's list.

  """
  #***************************************************************************************************

  cdef fefunction func = funcList[len(funcList)-1]
  cdef list res = [None]*int(func.funcid+1)
  cdef int64_t i
  
  for i in range(len(funcList)):
    func = funcList[i]
    res[func.funcid]=func
  # end for

  return res
#-----------------------------------------------------------------------------------------------------







#*****************************************************************************************************
cdef str c_fem_get_enum_string(int64_t enumId):
  """
  PURPOSE:    Returns a string with the name of the corresponding enum value given.

  """
  #***************************************************************************************************

  if enumId == opAdd        :
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
  elif enumId == constant     :
    return "constant     "
  elif enumId == variable     :
    return "variable     "
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


#***************************************************************************************************** 
cdef str c_darray_print(darray_t* array):
  """
  PURPOSE:  To print a representation of the sotiarray object that could be
            used to create new dualnum objects, in a compact form.

  
  """
  #***************************************************************************************************
  
  cdef uint64_t i,j
  cdef double tmp
  cdef str coef, head, body, tail

  head = 'darray('
  body = '['

  for i in range(array[0].nrows):
    if i!=0:
      body+="        "
    # end if 
    body+='['

    for j in range(array[0].ncols):
      
      body += " "
      

      c_darray_getItem(array,i,j,&tmp)
      
      coef = "%+.4f"%tmp
      
      if coef[0] == '+':
        
        body+= " "+coef[1:]

      else:

        body += coef

      # end if 
      
      body+=","
    
    # end for 
    body = body[:len(body)-1]
    body += "],\n"

  # end for 
      
  body  = body[:len(body)-2]
  body += "]"
  body += ' shape = ('+str(array[0].nrows)+','+str(array[0].ncols)+") "

  tail = " )\n"

  return (head + body + tail)

#-----------------------------------------------------------------------------------------------------

#***************************************************************************************************** 
cdef str c_elemprops_print(elemProps_t* array,style = 1):
  """
  PURPOSE:  To print a representation of the sotiarray object that could be
            used to create new dualnum objects, in a compact form.

  
  """
  #***************************************************************************************************
  
  cdef uint64_t i


  head   ='Element Definition:\n'
  body  = "   - nbasis:       "+str(array[0].nbasis  )+ ",\n"
  body += "   - order:        "+str(array[0].order   )+ ",\n"
  body += "   - geomBase:     "+c_fem_get_enum_string(array[0].geomBase)+ ",\n"
  body += "   - kind:         "+c_fem_get_enum_string(array[0].kind    )+ ",\n"
  body += "   - ndim:         "+str(array[0].ndim    )+ ",\n"
  body += "   - nIntPts:      "+str(array[0].nIntPts )+ ",\n"
  body += "   - nder:         "+str(array[0].nder    )+ ",\n"
  body += "   - isInit:       "+str(array[0].isInit  )+ ",\n"
  body += "   - otiorder:     "+str(array[0].otiorder )+ ",\n"
  body += "   - nDimAnalysis: "+str(array[0].nDimAnalysis )+ ",\n"
  
  body += "   - integration points:"+ "\n"
  
  body += c_darray_print(&array[0].p_intPoints)

  body += "   - Integration weights:"+ "\n"

  body += c_darray_print(&array[0].p_intWeights)
  

  body += "   - Evaluated basis functions: "+ "\n"

  for i in range(array[0].nder):

    body += "    "+ c_fem_get_enum_string(derN+i)+":\n"
    body += c_darray_print(&array[0].p_evalBasis[i])
    body += "\n"  

  # end for   
  
  tail = ""
  return (head + body + tail)

#-----------------------------------------------------------------------------------------------------

#***************************************************************************************************** 
cdef str c_femarray_print(femarray_t* array,style = 1):
  """
  PURPOSE:  To print a representation of the sotiarray object that could be
            used to create new dualnum objects, in a compact form.

  
  """
  #***************************************************************************************************
  
  cdef uint64_t i


  head   = 'femarray( order = '+str(array[0].order)+ ", "
  
  body   = 'shape = ('+str(array[0].nrows)+','+str(array[0].ncols)+"), "
  body  += 'offset = ('+str(array[0].offsetx)+','+str(array[0].offsety)+"), "
  body  += 'data:\n'

  for i in range(array[0].nIntPts):
    body += "int point "+ str(i)+"\n"
    body += c_sotiarray_print(&array[0].p_data[i])
    body += "\n"  
  # end for 
  
  tail = " )"
  return (head + body + tail)

#-----------------------------------------------------------------------------------------------------

#***************************************************************************************************** 
cdef str c_elemprops_print_perElement(elemProps_t* array,style = 1):
  """
  PURPOSE:  To print a representation of the sotiarray object that could be
            used to create new dualnum objects, in a compact form.

  
  """
  #***************************************************************************************************
  
  cdef uint64_t i


  head   ='Per Element Properties of '+c_fem_get_enum_string(array[0].geomBase)
  head  +=" of order " + str(array[0].order)+'\n'  
  body = "   - Jacobian:"+ "\n"
  body += c_femarray_print(&array[0].J)

  body += "\n   - Jacobian Inverse:"+ "\n"  
  body += c_femarray_print(&array[0].Jinv)

  body += "\n   - Jacobian Determinant:"+ "\n"
  body += c_femarray_print(&array[0].Jdet)

  body += "\n   - Integration weights times Jacobian:"+ "\n"
  body += c_femarray_print(&array[0].p_detWeights)
  

  body += "\n   - spacial defined basis functions: "+ "\n"

  for i in range(array[0].nder):

    body += "    "+ c_fem_get_enum_string(basisN+i)+" at "+hex(<uint64_t>&array[0].p_basis[i])+":\n"
    body += c_femarray_print(&array[0].p_basis[i])
    body += "\n"  

  # end for   
  
  tail = ""
  return (head + body + tail)

#-----------------------------------------------------------------------------------------------------



