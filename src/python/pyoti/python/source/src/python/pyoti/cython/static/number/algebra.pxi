
include "algebra_utils/add.pxi"
include "algebra_utils/sub.pxi"
include "algebra_utils/mul.pxi"
include "algebra_utils/div.pxi"



#*****************************************************************************************************
cpdef sum(object lhs, object rhs, object out = None):
  """
  PURPOSE:  Addition between two objects.
  """
  #***************************************************************************************************
  global dhl
  
  cdef uint8_t res_flag = 1
  cdef object res = None

  tlhs = type(lhs)

  if out is None:
    res_flag = 0
  # end if 

  if   tlhs is sotinum:
    res = __add__oX__(lhs, rhs, out = out)
  elif tlhs is sotife:
    res = __add__fX__(lhs, rhs, out = out)
  elif tlhs is matso:
    res = __add__OX__(lhs, rhs, out = out)
  elif tlhs is matsofe:
    res = __add__FX__(lhs, rhs, out = out)
  elif tlhs is dmat:
    res = __add__RX__(lhs, rhs, out = out)
  elif tlhs in number_types:
    res = __add__rX__(lhs, rhs, out = out)
  else:
    raise TypeError("Unsupported add operation between {0} and {1}.".format(tlhs,type(rhs)))
  # end if 

  if res_flag == 0:
    return res
  # end if 
#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cpdef sub(object lhs, object rhs, object out = None):
  """
  PURPOSE:  Subtraction between two objects.
  """
  #***************************************************************************************************
  global dhl
  
  cdef uint8_t res_flag = 1
  cdef object res = None

  tlhs = type(lhs)

  if out is None:
    res_flag = 0
  # end if 

  if   tlhs is sotinum:
    res = __sub__oX__(lhs, rhs, out = out)
  elif tlhs is sotife:
    res = __sub__fX__(lhs, rhs, out = out)
  elif tlhs is matso:
    res = __sub__OX__(lhs, rhs, out = out)
  elif tlhs is matsofe:
    res = __sub__FX__(lhs, rhs, out = out)
  elif tlhs is dmat:
    res = __sub__RX__(lhs, rhs, out = out)
  elif tlhs in number_types:
    res = __sub__rX__(lhs, rhs, out = out)
  else:
    raise TypeError("Unsupported sub operation between {0} and {1}.".format(tlhs,type(rhs)))
  # end if 

  if res_flag == 0:
    return res
  # end if 
#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cpdef mul(object lhs, object rhs, object out = None):
  """
  PURPOSE:  Multiplication between two objects.
  """
  #***************************************************************************************************
  global dhl
  
  cdef uint8_t res_flag = 1
  cdef object res = None

  tlhs = type(lhs)

  if out is None:
    res_flag = 0
  # end if 

  if   tlhs is sotinum:
    res = __mul__oX__(lhs, rhs, out = out)
  elif tlhs is sotife:
    res = __mul__fX__(lhs, rhs, out = out)
  elif tlhs is matso:
    res = __mul__OX__(lhs, rhs, out = out)
  elif tlhs is matsofe:
    res = __mul__FX__(lhs, rhs, out = out)
  elif tlhs is dmat:
    res = __mul__RX__(lhs, rhs, out = out)
  elif tlhs in number_types:
    res = __mul__rX__(lhs, rhs, out = out)
  else:
    raise TypeError("Unsupported mul operation between {0} and {1}.".format(tlhs,type(rhs)))
  # end if 

  if res_flag == 0:
    return res
  # end if 
#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cpdef div(object lhs, object rhs, object out = None):
  """
  PURPOSE:  Divition between two objects.
  """
  #***************************************************************************************************
  global dhl
  
  cdef uint8_t res_flag = 1
  cdef object res = None

  tlhs = type(lhs)

  if out is None:
    res_flag = 0
  # end if 

  if   tlhs is sotinum:
    res = __div__oX__(lhs, rhs, out = out)
  elif tlhs is sotife:
    res = __div__fX__(lhs, rhs, out = out)
  elif tlhs is matso:
    res = __div__OX__(lhs, rhs, out = out)
  elif tlhs is matsofe:
    res = __div__FX__(lhs, rhs, out = out)
  elif tlhs is dmat:
    res = __div__RX__(lhs, rhs, out = out)
  elif tlhs in number_types:
    res = __div__rX__(lhs, rhs, out = out)
  else:
    raise TypeError("Unsupported div operation between {0} and {1}.".format(tlhs,type(rhs)))
  # end if 

  if res_flag == 0:
    return res
  # end if 
#-----------------------------------------------------------------------------------------------------


#*****************************************************************************************************
cpdef trunc_sub(ord_t order, matso Olhs, matso Orhs, matso out = None):
  """
  PURPOSE:  Subtraction between two objects.
  """
  #***************************************************************************************************
  global dhl
  
  cdef uint8_t res_flag = 1
  cdef object res = None
  cdef arrso_t   cOres
  # tlhs = type(lhs)

  if out is None:
    res_flag = 0
  # end if 


  if res_flag:    
    arrso_trunc_sub_OO_to( order, &Olhs.arr, &Orhs.arr, &out.arr, dhl )
  # else:
  #   cOres = arrso_trunc_sub_OO( order, &Olhs.arr, &Orhs.arr, dhl )
  #   res = matso.create( &cOres )
  # end if

  # if   tlhs is sotinum:
  #   res = __sub__oX__(lhs, rhs, out = out)
  # elif tlhs is sotife:
  #   res = __sub__fX__(lhs, rhs, out = out)
  # elif tlhs is matso:
  #   res = __sub__OX__(lhs, rhs, out = out)
  # elif tlhs is matsofe:
  #   res = __sub__FX__(lhs, rhs, out = out)
  # elif tlhs is dmat:
  #   res = __sub__RX__(lhs, rhs, out = out)
  # elif tlhs in number_types:
  #   res = __sub__rX__(lhs, rhs, out = out)
  # else:
  #   raise TypeError("Unsupported sub operation between {0} and {1}.".format(tlhs,type(rhs)))
  # # end if 

  if res_flag == 0:
    return res
  # end if 
#-----------------------------------------------------------------------------------------------------