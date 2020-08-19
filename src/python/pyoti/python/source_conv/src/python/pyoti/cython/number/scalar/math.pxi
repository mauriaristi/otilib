

#*****************************************************************************************************
cpdef {num_pytype} {num_pytype}_cos({num_pytype} val):
  """
  PURPOSE:  Mathematical function of cosine for OTI numbers
  """
  #***************************************************************************************************

  
  
  cdef {num_type} res = {num_func}_cos(&val.num)

  return {num_pytype}.create(&res)
#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cpdef {num_pytype} {num_pytype}_sin({num_pytype} val):
  """
  PURPOSE:  Mathematical function of sine for OTI numbers.
  """
  #***************************************************************************************************
  
  
  cdef {num_type} res = {num_func}_sin(&val.num)

  return {num_pytype}.create(&res)
#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cpdef {num_pytype} {num_func}_tan({num_pytype} val):
  """
  PURPOSE:  Mathematical function of tangent for OTI numbers 
  """
  #***************************************************************************************************
  
  
  cdef {num_type} res = {num_func}_tan(&val.num)

  return {num_pytype}.create(&res)
#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cpdef {num_pytype} {num_pytype}_arctan({num_pytype} val):
  """
  PURPOSE:  Mathematical function of arctangent for OTI numbers
  """
  #***************************************************************************************************
  
  
  cdef {num_type} res = {num_func}_atan(&val.num)

  return {num_pytype}.create(&res)
#-----------------------------------------------------------------------------------------------------

# #*****************************************************************************************************
# cpdef {num_pytype} {num_pytype}_atan2({num_pytype} valx, {num_pytype} valy):
#   """
#   PURPOSE:  Mathematical function of arctangent for OTI numbers
   
#   EXAMPLE:   
#   """
#   #***************************************************************************************************
#   
  
#   cdef {num_type} res = {num_func}_atan2(&valx.num, &valy.num)

#   return {num_pytype}.create(&res)
# #-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cpdef {num_pytype} {num_pytype}_arccos({num_pytype} val):
  """
  PURPOSE:  Mathematical function of inverse cosine for OTI numbers
  """
  #***************************************************************************************************
  
  
  cdef {num_type} res = {num_func}_acos(&val.num)

  return {num_pytype}.create(&res)
#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cpdef {num_pytype} {num_pytype}_arcsin({num_pytype} val):
  """
  PURPOSE:  Mathematical function of inverse sine for OTI numbers
  """
  #***************************************************************************************************
  
  
  cdef {num_type} res = {num_func}_asin(&val.num)

  return {num_pytype}.create(&res)
#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cpdef {num_pytype} {num_pytype}_sinh({num_pytype} val):
  """
  PURPOSE:  Mathematical function of hyperbolic sine for OTI numbers
  """
  #***************************************************************************************************
  
  
  cdef {num_type} res = {num_func}_sinh(&val.num)

  return {num_pytype}.create(&res)
#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cpdef {num_pytype} {num_pytype}_arcsinh({num_pytype} val):
  """
  PURPOSE:  Mathematical function of inverse hyperbolic sine for OTI numbers  
  """
  #***************************************************************************************************
  
  
  cdef {num_type} res = {num_func}_asinh(&val.num)

  return {num_pytype}.create(&res)
#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cpdef {num_pytype} {num_pytype}_cosh({num_pytype} val):
  """
  PURPOSE:  Mathematical function of hyperbolic cosine for OTI numbers 
  """
  #***************************************************************************************************
  
  
  cdef {num_type} res = {num_func}_cosh(&val.num)

  return {num_pytype}.create(&res)
#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cpdef {num_pytype} {num_pytype}_arccosh({num_pytype} val):
  """
  PURPOSE:  Mathematical function of inverse hyperbolic cosine for OTI numbers

  """
  #***************************************************************************************************
  
  
  cdef {num_type} res = {num_func}_acosh(&val.num)

  return {num_pytype}.create(&res)
#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cpdef {num_pytype} {num_func}_tanh({num_pytype} val):
  """
  PURPOSE:  Mathematical function of hyperbolic tangent for OTI numbers  
  """
  #***************************************************************************************************
  
  
  cdef {num_type} res = {num_func}_tanh(&val.num)

  return {num_pytype}.create(&res)
#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cpdef {num_pytype} {num_pytype}_arctanh({num_pytype} val):
  """
  PURPOSE:  Mathematical function of Inverse hyperbolic tangent for OTI numbers

  """
  #***************************************************************************************************
  
  
  cdef {num_type} res = {num_func}_atanh(&val.num)

  return {num_pytype}.create(&res)
#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cpdef {num_pytype} {num_pytype}_logb({num_pytype} val, double base):
  """
  PURPOSE:  Logarithm base b for OTI numbers.
  """
  #***************************************************************************************************  

  
  
  
  cdef {num_type} res = {num_func}_logb(&val.num, base)

  return {num_pytype}.create(&res)
#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cpdef {num_pytype} {num_pytype}_log10({num_pytype} val):
  """
  PURPOSE:  Natural logarithm base 10 for OTI numbers.
  """
  #***************************************************************************************************  

  
  
  cdef {num_type} res = {num_func}_log10(&val.num)

  return {num_pytype}.create(&res)
#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cpdef {num_pytype} {num_pytype}_log({num_pytype} val):
  """
  PURPOSE:  Natural logarithm for OTI numbers. 
  """
  #***************************************************************************************************  
  
  
  cdef {num_type} res = {num_func}_log(&val.num)

  return {num_pytype}.create(&res)
#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cpdef {num_pytype} {num_pytype}_exp({num_pytype} val):
  """
  PURPOSE:  Exponential function for OTI numbers.
  """
  #*************************************************************************************************** 
  
  
  cdef {num_type} res = {num_func}_exp(&val.num)

  return {num_pytype}.create(&res)
#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cpdef {num_pytype} {num_pytype}_power({num_pytype} val, double exponent):
  """
  PURPOSE:  Power function for OTI numbers, for non integer exponents.
  """
  #*************************************************************************************************** 
  

  cdef {num_type} res = {num_func}_pow(&val.num, exponent)

  return {num_pytype}.create(&res)
#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cpdef {num_pytype} {num_pytype}_sqrt({num_pytype} val):
  """
  PURPOSE:  Square root function for OTI numbers, for non integer exponents. 
  """
  #*************************************************************************************************** 
  
  
  cdef {num_type} res = {num_func}_sqrt(&val.num)

  return {num_pytype}.create(&res)
#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cpdef {num_pytype} {num_pytype}_cbrt({num_pytype} val):
  """
  PURPOSE:  Square root function for OTI numbers, for non integer exponents. 
  """
  #*************************************************************************************************** 
  
  
  cdef {num_type} res = {num_func}_cbrt(&val.num)

  return {num_pytype}.create(&res)
#-----------------------------------------------------------------------------------------------------