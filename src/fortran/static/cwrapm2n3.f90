MODULE cwrapm2n3 

USE iso_c_binding
USE otim2n3

TYPE, BIND(C) :: oarrm2n3_t
   TYPE(c_ptr)        :: p_data
   INTEGER(c_int64_t) :: nrows
   INTEGER(c_int64_t) :: ncols
   INTEGER(c_int64_t) :: size
END TYPE

CONTAINS

SUBROUTINE oarrm2n3_sin_f(lhs,res) BIND(C)

   IMPLICIT NONE

   TYPE(oarrm2n3_t), INTENT(IN)  :: lhs 
   TYPE(oarrm2n3_t), INTENT(INOUT) :: res 
   TYPE(onumm2n3), POINTER :: lhsarray(:), resarray(:)
   INTEGER :: i

   ! Associate the c-pointers of the C-structure to an array-like structure in fortran.
   CALL c_f_pointer( lhs%p_data, lhsarray, [lhs%size])
   CALL c_f_pointer( res%p_data, resarray, [res%size])
   
   resarray = sin(lhsarray)

END SUBROUTINE oarrm2n3_sin_f

SUBROUTINE oarrm2n3_div_aa_f(lhs,rhs,res) BIND(C)

   IMPLICIT NONE

   TYPE(oarrm2n3_t), INTENT(IN)  :: lhs 
   TYPE(oarrm2n3_t), INTENT(IN)  :: rhs
   TYPE(oarrm2n3_t), INTENT(INOUT) :: res 
   TYPE(onumm2n3), POINTER :: lhsarray(:), resarray(:), rhsarray(:)
   INTEGER :: i

   ! Associate the c-pointers of the C-structure to an array-like structure in fortran.
   CALL c_f_pointer( lhs%p_data, lhsarray, [lhs%size])
   CALL c_f_pointer( rhs%p_data, rhsarray, [rhs%size])
   CALL c_f_pointer( res%p_data, resarray, [res%size])
   
   resarray = lhsarray/rhsarray


END SUBROUTINE oarrm2n3_div_aa_f

SUBROUTINE oarrm2n3_mul_aa_f(lhs,rhs,res) BIND(C)

   IMPLICIT NONE

   TYPE(oarrm2n3_t), INTENT(IN)  :: lhs 
   TYPE(oarrm2n3_t), INTENT(IN)  :: rhs
   TYPE(oarrm2n3_t), INTENT(INOUT) :: res 
   TYPE(onumm2n3), POINTER :: lhsarray(:), resarray(:), rhsarray(:)
   INTEGER :: i

   ! Associate the c-pointers of the C-structure to an array-like structure in fortran.
   CALL c_f_pointer( lhs%p_data, lhsarray, [lhs%size])
   CALL c_f_pointer( rhs%p_data, rhsarray, [rhs%size])
   CALL c_f_pointer( res%p_data, resarray, [res%size])
   
   resarray = lhsarray*rhsarray


END SUBROUTINE oarrm2n3_mul_aa_f

SUBROUTINE oarrm2n3_cos_f(lhs,res) BIND(C)

   IMPLICIT NONE

   TYPE(oarrm2n3_t), INTENT(IN)    :: lhs 
   TYPE(oarrm2n3_t), INTENT(INOUT) :: res 
   TYPE(onumm2n3), POINTER :: lhsarray(:), resarray(:)

   ! Associate the c-pointers of the C-structure to an array-like structure in fortran.
   CALL c_f_pointer( lhs%p_data, lhsarray, [lhs%size])
   CALL c_f_pointer( res%p_data, resarray, [res%size])

   resarray = cos(lhsarray)

END SUBROUTINE oarrm2n3_cos_f

SUBROUTINE oarrm2n3_tan_f(lhs,res) BIND(C)

   IMPLICIT NONE

   TYPE(oarrm2n3_t), INTENT(IN)    :: lhs 
   TYPE(oarrm2n3_t), INTENT(INOUT) :: res 
   TYPE(onumm2n3), POINTER :: lhsarray(:), resarray(:)

   ! Associate the c-pointers of the C-structure to an array-like structure in fortran.
   CALL c_f_pointer( lhs%p_data, lhsarray, [lhs%size])
   CALL c_f_pointer( res%p_data, resarray, [res%size])

   resarray = tan(lhsarray)

END SUBROUTINE oarrm2n3_tan_f


