# cython: boundscheck=False 
# cython: wraparound=False 
# cython: nonecheck=False 
# cython: language_level=3
# cython: profile=False
# cython: linetrace=False
# cython: binding=True
# cython: embedsignature=False
## distutils: define_macros=CYTHON_TRACE_NOGIL=1
## distutils: libraries = oti 
## distutils: extra_compile_args = -arch i386 -arch x86_64
# filename: dense.pyx

import numpy as np                  # General numerical library
cimport numpy as np                 # C-level functions of numpy
from c_otilib cimport *             # OTI lib in C.
cimport cython                      #

from pyoti.core import   number_types, dHelp
from pyoti.core cimport  c_ptr_to_np_1darray_double, ZERO, ONE
from pyoti.core cimport  c_ptr_to_np_2darray_double
from pyoti.core cimport  get_cython_dHelp, dHelp, imdir


cdef dHelp h = get_cython_dHelp()
cdef dhelpl_t dhl = h.dhl







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
  # not _cinit_ to avoid creation with _new_
  def __init__(self, coeffs, ord_t order, bases_t nbases = 1,uint8_t FLAGS = 1): 
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
    global dhl

    cdef uint64_t sizeOfCoefs, newSizeOfCoefs, i, j, ordi
    
    self.FLAGS = FLAGS

      
    # create a list to handle the index numbers 
    if type(coeffs) in number_types:
      
      self.num = oti_createZero( nbases, order, dhl);
      self.num.re = coeffs
    
    else:
      
      sizeOfCoefs = len(coeffs) - 1
      self.num = oti_createZero( nbases, order, dhl);
      self.num.re = coeffs[0]

      if (sizeOfCoefs != self.num.ndir):
        print("mismatch")
      else:
        
        j = 1
        
        for ordi in range(self.num.order):
          
          for i in range(self.num.p_ndpo[ordi]):
            
            self.num.p_im[ordi][i] = coeffs[j]
            j += 1

          # end for

        # end for 

      # end if 

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
      # print('Freeing otinum')
      oti_free(&self.num)

    # else:

    #   self.num

    #end if 
    
  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  @property
  def  ndir(self): 
    """
    PURPOSE:      Return the number of directions in the otinum.                  
    """
    #*************************************************************************************************

    return self.num.ndir

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  @property
  def  nbases(self): 
    """
    PURPOSE:      Return the number of bases in the otinum.                  
    """
    #*************************************************************************************************

    return self.num.nbases

  #---------------------------------------------------------------------------------------------------
  
  
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

  #   return c_ptr_to_np_1darray_double(self.num.p_coefs, self.num.Ndir)

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
    global dhl

    # create new empty object:
    cdef otinum otin = <otinum> otinum.__new__(otinum)

    otin.num = num[0]
    otin.FLAGS = FLAGS
    
    return otin

  #--------------------------------------------------------------------------------------------------- 


  #*************************************************************************************************** 
  def __repr__(self):
    """
    PURPOSE:  To print a representation of the otinum object that could be
              used to create new dualnum objects, in a compact form.
  
    """
    #*************************************************************************************************
    global h
    global p_dH

    cdef uint64_t i, nsteps = 2

    head      = 'otinum('
    body      = ''
    tail = str(self.num.re)+", ndir: "+str(self.num.ndir)+', order: '+str(self.num.order)+')'
    return (head + body + tail)

  #--------------------------------------------------------------------------------------------------- 

  #***************************************************************************************************
  def __str__(self):
    """
    PURPOSE: To print a representation of the otinum object that could 
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

      for i in range(self.num.p_ndpo[ordi]):
        
        num = '%+g'%self.num.p_im[ordi][i] 
        body += ' '+num[0]+" "+num[1:]
        body += ' * e(' 
        
        body += str(h.get_compact_fulldir(i,ordi+1)).replace(' ','')
        body += ")"
      
      # end for

    # end for 
      
    tail = ''
    
    return (head + body + tail)

  #---------------------------------------------------------------------------------------------------  






  #***************************************************************************************************
  def __getitem__(self, list item):
    """
    PURPOSE:  To get the value of an otinum coefficient.
    """
    #*************************************************************************************************
    global dhl

    cdef imdir_t idx = item[ZERO]
    cdef ord_t order = item[ONE]
    return oti_get( idx, order, &self.num, dhl)

  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  def __setitem__(self, list item, coeff_t value):
    """
    PURPOSE:  To set the value of an otinum coefficient.

              !!!!! TODO:  !!!!! 
              ADD ERROR WHEN DATA OWN FLAG IS SET LOW AND INDEX LARGER THAN SELF.NUM.NDIR 
              IS GIVEN !!!!!!!!
    """
    #*************************************************************************************************
    global dhl

    cdef int i = 0, j = 1
    cdef imdir_t index = item[i]
    cdef ord_t   order = item[j]

    oti_setIm_IdxOrd( value, index, order, &self.num, dhl)


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
    global dhl

    cdef otinum_t newnum = oti_neg(&self.num, dhl)

    return otinum.create(&newnum)
  #---------------------------------------------------------------------------------------------------




  #***************************************************************************************************
  def __add__(self, other_in):
    """
    PURPOSE:      To define how to sum two otinum numbers.

    DESCRIPTION:  It overloads the sum operator "+". It allows the addition
                  of oti numbers of different orders, or even the 
                  addition of a oti number and a scalar. 

    PERFORMANCE OPTION:

                  Be careful that this is very slow because to make it more robust, it checks all 
                  input types. For better performance use method add <not __add__>.


    """
    #*************************************************************************************************
    
    global dhl
    cdef: 
      otinum_t res
      otinum tmp1, tmp2
      
    type1 = type(self)     # takes 100 ns ... 
    type2 = type(other_in) # takes 100 ns ...

    # type1 = self.__class__     # takes ~50 ns ... 
    # type2 = other_in.__class__ # takes ~50 ns ...


    if ( type1 is type2) : # Case Sum between OTIs.
      tmp1 = self
      tmp2 = other_in
      res =  oti_sum_oo(&tmp1.num, &tmp2.num, dhl);
    
    elif (type2 in number_types): # Case Sum to real number. Very slow, consider changing this...
      
      tmp1 = self
      res = oti_sum_ro( other_in, &tmp1.num, dhl);

    elif (type1 in number_types): # Case 1.5. reverse Sum to real number.
      
      tmp1 = other_in
      res = oti_sum_ro( self, &tmp1.num, dhl);      

    # end if 
      
      
    return otinum.create(&res)

  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  def __iadd__(self, other_in):
    """
    PURPOSE:      To define how to sum two otinum numbers.

    DESCRIPTION:  It overloads the inplace sum operator "+=". It allows the 
                  addition of spr_otinum numbers of different orders, and 
                  the addition of a otinum number and a scalar. 
    """
    #*************************************************************************************************

    return self + other_in

  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  def __sub__(self, other_in):
    """
    PURPOSE:      To define how to subtract two otinum numbers.

    DESCRIPTION:  It overloads the subtract operator "-". It allows the 
                  subtraction of spr_otinum numbers of different orders, 
                  and the subtraction of a otinum number and a scalar. 
    """
  #************************************************************************
    
    global dhl
    cdef: 
      otinum_t res
      otinum tmp1, tmp2
      
    type1 = type(self)     # takes 100 ns ... 
    type2 = type(other_in) # takes 100 ns ...

    # type1 = self.__class__     # takes ~50 ns ... 
    # type2 = other_in.__class__ # takes ~50 ns ...


    if ( type1 is type2) : # Case Sum between OTIs.
      tmp1 = self
      tmp2 = other_in
      res =  oti_sub_oo(&tmp1.num, &tmp2.num, dhl);
    
    elif (type2 in number_types): # Case Sum to real number. Very slow, consider changing this...
      
      tmp1 = self
      res = oti_sub_or( &tmp1.num, other_in, dhl);

    elif (type1 in number_types): # Case 1.5. reverse Sum to real number.
      
      tmp1 = other_in
      res = oti_sub_ro( self, &tmp1.num, dhl);      

    # end if 
      
    return otinum.create(&res)


  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  def __isub__(self, other_in):
    """
    PURPOSE:      To define how to subtract two spr_otinum numbers.

    DESCRIPTION:  It overloads the inplace subtract operator "-=". It allows
                  the subtraction of spr_otinum numbers of different orders, 
                  and the subtraction of a spr_otinum number and a scalar. 
    

    """
    #*************************************************************************************************
  
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
    
    """
    #*************************************************************************************************
    
    global dhl
    cdef: 
      otinum_t res
      otinum tmp1, tmp2
      
    type1 = type(self)     # takes 100 ns ... 
    type2 = type(other_in) # takes 100 ns ...

    # type1 = self.__class__     # takes ~50 ns ... 
    # type2 = other_in.__class__ # takes ~50 ns ...


    if ( type1 is type2) : # Case Sum between OTIs.
      tmp1 = self
      tmp2 = other_in
      res =  oti_mul_oo(&tmp1.num, &tmp2.num, dhl);
    
    elif (type2 in number_types): # Case Sum to real number. Very slow, consider changing this...
      
      tmp1 = self
      res = oti_mul_ro( other_in, &tmp1.num, dhl);

    elif (type1 in number_types): # Case 1.5. reverse Sum to real number.
      
      tmp1 = other_in
      res = oti_mul_ro( self, &tmp1.num, dhl);       

    # end if 

    return otinum.create(&res)

  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  def __imul__(self, other_in):
    """
    PURPOSE:      To define how to make an inplace multiplication between
                  two OTI numbers.
    
    DESCRIPTION:  It overloads the multiplication operator "*=". It allows
                  the multiplication of OTI numbers of different orders, 
                  or even the multiplication with scalars.

    """
    #*************************************************************************************************

    return self * other_in

  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  def __truediv__(self, other_in):
    """
    PURPOSE:      To define how to divide two spr_otinum numbers.
    
    DESCRIPTION:  It overloads the division operator "/". It allows the
                  division of spr_otinum numbers of different orders, and 
                  the division of a spr_otinum number and a scalar. 

    """
    #*************************************************************************************************
    
    global dhl
    cdef: 
      otinum_t res
      otinum tmp1, tmp2
      
    type1 = type(self)     # takes 100 ns ... 
    type2 = type(other_in) # takes 100 ns ...

    # type1 = self.__class__     # takes ~50 ns ... 
    # type2 = other_in.__class__ # takes ~50 ns ...


    if ( type1 is type2) : # Case Sum between OTIs.
      
      tmp1 = self
      tmp2 = other_in
      res =  oti_div_oo(&tmp1.num, &tmp2.num, dhl);
    
    elif (type2 in number_types): # Case Sum to real number. Very slow, consider changing this...
      
      tmp1 = self
      res = oti_div_or( &tmp1.num, other_in, dhl);

    elif (type1 in number_types): # Case 1.5. reverse Sum to real number.
      
      tmp1 = other_in
      res = oti_div_ro( self, &tmp1.num, dhl);       

    # end if 

    return otinum.create(&res)

  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  def __pow__(self, n,z):
    """
    PURPOSE:      Power the number to exponent n.
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
    """
    #*************************************************************************************************
    global dhl
    
    cdef otinum_t res = oti_copy(&self.num,dhl)

    return otinum.create(&res)

  #---------------------------------------------------------------------------------------------------  



