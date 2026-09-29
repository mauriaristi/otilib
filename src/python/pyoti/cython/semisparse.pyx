# cython: language_level=3
# cython: c_api_binop_methods=False
"""
Bind semi-sparse scalars and array-of-structures / structure-of-arrays matrices to Python.

All C values returned here are owned by their Python wrappers.
"""

import numpy as np
cimport numpy as np
from libc.stdint cimport uint64_t
from pyoti.c_otilib cimport *
from pyoti.core cimport dHelp, get_cython_dHelp
from pyoti.core import expand_imdir as _expand_direction
from pyoti.sparse cimport sotinum, matso
from numbers import Real
from math import comb
from time import perf_counter as _perf_counter


cdef dHelp _helper = get_cython_dHelp()
cdef dhelpl_t _dhl = _helper.dhl


# ********************************************************************************************************
def _unrank(index, order):
    """
    Return the sorted global base labels of a global direction (index, order).

    Inverse of the colex rank sum(comb(label - 1 + i, i + 1)). It does not read the dhelp tables,
    so it covers every label.

    Parameters
    ----------
    index : int
        Global direction index within its order.
    order : int
        Direction order.

    Returns
    -------
    list of int
        Nondecreasing labels, one per unit of order.

    Examples
    --------
    >>> _unrank(11, 2)
    [2, 5]
    """

    labels = [0] * order
    rest = index

    for i in range(order - 1, -1, -1):

        # Largest c with comb(c, i + 1) <= rest; comb(c, m) >= c - m + 1 bounds c by rest + i.
        low, high = i, i + rest

        while low < high:

            mid = (low + high + 1) // 2

            if comb(mid, i + 1) <= rest:

                low = mid

            else:

                high = mid - 1

            # end if

        # end while

        rest -= comb(low, i + 1)
        labels[i] = low - i + 1

    # end for

    return labels

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
class rawdir:
    """
    A direction given by its raw global (index, order) pair.

    Every function of this module that takes a direction also accepts a ``rawdir``. Use it when
    the index comes from C, from ``pyoti.core.imdir`` or from another numbering step. A plain
    list or tuple always means a list of bases, as in ``pyoti.sparse``, so ``(4, 2)`` is
    ``e([2, 4])`` while ``rawdir(4, 2)`` is the order-2 direction with global index 4, ``e([2, 3])``.

    Parameters
    ----------
    index : int
        Global direction index within its order (the numbering of ``sotinum`` and ``ssotinum``).
    order : int
        Direction order, 0 to 255. Order 0 is the real part and needs index 0.

    Examples
    --------
    >>> d = rawdir(4, 2)
    >>> d.bases
    (2, 3)
    >>> rawdir.from_direction([2, 3]) == d
    True
    """

    __slots__ = ("_index", "_order")

    # ****************************************************************************************************
    def __init__(self, index, order):
        """
        Validate and store the pair.

        Parameters
        ----------
        index : int
            Global direction index within its order.
        order : int
            Direction order.
        """

        if not isinstance(index, (int, np.integer)) or not isinstance(order, (int, np.integer)):

            raise TypeError("rawdir index and order must be integers")

        # end if

        index, order = int(index), int(order)

        if not 0 <= order <= 255:

            raise ValueError("rawdir order must be between 0 and 255")

        # end if

        if not 0 <= index <= 2**64 - 1 or (order == 0 and index != 0):

            raise ValueError("rawdir index out of range for its order")

        # end if

        if order > 0 and _unrank(index, order)[-1] > 65535:

            raise ValueError("rawdir index needs a base label above 65535")

        # end if

        self._index = index
        self._order = order

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    @classmethod
    def from_direction(cls, direction):
        """
        Build the raw pair of a direction written in any pyoti.sparse format.

        Parameters
        ----------
        direction : int or list or tuple
            Direction in any pyoti.sparse format, or a rawdir.

        Returns
        -------
        rawdir
            The same direction as a raw pair.

        Examples
        --------
        >>> rawdir.from_direction([[1, 2]])
        rawdir(0, 2)
        """

        return cls(*_direction(direction))

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    @property
    def index(self):
        """
        Return the global direction index.

        Returns
        -------
        int
            Index within the direction's order.

        Examples
        --------
        >>> rawdir(4, 2).index
        4
        """

        return self._index

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    @property
    def order(self):
        """
        Return the direction order.

        Returns
        -------
        int
            Order.

        Examples
        --------
        >>> rawdir(4, 2).order
        2
        """

        return self._order

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    @property
    def bases(self):
        """
        Return the sorted base labels of the direction.

        Returns
        -------
        tuple of int
            One label per unit of order; empty for the real part.

        Examples
        --------
        >>> rawdir(0, 2).bases
        (1, 1)
        """

        return tuple(_unrank(self._index, self._order))

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def __eq__(self, other):
        """
        Compare two raw directions.

        Parameters
        ----------
        other : object
            Object to compare.

        Returns
        -------
        bool
            True when both index and order match.

        Examples
        --------
        >>> rawdir(1, 2) == rawdir(1, 2)
        True
        """

        if not isinstance(other, rawdir):

            return NotImplemented

        # end if

        return self._index == other._index and self._order == other._order

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def __hash__(self):
        """
        Hash the pair.

        Returns
        -------
        int
            Hash of (index, order).

        Examples
        --------
        >>> hash(rawdir(1, 2)) == hash((1, 2))
        True
        """

        return hash((self._index, self._order))

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def __repr__(self):
        """
        Show the pair.

        Returns
        -------
        str
            For example ``rawdir(4, 2)``.

        Examples
        --------
        >>> rawdir(4, 2)
        rawdir(4, 2)
        """

        return f"rawdir({self._index}, {self._order})"

    # end function
    # ----------------------------------------------------------------------------------------------------

