






# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# :::::::::::::::::::::::::::::     CLASS  matso    ::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
cdef class matso:
  #-----------------------------------------------------------------------------
  #------------------------   DEFINITION OF ATTRIBUTES   -----------------------
  #-----------------------------------------------------------------------------
  
  #                  --->      Look in include/sparse.pxd    <---

  # matso is a sequence now (len, iter, getitem): tell NumPy to defer to the operators of this class
  # (np.float64(2) * A must reach matso.__rmul__, not become an object ndarray).
  __array_ufunc__ = None

  #-----------------------------------------------------------------------------


  #*****************************************************************************
  
  def __init__(self, realArray, ord_t order = 0, bases_t nbases = 0, object nnz = None): 
    """
    PURPOSE:      Python level constructor of the matso class.

    DESCRIPTION:  Creates a new matrix, reserving memory Assumes coefficient values to be all zeroes.
                 
    """
    #***************************************************************************
    global dhl
    
    cdef uint64_t nrows, ncols, i,j
    cdef ord_t ordi
    cdef coeff_t val 


    if isinstance( realArray, np.ndarray):
      
      ndim = realArray.ndim
      
      if ( ndim >= 3 ):

        raise ValueError("pyoti.sparse arrays have at most 2 dimensions")

      elif ( ndim == 0 ):

        self.arr = arrso_zeros_bases( 1, 1, nbases, order, dhl)
        val = realArray.item()
        arrso_set_item_ij_r( val, 0, 0, &self.arr, dhl)
        self._lk = 2

      elif ( ndim == 1 ):

        ncols = 1
        nrows = realArray.shape[0]
        self._lk = 1


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
    # end if 
    
    self.FLAGS = 1

  #-----------------------------------------------------------------------------

  #*****************************************************************************
  def __dealloc__(self): 
    """
    PURPOSE:      Destructor of the class.                   
    """
    #***************************************************************************
    
    if self.FLAGS != 0:
      
      arrso_free(&self.arr)

    # end if 
    
  #-----------------------------------------------------------------------------

  #*****************************************************************************
  @property
  def T(self): 
    """
    PURPOSE:      Return the transpose of the stored matrix. 
    """
    #***************************************************************************
    global dhl
    
    cdef arrso_t res

    if self._lk != 0:

      # The transpose of a 1-D or 0-D array is the array itself (as NumPy): a copy here.
      return self.copy()

    # end if

    res = arrso_transpose( &self.arr,  dhl)

    return matso.create(&res)


  #-----------------------------------------------------------------------------

  #*****************************************************************************
  def reshape(self, *shape, order = 'C'):
    """
    PURPOSE:      A copy with another shape of at most 2 dimensions (reshape(3, 4), reshape((3, 4)),
                  reshape(-1)); one extent may be -1. Only order='C' (the row-major order of NumPy).
    """
    #***************************************************************************

    cdef matso res
    cdef tuple dims

    if order != 'C':

      raise ValueError("reshape: only order='C' is supported")

    # end if

    dims = reshape_shape(shape, self.arr.size, "pyoti.sparse")
    res = self.copy()

    # The elements stay in row-major order: only the header and the logical kind change.
    if len(dims) == 2:

      res.arr.nrows = dims[0]
      res.arr.ncols = dims[1]
      res._lk = 0

    elif len(dims) == 1:

      res.arr.nrows = dims[0]
      res.arr.ncols = 1
      res._lk = 1

    else:

      res.arr.nrows = 1
      res.arr.ncols = 1
      res._lk = 2

    # end if

    return res

  #-----------------------------------------------------------------------------

  #*****************************************************************************
  @property
  def shape(self): 
    """
    PURPOSE:      Return the shape of the stored matrix. 
    """
    #***************************************************************************

    if self._lk == 0:

      return (self.arr.nrows,self.arr.ncols)

    elif self._lk == 1:

      return (self.arr.nrows,)

    # end if

    return ()

  #-----------------------------------------------------------------------------

  #*****************************************************************************
  @property
  def ndim(self):
    """
    PURPOSE:      Return the number of dimensions of the logical shape (0, 1 or 2).
    """
    #***************************************************************************

    return 2 - self._lk

  #-----------------------------------------------------------------------------

  #*****************************************************************************
  @property
  def nrows(self):
    """
    PURPOSE:      Number of rows of the stored 2-D struct (deprecated: use shape; 1-D: n, 0-D: 1).
    """
    #***************************************************************************

    warnings.warn("nrows is deprecated, use shape", DeprecationWarning, stacklevel=2)

    return self.arr.nrows

  #-----------------------------------------------------------------------------

  #*****************************************************************************
  @property
  def ncols(self):
    """
    PURPOSE:      Number of columns of the stored 2-D struct (deprecated: use shape; 1-D, 0-D: 1).
    """
    #***************************************************************************

    warnings.warn("ncols is deprecated, use shape", DeprecationWarning, stacklevel=2)

    return self.arr.ncols

  #-----------------------------------------------------------------------------

  #*****************************************************************************
  def __len__(self):
    """
    PURPOSE:      Length of the first axis; a 0-D array has none.
    """
    #***************************************************************************

    if self._lk == 2:

      raise TypeError("len() of a 0-d matso")

    # end if

    return self.arr.nrows

  #-----------------------------------------------------------------------------

  #*****************************************************************************
  def __iter__(self):
    """
    PURPOSE:      Iterate over the first axis: rows with one axis fewer (OTI scalars for a 1-D array).
    """
    #***************************************************************************

    if self._lk == 2:

      raise TypeError("iteration over a 0-d matso")

    # end if

    return _matso_iter(self)


  #-----------------------------------------------------------------------------

  #*****************************************************************************
  @property
  def order(self): 
    """
    PURPOSE:      Return the shape of the stored matrix. 
    """
    #***************************************************************************

    return arrso_get_order(&self.arr)

  #-----------------------------------------------------------------------------


  #*****************************************************************************
  @property
  def  size(self): 
    """
    PURPOSE:      Return the size of array.                
    """
    #***************************************************************************

    return self.arr.size

  #-----------------------------------------------------------------------------
  
  #*****************************************************************************
  @property
  def real(self):
    """
    PURPOSE:      Get a numpy array with all coefficients in the real direction: a READ-ONLY COPY of
                  the array's logical shape (writes would not reach the matso; use get_real or copy()).

    """
    #***************************************************************************

    cdef np.ndarray[coeff_t, ndim=2] tmp
    cdef uint64_t i,j,k

    tmp = np.empty( (self.arr.nrows, self.arr.ncols) , dtype = np.float64)

    for i in range(self.arr.nrows):
      for j in range(self.arr.ncols):
        k = j+i*self.arr.ncols
        tmp[i,j] = self.arr.p_data[k].re
      # end for
    # end for

    out = tmp.reshape(self.shape)
    out.flags.writeable = False

    return out


  #-----------------------------------------------------------------------------

  #*****************************************************************************
  @staticmethod
  cdef matso create(arrso_t* arr, uint8_t FLAGS = 1):
    """
    PURPOSE:      C-level constructor of the class. Use this when creating objects within 
                  Cython
                  
    """
    #***************************************************************************

    # create new empty object:
    cdef matso mat = <matso> matso.__new__(matso)

    mat.arr = arr[0]
    mat.FLAGS = FLAGS
    
    return mat

  #-----------------------------------------------------------------------------

  #*****************************************************************************
  def short_repr(self):
    """
    PURPOSE:      A short representation of the object.
  
    """
    #***************************************************************************

    global dhl

    out =  "matso< "
    out += "shape: "+str(self.shape)+ ", "
    out += "re:\n"
    # first print the real part:
    out += repr( self.real )

    out += ">"

    return out

  #-----------------------------------------------------------------------------

  #*****************************************************************************
  def long_repr(self):
    """
    PURPOSE:      A short representation of the object.
  
    """
    #***************************************************************************

    global dhl

    cdef np.ndarray[uint64_t, ndim=1] tmp 

    out =  "matso< "
    out += "shape: "+str(self.shape)+ ", "
    out += "re:\n"
    # first print the real part:
    out += repr( self.real )

    out += ">"

    return out

  #-----------------------------------------------------------------------------

  #*****************************************************************************
  def list_repr(self):
    """
    PURPOSE:      A short representation of the object.
  
    """
    #***************************************************************************

    global dhl

    cdef uint64_t i,j 
    cdef sotinum tmp
    cdef sotinum_t el


    out =  "matso< "
    out += "shape: "+str(self.shape)+ ", \n"

    for j in range(self.arr.ncols):
      out += " - Column " + str(j) +"\n"
      for i in range(self.arr.nrows):

        out += "({0:d},{1:d}) ".format(i,j)
        el = arrso_get_item_ij( &self.arr, i, j, dhl)
         
        out += sotinum.create(&el, FLAGS = 0).__str__()
        out += "\n"

      # end for 
    # end for 

    out += ">"

    return out

  #-----------------------------------------------------------------------------

  #*****************************************************************************
  def __repr__(self):
    """
    PURPOSE:      Representation of the object.
  
    """
    #***************************************************************************

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

  #-----------------------------------------------------------------------------
  

  #*****************************************************************************
  def __str__(self):
    """
    PURPOSE:      Create a string representation of the object.    
    """
    #***************************************************************************
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

  #-----------------------------------------------------------------------------



  #*****************************************************************************
  def  __getitem__(self, val):
    """
    PURPOSE: NumPy basic indexing on the logical shape (ndim <= 2): an integer drops its axis, a
             slice keeps it, one ellipsis expands, negative indices count from the end. One integer
             per axis gives an OTI scalar; anything else gives a COPY (matso slices are copies).
    """
    #***************************************************************************

    global dhl

    cdef sotinum_t ores
    cdef arrso_t   Ores
    cdef matso     res
    cdef int64_t i, j
    cdef tuple r
    cdef object shape

    if (self._lk == 0 and type(val) is tuple and len(val) == 2 and type(val[0]) is int
        and type(val[1]) is int):

      # The fast path of element access (assembly loops).
      try:

        i = val[0]
        j = val[1]

      except OverflowError:

        raise IndexError("index {} is out of bounds for an array of shape {}".format(
                         val, self.shape)) from None

      # end try

      if i < 0:

        i += self.arr.nrows

      # end if

      if j < 0:

        j += self.arr.ncols

      # end if

      if i < 0 or i >= <int64_t>self.arr.nrows or j < 0 or j >= <int64_t>self.arr.ncols:

        raise IndexError("index ({}, {}) is out of bounds for an array of shape {}".format(
                         val[0], val[1], self.shape))

      # end if

      ores = arrso_get_item_ij( &self.arr, i, j, dhl)

      return sotinum.create(&ores, FLAGS = 0).copy()  # Create copy of data.

    # end if

    r = key2d(val, 2 - self._lk, self.arr.nrows, self.arr.ncols, "pyoti.sparse")
    shape = r[6]

    if shape is None:

      ores = arrso_get_item_ij( &self.arr, <int64_t>r[0], <int64_t>r[3], dhl)

      return sotinum.create(&ores, FLAGS = 0).copy()

    # end if

    Ores = arrso_get_slice( &self.arr, r[0], r[1], r[2], r[3], r[4], r[5], dhl)

    if len(shape) == 1 and Ores.nrows == 1 and Ores.ncols != 1:

      # A 1-D result of a row key is stored as a column: same elements in row-major order.
      Ores.nrows, Ores.ncols = Ores.ncols, Ores.nrows

    # end if

    res = matso.create(&Ores)
    res._lk = 2 - len(shape)

    return res

  #-----------------------------------------------------------------------------


  #*****************************************************************************
  def __setitem__(self, val, value):
    """
    PURPOSE: A[key] = value with NumPy's assignment rule (S1): the value (a real, an OTI scalar, a
             matso, a dmat or an array_like) is broadcast to the shape of A[key]: trailing axes
             aligned, extent 1 stretched, extra leading axes of extent 1 dropped. The right side is
             read as if copied first (S2: a[::-1] = a works).
    """
    #***************************************************************************

    global dhl

    cdef sotinum_t ores
    cdef sotinum   oval
    cdef matso     Oval
    cdef arrso_t   hdr
    cdef tuple r
    cdef object shape, tshape
    cdef int64_t nr, nc, i, j, plan
    cdef int64_t r0, r1, rt, c0, c1, ct

    tvalue = type(value)
    r = key2d(val, 2 - self._lk, self.arr.nrows, self.arr.ncols, "pyoti.sparse")
    shape = r[6]
    r0, r1, rt, c0, c1, ct = r[0], r[1], r[2], r[3], r[4], r[5]

    if tvalue in number_types:

      if shape is None:

        arrso_set_item_ij_r( value, r0, c0, &self.arr, dhl)

      else:

        arrso_set_slice_r( value, r0, r1, rt, c0, c1, ct, &self.arr, dhl)

      # end if

      return

    # end if

    if tvalue is sotinum:

      oval = value

      if shape is None:

        arrso_set_item_ij_o( &oval.num, r0, c0, &self.arr, dhl)

      else:

        arrso_set_slice_o( &oval.num, r0, r1, rt, c0, c1, ct, &self.arr, dhl)

      # end if

      return

    # end if

    if tvalue is not matso:

      Oval = _as_matso(value)

    else:

      Oval = value

      if Oval is self:

        # S2: the right side is read as if it were copied first.
        Oval = self.copy()

      # end if

    # end if

    nr = len(range(r0, r1, rt))
    nc = len(range(c0, c1, ct))
    tshape = () if shape is None else shape
    plan = assign_plan(Oval.shape, tshape)

    hdr = Oval.arr

    if plan == 1:

      ores = arrso_get_item_i( &Oval.arr, 0, dhl)

      if shape is None:

        arrso_set_item_ij_o( &ores, r0, c0, &self.arr, dhl)

      else:

        arrso_set_slice_o( &ores, r0, r1, rt, c0, c1, ct, &self.arr, dhl)

      # end if

    elif plan == 0:

      # Same shape: the same elements in row-major order, seen as the block of the 2-D struct.
      hdr.nrows = nr
      hdr.ncols = nc
      arrso_set_slice_O( &hdr, r0, r1, rt, c0, c1, ct, &self.arr, dhl)

    elif plan == 2:

      # A row (b,) or (1, b) repeated over the a rows of the block.
      hdr.nrows = 1
      hdr.ncols = nc

      for i in range(nr):

        arrso_set_slice_O( &hdr, r0 + i*rt, r0 + i*rt + 1, 1, c0, c1, ct, &self.arr, dhl)

      # end for

    else:

      # A column (a, 1) repeated over the b columns of the block.
      hdr.nrows = nr
      hdr.ncols = 1

      for j in range(nc):

        arrso_set_slice_O( &hdr, r0, r1, rt, c0 + j*ct, c0 + j*ct + 1, 1, &self.arr, dhl)

      # end for

    # end if

  #---------------------------------------------------------------------------------------------------

  #*****************************************************************************
  def copy(self):
    """
    PURPOSE: Copy to a new object.
    """
    #***************************************************************************
    
    global dhl
    
    cdef arrso_t res = arrso_copy(&self.arr, dhl)

    return _sk(matso.create(&res), self._lk)
  #-----------------------------------------------------------------------------


  #*****************************************************************************
  def __neg__(self):
    """
    PURPOSE: Negation overload.
    """
    #***************************************************************************
    
    global dhl
    
    cdef arrso_t res = arrso_neg(&self.arr, dhl)

    return _sk(matso.create(&res), self._lk)
  #-----------------------------------------------------------------------------

  #*****************************************************************************
  def __abs__(self):
    """
    PURPOSE: Absolute value (an element with a negative real part is negated), same as the function abs.
    """
    #***************************************************************************

    global dhl

    cdef arrso_t res = arrso_abs(&self.arr, dhl)

    return _sk(matso.create(&res), self._lk)
  #-----------------------------------------------------------------------------

  #*****************************************************************************
  def __add__(self, other):
    """
    PURPOSE: Addition overload.
    """
    #***************************************************************************
    
    global dhl
    
    cdef arrso_t res 
    cdef matso lhs,rhs
    cdef dmat dlhs,drhs
    cdef sotinum olhs,orhs
    
    tlhs = type(self)
    trhs = type(other)

    _check_elementwise("addition", self, other, None, True)

    if _shapes_differ(self, other):

      return _matso_mixed(_op.add, self, other)

    # end if
    
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
      dlhs._sync()
      rhs = other

      res = arrso_sum_RO(&dlhs.arr,&rhs.arr, dhl)

    elif ( trhs  == dmat ):

      lhs = self
      drhs = other
      drhs._sync()

      res = arrso_sum_RO(&drhs.arr,&lhs.arr, dhl)

    else:

      return NotImplemented

    # end if 
      
    return _sk(matso.create(&res), _op_kind(self, other))

  #-----------------------------------------------------------------------------


  #*****************************************************************************
  def __iadd__(self, other):
    """
    PURPOSE: Inplace addition overload.
    """
    #***************************************************************************

    return self + other

  #-----------------------------------------------------------------------------


  #*****************************************************************************
  def __sub__(self, other):
    """
    PURPOSE: Subtraction overload.
    """
    #***************************************************************************
    
    global dhl
    
    cdef arrso_t res 
    cdef matso lhs,rhs
    cdef dmat dlhs,drhs
    cdef sotinum olhs,orhs
    
    tlhs = type(self)
    trhs = type(other)

    _check_elementwise("subtraction", self, other, None, True)

    if _shapes_differ(self, other):

      return _matso_mixed(_op.sub, self, other)

    # end if
    
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
      dlhs._sync()
      rhs = other

      res = arrso_sub_RO(&dlhs.arr,&rhs.arr, dhl)

    elif ( trhs  == dmat ):

      lhs = self
      drhs = other
      drhs._sync()

      res = arrso_sub_OR(&lhs.arr, &drhs.arr, dhl)

    else:

      return NotImplemented      

    # end if 
      
    return _sk(matso.create(&res), _op_kind(self, other))

  #-----------------------------------------------------------------------------


  #*****************************************************************************
  def __isub__(self, other_in):
    """
    PURPOSE: Inplace subtraction overload.
    """
    #***************************************************************************
  
    return self - other_in

  #-----------------------------------------------------------------------------


  #*****************************************************************************
  def __mul__(self, other):
    """ 
    PURPOSE: Multiplication overload.
    """
    #***************************************************************************
    
    global dhl
    
    cdef arrso_t res 
    cdef matso lhs,rhs
    cdef dmat dlhs,drhs
    cdef sotinum olhs,orhs
    
    tlhs = type(self)
    trhs = type(other)

    _check_elementwise("multiplication", self, other, None, True)

    if _shapes_differ(self, other):

      return _matso_mixed(_op.mul, self, other)

    # end if
    
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
      dlhs._sync()
      rhs = other

      res = arrso_mul_RO(&dlhs.arr,&rhs.arr, dhl)

    elif ( trhs  == dmat ):

      lhs = self
      drhs = other
      drhs._sync()

      res = arrso_mul_RO(&drhs.arr,&lhs.arr, dhl)

    else:

      return NotImplemented      

    # end if 
      
    return _sk(matso.create(&res), _op_kind(self, other))

    

  #-----------------------------------------------------------------------------


  #*****************************************************************************
  def __imul__(self, other_in):
    """
    PURPOSE: Inplace multiplication overload.
    """
    #***************************************************************************

    return self * other_in

  #-----------------------------------------------------------------------------


  #*****************************************************************************
  def __truediv__(self, other):
    """
    PURPOSE: Division overload.
    """
    #***************************************************************************
    
    global dhl
    
    cdef arrso_t res 
    cdef matso lhs,rhs
    cdef dmat dlhs,drhs
    cdef sotinum olhs,orhs
    
    tlhs = type(self)
    trhs = type(other)

    _check_elementwise("division", self, other, None, True)

    if _shapes_differ(self, other):

      return _matso_mixed(_op.truediv, self, other)

    # end if
    
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
      dlhs._sync()
      rhs = other

      res = arrso_div_RO(&dlhs.arr,&rhs.arr, dhl)

    elif ( trhs  == dmat ):

      lhs = self
      drhs = other
      drhs._sync()

      res = arrso_div_OR(&lhs.arr, &drhs.arr, dhl)

    else:

      return NotImplemented      

    # end if 
      
    return _sk(matso.create(&res), _op_kind(self, other))

  #-----------------------------------------------------------------------------

  #*****************************************************************************
  def __matmul__(self, other):
    """
    PURPOSE: Matrix multiplication overload (self @ other). Equivalent to dot(self, other).
    """
    #***************************************************************************

    return dot(self, other)

  #-----------------------------------------------------------------------------

  #*****************************************************************************
  def __rmatmul__(self, other):
    """
    PURPOSE: Reflected matrix multiplication overload (other @ self).
    """
    #***************************************************************************

    return dot(other, self)

  #-----------------------------------------------------------------------------

  #*****************************************************************************
  def __pow__(self, n,z):
    """
    PURPOSE:      Power function overload
    """
    #***************************************************************************
    
    global dhl

    cdef arrso_t res 
    cdef matso S = self
    cdef sotinum n_oti
    cdef matso n_matso


    t_n = type(n)
    t_s = type(self)

    if t_s is matso:

      if t_n is sotinum:

        n_oti = n
        res = arrso_pow_soti( &S.arr, &n_oti.num, dhl)

      elif t_n is matso:

        _check_elementwise("power", self, n)
        n_matso = n
        res = arrso_pow_arrso( &S.arr, &n_matso.arr, dhl)

      else:

        res = arrso_pow( &S.arr, n, dhl)

      # end if 

    else:
      return NotImplemented
    # end if

    return _sk(matso.create(&res), S._lk)


  #-----------------------------------------------------------------------------

  #*****************************************************************************
  def get_all_ims(self, bases_t nbasis, ord_t order ):
    """
    This method creates a new 3D numpy array with all imag. coeffs. exported 
    from the current OTI matso object. A new dimension is added to account for 
    each direction. These are sorted associating the same index-order as 
    the OTI number structure. 
    
    The total number of directions is given by the (nbasis,order) pair 
    to be exported.


    :param nbasis: Number of bases in the OTI number (Related with the number 
                   of variables).

    :param order: Maximum order of directions to export (max order of 
                  derivative).

    :returns: Returns a new numpy array with the derivative information. The 
              resulting array contains the derivatives as follows:

              A = X.get_all_ims(nbasis, order)

              The shape of A is [X.shape[0],X.shape[1],nDirTotal], where 
              nDirTotal is the total numeber of imaginary directions of nbasis, 
              and order.

              A[:,i,j] contains all the imagianry coefficients for the 
              component X[i,j]. 
              -> A[0,i,j]: contains the real part of X[i,j].
              -> A[1,i,j]: contains the epsilon_1 part of X[i,j]. And so on. 
                           The order of the directions are exported in the 
                           same manner as the OTI directions are formed. First
                           directions are sorted by order, and then 
                           directions are sorted by index.

    """
    #***************************************************************************
    global dhl

    # cdef np.ndarray[coeff_t, ndim=3] res
    cdef double[:,:,:] res
    cdef ndir_t ndir
    cdef ord_t ordi
    cdef sotinum_t num
    cdef imdir_t idx, imdir
    cdef int64_t i, j, kk, count

    
    # get first the number of imaginary directions total
    ndir = dhelp_ndirTotal(nbasis, order )
    
    res = np.zeros(( ndir, self.arr.nrows, self.arr.ncols), dtype=np.float64 )

    # for i in range(self.arr.nrows):
    #   for j in range(self.arr.ncols):
    with nogil:
      # This function can be easily parallelized here.
      for kk in range(self.arr.size):
        
        i = kk//self.arr.ncols
        j = kk% self.arr.ncols
        
        num = arrso_get_item_ij( &self.arr, i, j, dhl)
        
        res[0,i,j] = num.re
        count=1

        # Set number imaginary directions
        for ordi in range(min(num.act_order,order)):
          
          for idx in range(num.p_nnz[ordi]):
            imdir = num.p_idx[ordi][idx]
            
            res[count+imdir,i,j] = num.p_im[ordi][idx]

          # end for 
          
          count = count + dhelp_ndirOrder(nbasis, ordi+1)

      # end for 

    # end with      

    return np.asarray(res)

  #-----------------------------------------------------------------------------

  #*****************************************************************************
  def get_all_derivs(self, bases_t nbasis, ord_t order ):
    """
    This method creates a new 3D numpy array with all derivatives exported from 
    the current OTI matso object. A new dimension is added to account for each 
    derivative. Derivatives are sorted associating the same index-order as 
    the OTI number structure. 
    
    The total number of derivatives is given by the (nbasis,order) pair 
    to be exported.


    :param nbasis: Number of bases in the OTI number (Related with the number 
                   of variables).

    :param order: Maximum order of directions to export (max order of 
                  derivative).

    :returns: Returns a new numpy array with the derivative information. The 
              resulting array contains the derivatives as follows:

              A = X.get_all_derivs(nbasis, order)

              The shape of A is [X.shape[0],X.shape[1],nDirTotal], where 
              nDirTotal is the total numeber of imaginary directions of nbasis, 
              and order.

              A[:,i,j] contains all the imagianry coefficients for the 
              component X[i,j]. 
              -> A[0,i,j]: contains the real part of X[i,j].
              -> A[1,i,j]: contains the epsilon_1 part of X[i,j]. And so on. 
                           The order of the derivatives are exported in the 
                           same manner as the OTI directions are formed. First
                           derivatives are sorted by order, and then 
                           derivatives are sorted by index.

    """
    #***************************************************************************
    global dhl

    # cdef np.ndarray[coeff_t, ndim=3] res
    cdef double[:,:,:] res
    cdef coeff_t factor = 1
    cdef ndir_t ndir
    cdef ord_t ordi
    cdef sotinum_t num
    cdef imdir_t idx, imdir
    cdef int64_t i, j, kk, count

    
    # get first the number of imaginary directions total
    ndir = dhelp_ndirTotal(nbasis, order )
    
    res = np.zeros(( ndir, self.arr.nrows, self.arr.ncols), dtype=np.float64 )

    # for i in range(self.arr.nrows):
    #   for j in range(self.arr.ncols):
    with nogil:
      # This function can be easily parallelized here.
      for kk in range(self.arr.size):
        
        i = kk//self.arr.ncols
        j = kk% self.arr.ncols
        
        num = arrso_get_item_ij( &self.arr, i, j, dhl)
        
        res[0,i,j] = num.re
        count=1

        # Set number imaginary directions
        for ordi in range(min(num.act_order,order)):
          
          for idx in range(num.p_nnz[ordi]):
            imdir = num.p_idx[ordi][idx]
            factor = dhelp_get_deriv_factor(imdir, ordi+1, dhl)
            
            res[count+imdir,i,j] = factor*num.p_im[ordi][idx]

          # end for 
          
          count = count + dhelp_ndirOrder(nbasis, ordi+1)

      # end for 

    # end with      

    return np.asarray(res)

  #-----------------------------------------------------------------------------

  #*****************************************************************************
  cpdef get_deriv(self, object hum_dir ):
    """
    PURPOSE: Get the corresponding derivative of the system.
    """
    #***************************************************************************
    global dhl

    cdef list item = imdir(hum_dir)
    cdef np.ndarray tmp
    cdef coeff_t factor = 1
    tmp = self.get_im(hum_dir)

    factor = dhelp_get_deriv_factor(item[ZERO], item[ONE], dhl)

    return tmp * factor

  #-----------------------------------------------------------------------------

  #*****************************************************************************
  cpdef get_im(self, object hum_dir):
    """
    PURPOSE: Get the corresponding imaginary direction in the matso object.
    """
    #***************************************************************************
    global dhl
    
    cdef list item = imdir(hum_dir)
    cdef darr_t res_darr
    cdef dmat res_dmat
    cdef uint64_t i,j, k
    cdef np.ndarray[double, ndim=2] res

    res_darr = arrso_get_im( item[ZERO],  item[ONE], &self.arr,  dhl)

    res = np.empty( (self.arr.nrows, self.arr.ncols) , dtype = np.float64)

    k=0

    for i in range(self.arr.nrows):

      for j in range(self.arr.ncols):

        res[i,j] = res_darr.p_data[k]
        k+=1

      # end for 

    #end for

    # Free memory from C.
    darr_free(&res_darr)

    return res.reshape(self.shape)


  #-----------------------------------------------------------------------------


  #*****************************************************************************
  cpdef extract_im(self, object hum_dir):
    """
    PURPOSE: Get the corresponding imaginary direction in the matso object.
    """
    #***************************************************************************
    global dhl
    
    cdef list item = imdir(hum_dir)
    cdef arrso_t res
    

    res = arrso_extract_im( item[ZERO],  item[ONE], &self.arr,  dhl)

    return _sk(matso.create(&res), self._lk)

  #-----------------------------------------------------------------------------
  
  #*****************************************************************************
  cpdef  extract_deriv(self, object hum_dir):
    """
    PURPOSE: Get the corresponding derivative in the matso object, as OTI number.
    """
    #***************************************************************************
    global dhl
    
    cdef list item = imdir(hum_dir)
    cdef arrso_t res
    
    res = arrso_extract_deriv( item[ZERO],  item[ONE], &self.arr,  dhl)

    return _sk(matso.create(&res), self._lk)

  #-----------------------------------------------------------------------------
  

  #*****************************************************************************
  cpdef  get_order_im(self, ord_t order):
    """
    PURPOSE: Get the corresponding derivative in the matso object, as OTI number.
    """
    #***************************************************************************
    global dhl
    
    cdef arrso_t res
    
    res = arrso_get_order_im( order, &self.arr,  dhl)

    return _sk(matso.create(&res), self._lk)

  #-----------------------------------------------------------------------------
  

  #*****************************************************************************
  cpdef  truncate( self, object humdir):
    """
    PURPOSE:      to set a specific imaginary direction as given.

    """
    #***************************************************************************
    global dhl

    cdef imdir_t indx
    cdef ord_t  order
    cdef arrso_t res
    
    indx, order = imdir(humdir)
    
    res = arrso_truncate_im( indx, order, &self.arr, dhl) 

    return _sk(matso.create(&res), self._lk)

  #-----------------------------------------------------------------------------

  #*****************************************************************************
  cpdef  truncate_order( self, ord_t order):
    """
    Truncates every term whose order is equal to or larger than ``order``.

    The real part is the term of order zero, so it is treated like any other order:
    ``truncate_order(0)`` removes every term, including the real part, and returns zero.
    ``truncate_order(k)`` with ``k >= 1`` keeps the real part and all imaginary directions of
    order ``1 .. k-1``. For ``order >= 1`` the result keeps the truncation order of the input;
    for ``order = 0`` the result is zero with truncation order 0.

    Parameters
    ----------
    order : int
        Lowest order to remove. Terms of order ``0 .. order-1`` are kept.

    Returns
    -------
    matso
        New matso with the truncated terms set to zero. The original is not modified.

    Examples
    --------
    >>> A = oti.array([[1.0, 2.0]]) + oti.e(1, order=3)
    >>> A.truncate_order(1).real     # only the real part remains
    array([[1., 2.]])
    >>> A.truncate_order(0).real     # the real part (order 0) is also removed
    array([[0., 0.]])
    """
    #***************************************************************************
    global dhl

    cdef arrso_t res
    
    res = arrso_truncate_order( order, &self.arr, dhl) 

    return _sk(matso.create(&res), self._lk)

  #-----------------------------------------------------------------------------

  #*****************************************************************************
  cpdef set(self, object rhs):
    """
    PURPOSE:  Sets from another value: ``A.set(rhs)`` is ``A[...] = rhs`` (rule S1c): rhs (an OTI
              scalar, a number, a matso, a dmat, an array_like) broadcasts to A's shape as NumPy does.
    """
    #***************************************************************************

    try:

      self[...] = rhs

    except ValueError as ex:

      if "could not broadcast" in str(ex):

        # 1.x said "different shapes": keep both phrases.
        raise ValueError("set: the arrays have different shapes: {}".format(ex)) from None

      # end if

      raise

    # end try

  #-----------------------------------------------------------------------------

  #*****************************************************************************
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

  #-----------------------------------------------------------------------------

  #*****************************************************************************
  def rom_eval(self, object bases, object deltas):
    """
    This method performs the evaluation of the Reduced Order Model (ROM) by 
    using the equivalent Taylor series expansion. Therefore, what needs to be 
    given to the method are the following inputs

    :param bases: List of bases corresponding to the 
    :param deltas: List of the corresponding deltas to be evaluated 
    """
    #***************************************************************************
    global dhl

    cdef bases_t  size     = dhl.p_dh[0].Nbasis
    cdef coeff_t* c_deltas = dhl.p_dh[0].p_im[0]
    cdef int64_t i
    cdef arrso_t res
    
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

    res = arrso_taylor_integrate( c_deltas, &self.arr, dhl)

    return _sk(matso.create(&res), self._lk)

  #-----------------------------------------------------------------------------

  #*****************************************************************************
  @staticmethod
  def dot( matso lhs, matso rhs, matso out = None):
    """
    PURPOSE: Matrix multiplication. Same as the module function ``dot``.
    """
    return dot( lhs, rhs, out)

  #-----------------------------------------------------------------------------

  #*****************************************************************************
  @staticmethod
  def inv( matso arr,  matso out = None):
    """
    PURPOSE: Matrix inversion. Same as the module function ``inv``.
    :raises numpy.linalg.LinAlgError: the real part of the array is singular.
    """
    return inv( arr, out = out)

  #-----------------------------------------------------------------------------

  #*****************************************************************************
  @staticmethod
  def transpose( matso arr,  matso out = None ):
    """
    PURPOSE: Matrix transpose. Same as the module function ``transpose``.
    """
    return transpose( arr, out)

  #-----------------------------------------------------------------------------

  #*****************************************************************************
  @staticmethod
  def add( matso lhs, matso rhs, matso out = None):
    """
    PURPOSE: Matrix elementwise addition. Same as the module function ``sum``.
    """
    return sum( lhs, rhs, out)

  #-----------------------------------------------------------------------------


