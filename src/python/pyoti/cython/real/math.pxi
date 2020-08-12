#*****************************************************************************************************
cpdef cos(object val, object out = None):
  """
  PURPOSE:  Matrix determinant.
  
  Supported types:

      -  matso
      -  dmatfe
      -  darr
      -  sotinum
      -  dnumfe
      -  real
  """
  #***************************************************************************************************

  
  cdef dmat       R, Rres
  cdef dmatfe     F, Fres
  
  cdef coeff_t    r, rres
  cdef dnumfe     f, fres
  cdef coeff_t   crres
  
  cdef fednum_t  cfres
  cdef darr_t    cRres
  
  cdef fedarr_t cFres
  cdef uint8_t res_flag = 1
  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 
  #
  if tval is dnumfe:
    f = val
    if res_flag:
      
      fres = out
      fednum_cos_to( &f.num, &fres.num)

    else:

      cfres = fednum_cos( &f.num)
      res   = dnumfe.create(&cfres)

    # end if         
  elif tval is dmatfe:    
    F = val
    if res_flag:

      Fres = out
      fedarr_cos_to( &F.arr, &Fres.arr)

    else:

      cFres = fedarr_cos( &F.arr)
      res   = dmatfe.create(&cFres)

    # end if    
  elif tval is dmat:
    R = val
    if res_flag:
      
      Rres = out
      darr_cos_to( &R.arr, &Rres.arr)

    else:

      cRres = darr_cos( &R.arr )
      res = dmat.create( &cRres )

    # end if 
  elif tval in number_types:
    import math    
    r    = val
    rres = math.cos(r)
    if res_flag:      
      out = rres
    else:
      res = rres
    # end if   
  else:
    raise TypeError("Unsupported types at cos operation.")    
  # end if 

  if res_flag == 0:
    return res
  # end if 

#-----------------------------------------------------------------------------------------------------




#*****************************************************************************************************
cpdef sin(object val, object out = None):
  """
  PURPOSE:  Matrix determinant.
  
  Supported types:

      -  matso
      -  dmatfe
      -  darr
      -  sotinum
      -  dnumfe
      -  real
  """
  #***************************************************************************************************

  
  cdef dmat       R, Rres
  cdef dmatfe     F, Fres
  
  cdef coeff_t    r, rres
  cdef dnumfe     f, fres
  cdef coeff_t   crres
  
  cdef fednum_t  cfres
  cdef darr_t    cRres
  
  cdef fedarr_t cFres
  cdef uint8_t res_flag = 1
  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if tval is dnumfe:
    f = val
    if res_flag:
      
      fres = out
      fednum_sin_to( &f.num, &fres.num)

    else:

      cfres = fednum_sin( &f.num)
      res   = dnumfe.create(&cfres)

    # end if  
  elif tval is dmatfe:    
    F = val
    if res_flag:

      Fres = out
      fedarr_sin_to( &F.arr, &Fres.arr)

    else:

      cFres = fedarr_sin( &F.arr)
      res   = dmatfe.create(&cFres)

    # end if   
  elif tval is dmat:
    R = val
    if res_flag:
      
      Rres = out
      darr_sin_to( &R.arr, &Rres.arr)

    else:

      cRres = darr_sin( &R.arr )
      res = dmat.create( &cRres )

    # end if 
  elif tval in number_types:
    import math    
    r    = val
    rres = math.sin(r)
    if res_flag:      
      out = rres
    else:
      res = rres
    # end if   
  else:  
    raise TypeError("Unsupported types at sin operation.")    
    # return NotImplemented
  # end if 

  if res_flag == 0:
    return res
  # end if 

#-----------------------------------------------------------------------------------------------------




#*****************************************************************************************************
cpdef tan(object val, object out = None):
  """
  PURPOSE:  Matrix determinant.
  
  Supported types:

      -  matso
      -  dmatfe
      -  darr
      -  sotinum
      -  dnumfe
      -  real
  """
  #***************************************************************************************************

  
  cdef dmat       R, Rres
  cdef dmatfe    F, Fres
  
  cdef coeff_t    r, rres
  cdef dnumfe     f, fres
  cdef coeff_t   crres
  
  cdef fednum_t  cfres
  cdef darr_t    cRres
  
  cdef fedarr_t cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if tval is dnumfe:
    f = val
    if res_flag:
      
      fres = out
      fednum_tan_to( &f.num, &fres.num)

    else:

      cfres = fednum_tan( &f.num)
      res   = dnumfe.create(&cfres)

    # end if  
  elif tval is dmatfe:    
    F = val
    if res_flag:

      Fres = out
      fedarr_tan_to( &F.arr, &Fres.arr)

    else:

      cFres = fedarr_tan( &F.arr)
      res   = dmatfe.create(&cFres)

    # end if    
  elif tval is dmat:
    R = val
    if res_flag:
      
      Rres = out
      darr_tan_to( &R.arr, &Rres.arr)

    else:

      cRres = darr_tan( &R.arr )
      res = dmat.create( &cRres )

    # end if 
  elif tval in number_types:
    import math    
    r    = val
    rres = math.tan(r)
    if res_flag:      
      out = rres
    else:
      res = rres
    # end if   
  else:  
    raise TypeError("Unsupported types at tan operation.")    
    # return NotImplemented
  # end if 

  if res_flag == 0:
    return res
  # end if 

