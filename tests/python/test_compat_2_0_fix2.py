"""
The 2.0.0 compatibility rows of fix round 2 (contracts 11.2, 11.3, 11.4, 11.5 and 11.12), one test per
rule run on every algebra that must give the same answer: ``pyoti.dense``, ``pyoti.sparse``,
``pyoti.semisparse`` and ``pyoti.real`` (``dmat``).

Every test asserts the 2.0.0 behaviour and none carries an expected-failure marker: each rule landed
in the fix round 2 of the implementers (the posts in ``build-orch/w4-notes``). The row names (``F1``,
``C4``, ...) are those of the W4 reviews (``review-critic.md`` and ``review-checker.md``).
"""

import operator
import os
import subprocess
import sys

import numpy as np
import pytest

import pyoti.dense as dn
import pyoti.real as real
import pyoti.semisparse as ss
import pyoti.sparse as sp

MODULES = {"dense": dn, "sparse": sp, "semisparse": ss, "real": real}


# ********************************************************************************************************
def _algebras(names=tuple(MODULES)):
    """
    Build the algebra parameters of a test.

    Parameters
    ----------
    names : iterable of str, optional
        Names of the algebras the test runs on.

    Returns
    -------
    list of _pytest.mark.structures.ParameterSet
        One parameter per algebra, with the module as value and its name as id.
    """

    return [pytest.param(MODULES[name], id=name) for name in names]

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _arr(alg, data):
    """
    Build an array of an algebra from NumPy data.

    Parameters
    ----------
    alg : module
        Algebra module.
    data : array_like
        Real values.

    Returns
    -------
    object
        The array (a scalar for 0-D data).
    """

    return alg.array(np.array(data, dtype=float))

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _np(obj):
    """
    Copy the real part of an array or scalar into a NumPy array.

    Parameters
    ----------
    obj : object
        Array or scalar of any algebra.

    Returns
    -------
    numpy.ndarray
        The real part, writable.
    """

    return np.array(obj.real, dtype=float, copy=True)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _isolated(code):
    """
    Run a snippet in a fresh interpreter with the same import path.

    Behaviour that ends the interpreter (the 1.x ``exit`` paths of the C library) cannot be asserted
    in-process.

    Parameters
    ----------
    code : str
        Python source; it prints its verdict.

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
# F1: single-element operands broadcast to NumPy's shape in every algebra
# ********************************************************************************************************


# ********************************************************************************************************
SINGLE_ELEMENT_CASES = {
    "vector-and-one-by-one": ((4,), (1, 1)),
    "one-by-one-and-vector": ((1, 1), (4,)),
    "one-by-one-and-one": ((1, 1), (1,)),
    "one-and-scalar": ((1,), ()),
    "matrix-and-one-by-one": ((3, 4), (1, 1)),
}


# ********************************************************************************************************
@pytest.mark.parametrize("name", ["sum", "sub", "mul", "div"])
@pytest.mark.parametrize("alg, left_shape, right_shape", [
    pytest.param(module, left, right, id=f"{case}-{alg}")
    for case, (left, right) in SINGLE_ELEMENT_CASES.items() for alg, module in MODULES.items()
])
def test_single_element_operands_broadcast_to_the_numpy_shape(alg, name, left_shape, right_shape):
    """
    Check that a function of two arrays returns NumPy's shape and values when an extent is 1 (F1).

    Parameters
    ----------
    alg : module
        Algebra module.
    name : str
        Function name (``sum``, ``sub``, ``mul`` or ``div``).
    left_shape : tuple of int
        Shape of the first operand.
    right_shape : tuple of int
        Shape of the second operand.
    """

    rng = np.random.default_rng(7)
    left = rng.uniform(1.0, 2.0, left_shape)
    right = rng.uniform(1.0, 2.0, right_shape)
    ufunc = {"sum": np.add, "sub": np.subtract, "mul": np.multiply, "div": np.divide}[name]
    expected = ufunc(left, right)

    result = getattr(alg, name)(_arr(alg, left), _arr(alg, right))

    assert tuple(result.shape) == expected.shape
    np.testing.assert_allclose(_np(result), expected, rtol=1e-14)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("alg", _algebras())
@pytest.mark.parametrize("python", [operator.add, operator.sub, operator.mul, operator.truediv],
                         ids=["add", "sub", "mul", "div"])
def test_single_element_operators_broadcast_to_the_numpy_shape(alg, python):
    """
    Check that the Python operators agree with NumPy on a ``(1, 1)`` operand (F1).

    Parameters
    ----------
    alg : module
        Algebra module.
    python : callable
        Operator function; NumPy's answer is the same operator on the NumPy data.
    """

    vector = np.arange(1.0, 5.0)
    one = np.array([[2.0]])

    for left, right in ((vector, one), (one, vector), (one, np.array([3.0])), (np.array([3.0]), one)):
        result = python(_arr(alg, left), _arr(alg, right))
        expected = python(left, right)

        assert tuple(result.shape) == expected.shape
        np.testing.assert_allclose(_np(result), expected, rtol=1e-14)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("alg", _algebras(names=("dense", "sparse", "semisparse")))
def test_a_one_by_one_product_scales_a_vector(alg):
    """
    Check that ``v * dot(c.T, c)`` is a ``(1, n)`` array, as in NumPy (F1, the FEM form).

    Parameters
    ----------
    alg : module
        Algebra module.
    """

    column = np.arange(3.0).reshape(3, 1)
    vector = np.arange(1.0, 4.0)
    expected = vector * (column.T @ column)

    scale = alg.dot(alg.transpose(_arr(alg, column)), _arr(alg, column))
    result = _arr(alg, vector) * scale

    assert tuple(scale.shape) == (1, 1)
    assert tuple(result.shape) == expected.shape
    np.testing.assert_allclose(_np(result), expected, rtol=1e-14)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
# F5: dot with a 0-D operand, inv and det of a 0-D array
# ********************************************************************************************************


# ********************************************************************************************************
@pytest.mark.parametrize("alg", _algebras())
@pytest.mark.parametrize("shape", [(4,), (3, 4)], ids=["vector", "matrix"])
def test_dot_with_a_zero_dimensional_operand_multiplies(alg, shape):
    """
    Check that ``dot`` of a 0-D operand and an array multiplies, as ``numpy.dot`` does (F5).

    Parameters
    ----------
    alg : module
        Algebra module.
    shape : tuple of int
        Shape of the array operand.
    """

    data = np.arange(1.0, 1.0 + np.prod(shape)).reshape(shape)

    for left, right in ((2.0, data), (data, 2.0)):
        expected = np.dot(left, right)
        result = alg.dot(_arr(alg, left), _arr(alg, right))

        assert tuple(result.shape) == expected.shape
        np.testing.assert_allclose(_np(result), expected, rtol=1e-14)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("alg", _algebras())
@pytest.mark.parametrize("name", ["inv", "det"])
@pytest.mark.parametrize("shape, text", [
    pytest.param((), "0-dimensional array given. Array must be at least two-dimensional", id="zero-d"),
    pytest.param((4,), "1-dimensional array given. Array must be at least two-dimensional", id="one-d"),
    pytest.param((2, 3), "Last 2 dimensions of the array must be square", id="non-square"),
])
def test_inv_and_det_of_a_bad_shape_raise_linalgerror_with_numpys_text(alg, name, shape, text):
    """
    Check that ``inv`` and ``det`` of a 0-D, 1-D or non-square array raise ``LinAlgError`` (F5).

    The texts are NumPy's, one table for every algebra (``build-orch/w4-notes``, py-ss and dense).

    Parameters
    ----------
    alg : module
        Algebra module.
    name : str
        Function name.
    shape : tuple of int
        Shape of the array.
    text : str
        Message of the exception.
    """

    with pytest.raises(np.linalg.LinAlgError) as raised:
        getattr(alg, name)(_arr(alg, np.ones(shape) * 2.0))

    assert text in str(raised.value)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
# S1c: A.set(rhs) is A[...] = rhs
# ********************************************************************************************************


# ********************************************************************************************************
@pytest.mark.parametrize("alg, rhs_shape", [
    pytest.param(MODULES[alg], shape, id=f"{case}-{alg}")
    for case, shape in {"scalar": (), "one": (1,), "one-by-one": (1, 1), "row": (4,), "column": (3, 1),
                        "matrix": (3, 4)}.items()
    for alg in MODULES
])
def test_set_broadcasts_like_an_ellipsis_assignment(alg, rhs_shape):
    """
    Check that ``A.set(rhs)`` fills ``A`` exactly as ``A[...] = rhs`` does (S1c).

    Parameters
    ----------
    alg : module
        Algebra module.
    rhs_shape : tuple of int
        Shape of the right-hand side.
    """

    rhs = np.random.default_rng(3).uniform(1.0, 2.0, rhs_shape)
    expected = np.zeros((3, 4))
    expected[...] = rhs

    target = alg.zeros((3, 4))
    target.set(_arr(alg, rhs))
    other = alg.zeros((3, 4))
    other[...] = _arr(alg, rhs)

    np.testing.assert_allclose(_np(target), expected, rtol=1e-14)
    np.testing.assert_array_equal(_np(target), _np(other))

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("alg", _algebras())
def test_set_rejects_what_an_ellipsis_assignment_rejects(alg):
    """
    Check that ``A.set(rhs)`` raises ``ValueError`` for a right-hand side that does not broadcast (S1c).

    Parameters
    ----------
    alg : module
        Algebra module.
    """

    target = alg.zeros((3, 4))

    with pytest.raises(ValueError):
        target.set(_arr(alg, np.ones((2, 4))))

    with pytest.raises(ValueError):
        target[...] = _arr(alg, np.ones((2, 4)))

    np.testing.assert_array_equal(_np(target), np.zeros((3, 4)))

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
# C4 / F12: out= returns the original out
# ********************************************************************************************************


# ********************************************************************************************************
@pytest.mark.parametrize("alg", _algebras())
@pytest.mark.parametrize("holder_shape", [(4,), (1, 4)], ids=["exact", "leading-unit-axis"])
@pytest.mark.parametrize("name", ["sum", "sub", "mul", "div"])
def test_binary_functions_with_out_return_the_out(alg, name, holder_shape):
    """
    Check that ``f(a, b, out=h)`` returns ``h`` itself, also for a holder with a leading unit axis (C4).

    Parameters
    ----------
    alg : module
        Algebra module.
    name : str
        Function name.
    holder_shape : tuple of int
        Shape of the holder.
    """

    left = np.arange(1.0, 5.0)
    right = np.arange(2.0, 6.0)
    ufunc = {"sum": np.add, "sub": np.subtract, "mul": np.multiply, "div": np.divide}[name]
    expected = ufunc(left, right)
    holder = alg.zeros(holder_shape)

    result = getattr(alg, name)(_arr(alg, left), _arr(alg, right), out=holder)

    assert result is holder
    np.testing.assert_allclose(_np(holder).reshape(-1), expected, rtol=1e-14)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("name", ["sum", "mul"])
@pytest.mark.parametrize("extra", [1, 2])
def test_dense_out_with_leading_unit_axes_is_returned(name, extra):
    """
    Check that a dense ``out`` with one or two leading unit axes is the object returned (C4, S1b).

    Parameters
    ----------
    name : str
        Function name.
    extra : int
        Number of leading axes of extent 1.
    """

    left = np.arange(1.0, 5.0)
    right = np.arange(2.0, 6.0)
    holder = dn.zeros((1,) * extra + (4,))

    result = getattr(dn, name)(_arr(dn, left), _arr(dn, right), out=holder)

    assert result is holder
    np.testing.assert_allclose(_np(holder).reshape(-1), {"sum": left + right, "mul": left * right}[name])

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("alg", _algebras())
@pytest.mark.parametrize("name", ["neg", "exp"])
def test_unary_functions_with_out_return_the_out(alg, name):
    """
    Check that ``f(a, out=h)`` returns ``h`` itself and fills it (C4).

    Parameters
    ----------
    alg : module
        Algebra module.
    name : str
        Function name.
    """

    data = np.arange(1.0, 5.0)
    expected = {"neg": np.negative, "exp": np.exp}[name](data)
    holder = alg.zeros(4)

    result = getattr(alg, name)(_arr(alg, data), out=holder)

    assert result is holder
    np.testing.assert_allclose(_np(holder), expected, rtol=1e-14)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("alg", _algebras())
def test_dot_with_out_returns_the_out(alg):
    """
    Check that ``dot(a, b, out=h)`` returns ``h`` itself and fills it (C4).

    Parameters
    ----------
    alg : module
        Algebra module.
    """

    matrix = np.arange(12.0).reshape(3, 4)
    vector = np.arange(1.0, 5.0)
    holder = alg.zeros(3)

    result = alg.dot(_arr(alg, matrix), _arr(alg, vector), out=holder)

    assert result is holder
    np.testing.assert_allclose(_np(holder), matrix @ vector, rtol=1e-14)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
# C3: huge slice bounds and steps clip as NumPy, huge integer indices are IndexError
# ********************************************************************************************************

HUGE = 10 ** 100

HUGE_SLICES = {
    "step": slice(None, None, HUGE),
    "negative-step": slice(None, None, -HUGE),
    "start": slice(HUGE, None),
    "negative-start": slice(-HUGE, None),
    "stop": slice(None, HUGE),
    "negative-stop": slice(None, -HUGE),
    "both": slice(-HUGE, HUGE),
    "reversed": slice(HUGE, -HUGE, -1),
    "start-and-step": slice(HUGE, None, -HUGE),
}


# ********************************************************************************************************
@pytest.mark.parametrize("alg, key", [
    pytest.param(module, key, id=f"{case}-{alg}")
    for case, key in HUGE_SLICES.items() for alg, module in MODULES.items()
])
def test_huge_slice_bounds_and_steps_clip_like_numpy(alg, key):
    """
    Check that a slice with a bound or step beyond 64 bits reads what NumPy reads (C3).

    Parameters
    ----------
    alg : module
        Algebra module.
    key : slice
        Slice applied to a vector and, on its second axis, to a matrix.
    """

    vector = np.arange(1.0, 6.0)
    matrix = np.arange(12.0).reshape(3, 4)

    got = _arr(alg, vector)[key]
    assert tuple(got.shape) == vector[key].shape
    np.testing.assert_array_equal(_np(got), vector[key])

    got = _arr(alg, matrix)[:, key]
    assert tuple(got.shape) == matrix[:, key].shape
    np.testing.assert_array_equal(_np(got), matrix[:, key])

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("alg", _algebras())
def test_a_huge_slice_assignment_clips_like_numpy(alg):
    """
    Check that assigning through a slice with huge bounds changes what NumPy changes (C3).

    Parameters
    ----------
    alg : module
        Algebra module.
    """

    expected = np.arange(1.0, 6.0)
    expected[-HUGE:HUGE:HUGE] = 9.0
    expected[HUGE:] = 7.0

    target = _arr(alg, np.arange(1.0, 6.0))
    target[-HUGE:HUGE:HUGE] = 9.0
    target[HUGE:] = 7.0

    np.testing.assert_array_equal(_np(target), expected)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("alg", _algebras())
@pytest.mark.parametrize("index", [HUGE, -HUGE], ids=["positive", "negative"])
def test_a_huge_integer_index_is_an_index_error(alg, index):
    """
    Check that an integer index beyond 64 bits raises ``IndexError`` for a read and for a write (C3).

    Parameters
    ----------
    alg : module
        Algebra module.
    index : int
        The index.
    """

    array = _arr(alg, np.arange(1.0, 5.0))

    with pytest.raises(IndexError):
        array[index]

    with pytest.raises(IndexError):
        array[index] = 1.0

    with pytest.raises(IndexError):
        _arr(alg, np.zeros((3, 4)))[0, index]

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
# F4: the real linear algebra never exits the process
# ********************************************************************************************************


# ********************************************************************************************************
@pytest.mark.parametrize("call, error", [
    pytest.param("real.inv(real.array(np.ones((2, 3))))", "LinAlgError", id="inv"),
    pytest.param("real.det(real.array(np.ones((2, 3))))", "LinAlgError", id="det"),
    pytest.param("real.solve(real.array(np.ones((2, 3))), real.array(np.ones(2)))", "LinAlgError",
                 id="solve-non-square"),
    pytest.param("real.solve(real.array(np.eye(3)), real.array(np.ones(2)))", "ValueError",
                 id="solve-short-b"),
])
def test_real_linear_algebra_on_bad_shapes_raises_instead_of_exiting(call, error):
    """
    Check that ``real.inv``, ``det`` and ``solve`` raise NumPy's exception for bad shapes (F4).

    The 1.x C paths print "DimensionError" and exit the interpreter with status 0, so the check runs
    in a subprocess and reads the verdict from its output. A non-square matrix is a ``LinAlgError``; a
    right-hand side of the wrong length is a ``ValueError``, as in ``numpy.linalg.solve``.

    Parameters
    ----------
    call : str
        Expression evaluated in the subprocess.
    error : str
        Name of the expected exception class (the exact class, not a subclass).
    """

    code = (
        "import numpy as np\n"
        "import pyoti.real as real\n"
        "try:\n"
        f"    {call}\n"
        "except BaseException as ex:\n"
        "    print('VERDICT', type(ex).__name__)\n"
        "else:\n"
        "    print('VERDICT no error')\n"
    )

    done = _isolated(code)

    assert f"VERDICT {error}" in done.stdout, done.stdout + done.stderr

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
# F8: portable method coverage
# ********************************************************************************************************


# ********************************************************************************************************
@pytest.mark.parametrize("alg", _algebras())
@pytest.mark.parametrize("shape, new_shape", [
    pytest.param((4,), (2, 2), id="vector-to-matrix"),
    pytest.param((3, 4), (12,), id="matrix-to-vector"),
    pytest.param((3, 4), (4, 3), id="matrix-to-matrix"),
    pytest.param((3, 4), (-1, 6), id="inferred-extent"),
    pytest.param((6,), (6, 1), id="vector-to-column"),
])
def test_reshape_matches_numpy_within_two_dimensions(alg, shape, new_shape):
    """
    Check that ``reshape`` gives NumPy's shape and values in every algebra (F8).

    Parameters
    ----------
    alg : module
        Algebra module.
    shape : tuple of int
        Shape of the array.
    new_shape : tuple of int
        Requested shape.
    """

    data = np.arange(float(np.prod(shape))).reshape(shape)
    expected = data.reshape(new_shape)

    for result in (_arr(alg, data).reshape(new_shape), _arr(alg, data).reshape(*new_shape)):
        assert tuple(result.shape) == expected.shape
        np.testing.assert_array_equal(_np(result), expected)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("alg", _algebras())
def test_reshape_refuses_a_wrong_size(alg):
    """
    Check that ``reshape`` raises ``ValueError`` when the sizes differ (F8).

    Parameters
    ----------
    alg : module
        Algebra module.
    """

    with pytest.raises(ValueError):
        _arr(alg, np.arange(12.0).reshape(3, 4)).reshape(5, 3)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("alg", _algebras(names=("sparse", "semisparse", "real")))
def test_reshape_beyond_two_dimensions_is_a_value_error(alg):
    """
    Check that a ``reshape`` to three dimensions raises ``ValueError`` where the rank limit is 2 (F8).

    Parameters
    ----------
    alg : module
        Algebra module.
    """

    with pytest.raises(ValueError):
        _arr(alg, np.arange(12.0).reshape(3, 4)).reshape(2, 3, 2)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("alg", _algebras())
@pytest.mark.parametrize("shape", [(3, 4), (4,), (3, 1)], ids=["matrix", "vector", "column"])
def test_transpose_property(alg, shape):
    """
    Check that ``A.T`` has NumPy's shape and values in every algebra (F8, ``dmat`` had no ``.T``).

    Parameters
    ----------
    alg : module
        Algebra module.
    shape : tuple of int
        Shape of the array.
    """

    data = np.arange(float(np.prod(shape))).reshape(shape)
    result = _arr(alg, data).T

    assert tuple(result.shape) == data.T.shape
    np.testing.assert_array_equal(_np(result), data.T)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("alg", _algebras(names=("dense", "sparse", "semisparse")))
@pytest.mark.parametrize("right_shape", [(4,), (4, 2)], ids=["vector", "matrix"])
def test_matmul_function_matches_numpy(alg, right_shape):
    """
    Check that ``matmul`` exists in the three OTI algebras and matches ``numpy.matmul`` (F8).

    Parameters
    ----------
    alg : module
        Algebra module.
    right_shape : tuple of int
        Shape of the second operand.
    """

    left = np.arange(12.0).reshape(3, 4)
    right = np.arange(1.0, 1.0 + np.prod(right_shape)).reshape(right_shape)

    result = alg.matmul(_arr(alg, left), _arr(alg, right))

    assert tuple(result.shape) == (left @ right).shape
    np.testing.assert_allclose(_np(result), left @ right, rtol=1e-14)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("alg", _algebras())
@pytest.mark.parametrize("shape", [(5,), (2, 3)], ids=["vector", "matrix"])
def test_abs_of_an_array(alg, shape):
    """
    Check that ``abs(A)`` is the entrywise absolute value in every algebra (F8).

    Parameters
    ----------
    alg : module
        Algebra module.
    shape : tuple of int
        Shape of the array.
    """

    data = np.linspace(-2.0, 3.0, int(np.prod(shape))).reshape(shape)

    result = abs(_arr(alg, data))

    assert tuple(result.shape) == shape
    np.testing.assert_array_equal(_np(result), np.abs(data))

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("alg", _algebras(names=("dense", "sparse", "semisparse")))
def test_a_list_of_scalars_is_an_assignment_value(alg):
    """
    Check that ``A[i] = [scalar, ...]`` stores the scalars, as in dense and semi-sparse (F8).

    Parameters
    ----------
    alg : module
        Algebra module.
    """

    target = alg.zeros((2, 4), nbases=1, order=1)
    target[0] = [alg.e(1, order=1) * float(k + 1) for k in range(4)]

    np.testing.assert_array_equal(_np(target)[0], np.zeros(4))
    np.testing.assert_array_equal(_np(target.get_deriv([1]))[0], np.arange(1.0, 5.0))
    np.testing.assert_array_equal(_np(target.get_deriv([1]))[1], np.zeros(4))

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
# F13: a boolean scalar key
# ********************************************************************************************************


# ********************************************************************************************************
@pytest.mark.parametrize("alg", _algebras())
@pytest.mark.parametrize("key", [True, False], ids=["true", "false"])
def test_a_boolean_scalar_key_is_numpy_or_a_clear_index_error(alg, key):
    """
    Check that ``A[True]`` adds an axis as NumPy does, or raises an ``IndexError`` naming a boolean (F13).

    Parameters
    ----------
    alg : module
        Algebra module.
    key : bool
        The scalar key.
    """

    data = np.arange(1.0, 5.0)
    array = _arr(alg, data)

    try:
        got = array[key]
    except IndexError as ex:
        assert "bool" in str(ex).lower(), str(ex)
    else:
        assert tuple(got.shape) == data[key].shape
        np.testing.assert_array_equal(_np(got), data[key])

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
# F9: error messages are NumPy's, built from the shapes
# ********************************************************************************************************


# ********************************************************************************************************
@pytest.mark.parametrize("alg", _algebras())
def test_broadcast_error_message_names_both_shapes(alg):
    """
    Check that a rejected assignment says "could not broadcast input array from shape .. into .." (F9).

    Parameters
    ----------
    alg : module
        Algebra module.
    """

    target = _arr(alg, np.arange(4.0))

    pattern = r"could not broadcast input array from shape \(3,\s?1\) into shape \(4,\)"

    with pytest.raises(ValueError, match=pattern):
        target[:] = _arr(alg, np.ones((3, 1)))

    with pytest.raises(ValueError, match=r"from shape \(3,\s?4\) into shape \(4,\)"):
        target[:] = _arr(alg, np.ones((3, 4)))

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("alg", _algebras())
def test_index_error_message_names_the_axis_and_size(alg):
    """
    Check that an index out of range says "index i is out of bounds for axis a with size n" (F9).

    Parameters
    ----------
    alg : module
        Algebra module.
    """

    vector = _arr(alg, np.arange(4.0))
    matrix = _arr(alg, np.zeros((3, 4)))

    with pytest.raises(IndexError, match=r"index 4 is out of bounds for axis 0 with size 4"):
        vector[4]

    with pytest.raises(IndexError, match=r"index -5 is out of bounds for axis 0 with size 4"):
        vector[-5]

    with pytest.raises(IndexError, match=r"index 4 is out of bounds for axis 0 with size 4"):
        vector[4] = 1.0

    with pytest.raises(IndexError, match=r"index 3 is out of bounds for axis 0 with size 3"):
        matrix[3]

    with pytest.raises(IndexError, match=r"index 5 is out of bounds for axis 1 with size 4"):
        matrix[:, 5] = 1.0

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
# F14: the representation of a dense array
# ********************************************************************************************************


# ********************************************************************************************************
def test_str_of_a_dense_array_names_its_own_type():
    """
    Check that ``str()`` of an ``omat`` starts with ``omat<``, not ``matso<`` (F14).
    """

    assert str(dn.zeros((2, 2))).startswith("omat<")
    assert str(sp.zeros((2, 2))).startswith("matso<")

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
# F11: an empty extended slice of a real Gauss array is empty
# ********************************************************************************************************


# ********************************************************************************************************
@pytest.mark.parametrize("key, shape", [
    pytest.param((slice(0, 0, 2), slice(None)), (0, 4), id="empty-rows"),
    pytest.param((slice(None), slice(2, 2, 3)), (3, 0), id="empty-columns"),
    pytest.param((slice(0, 0, 5), slice(1, 1, 2)), (0, 0), id="both-empty"),
    pytest.param(slice(0, 0, 2), (0, 4), id="rows-only"),
    pytest.param((slice(1, 3, 2), slice(None)), (1, 4), id="one-row-is-not-empty"),
])
def test_an_empty_extended_slice_of_a_gauss_array_is_empty(key, shape):
    """
    Check that ``dmatfe[a:a:s]`` has no rows or columns, as the matching slice of a NumPy array (F11).

    Parameters
    ----------
    key : tuple of slice or slice
        Key applied to a ``(3, 4)`` Gauss array.
    shape : tuple of int
        Shape of the result.
    """

    gauss = real.dmatfe((3, 4), nip=2)
    result = gauss[key]

    assert tuple(result.shape) == shape
    assert np.zeros((3, 4))[key].shape == shape

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("alg", _algebras())
@pytest.mark.parametrize("name", ["sum", "sub", "mul", "div"])
def test_functions_of_one_dimensional_arrays_stay_one_dimensional(alg, name):
    """
    Check that ``f(x, y)`` of two ``(n,)`` arrays is ``(n,)``, not ``(n, 1)`` (F8, the ``dmat`` results).

    Parameters
    ----------
    alg : module
        Algebra module.
    name : str
        Function name.
    """

    left = np.arange(1.0, 5.0)
    right = np.arange(2.0, 6.0)

    result = getattr(alg, name)(_arr(alg, left), _arr(alg, right))

    assert tuple(result.shape) == (4,)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_erf_of_a_dmat_is_the_error_function():
    """
    Check that ``pyoti.sparse.erf`` of a ``dmat`` is ``erf`` (it computed ``cos``, F8).
    """

    from scipy.special import erf

    data = np.linspace(-1.0, 1.0, 4)

    result = sp.erf(real.array(data))

    assert tuple(result.shape) == (4,)
    np.testing.assert_allclose(_np(result), erf(data), atol=1e-15)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("key", [
    pytest.param((slice(None), True), id="colon-true"),
    pytest.param((True, [0, 1]), id="true-list"),
    pytest.param((Ellipsis, True), id="ellipsis-true"),
])
def test_dense_boolean_scalar_keys_inside_a_tuple_match_numpy(key):
    """
    Check that a boolean scalar inside a key adds an axis of extent 1, as in NumPy (F13, dense).

    Parameters
    ----------
    key : tuple
        Key applied to a ``(3, 4)`` array.
    """

    data = np.arange(12.0).reshape(3, 4)
    got = _arr(dn, data)[key]

    assert tuple(got.shape) == data[key].shape
    np.testing.assert_array_equal(_np(got), data[key])

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_dense_boolean_scalar_assignment_writes_the_whole_array():
    """
    Check that ``A[True] = v`` writes every entry and ``A[False] = v`` none (F13, dense).
    """

    data = np.arange(12.0).reshape(3, 4)
    target = _arr(dn, data)

    target[False] = 5.0
    np.testing.assert_array_equal(_np(target), data)

    target[True] = 5.0
    np.testing.assert_array_equal(_np(target), np.full((3, 4), 5.0))

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_dense_index_arrays_that_do_not_broadcast_are_an_index_error():
    """
    Check that ``A[[0, 1], [0, 1, 2]]`` raises ``IndexError`` "shape mismatch", as NumPy does (F9, dense).
    """

    target = _arr(dn, np.zeros((3, 4)))

    with pytest.raises(IndexError, match="shape mismatch"):
        target[[0, 1], [0, 1, 2]]

# end function
# --------------------------------------------------------------------------------------------------------
