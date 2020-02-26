



# # ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# # :::::::::::::::::::::::::::::::::     CLASS  FEFUNCTION    :::::::::::::::::::::::::::::::::::::::::
# # ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# cdef class fefunction:

#   #---------------------------------------------------------------------------------------------------
#   #------------------------------------   DEFINITION OF ATTRIBUTES   ---------------------------------
#   #---------------------------------------------------------------------------------------------------

#   cdef public fespace    baseSpace     # Finite element space at which the variable is associated.
  
#   cdef public int64_t     interpDer     # Interpolation derivative that is required in this operation.

#   cdef public uint64_t    intorder      # Polynomial order. The interpolation basis define an order.
#                                         # Then, the operations will increase the order of the 
#                                         # equivalent polynomials. That will modify the integration 
#                                         # parameters for numerical computations.

#   cdef public uint64_t    funcid        # Global Id of the function. 

#   cdef public int64_t     nature        # Nature of the function: 
#                                         #    feNatTest, feNatUndef, feNatDef

#   cdef public list shape      
#   cdef public list shapeBounds                
#   cdef public list position             # position in the matrix.
  
#   cdef public object   data             # Data of the object, if defined already.
#   cdef public list     baseFunc         # A list to know which vars are associated to the number.


#   cdef np.ndarray  Koper                # Operations defined for Stiffness matrix.
#   cdef np.ndarray  foper                # Operations defined for Force vector.
#   cdef np.ndarray  essentialOper        # Operations defined for boundary conditions.

#   #---------------------------------------------------------------------------------------------------

#   @staticmethod
#   cdef fefunction newFromOperation(int64_t operId, fefunction func1, fefunction func2)

# # ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# # ::::::::::::::::::::::::::::::::::: END OF CLASS FEFUNCTION ::::::::::::::::::::::::::::::::::::::::
# # ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::


