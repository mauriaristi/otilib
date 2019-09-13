















# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::     CLASS  OMAT    ::::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
cdef class omat:
  #---------------------------------------------------------------------------------------------------
  #------------------------------------   DEFINITION OF ATTRIBUTES   ---------------------------------
  #---------------------------------------------------------------------------------------------------
  
  #                                --->      Look in dense.pxd    <---

  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  
  def __init__(self, realArray, ord_t order = 0, bases_t nbases = 0,  uint8_t FLAGS = 1): 
    """
    PURPOSE:      Python level constructor of the omat class.

    DESCRIPTION:  Creates a new matrix, reserving memory.
                 
    """
    #*************************************************************************************************
    global dhl
    
    cdef uint64_t nrows, ncols, i,j
    cdef dmat inval
    cdef double val 

    self.FLAGS = FLAGS

    if isinstance(realArray,np.ndarray):
      ndim = realArray.ndim
      
      if ndim >=3:
      
        raise ValueError("Only 1D and 2D arrays are supported.")
      
      elif (ndim == 1):
      
        ncols = 1
      
        nrows = realArray.shape[0]

        self.arr = oarr_zeros( nrows, ncols, nbases, order, dhl)

        for i in range(self.arr.nrows):
      
          val = realArray[i]
          self.arr.re[i] = val
        
        # end for
      
      else: # ndim =2

        nrows = realArray.shape[0]
        ncols = realArray.shape[1]

        self.arr = oarr_zeros( nrows, ncols, nbases, order, dhl)

        for i in range(self.arr.nrows):
      
          for j in range(self.arr.ncols):
            
            val = realArray[i,j]
            self.arr.re[j+i*self.arr.ncols] = val
          
          # end for
        
        # end for

      # end if

    elif type(realArray) == dmat:
      
      inval = realArray
      self.arr = oarr_zeros( inval.nrows, inval.ncols, nbases, order, dhl)

      for i in range(self.arr.nrows):
      
        for j in range(self.arr.ncols):
      
          self.arr.re[j+i*self.arr.ncols] = inval.arr.p_data[j+i*inval.arr.ncols]
        
        # end for
      
      # end for



  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  def __dealloc__(self): 
    """
    PURPOSE:      Destructor of the class.                   
    """
    #*************************************************************************************************
    
    if self.FLAGS & 1: # If memory is owned.
      
      oarr_free(&self.arr)

    #end if 
    
  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  @property
  def shape(self): 
    """
    PURPOSE:      Return the shape of the stored matrix. 
    """
    #*************************************************************************************************

    return (self.arr.nrows,self.arr.ncols)

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  @property
  def  size(self): 
    """
    PURPOSE:      Return the size of array.                
    """
    #*************************************************************************************************

    return self.arr.size

  #---------------------------------------------------------------------------------------------------
  
  #***************************************************************************************************
  @property
  def real(self):
    """
    PURPOSE:      Get a numpy array with all coefficients in the real direction.

    """
    #*************************************************************************************************

    cdef uint64_t i,j,k
    cdef double val
    
    cdef np.ndarray res = np.empty(( self.arr.nrows,self.arr.ncols),dtype = np.float64)
    cdef darr_t re;

    re.nrows = self.arr.nrows
    re.ncols = self.arr.ncols
    re.size  = self.arr.size

    re.p_data = self.arr.re

    for i in range(self.arr.nrows):
      for j in range(self.arr.ncols):
      
        res[i,j] = darr_get_item_ij(&re, i, j)

    # end for
    
    return res

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  @staticmethod
  cdef omat create(oarr_t* arr, uint8_t FLAGS = 1):
    """
    PURPOSE:      C-level constructor of the class. Use this when creating objects within 
                  Cython
                  
    """
    #*************************************************************************************************

    # create new empty object:
    cdef omat mat = <omat> omat.__new__(omat)

    mat.arr = arr[0]
    mat.FLAGS = FLAGS
    
    return mat

  #--------------------------------------------------------------------------------------------------- 


  #*************************************************************************************************** 
  def __repr__(self):
    """
    PURPOSE:      A short representation of the object.
  
    """
    #*************************************************************************************************

    global dhl
    global h

    cdef np.ndarray[double, ndim=2] tmp 

    out =  "omat<"
    out += "shape: "+str(self.shape)+ ", "
    out += "ndir: "+str(self.arr.ndir)+", "
    out += "order: "+str(self.arr.order)+", "
    out += "re:\n"
    # first print the real number:
    tmp = c_ptr_to_np_2darray_double(self.arr.re, self.arr.nrows, self.arr.ncols)
    
    out +=  repr(tmp)

    out += ">"

    return out

  #--------------------------------------------------------------------------------------------------- 
  

  #***************************************************************************************************
  def __str__(self):
    """
    PURPOSE:      Create a string representation of the object.    
    """
    #*************************************************************************************************
    
    global dhl
    global h

    cdef np.ndarray[coeff_t, ndim=2] tmp 
    cdef ord_t ordi
    cdef uint64_t i

    out = ""

    # first print the real number:
    tmp = c_ptr_to_np_2darray_double(self.arr.re, self.arr.nrows, self.arr.ncols)
    out +=  str(tmp) + "\n"

    # Print imaginary directions
    for ordi in range(self.arr.order):

      for i in range(self.arr.p_ndpo[ordi]):

        # Print imaginary direction first
        out += '+ e(' 
        
        out += str(h.get_compact_fulldir(i,ordi+1)).replace(' ','')
        out += ") * \n"

        tmp = c_ptr_to_np_2darray_double(self.arr.p_im[ordi][i], self.arr.nrows, self.arr.ncols)
        out +=  str(tmp) + "\n"

    # end for
    
    out += ""

    return out

  #---------------------------------------------------------------------------------------------------  



  #***************************************************************************************************
  def  __getitem__(self, val):
    """
    PURPOSE: Get the value of an element of the item.
    """
    #*************************************************************************************************
    
    global dhl

    cdef otinum_t res

    if (isinstance(val, int)):
      
      res = oarr_get_item_i( &self.arr, val, dhl)
    
    else:
      
      res = oarr_get_item_ij( &self.arr, val[0], val[1], dhl)

    # end if

    return otinum.create(&res)

  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  def __setitem__(self, val, value):
    """
    PURPOSE: Set an element of the item to the specified value.
    """
    #*************************************************************************************************
        
    global dhl

    cdef otinum valt
    
    tval = type(value)

    if (isinstance(val, int)):
      
      if tval == otinum:
        print('here:')
        valt = value
        oarr_set_item_i_o( &valt.num, val, &self.arr, dhl)

      else:

        oarr_set_item_i_r( value, val, &self.arr, dhl)

      # end if 
    
    else:
      
      if tval == otinum:
        
        valt = value
        oarr_set_item_ij_o( &valt.num, val[0], val[1], &self.arr, dhl)

      else:

        oarr_set_item_ij_r( value, val[0], val[1], &self.arr, dhl)

      # end if 

    # end if


  #---------------------------------------------------------------------------------------------------  




  #***************************************************************************************************
  def __neg__(self):
    """
    PURPOSE: Negation overload.
    """
    #*************************************************************************************************
    
    global dhl
    
    cdef oarr_t res = oarr_neg(&self.arr, dhl)

    return omat.create(&res)
  #---------------------------------------------------------------------------------------------------




  #***************************************************************************************************
  def __add__(self, other):
    """
    PURPOSE: Addition overload.
    """
    #*************************************************************************************************
    
    global dhl
    
    cdef oarr_t res 
    cdef omat lhs,rhs
    cdef dmat dlhs,drhs
    cdef otinum olhs,orhs
    
    tlhs = type(self)
    trhs = type(other)
    
    if (tlhs == trhs):

      lhs = self
      rhs = other

      res = oarr_sum_OO(&lhs.arr,&rhs.arr,dhl)

    elif ( tlhs  == otinum ):

      olhs = self
      rhs = other

      res = oarr_sum_oO(&olhs.num,&rhs.arr, dhl)

    elif ( trhs  == otinum ):

      lhs = self
      orhs = other

      res = oarr_sum_oO(&orhs.num,&lhs.arr, dhl)
    
    elif (tlhs in number_types):
      
      rhs = other
      res = oarr_sum_rO(self, &rhs.arr, dhl)

    elif (trhs in number_types):
        
      lhs = self
      res = oarr_sum_rO(other, &lhs.arr, dhl)

    elif ( tlhs  == dmat ):

      dlhs = self
      rhs = other

      res = oarr_sum_RO(&dlhs.arr,&rhs.arr, dhl)

    elif ( trhs  == dmat ):

      lhs = self
      drhs = other

      res = oarr_sum_RO(&drhs.arr,&lhs.arr, dhl)

    else:

      return NotImplemented      

    # end if 
      
    return omat.create(&res)

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
  #************************************************************************
    
    global dhl
    
    cdef oarr_t res 
    cdef omat lhs,rhs
    cdef dmat dlhs,drhs
    cdef otinum olhs,orhs
    
    tlhs = type(self)
    trhs = type(other)
    
    if (tlhs == trhs):

      lhs = self
      rhs = other

      res = oarr_sub_OO(&lhs.arr,&rhs.arr,dhl)

    elif ( tlhs  == otinum ):

      olhs = self
      rhs = other

      res = oarr_sub_oO(&olhs.num,&rhs.arr, dhl)

    elif ( trhs  == otinum ):

      lhs = self
      orhs = other

      res = oarr_sub_Oo(&lhs.arr, &orhs.num, dhl)
    
    elif (tlhs in number_types):
      
      rhs = other
      res = oarr_sub_rO(self, &rhs.arr, dhl)

    elif (trhs in number_types):
        
      lhs = self
      res = oarr_sub_Or(&lhs.arr, other, dhl)

    elif ( tlhs  == dmat ):

      dlhs = self
      rhs = other

      res = oarr_sub_RO(&dlhs.arr,&rhs.arr, dhl)

    elif ( trhs  == dmat ):

      lhs = self
      drhs = other

      res = oarr_sub_OR(&lhs.arr, &drhs.arr, dhl)

    else:

      return NotImplemented      

    # end if 
      
    return omat.create(&res)

  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  def __isub__(self, other_in):
    """
    PURPOSE: Inplace subtraction overload.
    """
    #*************************************************************************************************
  
    return self - other_in

  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  def __mul__(self, other):
    """ 
    PURPOSE: Multiplication overload.
    """
    #*************************************************************************************************
    
    global dhl
    
    cdef oarr_t res 
    cdef omat lhs,rhs
    cdef dmat dlhs,drhs
    cdef otinum olhs,orhs
    
    tlhs = type(self)
    trhs = type(other)
    
    if (tlhs == trhs):

      lhs = self
      rhs = other

      res = oarr_mul_OO(&lhs.arr,&rhs.arr,dhl)

    elif ( tlhs  == otinum ):

      olhs = self
      rhs = other

      res = oarr_mul_oO(&olhs.num,&rhs.arr, dhl)

    elif ( trhs  == otinum ):

      lhs = self
      orhs = other

      res = oarr_mul_oO(&orhs.num,&lhs.arr, dhl)
    
    elif (tlhs in number_types):
      
      rhs = other
      res = oarr_mul_rO(self, &rhs.arr, dhl)

    elif (trhs in number_types):
        
      lhs = self
      res = oarr_mul_rO(other, &lhs.arr, dhl)

    elif ( tlhs  == dmat ):

      dlhs = self
      rhs = other

      res = oarr_mul_RO(&dlhs.arr,&rhs.arr, dhl)

    elif ( trhs  == dmat ):

      lhs = self
      drhs = other

      res = oarr_mul_RO(&drhs.arr,&lhs.arr, dhl)

    else:

      return NotImplemented      

    # end if 
      
    return omat.create(&res)

    

  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  def __imul__(self, other_in):
    """
    PURPOSE: Inplace multiplication overload.
    """
    #*************************************************************************************************

    return self * other_in

  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  def __truediv__(self, other):
    """
    PURPOSE: Division overload.
    """
    #*************************************************************************************************
    
    global dhl
    
    cdef oarr_t res 
    cdef omat lhs,rhs
    cdef dmat dlhs,drhs
    cdef otinum olhs,orhs
    
    tlhs = type(self)
    trhs = type(other)
    
    if (tlhs == trhs):

      # lhs = self
      # rhs = other

      # res = oarr_div_OO(&lhs.arr,&rhs.arr,dhl)

      return NotImplemented

    elif ( tlhs  == otinum ):

      # olhs = self
      # rhs = other

      # res = oarr_div_oO(&olhs.num,&rhs.arr, dhl)

      return NotImplemented

    elif ( trhs  == otinum ):

      # lhs = self
      # orhs = other

      # res = oarr_div_oO(&orhs.num,&lhs.arr, dhl)

      return NotImplemented
    
    elif (tlhs in number_types):
      
      # rhs = other
      # res = oarr_div_rO(self, &rhs.arr, dhl)

      return NotImplemented      

    elif (trhs in number_types):
        
      lhs = self
      res = oarr_div_Or(&lhs.arr, other, dhl)

    elif ( tlhs  == dmat ):

      # dlhs = self
      # rhs = other

      # res = oarr_div_RO(&dlhs.arr,&rhs.arr, dhl)

      return NotImplemented      

    elif ( trhs  == dmat ):

      lhs = self
      drhs = other

      res = oarr_div_OR(&lhs.arr, &drhs.arr, dhl)

    else:

      return NotImplemented      

    # end if 

    return omat.create(&res)

  #---------------------------------------------------------------------------------------------------  

  # #***************************************************************************************************
  # cpdef np.ndarray[double, ndim=2] to_numpy(self):
  #   """
  #   PURPOSE: Interface to numpy representation.
  #   """
  #   #*************************************************************************************************

  #   return c_ptr_to_np_2oarray_double(self.arr.p_data, self.arr.nrows, self.arr.ncols)

  # #---------------------------------------------------------------------------------------------------    

  # #***************************************************************************************************
  # def __pow__(self, n,z):
  #   """
  #   PURPOSE: Power function.
  #   """
  #   #*************************************************************************************************

  #   return power(self,n)

  # #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  cpdef copy(self):
    """
    PURPOSE: Copy the elements to new memory spaces.
    """
    #*************************************************************************************************
    
    global dhl
    
    cdef oarr_t res = oarr_copy(&self.arr, dhl)    
      
    return omat.create(&res)

  #---------------------------------------------------------------------------------------------------  
  

  #***************************************************************************************************
  def get_deriv(self, hum_dir ,copy=True):
    """
    PURPOSE: Get the corresponding derivative of the system.
    """
    #*************************************************************************************************
    global dhl

    cdef list item = imdir(hum_dir)
    cdef np.ndarray[coeff_t, ndim=2] tmp
    cdef coeff_t factor = 1

    tmp = self.get_imdir( item[ZERO], item[ONE],copy=copy)

    factor = dhelp_get_deriv_factor(item[ZERO], item[ONE], dhl)

    return tmp * factor

  #---------------------------------------------------------------------------------------------------  

  #***************************************************************************************************
  cpdef get_im(self, hum_dir, copy = True):
    """
    PURPOSE: Get the corresponding imaginary direction in the omat object.
    """
    #*************************************************************************************************
    global dhl
    
    cdef list item = imdir(hum_dir)

    return self.get_imdir( item[ZERO], item[ONE], copy = copy )

  #---------------------------------------------------------------------------------------------------


  #***************************************************************************************************
  cpdef get_imdir(self, imdir_t idx , ord_t order, copy = True):
    """
    PURPOSE: Get the corresponding imaginary direction in the omat object.
    """
    #*************************************************************************************************
    global dhl

    cdef np.ndarray[coeff_t, ndim=2] tmp

    # Check first if derivative is the real coefficient.
    
    if order <= self.arr.order:

      if order == 0:

        tmp = c_ptr_to_np_2darray_double(self.arr.re, self.arr.nrows, self.arr.ncols)

      else: 
        
        if idx < self.arr.p_ndpo[order-1]:
          
          tmp =  c_ptr_to_np_2darray_double(self.arr.p_im[ order-1 ][ idx ], 
                                              self.arr.nrows, self.arr.ncols)
          
        else:

          tmp = np.zeros(self.shape)

        # end if

      # end if 

    else: 

      tmp = np.zeros(self.shape)
   
    # end if 

    # Export as a copy if requested.
    if copy:
      
      return tmp.copy()

    else:

      return tmp

    # end if 

  #---------------------------------------------------------------------------------------------------

  

  #***************************************************************************************************
  cpdef set_imdir(self,np.ndarray[coeff_t, ndim=2] arr, imdir_t idx , ord_t order):
    """
    PURPOSE: Get the corresponding imaginary direction in the omat object.
    """
    #*************************************************************************************************
    global dhl

    # Check first if derivative is the real coefficient.

    if (arr.shape[0] != self.arr.nrows or arr.shape[1] != self.arr.ncols):

      raise IndexError("Dimension mismatch in set_imdir() method.")

    # end if 

    if (order <= self.arr.order):
    
      if (order == 0):

        copy_numpy2d_to_ptr_f64(arr, self.arr.re)

      else: 

        if (idx <= self.arr.p_ndpo[order-1]):

          copy_numpy2d_to_ptr_f64(arr, self.arr.p_im[ order-1 ][ idx ])
          

        # end if

      # end if 

    # end if  

  #---------------------------------------------------------------------------------------------------

# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# :::::::::::::::::::::::::::::::::::: END OF CLASS OMAT :::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::








#***************************************************************************************************
cpdef omat addO(omat lhs, omat rhs, omat out = None):
  """
  PURPOSE:      Add two OTI numbers.
                
  DESCRIPTION:  Eliminates the need to type check the input parameters 
  
  INPUTS:
                lhs: otinum 
                rhs: otinum 
                out: otinum, optional. Result holder
                
  """
  #*************************************************************************************************
  global dhl
  cdef oarr_t res
  
  if out != None:

    oarr_sum_OO_to(&lhs.arr, &rhs.arr, &out.arr ,dhl)
    return None

  else:
    # 
    res = oarr_sum_OO(&lhs.arr, &rhs.arr, dhl)

    return omat.create(&res)

#--------------------------------------------------------------------------------------------------- 



#***************************************************************************************************
cpdef addO_to(omat lhs, omat rhs, omat out):
  """
  PURPOSE:      Add two elements.
                
  DESCRIPTION:  Eliminates the need to type check the input parameters 
  
  INPUTS:
                lhs: omat 
                rhs: omat 
                out: omat Result holder
                
  """
  #*************************************************************************************************
  global dhl
  
  oarr_sum_OO_to(&lhs.arr, &rhs.arr, &out.arr ,dhl)

