#*****************************************************************************************************
cpdef cos(object val, object out = None):
  """
  PURPOSE:  Matrix determinant.
  
  Supported types:

      -  {arr_pytype}
      -  {fearr_pytype}
      -  darr
      -  {num_pytype}
      -  {fenum_pytype}
      -  real
  """
  #***************************************************************************************************

  cdef {arr_pytype}      O, Ores
  cdef dmat       R, Rres
  cdef {fearr_pytype}    F, Fres
  cdef {num_pytype}    o, ores
  cdef coeff_t    r, rres
  cdef {fenum_pytype}     f, fres
  cdef coeff_t   crres
  cdef {num_type} cores
  cdef {fenum_type}  cfres
  cdef darr_t    cRres
  cdef {arr_type}   cOres
  cdef {fearr_type} cFres
  cdef uint8_t res_flag = 1
  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 
  #
  if   tval is {num_pytype}:
    o = val
    if res_flag:
      
      ores = out
      {num_func}_cos_to( &o.num, &ores.num)

    else:

      cores = {num_func}_cos( &o.num)
      res   = {num_pytype}.create(&cores)

    # end if 
  elif tval is {fenum_pytype}:
    f = val
    if res_flag:
      
      fres = out
      {fenum_func}_cos_to( &f.num, &fres.num)

    else:

      cfres = {fenum_func}_cos( &f.num)
      res   = {fenum_pytype}.create(&cfres)

    # end if         
  elif tval is {fearr_pytype}:    
    F = val
    if res_flag:

      Fres = out
      {fearr_func}_cos_to( &F.arr, &Fres.arr)

    else:

      cFres = {fearr_func}_cos( &F.arr)
      res   = {fearr_pytype}.create(&cFres)

    # end if 
  elif tval is {arr_pytype}:
    O = val
    if res_flag:
      
      Ores = out
      {arr_func}_cos_to( &O.arr, &Ores.arr)

    else:

      cOres = {arr_func}_cos( &O.arr)
      res   = {arr_pytype}.create(&cOres)

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

      -  {arr_pytype}
      -  {fearr_pytype}
      -  darr
      -  {num_pytype}
      -  {fenum_pytype}
      -  real
  """
  #***************************************************************************************************

  cdef {arr_pytype}      O, Ores
  cdef dmat       R, Rres
  cdef {fearr_pytype}    F, Fres
  cdef {num_pytype}    o, ores
  cdef coeff_t    r, rres
  cdef {fenum_pytype}     f, fres
  cdef coeff_t   crres
  cdef {num_type} cores
  cdef {fenum_type}  cfres
  cdef darr_t    cRres
  cdef {arr_type}   cOres
  cdef {fearr_type} cFres
  cdef uint8_t res_flag = 1
  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if   tval is {num_pytype}:
    o = val
    if res_flag:
      
      ores = out
      {num_func}_sin_to( &o.num, &ores.num)

    else:

      cores = {num_func}_sin( &o.num)
      res   = {num_pytype}.create(&cores)

    # end if 
  elif tval is {fenum_pytype}:
    f = val
    if res_flag:
      
      fres = out
      {fenum_func}_sin_to( &f.num, &fres.num)

    else:

      cfres = {fenum_func}_sin( &f.num)
      res   = {fenum_pytype}.create(&cfres)

    # end if  
  elif tval is {fearr_pytype}:    
    F = val
    if res_flag:

      Fres = out
      {fearr_func}_sin_to( &F.arr, &Fres.arr)

    else:

      cFres = {fearr_func}_sin( &F.arr)
      res   = {fearr_pytype}.create(&cFres)

    # end if 
  elif tval is {arr_pytype}:
    O = val
    if res_flag:
      
      Ores = out
      {arr_func}_sin_to( &O.arr, &Ores.arr)

    else:

      cOres = {arr_func}_sin( &O.arr)
      res   = {arr_pytype}.create(&cOres)

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

      -  {arr_pytype}
      -  {fearr_pytype}
      -  darr
      -  {num_pytype}
      -  {fenum_pytype}
      -  real
  """
  #***************************************************************************************************

  cdef {arr_pytype}      O, Ores
  cdef dmat       R, Rres
  cdef {fearr_pytype}    F, Fres
  cdef {num_pytype}    o, ores
  cdef coeff_t    r, rres
  cdef {fenum_pytype}     f, fres
  cdef coeff_t   crres
  cdef {num_type} cores
  cdef {fenum_type}  cfres
  cdef darr_t    cRres
  cdef {arr_type}   cOres
  cdef {fearr_type} cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if   tval is {num_pytype}:
    o = val
    if res_flag:
      
      ores = out
      {num_func}_tan_to( &o.num, &ores.num)

    else:

      cores = {num_func}_tan( &o.num)
      res   = {num_pytype}.create(&cores)

    # end if 
  elif tval is {fenum_pytype}:
    f = val
    if res_flag:
      
      fres = out
      {fenum_func}_tan_to( &f.num, &fres.num)

    else:

      cfres = {fenum_func}_tan( &f.num)
      res   = {fenum_pytype}.create(&cfres)

    # end if  
  elif tval is {fearr_pytype}:    
    F = val
    if res_flag:

      Fres = out
      {fearr_func}_tan_to( &F.arr, &Fres.arr)

    else:

      cFres = {fearr_func}_tan( &F.arr)
      res   = {fearr_pytype}.create(&cFres)

    # end if 
  elif tval is {arr_pytype}:
    O = val
    if res_flag:
      
      Ores = out
      {arr_func}_tan_to( &O.arr, &Ores.arr)

    else:

      cOres = {arr_func}_tan( &O.arr)
      res   = {arr_pytype}.create(&cOres)

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

      -  {arr_pytype}
      -  {fearr_pytype}
      -  darr
      -  {num_pytype}
      -  {fenum_pytype}
      -  real
  """
  #***************************************************************************************************

  cdef {arr_pytype}      O, Ores
  cdef dmat       R, Rres
  cdef {fearr_pytype}    F, Fres
  cdef {num_pytype}    o, ores
  cdef coeff_t    r, rres
  cdef {fenum_pytype}     f, fres
  cdef coeff_t   crres
  cdef {num_type} cores
  cdef {fenum_type}  cfres
  cdef darr_t    cRres
  cdef {arr_type}   cOres
  cdef {fearr_type} cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if   tval is {num_pytype}:
    o = val
    if res_flag:
      
      ores = out
      {num_func}_acos_to( &o.num, &ores.num)

    else:

      cores = {num_func}_acos( &o.num)
      res   = {num_pytype}.create(&cores)

    # end if 
  elif tval is {fenum_pytype}:
    f = val
    if res_flag:
      
      fres = out
      {fenum_func}_acos_to( &f.num, &fres.num)

    else:

      cfres = {fenum_func}_acos( &f.num)
      res   = {fenum_pytype}.create(&cfres)

    # end if  
  elif tval is {fearr_pytype}:    
    F = val
    if res_flag:

      Fres = out
      {fearr_func}_acos_to( &F.arr, &Fres.arr)

    else:

      cFres = {fearr_func}_acos( &F.arr)
      res   = {fearr_pytype}.create(&cFres)

    # end if 
  elif tval is {arr_pytype}:
    O = val
    if res_flag:
      
      Ores = out
      {arr_func}_acos_to( &O.arr, &Ores.arr)

    else:

      cOres = {arr_func}_acos( &O.arr)
      res   = {arr_pytype}.create(&cOres)

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

      -  {arr_pytype}
      -  {fearr_pytype}
      -  darr
      -  {num_pytype}
      -  {fenum_pytype}
      -  real
  """
  #***************************************************************************************************

  cdef {arr_pytype}      O, Ores
  cdef dmat       R, Rres
  cdef {fearr_pytype}    F, Fres
  cdef {num_pytype}    o, ores
  cdef coeff_t    r, rres
  cdef {fenum_pytype}     f, fres
  cdef coeff_t   crres
  cdef {num_type} cores
  cdef {fenum_type}  cfres
  cdef darr_t    cRres
  cdef {arr_type}   cOres
  cdef {fearr_type} cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if   tval is {num_pytype}:
    o = val
    if res_flag:
      
      ores = out
      {num_func}_asin_to( &o.num, &ores.num)

    else:

      cores = {num_func}_asin( &o.num)
      res   = {num_pytype}.create(&cores)

    # end if 
  elif tval is {fenum_pytype}:
    f = val
    if res_flag:
      
      fres = out
      {fenum_func}_asin_to( &f.num, &fres.num)

    else:

      cfres = {fenum_func}_asin( &f.num)
      res   = {fenum_pytype}.create(&cfres)

    # end if  
  elif tval is {fearr_pytype}:    
    F = val
    if res_flag:

      Fres = out
      {fearr_func}_asin_to( &F.arr, &Fres.arr)

    else:

      cFres = {fearr_func}_asin( &F.arr)
      res   = {fearr_pytype}.create(&cFres)

    # end if 
  elif tval is {arr_pytype}:
    O = val
    if res_flag:
      
      Ores = out
      {arr_func}_asin_to( &O.arr, &Ores.arr)

    else:

      cOres = {arr_func}_asin( &O.arr)
      res   = {arr_pytype}.create(&cOres)

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

      -  {arr_pytype}
      -  {fearr_pytype}
      -  darr
      -  {num_pytype}
      -  {fenum_pytype}
      -  real
  """
  #***************************************************************************************************

  cdef {arr_pytype}      O, Ores
  cdef dmat       R, Rres
  cdef {fearr_pytype}    F, Fres
  cdef {num_pytype}    o, ores
  cdef coeff_t    r, rres
  cdef {fenum_pytype}     f, fres
  cdef coeff_t   crres
  cdef {num_type} cores
  cdef {fenum_type}  cfres
  cdef darr_t    cRres
  cdef {arr_type}   cOres
  cdef {fearr_type} cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if   tval is {num_pytype}:
    o = val
    if res_flag:
      
      ores = out
      {num_func}_atan_to( &o.num, &ores.num)

    else:

      cores = {num_func}_atan( &o.num)
      res   = {num_pytype}.create(&cores)

    # end if 
  elif tval is {fenum_pytype}:
    f = val
    if res_flag:
      
      fres = out
      {fenum_func}_atan_to( &f.num, &fres.num)

    else:

      cfres = {fenum_func}_atan( &f.num)
      res   = {fenum_pytype}.create(&cfres)

    # end if  
  elif tval is {fearr_pytype}:    
    F = val
    if res_flag:

      Fres = out
      {fearr_func}_atan_to( &F.arr, &Fres.arr)

    else:

      cFres = {fearr_func}_atan( &F.arr)
      res   = {fearr_pytype}.create(&cFres)

    # end if 
  elif tval is {arr_pytype}:
    O = val
    if res_flag:
      
      Ores = out
      {arr_func}_atan_to( &O.arr, &Ores.arr)

    else:

      cOres = {arr_func}_atan( &O.arr)
      res   = {arr_pytype}.create(&cOres)

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

      -  {arr_pytype}
      -  {fearr_pytype}
      -  darr
      -  {num_pytype}
      -  {fenum_pytype}
      -  real
  """
  #***************************************************************************************************

  cdef {arr_pytype}      O, Ores
  cdef dmat       R, Rres
  cdef {fearr_pytype}    F, Fres
  cdef {num_pytype}    o, ores
  cdef coeff_t    r, rres
  cdef {fenum_pytype}     f, fres
  cdef coeff_t   crres
  cdef {num_type} cores
  cdef {fenum_type}  cfres
  cdef darr_t    cRres
  cdef {arr_type}   cOres
  cdef {fearr_type} cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if   tval is {num_pytype}:
    o = val
    if res_flag:
      
      ores = out
      {num_func}_sinh_to( &o.num, &ores.num)

    else:

      cores = {num_func}_sinh( &o.num)
      res   = {num_pytype}.create(&cores)

    # end if 
  elif tval is {fenum_pytype}:
    f = val
    if res_flag:
      
      fres = out
      {fenum_func}_sinh_to( &f.num, &fres.num)

    else:

      cfres = {fenum_func}_sinh( &f.num)
      res   = {fenum_pytype}.create(&cfres)

    # end if  
  elif tval is {fearr_pytype}:    
    F = val
    if res_flag:

      Fres = out
      {fearr_func}_sinh_to( &F.arr, &Fres.arr)

    else:

      cFres = {fearr_func}_sinh( &F.arr)
      res   = {fearr_pytype}.create(&cFres)

    # end if 
  elif tval is {arr_pytype}:
    O = val
    if res_flag:
      
      Ores = out
      {arr_func}_sinh_to( &O.arr, &Ores.arr)

    else:

      cOres = {arr_func}_sinh( &O.arr)
      res   = {arr_pytype}.create(&cOres)

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

      -  {arr_pytype}
      -  {fearr_pytype}
      -  darr
      -  {num_pytype}
      -  {fenum_pytype}
      -  real
  """
  #***************************************************************************************************

  cdef {arr_pytype}      O, Ores
  cdef dmat       R, Rres
  cdef {fearr_pytype}    F, Fres
  cdef {num_pytype}    o, ores
  cdef coeff_t    r, rres
  cdef {fenum_pytype}     f, fres
  cdef coeff_t   crres
  cdef {num_type} cores
  cdef {fenum_type}  cfres
  cdef darr_t    cRres
  cdef {arr_type}   cOres
  cdef {fearr_type} cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if   tval is {num_pytype}:
    o = val
    if res_flag:
      
      ores = out
      {num_func}_cosh_to( &o.num, &ores.num)

    else:

      cores = {num_func}_cosh( &o.num)
      res   = {num_pytype}.create(&cores)

    # end if 
  elif tval is {fenum_pytype}:
    f = val
    if res_flag:
      
      fres = out
      {fenum_func}_cosh_to( &f.num, &fres.num)

    else:

      cfres = {fenum_func}_cosh( &f.num)
      res   = {fenum_pytype}.create(&cfres)

    # end if  
  elif tval is {fearr_pytype}:    
    F = val
    if res_flag:

      Fres = out
      {fearr_func}_cosh_to( &F.arr, &Fres.arr)

    else:

      cFres = {fearr_func}_cosh( &F.arr)
      res   = {fearr_pytype}.create(&cFres)

    # end if 
  elif tval is {arr_pytype}:
    O = val
    if res_flag:
      
      Ores = out
      {arr_func}_cosh_to( &O.arr, &Ores.arr)

    else:

      cOres = {arr_func}_cosh( &O.arr)
      res   = {arr_pytype}.create(&cOres)

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

      -  {arr_pytype}
      -  {fearr_pytype}
      -  darr
      -  {num_pytype}
      -  {fenum_pytype}
      -  real
  """
  #***************************************************************************************************

  cdef {arr_pytype}      O, Ores
  cdef dmat       R, Rres
  cdef {fearr_pytype}    F, Fres
  cdef {num_pytype}    o, ores
  cdef coeff_t    r, rres
  cdef {fenum_pytype}     f, fres
  cdef coeff_t   crres
  cdef {num_type} cores
  cdef {fenum_type}  cfres
  cdef darr_t    cRres
  cdef {arr_type}   cOres
  cdef {fearr_type} cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if   tval is {num_pytype}:
    o = val
    if res_flag:
      
      ores = out
      {num_func}_tanh_to( &o.num, &ores.num)

    else:

      cores = {num_func}_tanh( &o.num)
      res   = {num_pytype}.create(&cores)

    # end if 
  elif tval is {fenum_pytype}:
    f = val
    if res_flag:
      
      fres = out
      {fenum_func}_tanh_to( &f.num, &fres.num)

    else:

      cfres = {fenum_func}_tanh( &f.num)
      res   = {fenum_pytype}.create(&cfres)

    # end if  
  elif tval is {fearr_pytype}:    
    F = val
    if res_flag:

      Fres = out
      {fearr_func}_tanh_to( &F.arr, &Fres.arr)

    else:

      cFres = {fearr_func}_tanh( &F.arr)
      res   = {fearr_pytype}.create(&cFres)

    # end if 
  elif tval is {arr_pytype}:
    O = val
    if res_flag:
      
      Ores = out
      {arr_func}_tanh_to( &O.arr, &Ores.arr)

    else:

      cOres = {arr_func}_tanh( &O.arr)
      res   = {arr_pytype}.create(&cOres)

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

      -  {arr_pytype}
      -  {fearr_pytype}
      -  darr
      -  {num_pytype}
      -  {fenum_pytype}
      -  real
  """
  #***************************************************************************************************

  cdef {arr_pytype}      O, Ores
  cdef dmat       R, Rres
  cdef {fearr_pytype}    F, Fres
  cdef {num_pytype}    o, ores
  cdef coeff_t    r, rres
  cdef {fenum_pytype}     f, fres
  cdef coeff_t   crres
  cdef {num_type} cores
  cdef {fenum_type}  cfres
  cdef darr_t    cRres
  cdef {arr_type}   cOres
  cdef {fearr_type} cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if   tval is {num_pytype}:
    o = val
    if res_flag:
      
      ores = out
      {num_func}_acosh_to( &o.num, &ores.num)

    else:

      cores = {num_func}_acosh( &o.num)
      res   = {num_pytype}.create(&cores)

    # end if 
  elif tval is {fenum_pytype}:
    f = val
    if res_flag:
      
      fres = out
      {fenum_func}_acosh_to( &f.num, &fres.num)

    else:

      cfres = {fenum_func}_acosh( &f.num)
      res   = {fenum_pytype}.create(&cfres)

    # end if  
  elif tval is {fearr_pytype}:    
    F = val
    if res_flag:

      Fres = out
      {fearr_func}_acosh_to( &F.arr, &Fres.arr)

    else:

      cFres = {fearr_func}_acosh( &F.arr)
      res   = {fearr_pytype}.create(&cFres)

    # end if 
  elif tval is {arr_pytype}:
    O = val
    if res_flag:
      
      Ores = out
      {arr_func}_acosh_to( &O.arr, &Ores.arr)

    else:

      cOres = {arr_func}_acosh( &O.arr)
      res   = {arr_pytype}.create(&cOres)

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

      -  {arr_pytype}
      -  {fearr_pytype}
      -  darr
      -  {num_pytype}
      -  {fenum_pytype}
      -  real
  """
  #***************************************************************************************************

  cdef {arr_pytype}      O, Ores
  cdef dmat       R, Rres
  cdef {fearr_pytype}    F, Fres
  cdef {num_pytype}    o, ores
  cdef coeff_t    r, rres
  cdef {fenum_pytype}     f, fres
  cdef coeff_t   crres
  cdef {num_type} cores
  cdef {fenum_type}  cfres
  cdef darr_t    cRres
  cdef {arr_type}   cOres
  cdef {fearr_type} cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if   tval is {num_pytype}:
    o = val
    if res_flag:
      
      ores = out
      {num_func}_asinh_to( &o.num, &ores.num)

    else:

      cores = {num_func}_asinh( &o.num)
      res   = {num_pytype}.create(&cores)

    # end if 
  elif tval is {fenum_pytype}:
    f = val
    if res_flag:
      
      fres = out
      {fenum_func}_asinh_to( &f.num, &fres.num)

    else:

      cfres = {fenum_func}_asinh( &f.num)
      res   = {fenum_pytype}.create(&cfres)

    # end if  
  elif tval is {fearr_pytype}:    
    F = val
    if res_flag:

      Fres = out
      {fearr_func}_asinh_to( &F.arr, &Fres.arr)

    else:

      cFres = {fearr_func}_asinh( &F.arr)
      res   = {fearr_pytype}.create(&cFres)

    # end if 
  elif tval is {arr_pytype}:
    O = val
    if res_flag:
      
      Ores = out
      {arr_func}_asinh_to( &O.arr, &Ores.arr)

    else:

      cOres = {arr_func}_asinh( &O.arr)
      res   = {arr_pytype}.create(&cOres)

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

      -  {arr_pytype}
      -  {fearr_pytype}
      -  darr
      -  {num_pytype}
      -  {fenum_pytype}
      -  real
  """
  #***************************************************************************************************

  cdef {arr_pytype}      O, Ores
  cdef dmat       R, Rres
  cdef {fearr_pytype}    F, Fres
  cdef {num_pytype}    o, ores
  cdef coeff_t    r, rres
  cdef {fenum_pytype}     f, fres
  cdef coeff_t   crres
  cdef {num_type} cores
  cdef {fenum_type}  cfres
  cdef darr_t    cRres
  cdef {arr_type}   cOres
  cdef {fearr_type} cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if   tval is {num_pytype}:
    o = val
    if res_flag:
      
      ores = out
      {num_func}_atanh_to( &o.num, &ores.num)

    else:

      cores = {num_func}_atanh( &o.num)
      res   = {num_pytype}.create(&cores)

    # end if 
  elif tval is {fenum_pytype}:
    f = val
    if res_flag:
      
      fres = out
      {fenum_func}_atanh_to( &f.num, &fres.num)

    else:

      cfres = {fenum_func}_atanh( &f.num)
      res   = {fenum_pytype}.create(&cfres)

    # end if  
  elif tval is {fearr_pytype}:    
    F = val
    if res_flag:

      Fres = out
      {fearr_func}_atanh_to( &F.arr, &Fres.arr)

    else:

      cFres = {fearr_func}_atanh( &F.arr)
      res   = {fearr_pytype}.create(&cFres)

    # end if 
  elif tval is {arr_pytype}:
    O = val
    if res_flag:
      
      Ores = out
      {arr_func}_atanh_to( &O.arr, &Ores.arr)

    else:

      cOres = {arr_func}_atanh( &O.arr)
      res   = {arr_pytype}.create(&cOres)

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

      -  {arr_pytype}
      -  {fearr_pytype}
      -  darr
      -  {num_pytype}
      -  {fenum_pytype}
      -  real
  """
  #***************************************************************************************************

  cdef {arr_pytype}      O, Ores
  cdef dmat       R, Rres
  cdef {fearr_pytype}    F, Fres
  cdef {num_pytype}    o, ores
  cdef coeff_t    r, rres
  cdef {fenum_pytype}     f, fres
  cdef coeff_t   crres
  cdef {num_type} cores
  cdef {fenum_type}  cfres
  cdef darr_t    cRres
  cdef {arr_type}   cOres
  cdef {fearr_type} cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if   tval is {num_pytype}:
    o = val
    if res_flag:
      
      ores = out
      {num_func}_exp_to( &o.num, &ores.num)

    else:

      cores = {num_func}_exp( &o.num)
      res   = {num_pytype}.create(&cores)

    # end if 
  elif tval is {fenum_pytype}:
    f = val
    if res_flag:
      
      fres = out
      {fenum_func}_exp_to( &f.num, &fres.num)

    else:

      cfres = {fenum_func}_exp( &f.num)
      res   = {fenum_pytype}.create(&cfres)

    # end if  
  elif tval is {fearr_pytype}:    
    F = val
    if res_flag:

      Fres = out
      {fearr_func}_exp_to( &F.arr, &Fres.arr)

    else:

      cFres = {fearr_func}_exp( &F.arr)
      res   = {fearr_pytype}.create(&cFres)

    # end if 
  elif tval is {arr_pytype}:
    O = val
    if res_flag:
      
      Ores = out
      {arr_func}_exp_to( &O.arr, &Ores.arr)

    else:

      cOres = {arr_func}_exp( &O.arr)
      res   = {arr_pytype}.create(&cOres)

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

      -  {arr_pytype}
      -  {fearr_pytype}
      -  darr
      -  {num_pytype}
      -  {fenum_pytype}
      -  real

  INPUTS:

    - val: Value to evaluate. Must be a supported one of the supported types.
    - out: (optional) Holder of result, in order to avoid memory allocation.

  OUTPUTS:

    If out is not defined, then the result is a newlly allocated member containing the result.
  """
  #***************************************************************************************************

  cdef {arr_pytype}      O, Ores
  cdef dmat       R, Rres
  cdef {fearr_pytype}    F, Fres
  cdef {num_pytype}    o, ores
  cdef coeff_t    r, rres
  cdef {fenum_pytype}     f, fres
  cdef coeff_t   crres
  cdef {num_type} cores
  cdef {fenum_type}  cfres
  cdef darr_t    cRres
  cdef {arr_type}   cOres
  cdef {fearr_type} cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if   tval is {num_pytype}:
    o = val
    if res_flag:
      
      ores = out
      {num_func}_log_to( &o.num, &ores.num)

    else:

      cores = {num_func}_log( &o.num)
      res   = {num_pytype}.create(&cores)

    # end if 
  elif tval is {fenum_pytype}:
    f = val
    if res_flag:
      
      fres = out
      {fenum_func}_log_to( &f.num, &fres.num)

    else:

      cfres = {fenum_func}_log( &f.num)
      res   = {fenum_pytype}.create(&cfres)

    # end if  
  elif tval is {fearr_pytype}:    
    F = val
    if res_flag:

      Fres = out
      {fearr_func}_log_to( &F.arr, &Fres.arr)

    else:

      cFres = {fearr_func}_log( &F.arr)
      res   = {fearr_pytype}.create(&cFres)

    # end if 
  elif tval is {arr_pytype}:
    O = val
    if res_flag:
      
      Ores = out
      {arr_func}_log_to( &O.arr, &Ores.arr)

    else:

      cOres = {arr_func}_log( &O.arr)
      res   = {arr_pytype}.create(&cOres)

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

      -  {arr_pytype}
      -  {fearr_pytype}
      -  darr
      -  {num_pytype}
      -  {fenum_pytype}
      -  real

  INPUTS:

    - val: Value to evaluate. Must be a supported one of the supported types.
    - out: (optional) Holder of result, in order to avoid memory allocation.

  OUTPUTS:

    If out is not defined, then the result is a newlly allocated member containing the result.
  """
  #***************************************************************************************************

  cdef {arr_pytype}      O, Ores
  cdef dmat       R, Rres
  cdef {fearr_pytype}    F, Fres
  cdef {num_pytype}    o, ores
  cdef coeff_t    r, rres
  cdef {fenum_pytype}     f, fres
  cdef coeff_t   crres
  cdef {num_type} cores
  cdef {fenum_type}  cfres
  cdef darr_t    cRres
  cdef {arr_type}   cOres
  cdef {fearr_type} cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if   tval is {num_pytype}:
    o = val
    if res_flag:
      
      ores = out
      {num_func}_log10_to( &o.num, &ores.num)

    else:

      cores = {num_func}_log10( &o.num)
      res   = {num_pytype}.create(&cores)

    # end if 
  elif tval is {fenum_pytype}:
    f = val
    if res_flag:
      
      fres = out
      {fenum_func}_log10_to( &f.num, &fres.num)

    else:

      cfres = {fenum_func}_log10( &f.num)
      res   = {fenum_pytype}.create(&cfres)

    # end if  
  elif tval is {fearr_pytype}:    
    F = val
    if res_flag:

      Fres = out
      {fearr_func}_log10_to( &F.arr, &Fres.arr)

    else:

      cFres = {fearr_func}_log10( &F.arr)
      res   = {fearr_pytype}.create(&cFres)

    # end if 
  elif tval is {arr_pytype}:
    O = val
    if res_flag:
      
      Ores = out
      {arr_func}_log10_to( &O.arr, &Ores.arr)

    else:

      cOres = {arr_func}_log10( &O.arr)
      res   = {arr_pytype}.create(&cOres)

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

      -  {arr_pytype}
      -  {fearr_pytype}
      -  darr
      -  {num_pytype}
      -  {fenum_pytype}
      -  real

  INPUTS:

    - val: Value to evaluate. Must be a supported one of the supported types.
    - b:   Base.
    - out: (optional) Holder of result, in order to avoid memory allocation.

  OUTPUTS:

    If out is not defined, then the result is a newlly allocated member containing the result.
  """
  #***************************************************************************************************

  cdef {arr_pytype}      O, Ores
  cdef dmat       R, Rres
  cdef {fearr_pytype}    F, Fres
  cdef {num_pytype}    o, ores
  cdef coeff_t    r, rres
  cdef {fenum_pytype}     f, fres
  cdef coeff_t   crres
  cdef {num_type} cores
  cdef {fenum_type}  cfres
  cdef darr_t    cRres
  cdef {arr_type}   cOres
  cdef {fearr_type} cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if   tval is {num_pytype}:
    o = val
    if res_flag:
      
      ores = out
      {num_func}_logb_to( &o.num, b, &ores.num)

    else:

      cores = {num_func}_logb( &o.num, b)
      res   = {num_pytype}.create(&cores)

    # end if 
  elif tval is {fenum_pytype}:
    f = val
    if res_flag:
      
      fres = out
      {fenum_func}_logb_to( &f.num, b, &fres.num)

    else:

      cfres = {fenum_func}_logb( &f.num, b)
      res   = {fenum_pytype}.create(&cfres)

    # end if  
  elif tval is {fearr_pytype}:    
    F = val
    if res_flag:

      Fres = out
      {fearr_func}_logb_to( &F.arr, b, &Fres.arr)

    else:

      cFres = {fearr_func}_logb( &F.arr, b)
      res   = {fearr_pytype}.create(&cFres)

    # end if 
  elif tval is {arr_pytype}:
    O = val
    if res_flag:
      
      Ores = out
      {arr_func}_logb_to( &O.arr, b, &Ores.arr)

    else:

      cOres = {arr_func}_logb( &O.arr, b)
      res   = {arr_pytype}.create(&cOres)

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

      -  {arr_pytype}
      -  {fearr_pytype}
      -  darr
      -  {num_pytype}
      -  {fenum_pytype}
      -  real

  INPUTS:

    - val: Value to evaluate. Must be a supported one of the supported types.
    - out: (optional) Holder of result, in order to avoid memory allocation.

  OUTPUTS:

    If out is not defined, then the result is a newlly allocated member containing the result.
  """
  #***************************************************************************************************

  cdef {arr_pytype}      O, Ores
  cdef dmat       R, Rres
  cdef {fearr_pytype}    F, Fres
  cdef {num_pytype}    o, ores
  cdef coeff_t    r, rres
  cdef {fenum_pytype}     f, fres
  cdef coeff_t   crres
  cdef {num_type} cores
  cdef {fenum_type}  cfres
  cdef darr_t    cRres
  cdef {arr_type}   cOres
  cdef {fearr_type} cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if   tval is {num_pytype}:
    o = val
    if res_flag:
      
      ores = out
      {num_func}_sqrt_to( &o.num, &ores.num)

    else:

      cores = {num_func}_sqrt( &o.num)
      res   = {num_pytype}.create(&cores)

    # end if 
  elif tval is {fenum_pytype}:
    f = val
    if res_flag:
      
      fres = out
      {fenum_func}_sqrt_to( &f.num, &fres.num)

    else:

      cfres = {fenum_func}_sqrt( &f.num)
      res   = {fenum_pytype}.create(&cfres)

    # end if  
  elif tval is {fearr_pytype}:    
    F = val
    if res_flag:

      Fres = out
      {fearr_func}_sqrt_to( &F.arr, &Fres.arr)

    else:

      cFres = {fearr_func}_sqrt( &F.arr)
      res   = {fearr_pytype}.create(&cFres)

    # end if 
  elif tval is {arr_pytype}:
    O = val
    if res_flag:
      
      Ores = out
      {arr_func}_sqrt_to( &O.arr, &Ores.arr)

    else:

      cOres = {arr_func}_sqrt( &O.arr)
      res   = {arr_pytype}.create(&cOres)

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

      -  {arr_pytype}
      -  {fearr_pytype}
      -  darr
      -  {num_pytype}
      -  {fenum_pytype}
      -  real

  INPUTS:

    - val: Value to evaluate. Must be a supported one of the supported types.
    - out: (optional) Holder of result, in order to avoid memory allocation.

  OUTPUTS:

    If out is not defined, then the result is a newlly allocated member containing the result.
  """
  #***************************************************************************************************

  cdef {arr_pytype}      O, Ores
  cdef dmat       R, Rres
  cdef {fearr_pytype}    F, Fres
  cdef {num_pytype}    o, ores
  cdef coeff_t    r, rres
  cdef {fenum_pytype}     f, fres
  cdef coeff_t   crres
  cdef {num_type} cores
  cdef {fenum_type}  cfres
  cdef darr_t    cRres
  cdef {arr_type}   cOres
  cdef {fearr_type} cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if   tval is {num_pytype}:
    o = val
    if res_flag:
      
      ores = out
      {num_func}_cbrt_to( &o.num, &ores.num)

    else:

      cores = {num_func}_cbrt( &o.num)
      res   = {num_pytype}.create(&cores)

    # end if 
  elif tval is {fenum_pytype}:
    f = val
    if res_flag:
      
      fres = out
      {fenum_func}_cbrt_to( &f.num, &fres.num)

    else:

      cfres = {fenum_func}_cbrt( &f.num)
      res   = {fenum_pytype}.create(&cfres)

    # end if  
  elif tval is {fearr_pytype}:    
    F = val
    if res_flag:

      Fres = out
      {fearr_func}_cbrt_to( &F.arr, &Fres.arr)

    else:

      cFres = {fearr_func}_cbrt( &F.arr)
      res   = {fearr_pytype}.create(&cFres)

    # end if 
  elif tval is {arr_pytype}:
    O = val
    if res_flag:
      
      Ores = out
      {arr_func}_cbrt_to( &O.arr, &Ores.arr)

    else:

      cOres = {arr_func}_cbrt( &O.arr)
      res   = {arr_pytype}.create(&cOres)

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

      -  {arr_pytype}
      -  {fearr_pytype}
      -  darr
      -  {num_pytype}
      -  {fenum_pytype}
      -  real

  INPUTS:

    - val: Value to evaluate. Must be a supported one of the supported types.
    - e:   exponent.
    - out: (optional) Holder of result, in order to avoid memory allocation.

  OUTPUTS:

    If out is not defined, then the result is a newlly allocated member containing the result.
  """
  #***************************************************************************************************

  cdef {arr_pytype}      O, Ores
  cdef dmat       R, Rres
  cdef {fearr_pytype}    F, Fres
  cdef {num_pytype}    o, ores
  cdef coeff_t    r, rres
  cdef {fenum_pytype}     f, fres
  cdef coeff_t   crres
  cdef {num_type} cores
  cdef {fenum_type}  cfres
  cdef darr_t    cRres
  cdef {arr_type}   cOres
  cdef {fearr_type} cFres  

  cdef uint8_t res_flag = 1

  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 

  #
  if   tval is {num_pytype}:
    o = val
    if res_flag:
      
      ores = out
      {num_func}_pow_to( &o.num, e, &ores.num)

    else:

      cores = {num_func}_pow( &o.num, e)
      res   = {num_pytype}.create(&cores)

    # end if 
  elif tval is {fenum_pytype}:
    f = val
    if res_flag:
      
      fres = out
      {fenum_func}_pow_to( &f.num, e, &fres.num)

    else:

      cfres = {fenum_func}_pow( &f.num, e)
      res   = {fenum_pytype}.create(&cfres)

    # end if  
  elif tval is {fearr_pytype}:    
    F = val
    if res_flag:

      Fres = out
      {fearr_func}_pow_to( &F.arr, e, &Fres.arr)

    else:

      cFres = {fearr_func}_pow( &F.arr, e)
      res   = {fearr_pytype}.create(&cFres)

    # end if 
  elif tval is {arr_pytype}:
    O = val
    if res_flag:
      
      Ores = out
      {arr_func}_pow_to( &O.arr, e, &Ores.arr)

    else:

      cOres = {arr_func}_pow( &O.arr, e)
      res   = {arr_pytype}.create(&cOres)

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
cpdef gauss_integrate(object val, {fenum_pytype} w, object out = None ):
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
  

  cdef {arr_pytype}      O, Ores
  cdef dmat       R, Rres
  cdef {fearr_pytype}    F, Fres
  cdef {num_pytype}    o, ores
  cdef coeff_t    r, rres
  cdef {fenum_pytype}     f, fres
  cdef coeff_t   crres
  cdef {num_type} cores
  cdef {fenum_type}  cfres
  cdef darr_t    cRres
  cdef {arr_type}   cOres
  cdef {fearr_type} cFres 
  cdef uint8_t res_flag = 1
  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if

  if   tval is {fenum_pytype}:
    f = val
    if res_flag:
      
      ores = out
      {fenum_func}_integrate_f_to( &f.num, &w.num, &ores.num)

    else:

      cores = {fenum_func}_integrate_f( &f.num, &w.num)
      res   = {num_pytype}.create(&cores)

    # end if  
  elif tval is {fearr_pytype}:
    F = val
    if res_flag:

      Ores = out
      {fearr_func}_integrate_to( &F.arr, &w.num, &Ores.arr)

    else:

      cOres = {fearr_func}_integrate( &F.arr, &w.num)
      res   = {arr_pytype}.create(&cOres)

    # end if 
  elif tval is {num_pytype}:
    o = val
    if res_flag:
      
      ores = out
      {fenum_func}_integrate_o_to( &o.num, &w.num, &ores.num)

    else:

      cores = {fenum_func}_integrate_o( &o.num, &w.num)
      res   = {num_pytype}.create(&cores)

    # end if
  else:
    try:
      r = val
      if res_flag:
        
        ores = out
        {fenum_func}_integrate_r_to( r, &w.num, &ores.num)

      else:

        cores = {fenum_func}_integrate_r( r, &w.num)
        res   = {num_pytype}.create(&cores)

      # end if  
    except:

      raise TypeError("Unsupported type {{0}} at gauss_integrate operation.".format(tval))
    
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

      -  {arr_pytype}
      -  {fearr_pytype}
      -  darr
      -  {num_pytype}
      -  {fenum_pytype}
      -  real
  """
  #***************************************************************************************************

  cdef {arr_pytype}      O, Ores
  cdef dmat       R, Rres
  cdef {fearr_pytype}    F, Fres
  cdef {num_pytype}    o, ores
  cdef coeff_t    r, rres
  cdef {fenum_pytype}     f, fres
  cdef coeff_t   crres
  cdef {num_type} cores
  cdef {fenum_type}  cfres
  cdef darr_t    cRres
  cdef {arr_type}   cOres
  cdef {fearr_type} cFres
  cdef uint8_t res_flag = 1
  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 
  #
  if   tval is {num_pytype}:
    o = val
    if res_flag:
      
      ores = out
      {num_func}_neg_to( &o.num, &ores.num)

    else:

      cores = {num_func}_neg( &o.num)
      res   = {num_pytype}.create(&cores)

    # end if 
  elif tval is {fenum_pytype}:
    f = val
    if res_flag:
      
      fres = out
      {fenum_func}_neg_to( &f.num, &fres.num)

    else:

      cfres = {fenum_func}_neg( &f.num)
      res   = {fenum_pytype}.create(&cfres)

    # end if         
  elif tval is {fearr_pytype}:    
    F = val
    if res_flag:

      Fres = out
      {fearr_func}_neg_to( &F.arr, &Fres.arr)

    else:

      cFres = {fearr_func}_neg( &F.arr)
      res   = {fearr_pytype}.create(&cFres)

    # end if 
  elif tval is {arr_pytype}:
    O = val
    if res_flag:
      
      Ores = out
      {arr_func}_neg_to( &O.arr, &Ores.arr)

    else:

      cOres = {arr_func}_neg( &O.arr)
      res   = {arr_pytype}.create(&cOres)

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