SUBROUTINE oarrm2n3_sinh_f(lhs,res) BIND(C)

   IMPLICIT NONE

   TYPE(oarrm2n3_t), INTENT(IN)  :: lhs 
   TYPE(oarrm2n3_t), INTENT(INOUT) :: res 
   TYPE(onumm2n3), POINTER :: lhsarray(:), resarray(:)

   ! Associate the c-pointers of the C-structure to an array-like structure in fortran.
   CALL c_f_pointer( lhs%p_data, lhsarray, [lhs%size])
   CALL c_f_pointer( res%p_data, resarray, [res%size])

   resarray = sinh(lhsarray)

END SUBROUTINE oarrm2n3_sinh_f


SUBROUTINE oarrm2n3_cosh_f(lhs,res) BIND(C)

   IMPLICIT NONE

   TYPE(oarrm2n3_t), INTENT(IN)    :: lhs 
   TYPE(oarrm2n3_t), INTENT(INOUT) :: res 
   TYPE(onumm2n3), POINTER :: lhsarray(:), resarray(:)

   ! Associate the c-pointers of the C-structure to an array-like structure in fortran.
   CALL c_f_pointer( lhs%p_data, lhsarray, [lhs%size])
   CALL c_f_pointer( res%p_data, resarray, [res%size])

   resarray = cosh(lhsarray)

END SUBROUTINE oarrm2n3_cosh_f

SUBROUTINE oarrm2n3_tanh_f(lhs,res) BIND(C)

   IMPLICIT NONE

   TYPE(oarrm2n3_t), INTENT(IN)    :: lhs 
   TYPE(oarrm2n3_t), INTENT(INOUT) :: res 
   TYPE(onumm2n3), POINTER :: lhsarray(:), resarray(:)

   ! Associate the c-pointers of the C-structure to an array-like structure in fortran.
   CALL c_f_pointer( lhs%p_data, lhsarray, [lhs%size])
   CALL c_f_pointer( res%p_data, resarray, [res%size])

   resarray = tanh(lhsarray)

END SUBROUTINE oarrm2n3_tanh_f


SUBROUTINE oarrm2n3_exp_f(lhs,res) BIND(C)

   IMPLICIT NONE

   TYPE(oarrm2n3_t), INTENT(IN)    :: lhs 
   TYPE(oarrm2n3_t), INTENT(INOUT) :: res 
   TYPE(onumm2n3), POINTER :: lhsarray(:), resarray(:)

   ! Associate the c-pointers of the C-structure to an array-like structure in fortran.
   CALL c_f_pointer( lhs%p_data, lhsarray, [lhs%size])
   CALL c_f_pointer( res%p_data, resarray, [res%size])

   resarray = exp(lhsarray)

END SUBROUTINE oarrm2n3_exp_f


SUBROUTINE oarrm2n3_log_f(lhs,res) BIND(C)

   IMPLICIT NONE

   TYPE(oarrm2n3_t), INTENT(IN)    :: lhs 
   TYPE(oarrm2n3_t), INTENT(INOUT) :: res 
   ! The following are local arrays.
   TYPE(onumm2n3), POINTER :: lhsarray(:), resarray(:)

   ! Associate the c-pointers of the C-structure to an array-like structure in fortran.
   CALL c_f_pointer( lhs%p_data, lhsarray, [lhs%size])
   CALL c_f_pointer( res%p_data, resarray, [res%size])

   resarray = log(lhsarray)

END SUBROUTINE oarrm2n3_log_f

SUBROUTINE oarrm2n3_atan_f(lhs,res) BIND(C)

   IMPLICIT NONE

   TYPE(oarrm2n3_t), INTENT(IN)    :: lhs 
   TYPE(oarrm2n3_t), INTENT(INOUT) :: res 
   ! The following are local arrays.
   TYPE(onumm2n3), POINTER :: lhsarray(:), resarray(:)

   ! Associate the c-pointers of the C-structure to an array-like structure in fortran.
   CALL c_f_pointer( lhs%p_data, lhsarray, [lhs%size])
   CALL c_f_pointer( res%p_data, resarray, [res%size])

   resarray = atan(lhsarray)

END SUBROUTINE oarrm2n3_atan_f

SUBROUTINE oarrm2n3_asin_f(lhs,res) BIND(C)

   IMPLICIT NONE

   TYPE(oarrm2n3_t), INTENT(IN)    :: lhs 
   TYPE(oarrm2n3_t), INTENT(INOUT) :: res 
   ! The following are local arrays.
   TYPE(onumm2n3), POINTER :: lhsarray(:), resarray(:)

   ! Associate the c-pointers of the C-structure to an array-like structure in fortran.
   CALL c_f_pointer( lhs%p_data, lhsarray, [lhs%size])
   CALL c_f_pointer( res%p_data, resarray, [res%size])

   resarray = asin(lhsarray)

