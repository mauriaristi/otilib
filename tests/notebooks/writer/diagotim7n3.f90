MODULE diagotim7n3

   USE master_parameters
   USE real_utils

   IMPLICIT NONE

   INTEGER, PARAMETER :: num_im_dir = 120
   INTEGER, PARAMETER :: torder     = 3
   INTEGER, PARAMETER :: n_imdir_order(4) = [1,7,7,7]

   TYPE DONUMM7N3
     ! Real
     REAL(DP) :: R
     ! Order 1
     REAL(DP) :: E1
     REAL(DP) :: E2
     REAL(DP) :: E3
     REAL(DP) :: E4
     REAL(DP) :: E5
     REAL(DP) :: E6
     REAL(DP) :: E7
     ! Order 2
     REAL(DP) :: E11
     REAL(DP) :: E22
     REAL(DP) :: E33
     REAL(DP) :: E44
     REAL(DP) :: E55
     REAL(DP) :: E66
     REAL(DP) :: E77
     ! Order 3
     REAL(DP) :: E111
     REAL(DP) :: E222
     REAL(DP) :: E333
     REAL(DP) :: E444
     REAL(DP) :: E555
     REAL(DP) :: E666
     REAL(DP) :: E777
   END TYPE DONUMM7N3

   ! Constant imaginary directions.
   ! Order 1
   TYPE(DONUMM7N3), PARAMETER :: E1 = DONUMM7N3(0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(DONUMM7N3), PARAMETER :: E2 = DONUMM7N3(0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(DONUMM7N3), PARAMETER :: E3 = DONUMM7N3(0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(DONUMM7N3), PARAMETER :: E4 = DONUMM7N3(0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(DONUMM7N3), PARAMETER :: E5 = DONUMM7N3(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(DONUMM7N3), PARAMETER :: E6 = DONUMM7N3(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(DONUMM7N3), PARAMETER :: E7 = DONUMM7N3(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   ! Order 2
   TYPE(DONUMM7N3), PARAMETER :: E11 = DONUMM7N3(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(DONUMM7N3), PARAMETER :: E22 = DONUMM7N3(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(DONUMM7N3), PARAMETER :: E33 = DONUMM7N3(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(DONUMM7N3), PARAMETER :: E44 = DONUMM7N3(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(DONUMM7N3), PARAMETER :: E55 = DONUMM7N3(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(DONUMM7N3), PARAMETER :: E66 = DONUMM7N3(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(DONUMM7N3), PARAMETER :: E77 = DONUMM7N3(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   ! Order 3
   TYPE(DONUMM7N3), PARAMETER :: E111 = DONUMM7N3(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(DONUMM7N3), PARAMETER :: E222 = DONUMM7N3(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(DONUMM7N3), PARAMETER :: E333 = DONUMM7N3(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(DONUMM7N3), PARAMETER :: E444 = DONUMM7N3(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(DONUMM7N3), PARAMETER :: E555 = DONUMM7N3(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp)
   TYPE(DONUMM7N3), PARAMETER :: E666 = DONUMM7N3(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp)
   TYPE(DONUMM7N3), PARAMETER :: E777 = DONUMM7N3(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp)


   INTERFACE OPERATOR(*)
      MODULE PROCEDURE DONUMM7N3_MUL_OO_SS,DONUMM7N3_MUL_RO_SS,DONUMM7N3_MUL_OR_SS,DONUMM7N3_MUL_OO_VS,&
                       DONUMM7N3_MUL_RO_VS,DONUMM7N3_MUL_OR_VS,DONUMM7N3_MUL_OO_MS,DONUMM7N3_MUL_RO_MS,&
                       DONUMM7N3_MUL_OR_MS,DONUMM7N3_MUL_OO_SV,DONUMM7N3_MUL_RO_SV,DONUMM7N3_MUL_OR_SV,&
                       DONUMM7N3_MUL_OO_SM,DONUMM7N3_MUL_RO_SM,DONUMM7N3_MUL_OR_SM
   END INTERFACE

   INTERFACE OPERATOR(+)
      MODULE PROCEDURE DONUMM7N3_ADD_OO_SS,DONUMM7N3_ADD_RO_SS,DONUMM7N3_ADD_OR_SS,DONUMM7N3_ADD_OO_VS,&
                       DONUMM7N3_ADD_RO_VS,DONUMM7N3_ADD_OR_VS,DONUMM7N3_ADD_OO_MS,DONUMM7N3_ADD_RO_MS,&
                       DONUMM7N3_ADD_OR_MS,DONUMM7N3_ADD_OO_SV,DONUMM7N3_ADD_RO_SV,DONUMM7N3_ADD_OR_SV,&
                       DONUMM7N3_ADD_OO_SM,DONUMM7N3_ADD_RO_SM,DONUMM7N3_ADD_OR_SM
   END INTERFACE

   INTERFACE OPERATOR(-)
      MODULE PROCEDURE DONUMM7N3_NEG,DONUMM7N3_SUB_OO_SS,DONUMM7N3_SUB_RO_SS,DONUMM7N3_SUB_OR_SS,&
                       DONUMM7N3_SUB_OO_VS,DONUMM7N3_SUB_RO_VS,DONUMM7N3_SUB_OR_VS,DONUMM7N3_SUB_OO_MS,&
                       DONUMM7N3_SUB_RO_MS,DONUMM7N3_SUB_OR_MS,DONUMM7N3_SUB_OO_SV,DONUMM7N3_SUB_RO_SV,&
                       DONUMM7N3_SUB_OR_SV,DONUMM7N3_SUB_OO_SM,DONUMM7N3_SUB_RO_SM,DONUMM7N3_SUB_OR_SM
   END INTERFACE

   INTERFACE OPERATOR(/)
      MODULE PROCEDURE DONUMM7N3_DIVISION_OO,DONUMM7N3_DIVISION_OR,DONUMM7N3_DIVISION_RO
   END INTERFACE

   INTERFACE ASSIGNMENT(=)
      MODULE PROCEDURE DONUMM7N3_ASSIGN_R
   END INTERFACE

   INTERFACE OPERATOR(**)
      MODULE PROCEDURE DONUMM7N3_POW_OR,DONUMM7N3_POW_RO,DONUMM7N3_POW_OO
   END INTERFACE

   INTERFACE PPRINT
      MODULE PROCEDURE DONUMM7N3_PPRINT_S,DONUMM7N3_PPRINT_V,DONUMM7N3_PPRINT_M
   END INTERFACE

   INTERFACE TRANSPOSE
      MODULE PROCEDURE DONUMM7N3_TRANSPOSE
   END INTERFACE

   INTERFACE MATMUL
      MODULE PROCEDURE DONUMM7N3_MATMUL_DONUMM7N3,R_MATMUL_DONUMM7N3,DONUMM7N3_MATMUL_R
   END INTERFACE

   INTERFACE DOT_PRODUCT
      MODULE PROCEDURE DONUMM7N3_DOT_PRODUCT_DONUMM7N3,R_DOT_PRODUCT_DONUMM7N3,DONUMM7N3_DOT_PRODUCT_R
   END INTERFACE

   INTERFACE UNFOLD
      MODULE PROCEDURE DONUMM7N3_TO_CR_MAT_S,DONUMM7N3_TO_CR_MAT_V,DONUMM7N3_TO_CR_MAT_M
   END INTERFACE

   INTERFACE TO_CR
      MODULE PROCEDURE DONUMM7N3_TO_CR_MAT_S,DONUMM7N3_TO_CR_MAT_V,DONUMM7N3_TO_CR_MAT_M
   END INTERFACE

   INTERFACE SIN
      MODULE PROCEDURE DONUMM7N3_SIN
   END INTERFACE

   INTERFACE COS
      MODULE PROCEDURE DONUMM7N3_COS
   END INTERFACE

   INTERFACE TAN
      MODULE PROCEDURE DONUMM7N3_TAN
   END INTERFACE

   INTERFACE ASIN
      MODULE PROCEDURE DONUMM7N3_ASIN
   END INTERFACE

   INTERFACE ACOS
      MODULE PROCEDURE DONUMM7N3_ACOS
   END INTERFACE

   INTERFACE ATAN
      MODULE PROCEDURE DONUMM7N3_ATAN
   END INTERFACE

   INTERFACE SINH
      MODULE PROCEDURE DONUMM7N3_SINH
   END INTERFACE

   INTERFACE COSH
      MODULE PROCEDURE DONUMM7N3_COSH
   END INTERFACE

   INTERFACE TANH
      MODULE PROCEDURE DONUMM7N3_TANH
   END INTERFACE

   INTERFACE SQRT
      MODULE PROCEDURE DONUMM7N3_SQRT
   END INTERFACE

   INTERFACE LOG
      MODULE PROCEDURE DONUMM7N3_LOG
   END INTERFACE

   INTERFACE EXP
      MODULE PROCEDURE DONUMM7N3_EXP
   END INTERFACE

   INTERFACE GEM
      MODULE PROCEDURE DONUMM7N3_GEM_OOO,DONUMM7N3_GEM_ROO,DONUMM7N3_GEM_ORO
   END INTERFACE

   INTERFACE FEVAL
      MODULE PROCEDURE DONUMM7N3_FEVAL
   END INTERFACE

   INTERFACE F2EVAL
      MODULE PROCEDURE DONUMM7N3_F2EVAL
   END INTERFACE

   INTERFACE REAL
      MODULE PROCEDURE DONUMM7N3_REAL
   END INTERFACE

   INTERFACE DET2X2
      MODULE PROCEDURE DONUMM7N3_det2x2
   END INTERFACE

   INTERFACE DET3X3
      MODULE PROCEDURE DONUMM7N3_det3x3
   END INTERFACE

   INTERFACE DET4X4
      MODULE PROCEDURE DONUMM7N3_det4x4
   END INTERFACE

   INTERFACE INV2X2
      MODULE PROCEDURE DONUMM7N3_INV2X2
   END INTERFACE

   INTERFACE INV3X3
      MODULE PROCEDURE DONUMM7N3_INV3X3
   END INTERFACE

   INTERFACE INV4X4
      MODULE PROCEDURE DONUMM7N3_INV4X4
   END INTERFACE

   INTERFACE GETIM
      MODULE PROCEDURE DONUMM7N3_GETIM_S,DONUMM7N3_GETIM_V,DONUMM7N3_GETIM_M
   END INTERFACE

   INTERFACE SETIM
      MODULE PROCEDURE DONUMM7N3_SETIM_S,DONUMM7N3_SETIM_V,DONUMM7N3_SETIM_M
   END INTERFACE

   CONTAINS

   ELEMENTAL SUBROUTINE DONUMM7N3_ASSIGN_R(RES,LHS)
      
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS 
      TYPE(DONUMM7N3), INTENT(OUT) :: RES 

      ! Assign like function 'LHS'
      ! Real
      RES%R = LHS

      ! Order 1
      RES%E1 = 0.0_dp
      RES%E2 = 0.0_dp
      RES%E3 = 0.0_dp
      RES%E4 = 0.0_dp
      RES%E5 = 0.0_dp
      RES%E6 = 0.0_dp
      RES%E7 = 0.0_dp

      ! Order 2
      RES%E11 = 0.0_dp
      RES%E22 = 0.0_dp
      RES%E33 = 0.0_dp
      RES%E44 = 0.0_dp
      RES%E55 = 0.0_dp
      RES%E66 = 0.0_dp
      RES%E77 = 0.0_dp

      ! Order 3
      RES%E111 = 0.0_dp
      RES%E222 = 0.0_dp
      RES%E333 = 0.0_dp
      RES%E444 = 0.0_dp
      RES%E555 = 0.0_dp
      RES%E666 = 0.0_dp
      RES%E777 = 0.0_dp

   END SUBROUTINE DONUMM7N3_ASSIGN_R

   ELEMENTAL FUNCTION DONUMM7N3_NEG(LHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(DONUMM7N3), INTENT(IN) :: LHS 
      TYPE(DONUMM7N3) :: RES 

      ! Negation like function '-LHS'
      ! Real
      RES%R = -LHS%R
      ! Order 1
      RES%E1 = -LHS%E1
      RES%E2 = -LHS%E2
      RES%E3 = -LHS%E3
      RES%E4 = -LHS%E4
      RES%E5 = -LHS%E5
      RES%E6 = -LHS%E6
      RES%E7 = -LHS%E7
      ! Order 2
      RES%E11 = -LHS%E11
      RES%E22 = -LHS%E22
      RES%E33 = -LHS%E33
      RES%E44 = -LHS%E44
      RES%E55 = -LHS%E55
      RES%E66 = -LHS%E66
      RES%E77 = -LHS%E77
      ! Order 3
      RES%E111 = -LHS%E111
      RES%E222 = -LHS%E222
      RES%E333 = -LHS%E333
      RES%E444 = -LHS%E444
      RES%E555 = -LHS%E555
      RES%E666 = -LHS%E666
      RES%E777 = -LHS%E777

   END FUNCTION DONUMM7N3_NEG

   ELEMENTAL FUNCTION DONUMM7N3_ADD_OO_SS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(DONUMM7N3), INTENT(IN) :: LHS
      TYPE(DONUMM7N3), INTENT(IN) :: RHS
      TYPE(DONUMM7N3) :: RES 

      ! Addition like function 'LHS + RHS'
      !  Real
      RES%R = LHS%R + RHS%R

      ! Order 1
      RES%E1 = LHS%E1 + RHS%E1
      RES%E2 = LHS%E2 + RHS%E2
      RES%E3 = LHS%E3 + RHS%E3
      RES%E4 = LHS%E4 + RHS%E4
      RES%E5 = LHS%E5 + RHS%E5
      RES%E6 = LHS%E6 + RHS%E6
      RES%E7 = LHS%E7 + RHS%E7

      ! Order 2
      RES%E11 = LHS%E11 + RHS%E11
      RES%E22 = LHS%E22 + RHS%E22
      RES%E33 = LHS%E33 + RHS%E33
      RES%E44 = LHS%E44 + RHS%E44
      RES%E55 = LHS%E55 + RHS%E55
      RES%E66 = LHS%E66 + RHS%E66
      RES%E77 = LHS%E77 + RHS%E77

      ! Order 3
      RES%E111 = LHS%E111 + RHS%E111
      RES%E222 = LHS%E222 + RHS%E222
      RES%E333 = LHS%E333 + RHS%E333
      RES%E444 = LHS%E444 + RHS%E444
      RES%E555 = LHS%E555 + RHS%E555
      RES%E666 = LHS%E666 + RHS%E666
      RES%E777 = LHS%E777 + RHS%E777

   END FUNCTION DONUMM7N3_ADD_OO_SS

   ELEMENTAL FUNCTION DONUMM7N3_ADD_RO_SS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS
      TYPE(DONUMM7N3), INTENT(IN) :: RHS
      TYPE(DONUMM7N3) :: RES 

      ! Addition like function 'LHS + RHS'
      ! Real
      RES%R = LHS + RHS%R

      ! Order 1
      RES%E1 =  + RHS%E1
      RES%E2 =  + RHS%E2
      RES%E3 =  + RHS%E3
      RES%E4 =  + RHS%E4
      RES%E5 =  + RHS%E5
      RES%E6 =  + RHS%E6
      RES%E7 =  + RHS%E7

      ! Order 2
      RES%E11 =  + RHS%E11
      RES%E22 =  + RHS%E22
      RES%E33 =  + RHS%E33
      RES%E44 =  + RHS%E44
      RES%E55 =  + RHS%E55
      RES%E66 =  + RHS%E66
      RES%E77 =  + RHS%E77

      ! Order 3
      RES%E111 =  + RHS%E111
      RES%E222 =  + RHS%E222
      RES%E333 =  + RHS%E333
      RES%E444 =  + RHS%E444
      RES%E555 =  + RHS%E555
      RES%E666 =  + RHS%E666
      RES%E777 =  + RHS%E777

   END FUNCTION DONUMM7N3_ADD_RO_SS

   ELEMENTAL FUNCTION DONUMM7N3_ADD_OR_SS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(DONUMM7N3), INTENT(IN) :: LHS
      REAL(DP), INTENT(IN) :: RHS
      TYPE(DONUMM7N3) :: RES 

      ! Addition like function 'LHS + RHS'
      ! Real
      RES%R = LHS%R + RHS

      ! Order 1
      RES%E1 = LHS%E1
      RES%E2 = LHS%E2
      RES%E3 = LHS%E3
      RES%E4 = LHS%E4
      RES%E5 = LHS%E5
      RES%E6 = LHS%E6
      RES%E7 = LHS%E7

      ! Order 2
      RES%E11 = LHS%E11
      RES%E22 = LHS%E22
      RES%E33 = LHS%E33
      RES%E44 = LHS%E44
      RES%E55 = LHS%E55
      RES%E66 = LHS%E66
      RES%E77 = LHS%E77

      ! Order 3
      RES%E111 = LHS%E111
      RES%E222 = LHS%E222
      RES%E333 = LHS%E333
      RES%E444 = LHS%E444
      RES%E555 = LHS%E555
      RES%E666 = LHS%E666
      RES%E777 = LHS%E777

   END FUNCTION DONUMM7N3_ADD_OR_SS

   ELEMENTAL FUNCTION DONUMM7N3_SUB_OO_SS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(DONUMM7N3), INTENT(IN) :: LHS
      TYPE(DONUMM7N3), INTENT(IN) :: RHS
      TYPE(DONUMM7N3) :: RES 

      ! Addition like function 'LHS - RHS'
      !  Real
      RES%R = LHS%R - RHS%R

      ! Order 1
      RES%E1 = LHS%E1 - RHS%E1
      RES%E2 = LHS%E2 - RHS%E2
      RES%E3 = LHS%E3 - RHS%E3
      RES%E4 = LHS%E4 - RHS%E4
      RES%E5 = LHS%E5 - RHS%E5
      RES%E6 = LHS%E6 - RHS%E6
      RES%E7 = LHS%E7 - RHS%E7

      ! Order 2
      RES%E11 = LHS%E11 - RHS%E11
      RES%E22 = LHS%E22 - RHS%E22
      RES%E33 = LHS%E33 - RHS%E33
      RES%E44 = LHS%E44 - RHS%E44
      RES%E55 = LHS%E55 - RHS%E55
      RES%E66 = LHS%E66 - RHS%E66
      RES%E77 = LHS%E77 - RHS%E77

      ! Order 3
      RES%E111 = LHS%E111 - RHS%E111
      RES%E222 = LHS%E222 - RHS%E222
      RES%E333 = LHS%E333 - RHS%E333
      RES%E444 = LHS%E444 - RHS%E444
      RES%E555 = LHS%E555 - RHS%E555
      RES%E666 = LHS%E666 - RHS%E666
      RES%E777 = LHS%E777 - RHS%E777

   END FUNCTION DONUMM7N3_SUB_OO_SS

   ELEMENTAL FUNCTION DONUMM7N3_SUB_RO_SS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS
      TYPE(DONUMM7N3), INTENT(IN) :: RHS
      TYPE(DONUMM7N3) :: RES 

      ! Addition like function 'LHS - RHS'
      ! Real
      RES%R = LHS - RHS%R

      ! Order 1
      RES%E1 =  - RHS%E1
      RES%E2 =  - RHS%E2
      RES%E3 =  - RHS%E3
      RES%E4 =  - RHS%E4
      RES%E5 =  - RHS%E5
      RES%E6 =  - RHS%E6
      RES%E7 =  - RHS%E7

      ! Order 2
      RES%E11 =  - RHS%E11
      RES%E22 =  - RHS%E22
      RES%E33 =  - RHS%E33
      RES%E44 =  - RHS%E44
      RES%E55 =  - RHS%E55
      RES%E66 =  - RHS%E66
      RES%E77 =  - RHS%E77

      ! Order 3
      RES%E111 =  - RHS%E111
      RES%E222 =  - RHS%E222
      RES%E333 =  - RHS%E333
      RES%E444 =  - RHS%E444
      RES%E555 =  - RHS%E555
      RES%E666 =  - RHS%E666
      RES%E777 =  - RHS%E777

   END FUNCTION DONUMM7N3_SUB_RO_SS

   ELEMENTAL FUNCTION DONUMM7N3_SUB_OR_SS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(DONUMM7N3), INTENT(IN) :: LHS
      REAL(DP), INTENT(IN) :: RHS
      TYPE(DONUMM7N3) :: RES 

      ! Addition like function 'LHS - RHS'
      ! Real
      RES%R = LHS%R - RHS

      ! Order 1
      RES%E1 = LHS%E1
      RES%E2 = LHS%E2
      RES%E3 = LHS%E3
      RES%E4 = LHS%E4
      RES%E5 = LHS%E5
      RES%E6 = LHS%E6
      RES%E7 = LHS%E7

      ! Order 2
      RES%E11 = LHS%E11
      RES%E22 = LHS%E22
      RES%E33 = LHS%E33
      RES%E44 = LHS%E44
      RES%E55 = LHS%E55
      RES%E66 = LHS%E66
      RES%E77 = LHS%E77

      ! Order 3
      RES%E111 = LHS%E111
      RES%E222 = LHS%E222
      RES%E333 = LHS%E333
      RES%E444 = LHS%E444
      RES%E555 = LHS%E555
      RES%E666 = LHS%E666
      RES%E777 = LHS%E777

   END FUNCTION DONUMM7N3_SUB_OR_SS

   ELEMENTAL FUNCTION DONUMM7N3_MUL_OO_SS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(DONUMM7N3), INTENT(IN) :: LHS
      TYPE(DONUMM7N3), INTENT(IN) :: RHS
      TYPE(DONUMM7N3) :: RES 

      !  Multiplication like function 'LHS*RHS'
      ! Order 3
      RES%E111 = LHS%R*RHS%E111 + LHS%E111*RHS%R +  &
              LHS%E1*RHS%E11 + LHS%E11*RHS%E1
      RES%E222 = LHS%R*RHS%E222 + LHS%E222*RHS%R +  &
              LHS%E2*RHS%E22 + LHS%E22*RHS%E2
      RES%E333 = LHS%R*RHS%E333 + LHS%E333*RHS%R +  &
              LHS%E3*RHS%E33 + LHS%E33*RHS%E3
      RES%E444 = LHS%R*RHS%E444 + LHS%E444*RHS%R +  &
              LHS%E4*RHS%E44 + LHS%E44*RHS%E4
      RES%E555 = LHS%R*RHS%E555 + LHS%E555*RHS%R +  &
              LHS%E5*RHS%E55 + LHS%E55*RHS%E5
      RES%E666 = LHS%R*RHS%E666 + LHS%E666*RHS%R +  &
              LHS%E6*RHS%E66 + LHS%E66*RHS%E6
      RES%E777 = LHS%R*RHS%E777 + LHS%E777*RHS%R +  &
              LHS%E7*RHS%E77 + LHS%E77*RHS%E7
      ! Order 2
      RES%E11 = LHS%R*RHS%E11 + LHS%E11*RHS%R + LHS%E1*RHS%E1
      RES%E22 = LHS%R*RHS%E22 + LHS%E22*RHS%R + LHS%E2*RHS%E2
      RES%E33 = LHS%R*RHS%E33 + LHS%E33*RHS%R + LHS%E3*RHS%E3
      RES%E44 = LHS%R*RHS%E44 + LHS%E44*RHS%R + LHS%E4*RHS%E4
      RES%E55 = LHS%R*RHS%E55 + LHS%E55*RHS%R + LHS%E5*RHS%E5
      RES%E66 = LHS%R*RHS%E66 + LHS%E66*RHS%R + LHS%E6*RHS%E6
      RES%E77 = LHS%R*RHS%E77 + LHS%E77*RHS%R + LHS%E7*RHS%E7
      ! Order 1
      RES%E1 = LHS%R*RHS%E1 + LHS%E1*RHS%R
      RES%E2 = LHS%R*RHS%E2 + LHS%E2*RHS%R
      RES%E3 = LHS%R*RHS%E3 + LHS%E3*RHS%R
      RES%E4 = LHS%R*RHS%E4 + LHS%E4*RHS%R
      RES%E5 = LHS%R*RHS%E5 + LHS%E5*RHS%R
      RES%E6 = LHS%R*RHS%E6 + LHS%E6*RHS%R
      RES%E7 = LHS%R*RHS%E7 + LHS%E7*RHS%R
      ! Order 0
      RES%R = LHS%R*RHS%R

   END FUNCTION DONUMM7N3_MUL_OO_SS

   ELEMENTAL FUNCTION DONUMM7N3_MUL_RO_SS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS
      TYPE(DONUMM7N3), INTENT(IN) :: RHS
      TYPE(DONUMM7N3) :: RES 

      ! Multiplication like function 'LHS*RHS'
      !  Real
      RES%R = LHS*RHS%R

      ! Order 1
      RES%E1 = LHS*RHS%E1
      RES%E2 = LHS*RHS%E2
      RES%E3 = LHS*RHS%E3
      RES%E4 = LHS*RHS%E4
      RES%E5 = LHS*RHS%E5
      RES%E6 = LHS*RHS%E6
      RES%E7 = LHS*RHS%E7

      ! Order 2
      RES%E11 = LHS*RHS%E11
      RES%E22 = LHS*RHS%E22
      RES%E33 = LHS*RHS%E33
      RES%E44 = LHS*RHS%E44
      RES%E55 = LHS*RHS%E55
      RES%E66 = LHS*RHS%E66
      RES%E77 = LHS*RHS%E77

      ! Order 3
      RES%E111 = LHS*RHS%E111
      RES%E222 = LHS*RHS%E222
      RES%E333 = LHS*RHS%E333
      RES%E444 = LHS*RHS%E444
      RES%E555 = LHS*RHS%E555
      RES%E666 = LHS*RHS%E666
      RES%E777 = LHS*RHS%E777

   END FUNCTION DONUMM7N3_MUL_RO_SS

   ELEMENTAL FUNCTION DONUMM7N3_MUL_OR_SS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(DONUMM7N3), INTENT(IN) :: LHS
      REAL(DP), INTENT(IN) :: RHS
      TYPE(DONUMM7N3) :: RES 

      ! Multiplication like function 'LHS*RHS'
      !  Real
      RES%R = LHS%R*RHS

      ! Order 1
      RES%E1 = LHS%E1*RHS
      RES%E2 = LHS%E2*RHS
      RES%E3 = LHS%E3*RHS
      RES%E4 = LHS%E4*RHS
      RES%E5 = LHS%E5*RHS
      RES%E6 = LHS%E6*RHS
      RES%E7 = LHS%E7*RHS

      ! Order 2
      RES%E11 = LHS%E11*RHS
      RES%E22 = LHS%E22*RHS
      RES%E33 = LHS%E33*RHS
      RES%E44 = LHS%E44*RHS
      RES%E55 = LHS%E55*RHS
      RES%E66 = LHS%E66*RHS
      RES%E77 = LHS%E77*RHS

      ! Order 3
      RES%E111 = LHS%E111*RHS
      RES%E222 = LHS%E222*RHS
      RES%E333 = LHS%E333*RHS
      RES%E444 = LHS%E444*RHS
      RES%E555 = LHS%E555*RHS
      RES%E666 = LHS%E666*RHS
      RES%E777 = LHS%E777*RHS

   END FUNCTION DONUMM7N3_MUL_OR_SS

   FUNCTION DONUMM7N3_ADD_OO_VS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(DONUMM7N3), INTENT(IN) :: LHS(:)
      TYPE(DONUMM7N3), INTENT(IN) :: RHS
      TYPE(DONUMM7N3) :: RES(SIZE(LHS,1)) 

      ! Addition like function 'LHS + RHS'
      !  Real
      RES%R = LHS%R + RHS%R

      ! Order 1
      RES%E1 = LHS%E1 + RHS%E1
      RES%E2 = LHS%E2 + RHS%E2
      RES%E3 = LHS%E3 + RHS%E3
      RES%E4 = LHS%E4 + RHS%E4
      RES%E5 = LHS%E5 + RHS%E5
      RES%E6 = LHS%E6 + RHS%E6
      RES%E7 = LHS%E7 + RHS%E7

      ! Order 2
      RES%E11 = LHS%E11 + RHS%E11
      RES%E22 = LHS%E22 + RHS%E22
      RES%E33 = LHS%E33 + RHS%E33
      RES%E44 = LHS%E44 + RHS%E44
      RES%E55 = LHS%E55 + RHS%E55
      RES%E66 = LHS%E66 + RHS%E66
      RES%E77 = LHS%E77 + RHS%E77

      ! Order 3
      RES%E111 = LHS%E111 + RHS%E111
      RES%E222 = LHS%E222 + RHS%E222
      RES%E333 = LHS%E333 + RHS%E333
      RES%E444 = LHS%E444 + RHS%E444
      RES%E555 = LHS%E555 + RHS%E555
      RES%E666 = LHS%E666 + RHS%E666
      RES%E777 = LHS%E777 + RHS%E777

   END FUNCTION DONUMM7N3_ADD_OO_VS

   FUNCTION DONUMM7N3_ADD_RO_VS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS(:)
      TYPE(DONUMM7N3), INTENT(IN) :: RHS
      TYPE(DONUMM7N3) :: RES(SIZE(LHS,1)) 

      ! Addition like function 'LHS + RHS'
      ! Real
      RES%R = LHS + RHS%R

      ! Order 1
      RES%E1 =  + RHS%E1
      RES%E2 =  + RHS%E2
      RES%E3 =  + RHS%E3
      RES%E4 =  + RHS%E4
      RES%E5 =  + RHS%E5
      RES%E6 =  + RHS%E6
      RES%E7 =  + RHS%E7

      ! Order 2
      RES%E11 =  + RHS%E11
      RES%E22 =  + RHS%E22
      RES%E33 =  + RHS%E33
      RES%E44 =  + RHS%E44
      RES%E55 =  + RHS%E55
      RES%E66 =  + RHS%E66
      RES%E77 =  + RHS%E77

      ! Order 3
      RES%E111 =  + RHS%E111
      RES%E222 =  + RHS%E222
      RES%E333 =  + RHS%E333
      RES%E444 =  + RHS%E444
      RES%E555 =  + RHS%E555
      RES%E666 =  + RHS%E666
      RES%E777 =  + RHS%E777

   END FUNCTION DONUMM7N3_ADD_RO_VS

   FUNCTION DONUMM7N3_ADD_OR_VS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(DONUMM7N3), INTENT(IN) :: LHS(:)
      REAL(DP), INTENT(IN) :: RHS
      TYPE(DONUMM7N3) :: RES(SIZE(LHS,1)) 

      ! Addition like function 'LHS + RHS'
      ! Real
      RES%R = LHS%R + RHS

      ! Order 1
      RES%E1 = LHS%E1
      RES%E2 = LHS%E2
      RES%E3 = LHS%E3
      RES%E4 = LHS%E4
      RES%E5 = LHS%E5
      RES%E6 = LHS%E6
      RES%E7 = LHS%E7

      ! Order 2
      RES%E11 = LHS%E11
      RES%E22 = LHS%E22
      RES%E33 = LHS%E33
      RES%E44 = LHS%E44
      RES%E55 = LHS%E55
      RES%E66 = LHS%E66
      RES%E77 = LHS%E77

      ! Order 3
      RES%E111 = LHS%E111
      RES%E222 = LHS%E222
      RES%E333 = LHS%E333
      RES%E444 = LHS%E444
      RES%E555 = LHS%E555
      RES%E666 = LHS%E666
      RES%E777 = LHS%E777

   END FUNCTION DONUMM7N3_ADD_OR_VS

   FUNCTION DONUMM7N3_SUB_OO_VS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(DONUMM7N3), INTENT(IN) :: LHS(:)
      TYPE(DONUMM7N3), INTENT(IN) :: RHS
      TYPE(DONUMM7N3) :: RES(SIZE(LHS,1)) 

      ! Addition like function 'LHS - RHS'
      !  Real
      RES%R = LHS%R - RHS%R

      ! Order 1
      RES%E1 = LHS%E1 - RHS%E1
      RES%E2 = LHS%E2 - RHS%E2
      RES%E3 = LHS%E3 - RHS%E3
      RES%E4 = LHS%E4 - RHS%E4
      RES%E5 = LHS%E5 - RHS%E5
      RES%E6 = LHS%E6 - RHS%E6
      RES%E7 = LHS%E7 - RHS%E7

      ! Order 2
      RES%E11 = LHS%E11 - RHS%E11
      RES%E22 = LHS%E22 - RHS%E22
      RES%E33 = LHS%E33 - RHS%E33
      RES%E44 = LHS%E44 - RHS%E44
      RES%E55 = LHS%E55 - RHS%E55
      RES%E66 = LHS%E66 - RHS%E66
      RES%E77 = LHS%E77 - RHS%E77

      ! Order 3
      RES%E111 = LHS%E111 - RHS%E111
      RES%E222 = LHS%E222 - RHS%E222
      RES%E333 = LHS%E333 - RHS%E333
      RES%E444 = LHS%E444 - RHS%E444
      RES%E555 = LHS%E555 - RHS%E555
      RES%E666 = LHS%E666 - RHS%E666
      RES%E777 = LHS%E777 - RHS%E777

   END FUNCTION DONUMM7N3_SUB_OO_VS

   FUNCTION DONUMM7N3_SUB_RO_VS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS(:)
      TYPE(DONUMM7N3), INTENT(IN) :: RHS
      TYPE(DONUMM7N3) :: RES(SIZE(LHS,1)) 

      ! Addition like function 'LHS - RHS'
      ! Real
      RES%R = LHS - RHS%R

      ! Order 1
      RES%E1 =  - RHS%E1
      RES%E2 =  - RHS%E2
      RES%E3 =  - RHS%E3
      RES%E4 =  - RHS%E4
      RES%E5 =  - RHS%E5
      RES%E6 =  - RHS%E6
      RES%E7 =  - RHS%E7

      ! Order 2
      RES%E11 =  - RHS%E11
      RES%E22 =  - RHS%E22
      RES%E33 =  - RHS%E33
      RES%E44 =  - RHS%E44
      RES%E55 =  - RHS%E55
      RES%E66 =  - RHS%E66
      RES%E77 =  - RHS%E77

      ! Order 3
      RES%E111 =  - RHS%E111
      RES%E222 =  - RHS%E222
      RES%E333 =  - RHS%E333
      RES%E444 =  - RHS%E444
      RES%E555 =  - RHS%E555
      RES%E666 =  - RHS%E666
      RES%E777 =  - RHS%E777

   END FUNCTION DONUMM7N3_SUB_RO_VS

   FUNCTION DONUMM7N3_SUB_OR_VS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(DONUMM7N3), INTENT(IN) :: LHS(:)
      REAL(DP), INTENT(IN) :: RHS
      TYPE(DONUMM7N3) :: RES(SIZE(LHS,1)) 

      ! Addition like function 'LHS - RHS'
      ! Real
      RES%R = LHS%R - RHS

      ! Order 1
      RES%E1 = LHS%E1
      RES%E2 = LHS%E2
      RES%E3 = LHS%E3
      RES%E4 = LHS%E4
      RES%E5 = LHS%E5
      RES%E6 = LHS%E6
      RES%E7 = LHS%E7

      ! Order 2
      RES%E11 = LHS%E11
      RES%E22 = LHS%E22
      RES%E33 = LHS%E33
      RES%E44 = LHS%E44
      RES%E55 = LHS%E55
      RES%E66 = LHS%E66
      RES%E77 = LHS%E77

      ! Order 3
      RES%E111 = LHS%E111
      RES%E222 = LHS%E222
      RES%E333 = LHS%E333
      RES%E444 = LHS%E444
      RES%E555 = LHS%E555
      RES%E666 = LHS%E666
      RES%E777 = LHS%E777

   END FUNCTION DONUMM7N3_SUB_OR_VS

   FUNCTION DONUMM7N3_MUL_OO_VS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(DONUMM7N3), INTENT(IN) :: LHS(:)
      TYPE(DONUMM7N3), INTENT(IN) :: RHS
      TYPE(DONUMM7N3) :: RES(SIZE(LHS,1)) 

      !  Multiplication like function 'LHS*RHS'
      ! Order 3
      RES%E111 = LHS%R*RHS%E111 + LHS%E111*RHS%R +  &
              LHS%E1*RHS%E11 + LHS%E11*RHS%E1
      RES%E222 = LHS%R*RHS%E222 + LHS%E222*RHS%R +  &
              LHS%E2*RHS%E22 + LHS%E22*RHS%E2
      RES%E333 = LHS%R*RHS%E333 + LHS%E333*RHS%R +  &
              LHS%E3*RHS%E33 + LHS%E33*RHS%E3
      RES%E444 = LHS%R*RHS%E444 + LHS%E444*RHS%R +  &
              LHS%E4*RHS%E44 + LHS%E44*RHS%E4
      RES%E555 = LHS%R*RHS%E555 + LHS%E555*RHS%R +  &
              LHS%E5*RHS%E55 + LHS%E55*RHS%E5
      RES%E666 = LHS%R*RHS%E666 + LHS%E666*RHS%R +  &
              LHS%E6*RHS%E66 + LHS%E66*RHS%E6
      RES%E777 = LHS%R*RHS%E777 + LHS%E777*RHS%R +  &
              LHS%E7*RHS%E77 + LHS%E77*RHS%E7
      ! Order 2
      RES%E11 = LHS%R*RHS%E11 + LHS%E11*RHS%R + LHS%E1*RHS%E1
      RES%E22 = LHS%R*RHS%E22 + LHS%E22*RHS%R + LHS%E2*RHS%E2
      RES%E33 = LHS%R*RHS%E33 + LHS%E33*RHS%R + LHS%E3*RHS%E3
      RES%E44 = LHS%R*RHS%E44 + LHS%E44*RHS%R + LHS%E4*RHS%E4
      RES%E55 = LHS%R*RHS%E55 + LHS%E55*RHS%R + LHS%E5*RHS%E5
      RES%E66 = LHS%R*RHS%E66 + LHS%E66*RHS%R + LHS%E6*RHS%E6
      RES%E77 = LHS%R*RHS%E77 + LHS%E77*RHS%R + LHS%E7*RHS%E7
      ! Order 1
      RES%E1 = LHS%R*RHS%E1 + LHS%E1*RHS%R
      RES%E2 = LHS%R*RHS%E2 + LHS%E2*RHS%R
      RES%E3 = LHS%R*RHS%E3 + LHS%E3*RHS%R
      RES%E4 = LHS%R*RHS%E4 + LHS%E4*RHS%R
      RES%E5 = LHS%R*RHS%E5 + LHS%E5*RHS%R
      RES%E6 = LHS%R*RHS%E6 + LHS%E6*RHS%R
      RES%E7 = LHS%R*RHS%E7 + LHS%E7*RHS%R
      ! Order 0
      RES%R = LHS%R*RHS%R

   END FUNCTION DONUMM7N3_MUL_OO_VS

   FUNCTION DONUMM7N3_MUL_RO_VS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS(:)
      TYPE(DONUMM7N3), INTENT(IN) :: RHS
      TYPE(DONUMM7N3) :: RES(SIZE(LHS,1)) 

      ! Multiplication like function 'LHS*RHS'
      !  Real
      RES%R = LHS*RHS%R

      ! Order 1
      RES%E1 = LHS*RHS%E1
      RES%E2 = LHS*RHS%E2
      RES%E3 = LHS*RHS%E3
      RES%E4 = LHS*RHS%E4
      RES%E5 = LHS*RHS%E5
      RES%E6 = LHS*RHS%E6
      RES%E7 = LHS*RHS%E7

      ! Order 2
      RES%E11 = LHS*RHS%E11
      RES%E22 = LHS*RHS%E22
      RES%E33 = LHS*RHS%E33
      RES%E44 = LHS*RHS%E44
      RES%E55 = LHS*RHS%E55
      RES%E66 = LHS*RHS%E66
      RES%E77 = LHS*RHS%E77

      ! Order 3
      RES%E111 = LHS*RHS%E111
      RES%E222 = LHS*RHS%E222
      RES%E333 = LHS*RHS%E333
      RES%E444 = LHS*RHS%E444
      RES%E555 = LHS*RHS%E555
      RES%E666 = LHS*RHS%E666
      RES%E777 = LHS*RHS%E777

   END FUNCTION DONUMM7N3_MUL_RO_VS

   FUNCTION DONUMM7N3_MUL_OR_VS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(DONUMM7N3), INTENT(IN) :: LHS(:)
      REAL(DP), INTENT(IN) :: RHS
      TYPE(DONUMM7N3) :: RES(SIZE(LHS,1)) 

      ! Multiplication like function 'LHS*RHS'
      !  Real
      RES%R = LHS%R*RHS

      ! Order 1
      RES%E1 = LHS%E1*RHS
      RES%E2 = LHS%E2*RHS
      RES%E3 = LHS%E3*RHS
      RES%E4 = LHS%E4*RHS
      RES%E5 = LHS%E5*RHS
      RES%E6 = LHS%E6*RHS
      RES%E7 = LHS%E7*RHS

      ! Order 2
      RES%E11 = LHS%E11*RHS
      RES%E22 = LHS%E22*RHS
      RES%E33 = LHS%E33*RHS
      RES%E44 = LHS%E44*RHS
      RES%E55 = LHS%E55*RHS
      RES%E66 = LHS%E66*RHS
      RES%E77 = LHS%E77*RHS

      ! Order 3
      RES%E111 = LHS%E111*RHS
      RES%E222 = LHS%E222*RHS
      RES%E333 = LHS%E333*RHS
      RES%E444 = LHS%E444*RHS
      RES%E555 = LHS%E555*RHS
      RES%E666 = LHS%E666*RHS
      RES%E777 = LHS%E777*RHS

   END FUNCTION DONUMM7N3_MUL_OR_VS

   FUNCTION DONUMM7N3_ADD_OO_MS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(DONUMM7N3), INTENT(IN) :: LHS(:,:)
      TYPE(DONUMM7N3), INTENT(IN) :: RHS
      TYPE(DONUMM7N3) :: RES(SIZE(LHS,1),SIZE(LHS,2)) 

      ! Addition like function 'LHS + RHS'
      !  Real
      RES%R = LHS%R + RHS%R

      ! Order 1
      RES%E1 = LHS%E1 + RHS%E1
      RES%E2 = LHS%E2 + RHS%E2
      RES%E3 = LHS%E3 + RHS%E3
      RES%E4 = LHS%E4 + RHS%E4
      RES%E5 = LHS%E5 + RHS%E5
      RES%E6 = LHS%E6 + RHS%E6
      RES%E7 = LHS%E7 + RHS%E7

      ! Order 2
      RES%E11 = LHS%E11 + RHS%E11
      RES%E22 = LHS%E22 + RHS%E22
      RES%E33 = LHS%E33 + RHS%E33
      RES%E44 = LHS%E44 + RHS%E44
      RES%E55 = LHS%E55 + RHS%E55
      RES%E66 = LHS%E66 + RHS%E66
      RES%E77 = LHS%E77 + RHS%E77

      ! Order 3
      RES%E111 = LHS%E111 + RHS%E111
      RES%E222 = LHS%E222 + RHS%E222
      RES%E333 = LHS%E333 + RHS%E333
      RES%E444 = LHS%E444 + RHS%E444
      RES%E555 = LHS%E555 + RHS%E555
      RES%E666 = LHS%E666 + RHS%E666
      RES%E777 = LHS%E777 + RHS%E777

   END FUNCTION DONUMM7N3_ADD_OO_MS

   FUNCTION DONUMM7N3_ADD_RO_MS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS(:,:)
      TYPE(DONUMM7N3), INTENT(IN) :: RHS
      TYPE(DONUMM7N3) :: RES(SIZE(LHS,1),SIZE(LHS,2)) 

      ! Addition like function 'LHS + RHS'
      ! Real
      RES%R = LHS + RHS%R

      ! Order 1
      RES%E1 =  + RHS%E1
      RES%E2 =  + RHS%E2
      RES%E3 =  + RHS%E3
      RES%E4 =  + RHS%E4
      RES%E5 =  + RHS%E5
      RES%E6 =  + RHS%E6
      RES%E7 =  + RHS%E7

      ! Order 2
      RES%E11 =  + RHS%E11
      RES%E22 =  + RHS%E22
      RES%E33 =  + RHS%E33
      RES%E44 =  + RHS%E44
      RES%E55 =  + RHS%E55
      RES%E66 =  + RHS%E66
      RES%E77 =  + RHS%E77

      ! Order 3
      RES%E111 =  + RHS%E111
      RES%E222 =  + RHS%E222
      RES%E333 =  + RHS%E333
      RES%E444 =  + RHS%E444
      RES%E555 =  + RHS%E555
      RES%E666 =  + RHS%E666
      RES%E777 =  + RHS%E777

   END FUNCTION DONUMM7N3_ADD_RO_MS

   FUNCTION DONUMM7N3_ADD_OR_MS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(DONUMM7N3), INTENT(IN) :: LHS(:,:)
      REAL(DP), INTENT(IN) :: RHS
      TYPE(DONUMM7N3) :: RES(SIZE(LHS,1),SIZE(LHS,2)) 

      ! Addition like function 'LHS + RHS'
      ! Real
      RES%R = LHS%R + RHS

      ! Order 1
      RES%E1 = LHS%E1
      RES%E2 = LHS%E2
      RES%E3 = LHS%E3
      RES%E4 = LHS%E4
      RES%E5 = LHS%E5
      RES%E6 = LHS%E6
      RES%E7 = LHS%E7

      ! Order 2
      RES%E11 = LHS%E11
      RES%E22 = LHS%E22
      RES%E33 = LHS%E33
      RES%E44 = LHS%E44
      RES%E55 = LHS%E55
      RES%E66 = LHS%E66
      RES%E77 = LHS%E77

      ! Order 3
      RES%E111 = LHS%E111
      RES%E222 = LHS%E222
      RES%E333 = LHS%E333
      RES%E444 = LHS%E444
      RES%E555 = LHS%E555
      RES%E666 = LHS%E666
      RES%E777 = LHS%E777

   END FUNCTION DONUMM7N3_ADD_OR_MS

   FUNCTION DONUMM7N3_SUB_OO_MS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(DONUMM7N3), INTENT(IN) :: LHS(:,:)
      TYPE(DONUMM7N3), INTENT(IN) :: RHS
      TYPE(DONUMM7N3) :: RES(SIZE(LHS,1),SIZE(LHS,2)) 

      ! Addition like function 'LHS - RHS'
      !  Real
      RES%R = LHS%R - RHS%R

      ! Order 1
      RES%E1 = LHS%E1 - RHS%E1
      RES%E2 = LHS%E2 - RHS%E2
      RES%E3 = LHS%E3 - RHS%E3
      RES%E4 = LHS%E4 - RHS%E4
      RES%E5 = LHS%E5 - RHS%E5
      RES%E6 = LHS%E6 - RHS%E6
      RES%E7 = LHS%E7 - RHS%E7

      ! Order 2
      RES%E11 = LHS%E11 - RHS%E11
      RES%E22 = LHS%E22 - RHS%E22
      RES%E33 = LHS%E33 - RHS%E33
      RES%E44 = LHS%E44 - RHS%E44
      RES%E55 = LHS%E55 - RHS%E55
      RES%E66 = LHS%E66 - RHS%E66
      RES%E77 = LHS%E77 - RHS%E77

      ! Order 3
      RES%E111 = LHS%E111 - RHS%E111
      RES%E222 = LHS%E222 - RHS%E222
      RES%E333 = LHS%E333 - RHS%E333
      RES%E444 = LHS%E444 - RHS%E444
      RES%E555 = LHS%E555 - RHS%E555
      RES%E666 = LHS%E666 - RHS%E666
      RES%E777 = LHS%E777 - RHS%E777

   END FUNCTION DONUMM7N3_SUB_OO_MS

   FUNCTION DONUMM7N3_SUB_RO_MS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS(:,:)
      TYPE(DONUMM7N3), INTENT(IN) :: RHS
      TYPE(DONUMM7N3) :: RES(SIZE(LHS,1),SIZE(LHS,2)) 

      ! Addition like function 'LHS - RHS'
      ! Real
      RES%R = LHS - RHS%R

      ! Order 1
      RES%E1 =  - RHS%E1
      RES%E2 =  - RHS%E2
      RES%E3 =  - RHS%E3
      RES%E4 =  - RHS%E4
      RES%E5 =  - RHS%E5
      RES%E6 =  - RHS%E6
      RES%E7 =  - RHS%E7

      ! Order 2
      RES%E11 =  - RHS%E11
      RES%E22 =  - RHS%E22
      RES%E33 =  - RHS%E33
      RES%E44 =  - RHS%E44
      RES%E55 =  - RHS%E55
      RES%E66 =  - RHS%E66
      RES%E77 =  - RHS%E77

      ! Order 3
      RES%E111 =  - RHS%E111
      RES%E222 =  - RHS%E222
      RES%E333 =  - RHS%E333
      RES%E444 =  - RHS%E444
      RES%E555 =  - RHS%E555
      RES%E666 =  - RHS%E666
      RES%E777 =  - RHS%E777

   END FUNCTION DONUMM7N3_SUB_RO_MS

   FUNCTION DONUMM7N3_SUB_OR_MS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(DONUMM7N3), INTENT(IN) :: LHS(:,:)
      REAL(DP), INTENT(IN) :: RHS
      TYPE(DONUMM7N3) :: RES(SIZE(LHS,1),SIZE(LHS,2)) 

      ! Addition like function 'LHS - RHS'
      ! Real
      RES%R = LHS%R - RHS

      ! Order 1
      RES%E1 = LHS%E1
      RES%E2 = LHS%E2
      RES%E3 = LHS%E3
      RES%E4 = LHS%E4
      RES%E5 = LHS%E5
      RES%E6 = LHS%E6
      RES%E7 = LHS%E7

      ! Order 2
      RES%E11 = LHS%E11
      RES%E22 = LHS%E22
      RES%E33 = LHS%E33
      RES%E44 = LHS%E44
      RES%E55 = LHS%E55
      RES%E66 = LHS%E66
      RES%E77 = LHS%E77

      ! Order 3
      RES%E111 = LHS%E111
      RES%E222 = LHS%E222
      RES%E333 = LHS%E333
      RES%E444 = LHS%E444
      RES%E555 = LHS%E555
      RES%E666 = LHS%E666
      RES%E777 = LHS%E777

   END FUNCTION DONUMM7N3_SUB_OR_MS

   FUNCTION DONUMM7N3_MUL_OO_MS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(DONUMM7N3), INTENT(IN) :: LHS(:,:)
      TYPE(DONUMM7N3), INTENT(IN) :: RHS
      TYPE(DONUMM7N3) :: RES(SIZE(LHS,1),SIZE(LHS,2)) 

      !  Multiplication like function 'LHS*RHS'
      ! Order 3
      RES%E111 = LHS%R*RHS%E111 + LHS%E111*RHS%R +  &
              LHS%E1*RHS%E11 + LHS%E11*RHS%E1
      RES%E222 = LHS%R*RHS%E222 + LHS%E222*RHS%R +  &
              LHS%E2*RHS%E22 + LHS%E22*RHS%E2
      RES%E333 = LHS%R*RHS%E333 + LHS%E333*RHS%R +  &
              LHS%E3*RHS%E33 + LHS%E33*RHS%E3
      RES%E444 = LHS%R*RHS%E444 + LHS%E444*RHS%R +  &
              LHS%E4*RHS%E44 + LHS%E44*RHS%E4
      RES%E555 = LHS%R*RHS%E555 + LHS%E555*RHS%R +  &
              LHS%E5*RHS%E55 + LHS%E55*RHS%E5
      RES%E666 = LHS%R*RHS%E666 + LHS%E666*RHS%R +  &
              LHS%E6*RHS%E66 + LHS%E66*RHS%E6
      RES%E777 = LHS%R*RHS%E777 + LHS%E777*RHS%R +  &
              LHS%E7*RHS%E77 + LHS%E77*RHS%E7
      ! Order 2
      RES%E11 = LHS%R*RHS%E11 + LHS%E11*RHS%R + LHS%E1*RHS%E1
      RES%E22 = LHS%R*RHS%E22 + LHS%E22*RHS%R + LHS%E2*RHS%E2
      RES%E33 = LHS%R*RHS%E33 + LHS%E33*RHS%R + LHS%E3*RHS%E3
      RES%E44 = LHS%R*RHS%E44 + LHS%E44*RHS%R + LHS%E4*RHS%E4
      RES%E55 = LHS%R*RHS%E55 + LHS%E55*RHS%R + LHS%E5*RHS%E5
      RES%E66 = LHS%R*RHS%E66 + LHS%E66*RHS%R + LHS%E6*RHS%E6
      RES%E77 = LHS%R*RHS%E77 + LHS%E77*RHS%R + LHS%E7*RHS%E7
      ! Order 1
      RES%E1 = LHS%R*RHS%E1 + LHS%E1*RHS%R
      RES%E2 = LHS%R*RHS%E2 + LHS%E2*RHS%R
      RES%E3 = LHS%R*RHS%E3 + LHS%E3*RHS%R
      RES%E4 = LHS%R*RHS%E4 + LHS%E4*RHS%R
      RES%E5 = LHS%R*RHS%E5 + LHS%E5*RHS%R
      RES%E6 = LHS%R*RHS%E6 + LHS%E6*RHS%R
      RES%E7 = LHS%R*RHS%E7 + LHS%E7*RHS%R
      ! Order 0
      RES%R = LHS%R*RHS%R

   END FUNCTION DONUMM7N3_MUL_OO_MS

   FUNCTION DONUMM7N3_MUL_RO_MS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS(:,:)
      TYPE(DONUMM7N3), INTENT(IN) :: RHS
      TYPE(DONUMM7N3) :: RES(SIZE(LHS,1),SIZE(LHS,2)) 

      ! Multiplication like function 'LHS*RHS'
      !  Real
      RES%R = LHS*RHS%R

      ! Order 1
      RES%E1 = LHS*RHS%E1
      RES%E2 = LHS*RHS%E2
      RES%E3 = LHS*RHS%E3
      RES%E4 = LHS*RHS%E4
      RES%E5 = LHS*RHS%E5
      RES%E6 = LHS*RHS%E6
      RES%E7 = LHS*RHS%E7

      ! Order 2
      RES%E11 = LHS*RHS%E11
      RES%E22 = LHS*RHS%E22
      RES%E33 = LHS*RHS%E33
      RES%E44 = LHS*RHS%E44
      RES%E55 = LHS*RHS%E55
      RES%E66 = LHS*RHS%E66
      RES%E77 = LHS*RHS%E77

      ! Order 3
      RES%E111 = LHS*RHS%E111
      RES%E222 = LHS*RHS%E222
      RES%E333 = LHS*RHS%E333
      RES%E444 = LHS*RHS%E444
      RES%E555 = LHS*RHS%E555
      RES%E666 = LHS*RHS%E666
      RES%E777 = LHS*RHS%E777

   END FUNCTION DONUMM7N3_MUL_RO_MS

   FUNCTION DONUMM7N3_MUL_OR_MS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(DONUMM7N3), INTENT(IN) :: LHS(:,:)
      REAL(DP), INTENT(IN) :: RHS
      TYPE(DONUMM7N3) :: RES(SIZE(LHS,1),SIZE(LHS,2)) 

      ! Multiplication like function 'LHS*RHS'
      !  Real
      RES%R = LHS%R*RHS

      ! Order 1
      RES%E1 = LHS%E1*RHS
      RES%E2 = LHS%E2*RHS
      RES%E3 = LHS%E3*RHS
      RES%E4 = LHS%E4*RHS
      RES%E5 = LHS%E5*RHS
      RES%E6 = LHS%E6*RHS
      RES%E7 = LHS%E7*RHS

      ! Order 2
      RES%E11 = LHS%E11*RHS
      RES%E22 = LHS%E22*RHS
      RES%E33 = LHS%E33*RHS
      RES%E44 = LHS%E44*RHS
      RES%E55 = LHS%E55*RHS
      RES%E66 = LHS%E66*RHS
      RES%E77 = LHS%E77*RHS

      ! Order 3
      RES%E111 = LHS%E111*RHS
      RES%E222 = LHS%E222*RHS
      RES%E333 = LHS%E333*RHS
      RES%E444 = LHS%E444*RHS
      RES%E555 = LHS%E555*RHS
      RES%E666 = LHS%E666*RHS
      RES%E777 = LHS%E777*RHS

   END FUNCTION DONUMM7N3_MUL_OR_MS

   FUNCTION DONUMM7N3_ADD_OO_SV(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(DONUMM7N3), INTENT(IN) :: LHS
      TYPE(DONUMM7N3), INTENT(IN) :: RHS(:)
      TYPE(DONUMM7N3) :: RES(SIZE(RHS,1)) 

      ! Addition like function 'LHS + RHS'
      !  Real
      RES%R = LHS%R + RHS%R

      ! Order 1
      RES%E1 = LHS%E1 + RHS%E1
      RES%E2 = LHS%E2 + RHS%E2
      RES%E3 = LHS%E3 + RHS%E3
      RES%E4 = LHS%E4 + RHS%E4
      RES%E5 = LHS%E5 + RHS%E5
      RES%E6 = LHS%E6 + RHS%E6
      RES%E7 = LHS%E7 + RHS%E7

      ! Order 2
      RES%E11 = LHS%E11 + RHS%E11
      RES%E22 = LHS%E22 + RHS%E22
      RES%E33 = LHS%E33 + RHS%E33
      RES%E44 = LHS%E44 + RHS%E44
      RES%E55 = LHS%E55 + RHS%E55
      RES%E66 = LHS%E66 + RHS%E66
      RES%E77 = LHS%E77 + RHS%E77

      ! Order 3
      RES%E111 = LHS%E111 + RHS%E111
      RES%E222 = LHS%E222 + RHS%E222
      RES%E333 = LHS%E333 + RHS%E333
      RES%E444 = LHS%E444 + RHS%E444
      RES%E555 = LHS%E555 + RHS%E555
      RES%E666 = LHS%E666 + RHS%E666
      RES%E777 = LHS%E777 + RHS%E777

   END FUNCTION DONUMM7N3_ADD_OO_SV

   FUNCTION DONUMM7N3_ADD_RO_SV(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS
      TYPE(DONUMM7N3), INTENT(IN) :: RHS(:)
      TYPE(DONUMM7N3) :: RES(SIZE(RHS,1)) 

      ! Addition like function 'LHS + RHS'
      ! Real
      RES%R = LHS + RHS%R

      ! Order 1
      RES%E1 =  + RHS%E1
      RES%E2 =  + RHS%E2
      RES%E3 =  + RHS%E3
      RES%E4 =  + RHS%E4
      RES%E5 =  + RHS%E5
      RES%E6 =  + RHS%E6
      RES%E7 =  + RHS%E7

      ! Order 2
      RES%E11 =  + RHS%E11
      RES%E22 =  + RHS%E22
      RES%E33 =  + RHS%E33
      RES%E44 =  + RHS%E44
      RES%E55 =  + RHS%E55
      RES%E66 =  + RHS%E66
      RES%E77 =  + RHS%E77

      ! Order 3
      RES%E111 =  + RHS%E111
      RES%E222 =  + RHS%E222
      RES%E333 =  + RHS%E333
      RES%E444 =  + RHS%E444
      RES%E555 =  + RHS%E555
      RES%E666 =  + RHS%E666
      RES%E777 =  + RHS%E777

   END FUNCTION DONUMM7N3_ADD_RO_SV

   FUNCTION DONUMM7N3_ADD_OR_SV(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(DONUMM7N3), INTENT(IN) :: LHS
      REAL(DP), INTENT(IN) :: RHS(:)
      TYPE(DONUMM7N3) :: RES(SIZE(RHS,1)) 

      ! Addition like function 'LHS + RHS'
      ! Real
      RES%R = LHS%R + RHS

      ! Order 1
      RES%E1 = LHS%E1
      RES%E2 = LHS%E2
      RES%E3 = LHS%E3
      RES%E4 = LHS%E4
      RES%E5 = LHS%E5
      RES%E6 = LHS%E6
      RES%E7 = LHS%E7

      ! Order 2
      RES%E11 = LHS%E11
      RES%E22 = LHS%E22
      RES%E33 = LHS%E33
      RES%E44 = LHS%E44
      RES%E55 = LHS%E55
      RES%E66 = LHS%E66
      RES%E77 = LHS%E77

      ! Order 3
      RES%E111 = LHS%E111
      RES%E222 = LHS%E222
      RES%E333 = LHS%E333
      RES%E444 = LHS%E444
      RES%E555 = LHS%E555
      RES%E666 = LHS%E666
      RES%E777 = LHS%E777

   END FUNCTION DONUMM7N3_ADD_OR_SV

   FUNCTION DONUMM7N3_SUB_OO_SV(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(DONUMM7N3), INTENT(IN) :: LHS
      TYPE(DONUMM7N3), INTENT(IN) :: RHS(:)
      TYPE(DONUMM7N3) :: RES(SIZE(RHS,1)) 

      ! Addition like function 'LHS - RHS'
      !  Real
      RES%R = LHS%R - RHS%R

      ! Order 1
      RES%E1 = LHS%E1 - RHS%E1
      RES%E2 = LHS%E2 - RHS%E2
      RES%E3 = LHS%E3 - RHS%E3
      RES%E4 = LHS%E4 - RHS%E4
      RES%E5 = LHS%E5 - RHS%E5
      RES%E6 = LHS%E6 - RHS%E6
      RES%E7 = LHS%E7 - RHS%E7

      ! Order 2
      RES%E11 = LHS%E11 - RHS%E11
      RES%E22 = LHS%E22 - RHS%E22
      RES%E33 = LHS%E33 - RHS%E33
      RES%E44 = LHS%E44 - RHS%E44
      RES%E55 = LHS%E55 - RHS%E55
      RES%E66 = LHS%E66 - RHS%E66
      RES%E77 = LHS%E77 - RHS%E77

      ! Order 3
      RES%E111 = LHS%E111 - RHS%E111
      RES%E222 = LHS%E222 - RHS%E222
      RES%E333 = LHS%E333 - RHS%E333
      RES%E444 = LHS%E444 - RHS%E444
      RES%E555 = LHS%E555 - RHS%E555
      RES%E666 = LHS%E666 - RHS%E666
      RES%E777 = LHS%E777 - RHS%E777

   END FUNCTION DONUMM7N3_SUB_OO_SV

   FUNCTION DONUMM7N3_SUB_RO_SV(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS
      TYPE(DONUMM7N3), INTENT(IN) :: RHS(:)
      TYPE(DONUMM7N3) :: RES(SIZE(RHS,1)) 

      ! Addition like function 'LHS - RHS'
      ! Real
      RES%R = LHS - RHS%R

      ! Order 1
      RES%E1 =  - RHS%E1
      RES%E2 =  - RHS%E2
      RES%E3 =  - RHS%E3
      RES%E4 =  - RHS%E4
      RES%E5 =  - RHS%E5
      RES%E6 =  - RHS%E6
      RES%E7 =  - RHS%E7

      ! Order 2
      RES%E11 =  - RHS%E11
      RES%E22 =  - RHS%E22
      RES%E33 =  - RHS%E33
      RES%E44 =  - RHS%E44
      RES%E55 =  - RHS%E55
      RES%E66 =  - RHS%E66
      RES%E77 =  - RHS%E77

      ! Order 3
      RES%E111 =  - RHS%E111
      RES%E222 =  - RHS%E222
      RES%E333 =  - RHS%E333
      RES%E444 =  - RHS%E444
      RES%E555 =  - RHS%E555
      RES%E666 =  - RHS%E666
      RES%E777 =  - RHS%E777

   END FUNCTION DONUMM7N3_SUB_RO_SV

   FUNCTION DONUMM7N3_SUB_OR_SV(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(DONUMM7N3), INTENT(IN) :: LHS
      REAL(DP), INTENT(IN) :: RHS(:)
      TYPE(DONUMM7N3) :: RES(SIZE(RHS,1)) 

      ! Addition like function 'LHS - RHS'
      ! Real
      RES%R = LHS%R - RHS

      ! Order 1
      RES%E1 = LHS%E1
      RES%E2 = LHS%E2
      RES%E3 = LHS%E3
      RES%E4 = LHS%E4
      RES%E5 = LHS%E5
      RES%E6 = LHS%E6
      RES%E7 = LHS%E7

      ! Order 2
      RES%E11 = LHS%E11
      RES%E22 = LHS%E22
      RES%E33 = LHS%E33
      RES%E44 = LHS%E44
      RES%E55 = LHS%E55
      RES%E66 = LHS%E66
      RES%E77 = LHS%E77

      ! Order 3
      RES%E111 = LHS%E111
      RES%E222 = LHS%E222
      RES%E333 = LHS%E333
      RES%E444 = LHS%E444
      RES%E555 = LHS%E555
      RES%E666 = LHS%E666
      RES%E777 = LHS%E777

   END FUNCTION DONUMM7N3_SUB_OR_SV

   FUNCTION DONUMM7N3_MUL_OO_SV(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(DONUMM7N3), INTENT(IN) :: LHS
      TYPE(DONUMM7N3), INTENT(IN) :: RHS(:)
      TYPE(DONUMM7N3) :: RES(SIZE(RHS,1)) 

      !  Multiplication like function 'LHS*RHS'
      ! Order 3
      RES%E111 = LHS%R*RHS%E111 + LHS%E111*RHS%R +  &
              LHS%E1*RHS%E11 + LHS%E11*RHS%E1
      RES%E222 = LHS%R*RHS%E222 + LHS%E222*RHS%R +  &
              LHS%E2*RHS%E22 + LHS%E22*RHS%E2
      RES%E333 = LHS%R*RHS%E333 + LHS%E333*RHS%R +  &
              LHS%E3*RHS%E33 + LHS%E33*RHS%E3
      RES%E444 = LHS%R*RHS%E444 + LHS%E444*RHS%R +  &
              LHS%E4*RHS%E44 + LHS%E44*RHS%E4
      RES%E555 = LHS%R*RHS%E555 + LHS%E555*RHS%R +  &
              LHS%E5*RHS%E55 + LHS%E55*RHS%E5
      RES%E666 = LHS%R*RHS%E666 + LHS%E666*RHS%R +  &
              LHS%E6*RHS%E66 + LHS%E66*RHS%E6
      RES%E777 = LHS%R*RHS%E777 + LHS%E777*RHS%R +  &
              LHS%E7*RHS%E77 + LHS%E77*RHS%E7
      ! Order 2
      RES%E11 = LHS%R*RHS%E11 + LHS%E11*RHS%R + LHS%E1*RHS%E1
      RES%E22 = LHS%R*RHS%E22 + LHS%E22*RHS%R + LHS%E2*RHS%E2
      RES%E33 = LHS%R*RHS%E33 + LHS%E33*RHS%R + LHS%E3*RHS%E3
      RES%E44 = LHS%R*RHS%E44 + LHS%E44*RHS%R + LHS%E4*RHS%E4
      RES%E55 = LHS%R*RHS%E55 + LHS%E55*RHS%R + LHS%E5*RHS%E5
      RES%E66 = LHS%R*RHS%E66 + LHS%E66*RHS%R + LHS%E6*RHS%E6
      RES%E77 = LHS%R*RHS%E77 + LHS%E77*RHS%R + LHS%E7*RHS%E7
      ! Order 1
      RES%E1 = LHS%R*RHS%E1 + LHS%E1*RHS%R
      RES%E2 = LHS%R*RHS%E2 + LHS%E2*RHS%R
      RES%E3 = LHS%R*RHS%E3 + LHS%E3*RHS%R
      RES%E4 = LHS%R*RHS%E4 + LHS%E4*RHS%R
      RES%E5 = LHS%R*RHS%E5 + LHS%E5*RHS%R
      RES%E6 = LHS%R*RHS%E6 + LHS%E6*RHS%R
      RES%E7 = LHS%R*RHS%E7 + LHS%E7*RHS%R
      ! Order 0
      RES%R = LHS%R*RHS%R

   END FUNCTION DONUMM7N3_MUL_OO_SV

   FUNCTION DONUMM7N3_MUL_RO_SV(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS
      TYPE(DONUMM7N3), INTENT(IN) :: RHS(:)
      TYPE(DONUMM7N3) :: RES(SIZE(RHS,1)) 

      ! Multiplication like function 'LHS*RHS'
      !  Real
      RES%R = LHS*RHS%R

      ! Order 1
      RES%E1 = LHS*RHS%E1
      RES%E2 = LHS*RHS%E2
      RES%E3 = LHS*RHS%E3
      RES%E4 = LHS*RHS%E4
      RES%E5 = LHS*RHS%E5
      RES%E6 = LHS*RHS%E6
      RES%E7 = LHS*RHS%E7

      ! Order 2
      RES%E11 = LHS*RHS%E11
      RES%E22 = LHS*RHS%E22
      RES%E33 = LHS*RHS%E33
      RES%E44 = LHS*RHS%E44
      RES%E55 = LHS*RHS%E55
      RES%E66 = LHS*RHS%E66
      RES%E77 = LHS*RHS%E77

      ! Order 3
      RES%E111 = LHS*RHS%E111
      RES%E222 = LHS*RHS%E222
      RES%E333 = LHS*RHS%E333
      RES%E444 = LHS*RHS%E444
      RES%E555 = LHS*RHS%E555
      RES%E666 = LHS*RHS%E666
      RES%E777 = LHS*RHS%E777

   END FUNCTION DONUMM7N3_MUL_RO_SV

   FUNCTION DONUMM7N3_MUL_OR_SV(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(DONUMM7N3), INTENT(IN) :: LHS
      REAL(DP), INTENT(IN) :: RHS(:)
      TYPE(DONUMM7N3) :: RES(SIZE(RHS,1)) 

      ! Multiplication like function 'LHS*RHS'
      !  Real
      RES%R = LHS%R*RHS

      ! Order 1
      RES%E1 = LHS%E1*RHS
      RES%E2 = LHS%E2*RHS
      RES%E3 = LHS%E3*RHS
      RES%E4 = LHS%E4*RHS
      RES%E5 = LHS%E5*RHS
      RES%E6 = LHS%E6*RHS
      RES%E7 = LHS%E7*RHS

      ! Order 2
      RES%E11 = LHS%E11*RHS
      RES%E22 = LHS%E22*RHS
      RES%E33 = LHS%E33*RHS
      RES%E44 = LHS%E44*RHS
      RES%E55 = LHS%E55*RHS
      RES%E66 = LHS%E66*RHS
      RES%E77 = LHS%E77*RHS

      ! Order 3
      RES%E111 = LHS%E111*RHS
      RES%E222 = LHS%E222*RHS
      RES%E333 = LHS%E333*RHS
      RES%E444 = LHS%E444*RHS
      RES%E555 = LHS%E555*RHS
      RES%E666 = LHS%E666*RHS
      RES%E777 = LHS%E777*RHS

   END FUNCTION DONUMM7N3_MUL_OR_SV

   FUNCTION DONUMM7N3_ADD_OO_SM(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(DONUMM7N3), INTENT(IN) :: LHS
      TYPE(DONUMM7N3), INTENT(IN) :: RHS(:,:)
      TYPE(DONUMM7N3) :: RES(SIZE(RHS,1),SIZE(RHS,2)) 

      ! Addition like function 'LHS + RHS'
      !  Real
      RES%R = LHS%R + RHS%R

      ! Order 1
      RES%E1 = LHS%E1 + RHS%E1
      RES%E2 = LHS%E2 + RHS%E2
      RES%E3 = LHS%E3 + RHS%E3
      RES%E4 = LHS%E4 + RHS%E4
      RES%E5 = LHS%E5 + RHS%E5
      RES%E6 = LHS%E6 + RHS%E6
      RES%E7 = LHS%E7 + RHS%E7

      ! Order 2
      RES%E11 = LHS%E11 + RHS%E11
      RES%E22 = LHS%E22 + RHS%E22
      RES%E33 = LHS%E33 + RHS%E33
      RES%E44 = LHS%E44 + RHS%E44
      RES%E55 = LHS%E55 + RHS%E55
      RES%E66 = LHS%E66 + RHS%E66
      RES%E77 = LHS%E77 + RHS%E77

      ! Order 3
      RES%E111 = LHS%E111 + RHS%E111
      RES%E222 = LHS%E222 + RHS%E222
      RES%E333 = LHS%E333 + RHS%E333
      RES%E444 = LHS%E444 + RHS%E444
      RES%E555 = LHS%E555 + RHS%E555
      RES%E666 = LHS%E666 + RHS%E666
      RES%E777 = LHS%E777 + RHS%E777

   END FUNCTION DONUMM7N3_ADD_OO_SM

   FUNCTION DONUMM7N3_ADD_RO_SM(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS
      TYPE(DONUMM7N3), INTENT(IN) :: RHS(:,:)
      TYPE(DONUMM7N3) :: RES(SIZE(RHS,1),SIZE(RHS,2)) 

      ! Addition like function 'LHS + RHS'
      ! Real
      RES%R = LHS + RHS%R

      ! Order 1
      RES%E1 =  + RHS%E1
      RES%E2 =  + RHS%E2
      RES%E3 =  + RHS%E3
      RES%E4 =  + RHS%E4
      RES%E5 =  + RHS%E5
      RES%E6 =  + RHS%E6
      RES%E7 =  + RHS%E7

      ! Order 2
      RES%E11 =  + RHS%E11
      RES%E22 =  + RHS%E22
      RES%E33 =  + RHS%E33
      RES%E44 =  + RHS%E44
      RES%E55 =  + RHS%E55
      RES%E66 =  + RHS%E66
      RES%E77 =  + RHS%E77

      ! Order 3
      RES%E111 =  + RHS%E111
      RES%E222 =  + RHS%E222
      RES%E333 =  + RHS%E333
      RES%E444 =  + RHS%E444
      RES%E555 =  + RHS%E555
      RES%E666 =  + RHS%E666
      RES%E777 =  + RHS%E777

   END FUNCTION DONUMM7N3_ADD_RO_SM

   FUNCTION DONUMM7N3_ADD_OR_SM(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(DONUMM7N3), INTENT(IN) :: LHS
      REAL(DP), INTENT(IN) :: RHS(:,:)
      TYPE(DONUMM7N3) :: RES(SIZE(RHS,1),SIZE(RHS,2)) 

      ! Addition like function 'LHS + RHS'
      ! Real
      RES%R = LHS%R + RHS

      ! Order 1
      RES%E1 = LHS%E1
      RES%E2 = LHS%E2
      RES%E3 = LHS%E3
      RES%E4 = LHS%E4
      RES%E5 = LHS%E5
      RES%E6 = LHS%E6
      RES%E7 = LHS%E7

      ! Order 2
      RES%E11 = LHS%E11
      RES%E22 = LHS%E22
      RES%E33 = LHS%E33
      RES%E44 = LHS%E44
      RES%E55 = LHS%E55
      RES%E66 = LHS%E66
      RES%E77 = LHS%E77

      ! Order 3
      RES%E111 = LHS%E111
      RES%E222 = LHS%E222
      RES%E333 = LHS%E333
      RES%E444 = LHS%E444
      RES%E555 = LHS%E555
      RES%E666 = LHS%E666
      RES%E777 = LHS%E777

   END FUNCTION DONUMM7N3_ADD_OR_SM

   FUNCTION DONUMM7N3_SUB_OO_SM(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(DONUMM7N3), INTENT(IN) :: LHS
      TYPE(DONUMM7N3), INTENT(IN) :: RHS(:,:)
      TYPE(DONUMM7N3) :: RES(SIZE(RHS,1),SIZE(RHS,2)) 

      ! Addition like function 'LHS - RHS'
      !  Real
      RES%R = LHS%R - RHS%R

      ! Order 1
      RES%E1 = LHS%E1 - RHS%E1
      RES%E2 = LHS%E2 - RHS%E2
      RES%E3 = LHS%E3 - RHS%E3
      RES%E4 = LHS%E4 - RHS%E4
      RES%E5 = LHS%E5 - RHS%E5
      RES%E6 = LHS%E6 - RHS%E6
      RES%E7 = LHS%E7 - RHS%E7

      ! Order 2
      RES%E11 = LHS%E11 - RHS%E11
      RES%E22 = LHS%E22 - RHS%E22
      RES%E33 = LHS%E33 - RHS%E33
      RES%E44 = LHS%E44 - RHS%E44
      RES%E55 = LHS%E55 - RHS%E55
      RES%E66 = LHS%E66 - RHS%E66
      RES%E77 = LHS%E77 - RHS%E77

      ! Order 3
      RES%E111 = LHS%E111 - RHS%E111
      RES%E222 = LHS%E222 - RHS%E222
      RES%E333 = LHS%E333 - RHS%E333
      RES%E444 = LHS%E444 - RHS%E444
      RES%E555 = LHS%E555 - RHS%E555
      RES%E666 = LHS%E666 - RHS%E666
      RES%E777 = LHS%E777 - RHS%E777

   END FUNCTION DONUMM7N3_SUB_OO_SM

   FUNCTION DONUMM7N3_SUB_RO_SM(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS
      TYPE(DONUMM7N3), INTENT(IN) :: RHS(:,:)
      TYPE(DONUMM7N3) :: RES(SIZE(RHS,1),SIZE(RHS,2)) 

      ! Addition like function 'LHS - RHS'
      ! Real
      RES%R = LHS - RHS%R

      ! Order 1
      RES%E1 =  - RHS%E1
      RES%E2 =  - RHS%E2
      RES%E3 =  - RHS%E3
      RES%E4 =  - RHS%E4
      RES%E5 =  - RHS%E5
      RES%E6 =  - RHS%E6
      RES%E7 =  - RHS%E7

      ! Order 2
      RES%E11 =  - RHS%E11
      RES%E22 =  - RHS%E22
      RES%E33 =  - RHS%E33
      RES%E44 =  - RHS%E44
      RES%E55 =  - RHS%E55
      RES%E66 =  - RHS%E66
      RES%E77 =  - RHS%E77

      ! Order 3
      RES%E111 =  - RHS%E111
      RES%E222 =  - RHS%E222
      RES%E333 =  - RHS%E333
      RES%E444 =  - RHS%E444
      RES%E555 =  - RHS%E555
      RES%E666 =  - RHS%E666
      RES%E777 =  - RHS%E777

   END FUNCTION DONUMM7N3_SUB_RO_SM

   FUNCTION DONUMM7N3_SUB_OR_SM(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(DONUMM7N3), INTENT(IN) :: LHS
      REAL(DP), INTENT(IN) :: RHS(:,:)
      TYPE(DONUMM7N3) :: RES(SIZE(RHS,1),SIZE(RHS,2)) 

      ! Addition like function 'LHS - RHS'
      ! Real
      RES%R = LHS%R - RHS

      ! Order 1
      RES%E1 = LHS%E1
      RES%E2 = LHS%E2
      RES%E3 = LHS%E3
      RES%E4 = LHS%E4
      RES%E5 = LHS%E5
      RES%E6 = LHS%E6
      RES%E7 = LHS%E7

      ! Order 2
      RES%E11 = LHS%E11
      RES%E22 = LHS%E22
      RES%E33 = LHS%E33
      RES%E44 = LHS%E44
      RES%E55 = LHS%E55
      RES%E66 = LHS%E66
      RES%E77 = LHS%E77

      ! Order 3
      RES%E111 = LHS%E111
      RES%E222 = LHS%E222
      RES%E333 = LHS%E333
      RES%E444 = LHS%E444
      RES%E555 = LHS%E555
      RES%E666 = LHS%E666
      RES%E777 = LHS%E777

   END FUNCTION DONUMM7N3_SUB_OR_SM

   FUNCTION DONUMM7N3_MUL_OO_SM(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(DONUMM7N3), INTENT(IN) :: LHS
      TYPE(DONUMM7N3), INTENT(IN) :: RHS(:,:)
      TYPE(DONUMM7N3) :: RES(SIZE(RHS,1),SIZE(RHS,2)) 

      !  Multiplication like function 'LHS*RHS'
      ! Order 3
      RES%E111 = LHS%R*RHS%E111 + LHS%E111*RHS%R +  &
              LHS%E1*RHS%E11 + LHS%E11*RHS%E1
      RES%E222 = LHS%R*RHS%E222 + LHS%E222*RHS%R +  &
              LHS%E2*RHS%E22 + LHS%E22*RHS%E2
      RES%E333 = LHS%R*RHS%E333 + LHS%E333*RHS%R +  &
              LHS%E3*RHS%E33 + LHS%E33*RHS%E3
      RES%E444 = LHS%R*RHS%E444 + LHS%E444*RHS%R +  &
              LHS%E4*RHS%E44 + LHS%E44*RHS%E4
      RES%E555 = LHS%R*RHS%E555 + LHS%E555*RHS%R +  &
              LHS%E5*RHS%E55 + LHS%E55*RHS%E5
      RES%E666 = LHS%R*RHS%E666 + LHS%E666*RHS%R +  &
              LHS%E6*RHS%E66 + LHS%E66*RHS%E6
      RES%E777 = LHS%R*RHS%E777 + LHS%E777*RHS%R +  &
              LHS%E7*RHS%E77 + LHS%E77*RHS%E7
      ! Order 2
      RES%E11 = LHS%R*RHS%E11 + LHS%E11*RHS%R + LHS%E1*RHS%E1
      RES%E22 = LHS%R*RHS%E22 + LHS%E22*RHS%R + LHS%E2*RHS%E2
      RES%E33 = LHS%R*RHS%E33 + LHS%E33*RHS%R + LHS%E3*RHS%E3
      RES%E44 = LHS%R*RHS%E44 + LHS%E44*RHS%R + LHS%E4*RHS%E4
      RES%E55 = LHS%R*RHS%E55 + LHS%E55*RHS%R + LHS%E5*RHS%E5
      RES%E66 = LHS%R*RHS%E66 + LHS%E66*RHS%R + LHS%E6*RHS%E6
      RES%E77 = LHS%R*RHS%E77 + LHS%E77*RHS%R + LHS%E7*RHS%E7
      ! Order 1
      RES%E1 = LHS%R*RHS%E1 + LHS%E1*RHS%R
      RES%E2 = LHS%R*RHS%E2 + LHS%E2*RHS%R
      RES%E3 = LHS%R*RHS%E3 + LHS%E3*RHS%R
      RES%E4 = LHS%R*RHS%E4 + LHS%E4*RHS%R
      RES%E5 = LHS%R*RHS%E5 + LHS%E5*RHS%R
      RES%E6 = LHS%R*RHS%E6 + LHS%E6*RHS%R
      RES%E7 = LHS%R*RHS%E7 + LHS%E7*RHS%R
      ! Order 0
      RES%R = LHS%R*RHS%R

   END FUNCTION DONUMM7N3_MUL_OO_SM

   FUNCTION DONUMM7N3_MUL_RO_SM(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS
      TYPE(DONUMM7N3), INTENT(IN) :: RHS(:,:)
      TYPE(DONUMM7N3) :: RES(SIZE(RHS,1),SIZE(RHS,2)) 

      ! Multiplication like function 'LHS*RHS'
      !  Real
      RES%R = LHS*RHS%R

      ! Order 1
      RES%E1 = LHS*RHS%E1
      RES%E2 = LHS*RHS%E2
      RES%E3 = LHS*RHS%E3
      RES%E4 = LHS*RHS%E4
      RES%E5 = LHS*RHS%E5
      RES%E6 = LHS*RHS%E6
      RES%E7 = LHS*RHS%E7

      ! Order 2
      RES%E11 = LHS*RHS%E11
      RES%E22 = LHS*RHS%E22
      RES%E33 = LHS*RHS%E33
      RES%E44 = LHS*RHS%E44
      RES%E55 = LHS*RHS%E55
      RES%E66 = LHS*RHS%E66
      RES%E77 = LHS*RHS%E77

      ! Order 3
      RES%E111 = LHS*RHS%E111
      RES%E222 = LHS*RHS%E222
      RES%E333 = LHS*RHS%E333
      RES%E444 = LHS*RHS%E444
      RES%E555 = LHS*RHS%E555
      RES%E666 = LHS*RHS%E666
      RES%E777 = LHS*RHS%E777

   END FUNCTION DONUMM7N3_MUL_RO_SM

   FUNCTION DONUMM7N3_MUL_OR_SM(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(DONUMM7N3), INTENT(IN) :: LHS
      REAL(DP), INTENT(IN) :: RHS(:,:)
      TYPE(DONUMM7N3) :: RES(SIZE(RHS,1),SIZE(RHS,2)) 

      ! Multiplication like function 'LHS*RHS'
      !  Real
      RES%R = LHS%R*RHS

      ! Order 1
      RES%E1 = LHS%E1*RHS
      RES%E2 = LHS%E2*RHS
      RES%E3 = LHS%E3*RHS
      RES%E4 = LHS%E4*RHS
      RES%E5 = LHS%E5*RHS
      RES%E6 = LHS%E6*RHS
      RES%E7 = LHS%E7*RHS

      ! Order 2
      RES%E11 = LHS%E11*RHS
      RES%E22 = LHS%E22*RHS
      RES%E33 = LHS%E33*RHS
      RES%E44 = LHS%E44*RHS
      RES%E55 = LHS%E55*RHS
      RES%E66 = LHS%E66*RHS
      RES%E77 = LHS%E77*RHS

      ! Order 3
      RES%E111 = LHS%E111*RHS
      RES%E222 = LHS%E222*RHS
      RES%E333 = LHS%E333*RHS
      RES%E444 = LHS%E444*RHS
      RES%E555 = LHS%E555*RHS
      RES%E666 = LHS%E666*RHS
      RES%E777 = LHS%E777*RHS

   END FUNCTION DONUMM7N3_MUL_OR_SM

ELEMENTAL    FUNCTION DONUMM7N3_GEM_OOO(A,B,C)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(DONUMM7N3), INTENT(IN) :: A 
      TYPE(DONUMM7N3), INTENT(IN) :: B 
      TYPE(DONUMM7N3), INTENT(IN) :: C 
      TYPE(DONUMM7N3) :: RES 

      !  General multiplication like function 'A*B + C'

      ! Order 0
      RES%R = C%R + A%R*B%R

      ! Order 1
      RES%E1 = C%E1 + A%R*B%E1 + A%E1*B%R
      RES%E2 = C%E2 + A%R*B%E2 + A%E2*B%R
      RES%E3 = C%E3 + A%R*B%E3 + A%E3*B%R
      RES%E4 = C%E4 + A%R*B%E4 + A%E4*B%R
      RES%E5 = C%E5 + A%R*B%E5 + A%E5*B%R
      RES%E6 = C%E6 + A%R*B%E6 + A%E6*B%R
      RES%E7 = C%E7 + A%R*B%E7 + A%E7*B%R

      ! Order 2
      RES%E11 = C%E11 + A%R*B%E11 + A%E11*B%R + A%E1*B%E1
      RES%E22 = C%E22 + A%R*B%E22 + A%E22*B%R + A%E2*B%E2
      RES%E33 = C%E33 + A%R*B%E33 + A%E33*B%R + A%E3*B%E3
      RES%E44 = C%E44 + A%R*B%E44 + A%E44*B%R + A%E4*B%E4
      RES%E55 = C%E55 + A%R*B%E55 + A%E55*B%R + A%E5*B%E5
      RES%E66 = C%E66 + A%R*B%E66 + A%E66*B%R + A%E6*B%E6
      RES%E77 = C%E77 + A%R*B%E77 + A%E77*B%R + A%E7*B%E7

      ! Order 3
      RES%E111 = C%E111 + A%R*B%E111 + A%E111*B%R + A%E1*B%E11 &
               + A%E11*B%E1
      RES%E222 = C%E222 + A%R*B%E222 + A%E222*B%R + A%E2*B%E22 &
               + A%E22*B%E2
      RES%E333 = C%E333 + A%R*B%E333 + A%E333*B%R + A%E3*B%E33 &
               + A%E33*B%E3
      RES%E444 = C%E444 + A%R*B%E444 + A%E444*B%R + A%E4*B%E44 &
               + A%E44*B%E4
      RES%E555 = C%E555 + A%R*B%E555 + A%E555*B%R + A%E5*B%E55 &
               + A%E55*B%E5
      RES%E666 = C%E666 + A%R*B%E666 + A%E666*B%R + A%E6*B%E66 &
               + A%E66*B%E6
      RES%E777 = C%E777 + A%R*B%E777 + A%E777*B%R + A%E7*B%E77 &
               + A%E77*B%E7

   END FUNCTION DONUMM7N3_GEM_OOO

ELEMENTAL    FUNCTION DONUMM7N3_GEM_ROO(A,B,C)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: A 
      TYPE(DONUMM7N3), INTENT(IN) :: B 
      TYPE(DONUMM7N3), INTENT(IN) :: C 
      TYPE(DONUMM7N3) :: RES 

      !  General multiplication like function 'A*B + C'
      ! Order 3
      RES%E111 = C%E111 + A*B%E111
      RES%E222 = C%E222 + A*B%E222
      RES%E333 = C%E333 + A*B%E333
      RES%E444 = C%E444 + A*B%E444
      RES%E555 = C%E555 + A*B%E555
      RES%E666 = C%E666 + A*B%E666
      RES%E777 = C%E777 + A*B%E777
      ! Order 2
      RES%E11 = C%E11 + A*B%E11
      RES%E22 = C%E22 + A*B%E22
      RES%E33 = C%E33 + A*B%E33
      RES%E44 = C%E44 + A*B%E44
      RES%E55 = C%E55 + A*B%E55
      RES%E66 = C%E66 + A*B%E66
      RES%E77 = C%E77 + A*B%E77
      ! Order 1
      RES%E1 = C%E1 + A*B%E1
      RES%E2 = C%E2 + A*B%E2
      RES%E3 = C%E3 + A*B%E3
      RES%E4 = C%E4 + A*B%E4
      RES%E5 = C%E5 + A*B%E5
      RES%E6 = C%E6 + A*B%E6
      RES%E7 = C%E7 + A*B%E7
      ! Order 0
      RES%R = C%R + A*B%R

   END FUNCTION DONUMM7N3_GEM_ROO

ELEMENTAL    FUNCTION DONUMM7N3_GEM_ORO(A,B,C)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(DONUMM7N3), INTENT(IN) :: A 
      REAL(DP), INTENT(IN) :: B 
      TYPE(DONUMM7N3), INTENT(IN) :: C 
      TYPE(DONUMM7N3) :: RES 

      !  General multiplication like function 'A*B + C'

      ! Order 0
      RES%R = C%R + A%R*B

      ! Order 1
      RES%E1 = C%E1 + A%E1*B
      RES%E2 = C%E2 + A%E2*B
      RES%E3 = C%E3 + A%E3*B
      RES%E4 = C%E4 + A%E4*B
      RES%E5 = C%E5 + A%E5*B
      RES%E6 = C%E6 + A%E6*B
      RES%E7 = C%E7 + A%E7*B

      ! Order 2
      RES%E11 = C%E11 + A%E11*B
      RES%E22 = C%E22 + A%E22*B
      RES%E33 = C%E33 + A%E33*B
      RES%E44 = C%E44 + A%E44*B
      RES%E55 = C%E55 + A%E55*B
      RES%E66 = C%E66 + A%E66*B
      RES%E77 = C%E77 + A%E77*B

      ! Order 3
      RES%E111 = C%E111 + A%E111*B
      RES%E222 = C%E222 + A%E222*B
      RES%E333 = C%E333 + A%E333*B
      RES%E444 = C%E444 + A%E444*B
      RES%E555 = C%E555 + A%E555*B
      RES%E666 = C%E666 + A%E666*B
      RES%E777 = C%E777 + A%E777*B

   END FUNCTION DONUMM7N3_GEM_ORO

   FUNCTION DONUMM7N3_MATMUL_DONUMM7N3(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(DONUMM7N3), INTENT(IN) :: LHS(:,:)
      TYPE(DONUMM7N3), INTENT(IN) :: RHS(:,:)
      TYPE(DONUMM7N3) :: RES(SIZE(LHS,1),SIZE(RHS,2))

      !  Multiplication like function 'MATMUL(lhs,rhs)'
      ! Order 3
      res%E111 = MATMUL(lhs%R,rhs%E111) + MATMUL(lhs%E111,rhs%R) +  &
              MATMUL(lhs%E1,rhs%E11) + MATMUL(lhs%E11,rhs%E1)
      res%E222 = MATMUL(lhs%R,rhs%E222) + MATMUL(lhs%E222,rhs%R) +  &
              MATMUL(lhs%E2,rhs%E22) + MATMUL(lhs%E22,rhs%E2)
      res%E333 = MATMUL(lhs%R,rhs%E333) + MATMUL(lhs%E333,rhs%R) +  &
              MATMUL(lhs%E3,rhs%E33) + MATMUL(lhs%E33,rhs%E3)
      res%E444 = MATMUL(lhs%R,rhs%E444) + MATMUL(lhs%E444,rhs%R) +  &
              MATMUL(lhs%E4,rhs%E44) + MATMUL(lhs%E44,rhs%E4)
      res%E555 = MATMUL(lhs%R,rhs%E555) + MATMUL(lhs%E555,rhs%R) +  &
              MATMUL(lhs%E5,rhs%E55) + MATMUL(lhs%E55,rhs%E5)
      res%E666 = MATMUL(lhs%R,rhs%E666) + MATMUL(lhs%E666,rhs%R) +  &
              MATMUL(lhs%E6,rhs%E66) + MATMUL(lhs%E66,rhs%E6)
      res%E777 = MATMUL(lhs%R,rhs%E777) + MATMUL(lhs%E777,rhs%R) +  &
              MATMUL(lhs%E7,rhs%E77) + MATMUL(lhs%E77,rhs%E7)
      ! Order 2
      res%E11 = MATMUL(lhs%R,rhs%E11) + MATMUL(lhs%E11,rhs%R) + MATMUL(lhs%E1,rhs%E1)
      res%E22 = MATMUL(lhs%R,rhs%E22) + MATMUL(lhs%E22,rhs%R) + MATMUL(lhs%E2,rhs%E2)
      res%E33 = MATMUL(lhs%R,rhs%E33) + MATMUL(lhs%E33,rhs%R) + MATMUL(lhs%E3,rhs%E3)
      res%E44 = MATMUL(lhs%R,rhs%E44) + MATMUL(lhs%E44,rhs%R) + MATMUL(lhs%E4,rhs%E4)
      res%E55 = MATMUL(lhs%R,rhs%E55) + MATMUL(lhs%E55,rhs%R) + MATMUL(lhs%E5,rhs%E5)
      res%E66 = MATMUL(lhs%R,rhs%E66) + MATMUL(lhs%E66,rhs%R) + MATMUL(lhs%E6,rhs%E6)
      res%E77 = MATMUL(lhs%R,rhs%E77) + MATMUL(lhs%E77,rhs%R) + MATMUL(lhs%E7,rhs%E7)
      ! Order 1
      res%E1 = MATMUL(lhs%R,rhs%E1) + MATMUL(lhs%E1,rhs%R)
      res%E2 = MATMUL(lhs%R,rhs%E2) + MATMUL(lhs%E2,rhs%R)
      res%E3 = MATMUL(lhs%R,rhs%E3) + MATMUL(lhs%E3,rhs%R)
      res%E4 = MATMUL(lhs%R,rhs%E4) + MATMUL(lhs%E4,rhs%R)
      res%E5 = MATMUL(lhs%R,rhs%E5) + MATMUL(lhs%E5,rhs%R)
      res%E6 = MATMUL(lhs%R,rhs%E6) + MATMUL(lhs%E6,rhs%R)
      res%E7 = MATMUL(lhs%R,rhs%E7) + MATMUL(lhs%E7,rhs%R)
      ! Order 0
      res%R = MATMUL(lhs%R,rhs%R)

   END FUNCTION DONUMM7N3_MATMUL_DONUMM7N3

   FUNCTION R_MATMUL_DONUMM7N3(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS(:,:)
      TYPE(DONUMM7N3), INTENT(IN) :: RHS(:,:)
      TYPE(DONUMM7N3) :: RES(SIZE(LHS,1),SIZE(RHS,2))

      ! Multiplication like function 'MATMUL(lhs,rhs)'
      !  Real
      res%R = MATMUL(lhs,rhs%R)

      ! Order 1
      res%E1 = MATMUL(lhs,rhs%E1)
      res%E2 = MATMUL(lhs,rhs%E2)
      res%E3 = MATMUL(lhs,rhs%E3)
      res%E4 = MATMUL(lhs,rhs%E4)
      res%E5 = MATMUL(lhs,rhs%E5)
      res%E6 = MATMUL(lhs,rhs%E6)
      res%E7 = MATMUL(lhs,rhs%E7)

      ! Order 2
      res%E11 = MATMUL(lhs,rhs%E11)
      res%E22 = MATMUL(lhs,rhs%E22)
      res%E33 = MATMUL(lhs,rhs%E33)
      res%E44 = MATMUL(lhs,rhs%E44)
      res%E55 = MATMUL(lhs,rhs%E55)
      res%E66 = MATMUL(lhs,rhs%E66)
      res%E77 = MATMUL(lhs,rhs%E77)

      ! Order 3
      res%E111 = MATMUL(lhs,rhs%E111)
      res%E222 = MATMUL(lhs,rhs%E222)
      res%E333 = MATMUL(lhs,rhs%E333)
      res%E444 = MATMUL(lhs,rhs%E444)
      res%E555 = MATMUL(lhs,rhs%E555)
      res%E666 = MATMUL(lhs,rhs%E666)
      res%E777 = MATMUL(lhs,rhs%E777)

   END FUNCTION R_MATMUL_DONUMM7N3

   FUNCTION DONUMM7N3_MATMUL_R(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(DONUMM7N3), INTENT(IN) :: LHS(:,:)
      REAL(DP), INTENT(IN) :: RHS(:,:)
      TYPE(DONUMM7N3) :: RES(SIZE(LHS,1),SIZE(RHS,2))

      ! Multiplication like function 'MATMUL(lhs,rhs)'
      !  Real
      res%R = MATMUL(lhs%R,rhs)

      ! Order 1
      res%E1 = MATMUL(lhs%E1,rhs)
      res%E2 = MATMUL(lhs%E2,rhs)
      res%E3 = MATMUL(lhs%E3,rhs)
      res%E4 = MATMUL(lhs%E4,rhs)
      res%E5 = MATMUL(lhs%E5,rhs)
      res%E6 = MATMUL(lhs%E6,rhs)
      res%E7 = MATMUL(lhs%E7,rhs)

      ! Order 2
      res%E11 = MATMUL(lhs%E11,rhs)
      res%E22 = MATMUL(lhs%E22,rhs)
      res%E33 = MATMUL(lhs%E33,rhs)
      res%E44 = MATMUL(lhs%E44,rhs)
      res%E55 = MATMUL(lhs%E55,rhs)
      res%E66 = MATMUL(lhs%E66,rhs)
      res%E77 = MATMUL(lhs%E77,rhs)

      ! Order 3
      res%E111 = MATMUL(lhs%E111,rhs)
      res%E222 = MATMUL(lhs%E222,rhs)
      res%E333 = MATMUL(lhs%E333,rhs)
      res%E444 = MATMUL(lhs%E444,rhs)
      res%E555 = MATMUL(lhs%E555,rhs)
      res%E666 = MATMUL(lhs%E666,rhs)
      res%E777 = MATMUL(lhs%E777,rhs)

   END FUNCTION DONUMM7N3_MATMUL_R

   FUNCTION DONUMM7N3_DOT_PRODUCT_DONUMM7N3(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(DONUMM7N3), INTENT(IN) :: LHS(:)
      TYPE(DONUMM7N3), INTENT(IN) :: RHS(SIZE(LHS))
      TYPE(DONUMM7N3) :: RES

      !  Multiplication like function 'DOT_PRODUCT(lhs,rhs)'
      ! Order 3
      res%E111 = DOT_PRODUCT(lhs%R,rhs%E111) + DOT_PRODUCT(lhs%E111,rhs%R) +  &
              DOT_PRODUCT(lhs%E1,rhs%E11) + DOT_PRODUCT(lhs%E11,rhs%E1)
      res%E222 = DOT_PRODUCT(lhs%R,rhs%E222) + DOT_PRODUCT(lhs%E222,rhs%R) +  &
              DOT_PRODUCT(lhs%E2,rhs%E22) + DOT_PRODUCT(lhs%E22,rhs%E2)
      res%E333 = DOT_PRODUCT(lhs%R,rhs%E333) + DOT_PRODUCT(lhs%E333,rhs%R) +  &
              DOT_PRODUCT(lhs%E3,rhs%E33) + DOT_PRODUCT(lhs%E33,rhs%E3)
      res%E444 = DOT_PRODUCT(lhs%R,rhs%E444) + DOT_PRODUCT(lhs%E444,rhs%R) +  &
              DOT_PRODUCT(lhs%E4,rhs%E44) + DOT_PRODUCT(lhs%E44,rhs%E4)
      res%E555 = DOT_PRODUCT(lhs%R,rhs%E555) + DOT_PRODUCT(lhs%E555,rhs%R) +  &
              DOT_PRODUCT(lhs%E5,rhs%E55) + DOT_PRODUCT(lhs%E55,rhs%E5)
      res%E666 = DOT_PRODUCT(lhs%R,rhs%E666) + DOT_PRODUCT(lhs%E666,rhs%R) +  &
              DOT_PRODUCT(lhs%E6,rhs%E66) + DOT_PRODUCT(lhs%E66,rhs%E6)
      res%E777 = DOT_PRODUCT(lhs%R,rhs%E777) + DOT_PRODUCT(lhs%E777,rhs%R) +  &
              DOT_PRODUCT(lhs%E7,rhs%E77) + DOT_PRODUCT(lhs%E77,rhs%E7)
      ! Order 2
      res%E11 = DOT_PRODUCT(lhs%R,rhs%E11) + DOT_PRODUCT(lhs%E11,rhs%R) + DOT_PRODUCT(lhs%E1,rhs%E1)
      res%E22 = DOT_PRODUCT(lhs%R,rhs%E22) + DOT_PRODUCT(lhs%E22,rhs%R) + DOT_PRODUCT(lhs%E2,rhs%E2)
      res%E33 = DOT_PRODUCT(lhs%R,rhs%E33) + DOT_PRODUCT(lhs%E33,rhs%R) + DOT_PRODUCT(lhs%E3,rhs%E3)
      res%E44 = DOT_PRODUCT(lhs%R,rhs%E44) + DOT_PRODUCT(lhs%E44,rhs%R) + DOT_PRODUCT(lhs%E4,rhs%E4)
      res%E55 = DOT_PRODUCT(lhs%R,rhs%E55) + DOT_PRODUCT(lhs%E55,rhs%R) + DOT_PRODUCT(lhs%E5,rhs%E5)
      res%E66 = DOT_PRODUCT(lhs%R,rhs%E66) + DOT_PRODUCT(lhs%E66,rhs%R) + DOT_PRODUCT(lhs%E6,rhs%E6)
      res%E77 = DOT_PRODUCT(lhs%R,rhs%E77) + DOT_PRODUCT(lhs%E77,rhs%R) + DOT_PRODUCT(lhs%E7,rhs%E7)
      ! Order 1
      res%E1 = DOT_PRODUCT(lhs%R,rhs%E1) + DOT_PRODUCT(lhs%E1,rhs%R)
      res%E2 = DOT_PRODUCT(lhs%R,rhs%E2) + DOT_PRODUCT(lhs%E2,rhs%R)
      res%E3 = DOT_PRODUCT(lhs%R,rhs%E3) + DOT_PRODUCT(lhs%E3,rhs%R)
      res%E4 = DOT_PRODUCT(lhs%R,rhs%E4) + DOT_PRODUCT(lhs%E4,rhs%R)
      res%E5 = DOT_PRODUCT(lhs%R,rhs%E5) + DOT_PRODUCT(lhs%E5,rhs%R)
      res%E6 = DOT_PRODUCT(lhs%R,rhs%E6) + DOT_PRODUCT(lhs%E6,rhs%R)
      res%E7 = DOT_PRODUCT(lhs%R,rhs%E7) + DOT_PRODUCT(lhs%E7,rhs%R)
      ! Order 0
      res%R = DOT_PRODUCT(lhs%R,rhs%R)

   END FUNCTION DONUMM7N3_DOT_PRODUCT_DONUMM7N3

   FUNCTION R_DOT_PRODUCT_DONUMM7N3(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS(:)
      TYPE(DONUMM7N3), INTENT(IN) :: RHS(SIZE(LHS))
      TYPE(DONUMM7N3) :: RES

      ! Multiplication like function 'DOT_PRODUCT(lhs,rhs)'
      !  Real
      res%R = DOT_PRODUCT(lhs,rhs%R)

      ! Order 1
      res%E1 = DOT_PRODUCT(lhs,rhs%E1)
      res%E2 = DOT_PRODUCT(lhs,rhs%E2)
      res%E3 = DOT_PRODUCT(lhs,rhs%E3)
      res%E4 = DOT_PRODUCT(lhs,rhs%E4)
      res%E5 = DOT_PRODUCT(lhs,rhs%E5)
      res%E6 = DOT_PRODUCT(lhs,rhs%E6)
      res%E7 = DOT_PRODUCT(lhs,rhs%E7)

      ! Order 2
      res%E11 = DOT_PRODUCT(lhs,rhs%E11)
      res%E22 = DOT_PRODUCT(lhs,rhs%E22)
      res%E33 = DOT_PRODUCT(lhs,rhs%E33)
      res%E44 = DOT_PRODUCT(lhs,rhs%E44)
      res%E55 = DOT_PRODUCT(lhs,rhs%E55)
      res%E66 = DOT_PRODUCT(lhs,rhs%E66)
      res%E77 = DOT_PRODUCT(lhs,rhs%E77)

      ! Order 3
      res%E111 = DOT_PRODUCT(lhs,rhs%E111)
      res%E222 = DOT_PRODUCT(lhs,rhs%E222)
      res%E333 = DOT_PRODUCT(lhs,rhs%E333)
      res%E444 = DOT_PRODUCT(lhs,rhs%E444)
      res%E555 = DOT_PRODUCT(lhs,rhs%E555)
      res%E666 = DOT_PRODUCT(lhs,rhs%E666)
      res%E777 = DOT_PRODUCT(lhs,rhs%E777)

   END FUNCTION R_DOT_PRODUCT_DONUMM7N3

   FUNCTION DONUMM7N3_DOT_PRODUCT_R(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(DONUMM7N3), INTENT(IN) :: LHS(:)
      REAL(DP), INTENT(IN) :: RHS(SIZE(LHS))
      TYPE(DONUMM7N3) :: RES

      ! Multiplication like function 'DOT_PRODUCT(lhs,rhs)'
      !  Real
      res%R = DOT_PRODUCT(lhs%R,rhs)

      ! Order 1
      res%E1 = DOT_PRODUCT(lhs%E1,rhs)
      res%E2 = DOT_PRODUCT(lhs%E2,rhs)
      res%E3 = DOT_PRODUCT(lhs%E3,rhs)
      res%E4 = DOT_PRODUCT(lhs%E4,rhs)
      res%E5 = DOT_PRODUCT(lhs%E5,rhs)
      res%E6 = DOT_PRODUCT(lhs%E6,rhs)
      res%E7 = DOT_PRODUCT(lhs%E7,rhs)

      ! Order 2
      res%E11 = DOT_PRODUCT(lhs%E11,rhs)
      res%E22 = DOT_PRODUCT(lhs%E22,rhs)
      res%E33 = DOT_PRODUCT(lhs%E33,rhs)
      res%E44 = DOT_PRODUCT(lhs%E44,rhs)
      res%E55 = DOT_PRODUCT(lhs%E55,rhs)
      res%E66 = DOT_PRODUCT(lhs%E66,rhs)
      res%E77 = DOT_PRODUCT(lhs%E77,rhs)

      ! Order 3
      res%E111 = DOT_PRODUCT(lhs%E111,rhs)
      res%E222 = DOT_PRODUCT(lhs%E222,rhs)
      res%E333 = DOT_PRODUCT(lhs%E333,rhs)
      res%E444 = DOT_PRODUCT(lhs%E444,rhs)
      res%E555 = DOT_PRODUCT(lhs%E555,rhs)
      res%E666 = DOT_PRODUCT(lhs%E666,rhs)
      res%E777 = DOT_PRODUCT(lhs%E777,rhs)

   END FUNCTION DONUMM7N3_DOT_PRODUCT_R

   FUNCTION DONUMM7N3_TRANSPOSE(LHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(DONUMM7N3), INTENT(IN) :: LHS(:,:)
      TYPE(DONUMM7N3) :: RES (SIZE(LHS,2),SIZE(LHS,1))

      ! Negation like function 'TRANSPOSE(LHS)'
      ! Real
      RES%R = TRANSPOSE(LHS%R)
      ! Order 1
      RES%E1 = TRANSPOSE(LHS%E1)
      RES%E2 = TRANSPOSE(LHS%E2)
      RES%E3 = TRANSPOSE(LHS%E3)
      RES%E4 = TRANSPOSE(LHS%E4)
      RES%E5 = TRANSPOSE(LHS%E5)
      RES%E6 = TRANSPOSE(LHS%E6)
      RES%E7 = TRANSPOSE(LHS%E7)
      ! Order 2
      RES%E11 = TRANSPOSE(LHS%E11)
      RES%E22 = TRANSPOSE(LHS%E22)
      RES%E33 = TRANSPOSE(LHS%E33)
      RES%E44 = TRANSPOSE(LHS%E44)
      RES%E55 = TRANSPOSE(LHS%E55)
      RES%E66 = TRANSPOSE(LHS%E66)
      RES%E77 = TRANSPOSE(LHS%E77)
      ! Order 3
      RES%E111 = TRANSPOSE(LHS%E111)
      RES%E222 = TRANSPOSE(LHS%E222)
      RES%E333 = TRANSPOSE(LHS%E333)
      RES%E444 = TRANSPOSE(LHS%E444)
      RES%E555 = TRANSPOSE(LHS%E555)
      RES%E666 = TRANSPOSE(LHS%E666)
      RES%E777 = TRANSPOSE(LHS%E777)

   END FUNCTION DONUMM7N3_TRANSPOSE

FUNCTION DONUMM7N3_TO_CR_MAT_S(VAL) RESULT(RES)
      IMPLICIT NONE
      TYPE(DONUMM7N3), INTENT(IN) :: VAL
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
      ! R x E4 -> E4 (5, 5)
      RES(1+NROWS*4:NROWS*5,1+NCOLS*4:NCOLS*5) = VAL%R
      ! E4 x R -> E4 (5, 1)
      RES(1+NROWS*4:NROWS*5,1+NCOLS*0:NCOLS*1) = VAL%E4
      ! R x E5 -> E5 (6, 6)
      RES(1+NROWS*5:NROWS*6,1+NCOLS*5:NCOLS*6) = VAL%R
      ! E5 x R -> E5 (6, 1)
      RES(1+NROWS*5:NROWS*6,1+NCOLS*0:NCOLS*1) = VAL%E5
      ! R x E6 -> E6 (7, 7)
      RES(1+NROWS*6:NROWS*7,1+NCOLS*6:NCOLS*7) = VAL%R
      ! E6 x R -> E6 (7, 1)
      RES(1+NROWS*6:NROWS*7,1+NCOLS*0:NCOLS*1) = VAL%E6
      ! R x E7 -> E7 (8, 8)
      RES(1+NROWS*7:NROWS*8,1+NCOLS*7:NCOLS*8) = VAL%R
      ! E7 x R -> E7 (8, 1)
      RES(1+NROWS*7:NROWS*8,1+NCOLS*0:NCOLS*1) = VAL%E7
      ! R x E11 -> E11 (9, 9)
      RES(1+NROWS*8:NROWS*9,1+NCOLS*8:NCOLS*9) = VAL%R
      ! E11 x R -> E11 (9, 1)
      RES(1+NROWS*8:NROWS*9,1+NCOLS*0:NCOLS*1) = VAL%E11
      ! E1 x E1 -> E11 (9, 2)
      RES(1+NROWS*8:NROWS*9,1+NCOLS*1:NCOLS*2) = VAL%E1
      ! R x E22 -> E22 (10, 10)
      RES(1+NROWS*9:NROWS*10,1+NCOLS*9:NCOLS*10) = VAL%R
      ! E22 x R -> E22 (10, 1)
      RES(1+NROWS*9:NROWS*10,1+NCOLS*0:NCOLS*1) = VAL%E22
      ! E2 x E2 -> E22 (10, 3)
      RES(1+NROWS*9:NROWS*10,1+NCOLS*2:NCOLS*3) = VAL%E2
      ! R x E33 -> E33 (11, 11)
      RES(1+NROWS*10:NROWS*11,1+NCOLS*10:NCOLS*11) = VAL%R
      ! E33 x R -> E33 (11, 1)
      RES(1+NROWS*10:NROWS*11,1+NCOLS*0:NCOLS*1) = VAL%E33
      ! E3 x E3 -> E33 (11, 4)
      RES(1+NROWS*10:NROWS*11,1+NCOLS*3:NCOLS*4) = VAL%E3
      ! R x E44 -> E44 (12, 12)
      RES(1+NROWS*11:NROWS*12,1+NCOLS*11:NCOLS*12) = VAL%R
      ! E44 x R -> E44 (12, 1)
      RES(1+NROWS*11:NROWS*12,1+NCOLS*0:NCOLS*1) = VAL%E44
      ! E4 x E4 -> E44 (12, 5)
      RES(1+NROWS*11:NROWS*12,1+NCOLS*4:NCOLS*5) = VAL%E4
      ! R x E55 -> E55 (13, 13)
      RES(1+NROWS*12:NROWS*13,1+NCOLS*12:NCOLS*13) = VAL%R
      ! E55 x R -> E55 (13, 1)
      RES(1+NROWS*12:NROWS*13,1+NCOLS*0:NCOLS*1) = VAL%E55
      ! E5 x E5 -> E55 (13, 6)
      RES(1+NROWS*12:NROWS*13,1+NCOLS*5:NCOLS*6) = VAL%E5
      ! R x E66 -> E66 (14, 14)
      RES(1+NROWS*13:NROWS*14,1+NCOLS*13:NCOLS*14) = VAL%R
      ! E66 x R -> E66 (14, 1)
      RES(1+NROWS*13:NROWS*14,1+NCOLS*0:NCOLS*1) = VAL%E66
      ! E6 x E6 -> E66 (14, 7)
      RES(1+NROWS*13:NROWS*14,1+NCOLS*6:NCOLS*7) = VAL%E6
      ! R x E77 -> E77 (15, 15)
      RES(1+NROWS*14:NROWS*15,1+NCOLS*14:NCOLS*15) = VAL%R
      ! E77 x R -> E77 (15, 1)
      RES(1+NROWS*14:NROWS*15,1+NCOLS*0:NCOLS*1) = VAL%E77
      ! E7 x E7 -> E77 (15, 8)
      RES(1+NROWS*14:NROWS*15,1+NCOLS*7:NCOLS*8) = VAL%E7
      ! R x E111 -> E111 (16, 16)
      RES(1+NROWS*15:NROWS*16,1+NCOLS*15:NCOLS*16) = VAL%R
      ! E111 x R -> E111 (16, 1)
      RES(1+NROWS*15:NROWS*16,1+NCOLS*0:NCOLS*1) = VAL%E111
      ! E1 x E11 -> E111 (16, 9)
      RES(1+NROWS*15:NROWS*16,1+NCOLS*8:NCOLS*9) = VAL%E1
      ! E11 x E1 -> E111 (16, 2)
      RES(1+NROWS*15:NROWS*16,1+NCOLS*1:NCOLS*2) = VAL%E11
      ! R x E222 -> E222 (17, 17)
      RES(1+NROWS*16:NROWS*17,1+NCOLS*16:NCOLS*17) = VAL%R
      ! E222 x R -> E222 (17, 1)
      RES(1+NROWS*16:NROWS*17,1+NCOLS*0:NCOLS*1) = VAL%E222
      ! E2 x E22 -> E222 (17, 10)
      RES(1+NROWS*16:NROWS*17,1+NCOLS*9:NCOLS*10) = VAL%E2
      ! E22 x E2 -> E222 (17, 3)
      RES(1+NROWS*16:NROWS*17,1+NCOLS*2:NCOLS*3) = VAL%E22
      ! R x E333 -> E333 (18, 18)
      RES(1+NROWS*17:NROWS*18,1+NCOLS*17:NCOLS*18) = VAL%R
      ! E333 x R -> E333 (18, 1)
      RES(1+NROWS*17:NROWS*18,1+NCOLS*0:NCOLS*1) = VAL%E333
      ! E3 x E33 -> E333 (18, 11)
      RES(1+NROWS*17:NROWS*18,1+NCOLS*10:NCOLS*11) = VAL%E3
      ! E33 x E3 -> E333 (18, 4)
      RES(1+NROWS*17:NROWS*18,1+NCOLS*3:NCOLS*4) = VAL%E33
      ! R x E444 -> E444 (19, 19)
      RES(1+NROWS*18:NROWS*19,1+NCOLS*18:NCOLS*19) = VAL%R
      ! E444 x R -> E444 (19, 1)
      RES(1+NROWS*18:NROWS*19,1+NCOLS*0:NCOLS*1) = VAL%E444
      ! E4 x E44 -> E444 (19, 12)
      RES(1+NROWS*18:NROWS*19,1+NCOLS*11:NCOLS*12) = VAL%E4
      ! E44 x E4 -> E444 (19, 5)
      RES(1+NROWS*18:NROWS*19,1+NCOLS*4:NCOLS*5) = VAL%E44
      ! R x E555 -> E555 (20, 20)
      RES(1+NROWS*19:NROWS*20,1+NCOLS*19:NCOLS*20) = VAL%R
      ! E555 x R -> E555 (20, 1)
      RES(1+NROWS*19:NROWS*20,1+NCOLS*0:NCOLS*1) = VAL%E555
      ! E5 x E55 -> E555 (20, 13)
      RES(1+NROWS*19:NROWS*20,1+NCOLS*12:NCOLS*13) = VAL%E5
      ! E55 x E5 -> E555 (20, 6)
      RES(1+NROWS*19:NROWS*20,1+NCOLS*5:NCOLS*6) = VAL%E55
      ! R x E666 -> E666 (21, 21)
      RES(1+NROWS*20:NROWS*21,1+NCOLS*20:NCOLS*21) = VAL%R
      ! E666 x R -> E666 (21, 1)
      RES(1+NROWS*20:NROWS*21,1+NCOLS*0:NCOLS*1) = VAL%E666
      ! E6 x E66 -> E666 (21, 14)
      RES(1+NROWS*20:NROWS*21,1+NCOLS*13:NCOLS*14) = VAL%E6
      ! E66 x E6 -> E666 (21, 7)
      RES(1+NROWS*20:NROWS*21,1+NCOLS*6:NCOLS*7) = VAL%E66
      ! R x E777 -> E777 (22, 22)
      RES(1+NROWS*21:NROWS*22,1+NCOLS*21:NCOLS*22) = VAL%R
      ! E777 x R -> E777 (22, 1)
      RES(1+NROWS*21:NROWS*22,1+NCOLS*0:NCOLS*1) = VAL%E777
      ! E7 x E77 -> E777 (22, 15)
      RES(1+NROWS*21:NROWS*22,1+NCOLS*14:NCOLS*15) = VAL%E7
      ! E77 x E7 -> E777 (22, 8)
      RES(1+NROWS*21:NROWS*22,1+NCOLS*7:NCOLS*8) = VAL%E77
   END FUNCTION DONUMM7N3_TO_CR_MAT_S

FUNCTION DONUMM7N3_TO_CR_MAT_V(VAL) RESULT(RES)
      IMPLICIT NONE
      TYPE(DONUMM7N3), INTENT(IN) :: VAL(:)
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
      ! R x E4 -> E4 (5, 5)
      RES(1+NROWS*4:NROWS*5,5) = VAL%R
      ! E4 x R -> E4 (5, 1)
      RES(1+NROWS*4:NROWS*5,1) = VAL%E4
      ! R x E5 -> E5 (6, 6)
      RES(1+NROWS*5:NROWS*6,6) = VAL%R
      ! E5 x R -> E5 (6, 1)
      RES(1+NROWS*5:NROWS*6,1) = VAL%E5
      ! R x E6 -> E6 (7, 7)
      RES(1+NROWS*6:NROWS*7,7) = VAL%R
      ! E6 x R -> E6 (7, 1)
      RES(1+NROWS*6:NROWS*7,1) = VAL%E6
      ! R x E7 -> E7 (8, 8)
      RES(1+NROWS*7:NROWS*8,8) = VAL%R
      ! E7 x R -> E7 (8, 1)
      RES(1+NROWS*7:NROWS*8,1) = VAL%E7
      ! R x E11 -> E11 (9, 9)
      RES(1+NROWS*8:NROWS*9,9) = VAL%R
      ! E11 x R -> E11 (9, 1)
      RES(1+NROWS*8:NROWS*9,1) = VAL%E11
      ! E1 x E1 -> E11 (9, 2)
      RES(1+NROWS*8:NROWS*9,2) = VAL%E1
      ! R x E22 -> E22 (10, 10)
      RES(1+NROWS*9:NROWS*10,10) = VAL%R
      ! E22 x R -> E22 (10, 1)
      RES(1+NROWS*9:NROWS*10,1) = VAL%E22
      ! E2 x E2 -> E22 (10, 3)
      RES(1+NROWS*9:NROWS*10,3) = VAL%E2
      ! R x E33 -> E33 (11, 11)
      RES(1+NROWS*10:NROWS*11,11) = VAL%R
      ! E33 x R -> E33 (11, 1)
      RES(1+NROWS*10:NROWS*11,1) = VAL%E33
      ! E3 x E3 -> E33 (11, 4)
      RES(1+NROWS*10:NROWS*11,4) = VAL%E3
      ! R x E44 -> E44 (12, 12)
      RES(1+NROWS*11:NROWS*12,12) = VAL%R
      ! E44 x R -> E44 (12, 1)
      RES(1+NROWS*11:NROWS*12,1) = VAL%E44
      ! E4 x E4 -> E44 (12, 5)
      RES(1+NROWS*11:NROWS*12,5) = VAL%E4
      ! R x E55 -> E55 (13, 13)
      RES(1+NROWS*12:NROWS*13,13) = VAL%R
      ! E55 x R -> E55 (13, 1)
      RES(1+NROWS*12:NROWS*13,1) = VAL%E55
      ! E5 x E5 -> E55 (13, 6)
      RES(1+NROWS*12:NROWS*13,6) = VAL%E5
      ! R x E66 -> E66 (14, 14)
      RES(1+NROWS*13:NROWS*14,14) = VAL%R
      ! E66 x R -> E66 (14, 1)
      RES(1+NROWS*13:NROWS*14,1) = VAL%E66
      ! E6 x E6 -> E66 (14, 7)
      RES(1+NROWS*13:NROWS*14,7) = VAL%E6
      ! R x E77 -> E77 (15, 15)
      RES(1+NROWS*14:NROWS*15,15) = VAL%R
      ! E77 x R -> E77 (15, 1)
      RES(1+NROWS*14:NROWS*15,1) = VAL%E77
      ! E7 x E7 -> E77 (15, 8)
      RES(1+NROWS*14:NROWS*15,8) = VAL%E7
      ! R x E111 -> E111 (16, 16)
      RES(1+NROWS*15:NROWS*16,16) = VAL%R
      ! E111 x R -> E111 (16, 1)
      RES(1+NROWS*15:NROWS*16,1) = VAL%E111
      ! E1 x E11 -> E111 (16, 9)
      RES(1+NROWS*15:NROWS*16,9) = VAL%E1
      ! E11 x E1 -> E111 (16, 2)
      RES(1+NROWS*15:NROWS*16,2) = VAL%E11
      ! R x E222 -> E222 (17, 17)
      RES(1+NROWS*16:NROWS*17,17) = VAL%R
      ! E222 x R -> E222 (17, 1)
      RES(1+NROWS*16:NROWS*17,1) = VAL%E222
      ! E2 x E22 -> E222 (17, 10)
      RES(1+NROWS*16:NROWS*17,10) = VAL%E2
      ! E22 x E2 -> E222 (17, 3)
      RES(1+NROWS*16:NROWS*17,3) = VAL%E22
      ! R x E333 -> E333 (18, 18)
      RES(1+NROWS*17:NROWS*18,18) = VAL%R
      ! E333 x R -> E333 (18, 1)
      RES(1+NROWS*17:NROWS*18,1) = VAL%E333
      ! E3 x E33 -> E333 (18, 11)
      RES(1+NROWS*17:NROWS*18,11) = VAL%E3
      ! E33 x E3 -> E333 (18, 4)
      RES(1+NROWS*17:NROWS*18,4) = VAL%E33
      ! R x E444 -> E444 (19, 19)
      RES(1+NROWS*18:NROWS*19,19) = VAL%R
      ! E444 x R -> E444 (19, 1)
      RES(1+NROWS*18:NROWS*19,1) = VAL%E444
      ! E4 x E44 -> E444 (19, 12)
      RES(1+NROWS*18:NROWS*19,12) = VAL%E4
      ! E44 x E4 -> E444 (19, 5)
      RES(1+NROWS*18:NROWS*19,5) = VAL%E44
      ! R x E555 -> E555 (20, 20)
      RES(1+NROWS*19:NROWS*20,20) = VAL%R
      ! E555 x R -> E555 (20, 1)
      RES(1+NROWS*19:NROWS*20,1) = VAL%E555
      ! E5 x E55 -> E555 (20, 13)
      RES(1+NROWS*19:NROWS*20,13) = VAL%E5
      ! E55 x E5 -> E555 (20, 6)
      RES(1+NROWS*19:NROWS*20,6) = VAL%E55
      ! R x E666 -> E666 (21, 21)
      RES(1+NROWS*20:NROWS*21,21) = VAL%R
      ! E666 x R -> E666 (21, 1)
      RES(1+NROWS*20:NROWS*21,1) = VAL%E666
      ! E6 x E66 -> E666 (21, 14)
      RES(1+NROWS*20:NROWS*21,14) = VAL%E6
      ! E66 x E6 -> E666 (21, 7)
      RES(1+NROWS*20:NROWS*21,7) = VAL%E66
      ! R x E777 -> E777 (22, 22)
      RES(1+NROWS*21:NROWS*22,22) = VAL%R
      ! E777 x R -> E777 (22, 1)
      RES(1+NROWS*21:NROWS*22,1) = VAL%E777
      ! E7 x E77 -> E777 (22, 15)
      RES(1+NROWS*21:NROWS*22,15) = VAL%E7
      ! E77 x E7 -> E777 (22, 8)
      RES(1+NROWS*21:NROWS*22,8) = VAL%E77
   END FUNCTION DONUMM7N3_TO_CR_MAT_V

FUNCTION DONUMM7N3_TO_CR_MAT_M(VAL) RESULT(RES)
      IMPLICIT NONE
      TYPE(DONUMM7N3), INTENT(IN) :: VAL(:,:)
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
      ! R x E4 -> E4 (5, 5)
      RES(1+NROWS*4:NROWS*5,1+NCOLS*4:NCOLS*5) = VAL%R
      ! E4 x R -> E4 (5, 1)
      RES(1+NROWS*4:NROWS*5,1+NCOLS*0:NCOLS*1) = VAL%E4
      ! R x E5 -> E5 (6, 6)
      RES(1+NROWS*5:NROWS*6,1+NCOLS*5:NCOLS*6) = VAL%R
      ! E5 x R -> E5 (6, 1)
      RES(1+NROWS*5:NROWS*6,1+NCOLS*0:NCOLS*1) = VAL%E5
      ! R x E6 -> E6 (7, 7)
      RES(1+NROWS*6:NROWS*7,1+NCOLS*6:NCOLS*7) = VAL%R
      ! E6 x R -> E6 (7, 1)
      RES(1+NROWS*6:NROWS*7,1+NCOLS*0:NCOLS*1) = VAL%E6
      ! R x E7 -> E7 (8, 8)
      RES(1+NROWS*7:NROWS*8,1+NCOLS*7:NCOLS*8) = VAL%R
      ! E7 x R -> E7 (8, 1)
      RES(1+NROWS*7:NROWS*8,1+NCOLS*0:NCOLS*1) = VAL%E7
      ! R x E11 -> E11 (9, 9)
      RES(1+NROWS*8:NROWS*9,1+NCOLS*8:NCOLS*9) = VAL%R
      ! E11 x R -> E11 (9, 1)
      RES(1+NROWS*8:NROWS*9,1+NCOLS*0:NCOLS*1) = VAL%E11
      ! E1 x E1 -> E11 (9, 2)
      RES(1+NROWS*8:NROWS*9,1+NCOLS*1:NCOLS*2) = VAL%E1
      ! R x E22 -> E22 (10, 10)
      RES(1+NROWS*9:NROWS*10,1+NCOLS*9:NCOLS*10) = VAL%R
      ! E22 x R -> E22 (10, 1)
      RES(1+NROWS*9:NROWS*10,1+NCOLS*0:NCOLS*1) = VAL%E22
      ! E2 x E2 -> E22 (10, 3)
      RES(1+NROWS*9:NROWS*10,1+NCOLS*2:NCOLS*3) = VAL%E2
      ! R x E33 -> E33 (11, 11)
      RES(1+NROWS*10:NROWS*11,1+NCOLS*10:NCOLS*11) = VAL%R
      ! E33 x R -> E33 (11, 1)
      RES(1+NROWS*10:NROWS*11,1+NCOLS*0:NCOLS*1) = VAL%E33
      ! E3 x E3 -> E33 (11, 4)
      RES(1+NROWS*10:NROWS*11,1+NCOLS*3:NCOLS*4) = VAL%E3
      ! R x E44 -> E44 (12, 12)
      RES(1+NROWS*11:NROWS*12,1+NCOLS*11:NCOLS*12) = VAL%R
      ! E44 x R -> E44 (12, 1)
      RES(1+NROWS*11:NROWS*12,1+NCOLS*0:NCOLS*1) = VAL%E44
      ! E4 x E4 -> E44 (12, 5)
      RES(1+NROWS*11:NROWS*12,1+NCOLS*4:NCOLS*5) = VAL%E4
      ! R x E55 -> E55 (13, 13)
      RES(1+NROWS*12:NROWS*13,1+NCOLS*12:NCOLS*13) = VAL%R
      ! E55 x R -> E55 (13, 1)
      RES(1+NROWS*12:NROWS*13,1+NCOLS*0:NCOLS*1) = VAL%E55
      ! E5 x E5 -> E55 (13, 6)
      RES(1+NROWS*12:NROWS*13,1+NCOLS*5:NCOLS*6) = VAL%E5
      ! R x E66 -> E66 (14, 14)
      RES(1+NROWS*13:NROWS*14,1+NCOLS*13:NCOLS*14) = VAL%R
      ! E66 x R -> E66 (14, 1)
      RES(1+NROWS*13:NROWS*14,1+NCOLS*0:NCOLS*1) = VAL%E66
      ! E6 x E6 -> E66 (14, 7)
      RES(1+NROWS*13:NROWS*14,1+NCOLS*6:NCOLS*7) = VAL%E6
      ! R x E77 -> E77 (15, 15)
      RES(1+NROWS*14:NROWS*15,1+NCOLS*14:NCOLS*15) = VAL%R
      ! E77 x R -> E77 (15, 1)
      RES(1+NROWS*14:NROWS*15,1+NCOLS*0:NCOLS*1) = VAL%E77
      ! E7 x E7 -> E77 (15, 8)
      RES(1+NROWS*14:NROWS*15,1+NCOLS*7:NCOLS*8) = VAL%E7
      ! R x E111 -> E111 (16, 16)
      RES(1+NROWS*15:NROWS*16,1+NCOLS*15:NCOLS*16) = VAL%R
      ! E111 x R -> E111 (16, 1)
      RES(1+NROWS*15:NROWS*16,1+NCOLS*0:NCOLS*1) = VAL%E111
      ! E1 x E11 -> E111 (16, 9)
      RES(1+NROWS*15:NROWS*16,1+NCOLS*8:NCOLS*9) = VAL%E1
      ! E11 x E1 -> E111 (16, 2)
      RES(1+NROWS*15:NROWS*16,1+NCOLS*1:NCOLS*2) = VAL%E11
      ! R x E222 -> E222 (17, 17)
      RES(1+NROWS*16:NROWS*17,1+NCOLS*16:NCOLS*17) = VAL%R
      ! E222 x R -> E222 (17, 1)
      RES(1+NROWS*16:NROWS*17,1+NCOLS*0:NCOLS*1) = VAL%E222
      ! E2 x E22 -> E222 (17, 10)
      RES(1+NROWS*16:NROWS*17,1+NCOLS*9:NCOLS*10) = VAL%E2
      ! E22 x E2 -> E222 (17, 3)
      RES(1+NROWS*16:NROWS*17,1+NCOLS*2:NCOLS*3) = VAL%E22
      ! R x E333 -> E333 (18, 18)
      RES(1+NROWS*17:NROWS*18,1+NCOLS*17:NCOLS*18) = VAL%R
      ! E333 x R -> E333 (18, 1)
      RES(1+NROWS*17:NROWS*18,1+NCOLS*0:NCOLS*1) = VAL%E333
      ! E3 x E33 -> E333 (18, 11)
      RES(1+NROWS*17:NROWS*18,1+NCOLS*10:NCOLS*11) = VAL%E3
      ! E33 x E3 -> E333 (18, 4)
      RES(1+NROWS*17:NROWS*18,1+NCOLS*3:NCOLS*4) = VAL%E33
      ! R x E444 -> E444 (19, 19)
      RES(1+NROWS*18:NROWS*19,1+NCOLS*18:NCOLS*19) = VAL%R
      ! E444 x R -> E444 (19, 1)
      RES(1+NROWS*18:NROWS*19,1+NCOLS*0:NCOLS*1) = VAL%E444
      ! E4 x E44 -> E444 (19, 12)
      RES(1+NROWS*18:NROWS*19,1+NCOLS*11:NCOLS*12) = VAL%E4
      ! E44 x E4 -> E444 (19, 5)
      RES(1+NROWS*18:NROWS*19,1+NCOLS*4:NCOLS*5) = VAL%E44
      ! R x E555 -> E555 (20, 20)
      RES(1+NROWS*19:NROWS*20,1+NCOLS*19:NCOLS*20) = VAL%R
      ! E555 x R -> E555 (20, 1)
      RES(1+NROWS*19:NROWS*20,1+NCOLS*0:NCOLS*1) = VAL%E555
      ! E5 x E55 -> E555 (20, 13)
      RES(1+NROWS*19:NROWS*20,1+NCOLS*12:NCOLS*13) = VAL%E5
      ! E55 x E5 -> E555 (20, 6)
      RES(1+NROWS*19:NROWS*20,1+NCOLS*5:NCOLS*6) = VAL%E55
      ! R x E666 -> E666 (21, 21)
      RES(1+NROWS*20:NROWS*21,1+NCOLS*20:NCOLS*21) = VAL%R
      ! E666 x R -> E666 (21, 1)
      RES(1+NROWS*20:NROWS*21,1+NCOLS*0:NCOLS*1) = VAL%E666
      ! E6 x E66 -> E666 (21, 14)
      RES(1+NROWS*20:NROWS*21,1+NCOLS*13:NCOLS*14) = VAL%E6
      ! E66 x E6 -> E666 (21, 7)
      RES(1+NROWS*20:NROWS*21,1+NCOLS*6:NCOLS*7) = VAL%E66
      ! R x E777 -> E777 (22, 22)
      RES(1+NROWS*21:NROWS*22,1+NCOLS*21:NCOLS*22) = VAL%R
      ! E777 x R -> E777 (22, 1)
      RES(1+NROWS*21:NROWS*22,1+NCOLS*0:NCOLS*1) = VAL%E777
      ! E7 x E77 -> E777 (22, 15)
      RES(1+NROWS*21:NROWS*22,1+NCOLS*14:NCOLS*15) = VAL%E7
      ! E77 x E7 -> E777 (22, 8)
      RES(1+NROWS*21:NROWS*22,1+NCOLS*7:NCOLS*8) = VAL%E77
   END FUNCTION DONUMM7N3_TO_CR_MAT_M

      SUBROUTINE DONUMM7N3_SETIM_S(VAL,IDX,RES)
      IMPLICIT NONE
      TYPE(DONUMM7N3), INTENT(INOUT) :: VAL
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
      CASE(4)
         VAL%E4=RES
      CASE(5)
         VAL%E5=RES
      CASE(6)
         VAL%E6=RES
      CASE(7)
         VAL%E7=RES

      ! Order 2
      CASE(8)
         VAL%E11=RES
      CASE(9)
         VAL%E22=RES
      CASE(10)
         VAL%E33=RES
      CASE(11)
         VAL%E44=RES
      CASE(12)
         VAL%E55=RES
      CASE(13)
         VAL%E66=RES
      CASE(14)
         VAL%E77=RES

      ! Order 3
      CASE(15)
         VAL%E111=RES
      CASE(16)
         VAL%E222=RES
      CASE(17)
         VAL%E333=RES
      CASE(18)
         VAL%E444=RES
      CASE(19)
         VAL%E555=RES
      CASE(20)
         VAL%E666=RES
      CASE(21)
         VAL%E777=RES

      END SELECT
   END SUBROUTINE DONUMM7N3_SETIM_S

      SUBROUTINE DONUMM7N3_SETIM_V(VAL,IDX,RES)
      IMPLICIT NONE
      TYPE(DONUMM7N3), INTENT(INOUT) :: VAL(:)
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
      CASE(4)
         VAL%E4=RES
      CASE(5)
         VAL%E5=RES
      CASE(6)
         VAL%E6=RES
      CASE(7)
         VAL%E7=RES

      ! Order 2
      CASE(8)
         VAL%E11=RES
      CASE(9)
         VAL%E22=RES
      CASE(10)
         VAL%E33=RES
      CASE(11)
         VAL%E44=RES
      CASE(12)
         VAL%E55=RES
      CASE(13)
         VAL%E66=RES
      CASE(14)
         VAL%E77=RES

      ! Order 3
      CASE(15)
         VAL%E111=RES
      CASE(16)
         VAL%E222=RES
      CASE(17)
         VAL%E333=RES
      CASE(18)
         VAL%E444=RES
      CASE(19)
         VAL%E555=RES
      CASE(20)
         VAL%E666=RES
      CASE(21)
         VAL%E777=RES

      END SELECT
   END SUBROUTINE DONUMM7N3_SETIM_V

      SUBROUTINE DONUMM7N3_SETIM_M(VAL,IDX,RES)
      IMPLICIT NONE
      TYPE(DONUMM7N3), INTENT(INOUT) :: VAL(:,:)
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
      CASE(4)
         VAL%E4=RES
      CASE(5)
         VAL%E5=RES
      CASE(6)
         VAL%E6=RES
      CASE(7)
         VAL%E7=RES

      ! Order 2
      CASE(8)
         VAL%E11=RES
      CASE(9)
         VAL%E22=RES
      CASE(10)
         VAL%E33=RES
      CASE(11)
         VAL%E44=RES
      CASE(12)
         VAL%E55=RES
      CASE(13)
         VAL%E66=RES
      CASE(14)
         VAL%E77=RES

      ! Order 3
      CASE(15)
         VAL%E111=RES
      CASE(16)
         VAL%E222=RES
      CASE(17)
         VAL%E333=RES
      CASE(18)
         VAL%E444=RES
      CASE(19)
         VAL%E555=RES
      CASE(20)
         VAL%E666=RES
      CASE(21)
         VAL%E777=RES

      END SELECT
   END SUBROUTINE DONUMM7N3_SETIM_M

FUNCTION DONUMM7N3_GETIM_S(VAL,IDX) RESULT(RES)
      IMPLICIT NONE
      TYPE(DONUMM7N3), INTENT(IN) :: VAL
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
      CASE(4)
         RES=VAL%E4
      CASE(5)
         RES=VAL%E5
      CASE(6)
         RES=VAL%E6
      CASE(7)
         RES=VAL%E7

      ! Order 2
      CASE(8)
         RES=VAL%E11
      CASE(9)
         RES=VAL%E22
      CASE(10)
         RES=VAL%E33
      CASE(11)
         RES=VAL%E44
      CASE(12)
         RES=VAL%E55
      CASE(13)
         RES=VAL%E66
      CASE(14)
         RES=VAL%E77

      ! Order 3
      CASE(15)
         RES=VAL%E111
      CASE(16)
         RES=VAL%E222
      CASE(17)
         RES=VAL%E333
      CASE(18)
         RES=VAL%E444
      CASE(19)
         RES=VAL%E555
      CASE(20)
         RES=VAL%E666
      CASE(21)
         RES=VAL%E777

      END SELECT
   END FUNCTION DONUMM7N3_GETIM_S

FUNCTION DONUMM7N3_GETIM_V(VAL,IDX) RESULT(RES)
      IMPLICIT NONE
      TYPE(DONUMM7N3), INTENT(IN) :: VAL(:)
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
      CASE(4)
         RES=VAL%E4
      CASE(5)
         RES=VAL%E5
      CASE(6)
         RES=VAL%E6
      CASE(7)
         RES=VAL%E7

      ! Order 2
      CASE(8)
         RES=VAL%E11
      CASE(9)
         RES=VAL%E22
      CASE(10)
         RES=VAL%E33
      CASE(11)
         RES=VAL%E44
      CASE(12)
         RES=VAL%E55
      CASE(13)
         RES=VAL%E66
      CASE(14)
         RES=VAL%E77

      ! Order 3
      CASE(15)
         RES=VAL%E111
      CASE(16)
         RES=VAL%E222
      CASE(17)
         RES=VAL%E333
      CASE(18)
         RES=VAL%E444
      CASE(19)
         RES=VAL%E555
      CASE(20)
         RES=VAL%E666
      CASE(21)
         RES=VAL%E777

      END SELECT
   END FUNCTION DONUMM7N3_GETIM_V

FUNCTION DONUMM7N3_GETIM_M(VAL,IDX) RESULT(RES)
      IMPLICIT NONE
      TYPE(DONUMM7N3), INTENT(IN) :: VAL(:,:)
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
      CASE(4)
         RES=VAL%E4
      CASE(5)
         RES=VAL%E5
      CASE(6)
         RES=VAL%E6
      CASE(7)
         RES=VAL%E7

      ! Order 2
      CASE(8)
         RES=VAL%E11
      CASE(9)
         RES=VAL%E22
      CASE(10)
         RES=VAL%E33
      CASE(11)
         RES=VAL%E44
      CASE(12)
         RES=VAL%E55
      CASE(13)
         RES=VAL%E66
      CASE(14)
         RES=VAL%E77

      ! Order 3
      CASE(15)
         RES=VAL%E111
      CASE(16)
         RES=VAL%E222
      CASE(17)
         RES=VAL%E333
      CASE(18)
         RES=VAL%E444
      CASE(19)
         RES=VAL%E555
      CASE(20)
         RES=VAL%E666
      CASE(21)
         RES=VAL%E777

      END SELECT
   END FUNCTION DONUMM7N3_GETIM_M

   SUBROUTINE DONUMM7N3_PPRINT_S(VAR,FMT,UNIT)
      IMPLICIT NONE
      TYPE(DONUMM7N3), INTENT(IN) :: VAR
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
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'E4 * '
      CALL PPRINT(VAR%E4,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'E5 * '
      CALL PPRINT(VAR%E5,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'E6 * '
      CALL PPRINT(VAR%E6,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'E7 * '
      CALL PPRINT(VAR%E7,unit=unt,fmt=output_format)

      !  Order 2
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'E11 * '
      CALL PPRINT(VAR%E11,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'E22 * '
      CALL PPRINT(VAR%E22,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'E33 * '
      CALL PPRINT(VAR%E33,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'E44 * '
      CALL PPRINT(VAR%E44,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'E55 * '
      CALL PPRINT(VAR%E55,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'E66 * '
      CALL PPRINT(VAR%E66,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'E77 * '
      CALL PPRINT(VAR%E77,unit=unt,fmt=output_format)

      !  Order 3
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'E111 * '
      CALL PPRINT(VAR%E111,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'E222 * '
      CALL PPRINT(VAR%E222,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'E333 * '
      CALL PPRINT(VAR%E333,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'E444 * '
      CALL PPRINT(VAR%E444,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'E555 * '
      CALL PPRINT(VAR%E555,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'E666 * '
      CALL PPRINT(VAR%E666,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'E777 * '
      CALL PPRINT(VAR%E777,unit=unt,fmt=output_format)


   END SUBROUTINE DONUMM7N3_PPRINT_S

   SUBROUTINE DONUMM7N3_PPRINT_V(VAR,FMT,UNIT)
      IMPLICIT NONE
      TYPE(DONUMM7N3), INTENT(IN) :: VAR(:)
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
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E4 * '
      CALL PPRINT(VAR%E4,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E5 * '
      CALL PPRINT(VAR%E5,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E6 * '
      CALL PPRINT(VAR%E6,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E7 * '
      CALL PPRINT(VAR%E7,unit=unt,fmt=output_format)

      !  Order 2
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E11 * '
      CALL PPRINT(VAR%E11,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E22 * '
      CALL PPRINT(VAR%E22,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E33 * '
      CALL PPRINT(VAR%E33,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E44 * '
      CALL PPRINT(VAR%E44,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E55 * '
      CALL PPRINT(VAR%E55,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E66 * '
      CALL PPRINT(VAR%E66,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E77 * '
      CALL PPRINT(VAR%E77,unit=unt,fmt=output_format)

      !  Order 3
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E111 * '
      CALL PPRINT(VAR%E111,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E222 * '
      CALL PPRINT(VAR%E222,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E333 * '
      CALL PPRINT(VAR%E333,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E444 * '
      CALL PPRINT(VAR%E444,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E555 * '
      CALL PPRINT(VAR%E555,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E666 * '
      CALL PPRINT(VAR%E666,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E777 * '
      CALL PPRINT(VAR%E777,unit=unt,fmt=output_format)


   END SUBROUTINE DONUMM7N3_PPRINT_V

   SUBROUTINE DONUMM7N3_PPRINT_M(VAR,FMT,UNIT)
      IMPLICIT NONE
      TYPE(DONUMM7N3), INTENT(IN) :: VAR(:,:)
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
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E4 * '
      CALL PPRINT(VAR%E4,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E5 * '
      CALL PPRINT(VAR%E5,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E6 * '
      CALL PPRINT(VAR%E6,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E7 * '
      CALL PPRINT(VAR%E7,unit=unt,fmt=output_format)

      !  Order 2
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E11 * '
      CALL PPRINT(VAR%E11,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E22 * '
      CALL PPRINT(VAR%E22,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E33 * '
      CALL PPRINT(VAR%E33,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E44 * '
      CALL PPRINT(VAR%E44,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E55 * '
      CALL PPRINT(VAR%E55,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E66 * '
      CALL PPRINT(VAR%E66,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E77 * '
      CALL PPRINT(VAR%E77,unit=unt,fmt=output_format)

      !  Order 3
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E111 * '
      CALL PPRINT(VAR%E111,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E222 * '
      CALL PPRINT(VAR%E222,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E333 * '
      CALL PPRINT(VAR%E333,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E444 * '
      CALL PPRINT(VAR%E444,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E555 * '
      CALL PPRINT(VAR%E555,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E666 * '
      CALL PPRINT(VAR%E666,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'E777 * '
      CALL PPRINT(VAR%E777,unit=unt,fmt=output_format)


   END SUBROUTINE DONUMM7N3_PPRINT_M

   ELEMENTAL FUNCTION DONUMM7N3_FEVAL(X,DER0,DER1,DER2,DER3)&
      RESULT(RES)
      IMPLICIT NONE
      !  Definitions
      REAL(DP) :: FACTOR, COEF
      TYPE(DONUMM7N3), INTENT(IN)  :: X
      REAL(DP), INTENT(IN)  :: DER0,DER1,DER2,DER3
      TYPE(DONUMM7N3) :: RES
      TYPE(DONUMM7N3) :: DX, DX_P

      FACTOR = 1.0_DP
      COEF   = 0.0_DP
      DX     = X
      DX_P   = X

      !  Set real part of deltas zero.
      DX%R = 0.0_dp
      DX_P%R = 0.0_dp

      ! Sets real part
      RES = DER0

      ! Sets order 1
      FACTOR = FACTOR * 1
      COEF = DER1 / FACTOR
      ! RES = RES COEF * DX_P
      ! Order 3
      RES%E111 = RES%E111+COEF*DX_P%E111
      RES%E222 = RES%E222+COEF*DX_P%E222
      RES%E333 = RES%E333+COEF*DX_P%E333
      RES%E444 = RES%E444+COEF*DX_P%E444
      RES%E555 = RES%E555+COEF*DX_P%E555
      RES%E666 = RES%E666+COEF*DX_P%E666
      RES%E777 = RES%E777+COEF*DX_P%E777
      ! Order 2
      RES%E11 = RES%E11+COEF*DX_P%E11
      RES%E22 = RES%E22+COEF*DX_P%E22
      RES%E33 = RES%E33+COEF*DX_P%E33
      RES%E44 = RES%E44+COEF*DX_P%E44
      RES%E55 = RES%E55+COEF*DX_P%E55
      RES%E66 = RES%E66+COEF*DX_P%E66
      RES%E77 = RES%E77+COEF*DX_P%E77
      ! Order 1
      RES%E1 = RES%E1+COEF*DX_P%E1
      RES%E2 = RES%E2+COEF*DX_P%E2
      RES%E3 = RES%E3+COEF*DX_P%E3
      RES%E4 = RES%E4+COEF*DX_P%E4
      RES%E5 = RES%E5+COEF*DX_P%E5
      RES%E6 = RES%E6+COEF*DX_P%E6
      RES%E7 = RES%E7+COEF*DX_P%E7
      ! DX_P = DX_P * DX
      ! Order 3
      DX_P%E111 = DX_P%E1*DX%E11+DX_P%E11*DX%E1
      DX_P%E222 = DX_P%E2*DX%E22+DX_P%E22*DX%E2
      DX_P%E333 = DX_P%E3*DX%E33+DX_P%E33*DX%E3
      DX_P%E444 = DX_P%E4*DX%E44+DX_P%E44*DX%E4
      DX_P%E555 = DX_P%E5*DX%E55+DX_P%E55*DX%E5
      DX_P%E666 = DX_P%E6*DX%E66+DX_P%E66*DX%E6
      DX_P%E777 = DX_P%E7*DX%E77+DX_P%E77*DX%E7
      ! Order 2
      DX_P%E11 = DX_P%E1*DX%E1
      DX_P%E22 = DX_P%E2*DX%E2
      DX_P%E33 = DX_P%E3*DX%E3
      DX_P%E44 = DX_P%E4*DX%E4
      DX_P%E55 = DX_P%E5*DX%E5
      DX_P%E66 = DX_P%E6*DX%E6
      DX_P%E77 = DX_P%E7*DX%E7
      
      ! Sets order 2
      FACTOR = FACTOR * 2
      COEF = DER2 / FACTOR
      ! RES = RES COEF * DX_P
      ! Order 3
      RES%E111 = RES%E111+COEF*DX_P%E111
      RES%E222 = RES%E222+COEF*DX_P%E222
      RES%E333 = RES%E333+COEF*DX_P%E333
      RES%E444 = RES%E444+COEF*DX_P%E444
      RES%E555 = RES%E555+COEF*DX_P%E555
      RES%E666 = RES%E666+COEF*DX_P%E666
      RES%E777 = RES%E777+COEF*DX_P%E777
      ! Order 2
      RES%E11 = RES%E11+COEF*DX_P%E11
      RES%E22 = RES%E22+COEF*DX_P%E22
      RES%E33 = RES%E33+COEF*DX_P%E33
      RES%E44 = RES%E44+COEF*DX_P%E44
      RES%E55 = RES%E55+COEF*DX_P%E55
      RES%E66 = RES%E66+COEF*DX_P%E66
      RES%E77 = RES%E77+COEF*DX_P%E77
      ! DX_P = DX_P * DX
      ! Order 3
      DX_P%E111 = DX_P%E11*DX%E1
      DX_P%E222 = DX_P%E22*DX%E2
      DX_P%E333 = DX_P%E33*DX%E3
      DX_P%E444 = DX_P%E44*DX%E4
      DX_P%E555 = DX_P%E55*DX%E5
      DX_P%E666 = DX_P%E66*DX%E6
      DX_P%E777 = DX_P%E77*DX%E7
      
      ! Sets order 3
      FACTOR = FACTOR * 3
      COEF = DER3 / FACTOR
      ! RES = RES COEF * DX_P
      ! Order 3
      RES%E111 = RES%E111+COEF*DX_P%E111
      RES%E222 = RES%E222+COEF*DX_P%E222
      RES%E333 = RES%E333+COEF*DX_P%E333
      RES%E444 = RES%E444+COEF*DX_P%E444
      RES%E555 = RES%E555+COEF*DX_P%E555
      RES%E666 = RES%E666+COEF*DX_P%E666
      RES%E777 = RES%E777+COEF*DX_P%E777
      
   END FUNCTION DONUMM7N3_FEVAL


  ! SUBROUTINE DONUMM7N3_PPRINT_M_R(X, FMT)
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

  ! END SUBROUTINE DONUMM7N3_PPRINT_M_R

  ! SUBROUTINE DONUMM7N3_PPRINT_V_R(X, FMT)
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

  ! END SUBROUTINE DONUMM7N3_PPRINT_V_R

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
  PURE FUNCTION DONUMM7N3_det2x2(A) RESULT(det)

    IMPLICIT NONE

    TYPE(DONUMM7N3), INTENT(IN) :: A(2,2)   !! Matrix
    TYPE(DONUMM7N3)             :: det

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
  PURE FUNCTION DONUMM7N3_det3x3(A) RESULT(det)
      
    IMPLICIT NONE

    TYPE(DONUMM7N3), INTENT(IN) :: A(3,3)   !! Matrix
    TYPE(DONUMM7N3)             :: det

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
  PURE FUNCTION DONUMM7N3_det4x4(A) RESULT(det)
      
    IMPLICIT NONE

    TYPE(DONUMM7N3), INTENT(IN) :: A(4,4)   !! Matrix
    TYPE(DONUMM7N3)             :: det

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
  PURE FUNCTION DONUMM7N3_cross3(a,b) RESULT(v)
      
    IMPLICIT NONE 

    TYPE(DONUMM7N3), DIMENSION (3),INTENT(IN) :: a,b
    TYPE(DONUMM7N3), DIMENSION (3) :: v
    
    v(1) = a(2) * b(3) - a(3) * b(2)
    v(2) = a(3) * b(1) - a(1) * b(3)
    v(3) = a(1) * b(2) - a(2) * b(1)

  END FUNCTION DONUMM7N3_cross3
  !===================================================================================================! 

  !***************************************************************************************************! 
  !> @brief Norm of a 3 element vector. # There is an intrinsic function named norm2.
  !!
  !! @param[in] a: Vector of 3 reals (rank 1).
  !! @param[in] b: Vector of 3 reals (rank 1).
  !!
  !***************************************************************************************************!
  FUNCTION DONUMM7N3_norm2_3(v) RESULT(n)
     
    IMPLICIT NONE 

    TYPE(DONUMM7N3), INTENT(IN) :: v(3)
    TYPE(DONUMM7N3) :: n
     
    n = SQRT( v(1)*v(1) + v(2)*v(2) + v(3)*v(3) )

  END FUNCTION DONUMM7N3_norm2_3
  !===================================================================================================! 

  ELEMENTAL FUNCTION DONUMM7N3_DIVISION_OO(X,Y) RESULT(RES)
      IMPLICIT NONE
      ! REAL(DP) :: DERIVS(TORDER + 1) 
      TYPE(DONUMM7N3), INTENT(IN) :: X
      TYPE(DONUMM7N3), INTENT(IN) :: Y
      TYPE(DONUMM7N3) :: RES

      RES = X*(Y**(-1.d0))

  END FUNCTION DONUMM7N3_DIVISION_OO

  ELEMENTAL FUNCTION DONUMM7N3_DIVISION_OR(X,Y) RESULT(RES)
      IMPLICIT NONE
      ! REAL(DP) :: DERIVS(TORDER + 1) 
      TYPE(DONUMM7N3), INTENT(IN) :: X
      REAL(DP), INTENT(IN) :: Y
      TYPE(DONUMM7N3) :: RES

      RES = X*(Y**(-1.d0))

  END FUNCTION DONUMM7N3_DIVISION_OR

  ELEMENTAL FUNCTION DONUMM7N3_DIVISION_RO(X,Y) RESULT(RES)
      IMPLICIT NONE
      ! REAL(DP) :: DERIVS(TORDER + 1) 
      REAL(DP), INTENT(IN) :: X
      TYPE(DONUMM7N3), INTENT(IN) :: Y
      TYPE(DONUMM7N3) :: RES

      RES = X*(Y**(-1.d0))

  END FUNCTION DONUMM7N3_DIVISION_RO

  ELEMENTAL FUNCTION DONUMM7N3_REAL(X) RESULT(RES)
      IMPLICIT NONE
      TYPE(DONUMM7N3), INTENT(IN) :: X
      REAL(DP) :: RES

      RES = X%R

  END FUNCTION DONUMM7N3_REAL

  FUNCTION DONUMM7N3_SQRT(X) RESULT(RES)
      IMPLICIT NONE
      TYPE(DONUMM7N3), INTENT(IN) :: X
      TYPE(DONUMM7N3) :: RES

      RES = X**0.5_DP

  END FUNCTION DONUMM7N3_SQRT

   ELEMENTAL FUNCTION DONUMM7N3_TAN(X) RESULT(RES)

      TYPE(DONUMM7N3), INTENT(IN) :: X
      REAL(DP) :: DER0,DER1,DER2,DER3
      TYPE(DONUMM7N3) :: RES
      
      DER0 = TAN(X%R)
      DER1 = TAN(X%R)**2 + 1
      DER2 = 2*(TAN(X%R)**2 + 1)*TAN(X%R)
      DER3 = 2*(TAN(X%R)**2 + 1)*(3*TAN(X%R)**2 + 1)

      RES = FEVAL(X,DER0,DER1,DER2,DER3)

   END FUNCTION DONUMM7N3_TAN

   ELEMENTAL FUNCTION DONUMM7N3_COS(X) RESULT(RES)

      TYPE(DONUMM7N3), INTENT(IN) :: X
      REAL(DP) :: DER0,DER1,DER2,DER3
      TYPE(DONUMM7N3) :: RES
      
      DER0 = COS(X%R)
      DER1 = -SIN(X%R)
      DER2 = -COS(X%R)
      DER3 = SIN(X%R)

      RES = FEVAL(X,DER0,DER1,DER2,DER3)

   END FUNCTION DONUMM7N3_COS

   ELEMENTAL FUNCTION DONUMM7N3_SIN(X) RESULT(RES)

      TYPE(DONUMM7N3), INTENT(IN) :: X
      REAL(DP) :: DER0,DER1,DER2,DER3
      TYPE(DONUMM7N3) :: RES
      
      DER0 = SIN(X%R)
      DER1 = COS(X%R)
      DER2 = -SIN(X%R)
      DER3 = -COS(X%R)

      RES = FEVAL(X,DER0,DER1,DER2,DER3)

   END FUNCTION DONUMM7N3_SIN

   ELEMENTAL FUNCTION DONUMM7N3_ATAN(X) RESULT(RES)

      TYPE(DONUMM7N3), INTENT(IN) :: X
      REAL(DP) :: DER0,DER1,DER2,DER3
      TYPE(DONUMM7N3) :: RES
      
      DER0 = ATAN(X%R)
      DER1 = 1D0/(X%R**2 + 1)
      DER2 = -2*X%R/(X%R**2 + 1)**2
      DER3 = 2*(4*X%R**2/(X%R**2 + 1) - 1)/(X%R**2 + 1)**2

      RES = FEVAL(X,DER0,DER1,DER2,DER3)

   END FUNCTION DONUMM7N3_ATAN

   ELEMENTAL FUNCTION DONUMM7N3_ACOS(X) RESULT(RES)

      TYPE(DONUMM7N3), INTENT(IN) :: X
      REAL(DP) :: DER0,DER1,DER2,DER3
      TYPE(DONUMM7N3) :: RES
      
      DER0 = ACOS(X%R)
      DER1 = -1/SQRT(1 - X%R**2)
      DER2 = -X%R/(1 - X%R**2)**(3.0D0/2.0D0)
      DER3 = -(3*X%R**2/(1 - X%R**2) + 1)/(1 - X%R**2)**(3.0D0/2.0D0)

      RES = FEVAL(X,DER0,DER1,DER2,DER3)

   END FUNCTION DONUMM7N3_ACOS

   ELEMENTAL FUNCTION DONUMM7N3_ASIN(X) RESULT(RES)

      TYPE(DONUMM7N3), INTENT(IN) :: X
      REAL(DP) :: DER0,DER1,DER2,DER3
      TYPE(DONUMM7N3) :: RES
      
      DER0 = ASIN(X%R)
      DER1 = 1/SQRT(1 - X%R**2)
      DER2 = X%R/(1 - X%R**2)**(3.0D0/2.0D0)
      DER3 = (3*X%R**2/(1 - X%R**2) + 1)/(1 - X%R**2)**(3.0D0/2.0D0)

      RES = FEVAL(X,DER0,DER1,DER2,DER3)

   END FUNCTION DONUMM7N3_ASIN

   ELEMENTAL FUNCTION DONUMM7N3_TANH(X) RESULT(RES)

      TYPE(DONUMM7N3), INTENT(IN) :: X
      REAL(DP) :: DER0,DER1,DER2,DER3
      TYPE(DONUMM7N3) :: RES
      
      DER0 = TANH(X%R)
      DER1 = 1 - TANH(X%R)**2
      DER2 = 2*(TANH(X%R)**2 - 1)*TANH(X%R)
      DER3 = -2*(TANH(X%R)**2 - 1)*(3*TANH(X%R)**2 - 1)

      RES = FEVAL(X,DER0,DER1,DER2,DER3)

   END FUNCTION DONUMM7N3_TANH

   ELEMENTAL FUNCTION DONUMM7N3_COSH(X) RESULT(RES)

      TYPE(DONUMM7N3), INTENT(IN) :: X
      REAL(DP) :: DER0,DER1,DER2,DER3
      TYPE(DONUMM7N3) :: RES
      
      DER0 = COSH(X%R)
      DER1 = SINH(X%R)
      DER2 = COSH(X%R)
      DER3 = SINH(X%R)

      RES = FEVAL(X,DER0,DER1,DER2,DER3)

   END FUNCTION DONUMM7N3_COSH

   ELEMENTAL FUNCTION DONUMM7N3_SINH(X) RESULT(RES)

      TYPE(DONUMM7N3), INTENT(IN) :: X
      REAL(DP) :: DER0,DER1,DER2,DER3
      TYPE(DONUMM7N3) :: RES
      
      DER0 = SINH(X%R)
      DER1 = COSH(X%R)
      DER2 = SINH(X%R)
      DER3 = COSH(X%R)

      RES = FEVAL(X,DER0,DER1,DER2,DER3)

   END FUNCTION DONUMM7N3_SINH

   ELEMENTAL FUNCTION DONUMM7N3_EXP(X) RESULT(RES)

      TYPE(DONUMM7N3), INTENT(IN) :: X
      REAL(DP) :: DER0,DER1,DER2,DER3
      TYPE(DONUMM7N3) :: RES
      
      DER0 = EXP(X%R)
      DER1 = EXP(X%R)
      DER2 = EXP(X%R)
      DER3 = EXP(X%R)

      RES = FEVAL(X,DER0,DER1,DER2,DER3)

   END FUNCTION DONUMM7N3_EXP

   ELEMENTAL FUNCTION DONUMM7N3_LOG(X) RESULT(RES)

      TYPE(DONUMM7N3), INTENT(IN) :: X
      REAL(DP) :: DER0,DER1,DER2,DER3
      TYPE(DONUMM7N3) :: RES
      
      DER0 = LOG(X%R)
      DER1 = 1D0/X%R
      DER2 = -1/X%R**2
      DER3 = 2/X%R**3

      RES = FEVAL(X,DER0,DER1,DER2,DER3)

   END FUNCTION DONUMM7N3_LOG

   ELEMENTAL FUNCTION DONUMM7N3_POW_OR(X,E) RESULT(RES)

      TYPE(DONUMM7N3), INTENT(IN) :: X
      REAL(DP), INTENT(IN) :: E
      REAL(DP) :: DER0,DER1,DER2,DER3
      TYPE(DONUMM7N3) :: RES
      
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

   END FUNCTION DONUMM7N3_POW_OR

   ELEMENTAL FUNCTION DONUMM7N3_POW_RO(E,X) RESULT(RES)

      TYPE(DONUMM7N3), INTENT(IN) :: X
      REAL(DP), INTENT(IN) :: E
      REAL(DP) :: DER0,DER1,DER2,DER3
      TYPE(DONUMM7N3) :: RES
      
      
      DER0 = E**X%R
      DER1 = E**X%R*LOG(E)
      DER2 = E**X%R*LOG(E)**2
      DER3 = E**X%R*LOG(E)**3

      RES = FEVAL(X,DER0,DER1,DER2,DER3)

   END FUNCTION DONUMM7N3_POW_RO

   ELEMENTAL FUNCTION DONUMM7N3_F2EVAL(X,Y,DER0_0,DER1_0,DER1_1, &
                                   DER2_0,DER2_1,DER2_2,DER3_0, &
                                   DER3_1,DER3_2,DER3_3)&
      RESULT(RES)
      IMPLICIT NONE
      !  Definitions
      REAL(DP) :: COEF, DELTA
      TYPE(DONUMM7N3), INTENT(IN)  :: X,Y
      REAL(DP), INTENT(IN)  :: DER0_0,DER1_0,DER1_1, &
                               DER2_0,DER2_1,DER2_2,DER3_0, &
                               DER3_1,DER3_2,DER3_3
      TYPE(DONUMM7N3) :: RES
      TYPE(DONUMM7N3) :: DX, DY

      COEF   = 0.0_DP
      DX     = X
      DY     = Y

      !  Set real part of deltas zero.
      DX%R = 0.0_dp
      DY%R = 0.0_dp

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

      

   END FUNCTION DONUMM7N3_F2EVAL


   ELEMENTAL FUNCTION DONUMM7N3_POW_OO(X,Y) RESULT(RES)

      TYPE(DONUMM7N3), INTENT(IN) :: X, Y
      REAL(DP) :: DER0_0,DER1_0,DER1_1,DER2_0,DER2_1,DER2_2,DER3_0,DER3_1,DER3_2,DER3_3
      TYPE(DONUMM7N3) :: RES
      
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

   END FUNCTION DONUMM7N3_POW_OO


   FUNCTION DONUMM7N3_INV2X2(A,det)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(DONUMM7N3) , INTENT(IN) :: A(2,2) 
      TYPE(DONUMM7N3) , INTENT(IN), OPTIONAL :: det
      REAL(DP) :: detCalc
      TYPE(DONUMM7N3) :: RES(SIZE(A,1),SIZE(A,2)) 

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
      RES%E4=-MATMUL(RES%R,(MATMUL(A%E4,RES%R)))
      RES%E5=-MATMUL(RES%R,(MATMUL(A%E5,RES%R)))
      RES%E6=-MATMUL(RES%R,(MATMUL(A%E6,RES%R)))
      RES%E7=-MATMUL(RES%R,(MATMUL(A%E7,RES%R)))

      ! Order 2
      RES%E11=-MATMUL(RES%R,(MATMUL(A%E11,RES%R)+MATMUL(A%E1,RES%E1)))
      RES%E22=-MATMUL(RES%R,(MATMUL(A%E22,RES%R)+MATMUL(A%E2,RES%E2)))
      RES%E33=-MATMUL(RES%R,(MATMUL(A%E33,RES%R)+MATMUL(A%E3,RES%E3)))
      RES%E44=-MATMUL(RES%R,(MATMUL(A%E44,RES%R)+MATMUL(A%E4,RES%E4)))
      RES%E55=-MATMUL(RES%R,(MATMUL(A%E55,RES%R)+MATMUL(A%E5,RES%E5)))
      RES%E66=-MATMUL(RES%R,(MATMUL(A%E66,RES%R)+MATMUL(A%E6,RES%E6)))
      RES%E77=-MATMUL(RES%R,(MATMUL(A%E77,RES%R)+MATMUL(A%E7,RES%E7)))

      ! Order 3
      RES%E111=-MATMUL(RES%R,(MATMUL(A%E111,RES%R)+MATMUL(A%E1,RES%E11)+&
              MATMUL(A%E11,RES%E1)))
      RES%E222=-MATMUL(RES%R,(MATMUL(A%E222,RES%R)+MATMUL(A%E2,RES%E22)+&
              MATMUL(A%E22,RES%E2)))
      RES%E333=-MATMUL(RES%R,(MATMUL(A%E333,RES%R)+MATMUL(A%E3,RES%E33)+&
              MATMUL(A%E33,RES%E3)))
      RES%E444=-MATMUL(RES%R,(MATMUL(A%E444,RES%R)+MATMUL(A%E4,RES%E44)+&
              MATMUL(A%E44,RES%E4)))
      RES%E555=-MATMUL(RES%R,(MATMUL(A%E555,RES%R)+MATMUL(A%E5,RES%E55)+&
              MATMUL(A%E55,RES%E5)))
      RES%E666=-MATMUL(RES%R,(MATMUL(A%E666,RES%R)+MATMUL(A%E6,RES%E66)+&
              MATMUL(A%E66,RES%E6)))
      RES%E777=-MATMUL(RES%R,(MATMUL(A%E777,RES%R)+MATMUL(A%E7,RES%E77)+&
              MATMUL(A%E77,RES%E7)))

   END FUNCTION DONUMM7N3_INV2X2

   FUNCTION DONUMM7N3_INV3X3(A,det)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(DONUMM7N3) , INTENT(IN) :: A(3,3) 
      TYPE(DONUMM7N3) , INTENT(IN), OPTIONAL :: det
      REAL(DP) :: detCalc
      TYPE(DONUMM7N3) :: RES(SIZE(A,1),SIZE(A,2)) 

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
      RES%E4=-MATMUL(RES%R,(MATMUL(A%E4,RES%R)))
      RES%E5=-MATMUL(RES%R,(MATMUL(A%E5,RES%R)))
      RES%E6=-MATMUL(RES%R,(MATMUL(A%E6,RES%R)))
      RES%E7=-MATMUL(RES%R,(MATMUL(A%E7,RES%R)))

      ! Order 2
      RES%E11=-MATMUL(RES%R,(MATMUL(A%E11,RES%R)+MATMUL(A%E1,RES%E1)))
      RES%E22=-MATMUL(RES%R,(MATMUL(A%E22,RES%R)+MATMUL(A%E2,RES%E2)))
      RES%E33=-MATMUL(RES%R,(MATMUL(A%E33,RES%R)+MATMUL(A%E3,RES%E3)))
      RES%E44=-MATMUL(RES%R,(MATMUL(A%E44,RES%R)+MATMUL(A%E4,RES%E4)))
      RES%E55=-MATMUL(RES%R,(MATMUL(A%E55,RES%R)+MATMUL(A%E5,RES%E5)))
      RES%E66=-MATMUL(RES%R,(MATMUL(A%E66,RES%R)+MATMUL(A%E6,RES%E6)))
      RES%E77=-MATMUL(RES%R,(MATMUL(A%E77,RES%R)+MATMUL(A%E7,RES%E7)))

      ! Order 3
      RES%E111=-MATMUL(RES%R,(MATMUL(A%E111,RES%R)+MATMUL(A%E1,RES%E11)+&
              MATMUL(A%E11,RES%E1)))
      RES%E222=-MATMUL(RES%R,(MATMUL(A%E222,RES%R)+MATMUL(A%E2,RES%E22)+&
              MATMUL(A%E22,RES%E2)))
      RES%E333=-MATMUL(RES%R,(MATMUL(A%E333,RES%R)+MATMUL(A%E3,RES%E33)+&
              MATMUL(A%E33,RES%E3)))
      RES%E444=-MATMUL(RES%R,(MATMUL(A%E444,RES%R)+MATMUL(A%E4,RES%E44)+&
              MATMUL(A%E44,RES%E4)))
      RES%E555=-MATMUL(RES%R,(MATMUL(A%E555,RES%R)+MATMUL(A%E5,RES%E55)+&
              MATMUL(A%E55,RES%E5)))
      RES%E666=-MATMUL(RES%R,(MATMUL(A%E666,RES%R)+MATMUL(A%E6,RES%E66)+&
              MATMUL(A%E66,RES%E6)))
      RES%E777=-MATMUL(RES%R,(MATMUL(A%E777,RES%R)+MATMUL(A%E7,RES%E77)+&
              MATMUL(A%E77,RES%E7)))

   END FUNCTION DONUMM7N3_INV3X3

   FUNCTION DONUMM7N3_INV4X4(A,det)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(DONUMM7N3) , INTENT(IN) :: A(4,4) 
      TYPE(DONUMM7N3) , INTENT(IN), OPTIONAL :: det
      REAL(DP) :: detCalc
      TYPE(DONUMM7N3) :: RES(SIZE(A,1),SIZE(A,2)) 

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
      RES%E4=-MATMUL(RES%R,(MATMUL(A%E4,RES%R)))
      RES%E5=-MATMUL(RES%R,(MATMUL(A%E5,RES%R)))
      RES%E6=-MATMUL(RES%R,(MATMUL(A%E6,RES%R)))
      RES%E7=-MATMUL(RES%R,(MATMUL(A%E7,RES%R)))

      ! Order 2
      RES%E11=-MATMUL(RES%R,(MATMUL(A%E11,RES%R)+MATMUL(A%E1,RES%E1)))
      RES%E22=-MATMUL(RES%R,(MATMUL(A%E22,RES%R)+MATMUL(A%E2,RES%E2)))
      RES%E33=-MATMUL(RES%R,(MATMUL(A%E33,RES%R)+MATMUL(A%E3,RES%E3)))
      RES%E44=-MATMUL(RES%R,(MATMUL(A%E44,RES%R)+MATMUL(A%E4,RES%E4)))
      RES%E55=-MATMUL(RES%R,(MATMUL(A%E55,RES%R)+MATMUL(A%E5,RES%E5)))
      RES%E66=-MATMUL(RES%R,(MATMUL(A%E66,RES%R)+MATMUL(A%E6,RES%E6)))
      RES%E77=-MATMUL(RES%R,(MATMUL(A%E77,RES%R)+MATMUL(A%E7,RES%E7)))

      ! Order 3
      RES%E111=-MATMUL(RES%R,(MATMUL(A%E111,RES%R)+MATMUL(A%E1,RES%E11)+&
              MATMUL(A%E11,RES%E1)))
      RES%E222=-MATMUL(RES%R,(MATMUL(A%E222,RES%R)+MATMUL(A%E2,RES%E22)+&
              MATMUL(A%E22,RES%E2)))
      RES%E333=-MATMUL(RES%R,(MATMUL(A%E333,RES%R)+MATMUL(A%E3,RES%E33)+&
              MATMUL(A%E33,RES%E3)))
      RES%E444=-MATMUL(RES%R,(MATMUL(A%E444,RES%R)+MATMUL(A%E4,RES%E44)+&
              MATMUL(A%E44,RES%E4)))
      RES%E555=-MATMUL(RES%R,(MATMUL(A%E555,RES%R)+MATMUL(A%E5,RES%E55)+&
              MATMUL(A%E55,RES%E5)))
      RES%E666=-MATMUL(RES%R,(MATMUL(A%E666,RES%R)+MATMUL(A%E6,RES%E66)+&
              MATMUL(A%E66,RES%E6)))
      RES%E777=-MATMUL(RES%R,(MATMUL(A%E777,RES%R)+MATMUL(A%E7,RES%E77)+&
              MATMUL(A%E77,RES%E7)))

   END FUNCTION DONUMM7N3_INV4X4

END MODULE diagotim7n3
