# Indexing, assignment and binary-operation dispatch for the array classes (NumPy rules, 7b).
#
# Keys follow NumPy on the logical shape (shape.pxi, pyoti.real.key2d); results of slices are new
# arrays (copies until Phase 8). Assignment broadcasts the value as NumPy does (rule S1, plans of
# pyoti.real.assign_plan): 0 equal shapes, 1 a single element, 2 a row repeated down a 2-D target, 3 a
# column repeated across it. Elementwise operations take equal shapes or a single-element operand.

from libc.string cimport memcmp


# ********************************************************************************************************
cdef object _set_shape(object value, tuple shape):
    """
    Give an array of the right size a logical shape (vectors switch between n x 1 and 1 x n freely).

    Parameters
    ----------
    value : oarrss or arrss
        Freshly built array with ``prod(shape)`` elements.
    shape : tuple
        Logical shape, ndim <= 2.

    Returns
    -------
    oarrss or arrss
        ``value``.
    """

    cdef oarrss soa
    cdef arrss aos

    if len(shape) < 2:

        return _nd(value, len(shape))

    # end if

    if isinstance(value, oarrss):

        soa = value
        soa.arr.nrows = shape[0]
        soa.arr.ncols = shape[1]
        soa._ndim = 2

    else:

        aos = value
        aos.arr.nrows = shape[0]
        aos.arr.ncols = shape[1]
        aos._ndim = 2

    # end if

    return value

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef object _array_binary(oarrss left, object other, str op, bint reverse):
    """
    Dispatch an elementwise SoA operation by operand type and side.

    Arrays must have equal logical shapes, or one of them a single element (11.2: broadcasting
    between other shapes is supported by pyoti.dense only).

    Parameters
    ----------
    left : oarrss
        Array operand.
    other : object
        Other array or broadcast scalar.
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
    cdef tuple shape

    if isinstance(other, oarrss):

        rhs = other

        if rhs._ndim != left._ndim or rhs.arr.nrows != left.arr.nrows or (
                rhs.arr.ncols != left.arr.ncols):

            shape = _broadcast_shape(left.shape, rhs.shape)

            if rhs.arr.size == 1:

                return _set_shape(_soa_elementwise(
                    left, ssotinum.wrap(oarrss_get_item(0, 0, &rhs.arr)), op, reverse), shape)

            # end if

            return _set_shape(_soa_elementwise(
                rhs, ssotinum.wrap(oarrss_get_item(0, 0, &left.arr)), op, not reverse), shape)

        # end if

    # end if

    return _soa_elementwise(left, other, op, reverse)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef object _aos_binary(arrss left, object other, str op, bint reverse):
    """
    Dispatch AoS elementwise operations without converting the array to SoA.

    Shapes follow the rule of ``_array_binary``.

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
    cdef tuple shape

    if isinstance(other, arrss):

        rhs = other

        if rhs._ndim != left._ndim or rhs.arr.nrows != left.arr.nrows or (
                rhs.arr.ncols != left.arr.ncols):

            shape = _broadcast_shape(left.shape, rhs.shape)

            if rhs.arr.size == 1:

                return _set_shape(_aos_elementwise(
                    left, ssotinum.wrap(ssoti_copy(&rhs.arr.p_data[0])), op, reverse), shape)

            # end if

            return _set_shape(_aos_elementwise(
                rhs, ssotinum.wrap(ssoti_copy(&left.arr.p_data[0])), op, not reverse), shape)

        # end if

    # end if

    return _aos_elementwise(left, other, op, reverse)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef object _soa_elementwise(oarrss left, object other, str op, bint reverse):
    """
    Run an elementwise SoA operation on operands of equal shapes, or an array and a scalar.

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

    return _nd(oarrss.wrap(result), left._ndim)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef object _aos_elementwise(arrss left, object other, str op, bint reverse):
    """
    Run an elementwise AoS operation on operands of equal shapes, or an array and a scalar.

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

    return _nd(arrss.wrap(result), left._ndim)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef np.ndarray _array_real(object a):
    """
    Return the real parts of an array: a read-only view (SoA) or a read-only copy (AoS).

    Parameters
    ----------
    a : oarrss or arrss
        Source array.

    Returns
    -------
    numpy.ndarray
        The array's logical shape. A SoA view is tracked like ``get_block(0)``.
    """

    cdef np.ndarray[np.float64_t, ndim=2] result
    cdef np.ndarray logical
    cdef uint64_t i, j
    cdef oarrss soa
    cdef arrss aos

    if isinstance(a, oarrss):

        soa = a
        return _export_view(soa, soa.arr.p_data, soa.arr.size, soa.shape, False)

    # end if

    aos = a
    result = np.empty((aos.arr.nrows, aos.arr.ncols), dtype=np.float64)

    for i in range(aos.arr.nrows):

        for j in range(aos.arr.ncols):

            result[i, j] = aos.arr.p_data[j + i * aos.arr.ncols].re

        # end for

    # end for

    logical = result.reshape(aos.shape)
    logical.flags.writeable = False
    return logical

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef np.ndarray _array_get_im(object a, object direction, bint deriv):
    """
    Read one direction of every element of an array as a NumPy array (always a copy).

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
        The array's logical shape; zeros for a direction outside the active set.
    """

    cdef tuple pair = _direction(direction)
    cdef np.ndarray[np.float64_t, ndim=2] result
    cdef uint64_t i, j
    cdef arrss aos
    cdef double factor = _deriv_factor(pair[0], pair[1]) if deriv else 1.0

    if isinstance(a, oarrss):

        try:

            result = np.array(_block_writeable(a, pair[0], pair[1]), dtype=np.float64, order="C")

        except KeyError:

            result = np.zeros(((<oarrss>a).arr.nrows, (<oarrss>a).arr.ncols), dtype=np.float64)

        # end try

        if deriv:

            result = result * factor

        # end if

        return result.reshape(a.shape)

    # end if

    aos = a
    result = np.empty((aos.arr.nrows, aos.arr.ncols), dtype=np.float64)

    for i in range(aos.arr.nrows):

        for j in range(aos.arr.ncols):

            result[i, j] = ssoti_get_item(pair[0], pair[1], &aos.arr.p_data[j + i * aos.arr.ncols])
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

    Writes go through the internal writable path, never through the public read-only exports.

    Parameters
    ----------
    a : oarrss or arrss
        Target array; its active set grows to hold the direction's bases.
    value : float or array_like
        Real scalar, or array broadcastable to the array's logical shape.
    direction : int or list or tuple
        Direction in any pyoti.sparse format, or a rawdir.
    deriv : bool
        Treat ``value`` as derivatives instead of coefficients.

    Raises
    ------
    BufferError
        The direction needs new labels or a higher order while a view of the array is alive.
    """

    cdef tuple pair = _direction(direction)
    cdef oarrss soa
    cdef arrss aos
    cdef np.ndarray[np.float64_t, ndim=2] data
    cdef np.ndarray[np.uint16_t, ndim=1] labels
    cdef object logical
    cdef uint64_t i, j, rows, cols
    cdef double factor = _deriv_factor(pair[0], pair[1]) if deriv else 1.0

    logical = np.empty(a.shape, dtype=np.float64)
    logical[...] = np.asarray(value, dtype=np.float64) / factor

    if isinstance(a, oarrss):

        soa = a
        rows = soa.arr.nrows
        cols = soa.arr.ncols
        data = np.ascontiguousarray(logical.reshape(rows, cols))

        if pair[1] == 0:

            _block_writeable(soa, 0, 0)[...] = data
            return

        # end if

        labels = np.asarray(sorted(set(_unrank(pair[0], pair[1]))), dtype=np.uint16)
        _check_ss_growth(soa, <bases_t *>labels.data, len(labels), pair[1])
        _raise_soa_order(soa, pair[1])
        oarrss_add_bases(<bases_t *>labels.data, len(labels), &soa.arr)
        _block_writeable(soa, pair[0], pair[1])[...] = data

        if pair[1] > soa.arr.act_order:

            soa.arr.act_order = pair[1]

        # end if

        return

    # end if

    aos = a
    rows = aos.arr.nrows
    cols = aos.arr.ncols
    data = np.ascontiguousarray(logical.reshape(rows, cols))

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
cdef void _copy_linear(coeff_t *dst, Py_ssize_t dst_nrows, Py_ssize_t dr0, Py_ssize_t drs,
                       Py_ssize_t dc0, Py_ssize_t dcs, const coeff_t *src, Py_ssize_t s_r,
                       Py_ssize_t s_c, Py_ssize_t nr, Py_ssize_t nc) noexcept nogil:
    """
    Fill an nr x nc block of a column-major matrix from linear source strides (0 repeats a value).

    Element (ii, jj) of the block receives ``src[ii * s_r + jj * s_c]``.

    Parameters
    ----------
    dst : coeff_t *
        Destination matrix (one direction block).
    dst_nrows : int
        Rows of the destination matrix.
    dr0, drs, dc0, dcs : int
        First row, row step, first column and column step of the destination block.
    src : coeff_t *
        Source coefficients.
    s_r, s_c : int
        Source steps along the block's rows and columns.
    nr, nc : int
        Rows and columns written.
    """

    cdef Py_ssize_t ii, jj
    cdef coeff_t *d

    for jj in range(nc):

        d = dst + (dc0 + jj * dcs) * dst_nrows + dr0

        for ii in range(nr):

            d[ii * drs] = src[ii * s_r + jj * s_c]

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

    if positions == NULL:

        raise MemoryError()

    # end if

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
    Read an element or a block of a SoA array with NumPy's basic indexing (rule I1).

    Parameters
    ----------
    a : oarrss
        Source array.
    key : int or slice or Ellipsis or tuple
        Basic key on the logical shape.

    Returns
    -------
    ssotinum or oarrss
        Element copy for one integer per axis, otherwise a new array holding the selection (a copy
        until Phase 8).
    """

    cdef tuple res = _key(key, a._ndim, a.arr.nrows, a.arr.ncols)
    cdef Py_ssize_t r0 = res[0], rs = res[1], rn = res[2], c0 = res[3], cs = res[4], cn = res[5]
    cdef Py_ssize_t block
    cdef uint64_t nblocks
    cdef oarrss result

    if res[6] is None:

        return ssotinum.wrap(oarrss_get_item(r0, c0, &a.arr))

    # end if

    result = oarrss.wrap(oarrss_zeros(a.arr.p_bases, a.arr.nbases, rn, cn, a.arr.trc_order))

    if rn * cn > 0:

        nblocks = 1 + sshelp_ndir_total(a.arr.nbases, a.arr.trc_order)

        for block in range(nblocks):

            _copy_strided(result.arr.p_data + block * result.arr.size, rn, 0, 1, 0, 1,
                          a.arr.p_data + block * a.arr.size, a.arr.nrows, r0, rs, c0, cs, rn, cn)

        # end for

    # end if

    result.arr.act_order = a.arr.act_order
    return _set_shape(result, res[6])

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef object _semisparse_value(object value):
    """
    Bring an assigned value to a real, an ssotinum, a real NumPy array or a semi-sparse array.

    Parameters
    ----------
    value : object
        Real, sparse or semi-sparse scalar or array, NumPy array, or nested list.

    Returns
    -------
    float or ssotinum or numpy.ndarray or oarrss or arrss
        Value ready for assignment (logical shapes kept).
    """

    cdef object data

    if isinstance(value, Real) or isinstance(value, ssotinum):

        return value

    elif isinstance(value, sotinum):

        return ssotinum(value)

    elif isinstance(value, (oarrss, arrss)):

        return value

    elif isinstance(value, matso):

        return oarrss.from_sparse(value)

    elif isinstance(value, np.ndarray) and value.dtype != object:

        return np.asarray(value, dtype=np.float64)

    elif isinstance(value, (np.ndarray, list, tuple)):

        return array(value)

    # end if

    raise TypeError("expected a real, a scalar or an array of OTI numbers")

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef int _soa_fill_scalar(oarrss a, ssotinum scalar, Py_ssize_t r0, Py_ssize_t rs, Py_ssize_t rn,
                          Py_ssize_t c0, Py_ssize_t cs, Py_ssize_t cn) except -1:
    """
    Write one semi-sparse scalar into every element of a block of a SoA array.

    Parameters
    ----------
    a : oarrss
        Target array; it grows to the scalar's labels and order (refused with live exports).
    scalar : ssotinum
        Value.
    r0, rs, rn, c0, cs, cn : int
        Start, step and count of the block's rows and columns.
    """

    cdef Py_ssize_t size, block, ii, jj
    cdef uint64_t nblocks
    cdef coeff_t *buffer = NULL
    cdef bases_t *positions = NULL
    cdef ord_t top

    _check_ss_growth(a, scalar.num.p_bases, scalar.num.nbases, scalar.num.trc_order)
    _raise_soa_order(a, scalar.num.trc_order)
    oarrss_add_bases(scalar.num.p_bases, scalar.num.nbases, &a.arr)
    nblocks = 1 + sshelp_ndir_total(a.arr.nbases, a.arr.trc_order)
    size = a.arr.size
    buffer = <coeff_t *>malloc(nblocks * sizeof(coeff_t))

    if buffer == NULL:

        raise MemoryError()

    # end if

    try:

        positions = _positions_c(a.arr.p_bases, a.arr.nbases, scalar.num.p_bases, scalar.num.nbases)
        buffer[0] = scalar.num.re

        if nblocks > 1:

            ssoti_kernel_expand(&scalar.num, positions, a.arr.nbases, a.arr.trc_order, buffer + 1)

        # end if

        for block in range(nblocks):

            for jj in range(cn):

                for ii in range(rn):

                    a.arr.p_data[block * size + (c0 + jj * cs) * a.arr.nrows + r0 + ii * rs] = (
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

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef int _soa_setitem(oarrss a, object key, object value) except -1:
    """
    Assign an element or a block of a SoA array with NumPy's rules (S1 broadcasting, S2 snapshot).

    Writing into a root grows it (truncation order and labels rise to the value's, existing entries
    are zero-extended) while no export of it is alive (G1); otherwise a growth raises BufferError.

    Parameters
    ----------
    a : oarrss
        Target array.
    key : int or slice or Ellipsis or tuple
        Basic key on the logical shape.
    value : object
        Real, scalar, array of OTI numbers or real NumPy array, broadcastable to the selection.
    """

    cdef tuple res = _key(key, a._ndim, a.arr.nrows, a.arr.ncols)
    cdef Py_ssize_t r0 = res[0], rs = res[1], rn = res[2], c0 = res[3], cs = res[4], cn = res[5]
    cdef Py_ssize_t nrows = a.arr.nrows
    cdef Py_ssize_t size, block, ii, jj, s_r, s_c
    cdef tuple tshape = () if res[6] is None else res[6]
    cdef uint64_t nblocks
    cdef ssotinum scalar
    cdef oarrss source
    cdef coeff_t *buffer = NULL
    cdef const coeff_t *table
    cdef bases_t *positions = NULL
    cdef bint same_set
    cdef ord_t top
    cdef type kind = type(value)
    cdef int plan = 0
    cdef double[:, ::1] full

    if res[6] is None:

        if kind is ssotinum:

            scalar = value
            _check_ss_growth(a, scalar.num.p_bases, scalar.num.nbases, scalar.num.trc_order)
            _raise_soa_order(a, scalar.num.trc_order)
            oarrss_set_item(&scalar.num, r0, c0, &a.arr)
            return 0

        # end if

        if kind is float or kind is int:

            oarrss_set_item_r(value, r0, c0, &a.arr)
            return 0

        # end if

    # end if

    value = _semisparse_value(value)

    if isinstance(value, np.ndarray):

        # Real values: NumPy broadcasts them (S1); the imaginary blocks of the selection become zero.
        data = np.empty(tshape, dtype=np.float64)
        data[...] = value
        full = np.ascontiguousarray(data.reshape(rn, cn))
        size = a.arr.size
        nblocks = 1 + sshelp_ndir_total(a.arr.nbases, a.arr.trc_order)

        for jj in range(cn):

            for ii in range(rn):

                a.arr.p_data[(c0 + jj * cs) * nrows + r0 + ii * rs] = full[ii, jj]

                for block in range(1, nblocks):

                    a.arr.p_data[block * size + (c0 + jj * cs) * nrows + r0 + ii * rs] = 0.0

                # end for

            # end for

        # end for

        return 0

    # end if

    if isinstance(value, arrss):

        value = value.to_soa()

    # end if

    if isinstance(value, oarrss):

        source = value
        plan = _assign_plan(source.shape, tshape)

        if plan == 1:

            value = ssotinum.wrap(oarrss_get_item(0, 0, &source.arr))

        # end if

    # end if

    if rn * cn == 0:

        return 0

    # end if

    if isinstance(value, Real):

        size = a.arr.size
        nblocks = 1 + sshelp_ndir_total(a.arr.nbases, a.arr.trc_order)

        for block in range(nblocks):

            for jj in range(cn):

                for ii in range(rn):

                    a.arr.p_data[block * size + (c0 + jj * cs) * nrows + r0 + ii * rs] = (
                        <double>value if block == 0 else 0.0)

                # end for

            # end for

        # end for

        return 0

    # end if

    if isinstance(value, ssotinum):

        return _soa_fill_scalar(a, value, r0, rs, rn, c0, cs, cn)

    # end if

    # S2: a value sharing the target's buffer is read as a snapshot.
    if source is a or (source.arr.p_data != NULL and source.arr.p_data == a.arr.p_data):

        source = source.copy()

    # end if

    if plan == 0:

        s_r = 1
        s_c = rn

    elif plan == 2:

        s_r = 0
        s_c = 1

    else:

        s_r = 1
        s_c = 0

    # end if

    _check_ss_growth(a, source.arr.p_bases, source.arr.nbases, source.arr.trc_order)
    _raise_soa_order(a, source.arr.trc_order)
    oarrss_add_bases(source.arr.p_bases, source.arr.nbases, &a.arr)
    nblocks = 1 + sshelp_ndir_total(a.arr.nbases, a.arr.trc_order)
    size = a.arr.size
    same_set = source.arr.nbases == a.arr.nbases and source.arr.trc_order == a.arr.trc_order and (
        a.arr.nbases == 0 or memcmp(source.arr.p_bases, a.arr.p_bases,
                                    a.arr.nbases * sizeof(bases_t)) == 0)

    if same_set:

        table = source.arr.p_data

    else:

        buffer = <coeff_t *>malloc(nblocks * source.arr.size * sizeof(coeff_t))

        if buffer == NULL:

            raise MemoryError()

        # end if

        positions = _positions_c(a.arr.p_bases, a.arr.nbases, source.arr.p_bases,
                                 source.arr.nbases)
        oarrss_kernel_expand(&source.arr, positions, a.arr.nbases, a.arr.trc_order, buffer)
        table = buffer

    # end if

    try:

        for block in range(nblocks):

            _copy_linear(a.arr.p_data + block * size, nrows, r0, rs, c0, cs,
                         table + block * source.arr.size, s_r, s_c, rn, cn)

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
    Read an element or a block of an AoS array with NumPy's basic indexing (rule I1).

    Parameters
    ----------
    a : arrss
        Source array.
    key : int or slice or Ellipsis or tuple
        Basic key on the logical shape.

    Returns
    -------
    ssotinum or arrss
        Element copy for one integer per axis, otherwise a new array holding copies of the block.
    """

    cdef tuple res = _key(key, a._ndim, a.arr.nrows, a.arr.ncols)
    cdef Py_ssize_t r0 = res[0], rs = res[1], rn = res[2], c0 = res[3], cs = res[4], cn = res[5]
    cdef Py_ssize_t ii, jj
    cdef arrss result

    if res[6] is None:

        return ssotinum.wrap(ssoti_copy(arrss_get_item_ptr(r0, c0, &a.arr)))

    # end if

    result = arrss.wrap(arrss_zeros(rn, cn, 0))

    for ii in range(rn):

        for jj in range(cn):

            arrss_set_item(arrss_get_item_ptr(r0 + ii * rs, c0 + jj * cs, &a.arr), ii, jj,
                           &result.arr)

        # end for

    # end for

    return _set_shape(result, res[6])

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef int _aos_setitem(arrss a, object key, object value) except -1:
    """
    Assign an element or a block of an AoS array with NumPy's rules (S1 broadcasting, S2 snapshot).

    Every assigned element becomes a copy of the value, with the value's truncation order.

    Parameters
    ----------
    a : arrss
        Target array.
    key : int or slice or Ellipsis or tuple
        Basic key on the logical shape.
    value : object
        Real, scalar, array of OTI numbers or real NumPy array, broadcastable to the selection.
    """

    cdef tuple res = _key(key, a._ndim, a.arr.nrows, a.arr.ncols)
    cdef Py_ssize_t r0 = res[0], rs = res[1], rn = res[2], c0 = res[3], cs = res[4], cn = res[5]
    cdef Py_ssize_t ii, jj, s_r, s_c
    cdef tuple tshape = () if res[6] is None else res[6]
    cdef ssotinum scalar
    cdef arrss source
    cdef int plan
    cdef double[:, ::1] full

    if res[6] is None and type(value) is ssotinum:

        scalar = value
        arrss_set_item(&scalar.num, r0, c0, &a.arr)
        return 0

    # end if

    value = _semisparse_value(value)

    if isinstance(value, np.ndarray):

        data = np.empty(tshape, dtype=np.float64)
        data[...] = value
        full = np.ascontiguousarray(data.reshape(rn, cn))

        for ii in range(rn):

            for jj in range(cn):

                arrss_set_item_r(full[ii, jj], r0 + ii * rs, c0 + jj * cs, &a.arr)

            # end for

        # end for

        return 0

    # end if

    if isinstance(value, oarrss):

        value = value.to_aos()

    # end if

    if isinstance(value, arrss):

        source = value
        plan = _assign_plan(source.shape, tshape)

        if plan == 1:

            value = ssotinum.wrap(ssoti_copy(&source.arr.p_data[0]))

        else:

            if source is a:

                source = source.copy()

            # end if

            # AoS records are row-major: equal shapes copy in that order.
            s_r = cn if plan == 0 else (0 if plan == 2 else 1)
            s_c = 1 if plan != 3 else 0

            for ii in range(rn):

                for jj in range(cn):

                    arrss_set_item(&source.arr.p_data[ii * s_r + jj * s_c], r0 + ii * rs,
                                   c0 + jj * cs, &a.arr)

                # end for

            # end for

            return 0

        # end if

    # end if

    if isinstance(value, Real):

        for ii in range(rn):

            for jj in range(cn):

                arrss_set_item_r(value, r0 + ii * rs, c0 + jj * cs, &a.arr)

            # end for

        # end for

        return 0

    # end if

    scalar = value

    for ii in range(rn):

        for jj in range(cn):

            arrss_set_item(&scalar.num, r0 + ii * rs, c0 + jj * cs, &a.arr)

        # end for

    # end for

    return 0

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef object _soa_matmul(oarrss lhs, oarrss rhs):
    """
    Matrix product with ``numpy.matmul``'s rules for 1-D operands (I3).

    A 1-D left operand is a row and a 1-D right operand a column; the promoted axes are removed, so two
    vectors give an OTI scalar.

    Parameters
    ----------
    lhs, rhs : oarrss
        Factors of ndim 1 or 2.

    Returns
    -------
    oarrss or ssotinum
        Product.
    """

    cdef oarrss left = _as_row(lhs) if lhs._ndim == 1 else lhs
    cdef oarrss_t result = oarrss_init()
    cdef oarrss product
    cdef int status

    if lhs._ndim == 0 or rhs._ndim == 0:

        raise ValueError("matmul: an input operand does not have enough dimensions (0-D array)")

    # end if

    if left.arr.ncols != rhs.arr.nrows:

        raise ValueError("matmul: mismatch in the core dimension: shapes {} and {}".format(
            lhs.shape, rhs.shape))

    # end if

    status = oarrss_matmul_OO_to(&left.arr, &rhs.arr, &result, _dhl)

    if status != 0:

        oarrss_free(&result)
        _status("matmul", status)

    # end if

    product = oarrss.wrap(result)

    if lhs._ndim == 1 and rhs._ndim == 1:

        return ssotinum.wrap(oarrss_get_item(0, 0, &product.arr))

    # end if

    if lhs._ndim == 1 or rhs._ndim == 1:

        return _nd(product, 1)

    # end if

    return product

# end function
# --------------------------------------------------------------------------------------------------------
