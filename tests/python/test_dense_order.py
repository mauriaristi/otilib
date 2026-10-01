"""
Compare the dense order and derivative plumbing (pyoti.dense, WP9 of PLAN-dense-update.md) with the
pyoti.sparse oracle: get_order_im, extract_im / extract_deriv, get_all_ims / get_all_derivs,
get_order_im_array / set_order_im_from_array, trunc_dot, trunc_sub, dot_product, rom_eval*,
interp1d, moving_average and inv_block.

Every comparison is at 1e-13 relative, at orders 1 to 5, for operands over the same base set, a
leading (prefix) set and the semi-sparse "interleaved" sets, which for dense are operands with a
different nact (bases up to 6). Dense-specific cases follow: nact above Nbasis(p + q) (the product
table fallback), bases beyond a layout or a value's nact, order validation and singular real parts.
Where pyoti.sparse has no test of its own for a function, a sparse-side check against an independent
computation comes first, so that the oracle itself is verified.
"""

import itertools
import os
import subprocess
import sys

import numpy as np
import pytest

import pyoti.dense as dn
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
    Export a sparse or dense scalar in the get_all_ims layout over NB bases.

    Parameters
    ----------
    x : sotinum or otinum
        Scalar.
    order : int
        Highest order of the layout.

    Returns
    -------
    numpy.ndarray
        Coefficients, real part first.
    """

    if isinstance(x, dn.otinum):

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
    Export a sparse or dense array in the get_all_ims layout over NB bases.

    Parameters
    ----------
    a : matso or omat or arro
        Array.
    order : int
        Highest order of the layout.

    Returns
    -------
    numpy.ndarray
        Coefficients, shape (directions, rows, columns).
    """

    if isinstance(a, (dn.omat, dn.arro)):

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
    Assert a dense scalar equals a sparse one in every direction.

    Parameters
    ----------
    actual : otinum
        Dense result.
    expected : sotinum
        Sparse reference.
    order : int
        Highest compared order.
    msg : str
        Context for the failure message.
    """

    assert isinstance(actual, dn.otinum), msg
    _close(_scalar_layout(actual, order), _scalar_layout(expected, order), msg)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _same_array(actual, expected, order, msg=""):
    """
    Assert a dense array equals a sparse one in every element and direction.

    Parameters
    ----------
    actual : omat or arro
        Dense result.
    expected : matso
        Sparse reference.
    order : int
        Highest compared order.
    msg : str
        Context for the failure message.
    """

    assert isinstance(actual, (dn.omat, dn.arro)), msg
    _close(_array_layout(actual, order), _array_layout(expected, order), msg)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _both_layouts(m):
    """
    Convert a sparse matrix to both dense layouts.

    Parameters
    ----------
    m : matso
        Sparse matrix.

    Returns
    -------
    tuple
        (omat, arro).
    """

    return dn.omat.from_sparse(m), dn.arro.from_sparse(m)

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

        _same_scalar(dn.get_order_im(k, dn.otinum(x)), sparse.get_order_im(k, x), order,
                     f"scalar order {k}")
        ref = sparse.get_order_im(k, m)
        _same_array(dn.get_order_im(k, soa), ref, order, f"soa order {k}")
        _same_array(dn.get_order_im(k, aos), ref, order, f"aos order {k}")

        out = dn.zeros((2, 3))
        assert dn.get_order_im(k, soa, out=out) is None
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
    sx = dn.otinum(x)
    dirs = [[bases[0]], [bases[-1]], [bases[0], bases[-1]], [bases[0], bases[0]],
            [bases[0]] * min(order, 3)]

    if other:

        dirs.append([other[0]])
        dirs.append([bases[0], other[0]])

    # end if

    for d in dirs:

        for name in ("extract_im", "extract_deriv"):

            sfun = getattr(dn, name)
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

            out = dn.otinum(0.0)
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
    smaller than nact (directions outside it are left out).

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

    # A layout over fewer bases than nact: only directions within it are exported.
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
        _close(dn.get_order_im_array(ordi, soa), ref, f"soa order {ordi}")
        _close(dn.get_order_im_array(ordi, aos), ref, f"aos order {ordi}")

    # end for

    # Above the truncation order sparse exports one zero direction.
    _close(dn.get_order_im_array(order + 1, soa), np.zeros((3, 2)), "empty order")
    _close(dn.get_order_im_array(0, soa), m.real, "order 0 is the real part")

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
    Test set_order_im_from_array on both layouts against sparse: the target grows its nact
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
        dn.set_order_im_from_array(ordi, vals, soa)
        dn.set_order_im_from_array(ordi, vals, aos)
        _same_array(soa, ref, order, f"soa order {ordi}")
        _same_array(aos, ref, order, f"aos order {ordi}")
        assert soa.order == max(1, ordi)

    # end for

    with pytest.raises(ValueError):

        dn.set_order_im_from_array(1, np.zeros((3, 3)), dn.zeros((2, 3)))

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
            res = dn.trunc_dot(oa, sa, ob, sb)
            assert isinstance(res, dn.omat)
            _same_array(res, ref, order, f"soa ({oa}, {ob})")
            res = dn.trunc_dot(oa, aa, ob, ab)
            assert isinstance(res, dn.arro)
            _same_array(res, ref, order, f"aos ({oa}, {ob})")

        # end for

    # end for

    out = sb.copy() if hasattr(sb, "copy") else dn.omat.from_sparse(b)
    assert dn.trunc_dot(0, sb, 1, out, out=out) is None
    _same_array(out, _trunc_dot_reference(0, b, 1, b), order, "out aliasing the right operand")

    with pytest.raises(ValueError):

        dn.trunc_dot(1, sb, 1, sa)

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
        _same_array(dn.trunc_sub(k, sa, sb), ref, order, f"soa order {k}")
        _same_array(dn.trunc_sub(k, aa, ab), ref, order, f"aos order {k}")

        out = dn.omat.from_sparse(a)
        assert dn.trunc_sub(k, out, sb, out=out) is None
        _same_array(out, ref, order, f"soa out aliasing order {k}")

        _same_scalar(dn.trunc_sub(k, dn.otinum(x), dn.otinum(y)),
                     sparse.get_order_im(k, x - y), order, f"scalar order {k}")

    # end for

    with pytest.raises(ValueError):

        dn.trunc_sub(1, sa, dn.zeros((3, 2)))

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

        for layout in (dn.omat, dn.arro):

            res = dn.dot_product(layout.from_sparse(lhs), layout.from_sparse(rhs))
            _same_scalar(res, ref, order, f"{layout.__name__} {lhs.shape}.{rhs.shape}")

        # end for

    # end for

    ref = sparse.dot_product(a, sparse.array(real))
    _same_scalar(dn.dot_product(dn.omat.from_sparse(a), real), ref, order, "real rhs")
    _same_scalar(dn.dot_product(real, dn.omat.from_sparse(a)), ref, order, "real lhs")

    out = dn.otinum(0.0)
    assert dn.dot_product(dn.omat.from_sparse(col), dn.omat.from_sparse(row),
                            out=out) is None
    _same_scalar(out, sparse.dot_product(col, row), order, "out")

    with pytest.raises(ValueError):

        dn.dot_product(dn.omat.from_sparse(col), dn.omat.from_sparse(a))

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

    res = dn.otinum(x).rom_eval(listed, deltas)
    assert res.order == 0
    _close(res.real, x.rom_eval(listed, deltas).real, "scalar")

    ref = m.rom_eval(listed, deltas).real
    _close(soa.rom_eval(listed, deltas).real, ref, "soa")
    _close(aos.rom_eval(listed, deltas).to_sparse().real, ref, "aos")

    # A single delta perturbs every active base.
    full = m.rom_eval(bases, [0.1] * len(bases)).real
    _close(soa.rom_eval(None, 0.1).real, full, "soa with one delta for every base")
    _close(aos.rom_eval(None, 0.1).to_sparse().real, full, "aos with one delta for every base")

    with pytest.raises(ValueError):

        dn.otinum(x).rom_eval([1, 2], [0.1])

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
    Test otinum.rom_eval_array (2-D grids of deltas) and rom_eval_object (float and OTI deltas).

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
    sx = dn.otinum(x)
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
        _same_scalar(dn.interp1d(dn.otinum(px), sxv, syv), ref, order, f"soa at {probe}")
        _same_scalar(dn.interp1d(dn.otinum(px), axv, ayv), ref, order, f"aos at {probe}")

    # end for

    _same_scalar(dn.interp1d(0.7, sxv, syv), sparse.interp1d(sparse.zero() + 0.7, xv, yv),
                 order, "float point")

    pts = _rand_matrix((2, 2), SETS[sets][0], order, rng)
    pts[0, 0] = pts[0, 0] - pts[0, 0].real - 1.0
    pts[1, 1] = pts[1, 1] - pts[1, 1].real + 2.2
    ref = sparse.interp1d(pts, xv, yv)
    _same_array(dn.interp1d(dn.omat.from_sparse(pts), sxv, syv), ref, order, "soa points")
    _same_array(dn.interp1d(dn.arro.from_sparse(pts), axv, ayv), ref, order, "aos points")

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
    _same_array(dn.moving_average(soa, size), ref, order, "soa")
    _same_array(dn.moving_average(aos, size), ref, order, "aos")

    with pytest.raises(ValueError):

        dn.moving_average(soa, 0)

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
    _same_array(dn.inv_block(soa), ref, order, "soa")
    _same_array(dn.inv_block(aos), ref, order, "aos")

    out = dn.zeros((3, 3))
    assert dn.inv_block(soa, out=out) is None
    _same_array(out, ref, order, "soa out")

    with pytest.raises(ValueError):

        dn.inv_block(dn.zeros((2, 3)))

    # end with

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_unsupported_types():
    """
    Test that the order functions reject unsupported operands with TypeError.
    """

    with pytest.raises(TypeError):

        dn.get_order_im(1, 3.0)

    # end with

    with pytest.raises(TypeError):

        dn.extract_im(1, "x")

    # end with

    with pytest.raises(TypeError):

        dn.trunc_dot(1, 2.0, 1, dn.zeros((2, 2)))

    # end with

    with pytest.raises(TypeError):

        dn.dot_product(np.ones((2, 1)), np.ones((2, 1)))

    # end with

    with pytest.raises(TypeError):

        dn.get_order_im_array(1, 2.0)

    # end with

# end function
# --------------------------------------------------------------------------------------------------------


# --------------------------------------------------------------------------------------------------------
# Dense-specific cases
# --------------------------------------------------------------------------------------------------------

# ********************************************************************************************************
def _twin_matrix(shape, bases, order, rng, shift=0.0):
    """
    Build the same random matrix as a dense SoA array and a semi-sparse SoA array.

    Parameters
    ----------
    shape : tuple of int
        Rows and columns.
    bases : list of int
        Bases with nonzero coefficients.
    order : int
        Truncation order.
    rng : numpy.random.Generator
        Random generator.
    shift : float
        Added to the diagonal real parts.

    Returns
    -------
    tuple
        (omat, oarrss) holding identical values.
    """

    d = dn.zeros(shape, order=order)
    s = semi.zeros(shape, order=order)

    for i in range(shape[0]):

        for j in range(shape[1]):

            real = rng.uniform(1.0, 2.0) + (shift if i == j else 0.0)
            xd = dn.otinum(real, order=order)
            xs = semi.ssotinum(real, order=order)

            for p in range(1, order + 1):

                for c in itertools.combinations_with_replacement(bases, p):

                    val = rng.uniform(-0.5, 0.5)
                    xd.set_im(val, list(c))
                    xs.set_im(val, list(c))

                # end for

            # end for

            d[i, j] = xd
            s[i, j] = xs

        # end for

    # end for

    return d, s

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _same_as_semi(actual, expected, bases, order, msg=""):
    """
    Assert a dense value equals a semi-sparse one in every direction over the given bases.

    Parameters
    ----------
    actual : otinum or omat or arro
        Dense result.
    expected : ssotinum or oarrss
        Semi-sparse reference.
    bases : list of int
        Bases whose directions are compared (every nonzero direction must use only these).
    order : int
        Highest compared order.
    msg : str
        Context for the failure message.
    """

    dirs = [[]] + [list(c) for p in range(1, order + 1)
                   for c in itertools.combinations_with_replacement(bases, p)]

    got = [actual.real if not d else actual.get_im(d) for d in dirs]
    ref = [expected.real if not d else expected.get_im(d) for d in dirs]
    _close(got, ref, msg)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("order", [3, 5])
def test_fallback_nact_above_nbasis(order):
    """
    Test the products with nact = 11, above Nbasis(5) = 10 (the product-table fallback), against
    semi-sparse over the bases {1, 2, 11} (pyoti.sparse cannot hold base 11 at order 5):
    trunc_dot, dot_product, trunc_sub, inv_block, extract_deriv, both dense layouts.

    Parameters
    ----------
    order : int
        Truncation order.
    """

    rng = np.random.default_rng(170 + order)
    union = [1, 2, 11]
    da, sa = _twin_matrix((2, 2), [1, 11], order, rng, shift=4.0)
    db, sb = _twin_matrix((2, 2), [2, 11], order, rng)
    assert da.nact == 11 and db.nact == 11

    for oa in range(order + 1):

        ob = order - oa
        ref = semi.trunc_dot(oa, sa, ob, sb)
        _same_as_semi(dn.trunc_dot(oa, da, ob, db), ref, union, order, f"soa trunc_dot {oa}")
        _same_as_semi(dn.trunc_dot(oa, da.to_aos(), ob, db.to_aos()).to_soa(), ref, union,
                      order, f"aos trunc_dot {oa}")

    # end for

    _same_as_semi(dn.dot_product(da, db), semi.dot_product(sa, sb), union, order, "dot_product")
    _same_as_semi(dn.inv_block(da), semi.inv_block(sa), union, order, "inv_block")
    _same_as_semi(dn.inv_block(da.to_aos()).to_soa(), semi.inv_block(sa), union, order,
                  "aos inv_block")
    _same_as_semi(dn.trunc_sub(order, da, db), semi.trunc_sub(order, sa, sb), union, order,
                  "trunc_sub")
    _same_as_semi(dn.extract_deriv([1, 11], da), semi.extract_deriv([1, 11], sa), union,
                  order - 2, "extract_deriv")

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("order", ORDERS)
def test_bases_beyond_nact_and_layout(order):
    """
    Test that rom_eval* ignore deltas of bases above nact (their coefficients are zero) and that
    get_all_ims over fewer bases than nact leaves the other directions out, for scalars and arrays.

    Parameters
    ----------
    order : int
        Truncation order.
    """

    rng = np.random.default_rng(180 + order)
    x = _rand_scalar([1, 2], order, rng)
    m = _rand_matrix((2, 2), [1, 2], order, rng)
    dx = dn.otinum(x)
    soa, aos = _both_layouts(m)
    listed = [2, 9, 1]
    deltas = [0.2, 5.0, -0.1]

    _close(dx.rom_eval(listed, deltas).real, x.rom_eval([1, 2], [-0.1, 0.2]).real, "scalar")
    _close(soa.rom_eval(listed, deltas).real, m.rom_eval([1, 2], [-0.1, 0.2]).real, "soa")
    _close(aos.rom_eval(listed, deltas).to_sparse().real, m.rom_eval([1, 2], [-0.1, 0.2]).real,
           "aos")

    grid = [np.full((2, 2), d) for d in deltas]
    _close(dx.rom_eval_array(listed, grid), np.full((2, 2), x.rom_eval([1, 2], [-0.1, 0.2]).real),
           "rom_eval_array")
    _close(dx.rom_eval_object(listed, deltas), x.rom_eval([1, 2], [-0.1, 0.2]).real,
           "rom_eval_object")

    # Scalar export in the get_all_ims layout, over more and fewer bases than nact.
    for nbasis in (NB, 1):

        ref = _scalar_layout(x, order) if nbasis == NB else None
        res = dn._order_get_all_ims(dx, nbasis, order, False)

        if ref is not None:

            _close(res, ref, "scalar get_all_ims")

        else:

            _close(res, [x.real] + [x.get_im([1] * p) for p in range(1, order + 1)],
                   "scalar get_all_ims over one base")

        # end if

    # end for

    with pytest.raises(ValueError):

        dx.rom_eval([0], [0.1])

    # end with

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_set_order_im_from_array_grows_nact():
    """
    Test that set_order_im_from_array raises nact to the largest base with a nonzero value and the
    truncation order to the added order, on both layouts.
    """

    vals = np.array([[0.0, 0.0, 5.0, 0.0]])

    for make in (lambda: dn.zeros((1, 1), order=1), lambda: dn.arro.zeros((1, 1), order=1)):

        arr = make()
        dn.set_order_im_from_array(1, vals, arr)
        assert arr[0, 0].nact == 3
        assert arr[0, 0].get_im(3) == 5.0

        # Global index 2 of order 2 is the direction [2, 2].
        dn.set_order_im_from_array(2, np.array([[0.0, 0.0, 7.0]]), arr)
        assert arr.order == 2
        assert arr[0, 0].get_im([2, 2]) == 7.0
        assert arr[0, 0].get_im(3) == 5.0

    # end for

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_order_validation_and_rawdir():
    """
    Test that orders above 150 raise ValueError, that order 150 works, and that a rawdir direction
    extracts the same as its human form.
    """

    x = 2.0 + dn.e([1, 2], order=3) + 3.0 * dn.e([2, 2, 2], order=3)
    a = dn.zeros((2, 2), order=2) + dn.e(1, order=2)

    for call in (lambda: dn.get_order_im(151, x), lambda: dn.get_order_im_array(151, a),
                 lambda: dn.trunc_dot(151, a, 0, a), lambda: dn.trunc_sub(151, x, x),
                 lambda: dn.set_order_im_from_array(151, np.zeros((2, 2)), a),
                 lambda: a.get_all_ims(2, 151)):

        with pytest.raises(ValueError):

            call()

        # end with

    # end for

    assert dn.get_order_im(150, x).real == 0.0
    assert dn.get_order_im(0, x).real == 2.0

    raw = dn.rawdir(dn.imdir([2, 2])[0], 2)
    _close(_scalar_layout(dn.extract_im(raw, x), 3), _scalar_layout(dn.extract_im([2, 2], x), 3),
           "rawdir extract_im")
    assert dn.extract_im([2, 2], x).get_im(2) == 3.0

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_inv_block_singular_and_out_kinds():
    """
    Test that inv_block raises LinAlgError for a singular real part, and that an AoS result can be
    stored into a SoA ``out`` holder.
    """

    sing = dn.zeros((2, 2), order=1) + dn.e(1, order=1)

    with pytest.raises(np.linalg.LinAlgError):

        dn.inv_block(sing)

    # end with

    with pytest.raises(np.linalg.LinAlgError):

        dn.inv_block(sing.to_aos())

    # end with

    rng = np.random.default_rng(190)
    m = _rand_matrix((2, 2), [1, 2], 2, rng)
    m[0, 0] = m[0, 0] + 4.0
    m[1, 1] = m[1, 1] + 4.0
    out = dn.zeros((2, 2))
    assert dn.inv_block(dn.arro.from_sparse(m), out=out) is None
    assert isinstance(out, dn.omat)
    _same_array(out, sparse.inv_block(m), 2, "aos result into a soa holder")

# end function
# --------------------------------------------------------------------------------------------------------


# --------------------------------------------------------------------------------------------------------
# Review fixes: out= holders, memory budget, invalid inputs, AoS with mixed truncation orders
# --------------------------------------------------------------------------------------------------------

# ********************************************************************************************************
def test_out_holders():
    """
    Test out= in the order functions: a wrong shape raises ValueError naming both shapes, a wrong type
    raises TypeError, and an AoS result goes into a SoA holder and a SoA result into an AoS one.
    """

    rng = np.random.default_rng(200)
    m = _rand_matrix((2, 3), [1, 2], 2, rng)
    soa, aos = _both_layouts(m)
    ref = sparse.get_order_im(1, m)

    with pytest.raises(ValueError, match=r"\(3, 3\).*\(2, 3\)"):

        dn.get_order_im(1, soa, out=dn.zeros((3, 3)))

    # end with

    with pytest.raises(ValueError):

        dn.extract_im(1, aos, out=dn.arro.zeros((1, 1)))

    # end with

    for bad in (np.zeros((2, 3)), dn.otinum(0.0), 3.0):

        with pytest.raises(TypeError):

            dn.get_order_im(1, soa, out=bad)

        # end with

    # end for

    with pytest.raises(TypeError):

        dn.trunc_sub(1, dn.otinum(1.0), dn.otinum(2.0), out=dn.zeros((1, 1)))

    # end with

    out = dn.zeros((2, 3))
    assert dn.get_order_im(1, aos, out=out) is None
    assert isinstance(out, dn.omat)
    _same_array(out, ref, 2, "aos result into a soa holder")

    out = dn.arro.zeros((2, 3))
    assert dn.get_order_im(1, soa, out=out) is None
    assert isinstance(out, dn.arro)
    _same_array(out, ref, 2, "soa result into an aos holder")

    out = dn.arro.zeros((2, 2))
    assert dn.trunc_dot(1, soa, 0, aos.T, out=out) is None
    _same_array(out, _trunc_dot_reference(1, m, 0, m.T), 2, "trunc_dot into an aos holder")

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_oversized_outputs_raise_memory_error():
    """
    Test that outputs far above the dense byte budget raise MemoryError before allocating: a
    get_all_ims layout of 3.6 TB, and a set_order_im_from_array whose one far nonzero would raise the
    target to nact 2829 at trc 4 (21 TB); the target stays valid and unchanged.
    """

    a = dn.zeros((2, 2), order=2)
    a[0, 0] = dn.e([[1, 2]], order=2) + dn.e(2, order=2)

    for call in (lambda: a.get_all_ims(200, 6), lambda: a.get_all_derivs(200, 6),
                 lambda: a.to_aos().get_all_ims(200, 6)):

        with pytest.raises(MemoryError):

            call()

        # end with

    # end for

    z = dn.zeros((1, 1), order=4)
    vals = np.zeros((1, 4_000_001))
    vals[0, 4_000_000] = 1.0

    for target in (z, dn.arro.zeros((1, 1), order=4)):

        with pytest.raises(MemoryError):

            dn.set_order_im_from_array(2, vals, target)

        # end with

        assert target[0, 0].nact == 0
        assert target.order == 4

    # end for

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_budget_from_environment():
    """
    Test OTI_DENSE_MAX_MB in a child process (the budget is read once per process): with 1 MB, a
    16 MB get_all_ims layout and a 2 MB array raise MemoryError while a small one works.
    """

    code = "\n".join([
        "import pyoti.dense as dn",
        "a = dn.zeros((2, 2), order=2) + dn.e(1, order=2)",
        "assert a.get_all_ims(2, 2).shape == (6, 2, 2)",
        "for call in (lambda: a.get_all_ims(60, 3), lambda: dn.zeros((512, 512), order=0)):",
        "    try:",
        "        call()",
        "    except MemoryError:",
        "        pass",
        "    else:",
        "        raise SystemExit('no MemoryError')",
        "print('ok')",
    ])
    env = dict(os.environ, OTI_DENSE_MAX_MB="1")
    run = subprocess.run([sys.executable, "-c", code], env=env, capture_output=True, text=True)
    assert run.returncode == 0 and run.stdout.strip() == "ok", run.stderr

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_invalid_inputs():
    """
    Test interp1d, moving_average and rom_eval* with invalid inputs: empty or too short data, bad
    window sizes, bad base labels, mismatched lengths and shapes, unsupported types.
    """

    xv = dn.array([[0.0], [1.0], [2.0]])
    yv = dn.array([[0.0], [2.0], [4.0]])
    x = 1.0 + dn.e(1, order=2) + dn.e([1, 2], order=2)
    a = dn.zeros((2, 2), order=1) + dn.e(1, order=1)

    for call in (lambda: dn.interp1d(0.5, dn.zeros((0, 1)), dn.zeros((0, 1))),
                 lambda: dn.interp1d(0.5, xv, dn.array([[0.0], [2.0]])),
                 lambda: dn.moving_average(a, 0), lambda: dn.moving_average(a, -3),
                 lambda: x.rom_eval([0], [0.1]), lambda: x.rom_eval([70000], [0.1]),
                 lambda: x.rom_eval([1, 2], [0.1]), lambda: a.rom_eval([1], [0.1, 0.2]),
                 lambda: x.rom_eval_array([], []), lambda: x.rom_eval_array([1], []),
                 lambda: x.rom_eval_array([1, 2], [np.zeros(3), np.zeros(4)]),
                 lambda: x.rom_eval_array([0], [np.zeros(3)]),
                 lambda: x.rom_eval_object([1, 2], [0.1])):

        with pytest.raises(ValueError):

            call()

        # end with

    # end for

    for call in (lambda: dn.interp1d("x", xv, yv), lambda: dn.interp1d(0.5, "x", yv),
                 lambda: dn.moving_average(np.ones((3, 1)), 2), lambda: dn.moving_average(x, 2),
                 lambda: dn._order_rom_eval("x", [1], [0.1]), lambda: dn.inv_block(np.eye(2)),
                 lambda: dn.trunc_sub(1, a, x), lambda: dn.extract_deriv(1, 2.0)):

        with pytest.raises(TypeError):

            call()

        # end with

    # end for

    # Valid edge cases: a point below, at and above the data; a window larger than the data.
    assert dn.interp1d(-1.0, xv, yv).real == 0.0
    assert dn.interp1d(5.0, xv, yv).real == 4.0
    assert dn.interp1d(1.0, xv, yv).real == pytest.approx(2.0)
    _close(dn.moving_average(yv, 10).real, sparse.moving_average(yv.to_sparse(), 10).real,
           "window larger than the data")

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _mixed_trc_matrix(shape, bases, rng, shift=0.0):
    """
    Build a sparse matrix whose elements have different truncation orders (1 to 3, cycling).

    Parameters
    ----------
    shape : tuple of int
        Rows and columns.
    bases : list of int
        Bases.
    rng : numpy.random.Generator
        Random generator.
    shift : float
        Added to the diagonal.

    Returns
    -------
    matso
        Sparse matrix with per-element truncation orders.
    """

    m = sparse.zeros(shape, order=3)
    count = 0

    for i in range(shape[0]):

        for j in range(shape[1]):

            m[i, j] = _rand_scalar(bases, 1 + count % 3, rng) + (shift if i == j else 0.0)
            count += 1

        # end for

    # end for

    return m

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_aos_mixed_trc():
    """
    Test the AoS paths on elements of different truncation orders: the elementwise functions agree
    with sparse element by element, and trunc_dot / dot_product go through SoA, which raises every
    element to the array's largest trc (pinned against the SoA result, documented behaviour).
    """

    rng = np.random.default_rng(210)
    m = _mixed_trc_matrix((3, 3), [1, 2, 3], rng, shift=4.0)
    b = _mixed_trc_matrix((3, 3), [2, 4], rng)
    aos = dn.arro.from_sparse(m)
    aob = dn.arro.from_sparse(b)
    assert sorted({aos[i, j].order for i in range(3) for j in range(3)}) == [1, 2, 3]

    for k in range(4):

        _same_array(dn.get_order_im(k, aos), sparse.get_order_im(k, m), 3, f"get_order_im {k}")

    # end for

    for d in ([1], [2, 3], [1, 1]):

        _same_array(dn.extract_im(d, aos), sparse.extract_im(d, m), 3, f"extract_im {d}")
        _same_array(dn.extract_deriv(d, aos), sparse.extract_deriv(d, m), 3, f"extract_deriv {d}")

    # end for

    for ordi in (1, 2, 3):

        _close(dn.get_order_im_array(ordi, aos), sparse.get_order_im_array(ordi, m),
               f"get_order_im_array {ordi}")

    # end for

    col = _mixed_trc_matrix((5, 1), [1, 3], rng)
    _same_array(dn.moving_average(dn.arro.from_sparse(col), 2), sparse.moving_average(col, 2), 3,
                "moving_average")
    _same_array(dn.inv_block(aos), sparse.inv_block(m), 3, "inv_block")

    # Products go through SoA: every element at the array's trc 3.
    for oa, ob in ((1, 1), (1, 2), (2, 1), (0, 3)):

        res = dn.trunc_dot(oa, aos, ob, aob)
        assert isinstance(res, dn.arro)
        _close(_array_layout(res, 3), _array_layout(dn.trunc_dot(oa, aos.to_soa(), ob,
                                                                 aob.to_soa()), 3),
               f"trunc_dot ({oa}, {ob}) equals the SoA product")
        assert all(res[i, j].order == 3 for i in range(3) for j in range(3))

    # end for

    _same_scalar(dn.dot_product(aos, aob), dn.dot_product(aos.to_soa(), aob.to_soa()).to_sparse(),
                 3, "dot_product equals the SoA product")

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_set_order_im_from_array_refuses_growth_under_block_views():
    """
    Test that set_order_im_from_array raises BufferError instead of growing an omat (higher trc or
    larger nact) while a get_block view is alive, leaving the array and the view intact; values
    that fit the current layout are still added, and growth works once the view is gone.
    """

    a = dn.zeros((2, 2), order=1)
    a[0, 0] = 2.0 * dn.e(1, order=1)
    block = a.get_block(1)

    for ordi, vals in ((2, np.ones((2, 2 * 10))), (1, np.ones((2, 2 * 4)))):

        with pytest.raises(BufferError):

            dn.set_order_im_from_array(ordi, vals, a)

        # end with

        assert a.nact == 1 and a.order == 1
        assert block[0, 0] == 2.0

    # end for

    # Within the layout (order 1 over base 1; zeros beyond it): no growth, the view sees the sum.
    vals = np.zeros((2, 2 * 4))
    vals[:, :2] = 1.0
    dn.set_order_im_from_array(1, vals, a)
    assert block[0, 0] == 3.0 and block[1, 1] == 1.0

    del block
    dn.set_order_im_from_array(2, np.ones((2, 2 * 10)), a)
    assert a.nact == 4 and a.order == 2
    assert a[0, 0].get_im([4, 4]) == 1.0

# end function
# --------------------------------------------------------------------------------------------------------
