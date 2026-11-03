"""
NumPy-oracle tests of the advanced indexing of ``ndarr_t`` (Phase 5: ``nd_index_get`` / ``nd_index_set``),
through ``pyoti.real._ndtest.index_get`` and ``index_set``.

Written from the contracts and the final semantics posted by the ``nd-core`` agent
(``build-orch/w3-notes/nd-core.md``), never from the implementation. NumPy 2 is the oracle: integer
arrays, masks (k-D, 0-D, boolean scalars), integers and slices mixed in one key, the axis placement of
the broadcast axes, negative indices, duplicates (the last write wins), aliasing of values and index
arrays with the destination, the statuses and their exceptions, and that a failed call leaves the
destination unchanged.
"""

import os
import subprocess
import sys

import numpy as np
import pytest

try:

    import pyoti.real as real

    ND = real._ndtest

except (ImportError, AttributeError):  # pragma: no cover - the test build has no _ndtest

    ND = None

# end try

if ND is None or not hasattr(ND, "index_get"):  # pragma: no cover

    pytest.skip("pyoti.real._ndtest has no index_get / index_set", allow_module_level=True)

# end if

DTYPES = [np.float64, np.int64, np.bool_]


# ********************************************************************************************************
@pytest.fixture(autouse=True)
def _clean_state():
    """
    Reset the context limits and the allocation-failure injection around every test.
    """

    ND.set_limits()
    ND.fail_alloc(0)
    ND.clear_error()

    yield

    ND.set_limits()
    ND.fail_alloc(0)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _source(rng, shape, dtype, layout):
    """
    Build a source array with a given dtype and memory layout.

    Parameters
    ----------
    rng : numpy.random.Generator
        Source of the values.
    shape : tuple of int
        Shape of the array.
    dtype : type
        ``numpy.float64``, ``numpy.int64`` or ``numpy.bool_``.
    layout : str
        ``"C"``, ``"F"``, ``"reversed"`` (negative strides) or ``"sliced"`` (a strided view of a
        larger array).

    Returns
    -------
    numpy.ndarray
        The array.
    """

    if dtype is np.bool_:

        values = rng.random(shape) > 0.5

    elif dtype is np.int64:

        values = rng.integers(-50, 50, size=shape)

    else:

        values = rng.standard_normal(shape)

    # end if

    if layout == "C":

        return np.ascontiguousarray(values)

    # end if

    if layout == "F":

        return np.asfortranarray(values)

    # end if

    if layout == "reversed":

        return np.ascontiguousarray(values)[(slice(None, None, -1),) * len(shape)]

    # end if

    big = np.zeros(tuple(2 * n + 1 for n in shape), dtype=dtype)
    window = tuple(slice(1, 2 * n, 2) for n in shape)
    big[window] = values

    return big[window]

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _int_array(rng, extent, shape):
    """
    Build an integer index array with values in ``[-extent, extent)``.

    Parameters
    ----------
    rng : numpy.random.Generator
        Source of the values.
    extent : int
        Extent of the indexed axis.
    shape : tuple of int
        Shape of the index array.

    Returns
    -------
    numpy.ndarray
        The ``int64`` index array.
    """

    return rng.integers(-extent, extent, size=shape).astype(np.int64)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _random_key(rng, shape):
    """
    Build a random NumPy key with at least one integer array or mask for an array of a given shape.

    Parameters
    ----------
    rng : numpy.random.Generator
        Source of the choices.
    shape : tuple of int
        Shape of the indexed array (every extent at least 1).

    Returns
    -------
    tuple
        The key (a tuple of items).
    """

    ndim = len(shape)
    broadcast = tuple(int(n) for n in rng.integers(1, 4, size=int(rng.integers(0, 3))))
    items = []
    axis = 0
    advanced = False

    if ndim >= 2 and rng.random() < 0.25:

        # A mask over the first k axes.
        k = int(rng.integers(1, ndim + 1))
        items.append(rng.random(shape[:k]) > 0.4)
        axis = k
        advanced = True

    # end if

    while axis < ndim:

        kind = int(rng.integers(0, 4))

        if kind == 0:

            items.append(int(rng.integers(-shape[axis], shape[axis])))

        elif kind == 1:

            start = int(rng.integers(-shape[axis], shape[axis]))
            items.append(slice(start, None, int(rng.choice([-2, -1, 1, 2]))))

        else:

            ashape = tuple(n if rng.random() < 0.6 else 1 for n in broadcast)
            ashape = ashape[int(rng.integers(0, len(ashape) + 1)):] if ashape else ashape
            items.append(_int_array(rng, shape[axis], ashape))
            advanced = True

        # end if

        axis += 1

        if rng.random() < 0.15:

            items.append(None)

        # end if

    # end while

    if not advanced:

        position = int(rng.integers(0, len(items)))
        extent = shape[min(position, ndim - 1)]
        items = [_int_array(rng, extent, (int(rng.integers(1, 4)),)) if i == position
                 and isinstance(item, (int, slice)) else item for i, item in enumerate(items)]

        if not any(isinstance(item, np.ndarray) for item in items):

            items[0] = np.array([0], dtype=np.int64)

        # end if

    # end if

    if rng.random() < 0.2 and not any(item is Ellipsis for item in items):

        items.insert(int(rng.integers(0, len(items) + 1)), Ellipsis)

    # end if

    return tuple(items)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _numpy_get(source, key):
    """
    Apply a key with NumPy, or report that NumPy refuses it.

    Parameters
    ----------
    source : numpy.ndarray
        Source array.
    key : tuple
        Key.

    Returns
    -------
    numpy.ndarray or None
        NumPy's result, or ``None`` when NumPy raises ``IndexError`` (an invalid random key).
    """

    try:

        return source[key]

    except IndexError:

        return None

    # end try

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("layout", ["C", "F", "reversed", "sliced"])
@pytest.mark.parametrize("dtype", DTYPES)
@pytest.mark.parametrize("seed", range(10))
def test_get_matches_numpy(seed, dtype, layout):
    """
    ``index_get`` with random keys (integer arrays, masks, integers, slices, ``None``, ``...``) on
    sources of every dtype and layout gives NumPy's values, shape and dtype, as a C-contiguous copy.

    Parameters
    ----------
    seed : int
        Seed of the shape and key.
    dtype : type
        Element type of the source.
    layout : str
        Memory layout of the source.
    """

    rng = np.random.default_rng(1000 * seed + 7)
    shape = tuple(int(n) for n in rng.integers(1, 5, size=int(rng.integers(1, 5))))
    source = _source(rng, shape, dtype, layout)

    for _ in range(12):

        key = _random_key(rng, shape)
        expected = _numpy_get(source, key)

        if expected is None:

            continue

        # end if

        result = ND.index_get(source, key)

        assert result.shape == expected.shape
        assert result.dtype == expected.dtype
        np.testing.assert_array_equal(result, expected)
        assert result.flags.c_contiguous
        assert result.flags.writeable
        assert not np.shares_memory(result, source) or result.size == 0

    # end for

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("layout", ["C", "F", "reversed", "sliced"])
@pytest.mark.parametrize("dtype", [np.float64, np.int64])
@pytest.mark.parametrize("seed", range(10))
def test_set_matches_numpy(seed, dtype, layout):
    """
    ``index_set`` with random keys and values of random broadcastable shapes gives NumPy's destination,
    duplicates included (the last write in C index order wins), and returns the destination.

    Parameters
    ----------
    seed : int
        Seed of the shape and key.
    dtype : type
        Element type of the destination.
    layout : str
        Memory layout of the destination.
    """

    rng = np.random.default_rng(2000 * seed + 11)
    shape = tuple(int(n) for n in rng.integers(1, 5, size=int(rng.integers(1, 5))))

    for _ in range(10):

        destination = _source(rng, shape, dtype, layout)
        reference = destination.copy()
        key = _random_key(rng, shape)
        target = _numpy_get(reference, key)

        if target is None:

            continue

        # end if

        choice = int(rng.integers(0, 4))

        if choice == 0:

            values = np.array(dtype(rng.integers(-9, 9)))

        elif choice == 1:

            values = _source(rng, target.shape, dtype, "C")

        elif choice == 2 and target.ndim > 0:

            values = _source(rng, target.shape[1:], dtype, "C")

        else:

            values = _source(rng, (1,) + target.shape, dtype, "C")

        # end if

        try:

            reference[key] = values

        except (ValueError, TypeError):

            # NumPy's single-mask path rejects values of rank >= 2; the library broadcasts them.
            continue

        # end try

        returned = ND.index_set(destination, key, values)

        assert returned is destination
        np.testing.assert_array_equal(destination, reference)

    # end for

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("key", [
    pytest.param((np.array([0, 2]),), id="rows"),
    pytest.param((np.array([0, 2]), np.array([1, 3])), id="pairs"),
    pytest.param((slice(None), np.array([3, 0, 3])), id="columns"),
    pytest.param((np.array([[0], [1]]), np.array([0, 2, 3])), id="broadcast"),
    pytest.param((np.array([-1, -4]), slice(1, 3)), id="negative"),
    pytest.param((np.array([1]), 2), id="integer-and-array"),
    pytest.param((Ellipsis, np.array([0, 1])), id="ellipsis"),
    pytest.param((np.array([0, 1]), None, np.array([2, 3])), id="newaxis-between"),
    pytest.param((np.array([0, 1]), slice(None), np.array([2, 3])), id="separated-by-a-slice"),
    pytest.param((slice(None), np.array([0, 1]), np.array([2, 3])), id="adjacent-trailing"),
])


