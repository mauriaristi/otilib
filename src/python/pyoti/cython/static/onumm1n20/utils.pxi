

#*****************************************************************************************************
cdef (uint64_t,uint64_t) process_shape(object shape_in):
  """
  PURPOSE: Review if shape can be created as a 2D matrix. (nrows,ncols).

  """
  cdef uint64_t nrows, ncols

  if isinstance(shape_in, int) :

    nrows = shape_in
    ncols = 1

  elif ( len(shape_in) == 1 ):

    nrows = shape_in[0]
    ncols = 1

  elif ( len(shape_in) == 2 ):

    nrows = shape_in[0]
    ncols = shape_in[1]

  else:

    raise ValueError(" Can't create matrix with more than 2 dimensions.")

  # end if 

  return (nrows, ncols)
#-----------------------------------------------------------------------------------------------------

  
  

#*****************************************************************************************************
cpdef truncate(object humdir, object val, object out = None):
  """
  PURPOSE:  Truncate the imaginary direction of an OTI member.
  
  Supported types:

      -  omatm1n20
      -  feomatm1n20
      -  onumm1n20
      -  feonumm1n20
  """
  #***************************************************************************************************
  cdef imdir_t indx
  cdef ord_t   order
  cdef omatm1n20      O, Ores
  cdef csr_matrix  S, Sres
  cdef dmat       R, Rres
  cdef feomatm1n20    F, Fres
  cdef onumm1n20    o, ores
  cdef coeff_t    r, rres
  cdef feonumm1n20     f, fres
  cdef coeff_t   crres
  cdef onumm1n20_t cores
  cdef feonumm1n20_t  cfres
  cdef darr_t    cRres
  cdef oarrm1n20_t   cOres
  cdef feoarrm1n20_t cFres
  cdef uint8_t res_flag = 1

  cdef uint64_t i
  cdef object res

  indx, order = imdir(humdir)

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 
  
  # Scalar Types
  if   tval is onumm1n20:
    o = val
    if res_flag:
      
      ores = out
      onumm1n20_truncate_im_to( indx, order, &o.num, &ores.num)

    else:

      cores = onumm1n20_truncate_im( indx, order, &o.num)
      res   = onumm1n20.create(&cores)

    # end if 
  elif tval is feonumm1n20:
    f = val
    if res_flag:
      
      fres = out
      feonumm1n20_truncate_im_to( indx, order, &f.num, &fres.num)

    else:

      cfres = feonumm1n20_truncate_im( indx, order, &f.num)
      res   = feonumm1n20.create(&cfres)

    # end if
  # Array Types
  elif tval is omatm1n20:
    O = val
    if res_flag:
      
      Ores = out
      oarrm1n20_truncate_im_to( indx, order, &O.arr, &Ores.arr)

    else:

      cOres = oarrm1n20_truncate_im( indx, order, &O.arr)
      res   = omatm1n20.create(&cOres)

    # end if
  elif tval is feomatm1n20:    
    F = val
    if res_flag:

      Fres = out
      feoarrm1n20_truncate_im_to( indx, order, &F.arr, &Fres.arr)

    else:

      cFres = feoarrm1n20_truncate_im( indx, order, &F.arr)
      res   = feomatm1n20.create(&cFres)

    # end if 
  elif tval is csr_matrix:
    S = val
    if res_flag:
      
      Sres = out
      oarrm1n20_truncate_im_to( indx, order, &S.arr, &Sres.arr)

    else:

      Sres = S.zeros_like()
      oarrm1n20_truncate_im_to( indx, order, &S.arr, &Sres.arr)
      res = Sres 

    # end if 
  else:
    raise TypeError("Unsupported types at truncate operation.")    
  # end if 

  if res_flag == 0:
    return res
  # end if 

