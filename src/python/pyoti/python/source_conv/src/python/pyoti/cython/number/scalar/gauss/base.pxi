

# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::     CLASS  {fenum_pytype}    ::::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
cdef class {fenum_pytype}:
  #---------------------------------------------------------------------------------------------------
  #------------------------------------   DEFINITION OF ATTRIBUTES   ---------------------------------
  #---------------------------------------------------------------------------------------------------
  
  #                                --->      Look in dense.pxd    <---

  #---------------------------------------------------------------------------------------------------  

  #***************************************************************************************************
  
  def __init__(self, real, uint64_t nip): 
    """
    PURPOSE:      Python level constructor of the {fenum_pytype} class.

    DESCRIPTION:  Creates a new matrix, reserving memory Assumes coefficient values to be all zeroes.
                 
    """
    #*************************************************************************************************
    
    
    cdef uint64_t i,j
    cdef ord_t ordi

    #
    self.num = {fenum_func}_zeros(nip)
    
    # Set all elements in the number as real.
    {fenum_func}_set_r( real, &self.num)

    self.FLAGS = 1

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  def __dealloc__(self): 
    """
    PURPOSE:      Destructor of the class.                   
    """
    #*************************************************************************************************
    
    if( self.FLAGS == 1):

      {fenum_func}_free(&self.num)

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

    return {fenum_func}_get_order(&self.num)

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
  cdef {fenum_pytype} create({fenum_type}* num, uint8_t FLAGS = 1):
    """
    PURPOSE:      C-level constructor of the class. Use this when creating objects within 
                  Cython
                  
    """
    #*************************************************************************************************

    # create new empty object:
    cdef {fenum_pytype} res = <{fenum_pytype}> {fenum_pytype}.__new__({fenum_pytype})

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

    

    out =  "{fenum_pytype}< "
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

    

    cdef np.ndarray[uint64_t, ndim=1] tmp 

    out =  "{fenum_pytype}< "
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

    

    cdef uint64_t i
    cdef {num_pytype} tmp

    out =  "{fenum_pytype}< "
    out += "nip: "+str(self.nip)+ ", \n"

    for i in range(self.nip):
      
      out += "({{0:d}}) ".format(i)
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

    
  
    cdef {num_type} d_{num_func}
    cdef {num_pytype}   {num_func}

    out  = self.list_repr()

    return out

  #--------------------------------------------------------------------------------------------------- 
  

  #***************************************************************************************************
  def __str__(self):
    """
    PURPOSE:      Create a string representation of the object.    
    """
    #*************************************************************************************************
    
  
    cdef {num_type} d_{num_func}
    cdef {num_pytype}   {num_func}

    out  = self.list_repr()

    return out

  #---------------------------------------------------------------------------------------------------  

  #***************************************************************************************************
  def  __getitem__(self, val):
    """
    PURPOSE: Get the value of an element of the item.
    """
    #*************************************************************************************************
    
    

    cdef {num_type} res

    if (isinstance(val, int)):
      
      res = {fenum_func}_get_item_k( &self.num, val)
    
    else:
      
      return NotImplemented

    # end if

    return {num_pytype}.create(&res, FLAGS=0)

  #---------------------------------------------------------------------------------------------------  

  #***************************************************************************************************
  def __setitem__(self, val, value):
    """
    PURPOSE: Set an element of the item to the specified value.
    """
    #*************************************************************************************************
        
    

    cdef {num_pytype} valt
    
    tval = type(value)

    if ( isinstance( val, int ) ):
      
      if tval == {num_pytype}:

        valt = value
        {fenum_func}_set_item_k_o( &valt.num, val, &self.num)

      else:

        {fenum_func}_set_item_k_r(     value, val, &self.num)

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
    
    
    
    cdef {fenum_type} res = {fenum_func}_copy(&self.num)

    return {fenum_pytype}.create(&res)
  #---------------------------------------------------------------------------------------------------
  
  #***************************************************************************************************
  def __neg__(self):
    """
    PURPOSE: Negation overload.
    """
    #*************************************************************************************************
    
    
    
    cdef {fenum_type} res = {fenum_func}_neg(&self.num)

    return {fenum_pytype}.create(&res)
  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  def __add__(self, other):
    """
    PURPOSE: Addition overload.
    """
    #*************************************************************************************************
    
    
    
    cdef {fenum_type} res 
    cdef {fenum_pytype} lhs,rhs
    cdef dmat dlhs,drhs
    cdef {num_pytype} olhs,orhs
    
    tlhs = type(self)
    trhs = type(other)
    
    if (tlhs == trhs):

      lhs = self
      rhs = other

      res = {fenum_func}_sum_ff(&lhs.num,&rhs.num)

    elif ( tlhs  == {num_pytype} ):

      olhs = self
      rhs = other

      res = {fenum_func}_sum_of(&olhs.num,&rhs.num)

    elif ( trhs  == {num_pytype} ):

      lhs = self
      orhs = other

      res = {fenum_func}_sum_of(&orhs.num,&lhs.num)
    
    elif (tlhs in number_types):
      
      rhs = other
      res = {fenum_func}_sum_rf(self, &rhs.num)

    elif (trhs in number_types):
        
      lhs = self
      res = {fenum_func}_sum_rf(other, &lhs.num)

    # elif ( tlhs  == {arr_pytype} ):

    #   dlhs = self
    #   rhs = other

    #   res = {fenum_func}_sum_RO(&dlhs.num,&rhs.num)

    # elif ( trhs  == {arr_pytype} ):

    #   lhs = self
    #   drhs = other

    #   res = {fenum_func}_sum_RO(&drhs.num,&lhs.num)

    # elif ( tlhs  == dmat ):

    #   dlhs = self
    #   rhs = other

    #   res = {fenum_func}_sum_RO(&dlhs.num,&rhs.num)

    # elif ( trhs  == dmat ):

    #   lhs = self
    #   drhs = other

    #   res = {fenum_func}_sum_RO(&drhs.num,&lhs.num)

    else:

      return NotImplemented

    # end if 
      
    return {fenum_pytype}.create(&res)

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
    
    
    
    cdef {fenum_type} res 
    cdef {fenum_pytype}   lhs, rhs
    cdef dmat    dlhs,drhs
    cdef {num_pytype} olhs,orhs
    
    tlhs = type(self)
    trhs = type(other)
    
    if (tlhs == trhs):

      lhs = self
      rhs = other

      res = {fenum_func}_sub_ff(&lhs.num,&rhs.num)

    elif ( tlhs  == {num_pytype} ):

      olhs = self
      rhs = other

      res = {fenum_func}_sub_of(&olhs.num,&rhs.num)

    elif ( trhs  == {num_pytype} ):

      lhs = self
      orhs = other

      res = {fenum_func}_sub_fo(&lhs.num, &orhs.num)
    
    elif (tlhs in number_types):
      
      rhs = other
      res = {fenum_func}_sub_rf(self, &rhs.num)

    elif (trhs in number_types):
        
      lhs = self
      res = {fenum_func}_sub_fr(&lhs.num, other)

    # elif ( tlhs  == dmat ):

    #   dlhs = self
    #   rhs = other

    #   res = {fenum_func}_sub_RO(&dlhs.num,&rhs.num)

    # elif ( trhs  == dmat ):

    #   lhs = self
    #   drhs = other

    #   res = {fenum_func}_sub_OR(&lhs.num, &drhs.num)

    else:

      return NotImplemented      

    # end if 
      
    return {fenum_pytype}.create(&res)

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
    
    
    
    cdef {fenum_type} res 
    cdef {fenum_pytype} lhs,rhs
    cdef dmat dlhs,drhs
    cdef {num_pytype} olhs,orhs
    
    tlhs = type(self)
    trhs = type(other)
    
    if (tlhs == trhs):

      lhs = self
      rhs = other

      res = {fenum_func}_mul_ff(&lhs.num,&rhs.num)

    elif ( tlhs  == {num_pytype} ):

      olhs = self
      rhs = other

      res = {fenum_func}_mul_of(&olhs.num,&rhs.num)

    elif ( trhs  == {num_pytype} ):

      lhs = self
      orhs = other

      res = {fenum_func}_mul_of(&orhs.num,&lhs.num)
    
    elif (tlhs in number_types):
      
      rhs = other
      res = {fenum_func}_mul_rf(self, &rhs.num)

    elif (trhs in number_types):
        
      lhs = self
      res = {fenum_func}_mul_rf(other, &lhs.num)

    # elif ( tlhs  == dmat ):

    #   dlhs = self
    #   rhs = other

    #   res = {fenum_func}_mul_RO(&dlhs.num,&rhs.num)

    # elif ( trhs  == dmat ):

    #   lhs = self
    #   drhs = other

    #   res = {fenum_func}_mul_RO(&drhs.num,&lhs.num)

    else:

      return NotImplemented      

    # end if 
      
    return {fenum_pytype}.create(&res)

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
    
    
    
    cdef {fenum_type} res 
    cdef {fenum_pytype} lhs,rhs
    cdef dmat dlhs,drhs
    cdef {num_pytype} olhs,orhs
    
    tlhs = type(self)
    trhs = type(other)
    
    if (tlhs == trhs):

      lhs = self
      rhs = other

      res = {fenum_func}_div_ff(&lhs.num,&rhs.num)

    elif ( tlhs  == {num_pytype} ):

      olhs = self
      rhs = other

      res = {fenum_func}_div_of(&olhs.num,&rhs.num)

    elif ( trhs  == {num_pytype} ):

      lhs = self
      orhs = other

      res = {fenum_func}_div_fo(&lhs.num, &orhs.num)
    
    elif (tlhs in number_types):
      
      rhs = other
      res = {fenum_func}_div_rf(self, &rhs.num)

    elif (trhs in number_types):
        
      lhs = self
      res = {fenum_func}_div_fr(&lhs.num, other)

    # elif ( tlhs  == dmat ):

    #   dlhs = self
    #   rhs = other

    #   res = {fenum_func}_div_RO(&dlhs.num,&rhs.num)

    # elif ( trhs  == dmat ):

    #   lhs = self
    #   drhs = other

    #   res = {fenum_func}_div_OR(&lhs.num, &drhs.num)

    else:

      return NotImplemented

    # end if 
      
    return {fenum_pytype}.create(&res)

  #---------------------------------------------------------------------------------------------------  

  #***************************************************************************************************
  def __pow__(self, n,z):
    """
    PURPOSE:      Power function overload

    res = self ** n

    """
    #*************************************************************************************************
    
    

    cdef {fenum_type} res 
    cdef {fenum_pytype} S = self

    res = {fenum_func}_pow( &S.num, n)
    
    return {fenum_pytype}.create(&res)

  #---------------------------------------------------------------------------------------------------  

  #***************************************************************************************************
  cpdef set(self, object rhs):
    """
    PURPOSE:  Sets from another value.
    """
    #*************************************************************************************************
    

    cdef {fenum_pytype}  frhs
    cdef {num_pytype} orhs
    cdef coeff_t rrhs
    trhs = type(rhs)

    if   trhs is {num_pytype}:

      orhs = rhs
      {fenum_func}_set_o( &orhs.num, &self.num)

    elif trhs is {fenum_pytype}:

      frhs = rhs
      {fenum_func}_set_f( &frhs.num, &self.num)      

    else:

      rrhs = rhs
      {fenum_func}_set_r( rrhs, &self.num)      

    # end if 

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  def gauss_integrate(self, {fenum_pytype} w  ):
    """
    PURPOSE: Get the corresponding derivative of the system.
    """
    #*************************************************************************************************
    

    cdef {num_type} res = {num_func}_init()

    res = {fenum_func}_integrate( &self.num, &w.num)

    return {num_pytype}.create(&res)

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  cpdef  truncate( self, object humdir):
    """
    PURPOSE:      to set a specific imaginary direction as given.

    """
    #*************************************************************************************************
    

    cdef imdir_t indx
    cdef ord_t  order
    cdef {fenum_type} res
    
    indx, order = imdir(humdir)
    
    res = {fenum_func}_truncate_im( indx, order, &self.num) 

    return {fenum_pytype}.create(&res)

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  cpdef  extract_deriv( self, object humdir):
    """
    PURPOSE:      to set a specific imaginary direction as given.

    """
    #*************************************************************************************************
    

    cdef imdir_t indx
    cdef ord_t  order
    cdef {fenum_type} res
    
    indx, order = imdir(humdir)
    
    res = {fenum_func}_extract_deriv( indx, order, &self.num) 

    return {fenum_pytype}.create(&res)

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  cpdef  extract_im( self, object humdir):
    """
    PURPOSE:      to set a specific imaginary direction as given.

    """
    #*************************************************************************************************
    

    cdef imdir_t indx
    cdef ord_t  order
    cdef {fenum_type} res
    
    indx, order = imdir(humdir)
    
    res = {fenum_func}_extract_im( indx, order, &self.num) 

    return {fenum_pytype}.create(&res)

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  cpdef  get_im( self, object humdir):
    """
    PURPOSE:      to set a specific imaginary direction as given.

    """
    #*************************************************************************************************
    

    cdef imdir_t indx
    cdef ord_t  order
    cdef {fenum_type} res
    
    indx, order = imdir(humdir)
    
    res = {fenum_func}_get_im( indx, order, &self.num) 

    return {fenum_pytype}.create(&res)

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  cpdef  get_deriv( self, object humdir):
    """
    PURPOSE:      to set a specific imaginary direction as given.

    """
    #*************************************************************************************************
    

    cdef imdir_t indx
    cdef ord_t  order
    cdef {fenum_type} res
    
    indx, order = imdir(humdir)
    
    res = {fenum_func}_get_deriv( indx, order, &self.num) 

    return {fenum_pytype}.create(&res)

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  cpdef  get_order_im( self, ord_t order):
    """
    PURPOSE:      to set a specific imaginary direction as given.

    """
    #*************************************************************************************************
    

    cdef {fenum_type} res
    
    res = {fenum_func}_get_order_im( order, &self.num) 

    return {fenum_pytype}.create(&res)

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  def get_active_bases(self):
    """

    """
    

    cdef bases_t  size       = dhl.p_dh[0].Nbasis
    cdef imdir_t* bases_list = dhl.p_dh[0].p_idx[0]
    cdef uint64_t i
    
    # Initialize all elements as zero (deactivated)
    for i in range(size):

      bases_list[i]=0

    # end for 

    {fenum_func}_get_active_bases( &self.num, bases_list)

    res = []
    for i in range(size):

      if bases_list[i]==1:
      
        res.append(i+1)

      # end if 

    # end for 

    return res

  #---------------------------------------------------------------------------------------------------
  

# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# :::::::::::::::::::::::::::::::::::: END OF CLASS {fenum_pytype} ::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

