"""
Check the real ndarray BLAS and linear algebra (Phase 3) through ``pyoti.real._ndtest``, NumPy and SciPy
as the oracles.

Products (``matmul``, ``dot``, ``gemm``, ``gemv``, ``ger``) over random strided operands (negative and
zero strides, F order, padded leading dimensions, zero-size dimensions, batches), the level-1 helpers on
negative-, zero- and odd-strided vectors, and tier-1 linear algebra: ``solve``, ``inv``, ``det``,
``slogdet`` (exactly singular matrices, badly scaled ones, stacks, empty matrices), ``cholesky``,
``cho_solve`` and ``solve_triangular`` with every flag combination. Written from the contracts (sections
9.1-9.5, 10) and the documented handle, not from the implementation.

Results of a BLAS call agree with NumPy to rounding (the summation order is the library's); the
tolerances scale with the magnitude of the terms of each product.
"""

import itertools

import numpy as np
import pytest

import pyoti.real as real


ND = getattr(real, "_ndtest", None)

pytestmark = pytest.mark.skipif(ND is None, reason="pyoti.real._ndtest is not built")

SPECIALS = [np.nan, np.inf, -np.inf, 0.0, -0.0, 1.0, -1.0]


# ********************************************************************************************************
@pytest.fixture(autouse=True)
def _quiet_and_clean():
    """
    Silence NumPy floating point warnings and restore the handle's context after every test.
    """

    with np.errstate(all="ignore"):

        yield

    # end with

    ND.set_limits()
    ND.fail_alloc(0)
    ND.clear_error()

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

        nan_a = np.atleast_1d(np.isnan(actual))
        assert np.array_equal(nan_a, np.atleast_1d(np.isnan(expected))), msg
        left = np.atleast_1d(actual)[~nan_a]
        right = np.atleast_1d(expected)[~nan_a]
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
def _fill(rng, shape, kind="normal", specials=0.0):
    """
    Random float64 values.

    Parameters
    ----------
    rng : numpy.random.Generator
        Random generator.
    shape : tuple of int
        Shape.
    kind : str
        ``normal``, ``positive`` (1 to 2), ``unit`` (-1 to 1), ``ints`` (small integers: many ties),
        ``wide`` (mixed magnitudes).
    specials : float
        Probability of replacing an element by NaN, an infinity or a signed zero.

    Returns
    -------
    numpy.ndarray
        C-contiguous array.
    """

    n = int(np.prod(shape, dtype=np.int64))

    if kind == "positive":

        out = rng.uniform(1.0, 2.0, n)

    elif kind == "unit":

        out = rng.uniform(-1.0, 1.0, n)

    elif kind == "ints":

        out = rng.integers(-3, 4, n).astype(np.float64)

    elif kind == "wide":

        out = rng.standard_normal(n) * 10.0 ** rng.integers(-8, 9, n)

    else:

        out = rng.standard_normal(n)

    # end if

    if specials > 0.0 and n > 0:

        hit = rng.random(n) < specials
        out[hit] = rng.choice(SPECIALS, int(hit.sum()))

    # end if

    return out.reshape(shape)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _rand_view(rng, shape, kind="normal", specials=0.0):
    """
    A random writeable strided view of ``shape`` over a larger base array, plus a function that builds
    the same view over another array of the base's shape (to compute the expected base with canaries).

    Parameters
    ----------
    rng : numpy.random.Generator
        Random generator.
    shape : tuple of int
        Shape of the view.
    kind : str
        Value kind of the base (see _fill).
    specials : float
        Probability of special values in the base.

    Returns
    -------
    tuple
        ``(base, view, maker)`` with ``view = maker(base)``.
    """

    nd = len(shape)
    perm = [int(k) for k in rng.permutation(nd)]
    pshape = tuple(shape[p] for p in perm)
    big = tuple(3 * s + 2 for s in pshape)
    base = _fill(rng, big, kind, specials)
    base = np.asfortranarray(base) if rng.random() < 0.3 else base
    steps = [int(x) for x in rng.choice([1, 1, 2, -1, -2, 3], nd)]
    slices = []

    for ax in range(nd):

        s, n, st = pshape[ax], big[ax], steps[ax]

        if st > 0:

            start = int(rng.integers(0, n - st * max(s - 1, 0)))
            slices.append(slice(start, start + st * s, st))

        else:

            start = int(rng.integers(-st * max(s - 1, 0), n))
            stop = start + st * s
            slices.append(slice(start, stop if stop >= 0 else None, st))

    # end for

        # end if

    inv = [int(k) for k in np.argsort(perm)] if nd else []

    def maker(arr):

        return arr[tuple(slices)].transpose(inv) if nd else arr[()].reshape(())

    # end def

    view = maker(base)

    if nd == 0:

        base = np.asarray(base).reshape(())
        view = base

        def maker(arr):

            return arr

    # end if

        # end def

    assert view.shape == shape
    return base, view, maker

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _place(rng, mat):
    """
    Copy a matrix (or a stack) into a random strided view: C, F, sliced, reversed or transposed storage.

    Parameters
    ----------
    rng : numpy.random.Generator
        Random generator.
    mat : numpy.ndarray
        Values.

    Returns
    -------
    numpy.ndarray
        Writeable strided array holding the values.
    """

    pick = rng.random()

    if pick < 0.25:

        return mat.copy()

    elif pick < 0.45:

        return np.asfortranarray(mat)

    # end if

    view = _rand_view(rng, mat.shape)[1]
    view[...] = mat
    return view

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _tol(a, b, k):
    """
    Absolute tolerance of a product of ``k`` terms.

    Parameters
    ----------
    a : numpy.ndarray
        Left operand.
    b : numpy.ndarray
        Right operand.
    k : int
        Inner dimension.

    Returns
    -------
    float
        ``1e-12`` times the magnitude of the largest possible sum of absolute terms (at least 1e-300).
    """

    ma = float(np.max(np.abs(a))) if np.size(a) else 0.0
    mb = float(np.max(np.abs(b))) if np.size(b) else 0.0
    return 1e-12 * max(ma * mb * max(k, 1), 1e-300)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_matmul_random_layouts_and_empty_sizes():
    """
    ``matmul`` of random strided matrices (negative strides, F order, zero-size dimensions) equals NumPy.
    """

    rng = np.random.default_rng(60)

    for _ in range(300):

        m, k, n = [int(x) for x in rng.integers(0, 7, 3)]
        a = _place(rng, _fill(rng, (m, k)))
        b = _place(rng, _fill(rng, (k, n)))
        res = ND.matmul(a, b)
        expected = a @ b
        assert res.shape == (m, n)
        np.testing.assert_allclose(res, expected, rtol=1e-12, atol=_tol(a, b, k))

    # end for

    a = np.zeros((3, 0))
    b = np.zeros((0, 4))
    _same(ND.matmul(a, b), np.zeros((3, 4)))

    # a broadcast (zero stride) read-only operand
    row = _fill(rng, (1, 5))
    a = np.broadcast_to(row, (4, 5))
    b = _fill(rng, (5, 3))
    np.testing.assert_allclose(ND.matmul(a, b), a @ b, rtol=1e-12, atol=_tol(a, b, 5))

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_matmul_vectors_batches_and_errors():
    """
    1-D promotion, batch broadcasting, and the SHAPE / DTYPE errors of ``matmul``.
    """

    rng = np.random.default_rng(61)
    v = _fill(rng, 5)
    w = _fill(rng, 5)
    m = _fill(rng, (5, 3))
    n = _fill(rng, (4, 5))

    np.testing.assert_allclose(ND.matmul(v, w), v @ w, rtol=1e-12)
    assert ND.matmul(v, w).shape == ()
    np.testing.assert_allclose(ND.matmul(v, m), v @ m, rtol=1e-12)
    np.testing.assert_allclose(ND.matmul(n, v), n @ v, rtol=1e-12)
    assert ND.matmul(v, m).shape == (3,) and ND.matmul(n, v).shape == (4,)

    for sa, sb in (((2, 3, 4), (4, 5)), ((3, 4), (2, 4, 5)), ((2, 1, 3, 4), (5, 4, 6)),
                   ((2, 3, 4), (2, 4, 5)), ((1, 3, 4), (6, 4, 2)), ((4,), (3, 4, 2)), ((3, 4, 5), (5,)),
                   ((0, 3, 4), (0, 4, 2)), ((2, 3, 0), (2, 0, 4))):

        a = _place(rng, _fill(rng, sa))
        b = _place(rng, _fill(rng, sb))
        res = ND.matmul(a, b)
        expected = np.matmul(a, b)
        assert res.shape == expected.shape, (sa, sb)
        np.testing.assert_allclose(res, expected, rtol=1e-12, atol=_tol(a, b, sa[-1]))

    # end for

    with pytest.raises(ValueError):

        ND.matmul(np.array(2.0), m)

    # end with

    with pytest.raises(ValueError):

        ND.matmul(m, np.array(2.0))

    # end with

    with pytest.raises(ValueError):

        ND.matmul(m, m)

    # end with

    with pytest.raises(ValueError):

        ND.matmul(_fill(rng, (2, 3, 4)), _fill(rng, (3, 4, 5)))

    # end with

    with pytest.raises(TypeError):

        ND.matmul(np.ones((2, 2), dtype=np.int64), np.ones((2, 2), dtype=np.int64))

    # end with

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_matmul_to_with_guard_regions_and_overlapping_outputs():
    """
    ``matmul_to`` into random strided outputs does not write outside the output; an output that is, or
    overlaps, an input is computed through a temporary as ``numpy.matmul(a, b, out=a)`` does.
    """

    rng = np.random.default_rng(62)

    for _ in range(150):

        m, k, n = [int(x) for x in rng.integers(0, 6, 3)]
        a = _place(rng, _fill(rng, (m, k)))
        b = _place(rng, _fill(rng, (k, n)))
        base, out, maker = _rand_view(rng, (m, n))
        exp_base = base.copy()
        maker(exp_base)[...] = a @ b
        before = base.copy()
        ND.matmul_to(a, b, out)
        marker = np.zeros_like(base)
        maker(marker)[...] = 1.0
        np.testing.assert_array_equal(base[marker == 0.0], before[marker == 0.0])
        np.testing.assert_allclose(out, a @ b, rtol=1e-12, atol=_tol(a, b, k))

    # end for

    for _ in range(40):

        n = int(rng.integers(1, 6))
        a = _fill(rng, (n, n))
        b = _fill(rng, (n, n))
        expected = a @ b
        ND.matmul_to(a, b, a)
        np.testing.assert_allclose(a, expected, rtol=1e-12, atol=1e-12 * n)

        a = _fill(rng, (n, n))
        b = _fill(rng, (n, n))
        expected = a @ b
        ND.matmul_to(a, b, b)
        np.testing.assert_allclose(b, expected, rtol=1e-12, atol=1e-12 * n)

        a = _fill(rng, (n, n))
        expected = a @ a.T
        ND.matmul_to(a, a.T, a)
        np.testing.assert_allclose(a, expected, rtol=1e-12, atol=1e-12 * n)

    # end for

    big = _fill(rng, (8, 5))
    expected = big.copy()
    expected[2:5] = big[:3] @ _fill(np.random.default_rng(1), (5, 5))
    other = _fill(np.random.default_rng(1), (5, 5))
    ND.matmul_to(big[:3], other, big[2:5])
    np.testing.assert_allclose(big, expected, rtol=1e-12, atol=1e-12)

    with pytest.raises(ValueError):

        ND.matmul_to(np.ones((2, 3)), np.ones((3, 4)), np.zeros((2, 5)))

    # end with

    ro = np.zeros((2, 4))
    ro.flags.writeable = False

    with pytest.raises(ValueError):

        ND.matmul_to(np.ones((2, 3)), np.ones((3, 4)), ro)

    # end with

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_dot_up_to_two_dimensions():
    """
    ``dot`` of 0-D, 1-D and 2-D operands equals NumPy; an N-D operand is a ValueError; ``dot_to`` with an
    overlapping output works.
    """

    rng = np.random.default_rng(63)
    shapes = [(), (4,), (3, 4), (4, 3), (1, 4), (4, 1), (0,), (3, 0), (0, 3)]

    for sa, sb in itertools.product(shapes, shapes):

        a = _place(rng, _fill(rng, sa))
        b = _place(rng, _fill(rng, sb))

        try:

            expected = np.dot(a, b)

        except ValueError:

            with pytest.raises(ValueError):

                ND.dot(a, b)

            # end with

            continue

        # end try

        res = ND.dot(a, b)
        assert res.shape == np.shape(expected), (sa, sb)
        np.testing.assert_allclose(res, expected, rtol=1e-12, atol=_tol(a, b, max(sa[-1:] + (1,))))

    # end for

    with pytest.raises(ValueError):

        ND.dot(np.ones((2, 2, 2)), np.ones((2, 2)))

    # end with

    a = _fill(rng, (4, 4))
    b = _fill(rng, (4, 4))
    expected = a @ b
    ND.dot_to(a, b, a)
    np.testing.assert_allclose(a, expected, rtol=1e-12, atol=1e-11)

    out = np.zeros(())
    ND.dot_to(np.arange(4.0), np.arange(4.0), out)
    assert out == 14.0

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("transb", [False, True])
@pytest.mark.parametrize("transa", [False, True])
def test_gemm_every_layout_and_scalar_combination(transa, transb):
    """
    ``gemm`` of C / F / sliced / reversed / transposed operands and outputs, with padded leading
    dimensions, ``alpha`` / ``beta`` of every kind; ``beta == 0`` does not read a NaN output.

    Parameters
    ----------
    transa : bool
        Use a transposed.
    transb : bool
        Use b transposed.
    """

    rng = np.random.default_rng(64)

    for _ in range(250):

        m, k, n = [int(x) for x in rng.integers(0, 6, 3)]
        a = _place(rng, _fill(rng, (k, m) if transa else (m, k)))
        b = _place(rng, _fill(rng, (n, k) if transb else (k, n)))
        c = _place(rng, _fill(rng, (m, n)))
        alpha = float(rng.choice([0.0, 1.0, -1.0, 2.5]))
        beta = float(rng.choice([0.0, 1.0, -0.5, 3.0]))

        if beta == 0.0 and rng.random() < 0.5:

            c[...] = np.nan

        # end if

        opa = a.T if transa else a
        opb = b.T if transb else b
        prod = alpha * (opa @ opb)
        expected = prod if beta == 0.0 else prod + beta * c
        res = ND.gemm(a, b, c, alpha=alpha, beta=beta, transa=transa, transb=transb)
        assert res is c
        scale = float(np.max(np.abs(expected))) if expected.size else 0.0
        atol = _tol(opa, opb, k) * max(abs(alpha), 1.0) + 1e-12 * abs(beta) * scale
        np.testing.assert_allclose(c, expected, rtol=1e-12, atol=atol)

    # end for

    # a zero-stride (broadcast) first operand, and k == 0 with beta == 0 over NaN
    row = _fill(rng, (1, 4))
    a = np.broadcast_to(row, (3, 4))
    b = _fill(rng, (4, 2))
    c = np.zeros((3, 2))
    ND.gemm(a if not transa else a.T.copy().T, b if not transb else b.T.copy().T, c,
            transa=False, transb=False)
    np.testing.assert_allclose(c, a @ b, rtol=1e-12, atol=1e-12)
    c = np.full((3, 2), np.nan)
    ND.gemm(np.zeros((3, 0)), np.zeros((0, 2)), c, beta=0.0)
    assert not c.any()
    c = np.full((3, 2), 2.0)
    ND.gemm(np.zeros((3, 0)), np.zeros((0, 2)), c, beta=0.5)
    np.testing.assert_array_equal(c, np.full((3, 2), 1.0))

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_gemm_shape_overlap_and_readonly_errors():
    """
    ``gemm`` rejects mismatched shapes, a read-only ``c`` and a ``c`` that overlaps an input.
    """

    a = np.ones((3, 4))
    b = np.ones((4, 2))

    with pytest.raises(ValueError):

        ND.gemm(a, b, np.zeros((3, 3)))

    # end with

    with pytest.raises(ValueError):

        ND.gemm(a, np.ones((3, 2)), np.zeros((3, 2)))

    # end with

    with pytest.raises(ValueError):

        ND.gemm(np.ones(4), b, np.zeros((3, 2)))

    # end with

    ro = np.zeros((3, 2))
    ro.flags.writeable = False

    with pytest.raises(ValueError):

        ND.gemm(a, b, ro)

    # end with

    sq = np.ones((3, 3))

    with pytest.raises(ValueError):

        ND.gemm(sq, sq, sq)

    # end with

    big = np.ones((6, 3))

    with pytest.raises(ValueError):

        ND.gemm(big[:3], sq, big[2:5])

    # end with

    with pytest.raises(TypeError):

        ND.gemm(np.ones((2, 2), dtype=np.int64), np.ones((2, 2)), np.zeros((2, 2)))

    # end with

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("trans", [False, True])
def test_gemv_and_ger(trans):
    """
    ``gemv`` with C and F matrices and strided or reversed vectors, and ``ger`` into C and F matrices.

    Parameters
    ----------
    trans : bool
        Use the matrix transposed in ``gemv``.
    """

    rng = np.random.default_rng(65)

    for _ in range(200):

        m, n = [int(x) for x in rng.integers(0, 7, 2)]
        a = _place(rng, _fill(rng, (m, n)))
        op = a.T if trans else a
        x = _place(rng, _fill(rng, (op.shape[1],)))
        y = _place(rng, _fill(rng, (op.shape[0],)))
        alpha = float(rng.choice([0.0, 1.0, -2.0]))
        beta = float(rng.choice([0.0, 1.0, 0.5]))
        expected = alpha * (op @ x) + (beta * y if beta != 0.0 else 0.0)

        if beta == 0.0:

            y[...] = np.nan

        # end if

        ND.gemv(a, x, y, alpha=alpha, beta=beta, trans=trans)
        np.testing.assert_allclose(y, expected, rtol=1e-12, atol=_tol(op, x, op.shape[1]) + 1e-12)

        x = _place(rng, _fill(rng, (m,)))
        z = _place(rng, _fill(rng, (n,)))
        mat = _place(rng, _fill(rng, (m, n)))
        expected = mat + alpha * np.outer(x, z)
        ND.ger(x, z, mat, alpha=alpha)
        np.testing.assert_allclose(mat, expected, rtol=1e-12, atol=1e-12)

    # end for

    with pytest.raises(ValueError):

        ND.gemv(np.ones((3, 4)), np.ones(3), np.zeros(3))

    # end with

    with pytest.raises(ValueError):

        ND.ger(np.ones(3), np.ones(4), np.zeros((4, 3)))

    # end with

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_level_one_with_negative_zero_and_odd_strides():
    """
    ``vdot / axpy / scal / nrm2 / asum / iamax`` on contiguous, strided, reversed and zero-stride vectors.
    """

    rng = np.random.default_rng(66)

    for _ in range(200):

        n = int(rng.integers(0, 9))
        x = _place(rng, _fill(rng, (n,)))
        y = _place(rng, _fill(rng, (n,)))
        mag = max(float(np.abs(x) @ np.abs(y)), 1e-300)
        assert abs(ND.vdot(x, y) - float(np.dot(x, y))) <= 1e-12 * mag
        assert abs(ND.nrm2(x) - float(np.linalg.norm(x))) <= 1e-12 * max(float(np.linalg.norm(x)), 1e-300)
        assert abs(ND.asum(x) - float(np.abs(x).sum())) <= 1e-12 * max(float(np.abs(x).sum()), 1e-300)
        assert ND.iamax(x) == (int(np.argmax(np.abs(x))) if n else -1)

        alpha = float(rng.choice([0.0, 1.0, -3.0]))
        expected = y + alpha * x
        ND.axpy(alpha, x, y)
        np.testing.assert_allclose(y, expected, rtol=1e-12, atol=1e-12)
        expected = alpha * x
        ND.scal(alpha, x)
        np.testing.assert_allclose(x, expected, rtol=1e-12, atol=1e-300)

    # end for

    zero = np.broadcast_to(np.array(2.0), (5,))
    other = _fill(rng, 5)
    assert abs(ND.vdot(zero, other) - 2.0 * other.sum()) < 1e-12
    assert abs(ND.nrm2(zero) - np.sqrt(20.0)) < 1e-12
    assert ND.iamax(np.array([1.0, -3.0, 3.0, 2.0])) == 1
    empty = np.zeros(0)
    assert ND.nrm2(empty) == 0.0 and ND.asum(empty) == 0.0 and ND.vdot(empty, empty) == 0.0

    with pytest.raises(ValueError):

        ND.vdot(np.ones(3), np.ones(4))

    # end with

    with pytest.raises(ValueError):

        ND.vdot(np.ones((2, 2)), np.ones((2, 2)))

    # end with

    with pytest.raises(ValueError):

        ND.axpy(1.0, np.ones(3), np.ones(4))

    # end with

    ro = np.ones(3)
    ro.flags.writeable = False

    with pytest.raises(ValueError):

        ND.scal(2.0, ro)

    # end with

    big = np.ones(8)

    with pytest.raises(ValueError):

        ND.axpy(1.0, big[:5], big[2:7])

    # end with

    with pytest.raises(ValueError):

        ND.axpy(1.0, big, big)

    # end with

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _well_conditioned(rng, n, batch=()):
    """
    Random well-conditioned square matrices (diagonally dominant), possibly a stack.

    Parameters
    ----------
    rng : numpy.random.Generator
        Random generator.
    n : int
        Order.
    batch : tuple of int
        Leading (batch) shape.

    Returns
    -------
    numpy.ndarray
        Array of shape ``batch + (n, n)``.
    """

    a = rng.standard_normal(batch + (n, n))
    return a + 2.0 * n * np.eye(n)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_solve_against_numpy():
    """
    ``solve`` for C, F, strided and stacked matrices, vector and matrix right-hand sides (NumPy 2 rules),
    empty systems and ``k = 0`` right-hand sides.
    """

    rng = np.random.default_rng(70)

    for _ in range(200):

        n = int(rng.integers(0, 7))
        batch = tuple(int(x) for x in rng.integers(1, 4, int(rng.integers(0, 3))))
        a = _place(rng, _well_conditioned(rng, n, batch))
        k = int(rng.integers(0, 4))
        kind = rng.integers(0, 3)

        if kind == 0 and not batch:

            b = _place(rng, _fill(rng, (n,)))

        else:

            b = _place(rng, _fill(rng, batch + (n, k)))

        # end if

        res = ND.solve(a, b)
        expected = np.linalg.solve(a, b)
        assert res.shape == expected.shape
        np.testing.assert_allclose(res, expected, rtol=1e-10, atol=1e-10)

    # end for

    # the broadcast of the batch axes of a and b
    a = _well_conditioned(rng, 3, (2, 1))
    b = _fill(rng, (4, 3, 2))
    np.testing.assert_allclose(ND.solve(a, b), np.linalg.solve(a, b), rtol=1e-10, atol=1e-10)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_solve_inv_errors_and_exact_singularity():
    """
    An exactly singular matrix is a LinAlgError for ``solve`` and ``inv``; shape and dtype errors are
    ValueError / TypeError; the input is not modified.
    """

    singular = np.array([[1.0, 2.0, 3.0], [0.0, 0.0, 0.0], [4.0, 5.0, 6.0]])
    keep = singular.copy()

    with pytest.raises(np.linalg.LinAlgError):

        ND.solve(singular, np.ones(3))

    # end with

    with pytest.raises(np.linalg.LinAlgError):

        ND.inv(singular)

    # end with

    np.testing.assert_array_equal(singular, keep)

    with pytest.raises(np.linalg.LinAlgError):

        ND.inv(np.zeros((2, 2)))

    # end with

    for fn in (ND.inv, ND.det):

        with pytest.raises(ValueError):

            fn(np.ones((2, 3)))

        # end with

        with pytest.raises(ValueError):

            fn(np.ones(3))

        # end with

        with pytest.raises(TypeError):

            fn(np.ones((2, 2), dtype=np.int64))

    # end for

        # end with

    with pytest.raises(ValueError):

        ND.solve(np.eye(3), np.ones(4))

    # end with

    with pytest.raises(ValueError):

        ND.solve(np.ones((2, 3)), np.ones(2))

    # end with

    # a stack with one singular matrix fails
    stack = np.stack([np.eye(2), np.zeros((2, 2))])

    with pytest.raises(np.linalg.LinAlgError):

        ND.inv(stack)

    # end with

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_inv_against_numpy_and_orientation():
    """
    ``inv`` of C, F, strided, stacked and empty matrices equals NumPy, leaves the input untouched, and a
    C-ordered input gives a C-ordered inverse (no transpose pass).
    """

    rng = np.random.default_rng(71)

    for _ in range(200):

        n = int(rng.integers(0, 7))
        batch = tuple(int(x) for x in rng.integers(1, 4, int(rng.integers(0, 3))))
        a = _place(rng, _well_conditioned(rng, n, batch))
        before = a.copy()
        res = ND.inv(a)
        expected = np.linalg.inv(a)
        assert res.shape == expected.shape
        np.testing.assert_allclose(res, expected, rtol=1e-10, atol=1e-10)
        np.testing.assert_array_equal(a, before)

    # end for

    c = np.ascontiguousarray(_well_conditioned(rng, 5))
    assert ND.inv(c).flags.c_contiguous
    f = np.asfortranarray(_well_conditioned(rng, 5))
    np.testing.assert_allclose(ND.inv(f), np.linalg.inv(f), rtol=1e-10, atol=1e-10)
    assert ND.inv(np.zeros((0, 0))).shape == (0, 0)
    assert ND.inv(np.zeros((3, 0, 0))).shape == (3, 0, 0)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_det_and_slogdet_against_numpy():
    """
    ``det`` / ``slogdet`` of random, stacked, empty and badly scaled matrices; the sign, the log, and
    ``det`` rebuilt from ``slogdet`` so that diag(1e200, 1e200, 1e-200, 1e-200) is 1.
    """

    rng = np.random.default_rng(72)

    for _ in range(200):

        n = int(rng.integers(0, 7))
        batch = tuple(int(x) for x in rng.integers(1, 4, int(rng.integers(0, 3))))
        a = _place(rng, rng.standard_normal(batch + (n, n)))
        det = ND.det(a)
        sign, logabs = ND.slogdet(a)
        e_det = np.linalg.det(a)
        e_sign, e_log = np.linalg.slogdet(a)
        assert det.shape == e_det.shape and sign.shape == e_sign.shape and logabs.shape == e_log.shape
        np.testing.assert_allclose(det, e_det, rtol=1e-9, atol=1e-12)
        np.testing.assert_array_equal(sign, e_sign)
        np.testing.assert_allclose(logabs, e_log, rtol=1e-9, atol=1e-9)

    # end for

    assert ND.det(np.zeros((0, 0))) == 1.0
    sign, logabs = ND.slogdet(np.zeros((0, 0)))
    assert sign == 1.0 and logabs == 0.0

    scaled = np.diag([1e200, 1e200, 1e-200, 1e-200])
    np.testing.assert_allclose(ND.det(scaled), 1.0, rtol=1e-12)
    np.testing.assert_allclose(ND.det(scaled), np.linalg.det(scaled), rtol=1e-12)

    huge = np.diag([1e200, 1e200])
    sign, logabs = ND.slogdet(huge)
    assert sign == 1.0 and np.isfinite(logabs)
    np.testing.assert_allclose(logabs, 2 * np.log(1e200), rtol=1e-12)
    assert ND.det(huge) == np.linalg.det(huge)

    neg = np.array([[0.0, 1.0], [1.0, 0.0]])
    assert ND.det(neg) == -1.0
    assert ND.slogdet(neg)[0] == -1.0

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_exactly_singular_det_is_zero_without_an_error():
    """
    An exactly zero pivot gives ``det == 0`` and ``slogdet == (0, -inf)`` with no exception, while
    ``solve`` / ``inv`` raise LinAlgError; a stack mixes both kinds.
    """

    singular = np.array([[1.0, 2.0], [2.0, 4.0]])
    zero = np.zeros((3, 3))
    assert ND.det(singular) == 0.0 or abs(ND.det(singular)) < 1e-15
    assert ND.det(zero) == 0.0
    sign, logabs = ND.slogdet(zero)
    assert sign == 0.0 and logabs == -np.inf
    assert ND.det(np.array([[1.0, 2.0], [0.0, 0.0]])) == 0.0
    sign, logabs = ND.slogdet(np.array([[1.0, 2.0], [0.0, 0.0]]))
    assert sign == 0.0 and logabs == -np.inf

    stack = np.stack([np.eye(2) * 3.0, np.zeros((2, 2)), -np.eye(2)])
    np.testing.assert_allclose(ND.det(stack), [9.0, 0.0, 1.0])
    sign, logabs = ND.slogdet(stack)
    np.testing.assert_array_equal(sign, [1.0, 0.0, 1.0])
    assert logabs[1] == -np.inf

    with pytest.raises(np.linalg.LinAlgError):

        ND.solve(zero, np.ones(3))

    # end with

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_cholesky_and_cho_solve():
    """
    ``cholesky`` lower and upper of C, F and strided SPD matrices equals NumPy; a matrix that is not
    positive definite is a LinAlgError; ``cho_solve`` solves from either factor.
    """

    rng = np.random.default_rng(73)

    for _ in range(150):

        n = int(rng.integers(0, 7))
        g = rng.standard_normal((n, n))
        spd = g @ g.T + n * np.eye(n)
        a = _place(rng, spd)
        lower = ND.cholesky(a, lower=True)
        upper = ND.cholesky(a, lower=False)
        expected = np.linalg.cholesky(spd)
        assert lower.shape == (n, n)
        np.testing.assert_allclose(np.tril(lower), expected, rtol=1e-10, atol=1e-10)
        np.testing.assert_allclose(np.triu(upper), expected.T, rtol=1e-10, atol=1e-10)
        k = int(rng.integers(0, 4))
        b = _place(rng, _fill(rng, (n, k)))
        solved = np.linalg.solve(spd, b)
        np.testing.assert_allclose(ND.cho_solve(lower, b, lower=True), solved, rtol=1e-9, atol=1e-9)
        np.testing.assert_allclose(ND.cho_solve(upper, b, lower=False), solved, rtol=1e-9, atol=1e-9)

    # end for

    # the C-ordered input is read as A^T: a symmetric matrix gives the same factor either way
    spd = np.array([[4.0, 2.0], [2.0, 3.0]])
    np.testing.assert_allclose(np.tril(ND.cholesky(np.ascontiguousarray(spd))), np.linalg.cholesky(spd))
    np.testing.assert_allclose(np.tril(ND.cholesky(np.asfortranarray(spd))), np.linalg.cholesky(spd))

    with pytest.raises(np.linalg.LinAlgError):

        ND.cholesky(np.array([[1.0, 2.0], [2.0, 1.0]]))

    # end with

    with pytest.raises(np.linalg.LinAlgError):

        ND.cholesky(-np.eye(3))

    # end with

    with pytest.raises(ValueError):

        ND.cholesky(np.ones((2, 3)))

    # end with

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("unit", [False, True])
@pytest.mark.parametrize("trans", [False, True])
@pytest.mark.parametrize("lower", [False, True])
def test_solve_triangular_every_flag_combination(lower, trans, unit):
    """
    ``solve_triangular`` against SciPy for every flag combination, layouts, vector and matrix right-hand
    sides; a zero diagonal is a LinAlgError unless the diagonal is taken as unit.

    Parameters
    ----------
    lower : bool
        Lower triangular.
    trans : bool
        Solve with the transpose.
    unit : bool
        Unit diagonal (the stored diagonal is ignored).
    """

    scipy_linalg = pytest.importorskip("scipy.linalg")
    rng = np.random.default_rng(74)

    for _ in range(100):

        n = int(rng.integers(1, 7))
        t = _place(rng, rng.standard_normal((n, n)) + 3.0 * np.eye(n))
        k = int(rng.integers(0, 4))
        b = _place(rng, _fill(rng, (n, k) if rng.random() < 0.7 else (n,)))
        res = ND.solve_triangular(t, b, lower=lower, trans=trans, unit_diagonal=unit)
        expected = scipy_linalg.solve_triangular(t, b, lower=lower, trans=1 if trans else 0,
                                                 unit_diagonal=unit)
        assert res.shape == expected.shape
        np.testing.assert_allclose(res, expected, rtol=1e-9, atol=1e-9)

    # end for

    bad = np.eye(3)
    bad[1, 1] = 0.0

    if unit:

        ND.solve_triangular(bad, np.ones(3), lower=lower, trans=trans, unit_diagonal=True)

    else:

        with pytest.raises(np.linalg.LinAlgError):

            ND.solve_triangular(bad, np.ones(3), lower=lower, trans=trans, unit_diagonal=False)

    # end if

        # end with

    with pytest.raises(ValueError):

        ND.solve_triangular(np.eye(3), np.ones(4), lower=lower, trans=trans, unit_diagonal=unit)

    # end with

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_linear_algebra_leaves_inputs_and_results_independent():
    """
    Linear algebra results are fresh arrays: writing into one does not change the input, and the inputs
    of ``solve`` / ``inv`` / ``det`` are bit-identical afterwards.
    """

    rng = np.random.default_rng(75)
    a = _well_conditioned(rng, 4)
    b = _fill(rng, (4, 2))
    a0 = a.copy()
    b0 = b.copy()
    x = ND.solve(a, b)
    ND.inv(a)
    ND.det(a)
    ND.slogdet(a)
    ND.cholesky(a @ a.T)
    x[...] = 0.0
    np.testing.assert_array_equal(a, a0)
    np.testing.assert_array_equal(b, b0)

# end function
# --------------------------------------------------------------------------------------------------------
