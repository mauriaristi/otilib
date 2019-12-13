






# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::     CLASS  matso    ::::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
cdef class matso:
  #---------------------------------------------------------------------------------------------------
  #------------------------------------   DEFINITION OF ATTRIBUTES   ---------------------------------
  #---------------------------------------------------------------------------------------------------
  
  #                                --->      Look in dense.pxd    <---

  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  
  def __init__(self, realArray, ord_t order = 0, bases_t nbases = 0, object nnz = None): 
    """
    PURPOSE:      Python level constructor of the somat class.

    DESCRIPTION:  Creates a new matrix, reserving memory Assumes coefficient values to be all zeroes.
                 
    """
    #*************************************************************************************************
    global dhl
    
    cdef uint64_t nrows, ncols, i,j
    cdef ord_t ordi
    cdef coeff_t val 


    if isinstance( realArray, np.ndarray):
      
      ndim = realArray.ndim
      
      if ndim >=3:
      
        raise ValueError("Only 1D and 2D arrays are supported.")
      
      elif (ndim == 1):
      
        ncols = 1      
        nrows = realArray.shape[0]

        self.arr = arrso_zeros_bases( nrows, ncols, nbases, order, dhl)

        for i in range(self.arr.nrows):
      
          val = realArray[i]
          arrso_set_item_i_r( val, i, &self.arr, dhl)
        
        # end for
      
      else: # ndim =2

        nrows = realArray.shape[0]
        ncols = realArray.shape[1]
        self.arr = arrso_zeros_bases( nrows, ncols, nbases, order, dhl)

        for i in range(self.arr.nrows):      
          for j in range(self.arr.ncols):
            
            val = realArray[i,j]
            arrso_set_item_ij_r( val, i, j, &self.arr, dhl)
          
          # end for        
        # end for

      # end if

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  def __dealloc__(self): 
    """
    PURPOSE:      Destructor of the class.                   
    """
    #*************************************************************************************************
    
    arrso_free(&self.arr)
    
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

    cdef np.ndarray[coeff_t, ndim=2] tmp
    cdef uint64_t i,j,k

    tmp = np.empty( self.shape , dtype = np.float64)

    for i in range(self.arr.nrows):
      for j in range(self.arr.ncols):
        k = j+i*self.arr.ncols
        tmp[i,j] = self.arr.p_data[k].re
      # end for 
    # end for 

    return tmp

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  @staticmethod
  cdef matso create(arrso_t* arr):
    """
    PURPOSE:      C-level constructor of the class. Use this when creating objects within 
                  Cython
                  
    """
    #*************************************************************************************************

    # create new empty object:
    cdef matso mat = <matso> matso.__new__(matso)

    mat.arr = arr[0]
    
    return mat

  #--------------------------------------------------------------------------------------------------- 

  #*************************************************************************************************** 
  def get_real(self):

    cdef np.ndarray[coeff_t, ndim=2] tmp
    cdef uint64_t i,j,k

    tmp = np.empty( self.shape , dtype = np.float64)

    for i in range(self.arr.nrows):
      for j in range(self.arr.ncols):
        k = j+i*self.arr.ncols
        tmp[i,j] = self.arr.p_data[k].re
      # end for 
    # end for 

    return tmp
  #--------------------------------------------------------------------------------------------------- 

  #*************************************************************************************************** 
  def __repr__(self):
    """
    PURPOSE:      A short representation of the object.
  
    """
    #*************************************************************************************************

    global dhl

    cdef np.ndarray[uint64_t, ndim=1] tmp 

    out =  "matso<"
    out += "shape: "+str(self.shape)+ ", "
    out += "order: "+str(self.arr.order)+", "

    tmp = c_ptr_to_np_1darray_uint64(self.arr.p_size,self.arr.order)

    out += "p_size: "+str(tmp)+", "
    out += "re:\n"
    # first print the real part:
    out += repr( self.get_real() )

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
  
    cdef sotinum_t d_soti
    cdef sotinum   soti
    out  = ""

    out += "["
    for i in range(self.arr.nrows):
      out += "["
      for j in range(self.arr.ncols):
        d_soti = arrso_get_item_ij(&self.arr, i, j, dhl)
        out+= (sotinum.create(&d_soti,FLAGS=0)).__str__()+", "
      # end for 
      out = out[:-2] + "],\n"
    # end for 
    out =out[:-2] + "]"
    return out

  #---------------------------------------------------------------------------------------------------  



  #***************************************************************************************************
  def  __getitem__(self, val):
    """
    PURPOSE: Get the value of an element of the item.
    """
    #*************************************************************************************************
    
    global dhl

    cdef sotinum_t res

    if (isinstance(val, int)):
      
      res = arrso_get_item_i( &self.arr, val, dhl)
    
    else:
      
      res = arrso_get_item_ij( &self.arr, val[0], val[1], dhl)

    # end if

    return sotinum.create(&res)

  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  def __setitem__(self, val, value):
    """
    PURPOSE: Set an element of the item to the specified value.
    """
    #*************************************************************************************************
        
    global dhl

    cdef sotinum valt
    
    tval = type(value)

    if (isinstance(val, int)):
      
      if tval == sotinum:

        valt = value
        arrso_set_item_i_o( &valt.num, val, &self.arr, dhl)

      else:

        arrso_set_item_i_r( value, val, &self.arr, dhl)

      # end if 
    
    else:
      
      if tval == sotinum:
        
        valt = value
        arrso_set_item_ij_o( &valt.num, val[0], val[1], &self.arr, dhl)

      else:

        arrso_set_item_ij_r( value, val[0], val[1], &self.arr, dhl)

      # end if 

    # end if


  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  def copy(self):
    """
    PURPOSE: Copy to a new object.
    """
    #*************************************************************************************************
    
    global dhl
    
    cdef arrso_t res = arrso_copy(&self.arr, dhl)

    return matso.create(&res)
  #---------------------------------------------------------------------------------------------------


  # #***************************************************************************************************
  # def __neg__(self):
  #   """
  #   PURPOSE: Negation overload.
  #   """
  #   #*************************************************************************************************
    
  #   global dhl
    
  #   cdef oarr_t res = oarr_neg(&self.arr, dhl)

  #   return somat.create(&res)
  # #---------------------------------------------------------------------------------------------------




  # #***************************************************************************************************
  # def __add__(self, other):
  #   """
  #   PURPOSE: Addition overload.
  #   """
  #   #*************************************************************************************************
    
  #   global dhl
    
  #   cdef oarr_t res 
  #   cdef somat lhs,rhs
  #   cdef dmat dlhs,drhs
  #   cdef otinum olhs,orhs
    
  #   tlhs = type(self)
  #   trhs = type(other)
    
  #   if (tlhs == trhs):

  #     lhs = self
  #     rhs = other

  #     res = oarr_sum_OO(&lhs.arr,&rhs.arr,dhl)

  #   elif ( tlhs  == otinum ):

  #     olhs = self
  #     rhs = other

  #     res = oarr_sum_oO(&olhs.num,&rhs.arr, dhl)

  #   elif ( trhs  == otinum ):

  #     lhs = self
  #     orhs = other

  #     res = oarr_sum_oO(&orhs.num,&lhs.arr, dhl)
    
  #   elif (tlhs in number_types):
      
  #     rhs = other
  #     res = oarr_sum_rO(self, &rhs.arr, dhl)

  #   elif (trhs in number_types):
        
  #     lhs = self
  #     res = oarr_sum_rO(other, &lhs.arr, dhl)

  #   elif ( tlhs  == dmat ):

  #     dlhs = self
  #     rhs = other

  #     res = oarr_sum_RO(&dlhs.arr,&rhs.arr, dhl)

  #   elif ( trhs  == dmat ):

  #     lhs = self
  #     drhs = other

  #     res = oarr_sum_RO(&drhs.arr,&lhs.arr, dhl)

  #   else:

  #     return NotImplemented      

  #   # end if 
      
  #   return somat.create(&res)

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
    
  #   cdef oarr_t res 
  #   cdef somat lhs,rhs
  #   cdef dmat dlhs,drhs
  #   cdef otinum olhs,orhs
    
  #   tlhs = type(self)
  #   trhs = type(other)
    
  #   if (tlhs == trhs):

  #     lhs = self
  #     rhs = other

  #     res = oarr_sub_OO(&lhs.arr,&rhs.arr,dhl)

  #   elif ( tlhs  == otinum ):

  #     olhs = self
  #     rhs = other

  #     res = oarr_sub_oO(&olhs.num,&rhs.arr, dhl)

  #   elif ( trhs  == otinum ):

  #     lhs = self
  #     orhs = other

  #     res = oarr_sub_Oo(&lhs.arr, &orhs.num, dhl)
    
  #   elif (tlhs in number_types):
      
  #     rhs = other
  #     res = oarr_sub_rO(self, &rhs.arr, dhl)

  #   elif (trhs in number_types):
        
  #     lhs = self
  #     res = oarr_sub_Or(&lhs.arr, other, dhl)

  #   elif ( tlhs  == dmat ):

  #     dlhs = self
  #     rhs = other

  #     res = oarr_sub_RO(&dlhs.arr,&rhs.arr, dhl)

  #   elif ( trhs  == dmat ):

  #     lhs = self
  #     drhs = other

  #     res = oarr_sub_OR(&lhs.arr, &drhs.arr, dhl)

  #   else:

  #     return NotImplemented      

  #   # end if 
      
  #   return somat.create(&res)

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
    
  #   cdef oarr_t res 
  #   cdef somat lhs,rhs
  #   cdef dmat dlhs,drhs
  #   cdef otinum olhs,orhs
    
  #   tlhs = type(self)
  #   trhs = type(other)
    
  #   if (tlhs == trhs):

  #     lhs = self
  #     rhs = other

  #     res = oarr_mul_OO(&lhs.arr,&rhs.arr,dhl)

  #   elif ( tlhs  == otinum ):

  #     olhs = self
  #     rhs = other

  #     res = oarr_mul_oO(&olhs.num,&rhs.arr, dhl)

  #   elif ( trhs  == otinum ):

  #     lhs = self
  #     orhs = other

  #     res = oarr_mul_oO(&orhs.num,&lhs.arr, dhl)
    
  #   elif (tlhs in number_types):
      
  #     rhs = other
  #     res = oarr_mul_rO(self, &rhs.arr, dhl)

  #   elif (trhs in number_types):
        
  #     lhs = self
  #     res = oarr_mul_rO(other, &lhs.arr, dhl)

  #   elif ( tlhs  == dmat ):

  #     dlhs = self
  #     rhs = other

  #     res = oarr_mul_RO(&dlhs.arr,&rhs.arr, dhl)

  #   elif ( trhs  == dmat ):

  #     lhs = self
  #     drhs = other

  #     res = oarr_mul_RO(&drhs.arr,&lhs.arr, dhl)

  #   else:

  #     return NotImplemented      

  #   # end if 
      
  #   return somat.create(&res)

    

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
    
  #   cdef oarr_t res 
  #   cdef somat lhs,rhs
  #   cdef dmat dlhs,drhs
  #   cdef otinum olhs,orhs
    
  #   tlhs = type(self)
  #   trhs = type(other)
    
  #   if (tlhs == trhs):

  #     # lhs = self
  #     # rhs = other

  #     # res = oarr_div_OO(&lhs.arr,&rhs.arr,dhl)

  #     return NotImplemented

  #   elif ( tlhs  == otinum ):

  #     # olhs = self
  #     # rhs = other

  #     # res = oarr_div_oO(&olhs.num,&rhs.arr, dhl)

  #     return NotImplemented

  #   elif ( trhs  == otinum ):

  #     # lhs = self
  #     # orhs = other

  #     # res = oarr_div_oO(&orhs.num,&lhs.arr, dhl)

  #     return NotImplemented
    
  #   elif (tlhs in number_types):
      
  #     # rhs = other
  #     # res = oarr_div_rO(self, &rhs.arr, dhl)

  #     return NotImplemented      

  #   elif (trhs in number_types):
        
  #     lhs = self
  #     res = oarr_div_Or(&lhs.arr, other, dhl)

  #   elif ( tlhs  == dmat ):

  #     # dlhs = self
  #     # rhs = other

  #     # res = oarr_div_RO(&dlhs.arr,&rhs.arr, dhl)

  #     return NotImplemented      

  #   elif ( trhs  == dmat ):

  #     lhs = self
  #     drhs = other

  #     res = oarr_div_OR(&lhs.arr, &drhs.arr, dhl)

  #   else:

  #     return NotImplemented      

  #   # end if 

  #   return somat.create(&res)

  # #---------------------------------------------------------------------------------------------------  

  # # #***************************************************************************************************
  # # cpdef np.ndarray[double, ndim=2] to_numpy(self):
  # #   """
  # #   PURPOSE: Interface to numpy representation.
  # #   """
  # #   #*************************************************************************************************

  # #   return c_ptr_to_np_2oarray_double(self.arr.p_data, self.arr.nrows, self.arr.ncols)

  # # #---------------------------------------------------------------------------------------------------    

  # # #***************************************************************************************************
  # # def __pow__(self, n,z):
  # #   """
  # #   PURPOSE: Power function.
  # #   """
  # #   #*************************************************************************************************

  # #   return power(self,n)

  # # #---------------------------------------------------------------------------------------------------  


  # #***************************************************************************************************
  # cpdef copy(self):
  #   """
  #   PURPOSE: Copy the elements to new memory spaces.
  #   """
  #   #*************************************************************************************************
    
  #   global dhl
    
  #   cdef oarr_t res = oarr_copy(&self.arr, dhl)    
      
  #   return somat.create(&res)

  # #---------------------------------------------------------------------------------------------------  
  

  # #***************************************************************************************************
  # def get_deriv(self, hum_dir ,copy=True):
  #   """
  #   PURPOSE: Get the corresponding derivative of the system.
  #   """
  #   #*************************************************************************************************
  #   global dhl

  #   cdef list item = imdir(hum_dir)
  #   cdef np.ndarray[coeff_t, ndim=2] tmp
  #   cdef coeff_t factor = 1

  #   tmp = self.get_imdir( item[ZERO], item[ONE],copy=copy)

  #   factor = dhelp_get_deriv_factor(item[ZERO], item[ONE], dhl)

  #   return tmp * factor

  # #---------------------------------------------------------------------------------------------------  

  # #***************************************************************************************************
  # cpdef get_im(self, hum_dir, copy = True):
  #   """
  #   PURPOSE: Get the corresponding imaginary direction in the somat object.
  #   """
  #   #*************************************************************************************************
  #   global dhl
    
  #   cdef list item = imdir(hum_dir)

  #   return self.get_imdir( item[ZERO], item[ONE], copy = copy )

  # #---------------------------------------------------------------------------------------------------


  # #***************************************************************************************************
  # cpdef get_imdir(self, imdir_t idx , ord_t order, copy = True):
  #   """
  #   PURPOSE: Get the corresponding imaginary direction in the somat object.
  #   """
  #   #*************************************************************************************************
  #   global dhl

  #   cdef np.ndarray[coeff_t, ndim=2] tmp

  #   # Check first if derivative is the real coefficient.
    
  #   if order <= self.arr.order:

  #     if order == 0:

  #       tmp = c_ptr_to_np_2darray_double(self.arr.re, self.arr.nrows, self.arr.ncols)

  #     else: 
        
  #       if idx < self.arr.p_ndpo[order-1]:
          
  #         tmp =  c_ptr_to_np_2darray_double(self.arr.p_im[ order-1 ][ idx ], 
  #                                             self.arr.nrows, self.arr.ncols)
          
  #       else:

  #         tmp = np.zeros(self.shape)

  #       # end if

  #     # end if 

  #   else: 

  #     tmp = np.zeros(self.shape)
   
  #   # end if 

  #   # Export as a copy if requested.
  #   if copy:
      
  #     return tmp.copy()

  #   else:

  #     return tmp

  #   # end if 

  # #---------------------------------------------------------------------------------------------------

  

  # #***************************************************************************************************
  # cpdef set_imdir(self,np.ndarray[coeff_t, ndim=2] arr, imdir_t idx , ord_t order):
  #   """
  #   PURPOSE: Get the corresponding imaginary direction in the somat object.
  #   """
  #   #*************************************************************************************************
  #   global dhl

  #   # Check first if derivative is the real coefficient.

  #   if (arr.shape[0] != self.arr.nrows or arr.shape[1] != self.arr.ncols):

  #     raise IndexError("Dimension mismatch in set_imdir() method.")

  #   # end if 

  #   if (order <= self.arr.order):
    
  #     if (order == 0):

  #       copy_numpy2d_to_ptr_f64(arr, self.arr.re)

  #     else: 

  #       if (idx <= self.arr.p_ndpo[order-1]):

  #         copy_numpy2d_to_ptr_f64(arr, self.arr.p_im[ order-1 ][ idx ])
          

  #       # end if

  #     # end if 

  #   # end if  

  # #---------------------------------------------------------------------------------------------------

# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# :::::::::::::::::::::::::::::::::::: END OF CLASS somat :::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::








# #***************************************************************************************************
# cpdef somat addO(somat lhs, somat rhs, somat out = None):
#   """
#   PURPOSE:      Add two OTI numbers.
                
#   DESCRIPTION:  Eliminates the need to type check the input parameters 
  
#   INPUTS:
#                 lhs: otinum 
#                 rhs: otinum 
#                 out: otinum, optional. Result holder
                
#   """
#   #*************************************************************************************************
#   global dhl
#   cdef oarr_t res
  
#   if out != None:

#     oarr_sum_OO_to(&lhs.arr, &rhs.arr, &out.arr ,dhl)
#     return None

#   else:
#     # 
#     res = oarr_sum_OO(&lhs.arr, &rhs.arr, dhl)

#     return somat.create(&res)

# #--------------------------------------------------------------------------------------------------- 



# #***************************************************************************************************
# cpdef addO_to(somat lhs, somat rhs, somat out):
#   """
#   PURPOSE:      Add two elements.
                
#   DESCRIPTION:  Eliminates the need to type check the input parameters 
  
#   INPUTS:
#                 lhs: somat 
#                 rhs: somat 
#                 out: somat Result holder
                
#   """
#   #*************************************************************************************************
#   global dhl
  
