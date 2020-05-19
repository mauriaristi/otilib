


#*****************************************************************************************************
cpdef cos(object val):
  """
  PURPOSE:  Mathematical function of cosine for OTI numbers
  """
  #***************************************************************************************************

  tval = type(val)

  if tval is sotinum:

    return sotinum_cos(val)

  elif tval is matso:

    return matso_cos(val)

  else:

    return NotImplemented

  # end if 

#-----------------------------------------------------------------------------------------------------


#*****************************************************************************************************
cpdef sin(object val):
  """
  PURPOSE:  Mathematical function of sine for OTI numbers.
  """
  #***************************************************************************************************
  
  tval = type(val)

  if tval is sotinum:

    return sotinum_sin(val)

  elif tval is matso:

    return matso_sin(val)

  else:

    return NotImplemented
    
  # end if 

#-----------------------------------------------------------------------------------------------------


#*****************************************************************************************************
cpdef tan(object val):
  """
  PURPOSE:  Mathematical function of tangent for OTI numbers 
  """
  #***************************************************************************************************

  tval = type(val)

  if tval is sotinum:

    return sotinum_tan(val)

  elif tval is matso:

    return matso_tan(val)

  else:

    return NotImplemented
    
  # end if 

#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cpdef arctan(object val):
  """
  PURPOSE:  Mathematical function of arctangent for OTI numbers
  """
  #***************************************************************************************************

  tval = type(val)

  if tval is sotinum:

    return sotinum_arctan(val)

  elif tval is matso:

    return matso_arctan(val)

  else:

    return NotImplemented
    
  # end if 

#-----------------------------------------------------------------------------------------------------

# #*****************************************************************************************************
# cpdef atan2(object valx, object valy):
#   """
#   PURPOSE:  Mathematical function of arctangent for OTI numbers
   
#   EXAMPLE:   
#   """
#   #***************************************************************************************************
# 
  
#   cdef return sotinum_t res = soti_atan2(&valx.num, &valy.num, dhl)

#   return object.create(&res)
# #-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cpdef arccos(object val):
  """
  PURPOSE:  Mathematical function of inverse cosine for OTI numbers
  """
  #***************************************************************************************************

  tval = type(val)

  if tval is sotinum:

    return sotinum_arccos(val)

  elif tval is matso:

    return matso_arccos(val)

  else:

    return NotImplemented
    
  # end if 

#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cpdef arcsin(object val):
  """
  PURPOSE:  Mathematical function of inverse sine for OTI numbers
  """
  #***************************************************************************************************

  tval = type(val)

  if tval is sotinum:

    return sotinum_arcsin(val)

  elif tval is matso:

    return matso_arcsin(val)

  else:

    return NotImplemented
    
  # end if 

#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cpdef sinh(object val):
  """
  PURPOSE:  Mathematical function of hyperbolic sine for OTI numbers
  """
  #***************************************************************************************************

  tval = type(val)

  if tval is sotinum:

    return sotinum_sinh(val)

  elif tval is matso:

    return matso_sinh(val)

  else:

    return NotImplemented
    
  # end if 

#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cpdef arcsinh(object val):
  """
  PURPOSE:  Mathematical function of inverse hyperbolic sine for OTI numbers  
  """
  #***************************************************************************************************

  tval = type(val)

  if tval is sotinum:

    return sotinum_arcsinh(val)

  elif tval is matso:

    return matso_arcsinh(val)

  else:

    return NotImplemented
    
  # end if 

#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cpdef cosh(object val):
  """
  PURPOSE:  Mathematical function of hyperbolic cosine for OTI numbers 
  """
  #***************************************************************************************************

  tval = type(val)

  if tval is sotinum:

    return sotinum_cosh(val)

  elif tval is matso:

    return matso_cosh(val)

  else:

    return NotImplemented
    
  # end if 

#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cpdef arccosh(object val):
  """
  PURPOSE:  Mathematical function of inverse hyperbolic cosine for OTI numbers

  """
  #***************************************************************************************************

  tval = type(val)

  if tval is sotinum:

    return sotinum_arccosh(val)

  elif tval is matso:

    return matso_arccosh(val)

  else:

    return NotImplemented
    
  # end if 

#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cpdef tanh(object val):
  """
  PURPOSE:  Mathematical function of hyperbolic tangent for OTI numbers  
  """
  #***************************************************************************************************

  tval = type(val)

  if tval is sotinum:

    return sotinum_tanh(val)

  elif tval is matso:

    return matso_tanh(val)

  else:

    return NotImplemented
    
  # end if 

#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cpdef arctanh(object val):
  """
  PURPOSE:  Mathematical function of Inverse hyperbolic tangent for OTI numbers

  """
  #***************************************************************************************************

  tval = type(val)

  if tval is sotinum:

    return sotinum_arctanh(val)

  elif tval is matso:

    return matso_arctanh(val)

  else:

    return NotImplemented
    
  # end if 

#-----------------------------------------------------------------------------------------------------


#*****************************************************************************************************
cpdef logb(object val, double base):
  """
  PURPOSE:  Logarithm base b for OTI numbers.
  """
  #***************************************************************************************************  

  tval = type(val)

  if tval is sotinum:

    return sotinum_logb(val,base)

  elif tval is matso:

    return matso_logb(val,base)

  else:

    return NotImplemented
    
  # end if 

#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cpdef log10(object val):
  """
  PURPOSE:  Natural logarithm base 10 for OTI numbers.
  """
  #***************************************************************************************************  

  tval = type(val)

  if tval is sotinum:

    return sotinum_log10(val)

  elif tval is matso:

    return matso_log10(val)

  else:

    return NotImplemented
    
  # end if 

#-----------------------------------------------------------------------------------------------------


#*****************************************************************************************************
cpdef log(object val):
  """
  PURPOSE:  Natural logarithm for OTI numbers. 
  """
  #***************************************************************************************************  

  tval = type(val)

  if tval is sotinum:

    return sotinum_log(val)

  elif tval is matso:

    return matso_log(val)

  else:

    return NotImplemented
    
  # end if 

#-----------------------------------------------------------------------------------------------------


#*****************************************************************************************************
cpdef exp(object val):
  """
  PURPOSE:  Exponential function for OTI numbers.
  """
  #*************************************************************************************************** 

  tval = type(val)

  if tval is sotinum:

    return sotinum_exp(val)

  elif tval is matso:

    return matso_exp(val)

  else:

    return NotImplemented
    
  # end if 

#-----------------------------------------------------------------------------------------------------


#*****************************************************************************************************
cpdef power(object val, double exponent):
  """
  PURPOSE:  Power function for OTI numbers, for non integer exponents.
  """
  #*************************************************************************************************** 

  tval = type(val)

  if tval is sotinum:

    return sotinum_power(val,exponent)

  elif tval is matso:

    return matso_power(val,exponent)

  else:

    return NotImplemented
    
  # end if 

#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cpdef sqrt(object val):
  """
  PURPOSE:  Square root function for OTI numbers, for non integer exponents. 
  """
  #*************************************************************************************************** 

  tval = type(val)

  if tval is sotinum:

    return sotinum_sqrt(val)

  elif tval is matso:

    return matso_sqrt(val)

  else:

    return NotImplemented
    
  # end if 

#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cpdef cbrt(object val):
  """
  PURPOSE:  Square root function for OTI numbers, for non integer exponents. 
  """
  #*************************************************************************************************** 

  tval = type(val)

  if tval is sotinum:

    return sotinum_cbrt(val)

  elif tval is matso:

    return matso_cbrt(val)

  else:

    return NotImplemented
    
  # end if 

#-----------------------------------------------------------------------------------------------------