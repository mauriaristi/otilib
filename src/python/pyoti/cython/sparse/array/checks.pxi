# Shape validation for array operations.
#
# The C core checks array dimensions too, but on failure it prints a message and calls exit(),
# which terminates the Python interpreter. These helpers validate the shapes in the bindings
# first and raise ValueError instead.


#*****************************************************************************************************
cdef object _array_shape(object obj):
  """
  PURPOSE:  Shape of an array operand, or None for scalars and other non-array objects.
  """
  #***************************************************************************************************

  tobj = type(obj)

  if tobj is matso or tobj is matsofe or tobj is dmat or tobj is csr_matrix:
    return obj.shape
  # end if

  return None

#-----------------------------------------------------------------------------------------------------


#*****************************************************************************************************
cdef object _array_phys(object obj):
  """
  PURPOSE:  (nrows, ncols) of the 2-D struct of an array operand (a 1-D (n,) is n x 1, a 0-D () is 1 x 1),
            or None for scalars and other non-array objects.
  """
  #***************************************************************************************************

  cdef matso O
  cdef dmat  R

  tobj = type(obj)

  if tobj is matso:

    O = obj

    return (O.arr.nrows, O.arr.ncols)

  elif tobj is dmat:

    R = obj

    return (R.nd.shape[0], R.nd.shape[1])

  elif tobj is matsofe or tobj is csr_matrix:

    return obj.shape

  # end if

  return None

#-----------------------------------------------------------------------------------------------------


#*****************************************************************************************************
cdef object _array_nip(object obj):
  """
  PURPOSE:  Number of integration points of a Gauss (FE) operand, or None for other objects.
  """
  #***************************************************************************************************

  tobj = type(obj)

  if tobj is matsofe or tobj is sotife:
    return obj.nip
  # end if

  return None

#-----------------------------------------------------------------------------------------------------


#*****************************************************************************************************
cdef object _check_nip(str op, object lhs, object rhs):
  """
  PURPOSE:  Check that two Gauss (FE) objects have the same number of integration points. Non-FE
            objects broadcast over the integration points.
  """
  #***************************************************************************************************

  cdef object lnip = _array_nip(lhs)
  cdef object rnip = _array_nip(rhs)

  if lnip is not None and rnip is not None and lnip != rnip:
    raise ValueError("{0}: operands have different numbers of integration points ({1} and {2})."
                     .format(op, lnip, rnip))
  # end if

  return None

#-----------------------------------------------------------------------------------------------------


#*****************************************************************************************************
cdef object _check_out_shape(str op, object out, object shape):
  """
  PURPOSE:  Check that an out= holder matches the shape of the result (shape None: scalar result).
  """
  #***************************************************************************************************

  cdef object oshape

  if out is None:
    return None
  # end if

  oshape = _array_shape(out)

  # Rule S1b: an out whose shape is the result shape with extra leading axes of extent 1 is accepted
  # (the caller works on a view of out without those axes, see _out_matso).
  if oshape is not None and shape is not None and len(oshape) > len(shape) and (
      oshape[len(oshape) - len(shape):] == shape and
      all(n == 1 for n in oshape[:len(oshape) - len(shape)])):

    return None

  # end if

  if oshape != shape:


    if shape is None:
      raise ValueError("{0}: out must be a scalar holder, got an array of shape {1}.".format(
        op, oshape))
    elif oshape is None:
      raise ValueError("{0}: out must be an array of shape {1}, got {2}.".format(
        op, shape, type(out).__name__))
    else:
      raise ValueError("{0}: out has shape {1}, expected {2}.".format(op, oshape, shape))
    # end if

  # end if

  return None

#-----------------------------------------------------------------------------------------------------


#*****************************************************************************************************
cdef object _check_out_phys(str op, object out, object shape):
  """
  PURPOSE:  Check that an out= holder of a matrix product is stored as the 2-D struct of the result.
  """
  #***************************************************************************************************

  cdef object oshape = _array_phys(out)

  if out is not None and oshape != shape:

    if oshape is None:
      raise ValueError("{0}: out must be an array of shape {1}, got {2}.".format(
        op, shape, type(out).__name__))
    # end if

    raise ValueError("{0}: out has shape {1}, expected {2}.".format(op, oshape, shape))

  # end if

  return None

#-----------------------------------------------------------------------------------------------------


#*****************************************************************************************************
cdef object _check_elementwise(str op, object lhs, object rhs, object out = None,
                               bint allow_single = False):
  """
  PURPOSE:  Check the operands (and out=) of an elementwise operation; scalars broadcast. A 2-D C struct
            broadcasts only between equal logical shapes and scalars (11.2); with allow_single an array
            with a single element also acts as a scalar (the operators handle it).
  """
  #***************************************************************************************************

  cdef object lshape = _array_shape(lhs)
  cdef object rshape = _array_shape(rhs)
  cdef object pl, pr

  if lshape is not None and rshape is not None and lshape != rshape:

    pl = _array_phys(lhs)
    pr = _array_phys(rhs)

    if not (allow_single and (pl[0]*pl[1] == 1 or pr[0]*pr[1] == 1)):

      raise ValueError("{0}: operands have different shapes {1} and {2} and could not be broadcast "
                       "together: broadcasting between shapes is supported by pyoti.dense only".format(
                       op, lshape, rshape))

    # end if

  # end if


  if out is not None and type(lhs) in number_types and type(rhs) in number_types:
    raise TypeError("{0}: the result of two reals is a float; out= is not supported.".format(op))
  # end if

  _check_nip(op, lhs, rhs)
  _check_out_shape(op, out, lshape if lshape is not None else rshape)

  if out is not None:
    _check_nip(op, lhs, out)
    _check_nip(op, rhs, out)
  # end if

  return None

