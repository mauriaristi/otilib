"""
Per-call cost of pyoti.dense from Python (critic W3 finding 1): the rows the Phase 7a campaign compares
between the 1.x and the 7a builds. A standalone script, never collected by pytest and never run at
gates (runs need approval)::

    OMP_NUM_THREADS=1 PYTHONPATH=<build>/ python tools/bench/bench_7a_py.py

Prints the size of an omat object and microseconds per call of the common operations.
"""

import sys
import timeit

import numpy as np


# ********************************************************************************************************
def per_call(stmt, env, number=20000, repeat=5):
    """
    Best time of one call in microseconds.

    Parameters
    ----------
    stmt : str
        Statement to time.
    env : dict
        Its globals.
    number : int
        Calls per repetition.
    repeat : int
        Repetitions (the minimum is kept).

    Returns
    -------
    float
        Microseconds per call.
    """

    return min(timeit.repeat(stmt, globals=env, number=number, repeat=repeat)) / number * 1e6

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def make_matrix(dn, n, k, p):
    """
    A diagonally dominant n x n dense OTI matrix over k bases at order p.

    Parameters
    ----------
    dn : module
        pyoti.dense.
    n, k, p : int
        Size, bases and order.

    Returns
    -------
    omat
        The matrix.
    """

    s = dn.e(1, order=p)

    for b in range(2, k + 1):

        s = s + dn.e(b, order=p)

    # end for

    A = dn.ones((n, n)) * (1.0 + s)

    for i in range(n):

        A[i, i] = A[i, i] * (n + 1.0)

    # end for

    for _ in range(p - 1):

        A = A * (1.0 + s)

    # end for

    return A

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
def main():
    """
    Time the operations and print the table.
    """

    import pyoti.dense as dn

    rows = []
    print("omat object size (bytes):", sys.getsizeof(dn.zeros((2, 2))))

    for (n, k, p) in [(2, 2, 2), (8, 3, 2), (20, 3, 2)]:

        A = make_matrix(dn, n, k, p)
        B = A * 2.0
        x = A[0, 0]
        env = dict(dn=dn, A=A, B=B, x=x, n=n, np=np)
        r = dict(shape="%dx%d k=%d p=%d" % (n, n, k, p))
        r["zeros"] = per_call("dn.zeros((n, n))", env)
        r["add"] = per_call("A + B", env)
        r["mul"] = per_call("A * B", env)
        r["matmul"] = per_call("A @ B", env, number=5000)
        r["getitem"] = per_call("A[0, 0]", env)
        r["setitem"] = per_call("B[0, 0] = x", env)
        r["real"] = per_call("A.real", env)
        r["sin"] = per_call("dn.sin(A)", env, number=5000)
        r["inv"] = per_call("dn.inv(A)", env, number=2000)
        r["copy"] = per_call("A.copy()", env)
        rows.append(r)

    # end for

    try:

        G = dn.zeros((3, 8), nip=4)
        G = G + (dn.e(1, order=2) + dn.e(2, order=2))
        H = G * 2.0
        env = dict(dn=dn, G=G, H=H)
        r = dict(shape="gauss 3x8 nip=4 k=2 p=2")
        r["add"] = per_call("G + H", env)
        r["mul"] = per_call("G * H", env)
        r["get_ip"] = per_call("G.get_ip(1)", env)
        r["real"] = per_call("G.real", env)
        rows.append(r)

    except Exception as e:

        rows.append(dict(shape="gauss failed: %r" % e))

    # end try

    keys = ["zeros", "add", "mul", "matmul", "getitem", "setitem", "real", "sin", "inv", "copy", "get_ip"]
    print("%-26s " % "us per call" + " ".join("%8s" % key for key in keys))

    for r in rows:

        print("%-26s " % r["shape"] + " ".join(("%8.2f" % r[key]) if key in r else "%8s" % "-"
                                                for key in keys))

    # end for

# end function
# --------------------------------------------------------------------------------------------------------


if __name__ == "__main__":

    main()

# end if
