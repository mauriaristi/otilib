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
from cpython.pycapsule cimport PyCapsule_IsValid, PyCapsule_GetPointer, PyCapsule_SetName
from cpython.ref cimport Py_INCREF as _nd_incref
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
