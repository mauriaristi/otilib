#!/usr/bin/env python3
"""
Regenerate the checked-in static OTI library without writing to its source files.

Activate the pyoti conda environment and build pyoti first. Examples::

    python tools/regen_static.py --build-dir build --output build-orch/static-regen/output
    python tools/regen_static.py --build-dir build --check

The output directory must be empty. Check mode uses a temporary directory and compares
bytes, including missing and unexpected files; it never copies the checked-in output.
Generator modules and templates are loaded from this checkout, not the built package.
"""
import argparse
from collections import Counter
import contextlib
import difflib
import importlib.util
import io
from pathlib import Path
import sys
import tempfile
import time

sys.dont_write_bytecode = True
ROOT = Path(__file__).resolve().parents[1]
COMBINATIONS = (
    tuple((1, order) for order in (1, 2, 3, 4, 10, 20, 30))
    + tuple((nbases, order) for nbases in (2, 3) for order in (1, 2, 3, 4))
    + ((10, 1), (10, 2))
)
FORTRAN_COMBINATIONS = tuple(
    (nbases, order) for nbases in (1, 2, 3) for order in (1, 2, 3, 4)
) + ((1, 10),)
OUTPUT_ROOTS = (
    'src/c/static', 'include/oti/static', 'include/pyoti/static',
    'include/pyoti/c_otilib/static', 'src/python/pyoti/cython/static',
)
AGGREGATES = ('src/c/static.c', 'include/oti/static.h', 'include/pyoti/c_otilib/static.pxi')


