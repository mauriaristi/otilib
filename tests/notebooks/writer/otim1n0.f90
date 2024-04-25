MODULE OTIM1N0

   USE master_parameters
   USE real_utils

   IMPLICIT NONE

   INTEGER, PARAMETER :: NUM_IM_DIR = 1
   INTEGER, PARAMETER :: TORDER     = 0
   INTEGER, PARAMETER :: N_IMDIR_ORDER(1) = [1]

   TYPE ONUMM1N0
     ! Real
     REAL(DP) :: R
   END TYPE ONUMM1N0

   ! Constant imaginary directions.


   INTERFACE OPERATOR(*)
      MODULE PROCEDURE ONUMM1N0_MUL_OO_SS,ONUMM1N0_MUL_RO_SS,ONUMM1N0_MUL_OR_SS,ONUMM1N0_MUL_OO_VS,&
                       ONUMM1N0_MUL_RO_VS,ONUMM1N0_MUL_OR_VS,ONUMM1N0_MUL_OO_MS,ONUMM1N0_MUL_RO_MS,&
                       ONUMM1N0_MUL_OR_MS,ONUMM1N0_MUL_OO_SV,ONUMM1N0_MUL_RO_SV,ONUMM1N0_MUL_OR_SV,&
                       ONUMM1N0_MUL_OO_SM,ONUMM1N0_MUL_RO_SM,ONUMM1N0_MUL_OR_SM
   END INTERFACE

   INTERFACE OPERATOR(+)
      MODULE PROCEDURE ONUMM1N0_ADD_OO_SS,ONUMM1N0_ADD_RO_SS,ONUMM1N0_ADD_OR_SS,ONUMM1N0_ADD_OO_VS,&
                       ONUMM1N0_ADD_RO_VS,ONUMM1N0_ADD_OR_VS,ONUMM1N0_ADD_OO_MS,ONUMM1N0_ADD_RO_MS,&
                       ONUMM1N0_ADD_OR_MS,ONUMM1N0_ADD_OO_SV,ONUMM1N0_ADD_RO_SV,ONUMM1N0_ADD_OR_SV,&
                       ONUMM1N0_ADD_OO_SM,ONUMM1N0_ADD_RO_SM,ONUMM1N0_ADD_OR_SM
   END INTERFACE

   INTERFACE OPERATOR(-)
      MODULE PROCEDURE ONUMM1N0_NEG,ONUMM1N0_SUB_OO_SS,ONUMM1N0_SUB_RO_SS,ONUMM1N0_SUB_OR_SS,&
                       ONUMM1N0_SUB_OO_VS,ONUMM1N0_SUB_RO_VS,ONUMM1N0_SUB_OR_VS,ONUMM1N0_SUB_OO_MS,&
                       ONUMM1N0_SUB_RO_MS,ONUMM1N0_SUB_OR_MS,ONUMM1N0_SUB_OO_SV,ONUMM1N0_SUB_RO_SV,&
                       ONUMM1N0_SUB_OR_SV,ONUMM1N0_SUB_OO_SM,ONUMM1N0_SUB_RO_SM,ONUMM1N0_SUB_OR_SM
   END INTERFACE

   INTERFACE OPERATOR(/)
      MODULE PROCEDURE ONUMM1N0_DIVISION_OO,ONUMM1N0_DIVISION_OR,ONUMM1N0_DIVISION_RO
   END INTERFACE

   INTERFACE ASSIGNMENT(=)
      MODULE PROCEDURE ONUMM1N0_ASSIGN_R
   END INTERFACE

   INTERFACE OPERATOR(**)
      MODULE PROCEDURE ONUMM1N0_POW_OR,ONUMM1N0_POW_RO,ONUMM1N0_POW_OO
   END INTERFACE

   INTERFACE PPRINT
      MODULE PROCEDURE ONUMM1N0_PPRINT_S,ONUMM1N0_PPRINT_V,ONUMM1N0_PPRINT_M
   END INTERFACE

   INTERFACE TRANSPOSE
      MODULE PROCEDURE ONUMM1N0_TRANSPOSE
   END INTERFACE

   INTERFACE MATMUL
      MODULE PROCEDURE ONUMM1N0_MATMUL_ONUMM1N0,R_MATMUL_ONUMM1N0,ONUMM1N0_MATMUL_R
   END INTERFACE

   INTERFACE DOT_PRODUCT
      MODULE PROCEDURE ONUMM1N0_DOT_PRODUCT_ONUMM1N0,R_DOT_PRODUCT_ONUMM1N0,ONUMM1N0_DOT_PRODUCT_R
   END INTERFACE

   INTERFACE UNFOLD
      MODULE PROCEDURE ONUMM1N0_TO_CR_MAT_S,ONUMM1N0_TO_CR_MAT_V,ONUMM1N0_TO_CR_MAT_M
   END INTERFACE

   INTERFACE TO_CR
      MODULE PROCEDURE ONUMM1N0_TO_CR_MAT_S,ONUMM1N0_TO_CR_MAT_V,ONUMM1N0_TO_CR_MAT_M
   END INTERFACE

   INTERFACE SIN
      MODULE PROCEDURE ONUMM1N0_SIN
   END INTERFACE

   INTERFACE COS
      MODULE PROCEDURE ONUMM1N0_COS
   END INTERFACE

   INTERFACE TAN
      MODULE PROCEDURE ONUMM1N0_TAN
   END INTERFACE

   INTERFACE ASIN
      MODULE PROCEDURE ONUMM1N0_ASIN
   END INTERFACE

   INTERFACE ACOS
      MODULE PROCEDURE ONUMM1N0_ACOS
   END INTERFACE

   INTERFACE ATAN
      MODULE PROCEDURE ONUMM1N0_ATAN
   END INTERFACE

   INTERFACE SINH
      MODULE PROCEDURE ONUMM1N0_SINH
   END INTERFACE

   INTERFACE COSH
      MODULE PROCEDURE ONUMM1N0_COSH
   END INTERFACE

   INTERFACE TANH
      MODULE PROCEDURE ONUMM1N0_TANH
   END INTERFACE

   INTERFACE SQRT
      MODULE PROCEDURE ONUMM1N0_SQRT
   END INTERFACE

   INTERFACE LOG
      MODULE PROCEDURE ONUMM1N0_LOG
   END INTERFACE

   INTERFACE EXP
      MODULE PROCEDURE ONUMM1N0_EXP
   END INTERFACE

   INTERFACE GEM
      MODULE PROCEDURE ONUMM1N0_GEM_OOO,ONUMM1N0_GEM_ROO,ONUMM1N0_GEM_ORO
   END INTERFACE

   INTERFACE FEVAL
      MODULE PROCEDURE ONUMM1N0_FEVAL
   END INTERFACE

   INTERFACE F2EVAL
      MODULE PROCEDURE ONUMM1N0_F2EVAL
   END INTERFACE

   INTERFACE REAL
      MODULE PROCEDURE ONUMM1N0_REAL
   END INTERFACE

   INTERFACE DET2X2
      MODULE PROCEDURE ONUMM1N0_det2x2
   END INTERFACE

   INTERFACE DET3X3
      MODULE PROCEDURE ONUMM1N0_det3x3
   END INTERFACE

   INTERFACE DET4X4
      MODULE PROCEDURE ONUMM1N0_det4x4
   END INTERFACE

   INTERFACE INV2X2
      MODULE PROCEDURE ONUMM1N0_INV2X2
   END INTERFACE

   INTERFACE INV3X3
      MODULE PROCEDURE ONUMM1N0_INV3X3
   END INTERFACE

   INTERFACE INV4X4
      MODULE PROCEDURE ONUMM1N0_INV4X4
   END INTERFACE

   INTERFACE GETIM
      MODULE PROCEDURE ONUMM1N0_GETIM_S,ONUMM1N0_GETIM_V,ONUMM1N0_GETIM_M
   END INTERFACE

   INTERFACE SETIM
      MODULE PROCEDURE ONUMM1N0_SETIM_S,ONUMM1N0_SETIM_V,ONUMM1N0_SETIM_M
   END INTERFACE

   CONTAINS

   ELEMENTAL SUBROUTINE ONUMM1N0_ASSIGN_R(RES,LHS)
      
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS 
      TYPE(ONUMM1N0), INTENT(OUT) :: RES 

      ! Assign like function 'LHS'
      ! Real
      RES%R = LHS

   END SUBROUTINE ONUMM1N0_ASSIGN_R

   ELEMENTAL FUNCTION ONUMM1N0_NEG(LHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM1N0), INTENT(IN) :: LHS 
      TYPE(ONUMM1N0) :: RES 

      ! Negation like function '-LHS'
      ! Real
      RES%R = -LHS%R

   END FUNCTION ONUMM1N0_NEG

   ELEMENTAL FUNCTION ONUMM1N0_ADD_OO_SS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM1N0), INTENT(IN) :: LHS
      TYPE(ONUMM1N0), INTENT(IN) :: RHS
      TYPE(ONUMM1N0) :: RES 

      ! Addition like function 'LHS + RHS'
      !  Real
      RES%R = LHS%R + RHS%R

   END FUNCTION ONUMM1N0_ADD_OO_SS

   ELEMENTAL FUNCTION ONUMM1N0_ADD_RO_SS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS
      TYPE(ONUMM1N0), INTENT(IN) :: RHS
      TYPE(ONUMM1N0) :: RES 

      ! Addition like function 'LHS + RHS'
      ! Real
      RES%R = LHS + RHS%R

   END FUNCTION ONUMM1N0_ADD_RO_SS

   ELEMENTAL FUNCTION ONUMM1N0_ADD_OR_SS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM1N0), INTENT(IN) :: LHS
      REAL(DP), INTENT(IN) :: RHS
      TYPE(ONUMM1N0) :: RES 

      ! Addition like function 'LHS + RHS'
      ! Real
      RES%R = LHS%R + RHS

   END FUNCTION ONUMM1N0_ADD_OR_SS

   ELEMENTAL FUNCTION ONUMM1N0_SUB_OO_SS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM1N0), INTENT(IN) :: LHS
      TYPE(ONUMM1N0), INTENT(IN) :: RHS
      TYPE(ONUMM1N0) :: RES 

      ! Addition like function 'LHS - RHS'
      !  Real
      RES%R = LHS%R - RHS%R

   END FUNCTION ONUMM1N0_SUB_OO_SS

   ELEMENTAL FUNCTION ONUMM1N0_SUB_RO_SS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS
      TYPE(ONUMM1N0), INTENT(IN) :: RHS
      TYPE(ONUMM1N0) :: RES 

      ! Addition like function 'LHS - RHS'
      ! Real
      RES%R = LHS - RHS%R

   END FUNCTION ONUMM1N0_SUB_RO_SS

   ELEMENTAL FUNCTION ONUMM1N0_SUB_OR_SS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM1N0), INTENT(IN) :: LHS
      REAL(DP), INTENT(IN) :: RHS
      TYPE(ONUMM1N0) :: RES 

      ! Addition like function 'LHS - RHS'
      ! Real
      RES%R = LHS%R - RHS

   END FUNCTION ONUMM1N0_SUB_OR_SS

   ELEMENTAL FUNCTION ONUMM1N0_MUL_OO_SS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM1N0), INTENT(IN) :: LHS
      TYPE(ONUMM1N0), INTENT(IN) :: RHS
      TYPE(ONUMM1N0) :: RES 

      !  Multiplication like function 'LHS*RHS'
      ! Order 0
      RES%R = LHS%R*RHS%R

   END FUNCTION ONUMM1N0_MUL_OO_SS

   ELEMENTAL FUNCTION ONUMM1N0_MUL_RO_SS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS
      TYPE(ONUMM1N0), INTENT(IN) :: RHS
      TYPE(ONUMM1N0) :: RES 

      ! Multiplication like function 'LHS*RHS'
      !  Real
      RES%R = LHS*RHS%R

   END FUNCTION ONUMM1N0_MUL_RO_SS

   ELEMENTAL FUNCTION ONUMM1N0_MUL_OR_SS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM1N0), INTENT(IN) :: LHS
      REAL(DP), INTENT(IN) :: RHS
      TYPE(ONUMM1N0) :: RES 

      ! Multiplication like function 'LHS*RHS'
      !  Real
      RES%R = LHS%R*RHS

   END FUNCTION ONUMM1N0_MUL_OR_SS

   FUNCTION ONUMM1N0_ADD_OO_VS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM1N0), INTENT(IN) :: LHS(:)
      TYPE(ONUMM1N0), INTENT(IN) :: RHS
      TYPE(ONUMM1N0) :: RES(SIZE(LHS,1)) 

      ! Addition like function 'LHS + RHS'
      !  Real
      RES%R = LHS%R + RHS%R

   END FUNCTION ONUMM1N0_ADD_OO_VS

   FUNCTION ONUMM1N0_ADD_RO_VS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS(:)
      TYPE(ONUMM1N0), INTENT(IN) :: RHS
      TYPE(ONUMM1N0) :: RES(SIZE(LHS,1)) 

      ! Addition like function 'LHS + RHS'
      ! Real
      RES%R = LHS + RHS%R

   END FUNCTION ONUMM1N0_ADD_RO_VS

   FUNCTION ONUMM1N0_ADD_OR_VS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM1N0), INTENT(IN) :: LHS(:)
      REAL(DP), INTENT(IN) :: RHS
      TYPE(ONUMM1N0) :: RES(SIZE(LHS,1)) 

      ! Addition like function 'LHS + RHS'
      ! Real
      RES%R = LHS%R + RHS

   END FUNCTION ONUMM1N0_ADD_OR_VS

   FUNCTION ONUMM1N0_SUB_OO_VS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM1N0), INTENT(IN) :: LHS(:)
      TYPE(ONUMM1N0), INTENT(IN) :: RHS
      TYPE(ONUMM1N0) :: RES(SIZE(LHS,1)) 

      ! Addition like function 'LHS - RHS'
      !  Real
      RES%R = LHS%R - RHS%R

   END FUNCTION ONUMM1N0_SUB_OO_VS

   FUNCTION ONUMM1N0_SUB_RO_VS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS(:)
      TYPE(ONUMM1N0), INTENT(IN) :: RHS
      TYPE(ONUMM1N0) :: RES(SIZE(LHS,1)) 

      ! Addition like function 'LHS - RHS'
      ! Real
      RES%R = LHS - RHS%R

   END FUNCTION ONUMM1N0_SUB_RO_VS

   FUNCTION ONUMM1N0_SUB_OR_VS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM1N0), INTENT(IN) :: LHS(:)
      REAL(DP), INTENT(IN) :: RHS
      TYPE(ONUMM1N0) :: RES(SIZE(LHS,1)) 

      ! Addition like function 'LHS - RHS'
      ! Real
      RES%R = LHS%R - RHS

   END FUNCTION ONUMM1N0_SUB_OR_VS

   FUNCTION ONUMM1N0_MUL_OO_VS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM1N0), INTENT(IN) :: LHS(:)
      TYPE(ONUMM1N0), INTENT(IN) :: RHS
      TYPE(ONUMM1N0) :: RES(SIZE(LHS,1)) 

      !  Multiplication like function 'LHS*RHS'
      ! Order 0
      RES%R = LHS%R*RHS%R

   END FUNCTION ONUMM1N0_MUL_OO_VS

   FUNCTION ONUMM1N0_MUL_RO_VS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS(:)
      TYPE(ONUMM1N0), INTENT(IN) :: RHS
      TYPE(ONUMM1N0) :: RES(SIZE(LHS,1)) 

      ! Multiplication like function 'LHS*RHS'
      !  Real
      RES%R = LHS*RHS%R

   END FUNCTION ONUMM1N0_MUL_RO_VS

   FUNCTION ONUMM1N0_MUL_OR_VS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM1N0), INTENT(IN) :: LHS(:)
      REAL(DP), INTENT(IN) :: RHS
      TYPE(ONUMM1N0) :: RES(SIZE(LHS,1)) 

      ! Multiplication like function 'LHS*RHS'
      !  Real
      RES%R = LHS%R*RHS

   END FUNCTION ONUMM1N0_MUL_OR_VS

   FUNCTION ONUMM1N0_ADD_OO_MS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM1N0), INTENT(IN) :: LHS(:,:)
      TYPE(ONUMM1N0), INTENT(IN) :: RHS
      TYPE(ONUMM1N0) :: RES(SIZE(LHS,1),SIZE(LHS,2)) 

      ! Addition like function 'LHS + RHS'
      !  Real
      RES%R = LHS%R + RHS%R

   END FUNCTION ONUMM1N0_ADD_OO_MS

   FUNCTION ONUMM1N0_ADD_RO_MS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS(:,:)
      TYPE(ONUMM1N0), INTENT(IN) :: RHS
      TYPE(ONUMM1N0) :: RES(SIZE(LHS,1),SIZE(LHS,2)) 

      ! Addition like function 'LHS + RHS'
      ! Real
      RES%R = LHS + RHS%R

   END FUNCTION ONUMM1N0_ADD_RO_MS

   FUNCTION ONUMM1N0_ADD_OR_MS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM1N0), INTENT(IN) :: LHS(:,:)
      REAL(DP), INTENT(IN) :: RHS
      TYPE(ONUMM1N0) :: RES(SIZE(LHS,1),SIZE(LHS,2)) 

      ! Addition like function 'LHS + RHS'
      ! Real
      RES%R = LHS%R + RHS

   END FUNCTION ONUMM1N0_ADD_OR_MS

   FUNCTION ONUMM1N0_SUB_OO_MS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM1N0), INTENT(IN) :: LHS(:,:)
      TYPE(ONUMM1N0), INTENT(IN) :: RHS
      TYPE(ONUMM1N0) :: RES(SIZE(LHS,1),SIZE(LHS,2)) 

      ! Addition like function 'LHS - RHS'
      !  Real
      RES%R = LHS%R - RHS%R

   END FUNCTION ONUMM1N0_SUB_OO_MS

   FUNCTION ONUMM1N0_SUB_RO_MS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS(:,:)
      TYPE(ONUMM1N0), INTENT(IN) :: RHS
      TYPE(ONUMM1N0) :: RES(SIZE(LHS,1),SIZE(LHS,2)) 

      ! Addition like function 'LHS - RHS'
      ! Real
      RES%R = LHS - RHS%R

   END FUNCTION ONUMM1N0_SUB_RO_MS

   FUNCTION ONUMM1N0_SUB_OR_MS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM1N0), INTENT(IN) :: LHS(:,:)
      REAL(DP), INTENT(IN) :: RHS
      TYPE(ONUMM1N0) :: RES(SIZE(LHS,1),SIZE(LHS,2)) 

      ! Addition like function 'LHS - RHS'
      ! Real
      RES%R = LHS%R - RHS

   END FUNCTION ONUMM1N0_SUB_OR_MS

   FUNCTION ONUMM1N0_MUL_OO_MS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM1N0), INTENT(IN) :: LHS(:,:)
      TYPE(ONUMM1N0), INTENT(IN) :: RHS
      TYPE(ONUMM1N0) :: RES(SIZE(LHS,1),SIZE(LHS,2)) 

      !  Multiplication like function 'LHS*RHS'
      ! Order 0
      RES%R = LHS%R*RHS%R

   END FUNCTION ONUMM1N0_MUL_OO_MS

   FUNCTION ONUMM1N0_MUL_RO_MS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS(:,:)
      TYPE(ONUMM1N0), INTENT(IN) :: RHS
      TYPE(ONUMM1N0) :: RES(SIZE(LHS,1),SIZE(LHS,2)) 

      ! Multiplication like function 'LHS*RHS'
      !  Real
      RES%R = LHS*RHS%R

   END FUNCTION ONUMM1N0_MUL_RO_MS

   FUNCTION ONUMM1N0_MUL_OR_MS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM1N0), INTENT(IN) :: LHS(:,:)
      REAL(DP), INTENT(IN) :: RHS
      TYPE(ONUMM1N0) :: RES(SIZE(LHS,1),SIZE(LHS,2)) 

      ! Multiplication like function 'LHS*RHS'
      !  Real
      RES%R = LHS%R*RHS

   END FUNCTION ONUMM1N0_MUL_OR_MS

   FUNCTION ONUMM1N0_ADD_OO_SV(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM1N0), INTENT(IN) :: LHS
      TYPE(ONUMM1N0), INTENT(IN) :: RHS(:)
      TYPE(ONUMM1N0) :: RES(SIZE(RHS,1)) 

      ! Addition like function 'LHS + RHS'
      !  Real
      RES%R = LHS%R + RHS%R

   END FUNCTION ONUMM1N0_ADD_OO_SV

   FUNCTION ONUMM1N0_ADD_RO_SV(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS
      TYPE(ONUMM1N0), INTENT(IN) :: RHS(:)
      TYPE(ONUMM1N0) :: RES(SIZE(RHS,1)) 

      ! Addition like function 'LHS + RHS'
      ! Real
      RES%R = LHS + RHS%R

   END FUNCTION ONUMM1N0_ADD_RO_SV

   FUNCTION ONUMM1N0_ADD_OR_SV(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM1N0), INTENT(IN) :: LHS
      REAL(DP), INTENT(IN) :: RHS(:)
      TYPE(ONUMM1N0) :: RES(SIZE(RHS,1)) 

      ! Addition like function 'LHS + RHS'
      ! Real
      RES%R = LHS%R + RHS

   END FUNCTION ONUMM1N0_ADD_OR_SV

   FUNCTION ONUMM1N0_SUB_OO_SV(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM1N0), INTENT(IN) :: LHS
      TYPE(ONUMM1N0), INTENT(IN) :: RHS(:)
      TYPE(ONUMM1N0) :: RES(SIZE(RHS,1)) 

      ! Addition like function 'LHS - RHS'
      !  Real
      RES%R = LHS%R - RHS%R

   END FUNCTION ONUMM1N0_SUB_OO_SV

   FUNCTION ONUMM1N0_SUB_RO_SV(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS
      TYPE(ONUMM1N0), INTENT(IN) :: RHS(:)
      TYPE(ONUMM1N0) :: RES(SIZE(RHS,1)) 

      ! Addition like function 'LHS - RHS'
      ! Real
      RES%R = LHS - RHS%R

   END FUNCTION ONUMM1N0_SUB_RO_SV

   FUNCTION ONUMM1N0_SUB_OR_SV(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM1N0), INTENT(IN) :: LHS
      REAL(DP), INTENT(IN) :: RHS(:)
      TYPE(ONUMM1N0) :: RES(SIZE(RHS,1)) 

      ! Addition like function 'LHS - RHS'
      ! Real
      RES%R = LHS%R - RHS

   END FUNCTION ONUMM1N0_SUB_OR_SV

   FUNCTION ONUMM1N0_MUL_OO_SV(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM1N0), INTENT(IN) :: LHS
      TYPE(ONUMM1N0), INTENT(IN) :: RHS(:)
      TYPE(ONUMM1N0) :: RES(SIZE(RHS,1)) 

      !  Multiplication like function 'LHS*RHS'
      ! Order 0
      RES%R = LHS%R*RHS%R

   END FUNCTION ONUMM1N0_MUL_OO_SV

   FUNCTION ONUMM1N0_MUL_RO_SV(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS
      TYPE(ONUMM1N0), INTENT(IN) :: RHS(:)
      TYPE(ONUMM1N0) :: RES(SIZE(RHS,1)) 

      ! Multiplication like function 'LHS*RHS'
      !  Real
      RES%R = LHS*RHS%R

   END FUNCTION ONUMM1N0_MUL_RO_SV

   FUNCTION ONUMM1N0_MUL_OR_SV(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM1N0), INTENT(IN) :: LHS
      REAL(DP), INTENT(IN) :: RHS(:)
      TYPE(ONUMM1N0) :: RES(SIZE(RHS,1)) 

      ! Multiplication like function 'LHS*RHS'
      !  Real
      RES%R = LHS%R*RHS

   END FUNCTION ONUMM1N0_MUL_OR_SV

   FUNCTION ONUMM1N0_ADD_OO_SM(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM1N0), INTENT(IN) :: LHS
      TYPE(ONUMM1N0), INTENT(IN) :: RHS(:,:)
      TYPE(ONUMM1N0) :: RES(SIZE(RHS,1),SIZE(RHS,2)) 

      ! Addition like function 'LHS + RHS'
      !  Real
      RES%R = LHS%R + RHS%R

   END FUNCTION ONUMM1N0_ADD_OO_SM

   FUNCTION ONUMM1N0_ADD_RO_SM(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS
      TYPE(ONUMM1N0), INTENT(IN) :: RHS(:,:)
      TYPE(ONUMM1N0) :: RES(SIZE(RHS,1),SIZE(RHS,2)) 

      ! Addition like function 'LHS + RHS'
      ! Real
      RES%R = LHS + RHS%R

   END FUNCTION ONUMM1N0_ADD_RO_SM

   FUNCTION ONUMM1N0_ADD_OR_SM(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM1N0), INTENT(IN) :: LHS
      REAL(DP), INTENT(IN) :: RHS(:,:)
      TYPE(ONUMM1N0) :: RES(SIZE(RHS,1),SIZE(RHS,2)) 

      ! Addition like function 'LHS + RHS'
      ! Real
      RES%R = LHS%R + RHS

   END FUNCTION ONUMM1N0_ADD_OR_SM

   FUNCTION ONUMM1N0_SUB_OO_SM(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM1N0), INTENT(IN) :: LHS
      TYPE(ONUMM1N0), INTENT(IN) :: RHS(:,:)
      TYPE(ONUMM1N0) :: RES(SIZE(RHS,1),SIZE(RHS,2)) 

      ! Addition like function 'LHS - RHS'
      !  Real
      RES%R = LHS%R - RHS%R

   END FUNCTION ONUMM1N0_SUB_OO_SM

   FUNCTION ONUMM1N0_SUB_RO_SM(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS
      TYPE(ONUMM1N0), INTENT(IN) :: RHS(:,:)
      TYPE(ONUMM1N0) :: RES(SIZE(RHS,1),SIZE(RHS,2)) 

      ! Addition like function 'LHS - RHS'
      ! Real
      RES%R = LHS - RHS%R

   END FUNCTION ONUMM1N0_SUB_RO_SM

   FUNCTION ONUMM1N0_SUB_OR_SM(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM1N0), INTENT(IN) :: LHS
      REAL(DP), INTENT(IN) :: RHS(:,:)
      TYPE(ONUMM1N0) :: RES(SIZE(RHS,1),SIZE(RHS,2)) 

      ! Addition like function 'LHS - RHS'
      ! Real
      RES%R = LHS%R - RHS

   END FUNCTION ONUMM1N0_SUB_OR_SM

   FUNCTION ONUMM1N0_MUL_OO_SM(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM1N0), INTENT(IN) :: LHS
      TYPE(ONUMM1N0), INTENT(IN) :: RHS(:,:)
      TYPE(ONUMM1N0) :: RES(SIZE(RHS,1),SIZE(RHS,2)) 

      !  Multiplication like function 'LHS*RHS'
      ! Order 0
      RES%R = LHS%R*RHS%R

   END FUNCTION ONUMM1N0_MUL_OO_SM

   FUNCTION ONUMM1N0_MUL_RO_SM(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS
      TYPE(ONUMM1N0), INTENT(IN) :: RHS(:,:)
      TYPE(ONUMM1N0) :: RES(SIZE(RHS,1),SIZE(RHS,2)) 

      ! Multiplication like function 'LHS*RHS'
      !  Real
      RES%R = LHS*RHS%R

   END FUNCTION ONUMM1N0_MUL_RO_SM

   FUNCTION ONUMM1N0_MUL_OR_SM(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM1N0), INTENT(IN) :: LHS
      REAL(DP), INTENT(IN) :: RHS(:,:)
      TYPE(ONUMM1N0) :: RES(SIZE(RHS,1),SIZE(RHS,2)) 

      ! Multiplication like function 'LHS*RHS'
      !  Real
      RES%R = LHS%R*RHS

   END FUNCTION ONUMM1N0_MUL_OR_SM

ELEMENTAL    FUNCTION ONUMM1N0_GEM_OOO(A,B,C)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM1N0), INTENT(IN) :: A 
      TYPE(ONUMM1N0), INTENT(IN) :: B 
      TYPE(ONUMM1N0), INTENT(IN) :: C 
      TYPE(ONUMM1N0) :: RES 

      !  General multiplication like function 'A*B + C'

      ! Order 0
      RES%R = C%R + A%R*B%R

   END FUNCTION ONUMM1N0_GEM_OOO

ELEMENTAL    FUNCTION ONUMM1N0_GEM_ROO(A,B,C)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: A 
      TYPE(ONUMM1N0), INTENT(IN) :: B 
      TYPE(ONUMM1N0), INTENT(IN) :: C 
      TYPE(ONUMM1N0) :: RES 

      !  General multiplication like function 'A*B + C'
      ! Order 0
      RES%R = C%R + A*B%R

   END FUNCTION ONUMM1N0_GEM_ROO

ELEMENTAL    FUNCTION ONUMM1N0_GEM_ORO(A,B,C)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM1N0), INTENT(IN) :: A 
      REAL(DP), INTENT(IN) :: B 
      TYPE(ONUMM1N0), INTENT(IN) :: C 
      TYPE(ONUMM1N0) :: RES 

      !  General multiplication like function 'A*B + C'

      ! Order 0
      RES%R = C%R + A%R*B

   END FUNCTION ONUMM1N0_GEM_ORO

   FUNCTION ONUMM1N0_MATMUL_ONUMM1N0(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM1N0), INTENT(IN) :: LHS(:,:)
      TYPE(ONUMM1N0), INTENT(IN) :: RHS(:,:)
      TYPE(ONUMM1N0) :: RES(SIZE(LHS,1),SIZE(RHS,2))

      !  Multiplication like function 'MATMUL(LHS,RHS)'
      ! Order 0
      RES%R = MATMUL(LHS%R,RHS%R)

   END FUNCTION ONUMM1N0_MATMUL_ONUMM1N0

   FUNCTION R_MATMUL_ONUMM1N0(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS(:,:)
      TYPE(ONUMM1N0), INTENT(IN) :: RHS(:,:)
      TYPE(ONUMM1N0) :: RES(SIZE(LHS,1),SIZE(RHS,2))

      ! Multiplication like function 'MATMUL(LHS,RHS)'
      !  Real
      RES%R = MATMUL(LHS,RHS%R)

   END FUNCTION R_MATMUL_ONUMM1N0

   FUNCTION ONUMM1N0_MATMUL_R(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM1N0), INTENT(IN) :: LHS(:,:)
      REAL(DP), INTENT(IN) :: RHS(:,:)
      TYPE(ONUMM1N0) :: RES(SIZE(LHS,1),SIZE(RHS,2))

      ! Multiplication like function 'MATMUL(LHS,RHS)'
      !  Real
      RES%R = MATMUL(LHS%R,RHS)

   END FUNCTION ONUMM1N0_MATMUL_R

   FUNCTION ONUMM1N0_DOT_PRODUCT_ONUMM1N0(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM1N0), INTENT(IN) :: LHS(:)
      TYPE(ONUMM1N0), INTENT(IN) :: RHS(SIZE(LHS))
      TYPE(ONUMM1N0) :: RES

      !  Multiplication like function 'DOT_PRODUCT(LHS,RHS)'
      ! Order 0
      RES%R = DOT_PRODUCT(LHS%R,RHS%R)

   END FUNCTION ONUMM1N0_DOT_PRODUCT_ONUMM1N0

   FUNCTION R_DOT_PRODUCT_ONUMM1N0(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS(:)
      TYPE(ONUMM1N0), INTENT(IN) :: RHS(SIZE(LHS))
      TYPE(ONUMM1N0) :: RES

      ! Multiplication like function 'DOT_PRODUCT(LHS,RHS)'
      !  Real
      RES%R = DOT_PRODUCT(LHS,RHS%R)

   END FUNCTION R_DOT_PRODUCT_ONUMM1N0

   FUNCTION ONUMM1N0_DOT_PRODUCT_R(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM1N0), INTENT(IN) :: LHS(:)
      REAL(DP), INTENT(IN) :: RHS(SIZE(LHS))
      TYPE(ONUMM1N0) :: RES

      ! Multiplication like function 'DOT_PRODUCT(LHS,RHS)'
      !  Real
      RES%R = DOT_PRODUCT(LHS%R,RHS)

   END FUNCTION ONUMM1N0_DOT_PRODUCT_R

   FUNCTION ONUMM1N0_TRANSPOSE(LHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM1N0), INTENT(IN) :: LHS(:,:)
      TYPE(ONUMM1N0) :: RES (SIZE(LHS,2),SIZE(LHS,1))

      ! Negation like function 'TRANSPOSE(LHS)'
      ! Real
      RES%R = TRANSPOSE(LHS%R)

   END FUNCTION ONUMM1N0_TRANSPOSE

FUNCTION ONUMM1N0_TO_CR_MAT_S(VAL) RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM1N0), INTENT(IN) :: VAL
      REAL(DP) :: RES(NUM_IM_DIR,NUM_IM_DIR) 
      INTEGER :: NCOLS=1, NROWS=1


      ! R x R -> R (1, 1)
      RES(1+NROWS*0:NROWS*1,1+NCOLS*0:NCOLS*1) = VAL%R
   END FUNCTION ONUMM1N0_TO_CR_MAT_S

FUNCTION ONUMM1N0_TO_CR_MAT_V(VAL) RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM1N0), INTENT(IN) :: VAL(:)
      REAL(DP) :: RES(NUM_IM_DIR*SIZE(VAL,1),NUM_IM_DIR) 
      INTEGER :: NCOLS=1, NROWS=1

      NROWS = SIZE(VAL,1)

      ! R x R -> R (1, 1)
      RES(1+NROWS*0:NROWS*1,1) = VAL%R
   END FUNCTION ONUMM1N0_TO_CR_MAT_V

FUNCTION ONUMM1N0_TO_CR_MAT_M(VAL) RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM1N0), INTENT(IN) :: VAL(:,:)
      REAL(DP) :: RES(NUM_IM_DIR*SIZE(VAL,1),NUM_IM_DIR*SIZE(VAL,2)) 
      INTEGER :: NCOLS=1, NROWS=1

      NCOLS = SIZE(VAL,1)
      NROWS = SIZE(VAL,2)

      ! R x R -> R (1, 1)
      RES(1+NROWS*0:NROWS*1,1+NCOLS*0:NCOLS*1) = VAL%R
   END FUNCTION ONUMM1N0_TO_CR_MAT_M

      SUBROUTINE ONUMM1N0_SETIM_S(VAL,IDX,RES)
      IMPLICIT NONE
      TYPE(ONUMM1N0), INTENT(INOUT) :: VAL
      REAL(DP),INTENT(IN) :: RES 
      INTEGER, INTENT(IN) :: IDX

      SELECT CASE(IDX)
      ! Order 0
      CASE(0)
         VAL%R=RES

      END SELECT
   END SUBROUTINE ONUMM1N0_SETIM_S

      SUBROUTINE ONUMM1N0_SETIM_V(VAL,IDX,RES)
      IMPLICIT NONE
      TYPE(ONUMM1N0), INTENT(INOUT) :: VAL(:)
      REAL(DP),INTENT(IN) :: RES(SIZE(VAL)) 
      INTEGER, INTENT(IN) :: IDX

      SELECT CASE(IDX)
      ! Order 0
      CASE(0)
         VAL%R=RES

      END SELECT
   END SUBROUTINE ONUMM1N0_SETIM_V

      SUBROUTINE ONUMM1N0_SETIM_M(VAL,IDX,RES)
      IMPLICIT NONE
      TYPE(ONUMM1N0), INTENT(INOUT) :: VAL(:,:)
      REAL(DP),INTENT(IN) :: RES(SIZE(VAL,1),SIZE(VAL,2)) 
      INTEGER, INTENT(IN) :: IDX

      SELECT CASE(IDX)
      ! Order 0
      CASE(0)
         VAL%R=RES

      END SELECT
   END SUBROUTINE ONUMM1N0_SETIM_M

FUNCTION ONUMM1N0_GETIM_S(VAL,IDX) RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM1N0), INTENT(IN) :: VAL
      REAL(DP) :: RES 
      INTEGER, INTENT(IN) :: IDX

      SELECT CASE(IDX)
      ! Order 0
      CASE(0)
         RES=VAL%R

      END SELECT
   END FUNCTION ONUMM1N0_GETIM_S

FUNCTION ONUMM1N0_GETIM_V(VAL,IDX) RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM1N0), INTENT(IN) :: VAL(:)
      REAL(DP) :: RES(SIZE(VAL)) 
      INTEGER, INTENT(IN) :: IDX

      SELECT CASE(IDX)
      ! Order 0
      CASE(0)
         RES=VAL%R

      END SELECT
   END FUNCTION ONUMM1N0_GETIM_V

FUNCTION ONUMM1N0_GETIM_M(VAL,IDX) RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM1N0), INTENT(IN) :: VAL(:,:)
      REAL(DP) :: RES(SIZE(VAL,1),SIZE(VAL,2)) 
      INTEGER, INTENT(IN) :: IDX

      SELECT CASE(IDX)
      ! Order 0
      CASE(0)
         RES=VAL%R

      END SELECT
   END FUNCTION ONUMM1N0_GETIM_M

   SUBROUTINE ONUMM1N0_PPRINT_S(VAR,FMT,UNIT)
      IMPLICIT NONE
      TYPE(ONUMM1N0), INTENT(IN) :: VAR
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


   END SUBROUTINE ONUMM1N0_PPRINT_S

   SUBROUTINE ONUMM1N0_PPRINT_V(VAR,FMT,UNIT)
      IMPLICIT NONE
      TYPE(ONUMM1N0), INTENT(IN) :: VAR(:)
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


   END SUBROUTINE ONUMM1N0_PPRINT_V

   SUBROUTINE ONUMM1N0_PPRINT_M(VAR,FMT,UNIT)
      IMPLICIT NONE
      TYPE(ONUMM1N0), INTENT(IN) :: VAR(:,:)
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


   END SUBROUTINE ONUMM1N0_PPRINT_M

   ELEMENTAL FUNCTION ONUMM1N0_FEVAL(X,DER0)&
      RESULT(RES)
      IMPLICIT NONE
      !  Definitions
      REAL(DP) :: FACTOR, COEF
      TYPE(ONUMM1N0), INTENT(IN)  :: X
      REAL(DP), INTENT(IN)  :: DER0
      TYPE(ONUMM1N0) :: RES
      TYPE(ONUMM1N0) :: DX, DX_P

      FACTOR = 1.0_DP
      COEF   = 0.0_DP
      DX     = X
      DX_P   = X

      !  Set real part of deltas zero.
      DX%R = 0.0_DP
      DX_P%R = 0.0_DP

      ! Sets real part
      RES = DER0

   END FUNCTION ONUMM1N0_FEVAL


  ! SUBROUTINE ONUMM1N0_PPRINT_M_R(X, FMT)
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

  ! END SUBROUTINE ONUMM1N0_PPRINT_M_R

  ! SUBROUTINE ONUMM1N0_PPRINT_V_R(X, FMT)
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

  ! END SUBROUTINE ONUMM1N0_PPRINT_V_R

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
  PURE FUNCTION ONUMM1N0_det2x2(A) RESULT(det)

    IMPLICIT NONE

    TYPE(ONUMM1N0), INTENT(IN) :: A(2,2)   !! Matrix
    TYPE(ONUMM1N0)             :: det

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
  PURE FUNCTION ONUMM1N0_det3x3(A) RESULT(det)
      
    IMPLICIT NONE

    TYPE(ONUMM1N0), INTENT(IN) :: A(3,3)   !! Matrix
    TYPE(ONUMM1N0)             :: det

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
  PURE FUNCTION ONUMM1N0_det4x4(A) RESULT(det)
      
    IMPLICIT NONE

    TYPE(ONUMM1N0), INTENT(IN) :: A(4,4)   !! Matrix
    TYPE(ONUMM1N0)             :: det

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
  PURE FUNCTION ONUMM1N0_cross3(a,b) RESULT(v)
      
    IMPLICIT NONE 

    TYPE(ONUMM1N0), DIMENSION (3),INTENT(IN) :: a,b
    TYPE(ONUMM1N0), DIMENSION (3) :: v
    
    v(1) = a(2) * b(3) - a(3) * b(2)
    v(2) = a(3) * b(1) - a(1) * b(3)
    v(3) = a(1) * b(2) - a(2) * b(1)

  END FUNCTION ONUMM1N0_cross3
  !===================================================================================================! 

  !***************************************************************************************************! 
  !> @brief Norm of a 3 element vector. # There is an intrinsic function named norm2.
  !!
  !! @param[in] a: Vector of 3 reals (rank 1).
  !! @param[in] b: Vector of 3 reals (rank 1).
  !!
  !***************************************************************************************************!
  FUNCTION ONUMM1N0_norm2_3(v) RESULT(n)
     
    IMPLICIT NONE 

    TYPE(ONUMM1N0), INTENT(IN) :: v(3)
    TYPE(ONUMM1N0) :: n
     
    n = SQRT( v(1)*v(1) + v(2)*v(2) + v(3)*v(3) )

  END FUNCTION ONUMM1N0_norm2_3
  !===================================================================================================! 

  ELEMENTAL FUNCTION ONUMM1N0_DIVISION_OO(X,Y) RESULT(RES)
      IMPLICIT NONE
      ! REAL(DP) :: DERIVS(TORDER + 1) 
      TYPE(ONUMM1N0), INTENT(IN) :: X
      TYPE(ONUMM1N0), INTENT(IN) :: Y
      TYPE(ONUMM1N0) :: RES

      RES = X*(Y**(-1.d0))

  END FUNCTION ONUMM1N0_DIVISION_OO

  ELEMENTAL FUNCTION ONUMM1N0_DIVISION_OR(X,Y) RESULT(RES)
      IMPLICIT NONE
      ! REAL(DP) :: DERIVS(TORDER + 1) 
      TYPE(ONUMM1N0), INTENT(IN) :: X
      REAL(DP), INTENT(IN) :: Y
      TYPE(ONUMM1N0) :: RES

      RES = X*(Y**(-1.d0))

  END FUNCTION ONUMM1N0_DIVISION_OR

  ELEMENTAL FUNCTION ONUMM1N0_DIVISION_RO(X,Y) RESULT(RES)
      IMPLICIT NONE
      ! REAL(DP) :: DERIVS(TORDER + 1) 
      REAL(DP), INTENT(IN) :: X
      TYPE(ONUMM1N0), INTENT(IN) :: Y
      TYPE(ONUMM1N0) :: RES

      RES = X*(Y**(-1.d0))

  END FUNCTION ONUMM1N0_DIVISION_RO

  ELEMENTAL FUNCTION ONUMM1N0_REAL(X) RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM1N0), INTENT(IN) :: X
      REAL(DP) :: RES

      RES = X%R

  END FUNCTION ONUMM1N0_REAL

  FUNCTION ONUMM1N0_SQRT(X) RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM1N0), INTENT(IN) :: X
      TYPE(ONUMM1N0) :: RES

      RES = X**0.5_DP

  END FUNCTION ONUMM1N0_SQRT

   ELEMENTAL FUNCTION ONUMM1N0_TAN(X) RESULT(RES)

      TYPE(ONUMM1N0), INTENT(IN) :: X
      REAL(DP) :: DER0
      TYPE(ONUMM1N0) :: RES
      
      DER0 = TAN(X%R)

      RES = FEVAL(X,DER0)

   END FUNCTION ONUMM1N0_TAN

   ELEMENTAL FUNCTION ONUMM1N0_COS(X) RESULT(RES)

      TYPE(ONUMM1N0), INTENT(IN) :: X
      REAL(DP) :: DER0
      TYPE(ONUMM1N0) :: RES
      
      DER0 = COS(X%R)

      RES = FEVAL(X,DER0)

   END FUNCTION ONUMM1N0_COS

   ELEMENTAL FUNCTION ONUMM1N0_SIN(X) RESULT(RES)

      TYPE(ONUMM1N0), INTENT(IN) :: X
      REAL(DP) :: DER0
      TYPE(ONUMM1N0) :: RES
      
      DER0 = SIN(X%R)

      RES = FEVAL(X,DER0)

   END FUNCTION ONUMM1N0_SIN

   ELEMENTAL FUNCTION ONUMM1N0_ATAN(X) RESULT(RES)

      TYPE(ONUMM1N0), INTENT(IN) :: X
      REAL(DP) :: DER0
      TYPE(ONUMM1N0) :: RES
      
      DER0 = ATAN(X%R)

      RES = FEVAL(X,DER0)

   END FUNCTION ONUMM1N0_ATAN

   ELEMENTAL FUNCTION ONUMM1N0_ACOS(X) RESULT(RES)

      TYPE(ONUMM1N0), INTENT(IN) :: X
      REAL(DP) :: DER0
      TYPE(ONUMM1N0) :: RES
      
      DER0 = ACOS(X%R)

      RES = FEVAL(X,DER0)

   END FUNCTION ONUMM1N0_ACOS

   ELEMENTAL FUNCTION ONUMM1N0_ASIN(X) RESULT(RES)

      TYPE(ONUMM1N0), INTENT(IN) :: X
      REAL(DP) :: DER0
      TYPE(ONUMM1N0) :: RES
      
      DER0 = ASIN(X%R)

      RES = FEVAL(X,DER0)

   END FUNCTION ONUMM1N0_ASIN

   ELEMENTAL FUNCTION ONUMM1N0_TANH(X) RESULT(RES)

      TYPE(ONUMM1N0), INTENT(IN) :: X
      REAL(DP) :: DER0
      TYPE(ONUMM1N0) :: RES
      
      DER0 = TANH(X%R)

      RES = FEVAL(X,DER0)

   END FUNCTION ONUMM1N0_TANH

   ELEMENTAL FUNCTION ONUMM1N0_COSH(X) RESULT(RES)

      TYPE(ONUMM1N0), INTENT(IN) :: X
      REAL(DP) :: DER0
      TYPE(ONUMM1N0) :: RES
      
      DER0 = COSH(X%R)

      RES = FEVAL(X,DER0)

   END FUNCTION ONUMM1N0_COSH

   ELEMENTAL FUNCTION ONUMM1N0_SINH(X) RESULT(RES)

      TYPE(ONUMM1N0), INTENT(IN) :: X
      REAL(DP) :: DER0
      TYPE(ONUMM1N0) :: RES
      
      DER0 = SINH(X%R)

      RES = FEVAL(X,DER0)

   END FUNCTION ONUMM1N0_SINH

   ELEMENTAL FUNCTION ONUMM1N0_EXP(X) RESULT(RES)

      TYPE(ONUMM1N0), INTENT(IN) :: X
      REAL(DP) :: DER0
      TYPE(ONUMM1N0) :: RES
      
      DER0 = EXP(X%R)

      RES = FEVAL(X,DER0)

   END FUNCTION ONUMM1N0_EXP

   ELEMENTAL FUNCTION ONUMM1N0_LOG(X) RESULT(RES)

      TYPE(ONUMM1N0), INTENT(IN) :: X
      REAL(DP) :: DER0
      TYPE(ONUMM1N0) :: RES
      
      DER0 = LOG(X%R)

      RES = FEVAL(X,DER0)

   END FUNCTION ONUMM1N0_LOG

   ELEMENTAL FUNCTION ONUMM1N0_POW_OR(X,E) RESULT(RES)

      TYPE(ONUMM1N0), INTENT(IN) :: X
      REAL(DP), INTENT(IN) :: E
      REAL(DP) :: DER0
      TYPE(ONUMM1N0) :: RES
      
      DER0=0.0d0
      
      DER0 = X%R**E

      RES = FEVAL(X,DER0)

   END FUNCTION ONUMM1N0_POW_OR

   ELEMENTAL FUNCTION ONUMM1N0_POW_RO(E,X) RESULT(RES)

      TYPE(ONUMM1N0), INTENT(IN) :: X
      REAL(DP), INTENT(IN) :: E
      REAL(DP) :: DER0
      TYPE(ONUMM1N0) :: RES
      
      
      DER0 = E**X%R

      RES = FEVAL(X,DER0)

   END FUNCTION ONUMM1N0_POW_RO

   ELEMENTAL FUNCTION ONUMM1N0_F2EVAL(X,Y,DER0_0)&
      RESULT(RES)
      IMPLICIT NONE
      !  Definitions
      REAL(DP) :: COEF, DELTA
      TYPE(ONUMM1N0), INTENT(IN)  :: X,Y
      REAL(DP), INTENT(IN)  :: DER0_0
      TYPE(ONUMM1N0) :: RES
      TYPE(ONUMM1N0) :: DX, DY

      COEF   = 0.0_DP
      DX     = X
      DY     = Y

      !  Set real part of deltas zero.
      DX%R = 0.0_DP
      DY%R = 0.0_DP

      ! Set real part
      RES = DER0_0

   END FUNCTION ONUMM1N0_F2EVAL


   ELEMENTAL FUNCTION ONUMM1N0_POW_OO(X,Y) RESULT(RES)

      TYPE(ONUMM1N0), INTENT(IN) :: X, Y
      REAL(DP) :: DER0_0
      TYPE(ONUMM1N0) :: RES
      
      DER0_0 = X%R**Y%R

      RES = F2EVAL(X,Y,DER0_0)

   END FUNCTION ONUMM1N0_POW_OO


   FUNCTION ONUMM1N0_INV2X2(A,det)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM1N0) , INTENT(IN) :: A(2,2) 
      TYPE(ONUMM1N0) , INTENT(IN), OPTIONAL :: det
      REAL(DP) :: detCalc
      TYPE(ONUMM1N0) :: RES(SIZE(A,1),SIZE(A,2)) 

      IF (PRESENT(det)) THEN
         detCalc=det%R
      ELSE
         detCalc=det2x2(A%R)
      END IF

      ! Get real part 
      RES%R=INV2X2(A%R,detCalc)

   END FUNCTION ONUMM1N0_INV2X2

   FUNCTION ONUMM1N0_INV3X3(A,det)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM1N0) , INTENT(IN) :: A(3,3) 
      TYPE(ONUMM1N0) , INTENT(IN), OPTIONAL :: det
      REAL(DP) :: detCalc
      TYPE(ONUMM1N0) :: RES(SIZE(A,1),SIZE(A,2)) 

      IF (PRESENT(det)) THEN
         detCalc=det%R
      ELSE
         detCalc=det3x3(A%R)
      END IF

      ! Get real part 
      RES%R=INV3X3(A%R,detCalc)

   END FUNCTION ONUMM1N0_INV3X3

   FUNCTION ONUMM1N0_INV4X4(A,det)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(ONUMM1N0) , INTENT(IN) :: A(4,4) 
      TYPE(ONUMM1N0) , INTENT(IN), OPTIONAL :: det
      REAL(DP) :: detCalc
      TYPE(ONUMM1N0) :: RES(SIZE(A,1),SIZE(A,2)) 

      IF (PRESENT(det)) THEN
         detCalc=det%R
      ELSE
         detCalc=det4x4(A%R)
      END IF

      ! Get real part 
      RES%R=INV4X4(A%R,detCalc)

   END FUNCTION ONUMM1N0_INV4X4

END MODULE OTIM1N0
