#!/usr/bin/env python3
"""
Benchmarks the dense linear algebra of ``pyoti.sparse``: ``det``, ``inv``, ``inv_block`` and
``solve``.

Each case times one operation on an n x n OTI matrix whose imaginary part fills every direction of
every order for the given number of bases. The script only uses the public API, so the same
command measures the library before and after a change. ``--det-inv-max`` limits the sizes timed
for ``det`` and ``inv`` (default 50, every default size); pass 3 to measure a build older than the
LU fix, where larger sizes are wrong (bugs C and G).

Examples
--------
Run the default grid and save the results::

    python tools/bench_linalg.py --json build/bench_linalg_before.json

Run a short grid and compare it with a saved run::

    python tools/bench_linalg.py --quick --compare build/bench_linalg_before.json
"""

import argparse
import itertools
import json
import platform
import sys
import timeit

import numpy as np

import pyoti
import pyoti.sparse as oti


DEFAULT_SIZES = [2, 3, 4, 5, 6, 8, 20, 50]
DEFAULT_ORDERS = [1, 2, 3, 4]
DEFAULT_BASES = [2, 3, 5]

QUICK_SIZES = [2, 3, 4, 8]
QUICK_ORDERS = [1, 2]
QUICK_BASES = [2]

OPERATIONS = ["det", "inv", "inv_block", "solve"]

# Largest n for which det is checked in every coefficient against the permutation expansion
# (n! terms); larger n only check the real part against numpy.linalg.det.
LEIBNIZ_MAX = 8


#*****************************************************************************************************
def random_oti_matrix(n, order, nbases, rng):
    """
    Builds a well-conditioned n x n OTI matrix with every direction of every order populated.

    The matrix is ``R0 + sum_p s**p Rp`` with ``s = e_1 + ... + e_nbases``, so ``s**p`` holds all
    directions of order ``p``. ``R0`` is diagonally dominant, which keeps the real part far from
    singular.

    Parameters
    ----------
    n : int
        Number of rows and columns.
    order : int
        Truncation order.
    nbases : int
        Number of imaginary bases.
    rng : numpy.random.Generator
        Random number generator.

    Returns
    -------
    matso
        The OTI matrix.

    Examples
    --------
    >>> a = random_oti_matrix(3, 2, 2, np.random.default_rng(0))
    >>> a.shape, a.order
    ((3, 3), 2)
    """

    s = oti.e(1, order=order)

    for k in range(2, nbases + 1):

        s = s + oti.e(k, order=order)

    # end for

    real = rng.uniform(-1.0, 1.0, (n, n)) + 2.0 * n * np.eye(n)
    mat = oti.array(real)
    sp = s

    for p in range(1, order + 1):

        mat = mat + sp * oti.array(rng.uniform(-1.0, 1.0, (n, n)))
        sp = sp * s

    # end for

    return mat

# end function


#*****************************************************************************************************
def random_oti_rhs(n, order, nbases, rng):
    """
    Builds an n x 1 OTI right-hand side with every direction of every order populated.

    Parameters
    ----------
    n : int
        Number of rows.
    order : int
        Truncation order.
    nbases : int
        Number of imaginary bases.
    rng : numpy.random.Generator
        Random number generator.

    Returns
    -------
    matso
        The OTI column vector.

    Examples
    --------
    >>> random_oti_rhs(4, 1, 2, np.random.default_rng(0)).shape
    (4, 1)
    """

    s = oti.e(1, order=order)

    for k in range(2, nbases + 1):

        s = s + oti.e(k, order=order)

    # end for

    vec = oti.array(rng.uniform(-1.0, 1.0, (n, 1)))
    sp = s

    for p in range(1, order + 1):

        vec = vec + sp * oti.array(rng.uniform(-1.0, 1.0, (n, 1)))
        sp = sp * s

    # end for

    return vec

# end function