#   oarr_sum_OO_to(&lhs.arr, &rhs.arr, &out.arr ,dhl)

# #--------------------------------------------------------------------------------------------------- 



# #*****************************************************************************************************
# cpdef somat dot(somat A, somat B):

#   global dhl
  
#   cdef oarr_t res = oarr_matmul_OO( &A.arr, &B.arr , dhl)

#   # TODO: Add check in python code.

#   return somat.create(&res)

# #-----------------------------------------------------------------------------------------------------


# #*****************************************************************************************************
# cpdef somat invert(somat A):
  
#   global dhl

#   cdef oarr_t res = oarr_invert( &A.arr, dhl )

#   # TODO: Add check in python code.

#   return somat.create(&res)

# #-----------------------------------------------------------------------------------------------------



# #*****************************************************************************************************
# cpdef somat transpose(somat A):
  
#   global dhl

#   cdef oarr_t res = oarr_transpose( &A.arr, dhl )

#   # TODO: Add check in python code.

#   return somat.create(&res)

# #-----------------------------------------------------------------------------------------------------

# #*****************************************************************************************************
# cpdef otinum det(somat A):
  
#   global dhl

#   cdef otinum_t res = oarr_det( &A.arr, dhl)

#   return otinum.create(&res)
  

# #-----------------------------------------------------------------------------------------------------




