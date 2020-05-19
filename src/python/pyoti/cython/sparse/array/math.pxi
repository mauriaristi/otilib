

#*****************************************************************************************************
cpdef matso matso_cos(matso val):
  """
  PURPOSE:  Mathematical function of cosine for Array of OTI numbers
  """
  #***************************************************************************************************

  global dhl
  
  cdef arrso_t res = arrso_cos(&val.arr, dhl)

  return matso.create(&res)
#-----------------------------------------------------------------------------------------------------


#*****************************************************************************************************
cpdef matso matso_sin(matso val):
  """
  PURPOSE:  Mathematical function of sine for Array of OTI numbers.
  """
  #***************************************************************************************************
  global dhl
  
  cdef arrso_t res = arrso_sin(&val.arr, dhl)

  return matso.create(&res)
#-----------------------------------------------------------------------------------------------------


#*****************************************************************************************************
cpdef matso matso_tan(matso val):
  """
  PURPOSE:  Mathematical function of tangent for Array of OTI numbers 
  """
  #***************************************************************************************************
  global dhl
  
  cdef arrso_t res = arrso_tan(&val.arr, dhl)

  return matso.create(&res)
#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cpdef matso matso_arctan(matso val):
  """
  PURPOSE:  Mathematical function of arctangent for Array of OTI numbers
  """
  #***************************************************************************************************
  global dhl
  
  cdef arrso_t res = arrso_atan(&val.arr, dhl)

  return matso.create(&res)
#-----------------------------------------------------------------------------------------------------

# #*****************************************************************************************************
# cpdef matso matso_atan2(matso valx, matso valy):
#   """
#   PURPOSE:  Mathematical function of arctangent for Array of OTI numbers
   
#   EXAMPLE:   
#   """
#   #***************************************************************************************************
#   global dhl
  
#   cdef arrso_t res = arrso_atan2(&valx.arr, &valy.arr, dhl)

#   return matso.create(&res)
# #-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cpdef matso matso_arccos(matso val):
  """
  PURPOSE:  Mathematical function of inverse cosine for Array of OTI numbers
  """
  #***************************************************************************************************
  global dhl
  
  cdef arrso_t res = arrso_acos(&val.arr, dhl)

  return matso.create(&res)
#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cpdef matso matso_arcsin(matso val):
  """
  PURPOSE:  Mathematical function of inverse sine for Array of OTI numbers
  """
  #***************************************************************************************************
  global dhl
  
  cdef arrso_t res = arrso_asin(&val.arr, dhl)

  return matso.create(&res)
#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cpdef matso matso_sinh(matso val):
  """
  PURPOSE:  Mathematical function of hyperbolic sine for Array of OTI numbers
  """
  #***************************************************************************************************
  global dhl
  
  cdef arrso_t res = arrso_sinh(&val.arr, dhl)

  return matso.create(&res)
#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cpdef matso matso_arcsinh(matso val):
  """
  PURPOSE:  Mathematical function of inverse hyperbolic sine for Array of OTI numbers  
  """
  #***************************************************************************************************
  global dhl
  
  cdef arrso_t res = arrso_asinh(&val.arr, dhl)

  return matso.create(&res)
#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cpdef matso matso_cosh(matso val):
  """
  PURPOSE:  Mathematical function of hyperbolic cosine for Array of OTI numbers 
  """
  #***************************************************************************************************
  global dhl
  
  cdef arrso_t res = arrso_cosh(&val.arr, dhl)

  return matso.create(&res)
#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cpdef matso matso_arccosh(matso val):
  """
  PURPOSE:  Mathematical function of inverse hyperbolic cosine for Array of OTI numbers

  """
  #***************************************************************************************************
  global dhl
  
  cdef arrso_t res = arrso_acosh(&val.arr, dhl)

  return matso.create(&res)
#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cpdef matso matso_tanh(matso val):
  """
  PURPOSE:  Mathematical function of hyperbolic tangent for Array of OTI numbers  
  """
  #***************************************************************************************************
  global dhl
  
  cdef arrso_t res = arrso_tanh(&val.arr, dhl)

  return matso.create(&res)
#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cpdef matso matso_arctanh(matso val):
  """
  PURPOSE:  Mathematical function of Inverse hyperbolic tangent for Array of OTI numbers

  """
  #***************************************************************************************************
  global dhl
  
  cdef arrso_t res = arrso_atanh(&val.arr, dhl)

  return matso.create(&res)
#-----------------------------------------------------------------------------------------------------


#*****************************************************************************************************
cpdef matso matso_logb(matso val, double base):
  """
  PURPOSE:  Logarithm base b for Array of OTI numbers.
  """
  #***************************************************************************************************  

  
  global dhl
  
  cdef arrso_t res = arrso_logb(&val.arr, base, dhl)

  return matso.create(&res)
#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cpdef matso matso_log10(matso val):
  """
  PURPOSE:  Natural logarithm base 10 for Array of OTI numbers.
  """
  #***************************************************************************************************  

  global dhl
  
  cdef arrso_t res = arrso_log10(&val.arr, dhl)

  return matso.create(&res)
#-----------------------------------------------------------------------------------------------------


#*****************************************************************************************************
cpdef matso matso_log(matso val):
  """
  PURPOSE:  Natural logarithm for Array of OTI numbers. 
  """
  #***************************************************************************************************  
  global dhl
  
  cdef arrso_t res = arrso_log(&val.arr, dhl)

  return matso.create(&res)
#-----------------------------------------------------------------------------------------------------


#*****************************************************************************************************
cpdef matso matso_exp(matso val):
  """
  PURPOSE:  Exponential function for Array of OTI numbers.
  """
  #*************************************************************************************************** 
  global dhl
  
  cdef arrso_t res = arrso_exp(&val.arr, dhl)

  return matso.create(&res)
#-----------------------------------------------------------------------------------------------------


#*****************************************************************************************************
cpdef matso matso_power(matso val, double exponent):
  """
  PURPOSE:  Power function for Array of OTI numbers, for non integer exponents.
  """
  #*************************************************************************************************** 
  global dhl

  cdef arrso_t res = arrso_pow(&val.arr, exponent, dhl)

  return matso.create(&res)
#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cpdef matso matso_sqrt(matso val):
  """
  PURPOSE:  Square root function for Array of OTI numbers, for non integer exponents. 
  """
  #*************************************************************************************************** 
  global dhl
  
  cdef arrso_t res = arrso_sqrt(&val.arr, dhl)

  return matso.create(&res)
#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cpdef matso matso_cbrt(matso val):
  """
  PURPOSE:  Square root function for Array of OTI numbers, for non integer exponents. 
  """
  #*************************************************************************************************** 
  global dhl
  
  cdef arrso_t res = arrso_cbrt(&val.arr, dhl)

  return matso.create(&res)
#-----------------------------------------------------------------------------------------------------