#-----------------------------------------------------------------------------------------------------
# 7b helpers: the logical shape kind of matso results (0: 2-D, 1: 1-D stored n x 1, 2: 0-D stored 1 x 1).
#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
cdef inline matso _sk(matso m, uint8_t lk):
  """
  PURPOSE:  Give a freshly created matso its logical shape kind and return it.
  """
  #***************************************************************************************************

  m._lk = lk

  return m

#-----------------------------------------------------------------------------------------------------


#*****************************************************************************************************
cdef uint8_t _op_kind(object lhs, object rhs):
  """
  PURPOSE:  The logical shape kind of an elementwise result: the one of the matso operand, else of the
            dmat operand (scalars have none).
  """
  #***************************************************************************************************

  cdef matso O
  cdef dmat  R

  if type(lhs) is matso:

    O = lhs

    return O._lk

  elif type(rhs) is matso:

    O = rhs

    return O._lk

  elif type(lhs) is dmat:

    R = lhs

    return R._lk

  elif type(rhs) is dmat:

    R = rhs

    return R._lk

  # end if

  return 0

#-----------------------------------------------------------------------------------------------------


#*****************************************************************************************************
def _matso_iter(matso A):
  """
  PURPOSE:  The rows of A, one axis fewer (OTI scalars for a 1-D array): A[0], A[1], ...
  """
  #***************************************************************************************************

  cdef uint64_t i

  for i in range(A.arr.nrows):

    yield A[i]

  # end for

