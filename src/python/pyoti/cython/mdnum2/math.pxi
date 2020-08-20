#*****************************************************************************************************
cpdef cos(object val, object out = None):
  """
  PURPOSE:  Matrix determinant.
  
  Supported types:

      -  mdmat2
      -  mdmatfe2
      -  darr
      -  mdnum2
      -  mdnumfe2
      -  real
  """
  #***************************************************************************************************

  cdef mdmat2      O, Ores
  cdef dmat       R, Rres
  cdef mdmatfe2    F, Fres
  cdef mdnum2    o, ores
  cdef coeff_t    r, rres
  cdef mdnumfe2     f, fres
  cdef coeff_t   crres
  cdef mdnum2_t cores
  cdef femdnum2_t  cfres
  cdef darr_t    cRres
  cdef mdarr2_t   cOres
  cdef femdarr2_t cFres
  cdef uint8_t res_flag = 1
  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 
  #
  if   tval is mdnum2:
    o = val
    if res_flag:
      
      ores = out
      mdnum2_cos_to( &o.num, &ores.num)

    else:

      cores = mdnum2_cos( &o.num)
      res   = mdnum2.create(&cores)

    # end if 
  elif tval is mdnumfe2:
    f = val
    if res_flag:
      
      fres = out
      femdnum2_cos_to( &f.num, &fres.num)

    else:

      cfres = femdnum2_cos( &f.num)
      res   = mdnumfe2.create(&cfres)

    # end if         
  elif tval is mdmatfe2:    
    F = val
    if res_flag:

      Fres = out
      femdarr2_cos_to( &F.arr, &Fres.arr)

    else:

      cFres = femdarr2_cos( &F.arr)
      res   = mdmatfe2.create(&cFres)

    # end if 
  elif tval is mdmat2:
    O = val
    if res_flag:
      
      Ores = out
      mdarr2_cos_to( &O.arr, &Ores.arr)

    else:

      cOres = mdarr2_cos( &O.arr)
      res   = mdmat2.create(&cOres)

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

      -  mdmat2
      -  mdmatfe2
      -  darr
      -  mdnum2
      -  mdnumfe2
      -  real
  """
  #***************************************************************************************************

  cdef mdmat2      O, Ores
  cdef dmat       R, Rres
  cdef mdmatfe2    F, Fres
  cdef mdnum2    o, ores
  cdef coeff_t    r, rres
  cdef mdnumfe2     f, fres
  cdef coeff_t   crres
  cdef mdnum2_t cores
  cdef femdnum2_t  cfres
  cdef darr_t    cRres
  cdef mdarr2_t   cOres
  cdef femdarr2_t cFres
  cdef uint8_t res_flag = 1
  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if   tval is mdnum2:
    o = val
    if res_flag:
      
      ores = out
      mdnum2_sin_to( &o.num, &ores.num)

    else:

      cores = mdnum2_sin( &o.num)
      res   = mdnum2.create(&cores)

    # end if 
  elif tval is mdnumfe2:
    f = val
    if res_flag:
      
      fres = out
      femdnum2_sin_to( &f.num, &fres.num)

    else:

      cfres = femdnum2_sin( &f.num)
      res   = mdnumfe2.create(&cfres)

    # end if  
  elif tval is mdmatfe2:    
    F = val
    if res_flag:

      Fres = out
      femdarr2_sin_to( &F.arr, &Fres.arr)

    else:

      cFres = femdarr2_sin( &F.arr)
      res   = mdmatfe2.create(&cFres)

    # end if 
  elif tval is mdmat2:
    O = val
    if res_flag:
      
      Ores = out
      mdarr2_sin_to( &O.arr, &Ores.arr)

    else:

      cOres = mdarr2_sin( &O.arr)
      res   = mdmat2.create(&cOres)

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

      -  mdmat2
      -  mdmatfe2
      -  darr
      -  mdnum2
      -  mdnumfe2
      -  real
  """
  #***************************************************************************************************

  cdef mdmat2      O, Ores
  cdef dmat       R, Rres
  cdef mdmatfe2    F, Fres
  cdef mdnum2    o, ores
  cdef coeff_t    r, rres
  cdef mdnumfe2     f, fres
  cdef coeff_t   crres
  cdef mdnum2_t cores
  cdef femdnum2_t  cfres
  cdef darr_t    cRres
  cdef mdarr2_t   cOres
  cdef femdarr2_t cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if   tval is mdnum2:
    o = val
    if res_flag:
      
      ores = out
      mdnum2_tan_to( &o.num, &ores.num)

    else:

      cores = mdnum2_tan( &o.num)
      res   = mdnum2.create(&cores)

    # end if 
  elif tval is mdnumfe2:
    f = val
    if res_flag:
      
      fres = out
      femdnum2_tan_to( &f.num, &fres.num)

    else:

      cfres = femdnum2_tan( &f.num)
      res   = mdnumfe2.create(&cfres)

    # end if  
  elif tval is mdmatfe2:    
    F = val
    if res_flag:

      Fres = out
      femdarr2_tan_to( &F.arr, &Fres.arr)

    else:

      cFres = femdarr2_tan( &F.arr)
      res   = mdmatfe2.create(&cFres)

    # end if 
  elif tval is mdmat2:
    O = val
    if res_flag:
      
      Ores = out
      mdarr2_tan_to( &O.arr, &Ores.arr)

    else:

      cOres = mdarr2_tan( &O.arr)
      res   = mdmat2.create(&cOres)

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

      -  mdmat2
      -  mdmatfe2
      -  darr
      -  mdnum2
      -  mdnumfe2
      -  real
  """
  #***************************************************************************************************

  cdef mdmat2      O, Ores
  cdef dmat       R, Rres
  cdef mdmatfe2    F, Fres
  cdef mdnum2    o, ores
  cdef coeff_t    r, rres
  cdef mdnumfe2     f, fres
  cdef coeff_t   crres
  cdef mdnum2_t cores
  cdef femdnum2_t  cfres
  cdef darr_t    cRres
  cdef mdarr2_t   cOres
  cdef femdarr2_t cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if   tval is mdnum2:
    o = val
    if res_flag:
      
      ores = out
      mdnum2_acos_to( &o.num, &ores.num)

    else:

      cores = mdnum2_acos( &o.num)
      res   = mdnum2.create(&cores)

    # end if 
  elif tval is mdnumfe2:
    f = val
    if res_flag:
      
      fres = out
      femdnum2_acos_to( &f.num, &fres.num)

    else:

      cfres = femdnum2_acos( &f.num)
      res   = mdnumfe2.create(&cfres)

    # end if  
  elif tval is mdmatfe2:    
    F = val
    if res_flag:

      Fres = out
      femdarr2_acos_to( &F.arr, &Fres.arr)

    else:

      cFres = femdarr2_acos( &F.arr)
      res   = mdmatfe2.create(&cFres)

    # end if 
  elif tval is mdmat2:
    O = val
    if res_flag:
      
      Ores = out
      mdarr2_acos_to( &O.arr, &Ores.arr)

    else:

      cOres = mdarr2_acos( &O.arr)
      res   = mdmat2.create(&cOres)

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

      -  mdmat2
      -  mdmatfe2
      -  darr
      -  mdnum2
      -  mdnumfe2
      -  real
  """
  #***************************************************************************************************

  cdef mdmat2      O, Ores
  cdef dmat       R, Rres
  cdef mdmatfe2    F, Fres
  cdef mdnum2    o, ores
  cdef coeff_t    r, rres
  cdef mdnumfe2     f, fres
  cdef coeff_t   crres
  cdef mdnum2_t cores
  cdef femdnum2_t  cfres
  cdef darr_t    cRres
  cdef mdarr2_t   cOres
  cdef femdarr2_t cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if   tval is mdnum2:
    o = val
    if res_flag:
      
      ores = out
      mdnum2_asin_to( &o.num, &ores.num)

    else:

      cores = mdnum2_asin( &o.num)
      res   = mdnum2.create(&cores)

    # end if 
  elif tval is mdnumfe2:
    f = val
    if res_flag:
      
      fres = out
      femdnum2_asin_to( &f.num, &fres.num)

    else:

      cfres = femdnum2_asin( &f.num)
      res   = mdnumfe2.create(&cfres)

    # end if  
  elif tval is mdmatfe2:    
    F = val
    if res_flag:

      Fres = out
      femdarr2_asin_to( &F.arr, &Fres.arr)

    else:

      cFres = femdarr2_asin( &F.arr)
      res   = mdmatfe2.create(&cFres)

    # end if 
  elif tval is mdmat2:
    O = val
    if res_flag:
      
      Ores = out
      mdarr2_asin_to( &O.arr, &Ores.arr)

    else:

      cOres = mdarr2_asin( &O.arr)
      res   = mdmat2.create(&cOres)

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

      -  mdmat2
      -  mdmatfe2
      -  darr
      -  mdnum2
      -  mdnumfe2
      -  real
  """
  #***************************************************************************************************

  cdef mdmat2      O, Ores
  cdef dmat       R, Rres
  cdef mdmatfe2    F, Fres
  cdef mdnum2    o, ores
  cdef coeff_t    r, rres
  cdef mdnumfe2     f, fres
  cdef coeff_t   crres
  cdef mdnum2_t cores
  cdef femdnum2_t  cfres
  cdef darr_t    cRres
  cdef mdarr2_t   cOres
  cdef femdarr2_t cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if   tval is mdnum2:
    o = val
    if res_flag:
      
      ores = out
      mdnum2_atan_to( &o.num, &ores.num)

    else:

      cores = mdnum2_atan( &o.num)
      res   = mdnum2.create(&cores)

    # end if 
  elif tval is mdnumfe2:
    f = val
    if res_flag:
      
      fres = out
      femdnum2_atan_to( &f.num, &fres.num)

    else:

      cfres = femdnum2_atan( &f.num)
      res   = mdnumfe2.create(&cfres)

    # end if  
  elif tval is mdmatfe2:    
    F = val
    if res_flag:

      Fres = out
      femdarr2_atan_to( &F.arr, &Fres.arr)

    else:

      cFres = femdarr2_atan( &F.arr)
      res   = mdmatfe2.create(&cFres)

    # end if 
  elif tval is mdmat2:
    O = val
    if res_flag:
      
      Ores = out
      mdarr2_atan_to( &O.arr, &Ores.arr)

    else:

      cOres = mdarr2_atan( &O.arr)
      res   = mdmat2.create(&cOres)

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

      -  mdmat2
      -  mdmatfe2
      -  darr
      -  mdnum2
      -  mdnumfe2
      -  real
  """
  #***************************************************************************************************

  cdef mdmat2      O, Ores
  cdef dmat       R, Rres
  cdef mdmatfe2    F, Fres
  cdef mdnum2    o, ores
  cdef coeff_t    r, rres
  cdef mdnumfe2     f, fres
  cdef coeff_t   crres
  cdef mdnum2_t cores
  cdef femdnum2_t  cfres
  cdef darr_t    cRres
  cdef mdarr2_t   cOres
  cdef femdarr2_t cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if   tval is mdnum2:
    o = val
    if res_flag:
      
      ores = out
      mdnum2_sinh_to( &o.num, &ores.num)

    else:

      cores = mdnum2_sinh( &o.num)
      res   = mdnum2.create(&cores)

    # end if 
  elif tval is mdnumfe2:
    f = val
    if res_flag:
      
      fres = out
      femdnum2_sinh_to( &f.num, &fres.num)

    else:

      cfres = femdnum2_sinh( &f.num)
      res   = mdnumfe2.create(&cfres)

    # end if  
  elif tval is mdmatfe2:    
    F = val
    if res_flag:

      Fres = out
      femdarr2_sinh_to( &F.arr, &Fres.arr)

    else:

      cFres = femdarr2_sinh( &F.arr)
      res   = mdmatfe2.create(&cFres)

    # end if 
  elif tval is mdmat2:
    O = val
    if res_flag:
      
      Ores = out
      mdarr2_sinh_to( &O.arr, &Ores.arr)

    else:

      cOres = mdarr2_sinh( &O.arr)
      res   = mdmat2.create(&cOres)

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

      -  mdmat2
      -  mdmatfe2
      -  darr
      -  mdnum2
      -  mdnumfe2
      -  real
  """
  #***************************************************************************************************

  cdef mdmat2      O, Ores
  cdef dmat       R, Rres
  cdef mdmatfe2    F, Fres
  cdef mdnum2    o, ores
  cdef coeff_t    r, rres
  cdef mdnumfe2     f, fres
  cdef coeff_t   crres
  cdef mdnum2_t cores
  cdef femdnum2_t  cfres
  cdef darr_t    cRres
  cdef mdarr2_t   cOres
  cdef femdarr2_t cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if   tval is mdnum2:
    o = val
    if res_flag:
      
      ores = out
      mdnum2_cosh_to( &o.num, &ores.num)

    else:

      cores = mdnum2_cosh( &o.num)
      res   = mdnum2.create(&cores)

    # end if 
  elif tval is mdnumfe2:
    f = val
    if res_flag:
      
      fres = out
      femdnum2_cosh_to( &f.num, &fres.num)

    else:

      cfres = femdnum2_cosh( &f.num)
      res   = mdnumfe2.create(&cfres)

    # end if  
  elif tval is mdmatfe2:    
    F = val
    if res_flag:

      Fres = out
      femdarr2_cosh_to( &F.arr, &Fres.arr)

    else:

      cFres = femdarr2_cosh( &F.arr)
      res   = mdmatfe2.create(&cFres)

    # end if 
  elif tval is mdmat2:
    O = val
    if res_flag:
      
      Ores = out
      mdarr2_cosh_to( &O.arr, &Ores.arr)

    else:

      cOres = mdarr2_cosh( &O.arr)
      res   = mdmat2.create(&cOres)

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

      -  mdmat2
      -  mdmatfe2
      -  darr
      -  mdnum2
      -  mdnumfe2
      -  real
  """
  #***************************************************************************************************

  cdef mdmat2      O, Ores
  cdef dmat       R, Rres
  cdef mdmatfe2    F, Fres
  cdef mdnum2    o, ores
  cdef coeff_t    r, rres
  cdef mdnumfe2     f, fres
  cdef coeff_t   crres
  cdef mdnum2_t cores
  cdef femdnum2_t  cfres
  cdef darr_t    cRres
  cdef mdarr2_t   cOres
  cdef femdarr2_t cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if   tval is mdnum2:
    o = val
    if res_flag:
      
      ores = out
      mdnum2_tanh_to( &o.num, &ores.num)

    else:

      cores = mdnum2_tanh( &o.num)
      res   = mdnum2.create(&cores)

    # end if 
  elif tval is mdnumfe2:
    f = val
    if res_flag:
      
      fres = out
      femdnum2_tanh_to( &f.num, &fres.num)

    else:

      cfres = femdnum2_tanh( &f.num)
      res   = mdnumfe2.create(&cfres)

    # end if  
  elif tval is mdmatfe2:    
    F = val
    if res_flag:

      Fres = out
      femdarr2_tanh_to( &F.arr, &Fres.arr)

    else:

      cFres = femdarr2_tanh( &F.arr)
      res   = mdmatfe2.create(&cFres)

    # end if 
  elif tval is mdmat2:
    O = val
    if res_flag:
      
      Ores = out
      mdarr2_tanh_to( &O.arr, &Ores.arr)

    else:

      cOres = mdarr2_tanh( &O.arr)
      res   = mdmat2.create(&cOres)

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

      -  mdmat2
      -  mdmatfe2
      -  darr
      -  mdnum2
      -  mdnumfe2
      -  real
  """
  #***************************************************************************************************

  cdef mdmat2      O, Ores
  cdef dmat       R, Rres
  cdef mdmatfe2    F, Fres
  cdef mdnum2    o, ores
  cdef coeff_t    r, rres
  cdef mdnumfe2     f, fres
  cdef coeff_t   crres
  cdef mdnum2_t cores
  cdef femdnum2_t  cfres
  cdef darr_t    cRres
  cdef mdarr2_t   cOres
  cdef femdarr2_t cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if   tval is mdnum2:
    o = val
    if res_flag:
      
      ores = out
      mdnum2_acosh_to( &o.num, &ores.num)

    else:

      cores = mdnum2_acosh( &o.num)
      res   = mdnum2.create(&cores)

    # end if 
  elif tval is mdnumfe2:
    f = val
    if res_flag:
      
      fres = out
      femdnum2_acosh_to( &f.num, &fres.num)

    else:

      cfres = femdnum2_acosh( &f.num)
      res   = mdnumfe2.create(&cfres)

    # end if  
  elif tval is mdmatfe2:    
    F = val
    if res_flag:

      Fres = out
      femdarr2_acosh_to( &F.arr, &Fres.arr)

    else:

      cFres = femdarr2_acosh( &F.arr)
      res   = mdmatfe2.create(&cFres)

    # end if 
  elif tval is mdmat2:
    O = val
    if res_flag:
      
      Ores = out
      mdarr2_acosh_to( &O.arr, &Ores.arr)

    else:

      cOres = mdarr2_acosh( &O.arr)
      res   = mdmat2.create(&cOres)

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

      -  mdmat2
      -  mdmatfe2
      -  darr
      -  mdnum2
      -  mdnumfe2
      -  real
  """
  #***************************************************************************************************

  cdef mdmat2      O, Ores
  cdef dmat       R, Rres
  cdef mdmatfe2    F, Fres
  cdef mdnum2    o, ores
  cdef coeff_t    r, rres
  cdef mdnumfe2     f, fres
  cdef coeff_t   crres
  cdef mdnum2_t cores
  cdef femdnum2_t  cfres
  cdef darr_t    cRres
  cdef mdarr2_t   cOres
  cdef femdarr2_t cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if   tval is mdnum2:
    o = val
    if res_flag:
      
      ores = out
      mdnum2_asinh_to( &o.num, &ores.num)

    else:

      cores = mdnum2_asinh( &o.num)
      res   = mdnum2.create(&cores)

    # end if 
  elif tval is mdnumfe2:
    f = val
    if res_flag:
      
      fres = out
      femdnum2_asinh_to( &f.num, &fres.num)

    else:

      cfres = femdnum2_asinh( &f.num)
      res   = mdnumfe2.create(&cfres)

    # end if  
  elif tval is mdmatfe2:    
    F = val
    if res_flag:

      Fres = out
      femdarr2_asinh_to( &F.arr, &Fres.arr)

    else:

      cFres = femdarr2_asinh( &F.arr)
      res   = mdmatfe2.create(&cFres)

    # end if 
  elif tval is mdmat2:
    O = val
    if res_flag:
      
      Ores = out
      mdarr2_asinh_to( &O.arr, &Ores.arr)

    else:

      cOres = mdarr2_asinh( &O.arr)
      res   = mdmat2.create(&cOres)

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

      -  mdmat2
      -  mdmatfe2
      -  darr
      -  mdnum2
      -  mdnumfe2
      -  real
  """
  #***************************************************************************************************

  cdef mdmat2      O, Ores
  cdef dmat       R, Rres
  cdef mdmatfe2    F, Fres
  cdef mdnum2    o, ores
  cdef coeff_t    r, rres
  cdef mdnumfe2     f, fres
  cdef coeff_t   crres
  cdef mdnum2_t cores
  cdef femdnum2_t  cfres
  cdef darr_t    cRres
  cdef mdarr2_t   cOres
  cdef femdarr2_t cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if   tval is mdnum2:
    o = val
    if res_flag:
      
      ores = out
      mdnum2_atanh_to( &o.num, &ores.num)

    else:

      cores = mdnum2_atanh( &o.num)
      res   = mdnum2.create(&cores)

    # end if 
  elif tval is mdnumfe2:
    f = val
    if res_flag:
      
      fres = out
      femdnum2_atanh_to( &f.num, &fres.num)

    else:

      cfres = femdnum2_atanh( &f.num)
      res   = mdnumfe2.create(&cfres)

    # end if  
  elif tval is mdmatfe2:    
    F = val
    if res_flag:

      Fres = out
      femdarr2_atanh_to( &F.arr, &Fres.arr)

    else:

      cFres = femdarr2_atanh( &F.arr)
      res   = mdmatfe2.create(&cFres)

    # end if 
  elif tval is mdmat2:
    O = val
    if res_flag:
      
      Ores = out
      mdarr2_atanh_to( &O.arr, &Ores.arr)

    else:

      cOres = mdarr2_atanh( &O.arr)
      res   = mdmat2.create(&cOres)

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

      -  mdmat2
      -  mdmatfe2
      -  darr
      -  mdnum2
      -  mdnumfe2
      -  real
  """
  #***************************************************************************************************

  cdef mdmat2      O, Ores
  cdef dmat       R, Rres
  cdef mdmatfe2    F, Fres
  cdef mdnum2    o, ores
  cdef coeff_t    r, rres
  cdef mdnumfe2     f, fres
  cdef coeff_t   crres
  cdef mdnum2_t cores
  cdef femdnum2_t  cfres
  cdef darr_t    cRres
  cdef mdarr2_t   cOres
  cdef femdarr2_t cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if   tval is mdnum2:
    o = val
    if res_flag:
      
      ores = out
      mdnum2_exp_to( &o.num, &ores.num)

    else:

      cores = mdnum2_exp( &o.num)
      res   = mdnum2.create(&cores)

    # end if 
  elif tval is mdnumfe2:
    f = val
    if res_flag:
      
      fres = out
      femdnum2_exp_to( &f.num, &fres.num)

    else:

      cfres = femdnum2_exp( &f.num)
      res   = mdnumfe2.create(&cfres)

    # end if  
  elif tval is mdmatfe2:    
    F = val
    if res_flag:

      Fres = out
      femdarr2_exp_to( &F.arr, &Fres.arr)

    else:

      cFres = femdarr2_exp( &F.arr)
      res   = mdmatfe2.create(&cFres)

    # end if 
  elif tval is mdmat2:
    O = val
    if res_flag:
      
      Ores = out
      mdarr2_exp_to( &O.arr, &Ores.arr)

    else:

      cOres = mdarr2_exp( &O.arr)
      res   = mdmat2.create(&cOres)

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

      -  mdmat2
      -  mdmatfe2
      -  darr
      -  mdnum2
      -  mdnumfe2
      -  real

  INPUTS:

    - val: Value to evaluate. Must be a supported one of the supported types.
    - out: (optional) Holder of result, in order to avoid memory allocation.

  OUTPUTS:

    If out is not defined, then the result is a newlly allocated member containing the result.
  """
  #***************************************************************************************************

  cdef mdmat2      O, Ores
  cdef dmat       R, Rres
  cdef mdmatfe2    F, Fres
  cdef mdnum2    o, ores
  cdef coeff_t    r, rres
  cdef mdnumfe2     f, fres
  cdef coeff_t   crres
  cdef mdnum2_t cores
  cdef femdnum2_t  cfres
  cdef darr_t    cRres
  cdef mdarr2_t   cOres
  cdef femdarr2_t cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if   tval is mdnum2:
    o = val
    if res_flag:
      
      ores = out
      mdnum2_log_to( &o.num, &ores.num)

    else:

      cores = mdnum2_log( &o.num)
      res   = mdnum2.create(&cores)

    # end if 
  elif tval is mdnumfe2:
    f = val
    if res_flag:
      
      fres = out
      femdnum2_log_to( &f.num, &fres.num)

    else:

      cfres = femdnum2_log( &f.num)
      res   = mdnumfe2.create(&cfres)

    # end if  
  elif tval is mdmatfe2:    
    F = val
    if res_flag:

      Fres = out
      femdarr2_log_to( &F.arr, &Fres.arr)

    else:

      cFres = femdarr2_log( &F.arr)
      res   = mdmatfe2.create(&cFres)

    # end if 
  elif tval is mdmat2:
    O = val
    if res_flag:
      
      Ores = out
      mdarr2_log_to( &O.arr, &Ores.arr)

    else:

      cOres = mdarr2_log( &O.arr)
      res   = mdmat2.create(&cOres)

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

      -  mdmat2
      -  mdmatfe2
      -  darr
      -  mdnum2
      -  mdnumfe2
      -  real

  INPUTS:

    - val: Value to evaluate. Must be a supported one of the supported types.
    - out: (optional) Holder of result, in order to avoid memory allocation.

  OUTPUTS:

    If out is not defined, then the result is a newlly allocated member containing the result.
  """
  #***************************************************************************************************

  cdef mdmat2      O, Ores
  cdef dmat       R, Rres
  cdef mdmatfe2    F, Fres
  cdef mdnum2    o, ores
  cdef coeff_t    r, rres
  cdef mdnumfe2     f, fres
  cdef coeff_t   crres
  cdef mdnum2_t cores
  cdef femdnum2_t  cfres
  cdef darr_t    cRres
  cdef mdarr2_t   cOres
  cdef femdarr2_t cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if   tval is mdnum2:
    o = val
    if res_flag:
      
      ores = out
      mdnum2_log10_to( &o.num, &ores.num)

    else:

      cores = mdnum2_log10( &o.num)
      res   = mdnum2.create(&cores)

    # end if 
  elif tval is mdnumfe2:
    f = val
    if res_flag:
      
      fres = out
      femdnum2_log10_to( &f.num, &fres.num)

    else:

      cfres = femdnum2_log10( &f.num)
      res   = mdnumfe2.create(&cfres)

    # end if  
  elif tval is mdmatfe2:    
    F = val
    if res_flag:

      Fres = out
      femdarr2_log10_to( &F.arr, &Fres.arr)

    else:

      cFres = femdarr2_log10( &F.arr)
      res   = mdmatfe2.create(&cFres)

    # end if 
  elif tval is mdmat2:
    O = val
    if res_flag:
      
      Ores = out
      mdarr2_log10_to( &O.arr, &Ores.arr)

    else:

      cOres = mdarr2_log10( &O.arr)
      res   = mdmat2.create(&cOres)

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

      -  mdmat2
      -  mdmatfe2
      -  darr
      -  mdnum2
      -  mdnumfe2
      -  real

  INPUTS:

    - val: Value to evaluate. Must be a supported one of the supported types.
    - b:   Base.
    - out: (optional) Holder of result, in order to avoid memory allocation.

  OUTPUTS:

    If out is not defined, then the result is a newlly allocated member containing the result.
  """
  #***************************************************************************************************

  cdef mdmat2      O, Ores
  cdef dmat       R, Rres
  cdef mdmatfe2    F, Fres
  cdef mdnum2    o, ores
  cdef coeff_t    r, rres
  cdef mdnumfe2     f, fres
  cdef coeff_t   crres
  cdef mdnum2_t cores
  cdef femdnum2_t  cfres
  cdef darr_t    cRres
  cdef mdarr2_t   cOres
  cdef femdarr2_t cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if   tval is mdnum2:
    o = val
    if res_flag:
      
      ores = out
      mdnum2_logb_to( &o.num, b, &ores.num)

    else:

      cores = mdnum2_logb( &o.num, b)
      res   = mdnum2.create(&cores)

    # end if 
  elif tval is mdnumfe2:
    f = val
    if res_flag:
      
      fres = out
      femdnum2_logb_to( &f.num, b, &fres.num)

    else:

      cfres = femdnum2_logb( &f.num, b)
      res   = mdnumfe2.create(&cfres)

    # end if  
  elif tval is mdmatfe2:    
    F = val
    if res_flag:

      Fres = out
      femdarr2_logb_to( &F.arr, b, &Fres.arr)

    else:

      cFres = femdarr2_logb( &F.arr, b)
      res   = mdmatfe2.create(&cFres)

    # end if 
  elif tval is mdmat2:
    O = val
    if res_flag:
      
      Ores = out
      mdarr2_logb_to( &O.arr, b, &Ores.arr)

    else:

      cOres = mdarr2_logb( &O.arr, b)
      res   = mdmat2.create(&cOres)

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

      -  mdmat2
      -  mdmatfe2
      -  darr
      -  mdnum2
      -  mdnumfe2
      -  real

  INPUTS:

    - val: Value to evaluate. Must be a supported one of the supported types.
    - out: (optional) Holder of result, in order to avoid memory allocation.

  OUTPUTS:

    If out is not defined, then the result is a newlly allocated member containing the result.
  """
  #***************************************************************************************************

  cdef mdmat2      O, Ores
  cdef dmat       R, Rres
  cdef mdmatfe2    F, Fres
  cdef mdnum2    o, ores
  cdef coeff_t    r, rres
  cdef mdnumfe2     f, fres
  cdef coeff_t   crres
  cdef mdnum2_t cores
  cdef femdnum2_t  cfres
  cdef darr_t    cRres
  cdef mdarr2_t   cOres
  cdef femdarr2_t cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if   tval is mdnum2:
    o = val
    if res_flag:
      
      ores = out
      mdnum2_sqrt_to( &o.num, &ores.num)

    else:

      cores = mdnum2_sqrt( &o.num)
      res   = mdnum2.create(&cores)

    # end if 
  elif tval is mdnumfe2:
    f = val
    if res_flag:
      
      fres = out
      femdnum2_sqrt_to( &f.num, &fres.num)

    else:

      cfres = femdnum2_sqrt( &f.num)
      res   = mdnumfe2.create(&cfres)

    # end if  
  elif tval is mdmatfe2:    
    F = val
    if res_flag:

      Fres = out
      femdarr2_sqrt_to( &F.arr, &Fres.arr)

    else:

      cFres = femdarr2_sqrt( &F.arr)
      res   = mdmatfe2.create(&cFres)

    # end if 
  elif tval is mdmat2:
    O = val
    if res_flag:
      
      Ores = out
      mdarr2_sqrt_to( &O.arr, &Ores.arr)

    else:

      cOres = mdarr2_sqrt( &O.arr)
      res   = mdmat2.create(&cOres)

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

      -  mdmat2
      -  mdmatfe2
      -  darr
      -  mdnum2
      -  mdnumfe2
      -  real

  INPUTS:

    - val: Value to evaluate. Must be a supported one of the supported types.
    - out: (optional) Holder of result, in order to avoid memory allocation.

  OUTPUTS:

    If out is not defined, then the result is a newlly allocated member containing the result.
  """
  #***************************************************************************************************

  cdef mdmat2      O, Ores
  cdef dmat       R, Rres
  cdef mdmatfe2    F, Fres
  cdef mdnum2    o, ores
  cdef coeff_t    r, rres
  cdef mdnumfe2     f, fres
  cdef coeff_t   crres
  cdef mdnum2_t cores
  cdef femdnum2_t  cfres
  cdef darr_t    cRres
  cdef mdarr2_t   cOres
  cdef femdarr2_t cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if   tval is mdnum2:
    o = val
    if res_flag:
      
      ores = out
      mdnum2_cbrt_to( &o.num, &ores.num)

    else:

      cores = mdnum2_cbrt( &o.num)
      res   = mdnum2.create(&cores)

    # end if 
  elif tval is mdnumfe2:
    f = val
    if res_flag:
      
      fres = out
      femdnum2_cbrt_to( &f.num, &fres.num)

    else:

      cfres = femdnum2_cbrt( &f.num)
      res   = mdnumfe2.create(&cfres)

    # end if  
  elif tval is mdmatfe2:    
    F = val
    if res_flag:

      Fres = out
      femdarr2_cbrt_to( &F.arr, &Fres.arr)

    else:

      cFres = femdarr2_cbrt( &F.arr)
      res   = mdmatfe2.create(&cFres)

    # end if 
  elif tval is mdmat2:
    O = val
    if res_flag:
      
      Ores = out
      mdarr2_cbrt_to( &O.arr, &Ores.arr)

    else:

      cOres = mdarr2_cbrt( &O.arr)
      res   = mdmat2.create(&cOres)

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

      -  mdmat2
      -  mdmatfe2
      -  darr
      -  mdnum2
      -  mdnumfe2
      -  real

  INPUTS:

    - val: Value to evaluate. Must be a supported one of the supported types.
    - e:   exponent.
    - out: (optional) Holder of result, in order to avoid memory allocation.

  OUTPUTS:

    If out is not defined, then the result is a newlly allocated member containing the result.
  """
  #***************************************************************************************************

  cdef mdmat2      O, Ores
  cdef dmat       R, Rres
  cdef mdmatfe2    F, Fres
  cdef mdnum2    o, ores
  cdef coeff_t    r, rres
  cdef mdnumfe2     f, fres
  cdef coeff_t   crres
  cdef mdnum2_t cores
  cdef femdnum2_t  cfres
  cdef darr_t    cRres
  cdef mdarr2_t   cOres
  cdef femdarr2_t cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if   tval is mdnum2:
    o = val
    if res_flag:
      
      ores = out
      mdnum2_pow_to( &o.num, e, &ores.num)

    else:

      cores = mdnum2_pow( &o.num, e)
      res   = mdnum2.create(&cores)

    # end if 
  elif tval is mdnumfe2:
    f = val
    if res_flag:
      
      fres = out
      femdnum2_pow_to( &f.num, e, &fres.num)

    else:

      cfres = femdnum2_pow( &f.num, e)
      res   = mdnumfe2.create(&cfres)

    # end if  
  elif tval is mdmatfe2:    
    F = val
    if res_flag:

      Fres = out
      femdarr2_pow_to( &F.arr, e, &Fres.arr)

    else:

      cFres = femdarr2_pow( &F.arr, e)
      res   = mdmatfe2.create(&cFres)

    # end if 
  elif tval is mdmat2:
    O = val
    if res_flag:
      
      Ores = out
      mdarr2_pow_to( &O.arr, e, &Ores.arr)

    else:

      cOres = mdarr2_pow( &O.arr, e)
      res   = mdmat2.create(&cOres)

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
cpdef gauss_integrate(object val, mdnumfe2 w, object out = None ):
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
  

  cdef mdmat2      O, Ores
  cdef dmat       R, Rres
  cdef mdmatfe2    F, Fres
  cdef mdnum2    o, ores
  cdef coeff_t    r, rres
  cdef mdnumfe2     f, fres
  cdef coeff_t   crres
  cdef mdnum2_t cores
  cdef femdnum2_t  cfres
  cdef darr_t    cRres
  cdef mdarr2_t   cOres
  cdef femdarr2_t cFres 
  cdef uint8_t res_flag = 1
  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if

  if   tval is mdnumfe2:
    f = val
    if res_flag:
      
      ores = out
      femdnum2_integrate_f_to( &f.num, &w.num, &ores.num)

    else:

      cores = femdnum2_integrate_f( &f.num, &w.num)
      res   = mdnum2.create(&cores)

    # end if  
  elif tval is mdmatfe2:
    F = val
    if res_flag:

      Ores = out
      femdarr2_integrate_to( &F.arr, &w.num, &Ores.arr)

    else:

      cOres = femdarr2_integrate( &F.arr, &w.num)
      res   = mdmat2.create(&cOres)

    # end if 
  elif tval is mdnum2:
    o = val
    if res_flag:
      
      ores = out
      femdnum2_integrate_o_to( &o.num, &w.num, &ores.num)

    else:

      cores = femdnum2_integrate_o( &o.num, &w.num)
      res   = mdnum2.create(&cores)

    # end if
  else:
    try:
      r = val
      if res_flag:
        
        ores = out
        femdnum2_integrate_r_to( r, &w.num, &ores.num)

      else:

        cores = femdnum2_integrate_r( r, &w.num)
        res   = mdnum2.create(&cores)

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

      -  mdmat2
      -  mdmatfe2
      -  darr
      -  mdnum2
      -  mdnumfe2
      -  real
  """
  #***************************************************************************************************

  cdef mdmat2      O, Ores
  cdef dmat       R, Rres
  cdef mdmatfe2    F, Fres
  cdef mdnum2    o, ores
  cdef coeff_t    r, rres
  cdef mdnumfe2     f, fres
  cdef coeff_t   crres
  cdef mdnum2_t cores
  cdef femdnum2_t  cfres
  cdef darr_t    cRres
  cdef mdarr2_t   cOres
  cdef femdarr2_t cFres
  cdef uint8_t res_flag = 1
  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 
  #
  if   tval is mdnum2:
    o = val
    if res_flag:
      
      ores = out
      mdnum2_neg_to( &o.num, &ores.num)

    else:

      cores = mdnum2_neg( &o.num)
      res   = mdnum2.create(&cores)

    # end if 
  elif tval is mdnumfe2:
    f = val
    if res_flag:
      
      fres = out
      femdnum2_neg_to( &f.num, &fres.num)

    else:

      cfres = femdnum2_neg( &f.num)
      res   = mdnumfe2.create(&cfres)

    # end if         
  elif tval is mdmatfe2:    
    F = val
    if res_flag:

      Fres = out
      femdarr2_neg_to( &F.arr, &Fres.arr)

    else:

      cFres = femdarr2_neg( &F.arr)
      res   = mdmatfe2.create(&cFres)

    # end if 
  elif tval is mdmat2:
    O = val
    if res_flag:
      
      Ores = out
      mdarr2_neg_to( &O.arr, &Ores.arr)

    else:

      cOres = mdarr2_neg( &O.arr)
      res   = mdmat2.create(&cOres)

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
