
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# :::::::::::::::::::::::::::::::::     CLASS  FEPROBLEM    ::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
cdef class feproblem:

  #---------------------------------------------------------------------------------------------------
  #------------------------------------   DEFINITION OF ATTRIBUTES   ---------------------------------
  #---------------------------------------------------------------------------------------------------
  
  


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
    self.problem.reorderBoundOpers() # Reorder boundary operations: First "on" then "int2d".
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
    # Loop for each element in the domain.
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