#-----------------------------------------------------------------------------------------------------






#*****************************************************************************************************
cpdef acos(object val, object out = None):
  """
  PURPOSE:  Matrix determinant.
  
  Supported types:

      -  matso
      -  dmatfe
      -  darr
      -  sotinum
      -  dnumfe
      -  real
  """
  #***************************************************************************************************

  
  cdef dmat       R, Rres
  cdef dmatfe    F, Fres
  
  cdef coeff_t    r, rres
  cdef dnumfe     f, fres
  cdef coeff_t   crres
  
  cdef fednum_t  cfres
  cdef darr_t    cRres
  
  cdef fedarr_t cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if tval is dnumfe:
    f = val
    if res_flag:
      
      fres = out
      fednum_acos_to( &f.num, &fres.num)

    else:

      cfres = fednum_acos( &f.num)
      res   = dnumfe.create(&cfres)

    # end if  
  elif tval is dmatfe:    
    F = val
    if res_flag:

      Fres = out
      fedarr_acos_to( &F.arr, &Fres.arr)

    else:

      cFres = fedarr_acos( &F.arr)
      res   = dmatfe.create(&cFres)

    # end if   
  elif tval is dmat:
    R = val
    if res_flag:
      
      Rres = out
      darr_acos_to( &R.arr, &Rres.arr)

    else:

      cRres = darr_acos( &R.arr )
      res = dmat.create( &cRres )

    # end if 
  elif tval in number_types:
    import math    
    r    = val
    rres = math.acos(r)
    if res_flag:      
      out = rres
    else:
      res = rres
    # end if   
  else:  
    raise TypeError("Unsupported types at acos operation.")    
    # return NotImplemented
  # end if 

  if res_flag == 0:
    return res
  # end if 

#-----------------------------------------------------------------------------------------------------






#*****************************************************************************************************
cpdef asin(object val, object out = None):
  """
  PURPOSE:  Matrix determinant.
  
  Supported types:

      -  matso
      -  dmatfe
      -  darr
      -  sotinum
      -  dnumfe
      -  real
  """
  #***************************************************************************************************

  
  cdef dmat       R, Rres
  cdef dmatfe    F, Fres
  
  cdef coeff_t    r, rres
  cdef dnumfe     f, fres
  cdef coeff_t   crres
  
  cdef fednum_t  cfres
  cdef darr_t    cRres
  
  cdef fedarr_t cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if tval is dnumfe:
    f = val
    if res_flag:
      
      fres = out
      fednum_asin_to( &f.num, &fres.num)

    else:

      cfres = fednum_asin( &f.num)
      res   = dnumfe.create(&cfres)

    # end if  
  elif tval is dmatfe:    
    F = val
    if res_flag:

      Fres = out
      fedarr_asin_to( &F.arr, &Fres.arr)

    else:

      cFres = fedarr_asin( &F.arr)
      res   = dmatfe.create(&cFres)

    # end if 
  elif tval is dmat:
    R = val
    if res_flag:
      
      Rres = out
      darr_asin_to( &R.arr, &Rres.arr)

    else:

      cRres = darr_asin( &R.arr )
      res = dmat.create( &cRres )

    # end if 
  elif tval in number_types:
    import math    
    r    = val
    rres = math.asin(r)
    if res_flag:      
      out = rres
    else:
      res = rres
    # end if   
  else:  
    raise TypeError("Unsupported types at asin operation.")    
    # return NotImplemented
  # end if 

  if res_flag == 0:
    return res
  # end if 

#-----------------------------------------------------------------------------------------------------



