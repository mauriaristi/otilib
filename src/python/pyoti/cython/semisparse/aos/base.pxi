# Semi-sparse array-of-structures matrix class (arrss).


# ********************************************************************************************************
cdef class arrss:
    """
    Array-of-structures semi-sparse matrix with an active set per element.

    Construct via ``zeros`` or ``from_sparse``. Indexing returns an owned scalar copy.
    """

    # ****************************************************************************************************
    def __cinit__(self):
        """
        Initialize the owned array handle.
        """

        self.arr = arrss_init()

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def __dealloc__(self):
        """
        Free all owned AoS elements.
        """

        arrss_free(&self.arr)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    @staticmethod
    cdef arrss wrap(arrss_t value):
        """
        Transfer ownership of a native AoS array.

        Parameters
        ----------
        value : arrss_t
            Owned array.

        Returns
        -------
        arrss
            Python wrapper.
        """

        cdef arrss result = arrss.__new__(arrss)
        result.arr = value
        return result

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    @classmethod
    def zeros(cls, shape, order=0):
        """
        Create a zero matrix whose elements initially have no active bases.

        Parameters
        ----------
        shape : tuple of int
            Rows and columns.
        order : int
            Truncation order of the zero elements.

        Returns
        -------
        arrss
            Zero AoS matrix.
        """

        if len(shape) != 2 or any(not isinstance(x, int) or x < 0 for x in shape):

            raise ValueError("shape must contain nonnegative rows and columns")

        # end if

        if order < 0 or order > 255:

            raise ValueError("order must be between 0 and 255")

        # end if

        return arrss.wrap(arrss_zeros(shape[0], shape[1], order))

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    @classmethod
    def from_sparse(cls, matso value):
        """
        Convert a sparse matrix element by element, retaining each active set.

        Parameters
        ----------
        value : matso
            Sparse source.

        Returns
        -------
        arrss
            AoS matrix.
        """

        return arrss.wrap(arrss_from_arrso(&value.arr, _dhl))

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    @classmethod
    def from_soa(cls, oarrss value):
        """
        Copy a shared-set SoA array into the AoS layout.

        Parameters
        ----------
        value : oarrss
            SoA array.

        Returns
        -------
        arrss
            AoS copy.
        """

        cdef arrss_t result = arrss_init()
        arrss_from_oarrss(&value.arr, &result)
        return arrss.wrap(result)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def to_sparse(self):
        """
        Convert every AoS element to a sparse OTI scalar.

        Returns
        -------
        matso
            Sparse array.
        """

        cdef arrso_t result = arrss_to_arrso(&self.arr, _dhl)
        return matso.create(&result)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def to_soa(self):
        """
        Convert the element-specific active sets to a shared union set.

        Returns
        -------
        oarrss
            SoA copy.
        """

        cdef oarrss_t result = oarrss_init()
        arrss_to_oarrss(&self.arr, &result)
        return oarrss.wrap(result)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    @property
    def shape(self):
        """
        Return the array's row and column counts.

        Returns
        -------
        tuple
            Matrix shape.
        """

        return self.arr.nrows, self.arr.ncols

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    @property
    def order(self):
        """
        Return the maximum truncation order among the elements.

        Returns
        -------
        int
            Maximum element order, or zero for an empty matrix.
        """

        cdef uint64_t index
        cdef ord_t top = 0

        for index in range(self.arr.size):

            if self.arr.p_data[index].trc_order > top:

                top = self.arr.p_data[index].trc_order

            # end if

        # end for

        return top

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    @property
    def memory_bytes(self):
        """
        Return the AoS container and its owned scalar buffer sizes.

        Returns
        -------
        int
            Allocated bytes.
        """

        cdef uint64_t index
        cdef size_t total = sizeof(arrss_t)

        for index in range(self.arr.size):

            total += ssoti_memory_size(&self.arr.p_data[index])

        # end for

        return total

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    @property
    def T(self):
        """
        Return a transposed AoS copy.

        Returns
        -------
        arrss
            Transposed array.
        """

        cdef arrss_t result = arrss_init()
        arrss_transpose_to(&self.arr, &result)
        return arrss.wrap(result)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # Make NumPy defer to the reflected operators of this class instead of broadcasting over it.
    __array_ufunc__ = None

    # ****************************************************************************************************
    @property
    def nrows(self):
        """
        Return the number of rows.

        Returns
        -------
        int
            Row count.
        """

        return self.arr.nrows

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    @property
    def ncols(self):
        """
        Return the number of columns.

        Returns
        -------
        int
            Column count.
        """

        return self.arr.ncols

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    @property
    def size(self):
        """
        Return the number of elements.

        Returns
        -------
        int
            Rows times columns.
        """

        return self.arr.size

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    @property
    def real(self):
        """
        Copy the real parts into a NumPy matrix.

        Returns
        -------
        numpy.ndarray
            Real coefficients, shape (nrows, ncols).
        """

        return _array_real(self)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def copy(self):
        """
        Copy the array.

        Returns
        -------
        arrss
            Independent copy.
        """

        return arrss.wrap(arrss_copy(&self.arr))

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def get_im(self, hum_dir):
        """
        Read the coefficient of one direction in every element.

        Parameters
        ----------
        hum_dir : int or list or tuple
            Direction in any pyoti.sparse format, or a rawdir; 0 or [] selects the real part.

        Returns
        -------
        numpy.ndarray
            Coefficients, shape (nrows, ncols); zeros outside the active set.
        """

        return _array_get_im(self, hum_dir, False)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def get_deriv(self, hum_dir):
        """
        Read the derivative along one direction in every element.

        Parameters
        ----------
        hum_dir : int or list or tuple
            Direction in any pyoti.sparse format, or a rawdir.

        Returns
        -------
        numpy.ndarray
            Derivatives, shape (nrows, ncols); zeros outside the active set.
        """

        return _array_get_im(self, hum_dir, True)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def set_im(self, val, humdir):
        """
        Set the coefficient of one direction in every element, growing the active set.

        Parameters
        ----------
        val : float or array_like
            Real scalar, or matrix of shape (nrows, ncols).
        humdir : int or list or tuple
            Direction in any pyoti.sparse format, or a rawdir.
        """

        _array_set_im(self, val, humdir, False)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def set_deriv(self, val, humdir):
        """
        Set one direction in every element from derivative values, growing the active set.

        Parameters
        ----------
        val : float or array_like
            Real scalar, or matrix of shape (nrows, ncols), of derivatives.
        humdir : int or list or tuple
            Direction in any pyoti.sparse format, or a rawdir.
        """

        _array_set_im(self, val, humdir, True)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def set(self, rhs):
        """
        Overwrite every element with a real, an OTI scalar or an array of the same shape.

        Parameters
        ----------
        rhs : float or ssotinum or sotinum or array
            New value; the truncation order rises to the value's when it is larger.
        """

        self[:, :] = rhs

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def get_active_bases(self):
        """
        List the active bases (the union over the elements for AoS arrays).

        Returns
        -------
        list of int
            Sorted basis labels.
        """

        return _array_active_bases(self)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def dot(lhs, rhs, out=None):
        """
        Multiply by another matrix; same as the module function ``dot``.

        Parameters
        ----------
        rhs : arrss
            Right factor.
        out : arrss, optional
            Holder for the product.

        Returns
        -------
        arrss
            Product, or None when ``out`` is given.
        """

        return dot(lhs, rhs, out)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def inv(arr, out=None):
        """
        Invert the matrix; same as the module function ``inv``.

        Parameters
        ----------
        out : arrss, optional
            Holder for the inverse.

        Returns
        -------
        arrss
            Inverse, or None when ``out`` is given.
        """

        return inv(arr, out)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def transpose(arr, out=None):
        """
        Transpose the matrix; same as the module function ``transpose``.

        Parameters
        ----------
        out : arrss, optional
            Holder for the transpose.

        Returns
        -------
        arrss
            Transposed copy, or None when ``out`` is given.
        """

        return transpose(arr, out)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def __rmatmul__(self, other):
        """
        Multiply a matrix of the other semi-sparse layout or a sparse matrix from the left.

        Parameters
        ----------
        other : oarrss or arrss or matso
            Left factor.

        Returns
        -------
        arrss or NotImplemented
            Matrix product when supported.
        """

        if isinstance(other, matso):

            other = arrss.from_sparse(other)

        elif isinstance(other, (oarrss, arrss)) and not isinstance(other, arrss):

            other = other.to_aos()

        else:

            return NotImplemented

        # end if

        return other @ self

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def __getitem__(self, key):
        """
        Read an element or a block with the indexing semantics of ``pyoti.sparse.matso``.

        A single integer or slice selects rows and keeps every column, so ``A[i]`` is a
        1 x ncols matrix; two integers select one element.

        Parameters
        ----------
        key : int or slice or tuple
            Matrix key.

        Returns
        -------
        ssotinum or arrss
            Element copy for two integers, otherwise a new array holding the block.
        """

        return _aos_getitem(self, key)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def __setitem__(self, key, value):
        """
        Assign an element or a block with the indexing semantics of ``pyoti.sparse.matso``.

        The truncation order rises to the value's when it is larger (existing entries are
        zero-extended), and the active set grows to hold the value's bases.

        Parameters
        ----------
        key : int or slice or tuple
            Matrix key.
        value : float or ssotinum or sotinum or array or numpy.ndarray
            Replacement; arrays must have the shape of the selected block.
        """

        _aos_setitem(self, key, value)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def __str__(self):
        """
        Format every element like ``pyoti.sparse``, with plain integers in the directions.

        Returns
        -------
        str
            One line per element.
        """

        return _array_text(self)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def short_repr(self):
        """
        Give a compact description with the real part.

        Returns
        -------
        str
            Shape and real coefficients.
        """

        return "arrss< shape: {}, re:\n{}>".format(self.shape, repr(self.real))

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def long_repr(self):
        """
        Give a description with the shape, order, active bases and real part.

        Returns
        -------
        str
            Shape, truncation order, active bases and real coefficients.
        """

        return "arrss< shape: {}, order: {}, bases: {}, re:\n{}>".format(
            self.shape, self.order, self.get_active_bases(), repr(self.real))

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def __abs__(self):
        """
        Take the absolute value of every element (negating those with a negative real part).

        Returns
        -------
        arrss
            Elementwise absolute value.
        """

        cdef arrss result = arrss.wrap(arrss_copy(&self.arr))
        cdef uint64_t index
        cdef ssotinum_t negated

        for index in range(result.arr.size):

            if result.arr.p_data[index].re < 0:

                negated = ssoti_neg(&result.arr.p_data[index], _dhl)
                ssoti_free(&result.arr.p_data[index])
                result.arr.p_data[index] = negated

            # end if

        # end for

        return result

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def __iadd__(self, other):
        """
        Add in the sense of ``+=``; like ``pyoti.sparse`` this binds the sum to the name.

        Parameters
        ----------
        other : arrss or ssotinum or float
            Addend.

        Returns
        -------
        arrss or NotImplemented
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
        other : arrss or ssotinum or float
            Subtrahend.

        Returns
        -------
        arrss or NotImplemented
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
        other : arrss or ssotinum or float
            Multiplier.

        Returns
        -------
        arrss or NotImplemented
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
        other : arrss or ssotinum or float
            Denominator.

        Returns
        -------
        arrss or NotImplemented
            Quotient when supported.
        """

        return self.__truediv__(other)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def __repr__(self):
        """
        Summarize the AoS shape and maximum truncation order.

        Returns
        -------
        str
            Array summary.
        """

        return "arrss(shape={}, order={})".format(self.shape, self.order)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def truncate(self, humdir):
        """
        Zero a direction and its multiples in every element.

        Parameters
        ----------
        humdir : int or list or tuple
            Direction in any pyoti.sparse format, or a rawdir.

        Returns
        -------
        arrss
            Truncated copy.
        """

        cdef tuple pair = _direction(humdir)
        cdef arrss_t result = arrss_init()
        arrss_truncate_im_to(pair[0], pair[1], &self.arr, &result, _dhl)
        return arrss.wrap(result)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def truncate_order(self, order):
        """
        Remove this order and higher orders from every element.

        Parameters
        ----------
        order : int
            First order removed.

        Returns
        -------
        arrss
            Truncated copy.
        """

        cdef arrss_t result = arrss_init()
        arrss_truncate_order_to(order, &self.arr, &result, _dhl)
        return arrss.wrap(result)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def get_order_im(self, order):
        """
        Keep only one order in every element.

        Parameters
        ----------
        order : int
            Order retained.

        Returns
        -------
        arrss
            Extracted copy.
        """

        cdef arrss_t result = arrss_init()
        arrss_get_order_im_to(order, &self.arr, &result, _dhl)
        return arrss.wrap(result)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def compact(self):
        """
        Drop inactive bases independently in each element.

        Returns
        -------
        arrss
            Compact copy.
        """

        cdef arrss_t result = arrss_init()
        arrss_compact_to(&self.arr, &result, _dhl)
        return arrss.wrap(result)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def __neg__(self):
        """
        Negate all elements.

        Returns
        -------
        arrss
            Negated array.
        """

        cdef arrss_t result = arrss_init()
        arrss_neg_to(&self.arr, &result, _dhl)
        return arrss.wrap(result)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def __add__(self, other):
        """
        Add an array or broadcast scalar.

        Parameters
        ----------
        other : arrss or ssotinum or float
            Addend.

        Returns
        -------
        arrss or NotImplemented
            Sum when supported.
        """

        return _aos_binary(self, other, "add", False)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def __radd__(self, other):
        """
        Broadcast-add a scalar on the left.

        Parameters
        ----------
        other : ssotinum or float
            Left addend.

        Returns
        -------
        arrss or NotImplemented
            Sum when supported.
        """

        return _aos_binary(self, other, "add", True)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def __sub__(self, other):
        """
        Subtract an array or broadcast scalar.

        Parameters
        ----------
        other : arrss or ssotinum or float
            Subtrahend.

        Returns
        -------
        arrss or NotImplemented
            Difference when supported.
        """

        return _aos_binary(self, other, "sub", False)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def __rsub__(self, other):
        """
        Subtract the array from a broadcast scalar.

        Parameters
        ----------
        other : ssotinum or float
            Left operand.

        Returns
        -------
        arrss or NotImplemented
            Difference when supported.
        """

        return _aos_binary(self, other, "sub", True)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def __mul__(self, other):
        """
        Multiply an array or broadcast scalar elementwise.

        Parameters
        ----------
        other : arrss or ssotinum or float
            Multiplier.

        Returns
        -------
        arrss or NotImplemented
            Product when supported.
        """

        return _aos_binary(self, other, "mul", False)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def __rmul__(self, other):
        """
        Broadcast-multiply a scalar on the left.

        Parameters
        ----------
        other : ssotinum or float
            Left multiplier.

        Returns
        -------
        arrss or NotImplemented
            Product when supported.
        """

        return _aos_binary(self, other, "mul", True)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def __truediv__(self, other):
        """
        Divide by an array or broadcast scalar elementwise.

        Parameters
        ----------
        other : arrss or ssotinum or float
            Denominator.

        Returns
        -------
        arrss or NotImplemented
            Quotient when supported.
        """

        return _aos_binary(self, other, "div", False)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def __rtruediv__(self, other):
        """
        Divide a broadcast scalar by this array.

        Parameters
        ----------
        other : ssotinum or float
            Numerator.

        Returns
        -------
        arrss or NotImplemented
            Quotient when supported.
        """

        return _aos_binary(self, other, "div", True)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def __pow__(self, exponent, modulus=None):
        """
        Raise each element to a real power.

        Parameters
        ----------
        exponent : float
            Real exponent.
        modulus : None
            Modular powers are unsupported.

        Returns
        -------
        arrss or NotImplemented
            Elementwise power.
        """

        cdef arrss_t result = arrss_init()

        if modulus is not None or not isinstance(exponent, Real):

            return NotImplemented

        # end if

        arrss_pow_to(&(<arrss>self).arr, exponent, &result, _dhl)
        return arrss.wrap(result)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def __matmul__(self, other):
        """
        Multiply two AoS matrices.

        Parameters
        ----------
        other : arrss
            Right matrix.

        Returns
        -------
        arrss or NotImplemented
            Matrix product when supported.
        """

        cdef arrss_t result = arrss_init()

        if not isinstance(other, arrss):

            return NotImplemented

        # end if

        if (<arrss>self).arr.ncols != (<arrss>other).arr.nrows:

            raise ValueError("matmul: incompatible matrix dimensions")

        # end if

        arrss_matmul_OO_to(&(<arrss>self).arr, &(<arrss>other).arr, &result, _dhl)
        return arrss.wrap(result)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def rom_eval(self, bases, deltas):
        """
        Evaluate the Taylor series of every element at real perturbations of the bases.

        Same call as ``matso.rom_eval``; a scalar ``deltas`` (or ``bases=None``) perturbs every
        active base by that value (Phase 2, ``semisparse/order.pxi``).

        Parameters
        ----------
        bases : sequence of int or None
            Base labels.
        deltas : sequence of float or float
            Perturbation of each base.

        Returns
        -------
        arrss
            Real values of the series (truncation order 0).
        """

        return _order_rom_eval(self, bases, deltas)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def get_all_ims(self, nbasis, order):
        """
        Export every imaginary coefficient in the layout of ``matso.get_all_ims``.

        Parameters
        ----------
        nbasis : int
            Number of global bases of the layout.
        order : int
            Highest order to export.

        Returns
        -------
        numpy.ndarray
            Shape (C(nbasis + order, order), nrows, ncols); [0] is the real part, then the
            directions sorted by order and global index.
        """

        return _order_get_all_ims(self, nbasis, order, False)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def get_all_derivs(self, nbasis, order):
        """
        Export every derivative in the layout of ``matso.get_all_derivs``.

        Parameters
        ----------
        nbasis : int
            Number of global bases of the layout.
        order : int
            Highest order to export.

        Returns
        -------
        numpy.ndarray
            Shape (C(nbasis + order, order), nrows, ncols), like ``get_all_ims`` with derivatives.
        """

        return _order_get_all_ims(self, nbasis, order, True)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def extract_im(self, hum_dir):
        """
        Collect, in every element, the coefficients that are multiples of a direction.

        Parameters
        ----------
        hum_dir : int or list or tuple
            Direction in any pyoti.sparse format, or a rawdir.

        Returns
        -------
        arrss
            Extracted array (see ``extract_im``).
        """

        return extract_im(hum_dir, self)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def extract_deriv(self, hum_dir):
        """
        Collect, in every element, the multiples of a direction as derivatives.

        Parameters
        ----------
        hum_dir : int or list or tuple
            Direction in any pyoti.sparse format, or a rawdir.

        Returns
        -------
        arrss
            Extracted array (see ``extract_deriv``).
        """

        return extract_deriv(hum_dir, self)

    # end function
    # ----------------------------------------------------------------------------------------------------

# end class
# --------------------------------------------------------------------------------------------------------
