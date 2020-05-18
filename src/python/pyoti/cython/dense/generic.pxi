print_options = {}
print_options['im_obj_separator'] = "\n"
print_options['term_separator']   = "*\n"
print_options['epsilon']          = "e"

# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::     CLASS  OTINUM    ::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
cdef class otibase:
  """
  Dense OTI scalar number base class.

  OTI is short for Order Truncated Imaginary numbers, which will allow you to compute derivatives
  very precisely on computer machines. The main idea is that you use OTIs as an on-demand tool
  to compute derivatives of a program that is enabled to use this algebra, by perturbing the 
  variable of interest with an OTI direction.

  """
  #---------------------------------------------------------------------------------------------------
  #------------------------------------   DEFINITION OF ATTRIBUTES   ---------------------------------
  #---------------------------------------------------------------------------------------------------
  


  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  # 
  def __init__(self, ord_t order, bases_t nbases = 1, type dtype = object, 
    object zero = None):
  # object identity = 1
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

    cdef uint64_t i
    cdef ord_t ordi
    
    self.nbases = nbases
    self.order  = order
    self.ndir   =  0      # Initialize element.
    self.dtype  = dtype


    # Try if the zeroth element passed has a copy method.
    has_copy = True
    try:
      zero.copy()
    except:
      has_copy = False
    # end Try.

    if has_copy:
      element = zero.copy()
    else:
      element = zero
    # end if

    self.re = zero

    self.p_im   = np.empty( self.order, dtype=np.ndarray)
    self.p_ndpo = np.zeros( self.order, dtype=np.uint64)

    # self.zero     = zero
    # self.identity = identity
   
    for ordi in range(self.order):
      
      self.p_ndpo[ordi] = dhelp_extract_ndirOrder( self.nbases, ordi+1, dhl )
      
      self.p_im[ordi]   = np.zeros( self.p_ndpo[ordi], dtype = object)

      self.ndir += self.p_ndpo[ordi]

      for i in range(self.p_ndpo[ordi]):
        
        if has_copy: 
          element = zero.copy()
        else:
          element = zero
        # end if 

        self.p_im[ordi][i] = element
      
    # end for  
    

  #---------------------------------------------------------------------------------------------------

#   #***************************************************************************************************
#   def __dealloc__(self): 
#     """
#     PURPOSE:      Destructor of the class. 

#     DESCRIPTION:  Frees all pointers allocated in the 
                  
#     """
#     #*************************************************************************************************
#     # print("Deallocating memory of otinum.")
#     if self.FLAGS & 1: # If memory is owned by this otinum.
#       # print('Freeing otinum')
#       oti_free(&self.num)

#     # else:

#     #   self.num

#     #end if 
    
