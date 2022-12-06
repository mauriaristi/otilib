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

                          arg1 = scipy.sparse.csr_matrix. Scipy's CSR matrix converted to OTI sparse type.

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
    global dhl

    cdef uint64_t i, j, k, ncols, nrows, nnz
    cdef lil_matrix lil
    cdef sotinum onum
    cdef matso otiarr
    cdef list lilrowsi, lildatai
    
    targ1 = type(arg1)

    if targ1 == lil_matrix :
      # Create CSR matrix from lil matrix type
      lil = arg1
      self.nrows, self.ncols = lil.shape
      self.size = lil.size
      nnz = lil.nnz
      # Generate arrays.
      self.arr       = arrso_zeros_bases( nnz, 1, 0, 0, dhl)
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
        self.arr       = arrso_zeros_bases( nnz, 1, 0, 0, dhl )
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
        tdata = type(data)
        
        if tdata == matso:

          for i in range(nnz):
            
            self.p_indices[i] = indices[i]

            onum = data[i,0]
            soti_copy_to( &onum.num, &self.arr.p_data[i], dhl)

          # end for

        else:

          for i in range(nnz):
            
            self.p_indices[i] = indices[i]

            if type(data[i]) == sotinum:

              onum = data[i]
              soti_copy_to( &onum.num, &self.arr.p_data[i], dhl)

            else:
              
              self.arr.p_data[i] = soti_createReal( data[i], 0, dhl )

            # end if   

          # end for
        
        # end if 

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
    elif targ1 == sci_spr.csr_matrix:
      
      nnz = arg1.nnz
      
      self.nrows = arg1.shape[0]
      self.ncols = arg1.shape[1]
      
      self.size = self.nrows*self.ncols
      otiarr = array(arg1.data)
      self.arr = otiarr.arr
      otiarr.FLAGS=0 # Remove ownership of memory.

      self.p_indices = <uint64_t*>malloc(       nnz*sizeof( uint64_t ) )
      self.p_indptr  = <uint64_t*>malloc( (self.nrows+1)*sizeof( uint64_t ) )

      if (not self.p_indices) or (not self.p_indptr):
        raise MemoryError("Could not allocate arrays for sparse matrix.")
      # end if 

      for i in range(nnz):
        self.p_indices[i] = arg1.indices[i]
      # end for

      for i in range(self.nrows+1):
        self.p_indptr[i] = arg1.indptr[i]
      # end for

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
    global dhl

    cdef ord_t order = 0, ordi
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

      data[i] = self.arr.p_data[i].re

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
    
  
    cdef sotinum   onum 
    cdef uint64_t i, j, k
    out  = ""

    for i in range( self.nrows ):

      for j in range(self.p_indptr[i], self.p_indptr[i+1] ):
        
        onum = sotinum.create(&self.arr.p_data[j], FLAGS = 0 )

        out += "({0:3d},{1:3d}) {2}\n".format( i, self.p_indices[j], str(onum) )
        
      # end for

    # end for

    return out

  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  def toarray(self):
    """
    PURPOSE:      Create a dense array out of the sparse representation.
    """
    #*************************************************************************************************
    
    global dhl
    cdef matso out
    cdef uint64_t i, col, k
    
    out = zeros(self.shape)

    for i in range( self.nrows ):

      for j in range(self.p_indptr[i], self.p_indptr[i+1] ):
        
        arrso_set_item_ij_o( &self.arr.p_data[j], i, self.p_indices[j], &out.arr, dhl)
        
      # end for

    # end for

    return out

  #---------------------------------------------------------------------------------------------------  

  #***************************************************************************************************
  def todense(self):
    """
    PURPOSE:      Create a dense array out of the sparse representation.
    """
    #*************************************************************************************************
    
    return self.toarray()

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

    res.arr       = arrso_zeros_bases( self.nnz, 1, 0, 0, dhl)
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
  def __neg__(self):
    """
    PURPOSE: Negation overload.
    """
    #*************************************************************************************************
    
    global dhl

    cdef csr_matrix res = self.zeros_like()
    
    arrso_neg_to(&self.arr, &res.arr, dhl)

    return res
  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  def __add__(self, other):
    """
    PURPOSE: Addition overload.
    """
    #*************************************************************************************************
    
    global dhl
    
    cdef csr_matrix res = <csr_matrix> csr_matrix.__new__(csr_matrix)
    cdef csr_matrix lhs,rhs
    cdef uint64_t ilhs, irhs, nTermL, nTermR
    cdef uint64_t i, j, counter
    
    
    
    tlhs = type(self)
    trhs = type(other)
    
    if (tlhs == csr_matrix and trhs == csr_matrix):

      lhs = self
      rhs = other

      # Find first common parameters
      
      if (lhs.nrows != rhs.nrows) or (lhs.ncols != rhs.ncols):
        raise ValueError("Matrices must have the same dimensions in addition operation: {0} x {1}".format(lhs.shape,rhs.shape) )
      # end if 
      
      res.nrows = lhs.nrows
      res.ncols = lhs.ncols
      res.size = res.nrows*res.ncols

      res.p_indptr = <uint64_t*>malloc( (lhs.nrows+1)*sizeof( uint64_t ) )

      if (not res.p_indptr):
        raise MemoryError("Could not allocate arrays for sparse matrix.")
      # end if

      res.p_indptr[0] = 0
      
      nnz = 0

      for i in range(lhs.nrows):
        
        counter = 0
        
        ilhs = 0
        irhs = 0
        
        nTermL = lhs.p_indptr[i+1] - lhs.p_indptr[i]
        nTermR = rhs.p_indptr[i+1] - rhs.p_indptr[i]

        while True:

          if ilhs<nTermL or irhs<nTermR:
            
            counter += 1

            if ilhs<nTermL and irhs<nTermR:

              if lhs.p_indices[ilhs+lhs.p_indptr[i]] == rhs.p_indices[irhs+rhs.p_indptr[i]]:
              
                ilhs+=1
                irhs+=1
              
              elif lhs.p_indices[ilhs+lhs.p_indptr[i]] < rhs.p_indices[irhs+rhs.p_indptr[i]]:
              
                ilhs+=1
              
              else:
              
                irhs+=1
              
              # end if 

            elif ilhs<nTermL:
              
              ilhs+=1

            else:
              
              irhs+=1

            # end if 
          else:
            break
          # end if 

        # end while

        nnz += counter
        res.p_indptr[i+1] = nnz
      
      # end for 
      
      res.p_indices = <uint64_t*>malloc( nnz*sizeof( uint64_t ) )

      if (not res.p_indices):
        raise MemoryError("Could not allocate arrays for sparse matrix.")
      # end if

      res.arr = arrso_zeros_bases( nnz, 1, 0, 0, dhl )
      
      nnz=0
      
      for i in range(res.nrows):
        
        counter = 0
        
        ilhs = 0
        irhs = 0
        
        nTermL = lhs.p_indptr[i+1] - lhs.p_indptr[i]
        nTermR = rhs.p_indptr[i+1] - rhs.p_indptr[i]

        while True:

          if ilhs<nTermL or irhs<nTermR:
            
            if ilhs<nTermL and irhs<nTermR:

              if lhs.p_indices[ilhs+lhs.p_indptr[i]] == rhs.p_indices[irhs+rhs.p_indptr[i]]:

                res.p_indices[nnz+counter]=lhs.p_indices[ilhs+lhs.p_indptr[i]]
                soti_sum_oo_to(&lhs.arr.p_data[ilhs+lhs.p_indptr[i]],&rhs.arr.p_data[irhs+rhs.p_indptr[i]],&res.arr.p_data[nnz+counter],dhl)
                
                ilhs+=1
                irhs+=1
              
              elif lhs.p_indices[ilhs+lhs.p_indptr[i]] < rhs.p_indices[irhs+rhs.p_indptr[i]]:
                
                res.p_indices[nnz+counter]=lhs.p_indices[ilhs+lhs.p_indptr[i]]
                soti_copy_to(&lhs.arr.p_data[ilhs+lhs.p_indptr[i]],&res.arr.p_data[nnz+counter],dhl)

                ilhs+=1
              
              else:

                res.p_indices[nnz+counter]=rhs.p_indices[irhs+rhs.p_indptr[i]]
                soti_copy_to(&rhs.arr.p_data[irhs+rhs.p_indptr[i]],&res.arr.p_data[nnz+counter],dhl)
              
                irhs+=1
              
              # end if 

            elif ilhs<nTermL:

              res.p_indices[nnz+counter]=lhs.p_indices[ilhs+lhs.p_indptr[i]]
              soti_copy_to(&lhs.arr.p_data[ilhs+lhs.p_indptr[i]],&res.arr.p_data[nnz+counter],dhl)
              
              ilhs+=1

            else:
              
              res.p_indices[nnz+counter]=rhs.p_indices[irhs+rhs.p_indptr[i]]
              soti_copy_to(&rhs.arr.p_data[irhs+rhs.p_indptr[i]],&res.arr.p_data[nnz+counter],dhl)

              irhs+=1

            # end if 
            
            counter += 1

          else:
            break
          # end if 

        # end while 

        nnz += counter

      # end for 

    else:

      return NotImplemented

    # end if 
      
    return res

  #--------------------------------------------------------------------------------------------------- 

  #***************************************************************************************************
  def __iadd__(self, other):
    """
    PURPOSE: Inplace addition overload.
    """
    #*************************************************************************************************

    return self + other

  #---------------------------------------------------------------------------------------------------  

  #***************************************************************************************************
  def __sub__(self, other):
    """
    PURPOSE: Subtraction overload.
    """
    #*************************************************************************************************

    return self + ( - other)

  #--------------------------------------------------------------------------------------------------- 

  #***************************************************************************************************
  def __isub__(self, other):
    """
    PURPOSE: Inplace subtraction overload.
    """
    #*************************************************************************************************

    return self - other

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  def __mul__(self, other):
    """ 
    PURPOSE: Multiplication overload.
    """
    #*************************************************************************************************
    
    global dhl
    
    cdef csr_matrix res = <csr_matrix> csr_matrix.__new__(csr_matrix)
    cdef csr_matrix csrMat
    cdef sotinum otiNum
    
    tlhs = type(self)
    trhs = type(other)
    
    if ( tlhs == sotinum ):
     
      otiNum = self
      csrMat = other 
      res = csrMat.zeros_like()

      for i in range(csrMat.nnz):

        soti_mul_oo_to(&otiNum.num, &csrMat.arr.p_data[i], &res.arr.p_data[i], dhl)

      # end for 

    elif ( trhs == sotinum ):
     
      otiNum = other
      csrMat = self
      res = csrMat.zeros_like()

      for i in range(csrMat.nnz):

        soti_mul_oo_to(&otiNum.num, &csrMat.arr.p_data[i], &res.arr.p_data[i], dhl)

      # end for 

    elif ( tlhs in number_types ):
      
      csrMat = other      
      res = csrMat.zeros_like()

      for i in range(csrMat.nnz):

        soti_mul_ro_to(self, &csrMat.arr.p_data[i], &res.arr.p_data[i], dhl)

      # end for 

    elif ( trhs in number_types ) :

      csrMat = self      
      res = csrMat.zeros_like()

      for i in range(csrMat.nnz):

        soti_mul_ro_to(other, &csrMat.arr.p_data[i], &res.arr.p_data[i], dhl)

      # end for 

    else:

      return NotImplemented      

    # end if 
      
    return res

  #***************************************************************************************************
  def zeros_like(self):
    """
    PURPOSE: Create new object with OTI zeros in positions.
    """
    #*************************************************************************************************
    global dhl

    cdef csr_matrix res = <csr_matrix> csr_matrix.__new__(csr_matrix)
    cdef uint64_t i, k
    
    res.arr       = arrso_zeros_bases( self.nnz, 1, 0, 0, dhl)
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
    PURPOSE: Get the corresponding imaginary direction in the object.
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
    PURPOSE: Get the corresponding derivative in the object, as OTI number.
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
    PURPOSE: Get the corresponding derivative in the object, as OTI number.
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
  order = max(lhs.order, rhs.order )
  tmp = soti_get_tmp( 5, order ,dhl)

  for i in range(lhs.nrows):
      
    for j in range(rhs.ncols):

      # tmp = 0
      soti_set_r( 0.0, &tmp, dhl)

      for l in range( lhs.p_indptr[i], lhs.p_indptr[i+1] ):

        # tmp = arr1[i,k] * arr2[k,j] + tmp
        k = lhs.p_indices[l]

        soti_gem_oo_to( &lhs.arr.p_data[ l ],
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
cdef void csrmatrix_trunc_matmul_SO_to(ord_t ordlhs, csr_matrix lhs, ord_t ordrhs, matso rhs, matso res):
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
  order = max(lhs.order, rhs.order )
  # print('-->> In csrmatrix_trunc_matmul multiplying ',lhs.order, rhs.order, order,"(-)",ordlhs,ordrhs)

  tmp = soti_get_tmp( 5, order ,dhl)
  
  # input()
  for i in range(lhs.nrows):      
    for j in range(rhs.ncols):

      # tmp = 0
      soti_set_r( 0.0, &tmp, dhl)

      # print("Obtaining ",i,'-',j)
      

      for l in range( lhs.p_indptr[i], lhs.p_indptr[i+1] ):

        # tmp = arr1[i,k] * arr2[k,j] + tmp
        k = lhs.p_indices[l]
        # soti_print(&lhs.arr.p_data[ l ], dhl)
        # soti_print(&rhs.arr.p_data[ j + k * rhs.ncols ], dhl)
        # print(" ++++ +++ lhs.act_ord",lhs.arr.p_data[ l ].act_order, " ----- rhs.act_ord",rhs.arr.p_data[ j + k * rhs.ncols ].act_order)
        # input()
        soti_trunc_gem_oo_to( ordlhs, &lhs.arr.p_data[ l ],
                              ordrhs, &rhs.arr.p_data[ j + k * rhs.ncols ],
                              &tmp, &tmp, dhl)

      # end for

      arrso_set_item_ij_o( &tmp, i, j, &res.arr, dhl)

    # end for

  # end for 

# ----------------------------------------------------------------------------------------------------

# ****************************************************************************************************
cdef matso csrmatrix_trunc_matmul_SO(ord_t ordlhs, csr_matrix lhs, ord_t ordrhs, matso rhs):
  """
  PORPUSE:  Perform matrix-matrix multiplication between csr matrix and dense matrix.

  """
  
  global dhl
  cdef matso res
  
  res = zeros((lhs.nrows,rhs.ncols))

  csrmatrix_trunc_matmul_SO_to( ordlhs, lhs, ordrhs, rhs, res)

  return res

# ----------------------------------------------------------------------------------------------------





































# # ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# # ::::::::::::::::::::::::::::::::::     CLASS  lil_matrix    :::::::::::::::::::::::::::::::::::::::::
# # ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# cdef class csr_matrix:
#   #---------------------------------------------------------------------------------------------------
#   #------------------------------------   DEFINITION OF ATTRIBUTES   ---------------------------------
#   #---------------------------------------------------------------------------------------------------
  
#   #                                --->      Look in dense.pxd    <---

#   #---------------------------------------------------------------------------------------------------  

#   #***************************************************************************************************
  
#   def __init__(self, arg1, shape=None, copy = True): 
#     """
#     PURPOSE:      Python level constructor of the csr_matrix class.

#     DESCRIPTION:  Creates a new empty csr_matrix matrix.
                 
#     """
#     #*************************************************************************************************
    
#     cdef uint64_t i, j, k, ncols, nrows
#     cdef lil_matrix lil
    
#     targ1 = type(arg1)

#     if targ1 == lil_matrix :
#       # Create CSR matrix from lil matrix type
#       lil = arg1
#       self.nrows, self.ncols = lil.shape
#       self.size = lil.size

#       # Generate arrays.
#       self.data    = np.empty( (lil.nnz,),     dtype = object    )
#       self.indices = np.empty( (lil.nnz,),     dtype = np.uint64 )
#       self.indptr  = np.empty( (lil.nrows+1,), dtype = np.uint64 )

#       self.indptr[0] = 0

#       for i in range(self.nrows):

#         self.indptr[i+1] = self.indptr[i] + len(lil.rows[i])
#         k = self.indptr[i]
        
#         for j in range(len(lil.rows[i])):

#           self.indices[k] = lil.rows[i][j]
#           self.data[k]    = lil.data[i][j].copy()
#           k+=1

#         # end for 

#       # end for 

#     elif targ1 == tuple:
      
#       if len(arg1) == 3: # Same as in scipy csr sparse.

#         (data, indices, indptr) = arg1

#         if shape is None:

#           nrows = len(indptr)-1
#           ncols = max(indices)+1

#         else:

#           nrows,ncols = shape

#         # end if 

#         self.nrows = nrows
#         self.ncols = ncols
        
#         self.size = nrows*ncols

#         self.indices = np.array(indices, copy=copy, dtype = np.uint64 )
#         self.indptr  = np.array(indptr,  copy=copy, dtype = np.uint64 )
#         self.data    = np.zeros(data.shape, dtype = object    )

        

#         for i in range(data.size):
          
#           if type(data) == sotinum:

#             self.data[i] = data[i].copy()

#           else:
            
#             self.data[i] = sotinum( data[i] )

#           # end if   

#         # end for

#       elif len(arg1) == 2 and type(arg1[0]) == int and type(arg1[1]) == int:

#         self.indices = np.zeros(0, dtype = np.uint64 )
#         self.indptr  = np.zeros(0, dtype = np.uint64 )
#         self.data    = np.zeros(0, dtype = object    )
        
#       elif len(arg1) == 2 and type(arg1[1]) == tuple:
#         # COO creator
#         raise ValueError(" ( data, (rows, cols) ) input format not currently implemented for CSR matrix.")

#       else:

#         raise ValueError("Wrong imput format to create CSR matrix.")

#       #end if       

#     else:

#       raise ValueError("Wrong imput format to create CSR matrix.")

#     # end if 

#   #---------------------------------------------------------------------------------------------------

#   #***************************************************************************************************
#   @property
#   def nnz(self): 
#     """
#     PURPOSE:      Return the number of non-zero elements in the stored matrix. 
#     """
#     #************************************************************************************************* 

#     return len(self.data)

#   #---------------------------------------------------------------------------------------------------

#   #***************************************************************************************************
#   @property
#   def shape(self): 
#     """
#     PURPOSE:      Return the shape of the stored matrix. 
#     """
#     #*************************************************************************************************

#     return (self.nrows,self.ncols)

#   #---------------------------------------------------------------------------------------------------

#   #***************************************************************************************************
#   @property
#   def data(self): 
#     """
#     PURPOSE:      Return the data array of the stored matrix. 
#     """
#     #*************************************************************************************************

#     return np.array(self.data)

#   #---------------------------------------------------------------------------------------------------

#   #***************************************************************************************************
#   @property
#   def indices(self): 
#     """
#     PURPOSE:      Return the indices array the stored matrix. 
#     """
#     #*************************************************************************************************

#     return np.array(self.indices)

#   #---------------------------------------------------------------------------------------------------

#   #***************************************************************************************************
#   @property
#   def indptr(self): 
#     """
#     PURPOSE:      Return the indptr array the stored matrix. 
#     """
#     #*************************************************************************************************

#     return np.array(self.indptr)

#   #---------------------------------------------------------------------------------------------------

#   #***************************************************************************************************
#   @property
#   def order(self): 
#     """
#     PURPOSE:      Return the shape of the stored matrix. 
#     """
#     #*************************************************************************************************
#     cdef ord_t order = 0, ordi
#     cdef sotinum onum
#     cdef uint64_t i

#     for i in range(self.data.size):
      
#       order = max( order, self.data[i].order )

#     # end for 

#     return order

#   #---------------------------------------------------------------------------------------------------

#   #***************************************************************************************************
#   @property
#   def real(self):
#     """
#     PURPOSE:      Get a numpy array with all coefficients in the real direction.

#     """
#     #*************************************************************************************************

#     cdef np.ndarray[coeff_t, ndim=1] data
#     cdef uint64_t i,j,k = 0
#     data = np.empty( (self.nnz,), dtype=np.float64 )

#     for i in range( self.data.size ):

#       data[i] = self.data[i].real

#     # end for

#     return sci_spr.csr_matrix((data, self.indices.copy(), self.indptr.copy() ), shape = self.shape)

#   #---------------------------------------------------------------------------------------------------

#   #*************************************************************************************************** 
#   def __repr__(self):
#     """
#     PURPOSE:      Representation of the object.
  
#     """
#     #*************************************************************************************************

#     out  = "<{0} sparse matrix of OTI numbers with \n".format(self.shape)
#     out += "         {0} stored elements in Compressed Sparse Row format>".format(self.nnz)

#     return out

#   #--------------------------------------------------------------------------------------------------- 
  
#   #***************************************************************************************************
#   def __str__(self):
#     """
#     PURPOSE:      Create a string representation of the object.    
#     """
#     #*************************************************************************************************
#     global dhl
  
#     cdef sotinum_t d_soti
#     cdef sotinum   soti
#     cdef uint64_t i, j, k
#     out  = ""

#     for i in range( len(self.indptr)-1 ):

#       for j in range(self.indptr[i], self.indptr[i+1] ):

#         out += "({0:3d},{1:3d}) {2}\n".format( i, self.indices[j], self.data[j] )
        
#       # end for

#     # end for

#     return out

#   #---------------------------------------------------------------------------------------------------  

#   #***************************************************************************************************
#   def copy(self):
#     """
#     PURPOSE: Deep copy to a new object.
#     """
#     #*************************************************************************************************
    
#     global dhl

#     cdef csr_matrix res = <csr_matrix> csr_matrix.__new__(csr_matrix)
#     cdef object[:]   data
#     cdef uint64_t[:] indices
#     cdef uint64_t[:] indptr
#     cdef uint64_t i, k
    
#     res.nrows   = self.nrows
#     res.ncols   = self.ncols
#     res.size    = self.size
#     res.data    = np.empty( (self.nnz,), dtype = object)
#     res.indices = self.indices.copy()
#     res.indptr  = self.indptr.copy()
    
#     for i in range(self.data.size):

#       res.data[i] = self.data[i].copy()

#     # end if 

#     return res

#   #---------------------------------------------------------------------------------------------------

#   #***************************************************************************************************
#   def zeros_like(self):
#     """
#     PURPOSE: Create new object with OTI zeros in positions.
#     """
#     #*************************************************************************************************
    
#     cdef csr_matrix res = <csr_matrix> csr_matrix.__new__(csr_matrix)
#     cdef object[:]   data
#     cdef uint64_t[:] indices
#     cdef uint64_t[:] indptr
#     cdef uint64_t i, k
    
#     res.nrows   = self.nrows
#     res.ncols   = self.ncols
#     res.size    = self.size
#     res.data    = np.empty( (self.nnz,), dtype = object)
#     res.indices = self.indices.copy()
#     res.indptr  = self.indptr.copy()
    
#     for i in range(self.data.size):

#       res.data[i] = sotinum(0.0)

#     # end if 

#     return res
#   #---------------------------------------------------------------------------------------------------


#   # #***************************************************************************************************
#   # def __neg__(self):
#   #   """
#   #   PURPOSE: Negation overload.
#   #   """
#   #   #*************************************************************************************************
    
#   #   global dhl
    
#   #   cdef arrso_t res = arrso_neg(&self.arr, dhl)

#   #   return matso.create(&res)
#   # #---------------------------------------------------------------------------------------------------




#   # #***************************************************************************************************
#   # def __add__(self, other):
#   #   """
#   #   PURPOSE: Addition overload.
#   #   """
#   #   #*************************************************************************************************
    
#   #   global dhl
    
#   #   cdef arrso_t res 
#   #   cdef matso lhs,rhs
#   #   cdef dmat dlhs,drhs
#   #   cdef sotinum olhs,orhs
    
#   #   tlhs = type(self)
#   #   trhs = type(other)
    
#   #   if (tlhs == trhs):

#   #     lhs = self
#   #     rhs = other

#   #     res = arrso_sum_OO(&lhs.arr,&rhs.arr,dhl)

#   #   elif ( tlhs  == sotinum ):

#   #     olhs = self
#   #     rhs = other

#   #     res = arrso_sum_oO(&olhs.num,&rhs.arr, dhl)

#   #   elif ( trhs  == sotinum ):

#   #     lhs = self
#   #     orhs = other

#   #     res = arrso_sum_oO(&orhs.num,&lhs.arr, dhl)
    
#   #   elif (tlhs in number_types):
      
#   #     rhs = other
#   #     res = arrso_sum_rO(self, &rhs.arr, dhl)

#   #   elif (trhs in number_types):
        
#   #     lhs = self
#   #     res = arrso_sum_rO(other, &lhs.arr, dhl)

#   #   elif ( tlhs  == dmat ):

#   #     dlhs = self
#   #     rhs = other

#   #     res = arrso_sum_RO(&dlhs.arr,&rhs.arr, dhl)

#   #   elif ( trhs  == dmat ):

#   #     lhs = self
#   #     drhs = other

#   #     res = arrso_sum_RO(&drhs.arr,&lhs.arr, dhl)

#   #   else:

#   #     return NotImplemented

#   #   # end if 
      
#   #   return matso.create(&res)

#   # #---------------------------------------------------------------------------------------------------  


#   # #***************************************************************************************************
#   # def __iadd__(self, other):
#   #   """
#   #   PURPOSE: Inplace addition overload.
#   #   """
#   #   #*************************************************************************************************

#   #   return self + other

#   # #---------------------------------------------------------------------------------------------------  


#   # #***************************************************************************************************
#   # def __sub__(self, other):
#   #   """
#   #   PURPOSE: Subtraction overload.
#   #   """
#   # #************************************************************************
    
#   #   global dhl
    
#   #   cdef arrso_t res 
#   #   cdef matso lhs,rhs
#   #   cdef dmat dlhs,drhs
#   #   cdef sotinum olhs,orhs
    
#   #   tlhs = type(self)
#   #   trhs = type(other)
    
#   #   if (tlhs == trhs):

#   #     lhs = self
#   #     rhs = other

#   #     res = arrso_sub_OO(&lhs.arr,&rhs.arr,dhl)

#   #   elif ( tlhs  == sotinum ):

#   #     olhs = self
#   #     rhs = other

#   #     res = arrso_sub_oO(&olhs.num,&rhs.arr, dhl)

#   #   elif ( trhs  == sotinum ):

#   #     lhs = self
#   #     orhs = other

#   #     res = arrso_sub_Oo(&lhs.arr, &orhs.num, dhl)
    
#   #   elif (tlhs in number_types):
      
#   #     rhs = other
#   #     res = arrso_sub_rO(self, &rhs.arr, dhl)

#   #   elif (trhs in number_types):
        
#   #     lhs = self
#   #     res = arrso_sub_Or(&lhs.arr, other, dhl)

#   #   elif ( tlhs  == dmat ):

#   #     dlhs = self
#   #     rhs = other

#   #     res = arrso_sub_RO(&dlhs.arr,&rhs.arr, dhl)

#   #   elif ( trhs  == dmat ):

#   #     lhs = self
#   #     drhs = other

#   #     res = arrso_sub_OR(&lhs.arr, &drhs.arr, dhl)

#   #   else:

#   #     return NotImplemented      

#   #   # end if 
      
#   #   return matso.create(&res)

#   # #---------------------------------------------------------------------------------------------------  


#   # #***************************************************************************************************
#   # def __isub__(self, other_in):
#   #   """
#   #   PURPOSE: Inplace subtraction overload.
#   #   """
#   #   #*************************************************************************************************
  
#   #   return self - other_in

#   # #---------------------------------------------------------------------------------------------------  


#   # #***************************************************************************************************
#   # def __mul__(self, other):
#   #   """ 
#   #   PURPOSE: Multiplication overload.
#   #   """
#   #   #*************************************************************************************************
    
#   #   global dhl
    
#   #   cdef arrso_t res 
#   #   cdef matso lhs,rhs
#   #   cdef dmat dlhs,drhs
#   #   cdef sotinum olhs,orhs
    
#   #   tlhs = type(self)
#   #   trhs = type(other)
    
#   #   if (tlhs == trhs):

#   #     lhs = self
#   #     rhs = other

#   #     res = arrso_mul_OO(&lhs.arr,&rhs.arr,dhl)

#   #   elif ( tlhs  == sotinum ):

#   #     olhs = self
#   #     rhs = other

#   #     res = arrso_mul_oO(&olhs.num,&rhs.arr, dhl)

#   #   elif ( trhs  == sotinum ):

#   #     lhs = self
#   #     orhs = other

#   #     res = arrso_mul_oO(&orhs.num,&lhs.arr, dhl)
    
#   #   elif (tlhs in number_types):
      
#   #     rhs = other
#   #     res = arrso_mul_rO(self, &rhs.arr, dhl)

#   #   elif (trhs in number_types):
        
#   #     lhs = self
#   #     res = arrso_mul_rO(other, &lhs.arr, dhl)

#   #   elif ( tlhs  == dmat ):

#   #     dlhs = self
#   #     rhs = other

#   #     res = arrso_mul_RO(&dlhs.arr,&rhs.arr, dhl)

#   #   elif ( trhs  == dmat ):

#   #     lhs = self
#   #     drhs = other

#   #     res = arrso_mul_RO(&drhs.arr,&lhs.arr, dhl)

#   #   else:

#   #     return NotImplemented      

#   #   # end if 
      
#   #   return matso.create(&res)

    

#   # #---------------------------------------------------------------------------------------------------  


#   # #***************************************************************************************************
#   # def __imul__(self, other_in):
#   #   """
#   #   PURPOSE: Inplace multiplication overload.
#   #   """
#   #   #*************************************************************************************************

#   #   return self * other_in

#   # #---------------------------------------------------------------------------------------------------  


#   # #***************************************************************************************************
#   # def __truediv__(self, other):
#   #   """
#   #   PURPOSE: Division overload.
#   #   """
#   #   #*************************************************************************************************
    
#   #   global dhl
    
#   #   cdef arrso_t res 
#   #   cdef matso lhs,rhs
#   #   cdef dmat dlhs,drhs
#   #   cdef sotinum olhs,orhs
    
#   #   tlhs = type(self)
#   #   trhs = type(other)
    
#   #   if (tlhs == trhs):

#   #     lhs = self
#   #     rhs = other

#   #     res = arrso_div_OO(&lhs.arr,&rhs.arr,dhl)

#   #   elif ( tlhs  == sotinum ):

#   #     olhs = self
#   #     rhs = other

#   #     res = arrso_div_oO(&olhs.num,&rhs.arr, dhl)

#   #   elif ( trhs  == sotinum ):

#   #     lhs = self
#   #     orhs = other

#   #     res = arrso_div_Oo(&lhs.arr, &orhs.num, dhl)
    
#   #   elif (tlhs in number_types):
      
#   #     rhs = other
#   #     res = arrso_div_rO(self, &rhs.arr, dhl)

#   #   elif (trhs in number_types):
        
#   #     lhs = self
#   #     res = arrso_div_Or(&lhs.arr, other, dhl)

#   #   elif ( tlhs  == dmat ):

#   #     dlhs = self
#   #     rhs = other

#   #     res = arrso_div_RO(&dlhs.arr,&rhs.arr, dhl)

#   #   elif ( trhs  == dmat ):

#   #     lhs = self
#   #     drhs = other

#   #     res = arrso_div_OR(&lhs.arr, &drhs.arr, dhl)

#   #   else:

#   #     return NotImplemented      

#   #   # end if 
      
#   #   return matso.create(&res)

#   # #---------------------------------------------------------------------------------------------------  

#   #***************************************************************************************************
#   def __pow__(self, n,z):
#     """
#     PURPOSE:      Power function oversload
#     """
#     #*************************************************************************************************
    
#     global dhl

#     cdef sotinum ores, oval
#     cdef uint64_t i
#     cdef csr_matrix res

#     res = self.zeros_like()

#     for i in range(self.data.size):
      
#       ores = res.data[i]
#       oval = self.data[i]
#       soti_pow_to( &oval.num, n, &ores.num, dhl)

#     # end for 

#     return res 

#   #---------------------------------------------------------------------------------------------------  

#   #***************************************************************************************************
#   cpdef get_deriv(self, object hum_dir ):
#     """
#     PURPOSE: Get the corresponding derivative of the system.
#     """
#     #*************************************************************************************************
#     global dhl

#     cdef imdir_t indx
#     cdef ord_t  order
#     cdef sotinum ores, oval
#     cdef uint64_t i
#     cdef csr_matrix res

#     indx, order = imdir(hum_dir)
#     res = self.zeros_like()

#     for i in range(self.data.size):
        
#       ores = res.data[i]
#       oval = self.data[i]
#       soti_get_deriv_to( indx, order, &oval.num, &ores.num, dhl)

#     # end for 

#     return res 

#   #---------------------------------------------------------------------------------------------------  

#   #***************************************************************************************************
#   cpdef get_im(self, object hum_dir ):
#     """
#     PURPOSE: Get the corresponding derivative of the system.
#     """
#     #*************************************************************************************************
#     global dhl

#     cdef imdir_t indx
#     cdef ord_t  order
#     cdef sotinum ores, oval
#     cdef uint64_t i, j, k
#     cdef csr_matrix res

#     indx, order = imdir(hum_dir)
#     res = self.zeros_like()

#     for i in range(self.data.size):
        
#       ores = res.data[i]
#       oval = self.data[i]
#       soti_get_im_to_o( indx, order, &oval.num, &ores.num, dhl)

#     # end for 

#     return res 

#   #---------------------------------------------------------------------------------------------------  


#   #***************************************************************************************************
#   cpdef extract_im(self, object hum_dir):
#     """
#     PURPOSE: Get the corresponding imaginary direction in the matso object.
#     """
#     #*************************************************************************************************
#     global dhl

#     cdef imdir_t indx
#     cdef ord_t  order
#     cdef sotinum ores, oval
#     cdef uint64_t i, j, k
#     cdef csr_matrix res

#     indx, order = imdir(hum_dir)
#     res = self.zeros_like()

#     for i in range(self.data.size):
        
#       ores = res.data[i]
#       oval = self.data[i]
#       soti_extract_im_to( indx, order, &oval.num, &ores.num, dhl)

#     # end for 

#     return res 

#   #---------------------------------------------------------------------------------------------------
  
#   #***************************************************************************************************
#   cpdef  extract_deriv(self, object hum_dir):
#     """
#     PURPOSE: Get the corresponding derivative in the matso object, as OTI number.
#     """
#     #*************************************************************************************************
#     global dhl

#     cdef imdir_t indx
#     cdef ord_t  order
#     cdef sotinum ores, oval
#     cdef uint64_t i, j, k
#     cdef csr_matrix res

#     indx, order = imdir(hum_dir)
#     res = self.zeros_like()

#     for i in range(self.data.size):
        
#       ores = res.data[i]
#       oval = self.data[i]
#       soti_extract_deriv_to( indx, order, &oval.num, &ores.num, dhl)

#     # end for 

#     return res 

#   #---------------------------------------------------------------------------------------------------
  
#   #***************************************************************************************************
#   cpdef  get_order_im(self, ord_t order):
#     """
#     PURPOSE: Get the corresponding derivative in the matso object, as OTI number.
#     """
#     #*************************************************************************************************
#     global dhl
    
#     cdef sotinum ores, oval
#     cdef uint64_t i, j, k
#     cdef csr_matrix res

#     res = self.zeros_like()

#     for i in range(self.data.size):
        
#       ores = res.data[i]
#       oval = self.data[i]
#       soti_get_order_im_to( order, &oval.num, &ores.num, dhl)

#     # end for 

#     return res 

#   #---------------------------------------------------------------------------------------------------

#   #***************************************************************************************************
#   cpdef  truncate( self, object hum_dir):
#     """
#     PURPOSE:      to set a specific imaginary direction as given.

#     """
#     #*************************************************************************************************
#     global dhl

#     cdef imdir_t indx
#     cdef ord_t  order
#     cdef sotinum ores, oval
#     cdef uint64_t i, j, k
#     cdef csr_matrix res

#     indx, order = imdir(hum_dir)
#     res = self.zeros_like()

#     for i in range(self.data.size):
        
#       ores = res.data[i]
#       oval = self.data[i]
#       soti_truncate_im_to( indx, order, &oval.num, &ores.num, dhl)

#     # end for 

#     return res 

#   #---------------------------------------------------------------------------------------------------

#   #***************************************************************************************************
#   def get_active_bases(self):
#     """
#     PORPUSE: Get the bases with non-zero coefficients in the OTI number.
#     """
#     global dhl

#     cdef bases_t  size       = dhl.p_dh[0].Nbasis
#     cdef imdir_t* bases_list = dhl.p_dh[0].p_idx[0]
#     cdef uint64_t i, j
#     cdef sotinum oval
    
#     # Initialize all elements as zero (deactivated)
#     for i in range(size):

#       bases_list[i]=0

#     # end for 

#     for i in range(self.data.size):

#       oval = self.data[i]
#       soti_get_active_bases( &oval.num, bases_list, dhl)

#     # end if 

#     res = []
#     for i in range(size):

#       if bases_list[i]==1:
      
#         res.append(i+1)

#       # end if 

#     # end for 

#     return res

#   #---------------------------------------------------------------------------------------------------


# # ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# # :::::::::::::::::::::::::::::::::::: END OF CLASS csr_matrix ::::::::::::::::::::::::::::::::::::::::
# # ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::




















# # ****************************************************************************************************
# cdef void csrmatrix_matmul_SO_to(csr_matrix lhs, matso rhs, matso res):
#   """
#   PORPUSE:  Perform matrix-matrix multiplication between csr matrix and dense matrix.

#   """

#   global dhl

#   cdef uint64_t i, j, k, l;
#   cdef ord_t order;
#   cdef sotinum_t tmp;
#   cdef sotinum olhs;

#   # check for dimensions.
#   if (lhs.ncols != rhs.nrows) or (lhs.nrows != res.nrows) or (rhs.ncols != res.ncols):
#     raise ValueError("Shapes < {0}, {1} > = < {2} > not aligned.".format(lhs.shape,rhs.shape,res.shape))

#   # end if

#   # Extract temporal 5.
#   order = max(lhs.order, rhs.order )
#   tmp = soti_get_tmp( 5, order ,dhl)

#   for i in range(lhs.nrows):
      
#     for j in range(rhs.ncols):

#       # tmp = 0
#       soti_set_r( 0.0, &tmp, dhl)

#       for l in range( lhs.indptr[i], lhs.indptr[i+1] ):

#         # tmp = arr1[i,k] * arr2[k,j] + tmp
#         k = lhs.indices[l]
#         olhs = lhs.data[l]

#         soti_gem_oo_to( &olhs.num,
#                         &rhs.arr.p_data[ j + k * rhs.ncols ],
#                         &tmp, &tmp, dhl)

#       # end for

#       arrso_set_item_ij_o( &tmp, i, j, &res.arr, dhl)

#     # end for

#   # end for 

# # ----------------------------------------------------------------------------------------------------

# # ****************************************************************************************************
# cdef matso csrmatrix_matmul_SO(csr_matrix lhs, matso rhs):
#   """
#   PORPUSE:  Perform matrix-matrix multiplication between csr matrix and dense matrix.

#   """
  
#   global dhl
#   cdef matso res
  
#   res = zeros((lhs.nrows,rhs.ncols))

#   csrmatrix_matmul_SO_to( lhs, rhs, res)

#   return res

# # ----------------------------------------------------------------------------------------------------















# # ****************************************************************************************************
# cdef void csrmatrix_trunc_matmul_SO_to(ord_t ordlhs, csr_matrix lhs, ord_t ordrhs, matso rhs, matso res):
#   """
#   PORPUSE:  Perform matrix-matrix multiplication between csr matrix and dense matrix.

#   """

#   global dhl

#   cdef uint64_t i, j, k, l;
#   cdef ord_t order;
#   cdef sotinum_t tmp;
#   cdef sotinum olhs;

#   # check for dimensions.
#   if (lhs.ncols != rhs.nrows) or (lhs.nrows != res.nrows) or (rhs.ncols != res.ncols):
#     raise ValueError("Shapes < {0}, {1} > = < {2} > not aligned.".format(lhs.shape,rhs.shape,res.shape))
#   # end if

#   # Extract temporal 5.
#   order = max(lhs.order, rhs.order )
#   tmp = soti_get_tmp( 5, order ,dhl)

#   for i in range(lhs.nrows):
      
#     for j in range(rhs.ncols):

#       # tmp = 0
#       soti_set_r( 0.0, &tmp, dhl)

#       for l in range( lhs.indptr[i], lhs.indptr[i+1] ):

#         # tmp = arr1[i,k] * arr2[k,j] + tmp
#         k = lhs.indices[l]
#         olhs = lhs.data[l]

#         soti_trunc_gem_oo_to( ordlhs, &olhs.num,
#                               ordrhs, &rhs.arr.p_data[ j + k * rhs.ncols ],
#                               &tmp, &tmp, dhl)

#       # end for

#       arrso_set_item_ij_o( &tmp, i, j, &res.arr, dhl)

#     # end for

#   # end for 

# # ----------------------------------------------------------------------------------------------------

# # ****************************************************************************************************
# cdef matso csrmatrix_trunc_matmul_SO(ord_t ordlhs, csr_matrix lhs, ord_t ordrhs, matso rhs):
#   """
#   PORPUSE:  Perform matrix-matrix multiplication between csr matrix and dense matrix.

#   """
  
#   global dhl
#   cdef matso res
  
#   res = zeros((lhs.nrows,rhs.ncols))

#   csrmatrix_trunc_matmul_SO_to( ordlhs, lhs, ordrhs, rhs, res)

#   return res

# # ----------------------------------------------------------------------------------------------------