#*****************************************************************************************************
cpdef atan(object val, object out = None):
  """
  PURPOSE:  Matrix determinant.
  
  Supported types:

      -  matso
      -  dmatfe
      -  darr
      -  sotinum
      -  dnumfe
      -  real
  """
  #***************************************************************************************************

  
  cdef dmat       R, Rres
  cdef dmatfe    F, Fres
  
  cdef coeff_t    r, rres
  cdef dnumfe     f, fres
  cdef coeff_t   crres
  
  cdef fednum_t  cfres
  cdef darr_t    cRres
  
  cdef fedarr_t cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if tval is dnumfe:
    f = val
    if res_flag:
      
      fres = out
      fednum_atan_to( &f.num, &fres.num)

    else:

      cfres = fednum_atan( &f.num)
      res   = dnumfe.create(&cfres)

    # end if  
  elif tval is dmatfe:    
    F = val
    if res_flag:

      Fres = out
      fedarr_atan_to( &F.arr, &Fres.arr)

    else:

      cFres = fedarr_atan( &F.arr)
      res   = dmatfe.create(&cFres)

    # end if 
  elif tval is dmat:
    R = val
    if res_flag:
      
      Rres = out
      darr_atan_to( &R.arr, &Rres.arr)

    else:

      cRres = darr_atan( &R.arr )
      res = dmat.create( &cRres )

    # end if 
  elif tval in number_types:
    import math    
    r    = val
    rres = math.atan(r)
    if res_flag:      
      out = rres
    else:
      res = rres
    # end if   
  else:  
    raise TypeError("Unsupported types at atan operation.")    
    # return NotImplemented
  # end if 

  if res_flag == 0:
    return res
  # end if 

#-----------------------------------------------------------------------------------------------------



































#*****************************************************************************************************
cpdef sinh(object val, object out = None):
  """
  PURPOSE:  Matrix determinant.
  
  Supported types:

      -  matso
      -  dmatfe
      -  darr
      -  sotinum
      -  dnumfe
      -  real
  """
  #***************************************************************************************************

  
  cdef dmat       R, Rres
  cdef dmatfe    F, Fres
  
  cdef coeff_t    r, rres
  cdef dnumfe     f, fres
  cdef coeff_t   crres
  
  cdef fednum_t  cfres
  cdef darr_t    cRres
  
  cdef fedarr_t cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if tval is dnumfe:
    f = val
    if res_flag:
      
      fres = out
      fednum_sinh_to( &f.num, &fres.num)

    else:

      cfres = fednum_sinh( &f.num)
      res   = dnumfe.create(&cfres)

    # end if  
  elif tval is dmatfe:    
    F = val
    if res_flag:

      Fres = out
      fedarr_sinh_to( &F.arr, &Fres.arr)

    else:

      cFres = fedarr_sinh( &F.arr)
      res   = dmatfe.create(&cFres)

    # end if 
  elif tval is dmat:
    R = val
    if res_flag:
      
      Rres = out
      darr_sinh_to( &R.arr, &Rres.arr)

    else:

      cRres = darr_sinh( &R.arr )
      res = dmat.create( &cRres )

    # end if 
  elif tval in number_types:
    import math    
    r    = val
    rres = math.sinh(r)
    if res_flag:      
      out = rres
    else:
      res = rres
    # end if   
  else:  
    raise TypeError("Unsupported types at sinh operation.")    
    # return NotImplemented
  # end if 

  if res_flag == 0:
    return res
  # end if 

#-----------------------------------------------------------------------------------------------------




#*****************************************************************************************************
cpdef cosh(object val, object out = None):
  """
  PURPOSE:  Matrix determinant.
  
  Supported types:

      -  matso
      -  dmatfe
      -  darr
      -  sotinum
      -  dnumfe
      -  real
  """
  #***************************************************************************************************

  
  cdef dmat       R, Rres
  cdef dmatfe    F, Fres
  
  cdef coeff_t    r, rres
  cdef dnumfe     f, fres
  cdef coeff_t   crres
  
  cdef fednum_t  cfres
  cdef darr_t    cRres
  
  cdef fedarr_t cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if tval is dnumfe:
    f = val
    if res_flag:
      
      fres = out
      fednum_cosh_to( &f.num, &fres.num)

    else:

      cfres = fednum_cosh( &f.num)
      res   = dnumfe.create(&cfres)

    # end if  
  elif tval is dmatfe:    
    F = val
    if res_flag:

      Fres = out
      fedarr_cosh_to( &F.arr, &Fres.arr)

    else:

      cFres = fedarr_cosh( &F.arr)
      res   = dmatfe.create(&cFres)

    # end if 
  elif tval is dmat:
    R = val
    if res_flag:
      
      Rres = out
      darr_cosh_to( &R.arr, &Rres.arr)

    else:

      cRres = darr_cosh( &R.arr )
      res = dmat.create( &cRres )

    # end if 
  elif tval in number_types:
    import math    
    r    = val
    rres = math.cosh(r)
    if res_flag:      
      out = rres
    else:
      res = rres
    # end if   
  else:  
    raise TypeError("Unsupported types at cosh operation.")    
    # return NotImplemented
  # end if 

  if res_flag == 0:
    return res
  # end if 

#-----------------------------------------------------------------------------------------------------






