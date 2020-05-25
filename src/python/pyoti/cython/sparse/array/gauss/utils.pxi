#*****************************************************************************************************
cpdef matsofe fezeros( shape, uint64_t nip, bases_t nbases = 0, ord_t order = 0 ):
  """
  PURPOSE: create a matsofe matrix with the given shape and number of integration points
  """
  global dhl
  
  cdef fearrso_t res 
  cdef uint64_t nrows, ncols, ZERO = 0, ONE = 1

  if isinstance(shape,tuple):
    
    ndim = len(shape)

    if ndim == 1:

      nrows = shape[ZERO]
      ncols = 1

    elif ndim == 2 :
      
      nrows = shape[ZERO]
      ncols = shape[ONE]

    else:

      raise ValueError("Only 2D matrices supported.")

    # end if 

  else:

    nrows = shape
    ncols = 1

  # end if 
  
  res = fearrso_zeros_bases(nrows, ncols, nip, nbases, order, dhl)  

  return matsofe.create(&res)

#-----------------------------------------------------------------------------------------------------