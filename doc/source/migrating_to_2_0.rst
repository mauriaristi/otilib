Migrating to OTIlib 2.0
=======================

OTIlib 2.0 moves the array types of ``pyoti.dense``, ``pyoti.semisparse``, ``pyoti.sparse`` and
``pyoti.real.dmat`` onto NumPy's indexing, creator and assignment rules. Scalars, the OTI algebra and
the numerical results do not change. Code that breaks does so loudly (an ``IndexError``, ``ValueError``
or ``BufferError``), not by returning different numbers, with one exception: the view-versus-copy
behaviour of slices (item 4 below).

.. contents::
   :local:
   :depth: 1

.. The examples below were written from the 2.0 compatibility specification and run against the 2.0
   builds of pyoti.dense, pyoti.sparse, pyoti.semisparse and pyoti.real (2026-11-02/03).


Who is affected
---------------

You need to read this page if your code:

* uses ``A[i]`` or ``A[i, :]`` expecting a ``(1, n)`` row matrix;
* creates a vector with ``zeros(n)`` or ``array(list)`` and then indexes it as ``x[i, 0]``;
* writes into ``.real``, ``get_block(...)`` or ``csr_matrix.real.data``;
* modifies a slice expecting the parent to stay unchanged (or to change);
* assigns an ``(n, 1)`` column into a 1-D slice;
* exchanges saved files with OTIlib 1.x;
* relies on ``nbases=`` having no effect on dense arrays.

Pure scalar code (``e``, ``number``, arithmetic, functions) is not affected.


Recipes, one per breaking change
--------------------------------

1. NumPy indexing
~~~~~~~~~~~~~~~~~

An integer index drops its axis, a slice keeps it, ``None`` / ``...`` work, and negative indices count
from the end in every algebra. All integers give an OTI scalar. ``len(A)`` is ``A.shape[0]`` and
iteration yields ``A[0], A[1], ...``.

.. code-block:: python

   # before (1.x)                       # after (2.0)
   A[1]        # (1, 4)                 A[1]        # (4,)
   A[1, :]     # (1, 4)                 A[1, :]     # (4,)
   A[:, 2]     # (3, 1)                 A[:, 2]     # (3,)
   A[1:2, :]   # (1, 4)                 A[1:2, :]   # (1, 4)   unchanged
   A[:, 2:3]   # (3, 1)                 A[:, 2:3]   # (3, 1)   unchanged
   A[-1, -1]   # sparse: OverflowError  A[-1, -1]   # scalar in every algebra

To keep a row or a column, use a slice of length one (``A[1:2, :]``, ``A[:, 2:3]``). The Gauss types
(``omatfe``, ``oarrssfe``, ``matsofe``) keep the 1.x matrix rule: ``G[i]`` is still a ``(1, ncols)``
Gauss matrix and point access is ``get_ip`` / ``set_ip``. ``dmat`` follows the same rules as the OTI
arrays.

2. Creators return NumPy shapes
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. code-block:: python

   import numpy as np
   import pyoti.dense as oti

   # before (1.x)                           # after (2.0)
   x = oti.array(np.arange(1.0, 5.0))       x = oti.array(np.arange(1.0, 5.0))
   x.shape       # (4, 1)                   x.shape       # (4,)
   x[2, 0]       # otinum                   x[2]          # otinum;  x[2, 0] raises IndexError
   f = oti.zeros(n)                         f = oti.zeros((n, 1))    # keep a column explicitly
   oti.array(2.5).shape   # (1, 1)          oti.array(2.5).shape     # ()  (0-D)

``zeros((2, 3))``, ``eye(3)`` and ``array([[a], [b]])`` are unchanged. ``nrows`` and ``ncols`` keep
their 1.x values for arrays of at most two dimensions (a 1-D array has ``ncols == 1``), are deprecated,
and raise ``AttributeError`` for more dimensions: use ``shape``.

3. Assignment broadcasts as NumPy does
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

The value is broadcast to the shape of the target. A ``(1, n)`` row fits an ``(n,)`` target; an
``(n, 1)`` column does not. ``A.set(rhs)`` is ``A[...] = rhs`` and broadcasts the same way (1.x raised
on a shape mismatch).

.. code-block:: python

   # before (1.x)                           # after (2.0)
   A[:, 3] = column      # column (3, 1)    A[:, 3] = column         # ValueError
                                            A[:, 3:4] = column       # OK
                                            A[:, 3] = column[:, 0]   # OK

