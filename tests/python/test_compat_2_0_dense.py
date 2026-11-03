"""
The 2.0.0 compatibility suite of ``pyoti.dense`` (contracts section 11, breaking-changes list 11.14).

Every test asserts the 2.0.0 behaviour (the "after" column of the contracts). Tests whose behaviour
lands with Phase 7b carry ``@pytest.mark.xfail(strict=True, reason="2.0.0 behaviour, Phase 7b")``: the
suite passes today, and a test that starts to pass (XPASS) fails loudly, which is the signal to remove
its marker. Behaviour that is already 2.0.0 carries no marker. The names ``row n`` in the docstrings
refer to the numbered items of the breaking-changes list (11.14).
"""

import warnings

import numpy as np
import pytest
import scipy.sparse as scs

import pyoti.dense as dn
import pyoti.fem as fem
import pyoti.sparse as sp

PENDING = pytest.mark.xfail(strict=True, reason="2.0.0 behaviour, Phase 7b")
LIVE = "live block views"

# Files written by the last 1.x writer (version 1): an order-2 array of shape (2, 3) with two bases and
# a (4, 1) column with one base.
V1_2X3_O2 = bytes.fromhex(
    "934f54440100030108000201020000000200000000000000030000000000000020010000000000000000000000000000"
    "0000000000000000000000000000000000000000000000000000000000000840000000000000f03f0000000000001040"
    "000000000000004000000000000014400000000000000000000000000000f83f000000000000e03f0000000000000040"
    "000000000000f03f0000000000000440000000000000f03f000000000000f03f000000000000f03f000000000000f03f"
    "000000000000f03f000000000000f03f0000000000000000000000000000000000000000000000000000000000000000"
    "000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000"
    "000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000"
    "00000000000000000000000000000000"
)
V1_4X1_O1 = bytes.fromhex(
    "934f54440100030108000101010000000400000000000000010000000000000040000000000000000000000000000000"
    "00000000000000000000000000000000000000000000f03f000000000000004000000000000008400000000000001040"
    "000000000000e03f000000000000d03f0000000000000040000000000000f03f"
)


# ********************************************************************************************************
def _real(obj):
    """
    Copy the real part of an array into a NumPy array.

    Parameters
    ----------
    obj : omat or arro or otinum
        Array or scalar.

    Returns
    -------
    numpy.ndarray
        The real part (writable copy).
    """

    return np.array(obj.real, copy=True)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _make(shape, seed=0, order=2):
    """
    Build a dense array with random real data and two imaginary directions.

    Parameters
    ----------
    shape : tuple of int
        Shape of the array.
    seed : int, optional
        Seed of the generator.
    order : int, optional
        Truncation order.

    Returns
    -------
    omat, numpy.ndarray
        The array and its real part.
    """

    rng = np.random.default_rng(seed)
    real = rng.standard_normal(shape)
    other = rng.standard_normal(shape)

    return dn.array(real) + dn.e(1, order=order) * dn.array(other), real

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _same_state(first, second):
    """
    Assert that two dense arrays have the same shape, layout and coefficients.

    Parameters
    ----------
    first : omat
        First array.
    second : omat
        Second array.
    """

    assert first.shape == second.shape
    assert first.order == second.order
    assert first.active_bases == second.active_bases
    np.testing.assert_array_equal(_real(first), _real(second))

    for direction in ([1], [2], [1, 1]):

        np.testing.assert_array_equal(_real(first.get_deriv(direction)),
                                      _real(second.get_deriv(direction)))

    # end for

# end function
# --------------------------------------------------------------------------------------------------------


KEYS_3X4 = [
    pytest.param(1, id="int", marks=PENDING),
    pytest.param((1, slice(None)), id="int-colon", marks=PENDING),
    pytest.param((slice(None), 2), id="colon-int", marks=PENDING),
    pytest.param(-1, id="negative-int", marks=PENDING),
    pytest.param((-2, slice(None)), id="negative-int-colon", marks=PENDING),
    pytest.param((Ellipsis, 0), id="ellipsis-int", marks=PENDING),
    pytest.param((slice(1, 2), slice(None)), id="row-slice"),
    pytest.param((slice(None), slice(2, 3)), id="column-slice"),
    pytest.param((slice(None, None, -1), slice(0, 4, 2)), id="reversed-strided"),
    pytest.param((None, slice(None)), id="newaxis", marks=PENDING),
    pytest.param((slice(None), None, 1), id="newaxis-middle", marks=PENDING),
    pytest.param((Ellipsis, None), id="ellipsis-newaxis", marks=PENDING),
]


