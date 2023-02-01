!*******************************************************************************************************!
!> @brief FORTRAN module to use of oti numbers. In particular, oti algebra with up to m = 2 imaginary 
!! bases and truncation order n = 2
!! 
!!
!! @author Mauricio Aristizabal Cano, Universidad EAFIT
!*******************************************************************************************************!
MODULE OTIM2N2
  !-----------------------------------------------------------------------------------------------------!
  IMPLICIT NONE
  !-----------------------------------------------------------------------------------------------------!
  
  INTEGER, PARAMETER :: DP  = 8 
  INTEGER, PARAMETER :: NUM_IM_DIR = 5
  INTEGER, PARAMETER :: TORDER     = 2
  INTEGER, PARAMETER :: SIZEX = 30
  
  !-----------------------------------------------------------------------------------------------------!
  ! OTI SCALAR TYPE. 
  TYPE ONUM_M2N2
     REAL(DP) :: R   !< Real direction
     ! ORDER 1
     REAL(DP) :: E1  !< e1 imaginary direction
     REAL(DP) :: E2  !< e1 imaginary direction
     ! ORDER 2
     REAL(DP) :: E11 !< e11 imaginary direction
     REAL(DP) :: E12 !< e12 imaginary direction
     REAL(DP) :: E22 !< e22 imaginary direction
  END TYPE ONUM_M2N2

  ! OTI VECTOR TYPE. 
  TYPE OVEC_M2N2
     REAL(DP), DIMENSION(:), ALLOCATABLE :: R   !< Real direction
     ! ORDER 1
     REAL(DP), DIMENSION(:), ALLOCATABLE :: E1  !< e1 imaginary direction
     REAL(DP), DIMENSION(:), ALLOCATABLE :: E2  !< e1 imaginary direction
     ! ORDER 2
     REAL(DP), DIMENSION(:), ALLOCATABLE :: E11 !< e11 imaginary direction
     REAL(DP), DIMENSION(:), ALLOCATABLE :: E12 !< e12 imaginary direction
     REAL(DP), DIMENSION(:), ALLOCATABLE :: E22 !< e22 imaginary direction
     integer :: flag !< If flag ==0,  then variable is known to user. Otherwise not known to the user.
  END TYPE OVEC_M2N2
  !-----------------------------------------------------------------------------------------------------!

  ! OTI MATRIX TYPE. 
  TYPE OMAT_M2N2
     REAL(DP), DIMENSION(:,:), ALLOCATABLE :: R   !< Real direction
     ! ORDER 1
     REAL(DP), DIMENSION(:,:), ALLOCATABLE :: E1  !< e1 imaginary direction
     REAL(DP), DIMENSION(:,:), ALLOCATABLE :: E2  !< e1 imaginary direction
     ! ORDER 2
     REAL(DP), DIMENSION(:,:), ALLOCATABLE :: E11 !< e11 imaginary direction
     REAL(DP), DIMENSION(:,:), ALLOCATABLE :: E12 !< e12 imaginary direction
     REAL(DP), DIMENSION(:,:), ALLOCATABLE :: E22 !< e22 imaginary direction
     integer :: flag !< If flag ==0,  then variable is known to user. Otherwise not known to the user.
  END TYPE OMAT_M2N2

  ! OTI MATRIX TYPE. 
  TYPE OMAT_M2N2_18x18
     REAL(DP), DIMENSION(SIZEX,SIZEX) :: R   
     ! ORDER 1
     REAL(DP), DIMENSION(SIZEX,SIZEX) :: E1  
     REAL(DP), DIMENSION(SIZEX,SIZEX) :: E2  
     ! ORDER 2
     REAL(DP), DIMENSION(SIZEX,SIZEX) :: E11 
     REAL(DP), DIMENSION(SIZEX,SIZEX) :: E12 
     REAL(DP), DIMENSION(SIZEX,SIZEX) :: E22 
  END TYPE OMAT_M2N2_18x18
  !-----------------------------------------------------------------------------------------------------!

!-------------------------------------------------------------------------------------------------------!
! =====================================================================================================
! -----------------------------------   OVERLOADED OPERATORS   ----------------------------------------
! =====================================================================================================

! INTIALIZATION OPERATIONS
INTERFACE ASSIGNMENT (=)
  MODULE PROCEDURE  ONUMM2N2_ASSIGN_REAL, ONUMM2N2_ARR_ASSIGN_REAL, OMAT_M2N2_18x18_ARR_ASSIGN_REAL
END INTERFACE

! PRETTY PRINTING FOR TYPES
INTERFACE PPRINT
  MODULE PROCEDURE ONUMM2N2_PRINT, ONUMM2N2_ARR_PRINT
END INTERFACE


! SCALAR OPERATORS
! ADDITION
INTERFACE OPERATOR(+)
   MODULE PROCEDURE ONUMM2N2_ADD_ONUMM2N2, REAL_ADD_ONUMM2N2,ONUMM2N2_ADD_REAL
END INTERFACE

! SUBTRACTION
INTERFACE OPERATOR(-)
   MODULE PROCEDURE ONUMM2N2_SUB_ONUMM2N2