#*****************************************************************************************************
cpdef tanh(object val, object out = None):
  """
  PURPOSE:  Matrix determinant.
  
  Supported types:

      -  matso
      -  dmatfe
      -  darr
      -  sotinum
      -  dnumfe
      -  real
  """
  #***************************************************************************************************

  
  cdef dmat       R, Rres
  cdef dmatfe    F, Fres
  
  cdef coeff_t    r, rres
  cdef dnumfe     f, fres
  cdef coeff_t   crres
  
  cdef fednum_t  cfres
  cdef darr_t    cRres
  
  cdef fedarr_t cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if tval is dnumfe:
    f = val
    if res_flag:
      
      fres = out
      fednum_tanh_to( &f.num, &fres.num)

    else:

      cfres = fednum_tanh( &f.num)
      res   = dnumfe.create(&cfres)

    # end if  
  elif tval is dmatfe:    
    F = val
    if res_flag:

      Fres = out
      fedarr_tanh_to( &F.arr, &Fres.arr)

    else:

      cFres = fedarr_tanh( &F.arr)
      res   = dmatfe.create(&cFres)

    # end if 
  elif tval is dmat:
    R = val
    if res_flag:
      
      Rres = out
      darr_tanh_to( &R.arr, &Rres.arr)

    else:

      cRres = darr_tanh( &R.arr )
      res = dmat.create( &cRres )

    # end if 
  elif tval in number_types:
    import math    
    r    = val
    rres = math.tanh(r)
    if res_flag:      
      out = rres
    else:
      res = rres
    # end if   
  else:  
    raise TypeError("Unsupported types at tanh operation.")    
    # return NotImplemented
  # end if 

  if res_flag == 0:
    return res
  # end if 

#-----------------------------------------------------------------------------------------------------





#*****************************************************************************************************
cpdef acosh(object val, object out = None):
  """
  PURPOSE:  Matrix determinant.
  
  Supported types:

      -  matso
      -  dmatfe
      -  darr
      -  sotinum
      -  dnumfe
      -  real
  """
  #***************************************************************************************************

  
  cdef dmat       R, Rres
  cdef dmatfe    F, Fres
  
  cdef coeff_t    r, rres
  cdef dnumfe     f, fres
  cdef coeff_t   crres
  
  cdef fednum_t  cfres
  cdef darr_t    cRres
  
  cdef fedarr_t cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if tval is dnumfe:
    f = val
    if res_flag:
      
      fres = out
      fednum_acosh_to( &f.num, &fres.num)

    else:

      cfres = fednum_acosh( &f.num)
      res   = dnumfe.create(&cfres)

    # end if  
  elif tval is dmatfe:    
    F = val
    if res_flag:

      Fres = out
      fedarr_acosh_to( &F.arr, &Fres.arr)

    else:

      cFres = fedarr_acosh( &F.arr)
      res   = dmatfe.create(&cFres)

    # end if 
  elif tval is dmat:
    R = val
    if res_flag:
      
      Rres = out
      darr_acosh_to( &R.arr, &Rres.arr)

    else:

      cRres = darr_acosh( &R.arr )
      res = dmat.create( &cRres )

    # end if 
  elif tval in number_types:
    import math    
    r    = val
    rres = math.acosh(r)
    if res_flag:      
      out = rres
    else:
      res = rres
    # end if   
  else:  
    raise TypeError("Unsupported types at acosh operation.")    
    # return NotImplemented
  # end if 

  if res_flag == 0:
    return res
  # end if 

#-----------------------------------------------------------------------------------------------------




#*****************************************************************************************************
cpdef asinh(object val, object out = None):
  """
  PURPOSE:  Matrix determinant.
  
  Supported types:

      -  matso
      -  dmatfe
      -  darr
      -  sotinum
      -  dnumfe
      -  real
  """
  #***************************************************************************************************

  
  cdef dmat       R, Rres
  cdef dmatfe    F, Fres
  
  cdef coeff_t    r, rres
  cdef dnumfe     f, fres
  cdef coeff_t   crres
  
  cdef fednum_t  cfres
  cdef darr_t    cRres
  
  cdef fedarr_t cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if tval is dnumfe:
    f = val
    if res_flag:
      
      fres = out
      fednum_asinh_to( &f.num, &fres.num)

    else:

      cfres = fednum_asinh( &f.num)
      res   = dnumfe.create(&cfres)

    # end if  
  elif tval is dmatfe:    
    F = val
    if res_flag:

      Fres = out
      fedarr_asinh_to( &F.arr, &Fres.arr)

    else:

      cFres = fedarr_asinh( &F.arr)
      res   = dmatfe.create(&cFres)

    # end if  
  elif tval is dmat:
    R = val
    if res_flag:
      
      Rres = out
      darr_asinh_to( &R.arr, &Rres.arr)

    else:

      cRres = darr_asinh( &R.arr )
      res = dmat.create( &cRres )

    # end if 
  elif tval in number_types:
    import math    
    r    = val
    rres = math.asinh(r)
    if res_flag:      
      out = rres
    else:
      res = rres
    # end if   
  else:  
    raise TypeError("Unsupported types at asinh operation.")    
    # return NotImplemented
  # end if 

  if res_flag == 0:
    return res
  # end if 