#   #---------------------------------------------------------------------------------------------------

    


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
  def __str__(self):
    """
    PURPOSE: To print a representation of the otinum object that could 
             be easy to read and understand.  
    
    """
    #*************************************************************************************************
    
    global dhl
    global h

    
    cdef ord_t ordi
    cdef ndir_t   i


    head      = ''
    body      = ''
    
    body += str(self.re)

    for ordi in range(0,self.order):

      for i in range(self.p_ndpo[ordi]):
        
        body += print_options['im_obj_separator']
        body += "+"
        body += print_options['epsilon']+'(' 
        body += str(h.get_compact_fulldir(i,ordi+1)).replace(' ','')
        body += ")"
        body += print_options['term_separator']
        num   = str(self.p_im[ordi][i])

        body += num
      
      # end for

    # end for 
      
    tail = ''
    
    return (head + body + tail)

  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  def empty_like(self):

    return otibase(self.order, nbases=self.nbases, dtype = self.dtype, zero = None)

  #---------------------------------------------------------------------------------------------------  

  #***************************************************************************************************
  def copy(self):

    cdef otibase res = self.empty_like()

    # Has copy?
    has_copy = True
    try:
      self.re.copy()
    except:
      has_copy = False
    # end Try.

    if has_copy:

      res.re = self.re.copy()

      for ordi in range(self.order):
        
        for i in range(self.p_ndpo[ordi]):
          
          res.p_im[ordi][i] = self.p_im[ordi][i].copy()
        
        # end 

      # end 

    else:
      
      res.re = self.re

      for ordi in range(self.order):
        
        for i in range(self.p_ndpo[ordi]):
          
          res.p_im[ordi][i] = self.p_im[ordi][i]
        
        # end 

      # end 

    # end if 
    return res

  #---------------------------------------------------------------------------------------------------  



    


  #***************************************************************************************************
  def __getitem__(self,item):
    """
    PURPOSE:  Propagate get item through all elements.
    """
    #*************************************************************************************************
    
    # get all items from other elements.

    cdef otibase res = otibase(self.order, nbases=self.nbases, dtype = self.dtype, zero = None);
    cdef ndir_t i
    cdef ord_t ordi
    # Try to propagate the get item through all operations.  
    try:

      res.re = self.re[item]
      
      for ordi in range(self.order):
        for i in range(self.p_ndpo[ordi]):
          res.p_im[ordi][i] = (self.p_im[ordi][i])[item]
        # end 
      # end 

    except:
      # TODO: Add warning when this is not possible.
      pass
    # end try.

    return res

  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  def changeOrder(self, ord_t newOrder):
    """
    PURPOSE:  To get the value of an otinum coefficient.
    """
    #*************************************************************************************************
    # global dhl
    cdef ord_t ordi
    cdef imdir_t i
    if newOrder<self.order:

      self.p_im = self.p_im[:newOrder]
      self.p_ndpo = self.p_ndpo[:newOrder]

      self.ndir = np.sum(self.p_ndpo)
      

    elif newOrder>self.order:

      new_p_im = np.empty(newOrder,dtype=np.ndarray)
      new_p_ndpo =  np.zeros( newOrder, dtype=np.uint64)

      # copy info
      new_p_im[:self.order] = self.p_im[:]
      new_p_ndpo[:self.order] = self.p_ndpo[:]
      
      for ordi in range(self.order, newOrder):
      
        new_p_ndpo[ordi] = dhelp_extract_ndirOrder( self.nbases, ordi+1, dhl )
        
        new_p_im[ordi]   = np.zeros( new_p_ndpo[ordi], dtype = object)

        self.ndir += new_p_ndpo[ordi]
        
      # end for  


      self.p_im   = new_p_im
      self.p_ndpo = new_p_ndpo
      
    self.order = newOrder
  #--------------------------------------------------------------------------------------------------- 


  #***************************************************************************************************
  def getIm(self, list item):
    """
    PURPOSE:  To get the value of an otinum coefficient.
    """
    #*************************************************************************************************
    # global dhl

    cdef imdir_t idx = item[ZERO]
    cdef ord_t order = item[ONE]
    cdef object res = None
    
    if order == 0:
    
      res = self.re
    
    else:
    
      try:
        res = self.p_im[order-1][idx]
      except:
        pass
      # end try.
    # end if 

    return res

  #--------------------------------------------------------------------------------------------------- 

  #***************************************************************************************************
  def extract_im(self, list item):
    """
    PURPOSE:  Extract the OTI number contained below the given imaginary direction.
    """
    #*************************************************************************************************
    global dhl

    cdef imdir_t idx = item[ZERO]
    cdef ord_t order = item[ONE]
    cdef object res = None
    cdef ord_t ordi, ord_res
    cdef imdir_t i, i_res
    cdef coeff_t factor_res, factor_i

    if order == 0:
    
      res = self.copy()
    
    else:

      try:
        
        res = otibase(self.order-order, nbases=self.nbases, dtype=self.dtype, zero=0.0)

        # Set the real value
        res.re = self.p_im[order-1][idx]

        for ordi in range(res.order):
          for i in range(res.p_ndpo[ordi]):
            
            dhelp_multDir( i,  ordi+1, idx, order, &i_res, &ord_res, dhl)
            
            factor_i   = dhelp_get_deriv_factor(    i,  ordi+1, dhl);
            factor_res = dhelp_get_deriv_factor(i_res, ord_res, dhl);

            res.p_im[ordi][i] = self.p_im[ord_res-1][i_res]

          # end 
        # end 

      except:

        res = 0.0

      # end try.
    # end if 

    return res

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  def extract_deriv(self, list item):
    """
    PURPOSE:  Extract the OTI number contained below the given imaginary direction.
    """
    #*************************************************************************************************
    global dhl

    cdef imdir_t idx = item[ZERO]
    cdef ord_t order = item[ONE]
    cdef object res = None
    cdef ord_t ordi, ord_res
    cdef imdir_t i, i_res
    cdef int factor_res, factor_i

    if order == 0:
    
      res = self.copy()
    
    else:

      try:
        
        res = otibase(self.order-order, nbases=self.nbases, dtype=self.dtype, zero=0.0)

        # Set the real value
        factor_res = int( dhelp_get_deriv_factor(  idx,   order, dhl) );
        
        res.re = (factor_res)*self.p_im[order-1][idx]

        for ordi in range(res.order):

          for i in range(res.p_ndpo[ordi]):
            
            dhelp_multDir( i,  ordi+1, idx, order, &i_res, &ord_res, dhl)
            
            factor_i   = int( dhelp_get_deriv_factor(    i,  ordi+1, dhl) );
            factor_res = int( dhelp_get_deriv_factor(i_res, ord_res, dhl) );

            res.p_im[ordi][i] = (factor_res)*self.p_im[ord_res-1][i_res]/(factor_i)

          # end 
        
        # end 

      except:

        res = 0.0

      # end try.
    # end if 

    return res

  #---------------------------------------------------------------------------------------------------  

  #***************************************************************************************************
  def setIm(self, list item, object value):
    """
    PURPOSE:  To set the value of an otinum coefficient.
    """
    #*************************************************************************************************
    # global dhl

    cdef imdir_t idx = item[ZERO]
    cdef ord_t order = item[ONE]
    cdef ord_t ordi
    cdef imdir_t i
    
    
    if order == 0:
    
      self.re = value
    
    else:
    
      try:
        self.p_im[order-1][idx] = value
      except:
        # What happens if indexing error?
        pass
      # end try.
    # end if 

  #---------------------------------------------------------------------------------------------------  



  #***************************************************************************************************
  def __setitem__(self, item, value):
    """
    PURPOSE:  Propagate get item through all elements.
    """
    #*************************************************************************************************
    
    # get all items from other elements.

    cdef ndir_t i
    cdef ord_t ordi

    if type(value) == self.dtype:

      self.re[item] = value.re

      for ordi in range(self.order):
        for i in range(self.p_ndpo[ordi]):
          self.p_im[ordi][i] [item] = value.p_im[ordi][i]
        # end 
      # end 

    else:

      self.re[item] = value

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
    global dhl

    cdef otibase res = self.empty_like()
    cdef ord_t ordi
    cdef ndir_t i

    # propagate negation.

    res.re = -self.re

    for ordi in range(self.order):
      
      for i in range(self.p_ndpo[ordi]):
        
        res.p_im[ordi][i] = -self.p_im[ordi][i]
      
      # end 

    # end 

    return res
  #---------------------------------------------------------------------------------------------------




  #***************************************************************************************************
  def __add__(lhs, rhs):
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
      otibase res, tlhs, trhs
    cdef ord_t ordi
    cdef ndir_t i
      
    isoti_lhs = isinstance(lhs,otibase)     
    isoti_rhs = isinstance(rhs,otibase)     

    if ( isoti_lhs and isoti_rhs) : # Case Sum between two OTI-like elements.
      
      tlhs = lhs
      trhs = rhs

      res = lhs.empty_like()

      res.re = tlhs.re + trhs.re

      for ordi in range(res.order):
      
        for i in range(res.p_ndpo[ordi]):
          
          res.p_im[ordi][i] = tlhs.p_im[ordi][i] + trhs.p_im[ordi][i]

        # end 

      # end      
    
    elif (isoti_lhs): # OTI-like + scalar
      
      tlhs = lhs
      res = lhs.empty_like()
      res.re = tlhs.re + rhs

      
      for ordi in range(res.order):
      
        for i in range(res.p_ndpo[ordi]):
          
          try:
            res.p_im[ordi][i] = tlhs.p_im[ordi][i].copy()
          except:
            res.p_im[ordi][i] = tlhs.p_im[ordi][i]
        
        # end 

      # end

    elif (isoti_rhs): #  scalar + OTI-like
      
      trhs = rhs
      res = rhs.empty_like()
      res.re = lhs + trhs.re

      for ordi in range(res.order):
      
        for i in range(res.p_ndpo[ordi]):
          try:
            res.p_im[ordi][i] = trhs.p_im[ordi][i].copy()
          except:
            res.p_im[ordi][i] = trhs.p_im[ordi][i]
          # end 
        
        # end 

      # end

      
    else:

      return NotImplemented         

    # end if 
      
      
    return res

  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  def __iadd__(lhs, rhs):
    """
    PURPOSE:      To define how to sum two otinum numbers.

    DESCRIPTION:  It overloads the inplace sum operator "+=". It allows the 
                  addition of spr_otinum numbers of different orders, and 
                  the addition of a otinum number and a scalar. 
    """
    #*************************************************************************************************

    return lhs + rhs

  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  def __sub__(lhs, rhs):
    """
    PURPOSE:      To define how to subtract two otinum numbers.

    DESCRIPTION:  It overloads the subtract operator "-". It allows the 
                  subtraction of spr_otinum numbers of different orders, 
                  and the subtraction of a otinum number and a scalar. 
    """
  #************************************************************************
    
    
    global dhl
    cdef: 
      otibase res, tlhs, trhs
    cdef ord_t ordi
    cdef ndir_t i
      
    isoti_lhs = isinstance(lhs,otibase)     
    isoti_rhs = isinstance(rhs,otibase)     

    if ( isoti_lhs and isoti_rhs) : # Case Sum between two OTI-like elements.
      
      tlhs = lhs
      trhs = rhs

      res = lhs.empty_like()

      res.re = tlhs.re - trhs.re

      for ordi in range(res.order):
      
        for i in range(res.p_ndpo[ordi]):
          
          res.p_im[ordi][i] = tlhs.p_im[ordi][i] - trhs.p_im[ordi][i]

        # end 

      # end      
    
    elif (isoti_lhs): # OTI-like + scalar
      
      tlhs = lhs
      res = lhs.empty_like()
      res.re = tlhs.re + rhs

      
      for ordi in range(res.order):
      
        for i in range(res.p_ndpo[ordi]):
          
          try:
            res.p_im[ordi][i] = tlhs.p_im[ordi][i].copy()
          except:
            res.p_im[ordi][i] = tlhs.p_im[ordi][i]
        
        # end 

      # end

    elif (isoti_rhs): #  scalar + OTI-like
      
      trhs = rhs
      res = rhs.empty_like()
      res.re = lhs - trhs.re

      for ordi in range(res.order):
      
        for i in range(res.p_ndpo[ordi]):
          try:
            res.p_im[ordi][i] = -trhs.p_im[ordi][i].copy()
          except:
            res.p_im[ordi][i] = -trhs.p_im[ordi][i]
          # end 
        
        # end 

      # end

      
    else:

      return NotImplemented         

    # end if 
      
      
    return res

  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  def __isub__(lhs, rhs):
    """
    PURPOSE:      To define how to subtract two spr_otinum numbers.

    DESCRIPTION:  It overloads the inplace subtract operator "-=". It allows
                  the subtraction of spr_otinum numbers of different orders, 
                  and the subtraction of a spr_otinum number and a scalar. 
    

    """
    #*************************************************************************************************
  
    return lhs - rhs

  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  def __mul__(lhs, rhs):
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
      otibase res, tlhs, trhs, tmpi, tmpj
    cdef ord_t ordi, ordj,ord_res
    cdef ndir_t i,j
    cdef imdir2d_t tmp_multtabl
    cdef imdir_t i_res

    isoti_lhs = isinstance(lhs,otibase)     
    isoti_rhs = isinstance(rhs,otibase)     

    if ( isoti_lhs and isoti_rhs) : # Case Sum between two OTI-like elements.
      
      # not implemented
      tlhs = lhs
      trhs = rhs

      # Initialize as zero.
      res = otibase(tlhs.order, nbases = tlhs.nbases, zero = 0 )

      # real x real      
      res.re = tlhs.re * trhs.re

      # real x im and im x real
      for ordi in range(res.order):
      
        for i in range(res.p_ndpo[ordi]):
          
          res.p_im[ordi][i] = tlhs.p_im[ordi][i] * trhs.re + tlhs.re * trhs.p_im[ordi][i]

        # end 

      # end      

      for ordi in range( res.order ):
        
        for ordj in range(res.order-ordi-1):

          ord_res = ordi + ordj + 1
          
          if ordi < ordj:

            tmp_multtabl = dhl.p_dh[ord_res].p_multtabls[ordi];
            tmpi = tlhs
            ord_ti = ordi
            tmpj = trhs
            ord_tj = ordj

          else:

            tmp_multtabl = dhl.p_dh[ord_res].p_multtabls[ordj];
            tmpj = tlhs
            ord_tj = ordi
            tmpi = trhs
            ord_ti = ordj

          # end if 

          for i in range(tmpi.p_ndpo[ord_ti]):
            for j in range(tmpj.p_ndpo[ord_tj]):

              i_res = array2d_getel_ui64_t(tmp_multtabl.p_arr,tmp_multtabl.shape[1],i,j)
              res.p_im[ord_res][i_res] = res.p_im[ord_res][i_res]+tmpi.p_im[ord_ti][i]*tmpj.p_im[ord_tj][j]

            # end for
          # end for 

        # end 

      # end      

      
    
    elif (isoti_lhs): # OTI-like * scalar
      
      tlhs = lhs
      res = lhs.empty_like()
      res.re = tlhs.re * rhs

      
      for ordi in range(res.order):
      
        for i in range(res.p_ndpo[ordi]):
                    
          res.p_im[ordi][i] = tlhs.p_im[ordi][i]*rhs
                  
        # end 

      # end

    elif (isoti_rhs): #  scalar + OTI-like
      
      trhs = rhs
      res = rhs.empty_like()
      res.re = lhs * trhs.re

      for ordi in range(res.order):
      
        for i in range(res.p_ndpo[ordi]):
          
          res.p_im[ordi][i] = lhs*trhs.p_im[ordi][i]
        
        # end 

      # end

      
    else:

      return NotImplemented         

    # end if 
      
      
    return res

  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  def __imul__(lhs, rhs):
    """
    PURPOSE:      To define how to make an inplace multiplication between
                  two OTI numbers.
    
    DESCRIPTION:  It overloads the multiplication operator "*=". It allows
                  the multiplication of OTI numbers of different orders, 
                  or even the multiplication with scalars.

    """
    #*************************************************************************************************

    return lhs * rhs

  #---------------------------------------------------------------------------------------------------  


  # #***************************************************************************************************
  # def __truediv__(lhs, rhs):
  #   """
  #   PURPOSE:      To define how to divide two spr_otinum numbers.
    
  #   DESCRIPTION:  It overloads the division operator "/". It allows the
  #                 division of spr_otinum numbers of different orders, and 
  #                 the division of a spr_otinum number and a scalar. 

  #   """
  #   #*************************************************************************************************
    
  #   global dhl
  #   cdef: 
  #     otinum_t res
  #     otinum tmp1, tmp2
      
  #   type1 = type(self)     # takes 100 ns ... 
  #   type2 = type(other_in) # takes 100 ns ...

  #   # type1 = self.__class__     # takes ~50 ns ... 
  #   # type2 = other_in.__class__ # takes ~50 ns ...


  #   if ( type1 is type2) : # Case Sum between OTIs.
      
  #     tmp1 = self
  #     tmp2 = other_in
  #     res =  oti_div_oo(&tmp1.num, &tmp2.num, dhl);
    
  #   elif (type2 in number_types): # Case Sum to real number. Very slow, consider changing this...
      
  #     tmp1 = self
  #     res = oti_div_or( &tmp1.num, other_in, dhl);

  #   elif (type1 in number_types): # Case 1.5. reverse Sum to real number.
      
  #     tmp1 = other_in
  #     res = oti_div_ro( self, &tmp1.num, dhl);       

  #   else:

  #     return NotImplemented      

  #   # end if 

  #   return otinum.create(&res)

  # #---------------------------------------------------------------------------------------------------  


