"""
Compare the semi-sparse order and derivative plumbing (Phase 2 of PLAN-semisparse-sparse-leveling.md)
with the pyoti.sparse oracle: get_order_im, extract_im / extract_deriv, get_all_ims / get_all_derivs,
get_order_im_array / set_order_im_from_array, trunc_dot, trunc_sub, dot_product, rom_eval*,
interp1d, moving_average and inv_block.

Every comparison is at 1e-13 relative, at orders 1 to 5, for operands over the same, leading and
interleaved active sets. Where pyoti.sparse has no test of its own for a function, a sparse-side
check against an independent computation comes first, so that the oracle itself is verified.
"""

import itertools

import numpy as np
import pytest

import pyoti.semisparse as semi
import pyoti.sparse as sparse


RTOL = 1e-13
ORDERS = [1, 2, 3, 4, 5]
SETS = {
    "same": ([1, 2, 3], [1, 2, 3]),
    "leading": ([1, 2], [1, 2, 3, 4]),
    "interleaved": ([1, 3, 5], [2, 4, 6]),
}
NB = 6


# ********************************************************************************************************
def _rand_scalar(bases, order, rng, real=None):
    """
    Build a sparse scalar with every direction over the given bases filled with random values.

    Parameters
    ----------
    bases : list of int
        Active bases.
    order : int
        Truncation order.
    rng : numpy.random.Generator
        Random generator.
    real : float, optional
        Real part (random in [1, 2) when None).

    Returns
    -------
    sotinum
        Sparse scalar.
    """

    x = sparse.zero(order=order) + (rng.uniform(1.0, 2.0) if real is None else real)

    for p in range(1, order + 1):

        for d in itertools.combinations_with_replacement(bases, p):

            x = x + rng.uniform(-0.5, 0.5) * sparse.e(list(d), order=order)

        # end for

    # end for

    return x

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _rand_matrix(shape, bases, order, rng):
    """
    Build a sparse matrix whose entries are independent random scalars over the given bases.

    Parameters
    ----------
    shape : tuple of int
        Rows and columns.
    bases : list of int
        Active bases.
    order : int
        Truncation order.
    rng : numpy.random.Generator
        Random generator.

    Returns
    -------
    matso
        Sparse matrix.
    """

    m = sparse.zeros(shape, order=order)

    for i in range(shape[0]):

        for j in range(shape[1]):

            m[i, j] = _rand_scalar(bases, order, rng)

        # end for

    # end for

    return m

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _scalar_layout(x, order):
    """
    Export a sparse or semi-sparse scalar in the get_all_ims layout over NB bases.

    Parameters
    ----------
    x : sotinum or ssotinum
        Scalar.
    order : int
        Highest order of the layout.

    Returns
    -------
    numpy.ndarray
        Coefficients, real part first.
    """

    if isinstance(x, semi.ssotinum):

        x = x.to_sparse()

    # end if

    m = sparse.zeros((1, 1), order=max(order, 1))
    m[0, 0] = x
    return m.get_all_ims(NB, order)[:, 0, 0]

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _array_layout(a, order):
    """
    Export a sparse or semi-sparse array in the get_all_ims layout over NB bases.

    Parameters
    ----------
    a : matso or oarrss or arrss
        Array.
    order : int
        Highest order of the layout.

    Returns
    -------
    numpy.ndarray
        Coefficients, shape (directions, rows, columns).
    """

    if isinstance(a, (semi.oarrss, semi.arrss)):

        a = a.to_sparse()

    # end if

    return a.get_all_ims(NB, order)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _close(actual, expected, msg=""):
    """
    Assert two real arrays agree to RTOL relative to the largest reference magnitude.

    Parameters
    ----------
    actual : array_like
        Computed values.
    expected : array_like
        Reference values.
    msg : str
        Context for the failure message.
    """

    actual = np.asarray(actual, dtype=np.float64)
    expected = np.asarray(expected, dtype=np.float64)
    assert actual.shape == expected.shape, msg
    scale = max(1.0, float(np.max(np.abs(expected)))) if expected.size else 1.0
    np.testing.assert_allclose(actual, expected, rtol=RTOL, atol=RTOL * scale, err_msg=msg)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _same_scalar(actual, expected, order, msg=""):
    """
    Assert a semi-sparse scalar equals a sparse one in every direction.

    Parameters
    ----------
    actual : ssotinum
        Semi-sparse result.
    expected : sotinum
        Sparse reference.
    order : int
        Highest compared order.
    msg : str
        Context for the failure message.
    """

    assert isinstance(actual, semi.ssotinum), msg
    _close(_scalar_layout(actual, order), _scalar_layout(expected, order), msg)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _same_array(actual, expected, order, msg=""):
    """
    Assert a semi-sparse array equals a sparse one in every element and direction.

    Parameters
    ----------
    actual : oarrss or arrss
        Semi-sparse result.
    expected : matso
        Sparse reference.
    order : int
        Highest compared order.
    msg : str
        Context for the failure message.
    """

    assert isinstance(actual, (semi.oarrss, semi.arrss)), msg
    _close(_array_layout(actual, order), _array_layout(expected, order), msg)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _both_layouts(m):
    """
    Convert a sparse matrix to both semi-sparse layouts.

    Parameters
    ----------
    m : matso
        Sparse matrix.

    Returns
    -------
    tuple
        (oarrss, arrss).
    """

    return semi.oarrss.from_sparse(m), semi.arrss.from_sparse(m)

