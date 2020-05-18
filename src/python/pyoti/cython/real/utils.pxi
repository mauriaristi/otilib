
#*****************************************************************************************************
cpdef dmat dot(dmat A, dmat B):
  
  cdef darr_t res = darr_matmul( &A.arr, &B.arr )

  # TODO: Add check in python code.

  return dmat.create(&res)

#-----------------------------------------------------------------------------------------------------


#*****************************************************************************************************
cpdef dmat invert(dmat A):
  
  cdef darr_t res = darr_invert( &A.arr )

  # TODO: Add check in python code.

  return dmat.create(&res)

#-----------------------------------------------------------------------------------------------------



#*****************************************************************************************************
cpdef dmat transpose(dmat A):
  
  cdef darr_t res = darr_transpose( &A.arr )

  # TODO: Add check in python code.

  return dmat.create(&res)

#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cpdef coeff_t det(dmat A):
  
  return darr_det( &A.arr ) 

#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cpdef dmat eye(uint64_t size):
  
  cdef darr_t res = darr_zeros(size,size)
  cdef uint64_t i;

  for i in range(size):

    darr_set_item_ij( 1.0, i, i,&res)

  # end for 


  return dmat.create(&res)

#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cpdef dmat zeros(uint64_t nrows,uint64_t ncols):
  
  cdef darr_t res = darr_zeros(nrows,ncols)

  return dmat.create(&res)

#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cpdef dmat ones(uint64_t nrows,uint64_t ncols):
  
  cdef darr_t res = darr_ones(nrows,ncols)

  return dmat.create(&res)
  
#-----------------------------------------------------------------------------------------------------

















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