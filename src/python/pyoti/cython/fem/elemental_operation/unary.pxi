#********************************************************************************************************
cdef __create_opDef__(int64_t operId, space baseSpace = None, basis = basisN, data = None):
  """
  PURPOSE: Create elemental operation from derivative call.

  This function creates an UNARY operation from derivative call.

  INPUTS:

    - operId: Operation id, expecting only opDx, opDy, opDz.
    - lhs:    Source operation from which to interpolate the solution. 
              Can come from feUndef or feDef functions
  """
  #******************************************************************************************************
  
  global __varid_counter
  # For now: Not supported dx( dx(...) )
  cdef elemental_operation res = <elemental_operation> elemental_operation.__new__(elemental_operation)
  cdef np.ndarray newOperation 
  


  res.baseSpace  = baseSpace

  if baseSpace is not None:
    res.intorder   = baseSpace.order
  else:
    res.intorder   = 1 # Needs to be corrected afterwards.
  # end if       
  
  if data is None:
    res.op_id = opDef
  else:
    res.op_id = opDefData
  # end if 

  res.var_id   = __varid_counter 
  __varid_counter += 1


  res.data = data

  res.op_graph = np.array( [[res.op_id,res,None]] , dtype = object)

  return res

#--------------------------------------------------------------------------------------------------------



#********************************************************************************************************
cdef __create_opDxx__(int64_t operId, elemental_operation lhs ):
  """
  PURPOSE: Create elemental operation from derivative call.

  This function creates an UNARY operation from derivative call.

  INPUTS:

    - operId: Operation id, expecting only opDx, opDy, opDz.
    - lhs:    Source operation from which to interpolate the solution. 
              Can come from feUndef or feDef functions
  """
  #******************************************************************************************************
  global __varid_counter
  # For now: Not supported dx( dx(...) )
  cdef elemental_operation res = <elemental_operation> elemental_operation.__new__(elemental_operation)
  cdef np.ndarray newOperation 
  
  res.baseSpace  = lhs.baseSpace
  res.intorder   = lhs.intorder-1

  if lhs.var_id == 0:
    raise ValueError("multiple concatenation of derivative operations is "+
                     "currently not supported")
  # end if 

  if   operId == opDx:
    res.op_id= opDx 
  elif operId == opDy:
    res.op_id= opDy 
  elif operId == opDz:
    res.op_id= opDz  
  else:
    raise ValueError("Wrong operation Id for Dxx operation")
  # end if 

  res.var_id   = lhs.var_id

  res.data     = lhs.data

  res.op_graph = np.array( [[res.op_id,res,None]] , dtype = object)

  return res

#--------------------------------------------------------------------------------------------------------

# #********************************************************************************************************
# cdef __create_opNeg__(int64_t operId, elemental_operation lhs ):
#   """
#   PURPOSE: Create elemental operation from negation operation.

#   This function creates an UNARY operation from derivative call.

#   INPUTS:

#     - operId: Operation id, expecting only opDx, opDy, opDz.
#     - lhs:    Source operation from which to interpolate the solution. 
#               Can come from feUndef or feDef functions
#   """
#   #******************************************************************************************************

#   # For now: Not supported dx( dx(...) )
#   cdef elemental_operation res = <elemental_operation> elemental_operation.__new__(elemental_operation)
#   cdef np.ndarray newOperation 
  
#   res.interpDer  = basisN

#   if func1.nature == feNatDef :
  
#   # TODO: Operation between two defined functions that have
#   #       different spaces should be performed as an operation
#   #       to be done later rather than an operation inplace.

#   # Perform the operation
#   res = func1.baseSpace.newFunction(-func1.data)

#   return res

# # end if 

# res.baseSpace = func1.baseSpace

# res.intorder = func1.intorder
# res.funcid   = res.baseSpace.addNewOperation()

# res.baseFunc = func1.baseFunc.copy()

# # Add itself to the list of baseFunctions
# res.baseFunc.append(res)

# # append both foper matrices
# res.foper = func1.foper.copy()

# if res.foper.ndim != 1:
#   res.foper = np.append(res.foper,\
#                      [[operId,res.funcid,func1.funcid,0]],\
#                       axis = 0)
# # end if 

# res.Koper = func1.Koper.copy()
# if res.Koper.ndim != 1:
#   res.Koper = np.append(res.Koper,\
#                      [[operId,res.funcid,func1.funcid,0]],\
#                       axis = 0)
# # end if 

# res.essentialOper = func1.essentialOper.copy()
# if res.essentialOper.ndim != 1:
#   res.essentialOper = np.append(res.essentialOper,\
#                      [[operId,res.funcid,func1.funcid,0]],\
#                       axis = 0)
# # end if 


