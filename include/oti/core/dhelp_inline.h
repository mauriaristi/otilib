#ifndef OTI_CORE_DHELP_INLINE_H
#define OTI_CORE_DHELP_INLINE_H

/**************************************************************************************************//**
@brief Get a multiplication table, building it on first use.

The table maps (direction of order `ord_small`, direction of order `ord_res-ord_small`) to the
resulting direction of order `ord_res`. Tables start with `p_arr = NULL` (see
dhelp_init_multtabls); the first call fills the table under `#pragma omp critical(oti_multtabl)`
and publishes it only once complete, so concurrent first calls from an OpenMP parallel region are
safe. Later calls are a single acquire load.

@param ord_res: Order of the resulting directions.
@param ord_small: Order of the row directions, with 1 <= ord_small <= ord_res/2.
@param dhl: Direction helper list.
@return Pointer to the (built) table.
******************************************************************************************************/
static inline const imdir2d_t* dhelp_get_multtabl(ord_t ord_res, ord_t ord_small, dhelpl_t dhl){

    imdir2d_t* p_tabl = &dhl.p_dh[ord_res-1].p_multtabls[ord_small-1];
    imdir_t*   p_arr;

    if (__atomic_load_n(&p_tabl->p_arr, __ATOMIC_ACQUIRE) == NULL){

        #pragma omp critical(oti_multtabl)
        {
            if (__atomic_load_n(&p_tabl->p_arr, __ATOMIC_ACQUIRE) == NULL){

                // Fill into a local array; other threads only see the complete table.
                p_arr = dhelp_fill_multtabl(ord_res, ord_small-1, dhl);
                __atomic_store_n(&p_tabl->p_arr, p_arr, __ATOMIC_RELEASE);

            }
        }

    }

    return p_tabl;

}
// ----------------------------------------------------------------------------------------------------

#endif
