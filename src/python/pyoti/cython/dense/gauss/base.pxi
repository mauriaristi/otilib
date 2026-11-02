# Gauss-point types otife / omatfe (C feoarr_t / feotinum_t, include/oti/dense/gauss/gauss.h).
# Owner: WP10 (dense-core). Template: src/python/pyoti/cython/semisparse/gauss/base.pxi.
#
# Names:
#   otife    dense scalar at nip integration points (sparse counterpart: sotife)
#   omatfe   dense SoA matrix at nip integration points (sparse counterpart: matsofe)
# Both hold one C feoarr_t: one nact and one truncation order shared by every point; the coefficients
# are an oarr_t of shape nip x (nrows * ncols), points fastest, so every elementwise operation is one
# batched SoA kernel.
#
# Hooks used by the creators (zeros/zero/one/e/number with nip > 0), by utils.pxi (_finish), by
# math.pxi and by the module functions (dot, dot_product, det, inv, transpose, sum, sub, mul, div):
# _fe_zeros, _fe_scalar, _fe_store, _fe_unary, _fe_binary, _fe_dot, _fe_dot_product, _fe_det, _fe_inv,
# _fe_transpose, _fe_arith.
#
# Views: _fe_view() wraps the embedded array in a non-owning omat (FLAGS bit 0 clear). A view is only
# ever an input of a C call, never its result (the C structs carry no ownership flag).

import operator as _operator