#-----------------------------------------------------------------------------------------------------


#*****************************************************************************************************
cdef matso _as_matso(object value):
  """
  PURPOSE:  A matso with the values of a dmat or an array_like (the right side of an assignment).
  """
  #***************************************************************************************************

  cdef dmat R

  if type(value) is dmat:

    R = value
    value = R.to_numpy()

  # end if

  try:

    values = np.asarray(value, dtype=np.float64)

  except (TypeError, ValueError):

    if isinstance(value, (list, tuple)):

      # A list of OTI scalars (or of lists of them): the creator reads OTI values.
      try:

        return array(value)

      except (TypeError, ValueError, IndexError):

        pass

      # end try

    # end if

    raise IndexError("ERROR: Cant set item of type {0} in matso object.".format(type(value))) from None

  # end try

  return matso(values)

#-----------------------------------------------------------------------------------------------------


#*****************************************************************************************************
cdef object _shapes_differ(object lhs, object rhs):
  """
  PURPOSE:  True when both operands are arrays (matso, dmat) of different logical shapes.
  """
  #***************************************************************************************************

  tl = type(lhs)
  tr = type(rhs)

  return (tl is matso or tl is dmat) and (tr is matso or tr is dmat) and lhs.shape != rhs.shape

#-----------------------------------------------------------------------------------------------------


