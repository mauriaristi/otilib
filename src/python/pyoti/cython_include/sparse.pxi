# cython: boundscheck=False 
# cython: wraparound=False 
# cython: nonecheck=False 
# cython: language_level=3
# cython: profile=False
# cython: linetrace=True
# cython: binding=True
# cython: embedsignature=False
## distutils: define_macros=CYTHON_TRACE_NOGIL=1
## distutils: libraries = oti 
## distutils: extra_compile_args = -arch i386 -arch x86_64
# filename: sparse.pyx  


import numpy as np                  # General numerical library
cimport numpy as np                 # C-level functions of numpy
from c_otilib cimport *             # OTI lib in C.
cimport cython                      #

# from pyoti.core import   number_types, dHelp, imdir
# from pyoti.core cimport  ZERO, ONE, get_cython_dHelp, dHelp, imdir
# from pyoti.core cimport  c_ptr_to_np_1darray_double 

# cdef dHelp h = get_cython_dHelp()
# cdef dhelpl_t dhl = h.dhl


# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::     CLASS  SPR_OTINUM   :::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
cdef class sotinum:
  
  #---------------------------------------------------------------------------------------------------
  #------------------------------------   DEFINITION OF ATTRIBUTES   ---------------------------------
  #---------------------------------------------------------------------------------------------------
  
  cdef sotinum_t num
  cdef uint8_t FLAGS
  #--------------------------------------------------------------------------------------------------- 


  #***************************************************************************************************
  def __init__(self, coeff_t re_coeff, ord_t order, uint8_t FLAGS = 1):
    """
    DESCRIPTION: Constructor of a sparse OTI number.
    """
    #*************************************************************************************************
    global dhl

    # Add warning for higher orders and orders that are not required
    self.FLAGS = FLAGS

    num1 = soti_createReal(re_coeff, order, dhl);
    

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

    otin.FLAGS = FLAGS
    
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
      res =  soti_sum(&tmp1.num, &tmp2.num, dhl);
    
    elif (type2 in number_types): # Case Sum to real number. Very slow, consider changing this...
      
      tmp1 = self
      res = soti_sum_real( other_in, &tmp1.num, dhl);

    elif (type1 in number_types): # Case 1.5. reverse Sum to real number.
      
      tmp1 = other_in
      res = soti_sum_real( self, &tmp1.num, dhl);      

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
      res =  soti_sub(&tmp1.num, &tmp2.num, dhl);
    
    elif (type2 in number_types): # Case Sum to real number. Very slow, consider changing this...
      
      tmp1 = self
      res = soti_sub_otireal(&tmp1.num, other_in, dhl);

    elif (type1 in number_types): # Case 1.5. reverse Sum to real number.
      
      tmp1 = other_in
      res = soti_sub_realoti(self, &tmp1.num, dhl);   

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
      res = soti_mul( &tmp1.num, &tmp2.num, dhl)
    
    elif (type2 in number_types): # Case Sum to real number. Very slow, consider changing this...
      
      tmp1 = self
      res = soti_mul_real( other_in, &tmp1.num, dhl);

    elif (type1 in number_types): # Case 1.5. reverse Sum to real number.
      
      tmp1 = other_in
      res = soti_mul_real( self, &tmp1.num, dhl);       

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

      res = soti_div(&S.num,&O.num,dhl)
      
    elif type2 in number_types:   # Case 1. Mult to real scalar. 
      
      S = self
      soti_div_otireal(&S.num,other_in,dhl)
    
    elif type1 in number_types:   # Case 1.5. Reverse Mult to real scalar.
      
      O = other_in
      res = soti_div_realoti( self, &O.num, dhl)
      
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
    global p_dH

    cdef sotinum_t res
    cdef sotinum S = self

    res = soti_pow(&S.num, n, dhl)
    
    return sotinum.create(&res)

  #---------------------------------------------------------------------------------------------------  

  #***************************************************************************************************
  cpdef coeff_t get_deriv( self, list item):
    """
    PURPOSE:      to retrieve the derivative contained in the oti number.

    """
    #*************************************************************************************************
    global dhl

    cdef imdir_t indx = item[ZERO]
    cdef ord_t  order = item[ONE]
    
    return soti_get_deriv(indx,order, &self.num, dhl) 

  #--------------------------------------------------------------------------------------------------- 

  # #***************************************************************************************************
  # def power(self, n):
  #   """
  #   PURPOSE:      To provide power function.
  
  #   DESCRIPTION:  It defines how to make a soti number to the power of n.
  
  #   EXAMPLE:      >>> a = spr_otinum([0,4,17], [1.,3.,5.], 2)
  #                 >>> a**3
  #                 spr_otinum([0,4,8,17], [1.,9.,27.,15.], 2)
  #   """
  #   #*************************************************************************************************
    
  #   global h
  #   global p_dH
  #   cdef sotinum_t res
  #   cdef sotinum S = self
    
  #   c_soti_ipow(&S.num, n, &res, p_dH)
    
  #   return sotinum.create(&res)

  # #--------------------------------------------------------------------------------------------------- 

