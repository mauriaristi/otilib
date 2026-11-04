# Semi-sparse structure-of-arrays matrix class (oarrss).


# ********************************************************************************************************
cdef class oarrss:
    """
    Column-major structure-of-arrays semi-sparse OTI array of logical ndim 0, 1 or 2.

    Create with ``zeros``, ``array``, ``from_sparse`` or ``from_real``. Indexing follows NumPy on the
    logical shape (slices are copies until Phase 8). ``.real`` and ``get_block`` are read-only views;
    while one is alive, an operation that would relayout the array raises ``BufferError``.
    """

    # ****************************************************************************************************
    def __cinit__(self):
        """
        Initialize an empty owned C array (logically 2-D until a creator says otherwise).
        """

        self.arr = oarrss_init()
        self._ndim = 2

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def __dealloc__(self):
        """
        Release the array's native buffers.
        """

        oarrss_free(&self.arr)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    @staticmethod
    cdef oarrss wrap(oarrss_t value):
        """
        Transfer ownership of a native SoA array.

        Parameters
        ----------
        value : oarrss_t
            Owned native array.

        Returns
        -------
        oarrss
            Wrapped array.
        """

        cdef oarrss result = oarrss.__new__(oarrss)
        result.arr = value
        return result

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    @classmethod
    def zeros(cls, shape, bases=(), order=0):
        """
        Allocate a zero SoA matrix over a sorted set of global bases.

        Parameters
        ----------
        shape : int or tuple of int
            Logical shape (ndim <= 2).
        bases : iterable of int
            Strictly increasing global basis labels.
        order : int
            Truncation order.

        Returns
        -------
        oarrss
            Zero array.
        """

        cdef list active = _bases(bases)
        cdef np.ndarray[np.uint16_t, ndim=1] labels = np.asarray(active, dtype=np.uint16)
        cdef bases_t *ptr = NULL
        cdef tuple dims = _creator_dims(shape)

        if order < 0 or order > 255:

            raise ValueError("order must be between 0 and 255")

        # end if

        if active:

            ptr = <bases_t *>labels.data

        # end if

        _check_alloc(comb(len(active) + order, order) * dims[1] * dims[2] * 8)
        return _nd(oarrss.wrap(oarrss_zeros(ptr, len(active), dims[1], dims[2], order)), dims[0])

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    @classmethod
    def from_sparse(cls, matso value):
        """
        Convert a sparse OTI matrix into the shared-set SoA layout.

        Parameters
        ----------
        value : matso
            Sparse matrix.

        Returns
        -------
        oarrss
            Semi-sparse array.
        """

        return _nd(oarrss.wrap(oarrss_from_arrso(&value.arr, _dhl)), len(value.shape))

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    @classmethod
    def from_real(cls, value, order=0):
        """
        Copy a real NumPy array (ndim <= 2) into a column-major SoA array of the same shape.

        Parameters
        ----------
        value : array_like
            Real array of ndim 0, 1 or 2.
        order : int
            Truncation order.

        Returns
        -------
        oarrss
            Real-valued semi-sparse array.
        """

        cdef np.ndarray[np.float64_t, ndim=2, mode="fortran"] data
        cdef coeff_t *ptr = NULL
        cdef object source = np.asarray(value, dtype=np.float64)
        cdef int ndim = source.ndim

        if ndim > 2:

            raise ValueError(_RANK_ERROR)

        # end if

        data = np.asfortranarray(source.reshape(source.shape + (1,) * (2 - ndim)))

        if order < 0 or order > 255:

            raise ValueError("order must be between 0 and 255")

        # end if

        if data.size:

            ptr = <coeff_t *>data.data

        # end if

        return _nd(oarrss.wrap(oarrss_from_real(ptr, data.shape[0], data.shape[1], order)), ndim)

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

        cdef arrso_t result = oarrss_to_arrso(&self.arr, _dhl)
        return _sparse_like(matso.create(&result), self._ndim)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def to_aos(self):
        """
        Convert the shared-set SoA matrix to an AoS matrix.

        Returns
        -------
        arrss
            Owned AoS array.
        """

        cdef arrss_t result = arrss_init()
        arrss_from_oarrss(&self.arr, &result)
        return _nd(arrss.wrap(result), self._ndim)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    @property
    def shape(self):
        """
        Return the logical shape (ndim <= 2 until Phase 8).

        Returns
        -------
        tuple
            ``(nrows, ncols)``, ``(n,)`` or ``()``.
        """

        return _lshape(self._ndim, self.arr.nrows, self.arr.ncols)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    @property
    def ndim(self):
        """
        Return the number of logical dimensions.

        Returns
        -------
        int
            0, 1 or 2.
        """

        return self._ndim

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def __len__(self):
        """
        Return the length of the first axis.

        Returns
        -------
        int
            ``shape[0]``.

        Raises
        ------
        TypeError
            For a 0-D array.
        """

        if self._ndim == 0:

            raise TypeError("len() of unsized object")

        # end if

        return self.arr.nrows

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def __iter__(self):
        """
        Iterate over the first axis: rows of a 2-D array, OTI scalars of a 1-D array.

        Returns
        -------
        iterator
            ``A[0], A[1], ...``.

        Raises
        ------
        TypeError
            For a 0-D array.
        """

        if self._ndim == 0:

            raise TypeError("iteration over a 0-d array")

        # end if

        return (self[i] for i in range(self.arr.nrows))

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
        Return the sorted active global basis labels.

        Returns
        -------
        tuple
            Shared basis labels.
        """

        return tuple(self.arr.p_bases[i] for i in range(self.arr.nbases))

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

        return oarrss_density(&self.arr)

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

        return oarrss_memory_size(&self.arr)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    @property
    def T(self):
        """
        Return a transposed copy of every coefficient block (a copy of a 0-D or 1-D array, as NumPy).

        Returns
        -------
        oarrss
            Transposed copy (a view from Phase 8).
        """

        cdef oarrss_t result = oarrss_init()

        if self._ndim < 2:

            return self.copy()

        # end if

        oarrss_transpose_to(&self.arr, &result, _dhl)
        return oarrss.wrap(result)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def get_block(self, humdir, writeable=False):
        """
        Return a read-only (or, on request, writable) Fortran-ordered NumPy view of one direction block.

        The view keeps the array alive and is tracked: while it lives, an operation that would
        relayout the array (new base labels, a higher truncation order) raises ``BufferError``.

        Parameters
        ----------
        humdir : int or list or tuple
            Direction in any pyoti.sparse format, or a rawdir; 0 or [] selects the real block.
        writeable : bool, optional
            Return a writable view. For an imaginary direction the active order is raised to the
            truncation order first, so values written there are never ignored.

        Returns
        -------
        numpy.ndarray
            The array's logical shape, sharing native memory; an empty array (not shared) for a
            zero-size array.

        Raises
        ------
        KeyError
            The direction is outside the array's active set.
        """

        cdef tuple pair = _direction(humdir)
        cdef coeff_t *block = oarrss_get_block(pair[0], pair[1], &self.arr)
        cdef ndir_t local

        if block == NULL and self.arr.size == 0:

            # A zero-size array has no native buffer: the block of a direction in the set is empty.
            if pair[1] == 0 or (pair[1] <= self.arr.trc_order and sshelp_global_to_local(
                    pair[0], pair[1], self.arr.p_bases, self.arr.nbases, &local) == 1):

                return _export_view(self, NULL, 0, self.shape, writeable)

            # end if

        # end if

        if block == NULL:

            raise KeyError("direction is not in the array's active set")

        # end if

        if writeable and pair[1] > 0:

            self.arr.act_order = self.arr.trc_order

        # end if

        return _export_view(self, block, self.arr.size, self.shape, writeable)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # Make NumPy defer to the reflected operators of this class instead of broadcasting over it.
    __array_ufunc__ = None

    # ****************************************************************************************************
    @property
    def nrows(self):
        """
        Return the number of rows of the 2-D C struct (deprecated in 2.0.0: use ``shape``).

        Returns
        -------
        int
            Row count (1-D: n; 0-D: 1).
        """

        _warn_nrows("nrows")
        return self.arr.nrows

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    @property
    def ncols(self):
        """
        Return the number of columns of the 2-D C struct (deprecated in 2.0.0: use ``shape``).

        Returns
        -------
        int
            Column count (1-D and 0-D: 1).
        """

        _warn_nrows("ncols")
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
        Return the real parts as a read-only view (tracked like ``get_block(0)``).

        Returns
        -------
        numpy.ndarray
            Real coefficients, of the array's logical shape; ``.real.copy()`` is writable.
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
        oarrss
            Independent copy.
        """

        return _nd(oarrss.wrap(oarrss_copy(&self.arr)), self._ndim)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def reshape(self, *shape, order='C'):
        """
        Return a copy with a new logical shape (C order, as NumPy's default; ndim <= 2).

        Parameters
        ----------
        *shape : int or tuple of int
            New shape; one extent may be -1.
        order : str, optional
            Only ``'C'`` (NumPy's row-major order), as ``matso.reshape``.

        Returns
        -------
        oarrss
            Reshaped copy.
        """

        cdef object target = shape[0] if len(shape) == 1 and not isinstance(
            shape[0], (int, np.integer)) else shape
        cdef tuple dims
        cdef object order_map
        cdef oarrss result

        if order != 'C':

            raise ValueError("reshape: only order='C' is supported")

        # end if

        target = np.empty(self.shape, dtype=np.int8).reshape(target).shape
        dims = _creator_dims(target)
        result = oarrss.wrap(oarrss_zeros(self.arr.p_bases, self.arr.nbases, dims[1], dims[2],
                                          self.arr.trc_order))
        result.arr.act_order = self.arr.act_order

        if self.arr.size > 0:

            # Position of every source element (in row-major order) in the column-major blocks.
            order_map = np.arange(self.arr.size).reshape(
                (self.arr.ncols, self.arr.nrows)).T.reshape(-1)
            _soa_blocks(result)[:, np.arange(result.arr.size).reshape(
                (result.arr.ncols, result.arr.nrows)).T.reshape(-1)] = _soa_blocks(self)[:, order_map]

        # end if

        return _nd(result, dims[0])

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def reserve(self, bases=None, order=None):
        """
        Grow the layout now (labels and truncation order) so later assignments never relayout (G4).

        Parameters
        ----------
        bases : iterable of int, optional
            Labels to add to the active set.
        order : int, optional
            Truncation order to raise to.

        Raises
        ------
        BufferError
            The layout must change and a ``.real`` / ``get_block`` view is alive.
        """

        cdef list active = _bases(sorted(set(bases))) if bases is not None else []
        cdef np.ndarray[np.uint16_t, ndim=1] labels = np.asarray(active, dtype=np.uint16)
        cdef ord_t top = self.arr.trc_order
        cdef bases_t *ptr = <bases_t *>labels.data if active else NULL

        if order is not None:

            if order < 0 or order > 255:

                raise ValueError("order must be between 0 and 255")

            # end if

            top = order if order > top else top

        # end if

        _check_ss_growth(self, ptr, len(active), top)
        _check_alloc(comb(len(set(active).union(self.active_bases)) + top, top) * self.arr.size * 8)
        _raise_soa_order(self, top)

        if active:

            oarrss_add_bases(ptr, len(active), &self.arr)

        # end if

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
        rhs : oarrss
            Right factor.
        out : oarrss, optional
            Holder for the product.

        Returns
        -------
        oarrss
            Product; ``out`` itself when it is given.
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
        out : oarrss, optional
            Holder for the inverse.

        Returns
        -------
        oarrss
            Inverse; ``out`` itself when it is given.
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
        out : oarrss, optional
            Holder for the transpose.

        Returns
        -------
        oarrss
            Transposed copy; ``out`` itself when it is given.
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
        oarrss or NotImplemented
            Matrix product when supported.
        """

        if isinstance(other, matso):

            other = oarrss.from_sparse(other)

        elif isinstance(other, (oarrss, arrss)) and not isinstance(other, oarrss):

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
        Read an element or a block with NumPy's basic indexing on the logical shape (7b).

        An integer drops its axis (``A[i]`` of a matrix is 1-D), a slice keeps it, one ``...``
        expands, negative integers count from the end; one integer per axis gives an OTI scalar.
        ``None`` raises ``ValueError`` (at most 2 dimensions until Phase 8).

        Parameters
        ----------
        key : int or slice or Ellipsis or tuple
            Basic key.

        Returns
        -------
        ssotinum or oarrss
            Element copy for one integer per axis, otherwise a new array holding the selection
            (a copy).
        """

        return _soa_getitem(self, key)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def __setitem__(self, key, value):
        """
        Assign an element or a block with NumPy's rules (S1 broadcasting, S2 snapshot; 7b).

        The truncation order rises to the value's when it is larger (existing entries are
        zero-extended), and the active set grows to hold the value's bases, unless a ``.real`` or
        ``get_block`` view is alive: then a growth raises ``BufferError`` (G1).

        Parameters
        ----------
        key : int or slice or Ellipsis or tuple
            Basic key.
        value : float or ssotinum or sotinum or array or numpy.ndarray
            Replacement, broadcast to the selection as NumPy does (an ``(n, 1)`` column does not fit
            an ``(n,)`` target).
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

        return "oarrss< shape: {}, re:\n{}>".format(self.shape, repr(self.real))

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

        return "oarrss< shape: {}, order: {}, bases: {}, re:\n{}>".format(
            self.shape, self.order, self.get_active_bases(), repr(self.real))

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def __abs__(self):
        """
        Take the absolute value of every element (negating those with a negative real part).

        Returns
        -------
        oarrss
            Elementwise absolute value.
        """

        cdef oarrss result = _nd(oarrss.wrap(oarrss_copy(&self.arr)), self._ndim)
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
        other : oarrss or ssotinum or float
            Addend.

        Returns
        -------
        oarrss or NotImplemented
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
        other : oarrss or ssotinum or float
            Subtrahend.

        Returns
        -------
        oarrss or NotImplemented
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
        other : oarrss or ssotinum or float
            Multiplier.

        Returns
        -------
        oarrss or NotImplemented
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
        other : oarrss or ssotinum or float
            Denominator.

        Returns
        -------
        oarrss or NotImplemented
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

        return "oarrss(shape={}, bases={}, order={})".format(
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
        oarrss
            Truncated copy.
        """

        cdef tuple pair = _direction(humdir)
        cdef oarrss_t result = oarrss_init()
        oarrss_truncate_im_to(pair[0], pair[1], &self.arr, &result)
        return _nd(oarrss.wrap(result), self._ndim)

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
        oarrss
            Truncated copy.
        """

        cdef oarrss_t result = oarrss_init()
        oarrss_truncate_order_to(order, &self.arr, &result)
        return _nd(oarrss.wrap(result), self._ndim)

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
        oarrss
            Extracted copy.
        """

        cdef oarrss_t result = oarrss_init()
        oarrss_get_order_im_to(order, &self.arr, &result)
        return _nd(oarrss.wrap(result), self._ndim)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def compact(self):
        """
        Remove bases whose blocks are zero across the matrix.

        Returns
        -------
        oarrss
            Compact copy.
        """

        cdef oarrss_t result = oarrss_init()
        oarrss_compact_to(&self.arr, &result)
        return _nd(oarrss.wrap(result), self._ndim)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def __add__(self, other):
        """
        Add an array or broadcast scalar elementwise.

        Parameters
        ----------
        other : oarrss or ssotinum or float
            Addend.

        Returns
        -------
        oarrss or NotImplemented
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
        other : ssotinum or float
            Left addend.

        Returns
        -------
        oarrss or NotImplemented
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
        other : oarrss or ssotinum or float
            Subtrahend.

        Returns
        -------
        oarrss or NotImplemented
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
        other : ssotinum or float
            Left operand.

        Returns
        -------
        oarrss or NotImplemented
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
        other : oarrss or ssotinum or float
            Multiplier.

        Returns
        -------
        oarrss or NotImplemented
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
        other : ssotinum or float
            Left multiplier.

        Returns
        -------
        oarrss or NotImplemented
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
        other : oarrss or ssotinum or float
            Denominator.

        Returns
        -------
        oarrss or NotImplemented
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
        other : ssotinum or float
            Numerator.

        Returns
        -------
        oarrss or NotImplemented
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
        oarrss
            Negated array.
        """

        cdef oarrss_t result = oarrss_init()
        oarrss_neg_to(&self.arr, &result, _dhl)
        return _nd(oarrss.wrap(result), self._ndim)

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
        oarrss or NotImplemented
            Elementwise power.
        """

        cdef oarrss_t result = oarrss_init()

        if modulus is not None or not isinstance(exponent, Real):

            return NotImplemented

        # end if

        oarrss_pow_to(&(<oarrss>self).arr, exponent, &result, _dhl)
        return _nd(oarrss.wrap(result), self._ndim)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def __matmul__(self, other):
        """
        Perform coefficient-aware matrix multiplication with ``numpy.matmul``'s 1-D rules (I3).

        A 1-D left operand acts as a row and a 1-D right operand as a column; the promoted axis is
        removed, so ``x @ y`` of two vectors is an OTI scalar.

        Parameters
        ----------
        other : oarrss
            Right factor.

        Returns
        -------
        oarrss or ssotinum or NotImplemented
            Product.
        """

        if not isinstance(other, oarrss):

            return NotImplemented

        # end if

        return _soa_matmul(self, other)

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
        oarrss
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
        oarrss
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
        oarrss
            Extracted array (see ``extract_deriv``).
        """

        return extract_deriv(hum_dir, self)

    # end function
    # ----------------------------------------------------------------------------------------------------

# end class
# --------------------------------------------------------------------------------------------------------
