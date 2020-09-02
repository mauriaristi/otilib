# cdef uint64_t[::1] arr_nnz = np.zeros(150)

# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::     CLASS  SPR_OTINUM   :::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
cdef class onumm1n7:
  
  #---------------------------------------------------------------------------------------------------
  #------------------------------------   DEFINITION OF ATTRIBUTES   ---------------------------------
  #---------------------------------------------------------------------------------------------------
  #
  #                                     --< Look in "sparse.pxd" >--
  #
  #---------------------------------------------------------------------------------------------------  

  #***************************************************************************************************
  def __init__(self, coeff_t re_coeff):
    """
    DESCRIPTION: Constructor of a sparse OTI number.
    """
    #*************************************************************************************************
    
    # First initialize the number.
    self.num = onumm1n7_create_r(re_coeff)

  #---------------------------------------------------------------------------------------------------  

  #***************************************************************************************************
  @property
  def  order(self): 
    """
    PURPOSE:      return the maximum order of the number.

    DESCRIPTION:  Reads the value in num.
                  
    """
    #*************************************************************************************************

    return onumm1n7_get_order(&self.num)

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  @property
  def  real(self): 
    """
    PURPOSE:      return the real coefficient of the OTI number.

    DESCRIPTION:  Reads the value in num.
                  
    """
    #*************************************************************************************************

    return self.num.r

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  @real.setter
  def  real(self, value): 
    """
    PURPOSE:      Sets the real coefficient of an OTI number

    DESCRIPTION:  Sets the real coefficient in num.
                  
    """
    #*************************************************************************************************

    self.num.r = value

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  @staticmethod
  cdef onumm1n7 create( onumm1n7_t* num, uint8_t FLAGS = 1 ):
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
    cdef onumm1n7 otin = <onumm1n7> onumm1n7.__new__(onumm1n7)

    otin.num     = onumm1n7_copy(num)
    
    return otin

  #--------------------------------------------------------------------------------------------------- 

  #*************************************************************************************************** 
  def __repr__(self):
    """
    PURPOSE:  To print a representation of the onumm1n7 object in a compact form.
    """
    #*************************************************************************************************
    
    global h

    
    cdef ord_t ordi, j
    cdef ndir_t i, idx;

    head      = ''
    body      = ''
    
    body += '%.4f'%self.num.r

    for ordi in range(1,self.order+1):

      for i in range( onumm1n7_get_ndir_order(ordi,&self.num) ):
        
        idx = onumm1n7_get_indx(i, ordi) 
        num = '%+.4f'%( onumm1n7_get_item(idx,ordi,&self.num) )

        body += ' '+num[0]+" "+num[1:]
        body += ' * e(' 
        
        body += str(h.get_compact_fulldir(idx,ordi)).replace(' ','')
        body += ")"
      
      # end for

    # end for 
      
    tail = ''
    
    return (head + body + tail)

  #--------------------------------------------------------------------------------------------------- 

  #*************************************************************************************************** 
  def short_repr(self):
    """
    PURPOSE:  To print a representation of the onumm1n7 object in a compact form.
    """
    #*************************************************************************************************
    global h
    global p_dH

    cdef ndir_t ndir_total, i;

    head = 'onumm1n7('
    body = str(self.num.r) + ", nnz: " + str(onumm1n7_get_ndir_total(&self.num)) + ', order: ' + str(self.order)
    tail = ')'

    return (head + body + tail)

  #---------------------------------------------------------------------------------------------------  

  #***************************************************************************************************
  def __str__(self):
    """
    PURPOSE: To print a representation of the onumm1n7 object that could 
             be easy to read and understand.  
    
    """
    #*************************************************************************************************
    
    
    global h

    
    cdef ord_t ordi
    cdef ndir_t i, idx

    head      = ''
    body      = ''
    
    body += '%.4f'%self.num.r

    for ordi in range(1,self.order+1):

      for i in range( onumm1n7_get_ndir_order(ordi,&self.num) ):
        
        idx = onumm1n7_get_indx(i, ordi) 
        num = '%+.4f'%( onumm1n7_get_item(idx,ordi,&self.num) )

        body += ' '+num[0]+" "+num[1:]
        body += ' * e(' 
        
        body += str(h.get_compact_fulldir(idx,ordi)).replace(' ','')
        body += ")"
      
      # end for

    # end for 
      
    tail = ''
    
    return (head + body + tail)

  #---------------------------------------------------------------------------------------------------  

  #***************************************************************************************************
  def __getitem__(self, list index):
    """
    PURPOSE:  To get the value of a onumm1n7 coefficient.

    """
    #*************************************************************************************************
    

    cdef imdir_t idx = index[ZERO]
    cdef ord_t order = index[ONE]
    return onumm1n7_get_item( idx, order, &self.num)

  #---------------------------------------------------------------------------------------------------  

  #***************************************************************************************************
  def __setitem__(self, list item, coeff_t value):
    """
    PURPOSE:  To set the value of a onumm1n7 coefficient.

    """
    #*************************************************************************************************
    
    

    cdef int i = 0, j = 1
    cdef imdir_t index = item[i]
    cdef ord_t   order = item[j]

    onumm1n7_set_item( value, index, order, &self.num)

  #---------------------------------------------------------------------------------------------------  

  #***************************************************************************************************
  def __neg__(self):
    """
    PURPOSE:      Negate a onumm1n7

    """
    #*************************************************************************************************
    
    

    cdef onumm1n7_t res = onumm1n7_neg(&self.num)

    return onumm1n7.create(&res)

  #---------------------------------------------------------------------------------------------------  

  #***************************************************************************************************
  def __add__(self, other_in):
    """
    PURPOSE:      Add onumm1n7 with other things.

    """
    #*************************************************************************************************
    
    
    cdef: 
      onumm1n7_t res
      onumm1n7 tmp1, tmp2
      
    type1 = type(self)     # takes 100 ns ... 
    type2 = type(other_in) # takes 100 ns ...

    # type1 = self.__class__     # takes ~50 ns ... 
    # type2 = other_in.__class__ # takes ~50 ns ...
    
    if ( type1 is type2) : # Case Sum between OTIs.
      tmp1 = self
      tmp2 = other_in
      res =  onumm1n7_sum_oo(&tmp1.num, &tmp2.num);
    
    elif (type2 in number_types): # Case Sum to real number. Very slow, consider changing this...
      
      tmp1 = self
      res = onumm1n7_sum_ro( other_in, &tmp1.num);

    elif (type1 in number_types): # Case 1.5. reverse Sum to real number.
      
      tmp1 = other_in
      res = onumm1n7_sum_ro( self, &tmp1.num);

    else:

      return NotImplemented

    # end if 
      
      
    return onumm1n7.create(&res)

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
      onumm1n7_t res
      onumm1n7 tmp1, tmp2
      
    type1 = type(self)     # takes 100 ns ... 
    type2 = type(other_in) # takes 100 ns ...

    # type1 = self.__class__     # takes ~50 ns ... 
    # type2 = other_in.__class__ # takes ~50 ns ...
    
    if ( type1 is type2) : # Case Sum between OTIs.
      tmp1 = self
      tmp2 = other_in
      res =  onumm1n7_sub_oo(&tmp1.num, &tmp2.num);
    
    elif (type2 in number_types): # Case Sum to real number. Very slow, consider changing this...
      
      tmp1 = self
      res = onumm1n7_sub_or(&tmp1.num, other_in);

    elif (type1 in number_types): # Case 1.5. reverse Sum to real number.
      
      tmp1 = other_in
      res = onumm1n7_sub_ro(self, &tmp1.num);   

    else:

      return NotImplemented

    # end if 
      
      
    return onumm1n7.create(&res)

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
      onumm1n7_t res
      onumm1n7 tmp1, tmp2
      
    type1 = type(self)     # takes 100 ns ... 
    type2 = type(other_in) # takes 100 ns ...

    # type1 = self.__class__     # takes ~50 ns ... 
    # type2 = other_in.__class__ # takes ~50 ns ...

    if ( type1 is type2) : # Case Sum between OTIs.

      tmp1 = self
      tmp2 = other_in
      res = onumm1n7_mul_oo( &tmp1.num, &tmp2.num)
    
    elif (type2 in number_types): # Case Sum to real number. Very slow, consider changing this...
      
      tmp1 = self
      res = onumm1n7_mul_ro( other_in, &tmp1.num);

    elif (type1 in number_types): # Case 1.5. reverse Sum to real number.
      
      tmp1 = other_in
      res = onumm1n7_mul_ro( self, &tmp1.num);       

    else:

      return NotImplemented

    # end if 

    return onumm1n7.create(&res)

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
    PURPOSE:      To define how to divide two onumm1n7 numbers.
    
    DESCRIPTION:  It overloads the division operator "/". It allows the
                  division of spr_otinum numbers of different orders, and 
                  the division of a spr_otinum number and a scalar. 
    """
    #*************************************************************************************************
    
    
    
    global p_dH

    cdef onumm1n7 S
    cdef onumm1n7 O
    cdef onumm1n7_t res = onumm1n7_init()

    type1 = type(self)     # takes 100 ns ... 
    type2 = type(other_in) # takes 100 ns ...

    if type1 == type2:  
      
      S = self
      O = other_in

      res = onumm1n7_div_oo(&S.num,&O.num)
      
    elif type2 in number_types:   # Case 1. Mult to real scalar. 
      
      S = self
      res = onumm1n7_div_or(&S.num,other_in)
    
    elif type1 in number_types:   # Case 1.5. Reverse Mult to real scalar.
      
      O = other_in
      res = onumm1n7_div_ro( self, &O.num)
      
    else:

      return NotImplemented

    # end if 

    return onumm1n7.create(&res)

  #---------------------------------------------------------------------------------------------------  

  #***************************************************************************************************
  def __pow__(self, n,z):
    """
    PURPOSE:      To provide power function of sparse oti numbers.
    """
    #*************************************************************************************************
    
    

    cdef onumm1n7_t res
    cdef onumm1n7 S = self

    res = onumm1n7_pow(&S.num, n)
    
    return onumm1n7.create(&res)

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
    

    cdef onumm1n7 orhs
    cdef coeff_t rrhs
    trhs = type(rhs)

    if trhs is onumm1n7:

      orhs = rhs
      onumm1n7_set_o( &orhs.num, &self.num)

    else:
      rrhs = rhs
      onumm1n7_set_r( rrhs, &self.num)      

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
    cdef onumm1n7 oval
    cdef coeff_t rval
    indx, order = imdir(humdir)
    tval = type(val)

    if tval is onumm1n7:
      
      oval = val
      onumm1n7_set_im_o( &oval.num, indx, order, &self.num) 

    else:

      rval = val
      onumm1n7_set_im_r( val, indx, order, &self.num) 

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
    cdef onumm1n7 oval
    cdef coeff_t rval
    indx, order = imdir(humdir)
    tval = type(val)

    if tval is onumm1n7:
      
      oval = val
      onumm1n7_set_deriv_o( &oval.num, indx, order, &self.num) 

    else:

      rval = val
      onumm1n7_set_deriv_r( val, indx, order, &self.num) 

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
    cdef onumm1n7_t res
    
    indx, order = imdir(humdir)
    
    res = onumm1n7_truncate_im( indx, order, &self.num) 

    return onumm1n7.create(&res)

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
    return onumm1n7_get_deriv(indx,order, &self.num) 

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
    return onumm1n7_get_item(indx,order, &self.num) 

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  cpdef extract_im( self, object humdir):
    """
    PURPOSE:      to retrieve the coefficient in the oti direction.

    """
    #*************************************************************************************************
    

    cdef imdir_t indx
    cdef ord_t  order
    cdef onumm1n7_t res
    
    indx, order = imdir(humdir)

    res = onumm1n7_extract_im(indx,order, &self.num) 

    return onumm1n7.create(&res)

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  cpdef extract_deriv( self, object humdir):
    """
    PURPOSE:      Get the derivative as an OTI number.

    """
    #*************************************************************************************************
    

    cdef imdir_t indx
    cdef ord_t  order
    cdef onumm1n7_t res
    
    indx, order = imdir(humdir)

    res = onumm1n7_extract_deriv(indx,order, &self.num)

    return onumm1n7.create(&res)

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  cpdef get_order_im( self, ord_t order):
    """
    PURPOSE:      Get the derivative as an OTI number.

    """
    #*************************************************************************************************
    

    cdef onumm1n7_t res
    
    res = onumm1n7_get_order_im( order, &self.num)

    return onumm1n7.create(&res)

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  def copy(self):
    """
    PURPOSE:      To create a copy of the object.
    """
    #*************************************************************************************************
    

    cdef onumm1n7_t res = onumm1n7_copy( &self.num )
    return onumm1n7.create(&res)

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

    onumm1n7_get_active_bases( &self.num, bases_list)

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
    cdef onumm1n7_t res
    
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

    res = onumm1n7_taylor_integrate( c_deltas, &self.num)

    return onumm1n7.create(&res)

  #---------------------------------------------------------------------------------------------------

# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# :::::::::::::::::::::::::::::::::::: End of class onumm1n7 ::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
