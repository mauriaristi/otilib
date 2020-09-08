#*****************************************************************************************************
cpdef feomatm8n2 fezeros( shape, uint64_t nip, bases_t nbases = 0, ord_t order = 0 ):
  """
  PURPOSE: create a feomatm8n2 matrix with the given shape and number of integration points
  """
  
  
  cdef feoarrm8n2_t res 
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
  
  res = feoarrm8n2_zeros(nrows, ncols, nip)  

  return feomatm8n2.create(&res)

#-----------------------------------------------------------------------------------------------------