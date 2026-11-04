# n-D arrays, NumPy indexing, views and read-only exports of the dense SoA class (Phase 7b).
#
# PLAN-ndarray-contracts.md section 11 (11.2 shapes, 11.3 indexing, 11.4 views, 11.5 assignment, 11.6
# growth, 11.11 exports) and 7.2-7.5; C side: include/oti/dense/soa/base.h "N-D ARRAYS (7b)".
#
#   _shape_of(value)              NumPy shape of a creator argument (int -> (n,), tuple, ())
#   _layout_of(layout)            'F' / 'C' -> ND_LAYOUT_F / ND_LAYOUT_C
#   _soa_zeros_nd(shape, ...)     zero omat of any shape, with a layout reservation (nbases=)
#   _parse_key(key, ...)          a Python key -> nd_index_t items (ints, slices, None, ..., arrays)
#   _soa_getitem / _soa_setitem   NumPy rules: scalars for full integer keys, views for basic keys,
#                                 copies for advanced keys; assignment broadcasts (S1), snapshots (S2)
#                                 and follows the growth rule (G1)
#   _soa_export(a, block, w)      one coefficient block as a NumPy array that pins the buffer
#                                 (read-only unless w; the buffer's export count fixes the layout)
#   _key_check / _assign_fail     a failed key or assignment -> the message table below

import operator as _operator
import warnings as _warnings
from cpython.long cimport PyLong_AsLongLongAndOverflow


# The messages of a bad key or assignment value, the same texts as pyoti.real.key2d (sparse, semi-sparse,
# dmat) and NumPy (W4 fix round 2, F9). A bad boolean mask or index array keeps NumPy's own text.
_KEY_BOUNDS = "index {} is out of bounds for axis {} with size {}"
_KEY_TOO_MANY = "too many indices for array: array is {}-dimensional, but {} were indexed"
_KEY_ELLIPSIS = "an index can only have a single ellipsis ('...')"
_ASSIGN_SHAPE = "slice assignment: could not broadcast input array from shape {} into shape {}"

# Saturation of an integer key component (C3): 2**62 is beyond every extent, so a huge slice bound or
# step selects what NumPy's clipping selects and a huge index stays out of range.
cdef int64_t _KEY_HUGE = 4611686018427387904


# ********************************************************************************************************
cdef tuple _shape_of(object shape):
    """
    Normalize a creator shape the way NumPy does.

    Parameters
    ----------
    shape : int or sequence of int
        An int gives a 1-D shape; a sequence its extents; ``()`` a 0-D shape.

    Returns
    -------
    tuple of int
        The shape.

    Raises
    ------
    ValueError
        A negative extent, or more than 31 axes.
    TypeError
        An extent that is not an integer.
    """

    cdef tuple dims

    if isinstance(shape, (int, np.integer)) and not isinstance(shape, (bool, np.bool_)):

        dims = (_operator.index(shape),)

    else:

        dims = tuple(_operator.index(x) for x in shape)

    # end if

    if len(dims) > OTI_ND_MAXDIM - 1:

        raise ValueError("dense arrays have at most {} dimensions".format(OTI_ND_MAXDIM - 1))

    # end if

    for x in dims:

        if x < 0:

            raise ValueError("negative dimensions are not allowed")

        # end if

    # end for

    return dims

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef object _deprecated_dim(tuple shape, int axis):
    """
    ``nrows`` / ``ncols`` of an array (deprecated in 2.0.0, contracts 11.2): the 1.x values for
    ndim <= 2 (1-D: n x 1; 0-D: 1 x 1).

    Parameters
    ----------
    shape : tuple of int
        Shape of the array.
    axis : int
        0 for nrows, 1 for ncols.

    Returns
    -------
    int
        The value.

    Raises
    ------
    AttributeError
        For an array of more than two dimensions (use ``shape``).
    """

    _warnings.warn("nrows / ncols are deprecated since pyoti 2.0.0; use shape", DeprecationWarning,
                   stacklevel=3)

    if len(shape) > 2:

        raise AttributeError("nrows / ncols are not defined for arrays of more than two dimensions; "
                             "use shape")

    # end if

    if len(shape) == 2:

        return shape[axis]

    # end if

    if len(shape) == 1 and axis == 0:

        return shape[0]

    # end if

    return 1

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef int32_t _layout_of(object layout) except -1:
    """
    Memory-layout keyword of the creators (``layout=``, decision 9).

    Parameters
    ----------
    layout : str
        ``'F'`` (column-major inside each block, the SoA default) or ``'C'``.

    Returns
    -------
    int
        ND_LAYOUT_F or ND_LAYOUT_C.
    """

    if layout == "F" or layout == "f":

        return ND_LAYOUT_F

    # end if

    if layout == "C" or layout == "c":

        return ND_LAYOUT_C

    # end if

    raise ValueError("layout must be 'C' or 'F', not {!r}".format(layout))

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef omat _soa_zeros_nd(tuple shape, bases_t nact, ord_t order, int32_t layout=ND_LAYOUT_F):
    """
    Create a zero SoA array of any shape over the bases 1..nact (a layout reservation, contracts 7.5).

    Parameters
    ----------
    shape : tuple of int
        Element shape.
    nact : int
        Number of active bases of the layout.
    order : int
        Truncation order.
    layout : int
        ND_LAYOUT_F or ND_LAYOUT_C.

    Returns
    -------
    omat
        Zero array.
    """

    cdef int64_t dims[OTI_ND_MAXDIM]
    cdef omat result
    cdef int32_t d, ndim = len(shape)

    for d in range(ndim):

        dims[d] = shape[d]

    # end for

    result = omat.__new__(omat)
    _soa_ok("zeros", oarr_zeros_nd_to(nact, ndim, dims, layout, order, &result.arr), &result.arr)
    return result

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef omat _soa_from_numpy(object data, ord_t order, int32_t layout=ND_LAYOUT_F):
    """
    Build a real SoA array (no bases) from a real array of any shape (a copy).

    Parameters
    ----------
    data : array_like
        Real values.
    order : int
        Truncation order.
    layout : int
        ND_LAYOUT_F or ND_LAYOUT_C.

    Returns
    -------
    omat
        The array, of the input's shape.
    """

    cdef np.ndarray values = np.asarray(data, dtype=np.float64)
    cdef int64_t dims[OTI_ND_MAXDIM]
    cdef int64_t strides[OTI_ND_MAXDIM]
    cdef ndarr_t view
    cdef omat result
    cdef int32_t d, ndim = values.ndim

    if ndim > OTI_ND_MAXDIM - 1:

        raise ValueError("dense arrays have at most {} dimensions".format(OTI_ND_MAXDIM - 1))

    # end if

    # Any strides (in elements) are fine; a byte stride that is not a multiple of 8 is not.
    if any(st % 8 != 0 for st in (<object>values).strides):

        values = values.copy(order="C")

    # end if

    for d in range(ndim):

        dims[d]    = values.shape[d]
        strides[d] = values.strides[d] // 8

    # end for

    nd_init_empty(&view)
    _status("array", nd_wrap_trusted(<void *>values.data if values.size > 0 else NULL, OTI_F64, ndim,
                                     dims, strides, 0, &view))
    result = omat.__new__(omat)
    _soa_ok("array", oarr_from_real_nd_to(&view, order, layout, &result.arr), &result.arr)
    return result

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef class _KeyArray:
    """
    An index array of a key (int64 indices or a uint8 mask) and the descriptor that borrows it.
    """

    cdef ndarr_t desc
    cdef object data

