"""
Generate fixed-(k, p) block kernels for the static library's SoA arrays (PLAN-ndarray.md, Phase 10).

A static array over k bases at truncation order p is a dense SoA array (``oarr_t``) with fixed
``nact = k`` and ``trc_order = p``: ``1 + sum_q N_q(k)`` blocks, block 0 the real part and direction
i of order q the block ``C(k + q - 1, q - 1) + i`` (dense colex order). For every product triple
(i, j, r) of the truncation's product table, the generated kernels run ``R_r[e] += A_i[e] * B_j[e]``
over all elements, one loop per triple. Three kernels per (k, p):

- ``oarrm{k}n{p}_kernel_mul``: ``R = A * B``;
- ``oarrm{k}n{p}_kernel_trunc_mul``: ``R = A_im * B_im``, the product of the imaginary parts (orders
  >= 1 of both operands, the static ``truncmul``); the real and order-1 blocks of ``R`` are zero;
- ``oarrm{k}n{p}_kernel_mul_acc``: ``R += A * B``, the in-place accumulate form.

Each takes block pointers, one block stride per operand (in elements, ``strides[0]`` of the 7a
``(nblocks, *S)`` descriptor) and the element count of a contiguous run: block d of A holds elements
``A[d * sa + e]`` for ``0 <= e < n``. The parallel unit is a range of elements with all of their blocks
(offset the three pointers by the first element). The terms are emitted in the order of the dense
kernel ``dnok_mul_acc`` (``src/c/dense/soa/kernels.c``: order of A, order of B, direction of A,
direction of B), one statement per term, so each result element sees the same sequence of
floating-point operations as the dense product: under the same FMA contraction setting the results
are bit-identical.

The product table is computed here from the colex rank of the merged direction tuples (the rank
fallback of the dense kernels), so the generator needs no compiled ``pyoti``. ``--verify-dhelp``
cross-checks it against the library's direction helper (``pyoti.core``) when one is importable.
The output goes to a build directory; nothing is wired into the library yet.

Examples
--------
Generate the kernels of the five harness truncations::

    python block_kernel_writer.py --output build/static_block --combos 1,1 1,10 2,4 3,3 10,2
"""
import argparse
from itertools import combinations_with_replacement
from pathlib import Path
import sys

# The 17 combinations of the checked-in static library (tools/regen_static.py).
STATIC_COMBINATIONS = (
    tuple((1, order) for order in (1, 2, 3, 4, 10, 20, 30))
    + tuple((nbases, order) for nbases in (2, 3) for order in (1, 2, 3, 4))
    + ((10, 1), (10, 2))
)
TOP = '// ' + '*' * 103 + '\n'
BOTTOM = '// ' + '-' * 103 + '\n'
KINDS = ('mul', 'trunc_mul', 'mul_acc')