#--------------------------------------------------------------------------------------------------- 



#*****************************************************************************************************
cpdef omat dot(omat A, omat B):

  global dhl
  
  cdef oarr_t res = oarr_matmul_OO( &A.arr, &B.arr , dhl)

  # TODO: Add check in python code.

  return omat.create(&res)

#-----------------------------------------------------------------------------------------------------


#*****************************************************************************************************
cpdef omat invert(omat A):
  
  global dhl

  cdef oarr_t res = oarr_invert( &A.arr, dhl )

  # TODO: Add check in python code.

  return omat.create(&res)

#-----------------------------------------------------------------------------------------------------



#*****************************************************************************************************
cpdef omat transpose(omat A):
  
  global dhl

  cdef oarr_t res = oarr_transpose( &A.arr, dhl )

  # TODO: Add check in python code.

  return omat.create(&res)

#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cpdef otinum det(omat A):
  
  global dhl

  cdef otinum_t res = oarr_det( &A.arr, dhl)

  return otinum.create(&res)
  

#-----------------------------------------------------------------------------------------------------




#*****************************************************************************************************
cpdef omat eye(uint64_t size, bases_t nbases=0, ord_t order=0):
  
  global dhl

  cdef oarr_t res = oarr_eye(size, nbases, order, dhl)

  return omat.create(&res)

