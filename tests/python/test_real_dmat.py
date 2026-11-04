"""
Tests of ``pyoti.real.dmat`` on ``ndarr_t`` (Phase 6b; contracts 11.9, 11.8, 11.11, 1.8, 6).

``dmat`` indexes as NumPy does (an integer drops its axis: ``D[0]`` is ``(ncols,)``; 2.0.0, Phase 7b),
and its slices are **views**: a write through a slice reaches the parent. ``to_numpy()`` is a writable
zero-copy view, ``dmat`` operands keep working with sparse (``matso op dmat``) and the fem helpers, and
the producers (``memoryview``, ``np.asarray``, ``np.from_dlpack``) share the memory of the ``dmat``.
``dmatfe`` / ``dnumfe`` keep their behaviour.

The references of the arrays under test are always held in a variable: 1.x returned views that did not
keep their owner alive.
"""

import gc
import os
import subprocess
import sys
import threading

import numpy as np
import pytest

import pyoti.fem as fem
import pyoti.real as real
import pyoti.sparse as sp


# ********************************************************************************************************
def _make(shape, seed=0):
    """
    Build a ``dmat`` with random data.

    Parameters
    ----------
    shape : tuple of int
        Rows and columns.
    seed : int, optional
        Seed of the generator.

    Returns
    -------
    dmat, numpy.ndarray
        The matrix and a NumPy copy of its values.
    """

    data = np.random.default_rng(seed).standard_normal(shape)

    return real.array(data), data.copy()

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _expected(data, key):
    """
    Apply a ``dmat`` key to a NumPy array (NumPy's rule, 2.0.0): an integer drops its axis.

    Parameters
    ----------
    data : numpy.ndarray
        Two-dimensional array.
    key : int or slice or tuple
        Key of the kinds a ``dmat`` accepts.

    Returns
    -------
    numpy.ndarray or float
        The selected part: a view of ``data``, or a float when every index is an integer.
    """

    return data[key]

# end function
# --------------------------------------------------------------------------------------------------------


KEYS = [
    pytest.param(1, id="int"),
    pytest.param(slice(1, 3), id="rows"),
    pytest.param(slice(None, None, 2), id="strided-rows"),
    pytest.param((2, slice(None)), id="int-colon"),
    pytest.param((slice(None), 1), id="colon-int"),
    pytest.param((slice(1, 3), slice(0, 3)), id="block"),
    pytest.param((slice(0, 4, 2), slice(1, 5, 2)), id="strided-block"),
    pytest.param((slice(None), slice(None)), id="all"),
]


# ********************************************************************************************************
@pytest.mark.parametrize("key", KEYS)
def test_slices_have_numpy_shapes_and_values(key):
    """
    The indexing shapes and values are NumPy's: an integer drops its axis (``D[0]`` is ``(ncols,)``,
    ``D[:, 1]`` is ``(nrows,)``).

    Parameters
    ----------
    key : object
        Key applied to a ``(4, 5)`` matrix.
    """

    matrix, data = _make((4, 5))
    result = matrix[key]
    expected = _expected(data, key)

    assert result.shape == expected.shape
    np.testing.assert_array_equal(result.to_numpy(), expected)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_two_integer_keys_give_floats():
    """
    ``D[i, j]`` is a float.
    """

    matrix, data = _make((4, 5))

    assert isinstance(matrix[2, 3], float)
    assert matrix[2, 3] == data[2, 3]

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("key", KEYS)
def test_a_write_through_a_slice_reaches_the_parent(key):
    """
    Slices are views: writing through ``S = D[key]`` changes exactly the selected entries of ``D``.

    Parameters
    ----------
    key : object
        Key applied to a ``(4, 5)`` matrix.
    """

    matrix, data = _make((4, 5))
    view = matrix[key]
    shape = view.shape

    view.set(7.5)
    _expected(data, key)[...] = 7.5

    np.testing.assert_array_equal(matrix.to_numpy(), data)

    first = (0,) * len(shape)
    view[first] = -3.0
    selected = _expected(data, key)
    selected[first] = -3.0

    np.testing.assert_array_equal(matrix.to_numpy(), data)
    assert view.shape == shape

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("key", KEYS)
def test_a_write_into_the_parent_shows_in_the_slice(key):
    """
    Slices are views: a write into the parent shows through a slice taken earlier.

    Parameters
    ----------
    key : object
        Key applied to a ``(4, 5)`` matrix.
    """

    matrix, data = _make((4, 5))
    view = matrix[key]

    matrix[:, :] = 2.0
    data[...] = 2.0

    np.testing.assert_array_equal(view.to_numpy(), _expected(data, key))

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_slices_of_slices_are_views_of_the_root():
    """
    A slice of a slice (with steps) is a view of the root.
    """

    matrix, data = _make((6, 7))
    inner = matrix[1:6, ::2][::2, 1:]

    inner.set(9.0)
    data[1:6, ::2][::2, 1:] = 9.0

    np.testing.assert_array_equal(matrix.to_numpy(), data)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("seed", range(12))
