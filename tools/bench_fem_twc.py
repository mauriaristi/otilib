"""
Benchmark the TWC finite-element model with the sparse, semi-sparse and dense algebras.

Each algebra/configuration runs in a fresh process. The report contains stage timings, peak memory,
and derivative-wise correctness comparisons of every non-sparse algebra against the sparse oracle.
``--algebras`` selects the algebras to run (default: all three); a non-sparse algebra whose preflight
fails is recorded as ``skipped`` with the reason.
"""

from __future__ import annotations

import argparse
import csv
import ctypes
import datetime
import fnmatch
import importlib.util
import json
import os
import platform
import resource
import shutil
import subprocess
import sys
import tempfile
import traceback
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
MEMTRACK_SOURCE = ROOT / "tools" / "bench" / "memtrack.c"
STAGES = ("assembly_K", "assembly_f", "boundary_conditions", "tocsr", "solve")
ALGEBRAS = ("sparse", "semisparse", "dense")
NON_SPARSE = ("semisparse", "dense")
COLORS = {"sparse": "#2457A6", "semisparse": "#E07A20", "dense": "#2A9D5B"}
LABELS = {"sparse": "sparse", "semisparse": "semi-sparse", "dense": "dense"}
_LINUX_MEMTRACK_SOURCE = r"""
#define _GNU_SOURCE
#include <errno.h>
#include <malloc.h>
#include <stdatomic.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>

extern void *__libc_malloc(size_t size);
extern void *__libc_calloc(size_t count, size_t size);
extern void *__libc_realloc(void *ptr, size_t size);
extern void __libc_free(void *ptr);
extern void *__libc_memalign(size_t alignment, size_t size);

static _Atomic int64_t live_bytes = 0;
static _Atomic int64_t peak_bytes = 0;

// *******************************************************************************************************
static void update_bytes(int64_t delta) {
    int64_t current = atomic_fetch_add(&live_bytes, delta) + delta;
    int64_t peak = atomic_load(&peak_bytes);

    while (current > peak && !atomic_compare_exchange_weak(&peak_bytes, &peak, current)) {
    }
}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int64_t memtrack_live(void) {
    return atomic_load(&live_bytes);
}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int64_t memtrack_peak(void) {
    return atomic_load(&peak_bytes);
}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void memtrack_reset_peak(void) {
    atomic_store(&peak_bytes, atomic_load(&live_bytes));
}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void *malloc(size_t size) {
    void *ptr = __libc_malloc(size);

    if (ptr != NULL) {
        update_bytes((int64_t)malloc_usable_size(ptr));
    }

    return ptr;
}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void *calloc(size_t count, size_t size) {
    void *ptr = __libc_calloc(count, size);

    if (ptr != NULL) {
        update_bytes((int64_t)malloc_usable_size(ptr));
    }

    return ptr;
}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void free(void *ptr) {
    if (ptr != NULL) {
        update_bytes(-(int64_t)malloc_usable_size(ptr));
    }

    __libc_free(ptr);
}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void *realloc(void *ptr, size_t size) {
    int64_t old_size = ptr == NULL ? 0 : (int64_t)malloc_usable_size(ptr);
    void *new_ptr = __libc_realloc(ptr, size);

    if (new_ptr != NULL) {
        update_bytes((int64_t)malloc_usable_size(new_ptr) - old_size);
    } else if (size == 0 && ptr != NULL) {
        update_bytes(-old_size);
    }

    return new_ptr;
}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
int posix_memalign(void **out, size_t alignment, size_t size) {
    void *ptr = __libc_memalign(alignment, size);

    if (ptr == NULL) {
        return ENOMEM;
    }

    *out = ptr;
    update_bytes((int64_t)malloc_usable_size(ptr));
    return 0;
}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void *aligned_alloc(size_t alignment, size_t size) {
    void *ptr = __libc_memalign(alignment, size);

    if (ptr != NULL) {
        update_bytes((int64_t)malloc_usable_size(ptr));
    }

    return ptr;
}
// -------------------------------------------------------------------------------------------------------


// *******************************************************************************************************
void *valloc(size_t size) {
    void *ptr = __libc_memalign((size_t)sysconf(_SC_PAGESIZE), size);

    if (ptr != NULL) {
        update_bytes((int64_t)malloc_usable_size(ptr));
    }

    return ptr;
}
// -------------------------------------------------------------------------------------------------------
"""