#   #***************************************************************************************************
#   cpdef void changeOrder(self,uint8_t neworder):
#     """
#     PURPOSE:      To change the order of a spr_otinum.

#     DESCRIPTION:  According to the new order, the index values are changed. 

#     """
#     #*************************************************************************************************
#     global p_dH

#     c_oti_changeOrder(&self.num, neworder, p_dH)


#   #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  cpdef coeff_t get_deriv( self, list item):
    """
    PURPOSE:      to retrieve the derivative contained in the oti number.

    """
    #*************************************************************************************************
    global dhl

    cdef imdir_t indx = item[ZERO]
    cdef ord_t  order = item[ONE]
    
    return oti_get_deriv(indx,order,&self.num,dhl) 

  #---------------------------------------------------------------------------------------------------  

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
#     PURPOSE:      To convert a otinum into its matrix form.
                  
#     DESCRIPTION:  Convert to its own Cauchy-Riemann representation form.
                   
#     INPUTS:
#                   ismat: To define a matrix (1) or a vector (0)

#                   m:     To use the shape that will result of the number 
#                          (-1) or an specific shape (given value).

#                   isspr: Matrix in a sparse matrix (1) or not (0).
                    
#     """
#     #*************************************************************************************************
    
#     global h
#     global p_dH

#     cdef: 
#       uint64_t i, k, j
#       uint64_t finalshape, nIterMin,  maxI
#       double* data   
#       uint64_t* shape


