#********************************************************************************************************
cdef __create_opDef__( space baseSpace = None, basis = basisN, data = None):
  """
  PURPOSE: Create elemental operation from derivative call.

  This function creates a UNARY operation from derivative call.

  INPUTS:

    - space baseSpace = None, 
    - basis = basisN 
    - data = None
  """
  #******************************************************************************************************
  
  global __varid_counter, __opid_counter
  # For now: Not supported dx( dx(...) )
  cdef elemental_operation res = <elemental_operation> elemental_operation.__new__(elemental_operation)
  cdef np.ndarray newOperation 
  cdef int op_type
  


  res.baseSpace  = baseSpace

  if baseSpace is not None:
    res.intorder   = baseSpace.order
  else:
    res.intorder   = 1 # Needs to be corrected afterwards.
  # end if       
  
  if data is None:
    op_type = opDef
  else:
    op_type = opDefData
  # end if 

  res.var_id   = __varid_counter 
  __varid_counter += 1

  res.op_id   = __opid_counter 
  __opid_counter += 1


  res.data = data

  res.op_graph = np.array( [[op_type, res, None, res ]] , dtype = object)

  return res

#--------------------------------------------------------------------------------------------------------



#********************************************************************************************************
cdef __create_opDxx__(int64_t operType, elemental_operation lhs ):
  """
  PURPOSE: Create elemental operation from derivative call.

  This function creates a UNARY operation from derivative call.

  INPUTS:

    - operId: Operation id, expecting only opDx, opDy, opDz.
    - lhs:    Source operation from which to interpolate the solution. 
              Can come from feUndef or feDef functions
  """
  #******************************************************************************************************
  
  global __varid_counter,__opid_counter
  
  # For now: Not supported dx( dx(...) )
  cdef elemental_operation res = <elemental_operation> elemental_operation.__new__(elemental_operation)
  cdef np.ndarray newOperation 
  cdef int op_type
  
  res.baseSpace  = lhs.baseSpace
  res.intorder   = lhs.intorder-1
  
  res.op_id   = __opid_counter 
  __opid_counter += 1

  if   operType == opDx:
    op_type = opDx 
  elif operType == opDy:
    op_type = opDy 
  elif operType == opDz:
    op_type = opDz  
  else:
    raise ValueError("Wrong operation Id for Dxx operation")
  # end if 

  res.var_id   = -1
  res.data     = lhs.data
  newOperation = np.array( [[ op_type, lhs, None, res]] , dtype = object)  
  res.op_graph = np.concatenate( ( lhs.op_graph, newOperation ), axis=0)

  return res

#--------------------------------------------------------------------------------------------------------

#********************************************************************************************************
cdef __create_opNeg__(int64_t operType, elemental_operation lhs ):
  """
  PURPOSE: Create elemental operation from negation operation.

  This function creates a UNARY indicative operation from negation call.

  INPUTS:

    - operId: Operation id, expecting only opNeg.
    - lhs:    Source operation to be negated. 

  """
  #******************************************************************************************************

  global __varid_counter,__opid_counter
  
  cdef elemental_operation res = <elemental_operation> elemental_operation.__new__(elemental_operation)
  cdef np.ndarray newOperation 
  cdef int op_type
  
  res.baseSpace  = lhs.baseSpace
  res.intorder   = lhs.intorder

  
  res.op_id   = __opid_counter 
  __opid_counter += 1

  if   operType == opNeg:
    op_type = opNeg
  else:
    raise ValueError("Wrong operation Id for negation operation")
  # end if 

  res.var_id   = -1
  res.data     = lhs.data
  newOperation = np.array( [[ op_type, lhs, None, res]] , dtype = object)  
  res.op_graph = np.concatenate( ( lhs.op_graph, newOperation ), axis=0)

  return res

#--------------------------------------------------------------------------------------------------------

#********************************************************************************************************
cdef __create_opIntXd__(int64_t operType, elemental_operation lhs, mesh Th, region ):
  """
  PURPOSE: Create elemental operation from integral call.

  This function creates a UNARY operation from integration call.

  INPUTS:

    - operId: Operation id, expecting only opInt0D, opInt1D, opInt2D, opInt3D.
    - lhs:    Source operation from which to interpolate the solution. 
              Can come from feUndef or feDef functions
  """
  #******************************************************************************************************
  
  global __varid_counter,__opid_counter
  
  cdef elemental_operation res = <elemental_operation> elemental_operation.__new__(elemental_operation)
  cdef np.ndarray newOperation 
  cdef int op_type
  
  res.baseSpace  = None
  res.intorder   = lhs.intorder
  
  res.op_id   = __opid_counter 
  __opid_counter += 1

  if   operType == opInt0d:
    op_type = opInt0d 
  elif operType == opInt1d:
    op_type = opInt1d 
  elif operType == opInt2d:
    op_type = opInt2d 
  elif operType == opInt3d:
    op_type = opInt3d 
  else:
    raise ValueError("Wrong operation Id for IntXd operation")
  # end if 

  res.var_id   = -1
  res.data     = { 'mesh':Th, 'region':region }

  newOperation = np.array( [[ op_type, lhs, None, res]] , dtype = object)  
  res.op_graph = np.concatenate( ( lhs.op_graph, newOperation ), axis=0)

  return res

#--------------------------------------------------------------------------------------------------------

#********************************************************************************************************
cdef __create_opOn__(int64_t operType, elemental_operation lhs, mesh Th, region ):
  """
  PURPOSE: Create elemental operation from on call.

  This function creates a UNARY operation from essential boundary condition call.

  INPUTS:

    - operId: Operation id, expecting only opDx, opDy, opDz.
    - lhs:    Source operation from which to interpolate the solution. 
              Can come from feUndef or feDef functions
  """
  #******************************************************************************************************
  
  global __varid_counter,__opid_counter
  
  cdef elemental_operation res = <elemental_operation> elemental_operation.__new__(elemental_operation)
  cdef np.ndarray newOperation 
  cdef int op_type
  
  res.baseSpace  = None
  res.intorder   = -1
  
  res.op_id   = __opid_counter 
  __opid_counter += 1

  if   operType == opOn:
    op_type = opOn 
  else:
    raise ValueError("Wrong operation Id for IntXd operation")
  # end if 

  res.var_id   = -1
  res.data     = { 'mesh':Th, 'region':region }

  newOperation = np.array( [[ op_type, lhs, None, res]] , dtype = object)  
  res.op_graph = np.concatenate( ( lhs.op_graph, newOperation ), axis=0)

  return res

#--------------------------------------------------------------------------------------------------------
