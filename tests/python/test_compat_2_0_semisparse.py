"""
The 2.0.0 compatibility suite of ``pyoti.semisparse`` (``oarrss`` SoA and ``arrss`` AoS; contracts
section 11, list 11.14).

Every test asserts the 2.0.0 behaviour (the "after" column of the contracts). Tests whose behaviour
lands with Phase 7b carry ``@pytest.mark.xfail(strict=True, reason="2.0.0 behaviour, Phase 7b")``: the
suite passes today, and a test that starts to pass (XPASS) fails loudly, which is the signal to remove
its marker. Behaviour that is already 2.0.0 carries no marker. ``Row n`` in the docstrings refers to
the numbered items of the breaking-changes list (11.14).

Semi-sparse arrays keep a 2-D C struct until Phase 8: the logical ndim is at most 2 and slices are
copies in 7b (``oarrss`` slices become views in Phase 8, A2; the tests that pin the copy behaviour say
so and change then).
"""

import os
import subprocess
import sys

import numpy as np
import pytest
import scipy.sparse as scs

import pyoti.fem as fem
import pyoti.semisparse as ss
import pyoti.sparse as sp

PENDING = pytest.mark.xfail(strict=True, reason="2.0.0 behaviour, Phase 7b")

# Files written by the last 1.x writer (version 1): an order-2 array of shape (2, 3) with two bases and
# a (4, 1) column with one base.
V1_SS_2X3_O2 = bytes.fromhex(
    "934f54530100030108020201020000000200000000000000030000000000000028010000000000000000000000000000"
    "00000000000000000000000000000000010002000000000000000000000000000000000000001040000000000000f03f"
    "00000000000014400000000000000040000000000000184000000000000000000000000000000040000000000000e03f"
    "0000000000000440000000000000f03f0000000000000840000000000000f03f000000000000f03f000000000000f03f"
    "000000000000f03f000000000000f03f000000000000f03f000000000000000000000000000000000000000000000000"
    "000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000"
    "000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000"
    "000000000000000000000000000000000000000000000000"
)
V1_SS_4X1_O1 = bytes.fromhex(
    "934f54530100030108020101010000000400000000000000010000000000000048000000000000000000000000000000"
    "000000000000000000000000000000000100000000000000000000000000f03f00000000000000400000000000000840"
    "0000000000001040000000000000e03f000000000000d03f0000000000000040000000000000f03f"
)


# ********************************************************************************************************
def _real(obj):
    """
    Copy the real part of an array or scalar into a NumPy array.

    Parameters
    ----------
    obj : oarrss or ssotinum
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
    Build a semi-sparse array with random real data and one imaginary direction.

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
    oarrss, numpy.ndarray
        The array and its real part.
    """

    rng = np.random.default_rng(seed)
    real = rng.standard_normal(shape)
    other = rng.standard_normal(shape)

    return ss.array(real) + ss.e(1, order=order) * ss.array(other), real

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _same_state(first, second):
    """
    Assert that two sparse arrays have the same shape, order and coefficients.

    Parameters
    ----------
    first : oarrss
        First array.
    second : oarrss
        Second array.
    """

    assert first.shape == second.shape
    assert first.order == second.order
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
    pytest.param((-2, slice(None)), id="negative-int-colon", marks=PENDING),
    pytest.param((Ellipsis, 0), id="ellipsis-int", marks=PENDING),
    pytest.param((slice(1, 2), slice(None)), id="row-slice"),
    pytest.param((slice(None), slice(2, 3)), id="column-slice"),
    pytest.param((slice(None, None, -1), slice(0, 4, 2)), id="reversed-strided"),
]