Assigning rows (the finite-element assembly pattern ``strain[0, 0:2*nb:2] = nx`` with ``nx`` of shape
``(1, nb)``) is unchanged. ``A[1:] = A[:-1]`` and ``A[::-1] = A`` behave as if the value were copied
first, as in NumPy.

4. Views
~~~~~~~~

In ``pyoti.dense``, basic slices, ``.T`` and ``reshape`` of an ``omat`` are **views**: writes through
them reach the parent (``reshape`` is a view when the memory layout allows it, otherwise a copy; for
example the reshape of a default ``'F'`` array is a copy, that of a ``layout='C'`` array a view).
``pyoti.real.dmat`` slices are views too. In ``pyoti.sparse``, ``pyoti.semisparse`` and for AoS
arrays and Gauss types they are copies. Because the answer depends on the algebra, write code that
works with both:

.. code-block:: python

   # before (1.x, dense)                    # after (2.0, dense omat)
   row = A[0]       # (1, n), a copy        row = A[0]           # (n,), a view
   row[0, 0] = 42.0 # A unchanged           row[0] = 42.0        # A[0, 0] is now 42.0

   # portable in both versions and every algebra
   row = A[0].copy()      # independent
   A[0, :] = new_row      # one subscript: writes into A

A chained assignment such as ``A[1:3][0] = v`` writes into ``A`` only when the first subscript is a view
(dense ``omat``); elsewhere it writes into a discarded copy. Use one subscript: ``A[1, :] = v``.

.. Phase 8 flag: semi-sparse ``oarrss`` slices, ``.T`` and ``reshape`` become views in the 2.0.0
   release (contracts A2); until then they are copies. Update the view paragraph above, the
   checklist and CHANGELOG "Breaking" item 4 when Phase 8 lands.

Static array classes (``omatmXnY``, ...) keep the 1.x matrix indexing and copies; they are provisional
in 2.0 and will follow ``pyoti.dense`` in a later 2.x release.

5. Read-only exports
~~~~~~~~~~~~~~~~~~~~

``.real``, ``get_block(d)``, Gauss ``.real`` and ``csr_matrix.real`` return read-only NumPy / SciPy
objects that share memory with the OTI array. Writing raises ``ValueError: ... read-only``.

.. code-block:: python

   # before (1.x)                           # after (2.0)
   r = A.real                               r = A.real             # read-only view
   r[0, 0] = 1.0                            r[0, 0] = 1.0          # ValueError: read-only
                                            r = A.real.copy()      # writable, independent
   A.get_block(1)[0, 1] = 5.0               A.get_block(1, writeable=True)[0, 1] = 5.0
   K.real.data[:] = 0.0                     K.get_real(writeable=True).data[:] = 0.0

``get_block(d, writeable=True)`` raises the array's active order to its truncation order first when
``d != 0``. For sparse OTI matrices ``get_real(writeable=True)`` returns a writable copy whose writes
do not reach ``K``; for dense and semi-sparse ones the writes reach the real block. A SciPy matrix
taken from ``K.real`` cannot be modified in place: ``K.real.data[:] = ...`` and ``eliminate_zeros()``
raise ``ValueError``, and ``sort_indices()`` / ``sum_duplicates()`` do nothing on a canonical matrix
(SciPy has nothing to change). Take ``K.real.copy()`` first if you need SciPy to modify the matrix.

Unchanged: static arrays, sparse Gauss ``.real`` (a real Gauss ``dmatfe`` object) and
``dmat.to_numpy()`` (a writable view of a real array).

6. Growth with live views or exports
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

An assignment that raises the truncation order or adds bases changes the array's layout. That is
allowed when nothing else points into the array, and raises ``BufferError`` while a view or an export
is alive (so does ``reserve``). A write that already fits the layout always works. Writing *through* a
view never changes the layout: it works when the value fits and raises ``BufferError`` otherwise; it
never clips. Semi-sparse arrays have the same guard in 2.0.

.. code-block:: python

   import pyoti.dense as dn

   A = dn.zeros((2, 2))                 # a root, truncation order 0
   A[0:2, 0:2] = dn.e(5, order=2)       # grows A: no view alive (as in 1.x)
   v = A[0]                             # a view of A
   A[1, 1] = dn.e(7, order=3)           # BufferError: A has a live view
   del v
   A[1, 1] = dn.e(7, order=3)           # grows again