#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cpdef extract_im(object humdir, object val, object out = None):
  """
  PURPOSE:  Extract imaginary direction of the given type.
  
  Supported types:

      -  omatm1n20
      -  feomatm1n20
      -  onumm1n20
      -  feonumm1n20
  """
  #***************************************************************************************************
  cdef imdir_t indx
  cdef ord_t   order
  cdef omatm1n20      O, Ores
  cdef csr_matrix  S, Sres
  cdef dmat       R, Rres
  cdef feomatm1n20    F, Fres
  cdef onumm1n20    o, ores
  cdef coeff_t    r, rres
  cdef feonumm1n20     f, fres
  cdef coeff_t   crres
  cdef onumm1n20_t cores
  cdef feonumm1n20_t  cfres
  cdef darr_t    cRres
  cdef oarrm1n20_t   cOres
  cdef feoarrm1n20_t cFres
  cdef uint8_t res_flag = 1
  cdef int64_t   i 
  cdef object res

  indx, order = imdir(humdir)

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 
  
  # Scalar Types
  if   tval is onumm1n20:
    o = val
    if res_flag:
      
      ores = out
      onumm1n20_extract_im_to( indx, order, &o.num, &ores.num)

    else:

      cores = onumm1n20_extract_im( indx, order, &o.num)
      res   = onumm1n20.create(&cores)

    # end if 
  elif tval is feonumm1n20:
    f = val
    if res_flag:
      
      fres = out
      feonumm1n20_extract_im_to( indx, order, &f.num, &fres.num)

    else:

      cfres = feonumm1n20_extract_im( indx, order, &f.num)
      res   = feonumm1n20.create(&cfres)

    # end if
  # Array Types
  elif tval is omatm1n20:
    O = val
    if res_flag:
      
      Ores = out
      oarrm1n20_extract_im_to( indx, order, &O.arr, &Ores.arr)

    else:

      cOres = oarrm1n20_extract_im( indx, order, &O.arr)
      res   = omatm1n20.create(&cOres)

    # end if
  elif tval is feomatm1n20:    
    F = val
    if res_flag:

      Fres = out
      feoarrm1n20_extract_im_to( indx, order, &F.arr, &Fres.arr)

    else:

      cFres = feoarrm1n20_extract_im( indx, order, &F.arr)
      res   = feomatm1n20.create(&cFres)

    # end if 
  elif tval is csr_matrix:
    S = val
    if res_flag:
      
      Sres = out
      oarrm1n20_extract_im_to( indx, order, &S.arr, &Sres.arr)

    else:

      Sres = S.zeros_like()
      oarrm1n20_extract_im_to( indx, order, &S.arr, &Sres.arr)
      res = Sres 

    # end if 
  else:
    raise TypeError("Unsupported types at extract_im operation.")    
  # end if 

  if res_flag == 0:
    return res
  # end if 

#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cpdef extract_deriv(object humdir, object val, object out = None):
  """
  PURPOSE:  Extract imaginary direction of the given type.
  
  Supported types:

      -  omatm1n20
      -  feomatm1n20
      -  onumm1n20
      -  feonumm1n20
  """
  #***************************************************************************************************
  cdef imdir_t indx
  cdef ord_t   order
  cdef omatm1n20      O, Ores
  cdef csr_matrix  S, Sres
  cdef dmat       R, Rres
  cdef feomatm1n20    F, Fres
  cdef onumm1n20    o, ores
  cdef coeff_t    r, rres
  cdef feonumm1n20     f, fres
  cdef coeff_t   crres
  cdef onumm1n20_t cores
  cdef feonumm1n20_t  cfres
  cdef darr_t    cRres
  cdef oarrm1n20_t   cOres
  cdef feoarrm1n20_t cFres
  cdef uint8_t res_flag = 1
  cdef object res

  indx, order = imdir(humdir)

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 
  
  # Scalar Types
  if   tval is onumm1n20:
    o = val
    if res_flag:
      
      ores = out
      onumm1n20_extract_deriv_to( indx, order, &o.num, &ores.num)

    else:

      cores = onumm1n20_extract_deriv( indx, order, &o.num)
      res   = onumm1n20.create(&cores)

    # end if 
  elif tval is feonumm1n20:
    f = val
    if res_flag:
      
      fres = out
      feonumm1n20_extract_deriv_to( indx, order, &f.num, &fres.num)

    else:

      cfres = feonumm1n20_extract_deriv( indx, order, &f.num)
      res   = feonumm1n20.create(&cfres)

    # end if
  # Array Types
  elif tval is omatm1n20:
    O = val
    if res_flag:
      
      Ores = out
      oarrm1n20_extract_deriv_to( indx, order, &O.arr, &Ores.arr)

    else:

      cOres = oarrm1n20_extract_deriv( indx, order, &O.arr)
      res   = omatm1n20.create(&cOres)

    # end if
  elif tval is feomatm1n20:    
    F = val
    if res_flag:

      Fres = out
      feoarrm1n20_extract_deriv_to( indx, order, &F.arr, &Fres.arr)

    else:

      cFres = feoarrm1n20_extract_deriv( indx, order, &F.arr)
      res   = feomatm1n20.create(&cFres)

    # end if 
  elif tval is csr_matrix:
    S = val
    if res_flag:
      
      Sres = out
      oarrm1n20_extract_deriv_to( indx, order, &S.arr, &Sres.arr)

    else:

      Sres = S.zeros_like()
      oarrm1n20_extract_deriv_to( indx, order, &S.arr, &Sres.arr)
      res = Sres 

    # end if 
  else:
    raise TypeError("Unsupported types at extract_deriv operation.")    
  # end if 

  if res_flag == 0:
    return res
  # end if 

