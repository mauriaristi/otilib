

# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::     CLASS  sndarray   ::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
cdef class sndarray:

  #---------------------------------------------------------------------------------------------------
  #------------------------------------   DEFINITION OF ATTRIBUTES   ---------------------------------
  #---------------------------------------------------------------------------------------------------
  
  cdef sotiarray_t array

  
  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  def __init__(self, tuple shape = None, uint8_t order = 0): 
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
    cdef uint64_t pointer_i, ldim = len(shape)

    # Determine the size of the array.

    # Number of imaginary directions:
    if order == 0:
      
      raise ValueError("Unable to create OTI ndarray with order 0.") # TODO: Allow non OTI numbers ...

    # end if 

    if shape == None:

      raise ValueError("Unable to create OTI ndarray with no specifyed shape.")

    # end if 
    
    if ldim >= 3 and ldim == 0:
    
      raise ValueError("Unable to create OTI array with dimensions greater or equal than 3")

    # end if 
    
    if ldim == 2:

      c_sotiarray_createEmpty(&self.array, shape[0], shape[1], order)
      
    else:

      c_sotiarray_createEmpty(&self.array, shape[0],        1, order)

    # end if 

    
  #---------------------------------------------------------------------------------------------------


  #***************************************************************************************************
  def __dealloc__(self): 
    """
    PURPOSE:      Destructor of the class. 

    DESCRIPTION:  Frees all pointers allocated inside.
                  
    """
    #*************************************************************************************************
    # print("trying to free sotiarray")
    # print(self)
    c_sotiarray_free(&self.array)
    # print("successfuly freed sotiarray")
    
  #---------------------------------------------------------------------------------------------------


  #***************************************************************************************************
  @staticmethod
  cdef sndarray create(sotiarray_t* array):
    """
    PURPOSE:      C-level constructor of the sotiarray class. Use this when creating arrays within 
                  Cython

    DESCRIPTION:  Creates a new OTI matrix given a c-level sotiarray_t type.

    PARAMETERS:
                 
                  num:  Array to be referenced in python     

    RESULT:       
            A new otinum python object is created
                  
    """
    #*************************************************************************************************

    # create new empty object:
    cdef sndarray otiarr = <sndarray> sndarray.__new__(sndarray)

    otiarr.array = array[0]     # Copy data
    
    return otiarr

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  def tondarray(self):
    """
    PURPOSE:      convert array to ndarray.

    """
    #*************************************************************************************************

    global h
    cdef uint64_t i,j,k, pos,maxdir=0, numsize, indx
    cdef double val
    cdef sotinum_t num

    
    maxdir = self.Ndir 
    
    shape = self.shape
    
    if shape[1] == 1:
      shape = (shape[0],)
    # end if 
    
    m = h.findMaxDir(maxdir,self.array.order)

    
    cdef ndarray res = zeros(shape = shape, maxorder = self.array.order, m = m )

    
    if len(shape) == 1:
      
      for k in range(self.array.size):
        
        # print("k: ", k)
        
        num = self.array.p_data[k]
        
        # print("num: ", c_soti_print(&num) )
        
        for j in range(num.size):

          indx = num.p_indx[j]
          val = num.p_coefs[j]
          # print("setting position ",k,",",indx," as ",val)
          res.data[k,indx] = val

        # end for 

      # end for
    # end if 
    
    return res

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  @property
  def Ndir(self):
    """
    PURPOSE:      Get the maximum number of directions in the array.

    """
    #*************************************************************************************************

    cdef uint64_t k, maxdir=0, numsize
    cdef sotinum_t num
    # first search maximum im direction
    # print("Computing Max direction of array with size: ", self.array.size)
    for k in range(self.array.size):
      # print("k: ", k)
      num = self.array.p_data[k]
      # print("num: ", c_soti_print(&num) )
      numsize = num.size
      if numsize != 0:
        # print("maxDir: ", num.p_indx[numsize-1])
        maxdir = max(num.p_indx[numsize-1],maxdir)
      # end if 
    # end for 

    return maxdir

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
    
    cdef np.ndarray res = np.empty(( self.array.nrows,self.array.ncols),dtype = np.float64)

    for k in range(self.array.size):
      
      val = 0.0
      
      if self.array.p_data[k].size != 0:
        
        if self.array.p_data[k].p_indx[0] == 0:

          val = self.array.p_data[k].p_coefs[0]

        # end if 
      
      # end if 

      i = k//self.array.ncols
      j = k%self.array.ncols
      res[i,j] = val

    # end for
    
    return res

  #---------------------------------------------------------------------------------------------------


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
    cdef sotinum soti = <sotinum> sotinum.__new__(sotinum)
    cdef uint64_t i,j


    soti.FLAGS = 0




    head      = 'sotiarray( order = '+str(self.array.order)+ ",\n"
    
    body      = 'shape = ('+str(self.array.nrows)+','+str(self.array.ncols)+"),\n"

    for i in range(self.array.nrows):
    
      for j in range(self.array.ncols):
        
        soti.num = self.array.p_data[j+i*self.array.ncols]
        body += "("
        body += str(i)+","
        body += str(j)
        body += ") "
        body += str(soti)
        body+="\n"

        if (j+i*self.array.ncols>15):
          break
        # end if 
      
      # end for 
      
      if (j+i*self.array.ncols>15):
        body+="...\n"
        break
      # end if 
    
    # end for 
        
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

    cdef sotinum soti = <sotinum> sotinum.__new__(sotinum)
    cdef uint64_t i,j

    soti.FLAGS = 0

    # print("size: " ,self.array.size)

    head = 'sotiarray( order = '+str(self.array.order)+ ",\n"
    
    body = 'shape = ('+str(self.array.nrows)+','+str(self.array.ncols)+"),\n"

    for i in range(self.array.nrows):
    
      for j in range(self.array.ncols):
        
        soti.num = self.array.p_data[j+i*self.array.ncols]

        # print("("+str(i)+","+str(j)+") ", j+i*self.array.ncols)
        
        # print("num.order:   " ,soti.num.order            )
        # print("num.size:    " ,soti.num.size             )
        # print("num.p_coefs: " ,<uint64_t>soti.num.p_coefs)
        # print("num.p_indx:  " ,<uint64_t>soti.num.p_indx )
        
        body += "("
        body += str(i)+","
        body += str(j)
        body += ") "
        body += str(soti)
        body+="\n"
      
      # end for       
    
    # end for 
        
    tail = " )"
    return (head + body + tail)

  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  def __setitem__(self, index, value):
    """
    PURPOSE:  To set the value of a of one oti number in the array.

    """
    #*************************************************************************************************
    cdef uint64_t i, j, matIndex
    cdef sotinum val
    cdef sotinum_t vali
    
    type1 = type(value)
    type2 = type(index)

    if type1 == sotinum:

      val = value 
      
      # type2 = type(index)

      if type2 in int_types:

        i = index // self.array.ncols
        j = index %  self.array.ncols

      else:

        i = index[ZERO]
        j = index[ONE] 

      # end if 

      if (i<self.array.nrows and j<self.array.ncols):

        # First copy the value
        c_soti_copy(&vali,&val.num)

        # Assign the new value to the array.
        c_sotiarray_setItemOTI( &vali, i, j, &self.array)

      # end if 

    elif type1 in number_types:

      
      if type2 in int_types:

        i = index // self.array.ncols
        j = index %  self.array.ncols

      else:        

        i = index[ZERO]
        j = index[ONE] 

      # end if 

      if ( i<self.array.nrows and j<self.array.ncols):
        
        c_sotiarray_setItemR(value,i, j, &self.array)

      # end if 

    # end if 

  #--------------------------------------------------------------------------------------------------- 

  #***************************************************************************************************
  def __getitem__(self, index):
    """
    PURPOSE:  To set the value of a of one oti number in the array.

    """
    #*************************************************************************************************
    cdef uint64_t i, j, matIndex
    cdef sotinum_t res

    res.size  = 0
    res.order = 1

    type1 = type(index)

    if type1 == tuple:
      
      if len(index)<=2:
        
        i = index[ZERO]
        j = index[ONE]

        if ( i<self.array.nrows and j<self.array.ncols):
          # print(i,j)
          # c_sotiarray_getItem(&self.array, i, j, &res)
          res = self.array.p_data[j+i*self.array.ncols]
        else:

          raise IndexError("Index out of bounds.")

        # end if 
      
      else:
      
        raise IndexError("No more than 2 dimensions for sndarray")

      # end if 

    elif type1 in int_types:

      i = index // self.array.ncols
      j = index %  self.array.ncols

      if ( i<self.array.nrows and j<self.array.ncols):
        # print(i,j)
        c_sotiarray_getItem(&self.array, i, j, &res)

      else:

        raise IndexError("Index out of bounds.")  
        
      # end if 

    # end if 

    return sotinum.create(&res,FLAGS=0) # initialize without owning data.

  #--------------------------------------------------------------------------------------------------- 


  #***************************************************************************************************
  def __neg__(self):
    """
    PURPOSE:      To define how to sum two otinum numbers.

    DESCRIPTION:  It overloads the sum operator "+". It allows the addition
                  of oti numbers of different orders, or even the 
                  addition of a oti number and a scalar. 
    
    EXAMPLE:      >>> a = otinum( [1.,3.,5.], 2)
                  >>> b = otinum( [7.,9.,11.], 2)
                  >>> a + b
                  otinum( [8.,12.,16.], 2)
                  
                  >>> a = otinum([1.,3.,5.], 2)
                  >>> a + 15
                  otinum([16.,3.,5.], 2)


    EXAMPLE:
                  >>> a = otinum( [1.,3.,5.], 2)
                  >>> b = otinum( [7.,9.,11.], 2)
                  >>> a.sum(b)
                  otinum( [8.,12.,16.], 2)

                  >>> a = otinum([1.,3.,5.], 2)
                  >>> a.sumr(15)   # Accepts everything
                  otinum([16.,3.,5.], 2)
    """
    #*************************************************************************************************
    
    cdef sotiarray_t res
    res.p_data = NULL # Init res as undefined
    
    c_sotiarray_neg(&self.array, &res)

    return sndarray.create(&res)

  #--------------------------------------------------------------------------------------------------- 

  #***************************************************************************************************
  def __add__(self, other_in):
    """
    PURPOSE:      To define how to sum two otinum numbers.

    DESCRIPTION:  It overloads the sum operator "+". It allows the addition
                  of oti numbers of different orders, or even the 
                  addition of a oti number and a scalar. 
    
    EXAMPLE:      >>> a = otinum( [1.,3.,5.], 2)
                  >>> b = otinum( [7.,9.,11.], 2)
                  >>> a + b
                  otinum( [8.,12.,16.], 2)
                  
                  >>> a = otinum([1.,3.,5.], 2)
                  >>> a + 15
                  otinum([16.,3.,5.], 2)


    EXAMPLE:
                  >>> a = otinum( [1.,3.,5.], 2)
                  >>> b = otinum( [7.,9.,11.], 2)
                  >>> a.sum(b)
                  otinum( [8.,12.,16.], 2)

                  >>> a = otinum([1.,3.,5.], 2)
                  >>> a.sumr(15)   # Accepts everything
                  otinum([16.,3.,5.], 2)
    """
    #*************************************************************************************************
    global h
    global p_dH
    
    cdef: 
      uint64_t i = 0
      sotiarray_t res
      sndarray S
      sndarray O
      sotinum   soti

    res.p_data = NULL # Init res as undefined

    type1 = type(self)     # takes 100 ns ... 
    type2 = type(other_in) # takes 100 ns ...

    # type1 = self.__class__     # takes ~50 ns ... 
    # type2 = other_in.__class__ # takes ~50 ns ...


    if ( type1 == type2) : # Case Sum between two arrays.

      S = self
      O = other_in

      if S.array.nrows != O.array.nrows and S.array.ncols != O.array.ncols :
        
        raise ValueError("Sizes must be the same for sum operation.")

      # end if

      c_sotiarray_matsum_otioti(&S.array, &O.array, &res, p_dH)

      return sndarray.create(&res)

    elif (type2 == sotinum): # Case Sum to sotinum

      S = self
      soti = other_in
      c_sotiarray_sum_oti(&S.array, &soti.num, &res, p_dH)

      return sndarray.create(&res)

    elif (type1 == sotinum): # Case Sum to sotinum

      soti = self
      O = other_in
      c_sotiarray_sum_oti(&O.array, &soti.num, &res, p_dH)

      return sndarray.create(&res)


    elif (type2 in number_types): # Case Sum to real number. Very slow, consider changing this...
      
      S = self
      c_sotiarray_sum_R( &S.array, np.float64(other_in), &res)

      return sndarray.create(&res)

    elif (type1 in number_types): # Case 1.5. reverse Sum to real number.
      
      O = other_in
      c_sotiarray_sum_R( &O.array, np.float64(self), &res)

      return sndarray.create(&res)

    else: 

      raise TypeError("Unsupported type.")

    # end if  

    # end if. Type cases.

  #---------------------------------------------------------------------------------------------------  

  #***************************************************************************************************
  def __sub__(self, other_in):
    """
    PURPOSE:      To define how to sum two otinum numbers.

    DESCRIPTION:  It overloads the sum operator "+". It allows the addition
                  of oti numbers of different orders, or even the 
                  addition of a oti number and a scalar. 
    
    EXAMPLE:      >>> a = otinum( [1.,3.,5.], 2)
                  >>> b = otinum( [7.,9.,11.], 2)
                  >>> a + b
                  otinum( [8.,12.,16.], 2)
                  
                  >>> a = otinum([1.,3.,5.], 2)
                  >>> a + 15
                  otinum([16.,3.,5.], 2)


    EXAMPLE:
                  >>> a = otinum( [1.,3.,5.], 2)
                  >>> b = otinum( [7.,9.,11.], 2)
                  >>> a.sum(b)
                  otinum( [8.,12.,16.], 2)

                  >>> a = otinum([1.,3.,5.], 2)
                  >>> a.sumr(15)   # Accepts everything
                  otinum([16.,3.,5.], 2)
    """
    #*************************************************************************************************
    global h
    global p_dH
    
    cdef: 
      uint64_t i = 0
      sotiarray_t res
      sndarray S
      sndarray O
      sotinum   soti

    res.p_data = NULL # Init res as undefined

    type1 = type(self)     # takes 100 ns ... 
    type2 = type(other_in) # takes 100 ns ...

    # type1 = self.__class__     # takes ~50 ns ... 
    # type2 = other_in.__class__ # takes ~50 ns ...


    if ( type1 is type2) : # Case Sum between two arrays.

      S = self
      O = other_in

      if S.array.nrows != O.array.nrows and S.array.ncols != O.array.ncols :
        
        raise ValueError("Sizes must be the same for sum operation.")

      # end if

      c_sotiarray_matsub_otioti(&S.array, &O.array, &res, p_dH)

      return sndarray.create(&res)

    elif (type2 is sotinum): # Case Sum to sotinum

      S = self
      soti = other_in
      c_sotiarray_sub_oti(&S.array, &soti.num, &res, p_dH)

      return sndarray.create(&res)

    elif (type1 is sotinum): # Case Sum to sotinum

      soti = self
      O = other_in
      c_sotiarray_oti_sub(&O.array, &soti.num, &res, p_dH)

      return sndarray.create(&res)


    elif (type2 in number_types): # Case Sum to real number. Very slow, consider changing this...
      
      S = self
      c_sotiarray_sub_R( &S.array, np.float64(other_in), &res)

      return sndarray.create(&res)

    elif (type1 in number_types): # Case 1.5. reverse Sum to real number.
      
      O = other_in
      c_sotiarray_R_sub( &O.array, np.float64(self), &res)

      return sndarray.create(&res)

    else: 

      raise TypeError("Unsupported type.")

    # end if  

    # end if. Type cases.

  #--------------------------------------------------------------------------------------------------- 

  #***************************************************************************************************
  def __mul__(self, other_in):
    """
    PURPOSE:      To define how to multiply arrays of sparse oti numbers.

    DESCRIPTION:  It overloads the sum operator "*". It allows the addition
                  of oti numbers of different orders, or even the 
                  addition of a oti number and a scalar. 
    
    EXAMPLE:      >>> a = otinum( [1.,3.,5.], 2)
                  >>> b = otinum( [7.,9.,11.], 2)
                  >>> a + b
                  otinum( [8.,12.,16.], 2)
                  
                  >>> a = otinum([1.,3.,5.], 2)
                  >>> a + 15
                  otinum([16.,3.,5.], 2)

    """
    #*************************************************************************************************
    global h
    global p_dH
    
    cdef: 
      uint64_t i = 0
      sotiarray_t res
      sndarray S
      sndarray O
      sotinum   soti

    res.p_data = NULL # Init res as undefined

    type1 = type(self)     # takes 100 ns ... 
    type2 = type(other_in) # takes 100 ns ...

    # type1 = self.__class__     # takes ~50 ns ... 
    # type2 = other_in.__class__ # takes ~50 ns ...


    if ( type1 is type2) : # Case mul between two arrays.

      # raise TypeError("Unsupported type.")

      S = self
      O = other_in

      if S.array.nrows != O.array.nrows and S.array.ncols != O.array.ncols :
        
        raise ValueError("Sizes must be the same for element wise mul operation.")

      # end if

      c_sotiarray_mul_sotiarr(&S.array, &O.array, &res, p_dH)

      return sndarray.create(&res)

    elif (type2 is sotinum): # Case Sum to sotinum

      S = self
      soti = other_in
      c_sotiarray_mul_oti(&S.array, &soti.num, &res, p_dH)

      return sndarray.create(&res)

    elif (type1 is sotinum): # Case Sum to sotinum

      soti = self
      O = other_in
      c_sotiarray_mul_oti(&O.array, &soti.num, &res, p_dH)

      return sndarray.create(&res)


    elif (type2 in number_types): # Case Sum to real number. Very slow, consider changing this...
      
      S = self
      c_sotiarray_mul_R( &S.array, np.float64(other_in), &res)

      return sndarray.create(&res)

    elif (type1 in number_types): # Case 1.5. reverse Sum to real number.
      
      O = other_in
      c_sotiarray_mul_R( &O.array, np.float64(self), &res)

      return sndarray.create(&res)

    else: 

      raise TypeError("Unsupported type.")

    # end if  

    # end if. Type cases.

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  @property 
  def T(self):
    """
    PURPOSE:      To define array transpose.

    DESCRIPTION:  Transpose of array

    """
    #*************************************************************************************************
    
    cdef sotiarray_t res

    res.p_data = NULL

    c_sotiarray_transpose(&self.array, &res)

    return sndarray.create(&res)

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  @property 
  def shape(self):
    """
    PURPOSE:      To get the shape of the array.


    """
    #*************************************************************************************************
    
    return (self.array.nrows,self.array.ncols)

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  def __truediv__(self, other_in):
    """
    PURPOSE:      To define how to divide two spr_otinum numbers.
    
    DESCRIPTION:  It overloads the division operator "/". It allows the
                  division of spr_otinum numbers of different orders, and 
                  the division of a spr_otinum number and a scalar. 

    EXAMPLE:      >>> a = spr_otinum([0,4,17], [1.,3.,5.], 2)
                  >>> b = spr_otinum([0,2,4], [7.,9.,11.], 2)
                  >>> a/b
                  spr_otinum([0,2,4,8,17], [0.14285714,-0.18367347,
                                    0.20408163,-0.32069971,0.71428571], 2)
    """
    #*************************************************************************************************
    
    
    global h
    global p_dH

    cdef sndarray S
    cdef sndarray O
    cdef sotinum  soti
    cdef sotiarray_t res

    res.p_data = NULL # Init res as undefined

    type1 = type(self)     # takes 100 ns ... 
    type2 = type(other_in) # takes 100 ns ...

    if type1 == type2:   # Case 2. Mult to spr_otinum.
      
      S = self
      O = other_in

      c_sotiarray_matdiv_otioti(&S.array, &O.array, &res, p_dH) 

    
    elif type2 is sotinum:
      
      soti = other_in
      S = self

      c_sotiarray_div_oti(&S.array, &soti.num, &res, p_dH)

    elif type1 is sotinum:
      
      soti = self
      S = other_in
      
      c_sotiarray_oti_div(&S.array, &soti.num, &res, p_dH)
    
    elif type2 in number_types:   # Case 1. Mult to real scalar. 
      
      S = self
      
      c_sotiarray_div_R(&S.array, np.float64(other_in), &res) 
    
    elif type1 in number_types:   # Case 1.5. Reverse Mult to real scalar.
      
      S = other_in
      
      c_sotiarray_R_div( &S.array, np.float64(self), &res, p_dH)
      
    # End if. Type cases.

    return sndarray.create(&res)

  #---------------------------------------------------------------------------------------------------







# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# :::::::::::::::::::::::::::::::::::: End of class sndarray :::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::




#*****************************************************************************************************
cpdef sndarray spzeros(shape = None , uint8_t order = 1 ):
  """
  PURPOSE: Create a sndarray filled with zeros.

  """
  #***************************************************************************************************

  cdef uint64_t ncols=1, nrows=1
  cdef sotiarray_t array

  if type(shape) == int:
    
    nrows = shape
    ncols = 1

  else:
    
    if len(shape)==1:
      
      nrows = shape[0]
      ncols = 1
    
    elif len(shape) == 2:
      
      nrows = shape[0]
      ncols = shape[1]

    else:

      raise ValueError("Unable to create OTI array with dimensions greater or equal than 3")

    # end if

  # end if 
  
  c_sotiarray_zeros(&array, nrows, ncols, order)
  
  return sndarray.create(&array)

#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cpdef sndarray sarray( pyarray, uint8_t order = 1 ):
  """
  PURPOSE: Create a sndarray out of a list of numbers, a list of sotinum or a numpy array.

  Maximum dimension supported: 2.

  """
  #***************************************************************************************************

  cdef uint64_t ncols=1, nrows=1, ndim, i 
  cdef sotiarray_t array
  cdef sotinum_t tmp
  cdef double data
  cdef np.ndarray pyarrayin = np.array(pyarray,dtype=np.float64)

  # Check if the data type is 

  ndim = pyarrayin.ndim
  
  if ndim<=2:
    
    nrows = pyarrayin.shape[0]
    
    if ndim == 2:

      ncols = pyarrayin.shape[1]

    # End if

    c_sotiarray_createEmpty(&array, nrows, ncols, order)

    for i in range(nrows):

      for j in range(ncols):

        if  ndim == 2:
        
          data = pyarrayin[i,j]
        
        else:
        
          data = pyarrayin[i]
        
        # end if 
        
        if data != 0.0:
        
          c_soti_createEmpty(&tmp,1,order)
          tmp.p_coefs[0] = data
          tmp.p_indx[0]  = 0
        
        else:
        
          c_soti_createEmpty(&tmp,0,order)

        # end if 
        array.p_data[j+i*array.ncols] = tmp

      # end for

    # end for

    return sndarray.create(&array)

  else:

    raise ValueError("Can't create arrays of more than 2 dimensions.")

  # end if