#*****************************************************************************************************
def time_call(func, min_time, repeat):
    """
    Returns the best time per call of ``func`` in seconds.

    The number of calls per sample grows until one sample takes at least ``min_time`` seconds; the
    best of ``repeat`` samples is reported.

    Parameters
    ----------
    func : callable
        Function without arguments.
    min_time : float
        Minimum duration of one sample, in seconds.
    repeat : int
        Number of samples.

    Returns
    -------
    float
        Best time per call, in seconds.

    Examples
    --------
    >>> time_call(lambda: None, 0.01, 2) < 1.0
    True
    """

    timer = timeit.Timer(func)
    number = 1

    while timer.timeit(number=number) < min_time:

        number *= 2

    # end while

    samples = timer.repeat(repeat=repeat, number=number)

    return min(samples) / number

# end function


#*****************************************************************************************************
def max_abs_coefficient(arr, order):
    """
    Returns the largest absolute coefficient of an OTI array over the real part and every order.

    Parameters
    ----------
    arr : matso
        OTI array.
    order : int
        Highest order to inspect.

    Returns
    -------
    float
        Largest absolute coefficient; NaN if any coefficient is not finite.

    Examples
    --------
    >>> max_abs_coefficient(oti.array(np.eye(2)), 1)
    1.0
    """

    values = [np.abs(np.asarray(arr.real, dtype=float)).ravel()]

    for p in range(1, order + 1):

        values.append(np.abs(oti.get_order_im_array(p, arr)).ravel())

    # end for

    values = np.concatenate(values)

    if not np.all(np.isfinite(values)):

        return float("nan")

    # end if

    return float(values.max()) if values.size else 0.0

# end function


#*****************************************************************************************************
def leibniz_det(mat):
    """
    Computes the determinant of an OTI matrix by the permutation (Leibniz) expansion.

    It uses only OTI products and sums, no division, and shares no code with ``oti.det``, so it
    is an independent reference for every coefficient. The cost grows as n!, so use it for small
    n only (see ``LEIBNIZ_MAX``).

    Parameters
    ----------
    mat : matso
        Square OTI matrix.

    Returns
    -------
    sotinum
        The determinant.

    Examples
    --------
    >>> leibniz_det(oti.array([[1.0, 2.0], [3.0, 4.0]])).real
    -2.0
    """

    n = mat.shape[0]
    total = 0.0 * mat[0, 0]

    for perm in itertools.permutations(range(n)):

        # Sign of the permutation from its number of inversions.
        inversions = sum(1 for i in range(n) for j in range(i + 1, n) if perm[i] > perm[j])
        term = mat[0, perm[0]]

        for i in range(1, n):

            term = term * mat[i, perm[i]]

        # end for

        total = total - term if inversions % 2 else total + term

    # end for

    return total

# end function


#*****************************************************************************************************
def residual_scope(op, n):
    """
    Tells which part of the result ``residual`` checks.

    Parameters
    ----------
    op : str
        One of ``OPERATIONS``.
    n : int
        Number of rows and columns.

    Returns
    -------
    str
        ``"full"`` (every coefficient) or ``"real"`` (real part only: ``det`` with
        n > ``LEIBNIZ_MAX``).

    Examples
    --------
    >>> residual_scope("det", 20), residual_scope("inv", 20)
    ('real', 'full')
    """

    return "real" if op == "det" and n > LEIBNIZ_MAX else "full"

# end function


#*****************************************************************************************************
def residual(op, mat, rhs, res, order):
    """
    Measures how far the result of one operation is from satisfying its definition.

    ``inv`` and ``inv_block``: largest coefficient of ``A X - I`` over all orders. ``solve``: of
    ``A x - b``. ``det``: largest coefficient of the difference from ``leibniz_det``, relative to
    the largest coefficient of that reference (at least 1), for n <= ``LEIBNIZ_MAX``; for larger n
    only the real part is compared with ``numpy.linalg.det`` (see ``residual_scope``). NaN if any
    coefficient of the result is not finite.

    Parameters
    ----------
    op : str
        One of ``OPERATIONS``.
    mat : matso
        Input matrix.
    rhs : matso or None
        Right-hand side for ``solve``.
    res : matso or sotinum
        Result of the operation.
    order : int
        Truncation order.

    Returns
    -------
    float
        The residual; NaN if the result is not finite.

    Examples
    --------
    >>> a = random_oti_matrix(3, 2, 2, np.random.default_rng(0))
    >>> residual("inv_block", a, None, oti.inv_block(a), 2) < 1e-12
    True
    """

    if op == "det":

        size = max_abs_coefficient(oti.array([[res]]), order)

        if not np.isfinite(size):

            return float("nan")

        # end if

        if residual_scope(op, mat.shape[0]) == "real":

            ref = np.linalg.det(np.asarray(mat.real, dtype=float))

            return abs(res.real - ref) / max(abs(ref), 1.0)

        # end if

        ref = leibniz_det(mat)
        scale = max(max_abs_coefficient(oti.array([[ref]]), order), 1.0)

        return max_abs_coefficient(oti.array([[res - ref]]), order) / scale

    # end if

    if op == "solve":

        return max_abs_coefficient(oti.dot(mat, res) - rhs, order)

    # end if

    eye = oti.array(np.eye(mat.shape[0]))

    return max_abs_coefficient(oti.dot(mat, res) - eye, order)

