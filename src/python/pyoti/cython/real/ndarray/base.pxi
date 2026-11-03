#-----------------------------------------------------------------------------------------------------
#--------------------------   REAL NDARRAY: THE PYTHON BOUNDARY (PHASE 4)   ------------------------
#-----------------------------------------------------------------------------------------------------
# PLAN-ndarray-contracts.md sections 1.8 (the boundary), 4.4 (status mapping), 5.7 (one default
# context per Cython module), 11.11 (exports are read-only unless asked otherwise).
#
#   nd_from_object(obj, want, writeable, res)   any buffer / DLPack object -> retained ndarr_t
#   nd_to_numpy(view, writeable)                ndarr_t -> NumPy array that pins the buffer
#   _nd_status(operation, status, subject)      status -> Python exception (this module's context)
#
# This file is textually included by the Cython modules that exchange ndarr_t with Python; each such
# module has its own copy of the default context (contracts 5.7), so the last error is read here, in
# the module that made the C call.
#-----------------------------------------------------------------------------------------------------

from libc.stdlib cimport malloc as _nd_malloc, free as _nd_free
from libc.stdint cimport uint32_t as _nd_u32
from cpython.buffer cimport Py_buffer, PyObject_CheckBuffer, PyObject_GetBuffer
from cpython.buffer cimport PyBUF_RECORDS, PyBUF_RECORDS_RO
from cpython.buffer cimport PyBUF_WRITABLE, PyBUF_ND, PyBUF_STRIDES, PyBUF_FORMAT
from cpython.buffer cimport PyBUF_C_CONTIGUOUS, PyBUF_F_CONTIGUOUS, PyBUF_ANY_CONTIGUOUS
from cpython.pycapsule cimport PyCapsule_IsValid, PyCapsule_GetPointer, PyCapsule_SetName
from cpython.pycapsule cimport PyCapsule_New
from cpython.ref cimport Py_INCREF as _nd_incref, Py_DECREF as _nd_decref
from cpython.object cimport PyTypeObject

np.import_array()


#-----------------------------------------------------------------------------------------------------
#------------------------------------   Python C-API, no GIL   -------------------------------------
#-----------------------------------------------------------------------------------------------------

cdef extern from "numpy/arrayobject.h":
    # numpy.pxd keeps PyArray_NewFromDescr commented out. It STEALS a reference to descr.
    object _nd_new_from_descr "PyArray_NewFromDescr"(PyTypeObject* subtype, np.dtype descr, int nd,
                                                    np.npy_intp* dims, np.npy_intp* strides, void* data,
                                                    int flags, object obj)


cdef extern from "Python.h" nogil:
    ctypedef int _NdGILState "PyGILState_STATE"
    _NdGILState _nd_gil_ensure "PyGILState_Ensure"()
    void _nd_gil_release "PyGILState_Release"(_NdGILState state)
    int _nd_is_finalizing "Py_IsFinalizing"()
    void _nd_buffer_release "PyBuffer_Release"(Py_buffer* view)

    ctypedef struct _NdPyObject "PyObject":
        pass

    void _nd_decref_nogil "Py_DECREF"(_NdPyObject* op)


#-----------------------------------------------------------------------------------------------------
#------------------------------------   DLPack structures   ----------------------------------------
#-----------------------------------------------------------------------------------------------------
# DLTensor is oti_dltensor_t (bit-compatible, structures.h). The managed wrappers are DLPack 1.x's.

cdef struct _NdDLPackVersion:
    _nd_u32 major
    _nd_u32 minor

cdef struct _NdDLManaged:
    oti_dltensor_t dl_tensor
    void* manager_ctx
    void (*deleter)(_NdDLManaged*) noexcept nogil

cdef struct _NdDLManagedVersioned:
    _NdDLPackVersion version
    void* manager_ctx
    void (*deleter)(_NdDLManagedVersioned*) noexcept nogil
    uint64_t flags
    oti_dltensor_t dl_tensor

cdef struct _NdDlHolder:
    void* tensor
    int versioned

cdef enum:
    _ND_DL_FLAG_READ_ONLY = 1
    _ND_KDLCPU = 1


#-----------------------------------------------------------------------------------------------------
#------------------------------------   MODULE CONTEXT   -------------------------------------------
#-----------------------------------------------------------------------------------------------------
# NULL is this module's default context (a thread-local last error). The private test handle may
# install a user context with byte budgets (_ndtest.set_limits); every call below uses _nd_ctx.

cdef oti_ctx  _nd_user_ctx
cdef oti_ctx* _nd_ctx = NULL


#-----------------------------------------------------------------------------------------------------
#------------------------------------   STATUS -> EXCEPTION   --------------------------------------
#-----------------------------------------------------------------------------------------------------

# *****************************************************************************************************
cdef str _nd_busy_reason(const ndarr_t* subject):
    """
    Say why a growth or an export was refused (contracts 4.4, critic W1 finding 10.3).

    Parameters
    ----------
    subject : const ndarr_t*
        The array the call was made on, or NULL.

    Returns
    -------
    str
        A reason that names a live export when the buffer has one.
    """

    cdef int64_t exports, refs

    if subject != NULL and subject.buf != NULL:

        exports = nd_buffer_exports(subject.buf)
        refs    = nd_buffer_refs(subject.buf)

        if exports > 0:

            return ("the buffer has %d live export(s): NumPy arrays or DLPack tensors still view its "
                    "memory; release them first, or reserve capacity at creation (reserve(...), "
                    "nbases= / order=)" % exports)

        # end if

        if refs > 1:

            return ("the buffer has %d live reference(s): views still share it; release them first, "
                    "or reserve capacity at creation (reserve(...), nbases= / order=)" % (refs - 1))

        # end if

    # end if

    return "the buffer is borrowed foreign memory or is not growable"

