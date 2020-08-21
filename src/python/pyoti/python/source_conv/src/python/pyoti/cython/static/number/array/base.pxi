

# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::     CLASS  {arr_pytype}    ::::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
cdef class {arr_pytype}:
  #---------------------------------------------------------------------------------------------------
  #------------------------------------   DEFINITION OF ATTRIBUTES   ---------------------------------
  #---------------------------------------------------------------------------------------------------
  
  #                                --->      Look in dense.pxd    <---

  #---------------------------------------------------------------------------------------------------  

  #***************************************************************************************************
  
  def __init__(self, realArray): 
    """
    PURPOSE:      Python level constructor of the {arr_pytype} class.

    DESCRIPTION:  Creates a new matrix, reserving memory Assumes coefficient values to be all zeroes.
                 
    """
    #*************************************************************************************************
    
    
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

        self.arr = {arr_func}_zeros( nrows, ncols)

        for i in range(self.arr.nrows):
      
          val = realArray[i]
          {arr_func}_set_item_i_r( val, i, &self.arr)
        
        # end for
      
      else: # ndim =2

        nrows = realArray.shape[0]
        ncols = realArray.shape[1]
        self.arr = {arr_func}_zeros( nrows, ncols)

        for i in range(self.arr.nrows):      
          for j in range(self.arr.ncols):
            
            val = realArray[i,j]
            {arr_func}_set_item_ij_r( val, i, j, &self.arr)
          
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
      
      {arr_func}_free(&self.arr)

    # end if 
    
  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  @property
  def T(self): 
    """
    PURPOSE:      Return the transpose of the stored matrix. 
    """
    #*************************************************************************************************
    
    
    cdef {arr_type} res 
      
    res = {arr_type}ranspose( &self.arr)

    return {arr_pytype}.create(&res)

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

    return {arr_func}_get_order(&self.arr)

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
  cdef {arr_pytype} create({arr_type}* arr, uint8_t FLAGS = 1):
    """
    PURPOSE:      C-level constructor of the class. Use this when creating objects within 
                  Cython
                  
    """
    #*************************************************************************************************

    # create new empty object:
    cdef {arr_pytype} mat = <{arr_pytype}> {arr_pytype}.__new__({arr_pytype})

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

    

    out =  "{arr_pytype}< "
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

    

    cdef np.ndarray[uint64_t, ndim=1] tmp 

    out =  "{arr_pytype}< "
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

    

    cdef uint64_t i,j 
    cdef {num_pytype} tmp

    out =  "{arr_pytype}< "
    out += "shape: "+str(self.shape)+ ", \n"

    for j in range(self.arr.ncols):
      out += " - Column " + str(j) +"\n"
      for i in range(self.arr.nrows):

        out += "({{0:d}},{{1:d}}) ".format(i,j)
         
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

    
  
    cdef {num_type} d_{num_func}
    cdef {num_pytype}   {num_func}
    
    out  = self.list_repr()
    # out=""

    # out += "["
    # for i in range(self.arr.nrows):
    #   out += "["
    #   for j in range(self.arr.ncols):
    #     d_{num_func} = {arr_func}_get_item_ij(&self.arr, i, j)
    #     out+= ({num_pytype}.create(&d_{num_func},FLAGS=0)).__str__()+", "
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
    
  
    cdef {num_type} d_{num_func}
    cdef {num_pytype}   {num_func}

    out  = self.list_repr()

    # out += "["
    # for i in range(self.arr.nrows):
    #   out += "["
    #   for j in range(self.arr.ncols):
    #     d_{num_func} = {arr_func}_get_item_ij(&self.arr, i, j)
    #     out+= ({num_pytype}.create(&d_{num_func},FLAGS=0)).__str__()+", "
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
    
    

    cdef {num_type} ores
    cdef {arr_type}   Ores
    cdef object res = None
    cdef int64_t starti, stopi, stepi
    cdef int64_t startj, stopj, stepj

    tval = type(val)
    
    if tval == int:
      
      # This is a slice
      if val < self.arr.nrows:
        
        starti, stopi, stepi = slice( val, val+1, None).indices( self.arr.nrows )
        startj, stopj, stepj = slice(None, None, None).indices( self.arr.ncols )

        Ores = {arr_func}_get_slice( &self.arr, starti, stopi, stepi, startj, stopj, stepj)
        res  = {arr_pytype}.create(&Ores)

      else:

        raise IndexError("Index out of bounds.")

      # end if 

    #   ores = {arr_func}_get_item_ij( &self.arr, val[0], val[1])
    #   res  = {num_pytype}.create( &ores, FLAGS = 0 )

    elif tval == slice: #slice of multiple items
      
      # print(val)
      # This is a slice
      starti, stopi, stepi = val.indices( self.arr.nrows )
      startj, stopj, stepj = slice(None, None, None).indices( self.arr.ncols )

      # print("i: ( {{0}}, {{1}}, {{2}})".format(starti, stopi, stepi) )
      # print("j: ( {{0}}, {{1}}, {{2}})".format(startj, stopj, stepj) )

      Ores = {arr_func}_get_slice( &self.arr, starti, stopi, stepi, startj, stopj, stepj)
      res  = {arr_pytype}.create(&Ores)
    
    elif tval == tuple:
      
      if len(val) == 2:

        tval0 = type(val[0])
        tval1 = type(val[1])

        if   tval0 == int and tval1 == int:
          
          # print("Case 1")
          if val[0] < self.arr.nrows and val[1] < self.arr.ncols:
          
            ores = {arr_func}_get_item_ij( &self.arr, val[0], val[1])
            res = {num_pytype}.create(&ores, FLAGS = 0)        
          
          else:

            raise IndexError("Index out of bounds.")

          # end if 

        elif tval0 == int and tval1 == slice:

          # print("Case 2")
          if val[0] < self.arr.nrows:

            starti, stopi, stepi = slice(val[0], val[0]+1, None).indices( self.arr.nrows )
            startj, stopj, stepj = val[1].indices( self.arr.ncols )

            Ores = {arr_func}_get_slice( &self.arr, starti, stopi, stepi, startj, stopj, stepj)
            res  = {arr_pytype}.create(&Ores)  

          else:

            raise IndexError("Index out of bounds.")

          # end if 

        elif tval0 == slice and tval1 == int:

          # print("Case 3")
          if val[1] < self.arr.ncols:

            starti, stopi, stepi = val[0].indices( self.arr.nrows )
            startj, stopj, stepj = slice(val[1], val[1]+1, None).indices( self.arr.ncols )

            Ores = {arr_func}_get_slice( &self.arr, starti, stopi, stepi, startj, stopj, stepj)
            res  = {arr_pytype}.create(&Ores)  

          else:

            raise IndexError("Index out of bounds.")

          # end if 

        elif tval0 == slice and tval1 == slice:

          # print("Case 3")
          starti, stopi, stepi = val[0].indices( self.arr.nrows )
          startj, stopj, stepj = val[1].indices( self.arr.ncols )

          Ores = {arr_func}_get_slice( &self.arr, starti, stopi, stepi, startj, stopj, stepj)
          res  = {arr_pytype}.create(&Ores) 

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

    if ( tvalue == {num_pytype} ):

      self.__setitem__o( val, value )

    elif ( tvalue == {arr_pytype} ):

      self.__setitem__O( val, value )

    elif ( tvalue == dmat ):

      self.__setitem__R( val, value )

    elif ( tvalue in number_types ):

      self.__setitem__r( val, value )

    else:

      raise IndexError("ERROR: Cant set item of type {{0}} in {arr_pytype} object.".format(tvalue))

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

        {arr_func}_set_slice_r( value, starti, stopi, stepi, startj, stopj, stepj, &self.arr)
        
      else:
        raise IndexError("Index out of bounds.")
      # end if 

    elif tval == slice: #slice of multiple items
      
      # This is a slice
      starti, stopi, stepi = val.indices( self.arr.nrows )
      startj, stopj, stepj = slice(None, None, None).indices( self.arr.ncols )

      {arr_func}_set_slice_r( value, starti, stopi, stepi, startj, stopj, stepj, &self.arr)
    
    elif tval == tuple:
      
      if len(val) == 2:

        tval0 = type(val[0])
        tval1 = type(val[1])

        if ( tval0 == int and tval1 == int ):
          
          if val[0] < self.arr.nrows and val[1] < self.arr.ncols:
          
            {arr_func}_set_item_ij_r( value, val[0], val[1], &self.arr)
            
          else:
            raise IndexError("Index out of bounds.")
          # end if 

        elif (tval0 == int and tval1 == slice):

          if val[0] < self.arr.nrows:

            starti, stopi, stepi = slice(val[0], val[0]+1, None).indices( self.arr.nrows )
            startj, stopj, stepj = val[1].indices( self.arr.ncols )

            {arr_func}_set_slice_r( value, starti, stopi, stepi, startj, stopj, stepj, &self.arr)

          else:
            raise IndexError("Index out of bounds.")
          # end if 

        elif (tval0 == slice and tval1 == int):

          if val[1] < self.arr.ncols:

            starti, stopi, stepi = val[0].indices( self.arr.nrows )
            startj, stopj, stepj = slice(val[1], val[1]+1, None).indices( self.arr.ncols )

            {arr_func}_set_slice_r(value, starti, stopi, stepi, startj, stopj, stepj, &self.arr)

          else:
            raise IndexError("Index out of bounds.")
          # end if 

        elif (tval0 == slice and tval1 == slice):

          starti, stopi, stepi = val[0].indices( self.arr.nrows )
          startj, stopj, stepj = val[1].indices( self.arr.ncols )

          {arr_func}_set_slice_r( value, starti, stopi, stepi, startj, stopj, stepj, &self.arr)

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
  cdef __setitem__o(self,  object val, {num_pytype} value):
    """
    PURPOSE: Set item from {num_pytype} value.
    """
    #*************************************************************************************************
    

    tval = type(val)

    if tval == int:
      
      # This is a slice
      if val < self.arr.nrows:
        
        starti, stopi, stepi = slice( val, val+1, None).indices( self.arr.nrows )
        startj, stopj, stepj = slice(None, None, None).indices( self.arr.ncols )

        {arr_func}_set_slice_o( &value.num, starti, stopi, stepi, startj, stopj, stepj, &self.arr)
        
      else:

        raise IndexError("Index out of bounds.")

      # end if 

    elif tval == slice: #slice of multiple items
      
      # This is a slice
      starti, stopi, stepi = val.indices( self.arr.nrows )
      startj, stopj, stepj = slice(None, None, None).indices( self.arr.ncols )

      {arr_func}_set_slice_o( &value.num, starti, stopi, stepi, startj, stopj, stepj, &self.arr)
    
    elif tval == tuple:
      
      if len(val) == 2:

        tval0 = type(val[0])
        tval1 = type(val[1])

        if ( tval0 == int and tval1 == int ):
          
          if val[0] < self.arr.nrows and val[1] < self.arr.ncols:
          
            {arr_func}_set_item_ij_o( &value.num, val[0], val[1], &self.arr)
            
          else:

            raise IndexError("Index out of bounds.")

          # end if 

        elif (tval0 == int and tval1 == slice):

          if val[0] < self.arr.nrows:

            starti, stopi, stepi = slice(val[0], val[0]+1, None).indices( self.arr.nrows )
            startj, stopj, stepj = val[1].indices( self.arr.ncols )

            {arr_func}_set_slice_o( &value.num, starti, stopi, stepi, startj, stopj, stepj, &self.arr)

          else:

            raise IndexError("Index out of bounds.")

          # end if 

        elif (tval0 == slice and tval1 == int):

          if val[1] < self.arr.ncols:

            starti, stopi, stepi = val[0].indices( self.arr.nrows )
            startj, stopj, stepj = slice(val[1], val[1]+1, None).indices( self.arr.ncols )

            {arr_func}_set_slice_o( &value.num, starti, stopi, stepi, startj, stopj, stepj, &self.arr)

          else:

            raise IndexError("Index out of bounds.")

          # end if 

        elif (tval0 == slice and tval1 == slice):

          starti, stopi, stepi = val[0].indices( self.arr.nrows )
          startj, stopj, stepj = val[1].indices( self.arr.ncols )

          {arr_func}_set_slice_o( &value.num, starti, stopi, stepi, startj, stopj, stepj, &self.arr)

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
    

    raise NotImplementedError("Error Setting from Real array not yet supported.")
  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  cdef __setitem__O(self,  object val, {arr_pytype} value):
    """
    PURPOSE: Set item from OTI array.
    """
    #*************************************************************************************************
    

    tval = type(val)

    if tval == int:
      
      # This is a slice
      if val < self.arr.nrows:
        
        starti, stopi, stepi = slice( val, val+1, None).indices( self.arr.nrows )
        startj, stopj, stepj = slice(None, None, None).indices( self.arr.ncols )

        {arr_func}_set_slice_O( &value.arr, starti, stopi, stepi, startj, stopj, stepj, &self.arr)
        
      else:

        raise IndexError("Index out of bounds.")

      # end if 

    elif tval == slice: #slice of multiple items
      
      # This is a slice
      starti, stopi, stepi = val.indices( self.arr.nrows )
      startj, stopj, stepj = slice(None, None, None).indices( self.arr.ncols )

      {arr_func}_set_slice_O( &value.arr, starti, stopi, stepi, startj, stopj, stepj, &self.arr)
    
    elif tval == tuple:
      
      if len(val) == 2:

        tval0 = type(val[0])
        tval1 = type(val[1])

        if ( tval0 == int and tval1 == int ):
          
          if val[0] < self.arr.nrows and val[1] < self.arr.ncols:
          
            starti, stopi, stepi = slice(val[0], val[0]+1, None).indices( self.arr.nrows )
            startj, stopj, stepj = slice(val[1], val[1]+1, None).indices( self.arr.ncols )

            {arr_func}_set_slice_O( &value.arr, starti, stopi, stepi, startj, stopj, stepj, &self.arr)
            
          else:

            raise IndexError("Index out of bounds.")

          # end if 

        elif (tval0 == int and tval1 == slice):

          if val[0] < self.arr.nrows:

            starti, stopi, stepi = slice(val[0], val[0]+1, None).indices( self.arr.nrows )
            startj, stopj, stepj = val[1].indices( self.arr.ncols )

            {arr_func}_set_slice_O( &value.arr, starti, stopi, stepi, startj, stopj, stepj, &self.arr)

          else:

            raise IndexError("Index out of bounds.")

          # end if 

        elif (tval0 == slice and tval1 == int):

          if val[1] < self.arr.ncols:

            starti, stopi, stepi = val[0].indices( self.arr.nrows )
            startj, stopj, stepj = slice(val[1], val[1]+1, None).indices( self.arr.ncols )

            {arr_func}_set_slice_O( &value.arr, starti, stopi, stepi, startj, stopj, stepj, &self.arr)

          else:

            raise IndexError("Index out of bounds.")

          # end if 

        elif (tval0 == slice and tval1 == slice):

          starti, stopi, stepi = val[0].indices( self.arr.nrows )
          startj, stopj, stepj = val[1].indices( self.arr.ncols )

          {arr_func}_set_slice_O( &value.arr, starti, stopi, stepi, startj, stopj, stepj, &self.arr)

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
    
    
    
    cdef {arr_type} res = {arr_func}_copy(&self.arr)

    return {arr_pytype}.create(&res)
  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  def __neg__(self):
    """
    PURPOSE: Negation overload.
    """
    #*************************************************************************************************
    
    
    
    cdef {arr_type} res = {arr_func}_neg(&self.arr)

    return {arr_pytype}.create(&res)
  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  def __add__(self, other):
    """
    PURPOSE: Addition overload.
    """
    #*************************************************************************************************
    
    
    
    cdef {arr_type} res 
    cdef {arr_pytype} lhs,rhs
    cdef dmat dlhs,drhs
    cdef {num_pytype} olhs,orhs
    
    tlhs = type(self)
    trhs = type(other)
    
    if (tlhs == trhs):

      lhs = self
      rhs = other

      res = {arr_func}_sum_OO(&lhs.arr,&rhs.arr)

    elif ( tlhs  == {num_pytype} ):

      olhs = self
      rhs = other

      res = {arr_func}_sum_oO(&olhs.num,&rhs.arr)

    elif ( trhs  == {num_pytype} ):

      lhs = self
      orhs = other

      res = {arr_func}_sum_oO(&orhs.num,&lhs.arr)
    
    elif (tlhs in number_types):
      
      rhs = other
      res = {arr_func}_sum_rO(self, &rhs.arr)

    elif (trhs in number_types):
        
      lhs = self
      res = {arr_func}_sum_rO(other, &lhs.arr)

    elif ( tlhs  == dmat ):

      dlhs = self
      rhs = other

      res = {arr_func}_sum_RO(&dlhs.arr,&rhs.arr)

    elif ( trhs  == dmat ):

      lhs = self
      drhs = other

      res = {arr_func}_sum_RO(&drhs.arr,&lhs.arr)

    else:

      return NotImplemented

    # end if 
      
    return {arr_pytype}.create(&res)

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
    
    
    
    cdef {arr_type} res 
    cdef {arr_pytype} lhs,rhs
    cdef dmat dlhs,drhs
    cdef {num_pytype} olhs,orhs
    
    tlhs = type(self)
    trhs = type(other)
    
    if (tlhs == trhs):

      lhs = self
      rhs = other

      res = {arr_func}_sub_OO(&lhs.arr,&rhs.arr)

    elif ( tlhs  == {num_pytype} ):

      olhs = self
      rhs = other

      res = {arr_func}_sub_oO(&olhs.num,&rhs.arr)

    elif ( trhs  == {num_pytype} ):

      lhs = self
      orhs = other

      res = {arr_func}_sub_Oo(&lhs.arr, &orhs.num)
    
    elif (tlhs in number_types):
      
      rhs = other
      res = {arr_func}_sub_rO(self, &rhs.arr)

    elif (trhs in number_types):
        
      lhs = self
      res = {arr_func}_sub_Or(&lhs.arr, other)

    elif ( tlhs  == dmat ):

      dlhs = self
      rhs = other

      res = {arr_func}_sub_RO(&dlhs.arr,&rhs.arr)

    elif ( trhs  == dmat ):

      lhs = self
      drhs = other

      res = {arr_func}_sub_OR(&lhs.arr, &drhs.arr)

    else:

      return NotImplemented      

    # end if 
      
    return {arr_pytype}.create(&res)

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
    
    
    
    cdef {arr_type} res 
    cdef {arr_pytype} lhs,rhs
    cdef dmat dlhs,drhs
    cdef {num_pytype} olhs,orhs
    
    tlhs = type(self)
    trhs = type(other)
    
    if (tlhs == trhs):

      lhs = self
      rhs = other

      res = {arr_func}_mul_OO(&lhs.arr,&rhs.arr)

    elif ( tlhs  == {num_pytype} ):

      olhs = self
      rhs = other

      res = {arr_func}_mul_oO(&olhs.num,&rhs.arr)

    elif ( trhs  == {num_pytype} ):

      lhs = self
      orhs = other

      res = {arr_func}_mul_oO(&orhs.num,&lhs.arr)
    
    elif (tlhs in number_types):
      
      rhs = other
      res = {arr_func}_mul_rO(self, &rhs.arr)

    elif (trhs in number_types):
        
      lhs = self
      res = {arr_func}_mul_rO(other, &lhs.arr)

    elif ( tlhs  == dmat ):

      dlhs = self
      rhs = other

      res = {arr_func}_mul_RO(&dlhs.arr,&rhs.arr)

    elif ( trhs  == dmat ):

      lhs = self
      drhs = other

      res = {arr_func}_mul_RO(&drhs.arr,&lhs.arr)

    else:

      return NotImplemented      

    # end if 
      
    return {arr_pytype}.create(&res)

    

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
    
    
    
    cdef {arr_type} res 
    cdef {arr_pytype} lhs,rhs
    cdef dmat dlhs,drhs
    cdef {num_pytype} olhs,orhs
    
    tlhs = type(self)
    trhs = type(other)
    
    if (tlhs == trhs):

      lhs = self
      rhs = other

      res = {arr_func}_div_OO(&lhs.arr,&rhs.arr)

    elif ( tlhs  == {num_pytype} ):

      olhs = self
      rhs = other

      res = {arr_func}_div_oO(&olhs.num,&rhs.arr)

    elif ( trhs  == {num_pytype} ):

      lhs = self
      orhs = other

      res = {arr_func}_div_Oo(&lhs.arr, &orhs.num)
    
    elif (tlhs in number_types):
      
      rhs = other
      res = {arr_func}_div_rO(self, &rhs.arr)

    elif (trhs in number_types):
        
      lhs = self
      res = {arr_func}_div_Or(&lhs.arr, other)

    elif ( tlhs  == dmat ):

      dlhs = self
      rhs = other

      res = {arr_func}_div_RO(&dlhs.arr,&rhs.arr)

    elif ( trhs  == dmat ):

      lhs = self
      drhs = other

      res = {arr_func}_div_OR(&lhs.arr, &drhs.arr)

    else:

      return NotImplemented      

    # end if 
      
    return {arr_pytype}.create(&res)

  #---------------------------------------------------------------------------------------------------  

  #***************************************************************************************************
  def __pow__(self, n,z):
    """
    PURPOSE:      Power function oversload
    """
    #*************************************************************************************************
    
    

    cdef {arr_type} res 
    cdef {arr_pytype} S = self

    res = {arr_func}_pow( &S.arr, n)
    
    return {arr_pytype}.create(&res)

  #---------------------------------------------------------------------------------------------------  

  #***************************************************************************************************
  cpdef get_deriv(self, object hum_dir):
    """
    PURPOSE: Get the corresponding imaginary direction in the {arr_pytype} object.
    """
    #*************************************************************************************************
    
    
    cdef list item = imdir(hum_dir)
    cdef darr_t res_darr
    cdef dmat res_dmat
    cdef uint64_t i,j, k
    cdef np.ndarray[double, ndim=2] res

    res_darr = {arr_func}_get_deriv( item[ZERO],  item[ONE], &self.arr)

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
  cpdef get_im(self, object hum_dir):
    """
    PURPOSE: Get the corresponding imaginary direction in the {arr_pytype} object.
    """
    #*************************************************************************************************
    
    
    cdef list item = imdir(hum_dir)
    cdef darr_t res_darr
    cdef dmat res_dmat
    cdef uint64_t i,j, k
    cdef np.ndarray[double, ndim=2] res

    res_darr = {arr_func}_get_im( item[ZERO],  item[ONE], &self.arr)

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
    PURPOSE: Get the corresponding imaginary direction in the {arr_pytype} object.
    """
    #*************************************************************************************************
    
    
    cdef list item = imdir(hum_dir)
    cdef {arr_type} res
    

    res = {arr_func}_extract_im( item[ZERO],  item[ONE], &self.arr)

    return {arr_pytype}.create(&res)

  #---------------------------------------------------------------------------------------------------
  
  #***************************************************************************************************
  cpdef  extract_deriv(self, object hum_dir):
    """
    PURPOSE: Get the corresponding derivative in the {arr_pytype} object, as OTI number.
    """
    #*************************************************************************************************
    
    
    cdef list item = imdir(hum_dir)
    cdef {arr_type} res
    
    res = {arr_func}_extract_deriv( item[ZERO],  item[ONE], &self.arr)

    return {arr_pytype}.create(&res)

  #---------------------------------------------------------------------------------------------------
  

  #***************************************************************************************************
  cpdef  get_order_im(self, ord_t order):
    """
    PURPOSE: Get the corresponding derivative in the {arr_pytype} object, as OTI number.
    """
    #*************************************************************************************************
    
    
    cdef {arr_type} res
    
    res = {arr_func}_get_order_im( order, &self.arr)

    return {arr_pytype}.create(&res)

  #---------------------------------------------------------------------------------------------------
  

  #***************************************************************************************************
  cpdef  truncate( self, object humdir):
    """
    PURPOSE:      to set a specific imaginary direction as given.

    """
    #*************************************************************************************************
    

    cdef imdir_t indx
    cdef ord_t  order
    cdef {arr_type} res
    
    indx, order = imdir(humdir)
    
    res = {arr_func}_truncate_im( indx, order, &self.arr) 

    return {arr_pytype}.create(&res)

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  cpdef set(self, object rhs):
    """
    PURPOSE:  Sets from another value.
    """
    #*************************************************************************************************
    
    
    cdef {num_pytype} orhs
    cdef coeff_t rrhs

    cdef {arr_pytype} Orhs
    trhs = type(rhs)

    if   trhs is {num_pytype}:

      orhs = rhs
      {arr_func}_set_o( &orhs.num, &self.arr)

    elif trhs is {arr_pytype}:

      Orhs = rhs
      {arr_func}_set_O( &Orhs.arr, &self.arr)      

    elif trhs in number_types:

      rrhs = rhs
      {arr_func}_set_r( rrhs, &self.arr)

    else:

      raise ValueError( "Cant assign '{{0}}' into a {arr_pytype} object.".format(trhs) )
      
    # end if 

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  def get_active_bases(self):
    """

    """
    

    cdef bases_t  size       = dhl.p_dh[0].Nbasis
    cdef imdir_t* bases_list = dhl.p_dh[0].p_idx[0]
    cdef uint64_t i
    
    # Initialize all elements as zero (deactivated)
    for i in range(size):

      bases_list[i]=0

    # end for 

    {arr_func}_get_active_bases( &self.arr, bases_list)

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
    

    cdef bases_t  size     = dhl.p_dh[0].Nbasis
    cdef coeff_t* c_deltas = dhl.p_dh[0].p_im[0]
    cdef int64_t i
    cdef {arr_type} res
    
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

    res = {arr_func}_taylor_integrate( c_deltas, &self.arr)

    return {arr_pytype}.create(&res)

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  @staticmethod
  def dot( {arr_pytype} lhs, {arr_pytype} rhs, {arr_pytype} out = None): 
    """
    PURPOSE: Matrix multiplication.
    """
    
    
    cdef {arr_type} res 

    if out is not None:
      
      {arr_func}_matmul_OO_to( &lhs.arr, &rhs.arr ,&out.arr)

    else:

      res = {arr_func}_matmul_OO( &lhs.arr, &rhs.arr )

      return {arr_pytype}.create(&res)

    # end if 

  #---------------------------------------------------------------------------------------------------

  

  #***************************************************************************************************
  @staticmethod
  def inv( {arr_pytype} arr,  {arr_pytype} out = None): 
    """
    PURPOSE: Matrix invertion.
    """
    
    
    cdef {arr_type} res 

    if out is not None:
      
      {arr_func}_invert_to( &arr.arr,&out.arr)

    else:

      res = {arr_func}_invert( &arr.arr)

      return {arr_pytype}.create(&res)

    # end if 

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  @staticmethod
  def transpose( {arr_pytype} arr,  {arr_pytype} out = None ): 
    """
    PURPOSE: Matrix transpose.
    """
    
    
    cdef {arr_type} res 

    if out is not None:
      
      {arr_type}ranspose_to( &arr.arr, &out.arr)

    else:

      res = {arr_type}ranspose( &arr.arr)

      return {arr_pytype}.create(&res)

    # end if 

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  @staticmethod
  def add( {arr_pytype} lhs, {arr_pytype} rhs, {arr_pytype} out = None): 
    """
    PURPOSE: Matrix elementwise addition.
    """
    
    
    cdef {arr_type} res 

    if out is not None:
      
      {arr_func}_sum_OO_to( &lhs.arr, &rhs.arr ,&out.arr)

    else:

      res = {arr_func}_sum_OO( &lhs.arr, &rhs.arr )

      return {arr_pytype}.create(&res)

    # end if 

  #---------------------------------------------------------------------------------------------------
  

# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# :::::::::::::::::::::::::::::::::::: END OF CLASS {arr_pytype} ::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