# end class
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef _KeyArray _key_array(object obj):
    """
    Wrap an advanced index (integer array, boolean mask, list, boolean scalar) for nd_index_t.

    Parameters
    ----------
    obj : object
        Index object.

    Returns
    -------
    _KeyArray
        Holder whose ``desc`` describes the index.
    """

    cdef _KeyArray holder = _KeyArray.__new__(_KeyArray)
    cdef np.ndarray values = np.asarray(obj)
    cdef int64_t dims[OTI_ND_MAXDIM]
    cdef int64_t strides[OTI_ND_MAXDIM]
    cdef int32_t d, dtype

    if values.dtype == np.bool_:

        values = np.ascontiguousarray(values, dtype=np.uint8)
        dtype  = OTI_U8

    elif values.size == 0 and values.dtype != np.int64:

        # An empty list is an empty integer index (NumPy).
        values = np.ascontiguousarray(values, dtype=np.int64)
        dtype  = OTI_I64

    elif np.issubdtype(values.dtype, np.integer):

        values = np.ascontiguousarray(values, dtype=np.int64)
        dtype  = OTI_I64

    else:

        raise IndexError("arrays used as indices must be of integer (or boolean) type")

    # end if

    if values.ndim > OTI_ND_MAXDIM:

        raise IndexError("index array has too many dimensions")

    # end if

    for d in range(values.ndim):

        dims[d]    = values.shape[d]
        strides[d] = values.strides[d] // values.itemsize

    # end for

    holder.data = values
    nd_init_empty(&holder.desc)
    _status("index", nd_wrap_trusted(<void *>values.data if values.size > 0 else NULL, dtype, values.ndim,
                                     dims, strides, 0, &holder.desc))
    return holder

# end function
# --------------------------------------------------------------------------------------------------------


# Flags of _parse_key: the key has an advanced item; every item is an integer; a boolean scalar.
cdef enum:
    _KEY_ADVANCED = 1
    _KEY_ALL_INT = 2
    _KEY_BOOL0 = 4

cdef enum:
    _MAX_KEY = 64


