
#*****************************************************************************************************
cdef np.ndarray darr_2_npy(darr_t* array ):
  """
    
  PURPOSE:      Convert a darray_t to numpy array for test purposes.

  """
  cdef np.ndarray nparray
  cdef uint64_t i, j

  nparray = np.empty((array[0].nrows,array[0].ncols),dtype = np.float64)

  for i in range(array[0].nrows):
    
    for j in range(array[0].ncols):

      nparray[i,j] = darr_get_item_ij(array,i,j)

    # end for

  # end for

  return nparray

#-----------------------------------------------------------------------------------------------------




#*****************************************************************************************************
cdef (uint64_t,uint64_t) process_shape_r(object shape_in):
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

