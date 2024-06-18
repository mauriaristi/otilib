MODULE cwrap{mXnY} 

USE iso_c_binding
USE oti{mXnY}

TYPE, BIND(C) :: oarr{mXnY}_t
   TYPE(c_ptr)        :: p_data
   INTEGER(c_int64_t) :: nrows
   INTEGER(c_int64_t) :: ncols
   INTEGER(c_int64_t) :: size
END TYPE

CONTAINS

SUBROUTINE oarr{mXnY}_sin_f(lhs,res) BIND(C)

   IMPLICIT NONE

   TYPE(oarr{mXnY}_t), INTENT(IN)  :: lhs 
   TYPE(oarr{mXnY}_t), INTENT(INOUT) :: res 
   TYPE(onum{mXnY}), POINTER :: lhsarray(:), resarray(:)
   INTEGER :: i

   ! Associate the c-pointers of the C-structure to an array-like structure in fortran.
   CALL c_f_pointer( lhs%p_data, lhsarray, [lhs%size])
   CALL c_f_pointer( res%p_data, resarray, [res%size])
   
   resarray = sin(lhsarray)

END SUBROUTINE oarr{mXnY}_sin_f

SUBROUTINE oarr{mXnY}_div_aa_f(lhs,rhs,res) BIND(C)

   IMPLICIT NONE

   TYPE(oarr{mXnY}_t), INTENT(IN)  :: lhs 
   TYPE(oarr{mXnY}_t), INTENT(IN)  :: rhs
   TYPE(oarr{mXnY}_t), INTENT(INOUT) :: res 
   TYPE(onum{mXnY}), POINTER :: lhsarray(:), resarray(:), rhsarray(:)
   INTEGER :: i

   ! Associate the c-pointers of the C-structure to an array-like structure in fortran.
   CALL c_f_pointer( lhs%p_data, lhsarray, [lhs%size])
   CALL c_f_pointer( rhs%p_data, rhsarray, [rhs%size])
   CALL c_f_pointer( res%p_data, resarray, [res%size])
   
   resarray = lhsarray/rhsarray


END SUBROUTINE oarr{mXnY}_div_aa_f

SUBROUTINE oarr{mXnY}_mul_aa_f(lhs,rhs,res) BIND(C)

   IMPLICIT NONE

   TYPE(oarr{mXnY}_t), INTENT(IN)  :: lhs 
   TYPE(oarr{mXnY}_t), INTENT(IN)  :: rhs
   TYPE(oarr{mXnY}_t), INTENT(INOUT) :: res 
   TYPE(onum{mXnY}), POINTER :: lhsarray(:), resarray(:), rhsarray(:)
   INTEGER :: i

   ! Associate the c-pointers of the C-structure to an array-like structure in fortran.
   CALL c_f_pointer( lhs%p_data, lhsarray, [lhs%size])
   CALL c_f_pointer( rhs%p_data, rhsarray, [rhs%size])
   CALL c_f_pointer( res%p_data, resarray, [res%size])
   
   resarray = lhsarray*rhsarray


END SUBROUTINE oarr{mXnY}_mul_aa_f

SUBROUTINE oarr{mXnY}_cos_f(lhs,res) BIND(C)

   IMPLICIT NONE

   TYPE(oarr{mXnY}_t), INTENT(IN)    :: lhs 
   TYPE(oarr{mXnY}_t), INTENT(INOUT) :: res 
   TYPE(onum{mXnY}), POINTER :: lhsarray(:), resarray(:)

   ! Associate the c-pointers of the C-structure to an array-like structure in fortran.
   CALL c_f_pointer( lhs%p_data, lhsarray, [lhs%size])
   CALL c_f_pointer( res%p_data, resarray, [res%size])

   resarray = cos(lhsarray)

END SUBROUTINE oarr{mXnY}_cos_f

SUBROUTINE oarr{mXnY}_tan_f(lhs,res) BIND(C)

   IMPLICIT NONE

   TYPE(oarr{mXnY}_t), INTENT(IN)    :: lhs 
   TYPE(oarr{mXnY}_t), INTENT(INOUT) :: res 
   TYPE(onum{mXnY}), POINTER :: lhsarray(:), resarray(:)

   ! Associate the c-pointers of the C-structure to an array-like structure in fortran.
   CALL c_f_pointer( lhs%p_data, lhsarray, [lhs%size])
   CALL c_f_pointer( res%p_data, resarray, [res%size])

   resarray = tan(lhsarray)

END SUBROUTINE oarr{mXnY}_tan_f


