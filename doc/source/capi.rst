C API Reference
================

This section documents the OTIlib C API, generated directly from the Doxygen comments in
``include/oti/`` using `Breathe <https://breathe.readthedocs.io/>`_ and
`Exhale <https://exhale.readthedocs.io/>`_.

.. note::
   The ``include/oti/static/`` subdirectory is intentionally **not** documented here. It contains
   18 near-duplicate ``onummMnN`` variant headers (``onumm1n1/``, ``onumm1n2/``, ... ``onumm10n2/``),
   one per fixed ``(m, n)`` order/basis-count combination, each repeating the same array/scalar API
   for that fixed size. The top-level umbrella header, ``include/oti/static.h``, *is* documented
   below — it explains the ``onummMnN`` naming convention each excluded variant implements.

.. toctree::
   :maxdepth: 2

   capi_generated/capi_root