# end function


#*****************************************************************************************************
def run_case(op, n, order, nbases, args):
    """
    Times one operation for one matrix size, truncation order and number of bases.

    Parameters
    ----------
    op : str
        One of ``OPERATIONS``.
    n : int
        Number of rows and columns.
    order : int
        Truncation order.
    nbases : int
        Number of imaginary bases.
    args : argparse.Namespace
        Command-line options (``seed``, ``min_time``, ``repeat``, ``tol``).

    Returns
    -------
    dict
        The case parameters, ``seconds`` (best time per call), ``residual`` (see ``residual``),
        ``ok`` (residual finite and at most ``args.tol``) and ``check`` (see ``residual_scope``).

    Examples
    --------
    >>> ns = argparse.Namespace(seed=0, min_time=0.01, repeat=1, tol=1e-8)
    >>> run_case("solve", 2, 1, 2, ns)["op"]
    'solve'
    """

    rng = np.random.default_rng(args.seed)
    mat = random_oti_matrix(n, order, nbases, rng)
    rhs = None

    if op == "det":

        func = lambda: oti.det(mat)

    elif op == "inv":

        func = lambda: oti.inv(mat)

    elif op == "inv_block":

        func = lambda: oti.inv_block(mat)

    else:

        rhs = random_oti_rhs(n, order, nbases, rng)
        func = lambda: oti.solve(mat, rhs)

    # end if

    # Correctness check once, outside the timed loop, so a fast wrong answer is not reported as a
    # speedup.
    resid = residual(op, mat, rhs, func(), order)
    seconds = time_call(func, args.min_time, args.repeat)

    return {"op": op, "n": n, "order": order, "nbases": nbases, "seconds": seconds,
            "residual": resid, "ok": bool(np.isfinite(resid) and resid <= args.tol),
            "check": residual_scope(op, n)}

# end function


#*****************************************************************************************************
def case_key(case):
    """
    Returns the tuple that identifies a case across runs.

    Parameters
    ----------
    case : dict
        A result of ``run_case``.

    Returns
    -------
    tuple
        ``(op, n, order, nbases)``.

    Examples
    --------
    >>> case_key({"op": "det", "n": 2, "order": 1, "nbases": 2, "seconds": 1e-6})
    ('det', 2, 1, 2)
    """

    return (case["op"], case["n"], case["order"], case["nbases"])

# end function


#*****************************************************************************************************
def metadata():
    """
    Collects the software and machine information stored with the results.

    Returns
    -------
    dict
        Versions of pyoti, NumPy and Python, and the platform string.

    Examples
    --------
    >>> "pyoti" in metadata()
    True
    """

    return {"pyoti": pyoti.__version__,
            "numpy": np.__version__,
            "python": platform.python_version(),
            "platform": platform.platform(),
            "machine": platform.machine()}

# end function