# ********************************************************************************************************
cdef inline int64_t _key_i64(object value) except? -1:
    """
    An integer key component as int64, saturated at +-2**62 (C3; no OverflowError).

    Parameters
    ----------
    value : int
        A Python integer (``operator.index`` already applied).

    Returns
    -------
    int
        The value, or +-2**62 when it is beyond.
    """

    cdef int overflow = 0
    cdef long long v = PyLong_AsLongLongAndOverflow(value, &overflow)

    if overflow > 0 or v > _KEY_HUGE:

        return _KEY_HUGE

    # end if

    if overflow < 0 or v < -_KEY_HUGE:

        return -_KEY_HUGE

    # end if

    return v

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef inline bint _is_bool0(object obj):
    """
    Tell whether a key item is a boolean scalar (NumPy: a 0-D mask, a new axis of extent 1 or 0).

    Parameters
    ----------
    obj : object
        Key item.

    Returns
    -------
    bool
        True for ``True``, ``False``, ``numpy.bool_`` and a 0-D boolean array.
    """

    return isinstance(obj, (bool, np.bool_)) or (
        isinstance(obj, np.ndarray) and (<np.ndarray>obj).ndim == 0 and obj.dtype == np.bool_)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef Py_ssize_t _key_axes(object obj):
    """
    The number of array axes a key item (not an ellipsis) consumes, by NumPy's rules.

    Parameters
    ----------
    obj : object
        Key item.

    Returns
    -------
    int
        0 for None and a boolean scalar, the mask's ndim for a boolean array, 1 otherwise.
    """

    cdef np.ndarray values

    if obj is None or _is_bool0(obj):

        return 0

    # end if

    if isinstance(obj, (list, np.ndarray)):

        values = np.asarray(obj)
        return values.ndim if values.dtype == np.bool_ else 1

    # end if

    return 1

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef object _key_stand(tuple shape):
    """
    A zero-stride NumPy stand-in of an array shape (no allocation): NumPy indexes it with its own rules.

    Parameters
    ----------
    shape : tuple of int
        Array shape.

    Returns
    -------
    numpy.ndarray
        Read-only uint8 array of that shape.
    """

    return np.lib.stride_tricks.as_strided(np.zeros(1, dtype=np.uint8), shape=shape,
                                           strides=(0,) * len(shape), writeable=False)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef int _key_check(tuple shape, object key, bint arrays=True) except -1:
    """
    Raise the message-table IndexError for the first fault of a key on an array of ``shape``.

    Only called after a native index call failed (no cost on the success path). Integers are checked
    here (a huge one included, with the axis it indexes); masks and index arrays by NumPy on a stand-in.

    Parameters
    ----------
    shape : tuple of int
        Shape of the indexed array.
    key : object
        The key (its items already passed _parse_key).
    arrays : bool
        Also let NumPy check the masks and index arrays (False: the basic items only).

    Returns
    -------
    int
        0 when no fault is found (the caller raises its native status).

    Raises
    ------
    IndexError
        Two ellipses, too many indices, an integer out of range, or a bad mask / index array.
    """

    cdef tuple parts = key if type(key) is tuple else (key,)
    cdef Py_ssize_t nd = len(shape)
    cdef Py_ssize_t used = 0
    cdef Py_ssize_t nell = 0
    cdef Py_ssize_t ax = 0
    cdef bint advanced = False

    for obj in parts:

        if obj is Ellipsis:

            nell += 1

        else:

            used += _key_axes(obj)
            advanced = advanced or (isinstance(obj, (list, np.ndarray)) and not _is_bool0(obj))

        # end if

    # end for

    if nell > 1:

        raise IndexError(_KEY_ELLIPSIS)

    # end if

    if used > nd:

        raise IndexError(_KEY_TOO_MANY.format(nd, used))

    # end if

    for obj in parts:

        if obj is Ellipsis:

            ax += nd - used

        elif obj is None or isinstance(obj, (slice, list, np.ndarray, bool, np.bool_)):

            ax += _key_axes(obj)

        else:

            try:

                index = _operator.index(obj)

            except TypeError:

                return 0    # not an index: the caller's own error

            # end try

            if index < -shape[ax] or index >= shape[ax]:

                raise IndexError(_KEY_BOUNDS.format(index, ax, shape[ax]))

            # end if

            ax += 1

        # end if

    # end for

    if advanced and arrays:

        _key_stand(shape)[key]

    # end if

    return 0

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef int _key_fail(tuple shape, object key, str operation, int status) except -1:
    """
    Raise the exception of a failed native index call: the message table for a key fault, else the
    native status.

    Parameters
    ----------
    shape : tuple of int
        Shape of the indexed array.
    key : object
        The key.
    operation : str
        Name of the operation.
    status : int
        Native status (not DN_OK).
    """

    if status == DN_ERR_INDEX or status == DN_ERR_SIZE or status == OTI_ERR_SHAPE:

        _key_check(shape, key)

    # end if

    _status(operation, status)
    return -1

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef int _assign_fail(tuple shape, object key, tuple vshape, int status) except -1:
    """
    Raise the exception of a failed assignment ``A[key] = value``: a key fault or a value that does not
    broadcast to ``A[key]`` gets the message table's text, anything else the native status.

    Parameters
    ----------
    shape : tuple of int
        Shape of the target array.
    key : object
        The key.
    vshape : tuple of int
        Shape of the value.
    status : int
        Native status (not DN_OK).
    """

    if status == DN_ERR_INDEX:

        _key_check(shape, key)

    elif status == DN_ERR_SIZE or status == OTI_ERR_SHAPE:

        _key_check(shape, key)
        raise ValueError(_ASSIGN_SHAPE.format(vshape, np.shape(_key_stand(shape)[key])))

    # end if

    _status("setitem", status)
    return -1

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef tuple _bool_key(tuple shape, object key):
    """
    Rewrite a key with boolean scalars as NumPy reads it: each one is a new axis of extent 1 (True) or 0
    (False) at its place, an advanced index (the result is a copy).

    The array is viewed with a unit axis inserted at the place of each boolean (a basic key), and each
    boolean becomes the index array [0] or [] on its unit axis.

    Parameters
    ----------
    shape : tuple of int
        Shape of the indexed array.
    key : object
        The key (at least one boolean scalar).

    Returns
    -------
    tuple
        ``(view_key, new_key)``.
    """

    cdef tuple parts = key if type(key) is tuple else (key,)
    cdef Py_ssize_t nd = len(shape)
    cdef Py_ssize_t used = 0
    cdef Py_ssize_t ax = 0
    cdef Py_ssize_t i
    cdef list at = []
    cdef list new = []
    cdef list view = []

    # The basic items against the array's own axes (a bad index array fails on the view, by NumPy).
    _key_check(shape, key, False)

    for obj in parts:

        if obj is not Ellipsis:

            used += _key_axes(obj)

        # end if

    # end for

    for obj in parts:

        if _is_bool0(obj):

            at.append(ax)
            new.append(np.zeros(1 if obj else 0, dtype=np.int64))
            continue

        # end if

        new.append(obj)
        ax += (nd - used) if obj is Ellipsis else _key_axes(obj)

    # end for

    for i in range(nd + 1):

        view.extend([None] * at.count(i))

        if i < nd:

            view.append(slice(None))

        # end if

    # end for

    return tuple(view), tuple(new)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef int32_t _parse_key(object key, nd_index_t* items, list holders, int* flags) except -1:
    """
    Turn a NumPy key into nd_index_t items (basic: integers, slices, None, one Ellipsis; advanced:
    integer arrays, boolean masks, lists, boolean scalars).

    Parameters
    ----------
    key : object
        The key of ``A[key]``.
    items : nd_index_t *
        At least 64 items.
    holders : list
        Receives the index arrays the items borrow (keep it alive while the items are used).
    flags : int *
        _KEY_ADVANCED, _KEY_ALL_INT and _KEY_BOOL0 (a boolean scalar: the caller uses _bool_key) bits.

    Returns
    -------
    int
        Number of items.

    Raises
    ------
    IndexError
        A float, string or other key that is not an index (NumPy), or more than 64 items.
    """

    cdef tuple parts
    cdef int32_t n = 0
    cdef nd_index_t* item
    cdef _KeyArray holder

    flags[0] = _KEY_ALL_INT

    if type(key) is tuple:

        parts = <tuple>key

    else:

        parts = (key,)

    # end if

    if len(parts) > _MAX_KEY:

        raise IndexError("too many indices for array")

    # end if

    for obj in parts:

        item       = &items[n]
        item.has   = 0
        item.start = 0
        item.stop  = 0
        item.step  = 0
        item.arr   = NULL

        if type(obj) is int:

            item.kind  = ND_IDX_INT
            item.start = _key_i64(obj)
            n += 1
            continue

        # end if

        flags[0] &= ~_KEY_ALL_INT

        if obj is None:

            item.kind = ND_IDX_NEWAXIS

        elif obj is Ellipsis:

            item.kind = ND_IDX_ELLIPSIS

        elif isinstance(obj, slice):

            item.kind = ND_IDX_SLICE

            try:

                # Saturated components select what NumPy's clipping selects (C3).
                if (<slice>obj).start is not None:

                    item.has  |= ND_HAS_START
                    item.start = _key_i64(_operator.index((<slice>obj).start))

                # end if

                if (<slice>obj).stop is not None:

                    item.has |= ND_HAS_STOP
                    item.stop = _key_i64(_operator.index((<slice>obj).stop))

                # end if

                if (<slice>obj).step is not None:

                    item.has |= ND_HAS_STEP
                    item.step = _key_i64(_operator.index((<slice>obj).step))

                    if item.step == 0:

                        raise ValueError("slice step cannot be zero")

                    # end if

                # end if

            except TypeError:

                raise IndexError("slice indices must be integers or None or have an __index__ method")

            # end try

        elif _is_bool0(obj):

            # A boolean scalar: the caller rewrites the key (_bool_key); a placeholder item here.
            item.kind = ND_IDX_NEWAXIS
            flags[0] |= _KEY_BOOL0 | _KEY_ADVANCED

        elif isinstance(obj, (list, np.ndarray)):

            holder = _key_array(obj)
            holders.append(holder)
            item.kind = ND_IDX_ARRAY
            item.arr  = &holder.desc
            flags[0] |= _KEY_ADVANCED

        else:

            try:

                item.start = _key_i64(_operator.index(obj))

            except TypeError:

                raise IndexError("only integers, slices (`:`), ellipsis (`...`), numpy.newaxis (`None`) "
                                 "and integer or boolean arrays are valid indices")

            # end try

            item.kind = ND_IDX_INT
            flags[0] |= _KEY_ALL_INT

        # end if

        n += 1

    # end for

    # _KEY_ALL_INT survives only when no other kind of item was seen.
    for d in range(n):

        if items[d].kind != ND_IDX_INT:

            flags[0] &= ~_KEY_ALL_INT
            break

        # end if

    # end for

    return n

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef object _soa_getitem(omat a, object key):
    """
    ``A[key]`` with NumPy's rules (contracts 11.3 I1, 11.4 V1): one integer per axis gives an OTI
    scalar (a copy), a basic key gives a view sharing the array's buffer and layout, a key with an
    advanced item gives a copy.

    Parameters
    ----------
    a : omat
        Source array.
    key : object
        Index key.

    Returns
    -------
    otinum or omat
        Scalar copy, view or copy.

    Raises
    ------
    IndexError
        A bad key, with the message table's text (_key_check).
    """

    cdef nd_index_t items[_MAX_KEY]
    cdef int64_t index[OTI_ND_MAXDIM]
    cdef list holders = []
    cdef int flags, status
    cdef int32_t n, d
    cdef otinum element
    cdef omat result

    n = _parse_key(key, items, holders, &flags)

    if flags & _KEY_BOOL0:

        # A boolean scalar (F13): a unit axis viewed in, then indexed with [0] or [] (a copy).
        view_key, new_key = _bool_key(a.shape, key)
        return _soa_getitem(<omat>_soa_getitem(a, view_key), new_key)

    # end if

    if (flags & _KEY_ALL_INT) and n == oarr_ndim(&a.arr):

        for d in range(n):

            index[d] = items[d].start

        # end for

        element = otinum.__new__(otinum)
        status  = oarr_get_elem_to(&a.arr, n, index, &element.num)

        if status != DN_OK:

            _key_fail(a.shape, key, "getitem", status)

        # end if

        return element

    # end if

    # The C call writes the copy or the retained view straight into the result object.
    result = omat.__new__(omat)

    if flags & _KEY_ADVANCED:

        status = oarr_index_get_to(&a.arr, n, items, &result.arr)

    else:

        status = oarr_view_index(&a.arr, n, items, &result.arr)

    # end if

    if status != DN_OK:

        oarr_free(&result.arr)
        _key_fail(a.shape, key, "getitem", status)

    # end if

    return result

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef omat _soa_value(object value):
    """
    The value of an assignment as an omat (anything an omat can be built from).

    Parameters
    ----------
    value : object
        omat, arro, matso, NumPy array, nested list, or OTI scalar of another algebra.

    Returns
    -------
    omat
        The value (the object itself when it already is an omat).
    """

    if isinstance(value, omat):

        return value

    # end if

    if isinstance(value, arro):

        return _to_soa(value)

    # end if

    if isinstance(value, matso):

        return _soa_from_matso(value)

    # end if

    if isinstance(value, sotinum):

        return _soa_value(otinum(value))

    # end if

    if isinstance(value, np.ndarray) and value.dtype != object:

        return _soa_from_numpy(value, 0)

    # end if

    if isinstance(value, _dnfe):

        raise TypeError("a Gauss value cannot be assigned into a plain array; use get_ip / set_ip")

    # end if

    return array(value)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef int _soa_setitem(omat a, object key, object value) except -1:
    """
    ``A[key] = value`` with NumPy's rules (contracts 11.5): the value broadcasts to the shape
    ``A[key]`` has (S1; leading axes of extent 1 dropped), an overlapping value is a snapshot (S2),
    and the growth rule G1 applies: a root nobody shares grows to hold the value's truncation order
    and bases, a view or a root with live views or exports must already hold them (BufferError).

    Parameters
    ----------
    a : omat
        Target array (root or view).
    key : object
        Index key.
    value : object
        Real, OTI scalar, array (dense, AoS, sparse, NumPy) or nested list.

    Raises
    ------
    IndexError
        A bad key (_key_check).
    ValueError
        A value that does not broadcast to ``A[key]`` (the message table's text).
    """

    cdef nd_index_t items[_MAX_KEY]
    cdef list holders = []
    cdef int flags, status
    cdef int32_t n
    cdef type kind = type(value)
    cdef omat source

    if not a.FLAGS & 1:

        raise ValueError("this array is a view of another object and cannot be modified")

    # end if

    n = _parse_key(key, items, holders, &flags)

    if flags & _KEY_BOOL0:

        return _soa_bool_setitem(a, key, value)

    # end if

    if kind is float or kind is int:

        status = oarr_index_set_r(&a.arr, n, items, value)

    elif kind is otinum:

        status = oarr_index_set_o(&a.arr, n, items, &(<otinum>value).num)

    elif isinstance(value, Real) and not isinstance(value, np.ndarray):

        status = oarr_index_set_r(&a.arr, n, items, float(value))

    else:

        source = _soa_value(value)
        status = oarr_index_set(&a.arr, n, items, &source.arr)

        if status != DN_OK:

            _assign_fail(a.shape, key, source.shape, status)

        # end if

        return 0

    # end if

    if status != DN_OK:

        _assign_fail(a.shape, key, (), status)

    # end if

    return 0

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef int _soa_bool_setitem(omat a, object key, object value) except -1:
    """
    ``A[key] = value`` for a key with boolean scalars (F13, NumPy): written through the view of
    _bool_key. The target grows first (rule G1), since a write through a view cannot grow it.

    Parameters
    ----------
    a : omat
        Target array.
    key : object
        Index key with at least one boolean scalar.
    value : object
        Assignment value.
    """

    cdef bases_t k = oarr_nact(&a.arr)
    cdef ord_t trc = oarr_trc_order(&a.arr)
    cdef omat source

    view_key, new_key = _bool_key(a.shape, key)

    if isinstance(value, otinum):

        k   = max(k, (<otinum>value).num.nact)
        trc = max(trc, (<otinum>value).num.trc_order)

    elif not isinstance(value, Real) or isinstance(value, np.ndarray):

        source = _soa_value(value)
        value  = source
        k      = max(k, oarr_nact(&source.arr))
        trc    = max(trc, oarr_trc_order(&source.arr))

    # end if

    _status("setitem", oarr_grow_layout(&a.arr, k, trc))
    return _soa_setitem(<omat>_soa_getitem(a, view_key), new_key, value)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef object _arr_export(oarr_t* arr, int64_t block, bint writeable):
    """
    One coefficient block of a dense C array as a NumPy array sharing its memory (contracts 11.11).

    The array pins the buffer (an export): while it lives the layout of the root is fixed (growth
    raises BufferError). Read-only unless ``writeable``.

    Parameters
    ----------
    arr : oarr_t *
        Source array (root, view, or the embedded array of a Gauss value).
    block : int
        Block index (0: the real part).
    writeable : bool
        Writable export (internal writers, ``get_block(..., writeable=True)``).

    Returns
    -------
    numpy.ndarray
        Array of the element shape, with the array's strides.
    """

    cdef ndarr_t desc = oarr_blocks(arr)[0]
    cdef int32_t d

    desc.flags &= ~(ND_RETAINED | ND_EXPORTED)

    if desc.data != NULL:

        desc.data = <void *>(<coeff_t *>desc.data + block * desc.strides[0])

    # end if

    for d in range(desc.ndim - 1):

        desc.shape[d]   = desc.shape[d + 1]
        desc.strides[d] = desc.strides[d + 1]

    # end for

    desc.ndim -= 1
    nd_update_flags(&desc)
    return nd_to_numpy(&desc, 1 if writeable else 0)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef object _soa_export(omat a, int64_t block, bint writeable):
    """
    One coefficient block of a SoA array as a NumPy array sharing its memory (_arr_export()).

    Parameters
    ----------
    a : omat
        Source array.
    block : int
        Block index (0: the real part).
    writeable : bool
        Writable export.

    Returns
    -------
    numpy.ndarray
        Array of the element shape, with the array's strides.
    """

    return _arr_export(&a.arr, block, writeable)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef object _block_writeable(omat a, int64_t block):
    """
    The internal writable path (contracts 11.11): a writable export of one block for library setters,
    never returned to users. The caller sets act_order itself.

    Parameters
    ----------
    a : omat
        Array.
    block : int
        Block index.

    Returns
    -------
    numpy.ndarray
        Writable view of the block.
    """

    return _soa_export(a, block, True)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _soa_iter(omat a):
    """
    Iterate over the first axis (contracts 11.3 I2): views of ndim - 1 for an n-D array, OTI scalars
    for a 1-D array.

    Parameters
    ----------
    a : omat
        Array with ndim >= 1.

    Yields
    ------
    omat or otinum
        ``a[0], a[1], ...``.
    """

    for i in range(oarr_shape(&a.arr, 0)):

        yield _soa_getitem(a, i)

    # end for

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef omat _soa_reshape(omat a, object shape, object order):
    """
    ``A.reshape(shape)``: a view when the strides allow it, else a copy (contracts 11.4).

    Parameters
    ----------
    a : omat
        Array.
    shape : int or tuple of int
        New shape (one -1 allowed).
    order : str
        Index order, ``'C'`` (default) or ``'F'``.

    Returns
    -------
    omat
        View or copy.
    """

    cdef int64_t dims[OTI_ND_MAXDIM]
    cdef tuple target
    cdef int32_t d, ndim, layout = _layout_of(order)
    cdef omat result
    cdef int status

    if isinstance(shape, (int, np.integer)):

        target = (_operator.index(shape),)

    else:

        target = tuple(_operator.index(x) for x in shape)

    # end if

    ndim = len(target)

    if ndim > OTI_ND_MAXDIM - 1:

        raise ValueError("dense arrays have at most {} dimensions".format(OTI_ND_MAXDIM - 1))

    # end if

    for d in range(ndim):

        dims[d] = target[d]

    # end for

    result = omat.__new__(omat)
    status = oarr_view_reshape(&a.arr, ndim, dims, layout, &result.arr)

    if status == DN_OK:

        return result

    # end if

    if status != OTI_ERR_LAYOUT:

        _soa_ok("reshape", status, &result.arr)

    # end if

    _soa_ok("reshape", oarr_reshape_copy_to(&a.arr, ndim, dims, layout, &result.arr), &result.arr)
    return result

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef int _soa_relabel(omat a, tuple shape) except -1:
    """
    Give a fresh root (a `_to` result, compact in F order) a new shape of the same size in place.

    Parameters
    ----------
    a : omat
        Fresh root.
    shape : tuple of int
        New shape.
    """

    cdef int64_t dims[OTI_ND_MAXDIM]
    cdef int32_t d

    for d in range(len(shape)):

        dims[d] = shape[d]

    # end for

    _status("reshape", oarr_reshape_root(&a.arr, len(shape), dims))
    return 0

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef tuple _batch_index(tuple index, tuple shape):
    """
    The index of one batch item of an operand that broadcasts to the batch (NumPy rules).

    Parameters
    ----------
    index : tuple of int
        Index in the broadcast batch.
    shape : tuple of int
        The operand's batch shape.

    Returns
    -------
    tuple of int
        Index into the operand's batch axes (0 on its axes of extent 1).
    """

    cdef Py_ssize_t skip = len(index) - len(shape)

    return tuple([0 if shape[d] == 1 else index[skip + d] for d in range(len(shape))])

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef omat _soa_batched(object fn, omat a, omat b, Py_ssize_t ka, Py_ssize_t kb, tuple tail):
    """
    Apply a 2-D product or solve over broadcast batch axes (an explicit loop over the batch).

    Parameters
    ----------
    fn : callable
        fn(a2d, b2d) -> omat of shape ``tail``.
    a, b : omat
        Operands with ``ka`` / ``kb`` trailing core axes.
    ka, kb : int
        Number of core axes of a and b.
    tail : tuple of int
        Shape of one result item.

    Returns
    -------
    omat
        Result of shape batch + tail.
    """

    cdef tuple abatch = a.shape[:a.ndim - ka]
    cdef tuple bbatch = b.shape[:b.ndim - kb]
    cdef tuple batch = tuple(np.broadcast_shapes(abatch, bbatch))
    cdef list items = []
    cdef bases_t k = 0
    cdef ord_t trc = 0
    cdef omat out, item

    for index in np.ndindex(batch):

        item = fn(a[_batch_index(index, abatch) + (Ellipsis,)],
                  b[_batch_index(index, bbatch) + (Ellipsis,)])
        k = max(k, oarr_nact(&item.arr))
        trc = max(trc, oarr_trc_order(&item.arr))
        items.append((index, item))

    # end for

    out = _soa_zeros_nd(batch + tail, k, trc)

    for index, item in items:

        out[index + (Ellipsis,)] = item

    # end for

    return out

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _soa_matmul2(omat a, omat b):
    """
    Product of two 2-D arrays (the C kernel).

    Parameters
    ----------
    a, b : omat
        Matrices with a.shape[1] == b.shape[0].

    Returns
    -------
    omat
        Product.
    """

    cdef omat result

    if oarr_shape(&a.arr, 1) != oarr_shape(&b.arr, 0):

        raise ValueError("matmul: mismatch in the contracted dimension ({} is different from {})".format(
            oarr_shape(&a.arr, 1), oarr_shape(&b.arr, 0)))

    # end if

    result = omat.__new__(omat)
    _soa_ok("matmul", oarr_matmul_OO_to(&a.arr, &b.arr, &result.arr, _dhl), &result.arr)
    return result

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef object _soa_matmul(omat a, omat b, bint dot_rules):
    """
    ``a @ b`` with numpy.matmul's rules (contracts 11.3 I3): a 1-D left operand is a row, a 1-D right
    operand a column, and the promoted axis is removed (1-D @ 1-D is an OTI scalar); batch axes
    broadcast. With ``dot_rules`` (numpy.dot) a 0-D operand multiplies and ndim > 2 is refused.

    Parameters
    ----------
    a, b : omat
        Operands.
    dot_rules : bool
        numpy.dot instead of numpy.matmul.

    Returns
    -------
    omat or otinum
        The product.
    """

    cdef int32_t na = oarr_ndim(&a.arr), nb = oarr_ndim(&b.arr)
    cdef omat A, B, r
    cdef tuple shape

    if na == 0 or nb == 0:

        if dot_rules:

            return a * b

        # end if

        raise ValueError("matmul: an operand has no dimensions (use *)")

    # end if

    if dot_rules and (na > 2 or nb > 2):

        raise ValueError("dot: arrays of more than two dimensions are not supported; use matmul")

    # end if

    A = a[None, :] if na == 1 else a
    B = b[:, None] if nb == 1 else b

    if A.ndim == 2 and B.ndim == 2:

        r = _soa_matmul2(A, B)

    else:

        if A.shape[-1] != B.shape[-2]:

            raise ValueError("matmul: mismatch in the contracted dimension")

        # end if

        r = _soa_batched(_soa_matmul2, A, B, 2, 2, (A.shape[-2], B.shape[-1]))

    # end if

    if na == 1 and nb == 1:

        return r[(0,) * r.ndim]

    # end if

    if na == 1:

        shape = r.shape[:-2] + (r.shape[-1],)
        _soa_relabel(r, shape)

    elif nb == 1:

        _soa_relabel(r, r.shape[:-1])

    # end if

    return r

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _soa_solve2(omat K, omat b):
    """
    Solve one square system with 2-D right-hand sides (the C solver).

    Parameters
    ----------
    K : omat
        Square matrix.
    b : omat
        Right-hand sides (n, k).

    Returns
    -------
    omat
        Solution (n, k).
    """

    cdef omat result

    # Shapes read in C (no Python property reads per call).
    if (oarr_ndim(&K.arr) != 2 or oarr_ndim(&b.arr) != 2 or oarr_shape(&K.arr, 0) != oarr_shape(&K.arr, 1)
            or oarr_shape(&b.arr, 0) != oarr_shape(&K.arr, 0)):

        raise ValueError("solve: matrix must be square and match the right-hand-side rows")

    # end if

    result = omat.__new__(omat)
    _soa_ok("solve", oarr_solve_to(&K.arr, &b.arr, &result.arr, _dhl), &result.arr)
    return result

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef omat _soa_solve(omat K, omat b):
    """
    ``solve(K, b)`` with NumPy 2's ``linalg.solve`` rule (contracts 11.3): a 1-D ``b`` is one vector
    broadcast against the batch axes of K (result (..., n)); otherwise ``b`` is (..., n, k) and the
    batch axes broadcast (result (..., n, k)).

    Parameters
    ----------
    K : omat
        Matrices (..., n, n).
    b : omat
        Right-hand side.

    Returns
    -------
    omat
        Solution.
    """

    cdef int32_t kd = oarr_ndim(&K.arr), bd = oarr_ndim(&b.arr)
    cdef bint vector = bd == 1
    cdef int64_t n
    cdef oarr_t col
    cdef omat B, r
    cdef int status

    if kd < 2 or oarr_shape(&K.arr, kd - 1) != oarr_shape(&K.arr, kd - 2):

        raise ValueError("solve: the matrix must be square in its last two dimensions")

    # end if

    if bd == 0:

        raise ValueError("solve: the right-hand side needs at least one dimension")

    # end if

    # One system, the common case (the pattern of inv): shapes read in C, one C call.
    if kd == 2 and bd <= 2:

        n = oarr_shape(&K.arr, 0)

        if oarr_shape(&b.arr, 0) != n:

            raise ValueError("solve: matrix must be square and match the right-hand-side rows")

        # end if

        r = omat.__new__(omat)

        if not vector:

            _soa_ok("solve", oarr_solve_to(&K.arr, &b.arr, &r.arr, _dhl), &r.arr)
            return r

        # end if

        # A 1-D b through an n x 1 temporary matrix view of it (no reference taken; b canonical), the
        # (n, 1) result relabelled (n,) in place. A strided 1-D view takes the general path below.
        col = oarr_init()

        if oarr_view_matrix(&b.arr, <uint64_t>n, 1, &col) == DN_OK:

            status = oarr_solve_to(&K.arr, &col, &r.arr, _dhl)
            oarr_free(&col)

            if status == DN_OK:

                status = oarr_reshape_root(&r.arr, 1, &n)

            # end if

            _soa_ok("solve", status, &r.arr)
            return r

        # end if

    # end if

    B = b[:, None] if vector else b

    if K.ndim == 2 and B.ndim == 2:

        r = _soa_solve2(K, B)

    else:

        r = _soa_batched(_soa_solve2, K, B, 2, 2, (K.shape[-1], B.shape[-1]))

    # end if

    if vector:

        _soa_relabel(r, r.shape[:-1])

    # end if

    return r

