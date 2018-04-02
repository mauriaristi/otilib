



# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::     CLASS  ndarray   ::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
cdef class ndarray:
  
  #---------------------------------------------------------------------------------------------------
  #------------------------------------   DEFINITION OF ATTRIBUTES   ---------------------------------
  #---------------------------------------------------------------------------------------------------
  
  #                                --->      Look in ndarray.pxd    <---

  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  def __cinit__(self, tuple shape = None, uint8_t maxorder = 0, uint16_t m = 1, object buffer = None): 
    """
    PURPOSE:      Constructor of a general array class. (dense arrays)

    DESCRIPTION:  Creates a new OTI vector given different types of constructors.

    

    ## Constructor 1: Dense constructor. ##

      DESCRIPTION: Creates a vector that will hold the elements given in the data arguments.

    Mandatory Keywords:
                  
                  shape:  Tuple representing shape.
                          Remark: All elements in D are considered to have the same order. 

                  maxorder: Maximum order of the elements that will be stored.



    Optional Keyword Arguments:

                  m:      Number of basis the array will allocate. In particular m=1.
                  buffer: Data to be transfered to the array. buffer = None, 
                          so by default it creates an empty array. TODO!
                  

                  
    """

    cdef uint64_t i, j, nImDir
    cdef uint64_t pointer_i

    # Determine the size of the array.

    # Number of imaginary directions:
    if maxorder == 0:
      
      raise ValueError("Unable to create OTI ndarray with maxorder 0.") # TODO: Allow non OTI numbers ...

    # end if 

    if shape == None:

      raise ValueError("Unable to create OTI ndarray with no specifyed shape.")

    # end if 
    
    self.shape = shape

    self.Ndir = h.getNels(m,maxorder)
    
    self.imshape = shape + (self.Ndir,) # TODO: Check which one is more efficient.

    if len(shape) >= 3:
    
      raise ValueError("Unable to create OTI array with dimensions greater or equal than 3")

    # end if 

    self.size = 1
    
    for i in range(<uint8_t>len(shape)):
      
      self.size *= self.shape[i]

    # end for
    
    self.data = np.empty( self.imshape, dtype = np.float64)

    pointer, read_only_flag = self.data.__array_interface__['data']
    # Get the pointer to the se.fldata array.
    pointer_i = <uint64_t> pointer
    self.p_data = <double*> pointer_i

    # self.p_data = <double*>malloc(self.size*sizeof(double))
    # if not self.p_data:
    #   raise MemoryError()
    # #end if 

    # if len(self.imshape) == 3:

    #   self.data = c_ptr_to_np_3darray_double(self.p_data, self.imshape[0], self.imshape[1],\
    #                   self.imshape[2],numpy_own = 0)

    # elif len(self.imshape) == 2:

    #   self.data = c_ptr_to_np_2darray_double(self.p_data, self.imshape[0], self.imshape[1],\
    #                   numpy_own = 0)
    # # end for

    # self.data.base =  <PyObject*>self

    self.order = maxorder

    self.m     = m
    
  #---------------------------------------------------------------------------------------------------
  
  # #***************************************************************************************************
  # def __dealloc__(self): 
  #   """
  #   PURPOSE:      Destructor of the class. 

  #   DESCRIPTION:  Frees all pointers allocated inside.
                  
  #   """
  #   #*************************************************************************************************
  #   print("Deallocating memory of ndarray.")
    
  #   free(self.p_data)
  #   self.p_data = NULL
  #   # del self.data

  # #---------------------------------------------------------------------------------------------------

  #*************************************************************************************************** 
  def __repr__(self):
    """
    PURPOSE:  To print a representation of the dualnum object that could be
              used to create new dualnum objects, in a compact form.
  
    EXAMPLE:  
              >>> spr_otinum([0,1,2,5],[1,2,3,4],2)
              spr_otinum([0,1,2,5],[1.,2.,3.,4.],2)
              
              >>> spr_otinum([0,1,2,4],[1,2,3,4],1)
              spr_otinum([0,1,2,4],[1.,2.,3.,4.],1)
    """
    #*************************************************************************************************

    # if len(self.imshape) == 3:

    #   data = c_ptr_to_np_3darray_double(self.p_data, self.imshape[0], self.imshape[1],\
    #                   self.imshape[2],numpy_own = 0)

    # elif len(self.imshape) == 2:

    #   data = c_ptr_to_np_2darray_double(self.p_data, self.imshape[0], self.imshape[1],\
    #                   numpy_own = 0)
    # # end if


    head      = 'otiarray( order = '+str(self.order)+ ",\n"
    body      = ''
    body += (np.array2string(self.data,separator=","))
    body += ' \n'

        
    tail = " )"
    return (head + body + tail)

  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  def __str__(self):
    """
    PURPOSE: To print a representation of the spr_otinum object that could 
             be easy to read and understand.  
    
    EXAMPLE:  
              >>> spr_otinum([0,1,2,5],[1,2,3,4],2)
              1.0 + 2.0 * e(1) + 3.0 * e([[1,2]]) + 4.0 * e([1,2])
              
              >>> spr_otinum([0,1,2,4],[1,2,3,4],1)
              1.0 + 2.0 * e(1) + 3.0 * e(2) + 4.0 * e(3)
    """
    #*************************************************************************************************
    
    # if len(self.imshape) == 3:

    #   data = c_ptr_to_np_3darray_double(self.p_data, self.imshape[0], self.imshape[1],\
    #                   self.imshape[2],numpy_own = 0)

    # elif len(self.imshape) == 2:

    #   data = c_ptr_to_np_2darray_double(self.p_data, self.imshape[0], self.imshape[1],\
    #                   numpy_own = 0)
    # # end if

    head = ''
    body = (np.array2string(self.data,separator=","))
    tail = ''
    
    return (head + body + tail)

  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  def __getitem__(self, index):
    """
    PURPOSE:  To get the value of one oti of the array.

    """
    #*************************************************************************************************
    
    
    # if type(index) == int or type(index) == slice:
    
    #   tuple_indx = (index,)
    
    # else:
    
    #   tuple_indx = index
    
    # # end if 
    #                                           # this only gets one dimension, not tuples or slices...
    
    # cdef double[::1] coefs = self.data[index] # be careful with the dimensions... 
    
    cdef otinum_t res
    cdef uint64_t i, matIndex
    # cdef uint64_t matIndex = 0
    type1 = type(index)
    # print(type1)
    if type1 in int_types:
      # print("we are here")
      matIndex = <uint64_t>index*self.Ndir
      # print(matIndex)
    else:
      # print("we are not here")
      matIndex = self.Ndir*(index[ZERO]*self.shape[ONE]+index[ONE])
    # end if 

    res.p_coefs = &self.p_data[matIndex]
    # print(matIndex)
    # res.p_coefs = &coefs[0]
    
    # res.p_coefs = <double*> malloc(self.Ndir*sizeof(double))
    # if not res.p_coefs:
    #   raise MemoryError()
    # # end if 

    # for i in range(self.Ndir):
    #   res.p_coefs[i] = self.data[index][i]
    # # end for


    res.order = self.order
    res.Ndir = self.Ndir

    # print(res.order)
    # print(res.Ndir)
    # This is very rudimentary


    return otinum.create(&res, FLAGS = 0)
    

  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  def __setitem__(self, index, value):
    """
    PURPOSE:  To set the value of a of one oti number in the array.

    """
    #*************************************************************************************************
    cdef uint64_t i, matIndex
    cdef otinum val
    type1 = type(value)

    if type1 == otinum:
      val = value
      if val.num.Ndir != self.Ndir:
        raise ValueError("Both array and oti number must have the same dimensions.")
      # end if 
      
      type2 = type(index)

      if type2 in int_types:

        matIndex = index*self.Ndir

      else:

        matIndex = self.Ndir*(index[ZERO]*self.shape[ONE]+index[ONE])
        
      # end if 

      for i in range(self.Ndir):

        self.p_data[matIndex+i] = val.num.p_coefs[i] # this must have the same dimensions....

      # end for

    # end if 

  #--------------------------------------------------------------------------------------------------- 






  #***************************************************************************************************
  def getDual(self, dirArray):
    """
    PURPOSE:      To add a human friendly form to get elements from a 
                  spr_otinum.
    
    EXAMPLE:      >>> a = spr_otinum([0,4,17], [1.,3.,5.], 2)
                  >>> print(a)
                  1.0 + 3.0 * e([2]) + 5.0 * e([1,3])
                  >>> a.getDual([1,3])
                  5.0
                  >>> a.getDual([1])
                  0.0
    """
    #*************************************************************************************************


    global h
    global p_dH

    cdef uint8_t order
    cdef uint16_t* p_dirA
    cdef uint8_t* p_expA
    cdef uint8_t i
    cdef uint64_t indx


    if type(dirArray)==int:
    
      indxArray = [dirArray]

    else:

      indxArray = dirArray
      
    # end if

    c_getDirExpA(indxArray, &p_dirA, &p_expA, &order)

    if order > self.order:
      
      return np.zeros(self.shape,dtype = np.float64)
    
    # end if

    if order == 0:
        
      indx = 0

    elif self.order == 1:

      indx = indxArray[0]

    else:

      indx = h.c_findIndx(p_dirA,p_expA,self.order)

    # end if


    if len(self.shape) == 1:

      return self.data[:,indx]

    else:

      return self.data[:,:,indx]

    # end if 
  #--------------------------------------------------------------------------------------------------- 

  #***************************************************************************************************
  cpdef np.ndarray c_getByIndx(self, uint64_t indx):
    """
    PURPOSE:      To add a fast manner to get all elements of a specified direction. 

    """
    #*************************************************************************************************



    if indx <  self.Ndir:

      if len(self.shape) == 1:

        return self.data[:,indx]

      else:

        return self.data[:,:,indx]

      # end if 

    else:

      raise IndexError("Index Out of bounds.")

    # end if
  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  cpdef void c_setByIndx(self, uint64_t indx, np.ndarray value):
    """
    PURPOSE:      To add a fast manner to set all elements of a specified direction. 

    """
    #*************************************************************************************************



    if indx <  self.Ndir:

      if len(self.shape) == 1:

        self.data[:,indx] = value

      else:

        self.data[:,:,indx] = value

      # end if 

    else:

      raise IndexError("Index Out of bounds.")

    # end if
  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  def getDeriv(self, dirArray):
    """
    PURPOSE:      to retrieve the n'th derivative according to the taylor 
                  series expansion with dual numbers.
                
    DESCRIPTION:  Simply given the combinations of derivatives with the 
                  dirArray, the function multiplys the terms that require
                  extra factors to get the desired derivatives.
    
    EXAMPLE:      >>> a = spr_otinum([0,1,2,4,5,8],[1,2,3,4,5,6],2)
                  >>>
                  >>> getDerivative(a,[0])
                  1.
                  >>> getDerivative(a,[1])
                  2.
                  >>> getDerivative(a,[[1,2]])
                  6.
                  >>> getDerivative(a,[2])
                  4.
                  >>> getDerivative(a,[1,2])
                  5.
                  >>> getDerivative(a,[[2,2]])
                  12.

    """
    #*************************************************************************************************

    global h
    global p_dH

    cdef uint8_t order
    cdef uint16_t* p_dirA
    cdef uint8_t* p_expA
    cdef uint8_t i
    cdef uint64_t indx
    cdef double factor = 1.0


    if type(dirArray)==int:
    
      indxArray = [dirArray]

    else:

      indxArray = dirArray
      
    # end if

    c_getDirExpA(indxArray, &p_dirA, &p_expA, &order)

    if order > self.order:
      
      return np.zeros(self.shape,dtype = np.float64)
    
    # end if

    if order == 0:
        
      indx = 0

    elif self.order == 1:

      indx = indxArray[0]

    else:

      indx = h.c_findIndx(p_dirA,p_expA,self.order)

    # end if

    for i in range(order):
      
      factor*= c_fastfact(p_expA[i])
      
      if p_expA[i]==0:
        
        break

      # end if

    # end for


    if len(self.shape) == 1:

      return self.data[:,indx]*factor

    else:

      return self.data[:,:,indx]*factor

    # end if 
  #---------------------------------------------------------------------------------------------------  

# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# :::::::::::::::::::::::::::::::::::: End of class ndarray ::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::





 

















#*****************************************************************************************************
cpdef ndarray zeros(shape = None , uint8_t maxorder = 1 , uint16_t m = 1):
  """
  PURPOSE: Create a ndarray filled with zeros.

  """
  #***************************************************************************************************

  cdef tuple finalShape
  cdef ndarray res 
  cdef uint64_t i,j,k,l
  cdef float64_t value = 0.

  if type(shape) == int:
    
    finalShape = (shape,)

  else:
    
    finalShape = shape

  # end if 

  res = ndarray(shape = finalShape,  m = m, maxorder = maxorder ) 

  # memset(res.p_data,0,res.size*res.Ndir*sizeof(double))
  res.data[:] = value

  return res

#-----------------------------------------------------------------------------------------------------