#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cpdef omat zeros( uint64_t nrows, uint64_t ncols, bases_t nbases=0, ord_t order=0):
  
  global dhl

  cdef oarr_t res = oarr_zeros(nrows,ncols,nbases,order,dhl)

  return omat.create(&res)

#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cpdef omat ones(uint64_t nrows,uint64_t ncols, bases_t nbases=0, ord_t order=0):
  
  global dhl

  cdef oarr_t res = oarr_ones(nrows,ncols,nbases,order,dhl)

  return omat.create(&res)
  
#-----------------------------------------------------------------------------------------------------



#*****************************************************************************************************
def solve(omat A, omat b):
  """
  
  PORPUSE: To solve a dense linear system of equations of OTI algebra.

  """
  
  global dhl

  from scipy.sparse import coo_matrix
  from scipy.linalg import lu_factor, lu_solve

  # Get the corresponding matrix form.
  cdef uint64_t i, j, k
  # cdef oarr_t oarr_res
  cdef omat res
  cdef np.ndarray[coeff_t, ndim=2] tmp
  cdef np.ndarray[coeff_t, ndim=2] tmp_rhs
  cdef np.ndarray[coeff_t, ndim=2] tmp_dot

  cdef matrix_form_t matform

  cdef np.ndarray[uint64_t, ndim=1] rows
  cdef np.ndarray[uint64_t, ndim=1] cols
  cdef np.ndarray[uint64_t, ndim=1] idx_coo  
  cdef np.ndarray[ uint8_t, ndim=1] ord_coo

  maxorder  = max(A.arr.order, b.arr.order)
  maxnbases = max(A.arr.nbases,b.arr.nbases)

  res = zeros(b.arr.nrows, b.arr.ncols, nbases = maxnbases, order = maxorder)

  # TODO: use matrix inner product from dmat object.
  matform = dhelp_matrix_form_indices(maxnbases,maxorder,dhl)

  rows    = c_ptr_to_np_1darray_uint64( matform.p_rows, matform.nonzero)
  cols    = c_ptr_to_np_1darray_uint64( matform.p_cols, matform.nonzero)
  idx_coo = c_ptr_to_np_1darray_uint64( matform.p_im  , matform.nonzero)
  ord_coo = c_ptr_to_np_1darray_uint8 ( matform.p_ord , matform.nonzero)


  
  indices = np.arange( 1, matform.nonzero+1, dtype = np.uint64)

  dummy_mat = coo_matrix( ( indices, (rows.copy(), cols.copy()) ), dtype = np.uint64 )
  dummy_mat = dummy_mat.tocsr()

  # first_col_indices = dummy_mat[:,0].data-1
  first_col_indices = indices[ (matform.sizex-1) : (2*matform.sizex-1) ] - 1
  
  # Get vector form index and order pairs
  vec_form_idx = idx_coo[first_col_indices]
  vec_form_ord = ord_coo[first_col_indices]
  
  

  # Factorize system.
  factorization = lu_factor( A.get_imdir(0,0) )

  # Solve the real system of equations.
  tmp = lu_solve(factorization, b.get_imdir(0,0) )
  res.set_imdir( tmp, 0, 0)

  # Solve the imaginary systems.
  tmp_rhs = np.zeros(b.shape,dtype = np.float64)
  tmp_dot = np.zeros(b.shape,dtype = np.float64)

  for i in range(1, dummy_mat.shape[0]):

    # print("\n\ni: ",i)
    # get the i'th row of elements to operate.
    # row_indices = dummy_mat[i].data - 1
    row_indices = dummy_mat.data[dummy_mat.indptr[i]:dummy_mat.indptr[i+1]] - 1

    row_idx = idx_coo[row_indices]
    row_ord = ord_coo[row_indices]

    # Get the imaginary direation from the OTI rhs
    tmp_rhs[:,:] = b.get_imdir( row_idx[ZERO], row_ord[ZERO], copy=False )

    # print("RHS:\n",tmp_rhs)
    
    k = row_idx.size-1
    # Get A imaginary times b real.
    np.dot( A.get_imdir(row_idx[ZERO], row_ord[ZERO], copy=False ), 
          res.get_imdir(row_idx[   k], row_ord[   k], copy=False ), out = tmp_dot )

    tmp_rhs -= tmp_dot

    # print("RHS:\n",tmp_rhs)
    # Solving 
    for j in range(1,row_idx.size-1):

      k = (row_idx.size-1) - j

      # Get A imaginary times b real.

      np.dot( A.get_imdir(row_idx[j], row_ord[j], copy=False ), 
            res.get_imdir(row_idx[k], row_ord[k], copy=False ),out = tmp_dot )
      tmp_rhs -= tmp_dot
    # end for 

    # print("\n\nFinal RHS:\n",tmp_rhs)
    # Solve the system of equations.
    tmp = lu_solve(factorization, tmp_rhs )

    # Write the result on the system.
    res.set_imdir( tmp, vec_form_idx[i], vec_form_ord[i])

  # end for 
  
  free(matform.p_im)
  free(matform.p_ord)
  free(matform.p_rows)
  free(matform.p_cols)

  return res