# # TODO: ADD INDICATION TO THE INTEGRATION REGION!
# res.nature = func1.nature
# res.shape = func1.shape.copy()
# res.shapeBounds = func1.shapeBounds.copy()
# res.position = func1.position.copy()

#   return res

# #--------------------------------------------------------------------------------------------------------

# #********************************************************************************************************
# cdef __create_opIntXd__(int64_t operId, elemental_operation lhs ):
#   """
#   PURPOSE: Create elemental operation from integral call.

#   This function creates an UNARY operation from derivative call.

#   INPUTS:

#     - operId: Operation id, expecting only opDx, opDy, opDz.
#     - lhs:    Source operation from which to interpolate the solution. 
#               Can come from feUndef or feDef functions
#   """
#   #******************************************************************************************************
  
#   # For now: Not supported dx( dx(...) )
#   cdef elemental_operation res = <elemental_operation> elemental_operation.__new__(elemental_operation)
#   cdef np.ndarray newOperation 
  
#   res.interpDer  = basisN




#   # INT 2D

#   res.baseSpace = func1.baseSpace
        
#   res.intorder = func1.intorder
#   res.funcid   = res.baseSpace.addNewOperation()

#   res.baseFunc = func1.baseFunc.copy()
  
#   # Add itself to the list of baseFunctions
#   res.baseFunc.append(res)

#   if func1.nature == feNatTest:

#     # append both foper matrices
#     res.foper = func1.foper.copy()

#     # append both Koper matrices
#     res.Koper = np.array([],dtype=np.int64)

#     # add new operation to the operation matrix
#     res.foper = np.append(res.foper,\
#                          [[operId,res.funcid,func1.funcid,0]],\
#                           axis = 0)

#     # initialize the other two operation matrices as void.
#     res.essentialOper = np.array([],dtype=np.int64)

#   elif func1.nature == feNatOperRes:

#     # append both foper matrices
#     res.foper = np.array([],dtype=np.int64)

#     # append both Koper matrices
#     res.Koper = func1.Koper.copy()

#     # add new operation to the operation matrix
#     res.Koper = np.append(res.Koper,\
#                          [[operId,res.funcid,func1.funcid,0]],\
#                           axis = 0)

#     # initialize the other two operation matrices as void.
#     res.essentialOper = np.array([],dtype=np.int64)

#   else:

#     raise ValueError("Domain integral only supports natures "+\
#       str(feNatTest)+" or "+str(feNatOperRes)+".")

#   # end if 
#   # TODO: ADD INDICATION TO THE INTEGRATION REGION!
#   res.nature   = feNatPostIntK 
#   res.shape    = []
#   res.shapeBounds = [[],[],[]]
#   res.position = [0]

#   return res

# #--------------------------------------------------------------------------------------------------------



# #********************************************************************************************************
# cdef __create_opOn__(int64_t operId, elemental_operation lhs ):
#   """
#   PURPOSE: Create elemental operation from integral call.

#   This function creates an UNARY operation from derivative call.

#   INPUTS:

#     - operId: Operation id, expecting only opDx, opDy, opDz.
#     - lhs:    Source operation from which to interpolate the solution. 
#               Can come from feUndef or feDef functions
#   """
#   #******************************************************************************************************
  
#   # For now: Not supported dx( dx(...) )
#   cdef elemental_operation res = <elemental_operation> elemental_operation.__new__(elemental_operation)
#   cdef np.ndarray newOperation 
  
#   res.interpDer  = basisN

#   res.baseSpace = func1.baseSpace
  
#   res.intorder = func1.intorder
#   res.funcid   = res.baseSpace.addNewOperation()

#   res.baseFunc = func1.baseFunc.copy()
  
#   # Add itself to the list of baseFunctions
#   res.baseFunc.append(res)

#   # append both foper matrices
#   res.foper = func1.foper.copy()

#   # append both Koper matrices
#   res.Koper = np.array([],dtype=np.int64)

#   # add new operation to the operation matrix
#   if func1.essentialOper.ndim != 1:
#     res.essentialOper = np.append(func1.essentialOper,\
#                        [[operId,res.funcid,func1.funcid,func2.funcid]],\
#                         axis = 0)
#   else:
#     res.essentialOper = np.array([[operId,res.funcid,func1.funcid,func2.funcid]],dtype=np.int64)
#   # end if 

#   # initialize the other two operation matrices as void.
#   res.foper = np.array([],dtype=np.int64)


#   # TODO: ADD INDICATION TO THE INTEGRATION REGION!
#   res.nature = feNatPostIntK
#   res.shape =[]
#   res.shapeBounds = [[],[],[]]
#   res.position = [0] #  Add here the position of the variable that is being defined.

#   return res

# #--------------------------------------------------------------------------------------------------------