#   #***************************************************************************************************
#   def copy(self):
#     """
#     PURPOSE:      To create a copy of a spr_otinum object, totally 
#                   independent of the original.

#     DESCRIPTION:  The equality operator "=" is intended to create aliases
#                   of multicomplex numbers. You should use copy() when you
#                   need a copy instead of an alias.
    
#     EXAMPLE:      >>> a = spr_otinum([0,4,17], [1.,7.,3.], 2)
#                   >>> b = a.copy()
#                   >>> b[1] = 10
#                   >>> a
#                   spr_otinum([0,4,17], [1.,7.,3.], 2)
#                   >>> b
#                   spr_otinum([0,1,4,17], [1.,10.,7.,3.], 2)
#     """
#     #*************************************************************************************************

#     if self.indx.size != 0:
      
#       return spr_otinum(self.indx.copy(),self.coefs.copy(),self.maxorder)

#     else:

#       #empty number, MemoryView does not know how to handle them, therefore...
#       return spr_otinum(np.array(self.indx),np.array(self.coefs),self.maxorder)

#   #---------------------------------------------------------------------------------------------------  


#   #***************************************************************************************************
#   cpdef void checkZeros(self):
#     """
#     PURPOSE:      check and eliminate the zeros of a spr_otinum.
    
#     DESCRIPTION:  it simply search for elements less than a tolerance value
#                   and erases them from the index and coefs array. 
#     """
#     #*************************************************************************************************
    
#     # Initialize a counter for the number of deleted items
#     cdef uint64_t j=0
#     cdef uint64_t k=0
    
#     cdef np.ndarray[uint64_t,ndim = 1] posToPreserve=np.empty(0,dtype=np.uint64)

#     cdef np.ndarray[float64_t,ndim = 1,mode = 'c'] tmp_coefs 
#     cdef np.ndarray[uint64_t,ndim = 1,mode = 'c']  tmp_indx

#     # Search all items and select the positions that are outside the 
#     # tolerance

#     for j in range(self.indx.size):

#       # If item is near zero, delete it.
#       if abs(self.coefs[j]) > self.tol:
        
#         posToPreserve = np.insert(posToPreserve,k,j)
#         k+=1
      
#       # end if
      
#     # end for

#     # remove the positions
#     tmp_coefs = np.empty(posToPreserve.size,dtype = np.float64)
#     tmp_indx = np.empty(posToPreserve.size,dtype = np.uint64)


#     # Fill in the data to be preserved:

#     for j in range(posToPreserve.size):
      
#       tmp_coefs[j]=self.coefs[posToPreserve[j]]
#       tmp_indx[j]=self.indx[posToPreserve[j]]

#     # end for

#     self.coefs = tmp_coefs
#     self.indx  = tmp_indx 

#   #---------------------------------------------------------------------------------------------------  


#   #***************************************************************************************************
#   cpdef void changeOrder(self,uint8_t neworder):
#     """
#     PURPOSE:      To change the order of a spr_otinum.
  
#     DESCRIPTION:  According to the new order, the index values are changed. 

#     """
#     #*************************************************************************************************
    
#     # Initialize a counter for the number of deleted items
#     cdef uint64_t count = 0
#     cdef uint64_t elimin = 0

#     cdef uint16_t[::1] oldDirA  
#     cdef uint16_t[::1] newDirA 
#     cdef uint8_t[::1]  oldExpA 
#     cdef uint8_t[::1]  newExpA 
#     cdef uint64_t starti
#     cdef uint64_t j
#     cdef uint8_t i

#     cdef object new_h = H[neworder-1]
    
#     # Case for a new order greater than previous order.
#     if neworder>self.maxorder:
      

#       newDirA = np.zeros(neworder,      dtype=np.uint16)
#       newExpA = np.zeros(neworder,      dtype=np.uint8)
      
#       if self.maxorder == 1:

#         # check if the real coefficient exist.
#         if self.indx[0] != 0:

#           starti = 0

#         else:

#           starti = 1

#         # end if
        
#         newExpA[0] = 1

#         # Search all index terms.
#         for j in range(starti,self.indx.size):
          

#           # Calculate the indx in base representation for the new order.
#           newDirA[0] = self.indx[j]

#           # find the new spr_otinum index for the new Order.
#           self.indx[j] = new_h.findIndx(newDirA, newExpA)

#         # end for

#       else:
        

#         # check if the real coefficient exist.
#         if self.indx[0] != 0:

#           starti = 0

#         else:

#           starti = 1

#         # end if

#         # Search all index terms.
#         for j in range(starti,self.indx.size):
          
#           # find old Exp and Dir arrays
          
#           oldDirA = self.h.getDirA(self.indx[j])
#           oldExpA = self.h.getExpA(self.indx[j])

          
#           for i in range(self.maxorder):

#             newDirA[i] = oldDirA[i]
#             newExpA[i] = oldExpA[i]

#           # end for
          
