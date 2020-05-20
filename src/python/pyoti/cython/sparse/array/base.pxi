






# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::     CLASS  matso    ::::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
cdef class matso:
  #---------------------------------------------------------------------------------------------------
  #------------------------------------   DEFINITION OF ATTRIBUTES   ---------------------------------
  #---------------------------------------------------------------------------------------------------
  
  #                                --->      Look in dense.pxd    <---

  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  
  def __init__(self, realArray, ord_t order = 0, bases_t nbases = 0, object nnz = None): 
    """
    PURPOSE:      Python level constructor of the matso class.

    DESCRIPTION:  Creates a new matrix, reserving memory Assumes coefficient values to be all zeroes.
                 
    """
    #*************************************************************************************************
    global dhl
    
    cdef uint64_t nrows, ncols, i,j
    cdef ord_t ordi
    cdef coeff_t val 


    if isinstance( realArray, np.ndarray):
      
      ndim = realArray.ndim
      
      if ndim >=3:
      
        raise ValueError("Only 1D and 2D arrays are supported.")
      
      elif (ndim == 1):
      
        ncols = 1      
        nrows = realArray.shape[0]

        self.arr = arrso_zeros_bases( nrows, ncols, nbases, order, dhl)

        for i in range(self.arr.nrows):
      
          val = realArray[i]
          arrso_set_item_i_r( val, i, &self.arr, dhl)
        
        # end for
      
      else: # ndim =2

        nrows = realArray.shape[0]
        ncols = realArray.shape[1]
        self.arr = arrso_zeros_bases( nrows, ncols, nbases, order, dhl)

        for i in range(self.arr.nrows):      
          for j in range(self.arr.ncols):
            
            val = realArray[i,j]
            arrso_set_item_ij_r( val, i, j, &self.arr, dhl)
          
          # end for        
        # end for

      # end if

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  def __dealloc__(self): 
    """
    PURPOSE:      Destructor of the class.                   
    """
    #*************************************************************************************************
    
    arrso_free(&self.arr)
    
  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  @property
  def shape(self): 
    """
    PURPOSE:      Return the shape of the stored matrix. 
    """
    #*************************************************************************************************

    return (self.arr.nrows,self.arr.ncols)

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  @property
  def order(self): 
    """
    PURPOSE:      Return the shape of the stored matrix. 
    """
    #*************************************************************************************************

    return arrso_get_order(&self.arr)

  #---------------------------------------------------------------------------------------------------


  #***************************************************************************************************
  @property
  def  size(self): 
    """
    PURPOSE:      Return the size of array.                
    """
    #*************************************************************************************************

    return self.arr.size

  #---------------------------------------------------------------------------------------------------
  
  #***************************************************************************************************
  @property
  def real(self):
    """
    PURPOSE:      Get a numpy array with all coefficients in the real direction.

    """
    #*************************************************************************************************

    cdef np.ndarray[coeff_t, ndim=2] tmp
    cdef uint64_t i,j,k

    tmp = np.empty( self.shape , dtype = np.float64)

    for i in range(self.arr.nrows):
      for j in range(self.arr.ncols):
        k = j+i*self.arr.ncols
        tmp[i,j] = self.arr.p_data[k].re
      # end for 
    # end for 

    return tmp

  #---------------------------------------------------------------------------------------------------

  # #***************************************************************************************************
  # @property
  # def order(self):
  #   """
  #   PURPOSE:      Gets the truncation order the OTI array.

  #   """
  #   #*************************************************************************************************

  #   return tmp

  # #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  @staticmethod
  cdef matso create(arrso_t* arr):
    """
    PURPOSE:      C-level constructor of the class. Use this when creating objects within 
                  Cython
                  
    """
    #*************************************************************************************************

    # create new empty object:
    cdef matso mat = <matso> matso.__new__(matso)

    mat.arr = arr[0]
    
    return mat

  #--------------------------------------------------------------------------------------------------- 

  # #*************************************************************************************************** 
  # def get_real(self):

  #   cdef np.ndarray[coeff_t, ndim=2] tmp
  #   cdef uint64_t i,j,k

  #   tmp = np.empty( self.shape , dtype = np.float64)

  #   for i in range(self.arr.nrows):
  #     for j in range(self.arr.ncols):
  #       k = j+i*self.arr.ncols
  #       tmp[i,j] = self.arr.p_data[k].re
  #     # end for 
  #   # end for 

  #   return tmp
  # #--------------------------------------------------------------------------------------------------- 

  #*************************************************************************************************** 
  def short_repr(self):
    """
    PURPOSE:      A short representation of the object.
  
    """
    #*************************************************************************************************

    global dhl

    out =  "matso< "
    out += "shape: "+str(self.shape)+ ", "
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

    out =  "matso< "
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

    cdef uint64_t i,j 
    cdef sotinum tmp


    out =  "matso< "
    out += "shape: "+str(self.shape)+ ", \n"

    for j in range(self.arr.ncols):
      for i in range(self.arr.nrows):

        out += "({0:d},{1:d}) ".format(i,j)
        tmp = self[i,j]
        out += tmp.__str__()
        out += "\n"

      # end for 
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
    # out=""

    # out += "["
    # for i in range(self.arr.nrows):
    #   out += "["
    #   for j in range(self.arr.ncols):
    #     d_soti = arrso_get_item_ij(&self.arr, i, j, dhl)
    #     out+= (sotinum.create(&d_soti,FLAGS=0)).__str__()+", "
    #   # end for 
    #   out = out[:-2] + "],\n"
    # # end for 
    # out =out[:-2] + "]"
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

    # out += "["
    # for i in range(self.arr.nrows):
    #   out += "["
    #   for j in range(self.arr.ncols):
    #     d_soti = arrso_get_item_ij(&self.arr, i, j, dhl)
    #     out+= (sotinum.create(&d_soti,FLAGS=0)).__str__()+", "
    #   # end for 
    #   out = out[:-2] + "],\n"
    # # end for 
    # out =out[:-2] + "]"
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
      
      res = arrso_get_item_i( &self.arr, val, dhl)
    
    else:
      
      res = arrso_get_item_ij( &self.arr, val[0], val[1], dhl)

    # end if

    return sotinum.create(&res)

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

    if (isinstance(val, int)):
      
      if tval == sotinum:

        valt = value
        arrso_set_item_i_o( &valt.num, val, &self.arr, dhl)

      else:

        arrso_set_item_i_r( value, val, &self.arr, dhl)

      # end if 
    
    else:
      
      if tval == sotinum:
        
        valt = value
        arrso_set_item_ij_o( &valt.num, val[0], val[1], &self.arr, dhl)

      else:

        arrso_set_item_ij_r( value, val[0], val[1], &self.arr, dhl)

      # end if 

    # end if


  #---------------------------------------------------------------------------------------------------  


  #***************************************************************************************************
  def copy(self):
    """
    PURPOSE: Copy to a new object.
    """
    #*************************************************************************************************
    
    global dhl
    
    cdef arrso_t res = arrso_copy(&self.arr, dhl)

    return matso.create(&res)
  #---------------------------------------------------------------------------------------------------


  #***************************************************************************************************
  def __neg__(self):
    """
    PURPOSE: Negation overload.
    """
    #*************************************************************************************************
    
    global dhl
    
    cdef arrso_t res = arrso_neg(&self.arr, dhl)

    return matso.create(&res)
  #---------------------------------------------------------------------------------------------------




  #***************************************************************************************************
  def __add__(self, other):
    """
    PURPOSE: Addition overload.
    """
    #*************************************************************************************************
    
    global dhl
    
    cdef arrso_t res 
    cdef matso lhs,rhs
    cdef dmat dlhs,drhs
    cdef sotinum olhs,orhs
    
    tlhs = type(self)
    trhs = type(other)
    
    if (tlhs == trhs):

      lhs = self
      rhs = other

      res = arrso_sum_OO(&lhs.arr,&rhs.arr,dhl)

    elif ( tlhs  == sotinum ):

      olhs = self
      rhs = other

      res = arrso_sum_oO(&olhs.num,&rhs.arr, dhl)

    elif ( trhs  == sotinum ):

      lhs = self
      orhs = other

      res = arrso_sum_oO(&orhs.num,&lhs.arr, dhl)
    
    elif (tlhs in number_types):
      
      rhs = other
      res = arrso_sum_rO(self, &rhs.arr, dhl)

    elif (trhs in number_types):
        
      lhs = self
      res = arrso_sum_rO(other, &lhs.arr, dhl)

    elif ( tlhs  == dmat ):

      dlhs = self
      rhs = other

      res = arrso_sum_RO(&dlhs.arr,&rhs.arr, dhl)

    elif ( trhs  == dmat ):

      lhs = self
      drhs = other

      res = arrso_sum_RO(&drhs.arr,&lhs.arr, dhl)

    else:

      return NotImplemented

    # end if 
      
    return matso.create(&res)

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
    
    cdef arrso_t res 
    cdef matso lhs,rhs
    cdef dmat dlhs,drhs
    cdef sotinum olhs,orhs
    
    tlhs = type(self)
    trhs = type(other)
    
    if (tlhs == trhs):

      lhs = self
      rhs = other

      res = arrso_sub_OO(&lhs.arr,&rhs.arr,dhl)

    elif ( tlhs  == sotinum ):

      olhs = self
      rhs = other

      res = arrso_sub_oO(&olhs.num,&rhs.arr, dhl)

    elif ( trhs  == sotinum ):

      lhs = self
      orhs = other

      res = arrso_sub_Oo(&lhs.arr, &orhs.num, dhl)
    
    elif (tlhs in number_types):
      
      rhs = other
      res = arrso_sub_rO(self, &rhs.arr, dhl)

    elif (trhs in number_types):
        
      lhs = self
      res = arrso_sub_Or(&lhs.arr, other, dhl)

    elif ( tlhs  == dmat ):

      dlhs = self
      rhs = other

      res = arrso_sub_RO(&dlhs.arr,&rhs.arr, dhl)

    elif ( trhs  == dmat ):

      lhs = self
      drhs = other

      res = arrso_sub_OR(&lhs.arr, &drhs.arr, dhl)

    else:

      return NotImplemented      

    # end if 
      
    return matso.create(&res)

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
    
    cdef arrso_t res 
    cdef matso lhs,rhs
    cdef dmat dlhs,drhs
    cdef sotinum olhs,orhs
    
    tlhs = type(self)
    trhs = type(other)
    
    if (tlhs == trhs):

      lhs = self
      rhs = other

      res = arrso_mul_OO(&lhs.arr,&rhs.arr,dhl)

    elif ( tlhs  == sotinum ):

      olhs = self
      rhs = other

      res = arrso_mul_oO(&olhs.num,&rhs.arr, dhl)

    elif ( trhs  == sotinum ):

      lhs = self
      orhs = other

      res = arrso_mul_oO(&orhs.num,&lhs.arr, dhl)
    
    elif (tlhs in number_types):
      
      rhs = other
      res = arrso_mul_rO(self, &rhs.arr, dhl)

    elif (trhs in number_types):
        
      lhs = self
      res = arrso_mul_rO(other, &lhs.arr, dhl)

    elif ( tlhs  == dmat ):

      dlhs = self
      rhs = other

      res = arrso_mul_RO(&dlhs.arr,&rhs.arr, dhl)

    elif ( trhs  == dmat ):

      lhs = self
      drhs = other

      res = arrso_mul_RO(&drhs.arr,&lhs.arr, dhl)

    else:

      return NotImplemented      

    # end if 
      
    return matso.create(&res)

    

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
    
    cdef arrso_t res 
    cdef matso lhs,rhs
    cdef dmat dlhs,drhs
    cdef sotinum olhs,orhs
    
    tlhs = type(self)
    trhs = type(other)
    
    if (tlhs == trhs):

      lhs = self
      rhs = other

      res = arrso_div_OO(&lhs.arr,&rhs.arr,dhl)

    elif ( tlhs  == sotinum ):

      olhs = self
      rhs = other

      res = arrso_div_oO(&olhs.num,&rhs.arr, dhl)

    elif ( trhs  == sotinum ):

      lhs = self
      orhs = other

      res = arrso_div_Oo(&lhs.arr, &orhs.num, dhl)
    
    elif (tlhs in number_types):
      
      rhs = other
      res = arrso_div_rO(self, &rhs.arr, dhl)

    elif (trhs in number_types):
        
      lhs = self
      res = arrso_div_Or(&lhs.arr, other, dhl)

    elif ( tlhs  == dmat ):

      dlhs = self
      rhs = other

      res = arrso_div_RO(&dlhs.arr,&rhs.arr, dhl)

    elif ( trhs  == dmat ):

      lhs = self
      drhs = other

      res = arrso_div_OR(&lhs.arr, &drhs.arr, dhl)

    else:

      return NotImplemented      

    # end if 
      
    return matso.create(&res)

  #---------------------------------------------------------------------------------------------------  

  #***************************************************************************************************
  def __pow__(self, n,z):
    """
    PURPOSE:      Power function oversload
    """
    #*************************************************************************************************
    
    global dhl

    cdef arrso_t res 
    cdef matso S = self

    res = arrso_pow( &S.arr, n, dhl)
    
    return matso.create(&res)

  #---------------------------------------------------------------------------------------------------  

  #***************************************************************************************************
  def get_deriv(self, hum_dir ):
    """
    PURPOSE: Get the corresponding derivative of the system.
    """
    #*************************************************************************************************
    global dhl

    cdef list item = imdir(hum_dir)
    cdef np.ndarray[coeff_t, ndim=2] tmp
    cdef coeff_t factor = 1

    tmp = self.get_im(hum_dir)

    factor = dhelp_get_deriv_factor(item[ZERO], item[ONE], dhl)

    return tmp * factor

  #---------------------------------------------------------------------------------------------------  

  #***************************************************************************************************
  def get_im(self, hum_dir):
    """
    PURPOSE: Get the corresponding imaginary direction in the matso object.
    """
    #*************************************************************************************************
    global dhl
    
    cdef list item = imdir(hum_dir)
    cdef darr_t res_darr
    cdef dmat res_dmat
    cdef uint64_t i,j, k
    cdef np.ndarray[double, ndim=2] res

    res_darr = arrso_get_im( item[ZERO],  item[ONE], &self.arr,  dhl)

    res = np.empty( self.shape , dtype = np.float64)

    k=0

    for i in range(self.arr.nrows):

      for j in range(self.arr.ncols):

        res[i,j] = res_darr.p_data[k]
        k+=1

      # end for 

    #end for

    return res

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

    arrso_get_active_bases( &self.arr, bases_list, dhl)

    res = []
    for i in range(size):

      if bases_list[i]==1:
      
        res.append(i+1)

      # end if 

    # end for 

    return res

  #---------------------------------------------------------------------------------------------------
  


# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# :::::::::::::::::::::::::::::::::::: END OF CLASS matso ::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

