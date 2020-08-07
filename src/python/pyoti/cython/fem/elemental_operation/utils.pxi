



# #*****************************************************************************************************
# cpdef intOmega(fefunction func1, region = -1):
#   """ 
#   PURPOSE: Domain integral

#   """

#   cdef fefunction res 
#   cdef fefunction func2 =  <fefunction> fefunction.__new__(fefunction)
#   cdef int64_t regionIdNum

#   res   = fefunction.newFromOperation(opInt3d,func1,func2)

#   type1 = type(region)

#   if type1 == str:
#     regionIdNum = res.baseSpace.mesh.nameIds[region]
#   else:
#     regionIdNum = region
#   # end if 

#   res.data = region

#   return res
# #-----------------------------------------------------------------------------------------------------

# #*****************************************************************************************************
# cpdef intGamma( boundaryId, fefunction func1 ):
#   """ 
#   PURPOSE: Boundary integral

#   """

#   cdef fefunction res 
#   cdef fefunction func2 =  <fefunction> fefunction.__new__(fefunction)
#   cdef int64_t boundIdNum
  
#   res   = fefunction.newFromOperation(opInt2d,func1,func2)

#   type1 = type(boundaryId)
  
#   if type1 == str:
#     boundIdNum = res.baseSpace.mesh.nameIds[boundaryId]
#   else:
#     boundIdNum = boundaryId
#   # end if 

#   res.data = boundIdNum

#   return res
# #-----------------------------------------------------------------------------------------------------

# #*****************************************************************************************************
# cpdef on(boundaryId, fefunction func1, in2): # define Dirichlet boundary conditions.
#   """
#   PURPOSE: Define essential (Dirichlet) boundary conditions for a finite element problem.

#   INPUTS: 

#     -> func1:   Undefined variable that will be set in the boundaries

#     -> in2:   Value at the boundary. This, for now, is only defined by defined FE function class.


#   """

#   cdef fefunction res, func2
#   cdef int64_t boundIdNum 

#   type1 = type(boundaryId)
#   type2 = type(in2)

#   if type2 == fefunction:
#     func2 = in2
#   else:
#     func2 = func1.baseSpace.newFunction(in2)
#   # end if 

#   res   = fefunction.newFromOperation(opOn,func2,func1)
    
#   if type1 == str:
#     boundIdNum = res.baseSpace.mesh.nameIds[boundaryId]
#   else:
#     boundIdNum = boundaryId
#   # end if 

#   res.data = boundIdNum

#   return res

# #-----------------------------------------------------------------------------------------------------


#*****************************************************************************************************
cpdef dx(object func1):
  """
  PURPOSE: Define derivative of a Finite Element operation.

  INPUTS:  

    -> func1:   Finite element function that will be derived.

  """ 

  cdef elemental_operation res 

  tfunc1 = type(func1)

  if tfunc1 == elemental_operation:
    res = __create_opDxx__(opDx,func1)
  elif tfunc1 == matso:
    tmp = __create_opDef__(opDefData, baseSpace = None, basis = basisNx, data = func1)
    res = __create_opDxx__(opDx,tmp)
    # raise ValueError("Derivative of defined function is not yet supported.")
  # end if

  return res

#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cpdef dy(object func1):
  """
  PURPOSE: Define derivative of a Finite Element operation.

  INPUTS:  

    -> func1:   Finite element function that will be derived.

  """ 

  cdef elemental_operation res 

  tfunc1 = type(func1)

  if tfunc1 == elemental_operation:
    res = __create_opDxx__(opDy,func1)
  elif tfunc1 == matso:
    tmp = __create_opDef__(opDefData, baseSpace = None, basis = basisNy, data = func1)
    res = __create_opDxx__(opDy,tmp)
    # raise ValueError("Derivative of defined function is not yet supported.")
  # end if

  return res

#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cpdef dz(object func1):
  """
  PURPOSE: Define derivative of a Finite Element operation.

  INPUTS:  

    -> func1:   Finite element function that will be derived.

  """ 

  cdef elemental_operation res 

  tfunc1 = type(func1)

  if tfunc1 == elemental_operation:
    res = __create_opDxx__(opDz,func1)
  elif tfunc1 == matso:
    tmp = __create_opDef__(opDefData, baseSpace = None, basis = basisNz, data = func1)
    res = __create_opDxx__(opDz,tmp)
    # raise ValueError("Derivative of defined function is not yet supported.")
  # end if

  return res

#-----------------------------------------------------------------------------------------------------

# #*****************************************************************************************************
# cpdef dy(fefunction func1):
#   """
#   PURPOSE: Define derivative of a Finite Element function.

#   INPUTS: 

#     -> func1:   Finite element function that will be derived.

#   """ 

#   cdef fefunction res 

#   res   = fefunction.newFromOperation(opDy,func1,None)

#   return res
# #-----------------------------------------------------------------------------------------------------

# #*****************************************************************************************************
# cpdef dz(fefunction func1):
#   """
#   PURPOSE: Define derivative of a Finite Element function.

#   INPUTS: 

#     -> func1:   Finite element function that will be derived.

#   """ 

#   cdef fefunction res 

#   res   = fefunction.newFromOperation(opDz,func1,None)

#   return res
# #-----------------------------------------------------------------------------------------------------