# end function
# --------------------------------------------------------------------------------------------------------


# --------------------------------------------------------------------------------------------------------
# get_order_im, extract_im, extract_deriv
# --------------------------------------------------------------------------------------------------------

# ********************************************************************************************************
@pytest.mark.parametrize("order", ORDERS)
@pytest.mark.parametrize("sets", list(SETS))
def test_get_order_im(order, sets):
    """
    Test the module get_order_im on scalars and both array layouts, with and without out=.

    Parameters
    ----------
    order : int
        Truncation order.
    sets : str
        Active-set scenario.
    """

    rng = np.random.default_rng(order)
    bases = SETS[sets][0] + [b for b in SETS[sets][1] if b not in SETS[sets][0]]
    x = _rand_scalar(bases, order, rng)
    m = _rand_matrix((2, 3), bases, order, rng)
    soa, aos = _both_layouts(m)

    for k in range(order + 2):

        _same_scalar(semi.get_order_im(k, semi.ssotinum(x)), sparse.get_order_im(k, x), order,
                     f"scalar order {k}")
        ref = sparse.get_order_im(k, m)
        _same_array(semi.get_order_im(k, soa), ref, order, f"soa order {k}")
        _same_array(semi.get_order_im(k, aos), ref, order, f"aos order {k}")

        out = semi.zeros((2, 3))
        assert semi.get_order_im(k, soa, out=out) is None
        _same_array(out, ref, order, f"soa out order {k}")

    # end for

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("order", ORDERS)
@pytest.mark.parametrize("sets", list(SETS))
def test_extract_im_and_deriv(order, sets):
    """
    Test extract_im / extract_deriv (functions and array methods) against sparse.

    Parameters
    ----------
    order : int
        Truncation order.
    sets : str
        Active-set scenario.
    """

    rng = np.random.default_rng(10 + order)
    bases = SETS[sets][0]
    other = [b for b in SETS[sets][1] if b not in bases]
    x = _rand_scalar(bases, order, rng)
    m = _rand_matrix((3, 2), bases, order, rng)
    soa, aos = _both_layouts(m)
    sx = semi.ssotinum(x)
    dirs = [[bases[0]], [bases[-1]], [bases[0], bases[-1]], [bases[0], bases[0]],
            [bases[0]] * min(order, 3)]

    if other:

        dirs.append([other[0]])
        dirs.append([bases[0], other[0]])

    # end if

    for d in dirs:

        for name in ("extract_im", "extract_deriv"):

            sfun = getattr(semi, name)
            pfun = getattr(sparse, name)
            ref_s = pfun(d, x)
            ref_m = pfun(d, m)
            res_s = sfun(d, sx)

            _same_scalar(res_s, ref_s, order, f"{name} scalar {d}")
            assert res_s.order == ref_s.order, f"{name} scalar order {d}"
            _same_array(sfun(d, soa), ref_m, order, f"{name} soa {d}")
            _same_array(sfun(d, aos), ref_m, order, f"{name} aos {d}")
            _same_array(getattr(soa, name)(d), ref_m, order, f"{name} soa method {d}")
            _same_array(getattr(aos, name)(d), ref_m, order, f"{name} aos method {d}")

            out = semi.ssotinum(0.0)
            assert sfun(d, sx, out=out) is None
            _same_scalar(out, ref_s, order, f"{name} scalar out {d}")

        # end for

    # end for

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("order", ORDERS)
@pytest.mark.parametrize("sets", list(SETS))
def test_get_all_ims_and_derivs(order, sets):
    """
    Test get_all_ims / get_all_derivs of both array layouts against matso, including a layout
    smaller than the active set (directions outside it are left out).

    Parameters
    ----------
    order : int
        Truncation order.
    sets : str
        Active-set scenario.
    """

    rng = np.random.default_rng(20 + order)
    m = _rand_matrix((2, 2), SETS[sets][1], order, rng)
    soa, aos = _both_layouts(m)

    for nbasis, top in ((NB, order), (max(SETS[sets][1]), max(order - 1, 1))):

        for name in ("get_all_ims", "get_all_derivs"):

            ref = getattr(m, name)(nbasis, top)
            _close(getattr(soa, name)(nbasis, top), ref, f"soa {name} {nbasis} {top}")
            _close(getattr(aos, name)(nbasis, top), ref, f"aos {name} {nbasis} {top}")

        # end for

    # end for

    # A layout over fewer bases than the active set: only directions within it are exported.
    small = soa.get_all_ims(1, order)
    assert small.shape == (order + 1, 2, 2)
    _close(small[0], m.real, "real part of a one-base layout")