# end function
# --------------------------------------------------------------------------------------------------------


#-----------------------------------------------------------------------------------------------------
#--------------------------------------   AoS (arro)   ---------------------------------------------
#-----------------------------------------------------------------------------------------------------
# NumPy indexing of the AoS class (contracts 11.1, 11.4: slices are COPIES): a key selects positions of
# an index grid np.arange(size).reshape(shape) (NumPy's own rules, advanced keys included); the selected
# elements are copied. Full integer keys are an O(1) fast path.


# ********************************************************************************************************
cdef int64_t _aos_flat(arro a, object key) except -2:
    """
    The flat (row-major) position of a full integer key, or -1 when the key is not one integer per axis.

    Parameters
    ----------
    a : arro
        Array.
    key : object
        Index key.

    Returns
    -------
    int
        Position, or -1.

    Raises
    ------
    IndexError
        An integer out of range.
    """

    cdef tuple parts = key if type(key) is tuple else (key,)
    cdef int32_t d, ndim = arro_ndim(&a.arr)
    cdef int64_t flat = 0, i, n

    if len(parts) != ndim:

        return -1

    # end if

    for d in range(ndim):

        if type(parts[d]) is not int:

            return -1

        # end if

    # end for

    for d in range(ndim):

        n = arro_shape(&a.arr, d)
        i = _key_i64(parts[d])

        if i < 0:

            i += n

        # end if

        if i < 0 or i >= n:

            raise IndexError(_KEY_BOUNDS.format(parts[d], d, n))

        # end if

        flat = flat * n + i

    # end for

    return flat

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef arro _aos_gather(arro a, object positions):
    """
    A new AoS array of the shape of ``positions`` holding copies of the elements at those flat positions.

    Parameters
    ----------
    a : arro
        Source array.
    positions : numpy.ndarray
        Integer array of flat positions.

    Returns
    -------
    arro
        The copy.
    """

    cdef np.ndarray flat = np.ascontiguousarray(np.ravel(positions), dtype=np.int64)
    cdef tuple shape = tuple(np.shape(positions))
    cdef int64_t dims[OTI_ND_MAXDIM]
    cdef const int64_t[::1] pos = flat
    cdef arro_t native = arro_init()
    cdef arro result
    cdef Py_ssize_t e
    cdef int32_t d

    for d in range(len(shape)):

        dims[d] = shape[d]

    # end for

    _aos_ok("getitem", arro_zeros_nd_to(len(shape), dims, 0, &native), &native)
    result = arro.wrap(native)

    for e in range(pos.shape[0]):

        _status("getitem", oti_copy_to(&arro_data(&a.arr)[pos[e]], &arro_data(&result.arr)[e]))

    # end for

    return result

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef object _aos_grid(arro a):
    """
    The index grid of an AoS array: np.arange(size).reshape(shape).

    Parameters
    ----------
    a : arro
        Array.

    Returns
    -------
    numpy.ndarray
        Flat positions in the array's shape.
    """

    return np.arange(arro_size(&a.arr), dtype=np.int64).reshape(a.shape)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef object _aos_getitem(arro a, object key):
    """
    ``A[key]`` of an AoS array with NumPy's rules; the result is a copy (contracts 11.4).

    Parameters
    ----------
    a : arro
        Source array.
    key : object
        Index key.

    Returns
    -------
    otinum or arro
        Element copy for a full integer key, otherwise a new array of copies.
    """

    cdef int64_t flat = _aos_flat(a, key)
    cdef otinum element
    cdef object positions

    if flat >= 0:

        element = otinum.__new__(otinum)
        _status("getitem", oti_copy_to(&arro_data(&a.arr)[flat], &element.num))
        return element

    # end if

    try:

        positions = _aos_grid(a)[key]

    except (TypeError, ValueError, OverflowError, IndexError) as error:

        # The message table first (an integer out of range, a huge one included), else NumPy's text.
        _key_check(a.shape, key)
        raise IndexError(str(error))

    # end try

    if np.ndim(positions) == 0 and not isinstance(positions, np.ndarray):

        element = otinum.__new__(otinum)
        _status("getitem", oti_copy_to(&arro_data(&a.arr)[<int64_t>positions], &element.num))
        return element

    # end if

    return _aos_gather(a, positions)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef int _aos_setitem(arro a, object key, object value) except -1:
    """
    ``A[key] = value`` of an AoS array with NumPy's rules: the value broadcasts to the selected shape
    (leading axes of extent 1 dropped), an array value is copied first (snapshot), and every selected
    element becomes a copy of its value element (with that value's truncation order and bases).

    Parameters
    ----------
    a : arro
        Target array.
    key : object
        Index key.
    value : object
        Real, OTI scalar, or array (AoS, SoA, NumPy, list).
    """

    cdef int64_t flat = _aos_flat(a, key)
    cdef otinum scalar
    cdef arro source
    cdef object positions, vpos
    cdef np.ndarray flat_pos, flat_val
    cdef const int64_t[::1] pos
    cdef const int64_t[::1] vp
    cdef tuple vshape
    cdef Py_ssize_t e

    if not a.FLAGS & 1:

        raise ValueError("this array is a view of another object and cannot be modified")

    # end if

    if isinstance(value, (Real, sotinum)) and not isinstance(value, np.ndarray):

        value = otinum(value)

    # end if

    if flat >= 0 and isinstance(value, otinum):

        _status("setitem", oti_copy_to(&(<otinum>value).num, &arro_data(&a.arr)[flat]))
        return 0

    # end if

    try:

        positions = np.asarray(_aos_grid(a)[key])

    except (TypeError, ValueError, OverflowError, IndexError) as error:

        # The message table first (an integer out of range, a huge one included), else NumPy's text.
        _key_check(a.shape, key)
        raise IndexError(str(error))

    # end try

    flat_pos = np.ascontiguousarray(positions.ravel(), dtype=np.int64)
    pos = flat_pos

    if isinstance(value, otinum):

        scalar = value

        for e in range(pos.shape[0]):

            _status("setitem", oti_copy_to(&scalar.num, &arro_data(&a.arr)[pos[e]]))

        # end for

        return 0

    # end if

    # An array value: an AoS copy (a snapshot, also when it is the target itself), broadcast by NumPy's
    # rule to the selected shape.
    source = _to_aos(_soa_value(value)) if not isinstance(value, arro) else (<arro>value).copy()
    vshape = source.shape

    while len(vshape) > positions.ndim and vshape[0] == 1:

        vshape = vshape[1:]

    # end while

    try:

        vpos = np.broadcast_to(np.arange(arro_size(&source.arr), dtype=np.int64).reshape(vshape),
                               positions.shape)

    except ValueError:

        raise ValueError(_ASSIGN_SHAPE.format(source.shape, positions.shape))

    # end try

    flat_val = np.ascontiguousarray(np.ravel(vpos), dtype=np.int64)
    vp = flat_val

    for e in range(pos.shape[0]):

        _status("setitem", oti_copy_to(&arro_data(&source.arr)[vp[e]], &arro_data(&a.arr)[pos[e]]))

    # end for

    return 0

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _aos_iter(arro a):
    """
    Iterate over the first axis of an AoS array (copies; OTI scalars for a 1-D array).

    Parameters
    ----------
    a : arro
        Array with ndim >= 1.

    Yields
    ------
    arro or otinum
        ``a[0], a[1], ...``.
    """

    for i in range(arro_shape(&a.arr, 0)):

        yield _aos_getitem(a, i)

    # end for

# end function
# --------------------------------------------------------------------------------------------------------