# end function
# -----------------------------------------------------------------------------------------------------


# *****************************************************************************************************
cdef int _nd_status(str operation, int status, const ndarr_t* subject = NULL) except -1:
    """
    Raise the Python exception of a failed C call (contracts 4.4); do nothing for a success.

    Parameters
    ----------
    operation : str
        Name of the operation, the first words of the message.
    status : int
        OTI_OK (0), a negative OTI_ERR_* status or a positive LAPACK info.
    subject : const ndarr_t*
        The array the call acted on (used to explain OTI_ERR_BUSY), or NULL.

    Returns
    -------
    int
        0 when status is OTI_OK; otherwise an exception is raised.
    """

    cdef const char* where = NULL
    cdef const char* msg   = NULL
    cdef int last
    cdef str text

    if status == OTI_OK:

        return 0

    # end if

    if status > 0:

        raise np.linalg.LinAlgError("{}: LAPACK info = {}".format(operation, status))

    # end if

    text = "{}: {}".format(operation, oti_status_string(status).decode())

    # The last error of THIS module's context, when it belongs to this status.
    last = oti_ctx_last_error(_nd_ctx, &where, &msg)

    if last == status:

        if where != NULL:

            text += " (in {}".format((<bytes>where).decode())

            if msg != NULL:

                text += ": {}".format((<bytes>msg).decode())

            # end if

            text += ")"

        elif msg != NULL:

            text += " ({})".format((<bytes>msg).decode())

        # end if

    # end if

    if status == OTI_ERR_BUSY:

        raise BufferError(text + ": " + _nd_busy_reason(subject))

    # end if

    if status == OTI_ERR_MEMORY:

        raise MemoryError(text)

    # end if

    if status == OTI_ERR_INDEX:

        raise IndexError(text)

    # end if

    if status == OTI_ERR_DTYPE:

        raise TypeError(text)

    # end if

    if status == OTI_ERR_CONVERGE or status == OTI_ERR_NOTPD:

        raise np.linalg.LinAlgError(text)

    # end if

    if status == OTI_ERR_BACKEND:

        raise RuntimeError(text)

    # end if

    # SIZE, PIVOT, ARGUMENT, SHAPE, LAYOUT, READONLY and any status added later.
    raise ValueError(text)

# end function
# -----------------------------------------------------------------------------------------------------


#-----------------------------------------------------------------------------------------------------
#------------------------------------   RELEASE CALLBACKS   ----------------------------------------
#-----------------------------------------------------------------------------------------------------
# They run exactly once, on the host thread that drops the last reference to the buffer (or inside
# nd_import on its failure / conversion paths). That thread may not hold the GIL, and with
# free-threaded Python two threads may release concurrently, so each callback takes the GIL state.
# During interpreter finalization they return without touching Python: a deliberate leak (contracts
# 1.5).

# *****************************************************************************************************
cdef void _nd_release_pybuffer(void* ctx) noexcept nogil:
    """
    End a PEP 3118 export: PyBuffer_Release under the GIL, then free the Py_buffer.

    Parameters
    ----------
    ctx : void*
        The heap-allocated Py_buffer given to nd_import.
    """

    cdef Py_buffer* view = <Py_buffer*>ctx
    cdef _NdGILState state

    if _nd_is_finalizing():

        return

    # end if

    state = _nd_gil_ensure()
    _nd_buffer_release(view)
    _nd_gil_release(state)
    _nd_free(view)

# end function
# -----------------------------------------------------------------------------------------------------


# *****************************************************************************************************
cdef void _nd_release_dlpack(void* ctx) noexcept nogil:
    """
    End a DLPack import: call the managed tensor's deleter (NULL allowed) under the GIL.

    Parameters
    ----------
    ctx : void*
        The _NdDlHolder given to nd_import.
    """

    cdef _NdDlHolder* holder = <_NdDlHolder*>ctx
    cdef _NdDLManaged* managed
    cdef _NdDLManagedVersioned* versioned
    cdef _NdGILState state

    if _nd_is_finalizing():

        return

    # end if

    state = _nd_gil_ensure()

    if holder.versioned:

        versioned = <_NdDLManagedVersioned*>holder.tensor

        if versioned.deleter != NULL:

            versioned.deleter(versioned)

        # end if

    else:

        managed = <_NdDLManaged*>holder.tensor

        if managed.deleter != NULL:

            managed.deleter(managed)

        # end if

    # end if

    _nd_gil_release(state)
    _nd_free(holder)

# end function
# -----------------------------------------------------------------------------------------------------


#-----------------------------------------------------------------------------------------------------
#------------------------------------   nd_from_object   -------------------------------------------
#-----------------------------------------------------------------------------------------------------

