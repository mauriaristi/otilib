#-----------------------------------------------------------------------------------------------------
# *****************************************************************************************************
cdef int _dmat_slice_item(nd_index_t* item, object sl, int64_t n) except -1:
  """
  PURPOSE:      A Python slice, applied to an axis of extent n, as a normalized ndarray index item.

  DESCRIPTION:  The slice is normalized by Python (slice.indices), then written so that the NumPy
                normalization of nd_view_index gives back exactly the same elements (an empty slice
                is 0:0, and a stop of "before 0" is left out).
  """
  #***************************************************************************************************

  cdef int64_t start, stop, step, length, last

  start, stop, step = sl.indices(n)
  length = len(range(start, stop, step))

  item.kind = ND_IDX_SLICE
  item.arr  = NULL

  if length == 0:

    item.start = 0
    item.stop  = 0
    item.step  = 1
    item.has   = ND_HAS_START | ND_HAS_STOP | ND_HAS_STEP

    return 0

  # end if

  item.start = start
  item.step  = step
  item.has   = ND_HAS_START | ND_HAS_STEP

  last = start + step*length

  if step > 0 or last >= 0:

    item.stop = last
    item.has |= ND_HAS_STOP

  # end if

  return 0

#-----------------------------------------------------------------------------------------------------

# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::     CLASS  DMAT    ::::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
cdef class dmat:
  #---------------------------------------------------------------------------------------------------
  #------------------------------------   DEFINITION OF ATTRIBUTES   ---------------------------------
  #---------------------------------------------------------------------------------------------------

  #                                --->      Look in real.pxd    <---

  # dmat is a buffer / DLPack exporter now: tell NumPy to defer to the operators of this class
  # (np.float64(2) * D must reach dmat.__rmul__, not become an ndarray).
  __array_ufunc__ = None

  #---------------------------------------------------------------------------------------------------


  #***************************************************************************************************
  def __cinit__(self, *args, **kwargs):
    """
    PURPOSE:      Allocation hook: the descriptors start empty (PLAN-ndarray.md Phase 6b).
    """
    #*************************************************************************************************

    nd_init_empty(&self.nd)
    nd_init_empty(&self.snap)

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  def __init__(self, nrows, ncols, uint8_t FLAGS = 1):
    """
    PURPOSE:      Python level constructor of the dmat class.

    DESCRIPTION:  Creates a new matrix (uninitialized memory), a retained (nrows, ncols) F64 array.

    """
    #*************************************************************************************************

    cdef uint64_t rows = nrows
    cdef uint64_t cols = ncols
    cdef int64_t  shape[2]

    if rows > <uint64_t>INT64_MAX or cols > <uint64_t>INT64_MAX:

      raise ValueError("dmat: the shape ({}, {}) is too large".format(nrows, ncols))

    # end if

    shape[0] = <int64_t>rows
    shape[1] = <int64_t>cols

    nd_release(&self.nd)
    nd_release(&self.snap)

    self.FLAGS = FLAGS
    _nd_status("dmat", nd_empty(_nd_ctx, 2, shape, ND_LAYOUT_C, &self.nd))
    self._bind()

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  def __dealloc__(self):
    """
    PURPOSE:      Destructor of the class.

    DESCRIPTION:  Drops the references to the memory (the last one frees it, or ends the export that
                  handed it over).

    """
    #*************************************************************************************************

    nd_release(&self.snap)
    nd_release(&self.nd)

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  @property
  def order(self):
    """
    PURPOSE:      Return the OTI imaginary order of the array.
    """
    #*************************************************************************************************

    return 0

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
  def nrows(self):
    """
    PURPOSE:      Return the number of rows of the stored matrix.
    """
    #*************************************************************************************************

    return self.arr.nrows

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  @property
  def ncols(self):
    """
    PURPOSE:      Return the number of columns of the stored matrix.
    """
    #*************************************************************************************************

    return self.arr.ncols

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
    PURPOSE:      Get a numpy array with all coefficients in the real direction (a copy).

    """
    #*************************************************************************************************

    return np.array(self.to_numpy(), dtype=np.float64, copy=True)

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  @staticmethod
  cdef dmat create(darr_t* arr, uint8_t FLAGS = 1):
    """
    PURPOSE:      C-level constructor of the class. Use this when creating objects within
                  Cython

    DESCRIPTION:  FLAGS & 1: the object takes over the memory of arr (the caller must not free it);
                  otherwise the memory stays with the caller, who must keep it alive.

    """
    #*************************************************************************************************

    # create new empty object:
    cdef dmat mat = <dmat> dmat.__new__(dmat)
    cdef darr_t tmp = arr[0]

    mat.FLAGS = FLAGS

    # TAKE passes the ownership on entry: the memory is freed with the last reference.
    _nd_status("dmat", nd_from_darr(_nd_ctx, &tmp, ND_DARR_TAKE if (FLAGS & 1) else ND_DARR_RETAIN,
                                    &mat.nd))
    mat._bind()

    return mat

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  @staticmethod
  cdef dmat create_view(ndarr_t* view):
    """
    PURPOSE:      C-level constructor over a retained 2-D F64 descriptor (a view of some dmat, or
                  any retained array). The object takes the reference: view is left empty.

    """
    #*************************************************************************************************

    cdef dmat mat = <dmat> dmat.__new__(dmat)

    nd_move(view, &mat.nd)
    mat.FLAGS = 1
    mat._bind()

    return mat

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  cdef int _bind(self) except -1:
    """
    PURPOSE:      Make self.arr (the darr_t window for sparse, static and fem code) describe self.nd.

    DESCRIPTION:  A C-contiguous matrix is described in place (zero-copy, live). A strided view (a
                  column slice, a step slice, ...) gets a contiguous snapshot in self.snap, which
                  _sync refreshes before the matrix is read through arr and _flush writes back.

    """
    #*************************************************************************************************

    cdef int status

    nd_release(&self.snap)

    if self.nd.flags & ND_C_CONTIG:

      _nd_status("dmat", nd_as_darr(&self.nd, 1, &self.arr), &self.nd)

    else:

      with nogil:

        status = nd_copy(_nd_ctx, &self.nd, ND_LAYOUT_C, &self.snap)

      # end with

      _nd_status("dmat", status, &self.nd)
      _nd_status("dmat", nd_as_darr(&self.snap, 1, &self.arr), &self.snap)

    # end if

    return 0

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  cdef int _sync(self) except -1:
    """
    PURPOSE:      Refresh self.arr before it is read: a no-op unless the matrix is a strided view.

    """
    #*************************************************************************************************

    cdef int status

    if self.snap.buf != NULL:

      with nogil:

        status = nd_assign(_nd_ctx, &self.nd, &self.snap)

      # end with

      _nd_status("dmat", status, &self.nd)

    # end if

    return 0

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  cdef int _flush(self) except -1:
    """
    PURPOSE:      Write self.arr back after C code wrote through it: a no-op unless the matrix is a
                  strided view.

    """
    #*************************************************************************************************

    cdef int status

    if self.snap.buf != NULL:

      with nogil:

        status = nd_assign(_nd_ctx, &self.snap, &self.nd)

      # end with

      _nd_status("dmat", status, &self.nd)

    # end if

    return 0

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  cdef int _check_out(self) except -1:
    """
    PURPOSE:      Refuse a strided view as the output of a routine that writes through self.arr (the
                  write would reach the snapshot only): the result must be a C-contiguous dmat.

    """
    #*************************************************************************************************

    if self.snap.buf != NULL:

      raise ValueError("out must be a C-contiguous dmat: a strided view (a column or step slice) "
                       "cannot be written by this routine")

    # end if

    return 0

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  cdef int _slice(self, object ii, object jj, ndarr_t* out) except -1:
    """
    PURPOSE:      The view self[ii, jj] for two slice objects, as a retained descriptor (out must be
                  empty). The two axes keep their extent-1 axis (the matrix rule of 1.x).

    """
    #*************************************************************************************************

    cdef nd_index_t idx[2]

    _dmat_slice_item(&idx[0], ii, self.nd.shape[0])
    _dmat_slice_item(&idx[1], jj, self.nd.shape[1])

    _nd_status("dmat", nd_view_index(&self.nd, 2, idx, out), &self.nd)

    return 0

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  cdef object _view(self, object ii, object jj):
    """
    PURPOSE:      self[ii, jj] as a dmat that shares the memory.

    """
    #*************************************************************************************************

    cdef ndarr_t view

    nd_init_empty(&view)

    try:

      self._slice(ii, jj, &view)

      return dmat.create_view(&view)

    finally:

      nd_release(&view)    # no-op once create_view took the reference

    # end try

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  cdef int _check_ij(self, object val0, object val1) except -1:
    """
    PURPOSE:      Convert an (i, j) pair like the 1.x item access did: negative values are an
                  OverflowError (they went to uint64_t), values past the shape an IndexError.

    """
    #*************************************************************************************************

    cdef uint64_t i = val0
    cdef uint64_t j = val1

    if i >= <uint64_t>self.nd.shape[0] or j >= <uint64_t>self.nd.shape[1]:

      raise IndexError("Index out of bounds.")

    # end if

    return 0

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  def __getbuffer__(self, Py_buffer* buffer, int flags):
    """
    PURPOSE:      Buffer protocol (PEP 3118): the matrix, writeable, strided (zero-copy). The export
                  pins the memory; see nd_getbuffer.
    """
    #*************************************************************************************************

    nd_getbuffer(&self.nd, 1, buffer, flags, self)

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  def __releasebuffer__(self, Py_buffer* buffer):
    """
    PURPOSE:      Ends a buffer export.
    """
    #*************************************************************************************************

    nd_releasebuffer(buffer)

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  def __dlpack__(self, *, stream = None, max_version = None, dl_device = None, copy = None):
    """
    PURPOSE:      DLPack export (CPU, writeable, zero-copy): a capsule that pins the memory.

    DESCRIPTION:  max_version >= (1, 0) gives a "dltensor_versioned" capsule, else a legacy
                  "dltensor" one. dl_device must be None or (1, 0).
    """
    #*************************************************************************************************

    return nd_dlpack_call(&self.nd, 1, stream, max_version, dl_device, copy)

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  def __dlpack_device__(self):
    """
    PURPOSE:      DLPack device of the memory: (kDLCPU, 0).
    """
    #*************************************************************************************************

    return (_ND_KDLCPU, 0)

  #---------------------------------------------------------------------------------------------------


  #***************************************************************************************************
  def __repr__(self):
    """
    PURPOSE:      A short representation of the object.

    """
    #*************************************************************************************************

    # head =  "dmat("
    # body =  "size: "+str(self.arr.size)  +  ", "
    # body += "nrows: "+str(self.arr.nrows)+  ", "
    # body += 'ncols: '+str(self.arr.ncols)
    # tail =  ")"
    # return (head + body + tail)

    cdef np.ndarray[double, ndim=2] A = self.to_numpy()

    return repr(A)

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  def __str__(self):
    """
    PURPOSE:      Create a string representation of the object.
    """
    #*************************************************************************************************

    # cdef uint64_t i,j,k=0

    # # dmat_print_fmt =
    # head      = ''
    # body      = '['
    # for i in range(self.arr.nrows):

    #   body += '['

    #   for j in range(self.arr.ncols):

    #     body += "{:10.4f},".format(self.arr.p_data[k])
    #     k += 1

    #   # end for

    #   body += '\b]\n '

    # # end for
    # body = body[:len(body)-2]
    # body += ']\n'

    # tail      = ''

    # return (head + body + tail)

    cdef np.ndarray[double, ndim=2] A = self.to_numpy()

    return str(A)

  #---------------------------------------------------------------------------------------------------



  #***************************************************************************************************
  def __getitem__(self, val):
    """
    PURPOSE: Get the value of an element of the item, or a view of a block (it shares the memory).
    """
    #*************************************************************************************************

    cdef object full = slice(None, None, None)

    tval = type(val)

    if tval == int:

      if val < self.nd.shape[0]:

        return self._view(slice(val, val+1, None), full)

      else:

        raise IndexError("Index out of bounds.")

      # end if

    elif tval == slice: #slice of multiple items

      return self._view(val, full)

    elif tval == tuple:

      if len(val) == 2:

        tval0 = type(val[0])
        tval1 = type(val[1])

        if   tval0 == int and tval1 == int:

          self._check_ij(val[0], val[1])
          return (<double*>self.nd.data)[val[0]*self.nd.strides[0] + val[1]*self.nd.strides[1]]

        elif tval0 == int and tval1 == slice:

          if val[0] < self.nd.shape[0]:

            return self._view(slice(val[0], val[0]+1, None), val[1])

          else:

            raise IndexError("Index out of bounds.")

          # end if

        elif tval0 == slice and tval1 == int:

          if val[1] < self.nd.shape[1]:

            return self._view(val[0], slice(val[1], val[1]+1, None))

          else:

            raise IndexError("Index out of bounds.")

          # end if

        elif tval0 == slice and tval1 == slice:

          return self._view(val[0], val[1])

        else:

          raise IndexError("ERROR: double index ( , ) only integers, slices (`:`) are valid indices")

        # end if

      else:

        raise IndexError("ERROR: Getting integration points by index is not yet supported.")

      # end if

    else:

      raise IndexError("ERROR: only integers, slices (`:`) are valid indices")

    # end if

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  def __setitem__(self, val, value):
    """
    PURPOSE: Set an element of the item to the specified value.
    """
    #*************************************************************************************************

    tvalue = type(value)

    if ( tvalue == dmat ):

      self.__setitem__R( val, value )

    elif ( tvalue in number_types ):

      self.__setitem__r( val, value )

    else:

      raise IndexError("ERROR: Cant set item of type {0} in matso object.".format(tvalue))

    # end if

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  cdef __setitem__r(self, object val, coeff_t value):
    """
    PURPOSE: Set item from real value.
    """
    #*************************************************************************************************

    cdef object full = slice(None, None, None)
    cdef ndarr_t dst
    cdef object ii, jj
    cdef int status

    tval = type(val)

    if tval == int:

      if val < self.nd.shape[0]:

        ii = slice(val, val+1, None)
        jj = full

      else:

        raise IndexError("Index out of bounds.")

      # end if

    elif tval == slice: #slice of multiple items

      ii = val
      jj = full

    elif tval == tuple:

      if len(val) == 2:

        tval0 = type(val[0])
        tval1 = type(val[1])

        if ( tval0 == int and tval1 == int ):

          self._check_ij(val[0], val[1])
          (<double*>self.nd.data)[val[0]*self.nd.strides[0] + val[1]*self.nd.strides[1]] = value
          return

        elif (tval0 == int and tval1 == slice):

          if val[0] < self.nd.shape[0]:

            ii = slice(val[0], val[0]+1, None)
            jj = val[1]

          else:

            raise IndexError("Index out of bounds.")

          # end if

        elif (tval0 == slice and tval1 == int):

          if val[1] < self.nd.shape[1]:

            ii = val[0]
            jj = slice(val[1], val[1]+1, None)

          else:

            raise IndexError("Index out of bounds.")

          # end if

        elif (tval0 == slice and tval1 == slice):

          ii = val[0]
          jj = val[1]

        else:

          raise IndexError("ERROR: double index ( , ) only integers, slices (`:`) are valid indices")

        # end if

      else:

        raise IndexError("ERROR: Getting integration points by index is not yet supported.")

      # end if

    else:

      raise IndexError("ERROR: only integers, slices (`:`) are valid indices")

    # end if

    nd_init_empty(&dst)

    try:

      self._slice(ii, jj, &dst)

      with nogil:

        status = nd_fill(_nd_ctx, &dst, value)

      # end with

      _nd_status("dmat", status, &dst)

    finally:

      nd_release(&dst)

    # end try

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  cdef __setitem__R(self,  object val, dmat value):
    """
    PURPOSE: Set item from real array. The block and the value must have the same shape.
    """
    #*************************************************************************************************

    cdef object full = slice(None, None, None)
    cdef ndarr_t dst
    cdef object ii, jj
    cdef int status

    tval = type(val)

    if tval == int:

      if val < self.nd.shape[0]:

        ii = slice(val, val+1, None)
        jj = full

      else:

        raise IndexError("Index out of bounds.")

      # end if

    elif tval == slice: #slice of multiple items

      ii = val
      jj = full

    elif tval == tuple:

      if len(val) == 2:

        tval0 = type(val[0])
        tval1 = type(val[1])

        if ( tval0 == int and tval1 == int ):

          if val[0] < self.nd.shape[0] and val[1] < self.nd.shape[1]:

            ii = slice(val[0], val[0]+1, None)
            jj = slice(val[1], val[1]+1, None)

          else:

            raise IndexError("Index out of bounds.")

          # end if

        elif (tval0 == int and tval1 == slice):

          if val[0] < self.nd.shape[0]:

            ii = slice(val[0], val[0]+1, None)
            jj = val[1]

          else:

            raise IndexError("Index out of bounds.")

          # end if

        elif (tval0 == slice and tval1 == int):

          if val[1] < self.nd.shape[1]:

            ii = val[0]
            jj = slice(val[1], val[1]+1, None)

          else:

            raise IndexError("Index out of bounds.")

          # end if

        elif (tval0 == slice and tval1 == slice):

          ii = val[0]
          jj = val[1]

        else:

          raise IndexError("ERROR: double index ( , ) only integers, slices (`:`) are valid indices")

        # end if

      else:

        raise IndexError("ERROR: Getting integration points by index is not yet supported.")

      # end if

    else:

      raise IndexError("ERROR: only integers, slices (`:`) are valid indices")

    # end if

    nd_init_empty(&dst)

    try:

      self._slice(ii, jj, &dst)

      if dst.shape[0] != value.nd.shape[0] or dst.shape[1] != value.nd.shape[1]:

        raise ValueError("Wrong dimensions for input array: cannot assign a ({}, {}) matrix to a "
                         "({}, {}) block.".format(value.nd.shape[0], value.nd.shape[1],
                                                  dst.shape[0], dst.shape[1]))

      # end if

      with nogil:

        status = nd_assign(_nd_ctx, &value.nd, &dst)

      # end with

      _nd_status("dmat", status, &dst)

    finally:

      nd_release(&dst)

    # end try

  #---------------------------------------------------------------------------------------------------


  #***************************************************************************************************
  def __neg__(self):
    """
    PURPOSE: Negation overload.
    """
    #*************************************************************************************************

    self._sync()
    cdef darr_t newmat = darr_neg(&self.arr)

    return dmat.create(&newmat)
  #---------------------------------------------------------------------------------------------------




  #***************************************************************************************************
  def __add__(self, other):
    """
    PURPOSE: Addition overload.
    """
    #*************************************************************************************************

    cdef darr_t res
    cdef dmat lhs,rhs

    tlhs = type(self)
    trhs = type(other)

    if (tlhs == trhs):

      lhs = self

      lhs._sync()
      rhs = other
      rhs._sync()

      res = darr_sum_RR(&lhs.arr,&rhs.arr)

    elif (tlhs in number_types):

      rhs = other

      rhs._sync()
      res = darr_sum_rR(self, &rhs.arr)

    elif (trhs in number_types):

      lhs = self

      lhs._sync()
      res = darr_sum_rR(other, &lhs.arr)

    else:

      return NotImplemented

    # end if

    return dmat.create(&res)

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

    cdef darr_t res
    cdef dmat lhs,rhs

    tlhs = type(self)
    trhs = type(other)

    if (tlhs == trhs):

      lhs = self

      lhs._sync()
      rhs = other
      rhs._sync()

      res = darr_sub_RR(&lhs.arr,&rhs.arr)

    elif (tlhs in number_types):

      rhs = other

      rhs._sync()
      res = darr_sub_rR(self, &rhs.arr)

    elif (trhs in number_types):

      lhs = self

      lhs._sync()
      res = darr_sub_Rr( &lhs.arr, other)

    else:

      return NotImplemented

    # end if

    return dmat.create(&res)

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

    cdef darr_t res
    cdef dmat lhs,rhs

    tlhs = type(self)
    trhs = type(other)

    if (tlhs == trhs):

      lhs = self

      lhs._sync()
      rhs = other
      rhs._sync()

      res = darr_mul_RR(&lhs.arr,&rhs.arr)

    elif (tlhs in number_types):

      rhs = other

      rhs._sync()
      res = darr_mul_rR(self, &rhs.arr)

    elif (trhs in number_types):

      lhs = self

      lhs._sync()
      res = darr_mul_rR(other, &lhs.arr)

    else:

      return NotImplemented

    # end if

    return dmat.create(&res)


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

    cdef darr_t res
    cdef dmat lhs,rhs

    tlhs = type(self)
    trhs = type(other)

    if (tlhs == trhs):

      lhs = self

      lhs._sync()
      rhs = other
      rhs._sync()

      res = darr_div_RR(&lhs.arr,&rhs.arr)

    elif (tlhs in number_types):

      rhs = other

      rhs._sync()
      res = darr_div_rR(self, &rhs.arr)

    elif (trhs in number_types):

      lhs = self

      lhs._sync()
      res = darr_div_Rr( &lhs.arr, other)

    else:

      return NotImplemented

    # end if

    return dmat.create(&res)


  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  cpdef np.ndarray[double, ndim=2] to_numpy(self):
    """
    PURPOSE: Interface to numpy representation.
    """
    #*************************************************************************************************

    return nd_to_numpy(&self.nd, 1)

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  def __pow__(self, n,z):
    """
    PURPOSE: Power function.
    """
    #*************************************************************************************************

    return pow(self,n)

  #---------------------------------------------------------------------------------------------------


  #***************************************************************************************************
  cpdef copy(self):
    """
    PURPOSE: Copy the elements to new memory spaces.
    """
    #*************************************************************************************************

    self._sync()

    cdef darr_t res = darr_copy(&self.arr)

    return dmat.create(&res)

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  cpdef set(self, coeff_t val):
    """
    PURPOSE: Set all elements to val.
    """
    #*************************************************************************************************

    cdef int status

    with nogil:

      status = nd_fill(_nd_ctx, &self.nd, val)

    # end with

    _nd_status("dmat", status, &self.nd)

  #---------------------------------------------------------------------------------------------------


# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# :::::::::::::::::::::::::::::::::::: END OF CLASS DMAT :::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::




