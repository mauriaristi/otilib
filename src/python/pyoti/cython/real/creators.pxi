#*****************************************************************************************************
cpdef e( object hum_dir, bases_t nbases = 0 , ord_t order = 0, uint64_t nip = 0):
  """
  PURPOSE:  To create a sotinum with value 1 at the specified imaginary direction
            in a human friendly manner

  """
  #***************************************************************************************************
  
  cdef object res
  
  # TODO: Support case for when hum_dir is 0, or its imaginary direction is 0.  
  res = number(0.0,nip=nip) 

  return res

#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cpdef zero( uint64_t nip = 0):
  """
  PURPOSE:  To create a real scalar with real value 1.

  """
  #***************************************************************************************************
  
  cdef object     res
  cdef dnumfe    fres

  if nip == 0:
    res = 0.0
  else:    
    fres = dnumfe(0.0, nip)
    res = fres
  # end if 

  return res

#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cpdef one( uint64_t nip = 0):
  """
  PURPOSE:  To create a real scalar with real value 1.

  """
  #***************************************************************************************************
  
  cdef object     res
  cdef dnumfe    fres

  if nip == 0:
    res = 1.0
  else:    
    fres = dnumfe(1.0, nip)
    res = fres
  # end if 

  return res

#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cpdef number( coeff_t num, uint64_t nip = 0):
  """
  PURPOSE:  To create a real with value num 

  """
  #***************************************************************************************************
  
  cdef object     res  
  cdef dnumfe    fres

  if nip == 0: 
    res = num
  else:    
    fres = dnumfe(num, nip)
    res = fres
  # end if 

  return res

#-----------------------------------------------------------------------------------------------------


#*****************************************************************************************************
cpdef eye(uint64_t size,   uint64_t nip = 0):
  """
  PURPOSE: Create identity matrix of shape: (size,size).

  """
  

  cdef darr_t   Rres
  cdef fedarr_t Fres

  if nip == 0:

    # This will create an dmat.
    Rres = darr_eye(size)
    return dmat.create(&Rres)

  else:

    # This will create a dmatfe
    Fres = fedarr_eye(size,nip)
    return dmatfe.create(&Fres)
  
  # end if 

#-----------------------------------------------------------------------------------------------------



#*****************************************************************************************************
cpdef array( object arr,   uint64_t nip = 0):
  """
  PURPOSE: Create a matrix for OTI algebra, according to the given array values.

  Array can be:
    - Scalar 
    - 0D array
    - 1D array
    - 2D array or
    - 3D array

  They can contain real or OTI values. No complex values are supported yet.

  """
  

  cdef uint64_t ncols, nrows, i, j, k 
  cdef darr_t   Rarr
  cdef fedarr_t Farr
  cdef dmat     Rres
  cdef dmatfe   Fres
  cdef object res
  cdef np.ndarray np_arr

  tin = type(array)
  
  if (tin is dmat) or (tin is dmatfe):

    # check if neccesary
    return arr.copy()

  else:

    # Try first generating a numpy array first.
    np_arr = np.array( arr, dtype=object)

    if   np_arr.ndim == 0:

      # Input is a scalar, Output shape: [1,1] x nip.
      nrows = 1
      ncols = 1

      if nip == 0:

        Oarr = darr_zeros( nrows, ncols)
        Rres = dmat.create(&Oarr)
        Rres[0,0] = np_arr.item(0)
        res = Rres

      else:
 
        Farr = fedarr_zeros( nrows, ncols, nip)
        Fres = dmatfe.create(&Farr)
        Fres[0,0] = np_arr.item(0)
        res = Fres

      # end if

    elif np_arr.ndim == 1:

      # Input is a one dimensional array, output shape: [nrows,1]x nip
      nrows = np_arr.shape[0]
      ncols = 1

      if nip == 0:
      
        Oarr = darr_zeros( nrows, ncols)
        Rres = dmat.create(&Oarr)
        for i in range(nrows):
          Rres[i,0] =  np_arr[i] # Column vectors.
        # end for 
        res = Rres

      else:
 
        Farr = fedarr_zeros( nrows, ncols, nip)
        Fres = dmatfe.create(&Farr)
        for i in range(nrows):
          Fres[i,0] =  np_arr[i] # Column vectors.
        # end for
        res = Fres

      # end if

    elif np_arr.ndim == 2:

      # Input is a two dimensional array, output shape: [nrows,ncols] x nip
      nrows = np_arr.shape[0]
      ncols = np_arr.shape[1]

      if nip == 0:
      
        Oarr = darr_zeros( nrows, ncols)
        Rres = dmat.create(&Oarr)
        for i in range(nrows):
          for j in range(ncols):
            
            Rres[i,j] = np_arr[i,j]

          # end for 
        # end for 
        res = Rres

      else:
 
        Farr = fedarr_zeros( nrows, ncols, nip)
        Fres = dmatfe.create(&Farr)
        for i in range(nrows):
          for j in range(ncols):
            
            Fres[i,j] = np_arr[i,j] 

          # end for 
        # end for 
        res = Fres

      # end if

    elif np_arr.ndim == 3:

      # Input is a two dimensional array, output shape: [nrows,ncols,nip]
      nrows = np_arr.shape[0]
      ncols = np_arr.shape[1]
      nip   = np_arr.shape[2]

      Farr = fedarr_zeros( nrows, ncols, nip)
      Fres = dmatfe.create(&Farr)

      for i in range(nrows):
        for j in range(ncols):
          for k in range(nip):
            
            Fres.set_ijk( np_arr[i,j,k], i, j, k  ) 

          # end for 
        # end for 
      # end for 
      res = Fres

    else:

      # Could not create a propper array.
      raise ValueError("Error: Can not create an array of such dimensions.")
      
    # end if 
  
  return res

#-----------------------------------------------------------------------------------------------------



#*****************************************************************************************************
cpdef zeros( object shape_in, uint64_t nip = 0):
  """
  PURPOSE: Create matrix filled with zeroes of shape: (nrows,ncols).

  """
  
  cdef uint64_t ncols, nrows
  cdef darr_t Rres
  cdef fedarr_t Fres
  
  nrows, ncols = process_shape_r(shape_in)

  if nip == 0:

    # This will create an dmat.
    Rres = darr_zeros(nrows,ncols)

    return dmat.create(&Rres)

  else:

    # This will create a dmatfe
    Fres = fedarr_zeros(nrows,ncols,nip)

    return dmatfe.create(&Fres)
  
  # end if 

#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cpdef ones( object shape_in, uint64_t nip = 0):
  """
  PURPOSE: Create matrix filled with ones of shape: (nrows,ncols).

  """
  
  cdef uint64_t ncols, nrows
  cdef darr_t Rres
  cdef fedarr_t Fres
  
  nrows, ncols = process_shape_r(shape_in)

  if nip == 0:

    # This will create an dmat.
    Rres = darr_ones(nrows,ncols)

    return dmat.create(&Rres)

  else:

    # This will create a dmatfe
    Fres = fedarr_ones(nrows,ncols,nip)
           # fedarr_ones(nrows,ncols,nip)

    return dmatfe.create(&Fres)
  
  # end if 
  
#-----------------------------------------------------------------------------------------------------

