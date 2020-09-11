# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::     CLASS  lil_matrix    :::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

cdef class csr_matrix:
  #---------------------------------------------------------------------------------------------------
  #------------------------------------   DEFINITION OF ATTRIBUTES   ---------------------------------
  #---------------------------------------------------------------------------------------------------
  
  #                                --->      Look in dense.pxd    <---

  #---------------------------------------------------------------------------------------------------  

  #***************************************************************************************************
  
  def __init__(self, arg1, shape=None, copy = True, preserve_in = False): 
    """
    PURPOSE:      Python level constructor of the csr_matrix class.

    DESCRIPTION:  Creates a new empty csr_matrix matrix. Note that this matrix does not support 
                  slicing or item get or set operations.

    INPUTS:
          - arg1:        Given constructors:

                          arg1 = lil_matrix. LIL matrix is converted to CSR type of sparse matrix.

                          arg1 = (data, indices, indptr). Matrix is created from given arrays.

                          arg1 = (data, ( rows, cols ) ). Coordinate creator. Currently not supported.

                          arg1 = (nrows, ncols). Empty matrix creator.

          - shape:       Default None. Defines the shape of the matrix. If not given, then it is inferred 
                         from the data. 

          - copy:        Default True. No use currently.

          - preserve_in: Default False. If True, the input matrix from arg1 is slowly freed in memory
                         with memory preservation in mind.

                 
    """
    #*************************************************************************************************
    
    cdef uint64_t i, j, k, ncols, nrows, nnz
    cdef lil_matrix lil
    cdef sotinum onum
    cdef list lilrowsi, lildatai
    
    targ1 = type(arg1)

    if targ1 == lil_matrix :
      # Create CSR matrix from lil matrix type
      lil = arg1
      self.nrows, self.ncols = lil.shape
      self.size = lil.size
      nnz = lil.nnz
      # Generate arrays.
      self.arr       = arrso_zeros_bases( nnz, 1, dhl)
      self.p_indices = <uint64_t*>malloc(           nnz*sizeof( uint64_t ) )
      self.p_indptr  = <uint64_t*>malloc( (lil.nrows+1)*sizeof( uint64_t ) )
      
      if (not self.p_indices) or (not self.p_indptr):
        raise MemoryError("Could not allocate arrays for sparse matrix.")
      # end if 

      self.p_indptr[0] = 0

      for i in range(self.nrows):

        self.p_indptr[i+1] = self.p_indptr[i] + len(lil.rows[i])
        k = self.p_indptr[i]

        lilrowsi = lil.rows[i]
        lildatai = lil.data[i]

        for j in range(len(lil.rows[i])):

          self.p_indices[k] = lilrowsi[j]
          onum = lildatai[j]
          
          soti_copy_to( &onum.num, &self.arr.p_data[k], dhl)
          
          k+=1

        # end for 
        
        # Remove data from source.
        if not preserve_in:
          lil.rows[i] = []
          lil.data[i] = []
        # end if 

        lilrowsi = []
        lildatai = []

      # end for 

    elif targ1 == tuple:
      
      if len(arg1) == 3: # Same as in scipy csr sparse.

        (data, indices, indptr) = arg1

        if shape is None:

          nrows = len(indptr)-1
          ncols = max(indices)+1

        else:

          nrows,ncols = shape

        # end if 

        self.nrows = nrows
        self.ncols = ncols
        
        self.size = nrows*ncols
        # copy arrays

        nnz = indices.size

        # Generate arrays.
        self.arr       = arrso_zeros_bases( nnz, 1, dhl)
        self.p_indices = <uint64_t*>malloc(       nnz*sizeof( uint64_t ) )
        self.p_indptr  = <uint64_t*>malloc( (nrows+1)*sizeof( uint64_t ) )
        
        if (not self.p_indices) or (not self.p_indptr):
          raise MemoryError("Could not allocate arrays for sparse matrix.")
        # end if 

        # Copy indptr
        for i in range(nrows+1):
          self.p_indptr[i] = indptr[i]
        # end for 

        # Copy data and indices.
        for i in range(nnz):
          
          self.p_indices[i] = indices[i]

          if type(data[i]) == sotinum:

            onum = data[i]
            soti_copy_to( &onum.num, &self.arr.p_data[i], dhl)

          else:
            
            self.arr.p_data[i] = soti_create_r( data[i] )

          # end if   

        # end for

      elif len(arg1) == 2 and type(arg1[0]) == int and type(arg1[1]) == int:

        self.nrows, self.ncols = arg1
        self.size = self.nrows * self.ncols

        self.p_indices = NULL
        self.p_indptr  = NULL
        self.arr    = arrso_init()
        
      elif len(arg1) == 2 and type(arg1[1]) == tuple:
        # COO creator
        raise ValueError(" ( data, (rows, cols) ) input format not currently implemented for CSR matrix.")

      else:

        raise ValueError("Wrong imput format to create CSR matrix.")

      #end if       

    else:

      raise ValueError("Wrong imput format to create CSR matrix.")

    # end if 

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  def __dealloc__(self): 
    """
    PURPOSE:      Free memory in csr matrix. 
    """
    #************************************************************************************************* 

    arrso_free(&self.arr)

    if self.p_indices:
      free(self.p_indices)
    # end if

    if self.p_indptr:
      free(self.p_indptr)
    # end if 

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  @property
  def nnz(self): 
    """
    PURPOSE:      Return the number of non-zero elements in the stored matrix. 
    """
    #************************************************************************************************* 

    return self.arr.nrows

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  @property
  def shape(self): 
    """
    PURPOSE:      Return the shape of the stored matrix. 
    """
    #*************************************************************************************************

    return (self.nrows,self.ncols)

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  @property
  def data(self): 
    """
    PURPOSE:      Return the data array of the stored matrix. 
    """
    #*************************************************************************************************

    return matso.create(&self.arr, FLAGS=0)

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  @property
  def indices(self): 
    """
    PURPOSE:      Return the indices array the stored matrix. 
    """
    #*************************************************************************************************
    cdef uint64_t[::1] indices = np.zeros(self.nnz,dtype=np.uint64)
    cdef uint64_t i
    
    for i in range(self.nnz):
      indices[i] = self.p_indices[i]
    # end for 

    return np.asarray(indices)

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  @property
  def indptr(self): 
    """
    PURPOSE:      Return the indptr array the stored matrix. 
    """
    #*************************************************************************************************
    cdef uint64_t[::1] indptr = np.zeros(self.nrows+1,dtype=np.uint64)
    cdef uint64_t i
    
    for i in range(self.nrows+1):
      indptr[i] = self.p_indptr[i]
    # end for 

    return np.asarray(indptr)

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  @property
  def order(self): 
    """
    PURPOSE:      Return the shape of the stored matrix. 
    """
    #*************************************************************************************************
    cdef ord_t order = 0, ordi
    cdef sotinum onum
    cdef uint64_t i

    order = arrso_get_order(&self.arr)
    
    return order

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  @property
  def real(self):
    """
    PURPOSE:      Get a numpy array with all coefficients in the real direction.

    """
    #*************************************************************************************************

    cdef np.ndarray[coeff_t, ndim=1] data
    cdef uint64_t i,j,k = 0
    data = np.empty( (self.nnz,), dtype=np.float64 )

    for i in range( self.arr.size ):

      data[i] = self.arr.p_data[i].<<<real_str>>>

    # end for

    return sci_spr.csr_matrix((data, self.indices, self.indptr ), shape = self.shape)

  #---------------------------------------------------------------------------------------------------

  #*************************************************************************************************** 
  def __repr__(self):
    """
    PURPOSE:      Representation of the object.
  
    """
    #*************************************************************************************************

    out  = "<{0} sparse matrix of OTI numbers with \n".format(self.shape)
    out += "         {0} stored elements in Compressed Sparse Row format>".format(self.nnz)

    return out

  #--------------------------------------------------------------------------------------------------- 
  
  #***************************************************************************************************
  def __str__(self):
    """
    PURPOSE:      Create a string representation of the object.    
    """
    #*************************************************************************************************
    global dhl
  
    cdef sotinum   onum = sotinum(0.0)
    cdef uint64_t i, j, k
    out  = ""

    for i in range( self.nrows ):

      for j in range(self.p_indptr[i], self.p_indptr[i+1] ):
        onum.num = self.arr.p_data[j]

        out += "({0:3d},{1:3d}) {2}\n".format( i, self.p_indices[j], str(onum) )
        
      # end for

    # end for

    return out

  #---------------------------------------------------------------------------------------------------  

  #***************************************************************************************************
  def copy(self):
    """
    PURPOSE: Deep copy to a new object.
    """
    #*************************************************************************************************
    
    global dhl

    cdef csr_matrix res = <csr_matrix> csr_matrix.__new__(csr_matrix)
    cdef uint64_t i, k

    res.arr       = arrso_zeros_bases( self.nnz, 1, dhl)
    res.p_indices = <uint64_t*>malloc(       self.nnz*sizeof( uint64_t ) )
    res.p_indptr  = <uint64_t*>malloc( (self.nrows+1)*sizeof( uint64_t ) )
    
    if (not self.p_indices) or (not self.p_indptr):
      raise MemoryError("Could not allocate arrays for sparse matrix.")
    # end if

    res.nrows   = self.nrows
    res.ncols   = self.ncols
    res.size    = self.size

    memcpy(res.p_indices, self.p_indices, self.nnz*sizeof(uint64_t) )
    memcpy(res.p_indptr, self.p_indptr,  (self.nrows+1)*sizeof(uint64_t) )

    arrso_copy_to( &self.arr, &res.arr, dhl)

    return res

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  def zeros_like(self):
    """
    PURPOSE: Create new object with OTI zeros in positions.
    """
    #*************************************************************************************************
    
    cdef csr_matrix res = <csr_matrix> csr_matrix.__new__(csr_matrix)
    cdef uint64_t i, k
    
    res.arr       = arrso_zeros_bases( self.nnz, 1, dhl)
    res.p_indices = <uint64_t*>malloc(       self.nnz*sizeof( uint64_t ) )
    res.p_indptr  = <uint64_t*>malloc( (self.nrows+1)*sizeof( uint64_t ) )
    
    if (not self.p_indices) or (not self.p_indptr):
      raise MemoryError("Could not allocate arrays for sparse matrix.")
    # end if

    res.nrows   = self.nrows
    res.ncols   = self.ncols
    res.size    = self.size

    memcpy(res.p_indices, self.p_indices, self.nnz*sizeof(uint64_t) )
    memcpy(res.p_indptr, self.p_indptr,  (self.nrows+1)*sizeof(uint64_t) )

    return res
  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  def __pow__(self, n,z):
    """
    PURPOSE:      Power function oversload
    """
    #*************************************************************************************************
    
    global dhl

    cdef uint64_t i
    cdef csr_matrix S = self, res

    res = S.zeros_like()

    arrso_pow_to( &S.arr, n, &res.arr, dhl)

    return res 

  #---------------------------------------------------------------------------------------------------  

  #***************************************************************************************************
  cpdef get_deriv(self, object hum_dir ):
    """
    PURPOSE: Get the corresponding derivative of the system.
    """
    #*************************************************************************************************
    global dhl

    cdef imdir_t indx
    cdef ord_t  order
    cdef uint64_t i
    cdef csr_matrix res

    indx, order = imdir(hum_dir)
    res = self.zeros_like()
    
    arrso_get_deriv_to( indx, order, &self.arr, &res.arr, dhl)

    return res 

  #---------------------------------------------------------------------------------------------------  

  #***************************************************************************************************
  cpdef get_im(self, object hum_dir ):
    """
    PURPOSE: Get the corresponding derivative of the system.
    """
    #*************************************************************************************************
    global dhl

    cdef imdir_t indx
    cdef ord_t  order
    cdef uint64_t i, j, k
    cdef csr_matrix res

    indx, order = imdir(hum_dir)
    res = self.zeros_like()
  
    arrso_get_im_to( indx, order, &self.arr, &res.arr, dhl)

    return res 

  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  cpdef extract_im(self, object hum_dir):
    """
    PURPOSE: Get the corresponding imaginary direction in the matso object.
    """
    #*************************************************************************************************
    global dhl

    cdef imdir_t indx
    cdef ord_t  order
    cdef uint64_t i, j, k
    cdef csr_matrix res

    indx, order = imdir(hum_dir)
    res = self.zeros_like()

    arrso_extract_im_to( indx, order, &self.arr, &res.arr, dhl)

    return res 

  #---------------------------------------------------------------------------------------------------
  
  #***************************************************************************************************
  cpdef  extract_deriv(self, object hum_dir):
    """
    PURPOSE: Get the corresponding derivative in the matso object, as OTI number.
    """
    #*************************************************************************************************
    global dhl

    cdef imdir_t indx
    cdef ord_t  order
    cdef uint64_t i, j, k
    cdef csr_matrix res

    indx, order = imdir(hum_dir)
    res = self.zeros_like()

    arrso_extract_deriv_to( indx, order, &self.arr, &res.arr, dhl)

    return res 

  #---------------------------------------------------------------------------------------------------
  
  #***************************************************************************************************
  cpdef  get_order_im(self, ord_t order):
    """
    PURPOSE: Get the corresponding derivative in the matso object, as OTI number.
    """
    #*************************************************************************************************
    global dhl
    
    cdef uint64_t i, j, k
    cdef csr_matrix res

    res = self.zeros_like()

    arrso_get_order_im_to( order, &self.arr, &res.arr, dhl)

    return res 

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  cpdef  truncate( self, object hum_dir):
    """
    PURPOSE:      to set a specific imaginary direction as given.

    """
    #*************************************************************************************************
    global dhl

    cdef imdir_t indx
    cdef ord_t  order
    cdef uint64_t i, j, k
    cdef csr_matrix res

    indx, order = imdir(hum_dir)
    res = self.zeros_like()

    arrso_truncate_im_to( indx, order, &self.arr, &res.arr, dhl)

    return res 

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  def get_active_bases(self):
    """
    PORPUSE: Get the bases with non-zero coefficients in the OTI number.
    """
    global dhl

    cdef matso tmp
    
    tmp = matso.create(&self.arr,FLAGS=0)

    return tmp.get_active_bases()

  #---------------------------------------------------------------------------------------------------


# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# :::::::::::::::::::::::::::::::::::: END OF CLASS csr_matrix ::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::




















# ****************************************************************************************************
cdef void csrmatrix_matmul_SO_to(csr_matrix lhs, matso rhs, matso res):
  """
  PORPUSE:  Perform matrix-matrix multiplication between csr matrix and dense matrix.

  """

  global dhl

  cdef uint64_t i, j, k, l;
  cdef ord_t order;
  cdef sotinum_t tmp;
  cdef sotinum olhs;

  # check for dimensions.
  if (lhs.ncols != rhs.nrows) or (lhs.nrows != res.nrows) or (rhs.ncols != res.ncols):
    raise ValueError("Shapes < {0}, {1} > = < {2} > not aligned.".format(lhs.shape,rhs.shape,res.shape))

  # end if

  # Extract temporal 5.

  for i in range(lhs.nrows):
      
    for j in range(rhs.ncols):

      # tmp = 0
      soti_set_r( 0.0, &tmp, dhl)

      for l in range( lhs.p_indptr[i], lhs.p_indptr[i+1] ):

        # tmp = arr1[i,k] * arr2[k,j] + tmp
        k = lhs.p_indices[l]
        

        soti_gem_oo_to( &lhs.arr.p_data[l],
                        &rhs.arr.p_data[ j + k * rhs.ncols ],
                        &tmp, &tmp, dhl)

      # end for

      arrso_set_item_ij_o( &tmp, i, j, &res.arr, dhl)

    # end for

  # end for 