#           # find the new spr_otinum index for the new Order.
#           self.indx[j] = new_h.findIndx(newDirA, newExpA)

#         # end for

#       # end if

#     elif neworder<self.maxorder:
      
      
#       newDirA = np.zeros(neworder,      dtype=np.uint16)
#       newExpA = np.zeros(neworder,      dtype=np.uint8)
      
#       # check if the real coefficient exist.
#       if self.indx[0] != 0:

#         starti = 0

#       else:

#         starti = 1

#       # end if

#       for j in range(starti,self.indx.size):

#         oldExpA = self.h.getExpA(self.indx[j])

#         # calculate the order of the term:
#         termOrder =  c_sumUI8(&oldExpA[0],self.maxorder)

#         if termOrder<= neworder:

#           oldDirA = self.h.getDirA(self.indx[j])
          
#           # determine actions for order = 1.
#           if neworder == 1:

#             self.indx[count] = oldDirA[0]
#             count+=1
          
#           else:

#             newDirA = oldDirA[:neworder]
#             newExpA = oldExpA[:neworder]

#             # find the new spr_otinum index for the new Order.
#             self.indx[count] = new_h.findIndx(newDirA, newExpA)
#             count+=1

#         # end if
        
#       # end for
      
#       # eliminate the other elements that were not counted in:
#       # look for a more efficient way...
      
#       self.indx = self.indx[:count]
#       self.coefs = self.coefs[:count]

#     # end if

#     #add check for other implementation

#     self.h = H[neworder-1]
#     self.maxorder = neworder

#   #---------------------------------------------------------------------------------------------------  


#   #***************************************************************************************************
#   def getDual(self, dirArray):
#     """
#     PURPOSE:      To add a human friendly form to get elements from a 
#                   spr_otinum.
    
#     EXAMPLE:      >>> a = spr_otinum([0,4,17], [1.,3.,5.], 2)
#                   >>> print(a)
#                   1.0 + 3.0 * e([2]) + 5.0 * e([1,3])
#                   >>> a.getDual([1,3])
#                   5.0
#                   >>> a.getDual([1])
#                   0.0
#     """
#     #*************************************************************************************************

#     if type(dirArray)==int:
    
#       indxArray = [dirArray]

#     else:

#       indxArray = dirArray
      
#     # end if
      
#     tmp_dirA,tmp_expA = getDirExpA(indxArray)

#     cdef uint8_t maxorder = np.sum(tmp_expA)
#     cdef uint8_t i
#     cdef uint64_t indx

#     if maxorder > self.maxorder:
#       return 0.
    
#     # create the real direction arrays:
#     dirA = np.zeros(self.maxorder,dtype = np.uint16)
#     expA = np.zeros(self.maxorder,dtype = np.uint8)
    
#     for i in range(len(tmp_expA)):
      
#       dirA[i] = tmp_dirA[i]
#       expA[i] = tmp_expA[i]

#     # end for 

#     if indxArray[0] == 0:
        
#       indx = 0

#     elif self.maxorder == 1:

#       indx = indxArray[0]

#     else:

#       indx = self.h.findIndx(dirA,expA)

#     # end if
    
#     return self[indx]

#   #---------------------------------------------------------------------------------------------------  


#   #***************************************************************************************************
#   def setDual(self, dirArray, value):
#     """
#     PURPOSE:      To add a human friendly form to set elements of a 
#                   spr_otinum.
    
#     EXAMPLE:      >>> a = spr_otinum([0,4,17], [1.,3.,5.], 2)
#                   >>> print(a)
#                   1.0 + 3.0 * e([2]) + 5.0 * e([1,3])
#                   >>> a.setDual([1,3],10)
#                   >>> print(a)
#                   1.0 + 3.0 * e([2]) + 10.0 * e([1,3])
#                   >>> a.setDual([1],2.5)
#                   >>> print(a)
#                   1.0 + 2.5 * e([1]) + 3.0 * e([2]) + 5.0 * e([1,3])
#     """
#     #*************************************************************************************************
  
#     if type(dirArray)==int:
    
#       indxArray = [dirArray]

#     else:

#       indxArray = dirArray
      
#     # end if
      
#     tmp_dirA,tmp_expA = getDirExpA(indxArray)

#     cdef uint8_t maxorder = np.sum(tmp_expA)
#     cdef uint8_t i
#     cdef uint64_t indx

#     if maxorder > self.maxorder:
#       return 0.
    
#     # create the real direction arrays:
#     dirA = np.zeros(self.maxorder,dtype = np.uint16)
#     expA = np.zeros(self.maxorder,dtype = np.uint8)
    
#     for i in range(len(tmp_expA)):
      
#       dirA[i] = tmp_dirA[i]
#       expA[i] = tmp_expA[i]

#     # end for 

#     if indxArray[0] == 0:
        
#       indx = 0

#     elif self.maxorder == 1:

#       indx = indxArray[0]

#     else:

#       indx = self.h.findIndx(dirA,expA)

#     # end if

#     self[indx] = value

#   #---------------------------------------------------------------------------------------------------  