#   #***************************************************************************************************
#   def __pow__(self, n,z):
#     """
#     PURPOSE:      Power the number to exponent n.
#     """
#     #*************************************************************************************************

#     return power(self,n)

#   #---------------------------------------------------------------------------------------------------  


#   #***************************************************************************************************
#   cpdef copy(self):
#     """
#     PURPOSE:      To create a copy of a spr_otinum object, totally 
#                   independent of the original.

#     DESCRIPTION:  The equality operator "=" is intended to create aliases
#                   of multicomplex numbers. You should use copy() when you
#                   need a copy instead of an alias.
#     """
#     #*************************************************************************************************
#     global dhl
    
#     cdef otinum_t res = oti_copy(&self.num,dhl)

#     return otinum.create(&res)

#   #---------------------------------------------------------------------------------------------------  



# #   #***************************************************************************************************
# #   cpdef void changeOrder(self,uint8_t neworder):
# #     """
# #     PURPOSE:      To change the order of a spr_otinum.

# #     DESCRIPTION:  According to the new order, the index values are changed. 

# #     """
# #     #*************************************************************************************************
# #     global p_dH

# #     c_oti_changeOrder(&self.num, neworder, p_dH)


# #   #---------------------------------------------------------------------------------------------------  
  
#   #***************************************************************************************************
#   def __float__(self):
#     """
#     PORPUSE:      Overload of function float()
#     """
#     return self.num.re
#   #---------------------------------------------------------------------------------------------------  