#-----------------------------------------------------------------------------------------------------



#*****************************************************************************************************
cpdef atanh(object val, object out = None):
  """
  PURPOSE:  Inverse hyperbolic tangent.
  
  Supported types:

      -  matso
      -  dmatfe
      -  darr
      -  sotinum
      -  dnumfe
      -  real
  """
  #***************************************************************************************************

  
  cdef dmat       R, Rres
  cdef dmatfe    F, Fres
  
  cdef coeff_t    r, rres
  cdef dnumfe     f, fres
  cdef coeff_t   crres
  
  cdef fednum_t  cfres
  cdef darr_t    cRres
  
  cdef fedarr_t cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if tval is dnumfe:
    f = val
    if res_flag:
      
      fres = out
      fednum_atanh_to( &f.num, &fres.num)

    else:

      cfres = fednum_atanh( &f.num)
      res   = dnumfe.create(&cfres)

    # end if  
  elif tval is dmatfe:    
    F = val
    if res_flag:

      Fres = out
      fedarr_atanh_to( &F.arr, &Fres.arr)

    else:

      cFres = fedarr_atanh( &F.arr)
      res   = dmatfe.create(&cFres)

    # end if 
  elif tval is dmat:
    R = val
    if res_flag:
      
      Rres = out
      darr_atanh_to( &R.arr, &Rres.arr)

    else:

      cRres = darr_atanh( &R.arr )
      res = dmat.create( &cRres )

    # end if 
  elif tval in number_types:
    import math    
    r    = val
    rres = math.atanh(r)
    if res_flag:      
      out = rres
    else:
      res = rres
    # end if   
  else:  
    raise TypeError("Unsupported types at atanh operation.")    
    # return NotImplemented
  # end if 

  if res_flag == 0:
    return res
  # end if 

#-----------------------------------------------------------------------------------------------------






























#*****************************************************************************************************
cpdef exp(object val, object out = None):
  """
  PURPOSE:  Exponential function.
  
  Supported types:

      -  matso
      -  dmatfe
      -  darr
      -  sotinum
      -  dnumfe
      -  real
  """
  #***************************************************************************************************

  
  cdef dmat       R, Rres
  cdef dmatfe    F, Fres
  
  cdef coeff_t    r, rres
  cdef dnumfe     f, fres
  cdef coeff_t   crres
  
  cdef fednum_t  cfres
  cdef darr_t    cRres
  
  cdef fedarr_t cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if tval is dnumfe:
    f = val
    if res_flag:
      
      fres = out
      fednum_exp_to( &f.num, &fres.num)

    else:

      cfres = fednum_exp( &f.num)
      res   = dnumfe.create(&cfres)

    # end if  
  elif tval is dmatfe:    
    F = val
    if res_flag:

      Fres = out
      fedarr_exp_to( &F.arr, &Fres.arr)

    else:

      cFres = fedarr_exp( &F.arr)
      res   = dmatfe.create(&cFres)

    # end if 
  elif tval is dmat:
    R = val
    if res_flag:
      
      Rres = out
      darr_exp_to( &R.arr, &Rres.arr)

    else:

      cRres = darr_exp( &R.arr )
      res = dmat.create( &cRres )

    # end if 
  elif tval in number_types:
    import math    
    r    = val
    rres = math.exp(r)
    if res_flag:      
      out = rres
    else:
      res = rres
    # end if   
  else:  
    raise TypeError("Unsupported types at exp operation.")    
    # return NotImplemented
  # end if 

  if res_flag == 0:
    return res
  # end if 

#-----------------------------------------------------------------------------------------------------


#*****************************************************************************************************
cpdef log(object val, object out = None):
  """
  PURPOSE:  Natural logarithm function.
  
  Supported types:

      -  matso
      -  dmatfe
      -  darr
      -  sotinum
      -  dnumfe
      -  real

  INPUTS:

    - val: Value to evaluate. Must be a supported one of the supported types.
    - out: (optional) Holder of result, in order to avoid memory allocation.

  OUTPUTS:

    If out is not defined, then the result is a newlly allocated member containing the result.
  """
  #***************************************************************************************************

  
  cdef dmat       R, Rres
  cdef dmatfe    F, Fres
  
  cdef coeff_t    r, rres
  cdef dnumfe     f, fres
  cdef coeff_t   crres
  
  cdef fednum_t  cfres
  cdef darr_t    cRres
  
  cdef fedarr_t cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if tval is dnumfe:
    f = val
    if res_flag:
      
      fres = out
      fednum_log_to( &f.num, &fres.num)

    else:

      cfres = fednum_log( &f.num)
      res   = dnumfe.create(&cfres)

    # end if  
  elif tval is dmatfe:    
    F = val
    if res_flag:

      Fres = out
      fedarr_log_to( &F.arr, &Fres.arr)

    else:

      cFres = fedarr_log( &F.arr)
      res   = dmatfe.create(&cFres)

    # end if 
  elif tval is dmat:
    R = val
    if res_flag:
      
      Rres = out
      darr_log_to( &R.arr, &Rres.arr)

    else:

      cRres = darr_log( &R.arr )
      res = dmat.create( &cRres )

    # end if 
  elif tval in number_types:
    import math    
    r    = val
    rres = math.log(r)
    if res_flag:      
      out = rres
    else:
      res = rres
    # end if   
  else:  
    raise TypeError("Unsupported types at log operation.")    
    # return NotImplemented
  # end if 

  if res_flag == 0:
    return res
  # end if 