Size the array up front instead, so assembly never grows:

.. code-block:: python

   A = dn.zeros((2, 2), nbases=7, order=3)   # reserved at creation
   A.reserve(nbases=10, order=4)             # or grow explicitly, while no view or export is alive

``reserve`` takes ``nbases=`` and ``order=`` in ``pyoti.dense``, and ``bases=`` and ``order=`` in
``pyoti.semisparse`` (``A.reserve(bases=[1, 2, 3], order=4)``).

The error message is "cannot grow an array with live block views or exports; size it first with
A.reserve(nbases=..., order=...) or create it with nbases= / bases= / order=".

7. ``nbases=`` reserves the layout
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. code-block:: python

   dn.zeros((2, 3), nbases=4, order=2).active_bases
   # 1.x: ()                      2.0: (1, 2, 3, 4)

``nbases=0`` (the default) reserves nothing. A hint too large for the memory budget raises
``MemoryError`` instead of allocating. Scalar creators (``e``, ``zero``, ``one``, ``number``), sparse
and static arrays and ``dmat`` are unchanged. Semi-sparse arrays reserve labels with ``bases=``; their
``nbases=`` is a capacity hint only.

8. 1-D products follow NumPy
~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. code-block:: python

   oti.dot(x, y)         # x, y 1-D: an OTI scalar (the inner product)
   oti.dot(A, x)         # (m,)
   A @ x, x @ A          # numpy.matmul promotion; x @ y is an OTI scalar
   x.T                   # a 1-D array is returned unchanged

``dot(x.T, y)`` on ``(n, 1)`` columns still works and gives ``(1, 1)``. ``dot_product`` (flattened
pairing), ``trunc_dot`` (a truncated matrix product) and ``gauss_integrate`` keep their own rules.
``solve(A, b)`` follows ``numpy.linalg.solve``; ``solve(csr, b)`` returns the shape of ``b``; ``csr @ b``
gives ``(m,)`` for ``b`` of shape ``(n,)``.

In ``pyoti.dense``, ``dot`` of operands with more than two dimensions raises ``ValueError`` (use
``matmul`` or ``@``).

Broadcasting between ``(n,)`` and ``(n, 1)`` gives ``(n, n)`` in ``pyoti.dense`` SoA arrays (``omat``),
as in NumPy; dense AoS arrays (``arro``), sparse and semi-sparse arrays only broadcast between equal
shapes, scalars and single-element arrays, and raise ``ValueError`` for anything else.

9. Saved files
~~~~~~~~~~~~~~

See `Saved files`_ below.

10. ``nrows`` / ``ncols``
~~~~~~~~~~~~~~~~~~~~~~~~~

Replace ``A.nrows`` / ``A.ncols`` with ``A.shape``. They still work for arrays of at most two
dimensions and are removed in a later release.

11. Static arrays
~~~~~~~~~~~~~~~~~

The static modules' array classes are provisional in 2.0. Static scalars are unchanged. Static modules
are not supported by ``pyoti.fem.set_global_algebra`` until they follow ``pyoti.dense``.


FEM users
---------

Code in the style of ``examples/python/fem_twc.py`` needs no change, with any of the three algebras.

* Mesh coordinates stay ``(n, 1)`` columns, so ``mesh.x[node, 0]`` keeps working.
* Functions that take nodal vectors (``set_coordinates``, ``get_local``, ...) accept ``(n,)`` and
  ``(n, 1)`` alike.
* Pass the true number of bases as ``nbases=`` and the order as ``order=`` to
  ``element.allocate(...)`` (and ``bases=`` for semi-sparse) to size every helper field once. The
  hint is no longer ignored: a generous ``nbases`` that cost nothing in 1.x now allocates every helper
  field at that size. the fields then never grow during assembly, so a view you hold (for
  example ``Nx.get_ip(ip)``) never blocks a later write. ``get_ip`` returns a copy.
* Keep force and solution vectors as ``(n, 1)`` columns, or switch to 1-D consistently; do not mix
  them in one expression with dense arrays.

.. code-block:: python

   element.allocate(intorder=1, nbases=3, order=2)   # 1.x: helper fields grew on demand
                                                     # 2.0: sized up front, never grow


Checklist for code that runs under any algebra
----------------------------------------------

Code written for ``set_global_algebra`` should work with ``pyoti.sparse``, ``pyoti.semisparse`` and
``pyoti.dense`` alike:

