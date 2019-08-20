















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
  
  def __init__(self, nrows, ncols, ord_t order = 0, bases_t nbases = 0,  uint8_t FLAGS = 1): 
    """
    PURPOSE:      Python level constructor of the omat class.

    DESCRIPTION:  Creates a new matrix, reserving memory.
                 
    """
    #*************************************************************************************************
    global dhl
    
    self.FLAGS = FLAGS

    self.arr = oarr_createEmpty( nrows, ncols, nbases, order, dhl)

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

    out = "omat<"+" ndir: "+str(self.arr.ndir)+', order: '+str(self.arr.order)+'>\n'
    out+= "re:\n"
    # first print the real number:
    tmp = c_ptr_to_np_2darray_double(self.arr.re, self.arr.nrows, self.arr.ncols)
    
    out +=  repr(tmp)

    out += ""

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

    cdef np.ndarray[double, ndim=2] tmp 
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



# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# :::::::::::::::::::::::::::::::::::: END OF CLASS OMAT :::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::







# #*****************************************************************************************************
# cpdef omat dot(omat A, omat B):
  
#   cdef oarr_t res = oarr_matmul( &A.arr, &B.arr )

#   # TODO: Add check in python code.

#   return omat.create(&res)

# #-----------------------------------------------------------------------------------------------------


# #*****************************************************************************************************
# cpdef omat invert(omat A):
  
#   cdef oarr_t res = oarr_invert( &A.arr )

#   # TODO: Add check in python code.

#   return omat.create(&res)

# #-----------------------------------------------------------------------------------------------------



# #*****************************************************************************************************
# cpdef omat transpose(omat A):
  
#   cdef oarr_t res = oarr_transpose( &A.arr )

#   # TODO: Add check in python code.

#   return omat.create(&res)

# #-----------------------------------------------------------------------------------------------------

# #*****************************************************************************************************
# cpdef coeff_t det(omat A):
  
#   return oarr_det( &A.arr ) 

# #-----------------------------------------------------------------------------------------------------




# #*****************************************************************************************************
# cpdef omat eye(uint64_t size):
  
#   cdef oarr_t res = oarr_zeros(size,size)
#   cdef uint64_t i;

#   for i in range(size):

#     oarr_set_item_ij( 1.0, i, i,&res)

#   # end for 


#   return omat.create(&res)

# #-----------------------------------------------------------------------------------------------------

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