#   #***************************************************************************************************
#   def getDerivByDirExp( self,uint16_t[::1] dirA, uint8_t[::1] expA):
#     """
#     PURPOSE:      to retrieve the n'th derivative according to the taylor 
#                   series expansion with dual numbers.
                
#     DESCRIPTION:  Simply given the combinations of derivatives with the 
#                   dirArray, the function multiplys the terms that require
#                   extra factors to get the desired derivatives.
    
#     EXAMPLE:      >>> a = spr_otinum([0,1,2,4,5,8],[1,2,3,4,5,6],2)
#                   >>>
#                   >>> getDerivative(a,[0])
#                   1.
#                   >>> getDerivative(a,[1])
#                   2.
#                   >>> getDerivative(a,[[1,2]])
#                   6.
#                   >>> getDerivative(a,[2])
#                   4.
#                   >>> getDerivative(a,[1,2])
#                   5.
#                   >>> getDerivative(a,[[2,2]])
#                   12.

#     """
#     #*************************************************************************************************
    
    
#     cdef uint8_t   order  = np.sum(expA)
    
#     # If asking for a coefficient of higher order, return 0.0
#     if order > self.maxorder:
    
#       return np.float64(0.0)  

#     # end if 
    
#     cdef float64_t factor = 1.0
#     cdef uint16_t[::1] tmp_dirA = np.zeros(self.maxorder,dtype = np.uint16)
#     cdef uint8_t[::1]  tmp_expA = np.zeros(self.maxorder,dtype = np.uint8)
#     cdef uint8_t i

    
#     # Compute the multiplication factor and fill in the temporary arrays.

#     for i in range(dirA.size):
      
#       factor *= factorial(expA[i])
#       tmp_dirA[i] = dirA[i]
#       tmp_expA[i] = expA[i]
    
#     # end for
    
#     value = np.float64(0.0)
#     indx  = self.h.findIndx(tmp_dirA,tmp_expA)
#     value = self[indx]*factor
    
#     return value

#   #---------------------------------------------------------------------------------------------------  


  # #***************************************************************************************************
  # def getDeriv(self, dirArray):
  #   """
  #   PURPOSE:      to retrieve the n'th derivative according to the taylor 
  #                 series expansion with dual numbers.
                
  #   DESCRIPTION:  Simply given the combinations of derivatives with the 
  #                 dirArray, the function multiplys the terms that require
  #                 extra factors to get the desired derivatives.
    
  #   EXAMPLE:      >>> a = spr_otinum([0,1,2,4,5,8],[1,2,3,4,5,6],2)
  #                 >>>
  #                 >>> getDerivative(a,[0])
  #                 1.
  #                 >>> getDerivative(a,[1])
  #                 2.
  #                 >>> getDerivative(a,[[1,2]])
  #                 6.
  #                 >>> getDerivative(a,[2])
  #                 4.
  #                 >>> getDerivative(a,[1,2])
  #                 5.
  #                 >>> getDerivative(a,[[2,2]])
  #                 12.

  #   """
  #   #*************************************************************************************************

  #   if type(dirArray)==int:
      
  #     indxArray = [dirArray]
      
  #   else:
      
  #     indxArray = dirArray
      
  #   # end if

    
  #   tmp_dirA,tmp_expA = getDirExpA(dirArray)
  #   cdef uint8_t maxorder = np.sum(tmp_expA)
  #   cdef uint8_t i
  #   cdef uint64_t indx

  #   # create the real direction arrays:
  #   cdef np.ndarray[uint16_t,ndim=1] dirA = np.zeros(maxorder,dtype = np.uint16)
  #   cdef np.ndarray[uint8_t ,ndim=1] expA = np.zeros(maxorder,dtype = np.uint8)
    
  #   for i in range(len(tmp_expA)):
      
  #     dirA[i] = tmp_dirA[i]
  #     expA[i] = tmp_expA[i]

  #   # end for 

  #   return self.getDerivByDirExp(dirA,expA)

  # #---------------------------------------------------------------------------------------------------  


#   #***************************************************************************************************
#   def toVector(self):
#     """
#     PURPOSE:      To convert a spr_otinum into its vector form.
                  
#     DESCRIPTION:  Convert to its own Cauchy-Riemann representation vector.

                    
#     """
#     #*************************************************************************************************

#     return self.expand(ismat =0)

#   #---------------------------------------------------------------------------------------------------  


#   #***************************************************************************************************
#   def toMatrix(self,ismat = 1,m = -1,isspr = 0):
#     """
#     PURPOSE:      To convert a spr_otinum into its matrix form.
                  
#     DESCRIPTION:  Convert to its own Cauchy-Riemann representation vector.
    
#     INPUTS:
#                   ismat: To define a matrix (1) or a vector (0)
#                   isshape: To use the shape that will result of the number 
#                     (-1) or an specific shape (given value).
#                   isspr: To result in a sparse matrix (1) or not (0).
#     """
#     #*************************************************************************************************

#     return self.expand(ismat = ismat, m = m, isspr = isspr)

