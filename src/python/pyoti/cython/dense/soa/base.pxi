# Dense structure-of-arrays matrix class (omat).

cimport cython


# ********************************************************************************************************
# Freelist (critic W3 finding 1): the object embeds a 560-byte struct, above CPython's 512-byte small-
# object limit, so freed objects are recycled instead of going back to malloc (exact type only).
@cython.freelist(32)
cdef class omat:
    """
    Dense OTI array of any shape, structure of arrays (one block per direction, column-major inside a
    block by default).

    Indexing follows NumPy (PLAN-ndarray-contracts.md 11.3): one integer per axis gives an OTI scalar,
    basic keys and ``.T`` / ``reshape`` give views that share this array's memory and layout, advanced
    keys give copies. ``.real`` and ``get_block`` are read-only NumPy views. While a view or an export
    lives, the layout (truncation order, active bases) of the array is fixed: an assignment that would
    grow it raises BufferError (size it first with ``reserve`` or ``nbases=`` / ``order=``).
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
        Allocate a zero SoA array over the bases 1..max(bases).

        Parameters
        ----------
        shape : int or tuple of int
            Shape (NumPy rules: an int is a 1-D shape).
        bases : iterable of int
            Basis labels; the array is dense over 1..max(bases) (nact 0 when empty).
        order : int
            Truncation order, between 0 and 150.

        Returns
        -------
        omat
            Zero array.

        Raises
        ------
        ValueError
            If the shape or the order is invalid.
        MemoryError
            If the array is too large.
        """

        _check_order(order)
        return _soa_zeros_nd(_shape_of(shape), _nact_of(bases), order)

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
        Return the shape.

        Returns
        -------
        tuple of int
            Extents of the axes.
        """

        return tuple([oarr_shape(&self.arr, d) for d in range(oarr_ndim(&self.arr))])

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    @property
    def ndim(self):
        """
        Return the number of axes.

        Returns
        -------
        int
            ``len(self.shape)``.
        """

        return oarr_ndim(&self.arr)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def __len__(self):
        """
        Return the extent of the first axis (contracts 11.3 I2).

        Returns
        -------
        int
            ``self.shape[0]``.

        Raises
        ------
        TypeError
            For a 0-D array.
        """

        if oarr_ndim(&self.arr) == 0:

            raise TypeError("len() of unsized object")

        # end if

        return oarr_shape(&self.arr, 0)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def __iter__(self):
        """
        Iterate over the first axis: views with one axis fewer, OTI scalars for a 1-D array.

        Returns
        -------
        iterator
            ``self[0], self[1], ...``.

        Raises
        ------
        TypeError
            For a 0-D array.
        """

        if oarr_ndim(&self.arr) == 0:

            raise TypeError("iteration over a 0-d array")

        # end if

        return _soa_iter(self)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def reshape(self, *shape, order="C"):
        """
        Give a new shape: a view sharing this array's memory when the strides allow it, else a copy.

        Parameters
        ----------
        *shape : int or tuple of int
            New shape (one -1 allowed), as one tuple or as separate integers.
        order : str
            Index order, ``'C'`` (default, NumPy's) or ``'F'``.

        Returns
        -------
        omat
            View or copy.
        """

        return _soa_reshape(self, shape[0] if len(shape) == 1 else shape, order)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def reserve(self, nbases=None, order=None):
        """
        Grow the layout now, so that later assignments of values over nbases bases up to this order
        never grow it (contracts 11.6 G4); the elements are zero-extended.

        Parameters
        ----------
        nbases : int, optional
            Number of active bases to hold (the array becomes dense over 1..nbases at least).
        order : int, optional
            Truncation order to hold.

        Raises
        ------
        BufferError
            When the layout must grow while views or exports of the array are alive.
        """

        cdef bases_t k = oarr_nact(&self.arr)
        cdef ord_t trc = oarr_trc_order(&self.arr)

        if nbases is not None:

            if nbases < 0:

                raise ValueError("nbases must be nonnegative")

            # end if

            k = max(k, nbases)

        # end if

        if order is not None:

            _check_order(order)
            trc = max(trc, order)

        # end if

        _status("reserve", oarr_grow_layout(&self.arr, k, trc))

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

        return oarr_trc_order(&self.arr)

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

        return tuple(range(1, oarr_nact(&self.arr) + 1))

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

        return oarr_nact(&self.arr)

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
        Return the transpose as a view (the axes reversed; a 1-D array is unchanged), as NumPy does.

        Returns
        -------
        omat
            View sharing this array's memory.
        """

        cdef omat result = omat.__new__(omat)

        _soa_ok("transpose", oarr_view_transpose(&self.arr, 0, NULL, &result.arr), &result.arr)
        return result

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def get_block(self, humdir, writeable=False):
        """
        Return one direction block as a NumPy view of the array's memory (contracts 11.11).

        The view is read-only by default. It pins the array's layout while it lives: an operation that
        would grow the array (truncation order, active bases) raises BufferError. With
        ``writeable=True`` the view is writable and its writes reach the array; for an imaginary
        direction the array's active order first rises to its truncation order (contracts 7.4).

        Parameters
        ----------
        humdir : int or list or tuple
            Direction in any pyoti.sparse format, or a rawdir; 0 or [] selects the real block.
        writeable : bool
            Return a writable view.

        Returns
        -------
        numpy.ndarray
            The block, of the array's shape and strides.

        Raises
        ------
        KeyError
            The direction is outside the array's active bases (a base above nact, or an order above
            the truncation order).
        """

        cdef tuple pair = _direction(humdir)
        cdef uint64_t index = pair[0]
        cdef ord_t order = pair[1]

        if order > oarr_trc_order(&self.arr) or (
            order > 0 and index >= <uint64_t>comb(oarr_nact(&self.arr) + order - 1, order)
        ):

            raise KeyError("direction is not in the array's active set")

        # end if

        if writeable and order > 0:

            oarr_raise_act(&self.arr, oarr_trc_order(&self.arr))

        # end if

        return _soa_export(self, oarr_block_index(oarr_nact(&self.arr), order, index), writeable)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # Make NumPy defer to the reflected operators of this class instead of broadcasting over it.
    __array_ufunc__ = None

    # ****************************************************************************************************
    @property
    def nrows(self):
        """
        Return the number of rows (deprecated in 2.0.0: use ``shape``).

        Returns
        -------
        int
            ``shape[0]`` for a 2-D array, ``n`` for a 1-D array, 1 for a 0-D array.

        Raises
        ------
        AttributeError
            For an array of more than two dimensions.
        """

        return _deprecated_dim(self.shape, 0)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    @property
    def ncols(self):
        """
        Return the number of columns (deprecated in 2.0.0: use ``shape``).

        Returns
        -------
        int
            ``shape[1]`` for a 2-D array, 1 for a 1-D or 0-D array.

        Raises
        ------
        AttributeError
            For an array of more than two dimensions.
        """

        return _deprecated_dim(self.shape, 1)

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
            Product of the extents.
        """

        return oarr_size(&self.arr)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    @property
    def real(self):
        """
        Return the real parts as a read-only NumPy view of the array's memory (contracts 11.11).

        Returns
        -------
        numpy.ndarray
            Real coefficients, of the array's shape; ``.copy()`` gives a writable copy.
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

        cdef omat result = omat.__new__(omat)

        _soa_ok("copy", oarr_copy_to(&self.arr, &result.arr), &result.arr)
        return result

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
            New value; the truncation order rises to the value's when it is larger (contracts 11.6 G1:
            BufferError while views or exports of the array are alive).
        """

        self[...] = rhs

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
            Product (``out`` itself when it is given).
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
            Inverse (``out`` itself when it is given).
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
            Transposed copy (``out`` itself when it is given).
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

        if oarr_size(&self.arr) > 0:

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
        cdef omat result = omat.__new__(omat)
        _soa_ok("truncate", oarr_truncate_im_to(pair[0], pair[1], &self.arr, &result.arr), &result.arr)
        return result

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

        cdef omat result = omat.__new__(omat)
        _soa_ok("truncate_order", oarr_truncate_order_to(order, &self.arr, &result.arr), &result.arr)
        return result

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

        cdef omat result = omat.__new__(omat)
        _soa_ok("get_order_im", oarr_get_order_im_to(order, &self.arr, &result.arr), &result.arr)
        return result

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

        cdef omat result = omat.__new__(omat)
        _soa_ok("compact", oarr_compact_to(&self.arr, &result.arr), &result.arr)
        return result

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

        cdef omat result = omat.__new__(omat)
        _soa_ok("neg", oarr_neg_to(&self.arr, &result.arr, _dhl), &result.arr)
        return result

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

        cdef omat result

        if modulus is not None or not isinstance(exponent, Real):

            return NotImplemented

        # end if

        result = omat.__new__(omat)
        _soa_ok("pow", oarr_pow_to(&(<omat>self).arr, exponent, &result.arr, _dhl), &result.arr)
        return result

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def __matmul__(self, other):
        """
        Matrix product with numpy.matmul's rules (contracts 11.3 I3): 1-D operands are promoted and
        the promoted axis is removed; batch axes broadcast.

        Parameters
        ----------
        other : omat
            Right operand.

        Returns
        -------
        omat or otinum or NotImplemented
            The product (an OTI scalar for two 1-D operands).
        """

        if not isinstance(other, omat):

            return NotImplemented

        # end if

        return _soa_matmul(self, <omat>other, False)

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
            Sum (``out`` itself when it is given).
        """

        return _finish(lhs + rhs, out)

    # end function
    # ----------------------------------------------------------------------------------------------------

# end class
# --------------------------------------------------------------------------------------------------------
