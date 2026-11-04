# Creators: e, zero, one, number, zeros, ones, eye, array.
#
# Calls follow pyoti.sparse; shapes follow NumPy (rule C1, 7b): an int or a 1-tuple gives a 1-D array,
# 1-D data a 1-D array, a scalar or () a 0-D array (ndim <= 2 until Phase 8). ``zeros(bases=)``
# reserves the labels (the view-stable layout) and ``nbases=K`` is capacity only: room for K labels is
# allocated but no label is reserved (decision A1). Scalar creators accept nbases and ignore it. A
# positive nip builds a Gauss-point type through the hooks _fe_zeros / _fe_scalar
# (semisparse/gauss/base.pxi), whose shapes keep the 1.x matrix rule (11.8).


# ********************************************************************************************************
cdef object _reserve_creation(object result, object nbases, object bases):
    """
    Apply the ``bases=`` labels and the ``nbases=`` capacity of an array creator.

    Parameters
    ----------
    result : oarrss
        Freshly created array (no view can exist yet).
    nbases : int
        Base capacity to allocate (no label is reserved).
    bases : iterable of int
        Labels to add to the active set.

    Returns
    -------
    oarrss
        ``result``.
    """

    cdef oarrss soa = result
    cdef list active = _bases(bases)
    cdef np.ndarray[np.uint16_t, ndim=1] labels

    if active:

        labels = np.asarray(active, dtype=np.uint16)
        _check_alloc(comb(len(set(active).union(soa.active_bases)) + soa.arr.trc_order,
                          soa.arr.trc_order) * soa.arr.size * 8)
        oarrss_add_bases(<bases_t *>labels.data, len(active), &soa.arr)

    # end if

    if nbases > soa.arr.cap_bases:

        if nbases > 65535:

            raise ValueError("nbases must be at most 65535")

        # end if

        _check_alloc(comb(nbases + soa.arr.trc_order, soa.arr.trc_order) * soa.arr.size * 8)
        oarrss_reserve(&soa.arr, nbases, soa.arr.nrows, soa.arr.ncols, soa.arr.trc_order)

    # end if

    return result

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef void _check_creation(object nbases, object order, object nip) except *:
    """
    Validate the common arguments of the creators.

    Parameters
    ----------
    nbases : int
        Capacity hint of the sparse API; must be nonnegative.
    order : int
        Truncation order, 0 to 255.
    nip : int
        Number of integration points, nonnegative.
    """

    if nbases < 0 or nip < 0:

        raise ValueError("nbases and nip must be nonnegative")

    # end if

    if order < 0 or order > 255:

        raise ValueError("order must be between 0 and 255")

    # end if

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def e(hum_dir, nbases=0, order=0, nip=0):
    """
    Create a semi-sparse number with value 1 along an imaginary direction.

    Same call as ``pyoti.sparse.e`` and the static modules' ``e``. The active set is the distinct
    bases of the direction, and the truncation order is the larger of ``order`` and the order of
    the direction, so the coefficient is never dropped.

    Parameters
    ----------
    hum_dir : int or list or tuple
        Direction in any format ``pyoti.sparse`` accepts (a base label, a list of bases, exponent
        pairs such as ``[[1, 2]]``), or a ``rawdir(index, order)``.
    nbases : int
        Accepted for compatibility with ``pyoti.sparse.e``; semi-sparse numbers grow their active
        set on demand, so it has no effect.
    order : int
        Minimum truncation order.
    nip : int
        Number of integration points. With ``nip > 0`` the Gauss-point scalar is built by the
        ``_fe_scalar`` hook.

    Returns
    -------
    ssotinum
        The imaginary unit along ``hum_dir``.

    Examples
    --------
    >>> x = e([1, 2], order=3)
    >>> x.get_im([1, 2]), x.order, x.active_bases
    (1.0, 3, (1, 2))
    """

    cdef tuple pair
    cdef ssotinum unit

    _check_creation(nbases, order, nip)
    pair = _direction(hum_dir)
    unit = ssotinum.wrap(ssoti_e(pair[0], pair[1], order))

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
    ssotinum
        The scalar.
    """

    _check_creation(nbases, order, nip)

    if nip != 0:

        return _fe_scalar(float(num), [], order, nip)

    # end if

    return ssotinum(float(num), order=order)

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
    ssotinum
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
    ssotinum
        One.
    """

    return number(1.0, nbases, order, nip)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def zeros(shape_in, nbases=0, order=0, nip=0, bases=()):
    """
    Create a zero SoA array, optionally over a given active basis set.

    The argument order matches ``pyoti.sparse.zeros``; ``bases`` is the semi-sparse extra.

    Parameters
    ----------
    shape_in : int or tuple of int
        An int or a 1-tuple gives a 1-D array, a 2-tuple a matrix and ``()`` a 0-D array
        (Gauss arrays, ``nip > 0``, keep the 1.x rule: an int is a column).
    nbases : int
        Base capacity (no label is reserved; use ``bases`` for that).
    order : int
        Truncation order.
    nip : int
        Number of integration points; a positive value builds a Gauss-point array.
    bases : iterable of int
        Strictly increasing global basis labels of the initial active set (reserved: assignments
        within them never relayout the array).

    Returns
    -------
    oarrss
        Zero array.
    """

    cdef tuple dims

    # Fast path: the common (rows, columns) call without a basis set.
    if nip == 0 and type(shape_in) is tuple and len(<tuple>shape_in) == 2 and (
        type(bases) is tuple and len(<tuple>bases) == 0
    ):

        dims = <tuple>shape_in

        if type(dims[0]) is int and type(dims[1]) is int and (
            dims[0] >= 0 and dims[1] >= 0 and 0 <= order <= 255 and nbases == 0
        ):

            return oarrss.wrap(oarrss_zeros(NULL, 0, dims[0], dims[1], order))

        # end if

    # end if

    _check_creation(nbases, order, nip)

    if nip != 0:

        return _fe_zeros(_process_shape(shape_in), list(bases), order, nip)

    # end if

    return _reserve_creation(oarrss.zeros(shape_in, bases=bases, order=order), nbases, ())

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def ones(shape_in, nbases=0, order=0, nip=0):
    """
    Create a SoA array whose elements are all 1.

    Parameters
    ----------
    shape_in : int or tuple of int
        Shape as in ``zeros`` (NumPy's rule; Gauss arrays keep the 1.x rule).
    nbases : int
        Base capacity (no label is reserved).
    order : int
        Truncation order.
    nip : int
        Number of integration points; a positive value builds a Gauss-point array.

    Returns
    -------
    oarrss
        Array of ones.
    """

    cdef tuple dims
    cdef object result
    cdef uint64_t i, j

    _check_creation(nbases, order, nip)

    if nip != 0:

        dims = _process_shape(shape_in)

        result = _fe_zeros(dims, [], order, nip)

        for i in range(dims[0]):

            for j in range(dims[1]):

                result[i, j] = 1.0

            # end for

        # end for

        return result

    # end if

    dims = _creator_dims(shape_in)
    _check_alloc(dims[1] * dims[2] * 8)
    result = oarrss.from_real(np.ones(_lshape(dims[0], dims[1], dims[2]), dtype=np.float64),
                              order=order)
    return _reserve_creation(result, nbases, ())

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
        Base capacity (no label is reserved).
    order : int
        Truncation order.
    nip : int
        Number of integration points; a positive value builds a Gauss-point array.

    Returns
    -------
    oarrss
        Identity matrix.
    """

    cdef object result
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

    _check_alloc(size * size * 8)
    return _reserve_creation(oarrss.wrap(oarrss_eye(size, order)), nbases, ())

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def array(arr, nbases=0, order=0, nip=0):
    """
    Create a SoA array from a scalar, a list or a NumPy array of reals and OTI scalars.

    Shapes follow NumPy (rule C1): a scalar gives a 0-D array, 1-D input a 1-D array and nested
    lists their nesting depth (at most 2). The truncation order is the larger of ``order`` and the
    orders of the elements. A 3-D input has integration points on its last axis and builds a
    Gauss-point array (the Gauss hooks, whose shapes keep the 1.x matrix rule).

    Parameters
    ----------
    arr : object
        Real or OTI scalar, or nested lists / arrays of them. An existing array is copied.
    nbases : int
        Base capacity (no label is reserved).
    order : int
        Minimum truncation order.
    nip : int
        Number of integration points; a positive value builds a Gauss-point array.

    Returns
    -------
    oarrss
        The array.
    """

    cdef np.ndarray values
    cdef object result
    cdef object dims
    cdef int ndim
    cdef uint64_t i, j, k

    _check_creation(nbases, order, nip)

    if nip == 0 and nbases >= 0 and 0 <= order <= 255:

        result = _array_from_lists(arr, order)

        if result is not None:

            return _reserve_creation(result, nbases, ())

        # end if

    # end if

    if isinstance(arr, (oarrss, arrss)):

        result = arr.copy()

        if isinstance(result, arrss):

            return result

        # end if

        return _reserve_creation(result, nbases, ())

    # end if

    if isinstance(arr, matso):

        return _reserve_creation(oarrss.from_sparse(arr), nbases, ())

    # end if

    values = np.array(arr, dtype=object)
    ndim = values.ndim

    if values.ndim == 0:

        dims = (1, 1)
        values = values.reshape(1, 1)

    elif values.ndim == 1:

        dims = (values.shape[0], 1)
        values = values.reshape(values.shape[0], 1)

    elif values.ndim == 2 or (values.ndim == 3 and nip == 0):

        dims = (values.shape[0], values.shape[1])

    else:

        raise ValueError(_RANK_ERROR)

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

        result = _nd(oarrss.from_real(values.astype(np.float64), order=order), ndim)
        return _reserve_creation(result, nbases, ())

    # end if

    result = oarrss.zeros(dims, order=order)

    for i in range(dims[0]):

        for j in range(dims[1]):

            result[i, j] = values[i, j]

        # end for

    # end for

    return _reserve_creation(_nd(result, ndim), nbases, ())

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef object _array_from_lists(object arr, ord_t order):
    """
    Build a SoA matrix straight from a (nested) list of reals and OTI scalars.

    Parameters
    ----------
    arr : list or tuple
        A list of numbers (a 1-D array) or a list of equally long lists of numbers (a matrix).
    order : int
        Minimum truncation order.

    Returns
    -------
    oarrss or None
        The matrix, or None when the input is not such a list (the general path then handles it).
    """

    cdef Py_ssize_t nr, nc, i, j
    cdef bint nested
    cdef ord_t top = order
    cdef object row, item
    cdef type kind
    cdef oarrss result
    cdef ssotinum scalar
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

            if kind is ssotinum:

                if (<ssotinum>item).num.trc_order > top:

                    top = (<ssotinum>item).num.trc_order

                # end if

            elif isinstance(item, Real):

                continue

            else:

                return None

            # end if

        # end for

    # end for

    result = oarrss.wrap(oarrss_zeros(NULL, 0, nr, nc, top))

    for i in range(nr):

        row = rows[i]

        for j in range(nc):

            item = row[j] if nested else row

            if type(item) is ssotinum:

                scalar = item
                oarrss_set_item(&scalar.num, i, j, &result.arr)

            else:

                result.arr.p_data[i + j * nr] = item

            # end if

        # end for

    # end for

    return result if nested else _nd(result, 1)

# end function
# --------------------------------------------------------------------------------------------------------
