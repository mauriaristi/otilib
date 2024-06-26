MODULE OTIM2N3

  IMPLICIT NONE

  INTEGER, PARAMETER :: DP         = 8
  INTEGER, PARAMETER :: NUM_IM_DIR = 10
  INTEGER, PARAMETER :: TORDER     = 3

  TYPE ONUMM2N3
    ! Real
    REAL(DP) :: R
    ! Order 1
    REAL(DP) :: E1
    REAL(DP) :: E2
    ! Order 2
    REAL(DP) :: E11
    REAL(DP) :: E12
    REAL(DP) :: E22
    ! Order 3
    REAL(DP) :: E111
    REAL(DP) :: E112
    REAL(DP) :: E122
    REAL(DP) :: E222
  END TYPE ONUMM2N3

  INTERFACE OPERATOR(*)
    MODULE PROCEDURE ONUMM2N3_MUL_ONUMM2N3,R_MUL_ONUMM2N3,ONUMM2N3_MUL_R
  END INTERFACE

  INTERFACE OPERATOR(+)
    MODULE PROCEDURE ONUMM2N3_ADD_ONUMM2N3,R_ADD_ONUMM2N3,ONUMM2N3_ADD_R
  END INTERFACE

  INTERFACE OPERATOR(-)
    MODULE PROCEDURE ONUMM2N3_NEG,ONUMM2N3_SUB_ONUMM2N3,R_SUB_ONUMM2N3,ONUMM2N3_SUB_R
  END INTERFACE

  INTERFACE ASSIGNMENT(=)
    MODULE PROCEDURE ONUMM2N3_ASSIGN_R
  END INTERFACE

  INTERFACE TRANSPOSE
    MODULE PROCEDURE ONUMM2N3_TRANSPOSE
  END INTERFACE

  INTERFACE MATMUL
    MODULE PROCEDURE ONUMM2N3_MATMUL_ONUMM2N3,R_MATMUL_ONUMM2N3,ONUMM2N3_MATMUL_R
  END INTERFACE

  CONTAINS

  ELEMENTAL SUBROUTINE ONUMM2N3_ASSIGN_R(RES,LHS)
    
    IMPLICIT NONE
    REAL(DP), INTENT(IN) :: LHS 
    TYPE(ONUMM2N3), INTENT(OUT) :: RES 

    ! Assign like function 'LHS'
    ! Real
    RES%R = LHS
    ! Order 1
    RES%E1 = 0.0_dp
    RES%E2 = 0.0_dp
    ! Order 2
    RES%E11 = 0.0_dp
    RES%E12 = 0.0_dp
    RES%E22 = 0.0_dp
    ! Order 3
    RES%E111 = 0.0_dp
    RES%E112 = 0.0_dp
    RES%E122 = 0.0_dp
    RES%E222 = 0.0_dp

  END SUBROUTINE ONUMM2N3_ASSIGN_R

  ELEMENTAL FUNCTION ONUMM2N3_ADD_ONUMM2N3(LHS,RHS)&
    RESULT(RES)
    IMPLICIT NONE
    TYPE(ONUMM2N3), INTENT(IN) :: LHS 
    TYPE(ONUMM2N3), INTENT(IN) :: RHS 
    TYPE(ONUMM2N3) :: RES 

    ! Addition like function 'LHS + RHS'
    ! Real
    RES%R = LHS%R + RHS%R
    ! Order 1
    RES%E1 = LHS%E1 + RHS%E1
    RES%E2 = LHS%E2 + RHS%E2
    ! Order 2
    RES%E11 = LHS%E11 + RHS%E11
    RES%E12 = LHS%E12 + RHS%E12
    RES%E22 = LHS%E22 + RHS%E22
    ! Order 3
    RES%E111 = LHS%E111 + RHS%E111
    RES%E112 = LHS%E112 + RHS%E112
    RES%E122 = LHS%E122 + RHS%E122
    RES%E222 = LHS%E222 + RHS%E222

  END FUNCTION ONUMM2N3_ADD_ONUMM2N3

  ELEMENTAL FUNCTION R_ADD_ONUMM2N3(LHS,RHS)&
    RESULT(RES)
    IMPLICIT NONE
    REAL(DP), INTENT(IN) :: LHS 
    TYPE(ONUMM2N3), INTENT(IN) :: RHS 
    TYPE(ONUMM2N3) :: RES 

    ! Addition like function 'LHS + RHS'
    ! Real
    RES%R = LHS + RHS%R
    ! Order 1
    RES%E1 =  + RHS%E1
    RES%E2 =  + RHS%E2
    ! Order 2
    RES%E11 =  + RHS%E11
    RES%E12 =  + RHS%E12
    RES%E22 =  + RHS%E22
    ! Order 3
    RES%E111 =  + RHS%E111
    RES%E112 =  + RHS%E112
    RES%E122 =  + RHS%E122
    RES%E222 =  + RHS%E222

  END FUNCTION R_ADD_ONUMM2N3

  ELEMENTAL FUNCTION ONUMM2N3_ADD_R(LHS,RHS)&
    RESULT(RES)
    IMPLICIT NONE
    TYPE(ONUMM2N3), INTENT(IN) :: LHS 
    REAL(DP), INTENT(IN) :: RHS 
    TYPE(ONUMM2N3) :: RES 

    ! Addition like function 'LHS + RHS'
    ! Real
    RES%R = LHS%R + RHS
    ! Order 1
    RES%E1 = LHS%E1
    RES%E2 = LHS%E2
    ! Order 2
    RES%E11 = LHS%E11
    RES%E12 = LHS%E12
    RES%E22 = LHS%E22
    ! Order 3
    RES%E111 = LHS%E111
    RES%E112 = LHS%E112
    RES%E122 = LHS%E122
    RES%E222 = LHS%E222

  END FUNCTION ONUMM2N3_ADD_R

  ELEMENTAL FUNCTION ONUMM2N3_NEG(LHS)&
    RESULT(RES)
    IMPLICIT NONE
    TYPE(ONUMM2N3), INTENT(IN) :: LHS 
    TYPE(ONUMM2N3) :: RES 

    ! Negation like function '-LHS'
    ! Real
    RES%R = -LHS%R
    ! Order 1
    RES%E1 = -LHS%E1
    RES%E2 = -LHS%E2
    ! Order 2
    RES%E11 = -LHS%E11
    RES%E12 = -LHS%E12
    RES%E22 = -LHS%E22
    ! Order 3
    RES%E111 = -LHS%E111
    RES%E112 = -LHS%E112
    RES%E122 = -LHS%E122
    RES%E222 = -LHS%E222

  END FUNCTION ONUMM2N3_NEG

  ELEMENTAL FUNCTION ONUMM2N3_SUB_ONUMM2N3(LHS,RHS)&
    RESULT(RES)
    IMPLICIT NONE
    TYPE(ONUMM2N3), INTENT(IN) :: LHS 
    TYPE(ONUMM2N3), INTENT(IN) :: RHS 
    TYPE(ONUMM2N3) :: RES 

    ! Addition like function 'LHS - RHS'
    ! Real
    RES%R = LHS%R - RHS%R
    ! Order 1
    RES%E1 = LHS%E1 - RHS%E1
    RES%E2 = LHS%E2 - RHS%E2
    ! Order 2
    RES%E11 = LHS%E11 - RHS%E11
    RES%E12 = LHS%E12 - RHS%E12
    RES%E22 = LHS%E22 - RHS%E22
    ! Order 3
    RES%E111 = LHS%E111 - RHS%E111
    RES%E112 = LHS%E112 - RHS%E112
    RES%E122 = LHS%E122 - RHS%E122
    RES%E222 = LHS%E222 - RHS%E222

  END FUNCTION ONUMM2N3_SUB_ONUMM2N3

  ELEMENTAL FUNCTION R_SUB_ONUMM2N3(LHS,RHS)&
    RESULT(RES)
    IMPLICIT NONE
    REAL(DP), INTENT(IN) :: LHS 
    TYPE(ONUMM2N3), INTENT(IN) :: RHS 
    TYPE(ONUMM2N3) :: RES 

    ! Addition like function 'LHS - RHS'
    ! Real
    RES%R = LHS - RHS%R
    ! Order 1
    RES%E1 =  - RHS%E1
    RES%E2 =  - RHS%E2
    ! Order 2
    RES%E11 =  - RHS%E11
    RES%E12 =  - RHS%E12
    RES%E22 =  - RHS%E22
    ! Order 3
    RES%E111 =  - RHS%E111
    RES%E112 =  - RHS%E112
    RES%E122 =  - RHS%E122
    RES%E222 =  - RHS%E222

  END FUNCTION R_SUB_ONUMM2N3

  ELEMENTAL FUNCTION ONUMM2N3_SUB_R(LHS,RHS)&
    RESULT(RES)
    IMPLICIT NONE
    TYPE(ONUMM2N3), INTENT(IN) :: LHS 
    REAL(DP), INTENT(IN) :: RHS 
    TYPE(ONUMM2N3) :: RES 

    ! Addition like function 'LHS - RHS'
    ! Real
    RES%R = LHS%R - RHS
    ! Order 1
    RES%E1 = LHS%E1
    RES%E2 = LHS%E2
    ! Order 2
    RES%E11 = LHS%E11
    RES%E12 = LHS%E12
    RES%E22 = LHS%E22
    ! Order 3
    RES%E111 = LHS%E111
    RES%E112 = LHS%E112
    RES%E122 = LHS%E122
    RES%E222 = LHS%E222

  END FUNCTION ONUMM2N3_SUB_R

  ELEMENTAL FUNCTION ONUMM2N3_MUL_ONUMM2N3(LHS,RHS)&
    RESULT(RES)
    IMPLICIT NONE
    TYPE(ONUMM2N3), INTENT(IN) :: LHS 
    TYPE(ONUMM2N3), INTENT(IN) :: RHS 
    TYPE(ONUMM2N3) :: RES 

    ! Multiplication like function 'LHS*RHS'
    ! Real
    RES%R = LHS%R*RHS%R
    ! Order 1
    RES%E1 = LHS%R*RHS%E1 + LHS%E1*RHS%R
    RES%E2 = LHS%R*RHS%E2 + LHS%E2*RHS%R
    ! Order 2
    RES%E11 = LHS%R*RHS%E11 + LHS%E11*RHS%R + LHS%E1*RHS%E1
    RES%E12 = LHS%R*RHS%E12 + LHS%E12*RHS%R + LHS%E1*RHS%E2 &
            + LHS%E2*RHS%E1
    RES%E22 = LHS%R*RHS%E22 + LHS%E22*RHS%R + LHS%E2*RHS%E2
    ! Order 3
    RES%E111 = LHS%R*RHS%E111 + LHS%E111*RHS%R + LHS%E1*RHS%E11
    RES%E112 = LHS%R*RHS%E112 + LHS%E112*RHS%R + LHS%E1*RHS%E12 &
             + LHS%E2*RHS%E11
    RES%E122 = LHS%R*RHS%E122 + LHS%E122*RHS%R + LHS%E1*RHS%E22 &
             + LHS%E2*RHS%E12
    RES%E222 = LHS%R*RHS%E222 + LHS%E222*RHS%R + LHS%E2*RHS%E22

  END FUNCTION ONUMM2N3_MUL_ONUMM2N3

  ELEMENTAL FUNCTION R_MUL_ONUMM2N3(LHS,RHS)&
    RESULT(RES)
    IMPLICIT NONE
    REAL(DP), INTENT(IN) :: LHS 
    TYPE(ONUMM2N3), INTENT(IN) :: RHS 
    TYPE(ONUMM2N3) :: RES 

    ! Multiplication like function 'LHS*RHS'
    ! Real
    RES%R = LHS*RHS%R
    ! Order 1
    RES%E1 = LHS*RHS%E1
    RES%E2 = LHS*RHS%E2
    ! Order 2
    RES%E11 = LHS*RHS%E11
    RES%E12 = LHS*RHS%E12
    RES%E22 = LHS*RHS%E22
    ! Order 3
    RES%E111 = LHS*RHS%E111
    RES%E112 = LHS*RHS%E112
    RES%E122 = LHS*RHS%E122
    RES%E222 = LHS*RHS%E222

  END FUNCTION R_MUL_ONUMM2N3

  ELEMENTAL FUNCTION ONUMM2N3_MUL_R(LHS,RHS)&
    RESULT(RES)
    IMPLICIT NONE
    TYPE(ONUMM2N3), INTENT(IN) :: LHS 
    REAL(DP), INTENT(IN) :: RHS 
    TYPE(ONUMM2N3) :: RES 

    ! Multiplication like function 'LHS*RHS'
    ! Real
    RES%R = LHS%R*RHS
    ! Order 1
    RES%E1 = LHS%E1*RHS
    RES%E2 = LHS%E2*RHS
    ! Order 2
    RES%E11 = LHS%E11*RHS
    RES%E12 = LHS%E12*RHS
    RES%E22 = LHS%E22*RHS
    ! Order 3
    RES%E111 = LHS%E111*RHS
    RES%E112 = LHS%E112*RHS
    RES%E122 = LHS%E122*RHS
    RES%E222 = LHS%E222*RHS

  END FUNCTION ONUMM2N3_MUL_R

  FUNCTION ONUMM2N3_MATMUL_ONUMM2N3(LHS,RHS)&
    RESULT(RES)
    IMPLICIT NONE
    TYPE(ONUMM2N3), INTENT(IN) :: LHS(:,:) 
    TYPE(ONUMM2N3), INTENT(IN) :: RHS(:,:) 
    TYPE(ONUMM2N3) :: TMP 
    TYPE(ONUMM2N3) :: RES(SIZE(LHS,1),SIZE(RHS,2)) 
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

  END FUNCTION ONUMM2N3_MATMUL_ONUMM2N3

  FUNCTION R_MATMUL_ONUMM2N3(LHS,RHS)&
    RESULT(RES)
    IMPLICIT NONE
    REAL(DP), INTENT(IN) :: LHS(:,:) 
    TYPE(ONUMM2N3), INTENT(IN) :: RHS(:,:) 
    TYPE(ONUMM2N3) :: TMP 
    TYPE(ONUMM2N3) :: RES(SIZE(LHS,1),SIZE(RHS,2)) 
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

  END FUNCTION R_MATMUL_ONUMM2N3

  FUNCTION ONUMM2N3_MATMUL_R(LHS,RHS)&
    RESULT(RES)
    IMPLICIT NONE
    TYPE(ONUMM2N3), INTENT(IN) :: LHS(:,:) 
    REAL(DP), INTENT(IN) :: RHS(:,:) 
    TYPE(ONUMM2N3) :: TMP 
    TYPE(ONUMM2N3) :: RES(SIZE(LHS,1),SIZE(RHS,2)) 
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

  END FUNCTION ONUMM2N3_MATMUL_R

  FUNCTION ONUMM2N3_TRANSPOSE(LHS)&
    RESULT(RES)
    IMPLICIT NONE
    TYPE(ONUMM2N3), INTENT(IN) :: LHS(:,:) 
    TYPE(ONUMM2N3) :: RES(SIZE(LHS,2),SIZE(LHS,1)) 
    INTEGER :: I,J 

    DO I = 1, SIZE(LHS,1)
      DO J = 1, SIZE(LHS,2)
        RES( J, I ) = LHS( I, J )
      END DO
    END DO

  END FUNCTION ONUMM2N3_TRANSPOSE

END MODULE OTIM2N3
