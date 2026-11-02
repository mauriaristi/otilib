#-----------------------------------------------------------------------------------------------------
#----------------------------   REAL NDARRAY: THE PRIVATE TEST HANDLE   ----------------------------
#-----------------------------------------------------------------------------------------------------
# ``pyoti.real._ndtest`` runs the C operations of the ndarray core on NumPy arrays and returns NumPy
# arrays (PLAN-ndarray.md Phase 4; contracts 1.8). It exists so that tests/python can check the C
# layer, the import / export boundary and the status mapping before any public Python class sits on
# top. It is private: never in docs, never in ``__all__``, and its API may change without notice.
#
# Conventions
#   - Inputs are anything with the buffer protocol or DLPack (NumPy arrays, ``memoryview``, ...).
#     They are imported by ``nd_from_object`` with the natural type (bool -> mask, int -> int64,
#     float -> float64) unless a method takes ``want``. Lists and scalars are TypeError (OTI_ERR_DTYPE).
#   - Results are NumPy arrays that share the library buffer (their ``base`` is the export), so
#     ``refs`` / ``exports`` queries and growth can be tested. ``mask`` results are ``bool`` arrays.
#   - A failing C call raises the exception of contracts 4.4 (``_nd_status``).
#   - ``op`` / ``fn`` arguments are names ('add', 'sqrt', 'sum', ...; see ``ops``, ``fns``, ``reds``)
#     or the integer codes.
#-----------------------------------------------------------------------------------------------------

import operator as _nd_operator

from libc.stdint cimport INT64_MAX, INT64_MIN


#-----------------------------------------------------------------------------------------------------
#------------------------------------   NAME TABLES   ----------------------------------------------
#-----------------------------------------------------------------------------------------------------

_ND_OPS = {"add": ND_OP_ADD, "sub": ND_OP_SUB, "mul": ND_OP_MUL, "div": ND_OP_DIV, "pow": ND_OP_POW,
           "maximum": ND_OP_MAXIMUM, "minimum": ND_OP_MINIMUM,
           "eq": ND_OP_EQ, "ne": ND_OP_NE, "lt": ND_OP_LT, "le": ND_OP_LE, "gt": ND_OP_GT,
           "ge": ND_OP_GE, "and": ND_OP_AND, "or": ND_OP_OR, "xor": ND_OP_XOR}

_ND_FNS = {"neg": ND_FN_NEG, "abs": ND_FN_ABS, "sqrt": ND_FN_SQRT, "cbrt": ND_FN_CBRT, "exp": ND_FN_EXP,
           "exp2": ND_FN_EXP2, "expm1": ND_FN_EXPM1, "log": ND_FN_LOG, "log2": ND_FN_LOG2,
           "log10": ND_FN_LOG10, "log1p": ND_FN_LOG1P, "sin": ND_FN_SIN, "cos": ND_FN_COS,
           "tan": ND_FN_TAN, "asin": ND_FN_ASIN, "acos": ND_FN_ACOS, "atan": ND_FN_ATAN,
           "sinh": ND_FN_SINH, "cosh": ND_FN_COSH, "tanh": ND_FN_TANH, "asinh": ND_FN_ASINH,
           "acosh": ND_FN_ACOSH, "atanh": ND_FN_ATANH, "floor": ND_FN_FLOOR, "ceil": ND_FN_CEIL,
           "trunc": ND_FN_TRUNC, "rint": ND_FN_RINT, "square": ND_FN_SQUARE,
           "reciprocal": ND_FN_RECIPROCAL, "sign": ND_FN_SIGN, "not": ND_FN_NOT}

_ND_REDS = {"sum": ND_RED_SUM, "prod": ND_RED_PROD, "min": ND_RED_MIN, "max": ND_RED_MAX,
            "mean": ND_RED_MEAN, "var": ND_RED_VAR, "std": ND_RED_STD, "argmin": ND_RED_ARGMIN,
            "argmax": ND_RED_ARGMAX, "any": ND_RED_ANY, "all": ND_RED_ALL}

_ND_STATUS = {"OK": OTI_OK, "SIZE": OTI_ERR_SIZE, "MEMORY": OTI_ERR_MEMORY, "PIVOT": OTI_ERR_PIVOT,
              "INDEX": OTI_ERR_INDEX, "ARGUMENT": OTI_ERR_ARGUMENT, "SHAPE": OTI_ERR_SHAPE,
              "BUSY": OTI_ERR_BUSY, "DTYPE": OTI_ERR_DTYPE, "LAYOUT": OTI_ERR_LAYOUT,
              "CONVERGE": OTI_ERR_CONVERGE, "NOTPD": OTI_ERR_NOTPD, "BACKEND": OTI_ERR_BACKEND,
              "READONLY": OTI_ERR_READONLY}

_ND_DTYPES = {OTI_F64: "float64", OTI_U8: "bool", OTI_I64: "int64"}
_ND_WANT   = {None: 0, 0: 0, "natural": 0, "f64": OTI_F64, "float64": OTI_F64, "u8": OTI_U8,
              "mask": OTI_U8, "bool": OTI_U8, "i64": OTI_I64, "int64": OTI_I64, "index": OTI_I64}
_ND_LAYOUTS = {"C": ND_LAYOUT_C, "F": ND_LAYOUT_F, "A": ND_LAYOUT_A, "K": ND_LAYOUT_K}


#-----------------------------------------------------------------------------------------------------
#------------------------------------   ARGUMENT HELPERS   -----------------------------------------
#-----------------------------------------------------------------------------------------------------

# *****************************************************************************************************
cdef int32_t _nd_code(table, key, str what) except -1:
    """
    Translate a name (or an integer code) of one of the code tables.
    """

    if key is None or isinstance(key, str):

        if key not in table:

            raise ValueError("unknown {} '{}'".format(what, key))

        # end if

        return table[key]

    # end if

    return _nd_operator.index(key)

# end function
# -----------------------------------------------------------------------------------------------------


# *****************************************************************************************************
cdef int32_t _nd_shape_arg(object shape, int64_t* out) except -1:
    """
    Fill a C shape from an int or a sequence of ints; return the rank (at most OTI_ND_MAXDIM).
    """

    cdef int32_t n, k

    try:

        shape = (_nd_operator.index(shape),)

    except TypeError:

        shape = tuple(shape)

    # end try

    n = <int32_t>len(shape)

    if n > OTI_ND_MAXDIM:

        _nd_status("shape", OTI_ERR_SHAPE)

    # end if

    for k in range(n):

        out[k] = _nd_operator.index(shape[k])

    # end for

    return n