# ********************************************************************************************************
cdef _dnfe _fe_new(bint array):
    """
    Create an empty Gauss-point object of the requested kind.

    Parameters
    ----------
    array : bool
        True for an omatfe, False for an otife.

    Returns
    -------
    _dnfe
        New object holding an empty feoarr_t.
    """

    if array:

        return omatfe.__new__(omatfe)

    # end if

    return otife.__new__(otife)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef _dnfe _fe_take(feoarr_t *value, bint array):
    """
    Move a native Gauss array into a new Python object.

    Parameters
    ----------
    value : feoarr_t *
        Owned native value; reset to an empty array on return.
    array : bool
        True for an omatfe, False for an otife.

    Returns
    -------
    _dnfe
        Object owning the buffers.
    """

    cdef _dnfe res = _fe_new(array)

    fearr_free(&res.fe)
    res.fe = value[0]
    value[0] = fearr_init()

    return res

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef int _fe_ok(str operation, int status, feoarr_t *result) except -1:
    """
    Check the status of a Gauss-point call and free the C result before raising on a failure.

    Parameters
    ----------
    operation : str
        Name of the operation.
    status : int
        Native status (``DN_OK``, a negative ``DN_ERR_*`` code or a positive LAPACK ``info``).
    result : feoarr_t *
        C result that was being written; released on a failure (may be NULL).
    """

    if status != DN_OK:

        if result != NULL:

            fearr_free(result)

        # end if

        _status(operation, status)

    # end if

    return 0

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef _dnfe _fe_shaped(feoarr_t *res, _dnfe like, bint array):
    """
    Label a result computed into res.arr with the shape of a Gauss value, and wrap it.

    Parameters
    ----------
    res : feoarr_t *
        Result whose embedded array is nip x (nrows * ncols) of ``like``.
    like : _dnfe
        Gauss value giving the shape.
    array : bool
        True for an omatfe result.

    Returns
    -------
    _dnfe
        Wrapped result.
    """

    _fe_ok("shape", fearr_set_shape(like.fe.nrows, like.fe.ncols, like.fe.nip, res), res)

    return _fe_take(res, array)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef omat _fe_view(_dnfe value):
    """
    Return a non-owning omat view of the embedded nip x (nrows * ncols) array.

    Parameters
    ----------
    value : _dnfe
        Gauss-point object; it must outlive the view and not change while the view is used.

    Returns
    -------
    omat
        View (FLAGS bit 0 clear, so it never frees the buffers). Only ever an input.
    """

    cdef omat view = omat.__new__(omat)

    view.arr   = value.fe.arr
    view.FLAGS = 0

    return view

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef object _fe_plain(object value):
    """
    Convert sparse and AoS values to the dense scalar / SoA types used by the Gauss kernels.

    Parameters
    ----------
    value : object
        Operand.

    Returns
    -------
    object
        otinum for OTI scalars, omat for OTI matrices, the value itself otherwise.
    """

    if isinstance(value, sotinum):

        return otinum(value)

    elif isinstance(value, matso):

        return omat.from_sparse(value)

    elif isinstance(value, arro):

        return _to_soa(value)

    # end if

    return value

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef bint _fe_is_array(object value):
    """
    Tell whether a value is a Gauss-point array (as opposed to a Gauss-point scalar).

    Parameters
    ----------
    value : object
        Value.

    Returns
    -------
    bool
        True for an omatfe.
    """

    return isinstance(value, omatfe)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef object _fe_binary(_dnfe left, object other, str op, bint reverse):
    """
    Evaluate a binary elementwise operation with a Gauss-point operand.

    Gauss scalars broadcast over Gauss arrays point by point; plain OTI scalars and reals apply to
    every entry at every point; a plain OTI matrix is the same matrix at every point.

    Parameters
    ----------
    left : _dnfe
        Gauss-point operand.
    other : object
        Other operand: real, otinum/sotinum, omat/matso/arro, otife or omatfe.
    op : str
        One of "add", "sub", "mul", "div".
    reverse : bool
        True when the Gauss operand is the right-hand one (other op left).

    Returns
    -------
    otife or omatfe
        Result, or NotImplemented for unsupported operands.
    """

    cdef feoarr_t res = fearr_init()
    cdef feoarr_t tmp_a = fearr_init()
    cdef feoarr_t tmp_b = fearr_init()
    cdef feoarr_t *A = &left.fe
    cdef feoarr_t *B = NULL
    cdef coeff_t r
    cdef otinum o
    cdef omat plain
    cdef _dnfe g
    cdef bint array = _fe_is_array(left)
    cdef int status

    other = _fe_plain(other)

    if isinstance(other, Real):

        r = other

        if op == "add":

            status = oarr_sum_rO_to(r, &A.arr, &res.arr, _dhl)

        elif op == "sub":

            if reverse:

                status = oarr_sub_rO_to(r, &A.arr, &res.arr, _dhl)

            else:

                status = oarr_sub_Or_to(&A.arr, r, &res.arr, _dhl)

            # end if

        elif op == "mul":

            status = oarr_mul_rO_to(r, &A.arr, &res.arr, _dhl)

        else:

            if reverse:

                status = oarr_div_rO_to(r, &A.arr, &res.arr, _dhl)

            else:

                status = oarr_div_Or_to(&A.arr, r, &res.arr, _dhl)

            # end if

        # end if

        _fe_ok(op, status, &res)

        return _fe_shaped(&res, left, array)

    elif isinstance(other, otinum):

        o = other

        if op == "add":

            status = oarr_sum_oO_to(&o.num, &A.arr, &res.arr, _dhl)

        elif op == "sub":

            if reverse:

                status = oarr_sub_oO_to(&o.num, &A.arr, &res.arr, _dhl)

            else:

                status = oarr_sub_Oo_to(&A.arr, &o.num, &res.arr, _dhl)

            # end if

        elif op == "mul":

            status = oarr_mul_oO_to(&o.num, &A.arr, &res.arr, _dhl)

        else:

            if reverse:

                status = oarr_div_oO_to(&o.num, &A.arr, &res.arr, _dhl)

            else:

                status = oarr_div_Oo_to(&A.arr, &o.num, &res.arr, _dhl)

            # end if

        # end if

        _fe_ok(op, status, &res)

        return _fe_shaped(&res, left, array)

    elif isinstance(other, _dnfe):

        g = other
        B = &g.fe
        array = array or _fe_is_array(g)

        if B.nip != A.nip:

            raise ValueError("Gauss-point operands have different numbers of integration points")

        # end if

    elif isinstance(other, omat):

        plain = other
        _fe_ok(op, fearr_from_oarr_to(&plain.arr, A.nip, &tmp_b), &tmp_b)
        B = &tmp_b
        array = True

    else:

        return NotImplemented

    # end if

    # Broadcast a 1 x 1 operand over the other's shape (into its own temporary).
    if A.nrows != B.nrows or A.ncols != B.ncols:

        if A.nrows == 1 and A.ncols == 1:

            status = fearr_bcast_to(A, B.nrows, B.ncols, &tmp_a)
            A = &tmp_a

        elif B.nrows == 1 and B.ncols == 1:

            if B == &tmp_b:

                status = fearr_bcast_to(B, A.nrows, A.ncols, &tmp_a)
                B = &tmp_a

            else:

                status = fearr_bcast_to(B, A.nrows, A.ncols, &tmp_b)
                B = &tmp_b

            # end if

        else:

            # The message first: B may be one of the temporaries freed below.
            message = ("Gauss-point operands have incompatible shapes ({}, {}) and ({}, {})"
                       .format(A.nrows, A.ncols, B.nrows, B.ncols))
            fearr_free(&tmp_a)
            fearr_free(&tmp_b)
            raise ValueError(message)

        # end if

        if status != DN_OK:

            fearr_free(&tmp_a)
            fearr_free(&tmp_b)
            _status(op, status)

        # end if

    # end if

    if reverse:

        A, B = B, A

    # end if

    if op == "add":

        status = oarr_sum_OO_to(&A.arr, &B.arr, &res.arr, _dhl)

    elif op == "sub":

        status = oarr_sub_OO_to(&A.arr, &B.arr, &res.arr, _dhl)

    elif op == "mul":

        status = oarr_mul_OO_to(&A.arr, &B.arr, &res.arr, _dhl)

    else:

        status = oarr_div_OO_to(&A.arr, &B.arr, &res.arr, _dhl)

    # end if

    if status == DN_OK:

        status = fearr_set_shape(A.nrows, A.ncols, A.nip, &res)

    # end if

    fearr_free(&tmp_a)
    fearr_free(&tmp_b)
    _fe_ok(op, status, &res)

    return _fe_take(&res, array)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef object _fe_unary(_dnfe value, str name):
    """
    Evaluate an elementary function at every entry and point through the SoA kernels.

    Parameters
    ----------
    value : _dnfe
        Argument.
    name : str
        Function name understood by math.pxi's _unary ("sin", "exp", ...).

    Returns
    -------
    otife or omatfe
        Result of the same kind and shape.
    """

    return _fe_adopt(value, _unary(_fe_view(value), name))

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef object _fe_adopt(_dnfe like, omat out):
    """
    Wrap an omat computed on a Gauss value's embedded array as a Gauss value of the same kind.

    Parameters
    ----------
    like : _dnfe
        Gauss value whose shape and kind the result takes.
    out : omat
        Owned result of an SoA operation on like's embedded nip x (nrows * ncols) array; its buffers
        move into the new object.

    Returns
    -------
    otife or omatfe
        Gauss-point result.
    """

    cdef feoarr_t res = fearr_init()

    if not out.FLAGS & 1:

        raise ValueError("internal error: a view cannot be adopted")

    # end if

    res.arr = out.arr
    out.arr = oarr_init()

    return _fe_shaped(&res, like, _fe_is_array(like))

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef object _fe_store(object result, object out):
    """
    Move a result into a caller-provided output object (the out= argument of module functions).

    Parameters
    ----------
    result : object
        Freshly created result (otife, omatfe, otinum or omat).
    out : object
        None, or an object of a compatible type that receives the result.

    Returns
    -------
    object
        out when given, otherwise result.
    """

    cdef _dnfe gres, gout
    cdef omat ares, aout
    cdef otinum sres, sout

    if out is None:

        return result

    # end if

    if isinstance(result, _dnfe) and isinstance(out, _dnfe):

        # An otife holder cannot take a matrix (nor an omatfe a scalar kind): the object would be
        # corrupt. An omatfe holder takes an omatfe result whatever its previous shape.
        if type(out) is not type(result):

            raise TypeError("out= has type {} but the result is {}".format(
                type(out).__name__, type(result).__name__))

        # end if

        gres = result
        gout = out
        fearr_free(&gout.fe)
        gout.fe = gres.fe
        gres.fe = fearr_init()

    elif isinstance(result, omat) and isinstance(out, omat):

        # Like semi-sparse, the holder takes the result whatever its previous shape.
        ares = result
        aout = out

        if not aout.FLAGS & 1:

            raise ValueError("out is a view of another object and cannot receive a result")

        # end if

        # Freeing the holder's buffer would leave its live block views dangling.
        _check_no_block_views(aout)
        oarr_free(&aout.arr)
        aout.arr = ares.arr
        ares.arr = oarr_init()

    elif isinstance(result, otinum) and isinstance(out, otinum):

        sres = result
        sout = out

        if not sout.FLAGS & 1:

            raise ValueError("out is a view of another object and cannot receive a result")

        # end if

        oti_free(&sout.num)
        sout.num = sres.num
        sres.num = oti_init()

    elif isinstance(result, (otinum, omat, arro)) and isinstance(out, (otinum, omat, arro)):

        _assign_out(out, result)

    else:

        raise TypeError("out= has type {} but the result is {}".format(
            type(out).__name__, type(result).__name__))

    # end if

    return out

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef object _fe_block(_dnfe value, object direction):
    """
    Copy one direction block of the embedded array into a NumPy array shaped like the object.

    Parameters
    ----------
    value : _dnfe
        Gauss-point object.
    direction : object
        Direction in any pyoti.sparse format, or a rawdir; 0 or [] selects the real part.

    Returns
    -------
    numpy.ndarray
        Shape (nip,) for an otife, (nip, nrows, ncols) for an omatfe; zeros when a base of the
        direction is above nact or its order is above the truncation order.
    """

    cdef tuple pair = _direction(direction)
    cdef coeff_t *block = oarr_get_block(pair[0], pair[1], &value.fe.arr)
    cdef np.npy_intp dims[1]
    cdef np.ndarray flat
    cdef object shape

    if _fe_is_array(value):

        shape = (value.fe.nip, value.fe.nrows, value.fe.ncols)

    else:

        shape = (value.fe.nip,)

    # end if

    if block == NULL or value.fe.arr.size == 0:

        return np.zeros(shape)

    # end if

    dims[0] = value.fe.arr.size
    flat = np.PyArray_SimpleNewFromData(1, dims, np.NPY_DOUBLE, <void *>block)

    return flat.reshape(shape, order="F").copy()

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef class _dnfe:
    """
    Common storage and operations of the dense Gauss-point types.

    The coefficients live in one feoarr_t: an nip x (nrows * ncols) SoA array whose entry
    (ip, i + j * nrows) is entry (i, j) of the matrix at integration point ip. Every point shares
    one nact (the value is dense over bases 1..nact) and one truncation order.
    """

    # ****************************************************************************************************
    def __cinit__(self):
        """
        Initialize an empty native value.
        """

        self.fe = fearr_init()

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def __dealloc__(self):
        """
        Release the native buffers.
        """

        fearr_free(&self.fe)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    @property
    def nip(self):
        """
        Number of integration points.

        Returns
        -------
        int
            Number of points.
        """

        return self.fe.nip

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    @property
    def order(self):
        """
        Truncation order.

        Returns
        -------
        int
            Truncation order.
        """

        return self.fe.arr.trc_order

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    @property
    def actual_order(self):
        """
        Highest order that may hold nonzero coefficients.

        Returns
        -------
        int
            Active order.
        """

        return self.fe.arr.act_order

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    @property
    def nbases(self):
        """
        Number of active bases shared by every point (the value is dense over bases 1..nact).

        Returns
        -------
        int
            nact.
        """

        return self.fe.arr.nact

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    @property
    def nact(self):
        """
        Number of active bases: the value is dense over bases 1..nact.

        Returns
        -------
        int
            nact.
        """

        return self.fe.arr.nact

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    @property
    def active_bases(self):
        """
        Active global bases, [1, ..., nact].

        Returns
        -------
        list of int
            Active bases.
        """

        return list(range(1, self.fe.arr.nact + 1))

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def get_active_bases(self):
        """
        Return the active global bases, [1, ..., nact].

        Returns
        -------
        list of int
            Active bases.
        """

        return list(range(1, self.fe.arr.nact + 1))

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def copy(self):
        """
        Return an independent copy.

        Returns
        -------
        otife or omatfe
            Copy of the same kind.
        """

        cdef feoarr_t res = fearr_init()

        _fe_ok("copy", fearr_copy_to(&self.fe, &res), &res)

        return _fe_take(&res, _fe_is_array(self))

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    @property
    def real(self):
        """
        Real part at every point.

        Returns
        -------
        numpy.ndarray
            Shape (nip,) for a scalar, (nip, nrows, ncols) for an array.
        """

        return _fe_block(self, 0)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    @property
    def real_numpy(self):
        """
        Real part at every point (same as real).

        Returns
        -------
        numpy.ndarray
            Shape (nip,) for a scalar, (nip, nrows, ncols) for an array.
        """

        return _fe_block(self, 0)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def get_im(self, humdir):
        """
        Imaginary coefficient along a direction at every point.

        Parameters
        ----------
        humdir : int or list or tuple
            Direction in any pyoti.sparse format, or a rawdir.

        Returns
        -------
        numpy.ndarray
            Shape (nip,) for a scalar, (nip, nrows, ncols) for an array.
        """

        return _fe_block(self, humdir)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def get_deriv(self, humdir):
        """
        Derivative along a direction at every point.

        Parameters
        ----------
        humdir : int or list or tuple
            Direction in any pyoti.sparse format, or a rawdir.

        Returns
        -------
        numpy.ndarray
            Shape (nip,) for a scalar, (nip, nrows, ncols) for an array.
        """

        cdef tuple pair = _direction(humdir)

        return _fe_block(self, humdir) * _deriv_factor(pair[0], pair[1])

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def get_order_im(self, order):
        """
        Keep only the coefficients of one order.

        Parameters
        ----------
        order : int
            Order to keep.

        Returns
        -------
        otife or omatfe
            Result of the same kind.
        """

        cdef feoarr_t res = fearr_init()

        _check_order(order)
        _fe_ok("get_order_im", oarr_get_order_im_to(order, &self.fe.arr, &res.arr), &res)

        return _fe_shaped(&res, self, _fe_is_array(self))

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def truncate(self, humdir):
        """
        Zero a direction and every higher direction containing it, at every point.

        Parameters
        ----------
        humdir : int or list or tuple
            Direction in any pyoti.sparse format, or a rawdir.

        Returns
        -------
        otife or omatfe
            Truncated copy.
        """

        cdef tuple pair = _direction(humdir)
        cdef feoarr_t res = fearr_init()

        _fe_ok("truncate", oarr_truncate_im_to(pair[0], pair[1], &self.fe.arr, &res.arr), &res)

        return _fe_shaped(&res, self, _fe_is_array(self))

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def truncate_order(self, order):
        """
        Remove the coefficients of this order and above, at every point.

        Parameters
        ----------
        order : int
            First order to remove.

        Returns
        -------
        otife or omatfe
            Truncated copy.
        """

        cdef feoarr_t res = fearr_init()

        _check_order(order)
        _fe_ok("truncate_order", oarr_truncate_order_to(order, &self.fe.arr, &res.arr), &res)

        return _fe_shaped(&res, self, _fe_is_array(self))

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def compact(self):
        """
        Trim trailing all-zero bases (shared by every point); the value is unchanged.

        Returns
        -------
        otife or omatfe
            Compacted copy.
        """

        cdef feoarr_t res = fearr_init()

        _fe_ok("compact", oarr_compact_to(&self.fe.arr, &res.arr), &res)

        return _fe_shaped(&res, self, _fe_is_array(self))

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def set(self, rhs):
        """
        Overwrite every entry at every point.

        Parameters
        ----------
        rhs : float or otinum or sotinum or otife or omat or matso or omatfe
            New value. Scalars (plain or Gauss) fill every entry; a plain matrix is repeated at every
            point; a Gauss array must have the same shape. nact and the order become the larger of
            self's and the value's.
        """

        cdef feoarr_t res = fearr_init()
        cdef feoarr_t zero = fearr_init()
        cdef _dnfe g
        cdef omat plain
        cdef otinum o
        cdef uint64_t e
        cdef int status

        rhs = _fe_plain(rhs)

        if isinstance(rhs, _dnfe):

            g = rhs

            if g.fe.nip != self.fe.nip:

                raise ValueError("Gauss-point operands have different numbers of integration points")

            # end if

            if g.fe.nrows == self.fe.nrows and g.fe.ncols == self.fe.ncols:

                _fe_ok("set", fearr_copy_to(&g.fe, &res), &res)

            elif g.fe.nrows == 1 and g.fe.ncols == 1:

                _fe_ok("set", fearr_bcast_to(&g.fe, self.fe.nrows, self.fe.ncols, &res), &res)

            else:

                raise ValueError("shape mismatch in set()")

            # end if

        elif isinstance(rhs, omat):

            plain = rhs

            if plain.arr.nrows != self.fe.nrows or plain.arr.ncols != self.fe.ncols:

                raise ValueError("shape mismatch in set()")

            # end if

            _fe_ok("set", fearr_from_oarr_to(&plain.arr, self.fe.nip, &res), &res)

        elif isinstance(rhs, (otinum, Real)):

            _fe_ok("set", fearr_zeros_to(self.fe.arr.nact, self.fe.nrows, self.fe.ncols,
                                         self.fe.nip, self.fe.arr.trc_order, &zero), &zero)

            if isinstance(rhs, otinum):

                o = rhs
                status = oarr_sum_oO_to(&o.num, &zero.arr, &res.arr, _dhl)

                if status == DN_OK:

                    status = fearr_set_shape(self.fe.nrows, self.fe.ncols, self.fe.nip, &res)

                # end if

                fearr_free(&zero)
                _fe_ok("set", status, &res)

            else:

                for e in range(zero.arr.size):

                    zero.arr.p_data[e] = rhs

                # end for

                res = zero

            # end if

        else:

            raise TypeError("unsupported value type {}".format(type(rhs).__name__))

        # end if

        # Like pyoti.sparse, the value never lowers self's nact or truncation order.
        _fe_ok("set", fearr_grow(self.fe.arr.nact, self.fe.arr.trc_order, &res), &res)
        fearr_free(&self.fe)
        self.fe = res

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def gauss_integrate(self, w):
        """
        Integrate with the Gauss rule: sum over points of w_ip times the value at ip.

        Parameters
        ----------
        w : otife
            Weights (possibly OTI, e.g. w * detJ) at the same points.

        Returns
        -------
        otinum or omat
            Integral (a scalar for an otife, a matrix for an omatfe).
        """

        return gauss_integrate(self, w)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def extract_im(self, humdir):
        """
        Collect, at every entry and point, the coefficients that are multiples of a direction.

        Parameters
        ----------
        humdir : int or list or tuple
            Direction in any pyoti.sparse format, or a rawdir.

        Returns
        -------
        otife or omatfe
            Same semantics as the scalar extract_im, per entry and point.
        """

        cdef tuple pair = _direction(humdir)
        cdef feoarr_t res = fearr_init()

        _fe_ok("extract_im", oarr_extract_im_to(pair[0], pair[1], &self.fe.arr, &res.arr), &res)

        return _fe_shaped(&res, self, _fe_is_array(self))

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def extract_deriv(self, humdir):
        """
        Collect, at every entry and point, the multiples of a direction as derivatives.

        Parameters
        ----------
        humdir : int or list or tuple
            Direction in any pyoti.sparse format, or a rawdir.

        Returns
        -------
        otife or omatfe
            Same semantics as the scalar extract_deriv, per entry and point.
        """

        cdef tuple pair = _direction(humdir)
        cdef feoarr_t res = fearr_init()

        _fe_ok("extract_deriv",
               oarr_extract_deriv_to(pair[0], pair[1], &self.fe.arr, &res.arr), &res)

        return _fe_shaped(&res, self, _fe_is_array(self))

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def short_repr(self):
        """
        Short representation: the number of points and the real part.

        Returns
        -------
        str
            Representation.
        """

        return "{}< nip: {}, re:\n{}>".format(type(self).__name__, self.fe.nip, repr(self.real))

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def long_repr(self):
        """
        Long representation: shape, number of points, active bases, order and real part.

        Returns
        -------
        str
            Representation.
        """

        return "{}< shape: {}, nip: {}, bases: {}, order: {}, re:\n{}>".format(
            type(self).__name__, (self.fe.nrows, self.fe.ncols), self.fe.nip,
            self.get_active_bases(), self.fe.arr.trc_order, repr(self.real))

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def list_repr(self):
        """
        One line per integration point with the value at that point.

        Returns
        -------
        str
            Representation.
        """

        cdef uint64_t ip
        cdef str out = "{}< nip: {}, \n".format(type(self).__name__, self.fe.nip)

        for ip in range(self.fe.nip):

            out += "({0:d}) {1}\n".format(ip, str(self.get_ip(ip)))

        # end for

        return out + ">"

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def __neg__(self):
        """
        Negate every entry at every point.

        Returns
        -------
        otife or omatfe
            Negated copy.
        """

        cdef feoarr_t res = fearr_init()

        _fe_ok("neg", oarr_neg_to(&self.fe.arr, &res.arr, _dhl), &res)

        return _fe_shaped(&res, self, _fe_is_array(self))

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def __pos__(self):
        """
        Return a copy.

        Returns
        -------
        otife or omatfe
            Copy.
        """

        return self.copy()

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def __abs__(self):
        """
        Absolute value at every entry and point (entries with a negative real part are negated).

        Returns
        -------
        otife or omatfe
            Absolute value.
        """

        return _fe_adopt(self, _builtins.abs(_fe_view(self)))

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def __add__(self, other):
        """
        Add elementwise.

        Parameters
        ----------
        other : object
            Real, OTI scalar or matrix, or Gauss value.

        Returns
        -------
        otife or omatfe
            Sum.
        """

        return _fe_binary(self, other, "add", False)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def __radd__(self, other):
        """
        Add elementwise (reflected).

        Parameters
        ----------
        other : object
            Real, OTI scalar or matrix.

        Returns
        -------
        otife or omatfe
            Sum.
        """

        return _fe_binary(self, other, "add", True)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def __sub__(self, other):
        """
        Subtract elementwise.

        Parameters
        ----------
        other : object
            Real, OTI scalar or matrix, or Gauss value.

        Returns
        -------
        otife or omatfe
            Difference.
        """

        return _fe_binary(self, other, "sub", False)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def __rsub__(self, other):
        """
        Subtract elementwise (reflected: other - self).

        Parameters
        ----------
        other : object
            Real, OTI scalar or matrix.

        Returns
        -------
        otife or omatfe
            Difference.
        """

        return _fe_binary(self, other, "sub", True)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def __mul__(self, other):
        """
        Multiply elementwise (Gauss scalars broadcast over Gauss arrays point by point).

        Parameters
        ----------
        other : object
            Real, OTI scalar or matrix, or Gauss value.

        Returns
        -------
        otife or omatfe
            Product.
        """

        return _fe_binary(self, other, "mul", False)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def __rmul__(self, other):
        """
        Multiply elementwise (reflected).

        Parameters
        ----------
        other : object
            Real, OTI scalar or matrix.

        Returns
        -------
        otife or omatfe
            Product.
        """

        return _fe_binary(self, other, "mul", True)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def __truediv__(self, other):
        """
        Divide elementwise.

        Parameters
        ----------
        other : object
            Real, OTI scalar or matrix, or Gauss value.

        Returns
        -------
        otife or omatfe
            Quotient.
        """

        return _fe_binary(self, other, "div", False)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def __rtruediv__(self, other):
        """
        Divide elementwise (reflected: other / self).

        Parameters
        ----------
        other : object
            Real, OTI scalar or matrix.

        Returns
        -------
        otife or omatfe
            Quotient.
        """

        return _fe_binary(self, other, "div", True)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def __iadd__(self, other):
        """
        Add and rebind, like pyoti.sparse: ``a += b`` is ``a = a + b``, so aliases of
        the old object are unchanged.

        Parameters
        ----------
        other : object
            Real, OTI scalar or matrix, or Gauss value.

        Returns
        -------
        otife or omatfe
            New object holding the result.
        """

        return _fe_binary(self, other, "add", False)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def __isub__(self, other):
        """
        Subtract and rebind, like pyoti.sparse: ``a -= b`` is ``a = a - b``, so aliases of
        the old object are unchanged.

        Parameters
        ----------
        other : object
            Real, OTI scalar or matrix, or Gauss value.

        Returns
        -------
        otife or omatfe
            New object holding the result.
        """

        return _fe_binary(self, other, "sub", False)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def __imul__(self, other):
        """
        Multiply and rebind, like pyoti.sparse: ``a *= b`` is ``a = a * b``, so aliases of
        the old object are unchanged.

        Parameters
        ----------
        other : object
            Real, OTI scalar or matrix, or Gauss value.

        Returns
        -------
        otife or omatfe
            New object holding the result.
        """

        return _fe_binary(self, other, "mul", False)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def __itruediv__(self, other):
        """
        Divide and rebind, like pyoti.sparse: ``a /= b`` is ``a = a / b``, so aliases of
        the old object are unchanged.

        Parameters
        ----------
        other : object
            Real, OTI scalar or matrix, or Gauss value.

        Returns
        -------
        otife or omatfe
            New object holding the result.
        """

        return _fe_binary(self, other, "div", False)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def __pow__(self, exponent, modulo):
        """
        Raise every entry at every point to a real power.

        Parameters
        ----------
        exponent : float
            Real exponent.
        modulo : None
            Unsupported; must be None.

        Returns
        -------
        otife or omatfe
            Power.
        """

        cdef feoarr_t res = fearr_init()

        if modulo is not None or not isinstance(exponent, Real):

            return NotImplemented

        # end if

        _fe_ok("pow", oarr_pow_to(&self.fe.arr, exponent, &res.arr, _dhl), &res)

        return _fe_shaped(&res, self, _fe_is_array(self))

    # end function
    # ----------------------------------------------------------------------------------------------------

