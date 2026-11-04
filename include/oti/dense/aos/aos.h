#ifndef OTI_DENSE_AOS_H
#define OTI_DENSE_AOS_H

// Dense AoS arrays (arro_t): every element is an otinum_t with its own nact and orders, like
// arrso_t. Elements are row-major (element (i, j) at arro_data(arr)[j + i*ncols]). Elementwise
// operations run the scalar kernels over the elements in fixed chunks through oti_parallel_for()
// (per-worker workspaces, oti_ws()); linear algebra goes through the SoA layout (arro_to_oarr()).
// Conventions in include/oti/dense/scalar/base.h; `_to` variants: @p res may alias any input, and a
// scalar operand @p num may be an element of @p res or @p arr1 (it is copied first). Shape mismatches
// return DN_ERR_SIZE.

/// Elements of one element struct in reals: the element stride of the descriptor (3).
#define ARRO_W ((int64_t)(sizeof(otinum_t) / sizeof(coeff_t)))

// The descriptor of an arro_t addresses the `re` field of every element as an OTI_F64 element
// (request dense-1, proposal A): `re` must open the struct and the struct must be a whole number of
// reals.
OTI_ND_STATIC_ASSERT(offsetof(otinum_t, re) == 0, "otinum_t.re must be the first field (arro_t)");
OTI_ND_STATIC_ASSERT(sizeof(otinum_t) % sizeof(coeff_t) == 0,
                     "sizeof(otinum_t) must be a multiple of 8 (arro_t element stride)");

/**
 * @brief Dense OTI array, array of structures, on ndarr_t (PLAN-ndarray.md "SoA arrays are one
 * (ndim + 1)-D ndarray": AoS arrays are strided grids of element structs; request dense-1, A).
 *
 * @p elems is an OTI_F64 descriptor over the `re` fields of the element structs: shape (nrows, ncols),
 * strides (ncols * ARRO_W, ARRO_W) in reals (row-major elements, compact in 7a), data = &element(0,
 * 0).re, which is the element itself (`re` is its first field). It is the real-part view of the array:
 * an nd_* function on it only ever reads or writes `re` slots. Element (i, j) is
 * `(otinum_t*)(nd_f64(&elems) + i * strides[0] + j * strides[1])`, `arro_data(arr)[j + i * ncols]` for
 * the compact layout.
 *
 * Ownership: an owning array holds one reference on its buffer (elems retained); the buffer wraps the
 * element store (nd_wrap(), neither OWNS nor GROWABLE) and its release callback oti_free()s every
 * element, then the store. arro_init() and an empty (0-element) array hold no buffer. Copying an
 * owning arro_t by struct assignment and keeping both copies is a double release: move it.
 */
typedef struct {
    ndarr_t elems; ///< OTI_F64 of the element shape S over the `re` fields, compact row-major (strides in
                   ///< units of ARRO_W; 2-D: (ncols * ARRO_W, ARRO_W)).
} arro_t;          ///< Dense AoS OTI array type.

// -------------------------------------------------------------------------------------------------------


/**
 * @name Dense AoS accessors
 * Valid on owning arrays and arro_init() (a 0 x 0 array).
 * @{
 */

/**
 * @brief Elements of an array, row-major (the compact 7a layout).
 *
 * @param[in] a Array.
 *
 * @return The first element (NULL without elements). Not owned by the caller.
 */
static inline otinum_t* arro_data(const arro_t* a){
    return (otinum_t*)a->elems.data;
}

/**
 * @brief The element descriptor over the `re` fields (for bindings that cannot name the field). It is
 *        only ever exported read-only (the `.real` view) and never an operand of an nd_* kernel.
 *
 * @param[in] a Array.
 *
 * @return &a->elems.
 */
static inline ndarr_t* arro_elems(arro_t* a){
    return &a->elems;
}

/**
 * @brief Number of axes of the element shape S (Phase 7b: any rank 0 .. OTI_ND_MAXDIM - 1).
 *
 * @param[in] a Array.
 *
 * @return elems.ndim.
 */
static inline int32_t arro_ndim(const arro_t* a){
    return a->elems.ndim;
}