#*****************************************************************************************************
cpdef matso eye(uint64_t size, bases_t nbases=0, ord_t order=0):
  
  global dhl

  cdef arrso_t res = arrso_eye_bases(size, nbases, order, dhl)

  return matso.create(&res)

#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cpdef matso zeros( uint64_t nrows, uint64_t ncols, bases_t nbases=0, ord_t order=0):
  
  global dhl

  cdef arrso_t res = arrso_zeros_bases(nrows,ncols,nbases,order,dhl)

  return matso.create(&res)

#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cpdef matso ones(uint64_t nrows,uint64_t ncols, bases_t nbases=0, ord_t order=0):
  
  global dhl

  cdef arrso_t res = arrso_ones_bases(nrows,ncols,nbases,order,dhl)

  return matso.create(&res)
  
#-----------------------------------------------------------------------------------------------------



# #*****************************************************************************************************
# def solve(somat A, somat b):
#   """
  
#   PORPUSE: To solve a dense linear system of equations of OTI algebra.

#   """
  
#   global dhl

#   from scipy.sparse import coo_matrix
#   from scipy.linalg import lu_factor, lu_solve

#   # Get the corresponding matrix form.
#   cdef uint64_t i, j, k
#   # cdef oarr_t oarr_res
#   cdef somat res
#   cdef np.ndarray[coeff_t, ndim=2] tmp
#   cdef np.ndarray[coeff_t, ndim=2] tmp_rhs
#   cdef np.ndarray[coeff_t, ndim=2] tmp_dot

