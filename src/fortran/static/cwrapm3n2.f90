MODULE cwrapm3n2 

USE iso_c_binding
USE otim3n2

TYPE, BIND(C) :: oarrm3n2_t
   TYPE(c_ptr)        :: p_data
   INTEGER(c_int64_t) :: nrows
   INTEGER(c_int64_t) :: ncols
   INTEGER(c_int64_t) :: size
END TYPE

CONTAINS

SUBROUTINE oarrm3n2_sin_f(lhs,res) BIND(C)

   IMPLICIT NONE

   TYPE(oarrm3n2_t), INTENT(IN)  :: lhs 
   TYPE(oarrm3n2_t), INTENT(INOUT) :: res 
   TYPE(onumm3n2), POINTER :: lhsarray(:), resarray(:)
   INTEGER :: i

   ! Associate the c-pointers of the C-structure to an array-like structure in fortran.
   CALL c_f_pointer( lhs%p_data, lhsarray, [lhs%size])
   CALL c_f_pointer( res%p_data, resarray, [res%size])
   
   resarray = sin(lhsarray)

END SUBROUTINE oarrm3n2_sin_f

SUBROUTINE oarrm3n2_div_aa_f(lhs,rhs,res) BIND(C)

   IMPLICIT NONE

   TYPE(oarrm3n2_t), INTENT(IN)  :: lhs 
   TYPE(oarrm3n2_t), INTENT(IN)  :: rhs
   TYPE(oarrm3n2_t), INTENT(INOUT) :: res 
   TYPE(onumm3n2), POINTER :: lhsarray(:), resarray(:), rhsarray(:)
   INTEGER :: i

   ! Associate the c-pointers of the C-structure to an array-like structure in fortran.
   CALL c_f_pointer( lhs%p_data, lhsarray, [lhs%size])
   CALL c_f_pointer( rhs%p_data, rhsarray, [rhs%size])
   CALL c_f_pointer( res%p_data, resarray, [res%size])
   
   resarray = lhsarray/rhsarray


END SUBROUTINE oarrm3n2_div_aa_f

SUBROUTINE oarrm3n2_mul_aa_f(lhs,rhs,res) BIND(C)

   IMPLICIT NONE

   TYPE(oarrm3n2_t), INTENT(IN)  :: lhs 
   TYPE(oarrm3n2_t), INTENT(IN)  :: rhs
   TYPE(oarrm3n2_t), INTENT(INOUT) :: res 
   TYPE(onumm3n2), POINTER :: lhsarray(:), resarray(:), rhsarray(:)
   INTEGER :: i

   ! Associate the c-pointers of the C-structure to an array-like structure in fortran.
   CALL c_f_pointer( lhs%p_data, lhsarray, [lhs%size])
   CALL c_f_pointer( rhs%p_data, rhsarray, [rhs%size])
   CALL c_f_pointer( res%p_data, resarray, [res%size])
   
   resarray = lhsarray*rhsarray


END SUBROUTINE oarrm3n2_mul_aa_f

SUBROUTINE oarrm3n2_cos_f(lhs,res) BIND(C)

   IMPLICIT NONE

   TYPE(oarrm3n2_t), INTENT(IN)    :: lhs 
   TYPE(oarrm3n2_t), INTENT(INOUT) :: res 
   TYPE(onumm3n2), POINTER :: lhsarray(:), resarray(:)

   ! Associate the c-pointers of the C-structure to an array-like structure in fortran.
   CALL c_f_pointer( lhs%p_data, lhsarray, [lhs%size])
   CALL c_f_pointer( res%p_data, resarray, [res%size])

   resarray = cos(lhsarray)

END SUBROUTINE oarrm3n2_cos_f

SUBROUTINE oarrm3n2_tan_f(lhs,res) BIND(C)

   IMPLICIT NONE

   TYPE(oarrm3n2_t), INTENT(IN)    :: lhs 
   TYPE(oarrm3n2_t), INTENT(INOUT) :: res 
   TYPE(onumm3n2), POINTER :: lhsarray(:), resarray(:)

   ! Associate the c-pointers of the C-structure to an array-like structure in fortran.
   CALL c_f_pointer( lhs%p_data, lhsarray, [lhs%size])
   CALL c_f_pointer( res%p_data, resarray, [res%size])

   resarray = tan(lhsarray)

END SUBROUTINE oarrm3n2_tan_f


