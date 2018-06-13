




# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::     CLASS  OTINUM    ::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
cdef class otinum:
  """
  OTI number class (and type). 

  .. note::
    An example of a note

  """
  #---------------------------------------------------------------------------------------------------
  #------------------------------------   DEFINITION OF ATTRIBUTES   ---------------------------------
  #---------------------------------------------------------------------------------------------------
  
  #                                --->      Look in otinum.pxd    <---

  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  def __init__(self, coefs, uint8_t order,uint16_t m = 1,uint8_t FLAGS = 1): # not _cinit_ to avoid creation with _new_
    """
    PURPOSE:      Python level constructor of the otinum class.

    DESCRIPTION:  Creates a new OTI number given a list of coefficients.

    PARAMETERS:
                 
                  coefs:  List of coefficients. Can be any iterator. 
                  
                  order:  Integer that sets the maximum order of the number.
                  
                      Example:  coefs = [1, 2, 3],
                                order = 2
                                
                      creates an OTI number:
                      1.0 + 2.0 * e([1]) + 3.0 * e([[1,2]])     

    RESULT:       
            The next attributes are allocated:
                  
                  private obj.num: Holder of the OTI number.
                  -> order:   Maximum order of the number
                  -> Ndir:    Number of coefficients in the number.
                  -> p_coefs: c-pointer with the coefficients.
                  
    """
    #*************************************************************************************************

    cdef uint64_t sizeOfCoefs, m_max, newSizeOfCoefs, i
    # print("Calling init")
    self.FLAGS = FLAGS

      
    # create a list to handle the index numbers 
    if type(coefs) in number_types:

      m_max = m
      newSizeOfCoefs = h.getNels(m_max,order)

      self.num.p_coefs = <double* >malloc(newSizeOfCoefs*sizeof(double))
      if not self.num.p_coefs:
        raise MemoryError()
      # end if 
      self.num.p_coefs[ZERO] = coefs

      for i in range(1,newSizeOfCoefs):
      
        self.num.p_coefs[i] = 0.0
      
      # end for 

      self.num.order = order
      self.num.Ndir  = newSizeOfCoefs

    
    else:
      
      sizeOfCoefs = len(coefs)                  # works for all iterative
      m_max = h.findMaxDir(sizeOfCoefs-1,order)
      newSizeOfCoefs = h.getNels(m_max,order)

      self.num.p_coefs = <double* > malloc( newSizeOfCoefs*sizeof(double) )
      if not self.num.p_coefs:
        raise MemoryError()
      # end if 

      self.num.order = order
      self.num.Ndir  = newSizeOfCoefs
      
      for i in range(sizeOfCoefs):
      
        self.num.p_coefs[i] = <double> coefs[i]
      
      # end for 

      for i in range(sizeOfCoefs,newSizeOfCoefs):

        self.num.p_coefs[i] = 0.0
      
      # end for 

      # TODO: Add warning and error if no enough coefficients are added 
      # to the coefs vector
      # 
      # Add also a code that enables the index array to be only a list with 
      # elements of type int (python integer, not numpy integer).

    # end if

  #---------------------------------------------------------------------------------------------------



  # #***************************************************************************************************
  # def __cinit__(self): # not _cinit_ to avoid creation with _new_
  #   """
  #   PURPOSE:      Python level constructor of the otinum class.

  #   DESCRIPTION:  Creates a new OTI number given a list of coefficients.

  #   PARAMETERS:
                 
  #                 coefs:  List of coefficients. Can be any iterator. 
                  
  #                 order:  Integer that sets the maximum order of the number.
                  
  #                     Example:  coefs = [1, 2, 3],
  #                               order = 2
                                
  #                     creates an OTI number:
  #                     1.0 + 2.0 * e([1]) + 3.0 * e([[1,2]])     

  #   RESULT:       
  #           The next attributes are allocated:
                  
  #                 private obj.num: Holder of the OTI number.
  #                 -> order:   Maximum order of the number
  #                 -> Ndir:    Number of coefficients in the number.
  #                 -> p_coefs: c-pointer with the coefficients.
                  
  #   """
  #   #*************************************************************************************************
  #   # print("Calling cinit") #Initialize 
  #   self.num.p_coefs = NULL
  #   self.num.order = 0
  #   self.num.Ndir = 0
  # #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  def __dealloc__(self): 
    """
    PURPOSE:      Destructor of the class. 

    DESCRIPTION:  Frees all pointers allocated in the 
                  
    """
    #*************************************************************************************************
    # print("Deallocating memory of otinum.")
    if self.FLAGS & 1: # If memory is owned by this otinum.

      free(self.num.p_coefs)
      self.num.p_coefs = NULL
      self.num.Ndir = 0
      self.num.order = 0

    else:

      self.num.p_coefs = NULL
      self.num.Ndir = 0
      self.num.order = 0

    #end if 
    
  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  @property
  def  Ndir(self): 
    """
    PURPOSE:      Return the number of directions in the otinum.

    DESCRIPTION:  Reads the component Ndir of otinum_t num.
                  
    """
    #*************************************************************************************************

    return self.num.Ndir

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  @property
  def  coefs(self): 
    """
    PURPOSE:      Return the coefficients in a python friendly object. 

    DESCRIPTION:  Creates a numpy array object using the raw p_coef pointer.
                  This is a view of the number's coefficients. Changing a value in the numpy array 
                  changes the number in the number's coefficient.
                  The given numpy array does not own the pointer, the object can be treated as 
                  volatile, which means that in can be reasigned to another memory, and it does not
                  be easily,
                  not a view of the pointer. Be careful.
                  
    """
    #*************************************************************************************************
    
    # print(hex(<uint64_t>self.num.p_coefs))
    # cdef np.ndarray[double, ndim=1]  myarray = c_ptr_to_np_1darray_double(self.num.p_coefs, self.num.Ndir)
    # myarray.base = <PyObject*>self
    # return myarray

    return c_ptr_to_np_1darray_double(self.num.p_coefs, self.num.Ndir)

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  @property
  def  order(self): 
    """
    PURPOSE:      return the maximum order of the number.

    DESCRIPTION:  Reads the value in num.
                  
    """
    #*************************************************************************************************

    return self.num.order

  #---------------------------------------------------------------------------------------------------


    
  #***************************************************************************************************
  @staticmethod
  cdef otinum create(otinum_t* num, uint8_t FLAGS = 1):
    """
    PURPOSE:      C-level constructor of the otinum class. Use this when creating otinums within 
                  Cython

    DESCRIPTION:  Creates a new OTI number given a c-level otinum_t type.

    PARAMETERS:
                 
                  num:  Number to be referenced in python     

    RESULT:       
            A new otinum python object is created
                  
    """
    #*************************************************************************************************

    # create new empty object:
    cdef otinum otin = <otinum> otinum.__new__(otinum)

    otin.num.p_coefs = num[0].p_coefs
    otin.num.Ndir    = num[0].Ndir
    otin.num.order   = num[0].order
    otin.FLAGS = FLAGS

    # Py_INCREF(otin) # Let python know this is 
    
    return otin

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
    cdef uint64_t i, nsteps = 2

    head      = 'otinum('
    body      = ''

    if self.num.Ndir < 25:
      
      body += '['
      
      for i in range(self.num.Ndir):
      
        body+= str(self.num.p_coefs[i])+","
      
      # end for
      
      i = len(body)-1
      body=body[:i]+']'

    else:

      body += '['

      for i in range(nsteps):

        body+= str(self.num.p_coefs[i])+","

      # end for 

      body+=" ..., "

      for i in range(nsteps):
        body+= str(self.num.p_coefs[self.num.Ndir-1-i])+","
      # end for

      i = len(body)
      body=body[:i]+']'

    # end if
    tail = ', '+str(self.num.order)+')'
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
    
    cdef uint64_t i

    head      = ''
    body      = ''
    


    for i in range(0,self.num.Ndir):
      
      humDir = getDirArray(i,self.num.order)
      
      coef = str('%+g' %self.num.p_coefs[i])
      
      e_dir = printOrderPos(humDir)
      
      if i == 0 :
        
        sign = ''
       
        if coef[0]=='-':
          
          sign = coef[0] + ' '
          
        # end if

      else: 
        
        sign = coef[0] + ' '
        
      # end if
      
      body = body + sign + coef[1:] + e_dir + ' '
      
    # end for
    
    tail = ''
    
    return (head + body + tail)

  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  @staticmethod
  cdef double getitem(self, uint64_t index):
    """
    PURPOSE:  To get the value of an otinum coefficient. C level implementation

    EXAMPLE:  >>> a = 1.0 + 2.0 * e(2) + 3.0 * e([1,3])
              >>> a
              otinum([0,4,17], [1.,2.,3.], 2)
              >>> 
              >>> a[0]
              1.0
              >>> a[4]
              2.0
              >>> a[17]
              3.0
              >>> a[2]
              0.0
    """
    #*************************************************************************************************
    cdef double zero = 0.0

    if index < self.num.Ndir:

      return self.num.p_coefs[index]

    else:

      return zero

    # end if

  #--------------------------------------------------------------------------------------------------- 

  #***************************************************************************************************
  def printPtr(self):
    """
    PURPOSE:  To get the value of an otinum coefficient.

    EXAMPLE:  >>> a = 1.0 + 2.0 * e(2) + 3.0 * e([1,3])
              >>> a
              spr_otinum([0,4,17], [1.,2.,3.], 2)
              >>> 
              >>> a[0]
              1.0
              >>> a[4]
              2.0
              >>> a[17]
              3.0
              >>> a[2]
              0.0
    """
    #*************************************************************************************************
    print(hex(<uint64_t>self.num.p_coefs))

  #--------------------------------------------------------------------------------------------------- 


  #***************************************************************************************************
  def __getitem__(self, uint64_t index):
    """
    PURPOSE:  To get the value of an otinum coefficient.

    EXAMPLE:  >>> a = 1.0 + 2.0 * e(2) + 3.0 * e([1,3])
              >>> a
              spr_otinum([0,4,17], [1.,2.,3.], 2)
              >>> 
              >>> a[0]
              1.0
              >>> a[4]
              2.0
              >>> a[17]
              3.0
              >>> a[2]
              0.0
    """
    #*************************************************************************************************
    cdef double zero = 0.0

    if index < self.num.Ndir:

      return self.num.p_coefs[index]

    else:

      return zero

    # end if

  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  def __setitem__(self, uint64_t index, float64_t value):
    """
    PURPOSE:  To set the value of an otinum coefficient.

    EXAMPLE:  >>> a = 1.0 + 2.0 * e(2) + 3.0 * e([1,3])
              >>> a
              spr_otinum([0,4,17], [1.,2.,3.], 2)
              >>> 
              >>> a[0]+=10
              >>> a
              spr_otinum([0,4,17], [10.,2.,3.], 2)
              >>> a[4] = 7
              >>> a
              spr_otinum([0,4,17], [10.,7.,3.], 2)
              >>> a[2] = 5
              >>> a
              spr_otinum([0,2,4,17], [10.,5.,7.,3.], 2)

              !!!!! TODO:  !!!!! 
              ADD ERROR WHEN DATA OWN FLAG IS SET LOW AND INDEX LARGER THAN SELF.NUM.NDIR 
              IS GIVEN !!!!!!!!
    """
    #*************************************************************************************************
    global h
    cdef double* tmp_coefs
    cdef uint64_t m_max,i, sizeOfCoefs, newSizeOfCoefs

    if index < self.num.Ndir:
    
      self.num.p_coefs[index] = value
    
    else:
    
      # change the size of coefs:
      sizeOfCoefs    = self.num.Ndir
      m_max          = h.findMaxDir(index,self.num.order)
      newSizeOfCoefs = h.getNels(m_max,self.num.order)

      #self.num.coefs

      tmp_coefs = self.num.p_coefs
      #try a realloc... Be careful of what it copues
      self.num.p_coefs = <double* > malloc(newSizeOfCoefs*sizeof(double) )
      if not self.num.p_coefs:
        raise MemoryError()
      # end if 

      self.num.Ndir = newSizeOfCoefs # update number of coefficients

      memcpy(self.num.p_coefs,tmp_coefs,sizeOfCoefs*sizeof(double))

      free(tmp_coefs)   # Not needed anymore.

      for i in range(sizeOfCoefs,newSizeOfCoefs):
        
        if i == index:
        
          self.num.p_coefs[i] = value
        
        else:
        
          self.num.p_coefs[i] = 0.0
        
        # end if

      # end for

    # end if

  #---------------------------------------------------------------------------------------------------  



  #***************************************************************************************************
  cdef otinum neg(self):
    """
    PURPOSE:      Fast c-version of operator -
                  (negative)
    
    EXAMPLE:      >>> a = otinum([10.,7.,3.], 2)
                  >>> a.neg()
                  otinum([-10.,-7.,-3.], 2)
    """
    #*************************************************************************************************
    cdef uint64_t i
    cdef otinum_t newnum

    # Allocate memory for new pointer
    newnum.p_coefs = <double*> malloc(self.num.Ndir*sizeof(double))
    if not newnum.p_coefs:
      raise MemoryError()
    # end if 
    
    # Copy data
    newnum.Ndir = self.num.Ndir
    newnum.order= self.num.order
    memcpy(newnum.p_coefs,self.num.p_coefs,self.num.Ndir*sizeof(double))

    for i in range(self.num.Ndir):
    
      newnum.p_coefs[i] *= -1.0

    # end for

    return otinum.create(&newnum)

  #--------------------------------------------------------------------------------------------------- 


  #***************************************************************************************************
  cpdef otinum selfNeg(self):
    """
    PURPOSE:      To define how to turn a otinum into its opposite
                  (negative)

    DESCRIPTION:  It overloads the operation "a*=-1".
    
    EXAMPLE:      >>> a = otinum([10.,7.,3.], 2)
                  >>> a.selfNeg
                  >>> a
                  otinum([-10.,-7.,-3.], 2)
    """
    #*************************************************************************************************
    cdef uint64_t i
    

    for i in range(self.num.Ndir):
    
      self.num.p_coefs[i] *= -1.0

    # end for
  #--------------------------------------------------------------------------------------------------- 


  #***************************************************************************************************
  def __neg__(self):
    """
    PURPOSE:      To define how to turn a spr_otinum into its opposite
                  (negative)

    DESCRIPTION:  It overloads the operator "-".
    
    EXAMPLE:      >>> a = otinum([10.,7.,3.], 2)
                  >>> -a
                  otinum([-10.,-7.,-3.], 2)
    """
    #*************************************************************************************************
    cdef uint64_t i
    cdef otinum_t newnum


    # Allocate memory for new pointer
    newnum.p_coefs = <double*> malloc(self.num.Ndir*sizeof(double))
    if not newnum.p_coefs:
      raise MemoryError()
    # end if 
    
    # Copy data
    newnum.Ndir = self.num.Ndir
    newnum.order= self.num.order
    memcpy(newnum.p_coefs,self.num.p_coefs,self.num.Ndir*sizeof(double))

    # negate coefficients

    for i in range(self.num.Ndir):
    
      newnum.p_coefs[i] *= -1.0

    # end for

    return otinum.create(&newnum)
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

    PERFORMANCE OPTION:

                  Be careful that this is very slow because to make it more robust, it checks all 
                  input types. For better performance use method add <not __add__>.


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
      uint64_t i = 0, minNdir, maxNdir
      otinum_t res
      otinum_t p_S
      uint8_t flag_p_S=0
      otinum_t p_O
      uint8_t flag_p_O=0
      otinum_t p_res
      otinum S
      otinum O

    type1 = type(self)     # takes 100 ns ... 
    type2 = type(other_in) # takes 100 ns ...

    # type1 = self.__class__     # takes ~50 ns ... 
    # type2 = other_in.__class__ # takes ~50 ns ...


    if ( type1 is type2) : # Case Sum between OTIs.

      S = self
      O = other_in
      p_S = S.num       # create views of the otinum_t
      p_O = O.num   #

      if p_S.order != p_O.order:
        
        # Preserve the maximum order.
        if p_S.order > p_O.order:

          c_oti_changeOrderToNew(&O.num, p_S.order, p_dH, &p_O) 
          flag_p_O = 1

        else:

          c_oti_changeOrderToNew(&S.num, p_O.order, p_dH, &p_S)
          flag_p_S = 1

        # end if

      # end if

      c_minUI64(p_O.Ndir,p_S.Ndir,&minNdir, &maxNdir)
      c_oti_createEmpty(&p_res, maxNdir,  p_S.order)
      c_oti_sum(&p_S, &p_O, &p_res)

      if flag_p_S == 1:
        # print("Address of self",hex(<uint64_t> &S.num))
        # print("Address of p_S",hex(<uint64_t> p_S))
        c_oti_free(&p_S)

      if flag_p_O == 1:
        # print("Address of self",<uint64_t> &O.num)
        # print("Address of p_O",<uint64_t> p_O)
        c_oti_free(&p_O)

        

    # TODO: Add support for interfacing with spr_otinum
    
    elif (type2 in number_types): # Case Sum to real number. Very slow, consider changing this...
      
      S = self
      c_oti_copy(&p_res,&S.num)
      p_res.p_coefs[0] += other_in

    elif (type1 in number_types): # Case 1.5. reverse Sum to real number.
      
      O = other_in
      c_oti_copy(&p_res,&O.num)
      p_res.p_coefs[0] += self

    # end if 
      
      

    # end if. Type cases.
    
    return otinum.create(&p_res)

  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  def __iadd__(self, other_in):
    """
    PURPOSE:      To define how to sum two otinum numbers.

    DESCRIPTION:  It overloads the inplace sum operator "+=". It allows the 
                  addition of spr_otinum numbers of different orders, and 
                  the addition of a otinum number and a scalar. 
    
    EXAMPLE:      >>> a = otinum([1.,3.,5.], 2)
                  >>> b = otinum([7.,9.,11.], 2)
                  >>> a += b
                  >>> a 
                  spr_otinum([8.,12.,16.], 2)
                  >>> b
                  spr_otinum([7.,9.,11.], 2)
    """
    #*************************************************************************************************
    
    global h
    global p_dH
    cdef: 
      uint64_t i = 0, minNdir, maxNdir
      otinum_t p_O
      uint8_t flag_p_O=0
      otinum_t p_res
      otinum O

    type2 = type(other_in) # takes 100 ns ...


    if (type2 is otinum) : # Case Sum between OTIs.

      O = other_in
      
      p_O = O.num   #

      if self.num.order != p_O.order:
        
        # Preserve the maximum order.
        if self.num.order > p_O.order:

          c_oti_changeOrderToNew(&O.num, self.num.order, p_dH, &p_O) 
          flag_p_O = 1

        else:

          c_oti_changeOrder(&self.num, p_O.order, p_dH)
          # TODO: Avoid the case in which it is needed both
          # change order and change length. (avoid two mallocs)

        # end if

      # end if

      c_minUI64(p_O.Ndir,self.num.Ndir,&minNdir, &maxNdir)

      if maxNdir != self.num.Ndir:

        c_oti_createEmpty(&p_res, maxNdir,  self.num.order)
        c_oti_sum(&self.num, &p_O, &p_res)
        c_oti_free(&self.num)
        self.num.p_coefs = p_res.p_coefs
        self.num.order = p_res.order
        self.num.Ndir = p_res.Ndir 

      else:

        c_oti_sum(&self.num, &p_O, &self.num)

      # end if 

      if flag_p_O == 1:

        c_oti_free(&p_O)

      # end if 

        

    # TODO: Add support for interfacing with spr_otinum
    
    elif (type2 in number_types): # Case Sum to real number. Very slow, consider changing this...
      
      
      self.num.p_coefs[0] += other_in

    # end if

    return self

  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  def __sub__(self, other_in):
    """
    PURPOSE:      To define how to subtract two otinum numbers.

    DESCRIPTION:  It overloads the subtract operator "-". It allows the 
                  subtraction of spr_otinum numbers of different orders, 
                  and the subtraction of a otinum number and a scalar. 
    
    EXAMPLE:      >>> a = otinum( [1.,3.,5.], 2)
                  >>> b = otinum( [7.,9.,11.], 2)
                  >>> a - b
                  otinum([-6.,-6.,-6.], 2)
                  
                  >>> a = otinum([1.,3.,5.], 2)
                  >>> a - 15
                  otinum([-14.,3.,5.], 2)
    """
  #************************************************************************
    
    global h
    global p_dH
    cdef: 
      uint64_t i = 0, minNdir, maxNdir
      otinum_t res
      otinum_t p_S
      uint8_t flag_p_S=0
      otinum_t p_O
      uint8_t flag_p_O=0
      otinum_t p_res
      otinum S
      otinum O

    type1 = type(self)     # takes 100 ns ... 
    type2 = type(other_in) # takes 100 ns ...

    # type1 = self.__class__     # takes ~50 ns ... 
    # type2 = other_in.__class__ # takes ~50 ns ...


    if ( type1 is type2) : # Case Sum between OTIs.

      S = self
      O = other_in
      p_S = S.num       # create views of the otinum_t
      p_O = O.num   #

      if p_S.order != p_O.order:
        
        # Preserve the maximum order.
        if p_S.order > p_O.order:

          c_oti_changeOrderToNew(&O.num, p_S.order, p_dH, &p_O) 
          flag_p_O = 1

        else:

          c_oti_changeOrderToNew(&S.num, p_O.order, p_dH, &p_S)
          flag_p_S = 1

        # end if

      # end if

      c_minUI64(p_O.Ndir,p_S.Ndir,&minNdir, &maxNdir)
      c_oti_createEmpty(&p_res, maxNdir,  p_S.order)
      c_oti_sub(&p_S, &p_O, &p_res)

      if flag_p_S == 1:
        # print("Address of self",hex(<uint64_t> &S.num))
        # print("Address of p_S",hex(<uint64_t> p_S))
        c_oti_free(&p_S)

      if flag_p_O == 1:
        # print("Address of self",<uint64_t> &O.num)
        # print("Address of p_O",<uint64_t> p_O)
        c_oti_free(&p_O)

        

    # TODO: Add support for interfacing with spr_otinum
    
    elif (type2 in number_types): # Case sub to real number. Very slow, consider changing this...
      
      S = self
      c_oti_copy(&p_res,&S.num)
      p_res.p_coefs[0] -= other_in

    elif (type1 in number_types): # Case 1.5. reverse Sub to real number.
      
      O = other_in
      c_oti_copy(&p_res,&O.num)
      c_oti_neg(&p_res) # Negate the elements of p_res
      p_res.p_coefs[0] += self

    # end if 
      
      

    # end if. Type cases.
    
    return otinum.create(&p_res)


  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  def __isub__(self, other_in):
    """
    PURPOSE:      To define how to subtract two spr_otinum numbers.

    DESCRIPTION:  It overloads the inplace subtract operator "-=". It allows
                  the subtraction of spr_otinum numbers of different orders, 
                  and the subtraction of a spr_otinum number and a scalar. 
    
    EXAMPLE:      >>> a = spr_otinum([0,4,17], [1.,3.,5.], 2)
                  >>> b = spr_otinum([0,2,4], [7.,9.,11.], 2)
                  >>> a -= b
                  >>> a
                  spr_otinum([0,2,4,17], [-6.,-9.,-8.,5.], 2)
                  >>>b
                  spr_otinum([0,2,4], [7.,9.,11.], 2)
    """
    #*************************************************************************************************
  
    global h
    global p_dH
    cdef: 
      uint64_t i = 0, minNdir, maxNdir
      otinum_t p_O
      uint8_t flag_p_O=0
      otinum_t p_res
      otinum O

    type2 = type(other_in) # takes 100 ns ...


    if (type2 is otinum) : # Case Sum between OTIs.

      O = other_in
      
      p_O = O.num   #

      if self.num.order != p_O.order:
        
        # Preserve the maximum order.
        if self.num.order > p_O.order:

          c_oti_changeOrderToNew(&O.num, self.num.order, p_dH, &p_O) 
          flag_p_O = 1

        else:

          c_oti_changeOrder(&self.num, p_O.order, p_dH)
          # TODO: Avoid the case in which it is needed both
          # change order and change length. (avoid two mallocs)

        # end if

      # end if

      c_minUI64(p_O.Ndir,self.num.Ndir,&minNdir, &maxNdir)

      if maxNdir != self.num.Ndir:

        c_oti_createEmpty(&p_res, maxNdir,  self.num.order)
        c_oti_sub(&self.num, &p_O, &p_res)
        c_oti_free(&self.num)
        self.num.p_coefs = p_res.p_coefs
        self.num.order = p_res.order
        self.num.Ndir = p_res.Ndir 

      else:

        c_oti_sub(&self.num, &p_O, &self.num)

      # end if 

      if flag_p_O == 1:

        c_oti_free(&p_O)

      # end if 

        

    # TODO: Add support for interfacing with spr_otinum
    
    elif (type2 in number_types): # Case Sum to real number. Very slow, consider changing this...
      
      
      self.num.p_coefs[0] -= other_in

    # end if

    return self

  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  def __mul__(self, other_in):
    """
    PURPOSE:      To define how to multiply two OTI numbers.
    
    DESCRIPTION:  It overloads the multiplication operator "*". It allows
                  the multiplication of OTI numbers of different 
                  orders, no matter how they are sorted, or even the 
                  multiplication of an OTI number and a scalar. 
    
    EXAMPLE:      >>> a = otinum([1.,3.,5.], 2)
                  >>> b = otinum([7.,9.,11.], 2)
                  >>> a * b
                  otinum([7.,30.,73.], 2)
    """
    #*************************************************************************************************
    
    


    global h
    global p_dH
    cdef: 
      uint64_t i = 0, minNdir, maxNdir
      otinum_t res
      otinum_t p_S
      uint8_t flag_p_S=0
      otinum_t p_O
      uint8_t flag_p_O=0
      otinum_t p_res
      otinum S
      otinum O

    type1 = type(self)     # takes 100 ns ... 
    type2 = type(other_in) # takes 100 ns ...


    if ( type1 is type2) : # Case mul between OTIs.

      S = self
      O = other_in
      p_S = S.num       # create views of the otinum_t
      p_O = O.num       #

      if p_S.order != p_O.order:
        
        # Preserve the minimum order.
        if p_S.order < p_O.order:

          c_oti_changeOrderToNew(&O.num, p_S.order, p_dH, &p_O) 
          flag_p_O = 1

        else:

          c_oti_changeOrderToNew(&S.num, p_O.order, p_dH, &p_S)
          flag_p_S = 1

        # end if

      # end if

      c_minUI64(p_O.Ndir,p_S.Ndir,&minNdir, &maxNdir)
      c_oti_createEmpty(&p_res, maxNdir,  p_S.order)
      c_oti_mul(&p_S, &p_O, &p_res, p_dH)

      if flag_p_S == 1:
        # print("Address of self",hex(<uint64_t> &S.num))
        # print("Address of p_S",hex(<uint64_t> p_S))
        c_oti_free(&p_S)

      if flag_p_O == 1:
        # print("Address of self",<uint64_t> &O.num)
        # print("Address of p_O",<uint64_t> p_O)
        c_oti_free(&p_O)

        

    # TODO: Add support for interfacing with spr_otinum
    
    elif (type2 in number_types): # Case sub to real number. Very slow, consider changing this...
      
      S = self
      c_oti_copy(&p_res,&S.num)
      c_oti_mulf(&p_res,other_in,&p_res)

    elif (type1 in number_types): # Case 1.5. reverse Sub to real number.
      
      O = other_in
      c_oti_copy(&p_res,&O.num)
      c_oti_mulf(&p_res,self,&p_res)

    # end if 
    
    return otinum.create(&p_res)

  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  def __imul__(self, other_in):
    """
    PURPOSE:      To define how to make an inplace multiplication between
                  two OTI numbers.
    
    DESCRIPTION:  It overloads the multiplication operator "*=". It allows
                  the multiplication of OTI numbers of different orders, 
                  or even the multiplication with scalars.
    
    EXAMPLE:      >>> a = spr_otinum([0,4,17], [1.,3.,5.], 2)
                  >>> b = spr_otinum([0,2,4], [7.,9.,11.], 2)
                  >>> a *= b
                  >>> a
                  spr_otinum([0,2,4,8,17], [7.,9.,32.,33.,35.], 2)
                  >>> b
                  spr_otinum([0,2,4], [7.,9.,11.], 2)

    TODO:         Replace this so that it does not require a mallocs...

    """
    #*************************************************************************************************

    
    self = self * other_in

    return self

  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  def __truediv__(self, other):
    """
    PURPOSE:      To define how to divide two spr_otinum numbers.
    
    DESCRIPTION:  It overloads the division operator "/". It allows the
                  division of spr_otinum numbers of different orders, and 
                  the division of a spr_otinum number and a scalar. 

    EXAMPLE:      >>> a = otinum([1.,3.,5.], 2)
                  >>> b = otinum([7.,9.,11.], 2)
                  >>> a/b
                  otinum([0.14285714285714285,0.24489795918367346,0.17492711370262393], 2)
    """
    #*************************************************************************************************
    
    cdef double factor
    cdef uint64_t i
    cdef otinum S

    type1 = type(self)
    type2 = type(other)

    if type(other) is otinum:   # Case 2. spr_otinum.
      
      S = self * power(other,-1)

    elif type(other) in number_types:    # Case 1. real number.
      
      
      S = self.copy()
      
      factor = (1./other)
      
      for i in range(S.num.Ndir):
        
        S.num.p_coefs[i] *= factor

      # end for 

    elif type(self) in number_types:    # Case 1.5 reverse real number. 

      # print("!!!!! THIS IS THE CASE !!!!!")

      # S = other.copy()
      # coefs = np.zeros(other.coefs.size,dtype = np.float64)
      m = h.c_findMaxDir(other.Ndir-1,other.order)
      return otinum(self,other.order,m=m)/other
      # return spr_otinum(np.array([0],dtype = np.uint64),np.array([self],dtype = np.float64),other.maxorder)/other
      
    
    # End if. Type cases.
    
    return S

  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  def __pow__(self, n,z):
    """
    PURPOSE:      To provide power function.
  
    DESCRIPTION:  It defines how to make a mcxnumber to the power of n.
  
    EXAMPLE:      >>> a = otinum([1.,3.,5.], 2)
                  >>> a**(-1)
                  otinum([1.,-3., 4.], 2)
    """
    #*************************************************************************************************

    return power(self,n)

  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  cpdef copy(self):
    """
    PURPOSE:      To create a copy of a spr_otinum object, totally 
                  independent of the original.

    DESCRIPTION:  The equality operator "=" is intended to create aliases
                  of multicomplex numbers. You should use copy() when you
                  need a copy instead of an alias.
    
    EXAMPLE:      >>> a = otinum([1.,7.,3.], 2)
                  >>> b = a.copy()
                  >>> b[1] = 10
                  >>> a
                  otinum([1.,7.,3.], 2)
                  >>> b
                  otinum([1.,10.,3.], 2)
    """
    #*************************************************************************************************
    cdef otinum_t newnum

    # c_createEmptyOti(&newnum, self.num.Ndir,self.num.order)
    # c_copyOti(&newnum,&self.num)

    newnum.p_coefs = <double*> malloc(self.num.Ndir*sizeof(double))
    if not newnum.p_coefs:
      raise MemoryError()
    # end if 
    newnum.Ndir = self.num.Ndir
    newnum.order= self.num.order
    memcpy(newnum.p_coefs,self.num.p_coefs,self.num.Ndir*sizeof(double))

    return otinum.create(&newnum)
  #---------------------------------------------------------------------------------------------------  



  #***************************************************************************************************
  cpdef void changeOrder(self,uint8_t neworder):
    """
    PURPOSE:      To change the order of a spr_otinum.

    DESCRIPTION:  According to the new order, the index values are changed. 

    """
    #*************************************************************************************************
    global p_dH

    c_oti_changeOrder(&self.num, neworder, p_dH)


  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  def getDual(self, dirArray):
    """
    PURPOSE:      To add a human friendly form to get elements from a 
                  otinum.
    
    EXAMPLE:      >>> a = otinum([1.,3.,5.], 2)
                  >>> print(a)
                  1.0 + 3.0 * e([1]) + 5.0 * e([[1,2]])
                  >>> a.getDual([[1,2]])
                  5.0
                  >>> a.getDual([2])
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

    if order > self.num.order:
      
      return 0.0 
    
    # end if

    if order == 0:
        
      indx = 0

    elif self.num.order == 1:

      indx = indxArray[0]

    else:

      indx = h.c_findIndx(p_dirA,p_expA,self.num.order)

    # end if
    
    return self[indx]

  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  def setDual(self, dirArray, value):
    """
    PURPOSE:      To add a human friendly form to set elements of a 
                  spr_otinum.
    
    EXAMPLE:      >>> a = spr_otinum([0,4,17], [1.,3.,5.], 2)
                  >>> print(a)
                  1.0 + 3.0 * e([2]) + 5.0 * e([1,3])
                  >>> a.setDual([1,3],10)
                  >>> print(a)
                  1.0 + 3.0 * e([2]) + 10.0 * e([1,3])
                  >>> a.setDual([1],2.5)
                  >>> print(a)
                  1.0 + 2.5 * e([1]) + 3.0 * e([2]) + 5.0 * e([1,3])
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

    if order > self.num.order:
      
      return 0.0 
    
    # end if

    if order == 0:
        
      indx = 0

    elif self.num.order == 1:

      indx = indxArray[0]

    else:

      indx = h.c_findIndx(p_dirA,p_expA,self.num.order)

    # end if

    if indx<= self.num.Ndir:
    
      self.num.p_coefs[indx] = value
    
    else:
    
      self[indx] = value  # Slow because it calls a python function. TODO: Add all memory allocation. 
    
    # end if    

  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  cdef double c_getDerivByDirExp( self, uint16_t* p_dirA, uint8_t* p_expA):
    """
    PURPOSE:      to retrieve the n'th derivative according to the taylor 
                  series expansion with dual numbers.
                
    DESCRIPTION:  Simply given the combinations of derivatives with the 
                  dirArray, the function multiplies the terms that require
                  extra factors to get the desired derivatives.

                  Be careful. The directions must come according to
                  p_dH[order-1].{p_dirA,p_expA}

                  No error checking is done  
    
    EXAMPLE:      >>> a = otinum([1,2,3,4,5,6],2)
                  >>>
                  >>> a.getDerivByDirExp(a,[0,0],[0,0])
                  1.
                  >>> a.getDerivByDirExp(a,[1,0],[1,0])
                  2.
                  >>> a.getDerivByDirExp(a,[1,0],[2,0])
                  6.
                  >>> a.getDerivByDirExp(a,[2,0],[1,0])
                  4.
                  >>> a.getDerivByDirExp(a,[1,2],[1,1])
                  5.
                  >>> a.getDerivByDirExp(a,[2,0],[2,0]])
                  12.

    """
    #*************************************************************************************************
    global p_dH
    cdef uint8_t  i
    cdef double value = 0.0, factor = 1.0
    
    # Compute the multiplication factor and fill in the temporal arrays.

    for i in range(self.num.order):
      
      factor *= c_fastfact(p_expA[i])
    
    # end for
    
    indx  = c_helper_findIndex(p_dirA,p_expA,self.num.order,p_dH)
    
    if indx <= self.num.Ndir:
    
      value = self.num.p_coefs[indx]*factor

    # end if 
    
    return value

  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  def getDeriv(self, dirArray):
    """
    PURPOSE:      to retrieve the n'th derivative according to the taylor 
                  series expansion with dual numbers.
                
    DESCRIPTION:  Simply given the combinations of derivatives with the 
                  dirArray, the function multiplies the terms that require
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


    if type(dirArray)==int:
    
      indxArray = [dirArray]

    else:

      indxArray = dirArray
      
    # end if

    c_getDirExpA(indxArray, &p_dirA, &p_expA, &order)

    if order > self.num.order:
      
      return 0.0 
    
    # end if

    return self.c_getDerivByDirExp(p_dirA,p_expA)

  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  def toVector(self):
    """
    PURPOSE:      To convert a spr_otinum into its vector form.
                  
    DESCRIPTION:  Convert to its own Cauchy-Riemann representation vector.

                    
    """
    #*************************************************************************************************

    return self.expand(ismat =0)

  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  def toMatrix(self,ismat = 1,m = -1,isspr = 0):
    """
    PURPOSE:      To convert a spr_otinum into its matrix form.
                  
    DESCRIPTION:  Convert to its own Cauchy-Riemann representation vector.
    
    INPUTS:
                  ismat: To define a matrix (1) or a vector (0)
                  isshape: To use the shape that will result of the number 
                    (-1) or an specific shape (given value).
                  isspr: To result in a sparse matrix (1) or not (0).
    """
    #*************************************************************************************************

    return self.expand(ismat = ismat, m = m, isspr = isspr)

  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  def expand(self,ismat = 1,m = -1 , isspr = 0):
    """
    PURPOSE:      To convert a otinum into its matrix form.
                  
    DESCRIPTION:  Convert to its own Cauchy-Riemann representation form.
                   
    INPUTS:
                  ismat: To define a matrix (1) or a vector (0)

                  m:     To use the shape that will result of the number 
                         (-1) or an specific shape (given value).

                  isspr: Matrix in a sparse matrix (1) or not (0).
                    
    """
    #*************************************************************************************************
    
    global h
    global p_dH

    cdef: 
      uint64_t i, k, j
      uint64_t finalshape, nIterMin,  maxI
      double* data   
      uint64_t* shape


    if m == -1:
      # Deduce the matrix dimension by looking at the last indx and 
      # looking for the maximum base direction
      
      # Separate cases for order 1 and others.       
      m_max =  c_helper_findMaxDir(self.num.Ndir-1,self.num.order,p_dH)

    else:
      
      m_max = m
      
    # end if

    finalshape = c_helper_getNels(m_max, self.num.order, p_dH)

    
    if ismat == 0:
      # vector type
      
      mat = np.zeros(finalshape)
      
      # Do only a certain amount of iterations:
      c_minUI64(finalshape, self.num.Ndir, &nIterMin, &maxI)
      
      k = 0

      for i in range(nIterMin):
        
        mat[i] = self.num.p_coefs[i]

      # end for
      
    else:

      # matrix type
      
      if isspr == 0:
        #return the np.array?
        #mat = np.array(__otinum2Mat_dense(self, finalshape))
        
        data = c_oti_num2mat(&self.num, finalshape, p_dH)
        mat = c_ptr_to_np_2darray_double(data,finalshape,finalshape, numpy_own = 1)
        
      else:
        
        
        pass

        
      # end if
      

    # end if 
    
    
    return mat

  #---------------------------------------------------------------------------------------------------


  #***************************************************************************************************
  cpdef assignAll(self, float64_t value):
    """
    PURPOSE:      Fast function to assign to all coefficients in self the given value.

    """
    #*************************************************************************************************
    cdef uint64_t i

    for i in range(self.num.Ndir):

      self.num.p_coefs[i] = value

    # end for   

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  cpdef one(self):
    """
    PURPOSE:      Fast function to assign to the real coefficient one and all others zero.

    """
    #*************************************************************************************************
    cdef uint64_t i=0
    
    self.num.p_coefs[i] = 1.0
    
    for i in range(1,self.num.Ndir):
      
      self.num.p_coefs[i] = 0.

    # end for   

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  def sum(self, *args):
    """
    PURPOSE:  Function to sum self with other otinum numbers without allocating memory between 
              processes. Input can be only one number or many otinum separated by commas.

              Notice that they need to have the same dimensions, otherwise it wont give accurate 
              results.

              example: Given otinum a,b,c,d:

                  >>> a.sum(b,c,d)       # Gives the same as doing:

                  >>> a = a + b + c + d  # but in a faster way. 
    """
    #*************************************************************************************************
    
    cdef uint64_t i, j, nels = self.num.Ndir, nargs = len(args)
    cdef otinum other_in     # holder to increase access speed

    for i in range(nargs):

      other_in = args[i] # Get input by input

      for j in range(nels):

        self.num.p_coefs[j] += other_in.num.p_coefs[j]

      # end for 

    # end for   

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  def sub(self, *args):
    """
    PURPOSE:  Function to substract self with other otinum numbers without allocating memory between 
              processes. Input can be only one number or many otinum separated by commas.

              Notice that they need to have the same dimensions, otherwise it wont give accurate 
              results.

              example: Given otinum a,b,c,d:

                  >>> a.sum(b,c,d)       # Gives the same as doing:

                  >>> a = a - b - c - d  # but in a faster way. 
    """
    #*************************************************************************************************
    
    cdef uint64_t i, j, nels = self.num.Ndir, nargs = len(args)
    cdef otinum other_in     # holder to increase access speed

    for i in range(nargs):

      other_in = args[i] # Get input by input

      for j in range(nels):

        self.num.p_coefs[j] -= other_in.num.p_coefs[j]

      # end for 

    # end for     

  #---------------------------------------------------------------------------------------------------


#   #***************************************************************************************************
#   def inv(self):
#     """
#     PURPOSE:  Function to divide 1.0/self with another otinum number without allocating memory between 
#               processes.

