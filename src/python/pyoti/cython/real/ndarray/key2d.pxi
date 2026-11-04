#-----------------------------------------------------------------------------------------------------
# NumPy index keys over the 2-D C structs of the 2.0.0 break (PLAN-ndarray-contracts.md 11.1, 11.3,
# 11.5; PLAN-ndarray.md Phase 7b).
#
# dmat, matso and the semi-sparse AoS / SoA types keep a 2-D C struct (nrows x ncols) and carry a
# LOGICAL shape of ndim 0, 1 or 2: a 1-D (n,) array is stored as n x 1, a 0-D () array as 1 x 1.
# These helpers are shared by every such type (cimport pyoti.real; declared in real/utils.pxd):
#
#   key2d(key, ndim, d0, d1, modname)   a NumPy basic key on the logical shape -> the rows / columns of
#                                       the 2-D struct it selects, and the logical result shape.
#   assign_plan(vshape, tshape)         how a value of shape vshape fills a target of shape tshape
#                                       (NumPy's assignment broadcasting, rule S1).
#-----------------------------------------------------------------------------------------------------


_ASSIGN_MSG = "slice assignment: could not broadcast input array from shape {} into shape {}"


#*****************************************************************************************************
cpdef tuple key2d(object key, int ndim, int64_t d0, int64_t d1, str modname = "pyoti"):
  """
  PURPOSE:      Resolve a NumPy basic index key on an array of logical ndim 0, 1 or 2.

  PARAMETERS:   key      The key (what __getitem__ / __setitem__ received).
                ndim     Logical ndim of the array: 0, 1 or 2.
                d0, d1   Extents of the logical axes 0 and 1 (d1 is not used when ndim < 2).
                modname  Name used in the rank-limit message (e.g. "pyoti.sparse").

  RETURNS:      (rstart, rstop, rstep, cstart, cstop, cstep, shape) where the ranges select rows and
                columns of the 2-D C struct (slice.indices normalization; an integer is (i, i + 1, 1);
                an axis the key does not have is (0, 1, 1)), and shape is the logical shape of the
                result: a tuple of ndim 0, 1 or 2, or None when the key is one integer per axis (the
                result is a scalar element, never a 0-D array).

  RAISES:       ValueError for None / np.newaxis (the rank limit of 2, 11.1), IndexError for a float,
                a string, an array / list (advanced indexing is not supported by these types), a
                boolean, too many indices, a second ellipsis or an integer out of range.
  """
  #***************************************************************************************************

  cdef list items
  cdef list full = []
  cdef list rng  = [(0, 1, 1), (0, 1, 1)]
  cdef list shape = []
  cdef int64_t ext[2]
  cdef int64_t start, stop, step, idx, n
  cdef object pstart, pstop, pstep
  cdef Py_ssize_t nell = 0
  cdef Py_ssize_t nidx = 0
  cdef Py_ssize_t k, ax
  cdef bint has_slice = False
  cdef object it

  ext[0] = d0
  ext[1] = d1

  if type(key) is tuple:

    items = list(key)

  else:

    items = [key]

  # end if

  for it in items:

    if it is None:

      raise ValueError("{} arrays have at most 2 dimensions".format(modname))

    elif it is Ellipsis:

      nell += 1

    else:

      nidx += 1

    # end if

  # end for

  if nell > 1:

    raise IndexError("an index can only have a single ellipsis ('...')")

  # end if

  if nidx > ndim:

    raise IndexError("too many indices for array: array is {}-dimensional, but {} were indexed".format(
                     ndim, nidx))

  # end if

  # Expand the ellipsis (or an implicit trailing one) into full slices.
  for it in items:

    if it is Ellipsis:

      for k in range(ndim - nidx):

        full.append(slice(None, None, None))

      # end for

    else:

      full.append(it)

    # end if

  # end for

  if nell == 0:

    for k in range(ndim - nidx):

      full.append(slice(None, None, None))

    # end for

  # end if

  for ax in range(ndim):

    it = full[ax]

    if type(it) is slice:

      # slice.indices keeps a step of any size as a Python int (NumPy clips it): narrow to int64 only
      # after the size is known. A range of two or more elements has |step| < the extent.
      pstart, pstop, pstep = it.indices(ext[ax])
      n = len(range(pstart, pstop, pstep))

      if n == 0:

        # An empty range is always (0, 0, 1): the C slice_size() of the frozen sparse / semi-sparse
        # layers computes a size of 1 for an empty range such as (0, 0, 2).
        start = 0
        stop  = 0
        step  = 1

      elif n == 1:

        # One element: any step selects it. The C layers compute with the negation of the step, so a
        # step such as -2**63 never reaches them.
        start = pstart
        stop  = start + 1
        step  = 1

      else:

        start = pstart
        stop  = pstop
        step  = pstep

      # end if

      rng[ax] = (start, stop, step)
      shape.append(n)
      has_slice = True

    else:

      if isinstance(it, (bool, np.bool_)):

        raise IndexError("boolean indices are not supported by {} arrays".format(modname))

      # end if

      try:

        pstart = operator_index(it)

      except TypeError:

        raise IndexError("only integers, slices (`:`) and ellipsis (`...`) are valid indices "
                         "(got {})".format(type(it).__name__)) from None

      # end try

      # A Python int of any size: compared before it is narrowed (a huge index is out of bounds).
      if pstart < -ext[ax] or pstart >= ext[ax]:

        raise IndexError("index {} is out of bounds for axis {} with size {}".format(pstart, ax, ext[ax]))

      # end if

      idx = pstart

      if idx < 0:

        idx += ext[ax]

      # end if

      rng[ax] = (idx, idx + 1, 1)

    # end if

  # end for

  if nell == 0 and not has_slice:

    return (rng[0][0], rng[0][1], rng[0][2], rng[1][0], rng[1][1], rng[1][2], None)

  # end if

  return (rng[0][0], rng[0][1], rng[0][2], rng[1][0], rng[1][1], rng[1][2], tuple(shape))

