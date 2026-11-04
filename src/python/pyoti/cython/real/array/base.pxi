#-----------------------------------------------------------------------------------------------------
# *****************************************************************************************************
cdef int _dmat_range_item(nd_index_t* item, int64_t start, int64_t stop, int64_t step) except -1:
  """
  PURPOSE:      A normalized (slice.indices) start / stop / step triple as a ndarray index item.

  DESCRIPTION:  Written so that the NumPy normalization of nd_view_index gives back exactly the same
                elements (an empty slice is 0:0, and a stop of "before 0" is left out).
  """
  #***************************************************************************************************

  cdef int64_t length, last

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

# *****************************************************************************************************
cdef int _dmat_slice_item(nd_index_t* item, object sl, int64_t n) except -1:
  """
  PURPOSE:      A Python slice, applied to an axis of extent n, as a normalized ndarray index item.
  """
  #***************************************************************************************************

  cdef int64_t start, stop, step

  start, stop, step = sl.indices(n)

  return _dmat_range_item(item, start, stop, step)

#-----------------------------------------------------------------------------------------------------

# *****************************************************************************************************
def _dmat_iter(dmat D):
  """
  PURPOSE:      The rows of D, one axis fewer (floats for a 1-D matrix): D[0], D[1], ...
  """
  #***************************************************************************************************

  cdef int64_t i

  for i in range(D.nd.shape[0]):

    yield D[i]

  # end for

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
  def T(self):
    """
    PURPOSE:      The transpose (a copy; a 1-D or 0-D array is its own transpose, as in NumPy).
    """
    #*************************************************************************************************

    return transpose(self)

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  def reshape(self, *shape, order = 'C'):
    """
    PURPOSE:      A copy with another shape of at most 2 dimensions (reshape(3, 4), reshape((3, 4)),
                  reshape(-1)); one extent may be -1. Only order='C' (the row-major order of NumPy).
    """
    #*************************************************************************************************

    if order != 'C':

      raise ValueError("reshape: only order='C' is supported")

    # end if

    dims = reshape_shape(shape, self.size, "pyoti.real")

    return array(np.ascontiguousarray(self.to_numpy()).reshape(dims))

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  @property
  def shape(self):
    """
    PURPOSE:      Return the shape of the stored matrix.
    """
    #*************************************************************************************************

    if self._lk == 0:

      return (self.nd.shape[0], self.nd.shape[1])

    elif self._lk == 1:

      return (self.nd.shape[0],)

    # end if

    return ()

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  @property
  def ndim(self):
    """
    PURPOSE:      Return the number of dimensions of the logical shape (0, 1 or 2).
    """
    #*************************************************************************************************

    return 2 - self._lk

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  @property
  def nrows(self):
    """
    PURPOSE:      Return the number of rows of the stored matrix (deprecated: use shape; 1-D: n, 0-D: 1).
    """
    #*************************************************************************************************

    warnings.warn("nrows is deprecated, use shape", DeprecationWarning, stacklevel=2)

    return self.nd.shape[0]

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  @property
  def ncols(self):
    """
    PURPOSE:      Return the number of columns of the stored matrix (deprecated: use shape; 1-D, 0-D: 1).
    """
    #*************************************************************************************************

    warnings.warn("ncols is deprecated, use shape", DeprecationWarning, stacklevel=2)

    return self.nd.shape[1]

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  @property
  def  size(self):
    """
    PURPOSE:      Return the size of array.
    """
    #*************************************************************************************************

    return self.nd.shape[0]*self.nd.shape[1]

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  def __len__(self):
    """
    PURPOSE:      Length of the first axis; a 0-D matrix has none.
    """
    #*************************************************************************************************

    if self._lk == 2:

      raise TypeError("len() of a 0-d dmat")

    # end if

    return self.nd.shape[0]

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  def __iter__(self):
    """
    PURPOSE:      Iterate over the first axis (rows with one axis fewer; floats for a 1-D matrix).
    """
    #*************************************************************************************************

    if self._lk == 2:

      raise TypeError("iteration over a 0-d dmat")

    # end if

    return _dmat_iter(self)

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
  cdef dmat create_view(ndarr_t* view, uint8_t lk = 0):
    """
    PURPOSE:      C-level constructor over a retained 2-D F64 descriptor (a view of some dmat, or
                  any retained array). The object takes the reference: view is left empty. lk is the
                  logical shape kind (0: 2-D, 1: 1-D stored n x 1, 2: 0-D stored 1 x 1).

    """
    #*************************************************************************************************

    cdef dmat mat = <dmat> dmat.__new__(dmat)

    nd_move(view, &mat.nd)
    mat.FLAGS = 1
    mat._lk   = lk
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
    cdef ndarr_t kept

    nd_init_empty(&view)
    nd_init_empty(&kept)

    try:

      self._slice(ii, jj, &view)

      # nd_view_index gives a temporary that only borrows self's reference: pin the memory.
      _nd_status("dmat", nd_view_retain(&view, &kept), &self.nd)

      return dmat.create_view(&kept)

    finally:

      nd_release(&kept)    # no-op once create_view took the reference

    # end try

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  cdef object _view_rng(self, tuple r):
    """
    PURPOSE:      The view selected by a key2d result r (ranges of the 2-D struct, logical shape) as
                  a dmat of that logical shape; it shares the memory.

    DESCRIPTION:  A 1-D result of a row key is 1 x k in the 2-D struct: it is transposed (a view) to
                  the stored k x 1 form.

    """
    #*************************************************************************************************

    cdef nd_index_t idx[2]
    cdef ndarr_t block
    cdef ndarr_t tmp
    cdef ndarr_t kept
    cdef uint8_t lk = 0
    cdef object shape = r[6]

    if shape is not None:

      lk = 2 - len(shape)

    # end if

    nd_init_empty(&block)
    nd_init_empty(&tmp)
    nd_init_empty(&kept)

    try:

      _dmat_range_item(&idx[0], r[0], r[1], r[2])
      _dmat_range_item(&idx[1], r[3], r[4], r[5])

      _nd_status("dmat", nd_view_index(&self.nd, 2, idx, &block), &self.nd)

      if lk == 1 and block.shape[0] == 1 and block.shape[1] != 1:

        _nd_status("dmat", nd_view_transpose(&block, 0, NULL, &tmp), &self.nd)
        _nd_status("dmat", nd_view_retain(&tmp, &kept), &self.nd)

      else:

        _nd_status("dmat", nd_view_retain(&block, &kept), &self.nd)

      # end if

      return dmat.create_view(&kept, lk)

    finally:

      nd_release(&kept)    # no-op once create_view took the reference

    # end try

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  cdef int _logical(self, ndarr_t* out) except -1:
    """
    PURPOSE:      A temporary view of the matrix with its LOGICAL shape: nd itself (2-D), nd without
                  its column axis (1-D) or without both axes (0-D). It borrows self's reference.

    """
    #*************************************************************************************************

    cdef int32_t axes[2]

    if self._lk == 0:

      _nd_status("dmat", nd_view_index(&self.nd, 0, NULL, out), &self.nd)

    elif self._lk == 1:

      axes[0] = 1
      _nd_status("dmat", nd_view_squeeze(&self.nd, 1, axes, out), &self.nd)

    else:

      axes[0] = 0
      axes[1] = 1
      _nd_status("dmat", nd_view_squeeze(&self.nd, 2, axes, out), &self.nd)

    # end if

    return 0

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

    cdef ndarr_t lv

    self._logical(&lv)
    nd_getbuffer(&lv, 1, buffer, flags, self)

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

    cdef ndarr_t lv

    self._logical(&lv)

    return nd_dlpack_call(&lv, 1, stream, max_version, dl_device, copy)

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

    return repr(self.to_numpy())

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

    return str(self.to_numpy())

  #---------------------------------------------------------------------------------------------------



  #***************************************************************************************************
  cdef tuple _key(self, object val):
    """
    PURPOSE:      The NumPy key val resolved on the logical shape (key2d): ranges of the 2-D struct
                  and the logical result shape (None: one integer per axis, a scalar element).
    """
    #*************************************************************************************************

    return key2d(val, 2 - self._lk, self.nd.shape[0], self.nd.shape[1], "pyoti.real")

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  cdef int _target(self, tuple r, ndarr_t* out) except -1:
    """
    PURPOSE:      The block selected by a key2d result as a temporary view of its logical shape (the
                  shape an assignment broadcasts to). It borrows self's reference.
    """
    #*************************************************************************************************

    cdef nd_index_t idx[2]
    cdef ndarr_t block
    cdef int32_t axes[2]
    cdef object shape = r[6]

    nd_init_empty(&block)

    _dmat_range_item(&idx[0], r[0], r[1], r[2])
    _dmat_range_item(&idx[1], r[3], r[4], r[5])

    _nd_status("dmat", nd_view_index(&self.nd, 2, idx, &block), &self.nd)

    if shape is None or len(shape) == 0:

      axes[0] = 0
      axes[1] = 1
      _nd_status("dmat", nd_view_squeeze(&block, 2, axes, out), &self.nd)

    elif len(shape) == 1:

      axes[0] = 1 if block.shape[1] == 1 else 0
      _nd_status("dmat", nd_view_squeeze(&block, 1, axes, out), &self.nd)

    else:

      _nd_status("dmat", nd_view_index(&block, 0, NULL, out), &self.nd)

    # end if

    return 0

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  def __getitem__(self, val):
    """
    PURPOSE: NumPy basic indexing on the logical shape (ndim <= 2): an integer drops its axis, a slice
             keeps it, one ellipsis expands, negative indices count from the end. One integer per
             axis gives a float; anything else gives a view that shares the memory.
    """
    #*************************************************************************************************

    cdef int64_t i, j
    cdef tuple r

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

        i += self.nd.shape[0]

      # end if

      if j < 0:

        j += self.nd.shape[1]

      # end if

      if i < 0 or i >= self.nd.shape[0] or j < 0 or j >= self.nd.shape[1]:

        raise IndexError("index ({}, {}) is out of bounds for a dmat of shape {}".format(
                         val[0], val[1], self.shape))

      # end if

      return (<double*>self.nd.data)[i*self.nd.strides[0] + j*self.nd.strides[1]]

    # end if

    r = self._key(val)

    if r[6] is None:

      return (<double*>self.nd.data)[<int64_t>r[0]*self.nd.strides[0] + <int64_t>r[3]*self.nd.strides[1]]

    # end if

    return self._view_rng(r)

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  def __setitem__(self, val, value):
    """
    PURPOSE: A[key] = value with NumPy's assignment rule (S1): the value (a real, a dmat or anything
             array_like) is broadcast to the shape of A[key]: trailing axes aligned, extent 1
             stretched, extra leading axes of extent 1 dropped. The right side is read as if copied
             first (S2: a[1:] = a[:-1] and a[::-1] = a work).
    """
    #*************************************************************************************************

    cdef ndarr_t dst
    cdef ndarr_t src
    cdef dmat V
    cdef tuple r
    cdef object shape
    cdef object values
    cdef double x
    cdef int status

    r = self._key(val)
    shape = r[6]

    if shape is None and type(value) in number_types:

      (<double*>self.nd.data)[<int64_t>r[0]*self.nd.strides[0] + <int64_t>r[3]*self.nd.strides[1]] = value

      return

    # end if

    nd_init_empty(&dst)
    nd_init_empty(&src)

    self._target(r, &dst)

    if type(value) in number_types:

      x = value

      with nogil:

        status = nd_fill(_nd_ctx, &dst, x)

      # end with

      _nd_status("dmat", status, &dst)

      return

    # end if

    if type(value) is dmat:

      V = value

    else:

      try:

        values = np.asarray(value, dtype=np.float64)

      except (TypeError, ValueError):

        raise IndexError("ERROR: Cant set item of type {0} in dmat object.".format(type(value))) from None

      # end try

      V = zeros(values.shape)
      V.to_numpy()[...] = values

    # end if

    assign_plan(V.shape, () if shape is None else shape)

    V._logical(&src)

    with nogil:

      status = nd_assign(_nd_ctx, &src, &dst)

    # end with

    _nd_status("dmat", status, &dst)

  #---------------------------------------------------------------------------------------------------


  #***************************************************************************************************
  def __neg__(self):
    """
    PURPOSE: Negation overload.
    """
    #*************************************************************************************************

    self._sync()
    cdef darr_t newmat = darr_neg(&self.arr)

    return _dmat_k(dmat.create(&newmat), self._lk)
  #---------------------------------------------------------------------------------------------------




  #***************************************************************************************************
  def __abs__(self):
    """
    PURPOSE: Absolute value overload (abs(self)).
    """
    #*************************************************************************************************

    # The C darr_abs calls the integer abs() (frozen C layer): NumPy does it.
    return array(np.abs(self.to_numpy()))

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  def __add__(self, other):
    """
    PURPOSE: Addition overload.
    """
    #*************************************************************************************************

    cdef darr_t res
    cdef dmat lhs,rhs
    cdef uint8_t kind = 0

    tlhs = type(self)
    trhs = type(other)

    if (tlhs == trhs):

      lhs = self
      rhs = other

      if not _dmat_same_shape(lhs, rhs):

        return _dmat_mixed(_op.add, lhs, rhs)

      # end if

      lhs._sync()
      rhs._sync()

      res = darr_sum_RR(&lhs.arr,&rhs.arr)
      kind = lhs._lk

    elif (tlhs in number_types):

      rhs = other
      kind = rhs._lk

      rhs._sync()
      res = darr_sum_rR(self, &rhs.arr)

    elif (trhs in number_types):

      lhs = self
      kind = lhs._lk

      lhs._sync()
      res = darr_sum_rR(other, &lhs.arr)

    else:

      return NotImplemented

    # end if

    return _dmat_k(dmat.create(&res), kind)

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
    cdef uint8_t kind = 0

    tlhs = type(self)
    trhs = type(other)

    if (tlhs == trhs):

      lhs = self
      rhs = other

      if not _dmat_same_shape(lhs, rhs):

        return _dmat_mixed(_op.sub, lhs, rhs)

      # end if

      lhs._sync()
      rhs._sync()

      res = darr_sub_RR(&lhs.arr,&rhs.arr)
      kind = lhs._lk

    elif (tlhs in number_types):

      rhs = other
      kind = rhs._lk

      rhs._sync()
      res = darr_sub_rR(self, &rhs.arr)

    elif (trhs in number_types):

      lhs = self
      kind = lhs._lk

      lhs._sync()
      res = darr_sub_Rr( &lhs.arr, other)

    else:

      return NotImplemented

    # end if

    return _dmat_k(dmat.create(&res), kind)

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
    cdef uint8_t kind = 0

    tlhs = type(self)
    trhs = type(other)

    if (tlhs == trhs):

      lhs = self
      rhs = other

      if not _dmat_same_shape(lhs, rhs):

        return _dmat_mixed(_op.mul, lhs, rhs)

      # end if

      lhs._sync()
      rhs._sync()

      res = darr_mul_RR(&lhs.arr,&rhs.arr)
      kind = lhs._lk

    elif (tlhs in number_types):

      rhs = other
      kind = rhs._lk

      rhs._sync()
      res = darr_mul_rR(self, &rhs.arr)

    elif (trhs in number_types):

      lhs = self
      kind = lhs._lk

      lhs._sync()
      res = darr_mul_rR(other, &lhs.arr)

    else:

      return NotImplemented

    # end if

    return _dmat_k(dmat.create(&res), kind)


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
    cdef uint8_t kind = 0

    tlhs = type(self)
    trhs = type(other)

    if (tlhs == trhs):

      lhs = self
      rhs = other

      if not _dmat_same_shape(lhs, rhs):

        return _dmat_mixed(_op.truediv, lhs, rhs)

      # end if

      lhs._sync()
      rhs._sync()

      res = darr_div_RR(&lhs.arr,&rhs.arr)
      kind = lhs._lk

    elif (tlhs in number_types):

      rhs = other
      kind = rhs._lk

      rhs._sync()
      res = darr_div_rR(self, &rhs.arr)

    elif (trhs in number_types):

      lhs = self
      kind = lhs._lk

      lhs._sync()
      res = darr_div_Rr( &lhs.arr, other)

    else:

      return NotImplemented

    # end if

    return _dmat_k(dmat.create(&res), kind)


  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  def __matmul__(self, other):
    """
    PURPOSE: Matrix multiplication overload (self @ other); the shape rules of dot (11.3).
    """
    #*************************************************************************************************

    if type(self) is dmat and type(other) is dmat:

      return _dmat_dot(self, other, None)

    # end if

    return NotImplemented

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  cpdef np.ndarray to_numpy(self):
    """
    PURPOSE: Interface to numpy representation: a writable zero-copy view of the logical shape.
    """
    #*************************************************************************************************

    cdef ndarr_t lv

    self._logical(&lv)

    return nd_to_numpy(&lv, 1)

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

    return _dmat_k(dmat.create(&res), self._lk)

  #---------------------------------------------------------------------------------------------------

  #***************************************************************************************************
  cpdef set(self, object rhs):
    """
    PURPOSE: ``A.set(rhs)`` is ``A[...] = rhs`` (rule S1c): rhs (a number, a dmat, an array_like)
             broadcasts to the shape of A as NumPy does.
    """
    #*************************************************************************************************

    cdef int status
    cdef coeff_t val

    if type(rhs) is float or type(rhs) is int:

      # The FEM loops call set(0) per element: fill directly.
      val = rhs

      with nogil:

        status = nd_fill(_nd_ctx, &self.nd, val)

      # end with

      _nd_status("dmat", status, &self.nd)

      return

    # end if

    self[...] = rhs

  #---------------------------------------------------------------------------------------------------


# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
# :::::::::::::::::::::::::::::::::::: END OF CLASS DMAT :::::::::::::::::::::::::::::::::::::::::::::
# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::


#-----------------------------------------------------------------------------------------------------
# *****************************************************************************************************
cdef inline bint _dmat_same_shape(dmat a, dmat b):
  """
  PURPOSE:      True when two dmat have the same logical shape (and so the same 2-D struct).
  """
  #***************************************************************************************************

  return a._lk == b._lk and a.nd.shape[0] == b.nd.shape[0] and a.nd.shape[1] == b.nd.shape[1]

#-----------------------------------------------------------------------------------------------------

# *****************************************************************************************************
cdef inline dmat _dmat_k(dmat d, uint8_t lk):
  """
  PURPOSE:      Give a freshly created dmat its logical shape kind (0: 2-D, 1: 1-D, 2: 0-D) and return it.
  """
  #***************************************************************************************************

  d._lk = lk

  return d

#-----------------------------------------------------------------------------------------------------

# *****************************************************************************************************
def _dmat_mixed(object op, dmat lhs, dmat rhs):
  """
  PURPOSE:      An elementwise operation between two dmat of different logical shapes. A matrix with a
                single element acts as a scalar; the result has NumPy's broadcast shape of the two
                operands ((4,) + (1, 1) is (1, 4)). Anything else is an error: a 2-D C struct broadcasts
                only between equal shapes and single elements (11.2).
  """
  #***************************************************************************************************

  cdef bint lone = lhs.nd.shape[0]*lhs.nd.shape[1] == 1
  cdef bint rone = rhs.nd.shape[0]*rhs.nd.shape[1] == 1

  if not lone and not rone:

    raise ValueError("operands have different shapes {} and {} and could not be broadcast together: "
                     "broadcasting between shapes is supported by pyoti.dense only".format(
                     lhs.shape, rhs.shape))

  # end if

  shape = tuple(np.broadcast_shapes(lhs.shape, rhs.shape))

  if len(shape) > 2:

    raise ValueError("pyoti.real arrays have at most 2 dimensions: the result of operands of shapes "
                     "{} and {} would have shape {}".format(lhs.shape, rhs.shape, shape))

  # end if

  if lone and (not rone or lhs._lk >= rhs._lk):

    res = op((<double*>lhs.nd.data)[0], rhs)

  else:

    res = op(lhs, (<double*>rhs.nd.data)[0])

  # end if

  if res.shape != shape:

    res = res.reshape(shape)

  # end if

  return res

