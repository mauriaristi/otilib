# cdef uint64_t[::1] arr_nnz = np.zeros(150)


# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::     CLASS  SPR_OTINUM   :::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
cdef class sotinum:
  """
  This is the base class that supports sparse OTI numbers (scalars). 
  This class provides operator overloads to must arithmetic operations and elementary functions
  to seamlessly support OTI-algebra within python functions.

  The constructor of the sotinum class contains the following elements:

  :param re_coeff: Real coefficient of the imaginary number.
  :type re_coeff: float

  :param nbases: Number of bases to allocate memory.
  :type nbases: int, optional

  :param order: Truncation order of the number.
  :type order: int, optional

  :param FLAGS: Integer with flags associated to this object. The first bit active (FLAGS & 1) 
      indicates that the memory is owned by this instance of the object.
  :type FLAGS: int, optional

  :param nnz: Integer list with number of non-zeroes per order to allocate memory.
  :type nnz: list, optional


  The attributes of a sotinum object are the following:

  :attr real: Real coefficient of the sotinum object (float)

  :cvar order: Truncation order of the number (int).
  :cvar actual_order: Actual order of the number (int). Typically actual_order <= order
  :cvar nnz: Number of non zero coefficients in the number.
  :cvar FLAGS: Flags of the object (int).

  This class provides overloads to the following operators (a and b are sotinum objects):

  .. list-table:: Overloaded operations
    :widths: 50 25 25
    :header-rows: 1

    * - Operator 
      - Symbol
      - Notes 
    * - Negation
      - ``-x``
      - 
    * - Addition
      - ``x+y``
      - 
    * - Subtraction
      - ``x-y``
      - 
    * - Multiplication
      - ``x*y``
      - 
    * - Division
      - ``x/y``
      - 
    * - Power
      - ``x**y``
      - 
    * - Sine
      - ``sin(x)``
      - 
    * - Cosine
      - ``cos(x)``
      - 
    * - Tangent
      - ``tan(x)``
      - 
    * - Hyperbolic Sine
      - ``sinh(x)``
      - 
    * - Hyperbolic Cosine
      - ``cosh(x)``
      - 
    
  Example:
  
  .. code-block:: python
    :linenos:

    import pyoti.sparse as oti

    x = oti.sotinum(1.5,nbases=3,order=1)
    print(x)
    
    # Set the first order imaginary directions to 1.
    x[[0,1]] = 1
    x[[1,1]] = 2
    x[[2,1]] = 3

    print(x)

  .. code-block:: python
    
    >>> 1.5 + 1 * e([1]) + 2 * e([2]) + 3 * e([3])

  """
  
  #---------------------------------------------------------------------------------------------------
  #------------------------------------   DEFINITION OF ATTRIBUTES   ---------------------------------
  #---------------------------------------------------------------------------------------------------
  #
  #                                     --< Look in "sparse.pxd" >--
  #
  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  def __init__(self, coeff_t re_coeff, bases_t nbases = 0,ord_t order = 0, uint8_t FLAGS = 1, 
    object nnz = None):
    """
    Constructor of a sparse OTI number.

    :param re_coeff: Real coefficient, which must be real scalar. (coeff_t re_coeff)
    :param nbases: Integer which defines number of bases to allocate the number. (bases_t nbases = 0)
    :param order: Integer (ord_t order = 0 )
    :param FLAGS: Flags. Unused in this moment. (uint8_t FLAGS = 1)
    :param nnz: Number of non zeros. List with (object nnz = None)

    """
    #*************************************************************************************************
    global dhl, ONE, ZERO
    

    # Add warning for higher orders and orders that are not required
    self.FLAGS = FLAGS
    cdef ndir_t* p_nnz # Static allocation of this array.
    cdef ord_t orderdef, i, size
    
    
    # First initialize the number.
    self.num = soti_init()

    # In case that nnz was defined.
    if nnz is not None:
      
      size = len(nnz)
      orderdef = max(size,order)

      p_nnz = dhl.p_dh[dhl.ndh-ONE].p_nnz[ZERO]

      for i in range(size):
        p_nnz[i] = nnz[i]
      # end for 

      for i in range(size,orderdef):
        p_nnz[i] = ZERO
      # end for 
      
      self.num =  soti_createEmpty_predef(p_nnz, orderdef, dhl)

      # Set real coefficient.
      self.num.re = re_coeff
    
    elif nbases != 0 and order !=0 :

      p_nnz = dhl.p_dh[order-ONE].p_nnz[ZERO]

      for i in range(order):
        p_nnz[i] = dhelp_extract_ndirOrder( nbases, i+1, dhl )
      # end for 
      
      self.num =  soti_createEmpty_predef(p_nnz, order, dhl)

      # Set real coefficient.
      self.num.re = re_coeff  

    else:
      
      self.num =  soti_createReal(re_coeff, order, dhl)
    
    # end if 

  #---------------------------------------------------------------------------------------------------  

  #***************************************************************************************************
  def __dealloc__(self): 
    """
    Destructor of the class. Frees all memory from the object.
                  
    """
    #*************************************************************************************************
    
    if self.FLAGS & 1: # If memory is owned by this otinum.

      soti_free(&self.num)

    #end if 
    
  #---------------------------------------------------------------------------------------------------
  

  #***************************************************************************************************
  @property
  def  order(self): 
    """
    PURPOSE:      returns the maximum truncation order of the number.

    DESCRIPTION:  Reads the value in num.
                  
    """
    #*************************************************************************************************

    return self.num.trc_order

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  @property
  def  actual_order(self): 
    """
    PURPOSE:      returns the actual order of the number (may not coincide with the truncation order).

    DESCRIPTION:  Reads the value in num.
                  
    """
    #*************************************************************************************************

    return self.num.act_order

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  @property
  def  nnz(self): 
    """
    PURPOSE:      returns the number of non-zero elements in the number. Only accounts for the 

    DESCRIPTION:  Reads the value in num.
                  
    """
    #*************************************************************************************************
    cdef int ndir_total = 1

    for i in range(0, self.num.trc_order):

      ndir_total += self.num.p_nnz[i]

    # end for

    return ndir_total

  #---------------------------------------------------------------------------------------------------
  

  #***************************************************************************************************
  @property
  def  real(self): 
    """
    PURPOSE:      returns the real coefficient of the OTI number.

    DESCRIPTION:  Reads the value in num.
                  
    """
    #*************************************************************************************************

    return self.num.re

  #---------------------------------------------------------------------------------------------------


  #***************************************************************************************************
  @real.setter
  def  real(self, value): 
    """
    PURPOSE:      Sets the real coefficient of an OTI number

    DESCRIPTION:  Sets the real coefficient in num.
                  
    """
    #*************************************************************************************************

    self.num.re = value

  #---------------------------------------------------------------------------------------------------


  #***************************************************************************************************
  @staticmethod
  cdef sotinum create( sotinum_t* num, uint8_t FLAGS = 1 ):
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
    cdef sotinum otin = <sotinum> sotinum.__new__(sotinum)


    otin.num.re        = num[ZERO].re    
    otin.num.p_im      = num[ZERO].p_im  
    otin.num.p_idx     = num[ZERO].p_idx 
    otin.num.p_nnz     = num[ZERO].p_nnz 
    otin.num.p_size    = num[ZERO].p_size
    otin.num.act_order = num[ZERO].act_order
    otin.num.trc_order = num[ZERO].trc_order
    otin.num.flag      = num[ZERO].flag  

    otin.FLAGS         = FLAGS
    
    return otin

  #--------------------------------------------------------------------------------------------------- 

  #***************************************************************************************************
  @staticmethod
  cdef sotinum init(  ):
    """
    PURPOSE:      Initialize memory for OTI num.

    DESCRIPTION:  Resets all pointer addresses to null, to avoid wrong memory reads.

    RESULT:       
            A new otinum python object.
                  
    """
    #*************************************************************************************************

    # create new empty object:
    cdef sotinum otin = <sotinum> sotinum.__new__(sotinum)

    otin.num        = soti_init()

    otin.FLAGS      = 1
    
    return otin

  #--------------------------------------------------------------------------------------------------- 


  #*************************************************************************************************** 
  def __repr__(self):
    """
    PURPOSE:  To print a representation of the sotinum object in a compact form.
    """
    #*************************************************************************************************
    global dhl
    global h

    
    cdef ord_t ordi, j
    cdef ndir_t i;
    cdef bases_t* dirs;

    head      = ''
    body      = ''

    append_ldots = False
    break_bool   = False
    
    termsPrtd = 0 # Count the number of terms printed. 
    
    # Print real part
    if self.num.re != 0:
      body += ('%'+floatFormat)%self.num.re
      termsPrtd += 1
    # end if 


    for ordi in range(0,self.num.act_order):

      for i in range(self.num.p_nnz[ordi]):
        
        num = ('%+'+floatFormat)%self.num.p_im[ordi][i] 
        body += ' '+num[0]+" "+num[1:]
        body += ' * e(' 
        
        body += str(h.get_compact_fulldir(self.num.p_idx[ordi][i],ordi+1)).replace(' ','')
        body += ")"
        
        termsPrtd += 1
        
        if termsPrtd == termsPrint:
          
          if (i < (self.num.p_nnz[ordi]-1)):
            append_ldots = True 
          # end if

          break_bool = True

          break

        # end if

      # end for
      
      if break_bool: # TODO: Find cleaner way to break from the two loops
        
        if ( ordi < ( self.num.act_order - 1 ) ):
          append_ldots = True
        # end if 

        break
      
      # end if

    # end for 

    if append_ldots:    
      body += " + ... "
    # end if 

    # Final, check if anything was printed at all
    if termsPrtd == 0:
      body += ('%'+floatFormat)%self.num.re
      termsPrtd += 1
    # end if 
      
    tail = ''
    
    return (head + body + tail)

  #--------------------------------------------------------------------------------------------------- 

  #*************************************************************************************************** 
  def short_repr(self):
    """
    PURPOSE:  To print a representation of the sotinum object in a compact form.
    """
    #*************************************************************************************************
    global h
    global p_dH

    cdef ndir_t ndir_total = 1, i;

    for i in range(0, self.num.act_order):

      ndir_total += self.num.p_nnz[i]

    # end for

    head = 'sotinum('
    body = str(self.num.re) + ", nnz: " + str(ndir_total) + ', order: ' + str(self.num.act_order)
    tail = ')'

    return (head + body + tail)

  #---------------------------------------------------------------------------------------------------  

  #*************************************************************************************************** 
  def get_nnz_full(self):
    """
    PURPOSE:  Get the number of non zeros (nnz) in the number, with the following format:
            
             [ total_nnz,        # actual nnz active in the number.
               max_nnz_storable, # related with reserved memory.
               [nnz_1,nnz_2,...],# array with the nnz for each order of derivative.
               [size_1,size_2,...],# array with the size for each order of derivative.
               ] 
    """
    #*************************************************************************************************
    global h
    global p_dH

    cdef ndir_t nnz_i, size_i, total_nnz = 1, max_nnz_storable = 1, i;
    cdef np.ndarray nnz = np.zeros(self.num.trc_order,dtype=int)
    cdef np.ndarray size= np.zeros(self.num.trc_order,dtype=int)

    for i in range(0, self.num.trc_order):
      
      nnz_i  = self.num.p_nnz[i]
      size_i = self.num.p_size[i]
      
      total_nnz += nnz_i
      max_nnz_storable   += size_i

      nnz[i]  = nnz_i
      size[i] = size_i

    # end for

    return [total_nnz,max_nnz_storable,nnz,size]

  #--------------------------------------------------------------------------------------------------- 

  #*************************************************************************************************** 
  def long_repr(self):
    """
    PURPOSE:  To print a representation of the sotinum object in a full detail form.
    """
    #*************************************************************************************************
    global h
    global p_dH

    cdef ndir_t ndir_total = 1, ndir_max = 1, i;

    for i in range(0, self.num.trc_order):

      ndir_total += self.num.p_nnz[i]
      ndir_max   += self.num.p_size[i]

    # end for

    head = 'sotinum('
    body = str(self.num.re) + ", nnz: " + str(ndir_total)+", alloc: " + str(ndir_max) 
    body += ', actual order: ' + str(self.num.act_order) 
    body += ', truncation order: ' + str(self.num.trc_order) 
    body += ', flag: ' + str(self.num.flag) + "\n"

    for i in range(0, self.num.trc_order):

      body += "  - Order {0}->   nnz: {1}  size: {2} \n".format(i+1, self.num.p_nnz[i],self.num.p_size[i])

    # end for 

    tail = ')'

    return (head + body + tail)

  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  def __str__(self):
    """
    PURPOSE: To print a representation of the sotinum object that could 
             be easy to read and understand.  
    
    """
    #*************************************************************************************************
    
    global dhl
    global h

    
    cdef ord_t ordi, j
    cdef ndir_t i;
    cdef bases_t* dirs;

    head      = ''
    body      = ''

    append_ldots = False
    break_bool   = False
    
    termsPrtd = 0 # Count the number of terms printed. 
    
    # Print real part
    if self.num.re != 0:
      body += ('%'+floatFormat)%self.num.re
      termsPrtd += 1
    # end if 


    for ordi in range(0,self.num.act_order):

      for i in range(self.num.p_nnz[ordi]):
        
        num = ('%+'+floatFormat)%self.num.p_im[ordi][i] 
        body += ' '+num[0]+" "+num[1:]
        body += ' * e(' 
        
        body += str(h.get_compact_fulldir(self.num.p_idx[ordi][i],ordi+1)).replace(' ','')
        body += ")"
        
        termsPrtd += 1
        
        if termsPrtd == termsPrint:
          
          if (i < (self.num.p_nnz[ordi]-1)):
            append_ldots = True 
          # end if

          break_bool = True

          break

        # end if

      # end for
      
      if break_bool: # TODO: Find cleaner way to break from the two loops
        
        if ( ordi < ( self.num.act_order - 1 ) ):
          append_ldots = True
        # end if 

        break
      
      # end if

    # end for 

    if append_ldots:    
      body += " + ... "
    # end if 

    # Final, check if anything was printed at all
    if termsPrtd == 0:
      body += ('%'+floatFormat)%self.num.re
      termsPrtd += 1
    # end if 
      
    tail = ''
    
    return (head + body + tail)

  #---------------------------------------------------------------------------------------------------  

  #***************************************************************************************************
  def __getitem__(self, list index):
    """
    PURPOSE:  To get the value of a sotinum coefficient.

    """
    #*************************************************************************************************
    global dhl

    cdef imdir_t idx = index[ZERO]
    cdef ord_t order = index[ONE]
    return soti_get_item( idx, order, &self.num, dhl)

  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  def __setitem__(self, list item, coeff_t value):
    """
    PURPOSE:  To set the value of a sotinum coefficient.

    """
    #*************************************************************************************************
    
    global dhl

    cdef int i = 0, j = 1
    cdef imdir_t index = item[i]
    cdef ord_t   order = item[j]

    soti_set_item( value, index, order, &self.num, dhl)

  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  def __neg__(self):
    """
    PURPOSE:      Negate a sotinum

    """
    #*************************************************************************************************
    
    global dhl

    cdef sotinum_t res = soti_neg(&self.num, dhl)

    return sotinum.create(&res)

  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  def __add__(self, other_in):
    """
    PURPOSE:      Add sotinum with other things.

    """
    #*************************************************************************************************
    
    global dhl
    cdef: 
      sotinum_t res
      sotinum tmp1, tmp2
      
    type1 = type(self)     # takes 100 ns ... 
    type2 = type(other_in) # takes 100 ns ...

    # type1 = self.__class__     # takes ~50 ns ... 
    # type2 = other_in.__class__ # takes ~50 ns ...
    
    if ( type1 is type2) : # Case Sum between OTIs.
      tmp1 = self
      tmp2 = other_in
      res =  soti_sum_oo(&tmp1.num, &tmp2.num, dhl);
    
    elif (type2 in number_types): # Case Sum to real number. Very slow, consider changing this...
      
      tmp1 = self
      res = soti_sum_ro( other_in, &tmp1.num, dhl);

    elif (type1 in number_types): # Case 1.5. reverse Sum to real number.
      
      tmp1 = other_in
      res = soti_sum_ro( self, &tmp1.num, dhl);

    else:

      return NotImplemented

    # end if 
      
      
    return sotinum.create(&res)


  #---------------------------------------------------------------------------------------------------  




  #***************************************************************************************************
  def __iadd__(self, other_in):
    """
    PURPOSE:      To define how to sum two spr_otinum numbers.

    DESCRIPTION:  It overloads the inplace sum operator "+=". It allows the 
                  addition of spr_otinum numbers of different orders, and 
                  the addition of a spr_otinum number and a scalar. 
    
    """
    #*************************************************************************************************
    

    return self + other_in

  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  def __sub__(self, other_in):
    """
    PURPOSE:      To define how to subtract two spr_otinum numbers.

    DESCRIPTION:  It overloads the subtract operator "-". It allows the 
                  subtraction of spr_otinum numbers of different orders, 
                  and the subtraction of a spr_otinum number and a scalar. 
    
    EXAMPLE:      >>> a = spr_otinum([0,4,17], [1.,3.,5.], 2)
                  >>> b = spr_otinum([0,2,4], [7.,9.,11.], 2)
                  >>> a - b
                  spr_otinum([0,2,4,17], [-6.,-9.,-8.,5.], 2)
                  
                  >>> a = spr_otinum([0,4,17], [1.,3.,5.], 2)
                  >>> a - 15
                  spr_otinum([0,4,17], [-14.,3.,5.], 2)
    """
  #************************************************************************
    global dhl
    cdef: 
      sotinum_t res
      sotinum tmp1, tmp2
      
    type1 = type(self)     # takes 100 ns ... 
    type2 = type(other_in) # takes 100 ns ...

    # type1 = self.__class__     # takes ~50 ns ... 
    # type2 = other_in.__class__ # takes ~50 ns ...
    
    if ( type1 is type2) : # Case Sum between OTIs.
      tmp1 = self
      tmp2 = other_in
      res =  soti_sub_oo(&tmp1.num, &tmp2.num, dhl);
    
    elif (type2 in number_types): # Case Sum to real number. Very slow, consider changing this...
      
      tmp1 = self
      res = soti_sub_or(&tmp1.num, other_in, dhl);

    elif (type1 in number_types): # Case 1.5. reverse Sum to real number.
      
      tmp1 = other_in
      res = soti_sub_ro(self, &tmp1.num, dhl);   

    else:

      return NotImplemented

    # end if 
      
      
    return sotinum.create(&res)

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
  
    # self = self - other_in

    return self - other_in

  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  def __mul__(self, other_in):
    """
    PURPOSE:      To define how to multiply two OTI numbers.
    
    DESCRIPTION:  It overloads the multiplication operator "*". It allows
                  the multiplication of OTI numbers of different 
                  orders, no matter how they are sorted, or even the 
                  multiplication of an OTI number and a scalar. 
    
    EXAMPLE:      >>> a = spr_otinum([0,4,17], [1.,3.,5.], 2)
                  >>> b = spr_otinum([0,2,4], [7.,9.,11.], 2)
                  >>> a * b
                  spr_otinum([0,2,4,8,17], [7.,9.,32.,33.,35.], 2)
    """
    #*************************************************************************************************
    
    global dhl
    cdef: 
      sotinum_t res
      sotinum tmp1, tmp2
      
    type1 = type(self)     # takes 100 ns ... 
    type2 = type(other_in) # takes 100 ns ...

    # type1 = self.__class__     # takes ~50 ns ... 
    # type2 = other_in.__class__ # takes ~50 ns ...


    if ( type1 is type2) : # Case Sum between OTIs.

      tmp1 = self
      tmp2 = other_in
      res = soti_mul_oo( &tmp1.num, &tmp2.num, dhl)
    
    elif (type2 in number_types): # Case Sum to real number. Very slow, consider changing this...
      
      tmp1 = self
      res = soti_mul_ro( other_in, &tmp1.num, dhl);

    elif (type1 in number_types): # Case 1.5. reverse Sum to real number.
      
      tmp1 = other_in
      res = soti_mul_ro( self, &tmp1.num, dhl);       

    else:

      return NotImplemented

    # end if 

    return sotinum.create(&res)

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
    """
    #*************************************************************************************************

    return self * other_in

  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  def __truediv__(self, other_in):
    """
    PURPOSE:      To define how to divide two sotinum numbers.
    
    DESCRIPTION:  It overloads the division operator "/". It allows the
                  division of spr_otinum numbers of different orders, and 
                  the division of a spr_otinum number and a scalar. 
    """
    #*************************************************************************************************
    
    
    global dhl
    global p_dH

    cdef sotinum S
    cdef sotinum O
    cdef sotinum_t res = soti_init()

    type1 = type(self)     # takes 100 ns ... 
    type2 = type(other_in) # takes 100 ns ...

    if type1 == type2:  
      
      S = self
      O = other_in

      res = soti_div_oo(&S.num,&O.num,dhl)
      
    elif type2 in number_types:   # Case 1. Mult to real scalar. 
      
      S = self
      res = soti_div_or(&S.num,other_in,dhl)
    
    elif type1 in number_types:   # Case 1.5. Reverse Mult to real scalar.
      
      O = other_in
      res = soti_div_ro( self, &O.num, dhl)
      
    else:

      return NotImplemented

    # end if 

    return sotinum.create(&res)

  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  def __pow__(self, n,z):
    """
    Power function of sparse oti numbers.

    
    """
    #*************************************************************************************************
    
    global dhl

    cdef sotinum_t res
    cdef sotinum S = self

    res = soti_pow(&S.num, n, dhl)
    
    return sotinum.create(&res)

  #---------------------------------------------------------------------------------------------------  


  #  =================================================================================================
  #  ------------------------------------   UTIL. FUNCTIONS  -----------------------------------------
  #  =================================================================================================

  #***************************************************************************************************
  cpdef set(self, object rhs):
    """
    Set the sotinum's object coefficients from the given value. This can be useful to avoid 
    unnecessary memory allocations.
    
    :param val: Value to be set. 
    :type val: float, int or sotinum. 

    """
    #*************************************************************************************************
    global dhl

    cdef sotinum orhs
    cdef coeff_t rrhs
    trhs = type(rhs)

    if trhs is sotinum:

      orhs = rhs
      soti_set_o( &orhs.num, &self.num, dhl)

    else:
      rrhs = rhs
      soti_set_r( rrhs, &self.num, dhl)      

    # end if 

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  cpdef  set_im( self,  object val, object humdir):
    """
    Set a specific imaginary direction with the given coefficient.


    :param val:  Value to be set.
    :type val: float, int

    :param humdir: Imaginary direction given by the basis and exponents. Example [1,2,2]
    :type val: int or list.

    """
    #*************************************************************************************************
    global dhl

    cdef imdir_t indx
    cdef ord_t  order
    cdef sotinum oval
    cdef coeff_t rval
    indx, order = imdir(humdir)
    tval = type(val)

    if tval is sotinum:
      
      oval = val
      soti_set_im_o( &oval.num, indx, order, &self.num, dhl) 

    else:

      rval = val
      soti_set_im_r( val, indx, order, &self.num, dhl) 

    # end if 

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  cpdef  set_deriv( self,  object val, object humdir):
    """
    Sets an imaginary coefficient grom the given derivative.

    :param val:  Derivative value to be set.
    :type val: float, int

    :param humdir: Imaginary direction given by the basis and exponents. Example [1,2,2]
    :type val: int or list.
    
    """
    #*************************************************************************************************
    global dhl

    cdef imdir_t indx
    cdef ord_t  order
    cdef sotinum oval
    cdef coeff_t rval
    indx, order = imdir(humdir)
    tval = type(val)

    if tval is sotinum:
      
      oval = val
      soti_set_deriv_o( &oval.num, indx, order, &self.num, dhl) 

    else:

      rval = val
      soti_set_deriv_r( val, indx, order, &self.num, dhl) 

    # end if 

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  cpdef  truncate( self, object humdir):
    """
    Removes (sets zero) all coefficients along imaginary directions multiple to the given 
    imaginary direction.

    :param humdir:    Imaginary direction given by the basis and exponents. Example [1,2,2]

    """
    #*************************************************************************************************
    global dhl

    cdef imdir_t indx
    cdef ord_t  order
    cdef sotinum_t res
    
    indx, order = imdir(humdir)
    
    res = soti_truncate_im( indx, order, &self.num, dhl) 

    return sotinum.create(&res)
  #---------------------------------------------------------------------------------------------------
  
  #***************************************************************************************************
  cpdef  truncate_order( self, ord_t order):
    """
    Truncates all imaginary directions with order equal or larger than the one specified.

    :param order: Order to be truncated.

    """
    #*************************************************************************************************
    global dhl

    cdef imdir_t indx
    cdef sotinum_t res
    
    res = soti_truncate_order( order, &self.num, dhl) 

    return sotinum.create(&res)

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  cpdef get_deriv( self, object humdir):
    """
    Retrieves the derivative contained in the oti number.

    :param humdir: Imaginary direction given by the basis and exponents. Example [1,2,2]

    """
    #*************************************************************************************************
    global dhl

    cdef imdir_t indx
    cdef ord_t  order

    indx, order = imdir(humdir)
    return soti_get_deriv(indx,order, &self.num, dhl) 

  #--------------------------------------------------------------------------------------------------- 

  #***************************************************************************************************
  cpdef get_im( self, object humdir):
    """
    Retrieves the coefficient along the indicated imaginary direction direction.

    :param humdir: Imaginary direction given by the basis and exponents. Example [1,2,2]

    """
    #*************************************************************************************************
    global dhl

    cdef imdir_t indx
    cdef ord_t  order

    indx, order = imdir(humdir)
    return soti_get_item(indx,order, &self.num, dhl) 

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  cpdef extract_im( self, object humdir):
    """
    Retrieves the OTI number formed by all coefficients multiple of the given imagianry direction.
    It extracts the coefficients by dividing each direction by the given direction and determining 
    if it is possible to extract the corresponding coefficients.

    :param humdir: Imaginary direction given by the basis and exponents. Example [1,2,2]

    """
    #*************************************************************************************************
    global dhl

    cdef imdir_t indx
    cdef ord_t  order
    cdef sotinum_t res
    
    indx, order = imdir(humdir)

    res = soti_extract_im(indx,order, &self.num, dhl) 

    return sotinum.create(&res)

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  cpdef extract_deriv( self, object humdir):
    """
    Similar to extract_im, this function retrieves the OTI number formed by all coefficients multiple 
    of the given imagianry direction. However, this function also sets up the resulting OTI number
    such that the resulting OTI number contains the correct derivatives

    :param humdir: Imaginary direction given by the basis and exponents. Example [1,2,2]

    """
    #*************************************************************************************************
    global dhl

    cdef imdir_t indx
    cdef ord_t  order
    cdef sotinum_t res
    
    indx, order = imdir(humdir)

    res = soti_extract_deriv(indx,order, &self.num, dhl)

    return sotinum.create(&res)

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  cpdef get_order_im( self, ord_t order):
    """
    Extract an OTI number with only the imagianry directions of the given order.

    :param order: Order of imaginary directions to get.

    """
    #*************************************************************************************************
    global dhl

    cdef sotinum_t res
    
    res = soti_get_order_im( order, &self.num, dhl)

    return sotinum.create(&res)

  #---------------------------------------------------------------------------------------------------


  #***************************************************************************************************
  def copy(self):
    """
    Create a copy of the object.

    """
    #*************************************************************************************************
    global dhl

    cdef sotinum_t res = soti_copy( &self.num, dhl )
    return sotinum.create(&res)

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  def get_active_bases(self):
    """
    Get all the active bases.

    """
    #*************************************************************************************************
    global dhl

    cdef bases_t  size = dhl.p_dh[0].Nbasis
    cdef imdir_t* bases_list = dhl.p_dh[0].p_idx[0]
    cdef uint64_t i
    
    # Initialize all elements as zero (deactivated)
    for i in range(size):

      bases_list[i]=0

    # end for 

    soti_get_active_bases( &self.num, bases_list, dhl)

    res = []
    for i in range(size):

      if bases_list[i]==1:
      
        res.append(i+1)

      # end if 

    # end for 

    return res

  #---------------------------------------------------------------------------------------------------


  #***************************************************************************************************
  def rom_eval(self, object bases, object deltas):
    """
    Evaluate the Taylor series from the coefficients with in the OTI number.
 
    :param bases:  Python list of Imaginary bases to evaluate the ROM
    :param deltas: Python list float coefficients to evaluate the ROM (can be a 1D numpy array).

    """
    #*************************************************************************************************
    global dhl

    cdef bases_t  size 
    cdef coeff_t* c_deltas = dhl.p_dh[0].p_im[0]
    cdef int64_t i
    cdef sotinum_t res #= soti_init()
    
    if len(bases) != len(deltas):
    
      raise ValueError("Both bases and deltas must have the same dimension")

    # end if 

    # Get the maximum active basis in the number.
    size = soti_get_max_basis(&self.num, dhl)

    # Initialize all elements as zero
    memset( c_deltas, 0, size*sizeof(coeff_t) )

    for i in range( min( len(bases) , size ) ):

      c_deltas[ bases[i] - 1 ] = deltas[i]

    # end for 

    res = soti_taylor_integrate( c_deltas, &self.num, dhl)

    return sotinum.create(&res)

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  def rom_eval_array(self, object bases, object deltas):
    """
    Evaluate the Taylor series from the coefficients with in the OTI number.

    :param bases:  Python list of Imagiary bases to evaluate the ROM
    :param deltas: Python list with arrays of coefficients of the deltas to evaluate the ROM.
        Arrays must be numpy arrays, and be of the same shape.
 

    """
    #*************************************************************************************************
    global dhl

    cdef bases_t  size #= dhl.p_dh[0].Nbasis
    cdef int64_t ordi, j, i
    cdef imdir_t idx, idxi
    cdef coeff_t coeff
    cdef np.ndarray res, prod, base, exp
    cdef bases_t* fulldir
    
    
    if len(bases) != len(deltas):
    
      raise ValueError("Both bases and deltas must have the same dimension")

    # end if 

    # Get the maximum active basis in the number.
    size = soti_get_max_basis(&self.num, dhl)

    shape = (size,)+deltas[0].shape
    deltas_eval = np.zeros( shape )

    for i in range( min( len(bases) , size ) ):

      deltas_eval[ bases[i] - 1 ] = deltas[i]

    # end for 

    # Evaluate the ROM:
    res = np.zeros_like(deltas[0])
    res += self.num.re

    prod = np.zeros_like(deltas[0])

    # order 1 and up.
    for ordi in range(self.num.act_order):
      
      for idxi in range(self.num.p_nnz[ordi]):
        
        # Get index and coefficient for current im. direction.
        idx   = self.num.p_idx[ordi][idxi]
        coeff = self.num.p_im[ordi][idxi]

        # Method 1: 182 ms
        # Get the imag direction full coefficient
        fulldir = dhelp_get_imdir( idx, ordi+1, dhl);
        
        # Multiply all deltas for this term:
        prod[:] = coeff
        for j in range(ordi+1):
          i = fulldir[j]-1
          prod *= deltas_eval[i]
        # end for

        # base,exp = h.get_base_exp(idx, ordi+1)

        res += prod 

      # end for

    # end for 


    return res

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  def rom_eval_object(self, object bases, object deltas):
    """
    PURPOSE:     Evaluate the Taylor series from the coefficients with in the OTI number.

    INPUTS: 
      - bases:  Python list of Imagiary bases to evaluate the ROM
      - deltas: Python list object coefficients with multiple deltas to evaluate the ROM.

    EXAMPLE:
      >>> 

    """
    #*************************************************************************************************
    global dhl

    cdef bases_t  size 
    cdef int64_t ordi, j, i
    cdef imdir_t idx, idxi
    cdef coeff_t coeff
    cdef object res, accum
    cdef bases_t* fulldir
    
    if len(bases) != len(deltas):
    
      raise ValueError("Both bases and deltas must have the same dimension")

    # end if 

    # Get the maximum active basis in the number.
    size = soti_get_max_basis(&self.num, dhl)
    size = max(size,max(bases))
    deltas_eval = np.zeros(size,dtype=object)

    res = 0
    # Create zeros with the total number of elements in the number.
    for i in range(len(bases)):
      
      j = bases[i] - 1
      deltas_eval[ j ] = deltas[i]

      res += 0*deltas[i]

    # end for 

    # Evaluate the ROM:

    res = self.num.re

    # order 1 and up.
    for ordi in range(self.num.act_order):
      
      for idxi in range(self.num.p_nnz[ordi]):
        
        # Get index and coefficient for current im. direction.
        idx   = self.num.p_idx[ordi][idxi]
        coeff = self.num.p_im[ordi][idxi]

        # Get the imag direction full coefficient
        fulldir = dhelp_get_imdir( idx, ordi+1, dhl);

        # Multiply all deltas for this term:
        prod = 1
        for j in range(ordi+1):
          i = fulldir[j]-1
          prod = prod*deltas_eval[i]
        # end for

        res = res + prod * coeff

      # end for

    # end for 

    return res

  #---------------------------------------------------------------------------------------------------





  # #  =================================================================================================
  # #  ------------------------------------   MATH FUNCTIONS  ------------------------------------------
  # #  =================================================================================================

  # #***************************************************************************************************
  # cpdef sin(self):
  #   """
  #   PURPOSE: function.
  #   """
  #   #*************************************************************************************************
  #   global dhl

  #   cdef sotinum_t res = soti_sin( &self.num, dhl )
  #   return sotinum.create(&res)
  # #---------------------------------------------------------------------------------------------------  

  # #***************************************************************************************************
  # cpdef cos(self):
  #   """
  #   PURPOSE: function.
  #   """
  #   #*************************************************************************************************
  #   global dhl
  #   cdef sotinum_t res = soti_cos( &self.num, dhl )
  #   return sotinum.create(&res)
  # #---------------------------------------------------------------------------------------------------  

  # #***************************************************************************************************
  # cpdef tan(self):
  #   """
  #   PURPOSE: function.
  #   """
  #   #*************************************************************************************************
  #   global dhl
  #   cdef sotinum_t res = soti_tan( &self.num, dhl )
  #   return sotinum.create(&res)
  # #---------------------------------------------------------------------------------------------------  
  
  # #***************************************************************************************************
  # cpdef arctan(self):
  #   """
  #   PURPOSE: function.
  #   """
  #   #*************************************************************************************************
  #   global dhl
  #   cdef sotinum_t res = soti_atan( &self.num, dhl )
  #   return sotinum.create(&res)
  # #---------------------------------------------------------------------------------------------------  
  
  # #***************************************************************************************************
  # cpdef arccos(self):
  #   """
  #   PURPOSE: function.
  #   """
  #   #*************************************************************************************************
  #   global dhl
  #   cdef sotinum_t res = soti_acos( &self.num, dhl )
  #   return sotinum.create(&res)
  # #---------------------------------------------------------------------------------------------------  
  
  # #***************************************************************************************************
  # cpdef arcsin(self):
  #   """
  #   PURPOSE: function.
  #   """
  #   #*************************************************************************************************
  #   global dhl
  #   cdef sotinum_t res = soti_asin( &self.num, dhl )
  #   return sotinum.create(&res)
  # #---------------------------------------------------------------------------------------------------  
  
  # #***************************************************************************************************
  # cpdef sinh(self):
  #   """
  #   PURPOSE: function.
  #   """
  #   #*************************************************************************************************
  #   global dhl
  #   cdef sotinum_t res = soti_sinh( &self.num, dhl )
  #   return sotinum.create(&res)
  # #---------------------------------------------------------------------------------------------------  
  
  # #***************************************************************************************************
  # cpdef arcsinh(self):
  #   """
  #   PURPOSE: function.
  #   """
  #   #*************************************************************************************************
  #   global dhl
  #   cdef sotinum_t res = soti_asinh( &self.num, dhl )
  #   return sotinum.create(&res)
  # #---------------------------------------------------------------------------------------------------  
  
  # #***************************************************************************************************
  # cpdef cosh(self):
  #   """
  #   PURPOSE: function.
  #   """
  #   #*************************************************************************************************
  #   global dhl
  #   cdef sotinum_t res = soti_cosh( &self.num, dhl )
  #   return sotinum.create(&res)
  # #---------------------------------------------------------------------------------------------------  
  
  # #***************************************************************************************************
  # cpdef arccosh(self):
  #   """
  #   PURPOSE: function.
  #   """
  #   #*************************************************************************************************
  #   global dhl
  #   cdef sotinum_t res = soti_acosh( &self.num, dhl )
  #   return sotinum.create(&res)
  # #---------------------------------------------------------------------------------------------------  
  
  # #***************************************************************************************************
  # cpdef tanh(self):
  #   """
  #   PURPOSE: function.
  #   """
  #   #*************************************************************************************************
  #   global dhl
  #   cdef sotinum_t res = soti_tanh( &self.num, dhl )
  #   return sotinum.create(&res)
  # #---------------------------------------------------------------------------------------------------  
  
  # #***************************************************************************************************
  # cpdef arctanh(self):
  #   """
  #   PURPOSE: function.
  #   """
  #   #*************************************************************************************************
  #   global dhl
  #   cdef sotinum_t res = soti_atanh( &self.num, dhl )
  #   return sotinum.create(&res)
  # #---------------------------------------------------------------------------------------------------  
  
  # #***************************************************************************************************
  # cpdef log10(self):
  #   """
  #   PURPOSE: function.
  #   """
  #   #*************************************************************************************************
  #   global dhl
  #   cdef sotinum_t res = soti_log10( &self.num, dhl )
  #   return sotinum.create(&res)
  # #---------------------------------------------------------------------------------------------------  
  
  # #***************************************************************************************************
  # cpdef log(self):
  #   """
  #   PURPOSE: function.
  #   """
  #   #*************************************************************************************************
  #   global dhl
  #   cdef sotinum_t res = soti_log( &self.num, dhl )
  #   return sotinum.create(&res)
  # #---------------------------------------------------------------------------------------------------  
  
  # #***************************************************************************************************
  # cpdef exp(self):
  #   """
  #   PURPOSE: function.
  #   """
  #   #*************************************************************************************************
  #   global dhl
  #   cdef sotinum_t res = soti_exp( &self.num, dhl )
  #   return sotinum.create(&res)
  # #---------------------------------------------------------------------------------------------------  
  
  # #***************************************************************************************************
  # cpdef sqrt(self):
  #   """
  #   PURPOSE: function.
  #   """
  #   #*************************************************************************************************
  #   global dhl
  #   cdef sotinum_t res = soti_sqrt( &self.num, dhl )
  #   return sotinum.create(&res)
  # #---------------------------------------------------------------------------------------------------  
  
  # #***************************************************************************************************
  # cpdef cbrt(self):
  #   """
  #   PURPOSE: function.
  #   """
  #   #*************************************************************************************************
  #   global dhl
  #   cdef sotinum_t res = soti_cbrt( &self.num, dhl )
  #   return sotinum.create(&res)
  # #---------------------------------------------------------------------------------------------------  


# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# :::::::::::::::::::::::::::::::::::: End of class sotinum ::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