# *****************************************************************************************************
cdef int _nd_from_buffer(object obj, int32_t want, int writeable, int32_t iflags, ndarr_t* res) except *:
    """
    Import an object that supports the buffer protocol (contracts 1.8, step 1).

    Parameters
    ----------
    obj : object
        Buffer exporter.
    want : int32_t
        OTI_F64, OTI_I64, OTI_U8 or 0 for the natural type.
    writeable : int
        1 for an output (out=): no conversion, the exporter must be writeable.
    iflags : int32_t
        Extra ND_IMPORT_* flags (ND_IMPORT_WRITEABLE is added by writeable).
    res : ndarr_t*
        Receives the retained array (empty on failure).

    Returns
    -------
    int
        OTI_OK or an OTI_ERR_* status.
    """

    cdef Py_buffer* view
    cdef nd_import_t imp
    cdef int64_t shape[OTI_ND_MAXDIM]
    cdef int64_t bstrides[OTI_ND_MAXDIM]
    cdef int status
    cdef int k

    view = <Py_buffer*>_nd_malloc(sizeof(Py_buffer))

    if view == NULL:

        raise MemoryError("nd_from_object: cannot allocate the buffer description")

    # end if

    try:

        PyObject_GetBuffer(obj, view, PyBUF_RECORDS if writeable else PyBUF_RECORDS_RO)

    except (BufferError, ValueError):

        # A writeable request on a read-only exporter: BufferError (bytes, memoryview, ...) or, for
        # NumPy, ValueError("buffer source array is read-only").
        _nd_free(view)

        if writeable:

            return OTI_ERR_READONLY

        # end if

        raise

    except BaseException:

        _nd_free(view)
        raise

    # end try

    if view.suboffsets != NULL:

        _nd_release_pybuffer(view)
        return OTI_ERR_LAYOUT

    # end if

    if view.ndim > OTI_ND_MAXDIM or view.ndim < 0:

        _nd_release_pybuffer(view)
        return OTI_ERR_SHAPE

    # end if

    status = nd_pep3118_classify(view.format, view.itemsize, &imp.src)

    if status != OTI_OK:

        _nd_release_pybuffer(view)
        return status

    # end if

    # Py_ssize_t -> int64_t through local arrays (no assumption on the width of Py_ssize_t).
    for k in range(view.ndim):

        shape[k] = view.shape[k]

        if view.strides != NULL:

            bstrides[k] = view.strides[k]

        # end if

    # end for

    imp.data         = view.buf
    imp.ndim         = view.ndim
    imp.readonly     = view.readonly
    imp.shape        = shape
    imp.byte_strides = bstrides if view.strides != NULL else NULL
    imp.device_type  = OTI_DEVICE_CPU
    imp.reserved     = 0

    if writeable:

        iflags |= ND_IMPORT_WRITEABLE

    # end if

    # The callback now belongs to the library, on every path (it releases the view).
    with nogil:

        status = nd_import(_nd_ctx, &imp, want, iflags, _nd_release_pybuffer, view, res)

    # end with

    return status

# end function
# -----------------------------------------------------------------------------------------------------