def test_random_slices_and_writes_follow_numpy(seed):
    """
    Random keys on random shapes: the view has NumPy's values, and writes of a ``dmat`` or a float
    through the key reach the parent exactly where NumPy's do.

    Parameters
    ----------
    seed : int
        Seed of the shape and the key.
    """

    rng = np.random.default_rng(700 + seed)
    shape = tuple(int(n) for n in rng.integers(3, 8, size=2))
    matrix, data = _make(shape, seed)
    rows = slice(int(rng.integers(0, shape[0])), None, int(rng.integers(1, 3)))
    cols = slice(int(rng.integers(0, shape[1])), None, int(rng.integers(1, 3)))
    key = (rows, cols)
    selected = data[key]
    view = matrix[key]

    np.testing.assert_array_equal(view.to_numpy(), selected)

    values = rng.standard_normal(selected.shape)

    matrix[key] = real.array(values)
    data[key] = values

    np.testing.assert_array_equal(matrix.to_numpy(), data)

    matrix[key] = -1.25
    data[key] = -1.25

    np.testing.assert_array_equal(matrix.to_numpy(), data)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _isolated(code):
    """
    Run a snippet in a fresh interpreter with the same import path.

    Parameters
    ----------
    code : str
        Python source; it must exit with status 0 when the behaviour is the expected one.

    Returns
    -------
    subprocess.CompletedProcess
        The finished process.
    """

    env = dict(os.environ, PYTHONPATH=os.pathsep.join(path for path in sys.path if path))

    return subprocess.run([sys.executable, "-c", code], capture_output=True, text=True, env=env,
                          timeout=300, check=False)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("key", [
    "(slice(1, 3), slice(None))",
    "(slice(None), slice(1, 3))",
    "(slice(None, None, 2), slice(1, 4))",
    "(slice(1, 4), slice(1, 4))",
])
@pytest.mark.parametrize("reader", ["to_numpy", "arithmetic", "element", "copy", "nested"])
def test_a_slice_read_after_the_parent_is_dropped(key, reader):
    """
    Regression (W4, ``dmat._view`` kept a temporary view of its parent): a slice, a slice of a slice,
    and the results computed from them read valid memory after every reference to the parent is gone
    and the heap has been churned.

    The check runs in a fresh interpreter, because a dangling view can crash the process.

    Parameters
    ----------
    key : str
        Source of the key of the slice.
    reader : str
        How the slice is read after the parent is dropped.
    """

    code = f"""
import gc
import numpy as np
import pyoti.real as real

data = np.random.default_rng(11).standard_normal((6, 6))
matrix = real.array(data)
key = {key}
view = matrix[key]
expected = data[key]

if {reader!r} == "nested":

    view = view[0:2, 0:2]
    expected = expected[0:2, 0:2]

del matrix
gc.collect()
noise = [np.full(50000, 123.0) for _ in range(8)]

if {reader!r} == "to_numpy":

    got = view.to_numpy()

elif {reader!r} == "arithmetic":

    got = (view + view).to_numpy()
    expected = expected + expected

elif {reader!r} == "element":

    got = np.array([view[0, 0]])
    expected = expected[:1, 0]

elif {reader!r} == "copy":

    got = view.copy().to_numpy()

else:

    got = view.to_numpy()

np.testing.assert_allclose(got.reshape(-1), np.asarray(expected).reshape(-1))
"""

    result = _isolated(code)

    assert result.returncode == 0, result.stderr[-2000:]

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_a_slice_keeps_the_parent_memory_alive():
    """
    A slice outlives its parent: the data stays valid after the parent is dropped.
    """

    matrix, data = _make((5, 5))
    view = matrix[1:4, 1:4]

    del matrix
    gc.collect()

    noise = [np.full(100000, 123.0) for _ in range(4)]

    np.testing.assert_array_equal(view.to_numpy(), data[1:4, 1:4])
    assert len(noise) == 4

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_to_numpy_is_a_writable_zero_copy_view():
    """
    ``to_numpy()`` is a writable NumPy view of the matrix memory: a write through it reaches the
    ``dmat``, and a write into the ``dmat`` shows in it. It works on slices too.
    """

    matrix, data = _make((4, 5))
    array = matrix.to_numpy()

    assert array.flags.writeable
    assert np.shares_memory(array, matrix.to_numpy())

    array[0, 0] = 5.0
    data[0, 0] = 5.0

    assert matrix[0, 0] == 5.0

    matrix[1, 1] = 6.0
    data[1, 1] = 6.0

    assert array[1, 1] == 6.0

    view = matrix[1:3, 2:5]
    sub = view.to_numpy()

    assert np.shares_memory(sub, array)

    sub[0, 0] = -2.0
    data[1, 2] = -2.0

    np.testing.assert_array_equal(matrix.to_numpy(), data)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_to_numpy_of_a_temporary_keeps_its_owner_alive():
    """
    The NumPy view of a temporary ``dmat`` stays valid: the array keeps the matrix alive.
    """

    first, a = _make((3, 4), 1)
    second, b = _make((3, 4), 2)
    array = (first * second).to_numpy()

    gc.collect()

    noise = [np.full(50000, 99.0) for _ in range(8)]

    np.testing.assert_array_equal(array, a * b)
    assert len(noise) == 8

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("key", KEYS)
def test_operators_accept_views(key):
    """
    Arithmetic operators work on views (strided included) and match NumPy; the results are new
    independent matrices.

    Parameters
    ----------
    key : object
        Key applied to two ``(4, 5)`` matrices.
    """

    first, a = _make((4, 5), 1)
    second, b = _make((4, 5), 2)
    left = first[key]
    right = second[key]
    ea = _expected(a, key)
    eb = _expected(b, key)

    np.testing.assert_allclose((left + right).to_numpy(), ea + eb)
    np.testing.assert_allclose((left - right).to_numpy(), ea - eb)
    np.testing.assert_allclose((left * right).to_numpy(), ea * eb)
    np.testing.assert_allclose((left / right).to_numpy(), ea / eb)
    np.testing.assert_allclose((-left).to_numpy(), -ea)
    np.testing.assert_allclose((left * 2.5).to_numpy(), ea * 2.5)
    np.testing.assert_allclose((left + 1.0).to_numpy(), ea + 1.0)

    product = left * right

    product.set(0.0)

    np.testing.assert_array_equal(first.to_numpy(), a)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_copy_of_a_view_is_independent():
    """
    ``copy()`` of a view is an independent matrix with the view's values.
    """

    matrix, data = _make((5, 6))
    view = matrix[1:4, ::2]
    clone = view.copy()

    clone.set(0.0)
    view[0, 0] = 99.0

    assert clone.shape == view.shape
    np.testing.assert_array_equal(clone.to_numpy(), np.zeros(view.shape))
    assert matrix[1, 0] == 99.0

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_linear_algebra_on_views_matches_numpy():
    """
    ``dot``, ``solve``, ``inv``, ``det``, ``norm`` and ``transpose`` accept views and match NumPy.
    """

    rng = np.random.default_rng(5)
    base = rng.standard_normal((8, 8)) + 6.0 * np.eye(8)
    square = real.array(base)
    view = square[0:6:2, 0:6:2]
    block = base[0:6:2, 0:6:2]
    rdata = rng.standard_normal((3, 1))
    rhs = real.array(rdata)

    np.testing.assert_allclose(real.dot(view, view).to_numpy(), block @ block)
    np.testing.assert_allclose(real.solve(view, rhs).to_numpy(), np.linalg.solve(block, rdata))
    np.testing.assert_allclose(real.inv(view).to_numpy(), np.linalg.inv(block))
    assert real.det(view) == pytest.approx(np.linalg.det(block))
    assert real.norm(view) == pytest.approx(np.linalg.norm(block))
    np.testing.assert_array_equal(real.transpose(view).to_numpy(), block.T)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_the_one_x_creators_keep_their_shapes():
    """
    The creators are unchanged until 7b: ``zeros((r, c))``, ``ones``, ``eye``, ``array`` of a 2-D
    array keep their 2-D shapes and values.
    """

    zeros = real.zeros((2, 3))
    ones = real.ones((2, 3))
    eye = real.eye(3)

    assert zeros.shape == (2, 3)
    assert ones.shape == (2, 3)
    assert eye.shape == (3, 3)
    np.testing.assert_array_equal(zeros.to_numpy(), np.zeros((2, 3)))
    np.testing.assert_array_equal(ones.to_numpy(), np.ones((2, 3)))
    np.testing.assert_array_equal(eye.to_numpy(), np.eye(3))
    assert real.array(np.arange(6.0).reshape(2, 3)).shape == (2, 3)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("key", [(4, 0), (0, 5), 4])