# end class
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef tuple _direction(object direction):
    """
    Resolve a human direction exactly as pyoti.sparse does (a tuple is a list of bases), or a rawdir.

    Parameters
    ----------
    direction : object
        Base label, list or tuple of bases (including exponent pairs such as [[1, 2]]), or a
        rawdir holding a raw (index, order) pair.

    Returns
    -------
    tuple
        Global direction index and order.
    """

    cdef object pair
    cdef list expanded

    # A raw (index, order) pair was validated when the rawdir was built.
    if isinstance(direction, rawdir):

        return direction.index, direction.order

    # end if

    expanded = _expand_direction(direction)

    if len(expanded) > 255 or any(base < 1 or base > 65535 for base in expanded):

        raise ValueError("direction order or basis label out of range")

    # end if

    pair = (sum(comb(base - 1 + i, i + 1) for i, base in enumerate(expanded)), len(expanded))

    if not (0 <= pair[0] <= 2**64 - 1):

        raise ValueError("direction index out of range")

    # end if

    return int(pair[0]), int(pair[1])

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef list _bases(object bases):
    """
    Validate sorted active base labels without silently changing their order.

    Parameters
    ----------
    bases : object
        Iterable of distinct one-based global base labels.

    Returns
    -------
    list
        Validated labels.
    """

    cdef list labels = list(bases)

    if len(labels) > 65535 or any(not isinstance(x, int) or x < 1 or x > 65535
                                 for x in labels):

        raise ValueError("bases must contain labels from 1 through 65535")

    # end if

    if labels != sorted(set(labels)):

        raise ValueError("bases must be strictly increasing and unique")

    # end if

    return labels

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef void _status(str operation, int status) except *:
    """
    Translate native linear algebra statuses into Python exceptions.

    Parameters
    ----------
    operation : str
        Name of the failing operation.
    status : int
        Native LAPACK or OTI error code.
    """

    if status == 0:

        return

    elif status > 0:

        raise np.linalg.LinAlgError("{}: singular real part at pivot {}".format(
            operation, status))

    elif status == OTI_LINALG_ERR_SIZE:

        raise ValueError("{}: incompatible shape or LAPACK dimension overflow".format(operation))

    elif status == OTI_LINALG_ERR_MEMORY:

        raise MemoryError("{}: allocation failed".format(operation))

    elif status == OTI_LINALG_ERR_PIVOT:

        raise ValueError("{}: invalid pivot index".format(operation))

    # end if

    raise RuntimeError("{}: native status {}".format(operation, status))

# end function
# --------------------------------------------------------------------------------------------------------


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
    def get_im(self, direction):
        """
        Read a coefficient using a human or global-index direction.

        Parameters
        ----------
        direction : int or list or tuple
            Direction in any pyoti.sparse format, or a rawdir.

        Returns
        -------
        float
            Coefficient value.
        """

        cdef tuple pair = _direction(direction)
        return ssoti_get_item(pair[0], pair[1], &self.num)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def get_deriv(self, direction):
        """
        Read the derivative along a direction.

        Parameters
        ----------
        direction : int or list or tuple
            Direction in any pyoti.sparse format, or a rawdir.

        Returns
        -------
        float
            Derivative value.
        """

        cdef tuple pair = _direction(direction)
        return ssoti_get_deriv(pair[0], pair[1], &self.num)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def set_im(self, value, direction):
        """
        Set a coefficient and grow the active set when necessary.

        Parameters
        ----------
        value : float
            New coefficient.
        direction : int or list or tuple
            Direction in any pyoti.sparse format, or a rawdir.
        """

        cdef tuple pair = _direction(direction)
        ssoti_set_item(value, pair[0], pair[1], &self.num)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def truncate(self, direction):
        """
        Zero a direction and every higher direction containing it.

        Parameters
        ----------
        direction : int or list or tuple
            Direction in any pyoti.sparse format, or a rawdir.

        Returns
        -------
        ssotinum
            Truncated copy.
        """

        cdef tuple pair = _direction(direction)
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

    # ****************************************************************************************************
    def __repr__(self):
        """
        Format the scalar through its public sparse representation.

        Returns
        -------
        str
            Scalar value and active set.
        """

        return "ssotinum({}, bases={})".format(self.to_sparse(), self.active_bases)

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

        return str(self.to_sparse())

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

        if isinstance(other, (ssotinum, sotinum, Real)):

            return ssotinum(other, order=self.order).__truediv__(self)

        # end if

        return NotImplemented

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def __pow__(self, exponent, modulus=None):
        """
        Raise the scalar to a real power.

        Parameters
        ----------
        exponent : float
            Real exponent.
        modulus : None
            Modular exponentiation is unsupported.

        Returns
        -------
        ssotinum or NotImplemented
            Power when supported.
        """

        if modulus is not None or not isinstance(exponent, Real):

            return NotImplemented

        # end if

        return ssotinum.wrap(ssoti_pow(&(<ssotinum>self).num, exponent, _dhl))

    # end function
    # ----------------------------------------------------------------------------------------------------

