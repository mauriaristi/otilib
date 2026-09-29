# Semi-sparse OTI scalar class (ssotinum).


# ********************************************************************************************************
cdef class ssotinum:
    """
    Semi-sparse OTI scalar, dense over its sorted active basis set.

    Parameters
    ----------
    value : float or pyoti.sparse.sotinum or ssotinum
        Value to initialize.
    order : int
        Truncation order for a real value.
    """

    # ****************************************************************************************************
    def __cinit__(self):
        """
        Initialize an empty owned C scalar.
        """

        self.num = ssoti_init()

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def __init__(self, value=0.0, order=0):
        """
        Initialize from a real, sparse scalar, or semi-sparse scalar.

        Parameters
        ----------
        value : float or sotinum or ssotinum
            Initial value.
        order : int
            Truncation order for real inputs.
        """

        if isinstance(value, ssotinum):

            self.num = ssoti_copy(&(<ssotinum>value).num)

        elif isinstance(value, sotinum):

            self.num = ssoti_from_soti(&(<sotinum>value).num, _dhl)

        elif isinstance(value, Real):

            if order < 0 or order > 255:

                raise ValueError("order must be between 0 and 255")

            # end if

            self.num = ssoti_create_r(value, order)

        else:

            raise TypeError("expected a real or sparse/semi-sparse OTI scalar")

        # end if


    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def __dealloc__(self):
        """
        Release the owned scalar buffers.
        """

        ssoti_free(&self.num)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    @staticmethod
    cdef ssotinum wrap(ssotinum_t value):
        """
        Transfer ownership of a native scalar into a Python wrapper.

        Parameters
        ----------
        value : ssotinum_t
            Owned C scalar.

        Returns
        -------
        ssotinum
            Wrapped scalar.
        """

        cdef ssotinum result = ssotinum.__new__(ssotinum)
        result.num = value
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

        cdef sotinum_t result = ssoti_to_soti(&self.num, _dhl)
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
    def active_bases(self):
        """
        Return the sorted active global basis labels.

        Returns
        -------
        tuple
            Basis labels.
        """

        return tuple(self.num.p_bases[i] for i in range(self.num.nbases))

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

        return ssoti_density(&self.num)

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

        return ssoti_memory_size(&self.num)

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
        return ssoti_get_item(pair[0], pair[1], &self.num)

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
        return ssoti_get_deriv(pair[0], pair[1], &self.num)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def set_im(self, val, humdir):
        """
        Set a coefficient and grow the active set when necessary.

        Parameters
        ----------
        val : float
            New coefficient.
        humdir : int or list or tuple
            Direction in any pyoti.sparse format, or a rawdir.
        """

        cdef tuple pair = _direction(humdir)
        ssoti_set_item(val, pair[0], pair[1], &self.num)

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
        ssotinum
            Truncated copy.
        """

        cdef tuple pair = _direction(humdir)
        return ssotinum.wrap(ssoti_truncate_im(pair[0], pair[1], &self.num))

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def truncate_order(self, order):
        """
        Remove coefficients of this order and above.

        Parameters
        ----------
        order : int
            First order to remove.

        Returns
        -------
        ssotinum
            Truncated copy.
        """

        return ssotinum.wrap(ssoti_truncate_order(order, &self.num))

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
        ssotinum
            Extracted copy.
        """

        return ssotinum.wrap(ssoti_get_order_im(order, &self.num))

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def compact(self):
        """
        Drop inactive bases while preserving the scalar's value.

        Returns
        -------
        ssotinum
            Compact copy.
        """

        return ssotinum.wrap(ssoti_compact(&self.num))

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

        cdef ndir_t total = sshelp_ndir_total(self.num.nbases, self.num.trc_order)
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

            size = sshelp_ndir_order(self.num.nbases, p)
            off = sshelp_order_offset(self.num.nbases, p)
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
            Sorted basis labels of the active set.
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
        ssotinum
            Independent copy.
        """

        return ssotinum.wrap(ssoti_copy(&self.num))

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def set(self, rhs):
        """
        Replace the coefficients by those of a real or OTI scalar, keeping this object.

        A real keeps the truncation order of this scalar; an OTI scalar brings its own.

        Parameters
        ----------
        rhs : float or sotinum or ssotinum
            New value.
        """

        cdef ssotinum_t fresh
        cdef ord_t order = self.num.trc_order

        if isinstance(rhs, Real):

            fresh = ssoti_create_r(rhs, order)

        elif isinstance(rhs, (ssotinum, sotinum)):

            fresh = ssoti_copy(&(<ssotinum>_as_scalar(rhs, 0)).num)

        else:

            raise TypeError("expected a real or sparse/semi-sparse OTI scalar")

        # end if

        ssoti_free(&self.num)
        self.num = fresh

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

        ssoti_set_item(val / _deriv_factor(pair[0], pair[1]), pair[0], pair[1], &self.num)

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
        ssotinum
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
        ssotinum
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
        return ssoti_get_item(pair[0], pair[1], &self.num)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def __setitem__(self, key, value):
        """
        Set a coefficient by its raw direction, growing the active set when necessary.

        Parameters
        ----------
        key : list or tuple or rawdir
            Global direction index and order, ``[index, order]``, or a rawdir.
        value : float
            New coefficient.
        """

        cdef tuple pair = _raw_key(key)
        ssoti_set_item(value, pair[0], pair[1], &self.num)

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

        return "ssotinum({}, nnz: {}, order: {})".format(self.num.re, self.nnz, self.num.act_order)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def long_repr(self):
        """
        Give a description with the storage of every order.

        Returns
        -------
        str
            Real part, counts, orders, active bases and the nonzero count of each order.
        """

        info = self.get_nnz_full()
        body = "{}, nnz: {}, alloc: {}, actual order: {}, truncation order: {}, bases: {}\n".format(
            self.num.re, info[0], info[1], self.num.act_order, self.num.trc_order,
            self.active_bases)

        for p in range(self.num.trc_order):

            body += "  - Order {}->   nnz: {}  size: {} \n".format(p + 1, info[2][p], info[3][p])

        # end for

        return "ssotinum(" + body + ")"

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def __abs__(self):
        """
        Return the absolute value, negating the scalar when its real part is negative.

        Returns
        -------
        ssotinum
            Absolute value.
        """

        if self.num.re < 0:

            return ssotinum.wrap(ssoti_neg(&self.num, _dhl))

        # end if

        return ssotinum.wrap(ssoti_copy(&self.num))

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def __iadd__(self, other):
        """
        Add in the sense of ``+=``; like ``pyoti.sparse`` this binds the sum to the name.

        Parameters
        ----------
        other : real or ssotinum or sotinum
            Addend.

        Returns
        -------
        ssotinum or NotImplemented
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
        other : real or ssotinum or sotinum
            Subtrahend.

        Returns
        -------
        ssotinum or NotImplemented
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
        other : real or ssotinum or sotinum
            Multiplier.

        Returns
        -------
        ssotinum or NotImplemented
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
        other : real or ssotinum or sotinum
            Denominator.

        Returns
        -------
        ssotinum or NotImplemented
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
        base : real or sotinum or ssotinum
            Base.
        modulus : None
            Modular exponentiation is unsupported.

        Returns
        -------
        ssotinum or NotImplemented
            Power when supported.
        """

        if modulus is not None:

            return NotImplemented

        # end if

        if isinstance(base, Real):

            return _unary(self * _math_log(base), "exp")

        # end if

        if isinstance(base, (ssotinum, sotinum)):

            return _unary(self * _unary(base, "log"), "exp")

        # end if

        return NotImplemented

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def __repr__(self):
        """
        Format the scalar through its public sparse representation.

        Returns
        -------
        str
            Scalar value and active set.
        """

        return "ssotinum({}, bases={})".format(_scalar_text(self), self.active_bases)

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
        ssotinum
            Negated scalar.
        """

        return ssotinum.wrap(ssoti_neg(&self.num, _dhl))

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def __add__(self, other):
        """
        Add a real or OTI scalar.

        Parameters
        ----------
        other : real or ssotinum or sotinum
            Addend.

        Returns
        -------
        ssotinum or NotImplemented
            Sum when supported.
        """

        cdef ssotinum fast

        if type(other) is float or type(other) is int:

            fast = ssotinum.__new__(ssotinum)
            ssoti_sum_or_to(&self.num, other, &fast.num, _dhl)
            return fast

        # end if

        cdef ssotinum rhs
        cdef ssotinum result

        if isinstance(other, ssotinum):

            rhs = other

        elif isinstance(other, sotinum):

            rhs = ssotinum(other)

        elif isinstance(other, Real):

            result = ssotinum.__new__(ssotinum)
            ssoti_sum_or_to(&(<ssotinum>self).num, other, &result.num, _dhl)
            return result

        else:

            return NotImplemented

        # end if

        result = ssotinum.__new__(ssotinum)
        ssoti_sum_oo_to(&(<ssotinum>self).num, &rhs.num, &result.num, _dhl)
        return result

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
        ssotinum or NotImplemented
            Sum when supported.
        """

        cdef ssotinum fast

        if type(other) is float or type(other) is int:

            fast = ssotinum.__new__(ssotinum)
            ssoti_sum_or_to(&self.num, other, &fast.num, _dhl)
            return fast

        # end if

        return self.__add__(other)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def __sub__(self, other):
        """
        Subtract a real or OTI scalar.

        Parameters
        ----------
        other : real or ssotinum or sotinum
            Subtrahend.

        Returns
        -------
        ssotinum or NotImplemented
            Difference when supported.
        """

        cdef ssotinum fast

        if type(other) is float or type(other) is int:

            fast = ssotinum.__new__(ssotinum)
            ssoti_sub_or_to(&self.num, other, &fast.num, _dhl)
            return fast

        # end if

        cdef ssotinum rhs

        if isinstance(other, (ssotinum, sotinum, Real)):

            rhs = other if isinstance(other, ssotinum) else ssotinum(other, order=self.order)
            return ssotinum.wrap(ssoti_sub_oo(&(<ssotinum>self).num, &rhs.num, _dhl))

        # end if

        return NotImplemented

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
        ssotinum or NotImplemented
            Difference when supported.
        """

        cdef ssotinum fast

        if type(other) is float or type(other) is int:

            fast = ssotinum.__new__(ssotinum)
            ssoti_sub_ro_to(other, &self.num, &fast.num, _dhl)
            return fast

        # end if

        if isinstance(other, (ssotinum, sotinum, Real)):

            return ssotinum(other, order=self.order).__sub__(self)

        # end if

        return NotImplemented

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def __mul__(self, other):
        """
        Multiply by a real or OTI scalar.

        Parameters
        ----------
        other : real or ssotinum or sotinum
            Multiplier.

        Returns
        -------
        ssotinum or NotImplemented
            Product when supported.
        """

        cdef ssotinum fast

        if type(other) is float or type(other) is int:

            fast = ssotinum.__new__(ssotinum)
            ssoti_mul_or_to(&self.num, other, &fast.num, _dhl)
            return fast

        # end if

        cdef ssotinum rhs
        cdef ssotinum result

        if isinstance(other, ssotinum):

            rhs = other

        elif isinstance(other, sotinum):

            rhs = ssotinum(other)

        elif isinstance(other, Real):

            result = ssotinum.__new__(ssotinum)
            ssoti_mul_or_to(&(<ssotinum>self).num, other, &result.num, _dhl)
            return result

        else:

            return NotImplemented

        # end if

        result = ssotinum.__new__(ssotinum)
        ssoti_mul_oo_to(&(<ssotinum>self).num, &rhs.num, &result.num, _dhl)
        return result

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
        ssotinum or NotImplemented
            Product when supported.
        """

        cdef ssotinum fast

        if type(other) is float or type(other) is int:

            fast = ssotinum.__new__(ssotinum)
            ssoti_mul_or_to(&self.num, other, &fast.num, _dhl)
            return fast

        # end if

        return self.__mul__(other)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def __truediv__(self, other):
        """
        Divide by a real or OTI scalar.

        Parameters
        ----------
        other : real or ssotinum or sotinum
            Denominator.

        Returns
        -------
        ssotinum or NotImplemented
            Quotient when supported.
        """

        cdef ssotinum fast

        if type(other) is float or type(other) is int:

            fast = ssotinum.__new__(ssotinum)
            ssoti_div_or_to(&self.num, other, &fast.num, _dhl)
            return fast

        # end if

        cdef ssotinum rhs

        if isinstance(other, (ssotinum, sotinum, Real)):

            rhs = other if isinstance(other, ssotinum) else ssotinum(other, order=self.order)
            return ssotinum.wrap(ssoti_div_oo(&(<ssotinum>self).num, &rhs.num, _dhl))

        # end if

        return NotImplemented

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
        ssotinum or NotImplemented
            Quotient when supported.
        """

        cdef ssotinum fast

        if type(other) is float or type(other) is int:

            fast = ssotinum.__new__(ssotinum)
            ssoti_div_ro_to(other, &self.num, &fast.num, _dhl)
            return fast

        # end if

        if isinstance(other, (ssotinum, sotinum, Real)):

            return ssotinum(other, order=self.order).__truediv__(self)

        # end if

        return NotImplemented

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def __pow__(self, exponent, modulus=None):
        """
        Raise the scalar to a real or OTI power (an OTI exponent gives ``exp(exponent * log(self))``).

        Parameters
        ----------
        exponent : float or ssotinum or sotinum
            Exponent.
        modulus : None
            Modular exponentiation is unsupported.

        Returns
        -------
        ssotinum or NotImplemented
            Power when supported.
        """

        if modulus is not None:

            return NotImplemented

        # end if

        if isinstance(exponent, (ssotinum, sotinum)):

            return _unary(_unary(self, "log") * exponent, "exp")

        # end if

        if not isinstance(exponent, Real):

            return NotImplemented

        # end if

        return ssotinum.wrap(ssoti_pow(&(<ssotinum>self).num, exponent, _dhl))

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def rom_eval(self, bases, deltas):
        """
        Evaluate the Taylor series (reduced-order model) at real perturbations of the bases.

        Same call as ``sotinum.rom_eval``; bases not listed get a zero perturbation (Phase 2,
        ``semisparse/order.pxi``).

        Parameters
        ----------
        bases : sequence of int
            Base labels.
        deltas : sequence of float
            Perturbation of each base.

        Returns
        -------
        ssotinum
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