# end function
# --------------------------------------------------------------------------------------------------------


# --------------------------------------------------------------------------------------------------------
# get_order_im_array, set_order_im_from_array
# --------------------------------------------------------------------------------------------------------

# ********************************************************************************************************
def _order_array_reference(m, ordi):
    """
    Independent get_order_im_array layout of a sparse matrix, from get_im per direction.

    Parameters
    ----------
    m : matso
        Sparse matrix.
    ordi : int
        Order.

    Returns
    -------
    numpy.ndarray
        Matrix of shape (nrows, ncols * width), width from the largest base in use.
    """

    nr, nc = m.shape
    used = [b for b in range(1, NB + 1) if np.any(m.get_im(b) != 0.0)]
    top = max(used) if used else 1
    dirs = sorted(itertools.combinations_with_replacement(range(1, top + 1), ordi),
                  key=lambda d: sum(np.prod([b - 1 + i + 1 - k for k in range(i + 1)]) // np.prod(
                      range(1, i + 2)) for i, b in enumerate(d)))
    res = np.zeros((nr, nc * len(dirs)))

    for g, d in enumerate(dirs):

        res[:, g * nc:(g + 1) * nc] = m.get_im(list(d))

    # end for

    return res

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("ordi", [1, 2, 3])
def test_sparse_get_order_im_array_oracle(ordi):
    """
    Check the sparse get_order_im_array layout against get_im per direction (oracle check).

    Parameters
    ----------
    ordi : int
        Exported order.
    """

    rng = np.random.default_rng(30 + ordi)
    m = _rand_matrix((2, 3), [1, 3], 3, rng)
    _close(sparse.get_order_im_array(ordi, m), _order_array_reference(m, ordi),
           f"sparse get_order_im_array order {ordi}")

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("order", ORDERS)
@pytest.mark.parametrize("sets", list(SETS))
def test_get_order_im_array(order, sets):
    """
    Test get_order_im_array of both array layouts against sparse, at every order.

    Parameters
    ----------
    order : int
        Truncation order.
    sets : str
        Active-set scenario.
    """

    rng = np.random.default_rng(40 + order)
    m = _rand_matrix((3, 2), SETS[sets][1], order, rng)
    soa, aos = _both_layouts(m)

    for ordi in range(1, order + 1):

        ref = sparse.get_order_im_array(ordi, m)
        _close(semi.get_order_im_array(ordi, soa), ref, f"soa order {ordi}")
        _close(semi.get_order_im_array(ordi, aos), ref, f"aos order {ordi}")

    # end for

    # Above the truncation order sparse exports one zero direction.
    _close(semi.get_order_im_array(order + 1, soa), np.zeros((3, 2)), "empty order")
    _close(semi.get_order_im_array(0, soa), m.real, "order 0 is the real part")

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_sparse_set_order_im_from_array_oracle():
    """
    Check the sparse set_order_im_from_array against a hand-built sum (oracle check).
    """

    rng = np.random.default_rng(50)
    base = _rand_matrix((2, 2), [1, 2], 2, rng)
    vals = rng.uniform(-1.0, 1.0, size=(2, 2 * 3))
    target = base.copy()
    sparse.set_order_im_from_array(2, vals, target)
    dirs = [[1, 1], [1, 2], [2, 2]]
    ref = base.copy()

    for g, d in enumerate(dirs):

        for i in range(2):

            for j in range(2):

                ref[i, j] = ref[i, j] + vals[i, j + 2 * g] * sparse.e(d, order=2)

            # end for

        # end for

    # end for

    _close(_array_layout(target, 2), _array_layout(ref, 2), "sparse set_order_im_from_array")

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("order", ORDERS)
@pytest.mark.parametrize("sets", list(SETS))
def test_set_order_im_from_array(order, sets):
    """
    Test set_order_im_from_array on both layouts against sparse: the target grows its active set
    and truncation order, and the values are added to what it holds.

    Parameters
    ----------
    order : int
        Truncation order of the exported data.
    sets : str
        Active-set scenario.
    """

    rng = np.random.default_rng(60 + order)
    lhs_bases, rhs_bases = SETS[sets]
    src = _rand_matrix((2, 3), rhs_bases, order, rng)
    start = _rand_matrix((2, 3), lhs_bases, 1, rng)

    for ordi in range(1, order + 1):

        vals = sparse.get_order_im_array(ordi, src)
        ref = start.copy()
        sparse.set_order_im_from_array(ordi, vals, ref)
        soa, aos = _both_layouts(start)
        semi.set_order_im_from_array(ordi, vals, soa)
        semi.set_order_im_from_array(ordi, vals, aos)
        _same_array(soa, ref, order, f"soa order {ordi}")
        _same_array(aos, ref, order, f"aos order {ordi}")
        assert soa.order == max(1, ordi)

    # end for

    with pytest.raises(ValueError):

        semi.set_order_im_from_array(1, np.zeros((3, 3)), semi.zeros((2, 3)))

    # end with