# ********************************************************************************************************
def binomial(n, k):
    """
    Binomial coefficient, zero outside 0 <= k <= n.

    Parameters
    ----------
    n, k : int
        Arguments.

    Returns
    -------
    int
        C(n, k).

    Examples
    --------
    >>> binomial(5, 2), binomial(2, 5)
    (10, 0)
    """

    if k < 0 or n < 0 or k > n:

        return 0

    # end if

    result = 1

    for i in range(k):

        result = result * (n - i) // (i + 1)

    # end for

    return result

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def directions(nbases, order):
    """
    Directions of one order in colex order, as sorted tuples of zero-based bases.

    Parameters
    ----------
    nbases : int
        Number of bases k.
    order : int
        Order p (0 gives the real part, the empty tuple).

    Returns
    -------
    list of tuple
        The N_p(k) = C(k + p - 1, p) directions; position i is local and global index i.

    Examples
    --------
    >>> directions(2, 2)
    [(0, 0), (0, 1), (1, 1)]
    """
    return sorted(combinations_with_replacement(range(nbases), order), key=lambda t: t[::-1])

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def colex_rank(bases):
    """
    Index of a direction within its order: sum over t of C(v_t + t, t + 1), v sorted ascending.

    Parameters
    ----------
    bases : sequence of int
        Zero-based bases, sorted ascending.

    Returns
    -------
    int
        Colex rank (sshelp_prod_rank() in the C library).

    Examples
    --------
    >>> [colex_rank(t) for t in directions(3, 2)]
    [0, 1, 2, 3, 4, 5]
    """
    return sum(binomial(v + t, t + 1) for t, v in enumerate(bases))

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def first_block(nbases, order):
    """
    Block of the first direction of an order: the number of blocks of the lower orders.

    Parameters
    ----------
    nbases : int
        Number of bases k.
    order : int
        Order p.

    Returns
    -------
    int
        C(k + p - 1, p - 1) (0 for the real part), as oarr_block_index(k, p, 0).

    Examples
    --------
    >>> [first_block(2, p) for p in range(4)]
    [0, 1, 3, 6]
    """
    return binomial(nbases + order - 1, order - 1) if order > 0 else 0

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def product_terms(nbases, trc, alo, ahi, blo, bhi):
    """
    Product triples of an order window, in the term order of the dense kernel dnok_mul_acc.

    Parameters
    ----------
    nbases : int
        Number of bases k.
    trc : int
        Truncation order.
    alo, ahi, blo, bhi : int
        Orders of A in [alo, ahi] and of B in [blo, bhi]; only p + q <= trc is kept.

    Returns
    -------
    list of tuple
        ``(a, b, r, p, q)``: blocks of A, B and R, and the orders of A and B.

    Examples
    --------
    >>> product_terms(1, 2, 0, 2, 0, 2)[:3]
    [(0, 0, 0, 0, 0), (0, 1, 1, 0, 1), (0, 2, 2, 0, 2)]
    """
    terms = []
    p = alo

    while p <= ahi and p + blo <= trc:

        dirs_p = directions(nbases, p)
        q = blo

        while q <= bhi and p + q <= trc:

            dirs_q = directions(nbases, q)
            base_r = first_block(nbases, p + q)

            for i, ui in enumerate(dirs_p):

                for j, uj in enumerate(dirs_q):

                    r = base_r + colex_rank(sorted(ui + uj))
                    terms.append((first_block(nbases, p) + i, first_block(nbases, q) + j, r, p, q))

                # end for

            # end for

            q += 1

        # end while

        p += 1

    # end while

    return terms

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def verify_dhelp(nbases, trc):
    """
    Cross-check the closed-form product table against pyoti.core's direction helper.

    Parameters
    ----------
    nbases : int
        Number of bases k.
    trc : int
        Truncation order.

    Returns
    -------
    int
        Number of direction products checked.
    """
    from pyoti.core import get_dHelp

    helper = get_dHelp()
    checked = 0

    for p in range(1, trc + 1):

        dirs_p = directions(nbases, p)

        for q in range(1, trc - p + 1):

            dirs_q = directions(nbases, q)

            for i in range(len(dirs_p)):

                for j in range(len(dirs_q)):

                    index, order = helper.mult_dir(i, p, j, q)
                    merged = sorted(dirs_p[i] + dirs_q[j])

                    if order != p + q or index != colex_rank(merged):

                        raise ValueError(f'k={nbases}: ({i}, {p}) x ({j}, {q}) gives ({index}, '
                                         f'{order}), closed form ({colex_rank(merged)}, {p + q})')

                    # end if

                    checked += 1

                # end for

            # end for

        # end for

    # end for

    return checked

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def kernel_name(nbases, trc, kind):
    """
    C name of one generated kernel.

    Parameters
    ----------
    nbases, trc : int
        Static truncation (k, p).
    kind : str
        'mul', 'trunc_mul' or 'mul_acc'.

    Returns
    -------
    str
        ``oarrm{k}n{p}_kernel_{kind}``.

    Examples
    --------
    >>> kernel_name(2, 4, 'mul_acc')
    'oarrm2n4_kernel_mul_acc'
    """
    return f'oarrm{nbases}n{trc}_kernel_{kind}'

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def prototype(nbases, trc, kind):
    """
    C prototype of one kernel, without the terminating semicolon or brace.

    Parameters
    ----------
    nbases, trc : int
        Static truncation (k, p).
    kind : str
        'mul', 'trunc_mul' or 'mul_acc'.

    Returns
    -------
    str
        Prototype, wrapped to 106 columns.
    """
    name = kernel_name(nbases, trc, kind)
    head = f'void {name}('
    pad = ' ' * len(head)
    return (head + 'const coeff_t* restrict A, int64_t sa, const coeff_t* restrict B,\n'
            + pad + 'int64_t sb, coeff_t* restrict R, int64_t sr, int64_t n)')

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def kernel_terms(nbases, trc, kind):
    """
    Terms of one kernel and the result blocks it zero-fills.

    Parameters
    ----------
    nbases, trc : int
        Static truncation (k, p).
    kind : str
        'mul', 'trunc_mul' or 'mul_acc'.

    Returns
    -------
    tuple
        ``(terms, zeroed, assign)``: the product triples in dense order, the result blocks set to
        zero (no term reaches them), and whether the first term of each result block assigns.
    """
    nblocks = binomial(nbases + trc, trc)

    if kind == 'trunc_mul':

        terms = product_terms(nbases, trc, 1, trc, 1, trc)

    else:

        terms = product_terms(nbases, trc, 0, trc, 0, trc)

    # end if

    reached = {term[2] for term in terms}
    zeroed = [] if kind == 'mul_acc' else [r for r in range(nblocks) if r not in reached]
    return terms, zeroed, kind != 'mul_acc'

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def write_kernel(nbases, trc, kind):
    """
    C source of one kernel.

    The first term of a result block of the assigning kernels is ``R = 0.0 + A * B``: the dense
    product zero-fills its result and then accumulates, and ``0.0 + x`` (contracted or not) rounds
    exactly as that first accumulation does, signed zeros included.

    Parameters
    ----------
    nbases, trc : int
        Static truncation (k, p).
    kind : str
        'mul', 'trunc_mul' or 'mul_acc'.

    Returns
    -------
    str
        Function definition framed by the 106-column dividers.
    """
    terms, zeroed, assign = kernel_terms(nbases, trc, kind)
    used_a = sorted({term[0] for term in terms})
    used_b = sorted({term[1] for term in terms})
    used_r = sorted({term[2] for term in terms} | set(zeroed))
    out = TOP + prototype(nbases, trc, kind) + '{\n\n'
    out += '    int64_t e;\n'

    for label, base, stride, blocks in (('a', 'A', 'sa', used_a), ('b', 'B', 'sb', used_b),
                                        ('r', 'R', 'sr', used_r)):

        const = 'const ' if label != 'r' else ''

        for block in blocks:

            out += f'    {const}coeff_t* {label}{block} = {base} + {block} * {stride};\n'

        # end for

    # end for

    if not terms:

        # Only the k x 1 truncated product: every result block is zero.
        out += '\n    (void)A;\n    (void)sa;\n    (void)B;\n    (void)sb;\n'

    # end if

    if zeroed:

        out += '\n    // Result blocks no term reaches.\n'

        for block in zeroed:

            out += f'    for (e = 0; e < n; e++) {{ r{block}[e] = 0.0; }}\n'

        # end for

    # end if

    seen = set(zeroed)
    group = None

    for a, b, r, p, q in terms:

        if (p, q) != group:

            group = (p, q)
            out += f'\n    // Order {p} x order {q} -> order {p + q}.\n'

        # end if

        if assign and r not in seen:

            out += f'    for (e = 0; e < n; e++) {{ r{r}[e] = 0.0 + a{a}[e] * b{b}[e]; }}\n'

        else:

            out += f'    for (e = 0; e < n; e++) {{ r{r}[e] += a{a}[e] * b{b}[e]; }}\n'

        # end if

        seen.add(r)

    # end for

    out += '\n}\n' + BOTTOM
    return out

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def write_doc(nbases, trc, kind):
    """
    Doxygen block and prototype of one kernel for the generated header.

    Parameters
    ----------
    nbases, trc : int
        Static truncation (k, p).
    kind : str
        'mul', 'trunc_mul' or 'mul_acc'.

    Returns
    -------
    str
        Documentation followed by the declaration and the closing divider.
    """
    nblocks = binomial(nbases + trc, trc)
    terms = len(kernel_terms(nbases, trc, kind)[0])
    brief, detail = {
        'mul': ('product R = A * B.', ''),
        'trunc_mul': ('truncated product R = A_im * B_im.',
                      ' * Products of the imaginary parts only (orders >= 1 of both operands, the\n'
                      ' * static truncmul); the real and order-1 blocks of R are set to zero.\n *\n'),
        'mul_acc': ('in-place accumulate R += A * B.', ''),
    }[kind]
    out = '/**\n'
    out += f' * @brief Static block kernel, k = {nbases}, p = {trc}: {brief}\n'
    out += ' *\n' + detail
    out += f' * Operands hold {nblocks} blocks (dense colex order, block 0 the real part); block d of A\n'
    out += f' * holds elements A[d * sa + e], 0 <= e < n. Runs {terms} block products, one loop each,\n'
    out += ' * in the term order of the dense kernel (bit-identical to it under the same FMA\n'
    out += ' * contraction).\n'
    out += ' *\n'
    out += ' * @param[in]     A  First operand blocks.\n'
    out += ' * @param[in]     sa Block stride of @p A, in elements.\n'
    out += ' * @param[in]     B  Second operand blocks; may be @p A.\n'
    out += ' * @param[in]     sb Block stride of @p B, in elements.\n'
    out += ' * @param[in,out] R  Result blocks; must not overlap @p A or @p B, nor each other.\n'
    out += ' * @param[in]     sr Block stride of @p R, in elements.\n'
    out += ' * @param[in]     n  Elements per block in this run (<= 0: nothing is done).\n'
    out += ' */\n'
    out += prototype(nbases, trc, kind) + ';\n' + BOTTOM
    return out

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def write_files(output, combos, basename='oti_static_block'):
    """
    Write the header and source of the block kernels of the requested truncations.

    Parameters
    ----------
    output : pathlib.Path
        Destination directory (a build directory; created if needed).
    combos : sequence of tuple
        ``(k, p)`` pairs.
    basename : str, optional
        File name stem of the ``.h`` / ``.c`` pair.

    Returns
    -------
    tuple of pathlib.Path
        Paths of the header and the source.
    """
    output.mkdir(parents=True, exist_ok=True)
    guard = basename.upper() + '_H'
    banner = ('// Generated by src/python/pyoti/python/block_kernel_writer.py; do not edit.\n'
              '// Static block kernels (PLAN-ndarray.md Phase 10) for (k, p) in:\n')
    line = '//'

    for nbases, trc in combos:

        item = f' ({nbases}, {trc})'

        if len(line) + len(item) > 106:

            banner += line + '\n'
            line = '//'

        # end if

        line += item

    # end for

    banner += line + '\n'
    header = banner + f'#ifndef {guard}\n#define {guard}\n\n#include <stdint.h>\n\n'
    header += '#include "oti/comm.h"\n\n'
    source = banner + f'#include "{basename}.h"\n\n'

    for nbases, trc in combos:

        for kind in KINDS:

            header += write_doc(nbases, trc, kind) + '\n\n'
            source += write_kernel(nbases, trc, kind) + '\n\n'

        # end for

    # end for

    header += f'#endif // {guard}\n'
    paths = (output / f'{basename}.h', output / f'{basename}.c')
    paths[0].write_text(header)
    paths[1].write_text(source.rstrip('\n') + '\n')
    return paths

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def parse_combo(text):
    """
    Parse one ``k,p`` command-line pair.

    Parameters
    ----------
    text : str
        ``"k,p"`` with k >= 1 and p >= 1.

    Returns
    -------
    tuple of int
        ``(k, p)``.

    Examples
    --------
    >>> parse_combo('10,2')
    (10, 2)
    """
    nbases, trc = (int(value) for value in text.split(','))

    if nbases < 1 or trc < 1:

        raise argparse.ArgumentTypeError(f'need k >= 1 and p >= 1: {text}')

    # end if

    return nbases, trc

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def main(argv=None):
    """
    Command-line entry point.

    Parameters
    ----------
    argv : list of str, optional
        Arguments (default: sys.argv[1:]).

    Returns
    -------
    int
        Process exit status.
    """
    parser = argparse.ArgumentParser(description=__doc__.split('\n\n')[0].strip())
    parser.add_argument('--output', type=Path, required=True, help='Destination (build) directory')
    parser.add_argument('--combos', type=parse_combo, nargs='+', default=list(STATIC_COMBINATIONS),
                        help='k,p pairs (default: the 17 static combinations)')
    parser.add_argument('--basename', default='oti_static_block', help='File name stem')
    parser.add_argument('--verify-dhelp', action='store_true',
                        help='Cross-check the product table against an importable pyoti.core')
    args = parser.parse_args(argv)

    if args.verify_dhelp:

        for nbases, trc in args.combos:

            print(f'k={nbases} p={trc}: {verify_dhelp(nbases, trc)} products match pyoti.core')

        # end for

    # end if

    for path in write_files(args.output, args.combos, args.basename):

        print(f'Wrote {path}')

    # end for

    return 0

# end function
# --------------------------------------------------------------------------------------------------------


if __name__ == '__main__':

    sys.exit(main())

# end if