/**
 * @brief Extent of axis d of S.
 *
 * @param[in] a Array.
 * @param[in] d Axis, 0 <= d < arro_ndim(a).
 *
 * @return elems.shape[d].
 */
static inline int64_t arro_shape(const arro_t* a, int32_t d){
    return a->elems.shape[d];
}

/**
 * @brief Rows of the row-major matricization of S: S[0] (1 for a rank-0 S).
 *
 * @param[in] a Array.
 *
 * @return nrows; element (i, j) of the matricization is arro_data(a)[j + i * ncols].
 */
static inline uint64_t arro_nrows(const arro_t* a){
    return (a->elems.ndim >= 1) ? (uint64_t)a->elems.shape[0] : 1;
}

/**
 * @brief Columns of the row-major matricization of S: the product of S[1..] (1 for rank 0 or 1).
 *
 * @param[in] a Array.
 *
 * @return ncols.
 */
static inline uint64_t arro_ncols(const arro_t* a){
    uint64_t n = 1;
    int32_t d;
    for (d = 1; d < a->elems.ndim; d++){
        n *= (uint64_t)a->elems.shape[d];
    }
    return n;
}

/**
 * @brief Number of elements.
 *
 * @param[in] a Array.
 *
 * @return nrows * ncols.
 */
static inline uint64_t arro_size(const arro_t* a){
    return arro_nrows(a) * arro_ncols(a);
}

/** @} */
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Gives an array another element shape of the same size (a relabel: the row-major order of the
 *        elements is kept, nothing moves).
 *
 * @param[in]     ndim  New rank, 0 .. OTI_ND_MAXDIM - 1.
 * @param[in]     shape New extents.
 * @param[in,out] arr   Array.
 *
 * @return DN_OK; DN_ERR_SIZE (another size, or a bad rank or extent).
 */
int arro_reshape(int32_t ndim, const int64_t* shape, arro_t* arr);
// -------------------------------------------------------------------------------------------------------

/**
 * @brief Makes an array of any element shape of real zeros (nact = 0): arro_zeros_to() of the
 *        matricized shape, then arro_reshape().
 *
 * @param[in]     ndim      Rank.
 * @param[in]     shape     Extents.
 * @param[in]     trc_order Truncation order of every element.
 * @param[in,out] res       Array.
 *
 * @return As arro_zeros_to(); DN_ERR_SIZE for a bad rank or extent.
 */
int arro_zeros_nd_to(int32_t ndim, const int64_t* shape, ord_t trc_order, arro_t* res);
// -------------------------------------------------------------------------------------------------------

/**
 * @brief Empty 0 x 0 array.
 *
 * @return Array with no elements. arro_free() on it is a no-op.
 */
arro_t arro_init(void);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Makes an array an nrows x ncols array of real zeros (nact = 0).
 *
 * @param[in]     nrows     Number of rows.
 * @param[in]     ncols     Number of columns.
 * @param[in]     trc_order Truncation order of every element.
 * @param[in,out] res       Array.
 *
 * @return DN_OK, or DN_ERR_MEMORY.
 */
int arro_zeros_to(uint64_t nrows, uint64_t ncols, ord_t trc_order, arro_t* res);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Gives an array a new shape, keeping the first min(size, new size) elements.
 *
 * Elements are stored row-major like arrso_t: element (i, j) is arro_data(arr)[j + i*ncols]. A new
 * size moves the kept element structs into a new element store (on a failure the array is unchanged).
 * A shape change is refused while the store is shared (another reference or a live export of the
 * buffer, compatibility rule G1); the same shape is always accepted (no change). The functions that
 * build their result apart (matmul, transpose) apply the same rule to @p res.
 *
 * @param[in]     nrows     Number of rows.
 * @param[in]     ncols     Number of columns.
 * @param[in]     trc_order Truncation order of added elements (real zeros).
 * @param[in,out] arr       Array.
 *
 * @return DN_OK; DN_ERR_MEMORY (allocation, or a shape not representable in the descriptor: an extent
 *         above INT64_MAX / sizeof(otinum_t), or more elements than that; also for an empty shape);
 *         DN_ERR_INDEX;
 *         OTI_ERR_BUSY (shared store). On a failure the array is unchanged.
 */
