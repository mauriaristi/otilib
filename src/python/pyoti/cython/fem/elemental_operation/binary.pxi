#********************************************************************************************************
cdef __create_opElementwise__(int64_t operType, elemental_operation lhs, elemental_operation rhs ):
  """
  PURPOSE: Create elemental operation from elementwise operation.

  This function creates an BINARY operation elementwise operation.

  INPUTS:

    - operType: Operation id, expecting: opMul, opAdd, opSub, opTruediv.
    - lhs:    Left hand side operation.
    - rhs:    Right hand side operation.
    
  """
  #******************************************************************************************************
  global __varid_counter,__opid_counter

  cdef elemental_operation res = <elemental_operation> elemental_operation.__new__(elemental_operation)
  cdef np.ndarray newOperation 
  
  cdef int op_type
  
  res.baseSpace  = lhs.baseSpace  

  if   operType == opMul:
    
    op_type = opMul 
    res.intorder = lhs.intorder + rhs.intorder

  elif operType == opTruediv:
    
    op_type = opTruediv 
    res.intorder = max( lhs.intorder, rhs.intorder ) * 2
    # TODO: Define a propper manner to define the integration order.
  
  elif operType == opAdd:
    
    op_type = opAdd 
    res.intorder = max( lhs.intorder, rhs.intorder )
  
  elif operType == opSub:
    
    op_type = opSub  
    res.intorder = max( lhs.intorder, rhs.intorder )

  else:

    raise ValueError("Wrong operation Id for opElementwise operation")

  # end if 

  res.var_id   = -1
  res.op_id   = __opid_counter 
  __opid_counter += 1

  res.data     = None

  newOperation = np.array( [[ op_type, lhs, rhs, res]] , dtype = object)
  newOperation = np.concatenate( ( rhs.op_graph, newOperation ), axis=0)
  
  res.op_graph = np.concatenate( ( lhs.op_graph, newOperation ), axis=0)

  
  return res

#--------------------------------------------------------------------------------------------------------

# #********************************************************************************************************
# cdef __create_opDotproduct__(int64_t operType, elemental_operation lhs, elemental_operation rhs ):
#   """
#   PURPOSE: Create elemental operation from dot product operation.

#   This function creates an BINARY operation from dot product operation.

#   INPUTS:

#     - operType: Operation id, expecting opDotproduct.
#     - lhs:    Left hand side operation.
#     - rhs:    Right hand side operation.

#   """
#   #******************************************************************************************************
  
#   # For now: Not supported dx( dx(...) )
#   cdef elemental_operation res = <elemental_operation> elemental_operation.__new__(elemental_operation)
#   cdef np.ndarray newOperation 
  
#   res.interpDer  = basisN


#   return res

# #--------------------------------------------------------------------------------------------------------

# #********************************************************************************************************
# cdef __create_opMatmul__(int64_t operType, elemental_operation lhs, elemental_operation rhs ):
#   """
#   PURPOSE: Create elemental operation from Matmul operation.

#   This function creates an BINARY operation from Matmul operation.

#   INPUTS:

#     - operType: Operation id, expecting only opMatmul.
#     - lhs:    Left hand side operation.
#     - rhs:    Right hand side operation.

#   """
#   #******************************************************************************************************
  
#   # For now: Not supported dx( dx(...) )
#   cdef elemental_operation res = <elemental_operation> elemental_operation.__new__(elemental_operation)
#   cdef np.ndarray newOperation 
  
#   res.interpDer  = basisN


#   return res

# #--------------------------------------------------------------------------------------------------------

# #********************************************************************************************************
# cdef __create_opTruediv__(int64_t operType, elemental_operation lhs, elemental_operation rhs ):
#   """
#   PURPOSE: Create elemental operation from division operation.

#   This function creates an BINARY operation from division operation.

#   INPUTS:

#     - operType: Operation id, expecting only opTruediv.
#     - lhs:    Left hand side operation.
#     - rhs:    Right hand side operation.

#   """
#   #******************************************************************************************************
  
#   # For now: Not supported dx( dx(...) )
#   cdef elemental_operation res = <elemental_operation> elemental_operation.__new__(elemental_operation)
#   cdef np.ndarray newOperation 
  
#   res.interpDer  = basisN


#   return res

# #--------------------------------------------------------------------------------------------------------

