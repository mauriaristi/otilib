# Phase 2: order and derivative plumbing, truncated products, rom_eval, interp1d, inv_block.
# (PLAN-semisparse-sparse-leveling.md)
#
# Module functions keep the names and signatures of pyoti.sparse. The kernels are in C
# (src/c/semisparse/{scalar,soa}/utils.c); AoS arrays run the scalar kernels per element, or go
# through the SoA layout for matrix products. Methods of the classes (rom_eval*, get_all_ims,
# get_all_derivs, extract_im, extract_deriv) delegate to the _order_* helpers below.


# ********************************************************************************************************
cdef object _order_out(object result, object out):
    """
    Return a result, or copy it into a holder of the same type.

    Parameters
    ----------
    result : ssotinum or oarrss or arrss
        Computed result.
    out : object
        Holder, or None.

    Returns
    -------
    object
        ``result`` when ``out`` is None, otherwise None.
    """

    if out is None:

        return result

    # end if

    if isinstance(result, ssotinum) and isinstance(out, ssotinum):

        ssoti_copy_to(&(<ssotinum>result).num, &(<ssotinum>out).num)

    elif isinstance(result, oarrss) and isinstance(out, oarrss):

        oarrss_copy_to(&(<oarrss>result).arr, &(<oarrss>out).arr)

    elif isinstance(result, arrss) and isinstance(out, arrss):

        arrss_copy_to(&(<arrss>result).arr, &(<arrss>out).arr)

    else:

        raise TypeError("out must be a {0}, got {1}".format(type(result).__name__,
                                                           type(out).__name__))

    # end if

    return None

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef oarrss _order_to_soa(object value, str op):
    """
    Return a SoA view of an array operand: SoA as is, AoS converted, real arrays copied.

    Parameters
    ----------
    value : oarrss or arrss or array_like
        Array operand.
    op : str
        Operation name, for error messages.

    Returns
    -------
    oarrss
        SoA array (the operand itself when it already is one).
    """

    cdef oarrss_t res = oarrss_init()
    cdef object real

    if isinstance(value, oarrss):

        return value

    # end if

    if isinstance(value, arrss):

        arrss_to_oarrss(&(<arrss>value).arr, &res)
        return oarrss.wrap(res)

    # end if

    if isinstance(value, (np.ndarray, list, tuple)):

        real = np.asarray(value, dtype=np.float64)

        if real.ndim == 1:

            real = real.reshape((-1, 1))

        # end if

        return oarrss.from_real(real)

    # end if

    raise TypeError("{0}: unsupported operand type {1}".format(op, type(value).__name__))

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef arrss _order_to_aos(oarrss value):
    """
    Convert a SoA array to AoS.

    Parameters
    ----------
    value : oarrss
        SoA array.

    Returns
    -------
    arrss
        Newly allocated AoS array.
    """

    cdef arrss_t res = arrss_init()

    arrss_from_oarrss(&value.arr, &res)
    return arrss.wrap(res)

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
def get_order_im(order, val, out=None):
    """
    Extract one order of a semi-sparse value, with every other order (and the real part) zeroed.

    Same call as ``pyoti.sparse.get_order_im``. Order 0 keeps only the real part.

    Parameters
    ----------
    order : int
        Order to keep.
    val : ssotinum or oarrss or arrss
        Value.
    out : same type as val, optional
        Holder for the result.

    Returns
    -------
    ssotinum or oarrss or arrss
        The order-``order`` part, or None when ``out`` is given.

    Examples
    --------
    >>> x = oti.e(1, order=2) + 3 * oti.e([1, 2], order=2)
    >>> oti.get_order_im(2, x).get_im([1, 2])
    3.0
    """

    cdef ssotinum_t sres = ssoti_init()
    cdef oarrss_t ores = oarrss_init()
    cdef arrss_t ares = arrss_init()

    if order < 0 or order > 255:

        raise ValueError("get_order_im: order must be between 0 and 255")

    # end if

    if isinstance(val, ssotinum):

        ssoti_get_order_im_to(order, &(<ssotinum>val).num, &sres)
        return _order_out(ssotinum.wrap(sres), out)

    elif isinstance(val, oarrss):

        oarrss_get_order_im_to(order, &(<oarrss>val).arr, &ores)
        return _order_out(oarrss.wrap(ores), out)

    elif isinstance(val, arrss):

        arrss_get_order_im_to(order, &(<arrss>val).arr, &ares, _dhl)
        return _order_out(arrss.wrap(ares), out)

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
    val : ssotinum or oarrss or arrss
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

    cdef tuple pair = _direction(humdir)
    cdef imdir_t idx = pair[0]
    cdef ord_t order = pair[1]
    cdef ssotinum_t sres = ssoti_init()
    cdef oarrss_t ores = oarrss_init()
    cdef arrss A, R
    cdef uint64_t e

    if isinstance(val, ssotinum):

        if deriv:

            ssoti_extract_deriv_to(idx, order, &(<ssotinum>val).num, &sres)

        else:

            ssoti_extract_im_to(idx, order, &(<ssotinum>val).num, &sres)

        # end if

        return _order_out(ssotinum.wrap(sres), out)

    elif isinstance(val, oarrss):

        if deriv:

            oarrss_extract_deriv_to(idx, order, &(<oarrss>val).arr, &ores)

        else:

            oarrss_extract_im_to(idx, order, &(<oarrss>val).arr, &ores)

        # end if

        return _order_out(oarrss.wrap(ores), out)

    elif isinstance(val, arrss):

        A = val
        R = arrss.wrap(arrss_zeros(A.arr.nrows, A.arr.ncols, 0))

        for e in range(A.arr.size):

            if deriv:

                ssoti_extract_deriv_to(idx, order, &A.arr.p_data[e], &R.arr.p_data[e])

            else:

                ssoti_extract_im_to(idx, order, &A.arr.p_data[e], &R.arr.p_data[e])

            # end if

        # end for

        return _order_out(R, out)

    # end if

    raise TypeError("Unsupported type {0} at extract_{1}.".format(type(val).__name__,
                                                                 "deriv" if deriv else "im"))

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def extract_im(humdir, val, out=None):
    """
    Extract the coefficients that contain an imaginary direction, divided by it.

    Same call and result as ``pyoti.sparse.extract_im``: coefficient d / g of the result is
    coefficient d of ``val``. The result keeps the active set, with truncation order lowered by the
    order of the direction.

    Parameters
    ----------
    humdir : int or list or tuple or rawdir
        Direction g.
    val : ssotinum or oarrss or arrss
        Value.
    out : same type as val, optional
        Holder for the result.

    Returns
    -------
    ssotinum or oarrss or arrss
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
    val : ssotinum or oarrss or arrss
        Value.
    out : same type as val, optional
        Holder for the result.

    Returns
    -------
    ssotinum or oarrss or arrss
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
    tmp : oarrss or arrss
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

    cdef oarrss S
    cdef arrss A
    cdef bases_t mb = 0, mbe
    cdef uint64_t i, j, nr, nc
    cdef object width
    cdef np.ndarray[np.float64_t, ndim=2] res

    if ordi < 0 or ordi > 255:

        raise ValueError("get_order_im_array: order must be between 0 and 255")

    # end if

    if isinstance(tmp, oarrss):

        S = tmp

        if ordi > 0:

            mb = oarrss_order_max_base(ordi, &S.arr)

        # end if

        width = _order_width(ordi, mb)
        res = np.empty((S.arr.nrows, S.arr.ncols * width), dtype=np.float64)

        if res.size > 0:

            oarrss_get_order_im_array_to(ordi, &S.arr, width, <coeff_t *>res.data)

        # end if

        return res

    elif isinstance(tmp, arrss):

        A = tmp
        nr = A.arr.nrows
        nc = A.arr.ncols

        if ordi > 0:

            for i in range(A.arr.size):

                mbe = ssoti_order_max_base(ordi, &A.arr.p_data[i])
                mb = mbe if mbe > mb else mb

            # end for

        # end if

        width = _order_width(ordi, mb)
        res = np.zeros((nr, nc * width), dtype=np.float64)

        for i in range(nr):

            for j in range(nc):

                ssoti_scatter_order_im(ordi, &A.arr.p_data[j + i * nc], width, &res[i, j], nc)

            # end for

        # end for

        return res

    # end if

    raise TypeError("Unsupported type {0} at get_order_im_array.".format(type(tmp).__name__))

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def set_order_im_from_array(ordi, arr, tmp):
    """
    Add one order to an OTI array from a real matrix with the directions side by side.

    Same call as ``pyoti.sparse.set_order_im_from_array`` and the inverse layout of
    ``get_order_im_array``: ``arr[i, j + ncols * g]`` is added to element (i, j) along the
    order-``ordi`` direction with global index g. ``tmp`` is modified in place; its active set
    grows by the bases of every nonzero direction and its truncation order is raised to ``ordi``
    when lower. Order 0 adds to the real part.

    Parameters
    ----------
    ordi : int
        Order to add.
    arr : numpy.ndarray
        Real matrix of shape (nrows, ncols * width).
    tmp : oarrss or arrss
        Array that receives the coefficients.

    Examples
    --------
    >>> A = oti.zeros((1, 1), order=1)
    >>> oti.set_order_im_from_array(1, np.array([[0.0, 5.0]]), A)
    >>> A[0, 0].get_im(2)
    5.0
    """

    cdef np.ndarray[np.float64_t, ndim=2] vals = np.ascontiguousarray(arr, dtype=np.float64)
    cdef oarrss S
    cdef arrss A
    cdef uint64_t nr, nc, i, j
    cdef ndir_t width

    if ordi < 0 or ordi > 255:

        raise ValueError("set_order_im_from_array: order must be between 0 and 255")

    # end if

    if isinstance(tmp, oarrss):

        nr = (<oarrss>tmp).arr.nrows
        nc = (<oarrss>tmp).arr.ncols

    elif isinstance(tmp, arrss):

        nr = (<arrss>tmp).arr.nrows
        nc = (<arrss>tmp).arr.ncols

    else:

        raise TypeError("Unsupported type {0} at set_order_im_from_array.".format(
            type(tmp).__name__))

    # end if

    if vals.shape[0] != nr or nc == 0 or vals.shape[1] % nc != 0:

        raise ValueError("set_order_im_from_array: array of shape {0} does not match {1}".format(
            (vals.shape[0], vals.shape[1]), (nr, nc)))

    # end if

    width = vals.shape[1] // nc

    if width == 0 or nr == 0:

        return None

    # end if

    if isinstance(tmp, oarrss):

        S = tmp
        oarrss_add_order_im_array(ordi, <coeff_t *>vals.data, width, &S.arr)

    else:

        A = tmp

        for i in range(nr):

            for j in range(nc):

                ssoti_add_order_im_global(ordi, &vals[i, j], width, nc, &A.arr.p_data[j + i * nc])

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
    their order (ordlhs + ordrhs) product is kept. Order 0 selects the real part. The result is
    over the union of the active sets with the larger truncation order.

    Parameters
    ----------
    ordlhs : int
        Order taken from ``lhs``.
    lhs : oarrss or arrss
        Left matrix.
    ordrhs : int
        Order taken from ``rhs``.
    rhs : oarrss or arrss
        Right matrix.
    out : oarrss or arrss, optional
        Holder for the result (same type as the result).

    Returns
    -------
    oarrss or arrss
        The product (AoS only when both operands are AoS), or None when ``out`` is given.

    Examples
    --------
    >>> K = oti.zeros((2, 2), order=2) + oti.e(1, order=2)
    >>> X = oti.zeros((2, 1), order=2) + 1.0
    >>> oti.trunc_dot(1, K, 0, X).get_im(1)[0, 0]
    2.0
    """

    cdef oarrss L, R
    cdef oarrss_t res = oarrss_init()
    cdef int status
    cdef bint aos = isinstance(lhs, arrss) and isinstance(rhs, arrss)

    if ordlhs < 0 or ordlhs > 255 or ordrhs < 0 or ordrhs > 255:

        raise ValueError("trunc_dot: orders must be between 0 and 255")

    # end if

    if not isinstance(lhs, (oarrss, arrss)) or not isinstance(rhs, (oarrss, arrss, np.ndarray)):

        raise TypeError("Unsupported types {0}, {1} at trunc_dot operation.".format(
            type(lhs).__name__, type(rhs).__name__))

    # end if

    L = _order_to_soa(lhs, "trunc_dot")
    R = _order_to_soa(rhs, "trunc_dot")

    if L.arr.ncols != R.arr.nrows:

        raise ValueError("trunc_dot: shapes {0} and {1} not aligned".format(
            (L.arr.nrows, L.arr.ncols), (R.arr.nrows, R.arr.ncols)))

    # end if

    status = oarrss_trunc_matmul_OO_to(ordlhs, &L.arr, ordrhs, &R.arr, &res, _dhl)

    if status != 0:

        oarrss_free(&res)
        _status("trunc_dot", status)

    # end if

    if aos:

        return _order_out(_order_to_aos(oarrss.wrap(res)), out)

    # end if

    return _order_out(oarrss.wrap(res), out)

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
    Olhs : ssotinum or oarrss or arrss
        First operand.
    Orhs : same type as Olhs
        Second operand, same shape.
    out : same type as Olhs, optional
        Holder for the result; may be one of the operands.

    Returns
    -------
    ssotinum or oarrss or arrss
        The order-``order`` part of the difference, or None when ``out`` is given.

    Examples
    --------
    >>> a = 1 + oti.e(1, order=2) + oti.e([1, 1], order=2)
    >>> oti.trunc_sub(1, a, 0.5 * a).get_im(1)
    0.5
    """

    cdef ssotinum_t sres = ssoti_init()
    cdef oarrss_t ores = oarrss_init()
    cdef arrss A, B, C
    cdef uint64_t e
    cdef int status

    if order < 0 or order > 255:

        raise ValueError("trunc_sub: order must be between 0 and 255")

    # end if

    if isinstance(Olhs, ssotinum) and isinstance(Orhs, ssotinum):

        ssoti_trunc_sub_to(order, &(<ssotinum>Olhs).num, &(<ssotinum>Orhs).num, &sres)
        return _order_out(ssotinum.wrap(sres), out)

    elif isinstance(Olhs, oarrss) and isinstance(Orhs, oarrss):

        status = oarrss_trunc_sub_OO_to(order, &(<oarrss>Olhs).arr, &(<oarrss>Orhs).arr, &ores)

        if status != 0:

            oarrss_free(&ores)
            _status("trunc_sub", status)

        # end if

        return _order_out(oarrss.wrap(ores), out)

    elif isinstance(Olhs, arrss) and isinstance(Orhs, arrss):

        A = Olhs
        B = Orhs

        if A.arr.nrows != B.arr.nrows or A.arr.ncols != B.arr.ncols:

            raise ValueError("trunc_sub: shapes {0} and {1} differ".format(
                (A.arr.nrows, A.arr.ncols), (B.arr.nrows, B.arr.ncols)))

        # end if

        C = arrss.wrap(arrss_zeros(A.arr.nrows, A.arr.ncols, 0))

        for e in range(A.arr.size):

            ssoti_trunc_sub_to(order, &A.arr.p_data[e], &B.arr.p_data[e], &C.arr.p_data[e])

        # end for

        return _order_out(C, out)

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

    Parameters
    ----------
    lhs : oarrss or arrss or numpy.ndarray
        First array.
    rhs : oarrss or arrss or numpy.ndarray
        Second array, same number of elements.
    out : ssotinum, optional
        Holder for the result.

    Returns
    -------
    ssotinum
        The dot product, or None when ``out`` is given.

    Examples
    --------
    >>> a = oti.zeros((3, 1), order=1) + oti.e(1, order=1)
    >>> oti.dot_product(a, np.ones((1, 3))).get_im(1)
    3.0
    """

    cdef oarrss L, R
    cdef oarrss_t Lt = oarrss_init(), Rt = oarrss_init()
    cdef ssotinum_t res = ssoti_init()
    cdef bint same, vectors
    cdef int status

    # Gauss-point operands (semisparse/gauss/base.pxi) handle every mix, and out=, themselves.
    if isinstance(lhs, _ssfe) or isinstance(rhs, _ssfe):

        return _fe_dot_product(lhs, rhs, out)

    # end if

    if not isinstance(lhs, (oarrss, arrss)) and not isinstance(rhs, (oarrss, arrss)):

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

    if same or vectors:

        status = oarrss_dot_product_OO_to(&L.arr, &R.arr, &res, _dhl)

    else:

        # Column-major storage of the transposes is the row-major order of the operands.
        oarrss_transpose_to(&L.arr, &Lt, _dhl)
        oarrss_transpose_to(&R.arr, &Rt, _dhl)
        status = oarrss_dot_product_OO_to(&Lt, &Rt, &res, _dhl)
        oarrss_free(&Lt)
        oarrss_free(&Rt)

    # end if

    if status != 0:

        ssoti_free(&res)
        _status("dot_product", status)

    # end if

    return _order_out(ssotinum.wrap(res), out)

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
    x : ssotinum or float or oarrss or arrss
        Point(s) to interpolate at.
    xvals : oarrss or arrss
        Abscissas, n x 1.
    yvals : oarrss or arrss
        Ordinates, n x 1.
    out : same type as the result, optional
        Holder for the result.

    Returns
    -------
    ssotinum or oarrss or arrss
        Interpolated value(s), or None when ``out`` is given.

    Examples
    --------
    >>> xv = oti.zeros((2, 1)) + np.array([[0.0], [1.0]])
    >>> yv = oti.zeros((2, 1)) + np.array([[0.0], [2.0]])
    >>> oti.interp1d(0.5 + oti.e(1, order=1), xv, yv).get_im(1)
    2.0
    """

    cdef oarrss X = _order_to_soa(xvals, "interp1d")
    cdef oarrss Y = _order_to_soa(yvals, "interp1d")
    cdef oarrss P
    cdef ssotinum px
    cdef ssotinum_t sres = ssoti_init()
    cdef oarrss_t ores = oarrss_init()
    cdef int status

    if isinstance(x, Real):

        x = ssotinum(float(x))

    # end if

    if isinstance(x, ssotinum):

        px = x
        status = oarrss_interp1d_o_to(&X.arr, &Y.arr, &px.num, &sres, _dhl)

        if status != 0:

            ssoti_free(&sres)
            _status("interp1d", status)

        # end if

        return _order_out(ssotinum.wrap(sres), out)

    elif isinstance(x, (oarrss, arrss)):

        P = _order_to_soa(x, "interp1d")
        status = oarrss_interp1d_O_to(&X.arr, &Y.arr, &P.arr, &ores, _dhl)

        if status != 0:

            oarrss_free(&ores)
            _status("interp1d", status)

        # end if

        if isinstance(x, arrss):

            return _order_out(_order_to_aos(oarrss.wrap(ores)), out)

        # end if

        return _order_out(oarrss.wrap(ores), out)

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
    data : oarrss or arrss
        Data, flattened (a column in practice).
    size : int
        Window size, at least 1.

    Returns
    -------
    oarrss or arrss
        Filtered data as an n x 1 column, of the type of ``data``.

    Examples
    --------
    >>> d = oti.zeros((3, 1), order=1) + np.array([[0.0], [3.0], [6.0]])
    >>> oti.moving_average(d, 3).real[1, 0]
    3.0
    """

    cdef oarrss D = _order_to_soa(data, "moving_average")
    cdef oarrss_t res = oarrss_init()
    cdef int status

    if not isinstance(data, (oarrss, arrss)):

        raise TypeError("moving_average expects a semi-sparse array")

    # end if

    if size < 1:

        raise ValueError("moving_average: size must be at least 1")

    # end if

    status = oarrss_moving_average_to(&D.arr, size, &res)

    if status != 0:

        oarrss_free(&res)
        _status("moving_average", status)

    # end if

    if isinstance(data, arrss):

        return _order_to_aos(oarrss.wrap(res))

    # end if

    return oarrss.wrap(res)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def inv_block(arr, out=None):
    """
    Matrix inverse by the order-by-order block solver.

    Same call as ``pyoti.sparse.inv_block``. The semi-sparse inverse is already a block solver
    (one LU factorization of the real part, then one multi-right-hand-side solve per order), so
    this is ``inv``.

    Parameters
    ----------
    arr : oarrss or arrss
        Square matrix with a nonsingular real part.
    out : same type as arr, optional
        Holder for the inverse.

    Returns
    -------
    oarrss or arrss
        The inverse, or None when ``out`` is given.

    Examples
    --------
    >>> K = oti.zeros((1, 1), order=1) + 2.0 + oti.e(1, order=1)
    >>> oti.inv_block(K).get_im(1)[0, 0]
    -0.25
    """

    cdef oarrss_t ores = oarrss_init()
    cdef arrss_t ares = arrss_init()
    cdef int status

    if isinstance(arr, oarrss):

        if (<oarrss>arr).arr.nrows != (<oarrss>arr).arr.ncols:

            raise ValueError("inv_block: matrix must be square")

        # end if

        status = oarrss_inv_to(&(<oarrss>arr).arr, &ores, _dhl)

        if status != 0:

            oarrss_free(&ores)
            _status("inv_block", status)

        # end if

        return _order_out(oarrss.wrap(ores), out)

    elif isinstance(arr, arrss):

        if (<arrss>arr).arr.nrows != (<arrss>arr).arr.ncols:

            raise ValueError("inv_block: matrix must be square")

        # end if

        status = arrss_inv_to(&(<arrss>arr).arr, &ares, _dhl)

        if status != 0:

            arrss_free(&ares)
            _status("inv_block", status)

        # end if

        return _order_out(arrss.wrap(ares), out)

    # end if

    raise TypeError("Unsupported types at Block-solver inverse operation.")

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef np.ndarray _order_global_deltas(object bases, object deltas, str op):
    """
    Deltas indexed by global base label (0 for bases not listed).

    Parameters
    ----------
    bases : sequence of int
        Base labels.
    deltas : sequence of float
        One delta per base.
    op : str
        Operation name, for error messages.

    Returns
    -------
    numpy.ndarray
        Array of 65536 reals; entry b is the delta of base b.
    """

    cdef np.ndarray[np.float64_t, ndim=1] g = np.zeros(65536, dtype=np.float64)
    cdef object b

    if len(bases) != len(deltas):

        raise ValueError("Both bases and deltas must have the same dimension")

    # end if

    for b, d in zip(bases, deltas):

        if b < 1 or b > 65535:

            raise ValueError("{0}: base labels must be between 1 and 65535".format(op))

        # end if

        g[b] = d

    # end for

    return g

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef np.ndarray _order_local_deltas(const bases_t *p_bases, bases_t k, np.ndarray gdeltas):
    """
    Deltas of a number's active bases, in local order.

    Parameters
    ----------
    p_bases : bases_t pointer
        Sorted active bases.
    k : int
        Number of active bases.
    gdeltas : numpy.ndarray
        Deltas indexed by global base label (``_order_global_deltas``).

    Returns
    -------
    numpy.ndarray
        One delta per active base (at least one entry, so the buffer is never empty).
    """

    cdef np.ndarray[np.float64_t, ndim=1] loc = np.zeros(max(<int>k, 1), dtype=np.float64)
    cdef np.ndarray[np.float64_t, ndim=1] g = gdeltas
    cdef bases_t u

    for u in range(k):

        loc[u] = g[p_bases[u]]

    # end for

    return loc

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef list _order_item_bases(const ssotinum_t *num):
    """
    Active bases of a native scalar.

    Parameters
    ----------
    num : ssotinum_t pointer
        Scalar.

    Returns
    -------
    list
        Sorted base labels.
    """

    cdef bases_t u

    return [num.p_bases[u] for u in range(num.nbases)]

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _order_rom_eval(value, bases, deltas):
    """
    Taylor-polynomial (ROM) evaluation of a scalar or an array at real deltas.

    Parameters
    ----------
    value : ssotinum or oarrss or arrss
        Value to evaluate.
    bases : sequence of int or None
        Base labels. For arrays, None (or a real ``deltas``) applies ``deltas`` to every active
        base, as sparse's fallback intends.
    deltas : sequence of float or float
        Delta of each base.

    Returns
    -------
    ssotinum or oarrss or arrss
        Real value(s) (truncation order 0) of the polynomial.
    """

    cdef np.ndarray gd, loc
    cdef ssotinum s
    cdef oarrss S
    cdef arrss A, R
    cdef oarrss_t ores = oarrss_init()
    cdef uint64_t e
    cdef coeff_t val

    if isinstance(value, (oarrss, arrss)) and (bases is None or isinstance(deltas, Real)):

        if isinstance(value, oarrss):

            bases = list((<oarrss>value).active_bases)

        else:

            A = value
            bases = []

            for e in range(A.arr.size):

                bases.extend(_order_item_bases(&A.arr.p_data[e]))

            # end for

            bases = sorted(set(bases))

        # end if

        deltas = [float(deltas)] * len(bases)

    # end if

    gd = _order_global_deltas(bases, deltas, "rom_eval")

    if isinstance(value, ssotinum):

        s = value
        loc = _order_local_deltas(s.num.p_bases, s.num.nbases, gd)
        val = ssoti_rom_eval(&s.num, <coeff_t *>loc.data)
        return ssotinum.wrap(ssoti_create_r(val, 0))

    elif isinstance(value, oarrss):

        S = value
        loc = _order_local_deltas(S.arr.p_bases, S.arr.nbases, gd)
        oarrss_rom_eval_to(&S.arr, <coeff_t *>loc.data, &ores)
        return oarrss.wrap(ores)

    elif isinstance(value, arrss):

        A = value
        R = arrss.wrap(arrss_zeros(A.arr.nrows, A.arr.ncols, 0))

        for e in range(A.arr.size):

            loc = _order_local_deltas(A.arr.p_data[e].p_bases, A.arr.p_data[e].nbases, gd)
            val = ssoti_rom_eval(&A.arr.p_data[e], <coeff_t *>loc.data)
            arrss_set_item_r(val, e // A.arr.ncols, e % A.arr.ncols, &R.arr)

        # end for

        return R

    # end if

    raise TypeError("rom_eval: unsupported type {0}".format(type(value).__name__))

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _order_rom_eval_array(ssotinum value, bases, deltas):
    """
    ROM evaluation of a scalar at many points: one NumPy array of deltas per base.

    Parameters
    ----------
    value : ssotinum
        Scalar to evaluate.
    bases : sequence of int
        Base labels.
    deltas : sequence of numpy.ndarray
        Deltas of each base, all of the same shape.

    Returns
    -------
    numpy.ndarray
        Values of the polynomial, of the shape of ``deltas[0]``.
    """

    cdef bases_t k = value.num.nbases, u
    cdef object shape
    cdef dict lookup
    cdef np.ndarray[np.float64_t, ndim=2] D
    cdef np.ndarray[np.float64_t, ndim=1] res
    cdef uint64_t npts
    cdef int status

    if len(bases) != len(deltas):

        raise ValueError("Both bases and deltas must have the same dimension")

    # end if

    if len(deltas) == 0:

        raise ValueError("rom_eval_array needs at least one array of deltas")

    # end if

    shape = np.shape(deltas[0])
    npts = int(np.prod(shape))
    lookup = {b: i for i, b in enumerate(bases)}
    D = np.zeros((max(<int>k, 1), npts), dtype=np.float64)

    for u in range(k):

        if value.num.p_bases[u] in lookup:

            D[u, :] = np.asarray(deltas[lookup[value.num.p_bases[u]]], dtype=np.float64).ravel()

        # end if

    # end for

    res = np.empty(npts, dtype=np.float64)

    if npts > 0:

        status = ssoti_rom_eval_points(&value.num, <coeff_t *>D.data, npts, <coeff_t *>res.data)

        if status != 0:

            raise MemoryError("rom_eval_array: allocation failed")

        # end if

    # end if

    return res.reshape(shape)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _order_rom_eval_object(ssotinum value, bases, deltas):
    """
    ROM evaluation of a scalar with arbitrary Python objects as deltas (e.g. OTI numbers).

    Parameters
    ----------
    value : ssotinum
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

    cdef bases_t k = value.num.nbases
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
    loc = [lookup.get(value.num.p_bases[i], 0) for i in range(k)]
    res = value.num.re

    for p in range(1, top + 1):

        Np = comb(k + p - 1, p)
        off = comb(k + p - 1, p - 1) - 1

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
    Export every coefficient (or derivative) of an array in the layout of matso.get_all_ims.

    Parameters
    ----------
    value : oarrss or arrss
        Array.
    nbasis : int
        Number of global bases of the layout.
    order : int
        Highest order of the layout.
    derivs : bool
        True to export derivatives.

    Returns
    -------
    numpy.ndarray
        Array of shape (C(nbasis + order, order), nrows, ncols); entry [d, i, j] is global position
        d (0 = real part, then orders by global index) of element (i, j). Directions using a base
        above ``nbasis`` are left out.
    """

    cdef object ndir
    cdef np.ndarray[np.float64_t, ndim=3] res
    cdef oarrss S
    cdef arrss A
    cdef uint64_t i, j, nr, nc

    if nbasis < 0 or nbasis > 65535 or order < 0 or order > 255:

        raise ValueError("get_all_ims: nbasis or order out of range")

    # end if

    ndir = comb(nbasis + order, order)

    if isinstance(value, oarrss):

        S = value
        res = np.empty((ndir, S.arr.nrows, S.arr.ncols), dtype=np.float64)

        if res.size > 0:

            oarrss_get_all_ims_to(&S.arr, nbasis, order, derivs, <coeff_t *>res.data)

        # end if

        return res

    elif isinstance(value, arrss):

        A = value
        nr = A.arr.nrows
        nc = A.arr.ncols
        res = np.zeros((ndir, nr, nc), dtype=np.float64)

        for i in range(nr):

            for j in range(nc):

                ssoti_get_all_ims_to(&A.arr.p_data[j + i * nc], nbasis, order, derivs, &res[0, i, j],
                                     nr * nc)

            # end for

        # end for

        return res

    # end if

    raise TypeError("get_all_ims: unsupported type {0}".format(type(value).__name__))

# end function
# --------------------------------------------------------------------------------------------------------
