"""
Test the public finite-element API against algebra-neutral affine identities.
"""

import numpy as np
import pytest

import pyoti.dense as dense
import pyoti.fem as fem
import pyoti.semisparse as semisparse
import pyoti.sparse as sparse


ELEMENT_IDS = (1, 2, 3, 4, 5, 6, 8, 9, 10, 11, 15, 16, 17, 18)


# ********************************************************************************************************
@pytest.fixture(
    params=[
        pytest.param(sparse, id="sparse"),
        pytest.param(semisparse, id="semisparse"),
        pytest.param(dense, id="dense"),
    ]
)
def algebra(request):
    """
    Select an FEM algebra and restore the sparse default after each test.

    Parameters
    ----------
    request : pytest.FixtureRequest
        Fixture request containing the selected algebra parameter.

    Returns
    -------
    module
        The selected OTI algebra module.
    """
    selected = request.param

    try:

        fem.set_global_algebra(selected)

    except ValueError as error:

        if selected is semisparse or selected is dense:

            fem.set_global_algebra(sparse)
            pytest.skip(f"{selected.__name__} FEM algebra is not available yet: {error}")

        # end if

        raise

    # end try

    try:

        yield selected

    finally:

        fem.end_elements()
        fem.set_global_algebra(sparse)

    # end try

# end function

# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _reference_nodes(element_id):
    """
    Return reference-space nodes in the element's basis-function order.

    Parameters
    ----------
    element_id : int
        Gmsh element identifier exposed by ``fem.element``.

    Returns
    -------
    numpy.ndarray
        Reference node coordinates with three columns.
    """
    nodes = {
        1: [(-1, 0, 0), (1, 0, 0)],
        2: [(0, 0, 0), (1, 0, 0), (0, 1, 0)],
        3: [(-1, -1, 0), (1, -1, 0), (1, 1, 0), (-1, 1, 0)],
        4: [(0, 0, 0), (1, 0, 0), (0, 1, 0), (0, 0, 1)],
        5: [
            (-1, -1, -1), (1, -1, -1), (1, 1, -1), (-1, 1, -1),
            (-1, -1, 1), (1, -1, 1), (1, 1, 1), (-1, 1, 1),
        ],
        6: [(0, 0, -1), (1, 0, -1), (0, 1, -1),
            (0, 0, 1), (1, 0, 1), (0, 1, 1)],
        8: [(-1, 0, 0), (1, 0, 0), (0, 0, 0)],
        9: [(0, 0, 0), (1, 0, 0), (0, 1, 0),
            (0.5, 0, 0), (0.5, 0.5, 0), (0, 0.5, 0)],
        10: [
            (-1, -1, 0), (1, -1, 0), (1, 1, 0), (-1, 1, 0),
            (0, -1, 0), (1, 0, 0), (0, 1, 0), (-1, 0, 0), (0, 0, 0),
        ],
        11: [
            (0, 0, 0), (1, 0, 0), (0, 1, 0), (0, 0, 1),
            (0.5, 0, 0), (0.5, 0.5, 0), (0, 0.5, 0),
            (0, 0, 0.5), (0.5, 0, 0.5), (0, 0.5, 0.5),
        ],
        15: [(0, 0, 0)],
        16: [
            (-1, -1, 0), (1, -1, 0), (1, 1, 0), (-1, 1, 0),
            (0, -1, 0), (1, 0, 0), (0, 1, 0), (-1, 0, 0),
        ],
        17: [
            (-1, -1, -1), (1, -1, -1), (1, 1, -1), (-1, 1, -1),
            (-1, -1, 1), (1, -1, 1), (1, 1, 1), (-1, 1, 1),
            (0, -1, -1), (-1, 0, -1), (-1, -1, 0),
            (1, 0, -1), (1, -1, 0), (0, 1, -1),
            (1, 1, 0), (-1, 1, 0), (0, -1, 1),
            (-1, 0, 1), (1, 0, 1), (0, 1, 1),
        ],
        18: [
            (0, 0, -1), (1, 0, -1), (0, 1, -1),
            (0, 0, 1), (1, 0, 1), (0, 1, 1),
            (0.5, 0, -1), (0.5, 0.5, -1), (0, 0.5, -1),
            (0.5, 0, 1), (0.5, 0.5, 1), (0, 0.5, 1),
            (0, 0, 0), (1, 0, 0), (0, 1, 0),
        ],
    }

    return np.asarray(nodes[element_id], dtype=float)

# end function

# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _real_array(value):
    """
    Convert an OTI scalar or array's real part to a NumPy array.

    Parameters
    ----------
    value : object
        OTI scalar or array.

    Returns
    -------
    numpy.ndarray
        Real coefficients as a NumPy array.
    """
    return np.asarray(value.real)

# end function

# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _real_value(value):
    """
    Return an OTI scalar's real coefficient as a Python float.

    Parameters
    ----------
    value : object
        OTI scalar.

    Returns
    -------
    float
        Real coefficient.
    """
    return float(np.asarray(value.real).item())

# end function

# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _mapped_coordinates(algebra, nodes, perturb=False):
    """
    Build nodal coordinates for a translated, diagonal affine map.

    Parameters
    ----------
    algebra : module
        Algebra used to construct OTI coordinate arrays.
    nodes : numpy.ndarray
        Reference node coordinates with three columns.
    perturb : bool, optional
        Add the reference-x coordinate times the third OTI direction to physical x.

    Returns
    -------
    tuple
        Three algebra arrays containing the physical x, y, and z nodal coordinates.
    """
    offsets = (0.25, -0.75, 0.5)
    scales = (2.0, 3.0, 4.0)
    x_values = [offsets[0] + scales[0] * node[0] for node in nodes]
    y_values = [offsets[1] + scales[1] * node[1] for node in nodes]
    z_values = [offsets[2] + scales[2] * node[2] for node in nodes]

    if perturb:

        epsilon = algebra.e(3, order=2)
        x_values = [value + node[0] * epsilon for value, node in zip(x_values, nodes)]

    # end if

    return (
        algebra.array(x_values),
        algebra.array(y_values),
        algebra.array(z_values),
    )

# end function

# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _reference_measure(element_id):
    """
    Return the reference measure of a supported one-, two-, or three-dimensional cell.

    Parameters
    ----------
    element_id : int
        Gmsh element identifier exposed by ``fem.element``.

    Returns
    -------
    float
        Reference line length, area, or volume.
    """
    if element_id in (1, 8):

        return 2.0

    # end if

    if element_id in (2, 9):

        return 0.5

    # end if

    if element_id in (3, 10, 16):

        return 4.0

    # end if

    if element_id in (4, 11):

        return 1.0 / 6.0

    # end if

    if element_id in (5, 17):

        return 8.0

    # end if

    if element_id in (6, 18):

        return 1.0

    # end if

    raise ValueError(f"Element {element_id} has no positive-dimensional reference measure")

# end function

# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("element_id", ELEMENT_IDS)
def test_element_partition_patch_and_affine_integration(algebra, element_id):
    """
    Check partition of unity, patch identities, element metadata, and affine integration.

    Parameters
    ----------
    algebra : module
        FEM algebra selected by the fixture.
    element_id : int
        Gmsh element identifier exposed by ``fem.element``.
    """
    element = fem.element[element_id]
    element.end()
    element.allocate(intorder=2)

    assert element.nip > 0
    assert element.nbasis == len(_reference_nodes(element_id))

    if element_id == 15:

        element.allocate_spatial(0, compute_Jinv=True)
        assert element.J.shape == (0, 0)
        assert element.Jinv.shape == (0, 0)
        np.testing.assert_allclose(_real_array(element.N.get_ip(0)).sum(), 1.0)
        assert _real_value(element.w[0]) == pytest.approx(1.0)
        _real_value(element.detJ[0])
        _real_value(element.dV[0])
        return

    # end if

    nodes = _reference_nodes(element_id)
    ndim = element.ndim
    element.allocate_spatial(ndim, compute_Jinv=True)
    coordinates = _mapped_coordinates(algebra, nodes)
    indices = np.arange(element.nbasis, dtype=np.int64)
    element.set_coordinates(*coordinates, indices)
    element.compute_jacobian()

    scales = np.asarray((2.0, 3.0, 4.0)[:ndim])
    offsets = np.asarray((0.25, -0.75, 0.5)[:ndim])
    directions = (element.Nx, element.Ny, element.Nz)[:ndim]
    nodal_coordinates = tuple(
        _real_array(axis).reshape(-1) for axis in (element.x, element.y, element.z)
    )
    integrated_measure = 0.0

    for ip in range(element.nip):

        shape = _real_array(element.N.get_ip(ip)).reshape(-1)
        np.testing.assert_allclose(shape.sum(), 1.0, atol=1e-13)

        natural_point = np.asarray(
            [_real_value(value[ip]) for value in (element.xi, element.eta, element.zeta)]
        )

        for coordinate_axis in range(ndim):

            interpolated = np.dot(shape, nodal_coordinates[coordinate_axis])
            expected_coordinate = offsets[coordinate_axis] + (
                scales[coordinate_axis] * natural_point[coordinate_axis]
            )
            np.testing.assert_allclose(interpolated, expected_coordinate, atol=1e-12)

        # end for

        for derivative_axis, derivative_array in enumerate(directions):

            derivative = _real_array(derivative_array.get_ip(ip)).reshape(-1)
            np.testing.assert_allclose(derivative.sum(), 0.0, atol=1e-13)

            for coordinate_axis in range(ndim):

                expected_derivative = float(derivative_axis == coordinate_axis)
                patch_derivative = np.dot(derivative, nodal_coordinates[coordinate_axis])
                np.testing.assert_allclose(
                    patch_derivative,
                    expected_derivative,
                    atol=1e-12,
                )

            # end for

        # end for

        expected_jacobian = np.diag(scales)
        np.testing.assert_allclose(
            _real_array(element.J.get_ip(ip)),
            expected_jacobian,
            rtol=1e-13,
            atol=1e-13,
        )
        np.testing.assert_allclose(
            _real_array(element.Jinv.get_ip(ip)),
            np.diag(1.0 / scales),
            rtol=1e-13,
            atol=1e-13,
        )
        jacobian_det = float(np.prod(scales))
        np.testing.assert_allclose(_real_value(element.detJ[ip]), jacobian_det)
        integrated_measure += _real_value(element.dV[ip])

    # end for

    expected_measure = _reference_measure(element_id) * float(np.prod(scales))
    np.testing.assert_allclose(integrated_measure, expected_measure, rtol=1e-12)