#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cpdef get_im(object humdir, object val, object out = None):
  """
  PURPOSE:  Extract imaginary direction of the given type.
  
  Supported types:

      -  omatm1n20
      -  feomatm1n20
      -  onumm1n20
      -  feonumm1n20
  """
  #***************************************************************************************************
  cdef imdir_t indx
  cdef ord_t   order
  cdef omatm1n20      O, Ores
  cdef csr_matrix  S, Sres
  cdef dmat       R, Rres
  cdef feomatm1n20    F, Fres
  cdef onumm1n20    o, ores
  cdef coeff_t    r, rres
  cdef feonumm1n20     f, fres
  cdef coeff_t   crres
  cdef onumm1n20_t cores
  cdef feonumm1n20_t  cfres
  cdef darr_t    cRres
  cdef oarrm1n20_t   cOres
  cdef feoarrm1n20_t cFres
  cdef uint8_t res_flag = 1
  cdef object res

  indx, order = imdir(humdir)

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 
  
  # Scalar Types
  if   tval is onumm1n20:
    o = val
    if res_flag:
      
      ores = out
      onumm1n20_get_im_to_o( indx, order, &o.num, &ores.num)

    else:

      cores = onumm1n20_get_im_o( indx, order, &o.num)
      res   = onumm1n20.create(&cores)

    # end if 
  elif tval is feonumm1n20:
    f = val
    if res_flag:
      
      fres = out
      feonumm1n20_get_im_to( indx, order, &f.num, &fres.num)

    else:

      cfres = feonumm1n20_get_im( indx, order, &f.num)
      res   = feonumm1n20.create(&cfres)

    # end if
  # Array Types
  elif tval is omatm1n20:
    O = val
    if res_flag:
      
      Ores = out
      oarrm1n20_get_im_to( indx, order, &O.arr, &Ores.arr)

    else:

      cOres = oarrm1n20_get_im_o( indx, order, &O.arr)
      res   = omatm1n20.create(&cOres)

    # end if
  elif tval is feomatm1n20:    
    F = val
    if res_flag:

      Fres = out
      feoarrm1n20_get_im_to( indx, order, &F.arr, &Fres.arr)

    else:

      cFres = feoarrm1n20_get_im( indx, order, &F.arr)
      res   = feomatm1n20.create(&cFres)

    # end if 
  elif tval is csr_matrix:
    S = val
    if res_flag:
      
      Sres = out
      oarrm1n20_get_im_to( indx, order, &S.arr, &Sres.arr)

    else:

      Sres = S.zeros_like()
      oarrm1n20_get_im_to( indx, order, &S.arr, &Sres.arr)
      res = Sres 

    # end if 
  else:
    raise TypeError("Unsupported types at get_im operation.")    
  # end if 

  if res_flag == 0:
    return res
  # end if 

#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cpdef get_deriv(object humdir, object val, object out = None):
  """
  PURPOSE:  Extract imaginary direction of the given type.
  
  Supported types:

      -  omatm1n20
      -  feomatm1n20
      -  onumm1n20
      -  feonumm1n20
  """
  #***************************************************************************************************
  cdef imdir_t indx
  cdef ord_t   order
  cdef omatm1n20      O, Ores
  cdef csr_matrix  S, Sres
  cdef dmat       R, Rres
  cdef feomatm1n20    F, Fres
  cdef onumm1n20    o, ores
  cdef coeff_t    r, rres
  cdef feonumm1n20     f, fres
  cdef coeff_t   crres
  cdef onumm1n20_t cores
  cdef feonumm1n20_t  cfres
  cdef darr_t    cRres
  cdef oarrm1n20_t   cOres
  cdef feoarrm1n20_t cFres
  cdef uint8_t res_flag = 1
  cdef object res

  indx, order = imdir(humdir)

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 
  
  # Scalar Types
  if   tval is onumm1n20:
    o = val
    if res_flag:
      
      ores = out
      onumm1n20_get_deriv_to( indx, order, &o.num, &ores.num)

    else:

      cores = onumm1n20_get_deriv_o( indx, order, &o.num)
      res   = onumm1n20.create(&cores)

    # end if 
  elif tval is feonumm1n20:
    f = val
    if res_flag:
      
      fres = out
      feonumm1n20_get_deriv_to( indx, order, &f.num, &fres.num)

    else:

      cfres = feonumm1n20_get_deriv( indx, order, &f.num)
      res   = feonumm1n20.create(&cfres)

    # end if
  # Array Types
  elif tval is omatm1n20:
    O = val
    if res_flag:
      
      Ores = out
      oarrm1n20_get_deriv_to( indx, order, &O.arr, &Ores.arr)

    else:

      cOres = oarrm1n20_get_deriv_o( indx, order, &O.arr)
      res   = omatm1n20.create(&cOres)

    # end if
  elif tval is feomatm1n20:    
    F = val
    if res_flag:

      Fres = out
      feoarrm1n20_get_deriv_to( indx, order, &F.arr, &Fres.arr)

    else:

      cFres = feoarrm1n20_get_deriv( indx, order, &F.arr)
      res   = feomatm1n20.create(&cFres)

    # end if
  elif tval is csr_matrix:
    S = val
    if res_flag:
      
      Sres = out
      oarrm1n20_get_deriv_to( indx, order, &S.arr, &Sres.arr)

    else:

      Sres = S.zeros_like()
      oarrm1n20_get_deriv_to( indx, order, &S.arr, &Sres.arr)
      res = Sres 

    # end if 
  else:
    raise TypeError("Unsupported types at get_deriv operation.")    
  # end if 

  if res_flag == 0:
    return res
  # end if 

