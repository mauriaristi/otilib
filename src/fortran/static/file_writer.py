"""
Generate the twelve C-interoperable wrappers for the native static Fortran types.
"""
import argparse
from pathlib import Path


# ********************************************************************************************************
def write_files(output_dir, template=None):
    """
    Render all supported wrappers into an explicit output directory.

    Parameters
    ----------
    output_dir : pathlib.Path or str
        Destination for cwrapmXnY.f90 files.
    template : pathlib.Path or str, optional
        Wrapper template; defaults to the template beside this script.
    """
    output_dir = Path(output_dir)
    template = Path(template) if template else Path(__file__).parent / 'templates/cwrapmtemplate.f90'
    contents = template.read_text()
    output_dir.mkdir(parents=True, exist_ok=True)

    for nbases in (1, 2, 3):

        for order in (1, 2, 3, 4):

            name = f'm{nbases}n{order}'
            # Preserve m3n4's reciprocal-product division and m1n1's original spacing.
            division = 'lhsarray*(rhsarray**-1.d0)' if (nbases, order) == (3, 4) else 'lhsarray/rhsarray'
            rendered = contents.format(
                mXnY=name, division=division,
                division_space=' ' if (nbases, order) == (3, 4) else '',
                module_spacing='\n\n' if (nbases, order) == (1, 1) else '',
            )
            (output_dir / f'cwrap{name}.f90').write_text(rendered)

        # end for

    # end for

# end function
# --------------------------------------------------------------------------------------------------------


if __name__ == '__main__':

    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--output-dir', type=Path, required=True)
    parser.add_argument('--template', type=Path)
    args = parser.parse_args()
    write_files(args.output_dir, args.template)

# end if
