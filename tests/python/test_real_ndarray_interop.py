"""
Check the Python boundary of the real ndarray core (contracts 1.8, 2.2, 5.7 and critic finding 10).

Everything goes through the private handle ``pyoti.real._ndtest``: ``roundtrip`` runs ``nd_from_object``
then ``nd_to_numpy``, ``import_info`` describes what ``nd_from_object`` made of an object, ``root``
gives a growable library array whose exports can be counted, and the other methods run C operations
and return NumPy arrays that share the library buffer. NumPy 2 is the oracle. The tests are written
from the contracts and the documented handle, not from the implementation.

Covered: export lifetime (the array outlives the root, the root dies first, a foreign exporter dies
early, release from another thread, interpreter shutdown with live exports in a subprocess), read-only
propagation through the buffer protocol and DLPack, both capsule names and the renaming of a consumed
capsule, a legacy-only exporter that raises BufferError, every exported dtype, boolean indexing with an
exported mask, a write into a read-only export, the format table of contracts 2.2 (PEP 3118 prefixes,
byte-swapped, unaligned and oddly strided inputs, the ``l`` format, DLPack codes), K-order conversion of
F-order and block-layout inputs (critic finding 10.1) and the per-module error records (contracts 5.7).
"""

import array
import ctypes
import gc
import importlib
import inspect
import os
import subprocess
import sys
import threading
import weakref

import numpy as np
import pytest

import pyoti.real as real


ND = getattr(real, "_ndtest", None)

pytestmark = pytest.mark.skipif(ND is None, reason="pyoti.real._ndtest is not built")

DTYPES = [np.float64, np.int64, np.bool_]
CASES = ["c", "f", "slice", "negative", "transposed", "block", "vector", "rank0", "empty", "empty_inner",
         "one", "broadcast"]
WANTS = [None, "f64", "mask", "index"]
INT64_MAX = 2**63 - 1


# ********************************************************************************************************
def _gc():
    """
    Run the garbage collector until nothing more is collected.
    """

    for _ in range(3):

        gc.collect()

    # end for

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _same(actual, expected, msg=""):
    """
    Assert that two arrays have the same dtype, shape and values, bit for bit (NaN matches NaN).

    Parameters
    ----------
    actual : array_like
        Computed array.
    expected : array_like
        Reference array.
    msg : str
        Context for the failure message.
    """

    actual = np.asarray(actual)
    expected = np.asarray(expected)
    assert actual.shape == expected.shape, msg
    assert actual.dtype == expected.dtype, msg

    if actual.dtype.kind == "f":

        nan_a = np.isnan(actual)
        assert np.array_equal(nan_a, np.isnan(expected)), msg
        left = np.atleast_1d(actual)[~np.atleast_1d(nan_a)]
        right = np.atleast_1d(expected)[~np.atleast_1d(nan_a)]
        assert np.array_equal(left.view(np.uint64), right.view(np.uint64)), msg

    else:

        assert np.array_equal(actual, expected), msg

    # end if

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _addr(arr):
    """
    Address of the first element of a NumPy array.

    Parameters
    ----------
    arr : numpy.ndarray
        Array.

    Returns
    -------
    int
        Data pointer.
    """

    return arr.__array_interface__["data"][0]

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _values(dtype, shape, rng):
    """
    Random values of a dtype, with a few special values for floats.

    Parameters
    ----------
    dtype : numpy.dtype
        Element type.
    shape : tuple of int
        Shape.
    rng : numpy.random.Generator
        Random generator.

    Returns
    -------
    numpy.ndarray
        Fresh C-contiguous array.
    """

    dtype = np.dtype(dtype)
    size = int(np.prod(shape, dtype=np.int64))

    if dtype.kind == "f":

        out = rng.standard_normal(size).astype(dtype)

        if size > 6:

            out[1] = np.nan
            out[2] = np.inf
            out[3] = -np.inf
            out[4] = -0.0

        # end if

    elif dtype.kind == "b":

        out = rng.integers(0, 2, size).astype(bool)

    else:

        info = np.iinfo(dtype)
        out = rng.integers(max(info.min, -2**62), min(info.max, 2**62), size).astype(dtype)

        if size > 2:

            out[0] = info.min if info.min > -2**63 else 0
            out[1] = info.max if info.max <= INT64_MAX else INT64_MAX

    # end if

        # end if

    return out.reshape(shape)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _make_case(dtype, case, seed=0):
    """
    Build one of the layouts of CASES for a dtype.

    Parameters
    ----------
    dtype : numpy.dtype
        Element type.
    case : str
        Name in CASES.
    seed : int
        Seed of the random values.

    Returns
    -------
    numpy.ndarray
        Array with the requested layout.
    """

    rng = np.random.default_rng(seed)
    dtype = np.dtype(dtype)
    big = _values(dtype, (6, 8, 5), rng)

    if case == "c":

        return big.copy()

    elif case == "f":

        return np.asfortranarray(big)

    elif case == "slice":

        return big[::2, 1::3, 2:]

    elif case == "negative":

        return big[::-1, ::-3, ::-1]

    elif case == "transposed":

        return big.transpose(2, 0, 1)

    elif case == "block":

        # The dense SoA block layout (nblocks, *S): F order inside a block, blocks outermost.
        raw = np.zeros(60, dtype=dtype)
        isz = dtype.itemsize
        blk = np.lib.stride_tricks.as_strided(raw, shape=(3, 4, 5), strides=(20 * isz, isz, 4 * isz))
        blk[...] = big[:3, :4, :5]
        return blk

    elif case == "vector":

        return big.reshape(-1)[3:40:2]

    elif case == "rank0":

        return np.array(big.flat[0], dtype=dtype)

    elif case == "empty":

        return big[:0]

    elif case == "empty_inner":

        return big[:, :0, :]

    elif case == "one":

        return big[2:3, 3:4, 1:2]

    elif case == "broadcast":

        out = np.broadcast_to(big[0, 0, :], (4, 5))
        return out

    # end if

    raise ValueError(case)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
class _BufExporter:
    """
    A buffer-protocol exporter that is not a NumPy array (Python 3.12 ``__buffer__``).

    Parameters
    ----------
    arr : numpy.ndarray
        Array whose memory is exported.
    """

    def __init__(self, arr):

        self.arr = arr
        self.gets = 0

    # end def

    def __buffer__(self, flags):

        self.gets += 1
        return memoryview(self.arr)

    # end def

    def __release_buffer__(self, view):

        view.release()

    # end def