# end class
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef class oarrss:
    """
    Column-major structure-of-arrays semi-sparse OTI matrix.

    Create with ``zeros``, ``from_sparse`` or ``from_real``. Views returned by ``get_block``
    retain this array, but must not be used after an operation that grows its active set.
    """

    # ****************************************************************************************************
    def __cinit__(self):
        """
        Initialize an empty owned C array.
        """

        self.arr = oarrss_init()

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
        shape : tuple of int
            Matrix rows and columns.
        bases : iterable of int
            Strictly increasing global basis labels.
        order : int
            Truncation order.

        Returns
        -------
        oarrss
            Zero matrix.
        """

        cdef list active = _bases(bases)
        cdef np.ndarray[np.uint16_t, ndim=1] labels = np.asarray(active, dtype=np.uint16)
        cdef bases_t *ptr = NULL

        if len(shape) != 2 or any(not isinstance(x, int) or x < 0 for x in shape):

            raise ValueError("shape must be (nonnegative rows, nonnegative columns)")

        # end if

        if order < 0 or order > 255:

            raise ValueError("order must be between 0 and 255")

        # end if

        if active:

            ptr = <bases_t *>labels.data

        # end if

        return oarrss.wrap(oarrss_zeros(ptr, len(active), shape[0], shape[1], order))

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

        return oarrss.wrap(oarrss_from_arrso(&value.arr, _dhl))

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
            Truncation order.

        Returns
        -------
        oarrss
            Real-valued semi-sparse matrix.
        """

        cdef np.ndarray[np.float64_t, ndim=2, mode="fortran"] data
        cdef coeff_t *ptr = NULL
        data = np.asfortranarray(value, dtype=np.float64)

        if data.ndim != 2:

            raise ValueError("expected a two-dimensional real matrix")

        # end if

        if order < 0 or order > 255:

            raise ValueError("order must be between 0 and 255")

        # end if

        if data.size:

            ptr = <coeff_t *>data.data

        # end if

        return oarrss.wrap(oarrss_from_real(ptr, data.shape[0], data.shape[1], order))

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
        return matso.create(&result)

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
        return arrss.wrap(result)

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
        Return a transposed copy of every coefficient block.

        Returns
        -------
        oarrss
            Transposed matrix.
        """

        cdef oarrss_t result = oarrss_init()
        oarrss_transpose_to(&self.arr, &result, _dhl)
        return oarrss.wrap(result)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def get_block(self, direction):
        """
        Return a writable Fortran-ordered NumPy view of one direction block.

        The view keeps the array alive. Changing the active set or shape afterwards may
        reallocate the native buffer and invalidates outstanding views.

        Parameters
        ----------
        direction : int or list or tuple
            Direction in any pyoti.sparse format, or a rawdir; 0 or [] selects the real block.

        Returns
        -------
        numpy.ndarray
            Shape (nrows, ncols), sharing native memory.
        """

        cdef tuple pair = _direction(direction)
        cdef coeff_t *block = oarrss_get_block(pair[0], pair[1], &self.arr)
        cdef np.npy_intp dims[1]
        cdef np.ndarray flat

        if block == NULL:

            raise KeyError("direction is not in the array's active set")

        # end if

        dims[0] = self.arr.size
        flat = np.PyArray_SimpleNewFromData(1, dims, np.NPY_DOUBLE, <void *>block)
        np.set_array_base(flat, self)
        return flat.reshape(self.shape, order="F")

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def __getitem__(self, key):
        """
        Return an independently owned semi-sparse scalar at a matrix position.

        Parameters
        ----------
        key : tuple of int
            Row and column indices.

        Returns
        -------
        ssotinum
            Element copy.
        """

        cdef tuple indices = _indices(key, self.arr.nrows, self.arr.ncols)
        return ssotinum.wrap(oarrss_get_item(indices[0], indices[1], &self.arr))

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def __setitem__(self, key, value):
        """
        Set a matrix element from a real or OTI scalar.

        Parameters
        ----------
        key : tuple of int
            Row and column indices.
        value : float or ssotinum or sotinum
            Replacement value.
        """

        cdef tuple indices = _indices(key, self.arr.nrows, self.arr.ncols)
        cdef ssotinum number

        if isinstance(value, Real):

            oarrss_set_item_r(value, indices[0], indices[1], &self.arr)

        elif isinstance(value, (ssotinum, sotinum)):

            number = value if isinstance(value, ssotinum) else ssotinum(value)
            oarrss_set_item(&number.num, indices[0], indices[1], &self.arr)

        else:

            raise TypeError("expected a real or sparse/semi-sparse OTI scalar")

        # end if

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
    def truncate(self, direction):
        """
        Zero a direction and its multiples in every matrix entry.

        Parameters
        ----------
        direction : int or list or tuple
            Direction in any pyoti.sparse format, or a rawdir.

        Returns
        -------
        oarrss
            Truncated copy.
        """

        cdef tuple pair = _direction(direction)
        cdef oarrss_t result = oarrss_init()
        oarrss_truncate_im_to(pair[0], pair[1], &self.arr, &result)
        return oarrss.wrap(result)

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
        return oarrss.wrap(result)

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
        return oarrss.wrap(result)

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
        return oarrss.wrap(result)

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
        return oarrss.wrap(result)

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
        return oarrss.wrap(result)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def __matmul__(self, other):
        """
        Perform coefficient-aware matrix multiplication.

        Parameters
        ----------
        other : oarrss
            Right matrix.

        Returns
        -------
        oarrss or NotImplemented
            Matrix product.
        """

        cdef oarrss_t result = oarrss_init()

        if not isinstance(other, oarrss):

            return NotImplemented

        # end if

        if self.arr.ncols != (<oarrss>other).arr.nrows:

            raise ValueError("matmul: incompatible matrix dimensions")

        # end if

        cdef int status = oarrss_matmul_OO_to(&(<oarrss>self).arr, &(<oarrss>other).arr,
                                               &result, _dhl)

        if status != 0:

            oarrss_free(&result)
            _status("matmul", status)

        # end if

        return oarrss.wrap(result)

    # end function
    # ----------------------------------------------------------------------------------------------------

# end class
# --------------------------------------------------------------------------------------------------------


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

    # ****************************************************************************************************
    def __getitem__(self, key):
        """
        Copy one element into an independently owned scalar.

        Parameters
        ----------
        key : tuple of int
            Row and column.

        Returns
        -------
        ssotinum
            Element copy.
        """

        cdef tuple position = _indices(key, self.arr.nrows, self.arr.ncols)
        cdef const ssotinum_t *item = arrss_get_item_ptr(position[0], position[1], &self.arr)
        return ssotinum.wrap(ssoti_copy(item))

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def __setitem__(self, key, value):
        """
        Set an element from a real or sparse/semi-sparse scalar.

        Parameters
        ----------
        key : tuple of int
            Row and column.
        value : float or ssotinum or sotinum
            Replacement value.
        """

        cdef tuple position = _indices(key, self.arr.nrows, self.arr.ncols)
        cdef ssotinum number

        if isinstance(value, Real):

            arrss_set_item_r(value, position[0], position[1], &self.arr)

        elif isinstance(value, (ssotinum, sotinum)):

            number = value if isinstance(value, ssotinum) else ssotinum(value)
            arrss_set_item(&number.num, position[0], position[1], &self.arr)

        else:

            raise TypeError("expected a real or sparse/semi-sparse OTI scalar")

        # end if

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
    def truncate(self, direction):
        """
        Zero a direction and its multiples in every element.

        Parameters
        ----------
        direction : int or list or tuple
            Direction in any pyoti.sparse format, or a rawdir.

        Returns
        -------
        arrss
            Truncated copy.
        """

        cdef tuple pair = _direction(direction)
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

# end class
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef tuple _indices(object key, uint64_t rows, uint64_t cols):
    """
    Check and normalize two-dimensional element indices.

    Parameters
    ----------
    key : object
        Pair of Python indices.
    rows : int
        Row count.
    cols : int
        Column count.

    Returns
    -------
    tuple
        Nonnegative row and column indices.
    """

    if not isinstance(key, tuple) or len(key) != 2 or any(
        not isinstance(index, int) for index in key
    ):

        raise TypeError("expected (row, column) integer indices")

    # end if

    row, col = key
    row = row + rows if row < 0 else row
    col = col + cols if col < 0 else col

    if not (0 <= row < rows and 0 <= col < cols):

        raise IndexError("matrix index out of bounds")

    # end if

    return row, col

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef object _array_binary(oarrss left, object other, str op, bint reverse):
    """
    Dispatch an elementwise SoA operation by operand type and side.

    Parameters
    ----------
    left : oarrss
        Matrix operand.
    other : object
        Other matrix or broadcast scalar.
    op : str
        Addition, subtraction, multiplication, or division.
    reverse : bool
        Whether other appears on the left.

    Returns
    -------
    oarrss or NotImplemented
        Elementwise result.
    """

    cdef oarrss rhs
    cdef ssotinum scalar
    cdef oarrss_t result = oarrss_init()

    if isinstance(other, oarrss):

        rhs = other

        if left.shape != rhs.shape:

            raise ValueError("{}: array shapes must match".format(op))

        # end if

        if op == "add":

            oarrss_sum_OO_to(&left.arr, &rhs.arr, &result, _dhl)

        elif op == "sub":

            if reverse:

                oarrss_sub_OO_to(&rhs.arr, &left.arr, &result, _dhl)

            else:

                oarrss_sub_OO_to(&left.arr, &rhs.arr, &result, _dhl)

            # end if

        elif op == "mul":

            oarrss_mul_OO_to(&left.arr, &rhs.arr, &result, _dhl)

        else:

            if reverse:

                oarrss_div_OO_to(&rhs.arr, &left.arr, &result, _dhl)

            else:

                oarrss_div_OO_to(&left.arr, &rhs.arr, &result, _dhl)

            # end if

        # end if

    elif isinstance(other, (ssotinum, sotinum)):

        scalar = other if isinstance(other, ssotinum) else ssotinum(other)

        if scalar.num.nbases == 0 and scalar.num.trc_order == 0:

            scalar = ssotinum(scalar.num.re, order=left.order)

        # end if

        if op == "add":

            oarrss_sum_oO_to(&scalar.num, &left.arr, &result, _dhl)

        elif op == "sub":

            if reverse:

                oarrss_sub_oO_to(&scalar.num, &left.arr, &result, _dhl)

            else:

                oarrss_sub_Oo_to(&left.arr, &scalar.num, &result, _dhl)

            # end if

        elif op == "mul":

            oarrss_mul_oO_to(&scalar.num, &left.arr, &result, _dhl)

        else:

            if reverse:

                oarrss_div_oO_to(&scalar.num, &left.arr, &result, _dhl)

            else:

                oarrss_div_Oo_to(&left.arr, &scalar.num, &result, _dhl)

            # end if

        # end if

    elif isinstance(other, Real):

        if op == "add":

            oarrss_sum_rO_to(other, &left.arr, &result, _dhl)

        elif op == "sub":

            if reverse:

                oarrss_sub_rO_to(other, &left.arr, &result, _dhl)

            else:

                oarrss_sub_Or_to(&left.arr, other, &result, _dhl)

            # end if

        elif op == "mul":

            oarrss_mul_rO_to(other, &left.arr, &result, _dhl)

        else:

            if reverse:

                oarrss_div_rO_to(other, &left.arr, &result, _dhl)

            else:

                oarrss_div_Or_to(&left.arr, other, &result, _dhl)

            # end if

        # end if

    else:

        return NotImplemented

    # end if

    return oarrss.wrap(result)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef object _aos_binary(arrss left, object other, str op, bint reverse):
    """
    Dispatch AoS elementwise operations without converting the array to SoA.

    Parameters
    ----------
    left : arrss
        Array operand.
    other : object
        Array or broadcast scalar.
    op : str
        Algebraic operation.
    reverse : bool
        Whether the other operand appears on the left.

    Returns
    -------
    arrss or NotImplemented
        Elementwise result.
    """

    cdef arrss rhs
    cdef ssotinum scalar
    cdef arrss_t result = arrss_init()

    if isinstance(other, arrss):

        rhs = other

        if left.shape != rhs.shape:

            raise ValueError("{}: array shapes must match".format(op))

        # end if

        if op == "add":

            arrss_sum_OO_to(&left.arr, &rhs.arr, &result, _dhl)

        elif op == "sub":

            if reverse:

                arrss_sub_OO_to(&rhs.arr, &left.arr, &result, _dhl)

            else:

                arrss_sub_OO_to(&left.arr, &rhs.arr, &result, _dhl)

            # end if

        elif op == "mul":

            arrss_mul_OO_to(&left.arr, &rhs.arr, &result, _dhl)

        else:

            if reverse:

                arrss_div_OO_to(&rhs.arr, &left.arr, &result, _dhl)

            else:

                arrss_div_OO_to(&left.arr, &rhs.arr, &result, _dhl)

            # end if

        # end if

    elif isinstance(other, (ssotinum, sotinum)):

        scalar = other if isinstance(other, ssotinum) else ssotinum(other)

        if scalar.num.nbases == 0 and scalar.num.trc_order == 0:

            scalar = ssotinum(scalar.num.re, order=left.order)

        # end if

        if op == "add":

            arrss_sum_oO_to(&scalar.num, &left.arr, &result, _dhl)

        elif op == "sub":

            if reverse:

                arrss_sub_oO_to(&scalar.num, &left.arr, &result, _dhl)

            else:

                arrss_sub_Oo_to(&left.arr, &scalar.num, &result, _dhl)

            # end if

        elif op == "mul":

            arrss_mul_oO_to(&scalar.num, &left.arr, &result, _dhl)

        else:

            if reverse:

                arrss_div_oO_to(&scalar.num, &left.arr, &result, _dhl)

            else:

                arrss_div_Oo_to(&left.arr, &scalar.num, &result, _dhl)

            # end if

        # end if

    elif isinstance(other, Real):

        if op == "add":

            arrss_sum_rO_to(other, &left.arr, &result, _dhl)

        elif op == "sub":

            if reverse:

                arrss_sub_rO_to(other, &left.arr, &result, _dhl)

            else:

                arrss_sub_Or_to(&left.arr, other, &result, _dhl)

            # end if

        elif op == "mul":

            arrss_mul_rO_to(other, &left.arr, &result, _dhl)

        else:

            if reverse:

                arrss_div_rO_to(other, &left.arr, &result, _dhl)

            else:

                arrss_div_Or_to(&left.arr, other, &result, _dhl)

            # end if

        # end if

    else:

        return NotImplemented

    # end if

    return arrss.wrap(result)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef class _LU:
    """
    Opaque owned factorization of the real block of a SoA matrix.
    """

    # ****************************************************************************************************
    def __cinit__(self):
        """
        Initialize native factor storage before construction.
        """

        self.factor.A = oarrss_init()
        self.factor.p_ipiv = NULL

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def __dealloc__(self):
        """
        Release the factorized matrix and pivot buffer.
        """

        oarrss_lu_free(&self.factor)

    # end function
    # ----------------------------------------------------------------------------------------------------

# end class
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def lu_factor(oarrss matrix):
    """
    Factor a square SoA matrix for repeated solves.

    Parameters
    ----------
    matrix : oarrss
        Square coefficient matrix.

    Returns
    -------
    _LU
        Owned opaque factorization.
    """

    cdef _LU factor = _LU()

    if matrix.arr.nrows != matrix.arr.ncols:

        raise ValueError("lu_factor: matrix must be square")

    # end if

    _status("lu_factor", oarrss_lu_factor(&matrix.arr, &factor.factor))
    return factor

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def lu_solve(_LU factor, oarrss rhs):
    """
    Solve a system using a reusable SoA LU factorization.

    Parameters
    ----------
    factor : _LU
        Factorization from lu_factor.
    rhs : oarrss
        Right-hand sides.

    Returns
    -------
    oarrss
        Solution.
    """

    cdef oarrss_t result = oarrss_init()
    cdef int status

    if factor.factor.A.nrows != rhs.arr.nrows:

        raise ValueError("lu_solve: incompatible right-hand-side rows")

    # end if

    status = oarrss_lu_solve(&factor.factor, &rhs.arr, &result, _dhl)

    if status != 0:

        oarrss_free(&result)
        _status("lu_solve", status)

    # end if

    return oarrss.wrap(result)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def solve(matrix, rhs):
    """
    Solve a semi-sparse matrix system.

    Parameters
    ----------
    matrix : oarrss or arrss
        Square coefficient matrix.
    rhs : oarrss or arrss
        Right-hand-side columns.

    Returns
    -------
    oarrss or arrss
        Solution.
    """

    cdef oarrss_t result = oarrss_init()
    cdef arrss_t aos_result = arrss_init()
    cdef oarrss soa_matrix, soa_rhs
    cdef arrss aos_matrix, aos_rhs
    cdef int status

    if isinstance(matrix, arrss) and isinstance(rhs, arrss):

        aos_matrix = matrix
        aos_rhs = rhs

        if aos_matrix.arr.nrows != aos_matrix.arr.ncols or (
            aos_matrix.arr.nrows != aos_rhs.arr.nrows
        ):

            raise ValueError("solve: matrix must be square and match the right-hand-side rows")

        # end if

        status = arrss_solve_to(&aos_matrix.arr, &aos_rhs.arr, &aos_result, _dhl)

        if status != 0:

            arrss_free(&aos_result)
            _status("solve", status)

        # end if

        return arrss.wrap(aos_result)

    # end if

    if not isinstance(matrix, oarrss) or not isinstance(rhs, oarrss):

        raise TypeError("solve expects two arrays of the same semi-sparse layout")

    # end if

    soa_matrix = matrix
    soa_rhs = rhs

    if soa_matrix.arr.nrows != soa_matrix.arr.ncols or soa_matrix.arr.nrows != soa_rhs.arr.nrows:

        raise ValueError("solve: matrix must be square and match the right-hand-side rows")

    # end if

    status = oarrss_solve_to(&soa_matrix.arr, &soa_rhs.arr, &result, _dhl)

    if status != 0:

        oarrss_free(&result)
        _status("solve", status)

    # end if

    return oarrss.wrap(result)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def inv(matrix):
    """
    Invert a nonsingular semi-sparse square matrix.

    Parameters
    ----------
    matrix : oarrss or arrss
        Square coefficient matrix.

    Returns
    -------
    oarrss or arrss
        Inverse matrix.
    """

    cdef oarrss_t result = oarrss_init()
    cdef arrss_t aos_result = arrss_init()
    cdef oarrss soa_matrix
    cdef arrss aos_matrix
    cdef int status

    if isinstance(matrix, arrss):

        aos_matrix = matrix

        if aos_matrix.arr.nrows != aos_matrix.arr.ncols:

            raise ValueError("inv: matrix must be square")

        # end if

        status = arrss_inv_to(&aos_matrix.arr, &aos_result, _dhl)

        if status != 0:

            arrss_free(&aos_result)
            _status("inv", status)

        # end if

        return arrss.wrap(aos_result)

    # end if

    if not isinstance(matrix, oarrss):

        raise TypeError("inv expects a semi-sparse array")

    # end if

    soa_matrix = matrix

    if soa_matrix.arr.nrows != soa_matrix.arr.ncols:

        raise ValueError("inv: matrix must be square")

    # end if

    status = oarrss_inv_to(&soa_matrix.arr, &result, _dhl)

    if status != 0:

        oarrss_free(&result)
        _status("inv", status)

    # end if

    return oarrss.wrap(result)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def det(matrix):
    """
    Compute the semi-sparse determinant of a square matrix.

    Parameters
    ----------
    matrix : oarrss or arrss
        Square coefficient matrix.

    Returns
    -------
    ssotinum
        Determinant.
    """

    cdef ssotinum_t result = ssoti_init()
    cdef oarrss soa_matrix
    cdef arrss aos_matrix
    cdef int status

    if isinstance(matrix, arrss):

        aos_matrix = matrix

        if aos_matrix.arr.nrows != aos_matrix.arr.ncols:

            raise ValueError("det: matrix must be square")

        # end if

        status = arrss_det_to(&aos_matrix.arr, &result, _dhl)

    elif isinstance(matrix, oarrss):

        soa_matrix = matrix

        if soa_matrix.arr.nrows != soa_matrix.arr.ncols:

            raise ValueError("det: matrix must be square")

        # end if

        status = oarrss_det_to(&soa_matrix.arr, &result, _dhl)

    else:

        raise TypeError("det expects a semi-sparse array")

    # end if

    if status != 0:

        ssoti_free(&result)
        _status("det", status)

    # end if

    return ssotinum.wrap(result)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def e(hum_dir, nbases=0, order=0, nip=0):
    """
    Create a semi-sparse number with value 1 along an imaginary direction.

    Same call as ``pyoti.sparse.e`` and the static modules' ``e``. The active set is the distinct
    bases of the direction, and the truncation order is the larger of ``order`` and the order of
    the direction, so the coefficient is never dropped.

    Parameters
    ----------
    hum_dir : int or list or tuple
        Direction in any format ``pyoti.sparse`` accepts (a base label, a list of bases, exponent
        pairs such as ``[[1, 2]]``), or a ``rawdir(index, order)``.
    nbases : int
        Accepted for compatibility with ``pyoti.sparse.e``; semi-sparse numbers grow their active
        set on demand, so it has no effect.
    order : int
        Minimum truncation order.
    nip : int
        Must be 0: semi-sparse Gauss-point types do not exist yet.

    Returns
    -------
    ssotinum
        The imaginary unit along ``hum_dir``.

    Examples
    --------
    >>> x = e([1, 2], order=3)
    >>> x.get_im([1, 2]), x.order, x.active_bases
    (1.0, 3, (1, 2))
    """

    cdef tuple pair

    if nip != 0:

        raise NotImplementedError("semi-sparse Gauss-point numbers (nip > 0) are not available")

    # end if

    if order < 0 or order > 255:

        raise ValueError("order must be between 0 and 255")

    # end if

    pair = _direction(hum_dir)

    return ssotinum.wrap(ssoti_e(pair[0], pair[1], order))

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def zeros(shape, bases=(), order=0):
    """
    Create a zero SoA matrix with the specified active basis set.

    Parameters
    ----------
    shape : tuple of int
        Matrix dimensions.
    bases : iterable of int
        Sorted active basis labels.
    order : int
        Truncation order.

    Returns
    -------
    oarrss
        Zero matrix.
    """

    return oarrss.zeros(shape, bases=bases, order=order)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def dot(left, right):
    """
    Multiply two semi-sparse matrices.

    Parameters
    ----------
    left : oarrss or arrss
        Left factor.
    right : oarrss or arrss
        Right factor.

    Returns
    -------
    oarrss or arrss
        Matrix product.
    """

    return left @ right

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def matmul(left, right):
    """
    Multiply two semi-sparse matrices.

    Parameters
    ----------
    left : oarrss or arrss
        Left factor.
    right : oarrss or arrss
        Right factor.

    Returns
    -------
    oarrss or arrss
        Matrix product.
    """

    return left @ right

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef object _unary(object value, str name):
    """
    Dispatch a scalar or array mathematical function to its native kernel.

    Parameters
    ----------
    value : ssotinum or oarrss or arrss
        Argument.
    name : str
        Mathematical function name.

    Returns
    -------
    ssotinum or oarrss or arrss
        Function result.
    """

    cdef ssotinum scalar
    cdef oarrss array
    cdef arrss aos
    cdef oarrss_t result = oarrss_init()
    cdef arrss_t aos_result = arrss_init()

    if isinstance(value, sotinum):

        value = ssotinum(value)

    # end if

    if isinstance(value, ssotinum):

        scalar = value

        if name == "sin":

            return ssotinum.wrap(ssoti_sin(&scalar.num, _dhl))

        elif name == "cos":

            return ssotinum.wrap(ssoti_cos(&scalar.num, _dhl))

        elif name == "tan":

            return ssotinum.wrap(ssoti_tan(&scalar.num, _dhl))

        elif name == "asin":

            return ssotinum.wrap(ssoti_asin(&scalar.num, _dhl))

        elif name == "acos":

            return ssotinum.wrap(ssoti_acos(&scalar.num, _dhl))

        elif name == "atan":

            return ssotinum.wrap(ssoti_atan(&scalar.num, _dhl))

        elif name == "sinh":

            return ssotinum.wrap(ssoti_sinh(&scalar.num, _dhl))

        elif name == "cosh":

            return ssotinum.wrap(ssoti_cosh(&scalar.num, _dhl))

        elif name == "tanh":

            return ssotinum.wrap(ssoti_tanh(&scalar.num, _dhl))

        elif name == "asinh":

            return ssotinum.wrap(ssoti_asinh(&scalar.num, _dhl))

        elif name == "acosh":

            return ssotinum.wrap(ssoti_acosh(&scalar.num, _dhl))

        elif name == "atanh":

            return ssotinum.wrap(ssoti_atanh(&scalar.num, _dhl))

        elif name == "exp":

            return ssotinum.wrap(ssoti_exp(&scalar.num, _dhl))

        elif name == "log":

            return ssotinum.wrap(ssoti_log(&scalar.num, _dhl))

        elif name == "log10":

            return ssotinum.wrap(ssoti_log10(&scalar.num, _dhl))

        elif name == "sqrt":

            return ssotinum.wrap(ssoti_sqrt(&scalar.num, _dhl))

        elif name == "cbrt":

            return ssotinum.wrap(ssoti_cbrt(&scalar.num, _dhl))

        else:

            return ssotinum.wrap(ssoti_erf(&scalar.num, _dhl))

        # end if

    elif isinstance(value, oarrss):

        array = value

        if name == "sin":

            oarrss_sin_to(&array.arr, &result, _dhl)

        elif name == "cos":

            oarrss_cos_to(&array.arr, &result, _dhl)

        elif name == "tan":

            oarrss_tan_to(&array.arr, &result, _dhl)

        elif name == "asin":

            oarrss_asin_to(&array.arr, &result, _dhl)

        elif name == "acos":

            oarrss_acos_to(&array.arr, &result, _dhl)

        elif name == "atan":

            oarrss_atan_to(&array.arr, &result, _dhl)

        elif name == "sinh":

            oarrss_sinh_to(&array.arr, &result, _dhl)

        elif name == "cosh":

            oarrss_cosh_to(&array.arr, &result, _dhl)

        elif name == "tanh":

            oarrss_tanh_to(&array.arr, &result, _dhl)

        elif name == "asinh":

            oarrss_asinh_to(&array.arr, &result, _dhl)

        elif name == "acosh":

            oarrss_acosh_to(&array.arr, &result, _dhl)

        elif name == "atanh":

            oarrss_atanh_to(&array.arr, &result, _dhl)

        elif name == "exp":

            oarrss_exp_to(&array.arr, &result, _dhl)

        elif name == "log":

            oarrss_log_to(&array.arr, &result, _dhl)

        elif name == "log10":

            oarrss_log10_to(&array.arr, &result, _dhl)

        elif name == "sqrt":

            oarrss_sqrt_to(&array.arr, &result, _dhl)

        elif name == "cbrt":

            oarrss_cbrt_to(&array.arr, &result, _dhl)

        else:

            oarrss_erf_to(&array.arr, &result, _dhl)

        # end if

        return oarrss.wrap(result)

    elif isinstance(value, arrss):

        aos = value

        if name == "sin":

            arrss_sin_to(&aos.arr, &aos_result, _dhl)

        elif name == "cos":

            arrss_cos_to(&aos.arr, &aos_result, _dhl)

        elif name == "tan":

            arrss_tan_to(&aos.arr, &aos_result, _dhl)

        elif name == "asin":

            arrss_asin_to(&aos.arr, &aos_result, _dhl)

        elif name == "acos":

            arrss_acos_to(&aos.arr, &aos_result, _dhl)

        elif name == "atan":

            arrss_atan_to(&aos.arr, &aos_result, _dhl)

        elif name == "sinh":

            arrss_sinh_to(&aos.arr, &aos_result, _dhl)

        elif name == "cosh":

            arrss_cosh_to(&aos.arr, &aos_result, _dhl)

        elif name == "tanh":

            arrss_tanh_to(&aos.arr, &aos_result, _dhl)

        elif name == "asinh":

            arrss_asinh_to(&aos.arr, &aos_result, _dhl)

        elif name == "acosh":

            arrss_acosh_to(&aos.arr, &aos_result, _dhl)

        elif name == "atanh":

            arrss_atanh_to(&aos.arr, &aos_result, _dhl)

        elif name == "exp":

            arrss_exp_to(&aos.arr, &aos_result, _dhl)

        elif name == "log":

            arrss_log_to(&aos.arr, &aos_result, _dhl)

        elif name == "log10":

            arrss_log10_to(&aos.arr, &aos_result, _dhl)

        elif name == "sqrt":

            arrss_sqrt_to(&aos.arr, &aos_result, _dhl)

        elif name == "cbrt":

            arrss_cbrt_to(&aos.arr, &aos_result, _dhl)

        else:

            arrss_erf_to(&aos.arr, &aos_result, _dhl)

        # end if

        return arrss.wrap(aos_result)

    # end if

    raise TypeError("{} expects a semi-sparse scalar or array".format(name))

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def sin(value):
    """
    Evaluate sine elementwise.

    Parameters
    ----------
    value : ssotinum or oarrss
        Argument.

    Returns
    -------
    ssotinum or oarrss
        Sine.
    """

    return _unary(value, "sin")

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def cos(value):
    """
    Evaluate cosine elementwise.

    Parameters
    ----------
    value : ssotinum or oarrss
        Argument.

    Returns
    -------
    ssotinum or oarrss
        Cosine.
    """

    return _unary(value, "cos")

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def tan(value):
    """
    Evaluate tangent elementwise.

    Parameters
    ----------
    value : ssotinum or oarrss
        Argument.

    Returns
    -------
    ssotinum or oarrss
        Tangent.
    """

    return _unary(value, "tan")

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def asin(value):
    """
    Evaluate inverse sine elementwise.

    Parameters
    ----------
    value : ssotinum or oarrss
        Argument.

    Returns
    -------
    ssotinum or oarrss
        Inverse sine.
    """

    return _unary(value, "asin")

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def acos(value):
    """
    Evaluate inverse cosine elementwise.

    Parameters
    ----------
    value : ssotinum or oarrss
        Argument.

    Returns
    -------
    ssotinum or oarrss
        Inverse cosine.
    """

    return _unary(value, "acos")

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def atan(value):
    """
    Evaluate inverse tangent elementwise.

    Parameters
    ----------
    value : ssotinum or oarrss
        Argument.

    Returns
    -------
    ssotinum or oarrss
        Inverse tangent.
    """

    return _unary(value, "atan")

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def sinh(value):
    """
    Evaluate hyperbolic sine elementwise.

    Parameters
    ----------
    value : ssotinum or oarrss
        Argument.

    Returns
    -------
    ssotinum or oarrss
        Hyperbolic sine.
    """

    return _unary(value, "sinh")

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def cosh(value):
    """
    Evaluate hyperbolic cosine elementwise.

    Parameters
    ----------
    value : ssotinum or oarrss
        Argument.

    Returns
    -------
    ssotinum or oarrss
        Hyperbolic cosine.
    """

    return _unary(value, "cosh")

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def tanh(value):
    """
    Evaluate hyperbolic tangent elementwise.

    Parameters
    ----------
    value : ssotinum or oarrss
        Argument.

    Returns
    -------
    ssotinum or oarrss
        Hyperbolic tangent.
    """

    return _unary(value, "tanh")

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def asinh(value):
    """
    Evaluate inverse hyperbolic sine elementwise.

    Parameters
    ----------
    value : ssotinum or oarrss
        Argument.

    Returns
    -------
    ssotinum or oarrss
        Inverse hyperbolic sine.
    """

    return _unary(value, "asinh")

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def acosh(value):
    """
    Evaluate inverse hyperbolic cosine elementwise.

    Parameters
    ----------
    value : ssotinum or oarrss
        Argument.

    Returns
    -------
    ssotinum or oarrss
        Inverse hyperbolic cosine.
    """

    return _unary(value, "acosh")

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def atanh(value):
    """
    Evaluate inverse hyperbolic tangent elementwise.

    Parameters
    ----------
    value : ssotinum or oarrss
        Argument.

    Returns
    -------
    ssotinum or oarrss
        Inverse hyperbolic tangent.
    """

    return _unary(value, "atanh")

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def exp(value):
    """
    Evaluate exponential elementwise.

    Parameters
    ----------
    value : ssotinum or oarrss
        Argument.

    Returns
    -------
    ssotinum or oarrss
        Exponential.
    """

    return _unary(value, "exp")

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def log(value):
    """
    Evaluate natural logarithm elementwise.

    Parameters
    ----------
    value : ssotinum or oarrss
        Argument.

    Returns
    -------
    ssotinum or oarrss
        Natural logarithm.
    """

    return _unary(value, "log")

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def log10(value):
    """
    Evaluate base-10 logarithm elementwise.

    Parameters
    ----------
    value : ssotinum or oarrss
        Argument.

    Returns
    -------
    ssotinum or oarrss
        Base-10 logarithm.
    """

    return _unary(value, "log10")

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def sqrt(value):
    """
    Evaluate square root elementwise.

    Parameters
    ----------
    value : ssotinum or oarrss
        Argument.

    Returns
    -------
    ssotinum or oarrss
        Square root.
    """

    return _unary(value, "sqrt")

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def cbrt(value):
    """
    Evaluate cube root elementwise.

    Parameters
    ----------
    value : ssotinum or oarrss
        Argument.

    Returns
    -------
    ssotinum or oarrss
        Cube root.
    """

    return _unary(value, "cbrt")

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def erf(value):
    """
    Evaluate error function elementwise.

    Parameters
    ----------
    value : ssotinum or oarrss
        Argument.

    Returns
    -------
    ssotinum or oarrss
        Error function.
    """

    return _unary(value, "erf")

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def pow(value, exponent):
    """
    Raise a semi-sparse scalar or array to a real power.

    Parameters
    ----------
    value : ssotinum or oarrss or arrss
        Base.
    exponent : float
        Real exponent.

    Returns
    -------
    ssotinum or oarrss or arrss
        Power.
    """

    return value ** exponent

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def logb(value, base):
    """
    Evaluate the logarithm of a scalar or array in a specified base.

    Parameters
    ----------
    value : ssotinum or oarrss or arrss
        Argument.
    base : float
        Logarithm base.

    Returns
    -------
    ssotinum or oarrss or arrss
        Logarithm in the given base.
    """

    cdef ssotinum scalar

    if isinstance(value, ssotinum):

        scalar = value
        return ssotinum.wrap(ssoti_logb(&scalar.num, base, _dhl))

    elif isinstance(value, (oarrss, arrss)):

        return log(value) / np.log(base)

    # end if

    raise TypeError("logb expects a semi-sparse scalar or array")

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _profile_scalar_native(left, right, operation, mode, iterations):
    """
    Time C-level scalar kernels separately from Python arithmetic dispatch.

    Parameters
    ----------
    left : ssotinum or sotinum
        First operand.
    right : ssotinum or sotinum
        Second operand, same backend as left.
    operation : str
        Multiplication or addition.
    mode : str
        Native allocating, native reusable destination, or Cython wrapper construction.
    iterations : int
        Number of calls.

    Returns
    -------
    float
        Average seconds per iteration.
    """

    cdef ssotinum a, b
    cdef sotinum x, y
    cdef ssotinum_t native = ssoti_init()
    cdef sotinum_t sparse_native = soti_init()
    cdef object wrapped = None
    cdef int i
    cdef double started

    if iterations <= 0 or operation not in ("mul", "add"):

        raise ValueError("expected a positive count and mul or add")

    # end if

    if isinstance(left, ssotinum) and isinstance(right, ssotinum):

        a = left
        b = right
        started = _perf_counter()

        if mode == "reuse":

            for i in range(iterations):

                if operation == "mul":

                    ssoti_mul_oo_to(&a.num, &b.num, &native, _dhl)

                else:

                    ssoti_sum_oo_to(&a.num, &b.num, &native, _dhl)

                # end if

            # end for

        elif mode == "alloc":

            for i in range(iterations):

                if operation == "mul":

                    native = ssoti_mul_oo(&a.num, &b.num, _dhl)

                else:

                    native = ssoti_sum_oo(&a.num, &b.num, _dhl)

                # end if

                ssoti_free(&native)

            # end for

        elif mode == "wrap":

            for i in range(iterations):

                if operation == "mul":

                    native = ssoti_mul_oo(&a.num, &b.num, _dhl)

                else:

                    native = ssoti_sum_oo(&a.num, &b.num, _dhl)

                # end if

                wrapped = ssotinum.wrap(native)

            # end for

        else:

            raise ValueError("unknown mode")

        # end if

        started = (_perf_counter() - started) / iterations

        if mode == "reuse":

            ssoti_free(&native)

        # end if

        return started

    elif isinstance(left, sotinum) and isinstance(right, sotinum):

        x = left
        y = right
        started = _perf_counter()

        if mode not in ("alloc", "wrap"):

            raise ValueError("sparse backend supports alloc and wrap modes")

        # end if

        for i in range(iterations):

            if operation == "mul":

                sparse_native = soti_mul_oo(&x.num, &y.num, _dhl)

            else:

                sparse_native = soti_sum_oo(&x.num, &y.num, _dhl)

            # end if

            if mode == "wrap":

                wrapped = sotinum.create(&sparse_native)

            else:

                soti_free(&sparse_native)

            # end if

        # end for

        return (_perf_counter() - started) / iterations

    # end if

    raise TypeError("operands must have the same supported scalar backend")

# end function
# --------------------------------------------------------------------------------------------------------
