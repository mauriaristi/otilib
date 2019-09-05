


from c_otilib cimport *
# from c_otifem cimport *

from pyoti.real   import dmat
from pyoti.real  cimport dmat, darr_2_npy

from pyoti.dense  import omat
from pyoti.dense cimport omat
# from pyoti.otimat  cimport otimat
# from pyoti.ndarray cimport ndarray
# from pyoti.sndarray cimport sndarray

cimport numpy as np

# from pyoti.otimat import otimat





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
  cdef public omat     xcoords      # Nodal coordinates as oti arrays.
  cdef public omat     ycoords      # Nodal coordinates as oti arrays.
  cdef public omat     zcoords      # Nodal coordinates as oti arrays.
  cdef public bases_t  otinbases    # Number of bases of oti numbers.
  cdef public ord_t    otiorder     # order of the oti numbers.
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

  
  cdef uint64_t getBaseDOFs(self)
  cdef uint64_t getDomainVtkCellId(self, dofs)
  cpdef uint64_t getGlobalDOFBound(self,int64_t ndim, fespace space)
  cpdef uint64_t getGlobalDOF(self,fespace space)
  cdef uint64_t addNewOperation(self)
  cdef uint64_t addNewSpace(self,fespace space)


# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# :::::::::::::::::::::::::::::::::::: END OF CLASS OTIMESH ::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::


























  


# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# :::::::::::::::::::::::::::::::::::     CLASS  FESPACE    ::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
cdef class fespace:

  #---------------------------------------------------------------------------------------------------
  #------------------------------------   DEFINITION OF ATTRIBUTES   ---------------------------------
  #---------------------------------------------------------------------------------------------------

  cdef public mesh    mesh        # Triangulation related to this space.
  cdef public elBase  elType     # Element type that defines the interpolation functions.
  cdef public uint8_t fespaceId  # Id of the finite element space in the mesh.

  #---------------------------------------------------------------------------------------------------
  
  cdef uint64_t addNewOperation(self)

# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::: END OF CLASS fespace ::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
















# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# :::::::::::::::::::::::::::::::::     CLASS  FEFUNCTION    :::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
cdef class fefunction:

  #---------------------------------------------------------------------------------------------------
  #------------------------------------   DEFINITION OF ATTRIBUTES   ---------------------------------
  #---------------------------------------------------------------------------------------------------

  cdef public fespace    baseSpace     # Finite element space at which the variable is associated.
  
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

  @staticmethod
  cdef fefunction newFromOperation(int64_t operId, fefunction func1, fefunction func2)

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

  cdef uint8_t FLAG # Defines if the elemen is defined in python or c.
  cdef public uint8_t elorder # Element type order
  cdef elem_t elem  # Properties of the element.
  cdef public list boundEls
  cdef object pyFunct

  #---------------------------------------------------------------------------------------------------

  
  @staticmethod
  cdef elBase createNewElement(uint64_t nbasis, int64_t geomBase, int64_t  kind,   uint8_t  ndim, \
              int64_t (*basis_f)(int64_t,int64_t,darr_t*,void*,darr_t*) nogil, list boundEls )

  cpdef allocate(self, uint64_t intorder)
  cpdef end(self)

  # cpdef initElement(self, uint64_t order, uint8_t otiorder, uint8_t nDimAnalysis)
  # cpdef uninitElement(self)
  # cdef sndarray Ke(self,sndarray coords, np.ndarray connect, other)
  # cdef sndarray fe(self,sndarray coords, np.ndarray connect, other)


# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# :::::::::::::::::::::::::::::::::::: END OF CLASS elBase :::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::






# # ----------------------------------------------------------------------------------------------------
# # -------------------------------------    AUX FUNCTIONS    ------------------------------------------
# # ----------------------------------------------------------------------------------------------------


cpdef intOmega(fefunction func1, region = *)
cpdef intGamma( boundaryId, fefunction func1 )
cpdef on(boundaryId, fefunction func1, in2)
cpdef dx(fefunction func1)
cpdef dy(fefunction func1)
cpdef dz(fefunction func1)
# cdef np.ndarray darray_2_numpyArray(darray_t* array )
# cpdef int64_t fem_getDataKind(object data)
# cpdef list fem_getOffset(list position,list solFunc,list testFunc,np.ndarray eDOF_per_sol)
# cpdef list fem_getEqvPosition(list position,list solFunc,list testFunc)
# cpdef uint64_t fem_getEqvPositionIndx(list position,list solFunc,list testFunc)
# cpdef list fem_getOrderedFuncList(list funcList)
cdef object enum2string(int64_t enumId)
# cdef object c_darray_print(darray_t* array)
# cdef object c_elemprops_print(elemProps_t* array,style = *) 
# cdef object c_femarray_print(femarray_t* array,style = *)
# cdef object c_elemprops_print_perElement(elemProps_t* array,style = *)

# # ----------------------------------------------------------------------------------------------------