# end class
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
class _DLExporter:
    """
    A DLPack-only producer (no buffer protocol) that records what the consumer calls.

    Parameters
    ----------
    arr : numpy.ndarray
        Array whose memory is exported.
    mode : str
        ``versioned`` forwards ``max_version``; ``legacy`` is a producer that predates the versioned
        protocol (``max_version`` is a TypeError); ``legacy-bufferror`` additionally raises BufferError on
        the legacy call; ``bufferror`` raises BufferError on every call.
    device : tuple of int
        Value of ``__dlpack_device__``; None asks the array.
    """

    def __init__(self, arr, mode="versioned", device=None):

        self.arr = arr
        self.mode = mode
        self.device = device
        self.calls = []
        self.caps = []

    # end def

    def __dlpack_device__(self):

        if self.device is not None:

            return self.device

        # end if

        return self.arr.__dlpack_device__()

    # end def

    def __dlpack__(self, *, stream=None, max_version=None, dl_device=None, copy=None):

        self.calls.append(max_version)

        if self.mode == "bufferror":

            raise BufferError("cannot export")

        # end if

        if self.mode in ("legacy", "legacy-bufferror"):

            if max_version is not None:

                raise TypeError("__dlpack__() got an unexpected keyword argument 'max_version'")

            # end if

            if self.mode == "legacy-bufferror":

                raise BufferError("cannot export a read-only array")

            # end if

            cap = self.arr.__dlpack__()

        else:

            cap = self.arr.__dlpack__(max_version=max_version)

        # end if

        self.caps.append(cap)
        return cap

    # end def

# end class
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _capsule_name(cap):
    """
    Name of a PyCapsule.

    Parameters
    ----------
    cap : PyCapsule
        Capsule.

    Returns
    -------
    str
        Its current name.
    """

    func = ctypes.pythonapi.PyCapsule_GetName
    func.restype = ctypes.c_char_p
    func.argtypes = [ctypes.py_object]
    return func(cap).decode()

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _k_strides(shape, src_strides):
    """
    Element strides of a compact copy in the K order of a source: axes sorted by decreasing |stride|
    (ties by axis index), positive compact strides.

    Parameters
    ----------
    shape : tuple of int
        Shape.
    src_strides : tuple of int
        Source element strides.

    Returns
    -------
    tuple of int
        Strides of the copy.
    """

    order = sorted(range(len(shape)), key=lambda k: (-abs(src_strides[k]), k))
    out = [0] * len(shape)
    acc = 1

    for k in reversed(order):

        out[k] = acc
        acc *= shape[k]

    # end for

    return tuple(out)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("case", CASES)
