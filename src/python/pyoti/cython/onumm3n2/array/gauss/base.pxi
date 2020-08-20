

# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::     CLASS  feoarrm3n2_t    :::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
cdef class feoarrm3n2_t:
  #---------------------------------------------------------------------------------------------------
  #------------------------------------   DEFINITION OF ATTRIBUTES   ---------------------------------
  #---------------------------------------------------------------------------------------------------
  
  #                                --->      Look in dense.pxd    <---

  #---------------------------------------------------------------------------------------------------  

  #***************************************************************************************************
  
  def __init__(self, shape, uint64_t nip, ord_t order = 0, bases_t nbases = 0): 
    """
    PURPOSE:      Python level constructor of the feoarrm3n2_t class.

    DESCRIPTION:  Creates a new matrix, reserving memory Assumes coefficient values to be all zeroes.
                 
    """
    #*************************************************************************************************
    
    
    cdef uint64_t i,j
    cdef ord_t ordi

    #
    if (isinstance(shape, tuple)):

      ndim = len(shape)
            
      if( ndim == 1 ):
      
        self.arr = feoarrm3n2_zeros(shape[0], 1, nip) 
      
      elif(ndim == 2):

        self.arr = feoarrm3n2_zeros(shape[0], shape[1], nip) 

      else:

        raise ValueError("Cant create feoarrm3n2_t for dimensions greater than 2.")
      
      # end if   
       
    elif(isinstance(shape,int)):

      self.arr = feoarrm3n2_zeros(shape, 1, nip)

    else:

      raise ValueError("Input should be either tuple or integer.")

    # end if 
    
    self.FLAGS = 1

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  def __dealloc__(self): 
    """
    PURPOSE:      Destructor of the class.                   
    """
    #*************************************************************************************************
    
    if self.FLAGS == 1:
    
      feoarrm3n2_free(&self.arr)

    # end if 
    
  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  @property
  def nip(self): 
    """
    PURPOSE:     Return the number of integration points. 
    """
    #*************************************************************************************************

    return self.arr.nip

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  @property
  def order(self): 
    """
    PURPOSE:      Return the shape of the stored matrix. 
    """
    #*************************************************************************************************

    return feoarrm3n2_get_order(&self.arr)

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
  def shape(self): 
    """
    PURPOSE:      Return the shape of the stored matrix. 
    """
    #*************************************************************************************************

    return (self.arr.nrows,self.arr.ncols)

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  @property
  def real(self):
    """
    PURPOSE:      Get a numpy array with all coefficients in the real direction.

    """
    #*************************************************************************************************

    cdef np.ndarray[coeff_t, ndim=3] tmp
    cdef uint64_t i, j, k
    cdef onumm3n2_t onumm3n2_tmp

    tmp = np.empty( (self.arr.nrows,self.arr.ncols,self.arr.nip) , dtype = np.float64)

    for k in range(self.arr.nip):
      for i in range(self.arr.nrows):
        for j in range(self.arr.ncols):
          
          onumm3n2_tmp = feoarrm3n2_get_item_ijk(&self.arr, i, j, k);
          tmp[i,j,k] = onumm3n2_tmp.re
        
        # end for
      # end for
    # end for

    return tmp

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  @staticmethod
  cdef feoarrm3n2_t create(feoarrm3n2_t* arr, uint8_t FLAGS = 1):
    """
    PURPOSE:      C-level constructor of the class. Use this when creating objects within 
                  Cython
                  
    """
    #*************************************************************************************************

    # create new empty object:
    cdef feoarrm3n2_t res = <feoarrm3n2_t> feoarrm3n2_t.__new__(feoarrm3n2_t)

    res.arr = arr[0]
    res.FLAGS = FLAGS

    return res

  #--------------------------------------------------------------------------------------------------- 

  #*************************************************************************************************** 
  def short_repr(self):
    """
    PURPOSE:      A short representation of the object.
  
    """
    #*************************************************************************************************

    

    out =  "feoarrm3n2_t< "
    out += "nip: "+str(self.nip)+ ", "
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

    out =  "feoarrm3n2_t< "
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

    

    cdef uint64_t i
    cdef oarrm3n2_t tmp

    out =  "feoarrm3n2_t< "
    out += "nip: "+str(self.nip)+ ", \n"

    for i in range(self.nip):

      out += "(Integration point - {0:d}) \n".format(i)
      out += "-------------------------\n"
      
      tmp = self.get_ip( i )
      
      out += tmp.__str__()
      
      out += "\n"
      out += "-------------------------\n"
     
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

    
  
    cdef onumm3n2_t d_onumm3n2
    cdef onumm3n2_t   onumm3n2

    out  = self.list_repr()

    return out

  #--------------------------------------------------------------------------------------------------- 
  

  #***************************************************************************************************
  def __str__(self):
    """
    PURPOSE:      Create a string representation of the object.    
    """
    #*************************************************************************************************
    
  
    cdef onumm3n2_t d_onumm3n2
    cdef onumm3n2_t   onumm3n2

    out  = self.list_repr()

    return out

  #---------------------------------------------------------------------------------------------------  

  #***************************************************************************************************
  def  __getitem__(self, val):
    """
    PURPOSE: Get the value of an element of the item.
    """
    #*************************************************************************************************

    

    cdef onumm3n2_t ores
    cdef feonumm3n2_t  fres
    cdef oarrm3n2_t   Ores
    cdef feoarrm3n2_t Fres
    cdef object res = None
    cdef int64_t starti, stopi, stepi
    cdef int64_t startj, stopj, stepj

    tval = type(val)
    
    if tval == int:
      
      # This is a slice
      if val < self.arr.nrows:
        
        starti, stopi, stepi = slice( val, val+1, None).indices( self.arr.nrows )
        startj, stopj, stepj = slice(None, None, None).indices( self.arr.ncols )

        Fres = feoarrm3n2_get_slice( &self.arr, starti, stopi, stepi, startj, stopj, stepj)
        res  = feoarrm3n2_t.create(&Fres)

      else:

        raise IndexError("Index out of bounds.")

      # end if 

    #   ores = oarrm3n2_get_item_ij( &self.arr, val[0], val[1])
    #   res  = onumm3n2_t.create( &ores, FLAGS = 0 )

    elif tval == slice: #slice of multiple items
      
      # print(val)
      # This is a slice
      starti, stopi, stepi = val.indices( self.arr.nrows )
      startj, stopj, stepj = slice(None, None, None).indices( self.arr.ncols )

      # print("i: ( {0}, {1}, {2})".format(starti, stopi, stepi) )
      # print("j: ( {0}, {1}, {2})".format(startj, stopj, stepj) )

      Fres = feoarrm3n2_get_slice( &self.arr, starti, stopi, stepi, startj, stopj, stepj)
      res  = feoarrm3n2_t.create(&Fres)
    
    elif tval == tuple:
      
      if len(val) == 2:

        tval0 = type(val[0])
        tval1 = type(val[1])

        if   tval0 == int and tval1 == int:
          
          # print("Case 1")
          if val[0] < self.arr.nrows and val[1] < self.arr.ncols:
          
            fres = feoarrm3n2_get_item_ij( &self.arr, val[0], val[1])
            res  = feonumm3n2_t.create( &fres )
          
          else:

            raise IndexError("Index out of bounds.")

          # end if 

        elif tval0 == int and tval1 == slice:

          # print("Case 2")
          if val[0] < self.arr.nrows:

            starti, stopi, stepi = slice(val[0], val[0]+1, None).indices( self.arr.nrows )
            startj, stopj, stepj = val[1].indices( self.arr.ncols )

            Fres = feoarrm3n2_get_slice( &self.arr, starti, stopi, stepi, startj, stopj, stepj)
            res  = feoarrm3n2_t.create(&Fres)  

          else:

            raise IndexError("Index out of bounds.")

          # end if 

        elif tval0 == slice and tval1 == int:

          # print("Case 3")
          if val[1] < self.arr.ncols:

            starti, stopi, stepi = val[0].indices( self.arr.nrows )
            startj, stopj, stepj = slice(val[1], val[1]+1, None).indices( self.arr.ncols )

            Fres = feoarrm3n2_get_slice( &self.arr, starti, stopi, stepi, startj, stopj, stepj)
            res  = feoarrm3n2_t.create(&Fres)  

          else:

            raise IndexError("Index out of bounds.")

          # end if 

        elif tval0 == slice and tval1 == slice:

          # print("Case 3")
          starti, stopi, stepi = val[0].indices( self.arr.nrows )
          startj, stopj, stepj = val[1].indices( self.arr.ncols )

          Fres = feoarrm3n2_get_slice( &self.arr, starti, stopi, stepi, startj, stopj, stepj)
          res  = feoarrm3n2_t.create(&Fres) 

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
  def __setitem__(self, indices, value):
    """
    PURPOSE: Set an element of the item to the specified value.
    """
    #*************************************************************************************************
    

    tvalue = type(value)

    if ( tvalue == onumm3n2_t ):

      self.__setitem__o( indices, value )

    elif ( tvalue == feonumm3n2_t ):

      self.__setitem__f( indices, value )

    elif ( tvalue == oarrm3n2_t ):

      self.__setitem__O( indices, value )

    elif ( tvalue == feoarrm3n2_t ):

      self.__setitem__F( indices, value )

    elif ( tvalue in number_types ):

      self.__setitem__r( indices, value )

    else:
      raise IndexError("ERROR: Cant set item of type {0} in oarrm3n2_t object.".format(tvalue))
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

        feoarrm3n2_set_slice_r( value, starti, stopi, stepi, startj, stopj, stepj, &self.arr)
        
      else:
        raise IndexError("Index out of bounds.")
      # end if 

    elif tval == slice: #slice of multiple items
      
      # This is a slice
      starti, stopi, stepi = val.indices( self.arr.nrows )
      startj, stopj, stepj = slice(None, None, None).indices( self.arr.ncols )

      feoarrm3n2_set_slice_r( value, starti, stopi, stepi, startj, stopj, stepj, &self.arr)
    
    elif tval == tuple:
      
      if len(val) == 2:

        tval0 = type(val[0])
        tval1 = type(val[1])

        if ( tval0 == int and tval1 == int ):
          
          if val[0] < self.arr.nrows and val[1] < self.arr.ncols:
          
            feoarrm3n2_set_item_ij_r( value, val[0], val[1], &self.arr)
            
          else:
            raise IndexError("Index out of bounds.")
          # end if 

        elif (tval0 == int and tval1 == slice):

          if val[0] < self.arr.nrows:

            starti, stopi, stepi = slice(val[0], val[0]+1, None).indices( self.arr.nrows )
            startj, stopj, stepj = val[1].indices( self.arr.ncols )

            feoarrm3n2_set_slice_r( value, starti, stopi, stepi, startj, stopj, stepj, &self.arr)

          else:
            raise IndexError("Index out of bounds.")
          # end if 

        elif (tval0 == slice and tval1 == int):

          if val[1] < self.arr.ncols:

            starti, stopi, stepi = val[0].indices( self.arr.nrows )
            startj, stopj, stepj = slice(val[1], val[1]+1, None).indices( self.arr.ncols )

            feoarrm3n2_set_slice_r(value, starti, stopi, stepi, startj, stopj, stepj, &self.arr)

          else:
            raise IndexError("Index out of bounds.")
          # end if 

        elif (tval0 == slice and tval1 == slice):

          starti, stopi, stepi = val[0].indices( self.arr.nrows )
          startj, stopj, stepj = val[1].indices( self.arr.ncols )

          feoarrm3n2_set_slice_r( value, starti, stopi, stepi, startj, stopj, stepj, &self.arr)

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
  cdef __setitem__o(self,  object val, onumm3n2_t value):
    """
    PURPOSE: Set item from onumm3n2_t value.
    """
    #*************************************************************************************************
    

    tval = type(val)

    if tval == int:
      
      # This is a slice
      if val < self.arr.nrows:
        
        starti, stopi, stepi = slice( val, val+1, None).indices( self.arr.nrows )
        startj, stopj, stepj = slice(None, None, None).indices( self.arr.ncols )

        feoarrm3n2_set_slice_o( &value.num, starti, stopi, stepi, startj, stopj, stepj, &self.arr)
        
      else:
        raise IndexError("Index out of bounds.")
      # end if 

    elif tval == slice: #slice of multiple items
      
      # This is a slice
      starti, stopi, stepi = val.indices( self.arr.nrows )
      startj, stopj, stepj = slice(None, None, None).indices( self.arr.ncols )

      feoarrm3n2_set_slice_o( &value.num, starti, stopi, stepi, startj, stopj, stepj, &self.arr)
    
    elif tval == tuple:
      
      if len(val) == 2:

        tval0 = type(val[0])
        tval1 = type(val[1])

        if ( tval0 == int and tval1 == int ):
          
          if val[0] < self.arr.nrows and val[1] < self.arr.ncols:
          
            feoarrm3n2_set_item_ij_o( &value.num, val[0], val[1], &self.arr)
            
          else:
            raise IndexError("Index out of bounds.")
          # end if 

        elif (tval0 == int and tval1 == slice):

          if val[0] < self.arr.nrows:

            starti, stopi, stepi = slice(val[0], val[0]+1, None).indices( self.arr.nrows )
            startj, stopj, stepj = val[1].indices( self.arr.ncols )

            feoarrm3n2_set_slice_o( &value.num, starti, stopi, stepi, startj, stopj, stepj, &self.arr)

          else:
            raise IndexError("Index out of bounds.")
          # end if 

        elif (tval0 == slice and tval1 == int):

          if val[1] < self.arr.ncols:

            starti, stopi, stepi = val[0].indices( self.arr.nrows )
            startj, stopj, stepj = slice(val[1], val[1]+1, None).indices( self.arr.ncols )

            feoarrm3n2_set_slice_o( &value.num, starti, stopi, stepi, startj, stopj, stepj, &self.arr)

          else:
            raise IndexError("Index out of bounds.")
          # end if 

        elif (tval0 == slice and tval1 == slice):

          starti, stopi, stepi = val[0].indices( self.arr.nrows )
          startj, stopj, stepj = val[1].indices( self.arr.ncols )

          feoarrm3n2_set_slice_o( &value.num, starti, stopi, stepi, startj, stopj, stepj, &self.arr)

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
  cdef __setitem__f(self,  object val, feonumm3n2_t value):
    """
    PURPOSE: Set item from feonumm3n2_t value.
    """
    #*************************************************************************************************
    

    tval = type(val)

    if tval == int:
      
      # This is a slice
      if val < self.arr.nrows:
        
        starti, stopi, stepi = slice( val, val+1, None).indices( self.arr.nrows )
        startj, stopj, stepj = slice(None, None, None).indices( self.arr.ncols )

        feoarrm3n2_set_slice_f( &value.num, starti, stopi, stepi, startj, stopj, stepj, &self.arr)
        
      else:
        raise IndexError("Index out of bounds.")
      # end if 

    elif tval == slice: #slice of multiple items
      
      # This is a slice
      starti, stopi, stepi = val.indices( self.arr.nrows )
      startj, stopj, stepj = slice(None, None, None).indices( self.arr.ncols )

      feoarrm3n2_set_slice_f( &value.num, starti, stopi, stepi, startj, stopj, stepj, &self.arr)
    
    elif tval == tuple:
      
      if len(val) == 2:

        tval0 = type(val[0])
        tval1 = type(val[1])

        if ( tval0 == int and tval1 == int ):
          
          if val[0] < self.arr.nrows and val[1] < self.arr.ncols:
          
            feoarrm3n2_set_item_ij_f( &value.num, val[0], val[1], &self.arr)
            
          else:
            raise IndexError("Index out of bounds.")
          # end if 

        elif (tval0 == int and tval1 == slice):

          if val[0] < self.arr.nrows:

            starti, stopi, stepi = slice(val[0], val[0]+1, None).indices( self.arr.nrows )
            startj, stopj, stepj = val[1].indices( self.arr.ncols )

            feoarrm3n2_set_slice_f( &value.num, starti, stopi, stepi, startj, stopj, stepj, &self.arr)

          else:
            raise IndexError("Index out of bounds.")
          # end if 

        elif (tval0 == slice and tval1 == int):

          if val[1] < self.arr.ncols:

            starti, stopi, stepi = val[0].indices( self.arr.nrows )
            startj, stopj, stepj = slice(val[1], val[1]+1, None).indices( self.arr.ncols )

            feoarrm3n2_set_slice_f( &value.num, starti, stopi, stepi, startj, stopj, stepj, &self.arr)

          else:
            raise IndexError("Index out of bounds.")
          # end if 

        elif (tval0 == slice and tval1 == slice):

          starti, stopi, stepi = val[0].indices( self.arr.nrows )
          startj, stopj, stepj = val[1].indices( self.arr.ncols )

          feoarrm3n2_set_slice_f( &value.num, starti, stopi, stepi, startj, stopj, stepj, &self.arr)

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
  cdef __setitem__F(self,  object val, feoarrm3n2_t value):
    """
    PURPOSE: Set item from feoarrm3n2_t value.
    """
    #*************************************************************************************************
    

    tval = type(val)

    if tval == int:
      
      # This is a slice
      if val < self.arr.nrows:
        
        starti, stopi, stepi = slice( val, val+1, None).indices( self.arr.nrows )
        startj, stopj, stepj = slice(None, None, None).indices( self.arr.ncols )

        feoarrm3n2_set_slice_F( &value.arr, starti, stopi, stepi, startj, stopj, stepj, &self.arr)
        
      else:
        raise IndexError("Index out of bounds.")
      # end if 

    elif tval == slice: #slice of multiple items
      
      # This is a slice
      starti, stopi, stepi = val.indices( self.arr.nrows )
      startj, stopj, stepj = slice(None, None, None).indices( self.arr.ncols )

      feoarrm3n2_set_slice_F( &value.arr, starti, stopi, stepi, startj, stopj, stepj, &self.arr)
    
    elif tval == tuple:
      
      if len(val) == 2:

        tval0 = type(val[0])
        tval1 = type(val[1])

        if (tval0 == int and tval1 == slice):

          if val[0] < self.arr.nrows:

            starti, stopi, stepi = slice(val[0], val[0]+1, None).indices( self.arr.nrows )
            startj, stopj, stepj = val[1].indices( self.arr.ncols )

            feoarrm3n2_set_slice_F( &value.arr, starti, stopi, stepi, startj, stopj, stepj, &self.arr)

          else:
            raise IndexError("Index out of bounds.")
          # end if 

        elif (tval0 == slice and tval1 == int):

          if val[1] < self.arr.ncols:

            starti, stopi, stepi = val[0].indices( self.arr.nrows )
            startj, stopj, stepj = slice(val[1], val[1]+1, None).indices( self.arr.ncols )

            feoarrm3n2_set_slice_F( &value.arr, starti, stopi, stepi, startj, stopj, stepj, &self.arr)

          else:
            raise IndexError("Index out of bounds.")
          # end if 

        elif (tval0 == slice and tval1 == slice):

          starti, stopi, stepi = val[0].indices( self.arr.nrows )
          startj, stopj, stepj = val[1].indices( self.arr.ncols )

          feoarrm3n2_set_slice_F( &value.arr, starti, stopi, stepi, startj, stopj, stepj, &self.arr)

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
  cdef __setitem__O(self,  object val, oarrm3n2_t value):
    """
    PURPOSE: Set item from feoarrm3n2_t value.
    """
    #*************************************************************************************************
    

    tval = type(val)

    if tval == int:
      
      # This is a slice
      if val < self.arr.nrows:
        
        starti, stopi, stepi = slice( val, val+1, None).indices( self.arr.nrows )
        startj, stopj, stepj = slice(None, None, None).indices( self.arr.ncols )

        feoarrm3n2_set_slice_O( &value.arr, starti, stopi, stepi, startj, stopj, stepj, &self.arr)
        
      else:
        raise IndexError("Index out of bounds.")
      # end if 

    elif tval == slice: #slice of multiple items
      
      # This is a slice
      starti, stopi, stepi = val.indices( self.arr.nrows )
      startj, stopj, stepj = slice(None, None, None).indices( self.arr.ncols )

      feoarrm3n2_set_slice_O( &value.arr, starti, stopi, stepi, startj, stopj, stepj, &self.arr)
    
    elif tval == tuple:
      
      if len(val) == 2:

        tval0 = type(val[0])
        tval1 = type(val[1])

        if (tval0 == int and tval1 == slice):

          if val[0] < self.arr.nrows:

            starti, stopi, stepi = slice(val[0], val[0]+1, None).indices( self.arr.nrows )
            startj, stopj, stepj = val[1].indices( self.arr.ncols )

            feoarrm3n2_set_slice_O( &value.arr, starti, stopi, stepi, startj, stopj, stepj, &self.arr)

          else:
            raise IndexError("Index out of bounds.")
          # end if 

        elif (tval0 == slice and tval1 == int):

          if val[1] < self.arr.ncols:

            starti, stopi, stepi = val[0].indices( self.arr.nrows )
            startj, stopj, stepj = slice(val[1], val[1]+1, None).indices( self.arr.ncols )

            feoarrm3n2_set_slice_O( &value.arr, starti, stopi, stepi, startj, stopj, stepj, &self.arr)

          else:
            raise IndexError("Index out of bounds.")
          # end if 

        elif (tval0 == slice and tval1 == slice):

          starti, stopi, stepi = val[0].indices( self.arr.nrows )
          startj, stopj, stepj = val[1].indices( self.arr.ncols )

          feoarrm3n2_set_slice_O( &value.arr, starti, stopi, stepi, startj, stopj, stepj, &self.arr)

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
    
    
    
    cdef feoarrm3n2_t res = feoarrm3n2_copy(&self.arr)

    return feoarrm3n2_t.create(&res)
  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  def __neg__(self):
    """
    PURPOSE: Negation overload.
    """
    #*************************************************************************************************
    
    
    
    cdef feoarrm3n2_t res = feoarrm3n2_neg(&self.arr)

    return feoarrm3n2_t.create(&res)
  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  def __add__(self, other):
    """
    PURPOSE: Addition overload.
    """
    #*************************************************************************************************
    
    
    
    cdef feoarrm3n2_t res 
    cdef feoarrm3n2_t Flhs,Frhs
    cdef feonumm3n2_t  flhs,frhs
    cdef dmat    Dlhs,Drhs
    cdef onumm3n2_t olhs,orhs
    cdef oarrm3n2_t   Olhs,Orhs
    
    tlhs = type(self)
    trhs = type(other)
    
    if (tlhs == trhs):     # FF

      Flhs = self
      Frhs = other

      res = feoarrm3n2_sum_FF(&Flhs.arr,&Frhs.arr)

    elif (tlhs == feonumm3n2_t): # fF

      flhs = self
      Frhs = other

      res = feoarrm3n2_sum_fF(&flhs.num,&Frhs.arr)

    elif (trhs == feonumm3n2_t): # Ff

      Flhs = self
      frhs = other

      res = feoarrm3n2_sum_fF(&frhs.num,&Flhs.arr)

    elif (tlhs == oarrm3n2_t): # OF

      Olhs = self
      Frhs = other

      res = feoarrm3n2_sum_OF(&Olhs.arr,&Frhs.arr)

    elif (trhs == oarrm3n2_t): # FO

      Flhs = self
      Orhs = other

      res = feoarrm3n2_sum_OF(&Orhs.arr,&Flhs.arr)

    # elif ( tlhs  == dmat ):

    #   Dlhs = self
    #   Frhs = other

    #   res = feoarrm3n2_sum_RO(&Dlhs.arr,&Frhs.arr)

    # elif ( trhs  == dmat ):

    #   Flhs = self
    #   Drhs = other

    #   res = feoarrm3n2_sum_RO(&Drhs.arr,&Flhs.arr)

    elif ( tlhs  == onumm3n2_t ): # oF

      olhs = self
      Frhs = other

      res = feoarrm3n2_sum_oF(&olhs.num,&Frhs.arr)

    elif ( trhs  == onumm3n2_t ): # oF

      Flhs = self
      orhs = other

      res = feoarrm3n2_sum_oF(&orhs.num,&Flhs.arr)
    
    elif (tlhs in number_types): # rF
      
      Frhs = other
      res = feoarrm3n2_sum_rF(self, &Frhs.arr)

    elif (trhs in number_types): # Fr
        
      Flhs = self
      res = feoarrm3n2_sum_rF(other, &Flhs.arr)

    else:

      return NotImplemented

    # end if 
      
    return feoarrm3n2_t.create(&res)

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
  #***************************************************************************************************
    
    
    
    cdef feoarrm3n2_t res 
    cdef feoarrm3n2_t Flhs,Frhs
    cdef feonumm3n2_t  flhs,frhs
    cdef dmat    Dlhs,Drhs
    cdef onumm3n2_t olhs,orhs
    cdef oarrm3n2_t   Olhs,Orhs
    
    tlhs = type(self)
    trhs = type(other)
    
    if (tlhs == trhs):     # FF

      Flhs = self
      Frhs = other

      res = feoarrm3n2_sub_FF(&Flhs.arr,&Frhs.arr)

    elif (tlhs == feonumm3n2_t): # fF

      flhs = self
      Frhs = other

      res = feoarrm3n2_sub_fF(&flhs.num,&Frhs.arr)

    elif (trhs == feonumm3n2_t): # Ff

      Flhs = self
      frhs = other

      res = feoarrm3n2_sub_Ff(&Flhs.arr,&frhs.num)

    elif (tlhs == oarrm3n2_t): # OF

      Olhs = self
      Frhs = other

      res = feoarrm3n2_sub_OF(&Olhs.arr,&Frhs.arr)

    elif (trhs == oarrm3n2_t): # FO

      Flhs = self
      Orhs = other

      res = feoarrm3n2_sub_FO(&Flhs.arr,&Orhs.arr)

    # elif ( tlhs  == dmat ):

    #   Dlhs = self
    #   Frhs = other

    #   res = feoarrm3n2_sub_RO(&Dlhs.arr,&Frhs.arr)

    # elif ( trhs  == dmat ):

    #   Flhs = self
    #   Drhs = other

    #   res = feoarrm3n2_sub_OR(&Drhs.arr,&Flhs.arr)

    elif ( tlhs  == onumm3n2_t ): # oF

      olhs = self
      Frhs = other

      res = feoarrm3n2_sub_oF(&olhs.num,&Frhs.arr)

    elif ( trhs  == onumm3n2_t ): # Fo

      Flhs = self
      orhs = other

      res = feoarrm3n2_sub_Fo(&Flhs.arr, &orhs.num)
    
    elif (tlhs in number_types): # rF
      
      Frhs = other
      res = feoarrm3n2_sub_rF(self, &Frhs.arr)

    elif (trhs in number_types): # Fr
        
      Flhs = self
      res = feoarrm3n2_sub_Fr( &Flhs.arr, other)

    else:

      return NotImplemented

    # end if 
      
    return feoarrm3n2_t.create(&res)

  #-----------------------------------------------------------------------------------------------------

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
    
    
    
    cdef feoarrm3n2_t res 
    cdef feoarrm3n2_t Flhs,Frhs
    cdef feonumm3n2_t  flhs,frhs
    cdef dmat    Dlhs,Drhs
    cdef onumm3n2_t olhs,orhs
    cdef oarrm3n2_t   Olhs,Orhs
    
    tlhs = type(self)
    trhs = type(other)
    
    if (tlhs == trhs):     # FF

      Flhs = self
      Frhs = other

      res = feoarrm3n2_mul_FF(&Flhs.arr,&Frhs.arr)

    elif (tlhs == feonumm3n2_t): # fF

      flhs = self
      Frhs = other

      res = feoarrm3n2_mul_fF(&flhs.num,&Frhs.arr)

    elif (trhs == feonumm3n2_t): # Ff

      Flhs = self
      frhs = other

      res = feoarrm3n2_mul_fF(&frhs.num,&Flhs.arr)

    elif (tlhs == oarrm3n2_t): # OF

      Olhs = self
      Frhs = other

      res = feoarrm3n2_mul_OF(&Olhs.arr,&Frhs.arr)

    elif (trhs == oarrm3n2_t): # FO

      Flhs = self
      Orhs = other

      res = feoarrm3n2_mul_OF(&Orhs.arr,&Flhs.arr)

    # elif ( tlhs  == dmat ):

    #   Dlhs = self
    #   Frhs = other

    #   res = feoarrm3n2_mul_RO(&Dlhs.arr,&Frhs.arr)

    # elif ( trhs  == dmat ):

    #   Flhs = self
    #   Drhs = other

    #   res = feoarrm3n2_mul_RO(&Drhs.arr,&Flhs.arr)

    elif ( tlhs  == onumm3n2_t ): # oF

      olhs = self
      Frhs = other

      res = feoarrm3n2_mul_oF(&olhs.num,&Frhs.arr)

    elif ( trhs  == onumm3n2_t ): # oF

      Flhs = self
      orhs = other

      res = feoarrm3n2_mul_oF(&orhs.num,&Flhs.arr)
    
    elif (tlhs in number_types): # rF
      
      Frhs = other
      res = feoarrm3n2_mul_rF(self, &Frhs.arr)

    elif (trhs in number_types): # Fr
        
      Flhs = self
      res = feoarrm3n2_mul_rF(other, &Flhs.arr)

    else:

      return NotImplemented

    # end if 
      
    return feoarrm3n2_t.create(&res)

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
    
    
    
    cdef feoarrm3n2_t res 
    cdef feoarrm3n2_t Flhs,Frhs
    cdef feonumm3n2_t  flhs,frhs
    cdef dmat    Dlhs,Drhs
    cdef onumm3n2_t olhs,orhs
    cdef oarrm3n2_t   Olhs,Orhs
    
    tlhs = type(self)
    trhs = type(other)
    
    if (tlhs == trhs):     # FF

      Flhs = self
      Frhs = other

      res = feoarrm3n2_div_FF(&Flhs.arr,&Frhs.arr)

    elif (tlhs == feonumm3n2_t): # fF

      flhs = self
      Frhs = other

      res = feoarrm3n2_div_fF(&flhs.num,&Frhs.arr)

    elif (trhs == feonumm3n2_t): # Ff

      Flhs = self
      frhs = other

      res = feoarrm3n2_div_Ff(&Flhs.arr,&frhs.num)

    elif (tlhs == oarrm3n2_t): # OF

      Olhs = self
      Frhs = other

      res = feoarrm3n2_div_OF(&Olhs.arr,&Frhs.arr)

    elif (trhs == oarrm3n2_t): # FO

      Flhs = self
      Orhs = other

      res = feoarrm3n2_div_FO(&Flhs.arr,&Orhs.arr)

    # elif ( tlhs  == dmat ):

    #   Dlhs = self
    #   Frhs = other

    #   res = feoarrm3n2_div_RO(&Dlhs.arr,&Frhs.arr)

    # elif ( trhs  == dmat ):

    #   Flhs = self
    #   Drhs = other

    #   res = feoarrm3n2_div_OR(&Drhs.arr,&Flhs.arr)

    elif ( tlhs  == onumm3n2_t ): # oF

      olhs = self
      Frhs = other

      res = feoarrm3n2_div_oF(&olhs.num,&Frhs.arr)

    elif ( trhs  == onumm3n2_t ): # Fo

      Flhs = self
      orhs = other

      res = feoarrm3n2_div_Fo(&Flhs.arr, &orhs.num)
    
    elif (tlhs in number_types): # rF
      
      Frhs = other
      res = feoarrm3n2_div_rF(self, &Frhs.arr)

    elif (trhs in number_types): # Fr
        
      Flhs = self
      res = feoarrm3n2_div_Fr( &Flhs.arr, other)

    else:

      return NotImplemented

    # end if 
      
    return feoarrm3n2_t.create(&res)

  #-----------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  def __pow__(self, n,z):
    """
    PURPOSE:      Power function overload

    res = self ** n

    """
    #*************************************************************************************************
    
    

    cdef feoarrm3n2_t res 
    cdef feoarrm3n2_t S = self

    res = feoarrm3n2_pow( &S.arr, n)
    
    return feoarrm3n2_t.create(&res)

  #---------------------------------------------------------------------------------------------------  

  #***************************************************************************************************
  cpdef set(self, object rhs):
    """
    PURPOSE:  Sets from another value.
    """
    #*************************************************************************************************
    

    cdef feonumm3n2_t  frhs
    cdef onumm3n2_t orhs
    cdef coeff_t rrhs

    cdef feoarrm3n2_t Frhs
    cdef oarrm3n2_t   Orhs
    cdef dmat    Rrhs

    trhs = type(rhs)

    if   trhs is onumm3n2_t:

      orhs = rhs
      feoarrm3n2_set_o( &orhs.num, &self.arr)

    elif trhs is feonumm3n2_t:

      frhs = rhs
      feoarrm3n2_set_f( &frhs.num, &self.arr)      

    # elif trhs is oarrm3n2_t:

    #   Orhs = rhs
    #   feoarrm3n2_set_O( &Orhs.arr, &self.arr)   

    # elif trhs is feoarrm3n2_t:

    #   Frhs = rhs
    #   feoarrm3n2_set_F( &Frhs.arr, &self.arr)   

    else:

      try:
      
        rrhs = rhs
        feoarrm3n2_set_r( rrhs, &self.arr)      
      
      except:
      
        raise ValueError("Supported values are real scalar, onumm3n2_t and feonumm3n2_t.")

      # end try

    # end if 

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  def gauss_integrate(self, feonumm3n2_t w  ):
    """
    PURPOSE: Get the corresponding derivative of the system.
    """
    #*************************************************************************************************
    

    cdef oarrm3n2_t res = oarrm3n2_init()

    res = feoarrm3n2_integrate( &self.arr, &w.num)

    return oarrm3n2_t.create(&res)

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  cpdef  truncate( self, object humdir):
    """
    PURPOSE:      to set a specific imaginary direction as given.

    """
    #*************************************************************************************************
    

    cdef imdir_t indx
    cdef ord_t  order
    cdef feoarrm3n2_t res
    
    indx, order = imdir(humdir)
    
    res = feoarrm3n2_truncate_im( indx, order, &self.arr) 

    return feoarrm3n2_t.create(&res)

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  cpdef  extract_im( self, object humdir):
    """
    PURPOSE:      to set a specific imaginary direction as given.

    """
    #*************************************************************************************************
    

    cdef imdir_t indx
    cdef ord_t  order
    cdef feoarrm3n2_t res
    
    indx, order = imdir(humdir)
    
    res = feoarrm3n2_extract_im( indx, order, &self.arr) 

    return feoarrm3n2_t.create(&res)

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  cpdef  extract_deriv( self, object humdir):
    """
    PURPOSE:      to set a specific imaginary direction as given.

    """
    #*************************************************************************************************
    

    cdef imdir_t indx
    cdef ord_t  order
    cdef feoarrm3n2_t res
    
    indx, order = imdir(humdir)
    
    res = feoarrm3n2_extract_deriv( indx, order, &self.arr) 

    return feoarrm3n2_t.create(&res)

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  cpdef  get_im( self, object humdir):
    """
    PURPOSE:      to set a specific imaginary direction as given.

    """
    #*************************************************************************************************
    

    cdef imdir_t indx
    cdef ord_t  order
    cdef feoarrm3n2_t res
    
    indx, order = imdir(humdir)
    
    res = feoarrm3n2_get_im( indx, order, &self.arr) 

    return feoarrm3n2_t.create(&res)

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  cpdef  get_ip( self, int64_t ip):
    """
    PURPOSE:      Get an Integration point.

    """
    #*************************************************************************************************
    

    cdef oarrm3n2_t res

    if (ip < 0):

      ip += self.nip

    # end if  

    if (ip > self.nip or ip < 0 ):

      raise IndexError("Index out of bounds for ip ({0:d}) and nip ({1:d}).".format(ip,self.nip))

    # end if

    res = feoarrm3n2_get_item_k( &self.arr, ip)
    
    return oarrm3n2_t.create(&res)

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  cpdef  get_item_ij( self, int64_t i, int64_t j, feonumm3n2_t out=None):
    """
    PURPOSE:      Get an item from feoarrm3n2_t array.

    """
    #*************************************************************************************************
    

    cdef feonumm3n2_t res;

    if ( i >= self.arr.nrows or  j >= self.arr.ncols ):
      raise IndexError("Index out of bounds for ({0:d},{1:d}) and shape {2}.".format(i,j,self.shape))
    # end if
    
    if out is None:
      res = feoarrm3n2_get_item_ij( &self.arr, i, j)
      return feonumm3n2_t.create(&res)
    else:
      feoarrm3n2_get_item_ij_to(  &self.arr, i,  j, &out.num)
    # end if 

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  cpdef  get_deriv( self, object humdir):
    """
    PURPOSE:      to set a specific imaginary direction as given.

    """
    #*************************************************************************************************
    

    cdef imdir_t indx
    cdef ord_t  order
    cdef feoarrm3n2_t res
    
    indx, order = imdir(humdir)
    
    res = feoarrm3n2_get_deriv( indx, order, &self.arr) 

    return feoarrm3n2_t.create(&res)

  #---------------------------------------------------------------------------------------------------
  
  #***************************************************************************************************
  cpdef  get_order_im(self, ord_t order):
    """
    PURPOSE: Get the corresponding derivative in the oarrm3n2_t object, as OTI number.
    """
    #*************************************************************************************************
    
    
    cdef feoarrm3n2_t res
    
    res = feoarrm3n2_get_order_im( order, &self.arr)

    return feoarrm3n2_t.create(&res)

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

    feoarrm3n2_get_active_bases( &self.arr, bases_list)

    res = []
    for i in range(size):

      if bases_list[i]==1:
      
        res.append(i+1)

      # end if 

    # end for 

    return res

  #---------------------------------------------------------------------------------------------------
  

# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# :::::::::::::::::::::::::::::::::::: END OF CLASS feoarrm3n2_t ::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