# end function
# -----------------------------------------------------------------------------------------------------


# *****************************************************************************************************
cdef int32_t _nd_axes_arg(object axes, int32_t* out) except -2:
    """
    Fill a C axis list from an int or a sequence; None gives -1 (all axes, naxes = -1).
    """

    cdef int32_t n, k

    if axes is None:

        return -1

    # end if

    try:

        axes = (_nd_operator.index(axes),)

    except TypeError:

        axes = tuple(axes)

    # end try

    n = <int32_t>len(axes)

    if n > OTI_ND_MAXDIM:

        _nd_status("axes", OTI_ERR_SHAPE)

    # end if

    for k in range(n):

        out[k] = _nd_operator.index(axes[k])

    # end for

    return n

# end function
# -----------------------------------------------------------------------------------------------------


# *****************************************************************************************************
cdef bint _nd_is_writeable(object obj):
    """
    True when the exporter allows writes (a NumPy flag or a memoryview's readonly attribute).
    """

    try:

        return not memoryview(obj).readonly

    except Exception:

        return False

    # end try

# end function
# -----------------------------------------------------------------------------------------------------


# *****************************************************************************************************
cdef int _nd_parse_index(object key, nd_index_t* idx, int maxn) except -1:
    """
    Fill the index items of a basic-indexing key: ints, slices, None and Ellipsis.

    Returns
    -------
    int
        Number of items.
    """

    cdef int n = 0
    cdef nd_index_t* item

    if not isinstance(key, tuple):

        key = (key,)

    # end if

    if len(key) > maxn:

        raise IndexError("too many indices for the test handle")

    # end if

    for obj in key:

        item = &idx[n]
        item.has = 0
        item.start = 0
        item.stop = 0
        item.step = 0
        item.arr = NULL

        if obj is None:

            item.kind = ND_IDX_NEWAXIS

        elif obj is Ellipsis:

            item.kind = ND_IDX_ELLIPSIS

        elif isinstance(obj, slice):

            item.kind = ND_IDX_SLICE

            if obj.start is not None:

                item.has |= ND_HAS_START
                item.start = _nd_operator.index(obj.start)

            # end if

            if obj.stop is not None:

                item.has |= ND_HAS_STOP
                item.stop = _nd_operator.index(obj.stop)

            # end if

            if obj.step is not None:

                item.has |= ND_HAS_STEP
                item.step = _nd_operator.index(obj.step)

            # end if

        elif isinstance(obj, (bool, np.bool_)):

            raise IndexError("boolean indices are advanced indexing (Phase 5)")

        else:

            try:

                item.start = _nd_operator.index(obj)

            except TypeError:

                raise IndexError("only integers, slices, None and Ellipsis are basic indices")

            # end try

            item.kind = ND_IDX_INT

        # end if

        n += 1

    # end for

    return n

# end function
# -----------------------------------------------------------------------------------------------------


#-----------------------------------------------------------------------------------------------------
#------------------------------------   HOLDERS   --------------------------------------------------
#-----------------------------------------------------------------------------------------------------

# *****************************************************************************************************
cdef class _NdHold:
    """
    A retained ndarr_t imported from a Python object; released when the holder dies.
    """

    cdef ndarr_t arr

    def __cinit__(self, object obj, int32_t want = 0, bint writeable = False, bint copy = False):

        cdef int status

        nd_init_empty(&self.arr)
        status = nd_from_object(obj, want, writeable, &self.arr, ND_IMPORT_COPY if copy else 0)
        _nd_status("nd_from_object", status)

    # end def

    def __dealloc__(self):

        nd_release(&self.arr)

    # end def

# end class
# -----------------------------------------------------------------------------------------------------


# *****************************************************************************************************
cdef object _nd_result(ndarr_t* res, int writeable = 1):
    """
    Export a result as a NumPy array and drop the descriptor's own reference.
    """

    try:

        return nd_to_numpy(res, writeable)

    finally:

        nd_release(res)

    # end try

# end function
# -----------------------------------------------------------------------------------------------------


# *****************************************************************************************************
cdef class _NdRoot:
    """
    A library array with a growable buffer, for growth and export tests.

    ``array()`` exports it as NumPy (a live export pins the buffer); ``grow`` / ``set_layout`` are the
    two halves of a relayout after growth (contracts 1.6, 7.2).
    """

    cdef ndarr_t arr

    def __cinit__(self, object shape, str layout = "C"):

        cdef int64_t shp[OTI_ND_MAXDIM]
        cdef int32_t nd = _nd_shape_arg(shape, shp)
        cdef int status

        nd_init_empty(&self.arr)
        status = nd_zeros(_nd_ctx, nd, shp, _nd_code(_ND_LAYOUTS, layout, "layout"), &self.arr)
        _nd_status("nd_zeros", status)

    # end def

    def __dealloc__(self):

        nd_release(&self.arr)

    # end def

    def array(self, writeable=True):
        """NumPy array exported from the root (a live export until it is released)."""

        return nd_to_numpy(&self.arr, 1 if writeable else 0)

    # end def

    def grow(self, int64_t nbytes, keep=None):
        """nd_grow: reallocate to ``nbytes``, keeping ``keep`` bytes (default: all that fit)."""

        cdef int64_t kept = min(nd_buffer_nbytes(self.arr.buf), nbytes) if keep is None else keep
        cdef int status

        status = nd_grow(_nd_ctx, &self.arr, nbytes, kept)
        _nd_status("nd_grow", status, &self.arr)

    # end def

    def set_layout(self, object shape, strides=None):
        """nd_set_layout: the checked relayout after growth (C strides when ``strides`` is None)."""

        cdef int64_t shp[OTI_ND_MAXDIM]
        cdef int64_t strd[OTI_ND_MAXDIM]
        cdef int32_t nd = _nd_shape_arg(shape, shp)
        cdef int32_t k
        cdef int64_t acc = 1
        cdef int status

        if strides is None:

            for k in range(nd - 1, -1, -1):

                strd[k] = acc
                acc *= shp[k]

            # end for

        else:

            for k in range(nd):

                strd[k] = _nd_operator.index(strides[k])

            # end for

        # end if

        status = nd_set_layout(&self.arr, nd, shp, strd)
        _nd_status("nd_set_layout", status, &self.arr)

    # end def

    @property
    def refs(self):
        """Retained references on the buffer (exports included)."""

        return nd_buffer_refs(self.arr.buf)

    # end def

    @property
    def exports(self):
        """Live exports (NumPy arrays, DLPack capsules)."""

        return nd_buffer_exports(self.arr.buf)

    # end def

    @property
    def nbytes(self):
        """Allocation size in bytes."""

        return nd_buffer_nbytes(self.arr.buf)

    # end def

    @property
    def shape(self):

        return tuple([self.arr.shape[k] for k in range(self.arr.ndim)])

    # end def