# ********************************************************************************************************
@pytest.mark.parametrize("key", KEYS_3X4)
def test_basic_indexing_matches_numpy(key):
    """
    Row 1: basic indexing follows NumPy: an integer drops its axis, a slice keeps it, ``None`` inserts
    an axis, one ``...`` expands, negative indices count from the end.

    Parameters
    ----------
    key : object
        Index key applied to an array of shape ``(3, 4)``.
    """

    array, real = _make((3, 4))
    result = array[key]

    assert result.shape == real[key].shape
    np.testing.assert_array_equal(_real(result), real[key])

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@PENDING
@pytest.mark.parametrize("seed", range(12))
def test_basic_indexing_random_keys_on_nd_arrays(seed):
    """
    Row 1: random basic keys (integers, slices with steps, ``None``, ``...``) on 1-D, 2-D and 3-D arrays
    give NumPy's shapes and values.

    Parameters
    ----------
    seed : int
        Seed of the random shape and key.
    """

    rng = np.random.default_rng(100 + seed)
    ndim = int(rng.integers(1, 4))
    shape = tuple(int(n) for n in rng.integers(2, 5, size=ndim))
    array, real = _make(shape, seed)
    items = []
    used = 0

    for _ in range(int(rng.integers(1, ndim + 2))):

        choice = int(rng.integers(0, 4))

        if choice == 0 or used >= ndim:

            items.append(None)

        elif choice == 1:

            items.append(int(rng.integers(-shape[used], shape[used])))
            used += 1

        else:

            start = int(rng.integers(-shape[used], shape[used]))
            step = int(rng.choice([-2, -1, 1, 2]))
            items.append(slice(start, None, step))
            used += 1

        # end if

    # end for

    key = tuple(items)
    result = array[key]

    assert result.shape == real[key].shape
    np.testing.assert_array_equal(_real(result), real[key])

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_integer_keys_give_scalars():
    """
    Row 1: one integer per axis gives an OTI scalar, never a 0-D array, and negative indices count from
    the end.
    """

    array, real = _make((3, 4))

    for key in ((1, 2), (-1, -1), (0, -4)):

        scalar = array[key]

        assert isinstance(scalar, dn.otinum)
        assert scalar.real == real[key]

    # end for

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@PENDING
def test_scalar_result_of_nd_array():
    """
    Row 1: one integer per axis of a 3-D array gives an OTI scalar with the right value.
    """

    array, real = _make((2, 3, 4))
    scalar = array[1, -1, 2]

    assert isinstance(scalar, dn.otinum)
    assert scalar.real == real[1, -1, 2]

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("key", [(3, 0), (0, 4), (-4, 0), 3, (0, 0, 0), (0, 0, None, 0)])
def test_index_errors(key):
    """
    Row 1: out-of-range integers and too many indices raise ``IndexError``.

    Parameters
    ----------
    key : object
        Invalid key for an array of shape ``(3, 4)``.
    """

    array, _ = _make((3, 4))

    with pytest.raises(IndexError):

        array[key]

    # end with

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("key", [1.5, "a", (0, "a"), (1.0, 0)])
def test_float_and_string_keys_raise(key):
    """
    Row 1: a float or string key raises ``IndexError`` or ``TypeError``.

    Parameters
    ----------
    key : object
        Invalid key for an array of shape ``(3, 4)``.
    """

    array, _ = _make((3, 4))

    with pytest.raises((IndexError, TypeError)):

        array[key]

    # end with

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@PENDING
def test_len_and_iteration():
    """
    Row 1: ``len(A) == A.shape[0]`` and ``iter(A)`` yields ``A[0], A[1], ...``: sub-arrays with one axis
    fewer, and OTI scalars for a 1-D array.
    """

    array, real = _make((3, 4))

    assert len(array) == 3

    rows = list(array)

    assert len(rows) == 3

    for i, row in enumerate(rows):

        assert row.shape == (4,)
        np.testing.assert_array_equal(_real(row), real[i])

    # end for

    vector, vreal = _make((5,))
    items = list(vector)

    assert len(vector) == 5
    assert all(isinstance(item, dn.otinum) for item in items)
    np.testing.assert_array_equal([item.real for item in items], vreal)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@PENDING
def test_zero_dimensional_len_and_iteration():
    """
    Row 1: ``len()`` and iteration of a 0-D array raise ``TypeError``.
    """

    zero_d = dn.array(2.5)

    with pytest.raises(TypeError):

        len(zero_d)

    # end with

    with pytest.raises(TypeError):

        iter(zero_d)

    # end with

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@PENDING
def test_object_array_has_the_shape_of_the_array():
    """
    Row 1: ``np.array(A, dtype=object)`` is an object array of shape ``A.shape`` holding OTI scalars.
    """

    array, real = _make((2, 3))
    objects = np.array(array, dtype=object)

    assert objects.shape == (2, 3)
    assert isinstance(objects[1, 2], dn.otinum)
    assert objects[1, 2].real == real[1, 2]

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("call, shape", [
    pytest.param(lambda: dn.zeros(4), (4,), id="zeros-int", marks=PENDING),
    pytest.param(lambda: dn.zeros((4,)), (4,), id="zeros-1-tuple", marks=PENDING),
    pytest.param(lambda: dn.ones(4), (4,), id="ones-int", marks=PENDING),
    pytest.param(lambda: dn.array(np.arange(1.0, 5.0)), (4,), id="array-1d", marks=PENDING),
    pytest.param(lambda: dn.array([1.0, 2.0, 3.0]), (3,), id="array-list", marks=PENDING),
    pytest.param(lambda: dn.array(2.5), (), id="array-scalar", marks=PENDING),
    pytest.param(lambda: dn.zeros(()), (), id="zeros-0d", marks=PENDING),
    pytest.param(lambda: dn.array([[1.0], [2.0]]), (2, 1), id="array-column"),
    pytest.param(lambda: dn.zeros((2, 3)), (2, 3), id="zeros-2d"),
    pytest.param(lambda: dn.eye(3), (3, 3), id="eye"),
    pytest.param(lambda: dn.zeros((2, 3, 4)), (2, 3, 4), id="zeros-3d", marks=PENDING),
])