#-----------------------------------------------------------------------------------------------------




#*****************************************************************************************************
def solve_latex(bases_t nbases, ord_t order, real = 're'):
  """
  
  PORPUSE: To solve a dense linear system of equations of OTI algebra.

  """
  
  global dhl

  from scipy.sparse import coo_matrix

  # Get the corresponding matrix form.
  cdef uint64_t i, j, k
  cdef matrix_form_t matform

  cdef np.ndarray[uint64_t, ndim=1] rows
  cdef np.ndarray[uint64_t, ndim=1] cols
  cdef np.ndarray[uint64_t, ndim=1] idx_coo  
  cdef np.ndarray[ uint8_t, ndim=1] ord_coo


  # idx_coo, ord_coo = dhelp_get_matrix_form( nbases, order, 
  #                                           export_latex  =False, 
  #                                           export_strings=False, 
  #                                           export_sparse =True)

  matform = dhelp_matrix_form_indices(nbases,order,dhl)

  rows    = c_ptr_to_np_1darray_uint64( matform.p_rows, matform.nonzero)
  cols    = c_ptr_to_np_1darray_uint64( matform.p_cols, matform.nonzero)
  idx_coo = c_ptr_to_np_1darray_uint64( matform.p_im  , matform.nonzero)
  ord_coo = c_ptr_to_np_1darray_uint8 ( matform.p_ord , matform.nonzero)


  
  indices = np.arange( 1, matform.nonzero+1, dtype = np.uint64)

  dummy_mat = coo_matrix( ( indices, (rows.copy(), cols.copy()) ), dtype = np.uint64 )
  dummy_mat = dummy_mat.tocsr()

  # first_col_indices = dummy_mat[:,0].data-1
  first_col_indices = indices[ (matform.sizex-1) : (2*matform.sizex-1) ] - 1
  
  # Get vector form index and order pairs
  # vec_form_idx = idx_coo[first_col_indices]
  # vec_form_ord = ord_coo[first_col_indices]
  
  string = "\\begin{align}"

  # Fist solve real system of equations.
  string += "A_{"
  string += get_latex_dir( idx_coo[first_col_indices[ZERO]], ord_coo[first_col_indices[ZERO]], real = "re" )
  string += "}"

  string += "x_{"
  string += get_latex_dir( idx_coo[first_col_indices[ZERO]], ord_coo[first_col_indices[ZERO]], real = "re")
  string += "}"

  string += "&="

  string += "b_{"
  string += get_latex_dir( idx_coo[first_col_indices[ZERO]], ord_coo[first_col_indices[ZERO]], real = "re")
  string += "}"

  string += "\\\\"

  # Solve the imaginary systems.

  for i in range(1, dummy_mat.shape[0]):

    
    string += "A_{"
    string += get_latex_dir( idx_coo[first_col_indices[ZERO]], ord_coo[first_col_indices[ZERO]], real = "re" )
    string += "}"

    string += "x_{"
    string += get_latex_dir( idx_coo[first_col_indices[i]], ord_coo[first_col_indices[i]] )
    string += "}"



    # get the i'th row of elements to operate.
    # row_els = dummy_mat[i]
    # row_indices = dummy_mat[i].data - 1
    row_indices = dummy_mat.data[dummy_mat.indptr[i]:dummy_mat.indptr[i+1]] - 1

    row_idx = idx_coo[row_indices]
    row_ord = ord_coo[row_indices]

    string += " &= "

    string += "b_{"
    string += get_latex_dir( idx_coo[row_indices[ZERO]], ord_coo[row_indices[ZERO]] )
    string += '} '


    string += '-A_{'
    string += get_latex_dir( idx_coo[row_indices[ZERO]], ord_coo[row_indices[ZERO]]  )
    string += '}x_{'
    string += get_latex_dir( idx_coo[row_indices[row_indices.size-1] ], ord_coo[row_indices[ row_indices.size - 1 ]], real = "re" )
    string += '} '

    # Solving 
    for j in range(1,row_indices.size-1):

      k = (row_indices.size-1) - j
      string += ""
      string += "-A_{"
      string += get_latex_dir( idx_coo[row_indices[j]], ord_coo[row_indices[j]] )
      string += '}x_{'
      string += get_latex_dir( idx_coo[row_indices[k]], ord_coo[row_indices[k]] )
      string += '} '

    # end for 

    
    string += "\\\\ "
    # print(i,row_els.data)

    # print(string)

  # end for 
  string += "\\end{align}"

  free(matform.p_im)
  free(matform.p_ord)
  free(matform.p_rows)
  free(matform.p_cols)


  return string
  
  
