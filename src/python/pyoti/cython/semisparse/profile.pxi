# Native profiling helpers used by tools/bench_semisparse.py.


# ********************************************************************************************************
def _profile_scalar_native(left, right, operation, mode, iterations):
    """
    Time C-level scalar kernels separately from Python arithmetic dispatch.

    Parameters
    ----------
    left : ssotinum or sotinum
        First operand.
    right : ssotinum or sotinum
        Second operand, same backend as left.
    operation : str
        Multiplication or addition.
    mode : str
        Native allocating, native reusable destination, or Cython wrapper construction.
    iterations : int
        Number of calls.

    Returns
    -------
    float
        Average seconds per iteration.
    """

    cdef ssotinum a, b
    cdef sotinum x, y
    cdef ssotinum_t native = ssoti_init()
    cdef sotinum_t sparse_native = soti_init()
    cdef object wrapped = None
    cdef int i
    cdef double started

    if iterations <= 0 or operation not in ("mul", "add"):

        raise ValueError("expected a positive count and mul or add")

    # end if

    if isinstance(left, ssotinum) and isinstance(right, ssotinum):

        a = left
        b = right
        started = _perf_counter()

        if mode == "reuse":

            for i in range(iterations):

                if operation == "mul":

                    ssoti_mul_oo_to(&a.num, &b.num, &native, _dhl)

                else:

                    ssoti_sum_oo_to(&a.num, &b.num, &native, _dhl)

                # end if

            # end for

        elif mode == "alloc":

            for i in range(iterations):

                if operation == "mul":

                    native = ssoti_mul_oo(&a.num, &b.num, _dhl)

                else:

                    native = ssoti_sum_oo(&a.num, &b.num, _dhl)

                # end if

                ssoti_free(&native)

            # end for

        elif mode == "wrap":

            for i in range(iterations):

                if operation == "mul":

                    native = ssoti_mul_oo(&a.num, &b.num, _dhl)

                else:

                    native = ssoti_sum_oo(&a.num, &b.num, _dhl)

                # end if

                wrapped = ssotinum.wrap(native)

            # end for

        else:

            raise ValueError("unknown mode")

        # end if

        started = (_perf_counter() - started) / iterations

        if mode == "reuse":

            ssoti_free(&native)

        # end if

        return started

    elif isinstance(left, sotinum) and isinstance(right, sotinum):

        x = left
        y = right
        started = _perf_counter()

        if mode not in ("alloc", "wrap"):

            raise ValueError("sparse backend supports alloc and wrap modes")

        # end if

        for i in range(iterations):

            if operation == "mul":

                sparse_native = soti_mul_oo(&x.num, &y.num, _dhl)

            else:

                sparse_native = soti_sum_oo(&x.num, &y.num, _dhl)

            # end if

            if mode == "wrap":

                wrapped = sotinum.create(&sparse_native)

            else:

                soti_free(&sparse_native)

            # end if

        # end for

        return (_perf_counter() - started) / iterations

    # end if

    raise TypeError("operands must have the same supported scalar backend")

# end function
# --------------------------------------------------------------------------------------------------------
