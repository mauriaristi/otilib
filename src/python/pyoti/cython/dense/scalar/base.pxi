# Dense OTI scalar class (otinum). Owner: WP8a.


cdef object _OP_NAMES = ("add", "sub", "mul", "div")


# ********************************************************************************************************
cdef otinum _to_operand(object other):
    """
    Bring a sparse or dense scalar operand to an otinum.

    Parameters
    ----------
    other : object
        Candidate operand.

    Returns
    -------
    otinum
        The operand itself, a dense copy of a sparse scalar, or None for any other type.
    """

    if isinstance(other, otinum):

        return other

    # end if

    if isinstance(other, sotinum):

        return otinum(other)

    # end if

    return None

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef object _scalar_binary(otinum left, object other, int op, bint reverse):
    """
    Evaluate ``left op other`` (or ``other op left`` when reverse) for a real or OTI operand.

    Parameters
    ----------
    left : otinum
        Scalar operand.
    other : object
        Real, sparse scalar or dense scalar.
    op : int
        0 add, 1 sub, 2 mul, 3 div.
    reverse : bool
        Whether ``other`` is the left operand of the operation.

    Returns
    -------
    otinum or NotImplemented
        Result of the operation.
    """

    cdef otinum rhs
    cdef otinum res = otinum.__new__(otinum)
    cdef double val
    cdef int status

    if type(other) is float or type(other) is int or isinstance(other, Real):

        val = other

        if op == 0:

            status = oti_sum_or_to(&left.num, val, &res.num, _dhl)

        elif op == 1:

            if reverse:

                status = oti_sub_ro_to(val, &left.num, &res.num, _dhl)

            else:

                status = oti_sub_or_to(&left.num, val, &res.num, _dhl)

            # end if

        elif op == 2:

            status = oti_mul_or_to(&left.num, val, &res.num, _dhl)

        else:

            if reverse:

                status = oti_div_ro_to(val, &left.num, &res.num, _dhl)

            else:

                status = oti_div_or_to(&left.num, val, &res.num, _dhl)

            # end if

        # end if

        _status(_OP_NAMES[op], status)
        return res

    # end if

    rhs = _to_operand(other)

    if rhs is None:

        return NotImplemented

    # end if

    if reverse:

        left, rhs = rhs, left

    # end if

    if op == 0:

        status = oti_sum_oo_to(&left.num, &rhs.num, &res.num, _dhl)

    elif op == 1:

        status = oti_sub_oo_to(&left.num, &rhs.num, &res.num, _dhl)

    elif op == 2:

        status = oti_mul_oo_to(&left.num, &rhs.num, &res.num, _dhl)

    else:

        status = oti_div_oo_to(&left.num, &rhs.num, &res.num, _dhl)

    # end if

    _status(_OP_NAMES[op], status)
    return res

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef otinum _scalar_log_exp(otinum value, bint take_log):
    """
    Evaluate the natural logarithm or the exponential of a scalar.

    Parameters
    ----------
    value : otinum
        Argument.
    take_log : bool
        True for the logarithm, False for the exponential.

    Returns
    -------
    otinum
        Function result.
    """

    cdef otinum res = otinum.__new__(otinum)

    if take_log:

        _status("log", oti_log_to(&value.num, &res.num, _dhl))

    else:

        _status("exp", oti_exp_to(&value.num, &res.num, _dhl))

    # end if

    return res

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef int _require_owner(otinum value) except -1:
    """
    Refuse to modify a scalar that only views another object's C value.

    Parameters
    ----------
    value : otinum
        Scalar about to be modified.
    """

    if not value.FLAGS & 1:

        raise ValueError("this otinum is a view of another object and cannot be modified in place")

    # end if

    return 0

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef class otinum:
    """
    Dense OTI scalar, dense over the global bases 1..nact with its own truncation order.

    Parameters
    ----------
    value : float or pyoti.sparse.sotinum or otinum
        Value to initialize.
    order : int
        Truncation order for a real value, 0 to 150.
    """

    # ****************************************************************************************************
    def __cinit__(self):
        """
        Initialize an empty owned C scalar.
        """

        self.num = oti_init()
        self.FLAGS = 1

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def __init__(self, value=0.0, order=0):
        """
        Initialize from a real, a sparse scalar, or a dense scalar.

        Parameters
        ----------
        value : float or sotinum or otinum
            Initial value.
        order : int
            Truncation order for real inputs.
        """

        _require_owner(self)

        if isinstance(value, otinum):

            _status("otinum", oti_copy_to(&(<otinum>value).num, &self.num))

        elif isinstance(value, sotinum):

            _status("otinum", oti_from_soti_to(&(<sotinum>value).num, &self.num, _dhl))

        elif isinstance(value, Real):

            _check_order(order)
            oti_free(&self.num)
            self.num = oti_create_r(value, order)

        else:

            raise TypeError("expected a real or sparse/dense OTI scalar")

        # end if

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def __dealloc__(self):
        """
        Release the C scalar when this wrapper owns it.
        """

        if self.FLAGS & 1:

            oti_free(&self.num)

        # end if

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    @staticmethod
    cdef otinum wrap(otinum_t value):
        """
        Transfer ownership of a native scalar into a Python wrapper.

        Parameters
        ----------
        value : otinum_t
            Owned C scalar.

        Returns
        -------
        otinum
            Wrapped scalar.
        """

        cdef otinum result = otinum.__new__(otinum)

        oti_free(&result.num)
        result.num = value
        result.FLAGS = 1

        return result

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def to_sparse(self):
        """
        Convert to a pyoti.sparse scalar with the same coefficients.

        Returns
        -------
        sotinum
            Newly allocated sparse scalar.
        """

        cdef sotinum_t result = oti_to_soti(&self.num, _dhl)
        return sotinum.create(&result)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    @property
    def real(self):
        """
        Return the real coefficient.

        Returns
        -------
        float
            Real part.
        """

        return self.num.re

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    @property
    def order(self):
        """
        Return the truncation order.

        Returns
        -------
        int
            Highest allocated order.
        """

        return self.num.trc_order

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    @property
    def nact(self):
        """
        Return the number of active bases (the number is dense over the bases 1..nact).

        Returns
        -------
        int
            Number of active bases.
        """

        return self.num.nact

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    @property
    def active_bases(self):
        """
        Return the active global basis labels, ``(1, ..., nact)``.

        Returns
        -------
        tuple
            Basis labels.
        """

        return tuple(range(1, self.num.nact + 1))

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    @property
    def density(self):
        """
        Return the fraction of nonzero imaginary coefficient slots.

        Returns
        -------
        float
            Imaginary coefficient density.
        """

        return oti_density(&self.num)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    @property
    def memory_bytes(self):
        """
        Return the native scalar structure and owned buffer size.

        Returns
        -------
        int
            Allocated bytes.
        """

        return oti_memory_size(&self.num)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def get_im(self, humdir):
        """
        Read a coefficient using a human or global-index direction.

        Parameters
        ----------
        humdir : int or list or tuple
            Direction in any pyoti.sparse format, or a rawdir.

        Returns
        -------
        float
            Coefficient value.
        """

        cdef tuple pair = _direction(humdir)
        return oti_get_item(pair[0], pair[1], &self.num)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def get_deriv(self, humdir):
        """
        Read the derivative along a direction.

        Parameters
        ----------
        humdir : int or list or tuple
            Direction in any pyoti.sparse format, or a rawdir.

        Returns
        -------
        float
            Derivative value.
        """

        cdef tuple pair = _direction(humdir)
        return oti_get_deriv(pair[0], pair[1], &self.num)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def set_im(self, val, humdir):
        """
        Set a coefficient and grow the active bases when necessary.

        A direction of an order above the truncation order is ignored, as in ``pyoti.sparse``.

        Parameters
        ----------
        val : float
            New coefficient.
        humdir : int or list or tuple
            Direction in any pyoti.sparse format, or a rawdir.
        """

        cdef tuple pair = _direction(humdir)

        _require_owner(self)
        _status("set_im", oti_set_item(val, pair[0], pair[1], &self.num))

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def truncate(self, humdir):
        """
        Zero a direction and every higher direction containing it.

        Parameters
        ----------
        humdir : int or list or tuple
            Direction in any pyoti.sparse format, or a rawdir.

        Returns
        -------
        otinum
            Truncated copy.
        """

        cdef tuple pair = _direction(humdir)
        cdef otinum res = otinum.__new__(otinum)

        _status("truncate", oti_truncate_im_to(pair[0], pair[1], &self.num, &res.num))
        return res

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def truncate_order(self, order):
        """
        Remove coefficients of this order and above (the truncation order is kept).

        Parameters
        ----------
        order : int
            First order to remove.

        Returns
        -------
        otinum
            Truncated copy.
        """

        cdef otinum res = otinum.__new__(otinum)

        _check_order(order)
        _status("truncate_order", oti_truncate_order_to(order, &self.num, &res.num))
        return res

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def get_order_im(self, order):
        """
        Extract one order with all other orders zeroed.

        Parameters
        ----------
        order : int
            Order to retain.

        Returns
        -------
        otinum
            Extracted copy.
        """

        cdef otinum res = otinum.__new__(otinum)

        _check_order(order)
        _status("get_order_im", oti_get_order_im_to(order, &self.num, &res.num))
        return res

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def compact(self):
        """
        Trim trailing bases that hold no nonzero coefficient, preserving the value.

        Returns
        -------
        otinum
            Compact copy.
        """

        cdef otinum res = otinum.__new__(otinum)

        _status("compact", oti_compact_to(&self.num, &res.num))
        return res

    # end function
    # ----------------------------------------------------------------------------------------------------

    # Make NumPy defer to the reflected operators of this class instead of broadcasting over it.
    __array_ufunc__ = None

    # ****************************************************************************************************
    @real.setter
    def real(self, value):
        """
        Set the real coefficient.

        Parameters
        ----------
        value : float
            New real part.
        """

        _require_owner(self)
        self.num.re = value

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    @property
    def actual_order(self):
        """
        Return the highest order that may hold nonzero coefficients.

        Returns
        -------
        int
            Actual order, at most the truncation order.
        """

        return self.num.act_order

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    @property
    def nnz(self):
        """
        Count the nonzero coefficients, the real part included.

        Returns
        -------
        int
            Number of coefficients that are nonzero, plus one for the real part.
        """

        cdef ndir_t total = sshelp_ndir_total(self.num.nact, self.num.trc_order)
        cdef ndir_t i
        cdef uint64_t count = 1

        for i in range(total):

            if self.num.p_im[i] != 0.0:

                count += 1

            # end if

        # end for

        return count

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def get_nnz_full(self):
        """
        Count the nonzero and the storable coefficients, in total and order by order.

        Returns
        -------
        list
            ``[total_nnz, max_nnz_storable, nnz_per_order, size_per_order]`` like
            ``pyoti.sparse``: the storable count is the dense size over the active bases, and the
            per-order arrays start at order 1.
        """

        cdef ord_t p
        cdef ndir_t i, size, off
        cdef uint64_t nonzero
        cdef uint64_t total_nnz = 1
        cdef uint64_t total_size = 1
        cdef np.ndarray nnz = np.zeros(self.num.trc_order, dtype=int)
        cdef np.ndarray sizes = np.zeros(self.num.trc_order, dtype=int)

        for p in range(1, self.num.trc_order + 1):

            size = sshelp_ndir_order(self.num.nact, p)
            off = sshelp_order_offset(self.num.nact, p)
            nonzero = 0

            for i in range(size):

                if self.num.p_im[off + i] != 0.0:

                    nonzero += 1

                # end if

            # end for

            nnz[p - 1] = nonzero
            sizes[p - 1] = size
            total_nnz += nonzero
            total_size += size

        # end for

        return [total_nnz, total_size, nnz, sizes]

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def get_active_bases(self):
        """
        List the active bases.

        Returns
        -------
        list of int
            The labels ``[1, ..., nact]``.
        """

        return list(self.active_bases)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def copy(self):
        """
        Copy the scalar.

        Returns
        -------
        otinum
            Independent copy.
        """

        cdef otinum res = otinum.__new__(otinum)

        _status("copy", oti_copy_to(&self.num, &res.num))
        return res

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def set(self, rhs):
        """
        Replace the coefficients by those of a real or OTI scalar, keeping this object.

        A real keeps the truncation order of this scalar; an OTI scalar brings its own.

        Parameters
        ----------
        rhs : float or sotinum or otinum
            New value.
        """

        cdef otinum source

        _require_owner(self)

        if isinstance(rhs, Real):

            oti_set_r(rhs, &self.num)

        elif isinstance(rhs, (otinum, sotinum)):

            source = _as_scalar(rhs, 0)
            _status("set", oti_copy_to(&source.num, &self.num))

        else:

            raise TypeError("expected a real or sparse/dense OTI scalar")

        # end if

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def set_deriv(self, val, humdir):
        """
        Set the coefficient of a direction from a derivative value.

        Parameters
        ----------
        val : float
            Derivative along the direction; the coefficient is the derivative divided by the
            product of the factorials of the direction's exponents.
        humdir : int or list or tuple
            Direction in any pyoti.sparse format, or a rawdir.
        """

        cdef tuple pair = _direction(humdir)

        if not isinstance(val, Real):

            raise TypeError("set_deriv expects a real derivative value")

        # end if

        _require_owner(self)
        _status("set_deriv", oti_set_item(val / _deriv_factor(pair[0], pair[1]), pair[0], pair[1],
                                          &self.num))

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def extract_im(self, humdir):
        """
        Collect the coefficients that are multiples of a direction.

        Direction ``d + r`` of this scalar becomes direction ``r`` of the result, whose truncation
        order is that of this scalar minus the order of ``d``.

        Parameters
        ----------
        humdir : int or list or tuple
            Direction in any pyoti.sparse format, or a rawdir.

        Returns
        -------
        otinum
            Extracted scalar.
        """

        cdef tuple pair = _direction(humdir)
        return _extract_scalar(self, pair[0], pair[1], False)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def extract_deriv(self, humdir):
        """
        Collect the multiples of a direction as derivatives.

        Like ``extract_im``, with the coefficients scaled so that the result holds the correct
        derivatives.

        Parameters
        ----------
        humdir : int or list or tuple
            Direction in any pyoti.sparse format, or a rawdir.

        Returns
        -------
        otinum
            Extracted scalar.
        """

        cdef tuple pair = _direction(humdir)
        return _extract_scalar(self, pair[0], pair[1], True)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def __getitem__(self, key):
        """
        Read a coefficient by its raw direction, as ``pyoti.sparse`` does.

        Parameters
        ----------
        key : list or tuple or rawdir
            Global direction index and order, ``[index, order]``, or a rawdir.

        Returns
        -------
        float
            Coefficient value.
        """

        cdef tuple pair = _raw_key(key)
        return oti_get_item(pair[0], pair[1], &self.num)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def __setitem__(self, key, value):
        """
        Set a coefficient by its raw direction, growing the active bases when necessary.

        Parameters
        ----------
        key : list or tuple or rawdir
            Global direction index and order, ``[index, order]``, or a rawdir.
        value : float
            New coefficient.
        """

        cdef tuple pair = _raw_key(key)

        _require_owner(self)
        _status("setitem", oti_set_item(value, pair[0], pair[1], &self.num))

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def short_repr(self):
        """
        Give a compact one-line description.

        Returns
        -------
        str
            Real part, nonzero count and actual order.
        """

        return "otinum({}, nnz: {}, order: {})".format(self.num.re, self.nnz, self.num.act_order)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def long_repr(self):
        """
        Give a description with the storage of every order.

        Returns
        -------
        str
            Real part, counts, orders, number of active bases and the nonzero count of each order.
        """

        info = self.get_nnz_full()
        body = "{}, nnz: {}, alloc: {}, actual order: {}, truncation order: {}, bases: {}\n".format(
            self.num.re, info[0], info[1], self.num.act_order, self.num.trc_order,
            self.active_bases)

        for p in range(self.num.trc_order):

            body += "  - Order {}->   nnz: {}  size: {} \n".format(p + 1, info[2][p], info[3][p])

        # end for

        return "otinum(" + body + ")"

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def __abs__(self):
        """
        Return the absolute value, negating the scalar when its real part is negative.

        Returns
        -------
        otinum
            Absolute value.
        """

        cdef otinum res = otinum.__new__(otinum)

        if self.num.re < 0:

            _status("abs", oti_neg_to(&self.num, &res.num, _dhl))

        else:

            _status("abs", oti_copy_to(&self.num, &res.num))

        # end if

        return res

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def __iadd__(self, other):
        """
        Add in the sense of ``+=``; like ``pyoti.sparse`` this binds the sum to the name.

        Parameters
        ----------
        other : real or otinum or sotinum
            Addend.

        Returns
        -------
        otinum or NotImplemented
            Sum when supported.
        """

        return self.__add__(other)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def __isub__(self, other):
        """
        Subtract in the sense of ``-=``; like ``pyoti.sparse`` this binds the difference.

        Parameters
        ----------
        other : real or otinum or sotinum
            Subtrahend.

        Returns
        -------
        otinum or NotImplemented
            Difference when supported.
        """

        return self.__sub__(other)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def __imul__(self, other):
        """
        Multiply in the sense of ``*=``; like ``pyoti.sparse`` this binds the product.

        Parameters
        ----------
        other : real or otinum or sotinum
            Multiplier.

        Returns
        -------
        otinum or NotImplemented
            Product when supported.
        """

        return self.__mul__(other)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def __itruediv__(self, other):
        """
        Divide in the sense of ``/=``; this binds the quotient to the name.

        Parameters
        ----------
        other : real or otinum or sotinum
            Denominator.

        Returns
        -------
        otinum or NotImplemented
            Quotient when supported.
        """

        return self.__truediv__(other)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def __rpow__(self, base, modulus=None):
        """
        Raise a real or OTI base to this scalar, as ``exp(self * log(base))``.

        Parameters
        ----------
        base : real or sotinum or otinum
            Base.
        modulus : None
            Modular exponentiation is unsupported.

        Returns
        -------
        otinum or NotImplemented
            Power when supported.
        """

        if modulus is not None:

            return NotImplemented

        # end if

        if isinstance(base, Real):

            return _scalar_log_exp(self * _math_log(base), False)

        # end if

        if isinstance(base, (otinum, sotinum)):

            return _scalar_log_exp(self * _scalar_log_exp(_as_scalar(base, 0), True), False)

        # end if

        return NotImplemented

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def __repr__(self):
        """
        Format the scalar through the sparse text format.

        Returns
        -------
        str
            Scalar value and active bases.
        """

        return "otinum({}, bases={})".format(_scalar_text(self), self.active_bases)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def __str__(self):
        """
        Format the scalar coefficients for printing.

        Returns
        -------
        str
            Sparse-style scalar representation.
        """

        return _scalar_text(self)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def __neg__(self):
        """
        Negate every coefficient.

        Returns
        -------
        otinum
            Negated scalar.
        """

        cdef otinum res = otinum.__new__(otinum)

        _status("neg", oti_neg_to(&self.num, &res.num, _dhl))
        return res

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def __add__(self, other):
        """
        Add a real or OTI scalar.

        Parameters
        ----------
        other : real or otinum or sotinum
            Addend.

        Returns
        -------
        otinum or NotImplemented
            Sum when supported.
        """

        return _scalar_binary(self, other, 0, False)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def __radd__(self, other):
        """
        Add this scalar to a real or sparse scalar.

        Parameters
        ----------
        other : real or sotinum
            Left operand.

        Returns
        -------
        otinum or NotImplemented
            Sum when supported.
        """

        return _scalar_binary(self, other, 0, True)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def __sub__(self, other):
        """
        Subtract a real or OTI scalar.

        Parameters
        ----------
        other : real or otinum or sotinum
            Subtrahend.

        Returns
        -------
        otinum or NotImplemented
            Difference when supported.
        """

        return _scalar_binary(self, other, 1, False)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def __rsub__(self, other):
        """
        Subtract this scalar from another scalar.

        Parameters
        ----------
        other : real or sotinum
            Left operand.

        Returns
        -------
        otinum or NotImplemented
            Difference when supported.
        """

        return _scalar_binary(self, other, 1, True)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def __mul__(self, other):
        """
        Multiply by a real or OTI scalar.

        Parameters
        ----------
        other : real or otinum or sotinum
            Multiplier.

        Returns
        -------
        otinum or NotImplemented
            Product when supported.
        """

        return _scalar_binary(self, other, 2, False)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def __rmul__(self, other):
        """
        Multiply a real or sparse scalar by this scalar.

        Parameters
        ----------
        other : real or sotinum
            Left operand.

        Returns
        -------
        otinum or NotImplemented
            Product when supported.
        """

        return _scalar_binary(self, other, 2, True)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def __truediv__(self, other):
        """
        Divide by a real or OTI scalar.

        Parameters
        ----------
        other : real or otinum or sotinum
            Denominator.

        Returns
        -------
        otinum or NotImplemented
            Quotient when supported.
        """

        return _scalar_binary(self, other, 3, False)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def __rtruediv__(self, other):
        """
        Divide a real or sparse scalar by this scalar.

        Parameters
        ----------
        other : real or sotinum
            Numerator.

        Returns
        -------
        otinum or NotImplemented
            Quotient when supported.
        """

        return _scalar_binary(self, other, 3, True)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def __pow__(self, exponent, modulus=None):
        """
        Raise the scalar to a real or OTI power (an OTI exponent gives ``exp(exponent * log(self))``).

        Parameters
        ----------
        exponent : float or otinum or sotinum
            Exponent.
        modulus : None
            Modular exponentiation is unsupported.

        Returns
        -------
        otinum or NotImplemented
            Power when supported.
        """

        cdef otinum res

        if modulus is not None:

            return NotImplemented

        # end if

        if isinstance(exponent, (otinum, sotinum)):

            return _scalar_log_exp(_scalar_log_exp(self, True) * exponent, False)

        # end if

        if not isinstance(exponent, Real):

            return NotImplemented

        # end if

        res = otinum.__new__(otinum)
        _status("pow", oti_pow_to(&self.num, exponent, &res.num, _dhl))
        return res

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def rom_eval(self, bases, deltas):
        """
        Evaluate the Taylor series (reduced-order model) at real perturbations of the bases.

        Same call as ``sotinum.rom_eval``; bases not listed get a zero perturbation (``order.pxi``).

        Parameters
        ----------
        bases : sequence of int
            Base labels.
        deltas : sequence of float
            Perturbation of each base.

        Returns
        -------
        otinum
            Real value of the series (truncation order 0).
        """

        return _order_rom_eval(self, bases, deltas)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def rom_eval_array(self, bases, deltas):
        """
        Evaluate the Taylor series at many perturbations, given as one NumPy array per base.

        Parameters
        ----------
        bases : sequence of int
            Base labels.
        deltas : sequence of numpy.ndarray
            Perturbations of each base, all of the same shape.

        Returns
        -------
        numpy.ndarray
            Values of the series, of the shape of ``deltas[0]``.
        """

        return _order_rom_eval_array(self, bases, deltas)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def rom_eval_object(self, bases, deltas):
        """
        Evaluate the Taylor series with arbitrary objects (e.g. OTI numbers) as perturbations.

        Parameters
        ----------
        bases : sequence of int
            Base labels.
        deltas : sequence of object
            Perturbation of each base.

        Returns
        -------
        object
            Value of the series.
        """

        return _order_rom_eval_object(self, bases, deltas)

    # end function
    # ----------------------------------------------------------------------------------------------------

# end class
# --------------------------------------------------------------------------------------------------------
