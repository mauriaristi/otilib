"""
Check sparse Gauss types and FEM helpers against pointwise sparse operations.
"""

from itertools import combinations_with_replacement

import numpy as np
import pytest

import pyoti.sparse as oti
from pyoti import fem


# ********************************************************************************************************
def _directions(bases, order):
    """
    Enumerate every nonconstant direction through a truncation order.

    Parameters
    ----------
    bases : tuple[int, ...]
        One-based imaginary basis labels.
    order : int
        Highest direction order to include.

    Returns
    -------
    list[tuple[int, ...]]
        Directions in increasing order and colex-independent basis order.
    """
    directions = []

    for degree in range(1, order + 1):

        directions.extend(combinations_with_replacement(bases, degree))

    # end for

    return directions

# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _assert_scalar_close(actual, expected, bases, order):
    """
    Compare a sparse scalar and all its derivatives through the requested order.

    Parameters
    ----------
    actual : sotinum
        Result under test.
    expected : sotinum
        Pointwise sparse oracle.
    bases : tuple[int, ...]
        Active basis labels to compare.
    order : int
        Highest derivative order to compare.
    """
    expected_real = float(expected.real) if hasattr(expected, "real") else float(expected)
    np.testing.assert_allclose(float(actual.real), expected_real, rtol=1e-13, atol=1e-13)

    for direction in _directions(bases, order):

        if hasattr(expected, "get_deriv"):

            expected_derivative = float(expected.get_deriv(direction))

        else:

            expected_derivative = 0.0

        # end if

        np.testing.assert_allclose(
            float(actual.get_deriv(direction)),
            expected_derivative,
            rtol=1e-13,
            atol=1e-13,
        )

    # end for

# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _assert_matrix_close(actual, expected, bases, order):
    """
    Compare sparse matrices and every requested derivative matrix.

    Parameters
    ----------
    actual : matso
        Result under test.
    expected : matso
        Pointwise sparse oracle.
    bases : tuple[int, ...]
        Active basis labels to compare.
    order : int
        Highest derivative order to compare.
    """
    expected_real = np.asarray(expected.real) if hasattr(expected, "real") else np.asarray(expected)
    np.testing.assert_allclose(np.asarray(actual.real), expected_real, rtol=1e-13, atol=1e-13)

    for direction in _directions(bases, order):

        if hasattr(expected, "get_deriv"):

            expected_derivative = np.asarray(expected.get_deriv(direction).real)

        else:

            expected_derivative = np.zeros_like(expected_real)

        # end if

        np.testing.assert_allclose(
            np.asarray(actual.get_deriv(direction).real),
            expected_derivative,
            rtol=1e-13,
            atol=1e-13,
        )

    # end for

# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _assert_gauss_scalar_close(actual, expected, bases, order):
    """
    Compare each point of a sparse Gauss scalar with its sparse oracle.

    Parameters
    ----------
    actual : sotife
        Result under test.
    expected : list[sotinum]
        Pointwise sparse oracle values.
    bases : tuple[int, ...]
        Active basis labels to compare.
    order : int
        Highest derivative order to compare.
    """
    assert actual.nip == len(expected)

    for ip in range(actual.nip):

        _assert_scalar_close(actual[ip], expected[ip], bases, order)

    # end for

# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _assert_gauss_array_close(actual, expected, bases, order):
    """
    Compare every integration-point matrix with its sparse oracle.

    Parameters
    ----------
    actual : matsofe
        Result under test.
    expected : list[matso]
        Pointwise sparse oracle matrices.
    bases : tuple[int, ...]
        Active basis labels to compare.
    order : int
        Highest derivative order to compare.
    """
    assert actual.nip == len(expected)

    for ip in range(actual.nip):

        _assert_matrix_close(actual.get_ip(ip), expected[ip], bases, order)

    # end for

# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_gauss_creators_and_real_views():
    """
    Check sparse scalar and array creators that accept integration-point counts.
    """
    nip = 3
    order = 4
    bases = (1, 2, 3)

    gauss_values = (
        oti.e(1, order=order, nip=nip),
        oti.zero(nbases=len(bases), order=order, nip=nip),
        oti.one(nbases=len(bases), order=order, nip=nip),
        oti.number(2.5, nbases=len(bases), order=order, nip=nip),
    )
    point_values = (
        oti.e(1, order=order),
        oti.zero(nbases=len(bases), order=order),
        oti.one(nbases=len(bases), order=order),
        oti.number(2.5, nbases=len(bases), order=order),
    )

    for actual, expected in zip(gauss_values, point_values):

        _assert_gauss_scalar_close(actual, [expected] * nip, bases, order)

    # end for

    np.testing.assert_allclose(
        gauss_values[0].real_numpy,
        np.zeros(nip),
        rtol=0.0,
        atol=0.0,
    )
    assert float(gauss_values[0][0].get_deriv([1])) == pytest.approx(1.0)

    zeros = oti.zeros((2, 3), nbases=len(bases), order=order, nip=nip)
    ones = oti.ones((2, 3), nbases=len(bases), order=order, nip=nip)
    matrix = oti.array([[1.0, 2.0], [3.0, 4.0]], order=order, nip=nip)

    assert zeros.shape == (2, 3)
    assert ones.shape == (2, 3)
    np.testing.assert_allclose(zeros.real_numpy, np.zeros((2, 3, nip)))
    np.testing.assert_allclose(ones.real_numpy, np.ones((2, 3, nip)))
    np.testing.assert_allclose(
        matrix.real_numpy,
        np.broadcast_to(np.array([[1.0, 2.0], [3.0, 4.0]])[:, :, None], (2, 2, nip)),
    )

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_gauss_scalar_arithmetic_math_and_directions():
    """
    Compare Gauss scalar operations, functions and direction utilities pointwise.
    """
    nip = 3
    order = 4
    bases = (1, 2, 3)
    x = oti.zero(nbases=len(bases), order=order, nip=nip)
    y = oti.zero(nbases=len(bases), order=order, nip=nip)

    for ip in range(nip):

        x[ip] = (
            1.5 + 0.2 * ip
            + oti.e(1, order=order)
            + 0.05 * oti.e([2, 3], order=order)
        )
        y[ip] = (
            2.0 + 0.1 * ip
            + 0.2 * oti.e(2, order=order)
            + 0.03 * oti.e([1, 3], order=order)
        )

    # end for

    scalar = 0.75 + oti.e(3, order=order)
    cases = (
        (x + y, [x[ip] + y[ip] for ip in range(nip)]),
        (x - y, [x[ip] - y[ip] for ip in range(nip)]),
        (x * y, [x[ip] * y[ip] for ip in range(nip)]),
        (x / y, [x[ip] / y[ip] for ip in range(nip)]),
        (x + 1.25, [x[ip] + 1.25 for ip in range(nip)]),
        (1.25 + x, [1.25 + x[ip] for ip in range(nip)]),
        (x - 1.25, [x[ip] - 1.25 for ip in range(nip)]),
        (1.25 - x, [1.25 - x[ip] for ip in range(nip)]),
        (x * 1.25, [x[ip] * 1.25 for ip in range(nip)]),
        (1.25 * x, [1.25 * x[ip] for ip in range(nip)]),
        (x / 1.25, [x[ip] / 1.25 for ip in range(nip)]),
        (1.25 / x, [1.25 / x[ip] for ip in range(nip)]),
        (x + scalar, [x[ip] + scalar for ip in range(nip)]),
        (scalar + x, [scalar + x[ip] for ip in range(nip)]),
        (x - scalar, [x[ip] - scalar for ip in range(nip)]),
        (scalar - x, [scalar - x[ip] for ip in range(nip)]),
        (x * scalar, [x[ip] * scalar for ip in range(nip)]),
        (scalar * x, [scalar * x[ip] for ip in range(nip)]),
        (x / scalar, [x[ip] / scalar for ip in range(nip)]),
        (scalar / x, [scalar / x[ip] for ip in range(nip)]),
    )

    for actual, expected in cases:

        _assert_gauss_scalar_close(actual, expected, bases, order)

    # end for

    _assert_gauss_scalar_close(
        x ** 2,
        [x[ip] ** 2 for ip in range(nip)],
        bases,
        order,
    )

    for function in (oti.sin, oti.cos, oti.exp, oti.log, oti.sqrt):

        _assert_gauss_scalar_close(
            function(x),
            [function(x[ip]) for ip in range(nip)],
            bases,
            order,
        )

    # end for

    _assert_gauss_scalar_close(
        x.truncate([1]), [x[ip].truncate([1]) for ip in range(nip)], bases, order
    )
    _assert_gauss_scalar_close(
        x.get_deriv([1, 2]), [x[ip].get_deriv([1, 2]) for ip in range(nip)], bases, order
    )
    _assert_gauss_scalar_close(
        x.get_im([2, 3]), [x[ip].get_im([2, 3]) for ip in range(nip)], bases, order
    )
    _assert_gauss_scalar_close(
        x.get_order_im(2), [x[ip].get_order_im(2) for ip in range(nip)], bases, order
    )
    assert x.get_active_bases() == [1, 2, 3]
    np.testing.assert_allclose(x.real_numpy, [1.5, 1.7, 1.9], rtol=0.0, atol=1e-14)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_gauss_array_arithmetic_math_linalg_and_integration():
    """
    Check sparse Gauss arrays against pointwise matrices for algebra and integration.
    """
    nip = 3
    order = 4
    bases = (1, 2, 3)
    a = oti.zeros((2, 2), nbases=len(bases), order=order, nip=nip)
    b = oti.zeros((2, 2), nbases=len(bases), order=order, nip=nip)
    a_points = []
    b_points = []

    for ip in range(nip):

        a_point = oti.array(
            [[4.0 + ip, 0.2], [0.2, 3.0 + ip]], nbases=len(bases), order=order
        )
        b_point = oti.array(
            [[2.0 + ip, 0.1], [0.1, 2.5 + ip]], nbases=len(bases), order=order
        )
        a_point[0, 0] += oti.e(1, order=order)
        a_point[0, 1] += 0.1 * oti.e(2, order=order)
        a_point[1, 0] += 0.1 * oti.e(2, order=order)
        a_point[1, 1] += 0.05 * oti.e([1, 3], order=order)
        b_point[0, 0] += 0.05 * oti.e(3, order=order)
        b_point[1, 1] += 0.1 * oti.e([2, 3], order=order)

        for i in range(2):

            for j in range(2):

                a.set_ijk(a_point[i, j], i, j, ip)
                b.set_ijk(b_point[i, j], i, j, ip)

            # end for

        # end for

        a_points.append(a_point)
        b_points.append(b_point)

    # end for

    gauss_scalar = oti.zero(nbases=len(bases), order=order, nip=nip)
    weights = oti.zero(nbases=len(bases), order=order, nip=nip)

    for ip in range(nip):

        gauss_scalar[ip] = 0.5 + 0.1 * ip + 0.05 * oti.e(1, order=order)
        weights[ip] = 0.5 + 0.25 * ip + 0.01 * oti.e(2, order=order)

    # end for

    scalar = 1.5 + oti.e(3, order=order)
    matrix = oti.array([[1.2, 0.3], [0.3, 1.5]], nbases=len(bases), order=order)
    matrix[0, 0] += 0.05 * oti.e([3, 3], order=order)

    cases = (
        (a + b, [lhs + rhs for lhs, rhs in zip(a_points, b_points)]),
        (a - b, [lhs - rhs for lhs, rhs in zip(a_points, b_points)]),
        (a * b, [lhs * rhs for lhs, rhs in zip(a_points, b_points)]),
        (a / b, [lhs / rhs for lhs, rhs in zip(a_points, b_points)]),
        (a + 0.5, [value + 0.5 for value in a_points]),
        (a + gauss_scalar, [value + gauss_scalar[ip] for ip, value in enumerate(a_points)]),
        (a + scalar, [value + scalar for value in a_points]),
        (a + matrix, [value + matrix for value in a_points]),
    )

    for actual, expected in cases:

        _assert_gauss_array_close(actual, expected, bases, order)

    # end for

    for function in (oti.sin, oti.exp, oti.log, oti.sqrt):

        _assert_gauss_array_close(
            function(a), [function(value) for value in a_points], bases, order
        )

    # end for

    _assert_gauss_array_close(oti.dot(a, b), [oti.dot(x, y) for x, y in zip(a_points, b_points)],
                              bases, order)
    _assert_gauss_array_close(oti.inv(a), [oti.inv(value) for value in a_points], bases, order)
    _assert_gauss_array_close(a.T, [value.T for value in a_points], bases, order)
    _assert_gauss_array_close(
        oti.transpose(a), [oti.transpose(value) for value in a_points], bases, order
    )
    _assert_gauss_scalar_close(oti.det(a), [oti.det(value) for value in a_points], bases, order)
    _assert_gauss_array_close(
        a.get_deriv([1, 2]), [value.get_deriv([1, 2]) for value in a_points], bases, order
    )
    _assert_gauss_array_close(
        a.get_im([2, 3]), [value.get_im([2, 3]) for value in a_points], bases, order
    )
    _assert_gauss_array_close(
        a.get_order_im(2), [value.get_order_im(2) for value in a_points], bases, order
    )
    _assert_gauss_array_close(
        a.truncate([1]), [value.truncate([1]) for value in a_points], bases, order
    )
    _assert_gauss_scalar_close(
        a[0, 0], [value[0, 0] for value in a_points], bases, order
    )
    assert a.get_active_bases() == [1, 2, 3]
    np.testing.assert_allclose(
        a.real_numpy,
        np.stack([np.asarray(value.real) for value in a_points], axis=2),
        rtol=1e-13,
        atol=1e-13,
    )

    scalar_integral = oti.gauss_integrate(gauss_scalar, weights)
    scalar_expected = gauss_scalar[0] * weights[0]

    for ip in range(1, nip):

        scalar_expected += gauss_scalar[ip] * weights[ip]

    # end for

    _assert_scalar_close(scalar_integral, scalar_expected, bases, order)

    array_integral = oti.gauss_integrate(a, weights)
    array_expected = a_points[0] * weights[0]

    for ip in range(1, nip):

        array_expected += a_points[ip] * weights[ip]

    # end for

    _assert_matrix_close(array_integral, array_expected, bases, order)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize(
    "element_id, node_x, node_y, area, area_derivative",
    [
        (2, [0.0, 2.0, 0.0], [0.0, 0.0, 1.0], 1.0, 0.5),
        (3, [0.0, 2.0, 2.0, 0.0], [0.0, 0.0, 1.0, 1.0], 2.0, 0.5),
    ],
)
def test_sparse_fem_element_helper_oracle(element_id, node_x, node_y, area, area_derivative):
    """
    Exercise sparse element helpers on tri3 and quad4 elements.

    Parameters
    ----------
    element_id : int
        Element-map key for tri3 or quad4.
    node_x : list[float]
        Nodal x coordinates before the active perturbation.
    node_y : list[float]
        Nodal y coordinates.
    area : float
        Expected physical area.
    area_derivative : float
        Expected derivative with respect to the first OTI basis.
    """
    order = 3
    bases = (1, 2)
    element_indices = np.arange(len(node_x), dtype=np.int64)
    x = oti.array(node_x, nbases=len(bases), order=order)
    y = oti.array(node_y, nbases=len(bases), order=order)
    z = oti.zeros((len(node_x), 1), nbases=len(bases), order=order)
    x[1, 0] += oti.e(1, order=order)
    element = fem.element[element_id].copy()

    element.allocate(2, nbases=len(bases), order=order)
    element.allocate_spatial(2, compute_Jinv=True)
    element.set_coordinates(x, y, z, element_indices)

    assert element.is_allocated()
    assert element.nip > 0
    assert element.N.shape == (1, len(node_x))
    assert element.N.nip == element.nip

    global_values = oti.array(
        [[1.0, 10.0], [2.0, 20.0], [3.0, 30.0], [4.0, 40.0]],
        nbases=len(bases),
        order=order,
    )
    local = element.get_local(global_values)
    local_set = element.elh.set_array(global_values, element_indices)
    expected_local = oti.array(
        [[i + 1.0, 10.0 * (i + 1)] for i in element_indices],
        nbases=len(bases),
        order=order,
    )
    _assert_matrix_close(local, expected_local, bases, order)
    _assert_matrix_close(local_set, expected_local, bases, order)

    element.compute_jacobian()
    fast_j = element.J.copy()
    fast_det = element.detJ.copy()
    fast_dv = element.dV.copy()
    fast_nx = element.Nx.copy()
    fast_ny = element.Ny.copy()

    element.compute_jacobian_bruteforce()
    _assert_gauss_array_close(element.J, [fast_j.get_ip(ip) for ip in range(element.nip)],
                              bases, order)
    _assert_gauss_scalar_close(
        element.detJ,
        [fast_det[ip] for ip in range(element.nip)],
        bases,
        order,
    )
    _assert_gauss_scalar_close(
        element.dV,
        [fast_dv[ip] for ip in range(element.nip)],
        bases,
        order,
    )
    _assert_gauss_array_close(
        element.Nx, [fast_nx.get_ip(ip) for ip in range(element.nip)], bases, order
    )
    _assert_gauss_array_close(
        element.Ny, [fast_ny.get_ip(ip) for ip in range(element.nip)], bases, order
    )

    integral = element.integrate(oti.one(nbases=len(bases), order=order, nip=element.nip))
    expected_integral = area + area_derivative * oti.e(1, order=order)
    _assert_scalar_close(integral, expected_integral, bases, order)

# end function
# --------------------------------------------------------------------------------------------------------
