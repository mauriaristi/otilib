MODULE otin1

   USE master_parameters
   USE real_utils

   IMPLICIT NONE

   INTEGER, PARAMETER :: num_im_dir = 2
   INTEGER, PARAMETER :: N_IMDIR_ORDER(2) = [1,1]

   INTEGER, PARAMETER, PRIVATE :: nim_o1 = 10
   ! INTEGER, PARAMETER, PRIVATE :: nim_o2 = 1891

   TYPE onumn1
     ! Real
     REAL(dp) :: r          ! <-- Real coefficient
     REAL(dp) :: e1(nim_o1) ! <-- First order coefficients
     ! REAL(dp) :: e2(nim_o2) !<-- Second order coefficients
     ! Order
     INTEGER(1) :: act_ord !<- Actual order
     INTEGER(1) :: trc_ord !<- Truncation order
   END TYPE onumn1


   ! Multiplication overloads.
   INTERFACE OPERATOR(*)
      MODULE PROCEDURE onumn1_mul_oo_ss,onumn1_mul_ro_ss,onumn1_mul_or_ss,onumn1_mul_oo_vs,&
                       onumn1_mul_ro_vs,onumn1_mul_or_vs,onumn1_mul_oo_ms,onumn1_mul_ro_ms,&
                       onumn1_mul_or_ms,onumn1_mul_oo_sv,onumn1_mul_ro_sv,onumn1_mul_or_sv,&
                       onumn1_mul_oo_sm,onumn1_mul_ro_sm,onumn1_mul_or_sm
   END INTERFACE

   ! Addition overloads.
   INTERFACE OPERATOR(+)
      MODULE PROCEDURE onumn1_add_oo_ss,onumn1_add_ro_ss,onumn1_add_or_ss,onumn1_add_oo_vs,&
                       onumn1_add_ro_vs,onumn1_add_or_vs,onumn1_add_oo_ms,onumn1_add_ro_ms,&
                       onumn1_add_or_ms,onumn1_add_oo_sv,onumn1_add_ro_sv,onumn1_add_or_sv,&
                       onumn1_add_oo_sm,onumn1_add_ro_sm,onumn1_add_or_sm
   END INTERFACE

   INTERFACE OPERATOR(-)
      MODULE PROCEDURe onumn1_neg,onumn1_sub_oo_ss,onumn1_sub_ro_ss,onumn1_sub_or_ss,&
                       onumn1_sub_oo_vs,onumn1_sub_ro_vs,onumn1_sub_or_vs,onumn1_sub_oo_ms,&
                       onumn1_sub_ro_ms,onumn1_sub_or_ms,onumn1_sub_oo_sv,onumn1_sub_ro_sv,&
                       onumn1_sub_or_sv,onumn1_sub_oo_sm,onumn1_sub_ro_sm,onumn1_sub_or_sm
   END INTERFACE

   INTERFACE OPERATOR(/)
      MODULE PROCEDURE onumn1_division_oo,onumn1_division_or,onumn1_division_ro
   END INTERFACE

   INTERFACE ASSIGNMENT(=)
      MODULE PROCEDURE onumn1_assign_r
   END INTERFACE

   INTERFACE OPERATOR(**)
      MODULE PROCEDURE onumn1_pow_or,onumn1_pow_ro,onumn1_pow_oo
   END INTERFACE

   INTERFACE PPRINT
      MODULE PROCEDURE onumn1_pprint_s,onumn1_pprint_v,onumn1_pprint_m
   END INTERFACE

   INTERFACE TRANSPOSE
      MODULE PROCEDURE onumn1_transpose
   END INTERFACE

   INTERFACE MATMUL
      MODULE PROCEDURE onumn1_matmul_onumn1,r_matmul_onumn1,onumn1_matmul_r
   END INTERFACE

   INTERFACE DOT_PRODUCT
      MODULE PROCEDURE onumn1_dot_product_onumn1,r_dot_product_onumn1,onumn1_dot_product_r
   END INTERFACE

   INTERFACE UNFOLD
      MODULE PROCEDURE onumn1_to_cr_mat_s,onumn1_to_cr_mat_v,onumn1_to_cr_mat_m
   END INTERFACE

   INTERFACE TO_CR
      MODULE PROCEDURE onumn1_to_cr_mat_s,onumn1_to_cr_mat_v,onumn1_to_cr_mat_m
   END INTERFACE

   INTERFACE SIN
      MODULE PROCEDURE onumn1_sin
   END INTERFACE

   INTERFACE COS
      MODULE PROCEDURE onumn1_cos
   END INTERFACE

   INTERFACE TAN
      MODULE PROCEDURE onumn1_tan
   END INTERFACE

   INTERFACE ASIN
      MODULE PROCEDURE onumn1_asin
   END INTERFACE

   INTERFACE ACOS
      MODULE PROCEDURE onumn1_acos
   END INTERFACE

   INTERFACE ATAN
      MODULE PROCEDURE onumn1_atan
   END INTERFACE

   INTERFACE SINH
      MODULE PROCEDURE onumn1_sinh
   END INTERFACE

   INTERFACE COSH
      MODULE PROCEDURE onumn1_cosh
   END INTERFACE

   INTERFACE TANH
      MODULE PROCEDURE onumn1_tanh
   END INTERFACE

   INTERFACE SQRT
      MODULE PROCEDURE onumn1_sqrt
   END INTERFACE

   INTERFACE LOG
      MODULE PROCEDURE onumn1_log
   END INTERFACE

   INTERFACE EXP
      MODULE PROCEDURE onumn1_exp
   END INTERFACE

   INTERFACE GEM
      MODULE PROCEDURE onumn1_gem_ooo,onumn1_gem_roo,onumn1_gem_oro
   END INTERFACE

   INTERFACE FEVAL
      MODULE PROCEDURE onumn1_feval
   END INTERFACE

   INTERFACE F2EVAL
      MODULE PROCEDURE onumn1_f2eval
   END INTERFACE

   INTERFACE REAL
      MODULE PROCEDURE onumn1_real
   END INTERFACE

   INTERFACE DET2X2
      MODULE PROCEDURE onumn1_det2x2
   END INTERFACE

   INTERFACE DET3X3
      MODULE PROCEDURE onumn1_det3x3
   END INTERFACE

   INTERFACE DET4X4
      MODULE PROCEDURE onumn1_det4x4
   END INTERFACE

   INTERFACE INV2X2
      MODULE PROCEDURE onumn1_inv2x2
   END INTERFACE

   INTERFACE INV3X3
      MODULE PROCEDURE onumn1_inv3x3
   END INTERFACE

   INTERFACE INV4X4
      MODULE PROCEDURE onumn1_inv4x4
   END INTERFACE

   INTERFACE GETIM
      MODULE PROCEDURE onumn1_getim_s, onumn1_getim_v, onumn1_getim_m
   END INTERFACE

   INTERFACE SETIM
      MODULE PROCEDURE onumn1_setim_s, onumn1_setim_v, onumn1_setim_m
   END INTERFACE

   CONTAINS

   ELEMENTAL SUBROUTINE onumn1_assign_r(RES,LHS)
      
      IMPLICIT NONE
      REAL(dp), INTENT(IN) :: LHS 
      TYPE(onumn1), INTENT(OUT) :: RES 

      ! Assign like function 'LHS'
      ! Real
      res%r = lhs

      ! Order 1
      res%e1 = 0.0_dp

   END SUBROUTINE onumn1_assign_r

   ELEMENTAL FUNCTION onumn1_neg(LHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(onumn1), INTENT(IN) :: LHS 
      TYPE(onumn1) :: RES 

      ! Negation like function '-LHS'
      ! Real
      RES%R = -LHS%R
      ! Order 1
      RES%E1 = -LHS%E1

   END FUNCTION onumn1_neg

   ELEMENTAL FUNCTION onumn1_add_oo_ss(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(onumn1), INTENT(IN) :: LHS
      TYPE(onumn1), INTENT(IN) :: RHS
      TYPE(onumn1) :: RES 

      ! addition like function 'LHS + RHS'
      !  Real
      RES%R = LHS%R + RHS%R

      ! Order 1
      RES%E1 = LHS%E1 + RHS%E1

   END FUNCTION onumn1_add_oo_ss

   ELEMENTAL FUNCTION onumn1_add_ro_ss(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(dp), INTENT(IN) :: LHS
      TYPE(onumn1), INTENT(IN) :: RHS
      TYPE(onumn1) :: RES 

      ! addition like function 'LHS + RHS'
      ! Real
      RES%R = LHS + RHS%R

      ! Order 1
      RES%E1 =  + RHS%E1

   END FUNCTION onumn1_add_ro_ss

   ELEMENTAL FUNCTION onumn1_add_or_ss(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(onumn1), INTENT(IN) :: LHS
      REAL(dp), INTENT(IN) :: RHS
      TYPE(onumn1) :: RES 

      ! addition like function 'LHS + RHS'
      ! Real
      RES%R = LHS%R + RHS

      ! Order 1
      RES%E1 = LHS%E1

   END FUNCTION onumn1_add_or_ss

   ELEMENTAL FUNCTION onumn1_sub_oo_ss(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(onumn1), INTENT(IN) :: LHS
      TYPE(onumn1), INTENT(IN) :: RHS
      TYPE(onumn1) :: RES 

      ! addition like function 'LHS - RHS'
      !  Real
      RES%R = LHS%R - RHS%R

      ! Order 1
      RES%E1 = LHS%E1 - RHS%E1

   END FUNCTION onumn1_sub_oo_ss

   ELEMENTAL FUNCTION onumn1_sub_ro_ss(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(dp), INTENT(IN) :: LHS
      TYPE(onumn1), INTENT(IN) :: RHS
      TYPE(onumn1) :: RES 

      ! addition like function 'LHS - RHS'
      ! Real
      RES%R = LHS - RHS%R

      ! Order 1
      RES%E1 =  - RHS%E1

   END FUNCTION onumn1_sub_ro_ss

   ELEMENTAL FUNCTION onumn1_sub_or_ss(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(onumn1), INTENT(IN) :: LHS
      REAL(dp), INTENT(IN) :: RHS
      TYPE(onumn1) :: RES 

      ! addition like function 'LHS - RHS'
      ! Real
      RES%R = LHS%R - RHS

      ! Order 1
      RES%E1 = LHS%E1

   END FUNCTION onumn1_sub_or_ss

   ELEMENTAL FUNCTION onumn1_mul_oo_ss(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(onumn1), INTENT(IN) :: LHS
      TYPE(onumn1), INTENT(IN) :: RHS
      TYPE(onumn1) :: RES 

      !  Multiplication like function 'LHS*RHS'
      ! Order 1
      RES%E1 = LHS%R*RHS%E1 + LHS%E1*RHS%R
      ! Order 0
      RES%R = LHS%R*RHS%R

   END FUNCTION onumn1_MUL_OO_SS

   ELEMENTAL FUNCTION onumn1_MUL_RO_SS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(dp), INTENT(IN) :: LHS
      TYPE(onumn1), INTENT(IN) :: RHS
      TYPE(onumn1) :: RES 

      ! Multiplication like function 'LHS*RHS'
      !  Real
      RES%R = LHS*RHS%R

      ! Order 1
      RES%E1 = LHS*RHS%E1

   END FUNCTION onumn1_MUL_RO_SS

   ELEMENTAL FUNCTION onumn1_MUL_OR_SS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(onumn1), INTENT(IN) :: LHS
      REAL(dp), INTENT(IN) :: RHS
      TYPE(onumn1) :: RES 

      ! Multiplication like function 'LHS*RHS'
      !  Real
      RES%R = LHS%R*RHS

      ! Order 1
      RES%E1 = LHS%E1*RHS

   END FUNCTION onumn1_MUL_OR_SS

   FUNCTION onumn1_add_OO_VS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(onumn1), INTENT(IN) :: LHS(:)
      TYPE(onumn1), INTENT(IN) :: RHS
      TYPE(onumn1) :: RES(SIZE(LHS,1)) 

      ! addition like function 'LHS + RHS'
      !  Real
      RES%R = LHS%R + RHS%R

      ! Order 1
      RES%E1 = LHS%E1 + RHS%E1

   END FUNCTION onumn1_add_OO_VS

   FUNCTION onumn1_add_RO_VS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(dp), INTENT(IN) :: LHS(:)
      TYPE(onumn1), INTENT(IN) :: RHS
      TYPE(onumn1) :: RES(SIZE(LHS,1)) 

      ! addition like function 'LHS + RHS'
      ! Real
      RES%R = LHS + RHS%R

      ! Order 1
      RES%E1 =  + RHS%E1

   END FUNCTION onumn1_add_RO_VS

   FUNCTION onumn1_add_OR_VS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(onumn1), INTENT(IN) :: LHS(:)
      REAL(dp), INTENT(IN) :: RHS
      TYPE(onumn1) :: RES(SIZE(LHS,1)) 

      ! addition like function 'LHS + RHS'
      ! Real
      RES%R = LHS%R + RHS

      ! Order 1
      RES%E1 = LHS%E1

   END FUNCTION onumn1_add_OR_VS

   FUNCTION onumn1_SUB_OO_VS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(onumn1), INTENT(IN) :: LHS(:)
      TYPE(onumn1), INTENT(IN) :: RHS
      TYPE(onumn1) :: RES(SIZE(LHS,1)) 

      ! addition like function 'LHS - RHS'
      !  Real
      RES%R = LHS%R - RHS%R

      ! Order 1
      RES%E1 = LHS%E1 - RHS%E1

   END FUNCTION onumn1_SUB_OO_VS

   FUNCTION onumn1_SUB_RO_VS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(dp), INTENT(IN) :: LHS(:)
      TYPE(onumn1), INTENT(IN) :: RHS
      TYPE(onumn1) :: RES(SIZE(LHS,1)) 

      ! addition like function 'LHS - RHS'
      ! Real
      RES%R = LHS - RHS%R

      ! Order 1
      RES%E1 =  - RHS%E1

   END FUNCTION onumn1_SUB_RO_VS

   FUNCTION onumn1_SUB_OR_VS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(onumn1), INTENT(IN) :: LHS(:)
      REAL(dp), INTENT(IN) :: RHS
      TYPE(onumn1) :: RES(SIZE(LHS,1)) 

      ! addition like function 'LHS - RHS'
      ! Real
      RES%R = LHS%R - RHS

      ! Order 1
      RES%E1 = LHS%E1

   END FUNCTION onumn1_SUB_OR_VS

   FUNCTION onumn1_MUL_OO_VS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(onumn1), INTENT(IN) :: LHS(:)
      TYPE(onumn1), INTENT(IN) :: RHS
      TYPE(onumn1) :: RES(SIZE(LHS,1)) 

      !  Multiplication like function 'LHS*RHS'
      ! Order 1
      RES%E1 = LHS%R*RHS%E1 + LHS%E1*RHS%R
      ! Order 0
      RES%R = LHS%R*RHS%R

   END FUNCTION onumn1_MUL_OO_VS

   FUNCTION onumn1_MUL_RO_VS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(dp), INTENT(IN) :: LHS(:)
      TYPE(onumn1), INTENT(IN) :: RHS
      TYPE(onumn1) :: RES(SIZE(LHS,1)) 

      ! Multiplication like function 'LHS*RHS'
      !  Real
      RES%R = LHS*RHS%R

      ! Order 1
      RES%E1 = LHS*RHS%E1

   END FUNCTION onumn1_MUL_RO_VS

   FUNCTION onumn1_MUL_OR_VS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(onumn1), INTENT(IN) :: LHS(:)
      REAL(dp), INTENT(IN) :: RHS
      TYPE(onumn1) :: RES(SIZE(LHS,1)) 

      ! Multiplication like function 'LHS*RHS'
      !  Real
      RES%R = LHS%R*RHS

      ! Order 1
      RES%E1 = LHS%E1*RHS

   END FUNCTION onumn1_MUL_OR_VS

   FUNCTION onumn1_add_OO_MS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(onumn1), INTENT(IN) :: LHS(:,:)
      TYPE(onumn1), INTENT(IN) :: RHS
      TYPE(onumn1) :: RES(SIZE(LHS,1),SIZE(LHS,2)) 

      ! addition like function 'LHS + RHS'
      !  Real
      RES%R = LHS%R + RHS%R

      ! Order 1
      RES%E1 = LHS%E1 + RHS%E1

   END FUNCTION onumn1_add_OO_MS

   FUNCTION onumn1_add_RO_MS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(dp), INTENT(IN) :: LHS(:,:)
      TYPE(onumn1), INTENT(IN) :: RHS
      TYPE(onumn1) :: RES(SIZE(LHS,1),SIZE(LHS,2)) 

      ! addition like function 'LHS + RHS'
      ! Real
      RES%R = LHS + RHS%R

      ! Order 1
      RES%E1 =  + RHS%E1

   END FUNCTION onumn1_add_RO_MS

   FUNCTION onumn1_add_OR_MS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(onumn1), INTENT(IN) :: LHS(:,:)
      REAL(dp), INTENT(IN) :: RHS
      TYPE(onumn1) :: RES(SIZE(LHS,1),SIZE(LHS,2)) 

      ! addition like function 'LHS + RHS'
      ! Real
      RES%R = LHS%R + RHS

      ! Order 1
      RES%E1 = LHS%E1

   END FUNCTION onumn1_add_OR_MS

   FUNCTION onumn1_SUB_OO_MS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(onumn1), INTENT(IN) :: LHS(:,:)
      TYPE(onumn1), INTENT(IN) :: RHS
      TYPE(onumn1) :: RES(SIZE(LHS,1),SIZE(LHS,2)) 

      ! addition like function 'LHS - RHS'
      !  Real
      RES%R = LHS%R - RHS%R

      ! Order 1
      RES%E1 = LHS%E1 - RHS%E1

   END FUNCTION onumn1_SUB_OO_MS

   FUNCTION onumn1_SUB_RO_MS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(dp), INTENT(IN) :: LHS(:,:)
      TYPE(onumn1), INTENT(IN) :: RHS
      TYPE(onumn1) :: RES(SIZE(LHS,1),SIZE(LHS,2)) 

      ! addition like function 'LHS - RHS'
      ! Real
      RES%R = LHS - RHS%R

      ! Order 1
      RES%E1 =  - RHS%E1

   END FUNCTION onumn1_SUB_RO_MS

   FUNCTION onumn1_SUB_OR_MS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(onumn1), INTENT(IN) :: LHS(:,:)
      REAL(dp), INTENT(IN) :: RHS
      TYPE(onumn1) :: RES(SIZE(LHS,1),SIZE(LHS,2)) 

      ! addition like function 'LHS - RHS'
      ! Real
      RES%R = LHS%R - RHS

      ! Order 1
      RES%E1 = LHS%E1

   END FUNCTION onumn1_SUB_OR_MS

   FUNCTION onumn1_MUL_OO_MS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(onumn1), INTENT(IN) :: LHS(:,:)
      TYPE(onumn1), INTENT(IN) :: RHS
      TYPE(onumn1) :: RES(SIZE(LHS,1),SIZE(LHS,2)) 

      !  Multiplication like function 'LHS*RHS'
      ! Order 1
      RES%E1 = LHS%R*RHS%E1 + LHS%E1*RHS%R
      ! Order 0
      RES%R = LHS%R*RHS%R

   END FUNCTION onumn1_MUL_OO_MS

   FUNCTION onumn1_MUL_RO_MS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(dp), INTENT(IN) :: LHS(:,:)
      TYPE(onumn1), INTENT(IN) :: RHS
      TYPE(onumn1) :: RES(SIZE(LHS,1),SIZE(LHS,2)) 

      ! Multiplication like function 'LHS*RHS'
      !  Real
      RES%R = LHS*RHS%R

      ! Order 1
      RES%E1 = LHS*RHS%E1

   END FUNCTION onumn1_MUL_RO_MS

   FUNCTION onumn1_MUL_OR_MS(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(onumn1), INTENT(IN) :: LHS(:,:)
      REAL(dp), INTENT(IN) :: RHS
      TYPE(onumn1) :: RES(SIZE(LHS,1),SIZE(LHS,2)) 

      ! Multiplication like function 'LHS*RHS'
      !  Real
      RES%R = LHS%R*RHS

      ! Order 1
      RES%E1 = LHS%E1*RHS

   END FUNCTION onumn1_MUL_OR_MS

   FUNCTION onumn1_add_OO_SV(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(onumn1), INTENT(IN) :: LHS
      TYPE(onumn1), INTENT(IN) :: RHS(:)
      TYPE(onumn1) :: RES(SIZE(RHS,1)) 

      ! addition like function 'LHS + RHS'
      !  Real
      RES%R = LHS%R + RHS%R

      ! Order 1
      RES%E1 = LHS%E1 + RHS%E1

   END FUNCTION onumn1_add_OO_SV

   FUNCTION onumn1_add_RO_SV(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(dp), INTENT(IN) :: LHS
      TYPE(onumn1), INTENT(IN) :: RHS(:)
      TYPE(onumn1) :: RES(SIZE(RHS,1)) 

      ! addition like function 'LHS + RHS'
      ! Real
      RES%R = LHS + RHS%R

      ! Order 1
      RES%E1 =  + RHS%E1

   END FUNCTION onumn1_add_RO_SV

   FUNCTION onumn1_add_OR_SV(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(onumn1), INTENT(IN) :: LHS
      REAL(dp), INTENT(IN) :: RHS(:)
      TYPE(onumn1) :: RES(SIZE(RHS,1)) 

      ! addition like function 'LHS + RHS'
      ! Real
      RES%R = LHS%R + RHS

      ! Order 1
      RES%E1 = LHS%E1

   END FUNCTION onumn1_add_OR_SV

   FUNCTION onumn1_SUB_OO_SV(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(onumn1), INTENT(IN) :: LHS
      TYPE(onumn1), INTENT(IN) :: RHS(:)
      TYPE(onumn1) :: RES(SIZE(RHS,1)) 

      ! addition like function 'LHS - RHS'
      !  Real
      RES%R = LHS%R - RHS%R

      ! Order 1
      RES%E1 = LHS%E1 - RHS%E1

   END FUNCTION onumn1_SUB_OO_SV

   FUNCTION onumn1_SUB_RO_SV(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(dp), INTENT(IN) :: LHS
      TYPE(onumn1), INTENT(IN) :: RHS(:)
      TYPE(onumn1) :: RES(SIZE(RHS,1)) 

      ! addition like function 'LHS - RHS'
      ! Real
      RES%R = LHS - RHS%R

      ! Order 1
      RES%E1 =  - RHS%E1

   END FUNCTION onumn1_SUB_RO_SV

   FUNCTION onumn1_SUB_OR_SV(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(onumn1), INTENT(IN) :: LHS
      REAL(dp), INTENT(IN) :: RHS(:)
      TYPE(onumn1) :: RES(SIZE(RHS,1)) 

      ! addition like function 'LHS - RHS'
      ! Real
      RES%R = LHS%R - RHS

      ! Order 1
      RES%E1 = LHS%E1

   END FUNCTION onumn1_SUB_OR_SV

   FUNCTION onumn1_MUL_OO_SV(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(onumn1), INTENT(IN) :: LHS
      TYPE(onumn1), INTENT(IN) :: RHS(:)
      TYPE(onumn1) :: RES(SIZE(RHS,1)) 

      !  Multiplication like function 'LHS*RHS'
      ! Order 1
      RES%E1 = LHS%R*RHS%E1 + LHS%E1*RHS%R
      ! Order 0
      RES%R = LHS%R*RHS%R

   END FUNCTION onumn1_MUL_OO_SV

   FUNCTION onumn1_MUL_RO_SV(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(dp), INTENT(IN) :: LHS
      TYPE(onumn1), INTENT(IN) :: RHS(:)
      TYPE(onumn1) :: RES(SIZE(RHS,1)) 

      ! Multiplication like function 'LHS*RHS'
      !  Real
      RES%R = LHS*RHS%R

      ! Order 1
      RES%E1 = LHS*RHS%E1

   END FUNCTION onumn1_MUL_RO_SV

   FUNCTION onumn1_MUL_OR_SV(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(onumn1), INTENT(IN) :: LHS
      REAL(dp), INTENT(IN) :: RHS(:)
      TYPE(onumn1) :: RES(SIZE(RHS,1)) 

      ! Multiplication like function 'LHS*RHS'
      !  Real
      RES%R = LHS%R*RHS

      ! Order 1
      RES%E1 = LHS%E1*RHS

   END FUNCTION onumn1_MUL_OR_SV

   FUNCTION onumn1_add_OO_SM(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(onumn1), INTENT(IN) :: LHS
      TYPE(onumn1), INTENT(IN) :: RHS(:,:)
      TYPE(onumn1) :: RES(SIZE(RHS,1),SIZE(RHS,2)) 

      ! addition like function 'LHS + RHS'
      !  Real
      RES%R = LHS%R + RHS%R

      ! Order 1
      RES%E1 = LHS%E1 + RHS%E1

   END FUNCTION onumn1_add_OO_SM

   FUNCTION onumn1_add_RO_SM(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(dp), INTENT(IN) :: LHS
      TYPE(onumn1), INTENT(IN) :: RHS(:,:)
      TYPE(onumn1) :: RES(SIZE(RHS,1),SIZE(RHS,2)) 

      ! addition like function 'LHS + RHS'
      ! Real
      RES%R = LHS + RHS%R

      ! Order 1
      RES%E1 =  + RHS%E1

   END FUNCTION onumn1_add_RO_SM

   FUNCTION onumn1_add_OR_SM(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(onumn1), INTENT(IN) :: LHS
      REAL(dp), INTENT(IN) :: RHS(:,:)
      TYPE(onumn1) :: RES(SIZE(RHS,1),SIZE(RHS,2)) 

      ! addition like function 'LHS + RHS'
      ! Real
      RES%R = LHS%R + RHS

      ! Order 1
      RES%E1 = LHS%E1

   END FUNCTION onumn1_add_OR_SM

   FUNCTION onumn1_SUB_OO_SM(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(onumn1), INTENT(IN) :: LHS
      TYPE(onumn1), INTENT(IN) :: RHS(:,:)
      TYPE(onumn1) :: RES(SIZE(RHS,1),SIZE(RHS,2)) 

      ! addition like function 'LHS - RHS'
      !  Real
      RES%R = LHS%R - RHS%R

      ! Order 1
      RES%E1 = LHS%E1 - RHS%E1

   END FUNCTION onumn1_SUB_OO_SM

   FUNCTION onumn1_SUB_RO_SM(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(dp), INTENT(IN) :: LHS
      TYPE(onumn1), INTENT(IN) :: RHS(:,:)
      TYPE(onumn1) :: RES(SIZE(RHS,1),SIZE(RHS,2)) 

      ! addition like function 'LHS - RHS'
      ! Real
      RES%R = LHS - RHS%R

      ! Order 1
      RES%E1 =  - RHS%E1

   END FUNCTION onumn1_SUB_RO_SM

   FUNCTION onumn1_SUB_OR_SM(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(onumn1), INTENT(IN) :: LHS
      REAL(dp), INTENT(IN) :: RHS(:,:)
      TYPE(onumn1) :: RES(SIZE(RHS,1),SIZE(RHS,2)) 

      ! addition like function 'LHS - RHS'
      ! Real
      RES%R = LHS%R - RHS

      ! Order 1
      RES%E1 = LHS%E1

   END FUNCTION onumn1_SUB_OR_SM

   FUNCTION onumn1_MUL_OO_SM(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(onumn1), INTENT(IN) :: LHS
      TYPE(onumn1), INTENT(IN) :: RHS(:,:)
      TYPE(onumn1) :: RES(SIZE(RHS,1),SIZE(RHS,2)) 

      !  Multiplication like function 'LHS*RHS'
      ! Order 1
      RES%E1 = LHS%R*RHS%E1 + LHS%E1*RHS%R
      ! Order 0
      RES%R = LHS%R*RHS%R

   END FUNCTION onumn1_MUL_OO_SM

   FUNCTION onumn1_MUL_RO_SM(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(dp), INTENT(IN) :: LHS
      TYPE(onumn1), INTENT(IN) :: RHS(:,:)
      TYPE(onumn1) :: RES(SIZE(RHS,1),SIZE(RHS,2)) 

      ! Multiplication like function 'LHS*RHS'
      !  Real
      RES%R = LHS*RHS%R

      ! Order 1
      RES%E1 = LHS*RHS%E1

   END FUNCTION onumn1_MUL_RO_SM

   FUNCTION onumn1_MUL_OR_SM(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(onumn1), INTENT(IN) :: LHS
      REAL(dp), INTENT(IN) :: RHS(:,:)
      TYPE(onumn1) :: RES(SIZE(RHS,1),SIZE(RHS,2)) 

      ! Multiplication like function 'LHS*RHS'
      !  Real
      RES%R = LHS%R*RHS

      ! Order 1
      RES%E1 = LHS%E1*RHS

   END FUNCTION onumn1_MUL_OR_SM

ELEMENTAL    FUNCTION onumn1_GEM_OOO(A,B,C)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(onumn1), INTENT(IN) :: A 
      TYPE(onumn1), INTENT(IN) :: B 
      TYPE(onumn1), INTENT(IN) :: C 
      TYPE(onumn1) :: RES 

      !  General multiplication like function 'A*B + C'

      ! Order 0
      RES%R = C%R + A%R*B%R

      ! Order 1
      RES%E1 = C%E1 + A%R*B%E1 + A%E1*B%R

   END FUNCTION onumn1_GEM_OOO

ELEMENTAL    FUNCTION onumn1_GEM_ROO(A,B,C)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(dp), INTENT(IN) :: A 
      TYPE(onumn1), INTENT(IN) :: B 
      TYPE(onumn1), INTENT(IN) :: C 
      TYPE(onumn1) :: RES 

      !  General multiplication like function 'A*B + C'
      ! Order 1
      RES%E1 = C%E1 + A*B%E1
      ! Order 0
      RES%R = C%R + A*B%R

   END FUNCTION onumn1_GEM_ROO

ELEMENTAL    FUNCTION onumn1_GEM_ORO(A,B,C)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(onumn1), INTENT(IN) :: A 
      REAL(dp), INTENT(IN) :: B 
      TYPE(onumn1), INTENT(IN) :: C 
      TYPE(onumn1) :: RES 

      !  General multiplication like function 'A*B + C'

      ! Order 0
      RES%R = C%R + A%R*B

      ! Order 1
      RES%E1 = C%E1 + A%E1*B

   END FUNCTION onumn1_GEM_ORO

   FUNCTION onumn1_MATMUL_onumn1(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(onumn1), INTENT(IN) :: LHS(:,:)
      TYPE(onumn1), INTENT(IN) :: RHS(:,:)
      TYPE(onumn1) :: RES(SIZE(LHS,1),SIZE(RHS,2))

      !  Multiplication like function 'MATMUL(LHS,RHS)'
      ! Order 1
      RES%E1 = MATMUL(LHS%R,RHS%E1) + MATMUL(LHS%E1,RHS%R)
      ! Order 0
      RES%R = MATMUL(LHS%R,RHS%R)

   END FUNCTION onumn1_MATMUL_onumn1

   FUNCTION R_MATMUL_onumn1(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(dp), INTENT(IN) :: LHS(:,:)
      TYPE(onumn1), INTENT(IN) :: RHS(:,:)
      TYPE(onumn1) :: RES(SIZE(LHS,1),SIZE(RHS,2))

      ! Multiplication like function 'MATMUL(LHS,RHS)'
      !  Real
      RES%R = MATMUL(LHS,RHS%R)

      ! Order 1
      RES%E1 = MATMUL(LHS,RHS%E1)

   END FUNCTION R_MATMUL_onumn1

   FUNCTION onumn1_MATMUL_R(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(onumn1), INTENT(IN) :: LHS(:,:)
      REAL(dp), INTENT(IN) :: RHS(:,:)
      TYPE(onumn1) :: RES(SIZE(LHS,1),SIZE(RHS,2))

      ! Multiplication like function 'MATMUL(LHS,RHS)'
      !  Real
      RES%R = MATMUL(LHS%R,RHS)

      ! Order 1
      RES%E1 = MATMUL(LHS%E1,RHS)

   END FUNCTION onumn1_MATMUL_R

   FUNCTION onumn1_DOT_PRODUCT_onumn1(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(onumn1), INTENT(IN) :: LHS(:)
      TYPE(onumn1), INTENT(IN) :: RHS(SIZE(LHS))
      TYPE(onumn1) :: RES

      !  Multiplication like function 'DOT_PRODUCT(LHS,RHS)'
      ! Order 1
      RES%E1 = DOT_PRODUCT(LHS%R,RHS%E1) + DOT_PRODUCT(LHS%E1,RHS%R)
      ! Order 0
      RES%R = DOT_PRODUCT(LHS%R,RHS%R)

   END FUNCTION onumn1_DOT_PRODUCT_onumn1

   FUNCTION R_DOT_PRODUCT_onumn1(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      REAL(dp), INTENT(IN) :: LHS(:)
      TYPE(onumn1), INTENT(IN) :: RHS(SIZE(LHS))
      TYPE(onumn1) :: RES

      ! Multiplication like function 'DOT_PRODUCT(LHS,RHS)'
      !  Real
      RES%R = DOT_PRODUCT(LHS,RHS%R)

      ! Order 1
      RES%E1 = DOT_PRODUCT(LHS,RHS%E1)

   END FUNCTION R_DOT_PRODUCT_onumn1

   FUNCTION onumn1_DOT_PRODUCT_R(LHS,RHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(onumn1), INTENT(IN) :: LHS(:)
      REAL(dp), INTENT(IN) :: RHS(SIZE(LHS))
      TYPE(onumn1) :: RES

      ! Multiplication like function 'DOT_PRODUCT(LHS,RHS)'
      !  Real
      RES%R = DOT_PRODUCT(LHS%R,RHS)

      ! Order 1
      RES%E1 = DOT_PRODUCT(LHS%E1,RHS)

   END FUNCTION onumn1_DOT_PRODUCT_R

   FUNCTION onumn1_TRANSPOSE(LHS)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(onumn1), INTENT(IN) :: LHS(:,:)
      TYPE(onumn1) :: RES (SIZE(LHS,2),SIZE(LHS,1))

      ! Negation like function 'TRANSPOSE(LHS)'
      ! Real
      RES%R = TRANSPOSE(LHS%R)
      ! Order 1
      RES%E1 = TRANSPOSE(LHS%E1)

   END FUNCTION onumn1_TRANSPOSE

FUNCTION onumn1_TO_CR_MAT_S(VAL) RESULT(RES)
      IMPLICIT NONE
      TYPE(onumn1), INTENT(IN) :: VAL
      REAL(dp) :: RES(num_im_dir,num_im_dir) 
      INTEGER :: NCOLS=1, NROWS=1


      ! R x R -> R (1, 1)
      RES(1+NROWS*0:NROWS*1,1+NCOLS*0:NCOLS*1) = VAL%R
      ! R x E1 -> E1 (2, 2)
      RES(1+NROWS*1:NROWS*2,1+NCOLS*1:NCOLS*2) = VAL%R
      ! E1 x R -> E1 (2, 1)
      RES(1+NROWS*1:NROWS*2,1+NCOLS*0:NCOLS*1) = VAL%E1
   END FUNCTION onumn1_TO_CR_MAT_S

FUNCTION onumn1_TO_CR_MAT_V(VAL) RESULT(RES)
      IMPLICIT NONE
      TYPE(onumn1), INTENT(IN) :: VAL(:)
      REAL(dp) :: RES(num_im_dir*SIZE(VAL,1),num_im_dir) 
      INTEGER :: NCOLS=1, NROWS=1

      NROWS = SIZE(VAL,1)

      ! R x R -> R (1, 1)
      RES(1+NROWS*0:NROWS*1,1) = VAL%R
      ! R x E1 -> E1 (2, 2)
      RES(1+NROWS*1:NROWS*2,2) = VAL%R
      ! E1 x R -> E1 (2, 1)
      RES(1+NROWS*1:NROWS*2,1) = VAL%E1
   END FUNCTION onumn1_TO_CR_MAT_V

FUNCTION onumn1_TO_CR_MAT_M(VAL) RESULT(RES)
      IMPLICIT NONE
      TYPE(onumn1), INTENT(IN) :: VAL(:,:)
      REAL(dp) :: RES(num_im_dir*SIZE(VAL,1),num_im_dir*SIZE(VAL,2)) 
      INTEGER :: NCOLS=1, NROWS=1

      NCOLS = SIZE(VAL,1)
      NROWS = SIZE(VAL,2)

      ! R x R -> R (1, 1)
      RES(1+NROWS*0:NROWS*1,1+NCOLS*0:NCOLS*1) = VAL%R
      ! R x E1 -> E1 (2, 2)
      RES(1+NROWS*1:NROWS*2,1+NCOLS*1:NCOLS*2) = VAL%R
      ! E1 x R -> E1 (2, 1)
      RES(1+NROWS*1:NROWS*2,1+NCOLS*0:NCOLS*1) = VAL%E1
   END FUNCTION onumn1_TO_CR_MAT_M

      SUBROUTINE onumn1_SETIM_S(VAL,IDX,RES)
      IMPLICIT NONE
      TYPE(onumn1), INTENT(INOUT) :: VAL
      REAL(dp),INTENT(IN) :: RES 
      INTEGER, INTENT(IN) :: IDX

      SELECT CASE(IDX)
      ! Order 0
      CASE(0)
         VAL%R=RES

      ! Order 1
      CASE(1)
         VAL%E1=RES

      END SELECT
   END SUBROUTINE onumn1_SETIM_S

      SUBROUTINE onumn1_SETIM_V(VAL,IDX,RES)
      IMPLICIT NONE
      TYPE(onumn1), INTENT(INOUT) :: VAL(:)
      REAL(dp),INTENT(IN) :: RES(SIZE(VAL)) 
      INTEGER, INTENT(IN) :: IDX

      SELECT CASE(IDX)
      ! Order 0
      CASE(0)
         VAL%R=RES

      ! Order 1
      CASE(1)
         VAL%E1=RES

      END SELECT
   END SUBROUTINE onumn1_SETIM_V

      SUBROUTINE onumn1_SETIM_M(VAL,IDX,RES)
      IMPLICIT NONE
      TYPE(onumn1), INTENT(INOUT) :: VAL(:,:)
      REAL(dp),INTENT(IN) :: RES(SIZE(VAL,1),SIZE(VAL,2)) 
      INTEGER, INTENT(IN) :: IDX

      SELECT CASE(IDX)
      ! Order 0
      CASE(0)
         VAL%R=RES

      ! Order 1
      CASE(1)
         VAL%E1=RES

      END SELECT
   END SUBROUTINE onumn1_SETIM_M

FUNCTION onumn1_GETIM_S(VAL,IDX) RESULT(RES)
      IMPLICIT NONE
      TYPE(onumn1), INTENT(IN) :: VAL
      REAL(dp) :: RES 
      INTEGER, INTENT(IN) :: IDX

      SELECT CASE(IDX)
      ! Order 0
      CASE(0)
         RES=VAL%R

      ! Order 1
      CASE(1)
         RES=VAL%E1

      END SELECT
   END FUNCTION onumn1_GETIM_S

FUNCTION onumn1_GETIM_V(VAL,IDX) RESULT(RES)
      IMPLICIT NONE
      TYPE(onumn1), INTENT(IN) :: VAL(:)
      REAL(dp) :: RES(SIZE(VAL)) 
      INTEGER, INTENT(IN) :: IDX

      SELECT CASE(IDX)
      ! Order 0
      CASE(0)
         RES=VAL%R

      ! Order 1
      CASE(1)
         RES=VAL%E1

      END SELECT
   END FUNCTION onumn1_GETIM_V

FUNCTION onumn1_GETIM_M(VAL,IDX) RESULT(RES)
      IMPLICIT NONE
      TYPE(onumn1), INTENT(IN) :: VAL(:,:)
      REAL(dp) :: RES(SIZE(VAL,1),SIZE(VAL,2)) 
      INTEGER, INTENT(IN) :: IDX

      SELECT CASE(IDX)
      ! Order 0
      CASE(0)
         RES=VAL%R

      ! Order 1
      CASE(1)
         RES=VAL%E1

      END SELECT
   END FUNCTION onumn1_GETIM_M

   SUBROUTINE onumn1_PPRINT_S(VAR,FMT,UNIT)
      IMPLICIT NONE
      TYPE(onumn1), INTENT(IN) :: VAR
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


   END SUBROUTINE onumn1_PPRINT_S

   SUBROUTINE onumn1_PPRINT_V(VAR,FMT,UNIT)
      IMPLICIT NONE
      TYPE(onumn1), INTENT(IN) :: VAR(:)
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


   END SUBROUTINE onumn1_PPRINT_V

   SUBROUTINE onumn1_PPRINT_M(VAR,FMT,UNIT)
      IMPLICIT NONE
      TYPE(onumn1), INTENT(IN) :: VAR(:,:)
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


   END SUBROUTINE onumn1_PPRINT_M

   ELEMENTAL FUNCTION onumn1_FEVAL(X,DER0,DER1)&
      RESULT(RES)
      IMPLICIT NONE
      !  Definitions
      REAL(dp) :: FACTOR, COEF
      TYPE(onumn1), INTENT(IN)  :: X
      REAL(dp), INTENT(IN)  :: DER0,DER1
      TYPE(onumn1) :: RES
      TYPE(onumn1) :: DX, DX_P

      FACTOR = 1.0_dp
      COEF   = 0.0_dp
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
      ! Order 1
      RES%E1 = RES%E1+COEF*DX_P%E1
      
   END FUNCTION onumn1_FEVAL


  ! SUBROUTINE onumn1_PPRINT_M_R(X, FMT)
  !     IMPLICIT NONE
  !     REAL(dp),INTENT(IN) :: X(:,:)
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

  ! END SUBROUTINE onumn1_PPRINT_M_R

  ! SUBROUTINE onumn1_PPRINT_V_R(X, FMT)
  !     IMPLICIT NONE
  !     REAL(dp),INTENT(IN) :: X(:)
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

  ! END SUBROUTINE onumn1_PPRINT_V_R

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
  PURE FUNCTION onumn1_det2x2(A) RESULT(det)

    IMPLICIT NONE

    TYPE(onumn1), INTENT(IN) :: A(2,2)   !! Matrix
    TYPE(onumn1)             :: det

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
  PURE FUNCTION onumn1_det3x3(A) RESULT(det)
      
    IMPLICIT NONE

    TYPE(onumn1), INTENT(IN) :: A(3,3)   !! Matrix
    TYPE(onumn1)             :: det

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
  PURE FUNCTION onumn1_det4x4(A) RESULT(det)
      
    IMPLICIT NONE

    TYPE(onumn1), INTENT(IN) :: A(4,4)   !! Matrix
    TYPE(onumn1)             :: det

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
  PURE FUNCTION onumn1_cross3(a,b) RESULT(v)
      
    IMPLICIT NONE 

    TYPE(onumn1), DIMENSION (3),INTENT(IN) :: a,b
    TYPE(onumn1), DIMENSION (3) :: v
    
    v(1) = a(2) * b(3) - a(3) * b(2)
    v(2) = a(3) * b(1) - a(1) * b(3)
    v(3) = a(1) * b(2) - a(2) * b(1)

  END FUNCTION onumn1_cross3
  !===================================================================================================! 

  !***************************************************************************************************! 
  !> @brief Norm of a 3 element vector. # There is an intrinsic function named norm2.
  !!
  !! @param[in] a: Vector of 3 reals (rank 1).
  !! @param[in] b: Vector of 3 reals (rank 1).
  !!
  !***************************************************************************************************!
  FUNCTION onumn1_norm2_3(v) RESULT(n)
     
    IMPLICIT NONE 

    TYPE(onumn1), INTENT(IN) :: v(3)
    TYPE(onumn1) :: n
     
    n = SQRT( v(1)*v(1) + v(2)*v(2) + v(3)*v(3) )

  END FUNCTION onumn1_norm2_3
  !===================================================================================================! 

  FUNCTION onumn1_DIVISION_OO(X,Y) RESULT(RES)
      IMPLICIT NONE
      REAL(dp) :: DERIVS(TORDER + 1) 
      TYPE(onumn1), INTENT(IN) :: X
      TYPE(onumn1), INTENT(IN) :: Y
      TYPE(onumn1) :: RES

      RES = X*(Y**(-1.d0))

  END FUNCTION onumn1_DIVISION_OO

  FUNCTION onumn1_DIVISION_OR(X,Y) RESULT(RES)
      IMPLICIT NONE
      REAL(dp) :: DERIVS(TORDER + 1) 
      TYPE(onumn1), INTENT(IN) :: X
      REAL(dp), INTENT(IN) :: Y
      TYPE(onumn1) :: RES

      RES = X*(Y**(-1.d0))

  END FUNCTION onumn1_DIVISION_OR

  FUNCTION onumn1_DIVISION_RO(X,Y) RESULT(RES)
      IMPLICIT NONE
      REAL(dp) :: DERIVS(TORDER + 1) 
      REAL(dp), INTENT(IN) :: X
      TYPE(onumn1), INTENT(IN) :: Y
      TYPE(onumn1) :: RES

      RES = X*(Y**(-1.d0))

  END FUNCTION onumn1_DIVISION_RO

  ELEMENTAL FUNCTION onumn1_REAL(X) RESULT(RES)
      IMPLICIT NONE
      TYPE(onumn1), INTENT(IN) :: X
      REAL(dp) :: RES

      RES = X%R

  END FUNCTION onumn1_REAL

  FUNCTION onumn1_SQRT(X) RESULT(RES)
      IMPLICIT NONE
      TYPE(onumn1), INTENT(IN) :: X
      TYPE(onumn1) :: RES

      RES = X**0.5_dp

  END FUNCTION onumn1_SQRT

   ELEMENTAL FUNCTION onumn1_TAN(X) RESULT(RES)

      TYPE(onumn1), INTENT(IN) :: X
      REAL(dp) :: DER0,DER1
      TYPE(onumn1) :: RES
      
      DER0 = TAN(X%R)
      DER1 = TAN(X%R)**2 + 1

      RES = FEVAL(X,DER0,DER1)

   END FUNCTION onumn1_TAN

   ELEMENTAL FUNCTION onumn1_COS(X) RESULT(RES)

      TYPE(onumn1), INTENT(IN) :: X
      REAL(dp) :: DER0,DER1
      TYPE(onumn1) :: RES
      
      DER0 = COS(X%R)
      DER1 = -SIN(X%R)

      RES = FEVAL(X,DER0,DER1)

   END FUNCTION onumn1_COS

   ELEMENTAL FUNCTION onumn1_SIN(X) RESULT(RES)

      TYPE(onumn1), INTENT(IN) :: X
      REAL(dp) :: DER0,DER1
      TYPE(onumn1) :: RES
      
      DER0 = SIN(X%R)
      DER1 = COS(X%R)

      RES = FEVAL(X,DER0,DER1)

   END FUNCTION onumn1_SIN

   ELEMENTAL FUNCTION onumn1_ATAN(X) RESULT(RES)

      TYPE(onumn1), INTENT(IN) :: X
      REAL(dp) :: DER0,DER1
      TYPE(onumn1) :: RES
      
      DER0 = ATAN(X%R)
      DER1 = 1D0/(X%R**2 + 1)

      RES = FEVAL(X,DER0,DER1)

   END FUNCTION onumn1_ATAN

   ELEMENTAL FUNCTION onumn1_ACOS(X) RESULT(RES)

      TYPE(onumn1), INTENT(IN) :: X
      REAL(dp) :: DER0,DER1
      TYPE(onumn1) :: RES
      
      DER0 = ACOS(X%R)
      DER1 = -1/SQRT(1 - X%R**2)

      RES = FEVAL(X,DER0,DER1)

   END FUNCTION onumn1_ACOS

   ELEMENTAL FUNCTION onumn1_ASIN(X) RESULT(RES)

      TYPE(onumn1), INTENT(IN) :: X
      REAL(dp) :: DER0,DER1
      TYPE(onumn1) :: RES
      
      DER0 = ASIN(X%R)
      DER1 = 1/SQRT(1 - X%R**2)

      RES = FEVAL(X,DER0,DER1)

   END FUNCTION onumn1_ASIN

   ELEMENTAL FUNCTION onumn1_TANH(X) RESULT(RES)

      TYPE(onumn1), INTENT(IN) :: X
      REAL(dp) :: DER0,DER1
      TYPE(onumn1) :: RES
      
      DER0 = TANH(X%R)
      DER1 = 1 - TANH(X%R)**2

      RES = FEVAL(X,DER0,DER1)

   END FUNCTION onumn1_TANH

   ELEMENTAL FUNCTION onumn1_COSH(X) RESULT(RES)

      TYPE(onumn1), INTENT(IN) :: X
      REAL(dp) :: DER0,DER1
      TYPE(onumn1) :: RES
      
      DER0 = COSH(X%R)
      DER1 = SINH(X%R)

      RES = FEVAL(X,DER0,DER1)

   END FUNCTION onumn1_COSH

   ELEMENTAL FUNCTION onumn1_SINH(X) RESULT(RES)

      TYPE(onumn1), INTENT(IN) :: X
      REAL(dp) :: DER0,DER1
      TYPE(onumn1) :: RES
      
      DER0 = SINH(X%R)
      DER1 = COSH(X%R)

      RES = FEVAL(X,DER0,DER1)

   END FUNCTION onumn1_SINH

   ELEMENTAL FUNCTION onumn1_EXP(X) RESULT(RES)

      TYPE(onumn1), INTENT(IN) :: X
      REAL(dp) :: DER0,DER1
      TYPE(onumn1) :: RES
      
      DER0 = EXP(X%R)
      DER1 = EXP(X%R)

      RES = FEVAL(X,DER0,DER1)

   END FUNCTION onumn1_EXP

   ELEMENTAL FUNCTION onumn1_LOG(X) RESULT(RES)

      TYPE(onumn1), INTENT(IN) :: X
      REAL(dp) :: DER0,DER1
      TYPE(onumn1) :: RES
      
      DER0 = LOG(X%R)
      DER1 = 1D0/X%R

      RES = FEVAL(X,DER0,DER1)

   END FUNCTION onumn1_LOG

   ELEMENTAL FUNCTION onumn1_POW_OR(X,E) RESULT(RES)

      TYPE(onumn1), INTENT(IN) :: X
      REAL(dp), INTENT(IN) :: E
      REAL(dp) :: DER0,DER1
      TYPE(onumn1) :: RES
      
      DER0=0.0d0
      DER1=0.0d0
      
      DER0 = X%R**E
      IF ((E-0)/=0.0d0) THEN
         DER1 = E*X%R**(E - 1)
      END IF

      RES = FEVAL(X,DER0,DER1)

   END FUNCTION onumn1_POW_OR

   ELEMENTAL FUNCTION onumn1_POW_RO(E,X) RESULT(RES)

      TYPE(onumn1), INTENT(IN) :: X
      REAL(dp), INTENT(IN) :: E
      REAL(dp) :: DER0,DER1
      TYPE(onumn1) :: RES
      
      
      DER0 = E**X%R
      DER1 = E**X%R*LOG(E)

      RES = FEVAL(X,DER0,DER1)

   END FUNCTION onumn1_POW_RO

   ELEMENTAL FUNCTION onumn1_F2EVAL(X,Y,DER0_0,DER1_0,DER1_1)&
      RESULT(RES)
      IMPLICIT NONE
      !  Definitions
      REAL(dp) :: COEF, DELTA
      TYPE(onumn1), INTENT(IN)  :: X,Y
      REAL(dp), INTENT(IN)  :: DER0_0,DER1_0,DER1_1
      TYPE(onumn1) :: RES
      TYPE(onumn1) :: DX, DY

      COEF   = 0.0_dp
      DX     = X
      DY     = Y

      !  Set real part of deltas zero.
      DX%R = 0.0_dp
      DY%R = 0.0_dp

      ! Set real part
      RES = DER0_0

      ! Set order 1
      COEF = DER1_0 / 1.0_dp
      RES = RES + COEF*DX

      COEF = DER1_1 / 1.0_dp
      RES = RES + COEF*DY

      

   END FUNCTION onumn1_F2EVAL


   ELEMENTAL FUNCTION onumn1_POW_OO(X,Y) RESULT(RES)

      TYPE(onumn1), INTENT(IN) :: X, Y
      REAL(dp) :: DER0_0,DER1_0,DER1_1
      TYPE(onumn1) :: RES
      
      DER0_0 = X%R**Y%R
      DER1_0 = X%R**Y%R*Y%R/X%R
      DER1_1 = X%R**Y%R*LOG(X%R)

      RES = F2EVAL(X,Y,DER0_0,DER1_0,DER1_1)

   END FUNCTION onumn1_POW_OO


   FUNCTION onumn1_INV2X2(A,det)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(onumn1) , INTENT(IN) :: A(2,2) 
      TYPE(onumn1) , INTENT(IN), OPTIONAL :: det
      REAL(dp) :: detCalc
      TYPE(onumn1) :: RES(SIZE(A,1),SIZE(A,2)) 

      IF (PRESENT(det)) THEN
         detCalc=det%R
      ELSE
         detCalc=det2x2(A%R)
      END IF

      ! Get real part 
      RES%R=INV2X2(A%R,detCalc)

      ! Order 1
      RES%E1=-MATMUL(RES%R,(MATMUL(A%E1,RES%R)))

   END FUNCTION onumn1_INV2X2

   FUNCTION onumn1_INV3X3(A,det)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(onumn1) , INTENT(IN) :: A(3,3) 
      TYPE(onumn1) , INTENT(IN), OPTIONAL :: det
      REAL(dp) :: detCalc
      TYPE(onumn1) :: RES(SIZE(A,1),SIZE(A,2)) 

      IF (PRESENT(det)) THEN
         detCalc=det%R
      ELSE
         detCalc=det3x3(A%R)
      END IF

      ! Get real part 
      RES%R=INV3X3(A%R,detCalc)

      ! Order 1
      RES%E1=-MATMUL(RES%R,(MATMUL(A%E1,RES%R)))

   END FUNCTION onumn1_INV3X3

   FUNCTION onumn1_INV4X4(A,det)&
      RESULT(RES)
      IMPLICIT NONE
      TYPE(onumn1) , INTENT(IN) :: A(4,4) 
      TYPE(onumn1) , INTENT(IN), OPTIONAL :: det
      REAL(dp) :: detCalc
      TYPE(onumn1) :: RES(SIZE(A,1),SIZE(A,2)) 

      IF (PRESENT(det)) THEN
         detCalc=det%R
      ELSE
         detCalc=det4x4(A%R)
      END IF

      ! Get real part 
      RES%R=INV4X4(A%R,detCalc)

      ! Order 1
      RES%E1=-MATMUL(RES%R,(MATMUL(A%E1,RES%R)))

   END FUNCTION onumn1_INV4X4

END MODULE otin1