#   #***************************************************************************************************
#   cpdef coeff_t get_deriv( self, hum_dir):
#     """
#     PURPOSE:      to retrieve the derivative contained in the oti number.

#     """
#     #*************************************************************************************************
#     global dhl
#     cdef list item = imdir(hum_dir)
#     cdef imdir_t indx = item[ZERO]
#     cdef ord_t  order = item[ONE]
    
#     return oti_get_deriv(indx,order,&self.num,dhl) 

#   #---------------------------------------------------------------------------------------------------  

#   #***************************************************************************************************
#   def get_all_deriv( self, int16_t order = -1, get_indices = False):
#     """
#     PURPOSE:    To retreive the derivatives contained in the oti number.

#     """
#     #*************************************************************************************************
#     global dhl

#     cdef uint64_t i, j, k
#     cdef ord_t ordi
#     cdef np.ndarray res



#     if order == -1:

#       # Get all derivatives of all orders.
#       res = np.empty((self.num.ndir+1,),dtype = np.float64)

#       j = 0
#       res[j] = self.num.re; j += 1
      
#       for ordi in range( self.num.order ):

#         for i in range( self.num.p_ndpo[ordi] ):

#           res [ j ] = oti_get_deriv( i, ordi+1, &self.num, dhl); j += 1

#         # end for 