#*****************************************************************************************************
def print_table(cases, reference):
    """
    Prints the results as a table, with the speedup against a saved run when one is given.

    Column ``ok``: ``yes`` (every coefficient checked), ``real`` (real part only, large-n ``det``)
    or ``NO`` (check failed; the speedup is then shown as ``invalid``).

    Parameters
    ----------
    cases : list of dict
        Results of ``run_case``.
    reference : dict or None
        Maps ``case_key`` to seconds of the saved run.

    Examples
    --------
    >>> print_table([{"op": "det", "n": 2, "order": 1, "nbases": 2, "seconds": 1e-6,
    ...               "residual": 0.0, "ok": True}], None)
    op              n  order  nbases     time [ms]   residual   ok
    det             2      1       2        0.0010    0.0e+00  yes
    """

    header = "{:<12} {:>4} {:>6} {:>7} {:>13} {:>10} {:>4}".format("op", "n", "order", "nbases",
                                                                   "time [ms]", "residual", "ok")

    if reference is not None:

        header += " {:>13} {:>9}".format("before [ms]", "speedup")

    # end if

    print(header)

    for case in cases:

        ok = case.get("ok", True)

        if not ok:

            status = "NO"

        elif case.get("check", "full") == "real":

            status = "real"

        else:

            status = "yes"

        # end if

        line = "{:<12} {:>4} {:>6} {:>7} {:>13.4f} {:>10.1e} {:>4}".format(
            case["op"], case["n"], case["order"], case["nbases"], 1e3 * case["seconds"],
            case.get("residual", float("nan")), status)

        if reference is not None and case_key(case) in reference:

            before = reference[case_key(case)]

            # A wrong answer is not a speedup.
            speedup = "{:>9.2f}".format(before / case["seconds"]) if ok else "  invalid"
            line += " {:>13.4f} {}".format(1e3 * before, speedup)

        # end if

        print(line)

    # end for

# end function


#*****************************************************************************************************
def main():
    """
    Parses the command line, runs the benchmark grid and reports the results.

    Returns
    -------
    int
        Process exit status: 1 if any case failed the correctness check, 0 otherwise.
    """

    parser = argparse.ArgumentParser(description="Benchmark pyoti.sparse dense linear algebra.")
    parser.add_argument("--ops", nargs="+", choices=OPERATIONS, default=OPERATIONS,
                        help="operations to time")
    parser.add_argument("--sizes", nargs="+", type=int, default=None, help="matrix sizes n")
    parser.add_argument("--orders", nargs="+", type=int, default=None, help="truncation orders")
    parser.add_argument("--bases", nargs="+", type=int, default=None, help="numbers of bases")
    parser.add_argument("--quick", action="store_true", help="use a short grid")
    parser.add_argument("--det-inv-max", type=int, default=50,
                        help="largest n timed for det and inv (default 50)")
    parser.add_argument("--min-time", type=float, default=0.2,
                        help="minimum duration of one timing sample in seconds")
    parser.add_argument("--repeat", type=int, default=3, help="number of timing samples")
    parser.add_argument("--seed", type=int, default=0, help="random seed")
    parser.add_argument("--tol", type=float, default=1e-8,
                        help="largest residual accepted by the correctness check (default 1e-8)")
    parser.add_argument("--json", metavar="PATH", help="write the results to a JSON file")
    parser.add_argument("--compare", metavar="PATH", help="saved JSON run to compare against")
    args = parser.parse_args()

    sizes = args.sizes or (QUICK_SIZES if args.quick else DEFAULT_SIZES)
    orders = args.orders or (QUICK_ORDERS if args.quick else DEFAULT_ORDERS)
    bases = args.bases or (QUICK_BASES if args.quick else DEFAULT_BASES)

    reference = None

    if args.compare:

        with open(args.compare, "r") as handle:

            saved = json.load(handle)

        # end with

        reference = {case_key(case): case["seconds"] for case in saved["cases"]}

    # end if

    cases = []

    for op, n, order, nbases in itertools.product(args.ops, sizes, orders, bases):

        if op in ("det", "inv") and n > args.det_inv_max:

            continue

        # end if

        cases.append(run_case(op, n, order, nbases, args))
        print("  {} n={} order={} nbases={}: {:.4f} ms".format(op, n, order, nbases,
                                                              1e3 * cases[-1]["seconds"]),
              file=sys.stderr)

    # end for

    print_table(cases, reference)

    failed = [case for case in cases if not case["ok"]]

    if failed:

        print("WARNING: {} case(s) failed the correctness check (ok = NO).".format(len(failed)))

    # end if

    if args.json:

        with open(args.json, "w") as handle:

            json.dump({"metadata": metadata(), "cases": cases}, handle, indent=2)

        # end with

        print("Wrote {}".format(args.json))

    # end if

    return 1 if failed else 0

# end function


if __name__ == "__main__":

    sys.exit(main())

# end if