#-----------------------------------------------------------------------------------------------------


#*****************************************************************************************************
cpdef log10(object val, object out = None):
  """
  PURPOSE:  Logarithm base 10 function.
  
  Supported types:

      -  matso
      -  dmatfe
      -  darr
      -  sotinum
      -  dnumfe
      -  real

  INPUTS:

    - val: Value to evaluate. Must be a supported one of the supported types.
    - out: (optional) Holder of result, in order to avoid memory allocation.

  OUTPUTS:

    If out is not defined, then the result is a newlly allocated member containing the result.
  """
  #***************************************************************************************************

  
  cdef dmat       R, Rres
  cdef dmatfe    F, Fres
  
  cdef coeff_t    r, rres
  cdef dnumfe     f, fres
  cdef coeff_t   crres
  
  cdef fednum_t  cfres
  cdef darr_t    cRres
  
  cdef fedarr_t cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if tval is dnumfe:
    f = val
    if res_flag:
      
      fres = out
      fednum_log10_to( &f.num, &fres.num)

    else:

      cfres = fednum_log10( &f.num)
      res   = dnumfe.create(&cfres)

    # end if  
  elif tval is dmatfe:    
    F = val
    if res_flag:

      Fres = out
      fedarr_log10_to( &F.arr, &Fres.arr)

    else:

      cFres = fedarr_log10( &F.arr)
      res   = dmatfe.create(&cFres)

    # end if 
  elif tval is dmat:
    R = val
    if res_flag:
      
      Rres = out
      darr_log10_to( &R.arr, &Rres.arr)

    else:

      cRres = darr_log10( &R.arr )
      res = dmat.create( &cRres )

    # end if 
  elif tval in number_types:
    import math    
    r    = val
    rres = math.log10(r)
    if res_flag:      
      out = rres
    else:
      res = rres
    # end if   
  else:  
    raise TypeError("Unsupported types at log10 operation.")    
    # return NotImplemented
  # end if 

  if res_flag == 0:
    return res
  # end if 

#-----------------------------------------------------------------------------------------------------


#*****************************************************************************************************
cpdef logb(object val, coeff_t b, object out = None):
  """
  PURPOSE:  Logarithm of base b
  
  Supported types:

      -  matso
      -  dmatfe
      -  darr
      -  sotinum
      -  dnumfe
      -  real

  INPUTS:

    - val: Value to evaluate. Must be a supported one of the supported types.
    - b:   Base.
    - out: (optional) Holder of result, in order to avoid memory allocation.

  OUTPUTS:

    If out is not defined, then the result is a newlly allocated member containing the result.
  """
  #***************************************************************************************************

  
  cdef dmat       R, Rres
  cdef dmatfe    F, Fres
  
  cdef coeff_t    r, rres
  cdef dnumfe     f, fres
  cdef coeff_t   crres
  
  cdef fednum_t  cfres
  cdef darr_t    cRres
  
  cdef fedarr_t cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if tval is dnumfe:
    f = val
    if res_flag:
      
      fres = out
      fednum_logb_to( &f.num, b, &fres.num)

    else:

      cfres = fednum_logb( &f.num, b)
      res   = dnumfe.create(&cfres)

    # end if  
  elif tval is dmatfe:    
    F = val
    if res_flag:

      Fres = out
      fedarr_logb_to( &F.arr, b, &Fres.arr)

    else:

      cFres = fedarr_logb( &F.arr, b)
      res   = dmatfe.create(&cFres)

    # end if 
  elif tval is dmat:
    R = val
    if res_flag:
      
      Rres = out
      darr_logb_to( &R.arr, b, &Rres.arr)

    else:

      cRres = darr_logb( &R.arr , b)
      res = dmat.create( &cRres )

    # end if 
  elif tval in number_types:
    import math    
    r    = val
    rres = math.logb(r,b)
    if res_flag:      
      out = rres
    else:
      res = rres
    # end if   
  else:  
    raise TypeError("Unsupported types at logber operation.")    
    # return NotImplemented
  # end if 

  if res_flag == 0:
    return res
  # end if 

#-----------------------------------------------------------------------------------------------------






