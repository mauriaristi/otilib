# Phase 4: Gauss-point types.
# (PLAN-semisparse-sparse-leveling.md)
#
# Names:
#   ssotife   semi-sparse scalar at nip integration points  (sparse counterpart: sotife)
#   oarrssfe  semi-sparse SoA array at nip integration points (sparse counterpart: matsofe)
# Both hold one C feoarrss_t (include/oti/semisparse/gauss/gauss.h): one active set shared by every
# point; the coefficients are an oarrss_t of shape nip x (nrows * ncols), points fastest, so every
# elementwise operation is one batched SoA kernel.
#
# Hooks used by the creators (zeros/zero/one/e/number with nip > 0), by math.pxi and by the module
# functions (dot, dot_product, det, inv, transpose, sum, sub, mul, div): _fe_zeros, _fe_scalar,
# _fe_unary, _fe_dot, _fe_dot_product, _fe_det, _fe_inv, _fe_transpose, _fe_arith.

from collections import Counter as _Counter
from math import factorial as _factorial


# ********************************************************************************************************
cdef _ssfe _fe_new(bint array):
    """
    Create an empty Gauss-point object of the requested kind.

    Parameters
    ----------
    array : bool
        True for an oarrssfe, False for an ssotife.

    Returns
    -------
    _ssfe
        New object holding an empty feoarrss_t.
    """

    if array:

        return oarrssfe.__new__(oarrssfe)

    # end if

    return ssotife.__new__(ssotife)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef _ssfe _fe_take(feoarrss_t *value, bint array):
    """
    Move a native Gauss array into a new Python object.

    Parameters
    ----------
    value : feoarrss_t *
        Owned native value; reset to an empty array on return.
    array : bool
        True for an oarrssfe, False for an ssotife.

    Returns
    -------
    _ssfe
        Object owning the buffers.
    """

    cdef _ssfe res = _fe_new(array)

    feoarrss_free(&res.fe)
    res.fe = value[0]
    value[0] = feoarrss_init()

    return res

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef void _fe_status(int status, str operation) except *:
    """
    Raise the Python exception matching a native linear-algebra status.

    Parameters
    ----------
    status : int
        Native status (0 is success).
    operation : str
        Operation name for the message.
    """

    if status != 0:

        _status(operation, status)

    # end if

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef oarrss _fe_view(_ssfe value):
    """
    Return a non-owning oarrss view of the embedded nip x (nrows * ncols) array.

    Parameters
    ----------
    value : _ssfe
        Gauss-point object; it must outlive the view and not change while the view is used.

    Returns
    -------
    oarrss
        View (its flag is 0, so it never frees the buffers).
    """

    cdef oarrss view = oarrss.__new__(oarrss)

    view.arr = value.fe.arr
    view.arr.flag = 0

    return view

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef object _fe_plain(object value):
    """
    Convert sparse and AoS values to the semi-sparse scalar / SoA types used by the Gauss kernels.

    Parameters
    ----------
    value : object
        Operand.

    Returns
    -------
    object
        ssotinum for OTI scalars, oarrss for OTI matrices, the value itself otherwise.
    """

    if isinstance(value, sotinum):

        return ssotinum(value)

    elif isinstance(value, matso):

        return oarrss.from_sparse(value)

    elif isinstance(value, arrss):

        return value.to_soa()

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
        True for an oarrssfe.
    """

    return isinstance(value, oarrssfe)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef object _fe_binary(_ssfe left, object other, str op, bint reverse):
    """
    Evaluate a binary elementwise operation with a Gauss-point operand on the left.

    Gauss scalars broadcast over Gauss arrays point by point; plain OTI scalars and reals apply to
    every entry at every point; a plain OTI matrix is the same matrix at every point.

    Parameters
    ----------
    left : _ssfe
        Gauss-point operand.
    other : object
        Other operand: real, ssotinum/sotinum, oarrss/matso/arrss, ssotife or oarrssfe.
    op : str
        One of "add", "sub", "mul", "div".
    reverse : bool
        True when the Gauss operand is the right-hand one (other op left).

    Returns
    -------
    ssotife or oarrssfe
        Result, or NotImplemented for unsupported operands.
    """

    cdef feoarrss_t res = feoarrss_init()
    cdef feoarrss_t tmp_a = feoarrss_init()
    cdef feoarrss_t tmp_b = feoarrss_init()
    cdef feoarrss_t *A = &left.fe
    cdef feoarrss_t *B = NULL
    cdef feoarrss_t *X
    cdef coeff_t r
    cdef ssotinum o
    cdef oarrss plain
    cdef _ssfe g
    cdef bint array = _fe_is_array(left)

    other = _fe_plain(other)

    if isinstance(other, Real):

        r = other

        if op == "add":

            oarrss_sum_rO_to(r, &A.arr, &res.arr, _dhl)

        elif op == "sub":

            if reverse:

                oarrss_sub_rO_to(r, &A.arr, &res.arr, _dhl)

            else:

                oarrss_sub_Or_to(&A.arr, r, &res.arr, _dhl)

            # end if

        elif op == "mul":

            oarrss_mul_rO_to(r, &A.arr, &res.arr, _dhl)

        else:

            if reverse:

                oarrss_div_rO_to(r, &A.arr, &res.arr, _dhl)

            else:

                oarrss_div_Or_to(&A.arr, r, &res.arr, _dhl)

            # end if

        # end if

        feoarrss_set_shape(A.nrows, A.ncols, A.nip, &res)

        return _fe_take(&res, array)

    elif isinstance(other, ssotinum):

        o = other

        if op == "add":

            oarrss_sum_oO_to(&o.num, &A.arr, &res.arr, _dhl)

        elif op == "sub":

            if reverse:

                oarrss_sub_oO_to(&o.num, &A.arr, &res.arr, _dhl)

            else:

                oarrss_sub_Oo_to(&A.arr, &o.num, &res.arr, _dhl)

            # end if

        elif op == "mul":

            oarrss_mul_oO_to(&o.num, &A.arr, &res.arr, _dhl)

        else:

            if reverse:

                oarrss_div_oO_to(&o.num, &A.arr, &res.arr, _dhl)

            else:

                oarrss_div_Oo_to(&A.arr, &o.num, &res.arr, _dhl)

            # end if

        # end if

        feoarrss_set_shape(A.nrows, A.ncols, A.nip, &res)

        return _fe_take(&res, array)

    elif isinstance(other, _ssfe):

        g = other
        B = &g.fe
        array = array or _fe_is_array(g)

        if B.nip != A.nip:

            raise ValueError("Gauss-point operands have different numbers of integration points")

        # end if

    elif isinstance(other, oarrss):

        plain = other
        feoarrss_from_oarrss_to(&plain.arr, A.nip, &tmp_b)
        B = &tmp_b
        array = True

    else:

        return NotImplemented

    # end if

    # Broadcast a 1 x 1 operand over the other's shape.
    if A.nrows != B.nrows or A.ncols != B.ncols:

        if A.nrows == 1 and A.ncols == 1:

            feoarrss_bcast_to(A, B.nrows, B.ncols, &tmp_a)
            A = &tmp_a

        elif B.nrows == 1 and B.ncols == 1:

            X = &tmp_a if B == &tmp_b else &tmp_b

            if X == &tmp_b:

                feoarrss_bcast_to(B, A.nrows, A.ncols, &tmp_b)

            else:

                feoarrss_bcast_to(B, A.nrows, A.ncols, &tmp_a)

            # end if

            B = X

        else:

            feoarrss_free(&tmp_a)
            feoarrss_free(&tmp_b)
            raise ValueError("Gauss-point operands have incompatible shapes ({}, {}) and ({}, {})"
                             .format(A.nrows, A.ncols, B.nrows, B.ncols))

        # end if

    # end if

    if reverse:

        A, B = B, A

    # end if

    if op == "add":

        oarrss_sum_OO_to(&A.arr, &B.arr, &res.arr, _dhl)

    elif op == "sub":

        oarrss_sub_OO_to(&A.arr, &B.arr, &res.arr, _dhl)

    elif op == "mul":

        oarrss_mul_OO_to(&A.arr, &B.arr, &res.arr, _dhl)

    else:

        oarrss_div_OO_to(&A.arr, &B.arr, &res.arr, _dhl)

    # end if

    feoarrss_set_shape(A.nrows, A.ncols, A.nip, &res)
    feoarrss_free(&tmp_a)
    feoarrss_free(&tmp_b)

    return _fe_take(&res, array)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef object _fe_unary(_ssfe value, str name):
    """
    Evaluate an elementary function at every entry and point through the SoA kernels.

    Parameters
    ----------
    value : _ssfe
        Argument.
    name : str
        Function name understood by math.pxi's _unary ("sin", "exp", ...).

    Returns
    -------
    ssotife or oarrssfe
        Result of the same kind and shape.
    """

    return _fe_adopt(value, _unary(_fe_view(value), name))

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef object _fe_adopt(_ssfe like, oarrss out):
    """
    Wrap an oarrss computed on a Gauss value's embedded array as a Gauss value of the same kind.

    Parameters
    ----------
    like : _ssfe
        Gauss value whose shape and kind the result takes.
    out : oarrss
        Result of an SoA operation on like's embedded nip x (nrows * ncols) array; its buffers
        move into the new object.

    Returns
    -------
    ssotife or oarrssfe
        Gauss-point result.
    """

    cdef feoarrss_t res = feoarrss_init()

    res.arr = out.arr
    out.arr = oarrss_init()
    feoarrss_set_shape(like.fe.nrows, like.fe.ncols, like.fe.nip, &res)

    return _fe_take(&res, _fe_is_array(like))

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef object _fe_store(object result, object out):
    """
    Move a result into a caller-provided output object (the out= argument of module functions).

    Parameters
    ----------
    result : object
        Freshly created result (ssotife, oarrssfe, ssotinum or oarrss).
    out : object
        None, or an object of a compatible type that receives the result.

    Returns
    -------
    object
        out when given, otherwise result.
    """

    cdef _ssfe gres, gout
    cdef oarrss ares, aout
    cdef ssotinum sres, sout

    if out is None:

        return result

    # end if

    if isinstance(result, _ssfe) and isinstance(out, _ssfe):

        gres = result
        gout = out
        feoarrss_free(&gout.fe)
        gout.fe = gres.fe
        gres.fe = feoarrss_init()

    elif isinstance(result, oarrss) and isinstance(out, oarrss):

        ares = result
        aout = out
        oarrss_free(&aout.arr)
        aout.arr = ares.arr
        ares.arr = oarrss_init()

    elif isinstance(result, ssotinum) and isinstance(out, ssotinum):

        sres = result
        sout = out
        ssoti_free(&sout.num)
        sout.num = sres.num
        sres.num = ssoti_init()

    else:

        raise TypeError("out= has type {} but the result is {}".format(
            type(out).__name__, type(result).__name__))

    # end if

    return out

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef object _fe_factor(object direction):
    """
    Return the factor that turns an imaginary coefficient into a derivative.

    Parameters
    ----------
    direction : object
        Direction in any pyoti.sparse format, or a rawdir.

    Returns
    -------
    float
        Product of the factorials of the base multiplicities (1 for the real part).
    """

    cdef tuple pair = _direction(direction)
    cdef object labels
    cdef object factor = 1

    if pair[1] == 0:

        return 1.0

    # end if

    labels = _unrank(pair[0], pair[1])

    for count in _Counter(labels).values():

        factor *= _factorial(count)

    # end for

    return float(factor)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef object _fe_block(_ssfe value, object direction):
    """
    Copy one direction block of the embedded array into a NumPy array shaped like the object.

    Parameters
    ----------
    value : _ssfe
        Gauss-point object.
    direction : object
        Direction in any pyoti.sparse format, or a rawdir; 0 or [] selects the real part.

    Returns
    -------
    numpy.ndarray
        Shape (nip,) for an ssotife, (nip, nrows, ncols) for an oarrssfe; zeros when the direction
        is outside the active set or above the truncation order.
    """

    cdef tuple pair = _direction(direction)
    cdef coeff_t *block = oarrss_get_block(pair[0], pair[1], &value.fe.arr)
    cdef np.npy_intp dims[1]
    cdef np.ndarray flat
    cdef object shape

    if _fe_is_array(value):

        shape = (value.fe.nip, value.fe.nrows, value.fe.ncols)

    else:

        shape = (value.fe.nip,)

    # end if

    if block == NULL:

        return np.zeros(shape)

    # end if

    dims[0] = value.fe.arr.size
    flat = np.PyArray_SimpleNewFromData(1, dims, np.NPY_DOUBLE, <void *>block)

    return flat.reshape(shape, order="F").copy()

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef class _ssfe:
    """
    Common storage and operations of the semi-sparse Gauss-point types.

    The coefficients live in one feoarrss_t: an nip x (nrows * ncols) SoA array whose entry
    (ip, i + j * nrows) is entry (i, j) of the matrix at integration point ip.
    """

    # ****************************************************************************************************
    def __cinit__(self):
        """
        Initialize an empty native value.
        """

        self.fe = feoarrss_init()

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def __dealloc__(self):
        """
        Release the native buffers.
        """

        feoarrss_free(&self.fe)

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
        Number of active bases shared by every point.

        Returns
        -------
        int
            Size of the active set.
        """

        return self.fe.arr.nbases

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def get_active_bases(self):
        """
        Return the sorted active global bases.

        Returns
        -------
        list of int
            Active bases.
        """

        cdef bases_t i

        return [self.fe.arr.p_bases[i] for i in range(self.fe.arr.nbases)]

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def copy(self):
        """
        Return an independent copy.

        Returns
        -------
        ssotife or oarrssfe
            Copy of the same kind.
        """

        cdef feoarrss_t res = feoarrss_init()

        feoarrss_copy_to(&self.fe, &res)

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

        return _fe_block(self, humdir) * _fe_factor(humdir)

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
        ssotife or oarrssfe
            Result of the same kind.
        """

        cdef feoarrss_t res = feoarrss_init()

        oarrss_get_order_im_to(order, &self.fe.arr, &res.arr)
        feoarrss_set_shape(self.fe.nrows, self.fe.ncols, self.fe.nip, &res)

        return _fe_take(&res, _fe_is_array(self))

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
        ssotife or oarrssfe
            Truncated copy.
        """

        cdef tuple pair = _direction(humdir)
        cdef feoarrss_t res = feoarrss_init()

        oarrss_truncate_im_to(pair[0], pair[1], &self.fe.arr, &res.arr)
        feoarrss_set_shape(self.fe.nrows, self.fe.ncols, self.fe.nip, &res)

        return _fe_take(&res, _fe_is_array(self))

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
        ssotife or oarrssfe
            Truncated copy.
        """

        cdef feoarrss_t res = feoarrss_init()

        oarrss_truncate_order_to(order, &self.fe.arr, &res.arr)
        feoarrss_set_shape(self.fe.nrows, self.fe.ncols, self.fe.nip, &res)

        return _fe_take(&res, _fe_is_array(self))

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def set(self, rhs):
        """
        Overwrite every entry at every point.

        Parameters
        ----------
        rhs : float or ssotinum or sotinum or ssotife or oarrss or matso or oarrssfe
            New value. Scalars (plain or Gauss) fill every entry; a plain matrix is repeated at every
            point; a Gauss array must have the same shape.
        """

        cdef feoarrss_t res = feoarrss_init()
        cdef feoarrss_t zero
        cdef _ssfe g
        cdef oarrss plain
        cdef ssotinum o
        cdef uint64_t e

        rhs = _fe_plain(rhs)

        if isinstance(rhs, _ssfe):

            g = rhs

            if g.fe.nip != self.fe.nip:

                raise ValueError("Gauss-point operands have different numbers of integration points")

            # end if

            if g.fe.nrows == self.fe.nrows and g.fe.ncols == self.fe.ncols:

                feoarrss_copy_to(&g.fe, &res)

            elif g.fe.nrows == 1 and g.fe.ncols == 1:

                feoarrss_bcast_to(&g.fe, self.fe.nrows, self.fe.ncols, &res)

            else:

                raise ValueError("shape mismatch in set()")

            # end if

        elif isinstance(rhs, oarrss):

            plain = rhs

            if plain.arr.nrows != self.fe.nrows or plain.arr.ncols != self.fe.ncols:

                raise ValueError("shape mismatch in set()")

            # end if

            feoarrss_from_oarrss_to(&plain.arr, self.fe.nip, &res)

        else:

            zero = feoarrss_zeros(self.fe.arr.p_bases, self.fe.arr.nbases, self.fe.nrows,
                                  self.fe.ncols, self.fe.nip, self.fe.arr.trc_order)

            if isinstance(rhs, ssotinum):

                o = rhs
                oarrss_sum_oO_to(&o.num, &zero.arr, &res.arr, _dhl)
                feoarrss_set_shape(self.fe.nrows, self.fe.ncols, self.fe.nip, &res)
                feoarrss_free(&zero)

            elif isinstance(rhs, Real):

                for e in range(zero.arr.size):

                    zero.arr.p_data[e] = rhs

                # end for

                res = zero

            else:

                feoarrss_free(&zero)
                raise TypeError("unsupported value type {}".format(type(rhs).__name__))

            # end if

        # end if

        feoarrss_free(&self.fe)
        self.fe = res

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def gauss_integrate(self, w):
        """
        Integrate with the Gauss rule: sum over points of w_ip times the value at ip.

        Parameters
        ----------
        w : ssotife
            Weights (possibly OTI, e.g. w * detJ) at the same points.

        Returns
        -------
        ssotinum or oarrss
            Integral (a scalar for an ssotife, a matrix for an oarrssfe).
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
        ssotife or oarrssfe
            Same semantics as oarrss.extract_im, per entry and point.
        """

        return _fe_adopt(self, _fe_view(self).extract_im(humdir))

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
        ssotife or oarrssfe
            Same semantics as oarrss.extract_deriv, per entry and point.
        """

        return _fe_adopt(self, _fe_view(self).extract_deriv(humdir))

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
        Long representation: shape, number of points, active set, order and real part.

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
        ssotife or oarrssfe
            Negated copy.
        """

        cdef feoarrss_t res = feoarrss_init()

        oarrss_neg_to(&self.fe.arr, &res.arr, _dhl)
        feoarrss_set_shape(self.fe.nrows, self.fe.ncols, self.fe.nip, &res)

        return _fe_take(&res, _fe_is_array(self))

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def __pos__(self):
        """
        Return a copy.

        Returns
        -------
        ssotife or oarrssfe
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
        ssotife or oarrssfe
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
        ssotife or oarrssfe
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
        ssotife or oarrssfe
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
        ssotife or oarrssfe
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
        ssotife or oarrssfe
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
        ssotife or oarrssfe
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
        ssotife or oarrssfe
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
        ssotife or oarrssfe
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
        ssotife or oarrssfe
            Quotient.
        """

        return _fe_binary(self, other, "div", True)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def __iadd__(self, other):
        """
        Add in place.

        Parameters
        ----------
        other : object
            Real, OTI scalar or matrix, or Gauss value.

        Returns
        -------
        ssotife or oarrssfe
            Updated object.
        """

        return _fe_inplace(self, _fe_binary(self, other, "add", False))

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def __isub__(self, other):
        """
        Subtract in place.

        Parameters
        ----------
        other : object
            Real, OTI scalar or matrix, or Gauss value.

        Returns
        -------
        ssotife or oarrssfe
            Updated object.
        """

        return _fe_inplace(self, _fe_binary(self, other, "sub", False))

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def __imul__(self, other):
        """
        Multiply in place.

        Parameters
        ----------
        other : object
            Real, OTI scalar or matrix, or Gauss value.

        Returns
        -------
        ssotife or oarrssfe
            Updated object.
        """

        return _fe_inplace(self, _fe_binary(self, other, "mul", False))

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def __itruediv__(self, other):
        """
        Divide in place.

        Parameters
        ----------
        other : object
            Real, OTI scalar or matrix, or Gauss value.

        Returns
        -------
        ssotife or oarrssfe
            Updated object.
        """

        return _fe_inplace(self, _fe_binary(self, other, "div", False))

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
        ssotife or oarrssfe
            Power.
        """

        cdef feoarrss_t res = feoarrss_init()

        if modulo is not None or not isinstance(exponent, Real):

            return NotImplemented

        # end if

        oarrss_pow_to(&self.fe.arr, exponent, &res.arr, _dhl)
        feoarrss_set_shape(self.fe.nrows, self.fe.ncols, self.fe.nip, &res)

        return _fe_take(&res, _fe_is_array(self))

    # end function
    # ----------------------------------------------------------------------------------------------------