#   cdef matrix_form_t matform

#   cdef np.ndarray[uint64_t, ndim=1] rows
#   cdef np.ndarray[uint64_t, ndim=1] cols
#   cdef np.ndarray[uint64_t, ndim=1] idx_coo  
#   cdef np.ndarray[ uint8_t, ndim=1] ord_coo

#   maxorder  = max(A.arr.order, b.arr.order)
#   maxnbases = max(A.arr.nbases,b.arr.nbases)

#   res = zeros(b.arr.nrows, b.arr.ncols, nbases = maxnbases, order = maxorder)

#   # TODO: use matrix inner product from dmat object.
#   matform = dhelp_matrix_form_indices(maxnbases,maxorder,dhl)

#   rows    = c_ptr_to_np_1darray_uint64( matform.p_rows, matform.nonzero)
#   cols    = c_ptr_to_np_1darray_uint64( matform.p_cols, matform.nonzero)
#   idx_coo = c_ptr_to_np_1darray_uint64( matform.p_im  , matform.nonzero)
#   ord_coo = c_ptr_to_np_1darray_uint8 ( matform.p_ord , matform.nonzero)


  
#   indices = np.arange( 1, matform.nonzero+1, dtype = np.uint64)

#   dummy_mat = coo_matrix( ( indices, (rows.copy(), cols.copy()) ), dtype = np.uint64 )
#   dummy_mat = dummy_mat.tocsr()

