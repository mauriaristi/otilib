"""
The 2.0.0 compatibility suite of ``pyoti.real`` (``dmat``, ``dmatfe``, ``dnumfe``; contracts 11.9, 11.8
and list 11.14).

Every test asserts the 2.0.0 behaviour (the "after" column of the contracts). Tests whose behaviour
lands with Phase 7b carry ``@pytest.mark.xfail(strict=True, reason="2.0.0 behaviour, Phase 7b")``: the
suite passes today, and a test that starts to pass (XPASS) fails loudly, which is the signal to remove
its marker. Behaviour that is already 2.0.0 carries no marker; that includes what Phase 6b delivers
(``dmat`` slices are views, ``to_numpy()`` is a writable zero-copy view). ``Row n`` in the docstrings
refers to the numbered items of the breaking-changes list (11.14).

``dmat`` keeps a 2-D C struct: the Python object carries a logical shape of ndim 0, 1 or 2, and ndim
above 2 raises ``ValueError``. Its indexing switches to NumPy's in 7b, in the same commit as ``matso``.
"""

import os
import subprocess
import sys
import warnings

import numpy as np
import pytest

import pyoti.real as real
import pyoti.sparse as sp

PENDING = pytest.mark.xfail(strict=True, reason="2.0.0 behaviour, Phase 7b")


# ********************************************************************************************************
def _make(shape, seed=0):
    """
    Build a ``dmat`` with random data.

    Parameters
    ----------
    shape : tuple of int
        Shape of the matrix.
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


KEYS_3X4 = [
    pytest.param(1, id="int", marks=PENDING),
    pytest.param((1, slice(None)), id="int-colon", marks=PENDING),
    pytest.param((slice(None), 2), id="colon-int", marks=PENDING),
    pytest.param(-1, id="negative-int", marks=PENDING),
    pytest.param((-2, slice(None)), id="negative-int-colon", marks=PENDING),
    pytest.param((slice(None), -1), id="colon-negative-int", marks=PENDING),
    pytest.param((Ellipsis, 0), id="ellipsis-int", marks=PENDING),
    pytest.param((slice(1, 2), slice(None)), id="row-slice"),
    pytest.param((slice(None), slice(2, 3)), id="column-slice"),
    pytest.param((slice(None, None, -1), slice(0, 4, 2)), id="reversed-strided"),
]


# ********************************************************************************************************
@pytest.mark.parametrize("key", KEYS_3X4)
def test_basic_indexing_matches_numpy(key):
    """
    Row 1: ``dmat`` indexing follows NumPy on the logical shape: an integer drops its axis, a slice
    keeps it, one ``...`` expands, negative indices count from the end.

    Parameters
    ----------
    key : object
        Index key applied to a matrix of shape ``(3, 4)``.
    """

    matrix, data = _make((3, 4))
    result = matrix[key]

    assert result.shape == data[key].shape
    np.testing.assert_array_equal(result.to_numpy(), data[key])

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@PENDING
def test_integer_keys_give_floats_and_negative_indices_count_from_the_end():
    """
    Row 1: one integer per axis gives a float; negative indices count from the end.
    """

    matrix, data = _make((3, 4))

    assert matrix[1, 2] == data[1, 2]
    assert matrix[-1, -1] == data[-1, -1]
    assert matrix[0, -4] == data[0, -4]

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@PENDING
def test_newaxis_is_a_rank_error():
    """
    Row 1 / 11.1: ``D[None]`` raises ``ValueError`` (the rank limit of 2 applies to ``dmat``).
    """

    matrix, _ = _make((3, 4))

    with pytest.raises(ValueError, match="at most 2 dimensions"):

        matrix[None]

    # end with

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@PENDING
def test_three_dimensional_shapes_are_refused():
    """
    11.1: ndim > 2 raises ``ValueError("... arrays have at most 2 dimensions")``.
    """

    with pytest.raises(ValueError, match="at most 2 dimensions"):

        real.zeros((2, 3, 4))

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
        Invalid key for a ``(3, 4)`` matrix.
    """

    matrix, _ = _make((3, 4))

    with pytest.raises(IndexError):

        matrix[key]

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

    matrix, _ = _make((3, 4))

    with pytest.raises((IndexError, TypeError)):

        matrix[key]

    # end with

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@PENDING
def test_len_and_iteration():
    """
    Row 1: ``len(D) == D.shape[0]`` and ``iter(D)`` yields ``D[0], D[1], ...`` (rows of shape
    ``(ncols,)``; floats for a 1-D matrix); ``len()`` and iteration of a 0-D matrix raise
    ``TypeError``.
    """

    matrix, data = _make((3, 4))
    rows = list(matrix)

    assert len(matrix) == 3
    assert all(row.shape == (4,) for row in rows)
    np.testing.assert_array_equal(rows[2].to_numpy(), data[2])

    vector = real.array(np.arange(5.0))

    assert len(vector) == 5
    assert list(vector) == [0.0, 1.0, 2.0, 3.0, 4.0]

    with pytest.raises(TypeError):

        len(real.array(2.5))

    # end with

    with pytest.raises(TypeError):

        iter(real.array(2.5))

    # end with

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("call, shape", [
    pytest.param(lambda: real.zeros(4), (4,), id="zeros-int", marks=PENDING),
    pytest.param(lambda: real.zeros((4,)), (4,), id="zeros-1-tuple", marks=PENDING),
    pytest.param(lambda: real.ones(4), (4,), id="ones-int", marks=PENDING),
    pytest.param(lambda: real.array(np.arange(1.0, 5.0)), (4,), id="array-1d", marks=PENDING),
    pytest.param(lambda: real.array(2.5), (), id="array-scalar", marks=PENDING),
    pytest.param(lambda: real.array(np.ones((2, 1))), (2, 1), id="array-column"),
    pytest.param(lambda: real.zeros((2, 3)), (2, 3), id="zeros-2d"),
    pytest.param(lambda: real.eye(3), (3, 3), id="eye"),
])


