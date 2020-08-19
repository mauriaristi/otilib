


# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::     CLASS  sotife    ::::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
cdef class sotife:
  #---------------------------------------------------------------------------------------------------
  #------------------------------------   DEFINITION OF ATTRIBUTES   ---------------------------------
  #---------------------------------------------------------------------------------------------------
  
  #                                --->      Look in dense.pxd    <---

  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  
  def __init__(self, real, uint64_t nip, ord_t order = 0, bases_t nbases = 0): 
    """
    PURPOSE:      Python level constructor of the sotife class.

    DESCRIPTION:  Creates a new matrix, reserving memory Assumes coefficient values to be all zeroes.
                 
    """
    #*************************************************************************************************
    global dhl
    
    cdef uint64_t i,j
    cdef ord_t ordi

    #
    self.num = fesoti_zeros_bases(nip, nbases, order, dhl)
    
    # Set all elements in the number as real.
    fesoti_set_r( real, &self.num, dhl)

    self.FLAGS = 1

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  def __dealloc__(self): 
    """
    PURPOSE:      Destructor of the class.                   
    """
    #*************************************************************************************************
    
    if( self.FLAGS == 1):

      fesoti_free(&self.num)

    # end if 
    
  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  @property
  def nip(self): 
    """
    PURPOSE:     Return the number of integration points. 
    """
    #*************************************************************************************************

    return self.num.nip

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  @property
  def order(self): 
    """
    PURPOSE:      Return the shape of the stored matrix. 
    """
    #*************************************************************************************************

    return fesoti_get_order(&self.num)

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  @property
  def real(self):
    """
    PURPOSE:      Get a numpy array with all coefficients in the real direction.

    """
    #*************************************************************************************************

    cdef np.ndarray[coeff_t, ndim=1] tmp
    cdef uint64_t i

    tmp = np.empty( self.nip , dtype = np.float64)

    for i in range(self.num.nip):

      tmp[i] = self.num.p_data[i].re

    # end for 

    return tmp

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  @staticmethod
  cdef sotife create(fesoti_t* num, uint8_t FLAGS = 1):
    """
    PURPOSE:      C-level constructor of the class. Use this when creating objects within 
                  Cython
                  
    """
    #*************************************************************************************************

    # create new empty object:
    cdef sotife res = <sotife> sotife.__new__(sotife)

    res.num = num[0]
    res.FLAGS = FLAGS

    return res

  #--------------------------------------------------------------------------------------------------- 

  #*************************************************************************************************** 
  def short_repr(self):
    """
    PURPOSE:      A short representation of the object.
  
    """
    #*************************************************************************************************

    global dhl

    out =  "sotife< "
    out += "nip: "+str(self.nip)+ ", "
    out += "re:\n"
    # first print the real part:
    out += repr( self.real )

    out += ">"

    return out

  #--------------------------------------------------------------------------------------------------- 

  #*************************************************************************************************** 
  def long_repr(self):
    """
    PURPOSE:      A short representation of the object.
  
    """
    #*************************************************************************************************

    global dhl

    cdef np.ndarray[uint64_t, ndim=1] tmp 

    out =  "sotife< "
    out += "shape: "+str(self.shape)+ ", "
    out += "re:\n"
    # first print the real part:
    out += repr( self.real )

    out += ">"

    return out

  #---------------------------------------------------------------------------------------------------

  #*************************************************************************************************** 
  def list_repr(self):
    """
    PURPOSE:      A short representation of the object.
  
    """
    #*************************************************************************************************

    global dhl

    cdef uint64_t i
    cdef sotinum tmp

    out =  "sotife< "
    out += "nip: "+str(self.nip)+ ", \n"

    for i in range(self.nip):
      
      out += "({0:d}) ".format(i)
      tmp = self[i]
      out += tmp.__str__()
      out += "\n"
      
    # end for 

    out += ">"

    return out

  #---------------------------------------------------------------------------------------------------

  #*************************************************************************************************** 
  def __repr__(self):
    """
    PURPOSE:      Representation of the object.
  
    """
    #*************************************************************************************************

    global dhl
  
    cdef sotinum_t d_soti
    cdef sotinum   soti

    out  = self.list_repr()

    return out

  #--------------------------------------------------------------------------------------------------- 
  

  #***************************************************************************************************
  def __str__(self):
    """
    PURPOSE:      Create a string representation of the object.    
    """
    #*************************************************************************************************
    global dhl
  
    cdef sotinum_t d_soti
    cdef sotinum   soti

    out  = self.list_repr()

    return out

  #---------------------------------------------------------------------------------------------------  



  #***************************************************************************************************
  def  __getitem__(self, val):
    """
    PURPOSE: Get the value of an element of the item.
    """
    #*************************************************************************************************
    
    global dhl

    cdef sotinum_t res

    if (isinstance(val, int)):
      
      res = fesoti_get_item_k( &self.num, val, dhl)
    
    else:
      
      return NotImplemented

    # end if

    return sotinum.create(&res, FLAGS=0)

  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  def __setitem__(self, val, value):
    """
    PURPOSE: Set an element of the item to the specified value.
    """
    #*************************************************************************************************
        
    global dhl

    cdef sotinum valt
    
    tval = type(value)

    if ( isinstance( val, int ) ):
      
      if tval == sotinum:

        valt = value
        fesoti_set_item_k_o( &valt.num, val, &self.num, dhl)

      else:

        fesoti_set_item_k_r(     value, val, &self.num, dhl)

      # end if 
    
    else:

      raise IndexError("Error: Index must be integer.")

    # end if


  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  def copy(self):
    """
    PURPOSE: Copy to a new object.
    """
    #*************************************************************************************************
    
    global dhl
    
    cdef fesoti_t res = fesoti_copy(&self.num, dhl)

    return sotife.create(&res)
  #---------------------------------------------------------------------------------------------------
  
  #***************************************************************************************************
  def __neg__(self):
    """
    PURPOSE: Negation overload.
    """
    #*************************************************************************************************
    
    global dhl
    
    cdef fesoti_t res = fesoti_neg(&self.num, dhl)

    return sotife.create(&res)
  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  def __add__(self, other):
    """
    PURPOSE: Addition overload.
    """
    #*************************************************************************************************
    
    global dhl
    
    cdef fesoti_t res 
    cdef sotife lhs,rhs
    cdef dmat dlhs,drhs
    cdef sotinum olhs,orhs
    
    tlhs = type(self)
    trhs = type(other)
    
    if (tlhs == trhs):

      lhs = self
      rhs = other

      res = fesoti_sum_ff(&lhs.num,&rhs.num,dhl)

    elif ( tlhs  == sotinum ):

      olhs = self
      rhs = other

      res = fesoti_sum_of(&olhs.num,&rhs.num, dhl)

    elif ( trhs  == sotinum ):

      lhs = self
      orhs = other

      res = fesoti_sum_of(&orhs.num,&lhs.num, dhl)
    
    elif (tlhs in number_types):
      
      rhs = other
      res = fesoti_sum_rf(self, &rhs.num, dhl)

    elif (trhs in number_types):
        
      lhs = self
      res = fesoti_sum_rf(other, &lhs.num, dhl)

    # elif ( tlhs  == matso ):

    #   dlhs = self
    #   rhs = other

    #   res = fesoti_sum_RO(&dlhs.num,&rhs.num, dhl)

    # elif ( trhs  == matso ):

    #   lhs = self
    #   drhs = other

    #   res = fesoti_sum_RO(&drhs.num,&lhs.num, dhl)

    # elif ( tlhs  == dmat ):

    #   dlhs = self
    #   rhs = other

    #   res = fesoti_sum_RO(&dlhs.num,&rhs.num, dhl)

    # elif ( trhs  == dmat ):

    #   lhs = self
    #   drhs = other

    #   res = fesoti_sum_RO(&drhs.num,&lhs.num, dhl)

    else:

      return NotImplemented

    # end if 
      
    return sotife.create(&res)

  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  def __iadd__(self, other):
    """
    PURPOSE: Inplace addition overload.
    """
    #*************************************************************************************************

    return self + other

  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  def __sub__(self, other):
    """
    PURPOSE: Subtraction overload.
    """
  #************************************************************************
    
    global dhl
    
    cdef fesoti_t res 
    cdef sotife   lhs, rhs
    cdef dmat    dlhs,drhs
    cdef sotinum olhs,orhs
    
    tlhs = type(self)
    trhs = type(other)
    
    if (tlhs == trhs):

      lhs = self
      rhs = other

      res = fesoti_sub_ff(&lhs.num,&rhs.num,dhl)

    elif ( tlhs  == sotinum ):

      olhs = self
      rhs = other

      res = fesoti_sub_of(&olhs.num,&rhs.num, dhl)

    elif ( trhs  == sotinum ):

      lhs = self
      orhs = other

      res = fesoti_sub_fo(&lhs.num, &orhs.num, dhl)
    
    elif (tlhs in number_types):
      
      rhs = other
      res = fesoti_sub_rf(self, &rhs.num, dhl)

    elif (trhs in number_types):
        
      lhs = self
      res = fesoti_sub_fr(&lhs.num, other, dhl)

    # elif ( tlhs  == dmat ):

    #   dlhs = self
    #   rhs = other

    #   res = fesoti_sub_RO(&dlhs.num,&rhs.num, dhl)

    # elif ( trhs  == dmat ):

    #   lhs = self
    #   drhs = other

    #   res = fesoti_sub_OR(&lhs.num, &drhs.num, dhl)

    else:

      return NotImplemented      

    # end if 
      
    return sotife.create(&res)

  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  def __isub__(self, other_in):
    """
    PURPOSE: Inplace subtraction overload.
    """
    #*************************************************************************************************
  
    return self - other_in

  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  def __mul__(self, other):
    """ 
    PURPOSE: Multiplication overload.
    """
    #*************************************************************************************************
    
    global dhl
    
    cdef fesoti_t res 
    cdef sotife lhs,rhs
    cdef dmat dlhs,drhs
    cdef sotinum olhs,orhs
    
    tlhs = type(self)
    trhs = type(other)
    
    if (tlhs == trhs):

      lhs = self
      rhs = other

      res = fesoti_mul_ff(&lhs.num,&rhs.num,dhl)

    elif ( tlhs  == sotinum ):

      olhs = self
      rhs = other

      res = fesoti_mul_of(&olhs.num,&rhs.num, dhl)

    elif ( trhs  == sotinum ):

      lhs = self
      orhs = other

      res = fesoti_mul_of(&orhs.num,&lhs.num, dhl)
    
    elif (tlhs in number_types):
      
      rhs = other
      res = fesoti_mul_rf(self, &rhs.num, dhl)

    elif (trhs in number_types):
        
      lhs = self
      res = fesoti_mul_rf(other, &lhs.num, dhl)

    # elif ( tlhs  == dmat ):

    #   dlhs = self
    #   rhs = other

    #   res = fesoti_mul_RO(&dlhs.num,&rhs.num, dhl)

    # elif ( trhs  == dmat ):

    #   lhs = self
    #   drhs = other

    #   res = fesoti_mul_RO(&drhs.num,&lhs.num, dhl)

    else:

      return NotImplemented      

    # end if 
      
    return sotife.create(&res)

  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  def __imul__(self, other_in):
    """
    PURPOSE: Inplace multiplication overload.
    """
    #*************************************************************************************************

    return self * other_in

  #---------------------------------------------------------------------------------------------------  

  #***************************************************************************************************
  def __truediv__(self, other):
    """
    PURPOSE: Division overload.
    """
    #*************************************************************************************************
    
    global dhl
    
    cdef fesoti_t res 
    cdef sotife lhs,rhs
    cdef dmat dlhs,drhs
    cdef sotinum olhs,orhs
    
    tlhs = type(self)
    trhs = type(other)
    
    if (tlhs == trhs):

      lhs = self
      rhs = other

      res = fesoti_div_ff(&lhs.num,&rhs.num,dhl)

    elif ( tlhs  == sotinum ):

      olhs = self
      rhs = other

      res = fesoti_div_of(&olhs.num,&rhs.num, dhl)

    elif ( trhs  == sotinum ):

      lhs = self
      orhs = other

      res = fesoti_div_fo(&lhs.num, &orhs.num, dhl)
    
    elif (tlhs in number_types):
      
      rhs = other
      res = fesoti_div_rf(self, &rhs.num, dhl)

    elif (trhs in number_types):
        
      lhs = self
      res = fesoti_div_fr(&lhs.num, other, dhl)

    # elif ( tlhs  == dmat ):

    #   dlhs = self
    #   rhs = other

    #   res = fesoti_div_RO(&dlhs.num,&rhs.num, dhl)

    # elif ( trhs  == dmat ):

    #   lhs = self
    #   drhs = other

    #   res = fesoti_div_OR(&lhs.num, &drhs.num, dhl)

    else:

      return NotImplemented

    # end if 
      
    return sotife.create(&res)

  #---------------------------------------------------------------------------------------------------  

  #***************************************************************************************************
  def __pow__(self, n,z):
    """
    PURPOSE:      Power function overload

    res = self ** n

    """
    #*************************************************************************************************
    
    global dhl

    cdef fesoti_t res 
    cdef sotife S = self

    res = fesoti_pow( &S.num, n, dhl)
    
    return sotife.create(&res)

  #---------------------------------------------------------------------------------------------------  

  #***************************************************************************************************
  cpdef set(self, object rhs):
    """
    PURPOSE:  Sets from another value.
    """
    #*************************************************************************************************
    global dhl

    cdef sotife  frhs
    cdef sotinum orhs
    cdef coeff_t rrhs
    trhs = type(rhs)

    if   trhs is sotinum:

      orhs = rhs
      fesoti_set_o( &orhs.num, &self.num, dhl)

    elif trhs is sotife:

      frhs = rhs
      fesoti_set_f( &frhs.num, &self.num, dhl)      

    else:

      rrhs = rhs
      fesoti_set_r( rrhs, &self.num, dhl)      

    # end if 

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  def gauss_integrate(self, sotife w  ):
    """
    PURPOSE: Get the corresponding derivative of the system.
    """
    #*************************************************************************************************
    global dhl

    cdef sotinum_t res = soti_init()

    res = fesoti_integrate( &self.num, &w.num, dhl)

    return sotinum.create(&res)

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  cpdef  truncate( self, object humdir):
    """
    PURPOSE:      to set a specific imaginary direction as given.

    """
    #*************************************************************************************************
    global dhl

    cdef imdir_t indx
    cdef ord_t  order
    cdef fesoti_t res
    
    indx, order = imdir(humdir)
    
    res = fesoti_truncate_im( indx, order, &self.num, dhl) 

    return sotife.create(&res)

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  cpdef  extract_deriv( self, object humdir):
    """
    PURPOSE:      to set a specific imaginary direction as given.

    """
    #*************************************************************************************************
    global dhl

    cdef imdir_t indx
    cdef ord_t  order
    cdef fesoti_t res
    
    indx, order = imdir(humdir)
    
    res = fesoti_extract_deriv( indx, order, &self.num, dhl) 

    return sotife.create(&res)

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  cpdef  extract_im( self, object humdir):
    """
    PURPOSE:      to set a specific imaginary direction as given.

    """
    #*************************************************************************************************
    global dhl

    cdef imdir_t indx
    cdef ord_t  order
    cdef fesoti_t res
    
    indx, order = imdir(humdir)
    
    res = fesoti_extract_im( indx, order, &self.num, dhl) 

    return sotife.create(&res)

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  cpdef  get_im( self, object humdir):
    """
    PURPOSE:      to set a specific imaginary direction as given.

    """
    #*************************************************************************************************
    global dhl

    cdef imdir_t indx
    cdef ord_t  order
    cdef fesoti_t res
    
    indx, order = imdir(humdir)
    
    res = fesoti_get_im( indx, order, &self.num, dhl) 

    return sotife.create(&res)

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  cpdef  get_deriv( self, object humdir):
    """
    PURPOSE:      to set a specific imaginary direction as given.

    """
    #*************************************************************************************************
    global dhl

    cdef imdir_t indx
    cdef ord_t  order
    cdef fesoti_t res
    
    indx, order = imdir(humdir)
    
    res = fesoti_get_deriv( indx, order, &self.num, dhl) 

    return sotife.create(&res)

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  cpdef  get_order_im( self, ord_t order):
    """
    PURPOSE:      to set a specific imaginary direction as given.

    """
    #*************************************************************************************************
    global dhl

    cdef fesoti_t res
    
    res = fesoti_get_order_im( order, &self.num, dhl) 

    return sotife.create(&res)

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  def get_active_bases(self):
    """

    """
    global dhl

    cdef bases_t  size       = dhl.p_dh[0].Nbasis
    cdef imdir_t* bases_list = dhl.p_dh[0].p_idx[0]
    cdef uint64_t i
    
    # Initialize all elements as zero (deactivated)
    for i in range(size):

      bases_list[i]=0

    # end for 

    fesoti_get_active_bases( &self.num, bases_list, dhl)

    res = []
    for i in range(size):

      if bases_list[i]==1:
      
        res.append(i+1)

      # end if 

    # end for 

    return res

  #---------------------------------------------------------------------------------------------------
  


# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# :::::::::::::::::::::::::::::::::::: END OF CLASS sotife ::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
















