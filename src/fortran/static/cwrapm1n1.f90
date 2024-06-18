MODULE cwrapm1n1 

USE iso_c_binding
USE otim1n1

TYPE, BIND(C) :: oarrm1n1_t
   TYPE(c_ptr)        :: p_data
   INTEGER(c_int64_t) :: nrows
   INTEGER(c_int64_t) :: ncols
   INTEGER(c_int64_t) :: size
END TYPE

CONTAINS

SUBROUTINE oarrm1n1_sin_f(lhs,res) BIND(C)

   IMPLICIT NONE

   TYPE(oarrm1n1_t), INTENT(IN)  :: lhs 
   TYPE(oarrm1n1_t), INTENT(INOUT) :: res 
   TYPE(onumm1n1), POINTER :: lhsarray(:), resarray(:)
   INTEGER :: i

   ! Associate the c-pointers of the C-structure to an array-like structure in fortran.
   CALL c_f_pointer( lhs%p_data, lhsarray, [lhs%size])
   CALL c_f_pointer( res%p_data, resarray, [res%size])
   
   resarray = sin(lhsarray)

END SUBROUTINE oarrm1n1_sin_f

SUBROUTINE oarrm1n1_div_aa_f(lhs,rhs,res) BIND(C)

   IMPLICIT NONE

   TYPE(oarrm1n1_t), INTENT(IN)  :: lhs 
   TYPE(oarrm1n1_t), INTENT(IN)  :: rhs
   TYPE(oarrm1n1_t), INTENT(INOUT) :: res 
   TYPE(onumm1n1), POINTER :: lhsarray(:), resarray(:), rhsarray(:)
   INTEGER :: i

   ! Associate the c-pointers of the C-structure to an array-like structure in fortran.
   CALL c_f_pointer( lhs%p_data, lhsarray, [lhs%size])
   CALL c_f_pointer( rhs%p_data, rhsarray, [rhs%size])
   CALL c_f_pointer( res%p_data, resarray, [res%size])
   
   resarray = lhsarray/rhsarray


END SUBROUTINE oarrm1n1_div_aa_f

SUBROUTINE oarrm1n1_mul_aa_f(lhs,rhs,res) BIND(C)

   IMPLICIT NONE

   TYPE(oarrm1n1_t), INTENT(IN)  :: lhs 
   TYPE(oarrm1n1_t), INTENT(IN)  :: rhs
   TYPE(oarrm1n1_t), INTENT(INOUT) :: res 
   TYPE(onumm1n1), POINTER :: lhsarray(:), resarray(:), rhsarray(:)
   INTEGER :: i

   ! Associate the c-pointers of the C-structure to an array-like structure in fortran.
   CALL c_f_pointer( lhs%p_data, lhsarray, [lhs%size])
   CALL c_f_pointer( rhs%p_data, rhsarray, [rhs%size])
   CALL c_f_pointer( res%p_data, resarray, [res%size])
   
   resarray = lhsarray*rhsarray


END SUBROUTINE oarrm1n1_mul_aa_f

SUBROUTINE oarrm1n1_cos_f(lhs,res) BIND(C)

   IMPLICIT NONE

   TYPE(oarrm1n1_t), INTENT(IN)    :: lhs 
   TYPE(oarrm1n1_t), INTENT(INOUT) :: res 
   TYPE(onumm1n1), POINTER :: lhsarray(:), resarray(:)

   ! Associate the c-pointers of the C-structure to an array-like structure in fortran.
   CALL c_f_pointer( lhs%p_data, lhsarray, [lhs%size])
   CALL c_f_pointer( res%p_data, resarray, [res%size])

   resarray = cos(lhsarray)

END SUBROUTINE oarrm1n1_cos_f

SUBROUTINE oarrm1n1_tan_f(lhs,res) BIND(C)

   IMPLICIT NONE

   TYPE(oarrm1n1_t), INTENT(IN)    :: lhs 
   TYPE(oarrm1n1_t), INTENT(INOUT) :: res 
   TYPE(onumm1n1), POINTER :: lhsarray(:), resarray(:)

   ! Associate the c-pointers of the C-structure to an array-like structure in fortran.
   CALL c_f_pointer( lhs%p_data, lhsarray, [lhs%size])
   CALL c_f_pointer( res%p_data, resarray, [res%size])

   resarray = tan(lhsarray)

END SUBROUTINE oarrm1n1_tan_f