#*****************************************************************************************************
def _matso_mixed(object op, object lhs, object rhs):
  """
  PURPOSE:  An elementwise operation between arrays of different logical shapes. An array with a single
            element acts as a scalar; the result has NumPy's broadcast shape of the two operands
            ((4,) + (1, 1) is (1, 4), as in pyoti.dense). Anything else is an error: a 2-D C struct
            broadcasts only between equal shapes and single elements (11.2).
  """
  #***************************************************************************************************

  cdef matso O
  cdef dmat  R
  cdef sotinum_t ores

  lsize = _array_size(lhs)
  rsize = _array_size(rhs)

  if lsize != 1 and rsize != 1:

    raise ValueError("operands have different shapes {} and {} and could not be broadcast together: "
                     "broadcasting between shapes is supported by pyoti.dense only".format(
                     lhs.shape, rhs.shape))

  # end if

  shape = tuple(np.broadcast_shapes(lhs.shape, rhs.shape))

  if len(shape) > 2:

    raise ValueError("pyoti.sparse arrays have at most 2 dimensions: the result of operands of shapes "
                     "{} and {} would have shape {}".format(lhs.shape, rhs.shape, shape))

  # end if

  if lsize == 1 and (rsize != 1 or lhs.ndim >= rhs.ndim):

    res = op(_single(lhs), rhs)

  else:

    res = op(lhs, _single(rhs))

  # end if

  if res.shape != shape:

    res = res.reshape(shape)

  # end if

  return res

#-----------------------------------------------------------------------------------------------------


#*****************************************************************************************************
cdef object _array_size(object obj):
  """
  PURPOSE:  Number of elements of a matso or dmat.
  """
  #***************************************************************************************************

  cdef matso O

  if type(obj) is matso:

    O = obj

    return O.arr.size

  # end if

  return obj.size

#-----------------------------------------------------------------------------------------------------


#*****************************************************************************************************
cdef object _single(object obj):
  """
  PURPOSE:  The only element of a one-element matso (an OTI scalar copy) or dmat (a float).
  """
  #***************************************************************************************************

  cdef matso O
  cdef sotinum_t ores

  if type(obj) is matso:

    O = obj
    ores = arrso_get_item_i( &O.arr, 0, dhl)

    return sotinum.create(&ores, FLAGS = 0).copy()

  # end if

  return obj.to_numpy().reshape(-1)[0].item()

#-----------------------------------------------------------------------------------------------------