@pytest.mark.parametrize("dtype", DTYPES)
def test_export_each_dtype_and_layout(dtype, case):
    """
    Import then export every dtype in every layout: same dtype, values and memory, no copy.

    Parameters
    ----------
    dtype : type
        NumPy scalar type (float64, int64 or bool: the mask).
    case : str
        Layout name.
    """

    src = _make_case(dtype, case)
    res = ND.roundtrip(src)

    _same(res, src)
    assert res.flags.writeable == src.flags.writeable

    if src.size > 0:

        assert res.base is not None
        assert _addr(res) == _addr(src)
        assert ND.import_info(src)["owns"] is False

        keep = [k for k in range(src.ndim) if src.shape[k] != 1]
        assert [res.strides[k] for k in keep] == [src.strides[k] for k in keep]

    # end if

    if src.flags.writeable and src.size > 0:

        idx = (0,) * src.ndim
        new = (not src[idx]) if src.dtype == np.bool_ else src[idx] + 3
        res[idx] = new
        assert src[idx] == new

    # end if

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_results_of_c_operations_have_the_exported_dtypes():
    """
    Results of C operations are float64, int64 or bool arrays, never uint8, and share a library buffer.
    """

    rng = np.random.default_rng(1)
    a = rng.standard_normal((4, 5))
    b = rng.standard_normal((4, 5))

    assert ND.zeros((3, 2)).dtype == np.float64
    assert ND.arange(0, 5).dtype == np.float64
    assert ND.binary("add", a, b).dtype == np.float64
    assert ND.binary("lt", a, b).dtype == np.bool_
    assert ND.binary("and", a > 0, b > 0).dtype == np.bool_
    assert ND.unary("not", a > 0).dtype == np.bool_
    assert ND.reduce("argmax", a, axes=0).dtype == np.int64
    assert ND.reduce("any", a > 0, axes=1).dtype == np.bool_

    for res in (ND.zeros((3, 2)), ND.binary("lt", a, b), ND.reduce("argmin", a, axes=1)):

        assert res.base is not None

    # end for

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("fortran", [False, True])
def test_boolean_indexing_with_exported_mask(fortran):
    """
    Index NumPy arrays with a mask made by the C layer: values, assignment and per-axis masks.

    Parameters
    ----------
    fortran : bool
        Make the mask from an F-ordered operand (its K layout is F).
    """

    rng = np.random.default_rng(2)
    a = rng.standard_normal((6, 7))
    b = rng.standard_normal((6, 7))
    left = np.asfortranarray(a) if fortran else a
    mask = ND.binary("gt", left, b)

    assert mask.dtype == np.bool_
    assert set(np.unique(mask.view(np.uint8))) <= {0, 1}
    np.testing.assert_array_equal(a[mask], a[a > b])

    got = a.copy()
    got[mask] = 0.0
    want = a.copy()
    want[a > b] = 0.0
    np.testing.assert_array_equal(got, want)

    rows = ND.reduce("any", mask, axes=1)
    cols = ND.reduce("all", mask, axes=0)
    np.testing.assert_array_equal(a[rows], a[(a > b).any(axis=1)])
    np.testing.assert_array_equal(a[:, cols], a[:, (a > b).all(axis=0)])
    assert np.count_nonzero(mask) == np.count_nonzero(a > b)

    # a one-dimensional mask taken from a column
    column = ND.binary("gt", a[:, 0], 0.0 * b[:, 0])
    np.testing.assert_array_equal(a[column], a[a[:, 0] > 0])

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_write_into_read_only_export():
    """
    Exports requested read-only reject writes; a writeable export shows its writes to later exports.
    """

    root = ND.root((3, 4))
    ro = root.array(writeable=False)
    assert not ro.flags.writeable

    with pytest.raises(ValueError, match="read-only"):

        ro[0, 0] = 1.0

    # end with

    with pytest.raises(ValueError, match="read-only"):

        ro[...] = 1.0

    # end with

    rw = root.array(writeable=True)
    assert rw.flags.writeable
    rw[:] = np.arange(12.0).reshape(3, 4)
    np.testing.assert_array_equal(root.array(writeable=False), np.arange(12.0).reshape(3, 4))
    np.testing.assert_array_equal(ro, np.arange(12.0).reshape(3, 4))

    # Views of a read-only export stay read-only; so do results of a read-only source.
    assert not ro[1:, ::2].flags.writeable
    src = np.arange(6.0)
    src.flags.writeable = False
    assert not ND.index(src, slice(1, 4)).flags.writeable
    assert not ND.transpose(src.reshape(2, 3)).flags.writeable

    # A write through the C layer into a read-only NumPy array fails and changes nothing.
    out = np.zeros(6)
    out.flags.writeable = False

    with pytest.raises(ValueError):

        ND.binary_to("add", src, src, out)

    # end with

    assert not out.any()

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_export_counts_and_the_array_outlives_the_root():
    """
    Every NumPy array exported from a root is an export; the arrays keep the memory after the root dies.
    """

    root = ND.root((4, 5))
    assert (root.refs, root.exports) == (1, 0)

    first = root.array()
    assert (root.refs, root.exports) == (2, 1)

    second = root.array()
    assert (root.refs, root.exports) == (3, 2)

    first[:] = np.arange(20.0).reshape(4, 5)
    part = second[1:3, ::2]
    expected = np.arange(20.0).reshape(4, 5)[1:3, ::2].copy()

    del first
    _gc()
    assert (root.refs, root.exports) == (2, 1)

    del root
    _gc()
    _same(part, expected)
    part[0, 0] = -1.0
    assert second[1, 0] == -1.0

    del second
    _gc()
    _same(part[0, 1:], expected[0, 1:])

    del part
    _gc()

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_root_deleted_first_then_exports_released():
    """
    Delete the root while exports live, then release the exports one by one, many times over.
    """

    for _ in range(100):

        root = ND.root((7, 3))
        arrays = [root.array() for _ in range(3)]
        arrays[0][...] = 2.5
        del root
        _gc()
        assert arrays[2].sum() == 2.5 * 21
        arrays.pop(0)
        arrays.pop()
        _gc()
        assert arrays[0].shape == (7, 3)

    # end for

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_growth_is_refused_by_a_live_export_then_allowed():
    """
    A growth refused by a live export is a BufferError that says so; after the exports die it works and
    keeps the values.
    """

    root = ND.root((4, 5))
    arr = root.array()
    arr[:] = np.arange(20.0).reshape(4, 5)
    old = root.nbytes

    with pytest.raises(BufferError, match="live export"):

        root.grow(old * 2)

    # end with

    assert root.nbytes == old
    del arr
    _gc()
    assert (root.refs, root.exports) == (1, 0)

    root.grow(old * 2)
    assert root.nbytes >= 2 * old
    root.set_layout((8, 5))
    got = root.array(writeable=False)
    assert got.shape == (8, 5)
    np.testing.assert_array_equal(got[:4], np.arange(20.0).reshape(4, 5))

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("kind", ["numpy", "buffer", "dlpack"])
@pytest.mark.parametrize("want", [None, "f64"])
def test_foreign_exporter_deleted_early(kind, want):
    """
    Drop the exporter and its array while the import lives: a zero-copy import keeps the memory alive
    until the result dies; a converted import has already released it.

    Parameters
    ----------
    kind : str
        ``numpy`` imports the array directly, ``buffer`` through a ``__buffer__`` exporter, ``dlpack``
        through a DLPack-only producer.
    want : str or None
        ``f64`` on an int64 array forces a conversion.
    """

    base = np.arange(12, dtype=np.int64) if want else np.arange(12, dtype=np.float64)
    ref = weakref.ref(base)
    expected = np.arange(12, dtype=np.float64)

    if kind == "numpy":

        exporter = base

    elif kind == "buffer":

        exporter = _BufExporter(base)

    else:

        exporter = _DLExporter(base)

    # end if

    res = ND.roundtrip(exporter, want=want)
    del exporter, base
    _gc()
    _same(res, expected)

    if want:

        assert ref() is None

    else:

        assert ref() is not None
        res[0] = 99.0
        assert ref()[0] == 99.0

    # end if

    del res
    _gc()
    assert ref() is None

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("kind", ["numpy", "buffer", "dlpack"])
def test_release_on_another_thread(kind):
    """
    The last reference of an import dies on a worker thread: the release callback runs there (it takes
    the GIL state) and nothing crashes or leaks.

    Parameters
    ----------
    kind : str
        Exporter kind, as in test_foreign_exporter_deleted_early.
    """

    for _ in range(20):

        base = np.arange(100.0)
        ref = weakref.ref(base)
        exporter = {"numpy": base, "buffer": _BufExporter(base), "dlpack": _DLExporter(base)}[kind]
        holder = [ND.roundtrip(exporter)]
        part = holder[0][10:20]
        del exporter, base

        def worker():

            holder.clear()

        # end def

        thread = threading.Thread(target=worker)
        thread.start()
        thread.join()
        _gc()
        assert ref() is not None
        assert part.sum() == sum(range(10, 20))

        part = None
        _gc()
        assert ref() is None

    # end for

    root = ND.root((5, 5))
    holder = [root.array()]
    del root
    thread = threading.Thread(target=holder.clear)
    thread.start()
    thread.join()

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_read_only_buffer_propagates():
    """
    A read-only Py_buffer makes a read-only import and export; a writeable request is an error.
    """

    src = np.arange(12.0).reshape(3, 4)
    src.flags.writeable = False

    for exporter in (src, _BufExporter(src), memoryview(src)):

        res = ND.roundtrip(exporter)
        assert not res.flags.writeable
        assert _addr(res) == _addr(src)
        assert ND.import_info(exporter)["writeable"] is False

        with pytest.raises(ValueError):

            ND.roundtrip(exporter, writeable=True)

        # end with

        with pytest.raises(ValueError):

            res[0, 0] = 1.0

    # end for

        # end with

    # A converted copy is a library array and is writeable even from a read-only source.
    ints = np.arange(6)
    ints.flags.writeable = False
    res = ND.roundtrip(ints, want="f64")
    assert res.flags.writeable
    assert ND.import_info(ints, want="f64")["owns"] is True

    # A writeable source stays writeable; the NumPy result may be asked read-only.
    live = np.arange(6.0)
    assert ND.roundtrip(live).flags.writeable
    assert not ND.roundtrip(live, export_writeable=False).flags.writeable

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_read_only_dlpack_propagates():
    """
    A DLPack tensor flagged READ_ONLY (versioned capsule) imports read-only; a writeable request fails.
    """

    src = np.arange(12.0).reshape(3, 4)
    src.flags.writeable = False
    exporter = _DLExporter(src)

    res = ND.roundtrip(exporter)
    assert not res.flags.writeable
    assert _addr(res) == _addr(src)
    assert exporter.calls[0] == (1, 0)

    with pytest.raises(ValueError):

        ND.roundtrip(_DLExporter(src), writeable=True)

    # end with

    rw = np.arange(12.0).reshape(3, 4)
    res = ND.roundtrip(_DLExporter(rw), writeable=True)
    assert res.flags.writeable
    res[1, 1] = -5.0
    assert rw[1, 1] == -5.0