def test_creators_return_numpy_shapes(call, shape):
    """
    Row 2: creators follow NumPy: an int or 1-tuple gives a 1-D array, 1-D input gives a 1-D array, a
    scalar gives a 0-D array, nested lists keep their depth.

    Parameters
    ----------
    call : callable
        Creator call.
    shape : tuple of int
        Expected shape.
    """

    assert call().shape == shape

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@PENDING
def test_one_dimensional_creator_indexes_with_one_integer():
    """
    Row 2: an array created from 1-D data is indexed with one integer; ``x[2, 0]`` raises
    ``IndexError``, loudly and never silently.
    """

    x = dn.array(np.arange(1.0, 5.0))

    assert x[2].real == 3.0

    with pytest.raises(IndexError):

        x[2, 0]

    # end with

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@PENDING
def test_zero_dimensional_array_values():
    """
    Row 2: ``array(2.5)`` is 0-D: ``shape == ()``, ``size == 1``, and it holds the value.
    """

    zero_d = dn.array(2.5)

    assert zero_d.shape == ()
    assert zero_d.size == 1
    assert _real(zero_d) == 2.5

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_nrows_ncols_keep_their_values_for_low_dimensions():
    """
    Row 10: ``nrows`` / ``ncols`` keep their 1.x values for ndim <= 2 (1-D: ``nrows = n, ncols = 1``;
    0-D: ``1, 1``); they are deprecated, so a ``DeprecationWarning`` is allowed.
    """

    with warnings.catch_warnings():

        warnings.simplefilter("ignore", DeprecationWarning)

        vector = dn.array(np.arange(1.0, 5.0))
        zero_d = dn.array(2.5)
        matrix = dn.zeros((2, 3))

        assert (vector.nrows, vector.ncols) == (4, 1)
        assert (zero_d.nrows, zero_d.ncols) == (1, 1)
        assert (matrix.nrows, matrix.ncols) == (2, 3)

    # end with

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@PENDING
def test_nrows_ncols_raise_for_nd_arrays():
    """
    Row 10: ``nrows`` / ``ncols`` raise ``AttributeError`` for ndim > 2; use ``shape``.
    """

    cube = dn.zeros((2, 3, 4))

    with warnings.catch_warnings():

        warnings.simplefilter("ignore", DeprecationWarning)

        with pytest.raises(AttributeError):

            cube.nrows

        # end with

        with pytest.raises(AttributeError):

            cube.ncols

        # end with

    # end with

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@PENDING
def test_column_into_one_dimensional_target_raises():
    """
    Row 3: assignment broadcasts as NumPy does: an ``(n, 1)`` column no longer fits an ``(n,)`` target.
    """

    array, _ = _make((3, 4))
    column, _ = _make((3, 1), seed=5)

    with pytest.raises(ValueError):

        array[:, 3] = column

    # end with

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_column_assignment_through_a_column_slice_or_a_vector():
    """
    Row 3: ``A[:, 3:4] = column`` and ``A[:, 3] = column[:, 0]`` give NumPy's result.
    """

    array, real = _make((3, 4))
    column, creal = _make((3, 1), seed=5)
    other, oreal = _make((3, 4))
    other_real = oreal.copy()

    array[:, 3:4] = column
    real[:, 3:4] = creal

    np.testing.assert_array_equal(_real(array), real)

    other[:, 3] = column[:, 0]
    other_real[:, 3] = creal[:, 0]

    np.testing.assert_array_equal(_real(other), other_real)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_row_assignment_into_a_one_dimensional_target():
    """
    Row 3: a ``(1, n)`` row fits an ``(n,)`` target (leading axes of extent 1 are dropped), the FEM
    assembly pattern ``strain[0, 0:2*nb:2] = nx``.
    """

    array = dn.zeros((3, 8))
    row, rreal = _make((1, 4))
    reference = np.zeros((3, 8))

    array[0, 0:8:2] = row
    reference[0, 0:8:2] = rreal

    np.testing.assert_array_equal(_real(array), reference)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@PENDING
@pytest.mark.parametrize("seed", range(10))
def test_assignment_broadcasts_like_numpy(seed):
    """
    Row 3: ``A[key] = value`` with random keys and values of random compatible shapes either gives
    NumPy's result or raises ``ValueError`` exactly where NumPy does.

    Parameters
    ----------
    seed : int
        Seed of the random key and value shape.
    """

    rng = np.random.default_rng(200 + seed)
    array, real = _make((4, 5), seed)
    key = (int(rng.integers(0, 4)), slice(int(rng.integers(0, 2)), None, int(rng.integers(1, 3))))
    target = real[key].shape

    for vshape in (target, (1,) + target, (1,), (), (target[0], 1), (2,) + target):

        value, vreal = _make(vshape, seed + 7) if vshape != () else (dn.array(1.5), np.array(1.5))
        reference = real.copy()

        try:

            reference[key] = vreal
            numpy_ok = True

        except ValueError:

            numpy_ok = False

        # end try

        if numpy_ok:

            array[key] = value
            np.testing.assert_array_equal(_real(array), reference)

        else:

            with pytest.raises(ValueError):

                array[key] = value

            # end with

        # end if

    # end for

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@PENDING
@pytest.mark.parametrize("operation", ["shift", "reverse"])
def test_assignment_from_an_overlapping_view_is_a_snapshot(operation):
    """
    Row 3 / S2: ``a[1:] = a[:-1]`` and ``a[::-1] = a`` behave as if the right side were copied first.

    Parameters
    ----------
    operation : str
        ``"shift"`` or ``"reverse"``.
    """

    array, real = _make((6,))

    if operation == "shift":

        array[1:] = array[:-1]
        real[1:] = real[:-1].copy()

    else:

        array[::-1] = array
        real[::-1] = real.copy()

    # end if

    np.testing.assert_array_equal(_real(array), real)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@PENDING
