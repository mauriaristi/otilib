# Index parsing, operand conversion and binary-operation dispatch for the array classes. Owner: WP8a.
#
# The omat / arro class bodies (WP8b) call these helpers: _indices, _array_binary, _aos_binary,
# _normalize_value, _array_real, _array_get_im, _array_set_im, _array_active_bases, _soa_getitem,
# _soa_setitem, _aos_getitem, _aos_setitem, _soa_block_view, _soa_from_real, _soa_from_matso,
# _to_soa, _to_aos.

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
    cdef oarr_t native = oarr_init()

    _soa_ok("from_real", oarr_from_real_to(<coeff_t *>fdata.data if fdata.size > 0 else NULL,
                                           fdata.shape[0], fdata.shape[1], order, &native),
            &native)
    return omat.wrap(native)

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

    cdef oarr_t native = oarr_init()

    _soa_ok("from_sparse", oarr_from_arrso_to(&value.arr, &native, _dhl), &native)
    return omat.wrap(native)

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
cdef object _soa_block_view(omat a, uint64_t index, ord_t order, object base=None):
    """
    Return the coefficient block of a direction as a writable Fortran-ordered NumPy view.

    Parameters
    ----------
    a : omat
        Source array.
    index : int
        Global direction index within its order.
    order : int
        Direction order; 0 gives the real block.
    base : object, optional
        Object kept as the base of the view (default: the array itself); ``omat.get_block`` passes a
        registered ``_BlockExport`` so that growth of the array can be refused while the view lives.

    Returns
    -------
    numpy.ndarray
        View of shape (nrows, ncols) sharing native memory, or None when the direction uses a base
        beyond the array's active bases (or an order above its truncation order).
    """

    cdef np.npy_intp dims[2]
    cdef coeff_t *block
    cdef np.ndarray flat

    if order > oarr_trc_order(&a.arr):

        return None

    # end if

    block = oarr_data(&a.arr) if order == 0 else oarr_get_block(index, order, &a.arr)

    if block == NULL or oarr_size(&a.arr) == 0:

        return None if block == NULL else np.zeros((oarr_nrows(&a.arr), oarr_ncols(&a.arr)), order="F")

    # end if

    dims[0] = oarr_ncols(&a.arr)
    dims[1] = oarr_nrows(&a.arr)
    flat = np.PyArray_SimpleNewFromData(2, dims, np.NPY_DOUBLE, <void *>block)
    np.set_array_base(flat, a if base is None else base)
    return flat.T

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
    cdef oarr_t result = oarr_init()
    cdef int status

    if isinstance(other, omat):

        rhs = other

        if oarr_nrows(&left.arr) != oarr_nrows(&rhs.arr) or oarr_ncols(&left.arr) != oarr_ncols(&rhs.arr):

            raise ValueError("{}: array shapes must match".format(op))

        # end if

        if op == "add":

            status = oarr_sum_OO_to(&left.arr, &rhs.arr, &result, _dhl)

        elif op == "sub":

            if reverse:

                status = oarr_sub_OO_to(&rhs.arr, &left.arr, &result, _dhl)

            else:

                status = oarr_sub_OO_to(&left.arr, &rhs.arr, &result, _dhl)

            # end if

        elif op == "mul":

            status = oarr_mul_OO_to(&left.arr, &rhs.arr, &result, _dhl)

        else:

            if reverse:

                status = oarr_div_OO_to(&rhs.arr, &left.arr, &result, _dhl)

            else:

                status = oarr_div_OO_to(&left.arr, &rhs.arr, &result, _dhl)

            # end if

        # end if

    elif isinstance(other, (otinum, sotinum)):

        scalar = other if isinstance(other, otinum) else otinum(other)

        if op == "add":

            status = oarr_sum_oO_to(&scalar.num, &left.arr, &result, _dhl)

        elif op == "sub":

            if reverse:

                status = oarr_sub_oO_to(&scalar.num, &left.arr, &result, _dhl)

            else:

                status = oarr_sub_Oo_to(&left.arr, &scalar.num, &result, _dhl)

            # end if

        elif op == "mul":

            status = oarr_mul_oO_to(&scalar.num, &left.arr, &result, _dhl)

        else:

            if reverse:

                status = oarr_div_oO_to(&scalar.num, &left.arr, &result, _dhl)

            else:

                status = oarr_div_Oo_to(&left.arr, &scalar.num, &result, _dhl)

            # end if

        # end if

    elif isinstance(other, Real):

        if op == "add":

            status = oarr_sum_rO_to(other, &left.arr, &result, _dhl)

        elif op == "sub":

            if reverse:

                status = oarr_sub_rO_to(other, &left.arr, &result, _dhl)

            else:

                status = oarr_sub_Or_to(&left.arr, other, &result, _dhl)

            # end if

        elif op == "mul":

            status = oarr_mul_rO_to(other, &left.arr, &result, _dhl)

        else:

            if reverse:

                status = oarr_div_rO_to(other, &left.arr, &result, _dhl)

            else:

                status = oarr_div_Or_to(&left.arr, other, &result, _dhl)

            # end if

        # end if

    else:

        return NotImplemented

    # end if

    _soa_ok(op, status, &result)
    return omat.wrap(result)

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

        if arro_nrows(&left.arr) != arro_nrows(&rhs.arr) or arro_ncols(&left.arr) != arro_ncols(&rhs.arr):

            raise ValueError("{}: array shapes must match".format(op))

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
    Copy the real parts of an array into a C-ordered NumPy matrix.

    Parameters
    ----------
    a : omat or arro
        Source array.

    Returns
    -------
    numpy.ndarray
        Matrix of shape (nrows, ncols).
    """

    cdef np.ndarray[np.float64_t, ndim=2] result
    cdef uint64_t i, j
    cdef omat soa
    cdef arro aos

    if isinstance(a, omat):

        soa = a
        return np.ascontiguousarray(
            _soa_blocks(soa)[0].reshape(oarr_ncols(&soa.arr), oarr_nrows(&soa.arr)).T)

    # end if

    aos = a
    result = np.empty((arro_nrows(&aos.arr), arro_ncols(&aos.arr)), dtype=np.float64)

    for i in range(arro_nrows(&aos.arr)):

        for j in range(arro_ncols(&aos.arr)):

            result[i, j] = arro_data(&aos.arr)[j + i * arro_ncols(&aos.arr)].re

        # end for

    # end for

    return result

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef np.ndarray _array_get_im(object a, object direction, bint deriv):
    """
    Read one direction of every element of an array as a NumPy matrix.

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
        Matrix of shape (nrows, ncols); zeros for a direction outside the active bases.
    """

    cdef tuple pair = _direction(direction)
    cdef np.ndarray[np.float64_t, ndim=2] result
    cdef object view
    cdef uint64_t i, j
    cdef arro aos
    cdef double factor = _deriv_factor(pair[0], pair[1]) if deriv else 1.0

    if isinstance(a, omat):

        view = _soa_block_view(a, pair[0], pair[1])

        if view is None:

            return np.zeros((oarr_nrows(&(<omat>a).arr), oarr_ncols(&(<omat>a).arr)), dtype=np.float64)

        # end if

        result = np.array(view, dtype=np.float64, order="C")

        if deriv:

            result = result * factor

        # end if

        return result

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

    return result

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef void _array_set_im(object a, object value, object direction, bint deriv) except *:
    """
    Set one direction of every element of an array from a real value or matrix.

    Parameters
    ----------
    a : omat or arro
        Target array; a SoA array raises its truncation order and its active bases to hold the
        direction.
    value : float or array_like
        Real scalar, or matrix of shape (nrows, ncols).
    direction : int or list or tuple
        Direction in any pyoti.sparse format, or a rawdir.
    deriv : bool
        Treat ``value`` as derivatives instead of coefficients.
    """

    cdef tuple pair = _direction(direction)
    cdef omat soa
    cdef arro aos
    cdef np.ndarray[np.float64_t, ndim=2] data
    cdef object view
    cdef uint64_t i, j, rows, cols
    cdef double factor = _deriv_factor(pair[0], pair[1]) if deriv else 1.0

    if isinstance(a, omat):

        rows, cols = oarr_nrows(&(<omat>a).arr), oarr_ncols(&(<omat>a).arr)

    else:

        rows, cols = arro_nrows(&(<arro>a).arr), arro_ncols(&(<arro>a).arr)

    # end if

    data = np.empty((rows, cols), dtype=np.float64)
    data[...] = np.asarray(value, dtype=np.float64) / factor

    if isinstance(a, omat):

        soa = a

        if not soa.FLAGS & 1:

            raise ValueError("this array is a view of another object and cannot be modified")

        # end if

        if pair[1] == 0:

            _soa_blocks(soa)[0][...] = data.T.reshape(-1)
            return

        # end if

        _check_growth(soa, _unrank(pair[0], pair[1])[-1], pair[1])
        _raise_soa_order(soa, pair[1])
        _status("set_im", oarr_add_bases(_unrank(pair[0], pair[1])[-1], &soa.arr))
        view = _soa_block_view(soa, pair[0], pair[1])
        view[...] = data

        if pair[1] > oarr_act_order(&soa.arr):

            oarr_set_act_order(&soa.arr, pair[1])

        # end if

        return

    # end if

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


# ********************************************************************************************************
cdef bint _axis_range(object index, Py_ssize_t extent, Py_ssize_t *start, Py_ssize_t *step,
                      Py_ssize_t *count) except -1:
    """
    Resolve one axis index of a matrix key into a start, a step and a count.

    Parameters
    ----------
    index : int or slice
        Index along the axis. Negative integers count from the end.
    extent : int
        Length of the axis.
    start : Py_ssize_t *
        First selected position.
    step : Py_ssize_t *
        Distance between selected positions.
    count : Py_ssize_t *
        Number of selected positions.

    Returns
    -------
    bool
        True when the index was an integer.
    """

    cdef Py_ssize_t stop
    cdef Py_ssize_t value

    if isinstance(index, slice):

        PySlice_Unpack(index, start, &stop, step)
        count[0] = PySlice_AdjustIndices(extent, start, &stop, step[0])
        return False

    # end if

    if type(index) is not int:

        if isinstance(index, (bool, np.bool_)) or not isinstance(index, (int, np.integer)):

            raise IndexError("only integers and slices (`:`) are valid indices")

        # end if

    # end if

    value = index

    if value < 0:

        value += extent

    # end if

    if value < 0 or value >= extent:

        raise IndexError("Index out of bounds.")

    # end if

    start[0] = value
    step[0] = 1
    count[0] = 1
    return True

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef bint _parse_key_c(object key, Py_ssize_t nrows, Py_ssize_t ncols, Py_ssize_t *r0,
                       Py_ssize_t *rs, Py_ssize_t *rn, Py_ssize_t *c0, Py_ssize_t *cs,
                       Py_ssize_t *cn) except -1:
    """
    Parse a matrix key with the semantics of ``pyoti.sparse.matso`` into C ranges.

    A single integer or slice selects rows and keeps every column, so ``A[i]`` is a 1 x ncols
    matrix. A pair of two integers selects one element.

    Parameters
    ----------
    key : int or slice or tuple
        Matrix key.
    nrows : int
        Row count.
    ncols : int
        Column count.
    r0, rs, rn : Py_ssize_t *
        Start, step and count of the selected rows.
    c0, cs, cn : Py_ssize_t *
        Start, step and count of the selected columns.

    Returns
    -------
    bool
        True when the key names a single element.
    """

    cdef bint row_integer, column_integer

    if isinstance(key, tuple):

        if len(<tuple>key) != 2:

            raise IndexError("expected a row index or a (row, column) pair")

        # end if

        row_integer = _axis_range((<tuple>key)[0], nrows, r0, rs, rn)
        column_integer = _axis_range((<tuple>key)[1], ncols, c0, cs, cn)
        return row_integer and column_integer

    # end if

    _axis_range(key, nrows, r0, rs, rn)
    c0[0] = 0
    cs[0] = 1
    cn[0] = ncols
    return False

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef void _copy_strided(coeff_t *dst, Py_ssize_t dst_nrows, Py_ssize_t dr0, Py_ssize_t drs,
                        Py_ssize_t dc0, Py_ssize_t dcs, const coeff_t *src, Py_ssize_t src_nrows,
                        Py_ssize_t sr0, Py_ssize_t srs, Py_ssize_t sc0, Py_ssize_t scs,
                        Py_ssize_t nr, Py_ssize_t nc) noexcept nogil:
    """
    Copy an nr x nc block between two column-major matrices with independent strides.

    Parameters
    ----------
    dst : coeff_t *
        Destination matrix (one direction block).
    dst_nrows : int
        Rows of the destination matrix.
    dr0, drs, dc0, dcs : int
        First row, row step, first column and column step of the destination block.
    src : coeff_t *
        Source matrix.
    src_nrows : int
        Rows of the source matrix.
    sr0, srs, sc0, scs : int
        First row, row step, first column and column step of the source block.
    nr, nc : int
        Rows and columns copied.
    """

    cdef Py_ssize_t ii, jj
    cdef coeff_t *d
    cdef const coeff_t *s

    for jj in range(nc):

        d = dst + (dc0 + jj * dcs) * dst_nrows + dr0
        s = src + (sc0 + jj * scs) * src_nrows + sr0

        for ii in range(nr):

            d[ii * drs] = s[ii * srs]

        # end for

    # end for

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef object _soa_getitem(omat a, object key):
    """
    Read an element or a block of a SoA array with the semantics of ``pyoti.sparse.matso``.

    Parameters
    ----------
    a : omat
        Source array.
    key : int or slice or tuple
        Matrix key.

    Returns
    -------
    otinum or omat
        Element copy for an (int, int) key, otherwise a new array holding the selected block.
    """

    cdef Py_ssize_t r0, rs, rn, c0, cs, cn, block
    cdef Py_ssize_t nrows = oarr_nrows(&a.arr)
    cdef uint64_t nblocks
    cdef otinum element
    cdef omat result

    if _parse_key_c(key, nrows, oarr_ncols(&a.arr), &r0, &rs, &rn, &c0, &cs, &cn):

        element = otinum.__new__(otinum)
        _status("getitem", oarr_get_item_to(r0, c0, &a.arr, &element.num))
        return element

    # end if

    result = _soa_zeros((rn, cn), oarr_nact(&a.arr), oarr_trc_order(&a.arr))

    if rn * cn > 0:

        nblocks = 1 + sshelp_ndir_total(oarr_nact(&a.arr), oarr_trc_order(&a.arr))

        for block in range(nblocks):

            _copy_strided(oarr_data(&result.arr) + block * oarr_size(&result.arr), rn, 0, 1, 0, 1,
                          oarr_data(&a.arr) + block * oarr_size(&a.arr), nrows, r0, rs, c0, cs, rn, cn)

        # end for

    # end if

    oarr_set_act_order(&result.arr, oarr_act_order(&a.arr))
    return result

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef int _soa_setitem(omat a, object key, object value) except -1:
    """
    Assign an element or a block of a SoA array with the semantics of ``pyoti.sparse.matso``.

    The array's truncation order is raised to the value's (zero-extending every entry) and its
    active bases grow to hold the value's, so no derivative of the value is dropped.

    Parameters
    ----------
    a : omat
        Target array; must own its buffer.
    key : int or slice or tuple
        Matrix key.
    value : object
        Real, scalar, array of OTI numbers or real NumPy array. Arrays must have the slice's shape.
    """

    cdef Py_ssize_t r0, rs, rn, c0, cs, cn, block, ii, jj
    cdef Py_ssize_t nrows = oarr_nrows(&a.arr)
    cdef Py_ssize_t size = oarr_size(&a.arr)
    cdef uint64_t nblocks
    cdef otinum scalar
    cdef omat source
    cdef coeff_t *buffer = NULL
    cdef const coeff_t *table
    cdef bint is_item
    cdef bint same_layout
    cdef ord_t top
    cdef type kind = type(value)
    cdef double real_value

    if not a.FLAGS & 1:

        raise ValueError("this array is a view of another object and cannot be modified")

    # end if

    is_item = _parse_key_c(key, nrows, oarr_ncols(&a.arr), &r0, &rs, &rn, &c0, &cs, &cn)

    if is_item:

        if kind is otinum:

            scalar = value
            _check_growth(a, scalar.num.nact, scalar.num.trc_order)
            _status("setitem", oarr_set_item(&scalar.num, r0, c0, &a.arr))
            return 0

        # end if

        if kind is float or kind is int:

            _status("setitem", oarr_set_item_r(value, r0, c0, &a.arr))
            return 0

        # end if

    # end if

    value = _normalize_value(value, rn, cn, True)

    if isinstance(value, omat):

        source = value

        if oarr_nrows(&source.arr) != rn or oarr_ncols(&source.arr) != cn:

            raise ValueError("slice assignment: value has shape {}, the slice has shape {}.".format(
                (oarr_nrows(&source.arr), oarr_ncols(&source.arr)), (rn, cn)))

        # end if

    # end if

    if rn * cn == 0:

        return 0

    # end if

    if isinstance(value, Real):

        real_value = value
        nblocks = 1 + sshelp_ndir_total(oarr_nact(&a.arr), oarr_trc_order(&a.arr))

        for block in range(nblocks):

            for jj in range(cn):

                for ii in range(rn):

                    oarr_data(&a.arr)[block * size + (c0 + jj * cs) * nrows + r0 + ii * rs] = (
                        real_value if block == 0 else 0.0)

                # end for

            # end for

        # end for

        return 0

    # end if

    if isinstance(value, otinum):

        scalar = value
        _check_growth(a, scalar.num.nact, scalar.num.trc_order)
        _raise_soa_order(a, scalar.num.trc_order)
        _status("setitem", oarr_add_bases(scalar.num.nact, &a.arr))
        nblocks = 1 + sshelp_ndir_total(oarr_nact(&a.arr), oarr_trc_order(&a.arr))
        buffer = <coeff_t *>malloc(nblocks * sizeof(coeff_t))

        if buffer == NULL:

            raise MemoryError("setitem: allocation failed")

        # end if

        try:

            buffer[0] = scalar.num.re

            if nblocks > 1:

                oti_kernel_expand(&scalar.num, oarr_nact(&a.arr), oarr_trc_order(&a.arr), buffer + 1)

            # end if

            for block in range(nblocks):

                for jj in range(cn):

                    for ii in range(rn):

                        oarr_data(&a.arr)[block * size + (c0 + jj * cs) * nrows + r0 + ii * rs] = (
                            buffer[block])

                    # end for

                # end for

            # end for

        finally:

            free(buffer)

        # end try

        top = (scalar.num.act_order if scalar.num.act_order < oarr_trc_order(&a.arr)
               else oarr_trc_order(&a.arr))

        if top > oarr_act_order(&a.arr):

            oarr_set_act_order(&a.arr, top)

        # end if

        return 0

    # end if

    _check_growth(a, oarr_nact(&source.arr), oarr_trc_order(&source.arr))
    _raise_soa_order(a, oarr_trc_order(&source.arr))
    _status("setitem", oarr_add_bases(oarr_nact(&source.arr), &a.arr))
    nblocks = 1 + sshelp_ndir_total(oarr_nact(&a.arr), oarr_trc_order(&a.arr))
    size = oarr_size(&a.arr)

    same_layout = (oarr_nact(&source.arr) == oarr_nact(&a.arr)
                   and oarr_trc_order(&source.arr) == oarr_trc_order(&a.arr))

    if same_layout:

        table = oarr_data(&source.arr)

    else:

        buffer = <coeff_t *>malloc(nblocks * oarr_size(&source.arr) * sizeof(coeff_t))

        if buffer == NULL:

            raise MemoryError("setitem: allocation failed")

        # end if

        oarr_kernel_expand(&source.arr, oarr_nact(&a.arr), oarr_trc_order(&a.arr), buffer)
        table = buffer

    # end if

    try:

        for block in range(nblocks):

            _copy_strided(oarr_data(&a.arr) + block * size, nrows, r0, rs, c0, cs,
                          table + block * oarr_size(&source.arr), rn, 0, 1, 0, 1, rn, cn)

        # end for

    finally:

        free(buffer)

    # end try

    top = (oarr_act_order(&source.arr) if oarr_act_order(&source.arr) < oarr_trc_order(&a.arr)
           else oarr_trc_order(&a.arr))

    if top > oarr_act_order(&a.arr):

        oarr_set_act_order(&a.arr, top)

    # end if

    return 0

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef object _aos_getitem(arro a, object key):
    """
    Read an element or a block of an AoS array with the semantics of ``pyoti.sparse.matso``.

    Parameters
    ----------
    a : arro
        Source array.
    key : int or slice or tuple
        Matrix key.

    Returns
    -------
    otinum or arro
        Element copy for an (int, int) key, otherwise a new array holding copies of the block.
    """

    cdef Py_ssize_t r0, rs, rn, c0, cs, cn, ii, jj
    cdef otinum element
    cdef arro_t native
    cdef arro result

    if _parse_key_c(key, arro_nrows(&a.arr), arro_ncols(&a.arr), &r0, &rs, &rn, &c0, &cs, &cn):

        element = otinum.__new__(otinum)
        _status("getitem", oti_copy_to(arro_get_item_ptr(r0, c0, &a.arr), &element.num))
        return element

    # end if

    native = arro_init()
    _aos_ok("getitem", arro_zeros_to(rn, cn, 0, &native), &native)
    result = arro.wrap(native)

    for ii in range(rn):

        for jj in range(cn):

            _status("getitem", arro_set_item(arro_get_item_ptr(r0 + ii * rs, c0 + jj * cs, &a.arr),
                                            ii, jj, &result.arr))

        # end for

    # end for

    return result

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef int _aos_setitem(arro a, object key, object value) except -1:
    """
    Assign an element or a block of an AoS array with the semantics of ``pyoti.sparse.matso``.

    Every assigned element becomes a copy of the value, with the value's truncation order.

    Parameters
    ----------
    a : arro
        Target array; must own its buffers.
    key : int or slice or tuple
        Matrix key.
    value : object
        Real, scalar, array of OTI numbers or real NumPy array. Arrays must have the slice's shape.
    """

    cdef Py_ssize_t r0, rs, rn, c0, cs, cn, ii, jj
    cdef bint is_item
    cdef otinum scalar
    cdef arro source
    cdef type kind = type(value)

    if not a.FLAGS & 1:

        raise ValueError("this array is a view of another object and cannot be modified")

    # end if

    is_item = _parse_key_c(key, arro_nrows(&a.arr), arro_ncols(&a.arr), &r0, &rs, &rn, &c0, &cs, &cn)

    if is_item and kind is otinum:

        scalar = value
        _status("setitem", arro_set_item(&scalar.num, r0, c0, &a.arr))
        return 0

    # end if

    value = _normalize_value(value, rn, cn, False)

    if isinstance(value, arro):

        source = value

        if arro_nrows(&source.arr) != rn or arro_ncols(&source.arr) != cn:

            raise ValueError("slice assignment: value has shape {}, the slice has shape {}.".format(
                (arro_nrows(&source.arr), arro_ncols(&source.arr)), (rn, cn)))

        # end if

        for ii in range(rn):

            for jj in range(cn):

                _status("setitem", arro_set_item(arro_get_item_ptr(ii, jj, &source.arr),
                                                r0 + ii * rs, c0 + jj * cs, &a.arr))

            # end for

        # end for

    elif isinstance(value, Real):

        for ii in range(rn):

            for jj in range(cn):

                _status("setitem", arro_set_item_r(value, r0 + ii * rs, c0 + jj * cs, &a.arr))

            # end for

        # end for

    else:

        scalar = value

        for ii in range(rn):

            for jj in range(cn):

                _status("setitem", arro_set_item(&scalar.num, r0 + ii * rs, c0 + jj * cs, &a.arr))

            # end for

        # end for

    # end if

    return 0

# end function
# --------------------------------------------------------------------------------------------------------
