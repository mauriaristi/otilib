#*****************************************************************************************************
cpdef cos(object val, object out = None):
  """
  PURPOSE:  Matrix determinant.
  
  Supported types:

      -  mdmat8
      -  mdmatfe8
      -  darr
      -  mdnum8
      -  mdnumfe8
      -  real
  """
  #***************************************************************************************************

  cdef mdmat8      O, Ores
  cdef dmat       R, Rres
  cdef mdmatfe8    F, Fres
  cdef mdnum8    o, ores
  cdef coeff_t    r, rres
  cdef mdnumfe8     f, fres
  cdef coeff_t   crres
  cdef mdnum8_t cores
  cdef femdnum8_t  cfres
  cdef darr_t    cRres
  cdef mdarr8_t   cOres
  cdef femdarr8_t cFres
  cdef uint8_t res_flag = 1
  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 
  #
  if   tval is mdnum8:
    o = val
    if res_flag:
      
      ores = out
      mdnum8_cos_to( &o.num, &ores.num)

    else:

      cores = mdnum8_cos( &o.num)
      res   = mdnum8.create(&cores)

    # end if 
  elif tval is mdnumfe8:
    f = val
    if res_flag:
      
      fres = out
      femdnum8_cos_to( &f.num, &fres.num)

    else:

      cfres = femdnum8_cos( &f.num)
      res   = mdnumfe8.create(&cfres)

    # end if         
  elif tval is mdmatfe8:    
    F = val
    if res_flag:

      Fres = out
      femdarr8_cos_to( &F.arr, &Fres.arr)

    else:

      cFres = femdarr8_cos( &F.arr)
      res   = mdmatfe8.create(&cFres)

    # end if 
  elif tval is mdmat8:
    O = val
    if res_flag:
      
      Ores = out
      mdarr8_cos_to( &O.arr, &Ores.arr)

    else:

      cOres = mdarr8_cos( &O.arr)
      res   = mdmat8.create(&cOres)

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

      -  mdmat8
      -  mdmatfe8
      -  darr
      -  mdnum8
      -  mdnumfe8
      -  real
  """
  #***************************************************************************************************

  cdef mdmat8      O, Ores
  cdef dmat       R, Rres
  cdef mdmatfe8    F, Fres
  cdef mdnum8    o, ores
  cdef coeff_t    r, rres
  cdef mdnumfe8     f, fres
  cdef coeff_t   crres
  cdef mdnum8_t cores
  cdef femdnum8_t  cfres
  cdef darr_t    cRres
  cdef mdarr8_t   cOres
  cdef femdarr8_t cFres
  cdef uint8_t res_flag = 1
  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if   tval is mdnum8:
    o = val
    if res_flag:
      
      ores = out
      mdnum8_sin_to( &o.num, &ores.num)

    else:

      cores = mdnum8_sin( &o.num)
      res   = mdnum8.create(&cores)

    # end if 
  elif tval is mdnumfe8:
    f = val
    if res_flag:
      
      fres = out
      femdnum8_sin_to( &f.num, &fres.num)

    else:

      cfres = femdnum8_sin( &f.num)
      res   = mdnumfe8.create(&cfres)

    # end if  
  elif tval is mdmatfe8:    
    F = val
    if res_flag:

      Fres = out
      femdarr8_sin_to( &F.arr, &Fres.arr)

    else:

      cFres = femdarr8_sin( &F.arr)
      res   = mdmatfe8.create(&cFres)

    # end if 
  elif tval is mdmat8:
    O = val
    if res_flag:
      
      Ores = out
      mdarr8_sin_to( &O.arr, &Ores.arr)

    else:

      cOres = mdarr8_sin( &O.arr)
      res   = mdmat8.create(&cOres)

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

      -  mdmat8
      -  mdmatfe8
      -  darr
      -  mdnum8
      -  mdnumfe8
      -  real
  """
  #***************************************************************************************************

  cdef mdmat8      O, Ores
  cdef dmat       R, Rres
  cdef mdmatfe8    F, Fres
  cdef mdnum8    o, ores
  cdef coeff_t    r, rres
  cdef mdnumfe8     f, fres
  cdef coeff_t   crres
  cdef mdnum8_t cores
  cdef femdnum8_t  cfres
  cdef darr_t    cRres
  cdef mdarr8_t   cOres
  cdef femdarr8_t cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if   tval is mdnum8:
    o = val
    if res_flag:
      
      ores = out
      mdnum8_tan_to( &o.num, &ores.num)

    else:

      cores = mdnum8_tan( &o.num)
      res   = mdnum8.create(&cores)

    # end if 
  elif tval is mdnumfe8:
    f = val
    if res_flag:
      
      fres = out
      femdnum8_tan_to( &f.num, &fres.num)

    else:

      cfres = femdnum8_tan( &f.num)
      res   = mdnumfe8.create(&cfres)

    # end if  
  elif tval is mdmatfe8:    
    F = val
    if res_flag:

      Fres = out
      femdarr8_tan_to( &F.arr, &Fres.arr)

    else:

      cFres = femdarr8_tan( &F.arr)
      res   = mdmatfe8.create(&cFres)

    # end if 
  elif tval is mdmat8:
    O = val
    if res_flag:
      
      Ores = out
      mdarr8_tan_to( &O.arr, &Ores.arr)

    else:

      cOres = mdarr8_tan( &O.arr)
      res   = mdmat8.create(&cOres)

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

      -  mdmat8
      -  mdmatfe8
      -  darr
      -  mdnum8
      -  mdnumfe8
      -  real
  """
  #***************************************************************************************************

  cdef mdmat8      O, Ores
  cdef dmat       R, Rres
  cdef mdmatfe8    F, Fres
  cdef mdnum8    o, ores
  cdef coeff_t    r, rres
  cdef mdnumfe8     f, fres
  cdef coeff_t   crres
  cdef mdnum8_t cores
  cdef femdnum8_t  cfres
  cdef darr_t    cRres
  cdef mdarr8_t   cOres
  cdef femdarr8_t cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if   tval is mdnum8:
    o = val
    if res_flag:
      
      ores = out
      mdnum8_acos_to( &o.num, &ores.num)

    else:

      cores = mdnum8_acos( &o.num)
      res   = mdnum8.create(&cores)

    # end if 
  elif tval is mdnumfe8:
    f = val
    if res_flag:
      
      fres = out
      femdnum8_acos_to( &f.num, &fres.num)

    else:

      cfres = femdnum8_acos( &f.num)
      res   = mdnumfe8.create(&cfres)

    # end if  
  elif tval is mdmatfe8:    
    F = val
    if res_flag:

      Fres = out
      femdarr8_acos_to( &F.arr, &Fres.arr)

    else:

      cFres = femdarr8_acos( &F.arr)
      res   = mdmatfe8.create(&cFres)

    # end if 
  elif tval is mdmat8:
    O = val
    if res_flag:
      
      Ores = out
      mdarr8_acos_to( &O.arr, &Ores.arr)

    else:

      cOres = mdarr8_acos( &O.arr)
      res   = mdmat8.create(&cOres)

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

      -  mdmat8
      -  mdmatfe8
      -  darr
      -  mdnum8
      -  mdnumfe8
      -  real
  """
  #***************************************************************************************************

  cdef mdmat8      O, Ores
  cdef dmat       R, Rres
  cdef mdmatfe8    F, Fres
  cdef mdnum8    o, ores
  cdef coeff_t    r, rres
  cdef mdnumfe8     f, fres
  cdef coeff_t   crres
  cdef mdnum8_t cores
  cdef femdnum8_t  cfres
  cdef darr_t    cRres
  cdef mdarr8_t   cOres
  cdef femdarr8_t cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if   tval is mdnum8:
    o = val
    if res_flag:
      
      ores = out
      mdnum8_asin_to( &o.num, &ores.num)

    else:

      cores = mdnum8_asin( &o.num)
      res   = mdnum8.create(&cores)

    # end if 
  elif tval is mdnumfe8:
    f = val
    if res_flag:
      
      fres = out
      femdnum8_asin_to( &f.num, &fres.num)

    else:

      cfres = femdnum8_asin( &f.num)
      res   = mdnumfe8.create(&cfres)

    # end if  
  elif tval is mdmatfe8:    
    F = val
    if res_flag:

      Fres = out
      femdarr8_asin_to( &F.arr, &Fres.arr)

    else:

      cFres = femdarr8_asin( &F.arr)
      res   = mdmatfe8.create(&cFres)

    # end if 
  elif tval is mdmat8:
    O = val
    if res_flag:
      
      Ores = out
      mdarr8_asin_to( &O.arr, &Ores.arr)

    else:

      cOres = mdarr8_asin( &O.arr)
      res   = mdmat8.create(&cOres)

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

      -  mdmat8
      -  mdmatfe8
      -  darr
      -  mdnum8
      -  mdnumfe8
      -  real
  """
  #***************************************************************************************************

  cdef mdmat8      O, Ores
  cdef dmat       R, Rres
  cdef mdmatfe8    F, Fres
  cdef mdnum8    o, ores
  cdef coeff_t    r, rres
  cdef mdnumfe8     f, fres
  cdef coeff_t   crres
  cdef mdnum8_t cores
  cdef femdnum8_t  cfres
  cdef darr_t    cRres
  cdef mdarr8_t   cOres
  cdef femdarr8_t cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if   tval is mdnum8:
    o = val
    if res_flag:
      
      ores = out
      mdnum8_atan_to( &o.num, &ores.num)

    else:

      cores = mdnum8_atan( &o.num)
      res   = mdnum8.create(&cores)

    # end if 
  elif tval is mdnumfe8:
    f = val
    if res_flag:
      
      fres = out
      femdnum8_atan_to( &f.num, &fres.num)

    else:

      cfres = femdnum8_atan( &f.num)
      res   = mdnumfe8.create(&cfres)

    # end if  
  elif tval is mdmatfe8:    
    F = val
    if res_flag:

      Fres = out
      femdarr8_atan_to( &F.arr, &Fres.arr)

    else:

      cFres = femdarr8_atan( &F.arr)
      res   = mdmatfe8.create(&cFres)

    # end if 
  elif tval is mdmat8:
    O = val
    if res_flag:
      
      Ores = out
      mdarr8_atan_to( &O.arr, &Ores.arr)

    else:

      cOres = mdarr8_atan( &O.arr)
      res   = mdmat8.create(&cOres)

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

      -  mdmat8
      -  mdmatfe8
      -  darr
      -  mdnum8
      -  mdnumfe8
      -  real
  """
  #***************************************************************************************************

  cdef mdmat8      O, Ores
  cdef dmat       R, Rres
  cdef mdmatfe8    F, Fres
  cdef mdnum8    o, ores
  cdef coeff_t    r, rres
  cdef mdnumfe8     f, fres
  cdef coeff_t   crres
  cdef mdnum8_t cores
  cdef femdnum8_t  cfres
  cdef darr_t    cRres
  cdef mdarr8_t   cOres
  cdef femdarr8_t cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if   tval is mdnum8:
    o = val
    if res_flag:
      
      ores = out
      mdnum8_sinh_to( &o.num, &ores.num)

    else:

      cores = mdnum8_sinh( &o.num)
      res   = mdnum8.create(&cores)

    # end if 
  elif tval is mdnumfe8:
    f = val
    if res_flag:
      
      fres = out
      femdnum8_sinh_to( &f.num, &fres.num)

    else:

      cfres = femdnum8_sinh( &f.num)
      res   = mdnumfe8.create(&cfres)

    # end if  
  elif tval is mdmatfe8:    
    F = val
    if res_flag:

      Fres = out
      femdarr8_sinh_to( &F.arr, &Fres.arr)

    else:

      cFres = femdarr8_sinh( &F.arr)
      res   = mdmatfe8.create(&cFres)

    # end if 
  elif tval is mdmat8:
    O = val
    if res_flag:
      
      Ores = out
      mdarr8_sinh_to( &O.arr, &Ores.arr)

    else:

      cOres = mdarr8_sinh( &O.arr)
      res   = mdmat8.create(&cOres)

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

      -  mdmat8
      -  mdmatfe8
      -  darr
      -  mdnum8
      -  mdnumfe8
      -  real
  """
  #***************************************************************************************************

  cdef mdmat8      O, Ores
  cdef dmat       R, Rres
  cdef mdmatfe8    F, Fres
  cdef mdnum8    o, ores
  cdef coeff_t    r, rres
  cdef mdnumfe8     f, fres
  cdef coeff_t   crres
  cdef mdnum8_t cores
  cdef femdnum8_t  cfres
  cdef darr_t    cRres
  cdef mdarr8_t   cOres
  cdef femdarr8_t cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if   tval is mdnum8:
    o = val
    if res_flag:
      
      ores = out
      mdnum8_cosh_to( &o.num, &ores.num)

    else:

      cores = mdnum8_cosh( &o.num)
      res   = mdnum8.create(&cores)

    # end if 
  elif tval is mdnumfe8:
    f = val
    if res_flag:
      
      fres = out
      femdnum8_cosh_to( &f.num, &fres.num)

    else:

      cfres = femdnum8_cosh( &f.num)
      res   = mdnumfe8.create(&cfres)

    # end if  
  elif tval is mdmatfe8:    
    F = val
    if res_flag:

      Fres = out
      femdarr8_cosh_to( &F.arr, &Fres.arr)

    else:

      cFres = femdarr8_cosh( &F.arr)
      res   = mdmatfe8.create(&cFres)

    # end if 
  elif tval is mdmat8:
    O = val
    if res_flag:
      
      Ores = out
      mdarr8_cosh_to( &O.arr, &Ores.arr)

    else:

      cOres = mdarr8_cosh( &O.arr)
      res   = mdmat8.create(&cOres)

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

      -  mdmat8
      -  mdmatfe8
      -  darr
      -  mdnum8
      -  mdnumfe8
      -  real
  """
  #***************************************************************************************************

  cdef mdmat8      O, Ores
  cdef dmat       R, Rres
  cdef mdmatfe8    F, Fres
  cdef mdnum8    o, ores
  cdef coeff_t    r, rres
  cdef mdnumfe8     f, fres
  cdef coeff_t   crres
  cdef mdnum8_t cores
  cdef femdnum8_t  cfres
  cdef darr_t    cRres
  cdef mdarr8_t   cOres
  cdef femdarr8_t cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if   tval is mdnum8:
    o = val
    if res_flag:
      
      ores = out
      mdnum8_tanh_to( &o.num, &ores.num)

    else:

      cores = mdnum8_tanh( &o.num)
      res   = mdnum8.create(&cores)

    # end if 
  elif tval is mdnumfe8:
    f = val
    if res_flag:
      
      fres = out
      femdnum8_tanh_to( &f.num, &fres.num)

    else:

      cfres = femdnum8_tanh( &f.num)
      res   = mdnumfe8.create(&cfres)

    # end if  
  elif tval is mdmatfe8:    
    F = val
    if res_flag:

      Fres = out
      femdarr8_tanh_to( &F.arr, &Fres.arr)

    else:

      cFres = femdarr8_tanh( &F.arr)
      res   = mdmatfe8.create(&cFres)

    # end if 
  elif tval is mdmat8:
    O = val
    if res_flag:
      
      Ores = out
      mdarr8_tanh_to( &O.arr, &Ores.arr)

    else:

      cOres = mdarr8_tanh( &O.arr)
      res   = mdmat8.create(&cOres)

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

      -  mdmat8
      -  mdmatfe8
      -  darr
      -  mdnum8
      -  mdnumfe8
      -  real
  """
  #***************************************************************************************************

  cdef mdmat8      O, Ores
  cdef dmat       R, Rres
  cdef mdmatfe8    F, Fres
  cdef mdnum8    o, ores
  cdef coeff_t    r, rres
  cdef mdnumfe8     f, fres
  cdef coeff_t   crres
  cdef mdnum8_t cores
  cdef femdnum8_t  cfres
  cdef darr_t    cRres
  cdef mdarr8_t   cOres
  cdef femdarr8_t cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if   tval is mdnum8:
    o = val
    if res_flag:
      
      ores = out
      mdnum8_acosh_to( &o.num, &ores.num)

    else:

      cores = mdnum8_acosh( &o.num)
      res   = mdnum8.create(&cores)

    # end if 
  elif tval is mdnumfe8:
    f = val
    if res_flag:
      
      fres = out
      femdnum8_acosh_to( &f.num, &fres.num)

    else:

      cfres = femdnum8_acosh( &f.num)
      res   = mdnumfe8.create(&cfres)

    # end if  
  elif tval is mdmatfe8:    
    F = val
    if res_flag:

      Fres = out
      femdarr8_acosh_to( &F.arr, &Fres.arr)

    else:

      cFres = femdarr8_acosh( &F.arr)
      res   = mdmatfe8.create(&cFres)

    # end if 
  elif tval is mdmat8:
    O = val
    if res_flag:
      
      Ores = out
      mdarr8_acosh_to( &O.arr, &Ores.arr)

    else:

      cOres = mdarr8_acosh( &O.arr)
      res   = mdmat8.create(&cOres)

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

      -  mdmat8
      -  mdmatfe8
      -  darr
      -  mdnum8
      -  mdnumfe8
      -  real
  """
  #***************************************************************************************************

  cdef mdmat8      O, Ores
  cdef dmat       R, Rres
  cdef mdmatfe8    F, Fres
  cdef mdnum8    o, ores
  cdef coeff_t    r, rres
  cdef mdnumfe8     f, fres
  cdef coeff_t   crres
  cdef mdnum8_t cores
  cdef femdnum8_t  cfres
  cdef darr_t    cRres
  cdef mdarr8_t   cOres
  cdef femdarr8_t cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if   tval is mdnum8:
    o = val
    if res_flag:
      
      ores = out
      mdnum8_asinh_to( &o.num, &ores.num)

    else:

      cores = mdnum8_asinh( &o.num)
      res   = mdnum8.create(&cores)

    # end if 
  elif tval is mdnumfe8:
    f = val
    if res_flag:
      
      fres = out
      femdnum8_asinh_to( &f.num, &fres.num)

    else:

      cfres = femdnum8_asinh( &f.num)
      res   = mdnumfe8.create(&cfres)

    # end if  
  elif tval is mdmatfe8:    
    F = val
    if res_flag:

      Fres = out
      femdarr8_asinh_to( &F.arr, &Fres.arr)

    else:

      cFres = femdarr8_asinh( &F.arr)
      res   = mdmatfe8.create(&cFres)

    # end if 
  elif tval is mdmat8:
    O = val
    if res_flag:
      
      Ores = out
      mdarr8_asinh_to( &O.arr, &Ores.arr)

    else:

      cOres = mdarr8_asinh( &O.arr)
      res   = mdmat8.create(&cOres)

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

      -  mdmat8
      -  mdmatfe8
      -  darr
      -  mdnum8
      -  mdnumfe8
      -  real
  """
  #***************************************************************************************************

  cdef mdmat8      O, Ores
  cdef dmat       R, Rres
  cdef mdmatfe8    F, Fres
  cdef mdnum8    o, ores
  cdef coeff_t    r, rres
  cdef mdnumfe8     f, fres
  cdef coeff_t   crres
  cdef mdnum8_t cores
  cdef femdnum8_t  cfres
  cdef darr_t    cRres
  cdef mdarr8_t   cOres
  cdef femdarr8_t cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if   tval is mdnum8:
    o = val
    if res_flag:
      
      ores = out
      mdnum8_atanh_to( &o.num, &ores.num)

    else:

      cores = mdnum8_atanh( &o.num)
      res   = mdnum8.create(&cores)

    # end if 
  elif tval is mdnumfe8:
    f = val
    if res_flag:
      
      fres = out
      femdnum8_atanh_to( &f.num, &fres.num)

    else:

      cfres = femdnum8_atanh( &f.num)
      res   = mdnumfe8.create(&cfres)

    # end if  
  elif tval is mdmatfe8:    
    F = val
    if res_flag:

      Fres = out
      femdarr8_atanh_to( &F.arr, &Fres.arr)

    else:

      cFres = femdarr8_atanh( &F.arr)
      res   = mdmatfe8.create(&cFres)

    # end if 
  elif tval is mdmat8:
    O = val
    if res_flag:
      
      Ores = out
      mdarr8_atanh_to( &O.arr, &Ores.arr)

    else:

      cOres = mdarr8_atanh( &O.arr)
      res   = mdmat8.create(&cOres)

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

      -  mdmat8
      -  mdmatfe8
      -  darr
      -  mdnum8
      -  mdnumfe8
      -  real
  """
  #***************************************************************************************************

  cdef mdmat8      O, Ores
  cdef dmat       R, Rres
  cdef mdmatfe8    F, Fres
  cdef mdnum8    o, ores
  cdef coeff_t    r, rres
  cdef mdnumfe8     f, fres
  cdef coeff_t   crres
  cdef mdnum8_t cores
  cdef femdnum8_t  cfres
  cdef darr_t    cRres
  cdef mdarr8_t   cOres
  cdef femdarr8_t cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if   tval is mdnum8:
    o = val
    if res_flag:
      
      ores = out
      mdnum8_exp_to( &o.num, &ores.num)

    else:

      cores = mdnum8_exp( &o.num)
      res   = mdnum8.create(&cores)

    # end if 
  elif tval is mdnumfe8:
    f = val
    if res_flag:
      
      fres = out
      femdnum8_exp_to( &f.num, &fres.num)

    else:

      cfres = femdnum8_exp( &f.num)
      res   = mdnumfe8.create(&cfres)

    # end if  
  elif tval is mdmatfe8:    
    F = val
    if res_flag:

      Fres = out
      femdarr8_exp_to( &F.arr, &Fres.arr)

    else:

      cFres = femdarr8_exp( &F.arr)
      res   = mdmatfe8.create(&cFres)

    # end if 
  elif tval is mdmat8:
    O = val
    if res_flag:
      
      Ores = out
      mdarr8_exp_to( &O.arr, &Ores.arr)

    else:

      cOres = mdarr8_exp( &O.arr)
      res   = mdmat8.create(&cOres)

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

      -  mdmat8
      -  mdmatfe8
      -  darr
      -  mdnum8
      -  mdnumfe8
      -  real

  INPUTS:

    - val: Value to evaluate. Must be a supported one of the supported types.
    - out: (optional) Holder of result, in order to avoid memory allocation.

  OUTPUTS:

    If out is not defined, then the result is a newlly allocated member containing the result.
  """
  #***************************************************************************************************

  cdef mdmat8      O, Ores
  cdef dmat       R, Rres
  cdef mdmatfe8    F, Fres
  cdef mdnum8    o, ores
  cdef coeff_t    r, rres
  cdef mdnumfe8     f, fres
  cdef coeff_t   crres
  cdef mdnum8_t cores
  cdef femdnum8_t  cfres
  cdef darr_t    cRres
  cdef mdarr8_t   cOres
  cdef femdarr8_t cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if   tval is mdnum8:
    o = val
    if res_flag:
      
      ores = out
      mdnum8_log_to( &o.num, &ores.num)

    else:

      cores = mdnum8_log( &o.num)
      res   = mdnum8.create(&cores)

    # end if 
  elif tval is mdnumfe8:
    f = val
    if res_flag:
      
      fres = out
      femdnum8_log_to( &f.num, &fres.num)

    else:

      cfres = femdnum8_log( &f.num)
      res   = mdnumfe8.create(&cfres)

    # end if  
  elif tval is mdmatfe8:    
    F = val
    if res_flag:

      Fres = out
      femdarr8_log_to( &F.arr, &Fres.arr)

    else:

      cFres = femdarr8_log( &F.arr)
      res   = mdmatfe8.create(&cFres)

    # end if 
  elif tval is mdmat8:
    O = val
    if res_flag:
      
      Ores = out
      mdarr8_log_to( &O.arr, &Ores.arr)

    else:

      cOres = mdarr8_log( &O.arr)
      res   = mdmat8.create(&cOres)

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

      -  mdmat8
      -  mdmatfe8
      -  darr
      -  mdnum8
      -  mdnumfe8
      -  real

  INPUTS:

    - val: Value to evaluate. Must be a supported one of the supported types.
    - out: (optional) Holder of result, in order to avoid memory allocation.

  OUTPUTS:

    If out is not defined, then the result is a newlly allocated member containing the result.
  """
  #***************************************************************************************************

  cdef mdmat8      O, Ores
  cdef dmat       R, Rres
  cdef mdmatfe8    F, Fres
  cdef mdnum8    o, ores
  cdef coeff_t    r, rres
  cdef mdnumfe8     f, fres
  cdef coeff_t   crres
  cdef mdnum8_t cores
  cdef femdnum8_t  cfres
  cdef darr_t    cRres
  cdef mdarr8_t   cOres
  cdef femdarr8_t cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if   tval is mdnum8:
    o = val
    if res_flag:
      
      ores = out
      mdnum8_log10_to( &o.num, &ores.num)

    else:

      cores = mdnum8_log10( &o.num)
      res   = mdnum8.create(&cores)

    # end if 
  elif tval is mdnumfe8:
    f = val
    if res_flag:
      
      fres = out
      femdnum8_log10_to( &f.num, &fres.num)

    else:

      cfres = femdnum8_log10( &f.num)
      res   = mdnumfe8.create(&cfres)

    # end if  
  elif tval is mdmatfe8:    
    F = val
    if res_flag:

      Fres = out
      femdarr8_log10_to( &F.arr, &Fres.arr)

    else:

      cFres = femdarr8_log10( &F.arr)
      res   = mdmatfe8.create(&cFres)

    # end if 
  elif tval is mdmat8:
    O = val
    if res_flag:
      
      Ores = out
      mdarr8_log10_to( &O.arr, &Ores.arr)

    else:

      cOres = mdarr8_log10( &O.arr)
      res   = mdmat8.create(&cOres)

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

      -  mdmat8
      -  mdmatfe8
      -  darr
      -  mdnum8
      -  mdnumfe8
      -  real

  INPUTS:

    - val: Value to evaluate. Must be a supported one of the supported types.
    - b:   Base.
    - out: (optional) Holder of result, in order to avoid memory allocation.

  OUTPUTS:

    If out is not defined, then the result is a newlly allocated member containing the result.
  """
  #***************************************************************************************************

  cdef mdmat8      O, Ores
  cdef dmat       R, Rres
  cdef mdmatfe8    F, Fres
  cdef mdnum8    o, ores
  cdef coeff_t    r, rres
  cdef mdnumfe8     f, fres
  cdef coeff_t   crres
  cdef mdnum8_t cores
  cdef femdnum8_t  cfres
  cdef darr_t    cRres
  cdef mdarr8_t   cOres
  cdef femdarr8_t cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if   tval is mdnum8:
    o = val
    if res_flag:
      
      ores = out
      mdnum8_logb_to( &o.num, b, &ores.num)

    else:

      cores = mdnum8_logb( &o.num, b)
      res   = mdnum8.create(&cores)

    # end if 
  elif tval is mdnumfe8:
    f = val
    if res_flag:
      
      fres = out
      femdnum8_logb_to( &f.num, b, &fres.num)

    else:

      cfres = femdnum8_logb( &f.num, b)
      res   = mdnumfe8.create(&cfres)

    # end if  
  elif tval is mdmatfe8:    
    F = val
    if res_flag:

      Fres = out
      femdarr8_logb_to( &F.arr, b, &Fres.arr)

    else:

      cFres = femdarr8_logb( &F.arr, b)
      res   = mdmatfe8.create(&cFres)

    # end if 
  elif tval is mdmat8:
    O = val
    if res_flag:
      
      Ores = out
      mdarr8_logb_to( &O.arr, b, &Ores.arr)

    else:

      cOres = mdarr8_logb( &O.arr, b)
      res   = mdmat8.create(&cOres)

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

      -  mdmat8
      -  mdmatfe8
      -  darr
      -  mdnum8
      -  mdnumfe8
      -  real

  INPUTS:

    - val: Value to evaluate. Must be a supported one of the supported types.
    - out: (optional) Holder of result, in order to avoid memory allocation.

  OUTPUTS:

    If out is not defined, then the result is a newlly allocated member containing the result.
  """
  #***************************************************************************************************

  cdef mdmat8      O, Ores
  cdef dmat       R, Rres
  cdef mdmatfe8    F, Fres
  cdef mdnum8    o, ores
  cdef coeff_t    r, rres
  cdef mdnumfe8     f, fres
  cdef coeff_t   crres
  cdef mdnum8_t cores
  cdef femdnum8_t  cfres
  cdef darr_t    cRres
  cdef mdarr8_t   cOres
  cdef femdarr8_t cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if   tval is mdnum8:
    o = val
    if res_flag:
      
      ores = out
      mdnum8_sqrt_to( &o.num, &ores.num)

    else:

      cores = mdnum8_sqrt( &o.num)
      res   = mdnum8.create(&cores)

    # end if 
  elif tval is mdnumfe8:
    f = val
    if res_flag:
      
      fres = out
      femdnum8_sqrt_to( &f.num, &fres.num)

    else:

      cfres = femdnum8_sqrt( &f.num)
      res   = mdnumfe8.create(&cfres)

    # end if  
  elif tval is mdmatfe8:    
    F = val
    if res_flag:

      Fres = out
      femdarr8_sqrt_to( &F.arr, &Fres.arr)

    else:

      cFres = femdarr8_sqrt( &F.arr)
      res   = mdmatfe8.create(&cFres)

    # end if 
  elif tval is mdmat8:
    O = val
    if res_flag:
      
      Ores = out
      mdarr8_sqrt_to( &O.arr, &Ores.arr)

    else:

      cOres = mdarr8_sqrt( &O.arr)
      res   = mdmat8.create(&cOres)

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

      -  mdmat8
      -  mdmatfe8
      -  darr
      -  mdnum8
      -  mdnumfe8
      -  real

  INPUTS:

    - val: Value to evaluate. Must be a supported one of the supported types.
    - out: (optional) Holder of result, in order to avoid memory allocation.

  OUTPUTS:

    If out is not defined, then the result is a newlly allocated member containing the result.
  """
  #***************************************************************************************************

  cdef mdmat8      O, Ores
  cdef dmat       R, Rres
  cdef mdmatfe8    F, Fres
  cdef mdnum8    o, ores
  cdef coeff_t    r, rres
  cdef mdnumfe8     f, fres
  cdef coeff_t   crres
  cdef mdnum8_t cores
  cdef femdnum8_t  cfres
  cdef darr_t    cRres
  cdef mdarr8_t   cOres
  cdef femdarr8_t cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if   tval is mdnum8:
    o = val
    if res_flag:
      
      ores = out
      mdnum8_cbrt_to( &o.num, &ores.num)

    else:

      cores = mdnum8_cbrt( &o.num)
      res   = mdnum8.create(&cores)

    # end if 
  elif tval is mdnumfe8:
    f = val
    if res_flag:
      
      fres = out
      femdnum8_cbrt_to( &f.num, &fres.num)

    else:

      cfres = femdnum8_cbrt( &f.num)
      res   = mdnumfe8.create(&cfres)

    # end if  
  elif tval is mdmatfe8:    
    F = val
    if res_flag:

      Fres = out
      femdarr8_cbrt_to( &F.arr, &Fres.arr)

    else:

      cFres = femdarr8_cbrt( &F.arr)
      res   = mdmatfe8.create(&cFres)

    # end if 
  elif tval is mdmat8:
    O = val
    if res_flag:
      
      Ores = out
      mdarr8_cbrt_to( &O.arr, &Ores.arr)

    else:

      cOres = mdarr8_cbrt( &O.arr)
      res   = mdmat8.create(&cOres)

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

      -  mdmat8
      -  mdmatfe8
      -  darr
      -  mdnum8
      -  mdnumfe8
      -  real

  INPUTS:

    - val: Value to evaluate. Must be a supported one of the supported types.
    - e:   exponent.
    - out: (optional) Holder of result, in order to avoid memory allocation.

  OUTPUTS:

    If out is not defined, then the result is a newlly allocated member containing the result.
  """
  #***************************************************************************************************

  cdef mdmat8      O, Ores
  cdef dmat       R, Rres
  cdef mdmatfe8    F, Fres
  cdef mdnum8    o, ores
  cdef coeff_t    r, rres
  cdef mdnumfe8     f, fres
  cdef coeff_t   crres
  cdef mdnum8_t cores
  cdef femdnum8_t  cfres
  cdef darr_t    cRres
  cdef mdarr8_t   cOres
  cdef femdarr8_t cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if   tval is mdnum8:
    o = val
    if res_flag:
      
      ores = out
      mdnum8_pow_to( &o.num, e, &ores.num)

    else:

      cores = mdnum8_pow( &o.num, e)
      res   = mdnum8.create(&cores)

    # end if 
  elif tval is mdnumfe8:
    f = val
    if res_flag:
      
      fres = out
      femdnum8_pow_to( &f.num, e, &fres.num)

    else:

      cfres = femdnum8_pow( &f.num, e)
      res   = mdnumfe8.create(&cfres)

    # end if  
  elif tval is mdmatfe8:    
    F = val
    if res_flag:

      Fres = out
      femdarr8_pow_to( &F.arr, e, &Fres.arr)

    else:

      cFres = femdarr8_pow( &F.arr, e)
      res   = mdmatfe8.create(&cFres)

    # end if 
  elif tval is mdmat8:
    O = val
    if res_flag:
      
      Ores = out
      mdarr8_pow_to( &O.arr, e, &Ores.arr)

    else:

      cOres = mdarr8_pow( &O.arr, e)
      res   = mdmat8.create(&cOres)

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
cpdef gauss_integrate(object val, mdnumfe8 w, object out = None ):
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
  

  cdef mdmat8      O, Ores
  cdef dmat       R, Rres
  cdef mdmatfe8    F, Fres
  cdef mdnum8    o, ores
  cdef coeff_t    r, rres
  cdef mdnumfe8     f, fres
  cdef coeff_t   crres
  cdef mdnum8_t cores
  cdef femdnum8_t  cfres
  cdef darr_t    cRres
  cdef mdarr8_t   cOres
  cdef femdarr8_t cFres 
  cdef uint8_t res_flag = 1
  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if

  if   tval is mdnumfe8:
    f = val
    if res_flag:
      
      ores = out
      femdnum8_integrate_f_to( &f.num, &w.num, &ores.num)

    else:

      cores = femdnum8_integrate_f( &f.num, &w.num)
      res   = mdnum8.create(&cores)

    # end if  
  elif tval is mdmatfe8:
    F = val
    if res_flag:

      Ores = out
      femdarr8_integrate_to( &F.arr, &w.num, &Ores.arr)

    else:

      cOres = femdarr8_integrate( &F.arr, &w.num)
      res   = mdmat8.create(&cOres)

    # end if 
  elif tval is mdnum8:
    o = val
    if res_flag:
      
      ores = out
      femdnum8_integrate_o_to( &o.num, &w.num, &ores.num)

    else:

      cores = femdnum8_integrate_o( &o.num, &w.num)
      res   = mdnum8.create(&cores)

    # end if
  else:
    try:
      r = val
      if res_flag:
        
        ores = out
        femdnum8_integrate_r_to( r, &w.num, &ores.num)

      else:

        cores = femdnum8_integrate_r( r, &w.num)
        res   = mdnum8.create(&cores)

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

      -  mdmat8
      -  mdmatfe8
      -  darr
      -  mdnum8
      -  mdnumfe8
      -  real
  """
  #***************************************************************************************************

  cdef mdmat8      O, Ores
  cdef dmat       R, Rres
  cdef mdmatfe8    F, Fres
  cdef mdnum8    o, ores
  cdef coeff_t    r, rres
  cdef mdnumfe8     f, fres
  cdef coeff_t   crres
  cdef mdnum8_t cores
  cdef femdnum8_t  cfres
  cdef darr_t    cRres
  cdef mdarr8_t   cOres
  cdef femdarr8_t cFres
  cdef uint8_t res_flag = 1
  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 
  #
  if   tval is mdnum8:
    o = val
    if res_flag:
      
      ores = out
      mdnum8_neg_to( &o.num, &ores.num)

    else:

      cores = mdnum8_neg( &o.num)
      res   = mdnum8.create(&cores)

    # end if 
  elif tval is mdnumfe8:
    f = val
    if res_flag:
      
      fres = out
      femdnum8_neg_to( &f.num, &fres.num)

    else:

      cfres = femdnum8_neg( &f.num)
      res   = mdnumfe8.create(&cfres)

    # end if         
  elif tval is mdmatfe8:    
    F = val
    if res_flag:

      Fres = out
      femdarr8_neg_to( &F.arr, &Fres.arr)

    else:

      cFres = femdarr8_neg( &F.arr)
      res   = mdmatfe8.create(&cFres)

    # end if 
  elif tval is mdmat8:
    O = val
    if res_flag:
      
      Ores = out
      mdarr8_neg_to( &O.arr, &Ores.arr)

    else:

      cOres = mdarr8_neg( &O.arr)
      res   = mdmat8.create(&cOres)

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
