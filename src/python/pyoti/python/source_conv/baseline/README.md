# Checked-in static generation profile

`tools/regen_static.py` selects `cmod_writer.writer(..., checked_in=True)`.
The default profile remains available for generating arbitrary combinations.

These templates port the hand edits in the historical output. They are source inputs,
not copies read from the checked-in generated tree during regeneration:

- `array_functions_to.c.in`: Fortran array calls for m1-3 / n1-4; the generic
  `src/c/static/number/array/functions_to.c` remains the source for other combinations.
- `array_div_oo_to.c.in`: Fortran division for those same twelve combinations.
  Parameters preserve their different comments, prototype argument spelling, and whitespace.
- `header_order.json`: the two historical declaration orders. Explicit ordering removes
  dependence on filesystem traversal; newly added headers follow in path order.
- `aggregates/`: the small include-list templates and empty package declaration. These
  preserve historical ordering, the duplicate m10n2 header include, and terminal newlines.

The m1n1 scalar specializations and the twelve Cython `size_of_onum` helpers are emitted
by `_checked_in_template` in `cmod_writer.py`. Scalar replacement sites are checked so a
future generator change cannot silently leave the old specialization unapplied.

When changing the static generators, update the active profile templates too. A change
of the supported combinations also requires updating the aggregate lists, the driver,
and (if necessary) the declaration-order profile selection. Do not normalize historical
formatting until the checked-in generated output is deliberately regenerated in a later phase.