# *****************************************************************************************************
cdef int _nd_from_dlpack(object obj, int32_t want, int writeable, int32_t iflags, ndarr_t* res) except *:
    """
    Import an object that exports DLPack (contracts 1.8, step 2).

    Parameters
    ----------
    obj : object
        Object with __dlpack__ (and __dlpack_device__).
    want : int32_t
        OTI_F64, OTI_I64, OTI_U8 or 0 for the natural type.
    writeable : int
        1 for an output (out=).
    iflags : int32_t
        Extra ND_IMPORT_* flags.
    res : ndarr_t*
        Receives the retained array (empty on failure).

    Returns
    -------
    int
        OTI_OK or an OTI_ERR_* status.
    """

    cdef object device, capsule
    cdef int versioned = 0
    cdef _NdDLManaged* managed = NULL
    cdef _NdDLManagedVersioned* mversioned = NULL
    cdef oti_dltensor_t* dl
    cdef nd_import_t imp
    cdef _NdDlHolder* holder
    cdef int64_t shape[OTI_ND_MAXDIM]
    cdef int64_t bstrides[OTI_ND_MAXDIM]
    cdef int64_t itemsize, limit
    cdef int readonly = 0
    cdef int status
    cdef int k

    # The device first: never export a tensor that this library cannot read.
    device = obj.__dlpack_device__()

    if int(device[0]) != _ND_KDLCPU or int(device[1]) != 0:

        return OTI_ERR_ARGUMENT

    # end if

    try:

        try:

            capsule = obj.__dlpack__(max_version=(1, 0))

        except TypeError:

            capsule = obj.__dlpack__()

        # end try

    except BufferError:

        # NumPy: a read-only array raises BufferError on the legacy call.
        return OTI_ERR_READONLY if writeable else OTI_ERR_DTYPE

    # end try

    if PyCapsule_IsValid(capsule, "dltensor_versioned"):

        versioned  = 1
        mversioned = <_NdDLManagedVersioned*>PyCapsule_GetPointer(capsule, "dltensor_versioned")

        if mversioned.version.major != 1:

            # Not renamed yet: the capsule's own destructor still owns the deleter.
            return OTI_ERR_DTYPE

        # end if

        dl       = &mversioned.dl_tensor
        readonly = 1 if (mversioned.flags & _ND_DL_FLAG_READ_ONLY) else 0

    elif PyCapsule_IsValid(capsule, "dltensor"):

        managed = <_NdDLManaged*>PyCapsule_GetPointer(capsule, "dltensor")
        dl      = &managed.dl_tensor

    else:

        return OTI_ERR_DTYPE

    # end if

    # Everything that can fail without owning the tensor comes before the rename.
    if dl.ndim > OTI_ND_MAXDIM or dl.ndim < 0:

        return OTI_ERR_SHAPE

    # end if

    status = nd_dlpack_classify(dl.dtype.code, dl.dtype.bits, dl.dtype.lanes, &imp.src)

    if status != OTI_OK:

        return status

    # end if

    itemsize = imp.src.itemsize
    limit    = INT64_MAX // itemsize if itemsize > 0 else 0

    for k in range(dl.ndim):

        shape[k] = dl.shape[k]

        if dl.strides != NULL:

            # Element strides to byte strides, checked.
            if dl.strides[k] > limit or dl.strides[k] < -limit:

                return OTI_ERR_SIZE

            # end if

            bstrides[k] = dl.strides[k] * itemsize

        # end if

    # end for

    holder = <_NdDlHolder*>_nd_malloc(sizeof(_NdDlHolder))

    if holder == NULL:

        raise MemoryError("nd_from_object: cannot allocate the DLPack holder")

    # end if

    holder.versioned = versioned
    holder.tensor    = <void*>mversioned if versioned else <void*>managed

    # The consumer rule: rename the capsule, and the deleter is now ours.
    if versioned:

        PyCapsule_SetName(capsule, "used_dltensor_versioned")

    else:

        PyCapsule_SetName(capsule, "used_dltensor")

    # end if

    imp.data         = <void*>(<char*>dl.data + dl.byte_offset)
    imp.ndim         = dl.ndim
    imp.readonly     = readonly
    imp.shape        = shape
    imp.byte_strides = bstrides if dl.strides != NULL else NULL
    imp.device_type  = dl.device.device_type
    imp.reserved     = 0

    if writeable:

        iflags |= ND_IMPORT_WRITEABLE

    # end if

    with nogil:

        status = nd_import(_nd_ctx, &imp, want, iflags, _nd_release_dlpack, holder, res)

    # end with

    return status

# end function
# -----------------------------------------------------------------------------------------------------


# *****************************************************************************************************
cdef int nd_from_object(object obj, int32_t want, int writeable, ndarr_t* res,
                        int32_t iflags = 0) except *:
    """
    Import a Python object as a retained ndarr_t: the buffer protocol first, then DLPack (S16).

    Zero-copy when the element type, alignment and strides allow it (the result then keeps the
    exporter alive through a release callback); otherwise a converted copy in a new library array
    (nd_import; the format table of contracts 2.2). A list, a scalar or any other object without
    either protocol is OTI_ERR_DTYPE: convert it with numpy.asarray first.

    Parameters
    ----------
    obj : object
        Buffer exporter or DLPack producer.
    want : int32_t
        OTI_F64, OTI_I64, OTI_U8, or 0 for the natural type.
    writeable : int
        1 for an output (out=): zero-copy only, the exporter must be writeable.
    res : ndarr_t*
        Receives the retained array; empty on failure. Release it with nd_release.
    iflags : int32_t
        Extra ND_IMPORT_* flags (ND_IMPORT_COPY always copies).

    Returns
    -------
    int
        OTI_OK or an OTI_ERR_* status; pass it to _nd_status(). Python errors raised by the exporter
        itself propagate as exceptions.
    """

    nd_init_empty(res)

    if PyObject_CheckBuffer(obj):

        return _nd_from_buffer(obj, want, writeable, iflags, res)

    # end if

    if hasattr(obj, "__dlpack__") and hasattr(obj, "__dlpack_device__"):

        return _nd_from_dlpack(obj, want, writeable, iflags, res)

    # end if

    return OTI_ERR_DTYPE

# end function
# -----------------------------------------------------------------------------------------------------


#-----------------------------------------------------------------------------------------------------
#------------------------------------   nd_to_numpy   ----------------------------------------------
#-----------------------------------------------------------------------------------------------------

# *****************************************************************************************************
cdef class _NdExport:
    """
    Base object of an exported NumPy array: holds one retained, exported ndarr_t.

    Its deallocation ends the export (nd_release). It is private; NumPy arrays returned by
    nd_to_numpy keep it as their ``base``.
    """

    cdef ndarr_t arr
    cdef Py_ssize_t pshape[OTI_ND_MAXDIM]       # Py_buffer.shape of a buffer export (elements)
    cdef Py_ssize_t pstrides[OTI_ND_MAXDIM]     # Py_buffer.strides of a buffer export (BYTES)

    def __cinit__(self):

        nd_init_empty(&self.arr)

    # end def

    def __dealloc__(self):

        # May run the foreign release callback (it takes the GIL state itself).
        nd_release(&self.arr)

    # end def

# end class
# -----------------------------------------------------------------------------------------------------


