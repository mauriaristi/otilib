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
    Create a zero SoA array over the bases 1..nact (column-major blocks).

    Parameters
    ----------
    dims : tuple of int
        Shape.
    nact : int
        Number of active bases.
    order : int
        Truncation order.

    Returns
    -------
    omat
        Zero array.
    """

    return _soa_zeros_nd(dims, nact, order)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef bases_t _reserved_nact(object nbases, object bases) except? 0:
    """
    Active bases of a new dense array (contracts 11.7, decision A1): ``nbases=K`` reserves the layout
    over 1..K, ``bases=`` over 1..max(bases); both give the larger.

    Parameters
    ----------
    nbases : int
        Reservation (0: none).
    bases : iterable of int
        Base labels.

    Returns
    -------
    int
        nact of the layout.
    """

    cdef bases_t k = _nact_of(bases)

    if nbases > k:

        if nbases > 65535:

            raise MemoryError("nbases={} is above the largest number of bases".format(nbases))

        # end if

        k = nbases

    # end if

    return k

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef object _fe_zeros_reserved(object dims, object bases, object order, object nip, object nbases):
    """
    The Gauss zero hook (``_fe_zeros``), passing a reservation only when one is asked for (the hook's
    1.x signature stays valid).

    Parameters
    ----------
    dims : tuple of int
        Matrix shape at each point.
    bases : list of int
        Base labels.
    order : int
        Truncation order.
    nip : int
        Number of integration points.
    nbases : int
        Bases to reserve (0: none).

    Returns
    -------
    omatfe
        Zero Gauss array.
    """

    if nbases:

        return _fe_zeros(dims, bases, order, nip, nbases)

    # end if

    return _fe_zeros(dims, bases, order, nip)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def zeros(shape_in, nbases=0, order=0, nip=0, bases=(), layout="F"):
    """
    Create a zero dense array.

    Shapes follow NumPy (contracts 11.2 C1): an int or a 1-tuple gives a 1-D array, ``()`` a 0-D array.
    ``nbases=K`` (K > 0) reserves the layout: the array is dense over the bases 1..K (all zero), so
    later values over at most K bases and up to ``order`` never grow it (contracts 7.5, 11.7); a
    reservation too large for the memory budget raises MemoryError.

    Parameters
    ----------
    shape_in : int or tuple of int
        Shape. With ``nip > 0`` it is the matrix shape of a Gauss array (an int is a column).
    nbases : int
        Bases to reserve (0: none).
    order : int
        Truncation order.
    nip : int
        Number of integration points; a positive value builds a Gauss-point array.
    bases : iterable of int
        Base labels; the array is dense over 1..max(bases).
    layout : str
        ``'F'`` (default) or ``'C'``: memory order inside each coefficient block.

    Returns
    -------
    omat
        Zero array.
    """

    cdef tuple dims

    # Fast path: the common (rows, columns) call without bases.
    if nip == 0 and nbases == 0 and layout == "F" and type(shape_in) is tuple and (
        type(bases) is tuple and len(<tuple>bases) == 0
    ):

        dims = <tuple>shape_in

        if len(dims) == 2 and type(dims[0]) is int and type(dims[1]) is int and (
            dims[0] >= 0 and dims[1] >= 0 and 0 <= order <= _MAXORDER_OTI
        ):

            return _soa_zeros_nd(dims, 0, order)

        # end if

    # end if

    _check_creation(nbases, order, nip)

    if nip != 0:

        return _fe_zeros_reserved(_process_shape(shape_in), list(bases), order, nip, nbases)

    # end if

    return _soa_zeros_nd(_shape_of(shape_in), _reserved_nact(nbases, bases), order, _layout_of(layout))

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef omat _soa_full(tuple dims, double value, bases_t nact, ord_t order, int32_t layout):
    """
    A dense array whose real parts are all ``value``.

    Parameters
    ----------
    dims : tuple of int
        Shape.
    value : float
        Real value.
    nact : int
        Reserved bases.
    order : int
        Truncation order.
    layout : int
        ND_LAYOUT_F or ND_LAYOUT_C.

    Returns
    -------
    omat
        The array.
    """

    cdef omat result = _soa_zeros_nd(dims, nact, order, layout)

    if oarr_size(&result.arr) > 0 and value != 0.0:

        _block_writeable(result, 0)[...] = value

    # end if

    return result

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def ones(shape_in, nbases=0, order=0, nip=0, layout="F"):
    """
    Create a dense array whose elements are all 1.

    Parameters
    ----------
    shape_in : int or tuple of int
        Shape (NumPy rules, as ``zeros``).
    nbases : int
        Bases to reserve (0: none).
    order : int
        Truncation order.
    nip : int
        Number of integration points; a positive value builds a Gauss-point array.
    layout : str
        ``'F'`` (default) or ``'C'``.

    Returns
    -------
    omat
        Array of ones.
    """

    cdef tuple dims
    cdef object result
    cdef uint64_t i, j

    _check_creation(nbases, order, nip)

    if nip != 0:

        dims = _process_shape(shape_in)
        result = _fe_zeros_reserved(dims, [], order, nip, nbases)

        for i in range(dims[0]):

            for j in range(dims[1]):

                result[i, j] = 1.0

            # end for

        # end for

        return result

    # end if

    return _soa_full(_shape_of(shape_in), 1.0, _reserved_nact(nbases, ()), order, _layout_of(layout))

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def eye(size, nbases=0, order=0, nip=0, layout="F"):
    """
    Create an identity matrix of shape (size, size).

    Parameters
    ----------
    size : int
        Dimension.
    nbases : int
        Bases to reserve (0: none).
    order : int
        Truncation order.
    nip : int
        Number of integration points; a positive value builds a Gauss-point array.
    layout : str
        ``'F'`` (default) or ``'C'``.

    Returns
    -------
    omat
        Identity matrix.
    """

    cdef object result
    cdef uint64_t i

    _check_creation(nbases, order, nip)

    if size < 0:

        raise ValueError("size must be nonnegative")

    # end if

    if nip != 0:

        result = _fe_zeros_reserved((size, size), [], order, nip, nbases)

        for i in range(size):

            result[i, i] = 1.0

        # end for

        return result

    # end if

    result = _soa_zeros_nd((size, size), _reserved_nact(nbases, ()), order, _layout_of(layout))

    if size > 0:

        np.fill_diagonal(_block_writeable(result, 0), 1.0)

    # end if

    return result

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def array(arr, nbases=0, order=0, nip=0, layout="F"):
    """
    Create a dense array from a scalar, a (nested) list or a NumPy array of reals and OTI scalars.

    Shapes follow NumPy (contracts 11.2 C1): a scalar gives a 0-D array, 1-D input a 1-D array, nested
    lists their nesting depth. The truncation order is the larger of ``order`` and the orders of the
    elements. With ``nip`` (or a 3-D input of Gauss values) the 1.x matrix rule builds a Gauss array.

    Parameters
    ----------
    arr : object
        Real or OTI scalar, or nested lists / arrays of them. An existing array is copied.
    nbases : int
        Bases to reserve (0: none).
    order : int
        Minimum truncation order.
    nip : int
        Number of integration points; a positive value builds a Gauss-point array.
    layout : str
        ``'F'`` (default) or ``'C'``.

    Returns
    -------
    omat
        The array.
    """

    cdef np.ndarray values
    cdef np.ndarray reals
    cdef object result
    cdef object dims
    cdef oarr_t native
    cdef uint64_t i, j, k
    cdef int32_t lay = _layout_of(layout)
    cdef ord_t top = order
    cdef omat out

    _check_creation(nbases, order, nip)

    if nip == 0:

        if isinstance(arr, omat):

            out = (<omat>arr).copy()

        elif isinstance(arr, arro):

            out = _to_soa(arr)

        elif isinstance(arr, matso):

            out = _soa_from_matso(arr)

        elif isinstance(arr, (otinum, sotinum)):

            native = oarr_init()
            result = arr if isinstance(arr, otinum) else otinum(arr)
            _soa_ok("array", oarr_from_oti_to(&(<otinum>result).num, &native), &native)
            out = omat.wrap(native)

        else:

            out = None

            try:

                reals = np.asarray(arr, dtype=np.float64)

            except (TypeError, ValueError):

                reals = None

            # end try

            if reals is not None:

                out = _soa_from_numpy(reals, order, lay)

            else:

                values = np.array(arr, dtype=object)

                for item in values.flat:

                    if isinstance(item, otinum) and (<otinum>item).num.trc_order > top:

                        top = (<otinum>item).num.trc_order

                    elif not isinstance(item, (Real, otinum, sotinum)):

                        raise TypeError("array: elements must be reals or OTI scalars, not {}".format(
                            type(item).__name__))

                    # end if

                # end for

                out = _soa_zeros_nd(tuple(np.shape(values)), 0, top, lay)

                for index in np.ndindex(np.shape(values)):

                    out[index] = values[index]

                # end for

            # end if

        # end if

        if order > oarr_trc_order(&out.arr) or nbases > oarr_nact(&out.arr):

            out.reserve(nbases=nbases, order=order)

        # end if

        return out

    # end if

    # Gauss arrays: the 1.x matrix rule (a scalar is 1 x 1, 1-D input a column).
    values = np.array(arr, dtype=object)

    if values.ndim == 0:

        dims = (1, 1)
        values = values.reshape(1, 1)

    elif values.ndim == 1:

        dims = (values.shape[0], 1)
        values = values.reshape(values.shape[0], 1)

    elif values.ndim == 2 or values.ndim == 3:

        dims = (values.shape[0], values.shape[1])

    else:

        raise ValueError("Error: Can not create an array of such dimensions.")

    # end if

    if values.ndim == 3:

        nip = values.shape[2]

    # end if

    result = _fe_zeros_reserved(dims, [], order, nip, nbases)

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

# end function
# --------------------------------------------------------------------------------------------------------