# end class
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef class otife(_dnfe):
    """
    Dense OTI scalar at nip integration points (counterpart of pyoti.sparse.sotife).
    """

    # ****************************************************************************************************
    def __init__(self, real=0.0, nip=1, order=0, nbases=0, bases=()):
        """
        Create a Gauss-point scalar holding the same value at every point.

        Same leading arguments as pyoti.sparse.sotife(real, nip, order, nbases).

        Parameters
        ----------
        real : float or otinum or sotinum
            Value at every point.
        nip : int
            Number of integration points.
        order : int
            Minimum truncation order.
        nbases : int
            Accepted for pyoti.sparse compatibility (a capacity hint there); unused.
        bases : iterable of int
            Labels whose largest sets the minimum nact (the value's own nact always applies).
        """

        cdef otife res = _fe_scalar(real, bases, order, nip)

        fearr_free(&self.fe)
        self.fe = res.fe
        res.fe = fearr_init()

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    @classmethod
    def from_sparse(cls, value):
        """
        Convert a pyoti.sparse Gauss-point scalar.

        Parameters
        ----------
        value : pyoti.sparse.sotife
            Sparse Gauss-point scalar.

        Returns
        -------
        otife
            Dense copy.
        """

        cdef otife res = _fe_scalar(0.0, (), 0, value.nip)
        cdef uint64_t ip

        for ip in range(value.nip):

            res[ip] = otinum(value[ip])

        # end for

        return res

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def to_sparse(self):
        """
        Convert to a pyoti.sparse Gauss-point scalar.

        Returns
        -------
        pyoti.sparse.sotife
            Sparse copy.
        """

        import pyoti.sparse as _sparse

        cdef uint64_t ip
        res = _sparse.zero(nip=self.fe.nip)

        for ip in range(self.fe.nip):

            res[ip] = self[ip].to_sparse()

        # end for

        return res

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    @property
    def shape(self):
        """
        Shape of the value at each point, (1, 1).

        Returns
        -------
        tuple
            (1, 1).
        """

        return (1, 1)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def __getitem__(self, ip):
        """
        Return the value at one integration point.

        Parameters
        ----------
        ip : int
            Integration point (negative values count from the end).

        Returns
        -------
        otinum
            Independent copy of the value at ip.
        """

        return self.get_ip(ip)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def get_ip(self, ip):
        """
        Return the value at one integration point.

        Parameters
        ----------
        ip : int
            Integration point (negative values count from the end).

        Returns
        -------
        otinum
            Independent copy of the value at ip.
        """

        cdef int64_t k = _fe_point(ip, self.fe.nip)
        cdef oarr_t one = oarr_init()
        cdef otinum_t num = oti_init()
        cdef int status = fearr_get_ip_to(k, &self.fe, &one)

        if status == DN_OK:

            status = oarr_get_item_to(0, 0, &one, &num)

        # end if

        oarr_free(&one)

        if status != DN_OK:

            oti_free(&num)
            _status("get_ip", status)

        # end if

        return otinum.wrap(num)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def __setitem__(self, ip, value):
        """
        Overwrite the value at one integration point.

        Parameters
        ----------
        ip : int
            Integration point (negative values count from the end).
        value : float or otinum or sotinum
            New value (nact and the order of the whole Gauss scalar grow to the value's).
        """

        cdef int64_t k = _fe_point(ip, self.fe.nip)
        cdef otinum o

        value = _fe_plain(value)

        if isinstance(value, otinum):

            o = value
            _status("setitem", fearr_set_ijk_o(&o.num, 0, 0, k, &self.fe))

        elif isinstance(value, Real):

            _status("setitem", fearr_set_ijk_r(value, 0, 0, k, &self.fe))

        else:

            raise TypeError("expected a real or OTI scalar")

        # end if

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def __repr__(self):
        """
        Describe the scalar and its real part at every point.

        Returns
        -------
        str
            Representation.
        """

        return "otife(nip={}, nact={}, order={}, real={})".format(
            self.fe.nip, self.fe.arr.nact, self.fe.arr.trc_order, self.real.tolist())

    # end function
    # ----------------------------------------------------------------------------------------------------