def test_basic_slices_are_views():
    """
    Row 4: in ``pyoti.dense`` (``omat``) basic slices are views: a write through the slice reaches the
    parent, and a write into the parent shows in the slice.
    """

    array, real = _make((3, 4))
    row = array[0]

    row[0] = 42.0
    real[0, 0] = 42.0

    assert array[0, 0].real == 42.0
    np.testing.assert_array_equal(_real(array), real)

    array[0, 1] = 7.0

    assert row[1].real == 7.0

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@PENDING
def test_views_of_views_reach_the_root():
    """
    Row 4: a slice of a slice is still a view of the root.
    """

    array, real = _make((4, 5))
    inner = array[1:4, ::2][1:, 1:]

    inner[:, :] = 3.5
    real[1:4, ::2][1:, 1:] = 3.5

    np.testing.assert_array_equal(_real(array), real)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@PENDING
def test_transpose_is_a_view():
    """
    Row 4: ``.T`` and ``transpose()`` of a 2-D array are views, and ``.T`` of a 1-D array returns it
    unchanged.
    """

    array, real = _make((3, 4))
    transposed = array.T

    assert transposed.shape == (4, 3)

    transposed[1, 2] = 9.0
    real.T[1, 2] = 9.0

    np.testing.assert_array_equal(_real(array), real)

    vector, _ = _make((4,))

    assert vector.T.shape == (4,)
    assert dn.transpose(vector).shape == (4,)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@PENDING
def test_reshape_is_a_view_when_possible():
    """
    Row 4: ``reshape`` of a compact array is a view; the values follow NumPy's reshape.
    """

    array, real = _make((3, 4), order=1)
    reshaped = array.reshape((2, 6))

    assert reshaped.shape == (2, 6)
    np.testing.assert_array_equal(_real(reshaped), real.reshape(2, 6))

    reshaped[0, 0] = -1.0

    assert array[0, 0].real == -1.0

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@PENDING
def test_chained_assignment_writes_into_the_root():
    """
    Row 4 / S3: ``A[1:3][0] = v`` writes into ``A`` when the first subscript returns a view.
    """

    array, real = _make((4, 3))

    array[1:3][0] = 5.0
    real[1:3][0] = 5.0

    np.testing.assert_array_equal(_real(array), real)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_aos_slices_are_copies():
    """
    Row 4: slices of an ``arro`` (AoS) are copies: a write through the slice does not reach the parent.
    """

    array = dn.array(np.arange(12.0).reshape(3, 4)).to_aos()
    row = array[0]

    row[0] = 42.0

    assert array[0, 0].real == 0.0

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_derived_arrays_are_copies():
    """
    Row 4: ``get_im``, ``get_deriv`` and ``copy`` return independent copies.
    """

    array, _ = _make((3, 4))
    copy = array.copy()
    derivative = array.get_deriv([1])

    copy[0, 0] = 99.0
    derivative[0, 0] = 99.0

    assert array[0, 0].real != 99.0
    assert array.get_deriv([1])[0, 0].real != 99.0

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@PENDING
def test_real_export_is_read_only():
    """
    Row 5: ``.real`` is a read-only view in every shape, including the singleton shapes that were
    writable before; writing raises ``ValueError``.
    """

    for shape in ((3, 4), (3, 1), (1, 4), (1, 1), (5,)):

        array, real = _make(shape)
        view = array.real

        assert not view.flags.writeable

        with pytest.raises(ValueError, match="read-only"):

            view[(0,) * len(shape)] = 1.0

        # end with

        np.testing.assert_array_equal(view, real)

    # end for

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@PENDING
def test_real_export_shares_memory_and_copy_is_independent():
    """
    Row 5: ``.real`` shares memory with the array (no copy); ``.real.copy()`` is writable and
    independent.
    """

    array, _ = _make((3, 4))
    view = array.real
    snapshot = view.copy()

    assert np.shares_memory(view, array.real)
    assert snapshot.flags.writeable

    snapshot[0, 0] = 123.0

    assert array[0, 0].real != 123.0

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@PENDING
def test_get_block_is_read_only_unless_writeable():
    """
    Row 5: ``get_block(d)`` is a read-only view by default and ``get_block(d, writeable=True)`` is a
    writable view that reaches the array; ``np.shares_memory`` holds.
    """

    array, real = _make((3, 4))
    block = array.get_block(0)

    assert not block.flags.writeable

    with pytest.raises(ValueError):

        block[0, 0] = 1.0

    # end with

    del block

    writable = array.get_block(0, writeable=True)

    assert writable.flags.writeable

    writable[0, 0] = 5.0

    assert array[0, 0].real == 5.0

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@PENDING
def test_get_block_for_an_imaginary_direction_writeable_raises_the_order():
    """
    Row 5: ``get_block(d, writeable=True)`` for ``d != 0`` makes the block exist (the active order rises
    to the truncation order) and the write reaches the array.
    """

    array = dn.zeros((2, 3), nbases=2, order=2)
    block = array.get_block((1,), writeable=True)

    block[1, 2] = 4.0

    assert array.get_deriv([1])[1, 2].real == 4.0

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@PENDING
def test_csr_real_is_read_only_and_get_real_writeable_reaches_the_matrix():
    """
    Row 5: ``csr_matrix.real`` is read-only (``data`` cannot be written); ``get_real(writeable=True)``
    returns a SciPy CSR whose ``data`` is the writable real block.
    """

    matrix = dn.csr_matrix(scs.csr_matrix(np.array([[1.0, 0.0], [0.0, 2.0]])))
    real = matrix.real

    assert not real.data.flags.writeable

    with pytest.raises(ValueError, match="read-only"):

        real.data[0] = 5.0

    # end with

    writable = matrix.get_real(writeable=True)
    writable.data[0] = 5.0

    assert matrix.real.data[0] == 5.0

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("data, indices, indptr", [
    pytest.param([1.0, 2.0, 3.0], [0, 1, 1], [0, 2, 3], id="sorted"),
    pytest.param([1.0, 2.0, 3.0], [1, 0, 1], [0, 2, 3], id="unsorted"),
    pytest.param([1.0, 2.0, 3.0], [0, 0, 1], [0, 2, 3], id="duplicates", marks=PENDING),
])