SUBROUTINE oarrm1n1_sinh_f(lhs,res) BIND(C)

   IMPLICIT NONE

   TYPE(oarrm1n1_t), INTENT(IN)  :: lhs 
   TYPE(oarrm1n1_t), INTENT(INOUT) :: res 
   TYPE(onumm1n1), POINTER :: lhsarray(:), resarray(:)

   ! Associate the c-pointers of the C-structure to an array-like structure in fortran.
   CALL c_f_pointer( lhs%p_data, lhsarray, [lhs%size])
   CALL c_f_pointer( res%p_data, resarray, [res%size])

   resarray = sinh(lhsarray)

END SUBROUTINE oarrm1n1_sinh_f


SUBROUTINE oarrm1n1_cosh_f(lhs,res) BIND(C)

   IMPLICIT NONE

   TYPE(oarrm1n1_t), INTENT(IN)    :: lhs 
   TYPE(oarrm1n1_t), INTENT(INOUT) :: res 
   TYPE(onumm1n1), POINTER :: lhsarray(:), resarray(:)

   ! Associate the c-pointers of the C-structure to an array-like structure in fortran.
   CALL c_f_pointer( lhs%p_data, lhsarray, [lhs%size])
   CALL c_f_pointer( res%p_data, resarray, [res%size])

   resarray = cosh(lhsarray)

END SUBROUTINE oarrm1n1_cosh_f

SUBROUTINE oarrm1n1_tanh_f(lhs,res) BIND(C)

   IMPLICIT NONE

   TYPE(oarrm1n1_t), INTENT(IN)    :: lhs 
   TYPE(oarrm1n1_t), INTENT(INOUT) :: res 
   TYPE(onumm1n1), POINTER :: lhsarray(:), resarray(:)

   ! Associate the c-pointers of the C-structure to an array-like structure in fortran.
   CALL c_f_pointer( lhs%p_data, lhsarray, [lhs%size])
   CALL c_f_pointer( res%p_data, resarray, [res%size])

   resarray = tanh(lhsarray)

END SUBROUTINE oarrm1n1_tanh_f


SUBROUTINE oarrm1n1_exp_f(lhs,res) BIND(C)

   IMPLICIT NONE

   TYPE(oarrm1n1_t), INTENT(IN)    :: lhs 
   TYPE(oarrm1n1_t), INTENT(INOUT) :: res 
   TYPE(onumm1n1), POINTER :: lhsarray(:), resarray(:)

   ! Associate the c-pointers of the C-structure to an array-like structure in fortran.
   CALL c_f_pointer( lhs%p_data, lhsarray, [lhs%size])
   CALL c_f_pointer( res%p_data, resarray, [res%size])

   resarray = exp(lhsarray)

END SUBROUTINE oarrm1n1_exp_f


SUBROUTINE oarrm1n1_log_f(lhs,res) BIND(C)

   IMPLICIT NONE

   TYPE(oarrm1n1_t), INTENT(IN)    :: lhs 
   TYPE(oarrm1n1_t), INTENT(INOUT) :: res 
   ! The following are local arrays.
   TYPE(onumm1n1), POINTER :: lhsarray(:), resarray(:)

   ! Associate the c-pointers of the C-structure to an array-like structure in fortran.
   CALL c_f_pointer( lhs%p_data, lhsarray, [lhs%size])
   CALL c_f_pointer( res%p_data, resarray, [res%size])

   resarray = log(lhsarray)

END SUBROUTINE oarrm1n1_log_f

SUBROUTINE oarrm1n1_atan_f(lhs,res) BIND(C)

   IMPLICIT NONE

   TYPE(oarrm1n1_t), INTENT(IN)    :: lhs 
   TYPE(oarrm1n1_t), INTENT(INOUT) :: res 
   ! The following are local arrays.
   TYPE(onumm1n1), POINTER :: lhsarray(:), resarray(:)

   ! Associate the c-pointers of the C-structure to an array-like structure in fortran.
   CALL c_f_pointer( lhs%p_data, lhsarray, [lhs%size])
   CALL c_f_pointer( res%p_data, resarray, [res%size])

   resarray = atan(lhsarray)

END SUBROUTINE oarrm1n1_atan_f

SUBROUTINE oarrm1n1_asin_f(lhs,res) BIND(C)

   IMPLICIT NONE

   TYPE(oarrm1n1_t), INTENT(IN)    :: lhs 
   TYPE(oarrm1n1_t), INTENT(INOUT) :: res 
   ! The following are local arrays.
   TYPE(onumm1n1), POINTER :: lhsarray(:), resarray(:)

   ! Associate the c-pointers of the C-structure to an array-like structure in fortran.
   CALL c_f_pointer( lhs%p_data, lhsarray, [lhs%size])
   CALL c_f_pointer( res%p_data, resarray, [res%size])

   resarray = asin(lhsarray)

