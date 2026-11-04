# Logical shapes, NumPy keys, read-only exports and the growth guard (Phase 7b).
#
# oarrss and arrss keep their 2-D C structs until Phase 8; the Python object carries a logical ndim
# (0, 1 or 2, PLAN-ndarray-contracts.md 11.1): a 1-D (n,) array is stored as an n x 1 C array and a
# 0-D () array as 1 x 1. A vector has the same memory order as n x 1 and as 1 x n in both layouts
# (column-major SoA blocks, row-major AoS records), so switching between the two only swaps nrows and
# ncols.
#
# Exports (`.real`, `get_block`) are NumPy views of an oarrss's native buffer. They are read-only by
# default and tracked in _SS_EXPORTS (weakly, like dense's _BLOCK_EXPORTS, until Phase U moves
# oarrss onto nd_buffer_t), and every path that relayouts an array (new base labels, a higher
# truncation order, a buffer swap) refuses to run while one is alive (rules G1-G3, 11.6).

import weakref as _weakref
import operator as _operator
import warnings as _warnings
cimport pyoti.real as _real_module
from libc.string cimport memcpy, memcmp
from libc.stdint cimport int64_t


# oti_ctx_check_alloc (the context budget) is declared in pyoti/c_otilib/real_ndarray.pxi.


_RANK_ERROR = "pyoti.semisparse arrays have at most 2 dimensions"

_GROWTH_ERROR = ("cannot grow an array with live block views or exports; size it first with "
                 "A.reserve(bases=..., order=...) or create it with nbases= / bases= / order=")

_BROADCAST_ERROR = ("broadcasting between shapes {} and {} is supported by pyoti.dense only; "
                    "pyoti.semisparse broadcasts equal shapes and single elements")


