




# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::     CLASS  OTINUM    ::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
cdef class otinum:
  """
  OTI scalar number class.

  OTI is short for Order Truncated Imaginary numbers, which will allow you to compute derivatives
  very precisely on computer machines. The main idea is that you use OTIs as an on-demand tool
  to compute derivatives of a program, by perturbing the variable of interest with an OTI direction.

  Example:

  >>> import pyoti.dense as oti
  >>> x = 3.5 + oti.e(1, order=2)
  >>> f = oti.sin(x**2)* oti.log(x)  # <-- This is the function we want to differentiate.
  >>>                                # At this point f already contains all derivatives, 
  >>>                                # we just need to extract them
  >>> f
  out: -0.389759 + 8.24523 * e([1]) + 12.6531 * e([[1,2]])
  >>> # This is the oti representation.
  >>>
  >>> f.get_all_deriv()
  out: array([-0.38975881,  8.24523458, 25.30624122])
  >>> #       ^ f(3.5)     ^ df/dx(3.5) ^ d^2f/dx^2(3.5)



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
                  
                  nbases: Integer that sets the number of imaginary bases of the number.

                  order:  Integer that sets the maximum order of the number.
                  
                      Example:  coefs  = [1, 2, 3],
                                nbases = 1,
                                order  = 2
                                
                      creates an OTI number:
                      1.0 + 2.0 * e([1]) + 3.0 * e([[1,2]])
                  
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
        print("Size mismatch of coeffs and the number of dimensions for nbases: "+
          str(nbases) + " and order: "+str(order)+".")
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
  
  
  #***************************************************************************************************
  @property
  def  order(self): 
    """
    PURPOSE:      To return the maximum order of the number.

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

    otin.num  = num[0]
    otin.FLAGS = FLAGS
    
    return otin

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

    else:

      return NotImplemented         

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

    else:

      return NotImplemented          

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

    else:

      return NotImplemented      

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

    else:

      return NotImplemented      

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
  def __float__(self):
    """
    PORPUSE:      Overload of function float()
    """
    return self.num.re
  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  cpdef coeff_t get_deriv( self, hum_dir):
    """
    PURPOSE:      to retrieve the derivative contained in the oti number.

    """
    #*************************************************************************************************
    global dhl
    cdef list item = imdir(hum_dir)
    cdef imdir_t indx = item[ZERO]
    cdef ord_t  order = item[ONE]
    
    return oti_get_deriv(indx,order,&self.num,dhl) 

  #---------------------------------------------------------------------------------------------------  

  #***************************************************************************************************
  def get_all_deriv( self, int16_t order = -1, get_indices = False):
    """
    PURPOSE:    To retreive the derivatives contained in the oti number.

    """
    #*************************************************************************************************
    global dhl

    cdef uint64_t i, j, k
    cdef ord_t ordi
    cdef np.ndarray res



    if order == -1:

      # Get all derivatives of all orders.
      res = np.empty((self.num.ndir+1,),dtype = np.float64)

      j = 0
      res[j] = self.num.re; j += 1
      
      for ordi in range( self.num.order ):

        for i in range( self.num.p_ndpo[ordi] ):

          res [ j ] = oti_get_deriv( i, ordi+1, &self.num, dhl); j += 1

        # end for 

      # end for 

    else:

      if order <= self.num.order:
        if order == 0:
          
          res = np.empty((1,),dtype=np.float64)
          res[0] = self.num.re

        else:

          res = np.empty((self.num.p_ndpo[order-1],),dtype=np.float64)

          for i in range(self.num.p_ndpo[order-1]):

            res[i] = oti_get_deriv(i,order,&self.num,dhl) 

          # end for 

        # end if 

      # end if 

    # end if 
    
    return res

  #---------------------------------------------------------------------------------------------------  

  #***************************************************************************************************
  def to_vector(self):
    """
    PURPOSE:      To convert an otinum into its vector form.
                    
    """
    #*************************************************************************************************
    cdef np.ndarray res
    cdef uint64_t i, j
    cdef ord_t ordi

    res = np.empty((self.num.ndir+1,),dtype = np.float64)

    j = 0
    res[j] = self.num.re; j += 1

    if self.num.order > 0:

      for ordi in range(self.num.order):
      
        for i in range(self.num.p_ndpo[ordi]):
      
          res[j] = self.num.p_im[ordi][i]; j+=1
      
        # end for
      
      # end for 

    # end if 

    return res

  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  def to_matrix(self,sparse_mat = False):
    """
    This function converts an otinum into its equivalent real-only matrix form 
    (Cauchy-Riemann matrix form).
    
    :param sparse_mat: Bool to specify if it returns a sparse matrix.
    :type sparse_mat: bool, optional. Default  sparse_mat=False.
    
    """
    #*************************************************************************************************

    global dhl
    
    cdef darr_t res

    res = oti_to_cr_dense(&self.num,  dhl)

    return dmat.create(&res)

  #---------------------------------------------------------------------------------------------------  

  

# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# :::::::::::::::::::::::::::::::::::: END OF CLASS OTINUM :::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::





