SUBROUTINE oarr{mXnY}_sinh_f(lhs,res) BIND(C)

   IMPLICIT NONE

   TYPE(oarr{mXnY}_t), INTENT(IN)  :: lhs 
   TYPE(oarr{mXnY}_t), INTENT(INOUT) :: res 
   TYPE(onum{mXnY}), POINTER :: lhsarray(:), resarray(:)

   ! Associate the c-pointers of the C-structure to an array-like structure in fortran.
   CALL c_f_pointer( lhs%p_data, lhsarray, [lhs%size])
   CALL c_f_pointer( res%p_data, resarray, [res%size])

   resarray = sinh(lhsarray)

END SUBROUTINE oarr{mXnY}_sinh_f


SUBROUTINE oarr{mXnY}_cosh_f(lhs,res) BIND(C)

   IMPLICIT NONE

   TYPE(oarr{mXnY}_t), INTENT(IN)    :: lhs 
   TYPE(oarr{mXnY}_t), INTENT(INOUT) :: res 
   TYPE(onum{mXnY}), POINTER :: lhsarray(:), resarray(:)

   ! Associate the c-pointers of the C-structure to an array-like structure in fortran.
   CALL c_f_pointer( lhs%p_data, lhsarray, [lhs%size])
   CALL c_f_pointer( res%p_data, resarray, [res%size])

   resarray = cosh(lhsarray)

END SUBROUTINE oarr{mXnY}_cosh_f

SUBROUTINE oarr{mXnY}_tanh_f(lhs,res) BIND(C)

   IMPLICIT NONE

   TYPE(oarr{mXnY}_t), INTENT(IN)    :: lhs 
   TYPE(oarr{mXnY}_t), INTENT(INOUT) :: res 
   TYPE(onum{mXnY}), POINTER :: lhsarray(:), resarray(:)

   ! Associate the c-pointers of the C-structure to an array-like structure in fortran.
   CALL c_f_pointer( lhs%p_data, lhsarray, [lhs%size])
   CALL c_f_pointer( res%p_data, resarray, [res%size])

   resarray = tanh(lhsarray)

END SUBROUTINE oarr{mXnY}_tanh_f


SUBROUTINE oarr{mXnY}_exp_f(lhs,res) BIND(C)

   IMPLICIT NONE

   TYPE(oarr{mXnY}_t), INTENT(IN)    :: lhs 
   TYPE(oarr{mXnY}_t), INTENT(INOUT) :: res 
   TYPE(onum{mXnY}), POINTER :: lhsarray(:), resarray(:)

   ! Associate the c-pointers of the C-structure to an array-like structure in fortran.
   CALL c_f_pointer( lhs%p_data, lhsarray, [lhs%size])
   CALL c_f_pointer( res%p_data, resarray, [res%size])

   resarray = exp(lhsarray)

END SUBROUTINE oarr{mXnY}_exp_f


SUBROUTINE oarr{mXnY}_log_f(lhs,res) BIND(C)

   IMPLICIT NONE

   TYPE(oarr{mXnY}_t), INTENT(IN)    :: lhs 
   TYPE(oarr{mXnY}_t), INTENT(INOUT) :: res 
   ! The following are local arrays.
   TYPE(onum{mXnY}), POINTER :: lhsarray(:), resarray(:)

   ! Associate the c-pointers of the C-structure to an array-like structure in fortran.
   CALL c_f_pointer( lhs%p_data, lhsarray, [lhs%size])
   CALL c_f_pointer( res%p_data, resarray, [res%size])

   resarray = log(lhsarray)

END SUBROUTINE oarr{mXnY}_log_f

SUBROUTINE oarr{mXnY}_atan_f(lhs,res) BIND(C)

   IMPLICIT NONE

   TYPE(oarr{mXnY}_t), INTENT(IN)    :: lhs 
   TYPE(oarr{mXnY}_t), INTENT(INOUT) :: res 
   ! The following are local arrays.
   TYPE(onum{mXnY}), POINTER :: lhsarray(:), resarray(:)

   ! Associate the c-pointers of the C-structure to an array-like structure in fortran.
   CALL c_f_pointer( lhs%p_data, lhsarray, [lhs%size])
   CALL c_f_pointer( res%p_data, resarray, [res%size])

   resarray = atan(lhsarray)

END SUBROUTINE oarr{mXnY}_atan_f