# end function
# --------------------------------------------------------------------------------------------------------


CAPSULES = [("versioned", "dltensor_versioned", "used_dltensor_versioned"),
            ("legacy", "dltensor", "used_dltensor")]


# ********************************************************************************************************
@pytest.mark.parametrize("mode,first,used", CAPSULES)
def test_dlpack_capsule_names_and_renaming(mode, first, used):
    """
    Both capsule names import; the consumed capsule is renamed as the DLPack consumer rule says.

    Parameters
    ----------
    mode : str
        Producer mode (see _DLExporter).
    first : str
        Capsule name the producer returns.
    used : str
        Name the capsule must have after the import consumed it.
    """

    base = np.arange(20.0).reshape(4, 5)
    exporter = _DLExporter(base, mode)
    res = ND.roundtrip(exporter, writeable=True)

    assert len(exporter.caps) == 1
    assert _capsule_name(exporter.caps[0]) == used
    assert exporter.calls == ([(1, 0)] if mode == "versioned" else [(1, 0), None])
    _same(res, base)
    assert _addr(res) == _addr(base)

    # The capsule can still be dropped (its destructor must not free what the consumer owns).
    exporter.caps.clear()
    _gc()
    _same(res, base)
    del res, exporter
    _gc()

    assert first.startswith("dltensor")

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("device", [(2, 0), (3, 0), (1, 1), (13, 0)])
def test_dlpack_rejects_other_devices_before_exporting(device):
    """
    A DLPack producer that is not on the CPU device (1, 0) is rejected before ``__dlpack__`` is called.

    Parameters
    ----------
    device : tuple of int
        Value of ``__dlpack_device__`` (CUDA, pinned memory, a second device, ...).
    """

    exporter = _DLExporter(np.arange(4.0), device=device)

    with pytest.raises(ValueError):

        ND.roundtrip(exporter)

    # end with

    assert exporter.calls == []

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("writeable", [False, True])
@pytest.mark.parametrize("mode", ["legacy-bufferror", "bufferror"])
def test_dlpack_buffererror_means_read_only_or_unusable(mode, writeable):
    """
    A producer that raises BufferError is READONLY (ValueError) when a writeable import was asked for,
    and otherwise an object without a usable export (TypeError). A legacy-only producer is retried
    without ``max_version`` first.

    Parameters
    ----------
    mode : str
        Producer mode (see _DLExporter).
    writeable : bool
        Ask for a writeable import.
    """

    exporter = _DLExporter(np.arange(4.0), mode)
    exc = ValueError if writeable else TypeError

    with pytest.raises(exc):

        ND.roundtrip(exporter, writeable=writeable)

    # end with

    if mode == "legacy-bufferror":

        assert exporter.calls == [(1, 0), None]

    else:

        assert exporter.calls[0] == (1, 0)

    # end if

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_numpy_legacy_call_of_a_read_only_array_is_not_needed():
    """
    A read-only NumPy array imports through DLPack alone even though its legacy ``__dlpack__()`` call
    raises BufferError: the versioned call comes first.
    """

    src = np.arange(6.0)
    src.flags.writeable = False

    with pytest.raises(BufferError):

        src.__dlpack__()

    # end with

    res = ND.roundtrip(_DLExporter(src))
    assert not res.flags.writeable
    _same(res, src)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("src_dtype,want,expect", [
    (np.float64, None, np.float64), (np.float64, "f64", np.float64), (np.float32, None, np.float64),
    (np.float32, "f64", np.float64), (np.int64, None, np.int64), (np.int64, "index", np.int64),
    (np.int64, "f64", np.float64), (np.int32, None, np.int64), (np.int8, "index", np.int64),
    (np.uint16, None, np.int64), (np.uint32, "f64", np.float64), (np.bool_, None, np.bool_),
    (np.bool_, "mask", np.bool_), (np.bool_, "f64", np.float64)])
def test_dlpack_dtype_codes(src_dtype, want, expect):
    """
    The DLPack codes kDLFloat / kDLInt / kDLUInt / kDLBool map as table 2.2 says, exact ones zero-copy.

    Parameters
    ----------
    src_dtype : type
        NumPy dtype of the producer.
    want : str or None
        Wanted type.
    expect : type
        Dtype of the result.
    """

    base = _values(src_dtype, (3, 4), np.random.default_rng(3))
    res = ND.roundtrip(_DLExporter(base), want=want)
    assert res.dtype == expect

    if src_dtype == np.bool_ and want == "f64":

        np.testing.assert_array_equal(res, base.astype(np.float64))

    else:

        np.testing.assert_array_equal(res, base.astype(expect))

    # end if

    exact = (src_dtype, expect) in ((np.float64, np.float64), (np.int64, np.int64), (np.bool_, np.bool_))

    if exact:

        assert _addr(res) == _addr(base)

    else:

        assert _addr(res) != _addr(base)

    # end if

# end function
# --------------------------------------------------------------------------------------------------------


REJECTED = [(np.complex128, None), (np.complex64, "f64"), (np.float16, None), (np.float16, "f64"),
            (np.uint8, "mask"), (np.float64, "mask"), (np.float64, "index"), (np.bool_, "index")]