END SUBROUTINE oarrm2n3_asin_f

SUBROUTINE oarrm2n3_acos_f(lhs,res) BIND(C)

   IMPLICIT NONE

   TYPE(oarrm2n3_t), INTENT(IN)    :: lhs 
   TYPE(oarrm2n3_t), INTENT(INOUT) :: res 
   ! The following are local arrays.
   TYPE(onumm2n3), POINTER :: lhsarray(:), resarray(:)

   ! Associate the c-pointers of the C-structure to an array-like structure in fortran.
   CALL c_f_pointer( lhs%p_data, lhsarray, [lhs%size])
   CALL c_f_pointer( res%p_data, resarray, [res%size])

   resarray = acos(lhsarray)

END SUBROUTINE oarrm2n3_acos_f

! SUBROUTINE oarrm2n3_atanh_f(lhs,res) BIND(C)

!    IMPLICIT NONE

!    TYPE(oarrm2n3_t), INTENT(IN)    :: lhs 
!    TYPE(oarrm2n3_t), INTENT(INOUT) :: res 
!    ! The following are local arrays.
!    TYPE(onumm2n3), POINTER :: lhsarray(:), resarray(:)

!    ! Associate the c-pointers of the C-structure to an array-like structure in fortran.
!    CALL c_f_pointer( lhs%p_data, lhsarray, [lhs%size])
!    CALL c_f_pointer( res%p_data, resarray, [res%size])

!    resarray = atanh(lhsarray)

! END SUBROUTINE oarrm2n3_atanh_f

! SUBROUTINE oarrm2n3_asinh_f(lhs,res) BIND(C)

!    IMPLICIT NONE

!    TYPE(oarrm2n3_t), INTENT(IN)    :: lhs 
!    TYPE(oarrm2n3_t), INTENT(INOUT) :: res 
!    ! The following are local arrays.
!    TYPE(onumm2n3), POINTER :: lhsarray(:), resarray(:)

!    ! Associate the c-pointers of the C-structure to an array-like structure in fortran.
!    CALL c_f_pointer( lhs%p_data, lhsarray, [lhs%size])
!    CALL c_f_pointer( res%p_data, resarray, [res%size])

!    resarray = asinh(lhsarray)

! END SUBROUTINE oarrm2n3_asinh_f

! SUBROUTINE oarrm2n3_acosh_f(lhs,res) BIND(C)

!    IMPLICIT NONE

!    TYPE(oarrm2n3_t), INTENT(IN)    :: lhs 
!    TYPE(oarrm2n3_t), INTENT(INOUT) :: res 
!    ! The following are local arrays.
!    TYPE(onumm2n3), POINTER :: lhsarray(:), resarray(:)

!    ! Associate the c-pointers of the C-structure to an array-like structure in fortran.
!    CALL c_f_pointer( lhs%p_data, lhsarray, [lhs%size])
!    CALL c_f_pointer( res%p_data, resarray, [res%size])

!    resarray = acosh(lhsarray)

! END SUBROUTINE oarrm2n3_acosh_f

SUBROUTINE oarrm2n3_pow_f(lhs,exponent,res) BIND(C)

   IMPLICIT NONE

   TYPE(oarrm2n3_t), INTENT(IN)    :: lhs 
   REAL(c_double), INTENT(IN)      :: exponent
   TYPE(oarrm2n3_t), INTENT(INOUT) :: res 
   ! The following are local arrays.
   TYPE(onumm2n3), POINTER :: lhsarray(:), resarray(:)

   ! Associate the c-pointers of the C-structure to an array-like structure in fortran.
   CALL c_f_pointer( lhs%p_data, lhsarray, [lhs%size])
   CALL c_f_pointer( res%p_data, resarray, [res%size])

   resarray = lhsarray**exponent

END SUBROUTINE oarrm2n3_pow_f

SUBROUTINE oarrm2n3_sqrt_f(lhs,res) BIND(C)
 
   IMPLICIT NONE
 
   TYPE(oarrm2n3_t), INTENT(IN)    :: lhs 
   TYPE(oarrm2n3_t), INTENT(INOUT) :: res 
   TYPE(onumm2n3), POINTER :: lhsarray(:), resarray(:)
 
   ! Associate the c-pointers of the C-structure to an array-like structure in fortran.
   CALL c_f_pointer( lhs%p_data, lhsarray, [lhs%size])
   CALL c_f_pointer( res%p_data, resarray, [res%size])
 
   resarray = lhsarray**(0.5d0)
 
END SUBROUTINE oarrm2n3_sqrt_f

END MODULE cwrapm2n3