int arro_resize(uint64_t nrows, uint64_t ncols, ord_t trc_order, arro_t* arr);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Releases every element and the array, and resets it to arro_init().
 *
 * @param[in,out] arr Array. Safe on arro_init() and on an array left by a failed call.
 */
void arro_free(arro_t* arr);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Copies an array into an existing one.
 *
 * @param[in]     arr1 Array to copy.
 * @param[in,out] res  Destination; may alias @p arr1 (no-op).
 *
 * @return DN_OK, or DN_ERR_MEMORY.
 */
int arro_copy_to(const arro_t* arr1, arro_t* res);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Element (i, j), by pointer.
 *
 * @param[in] i    Row.
 * @param[in] j    Column.
 * @param[in] arr1 Array.
 *
 * @return Pointer to the element inside the array (not a copy), or NULL when (i, j) is out of
 *         range. Valid until the array is resized or freed.
 */
const otinum_t* arro_get_item_ptr(uint64_t i, uint64_t j, const arro_t* arr1);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Sets element (i, j) to a copy of a scalar.
 *
 * @param[in]     num  Scalar.
 * @param[in]     i    Row.
 * @param[in]     j    Column.
 * @param[in,out] arr1 Array.
 *
 * @return DN_OK, DN_ERR_INDEX or DN_ERR_MEMORY.
 */