END SUBROUTINE oarrm1n1_asin_f

SUBROUTINE oarrm1n1_acos_f(lhs,res) BIND(C)

   IMPLICIT NONE

   TYPE(oarrm1n1_t), INTENT(IN)    :: lhs 
   TYPE(oarrm1n1_t), INTENT(INOUT) :: res 
   ! The following are local arrays.
   TYPE(onumm1n1), POINTER :: lhsarray(:), resarray(:)

   ! Associate the c-pointers of the C-structure to an array-like structure in fortran.
   CALL c_f_pointer( lhs%p_data, lhsarray, [lhs%size])
   CALL c_f_pointer( res%p_data, resarray, [res%size])

   resarray = acos(lhsarray)

END SUBROUTINE oarrm1n1_acos_f

! SUBROUTINE oarrm1n1_atanh_f(lhs,res) BIND(C)

!    IMPLICIT NONE

!    TYPE(oarrm1n1_t), INTENT(IN)    :: lhs 
!    TYPE(oarrm1n1_t), INTENT(INOUT) :: res 
!    ! The following are local arrays.
!    TYPE(onumm1n1), POINTER :: lhsarray(:), resarray(:)

!    ! Associate the c-pointers of the C-structure to an array-like structure in fortran.
!    CALL c_f_pointer( lhs%p_data, lhsarray, [lhs%size])
!    CALL c_f_pointer( res%p_data, resarray, [res%size])

!    resarray = atanh(lhsarray)

! END SUBROUTINE oarrm1n1_atanh_f

! SUBROUTINE oarrm1n1_asinh_f(lhs,res) BIND(C)

!    IMPLICIT NONE

!    TYPE(oarrm1n1_t), INTENT(IN)    :: lhs 
!    TYPE(oarrm1n1_t), INTENT(INOUT) :: res 
!    ! The following are local arrays.
!    TYPE(onumm1n1), POINTER :: lhsarray(:), resarray(:)

!    ! Associate the c-pointers of the C-structure to an array-like structure in fortran.
!    CALL c_f_pointer( lhs%p_data, lhsarray, [lhs%size])
!    CALL c_f_pointer( res%p_data, resarray, [res%size])

!    resarray = asinh(lhsarray)

! END SUBROUTINE oarrm1n1_asinh_f

! SUBROUTINE oarrm1n1_acosh_f(lhs,res) BIND(C)

!    IMPLICIT NONE

!    TYPE(oarrm1n1_t), INTENT(IN)    :: lhs 
!    TYPE(oarrm1n1_t), INTENT(INOUT) :: res 
!    ! The following are local arrays.
!    TYPE(onumm1n1), POINTER :: lhsarray(:), resarray(:)

!    ! Associate the c-pointers of the C-structure to an array-like structure in fortran.
!    CALL c_f_pointer( lhs%p_data, lhsarray, [lhs%size])
!    CALL c_f_pointer( res%p_data, resarray, [res%size])

!    resarray = acosh(lhsarray)

! END SUBROUTINE oarrm1n1_acosh_f

SUBROUTINE oarrm1n1_pow_f(lhs,exponent,res) BIND(C)

   IMPLICIT NONE

   TYPE(oarrm1n1_t), INTENT(IN)    :: lhs 
   REAL(c_double), INTENT(IN)      :: exponent
   TYPE(oarrm1n1_t), INTENT(INOUT) :: res 
   ! The following are local arrays.
   TYPE(onumm1n1), POINTER :: lhsarray(:), resarray(:)

   ! Associate the c-pointers of the C-structure to an array-like structure in fortran.
   CALL c_f_pointer( lhs%p_data, lhsarray, [lhs%size])
   CALL c_f_pointer( res%p_data, resarray, [res%size])

   resarray = lhsarray**exponent

END SUBROUTINE oarrm1n1_pow_f

SUBROUTINE oarrm1n1_sqrt_f(lhs,res) BIND(C)
 
   IMPLICIT NONE
 
   TYPE(oarrm1n1_t), INTENT(IN)    :: lhs 
   TYPE(oarrm1n1_t), INTENT(INOUT) :: res 
   TYPE(onumm1n1), POINTER :: lhsarray(:), resarray(:)
 
   ! Associate the c-pointers of the C-structure to an array-like structure in fortran.
   CALL c_f_pointer( lhs%p_data, lhsarray, [lhs%size])
   CALL c_f_pointer( res%p_data, resarray, [res%size])
 
   resarray = lhsarray**(0.5d0)
 
END SUBROUTINE oarrm1n1_sqrt_f



END MODULE cwrapm1n1