#-----------------------------------------------------------------------------------------------------


#*****************************************************************************************************
cpdef sndarray dot( arr1, arr2 ):
  """
  PURPOSE: perform inner matrix product pf sotinum arrays.
  
  Maximum dimension supported: 2.
  
  """
  #***************************************************************************************************
  
  global p_dH
  
  cdef uint64_t ncols=1, nrows=1, ndim, i 
  cdef sotiarray_t array
  # cdef double data
  cdef np.ndarray nparray
  cdef darray_t darray
  cdef uint64_t ptr_int 
  cdef sndarray sarr1, sarr2

  array.p_data = NULL
  
  type1 = type(arr1)
  type2 = type(arr2)
  
  # handle error from outside:
  if ( type1 == type2 and type1 == sndarray ):
  
    sarr1 = arr1
    sarr2 = arr2
  
    if sarr1.array.nrows == sarr2.array.ncols:
    
      c_sotiarray_matmul_otioti(&sarr1.array, &sarr2.array, &array, p_dH)
  
    else:
  
      raise ValueError("Shapes not aligned.")
  
    # end if 
  
    return sndarray.create(&array)

  elif type2 == np.ndarray :

    sarr1 = arr1
    nparray = arr2

    ptr_int, read_only_flag = nparray.data.__array_interface__['data']
    # Get the pointer to the  array.
    # ptr_int = <uint64_t> pointer
    darray.p_data = <double*> ptr_int
    darray.nrows = nparray.shape[0]
    darray.ncols = 1

    if nparray.ndim == 2:
      
      darray.ncols = nparray.shape[1]

    # end if 

    darray.size = darray.nrows*darray.ncols

    if sarr1.array.ncols != nparray.nrows:

      raise ValueError("Shapes not aligned.")

    # end if 

    c_sotiarray_matmul_otiR(&sarr1.array, &darray, &array, p_dH)

    return sndarray.create(&array)

  elif type1 == np.ndarray :

    nparray = arr1
    sarr1 = arr2

    ptr_int, read_only_flag = nparray.data.__array_interface__['data']
    # Get the pointer to the  array.
    # ptr_int = <uint64_t> pointer
    darray.p_data = <double*> ptr_int
    darray.nrows = nparray.shape[0]
    darray.ncols = 1

    if nparray.ndim == 2:
      
      darray.ncols = nparray.shape[1]

    # end if 

    darray.size = darray.nrows*darray.ncols

    if sarr1.array.nrows != nparray.ncols:

      raise ValueError("Shapes not aligned.")

    # end if 

    c_sotiarray_matmul_Roti( &darray, &sarr1.array, &array, p_dH)

    return sndarray.create(&array)

  else:

    raise TypeError("Unsupported type.")
  
  # end if
  