#*****************************************************************************************************
cpdef sqrt(object val, object out = None):
  """
  PURPOSE:  Square root function.
  
  Supported types:

      -  matso
      -  dmatfe
      -  darr
      -  sotinum
      -  dnumfe
      -  real

  INPUTS:

    - val: Value to evaluate. Must be a supported one of the supported types.
    - out: (optional) Holder of result, in order to avoid memory allocation.

  OUTPUTS:

    If out is not defined, then the result is a newlly allocated member containing the result.
  """
  #***************************************************************************************************

  
  cdef dmat       R, Rres
  cdef dmatfe    F, Fres
  
  cdef coeff_t    r, rres
  cdef dnumfe     f, fres
  cdef coeff_t   crres
  
  cdef fednum_t  cfres
  cdef darr_t    cRres
  
  cdef fedarr_t cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if tval is dnumfe:
    f = val
    if res_flag:
      
      fres = out
      fednum_sqrt_to( &f.num, &fres.num)

    else:

      cfres = fednum_sqrt( &f.num)
      res   = dnumfe.create(&cfres)

    # end if  
  elif tval is dmatfe:    
    F = val
    if res_flag:

      Fres = out
      fedarr_sqrt_to( &F.arr, &Fres.arr)

    else:

      cFres = fedarr_sqrt( &F.arr)
      res   = dmatfe.create(&cFres)

    # end if 
  elif tval is dmat:
    R = val
    if res_flag:
      
      Rres = out
      darr_sqrt_to( &R.arr, &Rres.arr)

    else:

      cRres = darr_sqrt( &R.arr )
      res = dmat.create( &cRres )

    # end if 
  elif tval in number_types:
    import math    
    r    = val
    rres = math.sqrt(r)
    if res_flag:      
      out = rres
    else:
      res = rres
    # end if   
  else:  
    raise TypeError("Unsupported types at sqrt operation.")
  # end if 

  if res_flag == 0:
    return res
  # end if 

#-----------------------------------------------------------------------------------------------------






#*****************************************************************************************************
cpdef cbrt(object val, object out = None):
  """
  PURPOSE:  Cubic root function.
  
  Supported types:

      -  matso
      -  dmatfe
      -  darr
      -  sotinum
      -  dnumfe
      -  real

  INPUTS:

    - val: Value to evaluate. Must be a supported one of the supported types.
    - out: (optional) Holder of result, in order to avoid memory allocation.

  OUTPUTS:

    If out is not defined, then the result is a newlly allocated member containing the result.
  """
  #***************************************************************************************************

  
  cdef dmat       R, Rres
  cdef dmatfe    F, Fres
  
  cdef coeff_t    r, rres
  cdef dnumfe     f, fres
  cdef coeff_t   crres
  
  cdef fednum_t  cfres
  cdef darr_t    cRres
  
  cdef fedarr_t cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if tval is dnumfe:
    f = val
    if res_flag:
      
      fres = out
      fednum_cbrt_to( &f.num, &fres.num)

    else:

      cfres = fednum_cbrt( &f.num)
      res   = dnumfe.create(&cfres)

    # end if  
  elif tval is dmatfe:    
    F = val
    if res_flag:

      Fres = out
      fedarr_cbrt_to( &F.arr, &Fres.arr)

    else:

      cFres = fedarr_cbrt( &F.arr)
      res   = dmatfe.create(&cFres)

    # end if 
  elif tval is dmat:
    R = val
    if res_flag:
      
      Rres = out
      darr_cbrt_to( &R.arr, &Rres.arr)

    else:

      cRres = darr_cbrt( &R.arr )
      res = dmat.create( &cRres )

    # end if 
  elif tval in number_types:
    import math    
    r    = val
    rres = math.cbrt(r)
    if res_flag:      
      out = rres
    else:
      res = rres
    # end if   
  else:  
    raise TypeError("Unsupported types at cbrt operation.")    
    # return NotImplemented
  # end if 

  if res_flag == 0:
    return res
  # end if 

#-----------------------------------------------------------------------------------------------------