# end class
# -----------------------------------------------------------------------------------------------------


# *****************************************************************************************************
cdef class _NdLU:
    """
    An LU factorization (nd_lu_t): ``info``, ``n``, ``trans``, ``solve(b)``, and the factors as arrays.
    """

    cdef nd_lu_t lu

    def __cinit__(self, a, bint overwrite = False):

        cdef _NdHold ha = _NdHold(a, 0, overwrite)
        cdef int status

        nd_lu_init(&self.lu)

        with nogil:

            status = nd_lu_factor(_nd_ctx, &ha.arr, 1 if overwrite else 0, &self.lu)

        # end with

        # A positive info (singular U) still gives a complete factorization.
        if status < 0:

            _nd_status("nd_lu_factor", status, &ha.arr)

        # end if

    # end def

    def __dealloc__(self):

        nd_lu_free(&self.lu)

    # end def

    @property
    def info(self):
        """dgetrf info: 0, or i > 0 when U(i, i) is exactly zero."""

        return self.lu.info

    # end def

    @property
    def n(self):

        return self.lu.n

    # end def

    @property
    def trans(self):
        """1 when the factors are those of A^T (a C-order input read as A^T)."""

        return self.lu.trans

    # end def

    def factors(self):
        """The packed L \\ U factors (F order) as a read-only NumPy array."""

        return nd_to_numpy(&self.lu.lu, 0)

    # end def

    def pivots(self):
        """1-based dgetrf pivots as an int64 array."""

        return np.array([self.lu.ipiv[k] for k in range(self.lu.n)], dtype=np.int64)

    # end def

    def solve(self, b):
        """nd_lu_solve: x with A x = b (b of shape (n,) or (n, k))."""

        cdef _NdHold hb = _NdHold(b, 0, False)
        cdef ndarr_t res
        cdef int status

        nd_init_empty(&res)

        with nogil:

            status = nd_lu_solve(_nd_ctx, &self.lu, &hb.arr, &res)

        # end with

        _nd_status("nd_lu_solve", status)

        return _nd_result(&res)

    # end def

# end class
# -----------------------------------------------------------------------------------------------------


#-----------------------------------------------------------------------------------------------------
#------------------------------------   THE HANDLE   -----------------------------------------------
#-----------------------------------------------------------------------------------------------------

