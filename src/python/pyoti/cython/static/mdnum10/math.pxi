#*****************************************************************************************************
cpdef cos(object val, object out = None):
  """
  PURPOSE:  Matrix determinant.
  
  Supported types:

      -  mdmat10
      -  mdmatfe10
      -  darr
      -  mdnum10
      -  mdnumfe10
      -  real
  """
  #***************************************************************************************************

  cdef mdmat10      O, Ores
  cdef dmat       R, Rres
  cdef mdmatfe10    F, Fres
  cdef mdnum10    o, ores
  cdef coeff_t    r, rres
  cdef mdnumfe10     f, fres
  cdef coeff_t   crres
  cdef mdnum10_t cores
  cdef femdnum10_t  cfres
  cdef darr_t    cRres
  cdef mdarr10_t   cOres
  cdef femdarr10_t cFres
  cdef uint8_t res_flag = 1
  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 
  #
  if   tval is mdnum10:
    o = val
    if res_flag:
      
      ores = out
      mdnum10_cos_to( &o.num, &ores.num)

    else:

      cores = mdnum10_cos( &o.num)
      res   = mdnum10.create(&cores)

    # end if 
  elif tval is mdnumfe10:
    f = val
    if res_flag:
      
      fres = out
      femdnum10_cos_to( &f.num, &fres.num)

    else:

      cfres = femdnum10_cos( &f.num)
      res   = mdnumfe10.create(&cfres)

    # end if         
  elif tval is mdmatfe10:    
    F = val
    if res_flag:

      Fres = out
      femdarr10_cos_to( &F.arr, &Fres.arr)

    else:

      cFres = femdarr10_cos( &F.arr)
      res   = mdmatfe10.create(&cFres)

    # end if 
  elif tval is mdmat10:
    O = val
    if res_flag:
      
      Ores = out
      mdarr10_cos_to( &O.arr, &Ores.arr)

    else:

      cOres = mdarr10_cos( &O.arr)
      res   = mdmat10.create(&cOres)

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

      -  mdmat10
      -  mdmatfe10
      -  darr
      -  mdnum10
      -  mdnumfe10
      -  real
  """
  #***************************************************************************************************

  cdef mdmat10      O, Ores
  cdef dmat       R, Rres
  cdef mdmatfe10    F, Fres
  cdef mdnum10    o, ores
  cdef coeff_t    r, rres
  cdef mdnumfe10     f, fres
  cdef coeff_t   crres
  cdef mdnum10_t cores
  cdef femdnum10_t  cfres
  cdef darr_t    cRres
  cdef mdarr10_t   cOres
  cdef femdarr10_t cFres
  cdef uint8_t res_flag = 1
  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if   tval is mdnum10:
    o = val
    if res_flag:
      
      ores = out
      mdnum10_sin_to( &o.num, &ores.num)

    else:

      cores = mdnum10_sin( &o.num)
      res   = mdnum10.create(&cores)

    # end if 
  elif tval is mdnumfe10:
    f = val
    if res_flag:
      
      fres = out
      femdnum10_sin_to( &f.num, &fres.num)

    else:

      cfres = femdnum10_sin( &f.num)
      res   = mdnumfe10.create(&cfres)

    # end if  
  elif tval is mdmatfe10:    
    F = val
    if res_flag:

      Fres = out
      femdarr10_sin_to( &F.arr, &Fres.arr)

    else:

      cFres = femdarr10_sin( &F.arr)
      res   = mdmatfe10.create(&cFres)

    # end if 
  elif tval is mdmat10:
    O = val
    if res_flag:
      
      Ores = out
      mdarr10_sin_to( &O.arr, &Ores.arr)

    else:

      cOres = mdarr10_sin( &O.arr)
      res   = mdmat10.create(&cOres)

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

      -  mdmat10
      -  mdmatfe10
      -  darr
      -  mdnum10
      -  mdnumfe10
      -  real
  """
  #***************************************************************************************************

  cdef mdmat10      O, Ores
  cdef dmat       R, Rres
  cdef mdmatfe10    F, Fres
  cdef mdnum10    o, ores
  cdef coeff_t    r, rres
  cdef mdnumfe10     f, fres
  cdef coeff_t   crres
  cdef mdnum10_t cores
  cdef femdnum10_t  cfres
  cdef darr_t    cRres
  cdef mdarr10_t   cOres
  cdef femdarr10_t cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if   tval is mdnum10:
    o = val
    if res_flag:
      
      ores = out
      mdnum10_tan_to( &o.num, &ores.num)

    else:

      cores = mdnum10_tan( &o.num)
      res   = mdnum10.create(&cores)

    # end if 
  elif tval is mdnumfe10:
    f = val
    if res_flag:
      
      fres = out
      femdnum10_tan_to( &f.num, &fres.num)

    else:

      cfres = femdnum10_tan( &f.num)
      res   = mdnumfe10.create(&cfres)

    # end if  
  elif tval is mdmatfe10:    
    F = val
    if res_flag:

      Fres = out
      femdarr10_tan_to( &F.arr, &Fres.arr)

    else:

      cFres = femdarr10_tan( &F.arr)
      res   = mdmatfe10.create(&cFres)

    # end if 
  elif tval is mdmat10:
    O = val
    if res_flag:
      
      Ores = out
      mdarr10_tan_to( &O.arr, &Ores.arr)

    else:

      cOres = mdarr10_tan( &O.arr)
      res   = mdmat10.create(&cOres)

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

      -  mdmat10
      -  mdmatfe10
      -  darr
      -  mdnum10
      -  mdnumfe10
      -  real
  """
  #***************************************************************************************************

  cdef mdmat10      O, Ores
  cdef dmat       R, Rres
  cdef mdmatfe10    F, Fres
  cdef mdnum10    o, ores
  cdef coeff_t    r, rres
  cdef mdnumfe10     f, fres
  cdef coeff_t   crres
  cdef mdnum10_t cores
  cdef femdnum10_t  cfres
  cdef darr_t    cRres
  cdef mdarr10_t   cOres
  cdef femdarr10_t cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if   tval is mdnum10:
    o = val
    if res_flag:
      
      ores = out
      mdnum10_acos_to( &o.num, &ores.num)

    else:

      cores = mdnum10_acos( &o.num)
      res   = mdnum10.create(&cores)

    # end if 
  elif tval is mdnumfe10:
    f = val
    if res_flag:
      
      fres = out
      femdnum10_acos_to( &f.num, &fres.num)

    else:

      cfres = femdnum10_acos( &f.num)
      res   = mdnumfe10.create(&cfres)

    # end if  
  elif tval is mdmatfe10:    
    F = val
    if res_flag:

      Fres = out
      femdarr10_acos_to( &F.arr, &Fres.arr)

    else:

      cFres = femdarr10_acos( &F.arr)
      res   = mdmatfe10.create(&cFres)

    # end if 
  elif tval is mdmat10:
    O = val
    if res_flag:
      
      Ores = out
      mdarr10_acos_to( &O.arr, &Ores.arr)

    else:

      cOres = mdarr10_acos( &O.arr)
      res   = mdmat10.create(&cOres)

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

      -  mdmat10
      -  mdmatfe10
      -  darr
      -  mdnum10
      -  mdnumfe10
      -  real
  """
  #***************************************************************************************************

  cdef mdmat10      O, Ores
  cdef dmat       R, Rres
  cdef mdmatfe10    F, Fres
  cdef mdnum10    o, ores
  cdef coeff_t    r, rres
  cdef mdnumfe10     f, fres
  cdef coeff_t   crres
  cdef mdnum10_t cores
  cdef femdnum10_t  cfres
  cdef darr_t    cRres
  cdef mdarr10_t   cOres
  cdef femdarr10_t cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if   tval is mdnum10:
    o = val
    if res_flag:
      
      ores = out
      mdnum10_asin_to( &o.num, &ores.num)

    else:

      cores = mdnum10_asin( &o.num)
      res   = mdnum10.create(&cores)

    # end if 
  elif tval is mdnumfe10:
    f = val
    if res_flag:
      
      fres = out
      femdnum10_asin_to( &f.num, &fres.num)

    else:

      cfres = femdnum10_asin( &f.num)
      res   = mdnumfe10.create(&cfres)

    # end if  
  elif tval is mdmatfe10:    
    F = val
    if res_flag:

      Fres = out
      femdarr10_asin_to( &F.arr, &Fres.arr)

    else:

      cFres = femdarr10_asin( &F.arr)
      res   = mdmatfe10.create(&cFres)

    # end if 
  elif tval is mdmat10:
    O = val
    if res_flag:
      
      Ores = out
      mdarr10_asin_to( &O.arr, &Ores.arr)

    else:

      cOres = mdarr10_asin( &O.arr)
      res   = mdmat10.create(&cOres)

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

      -  mdmat10
      -  mdmatfe10
      -  darr
      -  mdnum10
      -  mdnumfe10
      -  real
  """
  #***************************************************************************************************

  cdef mdmat10      O, Ores
  cdef dmat       R, Rres
  cdef mdmatfe10    F, Fres
  cdef mdnum10    o, ores
  cdef coeff_t    r, rres
  cdef mdnumfe10     f, fres
  cdef coeff_t   crres
  cdef mdnum10_t cores
  cdef femdnum10_t  cfres
  cdef darr_t    cRres
  cdef mdarr10_t   cOres
  cdef femdarr10_t cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if   tval is mdnum10:
    o = val
    if res_flag:
      
      ores = out
      mdnum10_atan_to( &o.num, &ores.num)

    else:

      cores = mdnum10_atan( &o.num)
      res   = mdnum10.create(&cores)

    # end if 
  elif tval is mdnumfe10:
    f = val
    if res_flag:
      
      fres = out
      femdnum10_atan_to( &f.num, &fres.num)

    else:

      cfres = femdnum10_atan( &f.num)
      res   = mdnumfe10.create(&cfres)

    # end if  
  elif tval is mdmatfe10:    
    F = val
    if res_flag:

      Fres = out
      femdarr10_atan_to( &F.arr, &Fres.arr)

    else:

      cFres = femdarr10_atan( &F.arr)
      res   = mdmatfe10.create(&cFres)

    # end if 
  elif tval is mdmat10:
    O = val
    if res_flag:
      
      Ores = out
      mdarr10_atan_to( &O.arr, &Ores.arr)

    else:

      cOres = mdarr10_atan( &O.arr)
      res   = mdmat10.create(&cOres)

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

      -  mdmat10
      -  mdmatfe10
      -  darr
      -  mdnum10
      -  mdnumfe10
      -  real
  """
  #***************************************************************************************************

  cdef mdmat10      O, Ores
  cdef dmat       R, Rres
  cdef mdmatfe10    F, Fres
  cdef mdnum10    o, ores
  cdef coeff_t    r, rres
  cdef mdnumfe10     f, fres
  cdef coeff_t   crres
  cdef mdnum10_t cores
  cdef femdnum10_t  cfres
  cdef darr_t    cRres
  cdef mdarr10_t   cOres
  cdef femdarr10_t cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if   tval is mdnum10:
    o = val
    if res_flag:
      
      ores = out
      mdnum10_sinh_to( &o.num, &ores.num)

    else:

      cores = mdnum10_sinh( &o.num)
      res   = mdnum10.create(&cores)

    # end if 
  elif tval is mdnumfe10:
    f = val
    if res_flag:
      
      fres = out
      femdnum10_sinh_to( &f.num, &fres.num)

    else:

      cfres = femdnum10_sinh( &f.num)
      res   = mdnumfe10.create(&cfres)

    # end if  
  elif tval is mdmatfe10:    
    F = val
    if res_flag:

      Fres = out
      femdarr10_sinh_to( &F.arr, &Fres.arr)

    else:

      cFres = femdarr10_sinh( &F.arr)
      res   = mdmatfe10.create(&cFres)

    # end if 
  elif tval is mdmat10:
    O = val
    if res_flag:
      
      Ores = out
      mdarr10_sinh_to( &O.arr, &Ores.arr)

    else:

      cOres = mdarr10_sinh( &O.arr)
      res   = mdmat10.create(&cOres)

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

      -  mdmat10
      -  mdmatfe10
      -  darr
      -  mdnum10
      -  mdnumfe10
      -  real
  """
  #***************************************************************************************************

  cdef mdmat10      O, Ores
  cdef dmat       R, Rres
  cdef mdmatfe10    F, Fres
  cdef mdnum10    o, ores
  cdef coeff_t    r, rres
  cdef mdnumfe10     f, fres
  cdef coeff_t   crres
  cdef mdnum10_t cores
  cdef femdnum10_t  cfres
  cdef darr_t    cRres
  cdef mdarr10_t   cOres
  cdef femdarr10_t cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if   tval is mdnum10:
    o = val
    if res_flag:
      
      ores = out
      mdnum10_cosh_to( &o.num, &ores.num)

    else:

      cores = mdnum10_cosh( &o.num)
      res   = mdnum10.create(&cores)

    # end if 
  elif tval is mdnumfe10:
    f = val
    if res_flag:
      
      fres = out
      femdnum10_cosh_to( &f.num, &fres.num)

    else:

      cfres = femdnum10_cosh( &f.num)
      res   = mdnumfe10.create(&cfres)

    # end if  
  elif tval is mdmatfe10:    
    F = val
    if res_flag:

      Fres = out
      femdarr10_cosh_to( &F.arr, &Fres.arr)

    else:

      cFres = femdarr10_cosh( &F.arr)
      res   = mdmatfe10.create(&cFres)

    # end if 
  elif tval is mdmat10:
    O = val
    if res_flag:
      
      Ores = out
      mdarr10_cosh_to( &O.arr, &Ores.arr)

    else:

      cOres = mdarr10_cosh( &O.arr)
      res   = mdmat10.create(&cOres)

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

      -  mdmat10
      -  mdmatfe10
      -  darr
      -  mdnum10
      -  mdnumfe10
      -  real
  """
  #***************************************************************************************************

  cdef mdmat10      O, Ores
  cdef dmat       R, Rres
  cdef mdmatfe10    F, Fres
  cdef mdnum10    o, ores
  cdef coeff_t    r, rres
  cdef mdnumfe10     f, fres
  cdef coeff_t   crres
  cdef mdnum10_t cores
  cdef femdnum10_t  cfres
  cdef darr_t    cRres
  cdef mdarr10_t   cOres
  cdef femdarr10_t cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if   tval is mdnum10:
    o = val
    if res_flag:
      
      ores = out
      mdnum10_tanh_to( &o.num, &ores.num)

    else:

      cores = mdnum10_tanh( &o.num)
      res   = mdnum10.create(&cores)

    # end if 
  elif tval is mdnumfe10:
    f = val
    if res_flag:
      
      fres = out
      femdnum10_tanh_to( &f.num, &fres.num)

    else:

      cfres = femdnum10_tanh( &f.num)
      res   = mdnumfe10.create(&cfres)

    # end if  
  elif tval is mdmatfe10:    
    F = val
    if res_flag:

      Fres = out
      femdarr10_tanh_to( &F.arr, &Fres.arr)

    else:

      cFres = femdarr10_tanh( &F.arr)
      res   = mdmatfe10.create(&cFres)

    # end if 
  elif tval is mdmat10:
    O = val
    if res_flag:
      
      Ores = out
      mdarr10_tanh_to( &O.arr, &Ores.arr)

    else:

      cOres = mdarr10_tanh( &O.arr)
      res   = mdmat10.create(&cOres)

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

      -  mdmat10
      -  mdmatfe10
      -  darr
      -  mdnum10
      -  mdnumfe10
      -  real
  """
  #***************************************************************************************************

  cdef mdmat10      O, Ores
  cdef dmat       R, Rres
  cdef mdmatfe10    F, Fres
  cdef mdnum10    o, ores
  cdef coeff_t    r, rres
  cdef mdnumfe10     f, fres
  cdef coeff_t   crres
  cdef mdnum10_t cores
  cdef femdnum10_t  cfres
  cdef darr_t    cRres
  cdef mdarr10_t   cOres
  cdef femdarr10_t cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if   tval is mdnum10:
    o = val
    if res_flag:
      
      ores = out
      mdnum10_acosh_to( &o.num, &ores.num)

    else:

      cores = mdnum10_acosh( &o.num)
      res   = mdnum10.create(&cores)

    # end if 
  elif tval is mdnumfe10:
    f = val
    if res_flag:
      
      fres = out
      femdnum10_acosh_to( &f.num, &fres.num)

    else:

      cfres = femdnum10_acosh( &f.num)
      res   = mdnumfe10.create(&cfres)

    # end if  
  elif tval is mdmatfe10:    
    F = val
    if res_flag:

      Fres = out
      femdarr10_acosh_to( &F.arr, &Fres.arr)

    else:

      cFres = femdarr10_acosh( &F.arr)
      res   = mdmatfe10.create(&cFres)

    # end if 
  elif tval is mdmat10:
    O = val
    if res_flag:
      
      Ores = out
      mdarr10_acosh_to( &O.arr, &Ores.arr)

    else:

      cOres = mdarr10_acosh( &O.arr)
      res   = mdmat10.create(&cOres)

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

      -  mdmat10
      -  mdmatfe10
      -  darr
      -  mdnum10
      -  mdnumfe10
      -  real
  """
  #***************************************************************************************************

  cdef mdmat10      O, Ores
  cdef dmat       R, Rres
  cdef mdmatfe10    F, Fres
  cdef mdnum10    o, ores
  cdef coeff_t    r, rres
  cdef mdnumfe10     f, fres
  cdef coeff_t   crres
  cdef mdnum10_t cores
  cdef femdnum10_t  cfres
  cdef darr_t    cRres
  cdef mdarr10_t   cOres
  cdef femdarr10_t cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if   tval is mdnum10:
    o = val
    if res_flag:
      
      ores = out
      mdnum10_asinh_to( &o.num, &ores.num)

    else:

      cores = mdnum10_asinh( &o.num)
      res   = mdnum10.create(&cores)

    # end if 
  elif tval is mdnumfe10:
    f = val
    if res_flag:
      
      fres = out
      femdnum10_asinh_to( &f.num, &fres.num)

    else:

      cfres = femdnum10_asinh( &f.num)
      res   = mdnumfe10.create(&cfres)

    # end if  
  elif tval is mdmatfe10:    
    F = val
    if res_flag:

      Fres = out
      femdarr10_asinh_to( &F.arr, &Fres.arr)

    else:

      cFres = femdarr10_asinh( &F.arr)
      res   = mdmatfe10.create(&cFres)

    # end if 
  elif tval is mdmat10:
    O = val
    if res_flag:
      
      Ores = out
      mdarr10_asinh_to( &O.arr, &Ores.arr)

    else:

      cOres = mdarr10_asinh( &O.arr)
      res   = mdmat10.create(&cOres)

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

      -  mdmat10
      -  mdmatfe10
      -  darr
      -  mdnum10
      -  mdnumfe10
      -  real
  """
  #***************************************************************************************************

  cdef mdmat10      O, Ores
  cdef dmat       R, Rres
  cdef mdmatfe10    F, Fres
  cdef mdnum10    o, ores
  cdef coeff_t    r, rres
  cdef mdnumfe10     f, fres
  cdef coeff_t   crres
  cdef mdnum10_t cores
  cdef femdnum10_t  cfres
  cdef darr_t    cRres
  cdef mdarr10_t   cOres
  cdef femdarr10_t cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if   tval is mdnum10:
    o = val
    if res_flag:
      
      ores = out
      mdnum10_atanh_to( &o.num, &ores.num)

    else:

      cores = mdnum10_atanh( &o.num)
      res   = mdnum10.create(&cores)

    # end if 
  elif tval is mdnumfe10:
    f = val
    if res_flag:
      
      fres = out
      femdnum10_atanh_to( &f.num, &fres.num)

    else:

      cfres = femdnum10_atanh( &f.num)
      res   = mdnumfe10.create(&cfres)

    # end if  
  elif tval is mdmatfe10:    
    F = val
    if res_flag:

      Fres = out
      femdarr10_atanh_to( &F.arr, &Fres.arr)

    else:

      cFres = femdarr10_atanh( &F.arr)
      res   = mdmatfe10.create(&cFres)

    # end if 
  elif tval is mdmat10:
    O = val
    if res_flag:
      
      Ores = out
      mdarr10_atanh_to( &O.arr, &Ores.arr)

    else:

      cOres = mdarr10_atanh( &O.arr)
      res   = mdmat10.create(&cOres)

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

      -  mdmat10
      -  mdmatfe10
      -  darr
      -  mdnum10
      -  mdnumfe10
      -  real
  """
  #***************************************************************************************************

  cdef mdmat10      O, Ores
  cdef dmat       R, Rres
  cdef mdmatfe10    F, Fres
  cdef mdnum10    o, ores
  cdef coeff_t    r, rres
  cdef mdnumfe10     f, fres
  cdef coeff_t   crres
  cdef mdnum10_t cores
  cdef femdnum10_t  cfres
  cdef darr_t    cRres
  cdef mdarr10_t   cOres
  cdef femdarr10_t cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if   tval is mdnum10:
    o = val
    if res_flag:
      
      ores = out
      mdnum10_exp_to( &o.num, &ores.num)

    else:

      cores = mdnum10_exp( &o.num)
      res   = mdnum10.create(&cores)

    # end if 
  elif tval is mdnumfe10:
    f = val
    if res_flag:
      
      fres = out
      femdnum10_exp_to( &f.num, &fres.num)

    else:

      cfres = femdnum10_exp( &f.num)
      res   = mdnumfe10.create(&cfres)

    # end if  
  elif tval is mdmatfe10:    
    F = val
    if res_flag:

      Fres = out
      femdarr10_exp_to( &F.arr, &Fres.arr)

    else:

      cFres = femdarr10_exp( &F.arr)
      res   = mdmatfe10.create(&cFres)

    # end if 
  elif tval is mdmat10:
    O = val
    if res_flag:
      
      Ores = out
      mdarr10_exp_to( &O.arr, &Ores.arr)

    else:

      cOres = mdarr10_exp( &O.arr)
      res   = mdmat10.create(&cOres)

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

      -  mdmat10
      -  mdmatfe10
      -  darr
      -  mdnum10
      -  mdnumfe10
      -  real

  INPUTS:

    - val: Value to evaluate. Must be a supported one of the supported types.
    - out: (optional) Holder of result, in order to avoid memory allocation.

  OUTPUTS:

    If out is not defined, then the result is a newlly allocated member containing the result.
  """
  #***************************************************************************************************

  cdef mdmat10      O, Ores
  cdef dmat       R, Rres
  cdef mdmatfe10    F, Fres
  cdef mdnum10    o, ores
  cdef coeff_t    r, rres
  cdef mdnumfe10     f, fres
  cdef coeff_t   crres
  cdef mdnum10_t cores
  cdef femdnum10_t  cfres
  cdef darr_t    cRres
  cdef mdarr10_t   cOres
  cdef femdarr10_t cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if   tval is mdnum10:
    o = val
    if res_flag:
      
      ores = out
      mdnum10_log_to( &o.num, &ores.num)

    else:

      cores = mdnum10_log( &o.num)
      res   = mdnum10.create(&cores)

    # end if 
  elif tval is mdnumfe10:
    f = val
    if res_flag:
      
      fres = out
      femdnum10_log_to( &f.num, &fres.num)

    else:

      cfres = femdnum10_log( &f.num)
      res   = mdnumfe10.create(&cfres)

    # end if  
  elif tval is mdmatfe10:    
    F = val
    if res_flag:

      Fres = out
      femdarr10_log_to( &F.arr, &Fres.arr)

    else:

      cFres = femdarr10_log( &F.arr)
      res   = mdmatfe10.create(&cFres)

    # end if 
  elif tval is mdmat10:
    O = val
    if res_flag:
      
      Ores = out
      mdarr10_log_to( &O.arr, &Ores.arr)

    else:

      cOres = mdarr10_log( &O.arr)
      res   = mdmat10.create(&cOres)

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

      -  mdmat10
      -  mdmatfe10
      -  darr
      -  mdnum10
      -  mdnumfe10
      -  real

  INPUTS:

    - val: Value to evaluate. Must be a supported one of the supported types.
    - out: (optional) Holder of result, in order to avoid memory allocation.

  OUTPUTS:

    If out is not defined, then the result is a newlly allocated member containing the result.
  """
  #***************************************************************************************************

  cdef mdmat10      O, Ores
  cdef dmat       R, Rres
  cdef mdmatfe10    F, Fres
  cdef mdnum10    o, ores
  cdef coeff_t    r, rres
  cdef mdnumfe10     f, fres
  cdef coeff_t   crres
  cdef mdnum10_t cores
  cdef femdnum10_t  cfres
  cdef darr_t    cRres
  cdef mdarr10_t   cOres
  cdef femdarr10_t cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if   tval is mdnum10:
    o = val
    if res_flag:
      
      ores = out
      mdnum10_log10_to( &o.num, &ores.num)

    else:

      cores = mdnum10_log10( &o.num)
      res   = mdnum10.create(&cores)

    # end if 
  elif tval is mdnumfe10:
    f = val
    if res_flag:
      
      fres = out
      femdnum10_log10_to( &f.num, &fres.num)

    else:

      cfres = femdnum10_log10( &f.num)
      res   = mdnumfe10.create(&cfres)

    # end if  
  elif tval is mdmatfe10:    
    F = val
    if res_flag:

      Fres = out
      femdarr10_log10_to( &F.arr, &Fres.arr)

    else:

      cFres = femdarr10_log10( &F.arr)
      res   = mdmatfe10.create(&cFres)

    # end if 
  elif tval is mdmat10:
    O = val
    if res_flag:
      
      Ores = out
      mdarr10_log10_to( &O.arr, &Ores.arr)

    else:

      cOres = mdarr10_log10( &O.arr)
      res   = mdmat10.create(&cOres)

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

      -  mdmat10
      -  mdmatfe10
      -  darr
      -  mdnum10
      -  mdnumfe10
      -  real

  INPUTS:

    - val: Value to evaluate. Must be a supported one of the supported types.
    - b:   Base.
    - out: (optional) Holder of result, in order to avoid memory allocation.

  OUTPUTS:

    If out is not defined, then the result is a newlly allocated member containing the result.
  """
  #***************************************************************************************************

  cdef mdmat10      O, Ores
  cdef dmat       R, Rres
  cdef mdmatfe10    F, Fres
  cdef mdnum10    o, ores
  cdef coeff_t    r, rres
  cdef mdnumfe10     f, fres
  cdef coeff_t   crres
  cdef mdnum10_t cores
  cdef femdnum10_t  cfres
  cdef darr_t    cRres
  cdef mdarr10_t   cOres
  cdef femdarr10_t cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if   tval is mdnum10:
    o = val
    if res_flag:
      
      ores = out
      mdnum10_logb_to( &o.num, b, &ores.num)

    else:

      cores = mdnum10_logb( &o.num, b)
      res   = mdnum10.create(&cores)

    # end if 
  elif tval is mdnumfe10:
    f = val
    if res_flag:
      
      fres = out
      femdnum10_logb_to( &f.num, b, &fres.num)

    else:

      cfres = femdnum10_logb( &f.num, b)
      res   = mdnumfe10.create(&cfres)

    # end if  
  elif tval is mdmatfe10:    
    F = val
    if res_flag:

      Fres = out
      femdarr10_logb_to( &F.arr, b, &Fres.arr)

    else:

      cFres = femdarr10_logb( &F.arr, b)
      res   = mdmatfe10.create(&cFres)

    # end if 
  elif tval is mdmat10:
    O = val
    if res_flag:
      
      Ores = out
      mdarr10_logb_to( &O.arr, b, &Ores.arr)

    else:

      cOres = mdarr10_logb( &O.arr, b)
      res   = mdmat10.create(&cOres)

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

      -  mdmat10
      -  mdmatfe10
      -  darr
      -  mdnum10
      -  mdnumfe10
      -  real

  INPUTS:

    - val: Value to evaluate. Must be a supported one of the supported types.
    - out: (optional) Holder of result, in order to avoid memory allocation.

  OUTPUTS:

    If out is not defined, then the result is a newlly allocated member containing the result.
  """
  #***************************************************************************************************

  cdef mdmat10      O, Ores
  cdef dmat       R, Rres
  cdef mdmatfe10    F, Fres
  cdef mdnum10    o, ores
  cdef coeff_t    r, rres
  cdef mdnumfe10     f, fres
  cdef coeff_t   crres
  cdef mdnum10_t cores
  cdef femdnum10_t  cfres
  cdef darr_t    cRres
  cdef mdarr10_t   cOres
  cdef femdarr10_t cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if   tval is mdnum10:
    o = val
    if res_flag:
      
      ores = out
      mdnum10_sqrt_to( &o.num, &ores.num)

    else:

      cores = mdnum10_sqrt( &o.num)
      res   = mdnum10.create(&cores)

    # end if 
  elif tval is mdnumfe10:
    f = val
    if res_flag:
      
      fres = out
      femdnum10_sqrt_to( &f.num, &fres.num)

    else:

      cfres = femdnum10_sqrt( &f.num)
      res   = mdnumfe10.create(&cfres)

    # end if  
  elif tval is mdmatfe10:    
    F = val
    if res_flag:

      Fres = out
      femdarr10_sqrt_to( &F.arr, &Fres.arr)

    else:

      cFres = femdarr10_sqrt( &F.arr)
      res   = mdmatfe10.create(&cFres)

    # end if 
  elif tval is mdmat10:
    O = val
    if res_flag:
      
      Ores = out
      mdarr10_sqrt_to( &O.arr, &Ores.arr)

    else:

      cOres = mdarr10_sqrt( &O.arr)
      res   = mdmat10.create(&cOres)

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

      -  mdmat10
      -  mdmatfe10
      -  darr
      -  mdnum10
      -  mdnumfe10
      -  real

  INPUTS:

    - val: Value to evaluate. Must be a supported one of the supported types.
    - out: (optional) Holder of result, in order to avoid memory allocation.

  OUTPUTS:

    If out is not defined, then the result is a newlly allocated member containing the result.
  """
  #***************************************************************************************************

  cdef mdmat10      O, Ores
  cdef dmat       R, Rres
  cdef mdmatfe10    F, Fres
  cdef mdnum10    o, ores
  cdef coeff_t    r, rres
  cdef mdnumfe10     f, fres
  cdef coeff_t   crres
  cdef mdnum10_t cores
  cdef femdnum10_t  cfres
  cdef darr_t    cRres
  cdef mdarr10_t   cOres
  cdef femdarr10_t cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if   tval is mdnum10:
    o = val
    if res_flag:
      
      ores = out
      mdnum10_cbrt_to( &o.num, &ores.num)

    else:

      cores = mdnum10_cbrt( &o.num)
      res   = mdnum10.create(&cores)

    # end if 
  elif tval is mdnumfe10:
    f = val
    if res_flag:
      
      fres = out
      femdnum10_cbrt_to( &f.num, &fres.num)

    else:

      cfres = femdnum10_cbrt( &f.num)
      res   = mdnumfe10.create(&cfres)

    # end if  
  elif tval is mdmatfe10:    
    F = val
    if res_flag:

      Fres = out
      femdarr10_cbrt_to( &F.arr, &Fres.arr)

    else:

      cFres = femdarr10_cbrt( &F.arr)
      res   = mdmatfe10.create(&cFres)

    # end if 
  elif tval is mdmat10:
    O = val
    if res_flag:
      
      Ores = out
      mdarr10_cbrt_to( &O.arr, &Ores.arr)

    else:

      cOres = mdarr10_cbrt( &O.arr)
      res   = mdmat10.create(&cOres)

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

      -  mdmat10
      -  mdmatfe10
      -  darr
      -  mdnum10
      -  mdnumfe10
      -  real

  INPUTS:

    - val: Value to evaluate. Must be a supported one of the supported types.
    - e:   exponent.
    - out: (optional) Holder of result, in order to avoid memory allocation.

  OUTPUTS:

    If out is not defined, then the result is a newlly allocated member containing the result.
  """
  #***************************************************************************************************

  cdef mdmat10      O, Ores
  cdef dmat       R, Rres
  cdef mdmatfe10    F, Fres
  cdef mdnum10    o, ores
  cdef coeff_t    r, rres
  cdef mdnumfe10     f, fres
  cdef coeff_t   crres
  cdef mdnum10_t cores
  cdef femdnum10_t  cfres
  cdef darr_t    cRres
  cdef mdarr10_t   cOres
  cdef femdarr10_t cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if   tval is mdnum10:
    o = val
    if res_flag:
      
      ores = out
      mdnum10_pow_to( &o.num, e, &ores.num)

    else:

      cores = mdnum10_pow( &o.num, e)
      res   = mdnum10.create(&cores)

    # end if 
  elif tval is mdnumfe10:
    f = val
    if res_flag:
      
      fres = out
      femdnum10_pow_to( &f.num, e, &fres.num)

    else:

      cfres = femdnum10_pow( &f.num, e)
      res   = mdnumfe10.create(&cfres)

    # end if  
  elif tval is mdmatfe10:    
    F = val
    if res_flag:

      Fres = out
      femdarr10_pow_to( &F.arr, e, &Fres.arr)

    else:

      cFres = femdarr10_pow( &F.arr, e)
      res   = mdmatfe10.create(&cFres)

    # end if 
  elif tval is mdmat10:
    O = val
    if res_flag:
      
      Ores = out
      mdarr10_pow_to( &O.arr, e, &Ores.arr)

    else:

      cOres = mdarr10_pow( &O.arr, e)
      res   = mdmat10.create(&cOres)

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
cpdef gauss_integrate(object val, mdnumfe10 w, object out = None ):
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
  

  cdef mdmat10      O, Ores
  cdef dmat       R, Rres
  cdef mdmatfe10    F, Fres
  cdef mdnum10    o, ores
  cdef coeff_t    r, rres
  cdef mdnumfe10     f, fres
  cdef coeff_t   crres
  cdef mdnum10_t cores
  cdef femdnum10_t  cfres
  cdef darr_t    cRres
  cdef mdarr10_t   cOres
  cdef femdarr10_t cFres 
  cdef uint8_t res_flag = 1
  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if

  if   tval is mdnumfe10:
    f = val
    if res_flag:
      
      ores = out
      femdnum10_integrate_f_to( &f.num, &w.num, &ores.num)

    else:

      cores = femdnum10_integrate_f( &f.num, &w.num)
      res   = mdnum10.create(&cores)

    # end if  
  elif tval is mdmatfe10:
    F = val
    if res_flag:

      Ores = out
      femdarr10_integrate_to( &F.arr, &w.num, &Ores.arr)

    else:

      cOres = femdarr10_integrate( &F.arr, &w.num)
      res   = mdmat10.create(&cOres)

    # end if 
  elif tval is mdnum10:
    o = val
    if res_flag:
      
      ores = out
      femdnum10_integrate_o_to( &o.num, &w.num, &ores.num)

    else:

      cores = femdnum10_integrate_o( &o.num, &w.num)
      res   = mdnum10.create(&cores)

    # end if
  else:
    try:
      r = val
      if res_flag:
        
        ores = out
        femdnum10_integrate_r_to( r, &w.num, &ores.num)

      else:

        cores = femdnum10_integrate_r( r, &w.num)
        res   = mdnum10.create(&cores)

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

      -  mdmat10
      -  mdmatfe10
      -  darr
      -  mdnum10
      -  mdnumfe10
      -  real
  """
  #***************************************************************************************************

  cdef mdmat10      O, Ores
  cdef dmat       R, Rres
  cdef mdmatfe10    F, Fres
  cdef mdnum10    o, ores
  cdef coeff_t    r, rres
  cdef mdnumfe10     f, fres
  cdef coeff_t   crres
  cdef mdnum10_t cores
  cdef femdnum10_t  cfres
  cdef darr_t    cRres
  cdef mdarr10_t   cOres
  cdef femdarr10_t cFres
  cdef uint8_t res_flag = 1
  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 
  #
  if   tval is mdnum10:
    o = val
    if res_flag:
      
      ores = out
      mdnum10_neg_to( &o.num, &ores.num)

    else:

      cores = mdnum10_neg( &o.num)
      res   = mdnum10.create(&cores)

    # end if 
  elif tval is mdnumfe10:
    f = val
    if res_flag:
      
      fres = out
      femdnum10_neg_to( &f.num, &fres.num)

    else:

      cfres = femdnum10_neg( &f.num)
      res   = mdnumfe10.create(&cfres)

    # end if         
  elif tval is mdmatfe10:    
    F = val
    if res_flag:

      Fres = out
      femdarr10_neg_to( &F.arr, &Fres.arr)

    else:

      cFres = femdarr10_neg( &F.arr)
      res   = mdmatfe10.create(&cFres)

    # end if 
  elif tval is mdmat10:
    O = val
    if res_flag:
      
      Ores = out
      mdarr10_neg_to( &O.arr, &Ores.arr)

    else:

      cOres = mdarr10_neg( &O.arr)
      res   = mdmat10.create(&cOres)

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
