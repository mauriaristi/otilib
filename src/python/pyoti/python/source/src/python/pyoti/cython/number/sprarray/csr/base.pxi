






# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::     CLASS  lil_matso    :::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
cdef class csr_matso:
  #---------------------------------------------------------------------------------------------------
  #------------------------------------   DEFINITION OF ATTRIBUTES   ---------------------------------
  #---------------------------------------------------------------------------------------------------
  
  #                                --->      Look in dense.pxd    <---

  #---------------------------------------------------------------------------------------------------  

  #***************************************************************************************************
  
  def __init__(self, arg1, shape=None, copy = True): 
    """
    PURPOSE:      Python level constructor of the csr_matso class.

    DESCRIPTION:  Creates a new empty csr_matso matrix.
                 
    """
    #*************************************************************************************************
    
    cdef uint64_t i, j, k, ncols, nrows
    cdef lil_matso lil
    
    targ1 = type(arg1)

    if targ1 == lil_matso :
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
          
          if type(data) == sotinum:

            self.data[i] = data[i].copy()

          else:
            
            self.data[i] = sotinum( data[i] )

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
    cdef sotinum onum
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
  
    cdef sotinum_t d_soti
    cdef sotinum   soti
    cdef uint64_t i, j, k
    out  = ""

    for i in range( len(self.indptr)-1 ):

      for j in range(self.indptr[i], self.indptr[i+1] ):

        out += "({0:3d},{1:3d}) {2}\n".format( i, self.indices[j], self.data[j] )
        
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

    cdef csr_matso res = <csr_matso> csr_matso.__new__(csr_matso)
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
    
    cdef csr_matso res = <csr_matso> csr_matso.__new__(csr_matso)
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

      res.data[i] = sotinum(0.0)

    # end if 

    return res
  #---------------------------------------------------------------------------------------------------


  # #***************************************************************************************************
  # def __neg__(self):
  #   """
  #   PURPOSE: Negation overload.
  #   """
  #   #*************************************************************************************************
    
  #   global dhl
    
  #   cdef arrso_t res = arrso_neg(&self.arr, dhl)

  #   return matso.create(&res)
  # #---------------------------------------------------------------------------------------------------




  # #***************************************************************************************************
  # def __add__(self, other):
  #   """
  #   PURPOSE: Addition overload.
  #   """
  #   #*************************************************************************************************
    
  #   global dhl
    
  #   cdef arrso_t res 
  #   cdef matso lhs,rhs
  #   cdef dmat dlhs,drhs
  #   cdef sotinum olhs,orhs
    
  #   tlhs = type(self)
  #   trhs = type(other)
    
  #   if (tlhs == trhs):

  #     lhs = self
  #     rhs = other

  #     res = arrso_sum_OO(&lhs.arr,&rhs.arr,dhl)

  #   elif ( tlhs  == sotinum ):

  #     olhs = self
  #     rhs = other

  #     res = arrso_sum_oO(&olhs.num,&rhs.arr, dhl)

  #   elif ( trhs  == sotinum ):

  #     lhs = self
  #     orhs = other

  #     res = arrso_sum_oO(&orhs.num,&lhs.arr, dhl)
    
  #   elif (tlhs in number_types):
      
  #     rhs = other
  #     res = arrso_sum_rO(self, &rhs.arr, dhl)

  #   elif (trhs in number_types):
        
  #     lhs = self
  #     res = arrso_sum_rO(other, &lhs.arr, dhl)

  #   elif ( tlhs  == dmat ):

  #     dlhs = self
  #     rhs = other

  #     res = arrso_sum_RO(&dlhs.arr,&rhs.arr, dhl)

  #   elif ( trhs  == dmat ):

  #     lhs = self
  #     drhs = other

  #     res = arrso_sum_RO(&drhs.arr,&lhs.arr, dhl)

  #   else:

  #     return NotImplemented

  #   # end if 
      
  #   return matso.create(&res)

  # #---------------------------------------------------------------------------------------------------  


  # #***************************************************************************************************
  # def __iadd__(self, other):
  #   """
  #   PURPOSE: Inplace addition overload.
  #   """
  #   #*************************************************************************************************

  #   return self + other

  # #---------------------------------------------------------------------------------------------------  


  # #***************************************************************************************************
  # def __sub__(self, other):
  #   """
  #   PURPOSE: Subtraction overload.
  #   """
  # #************************************************************************
    
  #   global dhl
    
  #   cdef arrso_t res 
  #   cdef matso lhs,rhs
  #   cdef dmat dlhs,drhs
  #   cdef sotinum olhs,orhs
    
  #   tlhs = type(self)
  #   trhs = type(other)
    
  #   if (tlhs == trhs):

  #     lhs = self
  #     rhs = other

  #     res = arrso_sub_OO(&lhs.arr,&rhs.arr,dhl)

  #   elif ( tlhs  == sotinum ):

  #     olhs = self
  #     rhs = other

  #     res = arrso_sub_oO(&olhs.num,&rhs.arr, dhl)

  #   elif ( trhs  == sotinum ):

  #     lhs = self
  #     orhs = other

  #     res = arrso_sub_Oo(&lhs.arr, &orhs.num, dhl)
    
  #   elif (tlhs in number_types):
      
  #     rhs = other
  #     res = arrso_sub_rO(self, &rhs.arr, dhl)

  #   elif (trhs in number_types):
        
  #     lhs = self
  #     res = arrso_sub_Or(&lhs.arr, other, dhl)

  #   elif ( tlhs  == dmat ):

  #     dlhs = self
  #     rhs = other

  #     res = arrso_sub_RO(&dlhs.arr,&rhs.arr, dhl)

  #   elif ( trhs  == dmat ):

  #     lhs = self
  #     drhs = other

  #     res = arrso_sub_OR(&lhs.arr, &drhs.arr, dhl)

  #   else:

  #     return NotImplemented      

  #   # end if 
      
  #   return matso.create(&res)

  # #---------------------------------------------------------------------------------------------------  


  # #***************************************************************************************************
  # def __isub__(self, other_in):
  #   """
  #   PURPOSE: Inplace subtraction overload.
  #   """
  #   #*************************************************************************************************
  
  #   return self - other_in

  # #---------------------------------------------------------------------------------------------------  


  # #***************************************************************************************************
  # def __mul__(self, other):
  #   """ 
  #   PURPOSE: Multiplication overload.
  #   """
  #   #*************************************************************************************************
    
  #   global dhl
    
  #   cdef arrso_t res 
  #   cdef matso lhs,rhs
  #   cdef dmat dlhs,drhs
  #   cdef sotinum olhs,orhs
    
  #   tlhs = type(self)
  #   trhs = type(other)
    
  #   if (tlhs == trhs):

  #     lhs = self
  #     rhs = other

  #     res = arrso_mul_OO(&lhs.arr,&rhs.arr,dhl)

  #   elif ( tlhs  == sotinum ):

  #     olhs = self
  #     rhs = other

  #     res = arrso_mul_oO(&olhs.num,&rhs.arr, dhl)

  #   elif ( trhs  == sotinum ):

  #     lhs = self
  #     orhs = other

  #     res = arrso_mul_oO(&orhs.num,&lhs.arr, dhl)
    
  #   elif (tlhs in number_types):
      
  #     rhs = other
  #     res = arrso_mul_rO(self, &rhs.arr, dhl)

  #   elif (trhs in number_types):
        
  #     lhs = self
  #     res = arrso_mul_rO(other, &lhs.arr, dhl)

  #   elif ( tlhs  == dmat ):

  #     dlhs = self
  #     rhs = other

  #     res = arrso_mul_RO(&dlhs.arr,&rhs.arr, dhl)

  #   elif ( trhs  == dmat ):

  #     lhs = self
  #     drhs = other

  #     res = arrso_mul_RO(&drhs.arr,&lhs.arr, dhl)

  #   else:

  #     return NotImplemented      

  #   # end if 
      
  #   return matso.create(&res)

    

  # #---------------------------------------------------------------------------------------------------  


  # #***************************************************************************************************
  # def __imul__(self, other_in):
  #   """
  #   PURPOSE: Inplace multiplication overload.
  #   """
  #   #*************************************************************************************************

  #   return self * other_in

  # #---------------------------------------------------------------------------------------------------  


  # #***************************************************************************************************
  # def __truediv__(self, other):
  #   """
  #   PURPOSE: Division overload.
  #   """
  #   #*************************************************************************************************
    
  #   global dhl
    
  #   cdef arrso_t res 
  #   cdef matso lhs,rhs
  #   cdef dmat dlhs,drhs
  #   cdef sotinum olhs,orhs
    
  #   tlhs = type(self)
  #   trhs = type(other)
    
  #   if (tlhs == trhs):

  #     lhs = self
  #     rhs = other

  #     res = arrso_div_OO(&lhs.arr,&rhs.arr,dhl)

  #   elif ( tlhs  == sotinum ):

  #     olhs = self
  #     rhs = other

  #     res = arrso_div_oO(&olhs.num,&rhs.arr, dhl)

  #   elif ( trhs  == sotinum ):

  #     lhs = self
  #     orhs = other

  #     res = arrso_div_Oo(&lhs.arr, &orhs.num, dhl)
    
  #   elif (tlhs in number_types):
      
  #     rhs = other
  #     res = arrso_div_rO(self, &rhs.arr, dhl)

  #   elif (trhs in number_types):
        
  #     lhs = self
  #     res = arrso_div_Or(&lhs.arr, other, dhl)

  #   elif ( tlhs  == dmat ):

  #     dlhs = self
  #     rhs = other

  #     res = arrso_div_RO(&dlhs.arr,&rhs.arr, dhl)

  #   elif ( trhs  == dmat ):

  #     lhs = self
  #     drhs = other

  #     res = arrso_div_OR(&lhs.arr, &drhs.arr, dhl)

  #   else:

  #     return NotImplemented      

  #   # end if 
      
  #   return matso.create(&res)

  # #---------------------------------------------------------------------------------------------------  

  #***************************************************************************************************
  def __pow__(self, n,z):
    """
    PURPOSE:      Power function oversload
    """
    #*************************************************************************************************
    
    global dhl

    cdef sotinum ores, oval
    cdef uint64_t i
    cdef csr_matso res

    res = self.zeros_like()

    for i in range(self.data.size):
      
      ores = res.data[i]
      oval = self.data[i]
      soti_pow_to( &oval.num, n, &ores.num, dhl)

    # end for 

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
    cdef sotinum ores, oval
    cdef uint64_t i
    cdef csr_matso res

    indx, order = imdir(hum_dir)
    res = self.zeros_like()

    for i in range(self.data.size):
        
      ores = res.data[i]
      oval = self.data[i]
      soti_get_deriv_to( indx, order, &oval.num, &ores.num, dhl)

    # end for 

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
    cdef sotinum ores, oval
    cdef uint64_t i, j, k
    cdef csr_matso res

    indx, order = imdir(hum_dir)
    res = self.zeros_like()

    for i in range(self.data.size):
        
      ores = res.data[i]
      oval = self.data[i]
      soti_get_im_to_o( indx, order, &oval.num, &ores.num, dhl)

    # end for 

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
    cdef sotinum ores, oval
    cdef uint64_t i, j, k
    cdef csr_matso res

    indx, order = imdir(hum_dir)
    res = self.zeros_like()

    for i in range(self.data.size):
        
      ores = res.data[i]
      oval = self.data[i]
      soti_extract_im_to( indx, order, &oval.num, &ores.num, dhl)

    # end for 

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
    cdef sotinum ores, oval
    cdef uint64_t i, j, k
    cdef csr_matso res

    indx, order = imdir(hum_dir)
    res = self.zeros_like()

    for i in range(self.data.size):
        
      ores = res.data[i]
      oval = self.data[i]
      soti_extract_deriv_to( indx, order, &oval.num, &ores.num, dhl)

    # end for 

    return res 

  #---------------------------------------------------------------------------------------------------
  
  #***************************************************************************************************
  cpdef  get_order_im(self, ord_t order):
    """
    PURPOSE: Get the corresponding derivative in the matso object, as OTI number.
    """
    #*************************************************************************************************
    global dhl
    
    cdef sotinum ores, oval
    cdef uint64_t i, j, k
    cdef csr_matso res

    res = self.zeros_like()

    for i in range(self.data.size):
        
      ores = res.data[i]
      oval = self.data[i]
      soti_get_order_im_to( order, &oval.num, &ores.num, dhl)

    # end for 

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
    cdef sotinum ores, oval
    cdef uint64_t i, j, k
    cdef csr_matso res

    indx, order = imdir(hum_dir)
    res = self.zeros_like()

    for i in range(self.data.size):
        
      ores = res.data[i]
      oval = self.data[i]
      soti_truncate_im_to( indx, order, &oval.num, &ores.num, dhl)

    # end for 

    return res 

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  def get_active_bases(self):
    """
    PORPUSE: Get the bases with non-zero coefficients in the OTI number.
    """
    global dhl

    cdef bases_t  size       = dhl.p_dh[0].Nbasis
    cdef imdir_t* bases_list = dhl.p_dh[0].p_idx[0]
    cdef uint64_t i, j
    cdef sotinum oval
    
    # Initialize all elements as zero (deactivated)
    for i in range(size):

      bases_list[i]=0

    # end for 

    for i in range(self.data.size):

      oval = self.data[i]
      soti_get_active_bases( &oval.num, bases_list, dhl)

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
# :::::::::::::::::::::::::::::::::::: END OF CLASS csr_matso ::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::




















# ****************************************************************************************************
cdef void csrmatso_matmul_SO_to(csr_matso lhs, matso rhs, matso res):
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

      for l in range( lhs.indptr[i], lhs.indptr[i+1] ):

        # tmp = arr1[i,k] * arr2[k,j] + tmp
        k = lhs.indices[l]
        olhs = lhs.data[l]

        soti_gem_oo_to( &olhs.num,
                        &rhs.arr.p_data[ j + k * rhs.ncols ],
                        &tmp, &tmp, dhl)

      # end for

      arrso_set_item_ij_o( &tmp, i, j, &res.arr, dhl)

    # end for

  # end for 

# ----------------------------------------------------------------------------------------------------




# ****************************************************************************************************
cdef matso csrmatso_matmul_SO(csr_matso lhs, matso rhs):
  """
  PORPUSE:  Perform matrix-matrix multiplication between csr matrix and dense matrix.

  """
  
  global dhl
  cdef matso res
  
  res = zeros((lhs.nrows,rhs.ncols))

  csrmatso_matmul_SO_to( lhs, rhs, res)

  return res

# ----------------------------------------------------------------------------------------------------