#     if m == -1:
#       # Deduce the matrix dimension by looking at the last indx and 
#       # looking for the maximum base direction
      
#       # Separate cases for order 1 and others.       
#       m_max =  c_helper_findMaxDir(self.num.Ndir-1,self.num.order,p_dH)

#     else:
      
#       m_max = m
      
#     # end if

#     finalshape = c_helper_getNels(m_max, self.num.order, p_dH)

    
#     if ismat == 0:
#       # vector type
      
#       mat = np.zeros(finalshape)
      
#       # Do only a certain amount of iterations:
#       c_minUI64(finalshape, self.num.Ndir, &nIterMin, &maxI)
      
#       k = 0

#       for i in range(nIterMin):
        
#         mat[i] = self.num.p_coefs[i]

#       # end for
      
#     else:

#       # matrix type
      
#       if isspr == 0:
#         #return the np.array?
#         #mat = np.array(__otinum2Mat_dense(self, finalshape))
        
#         data = c_oti_num2mat(&self.num, finalshape, p_dH)
#         mat = c_ptr_to_np_2darray_double(data,finalshape,finalshape, numpy_own = 1)
        
#       else:
        
        
#         pass

        
#       # end if
      

#     # end if 
    
    
#     return mat

#   #---------------------------------------------------------------------------------------------------




# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# :::::::::::::::::::::::::::::::::::: END OF CLASS OTINUM :::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::





























#*****************************************************************************************************
cpdef  otinum cos(otinum val):
  """
  PURPOSE:  Mathematical function of cosine for OTI numbers
  """
  #***************************************************************************************************

  global dhl
  
  cdef otinum_t res = oti_cos(&val.num, dhl)

  return otinum.create(&res)
#-----------------------------------------------------------------------------------------------------


#*****************************************************************************************************
cpdef  otinum sin(otinum val):
  """
  PURPOSE:  Mathematical function of sine for OTI numbers.
  """
  #***************************************************************************************************
  global dhl
  
  cdef otinum_t res = oti_sin(&val.num, dhl)

  return otinum.create(&res)
#-----------------------------------------------------------------------------------------------------


#*****************************************************************************************************
cpdef  otinum tan(otinum val):
  """
  PURPOSE:  Mathematical function of tangent for OTI numbers 
  """
  #***************************************************************************************************
  global dhl
  
  cdef otinum_t res = oti_tan(&val.num, dhl)

  return otinum.create(&res)
#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cpdef  otinum atan(otinum val):
  """
  PURPOSE:  Mathematical function of arctangent for OTI numbers
  """
  #***************************************************************************************************
  global dhl
  
  cdef otinum_t res = oti_atan(&val.num, dhl)

  return otinum.create(&res)
#-----------------------------------------------------------------------------------------------------

# #*****************************************************************************************************
# cpdef  otinum atan2(otinum valx, otinum valy):
#   """
#   PURPOSE:  Mathematical function of arctangent for OTI numbers
   
#   EXAMPLE:   
#   """
#   #***************************************************************************************************
#   global dhl
  
#   cdef otinum_t res = oti_atan2(&valx.num, &valy.num, dhl)

#   return otinum.create(&res)
# #-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cpdef  otinum acos(otinum val):
  """
  PURPOSE:  Mathematical function of inverse cosine for OTI numbers
  """
  #***************************************************************************************************
  global dhl
  
  cdef otinum_t res = oti_acos(&val.num, dhl)

  return otinum.create(&res)
#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cpdef  otinum asin(otinum val):
  """
  PURPOSE:  Mathematical function of inverse sine for OTI numbers
  """
  #***************************************************************************************************
  global dhl
  
  cdef otinum_t res = oti_asin(&val.num, dhl)

  return otinum.create(&res)
#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cpdef  otinum sinh(otinum val):
  """
  PURPOSE:  Mathematical function of hyperbolic sine for OTI numbers
  """
  #***************************************************************************************************
  global dhl
  
  cdef otinum_t res = oti_sinh(&val.num, dhl)

  return otinum.create(&res)
#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cpdef  otinum asinh(otinum val):
  """
  PURPOSE:  Mathematical function of inverse hyperbolic sine for OTI numbers  
  """
  #***************************************************************************************************
  global dhl
  
  cdef otinum_t res = oti_asinh(&val.num, dhl)

  return otinum.create(&res)
