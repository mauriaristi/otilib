# Index parsing, operand conversion and binary-operation dispatch for the array classes. Owner: WP8a.
#
# The omat / arro class bodies (WP8b) call these helpers: _indices, _array_binary, _aos_binary,
# _normalize_value, _array_real, _array_get_im, _array_set_im, _array_active_bases, _aos_getitem,
# _aos_setitem, _soa_from_real, _soa_from_matso, _to_soa, _to_aos. The SoA indexing (NumPy rules,
# views) is in dense/ndarray.pxi (Phase 7b).

from cpython.slice cimport PySlice_Unpack, PySlice_AdjustIndices


# ********************************************************************************************************
cdef tuple _indices(object key, uint64_t rows, uint64_t cols):
    """
    Check and normalize two-dimensional element indices.

    Parameters
    ----------
    key : object
        Pair of Python indices.
    rows : int
        Row count.
    cols : int
        Column count.

    Returns
    -------
    tuple
        Nonnegative row and column indices.
    """

    if not isinstance(key, tuple) or len(key) != 2 or any(
        not isinstance(index, int) for index in key
    ):

        raise TypeError("expected (row, column) integer indices")

    # end if

    row, col = key
    row = row + rows if row < 0 else row
    col = col + cols if col < 0 else col

    if not (0 <= row < rows and 0 <= col < cols):

        raise IndexError("matrix index out of bounds")

    # end if

    return row, col

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef omat _soa_from_real(np.ndarray data, ord_t order):
    """
    Build a SoA matrix (no active bases) from a real matrix.

    Parameters
    ----------
    data : numpy.ndarray
        Two-dimensional real matrix.
    order : int
        Truncation order.

    Returns
    -------
    omat
        The matrix.
    """

    cdef np.ndarray[np.float64_t, ndim=2, mode="fortran"] fdata = np.asfortranarray(
        data, dtype=np.float64)
    cdef omat native = omat.__new__(omat)

    _soa_ok("from_real", oarr_from_real_to(<coeff_t *>fdata.data if fdata.size > 0 else NULL,
                                           fdata.shape[0], fdata.shape[1], order, &native.arr),
            &native.arr)
    return native

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef omat _soa_from_matso(matso value):
    """
    Convert a sparse matrix into a dense SoA matrix.

    Parameters
    ----------
    value : matso
        Sparse matrix.

    Returns
    -------
    omat
        Dense matrix over the bases 1..(largest base present).
    """

    cdef omat native = omat.__new__(omat)
    cdef omat result
    cdef tuple shape

    _soa_ok("from_sparse", oarr_from_arrso_to(&value.arr, &native.arr, _dhl), &native.arr)
    result = native

    # A matso keeps a logical shape over its 2-D C struct (contracts 11.1): (n,) is stored n x 1 and
    # () as 1 x 1; the dense array takes the logical shape.
    shape = tuple(value.shape)

    if len(shape) < 2 and result.shape != shape:

        _soa_relabel(result, shape)

    # end if

    return result

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef omat _to_soa(object value):
    """
    Return a SoA matrix holding the values of an AoS or SoA matrix.

    Parameters
    ----------
    value : omat or arro
        Source matrix.

    Returns
    -------
    omat
        The matrix itself when it already is SoA, otherwise a converted copy.
    """

    cdef oarr_t native

    if isinstance(value, omat):

        return value

    # end if

    native = oarr_init()
    _soa_ok("to_soa", arro_to_oarr(&(<arro>value).arr, &native), &native)
    return omat.wrap(native)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef arro _to_aos(object value):
    """
    Return an AoS matrix holding the values of an AoS or SoA matrix.

    Parameters
    ----------
    value : omat or arro
        Source matrix.

    Returns
    -------
    arro
        The matrix itself when it already is AoS, otherwise a converted copy.
    """

    cdef arro_t native

    if isinstance(value, arro):

        return value

    # end if

    native = arro_init()
    _aos_ok("to_aos", arro_from_oarr(&(<omat>value).arr, &native), &native)
    return arro.wrap(native)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef object _array_binary(omat left, object other, str op, bint reverse):
    """
    Dispatch an elementwise SoA operation by operand type and side.

    Parameters
    ----------
    left : omat
        Matrix operand.
    other : object
        Other matrix or broadcast scalar.
    op : str
        Addition, subtraction, multiplication, or division.
    reverse : bool
        Whether other appears on the left.

    Returns
    -------
    omat or NotImplemented
        Elementwise result.
    """

    cdef omat rhs
    cdef otinum scalar
    cdef omat result = omat.__new__(omat)
    cdef int status

    if isinstance(other, omat):

        # The shapes broadcast (NumPy rules) in C; DN_ERR_SIZE (ValueError) when they cannot.
        rhs = other

        if op == "add":

            status = oarr_sum_OO_to(&left.arr, &rhs.arr, &result.arr, _dhl)

        elif op == "sub":

            if reverse:

                status = oarr_sub_OO_to(&rhs.arr, &left.arr, &result.arr, _dhl)

            else:

                status = oarr_sub_OO_to(&left.arr, &rhs.arr, &result.arr, _dhl)

            # end if

        elif op == "mul":

            status = oarr_mul_OO_to(&left.arr, &rhs.arr, &result.arr, _dhl)

        else:

            if reverse:

                status = oarr_div_OO_to(&rhs.arr, &left.arr, &result.arr, _dhl)

            else:

                status = oarr_div_OO_to(&left.arr, &rhs.arr, &result.arr, _dhl)

            # end if

        # end if

    elif isinstance(other, (otinum, sotinum)):

        scalar = other if isinstance(other, otinum) else otinum(other)

        if op == "add":

            status = oarr_sum_oO_to(&scalar.num, &left.arr, &result.arr, _dhl)

        elif op == "sub":

            if reverse:

                status = oarr_sub_oO_to(&scalar.num, &left.arr, &result.arr, _dhl)

            else:

                status = oarr_sub_Oo_to(&left.arr, &scalar.num, &result.arr, _dhl)

            # end if

        elif op == "mul":

            status = oarr_mul_oO_to(&scalar.num, &left.arr, &result.arr, _dhl)

        else:

            if reverse:

                status = oarr_div_oO_to(&scalar.num, &left.arr, &result.arr, _dhl)

            else:

                status = oarr_div_Oo_to(&left.arr, &scalar.num, &result.arr, _dhl)

            # end if

        # end if

    elif isinstance(other, Real):

        if op == "add":

            status = oarr_sum_rO_to(other, &left.arr, &result.arr, _dhl)

        elif op == "sub":

            if reverse:

                status = oarr_sub_rO_to(other, &left.arr, &result.arr, _dhl)

            else:

                status = oarr_sub_Or_to(&left.arr, other, &result.arr, _dhl)

            # end if

        elif op == "mul":

            status = oarr_mul_rO_to(other, &left.arr, &result.arr, _dhl)

        else:

            if reverse:

                status = oarr_div_rO_to(other, &left.arr, &result.arr, _dhl)

            else:

                status = oarr_div_Or_to(&left.arr, other, &result.arr, _dhl)

            # end if

        # end if

    else:

        return NotImplemented

    # end if

    _soa_ok(op, status, &result.arr)
    return result

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef object _aos_binary(arro left, object other, str op, bint reverse):
    """
    Dispatch AoS elementwise operations without converting the array to SoA.

    Parameters
    ----------
    left : arro
        Array operand.
    other : object
        Array or broadcast scalar.
    op : str
        Algebraic operation.
    reverse : bool
        Whether the other operand appears on the left.

    Returns
    -------
    arro or NotImplemented
        Elementwise result.
    """

    cdef arro rhs
    cdef otinum scalar
    cdef arro_t result = arro_init()
    cdef int status

    if isinstance(other, arro):

        rhs = other

        if left.shape != rhs.shape:

            raise ValueError("{}: AoS array shapes must match ({} and {})".format(op, left.shape,
                                                                                rhs.shape))

        # end if

        if op == "add":

            status = arro_sum_OO_to(&left.arr, &rhs.arr, &result, _dhl)

        elif op == "sub":

            if reverse:

                status = arro_sub_OO_to(&rhs.arr, &left.arr, &result, _dhl)

            else:

                status = arro_sub_OO_to(&left.arr, &rhs.arr, &result, _dhl)

            # end if

        elif op == "mul":

            status = arro_mul_OO_to(&left.arr, &rhs.arr, &result, _dhl)

        else:

            if reverse:

                status = arro_div_OO_to(&rhs.arr, &left.arr, &result, _dhl)

            else:

                status = arro_div_OO_to(&left.arr, &rhs.arr, &result, _dhl)

            # end if

        # end if

    elif isinstance(other, (otinum, sotinum)):

        scalar = other if isinstance(other, otinum) else otinum(other)

        if op == "add":

            status = arro_sum_oO_to(&scalar.num, &left.arr, &result, _dhl)

        elif op == "sub":

            if reverse:

                status = arro_sub_oO_to(&scalar.num, &left.arr, &result, _dhl)

            else:

                status = arro_sub_Oo_to(&left.arr, &scalar.num, &result, _dhl)

            # end if

        elif op == "mul":

            status = arro_mul_oO_to(&scalar.num, &left.arr, &result, _dhl)

        else:

            if reverse:

                status = arro_div_oO_to(&scalar.num, &left.arr, &result, _dhl)

            else:

                status = arro_div_Oo_to(&left.arr, &scalar.num, &result, _dhl)

            # end if

        # end if

    elif isinstance(other, Real):

        if op == "add":

            status = arro_sum_rO_to(other, &left.arr, &result, _dhl)

        elif op == "sub":

            if reverse:

                status = arro_sub_rO_to(other, &left.arr, &result, _dhl)

            else:

                status = arro_sub_Or_to(&left.arr, other, &result, _dhl)

            # end if

        elif op == "mul":

            status = arro_mul_rO_to(other, &left.arr, &result, _dhl)

        else:

            if reverse:

                status = arro_div_rO_to(other, &left.arr, &result, _dhl)

            else:

                status = arro_div_Or_to(&left.arr, other, &result, _dhl)

            # end if

        # end if

    else:

        return NotImplemented

    # end if

    _aos_ok(op, status, &result)
    return arro.wrap(result)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef object _normalize_value(object value, uint64_t nr, uint64_t nc, bint soa):
    """
    Bring a value assigned to a matrix slice to a real, an otinum or an array of the matrix layout.

    Parameters
    ----------
    value : object
        Real, sparse or dense scalar, sparse or dense array, or real NumPy array.
    nr : int
        Rows of the target slice.
    nc : int
        Columns of the target slice.
    soa : bool
        Whether the target is a SoA array (otherwise AoS).

    Returns
    -------
    float or otinum or omat or arro
        Value ready for assignment.
    """

    cdef object data

    if isinstance(value, Real) or isinstance(value, otinum):

        return value

    # end if

    if isinstance(value, sotinum):

        return otinum(value)

    # end if

    if isinstance(value, matso):

        value = _soa_from_matso(value)

    elif isinstance(value, np.ndarray):

        data = np.asarray(value, dtype=np.float64)

        if data.ndim == 0:

            return float(data)

        # end if

        if data.ndim == 1 and data.size == nr * nc:

            data = data.reshape(nr, nc)

        # end if

        if data.ndim != 2:

            raise ValueError("a real array must be one- or two-dimensional")

        # end if

        value = _soa_from_real(data, 0)

    # end if

    if soa and isinstance(value, arro):

        return _to_soa(value)

    # end if

    if not soa and isinstance(value, omat):

        return _to_aos(value)

    # end if

    if isinstance(value, (omat, arro)):

        return value

    # end if

    raise TypeError("expected a real, a scalar or an array of OTI numbers")

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef np.ndarray _array_real(object a):
    """
    The real parts of an array: a read-only NumPy view for SoA (contracts 11.11), a copy for AoS.

    Parameters
    ----------
    a : omat or arro
        Source array.

    Returns
    -------
    numpy.ndarray
        Real coefficients, of the array's shape.
    """

    cdef arro aos

    if isinstance(a, omat):

        return _soa_export(<omat>a, 0, False)

    # end if

    # AoS: a read-only strided view of the `re` fields (contracts 11.4; the store is pinned while it
    # lives, and it is never a writable export, critic W3 finding 5).
    aos = a
    return nd_to_numpy(arro_elems(&aos.arr), 0)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef int64_t _soa_block_of(omat a, tuple pair):
    """
    Block index of a direction in a SoA array's layout, or -1 when the direction is outside it (a
    base above nact, or an order above the truncation order).

    Parameters
    ----------
    a : omat
        Array.
    pair : tuple
        (global index, order) of the direction.

    Returns
    -------
    int
        Block index, or -1.
    """

    cdef uint64_t index = pair[0]
    cdef ord_t order = pair[1]

    if order > oarr_trc_order(&a.arr):

        return -1

    # end if

    if order > 0 and index >= <uint64_t>comb(oarr_nact(&a.arr) + order - 1, order):

        return -1

    # end if

    return oarr_block_index(oarr_nact(&a.arr), order, index)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef np.ndarray _array_get_im(object a, object direction, bint deriv):
    """
    Read one direction of every element of an array as a NumPy array (always a copy, 11.4).

    Parameters
    ----------
    a : omat or arro
        Source array.
    direction : int or list or tuple
        Direction in any pyoti.sparse format, or a rawdir.
    deriv : bool
        Multiply by the derivative factor of the direction.

    Returns
    -------
    numpy.ndarray
        Array of the array's shape; zeros for a direction outside the active bases.
    """

    cdef tuple pair = _direction(direction)
    cdef np.ndarray[np.float64_t, ndim=2] result
    cdef np.ndarray values
    cdef uint64_t i, j
    cdef int64_t block
    cdef arro aos
    cdef double factor = _deriv_factor(pair[0], pair[1]) if deriv else 1.0

    if isinstance(a, omat):

        block = _soa_block_of(<omat>a, pair)

        if block < 0:

            return np.zeros(a.shape, dtype=np.float64)

        # end if

        values = np.array(_soa_export(<omat>a, block, False), dtype=np.float64, order="C")

        if deriv:

            values *= factor

        # end if

        return values

    # end if

    aos = a
    result = np.empty((arro_nrows(&aos.arr), arro_ncols(&aos.arr)), dtype=np.float64)

    for i in range(arro_nrows(&aos.arr)):

        for j in range(arro_ncols(&aos.arr)):

            result[i, j] = oti_get_item(pair[0], pair[1],
                                        &arro_data(&aos.arr)[j + i * arro_ncols(&aos.arr)])
            result[i, j] *= factor

        # end for

    # end for

    return result.reshape(aos.shape)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef void _array_set_im(object a, object value, object direction, bint deriv) except *:
    """
    Set one direction of every element of an array from a real value or array.

    Parameters
    ----------
    a : omat or arro
        Target array; a SoA root nobody shares grows its truncation order and its active bases to
        hold the direction (contracts 11.6 G1); a view or a root with live views or exports must
        already hold it (BufferError).
    value : float or array_like
        Real scalar, or real values broadcasting to the array's shape (an OTI array gives its real
        part).
    direction : int or list or tuple
        Direction in any pyoti.sparse format, or a rawdir.
    deriv : bool
        Treat ``value`` as derivatives instead of coefficients.
    """

    cdef tuple pair = _direction(direction)
    cdef omat soa
    cdef arro aos
    cdef np.ndarray[np.float64_t, ndim=2] data
    cdef np.ndarray values
    cdef uint64_t i, j, rows, cols
    cdef bases_t need
    cdef double factor = _deriv_factor(pair[0], pair[1]) if deriv else 1.0

    if isinstance(value, (omat, arro)):

        value = value.real

    # end if

    if isinstance(a, omat):

        soa = a

        if not soa.FLAGS & 1:

            raise ValueError("this array is a view of another object and cannot be modified")

        # end if

        values = np.broadcast_to(np.asarray(value, dtype=np.float64) / factor, soa.shape)

        if pair[1] > 0:

            need = _unrank(pair[0], pair[1])[-1]
            _status("set_im", oarr_grow_layout(&soa.arr, max(need, oarr_nact(&soa.arr)),
                                               max(pair[1], oarr_trc_order(&soa.arr))))

        # end if

        # The internal writable path (11.11); the setter raises act itself.
        _block_writeable(soa, _soa_block_of(soa, pair))[...] = values

        if pair[1] > 0:

            oarr_raise_act(&soa.arr, pair[1])

        # end if

        return

    # end if

    rows, cols = arro_nrows(&(<arro>a).arr), arro_ncols(&(<arro>a).arr)
    data = np.ascontiguousarray(np.broadcast_to(np.asarray(value, dtype=np.float64) / factor,
                                                a.shape).reshape((rows, cols)))
    aos = a

    for i in range(rows):

        for j in range(cols):

            _status("set_im", oti_set_item(data[i, j], pair[0], pair[1],
                                           &arro_data(&aos.arr)[j + i * arro_ncols(&aos.arr)]))

        # end for

    # end for

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef list _array_active_bases(object a):
    """
    List the active bases of an array (the largest count over the elements for AoS).

    Parameters
    ----------
    a : omat or arro
        Source array.

    Returns
    -------
    list of int
        The labels ``[1, ..., nact]``.
    """

    cdef arro aos
    cdef uint64_t index
    cdef bases_t top

    if isinstance(a, omat):

        return list(range(1, oarr_nact(&(<omat>a).arr) + 1))

    # end if

    aos = a
    top = 0

    for index in range(arro_size(&aos.arr)):

        if arro_data(&aos.arr)[index].nact > top:

            top = arro_data(&aos.arr)[index].nact

        # end if

    # end for

    return list(range(1, top + 1))

# end function
# --------------------------------------------------------------------------------------------------------