def test_creators_return_numpy_shapes(call, shape):
    """
    Row 2: creators follow NumPy: an int or 1-tuple gives a 1-D matrix, 1-D input gives a 1-D matrix, a
    scalar gives a 0-D matrix (11.1: ``dmat`` carries a logical shape of ndim 0, 1 or 2).

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
def test_nrows_ncols_keep_their_values_for_low_dimensions():
    """
    Row 10: ``nrows`` / ``ncols`` keep their 1.x values (1-D: ``n, 1``; 0-D: ``1, 1``); they are
    deprecated, so a ``DeprecationWarning`` is allowed.
    """

    with warnings.catch_warnings():

        warnings.simplefilter("ignore", DeprecationWarning)

        vector = real.array(np.arange(4.0))
        scalar = real.array(2.5)

        assert (vector.nrows, vector.ncols) == (4, 1)
        assert (scalar.nrows, scalar.ncols) == (1, 1)
        assert (real.zeros((2, 3)).nrows, real.zeros((2, 3)).ncols) == (2, 3)

    # end with

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@PENDING
def test_column_into_one_dimensional_target_raises():
    """
    Row 3: assignment broadcasts as NumPy does: an ``(n, 1)`` column no longer fits an ``(n,)`` target;
    ``D[:, 3:4] = column`` and ``D[:, 3] = column[:, 0]`` work.
    """

    matrix, data = _make((3, 4))
    column, creal = _make((3, 1), seed=5)

    with pytest.raises(ValueError):

        matrix[:, 3] = column

    # end with

    matrix[:, 3:4] = column
    data[:, 3:4] = creal

    np.testing.assert_array_equal(matrix.to_numpy(), data)

    matrix[:, 2] = column[:, 0]
    data[:, 2] = creal[:, 0]

    np.testing.assert_array_equal(matrix.to_numpy(), data)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@PENDING
@pytest.mark.parametrize("seed", range(8))
def test_assignment_broadcasts_like_numpy(seed):
    """
    Row 3: ``D[key] = value`` with random keys and values of random compatible shapes gives NumPy's
    result or raises ``ValueError`` exactly where NumPy does.

    Parameters
    ----------
    seed : int
        Seed of the random key and value shape.
    """

    rng = np.random.default_rng(900 + seed)
    matrix, data = _make((4, 5), seed)
    key = (int(rng.integers(0, 4)), slice(int(rng.integers(0, 2)), None, int(rng.integers(1, 3))))
    target = data[key].shape

    for vshape in (target, (1,) + target, (target[0], 1), (2,) + target):

        value, vdata = _make(vshape, seed + 7)
        reference = data.copy()

        try:

            reference[key] = vdata
            numpy_ok = True

        except ValueError:

            numpy_ok = False

        # end try

        if numpy_ok:

            matrix[key] = value
            np.testing.assert_array_equal(matrix.to_numpy(), reference)

        else:

            with pytest.raises(ValueError):

                matrix[key] = value

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

    matrix, data = _make((6,))

    if operation == "shift":

        matrix[1:] = matrix[:-1]
        data[1:] = data[:-1].copy()

    else:

        matrix[::-1] = matrix
        data[::-1] = data.copy()

    # end if

    np.testing.assert_array_equal(matrix.to_numpy(), data)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@PENDING
def test_row_views_are_one_dimensional_and_write_through():
    """
    Row 4 (from 6b, shapes from 7b): ``D[i]`` is a 1-D view of the row; a write through it reaches the
    parent.
    """

    matrix, data = _make((3, 4))
    row = matrix[1]

    assert row.shape == (4,)

    row[2] = 42.0
    data[1, 2] = 42.0

    np.testing.assert_array_equal(matrix.to_numpy(), data)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_chained_assignment_writes_into_the_root():
    """
    Row 4 / S3: ``D[1:3][0] = v`` writes into ``D`` for ``dmat`` (from 6b), because the first subscript
    returns a view.
    """

    matrix, data = _make((4, 3))

    matrix[1:3][0] = 5.0
    data[1:3][0] = 5.0

    np.testing.assert_array_equal(matrix.to_numpy(), data)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_to_numpy_stays_a_writable_zero_copy_view():
    """
    Row 5 / A4: ``dmat.to_numpy()`` is a real array without OTI metadata: it stays a writable view that
    shares memory with the matrix.
    """

    matrix, data = _make((3, 4))
    array = matrix.to_numpy()

    assert array.flags.writeable
    assert np.shares_memory(array, matrix.to_numpy())

    array[0, 0] = 9.0

    assert matrix[0, 0] == 9.0

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_real_attribute_is_a_writable_numpy_array():
    """
    Row 5 / A4 (table 11.4: ``.real`` of a ``dmat`` is a NumPy view via ``to_numpy()``, writable,
    unchanged): ``D.real`` holds the values and is not read-only.
    """

    matrix, data = _make((3, 4))
    array = np.asarray(matrix.real)

    assert array.flags.writeable
    np.testing.assert_array_equal(array, data)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _isolated(code):
    """
    Run a snippet in a fresh interpreter with the same import path.

    The 1.x C layer terminates the interpreter on a dimension error (``dot`` of mismatched shapes calls
    ``exit``), so checks that exercise the shapes of 1-D operands run in a subprocess.

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
@pytest.mark.parametrize("expression, shape", [
    pytest.param("real.dot(x, y)", None, id="inner"),
    pytest.param("real.dot(matrix, x)", (3,), id="matrix-vector"),
    pytest.param("real.dot(z, matrix)", (4,), id="vector-matrix"),
])


