"""
Compare the real ndarray operations (creators, views, elementwise, masks, reductions) with NumPy 2.

Everything goes through the private handle ``pyoti.real._ndtest`` and is checked against NumPy as the
oracle, with randomized shapes and strides: negative and zero strides, rank 0, size 0, F order and the
dense SoA block layout (nblocks, *S) with F order inside a block. The tests are written from the
contracts (PLAN-ndarray-contracts.md sections 1-4, 5.4, 10) and the documented handle, not from the
implementation.

Where the contracts promise bit-identical results (arithmetic, comparisons, masks, ``sum`` of a
contiguous vector of at most 4096 elements, the pairwise block sum, the thread count not changing a
bit) the tests compare bits; for libm functions they allow a few ulps; reductions over several blocks
agree to rounding. Output arguments are checked together with guard regions around them (canaries).
"""

import os
import subprocess
import sys

import numpy as np
import pytest

import pyoti.real as real


ND = getattr(real, "_ndtest", None)

pytestmark = [pytest.mark.skipif(ND is None, reason="pyoti.real._ndtest is not built"),
              pytest.mark.filterwarnings("ignore::RuntimeWarning")]

ARITH = ["add", "sub", "mul", "div"]
EXTREMA = ["maximum", "minimum"]
COMPARE = ["eq", "ne", "lt", "le", "gt", "ge"]
NP_BINARY = {"add": np.add, "sub": np.subtract, "mul": np.multiply, "div": np.divide, "pow": np.power,
             "maximum": np.maximum, "minimum": np.minimum, "eq": np.equal, "ne": np.not_equal,
             "lt": np.less, "le": np.less_equal, "gt": np.greater, "ge": np.greater_equal,
             "and": np.logical_and, "or": np.logical_or, "xor": np.logical_xor}
EXACT_FNS = {"neg": np.negative, "abs": np.abs, "sqrt": np.sqrt, "floor": np.floor, "ceil": np.ceil,
             "trunc": np.trunc, "rint": np.rint, "square": np.square, "reciprocal": np.reciprocal}
LIBM_FNS = {"cbrt": np.cbrt, "exp": np.exp, "exp2": np.exp2, "expm1": np.expm1, "log": np.log,
            "log2": np.log2, "log10": np.log10, "log1p": np.log1p, "sin": np.sin, "cos": np.cos,
            "tan": np.tan, "asin": np.arcsin, "acos": np.arccos, "atan": np.arctan, "sinh": np.sinh,
            "cosh": np.cosh, "tanh": np.tanh, "asinh": np.arcsinh, "acosh": np.arccosh,
            "atanh": np.arctanh}