def test_axis_placement_follows_numpy(key):
    """
    The broadcast axes of the advanced items sit where NumPy puts them: at the first advanced item when
    the advanced items are adjacent (integers included), first when a slice, ``None`` or ``...``
    separates them.

    Parameters
    ----------
    key : tuple
        Key applied to an array of shape ``(4, 5)`` or ``(4, 5, 6)``.
    """

    for shape in ((4, 5, 6),):

        source = np.arange(np.prod(shape), dtype=np.float64).reshape(shape)
        expected = _numpy_get(source, key)

        if expected is None:

            continue

        # end if

        result = ND.index_get(source, key)

        assert result.shape == expected.shape
        np.testing.assert_array_equal(result, expected)

    # end for

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("mask_shape", [(4,), (4, 5), (4, 5, 6)])
def test_k_dimensional_masks_equal_their_nonzero_arrays(mask_shape):
    """
    A k-D mask indexes like its ``nonzero()`` arrays: ``a[m]`` gives one ``(nnz,)`` axis over the k
    masked axes, for get and set.

    Parameters
    ----------
    mask_shape : tuple of int
        Shape of the mask (leading axes of the ``(4, 5, 6)`` array).
    """

    rng = np.random.default_rng(31)
    source = rng.standard_normal((4, 5, 6))
    mask = rng.random(mask_shape) > 0.5
    result = ND.index_get(source, (mask,))

    np.testing.assert_array_equal(result, source[mask])
    np.testing.assert_array_equal(result, source[mask.nonzero()])

    destination = source.copy()
    reference = source.copy()
    values = rng.standard_normal(reference[mask].shape)

    reference[mask] = values
    ND.index_set(destination, (mask,), values)

    np.testing.assert_array_equal(destination, reference)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("scalar", [True, False])