#               example: Given otinum a,b,c,d:

#                   >>> a.inv()          # Gives the same as doing:

#                   >>> a = 1.0 / a      # but in a faster way. 
#     """
#     #*************************************************************************************************
    
#     cdef uint64_t i, j, nels = self.coefs.size
#     cdef otinum other_in     # holder to increase access speed
#     cdef float64_t val1, val2
    
#     if self.maxorder == 1:

#       val1 = 1/self.coefs[ZERO]
#       val2 = -1./(self.coefs[ZERO])
      
#       for i in range(self.coefs.size):

#         if i == 0:
        
#           self.coefs[i] = val1
        
#         else:
        
#           self.coefs[i] = val2*self.coefs[i]
        
#         # end if

#       # end for

#     else:

#       self = 1.0/self

#     # end if  

#   #---------------------------------------------------------------------------------------------------

#   #***************************************************************************************************
#   def mult(self, *args,float64_t[:] prealloc = None):
#     """
#     PURPOSE:  Function to multiply self with other otinum numbers without allocating memory between 
#               processes. Input can be only one number or many otinums separated by commas.

#               Notice that they need to have the same dimensions, otherwise it wont do a correct 
#               operation.

#               example: Given the otinum objects:  a, b, c and d:

#                   >>> a.mult(b)          # Gives the same as doing:

