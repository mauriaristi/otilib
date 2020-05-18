













#*****************************************************************************************************
cpdef  sotinum cos(sotinum val):
  """
  PURPOSE:  Mathematical function of cosine for OTI numbers
  """
  #***************************************************************************************************

  global dhl
  
  cdef sotinum_t res = soti_cos(&val.num, dhl)

  return sotinum.create(&res)
#-----------------------------------------------------------------------------------------------------


#*****************************************************************************************************
cpdef  sotinum sin(sotinum val):
  """
  PURPOSE:  Mathematical function of sine for OTI numbers.
  """
  #***************************************************************************************************
  global dhl
  
  cdef sotinum_t res = soti_sin(&val.num, dhl)

  return sotinum.create(&res)
#-----------------------------------------------------------------------------------------------------


#*****************************************************************************************************
cpdef  sotinum tan(sotinum val):
  """
  PURPOSE:  Mathematical function of tangent for OTI numbers 
  """
  #***************************************************************************************************
  global dhl
  
  cdef sotinum_t res = soti_tan(&val.num, dhl)

  return sotinum.create(&res)
#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cpdef  sotinum arctan(sotinum val):
  """
  PURPOSE:  Mathematical function of arctangent for OTI numbers
  """
  #***************************************************************************************************
  global dhl
  
  cdef sotinum_t res = soti_atan(&val.num, dhl)

  return sotinum.create(&res)
#-----------------------------------------------------------------------------------------------------

# #*****************************************************************************************************
# cpdef  sotinum atan2(sotinum valx, sotinum valy):
#   """
#   PURPOSE:  Mathematical function of arctangent for OTI numbers
   
#   EXAMPLE:   
#   """
#   #***************************************************************************************************
#   global dhl
  
#   cdef sotinum_t res = soti_atan2(&valx.num, &valy.num, dhl)

#   return sotinum.create(&res)
# #-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cpdef  sotinum arccos(sotinum val):
  """
  PURPOSE:  Mathematical function of inverse cosine for OTI numbers
  """
  #***************************************************************************************************
  global dhl
  
  cdef sotinum_t res = soti_acos(&val.num, dhl)

  return sotinum.create(&res)
#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cpdef  sotinum arcsin(sotinum val):
  """
  PURPOSE:  Mathematical function of inverse sine for OTI numbers
  """
  #***************************************************************************************************
  global dhl
  
  cdef sotinum_t res = soti_asin(&val.num, dhl)

  return sotinum.create(&res)
#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cpdef  sotinum sinh(sotinum val):
  """
  PURPOSE:  Mathematical function of hyperbolic sine for OTI numbers
  """
  #***************************************************************************************************
  global dhl
  
  cdef sotinum_t res = soti_sinh(&val.num, dhl)

  return sotinum.create(&res)
#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cpdef  sotinum arcsinh(sotinum val):
  """
  PURPOSE:  Mathematical function of inverse hyperbolic sine for OTI numbers  
  """
  #***************************************************************************************************
  global dhl
  
  cdef sotinum_t res = soti_asinh(&val.num, dhl)

  return sotinum.create(&res)
#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cpdef  sotinum cosh(sotinum val):
  """
  PURPOSE:  Mathematical function of hyperbolic cosine for OTI numbers 
  """
  #***************************************************************************************************
  global dhl
  
  cdef sotinum_t res = soti_cosh(&val.num, dhl)

  return sotinum.create(&res)
#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cpdef  sotinum arccosh(sotinum val):
  """
  PURPOSE:  Mathematical function of inverse hyperbolic cosine for OTI numbers

  """
  #***************************************************************************************************
  global dhl
  
  cdef sotinum_t res = soti_acosh(&val.num, dhl)

  return sotinum.create(&res)
#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cpdef  sotinum tanh(sotinum val):
  """
  PURPOSE:  Mathematical function of hyperbolic tangent for OTI numbers  
  """
  #***************************************************************************************************
  global dhl
  
  cdef sotinum_t res = soti_tanh(&val.num, dhl)

  return sotinum.create(&res)
#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cpdef  sotinum arctanh(sotinum val):
  """
  PURPOSE:  Mathematical function of Inverse hyperbolic tangent for OTI numbers

  """
  #***************************************************************************************************
  global dhl
  
  cdef sotinum_t res = soti_atanh(&val.num, dhl)

  return sotinum.create(&res)
#-----------------------------------------------------------------------------------------------------


#*****************************************************************************************************
cpdef  sotinum logb(sotinum val, double base):
  """
  PURPOSE:  Logarithm base b for OTI numbers.
  """
  #***************************************************************************************************  

  
  global dhl
  
  cdef sotinum_t res = soti_logb(&val.num, base, dhl)

  return sotinum.create(&res)
#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cpdef  sotinum log10(sotinum val):
  """
  PURPOSE:  Natural logarithm base 10 for OTI numbers.
  """
  #***************************************************************************************************  

  global dhl
  
  cdef sotinum_t res = soti_log10(&val.num, dhl)

  return sotinum.create(&res)
#-----------------------------------------------------------------------------------------------------


#*****************************************************************************************************
cpdef  sotinum log(sotinum val):
  """
  PURPOSE:  Natural logarithm for OTI numbers. 
  """
  #***************************************************************************************************  
  global dhl
  
  cdef sotinum_t res = soti_log(&val.num, dhl)

  return sotinum.create(&res)
#-----------------------------------------------------------------------------------------------------


#*****************************************************************************************************
cpdef  sotinum exp(sotinum val):
  """
  PURPOSE:  Exponential function for OTI numbers.
  """
  #*************************************************************************************************** 
  global dhl
  
  cdef sotinum_t res = soti_exp(&val.num, dhl)

  return sotinum.create(&res)
#-----------------------------------------------------------------------------------------------------


#*****************************************************************************************************
cpdef  sotinum power(sotinum val, double exponent):
  """
  PURPOSE:  Power function for OTI numbers, for non integer exponents.
  """
  #*************************************************************************************************** 
  global dhl

  cdef sotinum_t res = soti_pow(&val.num, exponent, dhl)

  return sotinum.create(&res)
#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cpdef  sotinum sqrt(sotinum val):
  """
  PURPOSE:  Square root function for OTI numbers, for non integer exponents. 
  """
  #*************************************************************************************************** 
  global dhl
  
  cdef sotinum_t res = soti_sqrt(&val.num, dhl)

  return sotinum.create(&res)
#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cpdef sotinum cbrt(sotinum val):
  """
  PURPOSE:  Square root function for OTI numbers, for non integer exponents. 
  """
  #*************************************************************************************************** 
  global dhl
  
  cdef sotinum_t res = soti_cbrt(&val.num, dhl)

  return sotinum.create(&res)
#-----------------------------------------------------------------------------------------------------