#-----------------------------------------------------------------------------------------------------

















# #*****************************************************************************************************
# cpdef omat atanh(omat A):
  
#   cdef oarr_t res = oarr_atanh(&A.arr)

#   return omat.create(&res)

# #-----------------------------------------------------------------------------------------------------



# #*****************************************************************************************************
# cpdef omat asinh(omat A):
  
#   cdef oarr_t res = oarr_asinh(&A.arr)

#   return omat.create(&res)

# #-----------------------------------------------------------------------------------------------------



# #*****************************************************************************************************
# cpdef omat acosh(omat A):
  
#   cdef oarr_t res = oarr_acosh(&A.arr)

#   return omat.create(&res)

# #-----------------------------------------------------------------------------------------------------



# #*****************************************************************************************************
# cpdef omat tanh(omat A):
  
#   cdef oarr_t res = oarr_tanh(&A.arr)

#   return omat.create(&res)

# #-----------------------------------------------------------------------------------------------------



# #*****************************************************************************************************
# cpdef omat sqrt(omat A):
  
#   cdef oarr_t res = oarr_sqrt(&A.arr)

#   return omat.create(&res)

# #-----------------------------------------------------------------------------------------------------



# #*****************************************************************************************************
# cpdef omat cosh(omat A):
  
#   cdef oarr_t res = oarr_cosh(&A.arr)

