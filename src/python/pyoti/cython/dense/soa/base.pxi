# Dense structure-of-arrays matrix class (omat).


# ********************************************************************************************************
cdef class omat:
    """
    Column-major structure-of-arrays dense OTI matrix.

    Create with ``zeros``, ``from_sparse`` or ``from_real``. Views returned by ``get_block``
    retain this array, but must not be used after an operation that grows its active set.
    """

    # ****************************************************************************************************
    def __cinit__(self):
        """
        Initialize an empty owned C array.
        """

        self.arr   = oarr_init()
        self.FLAGS = 1

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def __dealloc__(self):
        """
        Release the array's native buffers when this wrapper owns them.
        """

        if self.FLAGS & 1:

            oarr_free(&self.arr)

        # end if

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    @staticmethod
    cdef omat wrap(oarr_t value):
        """
        Transfer ownership of a native SoA array.

        Parameters
        ----------
        value : oarr_t
            Owned native array.

        Returns
        -------
        omat
            Wrapped array.
        """

        cdef omat result = omat.__new__(omat)
        result.arr   = value
        result.FLAGS = 1
        return result

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    @classmethod
    def zeros(cls, shape, bases=(), order=0):
        """
        Allocate a zero SoA matrix over the bases 1..max(bases).

        Parameters
        ----------
        shape : tuple of int
            Matrix rows and columns.
        bases : iterable of int
            Basis labels; the array is dense over 1..max(bases) (nact 0 when empty).
        order : int
            Truncation order, between 0 and 150.

        Returns
        -------
        omat
            Zero matrix.

        Raises
        ------
        ValueError
            If the shape or the order is invalid.
        MemoryError
            If the array is too large.
        """

        if len(shape) != 2 or any(not isinstance(x, int) or x < 0 for x in shape):

            raise ValueError("shape must be (nonnegative rows, nonnegative columns)")

        # end if

        _check_order(order)
        return _soa_zeros((shape[0], shape[1]), _nact_of(bases), order)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    @classmethod
    def from_sparse(cls, matso value):
        """
        Convert a sparse OTI matrix into a dense SoA matrix over the bases 1..(largest base present).

        Parameters
        ----------
        value : matso
            Sparse matrix.

        Returns
        -------
        omat
            Dense array.
        """

        return _soa_from_matso(value)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    @classmethod
    def from_real(cls, value, order=0):
        """
        Copy a real NumPy matrix into a column-major SoA array.

        Parameters
        ----------
        value : array_like
            Two-dimensional real matrix.
        order : int
            Truncation order, between 0 and 150.

        Returns
        -------
        omat
            Real-valued dense matrix (nact 0).

        Raises
        ------
        ValueError
            If ``value`` is not two-dimensional or the order is invalid.
        """

        cdef np.ndarray data = np.asarray(value, dtype=np.float64)

        if data.ndim != 2:

            raise ValueError("expected a two-dimensional real matrix")

        # end if

        _check_order(order)
        return _soa_from_real(data, order)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def to_sparse(self):
        """
        Convert the SoA matrix into a sparse OTI matrix.

        Returns
        -------
        matso
            Newly allocated sparse matrix.
        """

        cdef arrso_t result = oarr_to_arrso(&self.arr, _dhl)
        return matso.create(&result)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def to_aos(self):
        """
        Convert the SoA matrix to an AoS matrix: every element gets the array's nact and orders.

        Returns
        -------
        arro
            Owned AoS array.
        """

        return _to_aos(self)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    @property
    def shape(self):
        """
        Return the matrix dimensions.

        Returns
        -------
        tuple
            Number of rows and columns.
        """

        return self.arr.nrows, self.arr.ncols

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

        return self.arr.trc_order

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    @property
    def active_bases(self):
        """
        Return the active global basis labels 1..nact.

        Returns
        -------
        tuple
            Basis labels.
        """

        return tuple(range(1, self.arr.nact + 1))

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    @property
    def nact(self):
        """
        Return the number of active bases: every element is dense over 1..nact.

        Returns
        -------
        int
            Number of active bases.
        """

        return self.arr.nact

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
            Matrix density.
        """

        return oarr_density(&self.arr)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    @property
    def memory_bytes(self):
        """
        Return the native SoA structure and buffer size.

        Returns
        -------
        int
            Allocated bytes.
        """

        return oarr_memory_size(&self.arr)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    @property
    def T(self):
        """
        Return a transposed copy of every coefficient block.

        Returns
        -------
        omat
            Transposed matrix.
        """

        cdef oarr_t result = oarr_init()

        _soa_ok("transpose", oarr_transpose_to(&self.arr, &result, _dhl), &result)
        return omat.wrap(result)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def get_block(self, humdir):
        """
        Return a writable Fortran-ordered NumPy view of one direction block.

        The view keeps the array alive and is tracked: while it exists, an operation that would
        replace the native buffer (growing nact or the truncation order by assignment or ``set_im``,
        or ``out=`` into this array) raises BufferError instead of leaving the view dangling. Writes
        through the view and same-layout assignments are allowed.

        Parameters
        ----------
        humdir : int or list or tuple
            Direction in any pyoti.sparse format, or a rawdir; 0 or [] selects the real block.

        Returns
        -------
        numpy.ndarray
            Shape (nrows, ncols), sharing native memory; an empty array (not shared) for a zero-size
            matrix.

        Raises
        ------
        KeyError
            The direction is outside the array's active bases (a base above nact, or an order above
            the truncation order).
        """

        cdef tuple pair = _direction(humdir)
        cdef _BlockExport export = _BlockExport(self)
        cdef object view = _soa_block_view(self, pair[0], pair[1], export)

        if view is None and self.arr.size == 0:

            # A zero-size array has no native buffer: the block of a direction inside the layout
            # (order 0, or an index below N_order(nact) at an order up to the truncation order) is empty.
            if pair[1] == 0 or (pair[1] <= self.arr.trc_order and
                                pair[0] < comb(self.arr.nact + pair[1] - 1, pair[1])):

                return np.empty(self.shape, dtype=np.float64)

            # end if

        # end if

        if view is None:

            raise KeyError("direction is not in the array's active set")

        # end if

        _register_block_export(self, export)
        return view

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
        omat
            Independent copy.
        """

        cdef oarr_t result = oarr_init()

        _soa_ok("copy", oarr_copy_to(&self.arr, &result), &result)
        return omat.wrap(result)

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
        rhs : float or otinum or sotinum or array
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
        rhs : omat
            Right factor.
        out : omat, optional
            Holder for the product.

        Returns
        -------
        omat
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
        out : omat, optional
            Holder for the inverse.

        Returns
        -------
        omat
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
        out : omat, optional
            Holder for the transpose.

        Returns
        -------
        omat
            Transposed copy, or None when ``out`` is given.
        """

        return transpose(arr, out)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def __rmatmul__(self, other):
        """
        Multiply a matrix of the other dense layout or a sparse matrix from the left.

        Parameters
        ----------
        other : omat or arro or matso
            Left factor.

        Returns
        -------
        omat or NotImplemented
            Matrix product when supported.
        """

        if isinstance(other, matso):

            other = omat.from_sparse(other)

        elif isinstance(other, (omat, arro)) and not isinstance(other, omat):

            other = other.to_soa()

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
        otinum or omat
            Element copy for two integers, otherwise a new array holding the block.
        """

        return _soa_getitem(self, key)

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
        value : float or otinum or sotinum or array or numpy.ndarray
            Replacement; arrays must have the shape of the selected block.
        """

        _soa_setitem(self, key, value)

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

        return "omat< shape: {}, re:\n{}>".format(self.shape, repr(self.real))

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

        return "omat< shape: {}, order: {}, bases: {}, re:\n{}>".format(
            self.shape, self.order, self.get_active_bases(), repr(self.real))

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def __abs__(self):
        """
        Take the absolute value of every element (negating those with a negative real part).

        Returns
        -------
        omat
            Elementwise absolute value.
        """

        cdef omat result = self.copy()
        cdef np.ndarray blocks

        if self.arr.size > 0:

            blocks = _soa_blocks(result)
            blocks *= np.where(blocks[0] < 0, -1.0, 1.0)

        # end if

        return result

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def __iadd__(self, other):
        """
        Add in the sense of ``+=``; like ``pyoti.sparse`` this binds the sum to the name.

        Parameters
        ----------
        other : omat or otinum or float
            Addend.

        Returns
        -------
        omat or NotImplemented
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
        other : omat or otinum or float
            Subtrahend.

        Returns
        -------
        omat or NotImplemented
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
        other : omat or otinum or float
            Multiplier.

        Returns
        -------
        omat or NotImplemented
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
        other : omat or otinum or float
            Denominator.

        Returns
        -------
        omat or NotImplemented
            Quotient when supported.
        """

        return self.__truediv__(other)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def __repr__(self):
        """
        Describe the matrix shape, active set, and order.

        Returns
        -------
        str
            Array summary.
        """

        return "omat(shape={}, bases={}, order={})".format(
            self.shape, self.active_bases, self.order)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def truncate(self, humdir):
        """
        Zero a direction and its multiples in every matrix entry.

        Parameters
        ----------
        humdir : int or list or tuple
            Direction in any pyoti.sparse format, or a rawdir.

        Returns
        -------
        omat
            Truncated copy.
        """

        cdef tuple pair = _direction(humdir)
        cdef oarr_t result = oarr_init()
        _soa_ok("truncate", oarr_truncate_im_to(pair[0], pair[1], &self.arr, &result), &result)
        return omat.wrap(result)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def truncate_order(self, order):
        """
        Remove this order and above from every matrix entry.

        Parameters
        ----------
        order : int
            First order to remove.

        Returns
        -------
        omat
            Truncated copy.
        """

        cdef oarr_t result = oarr_init()
        _soa_ok("truncate_order", oarr_truncate_order_to(order, &self.arr, &result), &result)
        return omat.wrap(result)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def get_order_im(self, order):
        """
        Keep one coefficient order in every matrix entry.

        Parameters
        ----------
        order : int
            Order to retain.

        Returns
        -------
        omat
            Extracted copy.
        """

        cdef oarr_t result = oarr_init()
        _soa_ok("get_order_im", oarr_get_order_im_to(order, &self.arr, &result), &result)
        return omat.wrap(result)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def compact(self):
        """
        Remove bases whose blocks are zero across the matrix.

        Returns
        -------
        omat
            Compact copy.
        """

        cdef oarr_t result = oarr_init()
        _soa_ok("compact", oarr_compact_to(&self.arr, &result), &result)
        return omat.wrap(result)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def __add__(self, other):
        """
        Add an array or broadcast scalar elementwise.

        Parameters
        ----------
        other : omat or otinum or float
            Addend.

        Returns
        -------
        omat or NotImplemented
            Elementwise sum.
        """

        return _array_binary(self, other, "add", False)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def __radd__(self, other):
        """
        Broadcast-add a scalar on the left.

        Parameters
        ----------
        other : otinum or float
            Left addend.

        Returns
        -------
        omat or NotImplemented
            Elementwise sum.
        """

        return _array_binary(self, other, "add", True)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def __sub__(self, other):
        """
        Subtract an array or broadcast scalar elementwise.

        Parameters
        ----------
        other : omat or otinum or float
            Subtrahend.

        Returns
        -------
        omat or NotImplemented
            Elementwise difference.
        """

        return _array_binary(self, other, "sub", False)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def __rsub__(self, other):
        """
        Subtract this array from a broadcast scalar.

        Parameters
        ----------
        other : otinum or float
            Left operand.

        Returns
        -------
        omat or NotImplemented
            Elementwise difference.
        """

        return _array_binary(self, other, "sub", True)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def __mul__(self, other):
        """
        Multiply an array or broadcast scalar elementwise.

        Parameters
        ----------
        other : omat or otinum or float
            Multiplier.

        Returns
        -------
        omat or NotImplemented
            Elementwise product.
        """

        return _array_binary(self, other, "mul", False)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def __rmul__(self, other):
        """
        Broadcast-multiply a scalar on the left.

        Parameters
        ----------
        other : otinum or float
            Left multiplier.

        Returns
        -------
        omat or NotImplemented
            Elementwise product.
        """

        return _array_binary(self, other, "mul", True)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def __truediv__(self, other):
        """
        Divide by an array or broadcast scalar elementwise.

        Parameters
        ----------
        other : omat or otinum or float
            Denominator.

        Returns
        -------
        omat or NotImplemented
            Elementwise quotient.
        """

        return _array_binary(self, other, "div", False)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def __rtruediv__(self, other):
        """
        Divide a broadcast scalar by this array elementwise.

        Parameters
        ----------
        other : otinum or float
            Numerator.

        Returns
        -------
        omat or NotImplemented
            Elementwise quotient.
        """

        return _array_binary(self, other, "div", True)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def __neg__(self):
        """
        Negate every element.

        Returns
        -------
        omat
            Negated array.
        """

        cdef oarr_t result = oarr_init()
        _soa_ok("neg", oarr_neg_to(&self.arr, &result, _dhl), &result)
        return omat.wrap(result)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def __pow__(self, exponent, modulus=None):
        """
        Raise every element to a real power.

        Parameters
        ----------
        exponent : float
            Real exponent.
        modulus : None
            Modular exponentiation is unsupported.

        Returns
        -------
        omat or NotImplemented
            Elementwise power.
        """

        cdef oarr_t result = oarr_init()

        if modulus is not None or not isinstance(exponent, Real):

            return NotImplemented

        # end if

        _soa_ok("pow", oarr_pow_to(&(<omat>self).arr, exponent, &result, _dhl), &result)
        return omat.wrap(result)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def __matmul__(self, other):
        """
        Perform coefficient-aware matrix multiplication.

        Parameters
        ----------
        other : omat
            Right matrix.

        Returns
        -------
        omat or NotImplemented
            Matrix product.
        """

        cdef oarr_t result = oarr_init()

        if not isinstance(other, omat):

            return NotImplemented

        # end if

        if self.arr.ncols != (<omat>other).arr.nrows:

            raise ValueError("matmul: incompatible matrix dimensions")

        # end if

        _soa_ok("matmul", oarr_matmul_OO_to(&(<omat>self).arr, &(<omat>other).arr, &result, _dhl),
                &result)
        return omat.wrap(result)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def rom_eval(self, bases, deltas):
        """
        Evaluate the Taylor series of every element at real perturbations of the bases.

        Same call as ``matso.rom_eval``; a scalar ``deltas`` (or ``bases=None``) perturbs every
        active base by that value (Phase 2, ``dense/order.pxi``).

        Parameters
        ----------
        bases : sequence of int or None
            Base labels.
        deltas : sequence of float or float
            Perturbation of each base.

        Returns
        -------
        omat
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
        omat
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
        omat
            Extracted array (see ``extract_deriv``).
        """

        return extract_deriv(hum_dir, self)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def list_repr(self):
        """
        Describe the matrix with one line per element, like ``matso.list_repr``.

        Returns
        -------
        str
            Shape and the formatted elements.
        """

        return "omat< shape: {}, \n{}>".format(self.shape, _array_text(self))

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    @staticmethod
    def add(lhs, rhs, out=None):
        """
        Add two matrices elementwise; same as ``lhs + rhs`` (``matso.add``).

        Parameters
        ----------
        lhs : omat
            Left operand.
        rhs : omat
            Right operand.
        out : omat, optional
            Holder for the sum.

        Returns
        -------
        omat
            Sum, or None when ``out`` is given.
        """

        return _finish(lhs + rhs, out)

    # end function
    # ----------------------------------------------------------------------------------------------------

# end class
# --------------------------------------------------------------------------------------------------------
