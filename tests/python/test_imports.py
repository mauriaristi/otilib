"""
Tests installation, importability of submodules, and the lazy direction-helper tables.
"""

import importlib
import math

import numpy as np
import pytest


# ********************************************************************************************************
def test_import_pyoti():
    """
    Test importing the top-level pyoti package.
    """
    import pyoti

    assert pyoti is not None

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize(
    "mod_name",
    [
        "pyoti.core",
        "pyoti.sparse",
        "pyoti.dense",
        "pyoti.semisparse",
        "pyoti.real",
        "pyoti.fem",
        "pyoti.whereotilib",
    ],
)
def test_import_core_submodules(mod_name: str):
    """
    Test importing all core Cython / Python submodules.

    Parameters
    ----------
    mod_name : str
        Name of the module to import.
    """
    mod = importlib.import_module(mod_name)
    assert mod is not None

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_top_level_reexports_new_dense_api():
    """
    Check that ``import pyoti`` re-exports the new dense API (PLAN-dense-update.md, decision 4).

    The top-level namespace carries the dense classes and creators, and no longer re-exports the
    global truncation order controls, which stay in ``pyoti.core`` (decision 2).
    """
    import pyoti
    import pyoti.core as core
    import pyoti.dense as dense

    assert pyoti.otinum is dense.otinum
    assert pyoti.omat is dense.omat
    assert pyoti.e is dense.e

    x = pyoti.e(3, order=2)

    assert isinstance(x, dense.otinum)
    assert x.order == 2
    assert not hasattr(pyoti, "set_trunc_order")
    assert not hasattr(pyoti, "get_trunc_order")
    assert hasattr(core, "set_trunc_order")

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize(
    "sm",
    [
        "onumm1n1",
        "onumm1n2",
        "onumm1n3",
        "onumm1n4",
        "onumm1n10",
        "onumm1n20",
        "onumm1n30",
        "onumm2n1",
        "onumm2n2",
        "onumm2n3",
        "onumm2n4",
        "onumm3n1",
        "onumm3n2",
        "onumm3n3",
        "onumm3n4",
        "onumm10n1",
        "onumm10n2",
    ],
)
def test_import_static_modules(sm: str):
    """
    Test importing all precompiled static dense submodules.

    Parameters
    ----------
    sm : str
        Name of the static module to import.
    """
    mod = importlib.import_module(f"pyoti.static.{sm}")
    cls = getattr(mod, sm, None)
    assert cls is not None, f"Class {sm} not found in pyoti.static.{sm}"

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _ndirs(k, m):
    """
    Colex-rank building block: number of order-``k`` directions using at most ``m`` bases.

    Mirrors the library's ``dhelp_comb(k + m - 1, k)``, independently of the C tables.

    Parameters
    ----------
    k : int
        Order.
    m : int
        Maximum basis index allowed (``0`` means none).

    Returns
    -------
    int
        ``C(k + m - 1, k)``.
    """
    return math.comb(k + m - 1, k)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _rank(sorted_bases):
    """
    Pure-Python colex rank of a sorted, merged direction.

    Matches the enumeration ``dhelp_precompute_fulldir`` / ``dhelp_precompute_multiply`` use,
    without touching any precomputed C table: ``idx = sum_i ndirs_(i+1)(base_i - 1)``.

    Parameters
    ----------
    sorted_bases : list of int
        Bases of a single OTI direction, sorted ascending (repeats allowed).

    Returns
    -------
    int
        Colex index of the direction.
    """
    return sum(_ndirs(i, base - 1) for i, base in enumerate(sorted_bases, start=1))

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
@pytest.mark.parametrize(
    "order, expected_nbasis",
    [
        (1, 65000),
        (2, 1000),
        (3, 100),
        (4, 100),
        (5, 10),
        (10, 10),
        (11, 5),
        (20, 5),
        (21, 3),
        (50, 3),
        (51, 2),
        (150, 2),
    ],
)
def test_dhelp_nbasis_schedule(order: int, expected_nbasis: int):
    """
    Verify the per-order basis schedule used to build the lazy direction-helper tables.

    Parameters
    ----------
    order : int
        Truncation order to check.
    expected_nbasis : int
        Number of bases the schedule assigns to that order.
    """
    import pyoti.core as core

    assert core.get_dHelp().get_nbasis(order) == expected_nbasis

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_mult_dir_matches_rank():
    """
    Verify h.mult_dir against an independent, pure-Python colex rank of the merged direction.

    Random direction pairs are drawn at orders up to 10, including an order-4 result (whose
    100-basis tables are among the largest the lazy loader builds), each bounded to the
    resulting order's own basis count so the multiplication stays within the built sub-tables.
    """
    import pyoti.core as core

    h = core.get_dHelp()
    rng = np.random.default_rng(20260927)
    cases = [(1, 1), (1, 2), (2, 2), (1, 3), (2, 3), (3, 3), (1, 4), (2, 4), (3, 4), (4, 4)]

    for ord1, ord2 in cases:

        ord_res = ord1 + ord2
        nb = h.get_nbasis(ord_res)

        if ord_res == 4:

            assert nb == 100

        # end if

        n1 = h.get_ndir_order(nb, ord1)
        n2 = h.get_ndir_order(nb, ord2)

        for _ in range(5):

            indx1 = int(rng.integers(n1))
            indx2 = int(rng.integers(n2))

            dir1 = list(h.get_fulldir(indx1, ord1))
            dir2 = list(h.get_fulldir(indx2, ord2))

            indx_res, ord_res_got = h.mult_dir(indx1, ord1, indx2, ord2)

            assert ord_res_got == ord_res
            assert indx_res == _rank(sorted(dir1 + dir2))

        # end for

    # end for

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def test_multtabl_lazy():
    """
    Verify a multiplication table is built lazily, on first use, and cached afterward.
    """
    import pyoti.core as core

    dh = core.dHelp()
    order, ord_small = 6, 2
    k = ord_small - 1

    assert not dh.is_multtabl_loaded(order, k)

    dh.mult_dir(0, ord_small, 0, order - ord_small)

    assert dh.is_multtabl_loaded(order, k)

# end function
# --------------------------------------------------------------------------------------------------------


if __name__ == "__main__":

    pytest.main([__file__])

# end if