#       # end for 

#     else:

#       if order <= self.num.order:
#         if order == 0:
          
#           res = np.empty((1,),dtype=np.float64)
#           res[0] = self.num.re

#         else:

#           res = np.empty((self.num.p_ndpo[order-1],),dtype=np.float64)

#           for i in range(self.num.p_ndpo[order-1]):

#             res[i] = oti_get_deriv(i,order,&self.num,dhl) 

#           # end for 

#         # end if 

#       # end if 

#     # end if 
    
#     return res

#   #---------------------------------------------------------------------------------------------------  

#   #***************************************************************************************************
#   def to_vector(self):
#     """
#     PURPOSE:      To convert an otinum into its vector form.
                    
#     """
#     #*************************************************************************************************
#     cdef np.ndarray res
#     cdef uint64_t i, j
#     cdef ord_t ordi

#     res = np.empty((self.num.ndir+1,),dtype = np.float64)

#     j = 0
#     res[j] = self.num.re; j += 1

#     if self.num.order > 0:

#       for ordi in range(self.num.order):
      
#         for i in range(self.num.p_ndpo[ordi]):
      
#           res[j] = self.num.p_im[ordi][i]; j+=1
      
#         # end for
      
#       # end for 

#     # end if 

#     return res

#   #---------------------------------------------------------------------------------------------------  


