

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

      -  mdmat4
      -  mdmatfe4
      -  mdnum4
      -  mdnumfe4
  """
  #***************************************************************************************************
  cdef imdir_t indx
  cdef ord_t   order
  cdef mdmat4      O, Ores
  cdef csr_matrix  S, Sres
  cdef dmat       R, Rres
  cdef mdmatfe4    F, Fres
  cdef mdnum4    o, ores
  cdef coeff_t    r, rres
  cdef mdnumfe4     f, fres
  cdef coeff_t   crres
  cdef mdnum4_t cores
  cdef femdnum4_t  cfres
  cdef darr_t    cRres
  cdef mdarr4_t   cOres
  cdef femdarr4_t cFres
  cdef uint8_t res_flag = 1

  cdef uint64_t i
  cdef object res

  indx, order = imdir(humdir)

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 
  
  # Scalar Types
  if   tval is mdnum4:
    o = val
    if res_flag:
      
      ores = out
      mdnum4_truncate_im_to( indx, order, &o.num, &ores.num)

    else:

      cores = mdnum4_truncate_im( indx, order, &o.num)
      res   = mdnum4.create(&cores)

    # end if 
  elif tval is mdnumfe4:
    f = val
    if res_flag:
      
      fres = out
      femdnum4_truncate_im_to( indx, order, &f.num, &fres.num)

    else:

      cfres = femdnum4_truncate_im( indx, order, &f.num)
      res   = mdnumfe4.create(&cfres)

    # end if
  # Array Types
  elif tval is mdmat4:
    O = val
    if res_flag:
      
      Ores = out
      mdarr4_truncate_im_to( indx, order, &O.arr, &Ores.arr)

    else:

      cOres = mdarr4_truncate_im( indx, order, &O.arr)
      res   = mdmat4.create(&cOres)

    # end if
  elif tval is mdmatfe4:    
    F = val
    if res_flag:

      Fres = out
      femdarr4_truncate_im_to( indx, order, &F.arr, &Fres.arr)

    else:

      cFres = femdarr4_truncate_im( indx, order, &F.arr)
      res   = mdmatfe4.create(&cFres)

    # end if 
  elif tval is csr_matrix:
    S = val
    if res_flag:
      
      Sres = out
      mdarr4_truncate_im_to( indx, order, &S.arr, &Sres.arr)

    else:

      Sres = S.zeros_like()
      mdarr4_truncate_im_to( indx, order, &S.arr, &Sres.arr)
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

      -  mdmat4
      -  mdmatfe4
      -  mdnum4
      -  mdnumfe4
  """
  #***************************************************************************************************
  cdef imdir_t indx
  cdef ord_t   order
  cdef mdmat4      O, Ores
  cdef csr_matrix  S, Sres
  cdef dmat       R, Rres
  cdef mdmatfe4    F, Fres
  cdef mdnum4    o, ores
  cdef coeff_t    r, rres
  cdef mdnumfe4     f, fres
  cdef coeff_t   crres
  cdef mdnum4_t cores
  cdef femdnum4_t  cfres
  cdef darr_t    cRres
  cdef mdarr4_t   cOres
  cdef femdarr4_t cFres
  cdef uint8_t res_flag = 1
  cdef int64_t   i 
  cdef object res

  indx, order = imdir(humdir)

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 
  
  # Scalar Types
  if   tval is mdnum4:
    o = val
    if res_flag:
      
      ores = out
      mdnum4_extract_im_to( indx, order, &o.num, &ores.num)

    else:

      cores = mdnum4_extract_im( indx, order, &o.num)
      res   = mdnum4.create(&cores)

    # end if 
  elif tval is mdnumfe4:
    f = val
    if res_flag:
      
      fres = out
      femdnum4_extract_im_to( indx, order, &f.num, &fres.num)

    else:

      cfres = femdnum4_extract_im( indx, order, &f.num)
      res   = mdnumfe4.create(&cfres)

    # end if
  # Array Types
  elif tval is mdmat4:
    O = val
    if res_flag:
      
      Ores = out
      mdarr4_extract_im_to( indx, order, &O.arr, &Ores.arr)

    else:

      cOres = mdarr4_extract_im( indx, order, &O.arr)
      res   = mdmat4.create(&cOres)

    # end if
  elif tval is mdmatfe4:    
    F = val
    if res_flag:

      Fres = out
      femdarr4_extract_im_to( indx, order, &F.arr, &Fres.arr)

    else:

      cFres = femdarr4_extract_im( indx, order, &F.arr)
      res   = mdmatfe4.create(&cFres)

    # end if 
  elif tval is csr_matrix:
    S = val
    if res_flag:
      
      Sres = out
      mdarr4_extract_im_to( indx, order, &S.arr, &Sres.arr)

    else:

      Sres = S.zeros_like()
      mdarr4_extract_im_to( indx, order, &S.arr, &Sres.arr)
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

      -  mdmat4
      -  mdmatfe4
      -  mdnum4
      -  mdnumfe4
  """
  #***************************************************************************************************
  cdef imdir_t indx
  cdef ord_t   order
  cdef mdmat4      O, Ores
  cdef csr_matrix  S, Sres
  cdef dmat       R, Rres
  cdef mdmatfe4    F, Fres
  cdef mdnum4    o, ores
  cdef coeff_t    r, rres
  cdef mdnumfe4     f, fres
  cdef coeff_t   crres
  cdef mdnum4_t cores
  cdef femdnum4_t  cfres
  cdef darr_t    cRres
  cdef mdarr4_t   cOres
  cdef femdarr4_t cFres
  cdef uint8_t res_flag = 1
  cdef object res

  indx, order = imdir(humdir)

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 
  
  # Scalar Types
  if   tval is mdnum4:
    o = val
    if res_flag:
      
      ores = out
      mdnum4_extract_deriv_to( indx, order, &o.num, &ores.num)

    else:

      cores = mdnum4_extract_deriv( indx, order, &o.num)
      res   = mdnum4.create(&cores)

    # end if 
  elif tval is mdnumfe4:
    f = val
    if res_flag:
      
      fres = out
      femdnum4_extract_deriv_to( indx, order, &f.num, &fres.num)

    else:

      cfres = femdnum4_extract_deriv( indx, order, &f.num)
      res   = mdnumfe4.create(&cfres)

    # end if
  # Array Types
  elif tval is mdmat4:
    O = val
    if res_flag:
      
      Ores = out
      mdarr4_extract_deriv_to( indx, order, &O.arr, &Ores.arr)

    else:

      cOres = mdarr4_extract_deriv( indx, order, &O.arr)
      res   = mdmat4.create(&cOres)

    # end if
  elif tval is mdmatfe4:    
    F = val
    if res_flag:

      Fres = out
      femdarr4_extract_deriv_to( indx, order, &F.arr, &Fres.arr)

    else:

      cFres = femdarr4_extract_deriv( indx, order, &F.arr)
      res   = mdmatfe4.create(&cFres)

    # end if 
  elif tval is csr_matrix:
    S = val
    if res_flag:
      
      Sres = out
      mdarr4_extract_deriv_to( indx, order, &S.arr, &Sres.arr)

    else:

      Sres = S.zeros_like()
      mdarr4_extract_deriv_to( indx, order, &S.arr, &Sres.arr)
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

      -  mdmat4
      -  mdmatfe4
      -  mdnum4
      -  mdnumfe4
  """
  #***************************************************************************************************
  cdef imdir_t indx
  cdef ord_t   order
  cdef mdmat4      O, Ores
  cdef csr_matrix  S, Sres
  cdef dmat       R, Rres
  cdef mdmatfe4    F, Fres
  cdef mdnum4    o, ores
  cdef coeff_t    r, rres
  cdef mdnumfe4     f, fres
  cdef coeff_t   crres
  cdef mdnum4_t cores
  cdef femdnum4_t  cfres
  cdef darr_t    cRres
  cdef mdarr4_t   cOres
  cdef femdarr4_t cFres
  cdef uint8_t res_flag = 1
  cdef object res

  indx, order = imdir(humdir)

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 
  
  # Scalar Types
  if   tval is mdnum4:
    o = val
    if res_flag:
      
      ores = out
      mdnum4_get_im_to_o( indx, order, &o.num, &ores.num)

    else:

      cores = mdnum4_get_im_o( indx, order, &o.num)
      res   = mdnum4.create(&cores)

    # end if 
  elif tval is mdnumfe4:
    f = val
    if res_flag:
      
      fres = out
      femdnum4_get_im_to( indx, order, &f.num, &fres.num)

    else:

      cfres = femdnum4_get_im( indx, order, &f.num)
      res   = mdnumfe4.create(&cfres)

    # end if
  # Array Types
  elif tval is mdmat4:
    O = val
    if res_flag:
      
      Ores = out
      mdarr4_get_im_to( indx, order, &O.arr, &Ores.arr)

    else:

      cOres = mdarr4_get_im_o( indx, order, &O.arr)
      res   = mdmat4.create(&cOres)

    # end if
  elif tval is mdmatfe4:    
    F = val
    if res_flag:

      Fres = out
      femdarr4_get_im_to( indx, order, &F.arr, &Fres.arr)

    else:

      cFres = femdarr4_get_im( indx, order, &F.arr)
      res   = mdmatfe4.create(&cFres)

    # end if 
  elif tval is csr_matrix:
    S = val
    if res_flag:
      
      Sres = out
      mdarr4_get_im_to( indx, order, &S.arr, &Sres.arr)

    else:

      Sres = S.zeros_like()
      mdarr4_get_im_to( indx, order, &S.arr, &Sres.arr)
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

      -  mdmat4
      -  mdmatfe4
      -  mdnum4
      -  mdnumfe4
  """
  #***************************************************************************************************
  cdef imdir_t indx
  cdef ord_t   order
  cdef mdmat4      O, Ores
  cdef csr_matrix  S, Sres
  cdef dmat       R, Rres
  cdef mdmatfe4    F, Fres
  cdef mdnum4    o, ores
  cdef coeff_t    r, rres
  cdef mdnumfe4     f, fres
  cdef coeff_t   crres
  cdef mdnum4_t cores
  cdef femdnum4_t  cfres
  cdef darr_t    cRres
  cdef mdarr4_t   cOres
  cdef femdarr4_t cFres
  cdef uint8_t res_flag = 1
  cdef object res

  indx, order = imdir(humdir)

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 
  
  # Scalar Types
  if   tval is mdnum4:
    o = val
    if res_flag:
      
      ores = out
      mdnum4_get_deriv_to( indx, order, &o.num, &ores.num)

    else:

      cores = mdnum4_get_deriv_o( indx, order, &o.num)
      res   = mdnum4.create(&cores)

    # end if 
  elif tval is mdnumfe4:
    f = val
    if res_flag:
      
      fres = out
      femdnum4_get_deriv_to( indx, order, &f.num, &fres.num)

    else:

      cfres = femdnum4_get_deriv( indx, order, &f.num)
      res   = mdnumfe4.create(&cfres)

    # end if
  # Array Types
  elif tval is mdmat4:
    O = val
    if res_flag:
      
      Ores = out
      mdarr4_get_deriv_to( indx, order, &O.arr, &Ores.arr)

    else:

      cOres = mdarr4_get_deriv_o( indx, order, &O.arr)
      res   = mdmat4.create(&cOres)

    # end if
  elif tval is mdmatfe4:    
    F = val
    if res_flag:

      Fres = out
      femdarr4_get_deriv_to( indx, order, &F.arr, &Fres.arr)

    else:

      cFres = femdarr4_get_deriv( indx, order, &F.arr)
      res   = mdmatfe4.create(&cFres)

    # end if
  elif tval is csr_matrix:
    S = val
    if res_flag:
      
      Sres = out
      mdarr4_get_deriv_to( indx, order, &S.arr, &Sres.arr)

    else:

      Sres = S.zeros_like()
      mdarr4_get_deriv_to( indx, order, &S.arr, &Sres.arr)
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

      -  mdmat4
      -  mdmatfe4
      -  mdnum4
      -  mdnumfe4
  """
  #***************************************************************************************************
  cdef mdmat4      O, Ores
  cdef csr_matrix  S, Sres
  cdef dmat       R, Rres
  cdef mdmatfe4    F, Fres
  cdef mdnum4    o, ores
  cdef coeff_t    r, rres
  cdef mdnumfe4     f, fres
  cdef coeff_t   crres
  cdef mdnum4_t cores
  cdef femdnum4_t  cfres
  cdef darr_t    cRres
  cdef mdarr4_t   cOres
  cdef femdarr4_t cFres
  cdef uint8_t res_flag = 1
  cdef object res

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 
  
  # Scalar Types
  if   tval is mdnum4:
    o = val
    if res_flag:
      
      ores = out
      mdnum4_get_order_im_to( order, &o.num, &ores.num)

    else:

      cores = mdnum4_get_order_im( order, &o.num)
      res   = mdnum4.create(&cores)

    # end if 
  elif tval is mdnumfe4:
    f = val
    if res_flag:
      
      fres = out
      femdnum4_get_order_im_to( order, &f.num, &fres.num)

    else:

      cfres = femdnum4_get_order_im( order, &f.num)
      res   = mdnumfe4.create(&cfres)

    # end if
  # Array Types
  elif tval is mdmat4:
    O = val
    if res_flag:
      
      Ores = out
      mdarr4_get_order_im_to( order, &O.arr, &Ores.arr)

    else:

      cOres = mdarr4_get_order_im( order, &O.arr)
      res   = mdmat4.create(&cOres)

    # end if
  elif tval is mdmatfe4:    
    F = val
    if res_flag:

      Fres = out
      femdarr4_get_order_im_to( order, &F.arr, &Fres.arr)

    else:

      cFres = femdarr4_get_order_im( order, &F.arr)
      res   = mdmatfe4.create(&cFres)

    # end if
  elif tval is csr_matrix:
    S = val
    if res_flag:
      
      Sres = out
      mdarr4_get_order_im_to( order, &S.arr, &Sres.arr)

    else:

      Sres = S.zeros_like()
      mdarr4_get_order_im_to( order, &S.arr, &Sres.arr)
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