#                   >>> a = a * b          # but in a faster way. 

#                   >>> a.mult(b,c,d)      # Gives the same as doing:

#                   >>> a = a + b + c + d  # but in a faster way. 
#     """
#     #*************************************************************************************************
    
#     cdef uint64_t i, j, k, nels = self.coefs.size
#     cdef otinum other_in           # holder to increase access speed
#     cdef float64_t zerof = 0.
#     cdef uint8_t[:] error = np.array([0],dtype=np.uint8)

#     if prealloc == None:           # Check if the given prealloc value is allocated.
    
#       prealloc = np.empty(nels,dtype = np.float64)

#     # end if 
    
#     for k in range(len(args)):

#       O = args[k]  # Get one by one the given elements.

#       # initialize prealloc:
#       for i in range(nels):

#         prealloc[i] = zerof

#       # end for 

#       for i in range(nels):

#         for j in range(nels):

#           # multiply coefficients
#           resIndx = h.multIndx(i,j,self.maxorder,error)

#           if error[0] == 0:     # when error[0] is 1 the multiplication gives a non admissible dir.

#             prealloc[resIndx] = prealloc[resIndx] + self.coefs[i]*O.coefs[j] 

#           # end if

#         # end for

#       # end for

#       for i in range(nels):
      
#         self.coefs[i] = prealloc[i]