#   return omat.create(&res)

# #-----------------------------------------------------------------------------------------------------



# #*****************************************************************************************************
# cpdef omat sinh(omat A):
  
#   cdef oarr_t res = oarr_sinh(&A.arr)

#   return omat.create(&res)

# #-----------------------------------------------------------------------------------------------------



# #*****************************************************************************************************
# cpdef omat asin(omat A):
  
#   cdef oarr_t res = oarr_asin(&A.arr)

#   return omat.create(&res)

# #-----------------------------------------------------------------------------------------------------



# #*****************************************************************************************************
# cpdef omat acos(omat A):
  
#   cdef oarr_t res = oarr_acos(&A.arr)

#   return omat.create(&res)

# #-----------------------------------------------------------------------------------------------------



# #*****************************************************************************************************
# cpdef omat atan(omat A):
  
#   cdef oarr_t res = oarr_atan(&A.arr)

#   return omat.create(&res)

# #-----------------------------------------------------------------------------------------------------



# #*****************************************************************************************************
# cpdef omat tan(omat A):
  
#   cdef oarr_t res = oarr_tan(&A.arr)

#   return omat.create(&res)

# #-----------------------------------------------------------------------------------------------------

# #*****************************************************************************************************
# cpdef omat cos(omat A):
  
#   cdef oarr_t res = oarr_cos(&A.arr)

