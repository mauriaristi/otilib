
#*****************************************************************************************************
cpdef e( object hum_dir, uint64_t nip = 0):
  """
  PURPOSE:  To create a onumm2n5 with value 1 at the specified imaginary direction
            in a human friendly manner

  """
  #***************************************************************************************************
  

  

  cdef imdir_t indx_hd
  cdef ord_t order_hd, order_res
  cdef bases_t bases_hd
  cdef object res
  cdef onumm2n5_t ores
  cdef feonumm2n5 fres
  
  [indx_hd, order_hd] = imdir(hum_dir)

  if nip == 0: 

    # Create a onumm2n5
    ores = onumm2n5_create_r(0.0)

    # Set the coefficient to 1.
    onumm2n5_set_item(1.0, indx_hd, order_hd, &ores) 
    res = onumm2n5.create(&ores)

  else:
    
    fres = feonumm2n5(0.0, nip)
    feonumm2n5_set_im_r( 1.0, indx_hd, order_hd, &fres.num)

    res = fres

  # end if 

  return res

#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cpdef zero(  uint64_t nip = 0):
  """
  PURPOSE:  To create a scalar with real value 0 and every imaginary coefficient as zeros.

  """
  #***************************************************************************************************
  

  

  cdef object     res
  cdef onumm2n5_t ores
  cdef feonumm2n5    fres

  if nip == 0: 

    # Create a onumm2n5
    ores = onumm2n5_create_r(0.0)
    res = onumm2n5.create(&ores)

  else:
    
    fres = feonumm2n5(0.0, nip)
    res = fres

  # end if 

  return res

#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cpdef one( uint64_t nip = 0):
  """
  PURPOSE:  To create a scalar with real value 1 and every imaginary coefficient as zeros.

  """
  #***************************************************************************************************
  

  

  cdef object     res
  cdef onumm2n5_t ores
  cdef feonumm2n5    fres

  if nip == 0: 

    # Create a onumm2n5
    ores = onumm2n5_create_r(1.0)
    res = onumm2n5.create(&ores)

  else:
    
    fres = feonumm2n5(1.0, nip)
    res = fres

  # end if 

  return res

#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cpdef number( coeff_t num, uint64_t nip = 0):
  """
  PURPOSE:  To create a onumm2n5 with value 1 at the specified imaginary direction
            in a human friendly manner

  """
  #***************************************************************************************************
  

  

  cdef object     res
  cdef onumm2n5_t ores
  cdef feonumm2n5    fres

  if nip == 0: 

    # Create a onumm2n5
    ores = onumm2n5_create_r(num)
    res = onumm2n5.create(&ores)

  else:
    
    fres = feonumm2n5(num, nip)
    res = fres

  # end if 

  return res

#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cpdef eye(uint64_t size, uint64_t nip = 0):
  """
  PURPOSE: Create identity matrix of shape: (size,size).

  """
  

  cdef oarrm2n5_t   Ores
  cdef feoarrm2n5_t Fres

  if nip == 0:

    # This will create an omatm2n5.
    Ores = oarrm2n5_eye(size)

    return omatm2n5.create(&Ores)

  else:

    # This will create a feomatm2n5
    Fres = feoarrm2n5_eye(size,nip)

    return feomatm2n5.create(&Fres)
  
  # end if 

#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cpdef array( object arr,  uint64_t nip = 0):
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
  cdef oarrm2n5_t   Oarr
  cdef feoarrm2n5_t Farr
  cdef omatm2n5     Ores
  cdef feomatm2n5   Fres
  cdef object res
  cdef np.ndarray np_arr

  tin = type(array)
  
  if (tin is omatm2n5) or (tin is feomatm2n5):

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

        Oarr = oarrm2n5_zeros( nrows, ncols)
        Ores = omatm2n5.create(&Oarr)
        Ores[0,0] = np_arr.item(0)
        res = Ores

      else:
 
        Farr = feoarrm2n5_zeros( nrows, ncols, nip)
        Fres = feomatm2n5.create(&Farr)
        Fres[0,0] = np_arr.item(0)
        res = Fres

      # end if

    elif np_arr.ndim == 1:

      # Input is a one dimensional array, output shape: [nrows,1]x nip
      nrows = np_arr.shape[0]
      ncols = 1

      if nip == 0:
      
        Oarr = oarrm2n5_zeros( nrows, ncols)
        Ores = omatm2n5.create(&Oarr)
        for i in range(nrows):
          Ores[i,0] =  np_arr[i] # Column vectors.
        # end for 
        res = Ores

      else:
 
        Farr = feoarrm2n5_zeros( nrows, ncols, nip)
        Fres = feomatm2n5.create(&Farr)
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
      
        Oarr = oarrm2n5_zeros( nrows, ncols)
        Ores = omatm2n5.create(&Oarr)
        for i in range(nrows):
          for j in range(ncols):
            
            Ores[i,j] = np_arr[i,j]

          # end for 
        # end for 
        res = Ores

      else:
 
        Farr = feoarrm2n5_zeros( nrows, ncols, nip)
        Fres = feomatm2n5.create(&Farr)
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

      Farr = feoarrm2n5_zeros( nrows, ncols, nip)
      Fres = feomatm2n5.create(&Farr)

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
  cdef oarrm2n5_t Ores
  cdef feoarrm2n5_t Fres
  
  nrows, ncols = process_shape(shape_in)

  if nip == 0:

    # This will create an omatm2n5.
    Ores = oarrm2n5_zeros(nrows,ncols)

    return omatm2n5.create(&Ores)

  else:

    # This will create a feomatm2n5
    Fres = feoarrm2n5_zeros(nrows,ncols,nip)

    return feomatm2n5.create(&Fres)
  
  # end if 

#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cpdef ones( object shape_in,  uint64_t nip = 0):
  """
  PURPOSE: Create matrix filled with ones of shape: (nrows,ncols).

  """
  
  cdef uint64_t ncols, nrows
  cdef oarrm2n5_t Ores
  cdef feoarrm2n5_t Fres
  
  nrows, ncols = process_shape(shape_in)

  if nip == 0:

    # This will create an omatm2n5.
    Ores = oarrm2n5_ones(nrows,ncols)

    return omatm2n5.create(&Ores)

  else:

    # This will create a feomatm2n5
    Fres = feoarrm2n5_ones(nrows,ncols,nip)
           # feoarrm2n5_ones(nrows,ncols,nip,nbases,order)

    return feomatm2n5.create(&Fres)
  
  # end if 
  
#-----------------------------------------------------------------------------------------------------