# ********************************************************************************************************
@pytest.mark.parametrize("src_dtype,want", REJECTED)
def test_dlpack_rejected_codes(src_dtype, want):
    """
    Complex, float16, non-bool masks and float or bool indexes are TypeErrors through DLPack.

    Parameters
    ----------
    src_dtype : type
        NumPy dtype of the producer.
    want : str or None
        Wanted type.
    """

    base = np.ones((2, 3), dtype=src_dtype)

    with pytest.raises(TypeError):

        ND.roundtrip(_DLExporter(base), want=want)

    # end with

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _outcome(src_dtype, values, want):
    """
    What contracts 2.2 prescribe for importing an array of ``src_dtype``.

    Parameters
    ----------
    src_dtype : numpy.dtype
        Dtype of the source, byte order included.
    values : numpy.ndarray
        Source values.
    want : str or None
        Wanted type.

    Returns
    -------
    tuple
        ``(error, dtype, exact)``: the exception type or None, the result dtype, and whether the import is
        zero-copy.
    """

    dt = np.dtype(src_dtype)
    native = dt.isnative
    kind = dt.kind
    big = kind == "u" and dt.itemsize == 8 and bool(np.any(values > INT64_MAX))

    if want == "mask":

        return (None, np.bool_, True) if kind == "b" else (TypeError, None, False)

    # end if

    if want == "index":

        if kind not in "iu":

            return TypeError, None, False

        # end if

        if big:

            return IndexError, None, False

        # end if

        return None, np.int64, kind == "i" and dt.itemsize == 8 and native

    # end if

    if want == "f64":

        if kind in "biu" or (kind == "f" and dt.itemsize in (4, 8)):

            return None, np.float64, kind == "f" and dt.itemsize == 8 and native

        # end if

        return TypeError, None, False

    # end if

    # natural
    if kind == "b":

        return None, np.bool_, True

    # end if

    if kind in "iu":

        if big:

            return IndexError, None, False

        # end if

        return None, np.int64, kind == "i" and dt.itemsize == 8 and native

    # end if

    if kind == "f" and dt.itemsize in (4, 8):

        return None, np.float64, dt.itemsize == 8 and native

    # end if

    return TypeError, None, False

# end function
# --------------------------------------------------------------------------------------------------------


NUMPY_FORMATS = ["?", "i1", "i2", "i4", "i8", "u1", "u2", "u4", "u8", "f2", "f4", "f8", "c8", "c16",
                 ">i2", ">i4", ">i8", ">u2", ">u4", ">u8", ">f4", ">f8", "<i8", "<f8", "=f8", "=i8"]
FORMAT_CASES = [(fmt, False) for fmt in NUMPY_FORMATS] + [("u8", True), (">u8", True)]


# ********************************************************************************************************
@pytest.mark.parametrize("fmt,big", FORMAT_CASES)
@pytest.mark.parametrize("order", ["C", "F"])
@pytest.mark.parametrize("want", WANTS)
def test_format_table_pep3118(fmt, big, want, order):
    """
    Every row and column of table 2.2 through the buffer protocol: zero-copy where exact, converted
    exactly otherwise, rejected with the exception of contracts 4.4.

    Parameters
    ----------
    fmt : str
        NumPy dtype string of the source (byte-swapped ones export as ``>d``, ``>i``, ...).
    big : bool
        Put uint64 values above INT64_MAX into the source (an index fails with IndexError).
    want : str or None
        Wanted type.
    order : str
        Memory order of the source.
    """

    dt = np.dtype(fmt)
    rng = np.random.default_rng(4)
    ints = rng.integers(0, 100, (3, 4))

    if dt.kind in "iu":

        info = np.iinfo(dt)
        vals = ints.astype(np.int64)
        vals[0, 0] = max(info.min, -2**62) if info.min < 0 else 0
        vals[0, 1] = min(info.max, INT64_MAX)

        if big and dt.kind == "u" and dt.itemsize == 8:

            vals = vals.astype(np.uint64)
            vals[1, 1] = np.uint64(2**63 + 5)
            vals[2, 2] = np.uint64(2**64 - 1)

        # end if

        src = vals.astype(dt)

    elif dt.kind == "f":

        src = (rng.standard_normal((3, 4)) * 100).astype(dt)

    elif dt.kind == "c":

        src = (rng.standard_normal((3, 4)) + 1j).astype(dt)

    else:

        src = (ints % 2).astype(bool)

    # end if

    if order == "F":

        src = np.asfortranarray(src)

    # end if

    error, rdt, exact = _outcome(dt, src, want)

    if error is not None:

        with pytest.raises(error):

            ND.roundtrip(src, want=want)

        # end with

        return

    # end if

    res = ND.roundtrip(src, want=want)
    assert res.dtype == rdt
    assert res.shape == src.shape
    expected = src.astype(rdt)
    _same(res, expected)
    info = ND.import_info(src, want=want)
    assert info["owns"] is (not exact)

    if exact:

        assert _addr(res) == _addr(src)
        assert res.strides == src.strides

    else:

        assert _addr(res) != _addr(src)
        assert res.flags.writeable

    # end if

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _foreign_cases():
    """
    Exporters with formats NumPy does not produce: ctypes arrays (``<d``, ``>d``, ``<q``, ``<?``), the
    ``array`` module (``d``, ``l``, ``q``, ``L`` ...) and memoryview casts (``@d``, ``@q``, ``n``, ``N``).

    Returns
    -------
    list of tuple
        ``(id, factory, want, expected dtype or None, zero-copy, values)``.
    """

    vals = [1.0, 2.0, -3.0, 4.5]
    ints = [1, 2, 3, 4]
    cases = []

    def ct(kind, values):

        return lambda: (kind * len(values))(*values)

    # end def

    def ar(code, values):

        return lambda: array.array(code, values)

    # end def

    def mv(code, values):

        def make():

            raw = bytearray(array.array("d" if code in ("d", "@d") else "q", values).tobytes())
            return memoryview(raw).cast("B").cast(code)

        # end def

        return make

    # end def

    long8 = array.array("l").itemsize == 8
    flags = [True, False, True]
    cases += [("ct-d", ct(ctypes.c_double, vals), "f64", np.float64, True, vals),
              ("ct-d-natural", ct(ctypes.c_double, vals), None, np.float64, True, vals),
              ("ct-be-d", ct(ctypes.c_double.__ctype_be__, vals), "f64", np.float64, False, vals),
              ("ct-f", ct(ctypes.c_float, vals), "f64", np.float64, False, vals),
              ("ct-q-index", ct(ctypes.c_int64, ints), "index", np.int64, True, ints),
              ("ct-long-index", ct(ctypes.c_long, ints), "index", np.int64, long8, ints),
              ("ct-i-index", ct(ctypes.c_int32, ints), "index", np.int64, False, ints),
              ("ct-be-i-index", ct(ctypes.c_int32.__ctype_be__, ints), "index", np.int64, False, ints),
              ("ct-B-natural", ct(ctypes.c_uint8, ints), None, np.int64, False, ints),
              ("ct-B-mask", ct(ctypes.c_uint8, ints), "mask", TypeError, False, ints),
              ("ct-bool-mask", ct(ctypes.c_bool, flags), "mask", np.bool_, True, [1, 0, 1]),
              ("ct-bool-natural", ct(ctypes.c_bool, flags), None, np.bool_, True, [1, 0, 1]),
              ("ct-bool-f64", ct(ctypes.c_bool, flags), "f64", np.float64, False, [1, 0, 1]),
              ("ar-d", ar("d", vals), "f64", np.float64, True, vals),
              ("ar-f", ar("f", vals), None, np.float64, False, vals),
              ("ar-l-index", ar("l", ints), "index", np.int64, long8, ints),
              ("ar-q-index", ar("q", ints), "index", np.int64, True, ints),
              ("ar-L-index", ar("L", ints), "index", np.int64, False, ints),
              ("ar-Q-index", ar("Q", ints), "index", np.int64, False, ints),
              ("ar-i-natural", ar("i", ints), None, np.int64, False, ints),
              ("ar-h-f64", ar("h", ints), "f64", np.float64, False, ints),
              ("ar-b-index", ar("b", ints), "index", np.int64, False, ints),
              ("ar-H-index", ar("H", ints), "index", np.int64, False, ints),
              ("ar-I-f64", ar("I", ints), "f64", np.float64, False, ints),
              ("mv-@d", mv("@d", vals), "f64", np.float64, True, vals),
              ("mv-d", mv("d", vals), None, np.float64, True, vals),
              ("mv-@q-index", mv("@q", ints), "index", np.int64, True, ints),
              ("mv-q-natural", mv("q", ints), None, np.int64, True, ints),
              ("mv-n-index", mv("n", ints), "index", np.int64, True, ints),
              ("mv-N-index", mv("N", ints), "index", np.int64, False, ints),
              ("bytes-f64", lambda: bytes(ints), "f64", np.float64, False, ints),
              ("bytes-natural", lambda: bytes(ints), None, np.int64, False, ints),
              ("bytes-mask", lambda: bytes(ints), "mask", TypeError, False, ints),
              ("bytearray-index", lambda: bytearray(ints), "index", np.int64, False, ints)]

    return cases

