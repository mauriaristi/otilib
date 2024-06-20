
#*****************************************************************************************************
cpdef e( object hum_dir, bases_t nbases = 0 , ord_t order = 0, uint64_t nip = 0):
  """
  This function creates a sotinum with value 1 along the specified imaginary direction
  in a human friendly manner.

  
  :param hum_dir: Object that defines the imaginary direction in a human-friendly manner.
  :type hum_dir: list or int.

  :param nbases: Defines the number of imaignary bases of the number. If not set, it will only 
      allocate memory for a single imaginary direction at the specified order. 
  :type nbases: int, optional. Default nbases=0.

  :param order: Optional. Defines the truncation order of the number. The truncation order is defined 
      as the maximum between the order of the given imaginary direction and the order given
      in this parameter.
  :type order: int, optional. Default order=0.

  :param nip: Defines the number of integration points to create this number. This is useful when
      using this with the Gauss-types for numerical integration parameters. If nip is 0,
      then standard types will be used. If nip > 0, then a scalar gauss type will be created. 
  :type nip: int, optional. Default nip=0.
  
  """
  #***************************************************************************************************
  

  global dhl

  cdef imdir_t indx_hd
  cdef ord_t order_hd, order_res
  cdef bases_t bases_hd
  cdef object res
  cdef sotinum_t ores
  cdef sotife fres
  
  [indx_hd, order_hd] = imdir(hum_dir)

  order_res = max( order, order_hd )

  if nip == 0: 

    # Create a sotinum
    ores = soti_createReal(0.0, order_res, dhl)

    # Set the coefficient to 1.
    soti_set_item(1.0, indx_hd, order_hd, &ores, dhl) 

    res = sotinum.create(&ores)

  else:
    
    fres = sotife(0.0, nip, order = order_res, nbases = nbases)

    fesoti_set_im_r( 1.0, indx_hd, order_hd, &fres.num, dhl)

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
  

  global dhl

  cdef object     res
  cdef sotinum_t ores
  cdef sotife    fres

  if nip == 0: 

    # Create a sotinum
    ores = soti_createReal_bases(0.0, nbases, order, dhl)

    res = sotinum.create(&ores)

  else:
    
    fres = sotife(0.0, nip, order = order, nbases = nbases)

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
  

  global dhl

  cdef object     res
  cdef sotinum_t ores
  cdef sotife    fres

  if nip == 0: 

    # Create a sotinum
    ores = soti_createReal_bases(1.0, nbases, order, dhl)

    res = sotinum.create(&ores)

  else:
    
    fres = sotife(1.0, nip, order = order, nbases = nbases)

    res = fres

  # end if 

  return res

#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cpdef number( coeff_t num, bases_t nbases = 0 , ord_t order = 0, uint64_t nip = 0):
  """
  PURPOSE:  To create a sotinum with value 1 at the specified imaginary direction
            in a human friendly manner

  """
  #***************************************************************************************************
  

  global dhl

  cdef object     res
  cdef sotinum_t ores
  cdef sotife    fres

  if nip == 0: 

    # Create a sotinum
    ores = soti_createReal_bases(num, nbases, order, dhl)

    res = sotinum.create(&ores)

  else:
    
    fres = sotife(num, nip, order = order, nbases = nbases)

    res = fres

  # end if 

  return res

#-----------------------------------------------------------------------------------------------------


#*****************************************************************************************************
cpdef eye(uint64_t size, bases_t nbases = 0, ord_t order = 0, uint64_t nip = 0):
  """
  PURPOSE: Create identity matrix of shape: (size,size).

  """
  global dhl

  cdef arrso_t   Ores
  cdef fearrso_t Fres

  if nip == 0:

    # This will create an matso.
    Ores = arrso_eye_bases(size,nbases,order,dhl)

    return matso.create(&Ores)

  else:

    # This will create a matsofe
    Fres = fearrso_eye_bases(size,nip,nbases,order,dhl)

    return matsofe.create(&Fres)
  
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
  global dhl

  cdef uint64_t ncols, nrows, i, j, k 
  cdef arrso_t   Oarr
  cdef fearrso_t Farr
  cdef matso     Ores
  cdef matsofe   Fres
  cdef object res
  cdef np.ndarray np_arr

  tin = type(array)
  
  if (tin is matso) or (tin is matsofe):

    # check if neccesary
    return arr.copy()

  else:

    # Try generating a numpy array first.
    np_arr = np.array( arr, dtype=object)

    if   np_arr.ndim == 0:

      # Input is a scalar, Output shape: [1,1] x nip.
      nrows = 1
      ncols = 1

      if nip == 0:

        Oarr = arrso_zeros_bases( nrows, ncols, nbases, order, dhl)
        Ores = matso.create(&Oarr)
        Ores[0,0] = np_arr.item(0)
        res = Ores

      else:
 
        Farr = fearrso_zeros_bases( nrows, ncols, nip, nbases, order, dhl)
        Fres = matsofe.create(&Farr)
        Fres[0,0] = np_arr.item(0)
        res = Fres

      # end if

    elif np_arr.ndim == 1:

      # Input is a one dimensional array, output shape: [nrows,1]x nip
      nrows = np_arr.shape[0]
      ncols = 1

      if nip == 0:
      
        Oarr = arrso_zeros_bases( nrows, ncols, nbases, order, dhl)
        Ores = matso.create(&Oarr)
        for i in range(nrows):
          Ores[i,0] =  np_arr[i] # Column vectors.
        # end for 
        res = Ores

      else:
 
        Farr = fearrso_zeros_bases( nrows, ncols, nip, nbases, order, dhl)
        Fres = matsofe.create(&Farr)
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
      
        Oarr = arrso_zeros_bases( nrows, ncols, nbases, order, dhl)
        Ores = matso.create(&Oarr)
        for i in range(nrows):
          for j in range(ncols):
            
            Ores[i,j] = np_arr[i,j]

          # end for 
        # end for 
        res = Ores

      else:
 
        Farr = fearrso_zeros_bases( nrows, ncols, nip, nbases, order, dhl)
        Fres = matsofe.create(&Farr)
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

      Farr = fearrso_zeros_bases( nrows, ncols, nip, nbases, order, dhl)
      Fres = matsofe.create(&Farr)

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
  global dhl
  cdef uint64_t ncols, nrows
  cdef arrso_t Ores
  cdef fearrso_t Fres
  
  nrows, ncols = process_shape(shape_in)

  if nip == 0:

    # This will create an matso.
    Ores = arrso_zeros_bases(nrows,ncols,nbases,order,dhl)

    return matso.create(&Ores)

  else:

    # This will create a matsofe
    Fres = fearrso_zeros_bases(nrows,ncols,nip,nbases,order,dhl)

    return matsofe.create(&Fres)
  
  # end if 

#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cpdef ones( object shape_in, bases_t nbases = 0, ord_t order = 0, uint64_t nip = 0):
  """
  PURPOSE: Create matrix filled with ones of shape: (nrows,ncols).

  """
  global dhl
  cdef uint64_t ncols, nrows
  cdef arrso_t Ores
  cdef fearrso_t Fres
  
  nrows, ncols = process_shape(shape_in)


  if nip == 0:

    # This will create an matso.
    Ores = arrso_ones_bases(nrows,ncols,nbases,order,dhl)

    return matso.create(&Ores)

  else:

    # This will create a matsofe
    Fres = fearrso_ones_bases(nrows,ncols,nip,nbases,order,dhl)
           # fearrso_ones_bases(nrows,ncols,nip,nbases,order,dhl)

    return matsofe.create(&Fres)
  
  # end if 
  
#-----------------------------------------------------------------------------------------------------