#*****************************************************************************************************
cpdef pow(object val, coeff_t e, object out = None):
  """
  PURPOSE:  Power function.
  
  Supported types:

      -  matso
      -  dmatfe
      -  darr
      -  sotinum
      -  dnumfe
      -  real

  INPUTS:

    - val: Value to evaluate. Must be a supported one of the supported types.
    - e:   exponent.
    - out: (optional) Holder of result, in order to avoid memory allocation.

  OUTPUTS:

    If out is not defined, then the result is a newlly allocated member containing the result.
  """
  #***************************************************************************************************

  
  cdef dmat       R, Rres
  cdef dmatfe    F, Fres
  
  cdef coeff_t    r, rres
  cdef dnumfe     f, fres
  cdef coeff_t   crres
  
  cdef fednum_t  cfres
  cdef darr_t    cRres
  
  cdef fedarr_t cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if tval is dnumfe:
    f = val
    if res_flag:
      
      fres = out
      fednum_pow_to( &f.num, e, &fres.num)

    else:

      cfres = fednum_pow( &f.num, e)
      res   = dnumfe.create(&cfres)

    # end if  
  elif tval is dmatfe:    
    F = val
    if res_flag:

      Fres = out
      fedarr_pow_to( &F.arr, e, &Fres.arr)

    else:

      cFres = fedarr_pow( &F.arr, e)
      res   = dmatfe.create(&cFres)

    # end if 
  elif tval is dmat:
    R = val
    if res_flag:
      
      Rres = out
      darr_pow_to( &R.arr, e, &Rres.arr)

    else:

      cRres = darr_pow( &R.arr , e)
      res = dmat.create( &cRres )

    # end if 
  elif tval in number_types:
    import math    
    r    = val
    rres = math.pow(r,e)
    if res_flag:      
      out = rres
    else:
      res = rres
    # end if   
  else:  
    raise TypeError("Unsupported types at power operation.")    
    # return NotImplemented
  # end if 

  if res_flag == 0:
    return res
  # end if 

#-----------------------------------------------------------------------------------------------------






#*****************************************************************************************************
cpdef gauss_integrate(object val, dnumfe w, object out = None ):
  """
  PURPOSE: Integrate using Gauss rule.

  INPUTS:

    - val: Value to integrate. Must be a constant
    - w:   Integration weights.
    - out: (optional) Holder of result, in order to avoid memory allocation.

  OUTPUTS:

    If out is not defined, then the result is a newlly allocated member containing the integration 
    result.

  """
  #***************************************************************************************************
  global dhl

  
  cdef dmat       R, Rres
  cdef dmatfe    F, Fres
  
  cdef coeff_t    r, rres
  cdef dnumfe     f, fres
  cdef coeff_t   crres
  
  cdef fednum_t  cfres
  cdef darr_t    cRres
  
  cdef fedarr_t cFres 
  cdef uint8_t res_flag = 1
  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if

  if   tval is dnumfe:
    f = val
    if res_flag:
      
      rres = out
      fednum_integrate_f_to( &f.num, &w.num, &rres)

    else:

      crres = fednum_integrate_f( &f.num, &w.num)
      res   = crres

    # end if  
  elif tval is dmatfe:
    F = val
    if res_flag:

      Rres = out
      fedarr_integrate_to( &F.arr, &w.num, &Rres.arr)

    else:

      cRres = fedarr_integrate( &F.arr, &w.num)
      res   = dmat.create(&cRres)

    # end if 
  else:
    try:
      r = val
      if res_flag:
        
        rres = out
        fednum_integrate_r_to( r, &w.num, &rres)

      else:

        crres = fednum_integrate_r( r, &w.num)
        res   = crres

      # end if  
    except:

      raise TypeError("Unsupported type {0} at gauss_integrate operation.".format(tval))
    
    # end try

  # end if 

  if res_flag == 0:
    return res
  # end if 

#-----------------------------------------------------------------------------------------------------


#*****************************************************************************************************
cpdef neg(object val, object out = None):
  """
  PURPOSE:  Algebraic negation.
  
  Supported types:

      -  matso
      -  dmatfe
      -  darr
      -  sotinum
      -  dnumfe
      -  real
  """
  #***************************************************************************************************

  
  cdef dmat       R, Rres
  cdef dmatfe    F, Fres
  
  cdef coeff_t    r, rres
  cdef dnumfe     f, fres
  cdef coeff_t   crres
  
  cdef fednum_t  cfres
  cdef darr_t    cRres
  
  cdef fedarr_t cFres
  cdef uint8_t res_flag = 1
  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 
  #
  if tval is dnumfe:
    f = val
    if res_flag:
      
      fres = out
      fednum_neg_to( &f.num, &fres.num)

    else:

      cfres = fednum_neg( &f.num)
      res   = dnumfe.create(&cfres)

    # end if         
  elif tval is dmatfe:    
    F = val
    if res_flag:

      Fres = out
      fedarr_neg_to( &F.arr, &Fres.arr)

    else:

      cFres = fedarr_neg( &F.arr)
      res   = dmatfe.create(&cFres)

    # end if 
  elif tval is dmat:
    R = val
    if res_flag:
      
      Rres = out
      darr_neg_to( &R.arr, &Rres.arr)

    else:

      cRres = darr_neg( &R.arr )
      res = dmat.create( &cRres )

    # end if 
  elif tval in number_types:
    import math    
    r    = val
    rres = -r
    if res_flag:      
      out = rres
    else:
      res = rres
    # end if   
  else:
    raise TypeError("Unsupported types at cos operation.")    
  # end if 

  if res_flag == 0:
    return res
  # end if 

#-----------------------------------------------------------------------------------------------------