#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cpdef  otinum cosh(otinum val):
  """
  PURPOSE:  Mathematical function of hyperbolic cosine for OTI numbers 
  """
  #***************************************************************************************************
  global dhl
  
  cdef otinum_t res = oti_cosh(&val.num, dhl)

  return otinum.create(&res)
#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cpdef  otinum acosh(otinum val):
  """
  PURPOSE:  Mathematical function of inverse hyperbolic cosine for OTI numbers

  """
  #***************************************************************************************************
  global dhl
  
  cdef otinum_t res = oti_acosh(&val.num, dhl)

  return otinum.create(&res)
#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cpdef  otinum tanh(otinum val):
  """
  PURPOSE:  Mathematical function of hyperbolic tangent for OTI numbers  
  """
  #***************************************************************************************************
  global dhl
  
  cdef otinum_t res = oti_tanh(&val.num, dhl)

  return otinum.create(&res)
#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cpdef  otinum atanh(otinum val):
  """
  PURPOSE:  Mathematical function of Inverse hyperbolic tangent for OTI numbers

  """
  #***************************************************************************************************
  global dhl
  
  cdef otinum_t res = oti_atanh(&val.num, dhl)

  return otinum.create(&res)
#-----------------------------------------------------------------------------------------------------


#*****************************************************************************************************
cpdef  otinum logb(otinum val, float base):
  """
  PURPOSE:  Logarithm base b for OTI numbers.
  """
  #***************************************************************************************************  

  
  global dhl
  
  cdef otinum_t res = oti_logb(&val.num, base, dhl)

  return otinum.create(&res)
#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cpdef  otinum log10(otinum val):
  """
  PURPOSE:  Natural logarithm base 10 for OTI numbers.
  """
  #***************************************************************************************************  

  global dhl
  
  cdef otinum_t res = oti_log10(&val.num, dhl)

  return otinum.create(&res)
#-----------------------------------------------------------------------------------------------------


#*****************************************************************************************************
cpdef  otinum log(otinum val):
  """
  PURPOSE:  Natural logarithm for OTI numbers. 
  """
  #***************************************************************************************************  
  global dhl
  
  cdef otinum_t res = oti_log(&val.num, dhl)

  return otinum.create(&res)
#-----------------------------------------------------------------------------------------------------


#*****************************************************************************************************
cpdef  otinum exp(otinum val):
  """
  PURPOSE:  Exponential function for OTI numbers.
  """
  #*************************************************************************************************** 
  global dhl
  
  cdef otinum_t res = oti_exp(&val.num, dhl)

  return otinum.create(&res)
#-----------------------------------------------------------------------------------------------------


#*****************************************************************************************************
cpdef  otinum power(otinum val, double exponent):
  """
  PURPOSE:  Power function for OTI numbers, for non integer exponents.
  """
  #*************************************************************************************************** 
  global dhl

  cdef otinum_t res = oti_pow(&val.num, exponent, dhl)

  return otinum.create(&res)
#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cpdef  otinum sqrt(otinum val):
  """
  PURPOSE:  Square root function for OTI numbers, for non integer exponents. 
  """
  #*************************************************************************************************** 
  global dhl
  
  cdef otinum_t res = oti_sqrt(&val.num, dhl)

  return otinum.create(&res)
#-----------------------------------------------------------------------------------------------------







#*****************************************************************************************************
def e( hum_dir ,ord_t order = 0,bases_t nbases = 0):
  """
  PURPOSE:  To create an OTI number with value 1 at the specified
            direction, in a human friendly manner.

  """
  #***************************************************************************************************
  
  global dhl

  cdef imdir_t indx_hd
  cdef ord_t order_hd
  cdef bases_t bases_hd
  cdef otinum_t res
  
  [indx_hd, order_hd] = imdir(hum_dir)
  
  bases_hd = (dhelp_get_imdir( indx_hd, order_hd, dhl))[order_hd-1]
  
  res = oti_createZero(max(bases_hd,nbases), max(order_hd,order), dhl)

  # Set the coefficient to 1.
  oti_setIm_IdxOrd(1.0,indx_hd,order_hd,&res,dhl)    

  return otinum.create(&res)

# #-----------------------------------------------------------------------------------------------------















# Append array code.

include "dense_array.pxi"
