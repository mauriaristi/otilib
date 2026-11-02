# Creators: e, zero, one, number, zeros, ones, eye, array. Owner: WP8a.
#
# Calls follow pyoti.sparse. The nbases argument is a capacity hint of the sparse types: it is
# accepted and has no effect, since dense numbers grow their active bases on demand. A positive nip
# builds a Gauss-point type through the hooks _fe_zeros / _fe_scalar (dense/gauss/base.pxi). Every
# order is validated to 0..150 (_MAXORDER_OTI).


# ********************************************************************************************************
cdef void _check_creation(object nbases, object order, object nip) except *:
    """
    Validate the common arguments of the creators.

    Parameters
    ----------
    nbases : int
        Capacity hint of the sparse API; must be nonnegative.
    order : int
        Truncation order, 0 to 150.
    nip : int
        Number of integration points, nonnegative.
    """

    if nbases < 0 or nip < 0:

        raise ValueError("nbases and nip must be nonnegative")

    # end if

    _check_order(order)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def e(hum_dir, nbases=0, order=0, nip=0):
    """
    Create a dense number with value 1 along an imaginary direction.

    Same call as ``pyoti.sparse.e``. The number is dense over the bases 1..max(direction) and its
    truncation order is the larger of ``order`` and the order of the direction, so the coefficient
    is never dropped.

    Parameters
    ----------
    hum_dir : int or list or tuple
        Direction in any format ``pyoti.sparse`` accepts (a base label, a list of bases, exponent
        pairs such as ``[[1, 2]]``), or a ``rawdir(index, order)``.
    nbases : int
        Accepted for compatibility with ``pyoti.sparse.e``; it has no effect.
    order : int
        Minimum truncation order, 0 to 150.
    nip : int
        Number of integration points. With ``nip > 0`` the Gauss-point scalar is built by the
        ``_fe_scalar`` hook.

    Returns
    -------
    otinum
        The imaginary unit along ``hum_dir``.

    Examples
    --------
    >>> x = e([1, 2], order=3)
    >>> x.get_im([1, 2]), x.order, x.active_bases
    (1.0, 3, (1, 2))
    """

    cdef tuple pair
    cdef otinum unit = otinum.__new__(otinum)

    _check_creation(nbases, order, nip)
    pair = _direction(hum_dir)
    _status("e", oti_e_to(pair[0], pair[1], order, &unit.num))

    if nip != 0:

        return _fe_scalar(unit, [], unit.num.trc_order, nip)

    # end if

    return unit

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def number(num, nbases=0, order=0, nip=0):
    """
    Create a scalar with real value ``num`` and no imaginary coefficients.

    Parameters
    ----------
    num : float
        Real value.
    nbases : int
        Capacity hint of the sparse API; no effect here.
    order : int
        Truncation order.
    nip : int
        Number of integration points; a positive value builds a Gauss-point scalar.

    Returns
    -------
    otinum
        The scalar.
    """

    _check_creation(nbases, order, nip)

    if nip != 0:

        return _fe_scalar(float(num), [], order, nip)

    # end if

    return otinum(float(num), order=order)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def zero(nbases=0, order=0, nip=0):
    """
    Create a scalar with value 0.

    Parameters
    ----------
    nbases : int
        Capacity hint of the sparse API; no effect here.
    order : int
        Truncation order.
    nip : int
        Number of integration points; a positive value builds a Gauss-point scalar.

    Returns
    -------
    otinum
        Zero.
    """

    return number(0.0, nbases, order, nip)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def one(nbases=0, order=0, nip=0):
    """
    Create a scalar with value 1.

    Parameters
    ----------
    nbases : int
        Capacity hint of the sparse API; no effect here.
    order : int
        Truncation order.
    nip : int
        Number of integration points; a positive value builds a Gauss-point scalar.

    Returns
    -------
    otinum
        One.
    """

    return number(1.0, nbases, order, nip)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef omat _soa_zeros(tuple dims, bases_t nact, ord_t order):
    """
    Create a zero SoA matrix over the bases 1..nact.

    Parameters
    ----------
    dims : tuple of int
        Rows and columns.
    nact : int
        Number of active bases.
    order : int
        Truncation order.

    Returns
    -------
    omat
        Zero matrix.
    """

    cdef oarr_t result = oarr_init()

    _soa_ok("zeros", oarr_zeros_to(nact, dims[0], dims[1], order, &result), &result)
    return omat.wrap(result)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def zeros(shape_in, nbases=0, order=0, nip=0, bases=()):
    """
    Create a zero SoA matrix, optionally with a given number of active bases.

    The argument order matches ``pyoti.sparse.zeros``; ``bases`` is the dense extra: only its
    largest label matters, since the matrix is dense over the bases 1..max(bases) (no active bases
    when it is empty).

    Parameters
    ----------
    shape_in : int or tuple of int
        An int or a 1-tuple is a column vector; otherwise (rows, columns).
    nbases : int
        Capacity hint of the sparse API; no effect here.
    order : int
        Truncation order.
    nip : int
        Number of integration points; a positive value builds a Gauss-point array.
    bases : iterable of int
        Base labels; the matrix is dense over 1..max(bases).

    Returns
    -------
    omat
        Zero matrix.
    """

    cdef tuple dims

    # Fast path: the common (rows, columns) call without bases.
    if nip == 0 and type(shape_in) is tuple and len(<tuple>shape_in) == 2 and (
        type(bases) is tuple and len(<tuple>bases) == 0
    ):

        dims = <tuple>shape_in

        if type(dims[0]) is int and type(dims[1]) is int and (
            dims[0] >= 0 and dims[1] >= 0 and 0 <= order <= _MAXORDER_OTI and nbases >= 0
        ):

            return _soa_zeros(dims, 0, order)

        # end if

    # end if

    dims = _process_shape(shape_in)
    _check_creation(nbases, order, nip)

    if nip != 0:

        return _fe_zeros(dims, list(bases), order, nip)

    # end if

    return _soa_zeros(dims, _nact_of(bases), order)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def ones(shape_in, nbases=0, order=0, nip=0):
    """
    Create a SoA matrix whose elements are all 1.

    Parameters
    ----------
    shape_in : int or tuple of int
        An int or a 1-tuple is a column vector; otherwise (rows, columns).
    nbases : int
        Capacity hint of the sparse API; no effect here.
    order : int
        Truncation order.
    nip : int
        Number of integration points; a positive value builds a Gauss-point array.

    Returns
    -------
    omat
        Matrix of ones.
    """

    cdef tuple dims = _process_shape(shape_in)
    cdef object result
    cdef np.ndarray[np.float64_t, ndim=2, mode="fortran"] data
    cdef oarr_t native = oarr_init()
    cdef uint64_t i, j

    _check_creation(nbases, order, nip)

    if nip != 0:

        result = _fe_zeros(dims, [], order, nip)

        for i in range(dims[0]):

            for j in range(dims[1]):

                result[i, j] = 1.0

            # end for

        # end for

        return result

    # end if

    data = np.ones(dims, dtype=np.float64, order="F")
    _soa_ok("ones", oarr_from_real_to(<coeff_t *>data.data if data.size > 0 else NULL, dims[0],
                                      dims[1], order, &native), &native)
    return omat.wrap(native)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def eye(size, nbases=0, order=0, nip=0):
    """
    Create an identity matrix of shape (size, size).

    Parameters
    ----------
    size : int
        Dimension.
    nbases : int
        Capacity hint of the sparse API; no effect here.
    order : int
        Truncation order.
    nip : int
        Number of integration points; a positive value builds a Gauss-point array.

    Returns
    -------
    omat
        Identity matrix.
    """

    cdef object result
    cdef oarr_t native = oarr_init()
    cdef uint64_t i

    _check_creation(nbases, order, nip)

    if size < 0:

        raise ValueError("size must be nonnegative")

    # end if

    if nip != 0:

        result = _fe_zeros((size, size), [], order, nip)

        for i in range(size):

            result[i, i] = 1.0

        # end for

        return result

    # end if

    _soa_ok("eye", oarr_eye_to(size, order, &native), &native)
    return omat.wrap(native)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def array(arr, nbases=0, order=0, nip=0):
    """
    Create a SoA matrix from a scalar, a list or a NumPy array of reals and OTI scalars.

    A scalar gives a 1 x 1 matrix and a 1-D input gives a column; the truncation order is the
    larger of ``order`` and the orders of the elements. A 3-D input has integration points on its
    last axis and needs ``nip`` types (the Gauss-point hooks).

    Parameters
    ----------
    arr : object
        Real or OTI scalar, or nested lists / arrays of them. An existing array is copied.
    nbases : int
        Capacity hint of the sparse API; no effect here.
    order : int
        Minimum truncation order.
    nip : int
        Number of integration points; a positive value builds a Gauss-point array.

    Returns
    -------
    omat
        The matrix.
    """

    cdef np.ndarray values
    cdef object result
    cdef object dims
    cdef oarr_t native
    cdef np.ndarray[np.float64_t, ndim=2, mode="fortran"] data
    cdef uint64_t i, j, k

    _check_creation(nbases, order, nip)

    if nip == 0:

        result = _array_from_lists(arr, order)

        if result is not None:

            return result

        # end if

    # end if

    if isinstance(arr, (omat, arro)):

        return arr.copy()

    # end if

    if isinstance(arr, matso):

        native = oarr_init()
        _soa_ok("array", oarr_from_arrso_to(&(<matso>arr).arr, &native, _dhl), &native)
        return omat.wrap(native)

    # end if

    values = np.array(arr, dtype=object)

    if values.ndim == 0:

        dims = (1, 1)
        values = values.reshape(1, 1)

    elif values.ndim == 1:

        dims = (values.shape[0], 1)
        values = values.reshape(values.shape[0], 1)

    elif values.ndim == 2 or (values.ndim == 3 and nip == 0):

        dims = (values.shape[0], values.shape[1])

    else:

        raise ValueError("Error: Can not create an array of such dimensions.")

    # end if

    if values.ndim == 3:

        nip = values.shape[2]

    # end if

    if nip != 0:

        result = _fe_zeros(dims, [], order, nip)

        for i in range(dims[0]):

            for j in range(dims[1]):

                if values.ndim == 3:

                    for k in range(nip):

                        result.set_ijk(values[i, j, k], i, j, k)

                    # end for

                else:

                    result[i, j] = values[i, j]

                # end if

            # end for

        # end for

        return result

    # end if

    if all(isinstance(item, Real) for item in values.ravel()):

        data = np.asfortranarray(values.astype(np.float64))
        native = oarr_init()
        _soa_ok("array", oarr_from_real_to(<coeff_t *>data.data if data.size > 0 else NULL,
                                           dims[0], dims[1], order, &native), &native)
        return omat.wrap(native)

    # end if

    result = _soa_zeros((dims[0], dims[1]), 0, order)

    for i in range(dims[0]):

        for j in range(dims[1]):

            result[i, j] = values[i, j]

        # end for

    # end for

    return result

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef object _array_from_lists(object arr, ord_t order):
    """
    Build a SoA matrix straight from a (nested) list of reals and OTI scalars.

    Parameters
    ----------
    arr : list or tuple
        A list of numbers (a column) or a list of equally long lists of numbers (a matrix).
    order : int
        Minimum truncation order.

    Returns
    -------
    omat or None
        The matrix, or None when the input is not such a list (the general path then handles it).
    """

    cdef Py_ssize_t nr, nc, i, j
    cdef bint nested
    cdef ord_t top = order
    cdef object row, item
    cdef type kind
    cdef omat result
    cdef otinum scalar
    cdef object rows

    if not isinstance(arr, (list, tuple)) or len(arr) == 0:

        return None

    # end if

    nr = len(arr)
    nested = isinstance(arr[0], (list, tuple))
    nc = len(arr[0]) if nested else 1

    if nc == 0:

        return None

    # end if

    rows = arr

    for i in range(nr):

        row = rows[i]

        if nested:

            if not isinstance(row, (list, tuple)) or len(row) != nc:

                return None

            # end if

        # end if

        for j in range(nc):

            item = row[j] if nested else row
            kind = type(item)

            if kind is float or kind is int:

                continue

            # end if

            if kind is otinum:

                if (<otinum>item).num.trc_order > top:

                    top = (<otinum>item).num.trc_order

                # end if

            elif isinstance(item, Real):

                continue

            else:

                return None

            # end if

        # end for

    # end for

    result = _soa_zeros((nr, nc), 0, top)

    for i in range(nr):

        row = rows[i]

        for j in range(nc):

            item = row[j] if nested else row

            if type(item) is otinum:

                scalar = item
                _status("array", oarr_set_item(&scalar.num, i, j, &result.arr))

            else:

                result.arr.p_data[i + j * nr] = item

            # end if

        # end for

    # end for

    return result

# end function
# --------------------------------------------------------------------------------------------------------