END INTERFACE

! MULTIPLICATION
INTERFACE OPERATOR(*)
   MODULE PROCEDURE ONUMM2N2_MUL_ONUMM2N2, REAL_MUL_ONUMM2N2, ONUMM2N2_MUL_REAL
END INTERFACE

! DIVISION
INTERFACE OPERATOR(/)
   MODULE PROCEDURE ONUMM2N2_DIV_REAL, ONUMM2N2_DIV_ONUMM2N2
END INTERFACE

! OCTONION POWER OPERATOR
INTERFACE operator(**)
   MODULE PROCEDURE ONUMM2N2_IPOW, ONUMM2N2_POW
END INTERFACE

! TRASCENDENTAL FUNCTIONS
! SINE
INTERFACE SIN
  MODULE PROCEDURE ONUMM2N2_SIN
END INTERFACE

! COSINE
INTERFACE COS
  MODULE PROCEDURE ONUMM2N2_COS
END INTERFACE





! ARRAY FUNCTIONS

INTERFACE MATMUL
  MODULE PROCEDURE ONUMM2N2_MATMUL_ONUMM2N2, OMAT_M2N2_18x18_MATMUL_OMAT_M2N2_18x18
END INTERFACE



CONTAINS  
  
  ! =====================================================================================================
  ! --------------------------------------     SUBRUTINES   ---------------------------------------------
  ! =====================================================================================================
 

  !*****************************************************************************************************!
  !> @brief Assignment from OTI scalar.
  !!
  !! RES = RHS
  !!
  !! @param RES: Left hand side of the operation. Assignment target.
  !! @param RHS: Real number. 
  !*****************************************************************************************************!
  SUBROUTINE ONUMM2N2_ASSIGN_REAL(RES, RHS)
    
    IMPLICIT NONE
    TYPE(ONUM_M2N2), INTENT(OUT) :: RES
    REAL(DP), INTENT(IN)  :: RHS

    ! SET REAL PART AND ALL OTHER IMAGINARY DIRECTIONS AS 0.
    RES%R    = RHS 
    RES%E1   = 0.0D0
    RES%E2   = 0.0D0
    RES%E11  = 0.0D0
    RES%E12  = 0.0D0
    RES%E22  = 0.0D0

  END SUBROUTINE ONUMM2N2_ASSIGN_REAL
  !*****************************************************************************************************!

  !*****************************************************************************************************!
  !> @brief Pretty printing of scalar OTI type.
  !!
  !! @param ONUM: OTI number to be printed.
  !! @param FMT: Set floating point print format (optional). Default is 'ES11.3'. 
  !*****************************************************************************************************!
  SUBROUTINE ONUMM2N2_PRINT(ONUM,fmt)
    IMPLICIT NONE
    TYPE(ONUM_M2N2),  INTENT(IN) :: ONUM
    CHARACTER(len=*), INTENT(IN), OPTIONAL :: fmt
    CHARACTER(len=:), ALLOCATABLE :: output_format

    IF (PRESENT(fmt)) THEN
      output_format = '('//trim(fmt)//','// &
                           trim(fmt)//','// &
                           trim(fmt)//','// &
                           trim(fmt)//','// &
                           trim(fmt)//','// &
                           trim(fmt)//')'
    ELSE
      output_format = '(ES11.3,ES11.3,ES11.3,ES11.3,ES11.3,ES11.3)'
    END IF 

    ! PRINT CALL.
    write(*,output_format)  &
      ONUM%R  ,             &
      ONUM%E1 ,             &
      ONUM%E2 ,             &
      ONUM%E11,             &
      ONUM%E12,             &
      ONUM%E22

  END SUBROUTINE
  !*****************************************************************************************************!


  ! =====================================================================================================
  ! --------------------------------------     ADDITION     ---------------------------------------------
  ! =====================================================================================================
  !*****************************************************************************************************!
  !> @brief Addition of REAL and OTI numbers. This function is ELEMENTAL.
  !!
  !! RES = LHS + RHS
  !!
  !! @param LHS: Left hand operator.
  !! @param RHS: Right hand operator. 
  !*****************************************************************************************************!
  ELEMENTAL FUNCTION REAL_ADD_ONUMM2N2(LHS, RHS) &
    RESULT(RES)
    IMPLICIT NONE
    TYPE(ONUM_M2N2), INTENT(IN) :: RHS 
    REAL(DP), INTENT(IN) :: LHS 
    TYPE(ONUM_M2N2) :: RES

    ! ADD ALL IMAGINARY DIRECTIONS.

    RES%R    = LHS + RHS%R  

    RES%E1   = RHS%E1 
    RES%E2   = RHS%E2 

    RES%E11  = RHS%E11
    RES%E12  = RHS%E12
    RES%E22  = RHS%E22

  END FUNCTION REAL_ADD_ONUMM2N2
  !*****************************************************************************************************!

  !*****************************************************************************************************!
  !> @brief Addition of OTI and REAL numbers. This function is ELEMENTAL.
  !!
  !! RES = LHS + RHS
  !!
  !! @param LHS: Left hand operator.
  !! @param RHS: Right hand operator. 
  !*****************************************************************************************************!
  ELEMENTAL FUNCTION ONUMM2N2_ADD_REAL(LHS, RHS) &
    RESULT(RES)
    IMPLICIT NONE
    TYPE(ONUM_M2N2), INTENT(IN) :: LHS 
    REAL(DP), INTENT(IN) :: RHS 
    TYPE(ONUM_M2N2) :: RES

    ! ADD ALL IMAGINARY DIRECTIONS.
    RES%R    = LHS%R   + RHS  

    RES%E1   = LHS%E1 
    RES%E2   = LHS%E2 

    RES%E11  = LHS%E11
    RES%E12  = LHS%E12
    RES%E22  = LHS%E22

  END FUNCTION ONUMM2N2_ADD_REAL
  !*****************************************************************************************************!

  !*****************************************************************************************************!
  !> @brief Addition of OTI and OTI numbers. This function is ELEMENTAL.
  !!
  !! RES = LHS + RHS
  !!
  !! @param LHS: Left hand operator.
  !! @param RHS: Right hand operator. 
  !*****************************************************************************************************!
  ELEMENTAL FUNCTION ONUMM2N2_ADD_ONUMM2N2(LHS, RHS) &
    RESULT(RES)
    IMPLICIT NONE
    TYPE(ONUM_M2N2), INTENT(IN) :: LHS, RHS
    TYPE(ONUM_M2N2) :: RES

    ! ADD ALL IMAGINARY DIRECTIONS.
    RES%R    = LHS%R   + RHS%R  

    RES%E1   = LHS%E1  + RHS%E1 
    RES%E2   = LHS%E2  + RHS%E2 

    ! RES%E11  = LHS%E11 + RHS%E11
    ! RES%E12  = LHS%E12 + RHS%E12
    ! RES%E22  = LHS%E22 + RHS%E22

  END FUNCTION ONUMM2N2_ADD_ONUMM2N2
  !*****************************************************************************************************!







  ! =====================================================================================================
  ! -------------------------------------     SUBTRACTION     -------------------------------------------
  ! =====================================================================================================
  !*****************************************************************************************************!
  !> @brief Subtraction of OTI and REAL numbers. This function is ELEMENTAL.
  !!
  !! RES = LHS - RHS
  !!
  !! @param LHS: Left hand operator.
  !! @param RHS: Right hand operator. 
  !*****************************************************************************************************!
  ELEMENTAL FUNCTION ONUMM2N2_SUB_REAL(LHS, RHS) &
    RESULT(RES)
    IMPLICIT NONE
    TYPE(ONUM_M2N2), INTENT(IN) :: LHS
    REAL(DP), INTENT(IN) :: RHS
    TYPE(ONUM_M2N2) :: RES

    RES   = LHS
    RES%R = LHS%R   - RHS

  END FUNCTION ONUMM2N2_SUB_REAL
  !*****************************************************************************************************!

  ! SUBTRACTION OF TWO OTI NUMBERS
  !*****************************************************************************************************!
  !> @brief Subtraction of REAL and OTI numbers. This function is ELEMENTAL.
  !!
  !! RES = LHS - RHS
  !!
  !! @param LHS: Left hand operator.
  !! @param RHS: Right hand operator. 
  !*****************************************************************************************************!
  ELEMENTAL FUNCTION REAL_SUB_ONUMM2N2(LHS, RHS) &
    RESULT(RES)
    IMPLICIT NONE
    TYPE(ONUM_M2N2), INTENT(IN) :: RHS
    REAL(DP), INTENT(IN) :: LHS
    TYPE(ONUM_M2N2) :: RES

    ! SUBTRACT ALL IMAGINARY DIRECTIONS.

    RES%R    = LHS - RHS%R  

    RES%E1   = - RHS%E1 
    RES%E2   = - RHS%E2 

    RES%E11  = - RHS%E11
    RES%E12  = - RHS%E12
    RES%E22  = - RHS%E22

  END FUNCTION REAL_SUB_ONUMM2N2
  !*****************************************************************************************************!

  !*****************************************************************************************************!
  !> @brief Subtraction of OTI and OTI numbers. This function is ELEMENTAL.
  !!
  !! RES = LHS - RHS
  !!
  !! @param LHS: Left hand operator.
  !! @param RHS: Right hand operator. 
  !*****************************************************************************************************!
  ELEMENTAL FUNCTION ONUMM2N2_SUB_ONUMM2N2(LHS, RHS) &
    RESULT(RES)
    IMPLICIT NONE
    TYPE(ONUM_M2N2), INTENT(IN) :: LHS, RHS
    TYPE(ONUM_M2N2) :: RES

    ! SUBTRACT ALL IMAGINARY DIRECTIONS.

    RES%R    = LHS%R   - RHS%R  

    RES%E1   = LHS%E1  - RHS%E1 
    RES%E2   = LHS%E2  - RHS%E2 

    RES%E11  = LHS%E11 - RHS%E11
    RES%E12  = LHS%E12 - RHS%E12
    RES%E22  = LHS%E22 - RHS%E22

  END FUNCTION ONUMM2N2_SUB_ONUMM2N2
  !*****************************************************************************************************!









  ! =====================================================================================================
  ! ------------------------------------     MULTIPLICATION     -----------------------------------------
  ! =====================================================================================================
  !*****************************************************************************************************!
  !> @brief Multiplication of OTI and OTI numbers. This function is ELEMENTAL.
  !!
  !! RES = LHS * RHS
  !!
  !! @param LHS: Left hand operator.
  !! @param RHS: Right hand operator. 
  !*****************************************************************************************************!  
  ELEMENTAL FUNCTION ONUMM2N2_MUL_ONUMM2N2(LHS, RHS) &
    RESULT(RES)
    IMPLICIT NONE
    TYPE(ONUM_M2N2), INTENT(IN) :: LHS, RHS
    TYPE(ONUM_M2N2) :: RES

    ! MULTIPLY ALL IMAGINARY DIRECTIONS.

    RES%R    = LHS%R*RHS%R  

    RES%E1   = LHS%E1*RHS%R + LHS%R*RHS%E1
    RES%E2   = LHS%E2*RHS%R + LHS%R*RHS%E2

    ! RES%E11  = LHS%E1*RHS%E1 + LHS%E11*RHS%R + LHS%R*RHS%E11
    ! RES%E12  = LHS%E1*RHS%E2 + LHS%E2*RHS%E1 + LHS%E12*RHS%R + LHS%R*RHS%E12
    ! RES%E22  = LHS%E2*RHS%E2 + LHS%E22*RHS%R + LHS%R*RHS%E22

  END FUNCTION ONUMM2N2_MUL_ONUMM2N2
  !*****************************************************************************************************!

  !*****************************************************************************************************!
  !> @brief Multiplication of OTI and REAL numbers. This function is ELEMENTAL.
  !!
  !! RES = LHS * RHS
  !!
  !! @param LHS: Left hand operator.
  !! @param RHS: Right hand operator. 
  !*****************************************************************************************************!
  ELEMENTAL FUNCTION ONUMM2N2_MUL_REAL(LHS, RHS) &
    RESULT(RES)
    IMPLICIT NONE
    TYPE(ONUM_M2N2), INTENT(IN) :: LHS
    REAL(DP), INTENT(IN) :: RHS
    TYPE(ONUM_M2N2) :: RES

    ! MULTIPLY ALL IMAGINARY DIRECTIONS.

    RES%R    = LHS%R*RHS

    RES%E1   = LHS%E1*RHS
    RES%E2   = LHS%E2*RHS

    RES%E11  = LHS%E11*RHS
    RES%E12  = LHS%E12*RHS
    RES%E22  = LHS%E22*RHS

  END FUNCTION ONUMM2N2_MUL_REAL
  !*****************************************************************************************************!

  !*****************************************************************************************************!
  !> @brief Multiplication of OTI and OTI numbers. This function is ELEMENTAL.
  !!
  !! RES = LHS * RHS
  !!
  !! @param LHS: Left hand operator.
  !! @param RHS: Right hand operator. 
  !*****************************************************************************************************!
  ELEMENTAL FUNCTION REAL_MUL_ONUMM2N2(LHS, RHS) &
    RESULT(RES)
    IMPLICIT NONE
    
    REAL(DP), INTENT(IN) :: LHS
    TYPE(ONUM_M2N2), INTENT(IN) :: RHS
    TYPE(ONUM_M2N2) :: RES

    ! MULTIPLY ALL IMAGINARY DIRECTIONS.

    RES%R    = LHS * RHS%R

    RES%E1   = LHS * RHS%E1
    RES%E2   = LHS * RHS%E2

    RES%E11  = LHS * RHS%E11
    RES%E12  = LHS * RHS%E12
    RES%E22  = LHS * RHS%E22

  END FUNCTION REAL_MUL_ONUMM2N2
  !*****************************************************************************************************!





  ! =====================================================================================================
  ! ----------------------------------------     DIVISION     -------------------------------------------
  ! =====================================================================================================
  !*****************************************************************************************************!
  !> @brief Division of OTI and REAL numbers. This function is ELEMENTAL.
  !!
  !! RES = LHS / RHS
  !!
  !! @param LHS: Left hand operator.
  !! @param RHS: Right hand operator. 
  !*****************************************************************************************************!
  ELEMENTAL FUNCTION ONUMM2N2_DIV_REAL(LHS, RHS) &
    RESULT(RES)
    IMPLICIT NONE
    TYPE(ONUM_M2N2), INTENT(IN) :: LHS
    REAL(DP), INTENT(IN) :: RHS
    TYPE(ONUM_M2N2) :: RES

    ! DIVIDE ALL IMAGINARY DIRECTIONS.

    RES%R    = LHS%R /RHS

    RES%E1   = LHS%E1/RHS
    RES%E2   = LHS%E2/RHS

    RES%E11  = LHS%E11/RHS
    RES%E12  = LHS%E12/RHS
    RES%E22  = LHS%E22/RHS

  END FUNCTION ONUMM2N2_DIV_REAL
  !*****************************************************************************************************!

  !*****************************************************************************************************!
  !> @brief Division of OTI and OTI numbers.
  !!
  !! RES = LHS / RHS
  !!
  !! @param LHS: Left hand operator.
  !! @param RHS: Right hand operator. 
  !*****************************************************************************************************!
  FUNCTION ONUMM2N2_DIV_ONUMM2N2(LHS, RHS) &
    RESULT(RES)
    IMPLICIT NONE
    TYPE(ONUM_M2N2), INTENT(IN) :: LHS
    TYPE(ONUM_M2N2), INTENT(IN) :: RHS
    TYPE(ONUM_M2N2) :: RES

    ! DIVIDE ALL IMAGINARY DIRECTIONS.

    RES = LHS * ( RHS**(-1.0d0) )

  END FUNCTION ONUMM2N2_DIV_ONUMM2N2
  !*****************************************************************************************************!

  !*****************************************************************************************************!
  !> @brief Division of REAL and OTI numbers.
  !!
  !! RES = LHS / RHS
  !!
  !! @param LHS: Left hand operator.
  !! @param RHS: Right hand operator. 
  !*****************************************************************************************************!
  FUNCTION REAL_DIV_ONUMM2N2(LHS, RHS) &
    RESULT(RES)
    IMPLICIT NONE
    REAL(DP), INTENT(IN) :: LHS
    TYPE(ONUM_M2N2), INTENT(IN) :: RHS
    TYPE(ONUM_M2N2) :: RES

    ! DIVIDE ALL IMAGINARY DIRECTIONS.

    RES = LHS * ( RHS**(-1.0d0) )

  END FUNCTION REAL_DIV_ONUMM2N2
  !*****************************************************************************************************!









  ! =====================================================================================================
  ! -------------------------------     Trascendenal functions     --------------------------------------
  ! =====================================================================================================
  !*****************************************************************************************************!
  !> @brief Trascendental function evaluation of OTI numbers using Taylor series approach. This only 
  !! applies for single variable functions. e.g. sin(x), log(x), x**e, etc. Another function is necessary
  !! for multiple variable functions, such as x ** y, or x/y.
  !!
  !! @param DERIVS: Array with the derivatives of the function up to TORDER evaluated at X%R.
  !! @param X: Evaluation point (OTI).
  !*****************************************************************************************************!
  ! FUNCTION EVALUATION OF AN OTI NUMBER USING TRUNCATED TAYLOR SERIES.
  FUNCTION ONUMM2N2_FEVAL(DERIVS, X) &
    RESULT(RES)
    IMPLICIT NONE
    REAL(DP), INTENT(IN) :: DERIVS(:)
    TYPE(ONUM_M2N2), INTENT(IN) :: X
    TYPE(ONUM_M2N2) :: RES
    TYPE(ONUM_M2N2) :: DELTA
    TYPE(INTEGER)   :: I
    REAL(DP) :: FACTOR! = 1.0D0
    
    FACTOR    = 1.0D0

    ! MULTIPLY ALL IMAGINARY DIRECTIONS.
    DELTA = X

    ! DELTA HAS REAL DIRECTION EQUAL TO 0.
    DELTA%R = 0 ! DELTA = X - X%R

    RES = DERIVS(1) ! REAL COMPONENT.

    DO I = 1, TORDER
      
      FACTOR = FACTOR*I
      RES   = RES + (DERIVS(I+1)/FACTOR)*DELTA**(I)

    END DO
  
  END FUNCTION ONUMM2N2_FEVAL
  !*****************************************************************************************************!

  !*****************************************************************************************************!
  !> @brief Integer power of an OTI number. This function is ELEMENTAL.
  !!
  !! RES = NUM ** EXP
  !!
  !! @param NUM: Base (OTI).
  !! @param EXP: Exponent (INTEGER).
  !*****************************************************************************************************!
  ELEMENTAL FUNCTION ONUMM2N2_IPOW(NUM, EXP) &
    RESULT(RES)
    IMPLICIT NONE
    TYPE(ONUM_M2N2), INTENT(IN) :: NUM
    TYPE(INTEGER), INTENT(IN)   :: EXP
    TYPE(ONUM_M2N2) :: RES
    TYPE(INTEGER) :: I
    ! MULTIPLY ALL IMAGINARY DIRECTIONS.
    
    RES = NUM

    DO I = 2, EXP

      RES = RES * NUM

    END DO

  END FUNCTION ONUMM2N2_IPOW
  !*****************************************************************************************************!

  !*****************************************************************************************************!
  !> @brief Power function for OTI numbers.
  !!
  !! RES = NUM ** EXP
  !!
  !! @param NUM: Base (OTI).
  !! @param EXP: Exponent (REAL).
  !*****************************************************************************************************!
  FUNCTION ONUMM2N2_POW(NUM, EXP) &
    RESULT(RES)
    IMPLICIT NONE
    TYPE(ONUM_M2N2), INTENT(IN) :: NUM
    REAL(DP), INTENT(IN) :: EXP
    REAL(DP)             :: DERIVS(TORDER+1)
    TYPE(ONUM_M2N2) :: RES
    TYPE(INTEGER) :: I
    REAL(DP) :: FACTOR
    REAL(DP) :: X
    REAL(DP) :: EXPI

    FACTOR    = 1.0D0

    X         = NUM%R
    EXPI      = EXP

    DERIVS(1) = X**EXPI
    FACTOR = EXPI

    DO I = 1, TORDER

      DERIVS(I+1) = FACTOR * X**( EXPI - I )
      FACTOR = FACTOR*( EXPI - I )

    END DO    

    RES = ONUMM2N2_FEVAL(DERIVS,NUM)

  END FUNCTION ONUMM2N2_POW
  !*****************************************************************************************************!

  !*****************************************************************************************************!
  !> @brief Sine of OTI numbers.
  !!
  !! RES = SIN( NUM )
  !!
  !! @param NUM: Evaluation point (OTI).
  !*****************************************************************************************************!
  FUNCTION ONUMM2N2_SIN(NUM) &
    RESULT(RES)
    IMPLICIT NONE
    TYPE(ONUM_M2N2), INTENT(IN) :: NUM
    REAL(DP)             :: DERIVS(TORDER+1)
    TYPE(ONUM_M2N2) :: RES
    REAL(DP) :: X
    
    X         = NUM%R
    
    DERIVS(1) =  SIN(X) ! Function.
    DERIVS(2) =  COS(X) ! First Order derivative.
    DERIVS(3) = -SIN(X) ! Second Order derivative.

    RES = ONUMM2N2_FEVAL(DERIVS,NUM)

  END FUNCTION ONUMM2N2_SIN
  !*****************************************************************************************************!

  !*****************************************************************************************************!
  !> @brief Cosine of OTI numbers.
  !!
  !! RES = COS( NUM )
  !!
  !! @param NUM: Evaluation point (OTI).
  !*****************************************************************************************************!
  FUNCTION ONUMM2N2_COS(NUM) &
    RESULT(RES)
    IMPLICIT NONE
    TYPE(ONUM_M2N2), INTENT(IN) :: NUM
    REAL(DP)             :: DERIVS(TORDER+1)
    TYPE(ONUM_M2N2) :: RES
    REAL(DP) :: X
    
    X         = NUM%R
    
    DERIVS(1) =  COS(X) ! Function.
    DERIVS(2) = -SIN(X) ! First Order derivative.
    DERIVS(3) = -COS(X) ! Second Order derivative.

    RES = ONUMM2N2_FEVAL(DERIVS,NUM)

  END FUNCTION ONUMM2N2_COS
  !*****************************************************************************************************!



  







  ! ARRAY FUNCTIONS:
  !*****************************************************************************************************!
  SUBROUTINE ONUMM2N2_ARR_ASSIGN_REAL(RES, RHS)
    
    IMPLICIT NONE
    REAL(DP), INTENT(IN)  :: RHS
    TYPE(ONUM_M2N2), INTENT(OUT) :: RES(:,:)
    

    ! SET REAL PART AND ALL OTHER IMAGINARY DIRECTIONS AS 0.
    RES%R    = RHS 
    RES%E1   = 0.0D0
    RES%E2   = 0.0D0
    RES%E11  = 0.0D0
    RES%E12  = 0.0D0
    RES%E22  = 0.0D0

  END SUBROUTINE ONUMM2N2_ARR_ASSIGN_REAL
  !*****************************************************************************************************!

  !*****************************************************************************************************!
  !> @brief Pretty printing of scalar OTI type.
  !!
  !! @param ONUM: OTI number to be printed.
  !! @param FMT: Set floating point print format (optional). Default is 'ES11.3'. 
  !*****************************************************************************************************!
  SUBROUTINE ONUMM2N2_ARR_PRINT(OMAT,fmt)
    IMPLICIT NONE
    TYPE(ONUM_M2N2),  INTENT(IN) :: OMAT(:,:)
    CHARACTER(len=*), INTENT(IN), OPTIONAL :: fmt
    CHARACTER(len=:), ALLOCATABLE :: output_format
    INTEGER :: i,j

    IF (PRESENT(fmt)) THEN
      output_format = '(A,I4,A,I4,A,'//trim(fmt)//','// &
                           trim(fmt)//','// &
                           trim(fmt)//','// &
                           trim(fmt)//','// &
                           trim(fmt)//','// &
                           trim(fmt)//')'
    ELSE
      output_format = '(A,I4,A,I4,A,ES11.3,ES11.3,ES11.3,ES11.3,ES11.3,ES11.3)'
    END IF 


    DO i=1,SIZE(OMAT,1)
      DO j=1,SIZE(OMAT,2)
        ! PRINT CALL.
        write(*,output_format)  &
          '(',i,',',j,')', &
          OMAT(i,j)%R  ,        &
          OMAT(i,j)%E1 ,        &
          OMAT(i,j)%E2 ,        &
          OMAT(i,j)%E11,        &
          OMAT(i,j)%E12,        &
          OMAT(i,j)%E22

    END DO
  END DO

  END SUBROUTINE ONUMM2N2_ARR_PRINT
  !*****************************************************************************************************!

  !*****************************************************************************************************!
  !> @brief Matrix multiplication of OTI(:,:) and OTI(:,:) arrays.
  !!
  !! RES = MATMUL(LHS, RHS)
  !!
  !! @param LHS: Left hand operator.
  !! @param RHS: Right hand operator. 
  !*****************************************************************************************************!  
  FUNCTION ONUMM2N2_MATMUL_ONUMM2N2(LHS, RHS) &
    RESULT(RES)
    IMPLICIT NONE
    TYPE(ONUM_M2N2), INTENT(IN) :: LHS(:,:)
    TYPE(ONUM_M2N2), INTENT(IN) :: RHS(:,:)
    TYPE(ONUM_M2N2) :: TMP
    TYPE(ONUM_M2N2) :: RES( SIZE(LHS,1), SIZE(RHS,2) )
    REAL(DP) :: TMPLHS(SIZE(LHS,1), SIZE(LHS,2))
    REAL(DP) :: TMPRHS(SIZE(RHS,1), SIZE(RHS,2))
    INTEGER :: I, J, K
    
    ! Dimension check
    IF (SIZE(LHS,2) /= SIZE(RHS,1)) THEN
      STOP "Runtime error: " // &
        "Dimension mismatch in MATMUL."
    END IF


    ! Loop implementation

    DO I = 1, SIZE(LHS,1)

      DO J = 1, SIZE(RHS,2)

        TMP = 0.0d0

        DO  K = 1, SIZE(LHS,2)

          TMP = TMP + LHS( I, K )*RHS( K, J )

        END DO

        RES( I, J ) = TMP

      END DO

    END DO

    ! TMPLHS   = LHS%R
    ! TMPRHS   = RHS%R
    ! RES%R    = MATMUL(TMPLHS,TMPRHS)
    
    ! TMPLHS   = LHS%E1
    ! TMPRHS   = RHS%R
    ! RES%E1   = MATMUL(TMPLHS,TMPRHS) 
    
    ! ! MATMUL(LHS%R,  RHS%E1)
    ! TMPLHS   = LHS%R
    ! TMPRHS   = RHS%E1
    ! RES%E1   = RES%E1 + MATMUL(TMPLHS,TMPRHS)

    ! ! MATMUL(LHS%E2,RHS%R )
    ! TMPLHS = LHS%E2
    ! TMPRHS = RHS%R
    ! RES%E2 = MATMUL(TMPLHS,TMPRHS) 
    ! ! MATMUL(LHS%R,  RHS%E2)
    ! TMPLHS   = LHS%R
    ! TMPRHS   = RHS%E2
    ! RES%E2   = RES%E2 + MATMUL(TMPLHS,TMPRHS)
    


    ! ! MATMUL(LHS%E1,RHS%E1) 
    ! TMPLHS   = LHS%E1
    ! TMPRHS   = RHS%E1
    ! RES%E11  = MATMUL(TMPLHS,TMPRHS)

    ! ! MATMUL(LHS%E11,RHS%R ) 
    ! TMPLHS   = LHS%E11
    ! TMPRHS   = RHS%R
    ! RES%E11  = RES%E11 + MATMUL(TMPLHS,TMPRHS)

    ! ! MATMUL(LHS%R  ,RHS%E11)
    ! TMPLHS = LHS%R
    ! TMPRHS = RHS%E11
    ! RES%E11  = RES%E11 + MATMUL(TMPLHS,TMPRHS)

    

    ! RES%E12  = MATMUL(LHS%E1,RHS%E2) + MATMUL(LHS%E2, RHS%E1) + MATMUL(LHS%E12,RHS%R  ) + MATMUL(LHS%R  ,RHS%E12)
    ! ! MATMUL(LHS%E1,RHS%E2) 
    ! TMPLHS   = LHS%E2
    ! TMPRHS   = RHS%E1
    ! RES%E12  = MATMUL(TMPLHS,TMPRHS)

    ! ! MATMUL(LHS%E2,RHS%E1) 
    ! TMPLHS   = LHS%E1
    ! TMPRHS   = RHS%E2
    ! RES%E12  = RES%E12 + MATMUL(TMPLHS,TMPRHS)

    ! ! MATMUL(LHS%E12,RHS%R ) 
    ! TMPLHS   = LHS%E12
    ! TMPRHS   = RHS%R
    ! RES%E12  = RES%E12 + MATMUL(TMPLHS,TMPRHS)

    ! ! MATMUL(LHS%R  ,RHS%E12)
    ! TMPLHS = LHS%R
    ! TMPRHS = RHS%E12
    ! RES%E12  = RES%E12 + MATMUL(TMPLHS,TMPRHS)



    ! ! MATMUL(LHS%E2,RHS%E2) 
    ! TMPLHS   = LHS%E2
    ! TMPRHS   = RHS%E2
    ! RES%E22  = MATMUL(TMPLHS,TMPRHS)

    ! ! MATMUL(LHS%E22,RHS%R ) 
    ! TMPLHS   = LHS%E22
    ! TMPRHS   = RHS%R
    ! RES%E22  = RES%E22 + MATMUL(TMPLHS,TMPRHS)

    ! ! MATMUL(LHS%R  ,RHS%E11)
    ! TMPLHS = LHS%R
    ! TMPRHS = RHS%E22
    ! RES%E22  = RES%E22 + MATMUL(TMPLHS,TMPRHS)


    ! RES%R    = MATMUL(LHS%R,RHS%R)
    ! RES%E1   = MATMUL(LHS%E1,RHS%R ) + MATMUL(LHS%R,  RHS%E1)
    ! RES%E2   = MATMUL(LHS%E2,RHS%R ) + MATMUL(LHS%R,  RHS%E2)
    ! RES%E11  = MATMUL(LHS%E1,RHS%E1) + MATMUL(LHS%E11,RHS%R ) + MATMUL(LHS%R  ,RHS%E11)
    ! RES%E12  = MATMUL(LHS%E1,RHS%E2) + MATMUL(LHS%E2, RHS%E1) + MATMUL(LHS%E12,RHS%R  ) + MATMUL(LHS%R  ,RHS%E12)
    ! RES%E22  = MATMUL(LHS%E2,RHS%E2) + MATMUL(LHS%E22,RHS%R ) + MATMUL(LHS%R  ,RHS%E22)


  END FUNCTION ONUMM2N2_MATMUL_ONUMM2N2
  !*****************************************************************************************************!

  