SUBROUTINE oarrm3n2_sinh_f(lhs,res) BIND(C)

   IMPLICIT NONE

   TYPE(oarrm3n2_t), INTENT(IN)  :: lhs 
   TYPE(oarrm3n2_t), INTENT(INOUT) :: res 
   TYPE(onumm3n2), POINTER :: lhsarray(:), resarray(:)

   ! Associate the c-pointers of the C-structure to an array-like structure in fortran.
   CALL c_f_pointer( lhs%p_data, lhsarray, [lhs%size])
   CALL c_f_pointer( res%p_data, resarray, [res%size])

   resarray = sinh(lhsarray)

END SUBROUTINE oarrm3n2_sinh_f


SUBROUTINE oarrm3n2_cosh_f(lhs,res) BIND(C)

   IMPLICIT NONE

   TYPE(oarrm3n2_t), INTENT(IN)    :: lhs 
   TYPE(oarrm3n2_t), INTENT(INOUT) :: res 
   TYPE(onumm3n2), POINTER :: lhsarray(:), resarray(:)

   ! Associate the c-pointers of the C-structure to an array-like structure in fortran.
   CALL c_f_pointer( lhs%p_data, lhsarray, [lhs%size])
   CALL c_f_pointer( res%p_data, resarray, [res%size])

   resarray = cosh(lhsarray)

END SUBROUTINE oarrm3n2_cosh_f

SUBROUTINE oarrm3n2_tanh_f(lhs,res) BIND(C)

   IMPLICIT NONE

   TYPE(oarrm3n2_t), INTENT(IN)    :: lhs 
   TYPE(oarrm3n2_t), INTENT(INOUT) :: res 
   TYPE(onumm3n2), POINTER :: lhsarray(:), resarray(:)

   ! Associate the c-pointers of the C-structure to an array-like structure in fortran.
   CALL c_f_pointer( lhs%p_data, lhsarray, [lhs%size])
   CALL c_f_pointer( res%p_data, resarray, [res%size])

   resarray = tanh(lhsarray)

END SUBROUTINE oarrm3n2_tanh_f


SUBROUTINE oarrm3n2_exp_f(lhs,res) BIND(C)

   IMPLICIT NONE

   TYPE(oarrm3n2_t), INTENT(IN)    :: lhs 
   TYPE(oarrm3n2_t), INTENT(INOUT) :: res 
   TYPE(onumm3n2), POINTER :: lhsarray(:), resarray(:)

   ! Associate the c-pointers of the C-structure to an array-like structure in fortran.
   CALL c_f_pointer( lhs%p_data, lhsarray, [lhs%size])
   CALL c_f_pointer( res%p_data, resarray, [res%size])

   resarray = exp(lhsarray)

END SUBROUTINE oarrm3n2_exp_f


SUBROUTINE oarrm3n2_log_f(lhs,res) BIND(C)

   IMPLICIT NONE

   TYPE(oarrm3n2_t), INTENT(IN)    :: lhs 
   TYPE(oarrm3n2_t), INTENT(INOUT) :: res 
   ! The following are local arrays.
   TYPE(onumm3n2), POINTER :: lhsarray(:), resarray(:)

   ! Associate the c-pointers of the C-structure to an array-like structure in fortran.
   CALL c_f_pointer( lhs%p_data, lhsarray, [lhs%size])
   CALL c_f_pointer( res%p_data, resarray, [res%size])

   resarray = log(lhsarray)

END SUBROUTINE oarrm3n2_log_f

SUBROUTINE oarrm3n2_atan_f(lhs,res) BIND(C)

   IMPLICIT NONE

   TYPE(oarrm3n2_t), INTENT(IN)    :: lhs 
   TYPE(oarrm3n2_t), INTENT(INOUT) :: res 
   ! The following are local arrays.
   TYPE(onumm3n2), POINTER :: lhsarray(:), resarray(:)

   ! Associate the c-pointers of the C-structure to an array-like structure in fortran.
   CALL c_f_pointer( lhs%p_data, lhsarray, [lhs%size])
   CALL c_f_pointer( res%p_data, resarray, [res%size])

   resarray = atan(lhsarray)

END SUBROUTINE oarrm3n2_atan_f

SUBROUTINE oarrm3n2_asin_f(lhs,res) BIND(C)

   IMPLICIT NONE

   TYPE(oarrm3n2_t), INTENT(IN)    :: lhs 
   TYPE(oarrm3n2_t), INTENT(INOUT) :: res 
   ! The following are local arrays.
   TYPE(onumm3n2), POINTER :: lhsarray(:), resarray(:)

   ! Associate the c-pointers of the C-structure to an array-like structure in fortran.
   CALL c_f_pointer( lhs%p_data, lhsarray, [lhs%size])
   CALL c_f_pointer( res%p_data, resarray, [res%size])

   resarray = asin(lhsarray)