#       # end for 

#     # end for 

#   #--------------------------------------------------------------------------------------------------- 

#   # #***************************************************************************************************
#   # def mult2(self, *args,float64_t[:] prealloc = None):
#   #   """
#   #   PURPOSE:  Function to multiply self with other otinum numbers without allocating memory between 
#   #             processes. Input can be only one number or many otinums separated by commas.

#   #             Notice that they need to have the same dimensions, otherwise it wont do a correct 
#   #             operation.

#   #             example: Given the otinum objects:  a, b, c and d:

#   #                 >>> a.mult(b)          # Gives the same as doing:

#   #                 >>> a = a * b          # but in a faster way. 

#   #                 >>> a.mult(b,c,d)      # Gives the same as doing:

#   #                 >>> a = a + b + c + d  # but in a faster way. 
#   #   """
#   #   #*************************************************************************************************
    
#   #   cdef uint64_t i, j, k, nels = self.coefs.size
#   #   cdef otinum other_in           # holder to increase access speed
#   #   cdef float64_t zerof = 0.
#   #   cdef uint8_t[:] error = np.array([0],dtype=np.uint8) # avoid mallocs.....


#   #   if prealloc == None:           # Check if the given prealloc value is allocated.
    
#   #     prealloc = np.empty(nels,dtype = np.float64)