! OMAT_M2N2_18x18
! OMAT_M2N2_18x18


  !*****************************************************************************************************!
  SUBROUTINE OMAT_M2N2_18x18_ARR_ASSIGN_REAL(RES, RHS)
    
    IMPLICIT NONE
    REAL(DP), INTENT(IN)  :: RHS
    TYPE(OMAT_M2N2_18x18), INTENT(OUT) :: RES
    

    ! SET REAL PART AND ALL OTHER IMAGINARY DIRECTIONS AS 0.
    RES%R    = RHS 
    RES%E1   = 0.0D0
    RES%E2   = 0.0D0
    RES%E11  = 0.0D0
    RES%E12  = 0.0D0
    RES%E22  = 0.0D0

  END SUBROUTINE OMAT_M2N2_18x18_ARR_ASSIGN_REAL
  !*****************************************************************************************************!


  
  !*****************************************************************************************************!
  !> @brief Matrix multiplication of OTI(:,:) and OTI(:,:) arrays.
  !!
  !! RES = MATMUL(LHS, RHS)
  !!
  !! @param LHS: Left hand operator.
  !! @param RHS: Right hand operator. 
  !*****************************************************************************************************!  
  FUNCTION OMAT_M2N2_18x18_MATMUL_OMAT_M2N2_18x18(LHS, RHS) &
    RESULT(RES)
    IMPLICIT NONE
    TYPE(OMAT_M2N2_18x18), INTENT(IN) :: LHS
    TYPE(OMAT_M2N2_18x18), INTENT(IN) :: RHS
    TYPE(OMAT_M2N2_18x18) :: RES
    ! TYPE(ONUM_M2N2) :: TMP
    ! INTEGER :: I, J, K
    
    ! Dimension check
    IF (SIZE(LHS%R,2) /= SIZE(RHS%R,1)) THEN
      STOP "Runtime error: " // &
        "Dimension mismatch in MATMUL."
    END IF


    ! Loop implementation

    ! DO I = 1, SIZE(LHS,1)

    !   DO J = 1, SIZE(RHS,2)

    !     TMP = 0.0d0

    !     DO  K = 1, SIZE(LHS,2)

    !       TMP = TMP + LHS( I, K )*RHS( K, J )

    !     END DO

    !     RES( I, J ) = TMP

    !   END DO

    ! END DO

    RES%R    = MATMUL(LHS%R,RHS%R)
    RES%E1   = MATMUL(LHS%E1,RHS%R ) + MATMUL(LHS%R,  RHS%E1)
    RES%E2   = MATMUL(LHS%E2,RHS%R ) + MATMUL(LHS%R,  RHS%E2)
    ! RES%E11  = MATMUL(LHS%E1,RHS%E1) + MATMUL(LHS%E11,RHS%R ) + MATMUL(LHS%R  ,RHS%E11)
    ! RES%E12  = MATMUL(LHS%E1,RHS%E2) + MATMUL(LHS%E2, RHS%E1) + MATMUL(LHS%E12,RHS%R  ) + MATMUL(LHS%R  ,RHS%E12)
    ! RES%E22  = MATMUL(LHS%E2,RHS%E2) + MATMUL(LHS%E22,RHS%R ) + MATMUL(LHS%R  ,RHS%E22)


  END FUNCTION OMAT_M2N2_18x18_MATMUL_OMAT_M2N2_18x18
  !*****************************************************************************************************!



END MODULE OTIM2N2