# ********************************************************************************************************
def _isolated(code):
    """
    Run a snippet in a fresh interpreter with the same import path.

    Behaviour that terminates the 1.x interpreter (``A[-1]`` of a sparse array calls ``exit``) cannot
    be asserted in-process, so negative-key checks run in a subprocess for semi-sparse arrays as well.

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
@PENDING
@pytest.mark.parametrize("key", ["-1", "(slice(None), -1)", "(-2, slice(None))", "(Ellipsis, -1)",
                                 "(-1, slice(None, None, -2))"])


def test_negative_integer_keys_match_numpy(key):
    """
    Row 1: negative integer keys count from the end in every algebra. (Run in a subprocess: the 1.x
    interpreter is probed the same way as ``pyoti.sparse``.)

    Parameters
    ----------
    key : str
        Source text of the key applied to an array of shape ``(3, 4)``.
    """

    code = (
        "import numpy as np, pyoti.semisparse as ss\n"
        "real = np.arange(12.0).reshape(3, 4)\n"
        "result = ss.array(real)[%s]\n"
        "assert result.shape == real[%s].shape, result.shape\n"
        "assert np.array_equal(np.array(result.real), real[%s])\n" % (key, key, key)
    )
    process = _isolated(code)

    assert process.returncode == 0, process.stdout + process.stderr

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("key", KEYS_3X4)
def test_basic_indexing_matches_numpy(key):
    """
    Row 1: basic indexing follows NumPy on the logical shape (ndim <= 2 until Phase 8): an integer
    drops its axis, a slice keeps it, one ``...`` expands, negative indices count from the end.

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
@pytest.mark.parametrize("seed", range(8))
def test_random_slice_keys_keep_their_axes(seed):
    """
    Row 1: random slice keys (steps, negative starts) on 2-D arrays keep both axes and give NumPy's
    shapes and values.

    Parameters
    ----------
    seed : int
        Seed of the random shape and key.
    """

    rng = np.random.default_rng(300 + seed)
    shape = tuple(int(n) for n in rng.integers(2, 6, size=2))
    array, real = _make(shape, seed)
    key = tuple(slice(int(rng.integers(-extent, extent)), None, int(rng.choice([-2, -1, 1, 2])))
                for extent in shape)
    result = array[key]

    assert result.shape == real[key].shape
    np.testing.assert_array_equal(_real(result), real[key])

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@PENDING
@pytest.mark.parametrize("seed", range(8))
def test_random_integer_keys_drop_an_axis(seed):
    """
    Row 1: a random key with one integer and one slice on a 2-D array drops the integer's axis (NumPy
    rule) and gives NumPy's values.

    Parameters
    ----------
    seed : int
        Seed of the random shape and key.
    """

    rng = np.random.default_rng(500 + seed)
    shape = tuple(int(n) for n in rng.integers(2, 6, size=2))
    array, real = _make(shape, seed)
    axis = int(rng.integers(0, 2))
    items = [slice(int(rng.integers(0, shape[0])), None, int(rng.choice([1, 2]))),
             slice(int(rng.integers(0, shape[1])), None, int(rng.choice([1, 2])))]
    items[axis] = int(rng.integers(0, shape[axis]))
    key = tuple(items)
    result = array[key]

    assert len(result.shape) == 1
    assert result.shape == real[key].shape
    np.testing.assert_array_equal(_real(result), real[key])

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_integer_keys_give_scalars():
    """
    Row 1: one integer per axis gives an OTI scalar in every algebra; negative indices count from the
    end.
    """

    array, real = _make((3, 4))

    for key in ((1, 2), (-1, -1), (0, -4)):

        scalar = array[key]

        assert isinstance(scalar, ss.ssotinum)
        assert scalar.real == real[key]

    # end for

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@PENDING
def test_empty_tuple_key_of_a_zero_dimensional_array_gives_a_scalar():
    """
    Row 1: ``A[()]`` of a 0-D array is an OTI scalar.
    """

    scalar = ss.array(2.5)[()]

    assert isinstance(scalar, ss.ssotinum)
    assert scalar.real == 2.5

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@PENDING
def test_newaxis_is_a_rank_error():
    """
    Row 1: ``A[None]`` raises ``ValueError`` in ``pyoti.semisparse`` until Phase 8 (the rank limit of
    2, 11.1); ``A[..., 0]`` is supported and gives ``(3,)``.
    """

    array, real = _make((3, 4))

    with pytest.raises(ValueError, match="at most 2 dimensions"):

        array[None]

    # end with

    assert array[..., 0].shape == (3,)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@PENDING
