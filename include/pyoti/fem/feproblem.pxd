


# # ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# # :::::::::::::::::::::::::::::::::     CLASS  FEPROBLEM    ::::::::::::::::::::::::::::::::::::::::::
# # ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# cdef class feproblem:

#   #---------------------------------------------------------------------------------------------------
#   #------------------------------------   DEFINITION OF ATTRIBUTES   ---------------------------------
#   #---------------------------------------------------------------------------------------------------
  
#   # Global variables:
#   cdef public otimat   K     # Stiffness Matrix
#   cdef public otimat   Knobc # Stiffness Matrix before boundary conditions.
#   cdef public ndarray  f     # Force vector
#   cdef public ndarray  fnobc # Force vector before Boundary Conditions.
#   cdef public ndarray  u     # General Solution Vector.
#   cdef public mesh     mesh

#   # Only for usable for the 
#   cdef void** defFunc           # Constant holders for the assembly loop.  
  

#   cdef public uint64_t intorder
#   cdef np.ndarray      derCompFlags

#   # Operations associated with K
#   cdef public list Koper

#   # Operations associated with f
#   cdef public list Foper

#   # Other important things
#   cdef public list      solFunc 
#   cdef public list     testFunc 
#   cdef public list     undefFuncToCheck  # Undefined functions that require to be checked before 
#                                          # assembly.
#   cdef public uint8_t DOF   # Degrees of Freedom.

#   cdef public fefunction problem

#   # Flagging convention
#   cdef public uint64_t flags 

#   cdef public uint64_t m      # Number of variables in the problem 
#     # Conventions:
#     # Bit  0 - Is the system assembled? True - 1  False - 0
#     # Bit  1 - 
#     # Bit  2 - 
#     # Bit  3 - 
#     # Bit  4 - 
#     # Bit  5 - 
#     # Bit  6 - 
#     # Bit  7 - 
#     # Bit  8 - 
#     # Bit  9 - 
#     # Bit 10 - 

#   cdef public uint64_t eDOF              # Elemental degrees of freedom
#   cdef public list     eDOFBound
#   cdef np.ndarray      eDOF_per_sol      # Elemental degrees of freedom per element.
#   cdef public list     eDOF_per_solBound # Elemental degrees of freedom per element Boundary.
#   cdef np.ndarray      nDOF_per_sol      # Global degrees of freedom per element.
#   cdef public list     nDOF_per_solBound
#   cdef public uint64_t globalDOF
#   cdef public list     globalDOFBound
#   cdef np.ndarray      nDOF_global_per_systemDOF
#   cdef public list     nDOF_global_per_systemDOFBound  
#   cdef np.ndarray      eOffset_per_StateVariable
#   cdef public list     eOffset_per_StateVariableBound
#   cdef np.ndarray      eId_per_DOF
#   cdef public list     eId_per_DOFBound
#   cdef uint8_t     boundaryFlag
  

#   cdef public list       functionList 
#   cdef np.ndarray  expandedOperations
#   cdef public uint64_t  tmp_indx # defines the number of temporal elements in the operations.
#   cdef public uint64_t  noper
#   cdef public uint64_t  noperK
#   cdef public uint64_t  noperf
#   cdef public uint64_t  noperBC
#   cdef public uint64_t  noperDirichlet
#   cdef public uint64_t  noperNeumann
#   cdef public uint64_t  ndeffunc
#   cdef public uint64_t nIntPts

#   cdef public list defFuncList
#   cdef uint64_t    nDefFunc
#   cdef uint64_t    nOTIs
#   cdef uint64_t    nReals
#   cdef public list tmpIndx     # Temporal lists.
#   cdef public list tmpIndxFunc # Temporal lists.
#   cdef public list tmpIndxPos  # temporal list
#   cdef public list tmpTypes
#   cdef public list tmpShapesOffsets
#   cdef public list integrables
#   cdef public list uniqueOper

#   cdef public uint8_t order



#   cdef np.ndarray      expOperK
#   cdef np.ndarray      expOperf
#   cdef np.ndarray      expOperBCDir
#   cdef np.ndarray      expOperBCNeu
  

  


#   #---------------------------------------------------------------------------------------------------

  
#   cpdef solve(self)
#   cpdef assembleSystem(self)
#   cdef void c_assembleInGlobalsBound(self, int64_t ndim, sotiarray_t* Ke,  \
#                                       sotiarray_t* fe, np.ndarray elements)

#   cdef void c_assembleInGlobals(self,sotiarray_t* Ke, sotiarray_t* fe, np.ndarray elements)
#   cpdef appendBasicInfo(self,int64_t subOpType, uint64_t funcId, list shape, list position)
#   cpdef expandOperDef(self,fefunction res, fefunction func1)
    
#   cdef expandOperMul(self,fefunction res, fefunction func1,fefunction func2)
#   cdef expandOperNeg(self, fefunction res, fefunction func1)
#   cdef expandOperInt(self, fefunction res, fefunction func1)
#   cdef expandOperAdd(self, fefunction res , fefunction func1, fefunction func2)
#   cpdef expandOperMatrix(self, np.ndarray matrix, uint8_t onlyOn = * )
#   cpdef appendBasicInfoBound(self,int64_t subOpType, uint64_t funcId, list shape, \
#                          list position, int64_t bDim)
#   cpdef expandOperDefBound(self,fefunction res, fefunction func1, int64_t bDim, int64_t bIndx)
#   cdef expandOperNegBound(self, fefunction res, fefunction func1, int64_t bDim)
#   cdef expandOperIntBound(self, fefunction res, fefunction func1)
#   cdef expandOperAddBound(self, fefunction res , fefunction func1, fefunction func2)
#   cdef expandOperMulBound(self,fefunction res, fefunction func1,fefunction func2, int64_t bDim)
#   cdef expandOperOnBound(self, fefunction res, fefunction func1,fefunction func2, int64_t bDim)
#   cpdef expandOperMatrixBound(self, np.ndarray matrix, uint8_t onlyOn = * ) 
#   cdef void setDerFlag(self, int64_t operId)
#   cpdef applyBoundConds(self)


# # ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# # ::::::::::::::::::::::::::::::::::: END OF CLASS FEPROBLEM :::::::::::::::::::::::::::::::::::::::::
# # ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::