* one subscript per assignment (``A[i, :] = v``, not ``A[i:j][k] = v``);
* no reliance on a slice being a view or a copy; use ``.copy()`` for independence;
* equal shapes or scalars in elementwise operations (dense ``omat`` alone broadcasts fully);
* ``(n, 1)`` columns where ``fem`` expects them, created explicitly with ``zeros((n, 1))``;
* ``shape`` instead of ``nrows`` / ``ncols``;
* size arrays with ``nbases=`` / ``bases=`` / ``order=`` before taking views of them;
* ``.copy()`` of ``.real`` and ``get_block`` before modifying.


Diagnosing errors
-----------------

.. list-table::
   :header-rows: 1
   :widths: 35 65

   * - Error
     - Likely cause and fix
   * - ``IndexError`` (sparse, semi-sparse, ``dmat``: "too many indices"; dense: "index, direction or
       order out of range")
     - A 1-D array indexed as ``x[i, 0]``. Drop the ``, 0``, or create the column explicitly with
       ``zeros((n, 1))`` or ``array(v[:, None])``.
   * - ``ValueError`` (sparse, semi-sparse, ``dmat``: "could not broadcast"; dense: "incompatible shape")
     - An ``(n, 1)`` column assigned into a 1-D target. Use ``A[:, j:j+1] = column`` or
       ``A[:, j] = column[:, 0]``. Match the exception type, not the text: the messages differ by
       algebra.
   * - ``AttributeError: 'float' object has no attribute 'item'`` (or ``shape``)
     - ``x[i]`` is now an OTI scalar, so ``x[i].real`` is a float, not an array. Drop ``.item()``.
   * - ``ValueError: ... read-only``
     - A write into ``.real``, ``get_block`` or ``csr_matrix.real``. Use ``.copy()``,
       ``get_block(d, writeable=True)`` or ``get_real(writeable=True)``.
   * - ``BufferError: ... live block views``
     - A layout change while a view or export is alive. Delete the view, or size the array first
       with ``reserve(...)`` or ``nbases=`` / ``bases=`` / ``order=``.
   * - ``ValueError: broadcasting between shapes ... is supported by pyoti.dense only``
     - ``(n,)`` mixed with ``(n, 1)`` in sparse or semi-sparse. Use equal shapes or a scalar.
   * - ``ValueError: ... arrays have at most 2 dimensions``
     - ``None`` / ``...`` that adds an axis, or ``reshape`` to more than two dimensions, in sparse,
       ``dmat`` or semi-sparse.
   * - ``MemoryError`` from ``zeros(..., nbases=K)``
     - ``K`` is too large for the memory budget; pass the true number of bases.


Other behaviour changes
-----------------------

* ``bool(A)`` is ``len(A) > 0``: an empty array is ``False`` (1.x: always ``True``).
* ``pyoti.sparse``: an empty extended slice (``A[:-6:2]``, ``A[5:5:2]``) is empty; 1.x returned one row.
* ``pyoti.sparse``: ``numpy_array * matso`` raises ``TypeError`` (1.x: ``ValueError``);
  ``np.float64(2) * A`` still gives a ``matso``.
* ``pyoti.real``: ``inv``, ``det`` and ``solve`` of a non-square ``dmat`` raise ``LinAlgError`` (as
  NumPy) instead of ending the process.


Saved files
-----------

``save`` writes format version 2 in ``pyoti.dense`` (``'OTD'``), ``pyoti.sparse`` (``'OTI'``) and
``pyoti.semisparse`` (``'OTS'``). Version 2 adds the number of dimensions, the shape and the memory
layout, so 0-D and 1-D arrays round-trip.

* ``read`` accepts version 1 and version 2.
* A 1.x file gives back the 2-D shape it stored: a 1.x ``(n, 1)`` file reads as ``(n, 1)``, never as
  ``(n,)``.
* Files written by 2.0 cannot be read by 1.x. To exchange files with a 1.x installation, keep writing
  them with 1.x.
* To upgrade a file, read it with 2.0 and save it again; the original stays readable as it is.

.. code-block:: python

   A = oti.read("old_v1.otd")      # shape (n, 1) as stored by 1.x
   oti.save(A, "new_v2.otd")       # version 2; readable by 2.0 only
   A = A[:, 0]                     # (n,)  if you want a 1-D array

See also :doc:`installation` and the ``CHANGELOG.md`` file in the repository for the complete list of
changes.