# *****************************************************************************************************
cdef int _nd_typenum(int32_t dtype) except -1:
    """
    NumPy type number of an ndarray dtype: F64 -> double, I64 -> int64, U8 -> bool (never uint8).
    """

    if dtype == OTI_F64:

        return np.NPY_DOUBLE

    # end if

    if dtype == OTI_I64:

        return np.NPY_INT64

    # end if

    if dtype == OTI_U8:

        # A mask is a NumPy bool: uint8 would be an integer index to NumPy.
        return np.NPY_BOOL

    # end if

    raise SystemError("internal error: unknown ndarray dtype {}".format(dtype))

# end function
# -----------------------------------------------------------------------------------------------------


# *****************************************************************************************************
cdef object _nd_new_array(const ndarr_t* view, int typenum, void* data, int flags):
    """
    A NumPy array over the memory of a descriptor (no base object, no copy).
    """

    cdef np.npy_intp dims[OTI_ND_MAXDIM]
    cdef np.npy_intp strd[OTI_ND_MAXDIM]
    cdef np.dtype descr = np.PyArray_DescrFromType(typenum)
    cdef np.npy_intp itemsize = <np.npy_intp>nd_itemsize(view.dtype)
    cdef int k

    for k in range(view.ndim):

        dims[k] = <np.npy_intp>view.shape[k]
        strd[k] = <np.npy_intp>view.strides[k] * itemsize

    # end for

    # PyArray_NewFromDescr steals a reference to the descriptor; Cython keeps its own.
    _nd_incref(descr)

    return _nd_new_from_descr(<PyTypeObject*>np.ndarray, descr, view.ndim, dims, strd, data, flags, None)

# end function
# -----------------------------------------------------------------------------------------------------


# *****************************************************************************************************
cdef object nd_to_numpy(const ndarr_t* view, int writeable):
    """
    Export a descriptor as a NumPy array that shares its memory and pins the buffer.

    The array's base object holds one retained reference that also counts as an export (contracts
    S3): the buffer cannot be grown or relaid out while the array lives ("live export", BufferError).
    ``writeable`` = 0 gives a read-only array (the OTI default, 11.11); 1 on a read-only source is
    ValueError (OTI_ERR_READONLY). The element type is explicit: F64 -> float64, I64 -> int64 and
    U8 -> bool.

    A trusted temporary (``buf == NULL``: nd_from_view, nd_wrap_trusted, the Fortran shim) cannot be
    exported, because nothing owns its memory: nd_to_numpy COPIES it (keeping the K order) into a
    fresh array with no base. A zero-size view with ``data == NULL`` also returns a fresh empty array.

    Parameters
    ----------
    view : const ndarr_t*
        Well-formed descriptor (temporary or retained).
    writeable : int
        1 for a writeable array, 0 for a read-only one.

    Returns
    -------
    numpy.ndarray
        The array.
    """

    cdef _NdExport base
    cdef int status
    cdef int typenum = _nd_typenum(view.dtype)
    cdef np.ndarray arr
    cdef int flags

    if view.data == NULL or view.buf == NULL:

        # No memory to pin: a fresh array, a copy when there is data to preserve.
        if view.data == NULL:

            arr = np.empty(tuple([view.shape[k] for k in range(view.ndim)]),
                           dtype=(np.float64 if view.dtype == OTI_F64 else
                                  np.int64 if view.dtype == OTI_I64 else np.bool_))

        else:

            arr = _nd_new_array(view, typenum, view.data, 0)
            arr = np.PyArray_NewCopy(arr, np.NPY_KEEPORDER)

        # end if

        if not writeable:

            np.PyArray_CLEARFLAGS(arr, np.NPY_ARRAY_WRITEABLE)

        # end if

        return arr

    # end if

    base = _NdExport.__new__(_NdExport)
    status = nd_export(view, writeable, &base.arr)
    _nd_status("nd_to_numpy", status, view)

    flags = np.NPY_ARRAY_WRITEABLE if (base.arr.flags & ND_WRITEABLE) else 0
    arr = _nd_new_array(&base.arr, typenum, base.arr.data, flags)

    # PyArray_SetBaseObject steals a reference to the base object.
    _nd_incref(base)
    np.PyArray_SetBaseObject(arr, base)

    return arr

# end function
# -----------------------------------------------------------------------------------------------------


#-----------------------------------------------------------------------------------------------------
#------------------------------   PRODUCERS: DLPack and buffer protocol   ---------------------------
#-----------------------------------------------------------------------------------------------------
# PLAN-ndarray-contracts.md 7.4 and 11.11; critic W2 finding 6. They are generic over a view (an
# ndarr_t descriptor): dmat uses them in 6b, the OTI classes of 7b reuse them for their block arrays.
# Every export is one _NdExport: it holds a retained, exported ndarr_t (so a live export blocks
# growth with the "live export" BufferError text) and is the DLPack ``manager_ctx`` / the Py_buffer's
# ``internal``. A foreign consumer may release on ANY thread: the deleter takes the GIL state.

cdef const char* _ND_DLPACK_NAME_V  = b"dltensor_versioned"
cdef const char* _ND_DLPACK_NAME    = b"dltensor"
cdef const char* _ND_DLPACK_USED_V  = b"used_dltensor_versioned"
cdef const char* _ND_DLPACK_USED    = b"used_dltensor"