#-----------------------------------------------------------------------------------------------------






# *****************************************************************************************************
cdef dmat _dmat_out_shape(object out, tuple shape):
  """
  PURPOSE:      The holder of an out= argument for a result of logical shape `shape` (rule S1b): out
                itself when its shape is the result shape, or a zero-copy dmat of the result shape over
                out's memory when out's shape is the result shape with extra leading axes of extent 1
                (writes through it reach out; the caller still returns the original out).
  """
  #***************************************************************************************************

  cdef dmat O
  cdef ndarr_t tmp
  cdef ndarr_t kept
  cdef int64_t dims[2]
  cdef int64_t nr, nc
  cdef uint8_t lk
  cdef tuple oshape

  if type(out) is not dmat:

    raise TypeError("out must be a dmat, got {}".format(type(out).__name__))

  # end if

  O = out
  oshape = O.shape

  if oshape == shape:

    return O

  # end if

  lead = len(oshape) - len(shape)

  if lead < 1 or oshape[lead:] != shape or any(n != 1 for n in oshape[:lead]):

    raise ValueError("out has shape {}, expected {}".format(oshape, shape))

  # end if

  # Same elements, fewer leading unit axes: the result's stored 2-D form over out's memory.
  lk = 2 - len(shape)
  nr = 1 if lk == 2 else (shape[0])
  nc = shape[1] if lk == 0 else 1
  dims[0] = nr
  dims[1] = nc

  nd_init_empty(&tmp)
  nd_init_empty(&kept)

  try:

    _nd_status("dmat", nd_view_reshape(&O.nd, 2, dims, ND_LAYOUT_C, &tmp), &O.nd)
    _nd_status("dmat", nd_view_retain(&tmp, &kept), &O.nd)

    return dmat.create_view(&kept, lk)

  finally:

    nd_release(&kept)

  # end try

#-----------------------------------------------------------------------------------------------------

# *****************************************************************************************************
cdef dmat _dmat_out(object out, dmat like):
  """
  PURPOSE:      The holder of out= for a result that has the shape of `like` (see _dmat_out_shape).
  """
  #***************************************************************************************************

  return _dmat_out_shape(out, like.shape)

#-----------------------------------------------------------------------------------------------------
