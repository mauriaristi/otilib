

# cpdef point1_iso(coeff_t xi_r, coeff_t eta_r, coeff_t chi_r, ord_t derOrder)
# cpdef  line1_iso(coeff_t xi_r, coeff_t eta_r, coeff_t chi_r, ord_t derOrder)
# cpdef  line2_iso(coeff_t xi_r, coeff_t eta_r, coeff_t chi_r, ord_t derOrder)
# cpdef  line3_iso(coeff_t xi_r, coeff_t eta_r, coeff_t chi_r, ord_t derOrder)

# cpdef   tri1_iso(coeff_t xi_r, coeff_t eta_r, coeff_t chi_r, ord_t derOrder)
# cpdef   tri3_iso(coeff_t xi_r, coeff_t eta_r, coeff_t chi_r, ord_t derOrder)
# cpdef   tri4_iso(coeff_t xi_r, coeff_t eta_r, coeff_t chi_r, ord_t derOrder)
# cpdef   tri6_iso(coeff_t xi_r, coeff_t eta_r, coeff_t chi_r, ord_t derOrder)

# cpdef  quad4_iso(coeff_t xi_r, coeff_t eta_r, coeff_t chi_r, ord_t derOrder)
# cpdef  quad8_iso(coeff_t xi_r, coeff_t eta_r, coeff_t chi_r, ord_t derOrder)
# cpdef  quad9_iso(coeff_t xi_r, coeff_t eta_r, coeff_t chi_r, ord_t derOrder)

# cpdef   hex8_iso(coeff_t xi_r, coeff_t eta_r, coeff_t chi_r, ord_t derOrder)
# cpdef  hex20_iso(coeff_t xi_r, coeff_t eta_r, coeff_t chi_r, ord_t derOrder)

# cpdef   tet4_iso(coeff_t xi_r, coeff_t eta_r, coeff_t chi_r, ord_t derOrder)


cpdef point1_iso( xi, eta, zeta)

cpdef  line1_iso( xi, eta, zeta)
cpdef  line2_iso( xi, eta, zeta)
cpdef  line3_iso( xi, eta, zeta)

cpdef   tri1_iso( xi, eta, zeta)
cpdef   tri3_iso( xi, eta, zeta)
cpdef   tri4_iso( xi, eta, zeta)
cpdef   tri6_iso( xi, eta, zeta)

cpdef  quad1_iso( xi, eta, zeta)
cpdef  quad4_iso( xi, eta, zeta)
cpdef  quad8_iso( xi, eta, zeta)
cpdef  quad9_iso( xi, eta, zeta)

cpdef   hex1_iso( xi, eta, zeta)
cpdef   hex8_iso( xi, eta, zeta)
cpdef  hex20_iso( xi, eta, zeta)

cpdef   tet1_iso( xi, eta, zeta)
cpdef   tet4_iso( xi, eta, zeta)
cpdef  tet10_iso( xi, eta, zeta)


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
