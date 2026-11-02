# Direction parsing, raw directions, status helpers and shared utilities of pyoti.dense.
# Owner: WP8a.

import builtins as _builtins
import weakref as _weakref
from libc.stdlib cimport malloc, calloc, free
from math import factorial as _factorial
from math import log as _math_log
import pyoti.sparse as _sparse_module
from pyoti.sparse import set_printoptions as _sparse_set_printoptions


cdef extern from "oti/comm.h":

    cdef enum:
        _MAXORDER_OTI


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
        Global direction index within its order (the numbering of ``sotinum`` and ``otinum``).
    order : int
        Direction order, 0 to 150. Order 0 is the real part and needs index 0.

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

        if not 0 <= order <= _MAXORDER_OTI:

            raise ValueError("rawdir order must be between 0 and {}".format(_MAXORDER_OTI))

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

    if len(expanded) > _MAXORDER_OTI or any(base < 1 or base > 65535 for base in expanded):

        raise ValueError("direction order or basis label out of range")

    # end if

    pair = (_builtins.sum(comb(base - 1 + i, i + 1) for i, base in enumerate(expanded)),
            len(expanded))

    if not (0 <= pair[0] <= 2**64 - 1):

        raise ValueError("direction index out of range")

    # end if

    return int(pair[0]), int(pair[1])

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef list _bases(object bases):
    """
    Validate a collection of base labels (order and repetition are irrelevant to dense numbers).

    Parameters
    ----------
    bases : object
        Iterable of one-based global base labels.

    Returns
    -------
    list
        Validated labels.
    """

    cdef list labels = list(bases)

    if any(not isinstance(x, (int, np.integer)) or x < 1 or x > 65535 for x in labels):

        raise ValueError("bases must contain labels from 1 through 65535")

    # end if

    return [int(x) for x in labels]

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef bases_t _nact_of(object bases) except *:
    """
    Return the number of active bases a dense number needs to hold the given labels.

    A dense number is dense over the bases 1..nact, so the labels only set nact = max(labels).

    Parameters
    ----------
    bases : object
        Iterable of one-based global base labels; may be empty.

    Returns
    -------
    int
        Largest label, or 0 when there are none.
    """

    cdef list labels = _bases(bases)

    return max(labels) if len(labels) > 0 else 0

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef int _check_order(object order) except -1:
    """
    Validate a truncation order argument.

    Parameters
    ----------
    order : int
        Requested truncation order.
    """

    if not isinstance(order, (int, np.integer)):

        raise TypeError("order must be an integer")

    # end if

    if order < 0 or order > _MAXORDER_OTI:

        raise ValueError("order must be between 0 and {}".format(_MAXORDER_OTI))

    # end if

    return 0

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef void _status(str operation, int status) except *:
    """
    Translate a native dense status into a Python exception.

    Parameters
    ----------
    operation : str
        Name of the failing operation.
    status : int
        Native ``DN_*`` code, or a positive LAPACK ``info``.
    """

    if status == DN_OK:

        return

    elif status > 0:

        raise np.linalg.LinAlgError("{}: singular real part at pivot {}".format(
            operation, status))

    elif status == DN_ERR_SIZE:

        raise ValueError("{}: incompatible shape or LAPACK dimension overflow".format(operation))

    elif status == DN_ERR_MEMORY:

        raise MemoryError("{}: allocation failed or the size is too large".format(operation))

    elif status == DN_ERR_PIVOT:

        raise ValueError("{}: invalid pivot index".format(operation))

    elif status == DN_ERR_INDEX:

        raise IndexError("{}: index, direction or order out of range".format(operation))

    elif status == DN_ERR_ARGUMENT:

        raise ValueError("{}: invalid argument".format(operation))

    # end if

    raise RuntimeError("{}: native status {}".format(operation, status))

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef int _soa_ok(str operation, int status, oarr_t *result) except -1:
    """
    Check the status of a SoA call and free the C result before raising on a failure.

    Parameters
    ----------
    operation : str
        Name of the operation.
    status : int
        Native status.
    result : oarr_t *
        C result that was being written; released on a failure.
    """

    if status != DN_OK:

        oarr_free(result)
        _status(operation, status)

    # end if

    return 0

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef int _aos_ok(str operation, int status, arro_t *result) except -1:
    """
    Check the status of an AoS call and free the C result before raising on a failure.

    Parameters
    ----------
    operation : str
        Name of the operation.
    status : int
        Native status.
    result : arro_t *
        C result that was being written; released on a failure.
    """

    if status != DN_OK:

        arro_free(result)
        _status(operation, status)

    # end if

    return 0

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def imdir(hum_dir):
    """
    Resolve a human direction into its raw global pair, as ``pyoti.sparse.imdir`` does.

    Parameters
    ----------
    hum_dir : int or list or tuple or rawdir
        Direction in any pyoti.sparse format, or a rawdir.

    Returns
    -------
    list
        Global direction index and order, ``[index, order]``.
    """

    cdef tuple pair = _direction(hum_dir)
    return [pair[0], pair[1]]

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef double _deriv_factor(uint64_t index, ord_t order):
    """
    Return the factor that turns a coefficient into a derivative (product of exponent factorials).

    Parameters
    ----------
    index : int
        Global direction index within its order.
    order : int
        Direction order.

    Returns
    -------
    float
        Product over the bases of the direction of the factorial of their exponent.
    """

    cdef double result = 1.0
    cdef int run = 0
    cdef object previous = None

    for label in _unrank(index, order):

        if label == previous:

            run += 1

        else:

            run = 1
            previous = label

        # end if

        result *= run

    # end for

    return result

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef np.ndarray _soa_blocks(omat value):
    """
    Return all coefficient blocks of a SoA array as one writable (nblocks, size) NumPy view.

    The view keeps the array alive. Growing the array afterwards may reallocate its buffer and
    invalidates outstanding views.

    Parameters
    ----------
    value : omat
        Source array.

    Returns
    -------
    numpy.ndarray
        Shape (1 + number of imaginary directions, nrows * ncols), sharing native memory.
    """

    cdef np.npy_intp dims[2]
    cdef np.ndarray flat
    cdef uint64_t nblocks = 1 + sshelp_ndir_total(value.arr.nact, value.arr.trc_order)

    if value.arr.size == 0 or value.arr.p_data == NULL:

        return np.zeros((nblocks, value.arr.size), dtype=np.float64)

    # end if

    dims[0] = nblocks
    dims[1] = value.arr.size
    flat = np.PyArray_SimpleNewFromData(2, dims, np.NPY_DOUBLE, <void *>value.arr.p_data)
    np.set_array_base(flat, value)
    return flat

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef class _BlockExport:
    """
    Base object of a NumPy view returned by ``omat.get_block``.

    It keeps the exporting array alive and is registered (weakly) in ``_BLOCK_EXPORTS``, so an
    operation that would replace the array's native buffer can tell that views are alive.
    """

    cdef object owner
    cdef object __weakref__

    def __cinit__(self, owner):
        self.owner = owner

