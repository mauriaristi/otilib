
#*****************************************************************************************************
cpdef e( object hum_dir, uint64_t nip = 0):
  """
  PURPOSE:  To create a {num_pytype} with value 1 at the specified imaginary direction
            in a human friendly manner

  """
  #***************************************************************************************************
  

  

  cdef imdir_t indx_hd
  cdef ord_t order_hd, order_res
  cdef bases_t bases_hd
  cdef object res
  cdef {num_type} ores
  cdef {fenum_pytype} fres
  
  [indx_hd, order_hd] = imdir(hum_dir)

  if nip == 0: 

    # Create a {num_pytype}
    ores = {num_func}_create_r(0.0)

    # Set the coefficient to 1.
    {num_func}_set_item(1.0, indx_hd, order_hd, &ores) 
    res = {num_pytype}.create(&ores)

  else:
    
    fres = {fenum_pytype}(0.0, nip)
    {fenum_func}_set_im_r( 1.0, indx_hd, order_hd, &fres.num)

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
  cdef {num_type} ores
  cdef {fenum_pytype}    fres

  if nip == 0: 

    # Create a {num_pytype}
    ores = {num_func}_create_r(0.0)
    res = {num_pytype}.create(&ores)

  else:
    
    fres = {fenum_pytype}(0.0, nip)
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
  cdef {num_type} ores
  cdef {fenum_pytype}    fres

  if nip == 0: 

    # Create a {num_pytype}
    ores = {num_func}_create_r(1.0)
    res = {num_pytype}.create(&ores)

  else:
    
    fres = {fenum_pytype}(1.0, nip)
    res = fres

  # end if 

  return res

#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cpdef number( coeff_t num, uint64_t nip = 0):
  """
  PURPOSE:  To create a {num_pytype} with value 1 at the specified imaginary direction
            in a human friendly manner

  """
  #***************************************************************************************************
  

  

  cdef object     res
  cdef {num_type} ores
  cdef {fenum_pytype}    fres

  if nip == 0: 

    # Create a {num_pytype}
    ores = {num_func}_create_r(num)
    res = {num_pytype}.create(&ores)

  else:
    
    fres = {fenum_pytype}(num, nip)
    res = fres

  # end if 

  return res

#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cpdef eye(uint64_t size, uint64_t nip = 0):
  """
  PURPOSE: Create identity matrix of shape: (size,size).

  """
  

  cdef {arr_type}   Ores
  cdef {fearr_type} Fres

  if nip == 0:

    # This will create an {arr_pytype}.
    Ores = {arr_func}_eye(size)

    return {arr_pytype}.create(&Ores)

  else:

    # This will create a {fearr_pytype}
    Fres = {fearr_func}_eye(size,nip)

    return {fearr_pytype}.create(&Fres)
  
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
  cdef {arr_type}   Oarr
  cdef {fearr_type} Farr
  cdef {arr_pytype}     Ores
  cdef {fearr_pytype}   Fres
  cdef object res
  cdef np.ndarray np_arr

  tin = type(array)
  
  if (tin is {arr_pytype}) or (tin is {fearr_pytype}):

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

        Oarr = {arr_func}_zeros( nrows, ncols)
        Ores = {arr_pytype}.create(&Oarr)
        Ores[0,0] = np_arr.item(0)
        res = Ores

      else:
 
        Farr = {fearr_func}_zeros( nrows, ncols, nip)
        Fres = {fearr_pytype}.create(&Farr)
        Fres[0,0] = np_arr.item(0)
        res = Fres

      # end if

    elif np_arr.ndim == 1:

      # Input is a one dimensional array, output shape: [nrows,1]x nip
      nrows = np_arr.shape[0]
      ncols = 1

      if nip == 0:
      
        Oarr = {arr_func}_zeros( nrows, ncols)
        Ores = {arr_pytype}.create(&Oarr)
        for i in range(nrows):
          Ores[i,0] =  np_arr[i] # Column vectors.
        # end for 
        res = Ores

      else:
 
        Farr = {fearr_func}_zeros( nrows, ncols, nip)
        Fres = {fearr_pytype}.create(&Farr)
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
      
        Oarr = {arr_func}_zeros( nrows, ncols)
        Ores = {arr_pytype}.create(&Oarr)
        for i in range(nrows):
          for j in range(ncols):
            
            Ores[i,j] = np_arr[i,j]

          # end for 
        # end for 
        res = Ores

      else:
 
        Farr = {fearr_func}_zeros( nrows, ncols, nip)
        Fres = {fearr_pytype}.create(&Farr)
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

      Farr = {fearr_func}_zeros( nrows, ncols, nip)
      Fres = {fearr_pytype}.create(&Farr)

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
  cdef {arr_type} Ores
  cdef {fearr_type} Fres
  
  nrows, ncols = process_shape(shape_in)

  if nip == 0:

    # This will create an {arr_pytype}.
    Ores = {arr_func}_zeros(nrows,ncols)

    return {arr_pytype}.create(&Ores)

  else:

    # This will create a {fearr_pytype}
    Fres = {fearr_func}_zeros(nrows,ncols,nip)

    return {fearr_pytype}.create(&Fres)
  
  # end if 

#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cpdef ones( object shape_in,  uint64_t nip = 0):
  """
  PURPOSE: Create matrix filled with ones of shape: (nrows,ncols).

  """
  
  cdef uint64_t ncols, nrows
  cdef {arr_type} Ores
  cdef {fearr_type} Fres
  
  nrows, ncols = process_shape(shape_in)

  if nip == 0:

    # This will create an {arr_pytype}.
    Ores = {arr_func}_ones(nrows,ncols)

    return {arr_pytype}.create(&Ores)

  else:

    # This will create a {fearr_pytype}
    Fres = {fearr_func}_ones(nrows,ncols,nip)
           # {fearr_func}_ones(nrows,ncols,nip,nbases,order)

    return {fearr_pytype}.create(&Fres)
  
  # end if 
  
#-----------------------------------------------------------------------------------------------------