#   #---------------------------------------------------------------------------------------------------  


#   #***************************************************************************************************
#   def expand(self,ismat = 1,m = -1 , isspr = 0):
#     """
#     PURPOSE:      To convert a spr_otinum into its matrix form.
                  
#     DESCRIPTION:  Convert to its own Cauchy-Riemann representation form.
                   
#     INPUTS:
#                   ismat: To define a matrix (1) or a vector (0)
#                   m: To use the shape that will result of the number 
#                     (-1) or an specific shape (given value).
#                   isspr: To result in a sparse matrix (1) or not (0).
                    
#     """
#     #*************************************************************************************************
    
#     cdef uint8_t[:] error = np.zeros([0],dtype = np.uint8)
#     cdef uint64_t i
#     cdef uint64_t k
#     cdef uint64_t j
#     cdef uint64_t finalshape

#     if m == -1:
#       # Deduce the matrix dimension by looking at the last indx and 
#       # looking for the maximum base direction
#       i = self.indx.size-1
#       # Separate cases for order 1 and others.
#       if self.maxorder == 1:

#         m_max =  self.indx[i]
      
#       else: 
        
#         dirA = self.h.getDirA(self.indx[i])
#         m_max = np.max(dirA)

#       # end if 

#     else:
      
#       m_max = m
      
#     # end if

#     finalshape = findComb(m_max+1,self.maxorder)

    
#     if ismat ==0:
#       # vector type
      
#       mat = np.zeros(finalshape)
      
#       # Do only a certain amount of iterations:
#       i = self.indx.size-1
#       nIterMin = np.min([self.indx[i]+1,finalshape])
#       k = 0

#       for i in range(nIterMin):
        
#         if i == self.indx[k]:

#           mat[i] = self.coefs[k] 
#           k+=1
        
#         #end if

#       # end for
      
#     else:

#       # matrix type
      
#       if isspr == 0:
#         #return the np.array?
#         mat = np.array(__sprotinum2Mat_dense(self, finalshape))#np.zeros([finalshape,finalshape],dtype = np.float64)
        
#       else:
        
#         mat = __sprotinum2Mat_spr(self, finalshape)#spr.lil_matrix((finalshape,finalshape))
        
        
#       # end if
      

#     # end if 
    
    
#     return mat

#   #---------------------------------------------------------------------------------------------------

# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# :::::::::::::::::::::::::::::::::::: End of class sotinum ::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::



























#*****************************************************************************************************
cpdef  sotinum cos(sotinum val):
  """
  PURPOSE:  Mathematical function of cosine for OTI numbers
  """
  #***************************************************************************************************

  global dhl
  
  cdef sotinum_t res = soti_cos(&val.num, dhl)

  return sotinum.create(&res)
#-----------------------------------------------------------------------------------------------------


#*****************************************************************************************************
cpdef  sotinum sin(sotinum val):
  """
  PURPOSE:  Mathematical function of sine for OTI numbers.
  """
  #***************************************************************************************************
  global dhl
  
  cdef sotinum_t res = soti_sin(&val.num, dhl)

  return sotinum.create(&res)
#-----------------------------------------------------------------------------------------------------


#*****************************************************************************************************
cpdef  sotinum tan(sotinum val):
  """
  PURPOSE:  Mathematical function of tangent for OTI numbers 
  """
  #***************************************************************************************************
  global dhl
  
  cdef sotinum_t res = soti_tan(&val.num, dhl)

  return sotinum.create(&res)
#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cpdef  sotinum atan(sotinum val):
  """
  PURPOSE:  Mathematical function of arctangent for OTI numbers
  """
  #***************************************************************************************************
  global dhl
  
  cdef sotinum_t res = soti_atan(&val.num, dhl)

  return sotinum.create(&res)
#-----------------------------------------------------------------------------------------------------

# #*****************************************************************************************************
# cpdef  sotinum atan2(sotinum valx, sotinum valy):
#   """
#   PURPOSE:  Mathematical function of arctangent for OTI numbers
   
#   EXAMPLE:   
#   """
#   #***************************************************************************************************
#   global dhl
  
#   cdef sotinum_t res = soti_atan2(&valx.num, &valy.num, dhl)

#   return sotinum.create(&res)
# #-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cpdef  sotinum acos(sotinum val):
  """
  PURPOSE:  Mathematical function of inverse cosine for OTI numbers
  """
  #***************************************************************************************************
  global dhl
  
  cdef sotinum_t res = soti_acos(&val.num, dhl)

  return sotinum.create(&res)
#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cpdef  sotinum asin(sotinum val):
  """
  PURPOSE:  Mathematical function of inverse sine for OTI numbers
  """
  #***************************************************************************************************
  global dhl
  
  cdef sotinum_t res = soti_asin(&val.num, dhl)

  return sotinum.create(&res)
#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cpdef  sotinum sinh(sotinum val):
  """
  PURPOSE:  Mathematical function of hyperbolic sine for OTI numbers
  """
  #***************************************************************************************************
  global dhl
  
  cdef sotinum_t res = soti_sinh(&val.num, dhl)

  return sotinum.create(&res)
