#*****************************************************************************************************
cpdef cos(object val, object out = None):
  """
  PURPOSE:  Matrix determinant.
  
  Supported types:

      -  omatm5n3
      -  feomatm5n3
      -  darr
      -  onumm5n3
      -  feonumm5n3
      -  real
  """
  #***************************************************************************************************

  cdef omatm5n3      O, Ores
  cdef dmat       R, Rres
  cdef feomatm5n3    F, Fres
  cdef onumm5n3    o, ores
  cdef coeff_t    r, rres
  cdef feonumm5n3     f, fres
  cdef coeff_t   crres
  cdef onumm5n3_t cores
  cdef feonumm5n3_t  cfres
  cdef darr_t    cRres
  cdef oarrm5n3_t   cOres
  cdef feoarrm5n3_t cFres
  cdef uint8_t res_flag = 1
  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 
  #
  if   tval is onumm5n3:
    o = val
    if res_flag:
      
      ores = out
      onumm5n3_cos_to( &o.num, &ores.num)

    else:

      cores = onumm5n3_cos( &o.num)
      res   = onumm5n3.create(&cores)

    # end if 
  elif tval is feonumm5n3:
    f = val
    if res_flag:
      
      fres = out
      feonumm5n3_cos_to( &f.num, &fres.num)

    else:

      cfres = feonumm5n3_cos( &f.num)
      res   = feonumm5n3.create(&cfres)

    # end if         
  elif tval is feomatm5n3:    
    F = val
    if res_flag:

      Fres = out
      feoarrm5n3_cos_to( &F.arr, &Fres.arr)

    else:

      cFres = feoarrm5n3_cos( &F.arr)
      res   = feomatm5n3.create(&cFres)

    # end if 
  elif tval is omatm5n3:
    O = val
    if res_flag:
      
      Ores = out
      oarrm5n3_cos_to( &O.arr, &Ores.arr)

    else:

      cOres = oarrm5n3_cos( &O.arr)
      res   = omatm5n3.create(&cOres)

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

      -  omatm5n3
      -  feomatm5n3
      -  darr
      -  onumm5n3
      -  feonumm5n3
      -  real
  """
  #***************************************************************************************************

  cdef omatm5n3      O, Ores
  cdef dmat       R, Rres
  cdef feomatm5n3    F, Fres
  cdef onumm5n3    o, ores
  cdef coeff_t    r, rres
  cdef feonumm5n3     f, fres
  cdef coeff_t   crres
  cdef onumm5n3_t cores
  cdef feonumm5n3_t  cfres
  cdef darr_t    cRres
  cdef oarrm5n3_t   cOres
  cdef feoarrm5n3_t cFres
  cdef uint8_t res_flag = 1
  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if   tval is onumm5n3:
    o = val
    if res_flag:
      
      ores = out
      onumm5n3_sin_to( &o.num, &ores.num)

    else:

      cores = onumm5n3_sin( &o.num)
      res   = onumm5n3.create(&cores)

    # end if 
  elif tval is feonumm5n3:
    f = val
    if res_flag:
      
      fres = out
      feonumm5n3_sin_to( &f.num, &fres.num)

    else:

      cfres = feonumm5n3_sin( &f.num)
      res   = feonumm5n3.create(&cfres)

    # end if  
  elif tval is feomatm5n3:    
    F = val
    if res_flag:

      Fres = out
      feoarrm5n3_sin_to( &F.arr, &Fres.arr)

    else:

      cFres = feoarrm5n3_sin( &F.arr)
      res   = feomatm5n3.create(&cFres)

    # end if 
  elif tval is omatm5n3:
    O = val
    if res_flag:
      
      Ores = out
      oarrm5n3_sin_to( &O.arr, &Ores.arr)

    else:

      cOres = oarrm5n3_sin( &O.arr)
      res   = omatm5n3.create(&cOres)

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

      -  omatm5n3
      -  feomatm5n3
      -  darr
      -  onumm5n3
      -  feonumm5n3
      -  real
  """
  #***************************************************************************************************

  cdef omatm5n3      O, Ores
  cdef dmat       R, Rres
  cdef feomatm5n3    F, Fres
  cdef onumm5n3    o, ores
  cdef coeff_t    r, rres
  cdef feonumm5n3     f, fres
  cdef coeff_t   crres
  cdef onumm5n3_t cores
  cdef feonumm5n3_t  cfres
  cdef darr_t    cRres
  cdef oarrm5n3_t   cOres
  cdef feoarrm5n3_t cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if   tval is onumm5n3:
    o = val
    if res_flag:
      
      ores = out
      onumm5n3_tan_to( &o.num, &ores.num)

    else:

      cores = onumm5n3_tan( &o.num)
      res   = onumm5n3.create(&cores)

    # end if 
  elif tval is feonumm5n3:
    f = val
    if res_flag:
      
      fres = out
      feonumm5n3_tan_to( &f.num, &fres.num)

    else:

      cfres = feonumm5n3_tan( &f.num)
      res   = feonumm5n3.create(&cfres)

    # end if  
  elif tval is feomatm5n3:    
    F = val
    if res_flag:

      Fres = out
      feoarrm5n3_tan_to( &F.arr, &Fres.arr)

    else:

      cFres = feoarrm5n3_tan( &F.arr)
      res   = feomatm5n3.create(&cFres)

    # end if 
  elif tval is omatm5n3:
    O = val
    if res_flag:
      
      Ores = out
      oarrm5n3_tan_to( &O.arr, &Ores.arr)

    else:

      cOres = oarrm5n3_tan( &O.arr)
      res   = omatm5n3.create(&cOres)

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

      -  omatm5n3
      -  feomatm5n3
      -  darr
      -  onumm5n3
      -  feonumm5n3
      -  real
  """
  #***************************************************************************************************

  cdef omatm5n3      O, Ores
  cdef dmat       R, Rres
  cdef feomatm5n3    F, Fres
  cdef onumm5n3    o, ores
  cdef coeff_t    r, rres
  cdef feonumm5n3     f, fres
  cdef coeff_t   crres
  cdef onumm5n3_t cores
  cdef feonumm5n3_t  cfres
  cdef darr_t    cRres
  cdef oarrm5n3_t   cOres
  cdef feoarrm5n3_t cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if   tval is onumm5n3:
    o = val
    if res_flag:
      
      ores = out
      onumm5n3_acos_to( &o.num, &ores.num)

    else:

      cores = onumm5n3_acos( &o.num)
      res   = onumm5n3.create(&cores)

    # end if 
  elif tval is feonumm5n3:
    f = val
    if res_flag:
      
      fres = out
      feonumm5n3_acos_to( &f.num, &fres.num)

    else:

      cfres = feonumm5n3_acos( &f.num)
      res   = feonumm5n3.create(&cfres)

    # end if  
  elif tval is feomatm5n3:    
    F = val
    if res_flag:

      Fres = out
      feoarrm5n3_acos_to( &F.arr, &Fres.arr)

    else:

      cFres = feoarrm5n3_acos( &F.arr)
      res   = feomatm5n3.create(&cFres)

    # end if 
  elif tval is omatm5n3:
    O = val
    if res_flag:
      
      Ores = out
      oarrm5n3_acos_to( &O.arr, &Ores.arr)

    else:

      cOres = oarrm5n3_acos( &O.arr)
      res   = omatm5n3.create(&cOres)

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

      -  omatm5n3
      -  feomatm5n3
      -  darr
      -  onumm5n3
      -  feonumm5n3
      -  real
  """
  #***************************************************************************************************

  cdef omatm5n3      O, Ores
  cdef dmat       R, Rres
  cdef feomatm5n3    F, Fres
  cdef onumm5n3    o, ores
  cdef coeff_t    r, rres
  cdef feonumm5n3     f, fres
  cdef coeff_t   crres
  cdef onumm5n3_t cores
  cdef feonumm5n3_t  cfres
  cdef darr_t    cRres
  cdef oarrm5n3_t   cOres
  cdef feoarrm5n3_t cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if   tval is onumm5n3:
    o = val
    if res_flag:
      
      ores = out
      onumm5n3_asin_to( &o.num, &ores.num)

    else:

      cores = onumm5n3_asin( &o.num)
      res   = onumm5n3.create(&cores)

    # end if 
  elif tval is feonumm5n3:
    f = val
    if res_flag:
      
      fres = out
      feonumm5n3_asin_to( &f.num, &fres.num)

    else:

      cfres = feonumm5n3_asin( &f.num)
      res   = feonumm5n3.create(&cfres)

    # end if  
  elif tval is feomatm5n3:    
    F = val
    if res_flag:

      Fres = out
      feoarrm5n3_asin_to( &F.arr, &Fres.arr)

    else:

      cFres = feoarrm5n3_asin( &F.arr)
      res   = feomatm5n3.create(&cFres)

    # end if 
  elif tval is omatm5n3:
    O = val
    if res_flag:
      
      Ores = out
      oarrm5n3_asin_to( &O.arr, &Ores.arr)

    else:

      cOres = oarrm5n3_asin( &O.arr)
      res   = omatm5n3.create(&cOres)

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

      -  omatm5n3
      -  feomatm5n3
      -  darr
      -  onumm5n3
      -  feonumm5n3
      -  real
  """
  #***************************************************************************************************

  cdef omatm5n3      O, Ores
  cdef dmat       R, Rres
  cdef feomatm5n3    F, Fres
  cdef onumm5n3    o, ores
  cdef coeff_t    r, rres
  cdef feonumm5n3     f, fres
  cdef coeff_t   crres
  cdef onumm5n3_t cores
  cdef feonumm5n3_t  cfres
  cdef darr_t    cRres
  cdef oarrm5n3_t   cOres
  cdef feoarrm5n3_t cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if   tval is onumm5n3:
    o = val
    if res_flag:
      
      ores = out
      onumm5n3_atan_to( &o.num, &ores.num)

    else:

      cores = onumm5n3_atan( &o.num)
      res   = onumm5n3.create(&cores)

    # end if 
  elif tval is feonumm5n3:
    f = val
    if res_flag:
      
      fres = out
      feonumm5n3_atan_to( &f.num, &fres.num)

    else:

      cfres = feonumm5n3_atan( &f.num)
      res   = feonumm5n3.create(&cfres)

    # end if  
  elif tval is feomatm5n3:    
    F = val
    if res_flag:

      Fres = out
      feoarrm5n3_atan_to( &F.arr, &Fres.arr)

    else:

      cFres = feoarrm5n3_atan( &F.arr)
      res   = feomatm5n3.create(&cFres)

    # end if 
  elif tval is omatm5n3:
    O = val
    if res_flag:
      
      Ores = out
      oarrm5n3_atan_to( &O.arr, &Ores.arr)

    else:

      cOres = oarrm5n3_atan( &O.arr)
      res   = omatm5n3.create(&cOres)

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

      -  omatm5n3
      -  feomatm5n3
      -  darr
      -  onumm5n3
      -  feonumm5n3
      -  real
  """
  #***************************************************************************************************

  cdef omatm5n3      O, Ores
  cdef dmat       R, Rres
  cdef feomatm5n3    F, Fres
  cdef onumm5n3    o, ores
  cdef coeff_t    r, rres
  cdef feonumm5n3     f, fres
  cdef coeff_t   crres
  cdef onumm5n3_t cores
  cdef feonumm5n3_t  cfres
  cdef darr_t    cRres
  cdef oarrm5n3_t   cOres
  cdef feoarrm5n3_t cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if   tval is onumm5n3:
    o = val
    if res_flag:
      
      ores = out
      onumm5n3_sinh_to( &o.num, &ores.num)

    else:

      cores = onumm5n3_sinh( &o.num)
      res   = onumm5n3.create(&cores)

    # end if 
  elif tval is feonumm5n3:
    f = val
    if res_flag:
      
      fres = out
      feonumm5n3_sinh_to( &f.num, &fres.num)

    else:

      cfres = feonumm5n3_sinh( &f.num)
      res   = feonumm5n3.create(&cfres)

    # end if  
  elif tval is feomatm5n3:    
    F = val
    if res_flag:

      Fres = out
      feoarrm5n3_sinh_to( &F.arr, &Fres.arr)

    else:

      cFres = feoarrm5n3_sinh( &F.arr)
      res   = feomatm5n3.create(&cFres)

    # end if 
  elif tval is omatm5n3:
    O = val
    if res_flag:
      
      Ores = out
      oarrm5n3_sinh_to( &O.arr, &Ores.arr)

    else:

      cOres = oarrm5n3_sinh( &O.arr)
      res   = omatm5n3.create(&cOres)

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

      -  omatm5n3
      -  feomatm5n3
      -  darr
      -  onumm5n3
      -  feonumm5n3
      -  real
  """
  #***************************************************************************************************

  cdef omatm5n3      O, Ores
  cdef dmat       R, Rres
  cdef feomatm5n3    F, Fres
  cdef onumm5n3    o, ores
  cdef coeff_t    r, rres
  cdef feonumm5n3     f, fres
  cdef coeff_t   crres
  cdef onumm5n3_t cores
  cdef feonumm5n3_t  cfres
  cdef darr_t    cRres
  cdef oarrm5n3_t   cOres
  cdef feoarrm5n3_t cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if   tval is onumm5n3:
    o = val
    if res_flag:
      
      ores = out
      onumm5n3_cosh_to( &o.num, &ores.num)

    else:

      cores = onumm5n3_cosh( &o.num)
      res   = onumm5n3.create(&cores)

    # end if 
  elif tval is feonumm5n3:
    f = val
    if res_flag:
      
      fres = out
      feonumm5n3_cosh_to( &f.num, &fres.num)

    else:

      cfres = feonumm5n3_cosh( &f.num)
      res   = feonumm5n3.create(&cfres)

    # end if  
  elif tval is feomatm5n3:    
    F = val
    if res_flag:

      Fres = out
      feoarrm5n3_cosh_to( &F.arr, &Fres.arr)

    else:

      cFres = feoarrm5n3_cosh( &F.arr)
      res   = feomatm5n3.create(&cFres)

    # end if 
  elif tval is omatm5n3:
    O = val
    if res_flag:
      
      Ores = out
      oarrm5n3_cosh_to( &O.arr, &Ores.arr)

    else:

      cOres = oarrm5n3_cosh( &O.arr)
      res   = omatm5n3.create(&cOres)

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

      -  omatm5n3
      -  feomatm5n3
      -  darr
      -  onumm5n3
      -  feonumm5n3
      -  real
  """
  #***************************************************************************************************

  cdef omatm5n3      O, Ores
  cdef dmat       R, Rres
  cdef feomatm5n3    F, Fres
  cdef onumm5n3    o, ores
  cdef coeff_t    r, rres
  cdef feonumm5n3     f, fres
  cdef coeff_t   crres
  cdef onumm5n3_t cores
  cdef feonumm5n3_t  cfres
  cdef darr_t    cRres
  cdef oarrm5n3_t   cOres
  cdef feoarrm5n3_t cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if   tval is onumm5n3:
    o = val
    if res_flag:
      
      ores = out
      onumm5n3_tanh_to( &o.num, &ores.num)

    else:

      cores = onumm5n3_tanh( &o.num)
      res   = onumm5n3.create(&cores)

    # end if 
  elif tval is feonumm5n3:
    f = val
    if res_flag:
      
      fres = out
      feonumm5n3_tanh_to( &f.num, &fres.num)

    else:

      cfres = feonumm5n3_tanh( &f.num)
      res   = feonumm5n3.create(&cfres)

    # end if  
  elif tval is feomatm5n3:    
    F = val
    if res_flag:

      Fres = out
      feoarrm5n3_tanh_to( &F.arr, &Fres.arr)

    else:

      cFres = feoarrm5n3_tanh( &F.arr)
      res   = feomatm5n3.create(&cFres)

    # end if 
  elif tval is omatm5n3:
    O = val
    if res_flag:
      
      Ores = out
      oarrm5n3_tanh_to( &O.arr, &Ores.arr)

    else:

      cOres = oarrm5n3_tanh( &O.arr)
      res   = omatm5n3.create(&cOres)

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

      -  omatm5n3
      -  feomatm5n3
      -  darr
      -  onumm5n3
      -  feonumm5n3
      -  real
  """
  #***************************************************************************************************

  cdef omatm5n3      O, Ores
  cdef dmat       R, Rres
  cdef feomatm5n3    F, Fres
  cdef onumm5n3    o, ores
  cdef coeff_t    r, rres
  cdef feonumm5n3     f, fres
  cdef coeff_t   crres
  cdef onumm5n3_t cores
  cdef feonumm5n3_t  cfres
  cdef darr_t    cRres
  cdef oarrm5n3_t   cOres
  cdef feoarrm5n3_t cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if   tval is onumm5n3:
    o = val
    if res_flag:
      
      ores = out
      onumm5n3_acosh_to( &o.num, &ores.num)

    else:

      cores = onumm5n3_acosh( &o.num)
      res   = onumm5n3.create(&cores)

    # end if 
  elif tval is feonumm5n3:
    f = val
    if res_flag:
      
      fres = out
      feonumm5n3_acosh_to( &f.num, &fres.num)

    else:

      cfres = feonumm5n3_acosh( &f.num)
      res   = feonumm5n3.create(&cfres)

    # end if  
  elif tval is feomatm5n3:    
    F = val
    if res_flag:

      Fres = out
      feoarrm5n3_acosh_to( &F.arr, &Fres.arr)

    else:

      cFres = feoarrm5n3_acosh( &F.arr)
      res   = feomatm5n3.create(&cFres)

    # end if 
  elif tval is omatm5n3:
    O = val
    if res_flag:
      
      Ores = out
      oarrm5n3_acosh_to( &O.arr, &Ores.arr)

    else:

      cOres = oarrm5n3_acosh( &O.arr)
      res   = omatm5n3.create(&cOres)

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

      -  omatm5n3
      -  feomatm5n3
      -  darr
      -  onumm5n3
      -  feonumm5n3
      -  real
  """
  #***************************************************************************************************

  cdef omatm5n3      O, Ores
  cdef dmat       R, Rres
  cdef feomatm5n3    F, Fres
  cdef onumm5n3    o, ores
  cdef coeff_t    r, rres
  cdef feonumm5n3     f, fres
  cdef coeff_t   crres
  cdef onumm5n3_t cores
  cdef feonumm5n3_t  cfres
  cdef darr_t    cRres
  cdef oarrm5n3_t   cOres
  cdef feoarrm5n3_t cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if   tval is onumm5n3:
    o = val
    if res_flag:
      
      ores = out
      onumm5n3_asinh_to( &o.num, &ores.num)

    else:

      cores = onumm5n3_asinh( &o.num)
      res   = onumm5n3.create(&cores)

    # end if 
  elif tval is feonumm5n3:
    f = val
    if res_flag:
      
      fres = out
      feonumm5n3_asinh_to( &f.num, &fres.num)

    else:

      cfres = feonumm5n3_asinh( &f.num)
      res   = feonumm5n3.create(&cfres)

    # end if  
  elif tval is feomatm5n3:    
    F = val
    if res_flag:

      Fres = out
      feoarrm5n3_asinh_to( &F.arr, &Fres.arr)

    else:

      cFres = feoarrm5n3_asinh( &F.arr)
      res   = feomatm5n3.create(&cFres)

    # end if 
  elif tval is omatm5n3:
    O = val
    if res_flag:
      
      Ores = out
      oarrm5n3_asinh_to( &O.arr, &Ores.arr)

    else:

      cOres = oarrm5n3_asinh( &O.arr)
      res   = omatm5n3.create(&cOres)

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

      -  omatm5n3
      -  feomatm5n3
      -  darr
      -  onumm5n3
      -  feonumm5n3
      -  real
  """
  #***************************************************************************************************

  cdef omatm5n3      O, Ores
  cdef dmat       R, Rres
  cdef feomatm5n3    F, Fres
  cdef onumm5n3    o, ores
  cdef coeff_t    r, rres
  cdef feonumm5n3     f, fres
  cdef coeff_t   crres
  cdef onumm5n3_t cores
  cdef feonumm5n3_t  cfres
  cdef darr_t    cRres
  cdef oarrm5n3_t   cOres
  cdef feoarrm5n3_t cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if   tval is onumm5n3:
    o = val
    if res_flag:
      
      ores = out
      onumm5n3_atanh_to( &o.num, &ores.num)

    else:

      cores = onumm5n3_atanh( &o.num)
      res   = onumm5n3.create(&cores)

    # end if 
  elif tval is feonumm5n3:
    f = val
    if res_flag:
      
      fres = out
      feonumm5n3_atanh_to( &f.num, &fres.num)

    else:

      cfres = feonumm5n3_atanh( &f.num)
      res   = feonumm5n3.create(&cfres)

    # end if  
  elif tval is feomatm5n3:    
    F = val
    if res_flag:

      Fres = out
      feoarrm5n3_atanh_to( &F.arr, &Fres.arr)

    else:

      cFres = feoarrm5n3_atanh( &F.arr)
      res   = feomatm5n3.create(&cFres)

    # end if 
  elif tval is omatm5n3:
    O = val
    if res_flag:
      
      Ores = out
      oarrm5n3_atanh_to( &O.arr, &Ores.arr)

    else:

      cOres = oarrm5n3_atanh( &O.arr)
      res   = omatm5n3.create(&cOres)

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

      -  omatm5n3
      -  feomatm5n3
      -  darr
      -  onumm5n3
      -  feonumm5n3
      -  real
  """
  #***************************************************************************************************

  cdef omatm5n3      O, Ores
  cdef dmat       R, Rres
  cdef feomatm5n3    F, Fres
  cdef onumm5n3    o, ores
  cdef coeff_t    r, rres
  cdef feonumm5n3     f, fres
  cdef coeff_t   crres
  cdef onumm5n3_t cores
  cdef feonumm5n3_t  cfres
  cdef darr_t    cRres
  cdef oarrm5n3_t   cOres
  cdef feoarrm5n3_t cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if   tval is onumm5n3:
    o = val
    if res_flag:
      
      ores = out
      onumm5n3_exp_to( &o.num, &ores.num)

    else:

      cores = onumm5n3_exp( &o.num)
      res   = onumm5n3.create(&cores)

    # end if 
  elif tval is feonumm5n3:
    f = val
    if res_flag:
      
      fres = out
      feonumm5n3_exp_to( &f.num, &fres.num)

    else:

      cfres = feonumm5n3_exp( &f.num)
      res   = feonumm5n3.create(&cfres)

    # end if  
  elif tval is feomatm5n3:    
    F = val
    if res_flag:

      Fres = out
      feoarrm5n3_exp_to( &F.arr, &Fres.arr)

    else:

      cFres = feoarrm5n3_exp( &F.arr)
      res   = feomatm5n3.create(&cFres)

    # end if 
  elif tval is omatm5n3:
    O = val
    if res_flag:
      
      Ores = out
      oarrm5n3_exp_to( &O.arr, &Ores.arr)

    else:

      cOres = oarrm5n3_exp( &O.arr)
      res   = omatm5n3.create(&cOres)

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

      -  omatm5n3
      -  feomatm5n3
      -  darr
      -  onumm5n3
      -  feonumm5n3
      -  real

  INPUTS:

    - val: Value to evaluate. Must be a supported one of the supported types.
    - out: (optional) Holder of result, in order to avoid memory allocation.

  OUTPUTS:

    If out is not defined, then the result is a newlly allocated member containing the result.
  """
  #***************************************************************************************************

  cdef omatm5n3      O, Ores
  cdef dmat       R, Rres
  cdef feomatm5n3    F, Fres
  cdef onumm5n3    o, ores
  cdef coeff_t    r, rres
  cdef feonumm5n3     f, fres
  cdef coeff_t   crres
  cdef onumm5n3_t cores
  cdef feonumm5n3_t  cfres
  cdef darr_t    cRres
  cdef oarrm5n3_t   cOres
  cdef feoarrm5n3_t cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if   tval is onumm5n3:
    o = val
    if res_flag:
      
      ores = out
      onumm5n3_log_to( &o.num, &ores.num)

    else:

      cores = onumm5n3_log( &o.num)
      res   = onumm5n3.create(&cores)

    # end if 
  elif tval is feonumm5n3:
    f = val
    if res_flag:
      
      fres = out
      feonumm5n3_log_to( &f.num, &fres.num)

    else:

      cfres = feonumm5n3_log( &f.num)
      res   = feonumm5n3.create(&cfres)

    # end if  
  elif tval is feomatm5n3:    
    F = val
    if res_flag:

      Fres = out
      feoarrm5n3_log_to( &F.arr, &Fres.arr)

    else:

      cFres = feoarrm5n3_log( &F.arr)
      res   = feomatm5n3.create(&cFres)

    # end if 
  elif tval is omatm5n3:
    O = val
    if res_flag:
      
      Ores = out
      oarrm5n3_log_to( &O.arr, &Ores.arr)

    else:

      cOres = oarrm5n3_log( &O.arr)
      res   = omatm5n3.create(&cOres)

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

      -  omatm5n3
      -  feomatm5n3
      -  darr
      -  onumm5n3
      -  feonumm5n3
      -  real

  INPUTS:

    - val: Value to evaluate. Must be a supported one of the supported types.
    - out: (optional) Holder of result, in order to avoid memory allocation.

  OUTPUTS:

    If out is not defined, then the result is a newlly allocated member containing the result.
  """
  #***************************************************************************************************

  cdef omatm5n3      O, Ores
  cdef dmat       R, Rres
  cdef feomatm5n3    F, Fres
  cdef onumm5n3    o, ores
  cdef coeff_t    r, rres
  cdef feonumm5n3     f, fres
  cdef coeff_t   crres
  cdef onumm5n3_t cores
  cdef feonumm5n3_t  cfres
  cdef darr_t    cRres
  cdef oarrm5n3_t   cOres
  cdef feoarrm5n3_t cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if   tval is onumm5n3:
    o = val
    if res_flag:
      
      ores = out
      onumm5n3_log10_to( &o.num, &ores.num)

    else:

      cores = onumm5n3_log10( &o.num)
      res   = onumm5n3.create(&cores)

    # end if 
  elif tval is feonumm5n3:
    f = val
    if res_flag:
      
      fres = out
      feonumm5n3_log10_to( &f.num, &fres.num)

    else:

      cfres = feonumm5n3_log10( &f.num)
      res   = feonumm5n3.create(&cfres)

    # end if  
  elif tval is feomatm5n3:    
    F = val
    if res_flag:

      Fres = out
      feoarrm5n3_log10_to( &F.arr, &Fres.arr)

    else:

      cFres = feoarrm5n3_log10( &F.arr)
      res   = feomatm5n3.create(&cFres)

    # end if 
  elif tval is omatm5n3:
    O = val
    if res_flag:
      
      Ores = out
      oarrm5n3_log10_to( &O.arr, &Ores.arr)

    else:

      cOres = oarrm5n3_log10( &O.arr)
      res   = omatm5n3.create(&cOres)

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

      -  omatm5n3
      -  feomatm5n3
      -  darr
      -  onumm5n3
      -  feonumm5n3
      -  real

  INPUTS:

    - val: Value to evaluate. Must be a supported one of the supported types.
    - b:   Base.
    - out: (optional) Holder of result, in order to avoid memory allocation.

  OUTPUTS:

    If out is not defined, then the result is a newlly allocated member containing the result.
  """
  #***************************************************************************************************

  cdef omatm5n3      O, Ores
  cdef dmat       R, Rres
  cdef feomatm5n3    F, Fres
  cdef onumm5n3    o, ores
  cdef coeff_t    r, rres
  cdef feonumm5n3     f, fres
  cdef coeff_t   crres
  cdef onumm5n3_t cores
  cdef feonumm5n3_t  cfres
  cdef darr_t    cRres
  cdef oarrm5n3_t   cOres
  cdef feoarrm5n3_t cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if   tval is onumm5n3:
    o = val
    if res_flag:
      
      ores = out
      onumm5n3_logb_to( &o.num, b, &ores.num)

    else:

      cores = onumm5n3_logb( &o.num, b)
      res   = onumm5n3.create(&cores)

    # end if 
  elif tval is feonumm5n3:
    f = val
    if res_flag:
      
      fres = out
      feonumm5n3_logb_to( &f.num, b, &fres.num)

    else:

      cfres = feonumm5n3_logb( &f.num, b)
      res   = feonumm5n3.create(&cfres)

    # end if  
  elif tval is feomatm5n3:    
    F = val
    if res_flag:

      Fres = out
      feoarrm5n3_logb_to( &F.arr, b, &Fres.arr)

    else:

      cFres = feoarrm5n3_logb( &F.arr, b)
      res   = feomatm5n3.create(&cFres)

    # end if 
  elif tval is omatm5n3:
    O = val
    if res_flag:
      
      Ores = out
      oarrm5n3_logb_to( &O.arr, b, &Ores.arr)

    else:

      cOres = oarrm5n3_logb( &O.arr, b)
      res   = omatm5n3.create(&cOres)

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

      -  omatm5n3
      -  feomatm5n3
      -  darr
      -  onumm5n3
      -  feonumm5n3
      -  real

  INPUTS:

    - val: Value to evaluate. Must be a supported one of the supported types.
    - out: (optional) Holder of result, in order to avoid memory allocation.

  OUTPUTS:

    If out is not defined, then the result is a newlly allocated member containing the result.
  """
  #***************************************************************************************************

  cdef omatm5n3      O, Ores
  cdef dmat       R, Rres
  cdef feomatm5n3    F, Fres
  cdef onumm5n3    o, ores
  cdef coeff_t    r, rres
  cdef feonumm5n3     f, fres
  cdef coeff_t   crres
  cdef onumm5n3_t cores
  cdef feonumm5n3_t  cfres
  cdef darr_t    cRres
  cdef oarrm5n3_t   cOres
  cdef feoarrm5n3_t cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if   tval is onumm5n3:
    o = val
    if res_flag:
      
      ores = out
      onumm5n3_sqrt_to( &o.num, &ores.num)

    else:

      cores = onumm5n3_sqrt( &o.num)
      res   = onumm5n3.create(&cores)

    # end if 
  elif tval is feonumm5n3:
    f = val
    if res_flag:
      
      fres = out
      feonumm5n3_sqrt_to( &f.num, &fres.num)

    else:

      cfres = feonumm5n3_sqrt( &f.num)
      res   = feonumm5n3.create(&cfres)

    # end if  
  elif tval is feomatm5n3:    
    F = val
    if res_flag:

      Fres = out
      feoarrm5n3_sqrt_to( &F.arr, &Fres.arr)

    else:

      cFres = feoarrm5n3_sqrt( &F.arr)
      res   = feomatm5n3.create(&cFres)

    # end if 
  elif tval is omatm5n3:
    O = val
    if res_flag:
      
      Ores = out
      oarrm5n3_sqrt_to( &O.arr, &Ores.arr)

    else:

      cOres = oarrm5n3_sqrt( &O.arr)
      res   = omatm5n3.create(&cOres)

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

      -  omatm5n3
      -  feomatm5n3
      -  darr
      -  onumm5n3
      -  feonumm5n3
      -  real

  INPUTS:

    - val: Value to evaluate. Must be a supported one of the supported types.
    - out: (optional) Holder of result, in order to avoid memory allocation.

  OUTPUTS:

    If out is not defined, then the result is a newlly allocated member containing the result.
  """
  #***************************************************************************************************

  cdef omatm5n3      O, Ores
  cdef dmat       R, Rres
  cdef feomatm5n3    F, Fres
  cdef onumm5n3    o, ores
  cdef coeff_t    r, rres
  cdef feonumm5n3     f, fres
  cdef coeff_t   crres
  cdef onumm5n3_t cores
  cdef feonumm5n3_t  cfres
  cdef darr_t    cRres
  cdef oarrm5n3_t   cOres
  cdef feoarrm5n3_t cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if   tval is onumm5n3:
    o = val
    if res_flag:
      
      ores = out
      onumm5n3_cbrt_to( &o.num, &ores.num)

    else:

      cores = onumm5n3_cbrt( &o.num)
      res   = onumm5n3.create(&cores)

    # end if 
  elif tval is feonumm5n3:
    f = val
    if res_flag:
      
      fres = out
      feonumm5n3_cbrt_to( &f.num, &fres.num)

    else:

      cfres = feonumm5n3_cbrt( &f.num)
      res   = feonumm5n3.create(&cfres)

    # end if  
  elif tval is feomatm5n3:    
    F = val
    if res_flag:

      Fres = out
      feoarrm5n3_cbrt_to( &F.arr, &Fres.arr)

    else:

      cFres = feoarrm5n3_cbrt( &F.arr)
      res   = feomatm5n3.create(&cFres)

    # end if 
  elif tval is omatm5n3:
    O = val
    if res_flag:
      
      Ores = out
      oarrm5n3_cbrt_to( &O.arr, &Ores.arr)

    else:

      cOres = oarrm5n3_cbrt( &O.arr)
      res   = omatm5n3.create(&cOres)

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

      -  omatm5n3
      -  feomatm5n3
      -  darr
      -  onumm5n3
      -  feonumm5n3
      -  real

  INPUTS:

    - val: Value to evaluate. Must be a supported one of the supported types.
    - e:   exponent.
    - out: (optional) Holder of result, in order to avoid memory allocation.

  OUTPUTS:

    If out is not defined, then the result is a newlly allocated member containing the result.
  """
  #***************************************************************************************************

  cdef omatm5n3      O, Ores
  cdef dmat       R, Rres
  cdef feomatm5n3    F, Fres
  cdef onumm5n3    o, ores
  cdef coeff_t    r, rres
  cdef feonumm5n3     f, fres
  cdef coeff_t   crres
  cdef onumm5n3_t cores
  cdef feonumm5n3_t  cfres
  cdef darr_t    cRres
  cdef oarrm5n3_t   cOres
  cdef feoarrm5n3_t cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if   tval is onumm5n3:
    o = val
    if res_flag:
      
      ores = out
      onumm5n3_pow_to( &o.num, e, &ores.num)

    else:

      cores = onumm5n3_pow( &o.num, e)
      res   = onumm5n3.create(&cores)

    # end if 
  elif tval is feonumm5n3:
    f = val
    if res_flag:
      
      fres = out
      feonumm5n3_pow_to( &f.num, e, &fres.num)

    else:

      cfres = feonumm5n3_pow( &f.num, e)
      res   = feonumm5n3.create(&cfres)

    # end if  
  elif tval is feomatm5n3:    
    F = val
    if res_flag:

      Fres = out
      feoarrm5n3_pow_to( &F.arr, e, &Fres.arr)

    else:

      cFres = feoarrm5n3_pow( &F.arr, e)
      res   = feomatm5n3.create(&cFres)

    # end if 
  elif tval is omatm5n3:
    O = val
    if res_flag:
      
      Ores = out
      oarrm5n3_pow_to( &O.arr, e, &Ores.arr)

    else:

      cOres = oarrm5n3_pow( &O.arr, e)
      res   = omatm5n3.create(&cOres)

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
cpdef gauss_integrate(object val, feonumm5n3 w, object out = None ):
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
  

  cdef omatm5n3      O, Ores
  cdef dmat       R, Rres
  cdef feomatm5n3    F, Fres
  cdef onumm5n3    o, ores
  cdef coeff_t    r, rres
  cdef feonumm5n3     f, fres
  cdef coeff_t   crres
  cdef onumm5n3_t cores
  cdef feonumm5n3_t  cfres
  cdef darr_t    cRres
  cdef oarrm5n3_t   cOres
  cdef feoarrm5n3_t cFres 
  cdef uint8_t res_flag = 1
  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if

  if   tval is feonumm5n3:
    f = val
    if res_flag:
      
      ores = out
      feonumm5n3_integrate_f_to( &f.num, &w.num, &ores.num)

    else:

      cores = feonumm5n3_integrate_f( &f.num, &w.num)
      res   = onumm5n3.create(&cores)

    # end if  
  elif tval is feomatm5n3:
    F = val
    if res_flag:

      Ores = out
      feoarrm5n3_integrate_to( &F.arr, &w.num, &Ores.arr)

    else:

      cOres = feoarrm5n3_integrate( &F.arr, &w.num)
      res   = omatm5n3.create(&cOres)

    # end if 
  elif tval is onumm5n3:
    o = val
    if res_flag:
      
      ores = out
      feonumm5n3_integrate_o_to( &o.num, &w.num, &ores.num)

    else:

      cores = feonumm5n3_integrate_o( &o.num, &w.num)
      res   = onumm5n3.create(&cores)

    # end if
  else:
    try:
      r = val
      if res_flag:
        
        ores = out
        feonumm5n3_integrate_r_to( r, &w.num, &ores.num)

      else:

        cores = feonumm5n3_integrate_r( r, &w.num)
        res   = onumm5n3.create(&cores)

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

      -  omatm5n3
      -  feomatm5n3
      -  darr
      -  onumm5n3
      -  feonumm5n3
      -  real
  """
  #***************************************************************************************************

  cdef omatm5n3      O, Ores
  cdef dmat       R, Rres
  cdef feomatm5n3    F, Fres
  cdef onumm5n3    o, ores
  cdef coeff_t    r, rres
  cdef feonumm5n3     f, fres
  cdef coeff_t   crres
  cdef onumm5n3_t cores
  cdef feonumm5n3_t  cfres
  cdef darr_t    cRres
  cdef oarrm5n3_t   cOres
  cdef feoarrm5n3_t cFres
  cdef uint8_t res_flag = 1
  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 
  #
  if   tval is onumm5n3:
    o = val
    if res_flag:
      
      ores = out
      onumm5n3_neg_to( &o.num, &ores.num)

    else:

      cores = onumm5n3_neg( &o.num)
      res   = onumm5n3.create(&cores)

    # end if 
  elif tval is feonumm5n3:
    f = val
    if res_flag:
      
      fres = out
      feonumm5n3_neg_to( &f.num, &fres.num)

    else:

      cfres = feonumm5n3_neg( &f.num)
      res   = feonumm5n3.create(&cfres)

    # end if         
  elif tval is feomatm5n3:    
    F = val
    if res_flag:

      Fres = out
      feoarrm5n3_neg_to( &F.arr, &Fres.arr)

    else:

      cFres = feoarrm5n3_neg( &F.arr)
      res   = feomatm5n3.create(&cFres)

    # end if 
  elif tval is omatm5n3:
    O = val
    if res_flag:
      
      Ores = out
      oarrm5n3_neg_to( &O.arr, &Ores.arr)

    else:

      cOres = oarrm5n3_neg( &O.arr)
      res   = omatm5n3.create(&cOres)

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
