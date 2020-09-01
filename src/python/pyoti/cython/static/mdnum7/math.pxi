#*****************************************************************************************************
cpdef cos(object val, object out = None):
  """
  PURPOSE:  Matrix determinant.
  
  Supported types:

      -  mdmat7
      -  mdmatfe7
      -  darr
      -  mdnum7
      -  mdnumfe7
      -  real
  """
  #***************************************************************************************************

  cdef mdmat7      O, Ores
  cdef dmat       R, Rres
  cdef mdmatfe7    F, Fres
  cdef mdnum7    o, ores
  cdef coeff_t    r, rres
  cdef mdnumfe7     f, fres
  cdef coeff_t   crres
  cdef mdnum7_t cores
  cdef femdnum7_t  cfres
  cdef darr_t    cRres
  cdef mdarr7_t   cOres
  cdef femdarr7_t cFres
  cdef uint8_t res_flag = 1
  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 
  #
  if   tval is mdnum7:
    o = val
    if res_flag:
      
      ores = out
      mdnum7_cos_to( &o.num, &ores.num)

    else:

      cores = mdnum7_cos( &o.num)
      res   = mdnum7.create(&cores)

    # end if 
  elif tval is mdnumfe7:
    f = val
    if res_flag:
      
      fres = out
      femdnum7_cos_to( &f.num, &fres.num)

    else:

      cfres = femdnum7_cos( &f.num)
      res   = mdnumfe7.create(&cfres)

    # end if         
  elif tval is mdmatfe7:    
    F = val
    if res_flag:

      Fres = out
      femdarr7_cos_to( &F.arr, &Fres.arr)

    else:

      cFres = femdarr7_cos( &F.arr)
      res   = mdmatfe7.create(&cFres)

    # end if 
  elif tval is mdmat7:
    O = val
    if res_flag:
      
      Ores = out
      mdarr7_cos_to( &O.arr, &Ores.arr)

    else:

      cOres = mdarr7_cos( &O.arr)
      res   = mdmat7.create(&cOres)

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

      -  mdmat7
      -  mdmatfe7
      -  darr
      -  mdnum7
      -  mdnumfe7
      -  real
  """
  #***************************************************************************************************

  cdef mdmat7      O, Ores
  cdef dmat       R, Rres
  cdef mdmatfe7    F, Fres
  cdef mdnum7    o, ores
  cdef coeff_t    r, rres
  cdef mdnumfe7     f, fres
  cdef coeff_t   crres
  cdef mdnum7_t cores
  cdef femdnum7_t  cfres
  cdef darr_t    cRres
  cdef mdarr7_t   cOres
  cdef femdarr7_t cFres
  cdef uint8_t res_flag = 1
  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if   tval is mdnum7:
    o = val
    if res_flag:
      
      ores = out
      mdnum7_sin_to( &o.num, &ores.num)

    else:

      cores = mdnum7_sin( &o.num)
      res   = mdnum7.create(&cores)

    # end if 
  elif tval is mdnumfe7:
    f = val
    if res_flag:
      
      fres = out
      femdnum7_sin_to( &f.num, &fres.num)

    else:

      cfres = femdnum7_sin( &f.num)
      res   = mdnumfe7.create(&cfres)

    # end if  
  elif tval is mdmatfe7:    
    F = val
    if res_flag:

      Fres = out
      femdarr7_sin_to( &F.arr, &Fres.arr)

    else:

      cFres = femdarr7_sin( &F.arr)
      res   = mdmatfe7.create(&cFres)

    # end if 
  elif tval is mdmat7:
    O = val
    if res_flag:
      
      Ores = out
      mdarr7_sin_to( &O.arr, &Ores.arr)

    else:

      cOres = mdarr7_sin( &O.arr)
      res   = mdmat7.create(&cOres)

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

      -  mdmat7
      -  mdmatfe7
      -  darr
      -  mdnum7
      -  mdnumfe7
      -  real
  """
  #***************************************************************************************************

  cdef mdmat7      O, Ores
  cdef dmat       R, Rres
  cdef mdmatfe7    F, Fres
  cdef mdnum7    o, ores
  cdef coeff_t    r, rres
  cdef mdnumfe7     f, fres
  cdef coeff_t   crres
  cdef mdnum7_t cores
  cdef femdnum7_t  cfres
  cdef darr_t    cRres
  cdef mdarr7_t   cOres
  cdef femdarr7_t cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if   tval is mdnum7:
    o = val
    if res_flag:
      
      ores = out
      mdnum7_tan_to( &o.num, &ores.num)

    else:

      cores = mdnum7_tan( &o.num)
      res   = mdnum7.create(&cores)

    # end if 
  elif tval is mdnumfe7:
    f = val
    if res_flag:
      
      fres = out
      femdnum7_tan_to( &f.num, &fres.num)

    else:

      cfres = femdnum7_tan( &f.num)
      res   = mdnumfe7.create(&cfres)

    # end if  
  elif tval is mdmatfe7:    
    F = val
    if res_flag:

      Fres = out
      femdarr7_tan_to( &F.arr, &Fres.arr)

    else:

      cFres = femdarr7_tan( &F.arr)
      res   = mdmatfe7.create(&cFres)

    # end if 
  elif tval is mdmat7:
    O = val
    if res_flag:
      
      Ores = out
      mdarr7_tan_to( &O.arr, &Ores.arr)

    else:

      cOres = mdarr7_tan( &O.arr)
      res   = mdmat7.create(&cOres)

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

      -  mdmat7
      -  mdmatfe7
      -  darr
      -  mdnum7
      -  mdnumfe7
      -  real
  """
  #***************************************************************************************************

  cdef mdmat7      O, Ores
  cdef dmat       R, Rres
  cdef mdmatfe7    F, Fres
  cdef mdnum7    o, ores
  cdef coeff_t    r, rres
  cdef mdnumfe7     f, fres
  cdef coeff_t   crres
  cdef mdnum7_t cores
  cdef femdnum7_t  cfres
  cdef darr_t    cRres
  cdef mdarr7_t   cOres
  cdef femdarr7_t cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if   tval is mdnum7:
    o = val
    if res_flag:
      
      ores = out
      mdnum7_acos_to( &o.num, &ores.num)

    else:

      cores = mdnum7_acos( &o.num)
      res   = mdnum7.create(&cores)

    # end if 
  elif tval is mdnumfe7:
    f = val
    if res_flag:
      
      fres = out
      femdnum7_acos_to( &f.num, &fres.num)

    else:

      cfres = femdnum7_acos( &f.num)
      res   = mdnumfe7.create(&cfres)

    # end if  
  elif tval is mdmatfe7:    
    F = val
    if res_flag:

      Fres = out
      femdarr7_acos_to( &F.arr, &Fres.arr)

    else:

      cFres = femdarr7_acos( &F.arr)
      res   = mdmatfe7.create(&cFres)

    # end if 
  elif tval is mdmat7:
    O = val
    if res_flag:
      
      Ores = out
      mdarr7_acos_to( &O.arr, &Ores.arr)

    else:

      cOres = mdarr7_acos( &O.arr)
      res   = mdmat7.create(&cOres)

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

      -  mdmat7
      -  mdmatfe7
      -  darr
      -  mdnum7
      -  mdnumfe7
      -  real
  """
  #***************************************************************************************************

  cdef mdmat7      O, Ores
  cdef dmat       R, Rres
  cdef mdmatfe7    F, Fres
  cdef mdnum7    o, ores
  cdef coeff_t    r, rres
  cdef mdnumfe7     f, fres
  cdef coeff_t   crres
  cdef mdnum7_t cores
  cdef femdnum7_t  cfres
  cdef darr_t    cRres
  cdef mdarr7_t   cOres
  cdef femdarr7_t cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if   tval is mdnum7:
    o = val
    if res_flag:
      
      ores = out
      mdnum7_asin_to( &o.num, &ores.num)

    else:

      cores = mdnum7_asin( &o.num)
      res   = mdnum7.create(&cores)

    # end if 
  elif tval is mdnumfe7:
    f = val
    if res_flag:
      
      fres = out
      femdnum7_asin_to( &f.num, &fres.num)

    else:

      cfres = femdnum7_asin( &f.num)
      res   = mdnumfe7.create(&cfres)

    # end if  
  elif tval is mdmatfe7:    
    F = val
    if res_flag:

      Fres = out
      femdarr7_asin_to( &F.arr, &Fres.arr)

    else:

      cFres = femdarr7_asin( &F.arr)
      res   = mdmatfe7.create(&cFres)

    # end if 
  elif tval is mdmat7:
    O = val
    if res_flag:
      
      Ores = out
      mdarr7_asin_to( &O.arr, &Ores.arr)

    else:

      cOres = mdarr7_asin( &O.arr)
      res   = mdmat7.create(&cOres)

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

      -  mdmat7
      -  mdmatfe7
      -  darr
      -  mdnum7
      -  mdnumfe7
      -  real
  """
  #***************************************************************************************************

  cdef mdmat7      O, Ores
  cdef dmat       R, Rres
  cdef mdmatfe7    F, Fres
  cdef mdnum7    o, ores
  cdef coeff_t    r, rres
  cdef mdnumfe7     f, fres
  cdef coeff_t   crres
  cdef mdnum7_t cores
  cdef femdnum7_t  cfres
  cdef darr_t    cRres
  cdef mdarr7_t   cOres
  cdef femdarr7_t cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if   tval is mdnum7:
    o = val
    if res_flag:
      
      ores = out
      mdnum7_atan_to( &o.num, &ores.num)

    else:

      cores = mdnum7_atan( &o.num)
      res   = mdnum7.create(&cores)

    # end if 
  elif tval is mdnumfe7:
    f = val
    if res_flag:
      
      fres = out
      femdnum7_atan_to( &f.num, &fres.num)

    else:

      cfres = femdnum7_atan( &f.num)
      res   = mdnumfe7.create(&cfres)

    # end if  
  elif tval is mdmatfe7:    
    F = val
    if res_flag:

      Fres = out
      femdarr7_atan_to( &F.arr, &Fres.arr)

    else:

      cFres = femdarr7_atan( &F.arr)
      res   = mdmatfe7.create(&cFres)

    # end if 
  elif tval is mdmat7:
    O = val
    if res_flag:
      
      Ores = out
      mdarr7_atan_to( &O.arr, &Ores.arr)

    else:

      cOres = mdarr7_atan( &O.arr)
      res   = mdmat7.create(&cOres)

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

      -  mdmat7
      -  mdmatfe7
      -  darr
      -  mdnum7
      -  mdnumfe7
      -  real
  """
  #***************************************************************************************************

  cdef mdmat7      O, Ores
  cdef dmat       R, Rres
  cdef mdmatfe7    F, Fres
  cdef mdnum7    o, ores
  cdef coeff_t    r, rres
  cdef mdnumfe7     f, fres
  cdef coeff_t   crres
  cdef mdnum7_t cores
  cdef femdnum7_t  cfres
  cdef darr_t    cRres
  cdef mdarr7_t   cOres
  cdef femdarr7_t cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if   tval is mdnum7:
    o = val
    if res_flag:
      
      ores = out
      mdnum7_sinh_to( &o.num, &ores.num)

    else:

      cores = mdnum7_sinh( &o.num)
      res   = mdnum7.create(&cores)

    # end if 
  elif tval is mdnumfe7:
    f = val
    if res_flag:
      
      fres = out
      femdnum7_sinh_to( &f.num, &fres.num)

    else:

      cfres = femdnum7_sinh( &f.num)
      res   = mdnumfe7.create(&cfres)

    # end if  
  elif tval is mdmatfe7:    
    F = val
    if res_flag:

      Fres = out
      femdarr7_sinh_to( &F.arr, &Fres.arr)

    else:

      cFres = femdarr7_sinh( &F.arr)
      res   = mdmatfe7.create(&cFres)

    # end if 
  elif tval is mdmat7:
    O = val
    if res_flag:
      
      Ores = out
      mdarr7_sinh_to( &O.arr, &Ores.arr)

    else:

      cOres = mdarr7_sinh( &O.arr)
      res   = mdmat7.create(&cOres)

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

      -  mdmat7
      -  mdmatfe7
      -  darr
      -  mdnum7
      -  mdnumfe7
      -  real
  """
  #***************************************************************************************************

  cdef mdmat7      O, Ores
  cdef dmat       R, Rres
  cdef mdmatfe7    F, Fres
  cdef mdnum7    o, ores
  cdef coeff_t    r, rres
  cdef mdnumfe7     f, fres
  cdef coeff_t   crres
  cdef mdnum7_t cores
  cdef femdnum7_t  cfres
  cdef darr_t    cRres
  cdef mdarr7_t   cOres
  cdef femdarr7_t cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if   tval is mdnum7:
    o = val
    if res_flag:
      
      ores = out
      mdnum7_cosh_to( &o.num, &ores.num)

    else:

      cores = mdnum7_cosh( &o.num)
      res   = mdnum7.create(&cores)

    # end if 
  elif tval is mdnumfe7:
    f = val
    if res_flag:
      
      fres = out
      femdnum7_cosh_to( &f.num, &fres.num)

    else:

      cfres = femdnum7_cosh( &f.num)
      res   = mdnumfe7.create(&cfres)

    # end if  
  elif tval is mdmatfe7:    
    F = val
    if res_flag:

      Fres = out
      femdarr7_cosh_to( &F.arr, &Fres.arr)

    else:

      cFres = femdarr7_cosh( &F.arr)
      res   = mdmatfe7.create(&cFres)

    # end if 
  elif tval is mdmat7:
    O = val
    if res_flag:
      
      Ores = out
      mdarr7_cosh_to( &O.arr, &Ores.arr)

    else:

      cOres = mdarr7_cosh( &O.arr)
      res   = mdmat7.create(&cOres)

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

      -  mdmat7
      -  mdmatfe7
      -  darr
      -  mdnum7
      -  mdnumfe7
      -  real
  """
  #***************************************************************************************************

  cdef mdmat7      O, Ores
  cdef dmat       R, Rres
  cdef mdmatfe7    F, Fres
  cdef mdnum7    o, ores
  cdef coeff_t    r, rres
  cdef mdnumfe7     f, fres
  cdef coeff_t   crres
  cdef mdnum7_t cores
  cdef femdnum7_t  cfres
  cdef darr_t    cRres
  cdef mdarr7_t   cOres
  cdef femdarr7_t cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if   tval is mdnum7:
    o = val
    if res_flag:
      
      ores = out
      mdnum7_tanh_to( &o.num, &ores.num)

    else:

      cores = mdnum7_tanh( &o.num)
      res   = mdnum7.create(&cores)

    # end if 
  elif tval is mdnumfe7:
    f = val
    if res_flag:
      
      fres = out
      femdnum7_tanh_to( &f.num, &fres.num)

    else:

      cfres = femdnum7_tanh( &f.num)
      res   = mdnumfe7.create(&cfres)

    # end if  
  elif tval is mdmatfe7:    
    F = val
    if res_flag:

      Fres = out
      femdarr7_tanh_to( &F.arr, &Fres.arr)

    else:

      cFres = femdarr7_tanh( &F.arr)
      res   = mdmatfe7.create(&cFres)

    # end if 
  elif tval is mdmat7:
    O = val
    if res_flag:
      
      Ores = out
      mdarr7_tanh_to( &O.arr, &Ores.arr)

    else:

      cOres = mdarr7_tanh( &O.arr)
      res   = mdmat7.create(&cOres)

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

      -  mdmat7
      -  mdmatfe7
      -  darr
      -  mdnum7
      -  mdnumfe7
      -  real
  """
  #***************************************************************************************************

  cdef mdmat7      O, Ores
  cdef dmat       R, Rres
  cdef mdmatfe7    F, Fres
  cdef mdnum7    o, ores
  cdef coeff_t    r, rres
  cdef mdnumfe7     f, fres
  cdef coeff_t   crres
  cdef mdnum7_t cores
  cdef femdnum7_t  cfres
  cdef darr_t    cRres
  cdef mdarr7_t   cOres
  cdef femdarr7_t cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if   tval is mdnum7:
    o = val
    if res_flag:
      
      ores = out
      mdnum7_acosh_to( &o.num, &ores.num)

    else:

      cores = mdnum7_acosh( &o.num)
      res   = mdnum7.create(&cores)

    # end if 
  elif tval is mdnumfe7:
    f = val
    if res_flag:
      
      fres = out
      femdnum7_acosh_to( &f.num, &fres.num)

    else:

      cfres = femdnum7_acosh( &f.num)
      res   = mdnumfe7.create(&cfres)

    # end if  
  elif tval is mdmatfe7:    
    F = val
    if res_flag:

      Fres = out
      femdarr7_acosh_to( &F.arr, &Fres.arr)

    else:

      cFres = femdarr7_acosh( &F.arr)
      res   = mdmatfe7.create(&cFres)

    # end if 
  elif tval is mdmat7:
    O = val
    if res_flag:
      
      Ores = out
      mdarr7_acosh_to( &O.arr, &Ores.arr)

    else:

      cOres = mdarr7_acosh( &O.arr)
      res   = mdmat7.create(&cOres)

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

      -  mdmat7
      -  mdmatfe7
      -  darr
      -  mdnum7
      -  mdnumfe7
      -  real
  """
  #***************************************************************************************************

  cdef mdmat7      O, Ores
  cdef dmat       R, Rres
  cdef mdmatfe7    F, Fres
  cdef mdnum7    o, ores
  cdef coeff_t    r, rres
  cdef mdnumfe7     f, fres
  cdef coeff_t   crres
  cdef mdnum7_t cores
  cdef femdnum7_t  cfres
  cdef darr_t    cRres
  cdef mdarr7_t   cOres
  cdef femdarr7_t cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if   tval is mdnum7:
    o = val
    if res_flag:
      
      ores = out
      mdnum7_asinh_to( &o.num, &ores.num)

    else:

      cores = mdnum7_asinh( &o.num)
      res   = mdnum7.create(&cores)

    # end if 
  elif tval is mdnumfe7:
    f = val
    if res_flag:
      
      fres = out
      femdnum7_asinh_to( &f.num, &fres.num)

    else:

      cfres = femdnum7_asinh( &f.num)
      res   = mdnumfe7.create(&cfres)

    # end if  
  elif tval is mdmatfe7:    
    F = val
    if res_flag:

      Fres = out
      femdarr7_asinh_to( &F.arr, &Fres.arr)

    else:

      cFres = femdarr7_asinh( &F.arr)
      res   = mdmatfe7.create(&cFres)

    # end if 
  elif tval is mdmat7:
    O = val
    if res_flag:
      
      Ores = out
      mdarr7_asinh_to( &O.arr, &Ores.arr)

    else:

      cOres = mdarr7_asinh( &O.arr)
      res   = mdmat7.create(&cOres)

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

      -  mdmat7
      -  mdmatfe7
      -  darr
      -  mdnum7
      -  mdnumfe7
      -  real
  """
  #***************************************************************************************************

  cdef mdmat7      O, Ores
  cdef dmat       R, Rres
  cdef mdmatfe7    F, Fres
  cdef mdnum7    o, ores
  cdef coeff_t    r, rres
  cdef mdnumfe7     f, fres
  cdef coeff_t   crres
  cdef mdnum7_t cores
  cdef femdnum7_t  cfres
  cdef darr_t    cRres
  cdef mdarr7_t   cOres
  cdef femdarr7_t cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if   tval is mdnum7:
    o = val
    if res_flag:
      
      ores = out
      mdnum7_atanh_to( &o.num, &ores.num)

    else:

      cores = mdnum7_atanh( &o.num)
      res   = mdnum7.create(&cores)

    # end if 
  elif tval is mdnumfe7:
    f = val
    if res_flag:
      
      fres = out
      femdnum7_atanh_to( &f.num, &fres.num)

    else:

      cfres = femdnum7_atanh( &f.num)
      res   = mdnumfe7.create(&cfres)

    # end if  
  elif tval is mdmatfe7:    
    F = val
    if res_flag:

      Fres = out
      femdarr7_atanh_to( &F.arr, &Fres.arr)

    else:

      cFres = femdarr7_atanh( &F.arr)
      res   = mdmatfe7.create(&cFres)

    # end if 
  elif tval is mdmat7:
    O = val
    if res_flag:
      
      Ores = out
      mdarr7_atanh_to( &O.arr, &Ores.arr)

    else:

      cOres = mdarr7_atanh( &O.arr)
      res   = mdmat7.create(&cOres)

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

      -  mdmat7
      -  mdmatfe7
      -  darr
      -  mdnum7
      -  mdnumfe7
      -  real
  """
  #***************************************************************************************************

  cdef mdmat7      O, Ores
  cdef dmat       R, Rres
  cdef mdmatfe7    F, Fres
  cdef mdnum7    o, ores
  cdef coeff_t    r, rres
  cdef mdnumfe7     f, fres
  cdef coeff_t   crres
  cdef mdnum7_t cores
  cdef femdnum7_t  cfres
  cdef darr_t    cRres
  cdef mdarr7_t   cOres
  cdef femdarr7_t cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if   tval is mdnum7:
    o = val
    if res_flag:
      
      ores = out
      mdnum7_exp_to( &o.num, &ores.num)

    else:

      cores = mdnum7_exp( &o.num)
      res   = mdnum7.create(&cores)

    # end if 
  elif tval is mdnumfe7:
    f = val
    if res_flag:
      
      fres = out
      femdnum7_exp_to( &f.num, &fres.num)

    else:

      cfres = femdnum7_exp( &f.num)
      res   = mdnumfe7.create(&cfres)

    # end if  
  elif tval is mdmatfe7:    
    F = val
    if res_flag:

      Fres = out
      femdarr7_exp_to( &F.arr, &Fres.arr)

    else:

      cFres = femdarr7_exp( &F.arr)
      res   = mdmatfe7.create(&cFres)

    # end if 
  elif tval is mdmat7:
    O = val
    if res_flag:
      
      Ores = out
      mdarr7_exp_to( &O.arr, &Ores.arr)

    else:

      cOres = mdarr7_exp( &O.arr)
      res   = mdmat7.create(&cOres)

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

      -  mdmat7
      -  mdmatfe7
      -  darr
      -  mdnum7
      -  mdnumfe7
      -  real

  INPUTS:

    - val: Value to evaluate. Must be a supported one of the supported types.
    - out: (optional) Holder of result, in order to avoid memory allocation.

  OUTPUTS:

    If out is not defined, then the result is a newlly allocated member containing the result.
  """
  #***************************************************************************************************

  cdef mdmat7      O, Ores
  cdef dmat       R, Rres
  cdef mdmatfe7    F, Fres
  cdef mdnum7    o, ores
  cdef coeff_t    r, rres
  cdef mdnumfe7     f, fres
  cdef coeff_t   crres
  cdef mdnum7_t cores
  cdef femdnum7_t  cfres
  cdef darr_t    cRres
  cdef mdarr7_t   cOres
  cdef femdarr7_t cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if   tval is mdnum7:
    o = val
    if res_flag:
      
      ores = out
      mdnum7_log_to( &o.num, &ores.num)

    else:

      cores = mdnum7_log( &o.num)
      res   = mdnum7.create(&cores)

    # end if 
  elif tval is mdnumfe7:
    f = val
    if res_flag:
      
      fres = out
      femdnum7_log_to( &f.num, &fres.num)

    else:

      cfres = femdnum7_log( &f.num)
      res   = mdnumfe7.create(&cfres)

    # end if  
  elif tval is mdmatfe7:    
    F = val
    if res_flag:

      Fres = out
      femdarr7_log_to( &F.arr, &Fres.arr)

    else:

      cFres = femdarr7_log( &F.arr)
      res   = mdmatfe7.create(&cFres)

    # end if 
  elif tval is mdmat7:
    O = val
    if res_flag:
      
      Ores = out
      mdarr7_log_to( &O.arr, &Ores.arr)

    else:

      cOres = mdarr7_log( &O.arr)
      res   = mdmat7.create(&cOres)

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

      -  mdmat7
      -  mdmatfe7
      -  darr
      -  mdnum7
      -  mdnumfe7
      -  real

  INPUTS:

    - val: Value to evaluate. Must be a supported one of the supported types.
    - out: (optional) Holder of result, in order to avoid memory allocation.

  OUTPUTS:

    If out is not defined, then the result is a newlly allocated member containing the result.
  """
  #***************************************************************************************************

  cdef mdmat7      O, Ores
  cdef dmat       R, Rres
  cdef mdmatfe7    F, Fres
  cdef mdnum7    o, ores
  cdef coeff_t    r, rres
  cdef mdnumfe7     f, fres
  cdef coeff_t   crres
  cdef mdnum7_t cores
  cdef femdnum7_t  cfres
  cdef darr_t    cRres
  cdef mdarr7_t   cOres
  cdef femdarr7_t cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if   tval is mdnum7:
    o = val
    if res_flag:
      
      ores = out
      mdnum7_log10_to( &o.num, &ores.num)

    else:

      cores = mdnum7_log10( &o.num)
      res   = mdnum7.create(&cores)

    # end if 
  elif tval is mdnumfe7:
    f = val
    if res_flag:
      
      fres = out
      femdnum7_log10_to( &f.num, &fres.num)

    else:

      cfres = femdnum7_log10( &f.num)
      res   = mdnumfe7.create(&cfres)

    # end if  
  elif tval is mdmatfe7:    
    F = val
    if res_flag:

      Fres = out
      femdarr7_log10_to( &F.arr, &Fres.arr)

    else:

      cFres = femdarr7_log10( &F.arr)
      res   = mdmatfe7.create(&cFres)

    # end if 
  elif tval is mdmat7:
    O = val
    if res_flag:
      
      Ores = out
      mdarr7_log10_to( &O.arr, &Ores.arr)

    else:

      cOres = mdarr7_log10( &O.arr)
      res   = mdmat7.create(&cOres)

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

      -  mdmat7
      -  mdmatfe7
      -  darr
      -  mdnum7
      -  mdnumfe7
      -  real

  INPUTS:

    - val: Value to evaluate. Must be a supported one of the supported types.
    - b:   Base.
    - out: (optional) Holder of result, in order to avoid memory allocation.

  OUTPUTS:

    If out is not defined, then the result is a newlly allocated member containing the result.
  """
  #***************************************************************************************************

  cdef mdmat7      O, Ores
  cdef dmat       R, Rres
  cdef mdmatfe7    F, Fres
  cdef mdnum7    o, ores
  cdef coeff_t    r, rres
  cdef mdnumfe7     f, fres
  cdef coeff_t   crres
  cdef mdnum7_t cores
  cdef femdnum7_t  cfres
  cdef darr_t    cRres
  cdef mdarr7_t   cOres
  cdef femdarr7_t cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if   tval is mdnum7:
    o = val
    if res_flag:
      
      ores = out
      mdnum7_logb_to( &o.num, b, &ores.num)

    else:

      cores = mdnum7_logb( &o.num, b)
      res   = mdnum7.create(&cores)

    # end if 
  elif tval is mdnumfe7:
    f = val
    if res_flag:
      
      fres = out
      femdnum7_logb_to( &f.num, b, &fres.num)

    else:

      cfres = femdnum7_logb( &f.num, b)
      res   = mdnumfe7.create(&cfres)

    # end if  
  elif tval is mdmatfe7:    
    F = val
    if res_flag:

      Fres = out
      femdarr7_logb_to( &F.arr, b, &Fres.arr)

    else:

      cFres = femdarr7_logb( &F.arr, b)
      res   = mdmatfe7.create(&cFres)

    # end if 
  elif tval is mdmat7:
    O = val
    if res_flag:
      
      Ores = out
      mdarr7_logb_to( &O.arr, b, &Ores.arr)

    else:

      cOres = mdarr7_logb( &O.arr, b)
      res   = mdmat7.create(&cOres)

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

      -  mdmat7
      -  mdmatfe7
      -  darr
      -  mdnum7
      -  mdnumfe7
      -  real

  INPUTS:

    - val: Value to evaluate. Must be a supported one of the supported types.
    - out: (optional) Holder of result, in order to avoid memory allocation.

  OUTPUTS:

    If out is not defined, then the result is a newlly allocated member containing the result.
  """
  #***************************************************************************************************

  cdef mdmat7      O, Ores
  cdef dmat       R, Rres
  cdef mdmatfe7    F, Fres
  cdef mdnum7    o, ores
  cdef coeff_t    r, rres
  cdef mdnumfe7     f, fres
  cdef coeff_t   crres
  cdef mdnum7_t cores
  cdef femdnum7_t  cfres
  cdef darr_t    cRres
  cdef mdarr7_t   cOres
  cdef femdarr7_t cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if   tval is mdnum7:
    o = val
    if res_flag:
      
      ores = out
      mdnum7_sqrt_to( &o.num, &ores.num)

    else:

      cores = mdnum7_sqrt( &o.num)
      res   = mdnum7.create(&cores)

    # end if 
  elif tval is mdnumfe7:
    f = val
    if res_flag:
      
      fres = out
      femdnum7_sqrt_to( &f.num, &fres.num)

    else:

      cfres = femdnum7_sqrt( &f.num)
      res   = mdnumfe7.create(&cfres)

    # end if  
  elif tval is mdmatfe7:    
    F = val
    if res_flag:

      Fres = out
      femdarr7_sqrt_to( &F.arr, &Fres.arr)

    else:

      cFres = femdarr7_sqrt( &F.arr)
      res   = mdmatfe7.create(&cFres)

    # end if 
  elif tval is mdmat7:
    O = val
    if res_flag:
      
      Ores = out
      mdarr7_sqrt_to( &O.arr, &Ores.arr)

    else:

      cOres = mdarr7_sqrt( &O.arr)
      res   = mdmat7.create(&cOres)

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

      -  mdmat7
      -  mdmatfe7
      -  darr
      -  mdnum7
      -  mdnumfe7
      -  real

  INPUTS:

    - val: Value to evaluate. Must be a supported one of the supported types.
    - out: (optional) Holder of result, in order to avoid memory allocation.

  OUTPUTS:

    If out is not defined, then the result is a newlly allocated member containing the result.
  """
  #***************************************************************************************************

  cdef mdmat7      O, Ores
  cdef dmat       R, Rres
  cdef mdmatfe7    F, Fres
  cdef mdnum7    o, ores
  cdef coeff_t    r, rres
  cdef mdnumfe7     f, fres
  cdef coeff_t   crres
  cdef mdnum7_t cores
  cdef femdnum7_t  cfres
  cdef darr_t    cRres
  cdef mdarr7_t   cOres
  cdef femdarr7_t cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if   tval is mdnum7:
    o = val
    if res_flag:
      
      ores = out
      mdnum7_cbrt_to( &o.num, &ores.num)

    else:

      cores = mdnum7_cbrt( &o.num)
      res   = mdnum7.create(&cores)

    # end if 
  elif tval is mdnumfe7:
    f = val
    if res_flag:
      
      fres = out
      femdnum7_cbrt_to( &f.num, &fres.num)

    else:

      cfres = femdnum7_cbrt( &f.num)
      res   = mdnumfe7.create(&cfres)

    # end if  
  elif tval is mdmatfe7:    
    F = val
    if res_flag:

      Fres = out
      femdarr7_cbrt_to( &F.arr, &Fres.arr)

    else:

      cFres = femdarr7_cbrt( &F.arr)
      res   = mdmatfe7.create(&cFres)

    # end if 
  elif tval is mdmat7:
    O = val
    if res_flag:
      
      Ores = out
      mdarr7_cbrt_to( &O.arr, &Ores.arr)

    else:

      cOres = mdarr7_cbrt( &O.arr)
      res   = mdmat7.create(&cOres)

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

      -  mdmat7
      -  mdmatfe7
      -  darr
      -  mdnum7
      -  mdnumfe7
      -  real

  INPUTS:

    - val: Value to evaluate. Must be a supported one of the supported types.
    - e:   exponent.
    - out: (optional) Holder of result, in order to avoid memory allocation.

  OUTPUTS:

    If out is not defined, then the result is a newlly allocated member containing the result.
  """
  #***************************************************************************************************

  cdef mdmat7      O, Ores
  cdef dmat       R, Rres
  cdef mdmatfe7    F, Fres
  cdef mdnum7    o, ores
  cdef coeff_t    r, rres
  cdef mdnumfe7     f, fres
  cdef coeff_t   crres
  cdef mdnum7_t cores
  cdef femdnum7_t  cfres
  cdef darr_t    cRres
  cdef mdarr7_t   cOres
  cdef femdarr7_t cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if   tval is mdnum7:
    o = val
    if res_flag:
      
      ores = out
      mdnum7_pow_to( &o.num, e, &ores.num)

    else:

      cores = mdnum7_pow( &o.num, e)
      res   = mdnum7.create(&cores)

    # end if 
  elif tval is mdnumfe7:
    f = val
    if res_flag:
      
      fres = out
      femdnum7_pow_to( &f.num, e, &fres.num)

    else:

      cfres = femdnum7_pow( &f.num, e)
      res   = mdnumfe7.create(&cfres)

    # end if  
  elif tval is mdmatfe7:    
    F = val
    if res_flag:

      Fres = out
      femdarr7_pow_to( &F.arr, e, &Fres.arr)

    else:

      cFres = femdarr7_pow( &F.arr, e)
      res   = mdmatfe7.create(&cFres)

    # end if 
  elif tval is mdmat7:
    O = val
    if res_flag:
      
      Ores = out
      mdarr7_pow_to( &O.arr, e, &Ores.arr)

    else:

      cOres = mdarr7_pow( &O.arr, e)
      res   = mdmat7.create(&cOres)

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
cpdef gauss_integrate(object val, mdnumfe7 w, object out = None ):
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
  

  cdef mdmat7      O, Ores
  cdef dmat       R, Rres
  cdef mdmatfe7    F, Fres
  cdef mdnum7    o, ores
  cdef coeff_t    r, rres
  cdef mdnumfe7     f, fres
  cdef coeff_t   crres
  cdef mdnum7_t cores
  cdef femdnum7_t  cfres
  cdef darr_t    cRres
  cdef mdarr7_t   cOres
  cdef femdarr7_t cFres 
  cdef uint8_t res_flag = 1
  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if

  if   tval is mdnumfe7:
    f = val
    if res_flag:
      
      ores = out
      femdnum7_integrate_f_to( &f.num, &w.num, &ores.num)

    else:

      cores = femdnum7_integrate_f( &f.num, &w.num)
      res   = mdnum7.create(&cores)

    # end if  
  elif tval is mdmatfe7:
    F = val
    if res_flag:

      Ores = out
      femdarr7_integrate_to( &F.arr, &w.num, &Ores.arr)

    else:

      cOres = femdarr7_integrate( &F.arr, &w.num)
      res   = mdmat7.create(&cOres)

    # end if 
  elif tval is mdnum7:
    o = val
    if res_flag:
      
      ores = out
      femdnum7_integrate_o_to( &o.num, &w.num, &ores.num)

    else:

      cores = femdnum7_integrate_o( &o.num, &w.num)
      res   = mdnum7.create(&cores)

    # end if
  else:
    try:
      r = val
      if res_flag:
        
        ores = out
        femdnum7_integrate_r_to( r, &w.num, &ores.num)

      else:

        cores = femdnum7_integrate_r( r, &w.num)
        res   = mdnum7.create(&cores)

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

      -  mdmat7
      -  mdmatfe7
      -  darr
      -  mdnum7
      -  mdnumfe7
      -  real
  """
  #***************************************************************************************************

  cdef mdmat7      O, Ores
  cdef dmat       R, Rres
  cdef mdmatfe7    F, Fres
  cdef mdnum7    o, ores
  cdef coeff_t    r, rres
  cdef mdnumfe7     f, fres
  cdef coeff_t   crres
  cdef mdnum7_t cores
  cdef femdnum7_t  cfres
  cdef darr_t    cRres
  cdef mdarr7_t   cOres
  cdef femdarr7_t cFres
  cdef uint8_t res_flag = 1
  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 
  #
  if   tval is mdnum7:
    o = val
    if res_flag:
      
      ores = out
      mdnum7_neg_to( &o.num, &ores.num)

    else:

      cores = mdnum7_neg( &o.num)
      res   = mdnum7.create(&cores)

    # end if 
  elif tval is mdnumfe7:
    f = val
    if res_flag:
      
      fres = out
      femdnum7_neg_to( &f.num, &fres.num)

    else:

      cfres = femdnum7_neg( &f.num)
      res   = mdnumfe7.create(&cfres)

    # end if         
  elif tval is mdmatfe7:    
    F = val
    if res_flag:

      Fres = out
      femdarr7_neg_to( &F.arr, &Fres.arr)

    else:

      cFres = femdarr7_neg( &F.arr)
      res   = mdmatfe7.create(&cFres)

    # end if 
  elif tval is mdmat7:
    O = val
    if res_flag:
      
      Ores = out
      mdarr7_neg_to( &O.arr, &Ores.arr)

    else:

      cOres = mdarr7_neg( &O.arr)
      res   = mdmat7.create(&cOres)

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