def test_zero_dimensional_masks_join_the_broadcast(scalar):
    """
    A boolean scalar in the key inserts a ``(1,)`` (True) or ``(0,)`` (False) axis, like NumPy, for get
    and set.

    Parameters
    ----------
    scalar : bool
        Value of the boolean scalar.
    """

    source = np.arange(12.0).reshape(3, 4)
    key = (scalar, slice(None), 1)
    result = ND.index_get(source, key)

    assert result.shape == source[key].shape
    np.testing.assert_array_equal(result, source[key])

    destination = source.copy()
    reference = source.copy()

    reference[key] = -5.0
    ND.index_set(destination, key, -5.0)

    np.testing.assert_array_equal(destination, reference)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_zero_dimensional_integer_arrays_are_integers():
    """
    A 0-D integer array is an integer (NumPy): it is bounds-checked and drops its axis.
    """

    source = np.arange(24.0).reshape(2, 3, 4)
    key = (np.array(1), slice(None), np.array([0, 2]))
    result = ND.index_get(source, key)

    assert result.shape == source[key].shape
    np.testing.assert_array_equal(result, source[key])

    with pytest.raises(IndexError):

        ND.index_get(source, (np.array(5), np.array([0])))

    # end with

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_empty_index_arrays_and_masks():
    """
    Empty index arrays and all-False masks give empty results with NumPy's shapes, and set with them
    changes nothing.
    """

    source = np.arange(12.0).reshape(3, 4)

    nothing = np.array([], dtype=np.int64)

    for key in ((nothing,), (slice(None), nothing), (np.zeros((3, 4), dtype=bool),), (nothing, nothing)):

        result = ND.index_get(source, key)

        assert result.shape == source[key].shape
        assert result.size == 0

        destination = source.copy()
        ND.index_set(destination, key, 7.0)

        np.testing.assert_array_equal(destination, source)

    # end for

    empty = np.zeros((0, 3))

    assert ND.index_get(empty, (np.array([], dtype=np.int64),)).shape == (0, 3)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_duplicates_in_a_set_keep_the_last_write():
    """
    With duplicate indices the last write in C index order wins (NumPy's documented behaviour).
    """

    destination = np.zeros(5)
    reference = np.zeros(5)
    index = np.array([1, 1, 3, 1, 3])
    values = np.array([1.0, 2.0, 3.0, 4.0, 5.0])

    reference[index] = values
    ND.index_set(destination, (index,), values)

    np.testing.assert_array_equal(destination, reference)
    assert destination[1] == 4.0
    assert destination[3] == 5.0

    grid = np.zeros((3, 3))
    expected = np.zeros((3, 3))
    rows = np.array([[0], [0], [2]])
    columns = np.array([[1, 1, 2]])
    data = np.arange(9.0).reshape(3, 3)

    expected[rows, columns] = data
    ND.index_set(grid, (rows, columns), data)

    np.testing.assert_array_equal(grid, expected)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_values_that_overlap_the_destination_are_copied_first():
    """
    ``a[idx] = a[::-1]``-style assignments, where the values share memory with the destination, behave
    as if the values were copied first.
    """

    base = np.arange(10.0)
    destination = base.copy()
    reference = base.copy()
    key = (np.array([0, 2, 4, 6, 8]),)
    values_view = destination[::-1][:5]

    reference[key] = reference[::-1][:5].copy()
    ND.index_set(destination, key, values_view)

    np.testing.assert_array_equal(destination, reference)

    square = np.arange(16.0).reshape(4, 4)
    expected = square.copy()
    mask = np.eye(4, dtype=bool)

    expected[mask] = expected[:, 0].copy()
    ND.index_set(square, (mask,), square[:, 0])

    np.testing.assert_array_equal(square, expected)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_index_arrays_that_alias_the_destination_are_safe():
    """
    ``x[x] = v`` with the index array being the destination behaves as NumPy: every offset is computed
    before the first write.
    """

    destination = np.array([3, 0, 2, 1, 4, 4, 0, 2], dtype=np.int64)
    reference = destination.copy()
    values = np.arange(8, dtype=np.int64) * 10

    reference[reference] = values
    ND.index_set(destination, (destination,), values)

    np.testing.assert_array_equal(destination, reference)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_get_of_a_read_only_source_is_writable():
    """
    ``index_get`` copies: the result is writable (and independent) even when the source is read-only.
    """

    source = np.arange(12.0).reshape(3, 4)
    source.flags.writeable = False
    result = ND.index_get(source, (np.array([0, 2]),))

    assert result.flags.writeable

    result[...] = -1.0

    np.testing.assert_array_equal(source[[0, 2]], np.arange(12.0).reshape(3, 4)[[0, 2]])

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("key", [
    pytest.param((np.array([3]),), id="too-large"),
    pytest.param((np.array([-4]),), id="too-negative"),
    pytest.param((np.array([0, 1]), np.array([0, 1]), np.array([0, 1])), id="too-many-indices"),
    pytest.param((Ellipsis, Ellipsis, np.array([0])), id="two-ellipses"),
    pytest.param((np.ones(2, dtype=bool),), id="mask-extent"),
    pytest.param((np.array(7), np.array([0])), id="zero-d-out-of-range"),
])