def test_three_dimensional_arrays_are_refused():
    """
    11.1: ndim > 2 raises ``ValueError("... arrays have at most 2 dimensions")``.
    """

    with pytest.raises(ValueError, match="at most 2 dimensions"):

        ss.zeros((2, 3, 4))

    # end with

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("key", [(3, 0), (0, 4), (-4, 0), 3, (0, 0, 0)])
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
@pytest.mark.parametrize("key", [1.5, "a", (0, "a")])
def test_float_and_string_keys_raise(key):
    """
    Row 1: a float or string key raises ``IndexError`` or ``TypeError``.

    Parameters
    ----------
    key : object
        Invalid key.
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
    Row 1: ``len(A) == A.shape[0]``; ``iter(A)`` yields rows with one axis fewer (OTI scalars for a 1-D
    array); ``len()`` and iteration of a 0-D array raise ``TypeError``.
    """

    array, real = _make((3, 4))
    rows = list(array)

    assert len(array) == 3
    assert all(row.shape == (4,) for row in rows)
    np.testing.assert_array_equal(_real(rows[1]), real[1])

    vector, vreal = _make((5,))

    assert all(isinstance(item, ss.ssotinum) for item in vector)
    assert len(list(vector)) == 5

    with pytest.raises(TypeError):

        len(ss.array(2.5))

    # end with

    with pytest.raises(TypeError):

        iter(ss.array(2.5))

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
    assert objects[1, 2].real == real[1, 2]

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("call, shape", [
    pytest.param(lambda: ss.zeros(4), (4,), id="zeros-int", marks=PENDING),
    pytest.param(lambda: ss.zeros((4,)), (4,), id="zeros-1-tuple", marks=PENDING),
    pytest.param(lambda: ss.ones(4), (4,), id="ones-int", marks=PENDING),
    pytest.param(lambda: ss.array(np.arange(1.0, 5.0)), (4,), id="array-1d", marks=PENDING),
    pytest.param(lambda: ss.array([1.0, 2.0, 3.0]), (3,), id="array-list", marks=PENDING),
    pytest.param(lambda: ss.array(2.5), (), id="array-scalar", marks=PENDING),
    pytest.param(lambda: ss.zeros(()), (), id="zeros-0d", marks=PENDING),
    pytest.param(lambda: ss.array([[1.0], [2.0]]), (2, 1), id="array-column"),
    pytest.param(lambda: ss.zeros((2, 3)), (2, 3), id="zeros-2d"),
    pytest.param(lambda: ss.eye(3), (3, 3), id="eye"),
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
    ``IndexError``.
    """

    x = ss.array(np.arange(1.0, 5.0))

    assert x[2].real == 3.0

    with pytest.raises(IndexError):

        x[2, 0]

    # end with

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_nrows_ncols_keep_their_values_for_low_dimensions():
    """
    Row 10: ``nrows`` / ``ncols`` keep their 1.x values (1-D: ``n, 1``; 0-D: ``1, 1``); they are
    deprecated, so a ``DeprecationWarning`` is allowed.
    """

    import warnings

    with warnings.catch_warnings():

        warnings.simplefilter("ignore", DeprecationWarning)

        assert (ss.array(np.arange(1.0, 5.0)).nrows, ss.array(np.arange(1.0, 5.0)).ncols) == (4, 1)
        assert (ss.array(2.5).nrows, ss.array(2.5).ncols) == (1, 1)
        assert (ss.zeros((2, 3)).nrows, ss.zeros((2, 3)).ncols) == (2, 3)

    # end with

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@PENDING
def test_column_into_one_dimensional_target_raises():
    """
    Row 3: assignment broadcasts as NumPy does: an ``(n, 1)`` column no longer fits an ``(n,)`` target;
    ``A[:, 3:4] = column`` and ``A[:, 3] = column[:, 0]`` work.
    """

    array, real = _make((3, 4))
    column, creal = _make((3, 1), seed=5)

    with pytest.raises(ValueError):

        array[:, 3] = column

    # end with

    array[:, 3:4] = column
    real[:, 3:4] = creal

    np.testing.assert_array_equal(_real(array), real)

    array[:, 2] = column[:, 0]
    real[:, 2] = creal[:, 0]

    np.testing.assert_array_equal(_real(array), real)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_row_assignment_into_a_one_dimensional_target():
    """
    Row 3: a ``(1, n)`` row fits an ``(n,)`` target (the FEM pattern ``strain[0, 0:2*nb:2] = nx``).
    """

    array = ss.zeros((3, 8))
    row, rreal = _make((1, 4))
    reference = np.zeros((3, 8))

    array[0, 0:8:2] = row
    reference[0, 0:8:2] = rreal

    np.testing.assert_array_equal(_real(array), reference)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@PENDING
@pytest.mark.parametrize("seed", range(8))
def test_assignment_broadcasts_like_numpy(seed):
    """
    Row 3: ``A[key] = value`` with random keys and values of random compatible shapes gives NumPy's
    result or raises ``ValueError`` exactly where NumPy does.

    Parameters
    ----------
    seed : int
        Seed of the random key and value shape.
    """

    rng = np.random.default_rng(400 + seed)
    array, real = _make((4, 5), seed)
    key = (int(rng.integers(0, 4)), slice(int(rng.integers(0, 2)), None, int(rng.integers(1, 3))))
    target = real[key].shape

    for vshape in (target, (1,) + target, (target[0], 1), (2,) + target):

        value, vreal = _make(vshape, seed + 7)
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
def test_assignment_from_an_overlapping_slice_is_a_snapshot(operation):
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
def test_broadcasting_is_limited_to_equal_shapes_and_scalars():
    """
    Row 2 / 11.2: semi-sparse supports broadcasting only between equal shapes and against scalars; mixing
    ``(n,)`` and ``(n, 1)`` raises ``ValueError`` naming ``pyoti.dense`` instead of building an
    ``(n, n)`` array.
    """

    x, xreal = _make((4,), 1)
    y, yreal = _make((4, 1), 2)
    z, zreal = _make((4,), 3)

    with pytest.raises(ValueError, match="pyoti.dense only"):

        x + y

    # end with

    np.testing.assert_allclose(_real(x + z), xreal + zreal)
    np.testing.assert_allclose(_real(x + 2.0), xreal + 2.0)
    np.testing.assert_allclose(_real(2.0 * x), 2.0 * xreal)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_slices_are_copies():
    """
    Row 4: ``oarrss`` slices and ``.T`` are copies in 7b (views from Phase 8, A2): a write through a
    slice never reaches the parent. This test pins the 7b behaviour and changes in Phase 8.
    """

    array, real = _make((3, 4))
    row = array[0]
    transposed = array.T

    row[0] = 42.0
    transposed[0, 0] = 43.0

    np.testing.assert_array_equal(_real(array), real)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_chained_assignment_writes_into_a_discarded_copy():
    """
    Row 4 / S3: ``A[1:3][0] = v`` writes into a discarded copy for ``oarrss`` between 7b and Phase 8,
    like NumPy fancy indexing; portable code uses one subscript.
    """

    array, real = _make((4, 3))

    array[1:3][0] = 5.0

    np.testing.assert_array_equal(_real(array), real)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@PENDING
def test_real_is_a_read_only_view():
    """
    Row 5: ``oarrss.real`` is a read-only view that shares memory with the array: writing raises
    ``ValueError``; ``.real.copy()`` is writable and independent.
    """

    array, real = _make((3, 4))
    view = array.real

    assert not view.flags.writeable

    with pytest.raises(ValueError, match="read-only"):

        view[0, 0] = 1.0

    # end with

    np.testing.assert_array_equal(view, real)
    assert np.shares_memory(view, array.real)

    snapshot = view.copy()
    snapshot[0, 0] = 123.0

    assert array[0, 0].real != 123.0

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@PENDING
def test_csr_real_is_read_only_and_get_real_writeable_reaches_the_matrix():
    """
    Row 5: ``csr_matrix.real`` is read-only; ``get_real(writeable=True)`` returns a SciPy CSR whose
    ``data`` is the writable real block.
    """

    matrix = ss.csr_matrix(scs.csr_matrix(np.array([[1.0, 0.0], [0.0, 2.0]])))
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
@PENDING
def test_dot_of_one_dimensional_arrays():
    """
    Row 8: ``dot(x, y)`` of 1-D arrays is the inner product, an OTI scalar; ``x @ y`` gives the same
    scalar.
    """

    x, xreal = _make((4,), 1)
    y, yreal = _make((4,), 2)

    for scalar in (ss.dot(x, y), x @ y):

        assert isinstance(scalar, ss.ssotinum)
        assert scalar.real == pytest.approx(xreal @ yreal)

    # end for

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@PENDING
def test_matrix_vector_products_drop_the_vector_axis():
    """
    Row 8: ``dot(A, x)`` and ``A @ x`` are ``(m,)``, ``dot(x, A)`` and ``x @ A`` are ``(n,)``.
    """

    matrix, mreal = _make((3, 4), 1)
    x, xreal = _make((4,), 2)
    z, zreal = _make((3,), 3)

    for result in (ss.dot(matrix, x), matrix @ x):

        assert result.shape == (3,)
        np.testing.assert_allclose(_real(result), mreal @ xreal)

    # end for

    for result in (ss.dot(z, matrix), z @ matrix):

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
    result = ss.dot(x.T, y)

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
    scalar = ss.dot_product(a, b)

    assert isinstance(scalar, ss.ssotinum)
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
    result = ss.trunc_dot(0, lhs, 0, rhs)

    assert result.shape == expected
    np.testing.assert_allclose(_real(result), lreal @ rreal)

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
    matrix = ss.csr_matrix(real)
    vector, vreal = _make((3,), 1)
    block, breal = _make((3, 2), 2)

    assert (matrix @ vector).shape == (3,)
    assert (matrix @ block).shape == (3, 2)
    assert ss.solve(matrix, vector).shape == (3,)
    assert ss.solve(matrix, block).shape == (3, 2)
    np.testing.assert_allclose(_real(matrix @ vector), real @ vreal)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@PENDING
@pytest.mark.parametrize("shape", [(), (4,), (2, 3)])
def test_saved_files_are_version_2_and_round_trip(tmp_path, shape):
    """
    Row 9 / 11.12: ``save`` writes version 2 and the file reads back with the same shape (0-D, 1-D and
    2-D) and coefficients.

    Parameters
    ----------
    tmp_path : pathlib.Path
        Temporary directory.
    shape : tuple of int
        Shape of the array.
    """

    array, _ = _make(shape, 3)
    path = tmp_path / "file.ots"

    ss.save(array, path)

    assert int.from_bytes(path.read_bytes()[4:6], "little") == 2

    back = ss.read(path)

    assert back.shape == shape
    _same_state(back, array)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_v1_files_read_with_their_stored_two_dimensional_shape(tmp_path):
    """
    Row 9 / 11.12: 2.0 reads the files of 1.x: a ``(2, 3)`` file gives ``(2, 3)`` and a ``(4, 1)``
    column file gives ``(4, 1)``, never guessed as ``(4,)``; the values are the ones written.

    Parameters
    ----------
    tmp_path : pathlib.Path
        Temporary directory.
    """

    real = np.arange(12.0).reshape(3, 4)[:2, :3]
    wide = (ss.array(real) + ss.e(1, order=2) * ss.array(real * 0.5)
            + ss.e(2, order=2) * ss.array(np.ones((2, 3))))
    column = ss.array(np.array([[1.0], [2.0], [3.0], [4.0]])) + ss.e(1, order=1) * ss.array(
        np.array([[0.5], [0.25], [2.0], [1.0]]))

    for data, expected in ((V1_SS_2X3_O2, wide), (V1_SS_4X1_O1, column)):

        path = tmp_path / "v1.ots"
        path.write_bytes(data)

        assert int.from_bytes(data[4:6], "little") == 1

        array = ss.read(path)

        assert array.shape == expected.shape
        _same_state(array, expected)

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

    for data in (V1_SS_2X3_O2, V1_SS_4X1_O1):

        path = tmp_path / "v1.ots"
        path.write_bytes(data)

        array = ss.read(path)
        again = tmp_path / "v2.ots"

        ss.save(array, again)

        assert int.from_bytes(again.read_bytes()[4:6], "little") == 2

        _same_state(ss.read(again), array)

    # end for

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_gauss_arrays_keep_the_matrix_rule():
    """
    Row 1 / 11.8 (A5): Gauss arrays keep the matrix rule: ``G[i]`` is ``(1, ncols)``, ``G[:, j]`` is
    ``(nrows, 1)``, ``G[i, j]`` is a Gauss scalar, a 3-index key raises ``IndexError`` and ``get_ip``
    returns a plain ``(nrows, ncols)`` copy.
    """

    gauss = ss.oarrssfe((2, 3), nip=4, bases=[1, 2], order=1)

    assert gauss[0].shape == (1, 3)
    assert gauss[1, :].shape == (1, 3)
    assert gauss[:, 2].shape == (2, 1)
    assert isinstance(gauss[1, 2], ss.ssotife)
    assert gauss.get_ip(0).shape == (2, 3)

    with pytest.raises(IndexError):

        gauss[(0, 0, 0)]

    # end with

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_gauss_negative_indices_work_in_every_algebra():
    """
    Row 1 / 11.8: ``G[-1, -1]`` and ``G[-1]`` work for semi-sparse Gauss arrays.
    """

    gauss = ss.oarrssfe((2, 3), nip=4, bases=[1, 2], order=1)

    assert isinstance(gauss[-1, -1], ss.ssotife)
    assert gauss[-1].shape == (1, 3)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@PENDING
def test_gauss_real_is_a_read_only_view():
    """
    Row 5 / 11.8: ``G.real`` of a semi-sparse Gauss array is a read-only ``(nip, nrows, ncols)`` view.
    """

    gauss = ss.oarrssfe((2, 3), nip=4, bases=[1, 2], order=1)
    real = gauss.real

    assert real.shape == (4, 2, 3)
    assert not real.flags.writeable

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

    fem.set_global_algebra(ss)

    try:

        helper = ss.elm_help()
        helper.allocate(2, 4, 1, nbases=0, order=0)
        helper.allocate_spatial(2)

        values = np.array([4.0, 5.0, 6.0, 7.0, 8.0, 9.0])
        x = ss.array(values.reshape((6,) + shape[1:]))
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
def test_elm_help_allocate_reserves_the_labels():
    """
    Row 7 / 11.7: ``elm_help.allocate(..., nbases=K, bases=[...])`` for semi-sparse takes ``nbases`` as
    capacity and reserves the labels of every helper field, so the fields never relayout during
    assembly.
    """

    fem.set_global_algebra(ss)

    try:

        helper = ss.elm_help()
        helper.allocate(2, 4, 3, nbases=6, order=2, bases=[1, 3, 5])

        for name in ("N", "Nxi", "Neta", "w", "xi", "eta"):

            field = getattr(helper, name)

            assert tuple(field.active_bases) == (1, 3, 5), name
            assert field.order == 2, name

        # end for

    finally:

        fem.set_global_algebra(sp)

    # end try

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_aos_slices_are_copies():
    """
    Row 4: slices of an ``arrss`` (AoS) are copies: a write through the slice does not reach the
    parent.
    """

    array = ss.array(np.arange(12.0).reshape(3, 4)).to_aos()
    row = array[0]

    row[0] = 42.0

    assert array[0, 0].real == 0.0

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@PENDING
def test_get_block_is_read_only_unless_writeable():
    """
    Row 5: ``get_block(d)`` is a read-only view by default; ``get_block(d, writeable=True)`` is a
    writable view that reaches the array.
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
@pytest.mark.parametrize("source", ["real", "block"])
def test_growth_with_a_live_export_raises_buffererror(source):
    """
    Row 6 / G3: semi-sparse gets dense's growth guard: growing the layout (a new base label or a higher
    order) while a ``.real`` or ``get_block`` export is alive raises ``BufferError`` with the phrase
    ``live block views``; after the export is dropped the array grows again.

    Parameters
    ----------
    source : str
        Kind of live export.
    """

    array = ss.zeros((3, 3))
    array[0, 0] = ss.e(1, order=1)
    held = {"real": lambda: array.real, "block": lambda: array.get_block(0)}[source]()

    with pytest.raises(BufferError, match="live block views"):

        array[1, 1] = ss.e(7, order=3)

    # end with

    del held

    array[1, 1] = ss.e(7, order=3)

    assert array.order == 3

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_root_growth_without_exports():
    """
    Row 6 / G1: writing into a root grows it (labels and truncation order rise to the value's) while no
    export is alive.
    """

    array = ss.zeros((2, 2))
    array[0:2, 0:2] = ss.e(5, order=2)

    assert array.order == 2
    assert 5 in array.active_bases

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_bases_reserve_the_labels_and_keep_the_layout_stable():
    """
    Row 7 / 11.7: semi-sparse creators with ``bases=[...]`` reserve the labels (unchanged), so
    assignments inside them never grow the array while an export is alive.
    """

    array = ss.zeros((3, 3), bases=[1, 3], order=2)

    assert tuple(array.active_bases) == (1, 3)

    held = array.real

    array[0, 0] = ss.e(3, order=2)

    assert array.get_deriv([3])[0, 0].real == 1.0
    assert held.shape == (3, 3)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_nbases_is_capacity_only():
    """
    Row 7 / A1: semi-sparse creators with ``nbases=K`` take it as capacity only: no labels are
    reserved (the 1.x behaviour), unlike dense arrays where ``nbases`` reserves the layout.
    """

    assert tuple(ss.zeros((2, 3), nbases=4, order=2).active_bases) == ()

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@PENDING
def test_reserve_labels_up_front():
    """
    Row 6 / G4: ``oarrss.reserve(bases=, order=)`` grows the layout immediately; it raises
    ``BufferError`` with a live export.
    """

    array = ss.zeros((2, 3))

    array.reserve(bases=[2, 4], order=2)

    assert tuple(array.active_bases) == (2, 4)
    assert array.order == 2

    held = array.real

    with pytest.raises(BufferError, match="live block views"):

        array.reserve(bases=[7], order=2)

    # end with

    assert held.shape == (2, 3)

# end function
# --------------------------------------------------------------------------------------------------------