#-----------------------------------------------------------------------------------------------------


#*****************************************************************************************************
cdef object _check_matmul(str op, object lhs, object rhs, object out = None):
  """
  PURPOSE:  Check the operands (and out=) of a matrix product lhs @ rhs.
  """
  #***************************************************************************************************

  cdef object lshape = _array_phys(lhs)
  cdef object rshape = _array_phys(rhs)

  if lshape is None or rshape is None:
    _check_nip(op, lhs, rhs)
    return None
  # end if

  if lshape[1] != rshape[0]:
    raise ValueError("{0}: shapes {1} and {2} are not aligned ({3} != {4}).".format(
      op, lshape, rshape, lshape[1], rshape[0]))
  # end if

  _check_out_phys(op, out, (lshape[0], rshape[1]))
  _check_nip(op, lhs, rhs)
  _check_nip(op, lhs, out)
  _check_nip(op, rhs, out)

  return None

#-----------------------------------------------------------------------------------------------------


#*****************************************************************************************************
cdef object _check_same_size(str op, object lhs, object rhs, object out = None):
  """
  PURPOSE:  Check that two array operands hold the same number of elements (e.g. dot_product,
            which pairs the flattened arrays, so (1, n) and (n, 1) are compatible).
  """
  #***************************************************************************************************

  cdef object lshape = _array_phys(lhs)
  cdef object rshape = _array_phys(rhs)

  if lshape is not None and rshape is not None and (
      lshape[0] * lshape[1] != rshape[0] * rshape[1]):
    raise ValueError("{0}: operands have different sizes, shapes {1} and {2}.".format(
      op, lshape, rshape))
  # end if

  _check_nip(op, lhs, rhs)
  _check_nip(op, lhs, out)
  _check_nip(op, rhs, out)

  return None

#-----------------------------------------------------------------------------------------------------


#*****************************************************************************************************
cdef object _check_math_out(str op, object val, object out):
  """
  PURPOSE:  Check the out= holder of an elementwise function of one operand.
  """
  #***************************************************************************************************

  if out is None:
    return None
  # end if

  if type(val) in number_types:
    raise TypeError("{0}: the result for a real input is a float; out= is not supported.".format(op))
  # end if

  _check_out_shape(op, out, _array_shape(val))
  _check_nip(op, val, out)

  return None

#-----------------------------------------------------------------------------------------------------


#*****************************************************************************************************
cdef object _check_slice_assign(object value, int64_t starti, int64_t stopi, int64_t stepi,
                                int64_t startj, int64_t stopj, int64_t stepj):
  """
  PURPOSE:  Check that an array assigned to a slice has exactly the slice's shape.
  """
  #***************************************************************************************************

  cdef object shape = (len(range(starti, stopi, stepi)), len(range(startj, stopj, stepj)))

  if value.shape != shape:
    raise ValueError("slice assignment: value has shape {0}, the slice has shape {1}.".format(
      value.shape, shape))
  # end if

  return None

#-----------------------------------------------------------------------------------------------------


#*****************************************************************************************************
cdef object _check_square(str op, object arr):
  """
  PURPOSE:  Check that an array operand is square.
  """
  #***************************************************************************************************

  cdef object shape = _array_phys(arr)
  cdef uint8_t lk = _lkind(arr)

  # NumPy's own texts and type (numpy.linalg.LinAlgError is a ValueError subclass): one table for the
  # four algebras (build-orch/w4-notes/py-ss.md, fix round 2).
  if lk == 2:
    raise np.linalg.LinAlgError("0-dimensional array given. Array must be at least two-dimensional")
  elif lk == 1:
    raise np.linalg.LinAlgError("1-dimensional array given. Array must be at least two-dimensional")
  elif shape is not None and shape[0] != shape[1]:
    raise np.linalg.LinAlgError("Last 2 dimensions of the array must be square")
  # end if

  return None

#-----------------------------------------------------------------------------------------------------


#*****************************************************************************************************
cdef matso _out_matso(object out, matso like):
  """
  PURPOSE:  The holder of an out= argument for a result that has the shape of `like` (rule S1b): out
            itself when its shape is the result shape, or a matso of the result shape over out's
            elements (a non-owning header) when out's shape is the result shape with extra leading axes
            of extent 1. The caller still returns the original out.
  """
  #***************************************************************************************************

  cdef matso O
  cdef arrso_t hdr

  if type(out) is not matso:

    raise TypeError("out must be a matso, got {}".format(type(out).__name__))

  # end if

  O = out

  if O._lk == like._lk and O.arr.nrows == like.arr.nrows and O.arr.ncols == like.arr.ncols:

    return O

  # end if

  _check_out_shape("out", out, like.shape)

  hdr = O.arr
  hdr.nrows = like.arr.nrows
  hdr.ncols = like.arr.ncols

  return _sk(matso.create(&hdr, 0), like._lk)

#-----------------------------------------------------------------------------------------------------


#*****************************************************************************************************
cdef sotinum _vec_item(matso a, uint64_t i):
  """
  PURPOSE:  Element i of a vector given as a 1-D (n,) or a (n, 1) matso (both are stored as a column): an
            OTI scalar copy.
  """
  #***************************************************************************************************

  cdef sotinum_t ores

  ores = arrso_get_item_i( &a.arr, i, dhl)

  return sotinum.create(&ores, FLAGS = 0).copy()

#-----------------------------------------------------------------------------------------------------
