# cdef uint64_t[::1] arr_nnz = np.zeros(150)

# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::     CLASS  SPR_OTINUM   :::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
cdef class onumm2n5_t:
  
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
    DESCRIPTION: Constructor of a sparse OTI number.
    """
    #*************************************************************************************************
    , ONE, ZERO
    

    # Add warning for higher orders and orders that are not required
    self.FLAGS = FLAGS
    cdef ndir_t* p_nnz # Static allocation of this array.
    cdef ord_t orderdef, i, size
    
    
    # First initialize the number.
    self.num = onumm2n5_init()

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
      
      self.num =  onumm2n5_createEmpty(p_nnz, orderdef)

      # Set real coefficient.
      self.num.re = re_coeff
    
    elif nbases != 0 and order !=0 :

      p_nnz = dhl.p_dh[order-ONE].p_nnz[ZERO]

      for i in range(order):
        p_nnz[i] = dhelp_extract_ndirOrder( nbases, i+1 )
      # end for 
      
      self.num =  onumm2n5_createEmpty(p_nnz, order)

      # Set real coefficient.
      self.num.re = re_coeff  

    else:
      
      self.num =  onumm2n5_createReal(re_coeff, order)
    
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

      onumm2n5_free(&self.num)

    #end if 
    
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

  # #***************************************************************************************************
  # @order.setter
  # def  order(self): 
  #   """
  #   PURPOSE:      Set the truncation order of the number.

  #   DESCRIPTION:  Reads the value in num.
                  
  #   """
  #   #*************************************************************************************************

  #   return self.num.order

  # #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  @property
  def  real(self): 
    """
    PURPOSE:      return the real coefficient of the OTI number.

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
  cdef onumm2n5_t create( onumm2n5_t* num, uint8_t FLAGS = 1 ):
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
    cdef onumm2n5_t otin = <onumm2n5_t> onumm2n5_t.__new__(onumm2n5_t)

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
  @staticmethod
  cdef onumm2n5_t init(  ):
    """
    PURPOSE:      Initialize memory for OTI num.

    DESCRIPTION:  Resets all pointer addresses to null, to avoid wrong memory reads.

    RESULT:       
            A new otinum python object.
                  
    """
    #*************************************************************************************************

    # create new empty object:
    cdef onumm2n5_t otin = <onumm2n5_t> onumm2n5_t.__new__(onumm2n5_t)

    otin.num        = onumm2n5_init()

    otin.FLAGS      = 1
    
    return otin

  #--------------------------------------------------------------------------------------------------- 

  #*************************************************************************************************** 
  def __repr__(self):
    """
    PURPOSE:  To print a representation of the onumm2n5_t object in a compact form.
    """
    #*************************************************************************************************
    
    global h

    
    cdef ord_t ordi, j
    cdef ndir_t i;
    cdef bases_t* dirs;

    head      = ''
    body      = ''
    
    body += '%.4f'%self.num.re

    for ordi in range(0,self.num.order):

      for i in range(self.num.p_nnz[ordi]):
        
        num = '%+.4f'%self.num.p_im[ordi][i] 
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
  def short_repr(self):
    """
    PURPOSE:  To print a representation of the onumm2n5_t object in a compact form.
    """
    #*************************************************************************************************
    global h
    global p_dH

    cdef ndir_t ndir_total = 1, i;

    for i in range(0, self.num.order):

      ndir_total += self.num.p_nnz[i]

    # end for

    head = 'onumm2n5_t('
    body = str(self.num.re) + ", nnz: " + str(ndir_total) + ', order: ' + str(self.num.order)
    tail = ')'

    return (head + body + tail)

  #---------------------------------------------------------------------------------------------------  

  #*************************************************************************************************** 
  def long_repr(self):
    """
    PURPOSE:  To print a representation of the onumm2n5_t object in a full detail form.
    """
    #*************************************************************************************************
    global h
    global p_dH

    cdef ndir_t ndir_total = 1, ndir_max = 1, i;

    for i in range(0, self.num.order):

      ndir_total += self.num.p_nnz[i]
      ndir_max   += self.num.p_size[i]

    # end for

    head = 'onumm2n5_t('
    body = str(self.num.re) + ", nnz: " + str(ndir_total)+", alloc: " + str(ndir_max) 
    body += ', order: ' + str(self.num.order) + ', flag: ' + str(self.num.flag) + "\n"

    for i in range(0, self.num.order):

      body += "Order {0}->   nnz: {1}  size: {2} \n".format(i+1, self.num.p_nnz[i],self.num.p_size[i])

    # end for 

    tail = ')'

    return (head + body + tail)

  #---------------------------------------------------------------------------------------------------  

  #***************************************************************************************************
  def __str__(self):
    """
    PURPOSE: To print a representation of the onumm2n5_t object that could 
             be easy to read and understand.  
    
    """
    #*************************************************************************************************
    
    
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
    PURPOSE:  To get the value of a onumm2n5_t coefficient.

    """
    #*************************************************************************************************
    

    cdef imdir_t idx = index[ZERO]
    cdef ord_t order = index[ONE]
    return onumm2n5_get_item( idx, order, &self.num)

  #---------------------------------------------------------------------------------------------------  

  #***************************************************************************************************
  def __setitem__(self, list item, coeff_t value):
    """
    PURPOSE:  To set the value of a onumm2n5_t coefficient.

    """
    #*************************************************************************************************
    
    

    cdef int i = 0, j = 1
    cdef imdir_t index = item[i]
    cdef ord_t   order = item[j]

    onumm2n5_set_item( value, index, order, &self.num)

  #---------------------------------------------------------------------------------------------------  

  #***************************************************************************************************
  def __neg__(self):
    """
    PURPOSE:      Negate a onumm2n5_t

    """
    #*************************************************************************************************
    
    

    cdef onumm2n5_t res = onumm2n5_neg(&self.num)

    return onumm2n5_t.create(&res)

  #---------------------------------------------------------------------------------------------------  

  #***************************************************************************************************
  def __add__(self, other_in):
    """
    PURPOSE:      Add onumm2n5_t with other things.

    """
    #*************************************************************************************************
    
    
    cdef: 
      onumm2n5_t res
      onumm2n5_t tmp1, tmp2
      
    type1 = type(self)     # takes 100 ns ... 
    type2 = type(other_in) # takes 100 ns ...

    # type1 = self.__class__     # takes ~50 ns ... 
    # type2 = other_in.__class__ # takes ~50 ns ...
    
    if ( type1 is type2) : # Case Sum between OTIs.
      tmp1 = self
      tmp2 = other_in
      res =  onumm2n5_sum_oo(&tmp1.num, &tmp2.num);
    
    elif (type2 in number_types): # Case Sum to real number. Very slow, consider changing this...
      
      tmp1 = self
      res = onumm2n5_sum_ro( other_in, &tmp1.num);

    elif (type1 in number_types): # Case 1.5. reverse Sum to real number.
      
      tmp1 = other_in
      res = onumm2n5_sum_ro( self, &tmp1.num);

    else:

      return NotImplemented

    # end if 
      
      
    return onumm2n5_t.create(&res)

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
    
    """
  #************************************************************************
    
    cdef: 
      onumm2n5_t res
      onumm2n5_t tmp1, tmp2
      
    type1 = type(self)     # takes 100 ns ... 
    type2 = type(other_in) # takes 100 ns ...

    # type1 = self.__class__     # takes ~50 ns ... 
    # type2 = other_in.__class__ # takes ~50 ns ...
    
    if ( type1 is type2) : # Case Sum between OTIs.
      tmp1 = self
      tmp2 = other_in
      res =  onumm2n5_sub_oo(&tmp1.num, &tmp2.num);
    
    elif (type2 in number_types): # Case Sum to real number. Very slow, consider changing this...
      
      tmp1 = self
      res = onumm2n5_sub_or(&tmp1.num, other_in);

    elif (type1 in number_types): # Case 1.5. reverse Sum to real number.
      
      tmp1 = other_in
      res = onumm2n5_sub_ro(self, &tmp1.num);   

    else:

      return NotImplemented

    # end if 
      
      
    return onumm2n5_t.create(&res)

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
    

    """
    #*************************************************************************************************
    
    
    cdef: 
      onumm2n5_t res
      onumm2n5_t tmp1, tmp2
      
    type1 = type(self)     # takes 100 ns ... 
    type2 = type(other_in) # takes 100 ns ...

    # type1 = self.__class__     # takes ~50 ns ... 
    # type2 = other_in.__class__ # takes ~50 ns ...

    if ( type1 is type2) : # Case Sum between OTIs.

      tmp1 = self
      tmp2 = other_in
      res = onumm2n5_mul_oo( &tmp1.num, &tmp2.num)
    
    elif (type2 in number_types): # Case Sum to real number. Very slow, consider changing this...
      
      tmp1 = self
      res = onumm2n5_mul_ro( other_in, &tmp1.num);

    elif (type1 in number_types): # Case 1.5. reverse Sum to real number.
      
      tmp1 = other_in
      res = onumm2n5_mul_ro( self, &tmp1.num);       

    else:

      return NotImplemented

    # end if 

    return onumm2n5_t.create(&res)

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
    PURPOSE:      To define how to divide two onumm2n5_t numbers.
    
    DESCRIPTION:  It overloads the division operator "/". It allows the
                  division of spr_otinum numbers of different orders, and 
                  the division of a spr_otinum number and a scalar. 
    """
    #*************************************************************************************************
    
    
    
    global p_dH

    cdef onumm2n5_t S
    cdef onumm2n5_t O
    cdef onumm2n5_t res = onumm2n5_init()

    type1 = type(self)     # takes 100 ns ... 
    type2 = type(other_in) # takes 100 ns ...

    if type1 == type2:  
      
      S = self
      O = other_in

      res = onumm2n5_div_oo(&S.num,&O.num)
      
    elif type2 in number_types:   # Case 1. Mult to real scalar. 
      
      S = self
      res = onumm2n5_div_or(&S.num,other_in)
    
    elif type1 in number_types:   # Case 1.5. Reverse Mult to real scalar.
      
      O = other_in
      res = onumm2n5_div_ro( self, &O.num)
      
    else:

      return NotImplemented

    # end if 

    return onumm2n5_t.create(&res)

  #---------------------------------------------------------------------------------------------------  

  #***************************************************************************************************
  def __pow__(self, n,z):
    """
    PURPOSE:      To provide power function of sparse oti numbers.
    """
    #*************************************************************************************************
    
    

    cdef onumm2n5_t res
    cdef onumm2n5_t S = self

    res = onumm2n5_pow(&S.num, n)
    
    return onumm2n5_t.create(&res)

  #---------------------------------------------------------------------------------------------------  

  #  =================================================================================================
  #  ------------------------------------   UTIL. FUNCTIONS  -----------------------------------------
  #  =================================================================================================

  #***************************************************************************************************
  cpdef set(self, object rhs):
    """
    PURPOSE:  Sets from another value.
    """
    #*************************************************************************************************
    

    cdef onumm2n5_t orhs
    cdef coeff_t rrhs
    trhs = type(rhs)

    if trhs is onumm2n5_t:

      orhs = rhs
      onumm2n5_set_o( &orhs.num, &self.num)

    else:
      rrhs = rhs
      onumm2n5_set_r( rrhs, &self.num)      

    # end if 

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  cpdef  set_im( self,  object val, object humdir):
    """
    PURPOSE:      to set a specific imaginary direction as given.

    """
    #*************************************************************************************************
    

    cdef imdir_t indx
    cdef ord_t  order
    cdef onumm2n5_t oval
    cdef coeff_t rval
    indx, order = imdir(humdir)
    tval = type(val)

    if tval is onumm2n5_t:
      
      oval = val
      onumm2n5_set_im_o( &oval.num, indx, order, &self.num) 

    else:

      rval = val
      onumm2n5_set_im_r( val, indx, order, &self.num) 

    # end if 

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  cpdef  set_deriv( self,  object val, object humdir):
    """
    PURPOSE:      to set a specific derivative as given.

    """
    #*************************************************************************************************
    

    cdef imdir_t indx
    cdef ord_t  order
    cdef onumm2n5_t oval
    cdef coeff_t rval
    indx, order = imdir(humdir)
    tval = type(val)

    if tval is onumm2n5_t:
      
      oval = val
      onumm2n5_set_deriv_o( &oval.num, indx, order, &self.num) 

    else:

      rval = val
      onumm2n5_set_deriv_r( val, indx, order, &self.num) 

    # end if 

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  cpdef  truncate( self, object humdir):
    """
    PURPOSE:      to set a specific imaginary direction as given.

    """
    #*************************************************************************************************
    

    cdef imdir_t indx
    cdef ord_t  order
    cdef onumm2n5_t res
    
    indx, order = imdir(humdir)
    
    res = onumm2n5_truncate_im( indx, order, &self.num) 

    return onumm2n5_t.create(&res)

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  cpdef get_deriv( self, object humdir):
    """
    PURPOSE:      to retrieve the derivative contained in the oti number.

    """
    #*************************************************************************************************
    

    cdef imdir_t indx
    cdef ord_t  order

    indx, order = imdir(humdir)
    return onumm2n5_get_deriv(indx,order, &self.num) 

  #--------------------------------------------------------------------------------------------------- 

  #***************************************************************************************************
  cpdef get_im( self, object humdir):
    """
    PURPOSE:      to retrieve the coefficient in the oti direction.

    """
    #*************************************************************************************************
    

    cdef imdir_t indx
    cdef ord_t  order

    indx, order = imdir(humdir)
    return onumm2n5_get_item(indx,order, &self.num) 

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  cpdef extract_im( self, object humdir):
    """
    PURPOSE:      to retrieve the coefficient in the oti direction.

    """
    #*************************************************************************************************
    

    cdef imdir_t indx
    cdef ord_t  order
    cdef onumm2n5_t res
    
    indx, order = imdir(humdir)

    res = onumm2n5_extract_im(indx,order, &self.num) 

    return onumm2n5_t.create(&res)

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  cpdef extract_deriv( self, object humdir):
    """
    PURPOSE:      Get the derivative as an OTI number.

    """
    #*************************************************************************************************
    

    cdef imdir_t indx
    cdef ord_t  order
    cdef onumm2n5_t res
    
    indx, order = imdir(humdir)

    res = onumm2n5_extract_deriv(indx,order, &self.num)

    return onumm2n5_t.create(&res)

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  cpdef get_order_im( self, ord_t order):
    """
    PURPOSE:      Get the derivative as an OTI number.

    """
    #*************************************************************************************************
    

    cdef onumm2n5_t res
    
    res = onumm2n5_get_order_im( order, &self.num)

    return onumm2n5_t.create(&res)

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  def copy(self):
    """
    PURPOSE:      To create a copy of the object.
    """
    #*************************************************************************************************
    

    cdef onumm2n5_t res = onumm2n5_copy( &self.num )
    return onumm2n5_t.create(&res)

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  def get_active_bases(self):
    """
    PURPOSE:      Get all the active bases.
    """
    #*************************************************************************************************
    

    cdef bases_t  size = dhl.p_dh[0].Nbasis
    cdef imdir_t* bases_list = dhl.p_dh[0].p_idx[0]
    cdef uint64_t i
    
    # Initialize all elements as zero (deactivated)
    for i in range(size):

      bases_list[i]=0

    # end for 

    onumm2n5_get_active_bases( &self.num, bases_list)

    res = []
    for i in range(size):

      if bases_list[i]==1:
      
        res.append(i+1)

      # end if 

    # end for 

    return res

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  def taylor_integrate(self, object bases, object deltas):
    """
    PURPOSE:     Perform a Taylor series integration.
    """
    #*************************************************************************************************
    

    cdef bases_t  size = dhl.p_dh[0].Nbasis
    cdef coeff_t* c_deltas = dhl.p_dh[0].p_im[0]
    cdef int64_t i
    cdef onumm2n5_t res
    
    # Initialize all elements as zero
    memset( c_deltas, 0, size*sizeof(coeff_t))

    try:
      
      bases_eval  = bases
      deltas_eval = deltas

      if len(bases_eval) != len(deltas_eval):
      
        raise ValueError("Both bases and deltas must have the same dimension")

      # end if 

    except:

      bases_eval = np.array(self.get_active_bases(),dtype=np.uint16)
      deltas_eval= np.ones(len(bases_eval),dtype=np.float64) * deltas

    # end

    for i in range(len(bases_eval)):

      c_deltas[ bases[i] - 1 ] = deltas[i]

    # end for 

    res = onumm2n5_taylor_integrate( c_deltas, &self.num)

    return onumm2n5_t.create(&res)

  #---------------------------------------------------------------------------------------------------

# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# :::::::::::::::::::::::::::::::::::: End of class onumm2n5_t ::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