# end function
# --------------------------------------------------------------------------------------------------------


FOREIGN = _foreign_cases()


# ********************************************************************************************************
@pytest.mark.parametrize("name,factory,want,expect,exact,values", FOREIGN, ids=[c[0] for c in FOREIGN])
def test_format_table_other_exporters(name, factory, want, expect, exact, values):
    """
    PEP 3118 formats NumPy never produces: byte-order prefixes ``<`` ``>`` ``@`` and none, the ``l``
    format at its platform size, ``n`` / ``N``, and ``B`` for bytes.

    Parameters
    ----------
    name : str
        Case name.
    factory : callable
        Makes a fresh exporter.
    want : str or None
        Wanted type.
    expect : type
        Result dtype, or the exception type.
    exact : bool
        Whether the import is zero-copy.
    values : list
        Expected values.
    """

    obj = factory()

    if isinstance(expect, type) and issubclass(expect, Exception):

        with pytest.raises(expect):

            ND.roundtrip(obj, want=want)

        # end with

        return

    # end if

    res = ND.roundtrip(obj, want=want)
    assert res.dtype == expect
    np.testing.assert_array_equal(res, np.asarray(values).astype(expect))
    assert ND.import_info(obj, want=want)["owns"] is (not exact)

    if exact:

        view = np.frombuffer(obj, dtype=res.dtype) if not isinstance(obj, (bytes, bytearray)) else None

        if view is not None and view.size == res.size:

            assert _addr(res) == _addr(view)

    # end if

        # end if

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_format_l_with_itemsize_four_is_an_integer_of_that_size():
    """
    The ``l`` format means a 4-byte integer where C ``long`` is 4 bytes and an 8-byte one elsewhere.
    """

    if ctypes.sizeof(ctypes.c_long) == 4:

        arr = array.array("l", [1, 2, 3])
        assert arr.itemsize == 4
        assert ND.import_info(arr, want="index")["owns"] is True

    else:

        arr = array.array("l", [1, 2, 3])
        assert arr.itemsize == 8
        assert ND.import_info(arr, want="index")["owns"] is False

    # end if

    np.testing.assert_array_equal(ND.roundtrip(arr, want="index"), [1, 2, 3])

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_uint64_above_int64_max_as_index():
    """
    uint64 values above INT64_MAX are an IndexError as an index and fine as float64; the maximum that
    fits converts.
    """

    ok = np.array([0, 5, INT64_MAX], dtype=np.uint64)
    bad = np.array([0, 5, INT64_MAX + 1], dtype=np.uint64)
    np.testing.assert_array_equal(ND.roundtrip(ok, want="index"), ok.astype(np.int64))

    for want in ("index", None):

        with pytest.raises(IndexError):

            ND.roundtrip(bad, want=want)

    # end for

        # end with

    np.testing.assert_array_equal(ND.roundtrip(bad, want="f64"), bad.astype(np.float64))

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_byte_swapped_unaligned_and_odd_strides_convert_exactly():
    """
    Byte-swapped, misaligned and oddly strided float64 inputs convert exactly; none is zero-copy.
    """

    rng = np.random.default_rng(5)
    vals = rng.standard_normal(10)
    vals[3] = np.nan
    vals[4] = -0.0
    vals[5] = np.inf

    swapped = vals.astype(">f8")
    unaligned = np.ndarray((10,), dtype="<f8", buffer=bytearray(8 * 10 + 8), offset=1)
    unaligned[:] = vals
    assert not unaligned.flags.aligned
    oddly = np.ndarray((5,), dtype="<f8", buffer=bytearray(60), offset=0, strides=(12,))
    oddly[:] = vals[:5]

    for src, expected in ((swapped, vals), (unaligned, vals), (oddly, vals[:5])):

        res = ND.roundtrip(src, want="f64")
        _same(res, expected.astype(np.float64))
        assert ND.import_info(src, want="f64")["owns"] is True
        assert res.flags.writeable
        res2 = ND.roundtrip(src)
        _same(res2, expected.astype(np.float64))

    # end for

    # Two dimensions, F order, with negative strides: values are exact too.
    grid = vals.reshape(2, 5).astype(">f8")
    for src in (np.asfortranarray(grid), grid[::-1, ::-1], grid.T):

        _same(ND.roundtrip(src, want="f64"), src.astype(np.float64))

    # end for

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_import_as_output_refuses_conversions():
    """
    ``writeable=True`` (an ``out=`` argument) never converts: a type conversion is a TypeError, a layout
    conversion a ValueError, a read-only source a ValueError; exact inputs import and share their memory.
    """

    out = np.zeros((3, 4))
    res = ND.roundtrip(out, writeable=True)
    res[1, 2] = 7.0
    assert out[1, 2] == 7.0
    assert _addr(res) == _addr(out)

    with pytest.raises(TypeError):

        ND.roundtrip(np.zeros(4, dtype=np.int64), want="f64", writeable=True)

    # end with

    with pytest.raises(TypeError):

        ND.roundtrip(np.zeros(4, dtype=np.float32), writeable=True)

    # end with

    with pytest.raises(TypeError):

        ND.roundtrip(np.zeros(4, dtype=">f8"), want="f64", writeable=True)

    # end with

    unaligned = np.ndarray((4,), dtype="<f8", buffer=bytearray(8 * 4 + 8), offset=1)

    with pytest.raises(ValueError):

        ND.roundtrip(unaligned, want="f64", writeable=True)

    # end with

    oddly = np.ndarray((3,), dtype="<f8", buffer=bytearray(40), offset=0, strides=(12,))

    with pytest.raises(ValueError):

        ND.roundtrip(oddly, want="f64", writeable=True)

    # end with

    ro = np.zeros(4)
    ro.flags.writeable = False

    with pytest.raises(ValueError):

        ND.roundtrip(ro, writeable=True)

    # end with

    # ND_IMPORT_COPY always copies, also an exact input.
    src = np.arange(6.0)
    res = ND.roundtrip(src, copy=True)
    _same(res, src)
    assert _addr(res) != _addr(src)
    assert ND.import_info(src, copy=True)["owns"] is True
    res[0] = 42.0
    assert src[0] == 0.0

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_zero_strides_import_for_reading_only():
    """
    A broadcast (zero-stride) read-only input imports and exports; an output with zero strides is refused.
    """

    row = np.arange(5.0)
    bc = np.broadcast_to(row, (4, 5))
    res = ND.roundtrip(bc)
    _same(res, bc)
    assert res.strides[0] == 0
    assert not res.flags.writeable

    zero = np.lib.stride_tricks.as_strided(np.zeros(5), shape=(4, 5), strides=(0, 8), writeable=True)

    with pytest.raises(ValueError):

        ND.binary_to("add", np.ones((4, 5)), np.ones((4, 5)), zero)

    # end with

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_rank_limits_and_non_buffers():
    """
    Rank 32 imports, rank 33 is a ValueError; lists, scalars, strings and None are TypeErrors.
    """

    ok = np.ones((1,) * 32)
    assert ND.roundtrip(ok).shape == (1,) * 32

    with pytest.raises(ValueError):

        ND.roundtrip(np.ones((1,) * 33))

    # end with

    for obj in ([1.0, 2.0], 3.0, 7, "abc", None, (1, 2), {"a": 1}):

        with pytest.raises(TypeError):

            ND.roundtrip(obj)

    # end for

        # end with

    for dt in ([("a", "f8"), ("b", "i4")], "S4", "U3", "V8", "O"):

        try:

            src = np.zeros(3, dtype=dt)

        except TypeError:

            continue

        # end try

        with pytest.raises((TypeError, ValueError, BufferError)):

            ND.roundtrip(src)

    # end for

        # end with

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("src_dtype", [np.float32, np.float64, np.int32, np.int64, np.bool_])
@pytest.mark.parametrize("shape", [(3, 4), (3, 4, 5), (2, 3, 4, 5)])
def test_conversion_keeps_the_f_layout(shape, src_dtype):
    """
    Critic finding 10.1: an F-order foreign input that must be converted stays F (K order), not C.

    Parameters
    ----------
    shape : tuple of int
        Shape of the source.
    src_dtype : type
        Source dtype; every one except float64 and the mask is converted for ``want='f64'``.
    """

    src = np.asfortranarray(_values(src_dtype, shape, np.random.default_rng(6)))
    info = ND.import_info(src, want="f64")
    expected = tuple(np.cumprod((1,) + shape[:-1]))
    assert tuple(info["strides"]) == expected
    assert info["f_contiguous"] is True
    assert info["c_contiguous"] is False
    res = ND.roundtrip(src, want="f64")
    assert res.flags.f_contiguous and not res.flags.c_contiguous
    np.testing.assert_array_equal(res, src.astype(np.float64))

    # DLPack path as well
    res = ND.roundtrip(_DLExporter(src), want="f64")
    assert res.flags.f_contiguous and not res.flags.c_contiguous
    np.testing.assert_array_equal(res, src.astype(np.float64))

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("case", ["c", "f", "slice", "negative", "transposed", "block", "vector", "one"])
@pytest.mark.parametrize("src_dtype", [np.float32, np.int32, np.uint8])
def test_conversion_follows_the_k_order_of_the_source(src_dtype, case):
    """
    A converted import is compact, with positive strides, its axes in the order of the source's strides
    (decreasing absolute stride, ties by axis): C stays C, F stays F, the SoA block layout is kept.

    Parameters
    ----------
    src_dtype : type
        Source dtype (always converted).
    case : str
        Layout name of the source.
    """

    src = _make_case(src_dtype, case)
    info = ND.import_info(src, want="f64")
    esrc = tuple(s // src.itemsize for s in src.strides)
    expected = _k_strides(src.shape, esrc)
    keep = [k for k in range(src.ndim) if src.shape[k] != 1]

    assert info["shape"] == src.shape
    assert [info["strides"][k] for k in keep] == [expected[k] for k in keep]
    assert all(s >= 0 for s in info["strides"])
    _same(ND.roundtrip(src, want="f64"), src.astype(np.float64))

    if case == "block":

        assert info["strides"] == (20, 1, 4)

    # end if

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_conversion_k_order_random_strides():
    """
    Random distinct strides (including negative) give compact copies ordered by the source strides.
    """

    rng = np.random.default_rng(7)

    for _ in range(100):

        nd = int(rng.integers(2, 5))
        shape = tuple(int(x) for x in rng.integers(2, 5, nd))
        big = rng.standard_normal(tuple(s * 3 for s in shape)).astype(np.float32)
        steps = [int(x) for x in rng.choice([1, 2, -1, -2, 3], nd)]
        view = big[tuple(slice(None, None, st) for st in steps)][tuple(slice(0, s) for s in shape)]
        perm = [int(k) for k in rng.permutation(nd)]
        src = view.transpose(perm)
        esrc = tuple(s // src.itemsize for s in src.strides)

        if len({abs(s) for s in esrc}) < nd:

            continue

        # end if

        info = ND.import_info(src, want="f64")
        assert info["strides"] == _k_strides(src.shape, esrc)
        np.testing.assert_array_equal(ND.roundtrip(src, want="f64"), src.astype(np.float64))

    # end for

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_trusted_temporary_cannot_be_exported_so_it_is_copied():
    """
    A trusted temporary (no buffer behind it) cannot be pinned by an export: ``nd_to_numpy`` copies it,
    and the result is a fresh array without a base.
    """

    src = np.arange(12.0).reshape(3, 4)
    res = ND.trusted_copy(src)
    _same(res, src)
    assert res.base is None or not np.shares_memory(res, src)
    res[0, 0] = -1.0
    assert src[0, 0] == 0.0

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _run(script, env_extra=None):
    """
    Run a script in a fresh interpreter that sees the same pyoti as the tests.

    Parameters
    ----------
    script : str
        Python source.
    env_extra : dict, optional
        Extra environment variables.

    Returns
    -------
    subprocess.CompletedProcess
        Result with text output.
    """

    env = dict(os.environ)
    root = os.path.dirname(os.path.dirname(os.path.abspath(real.__file__)))
    old = [p for p in env.get("PYTHONPATH", "").split(os.pathsep) if p]
    env["PYTHONPATH"] = os.pathsep.join([root] + old)
    env.update(env_extra or {})
    return subprocess.run([sys.executable, "-c", script], capture_output=True, text=True, env=env,
                          timeout=300)

# end function
# --------------------------------------------------------------------------------------------------------


SHUTDOWN_SCENARIOS = {
    "numpy": """
a = np.arange(10.0)
res = ND.roundtrip(a)
keep = [a, res, ND.zeros((3, 4)), ND.roundtrip(a.astype(np.int64), want="f64")]
""",
    "buffer": """
exporter = Buf(np.arange(10.0))
res = ND.roundtrip(exporter)
view = res[2:5]
""",
    "dlpack": """
exporter = DL(np.arange(10.0))
res = ND.roundtrip(exporter)
exporter2 = DL(np.arange(6.0), "legacy")
res2 = ND.roundtrip(exporter2)
""",
    "root": """
root = ND.root((4, 5))
arr = root.array()
view = arr[1:3]
""",
    "cycle": """
class Box:
    pass

box = Box()
box.me = box
box.arr = ND.zeros((4, 4))
box.res = ND.roundtrip(np.ones(5))
""",
    "del_at_exit": """
class Last:
    def __del__(self):
        self.res = None

last = Last()
last.res = ND.roundtrip(np.arange(4.0))
last.dl = ND.roundtrip(DL(np.arange(4.0)))
""",
    "thread": """
import threading
res = ND.roundtrip(np.arange(10.0))
box = {"res": res}
thread = threading.Thread(target=lambda: None)
thread.start()
thread.join()
""",
}


# ********************************************************************************************************
@pytest.mark.parametrize("scenario", sorted(SHUTDOWN_SCENARIOS))
def test_interpreter_shutdown_with_live_exports(scenario):
    """
    Exit the interpreter while exports and imports are alive: a clean exit, no output, no crash.

    Parameters
    ----------
    scenario : str
        Key of SHUTDOWN_SCENARIOS.
    """

    prologue = "import numpy as np\nfrom pyoti.real import _ndtest as ND\n"
    prologue += inspect.getsource(_BufExporter).replace("_BufExporter", "Buf")
    prologue += inspect.getsource(_DLExporter).replace("_DLExporter", "DL")
    script = prologue + SHUTDOWN_SCENARIOS[scenario] + "\nprint('done')\n"

    proc = _run(script)
    assert proc.returncode == 0, proc.stderr
    assert proc.stdout.strip() == "done"
    assert proc.stderr.strip() == ""

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_interpreter_shutdown_with_an_atexit_release():
    """
    Release exports from an ``atexit`` handler and from a daemon thread at exit: a clean exit.
    """

    script = """
import atexit, threading, time
import numpy as np
from pyoti.real import _ndtest as ND

res = ND.roundtrip(np.arange(10.0))
root = ND.root((3, 3))
arr = root.array()
holder = [res, arr]

def drop():
    holder.clear()

atexit.register(drop)

def daemon():
    local = ND.roundtrip(np.arange(5.0))
    time.sleep(0.2)
    local = None

thread = threading.Thread(target=daemon, daemon=True)
thread.start()
print("done")
"""

    proc = _run(script)
    assert proc.returncode == 0, proc.stderr
    assert proc.stdout.strip() == "done"

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _modules_with_handle():
    """
    The pyoti Cython modules that expose a private ``_ndtest`` handle.

    Returns
    -------
    list of module
        Modules, ``pyoti.real`` first.
    """

    found = []

    for name in ("real", "dense", "sparse", "semisparse", "core", "fem"):

        try:

            mod = importlib.import_module("pyoti." + name)

        except ImportError:

            continue

        # end try

        if getattr(mod, "_ndtest", None) is not None:

            found.append(mod)

    # end for

        # end if

    return found

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_last_error_is_recorded_and_not_cleared_by_success():
    """
    A failing call records its status in this module's context; a later success does not clear it;
    ``clear_error`` does.
    """

    ND.clear_error()
    assert ND.last_error()[0] == 0

    with pytest.raises(ValueError):

        ND.reshape(np.arange(6.0), (7,))

    # end with

    status, where, msg = ND.last_error()
    assert status == ND.status["SHAPE"]
    assert where is None or isinstance(where, str)
    assert msg is None or isinstance(msg, str)

    ND.zeros((2, 2))
    assert ND.last_error()[0] == ND.status["SHAPE"]

    ND.clear_error()
    assert ND.last_error()[0] == 0

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_error_recorded_in_one_module_is_not_seen_by_another():
    """
    Contracts 5.7: every Cython module has its own default context, so an error recorded in one module
    is not visible in another (documented behaviour until the shared liboti exists).
    """

    mods = _modules_with_handle()

    if len(mods) < 2:

        pytest.skip("only pyoti.real exposes _ndtest: the cross-module check needs a second module")

    # end if

    for mod in mods:

        mod._ndtest.clear_error()

    # end for

    first, others = mods[0], mods[1:]

    with pytest.raises(ValueError):

        first._ndtest.reshape(np.arange(6.0), (7,))

    # end with

    assert first._ndtest.last_error()[0] == first._ndtest.status["SHAPE"]

    for mod in others:

        assert mod._ndtest.last_error()[0] == 0

    # end for

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_last_error_is_per_process_module_in_a_subprocess_pair():
    """
    A fresh interpreter starts with no recorded error although this process recorded one.
    """

    ND.clear_error()

    with pytest.raises(ValueError):

        ND.reshape(np.arange(6.0), (7,))

    # end with

    proc = _run("from pyoti.real import _ndtest as ND\nprint(ND.last_error()[0])")
    assert proc.returncode == 0, proc.stderr
    assert proc.stdout.strip() == "0"
    ND.clear_error()

# end function
# --------------------------------------------------------------------------------------------------------