# ********************************************************************************************************
cdef tuple _creator_dims(object shape):
    """
    Turn a creator's shape argument into the logical ndim and the 2-D C dimensions (rule C1).

    Parameters
    ----------
    shape : int or tuple of int
        An int or a 1-tuple gives a 1-D array, a 2-tuple a 2-D array and ``()`` a 0-D array.

    Returns
    -------
    tuple
        ``(ndim, nrows, ncols)``.

    Raises
    ------
    ValueError
        More than two dimensions, or a negative extent.
    """

    cdef tuple dims

    if isinstance(shape, (int, np.integer)):

        dims = (1, int(shape), 1)

    else:

        shape = tuple(shape)

        if len(shape) == 0:

            dims = (0, 1, 1)

        elif len(shape) == 1:

            dims = (1, _operator.index(shape[0]), 1)

        elif len(shape) == 2:

            dims = (2, _operator.index(shape[0]), _operator.index(shape[1]))

        else:

            raise ValueError(_RANK_ERROR)

        # end if

    # end if

    if dims[1] < 0 or dims[2] < 0:

        raise ValueError("negative dimensions are not allowed")

    # end if

    return dims

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef tuple _lshape(int ndim, uint64_t nrows, uint64_t ncols):
    """
    Logical shape of a 2-D C struct of the given logical ndim.

    Parameters
    ----------
    ndim : int
        Logical ndim (0, 1 or 2).
    nrows, ncols : int
        C dimensions.

    Returns
    -------
    tuple
        ``(nrows, ncols)``, ``(nrows,)`` or ``()``.
    """

    if ndim == 2:

        return (nrows, ncols)

    elif ndim == 1:

        return (nrows,)

    # end if

    return ()

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef object _nd(object value, int ndim):
    """
    Give a freshly built semi-sparse array its logical ndim (vectors are stored as columns).

    Parameters
    ----------
    value : oarrss or arrss or object
        Array; anything else is returned unchanged.
    ndim : int
        Logical ndim; 1 turns a 1 x n struct into n x 1 (same memory order); 0 requires one element.

    Returns
    -------
    object
        ``value``.
    """

    cdef oarrss soa
    cdef arrss aos

    if isinstance(value, oarrss):

        soa = value

        if ndim < 2 and soa.arr.nrows == 1:

            soa.arr.nrows = soa.arr.ncols
            soa.arr.ncols = 1

        # end if

        soa._ndim = ndim if soa.arr.ncols == 1 and (ndim == 1 or soa.arr.nrows == 1) else 2

    elif isinstance(value, arrss):

        aos = value

        if ndim < 2 and aos.arr.nrows == 1:

            aos.arr.nrows = aos.arr.ncols
            aos.arr.ncols = 1

        # end if

        aos._ndim = ndim if aos.arr.ncols == 1 and (ndim == 1 or aos.arr.nrows == 1) else 2

    # end if

    return value

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef object _same_nd(object result, object like):
    """
    Give a same-shape result (an elementwise operation, a copy) the logical ndim of its operand.

    Parameters
    ----------
    result : object
        Result; returned unchanged unless it is a semi-sparse array with like's C dimensions.
    like : object
        Operand whose logical ndim the result takes.

    Returns
    -------
    object
        ``result``.
    """

    cdef int ndim

    if isinstance(like, oarrss):

        ndim = (<oarrss>like)._ndim

    elif isinstance(like, arrss):

        ndim = (<arrss>like)._ndim

    else:

        return result

    # end if

    if ndim != 2 and (isinstance(result, oarrss) or isinstance(result, arrss)) and (
            result.size == like.size):

        _nd(result, ndim)

    # end if

    return result

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef int _ndim_of(object value):
    """
    Logical ndim of a semi-sparse array, ``len(shape)`` of anything else with a shape.

    Parameters
    ----------
    value : object
        Array.

    Returns
    -------
    int
        Logical ndim.
    """

    if isinstance(value, oarrss):

        return (<oarrss>value)._ndim

    elif isinstance(value, arrss):

        return (<arrss>value)._ndim

    # end if

    return len(value.shape)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef tuple _key(object key, int ndim, uint64_t nrows, uint64_t ncols):
    """
    Resolve a NumPy basic key on a logical shape of ndim <= 2 (rule I1; shared ``pyoti.real.key2d``).

    An integer drops its axis, a slice keeps it, one ``...`` expands, negative integers count from
    the end; ``None`` raises ``ValueError`` (rank limit of 2 until Phase 8), anything else that is not
    an integer, a slice or an ellipsis raises ``IndexError``.

    Parameters
    ----------
    key : object
        Index key.
    ndim : int
        Logical ndim of the indexed array.
    nrows, ncols : int
        C dimensions.

    Returns
    -------
    tuple
        ``(r0, rs, rn, c0, cs, cn, shape)``: start, step and count of the selected C rows and
        columns, and the logical result shape (None for one integer per axis: a scalar element).
    """

    cdef tuple res = _real_module.key2d(key, ndim, nrows, ncols if ndim == 2 else 1,
                                        "pyoti.semisparse")

    return (res[0], res[2], len(range(res[0], res[1], res[2])),
            res[3], res[5], len(range(res[3], res[4], res[5])), res[6])

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef int _assign_plan(tuple vshape, tuple tshape) except -1:
    """
    How a value of one shape fills a target of another (rule S1; shared ``pyoti.real.assign_plan``).

    Parameters
    ----------
    vshape : tuple
        Logical shape of the value.
    tshape : tuple
        Logical shape of the selection (ndim <= 2).

    Returns
    -------
    int
        0 equal shapes (element order shared), 1 a single element, 2 a row repeated down a 2-D
        target, 3 a column repeated across it.

    Raises
    ------
    ValueError
        NumPy would refuse the assignment.
    """

    return _real_module.assign_plan(vshape, tshape)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef tuple _broadcast_shape(tuple left, tuple right):
    """
    Shape of an elementwise result in pyoti.semisparse: equal shapes, or one single-element operand.

    Parameters
    ----------
    left, right : tuple
        Logical operand shapes.

    Returns
    -------
    tuple
        NumPy's broadcast shape.

    Raises
    ------
    ValueError
        Any other combination (11.2): mixing ``(n,)`` and ``(n, 1)`` never builds ``(n, n)`` here.
    """

    cdef tuple shape

    if left == right:

        return left

    # end if

    if np.prod(left, dtype=np.int64) == 1 or np.prod(right, dtype=np.int64) == 1:

        shape = tuple(np.broadcast_shapes(left, right))

        if len(shape) <= 2:

            return shape

        # end if

    # end if

    raise ValueError(_BROADCAST_ERROR.format(left, right))

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef int _check_alloc(object nbytes) except -1:
    """
    Check a requested buffer size against the execution context's allocation budget.

    Parameters
    ----------
    nbytes : int
        Requested bytes (a Python int, so it cannot overflow).

    Raises
    ------
    MemoryError
        The request exceeds the budget (or int64).
    """

    if nbytes > 9223372036854775807 or oti_ctx_check_alloc(NULL, <int64_t>nbytes) != 0:

        raise MemoryError("the requested semi-sparse array ({} bytes) exceeds the allocation "
                          "budget".format(nbytes))

    # end if

    return 0

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef class _SSExport:
    """
    Base object of a NumPy view of an oarrss buffer (``.real``, ``get_block``).

    It keeps the exporting array alive and is registered (weakly) in ``_SS_EXPORTS``, so an operation
    that would relayout the array can tell that views are alive.
    """

    cdef object owner
    cdef object __weakref__

    def __cinit__(self, owner):
        self.owner = owner