#   #***************************************************************************************************
#   def to_matrix(self,sparse_mat = False):
#     """
#     PURPOSE:      To convert an otinum into its matrix form.
                  
#     DESCRIPTION:  Convert to its own Cauchy-Riemann representation vector.
    
#     INPUTS:
#                   ismat: To define a matrix (1) or a vector (0)
#                   isshape: To use the shape that will result of the number 
#                     (-1) or an specific shape (given value).
#                   isspr: To result in a sparse matrix (1) or not (0).
#     """
#     #*************************************************************************************************

#     global dhl
    
#     cdef darr_t res

#     res = oti_to_cr_dense(&self.num,  dhl)

#     return dmat.create(&res)

#   #---------------------------------------------------------------------------------------------------  

  

# # ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# # :::::::::::::::::::::::::::::::::::: END OF CLASS OTINUM :::::::::::::::::::::::::::::::::::::::::::
# # ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::



























# #***************************************************************************************************
# cpdef otinum add(otinum lhs, otinum rhs):
#   """
#   PURPOSE:      Add two OTI numbers.
                
#   DESCRIPTION:  Eliminates the need to type check the input parameters 
  
#   INPUTS:
#                 lhs: otinum 
#                 rhs: otinum 
#                 out: otinum, optional. Result holder
                