END SUBROUTINE oarrm3n2_asin_f

SUBROUTINE oarrm3n2_acos_f(lhs,res) BIND(C)

   IMPLICIT NONE

   TYPE(oarrm3n2_t), INTENT(IN)    :: lhs 
   TYPE(oarrm3n2_t), INTENT(INOUT) :: res 
   ! The following are local arrays.
   TYPE(onumm3n2), POINTER :: lhsarray(:), resarray(:)

   ! Associate the c-pointers of the C-structure to an array-like structure in fortran.
   CALL c_f_pointer( lhs%p_data, lhsarray, [lhs%size])
   CALL c_f_pointer( res%p_data, resarray, [res%size])

   resarray = acos(lhsarray)

END SUBROUTINE oarrm3n2_acos_f

! SUBROUTINE oarrm3n2_atanh_f(lhs,res) BIND(C)

!    IMPLICIT NONE

!    TYPE(oarrm3n2_t), INTENT(IN)    :: lhs 
!    TYPE(oarrm3n2_t), INTENT(INOUT) :: res 
!    ! The following are local arrays.
!    TYPE(onumm3n2), POINTER :: lhsarray(:), resarray(:)

!    ! Associate the c-pointers of the C-structure to an array-like structure in fortran.
!    CALL c_f_pointer( lhs%p_data, lhsarray, [lhs%size])
!    CALL c_f_pointer( res%p_data, resarray, [res%size])

!    resarray = atanh(lhsarray)

! END SUBROUTINE oarrm3n2_atanh_f

! SUBROUTINE oarrm3n2_asinh_f(lhs,res) BIND(C)

!    IMPLICIT NONE

!    TYPE(oarrm3n2_t), INTENT(IN)    :: lhs 
!    TYPE(oarrm3n2_t), INTENT(INOUT) :: res 
!    ! The following are local arrays.
!    TYPE(onumm3n2), POINTER :: lhsarray(:), resarray(:)

!    ! Associate the c-pointers of the C-structure to an array-like structure in fortran.
!    CALL c_f_pointer( lhs%p_data, lhsarray, [lhs%size])
!    CALL c_f_pointer( res%p_data, resarray, [res%size])

!    resarray = asinh(lhsarray)

! END SUBROUTINE oarrm3n2_asinh_f

! SUBROUTINE oarrm3n2_acosh_f(lhs,res) BIND(C)

!    IMPLICIT NONE

!    TYPE(oarrm3n2_t), INTENT(IN)    :: lhs 
!    TYPE(oarrm3n2_t), INTENT(INOUT) :: res 
!    ! The following are local arrays.
!    TYPE(onumm3n2), POINTER :: lhsarray(:), resarray(:)

!    ! Associate the c-pointers of the C-structure to an array-like structure in fortran.
!    CALL c_f_pointer( lhs%p_data, lhsarray, [lhs%size])
!    CALL c_f_pointer( res%p_data, resarray, [res%size])

!    resarray = acosh(lhsarray)

! END SUBROUTINE oarrm3n2_acosh_f

SUBROUTINE oarrm3n2_pow_f(lhs,exponent,res) BIND(C)

   IMPLICIT NONE

   TYPE(oarrm3n2_t), INTENT(IN)    :: lhs 
   REAL(c_double), INTENT(IN)      :: exponent
   TYPE(oarrm3n2_t), INTENT(INOUT) :: res 
   ! The following are local arrays.
   TYPE(onumm3n2), POINTER :: lhsarray(:), resarray(:)

   ! Associate the c-pointers of the C-structure to an array-like structure in fortran.
   CALL c_f_pointer( lhs%p_data, lhsarray, [lhs%size])
   CALL c_f_pointer( res%p_data, resarray, [res%size])

   resarray = lhsarray**exponent

END SUBROUTINE oarrm3n2_pow_f

SUBROUTINE oarrm3n2_sqrt_f(lhs,res) BIND(C)
 
   IMPLICIT NONE
 
   TYPE(oarrm3n2_t), INTENT(IN)    :: lhs 
   TYPE(oarrm3n2_t), INTENT(INOUT) :: res 
   TYPE(onumm3n2), POINTER :: lhsarray(:), resarray(:)
 
   ! Associate the c-pointers of the C-structure to an array-like structure in fortran.
   CALL c_f_pointer( lhs%p_data, lhsarray, [lhs%size])
   CALL c_f_pointer( res%p_data, resarray, [res%size])
 
   resarray = lhsarray**(0.5d0)
 
END SUBROUTINE oarrm3n2_sqrt_f

END MODULE cwrapm3n2