#-----------------------------------------------------------------------------------------------------


#*****************************************************************************************************
cpdef tuple reshape_shape(object args, int64_t size, str modname = "pyoti"):
  """
  PURPOSE:      The target shape of reshape(*args) for an array of `size` elements within rank 2 (the
                reshape of matso and dmat copies, 11.4): reshape(3, 4), reshape((3, 4)), reshape(-1),
                reshape(()). One extent may be -1 (inferred).

  RAISES:       TypeError for a non-integer extent, ValueError for a negative extent other than -1, a
                shape of more than 2 dimensions or a size mismatch (NumPy's message).
  """
  #***************************************************************************************************

  cdef list dims
  cdef int64_t known = 1
  cdef int unknown = -1
  cdef int k

  if len(args) == 1 and isinstance(args[0], (tuple, list)):

    dims = [operator_index(n) for n in args[0]]

  else:

    dims = [operator_index(n) for n in args]

  # end if

  if len(dims) > 2:

    raise ValueError("{} arrays have at most 2 dimensions".format(modname))

  # end if

  for k in range(len(dims)):

    if dims[k] == -1:

      if unknown >= 0:

        raise ValueError("can only specify one unknown dimension")

      # end if

      unknown = k

    elif dims[k] < 0:

      raise ValueError("negative dimensions not allowed")

    else:

      known *= dims[k]

    # end if

  # end for

  if unknown >= 0:

    if known == 0 or size % known != 0:

      raise ValueError("cannot reshape array of size {} into shape {}".format(
                       size, tuple(dims)))

    # end if

    dims[unknown] = size // known

  elif known != size:

    raise ValueError("cannot reshape array of size {} into shape {}".format(size, tuple(dims)))

  # end if

  return tuple(dims)

