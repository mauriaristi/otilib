"""
Run the quarter-cylinder finite-element model with a selected pyOTI algebra.

The solve propagates derivatives of material properties, pressures, and optionally
the inner and outer radii through a structured quad4 mesh.
"""

from __future__ import annotations

import argparse
import itertools
import time

import numpy as np

import pyoti.fem as fem


_E = 200.0e9
_NU = 0.3
_PO = 10.0
_PI = 1000.0
_RI = 0.010
_RO = 0.020
_TGV = 1.0e30


# ********************************************************************************************************
def _make_mesh(ri: float, ro: float, ndivs: tuple[int, int]):
    """
    Build the structured quad4 mesh for a quarter annulus.

    Parameters
    ----------
    ri : float
        Inner radius.
    ro : float
        Outer radius.
    ndivs : tuple[int, int]
        Radial and circumferential element counts.

    Returns
    -------
    object
        The FEM mesh with named `ri`, `ro`, `left`, and `right` groups.
    """
    import gmsh

    gmsh.initialize()

    try:

        gmsh.option.setNumber("General.Terminal", 0)
        model = gmsh.model
        geo = model.geo

        center = geo.addPoint(0.0, 0.0, 0.0)
        inner_top = geo.addPoint(0.0, ri, 0.0)
        inner_right = geo.addPoint(ri, 0.0, 0.0)
        outer_top = geo.addPoint(0.0, ro, 0.0)
        outer_right = geo.addPoint(ro, 0.0, 0.0)

        inner_arc = geo.addCircleArc(inner_top, center, inner_right)
        outer_arc = geo.addCircleArc(outer_right, center, outer_top)
        left = geo.addLine(outer_top, inner_top)
        right = geo.addLine(inner_right, outer_right)
        loop = geo.addCurveLoop([inner_arc, right, outer_arc, left])
        surface = geo.addPlaneSurface([loop])

        groups = [
            (0, [center], "center"),
            (0, [inner_top], "ri_left"),
            (0, [inner_right], "ri_right"),
            (0, [outer_top], "ro_left"),
            (0, [outer_right], "ro_right"),
            (1, [inner_arc], "ri"),
            (1, [outer_arc], "ro"),
            (1, [left], "left"),
            (1, [right], "right"),
            (2, [surface], "domain"),
        ]

        for dim, entities, name in groups:

            tag = model.addPhysicalGroup(dim, entities)
            model.setPhysicalName(dim, tag, name)

        # end for

        geo.synchronize()

        for curve in (left, right):

            model.mesh.setTransfiniteCurve(curve, ndivs[0] + 1)

        # end for

        for curve in (inner_arc, outer_arc):

            model.mesh.setTransfiniteCurve(curve, ndivs[1] + 1)

        # end for

        model.mesh.setTransfiniteSurface(surface)
        gmsh.option.setNumber("Mesh.RecombineAll", 1)
        gmsh.option.setNumber("Mesh.ElementOrder", 1)
        model.mesh.generate(2)

        return fem.mesh.from_gmsh(gmsh)

    finally:

        gmsh.finalize()

    # end try

# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _coordinates(algebra, mesh, ri: float, ro: float, order: int, perturb_geometry: bool):
    """
    Create nodal coordinate arrays in the requested algebra.

    Parameters
    ----------
    algebra : module
        The `pyoti.sparse`-compatible algebra module.
    mesh : object
        The real-valued gmsh mesh.
    ri : float
        Inner reference radius.
    ro : float
        Outer reference radius.
    order : int
        Truncation order for radius perturbations.
    perturb_geometry : bool
        Whether to perturb the radii with bases 5 and 6.

    Returns
    -------
    tuple
        Column arrays for the nodal x, y, and z coordinates.
    """
    x_real = np.asarray(mesh.x.real, dtype=np.float64).reshape(-1)
    y_real = np.asarray(mesh.y.real, dtype=np.float64).reshape(-1)
    z_real = np.asarray(mesh.z.real, dtype=np.float64).reshape(-1)

    if perturb_geometry:

        ri_value = ri + algebra.e(5, order=order)
        ro_value = ro + algebra.e(6, order=order)
        x_values = []
        y_values = []

        for x, y in zip(x_real, y_real):

            radius = float(np.hypot(x, y))

            if radius == 0.0:

                x_values.append(0.0)
                y_values.append(0.0)

            else:

                radius_value = ri_value + (radius - ri) * (ro_value - ri_value) / (ro - ri)
                x_values.append(radius_value * (x / radius))
                y_values.append(radius_value * (y / radius))

            # end if

        # end for

    else:

        x_values = x_real.tolist()
        y_values = y_real.tolist()

    # end if

    x_array = algebra.array([[value] for value in x_values])
    y_array = algebra.array([[value] for value in y_values])
    z_array = algebra.array([[value] for value in z_real])

    return x_array, y_array, z_array

# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _constitutive(algebra, youngs_modulus, poisson_ratio):
    """
    Construct the plane-strain constitutive matrix.

    Parameters
    ----------
    algebra : module
        The `pyoti.sparse`-compatible algebra module.
    youngs_modulus : object
        Young's modulus, possibly carrying OTI derivatives.
    poisson_ratio : object
        Poisson's ratio, possibly carrying OTI derivatives.

    Returns
    -------
    object
        The 3 by 3 plane-strain constitutive matrix.
    """
    factor = youngs_modulus / ((1.0 + poisson_ratio) * (1.0 - 2.0 * poisson_ratio))
    values = algebra.array([
        [1.0 - poisson_ratio, poisson_ratio, 0.0],
        [poisson_ratio, 1.0 - poisson_ratio, 0.0],
        [0.0, 0.0, (1.0 - 2.0 * poisson_ratio) / 2.0],
    ])

    return factor * values

# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _analytic_solution(algebra, x, y, youngs_modulus, poisson_ratio, ri, pi, ro, po):
    """
    Evaluate the plane-strain Lamé displacement at one coordinate.

    Parameters
    ----------
    algebra : module
        The `pyoti.sparse`-compatible algebra module.
    x : object
        Horizontal coordinate.
    y : object
        Vertical coordinate.
    youngs_modulus : object
        Young's modulus.
    poisson_ratio : object
        Poisson's ratio.
    ri : object
        Inner radius.
    pi : object
        Inner pressure.
    ro : object
        Outer radius.
    po : object
        Outer pressure.

    Returns
    -------
    tuple
        The horizontal and vertical Lamé displacements.
    """

    if float(x.real) == 0.0 and float(y.real) == 0.0:

        return 0.0, 0.0

    # end if

    coeff_a = ri**2 * ro**2 * (po - pi) / (ro**2 - ri**2)
    coeff_b = (ri**2 * pi - ro**2 * po) / (ro**2 - ri**2)
    radius = algebra.sqrt(x**2 + y**2)
    radial = (1.0 + poisson_ratio) * radius / youngs_modulus
    radial *= (1.0 - 2.0 * poisson_ratio) * coeff_b - coeff_a / radius**2

    return radial * x / radius, radial * y / radius

# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _directions(nbases: int, order: int):
    """
    Generate all nondecreasing basis tuples through the requested order.

    Parameters
    ----------
    nbases : int
        Number of perturbed bases.
    order : int
        Maximum derivative order.

    Returns
    -------
    list[tuple[int, ...]]
        Empty tuple for the value followed by every derivative direction.
    """
    directions = [()]

    for degree in range(1, order + 1):

        directions.extend(itertools.combinations_with_replacement(
            range(1, nbases + 1), degree
        ))

    # end for

    return directions

# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _direction_label(direction: tuple[int, ...], basis_names: dict[int, str]):
    """
    Format a derivative direction as a readable table label.

    Parameters
    ----------
    direction : tuple[int, ...]
        Basis labels defining the derivative.
    basis_names : dict[int, str]
        Mapping from basis labels to parameter names.

    Returns
    -------
    str
        `value` or a derivative label such as `dE_dnu`.
    """

    if not direction:

        return "value"

    # end if

    return "d" + "_d".join(basis_names[basis] for basis in direction)

# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _error_table(solution, exact, basis_names, order: int):
    """
    Compare every computed derivative with the Lamé reference solution.

    Parameters
    ----------
    solution : object
        Finite-element displacement vector.
    exact : object
        Lamé displacement vector at the same nodes.
    basis_names : dict[int, str]
        Mapping from basis labels to parameter names.
    order : int
        Maximum derivative order to include.

    Returns
    -------
    list[dict]
        One row per derivative, containing relative L2 error and maximum absolute error.
    """
    rows = []

    for direction in _directions(len(basis_names), order):

        if direction:

            fem_values = np.asarray(solution.get_deriv(list(direction))).ravel()
            exact_values = np.asarray(exact.get_deriv(list(direction))).ravel()

        else:

            fem_values = np.asarray(solution.real).ravel()
            exact_values = np.asarray(exact.real).ravel()

        # end if

        difference = fem_values - exact_values
        reference_norm = float(np.linalg.norm(exact_values))
        relative_error = (
            float(np.linalg.norm(difference) / reference_norm)
            if reference_norm > 0.0 else None
        )
        maximum_error = float(np.max(np.abs(difference), initial=0.0))
        rows.append({
            "direction": direction,
            "label": _direction_label(direction, basis_names),
            "relative_l2": relative_error,
            "max_abs": maximum_error,
        })

    # end for

    return rows

# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def run(algebra, ndivs, order, perturb_geometry=False):
    """
    Solve the thick-walled-cylinder model and report timings and Lamé errors.

    Parameters
    ----------
    algebra : module
        Algebra module compatible with `pyoti.sparse`, such as `pyoti.sparse`.
    ndivs : tuple[int, int] or list[int]
        Radial and circumferential element counts.
    order : int
        Maximum OTI derivative order.
    perturb_geometry : bool, optional
        Also differentiate with respect to inner and outer radii using bases 5 and 6.

    Returns
    -------
    dict
        Solution `u`, OTI nodal coordinates, stage timings, and the Lamé-error table.

    Examples
    --------
    >>> import pyoti.sparse as sparse
    >>> result = run(sparse, [4, 4], 2)
    >>> result["u"].shape[1]
    1
    """

    if len(ndivs) != 2 or min(ndivs) < 1:

        raise ValueError("ndivs must contain positive radial and circumferential counts")

    # end if

    if order < 0:

        raise ValueError("order must be nonnegative")

    # end if

    if perturb_geometry and order == 0:

        raise ValueError("perturb_geometry requires an order of at least 1")

    # end if

    fem.set_global_algebra(algebra)
    algebra.set_printoptions(terms_print=-1)
    basis_names = {1: "E", 2: "nu", 3: "Po", 4: "Pi"}

    if perturb_geometry:

        basis_names.update({5: "ri", 6: "ro"})

    # end if

    youngs_modulus = _E
    poisson_ratio = _NU
    outer_pressure = _PO
    inner_pressure = _PI
    inner_radius = _RI
    outer_radius = _RO

    if order > 0:

        youngs_modulus += algebra.e(1, order=order)
        poisson_ratio += algebra.e(2, order=order)
        outer_pressure += algebra.e(3, order=order)
        inner_pressure += algebra.e(4, order=order)

    # end if

    if perturb_geometry:

        inner_radius += algebra.e(5, order=order)
        outer_radius += algebra.e(6, order=order)

    # end if

    mesh = _make_mesh(_RI, _RO, tuple(ndivs))
    mesh.x, mesh.y, mesh.z = _coordinates(
        algebra, mesh, _RI, _RO, order, perturb_geometry
    )
    node_count = mesh.x.shape[0]
    dof_count = 2 * node_count
    elements = mesh.elements[2]
    element_records = [
        (int(elements["types"][block_index]), element_nodes)
        for block_index in range(elements["types"].size)
        for element_nodes in elements["indices"][block_index]
    ]
    fem.end_elements()
    timings = {}

    start = time.perf_counter()
    stiffness = algebra.lil_matrix((dof_count, dof_count))

    for center_node in mesh.group_names["center"]["nodes"]:

        stiffness[2 * int(center_node), 2 * int(center_node)] = 1.0
        stiffness[2 * int(center_node) + 1, 2 * int(center_node) + 1] = 1.0

    # end for

    # The material is uniform, so D is the same at every integration point of every element.
    constitutive = _constitutive(algebra, youngs_modulus, poisson_ratio)
    allocated = set()

    for element_type, element_nodes in element_records:

        element = fem.element[element_type]

        # Allocate once per element type; set_coordinates and compute_jacobian overwrite the
        # per-element data.
        if element_type not in allocated:

            element.end()
            element.allocate(intorder=1, nbases=len(basis_names), order=order)
            element.allocate_spatial(2, compute_Jinv=True)
            allocated.add(element_type)

        # end if

        basis_count = element.nbasis
        element.set_coordinates(mesh.x, mesh.y, mesh.z, element_nodes)
        element.compute_jacobian()
        element_stiffness = algebra.zeros((2 * basis_count, 2 * basis_count))

        for ip in range(element.nip):

            nx = element.Nx.get_ip(ip)
            ny = element.Ny.get_ip(ip)
            differential = element.dV[ip]
            strain = algebra.zeros((3, 2 * basis_count))
            strain[0, 0:2 * basis_count:2] = nx
            strain[1, 1:2 * basis_count:2] = ny
            strain[2, 0:2 * basis_count:2] = ny
            strain[2, 1:2 * basis_count:2] = nx
            element_stiffness += algebra.dot(
                strain.T, algebra.dot(constitutive, strain)
            ) * differential

        # end for

        # Global dof of local dof 2 a + d is 2 node_a + d; one call scatters the whole element.
        element_dofs = np.empty(2 * basis_count, dtype=np.int64)
        element_dofs[0::2] = 2 * np.asarray(element_nodes, dtype=np.int64)
        element_dofs[1::2] = element_dofs[0::2] + 1
        stiffness.add_block(element_dofs, element_dofs, element_stiffness)

    # end for

    timings["assembly_K"] = time.perf_counter() - start
    fem.end_elements()

    start = time.perf_counter()
    force = algebra.zeros((dof_count, 1))
    boundaries = (
        ("ri", inner_pressure, -1.0, inner_radius),
        ("ro", outer_pressure, 1.0, outer_radius),
    )
    allocated = set()

    for name, pressure, normal_sign, radius in boundaries:

        boundary_elements = mesh.group_names[name]["members"][0]
        boundary_records = [
            (int(boundary_elements["types"][block_index]), element_nodes)
            for block_index in range(boundary_elements["types"].size)
            for element_nodes in boundary_elements["indices"][block_index]
        ]

        for element_type, element_nodes in boundary_records:

            element = fem.element[element_type]

            if element_type not in allocated:

                element.end()
                element.allocate(intorder=1, nbases=len(basis_names), order=order)
                element.allocate_spatial(2, compute_Jinv=False)
                allocated.add(element_type)

            # end if

            basis_count = element.nbasis
            element_force = algebra.zeros((2 * basis_count, 1))
            x_element = algebra.zeros((basis_count, 1))
            y_element = algebra.zeros((basis_count, 1))
            element.set_coordinates(mesh.x, mesh.y, mesh.z, element_nodes)
            element.compute_jacobian()

            for local_node, global_node in enumerate(element_nodes):

                x_element[local_node, 0] = mesh.x[int(global_node), 0]
                y_element[local_node, 0] = mesh.y[int(global_node), 0]

            # end for

            normal_x = normal_sign * x_element / radius
            normal_y = normal_sign * y_element / radius

            for ip in range(element.nip):

                shape = element.N.get_ip(ip)
                differential = element.dV[ip]
                interpolation = algebra.zeros((2, 2 * basis_count))
                interpolation[0, 0:2 * basis_count:2] = shape
                interpolation[1, 1:2 * basis_count:2] = shape
                traction = (-pressure) * algebra.array([
                    [algebra.dot_product(normal_x, shape)],
                    [algebra.dot_product(normal_y, shape)],
                ])
                element_force += algebra.dot(interpolation.T, traction) * differential

            # end for

            for local_node, global_node in enumerate(element_nodes):

                node = int(global_node)
                force[2 * node, 0] = force[2 * node, 0] + element_force[2 * local_node, 0]
                force[2 * node + 1, 0] = (
                    force[2 * node + 1, 0] + element_force[2 * local_node + 1, 0]
                )

            # end for

        # end for

    # end for

    timings["assembly_f"] = time.perf_counter() - start
    fem.end_elements()

    start = time.perf_counter()

    for group_name, component in (("right", 1), ("left", 0)):

        boundary_elements = mesh.group_names[group_name]["members"][0]
        boundary_records = [
            element_nodes
            for block_index in range(boundary_elements["types"].size)
            for element_nodes in boundary_elements["indices"][block_index]
        ]

        for element_nodes in boundary_records:

            for node_value in np.unique(element_nodes):

                node = int(node_value)
                dof = 2 * node + component
                stiffness[dof, dof] = _TGV
                force[dof, 0] = 0.0

            # end for

        # end for

    # end for

    timings["boundary_conditions"] = time.perf_counter() - start

    start = time.perf_counter()
    stiffness_csr = stiffness.tocsr()
    timings["tocsr"] = time.perf_counter() - start

    start = time.perf_counter()
    solution = algebra.solve(stiffness_csr, force, solver="SuperLU")
    timings["solve"] = time.perf_counter() - start
    exact_values = []

    for node in range(node_count):

        exact_values.extend(_analytic_solution(
            algebra,
            mesh.x[node, 0],
            mesh.y[node, 0],
            youngs_modulus,
            poisson_ratio,
            inner_radius,
            inner_pressure,
            outer_radius,
            outer_pressure,
        ))

    # end for

    exact_solution = algebra.array([[value] for value in exact_values])
    errors = _error_table(solution, exact_solution, basis_names, order)

    return {
        "u": solution,
        "coordinates": {"x": mesh.x, "y": mesh.y, "z": mesh.z},
        "timings": timings,
        "lame_errors": errors,
        "bases": tuple(basis_names),
        "ndivs": tuple(ndivs),
        "order": order,
        "perturb_geometry": perturb_geometry,
    }

# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _format_result(result):
    """
    Print model timings and the Lamé-error table.

    Parameters
    ----------
    result : dict
        Result returned by :func:`run`.

    Examples
    --------
    >>> # Call with the result of run(...).
    """
    print(f"mesh={result['ndivs']}, order={result['order']}")
    print("stage                 seconds")

    for stage, seconds in result["timings"].items():

        print(f"{stage:22s} {seconds:.6f}")

    # end for

    print(f"{'derivative':14s} {'relative L2':>14s} {'max abs':>14s}")

    for row in result["lame_errors"]:

        relative = "ref=0" if row["relative_l2"] is None else f"{row['relative_l2']:.6e}"
        print(f"{row['label']:14s} {relative:>14s} {row['max_abs']:14.6e}")

    # end for

# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def main(argv=None):
    """
    Run the cylinder model from command-line arguments.

    Parameters
    ----------
    argv : list[str] or None, optional
        Command-line arguments, or `None` to use :mod:`argparse` defaults.

    Examples
    --------
    >>> main(["--algebra", "sparse", "--ndivs", "4", "4", "--order", "2"])
    """
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--algebra", choices=("sparse", "semisparse", "dense"), default="sparse")
    parser.add_argument("--ndivs", nargs=2, type=int, default=(4, 4), metavar=("RADIAL", "THETA"))
    parser.add_argument("--order", type=int, default=2)
    parser.add_argument("--perturb", action="store_true", help="also differentiate the radii")
    args = parser.parse_args(argv)

    if args.algebra == "sparse":

        import pyoti.sparse as algebra

    elif args.algebra == "semisparse":

        import pyoti.semisparse as algebra

    else:

        import pyoti.dense as algebra

    # end if

    _format_result(run(algebra, args.ndivs, args.order, args.perturb))

# --------------------------------------------------------------------------------------------------------


if __name__ == "__main__":

    main()

# end if
