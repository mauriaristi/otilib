#*****************************************************************************************************
cpdef erf(object val, object out = None):
  """
  PURPOSE:  Matrix determinant.
  
  Supported types:

      -  matso
      -  matsofe
      -  darr
      -  sotinum
      -  sotife
      -  real
  """
  #***************************************************************************************************

  cdef matso      O, Ores
  cdef dmat       R, Rres
  cdef matsofe    F, Fres
  cdef sotinum    o, ores
  cdef coeff_t    r, rres
  cdef sotife     f, fres
  cdef coeff_t   crres
  cdef sotinum_t cores
  cdef fesoti_t  cfres
  cdef darr_t    cRres
  cdef arrso_t   cOres
  cdef fearrso_t cFres
  cdef uint8_t res_flag = 1
  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 
  #
  if   tval is sotinum:
    o = val
    if res_flag:
      
      ores = out
      soti_erf_to( &o.num, &ores.num, dhl)

    else:

      cores = soti_erf( &o.num,  dhl)
      res   = sotinum.create(&cores)

    # end if 
  elif tval is sotife:
    f = val
    if res_flag:
      
      fres = out
      fesoti_erf_to( &f.num, &fres.num, dhl)

    else:

      cfres = fesoti_erf( &f.num,  dhl)
      res   = sotife.create(&cfres)

    # end if         
  elif tval is matsofe:    
    F = val
    if res_flag:

      Fres = out
      fearrso_erf_to( &F.arr, &Fres.arr, dhl)

    else:

      cFres = fearrso_erf( &F.arr, dhl)
      res   = matsofe.create(&cFres)

    # end if 
  elif tval is matso:
    O = val
    if res_flag:
      
      Ores = out
      arrso_erf_to( &O.arr, &Ores.arr, dhl)

    else:

      cOres = arrso_erf( &O.arr,  dhl)
      res   = matso.create(&cOres)

    # end if    
  elif tval is dmat:
    R = val
    if res_flag:
      
      Rres = out
      darr_erf_to( &R.arr, &Rres.arr)

    else:

      cRres = darr_cos( &R.arr )
      res = dmat.create( &cRres )

    # end if 
  elif tval in number_types:
    import math    
    r    = val
    rres = math.erf(r)
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
cpdef cos(object val, object out = None):
  """
  PURPOSE:  Matrix determinant.
  
  Supported types:

      -  matso
      -  matsofe
      -  darr
      -  sotinum
      -  sotife
      -  real
  """
  #***************************************************************************************************

  cdef matso      O, Ores
  cdef dmat       R, Rres
  cdef matsofe    F, Fres
  cdef sotinum    o, ores
  cdef coeff_t    r, rres
  cdef sotife     f, fres
  cdef coeff_t   crres
  cdef sotinum_t cores
  cdef fesoti_t  cfres
  cdef darr_t    cRres
  cdef arrso_t   cOres
  cdef fearrso_t cFres
  cdef uint8_t res_flag = 1
  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 
  #
  if   tval is sotinum:
    o = val
    if res_flag:
      
      ores = out
      soti_cos_to( &o.num, &ores.num, dhl)

    else:

      cores = soti_cos( &o.num,  dhl)
      res   = sotinum.create(&cores)

    # end if 
  elif tval is sotife:
    f = val
    if res_flag:
      
      fres = out
      fesoti_cos_to( &f.num, &fres.num, dhl)

    else:

      cfres = fesoti_cos( &f.num,  dhl)
      res   = sotife.create(&cfres)

    # end if         
  elif tval is matsofe:    
    F = val
    if res_flag:

      Fres = out
      fearrso_cos_to( &F.arr, &Fres.arr, dhl)

    else:

      cFres = fearrso_cos( &F.arr, dhl)
      res   = matsofe.create(&cFres)

    # end if 
  elif tval is matso:
    O = val
    if res_flag:
      
      Ores = out
      arrso_cos_to( &O.arr, &Ores.arr, dhl)

    else:

      cOres = arrso_cos( &O.arr,  dhl)
      res   = matso.create(&cOres)

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
      -  matsofe
      -  darr
      -  sotinum
      -  sotife
      -  real
  """
  #***************************************************************************************************

  cdef matso      O, Ores
  cdef dmat       R, Rres
  cdef matsofe    F, Fres
  cdef sotinum    o, ores
  cdef coeff_t    r, rres
  cdef sotife     f, fres
  cdef coeff_t   crres
  cdef sotinum_t cores
  cdef fesoti_t  cfres
  cdef darr_t    cRres
  cdef arrso_t   cOres
  cdef fearrso_t cFres
  cdef uint8_t res_flag = 1
  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if   tval is sotinum:
    o = val
    if res_flag:
      
      ores = out
      soti_sin_to( &o.num, &ores.num, dhl)

    else:

      cores = soti_sin( &o.num,  dhl)
      res   = sotinum.create(&cores)

    # end if 
  elif tval is sotife:
    f = val
    if res_flag:
      
      fres = out
      fesoti_sin_to( &f.num, &fres.num, dhl)

    else:

      cfres = fesoti_sin( &f.num,  dhl)
      res   = sotife.create(&cfres)

    # end if  
  elif tval is matsofe:    
    F = val
    if res_flag:

      Fres = out
      fearrso_sin_to( &F.arr, &Fres.arr, dhl)

    else:

      cFres = fearrso_sin( &F.arr, dhl)
      res   = matsofe.create(&cFres)

    # end if 
  elif tval is matso:
    O = val
    if res_flag:
      
      Ores = out
      arrso_sin_to( &O.arr, &Ores.arr, dhl)

    else:

      cOres = arrso_sin( &O.arr,  dhl)
      res   = matso.create(&cOres)

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
      -  matsofe
      -  darr
      -  sotinum
      -  sotife
      -  real
  """
  #***************************************************************************************************

  cdef matso      O, Ores
  cdef dmat       R, Rres
  cdef matsofe    F, Fres
  cdef sotinum    o, ores
  cdef coeff_t    r, rres
  cdef sotife     f, fres
  cdef coeff_t   crres
  cdef sotinum_t cores
  cdef fesoti_t  cfres
  cdef darr_t    cRres
  cdef arrso_t   cOres
  cdef fearrso_t cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if   tval is sotinum:
    o = val
    if res_flag:
      
      ores = out
      soti_tan_to( &o.num, &ores.num, dhl)

    else:

      cores = soti_tan( &o.num,  dhl)
      res   = sotinum.create(&cores)

    # end if 
  elif tval is sotife:
    f = val
    if res_flag:
      
      fres = out
      fesoti_tan_to( &f.num, &fres.num, dhl)

    else:

      cfres = fesoti_tan( &f.num,  dhl)
      res   = sotife.create(&cfres)

    # end if  
  elif tval is matsofe:    
    F = val
    if res_flag:

      Fres = out
      fearrso_tan_to( &F.arr, &Fres.arr, dhl)

    else:

      cFres = fearrso_tan( &F.arr, dhl)
      res   = matsofe.create(&cFres)

    # end if 
  elif tval is matso:
    O = val
    if res_flag:
      
      Ores = out
      arrso_tan_to( &O.arr, &Ores.arr, dhl)

    else:

      cOres = arrso_tan( &O.arr,  dhl)
      res   = matso.create(&cOres)

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
      -  matsofe
      -  darr
      -  sotinum
      -  sotife
      -  real
  """
  #***************************************************************************************************

  cdef matso      O, Ores
  cdef dmat       R, Rres
  cdef matsofe    F, Fres
  cdef sotinum    o, ores
  cdef coeff_t    r, rres
  cdef sotife     f, fres
  cdef coeff_t   crres
  cdef sotinum_t cores
  cdef fesoti_t  cfres
  cdef darr_t    cRres
  cdef arrso_t   cOres
  cdef fearrso_t cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if   tval is sotinum:
    o = val
    if res_flag:
      
      ores = out
      soti_acos_to( &o.num, &ores.num, dhl)

    else:

      cores = soti_acos( &o.num,  dhl)
      res   = sotinum.create(&cores)

    # end if 
  elif tval is sotife:
    f = val
    if res_flag:
      
      fres = out
      fesoti_acos_to( &f.num, &fres.num, dhl)

    else:

      cfres = fesoti_acos( &f.num,  dhl)
      res   = sotife.create(&cfres)

    # end if  
  elif tval is matsofe:    
    F = val
    if res_flag:

      Fres = out
      fearrso_acos_to( &F.arr, &Fres.arr, dhl)

    else:

      cFres = fearrso_acos( &F.arr, dhl)
      res   = matsofe.create(&cFres)

    # end if 
  elif tval is matso:
    O = val
    if res_flag:
      
      Ores = out
      arrso_acos_to( &O.arr, &Ores.arr, dhl)

    else:

      cOres = arrso_acos( &O.arr,  dhl)
      res   = matso.create(&cOres)

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
      -  matsofe
      -  darr
      -  sotinum
      -  sotife
      -  real
  """
  #***************************************************************************************************

  cdef matso      O, Ores
  cdef dmat       R, Rres
  cdef matsofe    F, Fres
  cdef sotinum    o, ores
  cdef coeff_t    r, rres
  cdef sotife     f, fres
  cdef coeff_t   crres
  cdef sotinum_t cores
  cdef fesoti_t  cfres
  cdef darr_t    cRres
  cdef arrso_t   cOres
  cdef fearrso_t cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if   tval is sotinum:
    o = val
    if res_flag:
      
      ores = out
      soti_asin_to( &o.num, &ores.num, dhl)

    else:

      cores = soti_asin( &o.num,  dhl)
      res   = sotinum.create(&cores)

    # end if 
  elif tval is sotife:
    f = val
    if res_flag:
      
      fres = out
      fesoti_asin_to( &f.num, &fres.num, dhl)

    else:

      cfres = fesoti_asin( &f.num,  dhl)
      res   = sotife.create(&cfres)

    # end if  
  elif tval is matsofe:    
    F = val
    if res_flag:

      Fres = out
      fearrso_asin_to( &F.arr, &Fres.arr, dhl)

    else:

      cFres = fearrso_asin( &F.arr, dhl)
      res   = matsofe.create(&cFres)

    # end if 
  elif tval is matso:
    O = val
    if res_flag:
      
      Ores = out
      arrso_asin_to( &O.arr, &Ores.arr, dhl)

    else:

      cOres = arrso_asin( &O.arr,  dhl)
      res   = matso.create(&cOres)

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
      -  matsofe
      -  darr
      -  sotinum
      -  sotife
      -  real
  """
  #***************************************************************************************************

  cdef matso      O, Ores
  cdef dmat       R, Rres
  cdef matsofe    F, Fres
  cdef sotinum    o, ores
  cdef coeff_t    r, rres
  cdef sotife     f, fres
  cdef coeff_t   crres
  cdef sotinum_t cores
  cdef fesoti_t  cfres
  cdef darr_t    cRres
  cdef arrso_t   cOres
  cdef fearrso_t cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if   tval is sotinum:
    o = val
    if res_flag:
      
      ores = out
      soti_atan_to( &o.num, &ores.num, dhl)

    else:

      cores = soti_atan( &o.num,  dhl)
      res   = sotinum.create(&cores)

    # end if 
  elif tval is sotife:
    f = val
    if res_flag:
      
      fres = out
      fesoti_atan_to( &f.num, &fres.num, dhl)

    else:

      cfres = fesoti_atan( &f.num,  dhl)
      res   = sotife.create(&cfres)

    # end if  
  elif tval is matsofe:    
    F = val
    if res_flag:

      Fres = out
      fearrso_atan_to( &F.arr, &Fres.arr, dhl)

    else:

      cFres = fearrso_atan( &F.arr, dhl)
      res   = matsofe.create(&cFres)

    # end if 
  elif tval is matso:
    O = val
    if res_flag:
      
      Ores = out
      arrso_atan_to( &O.arr, &Ores.arr, dhl)

    else:

      cOres = arrso_atan( &O.arr,  dhl)
      res   = matso.create(&cOres)

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
      -  matsofe
      -  darr
      -  sotinum
      -  sotife
      -  real
  """
  #***************************************************************************************************

  cdef matso      O, Ores
  cdef dmat       R, Rres
  cdef matsofe    F, Fres
  cdef sotinum    o, ores
  cdef coeff_t    r, rres
  cdef sotife     f, fres
  cdef coeff_t   crres
  cdef sotinum_t cores
  cdef fesoti_t  cfres
  cdef darr_t    cRres
  cdef arrso_t   cOres
  cdef fearrso_t cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if   tval is sotinum:
    o = val
    if res_flag:
      
      ores = out
      soti_sinh_to( &o.num, &ores.num, dhl)

    else:

      cores = soti_sinh( &o.num,  dhl)
      res   = sotinum.create(&cores)

    # end if 
  elif tval is sotife:
    f = val
    if res_flag:
      
      fres = out
      fesoti_sinh_to( &f.num, &fres.num, dhl)

    else:

      cfres = fesoti_sinh( &f.num,  dhl)
      res   = sotife.create(&cfres)

    # end if  
  elif tval is matsofe:    
    F = val
    if res_flag:

      Fres = out
      fearrso_sinh_to( &F.arr, &Fres.arr, dhl)

    else:

      cFres = fearrso_sinh( &F.arr, dhl)
      res   = matsofe.create(&cFres)

    # end if 
  elif tval is matso:
    O = val
    if res_flag:
      
      Ores = out
      arrso_sinh_to( &O.arr, &Ores.arr, dhl)

    else:

      cOres = arrso_sinh( &O.arr,  dhl)
      res   = matso.create(&cOres)

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
      -  matsofe
      -  darr
      -  sotinum
      -  sotife
      -  real
  """
  #***************************************************************************************************

  cdef matso      O, Ores
  cdef dmat       R, Rres
  cdef matsofe    F, Fres
  cdef sotinum    o, ores
  cdef coeff_t    r, rres
  cdef sotife     f, fres
  cdef coeff_t   crres
  cdef sotinum_t cores
  cdef fesoti_t  cfres
  cdef darr_t    cRres
  cdef arrso_t   cOres
  cdef fearrso_t cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if   tval is sotinum:
    o = val
    if res_flag:
      
      ores = out
      soti_cosh_to( &o.num, &ores.num, dhl)

    else:

      cores = soti_cosh( &o.num,  dhl)
      res   = sotinum.create(&cores)

    # end if 
  elif tval is sotife:
    f = val
    if res_flag:
      
      fres = out
      fesoti_cosh_to( &f.num, &fres.num, dhl)

    else:

      cfres = fesoti_cosh( &f.num,  dhl)
      res   = sotife.create(&cfres)

    # end if  
  elif tval is matsofe:    
    F = val
    if res_flag:

      Fres = out
      fearrso_cosh_to( &F.arr, &Fres.arr, dhl)

    else:

      cFres = fearrso_cosh( &F.arr, dhl)
      res   = matsofe.create(&cFres)

    # end if 
  elif tval is matso:
    O = val
    if res_flag:
      
      Ores = out
      arrso_cosh_to( &O.arr, &Ores.arr, dhl)

    else:

      cOres = arrso_cosh( &O.arr,  dhl)
      res   = matso.create(&cOres)

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
      -  matsofe
      -  darr
      -  sotinum
      -  sotife
      -  real
  """
  #***************************************************************************************************

  cdef matso      O, Ores
  cdef dmat       R, Rres
  cdef matsofe    F, Fres
  cdef sotinum    o, ores
  cdef coeff_t    r, rres
  cdef sotife     f, fres
  cdef coeff_t   crres
  cdef sotinum_t cores
  cdef fesoti_t  cfres
  cdef darr_t    cRres
  cdef arrso_t   cOres
  cdef fearrso_t cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if   tval is sotinum:
    o = val
    if res_flag:
      
      ores = out
      soti_tanh_to( &o.num, &ores.num, dhl)

    else:

      cores = soti_tanh( &o.num,  dhl)
      res   = sotinum.create(&cores)

    # end if 
  elif tval is sotife:
    f = val
    if res_flag:
      
      fres = out
      fesoti_tanh_to( &f.num, &fres.num, dhl)

    else:

      cfres = fesoti_tanh( &f.num,  dhl)
      res   = sotife.create(&cfres)

    # end if  
  elif tval is matsofe:    
    F = val
    if res_flag:

      Fres = out
      fearrso_tanh_to( &F.arr, &Fres.arr, dhl)

    else:

      cFres = fearrso_tanh( &F.arr, dhl)
      res   = matsofe.create(&cFres)

    # end if 
  elif tval is matso:
    O = val
    if res_flag:
      
      Ores = out
      arrso_tanh_to( &O.arr, &Ores.arr, dhl)

    else:

      cOres = arrso_tanh( &O.arr,  dhl)
      res   = matso.create(&cOres)

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
      -  matsofe
      -  darr
      -  sotinum
      -  sotife
      -  real
  """
  #***************************************************************************************************

  cdef matso      O, Ores
  cdef dmat       R, Rres
  cdef matsofe    F, Fres
  cdef sotinum    o, ores
  cdef coeff_t    r, rres
  cdef sotife     f, fres
  cdef coeff_t   crres
  cdef sotinum_t cores
  cdef fesoti_t  cfres
  cdef darr_t    cRres
  cdef arrso_t   cOres
  cdef fearrso_t cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if   tval is sotinum:
    o = val
    if res_flag:
      
      ores = out
      soti_acosh_to( &o.num, &ores.num, dhl)

    else:

      cores = soti_acosh( &o.num,  dhl)
      res   = sotinum.create(&cores)

    # end if 
  elif tval is sotife:
    f = val
    if res_flag:
      
      fres = out
      fesoti_acosh_to( &f.num, &fres.num, dhl)

    else:

      cfres = fesoti_acosh( &f.num,  dhl)
      res   = sotife.create(&cfres)

    # end if  
  elif tval is matsofe:    
    F = val
    if res_flag:

      Fres = out
      fearrso_acosh_to( &F.arr, &Fres.arr, dhl)

    else:

      cFres = fearrso_acosh( &F.arr, dhl)
      res   = matsofe.create(&cFres)

    # end if 
  elif tval is matso:
    O = val
    if res_flag:
      
      Ores = out
      arrso_acosh_to( &O.arr, &Ores.arr, dhl)

    else:

      cOres = arrso_acosh( &O.arr,  dhl)
      res   = matso.create(&cOres)

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
      -  matsofe
      -  darr
      -  sotinum
      -  sotife
      -  real
  """
  #***************************************************************************************************

  cdef matso      O, Ores
  cdef dmat       R, Rres
  cdef matsofe    F, Fres
  cdef sotinum    o, ores
  cdef coeff_t    r, rres
  cdef sotife     f, fres
  cdef coeff_t   crres
  cdef sotinum_t cores
  cdef fesoti_t  cfres
  cdef darr_t    cRres
  cdef arrso_t   cOres
  cdef fearrso_t cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if   tval is sotinum:
    o = val
    if res_flag:
      
      ores = out
      soti_asinh_to( &o.num, &ores.num, dhl)

    else:

      cores = soti_asinh( &o.num,  dhl)
      res   = sotinum.create(&cores)

    # end if 
  elif tval is sotife:
    f = val
    if res_flag:
      
      fres = out
      fesoti_asinh_to( &f.num, &fres.num, dhl)

    else:

      cfres = fesoti_asinh( &f.num,  dhl)
      res   = sotife.create(&cfres)

    # end if  
  elif tval is matsofe:    
    F = val
    if res_flag:

      Fres = out
      fearrso_asinh_to( &F.arr, &Fres.arr, dhl)

    else:

      cFres = fearrso_asinh( &F.arr, dhl)
      res   = matsofe.create(&cFres)

    # end if 
  elif tval is matso:
    O = val
    if res_flag:
      
      Ores = out
      arrso_asinh_to( &O.arr, &Ores.arr, dhl)

    else:

      cOres = arrso_asinh( &O.arr,  dhl)
      res   = matso.create(&cOres)

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
      -  matsofe
      -  darr
      -  sotinum
      -  sotife
      -  real
  """
  #***************************************************************************************************

  cdef matso      O, Ores
  cdef dmat       R, Rres
  cdef matsofe    F, Fres
  cdef sotinum    o, ores
  cdef coeff_t    r, rres
  cdef sotife     f, fres
  cdef coeff_t   crres
  cdef sotinum_t cores
  cdef fesoti_t  cfres
  cdef darr_t    cRres
  cdef arrso_t   cOres
  cdef fearrso_t cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if   tval is sotinum:
    o = val
    if res_flag:
      
      ores = out
      soti_atanh_to( &o.num, &ores.num, dhl)

    else:

      cores = soti_atanh( &o.num,  dhl)
      res   = sotinum.create(&cores)

    # end if 
  elif tval is sotife:
    f = val
    if res_flag:
      
      fres = out
      fesoti_atanh_to( &f.num, &fres.num, dhl)

    else:

      cfres = fesoti_atanh( &f.num,  dhl)
      res   = sotife.create(&cfres)

    # end if  
  elif tval is matsofe:    
    F = val
    if res_flag:

      Fres = out
      fearrso_atanh_to( &F.arr, &Fres.arr, dhl)

    else:

      cFres = fearrso_atanh( &F.arr, dhl)
      res   = matsofe.create(&cFres)

    # end if 
  elif tval is matso:
    O = val
    if res_flag:
      
      Ores = out
      arrso_atanh_to( &O.arr, &Ores.arr, dhl)

    else:

      cOres = arrso_atanh( &O.arr,  dhl)
      res   = matso.create(&cOres)

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
      -  matsofe
      -  darr
      -  sotinum
      -  sotife
      -  real
  """
  #***************************************************************************************************

  cdef matso      O, Ores
  cdef dmat       R, Rres
  cdef matsofe    F, Fres
  cdef sotinum    o, ores
  cdef coeff_t    r, rres
  cdef sotife     f, fres
  cdef coeff_t   crres
  cdef sotinum_t cores
  cdef fesoti_t  cfres
  cdef darr_t    cRres
  cdef arrso_t   cOres
  cdef fearrso_t cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if   tval is sotinum:
    o = val
    if res_flag:
      
      ores = out
      soti_exp_to( &o.num, &ores.num, dhl)

    else:

      cores = soti_exp( &o.num,  dhl)
      res   = sotinum.create(&cores)

    # end if 
  elif tval is sotife:
    f = val
    if res_flag:
      
      fres = out
      fesoti_exp_to( &f.num, &fres.num, dhl)

    else:

      cfres = fesoti_exp( &f.num,  dhl)
      res   = sotife.create(&cfres)

    # end if  
  elif tval is matsofe:    
    F = val
    if res_flag:

      Fres = out
      fearrso_exp_to( &F.arr, &Fres.arr, dhl)

    else:

      cFres = fearrso_exp( &F.arr, dhl)
      res   = matsofe.create(&cFres)

    # end if 
  elif tval is matso:
    O = val
    if res_flag:
      
      Ores = out
      arrso_exp_to( &O.arr, &Ores.arr, dhl)

    else:

      cOres = arrso_exp( &O.arr,  dhl)
      res   = matso.create(&cOres)

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
      -  matsofe
      -  darr
      -  sotinum
      -  sotife
      -  real

  INPUTS:

    - val: Value to evaluate. Must be a supported one of the supported types.
    - out: (optional) Holder of result, in order to avoid memory allocation.

  OUTPUTS:

    If out is not defined, then the result is a newlly allocated member containing the result.
  """
  #***************************************************************************************************

  cdef matso      O, Ores
  cdef dmat       R, Rres
  cdef matsofe    F, Fres
  cdef sotinum    o, ores
  cdef coeff_t    r, rres
  cdef sotife     f, fres
  cdef coeff_t   crres
  cdef sotinum_t cores
  cdef fesoti_t  cfres
  cdef darr_t    cRres
  cdef arrso_t   cOres
  cdef fearrso_t cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if   tval is sotinum:
    o = val
    if res_flag:
      
      ores = out
      soti_log_to( &o.num, &ores.num, dhl)

    else:

      cores = soti_log( &o.num,  dhl)
      res   = sotinum.create(&cores)

    # end if 
  elif tval is sotife:
    f = val
    if res_flag:
      
      fres = out
      fesoti_log_to( &f.num, &fres.num, dhl)

    else:

      cfres = fesoti_log( &f.num,  dhl)
      res   = sotife.create(&cfres)

    # end if  
  elif tval is matsofe:    
    F = val
    if res_flag:

      Fres = out
      fearrso_log_to( &F.arr, &Fres.arr, dhl)

    else:

      cFres = fearrso_log( &F.arr, dhl)
      res   = matsofe.create(&cFres)

    # end if 
  elif tval is matso:
    O = val
    if res_flag:
      
      Ores = out
      arrso_log_to( &O.arr, &Ores.arr, dhl)

    else:

      cOres = arrso_log( &O.arr,  dhl)
      res   = matso.create(&cOres)

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
      -  matsofe
      -  darr
      -  sotinum
      -  sotife
      -  real

  INPUTS:

    - val: Value to evaluate. Must be a supported one of the supported types.
    - out: (optional) Holder of result, in order to avoid memory allocation.

  OUTPUTS:

    If out is not defined, then the result is a newlly allocated member containing the result.
  """
  #***************************************************************************************************

  cdef matso      O, Ores
  cdef dmat       R, Rres
  cdef matsofe    F, Fres
  cdef sotinum    o, ores
  cdef coeff_t    r, rres
  cdef sotife     f, fres
  cdef coeff_t   crres
  cdef sotinum_t cores
  cdef fesoti_t  cfres
  cdef darr_t    cRres
  cdef arrso_t   cOres
  cdef fearrso_t cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if   tval is sotinum:
    o = val
    if res_flag:
      
      ores = out
      soti_log10_to( &o.num, &ores.num, dhl)

    else:

      cores = soti_log10( &o.num,  dhl)
      res   = sotinum.create(&cores)

    # end if 
  elif tval is sotife:
    f = val
    if res_flag:
      
      fres = out
      fesoti_log10_to( &f.num, &fres.num, dhl)

    else:

      cfres = fesoti_log10( &f.num,  dhl)
      res   = sotife.create(&cfres)

    # end if  
  elif tval is matsofe:    
    F = val
    if res_flag:

      Fres = out
      fearrso_log10_to( &F.arr, &Fres.arr, dhl)

    else:

      cFres = fearrso_log10( &F.arr, dhl)
      res   = matsofe.create(&cFres)

    # end if 
  elif tval is matso:
    O = val
    if res_flag:
      
      Ores = out
      arrso_log10_to( &O.arr, &Ores.arr, dhl)

    else:

      cOres = arrso_log10( &O.arr,  dhl)
      res   = matso.create(&cOres)

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
      -  matsofe
      -  darr
      -  sotinum
      -  sotife
      -  real

  INPUTS:

    - val: Value to evaluate. Must be a supported one of the supported types.
    - b:   Base.
    - out: (optional) Holder of result, in order to avoid memory allocation.

  OUTPUTS:

    If out is not defined, then the result is a newlly allocated member containing the result.
  """
  #***************************************************************************************************

  cdef matso      O, Ores
  cdef dmat       R, Rres
  cdef matsofe    F, Fres
  cdef sotinum    o, ores
  cdef coeff_t    r, rres
  cdef sotife     f, fres
  cdef coeff_t   crres
  cdef sotinum_t cores
  cdef fesoti_t  cfres
  cdef darr_t    cRres
  cdef arrso_t   cOres
  cdef fearrso_t cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if   tval is sotinum:
    o = val
    if res_flag:
      
      ores = out
      soti_logb_to( &o.num, b, &ores.num, dhl)

    else:

      cores = soti_logb( &o.num, b,  dhl)
      res   = sotinum.create(&cores)

    # end if 
  elif tval is sotife:
    f = val
    if res_flag:
      
      fres = out
      fesoti_logb_to( &f.num, b, &fres.num, dhl)

    else:

      cfres = fesoti_logb( &f.num, b,  dhl)
      res   = sotife.create(&cfres)

    # end if  
  elif tval is matsofe:    
    F = val
    if res_flag:

      Fres = out
      fearrso_logb_to( &F.arr, b, &Fres.arr, dhl)

    else:

      cFres = fearrso_logb( &F.arr, b, dhl)
      res   = matsofe.create(&cFres)

    # end if 
  elif tval is matso:
    O = val
    if res_flag:
      
      Ores = out
      arrso_logb_to( &O.arr, b, &Ores.arr, dhl)

    else:

      cOres = arrso_logb( &O.arr, b,  dhl)
      res   = matso.create(&cOres)

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
      -  matsofe
      -  darr
      -  sotinum
      -  sotife
      -  real

  INPUTS:

    - val: Value to evaluate. Must be a supported one of the supported types.
    - out: (optional) Holder of result, in order to avoid memory allocation.

  OUTPUTS:

    If out is not defined, then the result is a newlly allocated member containing the result.
  """
  #***************************************************************************************************

  cdef matso      O, Ores
  cdef dmat       R, Rres
  cdef matsofe    F, Fres
  cdef sotinum    o, ores
  cdef coeff_t    r, rres
  cdef sotife     f, fres
  cdef coeff_t   crres
  cdef sotinum_t cores
  cdef fesoti_t  cfres
  cdef darr_t    cRres
  cdef arrso_t   cOres
  cdef fearrso_t cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if   tval is sotinum:
    o = val
    if res_flag:
      
      ores = out
      soti_sqrt_to( &o.num, &ores.num, dhl)

    else:

      cores = soti_sqrt( &o.num,  dhl)
      res   = sotinum.create(&cores)

    # end if 
  elif tval is sotife:
    f = val
    if res_flag:
      
      fres = out
      fesoti_sqrt_to( &f.num, &fres.num, dhl)

    else:

      cfres = fesoti_sqrt( &f.num,  dhl)
      res   = sotife.create(&cfres)

    # end if  
  elif tval is matsofe:    
    F = val
    if res_flag:

      Fres = out
      fearrso_sqrt_to( &F.arr, &Fres.arr, dhl)

    else:

      cFres = fearrso_sqrt( &F.arr, dhl)
      res   = matsofe.create(&cFres)

    # end if 
  elif tval is matso:
    O = val
    if res_flag:
      
      Ores = out
      arrso_sqrt_to( &O.arr, &Ores.arr, dhl)

    else:

      cOres = arrso_sqrt( &O.arr,  dhl)
      res   = matso.create(&cOres)

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
      -  matsofe
      -  darr
      -  sotinum
      -  sotife
      -  real

  INPUTS:

    - val: Value to evaluate. Must be a supported one of the supported types.
    - out: (optional) Holder of result, in order to avoid memory allocation.

  OUTPUTS:

    If out is not defined, then the result is a newlly allocated member containing the result.
  """
  #***************************************************************************************************

  cdef matso      O, Ores
  cdef dmat       R, Rres
  cdef matsofe    F, Fres
  cdef sotinum    o, ores
  cdef coeff_t    r, rres
  cdef sotife     f, fres
  cdef coeff_t   crres
  cdef sotinum_t cores
  cdef fesoti_t  cfres
  cdef darr_t    cRres
  cdef arrso_t   cOres
  cdef fearrso_t cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if   tval is sotinum:
    o = val
    if res_flag:
      
      ores = out
      soti_cbrt_to( &o.num, &ores.num, dhl)

    else:

      cores = soti_cbrt( &o.num,  dhl)
      res   = sotinum.create(&cores)

    # end if 
  elif tval is sotife:
    f = val
    if res_flag:
      
      fres = out
      fesoti_cbrt_to( &f.num, &fres.num, dhl)

    else:

      cfres = fesoti_cbrt( &f.num,  dhl)
      res   = sotife.create(&cfres)

    # end if  
  elif tval is matsofe:    
    F = val
    if res_flag:

      Fres = out
      fearrso_cbrt_to( &F.arr, &Fres.arr, dhl)

    else:

      cFres = fearrso_cbrt( &F.arr, dhl)
      res   = matsofe.create(&cFres)

    # end if 
  elif tval is matso:
    O = val
    if res_flag:
      
      Ores = out
      arrso_cbrt_to( &O.arr, &Ores.arr, dhl)

    else:

      cOres = arrso_cbrt( &O.arr,  dhl)
      res   = matso.create(&cOres)

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
cpdef pow(object val, object e, object out = None):
  """
  PURPOSE:  Power function.
  
  Supported types:

      -  matso
      -  matsofe
      -  darr
      -  sotinum
      -  sotife
      -  real

  INPUTS:

    - val: Value to evaluate. Must be a supported one of the supported types.
    - e:   exponent.
    - out: (optional) Holder of result, in order to avoid memory allocation.

  OUTPUTS:

    If out is not defined, then the result is a newlly allocated member containing the result.
  """
  #***************************************************************************************************

  cdef object res = None
  te   = type(e)

  if   te is sotinum:

    res = __pow__sotinumexp( val, e, out = out)

  elif   te is matso:

    res = __pow__matsoexp( val, e, out = out) 

  else:

    res = __pow__realexp( val, e, out = out)
    
  # end if 

  return res

#-----------------------------------------------------------------------------------------------------


#*****************************************************************************************************
cdef object __pow__realexp(object val, coeff_t e, object out = None):
  """
  cpdef __pow__realexp(object val, coeff_t e, object out = None)

  Power function x**e, where e is a real coefficient.
  
  Supported types:

      -  matso
      -  matsofe
      -  darr
      -  sotinum
      -  sotife
      -  real

  :param val: Power base. Must be a supported types.
  :param e:   exponent.
  :param out: (optional) Holder of result, in order to avoid memory allocation.

  If out is not defined, then the result is a newlly allocated member containing the result.

  """
  #***************************************************************************************************

  cdef matso      O, Ores
  cdef dmat       R, Rres
  cdef matsofe    F, Fres
  cdef sotinum    o, ores
  cdef coeff_t    r, rres
  cdef sotife     f, fres
  cdef coeff_t   crres
  cdef sotinum_t cores
  cdef fesoti_t  cfres
  cdef darr_t    cRres
  cdef arrso_t   cOres
  cdef fearrso_t cFres  
  cdef sotinum e_oti
  cdef matso e_matso

  cdef uint8_t res_flag = 1

  cdef object res = None

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  if   tval is sotinum:

    o = val
    if res_flag:
      
      ores = out
      soti_pow_to( &o.num, e, &ores.num, dhl)

    else:

      cores = soti_pow( &o.num, e,  dhl)
      res   = sotinum.create(&cores)

    # end if 

  elif tval is sotife:

    f = val
    if res_flag:
      
      fres = out
      fesoti_pow_to( &f.num, e, &fres.num, dhl)

    else:

      cfres = fesoti_pow( &f.num, e,  dhl)
      res   = sotife.create(&cfres)

    # end if 

  elif tval is matsofe:  

    F = val
    if res_flag:

      Fres = out
      fearrso_pow_to( &F.arr, e, &Fres.arr, dhl)

    else:

      cFres = fearrso_pow( &F.arr, e, dhl)
      res   = matsofe.create(&cFres)

    # end if 

  elif tval is matso:

    O = val
    if res_flag:
      
      Ores = out
      arrso_pow_to( &O.arr, e, &Ores.arr, dhl)

    else:

      cOres = arrso_pow( &O.arr, e,  dhl)
      res   = matso.create(&cOres)

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

    raise TypeError("Unsupported base type {0} in pow function.".format(tval))

  # end if 

  return res

#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cdef object __pow__sotinumexp(object val, sotinum e, object out = None):
  """
  cpdef __pow__sotinumexp(object val, sotinum e, object out = None)

  Power function x ** e, where e is sotinum type.
  
  Supported types:

      -  matso
      -  sotinum
      -  sotife

  :param val: Power base. Must be a supported types.
  :param e:   exponent.
  :param out: (optional) Holder of result, in order to avoid memory allocation.

  If out is not defined, then the result is a newlly allocated member containing the result.
  """
  #***************************************************************************************************

  cdef matso      O, Ores
  cdef dmat       R, Rres
  cdef matsofe    F, Fres
  cdef sotinum    o, ores
  cdef coeff_t    r, rres
  cdef sotife     f, fres
  cdef coeff_t   crres
  cdef sotinum_t cores
  cdef fesoti_t  cfres
  cdef darr_t    cRres
  cdef arrso_t   cOres
  cdef fearrso_t cFres  
  cdef sotinum e_oti
  cdef matso e_matso

  cdef uint8_t res_flag = 1

  cdef object res = None

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 


  if   tval is sotinum:

    o = val
    if res_flag:
      
      ores = out
      soti_pow_soti_to( &o.num, &e.num, &ores.num, dhl)

    else:

      cores = soti_pow_soti( &o.num, &e.num,  dhl)
      res   = sotinum.create(&cores)

    # end if 

  elif tval is sotife:

    f = val
    if res_flag:
      
      fres = out
      fesoti_pow_soti_to( &f.num, &e.num, &fres.num, dhl)

    else:

      cfres = fesoti_pow_soti( &f.num, &e.num,  dhl)
      res   = sotife.create(&cfres)

    # end if  
  
  elif tval is matso:

    O = val
    if res_flag:
      
      Ores = out
      arrso_pow_soti_to( &O.arr, &e.num, &Ores.arr, dhl)

    else:

      cOres = arrso_pow_soti( &O.arr, &e.num,  dhl)
      res   = matso.create(&cOres)

    # end if      

  else:  
    
    raise TypeError("Unsupported base type {0} in pow function.".format(tval))        
    
  # end if 
  
  return res

#-----------------------------------------------------------------------------------------------------


#*****************************************************************************************************
cdef object __pow__matsoexp(object val, matso e, object out = None):
  """
  __pow__matsoexp(object x, matso e, object out = None)
  
  Power function x**e, where e is a matso.
  
  Supported types for the base:

    -  matso
    -  sotinum

  :param val: Power base. Must be a supported types.
  :param e:   exponent.
  :param out: (optional) Holder of result, in order to avoid memory allocation.

  If out is not defined, then the result is a newlly allocated member containing the result.

  """
  #***************************************************************************************************

  cdef matso      O, Ores
  cdef dmat       R, Rres
  cdef matsofe    F, Fres
  cdef sotinum    o, ores
  cdef coeff_t    r, rres
  cdef sotife     f, fres
  cdef coeff_t   crres
  cdef sotinum_t cores
  cdef fesoti_t  cfres
  cdef darr_t    cRres
  cdef arrso_t   cOres
  cdef fearrso_t cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 
    
  if   tval is sotinum:

    o = val

    if res_flag:
      
      Ores = out
      soti_pow_arrso_to( &o.num, &e.arr, &Ores.arr, dhl)

    else:

      cOres = soti_pow_arrso( &o.num, &e.arr,  dhl)
      res   = matso.create(&cOres)

    # end if 
  
  elif tval is matso:

    O = val
    if res_flag:
      
      Ores = out
      arrso_pow_arrso_to( &O.arr, &e.arr, &Ores.arr, dhl)

    else:

      cOres = arrso_pow_arrso( &O.arr, &e.arr,  dhl)
      res   = matso.create(&cOres)

    # end if

  else:  
    
    raise TypeError("Unsupported base type {0} in pow function.".format(tval))    

  # end if 

  return res

#-----------------------------------------------------------------------------------------------------





#*****************************************************************************************************
cpdef gauss_integrate(object val, sotife w, object out = None ):
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

  cdef matso      O, Ores
  cdef dmat       R, Rres
  cdef matsofe    F, Fres
  cdef sotinum    o, ores
  cdef coeff_t    r, rres
  cdef sotife     f, fres
  cdef coeff_t   crres
  cdef sotinum_t cores
  cdef fesoti_t  cfres
  cdef darr_t    cRres
  cdef arrso_t   cOres
  cdef fearrso_t cFres 
  cdef uint8_t res_flag = 1
  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if

  if   tval is sotife:
    f = val
    if res_flag:
      
      ores = out
      fesoti_integrate_f_to( &f.num, &w.num, &ores.num, dhl)

    else:

      cores = fesoti_integrate_f( &f.num, &w.num, dhl)
      res   = sotinum.create(&cores)

    # end if  
  elif tval is matsofe:
    F = val
    if res_flag:

      Ores = out
      fearrso_integrate_to( &F.arr, &w.num, &Ores.arr, dhl)

    else:

      cOres = fearrso_integrate( &F.arr, &w.num, dhl)
      res   = matso.create(&cOres)

    # end if 
  elif tval is sotinum:
    o = val
    if res_flag:
      
      ores = out
      fesoti_integrate_o_to( &o.num, &w.num, &ores.num, dhl)

    else:

      cores = fesoti_integrate_o( &o.num, &w.num, dhl)
      res   = sotinum.create(&cores)

    # end if
  else:
    try:
      r = val
      if res_flag:
        
        ores = out
        fesoti_integrate_r_to( r, &w.num, &ores.num, dhl)

      else:

        cores = fesoti_integrate_r( r, &w.num, dhl)
        res   = sotinum.create(&cores)

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
      -  matsofe
      -  darr
      -  sotinum
      -  sotife
      -  real
  """
  #***************************************************************************************************

  cdef matso      O, Ores
  cdef dmat       R, Rres
  cdef matsofe    F, Fres
  cdef sotinum    o, ores
  cdef coeff_t    r, rres
  cdef sotife     f, fres
  cdef coeff_t   crres
  cdef sotinum_t cores
  cdef fesoti_t  cfres
  cdef darr_t    cRres
  cdef arrso_t   cOres
  cdef fearrso_t cFres
  cdef uint8_t res_flag = 1
  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 
  #
  if   tval is sotinum:
    o = val
    if res_flag:
      
      ores = out
      soti_neg_to( &o.num, &ores.num, dhl)

    else:

      cores = soti_neg( &o.num,  dhl)
      res   = sotinum.create(&cores)

    # end if 
  elif tval is sotife:
    f = val
    if res_flag:
      
      fres = out
      fesoti_neg_to( &f.num, &fres.num, dhl)

    else:

      cfres = fesoti_neg( &f.num,  dhl)
      res   = sotife.create(&cfres)

    # end if         
  elif tval is matsofe:    
    F = val
    if res_flag:

      Fres = out
      fearrso_neg_to( &F.arr, &Fres.arr, dhl)

    else:

      cFres = fearrso_neg( &F.arr, dhl)
      res   = matsofe.create(&cFres)

    # end if 
  elif tval is matso:
    O = val
    if res_flag:
      
      Ores = out
      arrso_neg_to( &O.arr, &Ores.arr, dhl)

    else:

      cOres = arrso_neg( &O.arr,  dhl)
      res   = matso.create(&cOres)

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
    raise TypeError("Unsupported types at neg operation.")    
  # end if 

  if res_flag == 0:
    return res
  # end if 

