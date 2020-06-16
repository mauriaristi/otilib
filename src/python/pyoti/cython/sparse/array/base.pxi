






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
    PURPOSE:      Python level constructor of the matso class.

    DESCRIPTION:  Creates a new matrix, reserving memory Assumes coefficient values to be all zeroes.
                 
    """
    #*************************************************************************************************
    global dhl
    
    cdef uint64_t nrows, ncols, i,j
    cdef ord_t ordi
    cdef coeff_t val 


    if isinstance( realArray, np.ndarray):
      
      ndim = realArray.ndim
      
      if ( ndim >= 3 ):
      
        raise ValueError("Only 1D and 2D arrays are supported.")
      
      elif ( ndim == 1 ):
      
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
    # end if 
    
    self.FLAGS = 1

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  def __dealloc__(self): 
    """
    PURPOSE:      Destructor of the class.                   
    """
    #*************************************************************************************************
    
    if self.FLAGS != 0:
      
      arrso_free(&self.arr)

    # end if 
    
  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  @property
  def T(self): 
    """
    PURPOSE:      Return the transpose of the stored matrix. 
    """
    #*************************************************************************************************
    global dhl
    
    cdef arrso_t res 
      
    res = arrso_transpose( &self.arr,  dhl)

    return matso.create(&res)

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
  def order(self): 
    """
    PURPOSE:      Return the shape of the stored matrix. 
    """
    #*************************************************************************************************

    return arrso_get_order(&self.arr)

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
  cdef matso create(arrso_t* arr, uint8_t FLAGS = 1):
    """
    PURPOSE:      C-level constructor of the class. Use this when creating objects within 
                  Cython
                  
    """
    #*************************************************************************************************

    # create new empty object:
    cdef matso mat = <matso> matso.__new__(matso)

    mat.arr = arr[0]
    mat.FLAGS = FLAGS
    
    return mat

  #--------------------------------------------------------------------------------------------------- 

  #*************************************************************************************************** 
  def short_repr(self):
    """
    PURPOSE:      A short representation of the object.
  
    """
    #*************************************************************************************************

    global dhl

    out =  "matso< "
    out += "shape: "+str(self.shape)+ ", "
    out += "re:\n"
    # first print the real part:
    out += repr( self.real )

    out += ">"

    return out

  #--------------------------------------------------------------------------------------------------- 

  #*************************************************************************************************** 
  def long_repr(self):
    """
    PURPOSE:      A short representation of the object.
  
    """
    #*************************************************************************************************

    global dhl

    cdef np.ndarray[uint64_t, ndim=1] tmp 

    out =  "matso< "
    out += "shape: "+str(self.shape)+ ", "
    out += "re:\n"
    # first print the real part:
    out += repr( self.real )

    out += ">"

    return out

  #---------------------------------------------------------------------------------------------------

  #*************************************************************************************************** 
  def list_repr(self):
    """
    PURPOSE:      A short representation of the object.
  
    """
    #*************************************************************************************************

    global dhl

    cdef uint64_t i,j 
    cdef sotinum tmp


    out =  "matso< "
    out += "shape: "+str(self.shape)+ ", \n"

    for j in range(self.arr.ncols):
      out += " - Column " + str(j) +"\n"
      for i in range(self.arr.nrows):

        out += "({0:d},{1:d}) ".format(i,j)
         
        out += self[i,j].__str__()
        out += "\n"

      # end for 
    # end for 

    out += ">"

    return out

  #---------------------------------------------------------------------------------------------------

  #*************************************************************************************************** 
  def __repr__(self):
    """
    PURPOSE:      Representation of the object.
  
    """
    #*************************************************************************************************

    global dhl
  
    cdef sotinum_t d_soti
    cdef sotinum   soti
    
    out  = self.list_repr()
    # out=""

    # out += "["
    # for i in range(self.arr.nrows):
    #   out += "["
    #   for j in range(self.arr.ncols):
    #     d_soti = arrso_get_item_ij(&self.arr, i, j, dhl)
    #     out+= (sotinum.create(&d_soti,FLAGS=0)).__str__()+", "
    #   # end for 
    #   out = out[:-2] + "],\n"
    # # end for 
    # out =out[:-2] + "]"
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

    out  = self.list_repr()

    # out += "["
    # for i in range(self.arr.nrows):
    #   out += "["
    #   for j in range(self.arr.ncols):
    #     d_soti = arrso_get_item_ij(&self.arr, i, j, dhl)
    #     out+= (sotinum.create(&d_soti,FLAGS=0)).__str__()+", "
    #   # end for 
    #   out = out[:-2] + "],\n"
    # # end for 
    # out =out[:-2] + "]"
    return out

  #---------------------------------------------------------------------------------------------------  



  #***************************************************************************************************
  def  __getitem__(self, val):
    """
    PURPOSE: Get the value of an element of the item.
    """
    #*************************************************************************************************
    
    global dhl

    cdef sotinum_t ores
    cdef arrso_t   Ores
    cdef object res = None
    cdef int64_t starti, stopi, stepi
    cdef int64_t startj, stopj, stepj

    tval = type(val)
    
    if tval == int:
      
      # This is a slice
      if val < self.arr.nrows:
        
        starti, stopi, stepi = slice( val, val+1, None).indices( self.arr.nrows )
        startj, stopj, stepj = slice(None, None, None).indices( self.arr.ncols )

        Ores = arrso_get_slice( &self.arr, starti, stopi, stepi, startj, stopj, stepj, dhl)
        res  = matso.create(&Ores)

      else:

        raise IndexError("Index out of bounds.")

      # end if 

    #   ores = arrso_get_item_ij( &self.arr, val[0], val[1], dhl)
    #   res  = sotinum.create( &ores, FLAGS = 0 )

    elif tval == slice: #slice of multiple items
      
      # print(val)
      # This is a slice
      starti, stopi, stepi = val.indices( self.arr.nrows )
      startj, stopj, stepj = slice(None, None, None).indices( self.arr.ncols )

      # print("i: ( {0}, {1}, {2})".format(starti, stopi, stepi) )
      # print("j: ( {0}, {1}, {2})".format(startj, stopj, stepj) )

      Ores = arrso_get_slice( &self.arr, starti, stopi, stepi, startj, stopj, stepj, dhl)
      res  = matso.create(&Ores)
    
    elif tval == tuple:
      
      if len(val) == 2:

        tval0 = type(val[0])
        tval1 = type(val[1])

        if   tval0 == int and tval1 == int:
          
          # print("Case 1")
          if val[0] < self.arr.nrows and val[1] < self.arr.ncols:
          
            ores = arrso_get_item_ij( &self.arr, val[0], val[1], dhl)
            res = sotinum.create(&ores, FLAGS = 0)        
          
          else:

            raise IndexError("Index out of bounds.")

          # end if 

        elif tval0 == int and tval1 == slice:

          # print("Case 2")
          if val[0] < self.arr.nrows:

            starti, stopi, stepi = slice(val[0], val[0]+1, None).indices( self.arr.nrows )
            startj, stopj, stepj = val[1].indices( self.arr.ncols )

            Ores = arrso_get_slice( &self.arr, starti, stopi, stepi, startj, stopj, stepj, dhl)
            res  = matso.create(&Ores)  

          else:

            raise IndexError("Index out of bounds.")

          # end if 

        elif tval0 == slice and tval1 == int:

          # print("Case 3")
          if val[1] < self.arr.ncols:

            starti, stopi, stepi = val[0].indices( self.arr.nrows )
            startj, stopj, stepj = slice(val[1], val[1]+1, None).indices( self.arr.ncols )

            Ores = arrso_get_slice( &self.arr, starti, stopi, stepi, startj, stopj, stepj, dhl)
            res  = matso.create(&Ores)  

          else:

            raise IndexError("Index out of bounds.")

          # end if 


        elif tval0 == slice and tval1 == slice:

          # print("Case 3")
          starti, stopi, stepi = val[0].indices( self.arr.nrows )
          startj, stopj, stepj = val[1].indices( self.arr.ncols )

          Ores = arrso_get_slice( &self.arr, starti, stopi, stepi, startj, stopj, stepj, dhl)
          res  = matso.create(&Ores) 

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
        
    global dhl

    tvalue = type(value)

    if ( tvalue == sotinum ):

      self.__setitem__o( val, value )

    elif ( tvalue == matso ):

      self.__setitem__O( val, value )

    elif ( tvalue == dmat ):

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
    global dhl

    tval = type(val)

    if tval == int:
      
      # This is a slice
      if val < self.arr.nrows:
        
        starti, stopi, stepi = slice( val, val+1, None).indices( self.arr.nrows )
        startj, stopj, stepj = slice(None, None, None).indices( self.arr.ncols )

        arrso_set_slice_r( value, starti, stopi, stepi, startj, stopj, stepj, &self.arr, dhl)
        
      else:

        raise IndexError("Index out of bounds.")

      # end if 

    elif tval == slice: #slice of multiple items
      
      # This is a slice
      starti, stopi, stepi = val.indices( self.arr.nrows )
      startj, stopj, stepj = slice(None, None, None).indices( self.arr.ncols )

      arrso_set_slice_r( value, starti, stopi, stepi, startj, stopj, stepj, &self.arr, dhl)
    
    elif tval == tuple:
      
      if len(val) == 2:

        tval0 = type(val[0])
        tval1 = type(val[1])

        if ( tval0 == int and tval1 == int ):
          
          if val[0] < self.arr.nrows and val[1] < self.arr.ncols:
          
            arrso_set_item_ij_r( value, val[0], val[1], &self.arr, dhl)
            
          else:

            raise IndexError("Index out of bounds.")

          # end if 

        elif (tval0 == int and tval1 == slice):

          if val[0] < self.arr.nrows:

            starti, stopi, stepi = slice(val[0], val[0]+1, None).indices( self.arr.nrows )
            startj, stopj, stepj = val[1].indices( self.arr.ncols )

            arrso_set_slice_r( value, starti, stopi, stepi, startj, stopj, stepj, &self.arr, dhl)

          else:

            raise IndexError("Index out of bounds.")

          # end if 

        elif (tval0 == slice and tval1 == int):

          if val[1] < self.arr.ncols:

            starti, stopi, stepi = val[0].indices( self.arr.nrows )
            startj, stopj, stepj = slice(val[1], val[1]+1, None).indices( self.arr.ncols )

            arrso_set_slice_r(value, starti, stopi, stepi, startj, stopj, stepj, &self.arr, dhl)

          else:

            raise IndexError("Index out of bounds.")

          # end if 

        elif (tval0 == slice and tval1 == slice):

          starti, stopi, stepi = val[0].indices( self.arr.nrows )
          startj, stopj, stepj = val[1].indices( self.arr.ncols )

          arrso_set_slice_r( value, starti, stopi, stepi, startj, stopj, stepj, &self.arr, dhl)

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
  cdef __setitem__o(self,  object val, sotinum value):
    """
    PURPOSE: Set item from sotinum value.
    """
    #*************************************************************************************************
    global dhl

    tval = type(val)

    if tval == int:
      
      # This is a slice
      if val < self.arr.nrows:
        
        starti, stopi, stepi = slice( val, val+1, None).indices( self.arr.nrows )
        startj, stopj, stepj = slice(None, None, None).indices( self.arr.ncols )

        arrso_set_slice_o( &value.num, starti, stopi, stepi, startj, stopj, stepj, &self.arr, dhl)
        
      else:

        raise IndexError("Index out of bounds.")

      # end if 

    elif tval == slice: #slice of multiple items
      
      # This is a slice
      starti, stopi, stepi = val.indices( self.arr.nrows )
      startj, stopj, stepj = slice(None, None, None).indices( self.arr.ncols )

      arrso_set_slice_o( &value.num, starti, stopi, stepi, startj, stopj, stepj, &self.arr, dhl)
    
    elif tval == tuple:
      
      if len(val) == 2:

        tval0 = type(val[0])
        tval1 = type(val[1])

        if ( tval0 == int and tval1 == int ):
          
          if val[0] < self.arr.nrows and val[1] < self.arr.ncols:
          
            arrso_set_item_ij_o( &value.num, val[0], val[1], &self.arr, dhl)
            
          else:

            raise IndexError("Index out of bounds.")

          # end if 

        elif (tval0 == int and tval1 == slice):

          if val[0] < self.arr.nrows:

            starti, stopi, stepi = slice(val[0], val[0]+1, None).indices( self.arr.nrows )
            startj, stopj, stepj = val[1].indices( self.arr.ncols )

            arrso_set_slice_o( &value.num, starti, stopi, stepi, startj, stopj, stepj, &self.arr, dhl)

          else:

            raise IndexError("Index out of bounds.")

          # end if 

        elif (tval0 == slice and tval1 == int):

          if val[1] < self.arr.ncols:

            starti, stopi, stepi = val[0].indices( self.arr.nrows )
            startj, stopj, stepj = slice(val[1], val[1]+1, None).indices( self.arr.ncols )

            arrso_set_slice_o( &value.num, starti, stopi, stepi, startj, stopj, stepj, &self.arr, dhl)

          else:

            raise IndexError("Index out of bounds.")

          # end if 

        elif (tval0 == slice and tval1 == slice):

          starti, stopi, stepi = val[0].indices( self.arr.nrows )
          startj, stopj, stepj = val[1].indices( self.arr.ncols )

          arrso_set_slice_o( &value.num, starti, stopi, stepi, startj, stopj, stepj, &self.arr, dhl)

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
    global dhl

    raise NotImplementedError("Error Setting from Real array not yet supported.")
  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  cdef __setitem__O(self,  object val, matso value):
    """
    PURPOSE: Set item from OTI array.
    """
    #*************************************************************************************************
    global dhl

    tval = type(val)

    if tval == int:
      
      # This is a slice
      if val < self.arr.nrows:
        
        starti, stopi, stepi = slice( val, val+1, None).indices( self.arr.nrows )
        startj, stopj, stepj = slice(None, None, None).indices( self.arr.ncols )

        arrso_set_slice_O( &value.arr, starti, stopi, stepi, startj, stopj, stepj, &self.arr, dhl)
        
      else:

        raise IndexError("Index out of bounds.")

      # end if 

    elif tval == slice: #slice of multiple items
      
      # This is a slice
      starti, stopi, stepi = val.indices( self.arr.nrows )
      startj, stopj, stepj = slice(None, None, None).indices( self.arr.ncols )

      arrso_set_slice_O( &value.arr, starti, stopi, stepi, startj, stopj, stepj, &self.arr, dhl)
    
    elif tval == tuple:
      
      if len(val) == 2:

        tval0 = type(val[0])
        tval1 = type(val[1])

        if ( tval0 == int and tval1 == int ):
          
          if val[0] < self.arr.nrows and val[1] < self.arr.ncols:
          
            starti, stopi, stepi = slice(val[0], val[0]+1, None).indices( self.arr.nrows )
            startj, stopj, stepj = slice(val[1], val[1]+1, None).indices( self.arr.ncols )

            arrso_set_slice_O( &value.arr, starti, stopi, stepi, startj, stopj, stepj, &self.arr, dhl)
            
          else:

            raise IndexError("Index out of bounds.")

          # end if 

        elif (tval0 == int and tval1 == slice):

          if val[0] < self.arr.nrows:

            starti, stopi, stepi = slice(val[0], val[0]+1, None).indices( self.arr.nrows )
            startj, stopj, stepj = val[1].indices( self.arr.ncols )

            arrso_set_slice_O( &value.arr, starti, stopi, stepi, startj, stopj, stepj, &self.arr, dhl)

          else:

            raise IndexError("Index out of bounds.")

          # end if 

        elif (tval0 == slice and tval1 == int):

          if val[1] < self.arr.ncols:

            starti, stopi, stepi = val[0].indices( self.arr.nrows )
            startj, stopj, stepj = slice(val[1], val[1]+1, None).indices( self.arr.ncols )

            arrso_set_slice_O( &value.arr, starti, stopi, stepi, startj, stopj, stepj, &self.arr, dhl)

          else:

            raise IndexError("Index out of bounds.")

          # end if 

        elif (tval0 == slice and tval1 == slice):

          starti, stopi, stepi = val[0].indices( self.arr.nrows )
          startj, stopj, stepj = val[1].indices( self.arr.ncols )

          arrso_set_slice_O( &value.arr, starti, stopi, stepi, startj, stopj, stepj, &self.arr, dhl)

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
  def copy(self):
    """
    PURPOSE: Copy to a new object.
    """
    #*************************************************************************************************
    
    global dhl
    
    cdef arrso_t res = arrso_copy(&self.arr, dhl)

    return matso.create(&res)
  #---------------------------------------------------------------------------------------------------


  #***************************************************************************************************
  def __neg__(self):
    """
    PURPOSE: Negation overload.
    """
    #*************************************************************************************************
    
    global dhl
    
    cdef arrso_t res = arrso_neg(&self.arr, dhl)

    return matso.create(&res)
  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  def __add__(self, other):
    """
    PURPOSE: Addition overload.
    """
    #*************************************************************************************************
    
    global dhl
    
    cdef arrso_t res 
    cdef matso lhs,rhs
    cdef dmat dlhs,drhs
    cdef sotinum olhs,orhs
    
    tlhs = type(self)
    trhs = type(other)
    
    if (tlhs == trhs):

      lhs = self
      rhs = other

      res = arrso_sum_OO(&lhs.arr,&rhs.arr,dhl)

    elif ( tlhs  == sotinum ):

      olhs = self
      rhs = other

      res = arrso_sum_oO(&olhs.num,&rhs.arr, dhl)

    elif ( trhs  == sotinum ):

      lhs = self
      orhs = other

      res = arrso_sum_oO(&orhs.num,&lhs.arr, dhl)
    
    elif (tlhs in number_types):
      
      rhs = other
      res = arrso_sum_rO(self, &rhs.arr, dhl)

    elif (trhs in number_types):
        
      lhs = self
      res = arrso_sum_rO(other, &lhs.arr, dhl)

    elif ( tlhs  == dmat ):

      dlhs = self
      rhs = other

      res = arrso_sum_RO(&dlhs.arr,&rhs.arr, dhl)

    elif ( trhs  == dmat ):

      lhs = self
      drhs = other

      res = arrso_sum_RO(&drhs.arr,&lhs.arr, dhl)

    else:

      return NotImplemented

    # end if 
      
    return matso.create(&res)

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
    
    cdef arrso_t res 
    cdef matso lhs,rhs
    cdef dmat dlhs,drhs
    cdef sotinum olhs,orhs
    
    tlhs = type(self)
    trhs = type(other)
    
    if (tlhs == trhs):

      lhs = self
      rhs = other

      res = arrso_sub_OO(&lhs.arr,&rhs.arr,dhl)

    elif ( tlhs  == sotinum ):

      olhs = self
      rhs = other

      res = arrso_sub_oO(&olhs.num,&rhs.arr, dhl)

    elif ( trhs  == sotinum ):

      lhs = self
      orhs = other

      res = arrso_sub_Oo(&lhs.arr, &orhs.num, dhl)
    
    elif (tlhs in number_types):
      
      rhs = other
      res = arrso_sub_rO(self, &rhs.arr, dhl)

    elif (trhs in number_types):
        
      lhs = self
      res = arrso_sub_Or(&lhs.arr, other, dhl)

    elif ( tlhs  == dmat ):

      dlhs = self
      rhs = other

      res = arrso_sub_RO(&dlhs.arr,&rhs.arr, dhl)

    elif ( trhs  == dmat ):

      lhs = self
      drhs = other

      res = arrso_sub_OR(&lhs.arr, &drhs.arr, dhl)

    else:

      return NotImplemented      

    # end if 
      
    return matso.create(&res)

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
    
    cdef arrso_t res 
    cdef matso lhs,rhs
    cdef dmat dlhs,drhs
    cdef sotinum olhs,orhs
    
    tlhs = type(self)
    trhs = type(other)
    
    if (tlhs == trhs):

      lhs = self
      rhs = other

      res = arrso_mul_OO(&lhs.arr,&rhs.arr,dhl)

    elif ( tlhs  == sotinum ):

      olhs = self
      rhs = other

      res = arrso_mul_oO(&olhs.num,&rhs.arr, dhl)

    elif ( trhs  == sotinum ):

      lhs = self
      orhs = other

      res = arrso_mul_oO(&orhs.num,&lhs.arr, dhl)
    
    elif (tlhs in number_types):
      
      rhs = other
      res = arrso_mul_rO(self, &rhs.arr, dhl)

    elif (trhs in number_types):
        
      lhs = self
      res = arrso_mul_rO(other, &lhs.arr, dhl)

    elif ( tlhs  == dmat ):

      dlhs = self
      rhs = other

      res = arrso_mul_RO(&dlhs.arr,&rhs.arr, dhl)

    elif ( trhs  == dmat ):

      lhs = self
      drhs = other

      res = arrso_mul_RO(&drhs.arr,&lhs.arr, dhl)

    else:

      return NotImplemented      

    # end if 
      
    return matso.create(&res)

    

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
    
    cdef arrso_t res 
    cdef matso lhs,rhs
    cdef dmat dlhs,drhs
    cdef sotinum olhs,orhs
    
    tlhs = type(self)
    trhs = type(other)
    
    if (tlhs == trhs):

      lhs = self
      rhs = other

      res = arrso_div_OO(&lhs.arr,&rhs.arr,dhl)

    elif ( tlhs  == sotinum ):

      olhs = self
      rhs = other

      res = arrso_div_oO(&olhs.num,&rhs.arr, dhl)

    elif ( trhs  == sotinum ):

      lhs = self
      orhs = other

      res = arrso_div_Oo(&lhs.arr, &orhs.num, dhl)
    
    elif (tlhs in number_types):
      
      rhs = other
      res = arrso_div_rO(self, &rhs.arr, dhl)

    elif (trhs in number_types):
        
      lhs = self
      res = arrso_div_Or(&lhs.arr, other, dhl)

    elif ( tlhs  == dmat ):

      dlhs = self
      rhs = other

      res = arrso_div_RO(&dlhs.arr,&rhs.arr, dhl)

    elif ( trhs  == dmat ):

      lhs = self
      drhs = other

      res = arrso_div_OR(&lhs.arr, &drhs.arr, dhl)

    else:

      return NotImplemented      

    # end if 
      
    return matso.create(&res)

  #---------------------------------------------------------------------------------------------------  

  #***************************************************************************************************
  def __pow__(self, n,z):
    """
    PURPOSE:      Power function oversload
    """
    #*************************************************************************************************
    
    global dhl

    cdef arrso_t res 
    cdef matso S = self

    res = arrso_pow( &S.arr, n, dhl)
    
    return matso.create(&res)

  #---------------------------------------------------------------------------------------------------  

  #***************************************************************************************************
  cpdef get_deriv(self, object hum_dir ):
    """
    PURPOSE: Get the corresponding derivative of the system.
    """
    #*************************************************************************************************
    global dhl

    cdef list item = imdir(hum_dir)
    cdef np.ndarray[coeff_t, ndim=2] tmp
    cdef coeff_t factor = 1

    tmp = self.get_im(hum_dir)

    factor = dhelp_get_deriv_factor(item[ZERO], item[ONE], dhl)

    return tmp * factor

  #---------------------------------------------------------------------------------------------------  

  #***************************************************************************************************
  cpdef get_im(self, object hum_dir):
    """
    PURPOSE: Get the corresponding imaginary direction in the matso object.
    """
    #*************************************************************************************************
    global dhl
    
    cdef list item = imdir(hum_dir)
    cdef darr_t res_darr
    cdef dmat res_dmat
    cdef uint64_t i,j, k
    cdef np.ndarray[double, ndim=2] res

    res_darr = arrso_get_im( item[ZERO],  item[ONE], &self.arr,  dhl)

    res = np.empty( self.shape , dtype = np.float64)

    k=0

    for i in range(self.arr.nrows):

      for j in range(self.arr.ncols):

        res[i,j] = res_darr.p_data[k]
        k+=1

      # end for 

    #end for

    return res

  #---------------------------------------------------------------------------------------------------


  #***************************************************************************************************
  cpdef extract_im(self, object hum_dir):
    """
    PURPOSE: Get the corresponding imaginary direction in the matso object.
    """
    #*************************************************************************************************
    global dhl
    
    cdef list item = imdir(hum_dir)
    cdef arrso_t res
    

    res = arrso_extract_im( item[ZERO],  item[ONE], &self.arr,  dhl)

    return matso.create(&res)

  #---------------------------------------------------------------------------------------------------
  
  #***************************************************************************************************
  cpdef  extract_deriv(self, object hum_dir):
    """
    PURPOSE: Get the corresponding derivative in the matso object, as OTI number.
    """
    #*************************************************************************************************
    global dhl
    
    cdef list item = imdir(hum_dir)
    cdef arrso_t res
    
    res = arrso_extract_deriv( item[ZERO],  item[ONE], &self.arr,  dhl)

    return matso.create(&res)

  #---------------------------------------------------------------------------------------------------
  

  #***************************************************************************************************
  cpdef  get_order_im(self, ord_t order):
    """
    PURPOSE: Get the corresponding derivative in the matso object, as OTI number.
    """
    #*************************************************************************************************
    global dhl
    
    cdef arrso_t res
    
    res = arrso_get_order_im( order, &self.arr,  dhl)

    return matso.create(&res)

  #---------------------------------------------------------------------------------------------------
  

  #***************************************************************************************************
  cpdef  truncate( self, object humdir):
    """
    PURPOSE:      to set a specific imaginary direction as given.

    """
    #*************************************************************************************************
    global dhl

    cdef imdir_t indx
    cdef ord_t  order
    cdef arrso_t res
    
    indx, order = imdir(humdir)
    
    res = arrso_truncate_im( indx, order, &self.arr, dhl) 

    return matso.create(&res)

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  cpdef set(self, object rhs):
    """
    PURPOSE:  Sets from another value.
    """
    #*************************************************************************************************
    global dhl
    
    cdef sotinum orhs
    cdef coeff_t rrhs

    cdef matso Orhs
    trhs = type(rhs)

    if   trhs is sotinum:

      orhs = rhs
      arrso_set_o( &orhs.num, &self.arr, dhl)

    elif trhs is matso:

      Orhs = rhs
      arrso_set_O( &Orhs.arr, &self.arr, dhl)      

    elif trhs in number_types:

      rrhs = rhs
      arrso_set_r( rrhs, &self.arr, dhl)

    else:

      raise ValueError( "Cant assign '{0}' into a matso object.".format(trhs) )
      
    # end if 

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  def get_active_bases(self):
    """

    """
    global dhl

    cdef bases_t  size       = dhl.p_dh[0].Nbasis
    cdef imdir_t* bases_list = dhl.p_dh[0].p_idx[0]
    cdef uint64_t i
    
    # Initialize all elements as zero (deactivated)
    for i in range(size):

      bases_list[i]=0

    # end for 

    arrso_get_active_bases( &self.arr, bases_list, dhl)

    res = []
    for i in range(size):

      if bases_list[i]==1:
      
        res.append(i+1)

      # end if 

    # end for 

    return res

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  def taylor_integrate(self, object bases, object deltas):
    """
    PURPOSE:     Perform a Taylor series integration.
    """
    #*************************************************************************************************
    global dhl

    cdef bases_t  size     = dhl.p_dh[0].Nbasis
    cdef coeff_t* c_deltas = dhl.p_dh[0].p_im[0]
    cdef int64_t i
    cdef arrso_t res
    
    # Initialize all elements as zero
    memset( c_deltas, 0, size*sizeof(coeff_t))

    try:
      
      bases_eval  = bases
      deltas_eval = deltas

      if len(bases_eval) != len(deltas_eval):
      
        raise ValueError("Both bases and deltas must have the same dimension")

      # end if 

    except:

      bases_eval = np.array(self.get_active_bases(),dtype=np.uint16)
      deltas_eval= np.ones(len(bases_eval),dtype=np.float64) * deltas

    # end

    for i in range(len(bases_eval)):

      c_deltas[ bases[i] - 1 ] = deltas[i]

    # end for 

    res = arrso_taylor_integrate( c_deltas, &self.arr, dhl)

    return matso.create(&res)

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  @staticmethod
  def dot( matso lhs, matso rhs, matso out = None): 
    """
    PURPOSE: Matrix multiplication.
    """
    global dhl
    
    cdef arrso_t res 


    if out is not None:
      
      arrso_matmul_OO_to( &lhs.arr, &rhs.arr ,&out.arr, dhl)

    else:

      res = arrso_matmul_OO( &lhs.arr, &rhs.arr , dhl)

      return matso.create(&res)

    # end if 

  #---------------------------------------------------------------------------------------------------

  

  #***************************************************************************************************
  @staticmethod
  def inv( matso arr,  matso out = None): 
    """
    PURPOSE: Matrix invertion.
    """
    global dhl
    
    cdef arrso_t res 


    if out is not None:
      
      arrso_invert_to( &arr.arr,&out.arr, dhl)

    else:

      res = arrso_invert( &arr.arr, dhl)

      return matso.create(&res)

    # end if 

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  @staticmethod
  def transpose( matso arr,  matso out = None ): 
    """
    PURPOSE: Matrix transpose.
    """
    global dhl
    
    cdef arrso_t res 

    if out is not None:
      
      arrso_transpose_to( &arr.arr, &out.arr, dhl)

    else:

      res = arrso_transpose( &arr.arr,  dhl)

      return matso.create(&res)

    # end if 

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  @staticmethod
  def add( matso lhs, matso rhs, matso out = None): 
    """
    PURPOSE: Matrix elementwise addition.
    """
    global dhl
    
    cdef arrso_t res 


    if out is not None:
      
      arrso_sum_OO_to( &lhs.arr, &rhs.arr ,&out.arr, dhl)

    else:

      res = arrso_sum_OO( &lhs.arr, &rhs.arr , dhl)

      return matso.create(&res)

    # end if 

  #---------------------------------------------------------------------------------------------------
  


# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# :::::::::::::::::::::::::::::::::::: END OF CLASS matso ::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