cdef const char* _ND_FMT_F64 = b"d"
cdef const char* _ND_FMT_I64 = b"q"
cdef const char* _ND_FMT_U8  = b"?"
cdef const char* _ND_FMT_BYTE = b"B"

cdef enum:
    _ND_DL_FLAG_IS_COPIED = 2


# *****************************************************************************************************
cdef void _nd_dl_delete_versioned(_NdDLManagedVersioned* mt) noexcept nogil:
    """
    Deleter of a DLManagedTensorVersioned made by nd_to_dlpack: drop the base object, free the struct.

    May run on any thread, with or without the GIL: it takes the GIL state. At interpreter shutdown
    the reference is leaked on purpose (contracts 1.5).
    """

    cdef _NdGILState state

    if mt.manager_ctx != NULL and not _nd_is_finalizing():

        state = _nd_gil_ensure()
        _nd_decref_nogil(<_NdPyObject*>mt.manager_ctx)
        _nd_gil_release(state)

    # end if

    _nd_free(mt)

# end function
# -----------------------------------------------------------------------------------------------------


# *****************************************************************************************************
cdef void _nd_dl_delete_legacy(_NdDLManaged* mt) noexcept nogil:
    """
    Deleter of an unversioned DLManagedTensor made by nd_to_dlpack (same rules as the versioned one).
    """

    cdef _NdGILState state

    if mt.manager_ctx != NULL and not _nd_is_finalizing():

        state = _nd_gil_ensure()
        _nd_decref_nogil(<_NdPyObject*>mt.manager_ctx)
        _nd_gil_release(state)

    # end if

    _nd_free(mt)

# end function
# -----------------------------------------------------------------------------------------------------


# *****************************************************************************************************
cdef void _nd_capsule_destructor(object capsule) noexcept:
    """
    Destructor of a DLPack capsule nobody consumed: call the deleter (a consumer renames the capsule
    to ``used_dltensor*`` and then owns the deleter, so a renamed capsule does nothing here).
    """

    cdef _NdDLManagedVersioned* versioned
    cdef _NdDLManaged* legacy

    if PyCapsule_IsValid(capsule, _ND_DLPACK_NAME_V):

        versioned = <_NdDLManagedVersioned*>PyCapsule_GetPointer(capsule, _ND_DLPACK_NAME_V)

        if versioned != NULL and versioned.deleter != NULL:

            versioned.deleter(versioned)

        # end if

    elif PyCapsule_IsValid(capsule, _ND_DLPACK_NAME):

        legacy = <_NdDLManaged*>PyCapsule_GetPointer(capsule, _ND_DLPACK_NAME)

        if legacy != NULL and legacy.deleter != NULL:

            legacy.deleter(legacy)

        # end if

    # end if

# end function
# -----------------------------------------------------------------------------------------------------


# *****************************************************************************************************
cdef _NdExport _nd_export_base(const ndarr_t* view, int writeable, int force_copy, int* copied):
    """
    One retained, exported descriptor of a view, in a fresh base object.

    A trusted temporary (``buf == NULL``) or ``force_copy`` exports a K-order copy instead: nothing
    owns the memory of a temporary, so it cannot be pinned (the same rule as nd_to_numpy).

    Parameters
    ----------
    view : const ndarr_t*
        Well-formed descriptor.
    writeable : int
        1 for a writeable export (the view must be ND_WRITEABLE), 0 for a read-only one.
    force_copy : int
        1 to export a copy even when the memory could be shared.
    copied : int*
        Set to 1 when a copy was exported, else 0.

    Returns
    -------
    _NdExport
        The base object (its ``arr`` is the exported descriptor).
    """

    cdef _NdExport base = _NdExport.__new__(_NdExport)
    cdef ndarr_t tmp
    cdef int status

    copied[0] = 0

    if view.buf == NULL or force_copy:

        if writeable and not (view.flags & ND_WRITEABLE):

            _nd_status("export", OTI_ERR_READONLY, view)

        # end if

        nd_init_empty(&tmp)
        with nogil:

            status = nd_copy(_nd_ctx, view, ND_LAYOUT_K, &tmp)

        # end with

        if status != OTI_OK:

            _nd_status("export", status, view)

        # end if

        status = nd_export(&tmp, writeable, &base.arr)
        nd_release(&tmp)
        copied[0] = 1

    else:

        status = nd_export(view, writeable, &base.arr)

    # end if

    _nd_status("export", status, view)

    return base

# end function
# -----------------------------------------------------------------------------------------------------


# Test hook (_ndtest.fail_capsule): the next capsule creation fails.
cdef int _nd_test_fail_capsule = 0


# *****************************************************************************************************
cdef object _nd_capsule_new(void* tensor, int versioned):
    """
    Wrap a managed tensor in a capsule; if that fails (MemoryError), call the tensor's deleter before
    re-raising, because ownership passes to the capsule only once it exists (the deleter drops the
    base-object reference and frees the tensor).

    Parameters
    ----------
    tensor : void*
        The managed tensor (a _NdDLManagedVersioned if ``versioned``, else a _NdDLManaged).
    versioned : int
        1 for the ``dltensor_versioned`` capsule, 0 for the legacy ``dltensor`` one.
    """

    global _nd_test_fail_capsule

    try:

        if _nd_test_fail_capsule > 0:

            _nd_test_fail_capsule -= 1
            raise MemoryError("capsule allocation failed (test hook)")

        # end if

        return PyCapsule_New(tensor, _ND_DLPACK_NAME_V if versioned else _ND_DLPACK_NAME,
                             _nd_capsule_destructor)

    except BaseException:

        if versioned:

            _nd_dl_delete_versioned(<_NdDLManagedVersioned*>tensor)

        else:

            _nd_dl_delete_legacy(<_NdDLManaged*>tensor)

        # end if

        raise

    # end try