def test_get_errors_are_index_errors(key):
    """
    Out-of-range values, too many indices, two ellipses and a mask of the wrong extent
    raise ``IndexError`` (``OTI_ERR_INDEX``), as NumPy does.

    Parameters
    ----------
    key : tuple
        Invalid key for an array of shape ``(3, 4)``.
    """

    source = np.arange(12.0).reshape(3, 4)

    with pytest.raises(IndexError):

        source[key]

    # end with

    with pytest.raises(IndexError):

        ND.index_get(source, key)

    # end with

    assert ND.last_error()[0] == ND.status["INDEX"]

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_index_arrays_that_do_not_broadcast_are_a_shape_error():
    """
    Index arrays that do not broadcast together raise ``ValueError`` (``OTI_ERR_SHAPE``, the status of
    a broadcast failure, status.h). NumPy raises ``IndexError`` here: the library's mapping differs on
    purpose, and ``nd-core``'s notes say ``INDEX`` while the code and its C tests say ``SHAPE``.
    """

    source = np.arange(12.0).reshape(3, 4)
    key = (np.array([0, 1]), np.array([0, 1, 2]))

    with pytest.raises(IndexError):

        source[key]

    # end with

    with pytest.raises(ValueError):

        ND.index_get(source, key)

    # end with

    assert ND.last_error()[0] == ND.status["SHAPE"]

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_get_float_index_arrays_are_a_dtype_error():
    """
    An index array that is not integer or boolean (``float64``) raises ``TypeError`` (``OTI_ERR_DTYPE``;
    NumPy raises ``IndexError`` here, the mapping is the library's).
    """

    source = np.arange(12.0).reshape(3, 4)

    with pytest.raises(TypeError):

        ND.index_get(source, (np.array([0.0, 1.0]),))

    # end with

    assert ND.last_error()[0] == ND.status["DTYPE"]

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_set_values_that_do_not_broadcast_raise_value_error():
    """
    Values that cannot be broadcast to the indexed shape raise ``ValueError`` (``OTI_ERR_SHAPE``), and
    the destination is unchanged.
    """

    destination = np.arange(12.0).reshape(3, 4)
    before = destination.copy()

    with pytest.raises(ValueError):

        ND.index_set(destination, (np.array([0, 2]),), np.ones((3, 4)))

    # end with

    assert ND.last_error()[0] == ND.status["SHAPE"]
    np.testing.assert_array_equal(destination, before)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_set_into_a_read_only_destination_raises_value_error():
    """
    A set into a read-only destination raises ``ValueError`` (``OTI_ERR_READONLY``) before anything is
    written.
    """

    destination = np.arange(12.0).reshape(3, 4)
    destination.flags.writeable = False

    with pytest.raises(ValueError):

        ND.index_set(destination, (np.array([0]),), 1.0)

    # end with

    np.testing.assert_array_equal(destination, np.arange(12.0).reshape(3, 4))

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_a_failed_set_leaves_the_destination_unchanged():
    """
    Every index is checked before the first write: a bad value in the middle of the index array leaves
    the destination untouched, and the call fails with ``IndexError``.
    """

    destination = np.arange(10.0)
    before = destination.copy()

    with pytest.raises(IndexError):

        ND.index_set(destination, (np.array([1, 2, 99, 3]),), 0.0)

    # end with

    np.testing.assert_array_equal(destination, before)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_a_values_error_comes_before_an_index_value_error():
    """
    In a set, a values-broadcast error (``ValueError``) is reported before an index-value error
    (``IndexError``), as NumPy does.
    """

    destination = np.arange(10.0)

    with pytest.raises(ValueError):

        destination.copy()[np.array([99, 1])] = np.ones(3)

    # end with

    with pytest.raises(ValueError):

        ND.index_set(destination, (np.array([99, 1]),), np.ones(3))

    # end with

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_index_values_are_checked_only_for_a_non_empty_broadcast():
    """
    NumPy does not check the values of an index array when the broadcast of the index arrays is empty
    (``zeros((3, 3))[[5], []]`` is fine, ``zeros((3, 3))[[5], :0]`` is an ``IndexError``).
    """

    source = np.zeros((3, 3))
    empty = np.array([], dtype=np.int64)

    assert ND.index_get(source, (np.array([5]), empty)).shape == source[[5], []].shape

    with pytest.raises(IndexError):

        ND.index_get(source, (np.array([5]), slice(None, 0)))

    # end with

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_injected_allocation_failures_raise_memory_error_and_leave_the_destination():
    """
    An injected allocation failure at each allocation of a get and of a set raises ``MemoryError``,
    leaves the destination unchanged, and the same call succeeds afterwards.
    """

    rng = np.random.default_rng(77)
    source = rng.standard_normal((6, 5))
    key = (np.array([1, 4, 2]), np.array([[0], [3]]))

    for countdown in range(1, 6):

        ND.fail_alloc(countdown)

        try:

            ND.index_get(source, key)

        except MemoryError:

            pass

        # end try

        ND.fail_alloc(0)

        destination = source.copy()
        ND.fail_alloc(countdown)

        try:

            ND.index_set(destination, key, np.ones((2, 3)))

        except MemoryError:

            np.testing.assert_array_equal(destination, source)

        # end try

        ND.fail_alloc(0)

    # end for

    np.testing.assert_array_equal(ND.index_get(source, key), source[key])

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_the_result_budget_is_enforced():
    """
    The result is charged to ``max_alloc_bytes`` and the temporaries to ``max_temp_bytes``: a get whose
    result does not fit raises ``MemoryError``, and works again when the limit is lifted.
    """

    source = np.arange(100.0)
    key = (np.arange(100, dtype=np.int64),)

    ND.set_limits(max_alloc_bytes=64)

    with pytest.raises(MemoryError):

        ND.index_get(source, key)

    # end with

    ND.set_limits()

    np.testing.assert_array_equal(ND.index_get(source, key), source)