def test_csr_real_canonical_flags_are_truthful(data, indices, indptr):
    """
    Row 5: the SciPy matrix of ``csr_matrix.real`` computes ``has_sorted_indices`` and
    ``has_canonical_format`` from the pattern: a pattern with unsorted indices or duplicates never
    claims them.

    Parameters
    ----------
    data : list of float
        Values of the CSR matrix.
    indices : list of int
        Column indices.
    indptr : list of int
        Row pointers.
    """

    raw = scs.csr_matrix((np.array(data), np.array(indices), np.array(indptr)), shape=(2, 2))
    raw.has_sorted_indices = True
    raw.has_canonical_format = True
    real = dn.csr_matrix(raw).real
    rows = [real.indices[real.indptr[i]:real.indptr[i + 1]] for i in range(2)]
    sorted_rows = all(bool(np.all(np.diff(row) > 0)) for row in rows)

    assert real.has_sorted_indices == sorted_rows
    assert real.has_canonical_format == sorted_rows

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_root_growth_without_views():
    """
    Row 6 / G1: writing into a root with any key grows it (truncation order and bases rise to the
    value's) while no view or export is alive.
    """

    array = dn.zeros((2, 2))
    array[0:2, 0:2] = dn.e(5, order=2)

    assert array.order == 2
    assert 5 in array.active_bases

    other = dn.zeros((2, 2))
    other[1, 1] = dn.e(3, order=3)

    assert other.order == 3
    assert 3 in other.active_bases

    third = dn.zeros((2, 2))
    third.set(dn.e(2, order=1))

    assert third.order == 1

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("source", [
    pytest.param("row", id="row", marks=PENDING),
    pytest.param("transpose", id="transpose", marks=PENDING),
    pytest.param("real", id="real", marks=PENDING),
    pytest.param("block", id="get-block"),
    pytest.param("slice", id="slice", marks=PENDING),
])


def test_growth_with_a_live_view_or_export_raises_buffererror(source):
    """
    Row 6 / G1, G2: growing a root while a view (``A[i]``, ``.T``, a slice) or an export (``.real``,
    ``get_block``) is alive raises ``BufferError`` with the phrase ``live block views``; after the view
    is dropped the array grows again.

    Parameters
    ----------
    source : str
        Kind of live view or export.
    """

    array = dn.zeros((3, 3))
    array[0, 0] = dn.e(1, order=1)
    held = {"row": lambda: array[0], "transpose": lambda: array.T, "real": lambda: array.real,
            "block": lambda: array.get_block(0), "slice": lambda: array[1:, 1:]}[source]()

    with pytest.raises(BufferError, match=LIVE):

        array[1, 1] = dn.e(7, order=3)

    # end with

    del held

    array[1, 1] = dn.e(7, order=3)

    assert array.order == 3

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@PENDING
def test_growth_message_names_the_remedy():
    """
    Row 6 / G2: the refusal says how to size the array first (``reserve`` / ``nbases=`` / ``bases=`` /
    ``order=``).
    """

    array = dn.zeros((2, 2))
    view = array[0]

    with pytest.raises(BufferError) as raised:

        array[1, 1] = dn.e(2, order=2)

    # end with

    message = str(raised.value)

    assert LIVE in message
    assert "reserve" in message
    assert view.shape == (2,)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@PENDING
def test_write_through_a_view_that_fits_reaches_the_root_and_never_grows():
    """
    Row 6 / G1: writing through a view object never changes the layout: a value that fits is written to
    the root, a value outside the shared layout raises ``BufferError`` and nothing is clipped.
    """

    array = dn.zeros((2, 2))
    array[0, 0] = dn.e(1, order=2)
    view = array[1]

    view[0] = dn.e(1, order=1)

    assert array.get_deriv([1])[1, 0].real == 1.0

    with pytest.raises(BufferError):

        view[1] = dn.e(2, order=1)

    # end with

    with pytest.raises(BufferError):

        view[1] = dn.e(1, order=3)

    # end with

    assert array.order == 2
    assert array.active_bases == (1,)
    assert array[1, 1].real == 0.0

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@PENDING
def test_reserve_sizes_the_layout_up_front():
    """
    Row 6 / G4: ``reserve(nbases=, order=)`` grows the layout immediately; afterwards assembly through
    live views never grows the array and never raises.
    """

    array = dn.zeros((2, 3))

    array.reserve(nbases=3, order=2)

    assert array.active_bases == (1, 2, 3)
    assert array.order == 2

    view = array[0]
    array[1, 1] = dn.e(3, order=2)

    assert view.shape == (3,)
    assert array.get_deriv([3])[1, 1].real == 1.0

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@PENDING
def test_reserve_with_live_views_raises():
    """
    Row 6 / G4: ``reserve`` grows the layout, so it raises ``BufferError`` with a live view.
    """

    array = dn.zeros((2, 3))
    view = array[0]

    with pytest.raises(BufferError, match=LIVE):

        array.reserve(nbases=3, order=2)

    # end with

    assert view.shape == (3,)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@PENDING
