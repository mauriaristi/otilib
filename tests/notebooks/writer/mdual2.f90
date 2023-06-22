MODULE MDUAL2

   USE master_parameters
   USE real_utils

   IMPLICIT NONE

   INTEGER, PARAMETER :: NUM_IM_DIR = 4
   INTEGER, PARAMETER :: TORDER     = 2
   INTEGER, PARAMETER :: N_IMDIR_ORDER(3) = [1,2,1]

   TYPE MDNUM2
     ! Real
     REAL(DP) :: R
     ! Order 1
     REAL(DP) :: E1
     REAL(DP) :: E2
     ! Order 2
     REAL(DP) :: E12
   END TYPE MDNUM2

   ! Constant imaginary directions.
   ! Order 1
   TYPE(MDNUM2), PARAMETER :: E1 = MDNUM2(0.0_DP,1.0_DP,0.0_DP,0.0_DP)
   TYPE(MDNUM2), PARAMETER :: E2 = MDNUM2(0.0_DP,0.0_DP,1.0_DP,0.0_DP)
   ! Order 2
   TYPE(MDNUM2), PARAMETER :: E12 = MDNUM2(0.0_DP,0.0_DP,0.0_DP,1.0_DP)


   INTERFACE OPERATOR(*)
      MODULE PROCEDURE MDNUM2_MUL_OO_SS,MDNUM2_MUL_RO_SS,MDNUM2_MUL_OR_SS,MDNUM2_MUL_OO_VS,&
                       MDNUM2_MUL_RO_VS,MDNUM2_MUL_OR_VS,MDNUM2_MUL_OO_MS,MDNUM2_MUL_RO_MS,&
                       MDNUM2_MUL_OR_MS,MDNUM2_MUL_OO_SV,MDNUM2_MUL_RO_SV,MDNUM2_MUL_OR_SV,&
                       MDNUM2_MUL_OO_SM,MDNUM2_MUL_RO_SM,MDNUM2_MUL_OR_SM
   END INTERFACE

   INTERFACE OPERATOR(+)
      MODULE PROCEDURE MDNUM2_ADD_OO_SS,MDNUM2_ADD_RO_SS,MDNUM2_ADD_OR_SS,MDNUM2_ADD_OO_VS,&
                       MDNUM2_ADD_RO_VS,MDNUM2_ADD_OR_VS,MDNUM2_ADD_OO_MS,MDNUM2_ADD_RO_MS,&
                       MDNUM2_ADD_OR_MS,MDNUM2_ADD_OO_SV,MDNUM2_ADD_RO_SV,MDNUM2_ADD_OR_SV,&
                       MDNUM2_ADD_OO_SM,MDNUM2_ADD_RO_SM,MDNUM2_ADD_OR_SM
   END INTERFACE

   INTERFACE OPERATOR(-)
      MODULE PROCEDURE MDNUM2_NEG,MDNUM2_SUB_OO_SS,MDNUM2_SUB_RO_SS,MDNUM2_SUB_OR_SS,&
                       MDNUM2_SUB_OO_VS,MDNUM2_SUB_RO_VS,MDNUM2_SUB_OR_VS,MDNUM2_SUB_OO_MS,&
                       MDNUM2_SUB_RO_MS,MDNUM2_SUB_OR_MS,MDNUM2_SUB_OO_SV,MDNUM2_SUB_RO_SV,&
                       MDNUM2_SUB_OR_SV,MDNUM2_SUB_OO_SM,MDNUM2_SUB_RO_SM,MDNUM2_SUB_OR_SM
   END INTERFACE

   INTERFACE OPERATOR(/)
      MODULE PROCEDURE MDNUM2_DIVISION_OO,MDNUM2_DIVISION_OR,MDNUM2_DIVISION_RO
   END INTERFACE

   INTERFACE ASSIGNMENT(=)
      MODULE PROCEDURE MDNUM2_ASSIGN_R
   END INTERFACE

   INTERFACE OPERATOR(**)
      MODULE PROCEDURE MDNUM2_POW_OR,MDNUM2_POW_RO,MDNUM2_POW_OO
   END INTERFACE

   INTERFACE PPRINT
      MODULE PROCEDURE MDNUM2_PPRINT_S,MDNUM2_PPRINT_V,MDNUM2_PPRINT_M
   END INTERFACE

   INTERFACE TRANSPOSE
      MODULE PROCEDURE MDNUM2_TRANSPOSE
   END INTERFACE

   INTERFACE MATMUL
      MODULE PROCEDURE MDNUM2_MATMUL_MDNUM2,R_MATMUL_MDNUM2,MDNUM2_MATMUL_R
   END INTERFACE

   INTERFACE DOT_PRODUCT
      MODULE PROCEDURE MDNUM2_DOT_PRODUCT_MDNUM2,R_DOT_PRODUCT_MDNUM2,MDNUM2_DOT_PRODUCT_R
   END INTERFACE

   INTERFACE UNFOLD
      MODULE PROCEDURE MDNUM2_TO_CR_MAT_S,MDNUM2_TO_CR_MAT_V,MDNUM2_TO_CR_MAT_M
   END INTERFACE

   INTERFACE TO_CR
      MODULE PROCEDURE MDNUM2_TO_CR_MAT_S,MDNUM2_TO_CR_MAT_V,MDNUM2_TO_CR_MAT_M
   END INTERFACE

   INTERFACE SIN
      MODULE PROCEDURE MDNUM2_SIN
   END INTERFACE

   INTERFACE COS
      MODULE PROCEDURE MDNUM2_COS
   END INTERFACE

   INTERFACE TAN
      MODULE PROCEDURE MDNUM2_TAN
   END INTERFACE

   INTERFACE ASIN
      MODULE PROCEDURE MDNUM2_ASIN
   END INTERFACE

   INTERFACE ACOS
      MODULE PROCEDURE MDNUM2_ACOS
   END INTERFACE

   INTERFACE ATAN
      MODULE PROCEDURE MDNUM2_ATAN
   END INTERFACE

   INTERFACE SINH
      MODULE PROCEDURE MDNUM2_SINH
   END INTERFACE

   INTERFACE COSH
      MODULE PROCEDURE MDNUM2_COSH
   END INTERFACE

   INTERFACE TANH
      MODULE PROCEDURE MDNUM2_TANH
   END INTERFACE

   INTERFACE SQRT
      MODULE PROCEDURE MDNUM2_SQRT
   END INTERFACE

   INTERFACE LOG
      MODULE PROCEDURE MDNUM2_LOG
   END INTERFACE

   INTERFACE EXP
      MODULE PROCEDURE MDNUM2_EXP
   END INTERFACE

   INTERFACE GEM
      MODULE PROCEDURE MDNUM2_GEM_OOO,MDNUM2_GEM_ROO,MDNUM2_GEM_ORO
   END INTERFACE

   INTERFACE FEVAL
      MODULE PROCEDURE MDNUM2_FEVAL
   END INTERFACE

   INTERFACE F2EVAL
      MODULE PROCEDURE MDNUM2_F2EVAL
   END INTERFACE

   INTERFACE REAL
      MODULE PROCEDURE MDNUM2_REAL
   END INTERFACE

   INTERFACE DET2X2
      MODULE PROCEDURE MDNUM2_det2x2
   END INTERFACE

   INTERFACE DET3X3
      MODULE PROCEDURE MDNUM2_det3x3
   END INTERFACE

   INTERFACE DET4X4
      MODULE PROCEDURE MDNUM2_det4x4
   END INTERFACE

   INTERFACE INV2X2
      MODULE PROCEDURE MDNUM2_INV2X2
   END INTERFACE

   INTERFACE INV3X3
      MODULE PROCEDURE MDNUM2_INV3X3
   END INTERFACE

   INTERFACE INV4X4
      MODULE PROCEDURE MDNUM2_INV4X4
   END INTERFACE

   INTERFACE GETIM
      MODULE PROCEDURE MDNUM2_GETIM_S,MDNUM2_GETIM_V,MDNUM2_GETIM_M
   END INTERFACE

   INTERFACE SETIM
      MODULE PROCEDURE MDNUM2_SETIM_S,MDNUM2_SETIM_V,MDNUM2_SETIM_M
   END INTERFACE

   CONTAINS

   ELEMENTAL SUBROUTINE MDNUM2_ASSIGN_R(RES,LHS)
      
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS 
      TYPE(MDNUM2), INTENT(OUT) :: RES 

      ! Assign like function 'LHS'
      ! Real
      RES%R = LHS

      ! Order 1
      RES%E1 = 0.0_DP
      RES%E2 = 0.0_DP

      ! Order 2
      RES%E12 = 0.0_DP

   END SUBROUTINE MDNUM2_ASSIGN_R

   ELEMENTAL FUNCTION MDNUM2_NEG(LHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(MDNUM2), INTENT(IN) :: LHS 
      TYPE(MDNUM2) :: RES 

      ! Negation like function '-LHS'
      ! Real
      RES%R = -LHS%R
      ! Order 1
      RES%E1 = -LHS%E1
      RES%E2 = -LHS%E2
      ! Order 2
      RES%E12 = -LHS%E12

   END FUNCTION MDNUM2_NEG

   ELEMENTAL FUNCTION MDNUM2_ADD_OO_SS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(MDNUM2), INTENT(IN) :: LHS
      TYPE(MDNUM2), INTENT(IN) :: RHS
      TYPE(MDNUM2) :: RES 

      ! Addition like function 'LHS + RHS'
      !  Real
      RES%R = LHS%R + RHS%R

      ! Order 1
      RES%E1 = LHS%E1 + RHS%E1
      RES%E2 = LHS%E2 + RHS%E2

      ! Order 2
      RES%E12 = LHS%E12 + RHS%E12

   END FUNCTION MDNUM2_ADD_OO_SS

   ELEMENTAL FUNCTION MDNUM2_ADD_RO_SS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS
      TYPE(MDNUM2), INTENT(IN) :: RHS
      TYPE(MDNUM2) :: RES 

      ! Addition like function 'LHS + RHS'
      ! Real
      RES%R = LHS + RHS%R

      ! Order 1
      RES%E1 =  + RHS%E1
      RES%E2 =  + RHS%E2

      ! Order 2
      RES%E12 =  + RHS%E12

   END FUNCTION MDNUM2_ADD_RO_SS

   ELEMENTAL FUNCTION MDNUM2_ADD_OR_SS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(MDNUM2), INTENT(IN) :: LHS
      REAL(DP), INTENT(IN) :: RHS
      TYPE(MDNUM2) :: RES 

      ! Addition like function 'LHS + RHS'
      ! Real
      RES%R = LHS%R + RHS

      ! Order 1
      RES%E1 = LHS%E1
      RES%E2 = LHS%E2

      ! Order 2
      RES%E12 = LHS%E12

   END FUNCTION MDNUM2_ADD_OR_SS

   ELEMENTAL FUNCTION MDNUM2_SUB_OO_SS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(MDNUM2), INTENT(IN) :: LHS
      TYPE(MDNUM2), INTENT(IN) :: RHS
      TYPE(MDNUM2) :: RES 

      ! Addition like function 'LHS - RHS'
      !  Real
      RES%R = LHS%R - RHS%R

      ! Order 1
      RES%E1 = LHS%E1 - RHS%E1
      RES%E2 = LHS%E2 - RHS%E2

      ! Order 2
      RES%E12 = LHS%E12 - RHS%E12

   END FUNCTION MDNUM2_SUB_OO_SS

   ELEMENTAL FUNCTION MDNUM2_SUB_RO_SS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS
      TYPE(MDNUM2), INTENT(IN) :: RHS
      TYPE(MDNUM2) :: RES 

      ! Addition like function 'LHS - RHS'
      ! Real
      RES%R = LHS - RHS%R

      ! Order 1
      RES%E1 =  - RHS%E1
      RES%E2 =  - RHS%E2

      ! Order 2
      RES%E12 =  - RHS%E12

   END FUNCTION MDNUM2_SUB_RO_SS

   ELEMENTAL FUNCTION MDNUM2_SUB_OR_SS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(MDNUM2), INTENT(IN) :: LHS
      REAL(DP), INTENT(IN) :: RHS
      TYPE(MDNUM2) :: RES 

      ! Addition like function 'LHS - RHS'
      ! Real
      RES%R = LHS%R - RHS

      ! Order 1
      RES%E1 = LHS%E1
      RES%E2 = LHS%E2

      ! Order 2
      RES%E12 = LHS%E12

   END FUNCTION MDNUM2_SUB_OR_SS

   ELEMENTAL FUNCTION MDNUM2_MUL_OO_SS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(MDNUM2), INTENT(IN) :: LHS
      TYPE(MDNUM2), INTENT(IN) :: RHS
      TYPE(MDNUM2) :: RES 

      !  Multiplication like function 'LHS*RHS'
      ! Order 2
      RES%E12 = LHS%R*RHS%E12 + LHS%E12*RHS%R +  &
             LHS%E1*RHS%E2 + LHS%E2*RHS%E1
      ! Order 1
      RES%E1 = LHS%R*RHS%E1 + LHS%E1*RHS%R
      RES%E2 = LHS%R*RHS%E2 + LHS%E2*RHS%R
      ! Order 0
      RES%R = LHS%R*RHS%R

   END FUNCTION MDNUM2_MUL_OO_SS

   ELEMENTAL FUNCTION MDNUM2_MUL_RO_SS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS
      TYPE(MDNUM2), INTENT(IN) :: RHS
      TYPE(MDNUM2) :: RES 

      ! Multiplication like function 'LHS*RHS'
      !  Real
      RES%R = LHS*RHS%R

      ! Order 1
      RES%E1 = LHS*RHS%E1
      RES%E2 = LHS*RHS%E2

      ! Order 2
      RES%E12 = LHS*RHS%E12

   END FUNCTION MDNUM2_MUL_RO_SS

   ELEMENTAL FUNCTION MDNUM2_MUL_OR_SS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(MDNUM2), INTENT(IN) :: LHS
      REAL(DP), INTENT(IN) :: RHS
      TYPE(MDNUM2) :: RES 

      ! Multiplication like function 'LHS*RHS'
      !  Real
      RES%R = LHS%R*RHS

      ! Order 1
      RES%E1 = LHS%E1*RHS
      RES%E2 = LHS%E2*RHS

      ! Order 2
      RES%E12 = LHS%E12*RHS

   END FUNCTION MDNUM2_MUL_OR_SS

   FUNCTION MDNUM2_ADD_OO_VS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(MDNUM2), INTENT(IN) :: LHS(:)
      TYPE(MDNUM2), INTENT(IN) :: RHS
      TYPE(MDNUM2) :: RES(SIZE(LHS,1)) 

      ! Addition like function 'LHS + RHS'
      !  Real
      RES%R = LHS%R + RHS%R

      ! Order 1
      RES%E1 = LHS%E1 + RHS%E1
      RES%E2 = LHS%E2 + RHS%E2

      ! Order 2
      RES%E12 = LHS%E12 + RHS%E12

   END FUNCTION MDNUM2_ADD_OO_VS

   FUNCTION MDNUM2_ADD_RO_VS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS(:)
      TYPE(MDNUM2), INTENT(IN) :: RHS
      TYPE(MDNUM2) :: RES(SIZE(LHS,1)) 

      ! Addition like function 'LHS + RHS'
      ! Real
      RES%R = LHS + RHS%R

      ! Order 1
      RES%E1 =  + RHS%E1
      RES%E2 =  + RHS%E2

      ! Order 2
      RES%E12 =  + RHS%E12

   END FUNCTION MDNUM2_ADD_RO_VS

   FUNCTION MDNUM2_ADD_OR_VS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(MDNUM2), INTENT(IN) :: LHS(:)
      REAL(DP), INTENT(IN) :: RHS
      TYPE(MDNUM2) :: RES(SIZE(LHS,1)) 

      ! Addition like function 'LHS + RHS'
      ! Real
      RES%R = LHS%R + RHS

      ! Order 1
      RES%E1 = LHS%E1
      RES%E2 = LHS%E2

      ! Order 2
      RES%E12 = LHS%E12

   END FUNCTION MDNUM2_ADD_OR_VS

   FUNCTION MDNUM2_SUB_OO_VS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(MDNUM2), INTENT(IN) :: LHS(:)
      TYPE(MDNUM2), INTENT(IN) :: RHS
      TYPE(MDNUM2) :: RES(SIZE(LHS,1)) 

      ! Addition like function 'LHS - RHS'
      !  Real
      RES%R = LHS%R - RHS%R

      ! Order 1
      RES%E1 = LHS%E1 - RHS%E1
      RES%E2 = LHS%E2 - RHS%E2

      ! Order 2
      RES%E12 = LHS%E12 - RHS%E12

   END FUNCTION MDNUM2_SUB_OO_VS

   FUNCTION MDNUM2_SUB_RO_VS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS(:)
      TYPE(MDNUM2), INTENT(IN) :: RHS
      TYPE(MDNUM2) :: RES(SIZE(LHS,1)) 

      ! Addition like function 'LHS - RHS'
      ! Real
      RES%R = LHS - RHS%R

      ! Order 1
      RES%E1 =  - RHS%E1
      RES%E2 =  - RHS%E2

      ! Order 2
      RES%E12 =  - RHS%E12

   END FUNCTION MDNUM2_SUB_RO_VS

   FUNCTION MDNUM2_SUB_OR_VS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(MDNUM2), INTENT(IN) :: LHS(:)
      REAL(DP), INTENT(IN) :: RHS
      TYPE(MDNUM2) :: RES(SIZE(LHS,1)) 

      ! Addition like function 'LHS - RHS'
      ! Real
      RES%R = LHS%R - RHS

      ! Order 1
      RES%E1 = LHS%E1
      RES%E2 = LHS%E2

      ! Order 2
      RES%E12 = LHS%E12

   END FUNCTION MDNUM2_SUB_OR_VS

   FUNCTION MDNUM2_MUL_OO_VS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(MDNUM2), INTENT(IN) :: LHS(:)
      TYPE(MDNUM2), INTENT(IN) :: RHS
      TYPE(MDNUM2) :: RES(SIZE(LHS,1)) 

      !  Multiplication like function 'LHS*RHS'
      ! Order 2
      RES%E12 = LHS%R*RHS%E12 + LHS%E12*RHS%R +  &
             LHS%E1*RHS%E2 + LHS%E2*RHS%E1
      ! Order 1
      RES%E1 = LHS%R*RHS%E1 + LHS%E1*RHS%R
      RES%E2 = LHS%R*RHS%E2 + LHS%E2*RHS%R
      ! Order 0
      RES%R = LHS%R*RHS%R

   END FUNCTION MDNUM2_MUL_OO_VS

   FUNCTION MDNUM2_MUL_RO_VS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS(:)
      TYPE(MDNUM2), INTENT(IN) :: RHS
      TYPE(MDNUM2) :: RES(SIZE(LHS,1)) 

      ! Multiplication like function 'LHS*RHS'
      !  Real
      RES%R = LHS*RHS%R

      ! Order 1
      RES%E1 = LHS*RHS%E1
      RES%E2 = LHS*RHS%E2

      ! Order 2
      RES%E12 = LHS*RHS%E12

   END FUNCTION MDNUM2_MUL_RO_VS

   FUNCTION MDNUM2_MUL_OR_VS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(MDNUM2), INTENT(IN) :: LHS(:)
      REAL(DP), INTENT(IN) :: RHS
      TYPE(MDNUM2) :: RES(SIZE(LHS,1)) 

      ! Multiplication like function 'LHS*RHS'
      !  Real
      RES%R = LHS%R*RHS

      ! Order 1
      RES%E1 = LHS%E1*RHS
      RES%E2 = LHS%E2*RHS

      ! Order 2
      RES%E12 = LHS%E12*RHS

   END FUNCTION MDNUM2_MUL_OR_VS

   FUNCTION MDNUM2_ADD_OO_MS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(MDNUM2), INTENT(IN) :: LHS(:,:)
      TYPE(MDNUM2), INTENT(IN) :: RHS
      TYPE(MDNUM2) :: RES(SIZE(LHS,1),SIZE(LHS,2)) 

      ! Addition like function 'LHS + RHS'
      !  Real
      RES%R = LHS%R + RHS%R

      ! Order 1
      RES%E1 = LHS%E1 + RHS%E1
      RES%E2 = LHS%E2 + RHS%E2

      ! Order 2
      RES%E12 = LHS%E12 + RHS%E12

   END FUNCTION MDNUM2_ADD_OO_MS

   FUNCTION MDNUM2_ADD_RO_MS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS(:,:)
      TYPE(MDNUM2), INTENT(IN) :: RHS
      TYPE(MDNUM2) :: RES(SIZE(LHS,1),SIZE(LHS,2)) 

      ! Addition like function 'LHS + RHS'
      ! Real
      RES%R = LHS + RHS%R

      ! Order 1
      RES%E1 =  + RHS%E1
      RES%E2 =  + RHS%E2

      ! Order 2
      RES%E12 =  + RHS%E12

   END FUNCTION MDNUM2_ADD_RO_MS

   FUNCTION MDNUM2_ADD_OR_MS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(MDNUM2), INTENT(IN) :: LHS(:,:)
      REAL(DP), INTENT(IN) :: RHS
      TYPE(MDNUM2) :: RES(SIZE(LHS,1),SIZE(LHS,2)) 

      ! Addition like function 'LHS + RHS'
      ! Real
      RES%R = LHS%R + RHS

      ! Order 1
      RES%E1 = LHS%E1
      RES%E2 = LHS%E2

      ! Order 2
      RES%E12 = LHS%E12

   END FUNCTION MDNUM2_ADD_OR_MS

   FUNCTION MDNUM2_SUB_OO_MS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(MDNUM2), INTENT(IN) :: LHS(:,:)
      TYPE(MDNUM2), INTENT(IN) :: RHS
      TYPE(MDNUM2) :: RES(SIZE(LHS,1),SIZE(LHS,2)) 

      ! Addition like function 'LHS - RHS'
      !  Real
      RES%R = LHS%R - RHS%R

      ! Order 1
      RES%E1 = LHS%E1 - RHS%E1
      RES%E2 = LHS%E2 - RHS%E2

      ! Order 2
      RES%E12 = LHS%E12 - RHS%E12

   END FUNCTION MDNUM2_SUB_OO_MS

   FUNCTION MDNUM2_SUB_RO_MS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS(:,:)
      TYPE(MDNUM2), INTENT(IN) :: RHS
      TYPE(MDNUM2) :: RES(SIZE(LHS,1),SIZE(LHS,2)) 

      ! Addition like function 'LHS - RHS'
      ! Real
      RES%R = LHS - RHS%R

      ! Order 1
      RES%E1 =  - RHS%E1
      RES%E2 =  - RHS%E2

      ! Order 2
      RES%E12 =  - RHS%E12

   END FUNCTION MDNUM2_SUB_RO_MS

   FUNCTION MDNUM2_SUB_OR_MS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(MDNUM2), INTENT(IN) :: LHS(:,:)
      REAL(DP), INTENT(IN) :: RHS
      TYPE(MDNUM2) :: RES(SIZE(LHS,1),SIZE(LHS,2)) 

      ! Addition like function 'LHS - RHS'
      ! Real
      RES%R = LHS%R - RHS

      ! Order 1
      RES%E1 = LHS%E1
      RES%E2 = LHS%E2

      ! Order 2
      RES%E12 = LHS%E12

   END FUNCTION MDNUM2_SUB_OR_MS

   FUNCTION MDNUM2_MUL_OO_MS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(MDNUM2), INTENT(IN) :: LHS(:,:)
      TYPE(MDNUM2), INTENT(IN) :: RHS
      TYPE(MDNUM2) :: RES(SIZE(LHS,1),SIZE(LHS,2)) 

      !  Multiplication like function 'LHS*RHS'
      ! Order 2
      RES%E12 = LHS%R*RHS%E12 + LHS%E12*RHS%R +  &
             LHS%E1*RHS%E2 + LHS%E2*RHS%E1
      ! Order 1
      RES%E1 = LHS%R*RHS%E1 + LHS%E1*RHS%R
      RES%E2 = LHS%R*RHS%E2 + LHS%E2*RHS%R
      ! Order 0
      RES%R = LHS%R*RHS%R

   END FUNCTION MDNUM2_MUL_OO_MS

   FUNCTION MDNUM2_MUL_RO_MS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS(:,:)
      TYPE(MDNUM2), INTENT(IN) :: RHS
      TYPE(MDNUM2) :: RES(SIZE(LHS,1),SIZE(LHS,2)) 

      ! Multiplication like function 'LHS*RHS'
      !  Real
      RES%R = LHS*RHS%R

      ! Order 1
      RES%E1 = LHS*RHS%E1
      RES%E2 = LHS*RHS%E2

      ! Order 2
      RES%E12 = LHS*RHS%E12

   END FUNCTION MDNUM2_MUL_RO_MS

   FUNCTION MDNUM2_MUL_OR_MS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(MDNUM2), INTENT(IN) :: LHS(:,:)
      REAL(DP), INTENT(IN) :: RHS
      TYPE(MDNUM2) :: RES(SIZE(LHS,1),SIZE(LHS,2)) 

      ! Multiplication like function 'LHS*RHS'
      !  Real
      RES%R = LHS%R*RHS

      ! Order 1
      RES%E1 = LHS%E1*RHS
      RES%E2 = LHS%E2*RHS

      ! Order 2
      RES%E12 = LHS%E12*RHS

   END FUNCTION MDNUM2_MUL_OR_MS

   FUNCTION MDNUM2_ADD_OO_SV(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(MDNUM2), INTENT(IN) :: LHS
      TYPE(MDNUM2), INTENT(IN) :: RHS(:)
      TYPE(MDNUM2) :: RES(SIZE(RHS,1)) 

      ! Addition like function 'LHS + RHS'
      !  Real
      RES%R = LHS%R + RHS%R

      ! Order 1
      RES%E1 = LHS%E1 + RHS%E1
      RES%E2 = LHS%E2 + RHS%E2

      ! Order 2
      RES%E12 = LHS%E12 + RHS%E12

   END FUNCTION MDNUM2_ADD_OO_SV

   FUNCTION MDNUM2_ADD_RO_SV(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS
      TYPE(MDNUM2), INTENT(IN) :: RHS(:)
      TYPE(MDNUM2) :: RES(SIZE(RHS,1)) 

      ! Addition like function 'LHS + RHS'
      ! Real
      RES%R = LHS + RHS%R

      ! Order 1
      RES%E1 =  + RHS%E1
      RES%E2 =  + RHS%E2

      ! Order 2
      RES%E12 =  + RHS%E12

   END FUNCTION MDNUM2_ADD_RO_SV

   FUNCTION MDNUM2_ADD_OR_SV(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(MDNUM2), INTENT(IN) :: LHS
      REAL(DP), INTENT(IN) :: RHS(:)
      TYPE(MDNUM2) :: RES(SIZE(RHS,1)) 

      ! Addition like function 'LHS + RHS'
      ! Real
      RES%R = LHS%R + RHS

      ! Order 1
      RES%E1 = LHS%E1
      RES%E2 = LHS%E2

      ! Order 2
      RES%E12 = LHS%E12

   END FUNCTION MDNUM2_ADD_OR_SV

   FUNCTION MDNUM2_SUB_OO_SV(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(MDNUM2), INTENT(IN) :: LHS
      TYPE(MDNUM2), INTENT(IN) :: RHS(:)
      TYPE(MDNUM2) :: RES(SIZE(RHS,1)) 

      ! Addition like function 'LHS - RHS'
      !  Real
      RES%R = LHS%R - RHS%R

      ! Order 1
      RES%E1 = LHS%E1 - RHS%E1
      RES%E2 = LHS%E2 - RHS%E2

      ! Order 2
      RES%E12 = LHS%E12 - RHS%E12

   END FUNCTION MDNUM2_SUB_OO_SV

   FUNCTION MDNUM2_SUB_RO_SV(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS
      TYPE(MDNUM2), INTENT(IN) :: RHS(:)
      TYPE(MDNUM2) :: RES(SIZE(RHS,1)) 

      ! Addition like function 'LHS - RHS'
      ! Real
      RES%R = LHS - RHS%R

      ! Order 1
      RES%E1 =  - RHS%E1
      RES%E2 =  - RHS%E2

      ! Order 2
      RES%E12 =  - RHS%E12

   END FUNCTION MDNUM2_SUB_RO_SV

   FUNCTION MDNUM2_SUB_OR_SV(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(MDNUM2), INTENT(IN) :: LHS
      REAL(DP), INTENT(IN) :: RHS(:)
      TYPE(MDNUM2) :: RES(SIZE(RHS,1)) 

      ! Addition like function 'LHS - RHS'
      ! Real
      RES%R = LHS%R - RHS

      ! Order 1
      RES%E1 = LHS%E1
      RES%E2 = LHS%E2

      ! Order 2
      RES%E12 = LHS%E12

   END FUNCTION MDNUM2_SUB_OR_SV

   FUNCTION MDNUM2_MUL_OO_SV(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(MDNUM2), INTENT(IN) :: LHS
      TYPE(MDNUM2), INTENT(IN) :: RHS(:)
      TYPE(MDNUM2) :: RES(SIZE(RHS,1)) 

      !  Multiplication like function 'LHS*RHS'
      ! Order 2
      RES%E12 = LHS%R*RHS%E12 + LHS%E12*RHS%R +  &
             LHS%E1*RHS%E2 + LHS%E2*RHS%E1
      ! Order 1
      RES%E1 = LHS%R*RHS%E1 + LHS%E1*RHS%R
      RES%E2 = LHS%R*RHS%E2 + LHS%E2*RHS%R
      ! Order 0
      RES%R = LHS%R*RHS%R

   END FUNCTION MDNUM2_MUL_OO_SV

   FUNCTION MDNUM2_MUL_RO_SV(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS
      TYPE(MDNUM2), INTENT(IN) :: RHS(:)
      TYPE(MDNUM2) :: RES(SIZE(RHS,1)) 

      ! Multiplication like function 'LHS*RHS'
      !  Real
      RES%R = LHS*RHS%R

      ! Order 1
      RES%E1 = LHS*RHS%E1
      RES%E2 = LHS*RHS%E2

      ! Order 2
      RES%E12 = LHS*RHS%E12

   END FUNCTION MDNUM2_MUL_RO_SV

   FUNCTION MDNUM2_MUL_OR_SV(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(MDNUM2), INTENT(IN) :: LHS
      REAL(DP), INTENT(IN) :: RHS(:)
      TYPE(MDNUM2) :: RES(SIZE(RHS,1)) 

      ! Multiplication like function 'LHS*RHS'
      !  Real
      RES%R = LHS%R*RHS

      ! Order 1
      RES%E1 = LHS%E1*RHS
      RES%E2 = LHS%E2*RHS

      ! Order 2
      RES%E12 = LHS%E12*RHS

   END FUNCTION MDNUM2_MUL_OR_SV

   FUNCTION MDNUM2_ADD_OO_SM(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(MDNUM2), INTENT(IN) :: LHS
      TYPE(MDNUM2), INTENT(IN) :: RHS(:,:)
      TYPE(MDNUM2) :: RES(SIZE(RHS,1),SIZE(RHS,2)) 

      ! Addition like function 'LHS + RHS'
      !  Real
      RES%R = LHS%R + RHS%R

      ! Order 1
      RES%E1 = LHS%E1 + RHS%E1
      RES%E2 = LHS%E2 + RHS%E2

      ! Order 2
      RES%E12 = LHS%E12 + RHS%E12

   END FUNCTION MDNUM2_ADD_OO_SM

   FUNCTION MDNUM2_ADD_RO_SM(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS
      TYPE(MDNUM2), INTENT(IN) :: RHS(:,:)
      TYPE(MDNUM2) :: RES(SIZE(RHS,1),SIZE(RHS,2)) 

      ! Addition like function 'LHS + RHS'
      ! Real
      RES%R = LHS + RHS%R

      ! Order 1
      RES%E1 =  + RHS%E1
      RES%E2 =  + RHS%E2

      ! Order 2
      RES%E12 =  + RHS%E12

   END FUNCTION MDNUM2_ADD_RO_SM

   FUNCTION MDNUM2_ADD_OR_SM(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(MDNUM2), INTENT(IN) :: LHS
      REAL(DP), INTENT(IN) :: RHS(:,:)
      TYPE(MDNUM2) :: RES(SIZE(RHS,1),SIZE(RHS,2)) 

      ! Addition like function 'LHS + RHS'
      ! Real
      RES%R = LHS%R + RHS

      ! Order 1
      RES%E1 = LHS%E1
      RES%E2 = LHS%E2

      ! Order 2
      RES%E12 = LHS%E12

   END FUNCTION MDNUM2_ADD_OR_SM

   FUNCTION MDNUM2_SUB_OO_SM(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(MDNUM2), INTENT(IN) :: LHS
      TYPE(MDNUM2), INTENT(IN) :: RHS(:,:)
      TYPE(MDNUM2) :: RES(SIZE(RHS,1),SIZE(RHS,2)) 

      ! Addition like function 'LHS - RHS'
      !  Real
      RES%R = LHS%R - RHS%R

      ! Order 1
      RES%E1 = LHS%E1 - RHS%E1
      RES%E2 = LHS%E2 - RHS%E2

      ! Order 2
      RES%E12 = LHS%E12 - RHS%E12

   END FUNCTION MDNUM2_SUB_OO_SM

   FUNCTION MDNUM2_SUB_RO_SM(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS
      TYPE(MDNUM2), INTENT(IN) :: RHS(:,:)
      TYPE(MDNUM2) :: RES(SIZE(RHS,1),SIZE(RHS,2)) 

      ! Addition like function 'LHS - RHS'
      ! Real
      RES%R = LHS - RHS%R

      ! Order 1
      RES%E1 =  - RHS%E1
      RES%E2 =  - RHS%E2

      ! Order 2
      RES%E12 =  - RHS%E12

   END FUNCTION MDNUM2_SUB_RO_SM

   FUNCTION MDNUM2_SUB_OR_SM(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(MDNUM2), INTENT(IN) :: LHS
      REAL(DP), INTENT(IN) :: RHS(:,:)
      TYPE(MDNUM2) :: RES(SIZE(RHS,1),SIZE(RHS,2)) 

      ! Addition like function 'LHS - RHS'
      ! Real
      RES%R = LHS%R - RHS

      ! Order 1
      RES%E1 = LHS%E1
      RES%E2 = LHS%E2

      ! Order 2
      RES%E12 = LHS%E12

   END FUNCTION MDNUM2_SUB_OR_SM

   FUNCTION MDNUM2_MUL_OO_SM(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(MDNUM2), INTENT(IN) :: LHS
      TYPE(MDNUM2), INTENT(IN) :: RHS(:,:)
      TYPE(MDNUM2) :: RES(SIZE(RHS,1),SIZE(RHS,2)) 

      !  Multiplication like function 'LHS*RHS'
      ! Order 2
      RES%E12 = LHS%R*RHS%E12 + LHS%E12*RHS%R +  &
             LHS%E1*RHS%E2 + LHS%E2*RHS%E1
      ! Order 1
      RES%E1 = LHS%R*RHS%E1 + LHS%E1*RHS%R
      RES%E2 = LHS%R*RHS%E2 + LHS%E2*RHS%R
      ! Order 0
      RES%R = LHS%R*RHS%R

   END FUNCTION MDNUM2_MUL_OO_SM

   FUNCTION MDNUM2_MUL_RO_SM(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS
      TYPE(MDNUM2), INTENT(IN) :: RHS(:,:)
      TYPE(MDNUM2) :: RES(SIZE(RHS,1),SIZE(RHS,2)) 

      ! Multiplication like function 'LHS*RHS'
      !  Real
      RES%R = LHS*RHS%R

      ! Order 1
      RES%E1 = LHS*RHS%E1
      RES%E2 = LHS*RHS%E2

      ! Order 2
      RES%E12 = LHS*RHS%E12

   END FUNCTION MDNUM2_MUL_RO_SM

   FUNCTION MDNUM2_MUL_OR_SM(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(MDNUM2), INTENT(IN) :: LHS
      REAL(DP), INTENT(IN) :: RHS(:,:)
      TYPE(MDNUM2) :: RES(SIZE(RHS,1),SIZE(RHS,2)) 

      ! Multiplication like function 'LHS*RHS'
      !  Real
      RES%R = LHS%R*RHS

      ! Order 1
      RES%E1 = LHS%E1*RHS
      RES%E2 = LHS%E2*RHS

      ! Order 2
      RES%E12 = LHS%E12*RHS

   END FUNCTION MDNUM2_MUL_OR_SM

ELEMENTAL    FUNCTION MDNUM2_GEM_OOO(A,B,C)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(MDNUM2), INTENT(IN) :: A 
      TYPE(MDNUM2), INTENT(IN) :: B 
      TYPE(MDNUM2), INTENT(IN) :: C 
      TYPE(MDNUM2) :: RES 

      !  General multiplication like function 'A*B + C'

      ! Order 0
      RES%R = C%R + A%R*B%R

      ! Order 1
      RES%E1 = C%E1 + A%R*B%E1 + A%E1*B%R
      RES%E2 = C%E2 + A%R*B%E2 + A%E2*B%R

      ! Order 2
      RES%E12 = C%E12 + A%R*B%E12 + A%E12*B%R + A%E1*B%E2 &
              + A%E2*B%E1

   END FUNCTION MDNUM2_GEM_OOO

ELEMENTAL    FUNCTION MDNUM2_GEM_ROO(A,B,C)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: A 
      TYPE(MDNUM2), INTENT(IN) :: B 
      TYPE(MDNUM2), INTENT(IN) :: C 
      TYPE(MDNUM2) :: RES 

      !  General multiplication like function 'A*B + C'
      ! Order 2
      RES%E12 = C%E12 + A*B%E12
      ! Order 1
      RES%E1 = C%E1 + A*B%E1
      RES%E2 = C%E2 + A*B%E2
      ! Order 0
      RES%R = C%R + A*B%R

   END FUNCTION MDNUM2_GEM_ROO

ELEMENTAL    FUNCTION MDNUM2_GEM_ORO(A,B,C)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(MDNUM2), INTENT(IN) :: A 
      REAL(DP), INTENT(IN) :: B 
      TYPE(MDNUM2), INTENT(IN) :: C 
      TYPE(MDNUM2) :: RES 

      !  General multiplication like function 'A*B + C'

      ! Order 0
      RES%R = C%R + A%R*B

      ! Order 1
      RES%E1 = C%E1 + A%E1*B
      RES%E2 = C%E2 + A%E2*B

      ! Order 2
      RES%E12 = C%E12 + A%E12*B

   END FUNCTION MDNUM2_GEM_ORO

   FUNCTION MDNUM2_MATMUL_MDNUM2(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(MDNUM2), INTENT(IN) :: LHS(:,:)
      TYPE(MDNUM2), INTENT(IN) :: RHS(:,:)
      TYPE(MDNUM2) :: RES(SIZE(LHS,1),SIZE(RHS,2))

      !  Multiplication like function 'MATMUL(LHS,RHS)'
      ! Order 2
      RES%E12 = MATMUL(LHS%R,RHS%E12) + MATMUL(LHS%E12,RHS%R) +  &
             MATMUL(LHS%E1,RHS%E2) + MATMUL(LHS%E2,RHS%E1)
      ! Order 1
      RES%E1 = MATMUL(LHS%R,RHS%E1) + MATMUL(LHS%E1,RHS%R)
      RES%E2 = MATMUL(LHS%R,RHS%E2) + MATMUL(LHS%E2,RHS%R)
      ! Order 0
      RES%R = MATMUL(LHS%R,RHS%R)

   END FUNCTION MDNUM2_MATMUL_MDNUM2

   FUNCTION R_MATMUL_MDNUM2(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS(:,:)
      TYPE(MDNUM2), INTENT(IN) :: RHS(:,:)
      TYPE(MDNUM2) :: RES(SIZE(LHS,1),SIZE(RHS,2))

      ! Multiplication like function 'MATMUL(LHS,RHS)'
      !  Real
      RES%R = MATMUL(LHS,RHS%R)

      ! Order 1
      RES%E1 = MATMUL(LHS,RHS%E1)
      RES%E2 = MATMUL(LHS,RHS%E2)

      ! Order 2
      RES%E12 = MATMUL(LHS,RHS%E12)

   END FUNCTION R_MATMUL_MDNUM2

   FUNCTION MDNUM2_MATMUL_R(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(MDNUM2), INTENT(IN) :: LHS(:,:)
      REAL(DP), INTENT(IN) :: RHS(:,:)
      TYPE(MDNUM2) :: RES(SIZE(LHS,1),SIZE(RHS,2))

      ! Multiplication like function 'MATMUL(LHS,RHS)'
      !  Real
      RES%R = MATMUL(LHS%R,RHS)

      ! Order 1
      RES%E1 = MATMUL(LHS%E1,RHS)
      RES%E2 = MATMUL(LHS%E2,RHS)

      ! Order 2
      RES%E12 = MATMUL(LHS%E12,RHS)

   END FUNCTION MDNUM2_MATMUL_R

   FUNCTION MDNUM2_DOT_PRODUCT_MDNUM2(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(MDNUM2), INTENT(IN) :: LHS(:)
      TYPE(MDNUM2), INTENT(IN) :: RHS(SIZE(LHS))
      TYPE(MDNUM2) :: RES

      !  Multiplication like function 'DOT_PRODUCT(LHS,RHS)'
      ! Order 2
      RES%E12 = DOT_PRODUCT(LHS%R,RHS%E12) + DOT_PRODUCT(LHS%E12,RHS%R) +  &
             DOT_PRODUCT(LHS%E1,RHS%E2) + DOT_PRODUCT(LHS%E2,RHS%E1)
      ! Order 1
      RES%E1 = DOT_PRODUCT(LHS%R,RHS%E1) + DOT_PRODUCT(LHS%E1,RHS%R)
      RES%E2 = DOT_PRODUCT(LHS%R,RHS%E2) + DOT_PRODUCT(LHS%E2,RHS%R)
      ! Order 0
      RES%R = DOT_PRODUCT(LHS%R,RHS%R)

   END FUNCTION MDNUM2_DOT_PRODUCT_MDNUM2

   FUNCTION R_DOT_PRODUCT_MDNUM2(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS(:)
      TYPE(MDNUM2), INTENT(IN) :: RHS(SIZE(LHS))
      TYPE(MDNUM2) :: RES

      ! Multiplication like function 'DOT_PRODUCT(LHS,RHS)'
      !  Real
      RES%R = DOT_PRODUCT(LHS,RHS%R)

      ! Order 1
      RES%E1 = DOT_PRODUCT(LHS,RHS%E1)
      RES%E2 = DOT_PRODUCT(LHS,RHS%E2)

      ! Order 2
      RES%E12 = DOT_PRODUCT(LHS,RHS%E12)

   END FUNCTION R_DOT_PRODUCT_MDNUM2

   FUNCTION MDNUM2_DOT_PRODUCT_R(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(MDNUM2), INTENT(IN) :: LHS(:)
      REAL(DP), INTENT(IN) :: RHS(SIZE(LHS))
      TYPE(MDNUM2) :: RES

      ! Multiplication like function 'DOT_PRODUCT(LHS,RHS)'
      !  Real
      RES%R = DOT_PRODUCT(LHS%R,RHS)

      ! Order 1
      RES%E1 = DOT_PRODUCT(LHS%E1,RHS)
      RES%E2 = DOT_PRODUCT(LHS%E2,RHS)

      ! Order 2
      RES%E12 = DOT_PRODUCT(LHS%E12,RHS)

   END FUNCTION MDNUM2_DOT_PRODUCT_R

   FUNCTION MDNUM2_TRANSPOSE(LHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(MDNUM2), INTENT(IN) :: LHS(:,:)
      TYPE(MDNUM2) :: RES (SIZE(LHS,2),SIZE(LHS,1))

      ! Negation like function 'TRANSPOSE(LHS)'
      ! Real
      RES%R = TRANSPOSE(LHS%R)
      ! Order 1
      RES%E1 = TRANSPOSE(LHS%E1)
      RES%E2 = TRANSPOSE(LHS%E2)
      ! Order 2
      RES%E12 = TRANSPOSE(LHS%E12)

   END FUNCTION MDNUM2_TRANSPOSE

FUNCTION MDNUM2_TO_CR_MAT_S(VAL) RESULT(RES)
      IMPLICIT NONE
      TYPE(MDNUM2), INTENT(IN) :: VAL
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
      ! R x E12 -> E12 (4, 4)
      RES(1+NROWS*3:NROWS*4,1+NCOLS*3:NCOLS*4) = VAL%R
      ! E12 x R -> E12 (4, 1)
      RES(1+NROWS*3:NROWS*4,1+NCOLS*0:NCOLS*1) = VAL%E12
      ! E1 x E2 -> E12 (4, 3)
      RES(1+NROWS*3:NROWS*4,1+NCOLS*2:NCOLS*3) = VAL%E1
      ! E2 x E1 -> E12 (4, 2)
      RES(1+NROWS*3:NROWS*4,1+NCOLS*1:NCOLS*2) = VAL%E2
   END FUNCTION MDNUM2_TO_CR_MAT_S

FUNCTION MDNUM2_TO_CR_MAT_V(VAL) RESULT(RES)
      IMPLICIT NONE
      TYPE(MDNUM2), INTENT(IN) :: VAL(:)
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
      ! R x E12 -> E12 (4, 4)
      RES(1+NROWS*3:NROWS*4,4) = VAL%R
      ! E12 x R -> E12 (4, 1)
      RES(1+NROWS*3:NROWS*4,1) = VAL%E12
      ! E1 x E2 -> E12 (4, 3)
      RES(1+NROWS*3:NROWS*4,3) = VAL%E1
      ! E2 x E1 -> E12 (4, 2)
      RES(1+NROWS*3:NROWS*4,2) = VAL%E2
   END FUNCTION MDNUM2_TO_CR_MAT_V

FUNCTION MDNUM2_TO_CR_MAT_M(VAL) RESULT(RES)
      IMPLICIT NONE
      TYPE(MDNUM2), INTENT(IN) :: VAL(:,:)
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
      ! R x E12 -> E12 (4, 4)
      RES(1+NROWS*3:NROWS*4,1+NCOLS*3:NCOLS*4) = VAL%R
      ! E12 x R -> E12 (4, 1)
      RES(1+NROWS*3:NROWS*4,1+NCOLS*0:NCOLS*1) = VAL%E12
      ! E1 x E2 -> E12 (4, 3)
      RES(1+NROWS*3:NROWS*4,1+NCOLS*2:NCOLS*3) = VAL%E1
      ! E2 x E1 -> E12 (4, 2)
      RES(1+NROWS*3:NROWS*4,1+NCOLS*1:NCOLS*2) = VAL%E2
   END FUNCTION MDNUM2_TO_CR_MAT_M

      SUBROUTINE MDNUM2_SETIM_S(VAL,IDX,RES)
      IMPLICIT NONE
      TYPE(MDNUM2), INTENT(INOUT) :: VAL
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

      ! Order 2
      CASE(3)
         VAL%E12=RES

      END SELECT
   END SUBROUTINE MDNUM2_SETIM_S

      SUBROUTINE MDNUM2_SETIM_V(VAL,IDX,RES)
      IMPLICIT NONE
      TYPE(MDNUM2), INTENT(INOUT) :: VAL(:)
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

      ! Order 2
      CASE(3)
         VAL%E12=RES

      END SELECT
   END SUBROUTINE MDNUM2_SETIM_V

      SUBROUTINE MDNUM2_SETIM_M(VAL,IDX,RES)
      IMPLICIT NONE
      TYPE(MDNUM2), INTENT(INOUT) :: VAL(:,:)
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

      ! Order 2
      CASE(3)
         VAL%E12=RES

      END SELECT
   END SUBROUTINE MDNUM2_SETIM_M

FUNCTION MDNUM2_GETIM_S(VAL,IDX) RESULT(RES)
      IMPLICIT NONE
      TYPE(MDNUM2), INTENT(IN) :: VAL
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

      ! Order 2
      CASE(3)
         RES=VAL%E12

      END SELECT
   END FUNCTION MDNUM2_GETIM_S

FUNCTION MDNUM2_GETIM_V(VAL,IDX) RESULT(RES)
      IMPLICIT NONE
      TYPE(MDNUM2), INTENT(IN) :: VAL(:)
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

      ! Order 2
      CASE(3)
         RES=VAL%E12

      END SELECT
   END FUNCTION MDNUM2_GETIM_V

FUNCTION MDNUM2_GETIM_M(VAL,IDX) RESULT(RES)
      IMPLICIT NONE
      TYPE(MDNUM2), INTENT(IN) :: VAL(:,:)
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

      ! Order 2
      CASE(3)
         RES=VAL%E12

      END SELECT
   END FUNCTION MDNUM2_GETIM_M

   SUBROUTINE MDNUM2_PPRINT_S(VAR,FMT,UNIT)
      IMPLICIT NONE
      TYPE(MDNUM2), INTENT(IN) :: VAR
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

      !  Order 2
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'E12 * '
      CALL PPRINT(VAR%E12,unit=unt,fmt=output_format)


   END SUBROUTINE MDNUM2_PPRINT_S

   SUBROUTINE MDNUM2_PPRINT_V(VAR,FMT,UNIT)
      IMPLICIT NONE
      TYPE(MDNUM2), INTENT(IN) :: VAR(:)
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

      !  Order 2
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E12 * '
      CALL PPRINT(VAR%E12,unit=unt,fmt=output_format)


   END SUBROUTINE MDNUM2_PPRINT_V

   SUBROUTINE MDNUM2_PPRINT_M(VAR,FMT,UNIT)
      IMPLICIT NONE
      TYPE(MDNUM2), INTENT(IN) :: VAR(:,:)
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

      !  Order 2
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E12 * '
      CALL PPRINT(VAR%E12,unit=unt,fmt=output_format)


   END SUBROUTINE MDNUM2_PPRINT_M

   ELEMENTAL FUNCTION MDNUM2_FEVAL(X,DER0,DER1,DER2)&
      RESULT(RES)
      IMPLICIT NONE
      !  Definitions
      REAL(DP) :: FACTOR, COEF
      TYPE(MDNUM2), INTENT(IN)  :: X
      REAL(DP), INTENT(IN)  :: DER0,DER1,DER2
      TYPE(MDNUM2) :: RES
      TYPE(MDNUM2) :: DX, DX_P

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
      ! Order 2
      RES%E12 = RES%E12+COEF*DX_P%E12
      ! Order 1
      RES%E1 = RES%E1+COEF*DX_P%E1
      RES%E2 = RES%E2+COEF*DX_P%E2
      ! DX_P = DX_P * DX
      ! Order 2
      DX_P%E12 = DX_P%E1*DX%E2+DX_P%E2*DX%E1
      
      ! Sets order 2
      FACTOR = FACTOR * 2
      COEF = DER2 / FACTOR
      ! RES = RES COEF * DX_P
      ! Order 2
      RES%E12 = RES%E12+COEF*DX_P%E12
      
   END FUNCTION MDNUM2_FEVAL


  ! SUBROUTINE MDNUM2_PPRINT_M_R(X, FMT)
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

  ! END SUBROUTINE MDNUM2_PPRINT_M_R

  ! SUBROUTINE MDNUM2_PPRINT_V_R(X, FMT)
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

  ! END SUBROUTINE MDNUM2_PPRINT_V_R

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
  PURE FUNCTION MDNUM2_det2x2(A) RESULT(det)

    IMPLICIT NONE

    TYPE(MDNUM2), INTENT(IN) :: A(2,2)   !! Matrix
    TYPE(MDNUM2)             :: det

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
  PURE FUNCTION MDNUM2_det3x3(A) RESULT(det)
      
    IMPLICIT NONE

    TYPE(MDNUM2), INTENT(IN) :: A(3,3)   !! Matrix
    TYPE(MDNUM2)             :: det

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
  PURE FUNCTION MDNUM2_det4x4(A) RESULT(det)
      
    IMPLICIT NONE

    TYPE(MDNUM2), INTENT(IN) :: A(4,4)   !! Matrix
    TYPE(MDNUM2)             :: det

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
  PURE FUNCTION MDNUM2_cross3(a,b) RESULT(v)
      
    IMPLICIT NONE 

    TYPE(MDNUM2), DIMENSION (3),INTENT(IN) :: a,b
    TYPE(MDNUM2), DIMENSION (3) :: v
    
    v(1) = a(2) * b(3) - a(3) * b(2)
    v(2) = a(3) * b(1) - a(1) * b(3)
    v(3) = a(1) * b(2) - a(2) * b(1)

  END FUNCTION MDNUM2_cross3
  !===================================================================================================! 

  !***************************************************************************************************! 
  !> @brief Norm of a 3 element vector. # There is an intrinsic function named norm2.
  !!
  !! @param[in] a: Vector of 3 reals (rank 1).
  !! @param[in] b: Vector of 3 reals (rank 1).
  !!
  !***************************************************************************************************!
  FUNCTION MDNUM2_norm2_3(v) RESULT(n)
     
    IMPLICIT NONE 

    TYPE(MDNUM2), INTENT(IN) :: v(3)
    TYPE(MDNUM2) :: n
     
    n = SQRT( v(1)*v(1) + v(2)*v(2) + v(3)*v(3) )

  END FUNCTION MDNUM2_norm2_3
  !===================================================================================================! 

  FUNCTION MDNUM2_DIVISION_OO(X,Y) RESULT(RES)
      IMPLICIT NONE
      REAL(DP) :: DERIVS(TORDER + 1) 
      TYPE(MDNUM2), INTENT(IN) :: X
      TYPE(MDNUM2), INTENT(IN) :: Y
      TYPE(MDNUM2) :: RES

      RES = X*(Y**(-1.d0))

  END FUNCTION MDNUM2_DIVISION_OO

  FUNCTION MDNUM2_DIVISION_OR(X,Y) RESULT(RES)
      IMPLICIT NONE
      REAL(DP) :: DERIVS(TORDER + 1) 
      TYPE(MDNUM2), INTENT(IN) :: X
      REAL(DP), INTENT(IN) :: Y
      TYPE(MDNUM2) :: RES

      RES = X*(Y**(-1.d0))

  END FUNCTION MDNUM2_DIVISION_OR

  FUNCTION MDNUM2_DIVISION_RO(X,Y) RESULT(RES)
      IMPLICIT NONE
      REAL(DP) :: DERIVS(TORDER + 1) 
      REAL(DP), INTENT(IN) :: X
      TYPE(MDNUM2), INTENT(IN) :: Y
      TYPE(MDNUM2) :: RES

      RES = X*(Y**(-1.d0))

  END FUNCTION MDNUM2_DIVISION_RO

  ELEMENTAL FUNCTION MDNUM2_REAL(X) RESULT(RES)
      IMPLICIT NONE
      TYPE(MDNUM2), INTENT(IN) :: X
      REAL(DP) :: RES

      RES = X%R

  END FUNCTION MDNUM2_REAL

  FUNCTION MDNUM2_SQRT(X) RESULT(RES)
      IMPLICIT NONE
      TYPE(MDNUM2), INTENT(IN) :: X
      TYPE(MDNUM2) :: RES

      RES = X**0.5_DP

  END FUNCTION MDNUM2_SQRT

   ELEMENTAL FUNCTION MDNUM2_TAN(X) RESULT(RES)

      TYPE(MDNUM2), INTENT(IN) :: X
      REAL(DP) :: DER0,DER1,DER2
      TYPE(MDNUM2) :: RES
      
      DER0 = TAN(X%R)
      DER1 = TAN(X%R)**2 + 1
      DER2 = 2*(TAN(X%R)**2 + 1)*TAN(X%R)

      RES = FEVAL(X,DER0,DER1,DER2)

   END FUNCTION MDNUM2_TAN

   ELEMENTAL FUNCTION MDNUM2_COS(X) RESULT(RES)

      TYPE(MDNUM2), INTENT(IN) :: X
      REAL(DP) :: DER0,DER1,DER2
      TYPE(MDNUM2) :: RES
      
      DER0 = COS(X%R)
      DER1 = -SIN(X%R)
      DER2 = -COS(X%R)

      RES = FEVAL(X,DER0,DER1,DER2)

   END FUNCTION MDNUM2_COS

   ELEMENTAL FUNCTION MDNUM2_SIN(X) RESULT(RES)

      TYPE(MDNUM2), INTENT(IN) :: X
      REAL(DP) :: DER0,DER1,DER2
      TYPE(MDNUM2) :: RES
      
      DER0 = SIN(X%R)
      DER1 = COS(X%R)
      DER2 = -SIN(X%R)

      RES = FEVAL(X,DER0,DER1,DER2)

   END FUNCTION MDNUM2_SIN

   ELEMENTAL FUNCTION MDNUM2_ATAN(X) RESULT(RES)

      TYPE(MDNUM2), INTENT(IN) :: X
      REAL(DP) :: DER0,DER1,DER2
      TYPE(MDNUM2) :: RES
      
      DER0 = ATAN(X%R)
      DER1 = 1D0/(X%R**2 + 1)
      DER2 = -2*X%R/(X%R**2 + 1)**2

      RES = FEVAL(X,DER0,DER1,DER2)

   END FUNCTION MDNUM2_ATAN

   ELEMENTAL FUNCTION MDNUM2_ACOS(X) RESULT(RES)

      TYPE(MDNUM2), INTENT(IN) :: X
      REAL(DP) :: DER0,DER1,DER2
      TYPE(MDNUM2) :: RES
      
      DER0 = ACOS(X%R)
      DER1 = -1/SQRT(1 - X%R**2)
      DER2 = -X%R/(1 - X%R**2)**(3.0D0/2.0D0)

      RES = FEVAL(X,DER0,DER1,DER2)

   END FUNCTION MDNUM2_ACOS

   ELEMENTAL FUNCTION MDNUM2_ASIN(X) RESULT(RES)

      TYPE(MDNUM2), INTENT(IN) :: X
      REAL(DP) :: DER0,DER1,DER2
      TYPE(MDNUM2) :: RES
      
      DER0 = ASIN(X%R)
      DER1 = 1/SQRT(1 - X%R**2)
      DER2 = X%R/(1 - X%R**2)**(3.0D0/2.0D0)

      RES = FEVAL(X,DER0,DER1,DER2)

   END FUNCTION MDNUM2_ASIN

   ELEMENTAL FUNCTION MDNUM2_TANH(X) RESULT(RES)

      TYPE(MDNUM2), INTENT(IN) :: X
      REAL(DP) :: DER0,DER1,DER2
      TYPE(MDNUM2) :: RES
      
      DER0 = TANH(X%R)
      DER1 = 1 - TANH(X%R)**2
      DER2 = 2*(TANH(X%R)**2 - 1)*TANH(X%R)

      RES = FEVAL(X,DER0,DER1,DER2)

   END FUNCTION MDNUM2_TANH

   ELEMENTAL FUNCTION MDNUM2_COSH(X) RESULT(RES)

      TYPE(MDNUM2), INTENT(IN) :: X
      REAL(DP) :: DER0,DER1,DER2
      TYPE(MDNUM2) :: RES
      
      DER0 = COSH(X%R)
      DER1 = SINH(X%R)
      DER2 = COSH(X%R)

      RES = FEVAL(X,DER0,DER1,DER2)

   END FUNCTION MDNUM2_COSH

   ELEMENTAL FUNCTION MDNUM2_SINH(X) RESULT(RES)

      TYPE(MDNUM2), INTENT(IN) :: X
      REAL(DP) :: DER0,DER1,DER2
      TYPE(MDNUM2) :: RES
      
      DER0 = SINH(X%R)
      DER1 = COSH(X%R)
      DER2 = SINH(X%R)

      RES = FEVAL(X,DER0,DER1,DER2)

   END FUNCTION MDNUM2_SINH

   ELEMENTAL FUNCTION MDNUM2_EXP(X) RESULT(RES)

      TYPE(MDNUM2), INTENT(IN) :: X
      REAL(DP) :: DER0,DER1,DER2
      TYPE(MDNUM2) :: RES
      
      DER0 = EXP(X%R)
      DER1 = EXP(X%R)
      DER2 = EXP(X%R)

      RES = FEVAL(X,DER0,DER1,DER2)

   END FUNCTION MDNUM2_EXP

   ELEMENTAL FUNCTION MDNUM2_LOG(X) RESULT(RES)

      TYPE(MDNUM2), INTENT(IN) :: X
      REAL(DP) :: DER0,DER1,DER2
      TYPE(MDNUM2) :: RES
      
      DER0 = LOG(X%R)
      DER1 = 1D0/X%R
      DER2 = -1/X%R**2

      RES = FEVAL(X,DER0,DER1,DER2)

   END FUNCTION MDNUM2_LOG

   ELEMENTAL FUNCTION MDNUM2_POW_OR(X,E) RESULT(RES)

      TYPE(MDNUM2), INTENT(IN) :: X
      REAL(DP), INTENT(IN) :: E
      REAL(DP) :: DER0,DER1,DER2
      TYPE(MDNUM2) :: RES
      
      DER0=0.0d0
      DER1=0.0d0
      DER2=0.0d0
      
      DER0 = X%R**E
      IF ((E-0)/=0.0d0) THEN
         DER1 = E*X%R**(E - 1)
         IF ((E-1)/=0.0d0) THEN
            DER2 = E*X%R**(E - 2)*(E - 1)
         END IF
      END IF

      RES = FEVAL(X,DER0,DER1,DER2)

   END FUNCTION MDNUM2_POW_OR

   ELEMENTAL FUNCTION MDNUM2_POW_RO(E,X) RESULT(RES)

      TYPE(MDNUM2), INTENT(IN) :: X
      REAL(DP), INTENT(IN) :: E
      REAL(DP) :: DER0,DER1,DER2
      TYPE(MDNUM2) :: RES
      
      
      DER0 = E**X%R
      DER1 = E**X%R*LOG(E)
      DER2 = E**X%R*LOG(E)**2

      RES = FEVAL(X,DER0,DER1,DER2)

   END FUNCTION MDNUM2_POW_RO

   ELEMENTAL FUNCTION MDNUM2_F2EVAL(X,Y,DER0_0,DER1_0,DER1_1, &
                                DER2_0,DER2_1,DER2_2)&
      RESULT(RES)
      IMPLICIT NONE
      !  Definitions
      REAL(DP) :: COEF, DELTA
      TYPE(MDNUM2), INTENT(IN)  :: X,Y
      REAL(DP), INTENT(IN)  :: DER0_0,DER1_0,DER1_1, &
                               DER2_0,DER2_1,DER2_2
      TYPE(MDNUM2) :: RES
      TYPE(MDNUM2) :: DX, DY

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

      

   END FUNCTION MDNUM2_F2EVAL


   ELEMENTAL FUNCTION MDNUM2_POW_OO(X,Y) RESULT(RES)

      TYPE(MDNUM2), INTENT(IN) :: X, Y
      REAL(DP) :: DER0_0,DER1_0,DER1_1,DER2_0,DER2_1,DER2_2
      TYPE(MDNUM2) :: RES
      
      DER0_0 = X%R**Y%R
      DER1_0 = X%R**Y%R*Y%R/X%R
      DER1_1 = X%R**Y%R*LOG(X%R)
      DER2_0 = X%R**Y%R*Y%R*(Y%R - 1)/X%R**2
      DER2_1 = X%R**Y%R*(Y%R*LOG(X%R) + 1)/X%R
      DER2_2 = X%R**Y%R*LOG(X%R)**2

      RES = F2EVAL(X,Y,DER0_0,DER1_0,DER1_1,DER2_0,DER2_1,DER2_2)

   END FUNCTION MDNUM2_POW_OO


   FUNCTION MDNUM2_INV2X2(A,det)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(MDNUM2) , INTENT(IN) :: A(2,2) 
      TYPE(MDNUM2) , INTENT(IN), OPTIONAL :: det
      REAL(DP) :: detCalc
      TYPE(MDNUM2) :: RES(SIZE(A,1),SIZE(A,2)) 

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

      ! Order 2
      RES%E12=-MATMUL(RES%R,(MATMUL(A%E12,RES%R)+MATMUL(A%E1,RES%E2)+&
             MATMUL(A%E2,RES%E1)))

   END FUNCTION MDNUM2_INV2X2

   FUNCTION MDNUM2_INV3X3(A,det)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(MDNUM2) , INTENT(IN) :: A(3,3) 
      TYPE(MDNUM2) , INTENT(IN), OPTIONAL :: det
      REAL(DP) :: detCalc
      TYPE(MDNUM2) :: RES(SIZE(A,1),SIZE(A,2)) 

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

      ! Order 2
      RES%E12=-MATMUL(RES%R,(MATMUL(A%E12,RES%R)+MATMUL(A%E1,RES%E2)+&
             MATMUL(A%E2,RES%E1)))

   END FUNCTION MDNUM2_INV3X3

   FUNCTION MDNUM2_INV4X4(A,det)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(MDNUM2) , INTENT(IN) :: A(4,4) 
      TYPE(MDNUM2) , INTENT(IN), OPTIONAL :: det
      REAL(DP) :: detCalc
      TYPE(MDNUM2) :: RES(SIZE(A,1),SIZE(A,2)) 

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

      ! Order 2
      RES%E12=-MATMUL(RES%R,(MATMUL(A%E12,RES%R)+MATMUL(A%E1,RES%E2)+&
             MATMUL(A%E2,RES%E1)))

   END FUNCTION MDNUM2_INV4X4

END MODULE MDUAL2