# end function
# --------------------------------------------------------------------------------------------------------


DETERMINISM_SCRIPT = """
import hashlib
import numpy as np
import pyoti.real as real

ND = real._ndtest
rng = np.random.default_rng(5)
source = rng.standard_normal((40, 50, 30))
digest = hashlib.sha256()

for key in ((rng.integers(0, 40, size=(70, 1)), rng.integers(0, 50, size=(1, 90))),
            (rng.random((40, 50)) > 0.5,),
            (slice(None), rng.integers(0, 50, size=500), slice(3, 20, 3))):

    digest.update(np.ascontiguousarray(ND.index_get(source, key)).tobytes())

destination = source.copy()
ND.index_set(destination, (rng.integers(0, 40, size=4000), rng.integers(0, 50, size=4000)), 2.5)
digest.update(destination.tobytes())
print(digest.hexdigest())
"""


# ********************************************************************************************************
def test_results_do_not_depend_on_the_thread_count():
    """
    Gather and scatter results (pure copies) are bit-identical at every thread count.
    """

    digests = set()

    for threads in ("1", "2", "3", "8"):

        env = dict(os.environ, OMP_NUM_THREADS=threads,
                   PYTHONPATH=os.pathsep.join(path for path in sys.path if path))
        process = subprocess.run([sys.executable, "-c", DETERMINISM_SCRIPT], capture_output=True,
                                 text=True, env=env, timeout=600, check=False)

        assert process.returncode == 0, process.stderr

        digests.add(process.stdout.strip())

    # end for

    assert len(digests) == 1

# end function
# --------------------------------------------------------------------------------------------------------
