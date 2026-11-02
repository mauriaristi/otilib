# Order and derivative plumbing, truncated products, rom_eval, interp1d, inv_block. Owner: WP9.
#
# Module functions keep the names and signatures of pyoti.sparse (template: semisparse/order.pxi).
# The kernels are in C (src/c/dense/{scalar,soa}/utils.c); AoS arrays run the scalar kernels per
# element, or go through the SoA layout for matrix products. A dense number is over the bases
# 1..nact and its numbering is the global one, so global layouts are direct (a direction beyond a
# layout is skipped) and rom_eval takes one delta per base 1..nact. Methods of the classes
# (rom_eval*, get_all_ims, get_all_derivs, extract_im, extract_deriv) delegate to the functions
# below. The sparse trunc_matmul kernel is exposed as trunc_dot, its pyoti.sparse name.


# ********************************************************************************************************
cdef omat _order_to_soa(object value, str op):
    """
    Return a SoA view of an array operand: SoA as is, AoS converted, real arrays copied.

    Parameters
    ----------
    value : omat or arro or array_like
        Array operand.
    op : str
        Operation name, for error messages.

    Returns
    -------
    omat
        SoA array (the operand itself when it already is one).
    """

    cdef object real

    if isinstance(value, (omat, arro)):

        return _to_soa(value)

    # end if

    if isinstance(value, (np.ndarray, list, tuple)):

        real = np.asarray(value, dtype=np.float64)

        if real.ndim == 1:

            real = real.reshape((-1, 1))

        # end if

        if real.ndim != 2:

            raise ValueError("{0}: real operands must be one- or two-dimensional".format(op))

        # end if

        return _soa_from_real(real, 0)

    # end if

    raise TypeError("{0}: unsupported operand type {1}".format(op, type(value).__name__))

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef object _order_width(ord_t order, bases_t max_base):
    """
    Number of global order-``order`` directions over bases 1..max_base, at least 1.

    Parameters
    ----------
    order : int
        Direction order.
    max_base : int
        Largest base label in use (0 when none).

    Returns
    -------
    int
        C(max_base + order - 1, order), or 1 when ``order`` or ``max_base`` is 0 (the sparse
        get_order_im_array() width of an empty order).
    """

    if order == 0 or max_base == 0:

        return 1

    # end if

    return comb(max_base + order - 1, order)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef int _order_check_bytes(object nreals, str op) except -1:
    """
    Refuse an output buffer above the dense byte budget before NumPy allocates it.

    Parameters
    ----------
    nreals : int
        Number of reals of the buffer.
    op : str
        Operation name, for error messages.

    Raises
    ------
    MemoryError
        If ``8 * nreals`` exceeds ``dn_max_bytes()`` (OTI_DENSE_MAX_MB, default the physical memory).
    """

    if nreals * 8 > dn_max_bytes():

        raise MemoryError("{0}: the result needs {1} bytes, above the dense budget of {2} bytes "
                          "(OTI_DENSE_MAX_MB)".format(op, nreals * 8, dn_max_bytes()))

    # end if

    return 0

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef bases_t _order_aos_nact(arro value):
    """
    Largest nact over the elements of an AoS array.

    Parameters
    ----------
    value : arro
        Array.

    Returns
    -------
    int
        Largest number of active bases (0 for an empty or real array).
    """

    cdef bases_t top = 0
    cdef uint64_t e

    for e in range(value.arr.size):

        if value.arr.p_data[e].nact > top:

            top = value.arr.p_data[e].nact

        # end if

    # end for

    return top

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef arro _order_aos_zeros(uint64_t nrows, uint64_t ncols, str op):
    """
    Allocate a real zero AoS array (truncation order 0) to hold per-element results.

    Parameters
    ----------
    nrows : int
        Number of rows.
    ncols : int
        Number of columns.
    op : str
        Operation name, for error messages.

    Returns
    -------
    arro
        Owned zero array.
    """

    cdef arro_t native = arro_init()

    _aos_ok(op, arro_zeros_to(nrows, ncols, 0, &native), &native)
    return arro.wrap(native)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def get_order_im(order, val, out=None):
    """
    Extract one order of a dense value, with every other order (and the real part) zeroed.

    Same call as ``pyoti.sparse.get_order_im``. Order 0 keeps only the real part.

    Parameters
    ----------
    order : int
        Order to keep, between 0 and 150.
    val : otinum or omat or arro
        Value.
    out : same type as val, optional
        Holder for the result.

    Returns
    -------
    otinum or omat or arro
        The order-``order`` part, or None when ``out`` is given.

    Examples
    --------
    >>> x = oti.e(1, order=2) + 3 * oti.e([1, 2], order=2)
    >>> oti.get_order_im(2, x).get_im([1, 2])
    3.0
    """

    cdef otinum sres
    cdef oarr_t ores = oarr_init()
    cdef arro_t ares = arro_init()

    _check_order(order)

    if isinstance(val, otinum):

        sres = otinum.__new__(otinum)
        _status("get_order_im", oti_get_order_im_to(order, &(<otinum>val).num, &sres.num))
        return _finish(sres, out)

    elif isinstance(val, omat):

        _soa_ok("get_order_im", oarr_get_order_im_to(order, &(<omat>val).arr, &ores), &ores)
        return _finish(omat.wrap(ores), out)

    elif isinstance(val, arro):

        _aos_ok("get_order_im", arro_get_order_im_to(order, &(<arro>val).arr, &ares, _dhl),
                &ares)
        return _finish(arro.wrap(ares), out)

    # end if

    raise TypeError("Unsupported type {0} at get_order_im.".format(type(val).__name__))

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef object _order_extract(object humdir, object val, object out, bint deriv):
    """
    Shared body of extract_im and extract_deriv.

    Parameters
    ----------
    humdir : object
        Direction in any pyoti.sparse format, or a rawdir.
    val : otinum or omat or arro
        Value.
    out : object
        Holder, or None.
    deriv : bool
        True to extract derivatives.

    Returns
    -------
    object
        Result, or None when ``out`` is given.
    """

    cdef str op = "extract_deriv" if deriv else "extract_im"
    cdef tuple pair
    cdef imdir_t idx
    cdef ord_t order
    cdef oarr_t ores = oarr_init()
    cdef arro A, R
    cdef uint64_t e
    cdef int status

    if not isinstance(val, (otinum, omat, arro)):

        raise TypeError("Unsupported type {0} at {1}.".format(type(val).__name__, op))

    # end if

    pair = _direction(humdir)
    idx = pair[0]
    order = pair[1]

    if isinstance(val, otinum):

        return _finish(_extract_scalar(val, idx, order, deriv), out)

    elif isinstance(val, omat):

        if deriv:

            status = oarr_extract_deriv_to(idx, order, &(<omat>val).arr, &ores)

        else:

            status = oarr_extract_im_to(idx, order, &(<omat>val).arr, &ores)

        # end if

        _soa_ok(op, status, &ores)
        return _finish(omat.wrap(ores), out)

    # end if

    A = val
    R = _order_aos_zeros(A.arr.nrows, A.arr.ncols, op)

    for e in range(A.arr.size):

        if deriv:

            status = oti_extract_deriv_to(idx, order, &A.arr.p_data[e], &R.arr.p_data[e])

        else:

            status = oti_extract_im_to(idx, order, &A.arr.p_data[e], &R.arr.p_data[e])

        # end if

        _status(op, status)

    # end for

    return _finish(R, out)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def extract_im(humdir, val, out=None):
    """
    Extract the coefficients that contain an imaginary direction, divided by it.

    Same call and result as ``pyoti.sparse.extract_im``: coefficient d / g of the result is
    coefficient d of ``val``. The result keeps nact, with truncation order lowered by the order of
    the direction.

    Parameters
    ----------
    humdir : int or list or tuple or rawdir
        Direction g.
    val : otinum or omat or arro
        Value.
    out : same type as val, optional
        Holder for the result.

    Returns
    -------
    otinum or omat or arro
        Extracted value, or None when ``out`` is given.

    Examples
    --------
    >>> x = 2 * oti.e([1, 2], order=2)
    >>> oti.extract_im(1, x).get_im(2)
    2.0
    """

    return _order_extract(humdir, val, out, False)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def extract_deriv(humdir, val, out=None):
    """
    Extract the derivatives that contain an imaginary direction, as an OTI value of derivatives.

    Same call and result as ``pyoti.sparse.extract_deriv``: like ``extract_im`` with the
    coefficients rescaled so that the result holds the derivatives of ``val`` differentiated along
    the direction.

    Parameters
    ----------
    humdir : int or list or tuple or rawdir
        Direction.
    val : otinum or omat or arro
        Value.
    out : same type as val, optional
        Holder for the result.

    Returns
    -------
    otinum or omat or arro
        Extracted value, or None when ``out`` is given.

    Examples
    --------
    >>> x = oti.e([1, 1], order=2)
    >>> oti.extract_deriv(1, x).get_deriv(1)
    2.0
    """

    return _order_extract(humdir, val, out, True)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def get_order_im_array(ordi, tmp):
    """
    Export one order of an OTI array as a real matrix with the directions side by side.

    Same call and layout as ``pyoti.sparse.get_order_im_array``: element (i, j) along the
    order-``ordi`` direction with global index g is at ``res[i, j + ncols * g]``, and the width
    covers the global directions over bases 1..b, b the largest base with a nonzero coefficient
    of that order (one direction when there is none). Order 0 exports the real part.

    Parameters
    ----------
    ordi : int
        Order to export.
    tmp : omat or arro
        Array.

    Returns
    -------
    numpy.ndarray
        Real matrix of shape (nrows, ncols * width).

    Examples
    --------
    >>> A = oti.zeros((2, 2), order=1) + oti.e(2, order=1)
    >>> oti.get_order_im_array(1, A).shape
    (2, 4)
    """

    cdef omat S
    cdef arro A
    cdef bases_t mb = 0, mbe
    cdef uint64_t i, j, nr, nc
    cdef object width
    cdef np.ndarray[np.float64_t, ndim=2] res

    if not isinstance(tmp, (omat, arro)):

        raise TypeError("Unsupported type {0} at get_order_im_array.".format(type(tmp).__name__))

    # end if

    _check_order(ordi)

    if isinstance(tmp, omat):

        S = tmp

        if ordi > 0:

            mb = oarr_order_max_base(ordi, &S.arr)

        # end if

        width = _order_width(ordi, mb)
        _order_check_bytes(S.arr.nrows * S.arr.ncols * width, "get_order_im_array")
        res = np.empty((S.arr.nrows, S.arr.ncols * width), dtype=np.float64)

        if res.size > 0:

            _status("get_order_im_array",
                    oarr_get_order_im_array_to(ordi, &S.arr, width, <coeff_t *>res.data))

        # end if

        return res

    # end if

    A = tmp
    nr = A.arr.nrows
    nc = A.arr.ncols

    if ordi > 0:

        for i in range(A.arr.size):

            mbe = oti_order_max_base(ordi, &A.arr.p_data[i])
            mb = mbe if mbe > mb else mb

        # end for

    # end if

    width = _order_width(ordi, mb)
    _order_check_bytes(nr * nc * width, "get_order_im_array")
    res = np.zeros((nr, nc * width), dtype=np.float64)

    for i in range(nr):

        for j in range(nc):

            oti_scatter_order_im(ordi, &A.arr.p_data[j + i * nc], width, &res[i, j], nc)

        # end for

    # end for

    return res

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def set_order_im_from_array(ordi, arr, tmp):
    """
    Add one order to an OTI array from a real matrix with the directions side by side.

    Same call as ``pyoti.sparse.set_order_im_from_array`` and the inverse layout of
    ``get_order_im_array``: ``arr[i, j + ncols * g]`` is added to element (i, j) along the
    order-``ordi`` direction with global index g. ``tmp`` is modified in place; its nact grows to
    the largest base of every nonzero direction and its truncation order is raised to ``ordi``
    when lower. Order 0 adds to the real part.

    Parameters
    ----------
    ordi : int
        Order to add.
    arr : numpy.ndarray
        Real matrix of shape (nrows, ncols * width).
    tmp : omat or arro
        Array that receives the coefficients.

    Examples
    --------
    >>> A = oti.zeros((1, 1), order=1)
    >>> oti.set_order_im_from_array(1, np.array([[0.0, 5.0]]), A)
    >>> A[0, 0].get_im(2)
    5.0
    """

    cdef np.ndarray[np.float64_t, ndim=2] vals
    cdef omat S
    cdef arro A
    cdef uint64_t nr, nc, i, j
    cdef ndir_t width

    if isinstance(tmp, omat):

        nr = (<omat>tmp).arr.nrows
        nc = (<omat>tmp).arr.ncols

        if not (<omat>tmp).FLAGS & 1:

            raise ValueError("set_order_im_from_array: cannot modify a view")

        # end if

    elif isinstance(tmp, arro):

        nr = (<arro>tmp).arr.nrows
        nc = (<arro>tmp).arr.ncols

        if not (<arro>tmp).FLAGS & 1:

            raise ValueError("set_order_im_from_array: cannot modify a view")

        # end if

    else:

        raise TypeError("Unsupported type {0} at set_order_im_from_array.".format(
            type(tmp).__name__))

    # end if

    _check_order(ordi)
    vals = np.ascontiguousarray(arr, dtype=np.float64)

    if vals.shape[0] != nr or nc == 0 or vals.shape[1] % nc != 0:

        raise ValueError("set_order_im_from_array: array of shape {0} does not match {1}".format(
            (vals.shape[0], vals.shape[1]), (nr, nc)))

    # end if

    width = vals.shape[1] // nc

    if width == 0 or nr == 0:

        return None

    # end if

    if isinstance(tmp, omat):

        S = tmp

        # Live get_block views would dangle if the layout grows: a higher trc, or a nonzero value
        # at a global index beyond the directions of order ordi over bases 1..nact.
        nonzero = np.flatnonzero(np.any(vals.reshape((nr, width, nc)) != 0.0, axis=(0, 2)))

        if ordi > S.arr.trc_order or (ordi > 0 and nonzero.size > 0
                                      and nonzero[-1] >= sshelp_ndir_order(S.arr.nact, ordi)):

            _check_no_block_views(S)

        # end if

        _status("set_order_im_from_array",
                oarr_add_order_im_array(ordi, <coeff_t *>vals.data, width, &S.arr))

    else:

        A = tmp

        for i in range(nr):

            for j in range(nc):

                _status("set_order_im_from_array",
                        oti_add_order_im_global(ordi, &vals[i, j], width, nc,
                                                &A.arr.p_data[j + i * nc]))

            # end for

        # end for

    # end if

    return None

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def trunc_dot(ordlhs, lhs, ordrhs, rhs, out=None):
    """
    Truncated matrix product: the order (ordlhs + ordrhs) part of lhs_ordlhs @ rhs_ordrhs.

    Same call as ``pyoti.sparse.trunc_dot`` (the inner step of the block solvers): only the
    order-``ordlhs`` part of ``lhs`` and the order-``ordrhs`` part of ``rhs`` take part, and only
    their order (ordlhs + ordrhs) product is kept. Order 0 selects the real part. The result has
    nact = max of the operands and the larger truncation order.

    AoS operands go through the SoA layout, which has one truncation order per array: every element
    is raised to the array's largest trc, so a product of two low-trc elements keeps orders that the
    pairwise rule of ``pyoti.sparse`` (``max(trc_a, trc_b)`` per pair) would drop.

    Parameters
    ----------
    ordlhs : int
        Order taken from ``lhs``.
    lhs : omat or arro
        Left matrix.
    ordrhs : int
        Order taken from ``rhs``.
    rhs : omat or arro or numpy.ndarray
        Right matrix.
    out : omat or arro, optional
        Holder for the result.

    Returns
    -------
    omat or arro
        The product (AoS only when both operands are AoS), or None when ``out`` is given.

    Examples
    --------
    >>> K = oti.zeros((2, 2), order=2) + oti.e(1, order=2)
    >>> X = oti.zeros((2, 1), order=2) + 1.0
    >>> oti.trunc_dot(1, K, 0, X).get_im(1)[0, 0]
    2.0
    """

    cdef omat L, R
    cdef oarr_t res = oarr_init()
    cdef bint aos = isinstance(lhs, arro) and isinstance(rhs, arro)

    if not isinstance(lhs, (omat, arro)) or not isinstance(rhs, (omat, arro, np.ndarray)):

        raise TypeError("Unsupported types {0}, {1} at trunc_dot operation.".format(
            type(lhs).__name__, type(rhs).__name__))

    # end if

    _check_order(ordlhs)
    _check_order(ordrhs)
    L = _order_to_soa(lhs, "trunc_dot")
    R = _order_to_soa(rhs, "trunc_dot")

    if L.arr.ncols != R.arr.nrows:

        raise ValueError("trunc_dot: shapes {0} and {1} not aligned".format(
            (L.arr.nrows, L.arr.ncols), (R.arr.nrows, R.arr.ncols)))

    # end if

    _soa_ok("trunc_dot", oarr_trunc_matmul_OO_to(ordlhs, &L.arr, ordrhs, &R.arr, &res, _dhl),
            &res)

    if aos:

        return _finish(_to_aos(omat.wrap(res)), out)

    # end if

    return _finish(omat.wrap(res), out)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def trunc_sub(order, Olhs, Orhs, out=None):
    """
    Truncated subtraction: keeps only the order-``order`` part of Olhs - Orhs.

    Same call as ``pyoti.sparse.trunc_sub``; every other order of the result (the real part
    included, unless ``order`` is 0) is zero. Unlike sparse, the result is also returned when no
    ``out`` is given.

    Parameters
    ----------
    order : int
        Order to keep.
    Olhs : otinum or omat or arro
        First operand.
    Orhs : same type as Olhs
        Second operand, same shape.
    out : same type as Olhs, optional
        Holder for the result; may be one of the operands.

    Returns
    -------
    otinum or omat or arro
        The order-``order`` part of the difference, or None when ``out`` is given.

    Examples
    --------
    >>> a = 1 + oti.e(1, order=2) + oti.e([1, 1], order=2)
    >>> oti.trunc_sub(1, a, 0.5 * a).get_im(1)
    0.5
    """

    cdef otinum sres
    cdef oarr_t ores = oarr_init()
    cdef arro A, B, C
    cdef uint64_t e

    if isinstance(Olhs, otinum) and isinstance(Orhs, otinum):

        _check_order(order)
        sres = otinum.__new__(otinum)
        _status("trunc_sub", oti_trunc_sub_to(order, &(<otinum>Olhs).num, &(<otinum>Orhs).num,
                                              &sres.num))
        return _finish(sres, out)

    elif isinstance(Olhs, omat) and isinstance(Orhs, omat):

        _check_order(order)
        _soa_ok("trunc_sub", oarr_trunc_sub_OO_to(order, &(<omat>Olhs).arr, &(<omat>Orhs).arr,
                                                  &ores), &ores)
        return _finish(omat.wrap(ores), out)

    elif isinstance(Olhs, arro) and isinstance(Orhs, arro):

        _check_order(order)
        A = Olhs
        B = Orhs

        if A.arr.nrows != B.arr.nrows or A.arr.ncols != B.arr.ncols:

            raise ValueError("trunc_sub: shapes {0} and {1} differ".format(
                (A.arr.nrows, A.arr.ncols), (B.arr.nrows, B.arr.ncols)))

        # end if

        C = _order_aos_zeros(A.arr.nrows, A.arr.ncols, "trunc_sub")

        for e in range(A.arr.size):

            _status("trunc_sub", oti_trunc_sub_to(order, &A.arr.p_data[e], &B.arr.p_data[e],
                                                  &C.arr.p_data[e]))

        # end for

        return _finish(C, out)

    # end if

    raise TypeError("Unsupported types {0}, {1} at trunc_sub operation.".format(
        type(Olhs).__name__, type(Orhs).__name__))

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def dot_product(lhs, rhs, out=None):
    """
    Vector dot product: the sum of the elementwise products of two arrays of the same size.

    Same call as ``pyoti.sparse.dot_product``. The arrays are paired flattened row by row, as sparse
    does, so an (n, 1) array pairs with a (1, n) one. Real NumPy arrays are accepted as either
    operand.

    AoS operands go through the SoA layout, which raises every element to the array's largest trc;
    with elements of different trc the result can keep orders that ``pyoti.sparse`` drops.

    Parameters
    ----------
    lhs : omat or arro or numpy.ndarray
        First array.
    rhs : omat or arro or numpy.ndarray
        Second array, same number of elements.
    out : otinum, optional
        Holder for the result.

    Returns
    -------
    otinum
        The dot product, or None when ``out`` is given.

    Examples
    --------
    >>> a = oti.zeros((3, 1), order=1) + oti.e(1, order=1)
    >>> oti.dot_product(a, np.ones((1, 3))).get_im(1)
    3.0
    """

    cdef omat L, R
    cdef oarr_t Lt = oarr_init(), Rt = oarr_init()
    cdef otinum res
    cdef bint same, vectors
    cdef int status

    # Gauss-point operands (dense/gauss/base.pxi) handle every mix, and out=, themselves.
    if isinstance(lhs, _dnfe) or isinstance(rhs, _dnfe):

        return _fe_dot_product(lhs, rhs, out)

    # end if

    if not isinstance(lhs, (omat, arro)) and not isinstance(rhs, (omat, arro)):

        raise TypeError("Unsupported types {0}, {1} at dot_product operation.".format(
            type(lhs).__name__, type(rhs).__name__))

    # end if

    L = _order_to_soa(lhs, "dot_product")
    R = _order_to_soa(rhs, "dot_product")

    if L.arr.size != R.arr.size:

        raise ValueError("dot_product: operands have different sizes, shapes {0} and {1}.".format(
            (L.arr.nrows, L.arr.ncols), (R.arr.nrows, R.arr.ncols)))

    # end if

    same = L.arr.nrows == R.arr.nrows and L.arr.ncols == R.arr.ncols
    vectors = (L.arr.nrows == 1 or L.arr.ncols == 1) and (R.arr.nrows == 1 or R.arr.ncols == 1)
    res = otinum.__new__(otinum)

    if same or vectors:

        status = oarr_dot_product_OO_to(&L.arr, &R.arr, &res.num, _dhl)

    else:

        # Column-major storage of the transposes is the row-major order of the operands.
        status = oarr_transpose_to(&L.arr, &Lt, _dhl)

        if status == DN_OK:

            status = oarr_transpose_to(&R.arr, &Rt, _dhl)

        # end if

        if status == DN_OK:

            status = oarr_dot_product_OO_to(&Lt, &Rt, &res.num, _dhl)

        # end if

        oarr_free(&Lt)
        oarr_free(&Rt)

    # end if

    _status("dot_product", status)
    return _finish(res, out)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def interp1d(x, xvals, yvals, out=None):
    """
    Linear 1-D interpolation of OTI values.

    Same call as ``pyoti.sparse.interp1d``: ``xvals`` and ``yvals`` are columns, the real parts of
    ``xvals`` strictly increasing. Outside the data range the first or last ordinate is returned;
    inside, m (x - x_i) + y_i with m the OTI slope of the bracketing interval.

    Parameters
    ----------
    x : otinum or float or omat or arro
        Point(s) to interpolate at.
    xvals : omat or arro
        Abscissas, n x 1.
    yvals : omat or arro
        Ordinates, n x 1.
    out : same type as the result, optional
        Holder for the result.

    Returns
    -------
    otinum or omat or arro
        Interpolated value(s), or None when ``out`` is given.

    Examples
    --------
    >>> xv = oti.array([[0.0], [1.0]])
    >>> yv = oti.array([[0.0], [2.0]])
    >>> oti.interp1d(0.5 + oti.e(1, order=1), xv, yv).get_im(1)
    2.0
    """

    cdef omat X = _order_to_soa(xvals, "interp1d")
    cdef omat Y = _order_to_soa(yvals, "interp1d")
    cdef omat P
    cdef otinum px, sres
    cdef oarr_t ores = oarr_init()

    if isinstance(x, Real):

        x = otinum(float(x))

    # end if

    if isinstance(x, otinum):

        px = x
        sres = otinum.__new__(otinum)
        _status("interp1d", oarr_interp1d_o_to(&X.arr, &Y.arr, &px.num, &sres.num, _dhl))
        return _finish(sres, out)

    elif isinstance(x, (omat, arro)):

        P = _order_to_soa(x, "interp1d")
        _soa_ok("interp1d", oarr_interp1d_O_to(&X.arr, &Y.arr, &P.arr, &ores, _dhl), &ores)

        if isinstance(x, arro):

            return _finish(_to_aos(omat.wrap(ores)), out)

        # end if

        return _finish(omat.wrap(ores), out)

    # end if

    raise TypeError("Unsupported type {0} in inter1d operation.".format(type(x).__name__))

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def moving_average(data, size):
    """
    Moving-average filter over a flattened OTI array with a given window size.

    Same call and result as ``pyoti.sparse.moving_average``: window positions outside the data
    repeat the first or last element. The filter is linear with real weights, so every direction
    is filtered alike.

    Parameters
    ----------
    data : omat or arro
        Data, flattened (a column in practice).
    size : int
        Window size, at least 1.

    Returns
    -------
    omat or arro
        Filtered data as an n x 1 column, of the type of ``data``.

    Examples
    --------
    >>> d = oti.array([[0.0], [3.0], [6.0]], order=1)
    >>> oti.moving_average(d, 3).real[1, 0]
    3.0
    """

    cdef omat D
    cdef oarr_t res = oarr_init()

    if not isinstance(data, (omat, arro)):

        raise TypeError("moving_average expects a dense array")

    # end if

    if size < 1:

        raise ValueError("moving_average: size must be at least 1")

    # end if

    D = _order_to_soa(data, "moving_average")
    _soa_ok("moving_average", oarr_moving_average_to(&D.arr, size, &res), &res)

    if isinstance(data, arro):

        return _to_aos(omat.wrap(res))

    # end if

    return omat.wrap(res)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def inv_block(arr, out=None):
    """
    Matrix inverse by the order-by-order block solver.

    Same call as ``pyoti.sparse.inv_block``. The dense inverse is already a block solver (one LU
    factorization of the real part, then one multi-right-hand-side solve per order), so this is
    ``inv``.

    Parameters
    ----------
    arr : omat or arro
        Square matrix with a nonsingular real part.
    out : same type as arr, optional
        Holder for the inverse.

    Returns
    -------
    omat or arro
        The inverse, or None when ``out`` is given.

    Raises
    ------
    numpy.linalg.LinAlgError
        If the real part is singular.

    Examples
    --------
    >>> K = oti.zeros((1, 1), order=1) + 2.0 + oti.e(1, order=1)
    >>> oti.inv_block(K).get_im(1)[0, 0]
    -0.25
    """

    cdef oarr_t ores = oarr_init()
    cdef arro_t ares = arro_init()

    if isinstance(arr, omat):

        if (<omat>arr).arr.nrows != (<omat>arr).arr.ncols:

            raise ValueError("inv_block: matrix must be square")

        # end if

        _soa_ok("inv_block", oarr_inv_to(&(<omat>arr).arr, &ores, _dhl), &ores)
        return _finish(omat.wrap(ores), out)

    elif isinstance(arr, arro):

        if (<arro>arr).arr.nrows != (<arro>arr).arr.ncols:

            raise ValueError("inv_block: matrix must be square")

        # end if

        _aos_ok("inv_block", arro_inv_to(&(<arro>arr).arr, &ares, _dhl), &ares)
        return _finish(arro.wrap(ares), out)

    # end if

    raise TypeError("Unsupported types at Block-solver inverse operation.")

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef np.ndarray _order_deltas(object bases, object deltas, bases_t nact):
    """
    Deltas of the bases 1..nact, from a list of base labels (0 for bases not listed).

    Parameters
    ----------
    bases : sequence of int
        Base labels; labels above ``nact`` are ignored (their coefficients are zero).
    deltas : sequence of float
        One delta per base.
    nact : int
        Number of active bases of the value.

    Returns
    -------
    numpy.ndarray
        max(nact, 1) reals; entry u is the delta of base u + 1 (at least one entry, so the buffer
        is never empty).
    """

    cdef np.ndarray[np.float64_t, ndim=1] loc = np.zeros(max(<int>nact, 1), dtype=np.float64)
    cdef object b, d

    if len(bases) != len(deltas):

        raise ValueError("Both bases and deltas must have the same dimension")

    # end if

    for b, d in zip(bases, deltas):

        if b < 1 or b > 65535:

            raise ValueError("rom_eval: base labels must be between 1 and 65535")

        # end if

        if b <= nact:

            loc[b - 1] = d

        # end if

    # end for

    return loc

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _order_rom_eval(value, bases, deltas):
    """
    Taylor-polynomial (ROM) evaluation of a scalar or an array at real deltas.

    Parameters
    ----------
    value : otinum or omat or arro
        Value to evaluate.
    bases : sequence of int or None
        Base labels. For arrays, None (or a real ``deltas``) applies ``deltas`` to every base
        1..nact, as sparse's fallback intends.
    deltas : sequence of float or float
        Delta of each base.

    Returns
    -------
    otinum or omat or arro
        Real value(s) (truncation order 0) of the polynomial.
    """

    cdef np.ndarray loc
    cdef omat S
    cdef arro A, R
    cdef oarr_t ores = oarr_init()
    cdef bases_t nact
    cdef uint64_t e
    cdef coeff_t val

    if isinstance(value, otinum):

        loc = _order_deltas(bases, deltas, (<otinum>value).num.nact)
        val = oti_rom_eval(&(<otinum>value).num, <coeff_t *>loc.data)
        return otinum(val)

    elif isinstance(value, (omat, arro)):

        nact = (<omat>value).arr.nact if isinstance(value, omat) else _order_aos_nact(value)

        if bases is None or isinstance(deltas, Real):

            bases = list(range(1, nact + 1))
            deltas = [float(deltas)] * nact

        # end if

        loc = _order_deltas(bases, deltas, nact)

        if isinstance(value, omat):

            S = value
            _soa_ok("rom_eval", oarr_rom_eval_to(&S.arr, <coeff_t *>loc.data, &ores), &ores)
            return omat.wrap(ores)

        # end if

        # Every element is a prefix of bases 1..nact, so the same deltas serve all of them.
        A = value
        R = _order_aos_zeros(A.arr.nrows, A.arr.ncols, "rom_eval")

        for e in range(A.arr.size):

            val = oti_rom_eval(&A.arr.p_data[e], <coeff_t *>loc.data)
            _status("rom_eval", arro_set_item_r(val, e // A.arr.ncols, e % A.arr.ncols, &R.arr))

        # end for

        return R

    # end if

    raise TypeError("rom_eval: unsupported type {0}".format(type(value).__name__))

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _order_rom_eval_array(otinum value, bases, deltas):
    """
    ROM evaluation of a scalar at many points: one NumPy array of deltas per base.

    Parameters
    ----------
    value : otinum
        Scalar to evaluate.
    bases : sequence of int
        Base labels; labels above nact are ignored.
    deltas : sequence of numpy.ndarray
        Deltas of each base, all of the same shape.

    Returns
    -------
    numpy.ndarray
        Values of the polynomial, of the shape of ``deltas[0]``.
    """

    cdef bases_t k = value.num.nact
    cdef object shape, b, d
    cdef np.ndarray[np.float64_t, ndim=2] D
    cdef np.ndarray[np.float64_t, ndim=1] res
    cdef uint64_t npts

    if len(bases) != len(deltas):

        raise ValueError("Both bases and deltas must have the same dimension")

    # end if

    if len(deltas) == 0:

        raise ValueError("rom_eval_array needs at least one array of deltas")

    # end if

    shape = np.shape(deltas[0])
    npts = int(np.prod(shape))
    _order_check_bytes((max(<int>k, 1) + 1) * <object>npts, "rom_eval_array")
    D = np.zeros((max(<int>k, 1), npts), dtype=np.float64)

    for b, d in zip(bases, deltas):

        if b < 1 or b > 65535:

            raise ValueError("rom_eval_array: base labels must be between 1 and 65535")

        # end if

        if np.shape(d) != shape:

            raise ValueError("rom_eval_array: every array of deltas must have the same shape")

        # end if

        if b <= k:

            D[b - 1, :] = np.asarray(d, dtype=np.float64).ravel()

        # end if

    # end for

    res = np.empty(npts, dtype=np.float64)

    if npts > 0:

        _status("rom_eval_array",
                oti_rom_eval_points(&value.num, <coeff_t *>D.data, npts, <coeff_t *>res.data))

    # end if

    return res.reshape(shape)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _order_rom_eval_object(otinum value, bases, deltas):
    """
    ROM evaluation of a scalar with arbitrary Python objects as deltas (e.g. OTI numbers).

    Parameters
    ----------
    value : otinum
        Scalar to evaluate.
    bases : sequence of int
        Base labels.
    deltas : sequence of object
        Delta of each base; must support ``*`` and ``+`` with floats.

    Returns
    -------
    object
        re + sum_d c_d prod_{b in d} delta_b, summed in global direction order as sparse does.
    """

    cdef bases_t k = value.num.nact
    cdef bases_t u[256]
    cdef ord_t top = min(value.num.act_order, value.num.trc_order), p, i
    cdef ndir_t Np, j, off
    cdef coeff_t coeff
    cdef dict lookup
    cdef list loc
    cdef object res, prod

    if len(bases) != len(deltas):

        raise ValueError("Both bases and deltas must have the same dimension")

    # end if

    lookup = {b: d for b, d in zip(bases, deltas)}
    loc = [lookup.get(i + 1, 0) for i in range(k)]
    res = value.num.re

    for p in range(1, top + 1):

        Np = sshelp_ndir_order(k, p)
        off = sshelp_order_offset(k, p)

        for j in range(Np):

            coeff = value.num.p_im[off + j]

            if coeff == 0.0:

                continue

            # end if

            sshelp_unrank(j, p, u)
            prod = 1

            for i in range(p):

                prod = prod * loc[u[i]]

            # end for

            res = res + prod * coeff

        # end for

    # end for

    return res

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _order_get_all_ims(value, nbasis, order, bint derivs):
    """
    Export every coefficient (or derivative) in the layout of matso.get_all_ims.

    Parameters
    ----------
    value : otinum or omat or arro
        Value to export.
    nbasis : int
        Number of global bases of the layout.
    order : int
        Highest order of the layout.
    derivs : bool
        True to export derivatives.

    Returns
    -------
    numpy.ndarray
        For arrays, shape (C(nbasis + order, order), nrows, ncols); entry [d, i, j] is global
        position d (0 = real part, then orders by global index) of element (i, j). For a scalar,
        shape (C(nbasis + order, order),). Directions using a base above ``nbasis`` are left out.

    Raises
    ------
    MemoryError
        If the layout exceeds the dense byte budget (``dn_max_bytes``).
    """

    cdef object ndir
    cdef np.ndarray[np.float64_t, ndim=3] res
    cdef np.ndarray[np.float64_t, ndim=1] vec
    cdef omat S
    cdef arro A
    cdef uint64_t i, j, nr, nc

    if nbasis < 0 or nbasis > 65535:

        raise ValueError("get_all_ims: nbasis must be between 0 and 65535")

    # end if

    _check_order(order)
    ndir = comb(nbasis + order, order)

    if isinstance(value, otinum):

        _order_check_bytes(ndir, "get_all_ims")
        vec = np.zeros(ndir, dtype=np.float64)
        oti_get_all_ims_to(&(<otinum>value).num, nbasis, order, derivs, &vec[0], 1)
        return vec

    elif isinstance(value, omat):

        S = value
        _order_check_bytes(ndir * S.arr.nrows * S.arr.ncols, "get_all_ims")
        res = np.empty((ndir, S.arr.nrows, S.arr.ncols), dtype=np.float64)

        if res.size > 0:

            _status("get_all_ims",
                    oarr_get_all_ims_to(&S.arr, nbasis, order, derivs, <coeff_t *>res.data))

        # end if

        return res

    elif isinstance(value, arro):

        A = value
        nr = A.arr.nrows
        nc = A.arr.ncols
        _order_check_bytes(ndir * nr * nc, "get_all_ims")
        res = np.zeros((ndir, nr, nc), dtype=np.float64)

        for i in range(nr):

            for j in range(nc):

                oti_get_all_ims_to(&A.arr.p_data[j + i * nc], nbasis, order, derivs, &res[0, i, j],
                                   nr * nc)

            # end for

        # end for

        return res

    # end if

    raise TypeError("get_all_ims: unsupported type {0}".format(type(value).__name__))

# end function
# --------------------------------------------------------------------------------------------------------
