




# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::     CLASS  OTINUM    ::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
cdef class oti_n2m2:
  #---------------------------------------------------------------------------------------------------
  #------------------------------------   DEFINITION OF ATTRIBUTES   ---------------------------------
  #---------------------------------------------------------------------------------------------------
  
  #                                --->      Look in otinum.pxd    <---

  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  # not _cinit_ to avoid creation with _new_
  def __init__(self, coeff_t real, coeff_t e1 = 0., coeff_t e2 = 0., 
               coeff_t e11 = 0., coeff_t e12 = 0., coeff_t e22 = 0.): 
    """
    PURPOSE:      Python level constructor of the otinum class.

    DESCRIPTION:  Creates a new OTI number given a list of coefficients.

    PARAMETERS:
                 
                  coefs:  List of coefficients. Can be any iterator. 
                  
                  nbases: Integer that sets the number of imaginary bases of the number.

                  order:  Integer that sets the maximum order of the number.
                  
                      Example:  coefs  = [1, 2, 3],
                                nbases = 1,
                                order  = 2
                                
                      creates an OTI number:
                      1.0 + 2.0 * e([1]) + 3.0 * e([[1,2]])
                  
    """
    #*************************************************************************************************
    
    self.re = real
    self.e1 = e1
    self.e2 = e2
    self.e11 = e11
    self.e12 = e12
    self.e22 = e22

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  @property
  def  ndir(self): 
    """
    PURPOSE:      Return the number of directions in the otinum.                  
    """
    #*************************************************************************************************

    return 6

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  @property
  def nbases(self): 
    """
    PURPOSE:      Return the number of bases in the otinum.                  
    """
    #*************************************************************************************************

    return 2

  #---------------------------------------------------------------------------------------------------
  
  
  #***************************************************************************************************
  @property
  def  order(self): 
    """
    PURPOSE:      To return the maximum order of the number.

    DESCRIPTION:  Reads the value in num.
                  
    """
    #*************************************************************************************************

    return 2

  #---------------------------------------------------------------------------------------------------

  #*************************************************************************************************** 
  def __repr__(self):
    """
    PURPOSE:  To print a representation of the otinum object that could be
              used to create new otinum objects.
  
    """
    #*************************************************************************************************
    
    
    return self.__str__()

  #--------------------------------------------------------------------------------------------------- 

  #*************************************************************************************************** 
  def short_repr(self):
    """
    PURPOSE:  To print a representation of the otinum object that could be
              used to create new otinum objects, in a compact form.
  
    """
    #*************************************************************************************************
    
    global dhl

    head      = 'oti_n2m2('
    body      = ''
    tail = str(self.re)+", ndir: "+str(self.ndir)+', order: '+str(self.order)+')'

    return (head + body + tail)

  #--------------------------------------------------------------------------------------------------- 

  #***************************************************************************************************
  def __str__(self):
    """
    PURPOSE: To print a representation of the otinum object that could 
             be easy to read and understand.  
    
    """
    #*************************************************************************************************
    
    head      = ''
    body      = ''
    
    # Real
    body += '%g'%self.re+' '

    # Order 1
    body += '%+g'%self.e1 +' * e([1]) '
    body += '%+g'%self.e2 +' * e([2]) '

    # Order 2
    body += '%+g'%self.e11 +' * e([[1,2]]) '
    body += '%+g'%self.e12 +' * e([1,2]) '
    body += '%+g'%self.e22 +' * e([[2,2]]) '
      
    tail = ''
    
    return (head + body + tail)

  #---------------------------------------------------------------------------------------------------  



  #***************************************************************************************************
  def __getitem__(self, list item):
    """
    PURPOSE:  To get the value of an otinum coefficient.
    """
    #*************************************************************************************************
    

    cdef imdir_t idx = item[ZERO]
    cdef ord_t order = item[ONE]
    cdef coeff_t res = 0.0

    if (order == 0):
      res = self.re
    elif (order == 1) :
      if item == 0:
        res = self.e1
      elif item == 1:
        res = self.e2
      # end if 
    elif (order == 2):
      if item == 0:
        res = self.e11
      elif item == 1:
        res = self.e12
      elif item == 2:
        res = self.e22
      # end if 
    # end if 
    return res

  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  def __setitem__(self, list item, coeff_t value):
    """
    PURPOSE:  To set the value of an otinum coefficient.

    """
    #*************************************************************************************************
    cdef int i = 0, j = 1
    cdef imdir_t index = item[i]
    cdef ord_t   order = item[j]

    if (order == 0):
      self.re = value
    elif (order == 1) :
      if item == 0:
        self.e1 = value
      elif item == 1:
        self.e2 = value
      # end if 
    elif (order == 2):
      if item == 0:
        self.e11 = value
      elif item == 1:
        self.e12 = value
      elif item == 2:
        self.e22 = value
      # end if 
    # end if 


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
    cdef: 
      oti_n2m2 tmp1 = self, res = oti_n2m2(0.0)
      
    
    
    

    res.re  = -tmp1.re

    res.e1  = -tmp1.e1
    res.e2  = -tmp1.e2

    res.e11 = -tmp1.e11
    res.e12 = -tmp1.e12
    res.e22 = -tmp1.e22
      
      
    return res
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
    
    cdef: 
      oti_n2m2 tmp1, tmp2, res = oti_n2m2(0.0)
      
    type1 = type(self)     # takes 100 ns ... 
    type2 = type(other_in) # takes 100 ns ...

    # type1 = self.__class__     # takes ~50 ns ... 
    # type2 = other_in.__class__ # takes ~50 ns ...


    if ( type1 is type2) : # Case Sum between OTIs.
      tmp1 = self
      tmp2 = other_in

      res.re  = tmp1.re + tmp2.re 

      res.e1  = tmp1.e1 + tmp2.e1 
      res.e2  = tmp1.e2 + tmp2.e2 

      res.e11 = tmp1.e11+ tmp2.e11
      res.e12 = tmp1.e12+ tmp2.e12
      res.e22 = tmp1.e22+ tmp2.e22
    
    elif (type2 in number_types): # Case Sum to real number. Very slow, consider changing this...
      
      tmp1 = self
      
      res.re  = tmp1.re + other_in

      res.e1  = tmp1.e1
      res.e2  = tmp1.e2
      
      res.e11 = tmp1.e11
      res.e12 = tmp1.e12
      res.e22 = tmp1.e22

    elif (type1 in number_types): # Case 1.5. reverse Sum to real number.
      
      tmp1 = other_in
      
      res.re  = tmp1.re + self

      res.e1  = tmp1.e1
      res.e2  = tmp1.e2
      
      res.e11 = tmp1.e11
      res.e12 = tmp1.e12
      res.e22 = tmp1.e22

    else:

      return NotImplemented         

    # end if 
      
      
    return res

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

    cdef: 
      oti_n2m2 tmp1, tmp2, res = self
      
    type2 = type(other_in) # takes 100 ns ...

    # type1 = self.__class__     # takes ~50 ns ... 
    # type2 = other_in.__class__ # takes ~50 ns ...


    if ( type2 is oti_n2m2 ) : # Case Sum between OTIs.
      
      tmp2 = other_in

      res.re  += tmp2.re 

      res.e1  += tmp2.e1 
      res.e2  += tmp2.e2 

      res.e11 += tmp2.e11
      res.e12 += tmp2.e12
      res.e22 += tmp2.e22
    
    elif (type2 in number_types): # Case Sum to real number. Very slow, consider changing this...
      
      res.re  += other_in

    else:

      return NotImplemented         

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
    """
  #************************************************************************
    
    cdef: 
      oti_n2m2 tmp1, tmp2, res = oti_n2m2(0.0)
      
    type1 = type(self)     # takes 100 ns ... 
    type2 = type(other_in) # takes 100 ns ...

    # type1 = self.__class__     # takes ~50 ns ... 
    # type2 = other_in.__class__ # takes ~50 ns ...


    if ( type1 is type2) : # Case Sum between OTIs.
      tmp1 = self
      tmp2 = other_in

      res.re  = tmp1.re - tmp2.re 

      res.e1  = tmp1.e1 - tmp2.e1 
      res.e2  = tmp1.e2 - tmp2.e2 

      res.e11 = tmp1.e11- tmp2.e11
      res.e12 = tmp1.e12- tmp2.e12
      res.e22 = tmp1.e22- tmp2.e22
    
    elif (type2 in number_types): # Case Sum to real number. Very slow, consider changing this...
      
      tmp1 = self
      
      res.re  = tmp1.re - other_in

      res.e1  = tmp1.e1
      res.e2  = tmp1.e2
      
      res.e11 = tmp1.e11
      res.e12 = tmp1.e12
      res.e22 = tmp1.e22

    elif (type1 in number_types): # Case 1.5. reverse Sum to real number.
      
      tmp1 = other_in
      
      res.re  = -tmp1.re + self

      res.e1  = -tmp1.e1
      res.e2  = -tmp1.e2
      
      res.e11 = -tmp1.e11
      res.e12 = -tmp1.e12
      res.e22 = -tmp1.e22

    else:

      return NotImplemented         

    # end if 
      
      
    return res


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
  
    cdef: 
      oti_n2m2 tmp1, tmp2, res = self
      
    type2 = type(other_in) # takes 100 ns ...

    # type1 = self.__class__     # takes ~50 ns ... 
    # type2 = other_in.__class__ # takes ~50 ns ...


    if ( type2 is oti_n2m2 ) : # Case Sum between OTIs.
      
      tmp2 = other_in

      res.re  -= tmp2.re 

      res.e1  -= tmp2.e1 
      res.e2  -= tmp2.e2 

      res.e11 -= tmp2.e11
      res.e12 -= tmp2.e12
      res.e22 -= tmp2.e22
    
    elif (type2 in number_types): # Case Sum to real number. Very slow, consider changing this...
      
      res.re  -= other_in

    else:

      return NotImplemented         

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
    
    """
    #*************************************************************************************************
    
    cdef: 
      oti_n2m2 tmp1, tmp2, res = oti_n2m2(0.0)
      
    type1 = type(self)     # takes 100 ns ... 
    type2 = type(other_in) # takes 100 ns ...

    # type1 = self.__class__     # takes ~50 ns ... 
    # type2 = other_in.__class__ # takes ~50 ns ...


    if ( type1 is type2) : # Case Sum between OTIs.
      tmp1 = self
      tmp2 = other_in

      res.re  = tmp1.re * tmp2.re 

      res.e1  = tmp1.e1*tmp2.re + tmp1.re * tmp2.e1
      res.e2  = tmp1.e2*tmp2.re + tmp1.re * tmp2.e2

      res.e11 = tmp1.e11*tmp2.re+ tmp1.re*tmp2.e11 + tmp1.e1*tmp2.e1 
      res.e12 = tmp1.e12*tmp2.re+ tmp1.re*tmp2.e12 + tmp1.e1*tmp2.e2 + tmp1.e2*tmp2.e1
      res.e22 = tmp1.e22*tmp2.re+ tmp1.re*tmp2.e22 + tmp1.e2*tmp2.e2 
    
    elif (type2 in number_types): # Case Sum to real number. Very slow, consider changing this...
      
      tmp1 = self
      
      res.re  = tmp1.re*other_in

      res.e1  = tmp1.e1*other_in
      res.e2  = tmp1.e2*other_in
      
      res.e11 = tmp1.e11*other_in
      res.e12 = tmp1.e12*other_in
      res.e22 = tmp1.e22*other_in

    elif (type1 in number_types): # Case 1.5. reverse Sum to real number.
      
      tmp1 = other_in
      
      res.re  = tmp1.re*self

      res.e1  = tmp1.e1*self
      res.e2  = tmp1.e2*self
      
      res.e11 = tmp1.e11*self
      res.e12 = tmp1.e12*self
      res.e22 = tmp1.e22*self

    else:

      return NotImplemented         

    # end if 
      
      
    return res

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

    cdef: 
      oti_n2m2 tmp1, tmp2, res = self
    
    type2 = type(other_in) # takes 100 ns ...

    # type1 = self.__class__     # takes ~50 ns ... 
    # type2 = other_in.__class__ # takes ~50 ns ...


    if ( type2 is oti_n2m2 ) : # Case Sum between OTIs.
      
      tmp2 = other_in

      res.re  *= tmp2.re 

      res.e1  = res.e1*tmp2.re + res.re * tmp2.e1
      res.e2  = res.e2*tmp2.re + res.re * tmp2.e2

      res.e11 = res.e11*tmp2.re+ res.re*tmp2.e11 + res.e1*tmp2.e1 
      res.e12 = res.e12*tmp2.re+ res.re*tmp2.e12 + res.e1*tmp2.e2 + res.e2*tmp2.e1
      res.e22 = res.e22*tmp2.re+ res.re*tmp2.e22 + res.e2*tmp2.e2 
    
    elif (type2 in number_types): # Case Sum to real number. Very slow, consider changing this...
      
      res.re  *= other_in

      res.e1  *= other_in
      res.e2  *= other_in
      
      res.e11 *= other_in
      res.e12 *= other_in
      res.e22 *= other_in

    else:

      return NotImplemented         

    # end if 
      
      
    return res

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
    pass

  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  def __pow__(self, n,z):
    """
    PURPOSE:      Power the number to exponent n.
    """
    #*************************************************************************************************

    # General feval.    

  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  def copy(self):
    """
    PURPOSE:      To create a copy of a spr_otinum object, totally 
                  independent of the original.

    DESCRIPTION:  The equality operator "=" is intended to create aliases
                  of multicomplex numbers. You should use copy() when you
                  need a copy instead of an alias.
    """
    #*************************************************************************************************
    return oti_n2m2(self.re, e1=self.e1, e2=self.e2, e11=self.e11, e12=self.e12, e22=self.e22)

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
  
  # #***************************************************************************************************
  # def __float__(self):
  #   """
  #   PORPUSE:      Overload of function float()
  #   """
  #   return self.num.re
  # #---------------------------------------------------------------------------------------------------  


  # #***************************************************************************************************
  # cpdef coeff_t get_deriv( self, hum_dir):
  #   """
  #   PURPOSE:      to retrieve the derivative contained in the oti number.

  #   """
  #   #*************************************************************************************************
  #   global dhl
  #   cdef list item = imdir(hum_dir)
  #   cdef imdir_t indx = item[ZERO]
  #   cdef ord_t  order = item[ONE]
    
  #   return oti_get_deriv(indx,order,&self.num,dhl) 

  # #---------------------------------------------------------------------------------------------------  

  # #***************************************************************************************************
  # def get_all_deriv( self, int16_t order = -1, get_indices = False):
  #   """
  #   PURPOSE:    To retreive the derivatives contained in the oti number.

  #   """
  #   #*************************************************************************************************
  #   global dhl

  #   cdef uint64_t i, j, k
  #   cdef ord_t ordi
  #   cdef np.ndarray res



  #   if order == -1:

  #     # Get all derivatives of all orders.
  #     res = np.empty((self.num.ndir+1,),dtype = np.float64)

  #     j = 0
  #     res[j] = self.num.re; j += 1
      
  #     for ordi in range( self.num.order ):

  #       for i in range( self.num.p_ndpo[ordi] ):

  #         res [ j ] = oti_get_deriv( i, ordi+1, &self.num, dhl); j += 1

  #       # end for 

  #     # end for 

  #   else:

  #     if order <= self.num.order:
  #       if order == 0:
          
  #         res = np.empty((1,),dtype=np.float64)
  #         res[0] = self.num.re

  #       else:

  #         res = np.empty((self.num.p_ndpo[order-1],),dtype=np.float64)

  #         for i in range(self.num.p_ndpo[order-1]):

  #           res[i] = oti_get_deriv(i,order,&self.num,dhl) 

  #         # end for 

  #       # end if 

  #     # end if 

  #   # end if 
    
  #   return res

  # #---------------------------------------------------------------------------------------------------  

  # #***************************************************************************************************
  # def to_vector(self):
  #   """
  #   PURPOSE:      To convert an otinum into its vector form.
                    
  #   """
  #   #*************************************************************************************************
  #   cdef np.ndarray res
  #   cdef uint64_t i, j
  #   cdef ord_t ordi

  #   res = np.empty((self.num.ndir+1,),dtype = np.float64)

  #   j = 0
  #   res[j] = self.num.re; j += 1

  #   if self.num.order > 0:

  #     for ordi in range(self.num.order):
      
  #       for i in range(self.num.p_ndpo[ordi]):
      
  #         res[j] = self.num.p_im[ordi][i]; j+=1
      
  #       # end for
      
  #     # end for 

  #   # end if 

  #   return res

  # #---------------------------------------------------------------------------------------------------  


  # #***************************************************************************************************
  # def to_matrix(self,sparse_mat = False):
  #   """
  #   PURPOSE:      To convert an otinum into its matrix form.
                  
  #   DESCRIPTION:  Convert to its own Cauchy-Riemann representation vector.
    
  #   INPUTS:
  #                 ismat: To define a matrix (1) or a vector (0)
  #                 isshape: To use the shape that will result of the number 
  #                   (-1) or an specific shape (given value).
  #                 isspr: To result in a sparse matrix (1) or not (0).
  #   """
  #   #*************************************************************************************************

  #   global dhl
    
  #   cdef darr_t res

  #   res = oti_to_cr_dense(&self.num,  dhl)

  #   return dmat.create(&res)

  # #---------------------------------------------------------------------------------------------------  

  

# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# :::::::::::::::::::::::::::::::::::: END OF CLASS OTINUM :::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::




