# ********************************************************************************************************
def load_generator(name, path):
    """
    Load a generator directly from the source checkout.

    Parameters
    ----------
    name : str
        Private module name.
    path : pathlib.Path
        Generator source file.

    Returns
    -------
    module
        Loaded generator.
    """
    spec = importlib.util.spec_from_file_location(name, path)
    module = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(module)
    return module

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def regenerate(output, build_dir):
    """
    Run all three generators using an existing compiled pyoti package.

    Parameters
    ----------
    output : pathlib.Path
        Empty destination directory.
    build_dir : pathlib.Path
        Build directory containing pyoti/core*.so.
    """

    if output == ROOT or output in ROOT.parents or (output.exists() and any(output.iterdir())):

        raise ValueError(f'Output must be an empty scratch directory: {output}')

    # end if

    sys.path.insert(0, str(build_dir))
    import pyoti.core as core

    if not Path(core.__file__).resolve().is_relative_to(build_dir):

        raise ValueError(f'pyoti.core loaded from {core.__file__}, outside requested build {build_dir}')

    # end if

    print(f'Bootstrap: {core.__file__}')
    sources = ROOT / 'src/python/pyoti/python'
    cmod = load_generator('_regen_cmod', sources / 'cmod_writer.py')
    fmod = load_generator('_regen_fmod', sources / 'fmod_writer.py')
    cwrap = load_generator('_regen_cwrap', ROOT / 'src/fortran/static/file_writer.py')
    output.mkdir(parents=True, exist_ok=True)
    # Keep the generator's per-template chatter out of the check summary.
    log = io.StringIO()

    with contextlib.redirect_stdout(log):

        for nbases, order in COMBINATIONS:

            cmod.writer(nbases, order, source_dir=sources / 'source_conv', checked_in=True).write_files(
                base_dir=str(output), tab='  '
            )

        # end for

        fortran_dir = output / 'src/fortran/static'
        fortran_dir.mkdir(parents=True, exist_ok=True)

        for nbases, order in FORTRAN_COMBINATIONS:

            fmod.writer(nbases, order).write_file(
                filename=str(fortran_dir / f'otim{nbases}n{order}.f90'), tab='   ',
                is_std_matmul=True, elemental_feval=True, real_utils=True,
            )

        # end for

        cwrap.write_files(fortran_dir)

    # end with

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def inventory(tree):
    """
    Inventory generated families, including files unexpected by the generators.

    Parameters
    ----------
    tree : pathlib.Path
        Reference or generated tree.

    Returns
    -------
    set of pathlib.Path
        Paths relative to the tree.
    """
    paths = set()

    for relative in OUTPUT_ROOTS:

        suffixes = ('.c',) if relative.startswith('src/c/') else (
            ('.h',) if relative.startswith('include/oti/') else ('.pxi', '.pxd', '.pyx')
        )

        for path in (tree / relative).rglob('*'):

            if path.is_file() and path.suffix in suffixes:

                paths.add(path.relative_to(tree))

            # end if

        # end for

    # end for

    for pattern in ('otim*.f90', 'cwrapm*.f90'):

        paths.update(path.relative_to(tree) for path in (tree / 'src/fortran/static').glob(pattern))

    # end for

    paths.update(Path(relative) for relative in AGGREGATES if (tree / relative).is_file())
    return paths

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def compare(output, reference, diff_file=None):
    """
    Compare every generated file byte for byte and report all missing or extra files.

    Parameters
    ----------
    output, reference : pathlib.Path
        Generated and reference trees.
    diff_file : pathlib.Path, optional
        Destination for a unified diff of all mismatches.

    Returns
    -------
    int
        Zero on equality, one on any mismatch.
    """
    counts = Counter()
    differences = []
    changed = 0

    for relative in sorted(inventory(output) | inventory(reference)):

        generated, existing = output / relative, reference / relative
        actual = generated.read_bytes() if generated.is_file() else None
        expected = existing.read_bytes() if existing.is_file() else None
        family = {'.c': 'C', '.h': 'headers', '.f90': 'Fortran'}.get(relative.suffix, 'Cython')

        if actual == expected:

            counts[family, 'equal'] += 1
            continue

        # end if

        changed += 1
        status = 'missing' if actual is None else 'extra' if expected is None else 'different'
        counts[family, status] += 1
        print(f'{status}: {relative}')

        if diff_file is not None:

            differences.extend(difflib.unified_diff(
                (expected or b'').decode().splitlines(keepends=True),
                (actual or b'').decode().splitlines(keepends=True),
                fromfile=f'checked-in/{relative}', tofile=f'generated/{relative}',
            ))

        # end if

    # end for

    for (family, status), count in sorted(counts.items()):

        print(f'{family}: {count} {status}')

    # end for

    if diff_file is not None:

        diff_file.write_text(''.join(differences))

    # end if

    message = (
        f'{changed} differing files' if changed else 'No diff: all generated files match byte for byte.'
    )
    print(message)
    return int(changed != 0)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def main():
    """
    Parse arguments, regenerate, and optionally check against a reference tree.

    Returns
    -------
    int
        Process exit status.
    """
    parser = argparse.ArgumentParser(
        description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter,
    )
    mode = parser.add_mutually_exclusive_group(required=True)
    mode.add_argument('--output', type=Path, help='Empty destination directory')
    mode.add_argument('--check', action='store_true', help='Regenerate temporarily and compare bytes')
    parser.add_argument('--build-dir', type=Path, default=ROOT / 'build')
    parser.add_argument('--reference', type=Path, default=ROOT,
                        help='Reference tree (default: this checkout)')
    parser.add_argument('--scratch-dir', type=Path, default=ROOT / 'build-orch/static-regen')
    parser.add_argument('--diff-file', type=Path, help='Write the complete unified diff in check mode')
    args = parser.parse_args()

    if args.diff_file and not args.check:

        parser.error('--diff-file requires --check')

    # end if

    start = time.monotonic()

    try:

        if args.check:

            args.scratch_dir.mkdir(parents=True, exist_ok=True)

            with tempfile.TemporaryDirectory(prefix='check-', dir=args.scratch_dir) as temporary:

                output = Path(temporary).resolve()
                regenerate(output, args.build_dir.resolve())
                generation_seconds = time.monotonic() - start
                status = compare(output, args.reference.resolve(), args.diff_file)

            # end with

        else:

            regenerate(args.output.resolve(), args.build_dir.resolve())
            generation_seconds = time.monotonic() - start
            print(f'Generated {len(inventory(args.output))} files in {args.output}')
            status = 0

        # end if

    except (OSError, ImportError, ValueError) as error:

        print(f'Regeneration failed: {error}', file=sys.stderr)
        return 2

    # end try

    print(f'Regeneration: {generation_seconds:.3f}s; total: {time.monotonic() - start:.3f}s')
    return status

# end function
# --------------------------------------------------------------------------------------------------------


if __name__ == '__main__':

    sys.exit(main())

# end if
