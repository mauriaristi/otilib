#!/usr/bin/env python3
"""
Benchmark direction-helper loading and sparse OTI multiplication.

Each case runs in a fresh interpreter so its first operation can include the cost of building
its multiplication table. Scalar operands populate every direction through half the truncation
order: this exercises the highest-order product without allocating millions of unused
highest-order input coefficients (order 4 with 100 bases has over four million of those).

Examples
--------
Run the benchmark and save a machine-readable baseline::

    conda run -n pyoti python tools/bench_dhelp.py --json build/bench_dhelp_before.json
"""

import argparse
import json
import os
import platform
import statistics
import subprocess
import sys
import time


SCALAR_CONFIGS = ((2, 1000), (4, 100), (10, 10))
CASES = ([("mult_dir", order, bases) for order, bases in SCALAR_CONFIGS]
         + [("scalar_mul", order, bases) for order, bases in SCALAR_CONFIGS]
         + [("matrix_dot", 2, 3)])


def populated_scalar(oti, core, order, bases):
    """
    Create a scalar with nonzero coefficients in every direction through half the order.

    Parameters
    ----------
    oti : module
        Sparse OTI API.
    core : module
        Core API with direction counts.
    order : int
        Truncation order.
    bases : int
        Number of imaginary bases.

    Returns
    -------
    sotinum
        Fully populated scalar at every operand order used in the highest-order product.
    """

    result = oti.sotinum(1.0, order=order)
    helper = core.get_dHelp()

    for degree in range(1, order // 2 + 1):

        for index in range(helper.get_ndir_order(bases, degree)):

            result[[index, degree]] = 1.0

        # end for

    # end for

    return result

# end function


def operation(kind, order, bases, oti, core):
    """
    Prepare one callable without invoking the operation being timed.

    Parameters
    ----------
    kind : str
        Benchmark case name.
    order : int
        Truncation order.
    bases : int
        Imaginary basis count.
    oti : module
        Sparse OTI API.
    core : module
        Core API.

    Returns
    -------
    callable
        No-argument operation to time.
    """

    if kind == "mult_dir":

        helper = core.get_dHelp()
        degree = order // 2
        index = helper.get_ndir_order(bases, degree) - 1
        return lambda: helper.mult_dir(index, degree, index, degree)

    # end if

    lhs = populated_scalar(oti, core, order, bases)
    rhs = populated_scalar(oti, core, order, bases)

    if kind == "scalar_mul":

        return lambda: lhs * rhs

    # end if

    left = oti.array([[lhs, rhs], [rhs, lhs]])
    right = oti.array([[rhs, lhs], [lhs, rhs]])
    return lambda: oti.dot(left, right)

# end function


def measure(func, repeat):
    """
    Time the first invocation separately from repeated steady-state invocations.

    Parameters
    ----------
    func : callable
        Operation to benchmark.
    repeat : int
        Number of subsequent timed calls.

    Returns
    -------
    dict
        First, minimum and median call times in seconds.
    """

    start = time.perf_counter()
    func()
    first = time.perf_counter() - start
    samples = []

    for unused in range(repeat):

        start = time.perf_counter()
        func()
        samples.append(time.perf_counter() - start)

    # end for

    return {"first_seconds": first, "min_seconds": min(samples),
            "median_seconds": statistics.median(samples)}

# end function


def child(args):
    """
    Import pyoti in this fresh process and print one JSON result.

    Parameters
    ----------
    args : argparse.Namespace
        Child mode, case parameters and repetition count.
    """

    import resource

    start = time.perf_counter()
    import pyoti
    import pyoti.core as core
    import pyoti.sparse as oti
    import_time = time.perf_counter() - start

    # ru_maxrss is bytes on macOS and KiB on Linux.
    rss = resource.getrusage(resource.RUSAGE_SELF).ru_maxrss
    rss_bytes = rss if sys.platform == "darwin" else rss * 1024
    result = {"import_seconds": import_time, "rss_after_import_bytes": rss_bytes,
              "pyoti": pyoti.__version__}

    if args.worker != "import":

        kind, order, bases = args.worker.split(":")
        result.update({"op": kind, "order": int(order), "nbases": int(bases)})
        func = operation(kind, int(order), int(bases), oti, core)
        result.update(measure(func, args.repeat))

    # end if

    print(json.dumps(result))

# end function


def run_child(worker, repeat):
    """
    Run one case in a separate Python interpreter with the current environment.

    Parameters
    ----------
    worker : str
        Import probe or encoded operation and dimensions.
    repeat : int
        Number of steady-state measurements.

    Returns
    -------
    dict
        Decoded child result.
    """

    output = subprocess.check_output(
        [sys.executable, os.path.abspath(__file__), "--worker", worker,
         "--repeat", str(repeat)], text=True)
    return json.loads(output)

# end function


def main():
    """
    Run the default grid, print a readable table and optionally save JSON results.

    Returns
    -------
    int
        Process exit status.
    """

    parser = argparse.ArgumentParser(description="Benchmark pyoti direction-helper tables.")
    parser.add_argument("--repeat", type=int, default=5, help="steady-state calls per case")
    parser.add_argument("--json", metavar="PATH", help="write results to a JSON file")
    parser.add_argument("--worker", help=argparse.SUPPRESS)
    args = parser.parse_args()

    if args.repeat < 1:

        parser.error("--repeat must be at least 1")

    # end if

    if args.worker:

        child(args)
        return 0

    # end if

    imported = run_child("import", args.repeat)
    cases = []

    for kind, order, bases in CASES:

        case = run_child("{}:{}:{}".format(kind, order, bases), args.repeat)
        cases.append({key: case[key] for key in (
            "op", "order", "nbases", "first_seconds", "min_seconds", "median_seconds")})

    # end for

    data = {"metadata": {"pyoti": imported["pyoti"],
                         "python": platform.python_version(), "platform": platform.platform(),
                         "machine": platform.machine(), "repeat": args.repeat},
            "import_seconds": imported["import_seconds"],
            "rss_after_import_bytes": imported["rss_after_import_bytes"], "cases": cases}

    print("pyoti import: {:.4f} s; RSS after import: {:.1f} MiB".format(
        data["import_seconds"], data["rss_after_import_bytes"] / 1048576))
    print("{:<13} {:>5} {:>6} {:>12} {:>12} {:>12}".format(
        "operation", "order", "bases", "first [ms]", "min [ms]", "median [ms]"))

    for case in cases:

        print("{:<13} {:>5} {:>6} {:>12.4f} {:>12.4f} {:>12.4f}".format(
            case["op"], case["order"], case["nbases"], 1000 * case["first_seconds"],
            1000 * case["min_seconds"], 1000 * case["median_seconds"]))

    # end for

    if args.json:

        with open(args.json, "w") as handle:

            json.dump(data, handle, indent=2)
            handle.write("\n")

        # end with

    # end if

    return 0

# end function


if __name__ == "__main__":

    sys.exit(main())

# end if
