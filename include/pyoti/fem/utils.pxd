

cpdef point1_iso( ord_t derOrder, np.ndarray coords)
cpdef  line2_iso( ord_t derOrder, np.ndarray coords)
cpdef  line3_iso( ord_t derOrder, np.ndarray coords)
cpdef   tri3_iso( ord_t derOrder, np.ndarray coords)
cpdef   tri4_iso( ord_t derOrder, np.ndarray coords)
cpdef   tri6_iso( ord_t derOrder, np.ndarray coords)
cpdef  quad4_iso( ord_t derOrder, np.ndarray coords)
cpdef  quad8_iso( ord_t derOrder, np.ndarray coords)
# cpdef brick8_iso( ord_t derOrder, np.ndarray coords)
# cpdef brick20_iso( ord_t derOrder, np.ndarray coords)


# ----------------------------------------------------------------------------------------------------
# -------------------------------------    AUX FUNCTIONS    ------------------------------------------
# ----------------------------------------------------------------------------------------------------

# cpdef intOmega(fefunction func1, region = *)
# cpdef intGamma( boundaryId, fefunction func1 )
# cpdef on(boundaryId, fefunction func1, in2)
# cpdef dx(fefunction func1)
# cpdef dy(fefunction func1)
# cpdef dz(fefunction func1)
# # cdef np.ndarray darray_2_numpyArray(darray_t* array )
# # cpdef int64_t fem_getDataKind(object data)
# # cpdef list fem_getOffset(list position,list solFunc,list testFunc,np.ndarray eDOF_per_sol)
# # cpdef list fem_getEqvPosition(list position,list solFunc,list testFunc)
# # cpdef uint64_t fem_getEqvPositionIndx(list position,list solFunc,list testFunc)
# # cpdef list fem_getOrderedFuncList(list funcList)
cdef object enum2string(int64_t enumId)
# # cdef object c_darray_print(darray_t* array)
# # cdef object c_elemprops_print(elemProps_t* array,style = *) 
# # cdef object c_femarray_print(femarray_t* array,style = *)
# # cdef object c_elemprops_print_perElement(elemProps_t* array,style = *)

# ----------------------------------------------------------------------------------------------------
