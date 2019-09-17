


















# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::     CLASS  FEOMAT    ::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
cdef class feomat:
  #---------------------------------------------------------------------------------------------------
  #------------------------------------   DEFINITION OF ATTRIBUTES   ---------------------------------
  #---------------------------------------------------------------------------------------------------
  
  #                                --->      Look in dense.pxd    <---

  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  
  def __init__(self, bases_t nbases = 0, ord_t order = 0, uint8_t FLAGS = 1): 
    """
    PURPOSE:      Python level constructor of the feomat class.
                 
    """
    #*************************************************************************************************
    global dhl
    
    

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  def __dealloc__(self): 
    """
    PURPOSE:      Destructor of the class.                   
    """
    #*************************************************************************************************
    
    if self.FLAGS & 1: # If memory is owned.
      
      feoarr_free(&self.arr)

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
  cdef feomat create(feoarr_t* arr, uint8_t FLAGS = 1):
    """
    PURPOSE:      C-level constructor of the class. Use this when creating objects within 
                  Cython
                  
    """
    #*************************************************************************************************

    # create new empty object:
    cdef feomat mat = <feomat> feomat.__new__(feomat)

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

    out =  "feomat<"
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
      
      res = feoarr_get_item_i( &self.arr, val, dhl)
    
    else:
      
      res = feoarr_get_item_ij( &self.arr, val[0], val[1], dhl)

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
        feoarr_set_item_i_o( &valt.num, val, &self.arr, dhl)

      else:

        feoarr_set_item_i_r( value, val, &self.arr, dhl)

      # end if 
    
    else:
      
      if tval == otinum:
        
        valt = value
        feoarr_set_item_ij_o( &valt.num, val[0], val[1], &self.arr, dhl)

      else:

        feoarr_set_item_ij_r( value, val[0], val[1], &self.arr, dhl)

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
    
    cdef feoarr_t res = feoarr_neg(&self.arr, dhl)

    return feomat.create(&res)
  #---------------------------------------------------------------------------------------------------




  #***************************************************************************************************
  def __add__(self, other):
    """
    PURPOSE: Addition overload.
    """
    #*************************************************************************************************
    
    global dhl
    
    cdef feoarr_t res 
    cdef feomat lhs,rhs
    cdef dmat dlhs,drhs
    cdef otinum olhs,orhs
    
    tlhs = type(self)
    trhs = type(other)
    
    if (tlhs == trhs):

      lhs = self
      rhs = other

      res = feoarr_sum_OO(&lhs.arr,&rhs.arr,dhl)

    elif ( tlhs  == otinum ):

      olhs = self
      rhs = other

      res = feoarr_sum_oO(&olhs.num,&rhs.arr, dhl)

    elif ( trhs  == otinum ):

      lhs = self
      orhs = other

      res = feoarr_sum_oO(&orhs.num,&lhs.arr, dhl)
    
    elif (tlhs in number_types):
      
      rhs = other
      res = feoarr_sum_rO(self, &rhs.arr, dhl)

    elif (trhs in number_types):
        
      lhs = self
      res = feoarr_sum_rO(other, &lhs.arr, dhl)

    elif ( tlhs  == dmat ):

      dlhs = self
      rhs = other

      res = feoarr_sum_RO(&dlhs.arr,&rhs.arr, dhl)

    elif ( trhs  == dmat ):

      lhs = self
      drhs = other

      res = feoarr_sum_RO(&drhs.arr,&lhs.arr, dhl)

    else:

      return NotImplemented      

    # end if 
      
    return feomat.create(&res)

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
    
    cdef feoarr_t res 
    cdef feomat lhs,rhs
    cdef dmat dlhs,drhs
    cdef otinum olhs,orhs
    
    tlhs = type(self)
    trhs = type(other)
    
    if (tlhs == trhs):

      lhs = self
      rhs = other

      res = feoarr_sub_OO(&lhs.arr,&rhs.arr,dhl)

    elif ( tlhs  == otinum ):

      olhs = self
      rhs = other

      res = feoarr_sub_oO(&olhs.num,&rhs.arr, dhl)

    elif ( trhs  == otinum ):

      lhs = self
      orhs = other

      res = feoarr_sub_Oo(&lhs.arr, &orhs.num, dhl)
    
    elif (tlhs in number_types):
      
      rhs = other
      res = feoarr_sub_rO(self, &rhs.arr, dhl)

    elif (trhs in number_types):
        
      lhs = self
      res = feoarr_sub_Or(&lhs.arr, other, dhl)

    elif ( tlhs  == dmat ):

      dlhs = self
      rhs = other

      res = feoarr_sub_RO(&dlhs.arr,&rhs.arr, dhl)

    elif ( trhs  == dmat ):

      lhs = self
      drhs = other

      res = feoarr_sub_OR(&lhs.arr, &drhs.arr, dhl)

    else:

      return NotImplemented      

    # end if 
      
    return feomat.create(&res)

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
    
    cdef feoarr_t res 
    cdef feomat lhs,rhs
    cdef dmat dlhs,drhs
    cdef otinum olhs,orhs
    
    tlhs = type(self)
    trhs = type(other)
    
    if (tlhs == trhs):

      lhs = self
      rhs = other

      res = feoarr_mul_OO(&lhs.arr,&rhs.arr,dhl)

    elif ( tlhs  == otinum ):

      olhs = self
      rhs = other

      res = feoarr_mul_oO(&olhs.num,&rhs.arr, dhl)

    elif ( trhs  == otinum ):

      lhs = self
      orhs = other

      res = feoarr_mul_oO(&orhs.num,&lhs.arr, dhl)
    
    elif (tlhs in number_types):
      
      rhs = other
      res = feoarr_mul_rO(self, &rhs.arr, dhl)

    elif (trhs in number_types):
        
      lhs = self
      res = feoarr_mul_rO(other, &lhs.arr, dhl)

    elif ( tlhs  == dmat ):

      dlhs = self
      rhs = other

      res = feoarr_mul_RO(&dlhs.arr,&rhs.arr, dhl)

    elif ( trhs  == dmat ):

      lhs = self
      drhs = other

      res = feoarr_mul_RO(&drhs.arr,&lhs.arr, dhl)

    else:

      return NotImplemented      

    # end if 
      
    return feomat.create(&res)

    

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
    
    cdef feoarr_t res 
    cdef feomat lhs,rhs
    cdef dmat dlhs,drhs
    cdef otinum olhs,orhs
    
    tlhs = type(self)
    trhs = type(other)
    
    if (tlhs == trhs):

      # lhs = self
      # rhs = other

      # res = feoarr_div_OO(&lhs.arr,&rhs.arr,dhl)

      return NotImplemented

    elif ( tlhs  == otinum ):

      # olhs = self
      # rhs = other

      # res = feoarr_div_oO(&olhs.num,&rhs.arr, dhl)

      return NotImplemented

    elif ( trhs  == otinum ):

      # lhs = self
      # orhs = other

      # res = feoarr_div_oO(&orhs.num,&lhs.arr, dhl)

      return NotImplemented
    
    elif (tlhs in number_types):
      
      # rhs = other
      # res = feoarr_div_rO(self, &rhs.arr, dhl)

      return NotImplemented      

    elif (trhs in number_types):
        
      lhs = self
      res = feoarr_div_Or(&lhs.arr, other, dhl)

    elif ( tlhs  == dmat ):

      # dlhs = self
      # rhs = other

      # res = feoarr_div_RO(&dlhs.arr,&rhs.arr, dhl)

      return NotImplemented      

    elif ( trhs  == dmat ):

      lhs = self
      drhs = other

      res = feoarr_div_OR(&lhs.arr, &drhs.arr, dhl)

    else:

      return NotImplemented      

    # end if 

    return feomat.create(&res)

  #---------------------------------------------------------------------------------------------------  

  #***************************************************************************************************
  cpdef copy(self):
    """
    PURPOSE: Copy the elements to new memory spaces.
    """
    #*************************************************************************************************
    
    global dhl
    
    cdef feoarr_t res = feoarr_copy(&self.arr, dhl)    
      
    return feomat.create(&res)

  #---------------------------------------------------------------------------------------------------
  


  # cpdef integrate(self, intwts):

# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# :::::::::::::::::::::::::::::::::::: END OF CLASS FEOMAT :::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

























#*****************************************************************************************************
cpdef feomat dot(feomat A, feomat B):

  global dhl
  
  cdef feoarr_t res = feoarr_matmul_OO( &A.arr, &B.arr , dhl)

  # TODO: Add check in python code.

  return feomat.create(&res)

#-----------------------------------------------------------------------------------------------------


#*****************************************************************************************************
cpdef feomat invert(feomat A):
  
  global dhl

  cdef feoarr_t res = feoarr_invert( &A.arr, dhl )

  # TODO: Add check in python code.

  return feomat.create(&res)

#-----------------------------------------------------------------------------------------------------



#*****************************************************************************************************
cpdef feomat transpose(feomat A):
  
  global dhl

  cdef feoarr_t res = feoarr_transpose( &A.arr, dhl )

  # TODO: Add check in python code.

  return feomat.create(&res)

#-----------------------------------------------------------------------------------------------------





#*****************************************************************************************************
cpdef otinum det(feomat A):
  
  global dhl

  cdef otinum_t res = feoarr_det( &A.arr, dhl)

  return otinum.create(&res)
  

#-----------------------------------------------------------------------------------------------------




#*****************************************************************************************************
cpdef feomat eye(uint64_t size, bases_t nbases=0, ord_t order=0):
  
  global dhl

  cdef feoarr_t res = feoarr_eye(size, nbases, order, dhl)

  return feomat.create(&res)

#-----------------------------------------------------------------------------------------------------














#*****************************************************************************************************
cpdef feomat zeros( uint64_t nrows, uint64_t ncols, bases_t nbases=0, ord_t order=0):
  
  global dhl

  cdef feoarr_t res = feoarr_zeros(nrows,ncols,nbases,order,dhl)

  return feomat.create(&res)

#-----------------------------------------------------------------------------------------------------















#*****************************************************************************************************
cpdef feomat empty( uint64_t nrows, uint64_t ncols, bases_t nbases=0, ord_t order=0):
  
  global dhl

  cdef feoarr_t res = feoarr_zeros(nrows,ncols,nbases,order,dhl)

  return feomat.create(&res)

#-----------------------------------------------------------------------------------------------------






#*****************************************************************************************************
cpdef feomat zeros( uint64_t nrows, uint64_t ncols, bases_t nbases=0, ord_t order=0):
  
  global dhl

  cdef feoarr_t res = feoarr_zeros(nrows,ncols,nbases,order,dhl)

  return feomat.create(&res)

#-----------------------------------------------------------------------------------------------------




#*****************************************************************************************************
cpdef feomat ones(uint64_t nrows,uint64_t ncols, bases_t nbases=0, ord_t order=0):
  
  global dhl

  cdef feoarr_t res = feoarr_ones(nrows,ncols,nbases,order,dhl)

  return feomat.create(&res)
  
#-----------------------------------------------------------------------------------------------------