#-----------------------------------------------------------------------------------------------------



#*****************************************************************************************************
cpdef abs(object val, object out = None):
  """
  PURPOSE:  Absolute value. abs(val).
  
  Supported types:

      -  matso
      -  matsofe
      -  darr
      -  sotinum
      -  sotife
      -  real
  """
  #***************************************************************************************************

  cdef matso      O, Ores
  cdef dmat       R, Rres
  cdef matsofe    F, Fres
  cdef sotinum    o, ores
  cdef coeff_t    r, rres
  cdef sotife     f, fres
  cdef coeff_t   crres
  cdef sotinum_t cores
  cdef fesoti_t  cfres
  cdef darr_t    cRres
  cdef arrso_t   cOres
  cdef fearrso_t cFres
  cdef uint8_t res_flag = 1
  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 
  #
  if   tval is sotinum:
    o = val
    if res_flag:
      
      ores = out
      soti_abs_to( &o.num, &ores.num, dhl)

    else:

      cores = soti_abs( &o.num,  dhl)
      res   = sotinum.create(&cores)

    # end if 
  elif tval is sotife:
    f = val
    if res_flag:
      
      fres = out
      fesoti_abs_to( &f.num, &fres.num, dhl)

    else:

      cfres = fesoti_abs( &f.num,  dhl)
      res   = sotife.create(&cfres)

    # end if         
  elif tval is matsofe:    
    F = val
    if res_flag:

      Fres = out
      fearrso_abs_to( &F.arr, &Fres.arr, dhl)

    else:

      cFres = fearrso_abs( &F.arr, dhl)
      res   = matsofe.create(&cFres)

    # end if 
  elif tval is matso:
    O = val
    if res_flag:
      
      Ores = out
      arrso_abs_to( &O.arr, &Ores.arr, dhl)

    else:

      cOres = arrso_abs( &O.arr,  dhl)
      res   = matso.create(&cOres)

    # end if    
  elif tval is dmat:
    R = val
    if res_flag:
      
      Rres = out
      darr_abs_to( &R.arr, &Rres.arr)

    else:

      cRres = darr_abs( &R.arr )
      res = dmat.create( &cRres )

    # end if 
  elif tval in number_types:
    import math    
    r    = val
    rres = abs(r)
    if res_flag:      
      out = rres
    else:
      res = rres
    # end if   
  else:
    raise TypeError("Unsupported types at abs operation.")    
  # end if 

  if res_flag == 0:
    return res
  # end if 

#-----------------------------------------------------------------------------------------------------