# end class
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef object _fe_inplace(_ssfe target, object result):
    """
    Move a result of the same kind into the target (the in-place operators).

    Parameters
    ----------
    target : _ssfe
        Left operand of the in-place operator.
    result : object
        Freshly computed result.

    Returns
    -------
    object
        target when the kinds match (updated in place), otherwise result.
    """

    cdef _ssfe g

    if result is NotImplemented or type(result) is not type(target):

        return result

    # end if

    g = result
    feoarrss_free(&target.fe)
    target.fe = g.fe
    g.fe = feoarrss_init()

    return target

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef class ssotife(_ssfe):
    """
    Semi-sparse OTI scalar at nip integration points (counterpart of pyoti.sparse.sotife).
    """

    # ****************************************************************************************************
    def __init__(self, real=0.0, nip=1, order=0, nbases=0, bases=()):
        """
        Create a Gauss-point scalar holding the same value at every point.

        Same leading arguments as pyoti.sparse.sotife(real, nip, order, nbases).

        Parameters
        ----------
        real : float or ssotinum or sotinum
            Value at every point.
        nip : int
            Number of integration points.
        order : int
            Minimum truncation order.
        nbases : int
            Accepted for pyoti.sparse compatibility (a capacity hint there); unused.
        bases : iterable of int
            Extra active bases to include (the value's own bases are always included).
        """

        cdef ssotife res = _fe_scalar(real, bases, order, nip)

        feoarrss_free(&self.fe)
        self.fe = res.fe
        res.fe = feoarrss_init()

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
        ssotife
            Semi-sparse copy.
        """

        cdef ssotife res = _fe_scalar(0.0, (), 0, value.nip)
        cdef uint64_t ip

        for ip in range(value.nip):

            res[ip] = ssotinum(value[ip])

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
        ssotinum
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
        ssotinum
            Independent copy of the value at ip.
        """

        cdef int64_t k = _fe_point(ip, self.fe.nip)
        cdef oarrss_t one = oarrss_init()
        cdef ssotinum_t num = ssoti_init()

        feoarrss_get_ip_to(k, &self.fe, &one)
        oarrss_get_item_to(0, 0, &one, &num)
        oarrss_free(&one)

        return ssotinum.wrap(num)

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
        value : float or ssotinum or sotinum
            New value.
        """

        cdef int64_t k = _fe_point(ip, self.fe.nip)
        cdef ssotinum o

        value = _fe_plain(value)

        if isinstance(value, ssotinum):

            o = value
            feoarrss_set_ijk_o(&o.num, 0, 0, k, &self.fe)

        elif isinstance(value, Real):

            feoarrss_set_ijk_r(value, 0, 0, k, &self.fe)

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

        return "ssotife(nip={}, bases={}, order={}, real={})".format(
            self.fe.nip, self.get_active_bases(), self.fe.arr.trc_order, self.real.tolist())

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

    cdef int64_t k = ip

    if k < 0:

        k += nip

    # end if

    if k < 0 or k >= <int64_t>nip:

        raise IndexError("integration point {} out of range for nip={}".format(ip, nip))

    # end if

    return k

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

    cdef int64_t k

    if isinstance(key, slice):

        start, stop, step = key.indices(n)

        return (start, len(range(start, stop, step)), step, False)

    # end if

    k = key

    if k < 0:

        k += n

    # end if

    if k < 0 or k >= <int64_t>n:

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
cdef class oarrssfe(_ssfe):
    """
    Semi-sparse OTI matrix at nip integration points (counterpart of pyoti.sparse.matsofe).
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
            Active bases.
        """

        cdef oarrssfe res = _fe_zeros(shape, bases, order, nip)

        feoarrss_free(&self.fe)
        self.fe = res.fe
        res.fe = feoarrss_init()

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
        oarrssfe
            Semi-sparse copy.
        """

        cdef oarrssfe res = _fe_zeros(value.shape, (), 0, value.nip)
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
        values : sequence of oarrss or matso
            Matrices of equal shape.

        Returns
        -------
        oarrssfe
            Gauss-point matrix with nip = len(values).
        """

        cdef list mats = [_fe_plain(v) for v in values]
        cdef oarrssfe res
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
        cdef oarrss point

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
        oarrssfe
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
        oarrssfe
            Transposed copy.
        """

        cdef feoarrss_t res = feoarrss_init()

        feoarrss_transpose_to(&self.fe, &res)

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
        oarrss
            Independent plain matrix.
        """

        cdef int64_t k = _fe_point(ip, self.fe.nip)
        cdef oarrss_t res = oarrss_init()

        feoarrss_get_ip_to(k, &self.fe, &res)

        return oarrss.wrap(res)

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
        value : oarrss or matso or arrss
            Plain matrix of the same shape.
        """

        cdef int64_t k = _fe_point(ip, self.fe.nip)
        cdef oarrss plain

        value = _fe_plain(value)

        if not isinstance(value, oarrss):

            raise TypeError("set_ip expects a plain OTI matrix")

        # end if

        plain = value

        if plain.arr.nrows != self.fe.nrows or plain.arr.ncols != self.fe.ncols:

            raise ValueError("shape mismatch in set_ip()")

        # end if

        feoarrss_set_ip(&plain.arr, k, &self.fe)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def set_ijk(self, rhs, i, j, k):
        """
        Overwrite entry (i, j) at integration point k.

        Parameters
        ----------
        rhs : float or ssotinum or sotinum
            New value.
        i : int
            Row.
        j : int
            Column.
        k : int
            Integration point.
        """

        cdef ssotinum o

        rhs = _fe_plain(rhs)

        if isinstance(rhs, ssotinum):

            o = rhs
            feoarrss_set_ijk_o(&o.num, i, j, k, &self.fe)

        elif isinstance(rhs, Real):

            feoarrss_set_ijk_r(rhs, i, j, k, &self.fe)

        else:

            raise ValueError("Supported values are real scalars, ssotinum and sotinum.")

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
        out : ssotife, optional
            Receives the result.

        Returns
        -------
        ssotife
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
        ssotife or oarrssfe
            A Gauss scalar for two integer indices, otherwise a Gauss sub-matrix.
        """

        cdef tuple parsed = _fe_key(key, self.fe.nrows, self.fe.ncols)
        cdef tuple rows = parsed[0]
        cdef tuple cols = parsed[1]
        cdef feoarrss_t res = feoarrss_init()

        feoarrss_get_slice_to(&self.fe, rows[0], rows[1], rows[2], cols[0], cols[1], cols[2], &res)

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
            same at every point) or Gauss matrix of the block's shape.
        """

        cdef tuple parsed = _fe_key(key, self.fe.nrows, self.fe.ncols)
        cdef tuple rows = parsed[0]
        cdef tuple cols = parsed[1]
        cdef feoarrss_t tmp = feoarrss_init()
        cdef _ssfe g
        cdef oarrss plain

        value = _fe_plain(value)

        if isinstance(value, _ssfe):

            g = value

            if g.fe.nip != self.fe.nip:

                raise ValueError("Gauss-point operands have different numbers of integration points")

            # end if

            if g is self:

                feoarrss_copy_to(&g.fe, &tmp)
                feoarrss_set_slice(&tmp, rows[0], rows[1], rows[2], cols[0], cols[1], cols[2],
                                   &self.fe)
                feoarrss_free(&tmp)

                return

            # end if

            if not ((g.fe.nrows == rows[1] and g.fe.ncols == cols[1])
                    or (g.fe.nrows == 1 and g.fe.ncols == 1)):

                raise ValueError("shape mismatch in Gauss-array assignment")

            # end if

            feoarrss_set_slice(&g.fe, rows[0], rows[1], rows[2], cols[0], cols[1], cols[2],
                               &self.fe)

        elif isinstance(value, oarrss):

            plain = value

            if plain.arr.nrows != rows[1] or plain.arr.ncols != cols[1]:

                raise ValueError("shape mismatch in Gauss-array assignment")

            # end if

            feoarrss_from_oarrss_to(&plain.arr, self.fe.nip, &tmp)
            feoarrss_set_slice(&tmp, rows[0], rows[1], rows[2], cols[0], cols[1], cols[2], &self.fe)
            feoarrss_free(&tmp)

        elif isinstance(value, (Real, ssotinum)):

            g = _fe_scalar(value, (), 0, self.fe.nip)
            feoarrss_set_slice(&g.fe, rows[0], rows[1], rows[2], cols[0], cols[1], cols[2],
                               &self.fe)

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
        other : oarrssfe or oarrss or matso
            Right operand.

        Returns
        -------
        oarrssfe
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
        other : oarrssfe or oarrss or matso
            Right operand.

        Returns
        -------
        oarrssfe
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
        other : oarrss or matso
            Left operand.

        Returns
        -------
        oarrssfe
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
        oarrssfe
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
        ssotife
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

        return "oarrssfe(shape={}, nip={}, bases={}, order={})\nreal =\n{}".format(
            self.shape, self.fe.nip, self.get_active_bases(), self.fe.arr.trc_order,
            repr(self.real))

    # end function
    # ----------------------------------------------------------------------------------------------------

