# cdef uint64_t[::1] arr_nnz = np.zeros(150)


# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::     CLASS  SPR_OTINUM   :::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
cdef class sotinum:
  
  #---------------------------------------------------------------------------------------------------
  #------------------------------------   DEFINITION OF ATTRIBUTES   ---------------------------------
  #---------------------------------------------------------------------------------------------------
  #
  #                                     --< Look in "sparse.pxd" >--
  #
  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  def __init__(self, coeff_t re_coeff, ord_t order = 0, uint8_t FLAGS = 1, object nnz = None):
    """
    DESCRIPTION: Constructor of a sparse OTI number.
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
    
    else:
      
      self.num =  soti_createReal(re_coeff, order, dhl)
    
    # end if 

  #---------------------------------------------------------------------------------------------------  

  #***************************************************************************************************
  def __dealloc__(self): 
    """
    PURPOSE:      Destructor of the class. 

    DESCRIPTION:  Frees all pointers allocated in the 
                  
    """
    #*************************************************************************************************
    
    if self.FLAGS & 1: # If memory is owned by this otinum.

      soti_free(&self.num)

    #end if 
    
  #---------------------------------------------------------------------------------------------------
  

  # #***************************************************************************************************
  # @property
  # def  size(self): 
  #   """
  #   PURPOSE:      Return the number of directions in the otinum.

  #   DESCRIPTION:  Reads the component Ndir of otinum_t num.
                  
  #   """
  #   #*************************************************************************************************

  #   return self.num.size

  # #---------------------------------------------------------------------------------------------------

  # #***************************************************************************************************
  # @property
  # def  coefs(self): 
  #   """
  #   PURPOSE:      Return the coefficients in a python friendly object. 

  #   DESCRIPTION:  Creates a numpy array object using the raw p_coef pointer.
  #                 This is a view of the number's coefficients. Changing a value in the numpy array 
  #                 changes the number in the number's coefficient.
  #                 The given numpy array does not own the pointer, the object can be treated as 
  #                 volatile, which means that in can be reasigned to another memory, and it does not
  #                 be easily,
  #                 not a view of the pointer. Be careful.
                  
  #   """
  #   #*************************************************************************************************
    
  #   # print(hex(<uint64_t>self.num.p_coefs))
  #   # cdef np.ndarray[double, ndim=1]  myarray = c_ptr_to_np_1darray_double(self.num.p_coefs, self.num.Ndir)
  #   # myarray.base = <PyObject*>self
  #   # return myarray

  #   return c_ptr_to_np_1darray_double(self.num.p_coefs, self.num.size)

  # #---------------------------------------------------------------------------------------------------

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
  cdef sotinum create(sotinum_t* num, uint8_t FLAGS = 1):
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


    otin.num.re     = num[ZERO].re    
    otin.num.p_im   = num[ZERO].p_im  
    otin.num.p_idx  = num[ZERO].p_idx 
    otin.num.p_nnz  = num[ZERO].p_nnz 
    otin.num.p_size = num[ZERO].p_size
    otin.num.order  = num[ZERO].order 
    otin.num.flag   = num[ZERO].flag 

    otin.FLAGS      = FLAGS
    
    return otin

  #--------------------------------------------------------------------------------------------------- 


  #*************************************************************************************************** 
  def __repr__(self):
    """
    PURPOSE:  To print a representation of the sotinum object in a compact form.
    """
    #*************************************************************************************************
    global h
    global p_dH

    cdef ndir_t ndir_total = 1, i;

    for i in range(0, self.num.order):

      ndir_total += self.num.p_nnz[i]

    # end for

    head = 'sotinum('
    body = str(self.num.re) + ", nnz: " + str(ndir_total) + ', order: ' + str(self.num.order)
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
    
    body += '%g'%self.num.re

    for ordi in range(0,self.num.order):

      for i in range(self.num.p_nnz[ordi]):
        
        num = '%+g'%self.num.p_im[ordi][i] 
        body += ' '+num[0]+" "+num[1:]
        body += ' * e(' 
        
        body += str(h.get_compact_fulldir(self.num.p_idx[ordi][i],ordi+1)).replace(' ','')
        body += ")"
      
      # end for

    # end for 
      
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

    # else:

    #   ?return other_in - self

    #   default:


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
    cdef sotinum_t res

    type1 = type(self)     # takes 100 ns ... 
    type2 = type(other_in) # takes 100 ns ...

    if type1 == type2:  
      
      S = self
      O = other_in

      res = soti_div_oo(&S.num,&O.num,dhl)
      
    elif type2 in number_types:   # Case 1. Mult to real scalar. 
      
      S = self
      soti_div_or(&S.num,other_in,dhl)
    
    elif type1 in number_types:   # Case 1.5. Reverse Mult to real scalar.
      
      O = other_in
      res = soti_div_ro( self, &O.num, dhl)
      
    # End if. Type cases.

    return sotinum.create(&res)

  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  def __pow__(self, n,z):
    """
    PURPOSE:      To provide power function of sparse oti numbers.
    """
    #*************************************************************************************************
    
    global dhl

    cdef sotinum_t res
    cdef sotinum S = self

    res = soti_pow(&S.num, n, dhl)
    
    return sotinum.create(&res)

  #---------------------------------------------------------------------------------------------------  

  #***************************************************************************************************
  cpdef coeff_t get_deriv( self, object humdir):
    """
    PURPOSE:      to retrieve the derivative contained in the oti number.

    """
    #*************************************************************************************************
    global dhl

    cdef imdir_t indx
    cdef ord_t  order

    indx, order = imdir(humdir)
    return soti_get_deriv(indx,order, &self.num, dhl) 

  #--------------------------------------------------------------------------------------------------- 


  #***************************************************************************************************
  def copy(self):
    """
    PURPOSE:      To create a copy of the object.
    """
    #*************************************************************************************************
    global dhl
    cdef sotinum_t res = soti_copy( &self.num, dhl )
    return sotinum.create(&res)

  #--------------------------------------------------------------------------------------------------- 

  #***************************************************************************************************
  cpdef sin(self):
    """
    PURPOSE: function.
    """
    #*************************************************************************************************
    global dhl
    cdef sotinum_t res = soti_sin( &self.num, dhl )
    return sotinum.create(&res)
  #---------------------------------------------------------------------------------------------------  

  #***************************************************************************************************
  cpdef cos(self):
    """
    PURPOSE: function.
    """
    #*************************************************************************************************
    global dhl
    cdef sotinum_t res = soti_cos( &self.num, dhl )
    return sotinum.create(&res)
  #---------------------------------------------------------------------------------------------------  

  #***************************************************************************************************
  cpdef tan(self):
    """
    PURPOSE: function.
    """
    #*************************************************************************************************
    global dhl
    cdef sotinum_t res = soti_tan( &self.num, dhl )
    return sotinum.create(&res)
  #---------------------------------------------------------------------------------------------------  
  #***************************************************************************************************
  cpdef atan(self):
    """
    PURPOSE: function.
    """
    #*************************************************************************************************
    global dhl
    cdef sotinum_t res = soti_atan( &self.num, dhl )
    return sotinum.create(&res)
  #---------------------------------------------------------------------------------------------------  
  #***************************************************************************************************
  cpdef acos(self):
    """
    PURPOSE: function.
    """
    #*************************************************************************************************
    global dhl
    cdef sotinum_t res = soti_acos( &self.num, dhl )
    return sotinum.create(&res)
  #---------------------------------------------------------------------------------------------------  
  #***************************************************************************************************
  cpdef asin(self):
    """
    PURPOSE: function.
    """
    #*************************************************************************************************
    global dhl
    cdef sotinum_t res = soti_asin( &self.num, dhl )
    return sotinum.create(&res)
  #---------------------------------------------------------------------------------------------------  
  #***************************************************************************************************
  cpdef sinh(self):
    """
    PURPOSE: function.
    """
    #*************************************************************************************************
    global dhl
    cdef sotinum_t res = soti_sinh( &self.num, dhl )
    return sotinum.create(&res)
  #---------------------------------------------------------------------------------------------------  
  #***************************************************************************************************
  cpdef asinh(self):
    """
    PURPOSE: function.
    """
    #*************************************************************************************************
    global dhl
    cdef sotinum_t res = soti_asinh( &self.num, dhl )
    return sotinum.create(&res)
  #---------------------------------------------------------------------------------------------------  
  #***************************************************************************************************
  cpdef cosh(self):
    """
    PURPOSE: function.
    """
    #*************************************************************************************************
    global dhl
    cdef sotinum_t res = soti_cosh( &self.num, dhl )
    return sotinum.create(&res)
  #---------------------------------------------------------------------------------------------------  
  #***************************************************************************************************
  cpdef acosh(self):
    """
    PURPOSE: function.
    """
    #*************************************************************************************************
    global dhl
    cdef sotinum_t res = soti_acosh( &self.num, dhl )
    return sotinum.create(&res)
  #---------------------------------------------------------------------------------------------------  
  #***************************************************************************************************
  cpdef tanh(self):
    """
    PURPOSE: function.
    """
    #*************************************************************************************************
    global dhl
    cdef sotinum_t res = soti_tanh( &self.num, dhl )
    return sotinum.create(&res)
  #---------------------------------------------------------------------------------------------------  
  #***************************************************************************************************
  cpdef atanh(self):
    """
    PURPOSE: function.
    """
    #*************************************************************************************************
    global dhl
    cdef sotinum_t res = soti_atanh( &self.num, dhl )
    return sotinum.create(&res)
  #---------------------------------------------------------------------------------------------------  
  #***************************************************************************************************
  cpdef log10(self):
    """
    PURPOSE: function.
    """
    #*************************************************************************************************
    global dhl
    cdef sotinum_t res = soti_log10( &self.num, dhl )
    return sotinum.create(&res)
  #---------------------------------------------------------------------------------------------------  
  #***************************************************************************************************
  cpdef log(self):
    """
    PURPOSE: function.
    """
    #*************************************************************************************************
    global dhl
    cdef sotinum_t res = soti_log( &self.num, dhl )
    return sotinum.create(&res)
  #---------------------------------------------------------------------------------------------------  
  #***************************************************************************************************
  cpdef exp(self):
    """
    PURPOSE: function.
    """
    #*************************************************************************************************
    global dhl
    cdef sotinum_t res = soti_exp( &self.num, dhl )
    return sotinum.create(&res)
  #---------------------------------------------------------------------------------------------------  
  #***************************************************************************************************
  cpdef sqrt(self):
    """
    PURPOSE: function.
    """
    #*************************************************************************************************
    global dhl
    cdef sotinum_t res = soti_sqrt( &self.num, dhl )
    return sotinum.create(&res)
  #---------------------------------------------------------------------------------------------------  
# #***************************************************************************************************
#   cpdef cbrt(self):
#     """
#     PURPOSE: function.
#     """
#     #*************************************************************************************************
#     global dhl
#     cdef sotinum_t res = soti_cbrt( &self.num, dhl )
#     return sotinum.create(&res)
#   #---------------------------------------------------------------------------------------------------  


# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# :::::::::::::::::::::::::::::::::::: End of class sotinum ::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::