# end class
# --------------------------------------------------------------------------------------------------------


# Live block exports of each omat: {omat: WeakSet of _BlockExport} (both weak, so nothing is kept alive
# beyond the views themselves).
_BLOCK_EXPORTS = _weakref.WeakKeyDictionary()


# ********************************************************************************************************
cdef int _register_block_export(omat owner, _BlockExport export) except -1:
    """
    Record a block view of an array so that layout changes can be refused while it lives.

    Parameters
    ----------
    owner : omat
        Exporting array.
    export : _BlockExport
        Base object of the view; forgotten automatically when the last view is released.
    """

    exports = _BLOCK_EXPORTS.get(owner)

    if exports is None:

        exports = _weakref.WeakSet()
        _BLOCK_EXPORTS[owner] = exports

    # end if

    exports.add(export)
    return 0

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef int _check_no_block_views(omat value) except -1:
    """
    Refuse to replace or reshape the buffer of an array that has live block views.

    Views made by ``get_block`` point into the array's native buffer; an operation that grows nact or
    the truncation order, or swaps in a new buffer (``out=``), would leave them dangling (or pointing at
    other blocks), as NumPy's ``resize`` refuses when references exist.

    Parameters
    ----------
    value : omat
        Array about to change its layout or buffer.

    Raises
    ------
    BufferError
        If a view returned by ``get_block`` is still alive.
    """

    exports = _BLOCK_EXPORTS.get(value)

    if exports is not None and len(exports) > 0:

        raise BufferError("cannot grow an array with live block views")

    # end if

    return 0

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef int _check_growth(omat value, bases_t nact, ord_t order) except -1:
    """
    Refuse a layout change (larger nact or truncation order) while block views are alive.

    Parameters
    ----------
    value : omat
        Array about to be grown.
    nact : int
        Number of active bases it will need.
    order : int
        Truncation order it will need.

    Raises
    ------
    BufferError
        If the layout would change and a view returned by ``get_block`` is still alive.
    """

    if nact > value.arr.nact or order > value.arr.trc_order:

        _check_no_block_views(value)

    # end if

    return 0

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef void _raise_soa_order(omat value, ord_t order) except *:
    """
    Raise the truncation order of a SoA array in place, zero-extending every entry.

    Parameters
    ----------
    value : omat
        Array to grow; must own its buffer.
    order : int
        Requested truncation order; nothing happens when the array already has it.
    """

    if order > _MAXORDER_OTI:

        raise ValueError("order must be between 0 and {}".format(_MAXORDER_OTI))

    # end if

    if order > value.arr.trc_order:

        _check_no_block_views(value)
        _status("raise order", oarr_reserve(&value.arr, value.arr.nact, value.arr.nrows,
                                            value.arr.ncols, order))

    # end if

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef object _assign_out(object out, object result):
    """
    Move a freshly computed result into a caller-provided ``out`` holder.

    The native structures of both objects are swapped, so ``out`` keeps its identity and takes the
    result; the temporary result releases the old buffers. A non-owning view cannot be ``out``.

    Parameters
    ----------
    out : otinum or omat or arro
        Result holder. Views of its old buffers become invalid.
    result : otinum or omat or arro
        Computed result.

    Returns
    -------
    otinum or omat or arro
        The holder ``out``.
    """

    cdef otinum_t stmp
    cdef oarr_t atmp
    cdef arro_t btmp

    if isinstance(out, otinum) and isinstance(result, otinum):

        if not (<otinum>out).FLAGS & 1:

            raise ValueError("out is a view of another object and cannot receive a result")

        # end if

        stmp = (<otinum>out).num
        (<otinum>out).num = (<otinum>result).num
        (<otinum>result).num = stmp
        return out

    # end if

    if isinstance(out, omat) and isinstance(result, arro):

        result = _to_soa(result)

    elif isinstance(out, arro) and isinstance(result, omat):

        result = _to_aos(result)

    # end if

    if isinstance(out, omat) and isinstance(result, omat):

        if not (<omat>out).FLAGS & 1:

            raise ValueError("out is a view of another object and cannot receive a result")

        # end if

        if (<omat>out).arr.nrows != (<omat>result).arr.nrows or (
            (<omat>out).arr.ncols != (<omat>result).arr.ncols
        ):

            raise ValueError("out has shape {}, expected {}".format(
                ((<omat>out).arr.nrows, (<omat>out).arr.ncols),
                ((<omat>result).arr.nrows, (<omat>result).arr.ncols)))

        # end if

        # The swap replaces the buffer of out: block views of it would dangle.
        _check_no_block_views(<omat>out)

        atmp = (<omat>out).arr
        (<omat>out).arr = (<omat>result).arr
        (<omat>result).arr = atmp
        return out

    # end if

    if isinstance(out, arro) and isinstance(result, arro):

        if not (<arro>out).FLAGS & 1:

            raise ValueError("out is a view of another object and cannot receive a result")

        # end if

        if (<arro>out).arr.nrows != (<arro>result).arr.nrows or (
            (<arro>out).arr.ncols != (<arro>result).arr.ncols
        ):

            raise ValueError("out has shape {}, expected {}".format(
                ((<arro>out).arr.nrows, (<arro>out).arr.ncols),
                ((<arro>result).arr.nrows, (<arro>result).arr.ncols)))

        # end if

        btmp = (<arro>out).arr
        (<arro>out).arr = (<arro>result).arr
        (<arro>result).arr = btmp
        return out

    # end if

    raise TypeError("out must be a dense holder of the same kind as the result")

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef object _finish(object result, object out):
    """
    Return a result, or store it in ``out`` when a holder was given.

    Parameters
    ----------
    result : object
        Computed result.
    out : object
        Optional holder.

    Returns
    -------
    object
        ``result`` when ``out`` is None, otherwise None (the result went into ``out``).
    """

    if out is None:

        return result

    # end if

    if isinstance(out, _dnfe) or isinstance(result, _dnfe):

        _fe_store(result, out)
        return None

    # end if

    _assign_out(out, result)
    return None

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef tuple _process_shape(object shape):
    """
    Turn a shape argument into (rows, columns) the way pyoti.sparse does; an int is a column.

    Parameters
    ----------
    shape : int or tuple of int
        Length of a column vector, or one or two dimensions.

    Returns
    -------
    tuple
        Number of rows and columns.
    """

    cdef object dims

    if isinstance(shape, (int, np.integer)):

        dims = (int(shape), 1)

    elif len(shape) == 1:

        dims = (int(shape[0]), 1)

    elif len(shape) == 2:

        dims = (int(shape[0]), int(shape[1]))

    else:

        raise ValueError("Can't create a matrix with more than 2 dimensions.")

    # end if

    if dims[0] < 0 or dims[1] < 0:

        raise ValueError("shape must contain nonnegative rows and columns")

    # end if

    return dims

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef otinum _as_scalar(object value, ord_t order):
    """
    Convert a real, sparse scalar or dense scalar into an otinum.

    Parameters
    ----------
    value : float or sotinum or otinum
        Source value.
    order : int
        Truncation order used when ``value`` is real.

    Returns
    -------
    otinum
        The scalar itself when it already is one, otherwise a new scalar.
    """

    if isinstance(value, otinum):

        return value

    # end if

    return otinum(value, order=order)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef otinum _soa_sum_all(omat value):
    """
    Add every element of a SoA array into one dense scalar.

    Parameters
    ----------
    value : omat
        Array to reduce.

    Returns
    -------
    otinum
        Sum of all elements, over the array's active bases.
    """

    cdef np.ndarray[np.float64_t, ndim=1] sums = _soa_blocks(value).sum(axis=1)
    cdef otinum total = otinum.__new__(otinum)
    cdef ndir_t i
    cdef ndir_t nimag = sshelp_ndir_total(value.arr.nact, value.arr.trc_order)

    _status("sum", oti_create_empty_to(value.arr.nact, value.arr.trc_order, &total.num))
    total.num.re = sums[0]

    for i in range(nimag):

        total.num.p_im[i] = sums[i + 1]

    # end for

    total.num.act_order = value.arr.act_order
    return total

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef otinum _extract_scalar(otinum value, uint64_t index, ord_t order, bint deriv):
    """
    Collect the coefficients of a scalar that are multiples of a direction.

    Every direction ``d + r`` of the scalar becomes direction ``r`` of the result, so the result has
    the truncation order of the scalar minus ``order``. With ``deriv`` the coefficients are scaled
    so that the result holds the derivatives of the scalar along ``d + r`` divided by those of
    ``r``, like ``pyoti.sparse``.

    Parameters
    ----------
    value : otinum
        Source scalar.
    index : int
        Global index of the direction ``d``.
    order : int
        Order of the direction ``d``.
    deriv : bool
        Scale the coefficients as derivatives instead of raw coefficients.

    Returns
    -------
    otinum
        Extracted scalar.
    """

    cdef otinum result = otinum.__new__(otinum)

    if order == 0:

        _status("extract", oti_copy_to(&value.num, &result.num))
        return result

    # end if

    if deriv:

        _status("extract_deriv", oti_extract_deriv_to(index, order, &value.num, &result.num))

    else:

        _status("extract_im", oti_extract_im_to(index, order, &value.num, &result.num))

    # end if

    return result

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef tuple _raw_key(object key):
    """
    Read a raw (index, order) direction key the way ``pyoti.sparse`` scalars do.

    Parameters
    ----------
    key : list or tuple or rawdir
        Global direction index and order, or a rawdir.

    Returns
    -------
    tuple
        Global index and order.
    """

    if isinstance(key, rawdir):

        return key.index, key.order

    # end if

    if isinstance(key, (list, tuple)) and len(key) == 2 and all(
        isinstance(x, (int, np.integer)) for x in key
    ):

        return rawdir(key[0], key[1]).index, rawdir(key[0], key[1]).order

    # end if

    raise TypeError("expected a raw direction [index, order] or a rawdir")

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def set_printoptions(float_format="g", terms_print=4):
    """
    Set how OTI numbers are printed, with the arguments of ``pyoti.sparse.set_printoptions``.

    Dense numbers and arrays print through the sparse text format, so this forwards to the sparse
    setting (and changes it for ``pyoti.sparse`` as well). Call it with no arguments to restore the
    defaults.

    Parameters
    ----------
    float_format : str
        Format specification of the coefficients.
    terms_print : int
        Number of terms printed; -1 prints all of them.
    """

    _sparse_set_printoptions(float_format, terms_print)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef str _scalar_text(otinum value):
    """
    Format a scalar the way ``str(pyoti.sparse.sotinum)`` does, with plain Python integers.

    The float format and the number of printed terms are those of ``set_printoptions``; terms are
    the nonzero coefficients in increasing order and direction, and the real part counts as one.

    Parameters
    ----------
    value : otinum
        Scalar to format.

    Returns
    -------
    str
        Text such as ``2 + 1 * e([1]) + 3 * e([[1,2],3])``.
    """

    cdef otinum_t *num = &value.num
    cdef str float_format = _sparse_module.floatFormat
    cdef object limit = _sparse_module.termsPrint
    cdef bases_t local[256]
    cdef list terms = []
    cdef list labels
    cdef ord_t p, u
    cdef ndir_t j, size, offset
    cdef double coefficient
    cdef int printed = 0
    cdef int position
    cdef bint dots = False
    cdef str body = ""
    cdef str text
    cdef object base
    cdef object previous
    cdef int run

    if num.re != 0:

        body += ("%" + float_format) % num.re
        printed += 1

    # end if

    for p in range(1, num.act_order + 1):

        size = sshelp_ndir_order(num.nact, p)
        offset = sshelp_order_offset(num.nact, p)

        for j in range(size):

            if num.p_im[offset + j] != 0.0:

                terms.append((p, j, num.p_im[offset + j]))

            # end if

        # end for

    # end for

    for position in range(len(terms)):

        p, j, coefficient = terms[position]
        sshelp_unrank(j, p, local)
        labels = []
        previous = None
        run = 0

        for u in range(p):

            base = int(local[u]) + 1

            if base == previous:

                run += 1
                labels[len(labels) - 1] = [base, run]

            else:

                run = 1
                previous = base
                labels.append(base)

            # end if

        # end for

        text = ("%+" + float_format) % coefficient
        body += " " + text[0] + " " + text[1:] + " * e(" + str(labels).replace(" ", "") + ")"
        printed += 1

        if printed == limit:

            dots = position < len(terms) - 1
            break

        # end if

    # end for

    if dots:

        body += " + ... "

    # end if

    if printed == 0:

        body += ("%" + float_format) % num.re

    # end if

    return body

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef str _array_text(object value):
    """
    Format an array the way ``str(pyoti.sparse.matso)`` does: one line per element, by columns.

    Parameters
    ----------
    value : omat or arro
        Array to format.

    Returns
    -------
    str
        Text with the header ``matso< shape: (r, c),`` and ``(i,j) element`` lines.
    """

    cdef uint64_t nrows = value.shape[0]
    cdef uint64_t ncols = value.shape[1]
    cdef uint64_t i, j
    cdef str out = "matso< shape: " + str(value.shape) + ", \n"

    for j in range(ncols):

        out += " - Column " + str(j) + "\n"

        for i in range(nrows):

            out += "({0:d},{1:d}) ".format(i, j) + str(value[i, j]) + "\n"

        # end for

    # end for

    return out + ">"

# end function
# --------------------------------------------------------------------------------------------------------