#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cpdef  sotinum asinh(sotinum val):
  """
  PURPOSE:  Mathematical function of inverse hyperbolic sine for OTI numbers  
  """
  #***************************************************************************************************
  global dhl
  
  cdef sotinum_t res = soti_asinh(&val.num, dhl)

  return sotinum.create(&res)
#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cpdef  sotinum cosh(sotinum val):
  """
  PURPOSE:  Mathematical function of hyperbolic cosine for OTI numbers 
  """
  #***************************************************************************************************
  global dhl
  
  cdef sotinum_t res = soti_cosh(&val.num, dhl)

  return sotinum.create(&res)
#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cpdef  sotinum acosh(sotinum val):
  """
  PURPOSE:  Mathematical function of inverse hyperbolic cosine for OTI numbers

  """
  #***************************************************************************************************
  global dhl
  
  cdef sotinum_t res = soti_acosh(&val.num, dhl)

  return sotinum.create(&res)
#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cpdef  sotinum tanh(sotinum val):
  """
  PURPOSE:  Mathematical function of hyperbolic tangent for OTI numbers  
  """
  #***************************************************************************************************
  global dhl
  
  cdef sotinum_t res = soti_tanh(&val.num, dhl)

  return sotinum.create(&res)
#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cpdef  sotinum atanh(sotinum val):
  """
  PURPOSE:  Mathematical function of Inverse hyperbolic tangent for OTI numbers

  """
  #***************************************************************************************************
  global dhl
  
  cdef sotinum_t res = soti_atanh(&val.num, dhl)

  return sotinum.create(&res)
#-----------------------------------------------------------------------------------------------------


#*****************************************************************************************************
cpdef  sotinum logb(sotinum val, double base):
  """
  PURPOSE:  Logarithm base b for OTI numbers.
  """
  #***************************************************************************************************  

  
  global dhl
  
  cdef sotinum_t res = soti_logb(&val.num, base, dhl)

  return sotinum.create(&res)
#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cpdef  sotinum log10(sotinum val):
  """
  PURPOSE:  Natural logarithm base 10 for OTI numbers.
  """
  #***************************************************************************************************  

  global dhl
  
  cdef sotinum_t res = soti_log10(&val.num, dhl)

  return sotinum.create(&res)
#-----------------------------------------------------------------------------------------------------


#*****************************************************************************************************
cpdef  sotinum log(sotinum val):
  """
  PURPOSE:  Natural logarithm for OTI numbers. 
  """
  #***************************************************************************************************  
  global dhl
  
  cdef sotinum_t res = soti_log(&val.num, dhl)

  return sotinum.create(&res)
#-----------------------------------------------------------------------------------------------------


#*****************************************************************************************************
cpdef  sotinum exp(sotinum val):
  """
  PURPOSE:  Exponential function for OTI numbers.
  """
  #*************************************************************************************************** 
  global dhl
  
  cdef sotinum_t res = soti_exp(&val.num, dhl)

  return sotinum.create(&res)
#-----------------------------------------------------------------------------------------------------


#*****************************************************************************************************
cpdef  sotinum power(sotinum val, double exponent):
  """
  PURPOSE:  Power function for OTI numbers, for non integer exponents.
  """
  #*************************************************************************************************** 
  global dhl

  cdef sotinum_t res = soti_pow(&val.num, exponent, dhl)

  return sotinum.create(&res) 
#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cpdef  sotinum sqrt(sotinum val):
  """
  PURPOSE:  Square root function for OTI numbers, for non integer exponents. 
  """
  #*************************************************************************************************** 
  global dhl
  
  cdef sotinum_t res = soti_sqrt(&val.num, dhl)

  return sotinum.create(&res)
#-----------------------------------------------------------------------------------------------------







#*****************************************************************************************************
def e( hum_dir ,ord_t order = 0,bases_t nbases = 0):
  """
  PURPOSE:  To create a sotinum with value 1 at the specified imaginary direction
            in a human friendly manner

  """
  #***************************************************************************************************
  

  global dhl

  cdef imdir_t indx_hd
  cdef ord_t order_hd
  cdef bases_t bases_hd
  cdef sotinum_t res
  
  # print("In e function.")
  [indx_hd, order_hd] = imdir(hum_dir)

  # print(indx_hd,order_hd)

  if order_hd <= order:

    res = soti_createReal(0.0, order, dhl)

    # Set the coefficient to 1.
    soti_set_item(1.0, indx_hd, order_hd, &res, dhl)

  else:

    # print("Before createReal.")
    # print("dhl.")
    res = soti_createReal(0.0, order_hd, dhl)
    # print("After createReal.")
    # Set the coefficient to 1.
    soti_set_item(1.0, indx_hd, order_hd, &res, dhl) 
    # print("After set_tem.")

  return sotinum.create(&res)

#-----------------------------------------------------------------------------------------------------







































