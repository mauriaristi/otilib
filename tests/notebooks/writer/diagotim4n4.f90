MODULE diagotim4n4

   USE master_parameters
   USE real_utils

   IMPLICIT NONE

   INTEGER, PARAMETER :: num_im_dir = 70
   INTEGER, PARAMETER :: torder     = 4
   INTEGER, PARAMETER :: n_imdir_order(5) = [1,4,4,4,4]

   TYPE donumm4n4
     ! Real
     REAL(DP) :: r
     ! Order 1
     REAL(DP) :: e1
     REAL(DP) :: e2
     REAL(DP) :: e3
     REAL(DP) :: e4
     ! Order 2
     REAL(DP) :: e11
     REAL(DP) :: e22
     REAL(DP) :: e33
     REAL(DP) :: e44
     ! Order 3
     REAL(DP) :: e111
     REAL(DP) :: e222
     REAL(DP) :: e333
     REAL(DP) :: e444
     ! Order 4
     REAL(DP) :: e1111
     REAL(DP) :: e2222
     REAL(DP) :: e3333
     REAL(DP) :: e4444
   END TYPE donumm4n4

   ! Constant imaginary directions.
   ! Order 1
   TYPE(donumm4n4), PARAMETER :: e1 = donumm4n4(0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(donumm4n4), PARAMETER :: e2 = donumm4n4(0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(donumm4n4), PARAMETER :: e3 = donumm4n4(0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(donumm4n4), PARAMETER :: e4 = donumm4n4(0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   ! Order 2
   TYPE(donumm4n4), PARAMETER :: e11 = donumm4n4(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(donumm4n4), PARAMETER :: e22 = donumm4n4(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(donumm4n4), PARAMETER :: e33 = donumm4n4(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(donumm4n4), PARAMETER :: e44 = donumm4n4(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   ! Order 3
   TYPE(donumm4n4), PARAMETER :: e111 = donumm4n4(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(donumm4n4), PARAMETER :: e222 = donumm4n4(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(donumm4n4), PARAMETER :: e333 = donumm4n4(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(donumm4n4), PARAMETER :: e444 = donumm4n4(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp)
   ! Order 4
   TYPE(donumm4n4), PARAMETER :: e1111 = donumm4n4(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp,0.0_dp)
   TYPE(donumm4n4), PARAMETER :: e2222 = donumm4n4(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp,0.0_dp)
   TYPE(donumm4n4), PARAMETER :: e3333 = donumm4n4(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp,0.0_dp)
   TYPE(donumm4n4), PARAMETER :: e4444 = donumm4n4(0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,0.0_dp,1.0_dp)


   INTERFACE OPERATOR(*)
      MODULE PROCEDURE donumm4n4_MUL_OO_SS,donumm4n4_MUL_rO_SS,donumm4n4_MUL_Or_SS,donumm4n4_MUL_OO_VS,&
                       donumm4n4_MUL_rO_VS,donumm4n4_MUL_Or_VS,donumm4n4_MUL_OO_MS,donumm4n4_MUL_rO_MS,&
                       donumm4n4_MUL_Or_MS,donumm4n4_MUL_OO_SV,donumm4n4_MUL_rO_SV,donumm4n4_MUL_Or_SV,&
                       donumm4n4_MUL_OO_SM,donumm4n4_MUL_rO_SM,donumm4n4_MUL_Or_SM
   END INTERFACE

   INTERFACE OPERATOR(+)
      MODULE PROCEDURE donumm4n4_ADD_OO_SS,donumm4n4_ADD_rO_SS,donumm4n4_ADD_Or_SS,donumm4n4_ADD_OO_VS,&
                       donumm4n4_ADD_rO_VS,donumm4n4_ADD_Or_VS,donumm4n4_ADD_OO_MS,donumm4n4_ADD_rO_MS,&
                       donumm4n4_ADD_Or_MS,donumm4n4_ADD_OO_SV,donumm4n4_ADD_rO_SV,donumm4n4_ADD_Or_SV,&
                       donumm4n4_ADD_OO_SM,donumm4n4_ADD_rO_SM,donumm4n4_ADD_Or_SM
   END INTERFACE

   INTERFACE OPERATOR(-)
      MODULE PROCEDURE donumm4n4_NEG,donumm4n4_SUB_OO_SS,donumm4n4_SUB_rO_SS,donumm4n4_SUB_Or_SS,&
                       donumm4n4_SUB_OO_VS,donumm4n4_SUB_rO_VS,donumm4n4_SUB_Or_VS,donumm4n4_SUB_OO_MS,&
                       donumm4n4_SUB_rO_MS,donumm4n4_SUB_Or_MS,donumm4n4_SUB_OO_SV,donumm4n4_SUB_rO_SV,&
                       donumm4n4_SUB_Or_SV,donumm4n4_SUB_OO_SM,donumm4n4_SUB_rO_SM,donumm4n4_SUB_Or_SM
   END INTERFACE

   INTERFACE OPERATOR(/)
      MODULE PROCEDURE donumm4n4_DIVISION_OO,donumm4n4_DIVISION_OR,donumm4n4_DIVISION_RO
   END INTERFACE

   INTERFACE ASSIGNMENT(=)
      MODULE PROCEDURE donumm4n4_ASSIGN_o
   END INTERFACE

   INTERFACE OPERATOR(**)
      MODULE PROCEDURE donumm4n4_POW_OR,donumm4n4_POW_RO,donumm4n4_POW_OO
   END INTERFACE

   INTERFACE PPRINT
      MODULE PROCEDURE donumm4n4_PPRINT_S,donumm4n4_PPRINT_V,donumm4n4_PPRINT_M
   END INTERFACE

   INTERFACE TRANSPOSE
      MODULE PROCEDURE donumm4n4_TRANSPOSE
   END INTERFACE

   INTERFACE MATMUL
      MODULE PROCEDURE donumm4n4_MATMUL_donumm4n4,r_MATMUL_donumm4n4,donumm4n4_MATMUL_r
   END INTERFACE

   INTERFACE DOT_PRODUCT
      MODULE PROCEDURE donumm4n4_DOT_PRODUCT_donumm4n4,r_DOT_PRODUCT_donumm4n4,donumm4n4_DOT_PRODUCT_r
   END INTERFACE

   INTERFACE UNFOLD
      MODULE PROCEDURE donumm4n4_TO_CR_MAT_S,donumm4n4_TO_CR_MAT_V,donumm4n4_TO_CR_MAT_M
   END INTERFACE

   INTERFACE TO_CR
      MODULE PROCEDURE donumm4n4_TO_CR_MAT_S,donumm4n4_TO_CR_MAT_V,donumm4n4_TO_CR_MAT_M
   END INTERFACE

   INTERFACE SIN
      MODULE PROCEDURE donumm4n4_SIN
   END INTERFACE

   INTERFACE COS
      MODULE PROCEDURE donumm4n4_COS
   END INTERFACE

   INTERFACE TAN
      MODULE PROCEDURE donumm4n4_TAN
   END INTERFACE

   INTERFACE ASIN
      MODULE PROCEDURE donumm4n4_ASIN
   END INTERFACE

   INTERFACE ACOS
      MODULE PROCEDURE donumm4n4_ACOS
   END INTERFACE

   INTERFACE ATAN
      MODULE PROCEDURE donumm4n4_ATAN
   END INTERFACE

   INTERFACE SINH
      MODULE PROCEDURE donumm4n4_SINH
   END INTERFACE

   INTERFACE COSH
      MODULE PROCEDURE donumm4n4_COSH
   END INTERFACE

   INTERFACE TANH
      MODULE PROCEDURE donumm4n4_TANH
   END INTERFACE

   INTERFACE SQRT
      MODULE PROCEDURE donumm4n4_SQRT
   END INTERFACE

   INTERFACE LOG
      MODULE PROCEDURE donumm4n4_LOG
   END INTERFACE

   INTERFACE EXP
      MODULE PROCEDURE donumm4n4_EXP
   END INTERFACE

   INTERFACE GEM
      MODULE PROCEDURE donumm4n4_GEM_OOO,donumm4n4_GEM_OOO,donumm4n4_GEM_OOO
   END INTERFACE

   INTERFACE FEVAL
      MODULE PROCEDURE donumm4n4_FEVAL
   END INTERFACE

   INTERFACE F2EVAL
      MODULE PROCEDURE donumm4n4_F2EVAL
   END INTERFACE

   INTERFACE REAL
      MODULE PROCEDURE donumm4n4_REAL
   END INTERFACE

   INTERFACE DET2X2
      MODULE PROCEDURE donumm4n4_det2x2
   END INTERFACE

   INTERFACE DET3X3
      MODULE PROCEDURE donumm4n4_det3x3
   END INTERFACE

   INTERFACE DET4X4
      MODULE PROCEDURE donumm4n4_det4x4
   END INTERFACE

   INTERFACE INV2X2
      MODULE PROCEDURE donumm4n4_INV2X2
   END INTERFACE

   INTERFACE INV3X3
      MODULE PROCEDURE donumm4n4_INV3X3
   END INTERFACE

   INTERFACE INV4X4
      MODULE PROCEDURE donumm4n4_INV4X4
   END INTERFACE

   INTERFACE GETIM
      MODULE PROCEDURE donumm4n4_GETIM_S,donumm4n4_GETIM_V,donumm4n4_GETIM_M
   END INTERFACE

   INTERFACE SETIM
      MODULE PROCEDURE donumm4n4_SETIM_S,donumm4n4_SETIM_V,donumm4n4_SETIM_M
   END INTERFACE

   CONTAINS

   ELEMENTAL SUBROUTINE donumm4n4_ASSIGN_o(RES,LHS)
      
      IMPLICIT NONE
      TYPE(donumm4n4), INTENT(IN) :: LHS 
      TYPE(donumm4n4), INTENT(OUT) :: RES 

      ! Assign like function 'LHS'
      ! Real
      RES%r = LHS

      ! Order 1
      RES%e1 = 0.0_dp
      RES%e2 = 0.0_dp
      RES%e3 = 0.0_dp
      RES%e4 = 0.0_dp

      ! Order 2
      RES%e11 = 0.0_dp
      RES%e22 = 0.0_dp
      RES%e33 = 0.0_dp
      RES%e44 = 0.0_dp

      ! Order 3
      RES%e111 = 0.0_dp
      RES%e222 = 0.0_dp
      RES%e333 = 0.0_dp
      RES%e444 = 0.0_dp

      ! Order 4
      RES%e1111 = 0.0_dp
      RES%e2222 = 0.0_dp
      RES%e3333 = 0.0_dp
      RES%e4444 = 0.0_dp

   END SUBROUTINE donumm4n4_ASSIGN_o

   ELEMENTAL FUNCTION donumm4n4_NEG(LHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(donumm4n4), INTENT(IN) :: LHS 
      TYPE(donumm4n4) :: RES 

      ! Negation like function '-LHS'
      ! Real
      RES%r = -LHS%r
      ! Order 1
      RES%e1 = -LHS%e1
      RES%e2 = -LHS%e2
      RES%e3 = -LHS%e3
      RES%e4 = -LHS%e4
      ! Order 2
      RES%e11 = -LHS%e11
      RES%e22 = -LHS%e22
      RES%e33 = -LHS%e33
      RES%e44 = -LHS%e44
      ! Order 3
      RES%e111 = -LHS%e111
      RES%e222 = -LHS%e222
      RES%e333 = -LHS%e333
      RES%e444 = -LHS%e444
      ! Order 4
      RES%e1111 = -LHS%e1111
      RES%e2222 = -LHS%e2222
      RES%e3333 = -LHS%e3333
      RES%e4444 = -LHS%e4444

   END FUNCTION donumm4n4_NEG

   ELEMENTAL FUNCTION donumm4n4_ADD_OO_SS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(donumm4n4), INTENT(IN) :: LHS
      TYPE(donumm4n4), INTENT(IN) :: RHS
      TYPE(donumm4n4) :: RES 

      ! Addition like function 'LHS + RHS'
      !  Real
      RES%r = LHS%r + RHS%r

      ! Order 1
      RES%e1 = LHS%e1 + RHS%e1
      RES%e2 = LHS%e2 + RHS%e2
      RES%e3 = LHS%e3 + RHS%e3
      RES%e4 = LHS%e4 + RHS%e4

      ! Order 2
      RES%e11 = LHS%e11 + RHS%e11
      RES%e22 = LHS%e22 + RHS%e22
      RES%e33 = LHS%e33 + RHS%e33
      RES%e44 = LHS%e44 + RHS%e44

      ! Order 3
      RES%e111 = LHS%e111 + RHS%e111
      RES%e222 = LHS%e222 + RHS%e222
      RES%e333 = LHS%e333 + RHS%e333
      RES%e444 = LHS%e444 + RHS%e444

      ! Order 4
      RES%e1111 = LHS%e1111 + RHS%e1111
      RES%e2222 = LHS%e2222 + RHS%e2222
      RES%e3333 = LHS%e3333 + RHS%e3333
      RES%e4444 = LHS%e4444 + RHS%e4444

   END FUNCTION donumm4n4_ADD_OO_SS

   ELEMENTAL FUNCTION donumm4n4_ADD_rO_SS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS
      TYPE(donumm4n4), INTENT(IN) :: RHS
      TYPE(donumm4n4) :: RES 

      ! Addition like function 'LHS + RHS'
      ! Real
      RES%r = LHS + RHS%r

      ! Order 1
      RES%e1 =  + RHS%e1
      RES%e2 =  + RHS%e2
      RES%e3 =  + RHS%e3
      RES%e4 =  + RHS%e4

      ! Order 2
      RES%e11 =  + RHS%e11
      RES%e22 =  + RHS%e22
      RES%e33 =  + RHS%e33
      RES%e44 =  + RHS%e44

      ! Order 3
      RES%e111 =  + RHS%e111
      RES%e222 =  + RHS%e222
      RES%e333 =  + RHS%e333
      RES%e444 =  + RHS%e444

      ! Order 4
      RES%e1111 =  + RHS%e1111
      RES%e2222 =  + RHS%e2222
      RES%e3333 =  + RHS%e3333
      RES%e4444 =  + RHS%e4444

   END FUNCTION donumm4n4_ADD_rO_SS

   ELEMENTAL FUNCTION donumm4n4_ADD_Or_SS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(donumm4n4), INTENT(IN) :: LHS
      REAL(DP), INTENT(IN) :: RHS
      TYPE(donumm4n4) :: RES 

      ! Addition like function 'LHS + RHS'
      ! Real
      RES%r = LHS%r + RHS

      ! Order 1
      RES%e1 = LHS%e1
      RES%e2 = LHS%e2
      RES%e3 = LHS%e3
      RES%e4 = LHS%e4

      ! Order 2
      RES%e11 = LHS%e11
      RES%e22 = LHS%e22
      RES%e33 = LHS%e33
      RES%e44 = LHS%e44

      ! Order 3
      RES%e111 = LHS%e111
      RES%e222 = LHS%e222
      RES%e333 = LHS%e333
      RES%e444 = LHS%e444

      ! Order 4
      RES%e1111 = LHS%e1111
      RES%e2222 = LHS%e2222
      RES%e3333 = LHS%e3333
      RES%e4444 = LHS%e4444

   END FUNCTION donumm4n4_ADD_Or_SS

   ELEMENTAL FUNCTION donumm4n4_SUB_OO_SS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(donumm4n4), INTENT(IN) :: LHS
      TYPE(donumm4n4), INTENT(IN) :: RHS
      TYPE(donumm4n4) :: RES 

      ! Addition like function 'LHS - RHS'
      !  Real
      RES%r = LHS%r - RHS%r

      ! Order 1
      RES%e1 = LHS%e1 - RHS%e1
      RES%e2 = LHS%e2 - RHS%e2
      RES%e3 = LHS%e3 - RHS%e3
      RES%e4 = LHS%e4 - RHS%e4

      ! Order 2
      RES%e11 = LHS%e11 - RHS%e11
      RES%e22 = LHS%e22 - RHS%e22
      RES%e33 = LHS%e33 - RHS%e33
      RES%e44 = LHS%e44 - RHS%e44

      ! Order 3
      RES%e111 = LHS%e111 - RHS%e111
      RES%e222 = LHS%e222 - RHS%e222
      RES%e333 = LHS%e333 - RHS%e333
      RES%e444 = LHS%e444 - RHS%e444

      ! Order 4
      RES%e1111 = LHS%e1111 - RHS%e1111
      RES%e2222 = LHS%e2222 - RHS%e2222
      RES%e3333 = LHS%e3333 - RHS%e3333
      RES%e4444 = LHS%e4444 - RHS%e4444

   END FUNCTION donumm4n4_SUB_OO_SS

   ELEMENTAL FUNCTION donumm4n4_SUB_rO_SS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS
      TYPE(donumm4n4), INTENT(IN) :: RHS
      TYPE(donumm4n4) :: RES 

      ! Addition like function 'LHS - RHS'
      ! Real
      RES%r = LHS - RHS%r

      ! Order 1
      RES%e1 =  - RHS%e1
      RES%e2 =  - RHS%e2
      RES%e3 =  - RHS%e3
      RES%e4 =  - RHS%e4

      ! Order 2
      RES%e11 =  - RHS%e11
      RES%e22 =  - RHS%e22
      RES%e33 =  - RHS%e33
      RES%e44 =  - RHS%e44

      ! Order 3
      RES%e111 =  - RHS%e111
      RES%e222 =  - RHS%e222
      RES%e333 =  - RHS%e333
      RES%e444 =  - RHS%e444

      ! Order 4
      RES%e1111 =  - RHS%e1111
      RES%e2222 =  - RHS%e2222
      RES%e3333 =  - RHS%e3333
      RES%e4444 =  - RHS%e4444

   END FUNCTION donumm4n4_SUB_rO_SS

   ELEMENTAL FUNCTION donumm4n4_SUB_Or_SS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(donumm4n4), INTENT(IN) :: LHS
      REAL(DP), INTENT(IN) :: RHS
      TYPE(donumm4n4) :: RES 

      ! Addition like function 'LHS - RHS'
      ! Real
      RES%r = LHS%r - RHS

      ! Order 1
      RES%e1 = LHS%e1
      RES%e2 = LHS%e2
      RES%e3 = LHS%e3
      RES%e4 = LHS%e4

      ! Order 2
      RES%e11 = LHS%e11
      RES%e22 = LHS%e22
      RES%e33 = LHS%e33
      RES%e44 = LHS%e44

      ! Order 3
      RES%e111 = LHS%e111
      RES%e222 = LHS%e222
      RES%e333 = LHS%e333
      RES%e444 = LHS%e444

      ! Order 4
      RES%e1111 = LHS%e1111
      RES%e2222 = LHS%e2222
      RES%e3333 = LHS%e3333
      RES%e4444 = LHS%e4444

   END FUNCTION donumm4n4_SUB_Or_SS

   ELEMENTAL FUNCTION donumm4n4_MUL_OO_SS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(donumm4n4), INTENT(IN) :: LHS
      TYPE(donumm4n4), INTENT(IN) :: RHS
      TYPE(donumm4n4) :: RES 

      !  Multiplication like function 'LHS*RHS'
      ! Order 4
      RES%e1111 = LHS%r*RHS%e1111 + LHS%e1111*RHS%r +  &
               LHS%e1*RHS%e111 + LHS%e111*RHS%e1 + LHS%e11*RHS%e11
      RES%e2222 = LHS%r*RHS%e2222 + LHS%e2222*RHS%r +  &
               LHS%e2*RHS%e222 + LHS%e222*RHS%e2 + LHS%e22*RHS%e22
      RES%e3333 = LHS%r*RHS%e3333 + LHS%e3333*RHS%r +  &
               LHS%e3*RHS%e333 + LHS%e333*RHS%e3 + LHS%e33*RHS%e33
      RES%e4444 = LHS%r*RHS%e4444 + LHS%e4444*RHS%r +  &
               LHS%e4*RHS%e444 + LHS%e444*RHS%e4 + LHS%e44*RHS%e44
      ! Order 3
      RES%e111 = LHS%r*RHS%e111 + LHS%e111*RHS%r +  &
              LHS%e1*RHS%e11 + LHS%e11*RHS%e1
      RES%e222 = LHS%r*RHS%e222 + LHS%e222*RHS%r +  &
              LHS%e2*RHS%e22 + LHS%e22*RHS%e2
      RES%e333 = LHS%r*RHS%e333 + LHS%e333*RHS%r +  &
              LHS%e3*RHS%e33 + LHS%e33*RHS%e3
      RES%e444 = LHS%r*RHS%e444 + LHS%e444*RHS%r +  &
              LHS%e4*RHS%e44 + LHS%e44*RHS%e4
      ! Order 2
      RES%e11 = LHS%r*RHS%e11 + LHS%e11*RHS%r + LHS%e1*RHS%e1
      RES%e22 = LHS%r*RHS%e22 + LHS%e22*RHS%r + LHS%e2*RHS%e2
      RES%e33 = LHS%r*RHS%e33 + LHS%e33*RHS%r + LHS%e3*RHS%e3
      RES%e44 = LHS%r*RHS%e44 + LHS%e44*RHS%r + LHS%e4*RHS%e4
      ! Order 1
      RES%e1 = LHS%r*RHS%e1 + LHS%e1*RHS%r
      RES%e2 = LHS%r*RHS%e2 + LHS%e2*RHS%r
      RES%e3 = LHS%r*RHS%e3 + LHS%e3*RHS%r
      RES%e4 = LHS%r*RHS%e4 + LHS%e4*RHS%r
      ! Order 0
      RES%r = LHS%r*RHS%r

   END FUNCTION donumm4n4_MUL_OO_SS

   ELEMENTAL FUNCTION donumm4n4_MUL_rO_SS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS
      TYPE(donumm4n4), INTENT(IN) :: RHS
      TYPE(donumm4n4) :: RES 

      ! Multiplication like function 'LHS*RHS'
      !  Real
      RES%r = LHS*RHS%r

      ! Order 1
      RES%e1 = LHS*RHS%e1
      RES%e2 = LHS*RHS%e2
      RES%e3 = LHS*RHS%e3
      RES%e4 = LHS*RHS%e4

      ! Order 2
      RES%e11 = LHS*RHS%e11
      RES%e22 = LHS*RHS%e22
      RES%e33 = LHS*RHS%e33
      RES%e44 = LHS*RHS%e44

      ! Order 3
      RES%e111 = LHS*RHS%e111
      RES%e222 = LHS*RHS%e222
      RES%e333 = LHS*RHS%e333
      RES%e444 = LHS*RHS%e444

      ! Order 4
      RES%e1111 = LHS*RHS%e1111
      RES%e2222 = LHS*RHS%e2222
      RES%e3333 = LHS*RHS%e3333
      RES%e4444 = LHS*RHS%e4444

   END FUNCTION donumm4n4_MUL_rO_SS

   ELEMENTAL FUNCTION donumm4n4_MUL_Or_SS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(donumm4n4), INTENT(IN) :: LHS
      REAL(DP), INTENT(IN) :: RHS
      TYPE(donumm4n4) :: RES 

      ! Multiplication like function 'LHS*RHS'
      !  Real
      RES%r = LHS%r*RHS

      ! Order 1
      RES%e1 = LHS%e1*RHS
      RES%e2 = LHS%e2*RHS
      RES%e3 = LHS%e3*RHS
      RES%e4 = LHS%e4*RHS

      ! Order 2
      RES%e11 = LHS%e11*RHS
      RES%e22 = LHS%e22*RHS
      RES%e33 = LHS%e33*RHS
      RES%e44 = LHS%e44*RHS

      ! Order 3
      RES%e111 = LHS%e111*RHS
      RES%e222 = LHS%e222*RHS
      RES%e333 = LHS%e333*RHS
      RES%e444 = LHS%e444*RHS

      ! Order 4
      RES%e1111 = LHS%e1111*RHS
      RES%e2222 = LHS%e2222*RHS
      RES%e3333 = LHS%e3333*RHS
      RES%e4444 = LHS%e4444*RHS

   END FUNCTION donumm4n4_MUL_Or_SS

   FUNCTION donumm4n4_ADD_OO_VS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(donumm4n4), INTENT(IN) :: LHS(:)
      TYPE(donumm4n4), INTENT(IN) :: RHS
      TYPE(donumm4n4) :: RES(SIZE(LHS,1)) 

      ! Addition like function 'LHS + RHS'
      !  Real
      RES%r = LHS%r + RHS%r

      ! Order 1
      RES%e1 = LHS%e1 + RHS%e1
      RES%e2 = LHS%e2 + RHS%e2
      RES%e3 = LHS%e3 + RHS%e3
      RES%e4 = LHS%e4 + RHS%e4

      ! Order 2
      RES%e11 = LHS%e11 + RHS%e11
      RES%e22 = LHS%e22 + RHS%e22
      RES%e33 = LHS%e33 + RHS%e33
      RES%e44 = LHS%e44 + RHS%e44

      ! Order 3
      RES%e111 = LHS%e111 + RHS%e111
      RES%e222 = LHS%e222 + RHS%e222
      RES%e333 = LHS%e333 + RHS%e333
      RES%e444 = LHS%e444 + RHS%e444

      ! Order 4
      RES%e1111 = LHS%e1111 + RHS%e1111
      RES%e2222 = LHS%e2222 + RHS%e2222
      RES%e3333 = LHS%e3333 + RHS%e3333
      RES%e4444 = LHS%e4444 + RHS%e4444

   END FUNCTION donumm4n4_ADD_OO_VS

   FUNCTION donumm4n4_ADD_rO_VS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS(:)
      TYPE(donumm4n4), INTENT(IN) :: RHS
      TYPE(donumm4n4) :: RES(SIZE(LHS,1)) 

      ! Addition like function 'LHS + RHS'
      ! Real
      RES%r = LHS + RHS%r

      ! Order 1
      RES%e1 =  + RHS%e1
      RES%e2 =  + RHS%e2
      RES%e3 =  + RHS%e3
      RES%e4 =  + RHS%e4

      ! Order 2
      RES%e11 =  + RHS%e11
      RES%e22 =  + RHS%e22
      RES%e33 =  + RHS%e33
      RES%e44 =  + RHS%e44

      ! Order 3
      RES%e111 =  + RHS%e111
      RES%e222 =  + RHS%e222
      RES%e333 =  + RHS%e333
      RES%e444 =  + RHS%e444

      ! Order 4
      RES%e1111 =  + RHS%e1111
      RES%e2222 =  + RHS%e2222
      RES%e3333 =  + RHS%e3333
      RES%e4444 =  + RHS%e4444

   END FUNCTION donumm4n4_ADD_rO_VS

   FUNCTION donumm4n4_ADD_Or_VS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(donumm4n4), INTENT(IN) :: LHS(:)
      REAL(DP), INTENT(IN) :: RHS
      TYPE(donumm4n4) :: RES(SIZE(LHS,1)) 

      ! Addition like function 'LHS + RHS'
      ! Real
      RES%r = LHS%r + RHS

      ! Order 1
      RES%e1 = LHS%e1
      RES%e2 = LHS%e2
      RES%e3 = LHS%e3
      RES%e4 = LHS%e4

      ! Order 2
      RES%e11 = LHS%e11
      RES%e22 = LHS%e22
      RES%e33 = LHS%e33
      RES%e44 = LHS%e44

      ! Order 3
      RES%e111 = LHS%e111
      RES%e222 = LHS%e222
      RES%e333 = LHS%e333
      RES%e444 = LHS%e444

      ! Order 4
      RES%e1111 = LHS%e1111
      RES%e2222 = LHS%e2222
      RES%e3333 = LHS%e3333
      RES%e4444 = LHS%e4444

   END FUNCTION donumm4n4_ADD_Or_VS

   FUNCTION donumm4n4_SUB_OO_VS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(donumm4n4), INTENT(IN) :: LHS(:)
      TYPE(donumm4n4), INTENT(IN) :: RHS
      TYPE(donumm4n4) :: RES(SIZE(LHS,1)) 

      ! Addition like function 'LHS - RHS'
      !  Real
      RES%r = LHS%r - RHS%r

      ! Order 1
      RES%e1 = LHS%e1 - RHS%e1
      RES%e2 = LHS%e2 - RHS%e2
      RES%e3 = LHS%e3 - RHS%e3
      RES%e4 = LHS%e4 - RHS%e4

      ! Order 2
      RES%e11 = LHS%e11 - RHS%e11
      RES%e22 = LHS%e22 - RHS%e22
      RES%e33 = LHS%e33 - RHS%e33
      RES%e44 = LHS%e44 - RHS%e44

      ! Order 3
      RES%e111 = LHS%e111 - RHS%e111
      RES%e222 = LHS%e222 - RHS%e222
      RES%e333 = LHS%e333 - RHS%e333
      RES%e444 = LHS%e444 - RHS%e444

      ! Order 4
      RES%e1111 = LHS%e1111 - RHS%e1111
      RES%e2222 = LHS%e2222 - RHS%e2222
      RES%e3333 = LHS%e3333 - RHS%e3333
      RES%e4444 = LHS%e4444 - RHS%e4444

   END FUNCTION donumm4n4_SUB_OO_VS

   FUNCTION donumm4n4_SUB_rO_VS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS(:)
      TYPE(donumm4n4), INTENT(IN) :: RHS
      TYPE(donumm4n4) :: RES(SIZE(LHS,1)) 

      ! Addition like function 'LHS - RHS'
      ! Real
      RES%r = LHS - RHS%r

      ! Order 1
      RES%e1 =  - RHS%e1
      RES%e2 =  - RHS%e2
      RES%e3 =  - RHS%e3
      RES%e4 =  - RHS%e4

      ! Order 2
      RES%e11 =  - RHS%e11
      RES%e22 =  - RHS%e22
      RES%e33 =  - RHS%e33
      RES%e44 =  - RHS%e44

      ! Order 3
      RES%e111 =  - RHS%e111
      RES%e222 =  - RHS%e222
      RES%e333 =  - RHS%e333
      RES%e444 =  - RHS%e444

      ! Order 4
      RES%e1111 =  - RHS%e1111
      RES%e2222 =  - RHS%e2222
      RES%e3333 =  - RHS%e3333
      RES%e4444 =  - RHS%e4444

   END FUNCTION donumm4n4_SUB_rO_VS

   FUNCTION donumm4n4_SUB_Or_VS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(donumm4n4), INTENT(IN) :: LHS(:)
      REAL(DP), INTENT(IN) :: RHS
      TYPE(donumm4n4) :: RES(SIZE(LHS,1)) 

      ! Addition like function 'LHS - RHS'
      ! Real
      RES%r = LHS%r - RHS

      ! Order 1
      RES%e1 = LHS%e1
      RES%e2 = LHS%e2
      RES%e3 = LHS%e3
      RES%e4 = LHS%e4

      ! Order 2
      RES%e11 = LHS%e11
      RES%e22 = LHS%e22
      RES%e33 = LHS%e33
      RES%e44 = LHS%e44

      ! Order 3
      RES%e111 = LHS%e111
      RES%e222 = LHS%e222
      RES%e333 = LHS%e333
      RES%e444 = LHS%e444

      ! Order 4
      RES%e1111 = LHS%e1111
      RES%e2222 = LHS%e2222
      RES%e3333 = LHS%e3333
      RES%e4444 = LHS%e4444

   END FUNCTION donumm4n4_SUB_Or_VS

   FUNCTION donumm4n4_MUL_OO_VS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(donumm4n4), INTENT(IN) :: LHS(:)
      TYPE(donumm4n4), INTENT(IN) :: RHS
      TYPE(donumm4n4) :: RES(SIZE(LHS,1)) 

      !  Multiplication like function 'LHS*RHS'
      ! Order 4
      RES%e1111 = LHS%r*RHS%e1111 + LHS%e1111*RHS%r +  &
               LHS%e1*RHS%e111 + LHS%e111*RHS%e1 + LHS%e11*RHS%e11
      RES%e2222 = LHS%r*RHS%e2222 + LHS%e2222*RHS%r +  &
               LHS%e2*RHS%e222 + LHS%e222*RHS%e2 + LHS%e22*RHS%e22
      RES%e3333 = LHS%r*RHS%e3333 + LHS%e3333*RHS%r +  &
               LHS%e3*RHS%e333 + LHS%e333*RHS%e3 + LHS%e33*RHS%e33
      RES%e4444 = LHS%r*RHS%e4444 + LHS%e4444*RHS%r +  &
               LHS%e4*RHS%e444 + LHS%e444*RHS%e4 + LHS%e44*RHS%e44
      ! Order 3
      RES%e111 = LHS%r*RHS%e111 + LHS%e111*RHS%r +  &
              LHS%e1*RHS%e11 + LHS%e11*RHS%e1
      RES%e222 = LHS%r*RHS%e222 + LHS%e222*RHS%r +  &
              LHS%e2*RHS%e22 + LHS%e22*RHS%e2
      RES%e333 = LHS%r*RHS%e333 + LHS%e333*RHS%r +  &
              LHS%e3*RHS%e33 + LHS%e33*RHS%e3
      RES%e444 = LHS%r*RHS%e444 + LHS%e444*RHS%r +  &
              LHS%e4*RHS%e44 + LHS%e44*RHS%e4
      ! Order 2
      RES%e11 = LHS%r*RHS%e11 + LHS%e11*RHS%r + LHS%e1*RHS%e1
      RES%e22 = LHS%r*RHS%e22 + LHS%e22*RHS%r + LHS%e2*RHS%e2
      RES%e33 = LHS%r*RHS%e33 + LHS%e33*RHS%r + LHS%e3*RHS%e3
      RES%e44 = LHS%r*RHS%e44 + LHS%e44*RHS%r + LHS%e4*RHS%e4
      ! Order 1
      RES%e1 = LHS%r*RHS%e1 + LHS%e1*RHS%r
      RES%e2 = LHS%r*RHS%e2 + LHS%e2*RHS%r
      RES%e3 = LHS%r*RHS%e3 + LHS%e3*RHS%r
      RES%e4 = LHS%r*RHS%e4 + LHS%e4*RHS%r
      ! Order 0
      RES%r = LHS%r*RHS%r

   END FUNCTION donumm4n4_MUL_OO_VS

   FUNCTION donumm4n4_MUL_rO_VS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS(:)
      TYPE(donumm4n4), INTENT(IN) :: RHS
      TYPE(donumm4n4) :: RES(SIZE(LHS,1)) 

      ! Multiplication like function 'LHS*RHS'
      !  Real
      RES%r = LHS*RHS%r

      ! Order 1
      RES%e1 = LHS*RHS%e1
      RES%e2 = LHS*RHS%e2
      RES%e3 = LHS*RHS%e3
      RES%e4 = LHS*RHS%e4

      ! Order 2
      RES%e11 = LHS*RHS%e11
      RES%e22 = LHS*RHS%e22
      RES%e33 = LHS*RHS%e33
      RES%e44 = LHS*RHS%e44

      ! Order 3
      RES%e111 = LHS*RHS%e111
      RES%e222 = LHS*RHS%e222
      RES%e333 = LHS*RHS%e333
      RES%e444 = LHS*RHS%e444

      ! Order 4
      RES%e1111 = LHS*RHS%e1111
      RES%e2222 = LHS*RHS%e2222
      RES%e3333 = LHS*RHS%e3333
      RES%e4444 = LHS*RHS%e4444

   END FUNCTION donumm4n4_MUL_rO_VS

   FUNCTION donumm4n4_MUL_Or_VS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(donumm4n4), INTENT(IN) :: LHS(:)
      REAL(DP), INTENT(IN) :: RHS
      TYPE(donumm4n4) :: RES(SIZE(LHS,1)) 

      ! Multiplication like function 'LHS*RHS'
      !  Real
      RES%r = LHS%r*RHS

      ! Order 1
      RES%e1 = LHS%e1*RHS
      RES%e2 = LHS%e2*RHS
      RES%e3 = LHS%e3*RHS
      RES%e4 = LHS%e4*RHS

      ! Order 2
      RES%e11 = LHS%e11*RHS
      RES%e22 = LHS%e22*RHS
      RES%e33 = LHS%e33*RHS
      RES%e44 = LHS%e44*RHS

      ! Order 3
      RES%e111 = LHS%e111*RHS
      RES%e222 = LHS%e222*RHS
      RES%e333 = LHS%e333*RHS
      RES%e444 = LHS%e444*RHS

      ! Order 4
      RES%e1111 = LHS%e1111*RHS
      RES%e2222 = LHS%e2222*RHS
      RES%e3333 = LHS%e3333*RHS
      RES%e4444 = LHS%e4444*RHS

   END FUNCTION donumm4n4_MUL_Or_VS

   FUNCTION donumm4n4_ADD_OO_MS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(donumm4n4), INTENT(IN) :: LHS(:,:)
      TYPE(donumm4n4), INTENT(IN) :: RHS
      TYPE(donumm4n4) :: RES(SIZE(LHS,1),SIZE(LHS,2)) 

      ! Addition like function 'LHS + RHS'
      !  Real
      RES%r = LHS%r + RHS%r

      ! Order 1
      RES%e1 = LHS%e1 + RHS%e1
      RES%e2 = LHS%e2 + RHS%e2
      RES%e3 = LHS%e3 + RHS%e3
      RES%e4 = LHS%e4 + RHS%e4

      ! Order 2
      RES%e11 = LHS%e11 + RHS%e11
      RES%e22 = LHS%e22 + RHS%e22
      RES%e33 = LHS%e33 + RHS%e33
      RES%e44 = LHS%e44 + RHS%e44

      ! Order 3
      RES%e111 = LHS%e111 + RHS%e111
      RES%e222 = LHS%e222 + RHS%e222
      RES%e333 = LHS%e333 + RHS%e333
      RES%e444 = LHS%e444 + RHS%e444

      ! Order 4
      RES%e1111 = LHS%e1111 + RHS%e1111
      RES%e2222 = LHS%e2222 + RHS%e2222
      RES%e3333 = LHS%e3333 + RHS%e3333
      RES%e4444 = LHS%e4444 + RHS%e4444

   END FUNCTION donumm4n4_ADD_OO_MS

   FUNCTION donumm4n4_ADD_rO_MS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS(:,:)
      TYPE(donumm4n4), INTENT(IN) :: RHS
      TYPE(donumm4n4) :: RES(SIZE(LHS,1),SIZE(LHS,2)) 

      ! Addition like function 'LHS + RHS'
      ! Real
      RES%r = LHS + RHS%r

      ! Order 1
      RES%e1 =  + RHS%e1
      RES%e2 =  + RHS%e2
      RES%e3 =  + RHS%e3
      RES%e4 =  + RHS%e4

      ! Order 2
      RES%e11 =  + RHS%e11
      RES%e22 =  + RHS%e22
      RES%e33 =  + RHS%e33
      RES%e44 =  + RHS%e44

      ! Order 3
      RES%e111 =  + RHS%e111
      RES%e222 =  + RHS%e222
      RES%e333 =  + RHS%e333
      RES%e444 =  + RHS%e444

      ! Order 4
      RES%e1111 =  + RHS%e1111
      RES%e2222 =  + RHS%e2222
      RES%e3333 =  + RHS%e3333
      RES%e4444 =  + RHS%e4444

   END FUNCTION donumm4n4_ADD_rO_MS

   FUNCTION donumm4n4_ADD_Or_MS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(donumm4n4), INTENT(IN) :: LHS(:,:)
      REAL(DP), INTENT(IN) :: RHS
      TYPE(donumm4n4) :: RES(SIZE(LHS,1),SIZE(LHS,2)) 

      ! Addition like function 'LHS + RHS'
      ! Real
      RES%r = LHS%r + RHS

      ! Order 1
      RES%e1 = LHS%e1
      RES%e2 = LHS%e2
      RES%e3 = LHS%e3
      RES%e4 = LHS%e4

      ! Order 2
      RES%e11 = LHS%e11
      RES%e22 = LHS%e22
      RES%e33 = LHS%e33
      RES%e44 = LHS%e44

      ! Order 3
      RES%e111 = LHS%e111
      RES%e222 = LHS%e222
      RES%e333 = LHS%e333
      RES%e444 = LHS%e444

      ! Order 4
      RES%e1111 = LHS%e1111
      RES%e2222 = LHS%e2222
      RES%e3333 = LHS%e3333
      RES%e4444 = LHS%e4444

   END FUNCTION donumm4n4_ADD_Or_MS

   FUNCTION donumm4n4_SUB_OO_MS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(donumm4n4), INTENT(IN) :: LHS(:,:)
      TYPE(donumm4n4), INTENT(IN) :: RHS
      TYPE(donumm4n4) :: RES(SIZE(LHS,1),SIZE(LHS,2)) 

      ! Addition like function 'LHS - RHS'
      !  Real
      RES%r = LHS%r - RHS%r

      ! Order 1
      RES%e1 = LHS%e1 - RHS%e1
      RES%e2 = LHS%e2 - RHS%e2
      RES%e3 = LHS%e3 - RHS%e3
      RES%e4 = LHS%e4 - RHS%e4

      ! Order 2
      RES%e11 = LHS%e11 - RHS%e11
      RES%e22 = LHS%e22 - RHS%e22
      RES%e33 = LHS%e33 - RHS%e33
      RES%e44 = LHS%e44 - RHS%e44

      ! Order 3
      RES%e111 = LHS%e111 - RHS%e111
      RES%e222 = LHS%e222 - RHS%e222
      RES%e333 = LHS%e333 - RHS%e333
      RES%e444 = LHS%e444 - RHS%e444

      ! Order 4
      RES%e1111 = LHS%e1111 - RHS%e1111
      RES%e2222 = LHS%e2222 - RHS%e2222
      RES%e3333 = LHS%e3333 - RHS%e3333
      RES%e4444 = LHS%e4444 - RHS%e4444

   END FUNCTION donumm4n4_SUB_OO_MS

   FUNCTION donumm4n4_SUB_rO_MS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS(:,:)
      TYPE(donumm4n4), INTENT(IN) :: RHS
      TYPE(donumm4n4) :: RES(SIZE(LHS,1),SIZE(LHS,2)) 

      ! Addition like function 'LHS - RHS'
      ! Real
      RES%r = LHS - RHS%r

      ! Order 1
      RES%e1 =  - RHS%e1
      RES%e2 =  - RHS%e2
      RES%e3 =  - RHS%e3
      RES%e4 =  - RHS%e4

      ! Order 2
      RES%e11 =  - RHS%e11
      RES%e22 =  - RHS%e22
      RES%e33 =  - RHS%e33
      RES%e44 =  - RHS%e44

      ! Order 3
      RES%e111 =  - RHS%e111
      RES%e222 =  - RHS%e222
      RES%e333 =  - RHS%e333
      RES%e444 =  - RHS%e444

      ! Order 4
      RES%e1111 =  - RHS%e1111
      RES%e2222 =  - RHS%e2222
      RES%e3333 =  - RHS%e3333
      RES%e4444 =  - RHS%e4444

   END FUNCTION donumm4n4_SUB_rO_MS

   FUNCTION donumm4n4_SUB_Or_MS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(donumm4n4), INTENT(IN) :: LHS(:,:)
      REAL(DP), INTENT(IN) :: RHS
      TYPE(donumm4n4) :: RES(SIZE(LHS,1),SIZE(LHS,2)) 

      ! Addition like function 'LHS - RHS'
      ! Real
      RES%r = LHS%r - RHS

      ! Order 1
      RES%e1 = LHS%e1
      RES%e2 = LHS%e2
      RES%e3 = LHS%e3
      RES%e4 = LHS%e4

      ! Order 2
      RES%e11 = LHS%e11
      RES%e22 = LHS%e22
      RES%e33 = LHS%e33
      RES%e44 = LHS%e44

      ! Order 3
      RES%e111 = LHS%e111
      RES%e222 = LHS%e222
      RES%e333 = LHS%e333
      RES%e444 = LHS%e444

      ! Order 4
      RES%e1111 = LHS%e1111
      RES%e2222 = LHS%e2222
      RES%e3333 = LHS%e3333
      RES%e4444 = LHS%e4444

   END FUNCTION donumm4n4_SUB_Or_MS

   FUNCTION donumm4n4_MUL_OO_MS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(donumm4n4), INTENT(IN) :: LHS(:,:)
      TYPE(donumm4n4), INTENT(IN) :: RHS
      TYPE(donumm4n4) :: RES(SIZE(LHS,1),SIZE(LHS,2)) 

      !  Multiplication like function 'LHS*RHS'
      ! Order 4
      RES%e1111 = LHS%r*RHS%e1111 + LHS%e1111*RHS%r +  &
               LHS%e1*RHS%e111 + LHS%e111*RHS%e1 + LHS%e11*RHS%e11
      RES%e2222 = LHS%r*RHS%e2222 + LHS%e2222*RHS%r +  &
               LHS%e2*RHS%e222 + LHS%e222*RHS%e2 + LHS%e22*RHS%e22
      RES%e3333 = LHS%r*RHS%e3333 + LHS%e3333*RHS%r +  &
               LHS%e3*RHS%e333 + LHS%e333*RHS%e3 + LHS%e33*RHS%e33
      RES%e4444 = LHS%r*RHS%e4444 + LHS%e4444*RHS%r +  &
               LHS%e4*RHS%e444 + LHS%e444*RHS%e4 + LHS%e44*RHS%e44
      ! Order 3
      RES%e111 = LHS%r*RHS%e111 + LHS%e111*RHS%r +  &
              LHS%e1*RHS%e11 + LHS%e11*RHS%e1
      RES%e222 = LHS%r*RHS%e222 + LHS%e222*RHS%r +  &
              LHS%e2*RHS%e22 + LHS%e22*RHS%e2
      RES%e333 = LHS%r*RHS%e333 + LHS%e333*RHS%r +  &
              LHS%e3*RHS%e33 + LHS%e33*RHS%e3
      RES%e444 = LHS%r*RHS%e444 + LHS%e444*RHS%r +  &
              LHS%e4*RHS%e44 + LHS%e44*RHS%e4
      ! Order 2
      RES%e11 = LHS%r*RHS%e11 + LHS%e11*RHS%r + LHS%e1*RHS%e1
      RES%e22 = LHS%r*RHS%e22 + LHS%e22*RHS%r + LHS%e2*RHS%e2
      RES%e33 = LHS%r*RHS%e33 + LHS%e33*RHS%r + LHS%e3*RHS%e3
      RES%e44 = LHS%r*RHS%e44 + LHS%e44*RHS%r + LHS%e4*RHS%e4
      ! Order 1
      RES%e1 = LHS%r*RHS%e1 + LHS%e1*RHS%r
      RES%e2 = LHS%r*RHS%e2 + LHS%e2*RHS%r
      RES%e3 = LHS%r*RHS%e3 + LHS%e3*RHS%r
      RES%e4 = LHS%r*RHS%e4 + LHS%e4*RHS%r
      ! Order 0
      RES%r = LHS%r*RHS%r

   END FUNCTION donumm4n4_MUL_OO_MS

   FUNCTION donumm4n4_MUL_rO_MS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS(:,:)
      TYPE(donumm4n4), INTENT(IN) :: RHS
      TYPE(donumm4n4) :: RES(SIZE(LHS,1),SIZE(LHS,2)) 

      ! Multiplication like function 'LHS*RHS'
      !  Real
      RES%r = LHS*RHS%r

      ! Order 1
      RES%e1 = LHS*RHS%e1
      RES%e2 = LHS*RHS%e2
      RES%e3 = LHS*RHS%e3
      RES%e4 = LHS*RHS%e4

      ! Order 2
      RES%e11 = LHS*RHS%e11
      RES%e22 = LHS*RHS%e22
      RES%e33 = LHS*RHS%e33
      RES%e44 = LHS*RHS%e44

      ! Order 3
      RES%e111 = LHS*RHS%e111
      RES%e222 = LHS*RHS%e222
      RES%e333 = LHS*RHS%e333
      RES%e444 = LHS*RHS%e444

      ! Order 4
      RES%e1111 = LHS*RHS%e1111
      RES%e2222 = LHS*RHS%e2222
      RES%e3333 = LHS*RHS%e3333
      RES%e4444 = LHS*RHS%e4444

   END FUNCTION donumm4n4_MUL_rO_MS

   FUNCTION donumm4n4_MUL_Or_MS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(donumm4n4), INTENT(IN) :: LHS(:,:)
      REAL(DP), INTENT(IN) :: RHS
      TYPE(donumm4n4) :: RES(SIZE(LHS,1),SIZE(LHS,2)) 

      ! Multiplication like function 'LHS*RHS'
      !  Real
      RES%r = LHS%r*RHS

      ! Order 1
      RES%e1 = LHS%e1*RHS
      RES%e2 = LHS%e2*RHS
      RES%e3 = LHS%e3*RHS
      RES%e4 = LHS%e4*RHS

      ! Order 2
      RES%e11 = LHS%e11*RHS
      RES%e22 = LHS%e22*RHS
      RES%e33 = LHS%e33*RHS
      RES%e44 = LHS%e44*RHS

      ! Order 3
      RES%e111 = LHS%e111*RHS
      RES%e222 = LHS%e222*RHS
      RES%e333 = LHS%e333*RHS
      RES%e444 = LHS%e444*RHS

      ! Order 4
      RES%e1111 = LHS%e1111*RHS
      RES%e2222 = LHS%e2222*RHS
      RES%e3333 = LHS%e3333*RHS
      RES%e4444 = LHS%e4444*RHS

   END FUNCTION donumm4n4_MUL_Or_MS

   FUNCTION donumm4n4_ADD_OO_SV(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(donumm4n4), INTENT(IN) :: LHS
      TYPE(donumm4n4), INTENT(IN) :: RHS(:)
      TYPE(donumm4n4) :: RES(SIZE(RHS,1)) 

      ! Addition like function 'LHS + RHS'
      !  Real
      RES%r = LHS%r + RHS%r

      ! Order 1
      RES%e1 = LHS%e1 + RHS%e1
      RES%e2 = LHS%e2 + RHS%e2
      RES%e3 = LHS%e3 + RHS%e3
      RES%e4 = LHS%e4 + RHS%e4

      ! Order 2
      RES%e11 = LHS%e11 + RHS%e11
      RES%e22 = LHS%e22 + RHS%e22
      RES%e33 = LHS%e33 + RHS%e33
      RES%e44 = LHS%e44 + RHS%e44

      ! Order 3
      RES%e111 = LHS%e111 + RHS%e111
      RES%e222 = LHS%e222 + RHS%e222
      RES%e333 = LHS%e333 + RHS%e333
      RES%e444 = LHS%e444 + RHS%e444

      ! Order 4
      RES%e1111 = LHS%e1111 + RHS%e1111
      RES%e2222 = LHS%e2222 + RHS%e2222
      RES%e3333 = LHS%e3333 + RHS%e3333
      RES%e4444 = LHS%e4444 + RHS%e4444

   END FUNCTION donumm4n4_ADD_OO_SV

   FUNCTION donumm4n4_ADD_rO_SV(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS
      TYPE(donumm4n4), INTENT(IN) :: RHS(:)
      TYPE(donumm4n4) :: RES(SIZE(RHS,1)) 

      ! Addition like function 'LHS + RHS'
      ! Real
      RES%r = LHS + RHS%r

      ! Order 1
      RES%e1 =  + RHS%e1
      RES%e2 =  + RHS%e2
      RES%e3 =  + RHS%e3
      RES%e4 =  + RHS%e4

      ! Order 2
      RES%e11 =  + RHS%e11
      RES%e22 =  + RHS%e22
      RES%e33 =  + RHS%e33
      RES%e44 =  + RHS%e44

      ! Order 3
      RES%e111 =  + RHS%e111
      RES%e222 =  + RHS%e222
      RES%e333 =  + RHS%e333
      RES%e444 =  + RHS%e444

      ! Order 4
      RES%e1111 =  + RHS%e1111
      RES%e2222 =  + RHS%e2222
      RES%e3333 =  + RHS%e3333
      RES%e4444 =  + RHS%e4444

   END FUNCTION donumm4n4_ADD_rO_SV

   FUNCTION donumm4n4_ADD_Or_SV(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(donumm4n4), INTENT(IN) :: LHS
      REAL(DP), INTENT(IN) :: RHS(:)
      TYPE(donumm4n4) :: RES(SIZE(RHS,1)) 

      ! Addition like function 'LHS + RHS'
      ! Real
      RES%r = LHS%r + RHS

      ! Order 1
      RES%e1 = LHS%e1
      RES%e2 = LHS%e2
      RES%e3 = LHS%e3
      RES%e4 = LHS%e4

      ! Order 2
      RES%e11 = LHS%e11
      RES%e22 = LHS%e22
      RES%e33 = LHS%e33
      RES%e44 = LHS%e44

      ! Order 3
      RES%e111 = LHS%e111
      RES%e222 = LHS%e222
      RES%e333 = LHS%e333
      RES%e444 = LHS%e444

      ! Order 4
      RES%e1111 = LHS%e1111
      RES%e2222 = LHS%e2222
      RES%e3333 = LHS%e3333
      RES%e4444 = LHS%e4444

   END FUNCTION donumm4n4_ADD_Or_SV

   FUNCTION donumm4n4_SUB_OO_SV(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(donumm4n4), INTENT(IN) :: LHS
      TYPE(donumm4n4), INTENT(IN) :: RHS(:)
      TYPE(donumm4n4) :: RES(SIZE(RHS,1)) 

      ! Addition like function 'LHS - RHS'
      !  Real
      RES%r = LHS%r - RHS%r

      ! Order 1
      RES%e1 = LHS%e1 - RHS%e1
      RES%e2 = LHS%e2 - RHS%e2
      RES%e3 = LHS%e3 - RHS%e3
      RES%e4 = LHS%e4 - RHS%e4

      ! Order 2
      RES%e11 = LHS%e11 - RHS%e11
      RES%e22 = LHS%e22 - RHS%e22
      RES%e33 = LHS%e33 - RHS%e33
      RES%e44 = LHS%e44 - RHS%e44

      ! Order 3
      RES%e111 = LHS%e111 - RHS%e111
      RES%e222 = LHS%e222 - RHS%e222
      RES%e333 = LHS%e333 - RHS%e333
      RES%e444 = LHS%e444 - RHS%e444

      ! Order 4
      RES%e1111 = LHS%e1111 - RHS%e1111
      RES%e2222 = LHS%e2222 - RHS%e2222
      RES%e3333 = LHS%e3333 - RHS%e3333
      RES%e4444 = LHS%e4444 - RHS%e4444

   END FUNCTION donumm4n4_SUB_OO_SV

   FUNCTION donumm4n4_SUB_rO_SV(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS
      TYPE(donumm4n4), INTENT(IN) :: RHS(:)
      TYPE(donumm4n4) :: RES(SIZE(RHS,1)) 

      ! Addition like function 'LHS - RHS'
      ! Real
      RES%r = LHS - RHS%r

      ! Order 1
      RES%e1 =  - RHS%e1
      RES%e2 =  - RHS%e2
      RES%e3 =  - RHS%e3
      RES%e4 =  - RHS%e4

      ! Order 2
      RES%e11 =  - RHS%e11
      RES%e22 =  - RHS%e22
      RES%e33 =  - RHS%e33
      RES%e44 =  - RHS%e44

      ! Order 3
      RES%e111 =  - RHS%e111
      RES%e222 =  - RHS%e222
      RES%e333 =  - RHS%e333
      RES%e444 =  - RHS%e444

      ! Order 4
      RES%e1111 =  - RHS%e1111
      RES%e2222 =  - RHS%e2222
      RES%e3333 =  - RHS%e3333
      RES%e4444 =  - RHS%e4444

   END FUNCTION donumm4n4_SUB_rO_SV

   FUNCTION donumm4n4_SUB_Or_SV(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(donumm4n4), INTENT(IN) :: LHS
      REAL(DP), INTENT(IN) :: RHS(:)
      TYPE(donumm4n4) :: RES(SIZE(RHS,1)) 

      ! Addition like function 'LHS - RHS'
      ! Real
      RES%r = LHS%r - RHS

      ! Order 1
      RES%e1 = LHS%e1
      RES%e2 = LHS%e2
      RES%e3 = LHS%e3
      RES%e4 = LHS%e4

      ! Order 2
      RES%e11 = LHS%e11
      RES%e22 = LHS%e22
      RES%e33 = LHS%e33
      RES%e44 = LHS%e44

      ! Order 3
      RES%e111 = LHS%e111
      RES%e222 = LHS%e222
      RES%e333 = LHS%e333
      RES%e444 = LHS%e444

      ! Order 4
      RES%e1111 = LHS%e1111
      RES%e2222 = LHS%e2222
      RES%e3333 = LHS%e3333
      RES%e4444 = LHS%e4444

   END FUNCTION donumm4n4_SUB_Or_SV

   FUNCTION donumm4n4_MUL_OO_SV(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(donumm4n4), INTENT(IN) :: LHS
      TYPE(donumm4n4), INTENT(IN) :: RHS(:)
      TYPE(donumm4n4) :: RES(SIZE(RHS,1)) 

      !  Multiplication like function 'LHS*RHS'
      ! Order 4
      RES%e1111 = LHS%r*RHS%e1111 + LHS%e1111*RHS%r +  &
               LHS%e1*RHS%e111 + LHS%e111*RHS%e1 + LHS%e11*RHS%e11
      RES%e2222 = LHS%r*RHS%e2222 + LHS%e2222*RHS%r +  &
               LHS%e2*RHS%e222 + LHS%e222*RHS%e2 + LHS%e22*RHS%e22
      RES%e3333 = LHS%r*RHS%e3333 + LHS%e3333*RHS%r +  &
               LHS%e3*RHS%e333 + LHS%e333*RHS%e3 + LHS%e33*RHS%e33
      RES%e4444 = LHS%r*RHS%e4444 + LHS%e4444*RHS%r +  &
               LHS%e4*RHS%e444 + LHS%e444*RHS%e4 + LHS%e44*RHS%e44
      ! Order 3
      RES%e111 = LHS%r*RHS%e111 + LHS%e111*RHS%r +  &
              LHS%e1*RHS%e11 + LHS%e11*RHS%e1
      RES%e222 = LHS%r*RHS%e222 + LHS%e222*RHS%r +  &
              LHS%e2*RHS%e22 + LHS%e22*RHS%e2
      RES%e333 = LHS%r*RHS%e333 + LHS%e333*RHS%r +  &
              LHS%e3*RHS%e33 + LHS%e33*RHS%e3
      RES%e444 = LHS%r*RHS%e444 + LHS%e444*RHS%r +  &
              LHS%e4*RHS%e44 + LHS%e44*RHS%e4
      ! Order 2
      RES%e11 = LHS%r*RHS%e11 + LHS%e11*RHS%r + LHS%e1*RHS%e1
      RES%e22 = LHS%r*RHS%e22 + LHS%e22*RHS%r + LHS%e2*RHS%e2
      RES%e33 = LHS%r*RHS%e33 + LHS%e33*RHS%r + LHS%e3*RHS%e3
      RES%e44 = LHS%r*RHS%e44 + LHS%e44*RHS%r + LHS%e4*RHS%e4
      ! Order 1
      RES%e1 = LHS%r*RHS%e1 + LHS%e1*RHS%r
      RES%e2 = LHS%r*RHS%e2 + LHS%e2*RHS%r
      RES%e3 = LHS%r*RHS%e3 + LHS%e3*RHS%r
      RES%e4 = LHS%r*RHS%e4 + LHS%e4*RHS%r
      ! Order 0
      RES%r = LHS%r*RHS%r

   END FUNCTION donumm4n4_MUL_OO_SV

   FUNCTION donumm4n4_MUL_rO_SV(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS
      TYPE(donumm4n4), INTENT(IN) :: RHS(:)
      TYPE(donumm4n4) :: RES(SIZE(RHS,1)) 

      ! Multiplication like function 'LHS*RHS'
      !  Real
      RES%r = LHS*RHS%r

      ! Order 1
      RES%e1 = LHS*RHS%e1
      RES%e2 = LHS*RHS%e2
      RES%e3 = LHS*RHS%e3
      RES%e4 = LHS*RHS%e4

      ! Order 2
      RES%e11 = LHS*RHS%e11
      RES%e22 = LHS*RHS%e22
      RES%e33 = LHS*RHS%e33
      RES%e44 = LHS*RHS%e44

      ! Order 3
      RES%e111 = LHS*RHS%e111
      RES%e222 = LHS*RHS%e222
      RES%e333 = LHS*RHS%e333
      RES%e444 = LHS*RHS%e444

      ! Order 4
      RES%e1111 = LHS*RHS%e1111
      RES%e2222 = LHS*RHS%e2222
      RES%e3333 = LHS*RHS%e3333
      RES%e4444 = LHS*RHS%e4444

   END FUNCTION donumm4n4_MUL_rO_SV

   FUNCTION donumm4n4_MUL_Or_SV(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(donumm4n4), INTENT(IN) :: LHS
      REAL(DP), INTENT(IN) :: RHS(:)
      TYPE(donumm4n4) :: RES(SIZE(RHS,1)) 

      ! Multiplication like function 'LHS*RHS'
      !  Real
      RES%r = LHS%r*RHS

      ! Order 1
      RES%e1 = LHS%e1*RHS
      RES%e2 = LHS%e2*RHS
      RES%e3 = LHS%e3*RHS
      RES%e4 = LHS%e4*RHS

      ! Order 2
      RES%e11 = LHS%e11*RHS
      RES%e22 = LHS%e22*RHS
      RES%e33 = LHS%e33*RHS
      RES%e44 = LHS%e44*RHS

      ! Order 3
      RES%e111 = LHS%e111*RHS
      RES%e222 = LHS%e222*RHS
      RES%e333 = LHS%e333*RHS
      RES%e444 = LHS%e444*RHS

      ! Order 4
      RES%e1111 = LHS%e1111*RHS
      RES%e2222 = LHS%e2222*RHS
      RES%e3333 = LHS%e3333*RHS
      RES%e4444 = LHS%e4444*RHS

   END FUNCTION donumm4n4_MUL_Or_SV

   FUNCTION donumm4n4_ADD_OO_SM(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(donumm4n4), INTENT(IN) :: LHS
      TYPE(donumm4n4), INTENT(IN) :: RHS(:,:)
      TYPE(donumm4n4) :: RES(SIZE(RHS,1),SIZE(RHS,2)) 

      ! Addition like function 'LHS + RHS'
      !  Real
      RES%r = LHS%r + RHS%r

      ! Order 1
      RES%e1 = LHS%e1 + RHS%e1
      RES%e2 = LHS%e2 + RHS%e2
      RES%e3 = LHS%e3 + RHS%e3
      RES%e4 = LHS%e4 + RHS%e4

      ! Order 2
      RES%e11 = LHS%e11 + RHS%e11
      RES%e22 = LHS%e22 + RHS%e22
      RES%e33 = LHS%e33 + RHS%e33
      RES%e44 = LHS%e44 + RHS%e44

      ! Order 3
      RES%e111 = LHS%e111 + RHS%e111
      RES%e222 = LHS%e222 + RHS%e222
      RES%e333 = LHS%e333 + RHS%e333
      RES%e444 = LHS%e444 + RHS%e444

      ! Order 4
      RES%e1111 = LHS%e1111 + RHS%e1111
      RES%e2222 = LHS%e2222 + RHS%e2222
      RES%e3333 = LHS%e3333 + RHS%e3333
      RES%e4444 = LHS%e4444 + RHS%e4444

   END FUNCTION donumm4n4_ADD_OO_SM

   FUNCTION donumm4n4_ADD_rO_SM(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS
      TYPE(donumm4n4), INTENT(IN) :: RHS(:,:)
      TYPE(donumm4n4) :: RES(SIZE(RHS,1),SIZE(RHS,2)) 

      ! Addition like function 'LHS + RHS'
      ! Real
      RES%r = LHS + RHS%r

      ! Order 1
      RES%e1 =  + RHS%e1
      RES%e2 =  + RHS%e2
      RES%e3 =  + RHS%e3
      RES%e4 =  + RHS%e4

      ! Order 2
      RES%e11 =  + RHS%e11
      RES%e22 =  + RHS%e22
      RES%e33 =  + RHS%e33
      RES%e44 =  + RHS%e44

      ! Order 3
      RES%e111 =  + RHS%e111
      RES%e222 =  + RHS%e222
      RES%e333 =  + RHS%e333
      RES%e444 =  + RHS%e444

      ! Order 4
      RES%e1111 =  + RHS%e1111
      RES%e2222 =  + RHS%e2222
      RES%e3333 =  + RHS%e3333
      RES%e4444 =  + RHS%e4444

   END FUNCTION donumm4n4_ADD_rO_SM

   FUNCTION donumm4n4_ADD_Or_SM(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(donumm4n4), INTENT(IN) :: LHS
      REAL(DP), INTENT(IN) :: RHS(:,:)
      TYPE(donumm4n4) :: RES(SIZE(RHS,1),SIZE(RHS,2)) 

      ! Addition like function 'LHS + RHS'
      ! Real
      RES%r = LHS%r + RHS

      ! Order 1
      RES%e1 = LHS%e1
      RES%e2 = LHS%e2
      RES%e3 = LHS%e3
      RES%e4 = LHS%e4

      ! Order 2
      RES%e11 = LHS%e11
      RES%e22 = LHS%e22
      RES%e33 = LHS%e33
      RES%e44 = LHS%e44

      ! Order 3
      RES%e111 = LHS%e111
      RES%e222 = LHS%e222
      RES%e333 = LHS%e333
      RES%e444 = LHS%e444

      ! Order 4
      RES%e1111 = LHS%e1111
      RES%e2222 = LHS%e2222
      RES%e3333 = LHS%e3333
      RES%e4444 = LHS%e4444

   END FUNCTION donumm4n4_ADD_Or_SM

   FUNCTION donumm4n4_SUB_OO_SM(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(donumm4n4), INTENT(IN) :: LHS
      TYPE(donumm4n4), INTENT(IN) :: RHS(:,:)
      TYPE(donumm4n4) :: RES(SIZE(RHS,1),SIZE(RHS,2)) 

      ! Addition like function 'LHS - RHS'
      !  Real
      RES%r = LHS%r - RHS%r

      ! Order 1
      RES%e1 = LHS%e1 - RHS%e1
      RES%e2 = LHS%e2 - RHS%e2
      RES%e3 = LHS%e3 - RHS%e3
      RES%e4 = LHS%e4 - RHS%e4

      ! Order 2
      RES%e11 = LHS%e11 - RHS%e11
      RES%e22 = LHS%e22 - RHS%e22
      RES%e33 = LHS%e33 - RHS%e33
      RES%e44 = LHS%e44 - RHS%e44

      ! Order 3
      RES%e111 = LHS%e111 - RHS%e111
      RES%e222 = LHS%e222 - RHS%e222
      RES%e333 = LHS%e333 - RHS%e333
      RES%e444 = LHS%e444 - RHS%e444

      ! Order 4
      RES%e1111 = LHS%e1111 - RHS%e1111
      RES%e2222 = LHS%e2222 - RHS%e2222
      RES%e3333 = LHS%e3333 - RHS%e3333
      RES%e4444 = LHS%e4444 - RHS%e4444

   END FUNCTION donumm4n4_SUB_OO_SM

   FUNCTION donumm4n4_SUB_rO_SM(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS
      TYPE(donumm4n4), INTENT(IN) :: RHS(:,:)
      TYPE(donumm4n4) :: RES(SIZE(RHS,1),SIZE(RHS,2)) 

      ! Addition like function 'LHS - RHS'
      ! Real
      RES%r = LHS - RHS%r

      ! Order 1
      RES%e1 =  - RHS%e1
      RES%e2 =  - RHS%e2
      RES%e3 =  - RHS%e3
      RES%e4 =  - RHS%e4

      ! Order 2
      RES%e11 =  - RHS%e11
      RES%e22 =  - RHS%e22
      RES%e33 =  - RHS%e33
      RES%e44 =  - RHS%e44

      ! Order 3
      RES%e111 =  - RHS%e111
      RES%e222 =  - RHS%e222
      RES%e333 =  - RHS%e333
      RES%e444 =  - RHS%e444

      ! Order 4
      RES%e1111 =  - RHS%e1111
      RES%e2222 =  - RHS%e2222
      RES%e3333 =  - RHS%e3333
      RES%e4444 =  - RHS%e4444

   END FUNCTION donumm4n4_SUB_rO_SM

   FUNCTION donumm4n4_SUB_Or_SM(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(donumm4n4), INTENT(IN) :: LHS
      REAL(DP), INTENT(IN) :: RHS(:,:)
      TYPE(donumm4n4) :: RES(SIZE(RHS,1),SIZE(RHS,2)) 

      ! Addition like function 'LHS - RHS'
      ! Real
      RES%r = LHS%r - RHS

      ! Order 1
      RES%e1 = LHS%e1
      RES%e2 = LHS%e2
      RES%e3 = LHS%e3
      RES%e4 = LHS%e4

      ! Order 2
      RES%e11 = LHS%e11
      RES%e22 = LHS%e22
      RES%e33 = LHS%e33
      RES%e44 = LHS%e44

      ! Order 3
      RES%e111 = LHS%e111
      RES%e222 = LHS%e222
      RES%e333 = LHS%e333
      RES%e444 = LHS%e444

      ! Order 4
      RES%e1111 = LHS%e1111
      RES%e2222 = LHS%e2222
      RES%e3333 = LHS%e3333
      RES%e4444 = LHS%e4444

   END FUNCTION donumm4n4_SUB_Or_SM

   FUNCTION donumm4n4_MUL_OO_SM(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(donumm4n4), INTENT(IN) :: LHS
      TYPE(donumm4n4), INTENT(IN) :: RHS(:,:)
      TYPE(donumm4n4) :: RES(SIZE(RHS,1),SIZE(RHS,2)) 

      !  Multiplication like function 'LHS*RHS'
      ! Order 4
      RES%e1111 = LHS%r*RHS%e1111 + LHS%e1111*RHS%r +  &
               LHS%e1*RHS%e111 + LHS%e111*RHS%e1 + LHS%e11*RHS%e11
      RES%e2222 = LHS%r*RHS%e2222 + LHS%e2222*RHS%r +  &
               LHS%e2*RHS%e222 + LHS%e222*RHS%e2 + LHS%e22*RHS%e22
      RES%e3333 = LHS%r*RHS%e3333 + LHS%e3333*RHS%r +  &
               LHS%e3*RHS%e333 + LHS%e333*RHS%e3 + LHS%e33*RHS%e33
      RES%e4444 = LHS%r*RHS%e4444 + LHS%e4444*RHS%r +  &
               LHS%e4*RHS%e444 + LHS%e444*RHS%e4 + LHS%e44*RHS%e44
      ! Order 3
      RES%e111 = LHS%r*RHS%e111 + LHS%e111*RHS%r +  &
              LHS%e1*RHS%e11 + LHS%e11*RHS%e1
      RES%e222 = LHS%r*RHS%e222 + LHS%e222*RHS%r +  &
              LHS%e2*RHS%e22 + LHS%e22*RHS%e2
      RES%e333 = LHS%r*RHS%e333 + LHS%e333*RHS%r +  &
              LHS%e3*RHS%e33 + LHS%e33*RHS%e3
      RES%e444 = LHS%r*RHS%e444 + LHS%e444*RHS%r +  &
              LHS%e4*RHS%e44 + LHS%e44*RHS%e4
      ! Order 2
      RES%e11 = LHS%r*RHS%e11 + LHS%e11*RHS%r + LHS%e1*RHS%e1
      RES%e22 = LHS%r*RHS%e22 + LHS%e22*RHS%r + LHS%e2*RHS%e2
      RES%e33 = LHS%r*RHS%e33 + LHS%e33*RHS%r + LHS%e3*RHS%e3
      RES%e44 = LHS%r*RHS%e44 + LHS%e44*RHS%r + LHS%e4*RHS%e4
      ! Order 1
      RES%e1 = LHS%r*RHS%e1 + LHS%e1*RHS%r
      RES%e2 = LHS%r*RHS%e2 + LHS%e2*RHS%r
      RES%e3 = LHS%r*RHS%e3 + LHS%e3*RHS%r
      RES%e4 = LHS%r*RHS%e4 + LHS%e4*RHS%r
      ! Order 0
      RES%r = LHS%r*RHS%r

   END FUNCTION donumm4n4_MUL_OO_SM

   FUNCTION donumm4n4_MUL_rO_SM(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS
      TYPE(donumm4n4), INTENT(IN) :: RHS(:,:)
      TYPE(donumm4n4) :: RES(SIZE(RHS,1),SIZE(RHS,2)) 

      ! Multiplication like function 'LHS*RHS'
      !  Real
      RES%r = LHS*RHS%r

      ! Order 1
      RES%e1 = LHS*RHS%e1
      RES%e2 = LHS*RHS%e2
      RES%e3 = LHS*RHS%e3
      RES%e4 = LHS*RHS%e4

      ! Order 2
      RES%e11 = LHS*RHS%e11
      RES%e22 = LHS*RHS%e22
      RES%e33 = LHS*RHS%e33
      RES%e44 = LHS*RHS%e44

      ! Order 3
      RES%e111 = LHS*RHS%e111
      RES%e222 = LHS*RHS%e222
      RES%e333 = LHS*RHS%e333
      RES%e444 = LHS*RHS%e444

      ! Order 4
      RES%e1111 = LHS*RHS%e1111
      RES%e2222 = LHS*RHS%e2222
      RES%e3333 = LHS*RHS%e3333
      RES%e4444 = LHS*RHS%e4444

   END FUNCTION donumm4n4_MUL_rO_SM

   FUNCTION donumm4n4_MUL_Or_SM(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(donumm4n4), INTENT(IN) :: LHS
      REAL(DP), INTENT(IN) :: RHS(:,:)
      TYPE(donumm4n4) :: RES(SIZE(RHS,1),SIZE(RHS,2)) 

      ! Multiplication like function 'LHS*RHS'
      !  Real
      RES%r = LHS%r*RHS

      ! Order 1
      RES%e1 = LHS%e1*RHS
      RES%e2 = LHS%e2*RHS
      RES%e3 = LHS%e3*RHS
      RES%e4 = LHS%e4*RHS

      ! Order 2
      RES%e11 = LHS%e11*RHS
      RES%e22 = LHS%e22*RHS
      RES%e33 = LHS%e33*RHS
      RES%e44 = LHS%e44*RHS

      ! Order 3
      RES%e111 = LHS%e111*RHS
      RES%e222 = LHS%e222*RHS
      RES%e333 = LHS%e333*RHS
      RES%e444 = LHS%e444*RHS

      ! Order 4
      RES%e1111 = LHS%e1111*RHS
      RES%e2222 = LHS%e2222*RHS
      RES%e3333 = LHS%e3333*RHS
      RES%e4444 = LHS%e4444*RHS

   END FUNCTION donumm4n4_MUL_Or_SM

ELEMENTAL    FUNCTION donumm4n4_GEM_OOO(A,B,C)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(donumm4n4), INTENT(IN) :: A 
      TYPE(donumm4n4), INTENT(IN) :: B 
      TYPE(donumm4n4), INTENT(IN) :: C 
      TYPE(donumm4n4) :: RES 

      !  General multiplication like function 'A*B + C'

      ! Order 0
      RES%r = C%r + A%r*B%r

      ! Order 1
      RES%e1 = C%e1 + A%r*B%e1 + A%e1*B%r
      RES%e2 = C%e2 + A%r*B%e2 + A%e2*B%r
      RES%e3 = C%e3 + A%r*B%e3 + A%e3*B%r
      RES%e4 = C%e4 + A%r*B%e4 + A%e4*B%r

      ! Order 2
      RES%e11 = C%e11 + A%r*B%e11 + A%e11*B%r + A%e1*B%e1
      RES%e22 = C%e22 + A%r*B%e22 + A%e22*B%r + A%e2*B%e2
      RES%e33 = C%e33 + A%r*B%e33 + A%e33*B%r + A%e3*B%e3
      RES%e44 = C%e44 + A%r*B%e44 + A%e44*B%r + A%e4*B%e4

      ! Order 3
      RES%e111 = C%e111 + A%r*B%e111 + A%e111*B%r + A%e1*B%e11 &
               + A%e11*B%e1
      RES%e222 = C%e222 + A%r*B%e222 + A%e222*B%r + A%e2*B%e22 &
               + A%e22*B%e2
      RES%e333 = C%e333 + A%r*B%e333 + A%e333*B%r + A%e3*B%e33 &
               + A%e33*B%e3
      RES%e444 = C%e444 + A%r*B%e444 + A%e444*B%r + A%e4*B%e44 &
               + A%e44*B%e4

      ! Order 4
      RES%e1111 = C%e1111 + A%r*B%e1111 + A%e1111*B%r + A%e1*B%e111 &
                + A%e111*B%e1 + A%e11*B%e11
      RES%e2222 = C%e2222 + A%r*B%e2222 + A%e2222*B%r + A%e2*B%e222 &
                + A%e222*B%e2 + A%e22*B%e22
      RES%e3333 = C%e3333 + A%r*B%e3333 + A%e3333*B%r + A%e3*B%e333 &
                + A%e333*B%e3 + A%e33*B%e33
      RES%e4444 = C%e4444 + A%r*B%e4444 + A%e4444*B%r + A%e4*B%e444 &
                + A%e444*B%e4 + A%e44*B%e44

   END FUNCTION donumm4n4_GEM_OOO

ELEMENTAL    FUNCTION donumm4n4_GEM_OOO(A,B,C)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(donumm4n4), INTENT(IN) :: A 
      TYPE(donumm4n4), INTENT(IN) :: B 
      TYPE(donumm4n4), INTENT(IN) :: C 
      TYPE(donumm4n4) :: RES 

      !  General multiplication like function 'A*B + C'
      ! Order 4
      RES%e1111 = C%e1111 + A*B%e1111
      RES%e2222 = C%e2222 + A*B%e2222
      RES%e3333 = C%e3333 + A*B%e3333
      RES%e4444 = C%e4444 + A*B%e4444
      ! Order 3
      RES%e111 = C%e111 + A*B%e111
      RES%e222 = C%e222 + A*B%e222
      RES%e333 = C%e333 + A*B%e333
      RES%e444 = C%e444 + A*B%e444
      ! Order 2
      RES%e11 = C%e11 + A*B%e11
      RES%e22 = C%e22 + A*B%e22
      RES%e33 = C%e33 + A*B%e33
      RES%e44 = C%e44 + A*B%e44
      ! Order 1
      RES%e1 = C%e1 + A*B%e1
      RES%e2 = C%e2 + A*B%e2
      RES%e3 = C%e3 + A*B%e3
      RES%e4 = C%e4 + A*B%e4
      ! Order 0
      RES%r = C%r + A*B%r

   END FUNCTION donumm4n4_GEM_OOO

ELEMENTAL    FUNCTION donumm4n4_GEM_OOO(A,B,C)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(donumm4n4), INTENT(IN) :: A 
      TYPE(donumm4n4), INTENT(IN) :: B 
      TYPE(donumm4n4), INTENT(IN) :: C 
      TYPE(donumm4n4) :: RES 

      !  General multiplication like function 'A*B + C'

      ! Order 0
      RES%r = C%r + A%r*B

      ! Order 1
      RES%e1 = C%e1 + A%e1*B
      RES%e2 = C%e2 + A%e2*B
      RES%e3 = C%e3 + A%e3*B
      RES%e4 = C%e4 + A%e4*B

      ! Order 2
      RES%e11 = C%e11 + A%e11*B
      RES%e22 = C%e22 + A%e22*B
      RES%e33 = C%e33 + A%e33*B
      RES%e44 = C%e44 + A%e44*B

      ! Order 3
      RES%e111 = C%e111 + A%e111*B
      RES%e222 = C%e222 + A%e222*B
      RES%e333 = C%e333 + A%e333*B
      RES%e444 = C%e444 + A%e444*B

      ! Order 4
      RES%e1111 = C%e1111 + A%e1111*B
      RES%e2222 = C%e2222 + A%e2222*B
      RES%e3333 = C%e3333 + A%e3333*B
      RES%e4444 = C%e4444 + A%e4444*B

   END FUNCTION donumm4n4_GEM_OOO

   FUNCTION donumm4n4_MATMUL_donumm4n4(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(donumm4n4), INTENT(IN) :: LHS(:,:)
      TYPE(donumm4n4), INTENT(IN) :: RHS(:,:)
      TYPE(donumm4n4) :: RES(SIZE(LHS,1),SIZE(RHS,2))

      !  Multiplication like function 'MATMUL(lhs,rhs)'
      ! Order 4
      res%e1111 = MATMUL(lhs%r,rhs%e1111) + MATMUL(lhs%e1111,rhs%r) +  &
               MATMUL(lhs%e1,rhs%e111) + MATMUL(lhs%e111,rhs%e1) + MATMUL(lhs%e11,rhs%e11)
      res%e2222 = MATMUL(lhs%r,rhs%e2222) + MATMUL(lhs%e2222,rhs%r) +  &
               MATMUL(lhs%e2,rhs%e222) + MATMUL(lhs%e222,rhs%e2) + MATMUL(lhs%e22,rhs%e22)
      res%e3333 = MATMUL(lhs%r,rhs%e3333) + MATMUL(lhs%e3333,rhs%r) +  &
               MATMUL(lhs%e3,rhs%e333) + MATMUL(lhs%e333,rhs%e3) + MATMUL(lhs%e33,rhs%e33)
      res%e4444 = MATMUL(lhs%r,rhs%e4444) + MATMUL(lhs%e4444,rhs%r) +  &
               MATMUL(lhs%e4,rhs%e444) + MATMUL(lhs%e444,rhs%e4) + MATMUL(lhs%e44,rhs%e44)
      ! Order 3
      res%e111 = MATMUL(lhs%r,rhs%e111) + MATMUL(lhs%e111,rhs%r) +  &
              MATMUL(lhs%e1,rhs%e11) + MATMUL(lhs%e11,rhs%e1)
      res%e222 = MATMUL(lhs%r,rhs%e222) + MATMUL(lhs%e222,rhs%r) +  &
              MATMUL(lhs%e2,rhs%e22) + MATMUL(lhs%e22,rhs%e2)
      res%e333 = MATMUL(lhs%r,rhs%e333) + MATMUL(lhs%e333,rhs%r) +  &
              MATMUL(lhs%e3,rhs%e33) + MATMUL(lhs%e33,rhs%e3)
      res%e444 = MATMUL(lhs%r,rhs%e444) + MATMUL(lhs%e444,rhs%r) +  &
              MATMUL(lhs%e4,rhs%e44) + MATMUL(lhs%e44,rhs%e4)
      ! Order 2
      res%e11 = MATMUL(lhs%r,rhs%e11) + MATMUL(lhs%e11,rhs%r) + MATMUL(lhs%e1,rhs%e1)
      res%e22 = MATMUL(lhs%r,rhs%e22) + MATMUL(lhs%e22,rhs%r) + MATMUL(lhs%e2,rhs%e2)
      res%e33 = MATMUL(lhs%r,rhs%e33) + MATMUL(lhs%e33,rhs%r) + MATMUL(lhs%e3,rhs%e3)
      res%e44 = MATMUL(lhs%r,rhs%e44) + MATMUL(lhs%e44,rhs%r) + MATMUL(lhs%e4,rhs%e4)
      ! Order 1
      res%e1 = MATMUL(lhs%r,rhs%e1) + MATMUL(lhs%e1,rhs%r)
      res%e2 = MATMUL(lhs%r,rhs%e2) + MATMUL(lhs%e2,rhs%r)
      res%e3 = MATMUL(lhs%r,rhs%e3) + MATMUL(lhs%e3,rhs%r)
      res%e4 = MATMUL(lhs%r,rhs%e4) + MATMUL(lhs%e4,rhs%r)
      ! Order 0
      res%r = MATMUL(lhs%r,rhs%r)

   END FUNCTION donumm4n4_MATMUL_donumm4n4

   FUNCTION r_MATMUL_donumm4n4(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS(:,:)
      TYPE(donumm4n4), INTENT(IN) :: RHS(:,:)
      TYPE(donumm4n4) :: RES(SIZE(LHS,1),SIZE(RHS,2))

      ! Multiplication like function 'MATMUL(lhs,rhs)'
      !  Real
      res%r = MATMUL(lhs,rhs%r)

      ! Order 1
      res%e1 = MATMUL(lhs,rhs%e1)
      res%e2 = MATMUL(lhs,rhs%e2)
      res%e3 = MATMUL(lhs,rhs%e3)
      res%e4 = MATMUL(lhs,rhs%e4)

      ! Order 2
      res%e11 = MATMUL(lhs,rhs%e11)
      res%e22 = MATMUL(lhs,rhs%e22)
      res%e33 = MATMUL(lhs,rhs%e33)
      res%e44 = MATMUL(lhs,rhs%e44)

      ! Order 3
      res%e111 = MATMUL(lhs,rhs%e111)
      res%e222 = MATMUL(lhs,rhs%e222)
      res%e333 = MATMUL(lhs,rhs%e333)
      res%e444 = MATMUL(lhs,rhs%e444)

      ! Order 4
      res%e1111 = MATMUL(lhs,rhs%e1111)
      res%e2222 = MATMUL(lhs,rhs%e2222)
      res%e3333 = MATMUL(lhs,rhs%e3333)
      res%e4444 = MATMUL(lhs,rhs%e4444)

   END FUNCTION r_MATMUL_donumm4n4

   FUNCTION donumm4n4_MATMUL_r(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(donumm4n4), INTENT(IN) :: LHS(:,:)
      REAL(DP), INTENT(IN) :: RHS(:,:)
      TYPE(donumm4n4) :: RES(SIZE(LHS,1),SIZE(RHS,2))

      ! Multiplication like function 'MATMUL(lhs,rhs)'
      !  Real
      res%r = MATMUL(lhs%r,rhs)

      ! Order 1
      res%e1 = MATMUL(lhs%e1,rhs)
      res%e2 = MATMUL(lhs%e2,rhs)
      res%e3 = MATMUL(lhs%e3,rhs)
      res%e4 = MATMUL(lhs%e4,rhs)

      ! Order 2
      res%e11 = MATMUL(lhs%e11,rhs)
      res%e22 = MATMUL(lhs%e22,rhs)
      res%e33 = MATMUL(lhs%e33,rhs)
      res%e44 = MATMUL(lhs%e44,rhs)

      ! Order 3
      res%e111 = MATMUL(lhs%e111,rhs)
      res%e222 = MATMUL(lhs%e222,rhs)
      res%e333 = MATMUL(lhs%e333,rhs)
      res%e444 = MATMUL(lhs%e444,rhs)

      ! Order 4
      res%e1111 = MATMUL(lhs%e1111,rhs)
      res%e2222 = MATMUL(lhs%e2222,rhs)
      res%e3333 = MATMUL(lhs%e3333,rhs)
      res%e4444 = MATMUL(lhs%e4444,rhs)

   END FUNCTION donumm4n4_MATMUL_r

   FUNCTION donumm4n4_DOT_PRODUCT_donumm4n4(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(donumm4n4), INTENT(IN) :: LHS(:)
      TYPE(donumm4n4), INTENT(IN) :: RHS(SIZE(LHS))
      TYPE(donumm4n4) :: RES

      !  Multiplication like function 'DOT_PRODUCT(lhs,rhs)'
      ! Order 4
      res%e1111 = DOT_PRODUCT(lhs%r,rhs%e1111) + DOT_PRODUCT(lhs%e1111,rhs%r) +  &
               DOT_PRODUCT(lhs%e1,rhs%e111) + DOT_PRODUCT(lhs%e111,rhs%e1) + DOT_PRODUCT(lhs%e11,rhs%e11)
      res%e2222 = DOT_PRODUCT(lhs%r,rhs%e2222) + DOT_PRODUCT(lhs%e2222,rhs%r) +  &
               DOT_PRODUCT(lhs%e2,rhs%e222) + DOT_PRODUCT(lhs%e222,rhs%e2) + DOT_PRODUCT(lhs%e22,rhs%e22)
      res%e3333 = DOT_PRODUCT(lhs%r,rhs%e3333) + DOT_PRODUCT(lhs%e3333,rhs%r) +  &
               DOT_PRODUCT(lhs%e3,rhs%e333) + DOT_PRODUCT(lhs%e333,rhs%e3) + DOT_PRODUCT(lhs%e33,rhs%e33)
      res%e4444 = DOT_PRODUCT(lhs%r,rhs%e4444) + DOT_PRODUCT(lhs%e4444,rhs%r) +  &
               DOT_PRODUCT(lhs%e4,rhs%e444) + DOT_PRODUCT(lhs%e444,rhs%e4) + DOT_PRODUCT(lhs%e44,rhs%e44)
      ! Order 3
      res%e111 = DOT_PRODUCT(lhs%r,rhs%e111) + DOT_PRODUCT(lhs%e111,rhs%r) +  &
              DOT_PRODUCT(lhs%e1,rhs%e11) + DOT_PRODUCT(lhs%e11,rhs%e1)
      res%e222 = DOT_PRODUCT(lhs%r,rhs%e222) + DOT_PRODUCT(lhs%e222,rhs%r) +  &
              DOT_PRODUCT(lhs%e2,rhs%e22) + DOT_PRODUCT(lhs%e22,rhs%e2)
      res%e333 = DOT_PRODUCT(lhs%r,rhs%e333) + DOT_PRODUCT(lhs%e333,rhs%r) +  &
              DOT_PRODUCT(lhs%e3,rhs%e33) + DOT_PRODUCT(lhs%e33,rhs%e3)
      res%e444 = DOT_PRODUCT(lhs%r,rhs%e444) + DOT_PRODUCT(lhs%e444,rhs%r) +  &
              DOT_PRODUCT(lhs%e4,rhs%e44) + DOT_PRODUCT(lhs%e44,rhs%e4)
      ! Order 2
      res%e11 = DOT_PRODUCT(lhs%r,rhs%e11) + DOT_PRODUCT(lhs%e11,rhs%r) + DOT_PRODUCT(lhs%e1,rhs%e1)
      res%e22 = DOT_PRODUCT(lhs%r,rhs%e22) + DOT_PRODUCT(lhs%e22,rhs%r) + DOT_PRODUCT(lhs%e2,rhs%e2)
      res%e33 = DOT_PRODUCT(lhs%r,rhs%e33) + DOT_PRODUCT(lhs%e33,rhs%r) + DOT_PRODUCT(lhs%e3,rhs%e3)
      res%e44 = DOT_PRODUCT(lhs%r,rhs%e44) + DOT_PRODUCT(lhs%e44,rhs%r) + DOT_PRODUCT(lhs%e4,rhs%e4)
      ! Order 1
      res%e1 = DOT_PRODUCT(lhs%r,rhs%e1) + DOT_PRODUCT(lhs%e1,rhs%r)
      res%e2 = DOT_PRODUCT(lhs%r,rhs%e2) + DOT_PRODUCT(lhs%e2,rhs%r)
      res%e3 = DOT_PRODUCT(lhs%r,rhs%e3) + DOT_PRODUCT(lhs%e3,rhs%r)
      res%e4 = DOT_PRODUCT(lhs%r,rhs%e4) + DOT_PRODUCT(lhs%e4,rhs%r)
      ! Order 0
      res%r = DOT_PRODUCT(lhs%r,rhs%r)

   END FUNCTION donumm4n4_DOT_PRODUCT_donumm4n4

   FUNCTION r_DOT_PRODUCT_donumm4n4(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(DP), INTENT(IN) :: LHS(:)
      TYPE(donumm4n4), INTENT(IN) :: RHS(SIZE(LHS))
      TYPE(donumm4n4) :: RES

      ! Multiplication like function 'DOT_PRODUCT(lhs,rhs)'
      !  Real
      res%r = DOT_PRODUCT(lhs,rhs%r)

      ! Order 1
      res%e1 = DOT_PRODUCT(lhs,rhs%e1)
      res%e2 = DOT_PRODUCT(lhs,rhs%e2)
      res%e3 = DOT_PRODUCT(lhs,rhs%e3)
      res%e4 = DOT_PRODUCT(lhs,rhs%e4)

      ! Order 2
      res%e11 = DOT_PRODUCT(lhs,rhs%e11)
      res%e22 = DOT_PRODUCT(lhs,rhs%e22)
      res%e33 = DOT_PRODUCT(lhs,rhs%e33)
      res%e44 = DOT_PRODUCT(lhs,rhs%e44)

      ! Order 3
      res%e111 = DOT_PRODUCT(lhs,rhs%e111)
      res%e222 = DOT_PRODUCT(lhs,rhs%e222)
      res%e333 = DOT_PRODUCT(lhs,rhs%e333)
      res%e444 = DOT_PRODUCT(lhs,rhs%e444)

      ! Order 4
      res%e1111 = DOT_PRODUCT(lhs,rhs%e1111)
      res%e2222 = DOT_PRODUCT(lhs,rhs%e2222)
      res%e3333 = DOT_PRODUCT(lhs,rhs%e3333)
      res%e4444 = DOT_PRODUCT(lhs,rhs%e4444)

   END FUNCTION r_DOT_PRODUCT_donumm4n4

   FUNCTION donumm4n4_DOT_PRODUCT_r(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(donumm4n4), INTENT(IN) :: LHS(:)
      REAL(DP), INTENT(IN) :: RHS(SIZE(LHS))
      TYPE(donumm4n4) :: RES

      ! Multiplication like function 'DOT_PRODUCT(lhs,rhs)'
      !  Real
      res%r = DOT_PRODUCT(lhs%r,rhs)

      ! Order 1
      res%e1 = DOT_PRODUCT(lhs%e1,rhs)
      res%e2 = DOT_PRODUCT(lhs%e2,rhs)
      res%e3 = DOT_PRODUCT(lhs%e3,rhs)
      res%e4 = DOT_PRODUCT(lhs%e4,rhs)

      ! Order 2
      res%e11 = DOT_PRODUCT(lhs%e11,rhs)
      res%e22 = DOT_PRODUCT(lhs%e22,rhs)
      res%e33 = DOT_PRODUCT(lhs%e33,rhs)
      res%e44 = DOT_PRODUCT(lhs%e44,rhs)

      ! Order 3
      res%e111 = DOT_PRODUCT(lhs%e111,rhs)
      res%e222 = DOT_PRODUCT(lhs%e222,rhs)
      res%e333 = DOT_PRODUCT(lhs%e333,rhs)
      res%e444 = DOT_PRODUCT(lhs%e444,rhs)

      ! Order 4
      res%e1111 = DOT_PRODUCT(lhs%e1111,rhs)
      res%e2222 = DOT_PRODUCT(lhs%e2222,rhs)
      res%e3333 = DOT_PRODUCT(lhs%e3333,rhs)
      res%e4444 = DOT_PRODUCT(lhs%e4444,rhs)

   END FUNCTION donumm4n4_DOT_PRODUCT_r

   FUNCTION donumm4n4_TRANSPOSE(LHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(donumm4n4), INTENT(IN) :: LHS(:,:)
      TYPE(donumm4n4) :: RES (SIZE(LHS,2),SIZE(LHS,1))

      ! Negation like function 'TRANSPOSE(LHS)'
      ! Real
      RES%r = TRANSPOSE(LHS%r)
      ! Order 1
      RES%e1 = TRANSPOSE(LHS%e1)
      RES%e2 = TRANSPOSE(LHS%e2)
      RES%e3 = TRANSPOSE(LHS%e3)
      RES%e4 = TRANSPOSE(LHS%e4)
      ! Order 2
      RES%e11 = TRANSPOSE(LHS%e11)
      RES%e22 = TRANSPOSE(LHS%e22)
      RES%e33 = TRANSPOSE(LHS%e33)
      RES%e44 = TRANSPOSE(LHS%e44)
      ! Order 3
      RES%e111 = TRANSPOSE(LHS%e111)
      RES%e222 = TRANSPOSE(LHS%e222)
      RES%e333 = TRANSPOSE(LHS%e333)
      RES%e444 = TRANSPOSE(LHS%e444)
      ! Order 4
      RES%e1111 = TRANSPOSE(LHS%e1111)
      RES%e2222 = TRANSPOSE(LHS%e2222)
      RES%e3333 = TRANSPOSE(LHS%e3333)
      RES%e4444 = TRANSPOSE(LHS%e4444)

   END FUNCTION donumm4n4_TRANSPOSE

FUNCTION donumm4n4_TO_CR_MAT_S(VAL) RESULT(RES)
      IMPLICIT NONE
      TYPE(donumm4n4), INTENT(IN) :: VAL
      REAL(DP) :: RES(NUM_IM_DIR,NUM_IM_DIR) 
      INTEGER :: NCOLS=1, NROWS=1


      ! r x r -> r (1, 1)
      RES(1+NROWS*0:NROWS*1,1+NCOLS*0:NCOLS*1) = VAL%r
      ! r x e1 -> e1 (2, 2)
      RES(1+NROWS*1:NROWS*2,1+NCOLS*1:NCOLS*2) = VAL%r
      ! e1 x r -> e1 (2, 1)
      RES(1+NROWS*1:NROWS*2,1+NCOLS*0:NCOLS*1) = VAL%e1
      ! r x e2 -> e2 (3, 3)
      RES(1+NROWS*2:NROWS*3,1+NCOLS*2:NCOLS*3) = VAL%r
      ! e2 x r -> e2 (3, 1)
      RES(1+NROWS*2:NROWS*3,1+NCOLS*0:NCOLS*1) = VAL%e2
      ! r x e3 -> e3 (4, 4)
      RES(1+NROWS*3:NROWS*4,1+NCOLS*3:NCOLS*4) = VAL%r
      ! e3 x r -> e3 (4, 1)
      RES(1+NROWS*3:NROWS*4,1+NCOLS*0:NCOLS*1) = VAL%e3
      ! r x e4 -> e4 (5, 5)
      RES(1+NROWS*4:NROWS*5,1+NCOLS*4:NCOLS*5) = VAL%r
      ! e4 x r -> e4 (5, 1)
      RES(1+NROWS*4:NROWS*5,1+NCOLS*0:NCOLS*1) = VAL%e4
      ! r x e11 -> e11 (6, 6)
      RES(1+NROWS*5:NROWS*6,1+NCOLS*5:NCOLS*6) = VAL%r
      ! e11 x r -> e11 (6, 1)
      RES(1+NROWS*5:NROWS*6,1+NCOLS*0:NCOLS*1) = VAL%e11
      ! e1 x e1 -> e11 (6, 2)
      RES(1+NROWS*5:NROWS*6,1+NCOLS*1:NCOLS*2) = VAL%e1
      ! r x e22 -> e22 (7, 7)
      RES(1+NROWS*6:NROWS*7,1+NCOLS*6:NCOLS*7) = VAL%r
      ! e22 x r -> e22 (7, 1)
      RES(1+NROWS*6:NROWS*7,1+NCOLS*0:NCOLS*1) = VAL%e22
      ! e2 x e2 -> e22 (7, 3)
      RES(1+NROWS*6:NROWS*7,1+NCOLS*2:NCOLS*3) = VAL%e2
      ! r x e33 -> e33 (8, 8)
      RES(1+NROWS*7:NROWS*8,1+NCOLS*7:NCOLS*8) = VAL%r
      ! e33 x r -> e33 (8, 1)
      RES(1+NROWS*7:NROWS*8,1+NCOLS*0:NCOLS*1) = VAL%e33
      ! e3 x e3 -> e33 (8, 4)
      RES(1+NROWS*7:NROWS*8,1+NCOLS*3:NCOLS*4) = VAL%e3
      ! r x e44 -> e44 (9, 9)
      RES(1+NROWS*8:NROWS*9,1+NCOLS*8:NCOLS*9) = VAL%r
      ! e44 x r -> e44 (9, 1)
      RES(1+NROWS*8:NROWS*9,1+NCOLS*0:NCOLS*1) = VAL%e44
      ! e4 x e4 -> e44 (9, 5)
      RES(1+NROWS*8:NROWS*9,1+NCOLS*4:NCOLS*5) = VAL%e4
      ! r x e111 -> e111 (10, 10)
      RES(1+NROWS*9:NROWS*10,1+NCOLS*9:NCOLS*10) = VAL%r
      ! e111 x r -> e111 (10, 1)
      RES(1+NROWS*9:NROWS*10,1+NCOLS*0:NCOLS*1) = VAL%e111
      ! e1 x e11 -> e111 (10, 6)
      RES(1+NROWS*9:NROWS*10,1+NCOLS*5:NCOLS*6) = VAL%e1
      ! e11 x e1 -> e111 (10, 2)
      RES(1+NROWS*9:NROWS*10,1+NCOLS*1:NCOLS*2) = VAL%e11
      ! r x e222 -> e222 (11, 11)
      RES(1+NROWS*10:NROWS*11,1+NCOLS*10:NCOLS*11) = VAL%r
      ! e222 x r -> e222 (11, 1)
      RES(1+NROWS*10:NROWS*11,1+NCOLS*0:NCOLS*1) = VAL%e222
      ! e2 x e22 -> e222 (11, 7)
      RES(1+NROWS*10:NROWS*11,1+NCOLS*6:NCOLS*7) = VAL%e2
      ! e22 x e2 -> e222 (11, 3)
      RES(1+NROWS*10:NROWS*11,1+NCOLS*2:NCOLS*3) = VAL%e22
      ! r x e333 -> e333 (12, 12)
      RES(1+NROWS*11:NROWS*12,1+NCOLS*11:NCOLS*12) = VAL%r
      ! e333 x r -> e333 (12, 1)
      RES(1+NROWS*11:NROWS*12,1+NCOLS*0:NCOLS*1) = VAL%e333
      ! e3 x e33 -> e333 (12, 8)
      RES(1+NROWS*11:NROWS*12,1+NCOLS*7:NCOLS*8) = VAL%e3
      ! e33 x e3 -> e333 (12, 4)
      RES(1+NROWS*11:NROWS*12,1+NCOLS*3:NCOLS*4) = VAL%e33
      ! r x e444 -> e444 (13, 13)
      RES(1+NROWS*12:NROWS*13,1+NCOLS*12:NCOLS*13) = VAL%r
      ! e444 x r -> e444 (13, 1)
      RES(1+NROWS*12:NROWS*13,1+NCOLS*0:NCOLS*1) = VAL%e444
      ! e4 x e44 -> e444 (13, 9)
      RES(1+NROWS*12:NROWS*13,1+NCOLS*8:NCOLS*9) = VAL%e4
      ! e44 x e4 -> e444 (13, 5)
      RES(1+NROWS*12:NROWS*13,1+NCOLS*4:NCOLS*5) = VAL%e44
      ! r x e1111 -> e1111 (14, 14)
      RES(1+NROWS*13:NROWS*14,1+NCOLS*13:NCOLS*14) = VAL%r
      ! e1111 x r -> e1111 (14, 1)
      RES(1+NROWS*13:NROWS*14,1+NCOLS*0:NCOLS*1) = VAL%e1111
      ! e1 x e111 -> e1111 (14, 10)
      RES(1+NROWS*13:NROWS*14,1+NCOLS*9:NCOLS*10) = VAL%e1
      ! e111 x e1 -> e1111 (14, 2)
      RES(1+NROWS*13:NROWS*14,1+NCOLS*1:NCOLS*2) = VAL%e111
      ! e11 x e11 -> e1111 (14, 6)
      RES(1+NROWS*13:NROWS*14,1+NCOLS*5:NCOLS*6) = VAL%e11
      ! r x e2222 -> e2222 (15, 15)
      RES(1+NROWS*14:NROWS*15,1+NCOLS*14:NCOLS*15) = VAL%r
      ! e2222 x r -> e2222 (15, 1)
      RES(1+NROWS*14:NROWS*15,1+NCOLS*0:NCOLS*1) = VAL%e2222
      ! e2 x e222 -> e2222 (15, 11)
      RES(1+NROWS*14:NROWS*15,1+NCOLS*10:NCOLS*11) = VAL%e2
      ! e222 x e2 -> e2222 (15, 3)
      RES(1+NROWS*14:NROWS*15,1+NCOLS*2:NCOLS*3) = VAL%e222
      ! e22 x e22 -> e2222 (15, 7)
      RES(1+NROWS*14:NROWS*15,1+NCOLS*6:NCOLS*7) = VAL%e22
      ! r x e3333 -> e3333 (16, 16)
      RES(1+NROWS*15:NROWS*16,1+NCOLS*15:NCOLS*16) = VAL%r
      ! e3333 x r -> e3333 (16, 1)
      RES(1+NROWS*15:NROWS*16,1+NCOLS*0:NCOLS*1) = VAL%e3333
      ! e3 x e333 -> e3333 (16, 12)
      RES(1+NROWS*15:NROWS*16,1+NCOLS*11:NCOLS*12) = VAL%e3
      ! e333 x e3 -> e3333 (16, 4)
      RES(1+NROWS*15:NROWS*16,1+NCOLS*3:NCOLS*4) = VAL%e333
      ! e33 x e33 -> e3333 (16, 8)
      RES(1+NROWS*15:NROWS*16,1+NCOLS*7:NCOLS*8) = VAL%e33
      ! r x e4444 -> e4444 (17, 17)
      RES(1+NROWS*16:NROWS*17,1+NCOLS*16:NCOLS*17) = VAL%r
      ! e4444 x r -> e4444 (17, 1)
      RES(1+NROWS*16:NROWS*17,1+NCOLS*0:NCOLS*1) = VAL%e4444
      ! e4 x e444 -> e4444 (17, 13)
      RES(1+NROWS*16:NROWS*17,1+NCOLS*12:NCOLS*13) = VAL%e4
      ! e444 x e4 -> e4444 (17, 5)
      RES(1+NROWS*16:NROWS*17,1+NCOLS*4:NCOLS*5) = VAL%e444
      ! e44 x e44 -> e4444 (17, 9)
      RES(1+NROWS*16:NROWS*17,1+NCOLS*8:NCOLS*9) = VAL%e44
   END FUNCTION donumm4n4_TO_CR_MAT_S

FUNCTION donumm4n4_TO_CR_MAT_V(VAL) RESULT(RES)
      IMPLICIT NONE
      TYPE(donumm4n4), INTENT(IN) :: VAL(:)
      REAL(DP) :: RES(NUM_IM_DIR*SIZE(VAL,1),NUM_IM_DIR) 
      INTEGER :: NCOLS=1, NROWS=1

      NROWS = SIZE(VAL,1)

      ! r x r -> r (1, 1)
      RES(1+NROWS*0:NROWS*1,1) = VAL%r
      ! r x e1 -> e1 (2, 2)
      RES(1+NROWS*1:NROWS*2,2) = VAL%r
      ! e1 x r -> e1 (2, 1)
      RES(1+NROWS*1:NROWS*2,1) = VAL%e1
      ! r x e2 -> e2 (3, 3)
      RES(1+NROWS*2:NROWS*3,3) = VAL%r
      ! e2 x r -> e2 (3, 1)
      RES(1+NROWS*2:NROWS*3,1) = VAL%e2
      ! r x e3 -> e3 (4, 4)
      RES(1+NROWS*3:NROWS*4,4) = VAL%r
      ! e3 x r -> e3 (4, 1)
      RES(1+NROWS*3:NROWS*4,1) = VAL%e3
      ! r x e4 -> e4 (5, 5)
      RES(1+NROWS*4:NROWS*5,5) = VAL%r
      ! e4 x r -> e4 (5, 1)
      RES(1+NROWS*4:NROWS*5,1) = VAL%e4
      ! r x e11 -> e11 (6, 6)
      RES(1+NROWS*5:NROWS*6,6) = VAL%r
      ! e11 x r -> e11 (6, 1)
      RES(1+NROWS*5:NROWS*6,1) = VAL%e11
      ! e1 x e1 -> e11 (6, 2)
      RES(1+NROWS*5:NROWS*6,2) = VAL%e1
      ! r x e22 -> e22 (7, 7)
      RES(1+NROWS*6:NROWS*7,7) = VAL%r
      ! e22 x r -> e22 (7, 1)
      RES(1+NROWS*6:NROWS*7,1) = VAL%e22
      ! e2 x e2 -> e22 (7, 3)
      RES(1+NROWS*6:NROWS*7,3) = VAL%e2
      ! r x e33 -> e33 (8, 8)
      RES(1+NROWS*7:NROWS*8,8) = VAL%r
      ! e33 x r -> e33 (8, 1)
      RES(1+NROWS*7:NROWS*8,1) = VAL%e33
      ! e3 x e3 -> e33 (8, 4)
      RES(1+NROWS*7:NROWS*8,4) = VAL%e3
      ! r x e44 -> e44 (9, 9)
      RES(1+NROWS*8:NROWS*9,9) = VAL%r
      ! e44 x r -> e44 (9, 1)
      RES(1+NROWS*8:NROWS*9,1) = VAL%e44
      ! e4 x e4 -> e44 (9, 5)
      RES(1+NROWS*8:NROWS*9,5) = VAL%e4
      ! r x e111 -> e111 (10, 10)
      RES(1+NROWS*9:NROWS*10,10) = VAL%r
      ! e111 x r -> e111 (10, 1)
      RES(1+NROWS*9:NROWS*10,1) = VAL%e111
      ! e1 x e11 -> e111 (10, 6)
      RES(1+NROWS*9:NROWS*10,6) = VAL%e1
      ! e11 x e1 -> e111 (10, 2)
      RES(1+NROWS*9:NROWS*10,2) = VAL%e11
      ! r x e222 -> e222 (11, 11)
      RES(1+NROWS*10:NROWS*11,11) = VAL%r
      ! e222 x r -> e222 (11, 1)
      RES(1+NROWS*10:NROWS*11,1) = VAL%e222
      ! e2 x e22 -> e222 (11, 7)
      RES(1+NROWS*10:NROWS*11,7) = VAL%e2
      ! e22 x e2 -> e222 (11, 3)
      RES(1+NROWS*10:NROWS*11,3) = VAL%e22
      ! r x e333 -> e333 (12, 12)
      RES(1+NROWS*11:NROWS*12,12) = VAL%r
      ! e333 x r -> e333 (12, 1)
      RES(1+NROWS*11:NROWS*12,1) = VAL%e333
      ! e3 x e33 -> e333 (12, 8)
      RES(1+NROWS*11:NROWS*12,8) = VAL%e3
      ! e33 x e3 -> e333 (12, 4)
      RES(1+NROWS*11:NROWS*12,4) = VAL%e33
      ! r x e444 -> e444 (13, 13)
      RES(1+NROWS*12:NROWS*13,13) = VAL%r
      ! e444 x r -> e444 (13, 1)
      RES(1+NROWS*12:NROWS*13,1) = VAL%e444
      ! e4 x e44 -> e444 (13, 9)
      RES(1+NROWS*12:NROWS*13,9) = VAL%e4
      ! e44 x e4 -> e444 (13, 5)
      RES(1+NROWS*12:NROWS*13,5) = VAL%e44
      ! r x e1111 -> e1111 (14, 14)
      RES(1+NROWS*13:NROWS*14,14) = VAL%r
      ! e1111 x r -> e1111 (14, 1)
      RES(1+NROWS*13:NROWS*14,1) = VAL%e1111
      ! e1 x e111 -> e1111 (14, 10)
      RES(1+NROWS*13:NROWS*14,10) = VAL%e1
      ! e111 x e1 -> e1111 (14, 2)
      RES(1+NROWS*13:NROWS*14,2) = VAL%e111
      ! e11 x e11 -> e1111 (14, 6)
      RES(1+NROWS*13:NROWS*14,6) = VAL%e11
      ! r x e2222 -> e2222 (15, 15)
      RES(1+NROWS*14:NROWS*15,15) = VAL%r
      ! e2222 x r -> e2222 (15, 1)
      RES(1+NROWS*14:NROWS*15,1) = VAL%e2222
      ! e2 x e222 -> e2222 (15, 11)
      RES(1+NROWS*14:NROWS*15,11) = VAL%e2
      ! e222 x e2 -> e2222 (15, 3)
      RES(1+NROWS*14:NROWS*15,3) = VAL%e222
      ! e22 x e22 -> e2222 (15, 7)
      RES(1+NROWS*14:NROWS*15,7) = VAL%e22
      ! r x e3333 -> e3333 (16, 16)
      RES(1+NROWS*15:NROWS*16,16) = VAL%r
      ! e3333 x r -> e3333 (16, 1)
      RES(1+NROWS*15:NROWS*16,1) = VAL%e3333
      ! e3 x e333 -> e3333 (16, 12)
      RES(1+NROWS*15:NROWS*16,12) = VAL%e3
      ! e333 x e3 -> e3333 (16, 4)
      RES(1+NROWS*15:NROWS*16,4) = VAL%e333
      ! e33 x e33 -> e3333 (16, 8)
      RES(1+NROWS*15:NROWS*16,8) = VAL%e33
      ! r x e4444 -> e4444 (17, 17)
      RES(1+NROWS*16:NROWS*17,17) = VAL%r
      ! e4444 x r -> e4444 (17, 1)
      RES(1+NROWS*16:NROWS*17,1) = VAL%e4444
      ! e4 x e444 -> e4444 (17, 13)
      RES(1+NROWS*16:NROWS*17,13) = VAL%e4
      ! e444 x e4 -> e4444 (17, 5)
      RES(1+NROWS*16:NROWS*17,5) = VAL%e444
      ! e44 x e44 -> e4444 (17, 9)
      RES(1+NROWS*16:NROWS*17,9) = VAL%e44
   END FUNCTION donumm4n4_TO_CR_MAT_V

FUNCTION donumm4n4_TO_CR_MAT_M(VAL) RESULT(RES)
      IMPLICIT NONE
      TYPE(donumm4n4), INTENT(IN) :: VAL(:,:)
      REAL(DP) :: RES(NUM_IM_DIR*SIZE(VAL,1),NUM_IM_DIR*SIZE(VAL,2)) 
      INTEGER :: NCOLS=1, NROWS=1

      NCOLS = SIZE(VAL,1)
      NROWS = SIZE(VAL,2)

      ! r x r -> r (1, 1)
      RES(1+NROWS*0:NROWS*1,1+NCOLS*0:NCOLS*1) = VAL%r
      ! r x e1 -> e1 (2, 2)
      RES(1+NROWS*1:NROWS*2,1+NCOLS*1:NCOLS*2) = VAL%r
      ! e1 x r -> e1 (2, 1)
      RES(1+NROWS*1:NROWS*2,1+NCOLS*0:NCOLS*1) = VAL%e1
      ! r x e2 -> e2 (3, 3)
      RES(1+NROWS*2:NROWS*3,1+NCOLS*2:NCOLS*3) = VAL%r
      ! e2 x r -> e2 (3, 1)
      RES(1+NROWS*2:NROWS*3,1+NCOLS*0:NCOLS*1) = VAL%e2
      ! r x e3 -> e3 (4, 4)
      RES(1+NROWS*3:NROWS*4,1+NCOLS*3:NCOLS*4) = VAL%r
      ! e3 x r -> e3 (4, 1)
      RES(1+NROWS*3:NROWS*4,1+NCOLS*0:NCOLS*1) = VAL%e3
      ! r x e4 -> e4 (5, 5)
      RES(1+NROWS*4:NROWS*5,1+NCOLS*4:NCOLS*5) = VAL%r
      ! e4 x r -> e4 (5, 1)
      RES(1+NROWS*4:NROWS*5,1+NCOLS*0:NCOLS*1) = VAL%e4
      ! r x e11 -> e11 (6, 6)
      RES(1+NROWS*5:NROWS*6,1+NCOLS*5:NCOLS*6) = VAL%r
      ! e11 x r -> e11 (6, 1)
      RES(1+NROWS*5:NROWS*6,1+NCOLS*0:NCOLS*1) = VAL%e11
      ! e1 x e1 -> e11 (6, 2)
      RES(1+NROWS*5:NROWS*6,1+NCOLS*1:NCOLS*2) = VAL%e1
      ! r x e22 -> e22 (7, 7)
      RES(1+NROWS*6:NROWS*7,1+NCOLS*6:NCOLS*7) = VAL%r
      ! e22 x r -> e22 (7, 1)
      RES(1+NROWS*6:NROWS*7,1+NCOLS*0:NCOLS*1) = VAL%e22
      ! e2 x e2 -> e22 (7, 3)
      RES(1+NROWS*6:NROWS*7,1+NCOLS*2:NCOLS*3) = VAL%e2
      ! r x e33 -> e33 (8, 8)
      RES(1+NROWS*7:NROWS*8,1+NCOLS*7:NCOLS*8) = VAL%r
      ! e33 x r -> e33 (8, 1)
      RES(1+NROWS*7:NROWS*8,1+NCOLS*0:NCOLS*1) = VAL%e33
      ! e3 x e3 -> e33 (8, 4)
      RES(1+NROWS*7:NROWS*8,1+NCOLS*3:NCOLS*4) = VAL%e3
      ! r x e44 -> e44 (9, 9)
      RES(1+NROWS*8:NROWS*9,1+NCOLS*8:NCOLS*9) = VAL%r
      ! e44 x r -> e44 (9, 1)
      RES(1+NROWS*8:NROWS*9,1+NCOLS*0:NCOLS*1) = VAL%e44
      ! e4 x e4 -> e44 (9, 5)
      RES(1+NROWS*8:NROWS*9,1+NCOLS*4:NCOLS*5) = VAL%e4
      ! r x e111 -> e111 (10, 10)
      RES(1+NROWS*9:NROWS*10,1+NCOLS*9:NCOLS*10) = VAL%r
      ! e111 x r -> e111 (10, 1)
      RES(1+NROWS*9:NROWS*10,1+NCOLS*0:NCOLS*1) = VAL%e111
      ! e1 x e11 -> e111 (10, 6)
      RES(1+NROWS*9:NROWS*10,1+NCOLS*5:NCOLS*6) = VAL%e1
      ! e11 x e1 -> e111 (10, 2)
      RES(1+NROWS*9:NROWS*10,1+NCOLS*1:NCOLS*2) = VAL%e11
      ! r x e222 -> e222 (11, 11)
      RES(1+NROWS*10:NROWS*11,1+NCOLS*10:NCOLS*11) = VAL%r
      ! e222 x r -> e222 (11, 1)
      RES(1+NROWS*10:NROWS*11,1+NCOLS*0:NCOLS*1) = VAL%e222
      ! e2 x e22 -> e222 (11, 7)
      RES(1+NROWS*10:NROWS*11,1+NCOLS*6:NCOLS*7) = VAL%e2
      ! e22 x e2 -> e222 (11, 3)
      RES(1+NROWS*10:NROWS*11,1+NCOLS*2:NCOLS*3) = VAL%e22
      ! r x e333 -> e333 (12, 12)
      RES(1+NROWS*11:NROWS*12,1+NCOLS*11:NCOLS*12) = VAL%r
      ! e333 x r -> e333 (12, 1)
      RES(1+NROWS*11:NROWS*12,1+NCOLS*0:NCOLS*1) = VAL%e333
      ! e3 x e33 -> e333 (12, 8)
      RES(1+NROWS*11:NROWS*12,1+NCOLS*7:NCOLS*8) = VAL%e3
      ! e33 x e3 -> e333 (12, 4)
      RES(1+NROWS*11:NROWS*12,1+NCOLS*3:NCOLS*4) = VAL%e33
      ! r x e444 -> e444 (13, 13)
      RES(1+NROWS*12:NROWS*13,1+NCOLS*12:NCOLS*13) = VAL%r
      ! e444 x r -> e444 (13, 1)
      RES(1+NROWS*12:NROWS*13,1+NCOLS*0:NCOLS*1) = VAL%e444
      ! e4 x e44 -> e444 (13, 9)
      RES(1+NROWS*12:NROWS*13,1+NCOLS*8:NCOLS*9) = VAL%e4
      ! e44 x e4 -> e444 (13, 5)
      RES(1+NROWS*12:NROWS*13,1+NCOLS*4:NCOLS*5) = VAL%e44
      ! r x e1111 -> e1111 (14, 14)
      RES(1+NROWS*13:NROWS*14,1+NCOLS*13:NCOLS*14) = VAL%r
      ! e1111 x r -> e1111 (14, 1)
      RES(1+NROWS*13:NROWS*14,1+NCOLS*0:NCOLS*1) = VAL%e1111
      ! e1 x e111 -> e1111 (14, 10)
      RES(1+NROWS*13:NROWS*14,1+NCOLS*9:NCOLS*10) = VAL%e1
      ! e111 x e1 -> e1111 (14, 2)
      RES(1+NROWS*13:NROWS*14,1+NCOLS*1:NCOLS*2) = VAL%e111
      ! e11 x e11 -> e1111 (14, 6)
      RES(1+NROWS*13:NROWS*14,1+NCOLS*5:NCOLS*6) = VAL%e11
      ! r x e2222 -> e2222 (15, 15)
      RES(1+NROWS*14:NROWS*15,1+NCOLS*14:NCOLS*15) = VAL%r
      ! e2222 x r -> e2222 (15, 1)
      RES(1+NROWS*14:NROWS*15,1+NCOLS*0:NCOLS*1) = VAL%e2222
      ! e2 x e222 -> e2222 (15, 11)
      RES(1+NROWS*14:NROWS*15,1+NCOLS*10:NCOLS*11) = VAL%e2
      ! e222 x e2 -> e2222 (15, 3)
      RES(1+NROWS*14:NROWS*15,1+NCOLS*2:NCOLS*3) = VAL%e222
      ! e22 x e22 -> e2222 (15, 7)
      RES(1+NROWS*14:NROWS*15,1+NCOLS*6:NCOLS*7) = VAL%e22
      ! r x e3333 -> e3333 (16, 16)
      RES(1+NROWS*15:NROWS*16,1+NCOLS*15:NCOLS*16) = VAL%r
      ! e3333 x r -> e3333 (16, 1)
      RES(1+NROWS*15:NROWS*16,1+NCOLS*0:NCOLS*1) = VAL%e3333
      ! e3 x e333 -> e3333 (16, 12)
      RES(1+NROWS*15:NROWS*16,1+NCOLS*11:NCOLS*12) = VAL%e3
      ! e333 x e3 -> e3333 (16, 4)
      RES(1+NROWS*15:NROWS*16,1+NCOLS*3:NCOLS*4) = VAL%e333
      ! e33 x e33 -> e3333 (16, 8)
      RES(1+NROWS*15:NROWS*16,1+NCOLS*7:NCOLS*8) = VAL%e33
      ! r x e4444 -> e4444 (17, 17)
      RES(1+NROWS*16:NROWS*17,1+NCOLS*16:NCOLS*17) = VAL%r
      ! e4444 x r -> e4444 (17, 1)
      RES(1+NROWS*16:NROWS*17,1+NCOLS*0:NCOLS*1) = VAL%e4444
      ! e4 x e444 -> e4444 (17, 13)
      RES(1+NROWS*16:NROWS*17,1+NCOLS*12:NCOLS*13) = VAL%e4
      ! e444 x e4 -> e4444 (17, 5)
      RES(1+NROWS*16:NROWS*17,1+NCOLS*4:NCOLS*5) = VAL%e444
      ! e44 x e44 -> e4444 (17, 9)
      RES(1+NROWS*16:NROWS*17,1+NCOLS*8:NCOLS*9) = VAL%e44
   END FUNCTION donumm4n4_TO_CR_MAT_M

      SUBROUTINE donumm4n4_SETIM_S(VAL,IDX,RES)
      IMPLICIT NONE
      TYPE(donumm4n4), INTENT(INOUT) :: VAL
      REAL(DP),INTENT(IN) :: RES 
      INTEGER, INTENT(IN) :: IDX

      SELECT CASE(IDX)
      ! Order 0
      CASE(0)
         VAL%r=RES

      ! Order 1
      CASE(1)
         VAL%e1=RES
      CASE(2)
         VAL%e2=RES
      CASE(3)
         VAL%e3=RES
      CASE(4)
         VAL%e4=RES

      ! Order 2
      CASE(5)
         VAL%e11=RES
      CASE(6)
         VAL%e22=RES
      CASE(7)
         VAL%e33=RES
      CASE(8)
         VAL%e44=RES

      ! Order 3
      CASE(9)
         VAL%e111=RES
      CASE(10)
         VAL%e222=RES
      CASE(11)
         VAL%e333=RES
      CASE(12)
         VAL%e444=RES

      ! Order 4
      CASE(13)
         VAL%e1111=RES
      CASE(14)
         VAL%e2222=RES
      CASE(15)
         VAL%e3333=RES
      CASE(16)
         VAL%e4444=RES

      END SELECT
   END SUBROUTINE donumm4n4_SETIM_S

      SUBROUTINE donumm4n4_SETIM_V(VAL,IDX,RES)
      IMPLICIT NONE
      TYPE(donumm4n4), INTENT(INOUT) :: VAL(:)
      REAL(DP),INTENT(IN) :: RES(SIZE(VAL)) 
      INTEGER, INTENT(IN) :: IDX

      SELECT CASE(IDX)
      ! Order 0
      CASE(0)
         VAL%r=RES

      ! Order 1
      CASE(1)
         VAL%e1=RES
      CASE(2)
         VAL%e2=RES
      CASE(3)
         VAL%e3=RES
      CASE(4)
         VAL%e4=RES

      ! Order 2
      CASE(5)
         VAL%e11=RES
      CASE(6)
         VAL%e22=RES
      CASE(7)
         VAL%e33=RES
      CASE(8)
         VAL%e44=RES

      ! Order 3
      CASE(9)
         VAL%e111=RES
      CASE(10)
         VAL%e222=RES
      CASE(11)
         VAL%e333=RES
      CASE(12)
         VAL%e444=RES

      ! Order 4
      CASE(13)
         VAL%e1111=RES
      CASE(14)
         VAL%e2222=RES
      CASE(15)
         VAL%e3333=RES
      CASE(16)
         VAL%e4444=RES

      END SELECT
   END SUBROUTINE donumm4n4_SETIM_V

      SUBROUTINE donumm4n4_SETIM_M(VAL,IDX,RES)
      IMPLICIT NONE
      TYPE(donumm4n4), INTENT(INOUT) :: VAL(:,:)
      REAL(DP),INTENT(IN) :: RES(SIZE(VAL,1),SIZE(VAL,2)) 
      INTEGER, INTENT(IN) :: IDX

      SELECT CASE(IDX)
      ! Order 0
      CASE(0)
         VAL%r=RES

      ! Order 1
      CASE(1)
         VAL%e1=RES
      CASE(2)
         VAL%e2=RES
      CASE(3)
         VAL%e3=RES
      CASE(4)
         VAL%e4=RES

      ! Order 2
      CASE(5)
         VAL%e11=RES
      CASE(6)
         VAL%e22=RES
      CASE(7)
         VAL%e33=RES
      CASE(8)
         VAL%e44=RES

      ! Order 3
      CASE(9)
         VAL%e111=RES
      CASE(10)
         VAL%e222=RES
      CASE(11)
         VAL%e333=RES
      CASE(12)
         VAL%e444=RES

      ! Order 4
      CASE(13)
         VAL%e1111=RES
      CASE(14)
         VAL%e2222=RES
      CASE(15)
         VAL%e3333=RES
      CASE(16)
         VAL%e4444=RES

      END SELECT
   END SUBROUTINE donumm4n4_SETIM_M

FUNCTION donumm4n4_GETIM_S(VAL,IDX) RESULT(RES)
      IMPLICIT NONE
      TYPE(donumm4n4), INTENT(IN) :: VAL
      REAL(DP) :: RES 
      INTEGER, INTENT(IN) :: IDX

      SELECT CASE(IDX)
      ! Order 0
      CASE(0)
         RES=VAL%r

      ! Order 1
      CASE(1)
         RES=VAL%e1
      CASE(2)
         RES=VAL%e2
      CASE(3)
         RES=VAL%e3
      CASE(4)
         RES=VAL%e4

      ! Order 2
      CASE(5)
         RES=VAL%e11
      CASE(6)
         RES=VAL%e22
      CASE(7)
         RES=VAL%e33
      CASE(8)
         RES=VAL%e44

      ! Order 3
      CASE(9)
         RES=VAL%e111
      CASE(10)
         RES=VAL%e222
      CASE(11)
         RES=VAL%e333
      CASE(12)
         RES=VAL%e444

      ! Order 4
      CASE(13)
         RES=VAL%e1111
      CASE(14)
         RES=VAL%e2222
      CASE(15)
         RES=VAL%e3333
      CASE(16)
         RES=VAL%e4444

      END SELECT
   END FUNCTION donumm4n4_GETIM_S

FUNCTION donumm4n4_GETIM_V(VAL,IDX) RESULT(RES)
      IMPLICIT NONE
      TYPE(donumm4n4), INTENT(IN) :: VAL(:)
      REAL(DP) :: RES(SIZE(VAL)) 
      INTEGER, INTENT(IN) :: IDX

      SELECT CASE(IDX)
      ! Order 0
      CASE(0)
         RES=VAL%r

      ! Order 1
      CASE(1)
         RES=VAL%e1
      CASE(2)
         RES=VAL%e2
      CASE(3)
         RES=VAL%e3
      CASE(4)
         RES=VAL%e4

      ! Order 2
      CASE(5)
         RES=VAL%e11
      CASE(6)
         RES=VAL%e22
      CASE(7)
         RES=VAL%e33
      CASE(8)
         RES=VAL%e44

      ! Order 3
      CASE(9)
         RES=VAL%e111
      CASE(10)
         RES=VAL%e222
      CASE(11)
         RES=VAL%e333
      CASE(12)
         RES=VAL%e444

      ! Order 4
      CASE(13)
         RES=VAL%e1111
      CASE(14)
         RES=VAL%e2222
      CASE(15)
         RES=VAL%e3333
      CASE(16)
         RES=VAL%e4444

      END SELECT
   END FUNCTION donumm4n4_GETIM_V

FUNCTION donumm4n4_GETIM_M(VAL,IDX) RESULT(RES)
      IMPLICIT NONE
      TYPE(donumm4n4), INTENT(IN) :: VAL(:,:)
      REAL(DP) :: RES(SIZE(VAL,1),SIZE(VAL,2)) 
      INTEGER, INTENT(IN) :: IDX

      SELECT CASE(IDX)
      ! Order 0
      CASE(0)
         RES=VAL%r

      ! Order 1
      CASE(1)
         RES=VAL%e1
      CASE(2)
         RES=VAL%e2
      CASE(3)
         RES=VAL%e3
      CASE(4)
         RES=VAL%e4

      ! Order 2
      CASE(5)
         RES=VAL%e11
      CASE(6)
         RES=VAL%e22
      CASE(7)
         RES=VAL%e33
      CASE(8)
         RES=VAL%e44

      ! Order 3
      CASE(9)
         RES=VAL%e111
      CASE(10)
         RES=VAL%e222
      CASE(11)
         RES=VAL%e333
      CASE(12)
         RES=VAL%e444

      ! Order 4
      CASE(13)
         RES=VAL%e1111
      CASE(14)
         RES=VAL%e2222
      CASE(15)
         RES=VAL%e3333
      CASE(16)
         RES=VAL%e4444

      END SELECT
   END FUNCTION donumm4n4_GETIM_M

   SUBROUTINE donumm4n4_PPRINT_S(VAR,FMT,UNIT)
      IMPLICIT NONE
      TYPE(donumm4n4), INTENT(IN) :: VAR
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
      CALL PPRINT(VAR%r,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') ' '

      !  Order 1
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'e1 * '
      CALL PPRINT(VAR%e1,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'e2 * '
      CALL PPRINT(VAR%e2,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'e3 * '
      CALL PPRINT(VAR%e3,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'e4 * '
      CALL PPRINT(VAR%e4,unit=unt,fmt=output_format)

      !  Order 2
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'e11 * '
      CALL PPRINT(VAR%e11,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'e22 * '
      CALL PPRINT(VAR%e22,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'e33 * '
      CALL PPRINT(VAR%e33,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'e44 * '
      CALL PPRINT(VAR%e44,unit=unt,fmt=output_format)

      !  Order 3
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'e111 * '
      CALL PPRINT(VAR%e111,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'e222 * '
      CALL PPRINT(VAR%e222,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'e333 * '
      CALL PPRINT(VAR%e333,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'e444 * '
      CALL PPRINT(VAR%e444,unit=unt,fmt=output_format)

      !  Order 4
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'e1111 * '
      CALL PPRINT(VAR%e1111,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'e2222 * '
      CALL PPRINT(VAR%e2222,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'e3333 * '
      CALL PPRINT(VAR%e3333,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='NO') '+ '
      WRITE(unt,'(A)',advance='NO') 'e4444 * '
      CALL PPRINT(VAR%e4444,unit=unt,fmt=output_format)


   END SUBROUTINE donumm4n4_PPRINT_S

   SUBROUTINE donumm4n4_PPRINT_V(VAR,FMT,UNIT)
      IMPLICIT NONE
      TYPE(donumm4n4), INTENT(IN) :: VAR(:)
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
      CALL PPRINT(VAR%r,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') ' '

      !  Order 1
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'e1 * '
      CALL PPRINT(VAR%e1,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'e2 * '
      CALL PPRINT(VAR%e2,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'e3 * '
      CALL PPRINT(VAR%e3,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'e4 * '
      CALL PPRINT(VAR%e4,unit=unt,fmt=output_format)

      !  Order 2
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'e11 * '
      CALL PPRINT(VAR%e11,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'e22 * '
      CALL PPRINT(VAR%e22,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'e33 * '
      CALL PPRINT(VAR%e33,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'e44 * '
      CALL PPRINT(VAR%e44,unit=unt,fmt=output_format)

      !  Order 3
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'e111 * '
      CALL PPRINT(VAR%e111,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'e222 * '
      CALL PPRINT(VAR%e222,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'e333 * '
      CALL PPRINT(VAR%e333,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'e444 * '
      CALL PPRINT(VAR%e444,unit=unt,fmt=output_format)

      !  Order 4
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'e1111 * '
      CALL PPRINT(VAR%e1111,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'e2222 * '
      CALL PPRINT(VAR%e2222,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'e3333 * '
      CALL PPRINT(VAR%e3333,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'e4444 * '
      CALL PPRINT(VAR%e4444,unit=unt,fmt=output_format)


   END SUBROUTINE donumm4n4_PPRINT_V

   SUBROUTINE donumm4n4_PPRINT_M(VAR,FMT,UNIT)
      IMPLICIT NONE
      TYPE(donumm4n4), INTENT(IN) :: VAR(:,:)
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
      CALL PPRINT(VAR%r,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') ' '

      !  Order 1
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'e1 * '
      CALL PPRINT(VAR%e1,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'e2 * '
      CALL PPRINT(VAR%e2,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'e3 * '
      CALL PPRINT(VAR%e3,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'e4 * '
      CALL PPRINT(VAR%e4,unit=unt,fmt=output_format)

      !  Order 2
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'e11 * '
      CALL PPRINT(VAR%e11,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'e22 * '
      CALL PPRINT(VAR%e22,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'e33 * '
      CALL PPRINT(VAR%e33,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'e44 * '
      CALL PPRINT(VAR%e44,unit=unt,fmt=output_format)

      !  Order 3
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'e111 * '
      CALL PPRINT(VAR%e111,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'e222 * '
      CALL PPRINT(VAR%e222,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'e333 * '
      CALL PPRINT(VAR%e333,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'e444 * '
      CALL PPRINT(VAR%e444,unit=unt,fmt=output_format)

      !  Order 4
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'e1111 * '
      CALL PPRINT(VAR%e1111,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'e2222 * '
      CALL PPRINT(VAR%e2222,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'e3333 * '
      CALL PPRINT(VAR%e3333,unit=unt,fmt=output_format)
      WRITE(unt,'(A)',advance='YES') '+ '
      WRITE(unt,'(A)',advance='YES') 'e4444 * '
      CALL PPRINT(VAR%e4444,unit=unt,fmt=output_format)


   END SUBROUTINE donumm4n4_PPRINT_M

   ELEMENTAL FUNCTION donumm4n4_FEVAL(X,DER0,DER1,DER2,DER3,DER4)&
      RESULT(RES)
      IMPLICIT NONE
      !  Definitions
      REAL(DP) :: FACTOR, COEF
      TYPE(donumm4n4), INTENT(IN)  :: X
      REAL(DP), INTENT(IN)  :: DER0,DER1,DER2,DER3,DER4
      TYPE(donumm4n4) :: RES
      TYPE(donumm4n4) :: DX, DX_P

      FACTOR = 1.0_DP
      COEF   = 0.0_DP
      DX     = X
      DX_P   = X

      !  Set real part of deltas zero.
      DX%r = 0.0_dp
      DX_P%r = 0.0_dp

      ! Sets real part
      RES = DER0

      ! Sets order 1
      FACTOR = FACTOR * 1
      COEF = DER1 / FACTOR
      ! RES = RES COEF * DX_P
      ! Order 4
      RES%e1111 = RES%e1111+COEF*DX_P%e1111
      RES%e2222 = RES%e2222+COEF*DX_P%e2222
      RES%e3333 = RES%e3333+COEF*DX_P%e3333
      RES%e4444 = RES%e4444+COEF*DX_P%e4444
      ! Order 3
      RES%e111 = RES%e111+COEF*DX_P%e111
      RES%e222 = RES%e222+COEF*DX_P%e222
      RES%e333 = RES%e333+COEF*DX_P%e333
      RES%e444 = RES%e444+COEF*DX_P%e444
      ! Order 2
      RES%e11 = RES%e11+COEF*DX_P%e11
      RES%e22 = RES%e22+COEF*DX_P%e22
      RES%e33 = RES%e33+COEF*DX_P%e33
      RES%e44 = RES%e44+COEF*DX_P%e44
      ! Order 1
      RES%e1 = RES%e1+COEF*DX_P%e1
      RES%e2 = RES%e2+COEF*DX_P%e2
      RES%e3 = RES%e3+COEF*DX_P%e3
      RES%e4 = RES%e4+COEF*DX_P%e4
      ! DX_P = DX_P * DX
      ! Order 4
      DX_P%e1111 = DX_P%e1*DX%e111+DX_P%e111*DX%e1+ &
                DX_P%e11*DX%e11
      DX_P%e2222 = DX_P%e2*DX%e222+DX_P%e222*DX%e2+ &
                DX_P%e22*DX%e22
      DX_P%e3333 = DX_P%e3*DX%e333+DX_P%e333*DX%e3+ &
                DX_P%e33*DX%e33
      DX_P%e4444 = DX_P%e4*DX%e444+DX_P%e444*DX%e4+ &
                DX_P%e44*DX%e44
      ! Order 3
      DX_P%e111 = DX_P%e1*DX%e11+DX_P%e11*DX%e1
      DX_P%e222 = DX_P%e2*DX%e22+DX_P%e22*DX%e2
      DX_P%e333 = DX_P%e3*DX%e33+DX_P%e33*DX%e3
      DX_P%e444 = DX_P%e4*DX%e44+DX_P%e44*DX%e4
      ! Order 2
      DX_P%e11 = DX_P%e1*DX%e1
      DX_P%e22 = DX_P%e2*DX%e2
      DX_P%e33 = DX_P%e3*DX%e3
      DX_P%e44 = DX_P%e4*DX%e4
      
      ! Sets order 2
      FACTOR = FACTOR * 2
      COEF = DER2 / FACTOR
      ! RES = RES COEF * DX_P
      ! Order 4
      RES%e1111 = RES%e1111+COEF*DX_P%e1111
      RES%e2222 = RES%e2222+COEF*DX_P%e2222
      RES%e3333 = RES%e3333+COEF*DX_P%e3333
      RES%e4444 = RES%e4444+COEF*DX_P%e4444
      ! Order 3
      RES%e111 = RES%e111+COEF*DX_P%e111
      RES%e222 = RES%e222+COEF*DX_P%e222
      RES%e333 = RES%e333+COEF*DX_P%e333
      RES%e444 = RES%e444+COEF*DX_P%e444
      ! Order 2
      RES%e11 = RES%e11+COEF*DX_P%e11
      RES%e22 = RES%e22+COEF*DX_P%e22
      RES%e33 = RES%e33+COEF*DX_P%e33
      RES%e44 = RES%e44+COEF*DX_P%e44
      ! DX_P = DX_P * DX
      ! Order 4
      DX_P%e1111 = DX_P%e111*DX%e1+DX_P%e11*DX%e11
      DX_P%e2222 = DX_P%e222*DX%e2+DX_P%e22*DX%e22
      DX_P%e3333 = DX_P%e333*DX%e3+DX_P%e33*DX%e33
      DX_P%e4444 = DX_P%e444*DX%e4+DX_P%e44*DX%e44
      ! Order 3
      DX_P%e111 = DX_P%e11*DX%e1
      DX_P%e222 = DX_P%e22*DX%e2
      DX_P%e333 = DX_P%e33*DX%e3
      DX_P%e444 = DX_P%e44*DX%e4
      
      ! Sets order 3
      FACTOR = FACTOR * 3
      COEF = DER3 / FACTOR
      ! RES = RES COEF * DX_P
      ! Order 4
      RES%e1111 = RES%e1111+COEF*DX_P%e1111
      RES%e2222 = RES%e2222+COEF*DX_P%e2222
      RES%e3333 = RES%e3333+COEF*DX_P%e3333
      RES%e4444 = RES%e4444+COEF*DX_P%e4444
      ! Order 3
      RES%e111 = RES%e111+COEF*DX_P%e111
      RES%e222 = RES%e222+COEF*DX_P%e222
      RES%e333 = RES%e333+COEF*DX_P%e333
      RES%e444 = RES%e444+COEF*DX_P%e444
      ! DX_P = DX_P * DX
      ! Order 4
      DX_P%e1111 = DX_P%e111*DX%e1
      DX_P%e2222 = DX_P%e222*DX%e2
      DX_P%e3333 = DX_P%e333*DX%e3
      DX_P%e4444 = DX_P%e444*DX%e4
      
      ! Sets order 4
      FACTOR = FACTOR * 4
      COEF = DER4 / FACTOR
      ! RES = RES COEF * DX_P
      ! Order 4
      RES%e1111 = RES%e1111+COEF*DX_P%e1111
      RES%e2222 = RES%e2222+COEF*DX_P%e2222
      RES%e3333 = RES%e3333+COEF*DX_P%e3333
      RES%e4444 = RES%e4444+COEF*DX_P%e4444
      
   END FUNCTION donumm4n4_FEVAL


  ! SUBROUTINE donumm4n4_PPRINT_M_R(X, FMT)
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

  ! END SUBROUTINE donumm4n4_PPRINT_M_R

  ! SUBROUTINE donumm4n4_PPRINT_V_R(X, FMT)
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

  ! END SUBROUTINE donumm4n4_PPRINT_V_R

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
  PURE FUNCTION donumm4n4_det2x2(A) RESULT(det)

    IMPLICIT NONE

    TYPE(donumm4n4), INTENT(IN) :: A(2,2)   !! Matrix
    TYPE(donumm4n4)             :: det

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
  PURE FUNCTION donumm4n4_det3x3(A) RESULT(det)
      
    IMPLICIT NONE

    TYPE(donumm4n4), INTENT(IN) :: A(3,3)   !! Matrix
    TYPE(donumm4n4)             :: det

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
  PURE FUNCTION donumm4n4_det4x4(A) RESULT(det)
      
    IMPLICIT NONE

    TYPE(donumm4n4), INTENT(IN) :: A(4,4)   !! Matrix
    TYPE(donumm4n4)             :: det

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
  PURE FUNCTION donumm4n4_cross3(a,b) RESULT(v)
      
    IMPLICIT NONE 

    TYPE(donumm4n4), DIMENSION (3),INTENT(IN) :: a,b
    TYPE(donumm4n4), DIMENSION (3) :: v
    
    v(1) = a(2) * b(3) - a(3) * b(2)
    v(2) = a(3) * b(1) - a(1) * b(3)
    v(3) = a(1) * b(2) - a(2) * b(1)

  END FUNCTION donumm4n4_cross3
  !===================================================================================================! 

  !***************************************************************************************************! 
  !> @brief Norm of a 3 element vector. # There is an intrinsic function named norm2.
  !!
  !! @param[in] a: Vector of 3 reals (rank 1).
  !! @param[in] b: Vector of 3 reals (rank 1).
  !!
  !***************************************************************************************************!
  FUNCTION donumm4n4_norm2_3(v) RESULT(n)
     
    IMPLICIT NONE 

    TYPE(donumm4n4), INTENT(IN) :: v(3)
    TYPE(donumm4n4) :: n
     
    n = SQRT( v(1)*v(1) + v(2)*v(2) + v(3)*v(3) )

  END FUNCTION donumm4n4_norm2_3
  !===================================================================================================! 

  ELEMENTAL FUNCTION donumm4n4_DIVISION_OO(X,Y) RESULT(RES)
      IMPLICIT NONE
      ! REAL(DP) :: DERIVS(TORDER + 1) 
      TYPE(donumm4n4), INTENT(IN) :: X
      TYPE(donumm4n4), INTENT(IN) :: Y
      TYPE(donumm4n4) :: RES

      RES = X*(Y**(-1.d0))

  END FUNCTION donumm4n4_DIVISION_OO

  ELEMENTAL FUNCTION donumm4n4_DIVISION_OR(X,Y) RESULT(RES)
      IMPLICIT NONE
      ! REAL(DP) :: DERIVS(TORDER + 1) 
      TYPE(donumm4n4), INTENT(IN) :: X
      REAL(DP), INTENT(IN) :: Y
      TYPE(donumm4n4) :: RES

      RES = X*(Y**(-1.d0))

  END FUNCTION donumm4n4_DIVISION_OR

  ELEMENTAL FUNCTION donumm4n4_DIVISION_RO(X,Y) RESULT(RES)
      IMPLICIT NONE
      ! REAL(DP) :: DERIVS(TORDER + 1) 
      REAL(DP), INTENT(IN) :: X
      TYPE(donumm4n4), INTENT(IN) :: Y
      TYPE(donumm4n4) :: RES

      RES = X*(Y**(-1.d0))

  END FUNCTION donumm4n4_DIVISION_RO

  ELEMENTAL FUNCTION donumm4n4_REAL(X) RESULT(RES)
      IMPLICIT NONE
      TYPE(donumm4n4), INTENT(IN) :: X
      REAL(DP) :: RES

      RES = X%R

  END FUNCTION donumm4n4_REAL

  FUNCTION donumm4n4_SQRT(X) RESULT(RES)
      IMPLICIT NONE
      TYPE(donumm4n4), INTENT(IN) :: X
      TYPE(donumm4n4) :: RES

      RES = X**0.5_DP

  END FUNCTION donumm4n4_SQRT

   ELEMENTAL FUNCTION donumm4n4_TAN(X) RESULT(RES)

      TYPE(donumm4n4), INTENT(IN) :: X
      REAL(DP) :: DER0,DER1,DER2,DER3,DER4
      TYPE(donumm4n4) :: RES
      
      DER0 = TAN(X%R)
      DER1 = TAN(X%R)**2 + 1
      DER2 = 2*(TAN(X%R)**2 + 1)*TAN(X%R)
      DER3 = 2*(TAN(X%R)**2 + 1)*(3*TAN(X%R)**2 + 1)
      DER4 = 8*(TAN(X%R)**2 + 1)*(3*TAN(X%R)**2 + 2)*TAN(X%R)

      RES = FEVAL(X,DER0,DER1,DER2,DER3,DER4)

   END FUNCTION donumm4n4_TAN

   ELEMENTAL FUNCTION donumm4n4_COS(X) RESULT(RES)

      TYPE(donumm4n4), INTENT(IN) :: X
      REAL(DP) :: DER0,DER1,DER2,DER3,DER4
      TYPE(donumm4n4) :: RES
      
      DER0 = COS(X%R)
      DER1 = -SIN(X%R)
      DER2 = -COS(X%R)
      DER3 = SIN(X%R)
      DER4 = COS(X%R)

      RES = FEVAL(X,DER0,DER1,DER2,DER3,DER4)

   END FUNCTION donumm4n4_COS

   ELEMENTAL FUNCTION donumm4n4_SIN(X) RESULT(RES)

      TYPE(donumm4n4), INTENT(IN) :: X
      REAL(DP) :: DER0,DER1,DER2,DER3,DER4
      TYPE(donumm4n4) :: RES
      
      DER0 = SIN(X%R)
      DER1 = COS(X%R)
      DER2 = -SIN(X%R)
      DER3 = -COS(X%R)
      DER4 = SIN(X%R)

      RES = FEVAL(X,DER0,DER1,DER2,DER3,DER4)

   END FUNCTION donumm4n4_SIN

   ELEMENTAL FUNCTION donumm4n4_ATAN(X) RESULT(RES)

      TYPE(donumm4n4), INTENT(IN) :: X
      REAL(DP) :: DER0,DER1,DER2,DER3,DER4
      TYPE(donumm4n4) :: RES
      
      DER0 = ATAN(X%R)
      DER1 = 1D0/(X%R**2 + 1)
      DER2 = -2*X%R/(X%R**2 + 1)**2
      DER3 = 2*(4*X%R**2/(X%R**2 + 1) - 1)/(X%R**2 + 1)**2
      DER4 = 24*X%R*(-2*X%R**2/(X%R**2 + 1) + 1)/(X%R**2 + 1)**3

      RES = FEVAL(X,DER0,DER1,DER2,DER3,DER4)

   END FUNCTION donumm4n4_ATAN

   ELEMENTAL FUNCTION donumm4n4_ACOS(X) RESULT(RES)

      TYPE(donumm4n4), INTENT(IN) :: X
      REAL(DP) :: DER0,DER1,DER2,DER3,DER4
      TYPE(donumm4n4) :: RES
      
      DER0 = ACOS(X%R)
      DER1 = -1/SQRT(1 - X%R**2)
      DER2 = -X%R/(1 - X%R**2)**(3.0D0/2.0D0)
      DER3 = -(3*X%R**2/(1 - X%R**2) + 1)/(1 - X%R**2)**(3.0D0/2.0D0)
      DER4 = -3*X%R*(5*X%R**2/(1 - X%R**2) + 3)/(1 - X%R**2)**(5.0D0/2.0D0)

      RES = FEVAL(X,DER0,DER1,DER2,DER3,DER4)

   END FUNCTION donumm4n4_ACOS

   ELEMENTAL FUNCTION donumm4n4_ASIN(X) RESULT(RES)

      TYPE(donumm4n4), INTENT(IN) :: X
      REAL(DP) :: DER0,DER1,DER2,DER3,DER4
      TYPE(donumm4n4) :: RES
      
      DER0 = ASIN(X%R)
      DER1 = 1/SQRT(1 - X%R**2)
      DER2 = X%R/(1 - X%R**2)**(3.0D0/2.0D0)
      DER3 = (3*X%R**2/(1 - X%R**2) + 1)/(1 - X%R**2)**(3.0D0/2.0D0)
      DER4 = 3*X%R*(5*X%R**2/(1 - X%R**2) + 3)/(1 - X%R**2)**(5.0D0/2.0D0)

      RES = FEVAL(X,DER0,DER1,DER2,DER3,DER4)

   END FUNCTION donumm4n4_ASIN

   ELEMENTAL FUNCTION donumm4n4_TANH(X) RESULT(RES)

      TYPE(donumm4n4), INTENT(IN) :: X
      REAL(DP) :: DER0,DER1,DER2,DER3,DER4
      TYPE(donumm4n4) :: RES
      
      DER0 = TANH(X%R)
      DER1 = 1 - TANH(X%R)**2
      DER2 = 2*(TANH(X%R)**2 - 1)*TANH(X%R)
      DER3 = -2*(TANH(X%R)**2 - 1)*(3*TANH(X%R)**2 - 1)
      DER4 = 8*(TANH(X%R)**2 - 1)*(3*TANH(X%R)**2 - 2)*TANH(X%R)

      RES = FEVAL(X,DER0,DER1,DER2,DER3,DER4)

   END FUNCTION donumm4n4_TANH

   ELEMENTAL FUNCTION donumm4n4_COSH(X) RESULT(RES)

      TYPE(donumm4n4), INTENT(IN) :: X
      REAL(DP) :: DER0,DER1,DER2,DER3,DER4
      TYPE(donumm4n4) :: RES
      
      DER0 = COSH(X%R)
      DER1 = SINH(X%R)
      DER2 = COSH(X%R)
      DER3 = SINH(X%R)
      DER4 = COSH(X%R)

      RES = FEVAL(X,DER0,DER1,DER2,DER3,DER4)

   END FUNCTION donumm4n4_COSH

   ELEMENTAL FUNCTION donumm4n4_SINH(X) RESULT(RES)

      TYPE(donumm4n4), INTENT(IN) :: X
      REAL(DP) :: DER0,DER1,DER2,DER3,DER4
      TYPE(donumm4n4) :: RES
      
      DER0 = SINH(X%R)
      DER1 = COSH(X%R)
      DER2 = SINH(X%R)
      DER3 = COSH(X%R)
      DER4 = SINH(X%R)

      RES = FEVAL(X,DER0,DER1,DER2,DER3,DER4)

   END FUNCTION donumm4n4_SINH

   ELEMENTAL FUNCTION donumm4n4_EXP(X) RESULT(RES)

      TYPE(donumm4n4), INTENT(IN) :: X
      REAL(DP) :: DER0,DER1,DER2,DER3,DER4
      TYPE(donumm4n4) :: RES
      
      DER0 = EXP(X%R)
      DER1 = EXP(X%R)
      DER2 = EXP(X%R)
      DER3 = EXP(X%R)
      DER4 = EXP(X%R)

      RES = FEVAL(X,DER0,DER1,DER2,DER3,DER4)

   END FUNCTION donumm4n4_EXP

   ELEMENTAL FUNCTION donumm4n4_LOG(X) RESULT(RES)

      TYPE(donumm4n4), INTENT(IN) :: X
      REAL(DP) :: DER0,DER1,DER2,DER3,DER4
      TYPE(donumm4n4) :: RES
      
      DER0 = LOG(X%R)
      DER1 = 1D0/X%R
      DER2 = -1/X%R**2
      DER3 = 2/X%R**3
      DER4 = -6/X%R**4

      RES = FEVAL(X,DER0,DER1,DER2,DER3,DER4)

   END FUNCTION donumm4n4_LOG

   ELEMENTAL FUNCTION donumm4n4_POW_OR(X,E) RESULT(RES)

      TYPE(donumm4n4), INTENT(IN) :: X
      REAL(DP), INTENT(IN) :: E
      REAL(DP) :: DER0,DER1,DER2,DER3,DER4
      TYPE(donumm4n4) :: RES
      
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

   END FUNCTION donumm4n4_POW_OR

   ELEMENTAL FUNCTION donumm4n4_POW_RO(E,X) RESULT(RES)

      TYPE(donumm4n4), INTENT(IN) :: X
      REAL(DP), INTENT(IN) :: E
      REAL(DP) :: DER0,DER1,DER2,DER3,DER4
      TYPE(donumm4n4) :: RES
      
      
      DER0 = E**X%R
      DER1 = E**X%R*LOG(E)
      DER2 = E**X%R*LOG(E)**2
      DER3 = E**X%R*LOG(E)**3
      DER4 = E**X%R*LOG(E)**4

      RES = FEVAL(X,DER0,DER1,DER2,DER3,DER4)

   END FUNCTION donumm4n4_POW_RO

   ELEMENTAL FUNCTION donumm4n4_F2EVAL(X,Y,DER0_0,DER1_0,DER1_1, &
                                   DER2_0,DER2_1,DER2_2,DER3_0, &
                                   DER3_1,DER3_2,DER3_3,DER4_0, &
                                   DER4_1,DER4_2,DER4_3,DER4_4)&
      RESULT(RES)
      IMPLICIT NONE
      !  Definitions
      REAL(DP) :: COEF, DELTA
      TYPE(donumm4n4), INTENT(IN)  :: X,Y
      REAL(DP), INTENT(IN)  :: DER0_0,DER1_0,DER1_1, &
                               DER2_0,DER2_1,DER2_2,DER3_0, &
                               DER3_1,DER3_2,DER3_3,DER4_0, &
                               DER4_1,DER4_2,DER4_3,DER4_4
      TYPE(donumm4n4) :: RES
      TYPE(donumm4n4) :: DX, DY

      COEF   = 0.0_DP
      DX     = X
      DY     = Y

      !  Set real part of deltas zero.
      DX%r = 0.0_dp
      DY%r = 0.0_dp

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

      

   END FUNCTION donumm4n4_F2EVAL


   ELEMENTAL FUNCTION donumm4n4_POW_OO(X,Y) RESULT(RES)

      TYPE(donumm4n4), INTENT(IN) :: X, Y
      REAL(DP) :: DER0_0,DER1_0,DER1_1,DER2_0,DER2_1,DER2_2,DER3_0,DER3_1,DER3_2,DER3_3,DER4_0,DER4_1,DER4_2,DER4_3,DER4_4
      TYPE(donumm4n4) :: RES
      
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

   END FUNCTION donumm4n4_POW_OO


   FUNCTION donumm4n4_INV2X2(A,det)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(donumm4n4) , INTENT(IN) :: A(2,2) 
      TYPE(donumm4n4) , INTENT(IN), OPTIONAL :: det
      REAL(DP) :: detCalc
      TYPE(donumm4n4) :: RES(SIZE(A,1),SIZE(A,2)) 

      IF (PRESENT(det)) THEN
         detCalc=det%R
      ELSE
         detCalc=det2x2(A%R)
      END IF

      ! Get real part 
      RES%R=INV2X2(A%R,detCalc)

      ! Order 1
      RES%e1=-MATMUL(RES%R,(MATMUL(A%e1,RES%r)))
      RES%e2=-MATMUL(RES%R,(MATMUL(A%e2,RES%r)))
      RES%e3=-MATMUL(RES%R,(MATMUL(A%e3,RES%r)))
      RES%e4=-MATMUL(RES%R,(MATMUL(A%e4,RES%r)))

      ! Order 2
      RES%e11=-MATMUL(RES%R,(MATMUL(A%e11,RES%r)+MATMUL(A%e1,RES%e1)))
      RES%e22=-MATMUL(RES%R,(MATMUL(A%e22,RES%r)+MATMUL(A%e2,RES%e2)))
      RES%e33=-MATMUL(RES%R,(MATMUL(A%e33,RES%r)+MATMUL(A%e3,RES%e3)))
      RES%e44=-MATMUL(RES%R,(MATMUL(A%e44,RES%r)+MATMUL(A%e4,RES%e4)))

      ! Order 3
      RES%e111=-MATMUL(RES%R,(MATMUL(A%e111,RES%r)+MATMUL(A%e1,RES%e11)+&
              MATMUL(A%e11,RES%e1)))
      RES%e222=-MATMUL(RES%R,(MATMUL(A%e222,RES%r)+MATMUL(A%e2,RES%e22)+&
              MATMUL(A%e22,RES%e2)))
      RES%e333=-MATMUL(RES%R,(MATMUL(A%e333,RES%r)+MATMUL(A%e3,RES%e33)+&
              MATMUL(A%e33,RES%e3)))
      RES%e444=-MATMUL(RES%R,(MATMUL(A%e444,RES%r)+MATMUL(A%e4,RES%e44)+&
              MATMUL(A%e44,RES%e4)))

      ! Order 4
      RES%e1111=-MATMUL(RES%R,(MATMUL(A%e1111,RES%r)+MATMUL(A%e1,RES%e111)+&
               MATMUL(A%e111,RES%e1)+MATMUL(A%e11,RES%e11)))
      RES%e2222=-MATMUL(RES%R,(MATMUL(A%e2222,RES%r)+MATMUL(A%e2,RES%e222)+&
               MATMUL(A%e222,RES%e2)+MATMUL(A%e22,RES%e22)))
      RES%e3333=-MATMUL(RES%R,(MATMUL(A%e3333,RES%r)+MATMUL(A%e3,RES%e333)+&
               MATMUL(A%e333,RES%e3)+MATMUL(A%e33,RES%e33)))
      RES%e4444=-MATMUL(RES%R,(MATMUL(A%e4444,RES%r)+MATMUL(A%e4,RES%e444)+&
               MATMUL(A%e444,RES%e4)+MATMUL(A%e44,RES%e44)))

   END FUNCTION donumm4n4_INV2X2

   FUNCTION donumm4n4_INV3X3(A,det)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(donumm4n4) , INTENT(IN) :: A(3,3) 
      TYPE(donumm4n4) , INTENT(IN), OPTIONAL :: det
      REAL(DP) :: detCalc
      TYPE(donumm4n4) :: RES(SIZE(A,1),SIZE(A,2)) 

      IF (PRESENT(det)) THEN
         detCalc=det%R
      ELSE
         detCalc=det3x3(A%R)
      END IF

      ! Get real part 
      RES%R=INV3X3(A%R,detCalc)

      ! Order 1
      RES%e1=-MATMUL(RES%R,(MATMUL(A%e1,RES%r)))
      RES%e2=-MATMUL(RES%R,(MATMUL(A%e2,RES%r)))
      RES%e3=-MATMUL(RES%R,(MATMUL(A%e3,RES%r)))
      RES%e4=-MATMUL(RES%R,(MATMUL(A%e4,RES%r)))

      ! Order 2
      RES%e11=-MATMUL(RES%R,(MATMUL(A%e11,RES%r)+MATMUL(A%e1,RES%e1)))
      RES%e22=-MATMUL(RES%R,(MATMUL(A%e22,RES%r)+MATMUL(A%e2,RES%e2)))
      RES%e33=-MATMUL(RES%R,(MATMUL(A%e33,RES%r)+MATMUL(A%e3,RES%e3)))
      RES%e44=-MATMUL(RES%R,(MATMUL(A%e44,RES%r)+MATMUL(A%e4,RES%e4)))

      ! Order 3
      RES%e111=-MATMUL(RES%R,(MATMUL(A%e111,RES%r)+MATMUL(A%e1,RES%e11)+&
              MATMUL(A%e11,RES%e1)))
      RES%e222=-MATMUL(RES%R,(MATMUL(A%e222,RES%r)+MATMUL(A%e2,RES%e22)+&
              MATMUL(A%e22,RES%e2)))
      RES%e333=-MATMUL(RES%R,(MATMUL(A%e333,RES%r)+MATMUL(A%e3,RES%e33)+&
              MATMUL(A%e33,RES%e3)))
      RES%e444=-MATMUL(RES%R,(MATMUL(A%e444,RES%r)+MATMUL(A%e4,RES%e44)+&
              MATMUL(A%e44,RES%e4)))

      ! Order 4
      RES%e1111=-MATMUL(RES%R,(MATMUL(A%e1111,RES%r)+MATMUL(A%e1,RES%e111)+&
               MATMUL(A%e111,RES%e1)+MATMUL(A%e11,RES%e11)))
      RES%e2222=-MATMUL(RES%R,(MATMUL(A%e2222,RES%r)+MATMUL(A%e2,RES%e222)+&
               MATMUL(A%e222,RES%e2)+MATMUL(A%e22,RES%e22)))
      RES%e3333=-MATMUL(RES%R,(MATMUL(A%e3333,RES%r)+MATMUL(A%e3,RES%e333)+&
               MATMUL(A%e333,RES%e3)+MATMUL(A%e33,RES%e33)))
      RES%e4444=-MATMUL(RES%R,(MATMUL(A%e4444,RES%r)+MATMUL(A%e4,RES%e444)+&
               MATMUL(A%e444,RES%e4)+MATMUL(A%e44,RES%e44)))

   END FUNCTION donumm4n4_INV3X3

   FUNCTION donumm4n4_INV4X4(A,det)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(donumm4n4) , INTENT(IN) :: A(4,4) 
      TYPE(donumm4n4) , INTENT(IN), OPTIONAL :: det
      REAL(DP) :: detCalc
      TYPE(donumm4n4) :: RES(SIZE(A,1),SIZE(A,2)) 

      IF (PRESENT(det)) THEN
         detCalc=det%R
      ELSE
         detCalc=det4x4(A%R)
      END IF

      ! Get real part 
      RES%R=INV4X4(A%R,detCalc)

      ! Order 1
      RES%e1=-MATMUL(RES%R,(MATMUL(A%e1,RES%r)))
      RES%e2=-MATMUL(RES%R,(MATMUL(A%e2,RES%r)))
      RES%e3=-MATMUL(RES%R,(MATMUL(A%e3,RES%r)))
      RES%e4=-MATMUL(RES%R,(MATMUL(A%e4,RES%r)))

      ! Order 2
      RES%e11=-MATMUL(RES%R,(MATMUL(A%e11,RES%r)+MATMUL(A%e1,RES%e1)))
      RES%e22=-MATMUL(RES%R,(MATMUL(A%e22,RES%r)+MATMUL(A%e2,RES%e2)))
      RES%e33=-MATMUL(RES%R,(MATMUL(A%e33,RES%r)+MATMUL(A%e3,RES%e3)))
      RES%e44=-MATMUL(RES%R,(MATMUL(A%e44,RES%r)+MATMUL(A%e4,RES%e4)))

      ! Order 3
      RES%e111=-MATMUL(RES%R,(MATMUL(A%e111,RES%r)+MATMUL(A%e1,RES%e11)+&
              MATMUL(A%e11,RES%e1)))
      RES%e222=-MATMUL(RES%R,(MATMUL(A%e222,RES%r)+MATMUL(A%e2,RES%e22)+&
              MATMUL(A%e22,RES%e2)))
      RES%e333=-MATMUL(RES%R,(MATMUL(A%e333,RES%r)+MATMUL(A%e3,RES%e33)+&
              MATMUL(A%e33,RES%e3)))
      RES%e444=-MATMUL(RES%R,(MATMUL(A%e444,RES%r)+MATMUL(A%e4,RES%e44)+&
              MATMUL(A%e44,RES%e4)))

      ! Order 4
      RES%e1111=-MATMUL(RES%R,(MATMUL(A%e1111,RES%r)+MATMUL(A%e1,RES%e111)+&
               MATMUL(A%e111,RES%e1)+MATMUL(A%e11,RES%e11)))
      RES%e2222=-MATMUL(RES%R,(MATMUL(A%e2222,RES%r)+MATMUL(A%e2,RES%e222)+&
               MATMUL(A%e222,RES%e2)+MATMUL(A%e22,RES%e22)))
      RES%e3333=-MATMUL(RES%R,(MATMUL(A%e3333,RES%r)+MATMUL(A%e3,RES%e333)+&
               MATMUL(A%e333,RES%e3)+MATMUL(A%e33,RES%e33)))
      RES%e4444=-MATMUL(RES%R,(MATMUL(A%e4444,RES%r)+MATMUL(A%e4,RES%e444)+&
               MATMUL(A%e444,RES%e4)+MATMUL(A%e44,RES%e44)))

   END FUNCTION donumm4n4_INV4X4

END MODULE diagotim4n4
