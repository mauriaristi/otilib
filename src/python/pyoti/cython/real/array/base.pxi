# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::     CLASS  DMAT    ::::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
cdef class dmat:
  #---------------------------------------------------------------------------------------------------
  #------------------------------------   DEFINITION OF ATTRIBUTES   ---------------------------------
  #---------------------------------------------------------------------------------------------------
  
  #                                --->      Look in real.pxd    <---

  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  # not _cinit_ to avoid creation with _new_
  def __init__(self, nrows, ncols, uint8_t FLAGS = 1): 
    """
    PURPOSE:      Python level constructor of the dmat class.

    DESCRIPTION:  Creates a new matrix.
                 
    """
    #*************************************************************************************************

    cdef uint64_t sizeOfCoefs, newSizeOfCoefs, i, j, ordi
    
    self.FLAGS = FLAGS

    self.arr = darr_createEmpty( nrows, ncols )

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  def __dealloc__(self): 
    """
    PURPOSE:      Destructor of the class. 

    DESCRIPTION:  Frees all memory.
                  
    """
    #*************************************************************************************************
    
    if self.FLAGS & 1: # If memory is owned by this class.
      
      darr_free(&self.arr)

    #end if 
    
  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  @property
  def order(self): 
    """
    PURPOSE:      Return the OTI imaginary order of the array.
    """
    #*************************************************************************************************

    return 0

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
  def nrows(self): 
    """
    PURPOSE:      Return the number of rows of the stored matrix. 
    """
    #*************************************************************************************************

    return self.arr.nrows

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  @property
  def ncols(self): 
    """
    PURPOSE:      Return the number of columns of the stored matrix. 
    """
    #*************************************************************************************************

    return self.arr.ncols

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
        tmp[i,j] = self.arr.p_data[k]
      # end for 
    # end for 

    return tmp

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  @staticmethod
  cdef dmat create(darr_t* arr, uint8_t FLAGS = 1):
    """
    PURPOSE:      C-level constructor of the class. Use this when creating objects within 
                  Cython
                  
    """
    #*************************************************************************************************

    # create new empty object:
    cdef dmat mat = <dmat> dmat.__new__(dmat)

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
    
    # head =  "dmat("
    # body =  "size: "+str(self.arr.size)  +  ", "
    # body += "nrows: "+str(self.arr.nrows)+  ", "
    # body += 'ncols: '+str(self.arr.ncols)
    # tail =  ")"
    # return (head + body + tail)

    cdef np.ndarray[double, ndim=2] A = self.to_numpy()

    return repr(A)

  #--------------------------------------------------------------------------------------------------- 

  #***************************************************************************************************
  def __str__(self):
    """
    PURPOSE:      Create a string representation of the object.    
    """
    #*************************************************************************************************
    
    # cdef uint64_t i,j,k=0

    # # dmat_print_fmt = 
    # head      = ''
    # body      = '['
    # for i in range(self.arr.nrows):

    #   body += '['

    #   for j in range(self.arr.ncols):

    #     body += "{:10.4f},".format(self.arr.p_data[k])
    #     k += 1 

    #   # end for

    #   body += '\b]\n '

    # # end for 
    # body = body[:len(body)-2]
    # body += ']\n'

    # tail      = ''
    
    # return (head + body + tail)

    cdef np.ndarray[double, ndim=2] A = self.to_numpy()

    return str(A)

  #---------------------------------------------------------------------------------------------------  



  #***************************************************************************************************
  def __getitem__(self, val):
    """
    PURPOSE: Get the value of an element of the item.
    """
    #*************************************************************************************************
    
    cdef coeff_t rres
    cdef darr_t  Rres
    cdef object  res = None
    cdef int64_t starti, stopi, stepi
    cdef int64_t startj, stopj, stepj

    tval = type(val)
    
    if tval == int:
      
      # This is a slice
      if val < self.arr.nrows:
        
        starti, stopi, stepi = slice( val, val+1, None).indices( self.arr.nrows )
        startj, stopj, stepj = slice(None, None, None).indices( self.arr.ncols )

        Ores = darr_get_slice( &self.arr, starti, stopi, stepi, startj, stopj, stepj)
        res  = dmat.create(&Ores)

      else:
        raise IndexError("Index out of bounds.")
      # end if 

    elif tval == slice: #slice of multiple items
      
      # This is a slice
      starti, stopi, stepi = val.indices( self.arr.nrows )
      startj, stopj, stepj = slice(None, None, None).indices( self.arr.ncols )

      Ores = darr_get_slice( &self.arr, starti, stopi, stepi, startj, stopj, stepj)
      res  = dmat.create(&Ores)
    
    elif tval == tuple:
      
      if len(val) == 2:

        tval0 = type(val[0])
        tval1 = type(val[1])

        if   tval0 == int and tval1 == int:
          
          # print("Case 1")
          if val[0] < self.arr.nrows and val[1] < self.arr.ncols:
          
            ores = darr_get_item_ij( &self.arr, val[0], val[1])
            res = ores
          
          else:
            raise IndexError("Index out of bounds.")
          # end if 

        elif tval0 == int and tval1 == slice:

          # print("Case 2")
          if val[0] < self.arr.nrows:

            starti, stopi, stepi = slice(val[0], val[0]+1, None).indices( self.arr.nrows )
            startj, stopj, stepj = val[1].indices( self.arr.ncols )

            Ores = darr_get_slice( &self.arr, starti, stopi, stepi, startj, stopj, stepj)
            res  = dmat.create(&Ores)  

          else:
            raise IndexError("Index out of bounds.")
          # end if 

        elif tval0 == slice and tval1 == int:

          # print("Case 3")
          if val[1] < self.arr.ncols:

            starti, stopi, stepi = val[0].indices( self.arr.nrows )
            startj, stopj, stepj = slice(val[1], val[1]+1, None).indices( self.arr.ncols )

            Ores = darr_get_slice( &self.arr, starti, stopi, stepi, startj, stopj, stepj)
            res  = dmat.create(&Ores)  

          else:
            raise IndexError("Index out of bounds.")
          # end if 


        elif tval0 == slice and tval1 == slice:

          # print("Case 3")
          starti, stopi, stepi = val[0].indices( self.arr.nrows )
          startj, stopj, stepj = val[1].indices( self.arr.ncols )

          Ores = darr_get_slice( &self.arr, starti, stopi, stepi, startj, stopj, stepj)
          res  = dmat.create(&Ores) 

        else:
          raise IndexError("ERROR: double index ( , ) only integers, slices (`:`) are valid indices")
        # end if 

      else:
        raise IndexError("ERROR: Getting integration points by index is not yet supported.")
      # end if 

    else:
      raise IndexError("ERROR: only integers, slices (`:`) are valid indices")
    # end if

    return res

  #---------------------------------------------------------------------------------------------------  

  #***************************************************************************************************
  def __setitem__(self, val, value):
    """
    PURPOSE: Set an element of the item to the specified value.
    """
    #*************************************************************************************************
    
    tvalue = type(value)

    if ( tvalue == dmat ):

      self.__setitem__R( val, value )

    elif ( tvalue in number_types ):

      self.__setitem__r( val, value )

    else:

      raise IndexError("ERROR: Cant set item of type {0} in matso object.".format(tvalue))

    # end if 


  #---------------------------------------------------------------------------------------------------  

  #***************************************************************************************************
  cdef __setitem__r(self, object val, coeff_t value):
    """
    PURPOSE: Set item from real value.
    """
    #*************************************************************************************************

    tval = type(val)

    if tval == int:
      
      # This is a slice
      if val < self.arr.nrows:
        
        starti, stopi, stepi = slice( val, val+1, None).indices( self.arr.nrows )
        startj, stopj, stepj = slice(None, None, None).indices( self.arr.ncols )

        darr_set_slice_r( value, starti, stopi, stepi, startj, stopj, stepj, &self.arr)
        
      else:
        raise IndexError("Index out of bounds.")
      # end if 

    elif tval == slice: #slice of multiple items
      
      # This is a slice
      starti, stopi, stepi = val.indices( self.arr.nrows )
      startj, stopj, stepj = slice(None, None, None).indices( self.arr.ncols )

      darr_set_slice_r( value, starti, stopi, stepi, startj, stopj, stepj, &self.arr)
    
    elif tval == tuple:
      
      if len(val) == 2:

        tval0 = type(val[0])
        tval1 = type(val[1])

        if ( tval0 == int and tval1 == int ):
          
          if val[0] < self.arr.nrows and val[1] < self.arr.ncols:
          
            darr_set_item_ij_r( value, val[0], val[1], &self.arr)
            
          else:
            raise IndexError("Index out of bounds.")
          # end if 

        elif (tval0 == int and tval1 == slice):

          if val[0] < self.arr.nrows:

            starti, stopi, stepi = slice(val[0], val[0]+1, None).indices( self.arr.nrows )
            startj, stopj, stepj = val[1].indices( self.arr.ncols )

            darr_set_slice_r( value, starti, stopi, stepi, startj, stopj, stepj, &self.arr)

          else:
            raise IndexError("Index out of bounds.")
          # end if 

        elif (tval0 == slice and tval1 == int):

          if val[1] < self.arr.ncols:

            starti, stopi, stepi = val[0].indices( self.arr.nrows )
            startj, stopj, stepj = slice(val[1], val[1]+1, None).indices( self.arr.ncols )

            darr_set_slice_r(value, starti, stopi, stepi, startj, stopj, stepj, &self.arr)

          else:
            raise IndexError("Index out of bounds.")
          # end if 

        elif (tval0 == slice and tval1 == slice):

          starti, stopi, stepi = val[0].indices( self.arr.nrows )
          startj, stopj, stepj = val[1].indices( self.arr.ncols )

          darr_set_slice_r( value, starti, stopi, stepi, startj, stopj, stepj, &self.arr)

        else:
          raise IndexError("ERROR: double index ( , ) only integers, slices (`:`) are valid indices")
        # end if 

      else:
        raise IndexError("ERROR: Getting integration points by index is not yet supported.")
      # end if 

    else:
      raise IndexError("ERROR: only integers, slices (`:`) are valid indices")
    # end if

  #---------------------------------------------------------------------------------------------------

  

  #***************************************************************************************************
  cdef __setitem__R(self,  object val, dmat value):
    """
    PURPOSE: Set item from real array.
    """
    #*************************************************************************************************

    tval = type(val)

    if tval == int:
      
      # This is a slice
      if val < self.arr.nrows:
        
        starti, stopi, stepi = slice( val, val+1, None).indices( self.arr.nrows )
        startj, stopj, stepj = slice(None, None, None).indices( self.arr.ncols )

        darr_set_slice_R( &value.arr, starti, stopi, stepi, startj, stopj, stepj, &self.arr)
        
      else:

        raise IndexError("Index out of bounds.")

      # end if 

    elif tval == slice: #slice of multiple items
      
      # This is a slice
      starti, stopi, stepi = val.indices( self.arr.nrows )
      startj, stopj, stepj = slice(None, None, None).indices( self.arr.ncols )

      darr_set_slice_R( &value.arr, starti, stopi, stepi, startj, stopj, stepj, &self.arr)
    
    elif tval == tuple:
      
      if len(val) == 2:

        tval0 = type(val[0])
        tval1 = type(val[1])

        if ( tval0 == int and tval1 == int ):
          
          if val[0] < self.arr.nrows and val[1] < self.arr.ncols:
          
            starti, stopi, stepi = slice(val[0], val[0]+1, None).indices( self.arr.nrows )
            startj, stopj, stepj = slice(val[1], val[1]+1, None).indices( self.arr.ncols )

            darr_set_slice_R( &value.arr, starti, stopi, stepi, startj, stopj, stepj, &self.arr)
            
          else:

            raise IndexError("Index out of bounds.")

          # end if 

        elif (tval0 == int and tval1 == slice):

          if val[0] < self.arr.nrows:

            starti, stopi, stepi = slice(val[0], val[0]+1, None).indices( self.arr.nrows )
            startj, stopj, stepj = val[1].indices( self.arr.ncols )

            darr_set_slice_R( &value.arr, starti, stopi, stepi, startj, stopj, stepj, &self.arr)

          else:
            raise IndexError("Index out of bounds.")
          # end if 

        elif (tval0 == slice and tval1 == int):

          if val[1] < self.arr.ncols:

            starti, stopi, stepi = val[0].indices( self.arr.nrows )
            startj, stopj, stepj = slice(val[1], val[1]+1, None).indices( self.arr.ncols )

            darr_set_slice_R( &value.arr, starti, stopi, stepi, startj, stopj, stepj, &self.arr)

          else:
            raise IndexError("Index out of bounds.")
          # end if 

        elif (tval0 == slice and tval1 == slice):

          starti, stopi, stepi = val[0].indices( self.arr.nrows )
          startj, stopj, stepj = val[1].indices( self.arr.ncols )

          darr_set_slice_R( &value.arr, starti, stopi, stepi, startj, stopj, stepj, &self.arr)

        else:
          raise IndexError("ERROR: double index ( , ) only integers, slices (`:`) are valid indices")
        # end if 

      else:
        raise IndexError("ERROR: Getting integration points by index is not yet supported.")
      # end if 

    else:
      raise IndexError("ERROR: only integers, slices (`:`) are valid indices")
    # end if

  #---------------------------------------------------------------------------------------------------



  #***************************************************************************************************
  def __neg__(self):
    """
    PURPOSE: Negation overload.
    """
    #*************************************************************************************************
    
    cdef darr_t newmat = darr_neg(&self.arr)

    return dmat.create(&newmat)
  #---------------------------------------------------------------------------------------------------




  #***************************************************************************************************
  def __add__(self, other):
    """
    PURPOSE: Addition overload.
    """
    #*************************************************************************************************
    
    cdef darr_t res 
    cdef dmat lhs,rhs
    
    tlhs = type(self)
    trhs = type(other)
    
    if (tlhs == trhs):

      lhs = self
      rhs = other

      res = darr_sum_RR(&lhs.arr,&rhs.arr)
    
    elif (tlhs in number_types):
      
      rhs = other
      res = darr_sum_rR(self, &rhs.arr)

    elif (trhs in number_types):
        
      lhs = self
      res = darr_sum_rR(other, &lhs.arr)

    else:

      return NotImplemented

    # end if 
      
    return dmat.create(&res)

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
    
    cdef darr_t res 
    cdef dmat lhs,rhs
    
    tlhs = type(self)
    trhs = type(other)
    
    if (tlhs == trhs):

      lhs = self
      rhs = other

      res = darr_sub_RR(&lhs.arr,&rhs.arr)
    
    elif (tlhs in number_types):
      
      rhs = other
      res = darr_sub_rR(self, &rhs.arr)

    elif (trhs in number_types):
        
      lhs = self
      res = darr_sub_Rr( &lhs.arr, other)

    else:

      return NotImplemented

    # end if 
      
    return dmat.create(&res)

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
    
    cdef darr_t res 
    cdef dmat lhs,rhs
    
    tlhs = type(self)
    trhs = type(other)
    
    if (tlhs == trhs):

      lhs = self
      rhs = other

      res = darr_mul_RR(&lhs.arr,&rhs.arr)
    
    elif (tlhs in number_types):
      
      rhs = other
      res = darr_mul_rR(self, &rhs.arr)

    elif (trhs in number_types):
        
      lhs = self
      res = darr_mul_rR(other, &lhs.arr)

    else:

      return NotImplemented

    # end if 
      
    return dmat.create(&res)
    

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
    
    cdef darr_t res 
    cdef dmat lhs,rhs
    
    tlhs = type(self)
    trhs = type(other)
    
    if (tlhs == trhs):

      lhs = self
      rhs = other

      res = darr_div_RR(&lhs.arr,&rhs.arr)
    
    elif (tlhs in number_types):
      
      rhs = other
      res = darr_div_rR(self, &rhs.arr)

    elif (trhs in number_types):
        
      lhs = self
      res = darr_div_Rr( &lhs.arr, other)

    else:

      return NotImplemented

    # end if 
      
    return dmat.create(&res)


  #---------------------------------------------------------------------------------------------------  

  #***************************************************************************************************
  cpdef np.ndarray[double, ndim=2] to_numpy(self):
    """
    PURPOSE: Interface to numpy representation.
    """
    #*************************************************************************************************

    return c_ptr_to_np_2darray_double(self.arr.p_data, self.arr.nrows, self.arr.ncols)

  #---------------------------------------------------------------------------------------------------    

  #***************************************************************************************************
  def __pow__(self, n,z):
    """
    PURPOSE: Power function.
    """
    #*************************************************************************************************

    return pow(self,n)

  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  cpdef copy(self):
    """
    PURPOSE: Copy the elements to new memory spaces.
    """
    #*************************************************************************************************
    
    cdef darr_t res = darr_copy(&self.arr)    
      
    return dmat.create(&res)

  #---------------------------------------------------------------------------------------------------  

  #***************************************************************************************************
  cpdef set(self, coeff_t val):
    """
    PURPOSE: Set all elements to val.
    """
    #*************************************************************************************************
    
    darr_set_all_r(val,&self.arr)

  #--------------------------------------------------------------------------------------------------- 


# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# :::::::::::::::::::::::::::::::::::: END OF CLASS DMAT :::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::