# *****************************************************************************************************
cdef class _NdTest:
    """
    Private handle that runs the C ndarray operations on NumPy arrays (see the file header).
    """

    #-------------------------------------------------------------------------------------------------
    # Tables and diagnostics.
    #-------------------------------------------------------------------------------------------------

    @property
    def ops(self):
        """Binary elementwise codes by name (comparisons and mask operations included)."""

        return dict(_ND_OPS)

    # end def

    @property
    def fns(self):
        """Unary elementwise codes by name."""

        return dict(_ND_FNS)

    # end def

    @property
    def reds(self):
        """Reduction codes by name."""

        return dict(_ND_REDS)

    # end def

    @property
    def status(self):
        """Status codes by name (without the ``OTI_ERR_`` prefix)."""

        return dict(_ND_STATUS)

    # end def

    @property
    def maxdim(self):
        """OTI_ND_MAXDIM."""

        return OTI_ND_MAXDIM

    # end def

    def status_string(self, int status):
        """oti_status_string of a status code."""

        return oti_status_string(status).decode()

    # end def

    def last_error(self):
        """(status, where, msg) of this module's context: the module that made the call."""

        cdef const char* where = NULL
        cdef const char* msg   = NULL
        cdef int status = oti_ctx_last_error(_nd_ctx, &where, &msg)

        return (status,
                None if where == NULL else (<bytes>where).decode(),
                None if msg == NULL else (<bytes>msg).decode())

    # end def

    def clear_error(self):
        """oti_ctx_clear_error of this module's context."""

        oti_ctx_clear_error(_nd_ctx)

    # end def

    def set_limits(self, int64_t max_alloc_bytes = 0, int64_t max_temp_bytes = 0):
        """
        Install (or, with both 0, remove) a user context with byte budgets for every later call.
        """

        global _nd_ctx

        if max_alloc_bytes == 0 and max_temp_bytes == 0:

            _nd_ctx = NULL
            return

        # end if

        _nd_status("oti_ctx_init", oti_ctx_init(&_nd_user_ctx))
        _nd_user_ctx.max_alloc_bytes = max_alloc_bytes
        _nd_user_ctx.max_temp_bytes  = max_temp_bytes
        _nd_ctx = &_nd_user_ctx

    # end def

    def fail_alloc(self, int64_t countdown):
        """nd_test_fail_alloc: make the countdown-th allocation from now on fail (0 disables)."""

        nd_test_fail_alloc(countdown)

    # end def

    #-------------------------------------------------------------------------------------------------
    # Import and export (contracts 1.8, 2.2).
    #-------------------------------------------------------------------------------------------------

    def roundtrip(self, obj, want = None, bint writeable = False, bint copy = False,
                  export_writeable = None):
        """
        nd_from_object then nd_to_numpy: the result shares memory with ``obj`` when the import was
        zero-copy and is a converted library copy otherwise.

        Parameters
        ----------
        obj : buffer exporter or DLPack producer
        want : None, 'f64', 'mask', 'index' (or the dtype codes); None is the natural type.
        writeable : bool
            Import as an output (out=): zero-copy only, the exporter must be writeable.
        copy : bool
            ND_IMPORT_COPY: always copy.
        export_writeable : bool or None
            Writeability of the NumPy result; None follows the import.
        """

        cdef _NdHold hold = _NdHold(obj, _nd_code(_ND_WANT, want, "dtype"), writeable, copy)
        cdef int w

        if export_writeable is None:

            w = 1 if (hold.arr.flags & ND_WRITEABLE) else 0

        else:

            w = 1 if export_writeable else 0

        # end if

        return nd_to_numpy(&hold.arr, w)

    # end def

    def import_info(self, obj, want = None, bint writeable = False, bint copy = False):
        """
        Describe what nd_from_object makes of ``obj``: shape, element strides, dtype name, flags,
        writeable, refs, exports, owns (the library allocated it: a converted copy) and nbytes.
        """

        cdef _NdHold hold = _NdHold(obj, _nd_code(_ND_WANT, want, "dtype"), writeable, copy)
        cdef uint64_t state = nd_buffer_state(hold.arr.buf)

        return {"ndim": hold.arr.ndim,
                "shape": tuple([hold.arr.shape[k] for k in range(hold.arr.ndim)]),
                "strides": tuple([hold.arr.strides[k] for k in range(hold.arr.ndim)]),
                "dtype": _ND_DTYPES[hold.arr.dtype],
                "flags": hold.arr.flags,
                "c_contiguous": bool(hold.arr.flags & ND_C_CONTIG),
                "f_contiguous": bool(hold.arr.flags & ND_F_CONTIG),
                "writeable": bool(hold.arr.flags & ND_WRITEABLE),
                "refs": nd_buffer_refs(hold.arr.buf),
                "exports": nd_buffer_exports(hold.arr.buf),
                "owns": bool(state & ND_STATE_OWNS),
                "growable": bool(state & ND_STATE_GROWABLE),
                "nbytes": nd_buffer_nbytes(hold.arr.buf)}

    # end def

    def trusted_copy(self, obj, bint writeable = True):
        """
        Wrap the memory of ``obj`` as a trusted temporary (buf == NULL) and export it: nd_to_numpy
        cannot pin it, so the result is a COPY with no base (critic W1 finding 10.2).
        """

        cdef _NdHold hold = _NdHold(obj, 0, False)
        cdef ndarr_t tmp
        cdef int status

        nd_init_empty(&tmp)
        status = nd_wrap_trusted(hold.arr.data, hold.arr.dtype, hold.arr.ndim, hold.arr.shape,
                                 hold.arr.strides, 1, &tmp)
        _nd_status("nd_wrap_trusted", status)

        return nd_to_numpy(&tmp, 1 if writeable else 0)

    # end def

    def root(self, shape, layout = "C"):
        """A growable library array (see ``_NdRoot``)."""

        return _NdRoot(shape, layout)

    # end def

    #-------------------------------------------------------------------------------------------------
    # Creators.
    #-------------------------------------------------------------------------------------------------

    def empty(self, shape, layout = "C"):

        cdef int64_t shp[OTI_ND_MAXDIM]
        cdef int32_t nd = _nd_shape_arg(shape, shp)
        cdef int32_t lay = _nd_code(_ND_LAYOUTS, layout, "layout")
        cdef ndarr_t res
        cdef int status

        nd_init_empty(&res)

        with nogil:

            status = nd_empty(_nd_ctx, nd, shp, lay, &res)

        # end with

        _nd_status("nd_empty", status)

        return _nd_result(&res)

    # end def

    def zeros(self, shape, layout = "C"):

        cdef int64_t shp[OTI_ND_MAXDIM]
        cdef int32_t nd = _nd_shape_arg(shape, shp)
        cdef int32_t lay = _nd_code(_ND_LAYOUTS, layout, "layout")
        cdef ndarr_t res
        cdef int status

        nd_init_empty(&res)

        with nogil:

            status = nd_zeros(_nd_ctx, nd, shp, lay, &res)

        # end with

        _nd_status("nd_zeros", status)

        return _nd_result(&res)

    # end def

    def ones(self, shape, layout = "C"):

        cdef int64_t shp[OTI_ND_MAXDIM]
        cdef int32_t nd = _nd_shape_arg(shape, shp)
        cdef int32_t lay = _nd_code(_ND_LAYOUTS, layout, "layout")
        cdef ndarr_t res
        cdef int status

        nd_init_empty(&res)

        with nogil:

            status = nd_ones(_nd_ctx, nd, shp, lay, &res)

        # end with

        _nd_status("nd_ones", status)

        return _nd_result(&res)

    # end def

    def full(self, shape, double value, layout = "C"):

        cdef int64_t shp[OTI_ND_MAXDIM]
        cdef int32_t nd = _nd_shape_arg(shape, shp)
        cdef int32_t lay = _nd_code(_ND_LAYOUTS, layout, "layout")
        cdef ndarr_t res
        cdef int status

        nd_init_empty(&res)

        with nogil:

            status = nd_full(_nd_ctx, nd, shp, value, lay, &res)

        # end with

        _nd_status("nd_full", status)

        return _nd_result(&res)

    # end def

    def eye(self, int64_t n, m = None, int64_t k = 0, layout = "C"):

        cdef int64_t cols = n if m is None else m
        cdef int32_t lay = _nd_code(_ND_LAYOUTS, layout, "layout")
        cdef ndarr_t res
        cdef int status

        nd_init_empty(&res)

        with nogil:

            status = nd_eye(_nd_ctx, n, cols, k, lay, &res)

        # end with

        _nd_status("nd_eye", status)

        return _nd_result(&res)

    # end def

    def arange(self, double start, double stop, double step = 1.0):

        cdef ndarr_t res
        cdef int status

        nd_init_empty(&res)

        with nogil:

            status = nd_arange(_nd_ctx, start, stop, step, &res)

        # end with

        _nd_status("nd_arange", status)

        return _nd_result(&res)

    # end def

    def linspace(self, double start, double stop, int64_t num, bint endpoint = True):

        cdef ndarr_t res
        cdef int status

        nd_init_empty(&res)

        with nogil:

            status = nd_linspace(_nd_ctx, start, stop, num, 1 if endpoint else 0, &res)

        # end with

        _nd_status("nd_linspace", status)

        return _nd_result(&res)

    # end def

    def copy(self, a, layout = "K"):
        """nd_copy of a float64 array (layout 'K' keeps the source's memory order)."""

        cdef _NdHold src = _NdHold(a, 0, False)
        cdef int32_t lay = _nd_code(_ND_LAYOUTS, layout, "layout")
        cdef ndarr_t res
        cdef int status

        nd_init_empty(&res)

        with nogil:

            status = nd_copy(_nd_ctx, &src.arr, lay, &res)

        # end with

        _nd_status("nd_copy", status)

        return _nd_result(&res)

    # end def

    def ascontiguous(self, a):
        """(array, copied): nd_ascontiguous."""

        cdef _NdHold src = _NdHold(a, 0, False)
        cdef ndarr_t res
        cdef int32_t copied = 0
        cdef int status

        nd_init_empty(&res)

        with nogil:

            status = nd_ascontiguous(_nd_ctx, &src.arr, &res, &copied)

        # end with

        _nd_status("nd_ascontiguous", status)

        return _nd_result(&res, 1 if (src.arr.flags & ND_WRITEABLE) or copied else 0), bool(copied)

    # end def

    def asfortran(self, a):
        """(array, copied): nd_asfortran."""

        cdef _NdHold src = _NdHold(a, 0, False)
        cdef ndarr_t res
        cdef int32_t copied = 0
        cdef int status

        nd_init_empty(&res)

        with nogil:

            status = nd_asfortran(_nd_ctx, &src.arr, &res, &copied)

        # end with

        _nd_status("nd_asfortran", status)

        return _nd_result(&res, 1 if (src.arr.flags & ND_WRITEABLE) or copied else 0), bool(copied)

    # end def

    def reshape(self, a, shape, layout = "C"):
        """(array, copied): nd_reshape (a view when the strides allow, else a copy)."""

        cdef _NdHold src = _NdHold(a, 0, _nd_is_writeable(a))
        cdef int64_t shp[OTI_ND_MAXDIM]
        cdef int32_t nd = _nd_shape_arg(shape, shp)
        cdef int32_t lay = _nd_code(_ND_LAYOUTS, layout, "layout")
        cdef ndarr_t res
        cdef int32_t copied = 0
        cdef int status

        nd_init_empty(&res)

        with nogil:

            status = nd_reshape(_nd_ctx, &src.arr, nd, shp, lay, &res, &copied)

        # end with

        _nd_status("nd_reshape", status)

        return _nd_result(&res, 1 if (res.flags & ND_WRITEABLE) else 0), bool(copied)

    # end def

    #-------------------------------------------------------------------------------------------------
    # Views: temporaries over the imported array, exported back as NumPy views of the same memory.
    #-------------------------------------------------------------------------------------------------

    def index(self, a, key):
        """nd_view_index: basic indexing (ints, slices, None, Ellipsis) as a NumPy view of ``a``."""

        cdef _NdHold src = _NdHold(a, 0, _nd_is_writeable(a))
        cdef nd_index_t idx[64]
        cdef int n = _nd_parse_index(key, idx, 64)
        cdef ndarr_t out

        nd_init_empty(&out)
        _nd_status("nd_view_index", nd_view_index(&src.arr, n, idx, &out))

        return nd_to_numpy(&out, 1 if (out.flags & ND_WRITEABLE) else 0)

    # end def

    def transpose(self, a, axes = None):

        cdef _NdHold src = _NdHold(a, 0, _nd_is_writeable(a))
        cdef int32_t ax[OTI_ND_MAXDIM]
        cdef int32_t n = _nd_axes_arg(axes, ax)
        cdef ndarr_t out

        nd_init_empty(&out)
        _nd_status("nd_view_transpose",
                   nd_view_transpose(&src.arr, n if n >= 0 else 0, ax if n >= 0 else NULL, &out))

        return nd_to_numpy(&out, 1 if (out.flags & ND_WRITEABLE) else 0)

    # end def

    def swapaxes(self, a, int32_t axis1, int32_t axis2):

        cdef _NdHold src = _NdHold(a, 0, _nd_is_writeable(a))
        cdef ndarr_t out

        nd_init_empty(&out)
        _nd_status("nd_view_swapaxes", nd_view_swapaxes(&src.arr, axis1, axis2, &out))

        return nd_to_numpy(&out, 1 if (out.flags & ND_WRITEABLE) else 0)

    # end def

    def squeeze(self, a, axes = None):

        cdef _NdHold src = _NdHold(a, 0, _nd_is_writeable(a))
        cdef int32_t ax[OTI_ND_MAXDIM]
        cdef int32_t n = _nd_axes_arg(axes, ax)
        cdef ndarr_t out

        nd_init_empty(&out)
        _nd_status("nd_view_squeeze",
                   nd_view_squeeze(&src.arr, n if n >= 0 else 0, ax if n >= 0 else NULL, &out))

        return nd_to_numpy(&out, 1 if (out.flags & ND_WRITEABLE) else 0)

    # end def

    def expand_dims(self, a, axes):

        cdef _NdHold src = _NdHold(a, 0, _nd_is_writeable(a))
        cdef int32_t ax[OTI_ND_MAXDIM]
        cdef int32_t n = _nd_axes_arg(axes, ax)
        cdef ndarr_t out

        nd_init_empty(&out)
        _nd_status("nd_view_expand_dims", nd_view_expand_dims(&src.arr, n if n >= 0 else 0, ax, &out))

        return nd_to_numpy(&out, 1 if (out.flags & ND_WRITEABLE) else 0)

    # end def

    def broadcast_to(self, a, shape):
        """nd_view_broadcast_to: always a read-only view (as NumPy)."""

        cdef _NdHold src = _NdHold(a, 0, False)
        cdef int64_t shp[OTI_ND_MAXDIM]
        cdef int32_t nd = _nd_shape_arg(shape, shp)
        cdef ndarr_t out

        nd_init_empty(&out)
        _nd_status("nd_view_broadcast_to", nd_view_broadcast_to(&src.arr, nd, shp, &out))

        return nd_to_numpy(&out, 1 if (out.flags & ND_WRITEABLE) else 0)

    # end def

    def diagonal(self, a, int64_t offset = 0, int32_t axis1 = 0, int32_t axis2 = 1):
        """nd_view_diagonal: always a read-only view (as NumPy)."""

        cdef _NdHold src = _NdHold(a, 0, False)
        cdef ndarr_t out

        nd_init_empty(&out)
        _nd_status("nd_view_diagonal", nd_view_diagonal(&src.arr, offset, axis1, axis2, &out))

        return nd_to_numpy(&out, 1 if (out.flags & ND_WRITEABLE) else 0)

    # end def

    def view_reshape(self, a, shape, layout = "C"):
        """nd_view_reshape: a view only; ValueError when the strides do not allow one."""

        cdef _NdHold src = _NdHold(a, 0, _nd_is_writeable(a))
        cdef int64_t shp[OTI_ND_MAXDIM]
        cdef int32_t nd = _nd_shape_arg(shape, shp)
        cdef int32_t lay = _nd_code(_ND_LAYOUTS, layout, "layout")
        cdef ndarr_t out

        nd_init_empty(&out)
        _nd_status("nd_view_reshape", nd_view_reshape(&src.arr, nd, shp, lay, &out))

        return nd_to_numpy(&out, 1 if (out.flags & ND_WRITEABLE) else 0)

    # end def

    def broadcast_shapes(self, *shapes):
        """nd_broadcast_shapes of zero-strided operands with the given shapes (as a tuple)."""

        cdef ndarr_t ops[8]
        cdef const ndarr_t* ptrs[8]
        cdef int64_t shp[OTI_ND_MAXDIM]
        cdef int32_t nd = 0
        cdef int32_t k, n = <int32_t>len(shapes)
        cdef int32_t j

        if n < 1 or n > 8:

            raise ValueError("between 1 and 8 shapes")

        # end if

        for k in range(n):

            shape = tuple(shapes[k])
            ops[k].ndim = <int32_t>len(shape)

            if ops[k].ndim > OTI_ND_MAXDIM:

                _nd_status("shape", OTI_ERR_SHAPE)

            # end if

            for j in range(ops[k].ndim):

                ops[k].shape[j]   = shape[j]
                ops[k].strides[j] = 0

            # end for

            ptrs[k] = &ops[k]

        # end for

        _nd_status("nd_broadcast_shapes", nd_broadcast_shapes(n, ptrs, &nd, shp))

        return tuple([shp[k] for k in range(nd)])

    # end def

    #-------------------------------------------------------------------------------------------------
    # Elementwise.
    #-------------------------------------------------------------------------------------------------

    def binary(self, op, a, b, want = None):
        """nd_binary: a new array (bool for comparisons and mask operations)."""

        cdef int32_t code = _nd_code(_ND_OPS, op, "binary operation")
        cdef int32_t w = _nd_code(_ND_WANT, want, "dtype")
        cdef _NdHold ha = _NdHold(a, w, False)
        cdef _NdHold hb = _NdHold(b, w, False)
        cdef ndarr_t res
        cdef int status

        nd_init_empty(&res)

        with nogil:

            status = nd_binary(_nd_ctx, code, &ha.arr, &hb.arr, &res)

        # end with

        _nd_status("nd_binary", status)

        return _nd_result(&res)

    # end def

    def binary_to(self, op, a, b, out, want = None):
        """nd_binary_to: writes into the NumPy array ``out`` (zero-copy import) and returns it."""

        cdef int32_t code = _nd_code(_ND_OPS, op, "binary operation")
        cdef int32_t w = _nd_code(_ND_WANT, want, "dtype")
        cdef _NdHold ha = _NdHold(a, w, False)
        cdef _NdHold hb = _NdHold(b, w, False)
        cdef _NdHold ho = _NdHold(out, 0, True)
        cdef int status

        with nogil:

            status = nd_binary_to(_nd_ctx, code, &ha.arr, &hb.arr, &ho.arr)

        # end with

        _nd_status("nd_binary_to", status)

        return out

    # end def

    def binary_scalar(self, op, a, double s, bint scalar_left = False):
        """nd_binary_scalar: ``s op a`` when ``scalar_left`` else ``a op s``."""

        cdef int32_t code = _nd_code(_ND_OPS, op, "binary operation")
        cdef _NdHold ha = _NdHold(a, 0, False)
        cdef ndarr_t res
        cdef int status

        nd_init_empty(&res)

        with nogil:

            status = nd_binary_scalar(_nd_ctx, code, &ha.arr, s, 1 if scalar_left else 0, &res)

        # end with

        _nd_status("nd_binary_scalar", status)

        return _nd_result(&res)

    # end def

    def binary_scalar_to(self, op, a, double s, out, bint scalar_left = False):
        """nd_binary_scalar_to into ``out`` (returned)."""

        cdef int32_t code = _nd_code(_ND_OPS, op, "binary operation")
        cdef _NdHold ha = _NdHold(a, 0, False)
        cdef _NdHold ho = _NdHold(out, 0, True)
        cdef int status

        with nogil:

            status = nd_binary_scalar_to(_nd_ctx, code, &ha.arr, s, 1 if scalar_left else 0, &ho.arr)

        # end with

        _nd_status("nd_binary_scalar_to", status)

        return out

    # end def

    def unary(self, fn, a):
        """nd_unary: a new array."""

        cdef int32_t code = _nd_code(_ND_FNS, fn, "unary function")
        cdef _NdHold ha = _NdHold(a, 0, False)
        cdef ndarr_t res
        cdef int status

        nd_init_empty(&res)

        with nogil:

            status = nd_unary(_nd_ctx, code, &ha.arr, &res)

        # end with

        _nd_status("nd_unary", status)

        return _nd_result(&res)

    # end def

    def unary_to(self, fn, a, out):
        """nd_unary_to into ``out`` (returned); ``out`` may be ``a`` (in place)."""

        cdef int32_t code = _nd_code(_ND_FNS, fn, "unary function")
        cdef _NdHold ha = _NdHold(a, 0, False)
        cdef _NdHold ho = _NdHold(out, 0, True)
        cdef int status

        with nogil:

            status = nd_unary_to(_nd_ctx, code, &ha.arr, &ho.arr)

        # end with

        _nd_status("nd_unary_to", status)

        return out

    # end def

    def assign(self, src, dst):
        """nd_assign: ``dst[...] = src`` with broadcasting and snapshot semantics (``dst`` returned)."""

        cdef _NdHold hs = _NdHold(src, 0, False)
        cdef _NdHold hd = _NdHold(dst, 0, True)
        cdef int status

        with nogil:

            status = nd_assign(_nd_ctx, &hs.arr, &hd.arr)

        # end with

        _nd_status("nd_assign", status)

        return dst

    # end def

    def fill(self, dst, double value):
        """nd_fill: ``dst[...] = value`` (``dst`` returned)."""

        cdef _NdHold hd = _NdHold(dst, 0, True)
        cdef int status

        with nogil:

            status = nd_fill(_nd_ctx, &hd.arr, value)

        # end with

        _nd_status("nd_fill", status)

        return dst

    # end def

    #-------------------------------------------------------------------------------------------------
    # Reductions.
    #-------------------------------------------------------------------------------------------------

    def reduce(self, op, a, axes = None, bint keepdims = False, int64_t ddof = 0):
        """
        nd_reduce: ``numpy.<op>(a, axis=axes, keepdims=keepdims)`` (``ddof`` for var / std). ``axes``
        None reduces every axis (argmin / argmax: the flattened index).
        """

        cdef int32_t code = _nd_code(_ND_REDS, op, "reduction")
        cdef _NdHold ha = _NdHold(a, 0, False)
        cdef int32_t ax[OTI_ND_MAXDIM]
        cdef int32_t n = _nd_axes_arg(axes, ax)
        cdef ndarr_t res
        cdef int status

        nd_init_empty(&res)

        with nogil:

            status = nd_reduce(_nd_ctx, code, &ha.arr, n, ax if n >= 0 else NULL,
                               1 if keepdims else 0, ddof, &res)

        # end with

        _nd_status("nd_reduce", status)

        return _nd_result(&res)

    # end def

    def reduce_to(self, op, a, out, axes = None, bint keepdims = False, int64_t ddof = 0):
        """nd_reduce_to into ``out`` (returned); ``out`` may overlap ``a`` (a temporary is used)."""

        cdef int32_t code = _nd_code(_ND_REDS, op, "reduction")
        cdef _NdHold ha = _NdHold(a, 0, _nd_is_writeable(a))
        cdef _NdHold ho
        cdef int32_t ax[OTI_ND_MAXDIM]
        cdef int32_t n = _nd_axes_arg(axes, ax)
        cdef int status

        # An output that is also the input shares one exporter: import it as an output first.
        ho = _NdHold(out, 0, True)

        with nogil:

            status = nd_reduce_to(_nd_ctx, code, &ha.arr, n, ax if n >= 0 else NULL,
                                  1 if keepdims else 0, ddof, &ho.arr)

        # end with

        _nd_status("nd_reduce_to", status)

        return out

    # end def

    def pairwise_sum(self, a):
        """nd_pairwise_sum over a float64 vector (the deterministic block sum)."""

        cdef _NdHold ha = _NdHold(a, OTI_F64, False)

        if ha.arr.ndim != 1:

            raise ValueError("pairwise_sum takes a 1-D array")

        # end if

        return nd_pairwise_sum(<const double*>ha.arr.data, ha.arr.shape[0], ha.arr.strides[0])

    # end def

    #-------------------------------------------------------------------------------------------------
    # BLAS (Phase 3). Positive LAPACK infos raise numpy.linalg.LinAlgError (contracts 4.4).
    #-------------------------------------------------------------------------------------------------

    def matmul(self, a, b):
        """nd_matmul: numpy.matmul (stacked, broadcasting)."""

        cdef _NdHold ha = _NdHold(a, 0, False)
        cdef _NdHold hb = _NdHold(b, 0, False)
        cdef ndarr_t res
        cdef int status

        nd_init_empty(&res)

        with nogil:

            status = nd_matmul(_nd_ctx, &ha.arr, &hb.arr, &res)

        # end with

        _nd_status("nd_matmul", status)

        return _nd_result(&res)

    # end def

    def matmul_to(self, a, b, out):
        """nd_matmul_to into ``out`` (returned); ``out`` may overlap an input (a temporary is used)."""

        cdef _NdHold ha = _NdHold(a, 0, False)
        cdef _NdHold hb = _NdHold(b, 0, False)
        cdef _NdHold ho = _NdHold(out, 0, True)
        cdef int status

        with nogil:

            status = nd_matmul_to(_nd_ctx, &ha.arr, &hb.arr, &ho.arr)

        # end with

        _nd_status("nd_matmul_to", status)

        return out

    # end def

    def dot(self, a, b):
        """nd_dot: numpy.dot for ndim <= 2."""

        cdef _NdHold ha = _NdHold(a, 0, False)
        cdef _NdHold hb = _NdHold(b, 0, False)
        cdef ndarr_t res
        cdef int status

        nd_init_empty(&res)

        with nogil:

            status = nd_dot(_nd_ctx, &ha.arr, &hb.arr, &res)

        # end with

        _nd_status("nd_dot", status)

        return _nd_result(&res)

    # end def

    def dot_to(self, a, b, out):
        """nd_dot_to into ``out`` (returned)."""

        cdef _NdHold ha = _NdHold(a, 0, False)
        cdef _NdHold hb = _NdHold(b, 0, False)
        cdef _NdHold ho = _NdHold(out, 0, True)
        cdef int status

        with nogil:

            status = nd_dot_to(_nd_ctx, &ha.arr, &hb.arr, &ho.arr)

        # end with

        _nd_status("nd_dot_to", status)

        return out

    # end def

    def gemm(self, a, b, c, double alpha = 1.0, double beta = 0.0, bint transa = False,
             bint transb = False):
        """nd_gemm: ``c = alpha op(a) op(b) + beta c`` in place (``c`` returned)."""

        cdef _NdHold ha = _NdHold(a, 0, False)
        cdef _NdHold hb = _NdHold(b, 0, False)
        cdef _NdHold hc = _NdHold(c, 0, True)
        cdef int status

        with nogil:

            status = nd_gemm(_nd_ctx, 1 if transa else 0, 1 if transb else 0, alpha, &ha.arr, &hb.arr,
                             beta, &hc.arr)

        # end with

        _nd_status("nd_gemm", status)

        return c

    # end def

    def gemv(self, a, x, y, double alpha = 1.0, double beta = 0.0, bint trans = False):
        """nd_gemv: ``y = alpha op(a) x + beta y`` in place (``y`` returned)."""

        cdef _NdHold ha = _NdHold(a, 0, False)
        cdef _NdHold hx = _NdHold(x, 0, False)
        cdef _NdHold hy = _NdHold(y, 0, True)
        cdef int status

        with nogil:

            status = nd_gemv(_nd_ctx, 1 if trans else 0, alpha, &ha.arr, &hx.arr, beta, &hy.arr)

        # end with

        _nd_status("nd_gemv", status)

        return y

    # end def

    def ger(self, x, y, a, double alpha = 1.0):
        """nd_ger: ``a += alpha x y^T`` in place (``a`` returned)."""

        cdef _NdHold hx = _NdHold(x, 0, False)
        cdef _NdHold hy = _NdHold(y, 0, False)
        cdef _NdHold ha = _NdHold(a, 0, True)
        cdef int status

        with nogil:

            status = nd_ger(_nd_ctx, alpha, &hx.arr, &hy.arr, &ha.arr)

        # end with

        _nd_status("nd_ger", status)

        return a

    # end def

    def vdot(self, x, y):
        """nd_vdot: the dot product of two vectors."""

        cdef _NdHold hx = _NdHold(x, 0, False)
        cdef _NdHold hy = _NdHold(y, 0, False)
        cdef double res = 0.0
        cdef int status

        with nogil:

            status = nd_vdot(_nd_ctx, &hx.arr, &hy.arr, &res)

        # end with

        _nd_status("nd_vdot", status)

        return res

    # end def

    def axpy(self, double alpha, x, y):
        """nd_axpy: ``y += alpha x`` in place (``y`` returned)."""

        cdef _NdHold hx = _NdHold(x, 0, False)
        cdef _NdHold hy = _NdHold(y, 0, True)
        cdef int status

        with nogil:

            status = nd_axpy(_nd_ctx, alpha, &hx.arr, &hy.arr)

        # end with

        _nd_status("nd_axpy", status)

        return y

    # end def

    def scal(self, double alpha, x):
        """nd_scal: ``x *= alpha`` in place (``x`` returned)."""

        cdef _NdHold hx = _NdHold(x, 0, True)
        cdef int status

        with nogil:

            status = nd_scal(_nd_ctx, alpha, &hx.arr)

        # end with

        _nd_status("nd_scal", status)

        return x

    # end def

    def nrm2(self, x):

        cdef _NdHold hx = _NdHold(x, 0, False)
        cdef double res = 0.0
        cdef int status

        with nogil:

            status = nd_nrm2(_nd_ctx, &hx.arr, &res)

        # end with

        _nd_status("nd_nrm2", status)

        return res

    # end def

    def asum(self, x):

        cdef _NdHold hx = _NdHold(x, 0, False)
        cdef double res = 0.0
        cdef int status

        with nogil:

            status = nd_asum(_nd_ctx, &hx.arr, &res)

        # end with

        _nd_status("nd_asum", status)

        return res

    # end def

    def iamax(self, x):

        cdef _NdHold hx = _NdHold(x, 0, False)
        cdef int64_t res = 0
        cdef int status

        with nogil:

            status = nd_iamax(_nd_ctx, &hx.arr, &res)

        # end with

        _nd_status("nd_iamax", status)

        return res

    # end def

    #-------------------------------------------------------------------------------------------------
    # Linear algebra (Phase 3).
    #-------------------------------------------------------------------------------------------------

    def lu_factor(self, a, bint overwrite = False):
        """nd_lu_factor: an ``_NdLU`` (``overwrite`` factors a writeable ``a`` in place)."""

        return _NdLU(a, overwrite)

    # end def

    def solve(self, a, b):
        """nd_solve: numpy.linalg.solve (NumPy 2 rules)."""

        cdef _NdHold ha = _NdHold(a, 0, False)
        cdef _NdHold hb = _NdHold(b, 0, False)
        cdef ndarr_t res
        cdef int status

        nd_init_empty(&res)

        with nogil:

            status = nd_solve(_nd_ctx, &ha.arr, &hb.arr, &res)

        # end with

        _nd_status("nd_solve", status)

        return _nd_result(&res)

    # end def

    def inv(self, a):
        """nd_inv: numpy.linalg.inv (stacked)."""

        cdef _NdHold ha = _NdHold(a, 0, False)
        cdef ndarr_t res
        cdef int status

        nd_init_empty(&res)

        with nogil:

            status = nd_inv(_nd_ctx, &ha.arr, &res)

        # end with

        _nd_status("nd_inv", status)

        return _nd_result(&res)

    # end def

    def det(self, a):
        """nd_det: numpy.linalg.det (stacked; a singular matrix gives 0)."""

        cdef _NdHold ha = _NdHold(a, 0, False)
        cdef ndarr_t res
        cdef int status

        nd_init_empty(&res)

        with nogil:

            status = nd_det(_nd_ctx, &ha.arr, &res)

        # end with

        _nd_status("nd_det", status)

        return _nd_result(&res)

    # end def

    def slogdet(self, a):
        """nd_slogdet: (sign, logabsdet) as NumPy arrays (0-d for one matrix)."""

        cdef _NdHold ha = _NdHold(a, 0, False)
        cdef ndarr_t sign, logabs
        cdef int status

        nd_init_empty(&sign)
        nd_init_empty(&logabs)

        with nogil:

            status = nd_slogdet(_nd_ctx, &ha.arr, &sign, &logabs)

        # end with

        try:

            _nd_status("nd_slogdet", status)

            return nd_to_numpy(&sign, 1), nd_to_numpy(&logabs, 1)

        finally:

            nd_release(&sign)
            nd_release(&logabs)

        # end try

    # end def

    def cholesky(self, a, bint lower = True):
        """nd_cholesky: the triangular factor (numpy.linalg.cholesky for ``lower``)."""

        cdef _NdHold ha = _NdHold(a, 0, False)
        cdef ndarr_t res
        cdef int status

        nd_init_empty(&res)

        with nogil:

            status = nd_cholesky(_nd_ctx, &ha.arr, 1 if lower else 0, &res)

        # end with

        _nd_status("nd_cholesky", status)

        return _nd_result(&res)

    # end def

    def cho_solve(self, c, b, bint lower = True):
        """nd_cho_solve: solve ``A x = b`` from the Cholesky factor ``c`` of A."""

        cdef _NdHold hc = _NdHold(c, 0, False)
        cdef _NdHold hb = _NdHold(b, 0, False)
        cdef ndarr_t res
        cdef int status

        nd_init_empty(&res)

        with nogil:

            status = nd_cho_solve(_nd_ctx, &hc.arr, 1 if lower else 0, &hb.arr, &res)

        # end with

        _nd_status("nd_cho_solve", status)

        return _nd_result(&res)

    # end def

    def solve_triangular(self, t, b, bint lower = False, bint trans = False, bint unit_diagonal = False):
        """nd_solve_triangular: ``op(T) x = b`` (scipy.linalg.solve_triangular)."""

        cdef _NdHold ht = _NdHold(t, 0, False)
        cdef _NdHold hb = _NdHold(b, 0, False)
        cdef ndarr_t res
        cdef int status

        nd_init_empty(&res)

        with nogil:

            status = nd_solve_triangular(_nd_ctx, &ht.arr, &hb.arr, 1 if lower else 0,
                                         1 if trans else 0, 1 if unit_diagonal else 0, &res)

        # end with

        _nd_status("nd_solve_triangular", status)

        return _nd_result(&res)

    # end def

# end class
# -----------------------------------------------------------------------------------------------------


#: The private handle: ``pyoti.real._ndtest``.
_ndtest = _NdTest()