# end function
# --------------------------------------------------------------------------------------------------------


# --------------------------------------------------------------------------------------------------------
# trunc_dot, trunc_sub, dot_product
# --------------------------------------------------------------------------------------------------------

# ********************************************************************************************************
def _trunc_dot_reference(oa, a, ob, b):
    """
    Truncated product from full sparse products: the order (oa + ob) part of a_oa @ b_ob.

    Parameters
    ----------
    oa : int
        Order taken from ``a``.
    a : matso
        Left matrix.
    ob : int
        Order taken from ``b``.
    b : matso
        Right matrix.

    Returns
    -------
    matso
        Reference product.
    """

    return sparse.get_order_im(oa + ob, sparse.dot(sparse.get_order_im(oa, a),
                                                   sparse.get_order_im(ob, b)))

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_sparse_trunc_dot_oracle():
    """
    Check the sparse trunc_dot (CSR left operand) against full products (oracle check).
    """

    rng = np.random.default_rng(70)
    a = _rand_matrix((3, 2), [1, 2], 3, rng)
    b = _rand_matrix((2, 2), [2, 3], 3, rng)
    lil = sparse.lil_matrix((3, 2))

    for i in range(3):

        for j in range(2):

            lil[i, j] = a[i, j]

        # end for

    # end for

    csr = lil.tocsr()

    for oa in range(4):

        for ob in range(4 - oa):

            _close(_array_layout(sparse.trunc_dot(oa, csr, ob, b), 3),
                   _array_layout(_trunc_dot_reference(oa, a, ob, b), 3),
                   f"sparse trunc_dot ({oa}, {ob})")

        # end for

    # end for

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("order", ORDERS)
@pytest.mark.parametrize("sets", list(SETS))
def test_trunc_dot(order, sets):
    """
    Test trunc_dot on SoA and AoS operands, every order pair, and out= aliasing an operand.

    Parameters
    ----------
    order : int
        Truncation order.
    sets : str
        Active-set scenario.
    """

    rng = np.random.default_rng(80 + order)
    a = _rand_matrix((3, 2), SETS[sets][0], order, rng)
    b = _rand_matrix((2, 2), SETS[sets][1], order, rng)
    sa, aa = _both_layouts(a)
    sb, ab = _both_layouts(b)

    for oa in range(order + 1):

        for ob in range(order + 2 - oa):

            ref = _trunc_dot_reference(oa, a, ob, b)
            res = semi.trunc_dot(oa, sa, ob, sb)
            assert isinstance(res, semi.oarrss)
            _same_array(res, ref, order, f"soa ({oa}, {ob})")
            res = semi.trunc_dot(oa, aa, ob, ab)
            assert isinstance(res, semi.arrss)
            _same_array(res, ref, order, f"aos ({oa}, {ob})")

        # end for

    # end for

    out = sb.copy() if hasattr(sb, "copy") else semi.oarrss.from_sparse(b)
    assert semi.trunc_dot(0, sb, 1, out, out=out) is None
    _same_array(out, _trunc_dot_reference(0, b, 1, b), order, "out aliasing the right operand")

    with pytest.raises(ValueError):

        semi.trunc_dot(1, sb, 1, sa)

    # end with

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("order", ORDERS)
@pytest.mark.parametrize("sets", list(SETS))
def test_trunc_sub(order, sets):
    """
    Test trunc_sub on scalars and both layouts against sparse (out= and a returned result).

    Parameters
    ----------
    order : int
        Truncation order.
    sets : str
        Active-set scenario.
    """

    rng = np.random.default_rng(90 + order)
    a = _rand_matrix((2, 3), SETS[sets][0], order, rng)
    b = _rand_matrix((2, 3), SETS[sets][1], order, rng)
    x = _rand_scalar(SETS[sets][0], order, rng)
    y = _rand_scalar(SETS[sets][1], order, rng)
    sa, aa = _both_layouts(a)
    sb, ab = _both_layouts(b)

    for k in range(order + 2):

        ref = sparse.zeros((2, 3), order=order)
        sparse.trunc_sub(k, a, b, out=ref)
        _same_array(semi.trunc_sub(k, sa, sb), ref, order, f"soa order {k}")
        _same_array(semi.trunc_sub(k, aa, ab), ref, order, f"aos order {k}")

        out = semi.oarrss.from_sparse(a)
        assert semi.trunc_sub(k, out, sb, out=out) is None
        _same_array(out, ref, order, f"soa out aliasing order {k}")

        _same_scalar(semi.trunc_sub(k, semi.ssotinum(x), semi.ssotinum(y)),
                     sparse.get_order_im(k, x - y), order, f"scalar order {k}")

    # end for

    with pytest.raises(ValueError):

        semi.trunc_sub(1, sa, semi.zeros((3, 2)))

    # end with

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("order", ORDERS)
@pytest.mark.parametrize("sets", list(SETS))
def test_dot_product(order, sets):
    """
    Test dot_product: a column against a row (the FEM use), equal shapes, a (2, 3) against a
    (3, 2) array (row-major pairing), and a real NumPy operand.

    Parameters
    ----------
    order : int
        Truncation order.
    sets : str
        Active-set scenario.
    """

    rng = np.random.default_rng(100 + order)
    col = _rand_matrix((4, 1), SETS[sets][0], order, rng)
    row = _rand_matrix((1, 4), SETS[sets][1], order, rng)
    a = _rand_matrix((2, 3), SETS[sets][0], order, rng)
    b = _rand_matrix((2, 3), SETS[sets][1], order, rng)
    c = _rand_matrix((3, 2), SETS[sets][1], order, rng)
    real = rng.uniform(-1.0, 1.0, size=(2, 3))

    for lhs, rhs in ((col, row), (a, b), (a, c)):

        ref = sparse.dot_product(lhs, rhs)

        for layout in (semi.oarrss, semi.arrss):

            res = semi.dot_product(layout.from_sparse(lhs), layout.from_sparse(rhs))
            _same_scalar(res, ref, order, f"{layout.__name__} {lhs.shape}.{rhs.shape}")

        # end for

    # end for

    ref = sparse.dot_product(a, sparse.array(real))
    _same_scalar(semi.dot_product(semi.oarrss.from_sparse(a), real), ref, order, "real rhs")
    _same_scalar(semi.dot_product(real, semi.oarrss.from_sparse(a)), ref, order, "real lhs")

    out = semi.ssotinum(0.0)
    assert semi.dot_product(semi.oarrss.from_sparse(col), semi.oarrss.from_sparse(row),
                            out=out) is None
    _same_scalar(out, sparse.dot_product(col, row), order, "out")

    with pytest.raises(ValueError):

        semi.dot_product(semi.oarrss.from_sparse(col), semi.oarrss.from_sparse(a))

    # end with

