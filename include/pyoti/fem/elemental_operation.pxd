



# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# :::::::::::::::::::::::::::::::::     CLASS  ELEMENTAL_OPERATION    ::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
cdef class elemental_operation:

  #---------------------------------------------------------------------------------------------------
  #------------------------------------   DEFINITION OF ATTRIBUTES   ---------------------------------
  #---------------------------------------------------------------------------------------------------

  cdef public fespace     baseSpace     # Finite element space at which the variable is associated.
  
  cdef public int64_t     interpDer     # Interpolation derivative that is required in this operation.

  cdef public uint64_t    intorder      # Polynomial order.  
  cdef public int64_t     nature        # Nature of the function: 
                                        #    feNatTest, feNatUndef, feNatDef
  
  cdef public object   data             # Data of the object, if defined already.

  cdef np.ndarray  operation_graph      # Operations to be executed.
  

  #---------------------------------------------------------------------------------------------------

  @staticmethod
  cdef elemental_operation create(int64_t operId, elemental_operation lhs, elemental_operation rhs)

# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::: END OF CLASS ELEMENTAL_OPERATION :::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::