# end class
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef int64_t _fe_point(object ip, uint64_t nip) except -1:
    """
    Normalize and check an integration-point index.

    Parameters
    ----------
    ip : int
        Index (negative values count from the end).
    nip : int
        Number of integration points.

    Returns
    -------
    int
        Index in [0, nip).
    """

    cdef object index = _operator.index(ip)

    # Python integers first: a huge index is an IndexError, not an OverflowError.
    if index < 0:

        index += nip

    # end if

    if index < 0 or index >= nip:

        raise IndexError("integration point {} out of range for nip={}".format(ip, nip))

    # end if

    return <int64_t>index

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef tuple _fe_axis(object key, uint64_t n):
    """
    Parse one axis of a Gauss-array index.

    Parameters
    ----------
    key : int or slice
        Index along the axis.
    n : int
        Axis length.

    Returns
    -------
    tuple
        (start, count, step, is_integer).
    """

    cdef object k
    cdef object count

    if isinstance(key, slice):

        start, stop, step = key.indices(n)
        count = len(range(start, stop, step))

        # An empty range may start at -1 (a negative step clamped below 0): any start will do.
        return (start if count > 0 else 0, count, step, False)

    # end if

    k = _operator.index(key)

    if k < 0:

        k += n

    # end if

    if k < 0 or k >= n:

        raise IndexError("index {} out of range for size {}".format(key, n))

    # end if

    return (k, 1, 1, True)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef tuple _fe_key(object key, uint64_t nrows, uint64_t ncols):
    """
    Parse a matsofe-style index of a Gauss array.

    Parameters
    ----------
    key : int or slice or tuple
        A row index/slice, or a (row, column) pair of integers and slices.
    nrows : int
        Rows.
    ncols : int
        Columns.

    Returns
    -------
    tuple
        (row axis, column axis, both_integers); each axis as returned by _fe_axis.
    """

    cdef tuple rows, cols

    if isinstance(key, tuple):

        if len(key) != 2:

            raise IndexError("Gauss arrays take one or two indices; use get_ip() for points")

        # end if

        rows = _fe_axis(key[0], nrows)
        cols = _fe_axis(key[1], ncols)

    else:

        rows = _fe_axis(key, nrows)
        cols = _fe_axis(slice(None), ncols)

    # end if

    return (rows, cols, rows[3] and cols[3])

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef class omatfe(_dnfe):
    """
    Dense OTI matrix at nip integration points (counterpart of pyoti.sparse.matsofe).
    """

    # ****************************************************************************************************
    def __init__(self, shape=(1, 1), nip=1, order=0, nbases=0, bases=()):
        """
        Create a zero Gauss-point matrix.

        Same leading arguments as pyoti.sparse.matsofe(shape, nip, order, nbases).

        Parameters
        ----------
        shape : int or tuple of int
            (nrows, ncols) at each point; an int n means (n, 1).
        nip : int
            Number of integration points.
        order : int
            Truncation order.
        nbases : int
            Accepted for pyoti.sparse compatibility (a capacity hint there); unused.
        bases : iterable of int
            Labels whose largest sets nact.
        """

        cdef omatfe res = _fe_zeros(shape, bases, order, nip)

        fearr_free(&self.fe)
        self.fe = res.fe
        res.fe = fearr_init()

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    @classmethod
    def from_sparse(cls, value):
        """
        Convert a pyoti.sparse Gauss-point matrix.

        Parameters
        ----------
        value : pyoti.sparse.matsofe
            Sparse Gauss-point matrix.

        Returns
        -------
        omatfe
            Dense copy.
        """

        cdef omatfe res = _fe_zeros(value.shape, (), 0, value.nip)
        cdef uint64_t ip

        for ip in range(value.nip):

            res.set_ip(ip, value.get_ip(ip))

        # end for

        return res

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    @classmethod
    def from_points(cls, values):
        """
        Stack plain matrices, one per integration point.

        Parameters
        ----------
        values : sequence of omat or matso or arro
            Matrices of equal shape.

        Returns
        -------
        omatfe
            Gauss-point matrix with nip = len(values).
        """

        cdef list mats = [_fe_plain(v) for v in values]
        cdef omatfe res
        cdef uint64_t ip

        if not mats:

            raise ValueError("from_points() needs at least one matrix")

        # end if

        res = _fe_zeros(mats[0].shape, (), 0, len(mats))

        for ip in range(len(mats)):

            res.set_ip(ip, mats[ip])

        # end for

        return res

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def to_sparse(self):
        """
        Convert to a pyoti.sparse Gauss-point matrix.

        Returns
        -------
        pyoti.sparse.matsofe
            Sparse copy.
        """

        import pyoti.sparse as _sparse

        cdef uint64_t ip, i, j
        cdef omat point

        res = _sparse.zeros((self.fe.nrows, self.fe.ncols), nip=self.fe.nip)

        for ip in range(self.fe.nip):

            point = self.get_ip(ip)

            for i in range(self.fe.nrows):

                for j in range(self.fe.ncols):

                    res.set_ijk(point[i, j].to_sparse(), i, j, ip)

                # end for

            # end for

        # end for

        return res

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    @property
    def shape(self):
        """
        Shape of the matrix at each point.

        Returns
        -------
        tuple
            (nrows, ncols).
        """

        return (self.fe.nrows, self.fe.ncols)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    @property
    def nrows(self):
        """
        Rows at each point.

        Returns
        -------
        int
            Rows.
        """

        return self.fe.nrows

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    @property
    def ncols(self):
        """
        Columns at each point.

        Returns
        -------
        int
            Columns.
        """

        return self.fe.ncols

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    @property
    def size(self):
        """
        Entries at each point.

        Returns
        -------
        int
            nrows * ncols.
        """

        return self.fe.nrows * self.fe.ncols

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    @property
    def T(self):
        """
        Transpose at every point.

        Returns
        -------
        omatfe
            Transposed copy.
        """

        return self.transpose()

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def transpose(self):
        """
        Transpose at every point.

        Returns
        -------
        omatfe
            Transposed copy.
        """

        cdef feoarr_t res = fearr_init()

        _fe_ok("transpose", fearr_transpose_to(&self.fe, &res), &res)

        return _fe_take(&res, True)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def get_ip(self, ip):
        """
        Return the matrix at one integration point.

        Parameters
        ----------
        ip : int
            Integration point (negative values count from the end).

        Returns
        -------
        omat
            Independent plain matrix.
        """

        cdef int64_t k = _fe_point(ip, self.fe.nip)
        cdef oarr_t res = oarr_init()

        _soa_ok("get_ip", fearr_get_ip_to(k, &self.fe, &res), &res)

        return omat.wrap(res)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def set_ip(self, ip, value):
        """
        Overwrite the matrix at one integration point.

        Parameters
        ----------
        ip : int
            Integration point (negative values count from the end).
        value : omat or matso or arro
            Plain matrix of the same shape (nact and the order of the whole Gauss matrix grow to
            the value's).
        """

        cdef int64_t k = _fe_point(ip, self.fe.nip)
        cdef omat plain

        value = _fe_plain(value)

        if not isinstance(value, omat):

            raise TypeError("set_ip expects a plain OTI matrix")

        # end if

        plain = value

        if plain.arr.nrows != self.fe.nrows or plain.arr.ncols != self.fe.ncols:

            raise ValueError("shape mismatch in set_ip()")

        # end if

        _status("set_ip", fearr_set_ip(&plain.arr, k, &self.fe))

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def set_ijk(self, rhs, i, j, k):
        """
        Overwrite entry (i, j) at integration point k.

        Parameters
        ----------
        rhs : float or otinum or sotinum
            New value.
        i : int
            Row.
        j : int
            Column.
        k : int
            Integration point.
        """

        cdef otinum o

        rhs = _fe_plain(rhs)
        i = _operator.index(i)
        j = _operator.index(j)
        k = _operator.index(k)

        if i < 0 or j < 0 or k < 0 or i >= self.fe.nrows or j >= self.fe.ncols or k >= self.fe.nip:

            raise IndexError("set_ijk index ({}, {}, {}) out of range for shape {} at nip={}".format(
                i, j, k, (self.fe.nrows, self.fe.ncols), self.fe.nip))

        # end if

        if isinstance(rhs, otinum):

            o = rhs
            _status("set_ijk", fearr_set_ijk_o(&o.num, i, j, k, &self.fe))

        elif isinstance(rhs, Real):

            _status("set_ijk", fearr_set_ijk_r(rhs, i, j, k, &self.fe))

        else:

            raise ValueError("Supported values are real scalars, otinum and sotinum.")

        # end if

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def get_item_ij(self, i, j, out=None):
        """
        Return entry (i, j) at every point.

        Parameters
        ----------
        i : int
            Row.
        j : int
            Column.
        out : otife, optional
            Receives the result.

        Returns
        -------
        otife
            Entry as a Gauss-point scalar.
        """

        return _fe_store(self[i, j], out)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def __getitem__(self, key):
        """
        Index like pyoti.sparse.matsofe: rows, (row, column) pairs and slices, at every point.

        Parameters
        ----------
        key : int or slice or tuple
            Index.

        Returns
        -------
        otife or omatfe
            A Gauss scalar for two integer indices, otherwise a Gauss sub-matrix.
        """

        cdef tuple parsed = _fe_key(key, self.fe.nrows, self.fe.ncols)
        cdef tuple rows = parsed[0]
        cdef tuple cols = parsed[1]
        cdef feoarr_t res = fearr_init()

        _fe_ok("getitem", fearr_get_slice_to(&self.fe, rows[0], rows[1], rows[2], cols[0], cols[1],
                                             cols[2], &res), &res)

        return _fe_take(&res, not parsed[2])

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def __setitem__(self, key, value):
        """
        Assign like pyoti.sparse.matsofe, at every point.

        Parameters
        ----------
        key : int or slice or tuple
            Index.
        value : object
            Real or OTI scalar (fills the block), Gauss scalar (point by point), plain matrix (the
            same at every point) or Gauss matrix of the block's shape. nact and the order of the
            Gauss matrix grow to the value's.
        """

        cdef tuple parsed = _fe_key(key, self.fe.nrows, self.fe.ncols)
        cdef tuple rows = parsed[0]
        cdef tuple cols = parsed[1]
        cdef feoarr_t tmp = fearr_init()
        cdef _dnfe g
        cdef omat plain
        cdef int status

        value = _fe_plain(value)

        if isinstance(value, _dnfe):

            g = value

            if g.fe.nip != self.fe.nip:

                raise ValueError("Gauss-point operands have different numbers of integration points")

            # end if

            if not ((g.fe.nrows == rows[1] and g.fe.ncols == cols[1])
                    or (g.fe.nrows == 1 and g.fe.ncols == 1)):

                raise ValueError("shape mismatch in Gauss-array assignment")

            # end if

            # The C slice assignment must not alias its source: copy a self-assignment first.
            if g is self:

                _fe_ok("setitem", fearr_copy_to(&g.fe, &tmp), &tmp)
                status = fearr_set_slice(&tmp, rows[0], rows[1], rows[2], cols[0], cols[1],
                                         cols[2], &self.fe)
                fearr_free(&tmp)
                _status("setitem", status)

                return

            # end if

            _status("setitem", fearr_set_slice(&g.fe, rows[0], rows[1], rows[2], cols[0], cols[1],
                                               cols[2], &self.fe))

        elif isinstance(value, omat):

            plain = value

            if plain.arr.nrows != rows[1] or plain.arr.ncols != cols[1]:

                raise ValueError("shape mismatch in Gauss-array assignment")

            # end if

            _fe_ok("setitem", fearr_from_oarr_to(&plain.arr, self.fe.nip, &tmp), &tmp)
            status = fearr_set_slice(&tmp, rows[0], rows[1], rows[2], cols[0], cols[1], cols[2],
                                     &self.fe)
            fearr_free(&tmp)
            _status("setitem", status)

        elif isinstance(value, (Real, otinum)):

            g = _fe_scalar(value, (), 0, self.fe.nip)
            _status("setitem", fearr_set_slice(&g.fe, rows[0], rows[1], rows[2], cols[0], cols[1],
                                               cols[2], &self.fe))

        else:

            raise TypeError("unsupported value type {}".format(type(value).__name__))

        # end if

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def dot(self, other):
        """
        Matrix product at every point.

        Parameters
        ----------
        other : omatfe or omat or matso
            Right operand.

        Returns
        -------
        omatfe
            Product.
        """

        return _fe_dot(self, other)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def __matmul__(self, other):
        """
        Matrix product at every point.

        Parameters
        ----------
        other : omatfe or omat or matso
            Right operand.

        Returns
        -------
        omatfe
            Product.
        """

        return _fe_dot(self, other)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def __rmatmul__(self, other):
        """
        Matrix product at every point (reflected: other @ self).

        Parameters
        ----------
        other : omat or matso
            Left operand.

        Returns
        -------
        omatfe
            Product.
        """

        return _fe_dot(other, self)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def inv(self):
        """
        Inverse at every point.

        Returns
        -------
        omatfe
            Inverse.
        """

        return _fe_inv(self)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def det(self):
        """
        Determinant at every point.

        Returns
        -------
        otife
            Determinant.
        """

        return _fe_det(self)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def __repr__(self):
        """
        Describe the matrix and its real part at every point.

        Returns
        -------
        str
            Representation.
        """

        return "omatfe(shape={}, nip={}, nact={}, order={})\nreal =\n{}".format(
            self.shape, self.fe.nip, self.fe.arr.nact, self.fe.arr.trc_order, repr(self.real))

    # end function
    # ----------------------------------------------------------------------------------------------------