# end function
# --------------------------------------------------------------------------------------------------------


# --------------------------------------------------------------------------------------------------------
# rom_eval, rom_eval_array, rom_eval_object
# --------------------------------------------------------------------------------------------------------

# ********************************************************************************************************
@pytest.mark.parametrize("order", ORDERS)
@pytest.mark.parametrize("sets", list(SETS))
def test_rom_eval(order, sets):
    """
    Test the scalar and array rom_eval against sparse, with deltas for a subset of the bases.

    Parameters
    ----------
    order : int
        Truncation order.
    sets : str
        Active-set scenario.
    """

    rng = np.random.default_rng(110 + order)
    bases = SETS[sets][1]
    x = _rand_scalar(bases, order, rng)
    m = _rand_matrix((2, 3), bases, order, rng)
    soa, aos = _both_layouts(m)
    listed = bases[:-1] if len(bases) > 1 else bases
    deltas = list(rng.uniform(-0.3, 0.3, size=len(listed)))

    res = semi.ssotinum(x).rom_eval(listed, deltas)
    assert res.order == 0
    _close(res.real, x.rom_eval(listed, deltas).real, "scalar")

    ref = m.rom_eval(listed, deltas).real
    _close(soa.rom_eval(listed, deltas).real, ref, "soa")
    _close(aos.rom_eval(listed, deltas).to_sparse().real, ref, "aos")

    # A single delta perturbs every active base.
    full = m.rom_eval(bases, [0.1] * len(bases)).real
    _close(soa.rom_eval(None, 0.1).real, full, "soa with one delta for every base")

    with pytest.raises(ValueError):

        semi.ssotinum(x).rom_eval([1, 2], [0.1])

    # end with

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_sparse_rom_eval_array_and_object_oracle():
    """
    Check the sparse rom_eval_array and rom_eval_object against rom_eval point by point.
    """

    rng = np.random.default_rng(120)
    x = _rand_scalar([1, 2, 3], 4, rng)
    dx = rng.uniform(-0.3, 0.3, size=(3, 5))
    arr = x.rom_eval_array([1, 2, 3], [dx[0], dx[1], dx[2]])
    pts = [x.rom_eval([1, 2, 3], list(dx[:, t])).real for t in range(5)]
    obj = [x.rom_eval_object([1, 2, 3], list(dx[:, t])) for t in range(5)]
    _close(arr, pts, "sparse rom_eval_array")
    _close(obj, pts, "sparse rom_eval_object")

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("order", ORDERS)
@pytest.mark.parametrize("sets", list(SETS))
def test_rom_eval_array_and_object(order, sets):
    """
    Test ssotinum.rom_eval_array (2-D grids of deltas) and rom_eval_object (float and OTI deltas).

    Parameters
    ----------
    order : int
        Truncation order.
    sets : str
        Active-set scenario.
    """

    rng = np.random.default_rng(130 + order)
    bases = SETS[sets][1]
    x = _rand_scalar(bases, order, rng)
    sx = semi.ssotinum(x)
    grids = [rng.uniform(-0.3, 0.3, size=(3, 4)) for _ in bases]
    res = sx.rom_eval_array(bases, grids)
    assert res.shape == (3, 4)
    _close(res, x.rom_eval_array(bases, grids), "rom_eval_array")

    deltas = list(rng.uniform(-0.3, 0.3, size=len(bases)))
    _close(sx.rom_eval_object(bases, deltas), x.rom_eval_object(bases, deltas), "object floats")

    # Sparse OTI deltas: the result is a sparse number, compared direction by direction.
    oti_deltas = [d + 0.1 * sparse.e(7, order=2) for d in deltas]
    ref = x.rom_eval_object(bases, oti_deltas)
    res = sx.rom_eval_object(bases, oti_deltas)
    _close([res.real, res.get_im(7), res.get_im([7, 7])],
           [ref.real, ref.get_im(7), ref.get_im([7, 7])], "object OTI deltas")