# end class
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _fe_zeros(shape, bases, order, nip):
    """
    Create an oarrssfe of zeros at nip integration points.

    Parameters
    ----------
    shape : int or tuple of int
        (nrows, ncols) at each point; an int n means (n, 1).
    bases : iterable of int
        Sorted active global bases (may be empty).
    order : int
        Truncation order.
    nip : int
        Number of integration points (> 0).

    Returns
    -------
    oarrssfe
        New Gauss-point array.
    """

    cdef list active = _bases(bases)
    cdef np.ndarray[np.uint16_t, ndim=1] labels = np.asarray(active, dtype=np.uint16)
    cdef bases_t *ptr = NULL
    cdef feoarrss_t res

    if isinstance(shape, int):

        shape = (shape, 1)

    # end if

    shape = tuple(shape)

    if len(shape) != 2 or any(not isinstance(x, int) or x < 0 for x in shape):

        raise ValueError("shape must be (nonnegative rows, nonnegative columns)")

    # end if

    if order < 0 or order > 255:

        raise ValueError("order must be between 0 and 255")

    # end if

    if nip < 1:

        raise ValueError("nip must be positive")

    # end if

    if active:

        ptr = <bases_t *>labels.data

    # end if

    res = feoarrss_zeros(ptr, len(active), shape[0], shape[1], nip, order)

    return _fe_take(&res, True)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _fe_scalar(value, bases, order, nip):
    """
    Create an ssotife holding the same value at nip integration points.

    Parameters
    ----------
    value : float or ssotinum or sotinum
        Value at every point.
    bases : iterable of int
        Sorted active global bases to include (may be empty).
    order : int
        Minimum truncation order.
    nip : int
        Number of integration points (> 0).

    Returns
    -------
    ssotife
        New Gauss-point scalar.
    """

    cdef list active = _bases(bases)
    cdef np.ndarray[np.uint16_t, ndim=1] labels = np.asarray(active, dtype=np.uint16)
    cdef bases_t *ptr = NULL
    cdef feoarrss_t zero, res = feoarrss_init()
    cdef ssotinum o
    cdef uint64_t ip

    if order < 0 or order > 255:

        raise ValueError("order must be between 0 and 255")

    # end if

    if nip < 1:

        raise ValueError("nip must be positive")

    # end if

    if active:

        ptr = <bases_t *>labels.data

    # end if

    zero  = feoarrss_zeros(ptr, len(active), 1, 1, nip, order)
    value = _fe_plain(value)

    if isinstance(value, ssotinum):

        o = value
        feoarrss_grow(o.num.p_bases, o.num.nbases, o.num.trc_order, &zero)
        oarrss_sum_oO_to(&o.num, &zero.arr, &res.arr, _dhl)
        feoarrss_set_shape(1, 1, nip, &res)
        feoarrss_free(&zero)

    elif isinstance(value, Real):

        for ip in range(nip):

            zero.arr.p_data[ip] = value

        # end for

        res = zero

    else:

        feoarrss_free(&zero)
        raise TypeError("expected a real or OTI scalar")

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
    val : ssotife or oarrssfe
        Integrand at the points.
    w : ssotife
        Weights at the same points (possibly OTI, e.g. w * detJ).
    out : ssotinum or oarrss, optional
        Receives the result.

    Returns
    -------
    ssotinum or oarrss
        Integral: a scalar for an ssotife integrand, a matrix for an oarrssfe.
    """

    cdef _ssfe v, g
    cdef oarrss_t res = oarrss_init()
    cdef ssotinum_t num = ssoti_init()
    cdef int status

    if not isinstance(val, _ssfe) or not isinstance(w, ssotife):

        raise TypeError("gauss_integrate expects a Gauss-point value and ssotife weights")

    # end if

    v = val
    g = w
    status = feoarrss_integrate_to(&v.fe, &g.fe, &res, _dhl)

    if status != 0:

        oarrss_free(&res)
        _fe_status(status, "gauss_integrate")

    # end if

    if _fe_is_array(v):

        return _fe_store(oarrss.wrap(res), out)

    # end if

    oarrss_get_item_to(0, 0, &res, &num)
    oarrss_free(&res)

    return _fe_store(ssotinum.wrap(num), out)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _fe_dot(left, right, out=None):
    """
    Matrix product at every point with at least one Gauss-point operand.

    Parameters
    ----------
    left : oarrssfe or oarrss or matso or arrss
        Left operand.
    right : oarrssfe or oarrss or matso or arrss
        Right operand.
    out : oarrssfe, optional
        Receives the result.

    Returns
    -------
    oarrssfe
        Product.
    """

    cdef _ssfe a, b
    cdef oarrss p
    cdef feoarrss_t res = feoarrss_init()
    cdef int status

    left  = _fe_plain(left)
    right = _fe_plain(right)

    if isinstance(left, _ssfe) and isinstance(right, _ssfe):

        a = left
        b = right

        if a.fe.nip != b.fe.nip:

            raise ValueError("Gauss-point operands have different numbers of integration points")

        # end if

        status = feoarrss_matmul_FF_to(&a.fe, &b.fe, &res, _dhl)

    elif isinstance(left, _ssfe) and isinstance(right, oarrss):

        a = left
        p = right
        status = feoarrss_matmul_FO_to(&a.fe, &p.arr, &res, _dhl)

    elif isinstance(left, oarrss) and isinstance(right, _ssfe):

        p = left
        b = right
        status = feoarrss_matmul_OF_to(&p.arr, &b.fe, &res, _dhl)

    else:

        raise TypeError("dot expects a Gauss-point matrix and an OTI matrix")

    # end if

    if status != 0:

        feoarrss_free(&res)
        _fe_status(status, "dot")

    # end if

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
    out : ssotife, optional
        Receives the result.

    Returns
    -------
    ssotife
        Dot product at every point.
    """

    cdef _ssfe a, b
    cdef oarrss p
    cdef feoarrss_t res = feoarrss_init()
    cdef int status

    left  = _fe_plain(left)
    right = _fe_plain(right)

    # Entries pair row-major, as in pyoti.sparse. The kernels pair column-major, which is the same
    # for equal shapes and for vectors; otherwise pair the transposes.
    if left.shape != right.shape:

        left  = left.T
        right = right.T

    # end if

    if isinstance(left, _ssfe) and isinstance(right, _ssfe):

        a = left
        b = right

        if a.fe.nip != b.fe.nip:

            raise ValueError("Gauss-point operands have different numbers of integration points")

        # end if

        status = feoarrss_dot_product_FF_to(&a.fe, &b.fe, &res, _dhl)

    elif isinstance(left, _ssfe) and isinstance(right, oarrss):

        a = left
        p = right
        status = feoarrss_dot_product_FO_to(&a.fe, &p.arr, &res, _dhl)

    elif isinstance(left, oarrss) and isinstance(right, _ssfe):

        p = left
        b = right
        status = feoarrss_dot_product_FO_to(&b.fe, &p.arr, &res, _dhl)

    else:

        raise TypeError("dot_product expects a Gauss-point value and an OTI matrix")

    # end if

    if status != 0:

        feoarrss_free(&res)
        _fe_status(status, "dot_product")

    # end if

    return _fe_store(_fe_take(&res, False), out)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _fe_det(value, out=None):
    """
    Determinant at every point.

    Parameters
    ----------
    value : oarrssfe
        Square Gauss-point matrix.
    out : ssotife, optional
        Receives the result.

    Returns
    -------
    ssotife
        Determinant.
    """

    cdef _ssfe a = value
    cdef feoarrss_t res = feoarrss_init()
    cdef int status = feoarrss_det_to(&a.fe, &res, _dhl)

    if status != 0:

        feoarrss_free(&res)
        _fe_status(status, "det")

    # end if

    return _fe_store(_fe_take(&res, False), out)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _fe_inv(value, out=None):
    """
    Inverse at every point.

    Parameters
    ----------
    value : oarrssfe
        Square Gauss-point matrix.
    out : oarrssfe, optional
        Receives the result.

    Returns
    -------
    oarrssfe
        Inverse.
    """

    cdef _ssfe a = value
    cdef feoarrss_t res = feoarrss_init()
    cdef int status = feoarrss_inv_to(&a.fe, &res, _dhl)

    if status != 0:

        feoarrss_free(&res)
        _fe_status(status, "inv")

    # end if

    return _fe_store(_fe_take(&res, True), out)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _fe_transpose(value, out=None):
    """
    Transpose at every point.

    Parameters
    ----------
    value : oarrssfe
        Gauss-point matrix.
    out : oarrssfe, optional
        Receives the result.

    Returns
    -------
    oarrssfe
        Transpose.
    """

    cdef _ssfe a = value
    cdef feoarrss_t res = feoarrss_init()

    feoarrss_transpose_to(&a.fe, &res)

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
    ssotife or oarrssfe
        Result.
    """

    cdef object res

    if isinstance(left, _ssfe):

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
    Create an oarrssfe of zeros (pyoti.sparse.fezeros counterpart).

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
    oarrssfe
        Zero Gauss-point matrix.
    """

    if isinstance(shape, tuple) and len(shape) == 1:

        shape = (shape[0], 1)

    # end if

    return _fe_zeros(shape, (), order, nip)

# end function
# --------------------------------------------------------------------------------------------------------