# end class
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef int _fe_check_nip(object nip) except -1:
    """
    Validate a number of integration points.

    Parameters
    ----------
    nip : int
        Number of integration points (> 0).
    """

    if not isinstance(nip, (int, np.integer)):

        raise TypeError("nip must be an integer")

    # end if

    if nip < 1:

        raise ValueError("nip must be positive")

    # end if

    return 0

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _fe_zeros(shape, bases, order, nip):
    """
    Create an omatfe of zeros at nip integration points.

    Parameters
    ----------
    shape : int or tuple of int
        (nrows, ncols) at each point; an int n means (n, 1).
    bases : iterable of int
        Labels whose largest sets nact (may be empty).
    order : int
        Truncation order.
    nip : int
        Number of integration points (> 0).

    Returns
    -------
    omatfe
        New Gauss-point array.
    """

    cdef bases_t nact = _nact_of(bases)
    cdef feoarr_t res = fearr_init()

    if isinstance(shape, (int, np.integer)):

        shape = (shape, 1)

    # end if

    shape = tuple(shape)

    if len(shape) != 2 or any(not isinstance(x, (int, np.integer)) or x < 0 for x in shape):

        raise ValueError("shape must be (nonnegative rows, nonnegative columns)")

    # end if

    _check_order(order)
    _fe_check_nip(nip)
    _fe_ok("zeros", fearr_zeros_to(nact, shape[0], shape[1], nip, order, &res), &res)

    return _fe_take(&res, True)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _fe_scalar(value, bases, order, nip):
    """
    Create an otife holding the same value at nip integration points.

    Parameters
    ----------
    value : float or otinum or sotinum
        Value at every point.
    bases : iterable of int
        Labels whose largest sets the minimum nact (may be empty).
    order : int
        Minimum truncation order.
    nip : int
        Number of integration points (> 0).

    Returns
    -------
    otife
        New Gauss-point scalar.
    """

    cdef bases_t nact = _nact_of(bases)
    cdef feoarr_t zero = fearr_init()
    cdef feoarr_t res = fearr_init()
    cdef otinum o
    cdef uint64_t ip
    cdef int status

    _check_order(order)
    _fe_check_nip(nip)
    value = _fe_plain(value)

    if not isinstance(value, (otinum, Real)):

        raise TypeError("expected a real or OTI scalar")

    # end if

    _fe_ok("zero", fearr_zeros_to(nact, 1, 1, nip, order, &zero), &zero)

    if isinstance(value, otinum):

        # zero + value at every point: nact and the order are the larger of both.
        o = value
        status = oarr_sum_oO_to(&o.num, &zero.arr, &res.arr, _dhl)

        if status == DN_OK:

            status = fearr_set_shape(1, 1, nip, &res)

        # end if

        fearr_free(&zero)
        _fe_ok("zero", status, &res)

    else:

        for ip in range(nip):

            zero.arr.p_data[ip] = value

        # end for

        res = zero

    # end if

    return _fe_take(&res, False)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def gauss_integrate(val, w, out=None):
    """
    Integrate with the Gauss rule: the sum over points of w_ip times val at ip.

    Parameters
    ----------
    val : otife or omatfe or float or otinum or sotinum
        Integrand at the points; a constant (real or OTI scalar) is the same at every point.
    w : otife
        Weights at the same points (possibly OTI, e.g. w * detJ).
    out : otinum or omat, optional
        Receives the result.

    Returns
    -------
    otinum or omat
        Integral: a scalar for an otife or constant integrand (``val * sum(w)``, as pyoti.sparse
        does), a matrix for an omatfe.
    """

    cdef _dnfe v, g
    cdef oarr_t res = oarr_init()
    cdef otinum_t num = oti_init()
    cdef int status

    if isinstance(w, otife) and isinstance(val, (Real, otinum, sotinum)):

        # A constant integrand: val times the sum of the weights.
        return _fe_store(_fe_plain(val) * gauss_integrate(_fe_scalar(1.0, (), 0, (<otife>w).fe.nip), w),
                         out)

    # end if

    if not isinstance(val, _dnfe) or not isinstance(w, otife):

        raise TypeError("gauss_integrate expects a Gauss-point value and otife weights")

    # end if

    v = val
    g = w
    _soa_ok("gauss_integrate", fearr_integrate_to(&v.fe, &g.fe, &res, _dhl), &res)

    if _fe_is_array(v):

        return _fe_store(omat.wrap(res), out)

    # end if

    status = oarr_get_item_to(0, 0, &res, &num)
    oarr_free(&res)

    if status != DN_OK:

        oti_free(&num)
        _status("gauss_integrate", status)

    # end if

    return _fe_store(otinum.wrap(num), out)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _fe_dot(left, right, out=None):
    """
    Matrix product at every point with at least one Gauss-point operand.

    Parameters
    ----------
    left : omatfe or omat or matso or arro
        Left operand.
    right : omatfe or omat or matso or arro
        Right operand.
    out : omatfe, optional
        Receives the result.

    Returns
    -------
    omatfe
        Product.
    """

    cdef _dnfe a, b
    cdef omat p
    cdef feoarr_t res = fearr_init()
    cdef int status

    left  = _fe_plain(left)
    right = _fe_plain(right)

    if isinstance(left, _dnfe) and isinstance(right, _dnfe):

        a = left
        b = right

        if a.fe.nip != b.fe.nip:

            raise ValueError("Gauss-point operands have different numbers of integration points")

        # end if

        status = fearr_matmul_FF_to(&a.fe, &b.fe, &res, _dhl)

    elif isinstance(left, _dnfe) and isinstance(right, omat):

        a = left
        p = right
        status = fearr_matmul_FO_to(&a.fe, &p.arr, &res, _dhl)

    elif isinstance(left, omat) and isinstance(right, _dnfe):

        p = left
        b = right
        status = fearr_matmul_OF_to(&p.arr, &b.fe, &res, _dhl)

    else:

        raise TypeError("dot expects a Gauss-point matrix and an OTI matrix")

    # end if

    _fe_ok("dot", status, &res)

    return _fe_store(_fe_take(&res, True), out)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _fe_dot_product(left, right, out=None):
    """
    Sum of elementwise products at every point, with at least one Gauss-point operand.

    Parameters
    ----------
    left : object
        Gauss-point value or plain OTI matrix with the same number of entries as right.
    right : object
        Gauss-point value or plain OTI matrix.
    out : otife, optional
        Receives the result.

    Returns
    -------
    otife
        Dot product at every point.
    """

    cdef _dnfe a, b
    cdef omat p
    cdef feoarr_t res = fearr_init()
    cdef int status

    left  = _fe_plain(left)
    right = _fe_plain(right)

    if not (isinstance(left, (_dnfe, omat)) and isinstance(right, (_dnfe, omat))
            and (isinstance(left, _dnfe) or isinstance(right, _dnfe))):

        raise TypeError("dot_product expects a Gauss-point value and an OTI matrix")

    # end if

    # Entries pair row-major, as in pyoti.sparse. The kernels pair column-major, which is the same
    # for equal shapes and for vectors; otherwise pair the transposes (a vector's transpose has the
    # same entry order, so vectors are never transposed).
    if left.shape != right.shape:

        if left.shape[0] > 1 and left.shape[1] > 1:

            left = left.T

        # end if

        if right.shape[0] > 1 and right.shape[1] > 1:

            right = right.T

        # end if

    # end if

    if isinstance(left, _dnfe) and isinstance(right, _dnfe):

        a = left
        b = right

        if a.fe.nip != b.fe.nip:

            raise ValueError("Gauss-point operands have different numbers of integration points")

        # end if

        status = fearr_dot_product_FF_to(&a.fe, &b.fe, &res, _dhl)

    elif isinstance(left, _dnfe) and isinstance(right, omat):

        a = left
        p = right
        status = fearr_dot_product_FO_to(&a.fe, &p.arr, &res, _dhl)

    elif isinstance(left, omat) and isinstance(right, _dnfe):

        p = left
        b = right
        status = fearr_dot_product_FO_to(&b.fe, &p.arr, &res, _dhl)

    else:

        raise TypeError("dot_product expects a Gauss-point value and an OTI matrix")

    # end if

    _fe_ok("dot_product", status, &res)

    return _fe_store(_fe_take(&res, False), out)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _fe_det(value, out=None):
    """
    Determinant at every point.

    Parameters
    ----------
    value : omatfe
        Square Gauss-point matrix.
    out : otife, optional
        Receives the result.

    Returns
    -------
    otife
        Determinant.
    """

    cdef _dnfe a = value
    cdef feoarr_t res = fearr_init()

    _fe_ok("det", fearr_det_to(&a.fe, &res, _dhl), &res)

    return _fe_store(_fe_take(&res, False), out)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _fe_inv(value, out=None):
    """
    Inverse at every point.

    Parameters
    ----------
    value : omatfe or otife
        Square Gauss-point matrix (an otife is the 1 x 1 case).
    out : omatfe or otife, optional
        Receives the result (the operand's kind).

    Returns
    -------
    omatfe or otife
        Inverse, of the operand's kind.
    """

    cdef _dnfe a = value
    cdef feoarr_t res = fearr_init()

    _fe_ok("inv", fearr_inv_to(&a.fe, &res, _dhl), &res)

    # Same kind as the operand (the inverse of an otife is an otife), as _fe_transpose does.
    return _fe_store(_fe_take(&res, _fe_is_array(a)), out)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _fe_transpose(value, out=None):
    """
    Transpose at every point.

    Parameters
    ----------
    value : omatfe
        Gauss-point matrix.
    out : omatfe, optional
        Receives the result.

    Returns
    -------
    omatfe
        Transpose.
    """

    cdef _dnfe a = value
    cdef feoarr_t res = fearr_init()

    _fe_ok("transpose", fearr_transpose_to(&a.fe, &res), &res)

    return _fe_store(_fe_take(&res, _fe_is_array(a)), out)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _fe_arith(op, left, right, out=None):
    """
    Module-level sum/sub/mul/div with at least one Gauss-point operand.

    Parameters
    ----------
    op : str
        One of "add", "sub", "mul", "div".
    left : object
        Left operand.
    right : object
        Right operand.
    out : object, optional
        Receives the result.

    Returns
    -------
    otife or omatfe
        Result.
    """

    cdef object res

    if isinstance(left, _dnfe):

        res = _fe_binary(left, right, op, False)

    else:

        res = _fe_binary(right, left, op, True)

    # end if

    if res is NotImplemented:

        raise TypeError("unsupported operand types {} and {}".format(
            type(left).__name__, type(right).__name__))

    # end if

    return _fe_store(res, out)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def fezeros(shape, nip, nbases=0, order=0):
    """
    Create an omatfe of zeros (pyoti.sparse.fezeros counterpart).

    Parameters
    ----------
    shape : int or tuple of int
        (nrows, ncols) at each point; an int or a 1-tuple n means (n, 1).
    nip : int
        Number of integration points.
    nbases : int
        Accepted for pyoti.sparse compatibility (a capacity hint there); unused.
    order : int
        Truncation order.

    Returns
    -------
    omatfe
        Zero Gauss-point matrix.
    """

    if isinstance(shape, tuple) and len(shape) == 1:

        shape = (shape[0], 1)

    # end if

    return _fe_zeros(shape, (), order, nip)

# end function
# --------------------------------------------------------------------------------------------------------