def test_out_of_range_keys_raise_index_error(key):
    """
    Out-of-range integers raise ``IndexError``.

    Parameters
    ----------
    key : object
        Invalid key for a ``(4, 5)`` matrix.
    """

    matrix, _ = _make((4, 5))

    with pytest.raises(IndexError):

        matrix[key]

    # end with

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("operation", ["add", "sub", "mul", "dot"])
def test_sparse_operands_mix_with_views(operation):
    """
    ``matso op dmat`` keeps working, with a whole matrix and with a strided view as the ``dmat``
    operand; the result is the NumPy value on the real part.

    Parameters
    ----------
    operation : str
        ``"add"``, ``"sub"``, ``"mul"`` or ``"dot"``.
    """

    rng = np.random.default_rng(8)
    wide, wdata = _make((4, 6), 9)
    sparse_data = rng.standard_normal((4, 3))
    sparse_array = sp.array(sparse_data) + sp.e(1, order=1) * sp.array(rng.standard_normal((4, 3)))
    view = wide[:, ::2]
    dense_part = wdata[:, ::2]

    if operation == "dot":

        sparse_array = sp.array(sparse_data.T) + sp.e(1, order=1) * sp.array(rng.standard_normal((3, 4)))
        expected = sparse_data.T @ dense_part
        result = sp.dot(sparse_array, view)

    else:

        function = {"add": np.add, "sub": np.subtract, "mul": np.multiply}[operation]
        operator = {"add": "__add__", "sub": "__sub__", "mul": "__mul__"}[operation]
        expected = function(sparse_data, dense_part)
        result = getattr(sparse_array, operator)(view)

    # end if

    np.testing.assert_allclose(np.array(result.real), expected)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_dmat_slices_written_by_sparse_code_reach_the_parent():
    """
    A ``dmat`` view handed to library code that writes into it (a ``matso`` assignment of a real
    block) reaches the parent matrix.
    """

    matrix, data = _make((4, 6))
    view = matrix[1:3, 2:5]
    sparse_array = sp.array(np.ones((2, 3)) * 4.0)

    view[:, :] = real.array(np.array(sparse_array.real))
    data[1:3, 2:5] = 4.0

    np.testing.assert_array_equal(matrix.to_numpy(), data)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_fem_helpers_still_use_real_matrices():
    """
    ``fem`` keeps allocating real shape-function matrices (``dmatfe``) for an element: the shape
    functions at an integration point sum to one and the weights are positive.
    """

    element = fem.element[3]

    element.end()
    element.allocate(intorder=2)

    assert element.nip > 0

    for ip in range(element.nip):

        shape = np.array(element.N.get_ip(ip).real).reshape(-1)

        assert shape.sum() == pytest.approx(1.0)

    # end for

    assert all(float(np.array(element.w[ip].real)) > 0.0 for ip in range(element.nip))

    element.end()

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_dmatfe_keeps_the_matrix_rule_and_the_gauss_layout():
    """
    ``dmatfe`` keeps its behaviour on the real Gauss layout ``(nip, nrows, ncols)``: ``G[i, j]`` is a
    ``dnumfe``, ``G[i]`` is ``(1, ncols)``, ``get_ip`` returns an ``(nrows, ncols)`` matrix and
    ``set_ijk`` writes one entry.
    """

    nip, rows, cols = 4, 2, 3
    gauss = real.dmatfe((rows, cols), nip=nip)

    assert gauss.shape == (rows, cols)
    assert gauss.nip == nip
    assert isinstance(gauss[1, 2], real.dnumfe)
    assert gauss[0].shape == (1, cols)
    assert gauss.get_ip(0).shape == (rows, cols)

    for ip in range(nip):

        for i in range(rows):

            for j in range(cols):

                gauss.set_ijk(float(100 * ip + 10 * i + j), i, j, ip)

            # end for

        # end for

    # end for

    for ip in range(nip):

        expected = np.array([[100 * ip + 10 * i + j for j in range(cols)] for i in range(rows)],
                            dtype=float)

        np.testing.assert_array_equal(gauss.get_ip(ip).to_numpy(), expected)

    # end for

    values = np.array(gauss.real_numpy)

    assert values.shape == (rows, cols, nip)
    assert values.strides[-1] == 8
    np.testing.assert_array_equal(values[:, :, 2], gauss.get_ip(2).to_numpy())

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_dnumfe_values_per_integration_point():
    """
    ``dnumfe`` holds one real value per integration point and indexes by point.
    """

    values = np.array([1.5, -2.0, 3.25, 4.0])
    number = real.dnumfe(0.0, nip=4)

    for ip, value in enumerate(values):

        number[ip] = value

    # end for

    assert [number[ip] for ip in range(4)] == list(values)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_numpy_asarray_shares_memory():
    """
    ``np.asarray(dmat)`` goes through the buffer protocol and shares the memory of the ``dmat``: a
    write through the array reaches the matrix.
    """

    matrix, data = _make((3, 4))
    array = np.asarray(matrix)

    assert array.shape == (3, 4)
    assert array.dtype == np.float64
    np.testing.assert_array_equal(array, data)

    array[1, 2] = 42.0

    assert matrix[1, 2] == 42.0

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_memoryview_exports_the_layout_of_the_matrix():
    """
    ``memoryview(dmat)`` exposes the matrix: ``float64`` (format ``d``), the shape and a writable
    buffer that shares memory.
    """

    matrix, data = _make((3, 4))

    with memoryview(matrix) as view:

        assert view.format == "d"
        assert view.shape == (3, 4)
        assert not view.readonly
        assert view.itemsize == 8

        view[0, 0] = 5.0

        np.testing.assert_array_equal(np.array(view), np.asarray(matrix))

    # end with

    assert matrix[0, 0] == 5.0

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("key", KEYS)
def test_buffer_export_of_a_view_shares_the_strided_memory(key):
    """
    The buffer export of a slice keeps the strides of the view (no copy): the NumPy array has the
    shape of the slice and writes reach the parent.

    Parameters
    ----------
    key : object
        Key applied to a ``(4, 5)`` matrix.
    """

    matrix, data = _make((4, 5))
    view = matrix[key]
    array = np.asarray(view)
    expected = _expected(data, key)

    assert array.shape == expected.shape
    np.testing.assert_array_equal(array, expected)

    array[...] = 3.0
    expected[...] = 3.0

    np.testing.assert_array_equal(matrix.to_numpy(), data)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_dlpack_shares_memory():
    """
    ``np.from_dlpack(dmat)`` shares the memory of the ``dmat`` (zero copy), with the strides of a view.
    """

    matrix, data = _make((4, 5))
    array = np.from_dlpack(matrix)

    assert array.shape == (4, 5)
    np.testing.assert_array_equal(array, data)
    assert np.shares_memory(array, matrix.to_numpy())

    array[0, 0] = 11.0

    assert matrix[0, 0] == 11.0

    view = matrix[1:4:2, ::2]
    strided = np.from_dlpack(view)

    assert strided.shape == (2, 3)
    np.testing.assert_array_equal(strided, data[1:4:2, ::2])

    strided[0, 0] = 12.0

    assert matrix[1, 0] == 12.0

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_dlpack_device_is_cpu():
    """
    ``__dlpack_device__`` reports the CPU device ``(1, 0)`` (``kDLCPU``).
    """

    matrix, _ = _make((2, 2))

    assert matrix.__dlpack_device__() == (1, 0)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_dlpack_capsule_is_versioned_and_renamed_when_consumed():
    """
    ``__dlpack__(max_version=(1, 0))`` returns a ``"dltensor_versioned"`` capsule, ``__dlpack__()``
    without a version returns a legacy ``"dltensor"`` capsule, and NumPy's consumption renames the
    capsule to its ``used_*`` name.
    """

    import ctypes

    matrix, data = _make((2, 3))
    name = ctypes.pythonapi.PyCapsule_GetName
    name.restype = ctypes.c_char_p
    name.argtypes = [ctypes.py_object]

    versioned = matrix.__dlpack__(max_version=(1, 0))

    assert name(versioned) == b"dltensor_versioned"

    legacy = matrix.__dlpack__()

    assert name(legacy) == b"dltensor"

    class Holder:
        """
        Minimal DLPack producer around an existing capsule.
        """

        def __init__(self, capsule):
            """
            Store the capsule.

            Parameters
            ----------
            capsule : object
                DLPack capsule.
            """

            self.capsule = capsule

        # end def

        def __dlpack__(self, stream=None, **kwargs):
            """
            Return the stored capsule.

            Parameters
            ----------
            stream : object, optional
                Ignored.
            **kwargs
                Ignored.

            Returns
            -------
            object
                The capsule.
            """

            return self.capsule

        # end def

        def __dlpack_device__(self):
            """
            Return the CPU device.

            Returns
            -------
            tuple of int
                ``(1, 0)``.
            """

            return (1, 0)

        # end def

    # end class

    array = np.from_dlpack(Holder(legacy))

    assert name(legacy) == b"used_dltensor"
    np.testing.assert_array_equal(array, data)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_dlpack_accepts_the_cpu_stream_argument():
    """
    A CPU producer accepts ``stream=None`` and a CPU ``dl_device``, and the result shares the memory.
    """

    matrix, data = _make((3, 3))
    array = np.from_dlpack(matrix)

    np.testing.assert_array_equal(array, data)

    capsule = matrix.__dlpack__(stream=None, max_version=(1, 0), dl_device=(1, 0))

    assert capsule is not None

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("producer", ["dlpack", "buffer", "asarray"])
def test_the_exporter_stays_alive_while_a_consumer_holds_it(producer):
    """
    The consumer's array keeps the exported memory alive: after the ``dmat`` (and its slice) are
    dropped and the garbage is collected, the array still reads the original values.

    Parameters
    ----------
    producer : str
        ``"dlpack"``, ``"buffer"`` or ``"asarray"``.
    """

    matrix, data = _make((5, 6), 21)
    view = matrix[1:4, 1:5]

    if producer == "dlpack":

        array = np.from_dlpack(view)

    elif producer == "buffer":

        array = np.asarray(memoryview(view))

    else:

        array = np.asarray(view)

    # end if

    expected = data[1:4, 1:5].copy()

    del view, matrix
    gc.collect()

    noise = [np.full(100000, 7.0) for _ in range(6)]

    np.testing.assert_array_equal(array, expected)
    assert len(noise) == 6

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_a_memoryview_keeps_the_export_alive():
    """
    A ``memoryview`` held by the consumer keeps the memory valid after the ``dmat`` is dropped.
    """

    matrix, data = _make((3, 3), 5)
    view = memoryview(matrix)
    expected = data.copy()

    del matrix
    gc.collect()

    noise = [np.full(100000, 7.0) for _ in range(6)]

    np.testing.assert_array_equal(np.array(view), expected)
    assert len(noise) == 6

    view.release()

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_a_live_export_blocks_growth_with_a_buffererror():
    """
    A live export (a ``memoryview``, a DLPack-backed NumPy array) pins the buffer: the relayout that
    would move it raises ``BufferError`` with the words ``live export``, and works once the export is
    released.
    """

    from pyoti.real import _ndtest

    root = _ndtest.root((2, 3))
    exported = np.from_dlpack(root)

    with pytest.raises(BufferError, match="live export"):

        root.grow(8)

    # end with

    del exported
    gc.collect()

    root.grow(8)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_the_dlpack_deleter_runs_on_another_thread():
    """
    The last reference to a DLPack-backed array dropped on another thread releases the export without
    crashing (the deleter takes the GIL itself): repeated many times with slices and parents.
    """

    errors = []

    def drop(holder):
        """
        Drop the last reference on a worker thread.

        Parameters
        ----------
        holder : list
            One-element list holding the array.
        """

        try:

            holder.clear()
            gc.collect()

        except BaseException as error:  # noqa: BLE001 - reported below

            errors.append(error)

        # end try

    # end def

    for seed in range(50):

        matrix, data = _make((4, 4), seed)
        holder = [np.from_dlpack(matrix[1:4:2, ::2])]
        thread = threading.Thread(target=drop, args=(holder,))
        thread.start()
        thread.join()

        del matrix

    # end for

    gc.collect()

    assert errors == []

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_the_buffer_release_runs_on_another_thread():
    """
    A ``memoryview`` released on another thread does not crash and frees the export.
    """

    for seed in range(30):

        matrix, _ = _make((3, 5), seed)
        view = memoryview(matrix)
        thread = threading.Thread(target=view.release)
        thread.start()
        thread.join()

        del view, matrix

    # end for

    gc.collect()

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_exports_of_a_numpy_array_view_the_matrix_not_a_copy():
    """
    ``np.asarray`` and ``np.from_dlpack`` of the same ``dmat`` view the same memory: a write through
    one shows through the other.
    """

    matrix, _ = _make((3, 3))
    first = np.asarray(matrix)
    second = np.from_dlpack(matrix)

    first[2, 2] = 77.0

    assert second[2, 2] == 77.0
    assert np.shares_memory(first, second)

# end function
# --------------------------------------------------------------------------------------------------------