# end class
# --------------------------------------------------------------------------------------------------------


# Live exports of each oarrss / Gauss value: {owner: WeakSet of _SSExport} (both weak).
_SS_EXPORTS = _weakref.WeakKeyDictionary()


# ********************************************************************************************************
cdef object _export_view(object owner, coeff_t *data, uint64_t count, object shape, bint writeable):
    """
    Build a tracked, column-major NumPy view of native coefficients.

    Parameters
    ----------
    owner : oarrss or _ssfe
        Array owning the buffer.
    data : coeff_t *
        First coefficient (not NULL when count > 0).
    count : int
        Number of coefficients.
    shape : tuple
        Shape of the view (Fortran order over the coefficients).
    writeable : bool
        Whether the view may be written.

    Returns
    -------
    numpy.ndarray
        The view; an empty array (not shared) when ``count`` is 0.
    """

    cdef np.npy_intp dims[1]
    cdef np.ndarray flat
    cdef _SSExport export
    cdef object result

    if count == 0 or data == NULL:

        result = np.zeros(shape, dtype=np.float64)
        result.flags.writeable = writeable
        return result

    # end if

    dims[0] = count
    flat = np.PyArray_SimpleNewFromData(1, dims, np.NPY_DOUBLE, <void *>data)
    export = _SSExport(owner)
    np.set_array_base(flat, export)

    exports = _SS_EXPORTS.get(owner)

    if exports is None:

        exports = _weakref.WeakSet()
        _SS_EXPORTS[owner] = exports

    # end if

    exports.add(export)
    result = flat.reshape(shape, order="F")
    result.flags.writeable = writeable
    return result

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef bint _has_exports(object owner):
    """
    Whether a ``.real`` or ``get_block`` view of an array is alive.

    Parameters
    ----------
    owner : oarrss or _ssfe
        Array.

    Returns
    -------
    bool
        True while a view lives.
    """

    exports = _SS_EXPORTS.get(owner)

    return exports is not None and len(exports) > 0

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef int _check_no_exports(object owner) except -1:
    """
    Refuse to relayout or swap the buffer of an array with live exports (rule G2's message).

    Parameters
    ----------
    owner : oarrss or _ssfe
        Array about to change its layout.

    Raises
    ------
    BufferError
        A view returned by ``.real`` or ``get_block`` is still alive.
    """

    if _has_exports(owner):

        raise BufferError(_GROWTH_ERROR)

    # end if

    return 0

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef bint _new_labels(const bases_t *have, bases_t nhave, const bases_t *want, bases_t nwant):
    """
    Whether a sorted label set holds a label that another sorted set lacks.

    Parameters
    ----------
    have : bases_t *
        Sorted labels of the array.
    nhave : int
        Their number.
    want : bases_t *
        Sorted labels of the value.
    nwant : int
        Their number.

    Returns
    -------
    bool
        True when ``want`` is not a subset of ``have``.
    """

    cdef bases_t i, j = 0

    for i in range(nwant):

        while j < nhave and have[j] < want[i]:

            j += 1

        # end while

        if j == nhave or have[j] != want[i]:

            return True

        # end if

    # end for

    return False

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef int _check_arr_growth(object owner, const oarrss_t *arr, const bases_t *bases, bases_t nbases,
                           ord_t order) except -1:
    """
    Refuse a layout change of a native SoA buffer (an oarrss or a Gauss value's) with live exports.

    Parameters
    ----------
    owner : oarrss or _ssfe
        Python object owning ``arr`` (the key of its exports).
    arr : oarrss_t *
        Buffer about to receive a value.
    bases : bases_t *
        Sorted labels of the value.
    nbases : int
        Their number.
    order : int
        Truncation order of the value.

    Raises
    ------
    BufferError
        The value needs new labels or a higher order and a view of ``owner`` is alive.
    """

    if order > arr.trc_order or _new_labels(arr.p_bases, arr.nbases, bases, nbases):

        _check_no_exports(owner)

    # end if

    return 0

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef int _check_ss_growth(oarrss a, const bases_t *bases, bases_t nbases, ord_t order) except -1:
    """
    Refuse a layout change (new labels or a higher truncation order) of an array with live exports.

    Parameters
    ----------
    a : oarrss
        Array about to receive a value.
    bases : bases_t *
        Sorted labels of the value.
    nbases : int
        Their number.
    order : int
        Truncation order of the value.

    Raises
    ------
    BufferError
        The value needs a relayout and a view of ``a`` is alive.
    """

    return _check_arr_growth(a, &a.arr, bases, nbases, order)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef np.ndarray _block_writeable(oarrss value, uint64_t index, ord_t order):
    """
    Internal writable path: an untracked, writable (nrows, ncols) view of one direction block.

    Library setters write through it right away and never hand it to users (contracts 11.11).

    Parameters
    ----------
    value : oarrss
        Array; the direction must be in its active set.
    index, order : int
        Global direction (order 0: the real block).

    Returns
    -------
    numpy.ndarray
        Fortran-ordered view of the C block, or an empty array for a zero-size array.
    """

    cdef coeff_t *block = oarrss_get_block(index, order, &value.arr)
    cdef np.npy_intp dims[1]
    cdef np.ndarray flat

    if block == NULL or value.arr.size == 0:

        if value.arr.size == 0:

            return np.empty((value.arr.nrows, value.arr.ncols), dtype=np.float64)

        # end if

        raise KeyError("direction is not in the array's active set")

    # end if

    dims[0] = value.arr.size
    flat = np.PyArray_SimpleNewFromData(1, dims, np.NPY_DOUBLE, <void *>block)
    np.set_array_base(flat, value)
    return flat.reshape((value.arr.nrows, value.arr.ncols), order="F")

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef bint _same_layout(const oarrss_t *a, const oarrss_t *b):
    """
    Whether two SoA arrays have the same C dimensions, labels and truncation order.

    Parameters
    ----------
    a, b : oarrss_t *
        Arrays.

    Returns
    -------
    bool
        True when one's blocks can be copied over the other's.
    """

    return (a.size == b.size and a.nbases == b.nbases and a.trc_order == b.trc_order
            and (a.nbases == 0 or memcmp(a.p_bases, b.p_bases, a.nbases * sizeof(bases_t)) == 0))

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef oarrss _as_row(oarrss value):
    """
    Copy a 1-D array into a 1 x n C array (the left operand of a 1-D product, rule I3).

    Parameters
    ----------
    value : oarrss
        Vector (stored n x 1).

    Returns
    -------
    oarrss
        2-D copy of shape (1, n).
    """

    cdef oarrss row = oarrss.wrap(oarrss_copy(&value.arr))

    row.arr.ncols = row.arr.nrows
    row.arr.nrows = 1
    return row

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef int _warn_nrows(str name) except -1:
    """
    Warn that ``nrows`` / ``ncols`` are deprecated (11.14 item 10).

    Parameters
    ----------
    name : str
        Attribute name.
    """

    _warnings.warn("{} is deprecated in pyoti 2.0; use shape".format(name), DeprecationWarning,
                   stacklevel=3)
    return 0

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef object _sparse_like(object value, int ndim):
    """
    Give a matso converted from a semi-sparse array the array's logical ndim.

    Parameters
    ----------
    value : matso
        Converted matrix (2-D C struct).
    ndim : int
        Logical ndim of the semi-sparse source.

    Returns
    -------
    matso
        ``value``.
    """

    if ndim == 2 or len(value.shape) == ndim:

        return value

    # end if

    # matso keeps its logical shape kind in _lk from 7b: 0 (nrows, ncols), 1 (n,) stored n x 1, 2 ().
    (<matso>value)._lk = 1 if ndim == 1 else 2
    return value

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef int _check_square(object value) except -1:
    """
    Raise NumPy's ``LinAlgError`` unless an array is a square matrix (``inv``, ``det``; F5).

    The messages are NumPy's (``numpy.linalg.inv``), shared with pyoti.dense and pyoti.sparse.
    ``LinAlgError`` is a ``ValueError``, so 1.x code that catches ``ValueError`` still works.

    Parameters
    ----------
    value : oarrss or arrss
        Array.

    Returns
    -------
    int
        0.
    """

    cdef int ndim = _ndim_of(value)
    cdef tuple shape

    if ndim < 2:

        raise np.linalg.LinAlgError(
            "%d-dimensional array given. Array must be at least two-dimensional" % ndim)

    # end if

    shape = value.shape

    if shape[0] != shape[1]:

        raise np.linalg.LinAlgError("Last 2 dimensions of the array must be square")

    # end if

    return 0

# end function
# --------------------------------------------------------------------------------------------------------
