
include "algebra_utils/add.pxi"
include "algebra_utils/mul.pxi"
include "algebra_utils/sub.pxi"
include "algebra_utils/div.pxi"










#*****************************************************************************************************
cpdef add(object lhs, object rhs, object out = None):
  """
  PURPOSE:  Addition between two objects.
  """
  #***************************************************************************************************
  global dhl
  
  # Scalar types
  cdef sotinum    olhs

  cdef sotife     flhs

  cdef coeff_t    rlhs

  # Array types
  cdef matso      Olhs

  cdef dmat       Rlhs

  cdef matsofe    Flhs

  cdef uint8_t res_flag = 1
  cdef object res = None

  tlhs = type(lhs)
  trhs = type(rhs)

  if out is None:
    res_flag = 0
  # end if 

  if   tlhs is sotinum:    

  elif tlhs is sotife:
    
  elif tlhs is matsofe:

  elif tlhs is dmat:

  elif tlhs is matso:        

  elif tlhs is dmat:

  else:

    raise TypeError("Unsupported types at dot operation.")
    
    # return NotImplemented

  # end if 

  if res_flag == 0:

    return res

  # end if 
#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cpdef sub(object lhs, object rhs, object out = None):
#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cpdef mul(object lhs, object rhs, object out = None):
#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cpdef div(object lhs, object rhs, object out = None):
#-----------------------------------------------------------------------------------------------------