REDUCTIONS = ["sum", "prod", "min", "max", "mean", "var", "std", "argmin", "argmax", "any", "all"]
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
def _equal_values(actual, expected, msg=""):
    """
    Assert equal values where NaN matches NaN and the sign of a zero is not compared.

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
    np.testing.assert_array_equal(actual, expected, err_msg=msg)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _ulps(actual, expected, k, msg=""):
    """
    Assert agreement to ``k`` ulps of the reference; NaN, infinities and exact zeros must match exactly.

    Parameters
    ----------
    actual : array_like
        Computed array.
    expected : array_like
        Reference array.
    k : int
        Allowed distance in units of ``numpy.spacing``.
    msg : str
        Context for the failure message.
    """

    actual = np.atleast_1d(np.asarray(actual, dtype=np.float64))
    expected = np.atleast_1d(np.asarray(expected, dtype=np.float64))
    assert actual.shape == expected.shape, msg
    nan_e = np.isnan(expected)
    assert np.array_equal(np.isnan(actual), nan_e), msg
    fin = np.isfinite(expected)
    assert np.array_equal(actual[~fin & ~nan_e], expected[~fin & ~nan_e]), msg
    diff = np.abs(actual[fin] - expected[fin])
    tol = k * np.spacing(np.abs(expected[fin]))
    bad = diff > tol
    worst = float(np.max(diff[bad] / np.maximum(tol[bad], 1e-320))) if bad.any() else 0.0
    assert not bad.any(), "{}: {} elements beyond {} ulp, worst {}".format(msg, int(bad.sum()), k, worst)

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
def _k_strides(shape, src_strides):
    """
    Element strides of a compact array in the K order of strides: axes sorted by decreasing |stride|
    (ties by axis index), positive compact strides.

    Parameters
    ----------
    shape : tuple of int
        Shape.
    src_strides : tuple of int
        Element strides that give the order.

    Returns
    -------
    tuple of int
        Compact strides.
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
def _estrides(arr):
    """
    Element strides of a NumPy array.

    Parameters
    ----------
    arr : numpy.ndarray
        Array.

    Returns
    -------
    tuple of int
        Strides in elements.
    """

    return tuple(s // arr.itemsize for s in arr.strides)

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
def _rand_shape(rng, max_rank=4, max_extent=5, empty=0.1):
    """
    Random shape with rank 0 .. max_rank and extents 1 .. max_extent (0 with probability ``empty``).

    Parameters
    ----------
    rng : numpy.random.Generator
        Random generator.
    max_rank : int
        Highest rank.
    max_extent : int
        Highest extent.
    empty : float
        Probability that one axis has extent 0.

    Returns
    -------
    tuple of int
        Shape.
    """

    nd = int(rng.integers(0, max_rank + 1))
    shape = [int(x) for x in rng.integers(1, max_extent + 1, nd)]

    if nd > 0 and rng.random() < empty:

        shape[int(rng.integers(0, nd))] = 0

    # end if

    return tuple(shape)

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
def _operand_shape(rng, shape):
    """
    Shape of an operand that broadcasts to ``shape``: fewer leading axes and some extents set to 1.

    Parameters
    ----------
    rng : numpy.random.Generator
        Random generator.
    shape : tuple of int
        Result shape.

    Returns
    -------
    tuple of int
        Operand shape.
    """

    drop = int(rng.integers(0, len(shape) + 1)) if shape else 0
    out = list(shape[drop:])

    for k in range(len(out)):

        if rng.random() < 0.3:

            out[k] = 1

    # end for

        # end if

    return tuple(out)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _operand(rng, shape, kind="normal", specials=0.0):
    """
    A random operand of a broadcast: a strided view, or a read-only broadcast of a smaller array.

    Parameters
    ----------
    rng : numpy.random.Generator
        Random generator.
    shape : tuple of int
        Result shape.
    kind : str
        Value kind (see _fill).
    specials : float
        Probability of special values.

    Returns
    -------
    numpy.ndarray
        Operand that broadcasts to ``shape``.
    """

    if rng.random() < 0.15 and len(shape) > 0:

        small = _rand_view(rng, _operand_shape(rng, shape), kind, specials)[1]
        return np.broadcast_to(small, shape)

    # end if

    return _rand_view(rng, _operand_shape(rng, shape), kind, specials)[1]

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("layout", ["C", "F"])
@pytest.mark.parametrize("creator", ["zeros", "ones", "empty", "full"])
def test_creators_shapes_layouts_and_values(creator, layout):
    """
    zeros / ones / empty / full over random shapes (rank 0, size 0): shape, dtype, values, flags.

    Parameters
    ----------
    creator : str
        Creator name.
    layout : str
        ``C`` or ``F``.
    """

    rng = np.random.default_rng(10)

    for _ in range(60):

        shape = _rand_shape(rng, 5, 5, 0.2)

        if creator == "full":

            value = float(rng.choice([2.5, -0.0, np.inf, 1e300]))
            res = ND.full(shape, value, layout=layout)
            expected = np.full(shape, value)

        else:

            res = getattr(ND, creator)(shape, layout=layout)
            expected = {"zeros": np.zeros, "ones": np.ones, "empty": np.empty}[creator](shape)

        # end if

        assert res.shape == shape
        assert res.dtype == np.float64
        assert res.flags.writeable

        if layout == "C":

            assert res.flags.c_contiguous

        else:

            assert res.flags.f_contiguous

        # end if

        if creator != "empty":

            _same(res, expected)

        # end if

        if res.size > 0:

            res[(0,) * len(shape)] = 3.5
            assert res.flat[0] == 3.5 or layout == "F"

    # end for

        # end if

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_creators_reject_bad_shapes():
    """
    A negative extent, rank 33 and a size that overflows int64 are ValueErrors; a budget breach is a
    MemoryError and leaves the handle usable.
    """

    with pytest.raises(ValueError):

        ND.zeros((3, -1))

    # end with

    with pytest.raises(ValueError):

        ND.zeros((1,) * 33)

    # end with

    assert ND.zeros((1,) * 32).shape == (1,) * 32

    with pytest.raises(ValueError):

        ND.zeros((2**62,))

    # end with

    with pytest.raises(ValueError):

        ND.ones((2**31, 2**31))

    # end with

    ND.set_limits(max_alloc_bytes=1000)

    with pytest.raises(MemoryError):

        ND.zeros(200)

    # end with

    assert ND.zeros(100).shape == (100,)
    ND.set_limits()
    assert ND.zeros(200).shape == (200,)

    ND.fail_alloc(1)

    with pytest.raises(MemoryError):

        ND.zeros((4, 4))

    # end with

    ND.fail_alloc(0)
    assert ND.zeros((4, 4)).shape == (4, 4)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("layout", ["C", "F"])
def test_eye(layout):
    """
    ``eye(n, m, k)`` against numpy.eye, including empty shapes and diagonals out of range.

    Parameters
    ----------
    layout : str
        ``C`` or ``F``.
    """

    rng = np.random.default_rng(11)

    for _ in range(80):

        n = int(rng.integers(0, 7))
        m = None if rng.random() < 0.3 else int(rng.integers(0, 7))
        k = int(rng.integers(-8, 9))
        res = ND.eye(n, m, k, layout=layout)
        _same(res, np.eye(n, m, k))
        assert res.flags.c_contiguous if layout == "C" else res.flags.f_contiguous

    # end for

    with pytest.raises(ValueError):

        ND.eye(-1)

    # end with

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_arange_follows_numpys_fill():
    """
    ``arange`` has NumPy's length and fill (to 1 ulp: NumPy's own loop may be compiled with FMA, the
    library's is not), and is exact in the 1e16 case where start + i * step would differ.
    """

    rng = np.random.default_rng(12)

    for _ in range(300):

        start = float(rng.uniform(-10, 10)) * 10.0 ** int(rng.integers(-3, 4))
        step = float(rng.uniform(0.01, 3)) * (1 if rng.random() < 0.5 else -1)
        stop = start + float(rng.uniform(-30, 30))
        expected = np.arange(start, stop, step)
        res = ND.arange(start, stop, step)
        assert res.shape == expected.shape
        tol = 4 * np.spacing(max(abs(start), abs(stop), 1.0))
        np.testing.assert_allclose(res, expected, rtol=0.0, atol=tol)

    # end for

    _same(ND.arange(1e16, 1e16 + 10, 1.0), np.arange(1e16, 1e16 + 10, 1.0))
    assert not (ND.arange(1e16, 1e16 + 10, 1.0) - 1e16).any()
    _ulps(ND.arange(0.0, 1.0, 0.1), np.arange(0.0, 1.0, 0.1), 1)
    _same(ND.arange(5.0, 0.0, 1.0), np.arange(5.0, 0.0, 1.0))
    _same(ND.arange(0.0, 0.0, 1.0), np.arange(0.0, 0.0, 1.0))

    for bad in ((0.0, 1.0, 0.0), (0.0, np.inf, 1.0), (np.nan, 1.0, 1.0), (0.0, 1.0, np.nan)):

        with pytest.raises(ValueError):

            ND.arange(*bad)

    # end for

        # end with

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("endpoint", [True, False])
def test_linspace_follows_numpys_formula(endpoint):
    """
    ``linspace`` against numpy.linspace to 1 ulp, including num of 0 and 1 and equal endpoints.

    Parameters
    ----------
    endpoint : bool
        Include ``stop``.
    """

    rng = np.random.default_rng(13)

    for num in [0, 1, 2, 3, 5, 10, 11, 100, 1001]:

        for _ in range(5):

            start, stop = [float(x) for x in rng.uniform(-100, 100, 2)]
            expected = np.linspace(start, stop, num, endpoint=endpoint)
            res = ND.linspace(start, stop, num, endpoint)
            assert res.shape == expected.shape
            _ulps(res, expected, 1, "linspace")

    # end for

        # end for

    _same(ND.linspace(2.0, 2.0, 7, endpoint), np.linspace(2.0, 2.0, 7, endpoint=endpoint))
    _ulps(ND.linspace(0.0, 1.0, 11, endpoint), np.linspace(0.0, 1.0, 11, endpoint=endpoint), 1)

    with pytest.raises(ValueError):

        ND.linspace(0.0, 1.0, -1, endpoint)

    # end with

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("layout", ["C", "F", "K", "A"])
def test_copy_layouts(layout):
    """
    ``copy`` of random strided views keeps values; C / F give C / F contiguity; K keeps the order of the
    source's strides with positive compact strides; A is F only for an F and not C source.

    Parameters
    ----------
    layout : str
        Layout code.
    """

    rng = np.random.default_rng(14)

    for _ in range(120):

        shape = _rand_shape(rng, 4, 5, 0.1)
        src = _rand_view(rng, shape, specials=0.1)[1]
        res = ND.copy(src, layout=layout)
        _same(res, src)
        assert res.flags.writeable

        if src.size > 0:

            assert _addr(res) != _addr(src)

        # end if

        keep = [k for k in range(res.ndim) if res.shape[k] != 1]

        if layout == "C":

            assert res.flags.c_contiguous

        elif layout == "F":

            assert res.flags.f_contiguous

        elif layout == "K" and src.size > 0:

            exp = _k_strides(shape, _estrides(src))
            assert [_estrides(res)[k] for k in keep] == [exp[k] for k in keep]

        elif layout == "K":

            pass

        else:

            if src.flags.f_contiguous and not src.flags.c_contiguous:

                assert res.flags.f_contiguous

            else:

                assert res.flags.c_contiguous

    # end for

        # end if

            # end if

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_ascontiguous_and_asfortran():
    """
    ``ascontiguous`` / ``asfortran`` return the input when it already has the layout and a copy otherwise.
    """

    rng = np.random.default_rng(15)

    for _ in range(120):

        shape = _rand_shape(rng, 4, 5, 0.1)
        src = _rand_view(rng, shape)[1]

        res, copied = ND.ascontiguous(src)
        _same(res, src)
        assert res.flags.c_contiguous
        assert copied == (not src.flags.c_contiguous)

        if not copied and src.size > 0:

            assert _addr(res) == _addr(src)

        # end if

        res, copied = ND.asfortran(src)
        _same(res, src)
        assert res.flags.f_contiguous
        assert copied == (not src.flags.f_contiguous)

        if not copied and src.size > 0:

            assert _addr(res) == _addr(src)

    # end for

        # end if

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("order", ["C", "F"])
def test_reshape_view_or_copy(order):
    """
    ``reshape`` gives NumPy's values, and a view exactly when NumPy gives one; ``view_reshape`` fails
    with ValueError otherwise.

    Parameters
    ----------
    order : str
        Index order of the reshape.
    """

    rng = np.random.default_rng(16)

    for _ in range(150):

        shape = _rand_shape(rng, 4, 5, 0.1)
        src = _rand_view(rng, shape)[1]
        size = src.size
        divs = [d for d in range(1, max(size, 1) + 1) if size % d == 0] if size else [1]
        first = int(rng.choice(divs))
        target = (first, size // first) if size else (0, 3)

        if rng.random() < 0.3:

            target = (size,)

        # end if

        expected = src.reshape(target, order=order)
        res, copied = ND.reshape(src, target, layout=order)
        _same(res, expected)
        shares = np.shares_memory(res, src) if size else False

        if size:

            assert copied == (not shares)
            assert copied == (not np.shares_memory(expected, src))

        # end if

        if copied or not size:

            if size:

                with pytest.raises(ValueError):

                    ND.view_reshape(src, target, layout=order)

            # end if

                # end with

        else:

            view = ND.view_reshape(src, target, layout=order)
            _same(view, expected)
            assert _addr(view) == _addr(expected)

    # end for

        # end if

    with pytest.raises(ValueError):

        ND.reshape(np.arange(6.0), (4,))

    # end with

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _rand_key(rng, shape):
    """
    A random basic-indexing key valid for ``shape`` (ints, slices, None, at most one Ellipsis).

    Parameters
    ----------
    rng : numpy.random.Generator
        Random generator.
    shape : tuple of int
        Shape of the indexed array.

    Returns
    -------
    tuple
        Key.
    """

    nd = len(shape)
    used = int(rng.integers(0, nd + 1))
    first = sorted(rng.choice(nd, used, replace=False).tolist()) if nd else []
    items = []

    for ax in range(nd):

        if ax not in first:

            continue

        # end if

        n = shape[ax]
        pick = rng.random()

        if pick < 0.35 and n > 0:

            items.append(int(rng.integers(-n, n)))

        else:

            a = int(rng.integers(-n - 2, n + 3)) if rng.random() < 0.7 else None
            b = int(rng.integers(-n - 2, n + 3)) if rng.random() < 0.7 else None
            c = int(rng.choice([1, 2, 3, -1, -2, -3])) if rng.random() < 0.6 else None
            items.append(slice(a, b, c))

    # end for

        # end if

    # leading axes that were skipped become full slices so that the items line up with the axes
    key = []
    it = iter(items)

    for ax in range(nd):

        if ax in first:

            key.append(next(it))

        else:

            if ax >= (max(first) + 1 if first else 0):

                break

            # end if

            key.append(slice(None))

    # end for

        # end if

    for _ in range(int(rng.integers(0, 3))):

        key.insert(int(rng.integers(0, len(key) + 1)), None)

    # end for

    if rng.random() < 0.3:

        key.insert(int(rng.integers(0, len(key) + 1)), Ellipsis)

    # end if

    return tuple(key)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_basic_indexing_views_match_numpy():
    """
    ``index`` with ints, slices (negative steps, out-of-range bounds), None and Ellipsis gives NumPy's
    shape, values, memory and writeability, and writes through the view reach the source.
    """

    rng = np.random.default_rng(17)
    done = 0

    for _ in range(600):

        shape = _rand_shape(rng, 4, 5, 0.1)
        base, src, maker = _rand_view(rng, shape)
        key = _rand_key(rng, shape)

        try:

            expected = src[key]

        except IndexError:

            with pytest.raises(IndexError):

                ND.index(src, key)

            # end with

            continue

        # end try

        res = ND.index(src, key)
        is_view = isinstance(expected, np.ndarray)
        expected = np.asarray(expected) if not is_view else expected
        done += 1
        assert res.shape == expected.shape
        _same(res, expected)
        assert res.flags.writeable == expected.flags.writeable

        if res.size > 0:

            if is_view:

                assert _addr(res) == _addr(expected)
                keep = [k for k in range(res.ndim) if res.shape[k] != 1]
                assert [res.strides[k] for k in keep] == [expected.strides[k] for k in keep]

            # end if

            exp_base = base.copy()
            maker(exp_base)[key] = 7.5
            ND.index(src, key)[...] = 7.5
            _same(base, exp_base)

    # end for

        # end if

    assert done > 300

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_basic_indexing_errors():
    """
    Out-of-range integers, too many indices, two Ellipsis and boolean keys are IndexErrors; a slice step
    of zero is a ValueError.
    """

    a = np.arange(24.0).reshape(2, 3, 4)

    for key in (2, -3, (0, 3), (0, 0, 4), (0, 0, 0, 0), (Ellipsis, Ellipsis), True, (slice(None), 7)):

        with pytest.raises(IndexError):

            ND.index(a, key)

    # end for

        # end with

    with pytest.raises(ValueError):

        ND.index(a, slice(None, None, 0))

    # end with

    with pytest.raises(IndexError):

        ND.index(np.zeros((0, 3)), 0)

    # end with

    _same(ND.index(a, (Ellipsis, 1)), a[..., 1])
    _same(ND.index(a, (None, 1, Ellipsis, None)), a[None, 1, ..., None])
    _same(ND.index(np.array(5.0), ()), np.array(5.0)[()].reshape(()))
    _same(ND.index(np.array(5.0), None), np.array(5.0)[None])

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_transpose_swapaxes_squeeze_expand_dims_match_numpy():
    """
    The axis-permuting and axis-adding views give NumPy's shapes, values and memory.
    """

    rng = np.random.default_rng(18)

    for _ in range(200):

        shape = _rand_shape(rng, 4, 4, 0.05)
        src = _rand_view(rng, shape)[1]
        nd = len(shape)

        res = ND.transpose(src)
        _same(res, src.transpose())

        if nd:

            perm = [int(k) for k in rng.permutation(nd)]
            neg = [k - nd if rng.random() < 0.5 else k for k in perm]
            _same(ND.transpose(src, neg), src.transpose(perm))
            assert ND.transpose(src, neg).flags.writeable
            a1, a2 = [int(x) for x in rng.integers(-nd, nd, 2)]
            _same(ND.swapaxes(src, a1, a2), src.swapaxes(a1, a2))

            if src.size:

                assert _addr(ND.transpose(src, neg)) == _addr(src)

        # end if

            # end if

        ones = [k for k in range(nd) if shape[k] == 1]
        _same(ND.squeeze(src), src.squeeze())

        if ones:

            count = int(rng.integers(1, len(ones) + 1))
            pick = tuple(int(k) for k in rng.choice(ones, count, replace=False))
            _same(ND.squeeze(src, pick), src.squeeze(pick))

        # end if

        n_new = int(rng.integers(1, 3))
        axes = tuple(sorted(int(k) for k in rng.choice(nd + n_new, n_new, replace=False)))
        _same(ND.expand_dims(src, axes), np.expand_dims(src, axes))

    # end for

    a = np.zeros((2, 3))

    with pytest.raises(IndexError):

        ND.swapaxes(a, 0, 2)

    # end with

    with pytest.raises(ValueError):

        ND.transpose(a, (0, 0))

    # end with

    with pytest.raises(ValueError):

        ND.squeeze(a, 0)

    # end with

    with pytest.raises(ValueError):

        ND.transpose(a, (0, 1, 2))

    # end with

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_broadcast_to_and_diagonal_are_read_only_views():
    """
    ``broadcast_to`` and ``diagonal`` give NumPy's values and are read-only, even from a writeable source.
    """

    rng = np.random.default_rng(19)

    for _ in range(150):

        shape = _rand_shape(rng, 3, 4, 0.0)
        src = _rand_view(rng, shape)[1]
        extra = tuple(int(x) for x in rng.integers(1, 4, int(rng.integers(0, 3))))
        grown = tuple(s if s != 1 or rng.random() < 0.5 else int(rng.integers(1, 5)) for s in shape)
        target = extra + grown
        res = ND.broadcast_to(src, target)
        expected = np.broadcast_to(src, target)
        _same(res, expected)
        assert not res.flags.writeable
        keep = [k for k in range(res.ndim) if res.shape[k] != 1]
        assert [res.strides[k] for k in keep] == [expected.strides[k] for k in keep] or res.size == 0

        if len(shape) >= 2:

            a1, a2 = [int(x) for x in rng.choice(len(shape), 2, replace=False)]
            off = int(rng.integers(-3, 4))
            res = ND.diagonal(src, off, a1, a2)
            _same(res, np.diagonal(src, off, a1, a2))
            assert not res.flags.writeable

    # end for

        # end if

    with pytest.raises(ValueError):

        ND.broadcast_to(np.zeros((3, 2)), (3, 3))

    # end with

    with pytest.raises(ValueError):

        ND.broadcast_to(np.zeros((3, 2)), (2,))

    # end with

    with pytest.raises(ValueError):

        ND.diagonal(np.zeros(4))

    # end with

    cases = [[(3, 1), (1, 4)], [(5,), (3, 1)], [(), (2, 3)], [(2, 1, 4), (3, 1), (1,)], [(0,), (1,)]]

    for shapes in cases:

        assert ND.broadcast_shapes(*shapes) == np.broadcast_shapes(*shapes)

    # end for

    with pytest.raises(ValueError):

        ND.broadcast_shapes((3,), (4,))

    # end with

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("op", ARITH + ["pow"])
def test_binary_arithmetic_with_broadcasting(op):
    """
    ``add / sub / mul / div`` are bit-identical to NumPy over random broadcast shapes, strides, F order,
    zero strides, rank 0 and size 0 (with NaN, infinities and signed zeros); ``pow`` agrees to 1 ulp.

    Parameters
    ----------
    op : str
        Operation name.
    """

    rng = np.random.default_rng(20)
    fn = NP_BINARY[op]

    for _ in range(250):

        shape = _rand_shape(rng, 4, 5, 0.08)
        a = _operand(rng, shape, specials=0.12)
        b = _operand(rng, shape, specials=0.12)
        expected = fn(a, b)
        res = ND.binary(op, a, b)
        assert res.shape == expected.shape

        if op == "pow":

            exact_zero = (expected == 0) | ~np.isfinite(expected)
            _ulps(np.where(exact_zero, 0.0, res), np.where(exact_zero, 0.0, expected), 1, op)
            assert np.array_equal(np.atleast_1d(np.isnan(res)), np.atleast_1d(np.isnan(expected)))
            assert np.array_equal(np.atleast_1d(res == np.inf), np.atleast_1d(expected == np.inf))
            assert np.array_equal(np.atleast_1d(res == -np.inf), np.atleast_1d(expected == -np.inf))

        else:

            _same(res, expected, op)

    # end for

        # end if

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("op", EXTREMA + COMPARE)
def test_binary_extrema_and_comparisons(op):
    """
    ``maximum`` / ``minimum`` propagate NaN as NumPy does; comparisons are bool arrays equal to NumPy.

    Parameters
    ----------
    op : str
        Operation name.
    """

    rng = np.random.default_rng(21)
    fn = NP_BINARY[op]

    for _ in range(250):

        shape = _rand_shape(rng, 4, 5, 0.08)
        a = _operand(rng, shape, "ints", specials=0.15)
        b = _operand(rng, shape, "ints", specials=0.15)
        expected = fn(a, b)
        res = ND.binary(op, a, b)

        if op in EXTREMA:

            assert res.dtype == np.float64
            _equal_values(res, expected, op)

        else:

            assert res.dtype == np.bool_
            _same(res, expected, op)

    # end for

        # end if

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("op", ["and", "or", "xor"])
def test_binary_mask_operations(op):
    """
    ``and / or / xor`` of masks are bool arrays equal to NumPy's logical operations, with broadcasting.

    Parameters
    ----------
    op : str
        Operation name.
    """

    rng = np.random.default_rng(22)
    fn = NP_BINARY[op]

    for _ in range(150):

        shape = _rand_shape(rng, 4, 5, 0.08)
        a = _operand(rng, shape, "ints") > 0
        b = _operand(rng, shape, "ints") >= 0
        res = ND.binary(op, a, b)
        assert res.dtype == np.bool_
        _same(res, fn(a, b), op)

    # end for

    with pytest.raises(TypeError):

        ND.binary(op, np.ones(3), np.ones(3))

    # end with

    with pytest.raises(TypeError):

        ND.binary(op, np.ones(3, dtype=bool), np.ones(3))

    # end with

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_unary_not_and_mask_values():
    """
    ``not`` of a mask is NumPy's logical_not; a float operand is a TypeError.
    """

    rng = np.random.default_rng(23)

    for _ in range(100):

        shape = _rand_shape(rng, 4, 5, 0.08)
        m = _operand(rng, shape, "ints") > 0
        res = ND.unary("not", m)
        assert res.dtype == np.bool_
        _same(res, np.logical_not(m))

    # end for

    with pytest.raises(TypeError):

        ND.unary("not", np.ones(3))

    # end with

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("scalar_left", [False, True])
@pytest.mark.parametrize("op", ARITH + EXTREMA + COMPARE)
def test_binary_with_a_scalar(op, scalar_left):
    """
    ``binary_scalar`` equals the NumPy operation with a Python float on either side.

    Parameters
    ----------
    op : str
        Operation name.
    scalar_left : bool
        Scalar is the left operand.
    """

    rng = np.random.default_rng(24)
    fn = NP_BINARY[op]

    for _ in range(80):

        shape = _rand_shape(rng, 3, 5, 0.08)
        a = _rand_view(rng, shape, "ints", specials=0.1)[1]
        s = float(rng.choice([0.0, -0.0, 1.0, -2.0, 0.5, np.nan, np.inf, 3.25]))
        res = ND.binary_scalar(op, a, s, scalar_left=scalar_left)
        expected = fn(s, a) if scalar_left else fn(a, s)

        if op in EXTREMA:

            _equal_values(res, expected, op)

        else:

            _same(res, expected, op)

        # end if

        out = np.empty(shape)

        if op not in COMPARE:

            ND.binary_scalar_to(op, a, s, out, scalar_left=scalar_left)

            if op in EXTREMA:

                _equal_values(out, expected, op)

            else:

                _same(out, expected, op)

    # end for

        # end if

            # end if

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("exponent", [2.0, 0.5, -1.0, 1.0, 0.0, 3.0, -2.5, 0.25, 10.0])
def test_scalar_exponents_use_numpys_fast_paths(exponent):
    """
    ``x ** s`` with a scalar exponent: the fast paths (2, 0.5, -1, 1, 0) equal NumPy; others to 1 ulp.

    Parameters
    ----------
    exponent : float
        Scalar exponent.
    """

    rng = np.random.default_rng(25)
    x = _fill(rng, (6, 7), "positive")
    x[0, :3] = [0.0, np.inf, 4.0]
    expected = np.power(x, exponent)
    res = ND.binary_scalar("pow", x, exponent)

    if exponent in (2.0, 0.5, -1.0, 1.0, 0.0):

        _equal_values(res, expected)

    else:

        _ulps(res, expected, 1)

    # end if

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("name", sorted(EXACT_FNS))
def test_unary_functions_with_exact_results(name):
    """
    Correctly rounded or exact unary functions are bit-identical to NumPy on random strided inputs.

    Parameters
    ----------
    name : str
        Function name.
    """

    rng = np.random.default_rng(26)
    fn = EXACT_FNS[name]

    for _ in range(150):

        shape = _rand_shape(rng, 4, 5, 0.08)
        a = _operand(rng, shape, "wide", specials=0.12)
        _same(ND.unary(name, a), fn(a), name)

    # end for

    x = np.array([0.5, 1.5, 2.5, -0.5, -1.5, -2.5, 0.49999999999999994, 1e300, -1e-300])

    if name == "rint":

        _same(ND.unary("rint", x), np.rint(x))

    # end if

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("name", sorted(LIBM_FNS))
def test_unary_libm_functions_agree_to_a_few_ulps(name):
    """
    The libm functions agree with NumPy to 4 ulp on finite inputs, and NaN / infinity / domain errors
    behave identically.

    Parameters
    ----------
    name : str
        Function name.
    """

    rng = np.random.default_rng(27)
    fn = LIBM_FNS[name]

    for _ in range(100):

        shape = _rand_shape(rng, 3, 6, 0.05)
        scale = rng.choice([0.5, 1.0, 3.0, 30.0])
        a = _fill(rng, shape, "normal", 0.1) * scale

        if name in ("log", "log2", "log10", "log1p", "acosh", "cbrt"):

            a = np.abs(a) + (1.0 if name == "acosh" else 0.0)

        # end if

        _ulps(ND.unary(name, a), fn(a), 4, name)

    # end for

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_unary_sign_of_zero_is_positive_zero():
    """
    ``sign`` is -1, +1, NaN for NaN and +0.0 for both zeros (contracts S: ``sign(-0.0)`` is +0.0).
    """

    x = np.array([-3.0, -0.0, 0.0, 2.0, np.nan, np.inf, -np.inf, 1e-320, -1e-320])
    res = ND.unary("sign", x)
    expected = np.where(x == 0, 0.0, np.sign(x))
    _same(res, expected)
    assert not np.signbit(res[1])
    assert np.signbit(res[0])

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_results_keep_the_k_layout_of_their_operands():
    """
    Allocating results take the K layout of the operands (contracts S24, S26): F operands give an F
    result, the SoA block layout is kept, a broadcast first operand does not decide the order.
    """

    rng = np.random.default_rng(28)
    c = rng.standard_normal((4, 5, 6))
    f = np.asfortranarray(c)
    raw = np.zeros(60)
    blk = np.lib.stride_tricks.as_strided(raw, shape=(3, 4, 5), strides=(160, 8, 32))
    blk[...] = rng.standard_normal((3, 4, 5))

    res = ND.binary("add", f, f)
    assert res.flags.f_contiguous and not res.flags.c_contiguous
    assert ND.binary("add", c, c).flags.c_contiguous
    assert ND.unary("exp", f).flags.f_contiguous and not ND.unary("exp", f).flags.c_contiguous
    assert ND.binary_scalar("add", f, 1.0).flags.f_contiguous

    res = ND.binary("mul", blk, blk)
    assert _estrides(res) == (20, 1, 4)
    assert _estrides(ND.unary("neg", blk)) == (20, 1, 4)
    assert _estrides(ND.copy(blk, "K")) == (20, 1, 4)
    _same(res, blk * blk)

    # a scalar-shaped (zero stride) first operand must not turn an F result into C
    res = ND.binary("add", np.broadcast_to(np.array(2.0), f.shape), f)
    assert res.flags.f_contiguous and not res.flags.c_contiguous
    _same(res, 2.0 + f)

    # equal operand layouts of different orders: the first operand decides (ties: lowest index)
    assert ND.binary("add", c, f).flags.c_contiguous
    assert ND.binary("add", f, c).flags.f_contiguous

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("op", ARITH + EXTREMA)
def test_binary_to_random_outputs_with_guard_regions(op):
    """
    ``binary_to`` into random strided outputs (negative strides, F order, size 0) equals NumPy and does
    not write outside the output (canary elements around it keep their bits).

    Parameters
    ----------
    op : str
        Operation name.
    """

    rng = np.random.default_rng(29)
    fn = NP_BINARY[op]

    for _ in range(250):

        shape = _rand_shape(rng, 4, 5, 0.08)
        a = _operand(rng, shape, "ints", specials=0.1)
        b = _operand(rng, shape, "ints", specials=0.1)
        shape = np.broadcast_shapes(a.shape, b.shape)
        base, out, maker = _rand_view(rng, shape, "ints")
        exp_base = base.copy()
        fn(a, b, out=maker(exp_base))
        before = base.copy()
        got = ND.binary_to(op, a, b, out)
        assert got is out

        if op in EXTREMA:

            np.testing.assert_array_equal(base, exp_base)

        else:

            _same(base, exp_base)

        # end if

        if out.size:

            outside = np.ones(base.shape, dtype=bool)
            outside[...] = True
            marker = base.copy()
            marker.fill(0.0)
            maker(marker)[...] = 1.0
            np.testing.assert_array_equal(base[marker == 0.0], before[marker == 0.0])

    # end for

        # end if

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("op", COMPARE)
def test_comparison_into_a_mask_output(op):
    """
    A comparison written into a bool array equals NumPy; a float output is a TypeError.

    Parameters
    ----------
    op : str
        Comparison name.
    """

    rng = np.random.default_rng(30)
    fn = NP_BINARY[op]

    for _ in range(80):

        shape = _rand_shape(rng, 3, 5, 0.08)
        a = _operand(rng, shape, "ints", specials=0.1)
        b = _operand(rng, shape, "ints", specials=0.1)
        out = np.zeros(np.broadcast_shapes(a.shape, b.shape), dtype=bool)
        ND.binary_to(op, a, b, out)
        _same(out, fn(a, b))

    # end for

    with pytest.raises(TypeError):

        ND.binary_to(op, np.ones(3), np.ones(3), np.zeros(3))

    # end with

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_binary_to_in_place_and_partial_overlap():
    """
    ``out`` exactly an input is computed in place; any other overlap (a shifted or reversed view of
    the same memory) gives the result as if the inputs had been copied first, as NumPy does.
    """

    rng = np.random.default_rng(31)
    ops = ["add", "sub", "mul", "div"]

    for op in ops:

        fn = NP_BINARY[op]

        # exact alias
        a = _fill(rng, (5, 6))
        b = _fill(rng, (5, 6))
        expected = fn(a, b)
        ND.binary_to(op, a, b, a)
        _same(a, expected)

        a = _fill(rng, (5, 6))
        expected = fn(b, a)
        ND.binary_to(op, b, a, a)
        _same(a, expected)

        # partial overlap, one dimension
        a = _fill(rng, 12)
        expected = a.copy()
        expected[1:] = fn(a[1:], a[:-1])
        ND.binary_to(op, a[1:], a[:-1], a[1:])
        _same(a, expected)

        a = _fill(rng, 12)
        expected = a.copy()
        expected[:-1] = fn(a[1:], a[:-1])
        ND.binary_to(op, a[1:], a[:-1], a[:-1])
        _same(a, expected)

        # reversed
        a = _fill(rng, 10)
        b = _fill(rng, 10)
        expected = fn(a[::-1], b)
        ND.binary_to(op, a[::-1], b, a)
        _same(a, expected)

        # transposed square matrix
        a = _fill(rng, (6, 6))
        b = _fill(rng, (6, 6))
        expected = fn(a.T, b)
        ND.binary_to(op, a.T, b, a)
        _same(a, expected)

        # two dimensional windows of one array
        big = _fill(rng, (8, 8))
        expected = big.copy()
        expected[1:, 1:] = fn(big[:-1, :-1], big[1:, 1:])
        ND.binary_to(op, big[:-1, :-1], big[1:, 1:], big[1:, 1:])
        _same(big, expected)

    # end for

    # unary
    for name in ("neg", "sqrt", "exp"):

        fn = {"neg": np.negative, "sqrt": np.sqrt, "exp": np.exp}[name]
        a = _fill(rng, 12, "positive")
        expected = a.copy()
        expected[:-1] = fn(a[1:])
        ND.unary_to(name, a[1:], a[:-1])
        _ulps(a, expected, 4)

        a = _fill(rng, 12, "positive")
        expected = fn(a)
        ND.unary_to(name, a, a)
        _ulps(a, expected, 4)

    # end for

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_assign_and_fill_with_overlap_and_broadcasting():
    """
    ``assign`` follows NumPy's ``dst[...] = src``: broadcasting, reversed and shifted self-assignment,
    transposed overlap, scatter into strided views; ``fill`` writes one value.
    """

    rng = np.random.default_rng(32)

    a = _fill(rng, 10)
    expected = a.copy()
    expected[1:] = expected[:-1]
    ND.assign(a[:-1], a[1:])
    _same(a, expected)

    a = _fill(rng, 10)
    expected = a.copy()
    expected[::-1] = expected
    ND.assign(a, a[::-1])
    _same(a, expected)

    a = _fill(rng, (5, 5))
    expected = a.copy()
    expected.T[...] = expected
    ND.assign(a, a.T)
    _same(a, expected)

    a = _fill(rng, (6, 6))
    expected = a.copy()
    expected[1:, :-1] = expected[:-1, 1:]
    ND.assign(a[:-1, 1:], a[1:, :-1])
    _same(a, expected)

    for _ in range(200):

        shape = _rand_shape(rng, 4, 5, 0.08)
        src = _operand(rng, shape, specials=0.1)
        base, dst, maker = _rand_view(rng, shape, specials=0.1)
        exp_base = base.copy()
        maker(exp_base)[...] = src
        ND.assign(src, dst)
        _same(base, exp_base)

        value = float(rng.choice([0.0, -0.0, 2.5, np.nan, np.inf]))
        maker(exp_base)[...] = value
        ND.fill(dst, value)
        _same(base, exp_base)

    # end for

    # a smaller source broadcasts into a bigger destination
    dst = np.zeros((3, 4))
    ND.assign(np.arange(4.0), dst)
    _same(dst, np.broadcast_to(np.arange(4.0), (3, 4)))

    with pytest.raises(ValueError):

        ND.assign(np.zeros((3, 4)), np.zeros(4))

    # end with

    with pytest.raises(ValueError):

        ND.assign(np.zeros(3), np.zeros(4))

    # end with

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_output_argument_errors():
    """
    Shape, dtype and writeability errors of ``_to`` operations, and an output with internal overlap.
    """

    a = np.ones((3, 4))

    with pytest.raises(ValueError):

        ND.binary_to("add", a, a, np.zeros((3, 5)))

    # end with

    with pytest.raises(ValueError):

        ND.binary_to("add", a, a, np.zeros((4,)))

    # end with

    with pytest.raises(ValueError):

        ND.binary_to("add", a, np.ones((2, 4)), np.zeros((3, 4)))

    # end with

    ro = np.zeros((3, 4))
    ro.flags.writeable = False

    with pytest.raises(ValueError):

        ND.binary_to("add", a, a, ro)

    # end with

    with pytest.raises(ValueError):

        ND.unary_to("neg", a, ro)

    # end with

    with pytest.raises(ValueError):

        ND.assign(a, ro)

    # end with

    with pytest.raises(ValueError):

        ND.fill(ro, 1.0)

    # end with

    with pytest.raises(TypeError):

        ND.binary_to("add", a, a, np.zeros((3, 4), dtype=bool))

    # end with

    with pytest.raises(TypeError):

        ND.binary("add", np.arange(3), np.arange(3))

    # end with

    _same(ND.binary("add", np.arange(3), np.arange(3), want="f64"), np.arange(3.0) * 2)

    with pytest.raises(ValueError):

        ND.binary("nope", a, a)

    # end with

    # an empty read-only output is still a READONLY error (every write path)
    empty = np.zeros((0, 3))
    empty.flags.writeable = False

    with pytest.raises(ValueError):

        ND.fill(empty, 1.0)

    # end with

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_output_with_extra_leading_unit_axes_is_exact_shape_or_numpys():
    """
    The contracts require ``out`` to have exactly the broadcast shape; NumPy also accepts extra leading
    axes of extent 1. Either a ValueError or NumPy's result is acceptable (the Python layer decides).
    """

    a = np.arange(12.0).reshape(3, 4)
    out = np.zeros((1, 3, 4))

    try:

        ND.binary_to("add", a, a, out)

    except ValueError:

        assert not out.any()

    else:

        np.testing.assert_array_equal(out[0], a + a)

    # end try

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _rand_axes(rng, nd, single=False):
    """
    Random reduction axes: None, an int, or a tuple, negative or not.

    Parameters
    ----------
    rng : numpy.random.Generator
        Random generator.
    nd : int
        Rank of the input.
    single : bool
        Only None or one axis.

    Returns
    -------
    None, int or tuple of int
        Axes.
    """

    if nd == 0 or rng.random() < 0.15:

        return None

    # end if

    count = 1 if single or rng.random() < 0.5 else int(rng.integers(1, nd + 1))
    axes = [int(k) for k in rng.choice(nd, count, replace=False)]
    axes = [k - nd if rng.random() < 0.4 else k for k in axes]

    if count == 1 and rng.random() < 0.5:

        return axes[0]

    # end if

    return tuple(axes)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("op", ["sum", "prod", "mean", "var", "std"])
def test_reductions_that_agree_to_rounding(op):
    """
    sum / prod / mean / var / std over random axes, keepdims and strided inputs equal NumPy to rounding.

    Parameters
    ----------
    op : str
        Reduction name.
    """

    rng = np.random.default_rng(40)
    fn = getattr(np, op)

    for _ in range(300):

        shape = _rand_shape(rng, 4, 6, 0.1)
        nd = len(shape)
        src = _rand_view(rng, shape, "positive")[1]
        axes = _rand_axes(rng, nd)
        keep = bool(rng.integers(0, 2))
        kwargs = {}

        if op in ("var", "std") and rng.random() < 0.4:

            kwargs["ddof"] = int(rng.integers(0, 3))

        # end if

        expected = fn(src, axis=axes, keepdims=keep, **kwargs)
        res = ND.reduce(op, src, axes=axes, keepdims=keep, **kwargs)
        assert res.shape == np.shape(expected)
        np.testing.assert_allclose(res, expected, rtol=1e-12, atol=0.0, equal_nan=True)

    # end for

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("op", ["min", "max"])
def test_min_max_propagate_nan_and_are_exact(op):
    """
    min / max are exact, propagate NaN and handle infinities and every axis choice.

    Parameters
    ----------
    op : str
        Reduction name.
    """

    rng = np.random.default_rng(41)
    fn = getattr(np, op)

    for _ in range(300):

        shape = _rand_shape(rng, 4, 6, 0.0)

        if 0 in shape:

            continue

        # end if

        src = _rand_view(rng, shape, "ints", specials=0.1)[1]
        axes = _rand_axes(rng, len(shape))
        keep = bool(rng.integers(0, 2))
        expected = fn(src, axis=axes, keepdims=keep)
        res = ND.reduce(op, src, axes=axes, keepdims=keep)
        assert res.shape == np.shape(expected)
        np.testing.assert_array_equal(res, expected)

    # end for

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("fortran", [False, True])
@pytest.mark.parametrize("op", ["argmin", "argmax"])
def test_arg_reductions_first_occurrence_in_c_order(op, fortran):
    """
    argmin / argmax return the first extremum (the first NaN when there is one) in C order, also for
    F-ordered and strided inputs full of ties; axis None is the flattened index.

    Parameters
    ----------
    op : str
        Reduction name.
    fortran : bool
        Make the input F-ordered.
    """

    rng = np.random.default_rng(42)
    fn = getattr(np, op)

    for _ in range(300):

        shape = _rand_shape(rng, 4, 5, 0.0)

        if 0 in shape or not shape:

            continue

        # end if

        src = _rand_view(rng, shape, "ints", specials=0.08)[1]

        if fortran:

            src = np.asfortranarray(src)

        # end if

        for axis in [None] + list(range(len(shape))):

            for keep in (False, True):

                expected = fn(src, axis=axis, keepdims=keep)
                res = ND.reduce(op, src, axes=axis, keepdims=keep)
                assert res.dtype == np.int64
                np.testing.assert_array_equal(res, expected)

    # end for

        # end for

            # end for

    # all ties and NaN first
    ties = np.zeros((4, 3))
    ties = np.asfortranarray(ties)
    assert ND.reduce(op, ties) == 0
    nan = np.asfortranarray(np.array([[1.0, np.nan, 2.0], [np.nan, 0.0, -5.0]]))
    assert ND.reduce(op, nan) == fn(nan)

    with pytest.raises(ValueError):

        ND.reduce(op, np.ones((3, 3)), axes=(0, 1))

    # end with

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("source", ["float", "mask"])
@pytest.mark.parametrize("op", ["any", "all"])
def test_any_all(op, source):
    """
    any / all over floats (NaN is true) and masks equal NumPy for every axis choice.

    Parameters
    ----------
    op : str
        Reduction name.
    source : str
        Input kind.
    """

    rng = np.random.default_rng(43)
    fn = getattr(np, op)

    for _ in range(250):

        shape = _rand_shape(rng, 4, 5, 0.1)
        src = _rand_view(rng, shape, "ints", specials=0.1)[1]

        if source == "mask":

            src = src > 0

        # end if

        axes = _rand_axes(rng, len(shape))
        keep = bool(rng.integers(0, 2))
        expected = fn(src, axis=axes, keepdims=keep)
        res = ND.reduce(op, src, axes=axes, keepdims=keep)
        assert res.dtype == np.bool_
        np.testing.assert_array_equal(res, expected)

    # end for

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_reductions_of_empty_arrays():
    """
    Empty sums are 0, empty products 1, empty mean / var NaN; empty min / max / argmin / argmax are
    ValueErrors; reductions over the other axes of an empty array give the NumPy shapes.
    """

    empty = np.zeros((0, 3))
    assert ND.reduce("sum", empty) == 0.0
    assert ND.reduce("prod", empty) == 1.0
    assert np.isnan(ND.reduce("mean", empty))
    assert np.isnan(ND.reduce("var", empty))
    assert np.isnan(ND.reduce("std", empty))
    assert ND.reduce("any", empty) == np.False_
    assert ND.reduce("all", empty) == np.True_
    _same(ND.reduce("sum", empty, axes=0), np.zeros(3))
    _same(ND.reduce("prod", empty, axes=0), np.ones(3))
    _same(ND.reduce("sum", empty, axes=1), np.zeros(0))
    assert ND.reduce("sum", empty, axes=1, keepdims=True).shape == (0, 1)
    assert ND.reduce("sum", empty, axes=(0, 1), keepdims=True).shape == (1, 1)

    for op in ("min", "max", "argmin", "argmax"):

        with pytest.raises(ValueError):

            ND.reduce(op, empty)

        # end with

        with pytest.raises(ValueError):

            ND.reduce(op, empty, axes=0)

    # end for

        # end with

    # min over the non-empty axis of an empty array is an empty result
    assert ND.reduce("min", empty, axes=1).shape == (0,)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_reduction_axis_errors_and_identity_axes():
    """
    A bad axis is an IndexError, a repeated axis a ValueError; an empty axis tuple reduces nothing.
    """

    a = np.arange(24.0).reshape(2, 3, 4)

    for axes in (3, -4, (0, 3), (5,)):

        with pytest.raises(IndexError):

            ND.reduce("sum", a, axes=axes)

    # end for

        # end with

    with pytest.raises(ValueError):

        ND.reduce("sum", a, axes=(1, 1))

    # end with

    with pytest.raises(ValueError):

        ND.reduce("sum", a, axes=(0, -3))

    # end with

    with pytest.raises(ValueError):

        ND.reduce("nope", a)

    # end with

    _same(ND.reduce("sum", a, axes=()), np.sum(a, axis=()))
    _same(ND.reduce("sum", a, axes=(), keepdims=True), np.sum(a, axis=(), keepdims=True))
    _same(ND.reduce("sum", np.array(3.5)), np.sum(np.array(3.5)))
    _same(ND.reduce("sum", np.array(3.5), keepdims=True), np.sum(np.array(3.5), keepdims=True))

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_variance_with_ddof_at_or_beyond_the_count():
    """
    ``var`` divides by max(N - ddof, 0): IEEE infinity or NaN when that is 0, as NumPy returns.
    """

    rng = np.random.default_rng(44)
    a = _fill(rng, (4, 5), "positive")

    for ddof in (0, 1, 3, 4, 5, 7):

        for axis in (0, 1, None):

            expected = np.var(a, axis=axis, ddof=ddof)
            res = ND.reduce("var", a, axes=axis, ddof=ddof)
            np.testing.assert_allclose(res, expected, rtol=1e-12, equal_nan=True)
            expected = np.std(a, axis=axis, ddof=ddof)
            res = ND.reduce("std", a, axes=axis, ddof=ddof)
            np.testing.assert_allclose(res, expected, rtol=1e-12, equal_nan=True)

    # end for

        # end for

    assert np.isinf(ND.reduce("var", a, axes=0, ddof=4)).all()
    assert np.isnan(ND.reduce("var", np.ones((4, 3)), axes=0, ddof=4)).all()

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _reference_pairwise(x):
    """
    The documented block sum of nd_pairwise_sum, in pure Python (NumPy's pairwise scheme).

    Parameters
    ----------
    x : list of float
        Values in order.

    Returns
    -------
    float
        Block sum (+0.0 for an empty list).
    """

    n = len(x)

    if n < 8:

        res = 0.0

        for v in x:

            res = res + v

        # end for

        return res

    # end if

    if n <= 128:

        r = list(x[:8])
        stop = n - (n % 8)
        i = 8

        while i < stop:

            for j in range(8):

                r[j] = r[j] + x[i + j]

            # end for

            i += 8

        # end while

        res = ((r[0] + r[1]) + (r[2] + r[3])) + ((r[4] + r[5]) + (r[6] + r[7]))

        for i in range(stop, n):

            res = res + x[i]

        # end for

        return res

    # end if

    n2 = n // 2
    n2 -= n2 % 8
    return _reference_pairwise(x[:n2]) + _reference_pairwise(x[n2:])

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_pairwise_sum_matches_the_documented_algorithm():
    """
    ``pairwise_sum`` is bit-identical to a reference implementation of its documented scheme, for
    contiguous, strided and reversed vectors of every size class, and to ``np.sum`` of a contiguous
    vector.
    """

    rng = np.random.default_rng(45)
    sizes = list(range(0, 40)) + [63, 64, 65, 127, 128, 129, 130, 255, 256, 257, 1000, 4095, 4096, 5000]

    for n in sizes:

        x = _fill(rng, n, "wide", 0.0)
        got = ND.pairwise_sum(x)
        assert np.float64(got).tobytes() == np.float64(_reference_pairwise(x.tolist())).tobytes()

        if n:

            sl = x[::-1]
            assert np.float64(ND.pairwise_sum(sl)).tobytes() == \
                np.float64(_reference_pairwise(sl.tolist())).tobytes()

            wide = np.zeros(2 * n)
            wide[::2] = x
            sl = wide[::2]
            assert np.float64(ND.pairwise_sum(sl)).tobytes() == \
                np.float64(_reference_pairwise(sl.tolist())).tobytes()

        # end if

        if 0 < n <= 4096:

            assert np.float64(ND.pairwise_sum(x)).tobytes() == np.float64(np.sum(x)).tobytes()

    # end for

        # end if

    assert not np.signbit(ND.pairwise_sum(np.zeros(0)))

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_sum_is_bitwise_numpy_for_short_contiguous_vectors():
    """
    ``sum`` of a contiguous vector of at most 4096 elements is bit-identical to ``np.sum`` (also with
    mixed magnitudes and cancellation); above that it agrees to rounding.
    """

    rng = np.random.default_rng(46)

    for n in list(range(0, 60)) + [100, 127, 128, 129, 500, 1024, 4000, 4095, 4096]:

        for kind in ("normal", "wide", "positive"):

            x = _fill(rng, n, kind)
            res = ND.reduce("sum", x)
            assert res.tobytes() == np.float64(np.sum(x)).tobytes(), (n, kind)

    # end for

        # end for

    x = np.array([1e16, 1.0, -1e16, 1.0] * 500)
    assert ND.reduce("sum", x).tobytes() == np.float64(np.sum(x)).tobytes()

    for n in (4097, 5000, 20000, 100000):

        x = _fill(rng, n, "positive")
        np.testing.assert_allclose(ND.reduce("sum", x), np.sum(x), rtol=1e-12)

    # end for

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_sum_of_negative_zeros_is_positive_zero():
    """
    A sum starts from the identity: the sum of negative zeros is +0.0 for every length and axis.
    """

    for n in (1, 2, 7, 8, 9, 100, 5000):

        res = ND.reduce("sum", np.full(n, -0.0))
        assert res == 0.0 and not np.signbit(res), n

    # end for

    res = ND.reduce("sum", np.full((3, 4), -0.0), axes=1)
    assert not np.signbit(res).any()
    res = ND.reduce("sum", np.full((3, 4), -0.0), axes=0)
    assert not np.signbit(res).any()
    assert not np.signbit(ND.reduce("sum", np.zeros(0)))

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_reduction_output_overlapping_the_input_uses_a_temporary():
    """
    ``reduce_to`` into a view of its own input gives the result of the original values, as
    ``np.sum(c, axis=0, out=c[0])`` does.
    """

    rng = np.random.default_rng(47)

    for op in ("sum", "prod", "max", "min", "mean"):

        fn = getattr(np, op)
        c = _fill(rng, (4, 5), "positive")
        expected = c.copy()
        fn(expected, axis=0, out=expected[0])
        ND.reduce_to(op, c, c[0], axes=0)
        np.testing.assert_allclose(c, expected, rtol=1e-13)

        c = _fill(rng, (5, 4), "positive")
        expected = c.copy()
        fn(expected, axis=1, out=expected[:, 0])
        ND.reduce_to(op, c, c[:, 0], axes=1)
        np.testing.assert_allclose(c, expected, rtol=1e-13)

    # end for

    # a non-overlapping output, keepdims shape convention, and the error cases
    a = _fill(rng, (3, 4), "positive")
    out = np.zeros((1, 4))
    ND.reduce_to("sum", a, out, axes=0, keepdims=True)
    np.testing.assert_allclose(out, a.sum(axis=0, keepdims=True), rtol=1e-13)

    with pytest.raises(ValueError):

        ND.reduce_to("sum", a, np.zeros(3), axes=0)

    # end with

    ro = np.zeros(4)
    ro.flags.writeable = False

    with pytest.raises(ValueError):

        ND.reduce_to("sum", a, ro, axes=0)

    # end with

    with pytest.raises(TypeError):

        ND.reduce_to("argmax", a, np.zeros(4), axes=0)

    # end with

    idx = np.zeros(4, dtype=np.int64)
    ND.reduce_to("argmax", a, idx, axes=0)
    np.testing.assert_array_equal(idx, a.argmax(axis=0))

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_masks_compose_with_reductions_and_comparisons():
    """
    Comparisons feed ``any`` / ``all`` / ``and`` / ``not``: the combined expression equals NumPy's.
    """

    rng = np.random.default_rng(48)

    for _ in range(100):

        shape = _rand_shape(rng, 3, 5, 0.0)
        a = _operand(rng, shape, "ints", specials=0.1)
        b = _operand(rng, shape, "ints", specials=0.1)
        lt = ND.binary("lt", a, b)
        ge = ND.binary("ge", a, b)
        neq = ND.binary("ne", a, b)
        both = ND.binary("and", lt, neq)
        either = ND.binary("or", lt, ge)
        flip = ND.unary("not", lt)
        _same(both, (a < b) & (a != b))
        _same(either, (a < b) | (a >= b))
        _same(flip, ~(a < b))
        _same(ND.binary("xor", lt, flip), np.ones(np.broadcast_shapes(a.shape, b.shape), dtype=bool))
        nd = len(either.shape)

        if nd:

            ax = int(rng.integers(0, nd))
            _same(ND.reduce("any", either, axes=ax), np.any((a < b) | (a >= b), axis=ax))
            _same(ND.reduce("all", flip, axes=ax), np.all(~(a < b), axis=ax))

    # end for

        # end if

# end function
# --------------------------------------------------------------------------------------------------------


STATUS_CASES = [("SHAPE", ValueError), ("SIZE", ValueError), ("ARGUMENT", ValueError),
                ("LAYOUT", ValueError), ("READONLY", ValueError), ("INDEX", IndexError),
                ("DTYPE", TypeError), ("BUSY", BufferError), ("MEMORY", MemoryError)]


# ********************************************************************************************************
@pytest.mark.parametrize("code,exc", STATUS_CASES)
def test_status_mapping_to_python_exceptions(code, exc):
    """
    Contracts 4.4: each status raises its Python exception, and records itself as the module's last error.

    Parameters
    ----------
    code : str
        Status name without the ``OTI_ERR_`` prefix.
    exc : type
        Expected exception type.
    """

    ND.clear_error()
    a = np.ones((3, 4))

    def trigger():

        if code == "SHAPE":

            ND.reshape(a, (5,))

        elif code == "SIZE":

            ND.zeros((2**62,))

        elif code == "ARGUMENT":

            ND.arange(0.0, 1.0, 0.0)

        elif code == "LAYOUT":

            tricks = np.lib.stride_tricks
            zero = tricks.as_strided(np.zeros(4), shape=(3, 4), strides=(0, 8), writeable=True)
            ND.binary_to("add", a, a, zero)

        elif code == "READONLY":

            ro = np.zeros((3, 4))
            ro.flags.writeable = False
            ND.fill(ro, 1.0)

        elif code == "INDEX":

            ND.index(a, 9)

        elif code == "DTYPE":

            ND.binary("add", np.arange(3), np.arange(3))

        elif code == "BUSY":

            root = ND.root((2, 2))
            keep = root.array()
            root.grow(1024)
            del keep

        else:

            ND.set_limits(max_alloc_bytes=64)
            ND.zeros(100)

    # end def

        # end if

    with pytest.raises(exc) as info:

        trigger()

    # end with

    assert type(info.value) is exc
    status, where, msg = ND.last_error()

    if code != "READONLY":

        # a read-only output is refused while the handle imports it (before any C operation runs), so
        # the C layer has nothing to record
        assert status == ND.status[code]

    # end if

    assert code in str(info.value) or "OTI_ERR" in str(info.value) or len(str(info.value)) > 0

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_status_strings():
    """
    ``oti_status_string`` is non-empty for every status, distinct for distinct statuses, and also answers
    for an unknown negative value and a positive value.
    """

    texts = {}

    for name, value in ND.status.items():

        text = ND.status_string(value)
        assert isinstance(text, str) and text, name
        texts[name] = text

    # end for

    errors = [t for n, t in texts.items() if n != "OK"]
    assert len(set(errors)) == len(errors)
    assert texts["OK"] not in errors
    assert isinstance(ND.status_string(-9999), str) and ND.status_string(-9999)
    assert isinstance(ND.status_string(3), str) and ND.status_string(3)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_failed_allocations_leave_no_state_behind():
    """
    An injected allocation failure at each allocation of several operations raises MemoryError, and
    the same call succeeds afterwards (outputs empty, nothing leaked as far as Python can see).
    """

    rng = np.random.default_rng(49)
    a = _fill(rng, (6, 7))
    b = _fill(rng, (6, 7))
    calls = [lambda: ND.zeros((5, 5)), lambda: ND.binary("add", a, b), lambda: ND.copy(a, "F"),
             lambda: ND.reduce("sum", a, axes=0), lambda: ND.roundtrip(a, want="f64", copy=True),
             lambda: ND.roundtrip(np.arange(10, dtype=np.int32), want="f64"),
             lambda: ND.arange(0.0, 100.0, 1.0)]

    for call in calls:

        raised = 0

        for countdown in range(1, 6):

            ND.fail_alloc(countdown)

            try:

                call()

            except MemoryError:

                raised += 1

            # end try

            ND.fail_alloc(0)

        # end for

        assert raised >= 1
        call()

    # end for

# end function
# --------------------------------------------------------------------------------------------------------


DETERMINISM_SCRIPT = """
import hashlib, sys
import numpy as np
from pyoti.real import _ndtest as ND

rng = np.random.default_rng(123)
big = rng.standard_normal(3_000_017) * 10.0 ** rng.integers(-6, 7, 3_000_017)
other = rng.standard_normal(3_000_017)
mat = rng.standard_normal((1500, 1700)) * 10.0 ** rng.integers(-4, 5, (1500, 1700))
matf = np.asfortranarray(mat)
big[::997] = np.nan
big[5::1013] = -0.0
h = hashlib.sha256()

def add(x):
    h.update(np.ascontiguousarray(x).view(np.uint8).tobytes() if x.dtype != np.bool_ else x.tobytes())

add(ND.binary("add", big, other))
add(ND.binary("mul", big, other))
add(ND.binary("div", big, other))
add(ND.binary("maximum", big, other))
add(ND.binary("lt", big, other))
add(ND.unary("exp", other * 0.01))
add(ND.unary("sqrt", np.abs(big)))
add(ND.binary_scalar("pow", np.abs(other), 2.5))
add(ND.reduce("sum", big))
add(ND.reduce("sum", mat))
add(ND.reduce("sum", mat, axes=0))
add(ND.reduce("sum", mat, axes=1))
add(ND.reduce("sum", matf, axes=0))
add(ND.reduce("sum", matf, axes=1))
add(ND.reduce("mean", mat, axes=0))
add(ND.reduce("var", mat, axes=1))
add(ND.reduce("std", matf))
add(ND.reduce("prod", np.abs(other[:200000]) + 0.5))
add(ND.reduce("min", big))
add(ND.reduce("argmax", mat))
add(ND.reduce("argmin", matf, axes=0))
add(ND.reduce("any", mat > 3.0, axes=1))
out = np.empty_like(mat)
ND.binary_to("sub", mat, matf, out)
add(out)
print(h.hexdigest())
"""


# ********************************************************************************************************
def test_results_are_bit_identical_at_every_thread_count():
    """
    Elementwise operations and reductions give the same bits with 1, 2, 3 and 8 OpenMP threads (contracts
    5.4: the result does not depend on the thread count), on large adversarial data.
    """

    env_root = os.path.dirname(os.path.dirname(os.path.abspath(real.__file__)))
    digests = {}

    for threads in ("1", "2", "3", "8"):

        env = dict(os.environ)
        old = [p for p in env.get("PYTHONPATH", "").split(os.pathsep) if p]
        env["PYTHONPATH"] = os.pathsep.join([env_root] + old)
        env["OMP_NUM_THREADS"] = threads
        proc = subprocess.run([sys.executable, "-c", DETERMINISM_SCRIPT], capture_output=True, text=True,
                              env=env, timeout=900)
        assert proc.returncode == 0, proc.stderr
        digests[threads] = proc.stdout.strip()

    # end for

    assert len(set(digests.values())) == 1, digests

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_large_operations_agree_with_numpy():
    """
    Arrays above the parallel thresholds: elementwise bit-identical to NumPy, reductions to rounding.
    """

    rng = np.random.default_rng(50)
    a = _fill(rng, (1200, 1100), "wide")
    b = _fill(rng, (1200, 1100))
    _same(ND.binary("add", a, b), a + b)
    _same(ND.binary("mul", a, b[:1]), a * b[:1])
    _same(ND.binary("lt", a, b), a < b)
    _same(ND.unary("neg", a), -a)
    scale = np.abs(a).max()

    for axis in (None, 0, 1):

        np.testing.assert_allclose(ND.reduce("sum", b, axes=axis), b.sum(axis=axis), rtol=1e-10,
                                   atol=1e-10)
        np.testing.assert_allclose(ND.reduce("sum", a, axes=axis), a.sum(axis=axis), rtol=1e-9,
                                   atol=1e-9 * scale)

    # end for

    np.testing.assert_array_equal(ND.reduce("max", a, axes=0), a.max(axis=0))
    np.testing.assert_array_equal(ND.reduce("argmin", a, axes=1), a.argmin(axis=1))
    np.testing.assert_array_equal(ND.reduce("argmax", np.asfortranarray(a), axes=0), a.argmax(axis=0))

# end function
# --------------------------------------------------------------------------------------------------------
