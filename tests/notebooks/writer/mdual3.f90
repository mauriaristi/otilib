MODULE MDUAL3

   USE master_parameters
   USE real_utils

   IMPLICIT NONE

   INTEGER, PARAMETER :: NUM_IM_DIR = 8
   INTEGER, PARAMETER :: TORDER     = 3
   INTEGER, PARAMETER :: N_IMDIR_ORDER(4) = [1,3,3,1]

   TYPE MDNUM3
     ! Real
     REAL(DP) :: R
     ! Order 1
     REAL(DP) :: E1
     REAL(DP) :: E2
     REAL(DP) :: E3
     ! Order 2
     REAL(DP) :: E12
     REAL(DP) :: E13
     REAL(DP) :: E23
     ! Order 3
     REAL(DP) :: E123
   END TYPE MDNUM3

   ! Constant imaginary directions.
   ! Order 1
   TYPE(MDNUM3), PARAMETER :: E1 = MDNUM3(0.0_DP,1.0_DP,0.0_DP,0.0_DP,0.0_DP,0.0_DP,0.0_DP,0.0_DP)
   TYPE(MDNUM3), PARAMETER :: E2 = MDNUM3(0.0_DP,0.0_DP,1.0_DP,0.0_DP,0.0_DP,0.0_DP,0.0_DP,0.0_DP)
   TYPE(MDNUM3), PARAMETER :: E3 = MDNUM3(0.0_DP,0.0_DP,0.0_DP,1.0_DP,0.0_DP,0.0_DP,0.0_DP,0.0_DP)
   ! Order 2
   TYPE(MDNUM3), PARAMETER :: E12 = MDNUM3(0.0_DP,0.0_DP,0.0_DP,0.0_DP,1.0_DP,0.0_DP,0.0_DP,0.0_DP)
   TYPE(MDNUM3), PARAMETER :: E13 = MDNUM3(0.0_DP,0.0_DP,0.0_DP,0.0_DP,0.0_DP,1.0_DP,0.0_DP,0.0_DP)
   TYPE(MDNUM3), PARAMETER :: E23 = MDNUM3(0.0_DP,0.0_DP,0.0_DP,0.0_DP,0.0_DP,0.0_DP,1.0_DP,0.0_DP)
   ! Order 3
   TYPE(MDNUM3), PARAMETER :: E123 = MDNUM3(0.0_DP,0.0_DP,0.0_DP,0.0_DP,0.0_DP,0.0_DP,0.0_DP,1.0_DP)


   INTERFACE OPERATOR(*)
      MODULE PROCEDURE MDNUM3_MUL_OO_SS,MDNUM3_MUL_RO_SS,MDNUM3_MUL_OR_SS,MDNUM3_MUL_OO_VS,&
                       MDNUM3_MUL_RO_VS,MDNUM3_MUL_OR_VS,MDNUM3_MUL_OO_MS,MDNUM3_MUL_RO_MS,&
                       MDNUM3_MUL_OR_MS,MDNUM3_MUL_OO_SV,MDNUM3_MUL_RO_SV,MDNUM3_MUL_OR_SV,&
                       MDNUM3_MUL_OO_SM,MDNUM3_MUL_RO_SM,MDNUM3_MUL_OR_SM
   END INTERFACE

   INTERFACE OPERATOR(+)
      MODULE PROCEDURE MDNUM3_ADD_OO_SS,MDNUM3_ADD_RO_SS,MDNUM3_ADD_OR_SS,MDNUM3_ADD_OO_VS,&
                       MDNUM3_ADD_RO_VS,MDNUM3_ADD_OR_VS,MDNUM3_ADD_OO_MS,MDNUM3_ADD_RO_MS,&
                       MDNUM3_ADD_OR_MS,MDNUM3_ADD_OO_SV,MDNUM3_ADD_RO_SV,MDNUM3_ADD_OR_SV,&
                       MDNUM3_ADD_OO_SM,MDNUM3_ADD_RO_SM,MDNUM3_ADD_OR_SM
   END INTERFACE

   INTERFACE OPERATOR(-)
      MODULE PROCEDURE MDNUM3_NEG,MDNUM3_SUB_OO_SS,MDNUM3_SUB_RO_SS,MDNUM3_SUB_OR_SS,&
                       MDNUM3_SUB_OO_VS,MDNUM3_SUB_RO_VS,MDNUM3_SUB_OR_VS,MDNUM3_SUB_OO_MS,&
                       MDNUM3_SUB_RO_MS,MDNUM3_SUB_OR_MS,MDNUM3_SUB_OO_SV,MDNUM3_SUB_RO_SV,&
                       MDNUM3_SUB_OR_SV,MDNUM3_SUB_OO_SM,MDNUM3_SUB_RO_SM,MDNUM3_SUB_OR_SM
   END INTERFACE

   INTERFACE OPERATOR(/)
      MODULE PROCEDURE MDNUM3_DIVISION_OO,MDNUM3_DIVISION_OR,MDNUM3_DIVISION_RO
   END INTERFACE

   INTERFACE ASSIGNMENT(=)
      MODULE PROCEDURE MDNUM3_ASSIGN_R
   END INTERFACE

   INTERFACE OPERATOR(**)
      MODULE PROCEDURE MDNUM3_POW_OR,MDNUM3_POW_RO,MDNUM3_POW_OO
   END INTERFACE

   INTERFACE PPRINT
      MODULE PROCEDURE MDNUM3_PPRINT_S,MDNUM3_PPRINT_V,MDNUM3_PPRINT_M
   END INTERFACE

   INTERFACE TRANSPOSE
      MODULE PROCEDURE MDNUM3_TRANSPOSE
   END INTERFACE

   INTERFACE MATMUL
      MODULE PROCEDURE MDNUM3_MATMUL_MDNUM3,R_MATMUL_MDNUM3,MDNUM3_MATMUL_R
   END INTERFACE

   INTERFACE DOT_PRODUCT
      MODULE PROCEDURE MDNUM3_DOT_PRODUCT_MDNUM3,R_DOT_PRODUCT_MDNUM3,MDNUM3_DOT_PRODUCT_R
   END INTERFACE

   INTERFACE UNFOLD
      MODULE PROCEDURE MDNUM3_TO_CR_MAT_S,MDNUM3_TO_CR_MAT_V,MDNUM3_TO_CR_MAT_M
   END INTERFACE

   INTERFACE TO_CR
      MODULE PROCEDURE MDNUM3_TO_CR_MAT_S,MDNUM3_TO_CR_MAT_V,MDNUM3_TO_CR_MAT_M
   END INTERFACE

   INTERFACE SIN
      MODULE PROCEDURE MDNUM3_SIN
   END INTERFACE

   INTERFACE COS
      MODULE PROCEDURE MDNUM3_COS
   END INTERFACE

   INTERFACE TAN
      MODULE PROCEDURE MDNUM3_TAN
   END INTERFACE

   INTERFACE ASIN
      MODULE PROCEDURE MDNUM3_ASIN
   END INTERFACE

   INTERFACE ACOS
      MODULE PROCEDURE MDNUM3_ACOS
   END INTERFACE

   INTERFACE ATAN
      MODULE PROCEDURE MDNUM3_ATAN
   END INTERFACE

   INTERFACE SINH
      MODULE PROCEDURE MDNUM3_SINH
   END INTERFACE

   INTERFACE COSH
      MODULE PROCEDURE MDNUM3_COSH
   END INTERFACE

   INTERFACE TANH
      MODULE PROCEDURE MDNUM3_TANH
   END INTERFACE

   INTERFACE SQRT
      MODULE PROCEDURE MDNUM3_SQRT
   END INTERFACE

   INTERFACE LOG
      MODULE PROCEDURE MDNUM3_LOG
   END INTERFACE

   INTERFACE EXP
      MODULE PROCEDURE MDNUM3_EXP
   END INTERFACE

   INTERFACE GEM
      MODULE PROCEDURE MDNUM3_GEM_OOO,MDNUM3_GEM_ROO,MDNUM3_GEM_ORO
   END INTERFACE

   INTERFACE FEVAL
      MODULE PROCEDURE MDNUM3_FEVAL
   END INTERFACE

   INTERFACE F2EVAL
      MODULE PROCEDURE MDNUM3_F2EVAL
   END INTERFACE

   INTERFACE REAL
      MODULE PROCEDURE MDNUM3_REAL
   END INTERFACE

   INTERFACE DET2X2
      MODULE PROCEDURE MDNUM3_det2x2
   END INTERFACE

   INTERFACE DET3X3
      MODULE PROCEDURE MDNUM3_det3x3
   END INTERFACE

   INTERFACE DET4X4
      MODULE PROCEDURE MDNUM3_det4x4
   END INTERFACE

   INTERFACE INV2X2
      MODULE PROCEDURE MDNUM3_INV2X2
   END INTERFACE

   INTERFACE INV3X3
      MODULE PROCEDURE MDNUM3_INV3X3
   END INTERFACE

   INTERFACE INV4X4
      MODULE PROCEDURE MDNUM3_INV4X4
   END INTERFACE

   INTERFACE GETIM
      MODULE PROCEDURE MDNUM3_GETIM_S,MDNUM3_GETIM_V,MDNUM3_GETIM_M
   END INTERFACE

   INTERFACE SETIM
      MODULE PROCEDURE MDNUM3_SETIM_S,MDNUM3_SETIM_V,MDNUM3_SETIM_M
   END INTERFACE

   CONTAINS

   ELEMENTAL SUBROUTINE MDNUM3_ASSIGN_R(RES,LHS)
      
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS 
      TYPE(MDNUM3), INTENT(OUT) :: RES 

      ! Assign like function 'LHS'
      ! Real
      RES%R = LHS

      ! Order 1
      RES%E1 = 0.0_DP
      RES%E2 = 0.0_DP
      RES%E3 = 0.0_DP

      ! Order 2
      RES%E12 = 0.0_DP
      RES%E13 = 0.0_DP
      RES%E23 = 0.0_DP

      ! Order 3
      RES%E123 = 0.0_DP

   END SUBROUTINE MDNUM3_ASSIGN_R

   ELEMENTAL FUNCTION MDNUM3_NEG(LHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(MDNUM3), INTENT(IN) :: LHS 
      TYPE(MDNUM3) :: RES 

      ! Negation like function '-LHS'
      ! Real
      RES%R = -LHS%R
      ! Order 1
      RES%E1 = -LHS%E1
      RES%E2 = -LHS%E2
      RES%E3 = -LHS%E3
      ! Order 2
      RES%E12 = -LHS%E12
      RES%E13 = -LHS%E13
      RES%E23 = -LHS%E23
      ! Order 3
      RES%E123 = -LHS%E123

   END FUNCTION MDNUM3_NEG

   ELEMENTAL FUNCTION MDNUM3_ADD_OO_SS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(MDNUM3), INTENT(IN) :: LHS
      TYPE(MDNUM3), INTENT(IN) :: RHS
      TYPE(MDNUM3) :: RES 

      ! Addition like function 'LHS + RHS'
      !  Real
      RES%R = LHS%R + RHS%R

      ! Order 1
      RES%E1 = LHS%E1 + RHS%E1
      RES%E2 = LHS%E2 + RHS%E2
      RES%E3 = LHS%E3 + RHS%E3

      ! Order 2
      RES%E12 = LHS%E12 + RHS%E12
      RES%E13 = LHS%E13 + RHS%E13
      RES%E23 = LHS%E23 + RHS%E23

      ! Order 3
      RES%E123 = LHS%E123 + RHS%E123

   END FUNCTION MDNUM3_ADD_OO_SS

   ELEMENTAL FUNCTION MDNUM3_ADD_RO_SS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS
      TYPE(MDNUM3), INTENT(IN) :: RHS
      TYPE(MDNUM3) :: RES 

      ! Addition like function 'LHS + RHS'
      ! Real
      RES%R = LHS + RHS%R

      ! Order 1
      RES%E1 =  + RHS%E1
      RES%E2 =  + RHS%E2
      RES%E3 =  + RHS%E3

      ! Order 2
      RES%E12 =  + RHS%E12
      RES%E13 =  + RHS%E13
      RES%E23 =  + RHS%E23

      ! Order 3
      RES%E123 =  + RHS%E123

   END FUNCTION MDNUM3_ADD_RO_SS

   ELEMENTAL FUNCTION MDNUM3_ADD_OR_SS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(MDNUM3), INTENT(IN) :: LHS
      REAL(DP), INTENT(IN) :: RHS
      TYPE(MDNUM3) :: RES 

      ! Addition like function 'LHS + RHS'
      ! Real
      RES%R = LHS%R + RHS

      ! Order 1
      RES%E1 = LHS%E1
      RES%E2 = LHS%E2
      RES%E3 = LHS%E3

      ! Order 2
      RES%E12 = LHS%E12
      RES%E13 = LHS%E13
      RES%E23 = LHS%E23

      ! Order 3
      RES%E123 = LHS%E123

   END FUNCTION MDNUM3_ADD_OR_SS

   ELEMENTAL FUNCTION MDNUM3_SUB_OO_SS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(MDNUM3), INTENT(IN) :: LHS
      TYPE(MDNUM3), INTENT(IN) :: RHS
      TYPE(MDNUM3) :: RES 

      ! Addition like function 'LHS - RHS'
      !  Real
      RES%R = LHS%R - RHS%R

      ! Order 1
      RES%E1 = LHS%E1 - RHS%E1
      RES%E2 = LHS%E2 - RHS%E2
      RES%E3 = LHS%E3 - RHS%E3

      ! Order 2
      RES%E12 = LHS%E12 - RHS%E12
      RES%E13 = LHS%E13 - RHS%E13
      RES%E23 = LHS%E23 - RHS%E23

      ! Order 3
      RES%E123 = LHS%E123 - RHS%E123

   END FUNCTION MDNUM3_SUB_OO_SS

   ELEMENTAL FUNCTION MDNUM3_SUB_RO_SS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS
      TYPE(MDNUM3), INTENT(IN) :: RHS
      TYPE(MDNUM3) :: RES 

      ! Addition like function 'LHS - RHS'
      ! Real
      RES%R = LHS - RHS%R

      ! Order 1
      RES%E1 =  - RHS%E1
      RES%E2 =  - RHS%E2
      RES%E3 =  - RHS%E3

      ! Order 2
      RES%E12 =  - RHS%E12
      RES%E13 =  - RHS%E13
      RES%E23 =  - RHS%E23

      ! Order 3
      RES%E123 =  - RHS%E123

   END FUNCTION MDNUM3_SUB_RO_SS

   ELEMENTAL FUNCTION MDNUM3_SUB_OR_SS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(MDNUM3), INTENT(IN) :: LHS
      REAL(DP), INTENT(IN) :: RHS
      TYPE(MDNUM3) :: RES 

      ! Addition like function 'LHS - RHS'
      ! Real
      RES%R = LHS%R - RHS

      ! Order 1
      RES%E1 = LHS%E1
      RES%E2 = LHS%E2
      RES%E3 = LHS%E3

      ! Order 2
      RES%E12 = LHS%E12
      RES%E13 = LHS%E13
      RES%E23 = LHS%E23

      ! Order 3
      RES%E123 = LHS%E123

   END FUNCTION MDNUM3_SUB_OR_SS

   ELEMENTAL FUNCTION MDNUM3_MUL_OO_SS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(MDNUM3), INTENT(IN) :: LHS
      TYPE(MDNUM3), INTENT(IN) :: RHS
      TYPE(MDNUM3) :: RES 

      !  Multiplication like function 'LHS*RHS'
      ! Order 3
      RES%E123 = LHS%R*RHS%E123 + LHS%E123*RHS%R +  &
              LHS%E1*RHS%E23 + LHS%E23*RHS%E1 + LHS%E2*RHS%E13 +  &
              LHS%E13*RHS%E2 + LHS%E3*RHS%E12 + LHS%E12*RHS%E3
      ! Order 2
      RES%E12 = LHS%R*RHS%E12 + LHS%E12*RHS%R +  &
             LHS%E1*RHS%E2 + LHS%E2*RHS%E1
      RES%E13 = LHS%R*RHS%E13 + LHS%E13*RHS%R +  &
             LHS%E1*RHS%E3 + LHS%E3*RHS%E1
      RES%E23 = LHS%R*RHS%E23 + LHS%E23*RHS%R +  &
             LHS%E2*RHS%E3 + LHS%E3*RHS%E2
      ! Order 1
      RES%E1 = LHS%R*RHS%E1 + LHS%E1*RHS%R
      RES%E2 = LHS%R*RHS%E2 + LHS%E2*RHS%R
      RES%E3 = LHS%R*RHS%E3 + LHS%E3*RHS%R
      ! Order 0
      RES%R = LHS%R*RHS%R

   END FUNCTION MDNUM3_MUL_OO_SS

   ELEMENTAL FUNCTION MDNUM3_MUL_RO_SS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS
      TYPE(MDNUM3), INTENT(IN) :: RHS
      TYPE(MDNUM3) :: RES 

      ! Multiplication like function 'LHS*RHS'
      !  Real
      RES%R = LHS*RHS%R

      ! Order 1
      RES%E1 = LHS*RHS%E1
      RES%E2 = LHS*RHS%E2
      RES%E3 = LHS*RHS%E3

      ! Order 2
      RES%E12 = LHS*RHS%E12
      RES%E13 = LHS*RHS%E13
      RES%E23 = LHS*RHS%E23

      ! Order 3
      RES%E123 = LHS*RHS%E123

   END FUNCTION MDNUM3_MUL_RO_SS

   ELEMENTAL FUNCTION MDNUM3_MUL_OR_SS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(MDNUM3), INTENT(IN) :: LHS
      REAL(DP), INTENT(IN) :: RHS
      TYPE(MDNUM3) :: RES 

      ! Multiplication like function 'LHS*RHS'
      !  Real
      RES%R = LHS%R*RHS

      ! Order 1
      RES%E1 = LHS%E1*RHS
      RES%E2 = LHS%E2*RHS
      RES%E3 = LHS%E3*RHS

      ! Order 2
      RES%E12 = LHS%E12*RHS
      RES%E13 = LHS%E13*RHS
      RES%E23 = LHS%E23*RHS

      ! Order 3
      RES%E123 = LHS%E123*RHS

   END FUNCTION MDNUM3_MUL_OR_SS

   FUNCTION MDNUM3_ADD_OO_VS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(MDNUM3), INTENT(IN) :: LHS(:)
      TYPE(MDNUM3), INTENT(IN) :: RHS
      TYPE(MDNUM3) :: RES(SIZE(LHS,1)) 

      ! Addition like function 'LHS + RHS'
      !  Real
      RES%R = LHS%R + RHS%R

      ! Order 1
      RES%E1 = LHS%E1 + RHS%E1
      RES%E2 = LHS%E2 + RHS%E2
      RES%E3 = LHS%E3 + RHS%E3

      ! Order 2
      RES%E12 = LHS%E12 + RHS%E12
      RES%E13 = LHS%E13 + RHS%E13
      RES%E23 = LHS%E23 + RHS%E23

      ! Order 3
      RES%E123 = LHS%E123 + RHS%E123

   END FUNCTION MDNUM3_ADD_OO_VS

   FUNCTION MDNUM3_ADD_RO_VS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS(:)
      TYPE(MDNUM3), INTENT(IN) :: RHS
      TYPE(MDNUM3) :: RES(SIZE(LHS,1)) 

      ! Addition like function 'LHS + RHS'
      ! Real
      RES%R = LHS + RHS%R

      ! Order 1
      RES%E1 =  + RHS%E1
      RES%E2 =  + RHS%E2
      RES%E3 =  + RHS%E3

      ! Order 2
      RES%E12 =  + RHS%E12
      RES%E13 =  + RHS%E13
      RES%E23 =  + RHS%E23

      ! Order 3
      RES%E123 =  + RHS%E123

   END FUNCTION MDNUM3_ADD_RO_VS

   FUNCTION MDNUM3_ADD_OR_VS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(MDNUM3), INTENT(IN) :: LHS(:)
      REAL(DP), INTENT(IN) :: RHS
      TYPE(MDNUM3) :: RES(SIZE(LHS,1)) 

      ! Addition like function 'LHS + RHS'
      ! Real
      RES%R = LHS%R + RHS

      ! Order 1
      RES%E1 = LHS%E1
      RES%E2 = LHS%E2
      RES%E3 = LHS%E3

      ! Order 2
      RES%E12 = LHS%E12
      RES%E13 = LHS%E13
      RES%E23 = LHS%E23

      ! Order 3
      RES%E123 = LHS%E123

   END FUNCTION MDNUM3_ADD_OR_VS

   FUNCTION MDNUM3_SUB_OO_VS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(MDNUM3), INTENT(IN) :: LHS(:)
      TYPE(MDNUM3), INTENT(IN) :: RHS
      TYPE(MDNUM3) :: RES(SIZE(LHS,1)) 

      ! Addition like function 'LHS - RHS'
      !  Real
      RES%R = LHS%R - RHS%R

      ! Order 1
      RES%E1 = LHS%E1 - RHS%E1
      RES%E2 = LHS%E2 - RHS%E2
      RES%E3 = LHS%E3 - RHS%E3

      ! Order 2
      RES%E12 = LHS%E12 - RHS%E12
      RES%E13 = LHS%E13 - RHS%E13
      RES%E23 = LHS%E23 - RHS%E23

      ! Order 3
      RES%E123 = LHS%E123 - RHS%E123

   END FUNCTION MDNUM3_SUB_OO_VS

   FUNCTION MDNUM3_SUB_RO_VS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS(:)
      TYPE(MDNUM3), INTENT(IN) :: RHS
      TYPE(MDNUM3) :: RES(SIZE(LHS,1)) 

      ! Addition like function 'LHS - RHS'
      ! Real
      RES%R = LHS - RHS%R

      ! Order 1
      RES%E1 =  - RHS%E1
      RES%E2 =  - RHS%E2
      RES%E3 =  - RHS%E3

      ! Order 2
      RES%E12 =  - RHS%E12
      RES%E13 =  - RHS%E13
      RES%E23 =  - RHS%E23

      ! Order 3
      RES%E123 =  - RHS%E123

   END FUNCTION MDNUM3_SUB_RO_VS

   FUNCTION MDNUM3_SUB_OR_VS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(MDNUM3), INTENT(IN) :: LHS(:)
      REAL(DP), INTENT(IN) :: RHS
      TYPE(MDNUM3) :: RES(SIZE(LHS,1)) 

      ! Addition like function 'LHS - RHS'
      ! Real
      RES%R = LHS%R - RHS

      ! Order 1
      RES%E1 = LHS%E1
      RES%E2 = LHS%E2
      RES%E3 = LHS%E3

      ! Order 2
      RES%E12 = LHS%E12
      RES%E13 = LHS%E13
      RES%E23 = LHS%E23

      ! Order 3
      RES%E123 = LHS%E123

   END FUNCTION MDNUM3_SUB_OR_VS

   FUNCTION MDNUM3_MUL_OO_VS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(MDNUM3), INTENT(IN) :: LHS(:)
      TYPE(MDNUM3), INTENT(IN) :: RHS
      TYPE(MDNUM3) :: RES(SIZE(LHS,1)) 

      !  Multiplication like function 'LHS*RHS'
      ! Order 3
      RES%E123 = LHS%R*RHS%E123 + LHS%E123*RHS%R +  &
              LHS%E1*RHS%E23 + LHS%E23*RHS%E1 + LHS%E2*RHS%E13 +  &
              LHS%E13*RHS%E2 + LHS%E3*RHS%E12 + LHS%E12*RHS%E3
      ! Order 2
      RES%E12 = LHS%R*RHS%E12 + LHS%E12*RHS%R +  &
             LHS%E1*RHS%E2 + LHS%E2*RHS%E1
      RES%E13 = LHS%R*RHS%E13 + LHS%E13*RHS%R +  &
             LHS%E1*RHS%E3 + LHS%E3*RHS%E1
      RES%E23 = LHS%R*RHS%E23 + LHS%E23*RHS%R +  &
             LHS%E2*RHS%E3 + LHS%E3*RHS%E2
      ! Order 1
      RES%E1 = LHS%R*RHS%E1 + LHS%E1*RHS%R
      RES%E2 = LHS%R*RHS%E2 + LHS%E2*RHS%R
      RES%E3 = LHS%R*RHS%E3 + LHS%E3*RHS%R
      ! Order 0
      RES%R = LHS%R*RHS%R

   END FUNCTION MDNUM3_MUL_OO_VS

   FUNCTION MDNUM3_MUL_RO_VS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS(:)
      TYPE(MDNUM3), INTENT(IN) :: RHS
      TYPE(MDNUM3) :: RES(SIZE(LHS,1)) 

      ! Multiplication like function 'LHS*RHS'
      !  Real
      RES%R = LHS*RHS%R

      ! Order 1
      RES%E1 = LHS*RHS%E1
      RES%E2 = LHS*RHS%E2
      RES%E3 = LHS*RHS%E3

      ! Order 2
      RES%E12 = LHS*RHS%E12
      RES%E13 = LHS*RHS%E13
      RES%E23 = LHS*RHS%E23

      ! Order 3
      RES%E123 = LHS*RHS%E123

   END FUNCTION MDNUM3_MUL_RO_VS

   FUNCTION MDNUM3_MUL_OR_VS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(MDNUM3), INTENT(IN) :: LHS(:)
      REAL(DP), INTENT(IN) :: RHS
      TYPE(MDNUM3) :: RES(SIZE(LHS,1)) 

      ! Multiplication like function 'LHS*RHS'
      !  Real
      RES%R = LHS%R*RHS

      ! Order 1
      RES%E1 = LHS%E1*RHS
      RES%E2 = LHS%E2*RHS
      RES%E3 = LHS%E3*RHS

      ! Order 2
      RES%E12 = LHS%E12*RHS
      RES%E13 = LHS%E13*RHS
      RES%E23 = LHS%E23*RHS

      ! Order 3
      RES%E123 = LHS%E123*RHS

   END FUNCTION MDNUM3_MUL_OR_VS

   FUNCTION MDNUM3_ADD_OO_MS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(MDNUM3), INTENT(IN) :: LHS(:,:)
      TYPE(MDNUM3), INTENT(IN) :: RHS
      TYPE(MDNUM3) :: RES(SIZE(LHS,1),SIZE(LHS,2)) 

      ! Addition like function 'LHS + RHS'
      !  Real
      RES%R = LHS%R + RHS%R

      ! Order 1
      RES%E1 = LHS%E1 + RHS%E1
      RES%E2 = LHS%E2 + RHS%E2
      RES%E3 = LHS%E3 + RHS%E3

      ! Order 2
      RES%E12 = LHS%E12 + RHS%E12
      RES%E13 = LHS%E13 + RHS%E13
      RES%E23 = LHS%E23 + RHS%E23

      ! Order 3
      RES%E123 = LHS%E123 + RHS%E123

   END FUNCTION MDNUM3_ADD_OO_MS

   FUNCTION MDNUM3_ADD_RO_MS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS(:,:)
      TYPE(MDNUM3), INTENT(IN) :: RHS
      TYPE(MDNUM3) :: RES(SIZE(LHS,1),SIZE(LHS,2)) 

      ! Addition like function 'LHS + RHS'
      ! Real
      RES%R = LHS + RHS%R

      ! Order 1
      RES%E1 =  + RHS%E1
      RES%E2 =  + RHS%E2
      RES%E3 =  + RHS%E3

      ! Order 2
      RES%E12 =  + RHS%E12
      RES%E13 =  + RHS%E13
      RES%E23 =  + RHS%E23

      ! Order 3
      RES%E123 =  + RHS%E123

   END FUNCTION MDNUM3_ADD_RO_MS

   FUNCTION MDNUM3_ADD_OR_MS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(MDNUM3), INTENT(IN) :: LHS(:,:)
      REAL(DP), INTENT(IN) :: RHS
      TYPE(MDNUM3) :: RES(SIZE(LHS,1),SIZE(LHS,2)) 

      ! Addition like function 'LHS + RHS'
      ! Real
      RES%R = LHS%R + RHS

      ! Order 1
      RES%E1 = LHS%E1
      RES%E2 = LHS%E2
      RES%E3 = LHS%E3

      ! Order 2
      RES%E12 = LHS%E12
      RES%E13 = LHS%E13
      RES%E23 = LHS%E23

      ! Order 3
      RES%E123 = LHS%E123

   END FUNCTION MDNUM3_ADD_OR_MS

   FUNCTION MDNUM3_SUB_OO_MS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(MDNUM3), INTENT(IN) :: LHS(:,:)
      TYPE(MDNUM3), INTENT(IN) :: RHS
      TYPE(MDNUM3) :: RES(SIZE(LHS,1),SIZE(LHS,2)) 

      ! Addition like function 'LHS - RHS'
      !  Real
      RES%R = LHS%R - RHS%R

      ! Order 1
      RES%E1 = LHS%E1 - RHS%E1
      RES%E2 = LHS%E2 - RHS%E2
      RES%E3 = LHS%E3 - RHS%E3

      ! Order 2
      RES%E12 = LHS%E12 - RHS%E12
      RES%E13 = LHS%E13 - RHS%E13
      RES%E23 = LHS%E23 - RHS%E23

      ! Order 3
      RES%E123 = LHS%E123 - RHS%E123

   END FUNCTION MDNUM3_SUB_OO_MS

   FUNCTION MDNUM3_SUB_RO_MS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS(:,:)
      TYPE(MDNUM3), INTENT(IN) :: RHS
      TYPE(MDNUM3) :: RES(SIZE(LHS,1),SIZE(LHS,2)) 

      ! Addition like function 'LHS - RHS'
      ! Real
      RES%R = LHS - RHS%R

      ! Order 1
      RES%E1 =  - RHS%E1
      RES%E2 =  - RHS%E2
      RES%E3 =  - RHS%E3

      ! Order 2
      RES%E12 =  - RHS%E12
      RES%E13 =  - RHS%E13
      RES%E23 =  - RHS%E23

      ! Order 3
      RES%E123 =  - RHS%E123

   END FUNCTION MDNUM3_SUB_RO_MS

   FUNCTION MDNUM3_SUB_OR_MS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(MDNUM3), INTENT(IN) :: LHS(:,:)
      REAL(DP), INTENT(IN) :: RHS
      TYPE(MDNUM3) :: RES(SIZE(LHS,1),SIZE(LHS,2)) 

      ! Addition like function 'LHS - RHS'
      ! Real
      RES%R = LHS%R - RHS

      ! Order 1
      RES%E1 = LHS%E1
      RES%E2 = LHS%E2
      RES%E3 = LHS%E3

      ! Order 2
      RES%E12 = LHS%E12
      RES%E13 = LHS%E13
      RES%E23 = LHS%E23

      ! Order 3
      RES%E123 = LHS%E123

   END FUNCTION MDNUM3_SUB_OR_MS

   FUNCTION MDNUM3_MUL_OO_MS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(MDNUM3), INTENT(IN) :: LHS(:,:)
      TYPE(MDNUM3), INTENT(IN) :: RHS
      TYPE(MDNUM3) :: RES(SIZE(LHS,1),SIZE(LHS,2)) 

      !  Multiplication like function 'LHS*RHS'
      ! Order 3
      RES%E123 = LHS%R*RHS%E123 + LHS%E123*RHS%R +  &
              LHS%E1*RHS%E23 + LHS%E23*RHS%E1 + LHS%E2*RHS%E13 +  &
              LHS%E13*RHS%E2 + LHS%E3*RHS%E12 + LHS%E12*RHS%E3
      ! Order 2
      RES%E12 = LHS%R*RHS%E12 + LHS%E12*RHS%R +  &
             LHS%E1*RHS%E2 + LHS%E2*RHS%E1
      RES%E13 = LHS%R*RHS%E13 + LHS%E13*RHS%R +  &
             LHS%E1*RHS%E3 + LHS%E3*RHS%E1
      RES%E23 = LHS%R*RHS%E23 + LHS%E23*RHS%R +  &
             LHS%E2*RHS%E3 + LHS%E3*RHS%E2
      ! Order 1
      RES%E1 = LHS%R*RHS%E1 + LHS%E1*RHS%R
      RES%E2 = LHS%R*RHS%E2 + LHS%E2*RHS%R
      RES%E3 = LHS%R*RHS%E3 + LHS%E3*RHS%R
      ! Order 0
      RES%R = LHS%R*RHS%R

   END FUNCTION MDNUM3_MUL_OO_MS

   FUNCTION MDNUM3_MUL_RO_MS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS(:,:)
      TYPE(MDNUM3), INTENT(IN) :: RHS
      TYPE(MDNUM3) :: RES(SIZE(LHS,1),SIZE(LHS,2)) 

      ! Multiplication like function 'LHS*RHS'
      !  Real
      RES%R = LHS*RHS%R

      ! Order 1
      RES%E1 = LHS*RHS%E1
      RES%E2 = LHS*RHS%E2
      RES%E3 = LHS*RHS%E3

      ! Order 2
      RES%E12 = LHS*RHS%E12
      RES%E13 = LHS*RHS%E13
      RES%E23 = LHS*RHS%E23

      ! Order 3
      RES%E123 = LHS*RHS%E123

   END FUNCTION MDNUM3_MUL_RO_MS

   FUNCTION MDNUM3_MUL_OR_MS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(MDNUM3), INTENT(IN) :: LHS(:,:)
      REAL(DP), INTENT(IN) :: RHS
      TYPE(MDNUM3) :: RES(SIZE(LHS,1),SIZE(LHS,2)) 

      ! Multiplication like function 'LHS*RHS'
      !  Real
      RES%R = LHS%R*RHS

      ! Order 1
      RES%E1 = LHS%E1*RHS
      RES%E2 = LHS%E2*RHS
      RES%E3 = LHS%E3*RHS

      ! Order 2
      RES%E12 = LHS%E12*RHS
      RES%E13 = LHS%E13*RHS
      RES%E23 = LHS%E23*RHS

      ! Order 3
      RES%E123 = LHS%E123*RHS

   END FUNCTION MDNUM3_MUL_OR_MS

   FUNCTION MDNUM3_ADD_OO_SV(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(MDNUM3), INTENT(IN) :: LHS
      TYPE(MDNUM3), INTENT(IN) :: RHS(:)
      TYPE(MDNUM3) :: RES(SIZE(RHS,1)) 

      ! Addition like function 'LHS + RHS'
      !  Real
      RES%R = LHS%R + RHS%R

      ! Order 1
      RES%E1 = LHS%E1 + RHS%E1
      RES%E2 = LHS%E2 + RHS%E2
      RES%E3 = LHS%E3 + RHS%E3

      ! Order 2
      RES%E12 = LHS%E12 + RHS%E12
      RES%E13 = LHS%E13 + RHS%E13
      RES%E23 = LHS%E23 + RHS%E23

      ! Order 3
      RES%E123 = LHS%E123 + RHS%E123

   END FUNCTION MDNUM3_ADD_OO_SV

   FUNCTION MDNUM3_ADD_RO_SV(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS
      TYPE(MDNUM3), INTENT(IN) :: RHS(:)
      TYPE(MDNUM3) :: RES(SIZE(RHS,1)) 

      ! Addition like function 'LHS + RHS'
      ! Real
      RES%R = LHS + RHS%R

      ! Order 1
      RES%E1 =  + RHS%E1
      RES%E2 =  + RHS%E2
      RES%E3 =  + RHS%E3

      ! Order 2
      RES%E12 =  + RHS%E12
      RES%E13 =  + RHS%E13
      RES%E23 =  + RHS%E23

      ! Order 3
      RES%E123 =  + RHS%E123

   END FUNCTION MDNUM3_ADD_RO_SV

   FUNCTION MDNUM3_ADD_OR_SV(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(MDNUM3), INTENT(IN) :: LHS
      REAL(DP), INTENT(IN) :: RHS(:)
      TYPE(MDNUM3) :: RES(SIZE(RHS,1)) 

      ! Addition like function 'LHS + RHS'
      ! Real
      RES%R = LHS%R + RHS

      ! Order 1
      RES%E1 = LHS%E1
      RES%E2 = LHS%E2
      RES%E3 = LHS%E3

      ! Order 2
      RES%E12 = LHS%E12
      RES%E13 = LHS%E13
      RES%E23 = LHS%E23

      ! Order 3
      RES%E123 = LHS%E123

   END FUNCTION MDNUM3_ADD_OR_SV

   FUNCTION MDNUM3_SUB_OO_SV(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(MDNUM3), INTENT(IN) :: LHS
      TYPE(MDNUM3), INTENT(IN) :: RHS(:)
      TYPE(MDNUM3) :: RES(SIZE(RHS,1)) 

      ! Addition like function 'LHS - RHS'
      !  Real
      RES%R = LHS%R - RHS%R

      ! Order 1
      RES%E1 = LHS%E1 - RHS%E1
      RES%E2 = LHS%E2 - RHS%E2
      RES%E3 = LHS%E3 - RHS%E3

      ! Order 2
      RES%E12 = LHS%E12 - RHS%E12
      RES%E13 = LHS%E13 - RHS%E13
      RES%E23 = LHS%E23 - RHS%E23

      ! Order 3
      RES%E123 = LHS%E123 - RHS%E123

   END FUNCTION MDNUM3_SUB_OO_SV

   FUNCTION MDNUM3_SUB_RO_SV(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS
      TYPE(MDNUM3), INTENT(IN) :: RHS(:)
      TYPE(MDNUM3) :: RES(SIZE(RHS,1)) 

      ! Addition like function 'LHS - RHS'
      ! Real
      RES%R = LHS - RHS%R

      ! Order 1
      RES%E1 =  - RHS%E1
      RES%E2 =  - RHS%E2
      RES%E3 =  - RHS%E3

      ! Order 2
      RES%E12 =  - RHS%E12
      RES%E13 =  - RHS%E13
      RES%E23 =  - RHS%E23

      ! Order 3
      RES%E123 =  - RHS%E123

   END FUNCTION MDNUM3_SUB_RO_SV

   FUNCTION MDNUM3_SUB_OR_SV(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(MDNUM3), INTENT(IN) :: LHS
      REAL(DP), INTENT(IN) :: RHS(:)
      TYPE(MDNUM3) :: RES(SIZE(RHS,1)) 

      ! Addition like function 'LHS - RHS'
      ! Real
      RES%R = LHS%R - RHS

      ! Order 1
      RES%E1 = LHS%E1
      RES%E2 = LHS%E2
      RES%E3 = LHS%E3

      ! Order 2
      RES%E12 = LHS%E12
      RES%E13 = LHS%E13
      RES%E23 = LHS%E23

      ! Order 3
      RES%E123 = LHS%E123

   END FUNCTION MDNUM3_SUB_OR_SV

   FUNCTION MDNUM3_MUL_OO_SV(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(MDNUM3), INTENT(IN) :: LHS
      TYPE(MDNUM3), INTENT(IN) :: RHS(:)
      TYPE(MDNUM3) :: RES(SIZE(RHS,1)) 

      !  Multiplication like function 'LHS*RHS'
      ! Order 3
      RES%E123 = LHS%R*RHS%E123 + LHS%E123*RHS%R +  &
              LHS%E1*RHS%E23 + LHS%E23*RHS%E1 + LHS%E2*RHS%E13 +  &
              LHS%E13*RHS%E2 + LHS%E3*RHS%E12 + LHS%E12*RHS%E3
      ! Order 2
      RES%E12 = LHS%R*RHS%E12 + LHS%E12*RHS%R +  &
             LHS%E1*RHS%E2 + LHS%E2*RHS%E1
      RES%E13 = LHS%R*RHS%E13 + LHS%E13*RHS%R +  &
             LHS%E1*RHS%E3 + LHS%E3*RHS%E1
      RES%E23 = LHS%R*RHS%E23 + LHS%E23*RHS%R +  &
             LHS%E2*RHS%E3 + LHS%E3*RHS%E2
      ! Order 1
      RES%E1 = LHS%R*RHS%E1 + LHS%E1*RHS%R
      RES%E2 = LHS%R*RHS%E2 + LHS%E2*RHS%R
      RES%E3 = LHS%R*RHS%E3 + LHS%E3*RHS%R
      ! Order 0
      RES%R = LHS%R*RHS%R

   END FUNCTION MDNUM3_MUL_OO_SV

   FUNCTION MDNUM3_MUL_RO_SV(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS
      TYPE(MDNUM3), INTENT(IN) :: RHS(:)
      TYPE(MDNUM3) :: RES(SIZE(RHS,1)) 

      ! Multiplication like function 'LHS*RHS'
      !  Real
      RES%R = LHS*RHS%R

      ! Order 1
      RES%E1 = LHS*RHS%E1
      RES%E2 = LHS*RHS%E2
      RES%E3 = LHS*RHS%E3

      ! Order 2
      RES%E12 = LHS*RHS%E12
      RES%E13 = LHS*RHS%E13
      RES%E23 = LHS*RHS%E23

      ! Order 3
      RES%E123 = LHS*RHS%E123

   END FUNCTION MDNUM3_MUL_RO_SV

   FUNCTION MDNUM3_MUL_OR_SV(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(MDNUM3), INTENT(IN) :: LHS
      REAL(DP), INTENT(IN) :: RHS(:)
      TYPE(MDNUM3) :: RES(SIZE(RHS,1)) 

      ! Multiplication like function 'LHS*RHS'
      !  Real
      RES%R = LHS%R*RHS

      ! Order 1
      RES%E1 = LHS%E1*RHS
      RES%E2 = LHS%E2*RHS
      RES%E3 = LHS%E3*RHS

      ! Order 2
      RES%E12 = LHS%E12*RHS
      RES%E13 = LHS%E13*RHS
      RES%E23 = LHS%E23*RHS

      ! Order 3
      RES%E123 = LHS%E123*RHS

   END FUNCTION MDNUM3_MUL_OR_SV

   FUNCTION MDNUM3_ADD_OO_SM(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(MDNUM3), INTENT(IN) :: LHS
      TYPE(MDNUM3), INTENT(IN) :: RHS(:,:)
      TYPE(MDNUM3) :: RES(SIZE(RHS,1),SIZE(RHS,2)) 

      ! Addition like function 'LHS + RHS'
      !  Real
      RES%R = LHS%R + RHS%R

      ! Order 1
      RES%E1 = LHS%E1 + RHS%E1
      RES%E2 = LHS%E2 + RHS%E2
      RES%E3 = LHS%E3 + RHS%E3

      ! Order 2
      RES%E12 = LHS%E12 + RHS%E12
      RES%E13 = LHS%E13 + RHS%E13
      RES%E23 = LHS%E23 + RHS%E23

      ! Order 3
      RES%E123 = LHS%E123 + RHS%E123

   END FUNCTION MDNUM3_ADD_OO_SM

   FUNCTION MDNUM3_ADD_RO_SM(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS
      TYPE(MDNUM3), INTENT(IN) :: RHS(:,:)
      TYPE(MDNUM3) :: RES(SIZE(RHS,1),SIZE(RHS,2)) 

      ! Addition like function 'LHS + RHS'
      ! Real
      RES%R = LHS + RHS%R

      ! Order 1
      RES%E1 =  + RHS%E1
      RES%E2 =  + RHS%E2
      RES%E3 =  + RHS%E3

      ! Order 2
      RES%E12 =  + RHS%E12
      RES%E13 =  + RHS%E13
      RES%E23 =  + RHS%E23

      ! Order 3
      RES%E123 =  + RHS%E123

   END FUNCTION MDNUM3_ADD_RO_SM

   FUNCTION MDNUM3_ADD_OR_SM(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(MDNUM3), INTENT(IN) :: LHS
      REAL(DP), INTENT(IN) :: RHS(:,:)
      TYPE(MDNUM3) :: RES(SIZE(RHS,1),SIZE(RHS,2)) 

      ! Addition like function 'LHS + RHS'
      ! Real
      RES%R = LHS%R + RHS

      ! Order 1
      RES%E1 = LHS%E1
      RES%E2 = LHS%E2
      RES%E3 = LHS%E3

      ! Order 2
      RES%E12 = LHS%E12
      RES%E13 = LHS%E13
      RES%E23 = LHS%E23

      ! Order 3
      RES%E123 = LHS%E123

   END FUNCTION MDNUM3_ADD_OR_SM

   FUNCTION MDNUM3_SUB_OO_SM(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(MDNUM3), INTENT(IN) :: LHS
      TYPE(MDNUM3), INTENT(IN) :: RHS(:,:)
      TYPE(MDNUM3) :: RES(SIZE(RHS,1),SIZE(RHS,2)) 

      ! Addition like function 'LHS - RHS'
      !  Real
      RES%R = LHS%R - RHS%R

      ! Order 1
      RES%E1 = LHS%E1 - RHS%E1
      RES%E2 = LHS%E2 - RHS%E2
      RES%E3 = LHS%E3 - RHS%E3

      ! Order 2
      RES%E12 = LHS%E12 - RHS%E12
      RES%E13 = LHS%E13 - RHS%E13
      RES%E23 = LHS%E23 - RHS%E23

      ! Order 3
      RES%E123 = LHS%E123 - RHS%E123

   END FUNCTION MDNUM3_SUB_OO_SM

   FUNCTION MDNUM3_SUB_RO_SM(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS
      TYPE(MDNUM3), INTENT(IN) :: RHS(:,:)
      TYPE(MDNUM3) :: RES(SIZE(RHS,1),SIZE(RHS,2)) 

      ! Addition like function 'LHS - RHS'
      ! Real
      RES%R = LHS - RHS%R

      ! Order 1
      RES%E1 =  - RHS%E1
      RES%E2 =  - RHS%E2
      RES%E3 =  - RHS%E3

      ! Order 2
      RES%E12 =  - RHS%E12
      RES%E13 =  - RHS%E13
      RES%E23 =  - RHS%E23

      ! Order 3
      RES%E123 =  - RHS%E123

   END FUNCTION MDNUM3_SUB_RO_SM

   FUNCTION MDNUM3_SUB_OR_SM(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(MDNUM3), INTENT(IN) :: LHS
      REAL(DP), INTENT(IN) :: RHS(:,:)
      TYPE(MDNUM3) :: RES(SIZE(RHS,1),SIZE(RHS,2)) 

      ! Addition like function 'LHS - RHS'
      ! Real
      RES%R = LHS%R - RHS

      ! Order 1
      RES%E1 = LHS%E1
      RES%E2 = LHS%E2
      RES%E3 = LHS%E3

      ! Order 2
      RES%E12 = LHS%E12
      RES%E13 = LHS%E13
      RES%E23 = LHS%E23

      ! Order 3
      RES%E123 = LHS%E123

   END FUNCTION MDNUM3_SUB_OR_SM

   FUNCTION MDNUM3_MUL_OO_SM(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(MDNUM3), INTENT(IN) :: LHS
      TYPE(MDNUM3), INTENT(IN) :: RHS(:,:)
      TYPE(MDNUM3) :: RES(SIZE(RHS,1),SIZE(RHS,2)) 

      !  Multiplication like function 'LHS*RHS'
      ! Order 3
      RES%E123 = LHS%R*RHS%E123 + LHS%E123*RHS%R +  &
              LHS%E1*RHS%E23 + LHS%E23*RHS%E1 + LHS%E2*RHS%E13 +  &
              LHS%E13*RHS%E2 + LHS%E3*RHS%E12 + LHS%E12*RHS%E3
      ! Order 2
      RES%E12 = LHS%R*RHS%E12 + LHS%E12*RHS%R +  &
             LHS%E1*RHS%E2 + LHS%E2*RHS%E1
      RES%E13 = LHS%R*RHS%E13 + LHS%E13*RHS%R +  &
             LHS%E1*RHS%E3 + LHS%E3*RHS%E1
      RES%E23 = LHS%R*RHS%E23 + LHS%E23*RHS%R +  &
             LHS%E2*RHS%E3 + LHS%E3*RHS%E2
      ! Order 1
      RES%E1 = LHS%R*RHS%E1 + LHS%E1*RHS%R
      RES%E2 = LHS%R*RHS%E2 + LHS%E2*RHS%R
      RES%E3 = LHS%R*RHS%E3 + LHS%E3*RHS%R
      ! Order 0
      RES%R = LHS%R*RHS%R

   END FUNCTION MDNUM3_MUL_OO_SM

   FUNCTION MDNUM3_MUL_RO_SM(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS
      TYPE(MDNUM3), INTENT(IN) :: RHS(:,:)
      TYPE(MDNUM3) :: RES(SIZE(RHS,1),SIZE(RHS,2)) 

      ! Multiplication like function 'LHS*RHS'
      !  Real
      RES%R = LHS*RHS%R

      ! Order 1
      RES%E1 = LHS*RHS%E1
      RES%E2 = LHS*RHS%E2
      RES%E3 = LHS*RHS%E3

      ! Order 2
      RES%E12 = LHS*RHS%E12
      RES%E13 = LHS*RHS%E13
      RES%E23 = LHS*RHS%E23

      ! Order 3
      RES%E123 = LHS*RHS%E123

   END FUNCTION MDNUM3_MUL_RO_SM

   FUNCTION MDNUM3_MUL_OR_SM(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(MDNUM3), INTENT(IN) :: LHS
      REAL(DP), INTENT(IN) :: RHS(:,:)
      TYPE(MDNUM3) :: RES(SIZE(RHS,1),SIZE(RHS,2)) 

      ! Multiplication like function 'LHS*RHS'
      !  Real
      RES%R = LHS%R*RHS

      ! Order 1
      RES%E1 = LHS%E1*RHS
      RES%E2 = LHS%E2*RHS
      RES%E3 = LHS%E3*RHS

      ! Order 2
      RES%E12 = LHS%E12*RHS
      RES%E13 = LHS%E13*RHS
      RES%E23 = LHS%E23*RHS

      ! Order 3
      RES%E123 = LHS%E123*RHS

   END FUNCTION MDNUM3_MUL_OR_SM

ELEMENTAL    FUNCTION MDNUM3_GEM_OOO(A,B,C)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(MDNUM3), INTENT(IN) :: A 
      TYPE(MDNUM3), INTENT(IN) :: B 
      TYPE(MDNUM3), INTENT(IN) :: C 
      TYPE(MDNUM3) :: RES 

      !  General multiplication like function 'A*B + C'

      ! Order 0
      RES%R = C%R + A%R*B%R

      ! Order 1
      RES%E1 = C%E1 + A%R*B%E1 + A%E1*B%R
      RES%E2 = C%E2 + A%R*B%E2 + A%E2*B%R
      RES%E3 = C%E3 + A%R*B%E3 + A%E3*B%R

      ! Order 2
      RES%E12 = C%E12 + A%R*B%E12 + A%E12*B%R + A%E1*B%E2 &
              + A%E2*B%E1
      RES%E13 = C%E13 + A%R*B%E13 + A%E13*B%R + A%E1*B%E3 &
              + A%E3*B%E1
      RES%E23 = C%E23 + A%R*B%E23 + A%E23*B%R + A%E2*B%E3 &
              + A%E3*B%E2

      ! Order 3
      RES%E123 = C%E123 + A%R*B%E123 + A%E123*B%R + A%E1*B%E23 &
               + A%E23*B%E1 + A%E2*B%E13 + A%E13*B%E2 &
               + A%E3*B%E12 + A%E12*B%E3

   END FUNCTION MDNUM3_GEM_OOO

ELEMENTAL    FUNCTION MDNUM3_GEM_ROO(A,B,C)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: A 
      TYPE(MDNUM3), INTENT(IN) :: B 
      TYPE(MDNUM3), INTENT(IN) :: C 
      TYPE(MDNUM3) :: RES 

      !  General multiplication like function 'A*B + C'
      ! Order 3
      RES%E123 = C%E123 + A*B%E123
      ! Order 2
      RES%E12 = C%E12 + A*B%E12
      RES%E13 = C%E13 + A*B%E13
      RES%E23 = C%E23 + A*B%E23
      ! Order 1
      RES%E1 = C%E1 + A*B%E1
      RES%E2 = C%E2 + A*B%E2
      RES%E3 = C%E3 + A*B%E3
      ! Order 0
      RES%R = C%R + A*B%R

   END FUNCTION MDNUM3_GEM_ROO

ELEMENTAL    FUNCTION MDNUM3_GEM_ORO(A,B,C)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(MDNUM3), INTENT(IN) :: A 
      REAL(DP), INTENT(IN) :: B 
      TYPE(MDNUM3), INTENT(IN) :: C 
      TYPE(MDNUM3) :: RES 

      !  General multiplication like function 'A*B + C'

      ! Order 0
      RES%R = C%R + A%R*B

      ! Order 1
      RES%E1 = C%E1 + A%E1*B
      RES%E2 = C%E2 + A%E2*B
      RES%E3 = C%E3 + A%E3*B

      ! Order 2
      RES%E12 = C%E12 + A%E12*B
      RES%E13 = C%E13 + A%E13*B
      RES%E23 = C%E23 + A%E23*B

      ! Order 3
      RES%E123 = C%E123 + A%E123*B

   END FUNCTION MDNUM3_GEM_ORO

   FUNCTION MDNUM3_MATMUL_MDNUM3(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(MDNUM3), INTENT(IN) :: LHS(:,:)
      TYPE(MDNUM3), INTENT(IN) :: RHS(:,:)
      TYPE(MDNUM3) :: RES(SIZE(LHS,1),SIZE(RHS,2))

      !  Multiplication like function 'MATMUL(LHS,RHS)'
      ! Order 3
      RES%E123 = MATMUL(LHS%R,RHS%E123) + MATMUL(LHS%E123,RHS%R) +  &
              MATMUL(LHS%E1,RHS%E23) + MATMUL(LHS%E23,RHS%E1) + MATMUL(LHS%E2,RHS%E13) +  &
              MATMUL(LHS%E13,RHS%E2) + MATMUL(LHS%E3,RHS%E12) + MATMUL(LHS%E12,RHS%E3)
      ! Order 2
      RES%E12 = MATMUL(LHS%R,RHS%E12) + MATMUL(LHS%E12,RHS%R) +  &
             MATMUL(LHS%E1,RHS%E2) + MATMUL(LHS%E2,RHS%E1)
      RES%E13 = MATMUL(LHS%R,RHS%E13) + MATMUL(LHS%E13,RHS%R) +  &
             MATMUL(LHS%E1,RHS%E3) + MATMUL(LHS%E3,RHS%E1)
      RES%E23 = MATMUL(LHS%R,RHS%E23) + MATMUL(LHS%E23,RHS%R) +  &
             MATMUL(LHS%E2,RHS%E3) + MATMUL(LHS%E3,RHS%E2)
      ! Order 1
      RES%E1 = MATMUL(LHS%R,RHS%E1) + MATMUL(LHS%E1,RHS%R)
      RES%E2 = MATMUL(LHS%R,RHS%E2) + MATMUL(LHS%E2,RHS%R)
      RES%E3 = MATMUL(LHS%R,RHS%E3) + MATMUL(LHS%E3,RHS%R)
      ! Order 0
      RES%R = MATMUL(LHS%R,RHS%R)

   END FUNCTION MDNUM3_MATMUL_MDNUM3

   FUNCTION R_MATMUL_MDNUM3(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS(:,:)
      TYPE(MDNUM3), INTENT(IN) :: RHS(:,:)
      TYPE(MDNUM3) :: RES(SIZE(LHS,1),SIZE(RHS,2))

      ! Multiplication like function 'MATMUL(LHS,RHS)'
      !  Real
      RES%R = MATMUL(LHS,RHS%R)

      ! Order 1
      RES%E1 = MATMUL(LHS,RHS%E1)
      RES%E2 = MATMUL(LHS,RHS%E2)
      RES%E3 = MATMUL(LHS,RHS%E3)

      ! Order 2
      RES%E12 = MATMUL(LHS,RHS%E12)
      RES%E13 = MATMUL(LHS,RHS%E13)
      RES%E23 = MATMUL(LHS,RHS%E23)

      ! Order 3
      RES%E123 = MATMUL(LHS,RHS%E123)

   END FUNCTION R_MATMUL_MDNUM3

   FUNCTION MDNUM3_MATMUL_R(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(MDNUM3), INTENT(IN) :: LHS(:,:)
      REAL(DP), INTENT(IN) :: RHS(:,:)
      TYPE(MDNUM3) :: RES(SIZE(LHS,1),SIZE(RHS,2))

      ! Multiplication like function 'MATMUL(LHS,RHS)'
      !  Real
      RES%R = MATMUL(LHS%R,RHS)

      ! Order 1
      RES%E1 = MATMUL(LHS%E1,RHS)
      RES%E2 = MATMUL(LHS%E2,RHS)
      RES%E3 = MATMUL(LHS%E3,RHS)

      ! Order 2
      RES%E12 = MATMUL(LHS%E12,RHS)
      RES%E13 = MATMUL(LHS%E13,RHS)
      RES%E23 = MATMUL(LHS%E23,RHS)

      ! Order 3
      RES%E123 = MATMUL(LHS%E123,RHS)

   END FUNCTION MDNUM3_MATMUL_R

   FUNCTION MDNUM3_DOT_PRODUCT_MDNUM3(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(MDNUM3), INTENT(IN) :: LHS(:)
      TYPE(MDNUM3), INTENT(IN) :: RHS(SIZE(LHS))
      TYPE(MDNUM3) :: RES

      !  Multiplication like function 'DOT_PRODUCT(LHS,RHS)'
      ! Order 3
      RES%E123 = DOT_PRODUCT(LHS%R,RHS%E123) + DOT_PRODUCT(LHS%E123,RHS%R) +  &
              DOT_PRODUCT(LHS%E1,RHS%E23) + DOT_PRODUCT(LHS%E23,RHS%E1) + DOT_PRODUCT(LHS%E2,RHS%E13) +  &
              DOT_PRODUCT(LHS%E13,RHS%E2) + DOT_PRODUCT(LHS%E3,RHS%E12) + DOT_PRODUCT(LHS%E12,RHS%E3)
      ! Order 2
      RES%E12 = DOT_PRODUCT(LHS%R,RHS%E12) + DOT_PRODUCT(LHS%E12,RHS%R) +  &
             DOT_PRODUCT(LHS%E1,RHS%E2) + DOT_PRODUCT(LHS%E2,RHS%E1)
      RES%E13 = DOT_PRODUCT(LHS%R,RHS%E13) + DOT_PRODUCT(LHS%E13,RHS%R) +  &
             DOT_PRODUCT(LHS%E1,RHS%E3) + DOT_PRODUCT(LHS%E3,RHS%E1)
      RES%E23 = DOT_PRODUCT(LHS%R,RHS%E23) + DOT_PRODUCT(LHS%E23,RHS%R) +  &
             DOT_PRODUCT(LHS%E2,RHS%E3) + DOT_PRODUCT(LHS%E3,RHS%E2)
      ! Order 1
      RES%E1 = DOT_PRODUCT(LHS%R,RHS%E1) + DOT_PRODUCT(LHS%E1,RHS%R)
      RES%E2 = DOT_PRODUCT(LHS%R,RHS%E2) + DOT_PRODUCT(LHS%E2,RHS%R)
      RES%E3 = DOT_PRODUCT(LHS%R,RHS%E3) + DOT_PRODUCT(LHS%E3,RHS%R)
      ! Order 0
      RES%R = DOT_PRODUCT(LHS%R,RHS%R)

   END FUNCTION MDNUM3_DOT_PRODUCT_MDNUM3

   FUNCTION R_DOT_PRODUCT_MDNUM3(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS(:)
      TYPE(MDNUM3), INTENT(IN) :: RHS(SIZE(LHS))
      TYPE(MDNUM3) :: RES

      ! Multiplication like function 'DOT_PRODUCT(LHS,RHS)'
      !  Real
      RES%R = DOT_PRODUCT(LHS,RHS%R)

      ! Order 1
      RES%E1 = DOT_PRODUCT(LHS,RHS%E1)
      RES%E2 = DOT_PRODUCT(LHS,RHS%E2)
      RES%E3 = DOT_PRODUCT(LHS,RHS%E3)

      ! Order 2
      RES%E12 = DOT_PRODUCT(LHS,RHS%E12)
      RES%E13 = DOT_PRODUCT(LHS,RHS%E13)
      RES%E23 = DOT_PRODUCT(LHS,RHS%E23)

      ! Order 3
      RES%E123 = DOT_PRODUCT(LHS,RHS%E123)

   END FUNCTION R_DOT_PRODUCT_MDNUM3

   FUNCTION MDNUM3_DOT_PRODUCT_R(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(MDNUM3), INTENT(IN) :: LHS(:)
      REAL(DP), INTENT(IN) :: RHS(SIZE(LHS))
      TYPE(MDNUM3) :: RES

      ! Multiplication like function 'DOT_PRODUCT(LHS,RHS)'
      !  Real
      RES%R = DOT_PRODUCT(LHS%R,RHS)

      ! Order 1
      RES%E1 = DOT_PRODUCT(LHS%E1,RHS)
      RES%E2 = DOT_PRODUCT(LHS%E2,RHS)
      RES%E3 = DOT_PRODUCT(LHS%E3,RHS)

      ! Order 2
      RES%E12 = DOT_PRODUCT(LHS%E12,RHS)
      RES%E13 = DOT_PRODUCT(LHS%E13,RHS)
      RES%E23 = DOT_PRODUCT(LHS%E23,RHS)

      ! Order 3
      RES%E123 = DOT_PRODUCT(LHS%E123,RHS)

   END FUNCTION MDNUM3_DOT_PRODUCT_R

   FUNCTION MDNUM3_TRANSPOSE(LHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(MDNUM3), INTENT(IN) :: LHS(:,:)
      TYPE(MDNUM3) :: RES (SIZE(LHS,2),SIZE(LHS,1))

      ! Negation like function 'TRANSPOSE(LHS)'
      ! Real
      RES%R = TRANSPOSE(LHS%R)
      ! Order 1
      RES%E1 = TRANSPOSE(LHS%E1)
      RES%E2 = TRANSPOSE(LHS%E2)
      RES%E3 = TRANSPOSE(LHS%E3)
      ! Order 2
      RES%E12 = TRANSPOSE(LHS%E12)
      RES%E13 = TRANSPOSE(LHS%E13)
      RES%E23 = TRANSPOSE(LHS%E23)
      ! Order 3
      RES%E123 = TRANSPOSE(LHS%E123)

   END FUNCTION MDNUM3_TRANSPOSE

FUNCTION MDNUM3_TO_CR_MAT_S(VAL) RESULT(RES)
      IMPLICIT NONE
      TYPE(MDNUM3), INTENT(IN) :: VAL
      REAL(DP) :: RES(NUM_IM_DIR,NUM_IM_DIR) 
      INTEGER :: NCOLS=1, NROWS=1


      ! R x R -> R (1, 1)
      RES(1+NROWS*0:NROWS*1,1+NCOLS*0:NCOLS*1) = VAL%R
      ! R x E1 -> E1 (2, 2)
      RES(1+NROWS*1:NROWS*2,1+NCOLS*1:NCOLS*2) = VAL%R
      ! E1 x R -> E1 (2, 1)
      RES(1+NROWS*1:NROWS*2,1+NCOLS*0:NCOLS*1) = VAL%E1
      ! R x E2 -> E2 (3, 3)
      RES(1+NROWS*2:NROWS*3,1+NCOLS*2:NCOLS*3) = VAL%R
      ! E2 x R -> E2 (3, 1)
      RES(1+NROWS*2:NROWS*3,1+NCOLS*0:NCOLS*1) = VAL%E2
      ! R x E3 -> E3 (4, 4)
      RES(1+NROWS*3:NROWS*4,1+NCOLS*3:NCOLS*4) = VAL%R
      ! E3 x R -> E3 (4, 1)
      RES(1+NROWS*3:NROWS*4,1+NCOLS*0:NCOLS*1) = VAL%E3
      ! R x E12 -> E12 (5, 5)
      RES(1+NROWS*4:NROWS*5,1+NCOLS*4:NCOLS*5) = VAL%R
      ! E12 x R -> E12 (5, 1)
      RES(1+NROWS*4:NROWS*5,1+NCOLS*0:NCOLS*1) = VAL%E12
      ! E1 x E2 -> E12 (5, 3)
      RES(1+NROWS*4:NROWS*5,1+NCOLS*2:NCOLS*3) = VAL%E1
      ! E2 x E1 -> E12 (5, 2)
      RES(1+NROWS*4:NROWS*5,1+NCOLS*1:NCOLS*2) = VAL%E2
      ! R x E13 -> E13 (6, 6)
      RES(1+NROWS*5:NROWS*6,1+NCOLS*5:NCOLS*6) = VAL%R
      ! E13 x R -> E13 (6, 1)
      RES(1+NROWS*5:NROWS*6,1+NCOLS*0:NCOLS*1) = VAL%E13
      ! E1 x E3 -> E13 (6, 4)
      RES(1+NROWS*5:NROWS*6,1+NCOLS*3:NCOLS*4) = VAL%E1
      ! E3 x E1 -> E13 (6, 2)
      RES(1+NROWS*5:NROWS*6,1+NCOLS*1:NCOLS*2) = VAL%E3
      ! R x E23 -> E23 (7, 7)
      RES(1+NROWS*6:NROWS*7,1+NCOLS*6:NCOLS*7) = VAL%R
      ! E23 x R -> E23 (7, 1)
      RES(1+NROWS*6:NROWS*7,1+NCOLS*0:NCOLS*1) = VAL%E23
      ! E2 x E3 -> E23 (7, 4)
      RES(1+NROWS*6:NROWS*7,1+NCOLS*3:NCOLS*4) = VAL%E2
      ! E3 x E2 -> E23 (7, 3)
      RES(1+NROWS*6:NROWS*7,1+NCOLS*2:NCOLS*3) = VAL%E3
      ! R x E123 -> E123 (8, 8)
      RES(1+NROWS*7:NROWS*8,1+NCOLS*7:NCOLS*8) = VAL%R
      ! E123 x R -> E123 (8, 1)
      RES(1+NROWS*7:NROWS*8,1+NCOLS*0:NCOLS*1) = VAL%E123
      ! E1 x E23 -> E123 (8, 7)
      RES(1+NROWS*7:NROWS*8,1+NCOLS*6:NCOLS*7) = VAL%E1
      ! E23 x E1 -> E123 (8, 2)
      RES(1+NROWS*7:NROWS*8,1+NCOLS*1:NCOLS*2) = VAL%E23
      ! E2 x E13 -> E123 (8, 6)
      RES(1+NROWS*7:NROWS*8,1+NCOLS*5:NCOLS*6) = VAL%E2
      ! E13 x E2 -> E123 (8, 3)
      RES(1+NROWS*7:NROWS*8,1+NCOLS*2:NCOLS*3) = VAL%E13
      ! E3 x E12 -> E123 (8, 5)
      RES(1+NROWS*7:NROWS*8,1+NCOLS*4:NCOLS*5) = VAL%E3
      ! E12 x E3 -> E123 (8, 4)
      RES(1+NROWS*7:NROWS*8,1+NCOLS*3:NCOLS*4) = VAL%E12
   END FUNCTION MDNUM3_TO_CR_MAT_S

FUNCTION MDNUM3_TO_CR_MAT_V(VAL) RESULT(RES)
      IMPLICIT NONE
      TYPE(MDNUM3), INTENT(IN) :: VAL(:)
      REAL(DP) :: RES(NUM_IM_DIR*SIZE(VAL,1),NUM_IM_DIR) 
      INTEGER :: NCOLS=1, NROWS=1

      NROWS = SIZE(VAL,1)

      ! R x R -> R (1, 1)
      RES(1+NROWS*0:NROWS*1,1) = VAL%R
      ! R x E1 -> E1 (2, 2)
      RES(1+NROWS*1:NROWS*2,2) = VAL%R
      ! E1 x R -> E1 (2, 1)
      RES(1+NROWS*1:NROWS*2,1) = VAL%E1
      ! R x E2 -> E2 (3, 3)
      RES(1+NROWS*2:NROWS*3,3) = VAL%R
      ! E2 x R -> E2 (3, 1)
      RES(1+NROWS*2:NROWS*3,1) = VAL%E2
      ! R x E3 -> E3 (4, 4)
      RES(1+NROWS*3:NROWS*4,4) = VAL%R
      ! E3 x R -> E3 (4, 1)
      RES(1+NROWS*3:NROWS*4,1) = VAL%E3
      ! R x E12 -> E12 (5, 5)
      RES(1+NROWS*4:NROWS*5,5) = VAL%R
      ! E12 x R -> E12 (5, 1)
      RES(1+NROWS*4:NROWS*5,1) = VAL%E12
      ! E1 x E2 -> E12 (5, 3)
      RES(1+NROWS*4:NROWS*5,3) = VAL%E1
      ! E2 x E1 -> E12 (5, 2)
      RES(1+NROWS*4:NROWS*5,2) = VAL%E2
      ! R x E13 -> E13 (6, 6)
      RES(1+NROWS*5:NROWS*6,6) = VAL%R
      ! E13 x R -> E13 (6, 1)
      RES(1+NROWS*5:NROWS*6,1) = VAL%E13
      ! E1 x E3 -> E13 (6, 4)
      RES(1+NROWS*5:NROWS*6,4) = VAL%E1
      ! E3 x E1 -> E13 (6, 2)
      RES(1+NROWS*5:NROWS*6,2) = VAL%E3
      ! R x E23 -> E23 (7, 7)
      RES(1+NROWS*6:NROWS*7,7) = VAL%R
      ! E23 x R -> E23 (7, 1)
      RES(1+NROWS*6:NROWS*7,1) = VAL%E23
      ! E2 x E3 -> E23 (7, 4)
      RES(1+NROWS*6:NROWS*7,4) = VAL%E2
      ! E3 x E2 -> E23 (7, 3)
      RES(1+NROWS*6:NROWS*7,3) = VAL%E3
      ! R x E123 -> E123 (8, 8)
      RES(1+NROWS*7:NROWS*8,8) = VAL%R
      ! E123 x R -> E123 (8, 1)
      RES(1+NROWS*7:NROWS*8,1) = VAL%E123
      ! E1 x E23 -> E123 (8, 7)
      RES(1+NROWS*7:NROWS*8,7) = VAL%E1
      ! E23 x E1 -> E123 (8, 2)
      RES(1+NROWS*7:NROWS*8,2) = VAL%E23
      ! E2 x E13 -> E123 (8, 6)
      RES(1+NROWS*7:NROWS*8,6) = VAL%E2
      ! E13 x E2 -> E123 (8, 3)
      RES(1+NROWS*7:NROWS*8,3) = VAL%E13
      ! E3 x E12 -> E123 (8, 5)
      RES(1+NROWS*7:NROWS*8,5) = VAL%E3
      ! E12 x E3 -> E123 (8, 4)
      RES(1+NROWS*7:NROWS*8,4) = VAL%E12
   END FUNCTION MDNUM3_TO_CR_MAT_V

FUNCTION MDNUM3_TO_CR_MAT_M(VAL) RESULT(RES)
      IMPLICIT NONE
      TYPE(MDNUM3), INTENT(IN) :: VAL(:,:)
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
      ! R x E2 -> E2 (3, 3)
      RES(1+NROWS*2:NROWS*3,1+NCOLS*2:NCOLS*3) = VAL%R
      ! E2 x R -> E2 (3, 1)
      RES(1+NROWS*2:NROWS*3,1+NCOLS*0:NCOLS*1) = VAL%E2
      ! R x E3 -> E3 (4, 4)
      RES(1+NROWS*3:NROWS*4,1+NCOLS*3:NCOLS*4) = VAL%R
      ! E3 x R -> E3 (4, 1)
      RES(1+NROWS*3:NROWS*4,1+NCOLS*0:NCOLS*1) = VAL%E3
      ! R x E12 -> E12 (5, 5)
      RES(1+NROWS*4:NROWS*5,1+NCOLS*4:NCOLS*5) = VAL%R
      ! E12 x R -> E12 (5, 1)
      RES(1+NROWS*4:NROWS*5,1+NCOLS*0:NCOLS*1) = VAL%E12
      ! E1 x E2 -> E12 (5, 3)
      RES(1+NROWS*4:NROWS*5,1+NCOLS*2:NCOLS*3) = VAL%E1
      ! E2 x E1 -> E12 (5, 2)
      RES(1+NROWS*4:NROWS*5,1+NCOLS*1:NCOLS*2) = VAL%E2
      ! R x E13 -> E13 (6, 6)
      RES(1+NROWS*5:NROWS*6,1+NCOLS*5:NCOLS*6) = VAL%R
      ! E13 x R -> E13 (6, 1)
      RES(1+NROWS*5:NROWS*6,1+NCOLS*0:NCOLS*1) = VAL%E13
      ! E1 x E3 -> E13 (6, 4)
      RES(1+NROWS*5:NROWS*6,1+NCOLS*3:NCOLS*4) = VAL%E1
      ! E3 x E1 -> E13 (6, 2)
      RES(1+NROWS*5:NROWS*6,1+NCOLS*1:NCOLS*2) = VAL%E3
      ! R x E23 -> E23 (7, 7)
      RES(1+NROWS*6:NROWS*7,1+NCOLS*6:NCOLS*7) = VAL%R
      ! E23 x R -> E23 (7, 1)
      RES(1+NROWS*6:NROWS*7,1+NCOLS*0:NCOLS*1) = VAL%E23
      ! E2 x E3 -> E23 (7, 4)
      RES(1+NROWS*6:NROWS*7,1+NCOLS*3:NCOLS*4) = VAL%E2
      ! E3 x E2 -> E23 (7, 3)
      RES(1+NROWS*6:NROWS*7,1+NCOLS*2:NCOLS*3) = VAL%E3
      ! R x E123 -> E123 (8, 8)
      RES(1+NROWS*7:NROWS*8,1+NCOLS*7:NCOLS*8) = VAL%R
      ! E123 x R -> E123 (8, 1)
      RES(1+NROWS*7:NROWS*8,1+NCOLS*0:NCOLS*1) = VAL%E123
      ! E1 x E23 -> E123 (8, 7)
      RES(1+NROWS*7:NROWS*8,1+NCOLS*6:NCOLS*7) = VAL%E1
      ! E23 x E1 -> E123 (8, 2)
      RES(1+NROWS*7:NROWS*8,1+NCOLS*1:NCOLS*2) = VAL%E23
      ! E2 x E13 -> E123 (8, 6)
      RES(1+NROWS*7:NROWS*8,1+NCOLS*5:NCOLS*6) = VAL%E2
      ! E13 x E2 -> E123 (8, 3)
      RES(1+NROWS*7:NROWS*8,1+NCOLS*2:NCOLS*3) = VAL%E13
      ! E3 x E12 -> E123 (8, 5)
      RES(1+NROWS*7:NROWS*8,1+NCOLS*4:NCOLS*5) = VAL%E3
      ! E12 x E3 -> E123 (8, 4)
      RES(1+NROWS*7:NROWS*8,1+NCOLS*3:NCOLS*4) = VAL%E12
   END FUNCTION MDNUM3_TO_CR_MAT_M

      SUBROUTINE MDNUM3_SETIM_S(VAL,IDX,RES)
      IMPLICIT NONE
      TYPE(MDNUM3), INTENT(INOUT) :: VAL
      REAL(DP),INTENT(IN) :: RES 
      INTEGER, INTENT(IN) :: IDX

      SELECT CASE(IDX)
      ! Order 0
      CASE(0)
         VAL%R=RES

      ! Order 1
      CASE(1)
         VAL%E1=RES
      CASE(2)
         VAL%E2=RES
      CASE(3)
         VAL%E3=RES

      ! Order 2
      CASE(4)
         VAL%E12=RES
      CASE(5)
         VAL%E13=RES
      CASE(6)
         VAL%E23=RES

      ! Order 3
      CASE(7)
         VAL%E123=RES

      END SELECT
   END SUBROUTINE MDNUM3_SETIM_S

      SUBROUTINE MDNUM3_SETIM_V(VAL,IDX,RES)
      IMPLICIT NONE
      TYPE(MDNUM3), INTENT(INOUT) :: VAL(:)
      REAL(DP),INTENT(IN) :: RES(SIZE(VAL)) 
      INTEGER, INTENT(IN) :: IDX

      SELECT CASE(IDX)
      ! Order 0
      CASE(0)
         VAL%R=RES

      ! Order 1
      CASE(1)
         VAL%E1=RES
      CASE(2)
         VAL%E2=RES
      CASE(3)
         VAL%E3=RES

      ! Order 2
      CASE(4)
         VAL%E12=RES
      CASE(5)
         VAL%E13=RES
      CASE(6)
         VAL%E23=RES

      ! Order 3
      CASE(7)
         VAL%E123=RES

      END SELECT
   END SUBROUTINE MDNUM3_SETIM_V

      SUBROUTINE MDNUM3_SETIM_M(VAL,IDX,RES)
      IMPLICIT NONE
      TYPE(MDNUM3), INTENT(INOUT) :: VAL(:,:)
      REAL(DP),INTENT(IN) :: RES(SIZE(VAL,1),SIZE(VAL,2)) 
      INTEGER, INTENT(IN) :: IDX

      SELECT CASE(IDX)
      ! Order 0
      CASE(0)
         VAL%R=RES

      ! Order 1
      CASE(1)
         VAL%E1=RES
      CASE(2)
         VAL%E2=RES
      CASE(3)
         VAL%E3=RES

      ! Order 2
      CASE(4)
         VAL%E12=RES
      CASE(5)
         VAL%E13=RES
      CASE(6)
         VAL%E23=RES

      ! Order 3
      CASE(7)
         VAL%E123=RES

      END SELECT
   END SUBROUTINE MDNUM3_SETIM_M

FUNCTION MDNUM3_GETIM_S(VAL,IDX) RESULT(RES)
      IMPLICIT NONE
      TYPE(MDNUM3), INTENT(IN) :: VAL
      REAL(DP) :: RES 
      INTEGER, INTENT(IN) :: IDX

      SELECT CASE(IDX)
      ! Order 0
      CASE(0)
         RES=VAL%R

      ! Order 1
      CASE(1)
         RES=VAL%E1
      CASE(2)
         RES=VAL%E2
      CASE(3)
         RES=VAL%E3

      ! Order 2
      CASE(4)
         RES=VAL%E12
      CASE(5)
         RES=VAL%E13
      CASE(6)
         RES=VAL%E23

      ! Order 3
      CASE(7)
         RES=VAL%E123

      END SELECT
   END FUNCTION MDNUM3_GETIM_S

FUNCTION MDNUM3_GETIM_V(VAL,IDX) RESULT(RES)
      IMPLICIT NONE
      TYPE(MDNUM3), INTENT(IN) :: VAL(:)
      REAL(DP) :: RES(SIZE(VAL)) 
      INTEGER, INTENT(IN) :: IDX

      SELECT CASE(IDX)
      ! Order 0
      CASE(0)
         RES=VAL%R

      ! Order 1
      CASE(1)
         RES=VAL%E1
      CASE(2)
         RES=VAL%E2
      CASE(3)
         RES=VAL%E3

      ! Order 2
      CASE(4)
         RES=VAL%E12
      CASE(5)
         RES=VAL%E13
      CASE(6)
         RES=VAL%E23

      ! Order 3
      CASE(7)
         RES=VAL%E123

      END SELECT
   END FUNCTION MDNUM3_GETIM_V

FUNCTION MDNUM3_GETIM_M(VAL,IDX) RESULT(RES)
      IMPLICIT NONE
      TYPE(MDNUM3), INTENT(IN) :: VAL(:,:)
      REAL(DP) :: RES(SIZE(VAL,1),SIZE(VAL,2)) 
      INTEGER, INTENT(IN) :: IDX

      SELECT CASE(IDX)
      ! Order 0
      CASE(0)
         RES=VAL%R

      ! Order 1
      CASE(1)
         RES=VAL%E1
      CASE(2)
         RES=VAL%E2
      CASE(3)
         RES=VAL%E3

      ! Order 2
      CASE(4)
         RES=VAL%E12
      CASE(5)
         RES=VAL%E13
      CASE(6)
         RES=VAL%E23

      ! Order 3
      CASE(7)
         RES=VAL%E123

      END SELECT
   END FUNCTION MDNUM3_GETIM_M

   SUBROUTINE MDNUM3_PPRINT_S(VAR,FMT,UNIT)
      IMPLICIT NONE
      TYPE(MDNUM3), INTENT(IN) :: VAR
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
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'E2 * '
      CALL PPRINT(VAR%E2,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'E3 * '
      CALL PPRINT(VAR%E3,unit=unt,fmt=output_format)

      !  Order 2
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'E12 * '
      CALL PPRINT(VAR%E12,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'E13 * '
      CALL PPRINT(VAR%E13,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'E23 * '
      CALL PPRINT(VAR%E23,unit=unt,fmt=output_format)

      !  Order 3
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'E123 * '
      CALL PPRINT(VAR%E123,unit=unt,fmt=output_format)


   END SUBROUTINE MDNUM3_PPRINT_S

   SUBROUTINE MDNUM3_PPRINT_V(VAR,FMT,UNIT)
      IMPLICIT NONE
      TYPE(MDNUM3), INTENT(IN) :: VAR(:)
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
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E2 * '
      CALL PPRINT(VAR%E2,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E3 * '
      CALL PPRINT(VAR%E3,unit=unt,fmt=output_format)

      !  Order 2
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E12 * '
      CALL PPRINT(VAR%E12,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E13 * '
      CALL PPRINT(VAR%E13,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E23 * '
      CALL PPRINT(VAR%E23,unit=unt,fmt=output_format)

      !  Order 3
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E123 * '
      CALL PPRINT(VAR%E123,unit=unt,fmt=output_format)


   END SUBROUTINE MDNUM3_PPRINT_V

   SUBROUTINE MDNUM3_PPRINT_M(VAR,FMT,UNIT)
      IMPLICIT NONE
      TYPE(MDNUM3), INTENT(IN) :: VAR(:,:)
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
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E2 * '
      CALL PPRINT(VAR%E2,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E3 * '
      CALL PPRINT(VAR%E3,unit=unt,fmt=output_format)

      !  Order 2
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E12 * '
      CALL PPRINT(VAR%E12,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E13 * '
      CALL PPRINT(VAR%E13,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E23 * '
      CALL PPRINT(VAR%E23,unit=unt,fmt=output_format)

      !  Order 3
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E123 * '
      CALL PPRINT(VAR%E123,unit=unt,fmt=output_format)


   END SUBROUTINE MDNUM3_PPRINT_M

   ELEMENTAL FUNCTION MDNUM3_FEVAL(X,DER0,DER1,DER2,DER3)&
      RESULT(RES)
      IMPLICIT NONE
      !  Definitions
      REAL(DP) :: FACTOR, COEF
      TYPE(MDNUM3), INTENT(IN)  :: X
      REAL(DP), INTENT(IN)  :: DER0,DER1,DER2,DER3
      TYPE(MDNUM3) :: RES
      TYPE(MDNUM3) :: DX, DX_P

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
      ! Order 3
      RES%E123 = RES%E123+COEF*DX_P%E123
      ! Order 2
      RES%E12 = RES%E12+COEF*DX_P%E12
      RES%E13 = RES%E13+COEF*DX_P%E13
      RES%E23 = RES%E23+COEF*DX_P%E23
      ! Order 1
      RES%E1 = RES%E1+COEF*DX_P%E1
      RES%E2 = RES%E2+COEF*DX_P%E2
      RES%E3 = RES%E3+COEF*DX_P%E3
      ! DX_P = DX_P * DX
      ! Order 3
      DX_P%E123 = DX_P%E1*DX%E23+DX_P%E23*DX%E1+ &
               DX_P%E2*DX%E13+DX_P%E13*DX%E2+DX_P%E3*DX%E12+ &
               DX_P%E12*DX%E3
      ! Order 2
      DX_P%E12 = DX_P%E1*DX%E2+DX_P%E2*DX%E1
      DX_P%E13 = DX_P%E1*DX%E3+DX_P%E3*DX%E1
      DX_P%E23 = DX_P%E2*DX%E3+DX_P%E3*DX%E2
      
      ! Sets order 2
      FACTOR = FACTOR * 2
      COEF = DER2 / FACTOR
      ! RES = RES COEF * DX_P
      ! Order 3
      RES%E123 = RES%E123+COEF*DX_P%E123
      ! Order 2
      RES%E12 = RES%E12+COEF*DX_P%E12
      RES%E13 = RES%E13+COEF*DX_P%E13
      RES%E23 = RES%E23+COEF*DX_P%E23
      ! DX_P = DX_P * DX
      ! Order 3
      DX_P%E123 = DX_P%E23*DX%E1+DX_P%E13*DX%E2+ &
               DX_P%E12*DX%E3
      
      ! Sets order 3
      FACTOR = FACTOR * 3
      COEF = DER3 / FACTOR
      ! RES = RES COEF * DX_P
      ! Order 3
      RES%E123 = RES%E123+COEF*DX_P%E123
      
   END FUNCTION MDNUM3_FEVAL


  ! SUBROUTINE MDNUM3_PPRINT_M_R(X, FMT)
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

  ! END SUBROUTINE MDNUM3_PPRINT_M_R

  ! SUBROUTINE MDNUM3_PPRINT_V_R(X, FMT)
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

  ! END SUBROUTINE MDNUM3_PPRINT_V_R

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
  PURE FUNCTION MDNUM3_det2x2(A) RESULT(det)

    IMPLICIT NONE

    TYPE(MDNUM3), INTENT(IN) :: A(2,2)   !! Matrix
    TYPE(MDNUM3)             :: det

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
  PURE FUNCTION MDNUM3_det3x3(A) RESULT(det)
      
    IMPLICIT NONE

    TYPE(MDNUM3), INTENT(IN) :: A(3,3)   !! Matrix
    TYPE(MDNUM3)             :: det

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
  PURE FUNCTION MDNUM3_det4x4(A) RESULT(det)
      
    IMPLICIT NONE

    TYPE(MDNUM3), INTENT(IN) :: A(4,4)   !! Matrix
    TYPE(MDNUM3)             :: det

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
  PURE FUNCTION MDNUM3_cross3(a,b) RESULT(v)
      
    IMPLICIT NONE 

    TYPE(MDNUM3), DIMENSION (3),INTENT(IN) :: a,b
    TYPE(MDNUM3), DIMENSION (3) :: v
    
    v(1) = a(2) * b(3) - a(3) * b(2)
    v(2) = a(3) * b(1) - a(1) * b(3)
    v(3) = a(1) * b(2) - a(2) * b(1)

  END FUNCTION MDNUM3_cross3
  !===================================================================================================! 

  !***************************************************************************************************! 
  !> @brief Norm of a 3 element vector. # There is an intrinsic function named norm2.
  !!
  !! @param[in] a: Vector of 3 reals (rank 1).
  !! @param[in] b: Vector of 3 reals (rank 1).
  !!
  !***************************************************************************************************!
  FUNCTION MDNUM3_norm2_3(v) RESULT(n)
     
    IMPLICIT NONE 

    TYPE(MDNUM3), INTENT(IN) :: v(3)
    TYPE(MDNUM3) :: n
     
    n = SQRT( v(1)*v(1) + v(2)*v(2) + v(3)*v(3) )

  END FUNCTION MDNUM3_norm2_3
  !===================================================================================================! 

  FUNCTION MDNUM3_DIVISION_OO(X,Y) RESULT(RES)
      IMPLICIT NONE
      REAL(DP) :: DERIVS(TORDER + 1) 
      TYPE(MDNUM3), INTENT(IN) :: X
      TYPE(MDNUM3), INTENT(IN) :: Y
      TYPE(MDNUM3) :: RES

      RES = X*(Y**(-1.d0))

  END FUNCTION MDNUM3_DIVISION_OO

  FUNCTION MDNUM3_DIVISION_OR(X,Y) RESULT(RES)
      IMPLICIT NONE
      REAL(DP) :: DERIVS(TORDER + 1) 
      TYPE(MDNUM3), INTENT(IN) :: X
      REAL(DP), INTENT(IN) :: Y
      TYPE(MDNUM3) :: RES

      RES = X*(Y**(-1.d0))

  END FUNCTION MDNUM3_DIVISION_OR

  FUNCTION MDNUM3_DIVISION_RO(X,Y) RESULT(RES)
      IMPLICIT NONE
      REAL(DP) :: DERIVS(TORDER + 1) 
      REAL(DP), INTENT(IN) :: X
      TYPE(MDNUM3), INTENT(IN) :: Y
      TYPE(MDNUM3) :: RES

      RES = X*(Y**(-1.d0))

  END FUNCTION MDNUM3_DIVISION_RO

  ELEMENTAL FUNCTION MDNUM3_REAL(X) RESULT(RES)
      IMPLICIT NONE
      TYPE(MDNUM3), INTENT(IN) :: X
      REAL(DP) :: RES

      RES = X%R

  END FUNCTION MDNUM3_REAL

  FUNCTION MDNUM3_SQRT(X) RESULT(RES)
      IMPLICIT NONE
      TYPE(MDNUM3), INTENT(IN) :: X
      TYPE(MDNUM3) :: RES

      RES = X**0.5_DP

  END FUNCTION MDNUM3_SQRT

   ELEMENTAL FUNCTION MDNUM3_TAN(X) RESULT(RES)

      TYPE(MDNUM3), INTENT(IN) :: X
      REAL(DP) :: DER0,DER1,DER2,DER3
      TYPE(MDNUM3) :: RES
      
      DER0 = TAN(X%R)
      DER1 = TAN(X%R)**2 + 1
      DER2 = 2*(TAN(X%R)**2 + 1)*TAN(X%R)
      DER3 = 2*(TAN(X%R)**2 + 1)*(3*TAN(X%R)**2 + 1)

      RES = FEVAL(X,DER0,DER1,DER2,DER3)

   END FUNCTION MDNUM3_TAN

   ELEMENTAL FUNCTION MDNUM3_COS(X) RESULT(RES)

      TYPE(MDNUM3), INTENT(IN) :: X
      REAL(DP) :: DER0,DER1,DER2,DER3
      TYPE(MDNUM3) :: RES
      
      DER0 = COS(X%R)
      DER1 = -SIN(X%R)
      DER2 = -COS(X%R)
      DER3 = SIN(X%R)

      RES = FEVAL(X,DER0,DER1,DER2,DER3)

   END FUNCTION MDNUM3_COS

   ELEMENTAL FUNCTION MDNUM3_SIN(X) RESULT(RES)

      TYPE(MDNUM3), INTENT(IN) :: X
      REAL(DP) :: DER0,DER1,DER2,DER3
      TYPE(MDNUM3) :: RES
      
      DER0 = SIN(X%R)
      DER1 = COS(X%R)
      DER2 = -SIN(X%R)
      DER3 = -COS(X%R)

      RES = FEVAL(X,DER0,DER1,DER2,DER3)

   END FUNCTION MDNUM3_SIN

   ELEMENTAL FUNCTION MDNUM3_ATAN(X) RESULT(RES)

      TYPE(MDNUM3), INTENT(IN) :: X
      REAL(DP) :: DER0,DER1,DER2,DER3
      TYPE(MDNUM3) :: RES
      
      DER0 = ATAN(X%R)
      DER1 = 1D0/(X%R**2 + 1)
      DER2 = -2*X%R/(X%R**2 + 1)**2
      DER3 = 2*(4*X%R**2/(X%R**2 + 1) - 1)/(X%R**2 + 1)**2

      RES = FEVAL(X,DER0,DER1,DER2,DER3)

   END FUNCTION MDNUM3_ATAN

   ELEMENTAL FUNCTION MDNUM3_ACOS(X) RESULT(RES)

      TYPE(MDNUM3), INTENT(IN) :: X
      REAL(DP) :: DER0,DER1,DER2,DER3
      TYPE(MDNUM3) :: RES
      
      DER0 = ACOS(X%R)
      DER1 = -1/SQRT(1 - X%R**2)
      DER2 = -X%R/(1 - X%R**2)**(3.0D0/2.0D0)
      DER3 = -(3*X%R**2/(1 - X%R**2) + 1)/(1 - X%R**2)**(3.0D0/2.0D0)

      RES = FEVAL(X,DER0,DER1,DER2,DER3)

   END FUNCTION MDNUM3_ACOS

   ELEMENTAL FUNCTION MDNUM3_ASIN(X) RESULT(RES)

      TYPE(MDNUM3), INTENT(IN) :: X
      REAL(DP) :: DER0,DER1,DER2,DER3
      TYPE(MDNUM3) :: RES
      
      DER0 = ASIN(X%R)
      DER1 = 1/SQRT(1 - X%R**2)
      DER2 = X%R/(1 - X%R**2)**(3.0D0/2.0D0)
      DER3 = (3*X%R**2/(1 - X%R**2) + 1)/(1 - X%R**2)**(3.0D0/2.0D0)

      RES = FEVAL(X,DER0,DER1,DER2,DER3)

   END FUNCTION MDNUM3_ASIN

   ELEMENTAL FUNCTION MDNUM3_TANH(X) RESULT(RES)

      TYPE(MDNUM3), INTENT(IN) :: X
      REAL(DP) :: DER0,DER1,DER2,DER3
      TYPE(MDNUM3) :: RES
      
      DER0 = TANH(X%R)
      DER1 = 1 - TANH(X%R)**2
      DER2 = 2*(TANH(X%R)**2 - 1)*TANH(X%R)
      DER3 = -2*(TANH(X%R)**2 - 1)*(3*TANH(X%R)**2 - 1)

      RES = FEVAL(X,DER0,DER1,DER2,DER3)

   END FUNCTION MDNUM3_TANH

   ELEMENTAL FUNCTION MDNUM3_COSH(X) RESULT(RES)

      TYPE(MDNUM3), INTENT(IN) :: X
      REAL(DP) :: DER0,DER1,DER2,DER3
      TYPE(MDNUM3) :: RES
      
      DER0 = COSH(X%R)
      DER1 = SINH(X%R)
      DER2 = COSH(X%R)
      DER3 = SINH(X%R)

      RES = FEVAL(X,DER0,DER1,DER2,DER3)

   END FUNCTION MDNUM3_COSH

   ELEMENTAL FUNCTION MDNUM3_SINH(X) RESULT(RES)

      TYPE(MDNUM3), INTENT(IN) :: X
      REAL(DP) :: DER0,DER1,DER2,DER3
      TYPE(MDNUM3) :: RES
      
      DER0 = SINH(X%R)
      DER1 = COSH(X%R)
      DER2 = SINH(X%R)
      DER3 = COSH(X%R)

      RES = FEVAL(X,DER0,DER1,DER2,DER3)

   END FUNCTION MDNUM3_SINH

   ELEMENTAL FUNCTION MDNUM3_EXP(X) RESULT(RES)

      TYPE(MDNUM3), INTENT(IN) :: X
      REAL(DP) :: DER0,DER1,DER2,DER3
      TYPE(MDNUM3) :: RES
      
      DER0 = EXP(X%R)
      DER1 = EXP(X%R)
      DER2 = EXP(X%R)
      DER3 = EXP(X%R)

      RES = FEVAL(X,DER0,DER1,DER2,DER3)

   END FUNCTION MDNUM3_EXP

   ELEMENTAL FUNCTION MDNUM3_LOG(X) RESULT(RES)

      TYPE(MDNUM3), INTENT(IN) :: X
      REAL(DP) :: DER0,DER1,DER2,DER3
      TYPE(MDNUM3) :: RES
      
      DER0 = LOG(X%R)
      DER1 = 1D0/X%R
      DER2 = -1/X%R**2
      DER3 = 2/X%R**3

      RES = FEVAL(X,DER0,DER1,DER2,DER3)

   END FUNCTION MDNUM3_LOG

   ELEMENTAL FUNCTION MDNUM3_POW_OR(X,E) RESULT(RES)

      TYPE(MDNUM3), INTENT(IN) :: X
      REAL(DP), INTENT(IN) :: E
      REAL(DP) :: DER0,DER1,DER2,DER3
      TYPE(MDNUM3) :: RES
      
      DER0=0.0d0
      DER1=0.0d0
      DER2=0.0d0
      DER3=0.0d0
      
      DER0 = X%R**E
      IF ((E-0)/=0.0d0) THEN
         DER1 = E*X%R**(E - 1)
         IF ((E-1)/=0.0d0) THEN
            DER2 = E*X%R**(E - 2)*(E - 1)
            IF ((E-2)/=0.0d0) THEN
               DER3 = E*X%R**(E - 3)*(E**2 - 3*E + 2)
            END IF
         END IF
      END IF

      RES = FEVAL(X,DER0,DER1,DER2,DER3)

   END FUNCTION MDNUM3_POW_OR

   ELEMENTAL FUNCTION MDNUM3_POW_RO(E,X) RESULT(RES)

      TYPE(MDNUM3), INTENT(IN) :: X
      REAL(DP), INTENT(IN) :: E
      REAL(DP) :: DER0,DER1,DER2,DER3
      TYPE(MDNUM3) :: RES
      
      
      DER0 = E**X%R
      DER1 = E**X%R*LOG(E)
      DER2 = E**X%R*LOG(E)**2
      DER3 = E**X%R*LOG(E)**3

      RES = FEVAL(X,DER0,DER1,DER2,DER3)

   END FUNCTION MDNUM3_POW_RO

   ELEMENTAL FUNCTION MDNUM3_F2EVAL(X,Y,DER0_0,DER1_0,DER1_1, &
                                DER2_0,DER2_1,DER2_2,DER3_0, &
                                DER3_1,DER3_2,DER3_3)&
      RESULT(RES)
      IMPLICIT NONE
      !  Definitions
      REAL(DP) :: COEF, DELTA
      TYPE(MDNUM3), INTENT(IN)  :: X,Y
      REAL(DP), INTENT(IN)  :: DER0_0,DER1_0,DER1_1, &
                               DER2_0,DER2_1,DER2_2,DER3_0, &
                               DER3_1,DER3_2,DER3_3
      TYPE(MDNUM3) :: RES
      TYPE(MDNUM3) :: DX, DY

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

      

   END FUNCTION MDNUM3_F2EVAL


   ELEMENTAL FUNCTION MDNUM3_POW_OO(X,Y) RESULT(RES)

      TYPE(MDNUM3), INTENT(IN) :: X, Y
      REAL(DP) :: DER0_0,DER1_0,DER1_1,DER2_0,DER2_1,DER2_2,DER3_0,DER3_1,DER3_2,DER3_3
      TYPE(MDNUM3) :: RES
      
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

      RES = F2EVAL(X,Y,DER0_0,DER1_0,DER1_1,DER2_0,DER2_1,DER2_2,DER3_0,DER3_1,DER3_2,DER3_3)

   END FUNCTION MDNUM3_POW_OO


   FUNCTION MDNUM3_INV2X2(A,det)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(MDNUM3) , INTENT(IN) :: A(2,2) 
      TYPE(MDNUM3) , INTENT(IN), OPTIONAL :: det
      REAL(DP) :: detCalc
      TYPE(MDNUM3) :: RES(SIZE(A,1),SIZE(A,2)) 

      IF (PRESENT(det)) THEN
         detCalc=det%R
      ELSE
         detCalc=det2x2(A%R)
      END IF

      ! Get real part 
      RES%R=INV2X2(A%R,detCalc)

      ! Order 1
      RES%E1=-MATMUL(RES%R,(MATMUL(A%E1,RES%R)))
      RES%E2=-MATMUL(RES%R,(MATMUL(A%E2,RES%R)))
      RES%E3=-MATMUL(RES%R,(MATMUL(A%E3,RES%R)))

      ! Order 2
      RES%E12=-MATMUL(RES%R,(MATMUL(A%E12,RES%R)+MATMUL(A%E1,RES%E2)+&
             MATMUL(A%E2,RES%E1)))
      RES%E13=-MATMUL(RES%R,(MATMUL(A%E13,RES%R)+MATMUL(A%E1,RES%E3)+&
             MATMUL(A%E3,RES%E1)))
      RES%E23=-MATMUL(RES%R,(MATMUL(A%E23,RES%R)+MATMUL(A%E2,RES%E3)+&
             MATMUL(A%E3,RES%E2)))

      ! Order 3
      RES%E123=-MATMUL(RES%R,(MATMUL(A%E123,RES%R)+MATMUL(A%E1,RES%E23)+&
              MATMUL(A%E23,RES%E1)+MATMUL(A%E2,RES%E13)+MATMUL(A%E13,RES%E2)+&
              MATMUL(A%E3,RES%E12)+MATMUL(A%E12,RES%E3)))

   END FUNCTION MDNUM3_INV2X2

   FUNCTION MDNUM3_INV3X3(A,det)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(MDNUM3) , INTENT(IN) :: A(3,3) 
      TYPE(MDNUM3) , INTENT(IN), OPTIONAL :: det
      REAL(DP) :: detCalc
      TYPE(MDNUM3) :: RES(SIZE(A,1),SIZE(A,2)) 

      IF (PRESENT(det)) THEN
         detCalc=det%R
      ELSE
         detCalc=det3x3(A%R)
      END IF

      ! Get real part 
      RES%R=INV3X3(A%R,detCalc)

      ! Order 1
      RES%E1=-MATMUL(RES%R,(MATMUL(A%E1,RES%R)))
      RES%E2=-MATMUL(RES%R,(MATMUL(A%E2,RES%R)))
      RES%E3=-MATMUL(RES%R,(MATMUL(A%E3,RES%R)))

      ! Order 2
      RES%E12=-MATMUL(RES%R,(MATMUL(A%E12,RES%R)+MATMUL(A%E1,RES%E2)+&
             MATMUL(A%E2,RES%E1)))
      RES%E13=-MATMUL(RES%R,(MATMUL(A%E13,RES%R)+MATMUL(A%E1,RES%E3)+&
             MATMUL(A%E3,RES%E1)))
      RES%E23=-MATMUL(RES%R,(MATMUL(A%E23,RES%R)+MATMUL(A%E2,RES%E3)+&
             MATMUL(A%E3,RES%E2)))

      ! Order 3
      RES%E123=-MATMUL(RES%R,(MATMUL(A%E123,RES%R)+MATMUL(A%E1,RES%E23)+&
              MATMUL(A%E23,RES%E1)+MATMUL(A%E2,RES%E13)+MATMUL(A%E13,RES%E2)+&
              MATMUL(A%E3,RES%E12)+MATMUL(A%E12,RES%E3)))

   END FUNCTION MDNUM3_INV3X3

   FUNCTION MDNUM3_INV4X4(A,det)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(MDNUM3) , INTENT(IN) :: A(4,4) 
      TYPE(MDNUM3) , INTENT(IN), OPTIONAL :: det
      REAL(DP) :: detCalc
      TYPE(MDNUM3) :: RES(SIZE(A,1),SIZE(A,2)) 

      IF (PRESENT(det)) THEN
         detCalc=det%R
      ELSE
         detCalc=det4x4(A%R)
      END IF

      ! Get real part 
      RES%R=INV4X4(A%R,detCalc)

      ! Order 1
      RES%E1=-MATMUL(RES%R,(MATMUL(A%E1,RES%R)))
      RES%E2=-MATMUL(RES%R,(MATMUL(A%E2,RES%R)))
      RES%E3=-MATMUL(RES%R,(MATMUL(A%E3,RES%R)))

      ! Order 2
      RES%E12=-MATMUL(RES%R,(MATMUL(A%E12,RES%R)+MATMUL(A%E1,RES%E2)+&
             MATMUL(A%E2,RES%E1)))
      RES%E13=-MATMUL(RES%R,(MATMUL(A%E13,RES%R)+MATMUL(A%E1,RES%E3)+&
             MATMUL(A%E3,RES%E1)))
      RES%E23=-MATMUL(RES%R,(MATMUL(A%E23,RES%R)+MATMUL(A%E2,RES%E3)+&
             MATMUL(A%E3,RES%E2)))

      ! Order 3
      RES%E123=-MATMUL(RES%R,(MATMUL(A%E123,RES%R)+MATMUL(A%E1,RES%E23)+&
              MATMUL(A%E23,RES%E1)+MATMUL(A%E2,RES%E13)+MATMUL(A%E13,RES%E2)+&
              MATMUL(A%E3,RES%E12)+MATMUL(A%E12,RES%E3)))

   END FUNCTION MDNUM3_INV4X4

END MODULE MDUAL3