# ********************************************************************************************************
def _rss_bytes() -> int:
    """
    Return the current process high-water resident set in bytes.

    Returns
    -------
    int
        Peak resident-set size in bytes.

    Examples
    --------
    >>> _rss_bytes() > 0
    True
    """

    peak = int(resource.getrusage(resource.RUSAGE_SELF).ru_maxrss)

    if sys.platform == "darwin":

        return peak

    # end if

    return peak * 1024

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _load_model():
    """
    Load the TWC example module directly from the repository.

    Returns
    -------
    module
        Imported ``examples/python/fem_twc.py`` module.

    Examples
    --------
    >>> _load_model().__name__
    'fem_twc'
    """

    path = ROOT / "examples" / "python" / "fem_twc.py"
    spec = importlib.util.spec_from_file_location("fem_twc", path)

    if spec is None or spec.loader is None:

        raise ImportError(f"Cannot load the FEM example at {path}")

    # end if

    model = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(model)

    return model

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _load_tracker(path: str | None):
    """
    Load the preloaded malloc tracker and record its baseline live bytes.

    Parameters
    ----------
    path : str or None
        Shared library path, or `None` when heap tracking is unavailable.

    Returns
    -------
    tuple
        Tracker handle and baseline live-byte count.

    Examples
    --------
    >>> _load_tracker(None)
    (None, None)
    """

    if path is None:

        return None, None

    # end if

    tracker = ctypes.CDLL(path)
    tracker.memtrack_live.restype = ctypes.c_int64
    tracker.memtrack_peak.restype = ctypes.c_int64
    tracker.memtrack_reset_peak.restype = None
    tracker.memtrack_reset_peak()
    baseline = int(tracker.memtrack_live())

    return tracker, baseline

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _preflight(model, name: str):
    """
    Check whether a non-sparse algebra exposes the APIs required by the TWC model.

    The check imports ``pyoti.<name>``, looks for the TWC APIs, asks ``pyoti.fem.set_global_algebra``
    to accept the module and builds a small probe array.

    Parameters
    ----------
    model : module
        FEM example module.
    name : str
        Algebra name, ``semisparse`` or ``dense``.

    Returns
    -------
    tuple
        Algebra module and `None` when available, otherwise `(None, reason)`.

    Examples
    --------
    >>> callable(_preflight)
    True
    """

    try:

        algebra = importlib.import_module(f"pyoti.{name}")

    except Exception as exc:

        return None, f"cannot import pyoti.{name}: {exc}"

    # end try

    required = ("array", "e", "lil_matrix", "set_printoptions", "solve", "zeros", "zero")
    missing = [item for item in required if not hasattr(algebra, item)]

    if missing:

        return None, f"pyoti.{name} lacks TWC APIs: " + ", ".join(missing)

    # end if

    try:

        model.fem.set_global_algebra(algebra)
        probe = algebra.zeros((1, 1), bases=[1], order=1)

        if not hasattr(probe, "get_deriv"):

            raise NotImplementedError(f"{name} arrays lack get_deriv")

        # end if

    except Exception as exc:

        return None, f"pyoti.fem.set_global_algebra rejects {name}: {exc}"

    # end try

    return algebra, None

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _solution_arrays(model, result):
    """
    Extract the real solution and every derivative vector for oracle comparison.

    Parameters
    ----------
    model : module
        TWC example module providing the direction generator.
    result : dict
        Result returned by ``fem_twc.run``.

    Returns
    -------
    dict
        Stable direction keys mapped to NumPy arrays.

    Examples
    --------
    >>> callable(_solution_arrays)
    True
    """
    import numpy as np

    solution = result["u"]
    arrays = {"real": np.asarray(solution.real)}

    for direction in model._directions(len(result["bases"]), result["order"]):

        if direction:

            key = "d_" + "_".join(str(base) for base in direction)
            arrays[key] = np.asarray(solution.get_deriv(list(direction)))

        # end if

    # end for

    return arrays

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _relative_difference(actual, reference_path: str) -> float:
    """
    Compute the largest derivative-wise relative L2 difference to sparse.

    Parameters
    ----------
    actual : dict
        Direction-keyed arrays from the current algebra.
    reference_path : str
        NPZ file containing sparse oracle arrays.

    Returns
    -------
    float
        Largest relative L2 difference over the solution and every derivative.

    Examples
    --------
    >>> callable(_relative_difference)
    True
    """
    import numpy as np

    errors = []

    with np.load(reference_path, allow_pickle=False) as reference:

        if set(actual) != set(reference.files):

            raise ValueError("Sparse and compared derivative directions do not match")

        # end if

        reference_scale = float(np.linalg.norm(reference["real"]))
        zero_floor = np.finfo(np.float64).eps * max(
            reference_scale, np.finfo(np.float64).tiny
        )

        for key, observed in actual.items():

            expected = np.asarray(reference[key])
            observed = np.asarray(observed)

            if observed.shape != expected.shape:

                raise ValueError(f"Shape mismatch for {key}: {observed.shape} != {expected.shape}")

            # end if

            denominator = max(float(np.linalg.norm(expected)), zero_floor)
            errors.append(float(np.linalg.norm(observed - expected) / denominator))

        # end for

    # end with

    return max(errors, default=0.0)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _worker(args) -> int:
    """
    Run one benchmark case in this fresh worker process.

    Parameters
    ----------
    args : argparse.Namespace
        Internal worker configuration.

    Returns
    -------
    int
        Zero after a run or a clean skip; one after a recorded worker error.

    Examples
    --------
    >>> callable(_worker)
    True
    """
    import numpy as np

    try:

        model = _load_model()

        if args.algebra == "sparse":

            import pyoti.sparse as algebra

        else:

            algebra, reason = _preflight(model, args.algebra)

            if reason is not None:

                print(json.dumps({"status": "skipped", "error": reason}))
                return 0

            # end if

        # end if

        tracker, baseline = _load_tracker(args.tracker)
        rss_start = _rss_bytes()
        result = model.run(
            algebra,
            (args.ndivs, args.ndivs),
            args.order,
            perturb_geometry=args.perturb_geometry,
        )
        rss_peak = _rss_bytes()

        if tracker is None:

            heap_peak = None
            heap_live = None

        else:

            heap_peak = max(0, int(tracker.memtrack_peak()) - baseline)
            heap_live = max(0, int(tracker.memtrack_live()) - baseline)

        # end if

        arrays = _solution_arrays(model, result)

        if args.solution:

            np.savez_compressed(args.solution, **arrays)

        # end if

        max_difference = None

        if args.reference:

            max_difference = _relative_difference(arrays, args.reference)

        # end if

        value_first = [
            row for row in result["lame_errors"]
            if len(row["direction"]) <= 1
        ]
        valid_lame = [row for row in value_first if row["relative_l2"] is not None]
        payload = {
            "status": "ok",
            "dof": int(result["u"].shape[0]),
            "timings": result["timings"],
            "peak_rss_bytes": rss_peak,
            "rss_increase_bytes": max(0, rss_peak - rss_start),
            "heap_peak_bytes": heap_peak,
            "heap_live_after_bytes": heap_live,
            "max_relative_diff_to_sparse": max_difference,
            "max_lame_relative_value_first": max(
                (float(row["relative_l2"]) for row in valid_lame), default=0.0
            ),
            "max_lame_absolute_value_first": max(
                (float(row["max_abs"]) for row in value_first), default=0.0
            ),
        }
        print(json.dumps(payload, allow_nan=False))

        return 0

    except Exception as exc:

        print(json.dumps({
            "status": "error",
            "error": str(exc),
            "traceback": traceback.format_exc(),
        }))

        return 1

    # end try

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _worker_command(
    algebra: str,
    ndivs: int,
    order: int,
    nbases: int,
    build_dir: Path,
    tracker_path: Path | None,
    reference_path: Path | None,
    solution_path: Path | None,
    timeout: int,
):
    """
    Launch one algebra/configuration in a clean Python process.

    Parameters
    ----------
    algebra : str
        One of `sparse`, `semisparse` or `dense`.
    ndivs : int
        Radial and circumferential divisions.
    order : int
        OTI truncation order.
    nbases : int
        Number of perturbation bases, four or six.
    build_dir : pathlib.Path
        Build tree containing the compiled package.
    tracker_path : pathlib.Path or None
        Platform interposition library for heap measurement.
    reference_path : pathlib.Path or None
        Sparse reference NPZ file (non-sparse algebras).
    solution_path : pathlib.Path or None
        Output NPZ path for the sparse process.
    timeout : int
        Maximum runtime for this worker process in seconds.

    Returns
    -------
    dict
        Parsed worker record, including `error` for failed or timed-out workers.

    Examples
    --------
    >>> callable(_worker_command)
    True
    """
    command = [
        sys.executable,
        "-m",
        "tools.bench_fem_twc",
        "--worker",
        "--algebra", algebra,
        "--ndivs", str(ndivs),
        "--order", str(order),
        "--perturb-geometry", str(nbases == 6),
    ]

    if tracker_path is not None:

        command.extend(("--tracker", str(tracker_path)))

    # end if

    if reference_path is not None:

        command.extend(("--reference", str(reference_path)))

    # end if

    if solution_path is not None:

        command.extend(("--solution", str(solution_path)))

    # end if

    environment = os.environ.copy()
    previous_pythonpath = environment.get("PYTHONPATH", "")
    python_paths = [str(build_dir.resolve()), str(ROOT)]

    if previous_pythonpath:

        python_paths.append(previous_pythonpath)

    # end if

    environment["PYTHONPATH"] = os.pathsep.join(python_paths)

    if tracker_path is not None and sys.platform in ("darwin", "linux"):

        variable = "DYLD_INSERT_LIBRARIES" if sys.platform == "darwin" else "LD_PRELOAD"
        previous = environment.get(variable, "")
        environment[variable] = os.pathsep.join(
            value for value in (str(tracker_path.resolve()), previous) if value
        )

    # end if

    try:

        completed = subprocess.run(
            command,
            cwd=ROOT,
            env=environment,
            capture_output=True,
            text=True,
            timeout=timeout,
            check=False,
        )

    except subprocess.TimeoutExpired:

        return {"status": "error", "error": f"Worker timed out after {timeout} seconds"}

    except OSError as exc:

        return {"status": "error", "error": f"Could not start worker: {exc}"}

    # end try

    stdout_lines = completed.stdout.strip().splitlines()

    if stdout_lines:

        try:

            payload = json.loads(stdout_lines[-1])

        except json.JSONDecodeError:

            payload = {"status": "error", "error": "Worker returned invalid JSON"}

        # end try

    else:

        payload = {"status": "error", "error": "Worker produced no JSON output"}

    # end if

    if completed.returncode != 0 and payload.get("status") not in ("error", "skipped"):

        payload = {"status": "error", "error": completed.stderr[-2000:]}

    # end if

    if payload.get("status") == "error" and completed.stderr:

        payload["stderr"] = completed.stderr[-2000:]

    # end if

    return payload

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _case_grid(quick: bool):
    """
    Return the full or smoke-test TWC benchmark grid.

    Parameters
    ----------
    quick : bool
        Restrict the grid to mesh sizes 5 and 10 and order two with four bases.

    Returns
    -------
    list[tuple[int, int, int]]
        Tuples of mesh divisions, order, and number of perturbation bases.

    Examples
    --------
    >>> _case_grid(True)
    [(5, 2, 4), (10, 2, 4)]
    """

    if quick:

        mesh_sizes = (5, 10)
        orders = (2,)
        basis_counts = (4,)

    else:

        mesh_sizes = (5, 10, 20, 40, 80)
        orders = (2, 4)
        basis_counts = (4, 6)

    # end if

    return [
        (ndivs, order, nbases)
        for order in orders
        for nbases in basis_counts
        for ndivs in mesh_sizes
    ]

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _case_ids(quick: bool, algebras=ALGEBRAS) -> list[str]:
    """
    Generate stable names for every algebra/configuration in a grid.

    Parameters
    ----------
    quick : bool
        Whether to use the reduced validation grid.
    algebras : sequence of str, optional
        Algebras to include, in the order of :data:`ALGEBRAS`.

    Returns
    -------
    list[str]
        Case IDs such as `sparse-n5-o2-b4`.

    Examples
    --------
    >>> "dense-n5-o2-b4" in _case_ids(True)
    True
    >>> _case_ids(True, ("sparse",))
    ['sparse-n5-o2-b4', 'sparse-n10-o2-b4']
    """

    return [
        f"{algebra}-n{ndivs}-o{order}-b{nbases}"
        for ndivs, order, nbases in _case_grid(quick)
        for algebra in ALGEBRAS
        if algebra in algebras
    ]

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _selected_case_ids(quick: bool, patterns: list[str] | None, algebras=ALGEBRAS) -> set[str]:
    """
    Filter case IDs by shell-style glob patterns.

    Parameters
    ----------
    quick : bool
        Whether to filter the reduced validation grid.
    patterns : list[str] or None
        Case ID glob patterns, or `None` to select the full grid.
    algebras : sequence of str, optional
        Algebras to include.

    Returns
    -------
    set[str]
        The selected case IDs.

    Examples
    --------
    >>> _selected_case_ids(True, ["sparse-n5-*"])
    {'sparse-n5-o2-b4'}
    """

    case_ids = _case_ids(quick, algebras)

    if not patterns:

        return set(case_ids)

    # end if

    selected = {
        case_id for case_id in case_ids
        if any(fnmatch.fnmatchcase(case_id, pattern) for pattern in patterns)
    }
    unmatched = [
        pattern for pattern in patterns
        if not any(fnmatch.fnmatchcase(case_id, pattern) for case_id in case_ids)
    ]

    if unmatched:

        raise ValueError("--cases patterns matched no grid entries: " + ", ".join(unmatched))

    # end if

    return selected

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _compile_tracker(directory: Path, disabled: bool) -> tuple[Path | None, str | None]:
    """
    Compile the existing macOS tracker or a glibc-compatible Linux interposer.

    Parameters
    ----------
    directory : pathlib.Path
        Temporary folder for generated source and library files.
    disabled : bool
        Whether heap tracking was explicitly disabled.

    Returns
    -------
    tuple
        Tracker path and a warning note, if tracking is unavailable.

    Examples
    --------
    >>> _compile_tracker(Path('.'), True)
    (None, 'disabled by request')
    """

    if disabled:

        return None, "disabled by request"

    # end if

    if sys.platform not in ("darwin", "linux"):

        return None, f"heap tracker unsupported on {sys.platform}; RSS only"

    # end if

    compiler = os.environ.get("CC", "cc").split()

    if not compiler or shutil.which(compiler[0]) is None:

        return None, "C compiler unavailable; RSS only"

    # end if

    if sys.platform == "darwin":

        if not MEMTRACK_SOURCE.is_file():

            return None, "tools/bench/memtrack.c unavailable; RSS only"

        # end if

        library = directory / "libmemtrack.dylib"
        command = [
            *compiler, "-dynamiclib", "-O2", str(MEMTRACK_SOURCE), "-o", str(library)
        ]

    else:

        source = directory / "memtrack_linux.c"
        source.write_text(_LINUX_MEMTRACK_SOURCE, encoding="utf-8")
        library = directory / "libmemtrack.so"
        command = [
            *compiler, "-shared", "-fPIC", "-O2", "-std=c11", str(source), "-o",
            str(library),
        ]

    # end if

    completed = subprocess.run(command, capture_output=True, text=True, check=False)

    if completed.returncode != 0:

        detail = completed.stderr.strip() or "unknown compiler error"
        return None, f"memtrack build failed ({detail}); RSS only"

    # end if

    return library, None

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _record(config, algebra: str, payload: dict, status: str = "ok") -> dict:
    """
    Convert one worker result into a flat CSV row.

    Parameters
    ----------
    config : tuple
        Mesh divisions, order, and number of bases.
    algebra : str
        Algebra name for the case.
    payload : dict
        Worker result or failure/skip payload.
    status : str
        Case status: `ok`, `skipped`, or `error`.

    Returns
    -------
    dict
        CSV fields for one benchmark case.

    Examples
    --------
    >>> _record((5, 2, 4), "sparse", {}, "skipped")["status"]
    'skipped'
    """

    ndivs, order, nbases = config
    timings = payload.get("timings", {})
    record = {
        "status": status,
        "algebra": algebra,
        "ndivs_radial": ndivs,
        "ndivs_theta": ndivs,
        "order": order,
        "nbases": nbases,
        "perturb_geometry": nbases == 6,
        "dof": payload.get("dof"),
        "peak_rss_bytes": payload.get("peak_rss_bytes"),
        "rss_increase_bytes": payload.get("rss_increase_bytes"),
        "heap_peak_bytes": payload.get("heap_peak_bytes"),
        "heap_live_after_bytes": payload.get("heap_live_after_bytes"),
        "max_relative_diff_to_sparse": payload.get("max_relative_diff_to_sparse"),
        "max_lame_relative_value_first": payload.get("max_lame_relative_value_first"),
        "max_lame_absolute_value_first": payload.get("max_lame_absolute_value_first"),
        "error": payload.get("error", ""),
    }

    for stage in STAGES:

        record[f"{stage}_seconds"] = timings.get(stage)

    # end for

    return record

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _read_records(csv_path: Path) -> list[dict]:
    """
    Read benchmark rows and convert numeric columns from CSV strings.

    Parameters
    ----------
    csv_path : pathlib.Path
        Per-case CSV file.

    Returns
    -------
    list[dict]
        Rows with numeric fields converted to integers, floats, or `None`.

    Examples
    --------
    >>> callable(_read_records)
    True
    """

    if not csv_path.exists():

        return []

    # end if

    integer_fields = ("ndivs_radial", "ndivs_theta", "order", "nbases", "dof")
    float_fields = (
        "assembly_K_seconds", "assembly_f_seconds", "boundary_conditions_seconds",
        "tocsr_seconds", "solve_seconds", "peak_rss_bytes", "rss_increase_bytes",
        "heap_peak_bytes", "heap_live_after_bytes", "max_relative_diff_to_sparse",
        "max_lame_relative_value_first", "max_lame_absolute_value_first",
    )
    records = []

    with csv_path.open("r", newline="", encoding="utf-8") as stream:

        for row in csv.DictReader(stream):

            row["perturb_geometry"] = row["perturb_geometry"].lower() == "true"

            for field in integer_fields:

                row[field] = int(row[field]) if row[field] else None

            # end for

            for field in float_fields:

                row[field] = float(row[field]) if row[field] else None

            # end for

            records.append(row)

        # end for

    # end with

    return records

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _plot_results(records: list[dict], output_dir: Path) -> list[str]:
    """
    Generate stage-time, memory, and speedup figures for the algebras present in the records.

    Parameters
    ----------
    records : list[dict]
        Numeric benchmark records.
    output_dir : pathlib.Path
        Directory receiving figures.

    Returns
    -------
    list[str]
        Names of figures created, or an empty list when matplotlib is unavailable.

    Examples
    --------
    >>> isinstance(_plot_results([], Path('.')), list)
    True
    """

    try:

        import matplotlib

        matplotlib.use("Agg")
        import matplotlib.pyplot as plt

    except ImportError:

        return []

    # end try

    successful = [
        row for row in records
        if row["status"] == "ok" and row.get("dof") is not None
    ]

    if not successful:

        return []

    # end if

    groups = ((2, 4), (2, 6), (4, 4), (4, 6))
    present = [
        algebra for algebra in ALGEBRAS
        if any(row["algebra"] == algebra for row in successful)
    ]
    stage_styles = ("-", "--", ":", "-.", (0, (5, 1, 1, 1)))
    figures = []

    figure, axes = plt.subplots(2, 2, figsize=(13, 9), constrained_layout=True)

    for axis, (order, nbases) in zip(axes.flat, groups):

        group = [
            row for row in successful
            if row["order"] == order and row["nbases"] == nbases
        ]

        for algebra in present:

            algebra_rows = [row for row in group if row["algebra"] == algebra]

            for stage, style in zip(STAGES, stage_styles):

                selected = sorted(
                    (row for row in algebra_rows if row.get(f"{stage}_seconds") is not None),
                    key=lambda row: row["dof"],
                )

                if selected:

                    axis.plot(
                        [row["dof"] for row in selected],
                        [row[f"{stage}_seconds"] for row in selected],
                        color=COLORS[algebra],
                        linestyle=style,
                        marker="o",
                        label=f"{LABELS[algebra]} {stage}",
                    )

                # end if

            # end for

        # end for

        axis.set_title(f"order {order}, {nbases} bases")
        axis.set_xlabel("Degrees of freedom")
        axis.set_ylabel("Stage time (s)")
        axis.set_xscale("log")
        axis.set_yscale("log")
        axis.grid(True, alpha=0.25)

        if group:

            axis.legend(fontsize="x-small", ncol=max(2, len(present)))

        # end if

    # end for

    figure.suptitle("TWC FEM stage timings vs degrees of freedom")
    figure.savefig(output_dir / "fem_twc_stages.png", dpi=160)
    plt.close(figure)
    figures.append("fem_twc_stages.png")

    figure, axes = plt.subplots(2, 2, figsize=(10, 7), constrained_layout=True)

    for axis, (order, nbases) in zip(axes.flat, groups):

        group = [
            row for row in successful
            if row["order"] == order and row["nbases"] == nbases
        ]

        for algebra in present:

            selected = sorted(
                (
                    row for row in group
                    if row["algebra"] == algebra and row.get("peak_rss_bytes") is not None
                ),
                key=lambda row: row["dof"],
            )

            if selected:

                axis.plot(
                    [row["dof"] for row in selected],
                    [row["peak_rss_bytes"] / 1024.0**2 for row in selected],
                    color=COLORS[algebra],
                    linestyle="-",
                    marker="o",
                    label=f"{LABELS[algebra]} peak RSS",
                )

            # end if

            heap_rows = [row for row in selected if row.get("heap_peak_bytes") is not None]

            if heap_rows:

                axis.plot(
                    [row["dof"] for row in heap_rows],
                    [row["heap_peak_bytes"] / 1024.0**2 for row in heap_rows],
                    color=COLORS[algebra],
                    linestyle="--",
                    marker="x",
                    label=f"{LABELS[algebra]} heap peak",
                )

            # end if

        # end for

        axis.set_title(f"order {order}, {nbases} bases")
        axis.set_xlabel("Degrees of freedom")
        axis.set_ylabel("Memory (MiB)")
        axis.set_xscale("log")
        axis.set_yscale("log")
        axis.grid(True, alpha=0.25)

        if group:

            axis.legend(fontsize="small")

        # end if

    # end for

    figure.suptitle("TWC FEM peak memory vs degrees of freedom")
    figure.savefig(output_dir / "fem_twc_memory.png", dpi=160)
    plt.close(figure)
    figures.append("fem_twc_memory.png")

    # Speedup of each non-sparse algebra relative to sparse: one row of panels per algebra.
    case_map = {}

    for row in successful:

        key = (row["ndivs_radial"], row["order"], row["nbases"])
        case_map.setdefault(key, {})[row["algebra"]] = row

    # end for

    compared = [
        algebra for algebra in NON_SPARSE
        if any(algebra in pair and "sparse" in pair for pair in case_map.values())
    ]

    if compared:

        figure, axes = plt.subplots(
            len(compared), 4, figsize=(16, 3.8 * len(compared)), constrained_layout=True,
            squeeze=False,
        )

        for row_axes, algebra in zip(axes, compared):

            for axis, (order, nbases) in zip(row_axes, groups):

                keys = sorted(
                    key for key, pair in case_map.items()
                    if key[1:] == (order, nbases) and "sparse" in pair and algebra in pair
                )

                for stage, color in zip(STAGES, plt.cm.tab10.colors):

                    dofs = []
                    speedups = []

                    for key in keys:

                        sparse_time = case_map[key]["sparse"].get(f"{stage}_seconds")
                        other_time = case_map[key][algebra].get(f"{stage}_seconds")

                        if sparse_time and other_time:

                            dofs.append(case_map[key]["sparse"]["dof"])
                            speedups.append(sparse_time / other_time)

                        # end if

                    # end for

                    if dofs:

                        axis.plot(dofs, speedups, marker="o", color=color, label=stage)

                    # end if

                # end for

                axis.axhline(1.0, color="black", linewidth=0.8, linestyle="--")
                axis.set_title(f"{LABELS[algebra]}: order {order}, {nbases} bases")
                axis.set_xlabel("Degrees of freedom")
                axis.set_ylabel(f"Sparse / {LABELS[algebra]} time")
                axis.set_xscale("log")
                axis.grid(True, alpha=0.25)

                if keys:

                    axis.legend(fontsize="small")

                # end if

            # end for

        # end for

        figure.suptitle("TWC FEM stage speedup relative to sparse")
        figure.savefig(output_dir / "fem_twc_speedup.png", dpi=160)
        plt.close(figure)
        figures.append("fem_twc_speedup.png")

    # end if

    return figures

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _write_report(
    records: list[dict],
    output_dir: Path,
    quick: bool,
    tracker_note: str | None,
    algebras=ALGEBRAS,
) -> None:
    """
    Write the per-case CSV, plots, figure script, and report README.

    Parameters
    ----------
    records : list[dict]
        Successful, skipped, and failed case rows.
    output_dir : pathlib.Path
        Dated benchmark output directory.
    quick : bool
        Whether this run used the quick grid.
    tracker_note : str or None
        Heap-tracker status or warning.
    algebras : sequence of str, optional
        Algebras that were selected for the run (listed in the README).

    Examples
    --------
    >>> callable(_write_report)
    True
    """

    output_dir.mkdir(parents=True, exist_ok=True)
    data_dir = output_dir / "data"
    data_dir.mkdir(parents=True, exist_ok=True)
    fields = [
        "status", "algebra", "ndivs_radial", "ndivs_theta", "order", "nbases",
        "perturb_geometry", "dof", "assembly_K_seconds", "assembly_f_seconds",
        "boundary_conditions_seconds", "tocsr_seconds", "solve_seconds", "peak_rss_bytes",
        "rss_increase_bytes", "heap_peak_bytes", "heap_live_after_bytes",
        "max_relative_diff_to_sparse", "max_lame_relative_value_first",
        "max_lame_absolute_value_first", "error",
    ]
    csv_path = data_dir / "fem_twc.csv"

    with csv_path.open("w", newline="", encoding="utf-8") as stream:

        writer = csv.DictWriter(stream, fieldnames=fields, extrasaction="ignore")
        writer.writeheader()
        writer.writerows(records)

    # end with

    figure_script = output_dir / "make_figures.py"
    figure_script.write_text(
        "\n".join((
            '"""',
            "Regenerate the benchmark figures from data/fem_twc.csv.",
            '"""',
            "",
            "from pathlib import Path",
            "import sys",
            "",
            "REPORT_DIR = Path(__file__).resolve().parent",
            "REPOSITORY_ROOT = REPORT_DIR.parents[1]",
            "sys.path.insert(0, str(REPOSITORY_ROOT))",
            "",
            "from tools.bench_fem_twc import _plot_results, _read_records",
            "",
            "_plot_results(",
            "    _read_records(REPORT_DIR / 'data' / 'fem_twc.csv'),",
            "    REPORT_DIR,",
            ")",
            "",
        )),
        encoding="utf-8",
    )
    figures = _plot_results(records, output_dir)
    completed = sum(row["status"] == "ok" for row in records)
    skipped = sum(row["status"] == "skipped" for row in records)
    failed = sum(row["status"] == "error" for row in records)
    lame_errors = [
        row["max_lame_relative_value_first"]
        for row in records
        if row.get("max_lame_relative_value_first") is not None
    ]
    run_algebras = [algebra for algebra in ALGEBRAS if algebra in algebras]
    difference_lines = []
    skip_lines = []

    for algebra in NON_SPARSE:

        if algebra not in run_algebras:

            continue

        # end if

        differences = [
            row["max_relative_diff_to_sparse"]
            for row in records
            if row["algebra"] == algebra and row.get("max_relative_diff_to_sparse") is not None
        ]
        difference_lines.append(
            f"Maximum {LABELS[algebra]} relative difference to sparse: {max(differences):.6e}."
            if differences else
            f"Maximum {LABELS[algebra]} relative difference to sparse: not measured."
        )
        reasons = sorted({
            row["error"] for row in records
            if row["algebra"] == algebra and row["status"] == "skipped"
        })

        for reason in reasons:

            skip_lines.append(f"- {LABELS[algebra]} skipped: {reason}")

        # end for

    # end for

    lines = [
        "# TWC FEM benchmark",
        "",
        f"Generated: {datetime.date.today().isoformat()}",
        f"Python: `{sys.version.split()[0]}` on `{platform.platform()}`",
        f"Grid: {'quick validation' if quick else 'full Phase 7 grid'}",
        "Algebras: " + ", ".join(f"`{algebra}`" for algebra in run_algebras) + ".",
        f"Cases: {completed} completed, {skipped} skipped, {failed} failed.",
        f"Memtrack: {tracker_note or 'enabled'}.",
        "",
        "Each algebra/configuration was run in a fresh Python process. Timings are the five stages",
        "returned by `examples/python/fem_twc.py`. RSS is peak resident memory in bytes.",
        "Heap peaks are additional live malloc-family bytes after the post-import baseline;",
        "allocator mmap buffers (such as BLAS workspaces) are not included.",
        "",
        "Every non-sparse solution (semi-sparse, dense) is compared with an independent sparse run for",
        "every derivative; the sparse rows are the oracle.",
        "Relative L2 norms use a machine-precision-scaled floor for zero sparse directions.",
        "Lamé error reports the maximum nonzero-reference relative L2 error over value and first",
        "derivatives only.",
        "",
        *difference_lines,
        f"Maximum value/first Lamé relative L2 error: {max(lame_errors):.6e}."
        if lame_errors else
        "Maximum value/first Lamé relative L2 error: not measured.",
        *([""] + skip_lines if skip_lines else []),
        "",
        "## Files",
        "",
        "- `data/fem_twc.csv`: one row per selected algebra/configuration.",
        "- `make_figures.py`: regenerate the plots from the CSV.",
    ]

    for figure in figures:

        lines.append(f"- `{figure}`: benchmark plot.")

    # end for

    if not figures:

        lines.append("No figures were generated (matplotlib is unavailable or no cases completed).")

    # end if

    lines.extend((
        "",
        "## CSV columns",
        "",
        "- `status` and `error`: `ok`, `skipped`, or `error`, plus the failure/skip reason.",
        "- `algebra`, divisions, `order`, `nbases`, `perturb_geometry`, `dof`: case config and",
        "  actual number of degrees of freedom.",
        "- `assembly_K_seconds`, `assembly_f_seconds`, `boundary_conditions_seconds`, `tocsr_seconds`,",
        "  `solve_seconds`: separately measured stages from the TWC model.",
        "- `peak_rss_bytes`, `rss_increase_bytes`: process high-water RSS and increase from the",
        "  post-import baseline. `heap_peak_bytes` and `heap_live_after_bytes` are memtrack deltas.",
        "- `max_relative_diff_to_sparse`: maximum relative L2 difference over real and all derivative",
        "  solution arrays; blank for sparse rows or unavailable comparisons (one value per",
        "  non-sparse algebra row).",
        "- `max_lame_relative_value_first`, `max_lame_absolute_value_first`: Lamé maxima over value",
        "  and all first derivatives.",
        "",
        "A missing heap tracker leaves heap columns blank while retaining RSS measurements.",
        "",
        "## Reproduce",
        "",
        "```bash",
        "python tools/bench_fem_twc.py --build build",
        "```",
        "",
        "Use `--quick` for meshes 5 and 10, order 2, and four bases. `--algebras sparse dense` runs a",
        "subset (default: sparse semisparse dense; sparse is always run as the oracle when another",
        "algebra is selected). `--cases` accepts quoted glob patterns such as `sparse-n5-*` or",
        "`dense-n10-o2-b4`. `--timeout` applies per worker. Use `--no-memtrack` to force RSS-only",
        "reporting. Semi-sparse and dense cases are recorded as skipped when required APIs or the FEM",
        "algebra probe are not available.",
        "",
    ))
    (output_dir / "README.md").write_text("\n".join(lines), encoding="utf-8")

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def _run_benchmark(args) -> int:
    """
    Execute selected benchmark cases and save the report folder.

    Parameters
    ----------
    args : argparse.Namespace
        Parsed CLI options.

    Returns
    -------
    int
        Zero if at least one case completed, or one when all selected cases failed.

    Examples
    --------
    >>> callable(_run_benchmark)
    True
    """

    build_dir = args.build.resolve()

    if not (build_dir / "pyoti").is_dir():

        raise FileNotFoundError(f"Compiled package directory not found under {build_dir}")

    # end if

    algebras = tuple(algebra for algebra in ALGEBRAS if algebra in args.algebras)

    try:

        selected = _selected_case_ids(args.quick, args.cases, algebras)

    except ValueError as exc:

        raise ValueError(str(exc)) from exc

    # end try

    output_dir = args.out.resolve()
    records = []
    skip_reasons = {}

    with tempfile.TemporaryDirectory(prefix="fem-twc-benchmark-") as temporary_dir:

        temporary_path = Path(temporary_dir)
        tracker_path, tracker_note = _compile_tracker(temporary_path, args.no_memtrack)

        for case_index, config in enumerate(_case_grid(args.quick)):

            ndivs, order, nbases = config
            wanted = {
                algebra: f"{algebra}-n{ndivs}-o{order}-b{nbases}" in selected
                for algebra in algebras
            }
            others = [algebra for algebra in NON_SPARSE if wanted.get(algebra)]

            if not any(wanted.values()):

                continue

            # end if

            # A non-sparse algebra whose preflight failed once is skipped without running anything.
            for algebra in [name for name in others if name in skip_reasons]:

                records.append(_record(
                    config, algebra, {"error": skip_reasons[algebra]}, "skipped"
                ))

            # end for

            others = [algebra for algebra in others if algebra not in skip_reasons]

            if not wanted.get("sparse") and not others:

                continue

            # end if

            reference_path = temporary_path / f"sparse-{case_index}.npz"
            sparse_result = _worker_command(
                "sparse",
                ndivs,
                order,
                nbases,
                build_dir,
                tracker_path,
                None,
                reference_path if others else None,
                args.timeout,
            )

            if wanted.get("sparse"):

                status = "ok" if sparse_result.get("status") == "ok" else "error"
                records.append(_record(config, "sparse", sparse_result, status))

            # end if

            for algebra in others:

                if sparse_result.get("status") != "ok":

                    reason = "sparse oracle case failed: " + sparse_result.get(
                        "error", "unknown error"
                    )
                    records.append(_record(config, algebra, {"error": reason}, "error"))
                    continue

                # end if

                result = _worker_command(
                    algebra,
                    ndivs,
                    order,
                    nbases,
                    build_dir,
                    tracker_path,
                    reference_path,
                    None,
                    args.timeout,
                )

                if result.get("status") == "skipped":

                    skip_reasons[algebra] = result.get("error", f"{algebra} TWC APIs unavailable")
                    records.append(_record(config, algebra, result, "skipped"))

                elif result.get("status") == "ok":

                    records.append(_record(config, algebra, result))

                else:

                    records.append(_record(config, algebra, result, "error"))

                # end if

            # end for

        # end for

        _write_report(records, output_dir, args.quick, tracker_note, algebras)

    # end with

    completed = sum(row["status"] == "ok" for row in records)
    skipped = sum(row["status"] == "skipped" for row in records)
    failed = sum(row["status"] == "error" for row in records)
    print(f"Wrote {output_dir}: {completed} completed, {skipped} skipped, {failed} failed.")

    return 0 if completed else 1

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def main(argv=None) -> int:
    """
    Run the CLI benchmark grid or one internal worker.

    Parameters
    ----------
    argv : list[str] or None, optional
        Command-line arguments, or `None` to use process arguments.

    Returns
    -------
    int
        Process exit code.

    Examples
    --------
    >>> callable(main)
    True
    """

    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--build", "--build-dir", dest="build", type=Path, default=Path("build"))
    parser.add_argument(
        "--out",
        "--output",
        dest="out",
        type=Path,
        default=Path("reports") / f"{datetime.date.today():%Y-%m-%d}-fem-twc-benchmark",
    )
    parser.add_argument("--quick", action="store_true")
    parser.add_argument("--cases", nargs="+", help="glob filters over case IDs")
    parser.add_argument(
        "--algebras",
        nargs="+",
        choices=ALGEBRAS,
        default=list(ALGEBRAS),
        help="algebras to run (default: all three); sparse is also run as the oracle",
    )
    parser.add_argument("--timeout", type=int, default=3600, help="timeout per child case in seconds")
    parser.add_argument("--no-memtrack", action="store_true")
    parser.add_argument("--worker", action="store_true", help=argparse.SUPPRESS)
    parser.add_argument("--algebra", choices=ALGEBRAS, help=argparse.SUPPRESS)
    parser.add_argument("--ndivs", type=int, help=argparse.SUPPRESS)
    parser.add_argument("--order", type=int, help=argparse.SUPPRESS)
    parser.add_argument("--perturb-geometry", choices=("True", "False"), help=argparse.SUPPRESS)
    parser.add_argument("--tracker", help=argparse.SUPPRESS)
    parser.add_argument("--reference", help=argparse.SUPPRESS)
    parser.add_argument("--solution", help=argparse.SUPPRESS)
    args = parser.parse_args(argv)

    if args.worker:

        if args.algebra is None or args.ndivs is None or args.order is None:

            parser.error("worker mode requires algebra, ndivs, and order")

        # end if

        args.perturb_geometry = args.perturb_geometry == "True"

        return _worker(args)

    # end if

    if args.timeout <= 0:

        parser.error("--timeout must be positive")

    # end if

    try:

        return _run_benchmark(args)

    except (FileNotFoundError, ValueError) as exc:

        parser.error(str(exc))

    # end try

    return 2

# end function
# --------------------------------------------------------------------------------------------------------


if __name__ == "__main__":

    raise SystemExit(main())

# end if
