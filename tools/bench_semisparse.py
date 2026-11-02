#!/usr/bin/env python3
"""
Benchmark sparse, dense and semi-sparse scalar, array, and assembly workloads.

Every measured case starts a fresh interpreter. A skipped or failed case remains in the JSON
output; timings exclude operand construction, while RSS includes construction and lazy tables.

Examples
--------
python tools/bench_semisparse.py --quick
python tools/bench_semisparse.py --json build/bench_semisparse_baseline.json
PYTHONPATH=build-pybind python tools/bench_semisparse.py --quick \
    --compare build/bench_semisparse_baseline.json
"""

import argparse
import itertools
import json
import math
import os
import platform
import re
import resource
import statistics
import subprocess
import sys
import time
from pathlib import Path


BASES = (2, 5, 10, 20, 50, 100)
ORDERS = (1, 2, 3, 4, 6, 8, 10)
SIZES = (10, 100, 1000)
SCALAR_OPS = ("mul", "add", "div", "sin", "exp", "pow")
ARRAY_OPS = ("mul", "matmul", "solve", "inv", "det")
FILLS = ("full", "separable", "first")
RELATIONS = ("same", "leading", "interleaved")
BACKENDS = ("sparse", "dense", "semisparse_scalar", "semisparse_aos", "semisparse_soa")