def test_one_dimensional_dot_follows_numpy(expression, shape):
    """
    Row 8 (11.3, NumPy's rule for 1-D operands): ``dot(x, y)`` of 1-D matrices is the inner product (a
    float), ``dot(A, x)`` is ``(m,)`` and ``dot(x, A)`` is ``(n,)``. (Run in a subprocess: the 1.x C
    layer terminates the interpreter on a dimension error.)

    Parameters
    ----------
    expression : str
        Source of the product.
    shape : tuple of int or None
        Expected shape of the result; ``None`` for the inner product (a float).
    """

    code = (
        "import numpy as np, pyoti.real as real\n"
        "rng = np.random.default_rng(1)\n"
        "mdata, xdata, ydata, zdata = (rng.standard_normal(s) for s in ((3, 4), (4,), (4,), (3,)))\n"
        "matrix, x, y, z = (real.array(a) for a in (mdata, xdata, ydata, zdata))\n"
        "result = %s\n"
        "expected = %s\n"
        "shape = %r\n"
        "if shape is None:\n"
        "    assert isinstance(result, float) and abs(result - expected) < 1e-12, result\n"
        "else:\n"
        "    assert result.shape == shape, result.shape\n"
        "    assert np.allclose(result.to_numpy(), expected)\n"
        % (expression, {"real.dot(x, y)": "xdata @ ydata", "real.dot(matrix, x)": "mdata @ xdata",
                        "real.dot(z, matrix)": "zdata @ mdata"}[expression], shape)
    )
    process = _isolated(code)

    assert process.returncode == 0, process.stdout + process.stderr

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_the_column_idiom_still_works():
    """
    Row 8: ``dot(x.T, y)`` on ``(n, 1)`` columns still gives a ``(1, 1)`` matrix.
    """

    x, xdata = _make((4, 1), 1)
    y, ydata = _make((4, 1), 2)
    result = real.dot(real.transpose(x), y)

    assert result.shape == (1, 1)
    assert result.to_numpy()[0, 0] == pytest.approx((xdata.T @ ydata)[0, 0])

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@PENDING
def test_sparse_and_dmat_agree_on_shapes():
    """
    11.9: ``matso op dmat`` agrees on shapes after the switch: a 1-D ``dmat`` and a 1-D ``matso`` of the
    same length add elementwise and give a 1-D result.
    """

    matrix, data = _make((5,), 1)
    sparse_array = sp.array(np.arange(5.0))
    result = sparse_array + matrix

    assert result.shape == (5,)
    np.testing.assert_allclose(np.array(result.real), np.arange(5.0) + data)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@PENDING
