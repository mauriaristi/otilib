#*****************************************************************************************************
cpdef cos(object val, object out = None):
  """
  PURPOSE:  Matrix determinant.
  
  Supported types:

      -  omatm4n4
      -  feomatm4n4
      -  darr
      -  onumm4n4
      -  feonumm4n4
      -  real
  """
  #***************************************************************************************************

  cdef omatm4n4      O, Ores
  cdef dmat       R, Rres
  cdef feomatm4n4    F, Fres
  cdef onumm4n4    o, ores
  cdef coeff_t    r, rres
  cdef feonumm4n4     f, fres
  cdef coeff_t   crres
  cdef onumm4n4_t cores
  cdef feonumm4n4_t  cfres
  cdef darr_t    cRres
  cdef oarrm4n4_t   cOres
  cdef feoarrm4n4_t cFres
  cdef uint8_t res_flag = 1
  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 
  #
  if   tval is onumm4n4:
    o = val
    if res_flag:
      
      ores = out
      onumm4n4_cos_to( &o.num, &ores.num)

    else:

      cores = onumm4n4_cos( &o.num)
      res   = onumm4n4.create(&cores)

    # end if 
  elif tval is feonumm4n4:
    f = val
    if res_flag:
      
      fres = out
      feonumm4n4_cos_to( &f.num, &fres.num)

    else:

      cfres = feonumm4n4_cos( &f.num)
      res   = feonumm4n4.create(&cfres)

    # end if         
  elif tval is feomatm4n4:    
    F = val
    if res_flag:

      Fres = out
      feoarrm4n4_cos_to( &F.arr, &Fres.arr)

    else:

      cFres = feoarrm4n4_cos( &F.arr)
      res   = feomatm4n4.create(&cFres)

    # end if 
  elif tval is omatm4n4:
    O = val
    if res_flag:
      
      Ores = out
      oarrm4n4_cos_to( &O.arr, &Ores.arr)

    else:

      cOres = oarrm4n4_cos( &O.arr)
      res   = omatm4n4.create(&cOres)

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

      -  omatm4n4
      -  feomatm4n4
      -  darr
      -  onumm4n4
      -  feonumm4n4
      -  real
  """
  #***************************************************************************************************

  cdef omatm4n4      O, Ores
  cdef dmat       R, Rres
  cdef feomatm4n4    F, Fres
  cdef onumm4n4    o, ores
  cdef coeff_t    r, rres
  cdef feonumm4n4     f, fres
  cdef coeff_t   crres
  cdef onumm4n4_t cores
  cdef feonumm4n4_t  cfres
  cdef darr_t    cRres
  cdef oarrm4n4_t   cOres
  cdef feoarrm4n4_t cFres
  cdef uint8_t res_flag = 1
  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if   tval is onumm4n4:
    o = val
    if res_flag:
      
      ores = out
      onumm4n4_sin_to( &o.num, &ores.num)

    else:

      cores = onumm4n4_sin( &o.num)
      res   = onumm4n4.create(&cores)

    # end if 
  elif tval is feonumm4n4:
    f = val
    if res_flag:
      
      fres = out
      feonumm4n4_sin_to( &f.num, &fres.num)

    else:

      cfres = feonumm4n4_sin( &f.num)
      res   = feonumm4n4.create(&cfres)

    # end if  
  elif tval is feomatm4n4:    
    F = val
    if res_flag:

      Fres = out
      feoarrm4n4_sin_to( &F.arr, &Fres.arr)

    else:

      cFres = feoarrm4n4_sin( &F.arr)
      res   = feomatm4n4.create(&cFres)

    # end if 
  elif tval is omatm4n4:
    O = val
    if res_flag:
      
      Ores = out
      oarrm4n4_sin_to( &O.arr, &Ores.arr)

    else:

      cOres = oarrm4n4_sin( &O.arr)
      res   = omatm4n4.create(&cOres)

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

      -  omatm4n4
      -  feomatm4n4
      -  darr
      -  onumm4n4
      -  feonumm4n4
      -  real
  """
  #***************************************************************************************************

  cdef omatm4n4      O, Ores
  cdef dmat       R, Rres
  cdef feomatm4n4    F, Fres
  cdef onumm4n4    o, ores
  cdef coeff_t    r, rres
  cdef feonumm4n4     f, fres
  cdef coeff_t   crres
  cdef onumm4n4_t cores
  cdef feonumm4n4_t  cfres
  cdef darr_t    cRres
  cdef oarrm4n4_t   cOres
  cdef feoarrm4n4_t cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if   tval is onumm4n4:
    o = val
    if res_flag:
      
      ores = out
      onumm4n4_tan_to( &o.num, &ores.num)

    else:

      cores = onumm4n4_tan( &o.num)
      res   = onumm4n4.create(&cores)

    # end if 
  elif tval is feonumm4n4:
    f = val
    if res_flag:
      
      fres = out
      feonumm4n4_tan_to( &f.num, &fres.num)

    else:

      cfres = feonumm4n4_tan( &f.num)
      res   = feonumm4n4.create(&cfres)

    # end if  
  elif tval is feomatm4n4:    
    F = val
    if res_flag:

      Fres = out
      feoarrm4n4_tan_to( &F.arr, &Fres.arr)

    else:

      cFres = feoarrm4n4_tan( &F.arr)
      res   = feomatm4n4.create(&cFres)

    # end if 
  elif tval is omatm4n4:
    O = val
    if res_flag:
      
      Ores = out
      oarrm4n4_tan_to( &O.arr, &Ores.arr)

    else:

      cOres = oarrm4n4_tan( &O.arr)
      res   = omatm4n4.create(&cOres)

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

      -  omatm4n4
      -  feomatm4n4
      -  darr
      -  onumm4n4
      -  feonumm4n4
      -  real
  """
  #***************************************************************************************************

  cdef omatm4n4      O, Ores
  cdef dmat       R, Rres
  cdef feomatm4n4    F, Fres
  cdef onumm4n4    o, ores
  cdef coeff_t    r, rres
  cdef feonumm4n4     f, fres
  cdef coeff_t   crres
  cdef onumm4n4_t cores
  cdef feonumm4n4_t  cfres
  cdef darr_t    cRres
  cdef oarrm4n4_t   cOres
  cdef feoarrm4n4_t cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if   tval is onumm4n4:
    o = val
    if res_flag:
      
      ores = out
      onumm4n4_acos_to( &o.num, &ores.num)

    else:

      cores = onumm4n4_acos( &o.num)
      res   = onumm4n4.create(&cores)

    # end if 
  elif tval is feonumm4n4:
    f = val
    if res_flag:
      
      fres = out
      feonumm4n4_acos_to( &f.num, &fres.num)

    else:

      cfres = feonumm4n4_acos( &f.num)
      res   = feonumm4n4.create(&cfres)

    # end if  
  elif tval is feomatm4n4:    
    F = val
    if res_flag:

      Fres = out
      feoarrm4n4_acos_to( &F.arr, &Fres.arr)

    else:

      cFres = feoarrm4n4_acos( &F.arr)
      res   = feomatm4n4.create(&cFres)

    # end if 
  elif tval is omatm4n4:
    O = val
    if res_flag:
      
      Ores = out
      oarrm4n4_acos_to( &O.arr, &Ores.arr)

    else:

      cOres = oarrm4n4_acos( &O.arr)
      res   = omatm4n4.create(&cOres)

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

      -  omatm4n4
      -  feomatm4n4
      -  darr
      -  onumm4n4
      -  feonumm4n4
      -  real
  """
  #***************************************************************************************************

  cdef omatm4n4      O, Ores
  cdef dmat       R, Rres
  cdef feomatm4n4    F, Fres
  cdef onumm4n4    o, ores
  cdef coeff_t    r, rres
  cdef feonumm4n4     f, fres
  cdef coeff_t   crres
  cdef onumm4n4_t cores
  cdef feonumm4n4_t  cfres
  cdef darr_t    cRres
  cdef oarrm4n4_t   cOres
  cdef feoarrm4n4_t cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if   tval is onumm4n4:
    o = val
    if res_flag:
      
      ores = out
      onumm4n4_asin_to( &o.num, &ores.num)

    else:

      cores = onumm4n4_asin( &o.num)
      res   = onumm4n4.create(&cores)

    # end if 
  elif tval is feonumm4n4:
    f = val
    if res_flag:
      
      fres = out
      feonumm4n4_asin_to( &f.num, &fres.num)

    else:

      cfres = feonumm4n4_asin( &f.num)
      res   = feonumm4n4.create(&cfres)

    # end if  
  elif tval is feomatm4n4:    
    F = val
    if res_flag:

      Fres = out
      feoarrm4n4_asin_to( &F.arr, &Fres.arr)

    else:

      cFres = feoarrm4n4_asin( &F.arr)
      res   = feomatm4n4.create(&cFres)

    # end if 
  elif tval is omatm4n4:
    O = val
    if res_flag:
      
      Ores = out
      oarrm4n4_asin_to( &O.arr, &Ores.arr)

    else:

      cOres = oarrm4n4_asin( &O.arr)
      res   = omatm4n4.create(&cOres)

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

      -  omatm4n4
      -  feomatm4n4
      -  darr
      -  onumm4n4
      -  feonumm4n4
      -  real
  """
  #***************************************************************************************************

  cdef omatm4n4      O, Ores
  cdef dmat       R, Rres
  cdef feomatm4n4    F, Fres
  cdef onumm4n4    o, ores
  cdef coeff_t    r, rres
  cdef feonumm4n4     f, fres
  cdef coeff_t   crres
  cdef onumm4n4_t cores
  cdef feonumm4n4_t  cfres
  cdef darr_t    cRres
  cdef oarrm4n4_t   cOres
  cdef feoarrm4n4_t cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if   tval is onumm4n4:
    o = val
    if res_flag:
      
      ores = out
      onumm4n4_atan_to( &o.num, &ores.num)

    else:

      cores = onumm4n4_atan( &o.num)
      res   = onumm4n4.create(&cores)

    # end if 
  elif tval is feonumm4n4:
    f = val
    if res_flag:
      
      fres = out
      feonumm4n4_atan_to( &f.num, &fres.num)

    else:

      cfres = feonumm4n4_atan( &f.num)
      res   = feonumm4n4.create(&cfres)

    # end if  
  elif tval is feomatm4n4:    
    F = val
    if res_flag:

      Fres = out
      feoarrm4n4_atan_to( &F.arr, &Fres.arr)

    else:

      cFres = feoarrm4n4_atan( &F.arr)
      res   = feomatm4n4.create(&cFres)

    # end if 
  elif tval is omatm4n4:
    O = val
    if res_flag:
      
      Ores = out
      oarrm4n4_atan_to( &O.arr, &Ores.arr)

    else:

      cOres = oarrm4n4_atan( &O.arr)
      res   = omatm4n4.create(&cOres)

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

      -  omatm4n4
      -  feomatm4n4
      -  darr
      -  onumm4n4
      -  feonumm4n4
      -  real
  """
  #***************************************************************************************************

  cdef omatm4n4      O, Ores
  cdef dmat       R, Rres
  cdef feomatm4n4    F, Fres
  cdef onumm4n4    o, ores
  cdef coeff_t    r, rres
  cdef feonumm4n4     f, fres
  cdef coeff_t   crres
  cdef onumm4n4_t cores
  cdef feonumm4n4_t  cfres
  cdef darr_t    cRres
  cdef oarrm4n4_t   cOres
  cdef feoarrm4n4_t cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if   tval is onumm4n4:
    o = val
    if res_flag:
      
      ores = out
      onumm4n4_sinh_to( &o.num, &ores.num)

    else:

      cores = onumm4n4_sinh( &o.num)
      res   = onumm4n4.create(&cores)

    # end if 
  elif tval is feonumm4n4:
    f = val
    if res_flag:
      
      fres = out
      feonumm4n4_sinh_to( &f.num, &fres.num)

    else:

      cfres = feonumm4n4_sinh( &f.num)
      res   = feonumm4n4.create(&cfres)

    # end if  
  elif tval is feomatm4n4:    
    F = val
    if res_flag:

      Fres = out
      feoarrm4n4_sinh_to( &F.arr, &Fres.arr)

    else:

      cFres = feoarrm4n4_sinh( &F.arr)
      res   = feomatm4n4.create(&cFres)

    # end if 
  elif tval is omatm4n4:
    O = val
    if res_flag:
      
      Ores = out
      oarrm4n4_sinh_to( &O.arr, &Ores.arr)

    else:

      cOres = oarrm4n4_sinh( &O.arr)
      res   = omatm4n4.create(&cOres)

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

      -  omatm4n4
      -  feomatm4n4
      -  darr
      -  onumm4n4
      -  feonumm4n4
      -  real
  """
  #***************************************************************************************************

  cdef omatm4n4      O, Ores
  cdef dmat       R, Rres
  cdef feomatm4n4    F, Fres
  cdef onumm4n4    o, ores
  cdef coeff_t    r, rres
  cdef feonumm4n4     f, fres
  cdef coeff_t   crres
  cdef onumm4n4_t cores
  cdef feonumm4n4_t  cfres
  cdef darr_t    cRres
  cdef oarrm4n4_t   cOres
  cdef feoarrm4n4_t cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if   tval is onumm4n4:
    o = val
    if res_flag:
      
      ores = out
      onumm4n4_cosh_to( &o.num, &ores.num)

    else:

      cores = onumm4n4_cosh( &o.num)
      res   = onumm4n4.create(&cores)

    # end if 
  elif tval is feonumm4n4:
    f = val
    if res_flag:
      
      fres = out
      feonumm4n4_cosh_to( &f.num, &fres.num)

    else:

      cfres = feonumm4n4_cosh( &f.num)
      res   = feonumm4n4.create(&cfres)

    # end if  
  elif tval is feomatm4n4:    
    F = val
    if res_flag:

      Fres = out
      feoarrm4n4_cosh_to( &F.arr, &Fres.arr)

    else:

      cFres = feoarrm4n4_cosh( &F.arr)
      res   = feomatm4n4.create(&cFres)

    # end if 
  elif tval is omatm4n4:
    O = val
    if res_flag:
      
      Ores = out
      oarrm4n4_cosh_to( &O.arr, &Ores.arr)

    else:

      cOres = oarrm4n4_cosh( &O.arr)
      res   = omatm4n4.create(&cOres)

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

      -  omatm4n4
      -  feomatm4n4
      -  darr
      -  onumm4n4
      -  feonumm4n4
      -  real
  """
  #***************************************************************************************************

  cdef omatm4n4      O, Ores
  cdef dmat       R, Rres
  cdef feomatm4n4    F, Fres
  cdef onumm4n4    o, ores
  cdef coeff_t    r, rres
  cdef feonumm4n4     f, fres
  cdef coeff_t   crres
  cdef onumm4n4_t cores
  cdef feonumm4n4_t  cfres
  cdef darr_t    cRres
  cdef oarrm4n4_t   cOres
  cdef feoarrm4n4_t cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if   tval is onumm4n4:
    o = val
    if res_flag:
      
      ores = out
      onumm4n4_tanh_to( &o.num, &ores.num)

    else:

      cores = onumm4n4_tanh( &o.num)
      res   = onumm4n4.create(&cores)

    # end if 
  elif tval is feonumm4n4:
    f = val
    if res_flag:
      
      fres = out
      feonumm4n4_tanh_to( &f.num, &fres.num)

    else:

      cfres = feonumm4n4_tanh( &f.num)
      res   = feonumm4n4.create(&cfres)

    # end if  
  elif tval is feomatm4n4:    
    F = val
    if res_flag:

      Fres = out
      feoarrm4n4_tanh_to( &F.arr, &Fres.arr)

    else:

      cFres = feoarrm4n4_tanh( &F.arr)
      res   = feomatm4n4.create(&cFres)

    # end if 
  elif tval is omatm4n4:
    O = val
    if res_flag:
      
      Ores = out
      oarrm4n4_tanh_to( &O.arr, &Ores.arr)

    else:

      cOres = oarrm4n4_tanh( &O.arr)
      res   = omatm4n4.create(&cOres)

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

      -  omatm4n4
      -  feomatm4n4
      -  darr
      -  onumm4n4
      -  feonumm4n4
      -  real
  """
  #***************************************************************************************************

  cdef omatm4n4      O, Ores
  cdef dmat       R, Rres
  cdef feomatm4n4    F, Fres
  cdef onumm4n4    o, ores
  cdef coeff_t    r, rres
  cdef feonumm4n4     f, fres
  cdef coeff_t   crres
  cdef onumm4n4_t cores
  cdef feonumm4n4_t  cfres
  cdef darr_t    cRres
  cdef oarrm4n4_t   cOres
  cdef feoarrm4n4_t cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if   tval is onumm4n4:
    o = val
    if res_flag:
      
      ores = out
      onumm4n4_acosh_to( &o.num, &ores.num)

    else:

      cores = onumm4n4_acosh( &o.num)
      res   = onumm4n4.create(&cores)

    # end if 
  elif tval is feonumm4n4:
    f = val
    if res_flag:
      
      fres = out
      feonumm4n4_acosh_to( &f.num, &fres.num)

    else:

      cfres = feonumm4n4_acosh( &f.num)
      res   = feonumm4n4.create(&cfres)

    # end if  
  elif tval is feomatm4n4:    
    F = val
    if res_flag:

      Fres = out
      feoarrm4n4_acosh_to( &F.arr, &Fres.arr)

    else:

      cFres = feoarrm4n4_acosh( &F.arr)
      res   = feomatm4n4.create(&cFres)

    # end if 
  elif tval is omatm4n4:
    O = val
    if res_flag:
      
      Ores = out
      oarrm4n4_acosh_to( &O.arr, &Ores.arr)

    else:

      cOres = oarrm4n4_acosh( &O.arr)
      res   = omatm4n4.create(&cOres)

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

      -  omatm4n4
      -  feomatm4n4
      -  darr
      -  onumm4n4
      -  feonumm4n4
      -  real
  """
  #***************************************************************************************************

  cdef omatm4n4      O, Ores
  cdef dmat       R, Rres
  cdef feomatm4n4    F, Fres
  cdef onumm4n4    o, ores
  cdef coeff_t    r, rres
  cdef feonumm4n4     f, fres
  cdef coeff_t   crres
  cdef onumm4n4_t cores
  cdef feonumm4n4_t  cfres
  cdef darr_t    cRres
  cdef oarrm4n4_t   cOres
  cdef feoarrm4n4_t cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if   tval is onumm4n4:
    o = val
    if res_flag:
      
      ores = out
      onumm4n4_asinh_to( &o.num, &ores.num)

    else:

      cores = onumm4n4_asinh( &o.num)
      res   = onumm4n4.create(&cores)

    # end if 
  elif tval is feonumm4n4:
    f = val
    if res_flag:
      
      fres = out
      feonumm4n4_asinh_to( &f.num, &fres.num)

    else:

      cfres = feonumm4n4_asinh( &f.num)
      res   = feonumm4n4.create(&cfres)

    # end if  
  elif tval is feomatm4n4:    
    F = val
    if res_flag:

      Fres = out
      feoarrm4n4_asinh_to( &F.arr, &Fres.arr)

    else:

      cFres = feoarrm4n4_asinh( &F.arr)
      res   = feomatm4n4.create(&cFres)

    # end if 
  elif tval is omatm4n4:
    O = val
    if res_flag:
      
      Ores = out
      oarrm4n4_asinh_to( &O.arr, &Ores.arr)

    else:

      cOres = oarrm4n4_asinh( &O.arr)
      res   = omatm4n4.create(&cOres)

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

      -  omatm4n4
      -  feomatm4n4
      -  darr
      -  onumm4n4
      -  feonumm4n4
      -  real
  """
  #***************************************************************************************************

  cdef omatm4n4      O, Ores
  cdef dmat       R, Rres
  cdef feomatm4n4    F, Fres
  cdef onumm4n4    o, ores
  cdef coeff_t    r, rres
  cdef feonumm4n4     f, fres
  cdef coeff_t   crres
  cdef onumm4n4_t cores
  cdef feonumm4n4_t  cfres
  cdef darr_t    cRres
  cdef oarrm4n4_t   cOres
  cdef feoarrm4n4_t cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if   tval is onumm4n4:
    o = val
    if res_flag:
      
      ores = out
      onumm4n4_atanh_to( &o.num, &ores.num)

    else:

      cores = onumm4n4_atanh( &o.num)
      res   = onumm4n4.create(&cores)

    # end if 
  elif tval is feonumm4n4:
    f = val
    if res_flag:
      
      fres = out
      feonumm4n4_atanh_to( &f.num, &fres.num)

    else:

      cfres = feonumm4n4_atanh( &f.num)
      res   = feonumm4n4.create(&cfres)

    # end if  
  elif tval is feomatm4n4:    
    F = val
    if res_flag:

      Fres = out
      feoarrm4n4_atanh_to( &F.arr, &Fres.arr)

    else:

      cFres = feoarrm4n4_atanh( &F.arr)
      res   = feomatm4n4.create(&cFres)

    # end if 
  elif tval is omatm4n4:
    O = val
    if res_flag:
      
      Ores = out
      oarrm4n4_atanh_to( &O.arr, &Ores.arr)

    else:

      cOres = oarrm4n4_atanh( &O.arr)
      res   = omatm4n4.create(&cOres)

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

      -  omatm4n4
      -  feomatm4n4
      -  darr
      -  onumm4n4
      -  feonumm4n4
      -  real
  """
  #***************************************************************************************************

  cdef omatm4n4      O, Ores
  cdef dmat       R, Rres
  cdef feomatm4n4    F, Fres
  cdef onumm4n4    o, ores
  cdef coeff_t    r, rres
  cdef feonumm4n4     f, fres
  cdef coeff_t   crres
  cdef onumm4n4_t cores
  cdef feonumm4n4_t  cfres
  cdef darr_t    cRres
  cdef oarrm4n4_t   cOres
  cdef feoarrm4n4_t cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if   tval is onumm4n4:
    o = val
    if res_flag:
      
      ores = out
      onumm4n4_exp_to( &o.num, &ores.num)

    else:

      cores = onumm4n4_exp( &o.num)
      res   = onumm4n4.create(&cores)

    # end if 
  elif tval is feonumm4n4:
    f = val
    if res_flag:
      
      fres = out
      feonumm4n4_exp_to( &f.num, &fres.num)

    else:

      cfres = feonumm4n4_exp( &f.num)
      res   = feonumm4n4.create(&cfres)

    # end if  
  elif tval is feomatm4n4:    
    F = val
    if res_flag:

      Fres = out
      feoarrm4n4_exp_to( &F.arr, &Fres.arr)

    else:

      cFres = feoarrm4n4_exp( &F.arr)
      res   = feomatm4n4.create(&cFres)

    # end if 
  elif tval is omatm4n4:
    O = val
    if res_flag:
      
      Ores = out
      oarrm4n4_exp_to( &O.arr, &Ores.arr)

    else:

      cOres = oarrm4n4_exp( &O.arr)
      res   = omatm4n4.create(&cOres)

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

      -  omatm4n4
      -  feomatm4n4
      -  darr
      -  onumm4n4
      -  feonumm4n4
      -  real

  INPUTS:

    - val: Value to evaluate. Must be a supported one of the supported types.
    - out: (optional) Holder of result, in order to avoid memory allocation.

  OUTPUTS:

    If out is not defined, then the result is a newlly allocated member containing the result.
  """
  #***************************************************************************************************

  cdef omatm4n4      O, Ores
  cdef dmat       R, Rres
  cdef feomatm4n4    F, Fres
  cdef onumm4n4    o, ores
  cdef coeff_t    r, rres
  cdef feonumm4n4     f, fres
  cdef coeff_t   crres
  cdef onumm4n4_t cores
  cdef feonumm4n4_t  cfres
  cdef darr_t    cRres
  cdef oarrm4n4_t   cOres
  cdef feoarrm4n4_t cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if   tval is onumm4n4:
    o = val
    if res_flag:
      
      ores = out
      onumm4n4_log_to( &o.num, &ores.num)

    else:

      cores = onumm4n4_log( &o.num)
      res   = onumm4n4.create(&cores)

    # end if 
  elif tval is feonumm4n4:
    f = val
    if res_flag:
      
      fres = out
      feonumm4n4_log_to( &f.num, &fres.num)

    else:

      cfres = feonumm4n4_log( &f.num)
      res   = feonumm4n4.create(&cfres)

    # end if  
  elif tval is feomatm4n4:    
    F = val
    if res_flag:

      Fres = out
      feoarrm4n4_log_to( &F.arr, &Fres.arr)

    else:

      cFres = feoarrm4n4_log( &F.arr)
      res   = feomatm4n4.create(&cFres)

    # end if 
  elif tval is omatm4n4:
    O = val
    if res_flag:
      
      Ores = out
      oarrm4n4_log_to( &O.arr, &Ores.arr)

    else:

      cOres = oarrm4n4_log( &O.arr)
      res   = omatm4n4.create(&cOres)

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

      -  omatm4n4
      -  feomatm4n4
      -  darr
      -  onumm4n4
      -  feonumm4n4
      -  real

  INPUTS:

    - val: Value to evaluate. Must be a supported one of the supported types.
    - out: (optional) Holder of result, in order to avoid memory allocation.

  OUTPUTS:

    If out is not defined, then the result is a newlly allocated member containing the result.
  """
  #***************************************************************************************************

  cdef omatm4n4      O, Ores
  cdef dmat       R, Rres
  cdef feomatm4n4    F, Fres
  cdef onumm4n4    o, ores
  cdef coeff_t    r, rres
  cdef feonumm4n4     f, fres
  cdef coeff_t   crres
  cdef onumm4n4_t cores
  cdef feonumm4n4_t  cfres
  cdef darr_t    cRres
  cdef oarrm4n4_t   cOres
  cdef feoarrm4n4_t cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if   tval is onumm4n4:
    o = val
    if res_flag:
      
      ores = out
      onumm4n4_log10_to( &o.num, &ores.num)

    else:

      cores = onumm4n4_log10( &o.num)
      res   = onumm4n4.create(&cores)

    # end if 
  elif tval is feonumm4n4:
    f = val
    if res_flag:
      
      fres = out
      feonumm4n4_log10_to( &f.num, &fres.num)

    else:

      cfres = feonumm4n4_log10( &f.num)
      res   = feonumm4n4.create(&cfres)

    # end if  
  elif tval is feomatm4n4:    
    F = val
    if res_flag:

      Fres = out
      feoarrm4n4_log10_to( &F.arr, &Fres.arr)

    else:

      cFres = feoarrm4n4_log10( &F.arr)
      res   = feomatm4n4.create(&cFres)

    # end if 
  elif tval is omatm4n4:
    O = val
    if res_flag:
      
      Ores = out
      oarrm4n4_log10_to( &O.arr, &Ores.arr)

    else:

      cOres = oarrm4n4_log10( &O.arr)
      res   = omatm4n4.create(&cOres)

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

      -  omatm4n4
      -  feomatm4n4
      -  darr
      -  onumm4n4
      -  feonumm4n4
      -  real

  INPUTS:

    - val: Value to evaluate. Must be a supported one of the supported types.
    - b:   Base.
    - out: (optional) Holder of result, in order to avoid memory allocation.

  OUTPUTS:

    If out is not defined, then the result is a newlly allocated member containing the result.
  """
  #***************************************************************************************************

  cdef omatm4n4      O, Ores
  cdef dmat       R, Rres
  cdef feomatm4n4    F, Fres
  cdef onumm4n4    o, ores
  cdef coeff_t    r, rres
  cdef feonumm4n4     f, fres
  cdef coeff_t   crres
  cdef onumm4n4_t cores
  cdef feonumm4n4_t  cfres
  cdef darr_t    cRres
  cdef oarrm4n4_t   cOres
  cdef feoarrm4n4_t cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if   tval is onumm4n4:
    o = val
    if res_flag:
      
      ores = out
      onumm4n4_logb_to( &o.num, b, &ores.num)

    else:

      cores = onumm4n4_logb( &o.num, b)
      res   = onumm4n4.create(&cores)

    # end if 
  elif tval is feonumm4n4:
    f = val
    if res_flag:
      
      fres = out
      feonumm4n4_logb_to( &f.num, b, &fres.num)

    else:

      cfres = feonumm4n4_logb( &f.num, b)
      res   = feonumm4n4.create(&cfres)

    # end if  
  elif tval is feomatm4n4:    
    F = val
    if res_flag:

      Fres = out
      feoarrm4n4_logb_to( &F.arr, b, &Fres.arr)

    else:

      cFres = feoarrm4n4_logb( &F.arr, b)
      res   = feomatm4n4.create(&cFres)

    # end if 
  elif tval is omatm4n4:
    O = val
    if res_flag:
      
      Ores = out
      oarrm4n4_logb_to( &O.arr, b, &Ores.arr)

    else:

      cOres = oarrm4n4_logb( &O.arr, b)
      res   = omatm4n4.create(&cOres)

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

      -  omatm4n4
      -  feomatm4n4
      -  darr
      -  onumm4n4
      -  feonumm4n4
      -  real

  INPUTS:

    - val: Value to evaluate. Must be a supported one of the supported types.
    - out: (optional) Holder of result, in order to avoid memory allocation.

  OUTPUTS:

    If out is not defined, then the result is a newlly allocated member containing the result.
  """
  #***************************************************************************************************

  cdef omatm4n4      O, Ores
  cdef dmat       R, Rres
  cdef feomatm4n4    F, Fres
  cdef onumm4n4    o, ores
  cdef coeff_t    r, rres
  cdef feonumm4n4     f, fres
  cdef coeff_t   crres
  cdef onumm4n4_t cores
  cdef feonumm4n4_t  cfres
  cdef darr_t    cRres
  cdef oarrm4n4_t   cOres
  cdef feoarrm4n4_t cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if   tval is onumm4n4:
    o = val
    if res_flag:
      
      ores = out
      onumm4n4_sqrt_to( &o.num, &ores.num)

    else:

      cores = onumm4n4_sqrt( &o.num)
      res   = onumm4n4.create(&cores)

    # end if 
  elif tval is feonumm4n4:
    f = val
    if res_flag:
      
      fres = out
      feonumm4n4_sqrt_to( &f.num, &fres.num)

    else:

      cfres = feonumm4n4_sqrt( &f.num)
      res   = feonumm4n4.create(&cfres)

    # end if  
  elif tval is feomatm4n4:    
    F = val
    if res_flag:

      Fres = out
      feoarrm4n4_sqrt_to( &F.arr, &Fres.arr)

    else:

      cFres = feoarrm4n4_sqrt( &F.arr)
      res   = feomatm4n4.create(&cFres)

    # end if 
  elif tval is omatm4n4:
    O = val
    if res_flag:
      
      Ores = out
      oarrm4n4_sqrt_to( &O.arr, &Ores.arr)

    else:

      cOres = oarrm4n4_sqrt( &O.arr)
      res   = omatm4n4.create(&cOres)

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

      -  omatm4n4
      -  feomatm4n4
      -  darr
      -  onumm4n4
      -  feonumm4n4
      -  real

  INPUTS:

    - val: Value to evaluate. Must be a supported one of the supported types.
    - out: (optional) Holder of result, in order to avoid memory allocation.

  OUTPUTS:

    If out is not defined, then the result is a newlly allocated member containing the result.
  """
  #***************************************************************************************************

  cdef omatm4n4      O, Ores
  cdef dmat       R, Rres
  cdef feomatm4n4    F, Fres
  cdef onumm4n4    o, ores
  cdef coeff_t    r, rres
  cdef feonumm4n4     f, fres
  cdef coeff_t   crres
  cdef onumm4n4_t cores
  cdef feonumm4n4_t  cfres
  cdef darr_t    cRres
  cdef oarrm4n4_t   cOres
  cdef feoarrm4n4_t cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if   tval is onumm4n4:
    o = val
    if res_flag:
      
      ores = out
      onumm4n4_cbrt_to( &o.num, &ores.num)

    else:

      cores = onumm4n4_cbrt( &o.num)
      res   = onumm4n4.create(&cores)

    # end if 
  elif tval is feonumm4n4:
    f = val
    if res_flag:
      
      fres = out
      feonumm4n4_cbrt_to( &f.num, &fres.num)

    else:

      cfres = feonumm4n4_cbrt( &f.num)
      res   = feonumm4n4.create(&cfres)

    # end if  
  elif tval is feomatm4n4:    
    F = val
    if res_flag:

      Fres = out
      feoarrm4n4_cbrt_to( &F.arr, &Fres.arr)

    else:

      cFres = feoarrm4n4_cbrt( &F.arr)
      res   = feomatm4n4.create(&cFres)

    # end if 
  elif tval is omatm4n4:
    O = val
    if res_flag:
      
      Ores = out
      oarrm4n4_cbrt_to( &O.arr, &Ores.arr)

    else:

      cOres = oarrm4n4_cbrt( &O.arr)
      res   = omatm4n4.create(&cOres)

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

      -  omatm4n4
      -  feomatm4n4
      -  darr
      -  onumm4n4
      -  feonumm4n4
      -  real

  INPUTS:

    - val: Value to evaluate. Must be a supported one of the supported types.
    - e:   exponent.
    - out: (optional) Holder of result, in order to avoid memory allocation.

  OUTPUTS:

    If out is not defined, then the result is a newlly allocated member containing the result.
  """
  #***************************************************************************************************

  cdef omatm4n4      O, Ores
  cdef dmat       R, Rres
  cdef feomatm4n4    F, Fres
  cdef onumm4n4    o, ores
  cdef coeff_t    r, rres
  cdef feonumm4n4     f, fres
  cdef coeff_t   crres
  cdef onumm4n4_t cores
  cdef feonumm4n4_t  cfres
  cdef darr_t    cRres
  cdef oarrm4n4_t   cOres
  cdef feoarrm4n4_t cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if   tval is onumm4n4:
    o = val
    if res_flag:
      
      ores = out
      onumm4n4_pow_to( &o.num, e, &ores.num)

    else:

      cores = onumm4n4_pow( &o.num, e)
      res   = onumm4n4.create(&cores)

    # end if 
  elif tval is feonumm4n4:
    f = val
    if res_flag:
      
      fres = out
      feonumm4n4_pow_to( &f.num, e, &fres.num)

    else:

      cfres = feonumm4n4_pow( &f.num, e)
      res   = feonumm4n4.create(&cfres)

    # end if  
  elif tval is feomatm4n4:    
    F = val
    if res_flag:

      Fres = out
      feoarrm4n4_pow_to( &F.arr, e, &Fres.arr)

    else:

      cFres = feoarrm4n4_pow( &F.arr, e)
      res   = feomatm4n4.create(&cFres)

    # end if 
  elif tval is omatm4n4:
    O = val
    if res_flag:
      
      Ores = out
      oarrm4n4_pow_to( &O.arr, e, &Ores.arr)

    else:

      cOres = oarrm4n4_pow( &O.arr, e)
      res   = omatm4n4.create(&cOres)

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
cpdef gauss_integrate(object val, feonumm4n4 w, object out = None ):
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
  

  cdef omatm4n4      O, Ores
  cdef dmat       R, Rres
  cdef feomatm4n4    F, Fres
  cdef onumm4n4    o, ores
  cdef coeff_t    r, rres
  cdef feonumm4n4     f, fres
  cdef coeff_t   crres
  cdef onumm4n4_t cores
  cdef feonumm4n4_t  cfres
  cdef darr_t    cRres
  cdef oarrm4n4_t   cOres
  cdef feoarrm4n4_t cFres 
  cdef uint8_t res_flag = 1
  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if

  if   tval is feonumm4n4:
    f = val
    if res_flag:
      
      ores = out
      feonumm4n4_integrate_f_to( &f.num, &w.num, &ores.num)

    else:

      cores = feonumm4n4_integrate_f( &f.num, &w.num)
      res   = onumm4n4.create(&cores)

    # end if  
  elif tval is feomatm4n4:
    F = val
    if res_flag:

      Ores = out
      feoarrm4n4_integrate_to( &F.arr, &w.num, &Ores.arr)

    else:

      cOres = feoarrm4n4_integrate( &F.arr, &w.num)
      res   = omatm4n4.create(&cOres)

    # end if 
  elif tval is onumm4n4:
    o = val
    if res_flag:
      
      ores = out
      feonumm4n4_integrate_o_to( &o.num, &w.num, &ores.num)

    else:

      cores = feonumm4n4_integrate_o( &o.num, &w.num)
      res   = onumm4n4.create(&cores)

    # end if
  else:
    try:
      r = val
      if res_flag:
        
        ores = out
        feonumm4n4_integrate_r_to( r, &w.num, &ores.num)

      else:

        cores = feonumm4n4_integrate_r( r, &w.num)
        res   = onumm4n4.create(&cores)

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

      -  omatm4n4
      -  feomatm4n4
      -  darr
      -  onumm4n4
      -  feonumm4n4
      -  real
  """
  #***************************************************************************************************

  cdef omatm4n4      O, Ores
  cdef dmat       R, Rres
  cdef feomatm4n4    F, Fres
  cdef onumm4n4    o, ores
  cdef coeff_t    r, rres
  cdef feonumm4n4     f, fres
  cdef coeff_t   crres
  cdef onumm4n4_t cores
  cdef feonumm4n4_t  cfres
  cdef darr_t    cRres
  cdef oarrm4n4_t   cOres
  cdef feoarrm4n4_t cFres
  cdef uint8_t res_flag = 1
  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 
  #
  if   tval is onumm4n4:
    o = val
    if res_flag:
      
      ores = out
      onumm4n4_neg_to( &o.num, &ores.num)

    else:

      cores = onumm4n4_neg( &o.num)
      res   = onumm4n4.create(&cores)

    # end if 
  elif tval is feonumm4n4:
    f = val
    if res_flag:
      
      fres = out
      feonumm4n4_neg_to( &f.num, &fres.num)

    else:

      cfres = feonumm4n4_neg( &f.num)
      res   = feonumm4n4.create(&cfres)

    # end if         
  elif tval is feomatm4n4:    
    F = val
    if res_flag:

      Fres = out
      feoarrm4n4_neg_to( &F.arr, &Fres.arr)

    else:

      cFres = feoarrm4n4_neg( &F.arr)
      res   = feomatm4n4.create(&cFres)

    # end if 
  elif tval is omatm4n4:
    O = val
    if res_flag:
      
      Ores = out
      oarrm4n4_neg_to( &O.arr, &Ores.arr)

    else:

      cOres = oarrm4n4_neg( &O.arr)
      res   = omatm4n4.create(&cOres)

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