# ----------------------------------------------------------------------------------------------------




# ****************************************************************************************************
cdef matso csrmatrix_matmul_SO(csr_matrix lhs, matso rhs):
  """
  PORPUSE:  Perform matrix-matrix multiplication between csr matrix and dense matrix.

  """
  
  global dhl
  cdef matso res
  
  res = zeros((lhs.nrows,rhs.ncols))

  csrmatrix_matmul_SO_to( lhs, rhs, res)

  return res

# ----------------------------------------------------------------------------------------------------





# ****************************************************************************************************
cdef void csrmatrix_trunc_matmul_SO_to(ord_t ord_lhs, csr_matrix lhs, ord_t ord_rhs, matso rhs, matso res):
  """
  PORPUSE:  Perform matrix-matrix multiplication between csr matrix and dense matrix.

  """

  global dhl

  cdef uint64_t i, j, k, l;
  cdef ord_t order;
  cdef sotinum_t tmp;
  cdef sotinum olhs;

  # check for dimensions.
  if (lhs.ncols != rhs.nrows) or (lhs.nrows != res.nrows) or (rhs.ncols != res.ncols):
    raise ValueError("Shapes < {0}, {1} > = < {2} > not aligned.".format(lhs.shape,rhs.shape,res.shape))

  # end if

  # Extract temporal 5.

  for i in range(lhs.nrows):
      
    for j in range(rhs.ncols):

      # tmp = 0
      soti_set_r( 0.0, &tmp, dhl)

      for l in range( lhs.p_indptr[i], lhs.p_indptr[i+1] ):

        # tmp = arr1[i,k] * arr2[k,j] + tmp
        k = lhs.p_indices[l]

        soti_trunc_gem_oo_to( ord_lhs, &lhs.arr.p_data[l], 
                              ord_rhs, &rhs.arr.p_data[ j + k * rhs.ncols ],
                              &tmp, &tmp, dhl)

      # end for

      arrso_set_item_ij_o( &tmp, i, j, &res.arr, dhl)

    # end for

  # end for 

# ----------------------------------------------------------------------------------------------------




# ****************************************************************************************************
cdef matso csrmatrix_trunc_matmul_SO(ord_t ord_lhs, csr_matrix lhs, ord_t ord_rhs, matso rhs):
  """
  PORPUSE:  Perform matrix-matrix multiplication between csr matrix and dense matrix.

  """
  
  global dhl
  cdef matso res
  
  res = zeros((lhs.nrows,rhs.ncols))

  csrmatrix_trunc_matmul_SO_to(ord_lhs, lhs, ord_rhs, rhs, res)

  return res

# ----------------------------------------------------------------------------------------------------
