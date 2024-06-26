






# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::     CLASS  lil_{arr_pytype}    :::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
cdef class csr_{arr_pytype}:
  #---------------------------------------------------------------------------------------------------
  #------------------------------------   DEFINITION OF ATTRIBUTES   ---------------------------------
  #---------------------------------------------------------------------------------------------------
  
  #                                --->      Look in dense.pxd    <---

  #---------------------------------------------------------------------------------------------------  

  #***************************************************************************************************
  
  def __init__(self, arg1, shape=None, copy = True): 
    """
    PURPOSE:      Python level constructor of the csr_{arr_pytype} class.

    DESCRIPTION:  Creates a new empty csr_{arr_pytype} matrix.
                 
    """
    #*************************************************************************************************
    
    cdef uint64_t i, j, k, ncols, nrows
    cdef lil_{arr_pytype} lil
    
    targ1 = type(arg1)

    if targ1 == lil_{arr_pytype} :
      # Create CSR matrix from lil matrix type
      lil = arg1
      self.nrows, self.ncols = lil.shape
      self.size = lil.size

      # Generate arrays.
      self.data    = np.empty( (lil.nnz,),     dtype = object    )
      self.indices = np.empty( (lil.nnz,),     dtype = np.uint64 )
      self.indptr  = np.empty( (lil.nrows+1,), dtype = np.uint64 )

      self.indptr[0] = 0

      for i in range(self.nrows):

        self.indptr[i+1] = self.indptr[i] + len(lil.rows[i])
        k = self.indptr[i]
        
        for j in range(len(lil.rows[i])):

          self.indices[k] = lil.rows[i][j]
          self.data[k]    = lil.data[i][j].copy()
          k+=1

        # end for 

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

        self.indices = np.array(indices, copy=copy, dtype = np.uint64 )
        self.indptr  = np.array(indptr,  copy=copy, dtype = np.uint64 )
        self.data    = np.zeros(data.shape, dtype = object    )

        

        for i in range(data.size):
          
          if type(data) == {num_pytype}:

            self.data[i] = data[i].copy()

          else:
            
            self.data[i] = {num_pytype}( data[i] )

          # end if   

        # end for

      elif len(arg1) == 2 and type(arg1[0]) == int and type(arg1[1]) == int:

        self.indices = np.zeros(0, dtype = np.uint64 )
        self.indptr  = np.zeros(0, dtype = np.uint64 )
        self.data    = np.zeros(0, dtype = object    )
        
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
  @property
  def nnz(self): 
    """
    PURPOSE:      Return the number of non-zero elements in the stored matrix. 
    """
    #************************************************************************************************* 

    return len(self.data)

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

    return np.array(self.data)

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  @property
  def indices(self): 
    """
    PURPOSE:      Return the indices array the stored matrix. 
    """
    #*************************************************************************************************

    return np.array(self.indices)

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  @property
  def indptr(self): 
    """
    PURPOSE:      Return the indptr array the stored matrix. 
    """
    #*************************************************************************************************

    return np.array(self.indptr)

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  @property
  def order(self): 
    """
    PURPOSE:      Return the shape of the stored matrix. 
    """
    #*************************************************************************************************
    cdef ord_t order = 0, ordi
    cdef {num_pytype} onum
    cdef uint64_t i

    for i in range(self.data.size):
      
      order = max( order, self.data[i].order )

    # end for 

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

    for i in range( self.data.size ):

      data[i] = self.data[i].real

    # end for

    return sci_spr.csr_matrix((data, self.indices.copy(), self.indptr.copy() ), shape = self.shape)

  #---------------------------------------------------------------------------------------------------

  #*************************************************************************************************** 
  def __repr__(self):
    """
    PURPOSE:      Representation of the object.
  
    """
    #*************************************************************************************************

    out  = "<{{0}} sparse matrix of OTI numbers with \n".format(self.shape)
    out += "         {{0}} stored elements in Compressed Sparse Row format>".format(self.nnz)

    return out

  #--------------------------------------------------------------------------------------------------- 
  
  #***************************************************************************************************
  def __str__(self):
    """
    PURPOSE:      Create a string representation of the object.    
    """
    #*************************************************************************************************
    
    cdef uint64_t i, j, k
    out  = ""

    for i in range( len(self.indptr)-1 ):

      for j in range(self.indptr[i], self.indptr[i+1] ):

        out += "({{0:3d}},{{1:3d}}) {{2}}\n".format( i, self.indices[j], self.data[j] )
        
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
    
    

    cdef csr_{arr_pytype} res = <csr_{arr_pytype}> csr_{arr_pytype}.__new__(csr_{arr_pytype})
    cdef object[:]   data
    cdef uint64_t[:] indices
    cdef uint64_t[:] indptr
    cdef uint64_t i, k
    
    res.nrows   = self.nrows
    res.ncols   = self.ncols
    res.size    = self.size
    res.data    = np.empty( (self.nnz,), dtype = object)
    res.indices = self.indices.copy()
    res.indptr  = self.indptr.copy()
    
    for i in range(self.data.size):

      res.data[i] = self.data[i].copy()

    # end if 

    return res

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  def zeros_like(self):
    """
    PURPOSE: Create new object with OTI zeros in positions.
    """
    #*************************************************************************************************
    
    cdef csr_{arr_pytype} res = <csr_{arr_pytype}> csr_{arr_pytype}.__new__(csr_{arr_pytype})
    cdef object[:]   data
    cdef uint64_t[:] indices
    cdef uint64_t[:] indptr
    cdef uint64_t i, k
    
    res.nrows   = self.nrows
    res.ncols   = self.ncols
    res.size    = self.size
    res.data    = np.empty( (self.nnz,), dtype = object)
    res.indices = self.indices.copy()
    res.indptr  = self.indptr.copy()
    
    for i in range(self.data.size):

      res.data[i] = {num_pytype}(0.0)

    # end if 

    return res
  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  def __pow__(self, n,z):
    """
    PURPOSE:      Power function oversload
    """
    #*************************************************************************************************

    cdef {num_pytype} ores, oval
    cdef uint64_t i
    cdef csr_{arr_pytype} res

    res = self.zeros_like()

    for i in range(self.data.size):
      
      ores = res.data[i]
      oval = self.data[i]
      {num_func}_pow_to( &oval.num, n, &ores.num)

    # end for 

    return res 

  #---------------------------------------------------------------------------------------------------  

  #***************************************************************************************************
  cpdef get_deriv(self, object hum_dir ):
    """
    PURPOSE: Get the corresponding derivative of the system.
    """
    #*************************************************************************************************
    

    cdef imdir_t indx
    cdef ord_t  order
    cdef {num_pytype} ores, oval
    cdef uint64_t i
    cdef csr_{arr_pytype} res

    indx, order = imdir(hum_dir)
    res = self.zeros_like()

    for i in range(self.data.size):
        
      ores = res.data[i]
      oval = self.data[i]
      {num_func}_get_deriv_to( indx, order, &oval.num, &ores.num)

    # end for 

    return res 

  #---------------------------------------------------------------------------------------------------  

  #***************************************************************************************************
  cpdef get_im(self, object hum_dir ):
    """
    PURPOSE: Get the corresponding derivative of the system.
    """
    #*************************************************************************************************
    

    cdef imdir_t indx
    cdef ord_t  order
    cdef {num_pytype} ores, oval
    cdef uint64_t i, j, k
    cdef csr_{arr_pytype} res

    indx, order = imdir(hum_dir)
    res = self.zeros_like()

    for i in range(self.data.size):
        
      ores = res.data[i]
      oval = self.data[i]
      {num_func}_get_im_to_o( indx, order, &oval.num, &ores.num)

    # end for 

    return res 

  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  cpdef extract_im(self, object hum_dir):
    """
    PURPOSE: Get the corresponding imaginary direction in the {arr_pytype} object.
    """
    #*************************************************************************************************
    

    cdef imdir_t indx
    cdef ord_t  order
    cdef {num_pytype} ores, oval
    cdef uint64_t i, j, k
    cdef csr_{arr_pytype} res

    indx, order = imdir(hum_dir)
    res = self.zeros_like()

    for i in range(self.data.size):
        
      ores = res.data[i]
      oval = self.data[i]
      {num_func}_extract_im_to( indx, order, &oval.num, &ores.num)

    # end for 

    return res 

  #---------------------------------------------------------------------------------------------------
  
  #***************************************************************************************************
  cpdef  extract_deriv(self, object hum_dir):
    """
    PURPOSE: Get the corresponding derivative in the {arr_pytype} object, as OTI number.
    """
    #*************************************************************************************************
    

    cdef imdir_t indx
    cdef ord_t  order
    cdef {num_pytype} ores, oval
    cdef uint64_t i, j, k
    cdef csr_{arr_pytype} res

    indx, order = imdir(hum_dir)
    res = self.zeros_like()

    for i in range(self.data.size):
        
      ores = res.data[i]
      oval = self.data[i]
      {num_func}_extract_deriv_to( indx, order, &oval.num, &ores.num)

    # end for 

    return res 

  #---------------------------------------------------------------------------------------------------
  
  #***************************************************************************************************
  cpdef  get_order_im(self, ord_t order):
    """
    PURPOSE: Get the corresponding derivative in the {arr_pytype} object, as OTI number.
    """
    #*************************************************************************************************
    
    
    cdef {num_pytype} ores, oval
    cdef uint64_t i, j, k
    cdef csr_{arr_pytype} res

    res = self.zeros_like()

    for i in range(self.data.size):
        
      ores = res.data[i]
      oval = self.data[i]
      {num_func}_get_order_im_to( order, &oval.num, &ores.num)

    # end for 

    return res 

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  cpdef  truncate( self, object hum_dir):
    """
    PURPOSE:      to set a specific imaginary direction as given.

    """
    #*************************************************************************************************
    

    cdef imdir_t indx
    cdef ord_t  order
    cdef {num_pytype} ores, oval
    cdef uint64_t i, j, k
    cdef csr_{arr_pytype} res

    indx, order = imdir(hum_dir)
    res = self.zeros_like()

    for i in range(self.data.size):
        
      ores = res.data[i]
      oval = self.data[i]
      {num_func}_truncate_im_to( indx, order, &oval.num, &ores.num)

    # end for 

    return res 

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  def get_active_bases(self):
    """
    PORPUSE: Get the bases with non-zero coefficients in the OTI number.
    """
    

    cdef bases_t  size       = dhl.p_dh[0].Nbasis
    cdef imdir_t* bases_list = dhl.p_dh[0].p_idx[0]
    cdef uint64_t i, j
    cdef {num_pytype} oval
    
    # Initialize all elements as zero (deactivated)
    for i in range(size):

      bases_list[i]=0

    # end for 

    for i in range(self.data.size):

      oval = self.data[i]
      {num_func}_get_active_bases( &oval.num, bases_list)

    # end if 

    res = []
    for i in range(size):

      if bases_list[i]==1:
      
        res.append(i+1)

      # end if 

    # end for 

    return res

  #---------------------------------------------------------------------------------------------------


# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# :::::::::::::::::::::::::::::::::::: END OF CLASS csr_{arr_pytype} ::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::








# ****************************************************************************************************
cdef void csr{arr_pytype}_matmul_SO_to(csr_{arr_pytype} lhs, {arr_pytype} rhs, {arr_pytype} res):
  """
  PORPUSE:  Perform matrix-matrix multiplication between csr matrix and dense matrix.

  """

  

  cdef uint64_t i, j, k, l;
  cdef ord_t order;
  cdef {num_pytype}_t tmp;
  cdef {num_pytype} olhs;

  # check for dimensions.
  if (lhs.ncols != rhs.nrows) or (lhs.nrows != res.nrows) or (rhs.ncols != res.ncols):
    raise ValueError("Shapes < {{0}}, {{1}} > = < {{2}} > not aligned.".format(lhs.shape,rhs.shape,res.shape))

  # end if

  # Extract temporal 5.
  order = max(lhs.order, rhs.order )
  tmp = {num_func}_get_tmp( 5, order )

  for i in range(lhs.nrows):
      
    for j in range(rhs.ncols):

      # tmp = 0
      {num_func}_set_r( 0.0, &tmp)

      for l in range( lhs.indptr[i], lhs.indptr[i+1] ):

        # tmp = arr1[i,k] * arr2[k,j] + tmp
        k = lhs.indices[l]
        olhs = lhs.data[l]

        {num_func}_gem_oo_to( &olhs.num,
                        &rhs.arr.p_data[ j + k * rhs.ncols ],
                        &tmp, &tmp)

      # end for

      {arr_func}_set_item_ij_o( &tmp, i, j, &res.arr)

    # end for

  # end for 

# ----------------------------------------------------------------------------------------------------




# ****************************************************************************************************
cdef {arr_pytype} csr{arr_pytype}_matmul_SO(csr_{arr_pytype} lhs, {arr_pytype} rhs):
  """
  PORPUSE:  Perform matrix-matrix multiplication between csr matrix and dense matrix.

  """ 
  
  cdef {arr_pytype} res
  
  res = zeros((lhs.nrows,rhs.ncols))

  csr{arr_pytype}_matmul_SO_to( lhs, rhs, res)

  return res

# ----------------------------------------------------------------------------------------------------
