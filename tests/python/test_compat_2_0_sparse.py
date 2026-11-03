"""
The 2.0.0 compatibility suite of ``pyoti.sparse`` (``matso``; contracts section 11, list 11.14).

Every test asserts the 2.0.0 behaviour (the "after" column of the contracts). Tests whose behaviour
lands with Phase 7b carry ``@pytest.mark.xfail(strict=True, reason="2.0.0 behaviour, Phase 7b")``: the
suite passes today, and a test that starts to pass (XPASS) fails loudly, which is the signal to remove
its marker. Behaviour that is already 2.0.0 carries no marker. ``Row n`` in the docstrings refers to
the numbered items of the breaking-changes list (11.14).

``matso`` is AoS with a 2-D C struct: basic slices are copies in every phase, the logical ndim is at
most 2, and broadcasting is limited to equal shapes and scalars.
"""

import os
import subprocess
import sys

import numpy as np
import pytest
import scipy.sparse as scs

import pyoti.fem as fem
import pyoti.sparse as sp

PENDING = pytest.mark.xfail(strict=True, reason="2.0.0 behaviour, Phase 7b")

# Files written by the last 1.x writer (version 1): an order-2 array of shape (2, 3) with two bases and
# a (4, 1) column with one base.
V1_SP_2X3_O2 = bytes.fromhex(
    "934f5449010015001c010000000000000200000000000000030000000000000000000000000000000000000000000000"
    "00000000000000000000000000000000000000000000000002010100000000000000000000000000f03f010000000000"
    "0000000000000000f03f02010200000000000000000000000000e03f000000000000f03f000000000000000001000000"
    "00000000000000000000004002010200000000000000000000000000f03f000000000000f03f00000000000000000100"
    "0000000000000000000000001040020102000000000000000000000000000040000000000000f03f0000000000000000"
    "01000000000000000000000000001440020102000000000000000000000000000440000000000000f03f000000000000"
    "000001000000000000000000000000001840020102000000000000000000000000000840000000000000f03f00000000"
    "000000000100000000000000"
)
V1_SP_4X1_O1 = bytes.fromhex(
    "934f54490100150088000000000000000400000000000000010000000000000000000000000000000000000000000000"
    "00000000000000000000000000000000000000000000f03f01010100000000000000000000000000e03f000000000000"
    "0000000000000000004001010100000000000000000000000000d03f0000000000000000000000000000084001010100"
    "00000000000000000000000000400000000000000000000000000000104001010100000000000000000000000000f03f"
    "0000000000000000"
)


