#*****************************************************************************************************
cpdef cos(object val, object out = None):
  """
  PURPOSE:  Matrix determinant.
  
  Supported types:

      -  mdmat5
      -  mdmatfe5
      -  darr
      -  mdnum5
      -  mdnumfe5
      -  real
  """
  #***************************************************************************************************

  cdef mdmat5      O, Ores
  cdef dmat       R, Rres
  cdef mdmatfe5    F, Fres
  cdef mdnum5    o, ores
  cdef coeff_t    r, rres
  cdef mdnumfe5     f, fres
  cdef coeff_t   crres
  cdef mdnum5_t cores
  cdef femdnum5_t  cfres
  cdef darr_t    cRres
  cdef mdarr5_t   cOres
  cdef femdarr5_t cFres
  cdef uint8_t res_flag = 1
  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 
  #
  if   tval is mdnum5:
    o = val
    if res_flag:
      
      ores = out
      mdnum5_cos_to( &o.num, &ores.num)

    else:

      cores = mdnum5_cos( &o.num)
      res   = mdnum5.create(&cores)

    # end if 
  elif tval is mdnumfe5:
    f = val
    if res_flag:
      
      fres = out
      femdnum5_cos_to( &f.num, &fres.num)

    else:

      cfres = femdnum5_cos( &f.num)
      res   = mdnumfe5.create(&cfres)

    # end if         
  elif tval is mdmatfe5:    
    F = val
    if res_flag:

      Fres = out
      femdarr5_cos_to( &F.arr, &Fres.arr)

    else:

      cFres = femdarr5_cos( &F.arr)
      res   = mdmatfe5.create(&cFres)

    # end if 
  elif tval is mdmat5:
    O = val
    if res_flag:
      
      Ores = out
      mdarr5_cos_to( &O.arr, &Ores.arr)

    else:

      cOres = mdarr5_cos( &O.arr)
      res   = mdmat5.create(&cOres)

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

      -  mdmat5
      -  mdmatfe5
      -  darr
      -  mdnum5
      -  mdnumfe5
      -  real
  """
  #***************************************************************************************************

  cdef mdmat5      O, Ores
  cdef dmat       R, Rres
  cdef mdmatfe5    F, Fres
  cdef mdnum5    o, ores
  cdef coeff_t    r, rres
  cdef mdnumfe5     f, fres
  cdef coeff_t   crres
  cdef mdnum5_t cores
  cdef femdnum5_t  cfres
  cdef darr_t    cRres
  cdef mdarr5_t   cOres
  cdef femdarr5_t cFres
  cdef uint8_t res_flag = 1
  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if   tval is mdnum5:
    o = val
    if res_flag:
      
      ores = out
      mdnum5_sin_to( &o.num, &ores.num)

    else:

      cores = mdnum5_sin( &o.num)
      res   = mdnum5.create(&cores)

    # end if 
  elif tval is mdnumfe5:
    f = val
    if res_flag:
      
      fres = out
      femdnum5_sin_to( &f.num, &fres.num)

    else:

      cfres = femdnum5_sin( &f.num)
      res   = mdnumfe5.create(&cfres)

    # end if  
  elif tval is mdmatfe5:    
    F = val
    if res_flag:

      Fres = out
      femdarr5_sin_to( &F.arr, &Fres.arr)

    else:

      cFres = femdarr5_sin( &F.arr)
      res   = mdmatfe5.create(&cFres)

    # end if 
  elif tval is mdmat5:
    O = val
    if res_flag:
      
      Ores = out
      mdarr5_sin_to( &O.arr, &Ores.arr)

    else:

      cOres = mdarr5_sin( &O.arr)
      res   = mdmat5.create(&cOres)

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

      -  mdmat5
      -  mdmatfe5
      -  darr
      -  mdnum5
      -  mdnumfe5
      -  real
  """
  #***************************************************************************************************

  cdef mdmat5      O, Ores
  cdef dmat       R, Rres
  cdef mdmatfe5    F, Fres
  cdef mdnum5    o, ores
  cdef coeff_t    r, rres
  cdef mdnumfe5     f, fres
  cdef coeff_t   crres
  cdef mdnum5_t cores
  cdef femdnum5_t  cfres
  cdef darr_t    cRres
  cdef mdarr5_t   cOres
  cdef femdarr5_t cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if   tval is mdnum5:
    o = val
    if res_flag:
      
      ores = out
      mdnum5_tan_to( &o.num, &ores.num)

    else:

      cores = mdnum5_tan( &o.num)
      res   = mdnum5.create(&cores)

    # end if 
  elif tval is mdnumfe5:
    f = val
    if res_flag:
      
      fres = out
      femdnum5_tan_to( &f.num, &fres.num)

    else:

      cfres = femdnum5_tan( &f.num)
      res   = mdnumfe5.create(&cfres)

    # end if  
  elif tval is mdmatfe5:    
    F = val
    if res_flag:

      Fres = out
      femdarr5_tan_to( &F.arr, &Fres.arr)

    else:

      cFres = femdarr5_tan( &F.arr)
      res   = mdmatfe5.create(&cFres)

    # end if 
  elif tval is mdmat5:
    O = val
    if res_flag:
      
      Ores = out
      mdarr5_tan_to( &O.arr, &Ores.arr)

    else:

      cOres = mdarr5_tan( &O.arr)
      res   = mdmat5.create(&cOres)

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

      -  mdmat5
      -  mdmatfe5
      -  darr
      -  mdnum5
      -  mdnumfe5
      -  real
  """
  #***************************************************************************************************

  cdef mdmat5      O, Ores
  cdef dmat       R, Rres
  cdef mdmatfe5    F, Fres
  cdef mdnum5    o, ores
  cdef coeff_t    r, rres
  cdef mdnumfe5     f, fres
  cdef coeff_t   crres
  cdef mdnum5_t cores
  cdef femdnum5_t  cfres
  cdef darr_t    cRres
  cdef mdarr5_t   cOres
  cdef femdarr5_t cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if   tval is mdnum5:
    o = val
    if res_flag:
      
      ores = out
      mdnum5_acos_to( &o.num, &ores.num)

    else:

      cores = mdnum5_acos( &o.num)
      res   = mdnum5.create(&cores)

    # end if 
  elif tval is mdnumfe5:
    f = val
    if res_flag:
      
      fres = out
      femdnum5_acos_to( &f.num, &fres.num)

    else:

      cfres = femdnum5_acos( &f.num)
      res   = mdnumfe5.create(&cfres)

    # end if  
  elif tval is mdmatfe5:    
    F = val
    if res_flag:

      Fres = out
      femdarr5_acos_to( &F.arr, &Fres.arr)

    else:

      cFres = femdarr5_acos( &F.arr)
      res   = mdmatfe5.create(&cFres)

    # end if 
  elif tval is mdmat5:
    O = val
    if res_flag:
      
      Ores = out
      mdarr5_acos_to( &O.arr, &Ores.arr)

    else:

      cOres = mdarr5_acos( &O.arr)
      res   = mdmat5.create(&cOres)

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

      -  mdmat5
      -  mdmatfe5
      -  darr
      -  mdnum5
      -  mdnumfe5
      -  real
  """
  #***************************************************************************************************

  cdef mdmat5      O, Ores
  cdef dmat       R, Rres
  cdef mdmatfe5    F, Fres
  cdef mdnum5    o, ores
  cdef coeff_t    r, rres
  cdef mdnumfe5     f, fres
  cdef coeff_t   crres
  cdef mdnum5_t cores
  cdef femdnum5_t  cfres
  cdef darr_t    cRres
  cdef mdarr5_t   cOres
  cdef femdarr5_t cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if   tval is mdnum5:
    o = val
    if res_flag:
      
      ores = out
      mdnum5_asin_to( &o.num, &ores.num)

    else:

      cores = mdnum5_asin( &o.num)
      res   = mdnum5.create(&cores)

    # end if 
  elif tval is mdnumfe5:
    f = val
    if res_flag:
      
      fres = out
      femdnum5_asin_to( &f.num, &fres.num)

    else:

      cfres = femdnum5_asin( &f.num)
      res   = mdnumfe5.create(&cfres)

    # end if  
  elif tval is mdmatfe5:    
    F = val
    if res_flag:

      Fres = out
      femdarr5_asin_to( &F.arr, &Fres.arr)

    else:

      cFres = femdarr5_asin( &F.arr)
      res   = mdmatfe5.create(&cFres)

    # end if 
  elif tval is mdmat5:
    O = val
    if res_flag:
      
      Ores = out
      mdarr5_asin_to( &O.arr, &Ores.arr)

    else:

      cOres = mdarr5_asin( &O.arr)
      res   = mdmat5.create(&cOres)

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

      -  mdmat5
      -  mdmatfe5
      -  darr
      -  mdnum5
      -  mdnumfe5
      -  real
  """
  #***************************************************************************************************

  cdef mdmat5      O, Ores
  cdef dmat       R, Rres
  cdef mdmatfe5    F, Fres
  cdef mdnum5    o, ores
  cdef coeff_t    r, rres
  cdef mdnumfe5     f, fres
  cdef coeff_t   crres
  cdef mdnum5_t cores
  cdef femdnum5_t  cfres
  cdef darr_t    cRres
  cdef mdarr5_t   cOres
  cdef femdarr5_t cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if   tval is mdnum5:
    o = val
    if res_flag:
      
      ores = out
      mdnum5_atan_to( &o.num, &ores.num)

    else:

      cores = mdnum5_atan( &o.num)
      res   = mdnum5.create(&cores)

    # end if 
  elif tval is mdnumfe5:
    f = val
    if res_flag:
      
      fres = out
      femdnum5_atan_to( &f.num, &fres.num)

    else:

      cfres = femdnum5_atan( &f.num)
      res   = mdnumfe5.create(&cfres)

    # end if  
  elif tval is mdmatfe5:    
    F = val
    if res_flag:

      Fres = out
      femdarr5_atan_to( &F.arr, &Fres.arr)

    else:

      cFres = femdarr5_atan( &F.arr)
      res   = mdmatfe5.create(&cFres)

    # end if 
  elif tval is mdmat5:
    O = val
    if res_flag:
      
      Ores = out
      mdarr5_atan_to( &O.arr, &Ores.arr)

    else:

      cOres = mdarr5_atan( &O.arr)
      res   = mdmat5.create(&cOres)

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

      -  mdmat5
      -  mdmatfe5
      -  darr
      -  mdnum5
      -  mdnumfe5
      -  real
  """
  #***************************************************************************************************

  cdef mdmat5      O, Ores
  cdef dmat       R, Rres
  cdef mdmatfe5    F, Fres
  cdef mdnum5    o, ores
  cdef coeff_t    r, rres
  cdef mdnumfe5     f, fres
  cdef coeff_t   crres
  cdef mdnum5_t cores
  cdef femdnum5_t  cfres
  cdef darr_t    cRres
  cdef mdarr5_t   cOres
  cdef femdarr5_t cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if   tval is mdnum5:
    o = val
    if res_flag:
      
      ores = out
      mdnum5_sinh_to( &o.num, &ores.num)

    else:

      cores = mdnum5_sinh( &o.num)
      res   = mdnum5.create(&cores)

    # end if 
  elif tval is mdnumfe5:
    f = val
    if res_flag:
      
      fres = out
      femdnum5_sinh_to( &f.num, &fres.num)

    else:

      cfres = femdnum5_sinh( &f.num)
      res   = mdnumfe5.create(&cfres)

    # end if  
  elif tval is mdmatfe5:    
    F = val
    if res_flag:

      Fres = out
      femdarr5_sinh_to( &F.arr, &Fres.arr)

    else:

      cFres = femdarr5_sinh( &F.arr)
      res   = mdmatfe5.create(&cFres)

    # end if 
  elif tval is mdmat5:
    O = val
    if res_flag:
      
      Ores = out
      mdarr5_sinh_to( &O.arr, &Ores.arr)

    else:

      cOres = mdarr5_sinh( &O.arr)
      res   = mdmat5.create(&cOres)

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

      -  mdmat5
      -  mdmatfe5
      -  darr
      -  mdnum5
      -  mdnumfe5
      -  real
  """
  #***************************************************************************************************

  cdef mdmat5      O, Ores
  cdef dmat       R, Rres
  cdef mdmatfe5    F, Fres
  cdef mdnum5    o, ores
  cdef coeff_t    r, rres
  cdef mdnumfe5     f, fres
  cdef coeff_t   crres
  cdef mdnum5_t cores
  cdef femdnum5_t  cfres
  cdef darr_t    cRres
  cdef mdarr5_t   cOres
  cdef femdarr5_t cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if   tval is mdnum5:
    o = val
    if res_flag:
      
      ores = out
      mdnum5_cosh_to( &o.num, &ores.num)

    else:

      cores = mdnum5_cosh( &o.num)
      res   = mdnum5.create(&cores)

    # end if 
  elif tval is mdnumfe5:
    f = val
    if res_flag:
      
      fres = out
      femdnum5_cosh_to( &f.num, &fres.num)

    else:

      cfres = femdnum5_cosh( &f.num)
      res   = mdnumfe5.create(&cfres)

    # end if  
  elif tval is mdmatfe5:    
    F = val
    if res_flag:

      Fres = out
      femdarr5_cosh_to( &F.arr, &Fres.arr)

    else:

      cFres = femdarr5_cosh( &F.arr)
      res   = mdmatfe5.create(&cFres)

    # end if 
  elif tval is mdmat5:
    O = val
    if res_flag:
      
      Ores = out
      mdarr5_cosh_to( &O.arr, &Ores.arr)

    else:

      cOres = mdarr5_cosh( &O.arr)
      res   = mdmat5.create(&cOres)

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

      -  mdmat5
      -  mdmatfe5
      -  darr
      -  mdnum5
      -  mdnumfe5
      -  real
  """
  #***************************************************************************************************

  cdef mdmat5      O, Ores
  cdef dmat       R, Rres
  cdef mdmatfe5    F, Fres
  cdef mdnum5    o, ores
  cdef coeff_t    r, rres
  cdef mdnumfe5     f, fres
  cdef coeff_t   crres
  cdef mdnum5_t cores
  cdef femdnum5_t  cfres
  cdef darr_t    cRres
  cdef mdarr5_t   cOres
  cdef femdarr5_t cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if   tval is mdnum5:
    o = val
    if res_flag:
      
      ores = out
      mdnum5_tanh_to( &o.num, &ores.num)

    else:

      cores = mdnum5_tanh( &o.num)
      res   = mdnum5.create(&cores)

    # end if 
  elif tval is mdnumfe5:
    f = val
    if res_flag:
      
      fres = out
      femdnum5_tanh_to( &f.num, &fres.num)

    else:

      cfres = femdnum5_tanh( &f.num)
      res   = mdnumfe5.create(&cfres)

    # end if  
  elif tval is mdmatfe5:    
    F = val
    if res_flag:

      Fres = out
      femdarr5_tanh_to( &F.arr, &Fres.arr)

    else:

      cFres = femdarr5_tanh( &F.arr)
      res   = mdmatfe5.create(&cFres)

    # end if 
  elif tval is mdmat5:
    O = val
    if res_flag:
      
      Ores = out
      mdarr5_tanh_to( &O.arr, &Ores.arr)

    else:

      cOres = mdarr5_tanh( &O.arr)
      res   = mdmat5.create(&cOres)

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

      -  mdmat5
      -  mdmatfe5
      -  darr
      -  mdnum5
      -  mdnumfe5
      -  real
  """
  #***************************************************************************************************

  cdef mdmat5      O, Ores
  cdef dmat       R, Rres
  cdef mdmatfe5    F, Fres
  cdef mdnum5    o, ores
  cdef coeff_t    r, rres
  cdef mdnumfe5     f, fres
  cdef coeff_t   crres
  cdef mdnum5_t cores
  cdef femdnum5_t  cfres
  cdef darr_t    cRres
  cdef mdarr5_t   cOres
  cdef femdarr5_t cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if   tval is mdnum5:
    o = val
    if res_flag:
      
      ores = out
      mdnum5_acosh_to( &o.num, &ores.num)

    else:

      cores = mdnum5_acosh( &o.num)
      res   = mdnum5.create(&cores)

    # end if 
  elif tval is mdnumfe5:
    f = val
    if res_flag:
      
      fres = out
      femdnum5_acosh_to( &f.num, &fres.num)

    else:

      cfres = femdnum5_acosh( &f.num)
      res   = mdnumfe5.create(&cfres)

    # end if  
  elif tval is mdmatfe5:    
    F = val
    if res_flag:

      Fres = out
      femdarr5_acosh_to( &F.arr, &Fres.arr)

    else:

      cFres = femdarr5_acosh( &F.arr)
      res   = mdmatfe5.create(&cFres)

    # end if 
  elif tval is mdmat5:
    O = val
    if res_flag:
      
      Ores = out
      mdarr5_acosh_to( &O.arr, &Ores.arr)

    else:

      cOres = mdarr5_acosh( &O.arr)
      res   = mdmat5.create(&cOres)

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

      -  mdmat5
      -  mdmatfe5
      -  darr
      -  mdnum5
      -  mdnumfe5
      -  real
  """
  #***************************************************************************************************

  cdef mdmat5      O, Ores
  cdef dmat       R, Rres
  cdef mdmatfe5    F, Fres
  cdef mdnum5    o, ores
  cdef coeff_t    r, rres
  cdef mdnumfe5     f, fres
  cdef coeff_t   crres
  cdef mdnum5_t cores
  cdef femdnum5_t  cfres
  cdef darr_t    cRres
  cdef mdarr5_t   cOres
  cdef femdarr5_t cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if   tval is mdnum5:
    o = val
    if res_flag:
      
      ores = out
      mdnum5_asinh_to( &o.num, &ores.num)

    else:

      cores = mdnum5_asinh( &o.num)
      res   = mdnum5.create(&cores)

    # end if 
  elif tval is mdnumfe5:
    f = val
    if res_flag:
      
      fres = out
      femdnum5_asinh_to( &f.num, &fres.num)

    else:

      cfres = femdnum5_asinh( &f.num)
      res   = mdnumfe5.create(&cfres)

    # end if  
  elif tval is mdmatfe5:    
    F = val
    if res_flag:

      Fres = out
      femdarr5_asinh_to( &F.arr, &Fres.arr)

    else:

      cFres = femdarr5_asinh( &F.arr)
      res   = mdmatfe5.create(&cFres)

    # end if 
  elif tval is mdmat5:
    O = val
    if res_flag:
      
      Ores = out
      mdarr5_asinh_to( &O.arr, &Ores.arr)

    else:

      cOres = mdarr5_asinh( &O.arr)
      res   = mdmat5.create(&cOres)

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

      -  mdmat5
      -  mdmatfe5
      -  darr
      -  mdnum5
      -  mdnumfe5
      -  real
  """
  #***************************************************************************************************

  cdef mdmat5      O, Ores
  cdef dmat       R, Rres
  cdef mdmatfe5    F, Fres
  cdef mdnum5    o, ores
  cdef coeff_t    r, rres
  cdef mdnumfe5     f, fres
  cdef coeff_t   crres
  cdef mdnum5_t cores
  cdef femdnum5_t  cfres
  cdef darr_t    cRres
  cdef mdarr5_t   cOres
  cdef femdarr5_t cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if   tval is mdnum5:
    o = val
    if res_flag:
      
      ores = out
      mdnum5_atanh_to( &o.num, &ores.num)

    else:

      cores = mdnum5_atanh( &o.num)
      res   = mdnum5.create(&cores)

    # end if 
  elif tval is mdnumfe5:
    f = val
    if res_flag:
      
      fres = out
      femdnum5_atanh_to( &f.num, &fres.num)

    else:

      cfres = femdnum5_atanh( &f.num)
      res   = mdnumfe5.create(&cfres)

    # end if  
  elif tval is mdmatfe5:    
    F = val
    if res_flag:

      Fres = out
      femdarr5_atanh_to( &F.arr, &Fres.arr)

    else:

      cFres = femdarr5_atanh( &F.arr)
      res   = mdmatfe5.create(&cFres)

    # end if 
  elif tval is mdmat5:
    O = val
    if res_flag:
      
      Ores = out
      mdarr5_atanh_to( &O.arr, &Ores.arr)

    else:

      cOres = mdarr5_atanh( &O.arr)
      res   = mdmat5.create(&cOres)

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

      -  mdmat5
      -  mdmatfe5
      -  darr
      -  mdnum5
      -  mdnumfe5
      -  real
  """
  #***************************************************************************************************

  cdef mdmat5      O, Ores
  cdef dmat       R, Rres
  cdef mdmatfe5    F, Fres
  cdef mdnum5    o, ores
  cdef coeff_t    r, rres
  cdef mdnumfe5     f, fres
  cdef coeff_t   crres
  cdef mdnum5_t cores
  cdef femdnum5_t  cfres
  cdef darr_t    cRres
  cdef mdarr5_t   cOres
  cdef femdarr5_t cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if   tval is mdnum5:
    o = val
    if res_flag:
      
      ores = out
      mdnum5_exp_to( &o.num, &ores.num)

    else:

      cores = mdnum5_exp( &o.num)
      res   = mdnum5.create(&cores)

    # end if 
  elif tval is mdnumfe5:
    f = val
    if res_flag:
      
      fres = out
      femdnum5_exp_to( &f.num, &fres.num)

    else:

      cfres = femdnum5_exp( &f.num)
      res   = mdnumfe5.create(&cfres)

    # end if  
  elif tval is mdmatfe5:    
    F = val
    if res_flag:

      Fres = out
      femdarr5_exp_to( &F.arr, &Fres.arr)

    else:

      cFres = femdarr5_exp( &F.arr)
      res   = mdmatfe5.create(&cFres)

    # end if 
  elif tval is mdmat5:
    O = val
    if res_flag:
      
      Ores = out
      mdarr5_exp_to( &O.arr, &Ores.arr)

    else:

      cOres = mdarr5_exp( &O.arr)
      res   = mdmat5.create(&cOres)

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

      -  mdmat5
      -  mdmatfe5
      -  darr
      -  mdnum5
      -  mdnumfe5
      -  real

  INPUTS:

    - val: Value to evaluate. Must be a supported one of the supported types.
    - out: (optional) Holder of result, in order to avoid memory allocation.

  OUTPUTS:

    If out is not defined, then the result is a newlly allocated member containing the result.
  """
  #***************************************************************************************************

  cdef mdmat5      O, Ores
  cdef dmat       R, Rres
  cdef mdmatfe5    F, Fres
  cdef mdnum5    o, ores
  cdef coeff_t    r, rres
  cdef mdnumfe5     f, fres
  cdef coeff_t   crres
  cdef mdnum5_t cores
  cdef femdnum5_t  cfres
  cdef darr_t    cRres
  cdef mdarr5_t   cOres
  cdef femdarr5_t cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if   tval is mdnum5:
    o = val
    if res_flag:
      
      ores = out
      mdnum5_log_to( &o.num, &ores.num)

    else:

      cores = mdnum5_log( &o.num)
      res   = mdnum5.create(&cores)

    # end if 
  elif tval is mdnumfe5:
    f = val
    if res_flag:
      
      fres = out
      femdnum5_log_to( &f.num, &fres.num)

    else:

      cfres = femdnum5_log( &f.num)
      res   = mdnumfe5.create(&cfres)

    # end if  
  elif tval is mdmatfe5:    
    F = val
    if res_flag:

      Fres = out
      femdarr5_log_to( &F.arr, &Fres.arr)

    else:

      cFres = femdarr5_log( &F.arr)
      res   = mdmatfe5.create(&cFres)

    # end if 
  elif tval is mdmat5:
    O = val
    if res_flag:
      
      Ores = out
      mdarr5_log_to( &O.arr, &Ores.arr)

    else:

      cOres = mdarr5_log( &O.arr)
      res   = mdmat5.create(&cOres)

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

      -  mdmat5
      -  mdmatfe5
      -  darr
      -  mdnum5
      -  mdnumfe5
      -  real

  INPUTS:

    - val: Value to evaluate. Must be a supported one of the supported types.
    - out: (optional) Holder of result, in order to avoid memory allocation.

  OUTPUTS:

    If out is not defined, then the result is a newlly allocated member containing the result.
  """
  #***************************************************************************************************

  cdef mdmat5      O, Ores
  cdef dmat       R, Rres
  cdef mdmatfe5    F, Fres
  cdef mdnum5    o, ores
  cdef coeff_t    r, rres
  cdef mdnumfe5     f, fres
  cdef coeff_t   crres
  cdef mdnum5_t cores
  cdef femdnum5_t  cfres
  cdef darr_t    cRres
  cdef mdarr5_t   cOres
  cdef femdarr5_t cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if   tval is mdnum5:
    o = val
    if res_flag:
      
      ores = out
      mdnum5_log10_to( &o.num, &ores.num)

    else:

      cores = mdnum5_log10( &o.num)
      res   = mdnum5.create(&cores)

    # end if 
  elif tval is mdnumfe5:
    f = val
    if res_flag:
      
      fres = out
      femdnum5_log10_to( &f.num, &fres.num)

    else:

      cfres = femdnum5_log10( &f.num)
      res   = mdnumfe5.create(&cfres)

    # end if  
  elif tval is mdmatfe5:    
    F = val
    if res_flag:

      Fres = out
      femdarr5_log10_to( &F.arr, &Fres.arr)

    else:

      cFres = femdarr5_log10( &F.arr)
      res   = mdmatfe5.create(&cFres)

    # end if 
  elif tval is mdmat5:
    O = val
    if res_flag:
      
      Ores = out
      mdarr5_log10_to( &O.arr, &Ores.arr)

    else:

      cOres = mdarr5_log10( &O.arr)
      res   = mdmat5.create(&cOres)

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

      -  mdmat5
      -  mdmatfe5
      -  darr
      -  mdnum5
      -  mdnumfe5
      -  real

  INPUTS:

    - val: Value to evaluate. Must be a supported one of the supported types.
    - b:   Base.
    - out: (optional) Holder of result, in order to avoid memory allocation.

  OUTPUTS:

    If out is not defined, then the result is a newlly allocated member containing the result.
  """
  #***************************************************************************************************

  cdef mdmat5      O, Ores
  cdef dmat       R, Rres
  cdef mdmatfe5    F, Fres
  cdef mdnum5    o, ores
  cdef coeff_t    r, rres
  cdef mdnumfe5     f, fres
  cdef coeff_t   crres
  cdef mdnum5_t cores
  cdef femdnum5_t  cfres
  cdef darr_t    cRres
  cdef mdarr5_t   cOres
  cdef femdarr5_t cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if   tval is mdnum5:
    o = val
    if res_flag:
      
      ores = out
      mdnum5_logb_to( &o.num, b, &ores.num)

    else:

      cores = mdnum5_logb( &o.num, b)
      res   = mdnum5.create(&cores)

    # end if 
  elif tval is mdnumfe5:
    f = val
    if res_flag:
      
      fres = out
      femdnum5_logb_to( &f.num, b, &fres.num)

    else:

      cfres = femdnum5_logb( &f.num, b)
      res   = mdnumfe5.create(&cfres)

    # end if  
  elif tval is mdmatfe5:    
    F = val
    if res_flag:

      Fres = out
      femdarr5_logb_to( &F.arr, b, &Fres.arr)

    else:

      cFres = femdarr5_logb( &F.arr, b)
      res   = mdmatfe5.create(&cFres)

    # end if 
  elif tval is mdmat5:
    O = val
    if res_flag:
      
      Ores = out
      mdarr5_logb_to( &O.arr, b, &Ores.arr)

    else:

      cOres = mdarr5_logb( &O.arr, b)
      res   = mdmat5.create(&cOres)

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

      -  mdmat5
      -  mdmatfe5
      -  darr
      -  mdnum5
      -  mdnumfe5
      -  real

  INPUTS:

    - val: Value to evaluate. Must be a supported one of the supported types.
    - out: (optional) Holder of result, in order to avoid memory allocation.

  OUTPUTS:

    If out is not defined, then the result is a newlly allocated member containing the result.
  """
  #***************************************************************************************************

  cdef mdmat5      O, Ores
  cdef dmat       R, Rres
  cdef mdmatfe5    F, Fres
  cdef mdnum5    o, ores
  cdef coeff_t    r, rres
  cdef mdnumfe5     f, fres
  cdef coeff_t   crres
  cdef mdnum5_t cores
  cdef femdnum5_t  cfres
  cdef darr_t    cRres
  cdef mdarr5_t   cOres
  cdef femdarr5_t cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if   tval is mdnum5:
    o = val
    if res_flag:
      
      ores = out
      mdnum5_sqrt_to( &o.num, &ores.num)

    else:

      cores = mdnum5_sqrt( &o.num)
      res   = mdnum5.create(&cores)

    # end if 
  elif tval is mdnumfe5:
    f = val
    if res_flag:
      
      fres = out
      femdnum5_sqrt_to( &f.num, &fres.num)

    else:

      cfres = femdnum5_sqrt( &f.num)
      res   = mdnumfe5.create(&cfres)

    # end if  
  elif tval is mdmatfe5:    
    F = val
    if res_flag:

      Fres = out
      femdarr5_sqrt_to( &F.arr, &Fres.arr)

    else:

      cFres = femdarr5_sqrt( &F.arr)
      res   = mdmatfe5.create(&cFres)

    # end if 
  elif tval is mdmat5:
    O = val
    if res_flag:
      
      Ores = out
      mdarr5_sqrt_to( &O.arr, &Ores.arr)

    else:

      cOres = mdarr5_sqrt( &O.arr)
      res   = mdmat5.create(&cOres)

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

      -  mdmat5
      -  mdmatfe5
      -  darr
      -  mdnum5
      -  mdnumfe5
      -  real

  INPUTS:

    - val: Value to evaluate. Must be a supported one of the supported types.
    - out: (optional) Holder of result, in order to avoid memory allocation.

  OUTPUTS:

    If out is not defined, then the result is a newlly allocated member containing the result.
  """
  #***************************************************************************************************

  cdef mdmat5      O, Ores
  cdef dmat       R, Rres
  cdef mdmatfe5    F, Fres
  cdef mdnum5    o, ores
  cdef coeff_t    r, rres
  cdef mdnumfe5     f, fres
  cdef coeff_t   crres
  cdef mdnum5_t cores
  cdef femdnum5_t  cfres
  cdef darr_t    cRres
  cdef mdarr5_t   cOres
  cdef femdarr5_t cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if   tval is mdnum5:
    o = val
    if res_flag:
      
      ores = out
      mdnum5_cbrt_to( &o.num, &ores.num)

    else:

      cores = mdnum5_cbrt( &o.num)
      res   = mdnum5.create(&cores)

    # end if 
  elif tval is mdnumfe5:
    f = val
    if res_flag:
      
      fres = out
      femdnum5_cbrt_to( &f.num, &fres.num)

    else:

      cfres = femdnum5_cbrt( &f.num)
      res   = mdnumfe5.create(&cfres)

    # end if  
  elif tval is mdmatfe5:    
    F = val
    if res_flag:

      Fres = out
      femdarr5_cbrt_to( &F.arr, &Fres.arr)

    else:

      cFres = femdarr5_cbrt( &F.arr)
      res   = mdmatfe5.create(&cFres)

    # end if 
  elif tval is mdmat5:
    O = val
    if res_flag:
      
      Ores = out
      mdarr5_cbrt_to( &O.arr, &Ores.arr)

    else:

      cOres = mdarr5_cbrt( &O.arr)
      res   = mdmat5.create(&cOres)

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

      -  mdmat5
      -  mdmatfe5
      -  darr
      -  mdnum5
      -  mdnumfe5
      -  real

  INPUTS:

    - val: Value to evaluate. Must be a supported one of the supported types.
    - e:   exponent.
    - out: (optional) Holder of result, in order to avoid memory allocation.

  OUTPUTS:

    If out is not defined, then the result is a newlly allocated member containing the result.
  """
  #***************************************************************************************************

  cdef mdmat5      O, Ores
  cdef dmat       R, Rres
  cdef mdmatfe5    F, Fres
  cdef mdnum5    o, ores
  cdef coeff_t    r, rres
  cdef mdnumfe5     f, fres
  cdef coeff_t   crres
  cdef mdnum5_t cores
  cdef femdnum5_t  cfres
  cdef darr_t    cRres
  cdef mdarr5_t   cOres
  cdef femdarr5_t cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if   tval is mdnum5:
    o = val
    if res_flag:
      
      ores = out
      mdnum5_pow_to( &o.num, e, &ores.num)

    else:

      cores = mdnum5_pow( &o.num, e)
      res   = mdnum5.create(&cores)

    # end if 
  elif tval is mdnumfe5:
    f = val
    if res_flag:
      
      fres = out
      femdnum5_pow_to( &f.num, e, &fres.num)

    else:

      cfres = femdnum5_pow( &f.num, e)
      res   = mdnumfe5.create(&cfres)

    # end if  
  elif tval is mdmatfe5:    
    F = val
    if res_flag:

      Fres = out
      femdarr5_pow_to( &F.arr, e, &Fres.arr)

    else:

      cFres = femdarr5_pow( &F.arr, e)
      res   = mdmatfe5.create(&cFres)

    # end if 
  elif tval is mdmat5:
    O = val
    if res_flag:
      
      Ores = out
      mdarr5_pow_to( &O.arr, e, &Ores.arr)

    else:

      cOres = mdarr5_pow( &O.arr, e)
      res   = mdmat5.create(&cOres)

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
cpdef gauss_integrate(object val, mdnumfe5 w, object out = None ):
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
  

  cdef mdmat5      O, Ores
  cdef dmat       R, Rres
  cdef mdmatfe5    F, Fres
  cdef mdnum5    o, ores
  cdef coeff_t    r, rres
  cdef mdnumfe5     f, fres
  cdef coeff_t   crres
  cdef mdnum5_t cores
  cdef femdnum5_t  cfres
  cdef darr_t    cRres
  cdef mdarr5_t   cOres
  cdef femdarr5_t cFres 
  cdef uint8_t res_flag = 1
  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if

  if   tval is mdnumfe5:
    f = val
    if res_flag:
      
      ores = out
      femdnum5_integrate_f_to( &f.num, &w.num, &ores.num)

    else:

      cores = femdnum5_integrate_f( &f.num, &w.num)
      res   = mdnum5.create(&cores)

    # end if  
  elif tval is mdmatfe5:
    F = val
    if res_flag:

      Ores = out
      femdarr5_integrate_to( &F.arr, &w.num, &Ores.arr)

    else:

      cOres = femdarr5_integrate( &F.arr, &w.num)
      res   = mdmat5.create(&cOres)

    # end if 
  elif tval is mdnum5:
    o = val
    if res_flag:
      
      ores = out
      femdnum5_integrate_o_to( &o.num, &w.num, &ores.num)

    else:

      cores = femdnum5_integrate_o( &o.num, &w.num)
      res   = mdnum5.create(&cores)

    # end if
  else:
    try:
      r = val
      if res_flag:
        
        ores = out
        femdnum5_integrate_r_to( r, &w.num, &ores.num)

      else:

        cores = femdnum5_integrate_r( r, &w.num)
        res   = mdnum5.create(&cores)

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

      -  mdmat5
      -  mdmatfe5
      -  darr
      -  mdnum5
      -  mdnumfe5
      -  real
  """
  #***************************************************************************************************

  cdef mdmat5      O, Ores
  cdef dmat       R, Rres
  cdef mdmatfe5    F, Fres
  cdef mdnum5    o, ores
  cdef coeff_t    r, rres
  cdef mdnumfe5     f, fres
  cdef coeff_t   crres
  cdef mdnum5_t cores
  cdef femdnum5_t  cfres
  cdef darr_t    cRres
  cdef mdarr5_t   cOres
  cdef femdarr5_t cFres
  cdef uint8_t res_flag = 1
  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 
  #
  if   tval is mdnum5:
    o = val
    if res_flag:
      
      ores = out
      mdnum5_neg_to( &o.num, &ores.num)

    else:

      cores = mdnum5_neg( &o.num)
      res   = mdnum5.create(&cores)

    # end if 
  elif tval is mdnumfe5:
    f = val
    if res_flag:
      
      fres = out
      femdnum5_neg_to( &f.num, &fres.num)

    else:

      cfres = femdnum5_neg( &f.num)
      res   = mdnumfe5.create(&cfres)

    # end if         
  elif tval is mdmatfe5:    
    F = val
    if res_flag:

      Fres = out
      femdarr5_neg_to( &F.arr, &Fres.arr)

    else:

      cFres = femdarr5_neg( &F.arr)
      res   = mdmatfe5.create(&cFres)

    # end if 
  elif tval is mdmat5:
    O = val
    if res_flag:
      
      Ores = out
      mdarr5_neg_to( &O.arr, &Ores.arr)

    else:

      cOres = mdarr5_neg( &O.arr)
      res   = mdmat5.create(&cOres)

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