# end function
# -----------------------------------------------------------------------------------------------------


# *****************************************************************************************************
cdef object nd_to_dlpack(const ndarr_t* view, int writeable, int versioned = 1, int copy = 0):
    """
    Export a descriptor as a DLPack capsule that shares its memory and pins the buffer.

    ``versioned`` = 1 (the default) gives a ``"dltensor_versioned"`` capsule (DLPack 1.0) with the
    READ_ONLY flag set when ``writeable`` is 0; ``versioned`` = 0 gives the legacy ``"dltensor"``
    capsule, which cannot say "read-only": it is refused (BufferError) for a read-only export. The
    managed tensor's ``manager_ctx`` is the base object (one reference), and its deleter drops that
    reference under the GIL state, so a consumer may release it on any thread. A trusted temporary
    (``buf == NULL``) or ``copy`` = 1 exports a copy (IS_COPIED flag).

    Parameters
    ----------
    view : const ndarr_t*
        Well-formed descriptor.
    writeable : int
        1 for a writeable export (``view`` must be ND_WRITEABLE), 0 for a read-only one.
    versioned : int
        1 for DLPack 1.x, 0 for the legacy capsule.
    copy : int
        1 to export a copy.

    Returns
    -------
    PyCapsule
        The capsule (consume it once, as DLPack says).
    """

    cdef _NdExport base
    cdef oti_view v
    cdef _NdDLManagedVersioned* mv
    cdef _NdDLManaged* ml
    cdef int copied

    if not versioned and not writeable:

        raise BufferError("a read-only array cannot be exported as an unversioned DLPack capsule: "
                          "ask for max_version >= (1, 0)")

    # end if

    base = _nd_export_base(view, writeable, copy, &copied)

    v.struct_size = sizeof(oti_view)
    _nd_status("nd_to_view", nd_to_view(&base.arr, &v))

    if versioned:

        mv = <_NdDLManagedVersioned*>_nd_malloc(sizeof(_NdDLManagedVersioned))

        if mv == NULL:

            raise MemoryError("DLPack: cannot allocate the managed tensor")

        # end if

        mv.version.major = 1
        mv.version.minor = 0
        mv.flags = ((0 if writeable else _ND_DL_FLAG_READ_ONLY) |
                    (_ND_DL_FLAG_IS_COPIED if copied else 0))
        mv.dl_tensor = v.dl
        mv.deleter = _nd_dl_delete_versioned

        _nd_incref(base)
        mv.manager_ctx = <void*>base

        return _nd_capsule_new(mv, 1)

    # end if

    ml = <_NdDLManaged*>_nd_malloc(sizeof(_NdDLManaged))

    if ml == NULL:

        raise MemoryError("DLPack: cannot allocate the managed tensor")

    # end if

    ml.dl_tensor = v.dl
    ml.deleter = _nd_dl_delete_legacy

    _nd_incref(base)
    ml.manager_ctx = <void*>base

    return _nd_capsule_new(ml, 0)

# end function
# -----------------------------------------------------------------------------------------------------


# *****************************************************************************************************
cdef object nd_dlpack_call(const ndarr_t* view, int writeable_ok, object stream, object max_version,
                           object dl_device, object copy):
    """
    The body of ``__dlpack__(stream=None, max_version=None, dl_device=None, copy=None)`` for a view.

    A CPU-only producer: ``dl_device`` other than None / (1, 0) is BufferError; ``stream`` is ignored
    (it is meaningless on the CPU). ``max_version`` None or with major < 1 selects the legacy capsule;
    otherwise the versioned one. ``copy=True`` exports a copy, ``copy=False`` refuses to (a trusted
    temporary then raises BufferError), ``None`` copies only when it must.

    Parameters
    ----------
    view : const ndarr_t*
        The array to export.
    writeable_ok : int
        1 if the object allows writing through the export (the export is then writeable when the
        view is), 0 for a read-only object.
    stream, max_version, dl_device, copy : object
        The ``__dlpack__`` arguments.

    Returns
    -------
    PyCapsule
        The capsule.
    """

    cdef int versioned = 0
    cdef int writeable = 1 if (writeable_ok and (view.flags & ND_WRITEABLE)) else 0

    if dl_device is not None:

        if (not isinstance(dl_device, (tuple, list)) or len(dl_device) != 2 or
                dl_device[0] != _ND_KDLCPU or dl_device[1] != 0):

            raise BufferError("only the CPU device (1, 0) is supported, got {!r}".format(dl_device))

        # end if

    # end if

    if max_version is not None:

        if (not isinstance(max_version, (tuple, list)) or len(max_version) != 2):

            raise TypeError("max_version must be a (major, minor) tuple or None")

        # end if

        versioned = 1 if max_version[0] >= 1 else 0

    # end if

    if copy is False and view.buf == NULL:

        raise BufferError("copy=False: this array is a temporary and can only be exported as a copy")

    # end if

    return nd_to_dlpack(view, writeable, versioned, 1 if copy is True else 0)