#   #   # end if 
    
    
#   #   compMultiplesPre(uint8_t[::1] expArray, uint8_t[:,::1] multiples, \
#   #                                     uint8_t[::1] multiple, uint64_t[:] maxiter)


#   #   for k in range(len(args)):

#   #     O = args[k]  # Get one by one the given elements.

#   #     # initialize prealloc:
#   #     for i in range(nels):

#   #       prealloc[i] = zerof

#   #     # end for 

#   #     for i in range(nels):

#   #       # Get direction and exponent arrays:
#   #       expArray = h.getExpA(i,A.maxorder)
#   #       dirArray = h.getDirA(i,A.maxorder)

#   #       # get the multiples of the exponent array:
#   #       multiples = compMultiples(expArray)

#   #       # string = 'A0x' + str(getDirArray(i,A.maxorder))+' = b'+str(getDirArray(i,A.maxorder))
        
#   #       # loop in all multiples
#   #       for j in range(multiples.shape[0]-1):

#   #         # Get the multiple of matrix A that is "mirrored" with respect to multiple for vector X
#   #         pos = multiples.shape[0]-j-1

#   #         c_orderDirExpArray(&dirArray[0],    &multiples[0,0] , pos,\
#   #                     &dirA[0], &expA[0], A.maxorder)