#   """
#   #*************************************************************************************************
#   global dhl
#   cdef otinum_t res  
  
#   res = oti_sum_oo(&lhs.num, &rhs.num, dhl)

#   return otinum.create(&res)

# #---------------------------------------------------------------------------------------------------  


# #***************************************************************************************************
# cpdef add_to(otinum lhs, otinum rhs, otinum out):
#   """
#   PURPOSE:      Add two OTI numbers.
                
#   DESCRIPTION:  Faster version to add two oti numbers to something already allocated.
  
#   INPUTS:
#                 lhs: otinum 
#                 rhs: otinum 
#                 out: otinum, optional. Result holder
                
#   """
#   #*************************************************************************************************
#   global dhl

#   oti_sum_oo_to(&lhs.num, &rhs.num, &out.num ,dhl)


# #---------------------------------------------------------------------------------------------------  







# #***************************************************************************************************
# cpdef otinum mul(otinum lhs, otinum rhs):
#   """
#   PURPOSE:      Add two OTI numbers.
                
#   DESCRIPTION:  Faster version to add two oti numbers to something already allocated.
  
#   INPUTS:
#                 lhs: otinum 
#                 rhs: otinum 
                
                
#   """
#   #*************************************************************************************************
#   global dhl

#   cdef otinum_t res
  
#   res = oti_mul_oo(&lhs.num, &rhs.num,dhl)

#   return otinum.create(&res)

# #---------------------------------------------------------------------------------------------------  



# #***************************************************************************************************
# cpdef mul_to(otinum lhs, otinum rhs, otinum res):
#   """
#   PURPOSE:      Multiply two OTI numbers.
                
#   DESCRIPTION:  Faster version to multiply two oti numbers to something already allocated.
  
#   INPUTS:
#                 lhs: otinum 
#                 rhs: otinum 
#                 out: otinum. Result holder
                
#   """
#   #*************************************************************************************************
#   global dhl

  
  
#   oti_mul_oo_to(&lhs.num, &rhs.num, &res.num, dhl)


# #---------------------------------------------------------------------------------------------------  



# #***************************************************************************************************
# cpdef mulr_to(otinum lhs, coeff_t rhs, otinum res):
#   """
#   PURPOSE:      Multiply two OTI numbers.
                
#   DESCRIPTION:  Faster version to multiply two oti numbers to something already allocated.
  
#   INPUTS:
#                 lhs: otinum 
#                 rhs: otinum 
#                 out: otinum. Result holder
                
#   """
#   #*************************************************************************************************
#   global dhl

#   oti_mul_ro_to(rhs, &lhs.num,  &res.num, dhl)


# #---------------------------------------------------------------------------------------------------  




# #***************************************************************************************************
# cpdef otinum sub(otinum lhs, otinum rhs):
#   """
#   PURPOSE:      subtract two OTI numbers.
                
#   DESCRIPTION:  Eliminates the need to type check the input parameters 
  
#   INPUTS:
#                 lhs: otinum 
#                 rhs: otinum 
#                 out: otinum, optional. Result holder
                
#   """
#   #*************************************************************************************************
#   global dhl
#   cdef otinum_t res
#   # 
#   res = oti_sub_oo(&lhs.num, &rhs.num, dhl)

#   return otinum.create(&res)

# #---------------------------------------------------------------------------------------------------  


# #***************************************************************************************************
# cpdef sub_to(otinum lhs, otinum rhs, otinum out):
#   """
#   PURPOSE:      subtract two OTI numbers.
                
#   DESCRIPTION:  Faster version to operate two oti numbers to something already allocated.
  
#   INPUTS:
#                 lhs: otinum 
#                 rhs: otinum 
#                 out: otinum. Result holder
                
#   """
#   #*************************************************************************************************
#   global dhl

#   oti_sub_oo_to(&lhs.num, &rhs.num, &out.num ,dhl)


# #---------------------------------------------------------------------------------------------------  