def test_set_methods_follow_the_growth_rule():
    """
    Row 6 / G1: ``set_im`` and ``set_deriv`` grow an unshared root and raise ``BufferError`` with a live
    view.
    """

    array = dn.zeros((2, 2))

    array.set_deriv(dn.array(np.ones((2, 2))), [1])

    assert array.active_bases == (1,)

    view = array[0]

    with pytest.raises(BufferError, match=LIVE):

        array.set_deriv(dn.array(np.ones((2, 2))), [2])

    # end with

    assert view.shape == (2,)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@PENDING
@pytest.mark.parametrize("order", [1, 2, 3])
def test_nbases_reserves_the_layout(order):
    """
    Row 7 / A1: a dense array created with ``nbases=K``, ``K > 0``, has ``nact = K`` and reports
    ``active_bases == (1, ..., K)``.

    Parameters
    ----------
    order : int
        Truncation order.
    """

    assert dn.zeros((2, 3), nbases=4, order=order).active_bases == (1, 2, 3, 4)
    assert dn.ones((2, 3), nbases=2, order=order).active_bases == (1, 2)
    assert dn.eye(3, nbases=3, order=order).active_bases == (1, 2, 3)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("order", [0, 1, 2])
def test_nbases_zero_reserves_nothing(order):
    """
    Row 7: ``nbases=0`` (the default) means no reservation, as in 1.x.

    Parameters
    ----------
    order : int
        Truncation order.
    """

    assert dn.zeros((2, 3), order=order).active_bases == ()
    assert dn.zeros((2, 3), nbases=0, order=order).active_bases == ()

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_nbases_reservation_keeps_views_stable():
    """
    Row 7: an array created with ``nbases=`` and ``order=`` takes assignments inside the reserved layout
    while views are alive.
    """

    array = dn.zeros((3, 3), nbases=3, order=2)
    view = array[1:, 1:]

    array[0, 0] = dn.e(3, order=2)

    assert array.get_deriv([3])[0, 0].real == 1.0
    assert view.shape == (2, 2)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@PENDING
def test_nbases_too_large_for_the_budget_raises_memoryerror():
    """
    Row 7: a hint too large for the memory budget fails with ``MemoryError`` before allocating.
    """

    with pytest.raises(MemoryError):

        dn.zeros((1000, 1000), nbases=200000, order=3)

    # end with

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_scalar_creators_ignore_nbases():
    """
    Row 7: scalar creators with ``nbases=`` are unchanged (scalars have no views).
    """

    assert dn.e(1, nbases=5, order=1).nact == 1
    assert dn.number(2.0, nbases=5, order=1).active_bases == ()

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@PENDING
def test_elm_help_allocate_sizes_every_field():
    """
    Row 7: ``elm_help.allocate(ndim, nbasis, nip, nbases=K, order=P)`` creates every helper field with
    the layout ``nact = K`` and truncation order ``P`` (the fields never grow during assembly).
    """

    fem.set_global_algebra(dn)

    try:

        helper = dn.elm_help()
        helper.allocate(2, 4, 3, nbases=3, order=2)

        for name in ("N", "Nxi", "Neta", "w", "xi", "eta"):

            field = getattr(helper, name)

            assert field.active_bases == (1, 2, 3), name
            assert field.order == 2, name

        # end for

    finally:

        fem.set_global_algebra(sp)

    # end try

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@PENDING
def test_dot_of_one_dimensional_arrays():
    """
    Row 8: ``dot(x, y)`` of 1-D arrays is the inner product, an OTI scalar; ``x @ y`` and
    ``matmul(x, y)`` give the same scalar.
    """

    x, xreal = _make((4,), 1)
    y, yreal = _make((4,), 2)

    for scalar in (dn.dot(x, y), x @ y, dn.matmul(x, y)):

        assert isinstance(scalar, dn.otinum)
        assert scalar.real == pytest.approx(xreal @ yreal)

    # end for

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@PENDING
def test_matrix_vector_products_drop_the_vector_axis():
    """
    Row 8: ``dot(A, x)`` and ``A @ x`` are ``(m,)``, ``dot(x, A)`` and ``x @ A`` are ``(n,)``
    (``numpy.matmul`` promotion).
    """

    matrix, mreal = _make((3, 4), 1)
    x, xreal = _make((4,), 2)
    z, zreal = _make((3,), 3)

    for result in (dn.dot(matrix, x), matrix @ x, dn.matmul(matrix, x)):

        assert result.shape == (3,)
        np.testing.assert_allclose(_real(result), mreal @ xreal)

    # end for

    for result in (dn.dot(z, matrix), z @ matrix, dn.matmul(z, matrix)):

        assert result.shape == (4,)
        np.testing.assert_allclose(_real(result), zreal @ mreal)

    # end for

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_column_idiom_still_works():
    """
    Row 8: the 1.x idiom ``dot(x.T, y)`` on ``(n, 1)`` columns still works and gives ``(1, 1)``.
    """

    x, xreal = _make((4, 1), 1)
    y, yreal = _make((4, 1), 2)
    result = dn.dot(x.T, y)

    assert result.shape == (1, 1)
    assert _real(result)[0, 0] == pytest.approx((xreal.T @ yreal)[0, 0])

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_dot_product_pairs_the_flattened_entries():
    """
    Row 8 / k6: ``dot_product(a, b)`` pairs the flattened entries in row-major order and returns an OTI
    scalar (unchanged).
    """

    a, areal = _make((3, 2), 1)
    b, breal = _make((3, 2), 2)
    scalar = dn.dot_product(a, b)

    assert isinstance(scalar, dn.otinum)
    assert scalar.real == pytest.approx(float(np.sum(areal * breal)))

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("lshape, rshape, expected", [
    pytest.param((4,), (4, 3), (3,), id="row-by-matrix", marks=PENDING),
    pytest.param((3, 4), (4,), (3,), id="matrix-by-column", marks=PENDING),
    pytest.param((3, 4), (4, 2), (3, 2), id="matrix-by-matrix"),
])