# end function

# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("element_id", tuple(value for value in ELEMENT_IDS if value != 15))
def test_affine_coordinate_sensitivity(algebra, element_id):
    """
    Check derivatives of the Jacobian and its determinant for affine nodal perturbations.

    Parameters
    ----------
    algebra : module
        FEM algebra selected by the fixture.
    element_id : int
        Gmsh element identifier exposed by ``fem.element``.
    """
    element = fem.element[element_id]
    element.end()
    element.allocate(intorder=2)
    ndim = element.ndim
    element.allocate_spatial(ndim, compute_Jinv=True)

    nodes = _reference_nodes(element_id)
    coordinates = _mapped_coordinates(algebra, nodes, perturb=True)
    indices = np.arange(element.nbasis, dtype=np.int64)
    element.set_coordinates(*coordinates, indices)
    element.compute_jacobian()

    scales = np.asarray((2.0, 3.0, 4.0)[:ndim])
    expected_jacobian_derivative = np.zeros((ndim, ndim))
    expected_jacobian_derivative[0, 0] = 1.0
    expected_det_derivative = float(np.prod(scales[1:]))

    for ip in range(element.nip):

        jacobian = element.J.get_ip(ip)
        np.testing.assert_allclose(
            _real_array(jacobian.get_deriv(3)),
            expected_jacobian_derivative,
            rtol=1e-13,
            atol=1e-13,
        )
        np.testing.assert_allclose(
            element.detJ[ip].get_deriv(3),
            expected_det_derivative,
            rtol=1e-12,
            atol=1e-12,
        )

    # end for

# end function

# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_quad4_plane_strain_stiffness(algebra):
    """
    Check Quad4 plane-strain stiffness symmetry, rigid modes, and Young's-modulus derivative.

    Parameters
    ----------
    algebra : module
        FEM algebra selected by the fixture.
    """
    element = fem.element[3]
    element.end()
    element.allocate(intorder=2)
    element.allocate_spatial(2, compute_Jinv=True)

    nodes = _reference_nodes(3)
    coordinates = _mapped_coordinates(algebra, nodes)
    indices = np.arange(element.nbasis, dtype=np.int64)
    element.set_coordinates(*coordinates, indices)
    element.compute_jacobian()

    youngs_modulus = 200.0e9 + algebra.e(1, order=2)
    poisson_ratio = 0.3 + algebra.e(2, order=2)
    factor = youngs_modulus / (
        (1.0 + poisson_ratio) * (1.0 - 2.0 * poisson_ratio)
    )
    elasticity = algebra.zeros((3, 3), order=2)
    elasticity[0, 0] = factor * (1.0 - poisson_ratio)
    elasticity[0, 1] = factor * poisson_ratio
    elasticity[1, 0] = factor * poisson_ratio
    elasticity[1, 1] = factor * (1.0 - poisson_ratio)
    elasticity[2, 2] = factor * (1.0 - 2.0 * poisson_ratio) / 2.0

    stiffness = algebra.zeros((8, 8), order=2)

    for ip in range(element.nip):

        dx = element.Nx.get_ip(ip)
        dy = element.Ny.get_ip(ip)
        strain_displacement = algebra.zeros((3, 8), order=2)

        for node in range(element.nbasis):

            strain_displacement[0, 2 * node] = dx[0, node]
            strain_displacement[1, 2 * node + 1] = dy[0, node]
            strain_displacement[2, 2 * node] = dy[0, node]
            strain_displacement[2, 2 * node + 1] = dx[0, node]

        # end for

        contribution = algebra.dot(
            algebra.dot(strain_displacement.T, elasticity),
            strain_displacement,
        )
        stiffness = stiffness + contribution * element.dV[ip]

    # end for

    stiffness_real = _real_array(stiffness)
    np.testing.assert_allclose(stiffness_real, stiffness_real.T, rtol=1e-13, atol=1e-4)

    eigenvalues = np.linalg.eigvalsh(stiffness_real)
    relative_cutoff = 1e-10 * np.max(np.abs(eigenvalues))
    assert np.count_nonzero(np.abs(eigenvalues) < relative_cutoff) == 3

    modulus_derivative = _real_array(stiffness.get_deriv(1))
    np.testing.assert_allclose(
        modulus_derivative,
        stiffness_real / 200.0e9,
        rtol=5e-12,
        atol=1e-13,
    )

# end function

# --------------------------------------------------------------------------------------------------------
