#********************************************************************************************************
cdef __create_opElementwise__(int64_t operId, elemental_operation lhs, elemental_operation rhs ):
  """
  PURPOSE: Create elemental operation from elementwise operation.

  This function creates an BINARY operation elementwise operation.

  INPUTS:

    - operId: Operation id, expecting only opTruediv.
    - lhs:    Left hand side operation.
    - rhs:    Right hand side operation.
    
  """
  #******************************************************************************************************
  
  # For now: Not supported dx( dx(...) )
  cdef elemental_operation res = <elemental_operation> elemental_operation.__new__(elemental_operation)
  cdef np.ndarray newOperation 
  
  res.interpDer  = basisN


  return res

#--------------------------------------------------------------------------------------------------------

#********************************************************************************************************
cdef __create_opDotproduct__(int64_t operId, elemental_operation lhs, elemental_operation rhs ):
  """
  PURPOSE: Create elemental operation from dot product operation.

  This function creates an BINARY operation from dot product operation.

  INPUTS:

    - operId: Operation id, expecting opDotproduct.
    - lhs:    Left hand side operation.
    - rhs:    Right hand side operation.

  """
  #******************************************************************************************************
  
  # For now: Not supported dx( dx(...) )
  cdef elemental_operation res = <elemental_operation> elemental_operation.__new__(elemental_operation)
  cdef np.ndarray newOperation 
  
  res.interpDer  = basisN


  return res

#--------------------------------------------------------------------------------------------------------

#********************************************************************************************************
cdef __create_opMatmul__(int64_t operId, elemental_operation lhs, elemental_operation rhs ):
  """
  PURPOSE: Create elemental operation from Matmul operation.

  This function creates an BINARY operation from Matmul operation.

  INPUTS:

    - operId: Operation id, expecting only opMatmul.
    - lhs:    Left hand side operation.
    - rhs:    Right hand side operation.

  """
  #******************************************************************************************************
  
  # For now: Not supported dx( dx(...) )
  cdef elemental_operation res = <elemental_operation> elemental_operation.__new__(elemental_operation)
  cdef np.ndarray newOperation 
  
  res.interpDer  = basisN


  return res

#--------------------------------------------------------------------------------------------------------

#********************************************************************************************************
cdef __create_opTruediv__(int64_t operId, elemental_operation lhs, elemental_operation rhs ):
  """
  PURPOSE: Create elemental operation from division operation.

  This function creates an BINARY operation from division operation.

  INPUTS:

    - operId: Operation id, expecting only opTruediv.
    - lhs:    Left hand side operation.
    - rhs:    Right hand side operation.

  """
  #******************************************************************************************************
  
  # For now: Not supported dx( dx(...) )
  cdef elemental_operation res = <elemental_operation> elemental_operation.__new__(elemental_operation)
  cdef np.ndarray newOperation 
  
  res.interpDer  = basisN


  return res

#--------------------------------------------------------------------------------------------------------