# ********************************************************************************************************
def _real(obj):
    """
    Copy the real part of an array or scalar into a NumPy array.

    Parameters
    ----------
    obj : matso or sotinum
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
    Build a sparse array with random real data and one imaginary direction.

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
    matso, numpy.ndarray
        The array and its real part.
    """

    rng = np.random.default_rng(seed)
    real = rng.standard_normal(shape)
    other = rng.standard_normal(shape)

    return sp.array(real) + sp.e(1, order=order) * sp.array(other), real

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _same_state(first, second):
    """
    Assert that two sparse arrays have the same shape, order and coefficients.

    Parameters
    ----------
    first : matso
        First array.
    second : matso
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
    be asserted in-process, so these checks run in a subprocess.

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
    ``matso`` terminates the interpreter on ``A[-1]``.)

    Parameters
    ----------
    key : str
        Source text of the key applied to an array of shape ``(3, 4)``.
    """

    code = (
        "import numpy as np, pyoti.sparse as sp\n"
        "real = np.arange(12.0).reshape(3, 4)\n"
        "result = sp.array(real)[%s]\n"
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
    Row 1: basic indexing follows NumPy on the logical shape: an integer drops its axis, a slice keeps
    it, one ``...`` expands, negative indices count from the end.

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
@PENDING
def test_integer_keys_give_scalars():
    """
    Row 1: one integer per axis gives an OTI scalar in every algebra; negative indices count from the
    end (sparse's ``OverflowError`` for ``A[-1, -1]`` disappears).
    """

    array, real = _make((3, 4))

    for key in ((1, 2), (-1, -1), (0, -4)):

        scalar = array[key]

        assert isinstance(scalar, sp.sotinum)
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

    scalar = sp.array(2.5)[()]

    assert isinstance(scalar, sp.sotinum)
    assert scalar.real == 2.5

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@PENDING
def test_newaxis_is_a_rank_error():
    """
    Row 1: ``A[None]`` raises ``ValueError`` in ``pyoti.sparse`` (the rank limit of 2, 11.1); ``A[...,
    0]`` is supported and gives ``(3,)``.
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

        sp.zeros((2, 3, 4))

    # end with

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("key", [(3, 0), (0, 4), pytest.param((-4, 0), marks=PENDING), 3, (0, 0, 0)])
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

    assert all(isinstance(item, sp.sotinum) for item in vector)
    assert len(list(vector)) == 5

    with pytest.raises(TypeError):

        len(sp.array(2.5))

    # end with

    with pytest.raises(TypeError):

        iter(sp.array(2.5))

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
    pytest.param(lambda: sp.zeros(4), (4,), id="zeros-int", marks=PENDING),
    pytest.param(lambda: sp.zeros((4,)), (4,), id="zeros-1-tuple", marks=PENDING),
    pytest.param(lambda: sp.ones(4), (4,), id="ones-int", marks=PENDING),
    pytest.param(lambda: sp.array(np.arange(1.0, 5.0)), (4,), id="array-1d", marks=PENDING),
    pytest.param(lambda: sp.array([1.0, 2.0, 3.0]), (3,), id="array-list", marks=PENDING),
    pytest.param(lambda: sp.array(2.5), (), id="array-scalar", marks=PENDING),
    pytest.param(lambda: sp.zeros(()), (), id="zeros-0d", marks=PENDING),
    pytest.param(lambda: sp.array([[1.0], [2.0]]), (2, 1), id="array-column"),
    pytest.param(lambda: sp.zeros((2, 3)), (2, 3), id="zeros-2d"),
    pytest.param(lambda: sp.eye(3), (3, 3), id="eye"),
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

    x = sp.array(np.arange(1.0, 5.0))

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

        assert (sp.array(np.arange(1.0, 5.0)).nrows, sp.array(np.arange(1.0, 5.0)).ncols) == (4, 1)
        assert (sp.array(2.5).nrows, sp.array(2.5).ncols) == (1, 1)
        assert (sp.zeros((2, 3)).nrows, sp.zeros((2, 3)).ncols) == (2, 3)

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

    array = sp.zeros((3, 8))
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
    Row 2 / 11.2: sparse supports broadcasting only between equal shapes and against scalars; mixing
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
    Row 4: ``matso`` slices are copies: a write through a slice never reaches the parent, and
    ``.T`` is a copy as well.
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
    Row 4 / S3: ``A[1:3][0] = v`` writes into a discarded copy for ``matso``, like NumPy fancy
    indexing; portable code uses one subscript.
    """

    array, real = _make((4, 3))

    array[1:3][0] = 5.0

    np.testing.assert_array_equal(_real(array), real)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@PENDING
def test_real_is_a_read_only_copy():
    """
    Row 5: ``matso.real`` is a read-only copy: writing raises ``ValueError``, and the copy does not
    share memory with the array.
    """

    array, real = _make((3, 4))
    view = array.real

    assert not view.flags.writeable

    with pytest.raises(ValueError, match="read-only"):

        view[0, 0] = 1.0

    # end with

    np.testing.assert_array_equal(view, real)
    assert not np.shares_memory(view, array.real)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@PENDING
def test_csr_real_is_read_only_and_get_real_returns_a_writable_copy():
    """
    Row 5: ``csr_matrix.real`` is a read-only copy for sparse; ``get_real(writeable=True)`` returns a
    writable **copy** whose writes do not reach the matrix.
    """

    matrix = sp.csr_matrix(scs.csr_matrix(np.array([[1.0, 0.0], [0.0, 2.0]])))
    real = matrix.real

    assert not real.data.flags.writeable

    with pytest.raises(ValueError, match="read-only"):

        real.data[0] = 5.0

    # end with

    writable = matrix.get_real(writeable=True)

    assert writable.data.flags.writeable

    writable.data[0] = 5.0

    assert matrix.real.data[0] == 1.0

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

    for scalar in (sp.dot(x, y), x @ y):

        assert isinstance(scalar, sp.sotinum)
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

    for result in (sp.dot(matrix, x), matrix @ x):

        assert result.shape == (3,)
        np.testing.assert_allclose(_real(result), mreal @ xreal)

    # end for

    for result in (sp.dot(z, matrix), z @ matrix):

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
    result = sp.dot(x.T, y)

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
    scalar = sp.dot_product(a, b)

    assert isinstance(scalar, sp.sotinum)
    assert scalar.real == pytest.approx(float(np.sum(areal * breal)))

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@PENDING
@pytest.mark.parametrize("lshape, rshape, expected", [
    pytest.param((4,), (4, 3), (3,), id="row-by-matrix"),
    pytest.param((3, 4), (4,), (3,), id="matrix-by-column"),
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
    result = sp.trunc_dot(0, lhs, 0, rhs)

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
    matrix = sp.csr_matrix(real)
    vector, vreal = _make((3,), 1)
    block, breal = _make((3, 2), 2)

    assert (matrix @ vector).shape == (3,)
    assert (matrix @ block).shape == (3, 2)
    assert sp.solve(matrix, vector).shape == (3,)
    assert sp.solve(matrix, block).shape == (3, 2)
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
    path = tmp_path / "file.oti"

    sp.save(array, path)

    assert int.from_bytes(path.read_bytes()[4:6], "little") == 2

    back = sp.read(path)

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
    wide = (sp.array(real) + sp.e(1, order=2) * sp.array(real * 0.5)
            + sp.e(2, order=2) * sp.array(np.ones((2, 3))))
    column = sp.array(np.array([[1.0], [2.0], [3.0], [4.0]])) + sp.e(1, order=1) * sp.array(
        np.array([[0.5], [0.25], [2.0], [1.0]]))

    for data, expected in ((V1_SP_2X3_O2, wide), (V1_SP_4X1_O1, column)):

        path = tmp_path / "v1.oti"
        path.write_bytes(data)

        assert int.from_bytes(data[4:6], "little") == 1

        array = sp.read(path)

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

    for data in (V1_SP_2X3_O2, V1_SP_4X1_O1):

        path = tmp_path / "v1.oti"
        path.write_bytes(data)

        array = sp.read(path)
        again = tmp_path / "v2.oti"

        sp.save(array, again)

        assert int.from_bytes(again.read_bytes()[4:6], "little") == 2

        _same_state(sp.read(again), array)

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

    gauss = sp.matsofe((2, 3), nip=4, order=1, nbases=2)

    assert gauss[0].shape == (1, 3)
    assert gauss[1, :].shape == (1, 3)
    assert gauss[:, 2].shape == (2, 1)
    assert isinstance(gauss[1, 2], sp.sotife)
    assert gauss.get_ip(0).shape == (2, 3)

    with pytest.raises(IndexError):

        gauss[(0, 0, 0)]

    # end with

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@PENDING
def test_gauss_negative_indices_work_in_every_algebra():
    """
    Row 1 / 11.8: ``G[-1, -1]`` works for sparse Gauss arrays (it raised ``OverflowError``).
    """

    gauss = sp.matsofe((2, 3), nip=4, order=1, nbases=2)

    assert isinstance(gauss[-1, -1], sp.sotife)
    assert gauss[-1].shape == (1, 3)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_gauss_real_is_a_real_gauss_matrix():
    """
    Row 5 / A4: sparse Gauss ``.real`` returns a real Gauss ``dmatfe`` object (a copy), not a NumPy
    array; it is unchanged in 2.0.0.
    """

    gauss = sp.matsofe((2, 3), nip=4, order=1, nbases=2)

    assert type(gauss.real).__name__ == "dmatfe"
    assert gauss.real.shape == (2, 3)

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

    fem.set_global_algebra(sp)

    helper = sp.elm_help()
    helper.allocate(2, 4, 1, nbases=0, order=0)
    helper.allocate_spatial(2)

    values = np.array([4.0, 5.0, 6.0, 7.0, 8.0, 9.0])
    x = sp.array(values.reshape((6,) + shape[1:]))
    indices = np.array([5, 1, 3, 0])

    helper.set_coordinates(x, x, x, indices)

    assert helper.x.shape == (4, 1)
    np.testing.assert_array_equal(_real(helper.x).reshape(-1), values[indices])

    local = helper.get_local(x, indices)

    assert local.shape == (4, 1)
    np.testing.assert_array_equal(_real(local).reshape(-1), values[indices])

# end function
# --------------------------------------------------------------------------------------------------------