#   return omat.create(&res)

# #-----------------------------------------------------------------------------------------------------

# #*****************************************************************************************************
# cpdef omat sin(omat A):
  
#   cdef oarr_t res = oarr_sin(&A.arr )

#   return omat.create(&res)

# #-----------------------------------------------------------------------------------------------------

# #*****************************************************************************************************
# cpdef omat log10(omat A):
  
#   cdef oarr_t res = oarr_log10(&A.arr)

#   return omat.create(&res)

# #-----------------------------------------------------------------------------------------------------

# #*****************************************************************************************************
# cpdef omat log(omat A):
  
#   cdef oarr_t res = oarr_log(&A.arr)

#   return omat.create(&res)

# #-----------------------------------------------------------------------------------------------------

# #*****************************************************************************************************
# cpdef omat exp(omat A):
  
#   cdef oarr_t res = oarr_exp(&A.arr)

#   return omat.create(&res)

# #-----------------------------------------------------------------------------------------------------

# #*****************************************************************************************************
# cpdef omat logb(omat A,coeff_t b):
  
#   cdef oarr_t res = oarr_logb(&A.arr,b)

#   return omat.create(&res)

# #-----------------------------------------------------------------------------------------------------

# #*****************************************************************************************************
# cpdef omat power(omat A,coeff_t b):
  
#   cdef oarr_t res = oarr_pow(&A.arr,b)

#   return omat.create(&res)

# #-----------------------------------------------------------------------------------------------------