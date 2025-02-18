MODULE OTIM2N1

  IMPLICIT NONE

  INTEGER, PARAMETER :: DP         = 8
  INTEGER, PARAMETER :: NUM_IM_DIR = 3
  INTEGER, PARAMETER :: TORDER     = 1

  TYPE ONUMM2N1
    ! Real
    REAL(DP) :: R
    ! Order 1
    REAL(DP) :: E1
    REAL(DP) :: E2
  END TYPE ONUMM2N1

  INTERFACE OPERATOR(*)
    MODULE PROCEDURE ONUMM2N1_MUL_ONUMM2N1,R_MUL_ONUMM2N1,ONUMM2N1_MUL_R
  END INTERFACE

  INTERFACE OPERATOR(+)
    MODULE PROCEDURE ONUMM2N1_ADD_ONUMM2N1,R_ADD_ONUMM2N1,ONUMM2N1_ADD_R
  END INTERFACE

  INTERFACE OPERATOR(-)
    MODULE PROCEDURE ONUMM2N1_NEG,ONUMM2N1_SUB_ONUMM2N1,R_SUB_ONUMM2N1,ONUMM2N1_SUB_R
  END INTERFACE

  INTERFACE ASSIGNMENT(=)
    MODULE PROCEDURE ONUMM2N1_ASSIGN_R
  END INTERFACE

  INTERFACE TRANSPOSE
    MODULE PROCEDURE ONUMM2N1_TRANSPOSE
  END INTERFACE

  INTERFACE MATMUL
    MODULE PROCEDURE ONUMM2N1_MATMUL_ONUMM2N1,R_MATMUL_ONUMM2N1,ONUMM2N1_MATMUL_R
  END INTERFACE

  CONTAINS

  ELEMENTAL SUBROUTINE ONUMM2N1_ASSIGN_R(RES,LHS)
    
    IMPLICIT NONE
    REAL(DP), INTENT(IN) :: LHS 
    TYPE(ONUMM2N1), INTENT(OUT) :: RES 

    ! Assign like function 'LHS'
    ! Real
    RES%R = LHS
    ! Order 1
    RES%E1 = 0.0_dp
    RES%E2 = 0.0_dp

  END SUBROUTINE ONUMM2N1_ASSIGN_R

  ELEMENTAL FUNCTION ONUMM2N1_ADD_ONUMM2N1(LHS,RHS)&
    RESULT(RES)
    IMPLICIT NONE
    TYPE(ONUMM2N1), INTENT(IN) :: LHS 
    TYPE(ONUMM2N1), INTENT(IN) :: RHS 
    TYPE(ONUMM2N1) :: RES 

    ! Addition like function 'LHS + RHS'
    ! Real
    RES%R = LHS%R + RHS%R
    ! Order 1
    RES%E1 = LHS%E1 + RHS%E1
    RES%E2 = LHS%E2 + RHS%E2

  END FUNCTION ONUMM2N1_ADD_ONUMM2N1

  ELEMENTAL FUNCTION R_ADD_ONUMM2N1(LHS,RHS)&
    RESULT(RES)
    IMPLICIT NONE
    REAL(DP), INTENT(IN) :: LHS 
    TYPE(ONUMM2N1), INTENT(IN) :: RHS 
    TYPE(ONUMM2N1) :: RES 

    ! Addition like function 'LHS + RHS'
    ! Real
    RES%R = LHS + RHS%R
    ! Order 1
    RES%E1 =  + RHS%E1
    RES%E2 =  + RHS%E2

  END FUNCTION R_ADD_ONUMM2N1

  ELEMENTAL FUNCTION ONUMM2N1_ADD_R(LHS,RHS)&
    RESULT(RES)
    IMPLICIT NONE
    TYPE(ONUMM2N1), INTENT(IN) :: LHS 
    REAL(DP), INTENT(IN) :: RHS 
    TYPE(ONUMM2N1) :: RES 

    ! Addition like function 'LHS + RHS'
    ! Real
    RES%R = LHS%R + RHS
    ! Order 1
    RES%E1 = LHS%E1
    RES%E2 = LHS%E2

  END FUNCTION ONUMM2N1_ADD_R

  ELEMENTAL FUNCTION ONUMM2N1_NEG(LHS)&
    RESULT(RES)
    IMPLICIT NONE
    TYPE(ONUMM2N1), INTENT(IN) :: LHS 
    TYPE(ONUMM2N1) :: RES 

    ! Negation like function '-LHS'
    ! Real
    RES%R = -LHS%R
    ! Order 1
    RES%E1 = -LHS%E1
    RES%E2 = -LHS%E2

  END FUNCTION ONUMM2N1_NEG

  ELEMENTAL FUNCTION ONUMM2N1_SUB_ONUMM2N1(LHS,RHS)&
    RESULT(RES)
    IMPLICIT NONE
    TYPE(ONUMM2N1), INTENT(IN) :: LHS 
    TYPE(ONUMM2N1), INTENT(IN) :: RHS 
    TYPE(ONUMM2N1) :: RES 

    ! Addition like function 'LHS - RHS'
    ! Real
    RES%R = LHS%R - RHS%R
    ! Order 1
    RES%E1 = LHS%E1 - RHS%E1
    RES%E2 = LHS%E2 - RHS%E2

  END FUNCTION ONUMM2N1_SUB_ONUMM2N1

  ELEMENTAL FUNCTION R_SUB_ONUMM2N1(LHS,RHS)&
    RESULT(RES)
    IMPLICIT NONE
    REAL(DP), INTENT(IN) :: LHS 
    TYPE(ONUMM2N1), INTENT(IN) :: RHS 
    TYPE(ONUMM2N1) :: RES 

    ! Addition like function 'LHS - RHS'
    ! Real
    RES%R = LHS - RHS%R
    ! Order 1
    RES%E1 =  - RHS%E1
    RES%E2 =  - RHS%E2

  END FUNCTION R_SUB_ONUMM2N1

  ELEMENTAL FUNCTION ONUMM2N1_SUB_R(LHS,RHS)&
    RESULT(RES)
    IMPLICIT NONE
    TYPE(ONUMM2N1), INTENT(IN) :: LHS 
    REAL(DP), INTENT(IN) :: RHS 
    TYPE(ONUMM2N1) :: RES 

    ! Addition like function 'LHS - RHS'
    ! Real
    RES%R = LHS%R - RHS
    ! Order 1
    RES%E1 = LHS%E1
    RES%E2 = LHS%E2

  END FUNCTION ONUMM2N1_SUB_R

  ELEMENTAL FUNCTION ONUMM2N1_MUL_ONUMM2N1(LHS,RHS)&
    RESULT(RES)
    IMPLICIT NONE
    TYPE(ONUMM2N1), INTENT(IN) :: LHS 
    TYPE(ONUMM2N1), INTENT(IN) :: RHS 
    TYPE(ONUMM2N1) :: RES 

    ! Multiplication like function 'LHS*RHS'
    ! Real
    RES%R = LHS%R*RHS%R
    ! Order 1
    RES%E1 = LHS%R*RHS%E1 + LHS%E1*RHS%R
    RES%E2 = LHS%R*RHS%E2 + LHS%E2*RHS%R

  END FUNCTION ONUMM2N1_MUL_ONUMM2N1

  ELEMENTAL FUNCTION R_MUL_ONUMM2N1(LHS,RHS)&
    RESULT(RES)
    IMPLICIT NONE
    REAL(DP), INTENT(IN) :: LHS 
    TYPE(ONUMM2N1), INTENT(IN) :: RHS 
    TYPE(ONUMM2N1) :: RES 

    ! Multiplication like function 'LHS*RHS'
    ! Real
    RES%R = LHS*RHS%R
    ! Order 1
    RES%E1 = LHS*RHS%E1
    RES%E2 = LHS*RHS%E2

  END FUNCTION R_MUL_ONUMM2N1

  ELEMENTAL FUNCTION ONUMM2N1_MUL_R(LHS,RHS)&
    RESULT(RES)
    IMPLICIT NONE
    TYPE(ONUMM2N1), INTENT(IN) :: LHS 
    REAL(DP), INTENT(IN) :: RHS 
    TYPE(ONUMM2N1) :: RES 

    ! Multiplication like function 'LHS*RHS'
    ! Real
    RES%R = LHS%R*RHS
    ! Order 1
    RES%E1 = LHS%E1*RHS
    RES%E2 = LHS%E2*RHS

  END FUNCTION ONUMM2N1_MUL_R

  FUNCTION ONUMM2N1_MATMUL_ONUMM2N1(LHS,RHS)&
    RESULT(RES)
    IMPLICIT NONE
    TYPE(ONUMM2N1), INTENT(IN) :: LHS(:,:) 
    TYPE(ONUMM2N1), INTENT(IN) :: RHS(:,:) 
    TYPE(ONUMM2N1) :: TMP 
    TYPE(ONUMM2N1) :: RES(SIZE(LHS,1),SIZE(RHS,2)) 
    INTEGER :: I,J,K 

    ! Dimension check
    IF (SIZE(LHS,2) /= SIZE(RHS,1)) THEN
      STOP "Runtime error: " // &
           "Dimension mismatch in MATMUL."
    END IF
    DO I = 1, SIZE(LHS,1)
      DO J = 1, SIZE(RHS,2)
        TMP = 0.0_DP
        DO K = 1, SIZE(LHS,2)
          TMP = TMP + LHS( I, K )*RHS( K, J )
        END DO
        RES( I, J ) = TMP
      END DO
    END DO

  END FUNCTION ONUMM2N1_MATMUL_ONUMM2N1

  FUNCTION R_MATMUL_ONUMM2N1(LHS,RHS)&
    RESULT(RES)
    IMPLICIT NONE
    REAL(DP), INTENT(IN) :: LHS(:,:) 
    TYPE(ONUMM2N1), INTENT(IN) :: RHS(:,:) 
    TYPE(ONUMM2N1) :: TMP 
    TYPE(ONUMM2N1) :: RES(SIZE(LHS,1),SIZE(RHS,2)) 
    INTEGER :: I,J,K 

    ! Dimension check
    IF (SIZE(LHS,2) /= SIZE(RHS,1)) THEN
      STOP "Runtime error: " // &
           "Dimension mismatch in MATMUL."
    END IF
    DO I = 1, SIZE(LHS,1)
      DO J = 1, SIZE(RHS,2)
        TMP = 0.0_DP
        DO K = 1, SIZE(LHS,2)
          TMP = TMP + LHS( I, K )*RHS( K, J )
        END DO
        RES( I, J ) = TMP
      END DO
    END DO

  END FUNCTION R_MATMUL_ONUMM2N1

  FUNCTION ONUMM2N1_MATMUL_R(LHS,RHS)&
    RESULT(RES)
    IMPLICIT NONE
    TYPE(ONUMM2N1), INTENT(IN) :: LHS(:,:) 
    REAL(DP), INTENT(IN) :: RHS(:,:) 
    TYPE(ONUMM2N1) :: TMP 
    TYPE(ONUMM2N1) :: RES(SIZE(LHS,1),SIZE(RHS,2)) 
    INTEGER :: I,J,K 

    ! Dimension check
    IF (SIZE(LHS,2) /= SIZE(RHS,1)) THEN
      STOP "Runtime error: " // &
           "Dimension mismatch in MATMUL."
    END IF
    DO I = 1, SIZE(LHS,1)
      DO J = 1, SIZE(RHS,2)
        TMP = 0.0_DP
        DO K = 1, SIZE(LHS,2)
          TMP = TMP + LHS( I, K )*RHS( K, J )
        END DO
        RES( I, J ) = TMP
      END DO
    END DO

  END FUNCTION ONUMM2N1_MATMUL_R

  FUNCTION ONUMM2N1_TRANSPOSE(LHS)&
    RESULT(RES)
    IMPLICIT NONE
    TYPE(ONUMM2N1), INTENT(IN) :: LHS(:,:) 
    TYPE(ONUMM2N1) :: RES(SIZE(LHS,2),SIZE(LHS,1)) 
    INTEGER :: I,J 

    DO I = 1, SIZE(LHS,1)
      DO J = 1, SIZE(LHS,2)
        RES( J, I ) = LHS( I, J )
      END DO
    END DO

  END FUNCTION ONUMM2N1_TRANSPOSE

END MODULE OTIM2N1
