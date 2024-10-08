MODULE OTIM1N4

   USE master_parameters
   USE real_utils

   IMPLICIT NONE

   INTEGER, PARAMETER :: NUM_IM_DIR = 5
   INTEGER, PARAMETER :: TORDER     = 4
   INTEGER, PARAMETER :: N_IMDIR_ORDER(5) = [1,1,1,1,1]

   TYPE ONUMM1N4
     ! Real
     REAL(DP) :: R
     ! Order 1
     REAL(DP) :: E1
     ! Order 2
     REAL(DP) :: E11
     ! Order 3
     REAL(DP) :: E111
     ! Order 4
     REAL(DP) :: E1111
   END TYPE ONUMM1N4

   ! Constant imaginary directions.
   ! Order 1
   TYPE(ONUMM1N4), PARAMETER :: E1 = ONUMM1N4(0.0_DP,1.0_DP,0.0_DP,0.0_DP,0.0_DP)
   ! Order 2
   TYPE(ONUMM1N4), PARAMETER :: E11 = ONUMM1N4(0.0_DP,0.0_DP,1.0_DP,0.0_DP,0.0_DP)
   ! Order 3
   TYPE(ONUMM1N4), PARAMETER :: E111 = ONUMM1N4(0.0_DP,0.0_DP,0.0_DP,1.0_DP,0.0_DP)
   ! Order 4
   TYPE(ONUMM1N4), PARAMETER :: E1111 = ONUMM1N4(0.0_DP,0.0_DP,0.0_DP,0.0_DP,1.0_DP)


   INTERFACE OPERATOR(*)
      MODULE PROCEDURE ONUMM1N4_MUL_OO_SS,ONUMM1N4_MUL_RO_SS,ONUMM1N4_MUL_OR_SS,ONUMM1N4_MUL_OO_VS,&
                       ONUMM1N4_MUL_RO_VS,ONUMM1N4_MUL_OR_VS,ONUMM1N4_MUL_OO_MS,ONUMM1N4_MUL_RO_MS,&
                       ONUMM1N4_MUL_OR_MS,ONUMM1N4_MUL_OO_SV,ONUMM1N4_MUL_RO_SV,ONUMM1N4_MUL_OR_SV,&
                       ONUMM1N4_MUL_OO_SM,ONUMM1N4_MUL_RO_SM,ONUMM1N4_MUL_OR_SM
   END INTERFACE

   INTERFACE OPERATOR(+)
      MODULE PROCEDURE ONUMM1N4_ADD_OO_SS,ONUMM1N4_ADD_RO_SS,ONUMM1N4_ADD_OR_SS,ONUMM1N4_ADD_OO_VS,&
                       ONUMM1N4_ADD_RO_VS,ONUMM1N4_ADD_OR_VS,ONUMM1N4_ADD_OO_MS,ONUMM1N4_ADD_RO_MS,&
                       ONUMM1N4_ADD_OR_MS,ONUMM1N4_ADD_OO_SV,ONUMM1N4_ADD_RO_SV,ONUMM1N4_ADD_OR_SV,&
                       ONUMM1N4_ADD_OO_SM,ONUMM1N4_ADD_RO_SM,ONUMM1N4_ADD_OR_SM
   END INTERFACE

   INTERFACE OPERATOR(-)
      MODULE PROCEDURE ONUMM1N4_NEG,ONUMM1N4_SUB_OO_SS,ONUMM1N4_SUB_RO_SS,ONUMM1N4_SUB_OR_SS,&
                       ONUMM1N4_SUB_OO_VS,ONUMM1N4_SUB_RO_VS,ONUMM1N4_SUB_OR_VS,ONUMM1N4_SUB_OO_MS,&
                       ONUMM1N4_SUB_RO_MS,ONUMM1N4_SUB_OR_MS,ONUMM1N4_SUB_OO_SV,ONUMM1N4_SUB_RO_SV,&
                       ONUMM1N4_SUB_OR_SV,ONUMM1N4_SUB_OO_SM,ONUMM1N4_SUB_RO_SM,ONUMM1N4_SUB_OR_SM
   END INTERFACE

   INTERFACE OPERATOR(/)
      MODULE PROCEDURE ONUMM1N4_DIVISION_OO,ONUMM1N4_DIVISION_OR,ONUMM1N4_DIVISION_RO
   END INTERFACE

   INTERFACE ASSIGNMENT(=)
      MODULE PROCEDURE ONUMM1N4_ASSIGN_R
   END INTERFACE

   INTERFACE OPERATOR(**)
      MODULE PROCEDURE ONUMM1N4_POW_OR,ONUMM1N4_POW_RO,ONUMM1N4_POW_OO
   END INTERFACE

   INTERFACE PPRINT
      MODULE PROCEDURE ONUMM1N4_PPRINT_S,ONUMM1N4_PPRINT_V,ONUMM1N4_PPRINT_M
   END INTERFACE

   INTERFACE TRANSPOSE
      MODULE PROCEDURE ONUMM1N4_TRANSPOSE
   END INTERFACE

   INTERFACE MATMUL
      MODULE PROCEDURE ONUMM1N4_MATMUL_ONUMM1N4,R_MATMUL_ONUMM1N4,ONUMM1N4_MATMUL_R
   END INTERFACE

   INTERFACE DOT_PRODUCT
      MODULE PROCEDURE ONUMM1N4_DOT_PRODUCT_ONUMM1N4,R_DOT_PRODUCT_ONUMM1N4,ONUMM1N4_DOT_PRODUCT_R
   END INTERFACE

   INTERFACE UNFOLD
      MODULE PROCEDURE ONUMM1N4_TO_CR_MAT_S,ONUMM1N4_TO_CR_MAT_V,ONUMM1N4_TO_CR_MAT_M
   END INTERFACE

   INTERFACE TO_CR
      MODULE PROCEDURE ONUMM1N4_TO_CR_MAT_S,ONUMM1N4_TO_CR_MAT_V,ONUMM1N4_TO_CR_MAT_M
   END INTERFACE

   INTERFACE SIN
      MODULE PROCEDURE ONUMM1N4_SIN
   END INTERFACE

   INTERFACE COS
      MODULE PROCEDURE ONUMM1N4_COS
   END INTERFACE

   INTERFACE TAN
      MODULE PROCEDURE ONUMM1N4_TAN
   END INTERFACE

   INTERFACE ASIN
      MODULE PROCEDURE ONUMM1N4_ASIN
   END INTERFACE

   INTERFACE ACOS
      MODULE PROCEDURE ONUMM1N4_ACOS
   END INTERFACE

   INTERFACE ATAN
      MODULE PROCEDURE ONUMM1N4_ATAN
   END INTERFACE

   INTERFACE SINH
      MODULE PROCEDURE ONUMM1N4_SINH
   END INTERFACE

   INTERFACE COSH
      MODULE PROCEDURE ONUMM1N4_COSH
   END INTERFACE

   INTERFACE TANH
      MODULE PROCEDURE ONUMM1N4_TANH
   END INTERFACE

   INTERFACE SQRT
      MODULE PROCEDURE ONUMM1N4_SQRT
   END INTERFACE

   INTERFACE LOG
      MODULE PROCEDURE ONUMM1N4_LOG
   END INTERFACE

   INTERFACE EXP
      MODULE PROCEDURE ONUMM1N4_EXP
   END INTERFACE

   INTERFACE GEM
      MODULE PROCEDURE ONUMM1N4_GEM_OOO,ONUMM1N4_GEM_ROO,ONUMM1N4_GEM_ORO
   END INTERFACE

   INTERFACE FEVAL
      MODULE PROCEDURE ONUMM1N4_FEVAL
   END INTERFACE

   INTERFACE F2EVAL
      MODULE PROCEDURE ONUMM1N4_F2EVAL
   END INTERFACE

   INTERFACE REAL
      MODULE PROCEDURE ONUMM1N4_REAL
   END INTERFACE

   INTERFACE DET2X2
      MODULE PROCEDURE ONUMM1N4_det2x2
   END INTERFACE

   INTERFACE DET3X3
      MODULE PROCEDURE ONUMM1N4_det3x3
   END INTERFACE

   INTERFACE DET4X4
      MODULE PROCEDURE ONUMM1N4_det4x4
   END INTERFACE

   INTERFACE INV2X2
      MODULE PROCEDURE ONUMM1N4_INV2X2
   END INTERFACE

   INTERFACE INV3X3
      MODULE PROCEDURE ONUMM1N4_INV3X3
   END INTERFACE

   INTERFACE INV4X4
      MODULE PROCEDURE ONUMM1N4_INV4X4
   END INTERFACE

   INTERFACE GETIM
      MODULE PROCEDURE ONUMM1N4_GETIM_S,ONUMM1N4_GETIM_V,ONUMM1N4_GETIM_M
   END INTERFACE

   INTERFACE SETIM
      MODULE PROCEDURE ONUMM1N4_SETIM_S,ONUMM1N4_SETIM_V,ONUMM1N4_SETIM_M
   END INTERFACE

   CONTAINS

   ELEMENTAL SUBROUTINE ONUMM1N4_ASSIGN_R(RES,LHS)
      
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS 
      TYPE(ONUMM1N4), INTENT(OUT) :: RES 

      ! Assign like function 'LHS'
      ! Real
      RES%R = LHS

      ! Order 1
      RES%E1 = 0.0_DP

      ! Order 2
      RES%E11 = 0.0_DP

      ! Order 3
      RES%E111 = 0.0_DP

      ! Order 4
      RES%E1111 = 0.0_DP

   END SUBROUTINE ONUMM1N4_ASSIGN_R

   ELEMENTAL FUNCTION ONUMM1N4_NEG(LHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM1N4), INTENT(IN) :: LHS 
      TYPE(ONUMM1N4) :: RES 

      ! Negation like function '-LHS'
      ! Real
      RES%R = -LHS%R
      ! Order 1
      RES%E1 = -LHS%E1
      ! Order 2
      RES%E11 = -LHS%E11
      ! Order 3
      RES%E111 = -LHS%E111
      ! Order 4
      RES%E1111 = -LHS%E1111

   END FUNCTION ONUMM1N4_NEG

   ELEMENTAL FUNCTION ONUMM1N4_ADD_OO_SS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM1N4), INTENT(IN) :: LHS
      TYPE(ONUMM1N4), INTENT(IN) :: RHS
      TYPE(ONUMM1N4) :: RES 

      ! Addition like function 'LHS + RHS'
      !  Real
      RES%R = LHS%R + RHS%R

      ! Order 1
      RES%E1 = LHS%E1 + RHS%E1

      ! Order 2
      RES%E11 = LHS%E11 + RHS%E11

      ! Order 3
      RES%E111 = LHS%E111 + RHS%E111

      ! Order 4
      RES%E1111 = LHS%E1111 + RHS%E1111

   END FUNCTION ONUMM1N4_ADD_OO_SS

   ELEMENTAL FUNCTION ONUMM1N4_ADD_RO_SS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS
      TYPE(ONUMM1N4), INTENT(IN) :: RHS
      TYPE(ONUMM1N4) :: RES 

      ! Addition like function 'LHS + RHS'
      ! Real
      RES%R = LHS + RHS%R

      ! Order 1
      RES%E1 =  + RHS%E1

      ! Order 2
      RES%E11 =  + RHS%E11

      ! Order 3
      RES%E111 =  + RHS%E111

      ! Order 4
      RES%E1111 =  + RHS%E1111

   END FUNCTION ONUMM1N4_ADD_RO_SS

   ELEMENTAL FUNCTION ONUMM1N4_ADD_OR_SS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM1N4), INTENT(IN) :: LHS
      REAL(DP), INTENT(IN) :: RHS
      TYPE(ONUMM1N4) :: RES 

      ! Addition like function 'LHS + RHS'
      ! Real
      RES%R = LHS%R + RHS

      ! Order 1
      RES%E1 = LHS%E1

      ! Order 2
      RES%E11 = LHS%E11

      ! Order 3
      RES%E111 = LHS%E111

      ! Order 4
      RES%E1111 = LHS%E1111

   END FUNCTION ONUMM1N4_ADD_OR_SS

   ELEMENTAL FUNCTION ONUMM1N4_SUB_OO_SS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM1N4), INTENT(IN) :: LHS
      TYPE(ONUMM1N4), INTENT(IN) :: RHS
      TYPE(ONUMM1N4) :: RES 

      ! Addition like function 'LHS - RHS'
      !  Real
      RES%R = LHS%R - RHS%R

      ! Order 1
      RES%E1 = LHS%E1 - RHS%E1

      ! Order 2
      RES%E11 = LHS%E11 - RHS%E11

      ! Order 3
      RES%E111 = LHS%E111 - RHS%E111

      ! Order 4
      RES%E1111 = LHS%E1111 - RHS%E1111

   END FUNCTION ONUMM1N4_SUB_OO_SS

   ELEMENTAL FUNCTION ONUMM1N4_SUB_RO_SS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS
      TYPE(ONUMM1N4), INTENT(IN) :: RHS
      TYPE(ONUMM1N4) :: RES 

      ! Addition like function 'LHS - RHS'
      ! Real
      RES%R = LHS - RHS%R

      ! Order 1
      RES%E1 =  - RHS%E1

      ! Order 2
      RES%E11 =  - RHS%E11

      ! Order 3
      RES%E111 =  - RHS%E111

      ! Order 4
      RES%E1111 =  - RHS%E1111

   END FUNCTION ONUMM1N4_SUB_RO_SS

   ELEMENTAL FUNCTION ONUMM1N4_SUB_OR_SS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM1N4), INTENT(IN) :: LHS
      REAL(DP), INTENT(IN) :: RHS
      TYPE(ONUMM1N4) :: RES 

      ! Addition like function 'LHS - RHS'
      ! Real
      RES%R = LHS%R - RHS

      ! Order 1
      RES%E1 = LHS%E1

      ! Order 2
      RES%E11 = LHS%E11

      ! Order 3
      RES%E111 = LHS%E111

      ! Order 4
      RES%E1111 = LHS%E1111

   END FUNCTION ONUMM1N4_SUB_OR_SS

   ELEMENTAL FUNCTION ONUMM1N4_MUL_OO_SS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM1N4), INTENT(IN) :: LHS
      TYPE(ONUMM1N4), INTENT(IN) :: RHS
      TYPE(ONUMM1N4) :: RES 

      !  Multiplication like function 'LHS*RHS'
      ! Order 4
      RES%E1111 = LHS%R*RHS%E1111 + LHS%E1111*RHS%R +  &
               LHS%E1*RHS%E111 + LHS%E111*RHS%E1 + LHS%E11*RHS%E11
      ! Order 3
      RES%E111 = LHS%R*RHS%E111 + LHS%E111*RHS%R +  &
              LHS%E1*RHS%E11 + LHS%E11*RHS%E1
      ! Order 2
      RES%E11 = LHS%R*RHS%E11 + LHS%E11*RHS%R + LHS%E1*RHS%E1
      ! Order 1
      RES%E1 = LHS%R*RHS%E1 + LHS%E1*RHS%R
      ! Order 0
      RES%R = LHS%R*RHS%R

   END FUNCTION ONUMM1N4_MUL_OO_SS

   ELEMENTAL FUNCTION ONUMM1N4_MUL_RO_SS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS
      TYPE(ONUMM1N4), INTENT(IN) :: RHS
      TYPE(ONUMM1N4) :: RES 

      ! Multiplication like function 'LHS*RHS'
      !  Real
      RES%R = LHS*RHS%R

      ! Order 1
      RES%E1 = LHS*RHS%E1

      ! Order 2
      RES%E11 = LHS*RHS%E11

      ! Order 3
      RES%E111 = LHS*RHS%E111

      ! Order 4
      RES%E1111 = LHS*RHS%E1111

   END FUNCTION ONUMM1N4_MUL_RO_SS

   ELEMENTAL FUNCTION ONUMM1N4_MUL_OR_SS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM1N4), INTENT(IN) :: LHS
      REAL(DP), INTENT(IN) :: RHS
      TYPE(ONUMM1N4) :: RES 

      ! Multiplication like function 'LHS*RHS'
      !  Real
      RES%R = LHS%R*RHS

      ! Order 1
      RES%E1 = LHS%E1*RHS

      ! Order 2
      RES%E11 = LHS%E11*RHS

      ! Order 3
      RES%E111 = LHS%E111*RHS

      ! Order 4
      RES%E1111 = LHS%E1111*RHS

   END FUNCTION ONUMM1N4_MUL_OR_SS

   FUNCTION ONUMM1N4_ADD_OO_VS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM1N4), INTENT(IN) :: LHS(:)
      TYPE(ONUMM1N4), INTENT(IN) :: RHS
      TYPE(ONUMM1N4) :: RES(SIZE(LHS,1)) 

      ! Addition like function 'LHS + RHS'
      !  Real
      RES%R = LHS%R + RHS%R

      ! Order 1
      RES%E1 = LHS%E1 + RHS%E1

      ! Order 2
      RES%E11 = LHS%E11 + RHS%E11

      ! Order 3
      RES%E111 = LHS%E111 + RHS%E111

      ! Order 4
      RES%E1111 = LHS%E1111 + RHS%E1111

   END FUNCTION ONUMM1N4_ADD_OO_VS

   FUNCTION ONUMM1N4_ADD_RO_VS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS(:)
      TYPE(ONUMM1N4), INTENT(IN) :: RHS
      TYPE(ONUMM1N4) :: RES(SIZE(LHS,1)) 

      ! Addition like function 'LHS + RHS'
      ! Real
      RES%R = LHS + RHS%R

      ! Order 1
      RES%E1 =  + RHS%E1

      ! Order 2
      RES%E11 =  + RHS%E11

      ! Order 3
      RES%E111 =  + RHS%E111

      ! Order 4
      RES%E1111 =  + RHS%E1111

   END FUNCTION ONUMM1N4_ADD_RO_VS

   FUNCTION ONUMM1N4_ADD_OR_VS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM1N4), INTENT(IN) :: LHS(:)
      REAL(DP), INTENT(IN) :: RHS
      TYPE(ONUMM1N4) :: RES(SIZE(LHS,1)) 

      ! Addition like function 'LHS + RHS'
      ! Real
      RES%R = LHS%R + RHS

      ! Order 1
      RES%E1 = LHS%E1

      ! Order 2
      RES%E11 = LHS%E11

      ! Order 3
      RES%E111 = LHS%E111

      ! Order 4
      RES%E1111 = LHS%E1111

   END FUNCTION ONUMM1N4_ADD_OR_VS

   FUNCTION ONUMM1N4_SUB_OO_VS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM1N4), INTENT(IN) :: LHS(:)
      TYPE(ONUMM1N4), INTENT(IN) :: RHS
      TYPE(ONUMM1N4) :: RES(SIZE(LHS,1)) 

      ! Addition like function 'LHS - RHS'
      !  Real
      RES%R = LHS%R - RHS%R

      ! Order 1
      RES%E1 = LHS%E1 - RHS%E1

      ! Order 2
      RES%E11 = LHS%E11 - RHS%E11

      ! Order 3
      RES%E111 = LHS%E111 - RHS%E111

      ! Order 4
      RES%E1111 = LHS%E1111 - RHS%E1111

   END FUNCTION ONUMM1N4_SUB_OO_VS

   FUNCTION ONUMM1N4_SUB_RO_VS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS(:)
      TYPE(ONUMM1N4), INTENT(IN) :: RHS
      TYPE(ONUMM1N4) :: RES(SIZE(LHS,1)) 

      ! Addition like function 'LHS - RHS'
      ! Real
      RES%R = LHS - RHS%R

      ! Order 1
      RES%E1 =  - RHS%E1

      ! Order 2
      RES%E11 =  - RHS%E11

      ! Order 3
      RES%E111 =  - RHS%E111

      ! Order 4
      RES%E1111 =  - RHS%E1111

   END FUNCTION ONUMM1N4_SUB_RO_VS

   FUNCTION ONUMM1N4_SUB_OR_VS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM1N4), INTENT(IN) :: LHS(:)
      REAL(DP), INTENT(IN) :: RHS
      TYPE(ONUMM1N4) :: RES(SIZE(LHS,1)) 

      ! Addition like function 'LHS - RHS'
      ! Real
      RES%R = LHS%R - RHS

      ! Order 1
      RES%E1 = LHS%E1

      ! Order 2
      RES%E11 = LHS%E11

      ! Order 3
      RES%E111 = LHS%E111

      ! Order 4
      RES%E1111 = LHS%E1111

   END FUNCTION ONUMM1N4_SUB_OR_VS

   FUNCTION ONUMM1N4_MUL_OO_VS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM1N4), INTENT(IN) :: LHS(:)
      TYPE(ONUMM1N4), INTENT(IN) :: RHS
      TYPE(ONUMM1N4) :: RES(SIZE(LHS,1)) 

      !  Multiplication like function 'LHS*RHS'
      ! Order 4
      RES%E1111 = LHS%R*RHS%E1111 + LHS%E1111*RHS%R +  &
               LHS%E1*RHS%E111 + LHS%E111*RHS%E1 + LHS%E11*RHS%E11
      ! Order 3
      RES%E111 = LHS%R*RHS%E111 + LHS%E111*RHS%R +  &
              LHS%E1*RHS%E11 + LHS%E11*RHS%E1
      ! Order 2
      RES%E11 = LHS%R*RHS%E11 + LHS%E11*RHS%R + LHS%E1*RHS%E1
      ! Order 1
      RES%E1 = LHS%R*RHS%E1 + LHS%E1*RHS%R
      ! Order 0
      RES%R = LHS%R*RHS%R

   END FUNCTION ONUMM1N4_MUL_OO_VS

   FUNCTION ONUMM1N4_MUL_RO_VS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS(:)
      TYPE(ONUMM1N4), INTENT(IN) :: RHS
      TYPE(ONUMM1N4) :: RES(SIZE(LHS,1)) 

      ! Multiplication like function 'LHS*RHS'
      !  Real
      RES%R = LHS*RHS%R

      ! Order 1
      RES%E1 = LHS*RHS%E1

      ! Order 2
      RES%E11 = LHS*RHS%E11

      ! Order 3
      RES%E111 = LHS*RHS%E111

      ! Order 4
      RES%E1111 = LHS*RHS%E1111

   END FUNCTION ONUMM1N4_MUL_RO_VS

   FUNCTION ONUMM1N4_MUL_OR_VS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM1N4), INTENT(IN) :: LHS(:)
      REAL(DP), INTENT(IN) :: RHS
      TYPE(ONUMM1N4) :: RES(SIZE(LHS,1)) 

      ! Multiplication like function 'LHS*RHS'
      !  Real
      RES%R = LHS%R*RHS

      ! Order 1
      RES%E1 = LHS%E1*RHS

      ! Order 2
      RES%E11 = LHS%E11*RHS

      ! Order 3
      RES%E111 = LHS%E111*RHS

      ! Order 4
      RES%E1111 = LHS%E1111*RHS

   END FUNCTION ONUMM1N4_MUL_OR_VS

   FUNCTION ONUMM1N4_ADD_OO_MS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM1N4), INTENT(IN) :: LHS(:,:)
      TYPE(ONUMM1N4), INTENT(IN) :: RHS
      TYPE(ONUMM1N4) :: RES(SIZE(LHS,1),SIZE(LHS,2)) 

      ! Addition like function 'LHS + RHS'
      !  Real
      RES%R = LHS%R + RHS%R

      ! Order 1
      RES%E1 = LHS%E1 + RHS%E1

      ! Order 2
      RES%E11 = LHS%E11 + RHS%E11

      ! Order 3
      RES%E111 = LHS%E111 + RHS%E111

      ! Order 4
      RES%E1111 = LHS%E1111 + RHS%E1111

   END FUNCTION ONUMM1N4_ADD_OO_MS

   FUNCTION ONUMM1N4_ADD_RO_MS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS(:,:)
      TYPE(ONUMM1N4), INTENT(IN) :: RHS
      TYPE(ONUMM1N4) :: RES(SIZE(LHS,1),SIZE(LHS,2)) 

      ! Addition like function 'LHS + RHS'
      ! Real
      RES%R = LHS + RHS%R

      ! Order 1
      RES%E1 =  + RHS%E1

      ! Order 2
      RES%E11 =  + RHS%E11

      ! Order 3
      RES%E111 =  + RHS%E111

      ! Order 4
      RES%E1111 =  + RHS%E1111

   END FUNCTION ONUMM1N4_ADD_RO_MS

   FUNCTION ONUMM1N4_ADD_OR_MS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM1N4), INTENT(IN) :: LHS(:,:)
      REAL(DP), INTENT(IN) :: RHS
      TYPE(ONUMM1N4) :: RES(SIZE(LHS,1),SIZE(LHS,2)) 

      ! Addition like function 'LHS + RHS'
      ! Real
      RES%R = LHS%R + RHS

      ! Order 1
      RES%E1 = LHS%E1

      ! Order 2
      RES%E11 = LHS%E11

      ! Order 3
      RES%E111 = LHS%E111

      ! Order 4
      RES%E1111 = LHS%E1111

   END FUNCTION ONUMM1N4_ADD_OR_MS

   FUNCTION ONUMM1N4_SUB_OO_MS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM1N4), INTENT(IN) :: LHS(:,:)
      TYPE(ONUMM1N4), INTENT(IN) :: RHS
      TYPE(ONUMM1N4) :: RES(SIZE(LHS,1),SIZE(LHS,2)) 

      ! Addition like function 'LHS - RHS'
      !  Real
      RES%R = LHS%R - RHS%R

      ! Order 1
      RES%E1 = LHS%E1 - RHS%E1

      ! Order 2
      RES%E11 = LHS%E11 - RHS%E11

      ! Order 3
      RES%E111 = LHS%E111 - RHS%E111

      ! Order 4
      RES%E1111 = LHS%E1111 - RHS%E1111

   END FUNCTION ONUMM1N4_SUB_OO_MS

   FUNCTION ONUMM1N4_SUB_RO_MS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS(:,:)
      TYPE(ONUMM1N4), INTENT(IN) :: RHS
      TYPE(ONUMM1N4) :: RES(SIZE(LHS,1),SIZE(LHS,2)) 

      ! Addition like function 'LHS - RHS'
      ! Real
      RES%R = LHS - RHS%R

      ! Order 1
      RES%E1 =  - RHS%E1

      ! Order 2
      RES%E11 =  - RHS%E11

      ! Order 3
      RES%E111 =  - RHS%E111

      ! Order 4
      RES%E1111 =  - RHS%E1111

   END FUNCTION ONUMM1N4_SUB_RO_MS

   FUNCTION ONUMM1N4_SUB_OR_MS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM1N4), INTENT(IN) :: LHS(:,:)
      REAL(DP), INTENT(IN) :: RHS
      TYPE(ONUMM1N4) :: RES(SIZE(LHS,1),SIZE(LHS,2)) 

      ! Addition like function 'LHS - RHS'
      ! Real
      RES%R = LHS%R - RHS

      ! Order 1
      RES%E1 = LHS%E1

      ! Order 2
      RES%E11 = LHS%E11

      ! Order 3
      RES%E111 = LHS%E111

      ! Order 4
      RES%E1111 = LHS%E1111

   END FUNCTION ONUMM1N4_SUB_OR_MS

   FUNCTION ONUMM1N4_MUL_OO_MS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM1N4), INTENT(IN) :: LHS(:,:)
      TYPE(ONUMM1N4), INTENT(IN) :: RHS
      TYPE(ONUMM1N4) :: RES(SIZE(LHS,1),SIZE(LHS,2)) 

      !  Multiplication like function 'LHS*RHS'
      ! Order 4
      RES%E1111 = LHS%R*RHS%E1111 + LHS%E1111*RHS%R +  &
               LHS%E1*RHS%E111 + LHS%E111*RHS%E1 + LHS%E11*RHS%E11
      ! Order 3
      RES%E111 = LHS%R*RHS%E111 + LHS%E111*RHS%R +  &
              LHS%E1*RHS%E11 + LHS%E11*RHS%E1
      ! Order 2
      RES%E11 = LHS%R*RHS%E11 + LHS%E11*RHS%R + LHS%E1*RHS%E1
      ! Order 1
      RES%E1 = LHS%R*RHS%E1 + LHS%E1*RHS%R
      ! Order 0
      RES%R = LHS%R*RHS%R

   END FUNCTION ONUMM1N4_MUL_OO_MS

   FUNCTION ONUMM1N4_MUL_RO_MS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS(:,:)
      TYPE(ONUMM1N4), INTENT(IN) :: RHS
      TYPE(ONUMM1N4) :: RES(SIZE(LHS,1),SIZE(LHS,2)) 

      ! Multiplication like function 'LHS*RHS'
      !  Real
      RES%R = LHS*RHS%R

      ! Order 1
      RES%E1 = LHS*RHS%E1

      ! Order 2
      RES%E11 = LHS*RHS%E11

      ! Order 3
      RES%E111 = LHS*RHS%E111

      ! Order 4
      RES%E1111 = LHS*RHS%E1111

   END FUNCTION ONUMM1N4_MUL_RO_MS

   FUNCTION ONUMM1N4_MUL_OR_MS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM1N4), INTENT(IN) :: LHS(:,:)
      REAL(DP), INTENT(IN) :: RHS
      TYPE(ONUMM1N4) :: RES(SIZE(LHS,1),SIZE(LHS,2)) 

      ! Multiplication like function 'LHS*RHS'
      !  Real
      RES%R = LHS%R*RHS

      ! Order 1
      RES%E1 = LHS%E1*RHS

      ! Order 2
      RES%E11 = LHS%E11*RHS

      ! Order 3
      RES%E111 = LHS%E111*RHS

      ! Order 4
      RES%E1111 = LHS%E1111*RHS

   END FUNCTION ONUMM1N4_MUL_OR_MS

   FUNCTION ONUMM1N4_ADD_OO_SV(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM1N4), INTENT(IN) :: LHS
      TYPE(ONUMM1N4), INTENT(IN) :: RHS(:)
      TYPE(ONUMM1N4) :: RES(SIZE(RHS,1)) 

      ! Addition like function 'LHS + RHS'
      !  Real
      RES%R = LHS%R + RHS%R

      ! Order 1
      RES%E1 = LHS%E1 + RHS%E1

      ! Order 2
      RES%E11 = LHS%E11 + RHS%E11

      ! Order 3
      RES%E111 = LHS%E111 + RHS%E111

      ! Order 4
      RES%E1111 = LHS%E1111 + RHS%E1111

   END FUNCTION ONUMM1N4_ADD_OO_SV

   FUNCTION ONUMM1N4_ADD_RO_SV(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS
      TYPE(ONUMM1N4), INTENT(IN) :: RHS(:)
      TYPE(ONUMM1N4) :: RES(SIZE(RHS,1)) 

      ! Addition like function 'LHS + RHS'
      ! Real
      RES%R = LHS + RHS%R

      ! Order 1
      RES%E1 =  + RHS%E1

      ! Order 2
      RES%E11 =  + RHS%E11

      ! Order 3
      RES%E111 =  + RHS%E111

      ! Order 4
      RES%E1111 =  + RHS%E1111

   END FUNCTION ONUMM1N4_ADD_RO_SV

   FUNCTION ONUMM1N4_ADD_OR_SV(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM1N4), INTENT(IN) :: LHS
      REAL(DP), INTENT(IN) :: RHS(:)
      TYPE(ONUMM1N4) :: RES(SIZE(RHS,1)) 

      ! Addition like function 'LHS + RHS'
      ! Real
      RES%R = LHS%R + RHS

      ! Order 1
      RES%E1 = LHS%E1

      ! Order 2
      RES%E11 = LHS%E11

      ! Order 3
      RES%E111 = LHS%E111

      ! Order 4
      RES%E1111 = LHS%E1111

   END FUNCTION ONUMM1N4_ADD_OR_SV

   FUNCTION ONUMM1N4_SUB_OO_SV(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM1N4), INTENT(IN) :: LHS
      TYPE(ONUMM1N4), INTENT(IN) :: RHS(:)
      TYPE(ONUMM1N4) :: RES(SIZE(RHS,1)) 

      ! Addition like function 'LHS - RHS'
      !  Real
      RES%R = LHS%R - RHS%R

      ! Order 1
      RES%E1 = LHS%E1 - RHS%E1

      ! Order 2
      RES%E11 = LHS%E11 - RHS%E11

      ! Order 3
      RES%E111 = LHS%E111 - RHS%E111

      ! Order 4
      RES%E1111 = LHS%E1111 - RHS%E1111

   END FUNCTION ONUMM1N4_SUB_OO_SV

   FUNCTION ONUMM1N4_SUB_RO_SV(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS
      TYPE(ONUMM1N4), INTENT(IN) :: RHS(:)
      TYPE(ONUMM1N4) :: RES(SIZE(RHS,1)) 

      ! Addition like function 'LHS - RHS'
      ! Real
      RES%R = LHS - RHS%R

      ! Order 1
      RES%E1 =  - RHS%E1

      ! Order 2
      RES%E11 =  - RHS%E11

      ! Order 3
      RES%E111 =  - RHS%E111

      ! Order 4
      RES%E1111 =  - RHS%E1111

   END FUNCTION ONUMM1N4_SUB_RO_SV

   FUNCTION ONUMM1N4_SUB_OR_SV(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM1N4), INTENT(IN) :: LHS
      REAL(DP), INTENT(IN) :: RHS(:)
      TYPE(ONUMM1N4) :: RES(SIZE(RHS,1)) 

      ! Addition like function 'LHS - RHS'
      ! Real
      RES%R = LHS%R - RHS

      ! Order 1
      RES%E1 = LHS%E1

      ! Order 2
      RES%E11 = LHS%E11

      ! Order 3
      RES%E111 = LHS%E111

      ! Order 4
      RES%E1111 = LHS%E1111

   END FUNCTION ONUMM1N4_SUB_OR_SV

   FUNCTION ONUMM1N4_MUL_OO_SV(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM1N4), INTENT(IN) :: LHS
      TYPE(ONUMM1N4), INTENT(IN) :: RHS(:)
      TYPE(ONUMM1N4) :: RES(SIZE(RHS,1)) 

      !  Multiplication like function 'LHS*RHS'
      ! Order 4
      RES%E1111 = LHS%R*RHS%E1111 + LHS%E1111*RHS%R +  &
               LHS%E1*RHS%E111 + LHS%E111*RHS%E1 + LHS%E11*RHS%E11
      ! Order 3
      RES%E111 = LHS%R*RHS%E111 + LHS%E111*RHS%R +  &
              LHS%E1*RHS%E11 + LHS%E11*RHS%E1
      ! Order 2
      RES%E11 = LHS%R*RHS%E11 + LHS%E11*RHS%R + LHS%E1*RHS%E1
      ! Order 1
      RES%E1 = LHS%R*RHS%E1 + LHS%E1*RHS%R
      ! Order 0
      RES%R = LHS%R*RHS%R

   END FUNCTION ONUMM1N4_MUL_OO_SV

   FUNCTION ONUMM1N4_MUL_RO_SV(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS
      TYPE(ONUMM1N4), INTENT(IN) :: RHS(:)
      TYPE(ONUMM1N4) :: RES(SIZE(RHS,1)) 

      ! Multiplication like function 'LHS*RHS'
      !  Real
      RES%R = LHS*RHS%R

      ! Order 1
      RES%E1 = LHS*RHS%E1

      ! Order 2
      RES%E11 = LHS*RHS%E11

      ! Order 3
      RES%E111 = LHS*RHS%E111

      ! Order 4
      RES%E1111 = LHS*RHS%E1111

   END FUNCTION ONUMM1N4_MUL_RO_SV

   FUNCTION ONUMM1N4_MUL_OR_SV(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM1N4), INTENT(IN) :: LHS
      REAL(DP), INTENT(IN) :: RHS(:)
      TYPE(ONUMM1N4) :: RES(SIZE(RHS,1)) 

      ! Multiplication like function 'LHS*RHS'
      !  Real
      RES%R = LHS%R*RHS

      ! Order 1
      RES%E1 = LHS%E1*RHS

      ! Order 2
      RES%E11 = LHS%E11*RHS

      ! Order 3
      RES%E111 = LHS%E111*RHS

      ! Order 4
      RES%E1111 = LHS%E1111*RHS

   END FUNCTION ONUMM1N4_MUL_OR_SV

   FUNCTION ONUMM1N4_ADD_OO_SM(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM1N4), INTENT(IN) :: LHS
      TYPE(ONUMM1N4), INTENT(IN) :: RHS(:,:)
      TYPE(ONUMM1N4) :: RES(SIZE(RHS,1),SIZE(RHS,2)) 

      ! Addition like function 'LHS + RHS'
      !  Real
      RES%R = LHS%R + RHS%R

      ! Order 1
      RES%E1 = LHS%E1 + RHS%E1

      ! Order 2
      RES%E11 = LHS%E11 + RHS%E11

      ! Order 3
      RES%E111 = LHS%E111 + RHS%E111

      ! Order 4
      RES%E1111 = LHS%E1111 + RHS%E1111

   END FUNCTION ONUMM1N4_ADD_OO_SM

   FUNCTION ONUMM1N4_ADD_RO_SM(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS
      TYPE(ONUMM1N4), INTENT(IN) :: RHS(:,:)
      TYPE(ONUMM1N4) :: RES(SIZE(RHS,1),SIZE(RHS,2)) 

      ! Addition like function 'LHS + RHS'
      ! Real
      RES%R = LHS + RHS%R

      ! Order 1
      RES%E1 =  + RHS%E1

      ! Order 2
      RES%E11 =  + RHS%E11

      ! Order 3
      RES%E111 =  + RHS%E111

      ! Order 4
      RES%E1111 =  + RHS%E1111

   END FUNCTION ONUMM1N4_ADD_RO_SM

   FUNCTION ONUMM1N4_ADD_OR_SM(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM1N4), INTENT(IN) :: LHS
      REAL(DP), INTENT(IN) :: RHS(:,:)
      TYPE(ONUMM1N4) :: RES(SIZE(RHS,1),SIZE(RHS,2)) 

      ! Addition like function 'LHS + RHS'
      ! Real
      RES%R = LHS%R + RHS

      ! Order 1
      RES%E1 = LHS%E1

      ! Order 2
      RES%E11 = LHS%E11

      ! Order 3
      RES%E111 = LHS%E111

      ! Order 4
      RES%E1111 = LHS%E1111

   END FUNCTION ONUMM1N4_ADD_OR_SM

   FUNCTION ONUMM1N4_SUB_OO_SM(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM1N4), INTENT(IN) :: LHS
      TYPE(ONUMM1N4), INTENT(IN) :: RHS(:,:)
      TYPE(ONUMM1N4) :: RES(SIZE(RHS,1),SIZE(RHS,2)) 

      ! Addition like function 'LHS - RHS'
      !  Real
      RES%R = LHS%R - RHS%R

      ! Order 1
      RES%E1 = LHS%E1 - RHS%E1

      ! Order 2
      RES%E11 = LHS%E11 - RHS%E11

      ! Order 3
      RES%E111 = LHS%E111 - RHS%E111

      ! Order 4
      RES%E1111 = LHS%E1111 - RHS%E1111

   END FUNCTION ONUMM1N4_SUB_OO_SM

   FUNCTION ONUMM1N4_SUB_RO_SM(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS
      TYPE(ONUMM1N4), INTENT(IN) :: RHS(:,:)
      TYPE(ONUMM1N4) :: RES(SIZE(RHS,1),SIZE(RHS,2)) 

      ! Addition like function 'LHS - RHS'
      ! Real
      RES%R = LHS - RHS%R

      ! Order 1
      RES%E1 =  - RHS%E1

      ! Order 2
      RES%E11 =  - RHS%E11

      ! Order 3
      RES%E111 =  - RHS%E111

      ! Order 4
      RES%E1111 =  - RHS%E1111

   END FUNCTION ONUMM1N4_SUB_RO_SM

   FUNCTION ONUMM1N4_SUB_OR_SM(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM1N4), INTENT(IN) :: LHS
      REAL(DP), INTENT(IN) :: RHS(:,:)
      TYPE(ONUMM1N4) :: RES(SIZE(RHS,1),SIZE(RHS,2)) 

      ! Addition like function 'LHS - RHS'
      ! Real
      RES%R = LHS%R - RHS

      ! Order 1
      RES%E1 = LHS%E1

      ! Order 2
      RES%E11 = LHS%E11

      ! Order 3
      RES%E111 = LHS%E111

      ! Order 4
      RES%E1111 = LHS%E1111

   END FUNCTION ONUMM1N4_SUB_OR_SM

   FUNCTION ONUMM1N4_MUL_OO_SM(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM1N4), INTENT(IN) :: LHS
      TYPE(ONUMM1N4), INTENT(IN) :: RHS(:,:)
      TYPE(ONUMM1N4) :: RES(SIZE(RHS,1),SIZE(RHS,2)) 

      !  Multiplication like function 'LHS*RHS'
      ! Order 4
      RES%E1111 = LHS%R*RHS%E1111 + LHS%E1111*RHS%R +  &
               LHS%E1*RHS%E111 + LHS%E111*RHS%E1 + LHS%E11*RHS%E11
      ! Order 3
      RES%E111 = LHS%R*RHS%E111 + LHS%E111*RHS%R +  &
              LHS%E1*RHS%E11 + LHS%E11*RHS%E1
      ! Order 2
      RES%E11 = LHS%R*RHS%E11 + LHS%E11*RHS%R + LHS%E1*RHS%E1
      ! Order 1
      RES%E1 = LHS%R*RHS%E1 + LHS%E1*RHS%R
      ! Order 0
      RES%R = LHS%R*RHS%R

   END FUNCTION ONUMM1N4_MUL_OO_SM

   FUNCTION ONUMM1N4_MUL_RO_SM(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS
      TYPE(ONUMM1N4), INTENT(IN) :: RHS(:,:)
      TYPE(ONUMM1N4) :: RES(SIZE(RHS,1),SIZE(RHS,2)) 

      ! Multiplication like function 'LHS*RHS'
      !  Real
      RES%R = LHS*RHS%R

      ! Order 1
      RES%E1 = LHS*RHS%E1

      ! Order 2
      RES%E11 = LHS*RHS%E11

      ! Order 3
      RES%E111 = LHS*RHS%E111

      ! Order 4
      RES%E1111 = LHS*RHS%E1111

   END FUNCTION ONUMM1N4_MUL_RO_SM

   FUNCTION ONUMM1N4_MUL_OR_SM(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM1N4), INTENT(IN) :: LHS
      REAL(DP), INTENT(IN) :: RHS(:,:)
      TYPE(ONUMM1N4) :: RES(SIZE(RHS,1),SIZE(RHS,2)) 

      ! Multiplication like function 'LHS*RHS'
      !  Real
      RES%R = LHS%R*RHS

      ! Order 1
      RES%E1 = LHS%E1*RHS

      ! Order 2
      RES%E11 = LHS%E11*RHS

      ! Order 3
      RES%E111 = LHS%E111*RHS

      ! Order 4
      RES%E1111 = LHS%E1111*RHS

   END FUNCTION ONUMM1N4_MUL_OR_SM

ELEMENTAL    FUNCTION ONUMM1N4_GEM_OOO(A,B,C)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM1N4), INTENT(IN) :: A 
      TYPE(ONUMM1N4), INTENT(IN) :: B 
      TYPE(ONUMM1N4), INTENT(IN) :: C 
      TYPE(ONUMM1N4) :: RES 

      !  General multiplication like function 'A*B + C'

      ! Order 0
      RES%R = C%R + A%R*B%R

      ! Order 1
      RES%E1 = C%E1 + A%R*B%E1 + A%E1*B%R

      ! Order 2
      RES%E11 = C%E11 + A%R*B%E11 + A%E11*B%R + A%E1*B%E1

      ! Order 3
      RES%E111 = C%E111 + A%R*B%E111 + A%E111*B%R + A%E1*B%E11 &
               + A%E11*B%E1

      ! Order 4
      RES%E1111 = C%E1111 + A%R*B%E1111 + A%E1111*B%R + A%E1*B%E111 &
                + A%E111*B%E1 + A%E11*B%E11

   END FUNCTION ONUMM1N4_GEM_OOO

ELEMENTAL    FUNCTION ONUMM1N4_GEM_ROO(A,B,C)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: A 
      TYPE(ONUMM1N4), INTENT(IN) :: B 
      TYPE(ONUMM1N4), INTENT(IN) :: C 
      TYPE(ONUMM1N4) :: RES 

      !  General multiplication like function 'A*B + C'
      ! Order 4
      RES%E1111 = C%E1111 + A*B%E1111
      ! Order 3
      RES%E111 = C%E111 + A*B%E111
      ! Order 2
      RES%E11 = C%E11 + A*B%E11
      ! Order 1
      RES%E1 = C%E1 + A*B%E1
      ! Order 0
      RES%R = C%R + A*B%R

   END FUNCTION ONUMM1N4_GEM_ROO

ELEMENTAL    FUNCTION ONUMM1N4_GEM_ORO(A,B,C)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM1N4), INTENT(IN) :: A 
      REAL(DP), INTENT(IN) :: B 
      TYPE(ONUMM1N4), INTENT(IN) :: C 
      TYPE(ONUMM1N4) :: RES 

      !  General multiplication like function 'A*B + C'

      ! Order 0
      RES%R = C%R + A%R*B

      ! Order 1
      RES%E1 = C%E1 + A%E1*B

      ! Order 2
      RES%E11 = C%E11 + A%E11*B

      ! Order 3
      RES%E111 = C%E111 + A%E111*B

      ! Order 4
      RES%E1111 = C%E1111 + A%E1111*B

   END FUNCTION ONUMM1N4_GEM_ORO

   FUNCTION ONUMM1N4_MATMUL_ONUMM1N4(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM1N4), INTENT(IN) :: LHS(:,:)
      TYPE(ONUMM1N4), INTENT(IN) :: RHS(:,:)
      TYPE(ONUMM1N4) :: RES(SIZE(LHS,1),SIZE(RHS,2))

      !  Multiplication like function 'MATMUL(LHS,RHS)'
      ! Order 4
      RES%E1111 = MATMUL(LHS%R,RHS%E1111) + MATMUL(LHS%E1111,RHS%R) +  &
               MATMUL(LHS%E1,RHS%E111) + MATMUL(LHS%E111,RHS%E1) + MATMUL(LHS%E11,RHS%E11)
      ! Order 3
      RES%E111 = MATMUL(LHS%R,RHS%E111) + MATMUL(LHS%E111,RHS%R) +  &
              MATMUL(LHS%E1,RHS%E11) + MATMUL(LHS%E11,RHS%E1)
      ! Order 2
      RES%E11 = MATMUL(LHS%R,RHS%E11) + MATMUL(LHS%E11,RHS%R) + MATMUL(LHS%E1,RHS%E1)
      ! Order 1
      RES%E1 = MATMUL(LHS%R,RHS%E1) + MATMUL(LHS%E1,RHS%R)
      ! Order 0
      RES%R = MATMUL(LHS%R,RHS%R)

   END FUNCTION ONUMM1N4_MATMUL_ONUMM1N4

   FUNCTION R_MATMUL_ONUMM1N4(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS(:,:)
      TYPE(ONUMM1N4), INTENT(IN) :: RHS(:,:)
      TYPE(ONUMM1N4) :: RES(SIZE(LHS,1),SIZE(RHS,2))

      ! Multiplication like function 'MATMUL(LHS,RHS)'
      !  Real
      RES%R = MATMUL(LHS,RHS%R)

      ! Order 1
      RES%E1 = MATMUL(LHS,RHS%E1)

      ! Order 2
      RES%E11 = MATMUL(LHS,RHS%E11)

      ! Order 3
      RES%E111 = MATMUL(LHS,RHS%E111)

      ! Order 4
      RES%E1111 = MATMUL(LHS,RHS%E1111)

   END FUNCTION R_MATMUL_ONUMM1N4

   FUNCTION ONUMM1N4_MATMUL_R(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM1N4), INTENT(IN) :: LHS(:,:)
      REAL(DP), INTENT(IN) :: RHS(:,:)
      TYPE(ONUMM1N4) :: RES(SIZE(LHS,1),SIZE(RHS,2))

      ! Multiplication like function 'MATMUL(LHS,RHS)'
      !  Real
      RES%R = MATMUL(LHS%R,RHS)

      ! Order 1
      RES%E1 = MATMUL(LHS%E1,RHS)

      ! Order 2
      RES%E11 = MATMUL(LHS%E11,RHS)

      ! Order 3
      RES%E111 = MATMUL(LHS%E111,RHS)

      ! Order 4
      RES%E1111 = MATMUL(LHS%E1111,RHS)

   END FUNCTION ONUMM1N4_MATMUL_R

   FUNCTION ONUMM1N4_DOT_PRODUCT_ONUMM1N4(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM1N4), INTENT(IN) :: LHS(:)
      TYPE(ONUMM1N4), INTENT(IN) :: RHS(SIZE(LHS))
      TYPE(ONUMM1N4) :: RES

      !  Multiplication like function 'DOT_PRODUCT(LHS,RHS)'
      ! Order 4
      RES%E1111 = DOT_PRODUCT(LHS%R,RHS%E1111) + DOT_PRODUCT(LHS%E1111,RHS%R) +  &
               DOT_PRODUCT(LHS%E1,RHS%E111) + DOT_PRODUCT(LHS%E111,RHS%E1) + DOT_PRODUCT(LHS%E11,RHS%E11)
      ! Order 3
      RES%E111 = DOT_PRODUCT(LHS%R,RHS%E111) + DOT_PRODUCT(LHS%E111,RHS%R) +  &
              DOT_PRODUCT(LHS%E1,RHS%E11) + DOT_PRODUCT(LHS%E11,RHS%E1)
      ! Order 2
      RES%E11 = DOT_PRODUCT(LHS%R,RHS%E11) + DOT_PRODUCT(LHS%E11,RHS%R) + DOT_PRODUCT(LHS%E1,RHS%E1)
      ! Order 1
      RES%E1 = DOT_PRODUCT(LHS%R,RHS%E1) + DOT_PRODUCT(LHS%E1,RHS%R)
      ! Order 0
      RES%R = DOT_PRODUCT(LHS%R,RHS%R)

   END FUNCTION ONUMM1N4_DOT_PRODUCT_ONUMM1N4

   FUNCTION R_DOT_PRODUCT_ONUMM1N4(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS(:)
      TYPE(ONUMM1N4), INTENT(IN) :: RHS(SIZE(LHS))
      TYPE(ONUMM1N4) :: RES

      ! Multiplication like function 'DOT_PRODUCT(LHS,RHS)'
      !  Real
      RES%R = DOT_PRODUCT(LHS,RHS%R)

      ! Order 1
      RES%E1 = DOT_PRODUCT(LHS,RHS%E1)

      ! Order 2
      RES%E11 = DOT_PRODUCT(LHS,RHS%E11)

      ! Order 3
      RES%E111 = DOT_PRODUCT(LHS,RHS%E111)

      ! Order 4
      RES%E1111 = DOT_PRODUCT(LHS,RHS%E1111)

   END FUNCTION R_DOT_PRODUCT_ONUMM1N4

   FUNCTION ONUMM1N4_DOT_PRODUCT_R(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM1N4), INTENT(IN) :: LHS(:)
      REAL(DP), INTENT(IN) :: RHS(SIZE(LHS))
      TYPE(ONUMM1N4) :: RES

      ! Multiplication like function 'DOT_PRODUCT(LHS,RHS)'
      !  Real
      RES%R = DOT_PRODUCT(LHS%R,RHS)

      ! Order 1
      RES%E1 = DOT_PRODUCT(LHS%E1,RHS)

      ! Order 2
      RES%E11 = DOT_PRODUCT(LHS%E11,RHS)

      ! Order 3
      RES%E111 = DOT_PRODUCT(LHS%E111,RHS)

      ! Order 4
      RES%E1111 = DOT_PRODUCT(LHS%E1111,RHS)

   END FUNCTION ONUMM1N4_DOT_PRODUCT_R

   FUNCTION ONUMM1N4_TRANSPOSE(LHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM1N4), INTENT(IN) :: LHS(:,:)
      TYPE(ONUMM1N4) :: RES (SIZE(LHS,2),SIZE(LHS,1))

      ! Negation like function 'TRANSPOSE(LHS)'
      ! Real
      RES%R = TRANSPOSE(LHS%R)
      ! Order 1
      RES%E1 = TRANSPOSE(LHS%E1)
      ! Order 2
      RES%E11 = TRANSPOSE(LHS%E11)
      ! Order 3
      RES%E111 = TRANSPOSE(LHS%E111)
      ! Order 4
      RES%E1111 = TRANSPOSE(LHS%E1111)

   END FUNCTION ONUMM1N4_TRANSPOSE

FUNCTION ONUMM1N4_TO_CR_MAT_S(VAL) RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM1N4), INTENT(IN) :: VAL
      REAL(DP) :: RES(NUM_IM_DIR,NUM_IM_DIR) 
      INTEGER :: NCOLS=1, NROWS=1


      ! R x R -> R (1, 1)
      RES(1+NROWS*0:NROWS*1,1+NCOLS*0:NCOLS*1) = VAL%R
      ! R x E1 -> E1 (2, 2)
      RES(1+NROWS*1:NROWS*2,1+NCOLS*1:NCOLS*2) = VAL%R
      ! E1 x R -> E1 (2, 1)
      RES(1+NROWS*1:NROWS*2,1+NCOLS*0:NCOLS*1) = VAL%E1
      ! R x E11 -> E11 (3, 3)
      RES(1+NROWS*2:NROWS*3,1+NCOLS*2:NCOLS*3) = VAL%R
      ! E11 x R -> E11 (3, 1)
      RES(1+NROWS*2:NROWS*3,1+NCOLS*0:NCOLS*1) = VAL%E11
      ! E1 x E1 -> E11 (3, 2)
      RES(1+NROWS*2:NROWS*3,1+NCOLS*1:NCOLS*2) = VAL%E1
      ! R x E111 -> E111 (4, 4)
      RES(1+NROWS*3:NROWS*4,1+NCOLS*3:NCOLS*4) = VAL%R
      ! E111 x R -> E111 (4, 1)
      RES(1+NROWS*3:NROWS*4,1+NCOLS*0:NCOLS*1) = VAL%E111
      ! E1 x E11 -> E111 (4, 3)
      RES(1+NROWS*3:NROWS*4,1+NCOLS*2:NCOLS*3) = VAL%E1
      ! E11 x E1 -> E111 (4, 2)
      RES(1+NROWS*3:NROWS*4,1+NCOLS*1:NCOLS*2) = VAL%E11
      ! R x E1111 -> E1111 (5, 5)
      RES(1+NROWS*4:NROWS*5,1+NCOLS*4:NCOLS*5) = VAL%R
      ! E1111 x R -> E1111 (5, 1)
      RES(1+NROWS*4:NROWS*5,1+NCOLS*0:NCOLS*1) = VAL%E1111
      ! E1 x E111 -> E1111 (5, 4)
      RES(1+NROWS*4:NROWS*5,1+NCOLS*3:NCOLS*4) = VAL%E1
      ! E111 x E1 -> E1111 (5, 2)
      RES(1+NROWS*4:NROWS*5,1+NCOLS*1:NCOLS*2) = VAL%E111
      ! E11 x E11 -> E1111 (5, 3)
      RES(1+NROWS*4:NROWS*5,1+NCOLS*2:NCOLS*3) = VAL%E11
   END FUNCTION ONUMM1N4_TO_CR_MAT_S

FUNCTION ONUMM1N4_TO_CR_MAT_V(VAL) RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM1N4), INTENT(IN) :: VAL(:)
      REAL(DP) :: RES(NUM_IM_DIR*SIZE(VAL,1),NUM_IM_DIR) 
      INTEGER :: NCOLS=1, NROWS=1

      NROWS = SIZE(VAL,1)

      ! R x R -> R (1, 1)
      RES(1+NROWS*0:NROWS*1,1) = VAL%R
      ! R x E1 -> E1 (2, 2)
      RES(1+NROWS*1:NROWS*2,2) = VAL%R
      ! E1 x R -> E1 (2, 1)
      RES(1+NROWS*1:NROWS*2,1) = VAL%E1
      ! R x E11 -> E11 (3, 3)
      RES(1+NROWS*2:NROWS*3,3) = VAL%R
      ! E11 x R -> E11 (3, 1)
      RES(1+NROWS*2:NROWS*3,1) = VAL%E11
      ! E1 x E1 -> E11 (3, 2)
      RES(1+NROWS*2:NROWS*3,2) = VAL%E1
      ! R x E111 -> E111 (4, 4)
      RES(1+NROWS*3:NROWS*4,4) = VAL%R
      ! E111 x R -> E111 (4, 1)
      RES(1+NROWS*3:NROWS*4,1) = VAL%E111
      ! E1 x E11 -> E111 (4, 3)
      RES(1+NROWS*3:NROWS*4,3) = VAL%E1
      ! E11 x E1 -> E111 (4, 2)
      RES(1+NROWS*3:NROWS*4,2) = VAL%E11
      ! R x E1111 -> E1111 (5, 5)
      RES(1+NROWS*4:NROWS*5,5) = VAL%R
      ! E1111 x R -> E1111 (5, 1)
      RES(1+NROWS*4:NROWS*5,1) = VAL%E1111
      ! E1 x E111 -> E1111 (5, 4)
      RES(1+NROWS*4:NROWS*5,4) = VAL%E1
      ! E111 x E1 -> E1111 (5, 2)
      RES(1+NROWS*4:NROWS*5,2) = VAL%E111
      ! E11 x E11 -> E1111 (5, 3)
      RES(1+NROWS*4:NROWS*5,3) = VAL%E11
   END FUNCTION ONUMM1N4_TO_CR_MAT_V

FUNCTION ONUMM1N4_TO_CR_MAT_M(VAL) RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM1N4), INTENT(IN) :: VAL(:,:)
      REAL(DP) :: RES(NUM_IM_DIR*SIZE(VAL,1),NUM_IM_DIR*SIZE(VAL,2)) 
      INTEGER :: NCOLS=1, NROWS=1

      NCOLS = SIZE(VAL,1)
      NROWS = SIZE(VAL,2)

      ! R x R -> R (1, 1)
      RES(1+NROWS*0:NROWS*1,1+NCOLS*0:NCOLS*1) = VAL%R
      ! R x E1 -> E1 (2, 2)
      RES(1+NROWS*1:NROWS*2,1+NCOLS*1:NCOLS*2) = VAL%R
      ! E1 x R -> E1 (2, 1)
      RES(1+NROWS*1:NROWS*2,1+NCOLS*0:NCOLS*1) = VAL%E1
      ! R x E11 -> E11 (3, 3)
      RES(1+NROWS*2:NROWS*3,1+NCOLS*2:NCOLS*3) = VAL%R
      ! E11 x R -> E11 (3, 1)
      RES(1+NROWS*2:NROWS*3,1+NCOLS*0:NCOLS*1) = VAL%E11
      ! E1 x E1 -> E11 (3, 2)
      RES(1+NROWS*2:NROWS*3,1+NCOLS*1:NCOLS*2) = VAL%E1
      ! R x E111 -> E111 (4, 4)
      RES(1+NROWS*3:NROWS*4,1+NCOLS*3:NCOLS*4) = VAL%R
      ! E111 x R -> E111 (4, 1)
      RES(1+NROWS*3:NROWS*4,1+NCOLS*0:NCOLS*1) = VAL%E111
      ! E1 x E11 -> E111 (4, 3)
      RES(1+NROWS*3:NROWS*4,1+NCOLS*2:NCOLS*3) = VAL%E1
      ! E11 x E1 -> E111 (4, 2)
      RES(1+NROWS*3:NROWS*4,1+NCOLS*1:NCOLS*2) = VAL%E11
      ! R x E1111 -> E1111 (5, 5)
      RES(1+NROWS*4:NROWS*5,1+NCOLS*4:NCOLS*5) = VAL%R
      ! E1111 x R -> E1111 (5, 1)
      RES(1+NROWS*4:NROWS*5,1+NCOLS*0:NCOLS*1) = VAL%E1111
      ! E1 x E111 -> E1111 (5, 4)
      RES(1+NROWS*4:NROWS*5,1+NCOLS*3:NCOLS*4) = VAL%E1
      ! E111 x E1 -> E1111 (5, 2)
      RES(1+NROWS*4:NROWS*5,1+NCOLS*1:NCOLS*2) = VAL%E111
      ! E11 x E11 -> E1111 (5, 3)
      RES(1+NROWS*4:NROWS*5,1+NCOLS*2:NCOLS*3) = VAL%E11
   END FUNCTION ONUMM1N4_TO_CR_MAT_M

      SUBROUTINE ONUMM1N4_SETIM_S(VAL,IDX,RES)
      IMPLICIT NONE
      TYPE(ONUMM1N4), INTENT(INOUT) :: VAL
      REAL(DP),INTENT(IN) :: RES 
      INTEGER, INTENT(IN) :: IDX

      SELECT CASE(IDX)
      ! Order 0
      CASE(0)
         VAL%R=RES

      ! Order 1
      CASE(1)
         VAL%E1=RES

      ! Order 2
      CASE(2)
         VAL%E11=RES

      ! Order 3
      CASE(3)
         VAL%E111=RES

      ! Order 4
      CASE(4)
         VAL%E1111=RES

      END SELECT
   END SUBROUTINE ONUMM1N4_SETIM_S

      SUBROUTINE ONUMM1N4_SETIM_V(VAL,IDX,RES)
      IMPLICIT NONE
      TYPE(ONUMM1N4), INTENT(INOUT) :: VAL(:)
      REAL(DP),INTENT(IN) :: RES(SIZE(VAL)) 
      INTEGER, INTENT(IN) :: IDX

      SELECT CASE(IDX)
      ! Order 0
      CASE(0)
         VAL%R=RES

      ! Order 1
      CASE(1)
         VAL%E1=RES

      ! Order 2
      CASE(2)
         VAL%E11=RES

      ! Order 3
      CASE(3)
         VAL%E111=RES

      ! Order 4
      CASE(4)
         VAL%E1111=RES

      END SELECT
   END SUBROUTINE ONUMM1N4_SETIM_V

      SUBROUTINE ONUMM1N4_SETIM_M(VAL,IDX,RES)
      IMPLICIT NONE
      TYPE(ONUMM1N4), INTENT(INOUT) :: VAL(:,:)
      REAL(DP),INTENT(IN) :: RES(SIZE(VAL,1),SIZE(VAL,2)) 
      INTEGER, INTENT(IN) :: IDX

      SELECT CASE(IDX)
      ! Order 0
      CASE(0)
         VAL%R=RES

      ! Order 1
      CASE(1)
         VAL%E1=RES

      ! Order 2
      CASE(2)
         VAL%E11=RES

      ! Order 3
      CASE(3)
         VAL%E111=RES

      ! Order 4
      CASE(4)
         VAL%E1111=RES

      END SELECT
   END SUBROUTINE ONUMM1N4_SETIM_M

FUNCTION ONUMM1N4_GETIM_S(VAL,IDX) RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM1N4), INTENT(IN) :: VAL
      REAL(DP) :: RES 
      INTEGER, INTENT(IN) :: IDX

      SELECT CASE(IDX)
      ! Order 0
      CASE(0)
         RES=VAL%R

      ! Order 1
      CASE(1)
         RES=VAL%E1

      ! Order 2
      CASE(2)
         RES=VAL%E11

      ! Order 3
      CASE(3)
         RES=VAL%E111

      ! Order 4
      CASE(4)
         RES=VAL%E1111

      END SELECT
   END FUNCTION ONUMM1N4_GETIM_S

FUNCTION ONUMM1N4_GETIM_V(VAL,IDX) RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM1N4), INTENT(IN) :: VAL(:)
      REAL(DP) :: RES(SIZE(VAL)) 
      INTEGER, INTENT(IN) :: IDX

      SELECT CASE(IDX)
      ! Order 0
      CASE(0)
         RES=VAL%R

      ! Order 1
      CASE(1)
         RES=VAL%E1

      ! Order 2
      CASE(2)
         RES=VAL%E11

      ! Order 3
      CASE(3)
         RES=VAL%E111

      ! Order 4
      CASE(4)
         RES=VAL%E1111

      END SELECT
   END FUNCTION ONUMM1N4_GETIM_V

FUNCTION ONUMM1N4_GETIM_M(VAL,IDX) RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM1N4), INTENT(IN) :: VAL(:,:)
      REAL(DP) :: RES(SIZE(VAL,1),SIZE(VAL,2)) 
      INTEGER, INTENT(IN) :: IDX

      SELECT CASE(IDX)
      ! Order 0
      CASE(0)
         RES=VAL%R

      ! Order 1
      CASE(1)
         RES=VAL%E1

      ! Order 2
      CASE(2)
         RES=VAL%E11

      ! Order 3
      CASE(3)
         RES=VAL%E111

      ! Order 4
      CASE(4)
         RES=VAL%E1111

      END SELECT
   END FUNCTION ONUMM1N4_GETIM_M

   SUBROUTINE ONUMM1N4_PPRINT_S(VAR,FMT,UNIT)
      IMPLICIT NONE
      TYPE(ONUMM1N4), INTENT(IN) :: VAR
      CHARACTER(len=*), INTENT(IN), OPTIONAL :: fmt
      INTEGER, INTENT(IN), OPTIONAL :: unit
      CHARACTER(len=:),ALLOCATABLE :: output_format
      INTEGER :: unt

      IF ( PRESENT(unit) ) THEN
         unt = unit
      ELSE
         unt = 6
      END IF

      IF ( PRESENT(fmt) ) THEN
         output_format = '('//trim(fmt)//')'
      ELSE
         output_format = '(F10.4)'
      END IF

      ! Pretty print function.
      !  Real
      CALL PPRINT(VAR%R,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') ' '

      !  Order 1
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'E1 * '
      CALL PPRINT(VAR%E1,unit=unt,fmt=output_format)

      !  Order 2
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'E11 * '
      CALL PPRINT(VAR%E11,unit=unt,fmt=output_format)

      !  Order 3
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'E111 * '
      CALL PPRINT(VAR%E111,unit=unt,fmt=output_format)

      !  Order 4
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'E1111 * '
      CALL PPRINT(VAR%E1111,unit=unt,fmt=output_format)


   END SUBROUTINE ONUMM1N4_PPRINT_S

   SUBROUTINE ONUMM1N4_PPRINT_V(VAR,FMT,UNIT)
      IMPLICIT NONE
      TYPE(ONUMM1N4), INTENT(IN) :: VAR(:)
      CHARACTER(len=*), INTENT(IN), OPTIONAL :: fmt
      INTEGER, INTENT(IN), OPTIONAL :: unit
      CHARACTER(len=:),ALLOCATABLE :: output_format
      INTEGER :: unt

      IF ( PRESENT(unit) ) THEN
         unt = unit
      ELSE
         unt = 6
      END IF

      IF ( PRESENT(fmt) ) THEN
         output_format = '('//trim(fmt)//')'
      ELSE
         output_format = '(F10.4)'
      END IF

      ! Pretty print function.
      !  Real
      CALL PPRINT(VAR%R,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') ' '

      !  Order 1
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E1 * '
      CALL PPRINT(VAR%E1,unit=unt,fmt=output_format)

      !  Order 2
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E11 * '
      CALL PPRINT(VAR%E11,unit=unt,fmt=output_format)

      !  Order 3
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E111 * '
      CALL PPRINT(VAR%E111,unit=unt,fmt=output_format)

      !  Order 4
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E1111 * '
      CALL PPRINT(VAR%E1111,unit=unt,fmt=output_format)


   END SUBROUTINE ONUMM1N4_PPRINT_V

   SUBROUTINE ONUMM1N4_PPRINT_M(VAR,FMT,UNIT)
      IMPLICIT NONE
      TYPE(ONUMM1N4), INTENT(IN) :: VAR(:,:)
      CHARACTER(len=*), INTENT(IN), OPTIONAL :: fmt
      INTEGER, INTENT(IN), OPTIONAL :: unit
      CHARACTER(len=:),ALLOCATABLE :: output_format
      INTEGER :: unt

      IF ( PRESENT(unit) ) THEN
         unt = unit
      ELSE
         unt = 6
      END IF

      IF ( PRESENT(fmt) ) THEN
         output_format = '('//trim(fmt)//')'
      ELSE
         output_format = '(F10.4)'
      END IF

      ! Pretty print function.
      !  Real
      CALL PPRINT(VAR%R,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') ' '

      !  Order 1
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E1 * '
      CALL PPRINT(VAR%E1,unit=unt,fmt=output_format)

      !  Order 2
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E11 * '
      CALL PPRINT(VAR%E11,unit=unt,fmt=output_format)

      !  Order 3
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E111 * '
      CALL PPRINT(VAR%E111,unit=unt,fmt=output_format)

      !  Order 4
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E1111 * '
      CALL PPRINT(VAR%E1111,unit=unt,fmt=output_format)


   END SUBROUTINE ONUMM1N4_PPRINT_M

   ELEMENTAL FUNCTION ONUMM1N4_FEVAL(X,DER0,DER1,DER2,DER3,DER4)&
      RESULT(RES)
      IMPLICIT NONE
      !  Definitions
      REAL(DP) :: FACTOR, COEF
      TYPE(ONUMM1N4), INTENT(IN)  :: X
      REAL(DP), INTENT(IN)  :: DER0,DER1,DER2,DER3,DER4
      TYPE(ONUMM1N4) :: RES
      TYPE(ONUMM1N4) :: DX, DX_P

      FACTOR = 1.0_DP
      COEF   = 0.0_DP
      DX     = X
      DX_P   = X

      !  Set real part of deltas zero.
      DX%R = 0.0_DP
      DX_P%R = 0.0_DP

      ! Sets real part
      RES = DER0

      ! Sets order 1
      FACTOR = FACTOR * 1
      COEF = DER1 / FACTOR
      ! RES = RES COEF * DX_P
      ! Order 4
      RES%E1111 = RES%E1111+COEF*DX_P%E1111
      ! Order 3
      RES%E111 = RES%E111+COEF*DX_P%E111
      ! Order 2
      RES%E11 = RES%E11+COEF*DX_P%E11
      ! Order 1
      RES%E1 = RES%E1+COEF*DX_P%E1
      ! DX_P = DX_P * DX
      ! Order 4
      DX_P%E1111 = DX_P%E1*DX%E111+DX_P%E111*DX%E1+ &
                DX_P%E11*DX%E11
      ! Order 3
      DX_P%E111 = DX_P%E1*DX%E11+DX_P%E11*DX%E1
      ! Order 2
      DX_P%E11 = DX_P%E1*DX%E1
      
      ! Sets order 2
      FACTOR = FACTOR * 2
      COEF = DER2 / FACTOR
      ! RES = RES COEF * DX_P
      ! Order 4
      RES%E1111 = RES%E1111+COEF*DX_P%E1111
      ! Order 3
      RES%E111 = RES%E111+COEF*DX_P%E111
      ! Order 2
      RES%E11 = RES%E11+COEF*DX_P%E11
      ! DX_P = DX_P * DX
      ! Order 4
      DX_P%E1111 = DX_P%E111*DX%E1+DX_P%E11*DX%E11
      ! Order 3
      DX_P%E111 = DX_P%E11*DX%E1
      
      ! Sets order 3
      FACTOR = FACTOR * 3
      COEF = DER3 / FACTOR
      ! RES = RES COEF * DX_P
      ! Order 4
      RES%E1111 = RES%E1111+COEF*DX_P%E1111
      ! Order 3
      RES%E111 = RES%E111+COEF*DX_P%E111
      ! DX_P = DX_P * DX
      ! Order 4
      DX_P%E1111 = DX_P%E111*DX%E1
      
      ! Sets order 4
      FACTOR = FACTOR * 4
      COEF = DER4 / FACTOR
      ! RES = RES COEF * DX_P
      ! Order 4
      RES%E1111 = RES%E1111+COEF*DX_P%E1111
      
   END FUNCTION ONUMM1N4_FEVAL


  ! SUBROUTINE ONUMM1N4_PPRINT_M_R(X, FMT)
  !     IMPLICIT NONE
  !     REAL(DP),INTENT(IN) :: X(:,:)
  !     INTEGER :: I, J
  !     CHARACTER(*),INTENT(IN),OPTIONAL :: FMT
  !     CHARACTER(:),ALLOCATABLE :: out_fmt
      
  !     IF (PRESENT(fmt)) THEN
  !       out_fmt = fmt
  !     ELSE
  !       out_fmt = 'F10.4'
  !     END IF
      
  !     write(*,'(A)',advance='no') "["
      
  !     DO I=1,SIZE(X,1)
        
  !       IF (I == 1) THEN
  !         write(*,'(A)',advance='no') "["
  !       ELSE
  !         write(*,'(A)',advance='no') " ["
  !       END IF 

  !       DO J=1,SIZE(X,2)
          
  !         write(*,'('//trim(out_fmt)//')',advance='no') X(I,J)

  !       END DO
        
  !       write(*,'(A)') "]"
      
  !     END DO

  !     write(*,'(A)') "]"

  ! END SUBROUTINE ONUMM1N4_PPRINT_M_R

  ! SUBROUTINE ONUMM1N4_PPRINT_V_R(X, FMT)
  !     IMPLICIT NONE
  !     REAL(DP),INTENT(IN) :: X(:)
  !     INTEGER :: I
  !     CHARACTER(*),INTENT(IN),OPTIONAL :: FMT
  !     CHARACTER(:),ALLOCATABLE :: out_fmt
      
  !     IF (PRESENT(fmt)) THEN
  !       out_fmt = fmt
  !     ELSE
  !       out_fmt = 'F10.4'
  !     END IF
      
  !     write(*,'(A)',advance='no') "["
      
  !     DO I=1,SIZE(X,1)

  !       write(*,'('//trim(out_fmt)//')',advance='no') X(I)

  !     END DO

  !     write(*,'(A)') "]"

  ! END SUBROUTINE ONUMM1N4_PPRINT_V_R

  ! !***************************************************************************************************! 
  ! !> @brief 2 x 2  matrix inversion.
  ! !!
  ! !! Taken from https://fortranwiki.org/fortran/show/Matrix+inversion
  ! !!
  ! !! @param[in] A: Matrix to be printed.
  ! !! @param[out] B: inverse of A.
  ! !!
  ! !***************************************************************************************************!
  ! PURE FUNCTION Rmatinv2x2(A,det) RESULT(B)

  !   IMPLICIT NONE

  !   REAL(dp), INTENT(IN) :: A(2,2)   !! Matrix
  !   REAL(dp), INTENT(IN), OPTIONAL :: det
  !   REAL(dp)             :: B(2,2)   !! Inverse matrix
  !   REAL(dp)             :: detinv

  !   IF ( PRESENT(det) ) THEN
  !     detinv = 1.0d0 / det
  !   ELSE
  !     ! Calculate the inverse determinant of the matrix
  !     detinv = 1.0d0 / det2x2(A)
  !   END IF

  !   ! Calculate the inverse of the matrix
  !   B(1,1) =  detinv * A(2,2)
  !   B(2,1) = -detinv * A(2,1)
  !   B(1,2) = -detinv * A(1,2)
  !   B(2,2) =  detinv * A(1,1)
  ! END FUNCTION
  ! !===================================================================================================! 
  
  ! !***************************************************************************************************! 
  ! !> @brief 3 x 3  matrix inversion.
  ! !!
  ! !! Taken from https://fortranwiki.org/fortran/show/Matrix+inversion
  ! !!
  ! !! @param[in]  A: Matrix to be printed.
  ! !! @param[out] B: inverse of A.
  ! !!
  ! !***************************************************************************************************!
  ! PURE FUNCTION Rmatinv3x3(A,det) RESULT(B)
      
  !     IMPLICIT NONE

  !     REAL(dp), INTENT(IN) :: A(3,3)   !! Matrix
  !     REAL(dp), INTENT(IN), OPTIONAL :: det
  !     REAL(dp)             :: B(3,3)   !! Inverse matrix
  !     REAL(dp)             :: detinv

  !     IF ( PRESENT(det) ) THEN
  !        detinv = 1.0d0/det
  !     ELSE
  !        ! Calculate the inverse determinant of the matrix
  !        detinv = 1.0d0/det3x3(A)
  !     END IF 

  !     ! Calculate the inverse of the matrix
  !     B(1,1) = + detinv * (A(2,2)*A(3,3) - A(2,3)*A(3,2))
  !     B(2,1) = - detinv * (A(2,1)*A(3,3) - A(2,3)*A(3,1))
  !     B(3,1) = + detinv * (A(2,1)*A(3,2) - A(2,2)*A(3,1))
  !     B(1,2) = - detinv * (A(1,2)*A(3,3) - A(1,3)*A(3,2))
  !     B(2,2) = + detinv * (A(1,1)*A(3,3) - A(1,3)*A(3,1))
  !     B(3,2) = - detinv * (A(1,1)*A(3,2) - A(1,2)*A(3,1))
  !     B(1,3) = + detinv * (A(1,2)*A(2,3) - A(1,3)*A(2,2))
  !     B(2,3) = - detinv * (A(1,1)*A(2,3) - A(1,3)*A(2,1))
  !     B(3,3) = + detinv * (A(1,1)*A(2,2) - A(1,2)*A(2,1))

  !  END FUNCTION
  !  !===================================================================================================! 

  !  !***************************************************************************************************! 
  !  !> @brief 4 x 4  matrix inversion.
  !  !!
  !  !! Taken from https://fortranwiki.org/fortran/show/Matrix+inversion
  !  !!
  !  !! @param[in]  A: Matrix to be printed.
  !  !! @param[in]  det: (optional) Determinant of A.
  !  !! @param[out] B: inverse of A.
  !  !!
  !  !***************************************************************************************************!
  !  PURE FUNCTION Rmatinv4x4(A,det) RESULT(B)
      
  !     IMPLICIT NONE

  !     REAL(dp), INTENT(IN) :: A(4,4)   !! Matrix
  !     REAL(dp), INTENT(IN), OPTIONAL :: det
  !     REAL(dp)             :: B(4,4)   !! Inverse matrix
  !     REAL(dp)             :: di  !! Determinant inverse

  !     ! Calculate the inverse determinant of the matrix
  !     IF ( PRESENT(det) ) THEN
  !        di = 1.0d0/det
  !     ELSE
  !        di = 1.0d0/det4x4(A)
  !     END IF 
      
  !     ! Calculate the inverse of the matrix
  !     B(1,1) = di*(A(2,2)*(A(3,3)*A(4,4)-A(3,4)*A(4,3))+A(2,3)*(A(3,4)*A(4,2)-A(3,2)*A(4,4))+A(2,4)*(A(3,2)*A(4,3)-A(3,3)*A(4,2)))
  !     B(2,1) = di*(A(2,1)*(A(3,4)*A(4,3)-A(3,3)*A(4,4))+A(2,3)*(A(3,1)*A(4,4)-A(3,4)*A(4,1))+A(2,4)*(A(3,3)*A(4,1)-A(3,1)*A(4,3)))
  !     B(3,1) = di*(A(2,1)*(A(3,2)*A(4,4)-A(3,4)*A(4,2))+A(2,2)*(A(3,4)*A(4,1)-A(3,1)*A(4,4))+A(2,4)*(A(3,1)*A(4,2)-A(3,2)*A(4,1)))
  !     B(4,1) = di*(A(2,1)*(A(3,3)*A(4,2)-A(3,2)*A(4,3))+A(2,2)*(A(3,1)*A(4,3)-A(3,3)*A(4,1))+A(2,3)*(A(3,2)*A(4,1)-A(3,1)*A(4,2)))
  !     B(1,2) = di*(A(1,2)*(A(3,4)*A(4,3)-A(3,3)*A(4,4))+A(1,3)*(A(3,2)*A(4,4)-A(3,4)*A(4,2))+A(1,4)*(A(3,3)*A(4,2)-A(3,2)*A(4,3)))
  !     B(2,2) = di*(A(1,1)*(A(3,3)*A(4,4)-A(3,4)*A(4,3))+A(1,3)*(A(3,4)*A(4,1)-A(3,1)*A(4,4))+A(1,4)*(A(3,1)*A(4,3)-A(3,3)*A(4,1)))
  !     B(3,2) = di*(A(1,1)*(A(3,4)*A(4,2)-A(3,2)*A(4,4))+A(1,2)*(A(3,1)*A(4,4)-A(3,4)*A(4,1))+A(1,4)*(A(3,2)*A(4,1)-A(3,1)*A(4,2)))
  !     B(4,2) = di*(A(1,1)*(A(3,2)*A(4,3)-A(3,3)*A(4,2))+A(1,2)*(A(3,3)*A(4,1)-A(3,1)*A(4,3))+A(1,3)*(A(3,1)*A(4,2)-A(3,2)*A(4,1)))
  !     B(1,3) = di*(A(1,2)*(A(2,3)*A(4,4)-A(2,4)*A(4,3))+A(1,3)*(A(2,4)*A(4,2)-A(2,2)*A(4,4))+A(1,4)*(A(2,2)*A(4,3)-A(2,3)*A(4,2)))
  !     B(2,3) = di*(A(1,1)*(A(2,4)*A(4,3)-A(2,3)*A(4,4))+A(1,3)*(A(2,1)*A(4,4)-A(2,4)*A(4,1))+A(1,4)*(A(2,3)*A(4,1)-A(2,1)*A(4,3)))
  !     B(3,3) = di*(A(1,1)*(A(2,2)*A(4,4)-A(2,4)*A(4,2))+A(1,2)*(A(2,4)*A(4,1)-A(2,1)*A(4,4))+A(1,4)*(A(2,1)*A(4,2)-A(2,2)*A(4,1)))
  !     B(4,3) = di*(A(1,1)*(A(2,3)*A(4,2)-A(2,2)*A(4,3))+A(1,2)*(A(2,1)*A(4,3)-A(2,3)*A(4,1))+A(1,3)*(A(2,2)*A(4,1)-A(2,1)*A(4,2)))
  !     B(1,4) = di*(A(1,2)*(A(2,4)*A(3,3)-A(2,3)*A(3,4))+A(1,3)*(A(2,2)*A(3,4)-A(2,4)*A(3,2))+A(1,4)*(A(2,3)*A(3,2)-A(2,2)*A(3,3)))
  !     B(2,4) = di*(A(1,1)*(A(2,3)*A(3,4)-A(2,4)*A(3,3))+A(1,3)*(A(2,4)*A(3,1)-A(2,1)*A(3,4))+A(1,4)*(A(2,1)*A(3,3)-A(2,3)*A(3,1)))
  !     B(3,4) = di*(A(1,1)*(A(2,4)*A(3,2)-A(2,2)*A(3,4))+A(1,2)*(A(2,1)*A(3,4)-A(2,4)*A(3,1))+A(1,4)*(A(2,2)*A(3,1)-A(2,1)*A(3,2)))
  !     B(4,4) = di*(A(1,1)*(A(2,2)*A(3,3)-A(2,3)*A(3,2))+A(1,2)*(A(2,3)*A(3,1)-A(2,1)*A(3,3))+A(1,3)*(A(2,1)*A(3,2)-A(2,2)*A(3,1)))
  !  END FUNCTION
  !  !===================================================================================================! 

  !***************************************************************************************************! 
  !> @brief 2 x 2  matrix determinant.
  !!
  !!
  !! @param[in] A: Matrix to be printed.
  !! @param[out] B: inverse of A.
  !!
  !***************************************************************************************************!
  PURE FUNCTION ONUMM1N4_det2x2(A) RESULT(det)

    IMPLICIT NONE

    TYPE(ONUMM1N4), INTENT(IN) :: A(2,2)   !! Matrix
    TYPE(ONUMM1N4)             :: det

    ! Calculate the determinant of the matrix
    det = (A(1,1)*A(2,2) - A(1,2)*A(2,1))

  END FUNCTION
  !===================================================================================================! 
  
  !***************************************************************************************************! 
  !> @brief 3 x 3  matrix determinant.
  !!
  !!
  !! @param[in]  A: Matrix to be printed.
  !! @param[out] B: inverse of A.
  !!
  !***************************************************************************************************!
  PURE FUNCTION ONUMM1N4_det3x3(A) RESULT(det)
      
    IMPLICIT NONE

    TYPE(ONUMM1N4), INTENT(IN) :: A(3,3)   !! Matrix
    TYPE(ONUMM1N4)             :: det

    ! Calculate the inverse determinant of the matrix
    det = (A(1,1)*A(2,2)*A(3,3) - A(1,1)*A(2,3)*A(3,2)&
         - A(1,2)*A(2,1)*A(3,3) + A(1,2)*A(2,3)*A(3,1)&
         + A(1,3)*A(2,1)*A(3,2) - A(1,3)*A(2,2)*A(3,1))

  END FUNCTION
  !===================================================================================================! 

  !***************************************************************************************************! 
  !> @brief 4 x 4  matrix determinant.
  !!
  !!
  !! @param[in]  A: Matrix to be printed.
  !! @param[out] B: inverse of A.
  !!
  !***************************************************************************************************!
  PURE FUNCTION ONUMM1N4_det4x4(A) RESULT(det)
      
    IMPLICIT NONE

    TYPE(ONUMM1N4), INTENT(IN) :: A(4,4)   !! Matrix
    TYPE(ONUMM1N4)             :: det

    ! Calculate the determinant of the matrix
    det = &
    (A(1,1)*(A(2,2)*(A(3,3)*A(4,4)-A(3,4)*A(4,3))+A(2,3)*(A(3,4)*A(4,2)-A(3,2)*A(4,4))+A(2,4)*(A(3,2)*A(4,3)-A(3,3)*A(4,2)))&
   - A(1,2)*(A(2,1)*(A(3,3)*A(4,4)-A(3,4)*A(4,3))+A(2,3)*(A(3,4)*A(4,1)-A(3,1)*A(4,4))+A(2,4)*(A(3,1)*A(4,3)-A(3,3)*A(4,1)))&
   + A(1,3)*(A(2,1)*(A(3,2)*A(4,4)-A(3,4)*A(4,2))+A(2,2)*(A(3,4)*A(4,1)-A(3,1)*A(4,4))+A(2,4)*(A(3,1)*A(4,2)-A(3,2)*A(4,1)))&
   - A(1,4)*(A(2,1)*(A(3,2)*A(4,3)-A(3,3)*A(4,2))+A(2,2)*(A(3,3)*A(4,1)-A(3,1)*A(4,3))+A(2,3)*(A(3,1)*A(4,2)-A(3,2)*A(4,1))))

  END FUNCTION
  !===================================================================================================! 
   
  !***************************************************************************************************! 
  !> @brief Cross product between two vectors.
  !!
  !! @param[in] a: Vector of 3 reals (rank 1).
  !! @param[in] b: Vector of 3 reals (rank 1).
  !!
  !***************************************************************************************************!
  PURE FUNCTION ONUMM1N4_cross3(a,b) RESULT(v)
      
    IMPLICIT NONE 

    TYPE(ONUMM1N4), DIMENSION (3),INTENT(IN) :: a,b
    TYPE(ONUMM1N4), DIMENSION (3) :: v
    
    v(1) = a(2) * b(3) - a(3) * b(2)
    v(2) = a(3) * b(1) - a(1) * b(3)
    v(3) = a(1) * b(2) - a(2) * b(1)

  END FUNCTION ONUMM1N4_cross3
  !===================================================================================================! 

  !***************************************************************************************************! 
  !> @brief Norm of a 3 element vector. # There is an intrinsic function named norm2.
  !!
  !! @param[in] a: Vector of 3 reals (rank 1).
  !! @param[in] b: Vector of 3 reals (rank 1).
  !!
  !***************************************************************************************************!
  FUNCTION ONUMM1N4_norm2_3(v) RESULT(n)
     
    IMPLICIT NONE 

    TYPE(ONUMM1N4), INTENT(IN) :: v(3)
    TYPE(ONUMM1N4) :: n
     
    n = SQRT( v(1)*v(1) + v(2)*v(2) + v(3)*v(3) )

  END FUNCTION ONUMM1N4_norm2_3
  !===================================================================================================! 

  ELEMENTAL FUNCTION ONUMM1N4_DIVISION_OO(X,Y) RESULT(RES)
      IMPLICIT NONE
      REAL(DP) :: DERIVS(TORDER + 1) 
      TYPE(ONUMM1N4), INTENT(IN) :: X
      TYPE(ONUMM1N4), INTENT(IN) :: Y
      TYPE(ONUMM1N4) :: RES

      RES = X*(Y**(-1.d0))

  END FUNCTION ONUMM1N4_DIVISION_OO

  FUNCTION ONUMM1N4_DIVISION_OR(X,Y) RESULT(RES)
      IMPLICIT NONE
      REAL(DP) :: DERIVS(TORDER + 1) 
      TYPE(ONUMM1N4), INTENT(IN) :: X
      REAL(DP), INTENT(IN) :: Y
      TYPE(ONUMM1N4) :: RES

      RES = X*(Y**(-1.d0))

  END FUNCTION ONUMM1N4_DIVISION_OR

  FUNCTION ONUMM1N4_DIVISION_RO(X,Y) RESULT(RES)
      IMPLICIT NONE
      REAL(DP) :: DERIVS(TORDER + 1) 
      REAL(DP), INTENT(IN) :: X
      TYPE(ONUMM1N4), INTENT(IN) :: Y
      TYPE(ONUMM1N4) :: RES

      RES = X*(Y**(-1.d0))

  END FUNCTION ONUMM1N4_DIVISION_RO

  ELEMENTAL FUNCTION ONUMM1N4_REAL(X) RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM1N4), INTENT(IN) :: X
      REAL(DP) :: RES

      RES = X%R

  END FUNCTION ONUMM1N4_REAL

  FUNCTION ONUMM1N4_SQRT(X) RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM1N4), INTENT(IN) :: X
      TYPE(ONUMM1N4) :: RES

      RES = X**0.5_DP

  END FUNCTION ONUMM1N4_SQRT

   ELEMENTAL FUNCTION ONUMM1N4_TAN(X) RESULT(RES)

      TYPE(ONUMM1N4), INTENT(IN) :: X
      REAL(DP) :: DER0,DER1,DER2,DER3,DER4
      TYPE(ONUMM1N4) :: RES
      
      DER0 = TAN(X%R)
      DER1 = TAN(X%R)**2 + 1
      DER2 = 2*(TAN(X%R)**2 + 1)*TAN(X%R)
      DER3 = 2*(TAN(X%R)**2 + 1)*(3*TAN(X%R)**2 + 1)
      DER4 = 8*(TAN(X%R)**2 + 1)*(3*TAN(X%R)**2 + 2)*TAN(X%R)

      RES = FEVAL(X,DER0,DER1,DER2,DER3,DER4)

   END FUNCTION ONUMM1N4_TAN

   ELEMENTAL FUNCTION ONUMM1N4_COS(X) RESULT(RES)

      TYPE(ONUMM1N4), INTENT(IN) :: X
      REAL(DP) :: DER0,DER1,DER2,DER3,DER4
      TYPE(ONUMM1N4) :: RES
      
      DER0 = COS(X%R)
      DER1 = -SIN(X%R)
      DER2 = -COS(X%R)
      DER3 = SIN(X%R)
      DER4 = COS(X%R)

      RES = FEVAL(X,DER0,DER1,DER2,DER3,DER4)

   END FUNCTION ONUMM1N4_COS

   ELEMENTAL FUNCTION ONUMM1N4_SIN(X) RESULT(RES)

      TYPE(ONUMM1N4), INTENT(IN) :: X
      REAL(DP) :: DER0,DER1,DER2,DER3,DER4
      TYPE(ONUMM1N4) :: RES
      
      DER0 = SIN(X%R)
      DER1 = COS(X%R)
      DER2 = -SIN(X%R)
      DER3 = -COS(X%R)
      DER4 = SIN(X%R)

      RES = FEVAL(X,DER0,DER1,DER2,DER3,DER4)

   END FUNCTION ONUMM1N4_SIN

   ELEMENTAL FUNCTION ONUMM1N4_ATAN(X) RESULT(RES)

      TYPE(ONUMM1N4), INTENT(IN) :: X
      REAL(DP) :: DER0,DER1,DER2,DER3,DER4
      TYPE(ONUMM1N4) :: RES
      
      DER0 = ATAN(X%R)
      DER1 = 1D0/(X%R**2 + 1)
      DER2 = -2*X%R/(X%R**2 + 1)**2
      DER3 = 2*(4*X%R**2/(X%R**2 + 1) - 1)/(X%R**2 + 1)**2
      DER4 = 24*X%R*(-2*X%R**2/(X%R**2 + 1) + 1)/(X%R**2 + 1)**3

      RES = FEVAL(X,DER0,DER1,DER2,DER3,DER4)

   END FUNCTION ONUMM1N4_ATAN

   ELEMENTAL FUNCTION ONUMM1N4_ACOS(X) RESULT(RES)

      TYPE(ONUMM1N4), INTENT(IN) :: X
      REAL(DP) :: DER0,DER1,DER2,DER3,DER4
      TYPE(ONUMM1N4) :: RES
      
      DER0 = ACOS(X%R)
      DER1 = -1/SQRT(1 - X%R**2)
      DER2 = -X%R/(1 - X%R**2)**(3.0D0/2.0D0)
      DER3 = -(3*X%R**2/(1 - X%R**2) + 1)/(1 - X%R**2)**(3.0D0/2.0D0)
      DER4 = -3*X%R*(5*X%R**2/(1 - X%R**2) + 3)/(1 - X%R**2)**(5.0D0/2.0D0)

      RES = FEVAL(X,DER0,DER1,DER2,DER3,DER4)

   END FUNCTION ONUMM1N4_ACOS

   ELEMENTAL FUNCTION ONUMM1N4_ASIN(X) RESULT(RES)

      TYPE(ONUMM1N4), INTENT(IN) :: X
      REAL(DP) :: DER0,DER1,DER2,DER3,DER4
      TYPE(ONUMM1N4) :: RES
      
      DER0 = ASIN(X%R)
      DER1 = 1/SQRT(1 - X%R**2)
      DER2 = X%R/(1 - X%R**2)**(3.0D0/2.0D0)
      DER3 = (3*X%R**2/(1 - X%R**2) + 1)/(1 - X%R**2)**(3.0D0/2.0D0)
      DER4 = 3*X%R*(5*X%R**2/(1 - X%R**2) + 3)/(1 - X%R**2)**(5.0D0/2.0D0)

      RES = FEVAL(X,DER0,DER1,DER2,DER3,DER4)

   END FUNCTION ONUMM1N4_ASIN

   ELEMENTAL FUNCTION ONUMM1N4_TANH(X) RESULT(RES)

      TYPE(ONUMM1N4), INTENT(IN) :: X
      REAL(DP) :: DER0,DER1,DER2,DER3,DER4
      TYPE(ONUMM1N4) :: RES
      
      DER0 = TANH(X%R)
      DER1 = 1 - TANH(X%R)**2
      DER2 = 2*(TANH(X%R)**2 - 1)*TANH(X%R)
      DER3 = -2*(TANH(X%R)**2 - 1)*(3*TANH(X%R)**2 - 1)
      DER4 = 8*(TANH(X%R)**2 - 1)*(3*TANH(X%R)**2 - 2)*TANH(X%R)

      RES = FEVAL(X,DER0,DER1,DER2,DER3,DER4)

   END FUNCTION ONUMM1N4_TANH

   ELEMENTAL FUNCTION ONUMM1N4_COSH(X) RESULT(RES)

      TYPE(ONUMM1N4), INTENT(IN) :: X
      REAL(DP) :: DER0,DER1,DER2,DER3,DER4
      TYPE(ONUMM1N4) :: RES
      
      DER0 = COSH(X%R)
      DER1 = SINH(X%R)
      DER2 = COSH(X%R)
      DER3 = SINH(X%R)
      DER4 = COSH(X%R)

      RES = FEVAL(X,DER0,DER1,DER2,DER3,DER4)

   END FUNCTION ONUMM1N4_COSH

   ELEMENTAL FUNCTION ONUMM1N4_SINH(X) RESULT(RES)

      TYPE(ONUMM1N4), INTENT(IN) :: X
      REAL(DP) :: DER0,DER1,DER2,DER3,DER4
      TYPE(ONUMM1N4) :: RES
      
      DER0 = SINH(X%R)
      DER1 = COSH(X%R)
      DER2 = SINH(X%R)
      DER3 = COSH(X%R)
      DER4 = SINH(X%R)

      RES = FEVAL(X,DER0,DER1,DER2,DER3,DER4)

   END FUNCTION ONUMM1N4_SINH

   ELEMENTAL FUNCTION ONUMM1N4_EXP(X) RESULT(RES)

      TYPE(ONUMM1N4), INTENT(IN) :: X
      REAL(DP) :: DER0,DER1,DER2,DER3,DER4
      TYPE(ONUMM1N4) :: RES
      
      DER0 = EXP(X%R)
      DER1 = EXP(X%R)
      DER2 = EXP(X%R)
      DER3 = EXP(X%R)
      DER4 = EXP(X%R)

      RES = FEVAL(X,DER0,DER1,DER2,DER3,DER4)

   END FUNCTION ONUMM1N4_EXP

   ELEMENTAL FUNCTION ONUMM1N4_LOG(X) RESULT(RES)

      TYPE(ONUMM1N4), INTENT(IN) :: X
      REAL(DP) :: DER0,DER1,DER2,DER3,DER4
      TYPE(ONUMM1N4) :: RES
      
      DER0 = LOG(X%R)
      DER1 = 1D0/X%R
      DER2 = -1/X%R**2
      DER3 = 2/X%R**3
      DER4 = -6/X%R**4

      RES = FEVAL(X,DER0,DER1,DER2,DER3,DER4)

   END FUNCTION ONUMM1N4_LOG

   ELEMENTAL FUNCTION ONUMM1N4_POW_OR(X,E) RESULT(RES)

      TYPE(ONUMM1N4), INTENT(IN) :: X
      REAL(DP), INTENT(IN) :: E
      REAL(DP) :: DER0,DER1,DER2,DER3,DER4
      TYPE(ONUMM1N4) :: RES
      
      DER0=0.0d0
      DER1=0.0d0
      DER2=0.0d0
      DER3=0.0d0
      DER4=0.0d0
      
      DER0 = X%R**E
      IF ((E-0)/=0.0d0) THEN
         DER1 = E*X%R**(E - 1)
         IF ((E-1)/=0.0d0) THEN
            DER2 = E*X%R**(E - 2)*(E - 1)
            IF ((E-2)/=0.0d0) THEN
               DER3 = E*X%R**(E - 3)*(E**2 - 3*E + 2)
               IF ((E-3)/=0.0d0) THEN
                  DER4 = E*X%R**(E - 4)*(E**3 - 6*E**2 + 11*E - 6)
               END IF
            END IF
         END IF
      END IF

      RES = FEVAL(X,DER0,DER1,DER2,DER3,DER4)

   END FUNCTION ONUMM1N4_POW_OR

   ELEMENTAL FUNCTION ONUMM1N4_POW_RO(E,X) RESULT(RES)

      TYPE(ONUMM1N4), INTENT(IN) :: X
      REAL(DP), INTENT(IN) :: E
      REAL(DP) :: DER0,DER1,DER2,DER3,DER4
      TYPE(ONUMM1N4) :: RES
      
      
      DER0 = E**X%R
      DER1 = E**X%R*LOG(E)
      DER2 = E**X%R*LOG(E)**2
      DER3 = E**X%R*LOG(E)**3
      DER4 = E**X%R*LOG(E)**4

      RES = FEVAL(X,DER0,DER1,DER2,DER3,DER4)

   END FUNCTION ONUMM1N4_POW_RO

   ELEMENTAL FUNCTION ONUMM1N4_F2EVAL(X,Y,DER0_0,DER1_0,DER1_1, &
                                  DER2_0,DER2_1,DER2_2,DER3_0, &
                                  DER3_1,DER3_2,DER3_3,DER4_0, &
                                  DER4_1,DER4_2,DER4_3,DER4_4)&
      RESULT(RES)
      IMPLICIT NONE
      !  Definitions
      REAL(DP) :: COEF, DELTA
      TYPE(ONUMM1N4), INTENT(IN)  :: X,Y
      REAL(DP), INTENT(IN)  :: DER0_0,DER1_0,DER1_1, &
                               DER2_0,DER2_1,DER2_2,DER3_0, &
                               DER3_1,DER3_2,DER3_3,DER4_0, &
                               DER4_1,DER4_2,DER4_3,DER4_4
      TYPE(ONUMM1N4) :: RES
      TYPE(ONUMM1N4) :: DX, DY

      COEF   = 0.0_DP
      DX     = X
      DY     = Y

      !  Set real part of deltas zero.
      DX%R = 0.0_DP
      DY%R = 0.0_DP

      ! Set real part
      RES = DER0_0

      ! Set order 1
      COEF = DER1_0 / 1.0_DP
      RES = RES + COEF*DX

      COEF = DER1_1 / 1.0_DP
      RES = RES + COEF*DY

      

      ! Set order 2
      COEF = DER2_0 / 2.0_DP
      RES = RES + COEF*DX*DX

      COEF = DER2_1 / 1.0_DP
      RES = RES + COEF*DX*DY

      COEF = DER2_2 / 2.0_DP
      RES = RES + COEF*DY*DY

      

      ! Set order 3
      COEF = DER3_0 / 6.0_DP
      RES = RES + COEF*DX*DX*DX

      COEF = DER3_1 / 2.0_DP
      RES = RES + COEF*DX*DX*DY

      COEF = DER3_2 / 2.0_DP
      RES = RES + COEF*DX*DY*DY

      COEF = DER3_3 / 6.0_DP
      RES = RES + COEF*DY*DY*DY

      

      ! Set order 4
      COEF = DER4_0 / 24.0_DP
      RES = RES + COEF*DX*DX*DX*DX

      COEF = DER4_1 / 6.0_DP
      RES = RES + COEF*DX*DX*DX*DY

      COEF = DER4_2 / 4.0_DP
      RES = RES + COEF*DX*DX*DY*DY

      COEF = DER4_3 / 6.0_DP
      RES = RES + COEF*DX*DY*DY*DY

      COEF = DER4_4 / 24.0_DP
      RES = RES + COEF*DY*DY*DY*DY

      

   END FUNCTION ONUMM1N4_F2EVAL


   ELEMENTAL FUNCTION ONUMM1N4_POW_OO(X,Y) RESULT(RES)

      TYPE(ONUMM1N4), INTENT(IN) :: X, Y
      REAL(DP) :: DER0_0,DER1_0,DER1_1,DER2_0,DER2_1,DER2_2,DER3_0,DER3_1,DER3_2,DER3_3,DER4_0,DER4_1,DER4_2,DER4_3,DER4_4
      TYPE(ONUMM1N4) :: RES
      
      DER0_0 = X%R**Y%R
      DER1_0 = X%R**Y%R*Y%R/X%R
      DER1_1 = X%R**Y%R*LOG(X%R)
      DER2_0 = X%R**Y%R*Y%R*(Y%R - 1)/X%R**2
      DER2_1 = X%R**Y%R*(Y%R*LOG(X%R) + 1)/X%R
      DER2_2 = X%R**Y%R*LOG(X%R)**2
      DER3_0 = X%R**Y%R*Y%R*(Y%R**2 - 3*Y%R + 2)/X%R**3
      DER3_1 = X%R**Y%R*(Y%R**2*LOG(X%R) - Y%R*LOG(X%R) + 2*Y%R - 1)/X%R**2
      DER3_2 = X%R**Y%R*(Y%R*LOG(X%R) + 2)*LOG(X%R)/X%R
      DER3_3 = X%R**Y%R*LOG(X%R)**3
      DER4_0 = X%R**Y%R*Y%R*(Y%R**3 - 6*Y%R**2 + 11*Y%R - 6)/X%R**4
      DER4_1 = X%R**Y%R*(Y%R**3*LOG(X%R) - 3*Y%R**2*LOG(X%R) + 3*Y%R**2 + 2*Y% &
      R*LOG(X%R) - 6*Y%R + 2)/X%R**3
      DER4_2 = X%R**Y%R*(Y%R**2*LOG(X%R)**2 - Y%R*LOG(X%R)**2 + 4*Y%R*LOG(X%R &
      ) - 2*LOG(X%R) + 2)/X%R**2
      DER4_3 = X%R**Y%R*(Y%R*LOG(X%R) + 3)*LOG(X%R)**2/X%R
      DER4_4 = X%R**Y%R*LOG(X%R)**4

      RES = F2EVAL(X,Y,DER0_0,DER1_0,DER1_1,DER2_0,DER2_1,DER2_2,DER3_0,DER3_1,DER3_2,DER3_3,DER4_0,DER4_1,DER4_2,DER4_3,DER4_4)

   END FUNCTION ONUMM1N4_POW_OO


   FUNCTION ONUMM1N4_INV2X2(A,det)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM1N4) , INTENT(IN) :: A(2,2) 
      TYPE(ONUMM1N4) , INTENT(IN), OPTIONAL :: det
      REAL(DP) :: detCalc
      TYPE(ONUMM1N4) :: RES(SIZE(A,1),SIZE(A,2)) 

      IF (PRESENT(det)) THEN
         detCalc=det%R
      ELSE
         detCalc=det2x2(A%R)
      END IF

      ! Get real part 
      RES%R=INV2X2(A%R,detCalc)

      ! Order 1
      RES%E1=-MATMUL(RES%R,(MATMUL(A%E1,RES%R)))

      ! Order 2
      RES%E11=-MATMUL(RES%R,(MATMUL(A%E11,RES%R)+MATMUL(A%E1,RES%E1)))

      ! Order 3
      RES%E111=-MATMUL(RES%R,(MATMUL(A%E111,RES%R)+MATMUL(A%E1,RES%E11)+&
              MATMUL(A%E11,RES%E1)))

      ! Order 4
      RES%E1111=-MATMUL(RES%R,(MATMUL(A%E1111,RES%R)+MATMUL(A%E1,RES%E111)+&
               MATMUL(A%E111,RES%E1)+MATMUL(A%E11,RES%E11)))

   END FUNCTION ONUMM1N4_INV2X2

   FUNCTION ONUMM1N4_INV3X3(A,det)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM1N4) , INTENT(IN) :: A(3,3) 
      TYPE(ONUMM1N4) , INTENT(IN), OPTIONAL :: det
      REAL(DP) :: detCalc
      TYPE(ONUMM1N4) :: RES(SIZE(A,1),SIZE(A,2)) 

      IF (PRESENT(det)) THEN
         detCalc=det%R
      ELSE
         detCalc=det3x3(A%R)
      END IF

      ! Get real part 
      RES%R=INV3X3(A%R,detCalc)

      ! Order 1
      RES%E1=-MATMUL(RES%R,(MATMUL(A%E1,RES%R)))

      ! Order 2
      RES%E11=-MATMUL(RES%R,(MATMUL(A%E11,RES%R)+MATMUL(A%E1,RES%E1)))

      ! Order 3
      RES%E111=-MATMUL(RES%R,(MATMUL(A%E111,RES%R)+MATMUL(A%E1,RES%E11)+&
              MATMUL(A%E11,RES%E1)))

      ! Order 4
      RES%E1111=-MATMUL(RES%R,(MATMUL(A%E1111,RES%R)+MATMUL(A%E1,RES%E111)+&
               MATMUL(A%E111,RES%E1)+MATMUL(A%E11,RES%E11)))

   END FUNCTION ONUMM1N4_INV3X3

   FUNCTION ONUMM1N4_INV4X4(A,det)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM1N4) , INTENT(IN) :: A(4,4) 
      TYPE(ONUMM1N4) , INTENT(IN), OPTIONAL :: det
      REAL(DP) :: detCalc
      TYPE(ONUMM1N4) :: RES(SIZE(A,1),SIZE(A,2)) 

      IF (PRESENT(det)) THEN
         detCalc=det%R
      ELSE
         detCalc=det4x4(A%R)
      END IF

      ! Get real part 
      RES%R=INV4X4(A%R,detCalc)

      ! Order 1
      RES%E1=-MATMUL(RES%R,(MATMUL(A%E1,RES%R)))

      ! Order 2
      RES%E11=-MATMUL(RES%R,(MATMUL(A%E11,RES%R)+MATMUL(A%E1,RES%E1)))

      ! Order 3
      RES%E111=-MATMUL(RES%R,(MATMUL(A%E111,RES%R)+MATMUL(A%E1,RES%E11)+&
              MATMUL(A%E11,RES%E1)))

      ! Order 4
      RES%E1111=-MATMUL(RES%R,(MATMUL(A%E1111,RES%R)+MATMUL(A%E1,RES%E111)+&
               MATMUL(A%E111,RES%E1)+MATMUL(A%E11,RES%E11)))

   END FUNCTION ONUMM1N4_INV4X4

END MODULE OTIM1N4