# #*****************************************************************************************************
# cpdef  sotinum scos(sotinum val):
#   """
#   PURPOSE:  Mathematical function of cosine for OTI numbers
   
#   EXAMPLE:   
#   """
#   #***************************************************************************************************

#   global p_dH
#   cdef sotinum_t res
  
#   c_soti_cos(&val.num, p_dH, &res)

#   return sotinum.create(&res)
# #-----------------------------------------------------------------------------------------------------


# #*****************************************************************************************************
# cpdef  sotinum ssin(sotinum val):
#   """
#   PURPOSE:  Mathematical function of sine for OTI numbers.
   
#   EXAMPLE:   
#   """
#   #***************************************************************************************************
#   global p_dH
#   cdef sotinum_t res
  
#   c_soti_sin(&val.num, p_dH, &res)

#   return sotinum.create(&res)
# #-----------------------------------------------------------------------------------------------------


# #*****************************************************************************************************
# cpdef  sotinum stan(sotinum val):
#   """
#   PURPOSE:  Mathematical function of tangent for OTI numbers
   
#   EXAMPLE:   
#   """
#   #***************************************************************************************************
#   global p_dH
#   cdef sotinum_t res
  
#   c_soti_tan(&val.num, p_dH, &res)

#   return sotinum.create(&res)
# #-----------------------------------------------------------------------------------------------------

# #*****************************************************************************************************
# cpdef  sotinum satan(sotinum val):
#   """
#   PURPOSE:  Mathematical function of arctangent for OTI numbers
   
#   EXAMPLE:   
#   """
#   #***************************************************************************************************
#   global p_dH
#   cdef sotinum_t res
  
#   c_soti_atan(&val.num, p_dH, &res)

#   return sotinum.create(&res)
# #-----------------------------------------------------------------------------------------------------

# #*****************************************************************************************************
# cpdef  sotinum satan2(sotinum valx, sotinum valy):
#   """
#   PURPOSE:  Mathematical function of arctangent for OTI numbers
   
#   EXAMPLE:   
#   """
#   #***************************************************************************************************
#   global p_dH
#   cdef sotinum_t res
  
#   c_soti_atan2(&valx.num, &valy.num, p_dH, &res)

#   return sotinum.create(&res)
# #-----------------------------------------------------------------------------------------------------

# #*****************************************************************************************************
# cpdef  sotinum sacos(sotinum val):
#   """
#   PURPOSE:  Mathematical function of inverse cosine for OTI numbers
   
#   EXAMPLE:   
#   """
#   #***************************************************************************************************
#   global p_dH
#   cdef sotinum_t res
  
#   c_soti_acos(&val.num, p_dH, &res)

#   return sotinum.create(&res)
# #-----------------------------------------------------------------------------------------------------

# #*****************************************************************************************************
# cpdef  sotinum sasin(sotinum val):
#   """
#   PURPOSE:  Mathematical function of inverse sine for OTI numbers
   
#   EXAMPLE:   
#   """
#   #***************************************************************************************************
#   global p_dH
#   cdef sotinum_t res
  
#   c_soti_asin(&val.num, p_dH, &res)

#   return sotinum.create(&res)
# #-----------------------------------------------------------------------------------------------------

# #*****************************************************************************************************
# cpdef  sotinum ssinh(sotinum val):
#   """
#   PURPOSE:  Mathematical function of hyperbolic sine for OTI numbers
   
#   EXAMPLE:   
#   """
#   #***************************************************************************************************
#   global p_dH
#   cdef sotinum_t res
  
#   c_soti_sinh(&val.num, p_dH, &res)

#   return sotinum.create(&res)
# #-----------------------------------------------------------------------------------------------------

# #*****************************************************************************************************
# cpdef  sotinum sasinh(sotinum val):
#   """
#   PURPOSE:  Mathematical function of inverse hyperbolic sine for OTI numbers
   
#   EXAMPLE:   
#   """
#   #***************************************************************************************************
#   global p_dH
#   cdef sotinum_t res
  
#   c_soti_asinh(&val.num, p_dH, &res)

#   return sotinum.create(&res)
# #-----------------------------------------------------------------------------------------------------

# #*****************************************************************************************************
# cpdef  sotinum scosh(sotinum val):
#   """
#   PURPOSE:  Mathematical function of hyperbolic cosine for OTI numbers
   
#   EXAMPLE:   
#   """
#   #***************************************************************************************************
#   global p_dH
#   cdef sotinum_t res
  
#   c_soti_cosh(&val.num, p_dH, &res)

#   return sotinum.create(&res)
# #-----------------------------------------------------------------------------------------------------

# #*****************************************************************************************************
# cpdef  sotinum sacosh(sotinum val):
#   """
#   PURPOSE:  Mathematical function of inverse hyperbolic cosine for OTI numbers
   
#   EXAMPLE:   
#   """
#   #***************************************************************************************************
#   global p_dH
#   cdef sotinum_t res
  
#   c_soti_acosh(&val.num, p_dH, &res)

#   return sotinum.create(&res)
# #-----------------------------------------------------------------------------------------------------