# end function
# -----------------------------------------------------------------------------------------------------


# *****************************************************************************************************
cdef int nd_getbuffer(const ndarr_t* view, int writeable_ok, Py_buffer* buffer, int flags,
                      object owner) except -1:
    """
    Fill a Py_buffer for a view: the body of ``__getbuffer__`` (PEP 3118).

    The export is one _NdExport, kept in ``buffer.internal`` (one reference) and counted as an export
    of the buffer; ``nd_releasebuffer`` ends it. The memory is exported writeable whenever the object
    allows it (``writeable_ok`` and an ND_WRITEABLE view), whether or not PyBUF_WRITABLE was asked
    (the buffer then says ``readonly = 0``); asking for PyBUF_WRITABLE on a read-only object is
    BufferError. Strides, shape and format are given when asked for; a request that needs contiguity
    (PyBUF_SIMPLE, PyBUF_ND, PyBUF_*_CONTIGUOUS) on a strided view is BufferError.

    Parameters
    ----------
    view : const ndarr_t*
        The array to export.
    writeable_ok : int
        1 if the object allows writing through the export.
    buffer : Py_buffer*
        The buffer to fill.
    flags : int
        The PyBUF_* request.
    owner : object
        The exporting object (``buffer.obj``).
    """

    cdef _NdExport base
    cdef int copied
    cdef int writeable = 1 if (writeable_ok and (view.flags & ND_WRITEABLE)) else 0
    cdef int wants_nd      = (flags & PyBUF_ND) == PyBUF_ND
    cdef int wants_strides = (flags & PyBUF_STRIDES) == PyBUF_STRIDES
    cdef int c_ok = view.flags & ND_C_CONTIG
    cdef int f_ok = view.flags & ND_F_CONTIG
    cdef int64_t itemsize = nd_itemsize(view.dtype)
    cdef int k

    if (flags & PyBUF_WRITABLE) == PyBUF_WRITABLE and not writeable:

        raise BufferError("the array is read-only: a writable buffer cannot be exported")

    # end if

    if (flags & PyBUF_C_CONTIGUOUS) == PyBUF_C_CONTIGUOUS and not c_ok:

        raise BufferError("the array is not C-contiguous")

    # end if

    if (flags & PyBUF_F_CONTIGUOUS) == PyBUF_F_CONTIGUOUS and not f_ok:

        raise BufferError("the array is not Fortran-contiguous")

    # end if

    if (flags & PyBUF_ANY_CONTIGUOUS) == PyBUF_ANY_CONTIGUOUS and not (c_ok or f_ok):

        raise BufferError("the array is not contiguous")

    # end if

    if not wants_strides and not c_ok:

        raise BufferError("the array is not C-contiguous: ask for strides (PyBUF_STRIDES)")

    # end if

    base = _nd_export_base(view, writeable, 0, &copied)

    for k in range(base.arr.ndim):

        base.pshape[k]   = <Py_ssize_t>base.arr.shape[k]
        base.pstrides[k] = <Py_ssize_t>(base.arr.strides[k] * itemsize)

    # end for

    buffer.buf        = base.arr.data if base.arr.data != NULL else <void*>&base.arr
    buffer.len        = <Py_ssize_t>(nd_size(&base.arr) * itemsize)
    buffer.readonly   = 0 if writeable else 1
    buffer.suboffsets = NULL

    if wants_nd:

        buffer.itemsize = <Py_ssize_t>itemsize
        buffer.ndim     = base.arr.ndim
        buffer.shape    = base.pshape if base.arr.ndim > 0 else NULL
        buffer.strides  = base.pstrides if (wants_strides and base.arr.ndim > 0) else NULL
        buffer.format   = NULL

        if (flags & PyBUF_FORMAT) == PyBUF_FORMAT:

            buffer.format = <char*>(_ND_FMT_F64 if base.arr.dtype == OTI_F64 else
                                    _ND_FMT_I64 if base.arr.dtype == OTI_I64 else _ND_FMT_U8)

        # end if

    else:

        # PyBUF_SIMPLE (like PyBuffer_FillInfo): a flat run of bytes.
        buffer.itemsize = 1
        buffer.ndim     = 1
        buffer.shape    = NULL
        buffer.strides  = NULL
        buffer.format   = <char*>_ND_FMT_BYTE if (flags & PyBUF_FORMAT) == PyBUF_FORMAT else NULL

    # end if

    _nd_incref(base)
    buffer.internal = <void*>base
    buffer.obj      = owner

    return 0

# end function
# -----------------------------------------------------------------------------------------------------


# *****************************************************************************************************
cdef void nd_releasebuffer(Py_buffer* buffer) noexcept:
    """
    End a buffer export started by nd_getbuffer: the body of ``__releasebuffer__``.

    ``noexcept``: it can run while another exception is pending (a failed request on the same
    object), which must be left alone.
    """

    cdef _NdExport base

    if buffer.internal != NULL:

        base = <_NdExport>buffer.internal
        buffer.internal = NULL
        _nd_decref(base)

    # end if

# end function
# -----------------------------------------------------------------------------------------------------