#   #         # Get the mirrored multiple for vector X
#   #         c_orderDirExpArray(&dirArray[0],    &multiples[0,0] , j, \
#   #                     &dirX[0], &expX[0], A.maxorder)
          
#   #         # Get the equivalent index for A.
#   #         indxA = h.findIndx(dirA, expA, A.maxorder)

#   #         if dirX[0] == 0:

#   #           indxX = 0

#   #         else:

#   #           # Get the equivalent index for X.
#   #           indxX = h.findIndx(dirX, expX, A.maxorder)

#   #         # end if 

#   #         # Subtract A_indxA * x_indxX to the fi vector
#   #         fi -= A[indxA].dot(x.data[:,indxX])


#   #         # string += ' - A'+ str(getDirArray(indxA,A.maxorder))
#   #         # string += 'x'+ str(getDirArray(indxX,A.maxorder))

          
#   #       # end for

#   #       # TODO: Change according to all different solvers selected.

#   #       x.data[:,i]  = A0.solve(fi.base)   # Solve factorized system


#   #     # end for




























#   #   for k in range(len(args)):

#   #     O = args[k]  # Get one by one the given elements.

#   #     # initialize prealloc:
#   #     for i in range(nels):

#   #       prealloc[i] = zerof

#   #     # end for 

#   #     for i in range(nels):