# ********************************************************************************************************
def coefficient_count(k, order):
    """
    Count the coefficients in a dense number with k bases and the given order.

    Parameters
    ----------
    k : int
        Number of bases.
    order : int
        Truncation order.

    Returns
    -------
    int
        Number of real and imaginary coefficients.
    """

    return math.comb(k + order, order)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def operand(module, bases, order, fill, semisparse=False):
    """
    Construct a scalar whose nonzero directions follow the requested pattern.

    Parameters
    ----------
    module : module
        Public sparse or dense pyoti module.
    bases : sequence of int
        Active global base labels.
    order : int
        Truncation order.
    fill : str
        Full, separable, or first-order-only pattern.
    semisparse : bool
        Use the semi-sparse scalar's public direction setter.

    Returns
    -------
    object
        OTI scalar with a nonzero real part.
    """

    capacity = max(bases)

    if semisparse:

        value = module.ssotinum(2.0, order=order)

    else:

        # sparse takes a capacity hint; dense and sparse share the call (dense ignores the hint)
        value = module.number(2.0, nbases=capacity, order=order)

    # end if

    if fill == "full":

        directions = (direction for degree in range(1, order + 1)
                      for direction in itertools.combinations_with_replacement(bases, degree))

    elif fill == "separable":

        directions = ([base] * degree for degree in range(1, order + 1)
                      for base in bases)

    else:

        directions = ([base] for base in bases)

    # end if

    for direction in directions:

        coefficient = 0.01 / len(direction)

        value.set_im(coefficient, list(direction))

    # end for

    return value

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def operands(module, case):
    """
    Build two scalars with the requested relation between their basis sets.

    Parameters
    ----------
    module : module
        Public pyoti module.
    case : dict
        Benchmark dimensions and fill pattern.

    Returns
    -------
    tuple
        Two OTI scalar operands.
    """

    k = case["k"]
    relation = case["relation"]
    left = list(range(1, k + 1))
    right = left

    if relation == "leading":

        left = left[:max(1, k // 2)]

    elif relation == "interleaved":

        left = left[::2]
        right = right[1::2]

    # end if

    semi = case["backend"].startswith("semisparse_")
    return (operand(module, left, case["order"], case["fill"], semi),
            operand(module, right, case["order"], case["fill"], semi))

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def matrix(module, case, scalar):
    """
    Create a diagonally dominant matrix with every requested scalar direction.

    Parameters
    ----------
    module : module
        Public pyoti module.
    case : dict
        Matrix dimensions and backend.
    scalar : object
        OTI scalar used for every matrix entry.

    Returns
    -------
    object
        OTI matrix with a well-conditioned real part.
    """

    import numpy as np

    n = case["n"]
    real = np.eye(n) * (n + 2.0) + np.full((n, n), 0.01)

    backend = case["backend"]

    if backend == "sparse":

        result = module.array(real)

    elif backend == "dense":

        result = module.zeros((n, n), order=case["order"], bases=range(1, case["k"] + 1))

    elif backend == "semisparse_aos":

        result = module.arrss.zeros((n, n), order=case["order"])

    else:

        result = module.oarrss.zeros((n, n), bases=range(1, case["k"] + 1),
                                    order=case["order"])

    # end if

    for i in range(n):

        for j in range(n):

            result[i, j] = real[i, j] + scalar - 2.0

        # end for

    # end for

    return result

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def assemble(module, case):
    """
    Assemble a one-dimensional bar stiffness matrix with one base per region.

    Parameters
    ----------
    module : module
        Public sparse or semi-sparse pyoti module.
    case : dict
        Number of regions and truncation order.

    Returns
    -------
    tuple
        Assembled matrix and right-hand side.
    """

    n = case["k"] + 1
    order = case["order"]
    entries = [[0.0 for column in range(n)] for row in range(n)]

    for region in range(1, n):

        if case["backend"] == "sparse":

            stiffness = 1.0 + 0.05 * module.e(region, order=order)

        else:

            stiffness = module.ssotinum(1.0, order=order)
            stiffness.set_im(0.05, region)

        # end if
        i = region - 1
        entries[i][i] += stiffness
        entries[i + 1][i + 1] += stiffness
        entries[i][i + 1] -= stiffness
        entries[i + 1][i] -= stiffness

    # end for

    entries[0][0] += 1.0
    if case["backend"] == "sparse":

        rhs = module.array([[1.0] for row in range(n)])
        return module.array(entries), rhs

    elif case["backend"] == "semisparse_aos":

        matrix = module.arrss.zeros((n, n), order=order)
        rhs = module.arrss.zeros((n, 1), order=order)

    else:

        matrix = module.oarrss.zeros((n, n), bases=range(1, case["k"] + 1), order=order)
        rhs = module.oarrss.zeros((n, 1), order=order)

    # end if

    for i in range(n):

        rhs[i, 0] = 1.0

        for j in range(n):

            matrix[i, j] = entries[i][j]

        # end for

    # end for

    return matrix, rhs

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def run_case(case, repeat):
    """
    Measure first call and median steady-state operation time in a fresh process.

    Parameters
    ----------
    case : dict
        Case specification.
    repeat : int
        Number of steady-state calls.

    Returns
    -------
    dict
        First-call and median times, peak RSS, and coefficient storage estimate.
    """

    import pyoti.dense as dense
    import pyoti.sparse as sparse

    backend = case["backend"]

    if backend.startswith("semisparse_"):

        import pyoti.semisparse as semi

        module = semi

    else:

        module = sparse if backend == "sparse" else dense

    # end if
    kind = case["kind"]
    op = case["op"]

    if kind == "fem":

        mat, rhs = assemble(module, case)
        call = lambda: module.solve(mat, rhs)

    else:

        left, right = operands(module, case)

        if kind == "scalar":

            calls = {"mul": lambda: left * right, "add": lambda: left + right,
                     "div": lambda: left / right, "sin": lambda: module.sin(left),
                     "exp": lambda: module.exp(left), "pow": lambda: left ** 1.5}
            call = calls[op]

        else:

            mat = matrix(module, case, left)

            if op == "mul":

                call = lambda: mat * mat

            elif op == "matmul":

                call = lambda: module.dot(mat, mat)

            elif op == "solve":

                if backend == "sparse":

                    rhs = module.array([[1.0] for row in range(case["n"])])

                elif backend == "dense":

                    rhs = module.ones((case["n"], 1), order=case["order"])

                elif backend == "semisparse_aos":

                    rhs = module.arrss.zeros((case["n"], 1), order=case["order"])

                    for i in range(case["n"]):

                        rhs[i, 0] = 1.0

                    # end for

                else:

                    rhs = module.oarrss.zeros((case["n"], 1), order=case["order"])

                    for i in range(case["n"]):

                        rhs[i, 0] = 1.0

                    # end for

                # end if

                call = lambda: module.solve(mat, rhs)

            elif op == "inv":

                call = lambda: module.inv(mat)

            else:

                call = lambda: module.det(mat)

            # end if

        # end if

    # end if

    start = time.perf_counter()
    result = call()
    first = time.perf_counter() - start
    samples = []

    for index in range(repeat):

        start = time.perf_counter()
        result = call()
        samples.append(time.perf_counter() - start)

    # end for

    peak = resource.getrusage(resource.RUSAGE_SELF).ru_maxrss
    peak_bytes = peak if sys.platform == "darwin" else peak * 1024
    storage = (getattr(left, "memory_bytes", None) if kind == "scalar" else
               getattr(mat, "memory_bytes", None))
    return {**case, "status": "ok", "seconds": statistics.median(samples),
            "first_seconds": first, "peak_rss_bytes": peak_bytes,
            "operand_storage_bytes": storage,
            "bytes_per_number_estimate": 8 * coefficient_count(case["k"], case["order"]),
            "estimate_note": "dense coefficient slots; sparse actual allocation depends on fill"}

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def case_key(case):
    """
    Identify a benchmark case across runs.

    Parameters
    ----------
    case : dict
        Case specification or result.

    Returns
    -------
    tuple
        Backend, kind, operation, shape, basis count, order, fill, and relation.
    """

    return tuple(case.get(key) for key in
                 ("backend", "kind", "op", "n", "k", "order", "fill", "relation"))

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def baseline_key(case):
    """
    Match a semi-sparse case to the equivalent sparse baseline case.

    Parameters
    ----------
    case : dict
        Semi-sparse or baseline case.

    Returns
    -------
    tuple
        Identity of its comparable sparse baseline case.
    """

    key = case_key(case)

    if case["backend"].startswith("semisparse_"):

        return ("sparse",) + key[1:]

    # end if

    return key

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def metadata():
    """
    Collect machine, library, BLAS linkage, and thread settings.

    Returns
    -------
    dict
        Reproducibility metadata for the benchmark run.
    """

    import numpy as np
    import pyoti

    extensions = sorted(Path(pyoti.__file__).parent.glob("sparse*.so"))
    blas = "not detected"

    if extensions and sys.platform == "darwin":

        linked = subprocess.run(["otool", "-L", str(extensions[0])], capture_output=True,
                                text=True, check=False).stdout
        blas = ", ".join(line.strip() for line in linked.splitlines()
                         if re.search(r"blas|accelerate|lapack", line, re.I)) or blas

    # end if

    return {"pyoti": pyoti.__version__, "numpy": np.__version__,
            "python": platform.python_version(), "platform": platform.platform(),
            "machine": platform.machine(), "processor": platform.processor(),
            "blas_linkage": blas, "omp_num_threads": os.getenv("OMP_NUM_THREADS", "unset"),
            "openblas_num_threads": os.getenv("OPENBLAS_NUM_THREADS", "unset")}

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def print_table(cases, reference):
    """
    Print successful case times and comparison ratios, plus status counts.

    Parameters
    ----------
    cases : list of dict
        Benchmark results, including skipped cases.
    reference : dict or None
        Saved successful cases keyed by case identity.
    """

    print("backend kind op n k order fill relation median_ms first_ms RSS_MiB "
          "speedup RSS_ratio")

    for case in cases:

        if case["status"] != "ok":

            continue

        # end if

        previous = reference.get(baseline_key(case)) if reference is not None else None
        ratio = ("-" if previous is None else
                 "{:.2f}".format(previous["seconds"] / case["seconds"]))
        rss_ratio = ("-" if previous is None or not previous.get("peak_rss_bytes") else
                     "{:.2f}".format(case["peak_rss_bytes"] / previous["peak_rss_bytes"]))
        print("{backend} {kind} {op} {n} {k} {order} {fill} {relation} {median:.4f} "
              "{first:.4f} {rss:.1f} {ratio} {memory_ratio_display}".format(
                  **case, median=1000 * case["seconds"],
                  first=1000 * case["first_seconds"],
                  rss=case["peak_rss_bytes"] / 1024**2, ratio=ratio,
                  memory_ratio_display=rss_ratio))

    # end for

    print("Status counts:", {status: sum(c["status"] == status for c in cases)
                             for status in sorted({c["status"] for c in cases})})

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def grid(args):
    """
    Yield the selected benchmark cases and explicit cap-based skips.

    Parameters
    ----------
    args : argparse.Namespace
        Grid and cap options.

    Returns
    -------
    iterator
        Case dictionaries paired with a skip reason or None.
    """

    bases = (2, 5) if args.quick else BASES
    orders = (1, 2) if args.quick else ORDERS
    sizes = (10,) if args.quick else SIZES
    fills = ("full", "separable") if args.quick else FILLS
    relations = ("same", "leading") if args.quick else RELATIONS

    for backend, k, order in itertools.product(args.backends, bases, orders):

        slots = coefficient_count(k, order)

        if backend in ("sparse", "dense", "semisparse_scalar"):

            for fill, op in itertools.product(fills, SCALAR_OPS):

                selected_relations = relations if op in ("mul", "add", "div") else ("same",)

                for relation in selected_relations:

                    case = {"backend": backend, "kind": "scalar", "op": op, "n": 1, "k": k,
                            "order": order, "fill": fill, "relation": relation}
                    yield case, "coefficient_cap" if slots > args.coeff_cap else None

                # end for

            # end for

        # end if

        if backend != "semisparse_scalar":

            for n, op in itertools.product(sizes, ARRAY_OPS):

                case = {"backend": backend, "kind": "array", "op": op, "n": n, "k": k,
                        "order": order, "fill": "full", "relation": "same"}
                estimated = 8 * slots * (n * n * 4 + n)
                reason = None

                if slots > args.coeff_cap:

                    reason = "coefficient_cap"

                elif estimated > args.memory_cap * 1024**2:

                    reason = "memory_cap"

                # end if

                yield case, reason

            # end for

        # end if

        if backend in ("sparse", "semisparse_aos", "semisparse_soa"):

            case = {"backend": backend, "kind": "fem", "op": "assemble_solve",
                    "n": k + 1, "k": k, "order": order, "fill": "first",
                    "relation": "regions"}
            estimated = 8 * slots * (k + 1)**2 * 4
            reason = ("coefficient_cap" if slots > args.coeff_cap else
                      "memory_cap" if estimated > args.memory_cap * 1024**2 else None)
            yield case, reason

        # end if

    # end for

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def child(case, args):
    """
    Execute one case in a fresh, timeout-limited interpreter.

    Parameters
    ----------
    case : dict
        Case specification.
    args : argparse.Namespace
        Repeats and timeout.

    Returns
    -------
    dict
        Child result or timeout/error status.
    """

    command = [sys.executable, str(Path(__file__).resolve()), "--child", json.dumps(case),
               "--repeat", str(args.repeat)]

    try:

        proc = subprocess.run(command, capture_output=True, text=True, timeout=args.timeout,
                              env={**os.environ, "OMP_NUM_THREADS": os.getenv("OMP_NUM_THREADS", "1"),
                                   "OPENBLAS_NUM_THREADS": os.getenv("OPENBLAS_NUM_THREADS", "1")})

    except subprocess.TimeoutExpired:

        return {**case, "status": "timeout"}

    # end try

    if proc.returncode:

        return {**case, "status": "error", "returncode": proc.returncode,
                "error": proc.stderr[-500:]}

    # end if

    try:

        return json.loads(proc.stdout)

    except json.JSONDecodeError:

        return {**case, "status": "error", "error": proc.stdout[-500:] + proc.stderr[-500:]}

    # end try

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def profile(args):
    """
    Sample a long-running public-API sparse multiplication and summarize named stacks.

    Parameters
    ----------
    args : argparse.Namespace
        Sampling duration and optional output path.

    Returns
    -------
    str
        Human-readable symbol-level profile summary or availability reason.
    """

    if sys.platform != "darwin":

        return "Profile unavailable: macOS sample is required."

    # end if

    code = ("import pyoti.sparse as s\n"
            "x=2+s.e(1,order=4)+s.e(2,order=4)\n"
            "x=x+x*x+x*x*x+x*x*x*x\n"
            "while True: y=x*x\n")
    process = subprocess.Popen([sys.executable, "-c", code], stdout=subprocess.DEVNULL,
                               stderr=subprocess.PIPE,
                               env={**os.environ, "OMP_NUM_THREADS": "1"})

    try:

        time.sleep(1)

        if process.poll() is not None:

            return "Profile child exited before sampling: " + process.stderr.read().decode()[-400:]

        # end if

        sampled = subprocess.run(["sample", str(process.pid), str(args.profile_seconds)],
                                 capture_output=True, text=True, timeout=args.profile_seconds + 20)
        text = sampled.stdout + sampled.stderr
        top = text.split("Sort by top of stack, same collapsed", 1)[-1]
        mult_match = re.search(r"^\s*dhelp_sparse_mult\s+\(in .*?\)\s+(\d+)$", top, re.M)
        merge_match = re.search(r"^\s*dhelp_sparse_add_dirs\s+\(in .*?\)\s+(\d+)$", top,
                                re.M)
        mult = int(mult_match.group(1)) if mult_match else 0
        merges = int(merge_match.group(1)) if merge_match else 0
        total = mult + merges
        summary = ("exclusive top-of-stack samples: dhelp_sparse_mult={} ({:.1f}%), "
                   "dhelp_sparse_add_dirs={} ({:.1f}%); denominator=these two symbols only.\n"
                   "mult includes index and other work; inlined/stripped symbols cannot be "
                   "attributed independently. Other multiply callees are excluded.\n"
                   "sample exit code={}; raw output follows:\n{}".format(
                       mult, 100 * mult / total if total else 0, merges,
                       100 * merges / total if total else 0, sampled.returncode, text))
        return summary

    except (OSError, subprocess.TimeoutExpired) as exc:

        return "Profile unavailable: {}".format(exc)

    finally:

        process.terminate()

        try:

            process.wait(timeout=3)

        except subprocess.TimeoutExpired:

            process.kill()
            process.wait()

        # end try

    # end try

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def main():
    """
    Parse options, run isolated cases, and save the baseline or a sampled profile.

    Returns
    -------
    int
        Process exit code.
    """

    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--quick", action="store_true", help="small validation grid")
    parser.add_argument("--backends", nargs="+", choices=BACKENDS,
                        help="selected backends (default: baseline, or semi-sparse with --compare)")
    parser.add_argument("--json", metavar="PATH", help="save all case results")
    parser.add_argument("--compare", metavar="PATH", help="compare with saved JSON")
    parser.add_argument("--coeff-cap", type=int, default=1_000_000)
    parser.add_argument("--memory-cap", type=float, default=16, help="estimated MiB per array case")
    parser.add_argument("--timeout", type=float, default=60, help="seconds per child")
    parser.add_argument("--repeat", type=int, default=3)
    parser.add_argument("--profile", action="store_true", help="sample sparse multiply")
    parser.add_argument("--profile-output", metavar="PATH", help="save sample output")
    parser.add_argument("--profile-seconds", type=int, default=5)
    parser.add_argument("--child", help=argparse.SUPPRESS)
    args = parser.parse_args()
    args.backends = args.backends or (("semisparse_scalar", "semisparse_aos", "semisparse_soa")
                                      if args.compare else ("sparse", "dense"))

    if args.child:

        print(json.dumps(run_case(json.loads(args.child), args.repeat)))
        return 0

    # end if

    if args.profile:

        report = profile(args)
        print(report[:2000])

        if args.profile_output:

            Path(args.profile_output).write_text(report)

        # end if

        return 0

    # end if

    reference = None

    if args.compare:

        saved = json.loads(Path(args.compare).read_text())
        reference = {case_key(case): case for case in saved["cases"]
                     if case["status"] == "ok"}

    # end if

    cases = []
    started = time.monotonic()

    for case, reason in grid(args):

        result = ({**case, "status": "skipped", "reason": reason} if reason else child(case, args))

        if result["status"] == "ok" and reference is not None:

            previous = reference.get(baseline_key(result))

            if previous is not None:

                result["baseline_seconds"] = previous["seconds"]
                result["speedup"] = previous["seconds"] / result["seconds"]
                result["baseline_peak_rss_bytes"] = previous.get("peak_rss_bytes")

                if previous.get("peak_rss_bytes"):

                    result["rss_ratio"] = (result["peak_rss_bytes"] /
                                           previous["peak_rss_bytes"])

                # end if

            # end if

        # end if

        cases.append(result)
        print("{} {} {} k={} order={} n={}: {}".format(
            case["backend"], case["kind"], case["op"], case["k"], case["order"],
            case["n"], result["status"]), file=sys.stderr, flush=True)

        if args.json and len(cases) % 20 == 0:

            Path(args.json).write_text(json.dumps(
                {"metadata": metadata(), "elapsed_seconds": time.monotonic() - started,
                 "cases": cases}, indent=2))

        # end if

    # end for

    print_table(cases, reference)

    if args.json:

        Path(args.json).write_text(json.dumps(
            {"metadata": metadata(), "elapsed_seconds": time.monotonic() - started,
             "cases": cases}, indent=2))

    # end if

    return 0

# end function
# --------------------------------------------------------------------------------------------------------


if __name__ == "__main__":

    sys.exit(main())

# end if