#-----------------------------------------------------------------------------------------------------


#*****************************************************************************************************
cpdef sotinum det( sndarray arr1 ):
  """
  PURPOSE: determinant of array.
  
  Maximum dimension supported: 2.
  
  """
  #***************************************************************************************************
  
  global p_dH
  
  cdef sotinum_t res

  if arr1.array.ncols != arr1.array.nrows:
    raise ValueError("Incompatible shape of array. Must be squared.")
  # end if 

  if arr1.array.ncols > 3:
    raise ValueError("Maximum supported matrix size: 3x3.")
  # end if 

  c_sotiarray_det(&arr1.array, &res, p_dH)

  return sotinum.create(&res)

#-----------------------------------------------------------------------------------------------------



#*****************************************************************************************************
cpdef sndarray inv( sndarray arr1 ):
  """
  PURPOSE: inverse of array. Only works for arrays of square size 2 and 3.
  
  
  """
  #***************************************************************************************************
  
  global p_dH
  
  cdef sotiarray_t res

  res.p_data = NULL

  if arr1.array.ncols != arr1.array.nrows:
    raise ValueError("Incompatible shape of array. Must be square matrix.")
  # end if 

  if arr1.array.ncols > 3:
    raise ValueError("Maximum supported matrix size: 3x3.")
  # end if 

  c_sotiarray_invert(&arr1.array, &res, p_dH)

  return sndarray.create(&res)

#-----------------------------------------------------------------------------------------------------




#***************************************************************************************************** 
cdef str c_sotiarray_print(sotiarray_t* array, style = 1):
  """
  PURPOSE:  To print a representation of the sotiarray object that could be
            used to create new dualnum objects, in a compact form.

  
  """
  #***************************************************************************************************
  
  cdef uint64_t i,j


  head = 'sotiarray('
  body = '['

  for i in range(array[0].nrows):
    if i!=0:
      body+="           "
    # end if 
    body+='['

    for j in range(array[0].ncols):
      
      body += " "
      

      body += c_soti_print(&array[0].p_data[j+i*array[0].ncols])
      
      
      body+=","
    
    # end for 
    body = body[:len(body)-1]
    body += "],\n"

  # end for 
      
  body  = body[:len(body)-2]
  body += "]"
  body += ' order = '+str(array[0].order)+ ", "
  body += 'shape = ('+str(array[0].nrows)+','+str(array[0].ncols)+") "

  tail = " )\n"
  return (head + body + tail)

#-----------------------------------------------------------------------------------------------------