#   #       for j in range(nels):

#   #         # multiply coefficients
#   #         resIndx = h.multIndx(i,j,self.maxorder,error)

#   #         if error[0] == 0:     # when error[0] is 1 the multiplication gives a non admissible dir.

#   #           prealloc[resIndx] = prealloc[resIndx] + self.coefs[i]*O.coefs[j] 

#   #         # end if

#   #       # end for

#   #     # end for

#   #     for i in range(nels):
      
#   #       self.coefs[i] = prealloc[i]

#   #     # end for 

#   #   # end for 

#   # #--------------------------------------------------------------------------------------------------- 


  #***************************************************************************************************
  cpdef null(self):
    """
    PURPOSE:      Fast function to assign to all coefficients 0 .

    """
    #*************************************************************************************************
    
    cdef float64_t value = 0.0
    
    self.assignAll(value)

  #---------------------------------------------------------------------------------------------------

#   #***************************************************************************************************
#   cpdef assign(self, float64_t[:] values):
#     """
#     PURPOSE:      Fast function to assign all coefficients from an array object.

#     """
#     #*************************************************************************************************
#     cdef uint64_t i

#     for i in range(self.coefs.size):

#       self.coefs[i] = values[i]

#     # end for   

#   #---------------------------------------------------------------------------------------------------


  #***************************************************************************************************
  cpdef scale(self,float64_t value):
    """
    PURPOSE:      Fast function to multiply all coefficients to scalar value.

    """
    #*************************************************************************************************
    
    cdef uint64_t i

    for i in range(self.num.Ndir):

      self.num.p_coefs[i] *= value

    # end for   

  #---------------------------------------------------------------------------------------------------

# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# :::::::::::::::::::::::::::::::::::: END OF CLASS OTINUM :::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::





























#*****************************************************************************************************
cpdef  otinum cos(otinum val):
  """
  PURPOSE:  Mathematical function of cosine for OTI numbers
   
  EXAMPLE:   
  """
  #***************************************************************************************************

  global p_dH
  cdef otinum_t res
  
  c_oti_cos(&val.num, p_dH, &res)

  return otinum.create(&res)
#-----------------------------------------------------------------------------------------------------


#*****************************************************************************************************
cpdef  otinum sin(otinum val):
  """
  PURPOSE:  Mathematical function of sine for OTI numbers.
   
  EXAMPLE:   
  """
  #***************************************************************************************************
  global p_dH
  cdef otinum_t res
  
  c_oti_sin(&val.num, p_dH, &res)

  return otinum.create(&res)
#-----------------------------------------------------------------------------------------------------


#*****************************************************************************************************
cpdef  otinum tan(otinum val):
  """
  PURPOSE:  Mathematical function of tangent for OTI numbers
   
  EXAMPLE:   
  """
  #***************************************************************************************************
  global p_dH
  cdef otinum_t res
  
  c_oti_tan(&val.num, p_dH, &res)

  return otinum.create(&res)
#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cpdef  otinum atan(otinum val):
  """
  PURPOSE:  Mathematical function of arctangent for OTI numbers
   
  EXAMPLE:   
  """
  #***************************************************************************************************
  global p_dH
  cdef otinum_t res
  
  c_oti_atan(&val.num, p_dH, &res)

  return otinum.create(&res)
#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cpdef  otinum atan2(otinum valx, otinum valy):
  """
  PURPOSE:  Mathematical function of arctangent for OTI numbers
   
  EXAMPLE:   
  """
  #***************************************************************************************************
  global p_dH
  cdef otinum_t res
  
  c_oti_atan2(&valx.num, &valy.num, p_dH, &res)

  return otinum.create(&res)
#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cpdef  otinum acos(otinum val):
  """
  PURPOSE:  Mathematical function of inverse cosine for OTI numbers
   
  EXAMPLE:   
  """
  #***************************************************************************************************
  global p_dH
  cdef otinum_t res
  
  c_oti_acos(&val.num, p_dH, &res)

  return otinum.create(&res)
#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cpdef  otinum asin(otinum val):
  """
  PURPOSE:  Mathematical function of inverse sine for OTI numbers
   
  EXAMPLE:   
  """
  #***************************************************************************************************
  global p_dH
  cdef otinum_t res
  
  c_oti_asin(&val.num, p_dH, &res)

  return otinum.create(&res)