#   # first_col_indices = dummy_mat[:,0].data-1
#   first_col_indices = indices[ (matform.sizex-1) : (2*matform.sizex-1) ] - 1
  
#   # Get vector form index and order pairs
#   vec_form_idx = idx_coo[first_col_indices]
#   vec_form_ord = ord_coo[first_col_indices]
  
  

#   # Factorize system.
#   factorization = lu_factor( A.get_imdir(0,0) )

#   # Solve the real system of equations.
#   tmp = lu_solve(factorization, b.get_imdir(0,0) )
#   res.set_imdir( tmp, 0, 0)

#   # Solve the imaginary systems.
#   tmp_rhs = np.zeros(b.shape,dtype = np.float64)
#   tmp_dot = np.zeros(b.shape,dtype = np.float64)

#   for i in range(1, dummy_mat.shape[0]):

#     # print("\n\ni: ",i)
#     # get the i'th row of elements to operate.
#     # row_indices = dummy_mat[i].data - 1
#     row_indices = dummy_mat.data[dummy_mat.indptr[i]:dummy_mat.indptr[i+1]] - 1

#     row_idx = idx_coo[row_indices]
#     row_ord = ord_coo[row_indices]

#     # Get the imaginary direation from the OTI rhs
#     tmp_rhs[:,:] = b.get_imdir( row_idx[ZERO], row_ord[ZERO], copy=False )

#     # print("RHS:\n",tmp_rhs)
    
#     k = row_idx.size-1
#     # Get A imaginary times b real.
#     np.dot( A.get_imdir(row_idx[ZERO], row_ord[ZERO], copy=False ), 
#           res.get_imdir(row_idx[   k], row_ord[   k], copy=False ), out = tmp_dot )

#     tmp_rhs -= tmp_dot

#     # print("RHS:\n",tmp_rhs)
#     # Solving 
#     for j in range(1,row_idx.size-1):

#       k = (row_idx.size-1) - j

#       # Get A imaginary times b real.

#       np.dot( A.get_imdir(row_idx[j], row_ord[j], copy=False ), 
#             res.get_imdir(row_idx[k], row_ord[k], copy=False ),out = tmp_dot )
#       tmp_rhs -= tmp_dot
#     # end for 

#     # print("\n\nFinal RHS:\n",tmp_rhs)
#     # Solve the system of equations.
#     tmp = lu_solve(factorization, tmp_rhs )

#     # Write the result on the system.
#     res.set_imdir( tmp, vec_form_idx[i], vec_form_ord[i])

#   # end for 
  
#   free(matform.p_im)
#   free(matform.p_ord)
#   free(matform.p_rows)
#   free(matform.p_cols)

#   return res

# #-----------------------------------------------------------------------------------------------------