def test_trunc_dot_is_a_truncated_matrix_product(lshape, rshape, expected):
    """
    Row 8 / k6: ``trunc_dot`` contracts the last axis of the left operand with the first of the right
    one, with ``numpy.dot``'s shape rules for 1-D operands.

    Parameters
    ----------
    lshape : tuple of int
        Shape of the left operand.
    rshape : tuple of int
        Shape of the right operand.
    expected : tuple of int
        Shape of the result.
    """

    lhs, lreal = _make(lshape, 1, order=1)
    rhs, rreal = _make(rshape, 2, order=1)
    result = dn.trunc_dot(0, lhs, 0, rhs)

    assert result.shape == expected
    np.testing.assert_allclose(_real(result), lreal @ rreal)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@PENDING
def test_solve_with_a_one_dimensional_right_hand_side():
    """
    Row 8 / k14: ``solve(A, b)`` with ``A (n, n)`` and ``b (n,)`` gives ``(n,)``; with ``b (n, k)`` it
    gives ``(n, k)``.
    """

    rng = np.random.default_rng(4)
    areal = rng.standard_normal((3, 3)) + 3.0 * np.eye(3)
    matrix = dn.array(areal)
    vector, vreal = _make((3,), 5)
    block, breal = _make((3, 2), 6)
    solution = dn.solve(matrix, vector)
    solutions = dn.solve(matrix, block)

    assert solution.shape == (3,)
    np.testing.assert_allclose(_real(solution), np.linalg.solve(areal, vreal))
    assert solutions.shape == (3, 2)
    np.testing.assert_allclose(_real(solutions), np.linalg.solve(areal, breal))

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@PENDING
def test_solve_batched_matrices_with_a_vector():
    """
    Row 8 / k14: three ``2 x 2`` matrices with ``b.shape == (2,)`` give ``(3, 2)`` (NumPy 2's
    ``linalg.solve`` rule).
    """

    rng = np.random.default_rng(8)
    areal = rng.standard_normal((3, 2, 2)) + 3.0 * np.eye(2)
    breal = rng.standard_normal(2)
    solution = dn.solve(dn.array(areal), dn.array(breal))

    assert solution.shape == (3, 2)
    expected = np.linalg.solve(areal, np.broadcast_to(breal, (3, 2))[..., None])[..., 0]

    np.testing.assert_allclose(_real(solution), expected)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@PENDING
def test_csr_products_and_solves_follow_the_shape_of_b():
    """
    Row 8 / k14: ``csr @ b`` is ``(m,)`` for ``b (n,)`` and ``(m, k)`` for ``b (n, k)``;
    ``solve(csr, b)`` has the shape of ``b``.
    """

    rng = np.random.default_rng(9)
    real = scs.csr_matrix(rng.standard_normal((3, 3)) + 4.0 * np.eye(3))
    matrix = dn.csr_matrix(real)
    vector, vreal = _make((3,), 1)
    block, breal = _make((3, 2), 2)

    assert (matrix @ vector).shape == (3,)
    assert (matrix @ block).shape == (3, 2)
    assert dn.solve(matrix, vector).shape == (3,)
    assert dn.solve(matrix, block).shape == (3, 2)
    np.testing.assert_allclose(_real(matrix @ vector), real @ vreal)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@PENDING
@pytest.mark.parametrize("shape", [(), (4,), (2, 3), (2, 3, 4)])
def test_saved_files_are_version_2_and_round_trip(tmp_path, shape):
    """
    Row 9 / 11.12: ``save`` writes version 2 and the file reads back with the same shape (0-D, 1-D, 2-D
    and n-D), layout and coefficients.

    Parameters
    ----------
    tmp_path : pathlib.Path
        Temporary directory.
    shape : tuple of int
        Shape of the array.
    """

    array, _ = _make(shape, 3)
    path = tmp_path / "file.otd"

    dn.save(array, path)

    data = path.read_bytes()

    assert int.from_bytes(data[4:6], "little") == 2

    back = dn.read(path)

    assert back.shape == shape
    _same_state(back, array)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_v1_files_read_with_their_stored_two_dimensional_shape(tmp_path):
    """
    Row 9 / 11.12: 2.0 reads the files of 1.x: a ``(2, 3)`` file gives ``(2, 3)`` and a ``(4, 1)``
    column file gives ``(4, 1)``, never guessed as ``(4,)``.

    Parameters
    ----------
    tmp_path : pathlib.Path
        Temporary directory.
    """

    for data, shape, order in ((V1_2X3_O2, (2, 3), 2), (V1_4X1_O1, (4, 1), 1)):

        path = tmp_path / "v1.otd"
        path.write_bytes(data)

        array = dn.read(path)

        assert int.from_bytes(data[4:6], "little") == 1
        assert array.shape == shape
        assert array.order == order

    # end for

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@PENDING
def test_v1_files_are_rewritten_as_version_2(tmp_path):
    """
    Row 9 / 11.12: saving an array read from a version-1 file writes version 2, and the file reads back
    equal.

    Parameters
    ----------
    tmp_path : pathlib.Path
        Temporary directory.
    """

    for data in (V1_2X3_O2, V1_4X1_O1):

        path = tmp_path / "v1.otd"
        path.write_bytes(data)

        array = dn.read(path)
        again = tmp_path / "v2.otd"

        dn.save(array, again)

        assert int.from_bytes(again.read_bytes()[4:6], "little") == 2

        _same_state(dn.read(again), array)

    # end for

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_v1_fixture_values(tmp_path):
    """
    Row 9 / 11.12: the version-1 fixtures hold the values they were written from.

    Parameters
    ----------
    tmp_path : pathlib.Path
        Temporary directory.
    """

    path = tmp_path / "v1.otd"
    path.write_bytes(V1_4X1_O1)

    column = dn.read(path)
    expected = dn.array(np.array([[1.0], [2.0], [3.0], [4.0]])) + dn.e(1, order=1) * dn.array(
        np.array([[0.5], [0.25], [2.0], [1.0]]))

    _same_state(column, expected)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@PENDING
