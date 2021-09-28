
#*****************************************************************************************************
cpdef e( object hum_dir, bases_t nbases = 0 , ord_t order = 0, uint64_t nip = 0):
  """
  PURPOSE:  To create a onumm20n1_t with value 1 at the specified imaginary direction
            in a human friendly manner

  """
  #***************************************************************************************************
  

  

  cdef imdir_t indx_hd
  cdef ord_t order_hd, order_res
  cdef bases_t bases_hd
  cdef object res
  cdef onumm20n1_t ores
  cdef feonumm20n1_t fres
  
  [indx_hd, order_hd] = imdir(hum_dir)

  order_res = max( order, order_hd )

  if nip == 0: 

    # Create a onumm20n1_t
    ores = onumm20n1_createReal(0.0, order_res)

    # Set the coefficient to 1.
    onumm20n1_set_item(1.0, indx_hd, order_hd, &ores) 

    res = onumm20n1_t.create(&ores)

  else:
    
    fres = feonumm20n1_t(0.0, nip, order = order_res, nbases = nbases)

    feonumm20n1_set_im_r( 1.0, indx_hd, order_hd, &fres.num)

    res = fres

  # end if 

  return res

#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cpdef zero( bases_t nbases = 0 , ord_t order = 0, uint64_t nip = 0):
  """
  PURPOSE:  To create a scalar with real value 0 and every imaginary coefficient as zeros.

  """
  #***************************************************************************************************
  

  

  cdef object     res
  cdef onumm20n1_t ores
  cdef feonumm20n1_t    fres

  if nip == 0: 

    # Create a onumm20n1_t
    ores = onumm20n1_createReal(0.0)

    res = onumm20n1_t.create(&ores)

  else:
    
    fres = feonumm20n1_t(0.0, nip, order = order, nbases = nbases)

    res = fres

  # end if 

  return res

#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cpdef one( bases_t nbases = 0 , ord_t order = 0, uint64_t nip = 0):
  """
  PURPOSE:  To create a scalar with real value 1 and every imaginary coefficient as zeros.

  """
  #***************************************************************************************************
  

  

  cdef object     res
  cdef onumm20n1_t ores
  cdef feonumm20n1_t    fres

  if nip == 0: 

    # Create a onumm20n1_t
    ores = onumm20n1_createReal(1.0)

    res = onumm20n1_t.create(&ores)

  else:
    
    fres = feonumm20n1_t(1.0, nip, order = order, nbases = nbases)

    res = fres

  # end if 

  return res

#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cpdef number( coeff_t num, bases_t nbases = 0 , ord_t order = 0, uint64_t nip = 0):
  """
  PURPOSE:  To create a onumm20n1_t with value 1 at the specified imaginary direction
            in a human friendly manner

  """
  #***************************************************************************************************
  

  

  cdef object     res
  cdef onumm20n1_t ores
  cdef feonumm20n1_t    fres

  if nip == 0: 

    # Create a onumm20n1_t
    ores = onumm20n1_createReal(num)

    res = onumm20n1_t.create(&ores)

  else:
    
    fres = feonumm20n1_t(num, nip, order = order, nbases = nbases)

    res = fres

  # end if 

  return res

#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cpdef eye(uint64_t size, bases_t nbases = 0, ord_t order = 0, uint64_t nip = 0):
  """
  PURPOSE: Create identity matrix of shape: (size,size).

  """
  

  cdef oarrm20n1_t   Ores
  cdef feoarrm20n1_t Fres

  if nip == 0:

    # This will create an oarrm20n1_t.
    Ores = oarrm20n1_eye(size,nbases,order)

    return oarrm20n1_t.create(&Ores)

  else:

    # This will create a feoarrm20n1_t
    Fres = feoarrm20n1_eye(size,nip,nbases,order)

    return feoarrm20n1_t.create(&Fres)
  
  # end if 

#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cpdef array( object arr, bases_t nbases = 0, ord_t order = 0, uint64_t nip = 0):
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
  cdef oarrm20n1_t   Oarr
  cdef feoarrm20n1_t Farr
  cdef oarrm20n1_t     Ores
  cdef feoarrm20n1_t   Fres
  cdef object res
  cdef np.ndarray np_arr

  tin = type(array)
  
  if (tin is oarrm20n1_t) or (tin is feoarrm20n1_t):

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

        Oarr = oarrm20n1_zeros( nrows, ncols)
        Ores = oarrm20n1_t.create(&Oarr)
        Ores[0,0] = np_arr.item(0)
        res = Ores

      else:
 
        Farr = feoarrm20n1_zeros( nrows, ncols, nip)
        Fres = feoarrm20n1_t.create(&Farr)
        Fres[0,0] = np_arr.item(0)
        res = Fres

      # end if

    elif np_arr.ndim == 1:

      # Input is a one dimensional array, output shape: [nrows,1]x nip
      nrows = np_arr.shape[0]
      ncols = 1

      if nip == 0:
      
        Oarr = oarrm20n1_zeros( nrows, ncols)
        Ores = oarrm20n1_t.create(&Oarr)
        for i in range(nrows):
          Ores[i,0] =  np_arr[i] # Column vectors.
        # end for 
        res = Ores

      else:
 
        Farr = feoarrm20n1_zeros( nrows, ncols, nip)
        Fres = feoarrm20n1_t.create(&Farr)
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
      
        Oarr = oarrm20n1_zeros( nrows, ncols)
        Ores = oarrm20n1_t.create(&Oarr)
        for i in range(nrows):
          for j in range(ncols):
            
            Ores[i,j] = np_arr[i,j]

          # end for 
        # end for 
        res = Ores

      else:
 
        Farr = feoarrm20n1_zeros( nrows, ncols, nip)
        Fres = feoarrm20n1_t.create(&Farr)
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

      Farr = feoarrm20n1_zeros( nrows, ncols, nip)
      Fres = feoarrm20n1_t.create(&Farr)

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
cpdef zeros( object shape_in, bases_t nbases = 0, ord_t order = 0, uint64_t nip = 0):
  """
  PURPOSE: Create matrix filled with zeroes of shape: (nrows,ncols).

  """
  
  cdef uint64_t ncols, nrows
  cdef oarrm20n1_t Ores
  cdef feoarrm20n1_t Fres
  
  nrows, ncols = process_shape(shape_in)

  if nip == 0:

    # This will create an oarrm20n1_t.
    Ores = oarrm20n1_zeros(nrows,ncols,nbases,order)

    return oarrm20n1_t.create(&Ores)

  else:

    # This will create a feoarrm20n1_t
    Fres = feoarrm20n1_zeros(nrows,ncols,nip,nbases,order)

    return feoarrm20n1_t.create(&Fres)
  
  # end if 

#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cpdef ones( object shape_in, bases_t nbases = 0, ord_t order = 0, uint64_t nip = 0):
  """
  PURPOSE: Create matrix filled with ones of shape: (nrows,ncols).

  """
  
  cdef uint64_t ncols, nrows
  cdef oarrm20n1_t Ores
  cdef feoarrm20n1_t Fres
  
  nrows, ncols = process_shape(shape_in)

  if nip == 0:

    # This will create an oarrm20n1_t.
    Ores = oarrm20n1_ones(nrows,ncols,nbases,order)

    return oarrm20n1_t.create(&Ores)

  else:

    # This will create a feoarrm20n1_t
    Fres = feoarrm20n1_ones(nrows,ncols,nip,nbases,order)
           # feoarrm20n1_ones(nrows,ncols,nip,nbases,order)

    return feoarrm20n1_t.create(&Fres)
  
  # end if 
  
#-----------------------------------------------------------------------------------------------------