# end function
# --------------------------------------------------------------------------------------------------------


# --------------------------------------------------------------------------------------------------------
# interp1d, moving_average, inv_block
# --------------------------------------------------------------------------------------------------------

# ********************************************************************************************************
@pytest.mark.parametrize("order", ORDERS)
@pytest.mark.parametrize("sets", list(SETS))
def test_interp1d(order, sets):
    """
    Test interp1d at OTI scalar, float and array points (inside, at and outside the data) against
    sparse.

    Parameters
    ----------
    order : int
        Truncation order.
    sets : str
        Active-set scenario.
    """

    rng = np.random.default_rng(140 + order)
    xr = np.array([0.0, 0.5, 1.5, 2.0, 3.5])
    xv = _rand_matrix((5, 1), SETS[sets][0], order, rng)
    yv = _rand_matrix((5, 1), SETS[sets][1], order, rng)

    for i in range(5):

        xv[i, 0] = xv[i, 0] - xv[i, 0].real + xr[i]

    # end for

    sxv, axv = _both_layouts(xv)
    syv, ayv = _both_layouts(yv)

    for probe in (-1.0, 0.0, 0.7, 1.5, 3.4, 4.0):

        px = _rand_scalar(SETS[sets][0], order, rng, real=probe)
        ref = sparse.interp1d(px, xv, yv)
        _same_scalar(semi.interp1d(semi.ssotinum(px), sxv, syv), ref, order, f"soa at {probe}")
        _same_scalar(semi.interp1d(semi.ssotinum(px), axv, ayv), ref, order, f"aos at {probe}")

    # end for

    _same_scalar(semi.interp1d(0.7, sxv, syv), sparse.interp1d(sparse.zero() + 0.7, xv, yv),
                 order, "float point")

    pts = _rand_matrix((2, 2), SETS[sets][0], order, rng)
    pts[0, 0] = pts[0, 0] - pts[0, 0].real - 1.0
    pts[1, 1] = pts[1, 1] - pts[1, 1].real + 2.2
    ref = sparse.interp1d(pts, xv, yv)
    _same_array(semi.interp1d(semi.oarrss.from_sparse(pts), sxv, syv), ref, order, "soa points")
    _same_array(semi.interp1d(semi.arrss.from_sparse(pts), axv, ayv), ref, order, "aos points")

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("order", ORDERS)
@pytest.mark.parametrize("size", [1, 2, 3, 4])
def test_moving_average(order, size):
    """
    Test moving_average against sparse for odd and even windows.

    Parameters
    ----------
    order : int
        Truncation order.
    size : int
        Window size.
    """

    rng = np.random.default_rng(150 + order)
    data = _rand_matrix((7, 1), [1, 3], order, rng)
    ref = sparse.moving_average(data, size)
    soa, aos = _both_layouts(data)
    _same_array(semi.moving_average(soa, size), ref, order, "soa")
    _same_array(semi.moving_average(aos, size), ref, order, "aos")

    with pytest.raises(ValueError):

        semi.moving_average(soa, 0)

    # end with

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("order", ORDERS)
@pytest.mark.parametrize("sets", list(SETS))
def test_inv_block(order, sets):
    """
    Test inv_block against sparse inv_block for both layouts.

    Parameters
    ----------
    order : int
        Truncation order.
    sets : str
        Active-set scenario.
    """

    rng = np.random.default_rng(160 + order)
    bases = SETS[sets][0] + [b for b in SETS[sets][1] if b not in SETS[sets][0]]
    m = _rand_matrix((3, 3), bases, order, rng)

    for i in range(3):

        m[i, i] = m[i, i] + 4.0

    # end for

    ref = sparse.inv_block(m)
    soa, aos = _both_layouts(m)
    _same_array(semi.inv_block(soa), ref, order, "soa")
    _same_array(semi.inv_block(aos), ref, order, "aos")

    out = semi.zeros((3, 3))
    assert semi.inv_block(soa, out=out) is None
    _same_array(out, ref, order, "soa out")

    with pytest.raises(ValueError):

        semi.inv_block(semi.zeros((2, 3)))

    # end with

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_unsupported_types():
    """
    Test that the Phase 2 functions reject unsupported operands with TypeError.
    """

    with pytest.raises(TypeError):

        semi.get_order_im(1, 3.0)

    # end with

    with pytest.raises(TypeError):

        semi.extract_im(1, "x")

    # end with

    with pytest.raises(TypeError):

        semi.trunc_dot(1, 2.0, 1, semi.zeros((2, 2)))

    # end with

    with pytest.raises(TypeError):

        semi.dot_product(np.ones((2, 1)), np.ones((2, 1)))

    # end with

    with pytest.raises(TypeError):

        semi.get_order_im_array(1, 2.0)

    # end with

# end function
# --------------------------------------------------------------------------------------------------------