def test_layout_keyword_selects_c_or_f():
    """
    Row 12: the creators accept ``layout=`` (``'C'`` / ``'F'``); the values do not depend on it.
    """

    for layout in ("C", "F"):

        array = dn.zeros((2, 3), layout=layout)

        assert array.shape == (2, 3)

    # end for

    data = np.arange(6.0).reshape(2, 3)

    for layout in ("C", "F"):

        np.testing.assert_array_equal(_real(dn.array(data, layout=layout)), data)

    # end for

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_static_arrays_keep_matrix_indexing():
    """
    Row 11 / A3: static array classes are provisional and keep the 1.x matrix indexing and copies:
    ``A[i]`` is a ``(1, ncols)`` matrix and ``A[:, j]`` an ``(nrows, 1)`` matrix. (No marker: this is
    behaviour that does not change in 2.0.0.)
    """

    import pyoti.static.onumm1n2 as static

    array = static.zeros((2, 3))

    assert array[0].shape == (1, 3)
    assert array[:, 1].shape == (2, 1)
    assert isinstance(array[1, 2], static.onumm1n2)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_gauss_arrays_keep_the_matrix_rule():
    """
    Row 1 / 11.8 (A5): Gauss arrays keep the matrix rule: ``G[i]`` is ``(1, ncols)``, ``G[:, j]`` is
    ``(nrows, 1)``, ``G[i, j]`` is a Gauss scalar, negative indices work, a 3-index key raises
    ``IndexError`` and ``get_ip`` returns a plain ``(nrows, ncols)`` copy.
    """

    gauss = dn.omatfe((2, 3), nip=4, bases=[1, 2], order=1)

    assert gauss[0].shape == (1, 3)
    assert gauss[1, :].shape == (1, 3)
    assert gauss[:, 2].shape == (2, 1)
    assert gauss[0:1, 1:3].shape == (1, 2)
    assert isinstance(gauss[-1, -1], dn.otife)

    with pytest.raises(IndexError):

        gauss[(0, 0, 0)]

    # end with

    point = gauss.get_ip(0)

    assert point.shape == (2, 3)

    point[0, 0] = 9.0

    assert gauss.get_ip(0)[0, 0].real != 9.0

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@PENDING
def test_gauss_real_is_a_read_only_view():
    """
    Row 5 / 11.8: ``G.real`` of a dense Gauss array is a read-only ``(nip, nrows, ncols)`` view.
    """

    gauss = dn.omatfe((2, 3), nip=4, bases=[1, 2], order=1)
    real = gauss.real

    assert real.shape == (4, 2, 3)
    assert not real.flags.writeable

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_gauss_set_ip_broadcasts_by_the_assignment_rule():
    """
    11.8 / S1: ``G.set_ip(ip, value)`` assigns the point's matrix; the value broadcasts to
    ``(nrows, ncols)``.
    """

    gauss = dn.omatfe((2, 3), nip=4, bases=[1], order=1)

    gauss.set_ip(2, dn.array(np.ones((2, 3))))

    np.testing.assert_array_equal(_real(gauss.get_ip(2)), np.ones((2, 3)))
    np.testing.assert_array_equal(_real(gauss.get_ip(1)), np.zeros((2, 3)))

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("shape", [(4,), (4, 1)])
def test_fem_helper_accepts_vectors_and_columns(shape):
    """
    11.2: ``elm_help.set_coordinates`` and ``get_local`` accept ``(n,)`` and ``(n, 1)`` nodal inputs
    alike; the helper's own vectors stay ``(nbasis, 1)`` columns.

    Parameters
    ----------
    shape : tuple of int
        Shape of the global nodal arrays.
    """

    fem.set_global_algebra(dn)

    try:

        helper = dn.elm_help()
        helper.allocate(2, 4, 1, nbases=0, order=0)
        helper.allocate_spatial(2)

        values = np.array([4.0, 5.0, 6.0, 7.0, 8.0, 9.0])
        x = dn.array(values.reshape((6,) + shape[1:]))
        indices = np.array([5, 1, 3, 0])

        helper.set_coordinates(x, x, x, indices)

        assert helper.x.shape == (4, 1)
        np.testing.assert_array_equal(_real(helper.x).reshape(-1), values[indices])

        local = helper.get_local(x, indices)

        assert local.shape == (4, 1)
        np.testing.assert_array_equal(_real(local).reshape(-1), values[indices])

    finally:

        fem.set_global_algebra(sp)

    # end try

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@PENDING
def test_empty_tuple_key_of_a_zero_dimensional_array_gives_a_scalar():
    """
    Row 1: ``A[()]`` of a 0-D array is an OTI scalar.
    """

    scalar = dn.array(2.5)[()]

    assert isinstance(scalar, dn.otinum)
    assert scalar.real == 2.5

# end function
# --------------------------------------------------------------------------------------------------------