def test_sparse_row_and_dmat_row_have_the_same_shape():
    """
    11.9: the row of a ``matso`` and the row of a ``dmat`` built from the same data have the same shape
    ``(ncols,)``, so paired code compares like with like.
    """

    data = np.arange(12.0).reshape(3, 4)

    assert sp.array(data)[1].shape == real.array(data)[1].shape == (4,)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_dmatfe_keeps_the_matrix_rule():
    """
    Row 1 / 11.8 (A5): ``dmatfe`` keeps the matrix rule: ``G[i]`` is ``(1, ncols)``, ``G[:, j]`` is
    ``(nrows, 1)``, ``G[i, j]`` is a ``dnumfe``, ``get_ip`` returns an ``(nrows, ncols)`` matrix.
    """

    gauss = real.dmatfe((2, 3), nip=4)

    assert gauss[0].shape == (1, 3)
    assert gauss[1, :].shape == (1, 3)
    assert gauss[:, 2].shape == (2, 1)
    assert isinstance(gauss[1, 2], real.dnumfe)
    assert gauss.get_ip(0).shape == (2, 3)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@PENDING
def test_dmatfe_negative_indices_work():
    """
    Row 1 / 11.8: negative indices work in Gauss arrays of every algebra, ``dmatfe`` included:
    ``G[-1, -1]`` is a ``dnumfe`` and ``G[-1]`` is ``(1, ncols)``.
    """

    gauss = real.dmatfe((2, 3), nip=4)

    assert isinstance(gauss[-1, -1], real.dnumfe)
    assert gauss[-1].shape == (1, 3)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_dmatfe_three_index_keys_raise():
    """
    11.8: a 3-index key raises ``IndexError`` (use ``get_ip``).
    """

    gauss = real.dmatfe((2, 3), nip=4)

    with pytest.raises(IndexError):

        gauss[(0, 0, 0)]

    # end with

# end function
# --------------------------------------------------------------------------------------------------------