int arro_set_item(const otinum_t* num, uint64_t i, uint64_t j, arro_t* arr1);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Sets element (i, j) to a real value (keeping the element's truncation order).
 *
 * @param[in]     val  Real value.
 * @param[in]     i    Row.
 * @param[in]     j    Column.
 * @param[in,out] arr1 Array.
 *
 * @return DN_OK, or DN_ERR_INDEX.
 */
int arro_set_item_r(coeff_t val, uint64_t i, uint64_t j, arro_t* arr1);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Converts a sparse array, element by element (every element gets its own nact).
 *
 * @param[in]     arr1 Sparse array.
 * @param[in,out] res  Dense AoS array.
 * @param[in]     dhl  Direction helper list.
 *
 * @return DN_OK, DN_ERR_INDEX or DN_ERR_MEMORY.
 */
int arro_from_arrso_to(const arrso_t* arr1, arro_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Converts to a sparse array (element by element).
 *
 * @param[in] arr1 Array.
 * @param[in] dhl  Direction helper list.
 *
 * @return Newly allocated sparse array. Caller must free via arrso_free(). The sparse
 *         constructors exit on an allocation failure, as everywhere in the sparse module.
 */
arrso_t arro_to_arrso(const arro_t* arr1, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Converts to a SoA array.
 *
 * nact is the largest element nact and the truncation order the largest element truncation order;
 * every element is zero-extended into that layout (column-major blocks).
 *
 * @param[in]     arr1 AoS array.
 * @param[in,out] res  SoA array; grown as needed.
 *
 * @return DN_OK, or DN_ERR_MEMORY.
 */
int arro_to_oarr(const arro_t* arr1, oarr_t* res);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Converts a SoA array; every element gets the SoA nact and orders.
 *
 * @param[in]     arr1 SoA array.
 * @param[in,out] res  AoS array; resized as needed.
 *
 * @return DN_OK, or DN_ERR_MEMORY.
 */
int arro_from_oarr(const oarr_t* arr1, arro_t* res);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Elementwise arr1 + arr2.
 *
 * @param[in]     arr1 First array.
 * @param[in]     arr2 Second array.
 * @param[in,out] res  Result; may alias an array operand.
 * @param[in]     dhl  Direction helper list.
 *
 * @return DN_OK, or a DN_ERR_* status (the result is then unspecified but freeable).
 */
int arro_sum_OO_to(const arro_t* arr1, const arro_t* arr2, arro_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Elementwise num + arr1.
 *
 * @param[in]     num  Scalar.
 * @param[in]     arr1 First array.
 * @param[in,out] res  Result; may alias an array operand.
 * @param[in]     dhl  Direction helper list.
 *
 * @return DN_OK, or a DN_ERR_* status (the result is then unspecified but freeable).
 */
int arro_sum_oO_to(const otinum_t* num, const arro_t* arr1, arro_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Elementwise val + arr1.
 *
 * @param[in]     val  Real value.
 * @param[in]     arr1 First array.
 * @param[in,out] res  Result; may alias an array operand.
 * @param[in]     dhl  Direction helper list.
 *
 * @return DN_OK, or a DN_ERR_* status (the result is then unspecified but freeable).
 */
int arro_sum_rO_to(coeff_t val, const arro_t* arr1, arro_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Elementwise arr1 - arr2.
 *
 * @param[in]     arr1 First array.
 * @param[in]     arr2 Second array.
 * @param[in,out] res  Result; may alias an array operand.
 * @param[in]     dhl  Direction helper list.
 *
 * @return DN_OK, or a DN_ERR_* status (the result is then unspecified but freeable).
 */
int arro_sub_OO_to(const arro_t* arr1, const arro_t* arr2, arro_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Elementwise num - arr1.
 *
 * @param[in]     num  Scalar.
 * @param[in]     arr1 First array.
 * @param[in,out] res  Result; may alias an array operand.
 * @param[in]     dhl  Direction helper list.
 *
 * @return DN_OK, or a DN_ERR_* status (the result is then unspecified but freeable).
 */
int arro_sub_oO_to(const otinum_t* num, const arro_t* arr1, arro_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Elementwise val - arr1.
 *
 * @param[in]     val  Real value.
 * @param[in]     arr1 First array.
 * @param[in,out] res  Result; may alias an array operand.
 * @param[in]     dhl  Direction helper list.
 *
 * @return DN_OK, or a DN_ERR_* status (the result is then unspecified but freeable).
 */
int arro_sub_rO_to(coeff_t val, const arro_t* arr1, arro_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Elementwise arr1 - num.
 *
 * @param[in]     arr1 First array.
 * @param[in]     num  Scalar.
 * @param[in,out] res  Result; may alias an array operand.
 * @param[in]     dhl  Direction helper list.
 *
 * @return DN_OK, or a DN_ERR_* status (the result is then unspecified but freeable).
 */
int arro_sub_Oo_to(const arro_t* arr1, const otinum_t* num, arro_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Elementwise arr1 - val.
 *
 * @param[in]     arr1 First array.
 * @param[in]     val  Real value.
 * @param[in,out] res  Result; may alias an array operand.
 * @param[in]     dhl  Direction helper list.
 *
 * @return DN_OK, or a DN_ERR_* status (the result is then unspecified but freeable).
 */
int arro_sub_Or_to(const arro_t* arr1, coeff_t val, arro_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Elementwise arr1 * arr2.
 *
 * @param[in]     arr1 First array.
 * @param[in]     arr2 Second array.
 * @param[in,out] res  Result; may alias an array operand.
 * @param[in]     dhl  Direction helper list.
 *
 * @return DN_OK, or a DN_ERR_* status (the result is then unspecified but freeable).
 */
int arro_mul_OO_to(const arro_t* arr1, const arro_t* arr2, arro_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Elementwise num * arr1.
 *
 * @param[in]     num  Scalar.
 * @param[in]     arr1 First array.
 * @param[in,out] res  Result; may alias an array operand.
 * @param[in]     dhl  Direction helper list.
 *
 * @return DN_OK, or a DN_ERR_* status (the result is then unspecified but freeable).
 */
int arro_mul_oO_to(const otinum_t* num, const arro_t* arr1, arro_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Elementwise val * arr1.
 *
 * @param[in]     val  Real value.
 * @param[in]     arr1 First array.
 * @param[in,out] res  Result; may alias an array operand.
 * @param[in]     dhl  Direction helper list.
 *
 * @return DN_OK, or a DN_ERR_* status (the result is then unspecified but freeable).
 */
int arro_mul_rO_to(coeff_t val, const arro_t* arr1, arro_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Elementwise arr1 / arr2.
 *
 * @param[in]     arr1 First array.
 * @param[in]     arr2 Second array.
 * @param[in,out] res  Result; may alias an array operand.
 * @param[in]     dhl  Direction helper list.
 *
 * @return DN_OK, or a DN_ERR_* status (the result is then unspecified but freeable).
 */
int arro_div_OO_to(const arro_t* arr1, const arro_t* arr2, arro_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Elementwise num / arr1.
 *
 * @param[in]     num  Scalar.
 * @param[in]     arr1 First array.
 * @param[in,out] res  Result; may alias an array operand.
 * @param[in]     dhl  Direction helper list.
 *
 * @return DN_OK, or a DN_ERR_* status (the result is then unspecified but freeable).
 */
int arro_div_oO_to(const otinum_t* num, const arro_t* arr1, arro_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Elementwise val / arr1.
 *
 * @param[in]     val  Real value.
 * @param[in]     arr1 First array.
 * @param[in,out] res  Result; may alias an array operand.
 * @param[in]     dhl  Direction helper list.
 *
 * @return DN_OK, or a DN_ERR_* status (the result is then unspecified but freeable).
 */
int arro_div_rO_to(coeff_t val, const arro_t* arr1, arro_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Elementwise arr1 / num.
 *
 * @param[in]     arr1 First array.
 * @param[in]     num  Scalar.
 * @param[in,out] res  Result; may alias an array operand.
 * @param[in]     dhl  Direction helper list.
 *
 * @return DN_OK, or a DN_ERR_* status (the result is then unspecified but freeable).
 */
int arro_div_Oo_to(const arro_t* arr1, const otinum_t* num, arro_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Elementwise arr1 / val.
 *
 * @param[in]     arr1 First array.
 * @param[in]     val  Real value.
 * @param[in,out] res  Result; may alias an array operand.
 * @param[in]     dhl  Direction helper list.
 *
 * @return DN_OK, or a DN_ERR_* status (the result is then unspecified but freeable).
 */
int arro_div_Or_to(const arro_t* arr1, coeff_t val, arro_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Elementwise negation.
 *
 * @param[in]     arr1 First array.
 * @param[in,out] res  Result; may alias an array operand.
 * @param[in]     dhl  Direction helper list.
 *
 * @return DN_OK, or a DN_ERR_* status (the result is then unspecified but freeable).
 */
int arro_neg_to(const arro_t* arr1, arro_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Elementwise exp.
 *
 * @param[in]     arr1 First array.
 * @param[in,out] res  Result; may alias an array operand.
 * @param[in]     dhl  Direction helper list.
 *
 * @return DN_OK, or a DN_ERR_* status (the result is then unspecified but freeable).
 */
int arro_exp_to(const arro_t* arr1, arro_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Elementwise log.
 *
 * @param[in]     arr1 First array.
 * @param[in,out] res  Result; may alias an array operand.
 * @param[in]     dhl  Direction helper list.
 *
 * @return DN_OK, or a DN_ERR_* status (the result is then unspecified but freeable).
 */
int arro_log_to(const arro_t* arr1, arro_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Elementwise log10.
 *
 * @param[in]     arr1 First array.
 * @param[in,out] res  Result; may alias an array operand.
 * @param[in]     dhl  Direction helper list.
 *
 * @return DN_OK, or a DN_ERR_* status (the result is then unspecified but freeable).
 */
int arro_log10_to(const arro_t* arr1, arro_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Elementwise sqrt.
 *
 * @param[in]     arr1 First array.
 * @param[in,out] res  Result; may alias an array operand.
 * @param[in]     dhl  Direction helper list.
 *
 * @return DN_OK, or a DN_ERR_* status (the result is then unspecified but freeable).
 */
int arro_sqrt_to(const arro_t* arr1, arro_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Elementwise cbrt.
 *
 * @param[in]     arr1 First array.
 * @param[in,out] res  Result; may alias an array operand.
 * @param[in]     dhl  Direction helper list.
 *
 * @return DN_OK, or a DN_ERR_* status (the result is then unspecified but freeable).
 */
int arro_cbrt_to(const arro_t* arr1, arro_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Elementwise sin.
 *
 * @param[in]     arr1 First array.
 * @param[in,out] res  Result; may alias an array operand.
 * @param[in]     dhl  Direction helper list.
 *
 * @return DN_OK, or a DN_ERR_* status (the result is then unspecified but freeable).
 */
int arro_sin_to(const arro_t* arr1, arro_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Elementwise cos.
 *
 * @param[in]     arr1 First array.
 * @param[in,out] res  Result; may alias an array operand.
 * @param[in]     dhl  Direction helper list.
 *
 * @return DN_OK, or a DN_ERR_* status (the result is then unspecified but freeable).
 */
int arro_cos_to(const arro_t* arr1, arro_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Elementwise tan.
 *
 * @param[in]     arr1 First array.
 * @param[in,out] res  Result; may alias an array operand.
 * @param[in]     dhl  Direction helper list.
 *
 * @return DN_OK, or a DN_ERR_* status (the result is then unspecified but freeable).
 */
int arro_tan_to(const arro_t* arr1, arro_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Elementwise asin.
 *
 * @param[in]     arr1 First array.
 * @param[in,out] res  Result; may alias an array operand.
 * @param[in]     dhl  Direction helper list.
 *
 * @return DN_OK, or a DN_ERR_* status (the result is then unspecified but freeable).
 */
int arro_asin_to(const arro_t* arr1, arro_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Elementwise acos.
 *
 * @param[in]     arr1 First array.
 * @param[in,out] res  Result; may alias an array operand.
 * @param[in]     dhl  Direction helper list.
 *
 * @return DN_OK, or a DN_ERR_* status (the result is then unspecified but freeable).
 */
int arro_acos_to(const arro_t* arr1, arro_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Elementwise atan.
 *
 * @param[in]     arr1 First array.
 * @param[in,out] res  Result; may alias an array operand.
 * @param[in]     dhl  Direction helper list.
 *
 * @return DN_OK, or a DN_ERR_* status (the result is then unspecified but freeable).
 */
int arro_atan_to(const arro_t* arr1, arro_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Elementwise sinh.
 *
 * @param[in]     arr1 First array.
 * @param[in,out] res  Result; may alias an array operand.
 * @param[in]     dhl  Direction helper list.
 *
 * @return DN_OK, or a DN_ERR_* status (the result is then unspecified but freeable).
 */
int arro_sinh_to(const arro_t* arr1, arro_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Elementwise cosh.
 *
 * @param[in]     arr1 First array.
 * @param[in,out] res  Result; may alias an array operand.
 * @param[in]     dhl  Direction helper list.
 *
 * @return DN_OK, or a DN_ERR_* status (the result is then unspecified but freeable).
 */
int arro_cosh_to(const arro_t* arr1, arro_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Elementwise tanh.
 *
 * @param[in]     arr1 First array.
 * @param[in,out] res  Result; may alias an array operand.
 * @param[in]     dhl  Direction helper list.
 *
 * @return DN_OK, or a DN_ERR_* status (the result is then unspecified but freeable).
 */
int arro_tanh_to(const arro_t* arr1, arro_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Elementwise asinh.
 *
 * @param[in]     arr1 First array.
 * @param[in,out] res  Result; may alias an array operand.
 * @param[in]     dhl  Direction helper list.
 *
 * @return DN_OK, or a DN_ERR_* status (the result is then unspecified but freeable).
 */
int arro_asinh_to(const arro_t* arr1, arro_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Elementwise acosh.
 *
 * @param[in]     arr1 First array.
 * @param[in,out] res  Result; may alias an array operand.
 * @param[in]     dhl  Direction helper list.
 *
 * @return DN_OK, or a DN_ERR_* status (the result is then unspecified but freeable).
 */
int arro_acosh_to(const arro_t* arr1, arro_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Elementwise atanh.
 *
 * @param[in]     arr1 First array.
 * @param[in,out] res  Result; may alias an array operand.
 * @param[in]     dhl  Direction helper list.
 *
 * @return DN_OK, or a DN_ERR_* status (the result is then unspecified but freeable).
 */
int arro_atanh_to(const arro_t* arr1, arro_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Elementwise erf.
 *
 * @param[in]     arr1 First array.
 * @param[in,out] res  Result; may alias an array operand.
 * @param[in]     dhl  Direction helper list.
 *
 * @return DN_OK, or a DN_ERR_* status (the result is then unspecified but freeable).
 */
int arro_erf_to(const arro_t* arr1, arro_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Elementwise power with a real exponent.
 *
 * @param[in]     arr1 First array.
 * @param[in]     ex   Exponent.
 * @param[in,out] res  Result; may alias an array operand.
 * @param[in]     dhl  Direction helper list.
 *
 * @return DN_OK, or a DN_ERR_* status (the result is then unspecified but freeable).
 */
int arro_pow_to(const arro_t* arr1, coeff_t ex, arro_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Elementwise oti_truncate_im().
 *
 * @param[in]     idx   Global direction index.
 * @param[in]     order Direction order.
 * @param[in]     arr1 First array.
 * @param[in,out] res  Result; may alias an array operand.
 * @param[in]     dhl  Direction helper list.
 *
 * @return DN_OK, or a DN_ERR_* status (the result is then unspecified but freeable).
 */
int arro_truncate_im_to(imdir_t idx, ord_t order, const arro_t* arr1, arro_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Elementwise oti_truncate_order().
 *
 * @param[in]     order First order removed.
 * @param[in]     arr1 First array.
 * @param[in,out] res  Result; may alias an array operand.
 * @param[in]     dhl  Direction helper list.
 *
 * @return DN_OK, or a DN_ERR_* status (the result is then unspecified but freeable).
 */
int arro_truncate_order_to(ord_t order, const arro_t* arr1, arro_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Elementwise oti_get_order_im().
 *
 * @param[in]     order Order kept.
 * @param[in]     arr1 First array.
 * @param[in,out] res  Result; may alias an array operand.
 * @param[in]     dhl  Direction helper list.
 *
 * @return DN_OK, or a DN_ERR_* status (the result is then unspecified but freeable).
 */
int arro_get_order_im_to(ord_t order, const arro_t* arr1, arro_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Elementwise oti_compact().
 *
 * @param[in]     arr1 First array.
 * @param[in,out] res  Result; may alias an array operand.
 * @param[in]     dhl  Direction helper list.
 *
 * @return DN_OK, or a DN_ERR_* status (the result is then unspecified but freeable).
 */
int arro_compact_to(const arro_t* arr1, arro_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Matrix product arr1 x arr2.
 *
 * Each output element accumulates products (nact and trc: the max over the operands).
 *
 * @param[in]     arr1 First array.
 * @param[in]     arr2 Second array.
 * @param[in,out] res  Result, n x p; may alias an operand.
 * @param[in]     dhl  Direction helper list.
 *
 * @return DN_OK, or a DN_ERR_* status (the result is then unspecified but freeable).
 */
int arro_matmul_OO_to(const arro_t* arr1, const arro_t* arr2, arro_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Transpose.
 *
 * @param[in]     arr1 First array.
 * @param[in,out] res  Result; may alias @p arr1.
 *
 * @return DN_OK, or a DN_ERR_* status (the result is then unspecified but freeable).
 */
int arro_transpose_to(const arro_t* arr1, arro_t* res);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Solves K X = B.
 *
 * Converts to SoA (arro_to_oarr()), solves with oarr_solve_to(), and converts back: every element
 * of the solution has the SoA nact and orders.
 *
 * @param[in]     K   Square matrix.
 * @param[in]     b   Right-hand sides.
 * @param[in,out] x   Solution; may alias an input.
 * @param[in]     dhl Direction helper list.
 *
 * @return Status of the SoA routine (see include/oti/dense/soa/linalg.h).
 */
int arro_solve_to(const arro_t* K, const arro_t* b, arro_t* x, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Inverse of a square matrix.
 *
 * Through the SoA layout, like arro_solve_to().
 *
 * @param[in]     A   Square matrix.
 * @param[in,out] res Inverse; may alias @p A.
 * @param[in]     dhl Direction helper list.
 *
 * @return Status of the SoA routine (see include/oti/dense/soa/linalg.h).
 */
int arro_inv_to(const arro_t* A, arro_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


/**
 * @brief Determinant of a square matrix.
 *
 * Through the SoA layout, like arro_solve_to().
 *
 * @param[in]     A   Square matrix.
 * @param[in,out] res Determinant.
 * @param[in]     dhl Direction helper list.
 *
 * @return Status of the SoA routine (see include/oti/dense/soa/linalg.h).
 */
int arro_det_to(const arro_t* A, otinum_t* res, dhelpl_t dhl);
// -------------------------------------------------------------------------------------------------------


#endif
