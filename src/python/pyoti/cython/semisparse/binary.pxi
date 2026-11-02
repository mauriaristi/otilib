# Index parsing and binary-operation dispatch for the array classes.

from cpython.slice cimport PySlice_Unpack, PySlice_AdjustIndices
from libc.string cimport memcmp


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
cdef object _array_binary(oarrss left, object other, str op, bint reverse):
    """
    Dispatch an elementwise SoA operation by operand type and side.

    Parameters
    ----------
    left : oarrss
        Matrix operand.
    other : object
        Other matrix or broadcast scalar.
    op : str
        Addition, subtraction, multiplication, or division.
    reverse : bool
        Whether other appears on the left.

    Returns
    -------
    oarrss or NotImplemented
        Elementwise result.
    """

    cdef oarrss rhs
    cdef ssotinum scalar
    cdef oarrss_t result = oarrss_init()

    if isinstance(other, oarrss):

        rhs = other

        if left.shape != rhs.shape:

            raise ValueError("{}: array shapes must match".format(op))

        # end if

        if op == "add":

            oarrss_sum_OO_to(&left.arr, &rhs.arr, &result, _dhl)

        elif op == "sub":

            if reverse:

                oarrss_sub_OO_to(&rhs.arr, &left.arr, &result, _dhl)

            else:

                oarrss_sub_OO_to(&left.arr, &rhs.arr, &result, _dhl)

            # end if

        elif op == "mul":

            oarrss_mul_OO_to(&left.arr, &rhs.arr, &result, _dhl)

        else:

            if reverse:

                oarrss_div_OO_to(&rhs.arr, &left.arr, &result, _dhl)

            else:

                oarrss_div_OO_to(&left.arr, &rhs.arr, &result, _dhl)

            # end if

        # end if

    elif isinstance(other, (ssotinum, sotinum)):

        scalar = other if isinstance(other, ssotinum) else ssotinum(other)

        if scalar.num.nbases == 0 and scalar.num.trc_order == 0:

            scalar = ssotinum(scalar.num.re, order=left.order)

        # end if

        if op == "add":

            oarrss_sum_oO_to(&scalar.num, &left.arr, &result, _dhl)

        elif op == "sub":

            if reverse:

                oarrss_sub_oO_to(&scalar.num, &left.arr, &result, _dhl)

            else:

                oarrss_sub_Oo_to(&left.arr, &scalar.num, &result, _dhl)

            # end if

        elif op == "mul":

            oarrss_mul_oO_to(&scalar.num, &left.arr, &result, _dhl)

        else:

            if reverse:

                oarrss_div_oO_to(&scalar.num, &left.arr, &result, _dhl)

            else:

                oarrss_div_Oo_to(&left.arr, &scalar.num, &result, _dhl)

            # end if

        # end if

    elif isinstance(other, Real):

        if op == "add":

            oarrss_sum_rO_to(other, &left.arr, &result, _dhl)

        elif op == "sub":

            if reverse:

                oarrss_sub_rO_to(other, &left.arr, &result, _dhl)

            else:

                oarrss_sub_Or_to(&left.arr, other, &result, _dhl)

            # end if

        elif op == "mul":

            oarrss_mul_rO_to(other, &left.arr, &result, _dhl)

        else:

            if reverse:

                oarrss_div_rO_to(other, &left.arr, &result, _dhl)

            else:

                oarrss_div_Or_to(&left.arr, other, &result, _dhl)

            # end if

        # end if

    else:

        return NotImplemented

    # end if

    return oarrss.wrap(result)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef object _aos_binary(arrss left, object other, str op, bint reverse):
    """
    Dispatch AoS elementwise operations without converting the array to SoA.

    Parameters
    ----------
    left : arrss
        Array operand.
    other : object
        Array or broadcast scalar.
    op : str
        Algebraic operation.
    reverse : bool
        Whether the other operand appears on the left.

    Returns
    -------
    arrss or NotImplemented
        Elementwise result.
    """

    cdef arrss rhs
    cdef ssotinum scalar
    cdef arrss_t result = arrss_init()

    if isinstance(other, arrss):

        rhs = other

        if left.shape != rhs.shape:

            raise ValueError("{}: array shapes must match".format(op))

        # end if

        if op == "add":

            arrss_sum_OO_to(&left.arr, &rhs.arr, &result, _dhl)

        elif op == "sub":

            if reverse:

                arrss_sub_OO_to(&rhs.arr, &left.arr, &result, _dhl)

            else:

                arrss_sub_OO_to(&left.arr, &rhs.arr, &result, _dhl)

            # end if

        elif op == "mul":

            arrss_mul_OO_to(&left.arr, &rhs.arr, &result, _dhl)

        else:

            if reverse:

                arrss_div_OO_to(&rhs.arr, &left.arr, &result, _dhl)

            else:

                arrss_div_OO_to(&left.arr, &rhs.arr, &result, _dhl)

            # end if

        # end if

    elif isinstance(other, (ssotinum, sotinum)):

        scalar = other if isinstance(other, ssotinum) else ssotinum(other)

        if scalar.num.nbases == 0 and scalar.num.trc_order == 0:

            scalar = ssotinum(scalar.num.re, order=left.order)

        # end if

        if op == "add":

            arrss_sum_oO_to(&scalar.num, &left.arr, &result, _dhl)

        elif op == "sub":

            if reverse:

                arrss_sub_oO_to(&scalar.num, &left.arr, &result, _dhl)

            else:

                arrss_sub_Oo_to(&left.arr, &scalar.num, &result, _dhl)

            # end if

        elif op == "mul":

            arrss_mul_oO_to(&scalar.num, &left.arr, &result, _dhl)

        else:

            if reverse:

                arrss_div_oO_to(&scalar.num, &left.arr, &result, _dhl)

            else:

                arrss_div_Oo_to(&left.arr, &scalar.num, &result, _dhl)

            # end if

        # end if

    elif isinstance(other, Real):

        if op == "add":

            arrss_sum_rO_to(other, &left.arr, &result, _dhl)

        elif op == "sub":

            if reverse:

                arrss_sub_rO_to(other, &left.arr, &result, _dhl)

            else:

                arrss_sub_Or_to(&left.arr, other, &result, _dhl)

            # end if

        elif op == "mul":

            arrss_mul_rO_to(other, &left.arr, &result, _dhl)

        else:

            if reverse:

                arrss_div_rO_to(other, &left.arr, &result, _dhl)

            else:

                arrss_div_Or_to(&left.arr, other, &result, _dhl)

            # end if

        # end if

    else:

        return NotImplemented

    # end if

    return arrss.wrap(result)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef object _normalize_value(object value, uint64_t nr, uint64_t nc, bint soa):
    """
    Bring a value assigned to a matrix slice to a real, an ssotinum or an array of the matrix layout.

    Parameters
    ----------
    value : object
        Real, sparse or semi-sparse scalar, sparse or semi-sparse array, or real NumPy array.
    nr : int
        Rows of the target slice.
    nc : int
        Columns of the target slice.
    soa : bool
        Whether the target is a SoA array (otherwise AoS).

    Returns
    -------
    float or ssotinum or oarrss or arrss
        Value ready for assignment.
    """

    cdef object data

    if isinstance(value, Real) or isinstance(value, ssotinum):

        return value

    # end if

    if isinstance(value, sotinum):

        return ssotinum(value)

    # end if

    if isinstance(value, matso):

        value = oarrss.from_sparse(value)

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

        value = oarrss.from_real(data)

    # end if

    if soa and isinstance(value, arrss):

        return value.to_soa()

    # end if

    if not soa and isinstance(value, oarrss):

        return value.to_aos()

    # end if

    if isinstance(value, (oarrss, arrss)):

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
    a : oarrss or arrss
        Source array.

    Returns
    -------
    numpy.ndarray
        Matrix of shape (nrows, ncols).
    """

    cdef np.ndarray[np.float64_t, ndim=2] result
    cdef uint64_t i, j
    cdef oarrss soa
    cdef arrss aos

    if isinstance(a, oarrss):

        soa = a
        return np.ascontiguousarray(
            _soa_blocks(soa)[0].reshape(soa.arr.ncols, soa.arr.nrows).T)

    # end if

    aos = a
    result = np.empty((aos.arr.nrows, aos.arr.ncols), dtype=np.float64)

    for i in range(aos.arr.nrows):

        for j in range(aos.arr.ncols):

            result[i, j] = aos.arr.p_data[j + i * aos.arr.ncols].re

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
    a : oarrss or arrss
        Source array.
    direction : int or list or tuple
        Direction in any pyoti.sparse format, or a rawdir.
    deriv : bool
        Multiply by the derivative factor of the direction.

    Returns
    -------
    numpy.ndarray
        Matrix of shape (nrows, ncols); zeros for a direction outside the active set.
    """

    cdef tuple pair = _direction(direction)
    cdef np.ndarray[np.float64_t, ndim=2] result
    cdef uint64_t i, j
    cdef arrss aos
    cdef double factor = _deriv_factor(pair[0], pair[1]) if deriv else 1.0

    if isinstance(a, oarrss):

        try:

            result = np.array(a.get_block(rawdir(pair[0], pair[1])), dtype=np.float64, order="C")

        except KeyError:

            result = np.zeros(a.shape, dtype=np.float64)

        # end try

        if deriv:

            result = result * factor

        # end if

        return result

    # end if

    aos = a
    result = np.empty((aos.arr.nrows, aos.arr.ncols), dtype=np.float64)

    for i in range(aos.arr.nrows):

        for j in range(aos.arr.ncols):

            result[i, j] = ssoti_get_item(pair[0], pair[1], &aos.arr.p_data[j + i * aos.arr.ncols])
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
    a : oarrss or arrss
        Target array; its active set grows to hold the direction's bases.
    value : float or array_like
        Real scalar, or matrix of shape (nrows, ncols).
    direction : int or list or tuple
        Direction in any pyoti.sparse format, or a rawdir.
    deriv : bool
        Treat ``value`` as derivatives instead of coefficients.
    """

    cdef tuple pair = _direction(direction)
    cdef oarrss soa
    cdef arrss aos
    cdef np.ndarray[np.float64_t, ndim=2] data
    cdef np.ndarray[np.uint16_t, ndim=1] labels
    cdef uint64_t i, j, rows, cols
    cdef double factor = _deriv_factor(pair[0], pair[1]) if deriv else 1.0

    rows, cols = a.shape
    data = np.empty((rows, cols), dtype=np.float64)
    data[...] = np.asarray(value, dtype=np.float64) / factor

    if isinstance(a, oarrss):

        soa = a

        if pair[1] == 0:

            _soa_blocks(soa)[0][...] = data.T.reshape(-1)
            return

        # end if

        _raise_soa_order(soa, pair[1])
        labels = np.asarray(sorted(set(_unrank(pair[0], pair[1]))), dtype=np.uint16)
        oarrss_add_bases(<bases_t *>labels.data, len(labels), &soa.arr)
        soa.get_block(rawdir(pair[0], pair[1]))[...] = data

        if pair[1] > soa.arr.act_order:

            soa.arr.act_order = pair[1]

        # end if

        return

    # end if

    aos = a

    for i in range(rows):

        for j in range(cols):

            ssoti_set_item(data[i, j], pair[0], pair[1], &aos.arr.p_data[j + i * aos.arr.ncols])

        # end for

    # end for

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef list _array_active_bases(object a):
    """
    List the active bases of an array (the union over the elements for AoS).

    Parameters
    ----------
    a : oarrss or arrss
        Source array.

    Returns
    -------
    list of int
        Sorted basis labels.
    """

    cdef arrss aos
    cdef uint64_t index
    cdef bases_t u
    cdef set labels

    if isinstance(a, oarrss):

        return list(a.active_bases)

    # end if

    aos = a
    labels = set()

    for index in range(aos.arr.size):

        for u in range(aos.arr.p_data[index].nbases):

            labels.add(aos.arr.p_data[index].p_bases[u])

        # end for

    # end for

    return sorted([int(x) for x in labels])

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
cdef bases_t *_positions_c(const bases_t *big, bases_t nbig, const bases_t *small, bases_t nsmall):
    """
    Locate every base of a sorted subset inside a sorted superset (caller frees the result).

    Parameters
    ----------
    big : bases_t *
        Sorted superset labels.
    nbig : int
        Superset size.
    small : bases_t *
        Sorted subset labels; every one must appear in the superset.
    nsmall : int
        Subset size.

    Returns
    -------
    bases_t *
        Malloc'd positions, or NULL when the subset is empty.
    """

    cdef bases_t *positions
    cdef bases_t i, j = 0

    if nsmall == 0:

        return NULL

    # end if

    positions = <bases_t *>malloc(nsmall * sizeof(bases_t))

    for i in range(nsmall):

        while j < nbig and big[j] < small[i]:

            j += 1

        # end while

        positions[i] = j

    # end for

    return positions

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef object _soa_getitem(oarrss a, object key):
    """
    Read an element or a block of a SoA array with the semantics of ``pyoti.sparse.matso``.

    Parameters
    ----------
    a : oarrss
        Source array.
    key : int or slice or tuple
        Matrix key.

    Returns
    -------
    ssotinum or oarrss
        Element copy for an (int, int) key, otherwise a new array holding the selected block.
    """

    cdef Py_ssize_t r0, rs, rn, c0, cs, cn, block
    cdef Py_ssize_t nrows = a.arr.nrows
    cdef uint64_t nblocks
    cdef oarrss result

    if _parse_key_c(key, nrows, a.arr.ncols, &r0, &rs, &rn, &c0, &cs, &cn):

        return ssotinum.wrap(oarrss_get_item(r0, c0, &a.arr))

    # end if

    result = oarrss.wrap(oarrss_zeros(a.arr.p_bases, a.arr.nbases, rn, cn, a.arr.trc_order))

    if rn * cn > 0:

        nblocks = 1 + sshelp_ndir_total(a.arr.nbases, a.arr.trc_order)

        for block in range(nblocks):

            _copy_strided(result.arr.p_data + block * result.arr.size, rn, 0, 1, 0, 1,
                          a.arr.p_data + block * a.arr.size, nrows, r0, rs, c0, cs, rn, cn)

        # end for

    # end if

    result.arr.act_order = a.arr.act_order
    return result

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef int _soa_setitem(oarrss a, object key, object value) except -1:
    """
    Assign an element or a block of a SoA array with the semantics of ``pyoti.sparse.matso``.

    The array's truncation order is raised to the value's (zero-extending every entry) and its active
    set grows to hold the value's bases, so no derivative of the value is dropped.

    Parameters
    ----------
    a : oarrss
        Target array.
    key : int or slice or tuple
        Matrix key.
    value : object
        Real, scalar, array of OTI numbers or real NumPy array. Arrays must have the slice's shape.
    """

    cdef Py_ssize_t r0, rs, rn, c0, cs, cn, block, ii, jj
    cdef Py_ssize_t nrows = a.arr.nrows
    cdef Py_ssize_t size = a.arr.size
    cdef uint64_t nblocks
    cdef ssotinum scalar
    cdef oarrss source
    cdef coeff_t *buffer = NULL
    cdef const coeff_t *table
    cdef bases_t *positions = NULL
    cdef bint is_item
    cdef bint same_set
    cdef ord_t top
    cdef type kind = type(value)
    cdef double real_value

    is_item = _parse_key_c(key, nrows, a.arr.ncols, &r0, &rs, &rn, &c0, &cs, &cn)

    if is_item:

        if kind is ssotinum:

            scalar = value
            _raise_soa_order(a, scalar.num.trc_order)
            oarrss_set_item(&scalar.num, r0, c0, &a.arr)
            return 0

        # end if

        if kind is float or kind is int:

            oarrss_set_item_r(value, r0, c0, &a.arr)
            return 0

        # end if

    # end if

    value = _normalize_value(value, rn, cn, True)

    if isinstance(value, oarrss):

        source = value

        if source.arr.nrows != rn or source.arr.ncols != cn:

            raise ValueError("slice assignment: value has shape {}, the slice has shape {}.".format(
                source.shape, (rn, cn)))

        # end if

    # end if

    if rn * cn == 0:

        return 0

    # end if

    if isinstance(value, Real):

        real_value = value
        nblocks = 1 + sshelp_ndir_total(a.arr.nbases, a.arr.trc_order)

        for block in range(nblocks):

            for jj in range(cn):

                for ii in range(rn):

                    a.arr.p_data[block * size + (c0 + jj * cs) * nrows + r0 + ii * rs] = (
                        real_value if block == 0 else 0.0)

                # end for

            # end for

        # end for

        return 0

    # end if

    if isinstance(value, ssotinum):

        scalar = value
        _raise_soa_order(a, scalar.num.trc_order)
        oarrss_add_bases(scalar.num.p_bases, scalar.num.nbases, &a.arr)
        nblocks = 1 + sshelp_ndir_total(a.arr.nbases, a.arr.trc_order)
        buffer = <coeff_t *>malloc(nblocks * sizeof(coeff_t))
        positions = _positions_c(a.arr.p_bases, a.arr.nbases, scalar.num.p_bases, scalar.num.nbases)

        try:

            buffer[0] = scalar.num.re

            if nblocks > 1:

                ssoti_kernel_expand(&scalar.num, positions, a.arr.nbases, a.arr.trc_order,
                                    buffer + 1)

            # end if

            for block in range(nblocks):

                for jj in range(cn):

                    for ii in range(rn):

                        a.arr.p_data[block * size + (c0 + jj * cs) * nrows + r0 + ii * rs] = (
                            buffer[block])

                    # end for

                # end for

            # end for

        finally:

            free(buffer)
            free(positions)

        # end try

        top = scalar.num.act_order if scalar.num.act_order < a.arr.trc_order else a.arr.trc_order

        if top > a.arr.act_order:

            a.arr.act_order = top

        # end if

        return 0

    # end if

    _raise_soa_order(a, source.arr.trc_order)
    oarrss_add_bases(source.arr.p_bases, source.arr.nbases, &a.arr)
    nblocks = 1 + sshelp_ndir_total(a.arr.nbases, a.arr.trc_order)
    size = a.arr.size

    same_set = (source.arr.nbases == a.arr.nbases and source.arr.trc_order == a.arr.trc_order
                and (a.arr.nbases == 0
                     or memcmp(source.arr.p_bases, a.arr.p_bases, a.arr.nbases * sizeof(bases_t)) == 0))

    if same_set:

        table = source.arr.p_data

    else:

        buffer = <coeff_t *>malloc(nblocks * source.arr.size * sizeof(coeff_t))
        positions = _positions_c(a.arr.p_bases, a.arr.nbases, source.arr.p_bases,
                                 source.arr.nbases)
        oarrss_kernel_expand(&source.arr, positions, a.arr.nbases, a.arr.trc_order, buffer)
        table = buffer

    # end if

    try:

        for block in range(nblocks):

            _copy_strided(a.arr.p_data + block * size, nrows, r0, rs, c0, cs,
                          table + block * source.arr.size, rn, 0, 1, 0, 1, rn, cn)

        # end for

    finally:

        free(buffer)
        free(positions)

    # end try

    top = source.arr.act_order if source.arr.act_order < a.arr.trc_order else a.arr.trc_order

    if top > a.arr.act_order:

        a.arr.act_order = top

    # end if

    return 0

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef object _aos_getitem(arrss a, object key):
    """
    Read an element or a block of an AoS array with the semantics of ``pyoti.sparse.matso``.

    Parameters
    ----------
    a : arrss
        Source array.
    key : int or slice or tuple
        Matrix key.

    Returns
    -------
    ssotinum or arrss
        Element copy for an (int, int) key, otherwise a new array holding copies of the block.
    """

    cdef Py_ssize_t r0, rs, rn, c0, cs, cn, ii, jj
    cdef arrss result

    if _parse_key_c(key, a.arr.nrows, a.arr.ncols, &r0, &rs, &rn, &c0, &cs, &cn):

        return ssotinum.wrap(ssoti_copy(arrss_get_item_ptr(r0, c0, &a.arr)))

    # end if

    result = arrss.wrap(arrss_zeros(rn, cn, 0))

    for ii in range(rn):

        for jj in range(cn):

            arrss_set_item(arrss_get_item_ptr(r0 + ii * rs, c0 + jj * cs, &a.arr), ii, jj,
                           &result.arr)

        # end for

    # end for

    return result

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef int _aos_setitem(arrss a, object key, object value) except -1:
    """
    Assign an element or a block of an AoS array with the semantics of ``pyoti.sparse.matso``.

    Every assigned element becomes a copy of the value, with the value's truncation order.

    Parameters
    ----------
    a : arrss
        Target array.
    key : int or slice or tuple
        Matrix key.
    value : object
        Real, scalar, array of OTI numbers or real NumPy array. Arrays must have the slice's shape.
    """

    cdef Py_ssize_t r0, rs, rn, c0, cs, cn, ii, jj
    cdef bint is_item
    cdef ssotinum scalar
    cdef arrss source
    cdef type kind = type(value)

    is_item = _parse_key_c(key, a.arr.nrows, a.arr.ncols, &r0, &rs, &rn, &c0, &cs, &cn)

    if is_item and kind is ssotinum:

        scalar = value
        arrss_set_item(&scalar.num, r0, c0, &a.arr)
        return 0

    # end if

    value = _normalize_value(value, rn, cn, False)

    if isinstance(value, arrss):

        source = value

        if source.arr.nrows != rn or source.arr.ncols != cn:

            raise ValueError("slice assignment: value has shape {}, the slice has shape {}.".format(
                source.shape, (rn, cn)))

        # end if

        for ii in range(rn):

            for jj in range(cn):

                arrss_set_item(arrss_get_item_ptr(ii, jj, &source.arr), r0 + ii * rs, c0 + jj * cs,
                               &a.arr)

            # end for

        # end for

    elif isinstance(value, Real):

        for ii in range(rn):

            for jj in range(cn):

                arrss_set_item_r(value, r0 + ii * rs, c0 + jj * cs, &a.arr)

            # end for

        # end for

    else:

        scalar = value

        for ii in range(rn):

            for jj in range(cn):

                arrss_set_item(&scalar.num, r0 + ii * rs, c0 + jj * cs, &a.arr)

            # end for

        # end for

    # end if

    return 0

# end function
# --------------------------------------------------------------------------------------------------------