SUBROUTINE oarr{mXnY}_asin_f(lhs,res) BIND(C)

   IMPLICIT NONE

   TYPE(oarr{mXnY}_t), INTENT(IN)    :: lhs 
   TYPE(oarr{mXnY}_t), INTENT(INOUT) :: res 
   ! The following are local arrays.
   TYPE(onum{mXnY}), POINTER :: lhsarray(:), resarray(:)

   ! Associate the c-pointers of the C-structure to an array-like structure in fortran.
   CALL c_f_pointer( lhs%p_data, lhsarray, [lhs%size])
   CALL c_f_pointer( res%p_data, resarray, [res%size])

   resarray = asin(lhsarray)

END SUBROUTINE oarr{mXnY}_asin_f

SUBROUTINE oarr{mXnY}_acos_f(lhs,res) BIND(C)

   IMPLICIT NONE

   TYPE(oarr{mXnY}_t), INTENT(IN)    :: lhs 
   TYPE(oarr{mXnY}_t), INTENT(INOUT) :: res 
   ! The following are local arrays.
   TYPE(onum{mXnY}), POINTER :: lhsarray(:), resarray(:)

   ! Associate the c-pointers of the C-structure to an array-like structure in fortran.
   CALL c_f_pointer( lhs%p_data, lhsarray, [lhs%size])
   CALL c_f_pointer( res%p_data, resarray, [res%size])

   resarray = acos(lhsarray)

END SUBROUTINE oarr{mXnY}_acos_f

! SUBROUTINE oarr{mXnY}_atanh_f(lhs,res) BIND(C)

!    IMPLICIT NONE

!    TYPE(oarr{mXnY}_t), INTENT(IN)    :: lhs 
!    TYPE(oarr{mXnY}_t), INTENT(INOUT) :: res 
!    ! The following are local arrays.
!    TYPE(onum{mXnY}), POINTER :: lhsarray(:), resarray(:)

!    ! Associate the c-pointers of the C-structure to an array-like structure in fortran.
!    CALL c_f_pointer( lhs%p_data, lhsarray, [lhs%size])
!    CALL c_f_pointer( res%p_data, resarray, [res%size])

!    resarray = atanh(lhsarray)

! END SUBROUTINE oarr{mXnY}_atanh_f

! SUBROUTINE oarr{mXnY}_asinh_f(lhs,res) BIND(C)

!    IMPLICIT NONE

!    TYPE(oarr{mXnY}_t), INTENT(IN)    :: lhs 
!    TYPE(oarr{mXnY}_t), INTENT(INOUT) :: res 
!    ! The following are local arrays.
!    TYPE(onum{mXnY}), POINTER :: lhsarray(:), resarray(:)

!    ! Associate the c-pointers of the C-structure to an array-like structure in fortran.
!    CALL c_f_pointer( lhs%p_data, lhsarray, [lhs%size])
!    CALL c_f_pointer( res%p_data, resarray, [res%size])

!    resarray = asinh(lhsarray)

! END SUBROUTINE oarr{mXnY}_asinh_f

! SUBROUTINE oarr{mXnY}_acosh_f(lhs,res) BIND(C)

!    IMPLICIT NONE

!    TYPE(oarr{mXnY}_t), INTENT(IN)    :: lhs 
!    TYPE(oarr{mXnY}_t), INTENT(INOUT) :: res 
!    ! The following are local arrays.
!    TYPE(onum{mXnY}), POINTER :: lhsarray(:), resarray(:)

!    ! Associate the c-pointers of the C-structure to an array-like structure in fortran.
!    CALL c_f_pointer( lhs%p_data, lhsarray, [lhs%size])
!    CALL c_f_pointer( res%p_data, resarray, [res%size])

!    resarray = acosh(lhsarray)

! END SUBROUTINE oarr{mXnY}_acosh_f

SUBROUTINE oarr{mXnY}_pow_f(lhs,exponent,res) BIND(C)

   IMPLICIT NONE

   TYPE(oarr{mXnY}_t), INTENT(IN)    :: lhs 
   REAL(c_double), INTENT(IN)      :: exponent
   TYPE(oarr{mXnY}_t), INTENT(INOUT) :: res 
   ! The following are local arrays.
   TYPE(onum{mXnY}), POINTER :: lhsarray(:), resarray(:)

   ! Associate the c-pointers of the C-structure to an array-like structure in fortran.
   CALL c_f_pointer( lhs%p_data, lhsarray, [lhs%size])
   CALL c_f_pointer( res%p_data, resarray, [res%size])

   resarray = lhsarray**exponent

END SUBROUTINE oarr{mXnY}_pow_f



END MODULE cwrap{mXnY}