#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cpdef get_order_im(ord_t order, object val, object out = None):
  """
  PURPOSE:  Extract imaginary direction of the given type.
  
  Supported types:

      -  omatm1n20
      -  feomatm1n20
      -  onumm1n20
      -  feonumm1n20
  """
  #***************************************************************************************************
  cdef omatm1n20      O, Ores
  cdef csr_matrix  S, Sres
  cdef dmat       R, Rres
  cdef feomatm1n20    F, Fres
  cdef onumm1n20    o, ores
  cdef coeff_t    r, rres
  cdef feonumm1n20     f, fres
  cdef coeff_t   crres
  cdef onumm1n20_t cores
  cdef feonumm1n20_t  cfres
  cdef darr_t    cRres
  cdef oarrm1n20_t   cOres
  cdef feoarrm1n20_t cFres
  cdef uint8_t res_flag = 1
  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 
  
  # Scalar Types
  if   tval is onumm1n20:
    o = val
    if res_flag:
      
      ores = out
      onumm1n20_get_order_im_to( order, &o.num, &ores.num)

    else:

      cores = onumm1n20_get_order_im( order, &o.num)
      res   = onumm1n20.create(&cores)

    # end if 
  elif tval is feonumm1n20:
    f = val
    if res_flag:
      
      fres = out
      feonumm1n20_get_order_im_to( order, &f.num, &fres.num)

    else:

      cfres = feonumm1n20_get_order_im( order, &f.num)
      res   = feonumm1n20.create(&cfres)

    # end if
  # Array Types
  elif tval is omatm1n20:
    O = val
    if res_flag:
      
      Ores = out
      oarrm1n20_get_order_im_to( order, &O.arr, &Ores.arr)

    else:

      cOres = oarrm1n20_get_order_im( order, &O.arr)
      res   = omatm1n20.create(&cOres)

    # end if
  elif tval is feomatm1n20:    
    F = val
    if res_flag:

      Fres = out
      feoarrm1n20_get_order_im_to( order, &F.arr, &Fres.arr)

    else:

      cFres = feoarrm1n20_get_order_im( order, &F.arr)
      res   = feomatm1n20.create(&cFres)

    # end if
  elif tval is csr_matrix:
    S = val
    if res_flag:
      
      Sres = out
      oarrm1n20_get_order_im_to( order, &S.arr, &Sres.arr)

    else:

      Sres = S.zeros_like()
      oarrm1n20_get_order_im_to( order, &S.arr, &Sres.arr)
      res = Sres 

    # end if 
  else:
    raise TypeError("Unsupported types at get_deriv operation.")    
  # end if 

  if res_flag == 0:
    return res
  # end if 

#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cdef inline uint64_t binSearch_list(list a, uint64_t x):
  """
  PURPOSE:   Binary search in a sorted list. List is assumed to contain 64 bit integers.

  INPUTS:
      - a: List to search in
      - x: Value to search for

  OUTPUTS:
  
      - j: int
          Index at value (if present), or at the point to which
          it can be inserted maintaining order.

  """
  #***************************************************************************************************

  cdef uint64_t hi = len(a)
  cdef uint64_t lo = 0
  cdef uint64_t mid, v

  while lo < hi:

    mid = lo + (hi - lo) // 2

    v = a[mid]

    if v < x:

      lo = mid + 1

    else:

      hi = mid

    # end if

  # end while

  return lo

#-----------------------------------------------------------------------------------------------------

