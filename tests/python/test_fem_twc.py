"""
Verify the thick-walled-cylinder FEM example against its Lamé reference solution.
"""

import numpy as np
import pytest

pytest.importorskip("gmsh")

import pyoti.fem as fem
import pyoti.sparse as sparse

from examples.python.fem_twc import _directions, run


# ********************************************************************************************************
def _rows_by_label(result):
    """
    Index a model's Lamé-error rows by derivative label.

    Parameters
    ----------
    result : dict
        Result returned by the TWC model.

    Returns
    -------
    dict
        Rows keyed by their readable derivative labels.
    """
    return {row["label"]: row for row in result["lame_errors"]}

# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _assert_lame_tolerance(result, relative_limit, absolute_limit):
    """
    Check every derivative against the selected discretization tolerances.

    Parameters
    ----------
    result : dict
        Result returned by the TWC model.
    relative_limit : float
        Maximum relative L2 error for a nonzero Lamé reference.
    absolute_limit : float
        Maximum absolute error for a zero Lamé reference.
    """

    for row in result["lame_errors"]:

        if row["relative_l2"] is None:

            assert row["max_abs"] <= absolute_limit, row

        else:

            assert row["relative_l2"] <= relative_limit, row

        # end if

    # end for

# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_sparse_solution_matches_lame_on_coarse_mesh():
    """
    Check value and all first- and second-order derivatives on the 4 by 4 mesh.
    """
    result = run(sparse, [4, 4], 2)
    assert len(result["lame_errors"]) == len(_directions(4, 2))
    assert set(result["timings"]) == {
        "assembly_K", "assembly_f", "boundary_conditions", "tocsr", "solve"
    }

    # Initial [4, 4] sparse runs set the nonzero-reference tolerance to 30%; the maximum
    # observed relative L2 error is recorded in WPE-report.md. Zero references use 1e-18 m.
    _assert_lame_tolerance(result, relative_limit=0.30, absolute_limit=1.0e-18)

# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_sparse_errors_decrease_under_mesh_refinement():
    """
    Check value and first-derivative errors decrease when both mesh divisions double.
    """
    coarse = _rows_by_label(run(sparse, [4, 4], 2))
    fine = _rows_by_label(run(sparse, [8, 8], 2))

    for label in ("value", "dE", "dnu", "dPo", "dPi"):

        coarse_error = coarse[label]["relative_l2"]
        fine_error = fine[label]["relative_l2"]
        assert coarse_error is not None
        assert fine_error is not None
        assert fine_error <= 0.35 * coarse_error, (label, coarse_error, fine_error)

    # end for

# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_sparse_geometry_derivatives_match_lame():
    """
    Check the inner- and outer-radius sensitivities on the 4 by 4 mesh.
    """
    result = run(sparse, [4, 4], 2, perturb_geometry=True)
    rows = _rows_by_label(result)

    for label in ("dri", "dro"):

        assert rows[label]["relative_l2"] is not None
        assert rows[label]["relative_l2"] <= 0.40, rows[label]

    # end for

    _assert_lame_tolerance(result, relative_limit=0.40, absolute_limit=1.0e-18)

# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _assert_matches_sparse(module, perturb_geometry):
    """
    Compare every displacement derivative of the TWC model in an algebra with the sparse oracle.

    Skips when the algebra lacks the TWC APIs or ``pyoti.fem`` rejects it.

    Parameters
    ----------
    module : module
        Algebra under test (``pyoti.semisparse`` or ``pyoti.dense``).
    perturb_geometry : bool
        Whether the comparison includes derivatives with respect to both radii.
    """
    name = module.__name__
    original_algebra = fem.get_global_algebra()

    try:

        required = ("array", "e", "lil_matrix", "set_printoptions", "solve", "zeros", "zero")
        missing = [label for label in required if not hasattr(module, label)]

        if missing:

            pytest.skip(f"{name} lacks TWC APIs: {', '.join(missing)}")

        # end if

        try:

            fem.set_global_algebra(module)

        except Exception as error:

            pytest.skip(f"pyoti.fem.set_global_algebra rejects {name}: {error}")

        # end try

        sparse_result = run(sparse, [4, 4], 2, perturb_geometry)
        other_result = run(module, [4, 4], 2, perturb_geometry)
        sparse_solution = sparse_result["u"]
        other_solution = other_result["u"]
        directions = _directions(len(sparse_result["bases"]), 2)

        for direction in directions:

            if direction:

                sparse_values = np.asarray(
                    sparse_solution.get_deriv(list(direction)), dtype=np.float64
                )
                other_values = np.asarray(
                    other_solution.get_deriv(list(direction)), dtype=np.float64
                )

            else:

                sparse_values = np.asarray(sparse_solution.real, dtype=np.float64)
                other_values = np.asarray(other_solution.real, dtype=np.float64)

            # end if

            error_norm = float(np.linalg.norm(sparse_values - other_values))
            reference_norm = float(np.linalg.norm(sparse_values))

            if reference_norm == 0.0:

                assert error_norm <= 1.0e-30, direction

            else:

                assert error_norm <= 1.0e-12 * reference_norm, (
                    direction, error_norm, reference_norm
                )

            # end if

        # end for

    finally:

        fem.set_global_algebra(original_algebra)

    # end try

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("perturb_geometry", [False, True])
def test_semisparse_matches_sparse(perturb_geometry):
    """
    Compare every semi-sparse displacement derivative with the sparse oracle.

    Parameters
    ----------
    perturb_geometry : bool
        Whether the comparison includes derivatives with respect to both radii.
    """
    import pyoti.semisparse as semisparse

    _assert_matches_sparse(semisparse, perturb_geometry)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize("perturb_geometry", [False, True])
def test_dense_matches_sparse(perturb_geometry):
    """
    Compare every dense displacement derivative with the sparse oracle (PLAN-dense-update.md).

    Parameters
    ----------
    perturb_geometry : bool
        Whether the comparison includes derivatives with respect to both radii.
    """
    import pyoti.dense as dense

    _assert_matches_sparse(dense, perturb_geometry)

# end function
# --------------------------------------------------------------------------------------------------------