#-----------------------------------------------------------------------------------------------------


#*****************************************************************************************************
cpdef int assign_plan(tuple vshape, tuple tshape) except -1:
  """
  PURPOSE:      How a value of logical shape vshape fills a target of logical shape tshape (rule S1:
                NumPy's rule, no OTI extension): trailing axes aligned, an extent of 1 stretches and
                extra leading axes of extent 1 are dropped.

  RETURNS:      0  same shape: copy the values in row-major order;
                1  the value has one element: broadcast it to the whole target;
                2  tshape is (a, b) and the value is a row, (b,) or (1, b): repeat it a times;
                3  tshape is (a, b) and the value is a column, (a, 1): repeat it b times.

  RAISES:       ValueError("slice assignment: could not broadcast input array from shape ... into
                shape ...").
  """
  #***************************************************************************************************

  cdef Py_ssize_t lv = len(vshape)
  cdef Py_ssize_t lt = len(tshape)
  cdef Py_ssize_t lead = 0
  cdef Py_ssize_t k
  cdef bint stretch0 = False
  cdef bint stretch1 = False
  cdef bint single = True
  cdef list v

  # Leading axes of extent 1 beyond the target's rank are dropped.
  while lv - lead > lt:

    if vshape[lead] != 1:

      raise ValueError(_ASSIGN_MSG.format(vshape, tshape))

    # end if

    lead += 1

  # end while

  v = list(vshape[lead:])

  # Right-align the value against the target.
  while len(v) < lt:

    v.insert(0, 1)

  # end while

  for k in range(lt):

    if v[k] == 1 and tshape[k] != 1:

      if k == 0:

        stretch0 = True

      else:

        stretch1 = True

      # end if

    elif v[k] != tshape[k]:

      raise ValueError(_ASSIGN_MSG.format(vshape, tshape))

    # end if

    if v[k] != 1:

      single = False

    # end if

  # end for

  if lt == 0 or single:

    return 1

  # end if

  if not (stretch0 or stretch1):

    return 0

  # end if

  if lt == 2 and stretch0 and not stretch1:

    return 2

  # end if

  if lt == 2 and stretch1 and not stretch0:

    return 3

  # end if

  raise ValueError(_ASSIGN_MSG.format(vshape, tshape))

#-----------------------------------------------------------------------------------------------------


#*****************************************************************************************************
cpdef object gauss_key(object key, int64_t nrows, int64_t ncols):
  """
  PURPOSE:      The key of a Gauss array ([] keeps the 1.x matrix rule, 11.8) with its integers made
                non-negative: negative indices count from the end in every algebra (2.0.0). Slices,
                other items and keys of other lengths are returned unchanged (the caller raises its
                own errors for them); an integer out of range is an IndexError.
  """
  #***************************************************************************************************

  cdef Py_ssize_t k
  cdef int64_t ext[2]
  cdef list items

  ext[0] = nrows
  ext[1] = ncols

  if type(key) is tuple:

    if len(key) != 2:

      return key

    # end if

    items = list(key)

    for k in range(2):

      items[k] = _gauss_item(items[k], ext[k])

    # end for

    return tuple(items)

  # end if

  return _gauss_item(key, nrows)

#-----------------------------------------------------------------------------------------------------


#*****************************************************************************************************
cdef object _gauss_item(object item, int64_t n):
  """
  PURPOSE:      An integer item made non-negative (bounds checked); anything else unchanged.
  """
  #***************************************************************************************************

  cdef int64_t idx

  if type(item) is slice or isinstance(item, (bool, np.bool_)):

    return item

  # end if

  try:

    idx = operator_index(item)

  except TypeError:

    return item

  # end try

  if idx < -n or idx >= n:

    raise IndexError("index {} is out of bounds for axis with size {}".format(idx, n))

  # end if

  return idx + n if idx < 0 else idx

#-----------------------------------------------------------------------------------------------------
