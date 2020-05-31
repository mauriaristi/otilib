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
  cdef np.ndarray[object] np_arr

  tin = type(array)
  
  if (tin is matso) or (tin is matsofe):

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

        Oarr = arrso_zeros_bases( nrows, ncols, nbases, order, dhl)
        Ores = matso.create(&Oarr)
        Ores.set_ij( np_arr.item(0), 0, 0)
        res = Ores

      else:
 
        Farr = fearrso_zeros_bases( nrows, ncols, nip, nbases, order, dhl)
        Fres = matsofe.create(&Farr)
        Fres.set_ij( np_arr.item(0), 0, 0)
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
          Ores.set_ij( np_arr.item(i), i, 0)
        # end for 
        res = Ores

      else:
 
        Farr = fearrso_zeros_bases( nrows, ncols, nip, nbases, order, dhl)
        Fres = matsofe.create(&Farr)
        for i in range(nrows):
          Fres.set_ij( np_arr.item(i), i, 0)
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
            
            Ores.set_ij( np_arr[i,j], i, j) 

          # end for 
        # end for 
        res = Ores

      else:
 
        Farr = fearrso_zeros_bases( nrows, ncols, nip, nbases, order, dhl)
        Fres = matsofe.create(&Farr)
        for i in range(nrows):
          for j in range(ncols):
            
            Fres.set_ij( np_arr[i,j], i, j ) 

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
  PURPOSE:  Matrix determinant.
  
  Supported types:

      -  matso
      -  matsofe
      -  darr
      -  sotinum
      -  sotife
      -  real
  """
  #***************************************************************************************************
  cdef imdir_t indx
  cdef ord_t   order
  cdef matso      O, Ores
  cdef dmat       R, Rres
  cdef matsofe    F, Fres
  cdef sotinum    o, ores
  cdef coeff_t    r, rres
  cdef sotife     f, fres
  cdef coeff_t   crres
  cdef sotinum_t cores
  cdef fesoti_t  cfres
  cdef darr_t    cRres
  cdef arrso_t   cOres
  cdef fearrso_t cFres
  cdef uint8_t res_flag = 1
  cdef object res

  indx, order = imdir(humdir)

  tval = type(val)

  if out is None:
    res_flag = 0
  # end if 
  #
  if   tval is sotinum:
    o = val
    if res_flag:
      
      ores = out
      soti_truncate_im_to( indx, order, &o.num, &ores.num, dhl)

    else:

      cores = soti_truncate_im( indx, order, &o.num,  dhl)
      res   = sotinum.create(&cores)

    # end if 
  elif tval is sotife:
    f = val
    if res_flag:
      
      fres = out
      fesoti_truncate_im_to( indx, order, &f.num, &fres.num, dhl)

    else:

      cfres = fesoti_truncate_im( indx, order, &f.num,  dhl)
      res   = sotife.create(&cfres)

    # end if         
  # elif tval is matsofe:    
  #   F = val
  #   if res_flag:

  #     Fres = out
  #     fearrso_truncate_im_to( indx, order, &F.arr, &Fres.arr, dhl)

  #   else:

  #     cFres = fearrso_truncate_im( indx, order, &F.arr, dhl)
  #     res   = matsofe.create(&cFres)

  #   # end if 
  elif tval is matso:
    O = val
    if res_flag:
      
      Ores = out
      arrso_truncate_im_to( indx, order, &O.arr, &Ores.arr, dhl)

    else:

      cOres = arrso_truncate_im( indx, order, &O.arr,  dhl)
      res   = matso.create(&cOres)

    # end if
  else:
    raise TypeError("Unsupported types at cos operation.")    
  # end if 

  if res_flag == 0:
    return res
  # end if 

#-----------------------------------------------------------------------------------------------------