# #*****************************************************************************************************
# cpdef  sotinum stanh(sotinum val):
#   """
#   PURPOSE:  Mathematical function of hyperbolic tangent for OTI numbers
   
#   EXAMPLE:   
#   """
#   #***************************************************************************************************
#   global p_dH
#   cdef sotinum_t res
  
#   c_soti_tanh(&val.num, p_dH, &res)

#   return sotinum.create(&res)
# #-----------------------------------------------------------------------------------------------------

# #*****************************************************************************************************
# cpdef  sotinum satanh(sotinum val):
#   """
#   PURPOSE:  Mathematical function of Inverse hyperbolic tangent for OTI numbers
   
#   EXAMPLE:   
#   """
#   #***************************************************************************************************
#   global p_dH
#   cdef sotinum_t res
  
#   c_soti_atanh(&val.num, p_dH, &res)

#   return sotinum.create(&res)
# #-----------------------------------------------------------------------------------------------------


# #*****************************************************************************************************
# cpdef  sotinum slogb(sotinum val, int base):
#   """
#   PURPOSE:  Natural logarithm base b for OTI numbers.
   
#   EXAMPLE:   
#   """
#   #***************************************************************************************************  

  
#   global p_dH
#   cdef sotinum_t res
  

#   c_soti_logb(&val.num, base, p_dH, &res)

#   return sotinum.create(&res)
# #-----------------------------------------------------------------------------------------------------

# #*****************************************************************************************************
# cpdef  sotinum slog10(sotinum val):
#   """
#   PURPOSE:  Natural logarithm base 10 for OTI numbers.
   
#   EXAMPLE:   
#   """
#   #***************************************************************************************************  

  
#   global p_dH
#   cdef sotinum_t res
  

#   c_soti_log10(&val.num, p_dH, &res)

#   return sotinum.create(&res)
# #-----------------------------------------------------------------------------------------------------


# #*****************************************************************************************************
# cpdef  sotinum slog(sotinum val):
#   """
#   PURPOSE:  Natural logarithm for OTI numbers.
   
#   EXAMPLE:   
#   """
#   #***************************************************************************************************  
#   #Natural Logarithm
  
#   global p_dH
#   cdef sotinum_t res
  

#   c_soti_log(&val.num, p_dH, &res)

#   return sotinum.create(&res)
# #-----------------------------------------------------------------------------------------------------


# #*****************************************************************************************************
# cpdef  sotinum sexp(sotinum val):
#   """
#   PURPOSE:  Exponential function for OTI numbers.
   
#   EXAMPLE:   
#   """
#   #*************************************************************************************************** 
  
#   # create an array that contains the 
#   # Compute all derivatives of the function 
#   # up to max order of the number.
#   global p_dH
#   cdef sotinum_t res
  

#   c_soti_exp(&val.num, p_dH, &res)

#   return sotinum.create(&res)
# #-----------------------------------------------------------------------------------------------------


# #*****************************************************************************************************
# cpdef  sotinum spower(sotinum val, double exponent):
#   """
#   PURPOSE:  Power function for OTI numbers, for non integer exponents.
   
#   EXAMPLE:   
#   """
#   #*************************************************************************************************** 
#   global p_dH
#   cdef sotinum_t res

#   c_soti_pow(&val.num, exponent, p_dH, &res)

#   return sotinum.create(&res)
# #-----------------------------------------------------------------------------------------------------

# #*****************************************************************************************************
# cpdef  sotinum ssqrt(sotinum val):
#   """
#   PURPOSE:  Square root function for OTI numbers, for non integer exponents.
   
#   EXAMPLE:   
#   """
#   #*************************************************************************************************** 
#   global p_dH
#   cdef sotinum_t res

#   c_soti_sqrt(&val.num, p_dH, &res)

#   return sotinum.create(&res)
# #-----------------------------------------------------------------------------------------------------

# #*****************************************************************************************************
# cdef object c_soti_print(sotinum_t* num):
#   """
#   PURPOSE:  get string of a sotinum_t
   
#   EXAMPLE:   
#   """
#   #*************************************************************************************************** 
#   cdef uint64_t i

#   head      = ''
#   body      = ''
  
#   if num[0].size == 0 :

#     body += '  %.4f' %0.0

#   # end if 

#   for i in range(0,num[0].size):
    
#     humDir = getDirArray(num[0].p_indx[i],num[0].order)
    
#     coef = str('%+.4f' %num[0].p_coefs[i])
    
#     e_dir = printOrderPos(humDir)
    
#     if i == 0 :
      
#       sign = ''
     
#       if coef[0]=='-':
        
#         sign = coef[0] + ' '

#       else:
        
#         sign = '  '        
        
#       # end if

#     else: 
      
#       sign = coef[0] + ' '
       
#     # end if
    
#     body = body + sign + coef[1:] + e_dir
    
#   # end for
#   body += '('+ str(num[0].order)+')'
#   tail = ''
  
#   return (head + body + tail)
# #-----------------------------------------------------------------------------------------------------



#*****************************************************************************************************