#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cpdef  otinum sinh(otinum val):
  """
  PURPOSE:  Mathematical function of hyperbolic sine for OTI numbers
   
  EXAMPLE:   
  """
  #***************************************************************************************************
  global p_dH
  cdef otinum_t res
  
  c_oti_sinh(&val.num, p_dH, &res)

  return otinum.create(&res)
#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cpdef  otinum asinh(otinum val):
  """
  PURPOSE:  Mathematical function of inverse hyperbolic sine for OTI numbers
   
  EXAMPLE:   
  """
  #***************************************************************************************************
  global p_dH
  cdef otinum_t res
  
  c_oti_asinh(&val.num, p_dH, &res)

  return otinum.create(&res)
#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cpdef  otinum cosh(otinum val):
  """
  PURPOSE:  Mathematical function of hyperbolic cosine for OTI numbers
   
  EXAMPLE:   
  """
  #***************************************************************************************************
  global p_dH
  cdef otinum_t res
  
  c_oti_cosh(&val.num, p_dH, &res)

  return otinum.create(&res)
#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cpdef  otinum acosh(otinum val):
  """
  PURPOSE:  Mathematical function of inverse hyperbolic cosine for OTI numbers
   
  EXAMPLE:   
  """
  #***************************************************************************************************
  global p_dH
  cdef otinum_t res
  
  c_oti_acosh(&val.num, p_dH, &res)

  return otinum.create(&res)
#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cpdef  otinum tanh(otinum val):
  """
  PURPOSE:  Mathematical function of hyperbolic tangent for OTI numbers
   
  EXAMPLE:   
  """
  #***************************************************************************************************
  global p_dH
  cdef otinum_t res
  
  c_oti_tanh(&val.num, p_dH, &res)

  return otinum.create(&res)
#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cpdef  otinum atanh(otinum val):
  """
  PURPOSE:  Mathematical function of Inverse hyperbolic tangent for OTI numbers
   
  EXAMPLE:   
  """
  #***************************************************************************************************
  global p_dH
  cdef otinum_t res
  
  c_oti_atanh(&val.num, p_dH, &res)

  return otinum.create(&res)
#-----------------------------------------------------------------------------------------------------


#*****************************************************************************************************
cpdef  otinum logb(otinum val, int base):
  """
  PURPOSE:  Natural logarithm base b for OTI numbers.
   
  EXAMPLE:   
  """
  #***************************************************************************************************  

  
  global p_dH
  cdef otinum_t res
  

  c_oti_logb(&val.num, base, p_dH, &res)

  return otinum.create(&res)
#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cpdef  otinum log10(otinum val):
  """
  PURPOSE:  Natural logarithm base 10 for OTI numbers.
   
  EXAMPLE:   
  """
  #***************************************************************************************************  

  
  global p_dH
  cdef otinum_t res
  

  c_oti_log10(&val.num, p_dH, &res)

  return otinum.create(&res)
#-----------------------------------------------------------------------------------------------------


#*****************************************************************************************************
cpdef  otinum log(otinum val):
  """
  PURPOSE:  Natural logarithm for OTI numbers.
   
  EXAMPLE:   
  """
  #***************************************************************************************************  
  #Natural Logarithm
  
  global p_dH
  cdef otinum_t res
  

  c_oti_log(&val.num, p_dH, &res)

  return otinum.create(&res)
#-----------------------------------------------------------------------------------------------------


#*****************************************************************************************************
cpdef  otinum exp(otinum val):
  """
  PURPOSE:  Exponential function for OTI numbers.
   
  EXAMPLE:   
  """
  #*************************************************************************************************** 
  
  # create an array that contains the 
  # Compute all derivatives of the function 
  # up to max order of the number.
  global p_dH
  cdef otinum_t res
  

  c_oti_exp(&val.num, p_dH, &res)

  return otinum.create(&res)
#-----------------------------------------------------------------------------------------------------


#*****************************************************************************************************
cpdef  otinum power(otinum val, double exponent):
  """
  PURPOSE:  Power function for OTI numbers, for non integer exponents.
   
  EXAMPLE:   
  """
  #*************************************************************************************************** 
  global p_dH
  cdef otinum_t res

  c_oti_pow(&val.num, exponent, p_dH, &res)

  return otinum.create(&res)
#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cpdef  otinum sqrt(otinum val):
  """
  PURPOSE:  Square root function for OTI numbers, for non integer exponents.
   
  EXAMPLE:   
  """
  #*************************************************************************************************** 
  global p_dH
  cdef otinum_t res

  c_oti_sqrt(&val.num, p_dH, &res)

  return otinum.create(&res)
#-----------------------------------------------------------------------------------------------------







#*****************************************************************************************************
def e(dirArray,uint8_t order = 1,uint16_t m = 0):
  """
  PURPOSE:  To create a dual number with value 1 at the specified
            dual direction, in a human friendly manner.

  EXAMPLE:  >>> e(2)
            1.0 * e(2)
            
            >>> e([1,2])
            1.0 * e([1,2])
            
            >>> e([1,[2,3]])
            1.0 * e([1,[2,3]])
  """
  #***************************************************************************************************
  

  global h
  global p_dH

  cdef uint8_t orderi
  cdef uint16_t* p_dirA
  cdef uint8_t* p_expA
  cdef uint8_t i
  cdef uint64_t indx, size
  cdef otinum_t num
  cdef uint16_t m_max = 0

  if type(dirArray)==int:
    
    if m == 0:

      size = h.getNels(dirArray, order)

    else: 

      size = h.getNels(m, order)

    # end if 

    num.p_coefs = <double* >malloc(size*sizeof(double))
    if not num.p_coefs:
      raise MemoryError()
    # end if 

    memset(num.p_coefs,0,size*sizeof(double))
    num.Ndir = size
    num.order = order

    if order == 1:

      indx = dirArray

    else:

      p_dirA = h.c_getUDirA(order,n=1)
      p_expA = h.c_getUExpA(order,n=1)
      
      p_dirA[ZERO] = dirArray
      p_expA[ZERO] = 1

      for i in range(1,order):

        p_dirA[i] = 0
        p_expA[i] = 0

      # end for 

      indx = c_helper_findIndex(p_dirA,p_expA,order,p_dH)

    # end if 

    if indx < num.Ndir:

      num.p_coefs[indx] = 1.0

    # end if
    
    return otinum.create(&num)
    
  # end if



  # CASE dirArray is list:::
    
  c_getDirExpA(dirArray, &p_dirA, &p_expA, &orderi)

  for i in range(10):#orderi):  # Unsafe if more order is given...

    if p_dirA[i] == 0:
    
      break

    # end if 

    m_max = c_maxUI16(p_dirA[i],m_max)

  # end for

  orderi = max(order,orderi)

  if m != 0:
  
    m_max = m

  # end if

  size = h.getNels(m_max, orderi)

  num.p_coefs = <double* >malloc(size*sizeof(double))
  if not num.p_coefs:
    raise MemoryError()
  # end if 

  memset(num.p_coefs,0,size*sizeof(double))
  num.Ndir = size
  num.order = orderi

  if order == 0:
      
    indx = 0

  else:

    indx = h.c_findIndx(p_dirA,p_expA,num.order)

  # end if

  if indx  < num.Ndir:
    num.p_coefs[indx] = 1.0
  
  return otinum.create(&num)

#-----------------------------------------------------------------------------------------------------



























